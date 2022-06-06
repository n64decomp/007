/*====================================================================
 * viblack.c
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

/**************************************************************************
 *
 *  $Revision: 1.2 $
 *  $Date: 1995/09/22 04:49:34 $
 *  $Source: /mdev2/PR/libultra/io/RCS/viblack.c,v $
 *
 **************************************************************************/

//#include "assert.h"
//#include "osint.h"
#include <os_internal.h>
//#include "rcp.h"
#include "viint.h"

/*
 * Name:   osViBlack
 *
 * Description:
 *	Generates black screen with sync pulses.
 *
 * When Nintendo 64 powers on, the boot code sets the timing to NTSC, PAL,
 * or MPAL and blanks out the video. The call to osCreateViManager initializes
 * the video to LAN1 (in either NTSC, PAL, or MPAL mode) and also blanks
 * interface to malfunction and enter a state that cannot be exited without
 * resetting the system.
 * 
 * Globals Referenced: 
 *	__osViNext
 */
void osViBlack(u8 active)
{
    register u32 saveMask;

    saveMask = __osDisableInt();

    if (active)
        __osViNext->state |= VI_STATE_BLACK;
    else
        __osViNext->state &= ~VI_STATE_BLACK;

    __osRestoreInt(saveMask);

} /* osViBlack */
