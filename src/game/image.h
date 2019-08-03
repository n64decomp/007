#ifndef _IMAGE_H_
#define _IMAGE_H_
#include "ultra64.h"

struct image_entry
{
  char flag1;
  char flag2;
  u16 size;
  char flag3;
  char flag4;
  char flag5;
  char flag6;
};

extern s32 ptr_texture_alloc_start;
extern struct image_entry image_entries[];

#endif
