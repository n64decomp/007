#ifndef _MP_WATCH_H_
#define _MP_WATCH_H_
#include "ultra64.h"

typedef enum TEXTCOLORS {
    GREEN_NORMAL=0,
    GREEN_HIGHLIGHT,
    RED_NORMAL,
    RED_HIGHLIGHT,
    BLUE_NORMAL,
    BLUE_HIGHLIGHT
} TEXTCOLORS;

s32 sub_GAME_7F0C2024(int param_1, int param_2, int param_3, int param_4, int param_5);

s32 sub_GAME_7F0C2114(int param_1, int param_2, int param_3, int param_4, int param_5);

#endif
