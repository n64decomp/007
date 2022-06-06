/**************************************************************************
 *									  *
 *		 Copyright (C) 1995, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/**************************************************************************
 *
 *  $Revision: 1.18 $
 *  $Date: 1997/02/11 08:26:14 $
 *  $Source: /disk6/Master/cvsmdev2/PR/include/os_internal.h,v $
 *
 **************************************************************************/

#ifndef _OS_INTERNAL_H_
#define	_OS_INTERNAL_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/os.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* Routines to get/fetch coprocessor 0 registers */

extern u32		__osGetCause(void);
extern void		__osSetCause(u32);
extern u32		__osGetCompare(void);
extern void		__osSetCompare(u32);
extern u32		__osGetConfig(void);
extern void		__osSetConfig(u32);
extern void		__osSetCount(u32);
extern u32		__osGetSR(void);
extern void		__osSetSR(u32);
extern u32		__osDisableInt(void);
extern void		__osRestoreInt(u32);

/* Routines to get/set floating-point control and status register */
extern u32              __osSetFpcCsr(u32);
extern u32              __osGetFpcCsr(void);

/* Routine for HW interrupt "handler" */
extern void		__osSetHWIntrRoutine(OSHWIntr, s32 (*handler)(void));

/* Routine for global interrupt mask */
extern void		__osSetGlobalIntMask(OSHWIntr);
extern void		__osResetGlobalIntMask(OSHWIntr);

/* Routine for global interrupt mask */
extern s32		__osLeoInterrupt(void);

/* Routines for fetch TLB info */

extern u32		__osGetTLBASID(void);
extern u32		__osGetTLBPageMask(s32);
extern u32		__osGetTLBHi(s32);
extern u32		__osGetTLBLo0(s32);
extern u32		__osGetTLBLo1(s32);

/* Serial interface (Si) */

extern u32 		__osSiGetStatus(void);
extern s32		__osSiRawWriteIo(u32, u32);
extern s32		__osSiRawReadIo(u32, u32 *);
extern s32		__osSiRawStartDma(s32, void *);

/* Signal processor interface (Sp) */

extern u32 		__osSpGetStatus(void);
extern void		__osSpSetStatus(u32);
extern s32		__osSpSetPc(u32);
extern s32		__osSpRawWriteIo(u32, u32);
extern s32		__osSpRawReadIo(u32, u32 *);
extern s32		__osSpRawStartDma(s32, u32, void *, u32);

/* Error handling */

extern void		__osError(s16, s16, ...);
extern OSThread *	__osGetCurrFaultedThread(void);
extern OSThread *	__osGetNextFaultedThread(OSThread *);

/* Development board functions */

extern void		__osGIOInit(s32);
extern void		__osGIOInterrupt(s32);
extern void		__osGIORawInterrupt(s32);

/* For debugger use */

extern OSThread *	__osGetActiveQueue(void);

/* Debug port */
extern void		__osSyncPutChars(int, int, const char *);
extern int		__osSyncGetChars(char *);
extern void		__osAsyncPutChars(int, int, const char *);
extern int		__osAsyncGetChars(char *);
extern int		__osAtomicInc(unsigned int *p);
extern int		__osAtomicDec(unsigned int *p);

/* routine for rdb port */
extern u32             __osRdbSend(u8 *buf, u32 size, u32 type);


#endif /* _LANGUAGE_C */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_INTERNAL_H */
