#ifndef _MEMA_H_
#define _MEMA_H_

#include <ultra64.h>

typedef struct allocation {
    s32 addr;
    u32 size;
} allocation;

void memaInit(void);
void memaSetBuffer(s32 buffer, s32 size);
void memaIterateAndMerge(void);
s32 memaFree(u32 size);
void memaRegister(u32 addr, u32 size);
void memaDumpPrePostMerge(void);
u32 memaGetLargestAllocSize(void);
s32 memaResize(s32 addr, u32 newsize, u32 oldsize);

#endif
