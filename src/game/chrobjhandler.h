#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include <snd.h>

struct ShotData {
    // temporary definition for GE:
    /*0x00*/ s32 unk00[13];
    /*0x34*/ f32 unk34;

    // the following is from PD, it seems to line up:
        /*0x00*/ //struct coord unk00;
        /*0x0c*/ //struct coord unk0c;
        /*0x18*/ //struct gset gset;
        /*0x1c*/ //struct coord gunpos;
        /*0x28*/ //struct coord dir;
        /*0x34*/ //f32 unk34;
        /*0x38*/ //s32 penetration;
        /*0x3c*/ //struct hit hits[10];
};

struct HitThing {
    // the following is taken from PD
    // may need adjustments
    coord3d unk00;
    coord3d unk0c;
    Vertex *unk18;
    Vertex *unk1c;
    Vertex *unk20;
    Gfx *tricmd;
    s16 unk28;
    s16 texturenum;
    s16 unk2c;
};

extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 g_AutogunPendingDamageTick;
extern f32 g_AutogunDamageScalar;
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
extern s32 g_RemoteMineOwnerTriggerFlag;
extern s32 g_NextWeaponSlot;
extern s32 g_NextHatSlot;
extern ObjectRecord *g_LevelLoadPropSwitch;
extern LockDoorRecord *g_LevelLoadPropLockDoor;
extern ObjectRecord *g_LevelLoadPropSafeItem;
extern struct PropRecord *D_80030B0C;
extern s32 bodypartshot;
extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 g_AutogunPendingDamageTick;
extern f32 g_AutogunDamageScalar;
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
void                 propobjSetDropped(PropRecord *prop, DROPTYPE droptype);
void                 chrobjSndCreatePostEventDefault(ALSoundState *, coord3d *);
void                 alarmActivate(void);
void                 weaponSetGunfireVisible(PropRecord *prop, s32 firing);
s32                  weaponIsGunfireVisible(PropRecord *);
s32                  sub_GAME_7F0539E4(coord3d *pos); //getVolume?
ObjectRecord        *create_new_item_instance_of_model(PROP propid, s32 arg1);
void                 maybe_detonate_object(ObjectRecord *obj, f32 damage, coord3d *pos, ITEM_IDS item, s32 owner);
void                 chrobjMaybeDetonateObjectIfFlags(ObjectRecord *arg0, f32 arg1, coord3d *arg2, ITEM_IDS item, s32 arg4);
void                 sub_GAME_7F03FDA8(PropRecord *);
void                 projectileSetSticky(PropRecord *);
void                 chrobjCollisionRelated(ObjectRecord *);
void                 objChangeShading(ObjectRecord *, coord3d *, Mtxf *, StandTile *);
s32                  sub_GAME_7F041074(coord3d *arg0, coord3d *arg1, coord3d *arg2, f32 arg3);
void                 sub_GAME_7F04F244(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *arg3, f32 *arg4);
void                 doorActivate(DoorRecord *door, DOORSTATE State);
s32                  posIsInFrontOfDoor(PropRecord *arg0, DoorRecord *arg1);
void                 doorsChooseSwingDirection(PropRecord *arg0, DoorRecord *arg1);
Gfx                 *chrobjRenderProp(PropRecord *arg0, Gfx *arg1, s32 arg2);

f32                  chrobjFogVisRangeRelated(PropRecord *prop, f32 size);
s32                  sub_GAME_7F054A64(PropRecord *prop, bbox2d *bbox);

// note: rgba to rgb
void                 sub_GAME_7F040384(rgba_s32 *arg0, s32 arg1, rgba_f32 *arg2);
void                 trigger_remote_mine_detonation(void);

void                 objDetach(PropRecord *prop);
void                 objFreeEmbedmentOrProjectile(PropRecord *);
bool                 alarmIsActive(void);
void                 init_trigger_toxic_gas_effect(coord3d *source);
void                 chrSetWeaponFlag4(ChrRecord *chr, GUNHAND hand);
void                 door7F053B10(DoorRecord *door);
void                 doorActivatePortal(DoorRecord *door);
void                 door7F052B00(DoorRecord *door);
s32                  sub_GAME_7F0539B8(f32 vol);
void                 monitorSetImageByNum(MonitorRecord *mon, s32 monAnimID);
void                 propweaponSetDual(WeaponObjRecord *leftweapon, WeaponObjRecord *rightweapon);
f32                  countdownTimerGetValue(void);
bool                 countdownTimerIsRunning(void);
void                 countdownTimerSetRunning(bool enable);
void                 countdownTimerSetValue(f32 time);
void                 countdownTimerSetVisible(int clocklockbits, bool unset);
void sub_GAME_7F04088C(ObjectRecord *baseobj, struct coord3d *pad, Mtxf *matrix, StandTile *stan, struct coord3d *pos2);
void sub_GAME_7F040BA0(ObjectRecord *obj, struct coord3d *pos, Mtxf *arg2, StandTile *stan2, struct coord3d *pos2);
bool                 chrEquipWeapon(WeaponObjRecord *wep, ChrRecord *chr);
INV_ITEM_TYPE        collect_or_interact_object(PropRecord *prop, bool showstring);
INV_ITEM_TYPE        propobjInteract(PropRecord *prop);
s32                  objGetDestroyedLevel(ObjectRecord *obj);
void                 doorActivateWrapper(PropRecord *prop);
bool                 objIsHealthy(ObjectRecord *self);
KeyRecord        *weaponFindThrown(s32 ID);
bool                 check_if_toxic_gas_activated(void);
HatRecord           *hatCreate(bool musthaveprop, bool musthavemodel, ModelFileHeader *modeldef);
PropRecord*          objInitWithAutoModel(ObjectRecord* obj);
PropRecord* objInitWithModelDef(ObjectRecord* object, ModelFileHeader* header);
Embedment           *embedmentAllocate(void);
void objDetach(PropRecord *prop);
void sub_GAME_7F043650(struct WeaponObjRecord *arg0);
s32 chrobjTestPolygonsTouchingOrOverlap2D(struct rect4f *arg0, s32 arg1, struct rect4f *arg2, s32 arg3);
s32 chrobjTestPointPolygonCollision(struct coord3d *arg0, f32 arg1, struct rect4f *arg2, s32 arg3);
void maybe_detonate_object_and_its_children(PropRecord *arg0, f32 arg1, struct coord3d *arg2, s32 arg3, s32 owner);
struct ModelRoData_BoundingBoxRecord* chrobjGetBboxFromObjectRecord(ObjectRecord *arg0);
void deactivate_alarm_sound_effect(void);
s32 sub_GAME_7F03F598(coord3d* pos, f32 arg1, BoundPadRecord *boundpads);
void sub_GAME_7F0A1DA0(f32*, f32*, f32*, f32*, f32, f32, f32, f32, f32, f32);
void sub_GAME_7F03F90C(Model *model, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
s32 sub_GAME_7F0448A8(struct PropRecord *arg0);
PropRecord* sub_GAME_7F051DD8(struct ObjectRecord* arg0, ModelFileHeader* arg1);
void sub_GAME_7F052030(WeaponObjRecord* arg0, ChrRecord* arg1);
void drop_inventory(void);
void sub_GAME_7F056690(void);

#endif
