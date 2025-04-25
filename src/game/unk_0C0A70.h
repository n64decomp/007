#ifndef _UNK_0C0A70_H_
#define _UNK_0C0A70_H_
#include <ultra64.h>

extern s32 lastFrameCounter;
extern s32 currentFrameCounter;
extern s32 speedgraphframes;

#if defined (BUGFIX_R1)
extern f32 jpD_800484CC;
extern f32 jpD_800484D0;
#endif

extern s32 previousFrameCounter;
extern s32 halfFrameCounter;
extern s32 isFrameCounterOdd;
extern s32 halfMinusPreviousCounter;
extern u32 copy_of_osgetcount_value_0;
extern u32 copy_of_osgetcount_value_1;
extern s32 frameDelay;

void waitForNextFrame(void);

#endif
