#include <os_extension.h>
#include <assets/oddtextures.h>
#include "assets/image_externs.h"
#include <ultra64.h>
#include <bondgame.h>
#include <bondconstants.h>
#include <boss.h>
#include <fr.h>
#include "language.h"
#include <joy.h>
#include <music.h>
#include <random.h>
#include <snd.h>
#include <macro.h>  
#include "bondview.h"
#include "chr.h"
#include "chr_b.h"
#include "chraction.h"
#include "cheat.h"
#include "chrobjdata.h"
#include "file2.h"
#include "front.h"
#include "image_bank.h"
#include "lv.h"
#include "initanitable.h"
#include "mp_weapon.h"
#include "math_floor.h"
#include "objective_status.h"
#include "player.h"
#include "spectrum.h"
#include "textrelated.h"
#include "blood_animation.h"
#include "game/othermodemicrocode.h"
#include "game/bondwalk2.h"
#include "game/file2.h"
#include "objecthandler.h"
#include "dyn.h"
#include "assets/obseg/text/LtitleE.h"
#include "matrixmath.h"
#include "bg.h"
#include "chrai.h"
#include "title.h"
#include <assets/font_dl.h>
#include "image.h"
#include "ob.h"
#include "gbi_extension.h"
#include "model.h"


/**
 * Each character showing in the display cast screen lasts 3 seconds with a half second cross-fade
 * and the camera velocity is tuned per refresh rate so its decay per second is the
 * same on PAL (0.95 ^ (60/50) = 0.9403). 
 */
#ifdef REFRESH_PAL
#define CAST_INTRO_LEN          (50 * 3)
#define CAST_INTRO_FADE         (50 / 2)
#define CAST_DAMP               0.940299988f
#define CAST_DAMP_COMP          0.0597000122f
#else
#define CAST_INTRO_LEN          (60 * 3)
#define CAST_INTRO_FADE         (60 / 2)
#define CAST_DAMP               0.94999999f
#define CAST_DAMP_COMP          0.050000012f
#endif
#define CAST_INTRO_FADEOUT      (CAST_INTRO_LEN - CAST_INTRO_FADE + 1)
#define CAST_INTRO_LEN_F        ((f32)CAST_INTRO_LEN)
#define CAST_INTRO_FADE_F       ((f32)CAST_INTRO_FADE)

struct BriefingDataSomething
{
    u16 textid;
    u16 enabled_difficulty;
};

struct BriefingData
{
    u16 brief[4];
    struct BriefingDataSomething objective[OBJECTIVES_MAX];
};

// bss
//CODE.bss:800695A0
f32 cast_camera_dist;
//CODE.bss:800695A4
f32 cast_camera_dist_start;
//CODE.bss:800695A8
f32 cast_camera_dist_end;
//CODE.bss:800695AC
f32 cast_camera_angle;
//CODE.bss:800695B0
f32 cast_camera_angle_start;
//CODE.bss:800695B4
f32 cast_camera_angle_end;
//CODE.bss:800695B8
f32 cast_camera_height;
//CODE.bss:800695BC
f32 cast_camera_height_start;
//CODE.bss:800695C0
f32 cast_camera_height_end;
//CODE.bss:800695C4
f32 flt_CODE_bss_800695C4; // unused
//CODE.bss:800695C8
struct coord3d cast_target_smoothed;
//CODE.bss:800695D4
f32 flt_CODE_bss_800695D4; // unused
//CODE.bss:800695D8
struct coord3d cast_target_accumulator;

//CODE.bss:800695E4
bool cast_camera_reset;

//CODE.bss:800695E8
struct coord3d cast_rootpos_smoothed;

//CODE.bss:800695F4
f32 flt_CODE_bss_800695F4;
//CODE.bss:800695F8
struct coord3d cast_rootvel_smoothed;
//CODE.bss:80069604
f32 flt_CODE_bss_80069604;

//CODE.bss:80069608
struct coord3d cast_rootvel_accumulator;


//CODE.bss:80069614
f32 ninLogoRotRate;

/**
 * Address 80069618
 * EU .bss 80068558
*/
f32 ninLogoScale;

//CODE.bss:8006961C
f32 flt_CODE_bss_8006961C;
//CODE.bss:80069620
coord3d folderpositions_camspace[MAX_FOLDER_COUNT];

//CODE.bss:80069650
u8 cheat_available[CHEAT_MAX];

//CODE.bss:800696A0
u8 g_CheatActivated[CHEAT_MAX];

#ifdef VERSION_EU

/**
 * EU .bss 80068630
*/
s32 mp_char_cur_select_player[MAX_PLAYER_COUNT];

/**
 * EU .bss 80068680
*/
s32 mp_char_prev_select_player[MAX_PLAYER_COUNT];

/**
 * EU .bss 80068650
*/
s32 array_favweapon[MAX_PLAYER_COUNT][GUNHANDS];

#else

/**
 * Address 800696F0
*/
s32 array_favweapon[MAX_PLAYER_COUNT][GUNHANDS];

/**
 * Address 80069710
*/
s32 mp_char_cur_select_player[MAX_PLAYER_COUNT];

/**
 * Address 80069720
*/
s32 mp_char_prev_select_player[MAX_PLAYER_COUNT];

#endif


/**
 * Address 80069730
 * EU .bss 80068690
*/
s32 mp_char_select_scroll_offset[MAX_PLAYER_COUNT];

//CODE.bss:80069740
bool player_has_selected_char[MAX_PLAYER_COUNT];

//CODE.bss:80069750
s32 size_mp_select_image_player[MAX_PLAYER_COUNT];
//CODE.bss:80069760
s32 dword_CODE_bss_80069760[MAX_PLAYER_COUNT];
//CODE.bss:80069770
char* g_textPtrTAB1;
//CODE.bss:80069774
char* g_textPtrTAB2;
//CODE.bss:80069778
char* g_textPtrTAB3;
//CODE.bss:8006977C
s32 current_mp_stage_highlighted;
//CODE.bss:80069780
s32 dword_CODE_bss_80069780;
//CODE.bss:80069784
s32 mission_difficulty_highlighted;
//CODE.bss:80069788
s32 teamsize;
//CODE.bss:8006978C
struct BriefingData *ptrbriefingdata;
//CODE.bss:80069790
s32 g_NewCheatUnlocked;
//CODE.bss:80069794
s32 highlight_enemy_reaction;
//CODE.bss:80069798
s32 highlight_enemy_health;
//CODE.bss:8006979C
s32 highlight_enemy_damage;
//CODE.bss:800697A0
s32 highlight_enemy_accuracy;

//CODE.bss:800697A4
s32 dword_CODE_bss_800697A4;

//CODE.bss:800697A8
s32 player_handicap[MAX_PLAYER_COUNT];

//CODE.bss:800697B8
s32 controlstyle_player[MAX_PLAYER_COUNT];

//CODE.bss:800697C8
s32 highlight_players;
//CODE.bss:800697CC
s32 highlight_scenario;
//CODE.bss:800697D0
s32 highlight_gameselect;
//CODE.bss:800697D4
s32 highlight_gamelength;
//CODE.bss:800697D8
s32 highlight_character;
//CODE.bss:800697DC
s32 highlight_weaponselect;
//CODE.bss:800697E0
s32 highlight_health;
//CODE.bss:800697E4
s32 highlight_controlstyle;
//CODE.bss:800697E8
s32 highlight_aimadjustment;
//CODE.bss:800697EC                     .align 4

/**
 * Address 0x800697F0
 * EU .bss 0x80058730
*/
u32 arrayUnlockedCheats[CHEAT_INVALID];


MENU current_menu = MENU_INVALID;
MENU menu_update = MENU_INVALID;
MENU maybe_prev_menu = MENU_INVALID;

s32 g_MenuTimer = 0;

s32 tab_start_selected = FALSE;
s32 tab_next_selected = FALSE;
s32 tab_prev_selected = FALSE;

s32 tab_start_highlight = FALSE;
s32 tab_next_highlight = FALSE;
s32 tab_prev_highlight = FALSE;

s32 selected_folder_num = FOLDER1;
s32 selected_folder_num_copy = FOLDER1;

GAMEMODE gamemode = GAMEMODE_INTRO;
s32 selected_stage = LEVELID_NONE;
s32 briefingpage = BRIEFING_INVALID;
DIFFICULTY selected_difficulty = DIFFICULTY_MULTI;

s32 g_AppendCheatSinglePlayer = FALSE;
s32 g_AppendCheatMultiPlayer = FALSE;

f32 cursor_h_pos = 220.0;
f32 cursor_v_pos = 165.0;

s32 final_menu_briefing_page = BRIEFING_M;
s32 current_menu_briefing_page = BRIEFING_TITLE;

s32 folder_selection_screen_option_icon = 0;
s32 folder_selected_for_deletion = FOLDER_INVALID;
s32 folder_selected_for_deletion_choice = FOLDER2;

s32 mission_failed_or_aborted = FALSE;
s32 g_isBondKIA = FALSE;

s32 is_first_time_on_legal_screen = TRUE;
s32 is_first_time_on_main_menu = TRUE;

s32 prev_keypresses = FALSE;
s32 ge_logo_bool = FALSE;

s32 maybe_is_in_menu = TRUE;
s32 screen_size = SCREEN_SIZE_320x240;

s32 spectrum_related_flag = 0;
s32 is_emulating_spectrum = FALSE;

s32 is_cheat_menu_available = FALSE;

u8 * ptr_logo_and_walletbond_DL = NULL;
s32 ptr_menu_videobuffer = 0;
struct Model *logoinst = NULL;
struct Model * walletinst[] = { NULL, NULL, NULL, NULL};

Lights1 gelogolight = gdSPDefLights1(
    0x96, 0x96, 0x96,
    0xFF, 0xFF, 0xFF,
    77, 77, 46
);

Lights1 ninlogolight = gdSPDefLights1(
    0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00,
    0, 0, 0
);


f32 slider_007_mode_reaction = 0.0f;
f32 slider_007_mode_health = 1.0f;
f32 slider_007_mode_damage = 1.0f;
f32 slider_007_mode_accuracy = 1.0f;

/* 0x8002A9B0 */ rgba_u8 textglowR = { 160, 0, 0, 0 };
/* 0x8002A9B4 */ rgba_u8 textglowG = { 150, 0, 0, 0 };
/* 0x8002A9B8 */ rgba_u8 textglowB = { 40, 0, 0, 0 };
/* 0x8002A9BC */ rgba_u8 textglowA = { 140, 0, 0, 0 };

struct coord3d legalpage_pos = {0.0f, 0.0f, 0.0f};

struct legal_screen_text legalpage_text_array[] = {
    {220,  30, CENTER_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_07_TWY), 0}, //"TWYCROSS BOARD OF GAME CLASSIFICATION\n"
    { 34,  83, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_08_CERT), 0}, //"This is to certify\n"
    {226,  84, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_09_NINRARE), 0}, //"(c) 1997 Nintendo/Rare\n"
    {226,  97, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_10_DANJAQ), 0}, //"(c) 1962, 1995 Danjaq, LLC. &\n"
    {226, 110, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_11_UAC), 0}, //"U.A.C. All Rights Reserved\n"
    {226, 122, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_12_EON), 0}, //"(c) 1997 Eon Productions\n"
    {227, 134, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_13_MACB), 0}, //"Ltd. & Mac B. Inc.\n"
    {219, 211, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_14_PERSONS), 0}, //"Suitable only for 1-4 persons\n"
    { 60, 169, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_15_PRESIDENT), 0}, //"PRESIDENT\n"
    { 60, 201, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_16_VICE), 0}, //"VICE\n"
    { 99, 266, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_17_NORMAN), 0}, //"James Bond theme by Monty Norman.\n"
    { 80, 280, LEFT_ALIGN, CENTER_ALIGN, getStringID(LTITLE, TITLE_STR_18_EMI), 0}  //"Used by permission of EMI Unart Catalog Inc.\n"
};

/* 0x8002AABC */ ModelRenderData legalscreen_MRD = {NULL,
                                    TRUE,
                                    0x00000003,
                                    NULL,

                                    NULL,
                                    0,
                                    0,
                                    0,

                                    0,
                                    0,
                                    0,
                                    0,

                                    0,
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    CULLMODE_BOTH};


struct coord3d nintendologo_pos = {0};

ModelRenderData       nintendologo_MRD = {NULL,
                                    TRUE,
                                    0x00000003,
                                    NULL,

                                    NULL,
                                    0,
                                    0,
                                    0,

                                    0,
                                    0,
                                    0,
                                    0,

                                    0,
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    CULLMODE_BOTH};


struct coord3d goldeneyelogo_pos = { 0 };

ModelRenderData       goldeneyelogo_MRD = {NULL,
                                    TRUE,
                                    0x00000003,
                                    NULL,

                                    NULL,
                                    0,
                                    0,
                                    0,

                                    0,
                                    0,
                                    0,
                                    0,

                                    0,
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    CULLMODE_BOTH};


struct coord3d folderpositions[] = {
    {-900.0f, 800.0f, 0.0f},
    {1800.0f, 800.0f, 0.0f},
    {-1800.0f, -200.0f, 0.0f},
    {900.0f, -200.0f, 0.0f}
};

struct rectbbox folder_option_COPY_bound = { 0 };
struct rectbbox folder_option_ERASE_bound = { 0 };

struct mission_folder_setup mission_folder_setup_entries[] = {
  /* string_ptr  folder_text_preset                                                         icon_text_preset                                            stage_id           unknown type             mission_num briefing_name_ptr */
    {"1",        getStringID(LTITLE, TITLE_STR_120_ARK)            /* Arkangelsk */,        0,                                                          LEVELID_NONE,           0, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_121_DAM)            /* Dam */,               0,                                                          LEVELID_DAM,            0, MISSION_PART,             0, "UbriefdamZ"},
    {"ii",       getStringID(LTITLE, TITLE_STR_122_FAC)            /* Facility */,          0,                                                          LEVELID_FACILITY,       0, MISSION_PART,             1, "UbriefarkZ"},
    {"iii",      getStringID(LTITLE, TITLE_STR_123_RUN)            /* Runway */,            0,                                                          LEVELID_RUNWAY,         0, MISSION_PART,             2, "UbriefrunZ"},
    {"2",        getStringID(LTITLE, TITLE_STR_124_SEV)            /* Severnaya */,         0,                                                          LEVELID_NONE,           0, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_125_SURF)           /* Surface */,           0,                                                          LEVELID_SURFACE,        0, MISSION_PART,             3, "UbriefsevxZ"},
    {"ii",       getStringID(LTITLE, TITLE_STR_126_BUNK)           /* Bunker */,            0,                                                          LEVELID_BUNKER1,        0, MISSION_PART,             4, "UbriefsevbunkerZ"},
    {"3",        getStringID(LTITLE, TITLE_STR_127_KIRG)           /* Kirghizstan */,       0,                                                          LEVELID_NONE,           1, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_128_SILO4)          /* Launch Silo #4 */,    getStringID(LTITLE, TITLE_STR_129_SILO)     /* Silo */,     LEVELID_SILO,           1, MISSION_PART,             5, "UbriefsiloZ"},
    {"4",        getStringID(LTITLE, TITLE_STR_130_MONTE)          /* Monte Carlo */,       0,                                                          LEVELID_NONE,           1, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_131_FRIG)           /* Frigate */,           0,                                                          LEVELID_FRIGATE,        1, MISSION_PART,             6, "UbriefdestZ"},
    {"5",        getStringID(LTITLE, TITLE_STR_124_SEV)            /* Severnaya */,         0,                                                          LEVELID_NONE,           1, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_125_SURF)           /* Surface */,           0,                                                          LEVELID_SURFACE2,       1, MISSION_PART,             7, "UbriefsevxbZ"},
    {"ii",       getStringID(LTITLE, TITLE_STR_126_BUNK)           /* Bunker */,            0,                                                          LEVELID_BUNKER2,        1, MISSION_PART,             8, "UbriefsevbZ"},
    {"6",        getStringID(LTITLE, TITLE_STR_132_STPETER)        /* St. Petersburg */,    0,                                                          LEVELID_NONE,           2, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_133_STATPARK)       /* Statue Park */,       getStringID(LTITLE, TITLE_STR_134_STAT)     /* Statue */,   LEVELID_STATUE,         2, MISSION_PART,             9, "UbriefstatueZ"},
    {"ii",       getStringID(LTITLE, TITLE_STR_135_MILARCH)        /* Military Archives */, getStringID(LTITLE, TITLE_STR_136_ARCH)     /* Archives */, LEVELID_ARCHIVES,       2, MISSION_PART,            10, "UbriefarchZ"},
    {"iii",      getStringID(LTITLE, TITLE_STR_137_STREETS)        /* Streets */,           0,                                                          LEVELID_STREETS,        2, MISSION_PART,            11, "UbriefpeteZ"},
    {"iv",       getStringID(LTITLE, TITLE_STR_138_DEPOT)          /* Depot */,             0,                                                          LEVELID_DEPOT,          2, MISSION_PART,            12, "UbriefdepoZ"},
    {"v",        getStringID(LTITLE, TITLE_STR_139_TRAIN)          /* Train */,             0,                                                          LEVELID_TRAIN,          2, MISSION_PART,            13, "UbrieftraZ"},
    {"7",        getStringID(LTITLE, TITLE_STR_140_CUBA)           /* Cuba */,              0,                                                          LEVELID_NONE,           3, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_141_JUN)            /* Jungle */,            0,                                                          LEVELID_JUNGLE,         3, MISSION_PART,            14, "UbriefjunZ"},
    {"ii",       getStringID(LTITLE, TITLE_STR_142_CONCENTER)      /* Control Center */,    getStringID(LTITLE, TITLE_STR_143_CON)      /* Control */,  LEVELID_CONTROL,        3, MISSION_PART,            15, "UbriefcontrolZ"},
    {"iii",      getStringID(LTITLE, TITLE_STR_144_WATERCAV)       /* Water Caverns */,     getStringID(LTITLE, TITLE_STR_145_CAV)      /* Caverns */,  LEVELID_CAVERNS,        3, MISSION_PART,            16, "UbriefcaveZ"},
    {"iv",       getStringID(LTITLE, TITLE_STR_146_ANTENNA)        /* Antenna Cradle */,    getStringID(LTITLE, TITLE_STR_147_CRADLE)   /* Cradle */,   LEVELID_CRADLE,         3, MISSION_PART,            17, "UbriefcradZ"},
    {"8",        getStringID(LTITLE, TITLE_STR_148_TEOTIHUACA)     /* Teotihuaca'n */,      0,                                                          LEVELID_NONE,           4, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_149_AZTECCOMPLEX)   /* Aztec Complex */,     getStringID(LTITLE, TITLE_STR_150_AZTEC)    /* Aztec */,    LEVELID_AZTEC,          4, MISSION_PART,            18, "UbriefaztZ"},
    {"9",        getStringID(LTITLE, TITLE_STR_151_ELSAGHIRA)      /* el-Saghira */,        0,                                                          LEVELID_NONE,           4, MISSION_HEADER,          -1, 0},
    {"i",        getStringID(LTITLE, TITLE_STR_152_EGYPTIANTEMPLE) /* Egyptian Temple */,   getStringID(LTITLE, TITLE_STR_153_EGYPTIAN) /* Egyptian */, LEVELID_EGYPT,          4, MISSION_PART,            19, "UbriefcrypZ"},
    {NULL,       0,                                                                         0,                                                          LEVELID_NONE,          -1, MISSION_PART,            -1, 0}
};

struct FolderSelectColour unknown_folderselect_constructor = { 0x14, 0x14, 0x14 };
struct FolderSelectColour unknown_folderselect_constructor_0 = { 0x32, 0x32, 0x32 };


