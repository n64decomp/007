/*====================================================================
 * heapinit.c
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

#include "synthInternals.h"
#include <libaudio.h>

void alHeapInit(ALHeap *hp, u8 *base, s32 len)
{
    s32 extraAlign = (AL_CACHE_ALIGN+1) - ((s32) base & AL_CACHE_ALIGN);
    
    if (extraAlign != AL_CACHE_ALIGN+1)
        hp->base = base + extraAlign;
    else
        hp->base = base;

    hp->len  = len;
    hp->cur  = hp->base;
    hp->count = 0;
}
