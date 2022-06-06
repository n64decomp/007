/*====================================================================
 * synthesizer.c
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include "synthInternals.h"
#include "include/assert.h"

#ifdef AUD_PROFILE
#include <os.h>
extern u32 cnt_index, drvr_num, drvr_cnt, drvr_max, drvr_min, lastCnt[];
extern u32 client_num, client_cnt, client_max, client_min;
#endif

#ifndef MIN
#   define MIN(a,b) (((a)<(b))?(a):(b))
#endif

static s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client);
static s32 _timeToSamplesNoRound(ALSynth *ALSynth, s32 micros);

/***********************************************************************
 * Synthesis driver public interfaces
 ***********************************************************************/
void alSynNew(ALSynth *drvr, ALSynConfig *c)
{
    s32         i;
    ALVoice     *vv;
    PVoice      *pv;
    ALVoice     *vvoices;
    PVoice      *pvoices;
    ALHeap      *hp = c->heap;
    ALSave      *save;
    ALFilter    *sources;
    ALParam     *params;
    ALParam     *paramPtr;
    
    drvr->head            = NULL;
    drvr->numPVoices      = c->maxPVoices;
    drvr->curSamples      = 0;
    drvr->paramSamples    = 0;
    drvr->outputRate      = c->outputRate;
    drvr->maxOutSamples   = AL_MAX_RSP_SAMPLES;
    drvr->dma             = (ALDMANew) c->dmaproc;

    save = alHeapAlloc(hp, 1, sizeof(ALSave));
    alSaveNew(save);
    drvr->outputFilter = (ALFilter *)save;

    /*
     * allocate and initialize the auxilliary effects bus. at present
     * we only support 1 effects bus.
     */
    drvr->auxBus = alHeapAlloc(hp, 1, sizeof(ALAuxBus));
    drvr->maxAuxBusses = 1;
    sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
    alAuxBusNew(drvr->auxBus, sources, c->maxPVoices);

    /*
     * allocate and initialize the main bus.
     */
    drvr->mainBus = alHeapAlloc(hp, 1, sizeof(ALMainBus));
    sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
    alMainBusNew(drvr->mainBus, sources, c->maxPVoices);

    if (c->fxType != AL_FX_NONE){
        /*
         * Allocate an effect and set parameters
         */
        alSynAllocFX(drvr, 0, c, hp);
    } else
        /*
         * Connect the aux bus to the main bus
         */
    	alMainBusParam(drvr->mainBus, AL_FILTER_ADD_SOURCE, &drvr->auxBus[0]);
    
    /*
     * Build the physical voice lists
     */
    drvr->pFreeList.next = 0;
    drvr->pFreeList.prev = 0;
    drvr->pLameList.next = 0;
    drvr->pLameList.prev = 0;
    drvr->pAllocList.next = 0;
    drvr->pAllocList.prev = 0;

    pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(PVoice));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        alLink((ALLink *)pv, &drvr->pFreeList);
        pv->vvoice = 0;

        alLoadNew(&pv->decoder, drvr->dma, hp);
        alLoadParam(&pv->decoder, AL_FILTER_SET_SOURCE, 0);
    
        alResampleNew(&pv->resampler, hp);
        alResampleParam(&pv->resampler, AL_FILTER_SET_SOURCE, &pv->decoder);

        alEnvmixerNew(&pv->envmixer, hp);
        alEnvmixerParam(&pv->envmixer, AL_FILTER_SET_SOURCE, &pv->resampler);

        alAuxBusParam(drvr->auxBus, AL_FILTER_ADD_SOURCE, &pv->envmixer);
        
        pv->channelKnob   = (ALFilter *)&pv->envmixer;
    }
    
    alSaveParam(save, AL_FILTER_SET_SOURCE, drvr->mainBus);

    /*
     * build the parameter update list
     */
    params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
    drvr->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr= &params[i];
        paramPtr->next = drvr->paramList;
        drvr->paramList = paramPtr;
    }
    
    drvr->heap = hp;
}

