// ****************************************************************************
//
//   $Revision: NTSC 1.0 $
//   $Date: __DATE__ __TIME__ $
//
// ***************************************************************************/\n\n

/*HELPER MACROS*/
#include <CPPLib.h>
#define DEFINE(x) CAT(CAT(??,=),define) x \n\n
#define INCLUDE CAT(CAT(??,=),include)

/*SPLIT/FORMAT MACROS*/
#define BBYTE(PARAM)      PARAM
#define BDBYTE(PARAM)     CharArrayFrom16(PARAM)
#define BTBYTE(PARAM)     CharArrayFrom24(PARAM)
#define BQBYTE(PARAM)     CharArrayFrom32(PARAM)
#define HEAD_BYTE(PARAM)  PARAM
#define HEAD_DBYTE(PARAM) PARAM
#define HEAD_TBYTE(PARAM) PARAM
#define HEAD_QBYTE(PARAM) PARAM
/*SIZE MACROS*/
#define COUNT_BYTE(PARAM)  +1
#define COUNT_DBYTE(PARAM) +2
#define COUNT_TBYTE(PARAM) +3
#define COUNT_QBYTE(PARAM) +4

/*SPLIT/FORMAT MACROS*/
/*HACK: Use of Multiline comments for formatting avoids extra spaces in output.
        Moving Splits to multiple lines for ease of reading
        Fixed typo on 6 params
        Use Cascade Macros to save repitition
*/
#define PARAMSPLIT_0()
#define PARAMSPLIT_1(PARAM1) \ /*
*/                    B ## PARAM1,
#define PARAMSPLIT_2(PARAM1, PARAM2)\
/*					*/PARAMSPLIT_1(PARAM1)\/*
*/                    B ## PARAM2,
#define PARAMSPLIT_3(PARAM1, PARAM2, PARAM3)\
/*					*/PARAMSPLIT_2(PARAM1, PARAM2)\/*
*/                    B ## PARAM3,
#define PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4)\
/*					*/PARAMSPLIT_3(PARAM1, PARAM2, PARAM3)\/*
*/                    B ## PARAM4,
#define PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5)\
/*					*/PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4)\/*
*/                    B ## PARAM5,
#define PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6)\
/*					*/PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5)\/*
*/                    B ## PARAM6,
#define PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7)\
/*					*/PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6)\/*
*/                    B ## PARAM7,
#define PARAMSPLIT_8(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, PARAM8)\
/*					*/PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7)\/*
*/                    B ## PARAM8,

/*HEAD MACROS FOR PARAMETER LISTING*/
#define HEAD_PARAMSPLIT_0()
#define HEAD_PARAMSPLIT_1(PARAM1) \
/*					*/HEAD_ ## PARAM1
#define HEAD_PARAMSPLIT_2(PARAM1, PARAM2)\
/*					*/HEAD_PARAMSPLIT_1(PARAM1),\
/*					*/HEAD_ ## PARAM2
#define HEAD_PARAMSPLIT_3(PARAM1, PARAM2, PARAM3)\
/*					*/HEAD_PARAMSPLIT_2(PARAM1, PARAM2),\
/*					*/HEAD_ ## PARAM3
#define HEAD_PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4)\
/*					*/HEAD_PARAMSPLIT_3(PARAM1, PARAM2, PARAM3),\
/*					*/HEAD_ ## PARAM4
#define HEAD_PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5)\
/*					*/HEAD_PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4),\
/*					*/HEAD_ ## PARAM5
#define HEAD_PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6)\
/*					*/HEAD_PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5),\
/*					*/HEAD_ ## PARAM6
#define HEAD_PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7)\
/*					*/HEAD_PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6),\
/*					*/HEAD_ ## PARAM7
#define HEAD_PARAMSPLIT_8(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, PARAM8)\
/*					*/HEAD_PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7),\
/*					*/HEAD_ ## PARAM8

/*COUNT MACROS FOR COMMAND SIZE*/
#define COUNT_PARAMSPLIT_0()
#define COUNT_PARAMSPLIT_1(PARAM1) \
/*					*/COUNT_ ## PARAM1
#define COUNT_PARAMSPLIT_2(PARAM1, PARAM2)\
/*					*/COUNT_PARAMSPLIT_1(PARAM1)\
/*					*/COUNT_ ## PARAM2
#define COUNT_PARAMSPLIT_3(PARAM1, PARAM2, PARAM3)\
/*					*/COUNT_PARAMSPLIT_2(PARAM1, PARAM2)\
/*					*/COUNT_ ## PARAM3
#define COUNT_PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4)\
/*					*/COUNT_PARAMSPLIT_3(PARAM1, PARAM2, PARAM3)\
/*					*/COUNT_ ## PARAM4
#define COUNT_PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5)\
/*					*/COUNT_PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4)\
/*					*/COUNT_ ## PARAM5
#define COUNT_PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6)\
/*					*/COUNT_PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5)\
/*					*/COUNT_ ## PARAM6
#define COUNT_PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7)\
/*					*/COUNT_PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6)\
/*					*/COUNT_ ## PARAM7
#define COUNT_PARAMSPLIT_8(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, PARAM8)\
/*					*/COUNT_PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7)\
/*					*/COUNT_ ## PARAM8


