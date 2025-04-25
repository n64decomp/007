#ifndef _UNK_0BC530_H_
#define _UNK_0BC530_H_
#include <ultra64.h>

void setPlayerRoomField(s32 param_1);
void updateRoomStatusFlags(void);
void getRoomPositionScaledByIndex(s32 index, coord3d *param_2);
Gfx * applyRoomMatrixToDisplayList(Gfx *DL,int index);
struct coord3d* getRoomPositionByIndex(s32 index);

#endif
