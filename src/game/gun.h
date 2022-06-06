#ifndef _BONDWALK_H_
#define _BONDWALK_H_
#include <ultra64.h>
#include "chrobjdata.h"
#include <bondconstants.h>
#include <bondtypes.h>

typedef struct WeaponStats
{
    /**
     * Distance of gun flash from the end of the barrel.
     */
    f32 MuzzleFlashExtension;

    /**
     * On screen gun position, X.
     */
    f32 PosX;

    /**
     * On screen gun position, Y.
     */
    f32 PosY;

    /**
     * On screen gun position, Z.
     */
    f32 PosZ;

    /**
     * The amount of play the guns are given when you move forward/back.
     */
    f32 PlayX;

    /**
     * The amount of play the guns are given when you move side
     * to side.
     */
    f32 PlayY;

    /**
     * The amount of play the guns are given when you move up or down.
     */
    f32 PlayZ;

    /**
     * Ammo type, and what ammo img is shown.
     */
    s32 AmmoType;

    /**
     * Number of rounds before needing to reload.
     */
    s16 MagSize;

    /**
     * Time between automatic shots. -1 (0xFF) for disabled.
     * For reference, RC-P90=0x2, and KF7=0x3.
     * (is this an enum?)
     */
    u8 AutomaticFiringRate;

    /**
     * Time between manual shots.
     * For reference, KF7=0, while rocket launcher = 0x14.
     */
    s8 SingleFiringRate;

    /**
     * How many objects the bullet goes through.
     */
    u8 ObjectsShootThrough;

    /**
     * Sound trigger rate.
     */
    u8 SoundTriggerRate;

    /**
     * Sound effect played when gun is shot. There are 261 sound effects, or 0 - 105h.
     */
    u16 Sound;

    /**
     * Comment from long ago:
     * Location of address that displays the bullet shells flying from the guns, and runs
     * the ping sound of the casings hitting the ground. This value is either 00000000 for
     * no bullet casings (laser, knife, grenade, so on) or 8003CB60, the location of pointers
     * that point to code possibly, I haven't explored the area a lot near that address
     * (8003CB60)
     */
    struct ModelFileHeader * ptr_cartridge_struct;

    /**
     * Amount of destruction or power each bullet packs.
     * For reference, KF7=1.0, while golden gun = 100.0.
     */
    f32 DestructionAmount;

    /**
     * Amount of inaccuracy the gun has.
     * For reference, KF7=10.0, sniper rifle = 0.0.
     */
    f32 Inaccuracy;

    /**
     * Amount of zoom the gun has. Just setting this value doesn't give the option of 
     * zooming in and out, that is somewhere else.
     * For reference, KF7=30.0, sniper rifle = 15.0.
     */
    f32 Zoom;

    /**
     * Speed of red cross-hair.
     */
    f32 CrosshairSpeed;

    /**
     * Weapon Aim/Lock-On Speed.
     */
    f32 AimLockSpeed;

    /**
     * Hand stabilization. A low value will keep the hands still while a high value will
     * cause bonds arms to twirl around in circles and turn every which way.
     */
    f32 Sway;

    /**
     * Recoil speed.
     */
    s32 RecoilSpeed;

    /**
     * How far back bonds hands pull back when the gun is fired.
     */
    f32 RecoilBack;

    /**
     * Amount of recoil the gun has.
     */
    f32 RecoilUp;

    /**
     * How far back the bolt slides when the gun is fired.
     */
    f32 BoltRecoilBack;

    /**
     * The minimum amount of sound an enemy can hear from this weapon.
     */
    f32 LoudnessMin;

    /**
     * The maximum amount of sound an enemy can hear from this weapon.
     */
    f32 LoudnessMax;

    /**
     * Amount of noise increased with each shot fired.
     * ("Noise" is the value used to determine if a guard should be alerted).
     */
    f32 NoiseIncreasePerShot;

    /**
     * Unknown (field 0x60).
     */
    f32 field_60;

    /**
     * Unknown (field 0x64).
     */
    f32 field_64;

    /**
     * Force of impact.
     */
    f32 ForceOfImpact;

    /**
     * 
     */
    u32 BitFlags;
} WeaponStats;

