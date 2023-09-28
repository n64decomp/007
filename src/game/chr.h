#ifndef _CHR_H_
#define _CHR_H_
#include <ultra64.h>
#include <bondgame.h>
#include <bondtypes.h>
#include "chrai.h"

#define EXPLOSION_ANIMATION_TABLE_LEN 8

struct struck_animation_table;

struct animation_something
{
    s32 id;
    s32 field_4;
    s32 field_8;
    f32 field_C;
    s32 field_10;
    s32 field_14;
    f32 field_18;
    
    struct struck_animation_table *field_1C;

    // maybe count of field_1C
    s32 field_20;

    struct struck_animation_table *field_24;

    // maybe count of field_24
    s32 field_28;
};

struct struck_animation_table
{
    void *anonymous_0; // This might be pointer to struct of ANIM_DATA_x
    s32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;
    s32 anonymous_4;
    f32 sfx1_timer_60;
    f32 sfx2_timer_60;
};

struct explosion_death_animation
{
    s32 anonymous_0;
    s32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;
    f32 anonymous_4;
    f32 anonymous_5;
    f32 anonymous_6;
};

struct explosion_anim_group_info
{
    s8 *table;
    s32 count;
};

struct weapon_firing_animation_table
{
    s32 anonymous_0;
    f32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;

    /**
     * Offset 0x10.
    */
    f32 anonymous_4;
    f32 anonymous_5;
    f32 anonymous_6;
    f32 anonymous_7;

    /**
     * Offset 0x20.
    */
    f32 anonymous_8;
    f32 anonymous_9;
    f32 anonymous_10;
    f32 anonymous_11;

    /**
     * Offset 0x30.
    */
    f32 anonymous_12;
    f32 anonymous_13;

    /**
     * Some kind of minimum. See chrlvUpdateAimendsideback.
     * Offset 0x38.
    */
    f32 anonymous_14;

    /**
     * Some kind of maximum. See chrlvUpdateAimendsideback.
     * Offset 0x3c.
    */
    f32 anonymous_15;

    /**
     * Offset 0x40.
    */
    f32 anonymous_16;
    f32 anonymous_17;
};

struct anim_group_info
{
    struct weapon_firing_animation_table (*table)[];
    s32 len;
};

struct unk_joint_list {
    Mtxf * unk_matrix;
    s32 unk04;
    s32 unk08;
    Gfx *gdl;

    Mtxf * mtxlist;
    u32 unk14;
    u32 unk18;
    u32 unk1C;

    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;

    s32 unk30;
    s32 unk34;
    rgba_u8 unk38;
    s32 unk3C;
};

extern s32 objectiveregisters1;
extern ChrRecord* g_ActiveChrs;
extern s32 g_ActiveChrsCount;

extern f32 g_AiAccuracyModifier;
extern f32 g_AiDamageModifier;
extern f32 g_AiHealthModifier;
extern f32 g_AiReactionSpeed;
extern s32 g_SeenBondRecentlyGuardCount;

extern struct animation_something D_8002C914[];

extern struct struck_animation_table D_8002CE54[];
extern struct struck_animation_table D_8002DF10[];
extern struct struck_animation_table D_8002CEE0[];
extern struct struck_animation_table D_8002DF64[];
extern struct struck_animation_table D_8002CF6C[];
extern struct struck_animation_table D_8002DFB8[];
extern struct struck_animation_table D_8002D014[];
extern struct struck_animation_table D_8002E028[];
extern struct struck_animation_table D_8002D0A0[];
extern struct struck_animation_table D_8002E07C[];
extern struct struck_animation_table D_8002D12C[];
extern struct struck_animation_table D_8002E0D0[];
extern struct struck_animation_table D_8002D1D4[];
extern struct struck_animation_table D_8002E140[];
extern struct struck_animation_table D_8002D3B0[];
extern struct struck_animation_table D_8002E23C[];
extern struct struck_animation_table D_8002D6DC[];
extern struct struck_animation_table D_8002E300[];
extern struct struck_animation_table D_8002D768[];
extern struct struck_animation_table D_8002E354[];
extern struct struck_animation_table D_8002D7F4[];
extern struct struck_animation_table D_8002E3A8[];
extern struct struck_animation_table D_8002D880[];
extern struct struck_animation_table D_8002E418[];
extern struct struck_animation_table D_8002D90C[];
extern struct struck_animation_table D_8002E46C[];
extern struct struck_animation_table D_8002D998[];
extern struct struck_animation_table D_8002E4C0[];
extern struct struck_animation_table D_8002DA24[];
extern struct struck_animation_table D_8002E530[];
extern struct struck_animation_table D_8002DCE0[];
extern struct struck_animation_table D_8002E5BC[];

extern struct struck_animation_table D_8002DEBC[];
extern struct animation_something D_8002CAA0;
extern struct animation_something D_8002CACC;
extern struct animation_something D_8002CB24;
extern struct animation_something D_8002CB50;

