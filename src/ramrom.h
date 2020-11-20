#ifndef _RAMROM_H_
#define _RAMROM_H_
#include <ultra64.h>

void romCreateMesgQueue(void);
void romCopy(void *target, void *source, u32 size);
s32 romCopyAligned(void *target, void *source, s32 length);
void romWrite(void *source, void *target, u32 size);

#endif
