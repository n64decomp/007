#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
    int mode;
    short txtClipW;
    short txtClipH;
    f32 far;
    f32 scale;
    f32 aspect;
    f32 anonymous_6;
    short somethingW;
    short somethingH;
    short width;
    short height;
    short ulx;
    short uly;
    int anonymous_12;
    u8* frameb;
};

#endif


