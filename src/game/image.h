#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <ultra64.h>
#include <bondconstants.h>

struct image_entry
{
    HIT_TYPE hitSound : 4;  //HitType-Sound
    HIT_TYPE hitTexture : 4;  //HitType-Texture
    s32  size    : 24; //this is u32 Size:24 - 24bit size/address
    char flag3; //Detailflag1 used once with value 0x38D2 (S/T offset of detail)
    char flag4; //DetailFlag2  difference from detail image, to large image, in terms of 2 to the power of value. It is subtracted from the small one, and absolute value or something. (Zoinkity)
    char flag5; //padding
    char flag6; //padding
};

extern s32 ptr_texture_alloc_start;
extern struct image_entry image_entries[];
extern s32 dword_CODE_bss_8008D090;
extern u32 bytes;

void nullsub_41(s32 arg0);

#endif
