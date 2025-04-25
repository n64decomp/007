#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include <ultra64.h>
#include <bondgame.h>
#include <bondconstants.h>


#define TABS_LEFT_EDGE 390.0f
#define TABS_RIGHT_EDGE 411

#define NEXTTAB_CURSOR_HPOS 399.0f
#define NEXTTAB_CURSOR_VPOS 144.0f

#define STARTTAB_TAB_TOP 40.0f
#define STARTTAB_TEXT_TOP 51
//#define STARTTAB_TEXT_HALF 84
#define STARTTAB_TEXT_HALF (STARTTAB_TEXT_TOP + ((STARTTAB_TEXT_BOTTOM-STARTTAB_TEXT_TOP)/2))
#define STARTTAB_TEXT_BOTTOM 117
#define STARTTAB_TAB_BOTTOM 130.5f

#define NEXTTAB_TAB_TOP 130.5f
#define NEXTTAB_TEXT_TOP 144
//#define NEXTTAB_TEXT_HALF 177
#define NEXTTAB_TEXT_HALF (NEXTTAB_TEXT_TOP + ((NEXTTAB_TEXT_BOTTOM-NEXTTAB_TEXT_TOP)/2))
#define NEXTTAB_TEXT_BOTTOM 210
#define NEXTTAB_TAB_BOTTOM 223.0f

#define PREVTAB_TAB_TOP 223.0f
#define PREVTAB_TEXT_TOP 236
//#define PREVTAB_TEXT_HALF 269
#define PREVTAB_TEXT_HALF (PREVTAB_TEXT_TOP + ((PREVTAB_TEXT_BOTTOM-PREVTAB_TEXT_TOP)/2))
#define PREVTAB_TEXT_BOTTOM 302
#define PREVTAB_TAB_BOTTOM 315.0f



struct legal_screen_text {
    s32 h_pos;
    s32 v_pos;
    s32 halign;
    s32 valign;
    u16 txtID;
    u16 anonymous_5;
};

struct mission_folder_setup {
    void * string_ptr;
    u16 folder_text_preset;
    u16 icon_text_preset;
    int stage_id;
    int unknown;
    int type;
    int mission_num;
    void * briefing_name_ptr;
};

struct MP_game_length_settings {
    u16 text_preset;
    u16 padding;
    int time;
    int points;
};

struct mp_stage_playercount {
    u16 stage;
    u8 min;
    u8 max;
};

struct mp_stage_setup {
    u16 folder_text_preset;
    u16 select_screen_text_preset;
    s32 photo;
    s32 stage_id;
    s32 unlock_after;
    s32 min_player;
    s32 max_player;
};

struct MP_selectable_chars {
    u16 text_preset;
    u8 gender;
    u8 select_photo;
    short body;
    short head;
    float pov;
};

struct MP_handicap_menu {
    u16 text_preset;
    u16 padding;
    float damage_modifier;
};

struct MP_controller_configuration_menu {
    u16 text_preset;
    //char field_1;
    u8 field_2;
    u8 field_3;
};

struct MP_sight_aim_settings {
    u16 anonymous_0;
    u8 sight;
    u8 autoaim;
};

struct intro_char {
    enum BODIES body;
    enum HEADS head;
    short text1;
    short text2;
    short text3;
    short RESERVED;
    int flag;
};

struct intro_animation {
    int animID;
    float startframeoffset;
    float playback_speed;
    int camera_preset;
};

struct solo_target_times {
    u16 agent_time;
    u16 secret_agent_time;
    u16 OO_agent_time;
};



extern f32 flt_CODE_bss_800695A0;
//CODE.bss:800695A4
extern f32 flt_CODE_bss_800695A4;
//CODE.bss:800695A8
extern f32 flt_CODE_bss_800695A8;
//CODE.bss:800695AC
extern f32 flt_CODE_bss_800695AC;
//CODE.bss:800695B0
extern f32 flt_CODE_bss_800695B0;
//CODE.bss:800695B4
extern f32 flt_CODE_bss_800695B4;
//CODE.bss:800695B8
extern f32 flt_CODE_bss_800695B8;
//CODE.bss:800695BC
extern f32 flt_CODE_bss_800695BC;
//CODE.bss:800695C0
extern f32 flt_CODE_bss_800695C0;
//CODE.bss:800695C4                     .align 3
//CODE.bss:800695C8
extern struct coord3d flt_CODE_bss_800695C8;
//CODE.bss:800695D4                     .align 3
//CODE.bss:800695D8
extern struct coord3d flt_CODE_bss_800695D8;

//CODE.bss:800695E4
extern s32 bss_800695E4;

//CODE.bss:800695E8
extern struct coord3d flt_CODE_bss_800695E8;

//CODE.bss:800695F4                     .align 3
//CODE.bss:800695F8
extern struct coord3d flt_CODE_bss_800695F8;
//CODE.bss:80069604                     .align 3
//CODE.bss:80069608
extern struct coord3d flt_CODE_bss_80069608;

//CODE.bss:80069614
extern f32 ninLogoRotRate;
//CODE.bss:80069618
extern f32 ninLogoScale;
//CODE.bss:80069620
extern coord3d dword_CODE_bss_80069620[0x4];

//CODE.bss:80069650
extern u8 cheat_available[];

//CODE.bss:800696A0
extern u8 g_CheatActivated[];


//CODE.bss:800696F0
extern s32 array_favweapon[4][2];
//CODE.bss:80069710
extern s32 mp_char_cur_select_player[4];

//CODE.bss:80069720
extern s32 mp_char_prev_select_player[4];

