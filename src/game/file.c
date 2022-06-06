#include <ultra64.h>
#include "file.h"
#include "file2.h"
#include "front.h"

/* EEPROM masks for in-game settings */
#define OPTION_INVERTLOOK    0x0001
#define OPTION_AUTOAIM       0x0002
#define OPTION_AIMCONTROL    0x0004
#define OPTION_SIGHTONSCREEN 0x0008
#define OPTION_LOOKAHEAD     0x0010
#define OPTION_DISPLAYAMMO   0x0020
#define OPTION_SCREENWIDE    0x0040
#define OPTION_SCREENRATIO   0x0080
#define OPTION_CONTROLTYPE   0x0700
#define OPTION_SCREENCINEMA  0x0800

#define DEFAULT_OPTIONS (OPTION_AUTOAIM | OPTION_SIGHTONSCREEN | OPTION_LOOKAHEAD | OPTION_DISPLAYAMMO)

// bss
//CODE.bss:80069920
//CODE.bss:80069980
//CODE.bss:800699E0
//CODE.bss:80069A40
//CODE.bss:80069AA0
//CODE.bss:80069B00
save_data saves[6];

//CODE.bss:80069B60
u32 dword_CODE_bss_80069B60;


//data
//D:8002C510
s32 save_selected_bond[] = {0,0,0,0};

//D:8002C520
save_data D_8002C520 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C580
// Default Save
save_data D_8002C580 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C5E0
save_data D_8002C5E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C640
smallSave blankSmallSave = {0, 0, 0x42};

//D:8002C660
save_data D_8002C660 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};

//D:8002C6C0
save_data D_8002C6C0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C720
save_data D_8002C720 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C780
save_data D_8002C780 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C7E0
save_data D_8002C7E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C840
save_data D_8002C840 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C8A0
save_data blank_eeprom = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



f32 get_007_reaction_speed(void)
{
    if (lvlGetSelectedDifficulty() == DIFFICULTY_007) {
        return slider_007_mode_reaction;
    }
    return 0.f;
}

f32 get_007_health_mod(void)
{
    if (lvlGetSelectedDifficulty() == DIFFICULTY_007) {
        return slider_007_mode_health;
    }
    return 1.f;
}

f32 get_007_damage_mod(void)
{
    if (lvlGetSelectedDifficulty() == DIFFICULTY_007) {
        return slider_007_mode_accuracy;
    }
    return 1.f;
}

f32 get_007_accuracy_mod(void)
{
    if (lvlGetSelectedDifficulty() == DIFFICULTY_007) {
        return slider_007_mode_damage;
    }
    return 1.f;
}

void end_of_mission_briefing(void)
{
    s16 var1;

    if ((-1 < briefingpage) && selected_difficulty != DIFFICULTY_007 && g_AppendCheatSinglePlayer == FALSE)
    {
        var1 = solo_target_time_array[mission_folder_setup_entries[briefingpage].mission_num][selected_difficulty];
        fileUnlockStageInFolderAtDifficulty(selected_folder_num, mission_folder_setup_entries[briefingpage].mission_num, selected_difficulty, getMissiontimer() / 0x3c);
        if ((getMissiontimer() / GAME_TICKRATE) <= var1)
        {
            if (!fileGetIsCheatUnlocked(fileGetSaveForFoldernum(selected_folder_num), mission_folder_setup_entries[briefingpage].mission_num))
            {
                sub_GAME_7F01E760(selected_folder_num, mission_folder_setup_entries[briefingpage].mission_num);
                g_NewCheatUnlocked = TRUE;
                return;
            }
        }
#ifdef VERSION_US
        g_NewCheatUnlocked = FALSE;
#endif
    }
}

void fileLoadSaveSettingsForSelectedFolder(int stage)
{
    if(stage){}
    fileLoadSettingsForFolder(selected_folder_num);
}

void deleteCurrentSelectedFolder(void)
{
  fileClearSavefileForFolder(selected_folder_num);
}

void copyCurrentEEPROMtoStack(void)
{
  fileCopySaveIfSelectedBondDifferent(selected_folder_num);
}

s32 getSelectedFolderBond(void)
{
  return fileGetBondForFolder(selected_folder_num);
}

void set_selected_folder_num(u32 foldernum)
{
  selected_folder_num = foldernum;
}

void set_selected_difficulty(DIFFICULTY difficulty)
{
    switch(difficulty)
    {
    case DIFFICULTY_AGENT:
    default:
        selected_difficulty = DIFFICULTY_AGENT;
        return;
    case DIFFICULTY_SECRET:
        selected_difficulty = DIFFICULTY_SECRET;
        return;
    case DIFFICULTY_00:
        selected_difficulty = DIFFICULTY_00;
        return;
    case DIFFICULTY_007:
        selected_difficulty = DIFFICULTY_007;
        return;
    }
}

void set_solo_and_ptr_briefing(LEVELID stage)
{
    gamemode = GAMEMODE_SOLO;
    selected_stage = stage;
    briefingpage = pull_and_display_text_for_folder_a0(stage);
}

void sub_GAME_7F01D61C(struct save_file *savefile)
{
    fileCopySave(selected_folder_num,savefile);
}



//this feels fake, generated with a permuter session i forgot was running
void set_selected_foldernum_and_copy_demo_eeprom(struct save_file *eeprom)
{
  int new_var;
  long long new_var2;
  new_var2 = (long long) 0x64;
  new_var = new_var2;
  selected_folder_num_copy = (s32) selected_folder_num;
  selected_folder_num = new_var;
  fileCopyDemoSaveToRamRomSave(new_var, eeprom);
}


void store_favorite_weapon_current_player(u32 right,u32 left)
{
  u32 playerNum;

  playerNum = get_cur_playernum();
  array_favweapon[playerNum][GUNRIGHT] = right;
  array_favweapon[playerNum][GUNLEFT] = left;
}