typedef struct GunModelFileRecord
{
  ModelFileHeader * item_header;
  char * item_file_name;
  s32 has_no_model;
  WeaponStats * item_weapon_stats;
  u16 upper_watch_text;
  u16 lower_watch_text;
  f32 watch_pos_x;
  f32 watch_pos_y;
  f32 watch_pos_z;
  f32 x_rotation;
  f32 y_rotation;
  u16 weapon_of_choice_text;
  u16 watch_equipment_text;
  f32 equip_watch_x;
  f32 equip_watch_y;
  f32 equip_watch_z;
} GunModelFileRecord;

typedef struct CartridgeModelFileRecord {
    ModelFileHeader* header;
    char * text;
} CartridgeModelFileRecord;

#if defined(VERSION_EU)
extern char dword_CODE_bss_80075DC8[20][104];
#else
extern char dword_CODE_bss_80075DC8[20][160];
#endif

f32 bondwalkItemGetForceOfImpact(ITEM_IDS item);

u32 bondwalkItemCheckBitflags(ITEM_IDS item, u32 mask);

void bondwalkFireBothHands(void);

f32 sub_GAME_7F0649AC(s32 param_1);

f32 sub_GAME_7F05DCB8(GUNHAND hand);

u16 *get_ptr_short_watch_text_for_item(ITEM_IDS item);

s32 bondwalkItemHasAmmo(ITEM_IDS item);

void display_in_game_crosshair(s32 *gdl);

WeaponStats *get_ptr_item_statistics(ITEM_IDS item);

s32 getCurrentPlayerWeaponId(GUNHAND hand);
s32 currentPlayerEquipWeaponWrapper(GUNHAND hand, s32 next_weapon);
void sub_GAME_7F068E6C(void);
void attempt_reload_item_in_hand(GUNHAND hand);
void set_max_ammo_for_cur_player(void);
void set_unset_ammo_on_screen_setting(s32 flags, s32 isset);
void set_unset_bitflags(s32 bitflags, s32 flag);

s32 get_max_ammo_for_type(s32);
void give_cur_player_ammo(s32, s32);
s8 bondwalkItemGetAutomaticFiringRate(ITEM_IDS item);
void inc_cur_civilian_casualties(void);
void increment_num_kills_display_text_in_MP();
f32 bondwalkItemGetDestructionAmount(ITEM_IDS item);
u16 bondwalkItemGetSound(ITEM_IDS item);
u8 bondwalkItemGetSoundTriggerRate(ITEM_IDS item);

void recall_joy2_hits_edit_detail_edit_flag(s32 arg0, u8 *arg1, s32 arg2);
void recall_joy2_hits_edit_flag(s32 arg0, coord3d *arg1, s32 arg2);
void sub_GAME_7F05EB0C(ObjectRecord *arg0, coord3d *arg1,  StandTile *arg2, Mtxf *arg3, coord3d *arg4, Mtxf *arg5,  PropRecord *arg6);
void sub_GAME_7F061948(struct ChrRecord_f180 *arg0, ITEM_IDS item, coord3d *arg2, coord3d *arg3);
void sub_GAME_7F068190(coord3d *arg0, coord3d *arg1);

void inc_curplayer_hitcount_with_weapon(ITEM_IDS item, SHOT_REGISTER shot_register);
s8 get_hands_firing_status(GUNHAND hand);
void gunFireTankShell(s32 hand);
void         remove_item_in_hand(GUNHAND hand);
void         currentPlayerUnEquipWeaponWrapper(GUNHAND hand, s32 weapid);
s32          currentPlayerGetAmmoCount(AMMOTYPE ammotype);
s32          get_civilian_casualties(void);
s32 Gun_hand_without_item(enum GUNHAND arg0);

void bgunCalculateBlend(s32 arg0);
void gunSetBondWeaponSway(f32 arg0, f32 arg1, f32 speed_verta, f32 speed_theta);
void gunSetOffsetRelated(f32 param_1);
#endif