ModelRenderData     unknown_folderselect = {NULL,
                                            TRUE,
                                            0x00000003,
                                            NULL,

                                            NULL,
                                            0,
                                            0,
                                            0,

                                            0,
                                            0,
                                            0,
                                            0,

                                            0,
                                            {0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            CULLMODE_BOTH};

ModelRenderData       D_8002AF84           = {NULL,
                                              TRUE,
                                              0x00000003,
                                              NULL,

                                              NULL,
                                              0,
                                              0,
                                              0,

                                              0,
                                              0,
                                              0,
                                              0,

                                              0,
                                              {0, 0, 0, 0},
                                              {0, 0, 0, 0},
                                              CULLMODE_BOTH};


f32 D_8002AFC4 = 0;
f32 D_8002AFC8 = 190.0;
f32 D_8002AFCC = -3300.0;
s32 cursor_xpos_table_mission_select[] = {73, 142, 212, 282, 352};

#if defined(VERSION_EU)
s32 cursor_ypos_table_mission_select[] = {62, 130, 201, 270};
#else
s32 cursor_ypos_table_mission_select[] = {62, 131, 201, 270};
#endif

struct MP_game_length_settings multi_game_lengths[] = {
    {getStringID(LTITLE, TITLE_STR_45_UNLIMITED), 0, 0, 0},                    /* unlimited */
    {getStringID(LTITLE, TITLE_STR_46_5MIN), 0, MINS_TO_TIMER60(5), 0},   /* 5 minutes */
    {getStringID(LTITLE, TITLE_STR_47_10MIN), 0, MINS_TO_TIMER60(10), 0},  /* 10 minutes */
    {getStringID(LTITLE, TITLE_STR_48_20MIN), 0, MINS_TO_TIMER60(20), 0},  /* 20 minutes */
    {getStringID(LTITLE, TITLE_STR_49_5PT), 0, 0, 5},                    /* first to 5 points */
    {getStringID(LTITLE, TITLE_STR_50_10PT), 0, 0, 10},                   /* first to 10 points */
    {getStringID(LTITLE, TITLE_STR_51_20PT), 0, 0, 20},                   /* first to 20 points */
    {getStringID(LTITLE, TITLE_STR_52_LASTALIVE), 0, 0, 0}                     /* last person alive wins */
};

struct mp_stage_playercount mp_player_counts[] = {
    {getStringID(LTITLE, TITLE_STR_53_NORMAL), 2, 4}, //"Normal"
    {getStringID(LTITLE, TITLE_STR_54_YOLT), 2, 4}, //"You Only Live Twice"
    {getStringID(LTITLE, TITLE_STR_55_FLAGTAG), 2, 4}, //"The Living Daylights [Flag Tag]"
    {getStringID(LTITLE, TITLE_STR_56_GG), 2, 4}, //"The Man With the Golden Gun"
    {getStringID(LTITLE, TITLE_STR_57_LTK), 2, 4}, //"License to Kill"
    {getStringID(LTITLE, TITLE_STR_58_2V2), 4, 4}, //"Team: 2 vs 2"
    {getStringID(LTITLE, TITLE_STR_59_3V1), 4, 4}, //"Team: 3 vs 1"
    {getStringID(LTITLE, TITLE_STR_60_2V1), 3, 3}  //"Team: 2 vs 1"
};

struct mp_stage_setup multi_stage_setups[] = {
    /* unlocked by default */
    {getStringID(LTITLE, TITLE_STR_154_RANDOM), getStringID(LTITLE, TITLE_STR_155_RANDOM2), IMG_MP_RANDOM, LEVELID_NONE, -1, 1, 4},
    {getStringID(LTITLE, TITLE_STR_156_TEMPLE), getStringID(LTITLE, TITLE_STR_157_TEMPLE2), IMG_MP_TEMPLE, LEVELID_TEMPLE, -1, 1, 4},
    {getStringID(LTITLE, TITLE_STR_158_COMPLEX), getStringID(LTITLE, TITLE_STR_159_COMPLEX2), IMG_MP_COMPLEX, LEVELID_COMPLEX, -1, 1, 4},
    {getStringID(LTITLE, TITLE_STR_162_CAVES), getStringID(LTITLE, TITLE_STR_163_CAVES2), IMG_MP_CAVES, LEVELID_CAVES, -1, 1, 4},
    {getStringID(LTITLE, TITLE_STR_160_LIBRARY), getStringID(LTITLE, TITLE_STR_161_LIBRARY2), IMG_MP_BASEMENT, LEVELID_LIBRARY, -1, 1, 4},
    {getStringID(LTITLE, TITLE_STR_269_BASEMENT), getStringID(LTITLE, TITLE_STR_270_BASEMENT2), IMG_MP_BASEMENT, LEVELID_BASEMENT, -1, 1, 4},
#ifdef MP_SURFACE
    /* Surface takes Stack's slot, the stage select grid only holds 12 */
    {getStringID(LTITLE, TITLE_STR_125_SURF), getStringID(LTITLE, TITLE_STR_125_SURF), IMG_MP_RANDOM, LEVELID_SURFACE, -1, 1, 4},
#else
    {getStringID(LTITLE, TITLE_STR_271_STACK), getStringID(LTITLE, TITLE_STR_272_STACK2), IMG_MP_BASEMENT, LEVELID_STACK, -1, 1, 4},
#endif
    /* unlocked on level progression */
    {getStringID(LTITLE, TITLE_STR_164_FACMP), getStringID(LTITLE, TITLE_STR_165_FACMP22), IMG_MP_FACILITY, LEVELID_FACILITY, SP_LEVEL_FACILITY, 1, 4},
    {getStringID(LTITLE, TITLE_STR_166_SEVERNAYABUNKER), getStringID(LTITLE, TITLE_STR_167_BUNKER), IMG_MP_BUNKER2, LEVELID_BUNKER2, SP_LEVEL_BUNKER2, 1, 3},
    {getStringID(LTITLE, TITLE_STR_168_MILITARYARCHIVES), getStringID(LTITLE, TITLE_STR_169_ARCHIVES), IMG_MP_ARCHIVES, LEVELID_ARCHIVES, SP_LEVEL_ARCHIVES, 1, 3},
    {getStringID(LTITLE, TITLE_STR_170_WATERCAVERNS), getStringID(LTITLE, TITLE_STR_171_CAVERNS), IMG_MP_CAVERNS, LEVELID_CAVERNS, SP_LEVEL_CAVERNS, 1, 3},
    {getStringID(LTITLE, TITLE_STR_172_EGYPTIANTEMPLEMP), getStringID(LTITLE, TITLE_STR_173_EGYPTIANMP), IMG_MP_EGYPT, LEVELID_EGYPT, SP_LEVEL_EGYPT, 1, 2}
  //{getStringID(LTITLE, TITLE_STR_174_CITADEL), getStringID(LTITLE, TITLE_STR_175_CITADEL2), IMG_MP_RANDOM, LEVELID_CITADEL, -1, 1, 4}, //Citadel (old format setup)
  //{getStringID(LTITLE, TITLE_STR_176_DEST), getStringID(LTITLE, TITLE_STR_177_DEST2), IMG_MP_FRIGATE, LEVELID_FRIGATE, SP_LEVEL_FRIGATE, 1, 4}, //dest (has xbla setup)
  //{getStringID(LTITLE, TITLE_STR_178_STAT), getStringID(LTITLE, TITLE_STR_179_STAT2), IMG_MP_STATUE, LEVELID_STATUE, SP_LEVEL_STATUE, 1, 2}, //stat (works)
  //{getStringID(LTITLE, TITLE_STR_180_CRAD), getStringID(LTITLE, TITLE_STR_181_CRADLE2), IMG_MP_CRADLE, LEVELID_CRADLE, SP_LEVEL_CRADLE, 1, 2}, //crad (works)
  //{getStringID(LTITLE, TITLE_STR_182_AZT), getStringID(LTITLE, TITLE_STR_183_AZT2), IMG_MP_AZTEC, LEVELID_AZTEC, SP_LEVEL_AZTEC, 1, 4}, //azt (needs setup)
  //{getStringID(LTITLE, TITLE_STR_123_RUN), getStringID(LTITLE, TITLE_STR_123_RUN), IMG_MP_RUNWAY, LEVELID_RUNWAY, SP_LEVEL_RUN, 1, 4}, //runway (xbla setup)
  //{getStringID(LTITLE, TITLE_STR_121_DAM), getStringID(LTITLE, TITLE_STR_121_DAM), IMG_MP_DAM, LEVELID_DAM, SP_LEVEL_DAM, 1, 4}, //dam (xbla setup)
  //{getStringID(LTITLE, TITLE_STR_138_DEPOT), getStringID(LTITLE, TITLE_STR_138_DEPOT), IMG_MP_DEPOT, LEVELID_DEPOT, SP_LEVEL_DEPOT, 1, 4}, //depot (xbla setup)
};

s32 num_chars_selectable_mp = 8;

#ifdef BUGFIX_R0
struct MP_selectable_chars mp_chr_setup[] = {
    {getStringID(LTITLE, TITLE_STR_184_BOND), MALE,   IMG_MPC_BROSNAN, BODY_Brosnan_Tuxedo,                   HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_191_NATALYA), FEMALE, IMG_MPC_NATALYA, BODY_Natalya_Skirt,            HEAD_Male_Brosnan_Tuxedo, 0.96609998},
    {getStringID(LTITLE, TITLE_STR_188_TREVELYAN), MALE,   IMG_MPC_TREVELYAN, BODY_Trevelyan_Janus,          HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_190_XENIA), FEMALE, IMG_MPC_XENIA, BODY_Xenia,                    HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_187_OURUMOV), MALE,   IMG_MPC_OURUMOV, BODY_Ourumov,                  HEAD_Male_Brosnan_Tuxedo, 1.0778},
    {getStringID(LTITLE, TITLE_STR_186_BORIS), MALE,   IMG_MPC_BORIS, BODY_Boris,                    HEAD_Male_Brosnan_Tuxedo, 0.9702},
    {getStringID(LTITLE, TITLE_STR_189_VALENTIN), MALE,   IMG_MPC_VALENTIN, BODY_Valentin_,                HEAD_Male_Brosnan_Tuxedo, 0.93239999},
    {getStringID(LTITLE, TITLE_STR_185_MISHKIN), MALE,   IMG_MPC_MISHKIN, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Mishkin, 1.0},
    {getStringID(LTITLE, TITLE_STR_194_MAYDAY), FEMALE, IMG_MPC_MAYDAY, BODY_Mayday,                   HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_193_JAWS), MALE,   IMG_MPC_JAWS, BODY_Jaws,                     HEAD_Male_Brosnan_Tuxedo, 1.199},
    {getStringID(LTITLE, TITLE_STR_195_ODDJOB), MALE,   IMG_MPC_ODDJOB, BODY_Oddjob,                   HEAD_Male_Brosnan_Tuxedo,0.78780001},
    {getStringID(LTITLE, TITLE_STR_192_BARONSAMEDI), MALE,   IMG_MPC_BARON, BODY_Baron_Samedi,             HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_253_RUSSIANSOLDIER), MALE,   IMG_MPC_RANDOM, BODY_Russian_Soldier,          HEAD_Male_Mark, 1.0},
    {getStringID(LTITLE, TITLE_STR_252_RUSSIANINFANTRY), MALE,   IMG_MPC_RANDOM, BODY_Russian_Infantry,         HEAD_Male_Karl, 1.0},
    {getStringID(LTITLE, TITLE_STR_263_SCIENTIST), MALE,   IMG_MPC_RANDOM, BODY_Scientist_1_Male,         HEAD_Male_Dave_Dr_Doak, 1.0},
    {getStringID(LTITLE, TITLE_STR_263_SCIENTIST), FEMALE, IMG_MPC_RANDOM, BODY_Scientist_2_Female,       HEAD_Female_Sally, 1.0},
    {getStringID(LTITLE, TITLE_STR_256_RUSSIANCOMMANDANT), MALE,   IMG_MPC_RANDOM, BODY_Russian_Commandant,       HEAD_Male_Martin, 1.0},
    {getStringID(LTITLE, TITLE_STR_254_JANUSMARINE), MALE,   IMG_MPC_RANDOM, BODY_Janus_Marine,             HEAD_Male_Steve_Ellis, 1.0},
    {getStringID(LTITLE, TITLE_STR_257_NAVALOFFICER), MALE,   IMG_MPC_RANDOM, BODY_Naval_Officer,            HEAD_Male_Duncan, 1.0},
    {getStringID(LTITLE, TITLE_STR_262_HELICOPTERPILOT), MALE,   IMG_MPC_RANDOM, BODY_Helicopter_Pilot,         HEAD_Male_Pete, 1.0},
    {getStringID(LTITLE, TITLE_STR_251_STPETERSBURGGUARD), MALE,   IMG_MPC_RANDOM, BODY_St_Petersburg_Guard,      HEAD_Male_Ken, 1.0},
    {getStringID(LTITLE, TITLE_STR_264_CIVILIAN), FEMALE, IMG_MPC_RANDOM, BODY_Civilian_1_Female,        HEAD_Female_Marion_Rosika, 1.0},
    {getStringID(LTITLE, TITLE_STR_264_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_2,               HEAD_Male_Graeme, 1.0},
    {getStringID(LTITLE, TITLE_STR_264_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_3,               HEAD_Male_Grant, 1.0},
    {getStringID(LTITLE, TITLE_STR_264_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_4,               HEAD_Male_Dwayne, 1.0},
    {getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Lee, 1.0},
    {getStringID(LTITLE, TITLE_STR_259_ARCTICCOMMANDO), MALE,   IMG_MPC_RANDOM, BODY_Arctic_Commando,          HEAD_Male_Chris, 1.0},
    {getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_2,         HEAD_Male_Scott, 1.0},
    {getStringID(LTITLE, TITLE_STR_260_SIBERIANSPECIALFORCES), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Special_Forces,  HEAD_Male_Alan, 1.0},
    {getStringID(LTITLE, TITLE_STR_250_JUNGLECOMMANDO), MALE,   IMG_MPC_RANDOM, BODY_Jungle_Commando,          HEAD_Male_Joel, 1.0},
    {getStringID(LTITLE, TITLE_STR_255_JANUSSPECIALFORCES), MALE,   IMG_MPC_RANDOM, BODY_Janus_Special_Forces,     HEAD_Male_B, 1.0},
    {getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE), MALE,   IMG_MPC_RANDOM, BODY_Moonraker_Elite_1_Male,   HEAD_Male_Neil, 1.0},
    {getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE), FEMALE, IMG_MPC_RANDOM, BODY_Moonraker_Elite_2_Female, HEAD_Female_Vivien, 1.0},
    {getStringID(LTITLE, TITLE_STR_196_ROSIKA), FEMALE, IMG_MPC_RANDOM, BODY_Rosika,                   HEAD_Female_Marion_Rosika, 0.88529998},
    {getStringID(LTITLE, TITLE_STR_197_KARL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Karl, 1.0446},
    {getStringID(LTITLE, TITLE_STR_198_MARTIN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Martin, 1.0446},
    {getStringID(LTITLE, TITLE_STR_199_MARK), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Mark, 1.0446},
    {getStringID(LTITLE, TITLE_STR_200_DAVE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Dave_Dr_Doak, 1.0446},
    {getStringID(LTITLE, TITLE_STR_201_DUNCAN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Duncan, 1.0446},
    {getStringID(LTITLE, TITLE_STR_202_B), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_B, 1.0446},
    {getStringID(LTITLE, TITLE_STR_203_STEVEE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Steve_Ellis, 1.0446},
    {getStringID(LTITLE, TITLE_STR_204_GRANT), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Grant, 1.0446},
    {getStringID(LTITLE, TITLE_STR_205_GRAEME), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Graeme, 1.0446},
    {getStringID(LTITLE, TITLE_STR_206_KEN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Ken, 1.0446},
    {getStringID(LTITLE, TITLE_STR_207_ALAN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Alan, 1.0446},
    {getStringID(LTITLE, TITLE_STR_208_PETE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Pete, 1.0446},
    {getStringID(LTITLE, TITLE_STR_209_SHAUN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Shaun, 1.0446},
    {getStringID(LTITLE, TITLE_STR_210_DWAYNE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Dwayne, 1.0446},
    {getStringID(LTITLE, TITLE_STR_211_DES), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Des, 1.0446},
    {getStringID(LTITLE, TITLE_STR_212_CHRIS), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Chris, 1.0446},
    {getStringID(LTITLE, TITLE_STR_213_LEE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Lee, 1.0446},
    {getStringID(LTITLE, TITLE_STR_214_NEIL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Neil, 1.0446},
    {getStringID(LTITLE, TITLE_STR_215_JIM), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Jim, 1.0446},
    {getStringID(LTITLE, TITLE_STR_216_ROBIN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Robin, 1.0446},
    {getStringID(LTITLE, TITLE_STR_217_STEVEH), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Steve_H, 1.0446},
    {getStringID(LTITLE, TITLE_STR_218_TERRORIST), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Terrorist, 1.0446},
    {getStringID(LTITLE, TITLE_STR_219_BIKER), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Biker, 1.0446},
    {getStringID(LTITLE, TITLE_STR_220_JOEL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Joel, 1.0446},
    {getStringID(LTITLE, TITLE_STR_221_SCOTT), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Scott, 1.0446},
    {getStringID(LTITLE, TITLE_STR_222_JOE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Joe, 1.0446},
    {getStringID(LTITLE, TITLE_STR_223_SALLY), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Sally, 1.0446},
    {getStringID(LTITLE, TITLE_STR_224_MARION), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Marion_Rosika, 1.0446},
    {getStringID(LTITLE, TITLE_STR_225_MANDY), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Mandy, 1.0446},
    {getStringID(LTITLE, TITLE_STR_226_VIVIEN), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Vivien, 1.0446}
};
#else
struct MP_selectable_chars mp_chr_setup[] = {
    {getStringID(LTITLE, TITLE_STR_184_BOND), MALE,   IMG_MPC_BROSNAN, BODY_Brosnan_Tuxedo,                   HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_191_NATALYA), FEMALE, IMG_MPC_NATALYA, BODY_Natalya_Skirt,            HEAD_Male_Brosnan_Tuxedo, 0.96609998},
    {getStringID(LTITLE, TITLE_STR_188_TREVELYAN), MALE,   IMG_MPC_TREVELYAN, BODY_Trevelyan_Janus,          HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_190_XENIA), FEMALE, IMG_MPC_XENIA, BODY_Xenia,                    HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_187_OURUMOV), MALE,   IMG_MPC_OURUMOV, BODY_Ourumov,                  HEAD_Male_Brosnan_Tuxedo, 1.0778},
    {getStringID(LTITLE, TITLE_STR_186_BORIS), MALE,   IMG_MPC_BORIS, BODY_Boris,                    HEAD_Male_Brosnan_Tuxedo, 0.9702},
    {getStringID(LTITLE, TITLE_STR_189_VALENTIN), MALE,   IMG_MPC_VALENTIN, BODY_Valentin_,                HEAD_Male_Brosnan_Tuxedo, 0.93239999},
    {getStringID(LTITLE, TITLE_STR_185_MISHKIN), MALE,   IMG_MPC_MISHKIN, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Mishkin, 1.0},
    {getStringID(LTITLE, TITLE_STR_194_MAYDAY), FEMALE, IMG_MPC_MAYDAY, BODY_Mayday,                   HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_193_JAWS), MALE,   IMG_MPC_JAWS, BODY_Jaws,                     HEAD_Male_Brosnan_Tuxedo, 1.199},
    {getStringID(LTITLE, TITLE_STR_195_ODDJOB), MALE,   IMG_MPC_ODDJOB, BODY_Oddjob,                   HEAD_Male_Brosnan_Tuxedo,0.78780001},
    {getStringID(LTITLE, TITLE_STR_192_BARONSAMEDI), MALE,   IMG_MPC_BARON, BODY_Baron_Samedi,             HEAD_Male_Brosnan_Tuxedo, 1.0},
    {getStringID(LTITLE, TITLE_STR_287_RUSSIANSOLDIER), MALE,   IMG_MPC_RANDOM, BODY_Russian_Soldier,          HEAD_Male_Mark, 1.0},
    {getStringID(LTITLE, TITLE_STR_288_RUSSIANINFANTRY), MALE,   IMG_MPC_RANDOM, BODY_Russian_Infantry,         HEAD_Male_Karl, 1.0},
    {getStringID(LTITLE, TITLE_STR_289_SCIENTIST), MALE,   IMG_MPC_RANDOM, BODY_Scientist_1_Male,         HEAD_Male_Dave_Dr_Doak, 1.0},
    {getStringID(LTITLE, TITLE_STR_289_SCIENTIST), FEMALE, IMG_MPC_RANDOM, BODY_Scientist_2_Female,       HEAD_Female_Sally, 1.0},
    {getStringID(LTITLE, TITLE_STR_290_RUSSIANCOMMANDANT), MALE,   IMG_MPC_RANDOM, BODY_Russian_Commandant,       HEAD_Male_Martin, 1.0},
    {getStringID(LTITLE, TITLE_STR_291_JANUSMARINE), MALE,   IMG_MPC_RANDOM, BODY_Janus_Marine,             HEAD_Male_Steve_Ellis, 1.0},
    {getStringID(LTITLE, TITLE_STR_292_NAVALOFFICER), MALE,   IMG_MPC_RANDOM, BODY_Naval_Officer,            HEAD_Male_Duncan, 1.0},
    {getStringID(LTITLE, TITLE_STR_293_HELICOPTERPILOT), MALE,   IMG_MPC_RANDOM, BODY_Helicopter_Pilot,         HEAD_Male_Pete, 1.0},
    {getStringID(LTITLE, TITLE_STR_294_STPETERSBURGARD), MALE,   IMG_MPC_RANDOM, BODY_St_Petersburg_Guard,      HEAD_Male_Ken, 1.0},
    {getStringID(LTITLE, TITLE_STR_295_CIVILIAN), FEMALE, IMG_MPC_RANDOM, BODY_Civilian_1_Female,        HEAD_Female_Marion_Rosika, 1.0},
    {getStringID(LTITLE, TITLE_STR_295_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_2,               HEAD_Male_Graeme, 1.0},
    {getStringID(LTITLE, TITLE_STR_295_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_3,               HEAD_Male_Grant, 1.0},
    {getStringID(LTITLE, TITLE_STR_295_CIVILIAN), MALE,   IMG_MPC_RANDOM, BODY_Civilian_4,               HEAD_Male_Dwayne, 1.0},
    {getStringID(LTITLE, TITLE_STR_296_SIBERIANGUARD), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Lee, 1.0},
    {getStringID(LTITLE, TITLE_STR_297_ARCTICCOMMANDO), MALE,   IMG_MPC_RANDOM, BODY_Arctic_Commando,          HEAD_Male_Chris, 1.0},
    {getStringID(LTITLE, TITLE_STR_296_SIBERIANGUARD), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_2,         HEAD_Male_Scott, 1.0},
    {getStringID(LTITLE, TITLE_STR_298_SIBERIANSPECIALFORCES), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Special_Forces,  HEAD_Male_Alan, 1.0},
    {getStringID(LTITLE, TITLE_STR_299_JUNGLECOMMANDO), MALE,   IMG_MPC_RANDOM, BODY_Jungle_Commando,          HEAD_Male_Joel, 1.0},
    {getStringID(LTITLE, TITLE_STR_300_JANUSSPECIALFORCES), MALE,   IMG_MPC_RANDOM, BODY_Janus_Special_Forces,     HEAD_Male_B, 1.0},
    {getStringID(LTITLE, TITLE_STR_301_MOONRAKERELITE), MALE,   IMG_MPC_RANDOM, BODY_Moonraker_Elite_1_Male,   HEAD_Male_Neil, 1.0},
    {getStringID(LTITLE, TITLE_STR_301_MOONRAKERELITE), FEMALE, IMG_MPC_RANDOM, BODY_Moonraker_Elite_2_Female, HEAD_Female_Vivien, 1.0},
    {getStringID(LTITLE, TITLE_STR_196_ROSIKA), FEMALE, IMG_MPC_RANDOM, BODY_Rosika,                   HEAD_Female_Marion_Rosika, 0.88529998},
    {getStringID(LTITLE, TITLE_STR_197_KARL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Karl, 1.0446},
    {getStringID(LTITLE, TITLE_STR_198_MARTIN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Martin, 1.0446},
    {getStringID(LTITLE, TITLE_STR_199_MARK), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Mark, 1.0446},
    {getStringID(LTITLE, TITLE_STR_200_DAVE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Dave_Dr_Doak, 1.0446},
    {getStringID(LTITLE, TITLE_STR_201_DUNCAN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Duncan, 1.0446},
    {getStringID(LTITLE, TITLE_STR_202_B), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_B, 1.0446},
    {getStringID(LTITLE, TITLE_STR_203_STEVEE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Steve_Ellis, 1.0446},
    {getStringID(LTITLE, TITLE_STR_204_GRANT), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Grant, 1.0446},
    {getStringID(LTITLE, TITLE_STR_205_GRAEME), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Graeme, 1.0446},
    {getStringID(LTITLE, TITLE_STR_206_KEN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Ken, 1.0446},
    {getStringID(LTITLE, TITLE_STR_207_ALAN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Alan, 1.0446},
    {getStringID(LTITLE, TITLE_STR_208_PETE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Pete, 1.0446},
    {getStringID(LTITLE, TITLE_STR_209_SHAUN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Shaun, 1.0446},
    {getStringID(LTITLE, TITLE_STR_210_DWAYNE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Dwayne, 1.0446},
    {getStringID(LTITLE, TITLE_STR_211_DES), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Des, 1.0446},
    {getStringID(LTITLE, TITLE_STR_212_CHRIS), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Chris, 1.0446},
    {getStringID(LTITLE, TITLE_STR_213_LEE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Lee, 1.0446},
    {getStringID(LTITLE, TITLE_STR_214_NEIL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Neil, 1.0446},
    {getStringID(LTITLE, TITLE_STR_215_JIM), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Jim, 1.0446},
    {getStringID(LTITLE, TITLE_STR_216_ROBIN), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Robin, 1.0446},
    {getStringID(LTITLE, TITLE_STR_217_STEVEH), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Steve_H, 1.0446},
    {getStringID(LTITLE, TITLE_STR_218_TERRORIST), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Terrorist, 1.0446},
    {getStringID(LTITLE, TITLE_STR_219_BIKER), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Biker, 1.0446},
    {getStringID(LTITLE, TITLE_STR_220_JOEL), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Joel, 1.0446},
    {getStringID(LTITLE, TITLE_STR_221_SCOTT), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Scott, 1.0446},
    {getStringID(LTITLE, TITLE_STR_222_JOE), MALE,   IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Male_Joe, 1.0446},
    {getStringID(LTITLE, TITLE_STR_223_SALLY), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Sally, 1.0446},
    {getStringID(LTITLE, TITLE_STR_224_MARION), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Marion_Rosika, 1.0446},
    {getStringID(LTITLE, TITLE_STR_225_MANDY), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Mandy, 1.0446},
    {getStringID(LTITLE, TITLE_STR_226_VIVIEN), FEMALE, IMG_MPC_RANDOM, BODY_Brosnan_Tuxedo,                   HEAD_Female_Vivien, 1.0446}
};
#endif


struct MP_handicap_menu MP_handicap_table[] = {
    {getStringID(LTITLE, TITLE_STR_61_HERO), 0, 10.0},       // "Health -10\n(Hero)"
    {getStringID(LTITLE, TITLE_STR_62_VET4), 0, 2.8560996},  // "Health -4\n(Veteran)"
    {getStringID(LTITLE, TITLE_STR_63_VET3), 0, 2.1969998},  // "Health -3\n(Veteran)"
    {getStringID(LTITLE, TITLE_STR_64_VET2), 0, 1.6899998},  // "Health -2\n(Veteran)"
    {getStringID(LTITLE, TITLE_STR_65_VET1), 0, 1.3},        // "Health -1\n(Veteran)"
    {getStringID(LTITLE, TITLE_STR_66_HEALTH_NORMAL), 0, 1.0},        // "Health +0\n(Normal)"
    {getStringID(LTITLE, TITLE_STR_67_NOVICE1), 0, 0.76923078}, // "Health +1\n(Novice)"
    {getStringID(LTITLE, TITLE_STR_68_NOVICE2), 0, 0.59171599}, // "Health +2\n(Novice)"
    {getStringID(LTITLE, TITLE_STR_69_NOVICE3), 0, 0.45516616}, // "Health +3\n(Novice)"
    {getStringID(LTITLE, TITLE_STR_70_NOVICE4), 0, 0.35012782}, // "Health +4\n(Novice)"
    {getStringID(LTITLE, TITLE_STR_71_ROOKIE), 0, 0.1}         // "Health +10\n(Rookie)"
};

struct MP_controller_configuration_menu MP_controller_configuration_table[] = {
    {getStringID(LTITLE, TITLE_STR_277_11HONEY), 0, 1}, //1.1 Honey*
    {getStringID(LTITLE, TITLE_STR_278_12SOLITAIRE), 1, 1}, //1.2 Solitaire*
    {getStringID(LTITLE, TITLE_STR_279_13KISSY), 2, 1}, //1.3 Kissy*
    {getStringID(LTITLE, TITLE_STR_280_14GOODNIGHT), 3, 1}, //1.4 Goodnight*
    {getStringID(LTITLE, TITLE_STR_281_21PLENTY), 4, 2}, //2.1 Plenty*
    {getStringID(LTITLE, TITLE_STR_282_22GALORE), 5, 2}, //2.2 Galore*
    {getStringID(LTITLE, TITLE_STR_283_23DOMINO), 6, 2}, //2.3 Domino*
    {getStringID(LTITLE, TITLE_STR_284_24GOODHEAD), 7, 2}  //2.4 Goodhead*
};

struct MP_sight_aim_settings mp_sight_adjust_table[] = {
    {getStringID(LTITLE, TITLE_STR_72_SOFFAOFF), 0, 0}, // "Sight OFF, Auto Aim OFF"
    {getStringID(LTITLE, TITLE_STR_73_SONAOFF), 1, 0}, // "Sight ON, Auto Aim OFF"
    {getStringID(LTITLE, TITLE_STR_74_SOFFAON), 0, 1}, // "Sight OFF, Auto Aim ON"
    {getStringID(LTITLE, TITLE_STR_75_SONAON), 1, 1}  // "Sight ON, Auto Aim ON"
};

s32 selected_num_players = 0;
s32 player_char[MAX_PLAYER_COUNT] = { -1, -1, -1, -1 };
s32 MP_stage_selected = MP_STAGE_TEMPLE;
s32 game_length = LEN_10MIN; //10minutes
s32 aim_sight_adjustment = 3; //"Sight ON, Auto Aim ON"
s32 scenario = SCENARIO_NORMAL;

s32 unlock_stage_select = TRUE;
s32 unlock_game_length = TRUE;
s32 unlock_chars = TRUE;
s32 unlock_weapon_select = TRUE;
s32 unlock_handicap = TRUE;
s32 unlock_control_style = TRUE;
s32 unlock_aim_sight = TRUE;

u32 D_8002B560 = 0;

s16 solo_target_time_array[20][3] = {
    {0, 160, 0}, // Dam
    {0, 0, 125}, // Facility
    {300, 0, 0}, // Runway
    {0, 210, 0}, // Surface 1
    {0, 0, 240}, // Bunker 1
    {180, 0, 0}, // Silo
    {0, 270, 0}, // Frigate
    {0, 0, 255}, // Surface 2
    {90, 0, 0},  // Bunker 2
    {0, 195, 0}, // Statue
    {0, 0, 80},  // Archives
    {105, 0, 0}, // Streets
    {0, 100, 0}, // Depot
    {0, 0, 325}, // Train
    {225, 0, 0}, // Jungle
    {0, 600, 0}, // Control
    {0, 0, 570}, // Caverns
    {135, 0, 0}, // Cradle
    {0, 540, 0}, // Aztec
    {0, 0, 360}  // Egyptian
};

s32 totalunlockedcheats = 0;
s32 cheathighlighted = 0; // 0x8002B5E0


u32 MP_menu_selected_option = 0;
s32 intro_character_index = 0;
u32 randomly_selected_intro_animation = ANIM_idle;
u32 intro_animation_count = 0;
struct Model *cast_model = NULL;
struct Model *cast_model_weapon = NULL;
u32 full_actor_intro = 0;

struct intro_char intro_char_table[] = {
    {BODY_Brosnan_Tuxedo,             HEAD_Male_Brosnan_Tuxedo, getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_228_THEACTORS),             getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Special_Operations_Uniform, HEAD_Male_Brosnan_Boiler, getStringID(LTITLE, TITLE_STR_229_STARRING),      getStringID(LTITLE, TITLE_STR_232_007),                   getStringID(LTITLE, TITLE_STR_233_JAMESBOND),        0, 0},
    {BODY_Natalya_Skirt,              HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_229_STARRING),      getStringID(LTITLE, TITLE_STR_234_NATALYASIMONOVA),       getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {BODY_Trevelyan_006,              HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_229_STARRING),      getStringID(LTITLE, TITLE_STR_235_006),                   getStringID(LTITLE, TITLE_STR_236_ALECTREVELYAN),    0, 0},
    {BODY_Xenia,                      HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_237_JANUSOPPERATIVE),       getStringID(LTITLE, TITLE_STR_238_XENIAONPTOPP),     0, 0},
    {BODY_Ourumov,                    HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_239_GENERAL),               getStringID(LTITLE, TITLE_STR_240_ARKADYOURUMOV),    0, 0},
    {BODY_Boris,                      HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_241_BORISGRISHENKO),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {BODY_Valentin_,                  HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_242_EXKGBAGENT),            getStringID(LTITLE, TITLE_STR_243_VELENTINZUKOVSKY), 0, 0},
    {BODY_Siberian_Guard_1_Mishkin,   HEAD_Male_Mishkin,        getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_244_DEFENSEMINISTER),       getStringID(LTITLE, TITLE_STR_245_DIMITRIMISHKIN),   0, 0},
    {BODY_Russian_Soldier,            HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_253_RUSSIANSOLDIER),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Russian_Infantry,           HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_252_RUSSIANINFANTRY),       getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Scientist_1_Male,           HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_263_SCIENTIST),             getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Scientist_2_Female,         HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_263_SCIENTIST),             getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Russian_Commandant,         HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_256_RUSSIANCOMMANDANT),     getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Janus_Marine,               HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_254_JANUSMARINE),           getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Naval_Officer,              HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_257_NAVALOFFICER),          getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Helicopter_Pilot,           HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_262_HELICOPTERPILOT),       getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_St_Petersburg_Guard,        HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_251_STPETERSBURGGUARD),     getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Civilian_1_Female,          HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_264_CIVILIAN),              getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Civilian_2,                 HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_264_CIVILIAN),              getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Civilian_3,                 HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_264_CIVILIAN),              getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Civilian_4,                 HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_264_CIVILIAN),              getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Siberian_Guard_1_Mishkin,   HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD),         getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Arctic_Commando,            HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_259_ARCTICCOMMANDO),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Siberian_Guard_2,           HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD),         getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Siberian_Special_Forces,    HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_260_SIBERIANSPECIALFORCES), getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Jungle_Commando,            HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_250_JUNGLECOMMANDO),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Janus_Special_Forces,       HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_255_JANUSSPECIALFORCES),    getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Moonraker_Elite_1_Male,     HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Moonraker_Elite_2_Female,   HEAD_RANDOM,              getStringID(LTITLE, TITLE_STR_227_LF),            getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE),        getStringID(LTITLE, TITLE_STR_227_LF),               0, 1},
    {BODY_Mayday,                     HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_231_GUESTSTAR),     getStringID(LTITLE, TITLE_STR_246_MAYDAY),                getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {BODY_Jaws,                       HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_231_GUESTSTAR),     getStringID(LTITLE, TITLE_STR_247_JAWS),                  getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {BODY_Oddjob,                     HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_231_GUESTSTAR),     getStringID(LTITLE, TITLE_STR_248_ODDJOB),                getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {BODY_Baron_Samedi,               HEAD_FIXED,               getStringID(LTITLE, TITLE_STR_231_GUESTSTAR),     getStringID(LTITLE, TITLE_STR_249_BERONSAMEDI),           getStringID(LTITLE, TITLE_STR_227_LF),               0, 0},
    {0xFFFFFFFF,                      0,                        0,                                                0,                                                        0,                                                   0, 0}
};

struct intro_animation intro_animation_table[] = {
    {ANIM_spotting_bond, 98.0, 1.0, 0},
    {ANIM_fire_standing_draw_one_handed_weapon_fast, 21.0, 1.0, 1},
    {ANIM_fire_standing_draw_one_handed_weapon_slow, 26.0, 1.0, 1},
    {ANIM_fire_step_right_one_handed_weapon, 0.0, 1.0, 1},
    {ANIM_fire_kneel_forward_one_handed_weapon_fast, 0.0, 1.0, 1},
    {ANIM_running_one_handed_weapon, 0.0, 0.91000003, 1},
    {ANIM_draw_one_handed_weapon_and_stand_up, 31.0, 1.0, 1},
    {ANIM_aim_one_handed_weapon_left_right, 0.0, 1.0, 1},
    {ANIM_cock_one_handed_weapon_and_turn_around, 0.0, 1.0, 1},
    {ANIM_cock_one_handed_weapon_turn_around_and_stand_up, 0.0, 1.0, 1},
    {ANIM_draw_one_handed_weapon_and_turn_around, 0.0, 1.0, 1},
    {ANIM_drop_weapon_and_show_fight_stance, 248.0, 1.0, 0},
    {ANIM_laughing_in_disbelief, 150.0, 1.0, 0},
    {ANIM_fire_hip_forward_one_handed_weapon, 0.0, 0.89999998, 1},
    {ANIM_fire_standing_left_one_handed_weapon_fast, 0.0, 0.89999998, 1},
    {ANIM_fire_kneel_left_one_handed_weapon_fast, 0.0, 0.89999998, 1},
    {ANIM_draw_one_handed_weapon_and_look_around, 51.0, 1.0, 1},
    {ANIM_aim_one_handed_weapon_left, 0.0, 0.89999998, 1},
    {ANIM_aim_one_handed_weapon_right, 0.0, 0.89999998, 1},
    {ANIM_conversation, 37.0, 1.0, 2},
    {ANIM_conversation_listener, 300.0, 1.0, 2},
    {ANIM_conversation_cleaned, 120.0, 1.0, 2},
    {0xFFFFFFFF, 0.0, 0.0, 0}
};

struct coord3d zeroCoord = { 0 };

#define INTRO_RANDOM_RIFLE_LEN 6
struct intro_random_rifles
{
    PROP props[INTRO_RANDOM_RIFLE_LEN];
};

struct intro_random_rifles random_rifles_in_intro = {
    PROP_CHRKALASH,
    PROP_CHRM16,
    PROP_CHRFNP90,
    PROP_CHRAUTOSHOT,
    PROP_CHRGRENADELAUNCH,
    PROP_CHRSNIPERRIFLE
};

#define INTRO_RANDOM_PISTO_LEN 10
struct intro_random_pistols
{
    PROP props[INTRO_RANDOM_PISTO_LEN];
};

struct intro_random_pistols random_pistols_in_intro = {
    PROP_CHRWPPK,
    PROP_CHRWPPKSIL,
    PROP_CHRSKORPION,
    PROP_CHRUZI,
    PROP_CHRUZI,
    PROP_CHRTT33,
    PROP_CHRTT33,
    PROP_CHRRUGER,
    PROP_CHRLASER,
    PROP_CHRGOLDEN
};

struct coord3d cast_camera_pos    = { 0.0f, 0.0f, 1.0f }; // campos in constructor_menu18_displaycast is set to this, but is then immediately overwritten, so the values here have no effect.
struct coord3d cast_camera_target = { 0.0f, 0.0f, 0.0f };
struct coord3d cast_camera_up     = { 0.0f, 1.0f, 0.0f }; // Display cast character up vector

ModelRenderData cast_renderdata_default = { NULL,
                                            TRUE,
                                            0x00000003,
                                            NULL,

                                            NULL,
                                            0,
                                            0,
                                            0,

                                            0,
                                            0,
                                            0,
                                            0,

                                            0,
                                           {0, 0, 0, 0},
                                           {0, 0, 0, 0},
                                           CULLMODE_BOTH};


struct coord3d cast_camera_offset = { 0.0f, 40.0f, 25.0f }; // vec in constructor_menu18_displaycast is initialized to this, but then gets overwritten before it's read, so these values don't have any effect.

u32 D_8002BAE8 = 0; // unused
u32 D_8002BAEC = 1; // unused

u16 color_palette_entries_50_percent[] = {1, 0x1F, 0x3C1, 0x3DF, 0x7801, 0x781F, 0x7BC1, 0x7BDF};


// forward declarations

Gfx* frontAddPreviousTabText(Gfx* DL);
s32 check_if_stage_completed_on_difficulty(int stage, DIFFICULTY difficulty);
s32 get_highest_unlocked_difficulty_for_level(s32 arg0);
Gfx *constructor_menu00_legalscreen(Gfx *DL);
Gfx *constructor_menu01_nintendo(Gfx *DL);
Gfx *constructor_menu02_rareware(Gfx *DL);
Gfx *constructor_menu03_eye(Gfx *DL);
Gfx *constructor_menu04_goldeneyelogo(Gfx *DL);
Gfx *constructor_menu05_fileselect(Gfx *DL);
Gfx *constructor_menu06_modesel(Gfx *DL);
Gfx *constructor_menu07_missionsel(Gfx *DL);
Gfx *constructor_menu08_difficulty(Gfx *DL);
Gfx *constructor_menu09_007options(Gfx *DL);
Gfx *constructor_menu0A_briefing(Gfx *DL);
Gfx *constructor_menu0C_missionfailed(Gfx *DL);
Gfx *constructor_menu0D_missioncomplete(Gfx *DL);
Gfx *constructor_menu0E_mpoptions(Gfx *DL);
Gfx *constructor_menu0F_mpcharsel(Gfx *DL);
Gfx *constructor_menu10_mphandicap(Gfx *DL);
Gfx *constructor_menu11_mpcontrol(Gfx *DL);
Gfx *constructor_menu12_mpstage(Gfx *DL);
Gfx *constructor_menu13_mpscenario(Gfx *DL);
Gfx *constructor_menu14_mpteams(Gfx *DL);
Gfx *constructor_menu15_cheat(Gfx *DL);
Gfx *constructor_menu16_nocontrollers(Gfx *DL);
Gfx *constructor_menu17_switchscreens(Gfx *DL);
Gfx *constructor_menu18_displaycast(Gfx *DL);
Gfx *constructor_menu19_spectrum(Gfx *DL);
void disable_all_switches(Model *arg0);
void set_item_visibility_in_objinstance(Model* objinstance, s32 item, s32 mode);
void set_cursor_to_stage_solo(LEVEL_SOLO_SEQUENCE level);
Gfx *display_aligned_white_text_to_screen(Gfx *dl, s32 arg1, s32 arg2, s32 halign, s32 valign, u8 *arg5, s32 arg6, s32 arg7);
void setCursorPOSforMode(int mode);
void set_cursor_pos_difficulty(int difficulty);

// end forward declarations.


Gfx *frontPrintText(Gfx *gdl, s32 *x, s32 *y, s8 *text, s32 second_font_table, s32 first_font_table, s32 arg6, s32 view_x, s32 view_y, s32 arg9, s32 arga)
{
    if (j_text_trigger != 0)
    {
        gdl = textRenderOutlined(
            gdl,
            x,
            y,
            text,
            second_font_table,
            first_font_table,
            arg6,
            (textglowR.r << 0x18) | (textglowG.r << 0x10) | (textglowB.r << 8) | textglowA.r,
            view_x,
            view_y,
            arg9,
            arga);
    }
    else
    {
        gdl = textRender(
            gdl,
            x,
            y,
            text,
            second_font_table,
            first_font_table,
            arg6,
            view_x,
            view_y,
            arg9,
            arga);
    }

    return gdl;
}


s32 frontCheckIfCheatIsUnlocked(s32 cheat)
{
    switch(cheat)
    {
        case CHEAT_EXTRA_MP_CHARS:
        case CHEAT_MAXAMMO:
        case CHEAT_DEBUG_UNK5:
        case CHEAT_DEACTIVATE_INVINCIBILITY:
        case CHEAT_LINEMODE:
        case CHEAT_2X_HEALTH:
        case CHEAT_2X_ARMOR:
        case CHEAT_EXTRA_WEAPONS:
        case CHEAT_10X_HEALTH:
        case CHEAT_BONDPHASE:
        case CHEAT_DEBUG_POS:
        case CHEAT_UNLOCK_PAINTBALL:
        case CHEAT_UNLOCK_INVINCIBLE:
        case CHEAT_UNLOCK_DKMODE:
        case CHEAT_UNLOCK_2XGL:
        case CHEAT_UNLOCK_2XRL:
        case CHEAT_UNLOCK_TURBO:
        case CHEAT_UNLOCK_NORADAR:
        case CHEAT_UNLOCK_TINY:
        case CHEAT_UNLOCK_2XTKNIFE:
        case CHEAT_UNLOCK_FAST:
        case CHEAT_UNLOCK_INVIS:
        case CHEAT_UNLOCK_ENEMYRL:
        case CHEAT_UNLOCK_SLOW:
        case CHEAT_UNLOCK_SILVERPPK:
        case CHEAT_UNLOCK_2XHKNIFE:
        case CHEAT_UNLOCK_INFAMMO:
        case CHEAT_UNLOCK_2XFNP0:
        case CHEAT_UNLOCK_GOLDPPK:
        case CHEAT_UNLOCK_2XLASER:
        case CHEAT_UNLOCK_ALLGUNS:
        case CHEAT_UNLOCK_DAM:
        case CHEAT_UNLOCK_FACILITY:
        case CHEAT_UNLOCK_RUNWAY:
        case CHEAT_UNLOCK_SURFACE:
        case CHEAT_UNLOCK_BUNKER:
        case CHEAT_UNLOCK_SILO:
        case CHEAT_UNLOCK_FRIGATE:
        case CHEAT_UNLOCK_SURFACE2:
        case CHEAT_UNLOCK_BUNKER2:
        case CHEAT_UNLOCK_STATUE:
        case CHEAT_UNLOCK_ARCHIVES:
        case CHEAT_UNLOCK_STREETS:
        case CHEAT_UNLOCK_DEPOT:
        case CHEAT_UNLOCK_TRAIN:
        case CHEAT_UNLOCK_JUNGLE:
        case CHEAT_UNLOCK_CONTROL:
        case CHEAT_UNLOCK_CAVERNS:
        case CHEAT_UNLOCK_CRADLE:
        case CHEAT_UNLOCK_AZTEK:
        case CHEAT_UNLOCK_EGYPT:
            return 0;

        case CHEAT_INVINCIBILITY:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_FACILITY);

        case CHEAT_ALLGUNS:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_EGYPT);

        case CHEAT_NO_RADAR_MP:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_FRIGATE);

        case CHEAT_FAST_ANIMATION:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_STATUE);

        case CHEAT_INVISIBILITY:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_ARCHIVES);

        case CHEAT_INFINITE_AMMO:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_CONTROL);

        case CHEAT_DK_MODE:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_RUNWAY);

        case CHEAT_TINY_BOND:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_SURFACE2);

        case CHEAT_SLOW_ANIMATION:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_DEPOT);

        case CHEAT_PAINTBALL:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_DAM);

        case CHEAT_SILVER_PP7:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_TRAIN);

        case CHEAT_GOLD_PP7:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_CRADLE);

        case CHEAT_ENEMY_ROCKETS:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_STREETS);

        case CHEAT_2X_ROCKET_LAUNCHER:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_BUNKER1);

        case CHEAT_2X_GRENADE_LAUNCHER:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_SURFACE1);

        case CHEAT_2X_RCP90:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_CAVERNS);

        case CHEAT_2X_THROWING_KNIFE:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_BUNKER2);

        case CHEAT_2X_HUNTING_KNIFE:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_JUNGLE);

        case CHEAT_2X_LASER:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_AZTEC);

        case CHEAT_TURBO_MODE:
            return fileGetIsCheatUnlocked( fileGetSaveForFoldernum(selected_folder_num), SP_LEVEL_SILO);

        case CHEAT_MAGNUM:
            return fileIsCradleCompletedForFolder(selected_folder_num);

        case CHEAT_LASER:
            return fileIsAztecCompletedOnSecretOr00ForFolder(selected_folder_num);

        case CHEAT_GOLDEN_GUN:
            return fileIsEgyptCompletedOn00ForFolder(selected_folder_num);

        default:
            do {/* WARNING: Do nothing block with infinite loop */
            } while( 1 );
        }
}


int frontGetPlayersFavoriteWeaponInHand(int player,int hand) {
    return get_ptr_long_watch_text_for_item(array_favweapon[player][hand]);
}




void frontUpdateControlStickPosition(void) {
    s8 stickx = joyGetStickX(PLAYER_1);
    s8 sticky = -joyGetStickY(PLAYER_1);


    if (stickx < -5) {
        stickx = (stickx + 5);
    }
    else  if (stickx >= 6) {
        stickx = (stickx - 5);
    }
    else {
        stickx = 0;
    }

    if (stickx >= 71) {
        stickx = 70;
    }
    else {
        if (stickx < -70) {
            stickx = -70;
        }
    }

    if (sticky < -5) {
        sticky = (sticky + 5);
    }
    else  if (sticky >= 6) {
        sticky = (sticky - 5);
    }
    else {
        sticky = 0;
    }

    if (sticky >= 71) {
        sticky = 70;
    }
    else {
        if (sticky < -70) {
            sticky = -70;
        }
    }

    if (stickx > 0) {
        cursor_h_pos += (f32)(( (f32)stickx * 0.075f + 0.5f) * g_GlobalTimerDelta);
    }
    else if (stickx < 0) {
        cursor_h_pos += (f32)(( (f32)stickx * 0.075f - 0.5f) * g_GlobalTimerDelta);
    }

    if ((getPlayer_c_screenleft() + getPlayer_c_screenwidth() - 20.0f) < cursor_h_pos) {
        cursor_h_pos = (getPlayer_c_screenleft() + getPlayer_c_screenwidth() - 20.0f);
    }
    else {
        if (cursor_h_pos < getPlayer_c_screenleft() + 20.0f) {
            cursor_h_pos = getPlayer_c_screenleft() + 20.0f;
        }
    }

    if (sticky > 0) {
        cursor_v_pos += (f32)(( (f32)sticky * 0.075f + 0.5f) * g_GlobalTimerDelta);
    }
    else if (sticky < 0) {
        cursor_v_pos += (f32)(( (f32)sticky * 0.075f - 0.5f) * g_GlobalTimerDelta);
    }

    if ((getPlayer_c_screentop() + getPlayer_c_screenheight() - 20.0f) < cursor_v_pos) {
        cursor_v_pos = (getPlayer_c_screentop() + getPlayer_c_screenheight() - 20.0f);
        return;
    }
    if (cursor_v_pos < (getPlayer_c_screentop() + 20.0f)) {
        cursor_v_pos = (getPlayer_c_screentop() + 20.0f);
    }
}



Gfx *frontDrawCursor(Gfx *DL)
{
    f32 xypos[2];
    f32 halfedxy[2];
    sImageTableEntry *image;
    s32 unused;
    s32 option;

    option = folder_selection_screen_option_icon;
    if (option == 0) {
        image = crosshairimage;
    }
    else if (option == 1) {
        image = mainfolderimages + IMG_COPY; //COPY
    }
    else if (option == 2) {
        image = mainfolderimages + IMG_DEL;
    }

    texSelect(&DL, image, 4, 0, 0);

    xypos[0] = floorFloat(cursor_h_pos + 0.5f);
    xypos[1] = floorFloat(cursor_v_pos + 0.5f);

    halfedxy[0] = image->width * 0.5f;
    halfedxy[1] = image->height * 0.5f;

    display_image_at_position(&DL, &xypos, &halfedxy, image->width, image->height, 0, 0, 1, 255, 255, 255, 220, (image->level > 0), 0);

    return DL;
}


