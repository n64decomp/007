#ifndef _IMAGE_BANK_H_
#define _IMAGE_BANK_H_
#include <ultra64.h>
#include <bondtypes.h>
#include "bondview.h"

extern struct sImageTableEntry *crosshairimage;

extern struct sImageTableEntry *mainfolderimages;
extern struct sImageTableEntry *mpstageselimages;
extern struct sImageTableEntry *genericimage;
extern struct sImageTableEntry *skywaterimages;
extern struct sImageTableEntry *monitorimages;
extern struct sImageTableEntry *mpcharselimages;

extern u8* img_curpos;
extern s32 img_bitcount;

void texReset(void);
u32 texReadBits(s32 bitCount);
void texSetBitstring(s32 pos);

#endif