extern struct weapon_firing_animation_table rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table rifle_firing_animation_group5[];
extern struct weapon_firing_animation_table rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table rifle_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table pistol_firing_animation_group6[];
extern struct weapon_firing_animation_table pistol_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group5[];
extern struct weapon_firing_animation_table doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table doubles_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_groupA[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group3[];


extern struct weapon_firing_animation_table D_80030078[];
extern struct weapon_firing_animation_table D_80030660[];

extern struct anim_group_info *ptr_rifle_firing_animation_groups[];
extern struct anim_group_info *ptr_pistol_firing_animation_groups[];
extern struct anim_group_info *ptr_doubles_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_rifle_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_pistol_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_doubles_firing_animation_groups[];

extern f32 animation_rate;
extern s32 D_8002C904;
extern s32 g_AnimationTablePointerCountRelated;
extern s32 D_8002C90C;
extern s32 D_8002C910;

extern s32 D_8002CC58;
extern s32 show_patrols_flag;
extern s32 player1_guardID;
extern ChrRecord *g_ChrSlots;
extern s32 g_NumChrSlots;
extern struct unk_joint_list D_8002CC6C;
extern s32 D_8002CCAC;
extern s32 D_8002CCB0;
extern s32 D_8002CCB4;
extern rgba_u8 D_8002CCB8;

extern f32 D_80030984;
extern f32 D_80030988;
extern f32 D_8003098C;
extern f32 D_80030990;
extern f32 D_80030994;
extern f32 D_80030998;
extern f32 D_8003099C;
extern f32 D_800309A0;
extern f32 D_800309A4;

extern point2d D_800309A8;
extern point2d D_800309B0;
extern point2d D_800309B8;
extern point2d D_800309C0;
extern point2d D_800309C8;
extern point2d D_800309D0;
extern point2d D_800309D8;
extern point2d D_800309E0;
extern point2d D_800309E8;
extern point2d D_800309F0;


extern u32 num_bodies;
extern u32 num_male_heads;
extern u32 num_female_heads;
extern s32 list_of_bodies[];
extern s32 random_male_heads[];
extern s32 random_female_heads[];
extern u32 current_random_body;
extern u32 current_random_male_head;
extern u32 current_random_female_head;

extern s32 female_guard_yelp_counter;
extern s16 female_guard_yelps[];
extern s32 male_guard_yelp_counter;
extern s16 male_guard_yelps[];

extern coord3d D_80030A44;
extern s16 metal_ricochet_SFX[3];

extern struct explosion_anim_group_info explosion_animation_table[];
extern struct explosion_death_animation D_8002E648[];

void        sub_GAME_7F022EE0(s32 param_1);
void        setanimationdebugflag(s32 param_1);
void        disable_sounds_attached_to_player_then_something(PropRecord* prop);
void        chrPositionRelated7F020D94(ChrRecord *);
void        chrSetMoving(ChrRecord *guard,s32 param_2);
f32         getAnimationRate(void);
void        setAnimationRate(f32);
PropRecord *init_GUARDdata_with_set_values(PropRecord *, Model *, coord3d *, f32 arg2, StandTile * arg3, s32 arg4);
PropRecord *chrAllocate(struct Model * arg0, coord3d * arg1, f32 arg2, StandTile * arg3, s32 arg4);
void        chrSetHiddenToRandom(ChrRecord *arg0);
void        chrRemoved7F022E1C(f32 arg0);
void        chrDecrementAnimationTablePointerCount(void);
void        chrIncrementAnimationTablePointerCount(void);
void        chrToggleD_8002C90C(void);
void        chrCheckGuardsHeardSound(f32 arg0);
ChrRecord  *chrFindByLiteralId(s32 index);
PropRecord *chrGetEquippedWeaponProp(ChrRecord *arg0, GUNHAND arg1);
PropRecord *chrGetEquippedWeaponPropWithCheck(ChrRecord *ChrRecord, GUNHAND arg1);
void        chrUpdateCollisionBounds(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *y_out, f32 *ground);
void        chrGetChrWidthHeight(PropRecord *arg0, f32 *width, f32 *height, f32 *always_20);
f32         chrGetChrGround(PropRecord *arg0);
void        chrDropItems(struct ChrRecord *arg0);
s32         get_numguards(void);
Gfx        *chrRenderProp(PropRecord *arg0, Gfx *arg1, s32 arg2);
void        chrAddHealth(ChrRecord *chr, f32 health);
void        chrSetMaxDamage(ChrRecord *chr, f32 maxdamage);
s32 sub_GAME_7F03DA50(struct PropRecord *arg0, s32 arg1);
s32 sub_GAME_7F023194(PropRecord *arg0, struct coord3d *arg1, struct coord2d *arg2, struct coord2d *arg3);

//tentative signature
s32         sub_GAME_7F01FC10(Model *, coord3d *, coord3d *, f32 *);
void sub_GAME_7F0221DC(Model *arg0, s32 arg1, ModelNode *arg2, struct coord3d *arg3);

#ifdef BUGFIX_R1
s32 not_in_us_7F0209EC(s32 bodynum, s32 headnum);
#endif

#endif
