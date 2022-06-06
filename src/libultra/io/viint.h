#ifndef _VIINT_H_
#define _VIINT_H_
#    include <os_internal.h>

/*====================================================================
 * viint.h
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
 *  $Revision: 1.11 $
 *  $Date: 1995/09/14 06:14:10 $
 *  $Source: /mdev2/PR/libultra/io/RCS/viint.h,v $
 *
 *  Description:
 *      This file contains defines and structures used internally in the VI 
 *	APIs.
 *
 **************************************************************************/

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C"
{
#endif

#if 1//def _LANGUAGE_C

    /**************************************************************************
 * Video mode definitions
 *
 * Use 5 bits to uniquely define a mode
 *
 *                 video format
 *                 |       resolution
 *                 |       |       pixel size
 *                 |       |       |       antialiasing(aa)/point-sampling(ps)
 *                 |       |       |       |       interlace
 * mode            |       |       |       |       |
 * ---------       -       -       -       -       -
 * vi_ntsc_lpn1    ntsc    lo      16      ps      non-interlace
 * vi_ntsc_lpf1    ntsc    lo      16      ps      interlace
 * vi_ntsc_lan1    ntsc    lo      16      aa      non-interlace
 * vi_ntsc_laf1    ntsc    lo      16      aa      interlace
 * vi_ntsc_lpn2    ntsc    lo      32      ps      non-interlace
 * vi_ntsc_lpf2    ntsc    lo      32      ps      interlace
 * vi_ntsc_lan2    ntsc    lo      32      aa      non-interlace
 * vi_ntsc_laf2    ntsc    lo      32      aa      interlace
 * vi_ntsc_hpn1    ntsc    hi      16      ps      normal interlace
 * vi_ntsc_hpf1    ntsc    hi      16      ps      deflickered interlace
 * vi_ntsc_han1    ntsc    hi      16      aa      normal interlace
 * vi_ntsc_haf1    ntsc    hi      16      aa      deflickered interlace
 * vi_ntsc_hpn2    ntsc    hi      32      ps      normal interlace
 * vi_ntsc_hpf2    ntsc    hi      32      ps      deflickered interlace
 * 
 * vi_pal_lpn1     pal     lo      16      ps      non-interlace
 * vi_pal_lpf1     pal     lo      16      ps      interlace
 * vi_pal_lan1     pal     lo      16      aa      non-interlace
 * vi_pal_laf1     pal     lo      16      aa      interlace
 * vi_pal_lpn2     pal     lo      32      ps      non-interlace
 * vi_pal_lpf2     pal     lo      32      ps      interlace
 * vi_pal_lan2     pal     lo      32      aa      non-interlace
 * vi_pal_laf2     pal     lo      32      aa      interlace
 * vi_pal_hpn1     pal     hi      16      ps      normal interlace
 * vi_pal_hpf1     pal     hi      16      ps      deflickered interlace
 * vi_pal_han1     pal     hi      16      aa      normal interlace
 * vi_pal_haf1     pal     hi      16      aa      deflickered interlace
 * vi_pal_hpn2     pal     hi      32      ps      normal interlace
 * vi_pal_hpf2     pal     hi      32      ps      deflickered interlace
 * 
 * Bit  0: non-interlace (lores)
 * Bit  1: interlace (lores)
 * Bit  2: normal interlace (hires)
 * Bit  3: deflickered interlace (hires)
 * Bit  4: antialiasing (aa)
 * Bit  5: point-sampling (ps)
 * Bit  6: 16-bit pixel size 
 * Bit  7: 32-bit pixel size 
 * Bit  8: low resolution
 * Bit  9: high resolution
 * Bit 10: NTSC video format
 * Bit 11: PAL video format
 *
 **************************************************************************/

#    define VI_FIELD1 0
#    define VI_FIELD2 1

/**************************************************************************
 * VI internal states 
 */
#    define VI_STATE_NORMAL     0x00
#    define VI_STATE_MODE       0x01
#    define VI_STATE_X_SCALE    0x02
#    define VI_STATE_Y_SCALE    0x04
#    define VI_STATE_CONTROL    0x08 //related to control regs changing
#    define VI_STATE_FRAME      0x10 //swap buffer
#    define VI_STATE_BLACK      0x20 //probably related to a black screen
#    define VI_STATE_REPEATLINE 0x40 //repeat line?
#    define VI_STATE_FADE       0x80 //fade

    /**************************************************************************
 * Structure to hold scaling value (x, y)
 */
    typedef struct
    {
        f32 factor; /* Scaling factor 0.0 <= x <= 1.0 */
        u16 offset; /* Result origin offset (16-bit) */
        u32 scale;  /* Result scale (12-bit) */
    } __OSViScale;

    /**************************************************************************
 * Structure for VI context
 */
    typedef struct
    {
        u16 state;         /* internal state */
        u16 retraceCount;  /* Number of retrace before get msg */
        void *framep;      /* pointer to frame buffer */
        OSViMode *modep;   /* pointer to standard mode struct */
        u32 control;       /* VI control value */
        OSMesgQueue *msgq; /* Application message queue */
        OSMesg msg;        /* Application message */
        __OSViScale x;     /* X-scaling */
        __OSViScale y;     /* Y-scaling */
    } __OSViContext;

    /**************************************************************************
 *
 * Extern global variables
 *
 */
    extern OSDevMgr __osViDevMgr;
    extern __OSViContext *__osViCurr;
    extern __OSViContext *__osViNext;

    /**************************************************************************
 *
 * Function prototypes
 *
 */
    extern void __osViCreateAccessQueue(void);
    extern OSMesgQueue *__osViGetAccessQueue(void);
    extern void __osViGetAccess(void);
    extern void __osViRelAccess(void);

    extern void __osViInit(void);
    extern __OSViContext *__osViGetCurrentContext(void);
    extern __OSViContext *__osViGetNextContext(void);
    extern void __osViSwapContext(void);

#endif /* _LANGUAGE_C */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

//extra defines and inline funcs

#define OS_TV_TYPE_PAL 0
#define OS_TV_TYPE_NTSC 1
#define OS_TV_TYPE_MPAL 2

#define VI_CTRL_ANTIALIAS_MODE_3 0x00300 /* Bit [9:8] anti-alias mode */
#define VI_CTRL_ANTIALIAS_MODE_2 0x00200 /* Bit [9:8] anti-alias mode */
#define VI_CTRL_ANTIALIAS_MODE_1 0x00100 /* Bit [9:8] anti-alias mode */

#define VI_SCALE_MASK 0xfff //see rcp scale_x/scale_y
#define VI_2_10_FPART_MASK 0x3ff
#define VI_SUBPIXEL_SH 0x10

#define BURST(hsync_width, color_width, vsync_width, color_start) \
    (hsync_width | (color_width << 8) | (vsync_width << 16) | (color_start << 20))
#define WIDTH(v) v
#define VSYNC(v) v
#define HSYNC(duration, leap) (duration | (leap << 16))
#define LEAP(upper, lower) ((upper << 16) | lower)
#define START(start, end) ((start << 16) | end)

#define FTOFIX(val, i, f) ((u32)(val * (f32)(1 << f)) & ((1 << (i + f)) - 1))

#define F210(val) FTOFIX(val, 2, 10)
#define SCALE(scaleup, off) (F210((1.0f / (f32)scaleup)) | (F210((f32)off) << 16))

#define VCURRENT(v) v //seemingly unused
#define ORIGIN(v) v
#define VINTR(v) v
#define HSTART START

#endif /* _VIINT_H_ */
