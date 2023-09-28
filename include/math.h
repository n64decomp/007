

#ifndef _MATH_EXT_H_
#define _MATH_EXT_H_

/* Some useful constants */
/*  The base of natural logarithms, e.*/
#define M_E        2.7182818284590452354
/*  The base 2 logarithm of e. (log2e)*/
#define M_LOG2E    1.4426950408889634074
/*  The base 10 logarithm of e. (log10e)*/
#define M_LOG10E   0.43429448190325182765
/*  The natural logarithm of 2. (ln 2)*/
#define M_LN2      0.69314718055994530942
/*  The natural logarithm of 10. (ln 10)*/
#define M_LN10     2.30258509299404568402
/*  The circumference of a circle with diameter 1, PI.*/
#define M_PI       3.14159265358979323846
/*  Half of PI. (PI/2)*/
#define M_PI_2     1.57079632679489661923
/*  A quarter of PI. (PI/4)*/
#define M_PI_4     0.78539816339744830962
/*  The inverse of PI. (1/PI)*/
#define M_1_PI     0.31830988618379067154
/*	Twice the inverse of PI. (2/PI)*/
#define M_2_PI     0.63661977236758134308
/*	The inverse of the square root of PI. (2/(sqrtPI))*/
#define M_2_SQRTPI 1.12837916709551257390
/*  The square root of 2. (sqrt2) */
#define M_SQRT2    1.41421356237309504880
/*	The inverse of the square root of 2. 1/(sqrt2)*/
#define M_SQRT1_2  0.70710678118654752440

// extra defines

/* The circumference of a circle with diameter 1, PI.*/
#define M_PI_F        3.1415927f
/* The circumference of a circle with diameter 1, PI.*/
#define M_MINUS_PI_F -3.1415927f

/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU         6.28318530717958647692
/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU_F       6.2831855f


/* Half of PI. (PI/2)*/
#define M_HALF_PI       (M_PI_F / 2)
/* 3 Halves of PI. (3*(PI/2))*/
#define M_THREE_HALF_PI (3 * M_HALF_PI)


#define M_U16_MAX_VALUE_F 65536.0f
#define M_U32_MAX_VALUE_F 4294967296.0f
/*
 The difference between 1.0 and the next larger floating point number
*/
#define FLT_EPSILON       1.19209290E-07F

/*Inline Math Funcs*/


#define SECS_TO_TIMER60(SECS) (SECS * GAME_TICKRATE)
#define MINS_TO_TIMER60(MINS) (SECS_TO_TIMER60(MINS * GAME_TICKRATE))
/* Gets the byte representation of an angle (degrees) */
#define DEG2BYTE(DEG)         (char)(256.0f / 360.0f * (DEG))
/* Gets the byte representation of an angle (radians) */
#define RAD2BYTE(RAD)         (char)(256.0f / M_TAU_F * (RAD))
/* Converts an angle from Degrees to Radians */
#define DegToRad(DEG)         (float)((DEG) * M_TAU_F / 360.0f)
/* Converts an angle from Degrees to Radians with only one multiply*/
#define DegToRad1Fact(DEG)         (float)((DEG) * (float)(M_TAU / 360.0))
/* Converts and halves an angle from Degrees to Radians */
#define mDegToHalfRad(x)      ((x * M_PI_F) / 360.0f)
/* Converts an angle from Radians to Degrees */
#define RadToDeg(RAD)         (float)((RAD) * (360.0f / M_TAU_F))
/* Gets the angle in radians represented by a byte */
#define ByteToRadian(Byte)    ((Byte * M_TAU_F) * (1.0f / 256.0f))

/* Macro Versions of functions */

#define ABS(x)    ((x) < 0 ? -(x) : (x))          /* absolute value of x */
#define SGN(x)    ((x) < 0 ? -1 : (x) > 0 ? 1 : 0)/* sign of x */
#define MIN(x, y) ((x) < (y) ? (x) : (y))         /* minimum of x and y */
#define MAX(x, y) ((x) > (y) ? (x) : (y))         /* maximum of x and y */
#define SQR(x)    ((x) * (x))                     /* square of x */

/**
 * 0.1f
*/
#define IDO_POINT_ONE 0.10000001f

float  sinf(float);
double sin(double);
float  cosf(float);
double cos(double);

float  sqrtf(float);

#endif

