#ifndef _IMAGE_H_
#define _IMAGE_H_
#include "ultra64.h"

struct image_entry
{
  char flag1; //HitType
  char flag2; //remove this line
  u16 size;   //this is u32 Size:24 - 24bit size/address
  char flag3; //Detailflag1 used once with value 0x38D2 (S/T offset of detail)
  char flag4; //DetailFlag2  difference from detail image, to large image, in terms of 2 to the power of value. It is subtracted from the small one, and absolute value or something. (Zoinkity)
  char flag5; //padding
  char flag6; //padding
};

extern s32 ptr_texture_alloc_start;
extern struct image_entry image_entries[];

#endif
