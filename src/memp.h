#ifndef _MEMP_H_
#define _MEMP_H_

#include <ultra64.h>

/*
* Align to 16 bit boundary. Version "b", without preliminary addition.
*/
#define ALIGN16_b(val)        (((val) | 0xf) ^ 0xf)

typedef struct s_mempBANK {
    u32 bankstart;
    u32 nextentry;
    u32 bankend;
    u32 data2;
} s_mempBANK;

typedef struct s_mempMVALS {
    u32 var1;
    u32 var2;
    u32 var3;
    u32 var4;
    u32 var5;
    u32 var6;
    u32 var7;
    u32 var8;
} s_mempMVALS;

void mempInitDebugNoticeList(void);
void mempCheckMemflagTokens(int bstart,int bsize);
void mempSetBankStarts(s32 banks[8]);
void *mempAllocBytesInBank(u32 bytes,u8 bank);
s32 mempAddEntryOfSizeToBank(u8* ptrdata, u32 size, u8 bank);
void nulled_mempLoopAllMemBanks(void);
s32 mempGetBankSizeLeft(u8 bank);
u32 mempAllocPackedBytesInBank(u32 param_1);
void mempResetBank(u8 bank);
void mempNullNextEntryInBank(u8 bank);

#endif
