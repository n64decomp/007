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

typedef struct AmmoStats {
    /**
     * The maximum amount of ammo.
     */
    u32 MaxAmmo;

    /**
     * Unknown (field 0x04).
     */
    u16 field_04;

    /**
     * Unknown (field 0x06).
     */
    u16 field_06;

    /**
     * Unknown (field 0x08).
     */
    u16 field_08;

    /**
     * Unknown (field 0x0A).
     */
    u16 field_0A;
} AmmoStats;

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

typedef struct CasingRecord {
    f32 floor_y_pos;
    coord3d pos;
    coord3d vel;
#if VERSION_EU
    f32 unk1C[3][3];
    f32 unk40[3][3];
#else
    Mtxf unk1C;
    Mtxf unk5C;
#endif
    ModelFileHeader *header;
} CasingRecord;

typedef struct CartridgeModelFileRecord {
    ModelFileHeader* header;
    char * text;
} CartridgeModelFileRecord;

struct RicochetSoundsSmall {
    u16 arr[20];
};

struct PunchSounds {
    u16 arr[3];
};

struct BulletFleshSounds {
    u16 arr[2];
};

struct LaserRichochetSounds {
    u16 arr[2];
};

struct RicochetSoundsLarge {
    u16 arr[36];
};

struct EarWhistleSounds {
    s16 arr[5];
};

extern CasingRecord g_Casings[20];

f32 bondwalkItemGetForceOfImpact(ITEM_IDS item);

u32 bondwalkItemCheckBitflags(ITEM_IDS item, u32 mask);

void bondwalkFireBothHands(void);

f32 sub_GAME_7F0649AC(s32 param_1);

f32 sub_GAME_7F05DCB8(GUNHAND hand);

u16 *get_ptr_short_watch_text_for_item(ITEM_IDS item);

s32 bondwalkItemHasAmmo(ITEM_IDS item);

void gunDrawSight(s32 *gdl);

WeaponStats *get_ptr_item_statistics(ITEM_IDS item);

ITEM_IDS getCurrentPlayerWeaponId(GUNHAND hand);
s32 currentPlayerEquipWeaponWrapper(GUNHAND hand, s32 next_weapon);
void update_bullet_casings(void);
void attempt_reload_item_in_hand(GUNHAND hand);
void set_max_ammo_for_cur_player(void);
void gunSetGunAmmoVisible(s32 reason, s32 enable);
void gunSetSightVisible(s32 reason, s32 visible);

s32 get_max_ammo_for_type(s32);
void give_cur_player_ammo(s32, s32);
s8 bondwalkItemGetAutomaticFiringRate(ITEM_IDS item);
void inc_cur_civilian_casualties(void);
void increment_num_kills_display_text_in_MP();
f32 bondwalkItemGetDestructionAmount(ITEM_IDS item);
u16 bondwalkItemGetSound(ITEM_IDS item);
u8 bondwalkItemGetSoundTriggerRate(ITEM_IDS item);

void recall_joy2_hits_edit_detail_edit_flag(enum ITEM_IDS item, PropRecord* prop, s32 texture_index);
void recall_joy2_hits_edit_flag(enum ITEM_IDS item, coord3d* arg1, s32 texture_index);
void sub_GAME_7F05EB0C(ObjectRecord *arg0, coord3d *arg1,  StandTile *arg2, Mtxf *arg3, coord3d *arg4, Mtxf *arg5,  PropRecord *arg6);
void CapBeamLengthAndDecideIfRendered(struct ChrRecord_f180 *arg0, ITEM_IDS item, coord3d *arg2, coord3d *arg3);
void sub_GAME_7F068190(coord3d *arg0, coord3d *arg1);

void inc_curplayer_hitcount_with_weapon(ITEM_IDS item, SHOT_REGISTER shot_register);
s8 get_hands_firing_status(GUNHAND hand);
void gunFireTankShell(s32 hand);
void         remove_item_in_hand(GUNHAND hand);
void currentPlayerUnEquipWeaponWrapper(enum GUNHAND hand, enum ITEM_IDS weapid);
s32          currentPlayerGetAmmoCount(AMMOTYPE ammotype);
s32          get_civilian_casualties(void);
s32 Gun_hand_without_item(enum GUNHAND arg0);
void sub_GAME_7F05FB00(enum GUNHAND hand);

void bgunCalculateBlend(enum GUNHAND handnum);
void gunSetBondWeaponSway(f32 arg0, f32 arg1, f32 speed_verta, f32 speed_theta);
void gunSetOffsetRelated(f32 param_1);

s32 get_curplayer_shot_register(SHOT_REGISTER shot_register);
void get_bullet_angle(f32* horizontal_angle, f32* vertical_angle);

ITEM_IDS get_item_in_hand_or_watch_menu(GUNHAND hand);
void draw_item_in_hand(GUNHAND hand, s32 next_weapon);
void sub_GAME_7F05DAE4(GUNHAND hand);
void sub_GAME_7F067F58(f32 turn_x, f32 turn_y, f32 max_aim_lock_speed);
s32 get_ammo_count_for_weapon(ITEM_IDS weapon);
void add_ammo_to_weapon(ITEM_IDS weapon, s32 ammo);
s32 get_ammo_in_hands_magazine(GUNHAND hand);
void autoadvance_on_deplete_all_ammo(void);
f32 getCurrentPlayerNoise(GUNHAND hand);
void camera_sniper_zoom_in(f32 zoom);
void camera_sniper_zoom_out(f32 zoom);
f32 get_item_in_hand_zoom(void);
void advance_through_inventory(void);
void backstep_through_inventory(void);
void gunSetAimType(s32 param_1);
void sub_GAME_7F067FBC(f32 turn_x, f32 turn_y);
void gunTickGameplay(s32 arg0);

Gfx *gunDrawHudString(Gfx *gdl, s8 *text, s32 x, s32 halign, s32 y, s32 valign, bool glow);
Gfx *gunDrawHudInteger(Gfx *gdl, s32 value, s32 x, s32 halign, s32 y, s32 valign, bool glow);

#endif
