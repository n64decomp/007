#ifndef _UNK_0D1AC0_H_
#define _UNK_0D1AC0_H_
#include <ultra64.h>
#include <bondtypes.h>

Gfx * InitializeSpeedGraphDL(Gfx *DL);
void UpdateGraphPosition(f32 arg0);
void AlignGraphPosition(void);

Gfx *DrawGraphBar(Gfx *gdl, f32 offset, s32 r, s32 g, s32 b, s32 width, s32 height);
Gfx *DrawVerticalLines(Gfx *gdl, s32 r, s32 g, s32 b);

#endif