//********************************************************************************************************
// TABS
//********************************************************************************************************

Gfx* frontAddStartTabText(Gfx* DL)
{
    s32 v;
    s32 h;

    s32 textWidth;
    s32 textHeight;

    g_textPtrTAB1 = langGet(getStringID(LTITLE, TITLE_STR_04_START));
    setTextSpacingInverted(TRUE);
    textHeight = 0;
    textWidth = 0;
    //text is sideways so textWidth and textHeight are flipped
    textMeasure(&textWidth, &textHeight, g_textPtrTAB1, ptrFontBankGothicChars, ptrFontBankGothic, 0);
    v = STARTTAB_TEXT_TOP;
    h = TABS_RIGHT_EDGE - (textWidth / 2);

    if (tab_start_highlight)
    {
        DL = microcode_constructor_related_to_menus(DL, (h - textWidth) + 1, STARTTAB_TEXT_TOP, h, STARTTAB_TEXT_BOTTOM, 50);
    }

    setTextOrientation(ROT_90CW);

    v = STARTTAB_TEXT_HALF - (textHeight / 2);
    DL = textRender(DL, &v, &h, g_textPtrTAB1, ptrFontBankGothicChars, ptrFontBankGothic, 0xFF, viGetY(), viGetX(), 0, 0);
    setTextOrientation(ROT_NORMAL);
    setTextSpacingInverted(FALSE);
    return DL;
}


s32 frontCheckCursorOnStartTab(void)
{
    if ((TABS_LEFT_EDGE < cursor_h_pos) && (cursor_v_pos <= STARTTAB_TAB_BOTTOM))
    {
        return TRUE;
    }

    return FALSE;
}


Gfx* frontAddPreviousTabText(Gfx* DL)
{
    s32 v;
    s32 h;

    s32 textWidth;
    s32 textHeight;

    g_textPtrTAB3 = langGet(getStringID(LTITLE, TITLE_STR_06_PREVIOUS));
    setTextSpacingInverted(TRUE);
    textHeight = 0;
    textWidth = 0;
    //text is sideways so textWidth and textHeight are flipped
    textMeasure(&textWidth, &textHeight, g_textPtrTAB3, ptrFontBankGothicChars, ptrFontBankGothic, 0);
    v = PREVTAB_TEXT_TOP;
    h = TABS_RIGHT_EDGE - (textWidth / 2);

    if (tab_prev_highlight != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, (h - textWidth) + 1, PREVTAB_TEXT_TOP, h, PREVTAB_TEXT_BOTTOM, 50);
    }

    setTextOrientation(ROT_90CW);

    v = PREVTAB_TEXT_HALF - (textHeight / 2);
    DL = textRender(DL, &v, &h, g_textPtrTAB3, ptrFontBankGothicChars, ptrFontBankGothic, 0xFF, viGetY(), viGetX(), 0, 0);
    setTextOrientation(ROT_NORMAL);
    setTextSpacingInverted(FALSE);

    return DL;
}


u32 frontCheckCursorOnPreviousTab(void)
{
    if ((TABS_LEFT_EDGE < cursor_h_pos) && (PREVTAB_TAB_TOP < cursor_v_pos))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void frontSetCursorPositionToNextTab(void)
{
    cursor_h_pos = NEXTTAB_CURSOR_HPOS;
    cursor_v_pos = NEXTTAB_CURSOR_VPOS;
}


Gfx* frontAddNextTabText(Gfx* DL)
{
    s32 v;
    s32 h;

    s32 textWidth;
    s32 textHeight;

    g_textPtrTAB2 = langGet(getStringID(LTITLE, TITLE_STR_05_NEXT)); //"NEXT\n"
    setTextSpacingInverted(TRUE);
    textHeight = 0;
    textWidth = 0;
    //text is sideways so textWidth and textHeight are flipped
    textMeasure(&textWidth, &textHeight, g_textPtrTAB2, ptrFontBankGothicChars, ptrFontBankGothic, 0);
    v = NEXTTAB_TEXT_TOP;
    h = TABS_RIGHT_EDGE - (textWidth / 2);

    if (tab_next_highlight != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, (h - textWidth) + 1, NEXTTAB_TEXT_TOP, h, NEXTTAB_TEXT_BOTTOM, 50);
    }

    setTextOrientation(ROT_90CW);

    v = NEXTTAB_TEXT_HALF - (textHeight / 2);
    DL = textRender(DL, &v, &h, g_textPtrTAB2, ptrFontBankGothicChars, ptrFontBankGothic, 0xFF, viGetY(), viGetX(), 0, 0);
    setTextOrientation(ROT_NORMAL);
    setTextSpacingInverted(FALSE);
    return DL;
}


u32 frontCheckCursorOnNextTab(void)
{
    if (((TABS_LEFT_EDGE < cursor_h_pos) && (NEXTTAB_TAB_TOP < cursor_v_pos)) && (cursor_v_pos <= PREVTAB_TAB_TOP))
    {
        return TRUE;
    }

    return FALSE;
}



//********************************************************************************************************
//BEGIN MENU SECTIONS
//********************************************************************************************************

//********************************************************************************************************
//LEGAL SCREEN
//********************************************************************************************************
void init_menu00_legalscreen(void)
{
    s32 padding;
    struct coord3d pos;

    musicTrack1Stop();
    maybe_is_in_menu = TRUE;
    g_MenuTimer = 0;
    pos = legalpage_pos;
    load_object_fill_header(PitemZ_entries[PROP_LEGALPAGE].header, PitemZ_entries[PROP_LEGALPAGE].filename, ptr_logo_and_walletbond_DL, 0x3c000, 0);
    modelCalculateRwDataLen(PitemZ_entries[PROP_LEGALPAGE].header);

    logoinst = modelmgrInstantiateModel(PitemZ_entries[PROP_LEGALPAGE].header);
    #ifdef DEBUG
        assert(logoinst);
    #endif
    modelSetScale(logoinst, 1.0f);
    setsuboffset(logoinst, &pos);
    fileValidateSaves();
}


void update_menu00_legalscreen(void)
{
    is_first_time_on_legal_screen = FALSE;
    clear_model_obj(logoinst);
}


void interface_menu00_legalscreen(void)
{
#ifdef REFRESH_PAL
#define MENU_LEGALSCREEN_MENU_TIMER_MAX (50*4+1)
#else
#define MENU_LEGALSCREEN_MENU_TIMER_MAX (60*4+1)
#endif

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);
#if defined(ISGOLDFINGER) || defined(USEEXPANSION)
    if (osGetMemSize != 0x00800000)
    {
        frontChangeMenu(MENU_NO_CONTROLLERS, TRUE); //double up as No expansion pak window
        return;
    }
#endif
    g_MenuTimer += g_ClockTimer;

    if (g_MenuTimer >= MENU_LEGALSCREEN_MENU_TIMER_MAX)
    {
        if ((joyGetControllerCount() < 1) && (is_first_time_on_legal_screen))
        {
            frontChangeMenu(MENU_NO_CONTROLLERS, TRUE);
        }
        else
        {
            frontChangeMenu(MENU_NINTENDO_LOGO, TRUE);
        }
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON) && (!is_first_time_on_legal_screen))
    {
        if (!is_first_time_on_main_menu)
        {
            frontChangeMenu(MENU_FILE_SELECT, TRUE);
        }
        else
        {
            frontChangeMenu(MENU_NINTENDO_LOGO, TRUE);
        }
    }
}


/**
 * Render a string of standard text on the legal screen e.g. "TWYCROSS BOARD OF GAME CLASSIFICATION"
 */
Gfx *display_aligned_white_text_to_screen(Gfx *dl, s32 arg1, s32 arg2, s32 halign, s32 valign, u8 *text, s32 arg6, s32 arg7)
{
    s32 sp4C;
    s32 sp48;
    s32 x;
    s32 y;

    sp48 = 0;
    sp4C = 0;
    textMeasure(&sp4C, &sp48, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    x = arg1 - ((s32) (halign * sp48) / 2);
    y = arg2 - ((s32) (valign * sp4C) / 2);

    return textRender(dl, &x, &y, text, arg6, arg7, -1, viGetX(), viGetY(), 0, 0);
}


Gfx *constructor_menu00_legalscreen(Gfx *DL)
{
    struct legal_screen_text *legal_text_end;
    struct ModelRenderData renderdata;
    Mtxf *temp;
    Mtxf lookatmtx;
    s32 i;
    u8 *txt;
    Mtxf tmpmtx;
    struct legal_screen_text *legal_text_ptr;

    renderdata = legalscreen_MRD;
    
    DL = clear_framebuffer_black(DL);
    
    matrix_4x4_set_lookat_target(&lookatmtx, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, legal_text_ptr->v_pos * 0.0f);
    
    renderdata.basemtx = &lookatmtx;
    renderdata.mtxlist = (Mtxf *) dynAllocate(logoinst->obj->numMatrices << 6);
    
    matrix_4x4_copy(&lookatmtx, renderdata.mtxlist);
    
    logoinst->render_pos = (union RenderPosView *) renderdata.mtxlist;
    
    modelUpdateNodeRelations(logoinst);
    
    renderdata.flags = 3;
    renderdata.zbufferenabled = 0;
    renderdata.gdl = DL;
    
    subdraw(&renderdata, logoinst);
    
    DL = renderdata.gdl;
    
    for (i = 0; i < logoinst->obj->numMatrices; i++)
    {
        matrix_4x4_copy((Mtxf *)&((s8 *)logoinst->render_pos)[i * 0x40], &tmpmtx);
        matrix_4x4_f32_to_s32(&tmpmtx, &((Mtxf *) logoinst->render_pos)[i]);
    }
    
    DL = microcode_constructor(DL);
    
    legal_text_ptr = legalpage_text_array;
    legal_text_end = (struct legal_screen_text *)&legalscreen_MRD;
    
    do
    {
        DL = display_aligned_white_text_to_screen(DL, legal_text_ptr->h_pos, legal_text_ptr->v_pos, legal_text_ptr->halign, legal_text_ptr->valign, langGet(legal_text_ptr->txtID), ptrFontZurichBoldChars, ptrFontZurichBold);
        legal_text_ptr++;
    }
    while (legal_text_ptr < legal_text_end);
    
    return DL;
}


void reset_menutimer(void) {
    g_MenuTimer = 0;
}

void dummy7F00AAF8(void) {
    // (function likely stub)
}




//********************************************************************************************************
//SWITCH SCREEN
//********************************************************************************************************
void interface_menu17_switchscreens(void)
{
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    g_MenuTimer++;
    if ((g_MenuTimer >= 4) && (!spectrum_related_flag) && (!is_emulating_spectrum))
    {
        maybe_prev_menu = menu_update;
        menu_update = MENU_INVALID;
    }
}


Gfx * constructor_menu17_switchscreens(Gfx * DL)
{
    return clear_framebuffer_black(DL);
}





//********************************************************************************************************
//NINTENDO LOGO
//********************************************************************************************************
void init_menu01_nintendo(void)
{
    struct coord3d pos;

    g_MenuTimer = 0;
    pos = nintendologo_pos;
    load_object_fill_header(PitemZ_entries[PROP_NINTENDOLOGO].header, PitemZ_entries[PROP_NINTENDOLOGO].filename, ptr_logo_and_walletbond_DL, 0x3c000, 0);
    modelCalculateRwDataLen(PitemZ_entries[PROP_NINTENDOLOGO].header);
    logoinst = modelmgrInstantiateModel(PitemZ_entries[PROP_NINTENDOLOGO].header);
    modelSetScale(logoinst, 1.0f);
    setsuboffset(logoinst, &pos);
    musicTrack1Play(M_INTROSWOOSH);
    maybe_is_in_menu = TRUE;
    ninLogoRotRate = -1.39626348019f;
    ninLogoScale = 0.0183333326131f;
}




void update_menu01_nintendo(void)
{
    clear_model_obj(logoinst);
}




void interface_menu01_nintendo(void)
{
#ifdef REFRESH_PAL
/*~= 8.32 * 50 + 1*/
#define NINTENDO_TIMER_MAX 417
#else
/*~= 8.32 * 60 + 1*/
#define NINTENDO_TIMER_MAX 501
#endif

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    g_MenuTimer += g_ClockTimer;

    if (g_MenuTimer >= NINTENDO_TIMER_MAX)
    {
        frontChangeMenu(MENU_RAREWARE_LOGO, TRUE);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON))
    {
        if (!is_first_time_on_main_menu)
        {
            frontChangeMenu(MENU_FILE_SELECT, TRUE);
        }
        else
        {
            prev_keypresses = TRUE;
            frontChangeMenu(MENU_RAREWARE_LOGO, TRUE);
        }
    }
}


Gfx *constructor_menu01_nintendo(Gfx *DL)
{
    ModelRenderData ninlogo;
    s32 padding;
    s32 ambiantlight;
    Mtxf ninlogoMtxf;
    s32 i;

    ninlogo = nintendologo_MRD;

    DL = clear_framebuffer_black(DL);

    // Lights macro? These need to be on one line.
    gSPNumLights(DL++, 1); \
    gSPLight(DL++, &ninlogolight.l[0], 1); \
    gSPLight(DL++, &ninlogolight, 2);

#if defined(VERSION_EU)
    // 0x100000000 ? 0xFFFECD34 = 0x132CC (78540 decimal)
    ambiantlight = 0xFF - ((s32) ((g_MenuTimer * 0xFF) + 0xFFFECD34) / 83);
#else
    // 0x100000000 ? 0xFFFE8F72 = 0x1708E (94350 decimal)
    ambiantlight = 0xFF - ((s32) ((g_MenuTimer * 0xFF) + 0xFFFE8F72) / 100);
#endif
    if (ambiantlight >= 0x100)
    {
        ambiantlight = 0xff;
    }
    if (ambiantlight < 0)
    {
        ambiantlight = 0;
    }

    ninlogolight.a.l.colc[2] = ambiantlight;
    ninlogolight.a.l.colc[1] = ambiantlight;
    ninlogolight.a.l.colc[0] = ambiantlight;
    ninlogolight.a.l.col[2] = ambiantlight;
    ninlogolight.a.l.col[1] = ambiantlight;
    ninlogolight.a.l.col[0] = ambiantlight;

#if defined(VERSION_EU)
    ninLogoRotRate += 0.0209439527243f;
#else
    ninLogoRotRate += 0.017453292f;
#endif

    // Not sure if this is actually an `if` block, but the sp90 variable
    // needs to be declared here for the stack to match.
    if(1)
    {
        Mtxf tmpMtx;

        matrix_4x4_set_rotation_around_y(ninLogoRotRate, &tmpMtx);
        matrix_scalar_multiply_3(ninLogoScale, (f32*)&tmpMtx);

#if defined(VERSION_EU)
        ninLogoScale *= 1.09647190571f;
#else
        ninLogoScale *= 1.07977f;
#endif
        if (ninLogoScale > 1.1f)
        {
            ninLogoScale = 1.1f;
        }

        matrix_4x4_set_lookat_target(&ninlogoMtxf, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        matrix_4x4_multiply_in_place(&ninlogoMtxf, &tmpMtx);
        matrix_4x4_copy(&tmpMtx, &ninlogoMtxf);
    }

    ninlogo.basemtx = &ninlogoMtxf;

    ninlogo.mtxlist = dynAllocate(logoinst->obj->numMatrices << 6);

    matrix_4x4_copy(&ninlogoMtxf, ninlogo.mtxlist);

    logoinst->render_pos = (union RenderPosView*)ninlogo.mtxlist;

    modelUpdateNodeRelations(logoinst);

    ninlogo.flags = 3;
    ninlogo.zbufferenabled = FALSE;
    ninlogo.gdl = DL;

    subdraw(&ninlogo, logoinst);

    DL = ninlogo.gdl;

    for (i=0; i<logoinst->obj->numMatrices; i++)
    {
        Mtxf tmpMtxf;
        s32 padding2;

        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)logoinst->render_pos)[i*0x40], &tmpMtxf);
        matrix_4x4_f32_to_s32(&tmpMtxf, &((Mtxf*)logoinst->render_pos)[i]);

        if(i);
    }

    return DL;
}












//********************************************************************************************************
//RARE LOGO
//********************************************************************************************************

/*
 * Address: 0x7F008B58
*/
void init_menu02_rarelogo(void)
{
    setupRarewareLogoData(ptr_logo_and_walletbond_DL, 0x78000);
    sndPlaySfx(g_musicSfxBufferPtr, RARELOGO_SFX, 0);
}

void update_menu02_rareware(void) {
    return;
}

void interface_menu02_rareware(void)
{
    viSetUseZBuf(FALSE);
    if (isGunBarrelInMode2())
    {
        frontChangeMenu(MENU_EYE_INTRO, TRUE);
        return;
    }
    if (joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON))
    {
        if (!is_first_time_on_main_menu)
        {
            frontChangeMenu(MENU_FILE_SELECT, TRUE);
            return;
        }
        prev_keypresses = TRUE;
        frontChangeMenu(MENU_EYE_INTRO, TRUE);
    }
}

Gfx * constructor_menu02_rareware(Gfx * DL) {
    return retrieve_display_rareware_logo(DL);
}











//********************************************************************************************************
//GUNBARREL
//********************************************************************************************************
void init_menu03_gunbarrel(void) {
    initializeGunBarrelIntro(ptr_logo_and_walletbond_DL, 0x78000);
    musicTrack1Play(M_INTRO);
    maybe_is_in_menu = TRUE;
}

/*
 * Address: 0x7F00920C
*/
void update_menu_03_gunbarrel(void) {
    clearChrGunModelInstances();
}

void interface_menu03_eye(void) {
    viSetUseZBuf(FALSE);
    if (isGunBarrelInMode9()) {
        frontChangeMenu(MENU_GOLDENEYE_LOGO, TRUE);
        return;
    }
    if (joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON)) {
        if (!is_first_time_on_main_menu) {
            frontChangeMenu(MENU_FILE_SELECT, TRUE);
            return;
        }
        prev_keypresses = TRUE;
        frontChangeMenu(MENU_GOLDENEYE_LOGO, TRUE);
    }
}

Gfx * constructor_menu03_eye(Gfx * DL) {
    return renderGunbarrelEyeIntroSequence (DL);
}




//********************************************************************************************************
//GOLDENEYE LOGO
//********************************************************************************************************
void init_menu04_goldeneyelogo(void)
{
    struct coord3d pos;

    g_MenuTimer = 0;
    pos = goldeneyelogo_pos;
    load_object_fill_header(PitemZ_entries[PROP_GOLDENEYELOGO].header, PitemZ_entries[PROP_GOLDENEYELOGO].filename, ptr_logo_and_walletbond_DL, 0x3c000, 0);
    modelCalculateRwDataLen(PitemZ_entries[PROP_GOLDENEYELOGO].header);
    logoinst = modelmgrInstantiateModel(PitemZ_entries[PROP_GOLDENEYELOGO].header);
    #ifdef DEBUG
        assert(logoinst);
    #endif

    modelSetScale(logoinst, 1.0f);
    setsuboffset(logoinst, &pos);
}





void update_menu04_goldeneye(void) {
    is_first_time_on_main_menu = FALSE;
    clear_model_obj(logoinst);
}

void interface_menu04_goldeneyelogo(void)
{
#ifdef REFRESH_PAL
#define GOLDENEYELOGO_TIMER_1 50*3
#define GOLDENEYELOGO_TIMER_2 (50/2)*3
#else
#define GOLDENEYELOGO_TIMER_1 60*3
#define GOLDENEYELOGO_TIMER_2 (60/2)*3
#endif

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);
    g_MenuTimer += g_ClockTimer;
    if (((!is_first_time_on_main_menu) || (GOLDENEYELOGO_TIMER_1 < g_MenuTimer)) ||
       ((ge_logo_bool && (GOLDENEYELOGO_TIMER_2 < g_MenuTimer)))) {
        if (g_MenuTimer > GOLDENEYELOGO_TIMER_1) {
            if (prev_keypresses) {
                frontChangeMenu(MENU_FILE_SELECT,TRUE);
            }
            else {
                do_extended_cast_display(FALSE);
                frontChangeMenu(MENU_DISPLAY_CAST,TRUE);
            }
        }
        else {
            if ((joyGetButtonsPressedThisFrame(PLAYER_1,ANY_BUTTON)) || ((is_first_time_on_main_menu && ge_logo_bool))) {
                frontChangeMenu(MENU_FILE_SELECT,TRUE);
            }
        }
    }
    else {
        if (joyGetButtonsPressedThisFrame(PLAYER_1,ANY_BUTTON)) {
            ge_logo_bool = TRUE;
        }
    }
}



Gfx *constructor_menu04_goldeneyelogo(Gfx *DL)
{
    ModelRenderData gelogo;
    s32 padding[2];
    Mtxf logoMatrix;
    s32 i;
    LookAt * logoLookAt;
    Mtxf logoReflectMtx;

    gelogo = goldeneyelogo_MRD;

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);

    logoLookAt = (LookAt *)dynAllocateLights(2);
    guLookAtReflect(&logoReflectMtx, logoLookAt, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Lights macro? These need to be on one line.
    gSPNumLights(DL++, 1); \
    gSPLight(DL++, &gelogolight.l[0], 1); \
    gSPLight(DL++, &gelogolight, 2);

    // gSPLookAt macro expands to gSPLookAtX + gSPLookAtY
    gSPLookAt(DL++, logoLookAt);

    matrix_4x4_set_lookat_target(&logoMatrix, 0.0f, 0.0f, 3000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    gelogo.basemtx = &logoMatrix;
    gelogo.mtxlist = dynAllocate(logoinst->obj->numMatrices << 6);

    matrix_scalar_multiply(1.2f, logoMatrix.m[0]);
    matrix_4x4_copy(&logoMatrix, gelogo.mtxlist);
    logoinst->render_pos = (union RenderPosView*)gelogo.mtxlist;

    modelUpdateNodeRelations(logoinst);

    gelogo.flags = 3;
    gelogo.zbufferenabled = FALSE;
    gelogo.gdl = DL;

    subdraw(&gelogo, logoinst);

    DL = gelogo.gdl;

    for (i=0; i<logoinst->obj->numMatrices; i++)
    {
        Mtxf tempMtxf;
        s32 padding2;

        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)logoinst->render_pos)[i*0x40], &tempMtxf);
        matrix_4x4_f32_to_s32(&tempMtxf, &((Mtxf*)logoinst->render_pos)[i]);

        if(i);
    }

    return DL;
}



void disable_all_switches(Model *arg0)
{
    s32 i;
    ModelNode *mnode;

    for (i = 0; i < arg0->obj->numSwitches; i++)
    {
        mnode = arg0->obj->Switches[i];

        if (mnode != NULL && (mnode->Opcode & 0xff) == MODELNODE_OPCODE_SWITCH)
        {
            union ModelRwData *unmrd;
            struct ModelRwData_SwitchRecord *srecord;

            unmrd = modelGetNodeRwData(arg0, mnode);
            srecord = (struct ModelRwData_SwitchRecord *)unmrd;
            srecord->visible = 0;
        }
    }
}


void set_item_visibility_in_objinstance(Model* objinstance, s32 item, s32 mode)
{
    if (objinstance->obj->Switches[item] != NULL)
    {
        ModelRwData_SwitchRecord *rwdata = &modelGetNodeRwData(objinstance, objinstance->obj->Switches[item])->Switch;

        rwdata->visible = mode;
    }
}


//********************************************************************************************************
//WALLETINIT
//********************************************************************************************************

void select_load_bond_picture(Model *objinstance, u32 bondID)
{
#ifdef ALL_BONDS
    set_item_visibility_in_objinstance(objinstance, SW_BROSNAN, (bondID == BOND_BROSNAN)); //brosnan picture
    set_item_visibility_in_objinstance(objinstance, SW_CONNERY, (bondID == BOND_CONNERY));
    set_item_visibility_in_objinstance(objinstance, SW_DALTON, (bondID == BOND_DALTON));
    set_item_visibility_in_objinstance(objinstance, SW_MOORE, (bondID == BOND_MOORE));
    set_item_visibility_in_objinstance(objinstance, SW_BROSNANCOVER, (bondID == BOND_BROSNAN)); //bigger brosnan picture
    set_item_visibility_in_objinstance(objinstance, SW_CONNERYCOVER, (bondID == BOND_CONNERY));
    set_item_visibility_in_objinstance(objinstance, SW_DALTONCOVER, (bondID == BOND_DALTON));
    set_item_visibility_in_objinstance(objinstance, SW_MOORECOVER, (bondID == BOND_MOORE));
#else
    set_item_visibility_in_objinstance(objinstance,SW_BROSNAN,TRUE); //brosnan picture
    set_item_visibility_in_objinstance(objinstance,SW_CONNERY,FALSE);
    set_item_visibility_in_objinstance(objinstance,SW_DALTON,FALSE);
    set_item_visibility_in_objinstance(objinstance,SW_MOORE,FALSE);
    set_item_visibility_in_objinstance(objinstance,SW_BROSNANCOVER,TRUE); //bigger brosnan picture
    set_item_visibility_in_objinstance(objinstance,SW_CONNERYCOVER,FALSE);
    set_item_visibility_in_objinstance(objinstance,SW_DALTONCOVER,FALSE);
    set_item_visibility_in_objinstance(objinstance,SW_MOORECOVER,FALSE);
#endif
}





/**
 * Address 0x7F00B8AC NTSC
*/
void load_walletbond(void)
{
    ModelNode *mnode;
    s32 i;

    if (walletinst[0] == NULL)
    {
        load_object_fill_header(
            PitemZ_entries[PROP_WALLETBOND].header,
            (s8*)PitemZ_entries[PROP_WALLETBOND].filename,
            (u8*)ptr_logo_and_walletbond_DL,
            0xA000,
            0);

        modelCalculateRwDataLen(PitemZ_entries[PROP_WALLETBOND].header);

        for (i = FOLDER1; i < MAX_FOLDER_COUNT; i++)
        {
            walletinst[i]  = modelmgrInstantiateModelWithAnim(PitemZ_entries[PROP_WALLETBOND].header);
            #ifdef DEBUG
            assert(walletinst[i]);
            #endif
            modelSetScale(walletinst[i], 1.0f);
        }

        mnode = PitemZ_entries[PROP_WALLETBOND].header->Switches[GFXHIT0_PICS];

        if (mnode != NULL)
        {
            struct ModelRoData_DisplayList_CollisionRecord *srecord;
            struct ModelNode *b;
            Gfx *arg0;

            b = (struct ModelNode *)mnode;
            srecord = b->Data;

            arg0 = (s32)srecord->BaseAddr + ((s32)srecord->Primary & 0xffffff);
            bgApplyDynamicCCRMLUT(arg0, NULL, CCRMLUT_WALLETBOND);
        }
    }
}




void frontCleanUpWalletBond(void)
{
    s32 i;

    for (i = FOLDER1; i < MAX_FOLDER_COUNT; i++)
    {
        if (walletinst[i] == NULL) { continue; }

        clear_aircraft_model_obj(walletinst[i]);
        walletinst[i] = NULL;
    }
}



//********************************************************************************************************
//FILE SELECT
//********************************************************************************************************
void init_menu05_fileselect(void)
{
    s32 size = 0x6e000;
    Gfx* DL = (s32)(ptr_logo_and_walletbond_DL) + (s32)(4096*10);
    int i;

    prev_keypresses = FALSE;


    if (selected_folder_num < FOLDER1)
    {
        selected_folder_num = FOLDER1;
    }
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    folder_selected_for_deletion = FOLDER_INVALID;
    folder_selected_for_deletion_choice = FOLDER2;
    sub_GAME_7F008DE4(&DL, &size);
    load_walletbond();
    if (maybe_is_in_menu){
        musicTrack1Play(M_FOLDERS);
        maybe_is_in_menu = FALSE;
    }
    g_MenuTimer = 0;
    for(i=1;i<CHEAT_INVALID;i++){
        g_CheatActivated[i] = FALSE;
    }
    g_AppendCheatSinglePlayer = FALSE;
    g_AppendCheatMultiPlayer = FALSE;
}



void update_menu05_filesel(void)
{
    if ((menu_update == MENU_LEGAL_SCREEN) || (maybe_prev_menu == MENU_LEGAL_SCREEN))
    {
        frontCleanUpWalletBond();
    }
}



s32 get_chapter_briefing_entry(s32 briefing)
{
    s32 i;

    for (i = briefing; i >= 0; i--)
    {
        if (mission_folder_setup_entries[i].type != MISSION_PART)
        {
            return i;
        }
    }

    return -1;
}


void toggle_deletion_menu_for_folder(int index)
{
  struct coord2d local_8;

  transform3Dto2DCoords(&folderpositions_camspace[index],&local_8);
  cursor_h_pos = local_8.x + -1.0f;
  cursor_v_pos = local_8.y + 20.0f;
}


/**
 * Address: 7F00BBCC
 * 
 * Tick function for the file folder select screen. Rebuild's each folder model's render matrix
 * then handles input. Also keeps track of the 30 second idle timeout for going back to the legal screen.
 */
s32 interface_menu05_fileselect(void)
{
    s32 walletnum;
    s32 foldernum;
    Mtxf lookatmtx;
    Mtxf walletmtx;
    struct coord3d *folderpos;

    /**
     *  Accumulate the menu timer if there's been no button inputs and no more than marginal stick input.
     *  The menu timer is checked at the end of this function to determine if we should switch to the legal screen.
     */
    if (((((joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON) != 0) || (joyGetStickX(0) < -5)) || (joyGetStickX(0) >= 6)) || (joyGetStickY(0) < -5)) || (joyGetStickY(0) >= 6))
    {
        g_MenuTimer = 0;
    }
    else
    {
        g_MenuTimer += g_ClockTimer;
    }

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    for (walletnum = 0; walletnum < MAX_FOLDER_COUNT; walletnum++)
    {
        folderpos = &folderpositions[walletnum];

        matrix_4x4_set_lookat_target(&lookatmtx, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        matrix_4x4_set_identity_and_position(folderpos, &walletmtx);
        matrix_scalar_multiply(0.37f, (f32*)&walletmtx);
        matrix_4x4_multiply_in_place(&lookatmtx, &walletmtx);

        walletinst[walletnum]->render_pos = dynAllocate(walletinst[walletnum]->obj->numMatrices << 6);
        matrix_4x4_copy(&walletmtx, &walletinst[walletnum]->render_pos->pos);

        folderpositions_camspace[walletnum].f[0] = walletinst[walletnum]->render_pos->pos.m[3][0];
        folderpositions_camspace[walletnum].f[1] = walletinst[walletnum]->render_pos->pos.m[3][1];
        folderpositions_camspace[walletnum].f[2] = walletinst[walletnum]->render_pos->pos.m[3][2];

        disable_all_switches(walletinst[walletnum]);

        select_load_bond_picture(walletinst[walletnum], fileGetBondForFolder(walletnum));
        set_item_visibility_in_objinstance(walletinst[walletnum], 0xE, 1);
        set_item_visibility_in_objinstance(walletinst[walletnum], 0xD, 1);
    }

    if (selected_folder_num >= FOLDER1)
    {
        if (selected_folder_num == RAMROM_FOLDERNUM)
        {
            selected_folder_num = selected_folder_num_copy;
        }

        if ((selected_folder_num < FOLDER1) || (selected_folder_num >= MAX_FOLDER_COUNT))
        {
            selected_folder_num = FOLDER1;
        }

        toggle_deletion_menu_for_folder(selected_folder_num);
        selected_folder_num = -1;
    }

    if (folder_selected_for_deletion >= 0)
    {
        if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_JPAD | L_TRIG | L_CBUTTONS) != 0) && (folder_selected_for_deletion_choice == 0))
        {
            folder_selected_for_deletion_choice = 1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
        }
        else if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_JPAD | R_TRIG | R_CBUTTONS) != 0) && (folder_selected_for_deletion_choice != 0))
        {
            folder_selected_for_deletion_choice = 0;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
        }
        if ((joyGetStickX(0) < -0x2D) && (folder_selected_for_deletion_choice == 0))
        {
            folder_selected_for_deletion_choice = 1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
        }
        else if ((joyGetStickX(0) >= 0x2E) && (folder_selected_for_deletion_choice != 0))
        {
            folder_selected_for_deletion_choice = 0;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
        }
        if (joyGetButtonsPressedThisFrame(PLAYER_1, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
        {
            if (folder_selected_for_deletion_choice == 0)
            {
                fileDeleteSaveForFolder(folder_selected_for_deletion);
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
            }
            else
            {
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
            }
            toggle_deletion_menu_for_folder(folder_selected_for_deletion);
            folder_selected_for_deletion = -1;
        }
        else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON) != 0)
        {
            toggle_deletion_menu_for_folder(folder_selected_for_deletion);
            folder_selected_for_deletion = -1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
        }
    }
    else
    {
        for (foldernum = FOLDER1; foldernum < MAX_FOLDER_COUNT; foldernum++)
        {
            f32 xmax;
            f32 xmin;
            f32 ymax;
            f32 ymin;

            struct rectbbox folderbbox;

            LEVEL_SOLO_SEQUENCE higheststage;
            DIFFICULTY highestdifficulty;

            modelGetXYExtents(walletinst[foldernum], &xmax, &xmin, &ymax, &ymin);
            projectRectCornersTo2D(&folderpositions_camspace[foldernum], &xmin, &ymin, &folderbbox.right, &folderbbox.left);

            if ((folderbbox.right <= cursor_h_pos)
                && (cursor_h_pos <= folderbbox.left)
                && (folderbbox.down <= cursor_v_pos)
                && (cursor_v_pos <= folderbbox.up))
            {
                fileGetHighestStageDifficultyCompletedForFolder(foldernum, &higheststage, &highestdifficulty);
#ifdef DEBUG
                osSyncPrintf("selected file %d\n", foldernum);
#endif

                if (joyGetButtonsPressedThisFrame(PLAYER_1, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
                {
                    if (folder_selection_screen_option_icon == 0)
                    {
                        selected_folder_num = foldernum;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, PAPER_TURN_SFX, NULL);
                    }
                    else if (folder_selection_screen_option_icon == 1)
                    {
                        fileCopyFolderToFirstFree(foldernum);
                        folder_selection_screen_option_icon = 0;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, COPY_FILE_SFX, NULL);
                    }
                    else if (folder_selection_screen_option_icon == 2)
                    {
                        if ((higheststage >= SP_LEVEL_DAM) && (highestdifficulty >= DIFFICULTY_AGENT))
                        {
                            folder_selected_for_deletion = foldernum;
                            folder_selected_for_deletion_choice = 1;
                        }

                        folder_selection_screen_option_icon = 0;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
                    }

                    break;
                }
            }
        }

        if (joyGetButtonsPressedThisFrame(PLAYER_1, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
        {
            if ((folder_option_COPY_bound.left <= cursor_h_pos)
                && (cursor_h_pos <= folder_option_COPY_bound.right)
                && (folder_option_COPY_bound.up <= cursor_v_pos)
                && (cursor_v_pos <= folder_option_COPY_bound.down))
            {
                folder_selection_screen_option_icon = 1;
                sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, DOOR_LOCK_SFX, NULL);
            }
            else if ((folder_option_ERASE_bound.left <= cursor_h_pos)
                && (cursor_h_pos <= folder_option_ERASE_bound.right)
                && (folder_option_ERASE_bound.up <= cursor_v_pos)
                && (cursor_v_pos <= folder_option_ERASE_bound.down))
            {
                folder_selection_screen_option_icon = 2;
                sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, DOOR_LOCK_SFX, NULL);
            }
            else if (folder_selection_screen_option_icon != 0)
            {
                folder_selection_screen_option_icon = 0;
                sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
            }
        }
        else if ((joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON) != 0)
            && (folder_selection_screen_option_icon != 0))
        {
            folder_selection_screen_option_icon = 0;
            sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
        }

        frontUpdateControlStickPosition();
    }

    if (selected_folder_num >= FOLDER1)
    {
        frontChangeMenu(MENU_MODE_SELECT, FALSE);
        setCursorPOSforMode(0);

        return;
    }

    // Change to the legal screen if 30 seconds of no input have elapsed
