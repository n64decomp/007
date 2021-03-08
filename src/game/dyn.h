#ifndef _DYN_H_
#define _DYN_H_

#include "ultra64.h"

/*
* Align to 16 bit boundary. Version "a", with preliminary addition.
*/
#define ALIGN16_a(val)        (((val) + 0xf | 0xf) ^ 0xf)

void dynInitDebugNoticeList(void);
void dynInitMemory(void);
Gfx *dynGetMasterDisplayList(void);
s32 dynGetFreeGfx2(Gfx *gdl);
void *dynAllocate7F0BD6C4(s32 count);
Mtx *dynAllocateMatrix(void);
void *dynAllocate7F0BD6F8(s32 count);
void *dynAllocate(s32 size);
void dynSwapBuffers(void);
void dynRemovedFunc(Gfx *gdl);
s32 dynGetFreeGfx(Gfx *gdl);
s32 dynGetFreeVtx(void);
void dynDrawMembars(Gfx *gdl);

#endif
