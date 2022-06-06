/*====================================================================
 * synallocvoice.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
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

#include <os_internal.h>
#include <ultraerror.h>
#include "synthInternals.h"

s32 _allocatePVoice(ALSynth *drvr, PVoice **pvoice, s16 priority);

s32 alSynAllocVoice(ALSynth *drvr, ALVoice *voice, ALVoiceConfig *vc)
{
    PVoice  *pvoice = 0;
    ALFilter *f;
    ALParam *update;
    s32 stolen;
    
#ifdef _DEBUG
    /* need two updates if voice is stolen */
    if (drvr->paramList == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    } else if (drvr->paramList->next == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    }
#endif    

    voice->priority     = vc->priority;
    voice->unityPitch   = vc->unityPitch;
    voice->table        = 0;
    voice->fxBus        = vc->fxBus;
    voice->state        = AL_STOPPED;        
    voice->pvoice       = 0;

    stolen = _allocatePVoice(drvr, &pvoice, vc->priority);
        
    if (pvoice) {    /* if we were able to allocate a voice */

        f = pvoice->channelKnob;            
            
        if (stolen) {
                
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0; /* zero stolen voice */
                
            /*
             * ramp down stolen voice
             */
            update = __allocParam();
            update->delta      = drvr->paramSamples;
            update->type       = AL_FILTER_SET_VOLUME;
            update->data.i     = 0;
            update->moredata.i = pvoice->offset - 64;
            (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);

            /*
             * stop stolen voice
             */
            update = __allocParam();
            if (update) {
                update->delta  = drvr->paramSamples + pvoice->offset;
                update->type   = AL_FILTER_STOP_VOICE;
                update->next   = 0;
                (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
            } else {
#ifdef _DEBUG                
                __osError(ERR_ALSYN_NO_UPDATE, 0);
#endif
            }

        } else {
            pvoice->offset = 0;
        }
            
        pvoice->vvoice = voice;     /* assign new voice  */
        voice->pvoice  = pvoice;

    }
    
    return (pvoice != 0);    
}

s32 _allocatePVoice(ALSynth *drvr, PVoice **pvoice, s16 priority)
{
    ALLink      *dl;
    PVoice      *pv;
    s32         stolen = 0;
    
    if ((dl = drvr->pLameList.next) != 0) { /* check the lame list first */
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);        
    } else if ((dl = drvr->pFreeList.next) != 0) { /* from the free list */
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);        
    } else { /* steal one */
        for (dl = drvr->pAllocList.next; dl != 0; dl = dl->next) {
            pv = (PVoice *)dl;

            /*
             * if it is lower priority and not already stolen, keep it
             * as a candidate for stealing
             */
            if ((pv->vvoice->priority <= priority) && (pv->offset == 0)) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = 1;
            }
        }
    }
    
    return stolen;
}

