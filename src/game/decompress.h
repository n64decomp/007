#ifndef _DECOMPRESS_H_
#define _DECOMPRESS_H_
#include "ultra64.h"
#include "inflate/inflate.h"


u32 decompressdata(u8 *src, u8 *dst, struct huft *hlist);
s32 sub_GAME_7F0CE894(void);

#endif
