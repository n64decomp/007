#ifndef _JOY_H_
#define _JOY_H_

#include "ultra64.h"

struct contsample {
	OSContPad pads[MAXCONTROLLERS];
};

typedef s32 (*contplaybackfunc)(struct contsample*, s32);
typedef void (*contrecordfunc)(struct contsample*, s32, s32);

void joyInit(void);
void joyCheckStatusThreadSafe(void);
s8 joyGetControllerCount(void);
u8 joyGetConnectedControllers(void);
void joySetPlaybackFunc(contplaybackfunc func, s32 controllercount);
void joySetRecordFunc(contrecordfunc func);
void joyConsumeSamplesWrapper(void);
void joyPoll(void);
s8 joyGetStickX(s8 contpadnum);
s8 joy7000C174(s8 contpadnum);
s8 joyGetStickY(s8 contpadnum);
s8 joy7000C284(s8 contpadnum);
u16 joyGetButtons(s8 contpadnum, u16 mask);
u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask);
s32 joyGetStickXInRange(s8 contpadnum, s32 rangemin, s32 rangemax);
s32 joyGetStickYInRange(s8 contpadnum, s32 rangemin, s32 rangemax);
s32 joyGamePakProbe(void);
s32 joyGamePakLongRead(u8 address, u8 *buffer, s32 nbytes);
s32 joyGamePakLongWrite(u8 address, u8 *buffer, s32 nbytes);
void joyRumblePakStart(s32 controller, f32 duration);
void joyRumblePakStop(void);
void joySetContDataIndex(s32 index);

#endif
