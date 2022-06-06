#ifndef _OBJECTIVE_STATUS_H_
#define _OBJECTIVE_STATUS_H_
#include <ultra64.h>
#include <bondtypes.h>

void             objectiveTakePictureHandler();
bool             objectiveIsAllComplete(void);
TagObjectRecord *sub_GAME_7F057080(s32 TagID);
s32              objectiveGetCount(void);
ObjectRecord *   objFindByTagId(s32 TagID);
OBJECTIVESTATUS  get_status_of_objective(s32 objectiveNum);
void sub_GAME_7F057C14(struct coord3d *arg0, s32 *arg1);
#endif
