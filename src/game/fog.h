#ifndef _FOG_H_
#define _FOG_H_
#include "ultra64.h"

struct fog_element {
    u32 stageID;
    f32 blendmultiplier;
    f32 farfog;
    f32 nearfog;
    f32 maxvisrange;
    f32 maxobfuscationrange;
    f32 minvisrange;
    u32 intensity;
    u32 dif_in_light;
    u32 far_ambiantlight;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    u16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    u16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

struct fog_element2 {
    u32 stageID;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    u16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    u16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

#endif
