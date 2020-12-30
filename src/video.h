#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
    s8 mode;
    s8 test1;
    s8 test2;
    s8 test3;
    s16 x;
    s16 y;
    f32 fovy;
    f32 aspect;
    f32 near;
    f32 far;
    s16 bufx;
    s16 bufy;
    s16 viewx;
    s16 viewy;
    s16 viewleft;
    s16 viewtop;
    s32 usezbuf;
    u8* framebuf;
};

void setvideo_far(f32 arg0);
void set_page_aspect(f32 arg0);
void set_page_height(f32 arg0, f32 arg1);
void set_video2_settings_offset_24(int param_1);
#endif


