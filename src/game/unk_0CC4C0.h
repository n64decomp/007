#ifndef _UNK_0CC4C0_H_
#define _UNK_0CC4C0_H_
#include <ultra64.h>

#include "image.h"

struct image_sound
{
    /**
     * Array of sound effect ids.
    */
    u16 *sfx;

    u8 *thing2;

    /**
     * Number of items in sfx array.
    */
    s16 sfx_len;

    /**
     * Number of items in thing2 array.
    */
    u16 thing2_len;
};

typedef struct s_bss_8008D148
{
    s32 inuse;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} s_bss_8008D148;

typedef struct s_bss_8008D2A8
{
    s32 inuse;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
} s_bss_8008D2A8;


extern struct image_sound *D_8004E86C[];

s32 texGetHeightAtLod(struct tex *tex, s32 lod);
void texGetDepthAndSize(struct tex *tex, s32 *deptharg, s32 *lenarg);

void texCopyGdls(Gfx *arg0, Gfx *arg1, s32 arg2);

#endif
