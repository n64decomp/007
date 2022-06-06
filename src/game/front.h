#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include <ultra64.h>
#include <bondgame.h>
#include <bondconstants.h>

struct legal_screen_text {
    s32 h_pos;
    s32 v_pos;
    s32 flag;
    s32 flag2;
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
    s16 select_screen_text_preset;
    s32 photo;
    s32 stage_id;
    s32 unlock_after;
    s32 min_player;
    s32 max_player;
};

struct MP_selectable_chars {
    short text_preset;
    char gender;
    char select_photo;
    short body;
    short head;
    float pov;
};

struct MP_handicap_menu {
    short text_preset;
    short padding;
    float damage_modifier;
};

struct MP_controller_configuration_menu {
    u16 anonymous_0;
    //char field_1;
    char field_2;
    char field_3;
};

struct MP_sight_aim_settings {
    u16 anonymous_0;
    u8 sight;
    u8 autoaim;
};

struct intro_char {
    int body;
    int head;
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
extern f32 flt_CODE_bss_800695C8;
//CODE.bss:800695CC
extern f32 flt_CODE_bss_800695CC;
//CODE.bss:800695D0
extern f32 flt_CODE_bss_800695D0;
//CODE.bss:800695D4                     .align 3
//CODE.bss:800695D8
extern f32 flt_CODE_bss_800695D8;
//CODE.bss:800695DC
extern f32 flt_CODE_bss_800695DC;
//CODE.bss:800695E0
extern f32 flt_CODE_bss_800695E0;
//CODE.bss:800695E4
extern f32 flt_CODE_bss_800695E4;
//CODE.bss:800695E8
extern f32 flt_CODE_bss_800695E8;
//CODE.bss:800695EC
extern f32 flt_CODE_bss_800695EC;
//CODE.bss:800695F0
extern f32 flt_CODE_bss_800695F0;
//CODE.bss:800695F4                     .align 3
//CODE.bss:800695F8
extern f32 flt_CODE_bss_800695F8;
//CODE.bss:800695FC
extern f32 flt_CODE_bss_800695FC;
//CODE.bss:80069600
extern f32 flt_CODE_bss_80069600;
//CODE.bss:80069604                     .align 3
//CODE.bss:80069608
extern f32 flt_CODE_bss_80069608;
//CODE.bss:8006960C
extern f32 flt_CODE_bss_8006960C;
//CODE.bss:80069610
extern f32 flt_CODE_bss_80069610;
//CODE.bss:80069614
extern f32 flt_CODE_bss_80069614;
//CODE.bss:80069618
extern f32 flt_CODE_bss_80069618;
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
extern s32 has_selected_char_player1;
//CODE.bss:80069744
extern s32 has_selected_char_player2;
//CODE.bss:80069748
extern s32 has_selected_char_player3;
//CODE.bss:8006974C
extern s32 has_selected_char_player4;
//CODE.bss:80069750
extern s32 size_mp_select_image_player1;
//CODE.bss:80069754
extern s32 size_mp_select_image_player2;
//CODE.bss:80069758
extern s32 size_mp_select_image_player3;
//CODE.bss:8006975C
extern s32 size_mp_select_image_player4;
//CODE.bss:80069760
extern s32 handicap_player1;
//CODE.bss:80069764
extern s32 handicap_player2;
//CODE.bss:80069768
extern s32 handicap_player3;
//CODE.bss:8006976C
extern s32 handicap_player4;
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
extern s32 handicap_player1;
//CODE.bss:800697AC
extern s32 handicap_player2;
//CODE.bss:800697B0
extern s32 handicap_player3;
//CODE.bss:800697B4
extern s32 handicap_player4;
//CODE.bss:800697B8
extern u32 controlstyle_player[];


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
extern s32 menu_timer;
extern s32 tab_1_selected;
extern s32 tab_2_selected;
extern s32 tab_3_selected;
extern s32 tab_1_highlight;
extern s32 tab_2_highlight;
extern s32 tab_3_highlight;

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
extern s32 append_cheat_mp;
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
extern Gfx * ptr_logo_and_walletbond_DL;
extern s32 ptr_menu_videobuffer;
extern struct object_standard * ptr_folder_object_instance;
extern s32 set0_never_used;
extern s32 set0_never_used_0;
extern s32 D_8002A968;
extern s32 dword_D_8002A96C;
extern struct rgba_u8 RGBA_8002A970;
extern struct rgba_u8 RGBA_8002A974;
extern struct rgba_u8 RGBA_8002A978;
extern struct rgba_u8 RGBA_8002A97C;
extern struct rgba_u8 RGBA_8002A980;
extern struct rgba_u8 RGBA_8002A984;
extern struct rgba_u8 RGBA_8002A988;
extern struct rgba_u8 RGBA_8002A98C;
extern u32 dword_D_8002A990;
extern u32 dword_D_8002A994;
extern u32 dword_D_8002A998;
extern u32 dword_D_8002A99C;
extern f32 slider_007_mode_reaction;
extern f32 slider_007_mode_health;
extern f32 slider_007_mode_damage;
extern f32 slider_007_mode_accuracy;


extern struct mission_folder_setup mission_folder_setup_entries[];

extern s32 selected_num_players;
extern s32 player_1_char;
extern s32 player_2_char;
extern s32 player_3_char;
extern s32 player_4_char;
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

extern u32 intro_character_index;
extern u32 randomly_selected_intro_animation;
extern u32 intro_animation_count;
extern u32 objinstance;
extern u32 ptrobjinstance;
extern u32 full_actor_intro;

void set_menu_to_mode(MENU menu, s32 mode);
s32 get_selected_num_players(void);
void do_extended_cast_display(s32 flag);
MPSCENARIOS get_scenario(void);
f32 get_player_mp_handicap(int player);
f32 get_player_mp_char_height(int player);
int get_mp_timelimit(void);
int get_mp_pointlimit(void);
void reset_mp_options_for_scenario(MPSCENARIOS scenarioid);
void copy_aim_settings_to_playerdata(void);
void menu_init();
Gfx * menu_jump_constructor_handler(Gfx *DL);
void unlock_all_mp_chars(void);
u8 get_player_mp_char_gender(int player);
s32 pull_and_display_text_for_folder_a0(s32 arg0);

#endif
