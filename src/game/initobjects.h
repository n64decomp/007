#ifndef _INITOBJECTS_H_
#define _INITOBJECTS_H_
#include "ultra64.h"

struct object_animation_controller {
    void * ptranimation;
    u16 offsettocurcmd;
    u16 waitcounter;
    u32 imagenum;
    f32 rotation;
    f32 curzoomx;
    f32 startzoomx;
    f32 zoomxtimer;
    f32 initialzoomx;
    f32 finalzoomx;
    f32 curzoomy;
    f32 startzoomy;
    f32 zoomytimer;
    f32 initialzoomy;
    f32 finalzoomy;
    f32 curhorizontalpos;
    f32 starthorscroll;
    f32 horscrolltimer;
    f32 horinitpos;
    f32 horfinalpos;
    f32 curverpos;
    f32 startverscroll;
    f32 verscrolltimer;
    f32 verinitpos;
    f32 verfinalpos;
    u8 curredcomponant;
    u8 initredcomponant;
    u8 finalredcomponant;
    u8 curgreencomponant;
    u8 initgreencomponant;
    u8 finalgreencomponant;
    u8 curbluecomponant;
    u8 initbluecomponant;
    u8 finalbluecomponant;
    u8 curalphacomponant;
    u8 initalphacomponant;
    u8 finalalphacomponant;
    f32 startcolorshift;
    f32 colorshifttimer;
};


#endif
