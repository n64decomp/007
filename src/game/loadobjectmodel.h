#ifndef _LOADOBJECTMODEL_H_
#define _LOADOBJECTMODEL_H_
#include <ultra64.h>

s32 sizepropdef(PropDefHeaderRecord *pdef);

void setupUpdateObjectRoomPosition(ObjectRecord *);
s32 sub_GAME_7F056850(PadRecord *arg0, StandTile *arg1, f32 arg2, PadRecord *arg3, StandTile **arg4);
ObjectRecord *setupGetPtrToCommandByIndex(s32 index);
s32 tagGetCommandIndex(struct ObjectRecord *arg0);
#endif
