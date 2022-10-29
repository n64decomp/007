#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include <snd.h>

extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 F_80030B1C;
extern f32 F_80030B20;
extern f32 F_80030B24;
extern f32 g_SoloAmmoMultiplier;

extern s32 alarm_timer;
extern s32 *ptr_alarm_sfx;
extern f32 toxic_gas_sound_timer;
extern s32 activate_gas_sound_timer;
extern coord3d D_80030AD0;
extern s32 D_80030ADC;
extern f32 D_80030AE0;
extern ALSoundState *ptr_gas_sound;
extern s32 clock_drawn_flag;
extern s32 clock_enable;
extern f32 clock_time;
extern s32 D_80030AF4;
extern s32 D_80030AF8;
extern s32 D_80030AFC;
extern ObjectRecord *g_LevelLoadPropSwitch;
extern ObjectRecord *g_LevelLoadPropLockDoor;
extern ObjectRecord *g_LevelLoadPropSafeItem;
extern s32 D_80030B0C;
extern s32 bodypartshot;
extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 F_80030B1C;
extern f32 F_80030B20;
extern f32 F_80030B24;
extern f32 g_SoloAmmoMultiplier;

/**
 * @param arg0: Prop for tank
 * @param arg1: maybe flags
 */
void                 sub_GAME_7F04F218(struct PropRecord *arg0, s32 arg1);

void                 objFreePermanently(struct ObjectRecord *obj, bool freeprop);

void                 chrobjApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);
void                 chrobjCallsApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);
Gfx                 *sub_GAME_7F049B58(Gfx *arg0);
void                 set_color_shading_from_tile(PropRecord *, rgba_u8 *);
void                 propobjSetDropped(PropRecord *, s32);
void                 sub_GAME_7F053A10(ALSoundState *, coord3d *);
void                 alarmActivate(void);
void                 sub_GAME_7F052574(PropRecord *, s32);
s32                  sub_GAME_7F052604(PropRecord *);
s32                  sub_GAME_7F0539E4(coord3d *pos); //getVolume?
ObjectRecord        *create_new_item_instance_of_model(PROP propid, s32 arg1);
void                 maybe_detonate_object(ObjectRecord *arg0, f32 arg1, coord3d *arg2, ITEM_IDS item, s32 arg4);
void                 chrobjMaybeDetonateObjectIfFlags(ObjectRecord *arg0, f32 arg1, coord3d *arg2, ITEM_IDS item, s32 arg4);
void                 sub_GAME_7F03FDA8(PropRecord *);
void                 sub_GAME_7F03FE14(PropRecord *);
void                 chrobjCollisionRelated(ObjectRecord *);
void                 sub_GAME_7F040754(ObjectRecord *, coord3d *, Mtxf *, StandTile *);
s32                  sub_GAME_7F041074(coord3d *arg0, coord3d *arg1, coord3d *arg2, f32 arg3);
void                 sub_GAME_7F04F244(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *arg3, f32 *arg4);
void                 doorActivate(DoorRecord *door, DOORSTATE State);
s32                  sub_GAME_7F055A70(PropRecord *arg0, DoorRecord *arg1);
void                 sub_GAME_7F055B78(PropRecord *arg0, DoorRecord *arg1);
Gfx                 *chrobjRenderProp(PropRecord *arg0, Gfx *arg1, s32 arg2);

f32                  chrobjFogVisRangeRelated(PropRecord *prop, f32 size);
s32                  sub_GAME_7F054A64(PropRecord *prop, bbox2d *bbox);

// note: rgba to rgb
void                 sub_GAME_7F040384(rgba_s32 *arg0, s32 arg1, rgba_f32 *arg2);
void                 trigger_remote_mine_detonation(void);

void                 sub_GAME_7F04C044(PropRecord *prop);
void                 sub_GAME_7F040CF0(PropRecord *);
bool                 alarmIsActive();
void                 init_trigger_toxic_gas_effect(coord3d *source);
void                 chrSetWeaponFlag4(ChrRecord *chr, GUNHAND hand);
void                 sub_GAME_7F053B10(DoorRecord *door);
void                 doorActivatePortal(DoorRecord *door);
void                 sub_GAME_7F052B00(DoorRecord *door);
s32                  sub_GAME_7F0539B8(f32 vol);
void                 monitorSetImageByNum(MonitorRecord *mon, s32 monAnimID);
void                 propweaponSetDual(WeaponObjRecord *leftweapon, WeaponObjRecord *rightweapon);
f32                  countdownTimerGetValue(void);
bool                 countdownTimerIsRunning(void);
void                 countdownTimerSetRunning(bool enable);
void                 countdownTimerSetValue(f32 time);
void                 countdownTimerSetVisible(int clocklockbits, bool unset);
void                 sub_GAME_7F04088C(ObjectRecord *baseobj, PadRecord *pad, Mtxf *matrix, StandTile *stan, PadRecord *pad2);
bool                 sub_GAME_7F051E1C(WeaponObjRecord *wep, ChrRecord *chr);
INV_ITEM_TYPE        collect_or_interact_object(PropRecord *prop, bool showstring);
INV_ITEM_TYPE        propobjInteract(PropRecord *prop);
s32                  do_something_if_object_destroyed(ObjectRecord *obj);
void                 doorActivateWrapper(PropRecord *prop);
bool                 objIsHealthy(ObjectRecord *self);
ObjectRecord        *weaponFindThrown(s32 ID);
bool                 check_if_toxic_gas_activated();
PropRecord          *chrTryEquipHat(ChrRecord *self, s32 index, s32 flags);
void sub_GAME_7F04C044(PropRecord *prop);
void sub_GAME_7F043650(struct WeaponObjRecord *arg0);
s32 sub_GAME_7F0446B8(struct rect4f *arg0, s32 arg1, struct rect4f *arg2, s32 arg3);
s32 chrobjTestPointPolygonCollision(struct coord3d *arg0, f32 arg1, struct rect4f *arg2, s32 arg3);
void sub_GAME_7F04DEFC(PropRecord *arg0, f32 arg1, struct coord3d *arg2, s32 arg3, s32 owner);
struct modeldata_unk_pos * sub_GAME_7F040078(ObjectRecord *arg0);
#endif
