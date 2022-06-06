/*====================================================================
 * resample.c
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

#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>

#ifdef AUD_PROFILE
extern u32 cnt_index, resampler_num, resampler_cnt, resampler_max, resampler_min, lastCnt[];
#endif

/***********************************************************************
 * Resampler filter public interfaces
 ***********************************************************************/
Acmd *alResamplePull(void *filter, s16 *outp, s32 outCnt, s32 sampleOffset, Acmd *p) 
{
    ALResampler *f = (ALResampler *)filter;
    Acmd        *ptr = p;
    s16         inp;
    s32         inCount;
    ALFilter    *source = f->filter.source;
    s32		incr;
    f32         finCount;
    
#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif
    
    inp = AL_DECODER_OUT;

    if (!outCnt)
        return ptr;

    /*
     * check if resampler is required
     */
    if (f->upitch) {

	ptr = (*source->handler)(source, &inp, outCnt, sampleOffset, p);
	aDMEMMove(ptr++, inp, *outp, outCnt<<1);

    } else {

	/*
	 * clip to maximum allowable pitch
	 * FIXME: should we check for some minimum as well?
	 */
	if (f->ratio > MAX_RATIO) f->ratio = MAX_RATIO;

	/*
	 * quantize the pitch
	 */
	f->ratio = (s32)(f->ratio * UNITY_PITCH);
	f->ratio = f->ratio / UNITY_PITCH;

	/*
	 * determine how many samples to generate
	 */
	finCount = f->delta + (f->ratio * (f32) outCnt);
	inCount = (s32) finCount;
	f->delta = finCount - (f32)inCount;

	/*
	 * ask all filters upstream from us to build their command
	 * lists.
	 */
	ptr = (*source->handler)(source, &inp, inCount, sampleOffset, p);

	/*
	 * construct our portion of the command list
	 */
	incr = (s32)(f->ratio * UNITY_PITCH);
	aSetBuffer(ptr++, 0, inp, *outp, outCnt<<1);
	aResample(ptr++, f->first, incr, osVirtualToPhysical(f->state));
	f->first = 0;
    }
    
#ifdef AUD_PROFILE
    PROFILE_AUD(resampler_num, resampler_cnt, resampler_max, resampler_min);
#endif
    return ptr;
}

s32 alResampleParam(void *filter, s32 paramID, void *param)
{
    ALFilter      *f = (ALFilter *) filter;
    ALResampler   *r = (ALResampler *) filter;
    union {
        f32             f;
        s32             i;
    } data;
    
    switch (paramID) {

        case (AL_FILTER_SET_SOURCE):
            f->source = (ALFilter *) param;
            break;
	  
        case (AL_FILTER_RESET):
            r->delta  = 0.0;
            r->first  = 1;
            r->motion = AL_STOPPED;
            r->upitch = 0;
            if (f->source)
                (*f->source->setParam)(f->source, AL_FILTER_RESET, 0);
            break;

        case (AL_FILTER_START):
            r->motion = AL_PLAYING;
            if (f->source)
                (*f->source->setParam)(f->source, AL_FILTER_START, 0);
            break;
            
        case (AL_FILTER_SET_PITCH):
            data.i = (s32) param;
            r->ratio = data.f;
            break;
            
	case (AL_FILTER_SET_UNITY_PITCH):
	    r->upitch = 1;
            break;
            
        default:
            if (f->source)
                (*f->source->setParam)(f->source, paramID, param);
            break;
    }
    return 0;
}