#if defined(VERSION_EU)
    if (g_MenuTimer >= 1501) // PAL (50fps): 30 seconds + 1 frame
#else
    if (g_MenuTimer >= 1801) // NTSC (60fps): 30 seconds + 1 frame
#endif
    {
        frontChangeMenu(MENU_LEGAL_SCREEN, TRUE);
    }
}


char* get_ptr_difficulty_name(s32 difficulty)
{
    char* text = NULL;
    switch (difficulty)
    {
    case 0:
        text = langGet(getStringID(LTITLE, TITLE_STR_19_AGENT)); //Agent
        break;
    case 1:
        text = langGet(getStringID(LTITLE, TITLE_STR_20_SECRETAGENT)); //Secret Agent
        break;
    case 2:
        text = langGet(getStringID(LTITLE, TITLE_STR_21_00AGENT)); //00 Agent
        break;
    case 3:
        text = langGet(getStringID(LTITLE, TITLE_STR_22_007)); //007
        break;
    }
    return text;
}


/**
 * Address: 7F00C408
 * 
 * Render the file folder select screen. That includes the background texture, four 3D wallet models, the progress text written on them,
 * the crosshair cursor, and the "SELECT FILE", "Copy", and "Erase" text and icons.
 *
 * The declaration of difficultytext (spD0) is likely incorrect, if this function is modified
 * make sure to extend difficultytext to avoid overflow.
 */
Gfx *constructor_menu05_fileselect(Gfx *DL)
{
    s32 foldernum;
    struct FolderSelectColour topcolour;
    struct FolderSelectColour bottomcolour;
    s32 j;
    s32 i;
    u8 *langp;
    s32 chapterindex;                       // index of the chapter (MISSION_HEADER) row in mission_folder_setup_entries
    ModelRenderData renderdata;
    s32 missionindex;                       // index of the mission (MISSION_PART) row in mission_folder_setup_entries
    Mtxf mtx;
    f32 folderx;
    struct point2d textpos;
    struct point2d textsize;
    LEVEL_SOLO_SEQUENCE higheststage;
    DIFFICULTY highestdifficulty;
    struct coord2d folderpos2d;             // folder position projected to screen space

    topcolour = unknown_folderselect_constructor;
    bottomcolour = unknown_folderselect_constructor_0;

    /** 
     * The background image doesn't fully cover the screen so it's necessary to clear the back framebuffer to opaque black.
     * This creates the impression of the folder menu having a black border.
     */ 
    DL = clear_framebuffer_black(DL);

    gDPSetCombineLERP(DL++, TEXEL0, PRIMITIVE, ENV_ALPHA, PRIMITIVE, 0, 0, 0, PRIMITIVE, TEXEL0, PRIMITIVE, ENV_ALPHA, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetEnvColor(DL++, 0xFF, 0xFF, 0xFF, 0x14);

    // Render the gun barrel background image.
    DL = titleRenderFolderMenuBackground(DL, (s32) floorFloat(((f32) viGetX() * -80.0f) / 1280.0f), &topcolour, &bottomcolour);

    gSPDisplayList(DL++, &dlBasicGeometry);
    gSPDisplayList(DL++, &dlFastPipelineSetup);

    for (j = 3; j >= 0; j--)
    {
        // struct copy
        renderdata = unknown_folderselect;

        renderdata.flags = 3;
        renderdata.zbufferenabled = FALSE;
        renderdata.gdl = DL;

        // Render the folder wall model.
        subdraw(&renderdata, walletinst[j]);

        DL = renderdata.gdl;

        for (i=0; i < walletinst[j]->obj->numMatrices; i++)
        {
            matrix_4x4_copy((Mtxf*)&((s8*)walletinst[j]->render_pos)[i * sizeof(Mtxf)], &mtx);
            matrix_4x4_f32_to_s32(&mtx, &((Mtxf*)walletinst[j]->render_pos)[i]);

        }
    }

    DL = microcode_constructor(DL);
    setTextSpacingInverted(0);

    for (foldernum = FOLDER1; foldernum < MAX_FOLDER_COUNT; foldernum++)
    {
        char difficultytext[4]; // spD0
        char missiontext[18];   // spBC: "Mission <chapter>.<part>\n"
        s32 padding3;
        struct coord3d * folderworldpos;

        folderworldpos = &folderpositions_camspace[foldernum];

        transform3Dto2DCoords(folderworldpos, &folderpos2d);

        if (foldernum == folder_selected_for_deletion)
        {
            textpos.p[1] = (s32) floorFloat(folderpos2d.f[0]) - 0x31;
            textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x19;

            DL = microcode_constructor_related_to_menus(DL, textpos.p[1], textpos.p[0], textpos.p[1] + 0x63, textpos.p[0] + 0x2A, 0x32);

            langp = langGet(getStringID(LTITLE, TITLE_STR_23_ERASEFILE)); /* Erase file? */
            textpos.p[1] = (s32) floorFloat(folderpos2d.f[0]) - 0x2F;
            textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x1E;

            DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);

            langp = langGet(getStringID(LTITLE, TITLE_STR_24_CANCEL)); /* cancel */
            textpos.p[1] = (s32) floorFloat(folderpos2d.f[0]) - 0x2F;
            textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x32;

            if (folder_selected_for_deletion_choice != 0)
            {
                textsize.p[0] = 0;
                textsize.p[1] = 0;
                textMeasure(&textsize.p[1], &textsize.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                DL = microcode_constructor_related_to_menus(DL, textpos.p[1] - 1, textpos.p[0] - 1, textsize.p[0] + textpos.p[1] + 3, textsize.p[1] + textpos.p[0], 0x32);
                DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
            }
            else
            {
                DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
            }

            langp = langGet(getStringID(LTITLE, TITLE_STR_25_CONFIRM)); /* confirm */

            folderx = floorFloat(folderpos2d.f[0]);
            textpos.p[1] = (((j_text_trigger != 0) ? 0x17 : -1) + (s32) folderx) - 1;
            textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x32;

            if (folder_selected_for_deletion_choice != 0)
            {
                DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
            }
            else
            {
                textsize.p[0] = 0;
                textsize.p[1] = 0;
                textMeasure(&textsize.p[1], &textsize.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                DL = microcode_constructor_related_to_menus(DL, textpos.p[1] - 1, textpos.p[0] - 1, textsize.p[0] + textpos.p[1] + 3, textsize.p[1] + textpos.p[0], 0x32);
                DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
            }

        }
        else
        {
            fileGetHighestStageDifficultyCompletedForFolder(foldernum, &higheststage, &highestdifficulty);

            if ((higheststage >= SP_LEVEL_DAM) && (highestdifficulty >= DIFFICULTY_AGENT))
            {
                langp = get_ptr_difficulty_name(highestdifficulty);

                if (langp != NULL)
                {
                    strcpy((char *)&difficultytext, langp);
                    strcat((char *)&difficultytext, "\n");

                    textsize.p[0] = 0;
                    textsize.p[1] = 0;

                    textMeasure(&textsize.p[1], &textsize.p[0], (char *)&difficultytext, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                    textpos.p[1] = ((s32) floorFloat(folderpos2d.f[0]) - (textsize.p[0] / 2)) - 1;
                    textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x15;
                    DL = textRender(DL, &textpos.p[1], &textpos.p[0], (char *)&difficultytext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
                }

                if (highestdifficulty != DIFFICULTY_007)
                {
                    chapterindex = -1;

                    strcpy(missiontext, langGet(getStringID(LTITLE, TITLE_STR_26_MISSION))); /* Mission */

                    for (missionindex = 0; mission_folder_setup_entries[missionindex].folder_text_preset != 0; missionindex++)
                    {
                        if (higheststage == mission_folder_setup_entries[missionindex].mission_num)
                        {
                            chapterindex = get_chapter_briefing_entry(missionindex);
                            break;
                        }
                    }

                    if (chapterindex >= 0)
                    {
                        strcat((char *)missiontext, (char *)mission_folder_setup_entries[chapterindex].string_ptr);
                        strcat((char *)missiontext, ".");
                    }

                    strcat((char *)missiontext, (char *)mission_folder_setup_entries[missionindex].string_ptr);
                    strcat((char *)missiontext, "\n");
                    textsize.p[0] = 0;
                    textsize.p[1] = 0;

                    textMeasure(&textsize.p[1], &textsize.p[0], (char *)missiontext, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                    textpos.p[1] = ((s32) floorFloat(folderpos2d.f[0]) - (textsize.p[0] / 2)) - 1;
                    textpos.p[0] = (s32) floorFloat(folderpos2d.f[1]) + 0x2D;

                    DL = textRender(DL, &textpos.p[1], &textpos.p[0], (char *)missiontext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
                }
            }
        }
    }

    {
        // The above for loops makes a lot of compiler temp variables on the stack,
        // These need to be declared sometime after the above for loop.
        struct coord2d copypos;
        struct coord2d copyhalfsize;
        struct coord2d erasepos;
        struct coord2d erasehalfsize;
        struct coord2d selectpos;
        struct coord2d selecthalfsize;

        setTextSpacingInverted(0);

        langp = langGet(getStringID(LTITLE, TITLE_STR_27_COPY)); /* Copy */

        textsize.p[0] = 0;
        textsize.p[1] = 0;

        textMeasure(&textsize.p[1], &textsize.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        textpos.p[0] = 285 - (textsize.p[1] / 2);
        textpos.p[1] = 247;

        DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
        folder_option_COPY_bound.right = (f32) (textsize.p[0] + textpos.p[1]);

        langp = langGet(getStringID(LTITLE, TITLE_STR_28_ERASE)); /* Erase */

        textsize.p[0] = 0;
        textsize.p[1] = 0;

        textMeasure(&textsize.p[1], &textsize.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        textpos.p[1] = 357;
        textpos.p[0] = 285 - (textsize.p[1] / 2);

        DL = textRender(DL, &textpos.p[1], &textpos.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);

        folder_option_ERASE_bound.right = (f32) (textsize.p[0] + textpos.p[1]);

        copypos.f[0] = 225.0f;
        copypos.f[1] = 285.0f;

        copyhalfsize.f[0] = (f32) (mainfolderimages + IMG_COPY)->width * 0.5f;
        copyhalfsize.f[1] = (f32) (mainfolderimages + IMG_COPY)->height * 0.5f;

        texSelect(&DL, mainfolderimages, 4, 0, 0);
        display_image_at_position(&DL, &copypos.f[0], &copyhalfsize.f[0], mainfolderimages->width, mainfolderimages->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) mainfolderimages->level > 0, 0);

        folder_option_COPY_bound.left = copypos.f[0] - copyhalfsize.f[0];
        folder_option_COPY_bound.up = copypos.f[1] - copyhalfsize.f[1];
        folder_option_COPY_bound.down = copypos.f[1] + copyhalfsize.f[1];

        erasepos.f[0] = 335.0f;
        erasepos.f[1] = 285.0f;

        erasehalfsize.f[0] = (mainfolderimages + IMG_DEL)->width * 0.5f;
        erasehalfsize.f[1] = (mainfolderimages + IMG_DEL)->height * 0.5f;

        texSelect(&DL, mainfolderimages + IMG_DEL, 4, 0, 0);
        display_image_at_position(&DL, &erasepos.f[0], &erasehalfsize.f[0], (mainfolderimages + IMG_DEL)->width, (mainfolderimages + IMG_DEL)->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) (mainfolderimages + IMG_DEL)->level > 0, 0);

        folder_option_ERASE_bound.left = (f32) (erasepos.f[0] - erasehalfsize.f[0]);
        folder_option_ERASE_bound.up = (f32) (erasepos.f[1] - erasehalfsize.f[1]);
        folder_option_ERASE_bound.down = (f32) (erasepos.f[1] + erasehalfsize.f[1]);

        selectpos.f[0] = 110.0f;
        selectpos.f[1] = 285.0f;

        selecthalfsize.f[0] = (mainfolderimages + IMG_SEL)->width * 0.5f;
        selecthalfsize.f[1] = (mainfolderimages + IMG_SEL)->height * 0.5f;

        texSelect(&DL, mainfolderimages + IMG_SEL, 4, 0, 0);
        display_image_at_position(&DL, &selectpos.f[0], &selecthalfsize.f[0], (mainfolderimages + IMG_SEL)->width, (mainfolderimages + IMG_SEL)->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) (mainfolderimages + IMG_SEL)->level > 0, 0);
    }

    if (folder_selected_for_deletion < 0)
    {
        DL = frontDrawCursor(DL);
    }

    return DL;
}


//********************************************************************************************************
//MODE SELECT
//********************************************************************************************************
void init_menu06_modeselect(void)
{
    gamemode = GAMEMODE_INTRO;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    load_walletbond();
    fileUpdateBondInCurrentFolder();
}


void update_menu06_modesel(void) 
{
    return;
}


void interface_menu06_modesel(void)
{
    u32 i;

    is_cheat_menu_available = FALSE;
    for (i=CHEAT_EXTRA_MP_CHARS; i != CHEAT_INVALID; i++)
    {
        if (frontCheckIfCheatIsUnlocked(i))
        {
            cheat_available[i] = TRUE;
            is_cheat_menu_available = TRUE;
        }
        else
        {
            cheat_available[i] = FALSE;
        }
    }
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);

    disable_all_switches(walletinst[0]);
    select_load_bond_picture(walletinst[0], fileGetBondForFolder(selected_folder_num));
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PHOTOBOND, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_EYESONLY, 1);
    tab_prev_highlight = FALSE;
    mission_difficulty_highlighted = DIFFICULTY_MULTI;
    if (frontCheckCursorOnPreviousTab())
    {
        tab_prev_highlight = TRUE;
        if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
        {
            tab_prev_selected = TRUE;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, 0);
        }
    }
    else if ((is_cheat_menu_available) && (275.0f <= cursor_v_pos))
    {
        mission_difficulty_highlighted = DIFFICULTY_00;
        if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
        {
            gamemode = GAMEMODE_CHEATS;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE_SFX, 0);
        }
    }
    else if ((243.0f <= cursor_v_pos) && (joyGetControllerCount() >= 2))
    {
        mission_difficulty_highlighted = DIFFICULTY_SECRET;
        if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
        {
            gamemode = GAMEMODE_MULTI;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE_SFX, 0);
        }
    }
    else
    {
        mission_difficulty_highlighted = DIFFICULTY_AGENT;
        if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
        {
            gamemode = GAMEMODE_SOLO;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE_SFX, 0);
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, 0);
    }
    frontUpdateControlStickPosition();
    if (gamemode == GAMEMODE_SOLO)
    {
        frontChangeMenu(MENU_MISSION_SELECT, FALSE);
        set_cursor_to_stage_solo(0);
        return;
    }
    if (gamemode == GAMEMODE_MULTI)
    {
        frontChangeMenu(MENU_MP_OPTIONS, FALSE);
        return;
    }
    if (gamemode == GAMEMODE_CHEATS)
    {
        frontChangeMenu(MENU_CHEAT, FALSE);
        return;
    }
    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_FILE_SELECT, FALSE);
    }
}


// Address 0x7F00D5E8 NTSC
Gfx *frontSetupMenuBackground(Gfx *DL)
{
    s32 padding;
    f32 temp_f0;
    f32 temp_f2;
    ModelRenderData sp10C;
    s32 i;
    Mtxf spC8;
    Mtxf sp88;
    Mtxf sp48;

    temp_f0 = folderpositions[selected_folder_num].f[0];
    temp_f2 = folderpositions[selected_folder_num].f[1];

    sp10C = D_8002AF84;

    temp_f0 += D_8002AFC4;
    temp_f2 += D_8002AFC8;

    matrix_4x4_set_lookat_target(&spC8, temp_f0, temp_f2, 4000.0f + D_8002AFCC, temp_f0, temp_f2, 0.0f, 0.0f, 1.0f, 0.0f);
    matrix_4x4_set_identity_and_position(&folderpositions[selected_folder_num], &sp88);
    matrix_scalar_multiply(0.25f, sp88.m[0]);
    matrix_4x4_multiply_in_place(&spC8, &sp88);

    sp10C.basemtx = &sp88;

    sp10C.mtxlist = dynAllocate(walletinst[0]->obj->numMatrices << 6);

    matrix_4x4_copy(&sp88, sp10C.mtxlist);

    walletinst[0]->render_pos = (union RenderPosView*)sp10C.mtxlist;

    sp10C.flags = 3;
    sp10C.zbufferenabled = FALSE;
    sp10C.gdl = DL;

    subdraw(&sp10C, walletinst[0]);

    DL = sp10C.gdl;

    for (i=0; i<walletinst[0]->obj->numMatrices; i++)
    {
        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)walletinst[0]->render_pos)[i*0x40], &sp48);
        matrix_4x4_f32_to_s32(&sp48, &((Mtxf*)walletinst[0]->render_pos)[i]);
    }


    return DL;
}



void setCursorPOSforMode(int mode)
{
    cursor_h_pos = 126.0f;
    cursor_v_pos = mode * 0x20 + 0xe2;
}




Gfx* constructor_menu06_modesel(Gfx* DL)
{
    char *textstring;
    s32 x;
    s32 y;
    s32 y2;
    s32 x2;
    s32 text_color;

    DL = viSetFillColor(DL,0,0,0);
    DL = viFillScreen(DL);
    #ifdef VERSION_EU
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
    #endif
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    x = 0x96;
    y = 0xdc;
    DL = frontPrintText(DL, &x, &y, "1.\n", ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    textstring = langGet((g_AppendCheatSinglePlayer != 0) ? getStringID(LTITLE, TITLE_STR_117_CHEATSELECTMISSION) : getStringID(LTITLE, TITLE_STR_29_SELECTMISSION));

    textMeasure(&x2, &y2, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    x = 0xAA;
    y = 0xdc;
    if (mission_difficulty_highlighted == 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x94, 0xDA, y2 + 0xAF, 0xEA, 0x32);
    }

    DL = frontPrintText(DL, &x, &y, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    x = 0x96;
    y = 0xFC;
    if (joyGetControllerCount() >= 2)
    {
        text_color = 0xFF;
    }
    else
    {
        text_color = 0x70;
    }
    DL = frontPrintText(DL, &x, &y, "2.\n", ptrFontZurichBoldChars, ptrFontZurichBold, text_color, viGetX(), viGetY(), 0, 0);

    textstring = langGet((g_AppendCheatMultiPlayer != 0) ? getStringID(LTITLE, TITLE_STR_276_CHEATMULTIPLAYER) : getStringID(LTITLE, TITLE_STR_30_MULTIPLAYER));

    textMeasure(&x2, &y2, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    x = 0xAA;
    y = 0xFC;
    if (mission_difficulty_highlighted == 1)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x94, 0xFA, y2 + 0xAF, 0x10A, 0x32);
    }
    DL = frontPrintText(DL, &x, &y, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, text_color, viGetX(), viGetY(), 0, 0);

    if (is_cheat_menu_available != 0)
    {
        x = 0x96;
        y = 0x11C;
        DL = frontPrintText(DL, &x, &y, "3.\n", ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        textstring = langGet(getStringID(LTITLE, TITLE_STR_31_CHEATOPTIONS));

        textMeasure(&x2, &y2, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        x = 0xAA;
        y = 0x11C;
        if (mission_difficulty_highlighted == 2)
        {
            DL = microcode_constructor_related_to_menus(DL, 0x94, 0x11A, y2 + 0xAF, 0x12A, 0x32);
        }
        DL = frontPrintText(DL, &x, &y, textstring, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    }

    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);
    return DL;
}


s32 pull_and_display_text_for_folder_a0(s32 arg0)
{
    int i;

    for (i=0; mission_folder_setup_entries[i].folder_text_preset != 0 ; i++)
    {
        if (arg0 == mission_folder_setup_entries[i].mission_num)
        {
            return i;
        }
    }

    return -1;
}


s32 check_if_stage_completed_on_difficulty(int stage, DIFFICULTY difficulty)
{
    s32 num;

    num = mission_folder_setup_entries[stage].mission_num;
    if (num >= 0)
    {
        return fileIsStageUnlockedAtDifficulty(selected_folder_num, num, difficulty);
    }
    return 0;
}





s32 get_highest_unlocked_difficulty_for_level(s32 arg0)
{
    s32 num;
    s32 difficulty;
    s32 temp_v0;

    if (mission_folder_setup_entries[pull_and_display_text_for_folder_a0(arg0)].stage_id >= 0)
    {
        num = DIFFICULTY_00;
        if (fileIs007ModeUnlocked(selected_folder_num) || get_debug_007_unlock_flag())
        {
            num = DIFFICULTY_007;
        }

        for (difficulty=num; difficulty >= 0; difficulty--)
        {
            temp_v0 = fileIsStageUnlockedAtDifficulty(selected_folder_num, arg0, difficulty);
            if (g_AppendCheatSinglePlayer == 0)
            {
                if (temp_v0 != DIFFICULTY_AGENT)
                {
                    return difficulty;
                }
            }
            else if (temp_v0 == DIFFICULTY_007)
            {
                return difficulty;
            }
        }
    }

    return -1;
}


//********************************************************************************************************
//MISSION SELECT
//********************************************************************************************************
void init_menu07_missionselect(void)
{
    selected_stage = LEVELID_NONE;
    briefingpage = BRIEFING_INVALID;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    if (maybe_is_in_menu)
    {
        musicTrack1Play(M_FOLDERS);
        maybe_is_in_menu = FALSE;
    }
    load_walletbond();
}


void update_menu07_missionsel(void) 
{
    return;
}


// Address 0x7F00DEB8 NTSC
void interface_menu07_missionsel(void)
{
    s32 var_s4;
    s32 var_s2;
    struct ModelRwData_DisplayList_CollisionRecord *temp_s1;
    s32 temp_a0;
    s32 i;
    s32 var_s1;
    struct ModelRoData_DisplayList_CollisionRecord *temp_s4;
    ModelNode *mnode;
    s32 padding;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);
    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], 0, 1);
    set_item_visibility_in_objinstance(walletinst[0], 0x13, 1);
    set_item_visibility_in_objinstance(walletinst[0], 0x14, 1);
    tab_prev_highlight = 0;
    mission_difficulty_highlighted = -1;

    if (frontCheckCursorOnPreviousTab() != 0)
    {
        tab_prev_highlight = 1;
    }
    else
    {
        for (var_s4 = 0; var_s4 < 5; )
        {
            if (var_s4 < 4)
            {
                if(!((cursor_xpos_table_mission_select[var_s4] + cursor_xpos_table_mission_select[var_s4+1]) * 0.5f > cursor_h_pos))
                {
                    var_s4++;
                    continue;
                }
            }

            break;
        }

        for (var_s2 = 0; var_s2 < 4; )
        {
            if (var_s2 < 3)
            {
                if(!((cursor_ypos_table_mission_select[var_s2] + cursor_ypos_table_mission_select[var_s2+1]) * 0.5f > cursor_v_pos))
                {
                    var_s2++;
                    continue;
                }
            }

            break;
        }

        for ( ; var_s2 > 0; var_s2--)
        {
            for (var_s1 = 0; var_s1 < 5; var_s1++)
            {
                if (get_highest_unlocked_difficulty_for_level((var_s2 * 5) + var_s1) >= 0)
                {
                    break;
                }
            }

            if (var_s1 < 5)
            {
                break;
            }

            if (1);
        }

        for ( ; var_s4 >= 0; var_s4--)
        {
            if (get_highest_unlocked_difficulty_for_level((var_s2 * 5) + var_s4) >= 0)
            {
                break;
            }
        }

        if (var_s4 < 0)
        {
            for (var_s4 = 0; var_s4 < 5; var_s4++)
            {
                if (get_highest_unlocked_difficulty_for_level((var_s2 * 5) + var_s4) >= 0)
                {
                    break;
                }
            }
        }

        mission_difficulty_highlighted = (var_s2 * 5) + var_s4;
    }

    mnode = walletinst[0]->obj->Switches[0x15];

    if (mnode != NULL)
    {
        temp_s4 = (struct ModelRoData_DisplayList_CollisionRecord *)mnode->Data;

        temp_s1 = (struct ModelRwData_DisplayList_CollisionRecord *)modelGetNodeRwData(walletinst[0], mnode);
        temp_s1->Vertices = dynAllocateVertices(temp_s4->numVertices);

        for (i = 0; i < temp_s4->numVertices; i++)
        {
            // struct copy
            temp_s1->Vertices[i] = temp_s4->Vertices[i];

            temp_a0 = i / 4;

            if (get_highest_unlocked_difficulty_for_level(temp_a0) >= 0)
            {
                if (temp_a0 == mission_difficulty_highlighted)
                {
                    temp_s1->Vertices[i].r = 0xff;
                    temp_s1->Vertices[i].g = 0xff;
                    temp_s1->Vertices[i].b = 0xff;
                    temp_s1->Vertices[i].a = 0xf5;
                }
                else
                {
                    temp_s1->Vertices[i].r = 0x6e;
                    temp_s1->Vertices[i].g = 0x6e;
                    temp_s1->Vertices[i].b = 0x6e;
                    temp_s1->Vertices[i].a = 0xff;
                }
            }
            else
            {
                temp_s1->Vertices[i].r = 0xf;
                temp_s1->Vertices[i].g = 0xf;
                temp_s1->Vertices[i].b = 0xf;
                temp_s1->Vertices[i].a = 0xff;
            }
        }
    }

    if (joyGetButtonsPressedThisFrame(0, A_BUTTON | START_BUTTON | Z_TRIG) != 0)
    {
        if (tab_prev_highlight != 0)
        {
            tab_prev_selected = 1;

            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
        else if (mission_difficulty_highlighted >= 0)
        {
            briefingpage = pull_and_display_text_for_folder_a0(mission_difficulty_highlighted);
            selected_stage = mission_folder_setup_entries[briefingpage].stage_id;
            tab_next_selected = 1;

            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }
    else if (joyGetButtonsPressedThisFrame(0, B_BUTTON) != 0)
    {
        tab_prev_selected = 1;

        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    frontUpdateControlStickPosition();

    if (tab_next_selected != 0)
    {
        frontChangeMenu(MENU_DIFFICULTY, 0);

#if defined(VERSION_JP) || defined(VERSION_EU)
        if (j_text_trigger != 0)
        {
            set_cursor_pos_difficulty(0);
        }
        else
#endif
        {
            set_cursor_pos_difficulty(get_highest_unlocked_difficulty_for_level(mission_folder_setup_entries[briefingpage].mission_num));
        }
    }
    else if (tab_prev_selected != 0)
    {
        frontChangeMenu(MENU_MODE_SELECT, 0);
        setCursorPOSforMode(0);
    }
}


void set_cursor_to_stage_solo(LEVEL_SOLO_SEQUENCE level)
{
    cursor_h_pos = cursor_xpos_table_mission_select[level % 5];
    cursor_v_pos = cursor_ypos_table_mission_select[level / 5];
}

// Address 0x7F00E458 NTSC
Gfx *constructor_menu07_missionsel(Gfx *DL)
{
    s32 i;
    s32 spD8;
    s32 padding[3];
    s32 spC8;
    s32 spC4;
    s32 temp_s0;
    s32 var_s5;
    s32 padding2[5];
    u8 sp90[24];
    s32 sp8C;
    s32 sp88;
    s32 temp_v0_3;
    u8 *var_v0;
    s32 var_s3;

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    gDPSetFogColor(DL++, 0xFF, 0xFF, 0xFF, 0xFF);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    for (spD8 = 0; spD8 < 5; spD8++)
    {
        var_s3 = spD8;

        for (i = 0; i < 4 ; i++, var_s3 += 5)
        {
            temp_s0 = pull_and_display_text_for_folder_a0(var_s3);

            if (get_highest_unlocked_difficulty_for_level(var_s3) >= 0)
            {
                var_s5 = 0x96969600;

                if (var_s3 == mission_difficulty_highlighted)
                {
                    var_s5 = -0x100;
                }

                if (mission_folder_setup_entries[temp_s0].icon_text_preset)
                {
                    strcpy(sp90, langGet(mission_folder_setup_entries[temp_s0].icon_text_preset));
                }
                else
                {
                    strcpy(sp90, langGet(mission_folder_setup_entries[temp_s0].folder_text_preset));
                }

                if (j_text_trigger == 0)
                {
                    temp_v0_3 = strlen(sp90) - 1;
                    for (; temp_v0_3 >= 0; temp_v0_3--)
                    {
                        if (sp90[temp_v0_3] >= 'a')
                        {
                            sp90[temp_v0_3] -= 0x20;
                        }
                    }
                }

                strcat(sp90, "\n");

                spC4 = 0;
                spC8 = 0;

                textMeasure(&spC8, &spC4, sp90, ptrFontBankGothicChars, ptrFontBankGothic, 0);

                sp8C = cursor_xpos_table_mission_select[spD8] - 0x1F;
                sp88 = (cursor_ypos_table_mission_select[i] - spC8) + 0x1D;

                DL = microcode_constructor_related_to_menus(DL, sp8C, sp88, sp8C + spC4, sp88 + spC8, 0);
                DL = textRender(DL, &sp8C, &sp88, sp90, ptrFontBankGothicChars, ptrFontBankGothic, var_s5 | 0xFF, viGetX(), viGetY(), 0, 0);

                sp8C = cursor_xpos_table_mission_select[spD8] - 0x1F;
                sp88 = (cursor_ypos_table_mission_select[i] - spC8) + 0x1D;

                DL = textRender(DL, &sp8C, &sp88, sp90, ptrFontBankGothicChars, ptrFontBankGothic, var_s5 | 0x64, viGetX(), viGetY(), 0, 0);

            }
        }
    }

    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);
}



//********************************************************************************************************
//DIFFICULTY SELECT
//********************************************************************************************************
void init_menu08_difficultyselect(void)
{
    selected_difficulty = DIFFICULTY_MULTI;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    load_walletbond();
}

void update_menu08_difficulty(void) {
    return;
}


void interface_menu08_difficulty(void)
{
    s32 unlockedDifficulty;

    unlockedDifficulty = get_highest_unlocked_difficulty_for_level(mission_folder_setup_entries[briefingpage].mission_num);
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);
    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CONFIDENTIAL, 1);
    tab_prev_highlight = FALSE;
    mission_difficulty_highlighted = DIFFICULTY_MULTI;

    if (frontCheckCursorOnPreviousTab())
    {
        tab_prev_highlight = TRUE;
    }
    else if ((unlockedDifficulty >= DIFFICULTY_007) && (cursor_v_pos >= 275.0f))
    {
        mission_difficulty_highlighted = DIFFICULTY_007;
    }
    else if ((unlockedDifficulty >= DIFFICULTY_00) && (cursor_v_pos >= 243.0f))
    {
        mission_difficulty_highlighted = DIFFICULTY_00;
    }
    else if ((unlockedDifficulty > DIFFICULTY_AGENT) && (cursor_v_pos >= 211.0f))
    {
        mission_difficulty_highlighted = DIFFICULTY_SECRET;
    }
    else
    {
        mission_difficulty_highlighted = DIFFICULTY_AGENT;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
    {
        if (tab_prev_highlight)
        {
            tab_prev_selected = TRUE;

            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
        else
        {
            if (mission_difficulty_highlighted >= DIFFICULTY_AGENT)
            {
                selected_difficulty = mission_difficulty_highlighted;
                tab_next_selected = TRUE;

                sndPlaySfx(g_musicSfxBufferPtr, PAPER_TURN_SFX, NULL);
            }
        }
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    frontUpdateControlStickPosition();

    if (tab_next_selected)
    {
        if (selected_difficulty == DIFFICULTY_007)
        {
            frontChangeMenu(MENU_007_OPTIONS, FALSE);
            frontSetCursorPositionToNextTab();

            return;
        }

        frontChangeMenu(MENU_BRIEFING, FALSE);
        frontSetCursorPositionToNextTab();

        return;
    }
    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MISSION_SELECT, FALSE);
        set_cursor_to_stage_solo(mission_folder_setup_entries[briefingpage].mission_num);
    }
}


Gfx * print_current_solo_briefing_stage_name(Gfx *DL, char *text)
{
    s32 x;
    s32 y;

    int chapter;

    if (selected_difficulty >= DIFFICULTY_AGENT)
    {
        strcpy(text, get_ptr_difficulty_name(selected_difficulty));
        strcat(text, langGet(getStringID(LTITLE, TITLE_STR_32_JB)));
        x = 0x37;
        y = 0x57;
        DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xff, viGetX(), viGetY(), 0, 0);
    }

    chapter = get_chapter_briefing_entry(briefingpage);
    if (chapter >=0 )
    {
        strcpy(text, langGet(getStringID(LTITLE, TITLE_STR_33_MISSION2)));
        strcat(text, mission_folder_setup_entries[chapter].string_ptr);
        strcat(text, ": ");
        strcat(text, langGet(mission_folder_setup_entries[chapter].folder_text_preset));
        strcat(text, "\n");
        x = 0x37;
        y = 0x67;
        DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xff, viGetX(), viGetY(), 0, 0);
    }

    strcpy(text, langGet(getStringID(LTITLE, TITLE_STR_34_PART)));
    strcat(text, mission_folder_setup_entries[briefingpage].string_ptr);
    strcat(text, ": ");
    strcat(text, langGet(mission_folder_setup_entries[briefingpage].folder_text_preset));
    strcat(text, "\n");
    x = 0x37;
    y = 0x77;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xff, viGetX(), viGetY(), 0, 0);
    return DL;
}


void set_cursor_pos_difficulty(int difficulty)
{
    cursor_h_pos = 106.0;
    cursor_v_pos = difficulty * 0x1e + 0xba;
}





/**
 * See notes below. Assume this is not in original codebase.
*/
struct MatchHack_front_rodata_3000 { u8 data[0xbb8]; };

/**
 * See notes below. Assume this is not in original codebase.
 * (the struct isn't, but the 3000 character newline string is)
*/
#ifndef VERSION_EU
const struct MatchHack_front_rodata_3000 asc_D_8004F4B4 = { "\n" };
#endif

Gfx *constructor_menu08_difficulty(Gfx *DL)
{
    u8 *text_sp3180;
    s32 unlockedDifficulty; // sp3176
    u8 *text_sp3172;
    s32 x;    // sp3168
    s32 y;    // sp3164 (sp164 + 3000)

    // This should be a `u8 [3000]`, see notes below.
    struct MatchHack_front_rodata_3000 stagename_struct;

    u8 *text_sp160; // sp ??
    s32 sp9C;                         // sp156
    s32 sp98;                         // sp152
    f32 xypos[2];                     // sp144
    f32 halfedxy[2];                  // sp136
    struct sImageTableEntry *image;   // sp ??
    s32 i;

    unlockedDifficulty = get_highest_unlocked_difficulty_for_level(mission_folder_setup_entries[briefingpage].mission_num);

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
#ifdef VERSION_EU
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);

#ifndef VERSION_EU
    /**
     * MatchHack notes:
     *
     * There is a chunk of auto generated code that copies 3000 characters
     * into the `stagename` variable. These 3000 characters are .rodata.
     * It would make sense that this is an array initialization spot,
     * but that means this is the start of a basic block which causes
     * problems ... but that might indicate there was a seperate DEBUG
     * difficulty menu. Anyways, a basic block split here messes
     * with the `DL` variable.
     * So that leaves struct copy, which just seems wrong.
     * But at least it matches.
     * -BB Feb 3, 2022
    */
    stagename_struct = asc_D_8004F4B4;
