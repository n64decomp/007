/*========================================================================
 * LibFixedPoint.h
 *
 * This library allows for complex fixed point math.
 * it has greater flexibility than the gu functions (which are 32bit)
 * 
 * example:
 *    FTOFIX32(100.5) 
 *  will result in 6586368 (or 0x0064 8000) which is a s15.16 fixed format.
 * 
 *    #define fixed_fmt_z s16, 13, 2
 *    fixed(fixed_fmt_z) z;           
 *    z.full = Float2Fixed(z, 7.3);
 * 
 *  will result in 402 (or 0x0192) which is s13.2 (as defined)
 * 
 *========================================================================*/
/**************************************************************************
 *
 *  $REVISION: 1.0 $
 *  $DATE: 2021/03/09 02:03:28 $
 *  $SOURCE: /include/LibFixedPoint.h,v $
 *
 **************************************************************************/
#ifndef _LIBFIXEDPOINT_H_
#    define _LIBFIXEDPOINT_H_
#include <CPPLib.h>
#include <ultra64.h>




#pragma region Private Implementation Macros 

#define _fixed(TYPE, INTEGER, FRACTION) \
    union                               \
    {                                   \
        TYPE full;                      \
        struct                          \
        {                               \
            TYPE integer : INTEGER;     \
            TYPE fraction : FRACTION;   \
        } part;                         \
    }

#define _Float2Fixed(SIZE, INTEGER, FRACTION, VALUE) ((VALUE) * (1 << FRACTION))

#define _Fixed2Float(SIZE, INTEGER, FRACTION, VALUE) \
    ((float)(VALUE) / (1 << FRACTION))

#define _GetFixedFraction(SIZE, INTEGER, FRACTION, VALUE)             \
    ((unsigned SIZE)((1E##FRACTION) *                                 \
                     (VALUE.part.fraction & ((1 << FRACTION) - 1))) / \
     (1 << FRACTION))

#define _FixedAddition(SIZE_A,     \
                       INTEGER_A,  \
                       FRACTION_A, \
                       VALUE_A,    \
                       SIZE_B,     \
                       INTEGER_B,  \
                       FRACTION_B, \
                       VALUE_B)    \
    (SIZE_A) VALUE_A + (VALUE_B << (FRACTION_A - FRACTION_B))

#define _FixedSubtraction(SIZE_A,     \
                          INTEGER_A,  \
                          FRACTION_A, \
                          VALUE_A,    \
                          SIZE_B,     \
                          INTEGER_B,  \
                          FRACTION_B, \
                          VALUE_B)    \
    (SIZE_A) VALUE_A - (VALUE_B << (FRACTION_A - FRACTION_B))

#define _FixedMultiplication(SIZE_A,     \
                             INTEGER_A,  \
                             FRACTION_A, \
                             VALUE_A,    \
                             SIZE_B,     \
                             INTEGER_B,  \
                             FRACTION_B, \
                             VALUE_B)    \
    (VALUE_A * VALUE_B) >> (FRACTION_A - FRACTION_B)

#define _FixedDivision(SIZE_A,     \
                       INTEGER_A,  \
                       FRACTION_A, \
                       VALUE_A,    \
                       SIZE_B,     \
                       INTEGER_B,  \
                       FRACTION_B, \
                       VALUE_B)    \
    (VALUE_A << (FRACTION_A - FRACTION_B) / VALUE_B) 

#pragma endregion
#pragma region Public Macros 

/**
 * Define a Fixed Point type.
 * Please Define the format Directly Before this.
 * #define fixed_fmt_VarName Size,Integer,Fraction
 * @param FORMAT: format name eg, fixed_fmt_VarName
 */
#define fixed(FORMAT) EXPAND(_fixed(FORMAT))

/**
 * Convert a float to a Fixed Point type (integer).
 * @param VAR: Variable to assign VALUE to.
 * @param VALUE: Float Value to convert.
 */
