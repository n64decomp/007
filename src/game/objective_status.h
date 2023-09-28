#ifndef _OBJECTIVE_STATUS_H_
#define _OBJECTIVE_STATUS_H_
#include <ultra64.h>
#include <bondtypes.h>

extern struct objective_entry * objective_ptrs[];
extern s32 objective_count;
extern s32 objective_count_related;

void             objectiveTakePictureHandler();
bool             objectiveIsAllComplete(void);
TagObjectRecord *sub_GAME_7F057080(s32 TagID);
s32              objectiveGetCount(void);
ObjectRecord *   objFindByTagId(s32 TagID);
OBJECTIVESTATUS  get_status_of_objective(s32 objectiveNum);
void             sub_GAME_7F057C14(coord3d *coord, Mtxf *mtx);
void objectivestatusCheckDeposit(s32 weaponnum, s32 roomid);
#endif
