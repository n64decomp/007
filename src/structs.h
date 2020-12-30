#ifndef _TED_H_
#define _TED_H_

#include "ultra64.h"
#include "game/stan.h"

// Staying here for the moment.

enum EObjectClass { // u8
    Zero,
    NormalObj1,
    Door,
    Guard,
    NormalObject2,
    Unknown,
    OtherPlayer
};

struct float3 {
    float x;
    float y;
    float z;
};

struct float2 {
    float x;
    float z;
};

struct prop {
    u8 type; // enum EObjectClass
    u8 flags;
    s16 timetoregen;
    union {
        struct chrdata* chr;
        // 	struct defaultobj *obj;
        // 	struct doorobj *door;
        // 	struct weaponobj *weapon;
        // 	struct explosion *explosion;
        // 	struct smoke *smoke;
    };
    /* 0x08 */
    struct float3 position;
    /* 0x14 */
    struct StandTile * standTile;
    /* 0x18 */
    u32 unknown_0x18;
    /* 0x1C */
    struct prop * host;
    struct prop * child;
    struct prop * nextSibling;
    struct prop * prevSibling;
    u8 rooms[4];
};

#endif