/*TEMPLATE COMMAND MACRO*/

#define Poly(A, C, D)                                                                                                                                 \
    IF(AND(IS_PAREN(A), IF_ELSE(IS_PAREN(A))(HAS_ARGS A)(0)))                                                                                         \
    (IF_ELSE(DEFER(IS_PAREN)(SECOND A))(\n DEFINE                                                                                                     \
            FIRST A                                                                                                                                   \
                IF(AND(EXPAND(DEFER(IS_PAREN) POP_ARG(POP_ARG A)),                                                                                    \
                       EXPAND(DEFER(HAS_ARGS)(IF(DEFER(IS_PAREN)(SECOND_PRE_VA POP_ARG A))(DEFER(FIRST_PRE_VA)) SECOND_PRE_VA POP_ARG A))))(          \
                    MAKE_EXPAND(EXPAND(DEFER(TRY_EXPAND)(DEFER(FIRST_PRE_VA) SECOND_PRE_VA POP_ARG A)), MAKE_EXPAND_END))                             \
                    C SECOND A                                                                                                                        \
                        IF(AND(EXPAND(DEFER(IS_PAREN) POP_ARG(POP_ARG A)),                                                                            \
                               EXPAND(DEFER(HAS_ARGS)(IF(DEFER(IS_PAREN)(SECOND_PRE_VA POP_ARG A))(DEFER(SECOND_PRE_VA)) SECOND_PRE_VA POP_ARG A))))( \
                            MAKE_EXPAND(, EXPAND(DEFER(TRY_EXPAND)(DEFER(SECOND_PRE_VA) SECOND_PRE_VA POP_ARG A)) MAKE_EXPAND_END))                   \
                            DEFER4(_Poly)()(POP_ARG(A), C, D))(\n FIRST A \n DEFINE                                                                   \
            SECOND A                                                                                                                                  \
                IF(AND(EXPAND(DEFER(IS_PAREN) POP_ARG(POP_ARG A)),                                                                                    \
                       EXPAND(DEFER(HAS_ARGS)(IF(DEFER(IS_PAREN)(SECOND_PRE_VA POP_ARG A))(DEFER(FIRST_PRE_VA)) SECOND_PRE_VA POP_ARG A))))(          \
                    MAKE_EXPAND(EXPAND(DEFER(TRY_EXPAND)(DEFER(FIRST_PRE_VA) SECOND_PRE_VA POP_ARG A)), MAKE_EXPAND_END))                             \
                    C SECOND POP_ARG A                                                                                                                \
                        IF(AND(EXPAND(DEFER(IS_PAREN) POP_ARG(POP_ARG A)),                                                                            \
                               EXPAND(DEFER(HAS_ARGS)(IF(DEFER(IS_PAREN)(SECOND_PRE_VA POP_ARG A))(DEFER(SECOND_PRE_VA)) SECOND_PRE_VA POP_ARG A))))( \
                            MAKE_EXPAND(, EXPAND(DEFER(TRY_EXPAND)(DEFER(SECOND_PRE_VA) SECOND_PRE_VA POP_ARG A)) MAKE_EXPAND_END))                   \
                            DEFER4(_Poly)()(POP_ARG(A), C, (FIRST A))))

#define _Poly() Poly

#if 0
    #define _AI_CMD(C,D,P,CODE,A)               /*
        */\nD/*
        */DEFINE CAT(C,(CAT(CAT(HEAD_PARAMSPLIT_, COUNTPARAMS(P)), P)))\/*
    */                    CAT(CAT(AI_ , C) , _ID), \
    /*                  */CAT(CAT(PARAMSPLIT_ , COUNTPARAMS(P)), P)\n/*
        */DEFINE CAT(CAT(AI_, C), _LENGTH) (AICMDSIZE CAT(CAT(COUNT_PARAMSPLIT_, COUNTPARAMS(P)), P))/*
        */\n \
       //Alias/Polymorph\n EVAL16(Poly(A,C,D))
#endif
    
