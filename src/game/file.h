#ifndef _FILE_H_
#define _FILE_H_
#include <ultra64.h>

#include <bondconstants.h>

typedef struct save_data
{
  s32 chksum1;
  s32 chksum2;
  u8 completion_bitflags;
  u8 flag_007;
  u8 music_vol;
  u8 sfx_vol;
  u16 options;
  u8 unlocked_cheats_1;
  u8 unlocked_cheats_2;
  u8 unlocked_cheats_3;
  char padding;
  u8 times[(SP_LEVEL_MAX-1) * 4];
} save_data;

// Used by fileValidateSaves
typedef struct smallSave
{
    int chksum1;
    int chksum2;
    u8 unk[24];
} smallSave;

extern save_data saves[6];

extern s32 save_selected_bond[];

f32 get_007_reaction_speed(void);
f32 get_007_health_mod(void);
f32 get_007_damage_mod(void);
f32 get_007_accuracy_mod(void);
void end_of_mission_briefing(void);
void fileLoadSaveSettingsForSelectedFolder(int stage);
void deleteCurrentSelectedFolder(void);
void fileUpdateBondInCurrentFolder(void);
s32 fileGetBondForCurrentFolder(void);
void fileSetCurrentFolder(u32 foldernum);
void set_selected_difficulty(DIFFICULTY difficulty);
void set_solo_and_ptr_briefing(LEVELID stage);
void sub_GAME_7F01D61C(struct save_data *savefile);
void set_selected_foldernum_and_copy_demo_eeprom(struct save_data *eeprom);
void store_favorite_weapon_current_player(u32 right,u32 left);

#endif