#endif

    DL = microcode_constructor(DL);
    DL = print_current_solo_briefing_stage_name(DL, &stagename_struct);

    //  "DIFFICULTY:\n"
    text_sp3180 = langGet(getStringID(LTITLE, TITLE_STR_35_DIFFICULTY));
    x = 0x37;
    y = 0x8F;
    DL = frontPrintText(DL, &x, &y, text_sp3180, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    if (mission_difficulty_highlighted >= 0)
    {
        DL = microcode_constructor_related_to_menus(
            DL,
            0x7E - (j_text_trigger ? 0x32 : 0),
            (mission_difficulty_highlighted * 0x1E) + 0xB2,
            0xF0,
            (mission_difficulty_highlighted * 0x1E) + 0xC3,
            0x32);
    }

    /**
     * Draw the list of available difficulties. Each item is
     * prefixed with a number.
    */
    for (i=0; i<DIFFICULTY_MAX; i++)
    {
        if (i == 0 || unlockedDifficulty >= i)
        {
            if (j_text_trigger)
            {
                switch (i)
                {
                    case 0:
                        text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_265_1DOT)); // "1.\n"
                        break;
                    case 1:
                        text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_266_2DOT)); // "2.\n"
                        break;
                    case 2:
                        text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_267_3DOT)); // "3.\n"
                        break;
                    case 3:
                        text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_268_4DOT)); // "4.\n"
                        break;
                }
            }
            else
            {
                sprintf(&stagename_struct, "%d.\n", i + 1);
                text_sp160 = &stagename_struct;
            }

            textMeasure(&sp98, &sp9C, text_sp160, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            x = 0x82 - (j_text_trigger ? (sp9C - 0xA) : 0);
            y = (i * 0x1E) + 0xB4;
            DL = frontPrintText(DL, &x, &y, text_sp160, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

            switch (i)
            {
                case 0:
                    text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_36_AGENT2)); // "Agent\n"
                    break;
                case 1:
                    text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_37_SECRETAGENT2)); // "Secret Agent\n"
                    break;
                case 2:
                    text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_38_00AGENT2)); // "00 Agent\n"
                    break;
                case 3:
                    text_sp160 = langGet(getStringID(LTITLE, TITLE_STR_39_0072)); // "007\n"
                    break;
            }

            x = 0x96;
            y = (i * 0x1E) + 0xB4;
            DL = frontPrintText(DL, &x, &y, text_sp160, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }
    }

    DL = frontAddPreviousTabText(DL);

    /**
     * Draw the checkmark for completed difficulties.
    */
    for (i=0; i<3; i++)
    {
        if ((i == 0 || unlockedDifficulty >= i)
            && (check_if_stage_completed_on_difficulty(briefingpage, i) == 3))
        {
            image = &mainfolderimages[IMAGE_CHECK];

            xypos[0] = 280.0f;
            xypos[1] = (f32) ((i * 0x1E) + 0xBA);

            halfedxy[0] = image->width * 0.5f;
            halfedxy[1] = image->height * 0.5f;

            texSelect(&DL, image, 4, 0, 0);
            display_image_at_position(&DL, &xypos, &halfedxy, image->width, image->height, 0, 0, 1, 0xB4, 0, 0, 0xFF, image->level > 0, 0);
        }
    }

    DL = frontDrawCursor(DL);

    return DL;
}

//********************************************************************************************************
//007 DIFFICULTY SELECT
//********************************************************************************************************

void init_menu09_007difficultyselect(void)
{
    tab_start_selected = 0;
    tab_next_selected = 0;
    tab_prev_selected = 0;
    tab_prev_highlight = 0;
    tab_next_highlight = 0;
    tab_start_highlight = 0;
    highlight_enemy_reaction = 0;
    highlight_enemy_health = 0;
    highlight_enemy_damage = 0;
    highlight_enemy_accuracy = 0;
    load_walletbond();
}


void update_menu09_007options(void) 
{
    return;
}


void interface_menu09_007options(void)
{
    f32 temp_x;
    s32 temp_y;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);
    if (joyGetButtons(PLAYER_1, Z_TRIG|A_BUTTON) == 0)
    {
        tab_prev_highlight = FALSE;
        tab_next_highlight = FALSE;
        tab_start_highlight = FALSE;
        highlight_enemy_reaction = FALSE;
        highlight_enemy_health = FALSE;
        highlight_enemy_damage = FALSE;
        highlight_enemy_accuracy = FALSE;

        if (frontCheckCursorOnPreviousTab())
        {
            tab_prev_highlight = TRUE;
        }
        else if (frontCheckCursorOnNextTab())
        {

            tab_next_highlight = TRUE;
        }
        else if (frontCheckCursorOnStartTab())
        {
            tab_start_highlight = TRUE;
        }
        else
        {
            temp_y = (s32) cursor_v_pos;
            if (temp_y >= 0x107)
            {
                highlight_enemy_reaction = TRUE;
            }
            else if (temp_y >= 0xE6)
            {
                highlight_enemy_accuracy = TRUE;
            }
            else if (temp_y >= 0xC5)
            {
                highlight_enemy_damage = TRUE;
            }
            else if (temp_y >= 0xA4)
            {
                highlight_enemy_health = TRUE;
            }
            else
            {
                tab_next_highlight = TRUE;
            }
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON))
    {
        tab_start_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON))
    {
        if (tab_next_highlight)
        {
            tab_next_selected = TRUE;
        }
        else if (tab_prev_highlight)
        {
            tab_prev_selected = TRUE;
        }
        else if (tab_start_highlight)
        {
            tab_start_selected = TRUE;
        }
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    if (joyGetButtons(PLAYER_1, Z_TRIG|A_BUTTON))
    {
        temp_x = (cursor_h_pos - 55.0f) / 300.0f;

        if (temp_x > 1.0f)
        {
            temp_x = 1.0f;
        }

        if (temp_x < 0.0f)
        {
            temp_x = 0.0f;
        }

        if (highlight_enemy_reaction)
        {
            slider_007_mode_reaction = temp_x;
        }
        else if (highlight_enemy_health)
        {
            slider_007_mode_health = (f32) (temp_x * temp_x * 10.0f);
        }
        else if (highlight_enemy_damage)
        {
            slider_007_mode_damage = (f32) (temp_x * temp_x * 10.0f);
        }
        else if (highlight_enemy_accuracy)
        {
            slider_007_mode_accuracy = (f32) (temp_x * temp_x * 10.0f);
        }
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();

    if (tab_start_selected)
    {
        frontChangeMenu(MENU_RUN_STAGE, TRUE);
        return;
    }

    if (tab_next_selected)
    {
        frontChangeMenu(MENU_BRIEFING, FALSE);
        return;
    }

    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_DIFFICULTY, FALSE);
        set_cursor_pos_difficulty(selected_difficulty);
    }
}


#if !defined(VERSION_EU)
const struct MatchHack_front_rodata_3000 asc_D_80050074 = { "\n" };
#endif

/**
 * Render the 007 Mode options. The slider bars are 300 pixels wide and
 * sit 33 pixels apart vertically.
 */
Gfx *constructor_menu09_007options(Gfx *DL)
{
    u8 *labeltext;
    s32 textx;
    s32 texty;
    struct MatchHack_front_rodata_3000 textbuffer;
    s32 textheight;
    s32 textwidth;
    s32 barwidth;

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
#if defined(VERSION_EU)
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);

#if !defined(VERSION_EU)
    textbuffer = asc_D_80050074;
#endif

    DL = microcode_constructor(DL);
    DL = print_current_solo_briefing_stage_name(DL, (char*)&textbuffer);

    labeltext = langGet(getStringID(LTITLE, TITLE_STR_40_SPECOPS)); /* SPECIAL OPTIONS */

    textx = 55;
    texty = 143;

    DL = frontPrintText(DL, &textx, &texty, (s8 *)labeltext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    /**
     * ENEMY HEALTH
     */
    labeltext = langGet(getStringID(LTITLE, TITLE_STR_42_HEALTH)); /* Enemy health */

    textx = 57;
    texty = 164;

    // Render the bar background with a black color and an opacity of 50/255.
    DL = microcode_constructor_related_to_menus(DL, 55, 181, 355, 192, 0x00000032);

    barwidth = (sqrtf(slider_007_mode_health / 10.0f)) * 300.0f;

    // Render the filled portion of the bar with a black color and an opacity of 100/255.
    DL = microcode_constructor_related_to_menus(DL, 55, texty + 17, barwidth + 55, texty + 28, 0x00000064);

    if (highlight_enemy_health != 0)
    {
        // Render a black rectangle over the "Enemy health" text to indicate it's highlighted.
        DL = microcode_constructor_related_to_menus(DL, 55, texty - 1, 199, texty + 14, 0x00000032);
    }

    // Render "Enemy health" text.
    DL = frontPrintText(DL, &textx, &texty, (s8 *)labeltext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&textbuffer, "%d%%\n", (s32) (slider_007_mode_health * 100.0f));

    textwidth = 0;
    textheight = 0;

    textMeasure(&textheight, &textwidth, (char*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    textx = 285 - textwidth;
    texty = 164;

    // Render enemy health percentage text.
    DL = frontPrintText(DL, &textx, &texty, (s8*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    /**
     * ENEMY DAMAGE
     */
    labeltext = langGet(getStringID(LTITLE, TITLE_STR_43_DAMAGE)); /* Enemy damage */

    textx = 57;
    texty = 197;

    DL = microcode_constructor_related_to_menus(DL, 55, 214, 355, 225, 0x00000032);
    barwidth = (sqrtf(slider_007_mode_damage / 10.0f)) * 300.0f;
    DL = microcode_constructor_related_to_menus(DL, 55, texty + 17, barwidth + 55, texty + 28, 0x00000064);

    if (highlight_enemy_damage != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 55, texty - 1, 199, texty + 14, 0x00000032);
    }

    DL = frontPrintText(DL, &textx, &texty, (s8*)labeltext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&textbuffer, "%d%%\n", (s32) (slider_007_mode_damage * 100.0f));

    textwidth = 0;
    textheight = 0;

    textMeasure(&textheight, &textwidth, (char*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    textx = 285 - textwidth;
    texty = 197;

    // Render enemy damage percentage text.
    DL = frontPrintText(DL, &textx, &texty, (s8*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    /**
     * ENEMY ACCURACY
     */
    labeltext = langGet(getStringID(LTITLE, TITLE_STR_44_ACCURACY)); /* Enemy accuracy */

    textx = 57;
    texty = 230;

    DL = microcode_constructor_related_to_menus(DL, 55, 247, 355, 258, 0x00000032);
    barwidth = (sqrtf(slider_007_mode_accuracy / 10.0f)) * 300.0f;
    DL = microcode_constructor_related_to_menus(DL, 55, texty + 17, barwidth + 55, texty + 28, 0x00000064);

    if (highlight_enemy_accuracy != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 55, texty - 1, 199, texty + 14, 0x00000032);
    }

    DL = frontPrintText(DL, &textx, &texty, (s8*)labeltext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&textbuffer, "%d%%\n", (s32) (slider_007_mode_accuracy * 10.0f));

    textwidth = 0;
    textheight = 0;

    textMeasure(&textheight, &textwidth, (char*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    textx = 285 - textwidth;
    texty = 230;

    // Render enemy accuracy percentage text.
    DL = frontPrintText(DL, &textx, &texty, (s8*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    /**
     * ENEMY REACTION
     */
    labeltext = langGet(getStringID(LTITLE, TITLE_STR_41_REACTION)); /* Enemy reaction speed */

    textx = 57;
    texty = 263;

    DL = microcode_constructor_related_to_menus(DL, 55, 280, 355, 291, 0x00000032);
    DL = microcode_constructor_related_to_menus(DL, 55, texty + 17, (s32) (slider_007_mode_reaction * 300.0f * 1) + 55, texty + 28, 0x00000064);

    if (highlight_enemy_reaction != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 55, texty - 1, 199, texty + 14, 0x00000032);
    }

    DL = frontPrintText(DL, &textx, &texty, (s8*)labeltext, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&textbuffer, "%d%%\n", (s32) (slider_007_mode_reaction * 100.0f));

    textwidth = 0;
    textheight = 0;

    textMeasure(&textheight, &textwidth, (char*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    textx = 285 - textwidth;
    texty = 263;

    // Render enemy reaction speed percentage text.
    DL = frontPrintText(DL, &textx, &texty, (s8*)&textbuffer, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    DL = frontAddStartTabText(DL);
    DL = frontAddPreviousTabText(DL);
    DL = frontAddNextTabText(DL);
    DL = frontDrawCursor(DL);

    return DL;
}


u32 get_player_control_style(s32 playernum)
{
  return controlstyle_player[playernum];
}


s32 check_if_mp_stage_unlocked(s32 stage)
{
    s32 players;
    if (!multi_stage_setups[stage].min_player)
    {
        return FALSE;
    }
    players=get_selected_num_players();
    if (multi_stage_setups[stage].max_player < players)
    {
        return FALSE;
    }
    if (multi_stage_setups[stage].unlock_after == -1)
    {
        return TRUE;
    }
    if ( fileIsStageUnlockedAtDifficulty(selected_folder_num, multi_stage_setups[stage].unlock_after, DIFFICULTY_AGENT))
    {
        return TRUE;
    }
    return FALSE;
}


void select_game_length(void)
{
    if (scenario != SCENARIO_TLD)
    {
        game_length = (s32) ((s32) (game_length + 1) % 7);
        return;
    }
    game_length = (s32) ((s32) (game_length + 1) % 4);
}


void copy_aim_settings_to_playerdata(void)
{
    s32 i;
    struct player_data * p;

    for (i = 0; i < 4; i++)
    {
        p = &g_playerPlayerData[i];
        p->autoaim = mp_sight_adjust_table[aim_sight_adjustment].autoaim;
        p->sight   = mp_sight_adjust_table[aim_sight_adjustment].sight;
    }
}


void advance_aim_settings_selection(void)
{
    aim_sight_adjustment = (s32) ((s32) (aim_sight_adjustment + 1) % 4);
    copy_aim_settings_to_playerdata();
}


void unlock_all_mp_chars(void) {
    num_chars_selectable_mp = 0x40;
}


s32 get_selected_num_players(void)
{
    if (gamemode == GAMEMODE_MULTI)
    {
        return selected_num_players;
    }
    return 1;
}

u16 get_player_mp_char_head(s32 player)
{
    if (player_char[player] < 0)
    {
        return mp_chr_setup[player].head;
    }
    return mp_chr_setup[player_char[player]].head;
}

u8 get_player_mp_char_gender(s32 player)
{
    if (player_char[player] < 0)
    {
        return mp_chr_setup[player].gender;
    }
    return mp_chr_setup[player_char[player]].gender;
}

u16 get_player_mp_char_body(s32 player)
{
    if (player_char[player] < 0)
    {
        return mp_chr_setup[player].body;
    }
    return mp_chr_setup[player_char[player]].body;
}

f32 get_player_mp_handicap(s32 player)
{
    return MP_handicap_table[player_handicap[player]].damage_modifier;
}

f32 get_player_mp_char_height(s32 player)
{
    if (player_char[player] < 0) {
        return mp_chr_setup[player].pov;
    }
    return mp_chr_setup[player_char[player]].pov;
}

s32 get_mp_timelimit(void) {
  return multi_game_lengths[game_length].time;
}

s32 get_mp_pointlimit(void) {
  return multi_game_lengths[game_length].points;
}

void reset_mp_options_for_scenario(MPSCENARIOS scenarioid)
{
    scenario = scenarioid;

    unlock_stage_select = 1;
    unlock_game_length = 1;
    unlock_chars = 1;
    unlock_weapon_select = 1;
    unlock_handicap = 1;
    unlock_control_style = 1;
    unlock_aim_sight = 1;


    switch(scenario)
    {
    case SCENARIO_NORMAL:
    case SCENARIO_2v2:
    case SCENARIO_3v1:
    case SCENARIO_2v1:
        if (6 < game_length)
        {
            game_length = 2;
        }
        if (0xd < getMPWeaponSet())
        {
            setMPWeaponSet(0xd);
        }
        break;
    case SCENARIO_YOLT:
        game_length = 7;

        if (0xd < getMPWeaponSet())
        {
            setMPWeaponSet(0xd);
        }
        unlock_game_length = 0;
        break;
    case SCENARIO_TLD:
        if (3 < game_length)
        {
            game_length = 2;
        }
        if (0xd < getMPWeaponSet())
        {
            setMPWeaponSet(0xd);
        }
        break;
    case SCENARIO_MWTGG:
        if (6 < game_length)
        {
            game_length = 2;
        }
        setMPWeaponSet(0xd);
        unlock_weapon_select = 0;
        break;
    case SCENARIO_LTK:
        if (6 < game_length)
        {
            game_length = 2;
        }
        setMPWeaponSet(1);
        unlock_handicap = 0;
    }
    return;
}




// Address 0x7F010608 NTSC
void init_mp_options_for_scenario(s32 numplayers)
{
    s32 i;

    if (numplayers < 2)
    {
        numplayers = 2;
    }

    selected_num_players = numplayers;

    for (i=0; i < selected_num_players; i++)
    {
        if (player_char[i] == -1)
        {
            player_char[i] = i;
            player_handicap[i] = 5;
        }

        if ((numplayers >= 3) && (controlstyle_player[i] >= CONTROLLER_CONFIG_PLENTY))
        {
            controlstyle_player[i] = CONTROLLER_CONFIG_HONEY;
        }
    }

    if ((mp_player_counts[scenario].max < selected_num_players) || (selected_num_players < mp_player_counts[scenario].min))
    {
        reset_mp_options_for_scenario(SCENARIO_NORMAL);

    }

    if (multi_stage_setups[MP_stage_selected].max_player < selected_num_players)
    {
        MP_stage_selected = MP_STAGE_TEMPLE;
    }
}


//********************************************************************************************************
//MULTIPLAYER OPTIONS
//********************************************************************************************************
void init_menu0E_mpoptions(void)
{
    int numplayers;

    tab_start_selected = FALSE;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;

    if (maybe_is_in_menu)
    {
        sndApplyVolumeAllSfxSlot(0x7fff);
        musicTrack1ApplySeqpVol(0x7fff);
        g_musicXTrack1Fade = MUSIC_FADESTATE_UNSET;
        musicTrack1Play(M_FOLDERS);
        maybe_is_in_menu = FALSE;
    }

    if (selected_num_players == 0)
    {
        numplayers = joyGetControllerCount();
        init_mp_options_for_scenario(numplayers);
    }

    if (check_if_mp_stage_unlocked(MP_stage_selected) == FALSE)
    {
        MP_stage_selected = MP_STAGE_TEMPLE;
    }

    highlight_players = FALSE;
    highlight_scenario = FALSE;
    highlight_gameselect = FALSE;
    highlight_gamelength = FALSE;
    highlight_character = FALSE;
    highlight_weaponselect = FALSE;
    highlight_health = FALSE;
    highlight_controlstyle = FALSE;
    highlight_aimadjustment = FALSE;
    load_walletbond();
}

void update_menu0E_mpoptions(void)
{
    return;
}





// Address 0x7F010848 NTSC
void interface_menu0E_mpoptions(void)
{
    s32 players_selected = 0;
    s32 scenario_selected = 0;
    s32 gameselect_selected = 0;
    s32 gamelength_selected = 0;
    s32 character_selected = 0;
    s32 weapon_selected = 0;
    s32 health_selected = 0;
    s32 controlstyle_selected = 0;
    s32 aimadjust_selected = 0;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    if (joyGetControllerCount() < 2)
    {
        frontChangeMenu(MENU_MODE_SELECT, 0);
        setCursorPOSforMode(gamemode);
    }

    if (joyGetControllerCount() < selected_num_players)
    {
        init_mp_options_for_scenario(joyGetControllerCount());
    }

    if (joyGetButtons(PLAYER_1, Z_TRIG|A_BUTTON) == 0)
    {
        tab_prev_highlight = 0;
        tab_next_highlight = 0;
        tab_start_highlight = 0;
        highlight_players = 0;
        highlight_scenario = 0;
        highlight_gameselect = 0;
        highlight_gamelength = 0;
        highlight_character = 0;
        highlight_weaponselect = 0;
        highlight_health = 0;
        highlight_controlstyle = 0;
        highlight_aimadjustment = 0;

        if (frontCheckCursorOnPreviousTab())
        {
            tab_prev_highlight = 1;
        }
        else if (frontCheckCursorOnStartTab())
        {
            tab_start_highlight = 1;
        }
        else
        {
            s32 temp_f6 = cursor_v_pos;
            if ((temp_f6 >= 0x119) && (unlock_aim_sight))
            {
                highlight_aimadjustment = 1;
            }
            else if ((temp_f6 >= 0x105) && (unlock_control_style))
            {
                highlight_controlstyle = 1;
            }
            else if ((temp_f6 >= 0xF1) && (unlock_handicap))
            {
                highlight_health = 1;
            }
            else if ((temp_f6 >= 0xDD) && (unlock_chars))
            {
                highlight_character = 1;
            }
            else if ((temp_f6 >= 0xC9) && (unlock_weapon_select))
            {
                highlight_weaponselect = 1;
            }
            else if ((temp_f6 >= 0xB5) && (unlock_game_length))
            {
                highlight_gamelength = 1;
            }
            else if ((temp_f6 >= 0xA1) && (unlock_stage_select))
            {
                highlight_gameselect = 1;
            }
            else if (temp_f6 >= 0x8D)
            {
                highlight_scenario = 1;
            }
            else
            {
                highlight_players = 1;
            }
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON))
    {
        tab_start_selected = 1;
        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON))
    {
        if (tab_prev_highlight)
        {
            tab_prev_selected = 1;
        }

        if (tab_start_highlight)
        {
            tab_start_selected = 1;
        }
        else if (highlight_players)
        {
            players_selected = 1;
        }
        else if (highlight_scenario)
        {
            scenario_selected = 1;
        }
        else if (highlight_gameselect)
        {
            gameselect_selected = 1;
        }
        else if (highlight_gamelength)
        {
            gamelength_selected = 1;
        }
        else if (highlight_character)
        {
            character_selected = 1;
        }
        else if (highlight_weaponselect)
        {
            weapon_selected = 1;
        }
        else if (highlight_health)
        {
            health_selected = 1;
        }
        else if (highlight_controlstyle)
        {
            controlstyle_selected = 1;
        }
        else if (highlight_aimadjustment)
        {
            aimadjust_selected = 1;
        }

        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = 1;
        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CONFIDENTIAL2, 1);
    frontUpdateControlStickPosition();

    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MODE_SELECT, 0);
        setCursorPOSforMode(gamemode);
        return;
    }

    if (tab_start_selected)
    {
        if (multi_stage_setups[MP_stage_selected].stage_id < 0)
        {
            s32 temp_hi;
            do
            {
                temp_hi = randomGetNext() % (u32)(MP_STAGE_SELECTED_MAX - 1);
                selected_stage = multi_stage_setups[1 + temp_hi].stage_id;
            } while (check_if_mp_stage_unlocked(temp_hi + 1) == 0);
        }
        else
        {
            selected_stage = multi_stage_setups[MP_stage_selected].stage_id;
        }

        briefingpage = -1;
        frontChangeMenu(MENU_RUN_STAGE, 1);

        return;
    }

    if (players_selected)
    {
        s32 tmpNumPlayers;

        if (joyGetControllerCount() < selected_num_players + 1)
        {
            tmpNumPlayers = 2;
        }
        else
        {
            tmpNumPlayers = selected_num_players + 1;
        }

        init_mp_options_for_scenario(tmpNumPlayers);

        return;
    }
    if (scenario_selected)
    {
        frontChangeMenu(MENU_MP_SCENARIO_SELECT, 0);
        return;
    }
    if (gameselect_selected)
    {
        frontChangeMenu(MENU_MP_STAGE_SELECT, 0);
        return;
    }
    if (gamelength_selected)
    {
        select_game_length();
        return;
    }
    if (character_selected)
    {
        frontChangeMenu(MENU_MP_CHAR_SELECT, 0);
        return;
    }
    if (weapon_selected)
    {
        incrementMPWeaponSet();
        return;
    }
    if (health_selected)
    {
        frontChangeMenu(MENU_MP_HANDICAP, 0);
        return;
    }
    if (controlstyle_selected)
    {
        frontChangeMenu(MENU_MP_CONTROL_STYLE, 0);
        return;
    }
    if (aimadjust_selected)
    {
        advance_aim_settings_selection();
    }
}


Gfx * constructor_menu0E_mpoptions(Gfx *DL)
{
    u8 *text;

    char acStack12 [8];

    s32 x;
    s32 y;

    int iStack24;
    int iStack28;
    u32 entry;


  DL = viSetFillColor(DL,0,0,0);
  DL = viFillScreen(DL);
  #if defined(BUGFIX_R2)
  DL = viFillScreen(DL);
  DL = viFillScreen(DL);
  #endif
  DL = frontSetupMenuBackground(DL);
  DL = microcode_constructor(DL);
  text = langGet(getStringID(LTITLE, TITLE_STR_76_MPOPTIONS));
  x = 0x37;
  y = 0x5f;
  DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xff, viGetX(), viGetY(), 0, 0);

  text = langGet(getStringID(LTITLE, TITLE_STR_77_PLAYERS));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0x79;
  if (highlight_players) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0x78,iStack28 + 0x3c,0x87,0x32);
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,0xff,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_78_SCENARIO));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0x8d;
  if (highlight_scenario) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0x8c,iStack28 + 0x3c,0x9b,0x32);
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,0xff,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_79_LEVEL));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0xa1;
  if (highlight_gameselect) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0xa0,iStack28 + 0x3c,0xaf,0x32);
  }
  if (unlock_stage_select) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_80_GAMELENGTH));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0xb5;
  if (highlight_gamelength) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0xb4,iStack28 + 0x3c,0xc3,0x32);
  }
  if (unlock_game_length) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_81_WEAPONS));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0xc9;
  if (highlight_weaponselect) {
    DL = microcode_constructor_related_to_menus(DL,0x37,200,iStack28 + 0x3c,0xd7,0x32);
  }
  if (unlock_weapon_select) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_82_CHARACTER));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0xdd;
  if (highlight_character) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0xdc,iStack28 + 0x3c,0xeb,0x32);
  }
  if (unlock_chars) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_83_HEALTH));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0xf1;
  if (highlight_health) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0xf0,iStack28 + 0x3c,0xff,0x32);
  }
  if (unlock_handicap) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_286_CONTROLSTYLE));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0x105;
  if (highlight_controlstyle) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0x104,iStack28 + 0x3c,0x113,0x32);
  }
  if (unlock_control_style) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(getStringID(LTITLE, TITLE_STR_84_AIM));
  textMeasure(&iStack24,&iStack28,text,ptrFontZurichBoldChars,ptrFontZurichBold,0);
  x = 0x39;
  y = 0x119;
  if (highlight_aimadjustment) {
    DL = microcode_constructor_related_to_menus(DL,0x37,0x118,iStack28 + 0x3c,0x127,0x32);
  }
  if (unlock_aim_sight) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  sprintf(acStack12,"%d",selected_num_players);
  x = 0xa0;
  y = 0x79;
  DL = frontPrintText(DL, &x, &y, acStack12, ptrFontZurichBoldChars, ptrFontZurichBold, 0xff, viGetX(), viGetY(), 0, 0);

  text = langGet(mp_player_counts[scenario].stage);
  x = 0xa0;
  y = 0x8d;
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,0xff,viGetX(),viGetY(),0,0);

  text = langGet(multi_stage_setups[MP_stage_selected].folder_text_preset);
  x = 0xa0;
  y = 0xa1;
  if (unlock_stage_select) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(multi_game_lengths[game_length].text_preset);
  x = 0xa0;
  y = 0xb5;
  if (unlock_game_length) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);


  text = langGet(*(getPtrMPWeaponSetTextID()));
  x = 0xa0;
  y = 0xc9;
  if (unlock_weapon_select) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);

  text = langGet(mp_sight_adjust_table[aim_sight_adjustment].anonymous_0);
  x = 0xa0;
  y = 0x119;
  if (unlock_aim_sight) {
    entry = 0xFF;
  }
  else {
    entry = 0x70;
  }
  DL = frontPrintText(DL,&x,&y,text,ptrFontZurichBoldChars,ptrFontZurichBold,entry,viGetX(),viGetY(),0,0);
  DL = frontAddPreviousTabText(DL);
  DL = frontAddStartTabText(DL);
  DL = frontDrawCursor(DL);
  return DL;
}


bool get_players_who_have_selected_mp_char(s32 character)
{
    s32 i;
    bool char_is_selected;

    char_is_selected = FALSE;

    for (i = 0; i < selected_num_players; i++)
    {
        if (player_has_selected_char[i] && character == player_char[i])
        {
            char_is_selected = TRUE;
        }
    }

    return char_is_selected;
}

// Address 0x7F011C3C NTSC
void init_menu0f_mpcharsel(void)
{
    s32 i;

    tab_start_selected = 0;
    tab_next_selected = 0;
    tab_prev_selected = 0;
    tab_prev_highlight = 0;
    tab_next_highlight = 0;
    tab_start_highlight = 0;

    for ( i = 0; i < 64; i += 1)
    {
        s32 selected_photo = mp_chr_setup[i].select_photo;

        // Multiplayer character images are composed of 4 textures.

        // upper left
        if (mpcharselimages[selected_photo * 4 + 0].index < (u32)(MAX_TEXTURES - 1))
        {
            texLoadFromTextureNum(mpcharselimages[selected_photo * 4 + 0].index, 0);
        }

        // upper right
        if (mpcharselimages[selected_photo * 4 + 1].index < (u32)(MAX_TEXTURES - 1))
        {
            texLoadFromTextureNum(mpcharselimages[selected_photo * 4 + 1].index, 0);
        }

        // lower left
        if (mpcharselimages[selected_photo * 4 + 2].index < (u32)(MAX_TEXTURES - 1))
        {
            texLoadFromTextureNum(mpcharselimages[selected_photo * 4 + 2].index, 0);
        }

        // lower right
        if (mpcharselimages[selected_photo * 4 + 3].index < (u32)(MAX_TEXTURES - 1))
        {
            texLoadFromTextureNum(mpcharselimages[selected_photo * 4 + 3].index, 0);
        }
    }

    if (num_chars_selectable_mp != 0x40)
    {
        if (fileIsStageUnlockedAtDifficulty(selected_folder_num, SP_LEVEL_CRADLE, DIFFICULTY_AGENT) == STAGESTATUS_COMPLETED)
        {
            num_chars_selectable_mp = 0x21;
        }
        else
        {
            num_chars_selectable_mp = 8;

            for ( i = 0; i < MAX_PLAYER_COUNT; i++)
            {
                if (player_char[i] >= num_chars_selectable_mp)
                {
                    s32 count = 0;

                    while (count < num_chars_selectable_mp)
                    {
                        if (get_players_who_have_selected_mp_char(count) != 0)
                        {
                            count++;
                            continue;
                        }

                        break;
                    }

                    player_char[i] = count;
                }
            }
        }
    }

    for (i = 0; i < MAX_PLAYER_COUNT; i++)
    {
        mp_char_cur_select_player[i] = player_char[i];
        mp_char_prev_select_player[i] = player_char[i];
        mp_char_select_scroll_offset[i] = 0;
        player_has_selected_char[i] = 0;
        size_mp_select_image_player[i] = 0;
    }

    load_walletbond();
}



//********************************************************************************************************
//MULTIPLAYER CHARACTER SELECT
//********************************************************************************************************

void update_menu0F_mpcharsel(void) 
{
    return;
}


