/*====================================================================
 * save.c
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
#include "include/assert.h"

Acmd *alSavePull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                 Acmd *p) 

{
    Acmd        *ptr = p;
    ALSave *f = (ALSave *)filter;
    ALFilter    *source = f->filter.source;

    assert(f->filter.source);
    
    ptr = (*source->handler)(source, outp, outCount, sampleOffset, ptr);
    
    aSetBuffer (ptr++, 0, 0, 0, outCount<<1);
    aInterleave(ptr++, AL_MAIN_L_OUT, AL_MAIN_R_OUT);
    aSetBuffer (ptr++, 0, 0, 0, outCount<<2);
    aSaveBuffer(ptr++, f->dramout);
    return ptr;
}

s32 alSaveParam(void *filter, s32 paramID, void *param)
{
    ALSave *a = (ALSave *) filter;
    ALFilter *f = (ALFilter *) filter;
    s32 pp = (s32) param;

    switch (paramID) {
        case (AL_FILTER_SET_SOURCE):
            f->source = (ALFilter *) param;
            break;

        case (AL_FILTER_SET_DRAM): 
            a->dramout = pp;
            break;
            
        default:
            break;
    }
    return 0;
            
}



