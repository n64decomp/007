#include <ultra64.h>
#include <bondaicommands.h>
#include <bondgame.h>
#include <bondconstants.h>
#include "chrlv.h"
#include <limits.h>
#include <math.h>
#include <music.h>
#include <random.h>
#include "bg.h"
#include "bondview.h"
#include "chr.h"
#include "chr_b.h"
#include "chrai.h"
#include "chrobjhandler.h"
#include "file.h"
#include "fog.h"
#include "front.h"
#include "gun.h"
#include "initanitable.h"
#include "loadobjectmodel.h"
#include "lvl.h"
#include "math_asinfacosf.h"
#include "math_atan2f.h"
#include "matrixmath.h"
#include "objecthandler.h"
#include "player.h"
#include "player_2.h"
#include "stan.h"
#include "bondhead.h"
#include "unk_0A1DA0.h"

#ifdef REFRESH_PAL
#define CHRLV_RECENT_TIME_CHECK 151
#define CHRLV_TICK_DEAD_CHECK 75
#define CHRLV_SEEN_RECENT_CHECK 100
#define CHRLV_LASTMOVEOK60_CHECK 50
#define CHRLV_ATTACKWALK_CLOCK_TIMER30_MIN 0x11
#define CHRLV_ATTACKWALK_CLOCK_TIMER30_MAX 0x1a
#define CHRLV_ATTACKWALK_TIMER40_A 0x4b
#define CHRLV_ATTACKWALK_TIMER40_B 0x10
#define CHRLV_ATTACKWALK_TIMER40_C 0x96
#define CHRLV_ATTACKWALK_TIMER40_D 0x21

#define CHRLV_DEFAULT_TIMER 0x96
#define CHRLV_10_SEC_TIMER 0x1f4 /* 500 */
#define CHRLV_FRAMERATE_F 50.0f

#else

#define CHRLV_RECENT_TIME_CHECK 181
#define CHRLV_TICK_DEAD_CHECK 90
#define CHRLV_SEEN_RECENT_CHECK 120
#define CHRLV_LASTMOVEOK60_CHECK 60
#define CHRLV_ATTACKWALK_CLOCK_TIMER30_MIN 0x15
#define CHRLV_ATTACKWALK_CLOCK_TIMER30_MAX 0x1F
#define CHRLV_ATTACKWALK_TIMER40_A 0x5a
#define CHRLV_ATTACKWALK_TIMER40_B 0x14
#define CHRLV_ATTACKWALK_TIMER40_C 0xb4
#define CHRLV_ATTACKWALK_TIMER40_D 0x28

#define CHRLV_DEFAULT_TIMER 0xb4
#define CHRLV_10_SEC_TIMER 0x258 /* 600 */
#define CHRLV_FRAMERATE_F 60.0f
#endif


// forward declarations

u32 check_if_item_held_like_pistol            (PropRecord *arg0);
void chrlvIdleAnimationRelated                (ChrRecord *self, f32 arg1);
f32 chrlvGetGuard007SpeedRating               (ChrRecord *self, f32 min, f32 max);
s32 chrlvGetGuard007SpeedRatingInt            (ChrRecord *self, s32 arg1);
f32 chrlvGetGuard007ArghRating                (ChrRecord *self, f32 min, f32 max);
void chrlvKneelingAnimationRelated            (ChrRecord *self);
void chrlvIdleAnimationRelated7F023E14        (ChrRecord *self, f32 arg1);
void chrlvKneelingAnimationRelated7F023E48    (ChrRecord *self);
void chrlvActorKneel                          (ChrRecord *self);
void chrlvPerformAnimationForActor            (ChrRecord *self, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
void chrlvExtendLeftHandAnimationRelated      (ChrRecord *self);
void chrlvThrowGrenadeAnimationRelated        (ChrRecord *self, PropRecord *arg1, s32 arg2, s32 arg3);
void chrlvSpotBondAnimationRelated            (ChrRecord *self, f32 arg1);
void chrlvActorShuffleFeet                    (ChrRecord *self);
void chrlvSurrenderAnimationRelated           (ChrRecord *self);
void chrlvActorLookFlustered                  (ChrRecord *self);
void chrlvActorThrowWeaponSurrender           (ChrRecord *self);
void chrlvActorFadeAway                       (ChrRecord *self);
void chrlvDeathStaggerAnimationRelated        (ChrRecord *self);
void chrlvAttackActionRelated                 (ChrRecord *self);
f32 chrlvDistanceToChrRelated                 (ChrRecord *self, s32 arg1, s32 arg2);
f32 get_distance_actor_to_position            (ChrRecord *self, coord3d *arg1);
f32 chrlvPathingCollisionRelated              (PropRecord *arg0, f32 arg1, f32 arg2, s32 objFlags, f32 unkHeight, f32 unkA);
f32 chrlvPathingCollisionRelated7F0264B0      (PropRecord *arg0, f32 arg1, f32 arg2);
void triggered_on_shot_hit                    (ChrRecord *self, coord3d *arg1, f32 arg2, s32 req_animation_id, ITEM_IDS item);
s32 chrlvAttackAnimationRelated7F026F30       (ChrRecord *self, f32 *result);
s32 chrlvStanRoomRelated                      (ChrRecord *self, coord3d *arg1, StandTile *tile);
f32 chrlvModelScaleAnimationRelated           (ChrRecord *self);
void chrlvActGoposRelated                     (ChrRecord *self, coord3d *arg1, StandTile **arg2);
s32 chrlvMovementTargetRelated                (ChrRecord *self);
waypoint *get_ptrpreset_in_table_matching_tile(StandTile* arg0);
s32 check_if_any_path_preset_lies_on_tile     (StandTile* arg0);
f32 chrlvPadPresetRelated                     (coord3d *arg0, waypoint *arg1);
waypoint *chrlvStanPathRelated                (coord3d *arg0, StandTile *arg1);
s32 chrlvStanRoomRelatedPad                   (ChrRecord *self, PadRecord *arg1);
void play_sound_for_shot_actor                (ChrRecord *);
void sub_GAME_7F025560                        (ChrRecord *self, s32 attack_type, s32 arg2);
coord3d *chrlvGetChrOrPresetLocation          (ChrRecord *self, s32 flags, s32 lookup_id, StandTile **stan);
void sub_GAME_7F02D184                        (ChrRecord *self);
void sub_GAME_7F0281F4                        (ChrRecord *self);
s32 plot_course_for_actor                     (ChrRecord *self, coord3d *arg1, StandTile *stan, SPEED speed);
void chrlvPlotCourseRelated                   (ChrRecord *self);
void chrlvActGoposSetTargetPosRelated         (ChrRecord *self);
void chrlvActGoposIncCurIndex                 (ChrRecord *self);
void play_hit_soundeffect_and_proper_volume   (ChrRecord *self);
void get_sound_at_range                       (ChrRecord *self, s32 arg1, s32 arg2);
void chrlvSetGoposSegDistTotal                (ChrRecord *self, struct waydata *arg1, coord3d *arg2);
void chrlvIterateGuardSeeShotDie              (ChrRecord *, s32);
s32 chrlvCall7F02982C                         (PropRecord *arg0, coord3d *arg1, f32 arg2);
void chrlvTickSurrender                       (ChrRecord *self);
void chrlvWalkingAnimationRelated             (ChrRecord *self);
void setSeenBondTimeToNow                     (ChrRecord *guardData);
s32 chrlvAttackRelated7F0292A8                (ChrRecord *self, coord3d *arg1, StandTile *arg2);
s32 chrlvMaybeSameRoom                        (ChrRecord *self, coord3d *arg1, StandTile *arg2);
s32 chrlvCurrentPlayerCall7F0B0E24            (ChrRecord *self);
s32 chrlvCall7F0B0E24WithChrWidthHeight       (PropRecord *arg0, coord3d *arg1, coord3d *arg2);
void chrlvSetTargetToPlayer                   (ChrRecord *self);
s32 chrSawTargetRecently                      (ChrRecord *);
s32 chrCheckTargetInSight                     (ChrRecord *self);
void chrlvModelRotyRelated                    (ChrRecord *self, s32 arg1, coord3d *arg2);
s32 chrIsNotDeadOrShot                        (ChrRecord *chr);
void chrlvTickAnim                            (ChrRecord *self);
void chrlvTickDead                            (ChrRecord *self);
void chrlvTickArgh                            (ChrRecord *self);
void chrlvTickPreArgh                         (ChrRecord *self);
void chrlvTickSidestep                        (ChrRecord *self);
void chrlvTickJumpout                         (ChrRecord *self);
void chrlvTickTest                            (ChrRecord *self);
void chrlvTickStartAlarm                      (ChrRecord *self);
void chrlvTickSurprised                       (ChrRecord *self);
void sub_GAME_7F02BFE4                        (ChrRecord *self, s32 arg1, s32 arg2);
s32 chrlvSetSubroty                           (ChrRecord *self, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 chrlvUpdateAimendsideback                 (ChrRecord *self, struct weapon_firing_animation_table *arg1, s32 arg2, s32 arg3, f32 arg4);
void chrlvResetAimend                         (ChrRecord *self);
void chrlvToggleHiddenRelated                 (ChrRecord *self, s32 arg1, s32 arg2);
void chrlvUpdateShotbondsum                   (ChrRecord *self, s32 *arg1, s32 *arg2, ITEM_IDS item);
f32 sub_GAME_7F02C27C                         (ChrRecord *self);
void chrlvFireWeaponRelated                   (ChrRecord *self, s32 hand);
s32 chrlvAttackrollAnimationRelated7F02E2E0   (ChrRecord *self);
void chrlvAttackrollAnimationRelated7F02E3B8  (ChrRecord *self);
void sub_GAME_7F0256F0                        (ChrRecord *self, s32 attack_type, s32 arg2);
void chrlvTickAttack                          (ChrRecord *self);
void chrlvTickAttackCommon                    (ChrRecord *);
void chrlvInitActAttackWalk                   (ChrRecord *chr, s32);
void sub_GAME_7F024CF8                        (ChrRecord *self, coord3d *arg1);
void chrlvTickThrowGrenade                    (ChrRecord *self);
void chrlvTickBondIntro                       (ChrRecord *self);
void chrlvTickBondDieRemoved                  (ChrRecord *self);
s32 chrlvApplySpeed                           (ChrRecord *self, coord3d *arg1, s32 arg2, f32 *speedPtr);
void chrlvTickAttackWalk                      (ChrRecord *self);
void chrlvTickRunPos                          (ChrRecord *self);
s32 sub_GAME_7F030128                         (ChrRecord *self, coord3d *point, StandTile *arg2, coord3d *dest, StandTile * arg4, s32 objflags);
s32 sub_GAME_7F0301FC                         (ChrRecord *self, coord3d *point, StandTile *arg2, coord3d *dest, f32 arg4, s32 arg5);
s32 sub_GAME_7F0304AC                         (ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, StandTile *arg5, s32 arg6);
void chrlvSwapIfDiffArg2Determinate           (coord3d *arg0, coord3d *arg1, coord3d *arg2);
s32 sub_GAME_7F03081C                         (ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, coord3d *arg5, f32 arg6, f32 arg7, s32 arg8);
s32 sub_GAME_7F030D70                         (ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, coord3d *arg5, f32 arg6, f32 arg7, s32 arg8);
void chrlvTravelTickMagic                     (ChrRecord *self, struct waydata *arg1, f32 arg2, coord3d *arg3, StandTile *arg4);
void chrlvTravelTick                          (ChrRecord *, coord3d *, StandTile *, struct waydata *);
void chrlvTickGoPos                           (ChrRecord *self);
void chrlvSetNextActPatrolStepPadPos          (ChrRecord *self);
void sub_GAME_7F0284DC                        (ChrRecord *self);
void chrlvTickPatrol                          (ChrRecord *self);
f32 get_distance_actor_to_position            (ChrRecord *self, coord3d *pos);
s32 chrResolveId                              (ChrRecord *self, s32 id);
s32 sub_GAME_7F033780                         (waypoint *arg0, coord3d *arg1, f32 angle);
s32 chrlvFindPathNeighborRelated              (coord3d *bondpos, StandTile *stan, f32 rot, u8 quadrant);
s32 sub_GAME_7F033EAC                         (coord3d *arg0, StandTile *arg1);
PropRecord *actionblock_guard_constructor_BDBE(s32 bodynum, s32 headnum, coord3d *pos, StandTile *stan, f32 yrot, AIListRecord *ailist, s32 arg5);
void chrlvInitActAttack                       (ChrRecord *self, struct anim_group_info ** arg1, s32 arg2, point2d *arg3, s32 attack_type, s32 arg5, s32 arg6);
s32 chrlvPatrolCalculateStep                  (ChrRecord *self, bool *forward, s32 numsteps);
s32 sub_GAME_7F028510                         (coord3d *arg0, StandTile *arg1);
s32 sub_GAME_7F03130C                         (ChrRecord *self,coord3d *arg1,s32 arg2,coord3d *arg3,f32 arg4,s32 arg5,coord3d *arg6,struct waydata *arg7,f32 arg8,s32 arg9,s32 set_copy);
void chrlvTickStand                           (ChrRecord *self);
PadRecord * chrlvGetPatrolStepPad             (ChrRecord *self, s32 arg1);

// unknown type for arg1, reads offsets 0x30,0x34,0x40,0x44
// arg2 is only used to compare to zero, either flag or pointer
void chrlvUpdateAimendbackShoulders           (ChrRecord *, void *, s32, s32, f32);


// end forward declarations














/**
 * Address 0x7F0234D0.
 */
Model * retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags)
{
    ModelFileHeader *body_header;
    ModelFileHeader *head_header;
    s32 sunglasses;
   
    body_header = c_item_entries[body].header;
    head_header = NULL;
    
    sunglasses = 0;

    if ((bitflags & 1))
    {
        sunglasses = 1;
    }
    else if ((bitflags & 2))
    {
        sunglasses = (randomGetNext() & 1) == 0;
    }
    
    if ((head >= 0) && (c_item_entries[body].hasHead == 0))
    {
        head_header = c_item_entries[head].header;
    }
    
    return setup_chr_instance(body, head, body_header, head_header, sunglasses);
}



s32 get_current_random_body(void)
{
  return list_of_bodies[current_random_body];
}




/**
 * Address 0x7F0235AC.
 * Get a Random Male Head Only
 * @param id: Integer Index of body
 * @return an integer ID of a head to use
 */
s32 select_psuedorandom_heads(s32 id)
{
    s32 ret;

    if (c_item_entries[id].isMale)
    {
        ret = randomGetNext() & 3;
        ret = ((s32)current_random_male_head + ret) % (s32)num_male_heads;
        ret = random_male_heads[ret];
    }
    else
    {
        ret = random_female_heads[current_random_female_head];
    }

    return ret;
}


/**
 * Get a Random head for body ID
 * @param id: Integer Index of body
 * @return an integer ID of a head to use
*/
s32 get_random_head(s32 id)
{
    return (c_item_entries[id].isMale ? random_male_heads[randomGetNext() % num_male_heads] : random_female_heads[randomGetNext() % num_female_heads]);
}



/**
 * Address 0x7F02370C.
*/
void expand_09_characters(s32 stageid, GuardRecord *arg1, s32 arg2)
{
    PadRecord *pad;
    s32 unused2;
    StandTile *sp54; // 84
    s32 unused3;
    ChrRecord *temp_v0_5;
    PadRecord *sp48; // 72
    PropRecord *temp_v0_4;
    ChrModelFileRecord *cmfr;
    f32 sp3C; // 60
    Model *sp38; //56
    s32 bodyid;
    s32 headid;

    pad = &g_chraiCurrentSetup.pads[arg1->PadID];

    if (sub_GAME_7F056850(pad, pad->stan, 20.0f, (PadRecord *)&sp48, &sp54) != 0)
    {
        headid = -1;
        bodyid = (arg1->BodyID == 0xFFFF) 
            ? get_current_random_body()
            : arg1->BodyID;

        cmfr = &c_item_entries[bodyid];
        if (cmfr->hasHead == 0)
        {
            headid = (arg1->HeadID >= 0)
                ? arg1->HeadID
                : select_psuedorandom_heads(bodyid);
        }

        sp38 = retrieve_header_for_body_and_head(bodyid, headid, (u32) arg1->bitflags);

        if (sp38 != 0)
        {
            sp3C = atan2f(pad->look.f[0], pad->look.f[2]);
            temp_v0_4 = replace_GUARDdata_with_actual_values(sp38, (PadRecord *)&sp48, sp3C, sp54, ailistFindById(arg1->AIListID));
            
            if (temp_v0_4 != 0)
            {
                chrpropActivate(temp_v0_4);
                chrpropEnable(temp_v0_4);

                temp_v0_5 = temp_v0_4->chr;
                temp_v0_5->chrnum = (s16) arg1->chrnum;
                temp_v0_5->hearingscale = ((f32)arg1->health) / 1000.0f;
                temp_v0_5->visionrange = (f32)arg1->ReactionTime;
                temp_v0_5->padpreset1 = (s16) arg1->Preset;
                temp_v0_5->chrpreset1 = (s16) arg1->chrpreset1;
                temp_v0_5->headnum = (s8) headid;
                temp_v0_5->bodynum = (s8) bodyid;

                if ((arg1->bitflags & 4) != 0)
                {
                    temp_v0_5->chrflags |= CHRFLAG_CLONE;
                }

                if ((arg1->bitflags & 8) != 0)
                {
                    temp_v0_5->chrflags |= CHRFLAG_INVINCIBLE;
                }

                arg1->Data = temp_v0_5;
            }
        }
    }
}



/**
 * Address 0x7F023910.
 * dont think this is right, shouldnt it check for gun flags not chr?
 */
u32 check_if_item_held_like_pistol(PropRecord *arg0)
{
    if (arg0 != NULL)
    {
        ChrRecord *v = (ChrRecord*)arg0->voidp;

        return bondwalkItemCheckBitflags(v->act_bytes.padding[84], 0x100U);
    }

    return 0U;
}



/**
 * Address 0x7F023948.
 */
void chrlvIdleAnimationRelated(ChrRecord *self, f32 duration)
{
    PropRecord *left;
    PropRecord *right;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    if (
        ((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_idle_unarmed], randomGetNext() & 1, 0, 0.25f, duration);
        modelSetAnimLooping(self->model, 0, 16.0f);
    }
    else if ((right != NULL) || (left != NULL))
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_idle], left != NULL, 0, 0.25f, duration);
        modelSetAnimLooping(self->model, 0, 16.0f);
        modelSetAnimEndFrame(self->model, 120.0f);
    }

    return;
}




/**
 * Address 0x7F023A94 (VERSION_US).
 * Address 0x7F023D94 (other)
 */
#ifdef REFRESH_PAL
#define RATE 1.2f
#else
#define RATE 1.0f
#endif

void chrlvIdleAnimationRelated7F023A94(ChrRecord *self, f32 arg1)
{
    f32 f2;

    sub_GAME_7F02D184(self);
    self->actiontype = ACT_STAND;

    self->act_stand.unk02c = 0;
    self->act_stand.face_entitytype = 0;
    self->act_stand.face_entityid = 0;
    self->act_stand.unk038 = 0;
    self->act_stand.unk03c = 2;
    self->act_stand.unk040 = 0;
    //eu bug, doesnt use pal version of CHRLV_SEEN_RECENT_CHECK) + CHRLV_DEFAULT_TIMER;
    //so temp hardcoded to 120) + 180;
    self->act_stand.unk044 = (randomGetNext() % (u32) 120) + 180;

    f2 = arg1;

    if (self->model->unka4 != RATE)
    {
#if defined(BUGFIX_R1)
        f2 *= (RATE / self->model->unka4);
#else
        f2 = arg1 / self->model->unka4;
#endif
    }

    if (f2 > 127.0f)
    {
        f2 = 127.0f;
    }

    self->sleep = (s8) (s32) f2;
    chrlvIdleAnimationRelated(self, arg1);
}


/**
 * @param arg0: guard
 * @param min: min reaction speed range
 * @param max: max reaction speed range
 * Address 0x7F023B5C.
 */
f32 chrlvGetGuard007SpeedRating(ChrRecord *self, f32 min, f32 max)
{
    f32 ret;

    ret = (f32) self->speedrating;
    ret = (get_007_reaction_speed() * (100.0f - ret)) + ret;
    return ((ret * (max - min)) / 100.0f) + min;
}



/**
 * @param self: guard
 * @param scale: scale factor
 * Address 0x7F023BC0.
 */
s32 chrlvGetGuard007SpeedRatingInt(ChrRecord *self, s32 scale)
{
    s32 ret;

    ret = (s32) self->speedrating;
    ret = (s32)(get_007_reaction_speed() * (f32)(100 - ret)) + ret;
    return ((100 - ret) * scale) / 100;
}




/**
 * @param arg0: guard
 * @param min: min argh speed range
 * @param max: max argh speed range
 * Address 0x7F023C54.
 */
f32 chrlvGetGuard007ArghRating(ChrRecord *self, f32 min, f32 max)
{
    f32 ret;

    ret = (f32) self->arghrating;
    ret = (get_007_reaction_speed() * (100.0f - ret)) + ret;
    return ((ret * (max - min)) / 100.0f) + min;
}




/**
 * Address 0x7F023CB8.
 */
void chrlvKneelingAnimationRelated(ChrRecord *self)
{
    if (self->actiontype == ACT_KNEEL)
    {
        sub_GAME_7F02D184(self);

        self->actiontype = ACT_STAND;
        self->act_stand.unk02c = 1;
        self->act_stand.face_entitytype = 0;
        self->act_stand.face_entityid = 0;
        self->act_stand.unk038 = 0;
        self->act_stand.unk03c = 2;
        self->act_stand.unk040 = 0;       
        // bug/typo??: this is the only code like this not adjusted for VERSION_EU
        self->act_stand.unk044 = (randomGetNext() % 120) + 180;
        self->sleep = 0;

        if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data)
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)((s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data), (s32) self->model->gunhand, 109.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
            modelSetAnimEndFrame(self->model, 140.0f);
        }
        else
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_left_leg], (s32) self->model->gunhand, 120.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
            modelSetAnimEndFrame(self->model, 151.0f);
        }

        return;
    }

    chrlvIdleAnimationRelated7F023A94(self, 16.0f);
}



/**
 * Address 0x7F023E14.
 */
void chrlvIdleAnimationRelated7F023E14(ChrRecord *self, f32 arg1)
{
    chrlvIdleAnimationRelated7F023A94(self, arg1);
    self->act_stand.unk040 = 1;
}




/**
 * Address 0x7F023E48.
 */
void chrlvKneelingAnimationRelated7F023E48(ChrRecord *self)
{
    chrlvKneelingAnimationRelated(self);
    self->act_stand.unk040 = 1;
}





/**
 * Address 0x7F023E74.
 */
void chrlvActorKneel(ChrRecord *self)
{
    PropRecord *left;
    PropRecord *right;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);
    sub_GAME_7F02D184(self);
    
    if (((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        s32 r = randomGetNext() & 1;
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow], r, 0.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
        modelSetAnimEndFrame(self->model, 28.0f);
    }
    else if ((right != NULL) || (left != NULL))
    {
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_left_leg], left != NULL, 0.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
        modelSetAnimEndFrame(self->model, 27.0f);
    }

    self->actiontype = ACT_KNEEL;
    self->sleep = 0;
}



/**
 * Address 0x7F023FE4.
 */
void chrlvPerformAnimationForActor(ChrRecord *self, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5)
{
    f32 farg2 = (f32)arg2;
    f32 phi_f0;

    phi_f0 = 0.5f;
    if ((arg4 & 0x80) != 0)
    {
        phi_f0 = -0.5f;
    }

    sub_GAME_7F02D184(self);
    modelSetAnimation(self->model, (void *) animation_table_ptrs1[arg1], (arg4 & 1) != 0, farg2, phi_f0, (f32)arg5);

    if (arg3 >= 0)
    {
        modelSetAnimEndFrame(self->model, (f32)arg3);
    }

    if ((arg4 & 0x20) != 0)
    {
        sub_GAME_7F06CE84(self->model, self->model->unkb8 * 4.0f);
    }

    self->chrflags &= 0xFDFFFFFF;
    self->actiontype = ACT_ANIM;

    self->act_anim.unk02c = (arg4 & 2) != 0;
    self->act_anim.unk30 = (arg4 & 4) != 0;
    self->act_anim.unk034 = (arg4 & 8) != 0;
    self->act_anim.unk038 = (arg4 & 0x10) != 0;
    self->act_anim.unk03c = (arg4 & 0x40) != 0;

    if (self->act_anim.unk038 != 0)
    {
        self->sleep = (s8) arg5;
    }
    else
    {
        self->sleep = 0;
    }
}



/**
 * Extend left hand = ACT_STARTALARM.
 * 
 * Address 0x7F024150.
 */
void chrlvExtendLeftHandAnimationRelated(ChrRecord *self)
{
    PropRecord *left;
    PropRecord *right;
    s32 phi_a2;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    phi_a2 = 0;
    if ((left != NULL) && (right == NULL))
    {
        phi_a2 = 1;
    }
    else if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        phi_a2 = randomGetNext() & 1;
    }

    sub_GAME_7F02D184(self);

    self->actiontype = ACT_STARTALARM;
    self->sleep = 0;

    modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_extending_left_hand], phi_a2, 40.0f, 1.0f, 16.0f);
    modelSetAnimEndFrame(self->model, 82.0f);
}



/**
 * Address 0x7F024238.
 */
void chrlvThrowGrenadeAnimationRelated(ChrRecord *self, PropRecord *arg1, s32 arg2, s32 arg3)
{
    sub_GAME_7F02D184(self);

    self->actiontype = ACT_THROWGRENADE;
    self->sleep = 0;

    if (arg3 != 0)
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_throw_grenade], arg2 != 0, 0.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
    }
    else
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_throw_grenade], arg2 != 0, 84.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
    }

    modelSetAnimEndFrame(self->model, 193.0f);
}




/**
 * Address 0x7F024334.
 */
void chrlvSpotBondAnimationRelated(ChrRecord *self, f32 arg1)
{
    PropRecord *left;
    PropRecord *right;
    s32 sp2C;
    f32 objarg4;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    sp2C = 0;
    if ((left != NULL) && (right == NULL))
    {
        sp2C = 1;
    }
    else if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        sp2C = randomGetNext() & 1;
    }

    objarg4 = chrlvGetGuard007SpeedRating(self, 0.6f, 0.96000004f); // 0.96000004 is different from 0.96
    modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_spotting_bond], sp2C, 10.0f, objarg4, arg1);
    modelSetAnimEndFrame(self->model, 52.0f);
}




/**
 * Address 0x7F024418.
 */
void chrlvActorShuffleFeet(ChrRecord *self)
{
    f32 temp_f0;

    temp_f0 = chrGetAngleToBond(self);

    if ((temp_f0 < 0.17453294f) || (temp_f0 > 6.1086526f))
    {
        chrlvSpotBondAnimationRelated(self, 16.0f);
        sub_GAME_7F02D184(self);
        self->actiontype = ACT_SURPRISED;
        self->sleep = 0;

        return;
    }

    if (chrHasStoppedOrPatroling(self) == 0)
    {
        chrlvKneelingAnimationRelated(self);
    }
}



/**
 * Address 0x7F0244AC.
 */
void chrlvSurrenderAnimationRelated(ChrRecord *self)
{
    sub_GAME_7F02D184(self);
    self->actiontype = ACT_SURPRISED;
    self->sleep = 0;
    modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 0.0f, chrlvGetGuard007SpeedRating(self, 0.35f, 0.56f), 16.0f);
    modelSetAnimEndFrame(self->model, 7.0f);
}



/**
 * Address 0x7F024548.
 */
void chrlvActorLookFlustered(ChrRecord *self)
{
    u32 sp2C;

    sp2C = randomGetNext() % 3U;

    sub_GAME_7F02D184(self);

    self->actiontype = ACT_SURPRISED;
    self->sleep = 0;
    modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_look_around], randomGetNext() & 1, 17.0f, 0.6f, 16.0f);

    if (sp2C == 0)
    {
        modelSetAnimEndFrame(self->model, chrlvGetGuard007SpeedRating(self, 38.0f, 8.0f));
    }
    else if (sp2C == 1)
    {
        modelSetAnimEndFrame(self->model, chrlvGetGuard007SpeedRating(self, 66.0f, 8.0f));
    }
    else
    {
        modelSetAnimEndFrame(self->model, chrlvGetGuard007SpeedRating(self, 96.0f, 8.0f));
    }
}




/**
 * Address 0x7F024648.
 */
void chrlvActorThrowWeaponSurrender(ChrRecord *self)
{
    PropRecord *left;
    PropRecord *right;

    if (self->actiontype != ACT_SURRENDER)
    {
        left = chrGetEquippedWeaponProp(self, GUNLEFT);
        right = chrGetEquippedWeaponProp(self, GUNRIGHT);

        sub_GAME_7F02D184(self);

        self->actiontype = ACT_SURRENDER;

        if ((right != NULL) || (left != NULL))
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed_drop_weapon], randomGetNext() & 1, 0.0f, 0.5f, 16.0f);
            modelSetAnimLooping(self->model, 40.0f, 16.0f);

            self->sleep = 0x10;

            if (left != 0)
            {
                propobjSetDropped(left, 2);
            }
            if (right != 0)
            {
                propobjSetDropped(right, 2);
            }

            self->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
        }
        else
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 0.0f, 0.5f, 16.0f);
            modelSetAnimLooping(self->model, 30.0f, 16.0f);

            self->sleep = 0x10;
        }

        chrDropItems(self);
    }
}



/**
 * Address 0x7F0247B8.
 */
void chrlvActorFadeAway(ChrRecord *self)
{
    if (self->actiontype != ACT_DEAD)
    {
        sub_GAME_7F02D184(self);
        self->actiontype = ACT_DEAD;
        self->act_dead.allowfade = -1;
        self->sleep = 0;
    }
}



/**
 * chrStepToSide
 * Address 0x7F024800.
 */
void chrlvSideStepAnimationRelated(ChrRecord *self, GUNHAND side)
{
    PropRecord *left;
    PropRecord *right;
    s32 sp2C;
    s32 phi_v1;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);
    sp2C = 0;
    phi_v1 = 0;

    if ((left != NULL) && (right != NULL))
    {
        sp2C = randomGetNext() & 1;
        phi_v1 = randomGetNext() & 1;
    }
    else if (check_if_item_held_like_pistol(left) == 0)
    {
        if ((check_if_item_held_like_pistol(right) == 0) && ((left != NULL) || (right != NULL)))
        {
            sp2C = left != 0;
            phi_v1 = randomGetNext() & 1;
        }
    }

    sub_GAME_7F02D184(self);

    self->actiontype = ACT_SIDESTEP;
    self->sleep = 0;

    if (phi_v1 == 0)
    {
        if (side != GUNRIGHT)
        {
            modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_side_step_left], 0, 5.0f, chrlvGetGuard007SpeedRating(self, 0.55f, 0.88000005f), 16.0f);
            modelSetAnimEndFrame(self->model, 27.0f);
        }
        else
        {
            modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_side_step_left], 1, 5.0f, chrlvGetGuard007SpeedRating(self, 0.55f, 0.88000005f), 16.0f);
            modelSetAnimEndFrame(self->model, 27.0f);
        }

        return;
    }

    if (((side != GUNRIGHT) && (sp2C == 0)) ||
        ((side == GUNRIGHT) && (sp2C != 0)))
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_slide_left], sp2C, 5.0f, chrlvGetGuard007SpeedRating(self, 0.7f, 1.12f), 16.0f);
        modelSetAnimEndFrame(self->model, 34.0f);

    }
    else
    {
        modelSetAnimation(self->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_slide_right], sp2C, 5.0f, chrlvGetGuard007SpeedRating(self, 0.7f, 1.12f), 16.0f);
        modelSetAnimEndFrame(self->model, 32.0f);
    }

    return;
}



/**
 * chrHopToSide
 * Address 0x7F024A84.
 */
void chrlvFireJumpToSideAnimationRelated(ChrRecord *self, GUNHAND side)
{
    PropRecord *left;
    PropRecord *right;
    s32 side2;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    side2 = GUNRIGHT;

    if ((left != NULL) && (right == NULL))
    {
        side2 = GUNLEFT;
    }
    else if (
        ((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        side2 = randomGetNext() & 1;
    }

    sub_GAME_7F02D184(self);

    self->actiontype = ACT_JUMPOUT;
    self->sleep = 0;

    if (((side != GUNRIGHT) && (side2 == GUNRIGHT)) ||
        ((side == GUNRIGHT) && (side2 != GUNRIGHT)))
    {
        if ((randomGetNext() & 1) != 0)
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_left], side2, 5.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
            modelSetAnimEndFrame(self->model, 49.0f);
        }
        else
        {
            modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_right], side2, 130.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
            modelSetAnimEndFrame(self->model, 173.0f);
        }

        return;
    }

    if ((randomGetNext() & 1) != 0)
    {
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_right], side2, 20.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
        modelSetAnimEndFrame(self->model, 63.0f);
    }
    else
    {
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_left], side2, 91.0f, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
        modelSetAnimEndFrame(self->model, 136.0f);
    }

    return;
}



/**
 *  // run to coord
 * Address 0x7F024CF8 (not EU).
 * Address 0x7F024CE0 (VERSION_EU).
 */
void sub_GAME_7F024CF8(ChrRecord *self, coord3d *arg1)
{
    f32 dx;
    f32 dz;
    s32 unused;
    f32 sq;
    PropRecord *left;
    PropRecord *right;
    s32 sp2C;
    s32 phi_a2;

    dx = self->prop->pos.f[0] - arg1->f[0];
    dz = self->prop->pos.f[2] - arg1->f[2];
    sq = sqrtf((dx * dx) + (dz * dz));
    
    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    sp2C = 1;

    if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        sp2C = 0;
        phi_a2 = randomGetNext() & 1;
    }
    else
    {
        if ((check_if_item_held_like_pistol(left)) || (check_if_item_held_like_pistol(right)))
        {
            sp2C = 0;
            phi_a2 = left != 0;
        }
        else
        {
            phi_a2 = left != 0;
        }
    }

    sub_GAME_7F02D184(self);

    self->actiontype = ACT_RUNPOS;
    self->act_runpos.pos.f[0] = arg1->f[0];
    self->act_runpos.pos.f[1] = arg1->f[1];
    self->act_runpos.pos.f[2] = arg1->f[2];
    self->sleep = 0;
    self->act_runpos.turnspeed = 0;
    self->act_runpos.neardist = 30.0f;

    if (sp2C)
    {
#ifdef VERSION_EU
        self->act_runpos.eta60 = (s32) (((sq / (D_80030988 * 0.5f)) * 50.0f) / 60.0f);
#else
        self->act_runpos.eta60 = (s32) (sq / (D_80030988 * 0.5f));
#endif
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_running], phi_a2, 0, 0.5f, 16.0f);
    }
    else
    {
#ifdef VERSION_EU
        self->act_runpos.eta60 = (s32) (((sq / (D_80030994 * 0.5f)) * 50.0f) / 60.0f);
#else
        self->act_runpos.eta60 = (s32) (sq / (D_80030994 * 0.5f));
#endif
        modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon], phi_a2, 0, 0.5f, 16.0f);
    }
}



void chrlvDeathStaggerAnimationRelated(ChrRecord *self)
{
    sub_GAME_7F02D184(self);
    self->actiontype = ACT_TEST;
    self->sleep = 0;
    modelSetAnimation(self->model, (struct ModelAnimation*)&ptr_animation_table->data[(s32)&ANIM_DATA_death_stagger_back_to_wall], 0, 10.0f, 0.5f, 16.0f);
    modelSetAnimLooping(self->model, 10.0f, 16.0f);
    modelSetAnimEndFrame(self->model, 40.0f);
}




/**
 * Called from actor_fire_or_aim_at_target_update, where action type is ACT_ATTACK.
 * 
 * Address 0x7F024F8C.
 */
void chrlvAttackActionRelated(ChrRecord *self)
{
    Model* model = self->model;

    struct weapon_firing_animation_table *f = self->act_attack.animfloats;

    if ((self->act_attack.attacktype & TARGET_AIM_ONLY) != 0)
    {
        if ((f->anonymous_8 >= 0.0f) && (f->anonymous_8 < f->anonymous_6))
        {
            modelSetAnimEndFrame(model, f->anonymous_8);
        }
        else
        {
            modelSetAnimEndFrame(model, f->anonymous_6);
        }
    }
    else if (self->act_attack.unk36 != 0)
    {
        if (f->anonymous_8 >= 0.0f)
        {
            modelSetAnimEndFrame(model, f->anonymous_8);
        }
        else
        {
            modelSetAnimEndFrame(model, f->anonymous_6);
        }
    }
    else if (f->anonymous_8 >= 0.0f)
    {
        modelSetAnimEndFrame(model, f->anonymous_8);
    }
    else if (f->anonymous_5 >= 0.0f)
    {
        modelSetAnimEndFrame(model, f->anonymous_5);
    }
    else
    {
        modelSetAnimEndFrame(model, -1.0f);
    }
}



/**
 * Address 0x7F0250BC.
 */
f32 chrlvDistanceToChrRelated(ChrRecord *self, s32 arg1, s32 arg2)
{
    f32 ret;
    StandTile *out_unused;

    if ((arg1 & 2) != 0)
    {
        return 0.0f;
    }

    if ((arg1 & 0x10) != 0)
    {
        ret = ((f32) arg2 * M_TAU_F) / M_U16_MAX_VALUE_F;

        ret -= getsubroty(self->model);

        if (ret < 0.0f)
        {
            ret += M_TAU_F;
        }

        return ret;
    }

    return get_distance_actor_to_position(self, chrlvGetChrOrPresetLocation(self, arg1, arg2, &out_unused));
}



 /**
  * @param self:
  * @param arg1: address of array of firing animations (example: ptr_pistol_firing_animation_groups)
  * @param arg2: flag of some sort related to calculating distance
  * @param arg3: flags
  * @param attack_type: 
  * @param arg5: chrlvDistanceToChrRelated arg2
  * @param arg6: set self->act_attack.unk54 to this
  * 
  * Address 0x7F02516C.
  */
void chrlvInitActAttack(ChrRecord *self, struct anim_group_info **arg1, s32 arg2, point2d *arg3, s32 attack_type, s32 arg5, s32 arg6)
{
    /**
     * Two unused stack variables, I tried to use them with the animation table
     * but couldn't get a match.
    */
    
    //
    Model *self_model; // 140
    s32 phi_s7;
    s32 next_anim;
    struct weapon_firing_animation_table *panim_float; // 128
    s32 unused;
    s32 unused2;
    s32 phi_s6;
    f32 dist;
    s32 anim_index;
    ChrRecord *temp_chr;
    point2d sp60; // 96
    point2d sp58; // 88
    s32 i;

    self_model = self->model;
    sp60 = D_800309A8;
    sp58 = D_800309B0;
    self->actiontype = ACT_ATTACK;
    phi_s6 = 1;
    phi_s7 = 0;

    dist = chrlvDistanceToChrRelated(self, attack_type, arg5);

    if (arg2 != 0)
    {
        anim_index = (s32) ((((M_TAU_F - dist) * 32.0f) / M_TAU_F) + 0.5f);
    }
    else
    {
        anim_index = (s32) (((dist * 32.0f) / M_TAU_F) + 0.5f);
    }

    if (anim_index >= 0x20)
    {
        anim_index = 0;
    }

    next_anim = (u32)randomGetNext() % (u32)arg1[anim_index]->len;

    // I can't get a `li t0,72` without explicit multiply, but
    // it seems array dereference would be more correct here?
    // Something like:
    //     &arg1[anim_index]->table[next_anim]
    //     arg1[anim_index]->table + next_anim
    panim_float = (struct weapon_firing_animation_table *)(
            (s32)arg1[anim_index]->table + (s32)((s32)next_anim * (s32)sizeof(struct weapon_firing_animation_table))
        );

    if ((self->chrflags & 0x20)
        && ((s32)panim_float->anonymous_0 == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_hip]))
    {
        // should be:
        //     panim_float = &arg1[anim_index]->table[(next_anim + 1) % len]
        // where `len = arg1[anim_index]->len`
        panim_float = (struct weapon_firing_animation_table *)(
            (s32)arg1[anim_index]->table + (s32)(((next_anim + 1) % arg1[anim_index]->len) * (s32)sizeof(struct weapon_firing_animation_table))
        );
    }

    for (i=0; i<2; i++)
    {
        if (arg3->p[i] != 0)
        {
            temp_chr = chrGetEquippedWeaponProp(self, i)->chr;

            if (bondwalkItemGetAutomaticFiringRate((s32) temp_chr->act_attack.attack_item) < 0)
            {
                sp60.p[i] = 1;
                if ((s32)temp_chr->act_attack.attack_item == ITEM_LASER)
                {
                    phi_s6 = 0;
                }
            }
            else
            {
                phi_s6 = 0;
                phi_s7 = 1;
            }

            if (((s32)temp_chr->act_attack.attack_item == ITEM_ROCKETLAUNCH) || ((s32)temp_chr->act_attack.attack_item == ITEM_GRENADELAUNCH))
            {
                sp58.p[i] = 1;
            }
        }
    }

    self->act_attack.unk30 = 1;
    self->act_attack.animfloats = panim_float;
    self->act_attack.unk31 = 0;
    self->act_attack.unk32 = (u32)randomGetNext() & 1U;
    self->act_attack.unk38[1] = arg3->p[1];
    self->act_attack.unk38[0] = arg3->p[0];
    self->act_attack.unk3a[1] = sp60.p[1];
    self->act_attack.unk3a[0] = sp60.p[0];
    self->act_attack.unk3c[1] = sp58.p[1];
    self->act_attack.unk3c[0] = sp58.p[0];
    self->act_attack.unk36 = phi_s6;
    self->act_attack.unk37 = phi_s7;
    self->act_attack.unk40 = 0;
    self->act_attack.unk33 = 0;

    if ((sp58.p[1] != 0) || (sp58.p[0] != 0))
    {
        if ((sp58.p[1] != 0) && (sp58.p[0] != 0))
        {
            self->act_attack.unk34 = 2;
        }
        else
        {
            self->act_attack.unk34 = 1;
        }
    }
    else
    {
        if ((attack_type & 0x80) != 0)
        {
            self->act_attack.unk34 = 1;
        }
        else
        {
            self->act_attack.unk34 = (randomGetNext() & 3) + 2;
        }

        if ((arg3->p[0] != 0) && (arg3->p[1] != 0))
        {
            self->act_attack.unk34 += (randomGetNext() & 3) + 2;
        }
    }

    self->act_attack.attacktype = attack_type;
    self->act_attack.entityid = arg5;
    self->act_attack.unk54 = arg6;
    self->act_attack.type_of_motion = 0;
    self->act_attack.unk44 = 0;
    self->act_attack.attack_time = 0;
    self->sleep = 0;

    modelSetAnimation(
        self_model,
        (struct ModelAnimation *) panim_float->anonymous_0,
        arg2,
        panim_float->anonymous_4,
        chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
        16.0f);

    chrlvAttackActionRelated(self);
}



/**
 * Address 0x7F025560.
*/
void sub_GAME_7F025560(ChrRecord *self, s32 attack_type, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 last_arg2;
    struct anim_group_info **animation_pointer;
    point2d sp;
    PropRecord * left2;
    PropRecord * right2;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    sp = D_800309B8;

    if ((left != NULL) && (right != NULL))
    {
        left2 = chrGetEquippedWeaponPropWithCheck(self, GUNLEFT);
        right2 = chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT);

        if ((left2 != NULL) && (right2 != NULL))
        {
            last_arg2 = (u32)randomGetNext() & (u32)1;

            if (((u32)randomGetNext() % 3U) == 0)
            {
                animation_pointer = (struct anim_group_info **)ptr_pistol_firing_animation_groups;
                sp.p[GUNLEFT] = last_arg2;
                sp.p[GUNRIGHT] = !last_arg2;
            }
            else
            {
                animation_pointer = (struct anim_group_info **)ptr_doubles_firing_animation_groups;
                sp.p[GUNLEFT] = 1;
                sp.p[GUNRIGHT] = 1;
            }
        }
        else
        {
            last_arg2 = right2 == 0;
            animation_pointer = (struct anim_group_info **)ptr_pistol_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
    }
    else
    {
        if ((check_if_item_held_like_pistol(left) != 0) || (check_if_item_held_like_pistol(right) != 0))
        {
            last_arg2 = left != 0;
            animation_pointer = (struct anim_group_info **)ptr_pistol_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
        else
        {
            last_arg2 = left != 0;
            animation_pointer = (struct anim_group_info **)ptr_rifle_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
    }

    chrlvInitActAttack(self, animation_pointer, last_arg2, &sp, attack_type, arg2, 1);
}



/**
 * Address 0x7F0256F0.
 * PD: chrAttackKneel.
*/
void sub_GAME_7F0256F0(ChrRecord *self, s32 attack_type, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 last_arg2;
    struct anim_group_info **animation_pointer;
    point2d sp;
    PropRecord * left2;
    PropRecord * right2;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    sp = D_800309C0;

    if ((left != NULL) && (right != NULL))
    {
        left2 = chrGetEquippedWeaponPropWithCheck(self, GUNLEFT);
        right2 = chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT);

        if ((left2 != NULL) && (right2 != NULL))
        {
            last_arg2 = (u32)randomGetNext() & (u32)1;

            if (((u32)randomGetNext() % 3U) == 0)
            {
                animation_pointer = (struct anim_group_info **)ptr_crouched_pistol_firing_animation_groups;
                sp.p[GUNLEFT] = last_arg2;
                sp.p[GUNRIGHT] = !last_arg2;
            }
            else
            {
                animation_pointer = (struct anim_group_info **)ptr_crouched_doubles_firing_animation_groups;
                sp.p[GUNLEFT] = 1;
                sp.p[GUNRIGHT] = 1;
            }
        }
        else
        {
            last_arg2 = right2 == 0;
            animation_pointer = (struct anim_group_info **)ptr_crouched_pistol_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
    }
    else
    {
        if ((check_if_item_held_like_pistol(left) != 0) || (check_if_item_held_like_pistol(right) != 0))
        {
            last_arg2 = left != 0;
            animation_pointer = (struct anim_group_info **)ptr_crouched_pistol_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
        else
        {
            last_arg2 = left != 0;
            animation_pointer = (struct anim_group_info **)ptr_crouched_rifle_firing_animation_groups;
            sp.p[GUNLEFT] = last_arg2;
            sp.p[GUNRIGHT] = !last_arg2;
        }
    }

    chrlvInitActAttack(self, animation_pointer, last_arg2, &sp, attack_type, arg2, 0);
}


/**
 * // run forward shooting
 * Address 0x7F02587C.
*/
void chrlvInitActAttackWalk(ChrRecord *chr, s32 arg1)
{
    struct weapon_firing_animation_table *panim_float; // 132
    s32 i; //
    ChrRecord *tmp_chr; //
    s32 sp78; // 120
    point2d sp70; // 112
    point2d sp68; // 104
    point2d sp60; // 96
    PropRecord *left;
    PropRecord *left2;
    PropRecord *right;
    PropRecord *right2;
    s32 phi_v1;
    u32 unused = 1;

    left = chrGetEquippedWeaponProp(chr, GUNLEFT);
    right = chrGetEquippedWeaponProp(chr, GUNRIGHT);

    sp70 = D_800309C8;
    sp68 = D_800309D0;
    sp60 = D_800309D8;

    if ((left != NULL) && (right != NULL))
    {
        left2 = chrGetEquippedWeaponPropWithCheck(chr, GUNLEFT);
        right2 = chrGetEquippedWeaponPropWithCheck(chr, GUNRIGHT);

        phi_v1 = 0U;

        if ((left2 != NULL) && (right2 != NULL))
        {
            sp78 = (u32)randomGetNext() & 1U;
            phi_v1 = (u32)randomGetNext() % 3U;
        }
        else
        {
            sp78 = right2 == 0;
        }

        if (phi_v1 == 0)
        {
            if (arg1 != 0)
            {
                panim_float = &D_80030660[3];
            }
            else
            {
                panim_float = &D_80030660[2];
            }

            if (sp78)
            {
                sp70.p[1] = 1;
            }
            else
            {
                // bug/mistake/typo.
                sp70.p[0] = sp70.p[0] = 1;
            }
        }
        else if (phi_v1 == 1)
        {
            if (arg1 != 0)
            {
                panim_float = &D_80030660[5];
            }
            else
            {
                panim_float = &D_80030660[4];
            }

            sp70.p[1] = 1;
            sp70.p[0] = 1;
        }
        else
        {
            if (arg1 != 0)
            {
                panim_float = &D_80030660[7];
            }
            else
            {
                panim_float = &D_80030660[6];
            }

            sp70.p[1] = 1;
            sp70.p[0] = 1;
        }
    }
    else if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
    {
        sp78 = (s32)left != 0;

        if (arg1)
        {
            panim_float = &D_80030660[3];
        }
        else
        {
            panim_float = &D_80030660[2];
        }

        if (sp78)
        {
            sp70.p[1] = 1;
        }
        else
        {
            sp70.p[0] = 1;
        }
    }
    else
    {
        sp78 = (s32)left != 0;

        if (arg1)
        {
            panim_float = &D_80030660[1];
        }
        else
        {
            panim_float = &D_80030660[0];
        }

        if (sp78)
        {
            sp70.p[1] = 1;
        }
        else
        {
            sp70.p[0] = 1;
        }
    }

    for (i=0; i<2; i++)
    {
        if (sp70.p[i])
        {
            tmp_chr = chrGetEquippedWeaponProp(chr, i)->chr;

            if (bondwalkItemGetAutomaticFiringRate((s32) tmp_chr->act_attackwalk.attack_item) < 0)
            {
                sp68.p[i] = 1;
            }

            if ((tmp_chr->act_attackwalk.attack_item == ITEM_ROCKETLAUNCH) || (tmp_chr->act_attackwalk.attack_item == ITEM_GRENADELAUNCH))
            {
                sp60.p[i] = 1;
            }
        }
    }

    chr->actiontype = ACT_ATTACKWALK;
    chr->act_attackwalk.clock_timer30 = 0;
    #if defined(REFRESH_PAL)
    chr->act_attackwalk.clock_timer34 = ((u32) randomGetNext() % (u32) (s32) (333.333343506f * g_AiReactionSpeed)) + CHRLV_SEEN_RECENT_CHECK;
    #else
    chr->act_attackwalk.clock_timer34 = ((u32) randomGetNext() % (u32) (s32) (400.0f * g_AiReactionSpeed)) + CHRLV_SEEN_RECENT_CHECK;
    #endif
    chr->act_attackwalk.unk038 = 0;
    chr->act_attackwalk.animfloats = panim_float;
    chr->act_attackwalk.timer40 = 0;
    chr->act_attackwalk.unk044 = (u32)randomGetNext() & 1U;
    chr->act_attackwalk.unk48[1] = (s8) sp70.p[1];
    chr->act_attackwalk.unk48[0] = (s8) sp70.p[0];
    chr->act_attackwalk.unk4a[1] = (s8) sp68.p[1];
    chr->act_attackwalk.unk4a[0] = (s8) sp68.p[0];
    chr->act_attackwalk.unk4C[1] = (s8) sp60.p[1];
    chr->act_attackwalk.unk4C[0] = (s8) sp60.p[0];
    chr->sleep = 0;
    chr->act_attackwalk.speed = 0.0f;

    modelSetAnimation(chr->model, (struct ModelAnimation *) panim_float->anonymous_0, sp78, panim_float->anonymous_4, 0.5f, 16.0f);
}


/**
 * chrRollToSide
 * Address 0x7F025C40.
*/
void chrlvInitActAttackRoll(ChrRecord *chr, GUNHAND side)
{
    Model *self_model; // 140
    struct weapon_firing_animation_table *panim_float; // 136
    PropRecord *left; // any
    PropRecord *left_2; // any
    s32 sp7C; // 124
    s32 sp78; // 120
    ChrRecord *sp70; // any
    ChrRecord *temp_v1_2; // 112
    PropRecord *right; // any
    point2d sp64; // 100
    PropRecord *right_2; // any
    s32 sp5C; // 92
    point2d sp54; // 84
    point2d sp4C; // 76
    s8 phi_s3; // 72
    s32 i; // 68

    self_model = chr->model;
    left = chrGetEquippedWeaponProp(chr, GUNLEFT);
    right = chrGetEquippedWeaponProp(chr, GUNRIGHT);
    sp78 = 0;
    sp64 = D_800309E0;
    sp5C = 0;
    sp54 = D_800309E8;
    sp4C = D_800309F0;
    phi_s3 = 1;

    if ((left != NULL) && (right != NULL))
    {
        left_2 = chrGetEquippedWeaponPropWithCheck(chr, GUNLEFT);
        right_2 = chrGetEquippedWeaponPropWithCheck(chr, GUNRIGHT);

        if ((left_2 != NULL) && (right_2 != NULL))
        {
            sp7C = (u32)randomGetNext() & 1U;
            sp78 = 1;

            if (((u32)randomGetNext() % 3U) == 0)
            {
                sp64.p[1] = sp7C;
                sp64.p[0] = sp7C == 0;
            }
            else
            {
                sp64.p[1] = 1;
                sp64.p[0] = 1;
            }
        }
        else
        {
            sp7C = (s32)right_2 == 0;
            sp78 = 1;
            sp64.p[1] = sp7C;
            sp64.p[0] = sp7C == 0;
        }
    }
    else if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
    {
        sp7C = (s32)left != 0;
        sp78 = 1;
        sp64.p[1] = sp7C;
        sp64.p[0] = sp7C == 0;
    }
    else
    {
        sp7C = (s32)left != 0;
        sp64.p[1] = sp7C;
        sp64.p[0] = sp7C == 0;
    }

    if (((side != GUNRIGHT) && (sp7C == 0)) ||
        ((side == GUNRIGHT) && (sp7C != 0)))
    {
        if ((u32)randomGetNext() & 1U)
        {
            panim_float = &D_80030078[0];
        }
        else
        {
            panim_float = &D_80030078[2];
        }
    }
    else if ((u32)randomGetNext() & 1U)
    {
        panim_float = &D_80030078[1];
    }
    else
    {
        panim_float = &D_80030078[3];
    }

    if (sp78 != 0)
    {
        panim_float += 4;
    }

    for (i=0; i<2; i++)
    {
        if (sp64.p[i] != 0)
        {
            temp_v1_2 = chrGetEquippedWeaponProp(chr, i)->chr;

            if (bondwalkItemGetAutomaticFiringRate((s32) temp_v1_2->act_attackroll.attack_item) < 0)
            {
                sp54.p[i] = 1;
                if (temp_v1_2->act_attackroll.attack_item == ITEM_LASER)
                {
                    phi_s3 = 0;
                }
            }
            else
            {
                phi_s3 = 0;
                sp5C = 1;
            }

            if ((temp_v1_2->act_attackroll.attack_item == ITEM_ROCKETLAUNCH) || (temp_v1_2->act_attackroll.attack_item == ITEM_GRENADELAUNCH))
            {
                sp4C.p[i] = 1;
            }
        }
    }

    chr->actiontype = ACT_ATTACKROLL;
    chr->act_attackroll.animfloats = panim_float;
    chr->act_attackroll.unk31 = 0;
    chr->act_attackroll.unk32 = (u32)randomGetNext() & (u32)1;
    chr->act_attackroll.unk38[1] = sp64.p[1];
    chr->act_attackroll.unk38[0] = sp64.p[0];
    chr->act_attackroll.unk3a[1] = sp54.p[1];
    chr->act_attackroll.unk3a[0] = sp54.p[0];
    chr->act_attackroll.unk3c[1] = sp4C.p[1];
    chr->act_attackroll.unk3c[0] = sp4C.p[0];
    chr->act_attackroll.unk36 = phi_s3;
    chr->act_attackroll.unk37 = sp5C;
    chr->act_attackroll.unk35 = sp78;
    chr->act_attackroll.unk40 = 0;
    chr->act_attackroll.unk33 = 0;
    chr->act_attackroll.unk30 = 1;

    if ((sp4C.p[1] != 0) || (sp4C.p[0] != 0))
    {
        if ((sp4C.p[1] != 0) && (sp4C.p[0] != 0))
        {
            chr->act_attackroll.unk34 = 2;
        }
        else
        {
            chr->act_attackroll.unk34 = (s8) 1U;
        }
    }
    else
    {
        chr->act_attackroll.unk34 = (s32)((u32)randomGetNext() & 3U) + 2;

        if ((sp64.p[0] != 0) && (sp64.p[1] != 0))
        {
            chr->act_attackroll.unk34 += (s32)((u32)randomGetNext() & 3U) + 2;
        }
    }

    chr->act_attackroll.unk4c[0] = 1;
    chr->act_attackroll.unk4c[1] = 0;
    chr->act_attackroll.unk54[0] = 1;
    chr->act_attackroll.unk54[1] = 0;
    chr->act_attackroll.unk44 = 0;
    chr->act_attackroll.attack_time = 0;
    chr->sleep = 0;
    
    modelSetAnimation(
        self_model,
        (struct ModelAnimation *) panim_float->anonymous_0,
        sp7C,
        panim_float->anonymous_4,
        chrlvGetGuard007SpeedRating(chr, 0.5f, 0.8f),
        16.0f);
    
    if (sp78 == 0)
    {
        if (phi_s3 != 0)
        {
            if (panim_float->anonymous_9 >= 0.0f)
            {
                modelSetAnimEndFrame(self_model, panim_float->anonymous_9);
            }
            else
            {
                modelSetAnimEndFrame(self_model, panim_float->anonymous_7);
            }
        }
        else if (panim_float->anonymous_8 >= 0.0f)
        {
            modelSetAnimEndFrame(self_model, panim_float->anonymous_8);
        }
        else if (panim_float->anonymous_5 >= 0.0f)
        {
            modelSetAnimEndFrame(self_model, panim_float->anonymous_5);
        }
    }
}



/**
 * Line-line intersection, where arg0 and arg1 are two points on line1, and arg2 and arg3 are a point and a direction of line2.
 * 3d coord/vector are passed as arguments, but only the 2d (x,z) values are used to find the intersection.
 * 
 * @param line1_p1: first point to describe line1
 * @param line1_p2: second point to describe line1
 * @param line2_p3: first point to describe line2
 * @param dir: vector giving direction of line2
 * @param result: contains result
 * 
 * Address 0x7F026130.
 */
void chrlvLineLineIntersection(coord3d *line1_p1, coord3d *line1_p2, coord3d *line2_p3, coord3d *dir, coord3d *result)
{
    /*
     * Line1 = P1 + u * (P2 - P1) 
     * Line2 = P3 + v * D
     * 
     * Intersection is where Line1==Line2, or:
     *     P1 + u * (P2 - P1) = P3 + v * D
     * 
     * u and v are unknown.
     * 
     * Isolate u:
     * 
     * u = (P3 + v*D - P1) / (P2 - P1)
     */
    f32 denom;

    // solve for v. (much algebra follows, not shown)
    
    denom = (dir->f[2] * (line1_p2->f[0] - line1_p1->f[0])) - (dir->f[0] * (line1_p2->f[2] - line1_p1->f[2]));

    if (denom != 0.0f)
    {
        f32 v = (
            ((line1_p1->f[2] - line2_p3->f[2]) * (line1_p2->f[0] - line1_p1->f[0])) 
            + ((line2_p3->f[0] - line1_p1->f[0]) * (line1_p2->f[2] - line1_p1->f[2]))
        ) / denom;

        // v is known, denom is non-zero, plug back into equation for Line2 = P3 + v * D

        result->f[0] = line2_p3->f[0] + (dir->f[0] * v);
        result->f[1] = line2_p3->f[1] + (dir->f[1] * v);
        result->f[2] = line2_p3->f[2] + (dir->f[2] * v);
    }
    else if ((dir->f[0] == 0.0f) && (dir->f[2] == 0.0f))
    {
        // else, denominator is zero, but direction is also zero, so assume Line 2 point as result
        result->f[0] = line2_p3->f[0];
        result->f[1] = line2_p3->f[1];
        result->f[2] = line2_p3->f[2];
    }
    else
    {
        // all other cases, fallback to Line 1 first point
        result->f[0] = line1_p1->f[0];
        result->f[1] = line1_p1->f[1];
        result->f[2] = line1_p1->f[2];
    }
}



/**
 * Line-line intersection.
 * The first two points are retrieved from getCollisionEdge_maybe.
 * The arguments to the method supply the other line, described by a point and direction.
 * 
 * 3d coord/vector are passed as arguments, but only the 2d (x,z) values are used to find the intersection.
 * 
 * @param line2_p3: first point to describe line2
 * @param dir: vector giving direction of line2
 * @param result: out parameter, contains result.
 * 
 * Address 0x7F02624C.
 */
void chrlvStanLineDirIntersection(coord3d *line2_p3, coord3d *dir, coord3d *result)
{
    coord3d sp2C;
    coord3d sp20;

    getCollisionEdge_maybe(&sp2C, &sp20);
    chrlvLineLineIntersection(&sp2C, &sp20, line2_p3, dir, result);
}



/**
 * @param arg0:
 * @param arg1:
 * @param result: out parameter, contains result.
 * 
 * Address 0x7F026298.
 */
void chrlvStanPointPointIntersection(coord3d *arg0, coord3d *arg1, coord3d *result)
{
    coord3d sp2C;
    coord3d sp20;
    f32 v;

    getCollisionEdge_maybe(&sp2C, &sp20);

    // see comments in chrlvLineLineIntersection

    v = ((arg1->f[0] * (sp2C.f[2] - arg0->f[2])) - (arg1->f[2] * (sp2C.f[0] - arg0->f[0]))) 
        / ((arg1->f[2] * (sp20.f[0] - sp2C.f[0])) - (arg1->f[0] * (sp20.f[2] - sp2C.f[2])));

    result->f[0] = sp2C.f[0] + ((sp20.f[0] - sp2C.f[0]) * v);
    result->f[1] = sp2C.f[1] + ((sp20.f[1] - sp2C.f[1]) * v);
    result->f[2] = sp2C.f[2] + ((sp20.f[2] - sp2C.f[2]) * v);
}




/**
 * Address 0x7F026364.
 */
f32 chrlvPathingCollisionRelated(PropRecord *arg0, f32 arg1, f32 arg2, s32 objFlags, f32 unkHeight, f32 unkA)
{
    coord3d sp5C; // sp92
    f32 dest_x; // sp88
    f32 dest_z; // sp84
    StandTile *stan; // sp80
    ChrRecord *chr; // sp76
    f32 ret;
    coord3d sp3C;

    stan = arg0->stan;
    chr = arg0->chr;

    sp5C.f[0] = sinf(arg1);
    sp5C.f[1] = 0.0f;
    sp5C.f[2] = cosf(arg1);
    dest_x = arg0->pos.f[0] + (sp5C.f[0] * arg2);
    dest_z = arg0->pos.f[2] + (sp5C.f[2] * arg2);

    set_or_unset_GUARDdata_flag(chr, 0);
    sub_GAME_7F0B1CC4();

    if (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], dest_x, dest_z, objFlags, unkHeight, unkA, 0.0f, 1.0f) != 0)
    {
        ret = arg2;
    }
    else
    {
        chrlvStanLineDirIntersection(&arg0->pos, &sp5C, &sp3C);
        dest_x = sp3C.f[0] - arg0->pos.f[0];
        dest_z = sp3C.f[2] - arg0->pos.f[2];
        ret = sqrtf((dest_x * dest_x) + (dest_z * dest_z));
    }

    set_or_unset_GUARDdata_flag(chr, 1);

    return ret;
}




/**
 * Address 0x7F0264B0.
*/
f32 chrlvPathingCollisionRelated7F0264B0(PropRecord *arg0, f32 arg1, f32 arg2)
{
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    chrGetChrWidthHeight(arg0, &sp24, &sp2C, &sp28);
    return chrlvPathingCollisionRelated(arg0, arg1, arg2, 0x1F, sp2C, sp28);
}




/**
 * @param arg0:
 * @param arg1:
 * @param arg2:
 * @param req_animation_id: Lookup by id property in D_8002C914
 * @param item: argument to bondwalkItemGetForceOfImpact
 * 
 * Address 0x7F026508.
 */
void triggered_on_shot_hit(ChrRecord *self, coord3d *arg1, f32 arg2, s32 req_animation_id, ITEM_IDS item)
{
    // stack offset in decimal

    s32 flag9c; // 156(sp)
    PropRecord *prop; // 152
    struct Model *model; // 148
    s32 another_flag; // 144
    f32 impact_force; // ?
    s32 animation_something_index; // 136
    s32 flag1; // 132
    u8 *sp80 = NULL; // ?
    struct animation_something *something_ani = NULL; // ?
    f32 fa;
    f32 fb;
    f32 f_under; // 112(sp)
    f32 f_over; // 108(sp)
    f32 ft;
    struct struck_animation_table *struck_ani; // 100
    s32 i;

    flag9c = 1;
    prop = self->prop;
    model = self->model;
    another_flag = 0;
    animation_something_index = 0;

    if ((self->prop->type != PROP_TYPE_VIEWER) || (getPlayerCount() < 2))
    {
        flag1 = (self->actiontype == ACT_ARGH) && (g_GlobalTimer == self->act_argh.unk30);

        for (i=0; D_8002C914[i].id != -1; i++)
        {
            if (req_animation_id == D_8002C914[i].id)
            {
                animation_something_index = i;

                break;
            }
        }

        if (self->damage >= self->maxdamage)
        {
            if (((arg2 < 1.5707964f) || (arg2 > 4.712389f)) && ((randomGetNext() % (u32)0x14) == 0))
            {
                ft = getsubroty(model) + M_PI_F;

                fa = ft + 0.17453294f;
                f_under = ft - 0.17453294f;

                if (fa >= M_TAU_F)
                {
                    fa -= M_TAU_F;
                }

                if (f_under >= M_TAU_F)
                {
                    f_under -= M_TAU_F;
                }

                f_over = chrlvPathingCollisionRelated7F0264B0(prop, fa, 150.0f);
                f_under = chrlvPathingCollisionRelated7F0264B0(prop, f_under, 150.0f);

                if ((f_over < 150.0f) && (f_under < 150.0f))
                {
                    ft = f_over - f_under;
                    if ((ft < 10.0f) && (ft > -10.0f))
                    {
                        struck_ani = &D_8002DEBC[randomGetNext() & 1];

                        sub_GAME_7F02D184(self);
                        self->actiontype = ACT_DIE;
                        self->act_die.notifychrindex = 0;
                        self->act_die.thudframe1 = struck_ani->sfx1_timer_60;
                        self->act_die.thudframe2 = struck_ani->sfx2_timer_60;
                        self->sleep = 0;
                        self->act_die.timeextra = 0.0f;

                        modelSetAnimationWithMerge(model, (void*)struck_ani->anonymous_0, struck_ani->anonymous_1, 0.0f, struck_ani->anonymous_3, 16.0f, flag1 == 0);

                        if (struck_ani->anonymous_2 >= 0.0f)
                        {
                            modelSetAnimEndFrame(model, struck_ani->anonymous_2);
                        }

                        // Note: PD sets the chrwidth to 10 when a guard dies slumped against an object or wall
                        self->chrwidth = 10.0f;

                        another_flag = 1;
                    }
                }
            }

            if (another_flag == 0)
            {
                if ((D_8002C914[animation_something_index].field_1C != NULL) && (D_8002C914[animation_something_index].field_20 > 0))
                {
                    struct struck_animation_table *struck_anib; // sp(92)
                    s32 tr;

                    if (0)
                    {
                        // removed
                    }
                    
                    another_flag = 1;

                    tr = (randomGetNext() % (u32)D_8002C914[animation_something_index].field_20);
                    struck_anib = &D_8002C914[animation_something_index].field_1C[tr];
                    sub_GAME_7F02D184(self);

                    self->actiontype = ACT_DIE;
                    self->act_die.notifychrindex = 0;
                    self->act_die.thudframe1 = struck_anib->sfx1_timer_60;
                    self->act_die.thudframe2 = struck_anib->sfx2_timer_60;
                    self->sleep = 0;
                    self->act_die.timeextra = 0.0f;

                    modelSetAnimationWithMerge(model, (void*)struck_anib->anonymous_0, struck_anib->anonymous_1, 0.0f, struck_anib->anonymous_3, 16.0f, flag1 == 0);

                    if ((s32)struck_anib->anonymous_0 == ((s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_neck]) && ((randomGetNext() % (u32)0x64) != 0))
                    {
                        modelSetAnimEndFrame(model, 241.0f);
                    }
                    else if (struck_anib->anonymous_2 >= 0.0f)
                    {
                        modelSetAnimEndFrame(model, struck_anib->anonymous_2);
                    }

                    impact_force = bondwalkItemGetForceOfImpact(item);

                    if ((impact_force <= 0.0f) && ((self->chrflags & CHRFLAG_IMPACT_ALWAYS) != 0))
                    {
                        impact_force = 6.0f;
                    }

                    if ((struck_anib->anonymous_4 != 0) && (impact_force > 0.0f))
                    {
                        self->act_die.elapseextra = 0.0f;
                        self->act_die.timeextra = ((impact_force * 90.0f) / 6.0f);
                        self->act_die.extraspeed.f[0] = (arg1->f[0] * impact_force);
                        self->act_die.extraspeed.f[1] = (arg1->f[1] * impact_force);
                        self->act_die.extraspeed.f[2] = (arg1->f[2] * impact_force);
                    }
                }
            }

            chrDropItems(self);
            increment_num_kills_display_text_in_MP();
            
            if (self->chrflags & CHRFLAG_COUNT_DEATH_AS_CIVILIAN)
            {
                inc_cur_civilian_casualties();
            }
        }
        else
        {
            if ((req_animation_id == 7) && (arg2 > 2.3561945f) && (arg2 < 3.926991f) && ((u32) (randomGetNext() % (u32)5) < 2U))
            {
                u32 sp54 = randomGetNext() % (u32)5;
                sub_GAME_7F02D184(self);
                self->actiontype = ACT_ARGH;
                self->act_argh.notifychrindex = 0;
                self->act_argh.unk30 = g_GlobalTimer;
                self->sleep = 0;

                if ((randomGetNext() & 1) != 0)
                {
                    sp80 = &ptr_animation_table->data[(s32)&ANIM_DATA_hit_butt_long];
                    modelSetAnimationWithMerge(model, sp80, randomGetNext() & 1, 10.f, 0.5f, 16.0f, flag1 == 0);

                    if (sp54 < 2U)
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, 34.0f, 8.0f));
                    }
                    else if (sp54 < 4U)
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, 71.0f, 8.0f));
                    }
                    else
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, (f32) (((u16*)sp80)[2] - 1), 8.0f));
                    }
                }
                else
                {
                    sp80 = &ptr_animation_table->data[(s32)&ANIM_DATA_hit_butt_short];
                    modelSetAnimationWithMerge(model, sp80, randomGetNext() & 1, 0.0f, 0.5f, 16.0f, flag1 == 0);
                    
                    if (sp54 < 2U)
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, 37.0f, 8.0f));
                    }
                    else if (sp54 < 4U)
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, 70.0f, 8.0f));
                    }
                    else
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, (f32) (((u16*)sp80)[2] - 1), 8.0f));
                    }
                }
                
                another_flag = 1;
            }

            if (another_flag == 0)
            {
                if ((D_8002C914[animation_something_index].field_24 != NULL) && (D_8002C914[animation_something_index].field_28 > 0))
                {
                    PropRecord *temp_left = chrGetEquippedWeaponProp(self, GUNLEFT); // 80(sp)
                    PropRecord *temp_right = chrGetEquippedWeaponProp(self, GUNRIGHT);
                    s32 tr;
                    struct struck_animation_table *struck_ani; // 68(sp)
                    s32 ff = flag1 == 0; // 52(sp) ??

                    another_flag = 1;
                    something_ani = &D_8002C914[animation_something_index];
                    
                    if (((s32)&D_8002C914[9] == (s32)something_ani) && (temp_left != NULL))
                    {
                        animation_something_index = 10;
                    }
                    else if (((s32)&D_8002C914[12] == (s32)something_ani) && (temp_right != NULL))
                    {
                        animation_something_index = 13;
                    }
                    
                    something_ani = &D_8002C914[animation_something_index];
                    tr = (randomGetNext() % (u32) something_ani->field_28);
                    struck_ani = &something_ani->field_24[tr];

                    sub_GAME_7F02D184(self);
                    
                    self->actiontype = ACT_ARGH;
                    self->act_argh.notifychrindex = 0;
                    self->act_argh.unk30 = g_GlobalTimer;
                    self->sleep = 0;

                    modelSetAnimationWithMerge(model, (void*)struck_ani->anonymous_0, struck_ani->anonymous_1, 0.0f, struck_ani->anonymous_3, 16.0f, ff);

                    if (struck_ani->anonymous_2 >= 0.0f)
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, struck_ani->anonymous_2, 8.0f));
                    }
                    else
                    {
                        modelSetAnimEndFrame(model, chrlvGetGuard007ArghRating(self, (f32)((s32)((u16*)struck_ani->anonymous_0)[2] - (s32)1), 8.0f));
                    }
                }
            }

            flag9c = 0;
        }

        if (flag9c && another_flag)
        {
            if ((self->weapons_held[GUNRIGHT] != NULL) && ((self->weapons_held[GUNRIGHT]->obj->flags & 0x2000) == 0))
            {
                propobjSetDropped(self->weapons_held[GUNRIGHT], 1);
                self->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
            }

            if ((self->weapons_held[GUNLEFT] != NULL) && ((self->weapons_held[GUNLEFT]->obj->flags & 0x2000) == 0))
            {
                propobjSetDropped(self->weapons_held[GUNLEFT], 1);
                self->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
            }
        }
    }
}


/**
 * @param self:
 * @param result: out parameter, will contain result
 * @returns status indicating if result is set
 * 
 * Address 0x7F026F30.
*/
s32 chrlvAttackAnimationRelated7F026F30(ChrRecord *self, f32 *result)
{
    s32 flag;
    f32 out_val;

    flag = 0;

    if (self->actiontype == ACT_ATTACKROLL)
    {
        if (self->act_attackroll.unk35 != 0)
        {
            if (
                (self->act_attackroll.animfloats == &D_80030078[4])
                || (self->act_attackroll.animfloats == &D_80030078[5])
                || (self->act_attackroll.animfloats == &D_80030078[6])
                || (self->act_attackroll.animfloats == &D_80030078[7]))
            {
                out_val = self->act_attackroll.animfloats->anonymous_1 - 8.0f;

                if (self->act_attackroll.animfloats->anonymous_5 < self->act_attackroll.animfloats->anonymous_1)
                {
                    out_val = self->act_attackroll.animfloats->anonymous_5;
                }

                if (objecthandlerGetModelField28(self->model) < out_val)
                {
                    *result = out_val;
                    flag = 1;
                }
            }
        }
        else
        {
            out_val = self->act_attackroll.animfloats->anonymous_1 - 8.0f;
            if (objecthandlerGetModelField28(self->model) < out_val)
            {
                *result = out_val;
                flag = 1;
            }
        }
    }
    else if (self->actiontype == ACT_PREARGH)
    {
        // typo/mistake, return without setting *result
        flag = 1;
    }

    return flag;
}




#ifdef NONMATCHING

/**
 * Address 0x7F027060.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: mystery section, seems to be missing something mips_to_c can't see.
 * male_guard_yelp_counter, female_guard_yelp_counter are static, need to be moved from chr.c
 * Also need to remove female_guard_yelps, male_guard_yelps from chr.c once this matches.
*/
void play_sound_for_shot_actor(ChrRecord *self)
{
    ALSoundState * sndstate = NULL;
    s32 male = 0;

    static s32 male_guard_yelp_counter = 0;
    static s32 female_guard_yelp_counter = 0;

    if ((self->prop->type != PROP_TYPE_VIEWER) || (g_playerPointers[sub_GAME_7F09B15C(self->prop)]->bonddead == 0))
    {
        /*
        * decomp issue: mystery section.
        * what is going on right here?
        * self = 104(sp), why is it only loaded six times instead of seven?
        */
        if (self->prop->type == PROP_TYPE_VIEWER)
        {
            if (getPlayerCount() == 1)
            {
                if (c_item_entries[self->bodynum].isMale != 0)
                {
                    male = 1;
                }
            }
            else
            {
                if (get_player_mp_char_gender(sub_GAME_7F09B15C(self->prop)) != 0)
                {
                    male = 1;
                }
            }
        }
        else if (c_item_entries[self->bodynum].isMale != 0)
        {
            male = 1;
        }

        if (male != 0)
        {
            //s16 sounds[26] = male_guard_yelps;
            s16 sounds[] = {
                0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,
                0x90,  0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x99,
                0x9A,  0x9B,  0x9C,  0x9D,  0x9E
            };

            sndstate = sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, sounds[male_guard_yelp_counter], NULL);

            male_guard_yelp_counter++;
            if (male_guard_yelp_counter >= 25)
            {
                male_guard_yelp_counter = 0;
            }
        }
        else
        {
            //s16 sounds[4] = female_guard_yelps;
            s16 sounds[] = {
                0xD,   0xE,   0xF
            };

            sndstate = sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, sounds[female_guard_yelp_counter], NULL);

            female_guard_yelp_counter++;
            if (female_guard_yelp_counter >= 3)
            {
                female_guard_yelp_counter = 0;
            }
        }

        sub_GAME_7F053A10(sndstate, &self->prop->pos);
    }
}
#else
GLOBAL_ASM(
.text
glabel play_sound_for_shot_actor
/* 05BB90 7F027060 27BDFF98 */  addiu $sp, $sp, -0x68
/* 05BB94 7F027064 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05BB98 7F027068 AFA40068 */  sw    $a0, 0x68($sp)
/* 05BB9C 7F02706C 8C850018 */  lw    $a1, 0x18($a0)
/* 05BBA0 7F027070 24010006 */  li    $at, 6
/* 05BBA4 7F027074 00001825 */  move  $v1, $zero
/* 05BBA8 7F027078 90AF0000 */  lbu   $t7, ($a1)
/* 05BBAC 7F02707C 00A02025 */  move  $a0, $a1
/* 05BBB0 7F027080 55E1000C */  bnel  $t7, $at, .L7F0270B4
/* 05BBB4 7F027084 8FA90068 */   lw    $t1, 0x68($sp)
/* 05BBB8 7F027088 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 05BBBC 7F02708C AFA00060 */   sw    $zero, 0x60($sp)
/* 05BBC0 7F027090 0002C080 */  sll   $t8, $v0, 2
/* 05BBC4 7F027094 3C198008 */  lui   $t9, %hi(g_playerPointers)
/* 05BBC8 7F027098 0338C821 */  addu  $t9, $t9, $t8
/* 05BBCC 7F02709C 8F399EE0 */  lw    $t9, %lo(g_playerPointers)($t9)
/* 05BBD0 7F0270A0 8FA30060 */  lw    $v1, 0x60($sp)
/* 05BBD4 7F0270A4 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 05BBD8 7F0270A8 55000071 */  bnezl $t0, .L7F027270
/* 05BBDC 7F0270AC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 05BBE0 7F0270B0 8FA90068 */  lw    $t1, 0x68($sp)
.L7F0270B4:
/* 05BBE4 7F0270B4 24010006 */  li    $at, 6
/* 05BBE8 7F0270B8 8FB90068 */  lw    $t9, 0x68($sp)
/* 05BBEC 7F0270BC 8D2A0018 */  lw    $t2, 0x18($t1)
/* 05BBF0 7F0270C0 914B0000 */  lbu   $t3, ($t2)
/* 05BBF4 7F0270C4 5561001D */  bnel  $t3, $at, .L7F02713C
/* 05BBF8 7F0270C8 8328000F */   lb    $t0, 0xf($t9)
/* 05BBFC 7F0270CC 0FC26919 */  jal   getPlayerCount
/* 05BC00 7F0270D0 AFA30060 */   sw    $v1, 0x60($sp)
/* 05BC04 7F0270D4 24010001 */  li    $at, 1
/* 05BC08 7F0270D8 1441000D */  bne   $v0, $at, .L7F027110
/* 05BC0C 7F0270DC 8FA30060 */   lw    $v1, 0x60($sp)
/* 05BC10 7F0270E0 8FAC0068 */  lw    $t4, 0x68($sp)
/* 05BC14 7F0270E4 3C0F8004 */  lui   $t7, %hi(c_item_entries+16)
/* 05BC18 7F0270E8 818D000F */  lb    $t5, 0xf($t4)
/* 05BC1C 7F0270EC 000D7080 */  sll   $t6, $t5, 2
/* 05BC20 7F0270F0 01CD7021 */  addu  $t6, $t6, $t5
/* 05BC24 7F0270F4 000E7080 */  sll   $t6, $t6, 2
/* 05BC28 7F0270F8 01EE7821 */  addu  $t7, $t7, $t6
/* 05BC2C 7F0270FC 91EFDE20 */  lbu   $t7, %lo(c_item_entries+16)($t7)
/* 05BC30 7F027100 11E00017 */  beqz  $t7, .L7F027160
/* 05BC34 7F027104 00000000 */   nop   
/* 05BC38 7F027108 10000015 */  b     .L7F027160
/* 05BC3C 7F02710C 24030001 */   li    $v1, 1
.L7F027110:
/* 05BC40 7F027110 8FB80068 */  lw    $t8, 0x68($sp)
/* 05BC44 7F027114 8F040018 */  lw    $a0, 0x18($t8)
/* 05BC48 7F027118 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 05BC4C 7F02711C AFA30060 */   sw    $v1, 0x60($sp)
/* 05BC50 7F027120 0FC040C3 */  jal   get_player_mp_char_gender
/* 05BC54 7F027124 00402025 */   move  $a0, $v0
/* 05BC58 7F027128 1040000D */  beqz  $v0, .L7F027160
/* 05BC5C 7F02712C 8FA30060 */   lw    $v1, 0x60($sp)
/* 05BC60 7F027130 1000000B */  b     .L7F027160
/* 05BC64 7F027134 24030001 */   li    $v1, 1
/* 05BC68 7F027138 8328000F */  lb    $t0, 0xf($t9)
.L7F02713C:
/* 05BC6C 7F02713C 3C0A8004 */  lui   $t2, %hi(c_item_entries+16)
/* 05BC70 7F027140 00084880 */  sll   $t1, $t0, 2
/* 05BC74 7F027144 01284821 */  addu  $t1, $t1, $t0
/* 05BC78 7F027148 00094880 */  sll   $t1, $t1, 2
/* 05BC7C 7F02714C 01495021 */  addu  $t2, $t2, $t1
/* 05BC80 7F027150 914ADE20 */  lbu   $t2, %lo(c_item_entries+16)($t2)
/* 05BC84 7F027154 11400002 */  beqz  $t2, .L7F027160
/* 05BC88 7F027158 00000000 */   nop   
/* 05BC8C 7F02715C 24030001 */  li    $v1, 1
.L7F027160:
/* 05BC90 7F027160 10600025 */  beqz  $v1, .L7F0271F8
/* 05BC94 7F027164 3C088003 */   lui   $t0, %hi(female_guard_yelps) 
/* 05BC98 7F027168 3C0B8003 */  lui   $t3, %hi(male_guard_yelps) 
/* 05BC9C 7F02716C 27A20028 */  addiu $v0, $sp, 0x28
/* 05BCA0 7F027170 256B09F8 */  addiu $t3, %lo(male_guard_yelps) # addiu $t3, $t3, 0x9f8
/* 05BCA4 7F027174 256D0030 */  addiu $t5, $t3, 0x30
/* 05BCA8 7F027178 00407025 */  move  $t6, $v0
.L7F02717C:
/* 05BCAC 7F02717C 8D610000 */  lw    $at, ($t3)
/* 05BCB0 7F027180 256B000C */  addiu $t3, $t3, 0xc
/* 05BCB4 7F027184 25CE000C */  addiu $t6, $t6, 0xc
/* 05BCB8 7F027188 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 05BCBC 7F02718C 8D61FFF8 */  lw    $at, -8($t3)
/* 05BCC0 7F027190 ADC1FFF8 */  sw    $at, -8($t6)
/* 05BCC4 7F027194 8D61FFFC */  lw    $at, -4($t3)
/* 05BCC8 7F027198 156DFFF8 */  bne   $t3, $t5, .L7F02717C
/* 05BCCC 7F02719C ADC1FFFC */   sw    $at, -4($t6)
/* 05BCD0 7F0271A0 95610000 */  lhu   $at, ($t3)
/* 05BCD4 7F0271A4 3C0F8003 */  lui   $t7, %hi(male_guard_yelp_counter) 
/* 05BCD8 7F0271A8 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 05BCDC 7F0271AC A5C10000 */  sh    $at, ($t6)
/* 05BCE0 7F0271B0 8DEF0A34 */  lw    $t7, %lo(male_guard_yelp_counter)($t7)
/* 05BCE4 7F0271B4 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 05BCE8 7F0271B8 00003025 */  move  $a2, $zero
/* 05BCEC 7F0271BC 000FC040 */  sll   $t8, $t7, 1
/* 05BCF0 7F0271C0 0058C821 */  addu  $t9, $v0, $t8
/* 05BCF4 7F0271C4 0C002382 */  jal   sndPlaySfx
/* 05BCF8 7F0271C8 87250000 */   lh    $a1, ($t9)
/* 05BCFC 7F0271CC 3C038003 */  lui   $v1, %hi(male_guard_yelp_counter)
/* 05BD00 7F0271D0 8C630A34 */  lw    $v1, %lo(male_guard_yelp_counter)($v1)
/* 05BD04 7F0271D4 3C018003 */  lui   $at, %hi(male_guard_yelp_counter)
/* 05BD08 7F0271D8 00402025 */  move  $a0, $v0
/* 05BD0C 7F0271DC 24630001 */  addiu $v1, $v1, 1
/* 05BD10 7F0271E0 AC230A34 */  sw    $v1, %lo(male_guard_yelp_counter)($at)
/* 05BD14 7F0271E4 28610019 */  slti  $at, $v1, 0x19
/* 05BD18 7F0271E8 1420001C */  bnez  $at, .L7F02725C
/* 05BD1C 7F0271EC 3C018003 */   lui   $at, %hi(male_guard_yelp_counter)
/* 05BD20 7F0271F0 1000001A */  b     .L7F02725C
/* 05BD24 7F0271F4 AC200A34 */   sw    $zero, %lo(male_guard_yelp_counter)($at)
.L7F0271F8:
/* 05BD28 7F0271F8 25080A2C */  addiu $t0, %lo(female_guard_yelps) # addiu $t0, $t0, 0xa2c
/* 05BD2C 7F0271FC 8D010000 */  lw    $at, ($t0)
/* 05BD30 7F027200 27A20020 */  addiu $v0, $sp, 0x20
/* 05BD34 7F027204 3C0D8003 */  lui   $t5, %hi(female_guard_yelp_counter) 
/* 05BD38 7F027208 AC410000 */  sw    $at, ($v0)
/* 05BD3C 7F02720C 95010004 */  lhu   $at, 4($t0)
/* 05BD40 7F027210 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 05BD44 7F027214 00003025 */  move  $a2, $zero
/* 05BD48 7F027218 A4410004 */  sh    $at, 4($v0)
/* 05BD4C 7F02721C 8DAD0A38 */  lw    $t5, %lo(female_guard_yelp_counter)($t5)
/* 05BD50 7F027220 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 05BD54 7F027224 000D5840 */  sll   $t3, $t5, 1
/* 05BD58 7F027228 004B7021 */  addu  $t6, $v0, $t3
/* 05BD5C 7F02722C 0C002382 */  jal   sndPlaySfx
/* 05BD60 7F027230 85C50000 */   lh    $a1, ($t6)
/* 05BD64 7F027234 3C038003 */  lui   $v1, %hi(female_guard_yelp_counter)
/* 05BD68 7F027238 8C630A38 */  lw    $v1, %lo(female_guard_yelp_counter)($v1)
/* 05BD6C 7F02723C 3C018003 */  lui   $at, %hi(female_guard_yelp_counter)
/* 05BD70 7F027240 00402025 */  move  $a0, $v0
/* 05BD74 7F027244 24630001 */  addiu $v1, $v1, 1
/* 05BD78 7F027248 AC230A38 */  sw    $v1, %lo(female_guard_yelp_counter)($at)
/* 05BD7C 7F02724C 28610003 */  slti  $at, $v1, 3
/* 05BD80 7F027250 14200002 */  bnez  $at, .L7F02725C
/* 05BD84 7F027254 3C018003 */   lui   $at, %hi(female_guard_yelp_counter)
/* 05BD88 7F027258 AC200A38 */  sw    $zero, %lo(female_guard_yelp_counter)($at)
.L7F02725C:
/* 05BD8C 7F02725C 8FAF0068 */  lw    $t7, 0x68($sp)
/* 05BD90 7F027260 8DE50018 */  lw    $a1, 0x18($t7)
/* 05BD94 7F027264 0FC14E84 */  jal   sub_GAME_7F053A10
/* 05BD98 7F027268 24A50008 */   addiu $a1, $a1, 8
/* 05BD9C 7F02726C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F027270:
/* 05BDA0 7F027270 27BD0068 */  addiu $sp, $sp, 0x68
/* 05BDA4 7F027274 03E00008 */  jr    $ra
/* 05BDA8 7F027278 00000000 */   nop   
)
#endif



/**
 * Address 0x7F02727C.
*/
bool handles_shot_actors(ChrRecord *self, s32 hitpart, coord3d *vector, s32 weaponid, bool isPlayer)
{
    s32 hattype;                     //sp78
    PropRecord *myprop = self->prop; //sp60
    s32 padd;

    // Handle hat shots.
    if (hitpart == HIT_HAT && self->handle_positiondata_hat)
    {
        hattype = get_hat_model(self->handle_positiondata_hat);

        if (hattype == HATTYPE_MOON) //moon - count as head hit
        {
            hitpart = HIT_HEAD;
        }
        else if (hattype != HATTYPE_HELMATE) //normal hats - knock off
        {
            propobjSetDropped(self->handle_positiondata_hat, 4); //propobjSetDropped
            self->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;           //drop hat
        }
        else //steel helmate - ricochet
        {
            s16 mrs[3] = metal_ricochet_SFX;
            ALSoundState * p = sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, mrs[randomGetNext() % 3U], NULL);
            sub_GAME_7F053A10(p, &self->prop->pos);
        }
    }

    // Handle incrementing player shot count
    if (isPlayer && hitpart)
    {
        switch (hitpart)
        {
            case HIT_HEAD:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOT_REGISTER_HEAD);
                break;
            }
            case HIT_GUN:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOT_REGISTER_GUN);
                break;
            }
            case HIT_HAT:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOT_REGISTER_HAT);
                break;
            }
            case HIT_CHEST:
            case HIT_PELVIS:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOT_REGISTER_BODY);
                break;
            }
            default:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOT_REGISTER_LIMB);
                break;
            }
        }
    }

    self->numarghs++;
    self->chrflags |= CHRFLAG_WAS_HIT;

    // If the chr is invincible, make them flinch then we're done
    if (self->chrflags & CHRFLAG_INVINCIBLE)
    {
        chrSetHiddenToRandom(self); //chrFlinchBody
        return FALSE;
    }

    // If chr is dying or already dead then we're done
    if ((self->actiontype != ACT_DIE) && (self->actiontype != ACT_DEAD))
    {
        vec3d vec;           
        f32   angle;         
        f32   damageToCause; 
        s32   playerNum;     

        damageToCause = bondwalkItemGetDestructionAmount(weaponid);

        if (isPlayer && (getPlayerCount() == 1))
        {
            damageToCause *= g_AiHealthModifier;
        }

        vec.x = myprop->pos.x - vector->x;
        vec.y = myprop->pos.y - vector->y;
        vec.z = myprop->pos.z - vector->z;
        angle = get_distance_actor_to_position(self, &vec); //chrGetAngleToPos

        if (hitpart == HIT_GENERAL)
        {
            // Halve the damage because it's doubled for torso below
            hitpart = HIT_CHEST;
            damageToCause *= 0.5f;
        }
        else if (hitpart == HIT_GENERALHALF)
        {
            // Likewise, quarter it here so it becomes half below
            hitpart = HIT_CHEST;
            damageToCause *= 0.25f;
        }

        if (weaponid == ITEM_FIST)
        {
            if ((self->actiontype != ACT_STAND) &&
                (self->actiontype != ACT_PATROL) &&
                (self->actiontype != ACT_SURRENDER) &&
                (self->actiontype != ACT_ANIM) &&
                ((self->actiontype != ACT_GOPOS) || self->act_gopos.unk59))
            {
                // Punching and pistol whipping is less effective from the front
                if ((angle < DegToRad(60.0)) || (angle > DegToRad(300.0)))
                {
                    damageToCause *= 0.125f;
                }
                else if ((angle < DegToRad(180.0 - 60.0)) || (angle > DegToRad(180.0 + 60.0)))
                {
                    damageToCause *= 0.25f;
                }
                else
                {
                    damageToCause *= 0.5f;
                }
            }
        }

        // Apply damage multipliers based on which body parts were hit,
        // and flinch head if shot in the head - PD Only
        if (hitpart == HIT_HEAD)
        {
            damageToCause *= 4.0f;
        }
        else if (hitpart == HIT_CHEST)
        {
            damageToCause *= 2.0f;
        }
        else if (hitpart == HIT_GUN)
        {
            damageToCause = 0.0f;
        }
        else if (hitpart == HIT_HAT)
        {
            damageToCause = 0.0f;
        }

        if (self->prop->type == PROP_TYPE_VIEWER)
        {
            playerNum = get_cur_playernum();
            set_cur_player(sub_GAME_7F09B15C(self->prop));
            record_damage_kills(damageToCause * 0.125f, vector->x, vector->z, playerNum, 1);
            set_cur_player(playerNum);
        }
        else
        {
            self->chrflags |= CHRFLAG_WAS_DAMAGED;
#    ifdef XBLA
            if (!cheatIsActive(76))
#    endif
                self->damage += damageToCause;

            if (self->damage < 0.0f)
            {
                f32 endframe = -1.0f; //sp34
                if (!chrlvAttackAnimationRelated7F026F30(self, &endframe))
                {
                    chrSetHiddenToRandom(self);
                    return FALSE;
                }
            }
        }

        if (hitpart != HIT_HAT)
        {
            // Cancel current animation and prepare for argh
            f32 endframe2 = -1.0f; //sp30
            play_sound_for_shot_actor(self);

            if (chrlvAttackAnimationRelated7F026F30(self, &endframe2)) //chrIsAnimPreventingArgh
            {
                if (endframe2 >= 0.0f)
                {
                    modelSetAnimEndFrame(self->model, endframe2); //modelSetAnimEndFrame
                }

                self->actiontype         = ACT_PREARGH;
                self->act_preargh.pos.x  = vector->x;
                self->act_preargh.pos.y  = vector->y;
                self->act_preargh.pos.z  = vector->z;
                self->act_preargh.unk038 = angle;
                self->act_preargh.unk03c = hitpart;
                self->act_preargh.unk040 = weaponid;
                self->sleep              = 0;
            }
            else
            {
                triggered_on_shot_hit(self, vector, angle, hitpart, weaponid);
            }
        }
    }

    return TRUE;
}




/**
 * Address 0x7F027804.
*/
s32 chrlvExplosionDamage(ChrRecord *self, coord3d *arg1, f32 damage, s32 arg3)
{
    Model *self_model; // 84
    PropRecord *self_prop; // 80
    f32 subroty; // 76
    f32 atan; // 72
    f32 norm; // any
    s32 sp40; // 64
    f32 phi_f12; // any
    struct explosion_death_animation *sp38; // 56
    coord3d sp2C; // 44
    s32 t;

    self_model = self->model;
    self_prop = self->prop;

    if ((self->actiontype == ACT_DEAD) || (self->actiontype == ACT_DIE))
    {
        return 0;
    }

    self->chrflags |= CHRFLAG_WAS_HIT;
    if (self->chrflags & CHRFLAG_INVINCIBLE)
    {
        return 0;
    }

    self->numarghs += 1;
    self->damage += damage;
    self->chrflags |= CHRFLAG_WAS_DAMAGED;

    if (self->damage > 0.0f)
    {
        self->damage = self->maxdamage;

        subroty = getsubroty(self_model);

        atan = atan2f(self_prop->pos.f[0] - arg1->f[0], self_prop->pos.f[2] - arg1->f[2]);

        sp2C.f[0] = self_prop->pos.f[0] - arg1->f[0];
        sp2C.f[1] = self_prop->pos.f[1] - arg1->f[1];
        sp2C.f[2] = self_prop->pos.f[2] - arg1->f[2];

        // avoid divide by zero
        if ((sp2C.f[0] == 0.0f) && (sp2C.f[1] == 0.0f) && (sp2C.f[2] == 0.0f))
        {
            sp2C.f[2] = 1.0f;
        }

        norm = (5.0f * damage) / sqrtf(((sp2C.f[0] * sp2C.f[0]) + (sp2C.f[1] * sp2C.f[1])) + (sp2C.f[2] * sp2C.f[2]));
        phi_f12 = atan - subroty;

        sp2C.f[0] *= norm;
        sp2C.f[1] *= norm;
        sp2C.f[2] *= norm;

        self->fallspeed.f[0] = sp2C.f[0];
        self->fallspeed.f[1] = sp2C.f[1];
        self->fallspeed.f[2] = sp2C.f[2];

        if (atan < subroty)
        {
            phi_f12 += M_TAU_F;
        }

        sp40 = (s32) (((phi_f12 * 8.0f) / M_TAU_F) + 0.5f);

        if (sp40 >= EXPLOSION_ANIMATION_TABLE_LEN)
        {
            sp40 = 0;
        }

        t = (u32)randomGetNext() % (u32) explosion_animation_table[sp40].count;
        sp38 = &D_8002E648[
            explosion_animation_table[sp40].table[t]
            ];
        
        sub_GAME_7F02D184(self);
        
        self->actiontype = ACT_DIE;
        self->act_die.notifychrindex = 0;
        self->act_die.thudframe1 = sp38->anonymous_5;
        self->sleep = 0;
        self->act_die.thudframe2 = -1.0f;
        self->act_die.timeextra = 0.0f;

        modelSetAnimation(
            self_model,
            (struct ModelAnimation *) ((s32)sp38->anonymous_0 + (s32)&ptr_animation_table->data),
            sp38->anonymous_1,
            sp38->anonymous_3,
            sp38->anonymous_2,
            8.0f);
        
        if (sp38->anonymous_6 >= 0.0f)
        {
            modelSetAnimEndFrame(self_model, sp38->anonymous_6);
        }

        if (arg3 != 0)
        {
            play_sound_for_shot_actor(self);
        }

        chrDropItems(self);
        increment_num_kills_display_text_in_MP();

        if (self->chrflags & CHRFLAG_COUNT_DEATH_AS_CIVILIAN)
        {
            inc_cur_civilian_casualties();
        }

        if ((self->weapons_held[GUNRIGHT] != NULL) && ((self->weapons_held[GUNRIGHT]->obj->flags & 0x2000) == 0))
        {
            propobjSetDropped(self->weapons_held[GUNRIGHT], 1);
            self->hidden |= 1;
        }

        if ((self->weapons_held[GUNLEFT] != NULL) && ((self->weapons_held[GUNLEFT]->obj->flags & 0x2000) == 0))
        {
            propobjSetDropped(self->weapons_held[GUNLEFT], 1);
            self->hidden |= 1;
        }

        return 1;
    }

    return 0;
}



#ifdef NONMATCHING
/**
 * Address 0x7F027BF4.
*/
waypoint *get_ptrpreset_in_table_matching_tile(StandTile* stan)
{
    waypoint  *waypoint;
    PadRecord *pad;

    if (g_chraiCurrentSetup.pathwaypoints != NULL)
    {
        for (waypoint = g_chraiCurrentSetup.pathwaypoints; waypoint->padID >= 0; waypoint++)
        {
            pad = &((PadRecord *)g_chraiCurrentSetup.pads)[waypoint->padID];

            if (pad->stan == stan)
            {
                return waypoint;
            }
        }
    }

    return NULL;
}
#else
GLOBAL_ASM(
.text
glabel get_ptrpreset_in_table_matching_tile
/* 05C724 7F027BF4 3C028007 */  lui   $v0, %hi(g_chraiCurrentSetup+0)
/* 05C728 7F027BF8 8C425D00 */  lw    $v0, %lo(g_chraiCurrentSetup+0)($v0)
/* 05C72C 7F027BFC 00803025 */  move  $a2, $a0
/* 05C730 7F027C00 50400015 */  beql  $v0, $zero, .L7F027C58
/* 05C734 7F027C04 00001025 */   move  $v0, $zero
/* 05C738 7F027C08 8C4E0000 */  lw    $t6, ($v0)
/* 05C73C 7F027C0C 00401825 */  move  $v1, $v0
/* 05C740 7F027C10 3C058007 */  lui   $a1, %hi(g_chraiCurrentSetup+0x18)
/* 05C744 7F027C14 05C0000F */  bltz  $t6, .L7F027C54
/* 05C748 7F027C18 2407002C */   li    $a3, 44
/* 05C74C 7F027C1C 8C440000 */  lw    $a0, ($v0)
/* 05C750 7F027C20 8CA55D18 */  lw    $a1, %lo(g_chraiCurrentSetup+0x18)($a1)
.L7F027C24:
/* 05C754 7F027C24 00870019 */  multu $a0, $a3
/* 05C758 7F027C28 00007812 */  mflo  $t7
/* 05C75C 7F027C2C 01E51021 */  addu  $v0, $t7, $a1
/* 05C760 7F027C30 8C580028 */  lw    $t8, 0x28($v0)
/* 05C764 7F027C34 54D80004 */  bnel  $a2, $t8, .L7F027C48
/* 05C768 7F027C38 8C640010 */   lw    $a0, 0x10($v1)
/* 05C76C 7F027C3C 03E00008 */  jr    $ra
/* 05C770 7F027C40 00601025 */   move  $v0, $v1

/* 05C774 7F027C44 8C640010 */  lw    $a0, 0x10($v1)
.L7F027C48:
/* 05C778 7F027C48 24630010 */  addiu $v1, $v1, 0x10
/* 05C77C 7F027C4C 0481FFF5 */  bgez  $a0, .L7F027C24
/* 05C780 7F027C50 00000000 */   nop   
.L7F027C54:
/* 05C784 7F027C54 00001025 */  move  $v0, $zero
.L7F027C58:
/* 05C788 7F027C58 03E00008 */  jr    $ra
/* 05C78C 7F027C5C 00000000 */   nop   
)
#endif



/**
 * Address 0x7F027C60.
*/
s32 check_if_any_path_preset_lies_on_tile(StandTile* arg0)
{
    return get_ptrpreset_in_table_matching_tile(arg0) != NULL;
}


/**
 * 100% match, unsure of argument types.
 * Addresss 0x7F027C84.
*/
f32 chrlvPadPresetRelated(coord3d *arg0, waypoint *arg1)
{
    f32 temp_f12;
    f32 temp_f2;
    PadRecord *temp_v0;

    temp_v0 = &g_chraiCurrentSetup.pads[arg1->padID];
    temp_f2 = temp_v0->pos.f[0] - arg0->f[0];
    temp_f12 = temp_v0->pos.f[2] - arg0->f[2];
    return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
}



/**
 * Address 0x7F027CD4.
*/
waypoint *chrlvStanPathRelated(coord3d *arg0, StandTile *arg1)
{
    StandTile *tile = NULL;
    f32 temp_f20;
    waypoint *ret = NULL;
    waypoint *wayp = NULL;
    s32 *n = NULL;
    
    tile = sub_GAME_7F0B2718(arg1, check_if_any_path_preset_lies_on_tile);
    if (tile != NULL)
    {
        ret = get_ptrpreset_in_table_matching_tile(tile);
        
        if (ret != NULL)
        {
            temp_f20 = chrlvPadPresetRelated(arg0, ret);

            for (n = ret->neighbours; *n >= 0; n++)
            {
                wayp = &g_chraiCurrentSetup.pathwaypoints[*n];
                
                if (chrlvPadPresetRelated(arg0, wayp) < temp_f20)
                {
                    ret = wayp;
                }
            }
        }
    }

    return ret;
}




/**
 * Address 0x7F027DB0.
*/
s32 chrlvStanRoomRelated(ChrRecord *self, coord3d *arg1, StandTile *tile)
{

#define BUFFER_SIZE_7F027DB0 0x14

    s32 sp48[BUFFER_SIZE_7F027DB0];
    PropRecord *prop;
    s32 tile_something;
    s32 i;

    prop = self->prop;
    tile_something = sub_GAME_7F0B0D0C(prop->stan, prop->pos.x, prop->pos.f[2], &tile, arg1->f[0], arg1->f[2], &sp48[0], BUFFER_SIZE_7F027DB0);

    if (tile_something > 0 && tile_something < BUFFER_SIZE_7F027DB0)
    {
        for (i=0; i<tile_something; i++)
        {
            if (getROOMID_Bitflags(sp48[i]) != 0)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}



/**
 * Address 0x7F027E70.
*/
s32 chrlvStanRoomRelatedPad(ChrRecord *self, PadRecord *arg1)
{
    return chrlvStanRoomRelated(self, &arg1->pos, arg1->stan);
}




/**
 * Address 0x7F027E90.
*/
void chrlvSetGoposSegDistTotal(ChrRecord *self, struct waydata *arg1, coord3d *arg2)
{
    PropRecord *prop;
    f32 dx;
    f32 dz;
    f32 sp18;

    prop = self->prop;
    dx = arg2->f[0] - prop->pos.f[0];
    dz = arg2->f[2] - prop->pos.f[2];

    sp18 = atan2f(dx, dz);

    arg1->mode = 6;
    arg1->segdistdone = 0.0f;
    arg1->segdisttotal = sqrtf((dx * dx) + (dz * dz));

    setsubroty(self->model, sp18);
}


/**
 * @param self:
 * @param target_point: out paramter, will contain target position
 * @param target_stan: out parameter, will contain pointer to target stan
 * 
 * Address 0x7F027F20.
*/
void chrlvActGoposRelated(ChrRecord *self, coord3d *target_point, StandTile **target_stan)
{
    waypoint *temp_v0;
    PadRecord *temp_v1;

    temp_v0 = self->act_gopos.waypoints[self->act_gopos.curindex];

    if (temp_v0 != 0)
    {
        temp_v1 = &g_chraiCurrentSetup.pads[temp_v0->padID];

        target_point->f[0] = temp_v1->pos.f[0];
        target_point->f[1] = temp_v1->pos.f[1];
        target_point->f[2] = temp_v1->pos.f[2];

        *target_stan = temp_v1->stan;
    }
    else
    {
        target_point->f[0] = self->act_gopos.targetpos.f[0];
        target_point->f[1] = self->act_gopos.targetpos.f[1];
        target_point->f[2] = self->act_gopos.targetpos.f[2];

        *target_stan = self->act_gopos.target;
    }
}



/**
 * Address 0x7F027FA8.
*/
f32 chrlvModelScaleAnimationRelated(ChrRecord *self)
{
    f32 scale_factor = D_80030984;

    if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting])
    {
        scale_factor = D_8003098C;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running])
    {
        scale_factor = D_80030988;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_80030998;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon])
    {
        scale_factor = D_80030994;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed])
    {
        scale_factor = D_80030990;
    }
    // typo/mistake, `ANIM_DATA_sprinting_one_handed_weapon` is duplicate of above.
    // compiler swaps addition order when reading this from the stack, unlike addresses only seen once (seen once means not saved to stack).
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_800309A4;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_female])
    {
        scale_factor = D_800309A0;
    }
    else if ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_female])
    {
        scale_factor = D_8003099C;
    }

    return self->model->scale * scale_factor * 9.999999f;
}





/**
 * Address 0x7F028144.
*/
s32 chrlvMovementTargetRelated(ChrRecord *self)
{
    f32 dx;
    f32 dz;
    PropRecord *temp_v0;
    coord3d sp20; // sp32
    StandTile *sp1C; // 28
    f32 sp18; // 24

    sp18 = modelGetAbsAnimSpeed(self->model);
    chrlvActGoposRelated(self, &sp20, &sp1C);
    temp_v0 = self->prop;
    dx = sp20.f[0] - temp_v0->pos.f[0];
    dz = sp20.f[2] - temp_v0->pos.f[2];

    if (dx < 0.0f)
    {
        dx = -dx;
    }

    if (dz < 0.0f)
    {
        dz = -dz;
    }

    return (s32) ((dx + dz) / (chrlvModelScaleAnimationRelated(self) * sp18));
}



/**
 * Address 0x7F0281F4.
*/
void sub_GAME_7F0281F4(ChrRecord *self)
{
    self->act_gopos.unk5a = 0;
}


/**
 * Address 0x7F0281FC (US,JP)
 * Address 0x7F028214 (VERSION_EU)
*/
void chrlvPlotCourseRelated(ChrRecord *self)
{
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;

    if (self->act_gopos.waydata.mode != WAYMODE_MAGIC)
    {
        temp_v0 = self->act_gopos.unk5a;

        if (temp_v0 == 0)
        {
#ifndef REFRESH_PAL
            temp_a1 = (chrlvMovementTargetRelated(self) * 2) + 300;
#else
            temp_a1 = ((chrlvMovementTargetRelated(self) * 100) + 15000) / 60;
#endif

            if (temp_a1 >= 0x10000)
            {
                temp_a1 = (u16)-1;
            }

            self->act_gopos.unk5a = (s16)temp_a1;

            return;
        }

        temp_v1 = (u16)g_ClockTimer;

        if (temp_v1 >= temp_v0)
        {
            plot_course_for_actor(self, &self->act_gopos.targetpos, self->act_gopos.target, self->act_gopos.unk59);
            
            return;
        }

        self->act_gopos.unk5a = (u16) (temp_v0 - temp_v1);
    }
}



/**
 * Address 0x7F02828C.
*/
void chrlvActGoposSetTargetPosRelated(ChrRecord *self)
{
    coord3d sp1C;
    StandTile *sp18;

    chrlvActGoposRelated(self, (coord3d *) &sp1C, &sp18);

    self->act_gopos.waydata.mode = 0;
    self->act_gopos.waydata.unk01 = 0;
    self->act_gopos.waydata.unk02 = 0;

    self->act_gopos.waydata.pos.f[0] = sp1C.f[0];
    self->act_gopos.waydata.pos.f[1] = sp1C.f[1];
    self->act_gopos.waydata.pos.f[2] = sp1C.f[2];

    sub_GAME_7F0281F4(self);
}



/**
 * Address 0x7F0282E0.
*/
void chrlvActGoposIncCurIndex(ChrRecord *self)
{
    if (self->act_gopos.curindex < 3)
    {
        self->act_gopos.curindex++;
    }
    else
    {
        waypoint * p = self->act_gopos.waypoints[self->act_gopos.curindex];

        self->act_gopos.curindex = 1;

        waypointFindRoute(p, self->act_gopos.target_path, (waypoint **)&self->act_gopos.waypoints, MAX_CHRWAYPOINTS);
    }

    chrlvActGoposSetTargetPosRelated(self);
}



/**
 * Determines which step index the chr will be at given their current index, the
 * number of steps to take and in which direction (forward or back).
 *
 * Returns the step index and populates *forward with true or false depending on
 * whether the chr will be traversing the path in the forward direction at that
 * point.
 * 
 * Address 0x7F028348.
 *
 * PD: chrPatrolCalculateStep
 */
s32 chrlvPatrolCalculateStep(ChrRecord *self, bool *forward, s32 numsteps)
{
    s32 nextstep = self->act_patrol.nextstep;
    bool isforward = *forward;

    if (numsteps < 0)
    {
        isforward = !isforward;
        numsteps = -numsteps;
    }

    while (numsteps > 0)
    {
        numsteps--;

        if (isforward)
        {
            nextstep++;

            if (self->act_patrol.path->data[nextstep] < 0)
            {
                nextstep -= 2;

                // Reached the end of the list
                if (self->act_patrol.path->flags & 1)
                {
                    nextstep = 0;
                }
                else
                {
                    isforward = FALSE;
                }
            }
        }
        else
        {
            nextstep--;

            if (nextstep < 0)
            {
                nextstep = 1;

                // Reached the start of the list
                if (self->act_patrol.path->flags & 1)
                {
                    nextstep = self->act_patrol.path->len - 1;
                }
                else
                {
                    isforward = TRUE;
                }
            }
        }
    }

    *forward = isforward;

    return nextstep;
}




#ifdef NONMATCHING

// notes: struct SetupPtrs isn't (currently defined), it's theoretical update
// to struct stagesetup. Requires AI Branch merge first.

/**
 * Address 0x7F0283FC.
*/
PadRecord * chrlvGetPatrolStepPad(ChrRecord *self, s32 arg1)
{
    //struct patrol_path *path;
    s32 forward;
    s32 step;
    //s32 nextstep;

    forward = self->act_patrol.forward;

    step = chrlvPatrolCalculateStep(self, &forward, arg1);

    //path = self->act_patrol.path;

    step = self->act_patrol.path->data[step];

     return &((struct SetupPtrs *)&g_chraiCurrentSetup.pathwaypoints)->pads[
         ((struct SetupPtrs *)&g_chraiCurrentSetup.pathwaypoints)->pathwaypoints[step].padID
         ];
}

#else
GLOBAL_ASM(
.text
glabel chrlvGetPatrolStepPad
/* 05CF2C 7F0283FC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05CF30 7F028400 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05CF34 7F028404 8C8E0034 */  lw    $t6, 0x34($a0)
/* 05CF38 7F028408 00A03025 */  move  $a2, $a1
/* 05CF3C 7F02840C 27A50020 */  addiu $a1, $sp, 0x20
/* 05CF40 7F028410 AFA40028 */  sw    $a0, 0x28($sp)
/* 05CF44 7F028414 0FC0A0D2 */  jal   chrlvPatrolCalculateStep
/* 05CF48 7F028418 AFAE0020 */   sw    $t6, 0x20($sp)
/* 05CF4C 7F02841C 8FA70028 */  lw    $a3, 0x28($sp)
/* 05CF50 7F028420 0002C880 */  sll   $t9, $v0, 2
/* 05CF54 7F028424 3C058007 */  lui   $a1, %hi(g_chraiCurrentSetup+0)
/* 05CF58 7F028428 8CEF002C */  lw    $t7, 0x2c($a3)
/* 05CF5C 7F02842C 24A55D00 */  addiu $a1, %lo(g_chraiCurrentSetup+0) # addiu $a1, $a1, 0x5d00
/* 05CF60 7F028430 8CAA0000 */  lw    $t2, ($a1)
/* 05CF64 7F028434 8DF80000 */  lw    $t8, ($t7)
/* 05CF68 7F028438 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05CF6C 7F02843C 8CAD0018 */  lw    $t5, 0x18($a1)
/* 05CF70 7F028440 03191821 */  addu  $v1, $t8, $t9
/* 05CF74 7F028444 8C680000 */  lw    $t0, ($v1)
/* 05CF78 7F028448 00084900 */  sll   $t1, $t0, 4
/* 05CF7C 7F02844C 012A2021 */  addu  $a0, $t1, $t2
/* 05CF80 7F028450 8C8B0000 */  lw    $t3, ($a0)
/* 05CF84 7F028454 27BD0028 */  addiu $sp, $sp, 0x28
/* 05CF88 7F028458 000B6080 */  sll   $t4, $t3, 2
/* 05CF8C 7F02845C 018B6023 */  subu  $t4, $t4, $t3
/* 05CF90 7F028460 000C6080 */  sll   $t4, $t4, 2
/* 05CF94 7F028464 018B6023 */  subu  $t4, $t4, $t3
/* 05CF98 7F028468 000C6080 */  sll   $t4, $t4, 2
/* 05CF9C 7F02846C 03E00008 */  jr    $ra
/* 05CFA0 7F028470 018D1021 */   addu  $v0, $t4, $t5
)
#endif



/**
 * Unknown return type.
 * 
 * Address 0x7F028474.
*/
PadRecord * chrlvGetNextPatrolStepPad(ChrRecord *self)
{
    return chrlvGetPatrolStepPad(self, 0);
}


/**
 * Address 0x7F028494.
*/
void chrlvSetNextActPatrolStepPadPos(ChrRecord *self)
{
    PadRecord *temp_v0;

    temp_v0 = chrlvGetNextPatrolStepPad(self);
    self->act_patrol.waydata.mode = 0;
    self->act_patrol.waydata.unk01 = 0;
    self->act_patrol.waydata.unk02 = 0;
    self->act_patrol.waydata.pos.f[0] = temp_v0->pos.f[0];
    self->act_patrol.waydata.pos.f[1] = temp_v0->pos.f[1];
    self->act_patrol.waydata.pos.f[2] = temp_v0->pos.f[2];
}




/**
 * Address 0x7F0284DC.
*/
void sub_GAME_7F0284DC(ChrRecord *self)
{
    self->act_patrol.nextstep = chrlvPatrolCalculateStep(self, &self->act_patrol.forward, 1);
    chrlvSetNextActPatrolStepPadPos(self);
}



/**
 * Address 0x7F028510.
*/
s32 sub_GAME_7F028510(coord3d *arg0, StandTile *arg1)
{
    s32 roomids[8];
    s16 *temp_s0;
    PropRecord *propss = (PropRecord *)&pos_data_entry;
    struct rect4f *prect4f; // 68
    s32 sp40;
    
    roomids[0] = arg1->room;
    roomids[1] = -1;
    sub_GAME_7F03E3FC((s32*)&roomids);
    
    for (temp_s0 = ptr_list_object_lookup_indices; *temp_s0 >= 0; temp_s0++)
    {
        PropRecord *prop = &propss[*temp_s0];

        if (prop->type == PROP_TYPE_OBJ)
        {
            chraiGetCollisionBoundsWithoutY(prop, &prect4f, &sp40);

            if ((sp40 > 0) && chrpropTestPointInPolygon(arg0, prect4f, sp40))
            {
                return 0;
            }
        }
    }

    return 1;
}







/**
 * contrast with @see chrlvTravelTick
 * Address 0x7F028600.
*/
void chrlvTravelTickMagic(ChrRecord *self, struct waydata *arg1, f32 arg2, coord3d *arg3, StandTile *arg4)
{
    /**
     * Three unused stack variables.
    */
    //
    PropRecord *self_prop;
    s32 unused1;
    s32 unused2;
    s32 unused3;
    u8 curindex;
    waypoint *pta;
    PadRecord *pad;
    coord3d sp40;
    StandTile *sp3C;

    self->invalidmove = 0;
    self->lastmoveok60 = g_GlobalTimer;
    arg1->segdistdone += arg2 * modelGetAbsAnimSpeed(self->model) * g_GlobalTimerDelta;
    
    if (arg1->segdisttotal <= arg1->segdistdone)
    {
        set_or_unset_GUARDdata_flag(self, 0);
        
        if (
            (sub_GAME_7F0B18B8(&arg4, arg3->f[0], arg3->f[2], self->chrwidth, 0x1F, 0.0f, 1.0f) < 0)
            && sub_GAME_7F028510(arg3, arg4))
        {
            self_prop = self->prop;
            self_prop->stan = arg4;
            self_prop->pos.f[0] = arg3->f[0];
            self_prop->pos.f[1] = arg3->f[1];
            self_prop->pos.f[2] = arg3->f[2];
            self->chrflags |= CHRFLAG_INIT;
            
            setsuboffset(self->model, arg3);
            sub_GAME_7F01FC10(self->model, &self_prop->pos, &self_prop->pos, &self->ground);
            chrPositionRelated7F020D94(self);

            if (self->actiontype == ACT_PATROL)
            {
                sub_GAME_7F0284DC(self);
                chrlvSetGoposSegDistTotal(self, arg1, chrlvGetNextPatrolStepPad(self));
            }
            else if (self->actiontype == ACT_GOPOS)
            {
                curindex = self->act_gopos.curindex;
                
                if (self->act_gopos.waypoints[curindex] == NULL)
                {
                    if (curindex > 0)
                    {
                        pta = self->act_gopos.waypoints[curindex - 1];
                        pad = &g_chraiCurrentSetup.pads[pta->padID];

                        setsubroty(
                            self->model,
                            atan2f(self_prop->pos.f[0] - pad->pos.f[0], self_prop->pos.f[2] - pad->pos.f[2]));
                    }

                    chrlvKneelingAnimationRelated7F023E48(self);
                }
                else
                {
                    chrlvActGoposIncCurIndex(self);
                    chrlvActGoposRelated(self, &sp40, &sp3C);
                    chrlvSetGoposSegDistTotal(self, arg1, &sp40);
                }
            }
        }
        else
        {
            arg1->segdistdone = arg1->segdisttotal;

            if (self->actiontype == ACT_PATROL)
            {
                self->act_patrol.lastvisible60 = g_GlobalTimer;
                chrlvSetNextActPatrolStepPadPos(self);
            }
            else
            {
                self->act_gopos.unk9c = g_GlobalTimer;
                chrlvActGoposSetTargetPosRelated(self);
            }
        }

        set_or_unset_GUARDdata_flag(self, 1);
    }
}


/**
 * Gets character segment percent completed.
 * If action type is ACT_PATROL, computes distance between chr and target pad.
 * If action type is ACT_GOPOS, computes distance between chr and target position.
 * Otherwise result is chr->prop position.
 * 
 * @param self:
 * @param arg1: Out parameter. Contains result.
 * 
 * Address 0x7F028894.
 * PD: chrCalculatePosition.
*/
void chrlvGetPatrolPercentOrPosition(ChrRecord *self, coord3d *arg1)
{
    PadRecord *pad;
    f32 percent;
    coord3d sp2C; // 44
    StandTile *stan;

    if ((self->actiontype == ACT_PATROL) && (self->act_patrol.waydata.mode == WAYMODE_MAGIC))
    {
        pad = chrlvGetNextPatrolStepPad(self);

        if (self->act_patrol.waydata.segdisttotal <= self->act_patrol.waydata.segdistdone)
        {
            arg1->f[0] = pad->pos.f[0];
            arg1->f[1] = pad->pos.f[1];
            arg1->f[2] = pad->pos.f[2];

            return;
        }

        percent = self->act_patrol.waydata.segdistdone / self->act_patrol.waydata.segdisttotal;

        arg1->f[0] = self->prop->pos.f[0] + ((pad->pos.f[0] - self->prop->pos.f[0]) * percent);
        arg1->f[1] = self->prop->pos.f[1] + ((pad->pos.f[1] - self->prop->pos.f[1]) * percent);
        arg1->f[2] = self->prop->pos.f[2] + ((pad->pos.f[2] - self->prop->pos.f[2]) * percent);

        return;
    }
    
    if ((self->actiontype == ACT_GOPOS) && (self->act_gopos.waydata.mode == WAYMODE_MAGIC))
    {
        chrlvActGoposRelated(self, &sp2C, &stan);

        if (self->act_gopos.waydata.segdisttotal <= self->act_gopos.waydata.segdistdone)
        {
            arg1->f[0] = sp2C.f[0];
            arg1->f[1] = sp2C.f[1];
            arg1->f[2] = sp2C.f[2];

            return;
        }

        percent = self->act_gopos.waydata.segdistdone / self->act_gopos.waydata.segdisttotal;

        arg1->f[0] = self->prop->pos.f[0] + ((sp2C.f[0] - self->prop->pos.f[0]) * percent);
        arg1->f[1] = self->prop->pos.f[1] + ((sp2C.f[1] - self->prop->pos.f[1]) * percent);
        arg1->f[2] = self->prop->pos.f[2] + ((sp2C.f[2] - self->prop->pos.f[2]) * percent);

        return;
    }

    arg1->f[0] = self->prop->pos.f[0];
    arg1->f[1] = self->prop->pos.f[1];
    arg1->f[2] = self->prop->pos.f[2];
}



/**
 * @param self:
 * @param arg1: sprinting animation when 2, running animation when 1, otherwise walking animation
 * @param arg2:
 * 
 * Address 0x7F028A5C.
*/
void get_sound_at_range(ChrRecord *self, s32 arg1, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 ani_arg;
    s32 flag;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        flag = 0;
        ani_arg = randomGetNext() & 1;
    }
    else
    {
        s32 t;
        if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
        {
            t = 0;
            flag = t;
            ani_arg = (s32)left != 0;
        }
        else
        {
            t = 1;
            flag = t;
            ani_arg = (s32)left != 0;
        }
    }

    if (flag != 0)
    {
        if (arg1 == 2)
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else if (arg1 == 1)
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_running], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_walking], ani_arg, 0.0f, 0.5f, 16.0f);
        }

        return;
    }

    if (arg2)
    {
        if (arg1 == 2)
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else if (arg1 == 1)
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else
        {
            modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed], ani_arg, 0.0f, 0.5f, 16.0f);
        }

        return;
    }

    if (arg1 == 2)
    {
        modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else if (arg1 == 1)
    {
        modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_running_female], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else
    {
        modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_female], ani_arg, 0.0f, 0.5f, 16.0f);
    }

    return;
}



/**
 * Address 0x7F028DA0.
*/
void play_hit_soundeffect_and_proper_volume( ChrRecord *self)
{
    get_sound_at_range(self, self->act_ubytes.padding[45], c_item_entries[self->bodynum].isMale);
}




/**
 * Address 0x7F028DDC.
*/
s32 plot_course_for_actor(ChrRecord *self, coord3d *arg1, StandTile *stan, SPEED speed)
{
    PropRecord *prop; //sp 100
    waypoint *prop_waypoint; // sp96
    waypoint *target_waypoint; // sp92
    waypoint *sp44[MAX_CHRWAYPOINTS];
    s32 i;
    coord3d sp34;
    StandTile *sp30;
    s32 phi_v0;

    prop = self->prop;

    phi_v0 = (self->actiontype == ACT_GOPOS) && (self->act_gopos.unk59 == (u8)speed);

    prop_waypoint = chrlvStanPathRelated(&prop->pos, prop->stan);
    target_waypoint = chrlvStanPathRelated(arg1, stan);

    if ((prop_waypoint != NULL) 
        && (target_waypoint != NULL) 
        && !(waypointFindRoute(prop_waypoint, target_waypoint, (waypoint **)&sp44, MAX_CHRWAYPOINTS) < 2)
    )
    {
        sub_GAME_7F02D184(self);

        self->actiontype = ACT_GOPOS;

        self->act_gopos.targetpos.f[0] = arg1->f[0];
        self->act_gopos.targetpos.f[1] = arg1->f[1];
        self->act_gopos.targetpos.f[2] = arg1->f[2];
        self->act_gopos.target = stan;
        self->act_gopos.target_path = target_waypoint;
        self->act_gopos.curindex = 0;
        self->act_gopos.unk59 = speed;
        self->act_gopos.speed = 0.0f;
        self->act_gopos.waydata.age = (s32) (randomGetNext() % 100U);
        self->act_gopos.waydata.unk03 = 0;
        self->act_gopos.unk9c = -1;

        for (i=0; i<MAX_CHRWAYPOINTS; i++)
        {
            self->act_gopos.waypoints[i] = sp44[i];
        }

        chrlvActGoposSetTargetPosRelated(self);
        self->sleep = 0;

        if (phi_v0 == 0)
        {
            play_hit_soundeffect_and_proper_volume(self);
        }

        chrlvActGoposRelated(self, &sp34, &sp30);

        if (((prop->flags & 2) == 0) && (chrlvStanRoomRelated(self, &sp34, sp30) != 0))
        {
            chrlvSetGoposSegDistTotal(self, &self->act_gopos.waydata, &sp34);
        }

        return 1;
    }

    return 0;
}




/**
 * Address 0x7F028FAC.
*/
void chrlvWalkingAnimationRelated(ChrRecord *self)
{
    PropRecord *left;
    PropRecord *right;
    s32 ani_arg;
    s32 flag;

    left = chrGetEquippedWeaponProp(self, GUNLEFT);
    right = chrGetEquippedWeaponProp(self, GUNRIGHT);

    if (((left != NULL) && (right != NULL)) || ((left == NULL)) && (right == NULL))
    {
        flag = 0;
        ani_arg = randomGetNext() & 1;
    }
    else
    {
        s32 t;
        if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
        {
            t = 0;
            flag = t;
            ani_arg = (s32)left != 0;
        }
        else
        {
            t = 1;
            flag = t;
            ani_arg = (s32)left != 0;
        }
    }

    if (flag != 0)
    {
        modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_walking], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else
    {
        f32 tf = (0.5f * D_80030984) / D_80030990;
        modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed], ani_arg, 0.0f, tf, 16.0f);
    }

    return;
}




#ifdef NONMATCHING

/*
* 7F0290F8
*/
void set_actor_on_path(ChrRecord *self, struct patrol_path *path)
{
    PadRecord * pad;
    s32 next_step = -1;
    PropRecord *prop = self->prop;
    s32 count = 0;
    s32 index;

    // decomp problem area: can't seem to get arr[count] to dereference the correct number of times.
    for (index = path->data[count] ; index >= 0; count++, index = path->data[count])
    {
        //s32 aa;

        //aa = g_chraiCurrentSetup.pathwaypoints[index].id;
        //pad = &g_chraiCurrentSetup.pads[aa];
        waypoint *pta = &g_chraiCurrentSetup.pathwaypoints[index];
        pad = &g_chraiCurrentSetup.pads[pta->padID];

        if ((pad->stan != NULL) && (prop->stan == pad->stan))
        {
            f32 dx = pad->pos.f[0] - prop->pos.f[0];
            f32 dz = pad->pos.f[2] - prop->pos.f[2];

            if (((((dx * dx) + (dz * dz)) < 10000.0f)))
            {
                next_step = count;
                break;
            }
        }
    }
    // end problem area.

    if (next_step < 0)
    {
        next_step = 0;
    }

    sub_GAME_7F02D184(self);
    self->actiontype = ACT_PATROL;
    self->act_patrol.path = path;

    self->act_patrol.nextstep = next_step;
    self->act_patrol.forward = TRUE;

    self->act_patrol.waydata.age = randomGetNext() % 0x64U;
    self->act_patrol.waydata.unk03 = 0;
    self->act_init.padding[0x13] = -1;

    self->act_patrol.unk7c = 0.0f;
    chrlvSetNextActPatrolStepPadPos(self);
    self->sleep = 0;
    chrlvWalkingAnimationRelated(self);
    pad = chrlvGetNextPatrolStepPad(self);

    if ((self->prop->flags & 2) == 0)
    {
        if (chrlvStanRoomRelatedPad(self, pad) != 0)
        {
            chrlvSetGoposSegDistTotal(self, &self->act_patrol.waydata, &pad->pos);
        }
    }
}

#else
GLOBAL_ASM(
.late_rodata
glabel D_80051DF8
.word 0x461c4000 /*10000.0*/
.text
glabel set_actor_on_path
/* 05DC28 7F0290F8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05DC2C 7F0290FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 05DC30 7F029100 AFB00018 */  sw    $s0, 0x18($sp)
/* 05DC34 7F029104 AFA5002C */  sw    $a1, 0x2c($sp)
/* 05DC38 7F029108 8CA80000 */  lw    $t0, ($a1)
/* 05DC3C 7F02910C 00808025 */  move  $s0, $a0
/* 05DC40 7F029110 240CFFFF */  li    $t4, -1
/* 05DC44 7F029114 8D0F0000 */  lw    $t7, ($t0)
/* 05DC48 7F029118 8C870018 */  lw    $a3, 0x18($a0)
/* 05DC4C 7F02911C 00003025 */  move  $a2, $zero
/* 05DC50 7F029120 05E0002C */  bltz  $t7, .L7F0291D4
/* 05DC54 7F029124 3C098007 */   lui   $t1, %hi(g_chraiCurrentSetup+0) 
/* 05DC58 7F029128 3C0A8007 */  lui   $t2, %hi(g_chraiCurrentSetup+0x18) 
/* 05DC5C 7F02912C 3C018005 */  lui   $at, %hi(D_80051DF8)
/* 05DC60 7F029130 C42C1DF8 */  lwc1  $f12, %lo(D_80051DF8)($at)
/* 05DC64 7F029134 8D4A5D18 */  lw    $t2, %lo(g_chraiCurrentSetup+0x18)($t2)
/* 05DC68 7F029138 8D295D00 */  lw    $t1, %lo(g_chraiCurrentSetup+0)($t1)
/* 05DC6C 7F02913C 240B002C */  li    $t3, 44
/* 05DC70 7F029140 0006C080 */  sll   $t8, $a2, 2
.L7F029144:
/* 05DC74 7F029144 01181021 */  addu  $v0, $t0, $t8
/* 05DC78 7F029148 8C590000 */  lw    $t9, ($v0)
/* 05DC7C 7F02914C 00196900 */  sll   $t5, $t9, 4
/* 05DC80 7F029150 01A91821 */  addu  $v1, $t5, $t1
/* 05DC84 7F029154 8C6E0000 */  lw    $t6, ($v1)
/* 05DC88 7F029158 01CB0019 */  multu $t6, $t3
/* 05DC8C 7F02915C 00007812 */  mflo  $t7
/* 05DC90 7F029160 01EA2021 */  addu  $a0, $t7, $t2
/* 05DC94 7F029164 8C850028 */  lw    $a1, 0x28($a0)
/* 05DC98 7F029168 50A00015 */  beql  $a1, $zero, .L7F0291C0
/* 05DC9C 7F02916C 24C60001 */   addiu $a2, $a2, 1
/* 05DCA0 7F029170 8CF80014 */  lw    $t8, 0x14($a3)
/* 05DCA4 7F029174 57050012 */  bnel  $t8, $a1, .L7F0291C0
/* 05DCA8 7F029178 24C60001 */   addiu $a2, $a2, 1
/* 05DCAC 7F02917C C4840000 */  lwc1  $f4, ($a0)
/* 05DCB0 7F029180 C4E60008 */  lwc1  $f6, 8($a3)
/* 05DCB4 7F029184 C4880008 */  lwc1  $f8, 8($a0)
/* 05DCB8 7F029188 C4EA0010 */  lwc1  $f10, 0x10($a3)
/* 05DCBC 7F02918C 46062001 */  sub.s $f0, $f4, $f6
/* 05DCC0 7F029190 460A4081 */  sub.s $f2, $f8, $f10
/* 05DCC4 7F029194 46000402 */  mul.s $f16, $f0, $f0
/* 05DCC8 7F029198 00000000 */  nop   
/* 05DCCC 7F02919C 46021482 */  mul.s $f18, $f2, $f2
/* 05DCD0 7F0291A0 46128100 */  add.s $f4, $f16, $f18
/* 05DCD4 7F0291A4 460C203C */  c.lt.s $f4, $f12
/* 05DCD8 7F0291A8 00000000 */  nop   
/* 05DCDC 7F0291AC 45000003 */  bc1f  .L7F0291BC
/* 05DCE0 7F0291B0 00000000 */   nop   
/* 05DCE4 7F0291B4 10000007 */  b     .L7F0291D4
/* 05DCE8 7F0291B8 00C06025 */   move  $t4, $a2
.L7F0291BC:
/* 05DCEC 7F0291BC 24C60001 */  addiu $a2, $a2, 1
.L7F0291C0:
/* 05DCF0 7F0291C0 0006C880 */  sll   $t9, $a2, 2
/* 05DCF4 7F0291C4 01196821 */  addu  $t5, $t0, $t9
/* 05DCF8 7F0291C8 8DAE0000 */  lw    $t6, ($t5)
/* 05DCFC 7F0291CC 05C3FFDD */  bgezl $t6, .L7F029144
/* 05DD00 7F0291D0 0006C080 */   sll   $t8, $a2, 2
.L7F0291D4:
/* 05DD04 7F0291D4 05810002 */  bgez  $t4, .L7F0291E0
/* 05DD08 7F0291D8 02002025 */   move  $a0, $s0
/* 05DD0C 7F0291DC 00006025 */  move  $t4, $zero
.L7F0291E0:
/* 05DD10 7F0291E0 0FC0B461 */  jal   sub_GAME_7F02D184
/* 05DD14 7F0291E4 AFAC0020 */   sw    $t4, 0x20($sp)
/* 05DD18 7F0291E8 8FAC0020 */  lw    $t4, 0x20($sp)
/* 05DD1C 7F0291EC 240F000E */  li    $t7, 14
/* 05DD20 7F0291F0 A20F0007 */  sb    $t7, 7($s0)
/* 05DD24 7F0291F4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 05DD28 7F0291F8 24190001 */  li    $t9, 1
/* 05DD2C 7F0291FC AE190034 */  sw    $t9, 0x34($s0)
/* 05DD30 7F029200 AE0C0030 */  sw    $t4, 0x30($s0)
/* 05DD34 7F029204 0C002914 */  jal   randomGetNext
/* 05DD38 7F029208 AE18002C */   sw    $t8, 0x2c($s0)
/* 05DD3C 7F02920C 24010064 */  li    $at, 100
/* 05DD40 7F029210 0041001B */  divu  $zero, $v0, $at
/* 05DD44 7F029214 44803000 */  mtc1  $zero, $f6
/* 05DD48 7F029218 00006810 */  mfhi  $t5
/* 05DD4C 7F02921C 240EFFFF */  li    $t6, -1
/* 05DD50 7F029220 AE0D0060 */  sw    $t5, 0x60($s0)
/* 05DD54 7F029224 A200003B */  sb    $zero, 0x3b($s0)
/* 05DD58 7F029228 AE0E0078 */  sw    $t6, 0x78($s0)
/* 05DD5C 7F02922C 02002025 */  move  $a0, $s0
/* 05DD60 7F029230 0FC0A125 */  jal   chrlvSetNextActPatrolStepPadPos
/* 05DD64 7F029234 E606007C */   swc1  $f6, 0x7c($s0)
/* 05DD68 7F029238 A2000008 */  sb    $zero, 8($s0)
/* 05DD6C 7F02923C 0FC0A3EB */  jal   chrlvWalkingAnimationRelated
/* 05DD70 7F029240 02002025 */   move  $a0, $s0
/* 05DD74 7F029244 0FC0A11D */  jal   chrlvGetNextPatrolStepPad
/* 05DD78 7F029248 02002025 */   move  $a0, $s0
/* 05DD7C 7F02924C 8E0F0018 */  lw    $t7, 0x18($s0)
/* 05DD80 7F029250 02002025 */  move  $a0, $s0
/* 05DD84 7F029254 00402825 */  move  $a1, $v0
/* 05DD88 7F029258 91F80001 */  lbu   $t8, 1($t7)
/* 05DD8C 7F02925C 33190002 */  andi  $t9, $t8, 2
/* 05DD90 7F029260 57200009 */  bnezl $t9, .L7F029288
/* 05DD94 7F029264 8FBF001C */   lw    $ra, 0x1c($sp)
/* 05DD98 7F029268 0FC09F9C */  jal   chrlvStanRoomRelatedPad
/* 05DD9C 7F02926C AFA20024 */   sw    $v0, 0x24($sp)
/* 05DDA0 7F029270 10400004 */  beqz  $v0, .L7F029284
/* 05DDA4 7F029274 8FA60024 */   lw    $a2, 0x24($sp)
/* 05DDA8 7F029278 02002025 */  move  $a0, $s0
/* 05DDAC 7F02927C 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 05DDB0 7F029280 26050038 */   addiu $a1, $s0, 0x38
.L7F029284:
/* 05DDB4 7F029284 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F029288:
/* 05DDB8 7F029288 8FB00018 */  lw    $s0, 0x18($sp)
/* 05DDBC 7F02928C 27BD0028 */  addiu $sp, $sp, 0x28
/* 05DDC0 7F029290 03E00008 */  jr    $ra
/* 05DDC4 7F029294 00000000 */   nop   
)
#endif



void setSeenBondTimeToNow(ChrRecord *self)
{
  self->seen_bond_time = g_GlobalTimer;
  return;
}



/**
 * Address 0x7F0292A8.
*/
s32 chrlvAttackRelated7F0292A8(ChrRecord *self, coord3d *arg1, StandTile *arg2)
{
    s32 ret;
    s32 flags;
    StandTile *stan;
    StandTile *sp40;
    coord3d *sp3C;

    ret = 0;
    flags = TARGET_BOND;

    if (self->actiontype == ACT_ATTACK)
    {
        flags = self->act_attack.attacktype;
    }

    if ((flags & TARGET_FRONT_OF_CHR) != 0)
    {
        ret = 1;
    }
    else
    {
        stan = arg2;
        sp3C = chrlvGetChrOrPresetLocation(self, flags, self->act_attack.entityid, &sp40);
        set_or_unset_GUARDdata_flag(self, 0);

        if ((flags & 1) != 0)
        {
            bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);
            
            if (bondviewGetVisibleToGuardsFlag() != 0)
            {
                if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x11B, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
                {
                    setSeenBondTimeToNow(self);
                    ret = 1;
                }
            }

            bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);
        }
        else if ((flags & 4) != 0)
        {
            if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x117, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
            {
                ret = 1;
            }
        }
        else if ((flags & 8) != 0)
        {
            if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x11F, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
            {
                ret = 1;
            }
        }

        set_or_unset_GUARDdata_flag(self, 1);
    }

    return ret;
}




/**
 * Address 0x7F0294BC.
*/
bool chrCanSeeBond(ChrRecord *self)
{
    bool pass = FALSE;
    PropRecord *myprop;
    PropRecord *bondprop;
    StandTile *mystan;
    f32 myheight;

    if (bondviewGetVisibleToGuardsFlag())
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();
        myheight = self->chrheight - 20.0f;

        set_or_unset_GUARDdata_flag(self, FALSE);
        bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);

        mystan = myprop->stan;

        if (sub_GAME_7F0B0E24(&mystan, myprop->pos.x, myprop->pos.z, bondprop->pos.x, bondprop->pos.z, 0x11B, myheight, myheight, 0.0f, 1.0f) && (mystan == bondprop->stan))
        {
            setSeenBondTimeToNow(self);
            pass = TRUE;
        }

        set_or_unset_GUARDdata_flag(self, TRUE);
        bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);
    }

    return pass;
}




/**
 * Address 0x7F0295D0.
*/
bool check_if_position_in_same_room(ChrRecord *self, coord3d *pos, StandTile *stan)
{
    PropRecord *myprop   = self->prop;
    StandTile  *propstan;
    f32         myheight = self->chrheight - 20.0f;
    bool        pass     = FALSE;

    set_or_unset_GUARDdata_flag(self, 0);

    propstan = myprop->stan;

    if (sub_GAME_7F0B0E24(&propstan, myprop->pos.x, myprop->pos.z, pos->x, pos->z, 0x113, myheight, myheight, 0.0f, 1.0f) && (propstan == stan))
    {
        pass = TRUE;
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return pass;
}



/**
 * Address 0x7F02969C.
*/
s32 chrlvMaybeSameRoom(ChrRecord *self, coord3d *arg1, StandTile *arg2)
{
    f32 atan;
    f32 roty;
    f32 df;

    roty = getsubroty(self->model);
    atan = atan2f(arg1->f[0] - self->prop->pos.f[0], arg1->f[2] - self->prop->pos.f[2]);
    df = atan - roty;

    if (atan < roty)
    {
        df += M_TAU_F;
    }
    // if NOT in rear left quadrant?
    if ((df < DegToRad(100)) || (df > DegToRad(260)))
    {
        return check_if_position_in_same_room(self, arg1, arg2);
    }

    return 0;
}




/**
 * Address 0x7F029760.
*/
s32 chrlvCurrentPlayerCall7F0B0E24(ChrRecord *self)
{
    PropRecord *sp3C;
    PropRecord *bond_prop;
    StandTile *bond_stan;
    s32 ret;

    sp3C = self->prop;
    bond_prop = get_curplayer_positiondata();
    ret = 0;

    bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);

    bond_stan = bond_prop->stan;
    
    if ((sub_GAME_7F0B0E24(
            &bond_stan,
            bond_prop->pos.f[0],
            bond_prop->pos.f[2],
            sp3C->pos.f[0],
            sp3C->pos.f[2],
            0x13,
            bond_prop->pos.f[1],
            bond_prop->pos.f[1],
            0.0f,
            1.0f) != 0)
        && (bond_stan == sp3C->stan))
    {
        ret = 1;
    }

    bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);

    return ret;
}




/**
 * Address 0x7F02982C.
*/
s32 chrlvCall7F0B0E24WithChrWidthHeight(PropRecord *arg0, coord3d *arg1, coord3d *arg2)
{
    ChrRecord *sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    StandTile *stan;
    f32 chrx;
    f32 chrz;
    s32 ret; // sp92
    f32 sp58; // sp88
    f32 sp54; // sp84
    f32 sp50; // sp80

    sp7C = arg0->chr;
    chrx = arg2->f[0] * sp7C->chrwidth * 1.2f;
    chrz = arg2->f[2] * sp7C->chrwidth * 1.2f;
    ret = 0;

    chrGetChrWidthHeight(arg0, &sp50, &sp58, &sp54);
    set_or_unset_GUARDdata_flag(sp7C, 0);

    sp78 = arg0->pos.f[0] + chrz;
    sp74 = arg0->pos.f[2] - chrx;
    sp70 = arg1->f[0] + chrz + chrx;
    sp6C = (arg1->f[2] - chrx) + chrz;

    stan = arg0->stan;

    if (
        (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], sp78, sp74, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
        && (sub_GAME_7F0B0E24(&stan, sp78, sp74, sp70, sp6C, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
        )
    {
        sp78 = arg0->pos.f[0] - chrz;
        sp74 = arg0->pos.f[2] + chrx;
        sp70 = (arg1->f[0] - chrz) + chrx;
        sp6C = arg1->f[2] + chrx + chrz;

        // why is this getting set again?
        stan = arg0->stan;

        if (
            (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], sp78, sp74, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
            && (sub_GAME_7F0B0E24(&stan, sp78, sp74, sp70, sp6C, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
            )
        {
            ret = 1;
        }
    }

    set_or_unset_GUARDdata_flag(sp7C, 1);

    return ret;
}




/**
 * Addres 0x7F029A94.
*/
s32 chrlvCall7F02982C(PropRecord *arg0, coord3d *arg1, f32 arg2)
{
    coord3d sp1C;

    sp1C.f[0] = arg0->pos.f[0] + (arg1->f[0] * arg2);
    sp1C.f[1] = arg0->pos.f[1];
    sp1C.f[2] = arg0->pos.f[2] + (arg1->f[2] * arg2);

    return chrlvCall7F0B0E24WithChrWidthHeight(arg0, &sp1C, arg1);
}



/**
 * Unreferenced.
 * 
 * Address 0x7F029AF0.
*/
s32 chrlvCall7F0B0E24Normalized(PropRecord *arg0, coord3d *arg1)
{
    coord3d sp24;
    f32 temp_f2;

    sp24.f[0] = arg1->f[0] - arg0->pos.f[0];
    sp24.f[1] = 0.0f;
    sp24.f[2] = arg1->f[2] - arg0->pos.f[2];

    if ((sp24.f[0] == 0.0f) && (sp24.f[2] == 0.0f))
    {
        return 1;
    }

    temp_f2 = 1.0f / sqrtf(SQR(sp24.f[0]) + SQR(sp24.f[2]));

    sp24.f[0] *= temp_f2;
    sp24.f[2] *= temp_f2;

    return chrlvCall7F0B0E24WithChrWidthHeight(arg0, arg1, &sp24);
}




/**
 * Same as chrlvAlertGuardToPlayerPosition, except without setting `hidden` flag 0x2.
 * 
 * Address 0x7F029BB0.
*/
void chrlvSetTargetToPlayer(ChrRecord *self)
{
    PropRecord *temp_v0;

    temp_v0 = get_curplayer_positiondata();
    self->lastseetarget60 = g_GlobalTimer;
    self->lastknowntargetpos.f[0] = temp_v0->pos.f[0];
    self->lastknowntargetpos.f[1] = temp_v0->pos.f[1];
    self->lastknowntargetpos.f[2] = temp_v0->pos.f[2];
    self->targetTile = temp_v0->stan;
}




/**
 * See also chrlvSetTargetToPlayer.
 * 
 * Address 0x7F029C00.
 */
void chrlvAlertGuardToPlayerPosition(ChrRecord *self)
{
    PropRecord *temp_v0;

    temp_v0 = get_curplayer_positiondata();
    self->hidden |= CHRHIDDEN_ALERT_GUARD_RELATED;
    self->lastheartarget60 = g_GlobalTimer;
    self->lastknowntargetpos.f[0] = temp_v0->pos.x;
    self->lastknowntargetpos.f[1] = temp_v0->pos.y;
    self->lastknowntargetpos.f[2] = temp_v0->pos.z;
    self->targetTile = temp_v0->stan;
}


/**
 * Address 0x7F029C5C.
*/
bool chrHasStoppedOrPatroling(ChrRecord *self) //chrHasStoppedOrPatroling
{
    if ((self->actiontype == ACT_STAND) && !self->act_stand.unk02c && !self->act_stand.unk038)
    {
        return TRUE;
    }
    else if (self->actiontype == ACT_ANIM)
    {
        if (self->act_anim.unk034 ||
            ((modelGetAnimSpeed(self->model) >= 0.0f) && objecthandlerGetModelField28(self->model) >= (sub_GAME_7F06F5C4(self->model))) ||
            ((modelGetAnimSpeed(self->model) < 0.0f) && (objecthandlerGetModelField28(self->model) <= 0.0f)))
        {
            return TRUE;
        }
    }
    else if (self->actiontype == ACT_PATROL)
    {
        return TRUE;
    }

    return FALSE;
}




/**
 * Address 0x7F029D70.
*/
bool chrCheckTargetInSight(ChrRecord *self)
{
    PropRecord *myprop;   
    PropRecord *bondprop; 
    f32         rrr;
    f32         vec2rd;
    f32         myRadDirection; 
    coord3d     vec;            
    f32         atn;
    f32         radChangeToFaceBond; 
    bool        pass;                
    u32         rt;
    s32         distance;

    myprop               = self->prop;
    bondprop             = get_curplayer_positiondata();
    myRadDirection       = getsubroty(self->model);
    //Note: x and z get swapped
    vec.z                = bondprop->pos.x - myprop->pos.x;
    vec.y                = bondprop->pos.y - myprop->pos.y;
    vec.x                = bondprop->pos.z - myprop->pos.z;

    atn = atan2f(vec.z, vec.x);

    pass                = FALSE;
    rrr                 = atn - myRadDirection;
    radChangeToFaceBond = rrr;

    if (atn < myRadDirection)
    {
        radChangeToFaceBond = rrr + M_TAU_F;
    }

    if (chrSawTargetRecently(self))
    {
        pass = TRUE;
    }
    else
    {
        vec2rd = SQR(vec.z) + SQR(vec.y) + SQR(vec.x);

        if (
            /*within 220 degrees of forward and within range*/
            (
                (vec2rd < (self->visionrange * self->visionrange * 100.0f * 100.0f)) &&
                ((radChangeToFaceBond < DegToRad(110)) || (radChangeToFaceBond > DegToRad(360 - 110)))
            )
            ||
            /*or within clamped minimum of 200*/
            (
                (vec2rd < SQR(200)) &&
                ((radChangeToFaceBond < DegToRad(110)) || (radChangeToFaceBond > DegToRad(360 - 110)))
            )
        )
        {
            if (vec2rd < fogGetScaledFarFogIntensitySquared())
            {
                distance = (s32)((sqrtf(vec2rd) * 30.0f) / 16000.0f);

                //Not facing bond
                if ((radChangeToFaceBond > DegToRad(45)) && (radChangeToFaceBond < DegToRad(360.0 - 45)))
                {
                    f32 f0 = radChangeToFaceBond;
                    if (radChangeToFaceBond > M_PI_F)
                    {
                        //confine/wrap to half
                        f0 = M_TAU_F - radChangeToFaceBond;
                    }

                    f0 -= DegToRad(45);

                    distance *= (s32)((f0 * 24.0f) / M_TAU_F) + 1;
                }

                distance = chrlvGetGuard007SpeedRatingInt(self, distance) + 1;
                pass = ((u32)randomGetNext() % (u32)distance) == 0;
            }
        }
    }

    if (pass)
    {
        pass = chrCanSeeBond(self);
    }

    if (pass)
    {
        chrlvSetTargetToPlayer(self);
    }

    return pass;
}



/**
 * get vector to run on
 * @param self:
 * @param side: If GUNLEFT set result is (dz, -dx), otherwise (-dz, dx).
 * @param arg2: Out parameter. Contains result vector.
 * 
 * Address 0x7F02A044.
*/
void chrlvNormDistanceToPlayer(ChrRecord *self, GUNHAND side, vec3d *vec)
{
    PropRecord *prop;
    f32 norm;
    f32 dx;
    f32 dz;
    PropRecord *player_prop;

    prop = self->prop;
    player_prop = get_curplayer_positiondata();
    dx = player_prop->pos.f[0] - prop->pos.f[0];
    dz = player_prop->pos.f[2] - prop->pos.f[2];

    norm = sqrtf((dx * dx) + (dz * dz));

    dx = dx / norm;
    dz = dz / norm;

    if (side != GUNRIGHT)
    {
        vec->f[1]  = 0;
        vec->f[0]  = dz;
        vec->f[2]  = -(dx);
    }
    else
    {
        vec->f[2]  = dx;
        vec->f[0]  = -(dz);
        vec->f[1]  = 0;
    }
}




/**
 * chrIsClearLow
 * @see sub_GAME_7F02A1E8
 * Address 0x7F02A0EC.
*/
s32 sub_GAME_7F02A0EC(ChrRecord *self, GUNHAND side, f32 distance)
{
    PropRecord *prop;
    coord3d sp28;
    coord3d sp1C;

    prop = self->prop;
    chrlvNormDistanceToPlayer(self, side, &sp28);

    sp1C.f[0] = prop->pos.f[0] + (sp28.f[0] * distance);
    sp1C.f[1] = prop->pos.f[1];
    sp1C.f[2] = prop->pos.f[2] + (sp28.f[2] * distance);

    return chrlvCall7F0B0E24WithChrWidthHeight(prop, &sp1C, &sp28);
}




/**
 * @param self:
 * @param arg1: flag. If set result is (cos, -sin), otherwise (-cos, sin).
 * @param arg2: out parameter, contains coordinate result.
 * 
 * Address 0x7F02A15C.
*/
void chrlvModelRotyRelated(ChrRecord *self, s32 arg1, coord3d *arg2)
{
    f32 temp_f12;

    temp_f12 = getsubroty(self->model);

    if (arg1 != 0)
    {
        arg2->f[0] = cosf(temp_f12);
        arg2->f[1] = 0.0f;
        arg2->f[2] = -sinf(temp_f12);
    }
    else
    {
        arg2->f[0] = -cosf(temp_f12);
        arg2->f[1] = 0.0f;
        arg2->f[2] = sinf(temp_f12);
    }
}




/**
 * chrIsClear
 * @see sub_GAME_7F02A0EC 
 * 
 * Address 0x7F02A1E8.
*/
s32 sub_GAME_7F02A1E8(ChrRecord *self, GUNHAND side, f32 distance)
{
    PropRecord *prop;
    coord3d sp28;
    coord3d sp1C;

    prop = self->prop;
    chrlvModelRotyRelated(self, side, &sp28);

    sp1C.f[0] = prop->pos.f[0] + (sp28.f[0] * distance);
    sp1C.f[1] = prop->pos.f[1];
    sp1C.f[2] = prop->pos.f[2] + (sp28.f[2] * distance);

    return chrlvCall7F0B0E24WithChrWidthHeight(prop, &sp1C, &sp28);
}




bool chrIsNotDeadOrShot(ChrRecord *self)
{
    s8 currentaction = self->actiontype;

    if ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD) || (currentaction == ACT_PREARGH) 
        || (currentaction == ACT_ARGH) && !(self->chrflags & CHRFLAG_00000200))
    {
        return FALSE;
    }

    return TRUE;
}



bool chrIsDead(ChrRecord *self)
{
    s8 currentaction = self->actiontype;

    return ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD));
}



/**
 * Address 0x7F02A2C8.
*/
bool actor_steps_sideways(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;
    int pad1; //needed for stack size - check debug rom
    f32 myRadDirection;
    int pad2; //needed for stack size
    f32 myRadDirectionToBond;
    f32 radChangeToFaceBond;
    GUNHAND HopOtherDirection; //needed for stack size
    GUNHAND HopDirection;
    f32 myNormalizedRadToBond;

    if (chrIsNotDeadOrShot(self))
    {
        myprop                = self->prop;
        bondprop              = get_curplayer_positiondata();
        myRadDirection        = getsubroty(self->model);
        myRadDirectionToBond  = atan2f(bondprop->pos.x - myprop->pos.x, bondprop->pos.z - myprop->pos.z);
        radChangeToFaceBond   = myRadDirectionToBond - myRadDirection;
        myNormalizedRadToBond = radChangeToFaceBond;

        if (myRadDirectionToBond < myRadDirection) //avoid negative radians
        {
            myNormalizedRadToBond = radChangeToFaceBond + M_TAU_F;
        }

        if ((myNormalizedRadToBond < DegToRad(45)) || (myNormalizedRadToBond > DegToRad(360.0 - 45)) ||        /*Front*/
            ((myNormalizedRadToBond > DegToRad(180.0 - 45)) && (myNormalizedRadToBond < DegToRad(180.0 + 45))) /*Back*/
        )
        {
            HopDirection = (randomGetNext() & 1) == 0;         //Hop Left or Right
            if (sub_GAME_7F02A1E8(self, HopDirection, 100.0f)) //able to step dir?
            {
                chrlvSideStepAnimationRelated(self, HopDirection);
                return TRUE;
            }

            HopOtherDirection = HopDirection == 0;

            if (sub_GAME_7F02A1E8(self, HopOtherDirection, 100.0f)) //able to step other dir?
            {
                chrlvSideStepAnimationRelated(self, HopOtherDirection);
                return TRUE;
            }
        }
    }

    return FALSE; //unable to step
}



/**
 * Address 0x7F02A428.
*/
bool actor_hops_sideways(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;
    int pad1; //needed for stack size - check debug rom
    f32 myRadDirection;
    int pad2; //needed for stack size
    f32 myRadDirectionToBond;
    f32 radChangeToFaceBond;
    GUNHAND HopOtherDirection; //needed for stack size
    GUNHAND HopDirection;
    f32 myNormalizedRadToBond;

    if (chrIsNotDeadOrShot(self))
    {
        myprop                = self->prop;
        bondprop              = get_curplayer_positiondata();
        myRadDirection        = getsubroty(self->model);
        myRadDirectionToBond  = atan2f(bondprop->pos.x - myprop->pos.x, bondprop->pos.z - myprop->pos.z);
        radChangeToFaceBond   = myRadDirectionToBond - myRadDirection;
        myNormalizedRadToBond = radChangeToFaceBond;

        if (myRadDirectionToBond < myRadDirection) //avoid negative radians
        {
            myNormalizedRadToBond = radChangeToFaceBond + M_TAU_F;
        }

        if ((myNormalizedRadToBond < DegToRad(45)) || (myNormalizedRadToBond > DegToRad(360.0 - 45)) ||        /*Front*/
            ((myNormalizedRadToBond > DegToRad(180.0 - 45)) && (myNormalizedRadToBond < DegToRad(180.0 + 45))) /*Back*/
        )
        {
            HopDirection = (randomGetNext() & 1) == 0;         //Hop Left or Right

            if (sub_GAME_7F02A1E8(self, HopDirection, 200.0f)) //able to hop dir?
            {
                chrlvFireJumpToSideAnimationRelated(self, HopDirection);
                return TRUE;
            }

            HopOtherDirection = HopDirection == 0;

            if (sub_GAME_7F02A1E8(self, HopOtherDirection, 200.0f)) //able to hop other dir?
            {
                chrlvFireJumpToSideAnimationRelated(self, HopOtherDirection);
                return TRUE;
            }
        }
    }

    return FALSE; //unable to hop
}



/**
 * Address 0x7F02A588.
*/
bool actor_jogs_sideways(ChrRecord *self)
{
    PropRecord *myprop;
    f32         distToRun;
    vec3d       TargetVector;
    coord3d     TargetCoord;

    if (chrIsNotDeadOrShot(self) && ((g_GlobalTimer - self->lastwalk60) >= CHRLV_RECENT_TIME_CHECK)) //>3 seconds since last walk
    {
        myprop    = self->prop;
        distToRun = ((u32)randomGetNext() * (1.0f / UINT_MAX) * 200.0f) + 200.0f;         //random dist to run between 0 and 200
        chrlvNormDistanceToPlayer(self, ((u32)randomGetNext() & 1) == 0, &TargetVector);  //get vector to run on
        
        TargetCoord.x = (TargetVector.x * distToRun) + myprop->pos.x;
        TargetCoord.y = myprop->pos.y;
        TargetCoord.z = (TargetVector.z * distToRun) + myprop->pos.z;

        if (chrlvCall7F0B0E24WithChrWidthHeight(myprop, &TargetCoord, &TargetVector))
        {
            sub_GAME_7F024CF8(self, &TargetCoord);
            return TRUE;
        }

        TargetVector.x = -TargetVector.x;
        TargetVector.z = -TargetVector.z;
        TargetCoord.x  = (TargetVector.x * distToRun) + myprop->pos.x;
        TargetCoord.y  = myprop->pos.y;
        TargetCoord.z  = (TargetVector.z * distToRun) + myprop->pos.z;


        if (chrlvCall7F0B0E24WithChrWidthHeight(myprop, &TargetCoord, &TargetVector))
        {
            sub_GAME_7F024CF8(self, &TargetCoord);
            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A704.
*/
bool actor_walks_and_fires(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (
            (chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT) || chrGetEquippedWeaponPropWithCheck(self, GUNLEFT))
            &&
            ((g_GlobalTimer - self->lastwalk60) >= CHRLV_RECENT_TIME_CHECK)
            )
        {
            f32 dx = bondprop->pos.x - myprop->pos.x;
            f32 dy = bondprop->pos.y - myprop->pos.y;
            f32 dz = bondprop->pos.z - myprop->pos.z;

            if ( (SQR(dx) + SQR(dy) + SQR(dz)) >= (1000000.0f))
            {
                chrlvInitActAttackWalk(self, SPEED_WALK);
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A7F8.
*/
bool actor_runs_and_fires(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (
            (chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT) || chrGetEquippedWeaponPropWithCheck(self, GUNLEFT))
            &&
            ((g_GlobalTimer - self->lastwalk60) >= CHRLV_RECENT_TIME_CHECK)
            )
        {
            f32 dx = bondprop->pos.x - myprop->pos.x;
            f32 dy = bondprop->pos.y - myprop->pos.y;
            f32 dz = bondprop->pos.z - myprop->pos.z;

            if ((SQR(dx) + SQR(dy) + SQR(dz)) >= (1000000.0f))
            {
                chrlvInitActAttackWalk(self, SPEED_RUN);
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A8EC.
*/
bool actor_rolls_fires_crouched(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    vec3d vec;

    GUNHAND HopOtherDirection;
    GUNHAND HopDirection;
    float vec2rd;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT) || chrGetEquippedWeaponPropWithCheck(self, GUNLEFT))
        {
            vec.x  = bondprop->pos.x - myprop->pos.x;
            vec.y  = bondprop->pos.y - myprop->pos.y;
            vec.z  = bondprop->pos.z - myprop->pos.z;
            vec2rd = SQR(vec.x) + SQR(vec.y) + SQR(vec.z);

            if (SQR(200.0f) <= vec2rd) /*Bond GT 200 from chr*/
            {
                HopDirection = (randomGetNext() & 1) == 0; //Hop Left or Right

                if (sub_GAME_7F02A0EC(self, HopDirection, 200))
                {
                    chrlvInitActAttackRoll(self, HopDirection);
                    return TRUE;
                }

                HopOtherDirection = HopDirection == 0;

                if (sub_GAME_7F02A0EC(self, HopOtherDirection, 200))
                {
                    chrlvInitActAttackRoll(self, HopOtherDirection);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02AA1C.
*/
bool actor_aim_at_actor(ChrRecord *self, s32 attack_type, s32 b)
{
    if ((chrIsNotDeadOrShot(self)) &&
        ((chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT)) || (chrGetEquippedWeaponPropWithCheck(self, GUNLEFT))))
    {
        sub_GAME_7F025560(self, attack_type, b);
        return TRUE;
    }

    return FALSE;
}




/**
 * Address 0x7F02AA88.
*/
bool actor_kneel_aim_at_actor(ChrRecord *self, s32 targettype, s32 targetid)
{
    if ((chrIsNotDeadOrShot(self)) &&
        ((chrGetEquippedWeaponPropWithCheck(self, GUNRIGHT)) || (chrGetEquippedWeaponPropWithCheck(self, GUNLEFT))))
    {
        sub_GAME_7F0256F0(self, targettype, targetid);
        return TRUE;
    }

    return FALSE;
}




bool actor_fire_or_aim_at_target_update(ChrRecord *self, s32 newtargettype, s32 newtargetid)
{
    if (self->actiontype == ACT_ATTACK)
    {
        if (self->act_attack.attacktype & (TARGET_AIM_ONLY | TARGET_DONTTURN))
        {
            self->act_attack.attacktype = newtargettype;
            self->act_attack.entityid   = newtargetid;
            chrlvAttackActionRelated(self);
            return TRUE;
        }
    }

    return FALSE;
}


/**
 * Address 0x7F02AB44.
*/
bool check_set_actor_standing_still(ChrRecord *self, s32 faceentitytype, s32 faceentityid)
{
    if (chrIsNotDeadOrShot(self) != 0)
    {
        if (self->actiontype != ACT_STAND)
        {
            chrlvKneelingAnimationRelated(self);
        }

        self->act_stand.face_entitytype = faceentitytype;
        self->act_stand.face_entityid   = faceentityid;
        self->act_stand.unk038          = 0;
        self->act_stand.unk040          = 0;

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F02ABB4.
*/
bool chrGoToPad(ChrRecord *self, s32 padid, SPEED speed)
{
    PadRecord *pad;
    StandTile *stan2; //sp38
    coord3d region;
    StandTile *stan; //sp28 - wow, deliberate duplicate...

    if ((padid >= 0) && chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        padid = chrResolvePadId(self, padid);
        if (isNotBoundPad(padid))
        {
            pad = &g_chraiCurrentSetup.pads[padid];
        }
        else
        {
            pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padid)];
        }

        stan = pad->stan;
        if (stan)
        {
            //if pad is not vertical
            if (pad->up.y < 0.5f)
            {
                stan2    = stan;
                region.x = (pad->up.x * (self->chrwidth * 1.1f)) + pad->pos.x;
                region.y = (pad->up.y * (self->chrwidth * 1.1f)) + pad->pos.y;
                region.z = (pad->up.z * (self->chrwidth * 1.1f)) + pad->pos.z;

                //if able to reach region surrounding pad?
                if (walkTilesBetweenPoints_NoCallback(&stan2, pad->pos.x, pad->pos.z, region.x, region.z) &&
                    plot_course_for_actor(self, &region, stan2, speed))
                {
                    return TRUE;
                }
            }
            else if (plot_course_for_actor(self, &pad->pos, stan, speed))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02AD54.
*/
bool if_actor_able_set_on_path(ChrRecord *self, s32 pathid)
{
    if (pathid && chrIsNotDeadOrShot(self))
    {
        set_actor_on_path(self, pathid);
        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F02AD98.
 * PD: chrTickStand
*/
void chrlvTickStand(ChrRecord *self)
{
    s32 i;             // any
    f32 aaa;
    s32 bbb;
    PropRecord *left;  // 160
    PropRecord *right; // 156
    s32 index;         // any
    s32 ccc;
    f32 sp74[8];       // 116
    f32 subroty;       // 112
    f32 temp_f0;       // 108
    f32 subrotyarg2;   // any
    s32 j;             // any
    s32 sp44[8];       // 68
    s32 z; // required to push $f0 below

    if (self->sleep > 0)
    {
        return;
    }

    if (self->act_stand.unk02c != 0)
    {
        // needs to save $f0 into sp(0x3c)
        if (objecthandlerGetModelField28(self->model) >= sub_GAME_7F06F5C4(self->model))
        {
            chrlvIdleAnimationRelated(self, 8.0f);
            self->act_stand.unk02c = 0;
        }

        self->sleep = 0;

        return;
    }

    if (self->act_stand.face_entitytype > 0)
    {
        if (self->act_stand.unk038)
        {
            subrotyarg2 = objecthandlerGetModelAnim(self->model)->unk04 - 1;
            self->act_stand.unk03c = chrlvSetSubroty(self, self->act_stand.unk03c, subrotyarg2, 1.0f, 0.0f);

            if (self->act_stand.unk03c != 1)
            {
                chrlvIdleAnimationRelated(self, 8.0f);
                self->act_stand.unk038 = 0;

                if (self->act_stand.face_entitytype & 0x10)
                {
                    self->act_stand.face_entitytype = 0;
                }
            }
        }
        else
        {
            temp_f0 = chrlvDistanceToChrRelated(self, self->act_stand.face_entitytype, self->act_stand.face_entityid);
            if ((temp_f0 > 0.34906587f) && (temp_f0 < 5.9341197f))
            {
                left = chrGetEquippedWeaponProp(self, 1);
                right = chrGetEquippedWeaponProp(self, 0);

                self->act_stand.unk038 = 1;
                self->act_stand.unk03c = 1;
                
                if (((left != NULL) && (right != NULL))
                    || ((left == NULL) && (right == NULL))
                    || check_if_item_held_like_pistol(left)
                    || check_if_item_held_like_pistol(right))
                {
                    // required to fix stack above
                    // looks like it doesn't matter which `s32` is used.
                    i = (s32)((u32)randomGetNext() & 1U);
                    modelSetAnimation(
                        self->model,
                        // awkward fix: addu instruction is backwards
                        (struct ModelAnimation *)((s32)&ANIM_DATA_walking_unarmed + (s32)&ptr_animation_table->data),
                        i,
                        0.0f,
                        0.5f,
                        16.0f);

                    modelSetAnimEndFrame(
                        self->model,
                        (((u16*)((s32)&ANIM_DATA_walking_unarmed + (s32)&ptr_animation_table->data))[2] - 1));
                }
                else if ((right != NULL) || (left != NULL))
                {
                    modelSetAnimation(
                        self->model,
                        // awkward fix: addu instruction is backwards
                        (struct ModelAnimation *)((s32)&ANIM_DATA_walking + (s32)&ptr_animation_table->data),
                        left != NULL,
                        0.0f,
                        0.5f,
                        16.0f);

                    modelSetAnimEndFrame(
                        self->model,
                        (((u16*)((s32)&ANIM_DATA_walking + (s32)&ptr_animation_table->data))[2] - 1));
                }
            }
            else if (self->act_stand.face_entitytype & 0x10)
            {
                self->act_stand.face_entitytype = 0;
            }
        }

        self->sleep = 0;

        return;
    }

    self->sleep = ((u32)randomGetNext() % 5U) + 0xE;

    if (self->act_stand.unk040)
    {
        if (self->chrflags & 0x80)
        {
            self->act_stand.unk040 = 0;
            return;
        }

        self->act_stand.unk044 -= self->sleep;
        if (self->act_stand.unk044 < 0)
        {
            subroty = getsubroty(self->model);

            temp_f0 = subroty;
            for (i = 0; i < 8; i++)
            {
                temp_f0 += DegToRad(45);
                
                if (temp_f0 >= M_TAU_F)
                {
                    temp_f0 -= M_TAU_F;
                }

                sp74[i] = chrlvPathingCollisionRelated(self->prop, temp_f0, 1000.0f, 0, 0.0f, 1.0f);
            }

            for (i = 0; i < 8; i++)
            {
                sp44[i] = i;
            }

            /**
             * Selection sort.
            */
            for (i=0; i<7; i++)
            {
                index = i;

                for (j = i + 1; j < 8; j++)
                {
                    if (sp74[sp44[j]] < sp74[sp44[index]])
                    {
                        index = j;
                    }
                }

                j = sp44[i];
                sp44[i] = sp44[index];
                sp44[index] = j;
            }

            index = -1;
            if (sp74[0] < 490.0f)
            {
                if (sp74[sp44[4]] < 200.0f)
                {
                    index = 7;
                }
                else if ((sp44[0] == 0) || (sp44[1] == 0) || (sp44[2] == 0))
                {
                    if (((sp44[3] == 4) || (sp44[4] == 4)) && ((randomGetNext() % 3U) == 0))
                    {
                        if (sp44[3] == 4)
                        {
                            index = 3;
                        }
                        else
                        {
                            index = 4;
                        }
                    }
                    else
                    {
                        index = 5 + (randomGetNext() % 3U);
                    }
                }
                else if (((sp44[0] == 1) || (sp44[0] == 7)) && (sp44[5] != 0) && (sp44[6] != 0) && (sp44[7] != 0))
                {
                    index = 5 + (randomGetNext() % 3U);
                }
            }

            if (index >= 0)
            {
                i = sp44[index];
                temp_f0 = ((f32)i * M_TAU_F * 0.125f) + subroty;
                
                if (temp_f0 >= M_TAU_F)
                {
                    temp_f0 -= M_TAU_F;
                }
                
                check_set_actor_standing_still(self, 0x10, (s32) ((temp_f0 * M_U16_MAX_VALUE_F) / M_TAU_F));
            }
            else
            {
                self->act_stand.unk040 = 0;
            }
        }
    }
}



void chrlvTickKneel(ChrRecord *actor) {
    actor->sleep = 0;
}



/**
 * Address 0x7F02B4E8.
*/
void chrlvTickAnim(ChrRecord *self)
{
    s32 unused[1];

    if (self->act_init.padding[1] == 0)
    {
        f32 sp20 = objecthandlerGetModelField28(self->model);
        
        if (sub_GAME_7F06F5C4(self->model) <= sp20)
        {
            chrlvKneelingAnimationRelated(self);
        }
    }

    if (
        ((s32)objecthandlerGetModelAnim(self->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_sneeze])
        && (objecthandlerGetModelField28(self->model) >= 42.0f)
        && ((self->chrflags << 6) >= 0))
    {
        if (((D_80048380 & 1) == 0) && (chrGetDistanceToBond(self) < 800.0f))
        {
            sub_GAME_7F053A10(sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, 0x101, 0), &self->prop->pos);
        }

        self->chrflags |= 0x2000000;
    }

    if (((s32) self->sleep <= 0) && (self->act_init.padding[3] != 0))
    {
        self->sleep = (randomGetNext() % 5U) + 0xE;
    }
}



/**
 * Address 0x7F02B638.
*/
void chrlvTickSurrender(ChrRecord *self)
{
    Model *model;

    if ((s32) self->sleep <= 0)
    {
        model = self->model;
        self->sleep = 0x10;

        if (((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed_drop_weapon]) 
            && (objecthandlerGetModelField28(model) >= 80.0f))
        {
            coord3d sp30 = D_80030A44;

            f32 t = getsubroty(model);

            sp30.f[0] = -sinf(t);
            sp30.f[2] = -cosf(t);

            if (chrlvCall7F02982C(self->prop, &sp30, 20.0f) == 0)
            {
                modelSetAnimation(self->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 30.0f, 0.5f, 16.0f);
                modelSetAnimLooping(self->model, 30.0f, 16.0f);
            }
        }
    }
}



/**
 * Address 0x7F02B774.
*/
void chrlvTickDead(ChrRecord *self)
{
    if (self->act_init.padding[0] >= 0)
    {
        self->act_init.padding[0] += g_ClockTimer;

        if (self->act_init.padding[0] >= CHRLV_TICK_DEAD_CHECK)
        {
            self->hidden |= CHRHIDDEN_REMOVE;
        }
        else
        {
            self->fadealpha = (u8) ((s32) ((CHRLV_TICK_DEAD_CHECK - self->act_init.padding[0]) * 0xFF) / CHRLV_TICK_DEAD_CHECK);
        }

        return;
    }

    self->act_init.padding[0] = 0;
}




/**
 * @param self:
 * @param flag: shot/die flag. 0 == shot, else die.
 * 
 * Address 0x7F02B800.
*/
void chrlvIterateGuardSeeShotDie(ChrRecord *self, s32 flag)
{
    ChrRecord *guard;
    PropRecord *self_prop;
    f32 dx;
    f32 dz;
    f32 dy;
    s32 numguards;
    PropRecord *guard_prop;
    s32 i = 0;
    s32 alert_count = 0;

    numguards = get_numguards();

    /*
     * Maybe there's removed code in these if,elseif blocks? 
    */
    if (self->actiontype == ACT_ARGH)
    {
        i = self->act_init.padding[0];
    }
    else if (self->actiontype == ACT_DIE)
    {
        i = self->act_init.padding[0];
    }

    for (; i < numguards && alert_count < 4; i++)
    {
        guard = &ptr_guard_data[i];

        if (guard->model != NULL)
        {
            guard_prop = guard->prop;
            self_prop = self->prop;
            dx = guard_prop->pos.f[0] - self_prop->pos.f[0];
            dy = guard_prop->pos.f[1] - self_prop->pos.f[1];
            dz = guard_prop->pos.f[2] - self_prop->pos.f[2];

            if (((dx * dx) + (dy * dy) + (dz * dz)) < 4000000.0f)
            {
                alert_count++;

                if (chrlvMaybeSameRoom(guard, &self_prop->pos, self_prop->stan))
                {
                    if (flag == 0)
                    {
                        guard->chrseeshot = self->chrnum;
                    }
                    else
                    {
                        guard->chrseedie = self->chrnum;
                    }
                }
            }
        }
    }

    if (self->actiontype == ACT_ARGH)
    {
        self->act_init.padding[0] = i;
    }
    else if (self->actiontype == ACT_DIE)
    {
        self->act_init.padding[0] = i;
    }
}




/**
 * Address 0x7F02B9A4.
 * PD: void chrTickDie(struct chrdata *chr).
*/
void chrlvTickDie(ChrRecord *self)
{
    Model *model = self->model;

    ALSoundState * p;

    s16 body_hit_SFX[] = {0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85};

    static s32 thud_index = 0;

    if ((self->act_die.thudframe1 >= 0.0f) && (self->act_die.thudframe1 <= objecthandlerGetModelField28(model)))
    {
        p = sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, body_hit_SFX[thud_index], NULL);

        sub_GAME_7F053A10(p, &self->prop->pos);

        thud_index++;
        if (thud_index >= 0xB)
        {
            thud_index = 0;
        }

        self->act_die.thudframe1 = -1.0f;
    }

    if ((self->act_die.thudframe2 >= 0.0f) && (self->act_die.thudframe2 <= objecthandlerGetModelField28(model)))
    {
        p = sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, body_hit_SFX[thud_index], NULL);

        sub_GAME_7F053A10(p, &self->prop->pos);

        thud_index++;
        if (thud_index >= 0xB)
        {
            thud_index = 0;
        }

        self->act_die.thudframe2 = -1.0f;
    }

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_left_leg])
        {
            modelSetAnimation(
                model,
                (void*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data),
                objecthandlerGetModelGunhand(model) == 0,
                50.0f,
                0.3f,
                (((u16*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data))[2] - 1.0f) - 50.0f);

            modelSetAnimSpeed(model, 0.5f, (((u16*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data))[2] - 1.0f) - 50.0f);

            return;
        }

        chrlvActorFadeAway(self);
    }

    chrlvIterateGuardSeeShotDie(self, 1);
}




/**
 * Address 0x7F02BC80.
*/
void chrlvTickArgh(ChrRecord *self)
{
    Model *model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(self);

        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_left_leg])
        {
            chrlvIdleAnimationRelated7F023E14(self, 26.0f);
        }
        else
        {
            chrlvKneelingAnimationRelated7F023E48(self);
        }
    }

    chrlvIterateGuardSeeShotDie(self, 0);
}



/**
 * Address 0x7F02BD20.
*/
void chrlvTickPreArgh(ChrRecord *self)
{
    Model *model;
    coord3d sp30;

    model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        sp30.f[0] = self->act_preargh.pos.f[0];
        sp30.f[1] = self->act_preargh.pos.f[1];
        sp30.f[2] = self->act_preargh.pos.f[2];
        triggered_on_shot_hit(self, &sp30, self->act_preargh.unk038, self->act_preargh.unk03c, self->act_preargh.unk040);
    }
}




/**
 * @see chrlvTickJumpout
 * @see chrlvTickTest
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BDA4.
*/
void chrlvTickSidestep(ChrRecord *self)
{
    Model *model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(self);
        chrlvIdleAnimationRelated7F023E14(self, 10.0f);
    }
}


/**
 * @see chrlvTickSidestep
 * @see chrlvTickTest
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BE00.
*/
void chrlvTickJumpout(ChrRecord *self)
{
    Model *model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(self);
        chrlvKneelingAnimationRelated7F023E48(self);
    }
}




/**
 * @see chrlvTickSidestep
 * @see chrlvTickJumpout
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BE58.
*/
void chrlvTickTest(ChrRecord *self)
{
    Model *model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvKneelingAnimationRelated(self);
    }
}



/**
 * @see chrlvTickSidestep
 * @see chrlvTickJumpout
 * @see chrlvTickTest
 * 
 * Address 0x7F02BEA8.
*/
void chrlvTickStartAlarm(ChrRecord *self)
{
    Model *model = self->model;

    // bug/typo, should be 50.0f on VERSION_EU
    if (objecthandlerGetModelField28(model) >= 60.0f)
    {
        alarmActivate();
    }

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvKneelingAnimationRelated7F023E48(self);
    }
}



/**
 * Address 0x7F02BF24.
*/
void chrlvTickSurprised(ChrRecord *self)
{
    Model *model = self->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed])
        {
            chrlvIdleAnimationRelated7F023E14(self, 26.0f);
        }
        else if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_spotting_bond])
        {
            chrlvIdleAnimationRelated7F023E14(self, 26.0f);
        }
        else
        {
            chrlvKneelingAnimationRelated7F023E48(self);
        }
    }
}



#ifdef NONMATCHING
/**
 * Address 0x7F02BFE4.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: no
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: ChrRecord needs some changes, but not sure what to figure out the weird section below.
*/
void sub_GAME_7F02BFE4(ChrRecord *self, s32 arg1, s32 arg2)
{
    PropRecord *prop;
    u8 sp33;
    u16 sp30;
    s32 phi_a1;
    ChrRecord *temp_v1;
    s32 unused[1];
    s32 sp28;
    ALSoundState *phi_a2;

    prop = chrGetEquippedWeaponProp(self, arg1);
    temp_v1 = prop->chr;
    phi_a1 = 0;

    sp33 = bondwalkItemGetSoundTriggerRate((s32) temp_v1->act_attack.attack_item);
    sp30 = bondwalkItemGetSound((s32) temp_v1->act_attack.attack_item);

    if (arg2 != 0)
    {
        if ((s32) sp33 > 0)
        {
            if (((self->hidden & CHRHIDDEN_FIRE_TRACER) == 0) && self->field_178[arg1] < g_GlobalTimer)
            {
                phi_a1 = 1;
            }
        }
        else
        {
            phi_a1 = 1;
        }
    }

    if (phi_a1 != 0)
    {
        // begin decomp problem area.
        // I can't make sense of this with the current ChrRecord definition.

        // if (self->unk160 != NULL)
        // {
        //     if (sndGetPlayingState(self->unk160[arg1]) != AL_STOPPED)
        //     {
        //         sndDeactivate(self->unk160[arg1]);
        //     }
        // }

        // if (self->unk164[arg1] != NULL)
        // {
        //     if (sndGetPlayingState(self->unk164[arg1]) != AL_STOPPED)
        //     {
        //         sndDeactivate(self->unk164[arg1]);
        //     }
        // }
        
        // if (sp30 != 0)
        // {
        //     phi_a2 = NULL;
        //     if (self->unk160[arg1] == NULL)
        //     {
        //         phi_a2 = self->unk160[arg1];
        //     }
        //     else if (self->unk164[arg1] == NULL)
        //     {
        //         phi_a2 = self->unk164[arg1];
        //     }

        //     if (phi_a2 != NULL)
        //     {
        //         sndPlaySfx(g_musicSfxBufferPtr, (s16) sp30, phi_a2);
        //         sub_GAME_7F053A10(phi_a2, &self->prop->pos);

        //         self->field_178[arg1] = g_GlobalTimer + sp33;
        //         self->hidden |= 0x80;
        //     }
        // }
        // end decomp problem area.
    }
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BFE4
/* 060B14 7F02BFE4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 060B18 7F02BFE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 060B1C 7F02BFEC AFB00018 */  sw    $s0, 0x18($sp)
/* 060B20 7F02BFF0 00808025 */  move  $s0, $a0
/* 060B24 7F02BFF4 AFA50044 */  sw    $a1, 0x44($sp)
/* 060B28 7F02BFF8 0FC08C0B */  jal   chrGetEquippedWeaponProp
/* 060B2C 7F02BFFC AFA60048 */   sw    $a2, 0x48($sp)
/* 060B30 7F02C000 8C430004 */  lw    $v1, 4($v0)
/* 060B34 7F02C004 80640080 */  lb    $a0, 0x80($v1)
/* 060B38 7F02C008 AFA00034 */  sw    $zero, 0x34($sp)
/* 060B3C 7F02C00C 0FC177FC */  jal   bondwalkItemGetSoundTriggerRate
/* 060B40 7F02C010 AFA30038 */   sw    $v1, 0x38($sp)
/* 060B44 7F02C014 8FA30038 */  lw    $v1, 0x38($sp)
/* 060B48 7F02C018 A3A20033 */  sb    $v0, 0x33($sp)
/* 060B4C 7F02C01C 0FC17805 */  jal   bondwalkItemGetSound
/* 060B50 7F02C020 80640080 */   lb    $a0, 0x80($v1)
/* 060B54 7F02C024 8FAE0048 */  lw    $t6, 0x48($sp)
/* 060B58 7F02C028 8FA50034 */  lw    $a1, 0x34($sp)
/* 060B5C 7F02C02C A7A20030 */  sh    $v0, 0x30($sp)
/* 060B60 7F02C030 11C00012 */  beqz  $t6, .L7F02C07C
/* 060B64 7F02C034 93AF0033 */   lbu   $t7, 0x33($sp)
/* 060B68 7F02C038 59E00010 */  blezl $t7, .L7F02C07C
/* 060B6C 7F02C03C 24050001 */   li    $a1, 1
/* 060B70 7F02C040 96180012 */  lhu   $t8, 0x12($s0)
/* 060B74 7F02C044 8FA80044 */  lw    $t0, 0x44($sp)
/* 060B78 7F02C048 3C0C8005 */  lui   $t4, %hi(g_GlobalTimer) 
/* 060B7C 7F02C04C 33190080 */  andi  $t9, $t8, 0x80
/* 060B80 7F02C050 1720000A */  bnez  $t9, .L7F02C07C
/* 060B84 7F02C054 00084880 */   sll   $t1, $t0, 2
/* 060B88 7F02C058 02095021 */  addu  $t2, $s0, $t1
/* 060B8C 7F02C05C 8D4B0178 */  lw    $t3, 0x178($t2)
/* 060B90 7F02C060 8D8C837C */  lw    $t4, %lo(g_GlobalTimer)($t4)
/* 060B94 7F02C064 016C082A */  slt   $at, $t3, $t4
/* 060B98 7F02C068 10200004 */  beqz  $at, .L7F02C07C
/* 060B9C 7F02C06C 00000000 */   nop   
/* 060BA0 7F02C070 10000002 */  b     .L7F02C07C
/* 060BA4 7F02C074 24050001 */   li    $a1, 1
/* 060BA8 7F02C078 24050001 */  li    $a1, 1
.L7F02C07C:
/* 060BAC 7F02C07C 10A0003F */  beqz  $a1, .L7F02C17C
/* 060BB0 7F02C080 8FAD0044 */   lw    $t5, 0x44($sp)
/* 060BB4 7F02C084 000D70C0 */  sll   $t6, $t5, 3
/* 060BB8 7F02C088 020E1821 */  addu  $v1, $s0, $t6
/* 060BBC 7F02C08C 8C640168 */  lw    $a0, 0x168($v1)
/* 060BC0 7F02C090 5080000A */  beql  $a0, $zero, .L7F02C0BC
/* 060BC4 7F02C094 8C64016C */   lw    $a0, 0x16c($v1)
/* 060BC8 7F02C098 0C00237C */  jal   sndGetPlayingState
/* 060BCC 7F02C09C AFA30028 */   sw    $v1, 0x28($sp)
/* 060BD0 7F02C0A0 10400005 */  beqz  $v0, .L7F02C0B8
/* 060BD4 7F02C0A4 8FA30028 */   lw    $v1, 0x28($sp)
/* 060BD8 7F02C0A8 8C640168 */  lw    $a0, 0x168($v1)
/* 060BDC 7F02C0AC 0C002408 */  jal   sndDeactivate
/* 060BE0 7F02C0B0 AFA30028 */   sw    $v1, 0x28($sp)
/* 060BE4 7F02C0B4 8FA30028 */  lw    $v1, 0x28($sp)
.L7F02C0B8:
/* 060BE8 7F02C0B8 8C64016C */  lw    $a0, 0x16c($v1)
.L7F02C0BC:
/* 060BEC 7F02C0BC 5080000A */  beql  $a0, $zero, .L7F02C0E8
/* 060BF0 7F02C0C0 97AF0030 */   lhu   $t7, 0x30($sp)
/* 060BF4 7F02C0C4 0C00237C */  jal   sndGetPlayingState
/* 060BF8 7F02C0C8 AFA30028 */   sw    $v1, 0x28($sp)
/* 060BFC 7F02C0CC 10400005 */  beqz  $v0, .L7F02C0E4
/* 060C00 7F02C0D0 8FA30028 */   lw    $v1, 0x28($sp)
/* 060C04 7F02C0D4 8C64016C */  lw    $a0, 0x16c($v1)
/* 060C08 7F02C0D8 0C002408 */  jal   sndDeactivate
/* 060C0C 7F02C0DC AFA30028 */   sw    $v1, 0x28($sp)
/* 060C10 7F02C0E0 8FA30028 */  lw    $v1, 0x28($sp)
.L7F02C0E4:
/* 060C14 7F02C0E4 97AF0030 */  lhu   $t7, 0x30($sp)
.L7F02C0E8:
/* 060C18 7F02C0E8 51E00025 */  beql  $t7, $zero, .L7F02C180
/* 060C1C 7F02C0EC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 060C20 7F02C0F0 8C780168 */  lw    $t8, 0x168($v1)
/* 060C24 7F02C0F4 00003025 */  move  $a2, $zero
/* 060C28 7F02C0F8 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 060C2C 7F02C0FC 17000003 */  bnez  $t8, .L7F02C10C
/* 060C30 7F02C100 87A50030 */   lh    $a1, 0x30($sp)
/* 060C34 7F02C104 10000005 */  b     .L7F02C11C
/* 060C38 7F02C108 24660168 */   addiu $a2, $v1, 0x168
.L7F02C10C:
/* 060C3C 7F02C10C 8C79016C */  lw    $t9, 0x16c($v1)
/* 060C40 7F02C110 17200002 */  bnez  $t9, .L7F02C11C
/* 060C44 7F02C114 00000000 */   nop   
/* 060C48 7F02C118 2466016C */  addiu $a2, $v1, 0x16c
.L7F02C11C:
/* 060C4C 7F02C11C 10C00017 */  beqz  $a2, .L7F02C17C
/* 060C50 7F02C120 93A80033 */   lbu   $t0, 0x33($sp)
/* 060C54 7F02C124 8FA90044 */  lw    $t1, 0x44($sp)
/* 060C58 7F02C128 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 060C5C 7F02C12C AFA80028 */  sw    $t0, 0x28($sp)
/* 060C60 7F02C130 00095080 */  sll   $t2, $t1, 2
/* 060C64 7F02C134 020A5821 */  addu  $t3, $s0, $t2
/* 060C68 7F02C138 AFAB0024 */  sw    $t3, 0x24($sp)
/* 060C6C 7F02C13C 0C002382 */  jal   sndPlaySfx
/* 060C70 7F02C140 AFA6002C */   sw    $a2, 0x2c($sp)
/* 060C74 7F02C144 8FA6002C */  lw    $a2, 0x2c($sp)
/* 060C78 7F02C148 8E050018 */  lw    $a1, 0x18($s0)
/* 060C7C 7F02C14C 8CC40000 */  lw    $a0, ($a2)
/* 060C80 7F02C150 0FC14E84 */  jal   sub_GAME_7F053A10
/* 060C84 7F02C154 24A50008 */   addiu $a1, $a1, 8
/* 060C88 7F02C158 3C0C8005 */  lui   $t4, %hi(g_GlobalTimer) 
/* 060C8C 7F02C15C 8D8C837C */  lw    $t4, %lo(g_GlobalTimer)($t4)
/* 060C90 7F02C160 8FAD0028 */  lw    $t5, 0x28($sp)
/* 060C94 7F02C164 8FAF0024 */  lw    $t7, 0x24($sp)
/* 060C98 7F02C168 018D7021 */  addu  $t6, $t4, $t5
/* 060C9C 7F02C16C ADEE0178 */  sw    $t6, 0x178($t7)
/* 060CA0 7F02C170 96180012 */  lhu   $t8, 0x12($s0)
/* 060CA4 7F02C174 37190080 */  ori   $t9, $t8, 0x80
/* 060CA8 7F02C178 A6190012 */  sh    $t9, 0x12($s0)
.L7F02C17C:
/* 060CAC 7F02C17C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F02C180:
/* 060CB0 7F02C180 8FB00018 */  lw    $s0, 0x18($sp)
/* 060CB4 7F02C184 27BD0040 */  addiu $sp, $sp, 0x40
/* 060CB8 7F02C188 03E00008 */  jr    $ra
/* 060CBC 7F02C18C 00000000 */   nop   
)
#endif


/**
 * Address 0x7F02C190.
*/
f32 chrlvGetSubrotySideback(ChrRecord *self)
{
    Model *model;
    f32 phi_f12;
    f32 ret;

    model = self->model;
    ret = getsubroty(model) + self->aimsideback;
    phi_f12 = 0.0f;

    if (ret >= M_TAU_F)
    {
        ret = ret - M_TAU_F;
    }
    else if (ret < 0.0f)
    {
        ret = ret + M_TAU_F;
    }

    if ((self->actiontype == ACT_ATTACK) || (self->actiontype == ACT_ATTACKROLL))
    {
        phi_f12 = self->act_attack.animfloats->anonymous_3;
    }
    else if (self->actiontype == ACT_BONDMULTI)
    {
        if (self->act_bondmulti.unk2c != NULL)
        {
            phi_f12 = self->act_bondmulti.unk2c[3];
        }
    }

    if (phi_f12 != 0.0f)
    {
        if (self->model->gunhand != GUNRIGHT)
        {
            phi_f12 = M_TAU_F - phi_f12;
        }

        ret = ret + phi_f12;

        if (ret >= M_TAU_F)
        {
            ret = ret - M_TAU_F;
        }
    }

    return ret;
}




/**
 * Address 0x7F02C27C.
*/
f32 sub_GAME_7F02C27C(ChrRecord *self)
{
    f32 temp_f2;

    temp_f2 = self->aimuprshoulder + self->aimupback;
    if (temp_f2 < 0.0f)
    {
        temp_f2 = temp_f2 + M_TAU_F;
    }

    return temp_f2;
}



/**
 * Address 0x7F02C2B0.
*/
s32 chrlvSetSubroty(ChrRecord *self, s32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    Model *model;
    f32 sp28; //sp40
    f32 dist;
    f32 roty;
    s32 unused[1];
    f32 temp_f14;

    if (arg1 != 2)
    {
        model = self->model;
        sp28 = objecthandlerGetModelField28(model);
        roty = getsubroty(model);

#if defined(BUGFIX_R1)
        temp_f14 = 0.06283186f * arg3 * g_JP_GlobalTimerDelta * model->unka4;
#else /* VERSION_US */
        temp_f14 = 0.06283186f * arg3 * g_GlobalTimerDelta * model->unka4;
#endif

        if (self->actiontype == ACT_ATTACK)
        {
            dist = chrlvDistanceToChrRelated(self, self->act_attack.attacktype, self->act_attack.entityid);
        }
        else if (self->actiontype == ACT_STAND)
        {
            dist = chrlvDistanceToChrRelated(self, self->act_stand.face_entitytype, self->act_stand.face_entityid);
        }
        else
        {
            PropRecord* p;
            p = get_curplayer_positiondata();
            dist = get_distance_actor_to_position(self, &p->pos);
        }

        dist = dist - arg4;

        if (dist < 0.0f)
        {
            dist = dist + M_TAU_F;
        }

        if ((dist < temp_f14) || ((M_TAU_F - temp_f14) < dist))
        {
            roty += dist;
            if (roty >= M_TAU_F)
            {
                roty -= M_TAU_F;
            }

            setsubroty(model, roty);
            arg1 = 3;
        }
        else if (dist < M_PI_F)
        {
            roty += temp_f14;
            if (roty >= M_TAU_F)
            {
                roty -= M_TAU_F;
            }

            setsubroty(model, roty);
        }
        else
        {
            roty -= temp_f14;
            
            if (roty < 0.0f)
            {
                roty += M_TAU_F;
            }

            setsubroty(model, roty);
        }

        if (arg2 <= sp28)
        {
            arg1 = 2;
        }
    }

    return arg1;
}




/**
 * @param self:
 * @param arg1:
 * @param arg2:
 * @param arg3:
 * @param arg4:
 * 
 * Address 0x7F02C4C0.
*/
s32 chrlvUpdateAimendsideback(ChrRecord *self, struct weapon_firing_animation_table *arg1, s32 arg2, s32 arg3, f32 arg4)
{
    f32 sp164; // sp356
    f32 calc_aimendsideback; // sp352
    u32 attack_type; // sp348
    s32 entity_id; // sp344
    s32 ret; // sp340
    f32 dx; // sp336
    f32 dy; // sp332
    f32 dz; // sp328
    f32 dxdydz_square; // sp324
    Model *self_model; 
    PropRecord *self_prop; // sp316
    s32 seen_bond_flag; // sp312
    coord3d *current_player_pos; //sp308
    f32 ducking_height; // sp304
    StandTile *pstan; // sp300
    coord3d sp120; // sp288
    PropRecord *player_prop;
    f32 subroty; // sp280

    /////////////////////

    ret = 1;
    sp164 = 0.0f;
    attack_type = TARGET_BOND;
    entity_id = 0;
    calc_aimendsideback = 0.0f;

    if (self->actiontype == ACT_ATTACK)
    {
        attack_type = self->act_attack.attacktype;
        entity_id = self->act_attack.entityid;
    }
    else if (self->actiontype == ACT_STAND)
    {
        attack_type = self->act_stand.face_entitytype;
        entity_id = self->act_stand.face_entityid;
    }
    
    if ((attack_type & TARGET_FRONT_OF_CHR) == 0)
    {
        player_prop = get_curplayer_positiondata();
        self_prop = self->prop;
        current_player_pos = &player_prop->pos;

        dx = player_prop->pos.f[0] - self_prop->pos.f[0];
        dy = player_prop->pos.f[1] - self_prop->pos.f[1];
        dz = player_prop->pos.f[2] - self_prop->pos.f[2];

        dxdydz_square = (dx * dx) + (dy * dy) + (dz * dz);

        if (attack_type & TARGET_BOND)
        {
            if ((attack_type & TARGET_DONTTURN) != 0)
            {
                seen_bond_flag = 1;
            }
            else
            {
                seen_bond_flag = chrCanSeeBond(self);
            }
        }
        else
        {
            seen_bond_flag = 1;
        }

        if (attack_type & TARGET_BOND > 0)
        {
            ducking_height = bondviewGetPlayerDuckingHeightRelated(g_CurrentPlayer);
            if ((self->chrflags & 0x20) != 0)
            {
                if (((dx * dx) + (dy * dy) + (dz * dz)) < 160000.0f)
                {
                    if (self_prop->pos.f[1] < (current_player_pos->f[1] - (2.0f * ducking_height)))
                    {
                        dy -= ducking_height * (0.55f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                    }
                    else if ((current_player_pos->f[1] - (ducking_height * 0.5f)) < self_prop->pos.f[1])
                    {
                        dy -= ducking_height * (0.15f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                    }
                    else
                    {
                        dy = (((f32) (u32)randomGetNext() * (1.0f / UINT_MAX) * 0.1f * arg4) + 1.0f) * 40.0f;
                    }
                }
                else
                {
                    dy += ducking_height * (0.025f - (0.05f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
            }
            else if (((dx * dx) + (dy * dy) + (dz * dz)) > 1000000.0f)
            {
                if (((u32)randomGetNext() % 3U) == 0)
                {
                    dy += ducking_height * (0.05f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else
                {
                    dy -= ducking_height * (0.05f + (0.55f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
            }
            else
            {
                if (self_prop->pos.f[1] < (current_player_pos->f[1] - ducking_height))
                {
                    dy -= ducking_height * (0.55f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else if ((current_player_pos->f[1] - (ducking_height * 0.5f)) < self_prop->pos.f[1])
                {
                    dy -= ducking_height * (0.15f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else
                {
                    dy = (((f32) (u32)randomGetNext() * (1.0f / UINT_MAX) * 0.1f * arg4) - 0.05f) * ducking_height;
                }
            }
        }
        else
        {
            getsuboffset(self->model, &sp120);
            current_player_pos = chrlvGetChrOrPresetLocation(self, attack_type, entity_id, &pstan);
            dx = current_player_pos->f[0] - sp120.f[0];
            dy = current_player_pos->f[1] - sp120.f[1];
            dz = current_player_pos->f[2] - sp120.f[2];
        }

        if ((attack_type & 0x100) == 0)
        {
            f32 sr = sqrtf((dx * dx) + (dz * dz));
            sp164 = atan2f(dy, sr);

            if (sp164 >= M_PI_F)
            {
                sp164 = sp164 - M_TAU_F;
            }
        }

        if (seen_bond_flag)
        {
            Model *weapon_prop_model; // sp272
            coord3d sp104; // sp260
            PropRecord *weapon_prop;
            struct modeldata_root *temp_v0_4;
            Mtxf spBC; // sp188
            f32 *spB8;  // sp184
            coord3d spAC; //sp172
            s32 intersect_flag; // sp140
            Mtxf sp68;
            coord3d sp5C; // sp92
            coord3d sp50; // sp80
            coord3d sp44; // sp68
            Mtxf *temp_a0;
            struct ObjectRecord *obj;
            f32 t1;
            
            ////////////////////////////////////////////

            subroty = chrlvGetSubrotySideback(self);
            
            if (arg3)
            {
                weapon_prop = chrGetEquippedWeaponProp(self, GUNRIGHT);
            }
            else
            {
                weapon_prop = chrGetEquippedWeaponProp(self, GUNLEFT);
            }

            // This if block is a slight modification of @see sub_GAME_7F02D630.
            if ((weapon_prop != NULL) && (weapon_prop->flags & 2) && (dxdydz_square < 1000000.0f))
            {
                obj = weapon_prop->obj;
                weapon_prop_model = obj->model;
                intersect_flag = 0;
                
                if (weapon_prop_model->obj->Switches[0])
                {
                    temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[0], 0);
                    spB8 = weapon_prop_model->obj->Switches[0]->Data;
                    sub_GAME_7F058E78(temp_a0, &spBC);

                    matrix_4x4_multiply_homogeneous_in_place(currentPlayerGetMatrix10EC(), &spBC);

                    spAC.f[0] = spB8[0];
                    spAC.f[1] = spB8[1];
                    spAC.f[2] = spB8[2];

                    matrix_4x4_transform_vector_in_place(&spBC, &spAC);

                    sp104.f[0] = spAC.f[0];
                    sp104.f[1] = spAC.f[1];
                    sp104.f[2] = spAC.f[2];

                    intersect_flag = 1;
                }
                else if (weapon_prop_model->obj->Switches[1])
                {
                    temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[1], 0);
                    sub_GAME_7F058E78(temp_a0, &sp68);
                    matrix_4x4_multiply_homogeneous_in_place(currentPlayerGetMatrix10EC(), &sp68);
                    sp104.f[0] = sp68.m[3][0];
                    sp104.f[1] = sp68.m[3][1];
                    sp104.f[2] = sp68.m[3][2];

                    intersect_flag = 1;
                }

                if (intersect_flag != 0)
                {
                    sp50.f[0] = sinf(subroty);
                    sp50.f[1] = 0.0f;
                    sp50.f[2] = cosf(subroty);
                    sp44.f[0] = self_prop->pos.f[0] - dz;
                    sp44.f[1] = self_prop->pos.f[1];
                    sp44.f[2] = self_prop->pos.f[2] + dx;
                    chrlvLineLineIntersection(&self_prop->pos, &sp44, &sp104, &sp50, &sp5C);
                    dx = current_player_pos->f[0] - sp5C.f[0];
                    dz = current_player_pos->f[2] - sp5C.f[2];
                }
            }

            t1 = atan2f(dx, dz);

            calc_aimendsideback = t1 - subroty;
            if (t1 < subroty)
            {
                calc_aimendsideback = t1 - subroty + M_TAU_F;
            }

            temp_v0_4 = (struct modeldata_root*)extract_id_from_object_structure_microcode(self->model, self->model->obj->RootNode);

            if (temp_v0_4->unk5c > 0.0f)
            {
                calc_aimendsideback = calc_aimendsideback - (temp_v0_4->unk5c * temp_v0_4->unk58);

                if (calc_aimendsideback < 0.0f)
                {
                    calc_aimendsideback = calc_aimendsideback + M_TAU_F;
                }

                if (calc_aimendsideback >= M_TAU_F)
                {
                    calc_aimendsideback = calc_aimendsideback - M_TAU_F;
                }
            }

            if ((attack_type & 1) && ((attack_type & 0x60) == 0))
            {
                t1 = (((f32) ((s32) ((s32) ((f32) g_GlobalTimer * self->model->unka4) + self->chrnum) % 60) * M_TAU_F) / 60.0f);
                t1 = sinf(t1) * (chrlvGetAimLimitAngle(dxdydz_square) * 0.5f);
                calc_aimendsideback += t1;

                if (calc_aimendsideback < 0.0f)
                {
                    calc_aimendsideback = calc_aimendsideback + M_TAU_F;
                }

                if (calc_aimendsideback >= M_TAU_F)
                {
                    calc_aimendsideback = calc_aimendsideback - M_TAU_F;
                }
            }

            if (calc_aimendsideback >= M_PI_F)
            {
                calc_aimendsideback = calc_aimendsideback - M_TAU_F;
            }

            calc_aimendsideback += self->aimsideback;

            if (self->model->gunhand != GUNRIGHT)
            {
                if (calc_aimendsideback < -arg1->anonymous_14)
                {
                    calc_aimendsideback = -arg1->anonymous_14;
                    ret = 0;
                }
                else if (-arg1->anonymous_15 < calc_aimendsideback)
                {
                    calc_aimendsideback = -arg1->anonymous_15;
                    ret = 0;
                }
            }
            else
            {
                if (arg1->anonymous_14 < calc_aimendsideback)
                {
                    calc_aimendsideback = arg1->anonymous_14;
                    ret = 0;
                }
                else if (calc_aimendsideback < arg1->anonymous_15)
                {
                    calc_aimendsideback = arg1->anonymous_15;
                    ret = 0;
                }
            }
        }
    }

    chrlvUpdateAimendbackShoulders(self, arg1, arg2, arg3, sp164);
    self->aimendsideback = calc_aimendsideback;
    self->aimendcount = 0xA;

    return ret;
}




/**
 * Calculates and sets chr aimendrshoulder, aimendlshoulder, and aimendback.
 * rshoulder defaults to 0.0f, lshoulder defaults to @param next.
 * 
 * @param self:
 * @param arg1: todo/fixme/hack: unsure of arg1 type.
 * @param same: When set, both shoulders will receive lshoulder value. Only
 *     applies with @param swap is set.
 * @param swap: When set, aimendrshoulder will get the calculated lshoulder value,
 *     and aimendlshoulder will get the rshoulder value. If both @param swap and
 *     @param same is set they will both be set to lshoulder value.
 * @param next: Starting aimendlshoulder value.
 * 
 * Address 0x7F02D048.
*/
void chrlvUpdateAimendbackShoulders(ChrRecord *self, void *arg1, s32 same, s32 swap, f32 next)
{
    f32 next_lshoulder;
    f32 next_rshoulder;
    f32 next_aimendback;

    next_rshoulder = 0.0f;
    next_aimendback = 0.0f;
    next_lshoulder = next;

    if (arg1 != NULL)
    {
        if (((f32*)arg1)[12] < next)
        {
            next_aimendback = next - ((f32*)arg1)[12];
            next_lshoulder = ((f32*)arg1)[12];
        }

        else if (next < ((f32*)arg1)[13])
        {
            next_aimendback = next - ((f32*)arg1)[13];
            next_lshoulder = ((f32*)arg1)[13];
        }

        if (next_lshoulder > 0.0f)
        {
            next_rshoulder = ((f32*)arg1)[16] * next_lshoulder;
        }
        else
        {
            next_rshoulder = ((f32*)arg1)[17] * next_lshoulder;
        }
    }

    if (swap != 0)
    {
        self->aimendrshoulder = next_lshoulder;

        if (same != 0)
        {
            self->aimendlshoulder = next_lshoulder;
        }
        else
        {
            self->aimendlshoulder = next_rshoulder;
        }
    }
    else
    {
        self->aimendrshoulder = next_rshoulder;
        self->aimendlshoulder = next_lshoulder;
    }

    self->aimendback = next_aimendback;
}





/**
 * Address 0x7F02D0F8.
*/
void chrlvResetAimend(ChrRecord *self)
{
    self->aimendcount = 0xA;
    self->aimendrshoulder = 0.0f;
    self->aimendlshoulder = 0.0f;
    self->aimendback = 0.0f;
    self->aimendsideback = 0.0f;
}



/**
 * Address 0x7F02D118.
*/
void sub_GAME_7F02D118(ChrRecord *self, s32 hand, s32 arg2)
{
    PropRecord *temp_v0;

    temp_v0 = chrGetEquippedWeaponProp(self, hand);

    if (temp_v0 != NULL)
    {
        sub_GAME_7F052574(temp_v0, arg2);
    }
}



/**
 * Unreferenced.
 * 
 * Address 0x7F02D148.
*/
s32 sub_GAME_7F02D148(ChrRecord *self, s32 hand)
{
    PropRecord *temp_v0;

    temp_v0 = chrGetEquippedWeaponProp(self, hand);

    if (temp_v0 != NULL)
    {
        return sub_GAME_7F052604(temp_v0);
    }

    return 0;
}


/**
 * Address 0x7F02D184.
*/
void sub_GAME_7F02D184(ChrRecord *self)
{
    sub_GAME_7F02D118(self, GUNRIGHT, 0);
    sub_GAME_7F02D118(self, GUNLEFT, 0);
    chrlvResetAimend(self);
}


/**
 * Address 0x7F02D1C4.
*/
void chrlvToggleHiddenRelated(ChrRecord *self, s32 hand, s32 arg2)
{
    if (arg2 != 0)
    {
        if (hand == GUNLEFT)
        {
            self->hidden |= CHRHIDDEN_FIRE_WEAPON_LEFT;
        }
        else
        {
            self->hidden |= CHRHIDDEN_FIRE_WEAPON_RIGHT;
        }
    }
    else if (hand == GUNLEFT)
    {
        self->hidden &= 0xFFFB; // CHRHIDDEN_FIRE_WEAPON_LEFT
    }
    else
    {
        self->hidden &= 0xFFF7; // CHRHIDDEN_FIRE_WEAPON_RIGHT
    }

    if (arg2 == 0)
    {
        sub_GAME_7F02D118(self, hand, 0);
    }
}




/**
 * Address 0x7F02D244.
*/
f32 chrlvGetAimLimitAngle(f32 sqdist)
{
    if (sqdist > (1600.0f * 1600.0f))
    {
        return (M_PI_F / 167.5f);
    }

    if (sqdist > (800.0f * 800.0f))
    {
        return (M_PI_F / 83.5f);
    }

    if (sqdist > (400.0f * 400.0f))
    {
        return (M_PI_F / 42.0f);
    }

    if (sqdist > (200.0f * 200.0f))
    {
        return (M_PI_F / 21.0f);
    }

    return (M_PI_F / 12.5f);
}



/**
 * @param arg0:
 * @param arg1: out parameter. bool. Whether or not self has correct line of site to hit player.
 * @param arg2: out parameter. bool. True if damage done, false otherwise.
 * @param item: weapon doing damage
 * 
 * Address 0x7F02D2E4.
*/
void chrlvUpdateShotbondsum(ChrRecord *self, s32 *arg1, s32 *arg2, ITEM_IDS item)
{
    f32 limit_angle;
    f32 dxdydz_square;
    f32 dx; // sp84
    f32 dy; // sp80
    f32 dz; // sp76
    f32 atan; // sp72
    f32 subroty; // sp68
    f32 phi_f2; // sp64
    PropRecord *player_prop;
    f32 temp_f0_3;
    PropRecord *self_prop;
    f32 t2; // sp48
    f32 phi_f2_4; // sp44
    s32 padding; // unused
    s32 phi_v1;

    player_prop = get_curplayer_positiondata();
    self_prop = self->prop;

    dx = player_prop->pos.f[0] - self_prop->pos.f[0];
    dy = player_prop->pos.f[1] - self_prop->pos.f[1];
    dz = player_prop->pos.f[2] - self_prop->pos.f[2];
    
    atan = atan2f(dx, dz);
    subroty = chrlvGetSubrotySideback(self);
    phi_f2 = atan - subroty;
    dxdydz_square = (dx * dx) + (dy * dy) + (dz * dz);
    
    limit_angle = chrlvGetAimLimitAngle(dxdydz_square);

    if (phi_f2 < 0.0f)
    {
        phi_f2 += M_TAU_F;
    }

    phi_v1 = (phi_f2 < limit_angle);

    if ((phi_f2 < limit_angle) == 0)
    {
        phi_v1 = ((M_TAU_F - limit_angle) < phi_f2);
    }

    *arg1 = phi_v1;
    *arg2 = 0;

    if ((bondviewGetIfCurrentPlayerDamageShowTime() == 0) && (phi_v1 != 0))
    {
        temp_f0_3 = sqrtf(dxdydz_square);

#if defined(VERSION_JP)
        phi_f2_4 = 0.16f * g_JP_GlobalTimerDelta;
#else
        phi_f2_4 = 0.16f * g_GlobalTimerDelta;
#endif

        if (temp_f0_3 > 300.0f)
        {
            phi_f2_4 *= (300.0f / temp_f0_3);
        }

        if ((s32) self->accuracyrating > 0)
        {
            phi_f2_4 *= (1.0f + ((f32) self->accuracyrating / 10.0f));
        }
        else if ((s32) self->accuracyrating < 0)
        {
            if ((s32) self->accuracyrating < -0x63)
            {
                phi_f2_4 = 0.0f;
            }
            else
            {
                phi_f2_4 *= ((f32) (self->accuracyrating + 0x64) / 100.0f);
            }
        }

        if (get_007_accuracy_mod() <= 1.0f)
        {
            phi_f2_4 *= get_007_accuracy_mod();
        }
        else
        {
            phi_f2_4 *= (9.0f / (10.001f - get_007_accuracy_mod()));
        }

        phi_f2_4 *= g_AiAccuracyModifier;

        if (bondwalkItemGetAutomaticFiringRate(item) <= 0)
        {
            phi_f2_4 *= 2.0f;
        }

        if ((item == ITEM_SHOTGUN) || (item == ITEM_AUTOSHOT))
        {
            phi_f2_4 *= 2.0f;
        }

        self->shotbondsum += phi_f2_4;

        if (self->shotbondsum >= 1.0f)
        {
            t2 = (0.125f * bondwalkItemGetDestructionAmount(item) * g_AiDamageModifier) * get_007_damage_mod();

            if ((item == ITEM_SHOTGUN) || (item == ITEM_AUTOSHOT))
            {
                t2 *= 3.0f;
            }

            bondviewCallRecordDamageKills(t2, subroty, -1, 1);

            self->shotbondsum = 0.0f;

            if (bondviewGetIfCurrentPlayerDamageShowTime() != 0)
            {
                *arg2 = 1;
            }
        }
    }
}


/**
 * Slight modification of a part of @see chrlvUpdateAimendsideback.
 * 
 * Address 0x7F02D630.
*/
s32 sub_GAME_7F02D630(ChrRecord *self, GUNHAND hand, coord3d *arg2)
{
    struct ObjectRecord *obj;
    PropRecord *weapon_prop;
    Model *weapon_prop_model; // sp188
    s32 ret;
    Mtxf *temp_a0; // sp180
    Mtxf sp74;
    f32 *spB8;
    Mtxf *temp_a0_2; // sp108
    Mtxf sp68; // sp44
    
    weapon_prop = chrGetEquippedWeaponProp(self, hand);
    ret = 0;

    if ((weapon_prop != NULL) )
    {
        obj = weapon_prop->obj;
        weapon_prop_model = obj->model;

        if ((weapon_prop->flags & 2))
        {
            if (weapon_prop_model->obj->Switches[0])
            {
                temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[0], 0);
                spB8 = weapon_prop_model->obj->Switches[0]->Data;

                arg2->f[0] = spB8[0];
                arg2->f[1] = spB8[1];
                arg2->f[2] = spB8[2];

                matrix_4x4_multiply_homogeneous(currentPlayerGetMatrix10D4(), temp_a0, &sp74);
                matrix_4x4_transform_vector_in_place(&sp74, arg2);

                ret = 1;
            }
            else if (weapon_prop_model->obj->Switches[1])
            {
                temp_a0_2 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[1], 0);
                matrix_4x4_multiply_homogeneous(currentPlayerGetMatrix10D4(), temp_a0_2, &sp68);

                arg2->f[0] = sp68.m[3][0];
                arg2->f[1] = sp68.m[3][1];
                arg2->f[2] = sp68.m[3][2];

                ret = 1;
            }
        }
    }

    return ret;
}



/**
 * Address 0x7F02D734.
*/
void chrlvFireWeaponRelated(ChrRecord *self, s32 hand)
{
    PropRecord *self_prop; // 644
    s32 phi_a2; // ?
    s32 sp27C; // stack 636
    s32 sp278;
    ChrRecord *prop_selfchr; // 628
    PropRecord *player_prop; // 624
    s32 phi_v1; // ?
    s32 sp268; // 616
    s32 sp264; // 612
    coord3d sp258; // 600
    StandTile *sp254; // 596
    f32 subroty; // 592
    f32 sp24C; // 588
     coord3d sp240; // 576
    StandTile *self_stan; // 572
    StandTile *sp238; // 568
    s32 sp234; // 564
    s32 sp230; // 560
    s32 sp22C; // 556
     coord3d sp220;
    s32 sp21C;
    f32 dy;
    f32 dz;
    f32 dx;
    f32 sp20C; // 524
    struct WeaponObjRecord *sp208;
    Mtxf sp1C8;
     coord3d sp1BC;  // 444
    PropRecord *weapon_prop;
     coord3d sp1AC; // 428
    Mtxf sp16C;
    Mtxf sp12C;
    struct WeaponObjRecord *sp128; // 296
    Mtxf spE8;
     coord3d spDC; // 220
    Mtxf sp9C;
    Mtxf sp5C; // 92
    s32 sp44;
    struct ObjectRecord_f6c * temp_v0_4;
    f32 sp4C;
    
    self_prop = self->prop;
    weapon_prop = chrGetEquippedWeaponProp(self, hand);

    if (weapon_prop != NULL)
    {
        sp27C = 0;
        sp278 = 0;
        prop_selfchr = weapon_prop->chr;
        player_prop = get_curplayer_positiondata();
        phi_v1 = 1;

        if (self->actiontype == ACT_ATTACK)
        {
            phi_v1 = self->act_attack.attacktype;
        }

        sp44 = phi_v1 & 1;

        if (
            (sp44 == 0)
            || (self->seen_bond_time >= (g_GlobalTimer - CHRLV_SEEN_RECENT_CHECK))
            || (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) < 0))
        {
            sp268 = 0;
            sp264 = 0;
            
            self->firecount[hand]++;

            if (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) < 0)
            {
                sp268 = 1;
                sp264 = 1;
            }
            else if (((s32) self->firecount[hand] % bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item)) == 0)
            {
                sp268 = 1;

                if ((((s32) self->firecount[hand] % (s32) (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) * 2)) == 0) 
                    || (prop_selfchr->act_attack.attack_item == ITEM_LASER))
                {
                    sp264 = 1;
                }
            }
            else
            {
                sp278 = 1;
            }

            if (sp268 != 0)
            {
                sp254 = NULL;
                subroty = chrlvGetSubrotySideback(self);
                sp24C = sub_GAME_7F02C27C(self);
                self_stan = self_prop->stan;
                sp27C = 1;

                if (sub_GAME_7F02D630(self, hand, (coord3d *) &sp240) == 0)
                {
                    sp240.f[0] = self_prop->pos.f[0];
                    sp240.f[1] = self_prop->pos.f[1] + 30.0f;
                    sp240.f[2] = self_prop->pos.f[2];

                    if (hand == 1)
                    {
                        sp240.f[0] += cosf(subroty) * 10.0f;
                        sp240.f[2] += -sinf(subroty) * 10.0f;
                    }
                    else
                    {
                        sp240.f[0] += -cosf(subroty) * 10.0f;
                        sp240.f[2] += sinf(subroty) * 10.0f;
                    }
                }

                if (sub_GAME_7F0B0E24(&self_stan, self_prop->pos.x, self_prop->pos.f[2], sp240.f[0], sp240.f[2], 2, sp240.f[1] - self->ground, sp240.f[1] - self->ground, 0.0f, 1.0f) != 0)
                {
                    sp238 = self_stan;
                }
                else
                {
                    self->firecount[hand]--;
                    sp27C = 0;
                }

                if (sp27C != 0)
                {
                    sp234 = 0;
                    sp230 = 0;
                    sp22C = 1;
                    
                    sp21C = chrlvAttackRelated7F0292A8(self, &sp240, sp238);
                    
                    sp220.f[0] = cosf(sp24C) * sinf(subroty);
                    sp220.f[1] = sinf(sp24C);
                    sp220.f[2] = cosf(sp24C) * cosf(subroty);
                    
                    sp258.f[0] = sp240.f[0] + (sp220.f[0] * M_U16_MAX_VALUE_F);
                    sp258.f[1] = sp240.f[1] + (sp220.f[1] * M_U16_MAX_VALUE_F);
                    sp258.f[2] = sp240.f[2] + (sp220.f[2] * M_U16_MAX_VALUE_F);
                    
                    set_or_unset_GUARDdata_flag(self, 0);
                    sub_GAME_7F0B1CC4();
                    self_stan = sp238;

                    if (sub_GAME_7F0B0E24(&self_stan, sp240.f[0], sp240.f[2], sp258.f[0], sp258.f[2], 0x1B, sp240.f[1], sp240.f[1], sp258.f[1], sp258.f[1]) == 0)
                    {
                        chrlvStanLineDirIntersection(&sp240, &sp220, &sp258);
                        sp254 = self_stan;
                        sp258.f[0] -= 26.0f * sp220.f[0];
                        sp258.f[1] -= 26.0f * sp220.f[1];
                        sp258.f[2] -= 26.0f * sp220.f[2];
                    }

                    set_or_unset_GUARDdata_flag(self, 1);

                    dx = sp258.f[0] - sp240.f[0];
                    dy = sp258.f[1] - sp240.f[1];
                    dz = sp258.f[2] - sp240.f[2];
                    
                    sp20C = (dx * dx) + (dy * dy) + (dz * dz);

                    if (prop_selfchr->act_attack.attack_item == ITEM_ROCKETLAUNCH)
                    {
                        if (((dx * dx) + (dy * dy) + (dz * dz)) > 160000.0f)
                        {
                            sp208 = (struct WeaponObjRecord *)create_new_item_instance_of_model(PROP_CHRROCKET, 0x56);
                            if (sp208 != NULL)
                            {
                                matrix_4x4_set_identity(&sp1C8);
                                matrix_4x4_set_rotation_around_x(sp24C, &sp16C);
                                matrix_4x4_set_rotation_around_y(subroty, &sp12C);
                                matrix_4x4_multiply_homogeneous_in_place(&sp12C, &sp16C);
                                
                                sp1AC.f[0] = sp220.f[0] * 1.111111f;
                                sp1AC.f[1] = sp220.f[1] * 1.111111f;
                                sp1AC.f[2] = sp220.f[2] * 1.111111f;

                                sp1BC.f[0] = sp1AC.f[0] * g_GlobalTimerDelta;
                                sp1BC.f[1] = sp1AC.f[1] * g_GlobalTimerDelta;
                                sp1BC.f[2] = sp1AC.f[2] * g_GlobalTimerDelta;

                                sub_GAME_7F05EB0C((ObjectRecord *)sp208, &sp240, sp238, &sp16C, &sp1BC, &sp1C8, self_prop);
                                
                                if (sp208->runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT)
                                {
                                    sp208->unk6C->id |= 0x80;
                                    sp208->timer = -1;
                                    sp208->unk6C->id |= 0x20;

                                    sp208->unk6C->unkb0 = sp208->runtime_pos.y;
                                    sp208->unk6C->unkb4 = sp208->unk6C->pos.f[1];

                                  /*  sp208->unk6C->vec.x = sp1AC.f[0];
                                    sp208->unk6C->vec.y = sp1AC.f[1];
                                    sp208->unk6C->vec.z = sp1AC.f[2];*/
                                    sp208->unk6C->vec.x = sp1AC.f[0];
                                    sp208->unk6C->vec.y = sp1AC.f[1];
                                    sp208->unk6C->vec.z = sp1AC.f[2];
                                    
                                    if (sp208->unk6C->unk98[0] == NULL)
                                    {
                                        sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, 1, (ALSoundState *)&sp208->unk6C->unk98[0]);
                                    }
                                    else if (sp208->unk6C->unk98[1] == NULL)
                                    {
                                        sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, 1, (ALSoundState *)&sp208->unk6C->unk98[1]);
                                    }
                                }
                            }
                        }
                        else
                        {
                            sp27C = 0;
                        }
                    }
                    else if (prop_selfchr->act_attack.attack_item == ITEM_GRENADELAUNCH)
                    {
                        if (((dx * dx) + (dy * dy) + (dz * dz)) > 160000.0f)
                        {
                            sp128 = (struct WeaponObjRecord *)create_new_item_instance_of_model(PROP_CHRGRENADEROUND, 0x57);
                            if (sp128 != NULL)
                            {
                                matrix_4x4_set_identity(&spE8);
                                spDC.f[0] = sp220.f[0] * 33.333332f;
                                spDC.f[1] = sp220.f[1] * 33.333332f;
                                spDC.f[2] = sp220.f[2] * 33.333332f;
                                matrix_4x4_set_rotation_around_x(sp24C, &sp9C);
                                matrix_4x4_set_rotation_around_y(subroty, &sp5C);
                                matrix_4x4_multiply_homogeneous_in_place(&sp5C, &sp9C);
                                sp128->timer = CHRLV_DEFAULT_TIMER;
                                sub_GAME_7F05EB0C((ObjectRecord *) sp128, &sp240, sp238, &sp9C, &spDC, &spE8, self_prop);
                                
                                if (sp128->runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT)
                                {
                                    sp128->unk6C->unk8c = 0.3f;
                                    sp128->unk6C->unk94 = 0.13333333f;
#ifdef REFRESH_PAL
                                    sp128->unk6C->refreshrate = 50;
#else
                                    sp128->unk6C->refreshrate = 60;
#endif
                                }
                            }
                        }
                        else
                        {
                            sp27C = 0;
                        }
                    }
                    else
                    {
                        if ((sp44 != 0) && (sp21C != 0))
                        {
                            dx = (player_prop->pos.f[0] - sp240.f[0]) - (sp220.f[0] * 15.0f);
                            dy = (player_prop->pos.f[1] - sp240.f[1]) - (sp220.f[1] * 15.0f);
                            dz = (player_prop->pos.f[2] - sp240.f[2]) - (sp220.f[2] * 15.0f);
                            
                            if (((dx * dx) + (dy * dy) + (dz * dz)) <= sp20C)
                            {
                                chrlvUpdateShotbondsum(self, &sp234, &sp230, prop_selfchr->act_attack.attack_item);
                                sp22C = sp230 == 0;
                                
                                if ((sp234 != 0) && ((self->actiontype == ACT_ATTACK) || (self->actiontype == ACT_ATTACKROLL)))
                                {
                                    self->act_attack.attack_time = g_GlobalTimer;
                                }
                            }
                        }
                        else
                        {
                            if ((self->actiontype == ACT_ATTACK) || (self->actiontype == ACT_ATTACKROLL))
                            {
                                self->act_attack.attack_time = g_GlobalTimer;
                            }
                        }

                        if (sp230 != 0)
                        {
                            sp258.f[0] = player_prop->pos.f[0];
                            sp258.f[1] = player_prop->pos.f[1];
                            sp258.f[2] = player_prop->pos.f[2];
                            sp254 = player_prop->stan;
                            recall_joy2_hits_edit_detail_edit_flag(prop_selfchr->act_attack.attack_item, &player_prop->type, -1);
                        }
                        else
                        {
                            if ((
                                    (stanSavedColl_posData == NULL) 
                                    || ((stanSavedColl_posData->type != PROP_TYPE_CHR) && (stanSavedColl_posData->type != PROP_TYPE_VIEWER))
                                ) 
                                && (sp20C < 10000.0f))
                            {
                                sp22C = 0;
                            }
                        }

                        if (sp22C != 0)
                        {
                            if (sp254 != 0)
                            {
                                sub_GAME_7F0A3E1C(&sp258, 1, 26.0f, (s16) sp254->room);
                            }

                            if (stanSavedColl_posData != NULL)
                            {
                                recall_joy2_hits_edit_detail_edit_flag(prop_selfchr->act_attack.attack_item, &stanSavedColl_posData->type, -1);

                                if (stanSavedColl_posData->type == PROP_TYPE_CHR)
                                {
                                    if ((self->chrflags & 0x40) != 0)
                                    {
                                        handles_shot_actors(stanSavedColl_posData->chr, 0xF, &sp220, prop_selfchr->act_attack.attack_item, 0);
                                    }
                                }
                                else if ((stanSavedColl_posData->type == PROP_TYPE_OBJ) || (stanSavedColl_posData->type == PROP_TYPE_WEAPON))
                                {
                                    chrobjMaybeDetonateObjectIfFlags(
                                        stanSavedColl_posData->obj,
                                        bondwalkItemGetDestructionAmount(prop_selfchr->act_attack.attack_item),
                                        &sp258,
                                        prop_selfchr->act_attack.attack_item,
                                        get_cur_playernum());
                                }
                            }
                            else
                            {
                                recall_joy2_hits_edit_flag(prop_selfchr->act_attack.attack_item, &sp258, -1);
                            }
                        }

                        if (sp264 != 0)
                        {
                            switch (prop_selfchr->act_attack.attack_item) 
                            {
                                case ITEM_WPPK:
                                case ITEM_WPPKSIL:
                                case ITEM_TT33:
                                case ITEM_SKORPION:
                                case ITEM_AK47:
                                case ITEM_UZI:
                                case ITEM_MP5K:
                                case ITEM_MP5KSIL:
                                case ITEM_SPECTRE:
                                case ITEM_M16:
                                case ITEM_FNP90:
                                case ITEM_RUGER:
                                case ITEM_GOLDENGUN:
                                case ITEM_SILVERWPPK:
                                case ITEM_GOLDWPPK:
                                case ITEM_LASER:
                                    sp264 = 1;
                                    break;

                                default:
                                    sp264 = 0;
                                    break;
                            }
                        }

                        if (sp264 != 0)
                        {
                            sub_GAME_7F061948(&self->unk180[hand], prop_selfchr->act_attack.attack_item, &sp240, &sp258);
                        }
                    }
                }
            }

            phi_a2 = (sp27C != 0) || (sp278 != 0);

            sub_GAME_7F02BFE4(self, hand, phi_a2);
        }

        sub_GAME_7F02D118(self, hand, sp27C);
    }
}



/**
 * Address 0x7F02E26C.
*/
void chrlvTriggerFireWeapon(ChrRecord *self)
{
    self->hidden &= 0xFF7F; // CHRHIDDEN_FIRE_WEAPON_RIGHT

    if (self->hidden & CHRHIDDEN_FIRE_WEAPON_RIGHT)
    {
        chrlvFireWeaponRelated(self, GUNRIGHT);

        self->hidden &= 0xFFF7; // CHRHIDDEN_FIRE_WEAPON_RIGHT
    }

     if (self->hidden & CHRHIDDEN_FIRE_WEAPON_LEFT)
    {
        chrlvFireWeaponRelated(self, GUNLEFT);

        self->hidden &= 0xFFFB; // CHRHIDDEN_FIRE_WEAPON_LEFT
    }
}



/**
 * Address 0x7F02E2E0.
*/
s32 chrlvAttackrollAnimationRelated7F02E2E0(ChrRecord *self)
{
    Model *model;
    struct weapon_firing_animation_table *p;
    s32 sp24;

    if ((self->act_attackroll.animfloats == &D_80030078[2]) || (self->act_attackroll.animfloats == &D_80030078[3]))
    {
        model = self->model;
        sp24 = (s32) model->gunhand;
        self->act_attackroll.unk30 = 2;
        self->act_attackroll.animfloats = &D_80030078[1];
        self->sleep = 0;

        p = &D_80030078[1];

        modelSetAnimation(
            model,
            (void *) p->anonymous_0,
            sp24,
            p->anonymous_7,
            chrlvGetGuard007SpeedRating(self, 0.7f, 1.12f),
            22.0f);

        if (D_80030078[1].anonymous_5 >= 0.0f)
        {
            modelSetAnimEndFrame(model, D_80030078[1].anonymous_5);
        }

        return 1;
    }

    return 0;
}





/**
 * Address 0x7F02E3B8.
*/
void chrlvAttackrollAnimationRelated7F02E3B8(ChrRecord *self)
{
    Model *model;

    model = self->model;

    if (self->act_attackroll.animfloats->anonymous_9 > 0.0f)
    {
        modelSetAnimation(
            model,
            objecthandlerGetModelAnim(model),
            (s32) model->gunhand,
            self->act_attackroll.animfloats->anonymous_9,
            chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
            8.0f);
    }
    else
    {
        modelSetAnimation(
            model,
            objecthandlerGetModelAnim(model),
            (s32) model->gunhand,
            self->act_attackroll.animfloats->anonymous_7,
            chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
            8.0f);
    }

    if (self->act_attackroll.animfloats->anonymous_5 >= 0.0f)
    {
        modelSetAnimEndFrame(model, self->act_attackroll.animfloats->anonymous_5);
    }
}



/**
 * Address 0x7F02E4C0.
 * Address 0x7F02E4F4 (VERSION_EU).
*/
void chrlvTickAttackCommon(ChrRecord *self)
{
    s32 i;
    Model *self_model;
    f32 df;
    f32 temp_f0_6;
    f32 fp1; // 92
    f32 phi_f20;
    f32 fp2;
    f32 fn40; // 80
    f32 fanon1; // 76

    self_model = self->model;
    phi_f20 = objecthandlerGetModelField28(self_model);

    if (
#ifdef REFRESH_PAL
        (self->act_attack.attack_time < (self->act_attack.unk44 - 25)) 
#else
        (self->act_attack.attack_time < (self->act_attack.unk44 - 30)) 
#endif
        && (self_model->anim2 == NULL))
    {
        if (((self->act_attack.animfloats->anonymous_6 + 10.0f) < phi_f20)
            && (phi_f20 < self->act_attack.animfloats->anonymous_7))
        {
            if (((self->act_attack.animfloats->anonymous_9 < 0.0f)) || (phi_f20 < self->act_attack.animfloats->anonymous_9))
            {
                if (self->act_attack.unk36 == 0)
                {
                    if (chrlvAttackrollAnimationRelated7F02E2E0(self) == 0)
                    {
                        modelSetAnimation(
                            self_model,
                            objecthandlerGetModelAnim(self_model),
                            (s32) self_model->gunhand,
                            self->act_attack.animfloats->anonymous_7,
                            chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
                            8.0f);
                        
                        if (self->act_attack.animfloats->anonymous_5 >= 0.0f)
                        {
                            modelSetAnimEndFrame(self_model, self->act_attack.animfloats->anonymous_5);
                        }
                    }
                }
                else
                {
                    chrlvAttackrollAnimationRelated7F02E3B8(self);
                }
                
                self->act_attack.unk33 = (s8) (self->act_attack.unk34 + 1);
                phi_f20 = objecthandlerGetModelField28(self_model);
            }
        }
    }

    if (sub_GAME_7F06F5C4(self_model) <= phi_f20)
    {
        if ((self->act_attack.unk37 != 0) || (self->act_attack.unk34 < self->act_attack.unk33))
        {
            if (chrlvAttackrollAnimationRelated7F02E2E0(self) == 0)
            {
                if ((self->act_attack.attacktype & 1) != 0)
                {
                    chrlvSetTargetToPlayer(self);
                }

                chrlvKneelingAnimationRelated7F023E48(self);

                return;
            }
        }
        else if (self->act_attack.unk33 == self->act_attack.unk34)
        {
            self->act_attack.unk33++;
            chrlvAttackrollAnimationRelated7F02E3B8(self);
        }
        else if (self->act_attack.unk31 != 0)
        {
            temp_f0_6 = 0.5f;

            if (self->act_attack.unk36 != 0)
            {
                if (self->act_attack.animfloats->anonymous_8 > 0.0f)
                {
                    fp1 = self->act_attack.animfloats->anonymous_8;
                }
                else
                {
                    fp1 = self->act_attack.animfloats->anonymous_6;
                }

                if (self->act_attack.animfloats->anonymous_9 > 0.0f)
                {
                    fp2 = self->act_attack.animfloats->anonymous_9;
                }
                else
                {
                    fp2 = self->act_attack.animfloats->anonymous_7;
                }
            }
            else
            {
                fp1 = self->act_attack.animfloats->anonymous_6;

                if (self->act_attack.animfloats->anonymous_8 > 0.0f)
                {
                    fp2 = self->act_attack.animfloats->anonymous_8;
                }
                else
                {
                    fp2 = self->act_attack.animfloats->anonymous_7;
                }
            }

            df = fp2 - fp1;
            if (df < 12.0f)
            {
                temp_f0_6 = (df * 0.5f) / 12.0f;
            }
            else if (df > 16.0f)
            {
                temp_f0_6 = df * 0.5f * 0.0625f;
            }

            if ((self->act_attack.unk3a[0] != 0) && (self->act_attack.unk3a[1] != 0))
            {
                temp_f0_6 = 2.0f * temp_f0_6;
            }

            self->act_attack.unk31 = 0;

            modelSetAnimation(self_model, objecthandlerGetModelAnim(self_model), (s32) self_model->gunhand, fp1, temp_f0_6, 8.0f);
            modelSetAnimEndFrame(self_model, fp2);
        }

        phi_f20 = objecthandlerGetModelField28(self_model);
    }

    if ((self->act_attack.attacktype & 0x40) == 0)
    {
        fn40 = self->act_attack.animfloats->anonymous_3;
        fanon1 = self->act_attack.animfloats->anonymous_1;

        if ((self->act_attack.attacktype & 0x20) != 0)
        {
            if (sub_GAME_7F06F5C4(self_model) < fanon1)
            {
                fanon1 = sub_GAME_7F06F5C4(self_model);
            }
        }

        if (self_model->gunhand != GUNRIGHT)
        {
            fn40 = 6.2831855f - fn40;
        }

        self->act_attack.unk30 = chrlvSetSubroty(
            self,
            (s32) self->act_attack.unk30,
            fanon1,
            chrlvGetGuard007SpeedRating(self, 1.0f, 1.6f),
            fn40);
    }

    if ((self->act_attack.animfloats->anonymous_10 < phi_f20) && (phi_f20 < self->act_attack.animfloats->anonymous_11))
    {
        chrlvUpdateAimendsideback(self, self->act_attack.animfloats, (s32) self->act_attack.unk38[1], (s32) self->act_attack.unk38[0], 1.0f);
    }
    else
    {
        chrlvResetAimend(self);
    }

    for (i=0; i<2; i++)
    {
        if (self->act_attack.unk38[i] != 0)
        {
            if (self->act_attack.unk3a[i] == 0)
            {
                if ((self->act_attack.animfloats->anonymous_6 <= phi_f20) && (phi_f20 < self->act_attack.animfloats->anonymous_7))
                {
                    chrlvToggleHiddenRelated(self, i, 1);
                    self->act_attack.unk44 = g_GlobalTimer;

                    if (self->actiontype == ACT_ATTACKROLL)
                    {
#ifdef REFRESH_PAL
                        df = ((self->act_attack.animfloats->anonymous_7 - self->act_attack.animfloats->anonymous_6) * 50.0f) / 60.0f;
#else
                        df = self->act_attack.animfloats->anonymous_7 - self->act_attack.animfloats->anonymous_6;
#endif

                        if (df < 30.0f)
                        {
#ifdef REFRESH_PAL
                            if ((s32) self->act_attack.unk40 >= (50 - ((s32) df * 2)))
#else
                            if ((s32) self->act_attack.unk40 >= (60 - ((s32) df * 2)))
#endif
                            {
                                modelSetAnimSpeed(self_model, 0.5f, 0.0f);
                            }
                            else
                            {
                                modelSetAnimSpeed(self_model, 0.1f, 0.0f);
                                self->act_attack.unk40 += g_ClockTimer;
                            }
                        }
                        else
                        {
                            modelSetAnimSpeed(self_model, 0.5f, 0.0f);
                        }
                    }
                    else
                    {
                        modelSetAnimSpeed(self_model, 0.5f, 0.0f);
                    }
                }
                else
                {
                    chrlvToggleHiddenRelated(self, i, 0);

                    if (self->actiontype == ACT_ATTACKROLL)
                    {
                        modelSetAnimSpeed(self_model, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 0.0f);
                    }
                    else
                    {
                        modelSetAnimSpeed(self_model, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 0.0f);
                    }
                }
            }
            else if (
                (self->act_attack.unk31 == 0)
                && ((i == self->act_attack.unk32) || (self->act_attack.unk3a[self->act_attack.unk32] == 0))
                && (
                    (
                        ( self->act_attack.animfloats->anonymous_8 >= 0.0f)
                        && (self->act_attack.animfloats->anonymous_8 <= phi_f20)
                        && (phi_f20 <= self->act_attack.animfloats->anonymous_9))
                    ||
                    (
                        (self->act_attack.animfloats->anonymous_8 < 0.0f)
                        && (self->act_attack.animfloats->anonymous_6 <= phi_f20)
                    )))
            {
                self->act_attack.unk31 = 1;
                self->act_attack.unk32 = (s8) (1 - self->act_attack.unk32);
                self->act_attack.unk33++;
                self->act_attack.unk44 = g_GlobalTimer;

                chrlvToggleHiddenRelated(self, i, 1);
            }
            else
            {
                chrlvToggleHiddenRelated(self, i, 0);
            }
        }
        else
        {
            chrlvToggleHiddenRelated(self, i, 0);
        }
    }
}

//#else

#ifdef NONMATCHING
    // should be implemented above, but untested.
//#else

GLOBAL_ASM(
.late_rodata
glabel D_80051FC8
.word 0x40c90fdb /*6.2831855*/
.text
glabel chrlvTickAttackCommon
/* 060EE4 7F02E4F4 27BDFF90 */  addiu $sp, $sp, -0x70
/* 060EE8 7F02E4F8 AFBF0044 */  sw    $ra, 0x44($sp)
/* 060EEC 7F02E4FC AFB30040 */  sw    $s3, 0x40($sp)
/* 060EF0 7F02E500 AFB2003C */  sw    $s2, 0x3c($sp)
/* 060EF4 7F02E504 AFB10038 */  sw    $s1, 0x38($sp)
/* 060EF8 7F02E508 AFB00034 */  sw    $s0, 0x34($sp)
/* 060EFC 7F02E50C F7B80028 */  sdc1  $f24, 0x28($sp)
/* 060F00 7F02E510 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 060F04 7F02E514 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 060F08 7F02E518 8C93001C */  lw    $s3, 0x1c($a0)
/* 060F0C 7F02E51C 00808025 */  move  $s0, $a0
/* 060F10 7F02E520 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 060F14 7F02E524 02602025 */   move  $a0, $s3
/* 060F18 7F02E528 8E0F0044 */  lw    $t7, 0x44($s0)
/* 060F1C 7F02E52C 8E0E0048 */  lw    $t6, 0x48($s0)
/* 060F20 7F02E530 46000506 */  mov.s $f20, $f0
/* 060F24 7F02E534 25F8FFE7 */  addiu $t8, $t7, -0x19
/* 060F28 7F02E538 01D8082A */  slt   $at, $t6, $t8
/* 060F2C 7F02E53C 5020004B */  beql  $at, $zero, .L7F02E66C
/* 060F30 7F02E540 3C013F00 */   lui   $at, 0x3f00
/* 060F34 7F02E544 8E790054 */  lw    $t9, 0x54($s3)
/* 060F38 7F02E548 57200048 */  bnezl $t9, .L7F02E66C
/* 060F3C 7F02E54C 3C013F00 */   lui   $at, 0x3f00
/* 060F40 7F02E550 8E05002C */  lw    $a1, 0x2c($s0)
/* 060F44 7F02E554 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 060F48 7F02E558 44813000 */  mtc1  $at, $f6
/* 060F4C 7F02E55C C4A40018 */  lwc1  $f4, 0x18($a1)
/* 060F50 7F02E560 46062200 */  add.s $f8, $f4, $f6
/* 060F54 7F02E564 4600403C */  c.lt.s $f8, $f0
/* 060F58 7F02E568 00000000 */  nop   
/* 060F5C 7F02E56C 4502003F */  bc1fl .L7F02E66C
/* 060F60 7F02E570 3C013F00 */   lui   $at, 0x3f00
/* 060F64 7F02E574 C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 060F68 7F02E578 460A003C */  c.lt.s $f0, $f10
/* 060F6C 7F02E57C 00000000 */  nop   
/* 060F70 7F02E580 4502003A */  bc1fl .L7F02E66C
/* 060F74 7F02E584 3C013F00 */   lui   $at, 0x3f00
/* 060F78 7F02E588 4480B000 */  mtc1  $zero, $f22
/* 060F7C 7F02E58C C4A20024 */  lwc1  $f2, 0x24($a1)
/* 060F80 7F02E590 4616103C */  c.lt.s $f2, $f22
/* 060F84 7F02E594 00000000 */  nop   
/* 060F88 7F02E598 45030006 */  bc1tl .L7F02E5B4
/* 060F8C 7F02E59C 82080036 */   lb    $t0, 0x36($s0)
/* 060F90 7F02E5A0 4602003C */  c.lt.s $f0, $f2
/* 060F94 7F02E5A4 00000000 */  nop   
/* 060F98 7F02E5A8 45020030 */  bc1fl .L7F02E66C
/* 060F9C 7F02E5AC 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 060FA0 7F02E5B0 82080036 */  lb    $t0, 0x36($s0)
.L7F02E5B4:
/* 060FA4 7F02E5B4 15000024 */  bnez  $t0, .L7F02E648
/* 060FA8 7F02E5B8 00000000 */   nop   
/* 060FAC 7F02E5BC 0FC0B8C5 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
/* 060FB0 7F02E5C0 02002025 */   move  $a0, $s0
/* 060FB4 7F02E5C4 1440001E */  bnez  $v0, .L7F02E640
/* 060FB8 7F02E5C8 00000000 */   nop   
/* 060FBC 7F02E5CC 0FC1BDD3 */  jal   objecthandlerGetModelAnim
/* 060FC0 7F02E5D0 02602025 */   move  $a0, $s3
/* 060FC4 7F02E5D4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 060FC8 7F02E5D8 4481C000 */  mtc1  $at, $f24
/* 060FCC 7F02E5DC 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 060FD0 7F02E5E0 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 060FD4 7F02E5E4 4405C000 */  mfc1  $a1, $f24
/* 060FD8 7F02E5E8 00408825 */  move  $s1, $v0
/* 060FDC 7F02E5EC 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 060FE0 7F02E5F0 02002025 */   move  $a0, $s0
/* 060FE4 7F02E5F4 8E09002C */  lw    $t1, 0x2c($s0)
/* 060FE8 7F02E5F8 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 060FEC 7F02E5FC 44818000 */  mtc1  $at, $f16
/* 060FF0 7F02E600 82660024 */  lb    $a2, 0x24($s3)
/* 060FF4 7F02E604 8D27001C */  lw    $a3, 0x1c($t1)
/* 060FF8 7F02E608 E7A00010 */  swc1  $f0, 0x10($sp)
/* 060FFC 7F02E60C 02602025 */  move  $a0, $s3
/* 061000 7F02E610 02202825 */  move  $a1, $s1
/* 061004 7F02E614 0FC1BF92 */  jal   modelSetAnimation
/* 061008 7F02E618 E7B00014 */   swc1  $f16, 0x14($sp)
/* 06100C 7F02E61C 8E0A002C */  lw    $t2, 0x2c($s0)
/* 061010 7F02E620 C5400014 */  lwc1  $f0, 0x14($t2)
/* 061014 7F02E624 4600B03E */  c.le.s $f22, $f0
/* 061018 7F02E628 00000000 */  nop   
/* 06101C 7F02E62C 45000004 */  bc1f  .L7F02E640
/* 061020 7F02E630 00000000 */   nop   
/* 061024 7F02E634 44050000 */  mfc1  $a1, $f0
/* 061028 7F02E638 0FC1BFE2 */  jal   modelSetAnimEndFrame
/* 06102C 7F02E63C 02602025 */   move  $a0, $s3
.L7F02E640:
/* 061030 7F02E640 10000004 */  b     .L7F02E654
/* 061034 7F02E644 820B0034 */   lb    $t3, 0x34($s0)
.L7F02E648:
/* 061038 7F02E648 0FC0B8FB */  jal   chrlvAttackrollAnimationRelated7F02E3B8
/* 06103C 7F02E64C 02002025 */   move  $a0, $s0
/* 061040 7F02E650 820B0034 */  lb    $t3, 0x34($s0)
.L7F02E654:
/* 061044 7F02E654 02602025 */  move  $a0, $s3
/* 061048 7F02E658 256C0001 */  addiu $t4, $t3, 1
/* 06104C 7F02E65C 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 061050 7F02E660 A20C0033 */   sb    $t4, 0x33($s0)
/* 061054 7F02E664 46000506 */  mov.s $f20, $f0
/* 061058 7F02E668 3C013F00 */  li    $at, 0x3F000000 # 0.500000
.L7F02E66C:
/* 06105C 7F02E66C 4481C000 */  mtc1  $at, $f24
/* 061060 7F02E670 4480B000 */  mtc1  $zero, $f22
/* 061064 7F02E674 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 061068 7F02E678 02602025 */   move  $a0, $s3
/* 06106C 7F02E67C 4614003E */  c.le.s $f0, $f20
/* 061070 7F02E680 00000000 */  nop   
/* 061074 7F02E684 45020076 */  bc1fl .L7F02E860
/* 061078 7F02E688 8E02004C */   lw    $v0, 0x4c($s0)
/* 06107C 7F02E68C 820D0037 */  lb    $t5, 0x37($s0)
/* 061080 7F02E690 15A00006 */  bnez  $t5, .L7F02E6AC
/* 061084 7F02E694 00000000 */   nop   
/* 061088 7F02E698 82030034 */  lb    $v1, 0x34($s0)
/* 06108C 7F02E69C 82020033 */  lb    $v0, 0x33($s0)
/* 061090 7F02E6A0 0062082A */  slt   $at, $v1, $v0
/* 061094 7F02E6A4 1020000F */  beqz  $at, .L7F02E6E4
/* 061098 7F02E6A8 00000000 */   nop   
.L7F02E6AC:
/* 06109C 7F02E6AC 0FC0B8C5 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
/* 0610A0 7F02E6B0 02002025 */   move  $a0, $s0
/* 0610A4 7F02E6B4 14400066 */  bnez  $v0, .L7F02E850
/* 0610A8 7F02E6B8 00000000 */   nop   
/* 0610AC 7F02E6BC 8E0F004C */  lw    $t7, 0x4c($s0)
/* 0610B0 7F02E6C0 31EE0001 */  andi  $t6, $t7, 1
/* 0610B4 7F02E6C4 11C00003 */  beqz  $t6, .L7F02E6D4
/* 0610B8 7F02E6C8 00000000 */   nop   
/* 0610BC 7F02E6CC 0FC0A6F9 */  jal   chrlvSetTargetToPlayer
/* 0610C0 7F02E6D0 02002025 */   move  $a0, $s0
.L7F02E6D4:
/* 0610C4 7F02E6D4 0FC08F8C */  jal   chrlvKneelingAnimationRelated7F023E48
/* 0610C8 7F02E6D8 02002025 */   move  $a0, $s0
/* 0610CC 7F02E6DC 10000151 */  b     .L7F02EC24
/* 0610D0 7F02E6E0 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F02E6E4:
/* 0610D4 7F02E6E4 14620006 */  bne   $v1, $v0, .L7F02E700
/* 0610D8 7F02E6E8 24580001 */   addiu $t8, $v0, 1
/* 0610DC 7F02E6EC A2180033 */  sb    $t8, 0x33($s0)
/* 0610E0 7F02E6F0 0FC0B8FB */  jal   chrlvAttackrollAnimationRelated7F02E3B8
/* 0610E4 7F02E6F4 02002025 */   move  $a0, $s0
/* 0610E8 7F02E6F8 10000055 */  b     .L7F02E850
/* 0610EC 7F02E6FC 00000000 */   nop   
.L7F02E700:
/* 0610F0 7F02E700 82190031 */  lb    $t9, 0x31($s0)
/* 0610F4 7F02E704 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0610F8 7F02E708 02602025 */  move  $a0, $s3
/* 0610FC 7F02E70C 13200050 */  beqz  $t9, .L7F02E850
/* 061100 7F02E710 00000000 */   nop   
/* 061104 7F02E714 82080036 */  lb    $t0, 0x36($s0)
/* 061108 7F02E718 4600C306 */  mov.s $f12, $f24
/* 06110C 7F02E71C 51000014 */  beql  $t0, $zero, .L7F02E770
/* 061110 7F02E720 8E05002C */   lw    $a1, 0x2c($s0)
/* 061114 7F02E724 8E05002C */  lw    $a1, 0x2c($s0)
/* 061118 7F02E728 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 06111C 7F02E72C 4600B03C */  c.lt.s $f22, $f0
/* 061120 7F02E730 00000000 */  nop   
/* 061124 7F02E734 45020004 */  bc1fl .L7F02E748
/* 061128 7F02E738 C4AE0018 */   lwc1  $f14, 0x18($a1)
/* 06112C 7F02E73C 10000002 */  b     .L7F02E748
/* 061130 7F02E740 46000386 */   mov.s $f14, $f0
/* 061134 7F02E744 C4AE0018 */  lwc1  $f14, 0x18($a1)
.L7F02E748:
/* 061138 7F02E748 C4A20024 */  lwc1  $f2, 0x24($a1)
/* 06113C 7F02E74C 4602B03C */  c.lt.s $f22, $f2
/* 061140 7F02E750 00000000 */  nop   
/* 061144 7F02E754 45000003 */  bc1f  .L7F02E764
/* 061148 7F02E758 00000000 */   nop   
/* 06114C 7F02E75C 1000000D */  b     .L7F02E794
/* 061150 7F02E760 46001506 */   mov.s $f20, $f2
.L7F02E764:
/* 061154 7F02E764 1000000B */  b     .L7F02E794
/* 061158 7F02E768 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 06115C 7F02E76C 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E770:
/* 061160 7F02E770 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 061164 7F02E774 C4AE0018 */  lwc1  $f14, 0x18($a1)
/* 061168 7F02E778 4600B03C */  c.lt.s $f22, $f0
/* 06116C 7F02E77C 00000000 */  nop   
/* 061170 7F02E780 45020004 */  bc1fl .L7F02E794
/* 061174 7F02E784 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 061178 7F02E788 10000002 */  b     .L7F02E794
/* 06117C 7F02E78C 46000506 */   mov.s $f20, $f0
/* 061180 7F02E790 C4B4001C */  lwc1  $f20, 0x1c($a1)
.L7F02E794:
/* 061184 7F02E794 460EA001 */  sub.s $f0, $f20, $f14
/* 061188 7F02E798 44811000 */  mtc1  $at, $f2
/* 06118C 7F02E79C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 061190 7F02E7A0 4602003C */  c.lt.s $f0, $f2
/* 061194 7F02E7A4 00000000 */  nop   
/* 061198 7F02E7A8 45020005 */  bc1fl .L7F02E7C0
/* 06119C 7F02E7AC 44812000 */   mtc1  $at, $f4
/* 0611A0 7F02E7B0 46180482 */  mul.s $f18, $f0, $f24
/* 0611A4 7F02E7B4 1000000D */  b     .L7F02E7EC
/* 0611A8 7F02E7B8 46029303 */   div.s $f12, $f18, $f2
/* 0611AC 7F02E7BC 44812000 */  mtc1  $at, $f4
.L7F02E7C0:
/* 0611B0 7F02E7C0 00000000 */  nop   
/* 0611B4 7F02E7C4 4600203C */  c.lt.s $f4, $f0
/* 0611B8 7F02E7C8 00000000 */  nop   
/* 0611BC 7F02E7CC 45020008 */  bc1fl .L7F02E7F0
/* 0611C0 7F02E7D0 8209003A */   lb    $t1, 0x3a($s0)
/* 0611C4 7F02E7D4 46180182 */  mul.s $f6, $f0, $f24
/* 0611C8 7F02E7D8 3C013D80 */  li    $at, 0x3D800000 # 0.062500
/* 0611CC 7F02E7DC 44814000 */  mtc1  $at, $f8
/* 0611D0 7F02E7E0 00000000 */  nop   
/* 0611D4 7F02E7E4 46083302 */  mul.s $f12, $f6, $f8
/* 0611D8 7F02E7E8 00000000 */  nop   
.L7F02E7EC:
/* 0611DC 7F02E7EC 8209003A */  lb    $t1, 0x3a($s0)
.L7F02E7F0:
/* 0611E0 7F02E7F0 51200006 */  beql  $t1, $zero, .L7F02E80C
/* 0611E4 7F02E7F4 A2000031 */   sb    $zero, 0x31($s0)
/* 0611E8 7F02E7F8 820A003B */  lb    $t2, 0x3b($s0)
/* 0611EC 7F02E7FC 51400003 */  beql  $t2, $zero, .L7F02E80C
/* 0611F0 7F02E800 A2000031 */   sb    $zero, 0x31($s0)
/* 0611F4 7F02E804 460C6300 */  add.s $f12, $f12, $f12
/* 0611F8 7F02E808 A2000031 */  sb    $zero, 0x31($s0)
.L7F02E80C:
/* 0611FC 7F02E80C E7AE005C */  swc1  $f14, 0x5c($sp)
/* 061200 7F02E810 0FC1BDD3 */  jal   objecthandlerGetModelAnim
/* 061204 7F02E814 E7AC0060 */   swc1  $f12, 0x60($sp)
/* 061208 7F02E818 C7AE005C */  lwc1  $f14, 0x5c($sp)
/* 06120C 7F02E81C 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 061210 7F02E820 44815000 */  mtc1  $at, $f10
/* 061214 7F02E824 C7AC0060 */  lwc1  $f12, 0x60($sp)
/* 061218 7F02E828 82660024 */  lb    $a2, 0x24($s3)
/* 06121C 7F02E82C 44077000 */  mfc1  $a3, $f14
/* 061220 7F02E830 02602025 */  move  $a0, $s3
/* 061224 7F02E834 00402825 */  move  $a1, $v0
/* 061228 7F02E838 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 06122C 7F02E83C 0FC1BF92 */  jal   modelSetAnimation
/* 061230 7F02E840 E7AC0010 */   swc1  $f12, 0x10($sp)
/* 061234 7F02E844 4405A000 */  mfc1  $a1, $f20
/* 061238 7F02E848 0FC1BFE2 */  jal   modelSetAnimEndFrame
/* 06123C 7F02E84C 02602025 */   move  $a0, $s3
.L7F02E850:
/* 061240 7F02E850 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 061244 7F02E854 02602025 */   move  $a0, $s3
/* 061248 7F02E858 46000506 */  mov.s $f20, $f0
/* 06124C 7F02E85C 8E02004C */  lw    $v0, 0x4c($s0)
.L7F02E860:
/* 061250 7F02E860 304B0040 */  andi  $t3, $v0, 0x40
/* 061254 7F02E864 5560002B */  bnezl $t3, .L7F02E914
/* 061258 7F02E868 8E05002C */   lw    $a1, 0x2c($s0)
/* 06125C 7F02E86C 8E05002C */  lw    $a1, 0x2c($s0)
/* 061260 7F02E870 304C0020 */  andi  $t4, $v0, 0x20
/* 061264 7F02E874 02602025 */  move  $a0, $s3
/* 061268 7F02E878 C4A2000C */  lwc1  $f2, 0xc($a1)
/* 06126C 7F02E87C 1180000F */  beqz  $t4, .L7F02E8BC
/* 061270 7F02E880 C4AC0004 */   lwc1  $f12, 4($a1)
/* 061274 7F02E884 E7A20050 */  swc1  $f2, 0x50($sp)
/* 061278 7F02E888 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 06127C 7F02E88C E7AC004C */   swc1  $f12, 0x4c($sp)
/* 061280 7F02E890 C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 061284 7F02E894 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 061288 7F02E898 02602025 */  move  $a0, $s3
/* 06128C 7F02E89C 460C003C */  c.lt.s $f0, $f12
/* 061290 7F02E8A0 00000000 */  nop   
/* 061294 7F02E8A4 45020006 */  bc1fl .L7F02E8C0
/* 061298 7F02E8A8 826D0024 */   lb    $t5, 0x24($s3)
/* 06129C 7F02E8AC 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 0612A0 7F02E8B0 E7A20050 */   swc1  $f2, 0x50($sp)
/* 0612A4 7F02E8B4 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0612A8 7F02E8B8 46000306 */  mov.s $f12, $f0
.L7F02E8BC:
/* 0612AC 7F02E8BC 826D0024 */  lb    $t5, 0x24($s3)
.L7F02E8C0:
/* 0612B0 7F02E8C0 02002025 */  move  $a0, $s0
/* 0612B4 7F02E8C4 3C053F80 */  lui   $a1, 0x3f80
/* 0612B8 7F02E8C8 11A00004 */  beqz  $t5, .L7F02E8DC
/* 0612BC 7F02E8CC 3C063FCC */   lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
/* 0612C0 7F02E8D0 3C018005 */  lui   $at, %hi(D_80051FC8) # $at, 0x8005
/* 0612C4 7F02E8D4 C4308100 */  lwc1  $f16, %lo(D_80051FC8)($at)
/* 0612C8 7F02E8D8 46028081 */  sub.s $f2, $f16, $f2
.L7F02E8DC:
/* 0612CC 7F02E8DC 34C6CCCD */  ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0612D0 7F02E8E0 E7A20050 */  swc1  $f2, 0x50($sp)
/* 0612D4 7F02E8E4 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 0612D8 7F02E8E8 E7AC004C */   swc1  $f12, 0x4c($sp)
/* 0612DC 7F02E8EC C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 0612E0 7F02E8F0 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0612E4 7F02E8F4 82050030 */  lb    $a1, 0x30($s0)
/* 0612E8 7F02E8F8 44070000 */  mfc1  $a3, $f0
/* 0612EC 7F02E8FC 44066000 */  mfc1  $a2, $f12
/* 0612F0 7F02E900 02002025 */  move  $a0, $s0
/* 0612F4 7F02E904 0FC0B0B9 */  jal   chrlvSetSubroty
/* 0612F8 7F02E908 E7A20010 */   swc1  $f2, 0x10($sp)
/* 0612FC 7F02E90C A2020030 */  sb    $v0, 0x30($s0)
/* 061300 7F02E910 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E914:
/* 061304 7F02E914 C4B20028 */  lwc1  $f18, 0x28($a1)
/* 061308 7F02E918 4614903C */  c.lt.s $f18, $f20
/* 06130C 7F02E91C 00000000 */  nop   
/* 061310 7F02E920 4500000F */  bc1f  .L7F02E960
/* 061314 7F02E924 00000000 */   nop   
/* 061318 7F02E928 C4A4002C */  lwc1  $f4, 0x2c($a1)
/* 06131C 7F02E92C 02002025 */  move  $a0, $s0
/* 061320 7F02E930 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061324 7F02E934 4604A03C */  c.lt.s $f20, $f4
/* 061328 7F02E938 00000000 */  nop   
/* 06132C 7F02E93C 45000008 */  bc1f  .L7F02E960
/* 061330 7F02E940 00000000 */   nop   
/* 061334 7F02E944 44813000 */  mtc1  $at, $f6
/* 061338 7F02E948 82060039 */  lb    $a2, 0x39($s0)
/* 06133C 7F02E94C 82070038 */  lb    $a3, 0x38($s0)
/* 061340 7F02E950 0FC0B13D */  jal   chrlvUpdateAimendsideback
/* 061344 7F02E954 E7A60010 */   swc1  $f6, 0x10($sp)
/* 061348 7F02E958 10000004 */  b     .L7F02E96C
/* 06134C 7F02E95C 00008825 */   move  $s1, $zero
.L7F02E960:
/* 061350 7F02E960 0FC0B44B */  jal   chrlvResetAimend
/* 061354 7F02E964 02002025 */   move  $a0, $s0
/* 061358 7F02E968 00008825 */  move  $s1, $zero
.L7F02E96C:
/* 06135C 7F02E96C 02009025 */  move  $s2, $s0
.L7F02E970:
/* 061360 7F02E970 824F0038 */  lb    $t7, 0x38($s2)
/* 061364 7F02E974 02002025 */  move  $a0, $s0
/* 061368 7F02E978 02202825 */  move  $a1, $s1
/* 06136C 7F02E97C 11E000A2 */  beqz  $t7, .L7F02EC08
/* 061370 7F02E980 00000000 */   nop   
/* 061374 7F02E984 824E003A */  lb    $t6, 0x3a($s2)
/* 061378 7F02E988 55C0006A */  bnezl $t6, .L7F02EB34
/* 06137C 7F02E98C 82090031 */   lb    $t1, 0x31($s0)
/* 061380 7F02E990 8E05002C */  lw    $a1, 0x2c($s0)
/* 061384 7F02E994 02002025 */  move  $a0, $s0
/* 061388 7F02E998 00003025 */  move  $a2, $zero
/* 06138C 7F02E99C C4A80018 */  lwc1  $f8, 0x18($a1)
/* 061390 7F02E9A0 4614403E */  c.le.s $f8, $f20
/* 061394 7F02E9A4 00000000 */  nop   
/* 061398 7F02E9A8 45000046 */  bc1f  .L7F02EAC4
/* 06139C 7F02E9AC 00000000 */   nop   
/* 0613A0 7F02E9B0 C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 0613A4 7F02E9B4 02202825 */  move  $a1, $s1
/* 0613A8 7F02E9B8 460AA03C */  c.lt.s $f20, $f10
/* 0613AC 7F02E9BC 00000000 */  nop   
/* 0613B0 7F02E9C0 45000040 */  bc1f  .L7F02EAC4
/* 0613B4 7F02E9C4 00000000 */   nop   
/* 0613B8 7F02E9C8 02002025 */  move  $a0, $s0
/* 0613BC 7F02E9CC 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0613C0 7F02E9D0 24060001 */   li    $a2, 1
/* 0613C4 7F02E9D4 82190007 */  lb    $t9, 7($s0)
/* 0613C8 7F02E9D8 3C188004 */  lui   $t8, %hi(g_GlobalTimer) # $t8, 0x8004
/* 0613CC 7F02E9DC 8F180FFC */  lw    $t8, %lo(g_GlobalTimer)($t8)
/* 0613D0 7F02E9E0 2401000A */  li    $at, 10
/* 0613D4 7F02E9E4 17210031 */  bne   $t9, $at, .L7F02EAAC
/* 0613D8 7F02E9E8 AE180044 */   sw    $t8, 0x44($s0)
/* 0613DC 7F02E9EC 8E05002C */  lw    $a1, 0x2c($s0)
/* 0613E0 7F02E9F0 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0613E4 7F02E9F4 44813000 */  mtc1  $at, $f6
/* 0613E8 7F02E9F8 C4B0001C */  lwc1  $f16, 0x1c($a1)
/* 0613EC 7F02E9FC C4B20018 */  lwc1  $f18, 0x18($a1)
/* 0613F0 7F02EA00 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0613F4 7F02EA04 44815000 */  mtc1  $at, $f10
/* 0613F8 7F02EA08 46128101 */  sub.s $f4, $f16, $f18
/* 0613FC 7F02EA0C 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 061400 7F02EA10 44818000 */  mtc1  $at, $f16
/* 061404 7F02EA14 46062202 */  mul.s $f8, $f4, $f6
/* 061408 7F02EA18 460A4003 */  div.s $f0, $f8, $f10
/* 06140C 7F02EA1C 4610003C */  c.lt.s $f0, $f16
/* 061410 7F02EA20 00000000 */  nop   
/* 061414 7F02EA24 4502001C */  bc1fl .L7F02EA98
/* 061418 7F02EA28 4405C000 */   mfc1  $a1, $f24
/* 06141C 7F02EA2C 4600048D */  trunc.w.s $f18, $f0
/* 061420 7F02EA30 8E080040 */  lw    $t0, 0x40($s0)
/* 061424 7F02EA34 240C0032 */  li    $t4, 50
/* 061428 7F02EA38 02602025 */  move  $a0, $s3
/* 06142C 7F02EA3C 440A9000 */  mfc1  $t2, $f18
/* 061430 7F02EA40 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 061434 7F02EA44 000A5840 */  sll   $t3, $t2, 1
/* 061438 7F02EA48 018B6823 */  subu  $t5, $t4, $t3
/* 06143C 7F02EA4C 010D082A */  slt   $at, $t0, $t5
/* 061440 7F02EA50 54200008 */  bnezl $at, .L7F02EA74
/* 061444 7F02EA54 4406B000 */   mfc1  $a2, $f22
/* 061448 7F02EA58 4405C000 */  mfc1  $a1, $f24
/* 06144C 7F02EA5C 4406B000 */  mfc1  $a2, $f22
/* 061450 7F02EA60 0FC1BFFB */  jal   modelSetAnimSpeed
/* 061454 7F02EA64 02602025 */   move  $a0, $s3
/* 061458 7F02EA68 1000006A */  b     .L7F02EC14
/* 06145C 7F02EA6C 26310001 */   addiu $s1, $s1, 1
/* 061460 7F02EA70 4406B000 */  mfc1  $a2, $f22
.L7F02EA74:
/* 061464 7F02EA74 0FC1BFFB */  jal   modelSetAnimSpeed
/* 061468 7F02EA78 34A5CCCD */   ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 06146C 7F02EA7C 3C0E8004 */  lui   $t6, %hi(g_ClockTimer) # $t6, 0x8004
/* 061470 7F02EA80 8DCE0FF4 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 061474 7F02EA84 8E0F0040 */  lw    $t7, 0x40($s0)
/* 061478 7F02EA88 01EEC021 */  addu  $t8, $t7, $t6
/* 06147C 7F02EA8C 10000060 */  b     .L7F02EC10
/* 061480 7F02EA90 AE180040 */   sw    $t8, 0x40($s0)
/* 061484 7F02EA94 4405C000 */  mfc1  $a1, $f24
.L7F02EA98:
/* 061488 7F02EA98 4406B000 */  mfc1  $a2, $f22
/* 06148C 7F02EA9C 0FC1BFFB */  jal   modelSetAnimSpeed
/* 061490 7F02EAA0 02602025 */   move  $a0, $s3
/* 061494 7F02EAA4 1000005B */  b     .L7F02EC14
/* 061498 7F02EAA8 26310001 */   addiu $s1, $s1, 1
.L7F02EAAC:
/* 06149C 7F02EAAC 4405C000 */  mfc1  $a1, $f24
/* 0614A0 7F02EAB0 4406B000 */  mfc1  $a2, $f22
/* 0614A4 7F02EAB4 0FC1BFFB */  jal   modelSetAnimSpeed
/* 0614A8 7F02EAB8 02602025 */   move  $a0, $s3
/* 0614AC 7F02EABC 10000055 */  b     .L7F02EC14
/* 0614B0 7F02EAC0 26310001 */   addiu $s1, $s1, 1
.L7F02EAC4:
/* 0614B4 7F02EAC4 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0614B8 7F02EAC8 02202825 */   move  $a1, $s1
/* 0614BC 7F02EACC 82190007 */  lb    $t9, 7($s0)
/* 0614C0 7F02EAD0 2401000A */  li    $at, 10
/* 0614C4 7F02EAD4 02002025 */  move  $a0, $s0
/* 0614C8 7F02EAD8 1721000C */  bne   $t9, $at, .L7F02EB0C
/* 0614CC 7F02EADC 3C063F4C */   lui   $a2, 0x3f4c
/* 0614D0 7F02EAE0 4405C000 */  mfc1  $a1, $f24
/* 0614D4 7F02EAE4 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0614D8 7F02EAE8 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0614DC 7F02EAEC 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 0614E0 7F02EAF0 02002025 */   move  $a0, $s0
/* 0614E4 7F02EAF4 44050000 */  mfc1  $a1, $f0
/* 0614E8 7F02EAF8 4406B000 */  mfc1  $a2, $f22
/* 0614EC 7F02EAFC 0FC1BFFB */  jal   modelSetAnimSpeed
/* 0614F0 7F02EB00 02602025 */   move  $a0, $s3
/* 0614F4 7F02EB04 10000043 */  b     .L7F02EC14
/* 0614F8 7F02EB08 26310001 */   addiu $s1, $s1, 1
.L7F02EB0C:
/* 0614FC 7F02EB0C 4405C000 */  mfc1  $a1, $f24
/* 061500 7F02EB10 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 061504 7F02EB14 34C6CCCD */   ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 061508 7F02EB18 44050000 */  mfc1  $a1, $f0
/* 06150C 7F02EB1C 4406B000 */  mfc1  $a2, $f22
/* 061510 7F02EB20 0FC1BFFB */  jal   modelSetAnimSpeed
/* 061514 7F02EB24 02602025 */   move  $a0, $s3
/* 061518 7F02EB28 1000003A */  b     .L7F02EC14
/* 06151C 7F02EB2C 26310001 */   addiu $s1, $s1, 1
/* 061520 7F02EB30 82090031 */  lb    $t1, 0x31($s0)
.L7F02EB34:
/* 061524 7F02EB34 02002025 */  move  $a0, $s0
/* 061528 7F02EB38 00003025 */  move  $a2, $zero
/* 06152C 7F02EB3C 1520002E */  bnez  $t1, .L7F02EBF8
/* 061530 7F02EB40 00000000 */   nop   
/* 061534 7F02EB44 82020032 */  lb    $v0, 0x32($s0)
/* 061538 7F02EB48 12220004 */  beq   $s1, $v0, .L7F02EB5C
/* 06153C 7F02EB4C 02025021 */   addu  $t2, $s0, $v0
/* 061540 7F02EB50 814C003A */  lb    $t4, 0x3a($t2)
/* 061544 7F02EB54 15800028 */  bnez  $t4, .L7F02EBF8
/* 061548 7F02EB58 00000000 */   nop   
.L7F02EB5C:
/* 06154C 7F02EB5C 8E05002C */  lw    $a1, 0x2c($s0)
/* 061550 7F02EB60 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 061554 7F02EB64 4600B03E */  c.le.s $f22, $f0
/* 061558 7F02EB68 00000000 */  nop   
/* 06155C 7F02EB6C 4502000B */  bc1fl .L7F02EB9C
/* 061560 7F02EB70 4616003C */   c.lt.s $f0, $f22
/* 061564 7F02EB74 4614003E */  c.le.s $f0, $f20
/* 061568 7F02EB78 00000000 */  nop   
/* 06156C 7F02EB7C 45020007 */  bc1fl .L7F02EB9C
/* 061570 7F02EB80 4616003C */   c.lt.s $f0, $f22
/* 061574 7F02EB84 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 061578 7F02EB88 4604A03E */  c.le.s $f20, $f4
/* 06157C 7F02EB8C 00000000 */  nop   
/* 061580 7F02EB90 4503000B */  bc1tl .L7F02EBC0
/* 061584 7F02EB94 82080033 */   lb    $t0, 0x33($s0)
/* 061588 7F02EB98 4616003C */  c.lt.s $f0, $f22
.L7F02EB9C:
/* 06158C 7F02EB9C 00000000 */  nop   
/* 061590 7F02EBA0 45000015 */  bc1f  .L7F02EBF8
/* 061594 7F02EBA4 00000000 */   nop   
/* 061598 7F02EBA8 C4A60018 */  lwc1  $f6, 0x18($a1)
/* 06159C 7F02EBAC 4614303E */  c.le.s $f6, $f20
/* 0615A0 7F02EBB0 00000000 */  nop   
/* 0615A4 7F02EBB4 45000010 */  bc1f  .L7F02EBF8
/* 0615A8 7F02EBB8 00000000 */   nop   
/* 0615AC 7F02EBBC 82080033 */  lb    $t0, 0x33($s0)
.L7F02EBC0:
/* 0615B0 7F02EBC0 24060001 */  li    $a2, 1
/* 0615B4 7F02EBC4 00C25823 */  subu  $t3, $a2, $v0
/* 0615B8 7F02EBC8 250D0001 */  addiu $t5, $t0, 1
/* 0615BC 7F02EBCC A2060031 */  sb    $a2, 0x31($s0)
/* 0615C0 7F02EBD0 A20B0032 */  sb    $t3, 0x32($s0)
/* 0615C4 7F02EBD4 A20D0033 */  sb    $t5, 0x33($s0)
/* 0615C8 7F02EBD8 3C0F8004 */  lui   $t7, %hi(g_GlobalTimer) # $t7, 0x8004
/* 0615CC 7F02EBDC 8DEF0FFC */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 0615D0 7F02EBE0 02002025 */  move  $a0, $s0
/* 0615D4 7F02EBE4 02202825 */  move  $a1, $s1
/* 0615D8 7F02EBE8 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0615DC 7F02EBEC AE0F0044 */   sw    $t7, 0x44($s0)
/* 0615E0 7F02EBF0 10000008 */  b     .L7F02EC14
/* 0615E4 7F02EBF4 26310001 */   addiu $s1, $s1, 1
.L7F02EBF8:
/* 0615E8 7F02EBF8 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0615EC 7F02EBFC 02202825 */   move  $a1, $s1
/* 0615F0 7F02EC00 10000004 */  b     .L7F02EC14
/* 0615F4 7F02EC04 26310001 */   addiu $s1, $s1, 1
.L7F02EC08:
/* 0615F8 7F02EC08 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0615FC 7F02EC0C 00003025 */   move  $a2, $zero
.L7F02EC10:
/* 061600 7F02EC10 26310001 */  addiu $s1, $s1, 1
.L7F02EC14:
/* 061604 7F02EC14 24010002 */  li    $at, 2
/* 061608 7F02EC18 1621FF55 */  bne   $s1, $at, .L7F02E970
/* 06160C 7F02EC1C 26520001 */   addiu $s2, $s2, 1
/* 061610 7F02EC20 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F02EC24:
/* 061614 7F02EC24 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 061618 7F02EC28 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 06161C 7F02EC2C D7B80028 */  ldc1  $f24, 0x28($sp)
/* 061620 7F02EC30 8FB00034 */  lw    $s0, 0x34($sp)
/* 061624 7F02EC34 8FB10038 */  lw    $s1, 0x38($sp)
/* 061628 7F02EC38 8FB2003C */  lw    $s2, 0x3c($sp)
/* 06162C 7F02EC3C 8FB30040 */  lw    $s3, 0x40($sp)
/* 061630 7F02EC40 03E00008 */  jr    $ra
/* 061634 7F02EC44 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif

//#endif


/**
 * Address 0x7F02EBFC (VERSION_US).
 * Adresss 0x7F02EF04 (other).
*/
void chrlvTickAttack(ChrRecord *self)
{
    Model *self_model;
    f32 temp_f0;
    f32 phi_f2;

    self_model = self->model;
    temp_f0 = objecthandlerGetModelField28(self_model);

    if (self->act_attack.type_of_motion)
    {
        if (self->act_attack.type_of_motion == 1)
        {
            if (self->act_attack.animfloats->anonymous_9 >= 0.0f)
            {
                phi_f2 = self->act_attack.animfloats->anonymous_9;
            }
            else
            {
                phi_f2 = self->act_attack.animfloats->anonymous_7;
            }

            modelSetAnimation(
                self_model,
                objecthandlerGetModelAnim(self_model),
                (s32) self_model->gunhand,
                phi_f2,
                chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
                16.0f);
            
            if (self->act_attack.animfloats->anonymous_5 >= 0.0f)
            {
                modelSetAnimEndFrame(self_model, self->act_attack.animfloats->anonymous_5);
            }

            self->act_attack.type_of_motion = 2;
            chrlvResetAimend(self);

            return;
        }

        if (self->act_attack.type_of_motion == 2)
        {
            if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
            {
#if defined(VERSION_US)
                self->act_attack.attacktype |= 0x20;
#else
                // don't set 0x20
#endif
                self->act_attack.attacktype &= ~0x40;

                if (self->act_attack.unk54 != 0)
                {
                    sub_GAME_7F025560(self, (s32) self->act_attack.attacktype, self->act_attack.entityid);

                    return;
                }

                sub_GAME_7F0256F0(self, (s32) self->act_attack.attacktype, self->act_attack.entityid);

                return;
            }

            return;
        }
    }

    if ((self->act_attack.attacktype & 0x20) != 0)
    {
        if ((self->act_attack.attacktype & 0x40) != 0)
        {
            if (chrlvUpdateAimendsideback(self, self->act_attack.animfloats, (s32) self->act_attack.unk38[1], (s32) self->act_attack.unk38[0], 0.2f) == 0)
            {
                self->act_attack.type_of_motion = 1;
            }

            return;
        }

        if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
        {
            self->act_attack.attacktype |= 0x40;
            self->act_attack.unk30 = 2;

            return;
        }
    }

    if (self->act_attack.unk36 == 0)
    {
        if ((self->act_attack.animfloats->anonymous_9 > 0.0f) && (temp_f0 <= self->act_attack.animfloats->anonymous_9))
        {
            if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
            {
                modelSetAnimation(
                    self_model,
                    objecthandlerGetModelAnim(self_model),
                    (s32) self_model->gunhand,
                    self->act_attack.animfloats->anonymous_9,
                    chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f),
                    16.0f);
                
                if (self->act_attack.unk37 != 0)
                {
                    if (self->act_attack.animfloats->anonymous_5 >= 0.0f)
                    {
                        modelSetAnimEndFrame(self_model, self->act_attack.animfloats->anonymous_5);
                    }
                }
                else
                {
                    modelSetAnimEndFrame(self_model, self->act_attack.animfloats->anonymous_7);
                }
            }
        }
    }

    chrlvTickAttackCommon(self);
}





/**
 * Address 0x7F02EEE0.
*/
void chrlvTickAttackRoll(ChrRecord *self)
{
    Model *temp_a0; // 68
    f32 temp_f0;
    struct weapon_firing_animation_table *phi_v1; // 60
    s32 sp38; // 56
    f32 phi_f2_2; // 52
    struct modeldata_root *temp_v0_2;
    struct weapon_firing_animation_table *temp_v0;

    if (self->act_attackroll.unk35 != 0)
    {
        temp_a0 = self->model;
        temp_f0 = objecthandlerGetModelField28(temp_a0);

        if (
            (self->act_attackroll.animfloats == &D_80030078[4])
            || (self->act_attackroll.animfloats == &D_80030078[5])
            || (self->act_attackroll.animfloats == &D_80030078[6])
            || (self->act_attackroll.animfloats == &D_80030078[7])
        )
        {
            if (self->act_attackroll.animfloats->anonymous_5 <= temp_f0)
            {
                sp38 = (s32) temp_a0->gunhand;
                phi_v1 = &self->act_attackroll.animfloats[4];

                phi_f2_2 = 16.0f;

                if ((self->act_attackroll.unk38[1] != 0) && (self->act_attackroll.unk38[0] != 0))
                {
                    if ((randomGetNext() & 1) == 0)
                    {
                        phi_v1 = &phi_v1[4];
                    }
                    else
                    {
                        phi_v1 = &phi_v1[8];
                    }
                }

                if (phi_v1 == &D_80030078[8])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[9])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[10])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[11])
                {
                    phi_f2_2 = 44.0f;
                }
                else if (phi_v1 == &D_80030078[12])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[13])
                {
                    phi_f2_2 = 34.0f;
                }
                else if (phi_v1 == &D_80030078[14])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[15])
                {
                    phi_f2_2 = 44.0f;
                }
                else if (phi_v1 == &D_80030078[16])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[17])
                {
                    phi_f2_2 = 34.0f;
                }
                else if (phi_v1 == &D_80030078[18])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[19])
                {
                    phi_f2_2 = 44.0f;
                }

                self->act_attackroll.unk30 = 2;
                self->act_attackroll.animfloats = phi_v1;
                self->sleep = 0;
                
                modelSetAnimation(temp_a0, (void *) phi_v1->anonymous_0, sp38, phi_v1->anonymous_4, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), phi_f2_2);
                
                if (self->act_attackroll.unk36 != 0)
                {
                    if (phi_v1->anonymous_9 >= 0.0f)
                    {
                        modelSetAnimEndFrame(temp_a0, phi_v1->anonymous_9);
                    }
                    else
                    {
                        modelSetAnimEndFrame(temp_a0, phi_v1->anonymous_7);
                    }
                }
                else if (phi_v1->anonymous_8 >= 0.0f)
                {
                    modelSetAnimEndFrame(temp_a0, phi_v1->anonymous_8);
                }
                else if (phi_v1->anonymous_5 >= 0.0f)
                {
                    modelSetAnimEndFrame(temp_a0, phi_v1->anonymous_5);
                }

                if (self->act_attackroll.animfloats->anonymous_3 != 0.0f)
                {
                    temp_v0_2 = (struct modeldata_root *)extract_id_from_object_structure_microcode(temp_a0, temp_a0->obj->RootNode);
                    temp_v0_2->unk5c = phi_f2_2;
                    temp_v0_2->unk58 = (-self->act_attackroll.animfloats->anonymous_3 / phi_f2_2);

                    if (sp38 != GUNRIGHT)
                    {
                        temp_v0_2->unk58 = -temp_v0_2->unk58;
                    }
                }
            }
        }
        else if (
            (
                (self->act_attackroll.animfloats == &D_80030078[8])
                || (self->act_attackroll.animfloats == &D_80030078[9])
                || (self->act_attackroll.animfloats == &D_80030078[10])
                || (self->act_attackroll.animfloats == &D_80030078[11]) 
                || (self->act_attackroll.animfloats == &D_80030078[12])
                || (self->act_attackroll.animfloats == &D_80030078[13])
                || (self->act_attackroll.animfloats == &D_80030078[14])
                || (self->act_attackroll.animfloats == &D_80030078[15])
                || (self->act_attackroll.animfloats == &D_80030078[16])
                || (self->act_attackroll.animfloats == &D_80030078[17])
                || (self->act_attackroll.animfloats == &D_80030078[18])
                || (self->act_attackroll.animfloats == &D_80030078[19])
            ) 
            && (self->act_attackroll.unk36 == 0))
        {
            if ((self->act_attackroll.animfloats->anonymous_9 > 0.0f) && (temp_f0 <= self->act_attackroll.animfloats->anonymous_9))
            {
                if (sub_GAME_7F06F5C4(temp_a0) <= temp_f0)
                {
                    modelSetAnimation(temp_a0, objecthandlerGetModelAnim(temp_a0), (s32) temp_a0->gunhand, self->act_attackroll.animfloats->anonymous_9, chrlvGetGuard007SpeedRating(self, 0.5f, 0.8f), 16.0f);
                    
                    if (self->act_attackroll.unk37 != 0)
                    {
                        if (self->act_attackroll.animfloats->anonymous_5 >= 0.0f)
                        {
                            modelSetAnimEndFrame(temp_a0, self->act_attackroll.animfloats->anonymous_5);
                        }
                    }
                    else
                    {
                        modelSetAnimEndFrame(temp_a0, self->act_attackroll.animfloats->anonymous_7);
                    }
                }
            }
        }
    }
    chrlvTickAttackCommon(self);
}




/**
 * Address 0x7F02F3F8.
*/
void chrlvTickThrowGrenade(ChrRecord *self)
{
    Model *self_model;
    f32 temp_f2;
    s32 gunhand;
    PropRecord *held_prop;

    self_model = self->model;
    temp_f2 = objecthandlerGetModelField28(self_model);
    gunhand = (self_model->gunhand != GUNRIGHT) ? GUNLEFT : GUNRIGHT;
    held_prop = chrGetEquippedWeaponProp(self, gunhand);

    if ((temp_f2 >= 20.0f) && (held_prop != NULL))
    {
        struct ObjectRecord *obj = held_prop->obj;
        obj->runtime_bitflags &= ~0x800;
    }

    if ((temp_f2 >= 61.0f) && (held_prop != NULL))
    {
        struct WeaponObjRecord *weap = held_prop->weapon;
        weap->timer = CHRLV_DEFAULT_TIMER;
    }

    if ((temp_f2 >= 119.0f) && (held_prop != NULL))
    {
        propobjSetDropped(self->weapons_held[gunhand], 3);
        self->hidden |= 1;
    }

    if (objecthandlerGetModelField28(self_model) >= sub_GAME_7F06F5C4(self_model))
    {
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    if ((temp_f2 >= 87.0f) && (temp_f2 <= 110.0f))
    {
        chrlvSetSubroty(self, 1, 110.0f, chrlvGetGuard007SpeedRating(self, 1.0f, 1.6f), 0.0f);
    }
}




/**
 * Address 0x7F02F5A4.
*/
void chrlvTickBondIntro(ChrRecord *self)
{
    Model *self_model;
    f32 sp28;

    self_model = self->model;
    sp28 = objecthandlerGetModelField28(self_model);

    if ((sp28 < 86.0f) && (sub_GAME_7F06F5C4(self_model) <= sp28))
    {
        modelSetAnimation(
            self_model,
            (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_standing_draw_one_handed_weapon_fast],
            0,
            86.0f,
            modelGetAnimSpeed(self_model),
            24.0f);

        modelSetAnimEndFrame(self_model, 131.0f);

        return;
    }

    if (sub_GAME_7F06F5C4(self_model) <= sp28)
    {
        chrlvKneelingAnimationRelated(self);
    }
}



/**
 * Address 0x7F02F688.
*/
void chrlvTickBondDieRemoved(ChrRecord *self)
{
    // removed.
}


#if defined(REFRESH_NTSC)
/* NTSC */
#define MAX_SPEED_A 0.2991993f
#define ACCEL_A 0.014959966f

#define MAX_SPEED_B1 0.019634955f
#define MAX_SPEED_B2 0.09817477f
#define MAX_SPEED_B3 0.19634955f
#define ACCEL_B 0.014959966f

#define MAX_SPEED_C1 0.009817477f
#define MAX_SPEED_C2 0.049087387f
#define MAX_SPEED_C3 0.12566371f
#define ACCEL_C 0.009817477f
#endif

#if defined(REFRESH_PAL)
/* PAL */
#define MAX_SPEED_A 0.359039157629013f
#define ACCEL_A 0.0179519578814507f

#define MAX_SPEED_B1 0.0235619451850653f
#define MAX_SPEED_B2 0.117809727787972f
#define MAX_SPEED_B3 0.235619455575943f
#define ACCEL_B 0.0179519578814507f

#define MAX_SPEED_C1 0.0117809725925326f
#define MAX_SPEED_C2 0.0589048638939858f
#define MAX_SPEED_C3 0.150796458125114f
#define ACCEL_C 0.0117809725925326f
#endif

/**
 * Address 0x7F02F690.
*/
s32 chrlvApplySpeed(ChrRecord *self, coord3d *arg1, s32 arg2, f32 *speedPtr)
{
    f32 maxSpeed;
    Model *self_model; // 72
    PropRecord *self_prop;
    f32 accel;
    f32 maxFrac; // 60
    f32 openPosition; // 56
    f32 phi_f2;
    f32 f0f0;
    f32 dx;
    f32 dz;
    s32 sp24;

    self_prop = self->prop;
    self_model = self->model;

    dx = arg1->f[0] - self_prop->pos.f[0];
    dz = arg1->f[2] - self_prop->pos.f[2];

    maxFrac = atan2f(dx, dz);
    openPosition = getsubroty(self_model);

    sp24 = 0;
    phi_f2 = maxFrac - openPosition;

    if (maxFrac < openPosition)
    {
        phi_f2 = phi_f2 + M_TAU_F;
    }

    f0f0 = phi_f2;

    if (phi_f2 > M_PI_F)
    {
        f0f0 = M_TAU_F - phi_f2;
    }

    if (arg2 == 2)
    {
        maxSpeed = MAX_SPEED_A;
        accel = ACCEL_A;
    }
    else if (arg2 == 1)
    {
        if (f0f0 < 0.3926991f)
        {
            maxSpeed = MAX_SPEED_B1;
        }
        else if (f0f0 < 1.2566371f)
        {
            maxSpeed = MAX_SPEED_B2;
        }
        else
        {
            maxSpeed = MAX_SPEED_B3;
        }

        accel = ACCEL_B;
    }
    else
    {
        if (f0f0 < 0.3926991f)
        {
            maxSpeed = MAX_SPEED_C1;
        }
        else if (f0f0 < 1.2566371f)
        {
            maxSpeed = MAX_SPEED_C2;
        }
        else
        {
            maxSpeed = MAX_SPEED_C3;
        }

        accel = ACCEL_C;
    }

    maxSpeed *= self_model->unka4;
    accel *= self_model->unka4;

    // void chrobjCallsApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed)
    chrobjCallsApplySpeed(
        &openPosition,
        maxFrac,
        speedPtr,
        accel,
        accel * 2.0f,
        maxSpeed);

    if (openPosition == maxFrac)
    {
        *speedPtr = 0.0f;
        sp24 = 1;
    }

    setsubroty(self_model, openPosition);

    return sp24;
}



/**
 * Address 0x7F02F888.
*/
void chrlvTickAttackWalk(ChrRecord *self)
{
    Model *self_model;
    PropRecord *player_prop;
    f32 temp_f0;
    f32 temp_f2;
    PropRecord *self_prop;
    s32 i;

    self_model = self->model;
    self_prop = self->prop;
    player_prop = get_curplayer_positiondata();
    self->act_attackwalk.clock_timer30 += g_ClockTimer;
    self->lastwalk60 = g_GlobalTimer;

    if (
        (self->invalidmove == 1)
        || (self->lastmoveok60 < (g_GlobalTimer - CHRLV_LASTMOVEOK60_CHECK))
        || (self->act_attackwalk.clock_timer34 < self->act_attackwalk.clock_timer30))
    {
        if (objecthandlerGetModelField28(self_model) > ((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f))
        {
            sub_GAME_7F06FE90(self_model, 0.0f, 16.0f);
        }
        else
        {
            sub_GAME_7F06FE90(self_model, (f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f, 16.0f);
        }

        chrlvSetTargetToPlayer(self);
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    temp_f0 = player_prop->pos.f[0] - self_prop->pos.f[0];
    temp_f2 = player_prop->pos.f[2] - self_prop->pos.f[2];
    if ((temp_f0 < 300.0f) && (temp_f0 > -300.0f) && (temp_f2 < 300.0f) && (temp_f2 > -300.0f))
    {
        chrlvSetTargetToPlayer(self);
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    if (chrlvApplySpeed(self, &player_prop->pos, 0, &self->act_attackwalk.speed) != 0)
    {
        self->act_attackwalk.unk038 = 1;
    }

    if (self->act_attackwalk.clock_timer30 >= CHRLV_ATTACKWALK_CLOCK_TIMER30_MIN)
    {
        chrlvUpdateAimendsideback(self, self->act_attackwalk.animfloats, (s32) self->act_attackwalk.unk48[1], (s32) self->act_attackwalk.unk48[0], 1.0f);
    }
    else
    {
        chrlvResetAimend(self);
    }

    if (self->act_attackwalk.unk038 && !(self->act_attackwalk.clock_timer30 < CHRLV_ATTACKWALK_CLOCK_TIMER30_MAX))
    {
        for (i=0; i<2; i++)
        {
            if (self->act_attackwalk.unk48[i])
            {
                if (self->act_attackwalk.unk4a[i] == 0)
                {
                    chrlvToggleHiddenRelated(self, i, 1);
                }
                else
                {
                    if ((self->act_attackwalk.timer40 < self->act_attackwalk.clock_timer30)
                        && ((i == self->act_attackwalk.unk044) || (self->act_attackwalk.unk4a[self->act_attackwalk.unk044] == 0)))
                    {
                        self->act_attackwalk.timer40 = self->act_attackwalk.clock_timer30;

                        if (self->act_attackwalk.unk4a[1 - i])
                        {
                            if (self->act_attackwalk.unk4C[i])
                            {
                                self->act_attackwalk.timer40 += CHRLV_ATTACKWALK_TIMER40_A;
                            }
                            else
                            {
                                self->act_attackwalk.timer40 += CHRLV_ATTACKWALK_TIMER40_B;
                            }
                        }
                        else if (self->act_attackwalk.unk4C[i])
                        {
                            self->act_attackwalk.timer40 += CHRLV_ATTACKWALK_TIMER40_C;
                        }
                        else
                        {
                            self->act_attackwalk.timer40 += CHRLV_ATTACKWALK_TIMER40_D;
                        }

                        self->act_attackwalk.unk044 = 1 - self->act_attackwalk.unk044;

                        chrlvToggleHiddenRelated(self, i, 1);
                    }
                    else
                    {
                        chrlvToggleHiddenRelated(self, i, 0);
                    }
                }
            }
            else
            {
                chrlvToggleHiddenRelated(self, i, 0);
            }
        }

        return;
    }

    chrlvToggleHiddenRelated(self, GUNLEFT, 0);
    chrlvToggleHiddenRelated(self, GUNRIGHT, 0);
}




/**
 * @param arg0: point in 3d
 * @param arg1: 3 vec
 * @param arg0: point in 3d
 * @param arg0: scalar value
 * 
 * Address 0x7F02FC34.
*/
s32 chrlvGeometryRelated7F02FC34(coord3d *arg0, coord3d *arg1, coord3d *arg2, f32 arg3)
{
    coord3d dd;
    f32 temp_f14;

    dd.f[0] = arg2->f[0] - arg0->f[0];
    dd.f[2] = arg2->f[2] - arg0->f[2];
    
    if ((arg1->f[0] == 0.0f) && (arg1->f[2] == 0.0f))
    {
        return ((dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2])) <= (arg3 * arg3);
    }

    temp_f14 = (arg1->f[0] * dd.f[0]) + (arg1->f[2] * dd.f[2]);

    if (temp_f14 > 0.0f)
    {
        f32 tf14_2 = temp_f14 * temp_f14;
        f32 f2 = (arg1->f[0] * arg1->f[0]) + (arg1->f[2] * arg1->f[2]);
        f32 f3 = (dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]);

        if ((f2 * (f3 - (arg3 * arg3))) <= tf14_2)
        {
            return 1;
        }

        return 0;
    }

    return 0;
}



/**
 * @param prevpos: point in 3d
 * @param curpos: 3 vec
 * @param prevpos: point in 3d
 * @param prevpos: scalar value
 * 
 * Address 0x7F02FD50.
 * 
 * PD posIsArrivingLaterallyAtPos.
*/
s32 chrlvIsArrivingLaterallyAtPos(coord3d *prevpos, coord3d *curpos, coord3d *targetpos, f32 range)
{
    coord3d sp34;

    if ((prevpos->f[0] <= targetpos->f[0] - range) && (curpos->f[0] <= targetpos->f[0] - range))
    {
        return 0;
    }

    if ((targetpos->f[0] + range <= prevpos->f[0]) && (targetpos->f[0] + range <= curpos->f[0]))
    {
        return 0;
    }

    if ((prevpos->f[2] <= targetpos->f[2] - range) && (curpos->f[2] <= targetpos->f[2] - range))
    {
        return 0;
    }

    if ((targetpos->f[2] + range <= prevpos->f[2]) && (targetpos->f[2] + range <= curpos->f[2]))
    {
        return 0;
    }

    sp34.f[0] = curpos->f[0] - prevpos->f[0];
    sp34.f[1] = 0.0f;
    sp34.f[2] = curpos->f[2] - prevpos->f[2];

    return chrlvGeometryRelated7F02FC34(prevpos, &sp34, targetpos, range);
}



/**
 * Address 0x7F02FE78.
 * PD chrTickRunPos
*/
void chrlvTickRunPos(ChrRecord *self)
{
    PropRecord *self_prop;
    Model *self_model;
    f32 phi_f2; // 52

    self_prop = self->prop;
    self_model = self->model;
    self->lastwalk60 = g_GlobalTimer;

    if(1)
    {
        // removed
    }

    if ((self->invalidmove == 1)
        || (self->lastmoveok60 < (g_GlobalTimer - CHRLV_LASTMOVEOK60_CHECK))
        || (chrlvIsArrivingLaterallyAtPos(&self->prevpos, &self_prop->pos, &self->act_runpos.pos, self->act_runpos.neardist)))
    {
        f32 offset = 0;

        // Maybe had debug side effects, otherwise this doesn't do anything.
        objecthandlerGetModelAnim(self_model);

        phi_f2 = objecthandlerGetModelField28(self_model) - offset;
        
        if (phi_f2 < 0.0f)
        {
            phi_f2 += (f32)objecthandlerGetModelAnim(self_model)->unk04;
        }

        if (((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f) < phi_f2)
        {
            phi_f2 = (f32)objecthandlerGetModelAnim(self_model)->unk04 - offset;
            sub_GAME_7F06FE90(self_model, phi_f2, 16.0f);
        }
        else
        {
            phi_f2 = ((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f) - offset;

            if (phi_f2 < 0)
            {
                phi_f2 += (f32)objecthandlerGetModelAnim(self_model)->unk04;
            }

            sub_GAME_7F06FE90(self_model, phi_f2, 16.0f);
        }

        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    chrlvApplySpeed(self, &self->act_runpos.pos, 1, &self->act_runpos.turnspeed);

    if (self->act_runpos.eta60 > 0)
    {
        self->act_runpos.eta60 -= g_ClockTimer;
    }
    else
    {
        f32 sp2C;

        sp2C = D_80030988;

        if ((s32)objecthandlerGetModelAnim(self_model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon])
        {
            sp2C = D_80030994;
        }

        self->act_runpos.neardist += sp2C * g_GlobalTimerDelta * modelGetAbsAnimSpeed(self_model);
    }
}



/**
 * Address 0x7F030128.
*/
s32 sub_GAME_7F030128(ChrRecord *self, coord3d *point, StandTile *arg2, coord3d *dest, StandTile * arg4, s32 objflags)
{
    StandTile *sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    sp44 = arg2;
    sp40 = 0;
    
    chrGetChrWidthHeight(self->prop, &sp34, &sp3C, &sp38);
    
    set_or_unset_GUARDdata_flag(self, 0);
    
    if (
        sub_GAME_7F0B0E24(&sp44, point->f[0], point->f[2], dest->f[0], dest->f[2], objflags, sp3C, sp38, 0.0f, 1.0f) 
        && ((arg4 == NULL) || (sp44 == arg4)))
    {
        sp40 = 1;
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return sp40;
}



/**
 * Address 0x7F0301FC.
*/
s32 sub_GAME_7F0301FC(ChrRecord *self, coord3d *point, StandTile *arg2, coord3d *dest, f32 arg4, s32 arg5)
{
    StandTile *pstan;
    coord3d dd;
    f32 temp_f20;
    f32 temp_f22;
    f32 norm;
    s32 ret; // 104
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    ret = 0;

    chrGetChrWidthHeight(self->prop, &sp5C, &sp64, &sp60);

    dd.f[0] = dest->f[0] - point->f[0];
    dd.f[1] = 0.0f;
    dd.f[2] = dest->f[2] - point->f[2];

    if ((dd.f[0] == 0.0f) && (dd.f[2] == 0.0f))
    {
        ret = 1;
    }
    else
    {
        norm = (dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]);
        norm = 1.0f / sqrtf(norm);
        
        dd.f[0] *= norm;
        dd.f[2] *= norm;

        temp_f20 = arg4 * dd.f[0];
        temp_f22 = arg4 * dd.f[2];

        set_or_unset_GUARDdata_flag(self, 0);

        pstan = arg2;

        if (sub_GAME_7F0B0E24(&pstan, point->f[0], point->f[2], point->f[0] + temp_f22, point->f[2] - temp_f20, arg5, sp64, sp60, 0.0f, 1.0f)
            && sub_GAME_7F0B0E24(&pstan, point->f[0] + temp_f22, point->f[2] - temp_f20, dest->f[0] + temp_f22, dest->f[2] - temp_f20, arg5, sp64, sp60, 0.0f, 1.0f))
        {
            pstan = arg2;

            if (sub_GAME_7F0B0E24(&pstan, point->f[0], point->f[2], point->f[0] - temp_f22, point->f[2] + temp_f20, arg5, sp64, sp60, 0.0f, 1.0f)
                && sub_GAME_7F0B0E24(&pstan, point->f[0] - temp_f22, point->f[2] + temp_f20, dest->f[0] - temp_f22, dest->f[2] + temp_f20, arg5, sp64, sp60, 0.0f, 1.0f))
            {
                ret = 1;
            }
        }

        set_or_unset_GUARDdata_flag(self, 1);
    }

    return ret;
}



/**
 * Address 0x7F0304AC.
*/
s32 sub_GAME_7F0304AC(ChrRecord *self, coord3d *mypos, StandTile *mystan, coord3d *arg3, coord3d *bondpos, StandTile *bondstan, s32 arg6)
{
    StandTile *sp44;
    bool pass;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    StandTile *sp30;

    sp44 = mystan; // duplicate var? needed?
    pass = FALSE;

    chrGetChrWidthHeight(self->prop, &sp34, &sp3C, &sp38);
    set_or_unset_GUARDdata_flag(self, 0);

    if (sub_GAME_7F0B0E24(&sp44, mypos->x, mypos->z, arg3->x, arg3->z, arg6, sp3C, sp38, 0.0f, 1.0f))
    {
        sp30 = sp44; // duplicate var? needed?

        if (sub_GAME_7F0B0E24(&sp30, arg3->x, arg3->z, bondpos->x, bondpos->z, arg6, sp3C, sp38, 0.0f, 1.0f)
            && ((bondstan == NULL) || (sp30 == bondstan)))
        {
            pass = TRUE;
        }
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return pass;
}



/**
 * Unreferenced.
 * 
 * Address 0x7F0305E0.
*/
s32 sub_GAME_7F0305E0(ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, f32 arg5, s32 arg6)
{
    StandTile *sp4C;
    s32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    StandTile *sp38;

    sp4C = arg2;
    sp48 = 0;

    chrGetChrWidthHeight(self->prop, &sp3C, &sp44, &sp40);
    set_or_unset_GUARDdata_flag(self, 0);

    if (sub_GAME_7F0B0E24(&sp4C, arg1->x, arg1->f[2], arg3->x, arg3->f[2], arg6, sp44, sp40, 0.0f, 1.0f))
    {
        sp38 = sp4C;

        if (sub_GAME_7F0B0E24(&sp38, arg3->x, arg3->f[2], arg4->x, arg4->f[2], arg6, sp44, sp40, 0.0f, 1.0f)
            && sub_GAME_7F0301FC(self, arg1, arg2, arg3, arg5, arg6)
            && sub_GAME_7F0301FC(self, arg3, sp4C, arg4, arg5, arg6))
        {
            sp48 = 1;
        }
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return sp48;
}


/**
 * Subtract arg0 from arg1. Take the determinate of the result and arg2.
 * If determinate is not greater than zero, then swap arg0 and arg1.
 *
 * Address 0x7F03074C.
*/
void chrlvSwapIfDiffArg2Determinate(coord3d *arg0, coord3d *arg1, coord3d *arg2)
{
    coord3d spock;
    coord3d kirk;

    spock.f[0] = arg1->f[0] - arg0->f[0];
    spock.f[1] = arg1->f[1] - arg0->f[1];
    spock.f[2] = arg1->f[2] - arg0->f[2];

    kirk.f[0] = -arg2->f[2];
    kirk.f[1] = 0.0f;
    kirk.f[2] = arg2->f[0];

    if (!(((kirk.f[0] * spock.f[0]) + (kirk.f[2] * spock.f[2])) > 0.0f))
    {
        spock.f[0] = arg0->f[0];
        spock.f[1] = arg0->f[1];
        spock.f[2] = arg0->f[2];

        arg0->f[0] = arg1->f[0];
        arg0->f[1] = arg1->f[1];
        arg0->f[2] = arg1->f[2];

        arg1->f[0] = spock.f[0];
        arg1->f[1] = spock.f[1];
        arg1->f[2] = spock.f[2];
    }
}



/**
 * Very similar to @see sub_GAME_7F030D70 .
 * Address 0x7F03081C.
*/
s32 sub_GAME_7F03081C(ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, coord3d *arg5, f32 arg6, f32 arg7, s32 arg8)
{
    StandTile *spAC;
    coord3d spA0;
    f32 sp9C; // 156
    f32 sp98; // 152
    f32 sp94; // 148
    f32 sp90; // 144
    f32 norm;
    s32 sp88; // 136
    s32 sp84; // 132
    coord3d sp78;
    coord3d sp6C;
    coord3d sp60;
    coord3d sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    sp88 = 0;
    sp84 = 0;
    sp50 = 0;

    chrGetChrWidthHeight(self->prop, &sp44, &sp4C, &sp48);

    spA0.f[0] = arg3->f[0] - arg1->f[0];
    spA0.f[1] = 0.0f;
    spA0.f[2] = arg3->f[2] - arg1->f[2];
    
    if ((spA0.f[0] == 0.0f) && (spA0.f[2] == 0.0f))
    {
        return 1;
    }

    norm = (spA0.f[0] * spA0.f[0]) + (spA0.f[2] * spA0.f[2]);
    norm = 1.0f / sqrtf(norm);

    spA0.f[0] *= norm;
    spA0.f[2] *= norm;
    
    sp9C = 0.95f * (arg7 * spA0.f[0]);
    sp98 = 0.95f * (arg7 * spA0.f[2]);

    sp94 = 1.2f * (arg7 * spA0.f[0]);
    sp90 = 1.2f * (arg7 * spA0.f[2]);

    set_or_unset_GUARDdata_flag(self, 0);
    sub_GAME_7F0B1CC4();

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] + sp98,
        arg1->f[2] - sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] + sp98,
            arg1->f[2] - sp9C,
            (arg3->f[0] + sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] - sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp88 = 1;

        getCollisionEdge_maybe(&sp78, &sp6C);
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp6C, &spA0);
    }

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] - sp98,
        arg1->f[2] + sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] - sp98,
            arg1->f[2] + sp9C,
            (arg3->f[0] - sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] + sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp84 = 1;

        getCollisionEdge_maybe(&sp60, &sp54);
        chrlvSwapIfDiffArg2Determinate(&sp60, &sp54, &spA0);
    }

    if ((sp88 != 0) && (sp84 != 0))
    {
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp60, &spA0);
        chrlvSwapIfDiffArg2Determinate(&sp6C, &sp54, &spA0);

        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else if (sp88 != 0)
    {
        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp6C.f[0];
        arg5->f[1] = sp6C.f[1];
        arg5->f[2] = sp6C.f[2];
    }
    else if (sp84 != 0)
    {
        arg4->f[0] = sp60.f[0];
        arg4->f[1] = sp60.f[1];
        arg4->f[2] = sp60.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else
    {
        spAC = arg2;

        if (sub_GAME_7F0B0E24(&spAC, arg1->f[0], arg1->f[2], arg3->f[0], arg3->f[2], arg8, sp4C, sp48, 0.0f, 1.0f)
            && sub_GAME_7F0B18B8(&spAC, arg3->f[0], arg3->f[2], arg7, arg8, sp4C, sp48) < 0)
        {
            sp50 = 1;
        }
        else
        {
            getCollisionEdge_maybe(arg4, arg5);
            chrlvSwapIfDiffArg2Determinate(arg4, arg5, &spA0);
        }
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return sp50;
}


/**
 * Very similar to @see sub_GAME_7F03081C .
 * 
 * Address 0x7F030D70.
*/
s32 sub_GAME_7F030D70(ChrRecord *self, coord3d *arg1, StandTile *arg2, coord3d *arg3, coord3d *arg4, coord3d *arg5, f32 arg6, f32 arg7, s32 arg8)
{
    StandTile *spAC;
    coord3d spA0;
    f32 sp9C; // 164
    f32 sp98; // 160
    f32 sp94; // 156
    f32 sp90; // 152
    f32 norm;
    s32 sp88; // 144
    s32 sp84; // 140
    coord3d sp78; // x
    coord3d sp6C;
    coord3d sp60;
    coord3d sp54;
    s32 sp50;
    f32 stanval1;
    f32 stanval2;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    sp88 = 0;
    sp84 = 0;
    sp50 = 0;

    chrGetChrWidthHeight(self->prop, &sp44, &sp4C, &sp48);

    spA0.f[0] = arg3->f[0] - arg1->f[0];
    spA0.f[1] = 0.0f;
    spA0.f[2] = arg3->f[2] - arg1->f[2];
    
    if ((spA0.f[0] == 0.0f) && (spA0.f[2] == 0.0f))
    {
        return 1;
    }

    norm = (spA0.f[0] * spA0.f[0]) + (spA0.f[2] * spA0.f[2]);
    norm = 1.0f / sqrtf(norm);

    spA0.f[0] *= norm;
    spA0.f[2] *= norm;
    
    sp9C = 0.95f * (arg7 * spA0.f[0]);
    sp98 = 0.95f * (arg7 * spA0.f[2]);

    sp94 = 1.2f * (arg7 * spA0.f[0]);
    sp90 = 1.2f * (arg7 * spA0.f[2]);

    set_or_unset_GUARDdata_flag(self, 0);
    sub_GAME_7F0B1CC4();

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] + sp98,
        arg1->f[2] - sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] + sp98,
            arg1->f[2] - sp9C,
            (arg3->f[0] + sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] - sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp88 = 1;

        getCollisionEdge_maybe(&sp78, &sp6C);
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp6C, &spA0);

        stanval1 = stanSavedColl_someMin;
    }

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] - sp98,
        arg1->f[2] + sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] - sp98,
            arg1->f[2] + sp9C,
            (arg3->f[0] - sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] + sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp84 = 1;

        getCollisionEdge_maybe(&sp60, &sp54);
        chrlvSwapIfDiffArg2Determinate(&sp60, &sp54, &spA0);

        stanval2 = stanSavedColl_someMin;
    }

    if ((sp88 != 0) && (sp84 != 0))
    {
        if (stanval1 < stanval2)
        {
            arg4->f[0] = sp78.f[0];
            arg4->f[1] = sp78.f[1];
            arg4->f[2] = sp78.f[2];

            arg5->f[0] = sp6C.f[0];
            arg5->f[1] = sp6C.f[1];
            arg5->f[2] = sp6C.f[2];
        }
        else
        {
            arg4->f[0] = sp60.f[0];
            arg4->f[1] = sp60.f[1];
            arg4->f[2] = sp60.f[2];

            arg5->f[0] = sp54.f[0];
            arg5->f[1] = sp54.f[1];
            arg5->f[2] = sp54.f[2];
        }
    }
    else if (sp88 != 0)
    {
        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp6C.f[0];
        arg5->f[1] = sp6C.f[1];
        arg5->f[2] = sp6C.f[2];
    }
    else if (sp84 != 0)
    {
        arg4->f[0] = sp60.f[0];
        arg4->f[1] = sp60.f[1];
        arg4->f[2] = sp60.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else
    {
        spAC = arg2;

        if (sub_GAME_7F0B0E24(&spAC, arg1->f[0], arg1->f[2], arg3->f[0], arg3->f[2], arg8, sp4C, sp48, 0.0f, 1.0f)
            && sub_GAME_7F0B18B8(&spAC, arg3->f[0], arg3->f[2], arg7, arg8, sp4C, sp48) < 0)
        {
            sp50 = 1;
        }
        else
        {
            getCollisionEdge_maybe(arg4, arg5);
            chrlvSwapIfDiffArg2Determinate(arg4, arg5, &spA0);
        }
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return sp50;
}



/**
 * Address 0x7F03130C.
*/
s32 sub_GAME_7F03130C(
    ChrRecord *self,
    coord3d *arg1,
    s32 arg2,
    coord3d *arg3,
    f32 arg4,
    s32 arg5,
    coord3d *arg6,
    struct waydata *arg7,
    f32 arg8,
    s32 arg9,
    s32 set_copy)
{
    PropRecord *self_prop; // -- 124
    coord3d dd; // -- 112
    coord3d sp64; // -- 100
    f32 norm; // -- 96
    f32 phi_f12; // 92
    coord3d sp50; // 80
    coord3d *sp4C; // 76
    coord3d *sp48; // 72

    self_prop = self->prop;

    if (arg2 != 0)
    {
        sp4C = arg1;
        sp48 = arg3;
    }
    else
    {
        sp4C = arg3;
        sp48 = arg1;
    }

    dd.f[0] = arg1->f[0] - self_prop->pos.f[0];
    dd.f[1] = 0.0f;
    dd.f[2] = arg1->f[2] - self_prop->pos.f[2];

    norm = 1.0f / sqrtf((dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]));

    dd.f[0] *= arg4 * norm;
    dd.f[2] *= arg4 * norm;

    if (arg4 * norm > 1.0f)
    {
        phi_f12 = DegToRad(45);
    }
    else
    {
        phi_f12 = acosf(arg4 * norm);
    }

    if ((arg2 == 0) && (phi_f12 != 0.0f))
    {
        phi_f12 = M_TAU_F - phi_f12;
    }

    sp50.f[0] = (-cosf(phi_f12) * dd.f[0]) + (sinf(phi_f12) * dd.f[2]);
    sp50.f[1] = 0.0f;
    sp50.f[2] = (-sinf(phi_f12) * dd.f[0]) - (cosf(phi_f12) * dd.f[2]);

    sp64.f[0] = arg1->f[0] + sp50.f[0];
    sp64.f[1] = arg1->f[1];
    sp64.f[2] = arg1->f[2] + sp50.f[2];

    if (sub_GAME_7F03081C(self, &self_prop->pos, self_prop->stan, &sp64, sp4C, sp48, arg8, self->chrwidth, arg9)
        && ((arg5 == 0) || sub_GAME_7F0304AC(self, &self_prop->pos, self_prop->stan, &sp64, arg6, NULL, arg9)))
    {
        if (set_copy != 0)
        {
            arg7->unk03 = 1;

            arg7->pos_copy.f[0] = sp64.f[0];
            arg7->pos_copy.f[1] = sp64.f[1];
            arg7->pos_copy.f[2] = sp64.f[2];
        }
        else
        {
            arg7->unk02 = 1;

            arg7->pos.f[0] = sp64.f[0];
            arg7->pos.f[1] = sp64.f[1];
            arg7->pos.f[2] = sp64.f[2];
        }

        return 1;
    }

    return 0;
}



/**
 * Iterates travel mode. Used by both ACT_GOPOS and ACT_PATROL.
 * 10% chance to open door.
 * Calls apply speed.
 * 
 * @see chrlvTickPatrol
 * @see chrlvTickGoPos
 * contrast with @see chrlvTravelTickMagic
 * 
 * Address 0x7F0315A4.
*/
void chrlvTravelTick(ChrRecord *self, coord3d *arg1, StandTile *arg2, struct waydata *arg3)
{
    s32 spF0;
    coord3d sp100; // 260
    coord3d spF4; // 244
    s32 i; // 240
    f32 spe0;
    f32 spE8; // 232
    f32 spE4; // 228
    struct ObjectRecord *obj;
    f32 spC4;
    f32 spB4;
    f32 atan_pos2_a; // 212
    f32 atan_pos3_a;
    PropRecord *self_prop;
    f32 dx;
    f32 atan_pos2_b; // 196
    f32 atan_pos3_b;
    f32 dy;
    f32 dz;
    f32 atan_pos2_c; // 180
    f32 atan_pos3_c;
    s32 max;
    f32 atan_pos;
    s32 temp_t1;
    s32 phi_s6;
    PropRecord *phi_s3;
    s32 stack_01;
    s32 stack_02;

    self_prop = self->prop;
    phi_s6 = 0x801D;
    if ((self->hidden & CHRHIDDEN_OFFSCREEN_PATROL) != 0)
    {
        phi_s6 = 0x1F;
    }

    max=1;
    for (i=0; i<1; i++)
    {
        if ((arg3->mode == WAYMODE_0) || (arg3->mode == WAYMODE_2))
        {
            sp100.f[0] = arg1->f[0];
            sp100.f[1] = arg1->f[1];
            sp100.f[2] = arg1->f[2];

            if (sub_GAME_7F03081C(self, &self_prop->pos, self_prop->stan, &sp100, &arg3->pos2, &arg3->pos3, -(self->chrwidth), self->chrwidth, 0x10) != 0)
            {
                arg3->unk02 = (u8) 1;
                arg3->pos.f[0] = sp100.f[0];
                arg3->pos.f[1] = sp100.f[1];
                arg3->pos.f[2] = sp100.f[2];
                arg3->mode = WAYMODE_4;
            }
            else
            {
                if (arg3->mode == WAYMODE_0)
                {
                    arg3->mode = (s8) WAYMODE_1;
                    arg3->unk01 = 0;
                }
                else if (arg3->mode == WAYMODE_2)
                {
                    arg3->mode = WAYMODE_3;
                    arg3->unk01 = 0;
                }
            }
        }
        else if (arg3->mode == WAYMODE_1)
        {
            spE8 = self->chrwidth * 1.2f * 1.05f;

            if (sub_GAME_7F03130C(self, &arg3->pos2, 1, &spF4, spE8, 1, arg1, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else if (sub_GAME_7F03130C(self, &arg3->pos3, 0, &spF4, spE8, 1, arg1, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else
            {
                arg3->unk01 = arg3->unk01 + 1;
                if (arg3->unk01 >= MAX_WAYMODE)
                {
                    arg3->mode = WAYMODE_2;
                }
            }
        }
        else if (arg3->mode == WAYMODE_3)
        {
            spE4 = self->chrwidth * 1.2f * 1.05f;

            if (sub_GAME_7F03130C(self, &arg3->pos2, 1, &spF4, spE4, 0, NULL, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else if (sub_GAME_7F03130C(self, &arg3->pos3, 0, &spF4, spE4, 0, NULL, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else
            {
                arg3->unk01 = arg3->unk01 + 1;
                if (arg3->unk01 >= MAX_WAYMODE)
                {
                    arg3->unk02 = 0;
                    arg3->unk03 = (u8) (s8) arg3->unk02;
                    arg3->pos_copy.f[0] = 
                        arg3->pos.f[0] = arg1->f[0];
                    arg3->pos_copy.f[1] =
                        arg3->pos.f[1] = arg1->f[1];
                    arg3->pos_copy.f[2] =
                        arg3->pos.f[2] = arg1->f[2];
                    arg3->mode = WAYMODE_0;
                }
            }
        }
        else if (arg3->mode == WAYMODE_4)
        {
            if (sub_GAME_7F030D70(self, &self_prop->pos, self_prop->stan, &arg3->pos, &arg3->pos2, &arg3->pos3, -(self->chrwidth), self->chrwidth, phi_s6) != 0)
            {
                arg3->unk03 = max;
                arg3->mode = WAYMODE_0;
                arg3->pos_copy.f[0] = arg3->pos.f[0];
                arg3->pos_copy.f[1] = arg3->pos.f[1];
                arg3->pos_copy.f[2] = arg3->pos.f[2];
            }
            else
            {
                arg3->mode = WAYMODE_5;
                arg3->unk01 = 0;
            }
        }
        else if (arg3->mode == WAYMODE_5)
        {
            spe0 = self->chrwidth * 1.2f * 1.05f;

            atan_pos =       atan2f( arg3->pos.f[0] - self_prop->pos.f[0],  arg3->pos.f[2] - self_prop->pos.f[2]);
            atan_pos2_a = atan_pos - atan2f(arg3->pos2.f[0] - self_prop->pos.f[0], arg3->pos2.f[2] - self_prop->pos.f[2]);
            atan_pos3_a = atan_pos - atan2f(arg3->pos3.f[0] - self_prop->pos.f[0], arg3->pos3.f[2] - self_prop->pos.f[2]);

            if (atan_pos2_a < 0.0f)
            {
                atan_pos2_a = atan_pos2_a + M_TAU_F;
            }

            if (atan_pos2_a >= M_PI_F)
            {
                atan_pos2_a = atan_pos2_a - M_TAU_F;
            }

            if (atan_pos2_a < 0.0f)
            {
                atan_pos2_a = -atan_pos2_a;
            }

            if (atan_pos3_a < 0.0f)
            {
                atan_pos3_a = atan_pos3_a + M_TAU_F;
            }

            if (atan_pos3_a >= M_PI_F)
            {
                atan_pos3_a = atan_pos3_a - M_TAU_F;
            }

            if (atan_pos3_a < 0.0f)
            {
                atan_pos3_a = -atan_pos3_a;
            }

            if (atan_pos2_a < atan_pos3_a)
            {
                if (sub_GAME_7F03130C(self, &arg3->pos2, 1, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0)
                {
                    arg3->mode = WAYMODE_0;
                    break;
                }
                else
                {
                    atan_pos2_b = atan_pos - atan2f(arg3->pos2.f[0] - self_prop->pos.f[0], arg3->pos2.f[2] - self_prop->pos.f[2]);
                    atan_pos3_b = atan_pos - atan2f(spF4.f[0] - self_prop->pos.f[0], spF4.f[2] - self_prop->pos.f[2]);

                    if (atan_pos2_b < 0.0f)
                    {
                        atan_pos2_b = atan_pos2_b + M_TAU_F;
                    }
                    if (atan_pos2_b >= M_PI_F)
                    {
                        atan_pos2_b = atan_pos2_b - M_TAU_F;
                    }
                    if (atan_pos2_b < 0.0f)
                    {
                        atan_pos2_b = -atan_pos2_b;
                    }

                    if (atan_pos3_b < 0.0f)
                    {
                        atan_pos3_b = atan_pos3_b + M_TAU_F;
                    }
                    if (atan_pos3_b >= M_PI_F)
                    {
                        atan_pos3_b = atan_pos3_b - M_TAU_F;
                    }
                    if (atan_pos3_b < 0.0f)
                    {
                        atan_pos3_b = -atan_pos3_b;
                    }

                    if ((atan_pos3_b < atan_pos2_b) && (sub_GAME_7F03130C(self, &spF4, 0, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0))
                    {
                        arg3->mode = WAYMODE_0;
                        break;
                    }
                }
            }
            else
            {
                if (sub_GAME_7F03130C(self,  &arg3->pos3, 0, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0)
                {
                    arg3->mode = WAYMODE_0;
                    break;
                }
                else
                {
                    atan_pos2_c = atan_pos - atan2f(arg3->pos3.f[0] - self_prop->pos.f[0], arg3->pos3.f[2] - self_prop->pos.f[2]);
                    atan_pos3_c = atan_pos - atan2f(spF4.f[0] - self_prop->pos.f[0], spF4.f[2] - self_prop->pos.f[2]);
                    
                    if (atan_pos2_c < 0.0f)
                    {
                        atan_pos2_c = atan_pos2_c + M_TAU_F;
                    }
                    if (atan_pos2_c >= M_PI_F)
                    {
                        atan_pos2_c = atan_pos2_c - M_TAU_F;
                    }
                    if (atan_pos2_c < 0.0f)
                    {
                        atan_pos2_c = -atan_pos2_c;
                    }

                    if (atan_pos3_c < 0.0f)
                    {
                        atan_pos3_c = atan_pos3_c + M_TAU_F;
                    }
                    if (atan_pos3_c >= M_PI_F)
                    {
                        atan_pos3_c = atan_pos3_c - M_TAU_F;
                    }
                    if (atan_pos3_c < 0.0f)
                    {
                        atan_pos3_c = -atan_pos3_c;
                    }

                    if ((atan_pos3_c < atan_pos2_c) && (sub_GAME_7F03130C(self, &spF4, 1, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0))
                    {
                        arg3->mode = WAYMODE_0;
                        break;
                    }
                }
            }

            arg3->unk01 = arg3->unk01 + 1;
            if (arg3->unk01 >= MAX_WAYMODE)
            {
                arg3->unk03 = 0;
                arg3->mode = WAYMODE_0;
            }
        }
    }

    if (arg3->unk03 == 0)
    {
        arg3->pos_copy.f[0] = arg3->pos.f[0];
        arg3->pos_copy.f[1] = arg3->pos.f[1];
        arg3->pos_copy.f[2] = arg3->pos.f[2];
    }

    if (((s32) arg3->age % 10) == 0)
    {
        phi_s3 = sub_GAME_7F0B1410(self_prop->stan, self_prop->pos.f[0], self_prop->pos.f[2], arg3->pos_copy.f[0], arg3->pos_copy.f[2], 0x5000);

        if (phi_s3 != NULL)
        {
            obj = phi_s3->obj;
            if (!(obj->flags2 & PROPFLAG_NO_AI_INTERACTION))
            {
                dx = phi_s3->pos.f[0] - self_prop->pos.f[0];
                dy = phi_s3->pos.f[1] - self_prop->pos.f[1];
                dz = phi_s3->pos.f[2] - self_prop->pos.f[2];

                if (((dx * dx) + (dy * dy) + (dz  * dz )) < 40000.0f)
                {
                    sub_GAME_7F0281F4(self);
                    sub_GAME_7F055B78(self_prop, phi_s3->door);
                    doorActivate(phi_s3->door, 1);

                    if (((self->hidden & CHRHIDDEN_OFFSCREEN_PATROL) == 0)
                        && (objecthandlerGetModelAnim(self->model) != (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle_unarmed])
                        && (objecthandlerGetModelAnim(self->model) != (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle]))
                    {
                        chrlvIdleAnimationRelated(self, 16.0f);
                        self->lastmoveok60 = g_GlobalTimer;
                    }
                }
                else
                {
                    phi_s3 = NULL;
                }
            }
            else
            {
                phi_s3 = NULL;
            }
        }

        if ((phi_s3 == NULL) || ((self->hidden & CHRHIDDEN_OFFSCREEN_PATROL) != 0))
        {
            if ((objecthandlerGetModelAnim(self->model) == (struct ModelAnimation *)((s32)&ANIM_DATA_idle_unarmed + (s32)&ptr_animation_table->data))
                || (objecthandlerGetModelAnim(self->model) == (struct ModelAnimation *)((s32)&ANIM_DATA_idle + (s32)&ptr_animation_table->data)))
            {
                if (self->actiontype == ACT_PATROL)
                {
                    chrlvWalkingAnimationRelated(self);
                }
                else
                {
                    play_hit_soundeffect_and_proper_volume(self);
                }
            }

            if (phi_s3 == NULL)
            {
                self->hidden &= ~(CHRHIDDEN_OFFSCREEN_PATROL);
            }
        }
    }
    
    if (self->actiontype == ACT_PATROL)
    {
        chrlvApplySpeed(self, &arg3->pos_copy, 0, &self->act_patrol.speed);
    }
    else
    {
        chrlvApplySpeed(self, &arg3->pos_copy, (s32) self->act_gopos.unk59, &self->act_gopos.speed);
    
        if (self->act_gopos.unk59 == 2)
        {
            if (self->act_gopos.speed != 0.0f)
            {
                modelSetAnimSpeed(self->model, 0.25f, 0.0f);
            }
            else if (self->chrflags & CHRFLAG_INCREASE_RUNNING_SPEED)
            {
                modelSetAnimSpeed(self->model, 0.65f, 0.0f);
            }
            else
            {
                modelSetAnimSpeed(self->model, 0.5f, 0.0f);
            }
        }
        else if (self->act_gopos.unk59 == 1)
        {
            if (self->act_gopos.speed != 0.0f)
            {
                modelSetAnimSpeed(self->model, 0.4f, 0.0f);
            }
            else
            {
                modelSetAnimSpeed(self->model, 0.5f, 0.0f);
            }
        }
    }
}






/**
 * Address 0x7F032088.
*/
void chrlvTickGoPos(ChrRecord *self)
{
    waypoint *wp;
    coord3d *wp_pos;
    StandTile *wp_stan;
    PropRecord *self_prop;
    s32 sp74;
    coord3d sp68;
    StandTile *sp64;
    coord3d sp58;
    StandTile *sp54;
    PadRecord *pad; // 80
    s32 phi_v1; // 76
    s32 unused[4]; // maybe used by the nested if statements ?

    self_prop = self->prop;
    sp74 = 0;
    self->act_gopos.waydata.age += 1;
    self->lastwalk60 = g_GlobalTimer;

    if (self->lastmoveok60 < (g_GlobalTimer - CHRLV_LASTMOVEOK60_CHECK))
    {
        plot_course_for_actor(self, &self->act_gopos.targetpos, self->act_gopos.target, (s32) self->act_gopos.unk59);
    }

    chrlvPlotCourseRelated(self);

    if ((self->act_gopos.waydata.mode != WAYMODE_MAGIC) && ((self->act_gopos.unk9c + CHRLV_DEFAULT_TIMER) < g_GlobalTimer))
    {
        chrlvActGoposRelated(self, &sp68, &sp64);

        if (chrlvStanRoomRelated(self, &sp68, sp64))
        {
            sp74 = 1;
            chrlvSetGoposSegDistTotal(self, &self->act_gopos.waydata, &sp68);
        }
    }

    if (g_SeenBondRecentlyGuardCount >= 0xA)
    {
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }
    
    if (self->act_gopos.waydata.mode == WAYMODE_MAGIC)
    {
        chrlvActGoposRelated(self, &sp58, &sp54);

        if ((sp74 == 0)
            && ((self_prop->flags & PROPFLAG_ONSCREEN) || (chrlvStanRoomRelated(self, &sp58, sp54) == 0)))
        {
            chrlvActGoposSetTargetPosRelated(self);
            self->act_gopos.unk9c = g_GlobalTimer;
            
            return;
        }

        chrlvTravelTickMagic(self, &self->act_gopos.waydata, chrlvModelScaleAnimationRelated(self), &sp58, sp54);

        return;
    }


    phi_v1 = 0;

    wp = self->act_gopos.waypoints[self->act_gopos.curindex];

    if (wp != NULL)
    {
        if (chrlvIsArrivingLaterallyAtPos(&self->prevpos, &self_prop->pos, &g_chraiCurrentSetup.pads[wp->padID].pos, 30.0f) != 0)
        {
            phi_v1 = 1;
        }
    }
    else
    {
        if (chrlvIsArrivingLaterallyAtPos(&self->prevpos, &self_prop->pos, &self->act_gopos.targetpos, 30.0f) != 0)
        {
            chrlvKneelingAnimationRelated7F023E48(self);

            return;
        }
    }

    if (phi_v1 != 0)
    {
        chrlvActGoposIncCurIndex(self);
    }

    if (((s32) self->act_gopos.waydata.age % 10) == 5)
    {
        wp = self->act_gopos.waypoints[self->act_gopos.curindex];

        if (wp != NULL)
        {
            wp = self->act_gopos.waypoints[self->act_gopos.curindex + 1];

            if (wp != NULL)
            {
                wp = self->act_gopos.waypoints[self->act_gopos.curindex + 2];

                if (wp != NULL)
                {
                    pad = &g_chraiCurrentSetup.pads[wp->padID];
                    wp_pos = &pad->pos;
                    wp_stan = pad->stan;
                }
                else
                {
                    wp_pos = &self->act_gopos.targetpos;
                    wp_stan = self->act_gopos.target;
                }

                if (sub_GAME_7F030128(self, &self_prop->pos, self_prop->stan, wp_pos, wp_stan, 0x10) 
                    && sub_GAME_7F0301FC(self, &self_prop->pos, self_prop->stan, wp_pos, self->chrwidth * 1.2f, 0x10))
                {
                    chrlvActGoposIncCurIndex(self);
                    chrlvActGoposIncCurIndex(self);
                }
            }
        }
    }

    if (((s32) self->act_gopos.waydata.age % 10) == 0)
    {
        wp = self->act_gopos.waypoints[self->act_gopos.curindex];

        if (wp != NULL)
        {
            wp = self->act_gopos.waypoints[self->act_gopos.curindex + 1];

            if (wp != NULL)
            {
                pad = &g_chraiCurrentSetup.pads[wp->padID];
                wp_pos = &pad->pos;
                wp_stan = pad->stan;
            }
            else
            {
                wp_pos = &self->act_gopos.targetpos;
                wp_stan = self->act_gopos.target;
            }

            if (sub_GAME_7F030128(self, &self_prop->pos, self_prop->stan, wp_pos, wp_stan, 0x10)
                && sub_GAME_7F0301FC(self, &self_prop->pos, self_prop->stan, wp_pos, self->chrwidth * 1.2f, 0x10))
            {
                chrlvActGoposIncCurIndex(self);
            }
        }
    }

    wp = self->act_gopos.waypoints[self->act_gopos.curindex];

    if (wp != NULL)
    {
        pad = &g_chraiCurrentSetup.pads[wp->padID];
        wp_pos = &pad->pos;
        wp_stan = pad->stan;
    }
    else
    {
        wp_pos = &self->act_gopos.targetpos;
        wp_stan = self->act_gopos.target;
    }

    chrlvTravelTick(self, wp_pos, wp_stan, &self->act_gopos.waydata);
}



/**
 * Address 0x7F032548.
*/
void chrlvTickPatrol(ChrRecord *self)
{
    PropRecord *self_prop;
    s32 unused_1;
    s32 sp34;
    PadRecord *temp_v0;

    self_prop = self->prop;
    temp_v0 = (PadRecord *) chrlvGetNextPatrolStepPad(self);
    sp34 = 0;
    self->act_patrol.waydata.age += 1;
    self->lastwalk60 = g_GlobalTimer;

    if ((self->act_patrol.waydata.mode != WAYMODE_MAGIC)
        && ((self->act_patrol.lastvisible60 + CHRLV_DEFAULT_TIMER) < g_GlobalTimer)
        && chrlvStanRoomRelatedPad(self, temp_v0))
    {
        sp34 = 1;
        chrlvSetGoposSegDistTotal(self, &self->act_patrol.waydata, &temp_v0->pos);
    }

    if (self->act_patrol.waydata.mode == WAYMODE_MAGIC)
    {
        if ((sp34 == 0)
            && ((self_prop->flags & PROPFLAG_ONSCREEN) || (chrlvStanRoomRelatedPad(self, temp_v0) == 0)))
        {
            self->act_patrol.lastvisible60 = g_GlobalTimer;
            chrlvSetNextActPatrolStepPadPos(self);
        }
        else
        {
            chrlvTravelTickMagic(self, &self->act_patrol.waydata, D_80030984, &temp_v0->pos, temp_v0->stan);
        }
    }
    else
    {
        if(1)
        {
            // removed
        }

        if (chrlvIsArrivingLaterallyAtPos(&self->prevpos, &self_prop->pos, &temp_v0->pos, 30.0f))
        {
            sub_GAME_7F0284DC(self);
            temp_v0 = (PadRecord *)chrlvGetNextPatrolStepPad(self);
        }

        chrlvTravelTick(self, &temp_v0->pos, temp_v0->stan, &self->act_patrol.waydata);
    }
}



/**
 * Address 0x7F0326BC.
*/
void chrlvActionTick(ChrRecord *self)
{
    if (g_ClockTimer > 0)
    {
        if (self->actiontype == ACT_INIT)
        {
            self->chrflags |= 1;
            chrlvIdleAnimationRelated7F023A94(self, 0.0f);
            self->sleep = 0;
        }

        if ((self->hidden & 0x40) != 0)
        {
            self->timer60 += g_ClockTimer;
        }

        self->sleep -= g_ClockTimer;

        if (((s32) self->sleep < 0) || (self->chrflags & 0x40000))
        {
            self->sleep = 0;
            ai(self, PROP_TYPE_CHR);
            
            switch (self->actiontype)
            {
                case ACT_STAND:
                    chrlvTickStand(self);
                    break;
                case ACT_KNEEL:
                    chrlvTickKneel(self);
                    break;
                case ACT_ANIM:
                    chrlvTickAnim(self);
                    break;
                case ACT_DIE:
                    chrlvTickDie(self);
                    break;
                case ACT_ARGH:
                    chrlvTickArgh(self);
                    break;
                case ACT_PREARGH:
                    chrlvTickPreArgh(self);
                    break;
                case ACT_SIDESTEP:
                    chrlvTickSidestep(self);
                    break;
                case ACT_JUMPOUT:
                    chrlvTickJumpout(self);
                    break;
                case ACT_DEAD:
                    chrlvTickDead(self);
                    break;
                case ACT_ATTACK:
                    chrlvTickAttack(self);
                    break;
                case ACT_ATTACKWALK:
                    chrlvTickAttackWalk(self);
                    break;
                case ACT_ATTACKROLL:
                    chrlvTickAttackRoll(self);
                    break;
                case ACT_RUNPOS:
                    chrlvTickRunPos(self);
                    break;
                case ACT_PATROL:
                    chrlvTickPatrol(self);
                    break;
                case ACT_GOPOS:
                    chrlvTickGoPos(self);
                    break;
                case ACT_SURRENDER:
                    chrlvTickSurrender(self);
                    break;
                case ACT_TEST:
                    chrlvTickTest(self);
                    break;
                case ACT_SURPRISED:
                    chrlvTickSurprised(self);
                    break;
                case ACT_STARTALARM:
                    chrlvTickStartAlarm(self);
                    break;
                case ACT_THROWGRENADE:
                    chrlvTickThrowGrenade(self);
                    break;
                case ACT_BONDINTRO:
                    chrlvTickBondIntro(self);
                    break;
                case ACT_BONDDIE:
                    chrlvTickBondDieRemoved(self);
                    break;
            }
            
            self->chrflags &= -5;
            self->hidden &= 0xFDFD;
            self->chrseeshot = -1;
            self->chrseedie = -1;
        }
    }
}


/**
 * Calls chrlvActionTick on all characters, and updates count of guards that have recently seen bond.
 * 
 * Address 0x7F03291C.
*/
void chrlvAllChrTick(void)
{
    s32 i;
    s32 max;
    ChrRecord *guard;

    max = get_numguards();

    for (i=0; i<g_ActiveChrsCount; i++)
    {
        chrlvActionTick(&g_ActiveChrs[i]);
    }

    g_SeenBondRecentlyGuardCount = 0;

    for (i=0; i<max; i++)
    {
        guard = &ptr_guard_data[i];

        if (guard->model != NULL)
        {
            if ((guard->lastseetarget60 > 0) && (g_GlobalTimer - guard->lastseetarget60 < CHRLV_SEEN_RECENT_CHECK))
            {
                g_SeenBondRecentlyGuardCount++;
            }
        }
    }
}


/**
 * Address 0x7F032B68.
*/
s32 chrSawTargetRecently(ChrRecord *self)
{
    if ((self->lastseetarget60 > 0) && ((g_GlobalTimer - self->lastseetarget60) < CHRLV_10_SEC_TIMER))
    {
        return TRUE;
    }
    return FALSE;
}




/**
 * Address 0x7F032BA0.
*/
s32 chrHeardTargetRecently(ChrRecord *self)
{
    if ((self->lastheartarget60 > 0) && ((g_GlobalTimer - self->lastheartarget60) < CHRLV_10_SEC_TIMER))
    {
        return TRUE;
    }
    return FALSE;
}



/**
 * Address 0x7F032BD8.
 * get angle to pos in Radians
*/
f32 get_distance_actor_to_position(ChrRecord *self, coord3d *pos)
{
    f32         radToPos;
    f32         radMyHeading;
    PropRecord *myprop;
    f32         anglebetween;

    radMyHeading = getsubroty(self->model);
    myprop       = self->prop;
    anglebetween = atan2f(pos->x - myprop->pos.x, pos->z - myprop->pos.z);
    radToPos     = anglebetween - radMyHeading;

    if (anglebetween < radMyHeading)
    {
        radToPos = radToPos + M_TAU_F;
    }

    return radToPos;
}


/**
 * Address 0x7F032C4C.
*/
f32 chrGetAngleToBond(ChrRecord *self)
{
    return get_distance_actor_to_position(self, &get_curplayer_positiondata()->pos);
}



/**
 * @param self:
 * @param flags: Lookup mode. 4 == lookup guard. 8 == lookup pad preset. Else, use current player.
 * @param lookup_id: Lookup id for guard or preset.
 * @param stan: Out parameter. Will contain found stan.
 * @returns: Position of found item (depends on lookup mode).
 * 
 * Address 0x7F032C78.
*/
coord3d *chrlvGetChrOrPresetLocation(ChrRecord *self, s32 flags, s32 lookup_id, StandTile **stan)
{
    ChrRecord *guard;
    PropRecord *player_prop;
    s32 padid;
    PadRecord *preset_pad;

    if ((flags & 4) != 0)
    {
        guard = chrFindById(self, lookup_id);

        if ((guard == 0) || (guard->prop == 0))
        {
            guard = self;
        }

        *stan = (StandTile *) self->prop->stan;

        return &guard->prop->pos;
    }

    if ((flags & 8) != 0)
    {
        padid = chrResolvePadId(self, lookup_id);

        if (isNotBoundPad(padid))
        {
            preset_pad = &g_chraiCurrentSetup.pads[padid];
        }
        else
        {
            preset_pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padid)];
        }

        *stan = (StandTile *) preset_pad->stan;

        return &preset_pad->pos;
    }

    player_prop = get_curplayer_positiondata();
    *stan = (StandTile *) player_prop->stan;
    
    return &player_prop->pos;
}


/**
 * Address 0x7F032D70.
*/
f32 chrGetAngleFromBond(ChrRecord *self)
{
    f32 radBondHeading   = get_curplay_horizontal_rotation_in_degrees();
    PropRecord *myprop   = self->prop;
    PropRecord *bondprop = get_curplayer_positiondata();
    f32 anglebetween     = atan2f(myprop->pos.x - bondprop->pos.x, myprop->pos.z - bondprop->pos.z);
    f32 radFromBond      = anglebetween - radBondHeading;

    if (anglebetween < radBondHeading)
    {
        radFromBond = radFromBond + M_TAU_F;
    }

    return radFromBond;
}


/**
 * Address 0x7F032DE4.
*/
f32 chrGetDistanceToBond(ChrRecord *guardData)
{
    PropRecord *guardPosData;
    PropRecord *playerPosData;
    float xDiff;
    float yDiff;
    float zDiff;

    guardPosData = guardData->prop;
    playerPosData = get_curplayer_positiondata();
    xDiff = playerPosData->pos.x - guardPosData->pos.x;
    yDiff = playerPosData->pos.y - guardPosData->pos.y;
    zDiff = playerPosData->pos.z - guardPosData->pos.z;

    return sqrtf(SQR(xDiff) + SQR(yDiff) + SQR(zDiff));
}


/**
 * Address 0x7F032E48.
*/
f32 chrGetDistanceToPad(ChrRecord *self, s32 padID)
{
    PropRecord *myprop;
    PadRecord *pad;

    myprop = self->prop;
    padID  = chrResolvePadId(self, padID);

    if (isNotBoundPad(padID))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padID];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padID)];
    }

    return sqrtf(
        SQR(pad->pos.x - myprop->pos.x) +
        SQR(pad->pos.y - myprop->pos.y) +
        SQR(pad->pos.z - myprop->pos.z));
}



/**
 * Address 0x7F032EFC.
*/
bool check_if_room_for_preset_loaded(ChrRecord *self, s32 padnum)
{
    PadRecord *pad;
    StandTile *padstan;

    padnum = chrResolvePadId(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padnum];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
    }

    padstan = pad->stan;

    if (padstan)
    {
        return getROOMID_Bitflags(getTileRoom(padstan));
    }

    return FALSE;
}


s32 chrResolvePadId(ChrRecord *guardData,s32 padNo)
{
    // Guard's target pad.
    if (padNo == PAD_PRESET1)
    {
        padNo = (s32)guardData->padpreset1;
    }

    return padNo;
}


/**
 * Address 0x7F032FAC.
*/
s32 chrResolveId(ChrRecord *self, s32 id)
{
    if (id == (u8)CHR_SEE_SHOT)
    {
        id = self->chrseeshot;
    }
    else if (id == (u8)CHR_SEE_DIE)
    {
        id = self->chrseedie;
    }
    else if (id == (u8)CHR_PRESET)
    {
        id = self->chrpreset1;
    }
    else if (id == (u8)CHR_SELF)
    {
        id = self->chrnum;
    }
    else if (id == (u8)CHR_CLONE)
    {
        id = self->chrnum + 0x2710;
    }
    else if (id == (u8)CHR_BOND_CINEMA)
    {
        if (g_CurrentPlayer->prop->chr)
        {
            id = g_CurrentPlayer->prop->chr->chrnum;
        }
    }

    return id;
}



/**
 * Address 0x7F033040.
 * chrFindById
*/
ChrRecord *chrFindById(ChrRecord *self, s32 guard_id)
{
    s32 i;
    ChrRecord* guard;

    guard_id = chrResolveId(self, guard_id);
    guard = chrFindByLiteralId(guard_id);

    if (guard == NULL)
    {
        for (i=0; i<g_ActiveChrsCount; i++)
        {
            if (guard_id == g_ActiveChrs[i].chrnum)
            {
                guard = &g_ActiveChrs[i];
                break;
            }
        }
    }

    return guard;
}



/**
 * Address 0x7F0330C4.
*/
f32 chrGetDistanceToChr(ChrRecord *self, s32 chrID)
{
    PropRecord *myprop;
    ChrRecord  *chr;
    f32         distance;

    myprop   = self->prop;
    chr      = chrFindById(self, chrID);
    distance = 0.0f;

    if (chr && chr->model && chr->prop)
    {
        distance = sqrtf(
            SQR(chr->prop->pos.x - myprop->pos.x) +
            SQR(chr->prop->pos.y - myprop->pos.y) +
            SQR(chr->prop->pos.z - myprop->pos.z));
    }
    
    return distance;
}



/**
 * Address 0x7F033154.
*/
f32 chrGetDistanceFromBondToPad(ChrRecord *self, s32 padid)
{
    PropRecord *bondprop;
    PadRecord *pad;

    bondprop = get_curplayer_positiondata();
    padid    = chrResolvePadId(self, padid);

    if (isNotBoundPad(padid))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padid];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padid)];
    }

    return sqrtf(
        SQR(pad->pos.x - bondprop->pos.x) +
        SQR(pad->pos.y - bondprop->pos.y) +
        SQR(pad->pos.z - bondprop->pos.z));
}


/**
 * The property is named "flags2".
 * Address 0x7F033218.
*/
void chrSetFlags2(ChrRecord *self, u8 flags2)
{
    self->flags2 |= flags2;
}



/**
 * The property is named "flags2".
 * Address 0x7F03322C.
*/
void chrUnsetFlags2(ChrRecord *self, u8 flags2)
{
    self->flags2 &= ~flags2;
}



/**
 * The property is named "flags2".
 * Address 0x7F033244.
*/
s32 chrHasFlags2(ChrRecord *self, u8 flags2)
{
    return (self->flags2 & flags2) != 0;
}



/**
 * The property is named "flags2".
 * Address 0x7F033260.
*/
void chrSetFlags2ById(ChrRecord *self, s32 chrNum, u8 flags2)
{
    ChrRecord *chr;

    chr = chrFindById(self, chrNum);

    if (chr != NULL)
    {
        chrSetFlags2(chr, flags2);
    }
}



/**
 * The property is named "flags2".
 * Address 0x7F033290.
*/
void chrUnsetFlags2ById(ChrRecord *self, s32 chrNum, u8 flags2)
{
    ChrRecord *chr;

    chr = chrFindById(self, chrNum);

    if (chr != NULL)
    {
        chrUnsetFlags2(chr, flags2);
    }
}



/**
 * The property is named "flags2".
 * Address 0x7F0332C0.
*/
bool chrHasFlags2ById(ChrRecord *self, s32 chrNum, u8 flags2)
{
    ChrRecord *chr;

    chr = chrFindById(self, chrNum);

    if (chr != NULL)
    {
        return chrHasFlags2(chr, flags2);
    }

    return FALSE;
}



/**
 * Address 0x7F0332FC.
*/
void chrSetStageFlags(ChrRecord *self, s32 arg1)
{
    objectiveregisters1 |= arg1;
}



/**
 * Address 0x7F033318.
*/
void chrUnsetStageFlags(ChrRecord *self, u32 flags)
{
    objectiveregisters1 = ~flags & objectiveregisters1; //shorthand does not match
}


/**
 * Address 0x7F033338.
*/
bool chrHasStageFlag(ChrRecord *self, s32 flags)
{
    return (objectiveregisters1 & flags) != 0;
}



/**
 * Address 0x7F033354.
*/
bool chrIsHearingBond(ChrRecord *self)
{
    return (self->hidden & CHRHIDDEN_ALERT_GUARD_RELATED) != 0;
}



/**
 * Address 0x7F033364.
*/
bool chrTrySurrender(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorThrowWeaponSurrender(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0333A0.
*/
bool chrFadeOut(ChrRecord *self)
{
    chrlvActorFadeAway(self);

    return TRUE;
}



/**
 * Address 0x7F0333C4.
*/
void chrRestartTimer(ChrRecord *self)
{
    self->timer60 = 0;
    self->hidden |= CHRHIDDEN_TIMER_ACTIVE;
}



/**
 * Address 0x7F0333D8.
*/
f32 chrGetTimer(ChrRecord *self)
{
    return self->timer60 / CHRLV_FRAMERATE_F;
}



/**
 * Address 0x7F0333F8.
*/
bool sub_GAME_7F0333F8(ChrRecord *self)
{
    Model  *mymodel;
    coord3d zeropos;
    coord3d pos;
    vec3    vec;
    f32     scale;

    if (chrlvCurrentPlayerCall7F0B0E24(self))
    {
        mymodel = self->model;
        scale   = getinstsize(mymodel) * 0.8f;
        sub_GAME_7F068190(&zeropos, &pos);
        getsuboffset(mymodel, &vec);
        matrix_4x4_transform_vector_in_place(currentPlayerGetMatrix10CC(), &vec);

        if (sub_GAME_7F041074(&zeropos, &pos, &vec, scale))
        {
            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F033490.
*/
bool chrIfNearMiss(ChrRecord *self)
{
    return (self->chrflags & CHRFLAG_NEAR_MISS) != 0;
}



/**
 * Address 0x7F0334A0.
*/
bool chrGoToBond(ChrRecord *self, SPEED speed)
{
    PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        bondprop = get_curplayer_positiondata();

        if (plot_course_for_actor(self, &bondprop->pos, bondprop->stan, speed))
        {
            return TRUE;
        }
    }

    return FALSE;
}


/**
 * Address 0x7F03350C0.
*/
bool chrGoToChr(ChrRecord *self, s32 chrid, SPEED speed)
{
    ChrRecord *chr;
    PropRecord *chrprop;

    if (chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        chr = chrFindById(self, chrid);
        if (chr && chr->model && chr->prop)
        {
            chrprop = chr->prop;

            if (plot_course_for_actor(self, &chrprop->pos, chrprop->stan, speed))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Return number of hits.
 * 
 * Address 0x7F0335A4.
 * PD: chrGetNumArghs
 */
s8 chrGetNumArghs(ChrRecord *self)
{
    return self->numarghs;
}



/**
 * Return number of near misses
 * 
 * Address 0x7F0335AC.
 * PD: chrGetNumCloseArghs
 */
s8 chrGetNumCloseArghs(ChrRecord *self)
{
    return self->numclosearghs;
}


/**
 * Return false if chrseeshot is negative.
 * 
 * Address 0x7F0335B4.
 */
bool chrSawInjury(ChrRecord *self)
{
    return ((self->chrseeshot < 0) ^ 1);
}


/**
 * Return false if chrseedie is negative.
 * 
 * Address 0x7F0335C4.
 */
bool chrSawDeath(ChrRecord *self)
{
    return ((self->chrseedie < 0) ^ 1);
}



/**
 * Address 0x7F0335D4.
*/
bool chraiStopAnimation(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvKneelingAnimationRelated7F023E48(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033610.
*/
bool chrTrySurprisedOneHand(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorShuffleFeet(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F03364C.
*/
bool chrTrySurprisedSurrender(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvSurrenderAnimationRelated(self);

        return TRUE;

    }
    return FALSE;
}


/**
 * Address 0x7F033688.
*/
bool chrTrySurprisedLookAround(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorLookFlustered(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0336C4.
*/
bool check_if_able_to_then_kneel(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorKneel(self);

        return TRUE;
    }

    return FALSE;
}


/**
 * Address 0x7F033700.
*/
s32 check_if_able_to_then_perform_animation(ChrRecord *self, s32 animID, s32 b, s32 c, u8 d, s32 e)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvPerformAnimationForActor(self, animID, b, c, d, e);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033760.
 * PD: chrCanHearAlarm
*/
bool chrCanHearAlarm(ChrRecord *self)
{
    /*
     possibly this was to be more advanced than simply
     a stub to alarmIsActive.
     It could have for example done a room check
     since this has a "self" reference.
     */
    return alarmIsActive();
}



/**
 * Address 0x7F033780.
 * PD: waypointIsWithin90DegreesOfPosAngle
*/
s32 sub_GAME_7F033780(waypoint *arg0, coord3d *arg1, f32 angle)
{
    f32 temp_f0;
    PadRecord *pad;
    f32 dx;
    f32 dz;
    f32 ff;

    pad = &g_chraiCurrentSetup.pads[arg0->padID];
    dx = pad->pos.f[0] - arg1->f[0];
    dz = pad->pos.f[2] - arg1->f[2];
    
    temp_f0 = atan2f(dx, dz);
    ff = angle - temp_f0;

    if (angle < temp_f0)
    {
        ff += M_TAU_F;
    }

    if ((ff < DegToRad(90)) || (ff > DegToRad(270)))
    {
        return 1;
    }

    return 0;
}




/**
 * Attempt to find a waypoint near pos which is in a particular quadrant to pos,
 * then return its padnum.
 *
 * For example, pos is typically the player's position, angle is the direction
 * the player is facing, and quadrant is which quadrant (front/back/left/right)
 * that is desired relative to the player's position and angle.
 *
 * The function starts by finding the closest waypoint to the pos. If it's not
 * in the quadrant then its neighouring waypoints are checked too. If none of
 * those are in the quadrant then no further checks are made and the function
 * returns -1.
 *
 * Address 0x7F033834.
 * PD: chrFindWaypointWithinPosQuadrant
*/
s32 chrlvFindPathNeighborRelated(coord3d *bondpos, StandTile *stan, f32 rot, u8 quadrant)
{
    s32 padnum_2;
    s32 temp_s1;
    s32 temp_s1_2;
    waypoint *waypoint;
    s32 path_id;
    s32 neighbor_index;

    waypoint = chrlvStanPathRelated(bondpos, stan);

    if (waypoint)
    {
        switch (quadrant)
        {
            case QUADRANT_BACK:
                rot = rot + DegToRad(180);
                break;

            case QUADRANT_SIDE1:
                rot = rot + DegToRad(90);
                break;

            case QUADRANT_SIDE2:
                rot = rot + DegToRad(270);
                break;

            case QUADRANT_FRONT:
                break;
        }

        if (rot >= M_TAU_F)
        {
            rot = rot - M_TAU_F;
        }

        if (sub_GAME_7F033780(waypoint, bondpos, rot))
        {
            return waypoint->padID;
        }

        for (
            neighbor_index = 0, path_id = waypoint->neighbours[neighbor_index];
            path_id>=0;
            neighbor_index++, path_id = waypoint->neighbours[neighbor_index]
            )
        {
            if (sub_GAME_7F033780(&g_chraiCurrentSetup.pathwaypoints[path_id], bondpos, rot) != 0)
            {
                return g_chraiCurrentSetup.pathwaypoints[path_id].padID;
            }
        }
    }

    return -1;
}



/**
 * Address 0x7F033998.
*/
bool check_2328_preset_set_with_method(ChrRecord *self, u8 quadrant)
{
    PropRecord *myprop;
    PropRecord *bondprop;
    
    waypoint *myclosestwaypoint;
    waypoint *bondsclosestwaypoint;

    waypoint *sp2C[PATH_FINDING_WP_LIMIT];
    
    if ((quadrant == QUADRANT_2NDWPTOTARGET) || (quadrant == QUADRANT_20))
    {
        myprop               = self->prop;
        bondprop             = get_curplayer_positiondata();
        myclosestwaypoint    = chrlvStanPathRelated(&myprop->pos, myprop->stan); 
        bondsclosestwaypoint = chrlvStanPathRelated(&bondprop->pos, bondprop->stan);

        if (myclosestwaypoint != NULL && bondsclosestwaypoint != NULL)
        {
            if (quadrant == QUADRANT_2NDWPTOTARGET)
            {
                if (waypointFindRoute(myclosestwaypoint, bondsclosestwaypoint, (waypoint **)&sp2C, PATH_FINDING_WP_LIMIT) >= PATH_FINDING_WP_LIMIT)
                {
                    self->padpreset1 = sp2C[1]->padID;

                    return TRUE;
                }
            }
            else 
            {
                myclosestwaypoint = sub_GAME_7F08FB90(myclosestwaypoint, bondsclosestwaypoint);
                if (myclosestwaypoint != NULL)
                {
                    self->padpreset1 = myclosestwaypoint->padID;

                    return TRUE;
                }
            }
        }
    }
    else
    {
        s32 closestpadid = chrlvFindPathNeighborRelated(&self->prop->pos, self->prop->stan, getsubroty(self->model), quadrant);

        if (closestpadid >= 0)
        {
            self->padpreset1 = closestpadid;

            return TRUE;
        }
    }

    return FALSE;
}




/**
 * Address 0x7F033AAC.
*/
bool sub_GAME_7F033AAC(ChrRecord *self, u8 padnum)
{
    f32 sp1C;
    s32 bondnearestpad;
    PropRecord *bondprop;

    if ((padnum == 16) || (padnum == 32))
    {
        return check_2328_preset_set_with_method(self, padnum);
    }

    sp1C           = get_curplay_horizontal_rotation_in_degrees();
    bondprop       = get_curplayer_positiondata();
    bondnearestpad = chrlvFindPathNeighborRelated(&bondprop->pos, bondprop->stan, sp1C, padnum);

    if (bondnearestpad >= 0)
    {
        self->padpreset1 = bondnearestpad;

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033B38.
 * PD: chrSetChrPresetToChrNearPos
*/
bool sub_GAME_7F033B38(ChrRecord *self, f32 distance)
{
    PropRecord *myprop;
    ChrRecord *chr;
    s32 numguards;
    coord3d distneg;
    coord3d distplus;
    s32 myroom;
    s32 i;

    numguards = get_numguards();
    myprop    = self->prop;
    myroom    = myprop->stan->room;

    distneg.x  = myprop->pos.x - distance;
    distplus.x = myprop->pos.x + distance;
    distneg.y  = myprop->pos.y - distance;
    distplus.y = myprop->pos.y + distance;
    distneg.z  = myprop->pos.z - distance;
    distplus.z = myprop->pos.z + distance;

    for (i = 0; i < numguards; i++)
    {
        chr = &ptr_guard_data[i];

        if ((chr != self) && chr->model && !chrIsDead(chr))
        {
            coord3d *pos = &chr->prop->pos;

            if (
                (pos->x >= distneg.x)  &&
                (pos->x <= distplus.x) &&
                (pos->y >= distneg.y)  &&
                (pos->y <= distplus.y) &&
                (pos->z >= distneg.z)  &&
                (pos->z <= distplus.z) &&
                ((chr->prop->stan->room == myroom) || sub_GAME_7F0B8FD0(myroom, chr->prop->stan->room)))
            {
                self->chrpreset1 = chr->chrnum;

                return TRUE;
            }
        }
    }
    return FALSE;
}



/**
 * Address 0x7F033CF4.
*/
void chrSetChrPreset(ChrRecord *self, s32 id)
{
    self->chrpreset1 = chrResolveId(self, id);
}


/**
 * Address 0x7F033D1C.
*/
void chrSetChrPreset2(ChrRecord *self, s32 id, s32 id2)
{
    ChrRecord *chr;

    chr = chrFindById(self, id);

    if (chr)
    {
        chr->chrpreset1 = chrResolveId(self, id2);
    }
}



/**
 * Address 0x7F033D5C.
*/
void chrSetPadPreset( ChrRecord *self, s32 padid)
{
    self->padpreset1 = chrResolvePadId(self, padid);
}


/**
 * Address 0x7F033D84.
*/
void chrSetPadPresetByChrnum(ChrRecord *self, s32 chrid, s32 padid)
{
    ChrRecord *chr = chrFindById(self, chrid);

    if (chr)
    {
        chr->padpreset1 = chrResolvePadId(self, padid);
    }
}



/**
 * Address 0x7F033DC4.
*/
s32 chrIsTargetNearlyInSight(ChrRecord *self)
{
    PropRecord *player_prop;
    PropRecord *self_prop;
    StandTile *stan;
    coord3d sp48;
    coord3d sp3C;

    player_prop = get_curplayer_positiondata();
    self_prop   = self->prop;
    stan        = self_prop->stan;

    sub_GAME_7F0B1CC4();

    if (walkTilesBetweenPoints_NoCallback(&stan, self_prop->pos.x, self_prop->pos.z, player_prop->pos.x, player_prop->pos.z))
    {
        return FALSE;
    }
    else
    {
        getCollisionEdge_maybe(&sp48, &sp3C); //extreme edges of stan tile

        if (
            sub_GAME_7F0304AC(self, &self_prop->pos, self_prop->stan, &sp48, &player_prop->pos, player_prop->stan, 0)
            || sub_GAME_7F0304AC(self, &self_prop->pos, self_prop->stan, &sp3C, &player_prop->pos, player_prop->stan, 0))
        {
            return TRUE;
        }
    }

    return FALSE;
}





/**
 * Address 0x7F033EAC.
*/
s32 sub_GAME_7F033EAC(coord3d *arg0, StandTile *arg1)
{
    bool pass;
    bbox2d sp1C;

    pass = TRUE;

    if (getROOMID_Bitflags(getTileRoom(arg1)) && fogPositionIsVisibleThroughFog(arg0, 0.0f))
    {
        if (bgGet2dBboxByRoomId(getTileRoom(arg1), &sp1C))
        {
            pass = sub_GAME_7F078BF4(arg0, 200.0f, &sp1C) == 0;
        }
        else
        {
            pass = sub_GAME_7F078A58(arg0, 200.0f) == 0;
        }
    }

    return pass;
}


/**
 * Address 0x7F033F48.
*/
bool sub_GAME_7F033F48(coord3d *pos, StandTile **arg1, f32 facing, bool b)
{
    coord3d angle;
    StandTile *s;
    s32 i;
    StandTile **spp;

    s = *arg1;
    spp = &s;

    if ((sub_GAME_7F0B18B8(spp, pos->f[0], pos->z, 20.0f, 0x1F, 0.0f, 1.0f) < 0) &&
        (b || sub_GAME_7F033EAC(pos, *arg1)))
    {
        return TRUE;
    }

    for (i = 0; i < 8; i++)
    {
        angle.f[0] = pos->f[0] + (sinf(facing) * 60.0f);
        angle.f[1] = pos->f[1];
        angle.f[2] = pos->f[2] + (cosf(facing) * 60.0f);

        s = *arg1;

        if (sub_GAME_7F0B0E24(spp, pos->f[0], pos->f[2], angle.f[0], angle.f[2], 0x13, 0.0f, 1.0f, 0.0f, 1.0f)
            && (sub_GAME_7F0B18B8(spp, angle.f[0], angle.f[2], 20.0f, 0x1F, 0.0f, 1.0f) < 0)
            && (b || sub_GAME_7F033EAC(&angle, s)))
        {
            *arg1 = s;

            pos->f[0] = angle.f[0]; //send back upstream
            pos->f[2] = angle.f[2];

            return TRUE;
        }

        facing += 0.7853982f;

        if (facing >= M_TAU_F) //clamp to 1 revolution
        {
            facing -= M_TAU_F;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F03415C.
*/
PropRecord *actionblock_guard_constructor_BDBE(s32 bodynum, s32 headnum, coord3d *pos, StandTile *stan, f32 yrot, AIListRecord *ailist, s32 arg5)
{
    PropRecord *chrprop;
    coord3d newpos; //struct copy here would have been more efficient
    ChrRecord *chr;
    StandTile *stancopy;
    Model *chrHeader;

    if (chrGetNumFree() >= 3)
    {
        if (headnum < 0)
        {
            headnum = select_psuedorandom_heads(bodynum);
        }

        newpos.x = pos->x;
        newpos.y = pos->y;
        newpos.z = pos->z;
        stancopy = stan;

        if (sub_GAME_7F033F48(&newpos, &stancopy, yrot, ((arg5 & 0x10) != 0)))
        {
            chrHeader = retrieve_header_for_body_and_head(bodynum, headnum, arg5);

            if (chrHeader != NULL)
            {
                chrprop = replace_GUARDdata_with_actual_values(chrHeader, &newpos, yrot, stancopy, ailist);

                if (chrprop != NULL)
                {
                    chrpropActivateThisFrame(chrprop);
                    chrpropEnable(chrprop);
                    chr          = chrprop->chr;
                    chr->headnum = headnum;
                    chr->bodynum = bodynum;

                    return chrprop;
                }
            }
        }
    }

    return NULL;
}



/**
 * Address 0x7F034258.
*/
PropRecord *chrSpawnAtPad(ChrRecord *self, s32 bodynum, s32 headnum, s32 padid, AIListRecord *ailist, s32 flags)
{
    PadRecord *pad;
    padid = chrResolvePadId(self, padid);

    if (isNotBoundPad(padid))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padid];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padid)];
    }
    #ifdef DEBUG
    osSyncPrintf("%s%s new char x = %f, y = %f, z = %f \n", "", "", pad->pos.x, pad->pos.y, pad->pos.z);
    #endif
    return actionblock_guard_constructor_BDBE(bodynum, headnum, &pad->pos, pad->stan, atan2f(pad->look.f[0], pad->look.f[2]), ailist, flags);
}



/**
 * Address 0x7F034308.
 */
PropRecord *chrSpawnAtChr(ChrRecord *self, s32 bodynum, s32 headnum, s32 chrnum, AIListRecord *ailist, s32 flags)
{
    ChrRecord *chr;
    chr = chrFindById(self, chrnum);

    if (!(chr->chrflags & CHRFLAG_HAS_BEEN_ON_SCREEN))
    {
        f32 chrRadHeading   = getsubroty(chr->model);
        PropRecord *chrprop = chr->prop;

        return actionblock_guard_constructor_BDBE(bodynum, headnum, &chrprop->pos, chrprop->stan, chrRadHeading, ailist, flags);
    }

    return NULL;
}



/**
 * Address 0x7F034388.
*/
bool chrIfInPadRoom(ChrRecord *self, s32 chrnum, s32 padnum)
{
    PadRecord *pad;
    ChrRecord *chr;

    chr    = chrFindById(self, chrnum);
    padnum = chrResolvePadId(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padnum];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
    }

    if (pad->stan && chr)
    {
        if (chr->prop && (pad->stan->room == chr->prop->stan->room))
        {
            return TRUE;
        }
    }

    return FALSE;
}


/**
 * Address 0x7F03444C.
*/
bool check_if_actor_is_at_preset(ChrRecord *self, s32 padnum)
{
    PropRecord *bondprop;
    PadRecord  *pad;

    bondprop = get_curplayer_positiondata();
    padnum   = chrResolvePadId(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.pads[padnum];
    }
    else
    {
        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
    }

    if (pad->stan && (pad->stan->room == bondprop->stan->room))
    {
        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0344FC.
*/
bool removed_animation_routine_27(ChrRecord *self)
{
    return FALSE;
}

/**
 * Address 0x7F034508.
*/
bool removed_animation_routine_2B(ChrRecord *self)
{
    return FALSE;
}



/**
 * Address 0x7F034514.
*/
bool chrTryStartAlarm(ChrRecord *self, s32 PadId)
{
    ObjectRecord *objinst;

    PadId = chrResolvePadId(self, PadId);

    if (chrIsNotDeadOrShot(self))
    {
        objinst = scan_position_data_table_for_normal_object_at_preset(PadId);

        if (objinst && objIsHealthy(objinst))
        {
            chrlvExtendLeftHandAnimationRelated(self);

            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F03457C.
*/
bool actor_draws_throws_grenade_at_player_if_possible(ChrRecord *self)
{
    PropRecord *Left;
    PropRecord *Right;

    PropRecord      *NewGrenadeProp;
    WeaponObjRecord *NewGrenadeObj;
    WeaponObjRecord *LeftWep;
    WeaponObjRecord *RightWep;

    s32 flags;
    //GUNHAND hand;
    //"grenade prob: no chr number %d for obj number %d!\n"
    if (((u32)randomGetNext() % (u32)0xFF) >= self->grenadeprob)
    {
        return FALSE;
    }

    if (chrGetDistanceToBond(self) < 10.0f)
    {
        return FALSE;
    }

    if (chrIsNotDeadOrShot(self))
    {
        Left  = chrGetEquippedWeaponProp(self, GUNLEFT);
        Right = chrGetEquippedWeaponProp(self, GUNRIGHT);

        if (Right && (RightWep = Right->weapon, RightWep->weaponnum == ITEM_GRENADE))
        {
            chrlvThrowGrenadeAnimationRelated(self, Right, GUNRIGHT, 0);

            return TRUE;
        }

        if (Left && (LeftWep = Left->weapon, LeftWep->weaponnum == ITEM_GRENADE))
        {
            chrlvThrowGrenadeAnimationRelated(self, Left, GUNLEFT, 0);

            return TRUE;
        }

        if (!Left || !Right)
        {
            flags = 0;
            
            if (Right)
            {
                flags = 0x10000000;
            }
            
            NewGrenadeProp = chrGiveWeapon(self, 0xC4, ITEM_GRENADE, flags);
            
            if (NewGrenadeProp)
            {
                NewGrenadeObj = NewGrenadeProp->weapon;
                NewGrenadeObj->runtime_bitflags |= 0x800; //manual bitflags are more effecient
                
                chrlvThrowGrenadeAnimationRelated(self, NewGrenadeProp, !Right ? GUNRIGHT : GUNLEFT, 1); //this matches

                return TRUE;
            }
        }
    }

    return FALSE;
}


/**
 * Address 0x7F0346FC.
 * chrDropItem
*/
bool chrDropItem(ChrRecord *self, s32 modelnum, u8 weaponid)
{
    WeaponObjRecord *NewModel = (WeaponObjRecord *)create_new_item_instance_of_model(modelnum, weaponid);
    
    if (NewModel && NewModel->prop)
    {
        modelSetScale(NewModel->model, NewModel->model->scale);
        chrpropReparent(NewModel->prop, self->prop);
        NewModel->timer = CHRLV_DEFAULT_TIMER;
        propobjSetDropped(NewModel->prop, 1);
        self->hidden = self->hidden | 1;

        return TRUE;
    }

    return FALSE;
}