/*
 * slAudioFrame() is called every video frame, and is based on the video
 * frame interrupt. It is assumed to be an accurate time source for the
 * clients.
 */
Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    ALPlayer    *client;
    ALFilter    *output;
    ALSynth     *drvr = &alGlobals->drvr;
    s16         tmp = 0;        /* Starting buffer in DMEM */
    Acmd        *cmdlEnd = cmdList;
    Acmd        *cmdPtr;
    s32         nOut;
    s16         *lOutBuf = outBuf;

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif
    
    if (drvr->head == 0) {
	*cmdLen = 0;
        return cmdList;         /* nothing to do */
    }    

    /*
     * run down list of clients and execute callback if needed this
     * subframe. Here we do all the work for the frame at the
     * start. Time offsets that occur before the next frame are
     * executed "early".
     */

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    /*
     * paramSamples = time of next parameter change.
     * curSamples = current sample time.
     * so paramSamples - curSamples is the time until the next parameter change.
     * if the next parameter change occurs within this frame time (outLen),
     * then call back the client that contains the parameter change.
     * Note, paramSamples must be rounded down to 16 sample boundary for use
     * during the client handler.
     */

    for (drvr->paramSamples = __nextSampleTime(drvr, &client);
	 drvr->paramSamples - drvr->curSamples < outLen;
	 drvr->paramSamples = __nextSampleTime(drvr, &client))
    {
	drvr->paramSamples &= ~0xf;
	client->samplesLeft += _timeToSamplesNoRound(drvr, (*client->handler)(client));
    }

    /* for safety's sake, always store paramSamples aligned to 16 sample boundary.
     * this way, if an voice handler routine gets called outside the ALVoiceHandler
     * routine (alSynAllocVoice) it will get timestamped with an aligned value and
     * will be processed immediately next audio frame.
     */
    drvr->paramSamples &= ~0xf;


#ifdef AUD_PROFILE
    PROFILE_AUD(client_num, client_cnt, client_max, client_min);
#endif

    /*
     * Now build the command list in small chunks
     */
    while (outLen > 0){
        nOut = MIN(drvr->maxOutSamples, outLen);

        /*
         * construct the command list for each physical voice by calling
         * the head of the filter chain.
         */
        cmdPtr = cmdlEnd;
        aSegment(cmdPtr++, 0, 0);
        output = drvr->outputFilter;
        (*output->setParam)(output, AL_FILTER_SET_DRAM, lOutBuf);
        cmdlEnd = (*output->handler)(output, &tmp, nOut, drvr->curSamples,
                                     cmdPtr);
        
        outLen -= nOut;
        lOutBuf += nOut<<1;     /* For Stereo */
        drvr->curSamples += nOut;
                
    }
    *cmdLen = (s32) (cmdlEnd - cmdList);

    _collectPVoices(drvr); /* collect free physical voices */
    
#ifdef AUD_PROFILE
    PROFILE_AUD(drvr_num, drvr_cnt, drvr_max, drvr_min);
#endif
    return cmdlEnd;
}

/***********************************************************************
 * Synthesis driver private interfaces
 ***********************************************************************/

ALParam *__allocParam() 
{
    ALParam *update = 0;
    ALSynth *drvr = &alGlobals->drvr;

    if (drvr->paramList) {        
        update = drvr->paramList;
        drvr->paramList = drvr->paramList->next;
        update->next = 0;
    }
    return update;
}
    
void __freeParam(ALParam *param) 
{
    ALSynth *drvr = &alGlobals->drvr;
    param->next = drvr->paramList;
    drvr->paramList = param;
}

void _collectPVoices(ALSynth *drvr) 
{
    ALLink       *dl;
    PVoice      *pv;

    while ((dl = drvr->pLameList.next) != 0) {
        pv = (PVoice *)dl;

        /* ### remove from mixer */

        alUnlink(dl);
        alLink(dl, &drvr->pFreeList);        
    }
}

void _freePVoice(ALSynth *drvr, PVoice *pvoice) 
{
    /*
     * move the voice from the allocated list to the lame list
     */
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &drvr->pLameList);
}


/*
  Add 0.5 to adjust the average affect of
  the truncation error produced by casting
  a float to an int.
*/
s32 _timeToSamplesNoRound(ALSynth *synth, s32 micros)
{
    f32 tmp = ((f32)micros) * synth->outputRate / 1000000.0 + 0.5;

    return (s32)tmp;
}

s32 _timeToSamples(ALSynth *synth, s32 micros)
{
    return _timeToSamplesNoRound(synth, micros) & ~0xf;
}

static s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client) 
{
    ALMicroTime delta = 0x7fffffff;     /* max delta for s32 */
    ALPlayer *cl;

    assert(drvr->head);
    *client = 0;
    
    for (cl = drvr->head; cl != 0; cl = cl->next) {
        if ((cl->samplesLeft - drvr->curSamples) < delta) {
            *client = cl;
            delta = cl->samplesLeft - drvr->curSamples;
        }
    }

    return (*client)->samplesLeft;
}