//CODE.bss:80069730
extern s32 dword_CODE_bss_80069730[4];

//CODE.bss:80069740
extern s32 player_has_selected_char[];
//CODE.bss:80069750
extern s32 size_mp_select_image_player[];
//CODE.bss:80069760
extern s32 player_handicap[];
//CODE.bss:80069770
extern char* g_textPtrTAB1;
//CODE.bss:80069774
extern char* g_textPtrTAB2;
//CODE.bss:80069778
extern char* g_textPtrTAB3;
//CODE.bss:8006977C
extern s32 current_mp_stage_highlighted;
//CODE.bss:80069780
extern s32 dword_CODE_bss_80069780;
//CODE.bss:80069784
extern s32 mission_difficulty_highlighted;
//CODE.bss:80069788
extern s32 teamsize;
//CODE.bss:80069790
extern s32 g_NewCheatUnlocked;
//CODE.bss:80069794
extern s32 highlight_enemy_reaction;
//CODE.bss:80069798
extern s32 highlight_enemy_health;
//CODE.bss:8006979C
extern s32 highlight_enemy_accuracy;
//CODE.bss:800697A0
extern s32 highlight_enemy_damage;

//CODE.bss:800697A4                     .align 3

//CODE.bss:800697A8
extern s32 player_handicap[];
//CODE.bss:800697B8
extern s32 controlstyle_player[];


//CODE.bss:800697C8
extern s32 highlight_players;
//CODE.bss:800697CC
extern s32 highlight_scenario;
//CODE.bss:800697D0
extern s32 highlight_gameselect;
//CODE.bss:800697D4
extern s32 highlight_gamelength;
//CODE.bss:800697D8
extern s32 highlight_character;
//CODE.bss:800697DC
extern s32 highlight_weaponselect;
//CODE.bss:800697E0
extern s32 highlight_health;
//CODE.bss:800697E4
extern s32 highlight_controlstyle;
//CODE.bss:800697E8
extern s32 highlight_aimadjustment;
//CODE.bss:800697EC                     .align 4
/*
CODE.bss:800697F0     dword_CODE_bss_800697F0:.space 0x130
*/

extern MENU current_menu;
extern MENU menu_update;
extern MENU maybe_prev_menu;
extern s32 g_MenuTimer;
extern s32 tab_start_selected;
extern s32 tab_next_selected;
extern s32 tab_prev_selected;
extern s32 tab_start_highlight;
extern s32 tab_next_highlight;
extern s32 tab_prev_highlight;

extern f32 tab2_first_x_coord;
extern f32 tab1_max_x_coord;
extern f32 tab2_bottom_y_coord;

extern s32 selected_folder_num;
extern s32 selected_folder_num_copy;
extern GAMEMODE gamemode;
extern s32 selected_stage;
extern s32 briefingpage;
extern DIFFICULTY selected_difficulty;
extern s32 g_AppendCheatSinglePlayer;
extern s32 g_AppendCheatMultiPlayer;
extern f32 cursor_h_pos;
extern f32 cursor_v_pos;
extern s32 final_menu_briefing_page;
extern s32 current_menu_briefing_page;
extern s32 folder_selection_screen_option_icon;
extern s32 folder_selected_for_deletion;
extern s32 folder_selected_for_deletion_choice;
extern s32 mission_failed_or_aborted;
extern s32 g_isBondKIA;
extern s32 is_first_time_on_legal_screen;
extern s32 is_first_time_on_main_menu;
extern s32 prev_keypresses;
extern s32 dword_ge_logo_bool;
extern s32 maybe_is_in_menu;
extern s32 screen_size;
extern s32 spectrum_related_flag;
extern s32 is_emulating_spectrum;
extern s32 is_cheat_menu_available;
extern u8 * ptr_logo_and_walletbond_DL;
extern s32 ptr_menu_videobuffer;
extern  Model * walletinst[];
extern Lights1 gelogolight;
extern Lights1 ninlogolight;

extern f32 slider_007_mode_reaction;
extern f32 slider_007_mode_health;
extern f32 slider_007_mode_damage;
extern f32 slider_007_mode_accuracy;


extern struct mission_folder_setup mission_folder_setup_entries[];

extern s32 selected_num_players;
extern s32 player_char[];
extern s32 MP_stage_selected;
extern s32 game_length;
extern s32 aim_sight_adjustment;
extern s32 scenario;
extern s32 unlock_stage_select;
extern s32 unlock_game_length;
extern s32 unlock_chars;
extern s32 unlock_weapon_select;
extern s32 unlock_handicap;
extern s32 unlock_control_style;
extern s32 unlock_aim_sight;
extern s16 solo_target_time_array[20][3];

extern s32 intro_character_index;
extern u32 randomly_selected_intro_animation;
extern u32 intro_animation_count;
extern struct Model *cast_model;
extern struct Model *cast_model_weapon;
extern u32 full_actor_intro;

void frontChangeMenu(MENU menu, s32 reload);
s32 get_selected_num_players(void);
void do_extended_cast_display(s32 flag);
MPSCENARIOS get_scenario(void);
f32 get_player_mp_handicap(int player);
f32 get_player_mp_char_height(int player);
int get_mp_timelimit(void);
int get_mp_pointlimit(void);
void reset_mp_options_for_scenario(MPSCENARIOS scenarioid);
void copy_aim_settings_to_playerdata(void);
void menu_init(void);
Gfx * menu_jump_constructor_handler(Gfx *DL);
void unlock_all_mp_chars(void);
u8 get_player_mp_char_gender(int player);
s32 pull_and_display_text_for_folder_a0(s32 arg0);

#endif