// Address 0x7F011ED4 NTSC
void interface_menu0F_mpcharsel(void)
{
    s32 numplayers;
    s32 padding;
    s32 ready_players;
    s32 padding2;
    s32 i;
    s32 temp_v1_3;

    numplayers = get_selected_num_players();
    ready_players = 0;
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    for (i = 0; i < numplayers; i++)
    {
        if (player_has_selected_char[i])
        {
            if ((size_mp_select_image_player[i] < 0xb) && (mp_char_prev_select_player[i] == mp_char_cur_select_player[i]))
            {
                size_mp_select_image_player[i] = size_mp_select_image_player[i] + 1;
            }

            if (joyGetButtonsPressedThisFrame(i, B_BUTTON))
            {
                player_has_selected_char[i] = 0;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }
        }

        if (player_has_selected_char[i] == 0 && size_mp_select_image_player[i] > 0)
        {
            size_mp_select_image_player[i] = size_mp_select_image_player[i] - 1;
        }
        else if (player_has_selected_char[i] == 0)
        {
            if (joyGetButtonsPressedThisFrame(i, L_JPAD|L_CBUTTONS)) // 0x202
            {
                if (mp_char_cur_select_player[i] > 0)
                {
                    mp_char_cur_select_player[i]--;
                }
            }
            else if (joyGetButtonsPressedThisFrame(i, R_JPAD|R_CBUTTONS)) // 0x101
            {
                if (mp_char_cur_select_player[i] < (num_chars_selectable_mp - 1))
                {
                    mp_char_cur_select_player[i]++;
                }
            }
            else if (joyGetButtonsPressedThisFrame(i, A_BUTTON|Z_TRIG|START_BUTTON)) // 0xb000
            {
                if (get_players_who_have_selected_mp_char(mp_char_cur_select_player[i]) == 0)
                {
                    player_char[i] = mp_char_cur_select_player[i];
                    size_mp_select_image_player[i] = 1;
                    player_has_selected_char[i] = 1;

                    sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
                }
            }
            else if (joyGetStickXInRange(i, -2, 1) > 0)
            {
                if (mp_char_select_scroll_offset[i] == 0)
                {
                    if (mp_char_cur_select_player[i] < (num_chars_selectable_mp - 1))
                    {
                        mp_char_cur_select_player[i]++;
                    }
                }
            }
            else if ((joyGetStickXInRange(i, -2, 1) < -1) && (mp_char_select_scroll_offset[i] == 0))
            {
                if (mp_char_cur_select_player[i] > 0)
                {
                    mp_char_cur_select_player[i]--;
                }
            }
        }

        temp_v1_3 = (mp_char_prev_select_player[i] * 0x54) + mp_char_select_scroll_offset[i];

        if (mp_char_cur_select_player[i] * 0x54 < temp_v1_3)
        {
            mp_char_select_scroll_offset[i] -= 0xc;
            if (mp_char_select_scroll_offset[i] < 0)
            {
                mp_char_select_scroll_offset[i] += 0x54;
                mp_char_prev_select_player[i]--;
            }
        }
        else if (temp_v1_3 < mp_char_cur_select_player[i] * 0x54)
        {
            mp_char_select_scroll_offset[i] += 0xC;
            if (mp_char_select_scroll_offset[i] >= 0x54)
            {
                mp_char_select_scroll_offset[i] -= 0x54;
                mp_char_prev_select_player[i]++;
            }
        }

        if (player_has_selected_char[i] != 0 && size_mp_select_image_player[i] == 0xb)
        {
            ready_players++;
        }
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    frontUpdateControlStickPosition();

    if (ready_players == numplayers)
    {
        frontChangeMenu(MENU_MP_OPTIONS, 0);
    }
}



s32 frontCalculateCharacterImageAlpha(s32 arg0, s32 arg1, s32 arg2)
{
    if ((arg1 >= arg0) || (arg0 >= arg2))
    {
        return 0;
    }

    if (arg0 < (arg1 + 0x28))
    {
        return 0xF - ((arg1 - arg0) * 6);
    }

    if ((arg2 - 0x28) < arg0)
    {
        return 0xF - ((arg0 - arg2) * 6);
    }

    return 0xFF;
}


// Address 0x7F01231C NTSC
Gfx *frontRenderCharacterPortrait(Gfx *DL, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    Mtx* spD4;
    Mtx* spD0;
    Vertex* spCC;
    s32 padding[26];
    u32 var_s2;
    u32 var_s3;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 var_v0;
    s32 selected_photo;
    s32 vtx_index;
    struct MP_selectable_chars *mpc;
    struct sImageTableEntry *simage;
    s32 j;
    s32 i;

    spD4 = dynAllocateMatrix();
    spD0 = dynAllocateMatrix();
    spCC = dynAllocateVertices(16);
    DL = microcode_constructor(DL);

    guOrtho(spD4, 0.0f, 440.0f, 0.0f, 330.0f, 1.0f, 10.0f, 1.0f);
    guRotate(spD0, 3.1415927f, 1.0f, 0.0f, 0.0f);

    vtx_index = 0;

    for (i = 0; i < 4; i++)
    {
        sp58 = arg6 + 0x23;
        sp54 = 0x14A - arg4;
        sp50 = arg6 + 0x2a;

        for (j = 0; j < 4; j++)
        {
            var_s3 = (j >= 2) ? j - 1 : j;
            var_s2 = (i >= 2) ? i - 1 : i;

            if ((get_players_who_have_selected_mp_char(arg5)) && (arg6 == 0))
            {
                var_v0 = 0x6E;
            }
            else
            {
                var_v0 = 0xFF;
            }

            spCC[vtx_index].coord.AsArray[0] = ((var_s3 - 1) * sp58) + arg3;
            spCC[vtx_index].coord.AsArray[1] = sp54 + ((var_s2 - 1) * sp50) + arg6;
            spCC[vtx_index].coord.AsArray[2] = -5;
            spCC[vtx_index].index = 0;

            if (j & 1)
            {
                spCC[vtx_index].s = 0x1000;
            }
            else
            {
                spCC[vtx_index].s = 0;
            }

            if (i & 1)
            {
                spCC[vtx_index].t = 0x1000;
            }
            else
            {
                spCC[vtx_index].t = 0;
            }

            spCC[vtx_index].r = var_v0;
            spCC[vtx_index].g = var_v0;
            spCC[vtx_index].b = var_v0;

            if (arg6 == 0)
            {
                spCC[vtx_index].a = frontCalculateCharacterImageAlpha(spCC[vtx_index].coord.AsArray[0], arg1, arg2);
            }
            else
            {
                spCC[vtx_index].a = 0xFF;
            }

            vtx_index++;
        }
    }

    gSPMatrix(DL++, OS_PHYSICAL_TO_K0(spD4), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(DL++, OS_PHYSICAL_TO_K0(spD0), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(DL++, spCC, 16, 0);

    selected_photo = mp_chr_setup[arg5].select_photo * 4;
    simage = &mpcharselimages[mp_chr_setup[arg5].select_photo * 4];
    texSelect(&DL, simage + 2, 2, 0, 2);
    gSP1Triangle(DL++, 0, 1, 4, 0);
    gSP1Triangle(DL++, 4, 1, 5, 0);

    selected_photo = mp_chr_setup[arg5].select_photo * 4;
    simage = &mpcharselimages[mp_chr_setup[arg5].select_photo * 4];
    texSelect(&DL, simage + 3, 2, 0, 2);
    gSP1Triangle(DL++, 2, 3, 6, 0);
    gSP1Triangle(DL++, 6, 3, 7, 0);

    selected_photo = mp_chr_setup[arg5].select_photo * 4;
    simage = &mpcharselimages[mp_chr_setup[arg5].select_photo * 4];
    texSelect(&DL, simage + 0, 2, 0, 2);
    gSP1Triangle(DL++, 8, 9, 12, 0);
    gSP1Triangle(DL++, 12, 9, 13, 0);

    selected_photo = mp_chr_setup[arg5].select_photo * 4;
    simage = &mpcharselimages[mp_chr_setup[arg5].select_photo * 4];
    texSelect(&DL, simage + 1, 2, 0, 2);
    gSP1Triangle(DL++, 10, 11, 14, 0);
    gSP1Triangle(DL++, 14, 11, 15, 0);

    return DL;
}


Gfx *constructor_menu0F_mpcharsel(Gfx *DL)
{
    s32 numplayers;
    s32 playernum;
    u8 *text;
    s32 panel_left;  // X position where the portraits completely fade out on the left.
    s32 panel_top;   
    s32 panel_width; // Width of the character portrait panel (1 panel per player)
    s32 grid_offset; // Distance between the portrait panels
    s32 stackpad;
    s32 stackpad2;
    s32 portrait_y_base;
    s32 select_char_height;
    s32 select_char_width;
    s32 select_char_x;
    s32 select_char_y;
    s32 panel_center_x;
    s32 name_height;
    s32 name_width;
    s32 name_x;
    s32 name_y;

    numplayers = get_selected_num_players();
    
    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = microcode_constructor_related_to_menus(DL, 0x26, 0xA9, 0x184, 0xAB, 0x90);

    if (numplayers >= 3)
    {
        DL = microcode_constructor_related_to_menus(DL, 0xD4, 0x1E, 0xD6, 0x136, 0x80);
    }

    for (playernum = 0; playernum < numplayers; playernum++)
    {
        panel_top = 0;

        if (numplayers == 2)
        {
            panel_left = 0x26;
            panel_width = 0x15E;
            grid_offset = (playernum > 0) ? (0x8C) : (0);
            panel_top = grid_offset + 0x1E;
        }
        else
        {
            panel_width = 0xAF;
            grid_offset = (playernum >= 2) ? (0x8C) : (0);
            panel_top = grid_offset + 0x1E;
            grid_offset = (playernum & 1) ? (0xAF) : (0);
            panel_left = grid_offset + 0x26;
        }
        
        gDPSetScissor(DL++, G_SC_NON_INTERLACE, (panel_left + 6), panel_top + 5, (panel_left + panel_width - 6), (panel_top + 0x8C - 5));

        panel_center_x = (panel_width >> 1) + panel_left;

        if ((player_has_selected_char[playernum] == 0) && (size_mp_select_image_player[playernum] == 0))
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_85_SELECTCHARACTER));
            textMeasure(&select_char_height, &select_char_width, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
            select_char_x = panel_center_x - (select_char_width >> 1);
            select_char_y = panel_top + 5;
            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &select_char_x, &select_char_y, (s8 *) text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }
        
        text = langGet(mp_chr_setup[mp_char_cur_select_player[playernum]].text_preset);
        textMeasure(&name_height, &name_width, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
        portrait_y_base = panel_top;
        name_x = panel_center_x - (name_width >> 1);
        name_y = (portrait_y_base + 0x46) + 0x32;
        DL = microcode_constructor(DL);
        DL = frontPrintText(DL, &name_x, &name_y, (s8 *) text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, panel_center_x - mp_char_select_scroll_offset[playernum], portrait_y_base + 0x46, mp_char_prev_select_player[playernum], size_mp_select_image_player[playernum]);

        if (((player_has_selected_char[playernum] == 0) && (size_mp_select_image_player[playernum] == 0)) || (mp_char_prev_select_player[playernum] != mp_char_cur_select_player[playernum]))
        {
            if (mp_char_prev_select_player[playernum] >= 3)
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) - 0xFC, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] - 3, size_mp_select_image_player[playernum]);
            }

            if (mp_char_prev_select_player[playernum] >= 2)
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) - 0xA8, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] - 2, size_mp_select_image_player[playernum]);
            }

            if (mp_char_prev_select_player[playernum] >= 1)
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) - 0x54, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] - 1, size_mp_select_image_player[playernum]);
            }

            if (mp_char_prev_select_player[playernum] < (num_chars_selectable_mp - 1))
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) + 0x54, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] + 1, size_mp_select_image_player[playernum]);
            }

            if (mp_char_prev_select_player[playernum] < (num_chars_selectable_mp - 2))
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) + 0xA8, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] + 2, size_mp_select_image_player[playernum]);
            }

            if (mp_char_prev_select_player[playernum] < (num_chars_selectable_mp - 3))
            {
                DL = frontRenderCharacterPortrait(DL, panel_left + 0xD, (panel_left + panel_width) - 0xE, (panel_center_x - mp_char_select_scroll_offset[playernum]) + 0xFC, portrait_y_base + 0x46, mp_char_prev_select_player[playernum] + 3, size_mp_select_image_player[playernum]);
            }
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}


//********************************************************************************************************
//MULTIPLAYER HANDICAP
//********************************************************************************************************
void init_menu10_mphandicap(void)
{
    s32 i = 0;
    tab_start_selected = FALSE;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;
    for (i = 0; i < MAX_PLAYER_COUNT; i++) {
        player_has_selected_char[i] = FALSE;
        dword_CODE_bss_80069760[i] = 0;
    }
    load_walletbond();
}

void update_menu10_mphandicap(void) 
{
    return;
}


// Address 0x7F012EC4 NTSC
void interface_menu10_mphandicap(void)
{
    s32 sp44;
    s32 i;
    s32 var_fp;

    sp44 = get_selected_num_players();
    var_fp = 0;
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    for (i = 0; i < sp44; i++)
    {
        if (player_has_selected_char[i] && joyGetButtonsPressedThisFrame(i, B_BUTTON))
        {
            player_has_selected_char[i] = 0;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }

        if (player_has_selected_char[i] == 0)
        {
            // 0x202
            if (joyGetButtonsPressedThisFrame(i, L_JPAD|L_CBUTTONS) || ((joyGetStickXInRange(i, -2, 1) < -1) && dword_CODE_bss_80069760[i] != 0))
            {
                if (player_handicap[i] > 0)
                {
                    player_handicap[i]--;
                }
            }
            // 0x101
            else if (joyGetButtonsPressedThisFrame(i, R_JPAD|R_CBUTTONS) || ((joyGetStickXInRange(i, -2, 1) > 0) && dword_CODE_bss_80069760[i] != 0))
            {
                if (player_handicap[i] < 0xA)
                {
                    player_handicap[i]++;
                }
            }
            else if (joyGetButtonsPressedThisFrame(i, A_BUTTON|Z_TRIG|START_BUTTON)) // 0xb000
            {
                player_has_selected_char[i] = 1;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }

            if ((joyGetStickXInRange(i, -2, 1) == -1) || (joyGetStickXInRange(i, -2, 1) == 0))
            {
                dword_CODE_bss_80069760[i] = 1;
            }
            else
            {
                dword_CODE_bss_80069760[i] = 0;
            }
        }

        if (player_has_selected_char[i] != 0)
        {
            var_fp++;
        }
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    frontUpdateControlStickPosition();

    if (var_fp == sp44)
    {
        frontChangeMenu(MENU_MP_OPTIONS, 0);
    }
}



// Address 0x7F01317C NTSC
Gfx * constructor_menu10_mphandicap(Gfx *DL)
{
    s32 spCC;
    s32 i; // spE0
    u8 *text;
    s32 var_s3;
    s32 var_s5;
    s32 var_v1;
    u8 *text2;
    s32 padding4;
    s32 padding1;
    s32 var_s2;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 padding2;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 padding5;

    spCC = get_selected_num_players();

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = microcode_constructor_related_to_menus(DL, 0x26, 0xA9, 0x184, 0xAB, 0x90);

    if (spCC >= 3)
    {
        DL = microcode_constructor_related_to_menus(DL, 0xD4, 0x1E, 0xD6, 0x136, 0x80);
    }

    for (i = 0; i < spCC; i++)
    {
        padding4 = player_has_selected_char[i];
        padding1 = player_handicap[i];

        var_s2 = 0;

        if (spCC == 2)
        {
            var_s3 = 0x26;
            var_s5 = 0x15E;
            var_v1 = (i > 0) ? 0x8C : 0;
            var_s2 = (var_v1) + 0x1E;
        }
        else
        {
            var_s5 = 0xAF;
            var_v1 = (i >= 2) ? 0x8C : 0;
            var_s2 = (var_v1) + 0x1E;
            var_v1 = (i & 1) ? 0xAF : 0;
            var_s3 = (var_v1) + 0x26;
        }

        gDPSetScissor(DL++, G_SC_NON_INTERLACE, (var_s3 + 6), var_s2 + 5, (var_s3 + var_s5 - 6), (var_s2 + 0x8C - 5));

        padding2 = ((var_s5 >> 1) + var_s3);
        padding5 = var_s2 + 0x46;

        if (player_has_selected_char[i] == 0)
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_86_SELECTHANDICAP));
            textMeasure(&spA4, &spA0, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp9C = padding2 - (spA0 >> 1);
            sp98 = padding5 - (spA4 >> 1) - 0xf;

            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &sp9C, &sp98, (s8*)text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }

        {
            text2 = langGet(MP_handicap_table[player_handicap[i]].text_preset);
            textMeasure(&sp90, &sp8C, text2, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
            sp88 = padding2 - (sp8C >> 1);
            sp84 = padding5 - (sp90 >> 1) + 0xf;

            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &sp88, &sp84, (s8*)text2, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}



//********************************************************************************************************
//MULTIPLAYER CONTROL OPTIONS
//********************************************************************************************************
void init_menu11_mpcontrol(void)
{
    s32 i;
    tab_start_selected = FALSE;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;

    for (i = 0; i < MAX_PLAYER_COUNT; i++) {
        player_has_selected_char[i] = FALSE;
        dword_CODE_bss_80069760[i] = 0;
    }

    load_walletbond();
}

void update_menu11_mpcontrols(void) {
    return;
}






// Address 0x7F013608 NTSC
// Address 0x7F013648 NTSC-J
void interface_menu11_mpcontrols(void)
{
    s32 sp44;
    s32 i;
    s32 var_fp;

    sp44 = get_selected_num_players();
    var_fp = 0;
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

#if defined(BUGFIX_R1)
    #define MAYBE_OR_JOYCOUNT_NOT_4 || joyGetControllerCount() != 4
    #define MAYBE_AND_JOYCOUNT_4 && joyGetControllerCount() == 4
#else
    #define MAYBE_OR_JOYCOUNT_NOT_4
    #define MAYBE_AND_JOYCOUNT_4
#endif


    for (i = 0; i < sp44; i++)
    {
        if (player_has_selected_char[i] && joyGetButtonsPressedThisFrame(i, B_BUTTON))
        {
            player_has_selected_char[i] = 0;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }

        if (player_has_selected_char[i] == 0)
        {
            // 0x202
            if (joyGetButtonsPressedThisFrame(i, L_JPAD|L_CBUTTONS) || ((joyGetStickXInRange(i, -2, 1) < -1) && dword_CODE_bss_80069760[i] != 0))
            {
                // if greater than 0
                if (controlstyle_player[i] > CONTROLLER_CONFIG_HONEY)
                {
                    // ... OR PLAYER_1 is 1.x OR controlstyle_player[i] is 1 + 2.x
                    if ((sp44 != 2) || (i != PLAYER_2) MAYBE_OR_JOYCOUNT_NOT_4 || (controlstyle_player[PLAYER_1] < CONTROLLER_CONFIG_PLENTY) || (controlstyle_player[i] >= CONTROLLER_CONFIG_GALORE))
                    {
                        controlstyle_player[i]--;
                    }

                    // ... AND PLAYER_1 is 1.x AND PLAYER_2 is 2.x
                    if ((sp44 == 2) && (i == PLAYER_1) MAYBE_AND_JOYCOUNT_4 && (controlstyle_player[PLAYER_1] < CONTROLLER_CONFIG_PLENTY) && (controlstyle_player[PLAYER_2] >= CONTROLLER_CONFIG_PLENTY))
                    {
                        // PLAYER_2 is 1.1
                        controlstyle_player[PLAYER_2] = CONTROLLER_CONFIG_HONEY;
                    }
                }
            }
            // 0x101
            else if (joyGetButtonsPressedThisFrame(i, R_JPAD|R_CBUTTONS) || ((joyGetStickXInRange(i, -2, 1) > 0) && dword_CODE_bss_80069760[i] != 0))
            {
                // ... controlstyle_player[i] is 2.x
                if (((sp44 == 2) && (i == PLAYER_1) MAYBE_AND_JOYCOUNT_4) || controlstyle_player[i] >= CONTROLLER_CONFIG_PLENTY)
                {
                    // if controlstyle_player[i] < 2.4
                    if (controlstyle_player[i] < CONTROLLER_CONFIG_GOODHEAD)
                    {
                        controlstyle_player[i]++;

                        // ... AND PLAYER_1 is 2.1 AND PLAYER_2 is 1.x
                        if ((i == PLAYER_1) && (controlstyle_player[PLAYER_1] == CONTROLLER_CONFIG_PLENTY) && (controlstyle_player[PLAYER_2] < CONTROLLER_CONFIG_PLENTY))
                        {
                            // PLAYER_2 is 2.1
                            controlstyle_player[PLAYER_2] = CONTROLLER_CONFIG_PLENTY;
                        }
                    }
                }
                // else if controlstyle_player[i] < 1.45
                else if (controlstyle_player[i] < CONTROLLER_CONFIG_GOODNIGHT)
                {
                    controlstyle_player[i]++;
                }

            }
            else if (joyGetButtonsPressedThisFrame(i, A_BUTTON|Z_TRIG|START_BUTTON)) // 0xb000
            {
                player_has_selected_char[i] = 1;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }

#if defined(VERSION_JP) || defined(VERSION_EU)
            if (joyGetControllerCount() != 4)
            {
                if (controlstyle_player[PLAYER_1] >= CONTROLLER_CONFIG_PLENTY)
                {
                    controlstyle_player[PLAYER_1] = CONTROLLER_CONFIG_HONEY;
                }

                if (controlstyle_player[PLAYER_2] >= CONTROLLER_CONFIG_PLENTY)
                {
                    controlstyle_player[PLAYER_2] = CONTROLLER_CONFIG_HONEY;
                }
            }
#endif

            if ((joyGetStickXInRange(i, -2, 1) == -1) || (joyGetStickXInRange(i, -2, 1) == 0))
            {
                dword_CODE_bss_80069760[i] = 1;
            }
            else
            {
                dword_CODE_bss_80069760[i] = 0;
            }
        }

        if (player_has_selected_char[i] != 0)
        {
            var_fp++;
        }
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    frontUpdateControlStickPosition();

    if (var_fp == sp44)
    {
        frontChangeMenu(MENU_MP_OPTIONS, 0);
    }

#undef MAYBE_OR_JOYCOUNT_NOT_4
#undef MAYBE_AND_JOYCOUNT_4
}



// Address 0x7F013980 NTSC
Gfx * constructor_menu11_mpcontrol(Gfx *DL)
{
    s32 spCC;
    s32 i; // spE0
    u8 *text;
    s32 var_s3;
    s32 var_s5;
    s32 var_v1;
    u8 *text2;
    s32 padding4;
    s32 padding1;
    s32 var_s2;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 padding2;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 padding5;

    spCC = get_selected_num_players();

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = microcode_constructor_related_to_menus(DL, 0x26, 0xA9, 0x184, 0xAB, 0x90);

    if (spCC >= 3)
    {
        DL = microcode_constructor_related_to_menus(DL, 0xD4, 0x1E, 0xD6, 0x136, 0x80);
    }

    for (i = 0; i < spCC; i++)
    {
        padding4 = player_has_selected_char[i];
        padding1 = controlstyle_player[i];

        var_s2 = 0;

        if (spCC == 2)
        {
            var_s3 = 0x26;
            var_s5 = 0x15E;
            var_v1 = (i > 0) ? 0x8C : 0;
            var_s2 = (var_v1) + 0x1E;
        }
        else
        {
            var_s5 = 0xAF;
            var_v1 = (i >= 2) ? 0x8C : 0;
            var_s2 = (var_v1) + 0x1E;
            var_v1 = (i & 1) ? 0xAF : 0;
            var_s3 = (var_v1) + 0x26;
        }

        gDPSetScissor(DL++, G_SC_NON_INTERLACE, (var_s3 + 6), var_s2 + 5, (var_s3 + var_s5 - 6), (var_s2 + 0x8C - 5));

        padding2 = ((var_s5 >> 1) + var_s3);
        padding5 = var_s2 + 0x46;

        if (player_has_selected_char[i] == 0)
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_285_SELECTCONTROLSTYLE));
            textMeasure(&spA4, &spA0, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp9C = padding2 - (spA0 >> 1);
            sp98 = padding5 - (spA4 >> 1) - 0xf;

            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &sp9C, &sp98, (s8*)text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }

        {
            text2 = langGet(MP_controller_configuration_table[controlstyle_player[i]].text_preset);
            textMeasure(&sp90, &sp8C, text2, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
            sp88 = padding2 - (sp8C >> 1);
            sp84 = padding5 - (sp90 >> 1) + 0xf;

            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &sp88, &sp84, (s8*)text2, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}



//********************************************************************************************************
//MULTIPLAYER STAGE SELECT
//********************************************************************************************************
void init_menu12_mpstage(void)
{
  tab_start_selected = FALSE;
  tab_next_selected = FALSE;
  tab_prev_selected = FALSE;
  tab_prev_highlight = FALSE;
  tab_next_highlight = FALSE;
  tab_start_highlight = FALSE;
  current_mp_stage_highlighted = MP_STAGE_RANDOM;
  load_walletbond();
}

void update_menu12_mpstage(void) {
return;
}



void interface_menu12_mpstage(void)
{
    s32 row;
    s32 column;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);
    if (joyGetButtons(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON) == 0)
    {
        tab_prev_highlight = FALSE;
        tab_next_highlight = FALSE;
        tab_start_highlight = FALSE;
        if (frontCheckCursorOnPreviousTab())
        {
            tab_prev_highlight = TRUE;
        }
        else
        {
            if ((s32)cursor_v_pos >= 240)
            {
                row = 2;
            }
            else if ((s32)cursor_v_pos >= 170)
            {
              row = 1;
            } else
            {
                row = 0;
            }

            if ((s32) cursor_h_pos >= 292)
            {
                column = 3;
            }
            else if ((s32) cursor_h_pos >= 207)
            {
                column = 2;
            }
            else if ((s32) cursor_h_pos >= 122)
            {
                column = 1;
            }
            else
            {
                column = 0;
            }

            current_mp_stage_highlighted = (row * 4) + column;
            while (check_if_mp_stage_unlocked(current_mp_stage_highlighted) == 0)
            {
                current_mp_stage_highlighted = current_mp_stage_highlighted - 1;
            }
        }
    }
    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
    {
        if (tab_prev_highlight)
        {
            tab_prev_selected = TRUE;
        }
        else
        {
            if (current_mp_stage_highlighted >= MP_STAGE_RANDOM)
            {
                tab_next_selected = TRUE;
                MP_stage_selected = current_mp_stage_highlighted;
            }
        }
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS,  1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS,  1);
    frontUpdateControlStickPosition();
    if (tab_next_selected)
    {
        frontChangeMenu(MENU_MP_OPTIONS, FALSE);
        return;
    }
    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MP_OPTIONS, FALSE);
    }
}


// Address 0x7F014050 NTSC
Gfx * constructor_menu12_mpstage(Gfx *DL)
{
    s32 padding5;
    s32 sp130;
    s32 sp12C;
    s32 sp128;
    s32 sp124;
    s32 padding2[7];
    struct coord2d sp100;
    struct coord2d spF8;
    s32 padding4[3];
    s32 i_3;
    s32 i_2;
    s32 i_1;
    struct coord2d spD8;
    struct coord2d spD0;
    s32 var_s6;
    s32 var_s2_2;
    struct sImageTableEntry *simage;
    s32 count;
    s32 count_2;
    s32 padding;
    s32 spB4;


    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    for (i_1 = 0; i_1 != 3; i_1++)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x25, 0x6c + (i_1 * 0x46), 0x185, 0xa0 + (i_1 * 0x46), 0x101010FF);
    }

    DL = combiner_bayer_lod_perspective(DL);

    gDPSetTextureFilter(DL++, G_TF_POINT);

    simage = mainfolderimages + 5;
    texSelect(&DL, simage, 1, 0, 2); // IMAGE_DOT

    spF8.f[0] = 176.0f;
    spF8.f[1] = 4.0f;
    sp100.f[0] = spF8.f[0] + 37.0f;
    sp100.f[1] = spF8.f[1] + 100.0f;

    for (i_2 = 0; i_2 < 3; i_2++)
    {
        display_image_at_position(&DL, &sp100.f[0], &spF8.f[0], 0x2F0, 0x12, 0, 0, 1, 0x6B, 0x67, 0x53, 0xFF, simage->level > 0, 0);
        sp100.f[1] += 60.0f;
        display_image_at_position(&DL, &sp100.f[0], &spF8.f[0], 0x2F0, 0x12, 0, 0, 1, 0x6B, 0x67, 0x53, 0xFF, simage->level > 0, 0);
        sp100.f[1] -= 60.0f;
        sp100.f[1] += 70.0f;
    }

    spD0.f[0] = 34.0f;
    spD0.f[1] = 22.0f;
    spD8.f[1] = spD0.f[1] + 108.0f + 4.0f;

    count = 0;

    for (spB4 = 0; spB4 != 3; spB4++)
    {
        spD8.f[0] = 86.0f;

        for (i_3 = 0; i_3 < 4; i_3++)
        {
            if (count < 12)
            {
                simage = &mpstageselimages[multi_stage_setups[count].photo];

                texSelect(&DL, simage, 1, 0, 2);

                if (count == current_mp_stage_highlighted)
                {
                    gDPSetCycleType(DL++, G_CYC_2CYCLE);
                    gDPSetFogColor(DL++, 0xff, 0xff, 0xff, 0x0a);
                    gDPSetRenderMode(DL++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);

                    display_image_at_position(&DL, &spD8.f[0], &spD0.f[0], 0x44, 0x2C, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, simage->level > 0, 1);
                }
                else if (check_if_mp_stage_unlocked(count) != 0)
                {
                    display_image_at_position(&DL, &spD8.f[0], &spD0.f[0], 0x44, 0x2C, 0, 0, 1, 0x6E, 0x6E, 0x6E, 0xFF, simage->level > 0, 0);
                }
                else
                {
                    display_image_at_position(&DL, &spD8.f[0], &spD0.f[0], 0x44, 0x2C, 0, 0, 1, 0xF, 0xF, 0xF, 0xFF, simage->level > 0, 0);
                }
            }

            spD8.f[0] += 85.0f;
            count++;
        }

        spD8.f[1] += 70.0f;
    }

    DL = microcode_constructor(DL);

    count_2 = 0;

    // not sure what's going on here, but this is required to get the stack to match.
    if(1)
    {
        s32 i_4;
        s32 sp9C;
        s32 padding6;
        s32 padding7;
        s32 sp90;
        s32 padding8;

        sp90 = 0x97;

        for (sp9C = 0; sp9C != 3; sp9C++)
        {
            var_s6 = 0x56;

            for (i_4 = 0; i_4 < 4; i_4++)
            {
                if (count_2 < 12 && check_if_mp_stage_unlocked(count_2))
                {
                    var_s2_2 = 0x96969600;

                    if (count_2 == current_mp_stage_highlighted)
                    {
                        var_s2_2 = -0x100;
                    }

                    textMeasure(&sp128, &sp124, langGet(multi_stage_setups[count_2].select_screen_text_preset), ptrFontBankGothicChars, ptrFontBankGothic, 0);

                    sp130 = var_s6 - 0x1F;
                    sp12C = sp90 - sp128;

                    DL = microcode_constructor_related_to_menus(DL, sp130, sp12C, sp130 + sp124, sp12C + sp128, 0);

                    DL = textRender(DL, &sp130, &sp12C, langGet(multi_stage_setups[count_2].select_screen_text_preset), ptrFontBankGothicChars, ptrFontBankGothic, var_s2_2 | 0xFF, viGetX(), viGetY(), 0, 0);

                    sp130 = var_s6 - 0x1F;
                    sp12C = sp90 - sp128;

                    DL = textRender(DL, &sp130, &sp12C, langGet(multi_stage_setups[count_2].select_screen_text_preset), ptrFontBankGothicChars, ptrFontBankGothic, var_s2_2 | 0x64, viGetX(), viGetY(), 0, 0);
                }

                var_s6 += 0x55;
                count_2++;
            }

            sp90 += 0x46;
        }
    }

    DL = microcode_constructor(DL);
    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);

    return DL;
}




MPSCENARIOS get_scenario(void)
{
  return scenario;
}

//********************************************************************************************************
//MULTIPLAYER SCENARIO SELECT
//********************************************************************************************************
void init_menu13_mpscenariosel(void)
{
  tab_start_selected = FALSE;
  tab_next_selected = FALSE;
  tab_prev_selected = FALSE;
  tab_prev_highlight = FALSE;
  tab_next_highlight = FALSE;
  tab_start_highlight = FALSE;
  load_walletbond();
}

void update_menu13_mpscenario(void) {
    return;
}






// Address 0x7F0147B8 NTSC
void interface_menu13_mpscenario(void)
{
    s32 isTeam;
    s32 scenarioid;
    s32 i;

    isTeam = FALSE;
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);

    if (joyGetButtons(PLAYER_1, Z_TRIG|A_BUTTON) == 0) {
        tab_prev_highlight = FALSE;
        tab_next_highlight = FALSE;
        tab_start_highlight = FALSE;

        if (frontCheckCursorOnPreviousTab())
        {
            tab_prev_highlight = TRUE;
            dword_CODE_bss_80069780 = SCENARIO_NORMAL;
        }
        else
        {
            dword_CODE_bss_80069780 = SCENARIO_YOLT;

            for (i = 7; i != 0; i--)
            {
                if (
                    (s32)cursor_v_pos  >=  (0x83 + (-i * -0x16))
                    && (mp_player_counts[i].min <= get_selected_num_players())
                    && (get_selected_num_players() <= mp_player_counts[i].max))
                {
                    dword_CODE_bss_80069780 = i + 1;
                    break;
                }
            }
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
    {
        if (tab_prev_highlight)
        {
            tab_prev_selected = TRUE;
        }
        else
        {
            scenarioid = dword_CODE_bss_80069780 - 1;

            if ((scenarioid == SCENARIO_2v2) || (scenarioid == SCENARIO_3v1) || (scenarioid == SCENARIO_2v1))
            {
                reset_mp_options_for_scenario(scenarioid);
                isTeam = TRUE;
            }
            else
            {
                reset_mp_options_for_scenario(scenarioid);
                tab_prev_selected = TRUE;
            }
        }

        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();

    if (isTeam)
    {
        frontChangeMenu(MENU_MP_TEAMS, FALSE);
        return;
    }

    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MP_OPTIONS, FALSE);
    }
}


// Address 0x7F014A48 NTSC
Gfx * constructor_menu13_mpscenario(Gfx *DL)
{
    s32 padding1;
    s32 padding2;
    s32 padding3;
    s32 x; // sp88
    s32 y; // sp84
    s32 i;
    s32 sp7C;
    s32 sp78;

    u8 *text;
    s32 var_s3;


    DL = viSetFillColor(DL,0,0,0);
    DL = viFillScreen(DL);
#ifdef VERSION_EU
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    text = langGet(getStringID(LTITLE, TITLE_STR_87_SCENARIO2));

    x = 0x37;
    y = 0x66;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    for (i = 0; i < 8; i++)
    {
        var_s3 = 0xff;

        if (((s32) mp_player_counts[i].max < get_selected_num_players()) || (get_selected_num_players() < (s32) mp_player_counts[i].min))
        {
            var_s3 = 0x70;
        }

        text = langGet(mp_player_counts[i].stage);

        textMeasure(&sp7C, &sp78, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        x = 0x39;
        y = 0x83 + (i * 0x16);
        if ((i + 1) == dword_CODE_bss_80069780)
        {
            DL = microcode_constructor_related_to_menus(DL, 0x37, y - 1, sp78 + 0x3C, y + 0xE, 0x32);
        }

        DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, var_s3, viGetX(), viGetY(), 0, 0);
    }

    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);

    return DL;
}




s32 get_players_team_or_scenario_item_flag(int player)
{
  return g_playerPlayerData[player].have_token_or_goldengun;
}

void set_players_team_or_scenario_item_flag(int player,s32 flag)
{
  g_playerPlayerData[player].have_token_or_goldengun = flag;
}



//********************************************************************************************************
//MULTIPLAYER TEAM SELECT
//********************************************************************************************************

void init_menu14_mpteamsel(void)
{
    tab_start_selected = FALSE;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;

    if (scenario == SCENARIO_2v1) {
        teamsize = 2;
    }
    else {
        teamsize = 3;
    }

    D_8002B560 = 0;
    load_walletbond();
}

void update_menu14_mpteams(void) 
{
    return;
}


