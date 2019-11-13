#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include "ultra64.h"
#include "bondgame.h"

struct legal_screen_text {
    int h_pos;
    int v_pos;
    int flag;
    int flag2;
    short txtID;
    short anonymous_5;
};

struct mission_folder_setup {
    void * string_ptr;
    short folder_text_preset;
    short icon_text_preset;
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
    short stage;
    char min;
    char max;
};

struct mp_stage_setup {
    short folder_text_preset;
    short select_screen_text_preset;
    int photo;
    int stage_id;
    int unlock_after;
    int min_player;
    int max_player;
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
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
};

struct MP_sight_aim_settings {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
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
//CODE.bss:8006961C                     .align 4
/*
CODE.bss:80069620     dword_CODE_bss_80069620:.space 0x30
CODE.bss:80069650                     .space 1
CODE.bss:80069651     cheat_available:.space 1
CODE.bss:80069652     CHEAT_AVAILABLE_INVINCIBLE:.space 1
CODE.bss:80069653     CHEAT_AVAILABLE_ALLGUNS:.space 1
CODE.bss:80069654                     .space 1
CODE.bss:80069655                     .space 2
CODE.bss:80069657     CHEAT_AVAILABLE_LINEMODE:.space 1
CODE.bss:80069658     CHEAT_AVAILABLE_2X_HEALTH:.space 1
CODE.bss:80069659     CHEAT_AVAILABLE_2X_ARMOR:.space 1
CODE.bss:8006965A     CHEAT_AVAILABLE_BOND_INVIS:.space 1
CODE.bss:8006965B     CHEAT_AVAILABLE_INFINITE_AMMO:.space 1
CODE.bss:8006965C     CHEAT_AVAILABLE_DK_MODE:.space 1
CODE.bss:8006965D     CHEAT_AVAILABLE_EXTRA_WEAPONS:.space 1
CODE.bss:8006965E     CHEAT_AVAILABLE_TINY_BOND:.space 1
CODE.bss:8006965F     CHEAT_AVAILABLE_PAINTBALL:.space 1
CODE.bss:80069660     CHEAT_AVAILABLE_10X_HEALTH:.space 1
CODE.bss:80069661     CHEAT_AVAILABLE_MAGNUM:.space 1
CODE.bss:80069662     CHEAT_AVAILABLE_LASER:.space 1
CODE.bss:80069663     CHEAT_AVAILABLE_GOLDENGUN:.space 1
CODE.bss:80069664     CHEAT_AVAILABLE_SILVERPP7:.space 1
CODE.bss:80069665     CHEAT_AVAILABLE_GOLDPP7:.space 1
CODE.bss:80069666     CHEAT_AVAILABLE_MP_INVINCIBILITY:.space 1
CODE.bss:80069667     CHEAT_AVAILABLE_NO_MP_RADAR:.space 1
CODE.bss:80069668     CHEAT_AVAILABLE_TURBO:.space 1
CODE.bss:80069669     CHEAT_AVAILABLE_DEBUG_MODE:.space 1
CODE.bss:8006966A     CHEAT_AVAILABLE_FAST_ANI:.space 1
CODE.bss:8006966B     CHEAT_AVAILABLE_SLOW_ANI:.space 1
CODE.bss:8006966C     CHEAT_AVAILABLE_ENMY_ROCKETS:.space 1
CODE.bss:8006966D     CHEAT_AVAILABLE_2X_ROCKET:.space 1
CODE.bss:8006966E     CHEAT_AVAILABLE_2X_GRENADE_LAUNCHER:.space 1
CODE.bss:8006966F     CHEAT_AVAILABLE_2X_RCP90:.space 1
CODE.bss:80069670     CHEAT_AVAILABLE_2X_THROWING_KNIVES:.space 1
CODE.bss:80069671     CHEAT_AVAILABLE_2X_HUNTING_KNIVES:.space 1
CODE.bss:80069672     CHEAT_AVAILABLE_2X_LASER:.space 2
CODE.bss:80069674                     .space 0x2C
*/
//CODE.bss:800696A0
extern u8 cheat_activated;
//CODE.bss:800696A1
extern u8 CHEAT_AVAILABLE_EXTRA_CHARS;
//CODE.bss:800696A2
extern u8 cheat_activated_1;
//CODE.bss:800696A3
extern u8 cheat_activated_2;
//CODE.bss:800696A4
extern u8 CHEAT_AVAILABLE_MAX_AMMO;
//CODE.bss:800696A5
extern u8 cheat_activated_4;
//CODE.bss:800696A6
extern u8 cheat_activated_5;
//CODE.bss:800696A7
extern u8 cheat_activated_6;
//CODE.bss:800696A8
extern u8 cheat_activated_7;
//CODE.bss:800696A9
extern u8 cheat_activated_8;
//CODE.bss:800696AA
extern u8 cheat_activated_9;
//CODE.bss:800696AB
extern u8 cheat_activated_10;
//CODE.bss:800696AC
extern u8 cheat_activated_11;
//CODE.bss:800696AD
extern u8 cheat_activated_12;
//CODE.bss:800696AE
extern u8 cheat_activated_13;
//CODE.bss:800696AF
extern u8 cheat_activated_14;
//CODE.bss:800696B0
extern u8 cheat_activated_15;
//CODE.bss:800696B1
extern u8 cheat_activated_16;
//CODE.bss:800696B2
extern u8 cheat_activated_17;
//CODE.bss:800696B3
extern u8 cheat_activated_18;
//CODE.bss:800696B4
extern u8 cheat_activated_19;
//CODE.bss:800696B5
extern u8 cheat_activated_20;
//CODE.bss:800696B6
extern u8 cheat_activated_21;
//CODE.bss:800696B7
extern u8 cheat_activated_22;
//CODE.bss:800696B8
extern u8 cheat_activated_23;
//CODE.bss:800696B9
extern u8 cheat_activated_24;
//CODE.bss:800696BA
extern u8 cheat_activated_25;
//CODE.bss:800696BB
extern u8 cheat_activated_26;
//CODE.bss:800696BC
extern u8 cheat_activated_27;
//CODE.bss:800696BD
extern u8 cheat_activated_28;
//CODE.bss:800696BE
extern u8 cheat_activated_29;
//CODE.bss:800696BF
extern u8 cheat_activated_30;
//CODE.bss:800696C0
extern u8 cheat_activated_31;
//CODE.bss:800696C1
extern u8 cheat_activated_32;
//CODE.bss:800696C2
extern u8 cheat_activated_33;
//CODE.bss:800696C3
extern u8 cheat_activated_34;
//CODE.bss:800696C4
extern u8 cheat_activated_35;
//CODE.bss:800696C5
extern u8 cheat_activated_36;
//CODE.bss:800696C6
extern u8 cheat_activated_37;
//CODE.bss:800696C7
extern u8 cheat_activated_38;
//CODE.bss:800696C8
extern u8 cheat_activated_39;
//CODE.bss:800696C9
extern u8 cheat_activated_40;
//CODE.bss:800696CA
extern u8 cheat_activated_41;
//CODE.bss:800696CB
extern u8 cheat_activated_42;
//CODE.bss:800696CC
extern u8 cheat_activated_43;
//CODE.bss:800696CD
extern u8 cheat_activated_44;
//CODE.bss:800696CE
extern u8 cheat_activated_45;
//CODE.bss:800696CF
extern u8 cheat_activated_46;
//CODE.bss:800696D0
extern u8 cheat_activated_47;
//CODE.bss:800696D1
extern u8 cheat_activated_48;
//CODE.bss:800696D2
extern u8 cheat_activated_49;
//CODE.bss:800696D3
extern u8 cheat_activated_50;
//CODE.bss:800696D4
extern u8 cheat_activated_51;
//CODE.bss:800696D5
extern u8 cheat_activated_52;
//CODE.bss:800696D6
extern u8 cheat_activated_53;
//CODE.bss:800696D7
extern u8 cheat_activated_54;
//CODE.bss:800696D8
extern u8 cheat_activated_55;
//CODE.bss:800696D9
extern u8 cheat_activated_56;
//CODE.bss:800696DA
extern u8 cheat_activated_57;
//CODE.bss:800696DB
extern u8 cheat_activated_58;
//CODE.bss:800696DC
extern u8 cheat_activated_59;
//CODE.bss:800696DD
extern u8 cheat_activated_60;
//CODE.bss:800696DE
extern u8 cheat_activated_61;
//CODE.bss:800696DF
extern u8 cheat_activated_62;
//CODE.bss:800696E0
extern u8 cheat_activated_63;
//CODE.bss:800696E1
extern u8 cheat_activated_64;
//CODE.bss:800696E2
extern u8 cheat_activated_65;
//CODE.bss:800696E3
extern u8 cheat_activated_66;
//CODE.bss:800696E4
extern u8 cheat_activated_67;
//CODE.bss:800696E5
extern u8 cheat_activated_68;
//CODE.bss:800696E6
extern u8 cheat_activated_69;
//CODE.bss:800696E7
extern u8 cheat_activated_70;
//CODE.bss:800696E8
extern u8 cheat_activated_71;
//CODE.bss:800696E9
extern u8 cheat_activated_72;
//CODE.bss:800696EA
extern u8 cheat_activated_73;
//CODE.bss:800696EB
extern u8 cheat_activated_74;
//CODE.bss:800696EC
extern u8 cheat_activated_75;
//CODE.bss:800696ED
extern u8 cheat_activated_76;
//CODE.bss:800696EE
extern u8 cheat_activated_77;
//CODE.bss:800696EF
extern u8 cheat_activated_78;

//CODE.bss:800696F0
extern s32 fav_weapon_right_player1;
//CODE.bss:800696F4
extern s32 fav_weapon_left_player1;
//CODE.bss:800696F8
extern s32 fav_weapon_right_player2;
//CODE.bss:800696FC
extern s32 fav_weapon_left_player2;
//CODE.bss:80069700
extern s32 fav_weapon_right_player3;
//CODE.bss:80069704
extern s32 fav_weapon_left_player3;
//CODE.bss:80069708
extern s32 fav_weapon_right_player4;
//CODE.bss:8006970C
extern s32 fav_weapon_left_player4;
//CODE.bss:80069710
extern s32 mp_char_cur_select_player1;
//CODE.bss:80069714
extern s32 mp_char_cur_select_player2;
//CODE.bss:80069718
extern s32 mp_char_cur_select_player3;
//CODE.bss:8006971C
extern s32 mp_char_cur_select_player4;
//CODE.bss:80069720
extern s32 mp_char_prev_select_player1;
//CODE.bss:80069724
extern s32 mp_char_prev_select_player2;
//CODE.bss:80069728
extern s32 mp_char_prev_select_player3;
//CODE.bss:8006972C
extern s32 mp_char_prev_select_player4;
//CODE.bss:80069730
extern s32 dword_CODE_bss_80069730;
//CODE.bss:80069734
extern s32 dword_CODE_bss_80069734;
//CODE.bss:80069738
extern s32 dword_CODE_bss_80069738;
//CODE.bss:8006973C
extern s32 dword_CODE_bss_8006973C;
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
extern s32 dword_CODE_bss_80069770;
//CODE.bss:80069774
extern s32 dword_CODE_bss_80069774;
//CODE.bss:80069778
extern s32 dword_CODE_bss_80069778;
//CODE.bss:8006977C
extern s32 current_mp_stage_highlighted;
//CODE.bss:80069780
extern s32 dword_CODE_bss_80069780;
//CODE.bss:80069784
extern s32 mission_difficulty_highlighted;
//CODE.bss:80069788
extern s32 teamsize;
//CODE.bss:8006978C
extern s32 ptrbriefingdata;
//CODE.bss:80069790
extern s32 newcheatunlocked;
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

extern s32 current_menu;
extern s32 menu_update;
extern s32 maybe_prev_menu;
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
extern s32 gamemode;
extern s32 selected_stage;
extern s32 briefingpage;
extern s32 selected_difficulty;
extern s32 append_cheat_sp;
extern s32 append_cheat_mp;
extern f32 cursor_h_pos;
extern f32 cursor_v_pos;
extern s32 final_menu_briefing_page;
extern s32 current_menu_briefing_page;
extern s32 folder_selection_screen_option_icon;
extern s32 folder_selected_for_deletion;
extern s32 folder_selected_for_deletion_choice;
extern s32 mission_failed_or_aborted;
extern s32 mission_kia_flag;
extern s32 is_first_time_on_legal_screen;
extern s32 is_first_time_on_main_menu;
extern s32 prev_keypresses;
extern s32 dword_D_8002A938;
extern s32 maybe_is_in_menu;
extern s32 screen_size;
extern s32 spectrum_related_flag;
extern s32 is_emulating_spectrum;
extern s32 is_cheat_menu_available;
extern s32 ptr_logo_and_walletbond_DL;
extern s32 ptr_menu_videobuffer;
extern s32 something_legalscreen_constructor;
extern s32 ptr_folder_object_instance;
extern s32 set0_never_used;
extern s32 set0_never_used_0;
extern s32 D_8002A968;
extern s32 dword_D_8002A96C;
extern struct rgba_val stru_D_8002A970;
extern struct rgba_val stru_D_8002A974;
extern struct rgba_val stru_D_8002A978;
extern struct rgba_val stru_D_8002A97C;
extern struct rgba_val stru_D_8002A980;
extern struct rgba_val stru_D_8002A984;
extern struct rgba_val stru_D_8002A988;
extern struct rgba_val stru_D_8002A98C;
extern u32 dword_D_8002A990;
extern u32 dword_D_8002A994;
extern u32 dword_D_8002A998;
extern u32 dword_D_8002A99C;
extern f32 slider_007_mode_reaction;
extern f32 slider_007_mode_health;
extern f32 slider_007_mode_damage;
extern f32 slider_007_mode_accuracy;

/*
dword_D_8002A9B0:.word 0xA0000000
dword_D_8002A9B4:.word 0x96000000
dword_D_8002A9B8:.word 0x28000000
dword_D_8002A9BC:.word 0x8C000000
dword_D_8002A9C0:.word 0
dword_D_8002A9C4:.word 0
dword_D_8002A9C8:.word 0
stru_D_8002A9CC:legal_screen_text <220, 30, 1, 1, 0x9C07, 0>
                legal_screen_text <34, 83, 0, 1, 0x9C08, 0>
                legal_screen_text <226, 84, 0, 1, 0x9C09, 0>
                legal_screen_text <226, 97, 0, 1, 0x9C0A, 0>
                legal_screen_text <226, 110, 0, 1, 0x9C0B, 0>
                legal_screen_text <226, 122, 0, 1, 0x9C0C, 0>
                legal_screen_text <227, 134, 0, 1, 0x9C0D, 0>
                legal_screen_text <219, 211, 0, 1, 0x9C0E, 0>
                legal_screen_text <60, 169, 0, 1, 0x9C0F, 0>
                legal_screen_text <60, 201, 0, 1, 0x9C10, 0>
                legal_screen_text <99, 266, 0, 1, 0x9C11, 0>
                legal_screen_text <80, 280, 0, 1, 0x9C12, 0>
dword_D_8002AABC:.word 0
dword_D_8002AAC0:.word 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
dword_D_8002AB0C:.word 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
dword_D_8002AB58:.word 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
dword_D_8002AB94:.word 0xC4610000, 0x44480000, 0
                .word 0x44E10000, 0x44480000, 0
                .word 0xC4E10000, 0xC3480000, 0
                .float 900.0
                .float -200.0
                .word 0
f32 folder_option_COPY_left_bound = 0.0;
f32 folder_option_COPY_upper_bound = 0.0;
f32 folder_option_COPY_right_bound = 0.0;
f32 folder_option_COPY_lower_bound = 0.0;
f32 folder_option_ERASE_left_bound = 0.0;
f32 folder_option_ERASE_upper_bound = 0.0;
f32 folder_option_ERASE_right_bound = 0.0;
f32 folder_option_ERASE_lower_bound = 0.0;
mission_folder_setup_entries:
    mission_folder_setup <"1", 0x9C78, 0, LEVELID_NONE, 0, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C79, 0, LEVELID_DAM, 0, MISSION_PART, 0, "UbriefdamZ">
    mission_folder_setup <"ii", 0x9C7A, 0, LEVELID_FACILITY, 0, MISSION_PART, 1, "UbriefarkZ">
    mission_folder_setup <"iii", 0x9C7B, 0, LEVELID_RUNWAY, 0, MISSION_PART, 2, "UbriefrunZ">
    mission_folder_setup <"2", 0x9C7C, 0, LEVELID_NONE, 0, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C7D, 0, LEVELID_SURFACE, 0, MISSION_PART, 3, "UbriefsevxZ">
    mission_folder_setup <"ii", 0x9C7E, 0, LEVELID_BUNKER1, 0, MISSION_PART, 4, "UbriefsevbunkerZ">
    mission_folder_setup <"3", 0x9C7F, 0, LEVELID_NONE, 1, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C80, 0x9C81, LEVELID_SILO, 1, MISSION_PART, 5, "UbriefsiloZ">
    mission_folder_setup <"4", 0x9C82, 0, LEVELID_NONE, 1, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C83, 0, LEVELID_FRIGATE, 1, MISSION_PART, 6, "UbriefdestZ">
    mission_folder_setup <"5", 0x9C7C, 0, LEVELID_NONE, 1, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C7D, 0, LEVELID_SURFACE2, 1, MISSION_PART, 7, "UbriefsevxbZ">
    mission_folder_setup <"ii", 0x9C7E, 0, LEVELID_BUNKER2, 1, MISSION_PART, 8, "UbriefsevbZ">
    mission_folder_setup <"6", 0x9C84, 0, LEVELID_NONE, 2, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C85, 0x9C86, LEVELID_STATUE, 2, MISSION_PART, 9, "UbriefstatueZ">
    mission_folder_setup <"ii", 0x9C87, 0x9C88, LEVELID_ARCHIVES, 2, MISSION_PART, 0xA, "UbriefarchZ">
    mission_folder_setup <"iii", 0x9C89, 0, LEVELID_STREETS, 2, MISSION_PART, 0xB, "UbriefpeteZ">
    mission_folder_setup <"iv", 0x9C8A, 0, LEVELID_DEPOT, 2, MISSION_PART, 0xC, "UbriefdepoZ">
    mission_folder_setup <"v", 0x9C8B, 0, LEVELID_TRAIN, 2, MISSION_PART, 0xD, "UbrieftraZ">
    mission_folder_setup <"7", 0x9C8C, 0, LEVELID_NONE, 3, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i"     , 0x9C8D, 0, LEVELID_JUNGLE, 3, MISSION_PART, 0xE, "UbriefjunZ">
    mission_folder_setup <"ii", 0x9C8E, 0x9C8F, LEVELID_CONTROL, 3, MISSION_PART, 0xF, "UbriefcontrolZ">
    mission_folder_setup <"iii", 0x9C90, 0x9C91, LEVELID_CAVERNS, 3, MISSION_PART, 0x10, "UbriefcaveZ">
    mission_folder_setup <"iv", 0x9C92, 0x9C93, LEVELID_CRADLE, 3, MISSION_PART, 0x11, "UbriefcradZ">
    mission_folder_setup <"8", 0x9C94, 0, LEVELID_NONE, 4, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C95, 0x9C96, LEVELID_AZTEC, 4, MISSION_PART, 0x12, "UbriefaztZ">
    mission_folder_setup <"9", 0x9C97, 0, LEVELID_NONE, 4, MISSION_HEADER, 0xFFFFFFFF, 0>
    mission_folder_setup <"i", 0x9C98, 0x9C99, LEVELID_EGYPT, 4, MISSION_PART, 0x13, "UbriefcrypZ">
    mission_folder_setup <0, 0, 0, LEVELID_NONE, 0xFFFFFFFF, MISSION_PART, 0xFFFFFFFF, 0>

unknown_folderselect_constructor:.word 0x14
dword_D_8002AF30:.word 0x14
dword_D_8002AF34:.word 0x14
unknown_folderselect_constructor_0:.word 0x32
dword_D_8002AF3C:.word 0x32
dword_D_8002AF40:.word 0x32
unknown_folderselect:.word          0,         1,         3,         0,         0,         0,         0
                .word          0,         0,         0,         0,         0,         0,         0
                .word          0,         0
dword_D_8002AF84:.word          0,         1,         3,         0,         0,         0,         0
                .word          0,         0,         0,         0,         0,         0,         0
                .word          0
dword_D_8002AFC0:.word 0
dword_D_8002AFC4:.word 0
flt_D_8002AFC8: .float 190.0
flt_D_8002AFCC: .float -3300.0
cursor_xpos_table_mission_select:.word         73,       142,       212,       282,       352
cursor_ypos_table_mission_select:.word         62,       131,       201,       270
                MP_game_length_settings <0x9C2D, 0, 0, 0>
                MP_game_length_settings <0x9C2E, 0, 0x4650, 0>
                MP_game_length_settings <0x9C2F, 0, 0x8CA0, 0>
                MP_game_length_settings <0x9C30, 0, 0x11940, 0>
                MP_game_length_settings <0x9C31, 0, 0, 5>
                MP_game_length_settings <0x9C32, 0, 0, 0xA>
                MP_game_length_settings <0x9C33, 0, 0, 0x14>
                MP_game_length_settings <0x9C34, 0, 0, 0>
mp_player_counts:mp_stage_playercount <0x9C35, 2, 4>
                mp_stage_playercount <0x9C36, 2, 4>
                mp_stage_playercount <0x9C37, 2, 4>
                mp_stage_playercount <0x9C38, 2, 4>
                mp_stage_playercount <0x9C39, 2, 4>
                mp_stage_playercount <0x9C3A, 4, 4>
                mp_stage_playercount <0x9C3B, 4, 4>
                mp_stage_playercount <0x9C3C, 3, 3>
multi_stage_setups:mp_stage_setup <0x9C9A, 0x9C9B, 0x10, 0xFFFFFFFF, 0xFFFFFFFF, 1, 4>
stru_D_8002B08C:mp_stage_setup <0x9C9C, 0x9C9D, 0xC, 0x26, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9C9E, 0x9C9F, 0xE, 0x1F, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9CA2, 0x9CA3, 0xF, 0x32, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9CA0, 0x9CA1, 0xD, 0x30, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9D0D, 0x9D0E, 0xD, 0x2D, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9D0F, 0x9D10, 0xD, 0x2E, 0xFFFFFFFF, 1, 4>
                mp_stage_setup <0x9CA4, 0x9CA5, 4, 0x22, 1, 1, 4>
                mp_stage_setup <0x9CA6, 0x9CA7, 0, 0x1B, 8, 1, 3>
                mp_stage_setup <0x9CA8, 0x9CA9, 2, 0x18, 0xA, 1, 3>
                mp_stage_setup <0x9CAA, 0x9CAB, 1, 0x27, 0x10, 1, 3>
                mp_stage_setup <0x9CAC, 0x9CAD, 0xA, 0x20, 0x13, 1, 2>
num_chars_selectable_mp:.word 8
mp_chr_setup:   MP_selectable_chars <0x9CB8, MALE, 0, BODY_Tuxedo, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0>
                MP_selectable_chars <0x9CBF, FEMALE, 9, BODY_Natalya_Skirt, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.96609998>
                MP_selectable_chars <0x9CBC, MALE, 6, BODY_Trevelyan_Janus, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0>
                MP_selectable_chars <0x9CBE, FEMALE, 8, BODY_Xenia, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0>
                MP_selectable_chars <0x9CBB, MALE, 5, BODY_Ourumov, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0778>
                MP_selectable_chars <0x9CBA, MALE, 4, BODY_Boris, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.9702>
                MP_selectable_chars <0x9CBD, MALE, 7, BODY_Valentin_, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.93239999>
                MP_selectable_chars <0x9CB9, MALE, 0xF, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Mishkin, 1.0>
                MP_selectable_chars <0x9CC2, FEMALE, 0xC, BODY_Mayday, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0>
                MP_selectable_chars <0x9CC1, MALE, 0xB, BODY_Jaws, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.199>
                MP_selectable_chars <0x9CC3, MALE, 0xD, BODY_Oddjob, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT,0.78780001>
                MP_selectable_chars <0x9CC0, MALE, 0xA, BODY_Baron_Samedi, HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0>
                MP_selectable_chars <0x9CFD, MALE, 0xE, BODY_Russian_Soldier, HEAD_Male_Mark, 1.0>
                MP_selectable_chars <0x9CFC, MALE, 0xE, BODY_Russian_Infantry, HEAD_Male_Karl, 1.0>
                MP_selectable_chars <0x9D07, MALE, 0xE, BODY_Scientist_1_Male, HEAD_Male_Dave_Dr_Doak, 1.0>
                MP_selectable_chars <0x9D07, FEMALE, 0xE, BODY_Scientist_2_Female, HEAD_Female_Sally, 1.0>
                MP_selectable_chars <0x9D00, MALE, 0xE, BODY_Russian_Commandant, HEAD_Male_Martin, 1.0>
                MP_selectable_chars <0x9CFE, MALE, 0xE, BODY_Janus_Marine, HEAD_Male_Steve_Ellis, 1.0>
                MP_selectable_chars <0x9D01, MALE, 0xE, BODY_Naval_Officer, HEAD_Male_Duncan, 1.0>
                MP_selectable_chars <0x9D06, MALE, 0xE, BODY_Helicopter_Pilot, HEAD_Male_Pete, 1.0>
                MP_selectable_chars <0x9CFB, MALE, 0xE, BODY_St_Petersburg_Guard, HEAD_Male_Ken, 1.0>
                MP_selectable_chars <0x9D08, FEMALE, 0xE, BODY_Civilian_1_Female, HEAD_Female_Marion_Rosika, 1.0>
                MP_selectable_chars <0x9D08, MALE, 0xE, BODY_Civilian_2, HEAD_Male_Graeme, 1.0>
                MP_selectable_chars <0x9D08, MALE, 0xE, BODY_Civilian_3, HEAD_Male_Grant, 1.0>
                MP_selectable_chars <0x9D08, MALE, 0xE, BODY_Civilian_4, HEAD_Male_Dwayne, 1.0>
                MP_selectable_chars <0x9D02, MALE, 0xE, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Lee, 1.0>
                MP_selectable_chars <0x9D03, MALE, 0xE, BODY_Arctic_Commando, HEAD_Male_Chris, 1.0>
                MP_selectable_chars <0x9D02, MALE, 0xE, BODY_Siberian_Guard_2, HEAD_Male_Scott, 1.0>
                MP_selectable_chars <0x9D04, MALE, 0xE, BODY_Siberian_Special_Forces, HEAD_Male_Alan, 1.0>
                MP_selectable_chars <0x9CFA, MALE, 0xE, BODY_Jungle_Commando, HEAD_Male_Joel, 1.0>
                MP_selectable_chars <0x9CFF, MALE, 0xE, BODY_Janus_Special_Forces, HEAD_Male_B, 1.0>
                MP_selectable_chars <0x9D05, MALE, 0xE, BODY_Moonraker_Elite_1_Male, HEAD_Male_Neil, 1.0>
                MP_selectable_chars <0x9D05, FEMALE, 0xE, BODY_Moonraker_Elite_2_Female, HEAD_Female_Vivien, 1.0>
                MP_selectable_chars <0x9CC4, FEMALE, 0xE, BODY_Rosika, HEAD_Female_Marion_Rosika, 0.88529998>
                MP_selectable_chars <0x9CC5, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Karl, 1.0446>
                MP_selectable_chars <0x9CC6, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Martin, 1.0446>
                MP_selectable_chars <0x9CC7, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Mark, 1.0446>
                MP_selectable_chars <0x9CC8, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dave_Dr_Doak, 1.0446>
                MP_selectable_chars <0x9CC9, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Duncan, 1.0446>
                MP_selectable_chars <0x9CCA, FEMALE, 0xE, BODY_Tuxedo, HEAD_Male_B, 1.0446>
                MP_selectable_chars <0x9CCB, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_Ellis, 1.0446>
                MP_selectable_chars <0x9CCC, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Grant, 1.0446>
                MP_selectable_chars <0x9CCD, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Graeme, 1.0446>
                MP_selectable_chars <0x9CCE, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Ken, 1.0446>
                MP_selectable_chars <0x9CCF, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Alan, 1.0446>
                MP_selectable_chars <0x9CD0, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Pete, 1.0446>
                MP_selectable_chars <0x9CD1, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Shaun, 1.0446>
                MP_selectable_chars <0x9CD2, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dwayne, 1.0446>
                MP_selectable_chars <0x9CD3, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Des, 1.0446>
                MP_selectable_chars <0x9CD4, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Chris, 1.0446>
                MP_selectable_chars <0x9CD5, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Lee, 1.0446>
                MP_selectable_chars <0x9CD6, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Neil, 1.0446>
                MP_selectable_chars <0x9CD7, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Jim, 1.0446>
                MP_selectable_chars <0x9CD8, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Robin, 1.0446>
                MP_selectable_chars <0x9CD9, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_H, 1.0446>
                MP_selectable_chars <0x9CDA, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Terrorist, 1.0446>
                MP_selectable_chars <0x9CDB, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Biker, 1.0446>
                MP_selectable_chars <0x9CDC, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joel, 1.0446>
                MP_selectable_chars <0x9CDD, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Scott, 1.0446>
                MP_selectable_chars <0x9CDE, MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joe, 1.0446>
                MP_selectable_chars <0x9CDF, FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Sally, 1.0446>
                MP_selectable_chars <0x9CE0, FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Marion_Rosika, 1.0446>
                MP_selectable_chars <0x9CE1, FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Mandy, 1.0446>
                MP_selectable_chars <0x9CE2, FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Vivien, 1.0446>

MP_handicap_table:MP_handicap_menu <0x9C3D, 0, 10.0>
                MP_handicap_menu <0x9C3E, 0, 2.8560996>
                MP_handicap_menu <0x9C3F, 0, 2.1969998>
                MP_handicap_menu <0x9C40, 0, 1.6899998>
                MP_handicap_menu <0x9C41, 0, 1.3>
                MP_handicap_menu <0x9C42, 0, 1.0>
                MP_handicap_menu <0x9C43, 0, 0.76923078>
                MP_handicap_menu <0x9C44, 0, 0.59171599>
                MP_handicap_menu <0x9C45, 0, 0.45516616>
                MP_handicap_menu <0x9C46, 0, 0.35012782>
                MP_handicap_menu <0x9C47, 0, 0.1>
                MP_controller_configuration_menu <0x9D, 0x15, 0, 1>
                MP_controller_configuration_menu <0x9D, 0x16, 1, 1>
                MP_controller_configuration_menu <0x9D, 0x17, 2, 1>
                MP_controller_configuration_menu <0x9D, 0x18, 3, 1>
                MP_controller_configuration_menu <0x9D, 0x19, 4, 2>
                MP_controller_configuration_menu <0x9D, 0x1A, 5, 2>
                MP_controller_configuration_menu <0x9D, 0x1B, 6, 2>
                MP_controller_configuration_menu <0x9D, 0x1C, 7, 2>
stru_mp_sight_adjust_table:MP_sight_aim_settings <0x9C, 0x48, 0, 0>
                MP_sight_aim_settings <0x9C, 0x49, 1, 0>
                MP_sight_aim_settings <0x9C, 0x4A, 0, 1>
                MP_sight_aim_settings <0x9C, 0x4B, 1, 1>
*/
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
/*
dword_D_8002B560:.word 0
                solo_target_times <0, 160, 0>
                solo_target_times <0, 0, 125>
                solo_target_times <300, 0, 0>
                solo_target_times <0, 210, 0>
                solo_target_times <0, 0, 240>
                solo_target_times <180, 0, 0>
                solo_target_times <0, 270, 0>
                solo_target_times <0, 0, 255>
                solo_target_times <90, 0, 0>
                solo_target_times <0, 195, 0>
                solo_target_times <0, 0, 80>
                solo_target_times <105, 0, 0>
                solo_target_times <0, 100, 0>
                solo_target_times <0, 0, 325>
                solo_target_times <225, 0, 0>
                solo_target_times <0, 600, 0>
                solo_target_times <0, 0, 570>
                solo_target_times <135, 0, 0>
                solo_target_times <0, 540, 0>
                solo_target_times <0, 0, 360>
dword_D_8002B5DC:.word 0
dword_D_8002B5E0:.word 0
MP_menu_selected_option:.word 0
*/
extern u32 do_not_play_intro_movie;
extern u32 randomly_selected_intro_animation;
extern u32 intro_animation_count;
extern u32 objinstance;
extern u32 ptrobjinstance;
extern u32 full_actor_intro;

#endif