#define _AI_CMD(CODE)  \n/*  
    */DESCRIPTION /*
    */DEFINE CAT(CMDNAME,(CAT(CAT(HEAD_PARAMSPLIT_, COUNTPARAMS((PARAMS))), (PARAMS))))\/*
*/                    CAT(AI_ , CMDNAME), \
/*                  */CAT(CAT(PARAMSPLIT_ , COUNTPARAMS((PARAMS))), (PARAMS))\n/*
    */DEFINE CAT(CAT(AI_, CMDNAME), _LENGTH) (AICMDSIZE CAT(CAT(COUNT_PARAMSPLIT_, COUNTPARAMS((PARAMS))), (PARAMS)))/*
    */\n\n

#define _AI_DEBUG() \n/*
    */DESCRIPTION /*
    */DEFINE CAT(CMDNAME,(STRING))\/*
    */            CAT(AI_,CMDNAME), /*
    */\n\n

#if 0
#define _AI_CMD_SHOR_old(CMD,                 \
                         ALIAS,               \
                         AI_NUMBER_OF_PARAMS, \
                         PARAM,               \
                         AI_NUMBER_OF_PARAMS2,\
                         PARAM2,              \
                         DESC)  /*
    */DESC/*
    */DEFINE CAT(ALIAS, CAT(HEAD_PARAMSPLIT_ ## AI_NUMBER_OF_PARAMS2, PARAM2)) \/*
        */  CAT(CMD, CAT(HEAD_PARAMSPLIT_ ## AI_NUMBER_OF_PARAMS, PARAM))/*
    */\n
#endif

#define _AI_CMD_POLYMORPH(PRE,      \
                          ALIAS,    \
                          CMDPARAM, \
                          POLYPARAM)     /*
    */DESCRIPTION/*
    */DEFINE CAT(/**/,CAT(ALIAS, POLYPARAM))\/*
    */                CAT(PRE,CAT(CMDNAME,CMDPARAM))/*
    */\n\n

INCLUDE<bondconstants.h>
// make sure this is after constants\n

//Define All Commands At Once From File: \n

//Number of bytes for AI cmds, GE 1, PD 2
DEFINE AICMDSIZE ((u8)(AI_CMD_COUNT / 255) + 1) \n

#include "aicommands.def"

/*UNDEF BUILDER*/
#undef DEFINE
#undef INCLUDE
/*SPLIT/FORMAT MACROS*/
#undef BBYTE
#undef BDBYTE
#undef BTBYTE
#undef BQBYTE
#undef BDEG
#undef BINVERSE_DEG
#undef BRAD
#undef BINVERSE_RAD
#undef HEAD_BYTE
#undef HEAD_DBYTE
#undef HEAD_TBYTE
#undef HEAD_QBYTE
#undef HEAD_INVERSE_DEG
#undef HEAD_DEG
#undef HEAD_RAD
#undef HEAD_INVERSE_RAD
/*SIZE MACROS*/
#undef COUNT_BYTE
#undef COUNT_DBYTE
#undef COUNT_TBYTE
#undef COUNT_QBYTE
#undef COUNT_DEG
#undef COUNT_INVERSE_DEG
#undef COUNT_RAD
#undef COUNT_INVERSE_RAD

/*SPLIT/FORMAT MACROS*/
#undef PARAMSPLIT_0
#undef PARAMSPLIT_1
#undef PARAMSPLIT_2
#undef PARAMSPLIT_3
#undef PARAMSPLIT_4
#undef PARAMSPLIT_5
#undef PARAMSPLIT_6
#undef PARAMSPLIT_7
#undef PARAMSPLIT_8
/*HEAD MACROS FOR PARAMETER LISTING*/
#undef HEAD_PARAMSPLIT_0
#undef HEAD_PARAMSPLIT_1
#undef HEAD_PARAMSPLIT_2
#undef HEAD_PARAMSPLIT_3
#undef HEAD_PARAMSPLIT_4
#undef HEAD_PARAMSPLIT_5
#undef HEAD_PARAMSPLIT_6
#undef HEAD_PARAMSPLIT_7
#undef HEAD_PARAMSPLIT_8
/*COUNT MACROS FOR COMMAND SIZE*/
#undef COUNT_PARAMSPLIT_0
#undef COUNT_PARAMSPLIT_1
#undef COUNT_PARAMSPLIT_2
#undef COUNT_PARAMSPLIT_3
#undef COUNT_PARAMSPLIT_4
#undef COUNT_PARAMSPLIT_5
#undef COUNT_PARAMSPLIT_6
#undef COUNT_PARAMSPLIT_7
#undef COUNT_PARAMSPLIT_8
