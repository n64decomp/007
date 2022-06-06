#ifndef _LIMITS_H
#define _LIMITS_H

/* Sizes of integral types */
#define CHAR_BIT  8      /* max # of bits in a "char" */
#define SCHAR_MIN (-128) /* min value of a "signed char" */
#define SCHAR_MAX 127    /* max value of a "signed char" */
#define UCHAR_MAX 255U   /* max value of an "unsigned char" */

#define MB_LEN_MAX 5

#define CHAR_MIN 0         /* min value of a "char" */
#define CHAR_MAX UCHAR_MAX /* max value of a "char" */

#define SHRT_MIN  (-32768)          /* min value of a "short int" */
#define SHRT_MAX  32767             /* max value of a "short int" */
#define USHRT_MAX 65535U            /* max value of an "unsigned short int" */
#define INT_MIN   (-2147483648)     /* min value of an "int" */
#define INT_MAX   2147483647        /* max value of an "int" */
#define UINT_MAX  4294967295U       /* max value of an "unsigned int" */
#if (_MIPS_SZLONG == 32)
#    define LONG_MIN  (-2147483648)     /* min value of a "long int" */
#    define LONG_MAX  2147483647        /* max value of a "long int" */
#    define ULONG_MAX 4294967295U       /* max value of an "unsigned long int" */
#endif
#if (_MIPS_SZLONG == 64)
#    define LONG_MIN  (-9223372036854775807L - 1L) /* min value of a "long int" */
#    define LONG_MAX  9223372036854775807L         /* max value of a "long int" */
#    define ULONG_MAX 18446744073709551615LU       /* max value of an "unsigned long int" */
#endif

#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
#    define LONGLONG_MIN  (-9223372036854775808LL)       /* min "long long int" */
#    define LONGLONG_MAX  9223372036854775807LL          /* max "long long int" */
#    define ULONGLONG_MAX 18446744073709551615LLU        /* max "unsigned long long int" */
#endif

#define DBL_DIG 15                      /* digits of precision of a "double" */
#define DBL_MAX 1.7976931348623157E+308 /* max decimal value of a "double"*/
#define DBL_MIN 2.2250738585072014E-308 /* min decimal value of a "double"*/
#define FLT_DIG 6                       /* digits of precision of a "float" */
#ifdef __STDC__
#    define FLT_MAX 3.40282347E+38F /* max decimal value of a "float" */
#    define FLT_MIN 1.17549435E-38F /* min decimal value of a "float" */
#else
#    define FLT_MAX 3.40282347E+38 /* max decimal value of a "float" */
#    define FLT_MIN 1.17549435E-38 /* min decimal value of a "float" */
#endif                             /* __STDC__ */

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
/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/
#ifndef __LIMITS_H__
#define __LIMITS_H__

#ident "$Revision: 7.27 $"
#include <sgidefs.h> removed for now, add back later

