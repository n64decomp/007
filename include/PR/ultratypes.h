#ifndef _ULTRA64_TYPES_H_
#define _ULTRA64_TYPES_H_

/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1995, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 **************************************************************************/

/*************************************************************************
 *
 *  File: ultratypes.h
 *
 *  This file contains various types used in Ultra64 interfaces.
 *
 *  $Header: /mdev2/PR/include/RCS/ultratypes.h,v 1.4 1995/03/29 00:52:13 jeffd Exp $
 *
 */

/**********************************************************************
 * General data types for R4300
 */
#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

typedef unsigned char               u8;  /* unsigned  8-bit */
typedef unsigned short              u16; /* unsigned 16-bit */
typedef unsigned int                u32; /* unsigned 32-bit */
typedef unsigned long long          u64; /* unsigned 64-bit */

typedef signed char                 s8;  /* signed  8-bit */
typedef short                       s16; /* signed 16-bit */
typedef int                         s32; /* signed 32-bit */
typedef long long                   s64; /* signed 64-bit */

typedef volatile unsigned char      vu8;  /* unsigned  8-bit */
typedef volatile unsigned short     vu16; /* unsigned 16-bit */
typedef volatile unsigned int       vu32; /* unsigned 32-bit */
typedef volatile unsigned long long vu64; /* unsigned 64-bit */

typedef volatile signed char        vs8;  /* signed  8-bit */
typedef volatile short              vs16; /* signed 16-bit */
typedef volatile int                vs32; /* signed 32-bit */
typedef volatile long long          vs64; /* signed 64-bit */

typedef float                       f32; /* single prec floating point */
typedef double                      f64; /* double prec floating point */

#endif /* _LANGUAGE_C */

/*************************************************************************
 * Common definitions
 */
#ifndef TRUE
#    define TRUE 1
#endif

#ifndef FALSE
#    define FALSE 0
#endif

#ifndef NULL
#    define NULL (void *)0
#endif

//this section is from stddef.h and should go back there
#ifdef TARGET_N64
    typedef u32 size_t;
    typedef s32 ssize_t;
    typedef u32 uintptr_t;
    typedef s32 intptr_t;
    typedef s32 ptrdiff_t;
#else
    #include <stddef.h>
    #include <stdint.h>
    typedef ptrdiff_t ssize_t;
#endif

#endif /* _ULTRATYPES_H_ */