#define Float2Fixed(VAR, VALUE) \
    EXPAND(DEFER(_Float2Fixed)(EXPAND(fixed_fmt_##VAR), VALUE))

/**
 * Convert a Fixed Point type (integer) to a float.
 * @param VAR: Variable to convert.
 */
#define Fixed2Float(VAR) \
    EXPAND(DEFER(_Fixed2Float)(EXPAND(fixed_fmt_##VAR), VAR.full))

/**
 * @param VAR: Fixed Type to Read.
 * @return Scaled Integer representing the Fractional Componant. eg, 75 for 0.75
 */
#define GetFixedFraction(VAR) \
    EXPAND(DEFER(_GetFixedFraction)(EXPAND(fixed_fmt_##VAR), VAR))

/**
 * Perform Addition on 2 Fixed Types.
 * If A and B are different types, the larger should come first.
 * @param A: Fixed Type to Read.
 * @param B: Fixed Type to Read.
 * @return Integer of Fixed Type "A".
 */
#define FixedAddition(A, B)                             \
    EXPAND(DEFER(_FixedAddition)(EXPAND(fixed_fmt_##A), \
                                 A.full,                \
                                 EXPAND(fixed_fmt_##B), \
                                 B.full))

/**
 * Perform Addition on A Fixed Type and Integer.
 * @param A: Fixed Type to Read.
 * @param B: Integer.
 * @return Integer of Fixed Type "A".
 */
#define FixedAddition_i(A, B)                             \
    EXPAND(DEFER(_FixedAddition)(EXPAND(fixed_fmt_##A), \
                                 A.full,                \
                                 0, 0, 0,               \
                                 B))

/**
 * Perform Addition on A Fixed Type and Float.
 * @param A: Fixed Type to Read.
 * @param B: Float.
 * @return Integer of Fixed Type "A".
 */
#define FixedAddition_f(A, B)       \
    EXPAND(DEFER(_FixedAddition)( \
        EXPAND(fixed_fmt_##A),    \
        A.full,                   \
        EXPAND(fixed_fmt_##A),    \
        EXPAND(DEFER(_Float2Fixed)(EXPAND(fixed_fmt_##A), B))))

/**
 * Perform Subtraction on 2 Fixed Types.
 * If A and B are different types, the larger should come first.
 * @param A: Fixed Type to Read.
 * @param B: Fixed Type to Read.
 * @return Integer of Fixed Type "A".
 */
#define FixedSubtraction(A, B)                             \
    EXPAND(DEFER(_FixedSubtraction)(EXPAND(fixed_fmt_##A), \
                                    A.full,                \
                                    EXPAND(fixed_fmt_##B), \
                                    B.full))

 /**
 * Perform Subtraction on A Fixed Type and Integer.
 * @param A: Fixed Type to Read.
 * @param B: Integer.
 * @return Integer of Fixed Type "A".
 */
#define FixedSubtraction_i(A, B) \
    EXPAND(DEFER(_FixedSubtraction)(EXPAND(fixed_fmt_##A), A.full, 0, 0, 0, B))

/**
 * Perform Subtraction on A Fixed Type and Float.
 * @param A: Fixed Type to Read.
 * @param B: Float.
 * @return Integer of Fixed Type "A".
 */
#define FixedSubtraction_f(A, B)     \
    EXPAND(DEFER(_FixedSubtraction)( \
        EXPAND(fixed_fmt_##A),    \
        A.full,                   \
        EXPAND(fixed_fmt_##A),    \
        EXPAND(DEFER(_Float2Fixed)(EXPAND(fixed_fmt_##A), B))))

/**
 * Perform Multiplication on 2 Fixed Types.
 * If A and B are different types, the larger Fractional should come first.
 * @param A: Fixed Type to Read.
 * @param B: Fixed Type to Read.
 * @return Integer with "A" bits fraction.
 */
#define FixedMultiplication(A, B)                             \
    EXPAND(DEFER(_FixedMultiplication)(EXPAND(fixed_fmt_##A), \
                                       A.full,                \
                                       EXPAND(fixed_fmt_##B), \
                                       B.full))

/**
 * Perform Multiplication on A Fixed Type and Integer.
 * @param A: Fixed Type to Read.
 * @param B: Integer.
 * @return Integer of Fixed Type "A".
 */
#define FixedMultiplication_i(A, B) \
    EXPAND(DEFER(                   \
        _FixedMultiplication)(EXPAND(fixed_fmt_##A), A.full, 0, 0, 0, B))

/**
 * Perform Multiplication on A Fixed Type and Float.
 * @param A: Fixed Type to Read.
 * @param B: Float.
 * @return Integer of Fixed Type "A".
 */
#define FixedMultiplication_f(A, B)     \
    EXPAND(DEFER(_FixedMultiplication)( \
        EXPAND(fixed_fmt_##A),       \
        A.full,                      \
        EXPAND(fixed_fmt_##A),       \
        EXPAND(DEFER(_Float2Fixed)(EXPAND(fixed_fmt_##A), B))))

/**
 * Perform Division on 2 Fixed Types.
 * If A and B are different types, the larger Fractional should come first.
 * @param A: Fixed Type to Read.
 * @param B: Fixed Type to Read.
 * @return Integer with "A" bits fraction.
 */
#define FixedDivision(A, B)                              \
    EXPAND(DEFER(_FixedDivision)(EXPAND(fixed_fmt_##A), \
                                  A.full,                \
                                  EXPAND(fixed_fmt_##B), \
                                  B.full))
/**
 * Perform Division on A Fixed Type and Integer.
 * @param A: Fixed Type to Read.
 * @param B: Integer.
 * @return Integer of Fixed Type "A".
 */
#define FixedDivision_i(A, B) \
    EXPAND(DEFER(_FixedDivision)(EXPAND(fixed_fmt_##A), A.full, 0, 0, 0, B))
/**
 * Perform Division on A Fixed Type and Float.
 * @param A: Fixed Type to Read.
 * @param B: Float.
 * @return Integer of Fixed Type "A".
 */
#define FixedDivision_f(A, B)     \
    EXPAND(DEFER(_FixedDivision)( \
        EXPAND(fixed_fmt_##A),       \
        A.full,                      \
        EXPAND(fixed_fmt_##A),       \
        EXPAND(DEFER(_Float2Fixed)(EXPAND(fixed_fmt_##A), B))))




#if 0 
/**
 * Example Showing all Fixed Types and a comparison to Float.
 * Result: Use Fixed for Storage and float for runtime.
 */
void Example()
{
#define fixed_fmt_y unsigned char, 3, 1
    fixed(fixed_fmt_y) y;           // 1bytes

#define fixed_fmt_z short, 13, 2
    fixed(fixed_fmt_z) z;           // 2bytes

#define fixed_fmt_Result short, 14, 2
    fixed(fixed_fmt_Result) Result; // 2bytes

    float Comparitor;               // 4bytes
    Comparitor = 6.5;               //                         1 Instructions

    z.full = Float2Fixed(z, 7.3);
    printf("\n Zfull = %d", z.full);          // 29            1 Instructions
    printf("\n Zint = %d", z.part.integer);   // 7             3 Instructions
    printf("\n Zfrac = %d", z.part.fraction); // 1             5 Instructions
    printf("\n Zfixedfulldec = %d.%u",
        z.part.integer,
        GetFixedFraction(z));                    // 7, 25   41 Instructions
    printf("\n ZFixed2Float = %g", Fixed2Float(z)); // 7.25     7 Instructions

    y.full = 4;
    printf("\n y = %g", Fixed2Float(y)); // 2

    Result.full = FixedMultiplication(z, y); //                 9 Instructions
    printf("\n Result = %g", Fixed2Float(Result)); // 14.5

    Result.full = FixedDivision(z, y); //                       9 Instructions
    printf("\n Result = %g", Fixed2Float(Result)); // 3.5

    Result.full = FixedSubtraction(z, y); //                    6 Instructions
    printf("\n Result = %g", Fixed2Float(Result)); // 5.25

    Result.full = FixedAddition(z, y); //                       6 Instructions
    printf("\n Result = %g", Fixed2Float(Result)); // 9.25

    printf("\n Comparison = %g", Comparitor); // 6.5            3 Instructions
    Comparitor *= 2.6; //                                       4 Instructions
    printf("\n Comparison = %g", Comparitor); // 16.9
}
#endif
#pragma endregion
#endif
