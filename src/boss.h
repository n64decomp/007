#ifndef _BOSS_H_
#define _BOSS_H_
#include <ultra64.h>
#include "bondgame.h"

struct memallocstring
{
  s32 id;
  void *string;
};

void set_loaded_stage(LEVELID stage);
void bossInitDebugNoticeList(void);

#endif