#if 0
#ifndef __MATH_H__
#define __MATH_H__
#ifdef __cplusplus
extern "C"
{
#endif
#if (!defined(__SGIDEFS_H__) && defined(_COMPILER_VERSION) && (_COMPILER_VERSION >= 400))
#    include <sgidefs.h>
#endif
/* Copyright (C) 1989 Silicon Graphics, Inc. All rights reserved.  */
/* ------------------------------------------------------------------ */
/* | Copyright Unpublished, MIPS Computer Systems, Inc.  All Rights | */
/* | Reserved.  This software contains proprietary and confidential | */
/* | information of MIPS and its suppliers.  Use, disclosure or     | */
/* | reproduction is prohibited without the prior express written   | */
/* | consent of MIPS.                                               | */
/* ------------------------------------------------------------------ */

/* #ident "$Revision: 7.28 $" */

/* ANSI C Notes:
 *
 * - THE IDENTIFIERS APPEARING OUTSIDE OF #ifdef __EXTENSIONS__ IN THIS
 *   standard header ARE SPECIFIED BY ANSI!  CONFORMANCE WILL BE ALTERED
 *   IF ANY NEW IDENTIFIERS ARE ADDED TO THIS AREA UNLESS THEY ARE IN ANSI's
 *   RESERVED NAMESPACE. (i.e., unless they are prefixed by __[a-z] or
 *   _[A-Z].  For external objects, identifiers with the prefix _[a-z] 
 *   are also reserved.)
 *
 *  - Names created by appending either the suffix 'l' or 'f'
 *    to one of the reserved function names are reserved for the corresponding
 *    single- or extended- precision version of the function.
 */

/* Power C Notes:
 *
 *  - Power C assumes that all external functions (unless otherwise marked)
 *    might modify global data and therefore calls to such functions can
 *    not be safely concurrentized.
 *
 *  - The pragma "no side effects" indicates that the named function is
 *    free from such side effects and calls to it can be concurrentized.
 *
 *  - This pragma has been added below for each function in the math library
 *    which is "safe".
 *
 *  - The pragma is properly passed on by 'cpp' & 'c++' and ignored by
 *    'ccom'.  It only has meaning to 'pca'.
 */

/* 
 *  ANSI-standard functions.  Each is listed with 
 *  its single-precision counterpart, if it exists. 
 */
#if defined(_XOPEN_SOURCE)

    extern double   lgamma(double);
#    pragma no side effects(lgamma)
    extern int      isnan(double);
#    pragma no side effects(isnan)

    extern double   erf(double);
#    pragma no side effects(erf)
    extern double   erfc(double);
#    pragma no side effects(erfc)

    extern double   gamma(double);
    extern double   hypot(double, double);
#    pragma no side effects(hypot)

    extern double   j0(double);
#    pragma no side effects(j0)
    extern double   j1(double);
#    pragma no side effects(j1)
    extern double   jn(int, double);
#    pragma no side effects(jn)

    extern double   y0(double);
#    pragma no side effects(y0)
    extern double   y1(double);
#    pragma no side effects(y1)
    extern double   yn(int, double);
#    pragma no side effects(yn)

/* Some useful constants */
#    define M_E        2.7182818284590452354
#    define M_LOG2E    1.4426950408889634074
#    define M_LOG10E   0.43429448190325182765
#    define M_LN2      0.69314718055994530942
#    define M_LN10     2.30258509299404568402
#    define M_PI       3.14159265358979323846
#    define M_PI_2     1.57079632679489661923
#    define M_PI_4     0.78539816339744830962
#    define M_1_PI     0.31830988618379067154
#    define M_2_PI     0.63661977236758134308
#    define M_2_SQRTPI 1.12837916709551257390
#    define M_SQRT2    1.41421356237309504880
#    define M_SQRT1_2  0.70710678118654752440

#    ifndef _MAXFLOAT
#        define _MAXFLOAT
#        define MAXFLOAT ((float)3.40282346638528860e+38)
#    endif /* _MAXFLOAT */

    extern int signgam;

#endif /* _XOPEN_SOURCE */

    extern double acos(double);
#pragma no side effects(acos)
    extern float acosf(float);
#pragma no side effects(acosf)

    extern double asin(double);
#pragma no side effects(asin)
    extern float asinf(float);
#pragma no side effects(asinf)

    extern double atan(double);
#pragma no side effects(atan)
    extern float atanf(float);
#pragma no side effects(atanf)

    extern double atan2(double, double);
#pragma no side effects(atan2)
    extern float atan2f(float, float);
#pragma no side effects(atan2f)

    extern double cos(double);
#pragma no side effects(cos)
    extern float cosf(float);
#pragma no side effects(cosf)

    extern double sin(double);
#pragma no side effects(sin)
    extern float sinf(float);
#pragma no side effects(sinf)

    extern double tan(double);
#pragma no side effects(tan)
    extern float tanf(float);
#pragma no side effects(tanf)

    extern double cosh(double);
#pragma no side effects(cosh)
    extern float coshf(float);
#pragma no side effects(coshf)

    extern double sinh(double);
#pragma no side effects(sinh)
    extern float sinhf(float);
#pragma no side effects(sinhf)

    extern double tanh(double);
#pragma no side effects(tanh)
    extern float tanhf(float);
#pragma no side effects(tanhf)

    extern double exp(double);
#pragma no side effects(exp)
    extern float expf(float);
#pragma no side effects(expf)

    extern double frexp(double, int *);
#if 0
/* not yet implemented */
extern float	frexpf(float, int *);
#endif

    extern double ldexp(double, int);
#if 0
/* not yet implemented */
extern float	ldexpf(float, int);
#endif

    extern double log(double);
#pragma no side effects(log)
    extern float logf(float);
#pragma no side effects(logf)

    extern double log10(double);
#pragma no side effects(log10)
    extern float log10f(float);
#pragma no side effects(log10f)

    extern double modf(double, double *);
    /* version of modff implemented for completeness only */
    extern float  modff(float, float *);

    extern double pow(double, double);
#pragma no side effects(pow)
    /* version of powf implemented for completeness only */
    extern float powf(float, float);
#pragma no side effects(powf)

    extern double sqrt(double);
#pragma no side effects(sqrt)
    extern float sqrtf(float);
#pragma no side effects(sqrtf)

    extern double ceil(double);
#pragma no side effects(ceil)
    extern float ceilf(float);
#pragma no side effects(ceilf)

    extern double fabs(double);
#pragma no side effects(fabs)
    /* version of fabsf implemented for completeness only */
    extern float fabsf(float);
#pragma no side effects(fabsf)

    extern double floor(double);
#pragma no side effects(floor)
    extern float floorf(float);
#pragma no side effects(floorf)

    extern double fmod(double, double);
#pragma no side effects(fmod)
    /* version of fmodf implemented for completeness only */
    extern float fmodf(float, float);
#pragma no side effects(fmodf)

#ifndef HUGE_VAL /* Also in limits.h */
#    ifdef _SVR4_SOURCE
#        ifndef __TYPEDEF_H_VAL
#            define __TYPEDEF_H_VAL
    typedef union _h_val
    {
#            if (_MIPS_SZLONG == 32)
        unsigned long i[2];
#            endif
#            if (_MIPS_SZLONG == 64)
        __uint32_t i[2];
#            endif
        double d;
    } _h_val;
#        endif /* __TYPEDEF_H_VAL */

    extern const _h_val __huge_val;
#        define HUGE_VAL __huge_val.d
#    else
    /* __infinity is a double-precision variable in libc set to infinity */
    extern const double __infinity;
#        define HUGE_VAL __infinity
#    endif /* _SVR4_SOURCE */
#endif     /* !HUGE_VAL */

#if (defined(__EXTENSIONS__) || defined(_POSIX_SOURCE))
    extern int    errno, signgam;

    extern double atof(const char *);
    extern int    rand(void);
    extern void   srand(unsigned);
#endif /* __EXTENSIONS__ || _POSIX_SOURCE */

#if (defined(__EXTENSIONS__) && (!defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)))

    enum version
    {
        c_issue_4,
        ansi_1,
        strict_ansi
    };
    extern const enum version _lib_version;

    /* Features from 4.3BSD */
    extern double             rint(double);
#    pragma no side           effects(rint)
    extern double             asinh(double);
#    pragma no side           effects(asinh)
    extern double             acosh(double);
#    pragma no side           effects(acosh)
    extern double             atanh(double);
#    pragma no side           effects(atanh)
    extern double             log1p(double);
#    pragma no side           effects(log1p)
    extern double             erf(double);
#    pragma no side           effects(erf)
    extern double             erfc(double);
#    pragma no side           effects(erfc)
    extern double             expm1(double);
#    pragma no side           effects(expm1)
    extern double             gamma(double);
    extern double             hypot(double, double);
#    pragma no side           effects(hypot)
    struct __cabs_s
    {
        double a, b;
    };
    extern double   cabs(struct __cabs_s);
#    pragma no side effects(cabs)
    extern double   copysign(double, double);
#    pragma no side effects(copysign)
    extern double   drem(double, double);
#    pragma no side effects(drem)
    extern double   logb(double);
#    pragma no side effects(logb)
#    if (defined(_COMPILER_VERSION) && (_COMPILER_VERSION >= 400))
    extern double nextafter(double, double);
#        pragma no side effects(nextafter)
    extern double remainder(double, double);
#        pragma no side effects(remainder)
#    endif
    extern double          scalb(double, double);
#    pragma no side        effects(scalb)
    extern int             finite(double);
#    pragma no side        effects(finite)
    extern double          j0(double);
#    pragma no side        effects(j0)
    extern double          j1(double);
#    pragma no side        effects(j1)
    extern double          jn(int, double);
#    pragma no side        effects(jn)
    extern double          y0(double);
#    pragma no side        effects(y0)
    extern double          y1(double);
#    pragma no side        effects(y1)
    extern double          yn(int, double);
#    pragma no side        effects(yn)
    extern double          cbrt(double);
#    pragma no side        effects(cbrt)
    extern double          atof(const char *);
    extern double          strtod(const char *, char **);
    extern double          trunc(double);
#    pragma no side        effects(trunc)

    extern int             rand(void);
    extern void            srand(unsigned);

    extern long            random(void);
    extern int             srandom(unsigned); /* doesn't return a value -- should be void */
    extern char *          initstate(unsigned int, char *, int);
    extern char *          setstate(char *);

    extern double          drand48(void);
    extern double          erand48(unsigned short[3]);
    extern long            lrand48(void);
    extern long            nrand48(unsigned short[3]);
    extern long            mrand48(void);
    extern long            jrand48(unsigned short[3]);
    extern void            srand48(long);
    extern unsigned short *seed48(const unsigned short[3]);
    extern void            lcong48(const unsigned short[7]);

    /* Map old MIPS names of single-precision forms to ANSI names.*/

#    define facos  acosf
#    define fasin  asinf
#    define fatan  atanf
#    define fatan2 atan2f
#    define fcos   cosf
#    define fsin   sinf
#    define ftan   tanf
#    define fcosh  coshf
#    define fsinh  sinhf
#    define ftanh  tanhf
#    define fexp   expf
#    define flog   logf
#    define flog10 log10f
#    define fsqrt  sqrtf
#    define fceil  ceilf
#    define ffloor floorf

/* similar mapping of old MIPS names to ANSI-like names */
#    undef flog1p
#    define flog1p log1pf
#    define ftrunc truncf

#    ifdef __cplusplus
#        ifndef _ABS_
#            define _ABS_
    inline int abs(int x)
    {
        return x > 0 ? x : -x;
    }
#        endif
#    endif

    /* additional single-percision forms */
    extern float    fhypot(float, float);
#    pragma no side effects(fhypot)
    extern float    hypotf(float, float);
#    pragma no side effects(hypotf)
    struct __fcabs_s
    {
        float a, b;
    };
    extern float    fcabs(struct __fcabs_s);
#    pragma no side effects(fcabs)
    extern float    fexpm1(float);
#    pragma no side effects(fexpm1)
    extern float    expm1f(float);
#    pragma no side effects(expm1f)
    extern float    log1pf(float);
#    pragma no side effects(log1pf)
    extern float    truncf(float);
#    pragma no side effects(truncf)
#    if (defined(__INLINE_INTRINSICS) && defined(_COMPILER_VERSION) && (_COMPILER_VERSION >= 400))
#        if _MIPS_ISA != _MIPS_ISA_MIPS1
#            pragma intrinsic(hypotf)
#            pragma intrinsic(fhypot)
#        endif
#    endif

#    if 0  /* These are not implemented yet. */
extern float	ferf(float);
extern float	ferfc(float);
extern float	flgamma(float);
extern float	fcopysign(float, float);
extern float	fdrem(float, float);
extern float	flogb(float);
extern float	fscalb(float, int);
extern int	ffinite(float);
extern float	fj0(float);
extern float	fj1(float);
extern float	fjn(int, float);
extern float	fy0(float);
extern float	fy1(float);
extern float	fyn(int, float);
extern float	fatof(char *);
extern float	frint(float);
extern float	facosh(float);
extern float	fatanh(float);
extern float	fcbrt(float);
#    endif /* 0 */

/* Some useful constants */
/*  The base of natural logarithms, e.*/
#    define M_E        2.7182818284590452354
/*  The base 2 logarithm of e. (log2e)*/
#    define M_LOG2E    1.4426950408889634074
/*  The base 10 logarithm of e. (log10e)*/
#    define M_LOG10E   0.43429448190325182765
/*  The natural logarithm of 2. (ln 2)*/
#    define M_LN2      0.69314718055994530942
/*  The natural logarithm of 10. (ln 10)*/
#    define M_LN10     2.30258509299404568402
/*  The circumference of a circle with diameter 1, PI.*/
#    define M_PI       3.14159265358979323846
/*  Half of PI. (?/2)*/
#    define M_PI_2     1.57079632679489661923
/*  A quarter of PI. (?/4)*/
#    define M_PI_4     0.78539816339744830962
/*  The inverse of PI. (1/?)*/
#    define M_1_PI     0.31830988618379067154
/*	Twice the inverse of PI. (2/?)*/
#    define M_2_PI     0.63661977236758134308
/*	The inverse of the square root of PI. (2/(??))*/
#    define M_2_SQRTPI 1.12837916709551257390
/*  The square root of 2. (?2) */
#    define M_SQRT2    1.41421356237309504880
/*	The inverse of the square root of 2. 1/(?2)*/
#    define M_SQRT1_2  0.70710678118654752440

#    ifndef HUGE
#        ifdef MAXFLOAT
#            define HUGE MAXFLOAT
#        else
#            define HUGE ((float)3.40282346638528860e+38) /* value of MAXFLOAT */
#        endif                                            /* MAXFLOAT */
#    endif                                                /* !HUGE */

#    define _ABS(x) ((x) < 0 ? -(x) : (x))
#    define _REDUCE(TYPE, X, XN, C1, C2)              \
        {                                             \
            double x1 = (double)(TYPE)X, x2 = X - x1; \
            X = x1 - (XN) * (C1);                     \
            X += x2;                                  \
            X -= (XN) * (C2);                         \
        }
#    define _POLY1(x, c) ((c)[0] * (x) + (c)[1])
#    define _POLY2(x, c) (_POLY1((x), (c)) * (x) + (c)[2])
#    define _POLY3(x, c) (_POLY2((x), (c)) * (x) + (c)[3])
#    define _POLY4(x, c) (_POLY3((x), (c)) * (x) + (c)[4])
#    define _POLY5(x, c) (_POLY4((x), (c)) * (x) + (c)[5])
#    define _POLY6(x, c) (_POLY5((x), (c)) * (x) + (c)[6])
#    define _POLY7(x, c) (_POLY6((x), (c)) * (x) + (c)[7])
#    define _POLY8(x, c) (_POLY7((x), (c)) * (x) + (c)[8])
#    define _POLY9(x, c) (_POLY8((x), (c)) * (x) + (c)[9])

    struct exception
    {
        int    type;
        char * name;
        double arg1;
        double arg2;
        double retval;
    };

    extern int matherr(struct exception *p);

#    include <svr4_math.h>

#endif /* __EXTENSIONS__ && !_POSIX_SOURCE */

#ifdef __INLINE_INTRINSICS
/* The functions made intrinsic here can be activated by the driver
** passing -D__INLINE_INTRINSICS to cfe, but cfe should ensure that
** this has no effect unless the hardware architecture directly
** supports these basic operations.
*/
#    if _MIPS_ISA != _MIPS_ISA_MIPS1
#        pragma intrinsic(sqrt)
#        pragma intrinsic(sqrtf)
#        if (defined(_COMPILER_VERSION) && (_COMPILER_VERSION >= 400))
#            pragma intrinsic(pow)
#            pragma intrinsic(powf)
#        endif
#    endif
#    pragma intrinsic(fabs)
#    pragma intrinsic(fabsf)
#endif

#ifdef __cplusplus
}
#endif
#endif /* !__MATH_H__ */
#endif