// Address 0x7F014D48 NTSC
void interface_menu14_mpteams(void)
{
    s32 i;
    s32 var_a1;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    D_8002B560 = (s32) (D_8002B560 + 1) % 20;

    // 0x101
    if ((joyGetButtonsPressedThisFrame(0, R_JPAD|R_CBUTTONS)) || (joyGetStickXInRange(0, -2, 1) > 0))
    {
        if (scenario == SCENARIO_2v1)
        {
            if (!(teamsize & 1))
            {
                teamsize = 1;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }
        }
        else if (!(teamsize & 1))
        {
            teamsize += 1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }
    // 0x808
    else if ((joyGetButtonsPressedThisFrame(0, U_JPAD|U_CBUTTONS)) || (joyGetStickYInRange(0, -2, 1) > 0))
    {
        if (scenario == SCENARIO_2v2)
        {
            if (teamsize & 2)
            {
                teamsize = 1;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }
        }
        else if (teamsize & 2)
        {
            teamsize -= 2;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }
    // 0x202
    else if ((joyGetButtonsPressedThisFrame(0, L_JPAD|L_CBUTTONS)) || (joyGetStickXInRange(0, -2, 1) < -1))
    {
        if (scenario == SCENARIO_2v2)
        {
            if (teamsize & 1)
            {
                teamsize = 2;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }
        }
        else if (teamsize & 1)
        {
            teamsize -= 1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }
    // 0x404
    else if ((joyGetButtonsPressedThisFrame(0, D_JPAD|D_CBUTTONS)) || (joyGetStickYInRange(0, -2, 1) < -1))
    {
        if (scenario == SCENARIO_2v1)
        {
            if (!(teamsize & 2))
            {
                teamsize = 2;
                sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
            }
        }
        else if (!(teamsize & 2))
        {
            teamsize += 2;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    frontUpdateControlStickPosition();

    if (joyGetButtonsPressedThisFrame(0, A_BUTTON|Z_TRIG|START_BUTTON)) // 0xb000
    {
        for (i = 0; i < 4; i++)
        {
            if (scenario == SCENARIO_2v2)
            {

                if (i == 0 || i == teamsize)
                {
                    var_a1 = 0;
                }
                else
                {
                    var_a1 = 1;
                }

                set_players_team_or_scenario_item_flag(i, var_a1);
            }
            else
            {
                if (i != teamsize)
                {
                    var_a1 = 0;
                }
                else
                {
                    var_a1 = 1;
                }

                set_players_team_or_scenario_item_flag(i, var_a1);
            }
        }

        frontChangeMenu(MENU_MP_OPTIONS, 0);
        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
}


/**
 * Address: 7F015138
 */
Gfx *constructor_menu14_mpteams(Gfx *DL)
{
    s32 numPlayers;
    s32 playerIndex;
    s32 layoutOffset;
    s32 titleY;
    s32 rectRightScaled;
    s32 useFirstTeam;
    s32 centerX;
    s32 rowTop;
    char *text;
    s32 textColour;
    s32 titleHeight;
    s32 titleWidth;
    s32 titleX;
    s32 titleYPos;
    s32 padding1;
    s32 textHeight;
    s32 textWidth;
    s32 textX;
    s32 textY;
    char *titleText;

    numPlayers = get_selected_num_players();

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = microcode_constructor_related_to_menus(DL, 0x26, 0xA9, 0x184, 0xAB, 0x90);

    if (numPlayers >= 3)
    {
        DL = microcode_constructor_related_to_menus(DL, 0xD4, 0x1E, 0xD6, 0x136, 0x80);
    }

    for (playerIndex = 0; playerIndex < numPlayers; playerIndex++)
    {
        layoutOffset = (0, (playerIndex >= 2) ? 0x8C : 0);
        rowTop = layoutOffset + 0x1E;
        layoutOffset = ((playerIndex & 1) ? 0xAF : 0) + 0;

        gDPSetScissor(DL++, G_SC_NON_INTERLACE, layoutOffset + 0x2c, rowTop + 5, layoutOffset + 0xcf, rowTop + 0x87);

        centerX = layoutOffset + 0x7d;

        if (playerIndex == 0)
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_88_SELECTTEAMS)); // "Select Teams"
            titleText = text;

            textMeasure(&titleHeight, &titleWidth, titleText, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            titleYPos = rowTop + 5;
            titleX = centerX - (titleWidth >> 1);

            DL = frontPrintText(DL, &titleX, &titleYPos, titleText, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }

        if (scenario == SCENARIO_2v2)
        {
            useFirstTeam = (playerIndex == 0) || (playerIndex == teamsize);
        }
        else
        {
            useFirstTeam = playerIndex != teamsize;
        }

        if (useFirstTeam)
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_89_RED)); // "Red Team"
        }
        else
        {
            text = langGet(getStringID(LTITLE, TITLE_STR_90_BLUE)); // "Blue Team"
        }

        if (useFirstTeam)
        {
            textColour = 0xFF0000FF;
        }
        else
        {
            textColour = 0x0000FFFF;
        }

        textMeasure(&textHeight, &textWidth, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        textX = centerX - (textWidth >> 1);
        textY = (rowTop - (textHeight >> 1)) + 0x46;

        if ((playerIndex != teamsize) || ((playerIndex == teamsize) && (((s32) D_8002B560) < 0xA)))
        {
            DL = frontPrintText(DL, &textX, &textY, text, ptrFontZurichBoldChars, ptrFontZurichBold, textColour, viGetX(), viGetY(), 0, 0);
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}


void set_briefing_page(WATCH_BRIEFING_PAGE page)
{
    short new_var;

    // could be a dev typo
    if (current_menu_briefing_page = page)
    {
        // maybe previous code was optimized out
    }
}


// Address 0x7F015520 NTSC
void load_briefing_text_for_stage(void)
{
    Gfx *temp_s0;
    s32 argg;

    // what is this
    temp_s0 = (s32)(ptr_logo_and_walletbond_DL) + (s32)(4096*10);

    // alright
    argg = 0x200;
    ptrbriefingdata = _fileNameLoadToAddr(mission_folder_setup_entries[briefingpage].briefing_name_ptr, FILELOADMETHOD_DEFAULT, (u8 *) temp_s0, argg);

    // what is this
    temp_s0 += argg / 8;

    // what is this
    argg *= 879;

    langLoadToBank(langGetLangBankIndexFromStagenum(mission_folder_setup_entries[briefingpage].stage_id), (u8 *)temp_s0, argg);

    // what is this
    for (argg = 0; argg < OBJECTIVES_MAX; argg++)
    {
        if (ptrbriefingdata->objective[argg].textid == 0)
        {
            break;
        }
    }
}

//********************************************************************************************************
//BRIEFING SCREEN
//********************************************************************************************************
void init_menu0A_briefing(void)
{
    tab_next_selected = 0;
    tab_prev_selected = 0;
    final_menu_briefing_page = 5;
    set_briefing_page(0);
    load_walletbond();
    load_briefing_text_for_stage();
}


void update_menu0A_briefing(void)
{
  langClearBank(langGetLangBankIndexFromStagenum(mission_folder_setup_entries[briefingpage].stage_id));
  if (-1 < menu_update) {
    frontCleanUpWalletBond();
  }
}


void interface_menu0A_briefing(void)
{
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;
    if (frontCheckCursorOnPreviousTab())
    {
        tab_prev_highlight = TRUE;
    }
    else if ((frontCheckCursorOnNextTab()) && (current_menu_briefing_page < (final_menu_briefing_page - 1)))
    {
        tab_next_highlight = TRUE;
    }
    else if (frontCheckCursorOnStartTab())
    {
        tab_start_highlight = TRUE;
    }
    else if (current_menu_briefing_page < (final_menu_briefing_page - 1))
    {
        tab_next_highlight = TRUE;
    }
    else
    {
        tab_start_highlight = TRUE;
    }
    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON))
    {
        tab_next_selected = TRUE;
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON))
    {
        if (tab_next_highlight)
        {
            set_briefing_page(current_menu_briefing_page + 1);
        }
        else if (tab_prev_highlight)
        {
            if (current_menu_briefing_page > BRIEFING_TITLE)
            {
                set_briefing_page(current_menu_briefing_page - 1);
            }
            else
            {
                tab_prev_selected = TRUE;
            }
        }
        else if (tab_start_highlight)
        {
            tab_next_selected = TRUE;
        }
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON) != 0)
    {
        if (current_menu_briefing_page > BRIEFING_TITLE)
        {
            set_briefing_page(current_menu_briefing_page - 1);
        }
        else
        {
            tab_prev_selected = TRUE;
        }
        sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_PHOTOBRIEF, current_menu_briefing_page == BRIEFING_TITLE);
    set_item_visibility_in_objinstance(walletinst[0], mission_folder_setup_entries[briefingpage].mission_num + 0x16, current_menu_briefing_page == BRIEFING_TITLE);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();
    if (tab_next_selected)
    {
        frontChangeMenu(MENU_RUN_STAGE, TRUE);
        return;
    }
    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MISSION_SELECT, FALSE);
        set_cursor_to_stage_solo(mission_folder_setup_entries[briefingpage].mission_num);
    }
}




// Address 0x7F015A08 NTSC
Gfx *print_objectives_and_status_to_menu(Gfx *DL, s32 arg1, u8 *arg2, s32 arg3)
{
    s32 i; // sp9C
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 var_s2;
    s32 var_fp;
    u8* text;
    s32 v1;

    sp98 = 0;
    var_fp = 0;
    i = 0;
    v1 = 0;

    for (i = 0; i < OBJECTIVES_MAX; i++)
    {
        if (ptrbriefingdata->objective[i].textid != 0 && selected_difficulty >= ptrbriefingdata->objective[i].enabled_difficulty)
        {
            v1 = ptrbriefingdata->objective[i].textid;
            text = langGet(v1);
            strcpy((u8*)arg2, "a.\n");
            *arg2 = *arg2 + sp98;

            sp94 = 0;
            sp90 = 0;
            textMeasure(&sp94, &sp90, (u8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold, 0);


            sp8C = 0x37;
            sp88 = (sp94 * var_fp) + arg1 + (i*0);
            DL = frontPrintText(DL, &sp8C, &sp88, (s8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

            sp8C = 0x4B;
            sp88 = (sp94 * var_fp) + arg1 + (i*0);

            if (arg3 != 0)
            {
                setTextWordWrap(2);
                textWrap(0xDC, (s8*)text, (s8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold);
                setTextWordWrap(0);
            }
            else
            {
                textWrap(0x140, (s8*)text, (s8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold);
            }

            DL = frontPrintText(DL, &sp8C, &sp88, (s8*)arg2,  ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

            if (arg3)
            {
                switch (get_status_of_objective(i))
                {
                    case 1:
                        text   = langGet(getStringID(LTITLE, TITLE_STR_91_COMPLETED));
                        var_s2 = 0xFF;
                        break;
                    default:
                    case 0:
                    case 2:
                        text   = langGet(getStringID(LTITLE, TITLE_STR_92_FAILED));
                        var_s2 = 0x780000FF;
                        break;
                }

                sp8C = 0x136;
                sp88 = (sp94 * var_fp) + arg1 + (i*0);

                DL = frontPrintText(DL, &sp8C, &sp88, (s8*)text, ptrFontZurichBoldChars, ptrFontZurichBold, var_s2, viGetX(), viGetY(), 0, 0);
            }

            var_fp += sub_GAME_7F0AC0E8(arg2);
            sp98++;
        }
    }

    return DL;
}


// Address 0x7F015D74 NTSC
#ifndef VERSION_EU
const struct MatchHack_front_rodata_3000 asc_D_80050C54 = { "\n" };
#endif

Gfx *constructor_menu0A_briefing(Gfx *DL)
{
    u8 *spC0C;
    s32 spC08;
    s32 spC04;
    struct MatchHack_front_rodata_3000 sp4C;

    DL = viSetFillColor(DL,0,0,0);
    DL = viFillScreen(DL);
#ifdef VERSION_EU
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);

#if !defined(VERSION_EU)
    sp4C = asc_D_80050C54;
#endif

    DL = microcode_constructor(DL);
    DL = print_current_solo_briefing_stage_name(DL, (char*)&sp4C);

    switch (current_menu_briefing_page)
    {
        case BRIEFING_TITLE:
            spC0C = langGet(getStringID(LTITLE, TITLE_STR_93_PRIMARYOBJECTIVES ));
            break;

        case BRIEFING_OVERVIEW:
            spC0C = langGet(getStringID(LTITLE, TITLE_STR_94_BACKGROUND));
            break;

        case BRIEFING_M:
            spC0C = langGet(getStringID(LTITLE, TITLE_STR_95_MBRIEFING));
            break;

        case BRIEFING_Q:
            spC0C = langGet(getStringID(LTITLE, TITLE_STR_96_QBRANCH));
            break;

        case BRIEFING_MONEYPENNY:
            spC0C = langGet(getStringID(LTITLE, TITLE_STR_97_MONEYPENNY));
            break;
    }

    spC08 = 0x37;
    spC04 = 0x8F;
    DL = frontPrintText(DL, &spC08, &spC04, (s8*)spC0C, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    if (current_menu_briefing_page == BRIEFING_TITLE)
    {
        DL = print_objectives_and_status_to_menu(DL, 0xA7, (char*)&sp4C, 0);
    }
    else
    {
        switch (current_menu_briefing_page)
        {
            case BRIEFING_OVERVIEW:
                spC0C = langGet(ptrbriefingdata->brief[0]);
            break;

            case BRIEFING_M:
                spC0C = langGet(ptrbriefingdata->brief[1]);
            break;

            case BRIEFING_Q:
                spC0C = langGet(ptrbriefingdata->brief[2]);
            break;

            case BRIEFING_MONEYPENNY:
                spC0C = langGet(ptrbriefingdata->brief[3]);
            break;
        }

        spC08 = 0x37;
        spC04 = 0xA7;
        textWrap(0x140, (s8*)spC0C, (s8*)&sp4C, ptrFontZurichBoldChars, ptrFontZurichBold);
        setTextOverlapCorrection(8);
        DL = frontPrintText(DL, &spC08, &spC04, (s8*)&sp4C, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        setTextOverlapCorrection(-1);
    }

    DL = frontAddStartTabText(DL);
    DL = frontAddPreviousTabText(DL);

    if (current_menu_briefing_page < BRIEFING_MONEYPENNY)
    {
        DL = frontAddNextTabText(DL);
    }

    DL = frontDrawCursor(DL);

    return DL;
}



//********************************************************************************************************
//RUN STAGE
//********************************************************************************************************
void init_menu0B_runstage(void)
{
    bossSetLoadedStage(selected_stage);
    lvlSetSelectedDifficulty(selected_difficulty);
}


//********************************************************************************************************
//MISSION FAILED
//********************************************************************************************************
void init_menu0C_missionfailed(void)
{
  tab_next_selected = FALSE;
  tab_prev_selected = FALSE;
  load_walletbond();
  load_briefing_text_for_stage();
  frontSetCursorPositionToNextTab();
  if (maybe_is_in_menu != FALSE) {
    sndApplyVolumeAllSfxSlot(0x7fff);
    musicTrack1ApplySeqpVol(0x7fff);
    g_musicXTrack1Fade = MUSIC_FADESTATE_UNSET;
    musicTrack1Play(M_FOLDERS);
    maybe_is_in_menu = FALSE;
  }
}

void update_menu0C_missionfailed(void) {
    return;
}


void interface_menu0C_missionfailed(void)
{
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(FALSE);
    tab_next_highlight = FALSE;
    tab_prev_highlight = FALSE;
    if (frontCheckCursorOnPreviousTab())
    {
        tab_prev_highlight = TRUE;
    }
    else
    {
        if (frontCheckCursorOnNextTab())
        {
            tab_next_highlight = TRUE;
        }
        else
        {
            tab_next_highlight = TRUE;
        }
    }
    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
    {
        if (tab_prev_highlight)
        {
            tab_prev_selected = TRUE;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, 0);
        }
        else
        {
            if (tab_next_highlight)
            {
                tab_next_selected = TRUE;
                sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, 0);
            }
        }
    }
    else
    {
        if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
        {
            tab_prev_selected = TRUE;
            sndPlaySfx(g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, 0);
        }
    }
    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();
    if (tab_next_selected)
    {
        frontChangeMenu(MENU_MISSION_COMPLETE, FALSE);
        return;
    }
    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MISSION_SELECT, FALSE);
        set_cursor_to_stage_solo(mission_folder_setup_entries[briefingpage].mission_num);
    }
}







s32 frontCompleteAllObjectivesAliveSuccess(void)
{
    s32 i;

    if (mission_failed_or_aborted || g_isBondKIA)
    {
        return 0;
    }

    for (i=0; i<10; i++)
    {
        if (ptrbriefingdata->objective[i].textid != 0
            && lvlGetSelectedDifficulty() >= ptrbriefingdata->objective[i].enabled_difficulty
            && get_status_of_objective(i) != OBJECTIVESTATUS_COMPLETE)
            {
                return 0;
            }
    }

    return 1;
}


Gfx * constructor_menu0C_missionfailed(Gfx *DL)
{
    s32 x;
    s32 y;

    char stagename[0xbb8];
    char *text;
    s32 phi_v1;

    s32 y2;
    s32 x2;


    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    #if defined(BUGFIX_R2)
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
    #endif
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = print_current_solo_briefing_stage_name(DL, &stagename);

    text = langGet(getStringID(LTITLE, TITLE_STR_98_REPORT)); //REPORT:*
    x = 0x37;
    y = 0x8F;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    text = langGet(getStringID(LTITLE, TITLE_STR_99_MISSIONSTATUS)); //Mission status:*
    x2 = 0;
    y2 = 0;
    textMeasure(&y2, &x2, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    x = 0x37;
    y = 0xA7;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    if (g_isBondKIA)
    {
        text = langGet(getStringID(LTITLE, TITLE_STR_100_KIA)); // KILLED IN ACTION*
        phi_v1 = 0x78000000 | 0xFF;
    }
    else if (mission_failed_or_aborted)
    {
        text = langGet(getStringID(LTITLE, TITLE_STR_101_ABORTED)); // ABORTED*
        phi_v1 = 0x78000000 | 0xFF;
    }
    else if (frontCompleteAllObjectivesAliveSuccess())
    {

        text = langGet(getStringID(LTITLE, TITLE_STR_102_COMPLETED)); // Completed*
        phi_v1 = 0xFF;
    }
    else
    {
        text = langGet(getStringID(LTITLE, TITLE_STR_103_FAILED)); // FAILED*
        phi_v1 = 0x78000000 | 0xFF;
    }

    x = x2 + 0x37;
    y = 0xA7;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, phi_v1, viGetX(), viGetY(), 0, 0);

    DL = print_objectives_and_status_to_menu(DL, 0xBF, &stagename, 1);
    DL = frontAddNextTabText(DL);
    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);
    return DL;
}

//********************************************************************************************************
//MISSION COMPLETE
//********************************************************************************************************
void init_menu0D_missioncomplete(void)
{
    tab_next_selected = 0;
    tab_prev_selected = 0;
    load_walletbond();
    load_briefing_text_for_stage();
    if (g_NewCheatUnlocked)
    {
        sndPlaySfx(g_musicSfxBufferPtr, RARELOGO_SFX, 0);
    }
}

void update_menu0D_missioncomplete(void) {
    return;
}







void interface_menu0D_missioncomplete()
{
    int entry;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;

    if (frontCheckCursorOnPreviousTab())
    {
        tab_prev_highlight = 1;
    }
    else
    {
        if (frontCheckCursorOnNextTab())
        {
            tab_next_highlight = 1;
        }
        else
        {
            tab_next_highlight = 1;
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON|Z_TRIG|A_BUTTON))
    {
        if (tab_next_highlight)
        {
            tab_next_selected = 1;
            sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
        else if (tab_prev_highlight != FALSE)
        {
            tab_prev_selected = 1;
            sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
        }
    }
    else if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
    {
        tab_prev_selected = 1;
        sndPlaySfx((struct ALBankAlt_s *)g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_PAPER, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_OHMSS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();

    if (tab_next_selected)
    {
        if (frontCompleteAllObjectivesAliveSuccess() && (!g_AppendCheatSinglePlayer))
        {
            if (mission_folder_setup_entries[briefingpage].mission_num == SP_LEVEL_CRADLE)
            {
                frontChangeMenu(MENU_RUN_STAGE, TRUE);
                selected_stage = LEVELID_CUBA;
            }
            else if (mission_folder_setup_entries[briefingpage].mission_num >= SP_LEVEL_AZTEC)
            {
                frontChangeMenu(MENU_MISSION_SELECT, FALSE);
                set_cursor_to_stage_solo((s32)mission_folder_setup_entries[briefingpage].mission_num);
            }
            else
            {
                entry = briefingpage + 1;
                while (mission_folder_setup_entries[entry].folder_text_preset)
                {
                    if (mission_folder_setup_entries[entry].stage_id >= 0)
                    {
                        break;
                    }

                    entry++;
                }

                if (mission_folder_setup_entries[entry].folder_text_preset)
                {
                    briefingpage = entry;
                    selected_stage = mission_folder_setup_entries[entry].stage_id;
                }

                frontChangeMenu(MENU_BRIEFING, FALSE);
            }
        }
        else
        {
            frontChangeMenu(MENU_BRIEFING, FALSE);
        }
    }
    else if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MISSION_SELECT, FALSE);
        set_cursor_to_stage_solo((s32)mission_folder_setup_entries[briefingpage].mission_num);
    }

    return;
}

Gfx *constructor_menu0D_missioncomplete(Gfx *DL)
{
    s32 x;
    s32 y;
    u8 stagename[3000];
    char *text;
    s32 y2;
    s32 x2;
    s32 missiontimer;
    s32 killcount;
    s32 shotsfired;
    s32 headshots;
    s32 bodyshots;
    s32 limbshots;
    s32 reg4;
    s32 reg5;
    s32 reg6;
    s32 hitshots;
    s32 allhits;

    s32 missiontime;
    s32 temp;
    s32 besttime;
    s32 targettime;
    s32 difficulty;
    f32 hitPct;



    DL = viSetFillColor(DL, 0,0,0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    missiontimer = getMissiontimer();
    killcount = get_curplay_killcount();
    shotsfired = get_curplayer_shot_register(0);
    headshots = get_curplayer_shot_register(1);
    bodyshots = get_curplayer_shot_register(2);
    limbshots = get_curplayer_shot_register(3);
    reg4 = get_curplayer_shot_register(4);
    reg5 = get_curplayer_shot_register(5);
    reg6 = get_curplayer_shot_register(6);
    allhits = headshots + bodyshots + limbshots + reg4 + reg5;
    hitshots = allhits + reg6;
    if (allhits <= 0) {
        allhits = 1;
    }
    DL = print_current_solo_briefing_stage_name(DL, stagename);

    text = langGet(getStringID(LTITLE, TITLE_STR_104_STATS)); //STATISTICS:*
    x = 0x37;
    y = 0x8F;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    x2 = 0;
    y2 = 0;
    textMeasure(&y2, &x2, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    text = langGet(getStringID(LTITLE, TITLE_STR_105_TIME)); //Time:*
    x = 0x37;
    y = 0xA7;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    besttime = fileGetSaveStageDifficultyTime( fileGetSaveForFoldernum(selected_folder_num), mission_folder_setup_entries[briefingpage].mission_num, selected_difficulty);
    if ((besttime == 0) || (!(besttime < 0x3FF))) {
        besttime = -1;
    }
    if (selected_difficulty >= DIFFICULTY_007) {
        difficulty = DIFFICULTY_00;
    }
    else {
        difficulty = selected_difficulty;
    }
    missiontime = missiontimer / 60;
    stagename[0] = '\0';
    targettime = solo_target_time_array[mission_folder_setup_entries[briefingpage].mission_num][difficulty];
    sprintf(stagename, "%02d:%02d", missiontime / 60, missiontime % 60);
    x = 0x82;
    y = 0xA7;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    if (g_NewCheatUnlocked) {
        stagename[0] = '\0';
        sprintf(stagename, "     [%s]", langGet(getStringID(LTITLE, TITLE_STR_275_NEWCHEATAVAILABLE))); //New Cheat Available
        DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xA00000FF, viGetX(), viGetY(), 0, 0);
    }


    if ((targettime > 0) && (selected_difficulty != DIFFICULTY_007)) {
        text = langGet(getStringID(LTITLE, TITLE_STR_274_TARGET)); //Target:
        x = 0x37;
        y = y2 + 0xA9;
        DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        stagename[0] = '\0';
        sprintf(stagename, "%02d:%02d", targettime / 60, targettime % 60);
        x = 0x82;
        y = y2 + 0xA9;
        DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        if (besttime >= 0) {
            if (besttime < 0x3FF) {
                stagename[0] = '\0';
                if (besttime >= 0) {
                    sprintf(stagename, "     (%s  %02d:%02d)", langGet(getStringID(LTITLE, TITLE_STR_273_BESTTIME)), besttime / 60, besttime % 60); //Best Time:
                }
                else {
                    sprintf(stagename, "");
                }
                DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
            }
        }
    }
    else {
        if (besttime >= 0) {
            if (besttime < 0x3FF) {
                text = langGet(getStringID(LTITLE, TITLE_STR_273_BESTTIME)); //Best Time:
                x = 0x37;
                y = y2 + 0xA9;
                DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
                stagename[0] = '\0';
                sprintf(stagename, "%02d:%02d", besttime / 60, besttime % 60);
                x = 0x82;
                y = y2 + 0xA9;
                DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
            }
        }
    }


    text = langGet(getStringID(LTITLE, TITLE_STR_106_ACCURACY)); //Accuracy:*
    x = 0x37;
    y = 0xCC;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    if (shotsfired > 0) {
        hitPct = (hitshots * 100.0f) / shotsfired;
    }
    else {
        hitPct = 0.0f;
    }
    sprintf(stagename, "%.1f%%",  hitPct);
    x = 0x82;
    y = 0xCC;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_107_WEAPONOFCHOICE)); //Weapon of choice:*
    x = 0x37;
    y = 0xDC;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    strcpy(stagename, frontGetPlayersFavoriteWeaponInHand(0, 0));
    if ((array_favweapon[0][0] > 0) && (array_favweapon[0][1] == array_favweapon[0][0]))
    {
        temp = strlen(stagename)-1;
        sprintf(&stagename[temp], " x 2\n");
    }
    x = 0xBE;
    y = 0xDC;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_108_SHOTTOTAL)); //Shot total:*
    x = 0x37;
    y = 0xF4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d", shotsfired);
    x = 0x82;
    y = 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_109_HEADHITS)); //Head hits:*
    x = 0xB4;
    y = 0xF4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d (%d%%)", headshots, (s32)(floorFloat(((headshots * 100.0f) / allhits) + 0.5f)));
    x = 0x12C;
    y = 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_110_BODYHITS)); //Body hits:*
    x = 0xB4;
    y = y2 + 0xF4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d (%d%%)", bodyshots, (s32)floorFloat(((bodyshots * 100.0f) / allhits) + 0.5f));
    x = 0x12C;
    y = y2 + 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_111_LIMBHITS)); //Limb hits:*
    x = 0xB4;
    y = (y2 * 2) + 0xF4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d (%d%%)", limbshots, (s32)floorFloat(((limbshots * 100.0f) / allhits) + 0.5f));
    x = 0x12C;
    y = (y2 * 2) + 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_112_OTHER)); //Others:*
    x = 0xB4;
    y = (y2 * 3) + 0xF4;
    temp = reg5 + reg4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d (%d%%)", temp, (s32)floorFloat(((temp * 100.0f) / allhits) + 0.5f));
    x = 0x12C;
    y = (y2 * 3) + 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    text = langGet(getStringID(LTITLE, TITLE_STR_113_KILLTOTAL)); //Kill total:*
    x = 0x37;
    y = y2 + 0xF4;
    DL = frontPrintText(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
    sprintf(stagename, "%d", killcount);
    x = 0x82;
    y = y2 + 0xF4;
    DL = frontPrintText(DL, &x, &y, stagename, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);


    DL = frontAddNextTabText(DL);
    DL = frontAddPreviousTabText(DL);
    DL = frontDrawCursor(DL);
}


//********************************************************************************************************
//CHEAT SCREEN
//********************************************************************************************************

void init_menu15_cheat(void)
{
    int i;

    tab_start_selected = FALSE;
    tab_next_selected = FALSE;
    tab_prev_selected = FALSE;
    tab_prev_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_start_highlight = FALSE;
    totalunlockedcheats = 0x0;

    for (i = 1; i != CHEAT_INVALID; i++) {
        if (cheat_available[i]) {
          arrayUnlockedCheats[totalunlockedcheats] = i;
          totalunlockedcheats++;
        }
    };
    load_walletbond();
}


void update_menu15_cheat(void)
{
  int i;
  u32 appendsp;
  u32 appendmp;

  appendsp = FALSE;
  appendmp = FALSE;

  for (i = 1; i != CHEAT_INVALID; i++) {
    if (g_CheatActivated[i]) {
        appendsp = TRUE;
        if (cheatCheckIfMPCheat(i)) {
            appendmp = TRUE;
        }
    }
  };

  g_AppendCheatSinglePlayer = appendsp;
  g_AppendCheatMultiPlayer = appendmp;
}


// Address 0x7F017C88 NTSC
void interface_menu15_cheat(void)
{
    s32 i;

    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    MP_menu_selected_option = 0;

    if (joyGetButtons(PLAYER_1, A_BUTTON|Z_TRIG) == 0)
    {
        tab_prev_highlight = 0;
        tab_next_highlight = 0;
        tab_start_highlight = 0;
        cheathighlighted = 0;

        if (frontCheckCursorOnPreviousTab())
        {
            tab_prev_highlight = 1;
        }
        else
        {
            if (totalunlockedcheats >= 0xD)
            {
                i = totalunlockedcheats - 0xD;
                if ((s32) cursor_h_pos >= 0xDC)
                {
                    for (; i >= 0; i--)
                    {
                        if ((s32) cursor_v_pos >= (i * 0x14) + 0x35)
                        {
                            cheathighlighted = i + 0xC;
                            break;
                        }
                    }
                }
            }

            if (cheathighlighted == 0)
            {
                i = (totalunlockedcheats >= 0xD)
                    ? 0xB
                    : totalunlockedcheats - 1;

                for (; i >= 0; i--)
                {
                    if ((s32) cursor_v_pos >= (i * 0x14) + 0x35)
                    {
                        cheathighlighted = i;
                        break;
                    }
                }
            }
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, A_BUTTON|Z_TRIG))
    {
        if (tab_prev_highlight != 0)
        {
            tab_prev_selected = 1;
        }
        else
        {
            MP_menu_selected_option = 1;
        }

        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }
    else if (joyGetButtonsPressedThisFrame(0, 0x4000U) != 0)
    {
        tab_prev_selected = 1;
        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, DOOR_METAL_CLOSE2_SFX, NULL);
    }

    disable_all_switches(walletinst[0]);
    set_item_visibility_in_objinstance(walletinst[0], SW_TABS, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_BLANK, 1);
    set_item_visibility_in_objinstance(walletinst[0], SW_CLASSIFIED, 1);
    frontUpdateControlStickPosition();

    if (tab_prev_selected)
    {
        frontChangeMenu(MENU_MODE_SELECT, 0);
        setCursorPOSforMode(gamemode);
        return;
    }

    if (MP_menu_selected_option)
    {
    i = arrayUnlockedCheats[cheathighlighted];
        g_CheatActivated[i] = 1 - g_CheatActivated[i];
    }
}



// Address 0x7F017F5C NTSC
// Address 0x7F017EB8 PAL
Gfx * constructor_menu15_cheat(Gfx *DL)
{
    s32 padding;
    s32 strID;
    s32 var_fp;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    u8 *temp_v0;
    s32 var_s5;

    DL = viSetFillColor(DL,0,0,0);
    DL = viFillScreen(DL);
#ifdef VERSION_EU
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);

    for (var_fp = 0; var_fp < ((totalunlockedcheats >= 0xD) ? 0xC : totalunlockedcheats); var_fp++)
    {
        temp_v0 = cheatGetMenuTextPointer(arrayUnlockedCheats[var_fp]);
        textMeasure(&sp80, &sp7C, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        sp88 = 0x37;
        sp84 = (var_fp * 0x14) + 0x35;
        if ((var_fp == cheathighlighted) && (frontCheckCursorOnPreviousTab() == 0))
        {
            DL = microcode_constructor_related_to_menus(DL, sp88 - 2, sp84 - 1, sp88 + sp7C + 5, sp84 + 0xE, 0x32);
        }

        DL = frontPrintText(DL, &sp88, &sp84, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

        strID  = (g_CheatActivated[arrayUnlockedCheats[var_fp]]) ? getStringID(LTITLE, TITLE_STR_115_ON) : getStringID(LTITLE, TITLE_STR_116_OFF);
        temp_v0 = langGet(strID);
        textMeasure(&sp80, &sp7C, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        sp88 = 0xB3;
        sp84 = (var_fp * 0x14) + 0x35;

        DL = frontPrintText(DL, &sp88, &sp84, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, (g_CheatActivated[arrayUnlockedCheats[var_fp]]) ? 0xA00000FF : 0xFF, viGetX(), viGetY(), 0, 0);
    }

    if (totalunlockedcheats >= 0xd)
    {
        for (var_fp = 0; var_fp < (totalunlockedcheats - 0xC); var_fp++)
        {
            temp_v0 = cheatGetMenuTextPointer(arrayUnlockedCheats[var_fp + 12]);
            textMeasure(&sp80, &sp7C, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp88 = 0xDC;
            sp84 = (var_fp * 0x14) + 0x35;
            if ((var_fp + 0xc == cheathighlighted) && (frontCheckCursorOnPreviousTab() == 0))
            {
                DL = microcode_constructor_related_to_menus(DL, sp88 - 2, sp84 - 1, sp88 + sp7C + 5, sp84 + 0xE, 0x32);
            }

            DL = frontPrintText(DL, &sp88, &sp84, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

            strID  = (g_CheatActivated[arrayUnlockedCheats[var_fp + 12]]) ? getStringID(LTITLE, TITLE_STR_115_ON) : getStringID(LTITLE, TITLE_STR_116_OFF);
            temp_v0 = langGet(strID);
            textMeasure(&sp80, &sp7C, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp88 = 0x158;
            sp84 = (var_fp * 0x14) + 0x35;
            strID = (g_CheatActivated[arrayUnlockedCheats[var_fp + 12]]) ? 0xA00000FF : 0xFF;

            DL = frontPrintText(DL, &sp88, &sp84, temp_v0, ptrFontZurichBoldChars, ptrFontZurichBold, strID, viGetX(), viGetY(), 0, 0);
        }
    }

    DL = frontAddPreviousTabText(DL);

    DL = frontDrawCursor(DL);

    return DL;
}


//********************************************************************************************************
//NO CONTROLLER SCREEN
//********************************************************************************************************
void init_menu16_nocontroller(void) {
    return;
}


void update_menu16_nocontrollers(void) {
    return;
}


void interface_menu16_nocontrollers(void) {
    return;
}


Gfx *constructor_menu16_nocontrollers(Gfx *DL)
{
    s32 y2;
    s32 x2;
    s32 x;
    s32 y;
    s32 text;
    s32 conConnected = joyGetConnectedControllers();
    s32 numContCon = 0;

    if ((conConnected & 8)) {
        numContCon++;
    }
    if ((conConnected & 4)) {
        numContCon++;
    }
    if ((conConnected & 2)) {
        numContCon++;
    }
    DL = microcode_constructor(clear_framebuffer_black(DL));


    if ((numContCon == 0) || (numContCon == 1) || (numContCon == 2) || (numContCon == 3)) {
        text = langGet(getStringID(LTITLE, TITLE_STR_118_NOCONT)); //NO CONTROLLER IN CONTROLLER SOCKET 1
    }
    textMeasure(&y2, &x2, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    x = 0xDC - (x2 >> 1);
    y = 0x99 - (y2 >> 1);
#ifdef BUGFIX_R1
    if (j_text_trigger) {
        DL = textRenderOutlined(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, 0x8000FF, viGetX(), viGetY(), 0, 0);
    }
    else {
#endif
        DL = textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
#ifdef BUGFIX_R1
    }
#endif


    if ((numContCon == 0) || (numContCon == 1) || (numContCon == 2) || (numContCon == 3)) {
        text = langGet(getStringID(LTITLE, TITLE_STR_119_ATTACHCONT)); //PLEASE POWER OFF AND ATTACH A CONTROLLER
    }
    textMeasure(&y2, &x2, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    x = 0xDC - (x2 >> 1);
    y = 0xB1 - (y2 >> 1);
#ifdef BUGFIX_R1
    if (j_text_trigger) {
        DL = textRenderOutlined(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, 0x8000FF, viGetX(), viGetY(), 0, 0);
    }
    else {
#endif
        DL = textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
#ifdef BUGFIX_R1
    }
#endif

    return DL;
}


void do_extended_cast_display(bool doExtended)
{
    full_actor_intro = doExtended;
    if (doExtended)
    {
        intro_character_index = 0;
        return;
    }
    intro_character_index = 1;
}


//********************************************************************************************************
//CAST SCREEN
//********************************************************************************************************
void init_menu18_displaycast(void)
{
    u8 *bufferPtr;
    s32 bufferRemaining;
    s32 allocSize;
    struct coord3d subOffset;
    struct texpool texPool;
    enum BODIES body;
    enum HEADS head;
    s32 weaponProp;
    ModelFileHeader *bodyHeader;
    ModelFileHeader *headHeader;
    ModelFileHeader *weaponHeader;
    s32 padding;
    bool flip;
    s32 cameraPreset;
    struct intro_random_rifles rifles;
    struct intro_random_pistols pistols;
    
    bufferPtr = ptr_logo_and_walletbond_DL;
    subOffset = zeroCoord;
    headHeader = NULL;
    flip = randomGetNext() & 1;

    if ((full_actor_intro != 0) && (intro_character_index == 0))
    {
        musicTrack1ApplySeqpVol(VOLUME_MAX);
        g_musicXTrack1Fade = 0;
        musicTrack1Play(M_INTRO);
    }

    for (intro_animation_count = 0; intro_animation_table[intro_animation_count].animID >= 0; intro_animation_count++)
    {
        // empty
    }

    randomly_selected_intro_animation = randomGetNext() % ((u32) intro_animation_count);
    body = intro_char_table[intro_character_index].body;
    head = intro_char_table[intro_character_index].head;
    cameraPreset = intro_animation_table[randomly_selected_intro_animation].camera_preset;
    
    if (body == BODY_Special_Operations_Uniform)
    {
        // Keep the multiple assignments on the same line for matching.
        switch (randomGetNext() % 5U) 
        { 
            case 0: 
                break; 
            case 1: 
                body = BODY_Formal_Wear; head = HEAD_Male_Brosnan_Default; 
                break; 
            case 2: 
                body = BODY_Jungle_Fatigues; head = HEAD_Male_Brosnan_Default; 
                break; 
            case 3: 
                body = BODY_Parka; head = HEAD_Male_Brosnan_Default;
                break; 
            case 4: 
                body = BODY_Brosnan_Tuxedo; head = HEAD_Male_Brosnan_Tuxedo; 
            break; 
        } 
    } 
    else if (body == BODY_Natalya_Skirt) 
    { 
        if (randomGetNext() & 1) 
        { 
            body = BODY_Natalya_Jungle_Fatigues; 
        } 
    } 
    else if ((body == BODY_Trevelyan_006) && (randomGetNext() & 1))
    { 
        body = BODY_Trevelyan_Janus; 
    } 

    if (head == HEAD_RANDOM) 
    { 
        head = get_random_head(body); 
    } 

    allocSize = 0x19000; 
    bufferRemaining = 0x18160; 

    if (1);

    bufferRemaining = bufferRemaining + allocSize; 

    zbufSetBuffer(ALIGN64_V2(bufferPtr + bufferRemaining), Z_BUFFER_4_3_WIDTH, Z_BUFFER_4_3_HEIGHT);
    texInitPool(&texPool, bufferPtr, allocSize);

    bufferRemaining -= allocSize;
    bufferPtr += allocSize;
    bodyHeader = c_item_entries[body].header;

    load_object_fill_header(c_item_entries[body].header, c_item_entries[body].filename, bufferPtr, bufferRemaining, &texPool);
    allocSize = ALIGN64_V2(get_pc_buffer_remaining_value(c_item_entries[body].filename));
    bufferRemaining -= allocSize;
    bufferPtr += allocSize;

    if (head >= 0)
    {
        headHeader = c_item_entries[head].header;
        load_object_fill_header(c_item_entries[head].header, c_item_entries[head].filename, bufferPtr, bufferRemaining, &texPool);
        allocSize = ALIGN64_V2(get_pc_buffer_remaining_value(c_item_entries[head].filename));
        bufferRemaining -= allocSize;
        bufferPtr += allocSize;
    }

    cast_model = setup_chr_instance(body, head, bodyHeader, headHeader, 0);
    modelSetScale((Model *) cast_model, 0.1f);

    if (cameraPreset != INTRO_WEAPON_TYPE_NONE)
    {
        if (cameraPreset == INTRO_WEAPON_TYPE_RIFLE)
        {
            rifles = random_rifles_in_intro;
            weaponProp = rifles.props[randomGetNext() % 6];
        }
        else
        {
            pistols = random_pistols_in_intro;
            weaponProp = pistols.props[randomGetNext() % 10];
        }

        // Replace Cougar Magnum with PP7 if Cradle has not been completed on any folder.
        if (weaponProp == PROP_CHRRUGER)
        {
            if (fileIsCradleCompletedAnyFolder() == FALSE)
            {
                weaponProp = PROP_CHRWPPK;
            }
        }

        // Replace Laser with PP7 if Aztec has not been completed on Secret Agent or 00 Agent on any folder.
        if (weaponProp == PROP_CHRLASER)
        {
            if (check_aztec_completed_any_folder_secret_00() == FALSE)
            {
                weaponProp = PROP_CHRWPPK;
            }
        }

        // Replace Golden Gun with PP7 if Egyptian has not been completed on 00 Agent on any folder.
        if (weaponProp == PROP_CHRGOLDEN)
        {
            if (fileIsEgyptCompletedOn00AnyFolder() == FALSE)
            {
                weaponProp = PROP_CHRWPPK;
            }
        }

        weaponHeader = PitemZ_entries[weaponProp].header;
        load_object_fill_header(weaponHeader, PitemZ_entries[weaponProp].filename, bufferPtr, bufferRemaining, &texPool);
        allocSize = ALIGN64_V2(get_pc_buffer_remaining_value(PitemZ_entries[weaponProp].filename));
        bufferRemaining -= allocSize;
        bufferPtr += allocSize;

        modelCalculateRwDataLen(weaponHeader);
        cast_model_weapon = modelmgrInstantiateModel(weaponHeader);
        modelSetScale(cast_model_weapon, 0.1f);
        cast_model_weapon->attachedto = cast_model;
        cast_model_weapon->attachedto_objinst = cast_model->obj->Switches[(flip != FALSE) ? (5) : (3)];
    }
    else
    {
        cast_model_weapon = NULL;
    }

    modelSetAnimTranslationScale(cast_model, 0.1f);
    setsuboffset(cast_model, &subOffset);
    setsubroty(cast_model, 0.0f);

#if defined VERSION_EU
    modelSetAnimPlaySpeed(cast_model, 0.6f, 0);
#else
    modelSetAnimPlaySpeed(cast_model, 0.5f, 0);
#endif
    modelSetAnimation(cast_model, animation_table_ptrs1[intro_animation_table[randomly_selected_intro_animation].animID], flip, intro_animation_table[randomly_selected_intro_animation].startframeoffset, intro_animation_table[randomly_selected_intro_animation].playback_speed, 0.0f);

    g_MenuTimer = 0;
    cast_camera_dist_start = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) * 80.0f) + 70.0f;
    cast_camera_dist_end = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) * 80.0f) + 70.0f;
    cast_camera_angle_start = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) - 0.5f) * M_TAU_F;
    cast_camera_angle_end = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) - 0.5f) * 2.5132742f;
    cast_camera_height_start = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) * 200.0f) + (-100.0f);
    cast_camera_height_end = ((((f32) ((u32) randomGetNext())) * (1.0f / U32_MAX)) * 200.0f) + (-100.0f);
    cast_camera_dist = cast_camera_dist_start;
    cast_camera_angle = cast_camera_angle_start;
    cast_camera_height = cast_camera_height_start;
    cast_camera_reset = TRUE;
    cast_rootpos_smoothed.f[0] = 0.0f;
    cast_rootpos_smoothed.f[1] = 0.0f;
    cast_rootpos_smoothed.f[2] = 0.0f;
}


