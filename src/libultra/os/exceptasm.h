#ifndef _EXCEPTASM_H
#define _EXCEPTASM_H
#include <ultratypes.h>
#define THREAD_NEXT 0
#define THREAD_PRI 4
#define THREAD_QUEUE 8
#define THREAD_TLNEXT 12
#define THREAD_STATE 16
#define THREAD_FLAGS 18
#define THREAD_ID 20
#define THREAD_FP 24
#define THREAD_AT 32
#define THREAD_V0 40
#define THREAD_V1 48
#define THREAD_A0 56
#define THREAD_A1 64
#define THREAD_A2 72
#define THREAD_A3 80
#define THREAD_T0 88
#define THREAD_T1 96
#define THREAD_T2 104
#define THREAD_T3 112
#define THREAD_T4 120
#define THREAD_T5 128
#define THREAD_T6 136
#define THREAD_T7 144
#define THREAD_S0 152
#define THREAD_S1 160
#define THREAD_S2 168
#define THREAD_S3 176
#define THREAD_S4 184
#define THREAD_S5 192
#define THREAD_S6 200
#define THREAD_S7 208
#define THREAD_T8 216
#define THREAD_T9 224
#define THREAD_GP 232
#define THREAD_SP 240
#define THREAD_S8 248
#define THREAD_RA 256
#define THREAD_LO 264
#define THREAD_HI 272
#define THREAD_SR 280
#define THREAD_PC 284
#define THREAD_CAUSE 288
#define THREAD_BADVADDR 292
#define THREAD_RCP 296
#define THREAD_FPCSR 300
#define THREAD_FP0 304
#define THREAD_FP2 312
#define THREAD_FP4 320
#define THREAD_FP6 328
#define THREAD_FP8 336
#define THREAD_FP10 344
#define THREAD_FP12 352
#define THREAD_FP14 360
#define THREAD_FP16 368
#define THREAD_FP18 376
#define THREAD_FP20 384
#define THREAD_FP22 392
#define THREAD_FP24 400
#define THREAD_FP26 408
#define THREAD_FP28 416
#define THREAD_FP30 424

#define MESG(type) (type << 3)

#define MQ_MTQUEUE 0
#define MQ_FULLQUEUE 4
#define MQ_VALIDCOUNT 8
#define MQ_FIRST 12
#define MQ_MSGCOUNT 16
#define MQ_MSG 20

#define OS_EVENTSTATE_MESSAGE_QUEUE 0
#define OS_EVENTSTATE_MESSAGE 4

#ifdef _LANGUAGE_C
extern s32 (*__osHwIntTable[])(void); //maybe 6? or 9
#endif 

#endif