#ifdef __cplusplus
extern "C"
{
#endif

/* Sizes of integral types */
#define CHAR_BIT  8      /* max # of bits in a "char" */
#define SCHAR_MIN (-128) /* min value of a "signed char" */
#define SCHAR_MAX 127    /* max value of a "signed char" */
#define UCHAR_MAX 255U   /* max value of an "unsigned char" */

#define MB_LEN_MAX 5

#define CHAR_MIN 0         /* min value of a "char" */
#define CHAR_MAX UCHAR_MAX /* max value of a "char" */

#define SHRT_MIN  (-32768)          /* min value of a "short int" */
#define SHRT_MAX  32767             /* max value of a "short int" */
#define USHRT_MAX 65535U            /* max value of an "unsigned short int" */
#define INT_MIN   (-2147483647 - 1) /* min value of an "int" */
#define INT_MAX   2147483647        /* max value of an "int" */
#define UINT_MAX  4294967295U       /* max value of an "unsigned int" */
#if (_MIPS_SZLONG == 32)
#    define LONG_MIN  (-2147483647 - 1) /* min value of a "long int" */
#    define LONG_MAX  2147483647        /* max value of a "long int" */
#    define ULONG_MAX 4294967295U       /* max value of an "unsigned long int" */
#endif
#if (_MIPS_SZLONG == 64)
#    define LONG_MIN  (-9223372036854775807L - 1L) /* min value of a "long int" */
#    define LONG_MAX  9223372036854775807L         /* max value of a "long int" */
#    define ULONG_MAX 18446744073709551615LU       /* max value of an "unsigned long int" */
#endif

#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
#    define LONGLONG_MIN  (-9223372036854775807LL - 1LL) /* min "long long int" */
#    define LONGLONG_MAX  9223372036854775807LL          /* max "long long int" */
#    define ULONGLONG_MAX 18446744073709551615LLU        /* max "unsigned long long int" */
#endif


#if defined(_SVR4_SOURCE) || defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE)

#    define NGROUPS_MAX 16 /* max number of groups for a user */
    /*
 * ARG_MAX
 * CHILD_MAX
 * OPEN_MAX
 * STREAM_MAX
 *
 * PATH_MAX
 * NAME_MAX
 * LINK_MAX
 * - are available only thru sysconf/pathconf
 */

#    ifndef PIPE_BUF
#        define PIPE_BUF 10240 /* max # bytes atomic in pipe write */
#    endif

#    define TZNAME_MAX 8 /* max # bytes for time zone name */

#    ifndef TMP_MAX
#        define TMP_MAX 17576 /* 26 * 26 * 26 */
#    endif

    /* POSIX conformant definitions - An implementation may define
** other symbols which reflect the actual implementation. Alternate
** definitions may not be as restrictive as the POSIX definitions.
*/

#    define _POSIX_ARG_MAX     4096
#    define _POSIX_CHILD_MAX   6
#    define _POSIX_LINK_MAX    8
#    define _POSIX_MAX_CANON   255
#    define _POSIX_MAX_INPUT   255
#    define _POSIX_NAME_MAX    14
#    define _POSIX_NGROUPS_MAX 0
#    define _POSIX_OPEN_MAX    16
#    define _POSIX_PATH_MAX    255
#    define _POSIX_PIPE_BUF    512
#    define _POSIX_SSIZE_MAX   32767
#    define _POSIX_STREAM_MAX  8
#    define _POSIX_TZNAME_MAX  3

#    ifndef MAX_CANON
#        define MAX_CANON 256
#    endif

#    ifndef MAX_INPUT
#        define MAX_INPUT 512
#    endif

#    define SSIZE_MAX LONG_MAX /* yes, its an int but this does the \
                                * right thingh for 64 bits */

#endif

#if (defined(_SVR4_SOURCE) && !defined(_POSIX_SOURCE)) || defined(_XOPEN_SOURCE)

#    define PASS_MAX 8 /* max # of characters in a password */

#    define NL_ARGMAX  9  /* max value of "digit" in calls to the \
                           * NLS printf() and scanf() */
#    define NL_LANGMAX 14 /* max # of bytes in a LANG name */
#    define NL_NMAX    1  /* max # of bytes in N-to-1 mapping characters */
/* also defined in nl_types.h */
#    ifndef NL_SETMAX
#        define NL_SETMAX  255
#        define NL_MSGMAX  32767
#        define NL_TEXTMAX 255
#    endif
#    ifndef NZERO
#        define NZERO 20 /* default process priority */
#    endif

#    define WORD_BIT 32 /* # of bits in a "word" or "int" */
#    if (_MIPS_SZLONG == 32)
#        define LONG_BIT 32 /* # of bits in a "long" */
#    endif
#    if (_MIPS_SZLONG == 64)
#        define LONG_BIT 64 /* # of bits in a "long" */
#    endif

#    define DBL_DIG 15                      /* digits of precision of a "double" */
#    define DBL_MAX 1.7976931348623157E+308 /* max decimal value of a "double"*/
#    define DBL_MIN 2.2250738585072014E-308 /* min decimal value of a "double"*/
#    define FLT_DIG 6                       /* digits of precision of a "float" */
#    ifdef __STDC__
#        define FLT_MAX 3.40282347E+38F /* max decimal value of a "float" */
#        define FLT_MIN 1.17549435E-38F /* min decimal value of a "float" */
#    else
#        define FLT_MAX 3.40282347E+38 /* max decimal value of a "float" */
#        define FLT_MIN 1.17549435E-38 /* min decimal value of a "float" */
#    endif                             /* __STDC__ */

#endif /* (_SVR4_SOURCE && !defined(_POSIX_SOURCE)) || defined(_XOPEN_SOURCE) */

#if defined(_SVR4_SOURCE) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)

/*
 * Note that for POSIX/XPG3: ARG_MAX, CHILD_MAX, NAME_MAX, OPEN_MAX, PATH_MAX,
 * come LINK_MAX only from sysconf/pathconf, but for default environment we
 * put in backward compatibility defines
 */
#    define FCHR_MAX  2147483647 /* max size of a file in bytes */
#    define PID_MAX   30000      /* max value for a process ID */
#    define CHILD_MAX 25         /* max # of processes per user id */
#    define NAME_MAX  255        /* max # of characters in a file name */
#    define LINK_MAX  30000      /* max # of links to a single file */

#    ifndef OPEN_MAX
#        if i386
#            define OPEN_MAX 60 /* max # of files a process can have open */
#        else
#            define OPEN_MAX 20 /* max # of files a process can have open */
#        endif
#    endif

#    ifndef PIPE_MAX
#        define PIPE_MAX 10240 /* max # bytes written to pipe in a wrt */
#    endif

#    define STD_BLK    1024       /* # bytes in a physical I/O block */
#    define UID_MAX    60002      /* max value for a user or group ID */
#    define USI_MAX    4294967295 /* max decimal value of an "unsigned" */
#    define SYSPID_MAX 1          /* max pid of system processes */

#    ifndef PATH_MAX
#        define PATH_MAX 1024 /* max # of characters in a path name */
#    endif
#    ifndef ARG_MAX
#        define ARG_MAX 5120
#    endif

#    if !defined(SYS_NMLN)
#        define SYS_NMLN 257 /* SVR4.0 size of utsname elements */
    /* also defined in sys/utsname.h */
#    endif /* !SYS_NMLN */

#    ifndef CLK_TCK
#        define CLK_TCK sysconf(3) /* clock ticks per second */
    /* 3 is _SC_CLK_TCK */
#    endif

#    define LOGNAME_MAX 8 /* max # of characters in a login name */

#endif

#if defined(_SGI_SOURCE) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
#    if (defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS))
#        ifndef HUGE_VAL
#            ifndef __TYPEDEF_H_VAL
#                define __TYPEDEF_H_VAL
    typedef union _h_val
    {
#                if (_MIPS_SZLONG == 32)
        unsigned long i[2];
#                endif
#                if (_MIPS_SZLONG == 64)
        __uint32_t i[2];
#                endif
        double d;
    } _h_val;
#            endif /* __TYPEDEF_H_VAL */
    extern const _h_val __huge_val;
#            define HUGE_VAL __huge_val.d
#        endif /* !HUGE_VAL */
#    endif     /* _LANGUAGE_C || _LANGUAGE_C_PLUS_PLUS */
#endif

#if (defined(_SVR4_SOURCE) || defined(_SGI_SOURCE) || defined(_POSIX_SOURCE)) && !defined(_XOPEN_SOURCE)

#    define _POSIX_AIO_MAX        1 /* number of oustanding async I/O ops */
#    define _POSIX_AIO_LISTIO_MAX 2 /* number of I/O operations per lio */
#    define _ABI_AIO_XFER_MAX     (128 * 1024)
#    define _POSIX_RTSIG_MAX      8  /* max RT signals for application use */
#    define _POSIX_SIGQUEUE_MAX   32 /* max # of queued signals pending */
#endif                               /*  _SGI_SOURCE || (_POSIX_SOURCE && !_XOPEN_SOURCE */
#ifdef __cplusplus
}
#endif
#endif /* !__LIMITS_H__ */
#endif
