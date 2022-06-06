#ifndef _STDDEF_H_
#define _STDDEF_H_

#define NULL ((void *)0)

typedef unsigned long size_t;

#endif


#if 0
/*
*
* Copyright 1992, Silicon Graphics, Inc.
* All Rights Reserved.
*
* This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
* the contents of this file may not be disclosed to third parties, copied or
* duplicated in any form, in whole or in part, without the prior written
* permission of Silicon Graphics, Inc.
*
* RESTRICTED RIGHTS LEGEND:
* Use, duplication or disclosure by the Government is subject to restrictions
* as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
* and Computer Software clause at DFARS 252.227-7013, and/or in similar or
* successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
* rights reserved under the Copyright Laws of the United States.
*/
/*	Copyright (c) 1990, 1991 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/
#ifndef __STDDEF_H__
#define __STDDEF_H__
#ident "$Revision: 1.17 $"

#include <sgidefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

#if (_MIPS_SZPTR == 32)
    typedef int ptrdiff_t;
#endif
#if (_MIPS_SZPTR == 64)
    typedef __int64_t ptrdiff_t;
#endif

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#    define _SIZE_T
#    if (_MIPS_SZLONG == 32)
    typedef unsigned int size_t;
#    endif
#    if (_MIPS_SZLONG == 64)
    typedef unsigned long size_t;
#    endif
#endif

#ifndef NULL
#    define NULL 0
#endif

#ifndef _WCHAR_T
#    define _WCHAR_T
#    if (_MIPS_SZLONG == 32)
    typedef long wchar_t;
#    endif
#    if (_MIPS_SZLONG == 64)
    typedef __int32_t wchar_t;
#    endif
#endif

#define offsetof(s, m) (size_t)(&(((s *)0)->m))

#ifdef __cplusplus
}
#endif
#endif /* !__STDDEF_H__ */
#endif
