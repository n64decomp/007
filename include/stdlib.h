#ifndef _STDLIB_H_
#define _STDLIB_H_

typedef struct lldiv_t
{
    long long quot;
    long long rem;
} lldiv_t;

typedef struct ldiv_t
{
    long quot;
    long rem;
} ldiv_t;

lldiv_t lldiv(long long, long long);
ldiv_t  ldiv(long, long);

#endif


#if 0
#ifndef __STDLIB_H__
#define __STDLIB_H__
#ifdef __cplusplus
extern "C" {
#endif
#ident "$Revision: 1.34 $"
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

#include <sgidefs.h>

#ifndef	NULL
#define NULL	0
#endif

/* Arguments to exit(2). */
#define EXIT_FAILURE	1
#define EXIT_SUCCESS	0

/* Maximum value returned by rand(3C). */
#define RAND_MAX	32767

#ifdef _LANGUAGE_ASSEMBLY
/* assembly-level offsets of quot, rem fields into [l ]div_t structure below */
#define _QUOT_OFFSET 	0
#define _REM_OFFSET	4
#if (_MIPS_SZLONG == 32)
#define _LQUOT_OFFSET 	0
#define _LREM_OFFSET	4
#endif
#if (_MIPS_SZLONG == 64)
#define _LQUOT_OFFSET 	0
#define _LREM_OFFSET	8
#endif
#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
#define _LLQUOT_OFFSET 	0
#define _LLREM_OFFSET	8
#endif
#endif 

#if (defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS))
typedef	struct {
	 int	quot;
	 int	rem;
	} div_t;

typedef struct {
	 long	quot;
	 long	rem;
	} ldiv_t;

#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
typedef struct {
	 long long	quot;
	 long long	rem;
	} lldiv_t;
#endif

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#if (_MIPS_SZLONG == 32)
typedef unsigned int	size_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef unsigned long	size_t;
#endif
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
#if (_MIPS_SZLONG == 32)
typedef int	ssize_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef long	ssize_t;
#endif
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
#if (_MIPS_SZLONG == 32)
typedef long wchar_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef __int32_t wchar_t;
#endif
#endif

extern unsigned char 	__ctype[];	

#define MB_CUR_MAX	(int)__ctype[520]	

extern double atof(const char *);
extern int atoi(const char *);
extern long int atol(const char *);
extern double strtod(const char *, char **);
extern long int strtol(const char *, char **, int);
extern unsigned long int strtoul(const char *, char **, int);
#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
extern long long int atoll(const char *);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
#endif

extern int rand(void);
extern void srand(unsigned int);

extern void *calloc(size_t, size_t);
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);

extern void abort(void);
extern int atexit(void (*)(void));
extern void exit(int);
extern char *getenv(const char *);
extern int system(const char *);

extern void *bsearch(const void *, const void *, size_t, size_t,
	int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t,
	int (*)(const void *, const void *));

#ifdef __cplusplus
#ifndef _ABS_
#define _ABS_
inline int abs(int x) {return x > 0 ? x : -x;}
#endif
#else
extern int abs(int);
#endif

extern div_t div(int, int);
extern long int labs(long);
extern ldiv_t ldiv(long, long);
#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
extern long long llabs(long long);
extern lldiv_t lldiv(long long, long long);
#endif

extern int mbtowc(wchar_t *, const char *, size_t);
extern int mblen(const char *, size_t);
extern int wctomb(char *, wchar_t);

extern size_t mbstowcs(wchar_t *, const char *, size_t);
extern size_t wcstombs(char *, const wchar_t *, size_t);

#if defined(_SVR4_SOURCE) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)

extern long a64l(const char *);
extern int dup2(int, int);
extern char *ecvt(double, int, int *, int *);
extern char *fcvt(double, int, int *, int *);
extern char *getcwd(char *, size_t);
extern char *getlogin(void);
#include <getopt.h>
extern char *getpass(const char *);
extern int getpw(int, char *);
extern char *gcvt(double, int, char *);
extern int isatty(int);
extern void l3tol(long *, const char *, int);
extern char *l64a(long);
extern void ltol3(char *, const long *, int);
extern void * memalign(size_t, size_t);
extern char *mktemp(char *);
extern int putenv(char *);
extern char *realpath(const char *, char *);
extern void swab(const char *, char *, int);
extern char *ttyname(int);
extern int ttyslot(void);
extern void *valloc(size_t);

extern double	drand48(void);
extern double	erand48(unsigned short [3]);
extern long	lrand48(void);
extern long	nrand48(unsigned short [3]);
extern long	mrand48(void);
extern long	jrand48(unsigned short [3]);
extern void	srand48(long);
extern unsigned short * seed48(const unsigned short [3]);
extern void	lcong48(const unsigned short [7]);

#endif	/* _SVR4_SOURCE && !POSIX_SOURCE && !_XOPEN_SOURCE */
#if (defined(_SGI_SOURCE) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)) || defined(_SGI_REENTRANT_FUNCTIONS)

extern int rand_r(unsigned int *);
extern char *ttyname_r(int, char *, int);
extern char *ecvt_r(double, int, int *, int *, char *);
extern char *fcvt_r(double, int, int *, int *, char *);
#endif

#define mblen(s, n)	mbtowc((wchar_t *)0, s, n)
#endif /* _LANGUAGE_C || _LANGUAGE_C_PLUS_PLUS */

#ifdef __cplusplus
}
#endif
#endif /* !__STDLIB_H__ */
#endif
