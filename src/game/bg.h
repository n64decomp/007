#ifndef _BG_H_
#define _BG_H_
#include "ultra64.h"
#include "bondgame.h"

struct levelentry
{
  int levelID;
  void *bg_seg_filename;
  void *bg_stan_filename;
  float levelscale;
  float visibility;
  float unknownfloat;
};

#endif
