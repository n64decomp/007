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
#define BS_BYTE(PARAM)     PARAM
#define BS_SBYTE(PARAM)    PARAM
#define BS_DBYTE(PARAM)    CharArrayFrom16(PARAM)
#define BS_TBYTE(PARAM)    CharArrayFrom24(PARAM)
#define BS_QBYTE(PARAM)    CharArrayFrom32(PARAM)
#define HEAD_BYTE(PARAM)   PARAM
#define HEAD_SBYTE(PARAM)  PARAM
#define HEAD_DBYTE(PARAM)  PARAM
#define HEAD_TBYTE(PARAM)  PARAM
#define HEAD_QBYTE(PARAM)  PARAM
/*SIZE MACROS*/
#define COUNT_BYTE(PARAM)  +1
#define COUNT_SBYTE(PARAM) +1
#define COUNT_DBYTE(PARAM) +2
#define COUNT_TBYTE(PARAM) +3
#define COUNT_QBYTE(PARAM) +4

#define STRUCT_BYTE(PARAM)  u8 PARAM
#define STRUCT_SBYTE(PARAM) s8 PARAM
#define STRUCT_DBYTE(PARAM) s16 PARAM
#define STRUCT_TBYTE(PARAM) s8 PARAM[3]
#define STRUCT_QBYTE(PARAM) s32 PARAM

/*SPLIT/FORMAT MACROS*/
/*HACK: Use of Multiline comments for formatting avoids extra spaces in output.
        Moving Splits to multiple lines for ease of reading
        Fixed typo on 6 params
        Use Cascade Macros to save repitition
*/
#define DELIM_HEAD_(A) EXPAND(_IF_VA_##A)(COMMA())
#define DELIM_COUNT_(A)
#define DELIM_BS_(A)     ,
#define DELIM_STRUCT_(A) ;


#define PARAMSPLIT_0(TYPE)
#define PARAMSPLIT_1(PARAM1, TYPE)\
/*					*/ TYPE##PARAM1 DELIM_##TYPE(0)
#define PARAMSPLIT_2(PARAM1, PARAM2, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1)\
/*					*/PARAMSPLIT_1(PARAM2, TYPE)
#define PARAMSPLIT_3(PARAM1, PARAM2, PARAM3, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1) \
/*					*/PARAMSPLIT_2(PARAM2, PARAM3, TYPE)
#define PARAMSPLIT_4(PARAM1, PARAM2, PARAM3, PARAM4, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1)\
/*					*/PARAMSPLIT_3(PARAM2, PARAM3, PARAM4, TYPE)
#define PARAMSPLIT_5(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1) \
/*					*/PARAMSPLIT_4(PARAM2, PARAM3, PARAM4, PARAM5, TYPE)
#define PARAMSPLIT_6(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1)\
/*					*/PARAMSPLIT_5(PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, TYPE)
#define PARAMSPLIT_7(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1)\
/*					*/PARAMSPLIT_6(PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, TYPE)
#define PARAMSPLIT_8(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, PARAM8, TYPE)\
/*					*/TYPE ## PARAM1 DELIM_##TYPE(1)\
/*					*/PARAMSPLIT_7(PARAM2, PARAM3, PARAM4, PARAM5, PARAM6, PARAM7, PARAM8, TYPE)


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
    */DEFINE CMDNAME (CAT(CAT(PARAMSPLIT_ , COUNTPARAMS((PARAMS))), (PARAMS, HEAD_)))\/*
*/                    CAT(AI_ , CMDNAME), \
/*                  */CAT(CAT(PARAMSPLIT_, COUNTPARAMS((PARAMS))), (PARAMS, BS_))\n /*
    */DEFINE CAT(CAT(AI_, CMDNAME), _LENGTH) (AICMDSIZE CAT(CAT(PARAMSPLIT_, COUNTPARAMS((PARAMS))), (PARAMS, COUNT_)))\n/*
    */typedef struct CAT(Ai_, CMDNAME) {u8 cmd; CAT(CAT(PARAMSPLIT_, COUNTPARAMS((PARAMS))),(PARAMS, STRUCT_))}CAT(Ai_, CMDNAME);/*
    */\n\n

#define _AI_DEBUG() \n/*
    */DESCRIPTION /*
    */DEFINE CAT(CMDNAME,(STRING))\/*
    */            CAT(AI_,CMDNAME),/*
    */typedef struct CAT(Ai_, CMDNAME) {u8 cmd;  u8 val[];}CAT(Ai_, CMDNAME);/*
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
