#ifndef _MEMP_H_
#define _MEMP_H_

#include <ultra64.h>

/*
* Align to 16 bit boundary. Version "b", without preliminary addition.
*/
#define ALIGN16_b(val)        (((val) | 0xf) ^ 0xf)

typedef struct MemoryPool {
    s32 start;
    s32 pos;
    s32 end;
    s32 prevpos;
} MemoryPool;

typedef struct s_mempMVALS {
    u32 var1;
    u32 mf;
    u32 var3;
    u32 ml;
    u32 stage;
    u32 me;
    u32 permanent;
    u32 var8;
} s_mempMVALS;

enum MEMPOOL
{
    MEMPOOL_0,
    MEMPOOL_MF,
    MEMPOOL_2,
    MEMPOOL_ML,
    MEMPOOL_STAGE,
    MEMPOOL_ME,
    MEMPOOL_PERMANENT,
    MEMPOOL_7
};

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