void update_menu18_displaycast(void) {
    if (cast_model != 0) {
        clear_aircraft_model_obj(cast_model);
    }
    if (cast_model_weapon != 0) {
        clear_model_obj(cast_model_weapon);
        return;
    }
}


// Address 0x7F018F60 NTSC

void interface_menu18_displaycast(void)
{
    s32 f;

    // Unlike all other menu functions, this one uses a FOV of 46.0 degrees instead of 60.0 degrees.
    viSetFovY(46.0f);
    viSetZRange(10.0f, 2000.0f);
    viSetUseZBuf(TRUE);
    viSetAspect(ASPECT_RATIO_SD);
    set_cur_player_screen_size(440, 330);
    viSetViewSize(440, 330);
    set_cur_player_viewport_size(0, 0);
    viSetViewPosition(0, 0);

    g_MenuTimer += g_ClockTimer;

#if defined(REFRESH_PAL)
#define INTERFACE_MENU18_TIMER 151
#else
#define INTERFACE_MENU18_TIMER 181
#endif

    if (g_MenuTimer >= INTERFACE_MENU18_TIMER)
    {
#undef INTERFACE_MENU18_TIMER
        intro_character_index++;

        while (1)
        {
            if (intro_char_table[intro_character_index].flag && full_actor_intro == 0 && 1)
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Moonraker_Elite_1_Male) && (check_aztec_completed_any_folder_secret_00()) == 0)
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Moonraker_Elite_2_Female) && (check_aztec_completed_any_folder_secret_00() == 0))
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Mayday) && (check_aztec_completed_any_folder_secret_00() == 0 && (randomGetNext() % 0x2710U)))
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Jaws) && (check_aztec_completed_any_folder_secret_00() == 0 && (randomGetNext() % 0x2710U)))
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Oddjob) && (fileIsEgyptCompletedOn00AnyFolder() == 0 && (randomGetNext() % 0x2710U)))
            {
                intro_character_index++;
                continue;
            }

            if ((intro_char_table[intro_character_index].body == BODY_Baron_Samedi) && (fileIsEgyptCompletedOn00AnyFolder() == 0 && (randomGetNext() % 0x2710U) ))
            {
                intro_character_index++;
                continue;
            }

            break;
        }

        f = intro_character_index;

        if (intro_char_table[f].body < 0)
        {
            intro_character_index = 0;
            f = 0;
        }

        if (intro_character_index > 0)
        {
            frontChangeMenu(MENU_DISPLAY_CAST, 1);
        }
        else if (full_actor_intro != 0)
        {
            frontChangeMenu(MENU_MISSION_SELECT, 1);
            set_cursor_to_stage_solo(SP_LEVEL_CRADLE);
            full_actor_intro = 0;
        }
        else
        {
            select_ramrom_to_play();
        }
    }

    else if ((joyGetButtonsPressedThisFrame(PLAYER_1, 0xFFFF) != 0) && (!full_actor_intro))
    {
        frontChangeMenu(MENU_FILE_SELECT, TRUE);
    }
}


Gfx *constructor_menu18_displaycast(Gfx *DL)
{
    coord3d campos = cast_camera_pos;
    coord3d tarpos = cast_camera_target;
    coord3d up = cast_camera_up;
    Light *light;
    Mtxf mtx;
    ModelRenderData renderdata = cast_renderdata_default;
    s32 pad1A4;
    s32 pad1A0;
    Mtxf mtx2;
    s32 x;
    s32 y;
    s32 textwidth;
    s32 textheight;
    s32 i;
    f32 menufrac = (f32)g_MenuTimer / CAST_INTRO_LEN_F;
    f32 fade;
    char *text;
    coord3d vec = cast_camera_offset;
    coord3d suboffset;
    s32 pad120;
    s32 pad124;
    Mtx lookatmtx;
    s32 padDC;
 
    if (g_MenuTimer < 0 || g_MenuTimer >= CAST_INTRO_LEN)
    {
        fade = 0.0f;
    }
    else if (g_MenuTimer < CAST_INTRO_FADE)
    {
        fade = (f32)g_MenuTimer / CAST_INTRO_FADE_F;
    }
    else if (g_MenuTimer >= CAST_INTRO_FADEOUT)
    {
        fade = (f32)(CAST_INTRO_LEN - g_MenuTimer) / CAST_INTRO_FADE_F;
    }
    else
    {
        fade = 1.0f;
    }
 
    DL = viFillScreen(viSetFillColor(DL, 0, 0, 0));
 
    cast_camera_dist = (cast_camera_dist_end - cast_camera_dist_start) * menufrac + cast_camera_dist_start;
    cast_camera_angle = (cast_camera_angle_end - cast_camera_angle_start) * menufrac + cast_camera_angle_start;
    cast_camera_height = (cast_camera_height_end - cast_camera_height_start) * menufrac + cast_camera_height_start;
 
    if (cast_camera_angle < 0.0f)
    {
        cast_camera_angle += M_TAU_F;
    }
 
    campos.x = cast_camera_dist * sinf(cast_camera_angle) + cosf(cast_camera_angle) * 0.2f * cast_camera_dist;
    campos.y = cast_camera_height;
    campos.z = cast_camera_dist * cosf(cast_camera_angle) - sinf(cast_camera_angle) * 0.2f * cast_camera_dist;
 
    tarpos.x += cosf(cast_camera_angle) * 0.2f * cast_camera_dist;
    tarpos.z += -sinf(cast_camera_angle) * 0.2f * cast_camera_dist;
 
    light = dynAllocateLights(2);
 
    guLookAtReflect(&lookatmtx, (LookAt *)light, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
 
    gSPNumLights(DL++, 1); \
    gSPLight(DL++, &gelogolight.l[0], 1); \
    gSPLight(DL++, &gelogolight, 2);
 
    gSPLookAt(DL++, light);
 
    modelTickAnim(cast_model, g_ClockTimer, 1);
    modelSetDistanceDisabled(1);
    sub_GAME_7F073FC8(0);
    subcalcpos(cast_model);
 
    if (cast_model_weapon != NULL && cast_model_weapon->obj->Switches[0] != NULL)
    {
        modelGetNodeRwData( cast_model_weapon, cast_model_weapon->obj->Switches[0])->Gunfire.visible = 0;
    }
 
    if (cast_model_weapon != NULL && cast_model_weapon->obj->Switches[2] != NULL)
    {
        modelGetNodeRwData(cast_model_weapon, cast_model_weapon->obj->Switches[2])->Switch.visible = 0;
    }
 
    renderdata.mtxlist = (Mtxf *)dynAllocate(cast_model->obj->numMatrices << 6);
 
    matrix_4x4_set_identity(&mtx);
 
    renderdata.basemtx = &mtx;
 
    subcalcmatrices(&renderdata, cast_model);
    getsuboffset(cast_model, &suboffset);
 
    if (cast_camera_reset)
    {
        cast_rootpos_smoothed.y = suboffset.y;
    }
 
    vec.f[0] = (suboffset.x - cast_rootpos_smoothed.x) / g_GlobalTimerDelta;
    vec.f[1] = (suboffset.y - cast_rootpos_smoothed.y) / g_GlobalTimerDelta;
    vec.f[2] = (suboffset.z - cast_rootpos_smoothed.z) / g_GlobalTimerDelta;
 
    if (cast_camera_reset)
    {
        cast_rootvel_accumulator.x = vec.f[0] / CAST_DAMP_COMP;
        cast_rootvel_accumulator.y = vec.f[1] / CAST_DAMP_COMP;
        cast_rootvel_accumulator.z = vec.f[2] / CAST_DAMP_COMP;
    }
 
    for (i = 0; i < g_ClockTimer; i++)
    {
        cast_rootvel_accumulator.x = vec.f[0] + CAST_DAMP * cast_rootvel_accumulator.x;
        cast_rootvel_accumulator.y = vec.f[1] + CAST_DAMP * cast_rootvel_accumulator.y;
        cast_rootvel_accumulator.z = vec.f[2] + CAST_DAMP * cast_rootvel_accumulator.z;
    }
 
    cast_rootvel_smoothed.x = cast_rootvel_accumulator.x * CAST_DAMP_COMP;
    cast_rootvel_smoothed.y = cast_rootvel_accumulator.y * CAST_DAMP_COMP;
    cast_rootvel_smoothed.z = cast_rootvel_accumulator.z * CAST_DAMP_COMP;
 
    cast_rootpos_smoothed.x += cast_rootvel_smoothed.x * g_GlobalTimerDelta;
    cast_rootpos_smoothed.y += cast_rootvel_smoothed.y * g_GlobalTimerDelta;
    cast_rootpos_smoothed.z += cast_rootvel_smoothed.z * g_GlobalTimerDelta;
 
    mtx4TransformVecInPlace(cast_model->render_pos, &vec);
 
    vec.f[0] -= cast_rootpos_smoothed.x;
    vec.f[1] -= cast_rootpos_smoothed.y;
    vec.f[2] -= cast_rootpos_smoothed.z;
 
    if (cast_camera_reset)
    {
        cast_camera_reset = FALSE;

        cast_target_accumulator.x = vec.f[0] / CAST_DAMP_COMP;
        cast_target_accumulator.y = vec.f[1] / CAST_DAMP_COMP;
        cast_target_accumulator.z = vec.f[2] / CAST_DAMP_COMP;
    }
 
    for (i = 0; i < g_ClockTimer; i++)
    {
        cast_target_accumulator.x = vec.f[0] + CAST_DAMP * cast_target_accumulator.x;
        cast_target_accumulator.y = vec.f[1] + CAST_DAMP * cast_target_accumulator.y;
        cast_target_accumulator.z = vec.f[2] + CAST_DAMP * cast_target_accumulator.z;
    }
 
    cast_target_smoothed.x = cast_target_accumulator.x * CAST_DAMP_COMP;
    cast_target_smoothed.y = cast_target_accumulator.y * CAST_DAMP_COMP;
    cast_target_smoothed.z = cast_target_accumulator.z * CAST_DAMP_COMP;
 
    vec.f[0] = cast_rootpos_smoothed.x + cast_target_smoothed.x;
    vec.f[1] = (cast_rootpos_smoothed.y + cast_target_smoothed.y) - 10.0f;
    vec.f[2] = cast_rootpos_smoothed.z + cast_target_smoothed.z;
 
    tarpos.x += vec.f[0];
    tarpos.y += vec.f[1];
    tarpos.z += vec.f[2];
 
    campos.x += cast_rootpos_smoothed.x;
    campos.y += cast_rootpos_smoothed.y + 52.5f;
    campos.z += cast_rootpos_smoothed.z;
 
    matrix_4x4_set_lookat_target(&mtx, campos.x, campos.y, campos.z, tarpos.x, tarpos.y, tarpos.z, up.x, up.y, up.z);
 
    renderdata.basemtx = &mtx;
    renderdata.mtxlist = (Mtxf *)dynAllocate(cast_model->obj->numMatrices << 6);
 
    subcalcmatrices(&renderdata, cast_model);
 
    if (cast_model_weapon != NULL)
    {
        renderdata.basemtx = modelFindNodeMtx(cast_model, cast_model_weapon->attachedto_objinst, 0);
 
        if (cast_model_weapon->attachedto_objinst == cast_model->obj->Switches[5])
        {
            matrix_4x4_set_rotation_around_z(M_PI_F, &mtx2);
            matrix_4x4_multiply_in_place(renderdata.basemtx, &mtx2);
 
            renderdata.basemtx = &mtx2;
        }
 
        renderdata.mtxlist = (Mtxf *)dynAllocate(cast_model_weapon->obj->numMatrices << 6);
 
        instcalcmatrices(&renderdata, cast_model_weapon);
    }
 
    renderdata.PropType = PROP_TYPE_EXPLOSION;
    renderdata.zbufferenabled = TRUE;
    renderdata.gdl = DL;
    renderdata.flags = 3;
 
    subdraw(&renderdata, cast_model);
 
    if (cast_model_weapon != NULL)
    {
        subdraw(&renderdata, cast_model_weapon);
    }
 
    DL = renderdata.gdl;
 
    modelSetDistanceDisabled(0);
 
    for (i = 0; i < cast_model->obj->numMatrices; i++)
    {
        matrix_4x4_copy(&((s8 *)cast_model->render_pos)[i * sizeof(Mtxf)], &mtx2);
        matrix_4x4_f32_to_s32(&mtx2, &((Mtxf *)cast_model->render_pos)[i]);
    }
 
    if (cast_model_weapon != NULL)
    {
        for (i = 0; i < cast_model_weapon->obj->numMatrices; i++)
        {
            matrix_4x4_copy(&((s8 *)cast_model_weapon->render_pos)[i * sizeof(Mtxf)], &mtx2);
 
            matrix_4x4_f32_to_s32(&mtx2, &((Mtxf *)cast_model_weapon->render_pos)[i]);
        }
    }
 
    gDPSetScissor(DL++, G_SC_NON_INTERLACE, 0, 0, 440, 330);
    gDPPipeSync(DL++);
    gDPSetCycleType(DL++, G_CYC_1CYCLE);
    gDPSetColorDither(DL++, G_CD_DISABLE);
    gDPSetTexturePersp(DL++, G_TP_NONE);
    gDPSetAlphaCompare(DL++, G_AC_NONE);
    gDPSetTextureLOD(DL++, G_TL_TILE);
    gDPSetTextureFilter(DL++, G_TF_BILERP);
    gDPSetTextureConvert(DL++, G_TC_FILT);
    gDPSetTextureLUT(DL++, G_TT_NONE);
    gDPSetRenderMode(DL++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(DL++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(DL++, 0, 0, 0, 0, 0, 0xFF - (s32)(255.0f * fade));
    gDPFillRectangle(DL++, 0, 0, 440, 330);
    gDPPipeSync(DL++);
    gDPSetColorDither(DL++, G_CD_BAYER);
    gDPSetTexturePersp(DL++, G_TP_PERSP);
    gDPSetTextureLOD(DL++, G_TL_LOD);
 
    DL = microcode_constructor(DL);
 
    if (full_actor_intro == FALSE)
    {
        text = langGet( (u16)intro_char_table[intro_character_index].text1);
 
        textMeasure(&textheight, &textwidth, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
 
        x = 315 - textwidth / 2;
        y = 108;
 
        DL = microcode_constructor_related_to_menus(DL, x, 108, x + textwidth + 1, textheight + 109, 0);
 
        DL = textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, (u32)(255.0f * fade) | 0xFFFFFF00, viGetX(), viGetY(), 0, 0);
    }
 
    text = langGet((u16)intro_char_table[intro_character_index].text2);
 
    textMeasure(&textheight, &textwidth, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
 
    x = 315 - textwidth / 2;
    y = 152;
 
    DL = microcode_constructor_related_to_menus(DL, x, 152, x + textwidth + 1, textheight + 153, 0);
 
    DL = textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, (u32)(255.0f * fade) | 0xFFFFFF00, viGetX(), viGetY(), 0, 0);
 
    text = langGet((u16)intro_char_table[intro_character_index].text3);
 
    textMeasure(&textheight, &textwidth, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
 
    x = 315 - textwidth / 2;
    y = 174;
 
    DL = microcode_constructor_related_to_menus(DL, x, 174, x + textwidth + 1, textheight + 175, 0);
 
    return textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, (u32)(255.0f * fade) | 0xFFFFFF00, viGetX(), viGetY(), 0, 0);
}


//********************************************************************************************************
//SPECTRUM EMULATOR
//********************************************************************************************************
void init_menu19_spectrum(void)
{
    #if defined(LEFTOVERSPECTRUM)
    SPECTRUMROMS rom = ROM_SABRE;

    if (!joyGetButtons(2, L_CBUTTONS))
    {
        if (joyGetButtons(2, R_CBUTTONS))
        {
            rom = ROM_ATIC;
        }
        else if (joyGetButtons(2, U_CBUTTONS))
        {
            rom = ROM_JETPAC;
        }
        else if (joyGetButtons(2, D_CBUTTONS))
        {
            rom = ROM_JETMAN;
        }
        else if (joyGetButtons(2, L_JPAD))
        {
            rom = ROM_ALIEN8;
        }
        else if (joyGetButtons(2, R_JPAD))
        {
            rom = ROM_GUNFRIGHT;
        }
        else if (joyGetButtons(2, U_JPAD))
        {
            rom = ROM_UNDER;
        }
        else
        {
            rom = ROM_SABRE;
            if (joyGetButtons(2, D_JPAD))
            {
                rom = ROM_KNIGHTLORE;
            }
        }
    }
    init_spectrum_game(rom);
    #endif
}


void update_menu19_spectrum(void) 
{
    return;
}


void interface_menu19_spectrum(void)
{
    #if defined(LEFTOVERSPECTRUM)
    viSetFovY(FOV_Y_F);
    viSetAspect(ASPECT_RATIO_SD);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);
    run_spectrum_game();
    #endif
}


#if !defined(LEFTOVERSPECTRUM)
Gfx* constructor_menu19_spectrum(Gfx* DL)
{
    return DL;
}
#else
// Address 0x7F01A4E0 NTSC
Gfx * constructor_menu19_spectrum(Gfx * DL)
{
    DL = clear_framebuffer_black(DL);

    gDPSetCycleType(DL++, G_CYC_1CYCLE);
    gDPSetRenderMode(DL++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode(DL++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetCombineMode(DL++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetTextureFilter(DL++, G_TF_POINT);
    gDPSetTextureImage(DL++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, color_palette_entries_50_percent);
    gDPSetTile(DL++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 1, 0x100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(DL++);
    gDPLoadTLUTCmd2(DL++, G_TX_LOADTILE, 7);
    gDPPipeSync(DL++);
    gDPSetTextureLUT(DL++, G_TT_RGBA16);

    DL = spectrum_draw_screen(DL);

    return DL;
}
#endif


void frontChangeMenu(MENU menu, s32 reload)
{
    if ((menu == MENU_RUN_STAGE) || (menu == MENU_SPECTRUM_EMU))
    {
        is_emulating_spectrum = TRUE;
    }

    if (reload)
    {
        menu_update = menu;
        return;
    }

    maybe_prev_menu = menu;
}


MENU get_currentmenu(void)
{
  return current_menu;
}


void menu_init(void)
{
    s32 var_v0;

    if (current_menu == MENU_SWITCH_SCREENS)
    {
        if (spectrum_related_flag != 0)
        {
            if (viGetFrameBuf2() == (cfb_16[1]))
            {
                screen_size = SCREEN_SIZE_440x330;
                spectrum_related_flag = 0;
            }
        }
        else if ((is_emulating_spectrum != 0) && (viGetFrameBuf2() == cfb_16[0]))
        {
            screen_size = SCREEN_SIZE_320x240;
            is_emulating_spectrum = 0;
        }
    }

#if defined(VERSION_EU)
#define MENU_INIT_ASPECT_440 ASPECT_RATIO_EU_400_330
#define MENU_INIT_ASPECT_320 ASPECT_RATIO_EU_320_272
#else
#define MENU_INIT_ASPECT_440 ASPECT_RATIO
#define MENU_INIT_ASPECT_320 ASPECT_RATIO
#endif

    if (screen_size != SCREEN_SIZE_320x240)
    {
        if (viGetFrameBuf2() == (cfb_16[1]))
        {
            viSetFrameBuf2(ptr_menu_videobuffer);
        }

        viSetAspect(MENU_INIT_ASPECT_440);
        viSetXY(440, 330);
        viSetBuf(440, 330);
        set_cur_player_screen_size(440, 330);
        viSetViewSize(440, 330);
        set_cur_player_viewport_size(0, 0);
        viSetViewPosition(0, 0);
    }
    else
    {
        viSetAspect(MENU_INIT_ASPECT_320);
        viSetXY(320, SCREEN_HEIGHT);
        viSetBuf(320, SCREEN_HEIGHT);
        set_cur_player_screen_size(320, SCREEN_HEIGHT);
        viSetViewSize(320, SCREEN_HEIGHT);
        set_cur_player_viewport_size(0, 0);
        viSetViewPosition(0, 0);
    }

#undef MENU_INIT_ASPECT_440
#undef MENU_INIT_ASPECT_320

    if (
        ((menu_update > MENU_INVALID) || (maybe_prev_menu > MENU_INVALID))
        && (current_menu != MENU_SWITCH_SCREENS))
    {
        switch(current_menu) {
            case MENU_LEGAL_SCREEN:           update_menu00_legalscreen();          break;
            case MENU_NINTENDO_LOGO:          update_menu01_nintendo();             break;
            case MENU_RAREWARE_LOGO:          update_menu02_rareware();             break;
            case MENU_EYE_INTRO:              update_menu_03_gunbarrel();                 break;
            case MENU_GOLDENEYE_LOGO:         update_menu04_goldeneye();            break;
            case MENU_FILE_SELECT:            update_menu05_filesel();              break;
            case MENU_MODE_SELECT:            update_menu06_modesel();              break;
            case MENU_MISSION_SELECT:         update_menu07_missionsel();           break;
            case MENU_DIFFICULTY:             update_menu08_difficulty();           break;
            case MENU_007_OPTIONS:            update_menu09_007options();           break;
            case MENU_BRIEFING:               update_menu0A_briefing();             break;
            case MENU_MISSION_FAILED:         update_menu0C_missionfailed();        break;
            case MENU_MISSION_COMPLETE:       update_menu0D_missioncomplete();      break;
            case MENU_MP_OPTIONS:             update_menu0E_mpoptions();            break;
            case MENU_MP_SCENARIO_SELECT:     update_menu13_mpscenario();           break;
            case MENU_MP_CHAR_SELECT:         update_menu0F_mpcharsel();            break;
            case MENU_MP_TEAMS:               update_menu14_mpteams();              break;
            case MENU_MP_HANDICAP:            update_menu10_mphandicap();           break;
            case MENU_MP_CONTROL_STYLE:       update_menu11_mpcontrols();           break;
            case MENU_MP_STAGE_SELECT:        update_menu12_mpstage();              break;
            case MENU_CHEAT:                  update_menu15_cheat();                break;
            case MENU_NO_CONTROLLERS:         update_menu16_nocontrollers();        break;
            case MENU_DISPLAY_CAST:           update_menu18_displaycast();          break;
            case MENU_SPECTRUM_EMU:           update_menu19_spectrum();             break;
        }

        if (menu_update > MENU_INVALID)
        {
            current_menu = MENU_SWITCH_SCREENS;
            reset_menutimer();
        }
    }

    if (maybe_prev_menu > MENU_INVALID)
    {
        current_menu = maybe_prev_menu;
        maybe_prev_menu = MENU_INVALID;

        switch(current_menu) {
            case MENU_LEGAL_SCREEN:           init_menu00_legalscreen();            break;
            case MENU_NINTENDO_LOGO:          init_menu01_nintendo();               break;
            case MENU_RAREWARE_LOGO:          init_menu02_rarelogo();               break;
            case MENU_EYE_INTRO:              init_menu03_gunbarrel();               break;
            case MENU_GOLDENEYE_LOGO:         init_menu04_goldeneyelogo();          break;
            case MENU_FILE_SELECT:            init_menu05_fileselect();             break;
            case MENU_MODE_SELECT:            init_menu06_modeselect();             break;
            case MENU_MISSION_SELECT:         init_menu07_missionselect();          break;
            case MENU_DIFFICULTY:             init_menu08_difficultyselect();       break;
            case MENU_007_OPTIONS:            init_menu09_007difficultyselect();    break;
            case MENU_BRIEFING:               init_menu0A_briefing();               break;
            case MENU_RUN_STAGE:              init_menu0B_runstage();               break;
            case MENU_MISSION_FAILED:         init_menu0C_missionfailed();          break;
            case MENU_MISSION_COMPLETE:       init_menu0D_missioncomplete();        break;
            case MENU_MP_OPTIONS:             init_menu0E_mpoptions();              break;
            case MENU_MP_SCENARIO_SELECT:     init_menu13_mpscenariosel();          break;
            case MENU_MP_CHAR_SELECT:         init_menu0f_mpcharsel();              break;
            case MENU_MP_TEAMS:               init_menu14_mpteamsel();              break;
            case MENU_MP_HANDICAP:            init_menu10_mphandicap();             break;
            case MENU_MP_CONTROL_STYLE:       init_menu11_mpcontrol();              break;
            case MENU_MP_STAGE_SELECT:        init_menu12_mpstage();                break;
            case MENU_CHEAT:                  init_menu15_cheat();                  break;
            case MENU_NO_CONTROLLERS:         init_menu16_nocontroller();           break;
            case MENU_DISPLAY_CAST:           init_menu18_displaycast();            break;
            case MENU_SPECTRUM_EMU:           init_menu19_spectrum();               break;
        }
    }

    switch(current_menu) {
        case MENU_LEGAL_SCREEN:           interface_menu00_legalscreen();           break;
        case MENU_SWITCH_SCREENS:         interface_menu17_switchscreens();         break;
        case MENU_NINTENDO_LOGO:          interface_menu01_nintendo();              break;
        case MENU_RAREWARE_LOGO:          interface_menu02_rareware();              break;
        case MENU_EYE_INTRO:              interface_menu03_eye();                   break;
        case MENU_GOLDENEYE_LOGO:         interface_menu04_goldeneyelogo();         break;
        case MENU_FILE_SELECT:            interface_menu05_fileselect();            break;
        case MENU_MODE_SELECT:            interface_menu06_modesel();               break;
        case MENU_MISSION_SELECT:         interface_menu07_missionsel();            break;
        case MENU_DIFFICULTY:             interface_menu08_difficulty();            break;
        case MENU_007_OPTIONS:            interface_menu09_007options();            break;
        case MENU_BRIEFING:               interface_menu0A_briefing();              break;
        case MENU_MISSION_FAILED:         interface_menu0C_missionfailed();         break;
        case MENU_MISSION_COMPLETE:       interface_menu0D_missioncomplete();       break;
        case MENU_MP_OPTIONS:             interface_menu0E_mpoptions();             break;
        case MENU_MP_SCENARIO_SELECT:     interface_menu13_mpscenario();            break;
        case MENU_MP_CHAR_SELECT:         interface_menu0F_mpcharsel();             break;
        case MENU_MP_TEAMS:               interface_menu14_mpteams();               break;
        case MENU_MP_HANDICAP:            interface_menu10_mphandicap();            break;
        case MENU_MP_CONTROL_STYLE:       interface_menu11_mpcontrols();            break;
        case MENU_MP_STAGE_SELECT:        interface_menu12_mpstage();               break;
        case MENU_CHEAT:                  interface_menu15_cheat();                 break;
        case MENU_NO_CONTROLLERS:         interface_menu16_nocontrollers();         break;
        case MENU_DISPLAY_CAST:           interface_menu18_displaycast();           break;
        case MENU_SPECTRUM_EMU:           interface_menu19_spectrum();              break;
        case MENU_RUN_STAGE:
            if (interface_menu0B_runstage())
            {
                frontChangeMenu(MENU_LEGAL_SCREEN, 1);
            }
            else if (gamemode == GAMEMODE_MULTI)
            {
                frontChangeMenu(MENU_MP_OPTIONS, 1);
            }
            /**
             * The intro roster only shows main characters. The credits roster shows minor characters like guards.
             */
            else if (selected_stage == LEVELID_CUBA)
            {
                do_extended_cast_display(TRUE);
                frontChangeMenu(MENU_DISPLAY_CAST, 1);
            }
            else
            {
                frontChangeMenu(MENU_MISSION_FAILED, 1);
            }
    }

}


Gfx * menu_jump_constructor_handler(Gfx *DL)
{
    switch(current_menu) {
        case MENU_LEGAL_SCREEN:
            DL = constructor_menu00_legalscreen(DL);
            break;
        case MENU_SWITCH_SCREENS:
            DL = constructor_menu17_switchscreens(DL);
            break;
        case MENU_NINTENDO_LOGO:
            DL = constructor_menu01_nintendo(DL);
            break;
        case MENU_RAREWARE_LOGO:
            DL = constructor_menu02_rareware(DL);
            break;
        case MENU_EYE_INTRO:
            DL = constructor_menu03_eye(DL);
            break;
        case MENU_GOLDENEYE_LOGO:
            DL = constructor_menu04_goldeneyelogo(DL);
            break;
        case MENU_FILE_SELECT:
            DL = constructor_menu05_fileselect(DL);
            break;
        case MENU_MODE_SELECT:
            DL = constructor_menu06_modesel(DL);
            break;
        case MENU_MISSION_SELECT:
            DL = constructor_menu07_missionsel(DL);
            break;
        case MENU_DIFFICULTY:
            DL = constructor_menu08_difficulty(DL);
            break;
        case MENU_007_OPTIONS:
            DL = constructor_menu09_007options(DL);
            break;
        case MENU_BRIEFING:
            DL = constructor_menu0A_briefing(DL);
            break;
        case MENU_MISSION_FAILED:
            DL = constructor_menu0C_missionfailed(DL);
            break;
        case MENU_MISSION_COMPLETE:
            DL = constructor_menu0D_missioncomplete(DL);
            break;
        case MENU_MP_OPTIONS:
            DL = constructor_menu0E_mpoptions(DL);
            break;
        case MENU_MP_SCENARIO_SELECT:
            DL = constructor_menu13_mpscenario(DL);
            break;
        case MENU_MP_CHAR_SELECT:
            DL = constructor_menu0F_mpcharsel(DL);
            break;
        case MENU_MP_TEAMS:
            DL = constructor_menu14_mpteams(DL);
            break;
        case MENU_MP_HANDICAP:
            DL = constructor_menu10_mphandicap(DL);
            break;
        case MENU_MP_CONTROL_STYLE:
            DL = constructor_menu11_mpcontrol(DL);
            break;
        case MENU_MP_STAGE_SELECT:
            DL = constructor_menu12_mpstage(DL);
            break;
        case MENU_CHEAT:
            DL = constructor_menu15_cheat(DL);
            break;
        case MENU_NO_CONTROLLERS:
            DL = constructor_menu16_nocontrollers(DL);
            break;
        case MENU_DISPLAY_CAST:
            DL = constructor_menu18_displaycast(DL);
            break;
        case MENU_SPECTRUM_EMU:
            DL = constructor_menu19_spectrum(DL);
    }

    return DL;
}


