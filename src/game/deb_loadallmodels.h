#ifndef _DEB_LOADALLMODELS_H_
#define _DEB_LOADALLMODELS_H_
#include <ultra64.h>

typedef struct WeaponProjectileModels {
    union {
        struct {
            s32 knife;
            s32 grenade;
            s32 remote;
            s32 prox;
            s32 timed;
            s32 rocket;
            s32 glaunch;
            s32 none;
        };
        s32 array[8];
    };
} WeaponProjectileModels;

void init_obj_register_difficulty_vals(void);

#endif
