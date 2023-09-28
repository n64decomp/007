#ifndef _CHR2_H_
#define _CHR2_H_
#include <ultra64.h>
#include <bondgame.h>
#include "chrobjdata.h"

// Value is 3, it just needs to be less than MAX_CHRWAYPOINTS
#define PATH_FINDING_WP_LIMIT (MAX_CHRWAYPOINTS - 3)

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



Model * retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags);

s32 get_current_random_body(void);

s32 bodyChooseHead(s32 id);

s32 get_random_head(s32 id);
f32 chrGetDistanceToBond(ChrRecord *guardData);
s32 chrCheckTargetInSight(ChrRecord *self);
bool actor_fire_or_aim_at_target_update(ChrRecord *self, s32 newtargettype, s32 newtargetid);
void chrlvAlertGuardToPlayerPosition(ChrRecord *);
void chrlvIdleAnimationRelated7F023A94(ChrRecord *self, f32 mergetime);
f32 chrGetAngleToBond(ChrRecord *arg0);
s32 chrHasStoppedOrPatroling(ChrRecord *);
s32 chrResolvePadId(ChrRecord *guardData,s32 padNo);
void chrlvLineLineIntersection(coord3d *arg0, coord3d *arg1, coord3d *arg2, coord3d *arg3, coord3d *result);
void chrlvStanLineDirIntersection(coord3d *arg0, coord3d *arg1, coord3d *result);
void chrlvStanPointPointIntersection(coord3d *arg0, coord3d *arg1, coord3d *result);
bool handles_shot_actors(ChrRecord *self, s32 hitpart, coord3d *vector, s32 weaponid, bool isPlayer);
bool chrCanSeeBond(ChrRecord *self);
bool check_if_position_in_same_room(ChrRecord *self, coord3d *pos, StandTile *stan);
s32 chrSawTargetRecently(ChrRecord *);
s32 chrIsDead(ChrRecord *chr);
bool actor_steps_sideways(ChrRecord *self);
bool actor_hops_sideways(ChrRecord *self);
bool actor_jogs_sideways(ChrRecord *self);
bool actor_walks_and_fires(ChrRecord *self);
bool actor_runs_and_fires(ChrRecord *self);
bool actor_rolls_fires_crouched(ChrRecord *self);
bool actor_aim_at_actor(ChrRecord *self, s32 attack_type, s32 b);
bool actor_kneel_aim_at_actor(ChrRecord *self, s32 targettype, s32 targetid);
bool check_set_actor_standing_still(ChrRecord *self, s32 faceentitytype, s32 faceentityid);
bool chrGoToPad(ChrRecord *self, s32 padid, SPEED speed);
bool if_actor_able_set_on_path(ChrRecord *self, s32 pathid);
f32 chrlvGetSubrotySideback(ChrRecord *arg0);
f32 chrlvGetAimLimitAngle(f32 arg0);
void chrlvUpdateAimendbackShoulders(ChrRecord *arg0, void *arg1, s32 same, s32 swap, f32 next);
void chrSetFiring(ChrRecord *arg0, s32 hand, s32 firing);
s32 sub_GAME_7F02D630(ChrRecord *arg0, GUNHAND hand, coord3d *arg2);
void chrlvTriggerFireWeapon(ChrRecord *arg0);
s32 chrlvGeometryRelated7F02FC34(coord3d *arg0, coord3d *arg1, coord3d *arg2, f32 arg3);
s32 chrlvIsArrivingLaterallyAtPos(coord3d *prevpos, coord3d *curpos, coord3d *targetpos, f32 range);
void chrlvActionTick(ChrRecord *arg0);
void chrlvAllChrTick(void);
s32 chrSawTargetRecently(ChrRecord *arg0);
s32 chrHeardTargetRecently(ChrRecord *arg0);
ChrRecord *chrFindById(ChrRecord *arg0, s32);
f32 chrGetAngleFromBond(ChrRecord *self);
f32 chrGetDistanceToPad(ChrRecord *self, s32 padID);
bool check_if_room_for_preset_loaded(ChrRecord *self, s32 padnum);
f32 chrGetDistanceToChr(ChrRecord *self, s32 chrID);
f32 chrGetDistanceFromBondToPad(ChrRecord *self, s32 padid);
void chrSetFlags2(ChrRecord *arg0, u8 arg1);
void chrUnsetFlags2(ChrRecord *arg0, u8 arg1);
s32 chrHasFlags2(ChrRecord *self, u8 arg1);
void chrSetFlags2ById(ChrRecord *arg0, s32 guard_id, u8 arg2);
void chrUnsetFlags2ById(ChrRecord *arg0, s32 guard_id, u8 arg2);
s32 chrHasFlags2ById(ChrRecord *arg0, s32 guard_id, u8 arg2); //chrHasFlags2ById
void chrSetStageFlags(ChrRecord *arg0, s32 arg1);
void chrUnsetStageFlags(ChrRecord *self, u32 flags);
bool chrHasStageFlag(ChrRecord *self, s32 flags);
bool chrIsHearingBond(ChrRecord *self);
bool chrTrySurrender(ChrRecord *self);
bool chrFadeOut(ChrRecord *self);
void chrRestartTimer(ChrRecord *self);
f32 chrGetTimer(ChrRecord *self);
bool sub_GAME_7F0333F8(ChrRecord *self);
bool chrIfNearMiss(ChrRecord *self);
bool chrGoToBond(ChrRecord *self, SPEED speed);
bool chrGoToChr(ChrRecord *self, s32 chrid, SPEED speed);
s8 chrGetNumArghs(ChrRecord *self);
s8 chrGetNumCloseArghs(ChrRecord *self);
bool chrSawInjury(ChrRecord *self);
bool chrSawDeath(ChrRecord *self);
bool chraiStopAnimation(ChrRecord *self);
bool chrTrySurprisedOneHand(ChrRecord *self);
bool chrTrySurprisedSurrender(ChrRecord *self);
bool chrTrySurprisedLookAround(ChrRecord *self);
bool check_if_able_to_then_kneel(ChrRecord *self);
s32 check_if_able_to_then_perform_animation(ChrRecord *self, s32 animID, s32 b, s32 c, u8 d, s32 e);
bool chrCanHearAlarm(ChrRecord *self);
bool check_2328_preset_set_with_method(ChrRecord *self, u8 quadrant);
bool sub_GAME_7F033AAC(ChrRecord *self, u8 padnum);
bool sub_GAME_7F033B38(ChrRecord *self, f32 distance);
void chrSetChrPreset(ChrRecord *self, s32 id);
void chrSetChrPreset2(ChrRecord *self, s32 id, s32 id2);
void chrSetPadPreset( ChrRecord *self, s32 padid);
void chrSetPadPresetByChrnum(ChrRecord *self, s32 chrid, s32 padid);
s32 chrIsTargetNearlyInSight(ChrRecord *arg0);
bool sub_GAME_7F033F48(coord3d *pos, StandTile **arg1, f32 facing, bool b);
PropRecord *chrSpawnAtPad(ChrRecord *self, s32 bodynum, s32 headnum, s32 padid, AIListRecord *ailist, s32 flags);
PropRecord *chrSpawnAtChr(ChrRecord *self, s32 bodynum, s32 headnum, s32 chrnum, AIListRecord *ailist, s32 flags);
bool chrIfInPadRoom(ChrRecord *self, s32 chrnum, s32 padnum);
bool check_if_actor_is_at_preset(ChrRecord *self, s32 padnum);
bool removed_animation_routine_27(ChrRecord *self);
bool removed_animation_routine_2B(ChrRecord *self);
bool chrTryStartAlarm(ChrRecord *self, s32 PadId);
bool actor_draws_throws_grenade_at_player_if_possible(ChrRecord *self);
bool chrDropItem(ChrRecord *self, s32 modelnum, u8 weaponid);
void expand_09_characters(s32 stageid, GuardRecord *arg1, s32 arg2);
void chrlvGetPatrolPercentOrPosition(ChrRecord *arg0, coord3d *arg1);
s32 chrlvExplosionDamage(ChrRecord *arg0, coord3d *arg1, f32 arg2, s32 arg3);

#endif
