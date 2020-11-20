#ifndef _MEMP_H_
#define _MEMP_H_

#include "ultra64.h"

typedef struct s_mempBANK {
    s32 bankstart;
    s32 nextentry;
    s32 bankend;
    s32 data2;
} s_mempBANK;

typedef struct s_mempMVALS {
    u32 D_80024410;
    u32 D_80024414;
    u32 mf;
    u32 D_8002441C;
    u32 ml;
    u32 D_80024424;
    u32 me;
    u32 D_8002442C;
    u32 D_80024430;
} s_mempMVALS;

typedef struct s_mempMEMSTARTS {
    s32 bank1start;
    s32 bank2start;
    s32 bank3start;
    s32 bank4start;
    s32 bank5start;
    s32 bank6start;
    s32 bank7start;
} s_mempMEMSTARTS;

void mempInitDebugNoticeList(void);
void mempCheckMemflagTokens(int bstart,int bsize);
void mempSetBankStarts(int *banks);
u32 mempAllocBytesInBank(u32 bytes,u8 bank);
u32 mempAddEntryOfSizeToBank(u8* ptrdata,u32 size,u8 bank);
void nulled_mempLoopAllMemBanks(void);
s32 mempGetBankSizeLeft(u8 bank);
u32 mempAllocPackedBytesInBank(u32 param_1);
void mempResetBank(u8 bank);
void mempNullNextEntryInBank(u8 bank);

#endif
