#ifndef _BONDHEAD_H_
#define _BONDHEAD_H_
#include <ultra64.h>

#include <bondtypes.h>

struct init_bond_anim_unk {
    u32 anim_id;
    f32 loopframe;
    f32 endframe;
    f32 unk0C;

    f32 unk10;
    f32 unk14;
};

extern struct init_bond_anim_unk g_BondMoveAnimationSetup[];

s32 waypointFindRoute(waypoint *, waypoint *, waypoint ** arr, s32 arr_len);
waypoint * sub_GAME_7F08FB90(waypoint *, waypoint *);
void bheadFlipAnimation();
void bheadUpdateIdleRoll();
void bheadUpdate(f32 arg0, f32 arg1);
void bheadAdjustAnimation(f32 arg0);
void bheadStartDeathAnimation(struct ModelAnimation *arg0, s32 arg1, f32 arg2, f32 arg3);
void bheadSetSpeed(f32 arg0);

#endif
