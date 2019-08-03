#ifndef _BONDVIEW_H_
#define _BONDVIEW_H_
#include "ultra64.h"
#include "game/cheat_buttons_objectrelated.h"

struct weapon_stats
{
  f32 field_0;
  f32 pos_x;
  f32 pos_y;
  f32 pos_z;
  f32 field_10;
  f32 field_14;
  f32 field_18;
  s32 ammotype;
  s16 mag_size;
  u8 automatic_firing_rate;
  s8 single_firing_rate;
  u8 objects_shoot_through;
  u8 sound_trigger_rate;
  s16 sound;
  struct Gitemheader * ptr_cartridge_struct;
  f32 destruction_amount;
  f32 inaccuracy;
  f32 zoom;
  f32 field_38;
  f32 field_3C;
  f32 sway;
  s32 recoilspeed;
  f32 recoil_back;
  f32 recoil_up;
  f32 bolt_recoil_back;
  f32 loudness;
  f32 loudness2;
  f32 field_5C;
  f32 field_60;
  f32 field_64;
  f32 field_68;
  u32 bitflags;
};

struct gitem_data_struct
{
  struct Gitemheader * item_header;
  char * item_file_name;
  s32 has_no_model;
  struct weapon_stats * item_weapon_stats;
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
};

struct ejected_cart {
    struct Gitemheader * header;
    char * text;
};

#endif
