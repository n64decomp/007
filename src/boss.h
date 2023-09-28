#ifndef _BOSS_H_
#define _BOSS_H_
#include <ultra64.h>
#include <bondgame.h>

struct memallocstring
{
  s32 id;
  void *string;
};

LEVELID bossGetStageNum();
void bossSetLoadedStage(LEVELID stage);
void bossInit(void);
void bossEnableShowMemUseFlag(void);
void bossMemBarsFlagToggle(void);
void bossRunTitleStage(void);
void bossReturnTitleStage(void);

#endif
