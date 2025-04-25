#include <os_extension.h>
#include <assets/GlobalImageTable.h>
#include "assets/image_externs.h"
#include <ultra64.h>
#include <bondgame.h>
#include <bondconstants.h>
#include <boss.h>
#include <fr.h>
#include "lvl_text.h"
#include <joy.h>
#include <music.h>
#include <random.h>
#include <snd.h>
#include "bondview.h"
#include "chr.h"
#include "chr_b.h"
#include "chrlv.h"
#include "cheat_buttons.h"
#include "chrobjdata.h"
#include "file2.h"
#include "front.h"
#include "image_bank.h"
#include "lvl.h"
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
#include "textrelated.h"
#include "matrixmath.h"
#include "bg.h"
#include "chrai.h"
#include "title.h"
#include <assets/font_dl.h>
#include "image.h"
#include "ob.h"
#include "gbi_extension.h"



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
f32 flt_CODE_bss_800695A0;
//CODE.bss:800695A4
f32 flt_CODE_bss_800695A4;
//CODE.bss:800695A8
f32 flt_CODE_bss_800695A8;
//CODE.bss:800695AC
f32 flt_CODE_bss_800695AC;
//CODE.bss:800695B0
f32 flt_CODE_bss_800695B0;
//CODE.bss:800695B4
f32 flt_CODE_bss_800695B4;
//CODE.bss:800695B8
f32 flt_CODE_bss_800695B8;
//CODE.bss:800695BC
f32 flt_CODE_bss_800695BC;
//CODE.bss:800695C0
f32 flt_CODE_bss_800695C0;
//CODE.bss:800695C4
f32 flt_CODE_bss_800695C4;
//CODE.bss:800695C8
struct coord3d flt_CODE_bss_800695C8;
//CODE.bss:800695D4
f32 flt_CODE_bss_800695D4;
//CODE.bss:800695D8
struct coord3d flt_CODE_bss_800695D8;

//CODE.bss:800695E4
s32 bss_800695E4;

//CODE.bss:800695E8
struct coord3d flt_CODE_bss_800695E8;

//CODE.bss:800695F4
f32 flt_CODE_bss_800695F4;
//CODE.bss:800695F8
struct coord3d flt_CODE_bss_800695F8;
//CODE.bss:80069604
f32 flt_CODE_bss_80069604;

//CODE.bss:80069608
struct coord3d flt_CODE_bss_80069608;


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
coord3d dword_CODE_bss_80069620[MAX_FOLDER_COUNT];

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
s32 dword_CODE_bss_80069730[MAX_PLAYER_COUNT];

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
s32 highlight_enemy_accuracy;
//CODE.bss:800697A0
s32 highlight_enemy_damage;

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
f32 slider_007_mode_accuracy = 1.0f;
f32 slider_007_mode_damage = 1.0f;

rgba_u8 D_8002A9B0 = { 160, 0, 0, 0 };
rgba_u8 D_8002A9B4 = { 150, 0, 0, 0 };
rgba_u8 D_8002A9B8 = { 40, 0, 0, 0 };
rgba_u8 D_8002A9BC = { 140, 0, 0, 0 };

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

ModelRenderData       D_8002AABC = {NULL,
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

ModelRenderData       D_8002AB08 = {NULL,
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

ModelRenderData       D_8002AB54 = {NULL,
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


struct coord3d D_8002AB94[] = {
    {-900.0f, 800.0f, 0.0f},
    {1800.0f, 800.0f, 0.0f},
    {-1800.0f, -200.0f, 0.0f},
    {900.0f, -200.0f, 0.0f}
};

struct rectbbox folder_option_COPY_bound = { 0 };
struct rectbbox folder_option_ERASE_bound = { 0 };

struct mission_folder_setup mission_folder_setup_entries[] = {
    {"1",   getStringID(LTITLE, TITLE_STR_120_ARK),                  0, LEVELID_NONE,     0, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_121_DAM),                  0, LEVELID_DAM,      0, MISSION_PART,      0, "UbriefdamZ"},
    {"ii",  getStringID(LTITLE, TITLE_STR_122_FAC),                  0, LEVELID_FACILITY, 0, MISSION_PART,      1, "UbriefarkZ"},
    {"iii", getStringID(LTITLE, TITLE_STR_123_RUN),                  0, LEVELID_RUNWAY,   0, MISSION_PART,      2, "UbriefrunZ"},
    {"2",   getStringID(LTITLE, TITLE_STR_124_SEV),                  0, LEVELID_NONE,     0, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_125_SURF),                  0, LEVELID_SURFACE,  0, MISSION_PART,      3, "UbriefsevxZ"},
    {"ii",  getStringID(LTITLE, TITLE_STR_126_BUNK),                  0, LEVELID_BUNKER1,  0, MISSION_PART,      4, "UbriefsevbunkerZ"},
    {"3",   getStringID(LTITLE, TITLE_STR_127_KIRG),                  0, LEVELID_NONE,     1, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_128_SILO4), getStringID(LTITLE, TITLE_STR_129_SILO), LEVELID_SILO,     1, MISSION_PART,      5, "UbriefsiloZ"},
    {"4",   getStringID(LTITLE, TITLE_STR_130_MONTE),                  0, LEVELID_NONE,     1, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_131_FRIG),                  0, LEVELID_FRIGATE,  1, MISSION_PART,      6, "UbriefdestZ"},
    {"5",   getStringID(LTITLE, TITLE_STR_124_SEV),                  0, LEVELID_NONE,     1, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_125_SURF),                  0, LEVELID_SURFACE2, 1, MISSION_PART,      7, "UbriefsevxbZ"},
    {"ii",  getStringID(LTITLE, TITLE_STR_126_BUNK),                  0, LEVELID_BUNKER2,  1, MISSION_PART,      8, "UbriefsevbZ"},
    {"6",   getStringID(LTITLE, TITLE_STR_132_STPETER),                  0, LEVELID_NONE,     2, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_133_STATPARK), getStringID(LTITLE, TITLE_STR_134_STAT), LEVELID_STATUE,   2, MISSION_PART,      9, "UbriefstatueZ"},
    {"ii",  getStringID(LTITLE, TITLE_STR_135_MILARCH), getStringID(LTITLE, TITLE_STR_136_ARCH), LEVELID_ARCHIVES, 2, MISSION_PART,    0xA, "UbriefarchZ"},
    {"iii", getStringID(LTITLE, TITLE_STR_137_STREETS),                  0, LEVELID_STREETS,  2, MISSION_PART,    0xB, "UbriefpeteZ"},
    {"iv",  getStringID(LTITLE, TITLE_STR_138_DEPOT),                  0, LEVELID_DEPOT,    2, MISSION_PART,    0xC, "UbriefdepoZ"},
    {"v",   getStringID(LTITLE, TITLE_STR_139_TRAIN),                  0, LEVELID_TRAIN,    2, MISSION_PART,    0xD, "UbrieftraZ"},
    {"7",   getStringID(LTITLE, TITLE_STR_140_CUBA),                  0, LEVELID_NONE,     3, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_141_JUN),                  0, LEVELID_JUNGLE,   3, MISSION_PART,    0xE, "UbriefjunZ"},
    {"ii",  getStringID(LTITLE, TITLE_STR_142_CONCENTER), getStringID(LTITLE, TITLE_STR_143_CON), LEVELID_CONTROL,  3, MISSION_PART,    0xF, "UbriefcontrolZ"},
    {"iii", getStringID(LTITLE, TITLE_STR_144_WATERCAV), getStringID(LTITLE, TITLE_STR_145_CAV), LEVELID_CAVERNS,  3, MISSION_PART,   0x10, "UbriefcaveZ"},
    {"iv",  getStringID(LTITLE, TITLE_STR_146_ANTENNA), getStringID(LTITLE, TITLE_STR_147_CRADLE), LEVELID_CRADLE,   3, MISSION_PART,   0x11, "UbriefcradZ"},
    {"8",   getStringID(LTITLE, TITLE_STR_148_TEOTIHUACA),                  0, LEVELID_NONE,     4, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_149_AZTECCOMPLEX), getStringID(LTITLE, TITLE_STR_150_AZTEC), LEVELID_AZTEC,    4, MISSION_PART,   0x12, "UbriefaztZ"},
    {"9",   getStringID(LTITLE, TITLE_STR_151_ELSAGHIRA),                  0, LEVELID_NONE,     4, MISSION_HEADER,   -1, 0},
    {"i",   getStringID(LTITLE, TITLE_STR_152_EGYPTIANTEMPLE), getStringID(LTITLE, TITLE_STR_153_EGYPTIAN), LEVELID_EGYPT,    4, MISSION_PART,   0x13, "UbriefcrypZ"},
    {NULL, 0, 0, LEVELID_NONE, -1, MISSION_PART, -1, 0}
};

struct FolderSelect unknown_folderselect_constructor = { 0x14, 0x14, 0x14 };
struct FolderSelect unknown_folderselect_constructor_0 = { 0x32, 0x32, 0x32 };


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
    {getStringID(LTITLE, TITLE_STR_271_STACK), getStringID(LTITLE, TITLE_STR_272_STACK2), IMG_MP_BASEMENT, LEVELID_STACK, -1, 1, 4},
    /* unlocked on level progression */
    {getStringID(LTITLE, TITLE_STR_164_FACMP), getStringID(LTITLE, TITLE_STR_165_FACMP22), IMG_MP_FACILITY, LEVELID_FACILITY, SP_LEVEL_FACILITY, 1, 4},
    {getStringID(LTITLE, TITLE_STR_166_SEVERNAYABUNKER), getStringID(LTITLE, TITLE_STR_167_BUNKER), IMG_MP_BUNKER2, LEVELID_BUNKER2, SP_LEVEL_BUNKER2, 1, 3},
    {getStringID(LTITLE, TITLE_STR_168_MILITARYARCHIVES), getStringID(LTITLE, TITLE_STR_169_ARCHIVES), IMG_MP_ARCHIVES, LEVELID_ARCHIVES, SP_LEVEL_ARCHIVES, 1, 3},
    {getStringID(LTITLE, TITLE_STR_170_WATERCAVERNS), getStringID(LTITLE, TITLE_STR_171_CAVERNS), IMG_MP_CAVERNS, LEVELID_CAVERNS, SP_LEVEL_CAVERNS, 1, 3},
    {getStringID(LTITLE, TITLE_STR_172_EGYPTIANTEMPLEMP), getStringID(LTITLE, TITLE_STR_173_EGYPTIANMP), IMG_MP_EGYPT, LEVELID_EGYPT, SP_LEVEL_EGYPT, 1, 2}
  //{getStringID(LTITLE, TITLE_STR_174_CITADEL), getStringID(LTITLE, TITLE_STR_175_CITADEL2), IMG_MP_RANDOM, LEVELID_CITADEL, -1, 1, 4}, //Citadel (old format setup)
  //{getStringID(LTITLE, TITLE_STR_176_DEST), getStringID(LTITLE, TITLE_STR_177_DEST2), IMG_MP_FRIGATE, LEVELID_FRIGATE, -1, 1, 4}, //dest (needs setup)
  //{getStringID(LTITLE, TITLE_STR_178_STAT), getStringID(LTITLE, TITLE_STR_179_STAT2), IMG_MP_STATUE, LEVELID_STATUE, -1, 1, 2}, //stat (works)
  //{getStringID(LTITLE, TITLE_STR_180_CRAD), getStringID(LTITLE, TITLE_STR_181_CRADLE2), IMG_MP_CRADLE, LEVELID_CRADLE, -1, 1, 2}, //crad (works)
  //{getStringID(LTITLE, TITLE_STR_182_AZT), getStringID(LTITLE, TITLE_STR_183_AZT2), IMG_MP_AZTEC, LEVELID_AZTEC, -1, 1, 4}, //azt (needs setup)

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
    {getStringID(LTITLE, TITLE_STR_290), MALE,   IMG_MPC_RANDOM, BODY_Russian_Commandant,       HEAD_Male_Martin, 1.0},
    {getStringID(LTITLE, TITLE_STR_291), MALE,   IMG_MPC_RANDOM, BODY_Janus_Marine,             HEAD_Male_Steve_Ellis, 1.0},
    {getStringID(LTITLE, TITLE_STR_292), MALE,   IMG_MPC_RANDOM, BODY_Naval_Officer,            HEAD_Male_Duncan, 1.0},
    {getStringID(LTITLE, TITLE_STR_293), MALE,   IMG_MPC_RANDOM, BODY_Helicopter_Pilot,         HEAD_Male_Pete, 1.0},
    {getStringID(LTITLE, TITLE_STR_294), MALE,   IMG_MPC_RANDOM, BODY_St_Petersburg_Guard,      HEAD_Male_Ken, 1.0},
    {getStringID(LTITLE, TITLE_STR_295), FEMALE, IMG_MPC_RANDOM, BODY_Civilian_1_Female,        HEAD_Female_Marion_Rosika, 1.0},
    {getStringID(LTITLE, TITLE_STR_295), MALE,   IMG_MPC_RANDOM, BODY_Civilian_2,               HEAD_Male_Graeme, 1.0},
    {getStringID(LTITLE, TITLE_STR_295), MALE,   IMG_MPC_RANDOM, BODY_Civilian_3,               HEAD_Male_Grant, 1.0},
    {getStringID(LTITLE, TITLE_STR_295), MALE,   IMG_MPC_RANDOM, BODY_Civilian_4,               HEAD_Male_Dwayne, 1.0},
    {getStringID(LTITLE, TITLE_STR_296), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_1_Mishkin, HEAD_Male_Lee, 1.0},
    {getStringID(LTITLE, TITLE_STR_297), MALE,   IMG_MPC_RANDOM, BODY_Arctic_Commando,          HEAD_Male_Chris, 1.0},
    {getStringID(LTITLE, TITLE_STR_296), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Guard_2,         HEAD_Male_Scott, 1.0},
    {getStringID(LTITLE, TITLE_STR_298), MALE,   IMG_MPC_RANDOM, BODY_Siberian_Special_Forces,  HEAD_Male_Alan, 1.0},
    {getStringID(LTITLE, TITLE_STR_299), MALE,   IMG_MPC_RANDOM, BODY_Jungle_Commando,          HEAD_Male_Joel, 1.0},
    {getStringID(LTITLE, TITLE_STR_300), MALE,   IMG_MPC_RANDOM, BODY_Janus_Special_Forces,     HEAD_Male_B, 1.0},
    {getStringID(LTITLE, TITLE_STR_301), MALE,   IMG_MPC_RANDOM, BODY_Moonraker_Elite_1_Male,   HEAD_Male_Neil, 1.0},
    {getStringID(LTITLE, TITLE_STR_301), FEMALE, IMG_MPC_RANDOM, BODY_Moonraker_Elite_2_Female, HEAD_Female_Vivien, 1.0},
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
    {0, 160, 0},
    {0, 0, 125},
    {300, 0, 0},
    {0, 210, 0},
    {0, 0, 240},
    {180, 0, 0},
    {0, 270, 0},
    {0, 0, 255},
    {90, 0, 0},
    {0, 195, 0},
    {0, 0, 80},
    {105, 0, 0},
    {0, 100, 0},
    {0, 0, 325},
    {225, 0, 0},
    {0, 600, 0},
    {0, 0, 570},
    {135, 0, 0},
    {0, 540, 0},
    {0, 0, 360}
};

s32 totalunlockedcheats = 0;
s32 D_8002B5E0 = 0;


u32 MP_menu_selected_option = 0;
s32 intro_character_index = 0;
u32 randomly_selected_intro_animation = ANIM_idle;
u32 intro_animation_count = 0;
struct Model *cast_model = NULL;
struct Model *cast_model_weapon = NULL;
u32 full_actor_intro = 0;

struct intro_char intro_char_table[] = {
    {BODY_Brosnan_Tuxedo, HEAD_Male_Brosnan_Tuxedo, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_228_THEACTORS), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Special_Operations_Uniform, HEAD_Male_Brosnan_Boiler, getStringID(LTITLE, TITLE_STR_229_STARRING), getStringID(LTITLE, TITLE_STR_232_007), getStringID(LTITLE, TITLE_STR_233_JAMESBOND), 0, 0},
    {BODY_Natalya_Skirt, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_229_STARRING), getStringID(LTITLE, TITLE_STR_234_NATALYASIMONOVA), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {BODY_Trevelyan_006, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_229_STARRING), getStringID(LTITLE, TITLE_STR_235_006), getStringID(LTITLE, TITLE_STR_236_ALECTREVELYAN), 0, 0},
    {BODY_Xenia, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_237_JANUSOPPERATIVE), getStringID(LTITLE, TITLE_STR_238_XENIAONPTOPP), 0, 0},
    {BODY_Ourumov, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_239_GENERAL), getStringID(LTITLE, TITLE_STR_240_ARKADYOURUMOV), 0, 0},
    {BODY_Boris, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_241_BORISGRISHENKO), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {BODY_Valentin_, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_242_EXKGBAGENT), getStringID(LTITLE, TITLE_STR_243_VELENTINZUKOVSKY), 0, 0},
    {BODY_Siberian_Guard_1_Mishkin, 0x45, getStringID(LTITLE, TITLE_STR_230_ALSOFEATURING), getStringID(LTITLE, TITLE_STR_244_DEFENSEMINISTER), getStringID(LTITLE, TITLE_STR_245_DIMITRIMISHKIN), 0, 0},
    {BODY_Russian_Soldier, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_253_RUSSIANSOLDIER), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Russian_Infantry, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_252_RUSSIANINFANTRY), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Scientist_1_Male, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_263_SCIENTIST), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Scientist_2_Female, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_263_SCIENTIST), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Russian_Commandant, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_256_RUSSIANCOMMANDANT), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Janus_Marine, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_254_JANUSMARINE), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Naval_Officer, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_257_NAVALOFFICER), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Helicopter_Pilot, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_262_HELICOPTERPILOT), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_St_Petersburg_Guard, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_251_STPETERSBURGGUARD), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Civilian_1_Female, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_264_CIVILIAN), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Civilian_2, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_264_CIVILIAN), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Civilian_3, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_264_CIVILIAN), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Civilian_4, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_264_CIVILIAN), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Siberian_Guard_1_Mishkin, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Arctic_Commando, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_259_ARCTICCOMMANDO), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Siberian_Guard_2, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_258_SIBERIANGUARD), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Siberian_Special_Forces, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_260_SIBERIANSPECIALFORCES), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Jungle_Commando, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_250_JUNGLECOMMANDO), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Janus_Special_Forces, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_255_JANUSSPECIALFORCES), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Moonraker_Elite_1_Male, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Moonraker_Elite_2_Female, 0xFFFFFF9F, getStringID(LTITLE, TITLE_STR_227_LF), getStringID(LTITLE, TITLE_STR_261_MOOKRAKERELITE), getStringID(LTITLE, TITLE_STR_227_LF), 0, 1},
    {BODY_Mayday, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_231_GUESTSTAR), getStringID(LTITLE, TITLE_STR_246_MAYDAY), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {BODY_Jaws, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_231_GUESTSTAR), getStringID(LTITLE, TITLE_STR_247_JAWS), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {BODY_Oddjob, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_231_GUESTSTAR), getStringID(LTITLE, TITLE_STR_248_ODDJOB), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {BODY_Baron_Samedi, 0xFFFFFFFF, getStringID(LTITLE, TITLE_STR_231_GUESTSTAR), getStringID(LTITLE, TITLE_STR_249_BERONSAMEDI), getStringID(LTITLE, TITLE_STR_227_LF), 0, 0},
    {0xFFFFFFFF, 0, 0, 0, 0, 0, 0}
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

struct coord3d D_8002BA2C = { 0 };

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


struct coord3d D_8002BA78 = { 0.0f, 0.0f, 1.0f };
struct coord3d D_8002BA84 = { 0.0f, 0.0f, 0.0f };
struct coord3d D_8002BA90 = { 0.0f, 1.0f, 0.0f };

ModelRenderData D_8002BA9C = {NULL,
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


struct coord3d D_8002BADC = { 0.0f, 40.0f, 25.0f };

u32 D_8002BAE8 = 0;
u32 D_8002BAEC = 1;

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
        gdl = textRenderGlow(
            gdl,
            x,
            y,
            text,
            second_font_table,
            first_font_table,
            arg6,
            (D_8002A9B0.r << 0x18) | (D_8002A9B4.r << 0x10) | (D_8002A9B8.r << 8) | D_8002A9BC.r,
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
            do {
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

    logoinst = get_obj_instance_controller_for_header(PitemZ_entries[PROP_LEGALPAGE].header);
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





#ifdef NONMATCHING
/**
 * https://decomp.me/scratch/hx7ye 99.27%
 *
 * decomp notes:
 * compiles: yes
 * stack resize: match
 * instructions match: yes
 * resgisters match: false
 *
 * decomp notes: match down to regalloc in final loop.
 */
Gfx *constructor_menu00_legalscreen(Gfx *DL)
{
    s32 padding;
    ModelRenderData spE4;
    Mtxf *temp;
    Mtxf spA0;
    s32 i;
    u8 *txt;
    Mtxf sp58;
    struct legal_screen_text *legal_text_ptr;

    spE4 = D_8002AABC;

    DL = insert_imageDL(DL);
    matrix_4x4_7F059694(&spA0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    spE4.unk_matrix = &spA0;
    spE4.mtxlist = (Mtxf*)dynAllocate(logoinst->obj->numMatrices << 6);
    matrix_4x4_copy(&spA0, spE4.mtxlist);
    logoinst->render_pos = spE4.mtxlist;
    sub_GAME_7F06EFC4(logoinst);
    spE4.unk08 = 3;
    spE4.unk04 = 0;
    spE4.gdl = DL;
    subdraw(&spE4, logoinst);
    DL = spE4.gdl;

    for (i=0; i<logoinst->obj->numMatrices; i++)
    {
        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)logoinst->render_pos)[i*0x40], &sp58);
        matrix_4x4_f32_to_s32(&sp58, &((Mtxf*)logoinst->render_pos)[i]);
    }

    DL = microcode_constructor(DL);

    for (legal_text_ptr = &legalpage_text_array[0]; legal_text_ptr < &legalpage_text_array[12]; legal_text_ptr++)
    {
        txt = langGet(legal_text_ptr->txtID);

        DL = display_aligned_white_text_to_screen(
            DL,
            legal_text_ptr->h_pos,
            legal_text_ptr->v_pos,
            legal_text_ptr->halign,
            legal_text_ptr->valign,
            txt,
            ptrFontZurichBoldChars,
            ptrFontZurichBold);

    }

    return DL;
}
#else
GLOBAL_ASM(
.text
glabel constructor_menu00_legalscreen
/* 03F410 7F00A8E0 27BDFED8 */  addiu $sp, $sp, -0x128
/* 03F414 7F00A8E4 AFB10034 */  sw    $s1, 0x34($sp)
/* 03F418 7F00A8E8 3C0E8003 */  lui   $t6, %hi(D_8002AABC)
/* 03F41C 7F00A8EC 27B100E4 */  addiu $s1, $sp, 0xe4
/* 03F420 7F00A8F0 AFB40040 */  sw    $s4, 0x40($sp)
/* 03F424 7F00A8F4 25CEAABC */  addiu $t6, %lo(D_8002AABC) # addiu $t6, $t6, -0x5544
/* 03F428 7F00A8F8 0080A025 */  move  $s4, $a0
/* 03F42C 7F00A8FC AFBF0044 */  sw    $ra, 0x44($sp)
/* 03F430 7F00A900 AFB3003C */  sw    $s3, 0x3c($sp)
/* 03F434 7F00A904 AFB20038 */  sw    $s2, 0x38($sp)
/* 03F438 7F00A908 AFB00030 */  sw    $s0, 0x30($sp)
/* 03F43C 7F00A90C 25D9003C */  addiu $t9, $t6, 0x3c
/* 03F440 7F00A910 02204025 */  move  $t0, $s1
.L7F00A914:
/* 03F444 7F00A914 8DC10000 */  lw    $at, ($t6)
/* 03F448 7F00A918 25CE000C */  addiu $t6, $t6, 0xc
/* 03F44C 7F00A91C 2508000C */  addiu $t0, $t0, 0xc
/* 03F450 7F00A920 AD01FFF4 */  sw    $at, -0xc($t0)
/* 03F454 7F00A924 8DC1FFF8 */  lw    $at, -8($t6)
/* 03F458 7F00A928 AD01FFF8 */  sw    $at, -8($t0)
/* 03F45C 7F00A92C 8DC1FFFC */  lw    $at, -4($t6)
/* 03F460 7F00A930 15D9FFF8 */  bne   $t6, $t9, .L7F00A914
/* 03F464 7F00A934 AD01FFFC */   sw    $at, -4($t0)
/* 03F468 7F00A938 8DC10000 */  lw    $at, ($t6)
/* 03F46C 7F00A93C 02802025 */  move  $a0, $s4
/* 03F470 7F00A940 0FC07034 */  jal   insert_imageDL
/* 03F474 7F00A944 AD010000 */   sw    $at, ($t0)
/* 03F478 7F00A948 44800000 */  mtc1  $zero, $f0
/* 03F47C 7F00A94C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03F480 7F00A950 44812000 */  mtc1  $at, $f4
/* 03F484 7F00A954 27B000A0 */  addiu $s0, $sp, 0xa0
/* 03F488 7F00A958 44050000 */  mfc1  $a1, $f0
/* 03F48C 7F00A95C 44060000 */  mfc1  $a2, $f0
/* 03F490 7F00A960 0040A025 */  move  $s4, $v0
/* 03F494 7F00A964 02002025 */  move  $a0, $s0
/* 03F498 7F00A968 3C07457A */  lui   $a3, 0x457a
/* 03F49C 7F00A96C E7A00010 */  swc1  $f0, 0x10($sp)
/* 03F4A0 7F00A970 E7A00014 */  swc1  $f0, 0x14($sp)
/* 03F4A4 7F00A974 E7A00018 */  swc1  $f0, 0x18($sp)
/* 03F4A8 7F00A978 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 03F4AC 7F00A97C E7A00024 */  swc1  $f0, 0x24($sp)
/* 03F4B0 7F00A980 0FC165A5 */  jal   matrix_4x4_7F059694
/* 03F4B4 7F00A984 E7A40020 */   swc1  $f4, 0x20($sp)
/* 03F4B8 7F00A988 3C138003 */  lui   $s3, %hi(logoinst)
/* 03F4BC 7F00A98C 2673A958 */  addiu $s3, %lo(logoinst) # addiu $s3, $s3, -0x56a8
/* 03F4C0 7F00A990 8E690000 */  lw    $t1, ($s3)
/* 03F4C4 7F00A994 AFB000E4 */  sw    $s0, 0xe4($sp)
/* 03F4C8 7F00A998 8D2A0008 */  lw    $t2, 8($t1)
/* 03F4CC 7F00A99C 8544000E */  lh    $a0, 0xe($t2)
/* 03F4D0 7F00A9A0 00045980 */  sll   $t3, $a0, 6
/* 03F4D4 7F00A9A4 0FC2F5C5 */  jal   dynAllocate
/* 03F4D8 7F00A9A8 01602025 */   move  $a0, $t3
/* 03F4DC 7F00A9AC AFA200F4 */  sw    $v0, 0xf4($sp)
/* 03F4E0 7F00A9B0 02002025 */  move  $a0, $s0
/* 03F4E4 7F00A9B4 0FC16008 */  jal   matrix_4x4_copy
/* 03F4E8 7F00A9B8 00402825 */   move  $a1, $v0
/* 03F4EC 7F00A9BC 8FAC00F4 */  lw    $t4, 0xf4($sp)
/* 03F4F0 7F00A9C0 8E6D0000 */  lw    $t5, ($s3)
/* 03F4F4 7F00A9C4 ADAC000C */  sw    $t4, 0xc($t5)
/* 03F4F8 7F00A9C8 0FC1BBF1 */  jal   sub_GAME_7F06EFC4
/* 03F4FC 7F00A9CC 8E640000 */   lw    $a0, ($s3)
/* 03F500 7F00A9D0 24180003 */  li    $t8, 3
/* 03F504 7F00A9D4 AFB800EC */  sw    $t8, 0xec($sp)
/* 03F508 7F00A9D8 AFA000E8 */  sw    $zero, 0xe8($sp)
/* 03F50C 7F00A9DC AFB400F0 */  sw    $s4, 0xf0($sp)
/* 03F510 7F00A9E0 02202025 */  move  $a0, $s1
/* 03F514 7F00A9E4 0FC1D1A1 */  jal   subdraw
/* 03F518 7F00A9E8 8E650000 */   lw    $a1, ($s3)
/* 03F51C 7F00A9EC 8E620000 */  lw    $v0, ($s3)
/* 03F520 7F00A9F0 8FB400F0 */  lw    $s4, 0xf0($sp)
/* 03F524 7F00A9F4 00008025 */  move  $s0, $zero
/* 03F528 7F00A9F8 8C4F0008 */  lw    $t7, 8($v0)
/* 03F52C 7F00A9FC 00008825 */  move  $s1, $zero
/* 03F530 7F00AA00 27B20058 */  addiu $s2, $sp, 0x58
/* 03F534 7F00AA04 85F9000E */  lh    $t9, 0xe($t7)
/* 03F538 7F00AA08 1B200013 */  blez  $t9, .L7F00AA58
/* 03F53C 7F00AA0C 00000000 */   nop
/* 03F540 7F00AA10 8C4E000C */  lw    $t6, 0xc($v0)
.L7F00AA14:
/* 03F544 7F00AA14 02402825 */  move  $a1, $s2
/* 03F548 7F00AA18 0FC16008 */  jal   matrix_4x4_copy
/* 03F54C 7F00AA1C 01D12021 */   addu  $a0, $t6, $s1
/* 03F550 7F00AA20 8E680000 */  lw    $t0, ($s3)
/* 03F554 7F00AA24 00105180 */  sll   $t2, $s0, 6
/* 03F558 7F00AA28 02402025 */  move  $a0, $s2
/* 03F55C 7F00AA2C 8D09000C */  lw    $t1, 0xc($t0)
/* 03F560 7F00AA30 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 03F564 7F00AA34 012A2821 */   addu  $a1, $t1, $t2
/* 03F568 7F00AA38 8E620000 */  lw    $v0, ($s3)
/* 03F56C 7F00AA3C 26100001 */  addiu $s0, $s0, 1
/* 03F570 7F00AA40 26310040 */  addiu $s1, $s1, 0x40
/* 03F574 7F00AA44 8C4B0008 */  lw    $t3, 8($v0)
/* 03F578 7F00AA48 856C000E */  lh    $t4, 0xe($t3)
/* 03F57C 7F00AA4C 020C082A */  slt   $at, $s0, $t4
/* 03F580 7F00AA50 5420FFF0 */  bnezl $at, .L7F00AA14
/* 03F584 7F00AA54 8C4E000C */   lw    $t6, 0xc($v0)
.L7F00AA58:
/* 03F588 7F00AA58 0FC2B366 */  jal   microcode_constructor
/* 03F58C 7F00AA5C 02802025 */   move  $a0, $s4
/* 03F590 7F00AA60 3C108003 */  lui   $s0, %hi(legalpage_text_array)
/* 03F594 7F00AA64 3C118003 */  lui   $s1, %hi(D_8002AABC)
/* 03F598 7F00AA68 3C138004 */  lui   $s3, %hi(ptrFontZurichBold)
/* 03F59C 7F00AA6C 3C128004 */  lui   $s2, %hi(ptrFontZurichBoldChars)
/* 03F5A0 7F00AA70 0040A025 */  move  $s4, $v0
/* 03F5A4 7F00AA74 2610A9CC */  addiu $s0, %lo(legalpage_text_array) # addiu $s0, $s0, -0x5634
/* 03F5A8 7F00AA78 2631AABC */  addiu $s1, %lo(D_8002AABC) # addiu $s1, $s1, -0x5544
/* 03F5AC 7F00AA7C 26520EB8 */  addiu $s2, %lo(ptrFontZurichBoldChars) # addiu $s2, $s2, 0xeb8
/* 03F5B0 7F00AA80 26730EB4 */  addiu $s3, %lo(ptrFontZurichBold) # addiu $s3, $s3, 0xeb4
.L7F00AA84:
/* 03F5B4 7F00AA84 0FC30776 */  jal   langGet
/* 03F5B8 7F00AA88 96040010 */   lhu   $a0, 0x10($s0)
/* 03F5BC 7F00AA8C 8E0D000C */  lw    $t5, 0xc($s0)
/* 03F5C0 7F00AA90 8E050000 */  lw    $a1, ($s0)
/* 03F5C4 7F00AA94 8E060004 */  lw    $a2, 4($s0)
/* 03F5C8 7F00AA98 8E070008 */  lw    $a3, 8($s0)
/* 03F5CC 7F00AA9C 8E580000 */  lw    $t8, ($s2)
/* 03F5D0 7F00AAA0 8E6F0000 */  lw    $t7, ($s3)
/* 03F5D4 7F00AAA4 AFA20014 */  sw    $v0, 0x14($sp)
/* 03F5D8 7F00AAA8 02802025 */  move  $a0, $s4
/* 03F5DC 7F00AAAC AFAD0010 */  sw    $t5, 0x10($sp)
/* 03F5E0 7F00AAB0 AFB80018 */  sw    $t8, 0x18($sp)
/* 03F5E4 7F00AAB4 0FC029F9 */  jal   display_aligned_white_text_to_screen
/* 03F5E8 7F00AAB8 AFAF001C */   sw    $t7, 0x1c($sp)
/* 03F5EC 7F00AABC 26100014 */  addiu $s0, $s0, 0x14
/* 03F5F0 7F00AAC0 0211082B */  sltu  $at, $s0, $s1
/* 03F5F4 7F00AAC4 1420FFEF */  bnez  $at, .L7F00AA84
/* 03F5F8 7F00AAC8 0040A025 */   move  $s4, $v0
/* 03F5FC 7F00AACC 8FBF0044 */  lw    $ra, 0x44($sp)
/* 03F600 7F00AAD0 8FB00030 */  lw    $s0, 0x30($sp)
/* 03F604 7F00AAD4 8FB10034 */  lw    $s1, 0x34($sp)
/* 03F608 7F00AAD8 8FB20038 */  lw    $s2, 0x38($sp)
/* 03F60C 7F00AADC 8FB3003C */  lw    $s3, 0x3c($sp)
/* 03F610 7F00AAE0 8FB40040 */  lw    $s4, 0x40($sp)
/* 03F614 7F00AAE4 03E00008 */  jr    $ra
/* 03F618 7F00AAE8 27BD0128 */   addiu $sp, $sp, 0x128
)
#endif



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
    return insert_imageDL(DL);
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
    logoinst = get_obj_instance_controller_for_header(PitemZ_entries[PROP_NINTENDOLOGO].header);
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
    ModelRenderData sp128;
    s32 padding;
    s32 var_v1;
    Mtxf spE0;
    s32 i;

    sp128 = D_8002AB08;

    DL = insert_imageDL(DL);

    // Lights macro? These need to be on one line.
    gSPNumLights(DL++, 1); \
    gSPLight(DL++, &ninlogolight.l[0], 1); \
    gSPLight(DL++, &ninlogolight, 2);

#if defined(VERSION_EU)
    // 0x100000000 ? 0xFFFECD34 = 0x132CC (78540 decimal)
    var_v1 = 0xFF - ((s32) ((g_MenuTimer * 0xFF) + 0xFFFECD34) / 83);
#else
    // 0x100000000 ? 0xFFFE8F72 = 0x1708E (94350 decimal)
    var_v1 = 0xFF - ((s32) ((g_MenuTimer * 0xFF) + 0xFFFE8F72) / 100);
#endif
    if (var_v1 >= 0x100)
    {
        var_v1 = 0xff;
    }
    if (var_v1 < 0)
    {
        var_v1 = 0;
    }

    ninlogolight.a.l.colc[2] = var_v1;
    ninlogolight.a.l.colc[1] = var_v1;
    ninlogolight.a.l.colc[0] = var_v1;
    ninlogolight.a.l.col[2] = var_v1;
    ninlogolight.a.l.col[1] = var_v1;
    ninlogolight.a.l.col[0] = var_v1;

#if defined(VERSION_EU)
    ninLogoRotRate += 0.0209439527243f;
#else
    ninLogoRotRate += 0.017453292f;
#endif

    // Not sure if this is actually an `if` block, but the sp90 variable
    // needs to be declared here for the stack to match.
    if(1)
    {
        Mtxf sp90;

        matrix_4x4_set_rotation_around_y(ninLogoRotRate, &sp90);
        matrix_scalar_multiply_3(ninLogoScale, (f32*)&sp90);

#if defined(VERSION_EU)
        ninLogoScale *= 1.09647190571f;
#else
        ninLogoScale *= 1.07977f;
#endif
        if (ninLogoScale > 1.1f)
        {
            ninLogoScale = 1.1f;
        }

        matrix_4x4_7F059694(&spE0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        matrix_4x4_multiply_in_place(&spE0, &sp90);
        matrix_4x4_copy(&sp90, &spE0);
    }

    sp128.unk_matrix = &spE0;

    sp128.mtxlist = dynAllocate(logoinst->obj->numMatrices << 6);

    matrix_4x4_copy(&spE0, sp128.mtxlist);

    logoinst->render_pos = (union RenderPosView*)sp128.mtxlist;

    sub_GAME_7F06EFC4(logoinst);

    sp128.flags = 3;
    sp128.zbufferenabled = FALSE;
    sp128.gdl = DL;

    subdraw(&sp128, logoinst);

    DL = sp128.gdl;

    for (i=0; i<logoinst->obj->numMatrices; i++)
    {
        Mtxf sp50;
        s32 padding2;

        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)logoinst->render_pos)[i*0x40], &sp50);
        matrix_4x4_f32_to_s32(&sp50, &((Mtxf*)logoinst->render_pos)[i]);

        if(i);
    }

    return DL;
}












//********************************************************************************************************
//RARE LOGO
//********************************************************************************************************
void init_menu02_rarelogo(void)
{
    sub_GAME_7F008B58(ptr_logo_and_walletbond_DL, 0x78000);
    sndPlaySfx(g_musicSfxBufferPtr, RARELOGO_SFX, 0);
}

void update_menu02_rareware(void) {
    return;
}

void interface_menu02_rareware(void)
{
    viSetUseZBuf(0);
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
void init_menu03_eyeintro(void) {
    initializeGunBarrelIntro(ptr_logo_and_walletbond_DL, 0x78000);
    musicTrack1Play(M_INTRO);
    maybe_is_in_menu = TRUE;
}

void update_menu_03_eye(void) {
    sub_GAME_7F00920C();
}

void interface_menu03_eye(void) {
    viSetUseZBuf(0);
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
    return sub_GAME_7F009254(DL);
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
    logoinst = get_obj_instance_controller_for_header(PitemZ_entries[PROP_GOLDENEYELOGO].header);
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
    ModelRenderData sp140;
    s32 padding[2];
    Mtxf spF8;
    s32 i;
    LookAt * temp_v0;
    Mtxf spB0;

    sp140 = D_8002AB54;

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);

    temp_v0 = (LookAt *)dynAllocate7F0BD6F8(2);
    guLookAtReflect(&spB0, temp_v0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Lights macro? These need to be on one line.
    gSPNumLights(DL++, 1); \
    gSPLight(DL++, &gelogolight.l[0], 1); \
    gSPLight(DL++, &gelogolight, 2);

    // gSPLookAt macro expands to gSPLookAtX + gSPLookAtY
    gSPLookAt(DL++, temp_v0);

    matrix_4x4_7F059694(&spF8, 0.0f, 0.0f, 3000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    sp140.unk_matrix = &spF8;
    sp140.mtxlist = dynAllocate(logoinst->obj->numMatrices << 6);

    matrix_scalar_multiply(1.2f, spF8.m[0]);
    matrix_4x4_copy(&spF8, sp140.mtxlist);
    logoinst->render_pos = (union RenderPosView*)sp140.mtxlist;

    sub_GAME_7F06EFC4(logoinst);

    sp140.flags = 3;
    sp140.zbufferenabled = FALSE;
    sp140.gdl = DL;

    subdraw(&sp140, logoinst);

    DL = sp140.gdl;

    for (i=0; i<logoinst->obj->numMatrices; i++)
    {
        Mtxf sp50;
        s32 padding2;

        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)logoinst->render_pos)[i*0x40], &sp50);
        matrix_4x4_f32_to_s32(&sp50, &((Mtxf*)logoinst->render_pos)[i]);

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

        if (mnode != NULL && (mnode->Opcode & 0xff) == 0x12)
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
        struct ModelRoData_HeaderRecord *node = modelGetNodeRwData(objinstance, objinstance->obj->Switches[item]);
        node->ModelType = mode;
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



struct unk_walletbond_struct {
    s32 Primary;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 BaseAddr;
};


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
            walletinst[i]  = get_aircraft_obj_instance_controller(PitemZ_entries[PROP_WALLETBOND].header);
            #ifdef DEBUG
            assert(walletinst[i]);
            #endif
            modelSetScale(walletinst[i], 1.0f);
        }

        mnode = PitemZ_entries[PROP_WALLETBOND].header->Switches[GFXHIT0_PICS];

        if (mnode != NULL)
        {
            struct unk_walletbond_struct *srecord;
            struct ModelNode *b;
            Gfx *arg0;

            b = (struct ModelNode *)mnode;
            srecord = b->Data;

            arg0 = (s32)srecord->BaseAddr + (srecord->Primary & 0xffffff);
            bgLoadFromDynamicCCRMLUT(arg0, NULL, CCRMLUT_WALLETBOND);
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
    s32 sp24 = 0x6e000;
    Gfx* sp20 = (s32)(ptr_logo_and_walletbond_DL) + (s32)(4096*10);
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
    sub_GAME_7F008DE4(&sp20, &sp24);
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

  transform3Dto2DCoords(&dword_CODE_bss_80069620[index],&local_8);
  cursor_h_pos = local_8.x + -1.0f;
  cursor_v_pos = local_8.y + 20.0f;
}






// address 0x7F00BBCC NTSC
s32 interface_menu05_fileselect(void)
{
    s32 i1;
    s32 i2;
    Mtxf spC8;
    Mtxf sp88;
    struct coord3d *sp54;

    if (((((joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON) != 0) || (joyGetStickX(0) < -5)) || (joyGetStickX(0) >= 6)) || (joyGetStickY(0) < -5)) || (joyGetStickY(0) >= 6))
    {
        g_MenuTimer = 0;
    }
    else
    {
        g_MenuTimer += g_ClockTimer;
    }

    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    for (i1 = 0; i1 < 4; i1++)
    {
        sp54 = &D_8002AB94[i1];

        matrix_4x4_7F059694(&spC8, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        matrix_4x4_set_identity_and_position(sp54, &sp88);
        matrix_scalar_multiply(0.37f, (f32*)&sp88);
        matrix_4x4_multiply_in_place(&spC8, &sp88);

        walletinst[i1]->render_pos = dynAllocate(walletinst[i1]->obj->numMatrices << 6);
        matrix_4x4_copy(&sp88, &walletinst[i1]->render_pos->pos);

        dword_CODE_bss_80069620[i1].f[0] = walletinst[i1]->render_pos->pos.m[3][0];
        dword_CODE_bss_80069620[i1].f[1] = walletinst[i1]->render_pos->pos.m[3][1];
        dword_CODE_bss_80069620[i1].f[2] = walletinst[i1]->render_pos->pos.m[3][2];

        disable_all_switches(walletinst[i1]);

        select_load_bond_picture(walletinst[i1], fileGetBondForFolder(i1));
        set_item_visibility_in_objinstance(walletinst[i1], 0xE, 1);
        set_item_visibility_in_objinstance(walletinst[i1], 0xD, 1);
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
        if ((joyGetButtonsPressedThisFrame(0, 0x222U) != 0) && (folder_selected_for_deletion_choice == 0))
        {
            folder_selected_for_deletion_choice = 1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
        }
        else if ((joyGetButtonsPressedThisFrame(0, 0x111U) != 0) && (folder_selected_for_deletion_choice != 0))
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
        if (joyGetButtonsPressedThisFrame(0, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
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
        else if (joyGetButtonsPressedThisFrame(0, B_BUTTON) != 0)
        {
            toggle_deletion_menu_for_folder(folder_selected_for_deletion);
            folder_selected_for_deletion = -1;
            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, GUN_M60AMMGUN_3_SFX, NULL);
        }
    }
    else
    {
        for (i2 = FOLDER1; i2 < MAX_FOLDER_COUNT; i2++)
        {
            f32 sp80;
            f32 sp7C;
            f32 sp78;
            f32 sp74;

            struct rectbbox sp64;

            LEVEL_SOLO_SEQUENCE sp60;
            DIFFICULTY sp5C;

            sub_GAME_7F03F90C(walletinst[i2], &sp80, &sp7C, &sp78, &sp74);
            sub_GAME_7F03F948(&dword_CODE_bss_80069620[i2], &sp7C, &sp74, &sp64.right, &sp64.left);

            if ((sp64.right <= cursor_h_pos)
                && (cursor_h_pos <= sp64.left)
                && (sp64.down <= cursor_v_pos)
                && (cursor_v_pos <= sp64.up))
            {
                fileGetHighestStageDifficultyCompletedForFolder(i2, &sp60, &sp5C);

                if (joyGetButtonsPressedThisFrame(0, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
                {
                    if (folder_selection_screen_option_icon == 0)
                    {
                        selected_folder_num = i2;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, PAPER_TURN_SFX, NULL);
                    }
                    else if (folder_selection_screen_option_icon == 1)
                    {
                        fileCopyFolderToFirstFree(i2);
                        folder_selection_screen_option_icon = 0;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, COPY_FILE_SFX, NULL);
                    }
                    else if (folder_selection_screen_option_icon == 2)
                    {
                        if ((sp60 >= SP_LEVEL_DAM) && (sp5C >= DIFFICULTY_AGENT))
                        {
                            folder_selected_for_deletion = i2;
                            folder_selected_for_deletion_choice = 1;
                        }

                        folder_selection_screen_option_icon = 0;
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, OPTION_CLICK2_SFX, NULL);
                    }

                    break;
                }
            }
        }

        if (joyGetButtonsPressedThisFrame(0, A_BUTTON | Z_TRIG | START_BUTTON) != 0)
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
        else if ((joyGetButtonsPressedThisFrame(0, B_BUTTON) != 0)
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




// Warning: The declaration of spD0 is likely incorrect, if this if this function is modified
// make sure to extend spD0 to avoid overflow.
Gfx *constructor_menu05_fileselect(Gfx *DL)
{
    s32 sp1B4;
    struct FolderSelect sp1A8;
    struct FolderSelect sp19C;
    s32 j;
    s32 i;
    u8 *langp;
    s32 var_s2_2;
    ModelRenderData sp14C;
    s32 var_s1_2;
    Mtxf sp108;
    f32 temp_f4;
    struct point2d spFC;
    struct point2d spF4;
    LEVEL_SOLO_SEQUENCE spF0;
    DIFFICULTY spEC;
    struct coord2d spE4;

    sp1A8 = unknown_folderselect_constructor;
    sp19C = unknown_folderselect_constructor_0;

    DL = insert_imageDL(DL);

    gDPSetCombineLERP(DL++, TEXEL0, PRIMITIVE, ENV_ALPHA, PRIMITIVE, 0, 0, 0, PRIMITIVE, TEXEL0, PRIMITIVE, ENV_ALPHA, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetEnvColor(DL++, 0xFF, 0xFF, 0xFF, 0x14);

    DL = sub_GAME_7F007CC8(DL, (s32) floorFloat(((f32) viGetX() * -80.0f) / 1280.0f), &sp1A8, &sp19C);

    gSPDisplayList(DL++, &dlBasicGeometry);
    gSPDisplayList(DL++, &dlFastPipelineSetup);

    for (j = 3; j >= 0; j--)
    {
        // struct copy
        sp14C = unknown_folderselect;

        sp14C.flags = 3;
        sp14C.zbufferenabled = FALSE;
        sp14C.gdl = DL;

        subdraw(&sp14C, walletinst[j]);

        DL = sp14C.gdl;

        for (i=0; i < walletinst[j]->obj->numMatrices; i++)
        {
            // hack: source address steps by sizeof(Mtxf), but can't get that to match
            matrix_4x4_copy(
                (Mtxf*)&((s8*)walletinst[j]->render_pos)[i*0x40],
                &sp108);

            matrix_4x4_f32_to_s32(&sp108, &((Mtxf*)walletinst[j]->render_pos)[i]);

        }
    }

    DL = microcode_constructor(DL);
    setTextSpacingInverted(0);

    for (sp1B4 = FOLDER1; sp1B4 < MAX_FOLDER_COUNT; sp1B4++)
    {
        // HACK:
        char spD0[4]; // this needs to be at least 14 characters.
        char spBC[18];
        s32 padding3;
        struct coord3d * sp74;

        sp74 = &dword_CODE_bss_80069620[sp1B4];

        transform3Dto2DCoords(sp74, &spE4);

        if (sp1B4 == folder_selected_for_deletion)
        {
            spFC.p[1] = (s32) floorFloat(spE4.f[0]) - 0x31;
            spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x19;

            DL = microcode_constructor_related_to_menus(DL, spFC.p[1], spFC.p[0], spFC.p[1] + 0x63, spFC.p[0] + 0x2A, 0x32);

            langp     = langGet(getStringID(LTITLE, TITLE_STR_23_ERASEFILE));
            spFC.p[1] = (s32) floorFloat(spE4.f[0]) - 0x2F;
            spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x1E;

            // 0xEBD879FF
            DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);

            langp     = langGet(getStringID(LTITLE, TITLE_STR_24_CANCEL));
            spFC.p[1] = (s32) floorFloat(spE4.f[0]) - 0x2F;
            spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x32;

            if (folder_selected_for_deletion_choice != 0)
            {
                spF4.p[0] = 0;
                spF4.p[1] = 0;
                textMeasure(&spF4.p[1], &spF4.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                DL = microcode_constructor_related_to_menus(DL, spFC.p[1] - 1, spFC.p[0] - 1, spF4.p[0] + spFC.p[1] + 3, spF4.p[1] + spFC.p[0], 0x32);
                DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
            }
            else
            {
                DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
            }

            langp = langGet(getStringID(LTITLE, TITLE_STR_25_CONFIRM));

            temp_f4 = floorFloat(spE4.f[0]);
            spFC.p[1] = (((j_text_trigger != 0) ? 0x17 : -1) + (s32) temp_f4) - 1;
            spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x32;

            if (folder_selected_for_deletion_choice != 0)
            {
                DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
            }
            else
            {
                spF4.p[0] = 0;
                spF4.p[1] = 0;
                textMeasure(&spF4.p[1], &spF4.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                DL = microcode_constructor_related_to_menus(DL, spFC.p[1] - 1, spFC.p[0] - 1, spF4.p[0] + spFC.p[1] + 3, spF4.p[1] + spFC.p[0], 0x32);
                DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
            }

        }
        else
        {

            fileGetHighestStageDifficultyCompletedForFolder(sp1B4, &spF0, &spEC);

            if ((spF0 >= SP_LEVEL_DAM) && (spEC >= DIFFICULTY_AGENT))
            {
                langp = get_ptr_difficulty_name(spEC);

                if (langp != NULL)
                {
                    strcpy((char *)&spD0, langp);
                    strcat((char *)&spD0, "\n");

                    spF4.p[0] = 0;
                    spF4.p[1] = 0;

                    textMeasure(&spF4.p[1], &spF4.p[0], (char *)&spD0, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                    spFC.p[1] = ((s32) floorFloat(spE4.f[0]) - (spF4.p[0] / 2)) - 1;
                    spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x15;
                    DL = textRender(DL, &spFC.p[1], &spFC.p[0], (char *)&spD0, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
                }

                if (spEC != DIFFICULTY_007)
                {
                    var_s2_2 = -1;

                    strcpy(spBC, langGet(getStringID(LTITLE, TITLE_STR_26_MISSION)));

                    for (var_s1_2 = 0; mission_folder_setup_entries[var_s1_2].folder_text_preset != 0; var_s1_2++)
                    {
                        if (spF0 == mission_folder_setup_entries[var_s1_2].mission_num)
                        {
                            var_s2_2 = get_chapter_briefing_entry(var_s1_2);
                            break;
                        }
                    }

                    if (var_s2_2 >= 0)
                    {
                        strcat((char *)spBC, (char *)mission_folder_setup_entries[var_s2_2].string_ptr);
                        strcat((char *)spBC, ".");
                    }

                    strcat((char *)spBC, (char *)mission_folder_setup_entries[var_s1_2].string_ptr);
                    strcat((char *)spBC, "\n");
                    spF4.p[0] = 0;
                    spF4.p[1] = 0;

                    textMeasure(&spF4.p[1], &spF4.p[0], (char *)spBC, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
                    spFC.p[1] = ((s32) floorFloat(spE4.f[0]) - (spF4.p[0] / 2)) - 1;
                    spFC.p[0] = (s32) floorFloat(spE4.f[1]) + 0x2D;

                    DL = textRender(DL, &spFC.p[1], &spFC.p[0], (char *)spBC, ptrFontZurichBoldChars, ptrFontZurichBold, 0xEBD879FF, viGetX(), viGetY(), 0, 0);
                }
            }
        }
    }

    if(1)
    {
        // The above for loops makes a lot of compiler temp variables on the stack,
        // These need to be declared sometime after the above for loop.
        struct coord2d spAC;
        struct coord2d spA4;
        struct coord2d sp9C;
        struct coord2d sp94;
        struct coord2d sp8C;
        struct coord2d sp84;

        setTextSpacingInverted(0);

        langp = langGet(getStringID(LTITLE, TITLE_STR_27_COPY));

        spF4.p[0] = 0;
        spF4.p[1] = 0;

        textMeasure(&spF4.p[1], &spF4.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        spFC.p[0] = 0x11D - (spF4.p[1] / 2);
        spFC.p[1] = 0xF7;

        DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
        folder_option_COPY_bound.right = (f32) (spF4.p[0] + spFC.p[1]);

        langp = langGet(getStringID(LTITLE, TITLE_STR_28_ERASE));

        spF4.p[0] = 0;
        spF4.p[1] = 0;

        textMeasure(&spF4.p[1], &spF4.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        spFC.p[1] = 0x165;
        spFC.p[0] = 0x11D - (spF4.p[1] / 2);

        DL = textRender(DL, &spFC.p[1], &spFC.p[0], langp, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);

        folder_option_ERASE_bound.right = (f32) (spF4.p[0] + spFC.p[1]);

        spAC.f[0] = 225.0f;
        spAC.f[1] = 285.0f;

        spA4.f[0] = (f32) (mainfolderimages + IMG_COPY)->width * 0.5f;
        spA4.f[1] = (f32) (mainfolderimages + IMG_COPY)->height * 0.5f;

        texSelect(&DL, mainfolderimages, 4, 0, 0);
        display_image_at_position(&DL, &spAC.f[0], &spA4.f[0], mainfolderimages->width, mainfolderimages->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) mainfolderimages->level > 0, 0);

        folder_option_COPY_bound.left = spAC.f[0] - spA4.f[0];
        folder_option_COPY_bound.up = spAC.f[1] - spA4.f[1];
        folder_option_COPY_bound.down = spAC.f[1] + spA4.f[1];

        sp9C.f[0] = 335.0f;
        sp9C.f[1] = 285.0f;

        sp94.f[0] = (mainfolderimages + IMG_DEL)->width * 0.5f;
        sp94.f[1] = (mainfolderimages + IMG_DEL)->height * 0.5f;

        texSelect(&DL, mainfolderimages + IMG_DEL, 4, 0, 0);
        display_image_at_position(&DL, &sp9C.f[0], &sp94.f[0], (mainfolderimages + IMG_DEL)->width, (mainfolderimages + IMG_DEL)->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) (mainfolderimages + IMG_DEL)->level > 0, 0);

        folder_option_ERASE_bound.left = (f32) (sp9C.f[0] - sp94.f[0]);
        folder_option_ERASE_bound.up = (f32) (sp9C.f[1] - sp94.f[1]);
        folder_option_ERASE_bound.down = (f32) (sp9C.f[1] + sp94.f[1]);

        sp8C.f[0] = 110.0f;
        sp8C.f[1] = 285.0f;

        sp84.f[0] = (mainfolderimages + IMG_SEL)->width * 0.5f;
        sp84.f[1] = (mainfolderimages + IMG_SEL)->height * 0.5f;

        texSelect(&DL, mainfolderimages + IMG_SEL, 4, 0, 0);
        display_image_at_position(&DL, &sp8C.f[0], &sp84.f[0], (mainfolderimages + IMG_SEL)->width, (mainfolderimages + IMG_SEL)->height, 0, 0, 1, 0xFF, 0xFF, 0xFF, 0xFF, (s32) (mainfolderimages + IMG_SEL)->level > 0, 0);
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

void update_menu06_modesel(void) {
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

    temp_f0 = D_8002AB94[selected_folder_num].f[0];
    temp_f2 = D_8002AB94[selected_folder_num].f[1];

    sp10C = D_8002AF84;

    temp_f0 += D_8002AFC4;
    temp_f2 += D_8002AFC8;

    matrix_4x4_7F059694(&spC8, temp_f0, temp_f2, 4000.0f + D_8002AFCC, temp_f0, temp_f2, 0.0f, 0.0f, 1.0f, 0.0f);
    matrix_4x4_set_identity_and_position(&D_8002AB94[selected_folder_num], &sp88);
    matrix_scalar_multiply(0.25f, sp88.m[0]);
    matrix_4x4_multiply_in_place(&spC8, &sp88);

    sp10C.unk_matrix = &sp88;

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
        num = 2;
        if (fileIs007ModeUnlocked(selected_folder_num) || get_debug_007_unlock_flag())
        {
            num = 3;
        }

        for (difficulty=num; difficulty >= 0; difficulty--)
        {
            temp_v0 = fileIsStageUnlockedAtDifficulty(selected_folder_num, arg0, difficulty);
            if (g_AppendCheatSinglePlayer == 0)
            {
                if (temp_v0 != 0)
                {
                    return difficulty;
                }
            }
            else if (temp_v0 == 3)
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

void update_menu07_missionsel(void) {
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

    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
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
        temp_s1->Vertices = dynAllocate7F0BD6C4(temp_s4->numVertices);

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
    highlight_enemy_accuracy = 0;
    highlight_enemy_damage = 0;
    load_walletbond();
}

void update_menu09_007options(void) {
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
        highlight_enemy_accuracy = FALSE;
        highlight_enemy_damage = FALSE;
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
                highlight_enemy_damage = TRUE;
            }
            else if (temp_y >= 0xC5)
            {
                highlight_enemy_accuracy = TRUE;
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
        else if (highlight_enemy_accuracy)
        {
            slider_007_mode_accuracy = (f32) (temp_x * temp_x * 10.0f);
        }
        else if (highlight_enemy_damage)
        {
            slider_007_mode_damage = (f32) (temp_x * temp_x * 10.0f);
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

Gfx *constructor_menu09_007options(Gfx *DL)
{
    u8 *spC14;
    s32 spC10;
    s32 spC0C;
    struct MatchHack_front_rodata_3000 sp54;
    s32 sp50;
    s32 sp4C;
    s32 val;

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
#if defined(VERSION_EU)
    DL = viFillScreen(DL);
    DL = viFillScreen(DL);
#endif
    DL = frontSetupMenuBackground(DL);

#if !defined(VERSION_EU)
    sp54 = asc_D_80050074;
#endif

    DL = microcode_constructor(DL);
    DL = print_current_solo_briefing_stage_name(DL, (char*)&sp54);

    spC14 = langGet(getStringID(LTITLE, TITLE_STR_40_SPECOPS));

    spC10 = 0x37;
    spC0C = 0x8f;

    DL = frontPrintText(DL, &spC10, &spC0C, (s8 *)spC14, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    spC14 = langGet(getStringID(LTITLE, TITLE_STR_42_HEALTH));

    spC10 = 0x39;
    spC0C = 0xA4;

    DL = microcode_constructor_related_to_menus(DL, 0x37, 0xB5, 0x163, 0xC0, 0x32);
    val = (sqrtf(slider_007_mode_health / 10.0f)) * 300.0f;
    DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C + 0x11, val + 0x37, spC0C + 0x1c, 0x64);

    if (highlight_enemy_health != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C - 1, 0xC7, spC0C + 0xE, 0x32);
    }

    DL = frontPrintText(DL, &spC10, &spC0C, (s8 *)spC14, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&sp54, "%d%%\n", (s32) (slider_007_mode_health * 100.0f));

    sp4C = 0;
    sp50 = 0;

    textMeasure(&sp50, &sp4C, (char*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    spC10 = 0x11D - sp4C;
    spC0C = 0xA4;

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    spC14 = langGet(getStringID(LTITLE, TITLE_STR_43_DAMAGE));

    spC10 = 0x39;
    spC0C = 0xC5;

    DL = microcode_constructor_related_to_menus(DL, 0x37, 0xD6, 0x163, 0xE1, 0x32);
    val = (sqrtf(slider_007_mode_accuracy / 10.0f)) * 300.0f;
    DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C + 0x11, val + 0x37, spC0C + 0x1c, 0x64);

    if (highlight_enemy_accuracy != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C - 1, 0xC7, spC0C + 0xE, 0x32);
    }

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)spC14, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&sp54, "%d%%\n", (s32) (slider_007_mode_accuracy * 100.0f));

    sp4C = 0;
    sp50 = 0;

    textMeasure(&sp50, &sp4C, (char*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    spC10 = 0x11D - sp4C;
    spC0C = 0xC5;

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    spC14 = langGet(getStringID(LTITLE, TITLE_STR_44_ACCURACY));

    spC10 = 0x39;
    spC0C = 0xE6;

    DL = microcode_constructor_related_to_menus(DL, 0x37, 0xF7, 0x163, 0x102, 0x32);
    val = (sqrtf(slider_007_mode_damage / 10.0f)) * 300.0f;
    DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C + 0x11, val + 0x37, spC0C + 0x1c, 0x64);

    if (highlight_enemy_damage != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C - 1, 0xC7, spC0C + 0xE, 0x32);
    }

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)spC14, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&sp54, "%d%%\n", (s32) (slider_007_mode_damage * 10.0f));

    sp4C = 0;
    sp50 = 0;

    textMeasure(&sp50, &sp4C, (char*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    spC10 = 0x11D - sp4C;
    spC0C = 0xE6;

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    spC14 = langGet(getStringID(LTITLE, TITLE_STR_41_REACTION));

    spC10 = 0x39;
    spC0C = 0x107;

    DL = microcode_constructor_related_to_menus(DL, 0x37, 0x118, 0x163, 0x123, 0x32);
    DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C + 0x11, (s32) (slider_007_mode_reaction * 300.0f * 1) + 0x37, spC0C + 0x1c, 0x64);

    if (highlight_enemy_reaction != 0)
    {
        DL = microcode_constructor_related_to_menus(DL, 0x37, spC0C - 1, 0xC7, spC0C + 0xE, 0x32);
    }

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)spC14, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

    sprintf((char*)&sp54, "%d%%\n", (s32) (slider_007_mode_reaction * 100.0f));

    sp4C = 0;
    sp50 = 0;

    textMeasure(&sp50, &sp4C, (char*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

    spC10 = 0x11D - sp4C;
    spC0C = 0x107;

    DL = frontPrintText(DL, &spC10, &spC0C, (s8*)&sp54, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);

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

u8 get_player_mp_char_gender(int player)
{
    if (player_char[player] < 0)
    {
        return mp_chr_setup[player].gender;
    }
    return mp_chr_setup[player_char[player]].gender;
}

u16 get_player_mp_char_body(int player)
{
    if (player_char[player] < 0)
    {
        return mp_chr_setup[player].body;
    }
    return mp_chr_setup[player_char[player]].body;
}

f32 get_player_mp_handicap(int player)
{
    return MP_handicap_table[player_handicap[player]].damage_modifier;
}

f32 get_player_mp_char_height(int player)
{
    if (player_char[player] < 0) {
        return mp_chr_setup[player].pov;
    }
    return mp_chr_setup[player_char[player]].pov;
}

int get_mp_timelimit(void) {
  return multi_game_lengths[game_length].time;
}

int get_mp_pointlimit(void) {
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
    s32 sp3C = 0;
    s32 sp38 = 0;
    s32 sp34 = 0;
    s32 sp30 = 0;
    s32 sp2C = 0;
    s32 sp28 = 0;
    s32 sp24 = 0;
    s32 sp20 = 0;
    s32 sp1C = 0;

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
            sp3C = 1;
        }
        else if (highlight_scenario)
        {
            sp38 = 1;
        }
        else if (highlight_gameselect)
        {
            sp34 = 1;
        }
        else if (highlight_gamelength)
        {
            sp30 = 1;
        }
        else if (highlight_character)
        {
            sp2C = 1;
        }
        else if (highlight_weaponselect)
        {
            sp28 = 1;
        }
        else if (highlight_health)
        {
            sp24 = 1;
        }
        else if (highlight_controlstyle)
        {
            sp20 = 1;
        }
        else if (highlight_aimadjustment)
        {
            sp1C = 1;
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

    if (sp3C)
    {
        s32 temp_v1;

        if (joyGetControllerCount() < selected_num_players + 1)
        {
            temp_v1 = 2;
        }
        else
        {
            temp_v1 = selected_num_players + 1;
        }

        init_mp_options_for_scenario(temp_v1);

        return;
    }
    if (sp38)
    {
        frontChangeMenu(MENU_MP_SCENARIO_SELECT, 0);
        return;
    }
    if (sp34)
    {
        frontChangeMenu(MENU_MP_STAGE_SELECT, 0);
        return;
    }
    if (sp30)
    {
        select_game_length();
        return;
    }
    if (sp2C)
    {
        frontChangeMenu(MENU_MP_CHAR_SELECT, 0);
        return;
    }
    if (sp28)
    {
        incrementMPWeaponSet();
        return;
    }
    if (sp24)
    {
        frontChangeMenu(MENU_MP_HANDICAP, 0);
        return;
    }
    if (sp20)
    {
        frontChangeMenu(MENU_MP_CONTROL_STYLE, 0);
        return;
    }
    if (sp1C)
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
        dword_CODE_bss_80069730[i] = 0;
        player_has_selected_char[i] = 0;
        size_mp_select_image_player[i] = 0;
    }

    load_walletbond();
}



//********************************************************************************************************
//MULTIPLAYER CHARACTER SELECT
//********************************************************************************************************
void update_menu0F_mpcharsel(void) {
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
    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
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
                if (dword_CODE_bss_80069730[i] == 0)
                {
                    if (mp_char_cur_select_player[i] < (num_chars_selectable_mp - 1))
                    {
                        mp_char_cur_select_player[i]++;
                    }
                }
            }
            else if ((joyGetStickXInRange(i, -2, 1) < -1) && (dword_CODE_bss_80069730[i] == 0))
            {
                if (mp_char_cur_select_player[i] > 0)
                {
                    mp_char_cur_select_player[i]--;
                }
            }
        }

        temp_v1_3 = (mp_char_prev_select_player[i] * 0x54) + dword_CODE_bss_80069730[i];

        if (mp_char_cur_select_player[i] * 0x54 < temp_v1_3)
        {
            dword_CODE_bss_80069730[i] -= 0xc;
            if (dword_CODE_bss_80069730[i] < 0)
            {
                dword_CODE_bss_80069730[i] += 0x54;
                mp_char_prev_select_player[i]--;
            }
        }
        else if (temp_v1_3 < mp_char_cur_select_player[i] * 0x54)
        {
            dword_CODE_bss_80069730[i] += 0xC;
            if (dword_CODE_bss_80069730[i] >= 0x54)
            {
                dword_CODE_bss_80069730[i] -= 0x54;
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
    spCC = dynAllocate7F0BD6C4(16);
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



#ifdef NONMATCHING
// https://decomp.me/scratch/VJHe2 99.89% (0x6c(sp) -> 0x70(sp)

// Address 0x7F012794 NTSC
Gfx * constructor_menu0F_mpcharsel(Gfx *DL)
{
    s32 spE4;
    s32 i; // spE0
    u8 *text;
    s32 var_s2;
    s32 var_s7;
    s32 var_s4;
    s32 var_v1;
    s32 padding3;
    s32 padding4;
    s32 padding1;
    s32 spBC;
    s32 spB8;
    s32 spB4;
    s32 spB0;
    s32 padding2;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;

    spE4 = get_selected_num_players();

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);
    DL = frontSetupMenuBackground(DL);
    DL = microcode_constructor(DL);
    DL = microcode_constructor_related_to_menus(DL, 0x26, 0xA9, 0x184, 0xAB, 0x90);

    if (spE4 >= 3)
    {
        DL = microcode_constructor_related_to_menus(DL, 0xD4, 0x1E, 0xD6, 0x136, 0x80);
    }

    for (i = 0; i < spE4; i++)
    {
        if (spE4 == 2)
        {
            var_s2 = 0x26;
            var_s4 = 0x15E;

            if (i > 0)
            {
                var_v1 = 0x8c;
            }
            else
            {
                var_v1 = 0;
            }
            var_s7 = var_v1 + 0x1E;
        }
        else
        {
            var_s4 = 0xAF;

            if (i >= 2)
            {
                var_v1 = 0x8C;
            }
            else
            {
                var_v1 = 0;
            }
            var_s7 = var_v1 + 0x1E;

            if (i & 1)
            {
                var_v1 = 0xAF;
            }
            else
            {
                var_v1 = 0;
            }
            var_s2 = var_v1 + 0x26;
        }

        gDPSetScissor(DL++, G_SC_NON_INTERLACE, (var_s2 + 6), var_s7 + 5, (var_s2 + var_s4 - 6), (var_s7 + 0x87));

        if ((player_has_selected_char[i] == 0) && (size_mp_select_image_player[i] == 0))
        {

            text = langGet(0x9C55U);
            textMeasure(&spBC, &spB8, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            spB4 = ((var_s4 >> 1) + var_s2) - (spB8 >> 1);
            spB0 = var_s7 + 5;

            DL = microcode_constructor(DL);
            DL = frontPrintText(DL, &spB4, &spB0, (s8*)text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }

        text = langGet(mp_chr_setup[mp_char_cur_select_player[i]].text_preset);
        textMeasure(&spA8, &spA4, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        spA0 = (var_s4 >> 1) + var_s2 - (spA4 >> 1);
        sp9C = var_s7 + 0x78;

        DL = microcode_constructor(DL);
        DL = frontPrintText(DL, &spA0, &sp9C, (s8*)text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, (var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i], var_s7 + 0x46, mp_char_prev_select_player[i], size_mp_select_image_player[i]);

        if ((player_has_selected_char[i] == 0 && size_mp_select_image_player[i] == 0) || (mp_char_prev_select_player[i] != mp_char_cur_select_player[i]))
        {
            if (mp_char_prev_select_player[i] >= 3)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) - 0xFC, var_s7 + 0x46, mp_char_prev_select_player[i] - 3, size_mp_select_image_player[i]);
            }

            if (mp_char_prev_select_player[i] >= 2)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) - 0xA8, var_s7 + 0x46, mp_char_prev_select_player[i] - 2, size_mp_select_image_player[i]);
            }

            if (mp_char_prev_select_player[i] >= 1)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) - 0x54, var_s7 + 0x46, mp_char_prev_select_player[i] - 1, size_mp_select_image_player[i]);
            }

            if (mp_char_prev_select_player[i] < num_chars_selectable_mp - 1)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) + 0x54, var_s7 + 0x46, mp_char_prev_select_player[i] + 1, size_mp_select_image_player[i]);
            }

            if (mp_char_prev_select_player[i] < num_chars_selectable_mp - 2)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) + 0xA8, var_s7 + 0x46, mp_char_prev_select_player[i] + 2, size_mp_select_image_player[i]);
            }

            if (mp_char_prev_select_player[i] < num_chars_selectable_mp - 3)
            {
                DL = frontRenderCharacterPortrait(DL, var_s2 + 0xD, var_s2 + var_s4 - 0xE, ((var_s4 >> 1) + var_s2 - dword_CODE_bss_80069730[i]) + 0xFC, var_s7 + 0x46, mp_char_prev_select_player[i] + 3, size_mp_select_image_player[i]);
            }
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}
#else
GLOBAL_ASM(
.text
glabel constructor_menu0F_mpcharsel
/* 0472C4 7F012794 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0472C8 7F012798 AFBF0064 */  sw    $ra, 0x64($sp)
/* 0472CC 7F01279C AFB10044 */  sw    $s1, 0x44($sp)
/* 0472D0 7F0127A0 00808825 */  move  $s1, $a0
/* 0472D4 7F0127A4 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0472D8 7F0127A8 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0472DC 7F0127AC AFB60058 */  sw    $s6, 0x58($sp)
/* 0472E0 7F0127B0 AFB50054 */  sw    $s5, 0x54($sp)
/* 0472E4 7F0127B4 AFB40050 */  sw    $s4, 0x50($sp)
/* 0472E8 7F0127B8 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0472EC 7F0127BC AFB20048 */  sw    $s2, 0x48($sp)
/* 0472F0 7F0127C0 AFB00040 */  sw    $s0, 0x40($sp)
/* 0472F4 7F0127C4 0FC040A4 */  jal   get_selected_num_players
/* 0472F8 7F0127C8 F7B40038 */   sdc1  $f20, 0x38($sp)
/* 0472FC 7F0127CC AFA200E4 */  sw    $v0, 0xe4($sp)
/* 047300 7F0127D0 02202025 */  move  $a0, $s1
/* 047304 7F0127D4 00002825 */  move  $a1, $zero
/* 047308 7F0127D8 00003025 */  move  $a2, $zero
/* 04730C 7F0127DC 0C0011B4 */  jal   viSetFillColor
/* 047310 7F0127E0 00003825 */   move  $a3, $zero
/* 047314 7F0127E4 0C000FBE */  jal   viFillScreen
/* 047318 7F0127E8 00402025 */   move  $a0, $v0
/* 04731C 7F0127EC 0FC0357A */  jal   frontSetupMenuBackground
/* 047320 7F0127F0 00402025 */   move  $a0, $v0
/* 047324 7F0127F4 0FC2B366 */  jal   microcode_constructor
/* 047328 7F0127F8 00402025 */   move  $a0, $v0
/* 04732C 7F0127FC 240E00AB */  li    $t6, 171
/* 047330 7F012800 240F0090 */  li    $t7, 144
/* 047334 7F012804 AFAF0014 */  sw    $t7, 0x14($sp)
/* 047338 7F012808 AFAE0010 */  sw    $t6, 0x10($sp)
/* 04733C 7F01280C 00402025 */  move  $a0, $v0
/* 047340 7F012810 24050026 */  li    $a1, 38
/* 047344 7F012814 240600A9 */  li    $a2, 169
/* 047348 7F012818 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 04734C 7F01281C 24070184 */   li    $a3, 388
/* 047350 7F012820 8FA800E4 */  lw    $t0, 0xe4($sp)
/* 047354 7F012824 00408825 */  move  $s1, $v0
/* 047358 7F012828 02202025 */  move  $a0, $s1
/* 04735C 7F01282C 29010003 */  slti  $at, $t0, 3
/* 047360 7F012830 1420000A */  bnez  $at, .L7F01285C
/* 047364 7F012834 240500D4 */   li    $a1, 212
/* 047368 7F012838 24180136 */  li    $t8, 310
/* 04736C 7F01283C 24190080 */  li    $t9, 128
/* 047370 7F012840 AFB90014 */  sw    $t9, 0x14($sp)
/* 047374 7F012844 AFB80010 */  sw    $t8, 0x10($sp)
/* 047378 7F012848 2406001E */  li    $a2, 30
/* 04737C 7F01284C 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 047380 7F012850 240700D6 */   li    $a3, 214
/* 047384 7F012854 00408825 */  move  $s1, $v0
/* 047388 7F012858 8FA800E4 */  lw    $t0, 0xe4($sp)
.L7F01285C:
/* 04738C 7F01285C 19000165 */  blez  $t0, .L7F012DF4
/* 047390 7F012860 3C098007 */   lui   $t1, %hi(player_has_selected_char)
/* 047394 7F012864 3C0A8007 */  lui   $t2, %hi(mp_char_cur_select_player)
/* 047398 7F012868 3C0B8007 */  lui   $t3, %hi(dword_CODE_bss_80069730)
/* 04739C 7F01286C 3C0C8007 */  lui   $t4, %hi(mp_char_prev_select_player)
/* 0473A0 7F012870 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0473A4 7F012874 258C9720 */  addiu $t4, %lo(mp_char_prev_select_player) # addiu $t4, $t4, -0x68e0
/* 0473A8 7F012878 256B9730 */  addiu $t3, %lo(dword_CODE_bss_80069730) # addiu $t3, $t3, -0x68d0
/* 0473AC 7F01287C 254A9710 */  addiu $t2, %lo(mp_char_cur_select_player) # addiu $t2, $t2, -0x68f0
/* 0473B0 7F012880 25299740 */  addiu $t1, %lo(player_has_selected_char) # addiu $t1, $t1, -0x68c0
/* 0473B4 7F012884 3C1E8007 */  lui   $fp, %hi(size_mp_select_image_player)
/* 0473B8 7F012888 4481A000 */  mtc1  $at, $f20
/* 0473BC 7F01288C 27DE9750 */  addiu $fp, %lo(size_mp_select_image_player) # addiu $fp, $fp, -0x68b0
/* 0473C0 7F012890 AFA90088 */  sw    $t1, 0x88($sp)
/* 0473C4 7F012894 AFAA0080 */  sw    $t2, 0x80($sp)
/* 0473C8 7F012898 AFAB0074 */  sw    $t3, 0x74($sp)
/* 0473CC 7F01289C AFAC0070 */  sw    $t4, 0x70($sp)
/* 0473D0 7F0128A0 AFA000E0 */  sw    $zero, 0xe0($sp)
.L7F0128A4:
/* 0473D4 7F0128A4 8FA800E4 */  lw    $t0, 0xe4($sp)
/* 0473D8 7F0128A8 8FA400E0 */  lw    $a0, 0xe0($sp)
/* 0473DC 7F0128AC 24010002 */  li    $at, 2
/* 0473E0 7F0128B0 15010009 */  bne   $t0, $at, .L7F0128D8
/* 0473E4 7F0128B4 308D0001 */   andi  $t5, $a0, 1
/* 0473E8 7F0128B8 24120026 */  li    $s2, 38
/* 0473EC 7F0128BC 18800003 */  blez  $a0, .L7F0128CC
/* 0473F0 7F0128C0 2414015E */   li    $s4, 350
/* 0473F4 7F0128C4 10000010 */  b     .L7F012908
/* 0473F8 7F0128C8 241700AA */   li    $s7, 170
.L7F0128CC:
/* 0473FC 7F0128CC 00001825 */  move  $v1, $zero
/* 047400 7F0128D0 1000000D */  b     .L7F012908
/* 047404 7F0128D4 2477001E */   addiu $s7, $v1, 0x1e
.L7F0128D8:
/* 047408 7F0128D8 28810002 */  slti  $at, $a0, 2
/* 04740C 7F0128DC 14200003 */  bnez  $at, .L7F0128EC
/* 047410 7F0128E0 241400AF */   li    $s4, 175
/* 047414 7F0128E4 10000002 */  b     .L7F0128F0
/* 047418 7F0128E8 2403008C */   li    $v1, 140
.L7F0128EC:
/* 04741C 7F0128EC 00001825 */  move  $v1, $zero
.L7F0128F0:
/* 047420 7F0128F0 11A00003 */  beqz  $t5, .L7F012900
/* 047424 7F0128F4 2477001E */   addiu $s7, $v1, 0x1e
/* 047428 7F0128F8 10000002 */  b     .L7F012904
/* 04742C 7F0128FC 240300AF */   li    $v1, 175
.L7F012900:
/* 047430 7F012900 00001825 */  move  $v1, $zero
.L7F012904:
/* 047434 7F012904 24720026 */  addiu $s2, $v1, 0x26
.L7F012908:
/* 047438 7F012908 264E0006 */  addiu $t6, $s2, 6
/* 04743C 7F01290C 448E2000 */  mtc1  $t6, $f4
/* 047440 7F012910 26F00005 */  addiu $s0, $s7, 5
/* 047444 7F012914 44908000 */  mtc1  $s0, $f16
/* 047448 7F012918 468021A0 */  cvt.s.w $f6, $f4
/* 04744C 7F01291C 02547821 */  addu  $t7, $s2, $s4
/* 047450 7F012920 3C01ED00 */  lui   $at, 0xed00
/* 047454 7F012924 24510008 */  addiu $s1, $v0, 8
/* 047458 7F012928 468084A0 */  cvt.s.w $f18, $f16
/* 04745C 7F01292C 46143202 */  mul.s $f8, $f6, $f20
/* 047460 7F012930 4600428D */  trunc.w.s $f10, $f8
/* 047464 7F012934 46149102 */  mul.s $f4, $f18, $f20
/* 047468 7F012938 44185000 */  mfc1  $t8, $f10
/* 04746C 7F01293C 00000000 */  nop
/* 047470 7F012940 33190FFF */  andi  $t9, $t8, 0xfff
/* 047474 7F012944 4600218D */  trunc.w.s $f6, $f4
/* 047478 7F012948 00194B00 */  sll   $t1, $t9, 0xc
/* 04747C 7F01294C 25F9FFFA */  addiu $t9, $t7, -6
/* 047480 7F012950 44994000 */  mtc1  $t9, $f8
/* 047484 7F012954 440C3000 */  mfc1  $t4, $f6
/* 047488 7F012958 01215025 */  or    $t2, $t1, $at
/* 04748C 7F01295C 468042A0 */  cvt.s.w $f10, $f8
/* 047490 7F012960 318D0FFF */  andi  $t5, $t4, 0xfff
/* 047494 7F012964 014D7025 */  or    $t6, $t2, $t5
/* 047498 7F012968 26ED0087 */  addiu $t5, $s7, 0x87
/* 04749C 7F01296C 448D2000 */  mtc1  $t5, $f4
/* 0474A0 7F012970 AC4E0000 */  sw    $t6, ($v0)
/* 0474A4 7F012974 46145402 */  mul.s $f16, $f10, $f20
/* 0474A8 7F012978 AFAF008C */  sw    $t7, 0x8c($sp)
/* 0474AC 7F01297C 468021A0 */  cvt.s.w $f6, $f4
/* 0474B0 7F012980 4600848D */  trunc.w.s $f18, $f16
/* 0474B4 7F012984 46143202 */  mul.s $f8, $f6, $f20
/* 0474B8 7F012988 440B9000 */  mfc1  $t3, $f18
/* 0474BC 7F01298C 00000000 */  nop
/* 0474C0 7F012990 316C0FFF */  andi  $t4, $t3, 0xfff
/* 0474C4 7F012994 4600428D */  trunc.w.s $f10, $f8
/* 0474C8 7F012998 000C5300 */  sll   $t2, $t4, 0xc
/* 0474CC 7F01299C 440F5000 */  mfc1  $t7, $f10
/* 0474D0 7F0129A0 00000000 */  nop
/* 0474D4 7F0129A4 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0474D8 7F0129A8 0158C825 */  or    $t9, $t2, $t8
/* 0474DC 7F0129AC AC590004 */  sw    $t9, 4($v0)
/* 0474E0 7F0129B0 8FA90088 */  lw    $t1, 0x88($sp)
/* 0474E4 7F0129B4 AFA400E0 */  sw    $a0, 0xe0($sp)
/* 0474E8 7F0129B8 8D2B0000 */  lw    $t3, ($t1)
/* 0474EC 7F0129BC 55600034 */  bnezl $t3, .L7F012A90
/* 0474F0 7F0129C0 8FAE0080 */   lw    $t6, 0x80($sp)
/* 0474F4 7F0129C4 8FCC0000 */  lw    $t4, ($fp)
/* 0474F8 7F0129C8 AFA400E0 */  sw    $a0, 0xe0($sp)
/* 0474FC 7F0129CC 55800030 */  bnezl $t4, .L7F012A90
/* 047500 7F0129D0 8FAE0080 */   lw    $t6, 0x80($sp)
/* 047504 7F0129D4 0FC30776 */  jal   langGet
/* 047508 7F0129D8 34049C55 */   li    $a0, 40021
/* 04750C 7F0129DC 3C0D8004 */  lui   $t5, %hi(ptrFontZurichBold)
/* 047510 7F0129E0 8DAD0EB4 */  lw    $t5, %lo(ptrFontZurichBold)($t5)
/* 047514 7F0129E4 3C078004 */  lui   $a3, %hi(ptrFontZurichBoldChars)
/* 047518 7F0129E8 00409825 */  move  $s3, $v0
/* 04751C 7F0129EC 8CE70EB8 */  lw    $a3, %lo(ptrFontZurichBoldChars)($a3)
/* 047520 7F0129F0 27A400BC */  addiu $a0, $sp, 0xbc
/* 047524 7F0129F4 27A500B8 */  addiu $a1, $sp, 0xb8
/* 047528 7F0129F8 00403025 */  move  $a2, $v0
/* 04752C 7F0129FC AFA00014 */  sw    $zero, 0x14($sp)
/* 047530 7F012A00 0FC2BA63 */  jal   textMeasure
/* 047534 7F012A04 AFAD0010 */   sw    $t5, 0x10($sp)
/* 047538 7F012A08 8FAA00B8 */  lw    $t2, 0xb8($sp)
/* 04753C 7F012A0C 00147043 */  sra   $t6, $s4, 1
/* 047540 7F012A10 01D27821 */  addu  $t7, $t6, $s2
/* 047544 7F012A14 000AC043 */  sra   $t8, $t2, 1
/* 047548 7F012A18 01F8C823 */  subu  $t9, $t7, $t8
/* 04754C 7F012A1C AFB900B4 */  sw    $t9, 0xb4($sp)
/* 047550 7F012A20 AFB000B0 */  sw    $s0, 0xb0($sp)
/* 047554 7F012A24 0FC2B366 */  jal   microcode_constructor
/* 047558 7F012A28 02202025 */   move  $a0, $s1
/* 04755C 7F012A2C 0C001107 */  jal   viGetX
/* 047560 7F012A30 00408825 */   move  $s1, $v0
/* 047564 7F012A34 00028400 */  sll   $s0, $v0, 0x10
/* 047568 7F012A38 00104C03 */  sra   $t1, $s0, 0x10
/* 04756C 7F012A3C 0C00110B */  jal   viGetY
/* 047570 7F012A40 01208025 */   move  $s0, $t1
/* 047574 7F012A44 3C0B8004 */  lui   $t3, %hi(ptrFontZurichBoldChars)
/* 047578 7F012A48 3C0C8004 */  lui   $t4, %hi(ptrFontZurichBold)
/* 04757C 7F012A4C 8D8C0EB4 */  lw    $t4, %lo(ptrFontZurichBold)($t4)
/* 047580 7F012A50 8D6B0EB8 */  lw    $t3, %lo(ptrFontZurichBoldChars)($t3)
/* 047584 7F012A54 240D00FF */  li    $t5, 255
/* 047588 7F012A58 AFAD0018 */  sw    $t5, 0x18($sp)
/* 04758C 7F012A5C 02202025 */  move  $a0, $s1
/* 047590 7F012A60 27A500B4 */  addiu $a1, $sp, 0xb4
/* 047594 7F012A64 27A600B0 */  addiu $a2, $sp, 0xb0
/* 047598 7F012A68 02603825 */  move  $a3, $s3
/* 04759C 7F012A6C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0475A0 7F012A70 AFA20020 */  sw    $v0, 0x20($sp)
/* 0475A4 7F012A74 AFA00024 */  sw    $zero, 0x24($sp)
/* 0475A8 7F012A78 AFA00028 */  sw    $zero, 0x28($sp)
/* 0475AC 7F012A7C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0475B0 7F012A80 0FC025D8 */  jal   frontPrintText
/* 0475B4 7F012A84 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0475B8 7F012A88 00408825 */  move  $s1, $v0
/* 0475BC 7F012A8C 8FAE0080 */  lw    $t6, 0x80($sp)
.L7F012A90:
/* 0475C0 7F012A90 3C048003 */  lui   $a0, %hi(mp_chr_setup)
/* 0475C4 7F012A94 0014C043 */  sra   $t8, $s4, 1
/* 0475C8 7F012A98 8DCA0000 */  lw    $t2, ($t6)
/* 0475CC 7F012A9C 0312B021 */  addu  $s6, $t8, $s2
/* 0475D0 7F012AA0 000A7880 */  sll   $t7, $t2, 2
/* 0475D4 7F012AA4 01EA7823 */  subu  $t7, $t7, $t2
/* 0475D8 7F012AA8 000F7880 */  sll   $t7, $t7, 2
/* 0475DC 7F012AAC 008F2021 */  addu  $a0, $a0, $t7
/* 0475E0 7F012AB0 0FC30776 */  jal   langGet
/* 0475E4 7F012AB4 9484B198 */   lhu   $a0, %lo(mp_chr_setup)($a0)
/* 0475E8 7F012AB8 3C198004 */  lui   $t9, %hi(ptrFontZurichBold)
/* 0475EC 7F012ABC 8F390EB4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0475F0 7F012AC0 3C078004 */  lui   $a3, %hi(ptrFontZurichBoldChars)
/* 0475F4 7F012AC4 00409825 */  move  $s3, $v0
/* 0475F8 7F012AC8 8CE70EB8 */  lw    $a3, %lo(ptrFontZurichBoldChars)($a3)
/* 0475FC 7F012ACC 27A400A8 */  addiu $a0, $sp, 0xa8
/* 047600 7F012AD0 27A500A4 */  addiu $a1, $sp, 0xa4
/* 047604 7F012AD4 00403025 */  move  $a2, $v0
/* 047608 7F012AD8 AFA00014 */  sw    $zero, 0x14($sp)
/* 04760C 7F012ADC 0FC2BA63 */  jal   textMeasure
/* 047610 7F012AE0 AFB90010 */   sw    $t9, 0x10($sp)
/* 047614 7F012AE4 8FA900A4 */  lw    $t1, 0xa4($sp)
/* 047618 7F012AE8 26ED0078 */  addiu $t5, $s7, 0x78
/* 04761C 7F012AEC AFAD009C */  sw    $t5, 0x9c($sp)
/* 047620 7F012AF0 00095843 */  sra   $t3, $t1, 1
/* 047624 7F012AF4 02CB6023 */  subu  $t4, $s6, $t3
/* 047628 7F012AF8 AFAC00A0 */  sw    $t4, 0xa0($sp)
/* 04762C 7F012AFC 0FC2B366 */  jal   microcode_constructor
/* 047630 7F012B00 02202025 */   move  $a0, $s1
/* 047634 7F012B04 0C001107 */  jal   viGetX
/* 047638 7F012B08 00408825 */   move  $s1, $v0
/* 04763C 7F012B0C 00028400 */  sll   $s0, $v0, 0x10
/* 047640 7F012B10 00107403 */  sra   $t6, $s0, 0x10
/* 047644 7F012B14 0C00110B */  jal   viGetY
/* 047648 7F012B18 01C08025 */   move  $s0, $t6
/* 04764C 7F012B1C 3C0A8004 */  lui   $t2, %hi(ptrFontZurichBoldChars)
/* 047650 7F012B20 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBold)
/* 047654 7F012B24 8DEF0EB4 */  lw    $t7, %lo(ptrFontZurichBold)($t7)
/* 047658 7F012B28 8D4A0EB8 */  lw    $t2, %lo(ptrFontZurichBoldChars)($t2)
/* 04765C 7F012B2C 241800FF */  li    $t8, 255
/* 047660 7F012B30 AFB80018 */  sw    $t8, 0x18($sp)
/* 047664 7F012B34 02202025 */  move  $a0, $s1
/* 047668 7F012B38 27A500A0 */  addiu $a1, $sp, 0xa0
/* 04766C 7F012B3C 27A6009C */  addiu $a2, $sp, 0x9c
/* 047670 7F012B40 02603825 */  move  $a3, $s3
/* 047674 7F012B44 AFB0001C */  sw    $s0, 0x1c($sp)
/* 047678 7F012B48 AFA20020 */  sw    $v0, 0x20($sp)
/* 04767C 7F012B4C AFA00024 */  sw    $zero, 0x24($sp)
/* 047680 7F012B50 AFA00028 */  sw    $zero, 0x28($sp)
/* 047684 7F012B54 AFAF0014 */  sw    $t7, 0x14($sp)
/* 047688 7F012B58 0FC025D8 */  jal   frontPrintText
/* 04768C 7F012B5C AFAA0010 */   sw    $t2, 0x10($sp)
/* 047690 7F012B60 8FB90074 */  lw    $t9, 0x74($sp)
/* 047694 7F012B64 8FAB0070 */  lw    $t3, 0x70($sp)
/* 047698 7F012B68 8FB4008C */  lw    $s4, 0x8c($sp)
/* 04769C 7F012B6C 8F290000 */  lw    $t1, ($t9)
/* 0476A0 7F012B70 26F50046 */  addiu $s5, $s7, 0x46
/* 0476A4 7F012B74 AFB50010 */  sw    $s5, 0x10($sp)
/* 0476A8 7F012B78 8FCD0000 */  lw    $t5, ($fp)
/* 0476AC 7F012B7C 8D6C0000 */  lw    $t4, ($t3)
/* 0476B0 7F012B80 2653000D */  addiu $s3, $s2, 0xd
/* 0476B4 7F012B84 2694FFF2 */  addiu $s4, $s4, -0xe
/* 0476B8 7F012B88 02803025 */  move  $a2, $s4
/* 0476BC 7F012B8C 02602825 */  move  $a1, $s3
/* 0476C0 7F012B90 00402025 */  move  $a0, $v0
/* 0476C4 7F012B94 02C93823 */  subu  $a3, $s6, $t1
/* 0476C8 7F012B98 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0476CC 7F012B9C 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 0476D0 7F012BA0 AFAC0014 */   sw    $t4, 0x14($sp)
/* 0476D4 7F012BA4 8FAE0088 */  lw    $t6, 0x88($sp)
/* 0476D8 7F012BA8 00408825 */  move  $s1, $v0
/* 0476DC 7F012BAC 8FB80070 */  lw    $t8, 0x70($sp)
/* 0476E0 7F012BB0 8DCA0000 */  lw    $t2, ($t6)
/* 0476E4 7F012BB4 8FA90080 */  lw    $t1, 0x80($sp)
/* 0476E8 7F012BB8 55400005 */  bnezl $t2, .L7F012BD0
/* 0476EC 7F012BBC 8F190000 */   lw    $t9, ($t8)
/* 0476F0 7F012BC0 8FCF0000 */  lw    $t7, ($fp)
/* 0476F4 7F012BC4 51E00006 */  beql  $t7, $zero, .L7F012BE0
/* 0476F8 7F012BC8 8FAC0070 */   lw    $t4, 0x70($sp)
/* 0476FC 7F012BCC 8F190000 */  lw    $t9, ($t8)
.L7F012BD0:
/* 047700 7F012BD0 8D2B0000 */  lw    $t3, ($t1)
/* 047704 7F012BD4 532B0076 */  beql  $t9, $t3, .L7F012DB0
/* 047708 7F012BD8 8FAB0088 */   lw    $t3, 0x88($sp)
/* 04770C 7F012BDC 8FAC0070 */  lw    $t4, 0x70($sp)
.L7F012BE0:
/* 047710 7F012BE0 02202025 */  move  $a0, $s1
/* 047714 7F012BE4 02602825 */  move  $a1, $s3
/* 047718 7F012BE8 8D900000 */  lw    $s0, ($t4)
/* 04771C 7F012BEC 02803025 */  move  $a2, $s4
/* 047720 7F012BF0 8FAD0074 */  lw    $t5, 0x74($sp)
/* 047724 7F012BF4 2A010003 */  slti  $at, $s0, 3
/* 047728 7F012BF8 1420000C */  bnez  $at, .L7F012C2C
/* 04772C 7F012BFC 260AFFFD */   addiu $t2, $s0, -3
/* 047730 7F012C00 8DAE0000 */  lw    $t6, ($t5)
/* 047734 7F012C04 8FCF0000 */  lw    $t7, ($fp)
/* 047738 7F012C08 AFAA0014 */  sw    $t2, 0x14($sp)
/* 04773C 7F012C0C 02CE3823 */  subu  $a3, $s6, $t6
/* 047740 7F012C10 24E7FF04 */  addiu $a3, $a3, -0xfc
/* 047744 7F012C14 AFB50010 */  sw    $s5, 0x10($sp)
/* 047748 7F012C18 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 04774C 7F012C1C AFAF0018 */   sw    $t7, 0x18($sp)
/* 047750 7F012C20 8FB80070 */  lw    $t8, 0x70($sp)
/* 047754 7F012C24 00408825 */  move  $s1, $v0
/* 047758 7F012C28 8F100000 */  lw    $s0, ($t8)
.L7F012C2C:
/* 04775C 7F012C2C 2A010002 */  slti  $at, $s0, 2
/* 047760 7F012C30 14200010 */  bnez  $at, .L7F012C74
/* 047764 7F012C34 02202025 */   move  $a0, $s1
/* 047768 7F012C38 8FA90074 */  lw    $t1, 0x74($sp)
/* 04776C 7F012C3C 8FCC0000 */  lw    $t4, ($fp)
/* 047770 7F012C40 260BFFFE */  addiu $t3, $s0, -2
/* 047774 7F012C44 8D390000 */  lw    $t9, ($t1)
/* 047778 7F012C48 AFAB0014 */  sw    $t3, 0x14($sp)
/* 04777C 7F012C4C AFB50010 */  sw    $s5, 0x10($sp)
/* 047780 7F012C50 02D93823 */  subu  $a3, $s6, $t9
/* 047784 7F012C54 24E7FF58 */  addiu $a3, $a3, -0xa8
/* 047788 7F012C58 02602825 */  move  $a1, $s3
/* 04778C 7F012C5C 02803025 */  move  $a2, $s4
/* 047790 7F012C60 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 047794 7F012C64 AFAC0018 */   sw    $t4, 0x18($sp)
/* 047798 7F012C68 8FAD0070 */  lw    $t5, 0x70($sp)
/* 04779C 7F012C6C 00408825 */  move  $s1, $v0
/* 0477A0 7F012C70 8DB00000 */  lw    $s0, ($t5)
.L7F012C74:
/* 0477A4 7F012C74 1A000010 */  blez  $s0, .L7F012CB8
/* 0477A8 7F012C78 02202025 */   move  $a0, $s1
/* 0477AC 7F012C7C 8FAE0074 */  lw    $t6, 0x74($sp)
/* 0477B0 7F012C80 8FD80000 */  lw    $t8, ($fp)
/* 0477B4 7F012C84 260FFFFF */  addiu $t7, $s0, -1
/* 0477B8 7F012C88 8DCA0000 */  lw    $t2, ($t6)
/* 0477BC 7F012C8C AFAF0014 */  sw    $t7, 0x14($sp)
/* 0477C0 7F012C90 AFB50010 */  sw    $s5, 0x10($sp)
/* 0477C4 7F012C94 02CA3823 */  subu  $a3, $s6, $t2
/* 0477C8 7F012C98 24E7FFAC */  addiu $a3, $a3, -0x54
/* 0477CC 7F012C9C 02602825 */  move  $a1, $s3
/* 0477D0 7F012CA0 02803025 */  move  $a2, $s4
/* 0477D4 7F012CA4 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 0477D8 7F012CA8 AFB80018 */   sw    $t8, 0x18($sp)
/* 0477DC 7F012CAC 8FA90070 */  lw    $t1, 0x70($sp)
/* 0477E0 7F012CB0 00408825 */  move  $s1, $v0
/* 0477E4 7F012CB4 8D300000 */  lw    $s0, ($t1)
.L7F012CB8:
/* 0477E8 7F012CB8 3C038003 */  lui   $v1, %hi(num_chars_selectable_mp)
/* 0477EC 7F012CBC 8C63B194 */  lw    $v1, %lo(num_chars_selectable_mp)($v1)
/* 0477F0 7F012CC0 02202025 */  move  $a0, $s1
/* 0477F4 7F012CC4 02602825 */  move  $a1, $s3
/* 0477F8 7F012CC8 2479FFFF */  addiu $t9, $v1, -1
/* 0477FC 7F012CCC 0219082A */  slt   $at, $s0, $t9
/* 047800 7F012CD0 10200010 */  beqz  $at, .L7F012D14
/* 047804 7F012CD4 02803025 */   move  $a2, $s4
/* 047808 7F012CD8 8FAB0074 */  lw    $t3, 0x74($sp)
/* 04780C 7F012CDC 8FCE0000 */  lw    $t6, ($fp)
/* 047810 7F012CE0 260D0001 */  addiu $t5, $s0, 1
/* 047814 7F012CE4 8D6C0000 */  lw    $t4, ($t3)
/* 047818 7F012CE8 AFAD0014 */  sw    $t5, 0x14($sp)
/* 04781C 7F012CEC AFB50010 */  sw    $s5, 0x10($sp)
/* 047820 7F012CF0 02CC3823 */  subu  $a3, $s6, $t4
/* 047824 7F012CF4 24E70054 */  addiu $a3, $a3, 0x54
/* 047828 7F012CF8 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 04782C 7F012CFC AFAE0018 */   sw    $t6, 0x18($sp)
/* 047830 7F012D00 8FAA0070 */  lw    $t2, 0x70($sp)
/* 047834 7F012D04 3C038003 */  lui   $v1, %hi(num_chars_selectable_mp)
/* 047838 7F012D08 8C63B194 */  lw    $v1, %lo(num_chars_selectable_mp)($v1)
/* 04783C 7F012D0C 00408825 */  move  $s1, $v0
/* 047840 7F012D10 8D500000 */  lw    $s0, ($t2)
.L7F012D14:
/* 047844 7F012D14 246FFFFE */  addiu $t7, $v1, -2
/* 047848 7F012D18 020F082A */  slt   $at, $s0, $t7
/* 04784C 7F012D1C 10200012 */  beqz  $at, .L7F012D68
/* 047850 7F012D20 02202025 */   move  $a0, $s1
/* 047854 7F012D24 8FB80074 */  lw    $t8, 0x74($sp)
/* 047858 7F012D28 8FCB0000 */  lw    $t3, ($fp)
/* 04785C 7F012D2C 26190002 */  addiu $t9, $s0, 2
/* 047860 7F012D30 8F090000 */  lw    $t1, ($t8)
/* 047864 7F012D34 AFB90014 */  sw    $t9, 0x14($sp)
/* 047868 7F012D38 AFB50010 */  sw    $s5, 0x10($sp)
/* 04786C 7F012D3C 02C93823 */  subu  $a3, $s6, $t1
/* 047870 7F012D40 24E700A8 */  addiu $a3, $a3, 0xa8
/* 047874 7F012D44 02602825 */  move  $a1, $s3
/* 047878 7F012D48 02803025 */  move  $a2, $s4
/* 04787C 7F012D4C 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 047880 7F012D50 AFAB0018 */   sw    $t3, 0x18($sp)
/* 047884 7F012D54 8FAC0070 */  lw    $t4, 0x70($sp)
/* 047888 7F012D58 3C038003 */  lui   $v1, %hi(num_chars_selectable_mp)
/* 04788C 7F012D5C 8C63B194 */  lw    $v1, %lo(num_chars_selectable_mp)($v1)
/* 047890 7F012D60 00408825 */  move  $s1, $v0
/* 047894 7F012D64 8D900000 */  lw    $s0, ($t4)
.L7F012D68:
/* 047898 7F012D68 246DFFFD */  addiu $t5, $v1, -3
/* 04789C 7F012D6C 020D082A */  slt   $at, $s0, $t5
/* 0478A0 7F012D70 1020000E */  beqz  $at, .L7F012DAC
/* 0478A4 7F012D74 02202025 */   move  $a0, $s1
/* 0478A8 7F012D78 8FAE0074 */  lw    $t6, 0x74($sp)
/* 0478AC 7F012D7C 8FD80000 */  lw    $t8, ($fp)
/* 0478B0 7F012D80 260F0003 */  addiu $t7, $s0, 3
/* 0478B4 7F012D84 8DCA0000 */  lw    $t2, ($t6)
/* 0478B8 7F012D88 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0478BC 7F012D8C AFB50010 */  sw    $s5, 0x10($sp)
/* 0478C0 7F012D90 02CA3823 */  subu  $a3, $s6, $t2
/* 0478C4 7F012D94 24E700FC */  addiu $a3, $a3, 0xfc
/* 0478C8 7F012D98 02602825 */  move  $a1, $s3
/* 0478CC 7F012D9C 02803025 */  move  $a2, $s4
/* 0478D0 7F012DA0 0FC048C7 */  jal   frontRenderCharacterPortrait
/* 0478D4 7F012DA4 AFB80018 */   sw    $t8, 0x18($sp)
/* 0478D8 7F012DA8 00408825 */  move  $s1, $v0
.L7F012DAC:
/* 0478DC 7F012DAC 8FAB0088 */  lw    $t3, 0x88($sp)
.L7F012DB0:
/* 0478E0 7F012DB0 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0478E4 7F012DB4 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0478E8 7F012DB8 8FAA0074 */  lw    $t2, 0x74($sp)
/* 0478EC 7F012DBC 8FB80070 */  lw    $t8, 0x70($sp)
/* 0478F0 7F012DC0 256C0004 */  addiu $t4, $t3, 4
/* 0478F4 7F012DC4 8FAB00E4 */  lw    $t3, 0xe4($sp)
/* 0478F8 7F012DC8 25390001 */  addiu $t9, $t1, 1
/* 0478FC 7F012DCC 25AE0004 */  addiu $t6, $t5, 4
/* 047900 7F012DD0 254F0004 */  addiu $t7, $t2, 4
/* 047904 7F012DD4 27090004 */  addiu $t1, $t8, 4
/* 047908 7F012DD8 AFA90070 */  sw    $t1, 0x70($sp)
/* 04790C 7F012DDC AFAF0074 */  sw    $t7, 0x74($sp)
/* 047910 7F012DE0 AFAE0080 */  sw    $t6, 0x80($sp)
/* 047914 7F012DE4 AFB900E0 */  sw    $t9, 0xe0($sp)
/* 047918 7F012DE8 AFAC0088 */  sw    $t4, 0x88($sp)
/* 04791C 7F012DEC 172BFEAD */  bne   $t9, $t3, .L7F0128A4
/* 047920 7F012DF0 27DE0004 */   addiu $fp, $fp, 4
.L7F012DF4:
/* 047924 7F012DF4 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 047928 7F012DF8 02202025 */   move  $a0, $s1
/* 04792C 7F012DFC 8FBF0064 */  lw    $ra, 0x64($sp)
/* 047930 7F012E00 D7B40038 */  ldc1  $f20, 0x38($sp)
/* 047934 7F012E04 8FB00040 */  lw    $s0, 0x40($sp)
/* 047938 7F012E08 8FB10044 */  lw    $s1, 0x44($sp)
/* 04793C 7F012E0C 8FB20048 */  lw    $s2, 0x48($sp)
/* 047940 7F012E10 8FB3004C */  lw    $s3, 0x4c($sp)
/* 047944 7F012E14 8FB40050 */  lw    $s4, 0x50($sp)
/* 047948 7F012E18 8FB50054 */  lw    $s5, 0x54($sp)
/* 04794C 7F012E1C 8FB60058 */  lw    $s6, 0x58($sp)
/* 047950 7F012E20 8FB7005C */  lw    $s7, 0x5c($sp)
/* 047954 7F012E24 8FBE0060 */  lw    $fp, 0x60($sp)
/* 047958 7F012E28 03E00008 */  jr    $ra
/* 04795C 7F012E2C 27BD00E8 */   addiu $sp, $sp, 0xe8
)
#endif


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

void update_menu10_mphandicap(void) {
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
    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
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
    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
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

void update_menu14_mpteams(void) {
return;
}





// Address 0x7F014D48 NTSC
void interface_menu14_mpteams(void)
{
    s32 i;
    s32 var_a1;

    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
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


// Address 0x7F015138 NTSC
#ifdef NONMATCHING
// https://decomp.me/scratch/N4sd9 99.55%
// Just down to regalloc. Need a break from this one, not sure how much is fake match improvement.
Gfx * constructor_menu14_mpteams(Gfx *DL)
{
    s32 spCC;
    s32 i;
    s32 var_v0;
    s32 temp_s0;
    s32 temp_s2;
    s32 var_s0;
    s32 spB4;
    s32 temp_s6;
    u8 *text;
    s32 var_s2;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 padding1;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 padding2;

    spCC = get_selected_num_players();

    DL = viSetFillColor(DL,0,0,0);
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
        var_v0 = (i >= 2) ? 0x8C : 0;
        temp_s6 = (var_v0) + 0x1E;

        // nonmatching: Problem line.
        var_v0 = ((i & 1) ? 0xAF : 0) + 0;

        gDPSetScissor(DL++, G_SC_NON_INTERLACE, (var_v0 + 0x2c), temp_s6 + 5, var_v0 + 0xcf, temp_s6 + 0x87);

        // nonmatching: Problem line ??
        spB4 = var_v0 + 0x7d;

        if (i == 0)
        {
            text = langGet(0x9C58);
            textMeasure(&spA4, &spA0, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp98 = temp_s6 + 5;
            sp9C = spB4 - (spA0 >> 1);

            DL = frontPrintText(DL, &sp9C, &sp98, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0xFF, viGetX(), viGetY(), 0, 0);
        }

        if (scenario == 5)
        {
            var_s0 = i == 0 || i == teamsize;
        }
        else
        {
            var_s0 = i != teamsize;
        }

        text = var_s0 ? langGet(0x9C59) : langGet(0x9C5A);
        var_s2 = var_s0 ? -0xFFFF01 : 0xFFFF;

        // nonmatching: Basic block, yes or no ??
        if (1)
        {
            textMeasure(&sp90, &sp8C, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

            sp88 = spB4 - (sp8C >> 1);
            sp84 = (temp_s6 - (sp90 >> 1)) + 0x46;

            if ((i != teamsize) || ((i == teamsize) && (D_8002B560 < 0xA)))
            {
                DL = frontPrintText(DL, &sp88, &sp84, text, ptrFontZurichBoldChars, ptrFontZurichBold, var_s2, viGetX(), viGetY(), 0, 0);
            }
        }
    }

    DL = combiner_bayer_lod_perspective(DL);

    return DL;
}

#else
GLOBAL_ASM(
.text
glabel constructor_menu14_mpteams
/* 049C68 7F015138 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 049C6C 7F01513C AFBF0064 */  sw    $ra, 0x64($sp)
/* 049C70 7F015140 AFB50054 */  sw    $s5, 0x54($sp)
/* 049C74 7F015144 0080A825 */  move  $s5, $a0
/* 049C78 7F015148 AFBE0060 */  sw    $fp, 0x60($sp)
/* 049C7C 7F01514C AFB7005C */  sw    $s7, 0x5c($sp)
/* 049C80 7F015150 AFB60058 */  sw    $s6, 0x58($sp)
/* 049C84 7F015154 AFB40050 */  sw    $s4, 0x50($sp)
/* 049C88 7F015158 AFB3004C */  sw    $s3, 0x4c($sp)
/* 049C8C 7F01515C AFB20048 */  sw    $s2, 0x48($sp)
/* 049C90 7F015160 AFB10044 */  sw    $s1, 0x44($sp)
/* 049C94 7F015164 AFB00040 */  sw    $s0, 0x40($sp)
/* 049C98 7F015168 0FC040A4 */  jal   get_selected_num_players
/* 049C9C 7F01516C F7B40038 */   sdc1  $f20, 0x38($sp)
/* 049CA0 7F015170 AFA200CC */  sw    $v0, 0xcc($sp)
/* 049CA4 7F015174 02A02025 */  move  $a0, $s5
/* 049CA8 7F015178 00002825 */  move  $a1, $zero
/* 049CAC 7F01517C 00003025 */  move  $a2, $zero
/* 049CB0 7F015180 0C0011B4 */  jal   viSetFillColor
/* 049CB4 7F015184 00003825 */   move  $a3, $zero
/* 049CB8 7F015188 0C000FBE */  jal   viFillScreen
/* 049CBC 7F01518C 00402025 */   move  $a0, $v0
/* 049CC0 7F015190 0FC0357A */  jal   frontSetupMenuBackground
/* 049CC4 7F015194 00402025 */   move  $a0, $v0
/* 049CC8 7F015198 0FC2B366 */  jal   microcode_constructor
/* 049CCC 7F01519C 00402025 */   move  $a0, $v0
/* 049CD0 7F0151A0 240E00AB */  li    $t6, 171
/* 049CD4 7F0151A4 240F0090 */  li    $t7, 144
/* 049CD8 7F0151A8 AFAF0014 */  sw    $t7, 0x14($sp)
/* 049CDC 7F0151AC AFAE0010 */  sw    $t6, 0x10($sp)
/* 049CE0 7F0151B0 00402025 */  move  $a0, $v0
/* 049CE4 7F0151B4 24050026 */  li    $a1, 38
/* 049CE8 7F0151B8 240600A9 */  li    $a2, 169
/* 049CEC 7F0151BC 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 049CF0 7F0151C0 24070184 */   li    $a3, 388
/* 049CF4 7F0151C4 8FB800CC */  lw    $t8, 0xcc($sp)
/* 049CF8 7F0151C8 0040A825 */  move  $s5, $v0
/* 049CFC 7F0151CC 00402025 */  move  $a0, $v0
/* 049D00 7F0151D0 2B010003 */  slti  $at, $t8, 3
/* 049D04 7F0151D4 14200009 */  bnez  $at, .L7F0151FC
/* 049D08 7F0151D8 240500D4 */   li    $a1, 212
/* 049D0C 7F0151DC 24190136 */  li    $t9, 310
/* 049D10 7F0151E0 24080080 */  li    $t0, 128
/* 049D14 7F0151E4 AFA80014 */  sw    $t0, 0x14($sp)
/* 049D18 7F0151E8 AFB90010 */  sw    $t9, 0x10($sp)
/* 049D1C 7F0151EC 2406001E */  li    $a2, 30
/* 049D20 7F0151F0 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 049D24 7F0151F4 240700D6 */   li    $a3, 214
/* 049D28 7F0151F8 0040A825 */  move  $s5, $v0
.L7F0151FC:
/* 049D2C 7F0151FC 8FA900CC */  lw    $t1, 0xcc($sp)
/* 049D30 7F015200 0000A025 */  move  $s4, $zero
/* 049D34 7F015204 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 049D38 7F015208 192000B2 */  blez  $t1, .L7F0154D4
/* 049D3C 7F01520C 3C178004 */   lui   $s7, %hi(ptrFontZurichBoldChars)
/* 049D40 7F015210 3C1E8004 */  lui   $fp, %hi(ptrFontZurichBold)
/* 049D44 7F015214 4481A000 */  mtc1  $at, $f20
/* 049D48 7F015218 27DE0EB4 */  addiu $fp, %lo(ptrFontZurichBold) # addiu $fp, $fp, 0xeb4
/* 049D4C 7F01521C 26F70EB8 */  addiu $s7, %lo(ptrFontZurichBoldChars) # addiu $s7, $s7, 0xeb8
/* 049D50 7F015220 2A810002 */  slti  $at, $s4, 2
.L7F015224:
/* 049D54 7F015224 14200003 */  bnez  $at, .L7F015234
/* 049D58 7F015228 328A0001 */   andi  $t2, $s4, 1
/* 049D5C 7F01522C 10000002 */  b     .L7F015238
/* 049D60 7F015230 2402008C */   li    $v0, 140
.L7F015234:
/* 049D64 7F015234 00001025 */  move  $v0, $zero
.L7F015238:
/* 049D68 7F015238 11400003 */  beqz  $t2, .L7F015248
/* 049D6C 7F01523C 2456001E */   addiu $s6, $v0, 0x1e
/* 049D70 7F015240 10000002 */  b     .L7F01524C
/* 049D74 7F015244 240200AF */   li    $v0, 175
.L7F015248:
/* 049D78 7F015248 00001025 */  move  $v0, $zero
.L7F01524C:
/* 049D7C 7F01524C 244B002C */  addiu $t3, $v0, 0x2c
/* 049D80 7F015250 448B2000 */  mtc1  $t3, $f4
/* 049D84 7F015254 26D00005 */  addiu $s0, $s6, 5
/* 049D88 7F015258 44908000 */  mtc1  $s0, $f16
/* 049D8C 7F01525C 468021A0 */  cvt.s.w $f6, $f4
/* 049D90 7F015260 244B00CF */  addiu $t3, $v0, 0xcf
/* 049D94 7F015264 26D90087 */  addiu $t9, $s6, 0x87
/* 049D98 7F015268 3C01ED00 */  lui   $at, 0xed00
/* 049D9C 7F01526C 02A01825 */  move  $v1, $s5
/* 049DA0 7F015270 468084A0 */  cvt.s.w $f18, $f16
/* 049DA4 7F015274 46143202 */  mul.s $f8, $f6, $f20
/* 049DA8 7F015278 2451007D */  addiu $s1, $v0, 0x7d
/* 049DAC 7F01527C 2E920001 */  sltiu $s2, $s4, 1
/* 049DB0 7F015280 26B50008 */  addiu $s5, $s5, 8
/* 049DB4 7F015284 46149102 */  mul.s $f4, $f18, $f20
/* 049DB8 7F015288 4600428D */  trunc.w.s $f10, $f8
/* 049DBC 7F01528C 448B4000 */  mtc1  $t3, $f8
/* 049DC0 7F015290 4600218D */  trunc.w.s $f6, $f4
/* 049DC4 7F015294 440D5000 */  mfc1  $t5, $f10
/* 049DC8 7F015298 44992000 */  mtc1  $t9, $f4
/* 049DCC 7F01529C 468042A0 */  cvt.s.w $f10, $f8
/* 049DD0 7F0152A0 44083000 */  mfc1  $t0, $f6
/* 049DD4 7F0152A4 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 049DD8 7F0152A8 000E7B00 */  sll   $t7, $t6, 0xc
/* 049DDC 7F0152AC 01E1C025 */  or    $t8, $t7, $at
/* 049DE0 7F0152B0 468021A0 */  cvt.s.w $f6, $f4
/* 049DE4 7F0152B4 46145402 */  mul.s $f16, $f10, $f20
/* 049DE8 7F0152B8 31090FFF */  andi  $t1, $t0, 0xfff
/* 049DEC 7F0152BC 03095025 */  or    $t2, $t8, $t1
/* 049DF0 7F0152C0 AC6A0000 */  sw    $t2, ($v1)
/* 049DF4 7F0152C4 46143202 */  mul.s $f8, $f6, $f20
/* 049DF8 7F0152C8 4600848D */  trunc.w.s $f18, $f16
/* 049DFC 7F0152CC 4600428D */  trunc.w.s $f10, $f8
/* 049E00 7F0152D0 440D9000 */  mfc1  $t5, $f18
/* 049E04 7F0152D4 44185000 */  mfc1  $t8, $f10
/* 049E08 7F0152D8 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 049E0C 7F0152DC 000E7B00 */  sll   $t7, $t6, 0xc
/* 049E10 7F0152E0 33090FFF */  andi  $t1, $t8, 0xfff
/* 049E14 7F0152E4 01E95025 */  or    $t2, $t7, $t1
/* 049E18 7F0152E8 AC6A0004 */  sw    $t2, 4($v1)
/* 049E1C 7F0152EC 12400026 */  beqz  $s2, .L7F015388
/* 049E20 7F0152F0 AFB100B4 */   sw    $s1, 0xb4($sp)
/* 049E24 7F0152F4 0FC30776 */  jal   langGet
/* 049E28 7F0152F8 34049C58 */   li    $a0, 40024
/* 049E2C 7F0152FC 8FCB0000 */  lw    $t3, ($fp)
/* 049E30 7F015300 00409825 */  move  $s3, $v0
/* 049E34 7F015304 27A400A4 */  addiu $a0, $sp, 0xa4
/* 049E38 7F015308 27A500A0 */  addiu $a1, $sp, 0xa0
/* 049E3C 7F01530C 00403025 */  move  $a2, $v0
/* 049E40 7F015310 8EE70000 */  lw    $a3, ($s7)
/* 049E44 7F015314 AFA00014 */  sw    $zero, 0x14($sp)
/* 049E48 7F015318 0FC2BA63 */  jal   textMeasure
/* 049E4C 7F01531C AFAB0010 */   sw    $t3, 0x10($sp)
/* 049E50 7F015320 8FAC00A0 */  lw    $t4, 0xa0($sp)
/* 049E54 7F015324 AFB00098 */  sw    $s0, 0x98($sp)
/* 049E58 7F015328 000C6843 */  sra   $t5, $t4, 1
/* 049E5C 7F01532C 022D7023 */  subu  $t6, $s1, $t5
/* 049E60 7F015330 0C001107 */  jal   viGetX
/* 049E64 7F015334 AFAE009C */   sw    $t6, 0x9c($sp)
/* 049E68 7F015338 00028400 */  sll   $s0, $v0, 0x10
/* 049E6C 7F01533C 0010CC03 */  sra   $t9, $s0, 0x10
/* 049E70 7F015340 0C00110B */  jal   viGetY
/* 049E74 7F015344 03208025 */   move  $s0, $t9
/* 049E78 7F015348 8EE80000 */  lw    $t0, ($s7)
/* 049E7C 7F01534C 8FD80000 */  lw    $t8, ($fp)
/* 049E80 7F015350 240F00FF */  li    $t7, 255
/* 049E84 7F015354 AFAF0018 */  sw    $t7, 0x18($sp)
/* 049E88 7F015358 02A02025 */  move  $a0, $s5
/* 049E8C 7F01535C 27A5009C */  addiu $a1, $sp, 0x9c
/* 049E90 7F015360 27A60098 */  addiu $a2, $sp, 0x98
/* 049E94 7F015364 02603825 */  move  $a3, $s3
/* 049E98 7F015368 AFB0001C */  sw    $s0, 0x1c($sp)
/* 049E9C 7F01536C AFA20020 */  sw    $v0, 0x20($sp)
/* 049EA0 7F015370 AFA00024 */  sw    $zero, 0x24($sp)
/* 049EA4 7F015374 AFA00028 */  sw    $zero, 0x28($sp)
/* 049EA8 7F015378 AFA80010 */  sw    $t0, 0x10($sp)
/* 049EAC 7F01537C 0FC025D8 */  jal   frontPrintText
/* 049EB0 7F015380 AFB80014 */   sw    $t8, 0x14($sp)
/* 049EB4 7F015384 0040A825 */  move  $s5, $v0
.L7F015388:
/* 049EB8 7F015388 3C098003 */  lui   $t1, %hi(scenario)
/* 049EBC 7F01538C 8D29B540 */  lw    $t1, %lo(scenario)($t1)
/* 049EC0 7F015390 24010005 */  li    $at, 5
/* 049EC4 7F015394 3C0B8007 */  lui   $t3, %hi(teamsize)
/* 049EC8 7F015398 15210009 */  bne   $t1, $at, .L7F0153C0
/* 049ECC 7F01539C 00000000 */   nop
/* 049ED0 7F0153A0 16400005 */  bnez  $s2, .L7F0153B8
/* 049ED4 7F0153A4 02401025 */   move  $v0, $s2
/* 049ED8 7F0153A8 3C0A8007 */  lui   $t2, %hi(teamsize)
/* 049EDC 7F0153AC 8D4A9788 */  lw    $t2, %lo(teamsize)($t2)
/* 049EE0 7F0153B0 028A1026 */  xor   $v0, $s4, $t2
/* 049EE4 7F0153B4 2C420001 */  sltiu $v0, $v0, 1
.L7F0153B8:
/* 049EE8 7F0153B8 10000004 */  b     .L7F0153CC
/* 049EEC 7F0153BC 00408025 */   move  $s0, $v0
.L7F0153C0:
/* 049EF0 7F0153C0 8D6B9788 */  lw    $t3, %lo(teamsize)($t3)
/* 049EF4 7F0153C4 028B8026 */  xor   $s0, $s4, $t3
/* 049EF8 7F0153C8 0010802B */  sltu  $s0, $zero, $s0
.L7F0153CC:
/* 049EFC 7F0153CC 12000005 */  beqz  $s0, .L7F0153E4
/* 049F00 7F0153D0 00000000 */   nop
/* 049F04 7F0153D4 0FC30776 */  jal   langGet
/* 049F08 7F0153D8 34049C59 */   li    $a0, 40025
/* 049F0C 7F0153DC 10000004 */  b     .L7F0153F0
/* 049F10 7F0153E0 00408825 */   move  $s1, $v0
.L7F0153E4:
/* 049F14 7F0153E4 0FC30776 */  jal   langGet
/* 049F18 7F0153E8 34049C5A */   li    $a0, 40026
/* 049F1C 7F0153EC 00408825 */  move  $s1, $v0
.L7F0153F0:
/* 049F20 7F0153F0 12000004 */  beqz  $s0, .L7F015404
/* 049F24 7F0153F4 27A40090 */   addiu $a0, $sp, 0x90
/* 049F28 7F0153F8 3C12FF00 */  lui   $s2, (0xFF0000FF >> 16) # lui $s2, 0xff00
/* 049F2C 7F0153FC 10000002 */  b     .L7F015408
/* 049F30 7F015400 365200FF */   ori   $s2, (0xFF0000FF & 0xFFFF) # ori $s2, $s2, 0xff
.L7F015404:
/* 049F34 7F015404 3412FFFF */  li    $s2, 65535
.L7F015408:
/* 049F38 7F015408 8FCC0000 */  lw    $t4, ($fp)
/* 049F3C 7F01540C 27A5008C */  addiu $a1, $sp, 0x8c
/* 049F40 7F015410 02203025 */  move  $a2, $s1
/* 049F44 7F015414 8EE70000 */  lw    $a3, ($s7)
/* 049F48 7F015418 AFA00014 */  sw    $zero, 0x14($sp)
/* 049F4C 7F01541C 0FC2BA63 */  jal   textMeasure
/* 049F50 7F015420 AFAC0010 */   sw    $t4, 0x10($sp)
/* 049F54 7F015424 8FB80090 */  lw    $t8, 0x90($sp)
/* 049F58 7F015428 8FAE008C */  lw    $t6, 0x8c($sp)
/* 049F5C 7F01542C 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 049F60 7F015430 3C028007 */  lui   $v0, %hi(teamsize)
/* 049F64 7F015434 8C429788 */  lw    $v0, %lo(teamsize)($v0)
/* 049F68 7F015438 00187843 */  sra   $t7, $t8, 1
/* 049F6C 7F01543C 02CF4823 */  subu  $t1, $s6, $t7
/* 049F70 7F015440 000EC843 */  sra   $t9, $t6, 1
/* 049F74 7F015444 252A0046 */  addiu $t2, $t1, 0x46
/* 049F78 7F015448 01B94023 */  subu  $t0, $t5, $t9
/* 049F7C 7F01544C AFA80088 */  sw    $t0, 0x88($sp)
/* 049F80 7F015450 16820007 */  bne   $s4, $v0, .L7F015470
/* 049F84 7F015454 AFAA0084 */   sw    $t2, 0x84($sp)
/* 049F88 7F015458 1682001A */  bne   $s4, $v0, .L7F0154C4
/* 049F8C 7F01545C 3C0B8003 */   lui   $t3, %hi(D_8002B560)
/* 049F90 7F015460 8D6BB560 */  lw    $t3, %lo(D_8002B560)($t3)
/* 049F94 7F015464 2961000A */  slti  $at, $t3, 0xa
/* 049F98 7F015468 50200017 */  beql  $at, $zero, .L7F0154C8
/* 049F9C 7F01546C 8FB900CC */   lw    $t9, 0xcc($sp)
.L7F015470:
/* 049FA0 7F015470 0C001107 */  jal   viGetX
/* 049FA4 7F015474 00000000 */   nop
/* 049FA8 7F015478 00028400 */  sll   $s0, $v0, 0x10
/* 049FAC 7F01547C 00106403 */  sra   $t4, $s0, 0x10
/* 049FB0 7F015480 0C00110B */  jal   viGetY
/* 049FB4 7F015484 01808025 */   move  $s0, $t4
/* 049FB8 7F015488 8EEE0000 */  lw    $t6, ($s7)
/* 049FBC 7F01548C 8FCD0000 */  lw    $t5, ($fp)
/* 049FC0 7F015490 02A02025 */  move  $a0, $s5
/* 049FC4 7F015494 27A50088 */  addiu $a1, $sp, 0x88
/* 049FC8 7F015498 27A60084 */  addiu $a2, $sp, 0x84
/* 049FCC 7F01549C 02203825 */  move  $a3, $s1
/* 049FD0 7F0154A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 049FD4 7F0154A4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 049FD8 7F0154A8 AFA20020 */  sw    $v0, 0x20($sp)
/* 049FDC 7F0154AC AFA00024 */  sw    $zero, 0x24($sp)
/* 049FE0 7F0154B0 AFA00028 */  sw    $zero, 0x28($sp)
/* 049FE4 7F0154B4 AFAE0010 */  sw    $t6, 0x10($sp)
/* 049FE8 7F0154B8 0FC025D8 */  jal   frontPrintText
/* 049FEC 7F0154BC AFAD0014 */   sw    $t5, 0x14($sp)
/* 049FF0 7F0154C0 0040A825 */  move  $s5, $v0
.L7F0154C4:
/* 049FF4 7F0154C4 8FB900CC */  lw    $t9, 0xcc($sp)
.L7F0154C8:
/* 049FF8 7F0154C8 26940001 */  addiu $s4, $s4, 1
/* 049FFC 7F0154CC 5699FF55 */  bnel  $s4, $t9, .L7F015224
/* 04A000 7F0154D0 2A810002 */   slti  $at, $s4, 2
.L7F0154D4:
/* 04A004 7F0154D4 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 04A008 7F0154D8 02A02025 */   move  $a0, $s5
/* 04A00C 7F0154DC 8FBF0064 */  lw    $ra, 0x64($sp)
/* 04A010 7F0154E0 D7B40038 */  ldc1  $f20, 0x38($sp)
/* 04A014 7F0154E4 8FB00040 */  lw    $s0, 0x40($sp)
/* 04A018 7F0154E8 8FB10044 */  lw    $s1, 0x44($sp)
/* 04A01C 7F0154EC 8FB20048 */  lw    $s2, 0x48($sp)
/* 04A020 7F0154F0 8FB3004C */  lw    $s3, 0x4c($sp)
/* 04A024 7F0154F4 8FB40050 */  lw    $s4, 0x50($sp)
/* 04A028 7F0154F8 8FB50054 */  lw    $s5, 0x54($sp)
/* 04A02C 7F0154FC 8FB60058 */  lw    $s6, 0x58($sp)
/* 04A030 7F015500 8FB7005C */  lw    $s7, 0x5c($sp)
/* 04A034 7F015504 8FBE0060 */  lw    $fp, 0x60($sp)
/* 04A038 7F015508 03E00008 */  jr    $ra
/* 04A03C 7F01550C 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#endif



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
                sub_GAME_7F0AEB64(0xDC, (s8*)text, (s8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold);
                setTextWordWrap(0);
            }
            else
            {
                sub_GAME_7F0AEB64(0x140, (s8*)text, (s8*)arg2, ptrFontZurichBoldChars, ptrFontZurichBold);
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
        sub_GAME_7F0AEB64(0x140, (s8*)spC0C, (s8*)&sp4C, ptrFontZurichBoldChars, ptrFontZurichBold);
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

    viSetFovY(60.0f);
    viSetAspect(1.3333334f);
    viSetZRange(100.0f, 10000.0f);
    viSetUseZBuf(0);

    MP_menu_selected_option = 0;

    if (joyGetButtons(PLAYER_1, A_BUTTON|Z_TRIG) == 0)
    {
        tab_prev_highlight = 0;
        tab_next_highlight = 0;
        tab_start_highlight = 0;
        D_8002B5E0 = 0;

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
                            D_8002B5E0 = i + 0xC;
                            break;
                        }
                    }
                }
            }

            if (D_8002B5E0 == 0)
            {
                i = (totalunlockedcheats >= 0xD)
                    ? 0xB
                    : totalunlockedcheats - 1;

                for (; i >= 0; i--)
                {
                    if ((s32) cursor_v_pos >= (i * 0x14) + 0x35)
                    {
                        D_8002B5E0 = i;
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
    i = arrayUnlockedCheats[D_8002B5E0];
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
        if ((var_fp == D_8002B5E0) && (frontCheckCursorOnPreviousTab() == 0))
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
            if ((var_fp + 0xc == D_8002B5E0) && (frontCheckCursorOnPreviousTab() == 0))
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
    DL = microcode_constructor(insert_imageDL(DL));


    if ((numContCon == 0) || (numContCon == 1) || (numContCon == 2) || (numContCon == 3)) {
        text = langGet(getStringID(LTITLE, TITLE_STR_118_NOCONT)); //NO CONTROLLER IN CONTROLLER SOCKET 1
    }
    textMeasure(&y2, &x2, text, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    x = 0xDC - (x2 >> 1);
    y = 0x99 - (y2 >> 1);
#ifdef BUGFIX_R1
    if (j_text_trigger) {
        DL = textRenderGlow(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, 0x8000FF, viGetX(), viGetY(), 0, 0);
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
        DL = textRenderGlow(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, 0x8000FF, viGetX(), viGetY(), 0, 0);
    }
    else {
#endif
        DL = textRender(DL, &x, &y, text, ptrFontZurichBoldChars, ptrFontZurichBold, -1, viGetX(), viGetY(), 0, 0);
#ifdef BUGFIX_R1
    }
#endif

    return DL;
}









void do_extended_cast_display(s32 flag)
{
    full_actor_intro = flag;
    if (flag)
    {
        intro_character_index = 0;
        return;
    }
    intro_character_index = 1;
}

//********************************************************************************************************
//CAST SCREEN
//********************************************************************************************************
#ifdef NONMATCHING

// Address 0x7F01869C NTSC
// Address 0x7F018714 PAL

// https://decomp.me/scratch/MAkgo (PAL) 97.69%
void init_menu18_displaycast(void)
{
    u8 *spB4;
    s32 spB0;
    s32 temp_t0;
    struct coord3d spA0;
    struct texpool sp90;
    enum BODIES sp8C;
    enum HEADS sp88;
    s32 sp84;
    ModelFileHeader *sp80;
    ModelFileHeader *sp7C;
    ModelFileHeader *sp78;
    s32 padding;
    s32 sp70;
    s32 sp6C;
    struct intro_random_rifles sp54;
    struct intro_random_pistols sp2C;

    spB4 = ptr_logo_and_walletbond_DL;

    // struct copy
    spA0 = D_8002BA2C;

    sp7C = NULL;
    sp70 = randomGetNext() & 1;

    if ((full_actor_intro != 0) && (intro_character_index == 0))
    {
        musicTrack1ApplySeqpVol(0x7FFF);
        g_musicXTrack1Fade = 0;
        musicTrack1Play(2);
    }

    for (intro_animation_count = 0; intro_animation_table[intro_animation_count].animID >= 0; intro_animation_count++)
    {
        // this `for` loop just sets intro_animation_count
    }

    randomly_selected_intro_animation = randomGetNext() % (u32) intro_animation_count;

    sp8C = intro_char_table[intro_character_index].body;
    sp88 = intro_char_table[intro_character_index].head;

    sp6C = intro_animation_table[randomly_selected_intro_animation].camera_preset;

    if (sp8C == BODY_Special_Operations_Uniform)
    {
        switch (randomGetNext() % 5U)
        {
            case 0:
            break;

            case 1:
                sp8C = BODY_Formal_Wear;\
                sp88 = HEAD_Male_Brosnan_Default;
            break;

            case 2:
                sp8C = BODY_Jungle_Fatigues;\
                sp88 = HEAD_Male_Brosnan_Default;
            break;

            case 3:
                sp8C = BODY_Parka;\
                sp88 = HEAD_Male_Brosnan_Default;
            break;

            case 4:
                sp8C = BODY_Brosnan_Tuxedo;\
                sp88 = HEAD_Male_Brosnan_Tuxedo;
            break;
        }
    }
    else if (sp8C == BODY_Natalya_Skirt)
    {
        if (randomGetNext() & 1)
        {
            sp8C = BODY_Natalya_Jungle_Fatigues;
        }
    }
    else if (sp8C == BODY_Trevelyan_006 && randomGetNext() & 1)
    {
        sp8C = BODY_Trevelyan_Janus;
    }

    if (sp88 == -0x61)
    {
        sp88 = get_random_head(sp8C);
    }

    // begin problem area

    temp_t0 = 0x19000;
    spB0 = 0x18160 + temp_t0;

    if(0);

    zbufSetBuffer(ALIGN64_V2(spB4 + spB0), 440, 330);
    texInitPool(&sp90, spB4, temp_t0);

    spB0 -= temp_t0;
    spB4 += temp_t0;

    sp80 = c_item_entries[sp8C].header;

    // can't get subu a3,a3,v1

    load_object_fill_header(c_item_entries[sp8C].header, c_item_entries[sp8C].filename, spB4, spB0, &sp90);
    temp_t0 = ALIGN64_V2(get_pc_buffer_remaining_value(c_item_entries[sp8C].filename));

    // end problem area

    spB0 -= temp_t0;
    spB4 += temp_t0;

    if (sp88 >= 0)
    {
        sp7C = c_item_entries[sp88].header;

        load_object_fill_header(c_item_entries[sp88].header, c_item_entries[sp88].filename, spB4, spB0, &sp90);
        temp_t0 = ALIGN64_V2(get_pc_buffer_remaining_value(c_item_entries[sp88].filename));

        spB0 -= temp_t0;
        spB4 += temp_t0;
    }

    cast_model = setup_chr_instance(sp8C, sp88, sp80, sp7C, 0);
    modelSetScale((Model *) cast_model, 0.1f);

    if (sp6C != 0)
    {
        if (sp6C == 2)
        {
            // struct copy
            sp54 = random_rifles_in_intro;

            sp84 = sp54.props[randomGetNext() % INTRO_RANDOM_RIFLE_LEN];
        }
        else
        {
            // struct copy
            sp2C = random_pistols_in_intro;

            sp84 = sp2C.props[randomGetNext() % INTRO_RANDOM_PISTO_LEN];
        }

        if (sp84 == PROP_CHRRUGER) // Cougar Magnum
        {
            if (fileIsCradleCompletedAnyFolder() == 0)
            {
                sp84 = PROP_CHRWPPK;
            }
        }

        if (sp84 == PROP_CHRLASER)
        {
            if (check_aztec_completed_any_folder_secret_00() == 0)
            {
                sp84 = PROP_CHRWPPK;
            }
        }

        if (sp84 == PROP_CHRGOLDEN)
        {
            if (fileIsEgyptCompletedOn00AnyFolder() == 0)
            {
                sp84 = PROP_CHRWPPK;
            }
        }

        //temp_v0_4 = &PitemZ_entries[sp84];
        sp78 = PitemZ_entries[sp84].header;

        load_object_fill_header(sp78, PitemZ_entries[sp84].filename, spB4, spB0, &sp90);
        temp_t0 = ALIGN64_V2(get_pc_buffer_remaining_value(PitemZ_entries[sp84].filename));
        spB0 -= temp_t0;
        spB4 += temp_t0;

        modelCalculateRwDataLen(sp78);
        cast_model_weapon = get_obj_instance_controller_for_header(sp78);
        modelSetScale((Model *) cast_model_weapon, 0.1f);

        cast_model_weapon->attachedto = cast_model;
        //var_v0_2 = (sp70 != 0) ? 5 : 3;
        cast_model_weapon->attachedto_objinst = cast_model->obj->Switches[(sp70 != 0) ? 5 : 3];
    }
    else
    {
        cast_model_weapon = NULL;
    }

    sub_GAME_7F06CE84(cast_model, 0.1f);
    setsuboffset(cast_model, &spA0);
    setsubroty(cast_model, 0.0f);
#if defined(VERSION_EU)
    modelSetAnimPlaySpeed(cast_model, 0.600000023842f, 0);
#else
    modelSetAnimPlaySpeed(cast_model, 0.5f, 0);
#endif

    modelSetAnimation(
        cast_model,
        animation_table_ptrs1[intro_animation_table[randomly_selected_intro_animation].animID],
        sp70,
        intro_animation_table[randomly_selected_intro_animation].startframeoffset,
        intro_animation_table[randomly_selected_intro_animation].playback_speed,
        0.0f);

    g_MenuTimer = 0;

    flt_CODE_bss_800695A4 = (RANDOMGETNEXT_F32() * 80.0f) + 70.0f;
    flt_CODE_bss_800695A8 = (RANDOMGETNEXT_F32() * 80.0f) + 70.0f;
    flt_CODE_bss_800695B0 = (RANDOMGETNEXT_F32() - 0.5f) * 6.2831855f;
    flt_CODE_bss_800695B4 = (RANDOMGETNEXT_F32() - 0.5f) * 2.5132742f;
    flt_CODE_bss_800695BC = (RANDOMGETNEXT_F32() * 200.0f) + (-100.0f);
    flt_CODE_bss_800695C0 = (RANDOMGETNEXT_F32() * 200.0f) + (-100.0f);
    flt_CODE_bss_800695A0 = flt_CODE_bss_800695A4;
    flt_CODE_bss_800695AC = flt_CODE_bss_800695B0;
    flt_CODE_bss_800695B8 = flt_CODE_bss_800695BC;
    bss_800695E4 = 1;
    flt_CODE_bss_800695E8.f[0] = 0.0f;
    flt_CODE_bss_800695E8.f[1] = 0.0f;
    flt_CODE_bss_800695E8.f[2] = 0.0f;
}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel jpt_intro_bond_head
 .word .L7F0188C0
 .word .L7F01881C
 .word .L7F018830
 .word .L7F018844
 .word .L7F018858
 .size jpt_intro_bond_head, . - jpt_intro_bond_head

glabel D_80051B00
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B04
.word 0x4020D97C /*2.5132742;*/


.text
glabel init_menu18_displaycast
/* 04D1CC 7F01869C 3C0E8003 */  lui   $t6, %hi(ptr_logo_and_walletbond_DL)
/* 04D1D0 7F0186A0 8DCEA950 */  lw    $t6, %lo(ptr_logo_and_walletbond_DL)($t6)
/* 04D1D4 7F0186A4 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 04D1D8 7F0186A8 3C188003 */  lui   $t8, %hi(D_8002BA2C)
/* 04D1DC 7F0186AC AFBF001C */  sw    $ra, 0x1c($sp)
/* 04D1E0 7F0186B0 2718BA2C */  addiu $t8, %lo(D_8002BA2C) # addiu $t8, $t8, -0x45d4
/* 04D1E4 7F0186B4 AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 04D1E8 7F0186B8 8F010000 */  lw    $at, ($t8)
/* 04D1EC 7F0186BC 27AF00A0 */  addiu $t7, $sp, 0xa0
/* 04D1F0 7F0186C0 8F090004 */  lw    $t1, 4($t8)
/* 04D1F4 7F0186C4 ADE10000 */  sw    $at, ($t7)
/* 04D1F8 7F0186C8 8F010008 */  lw    $at, 8($t8)
/* 04D1FC 7F0186CC ADE90004 */  sw    $t1, 4($t7)
/* 04D200 7F0186D0 ADE10008 */  sw    $at, 8($t7)
/* 04D204 7F0186D4 0C002914 */  jal   randomGetNext
/* 04D208 7F0186D8 AFA0007C */   sw    $zero, 0x7c($sp)
/* 04D20C 7F0186DC 3C0B8003 */  lui   $t3, %hi(full_actor_intro)
/* 04D210 7F0186E0 8D6BB5FC */  lw    $t3, %lo(full_actor_intro)($t3)
/* 04D214 7F0186E4 304A0001 */  andi  $t2, $v0, 1
/* 04D218 7F0186E8 AFAA0070 */  sw    $t2, 0x70($sp)
/* 04D21C 7F0186EC 1160000A */  beqz  $t3, .L7F018718
/* 04D220 7F0186F0 3C0C8003 */   lui   $t4, %hi(intro_character_index)
/* 04D224 7F0186F4 8D8CB5E8 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04D228 7F0186F8 15800007 */  bnez  $t4, .L7F018718
/* 04D22C 7F0186FC 00000000 */   nop
/* 04D230 7F018700 0C001C0F */  jal   musicTrack1ApplySeqpVol
/* 04D234 7F018704 24047FFF */   li    $a0, 32767
/* 04D238 7F018708 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade)
/* 04D23C 7F01870C AC20434C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 04D240 7F018710 0C001B9F */  jal   musicTrack1Play
/* 04D244 7F018714 24040002 */   li    $a0, 2
.L7F018718:
/* 04D248 7F018718 3C048003 */  lui   $a0, %hi(intro_animation_table)
/* 04D24C 7F01871C 2484B8BC */  addiu $a0, %lo(intro_animation_table) # addiu $a0, $a0, -0x4744
/* 04D250 7F018720 00006900 */  sll   $t5, $zero, 4
/* 04D254 7F018724 008D7021 */  addu  $t6, $a0, $t5
/* 04D258 7F018728 8DC80000 */  lw    $t0, ($t6)
/* 04D25C 7F01872C 3C038003 */  lui   $v1, %hi(intro_animation_count)
/* 04D260 7F018730 2463B5F0 */  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, -0x4a10
/* 04D264 7F018734 AC600000 */  sw    $zero, ($v1)
/* 04D268 7F018738 05000009 */  bltz  $t0, .L7F018760
/* 04D26C 7F01873C 00001025 */   move  $v0, $zero
/* 04D270 7F018740 24590001 */  addiu $t9, $v0, 1
.L7F018744:
/* 04D274 7F018744 00197900 */  sll   $t7, $t9, 4
/* 04D278 7F018748 008FC021 */  addu  $t8, $a0, $t7
/* 04D27C 7F01874C 8F090000 */  lw    $t1, ($t8)
/* 04D280 7F018750 AC790000 */  sw    $t9, ($v1)
/* 04D284 7F018754 03201025 */  move  $v0, $t9
/* 04D288 7F018758 0523FFFA */  bgezl $t1, .L7F018744
/* 04D28C 7F01875C 24590001 */   addiu $t9, $v0, 1
.L7F018760:
/* 04D290 7F018760 0C002914 */  jal   randomGetNext
/* 04D294 7F018764 00000000 */   nop
/* 04D298 7F018768 3C038003 */  lui   $v1, %hi(intro_animation_count)
/* 04D29C 7F01876C 2463B5F0 */  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, -0x4a10
/* 04D2A0 7F018770 8C6A0000 */  lw    $t2, ($v1)
/* 04D2A4 7F018774 3C0C8003 */  lui   $t4, %hi(intro_character_index)
/* 04D2A8 7F018778 8D8CB5E8 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04D2AC 7F01877C 004A001B */  divu  $zero, $v0, $t2
/* 04D2B0 7F018780 00005810 */  mfhi  $t3
/* 04D2B4 7F018784 3C018003 */  lui   $at, %hi(randomly_selected_intro_animation)
/* 04D2B8 7F018788 AC2BB5EC */  sw    $t3, %lo(randomly_selected_intro_animation)($at)
/* 04D2BC 7F01878C 3C0F8003 */  lui   $t7, %hi(randomly_selected_intro_animation)
/* 04D2C0 7F018790 000C6880 */  sll   $t5, $t4, 2
/* 04D2C4 7F018794 8DEFB5EC */  lw    $t7, %lo(randomly_selected_intro_animation)($t7)
/* 04D2C8 7F018798 3C0E8003 */  lui   $t6, %hi(intro_char_table)
/* 04D2CC 7F01879C 01AC6821 */  addu  $t5, $t5, $t4
/* 04D2D0 7F0187A0 000D6880 */  sll   $t5, $t5, 2
/* 04D2D4 7F0187A4 25CEB600 */  addiu $t6, %lo(intro_char_table) # addiu $t6, $t6, -0x4a00
/* 04D2D8 7F0187A8 01AE2021 */  addu  $a0, $t5, $t6
/* 04D2DC 7F0187AC 8C880000 */  lw    $t0, ($a0)
/* 04D2E0 7F0187B0 3C098003 */  lui   $t1, %hi(intro_animation_table+12)
/* 04D2E4 7F0187B4 000FC100 */  sll   $t8, $t7, 4
/* 04D2E8 7F0187B8 01384821 */  addu  $t1, $t1, $t8
/* 04D2EC 7F0187BC 8C990004 */  lw    $t9, 4($a0)
/* 04D2F0 7F0187C0 8D29B8C8 */  lw    $t1, %lo(intro_animation_table+12)($t1)
/* 04D2F4 7F0187C4 24010016 */  li    $at, 22
/* 04D2F8 7F0187C8 15400002 */  bnez  $t2, .L7F0187D4
/* 04D2FC 7F0187CC 00000000 */   nop
/* 04D300 7F0187D0 0007000D */  break 7
.L7F0187D4:
/* 04D304 7F0187D4 AFA8008C */  sw    $t0, 0x8c($sp)
/* 04D308 7F0187D8 01005025 */  move  $t2, $t0
/* 04D30C 7F0187DC AFB90088 */  sw    $t9, 0x88($sp)
/* 04D310 7F0187E0 15010022 */  bne   $t0, $at, .L7F01886C
/* 04D314 7F0187E4 AFA9006C */   sw    $t1, 0x6c($sp)
/* 04D318 7F0187E8 0C002914 */  jal   randomGetNext
/* 04D31C 7F0187EC 00000000 */   nop
/* 04D320 7F0187F0 24010005 */  li    $at, 5
/* 04D324 7F0187F4 0041001B */  divu  $zero, $v0, $at
/* 04D328 7F0187F8 00005810 */  mfhi  $t3
/* 04D32C 7F0187FC 2D610005 */  sltiu $at, $t3, 5
/* 04D330 7F018800 1020002F */  beqz  $at, .L7F0188C0
/* 04D334 7F018804 000B5880 */   sll   $t3, $t3, 2
/* 04D338 7F018808 3C018005 */  lui   $at, %hi(jpt_intro_bond_head)
/* 04D33C 7F01880C 002B0821 */  addu  $at, $at, $t3
/* 04D340 7F018810 8C2B1AEC */  lw    $t3, %lo(jpt_intro_bond_head)($at)
/* 04D344 7F018814 01600008 */  jr    $t3
/* 04D348 7F018818 00000000 */   nop
.L7F01881C:
/* 04D34C 7F01881C 240C0017 */  li    $t4, 23
/* 04D350 7F018820 240D004B */  li    $t5, 75
/* 04D354 7F018824 AFAD0088 */  sw    $t5, 0x88($sp)
/* 04D358 7F018828 10000025 */  b     .L7F0188C0
/* 04D35C 7F01882C AFAC008C */   sw    $t4, 0x8c($sp)
.L7F018830:
/* 04D360 7F018830 240E0018 */  li    $t6, 24
/* 04D364 7F018834 2408004B */  li    $t0, 75
/* 04D368 7F018838 AFA80088 */  sw    $t0, 0x88($sp)
/* 04D36C 7F01883C 10000020 */  b     .L7F0188C0
/* 04D370 7F018840 AFAE008C */   sw    $t6, 0x8c($sp)
.L7F018844:
/* 04D374 7F018844 24190019 */  li    $t9, 25
/* 04D378 7F018848 240F004B */  li    $t7, 75
/* 04D37C 7F01884C AFAF0088 */  sw    $t7, 0x88($sp)
/* 04D380 7F018850 1000001B */  b     .L7F0188C0
/* 04D384 7F018854 AFB9008C */   sw    $t9, 0x8c($sp)
.L7F018858:
/* 04D388 7F018858 24180005 */  li    $t8, 5
/* 04D38C 7F01885C 2409004E */  li    $t1, 78
/* 04D390 7F018860 AFA90088 */  sw    $t1, 0x88($sp)
/* 04D394 7F018864 10000016 */  b     .L7F0188C0
/* 04D398 7F018868 AFB8008C */   sw    $t8, 0x8c($sp)
.L7F01886C:
/* 04D39C 7F01886C 8FAA008C */  lw    $t2, 0x8c($sp)
/* 04D3A0 7F018870 24010010 */  li    $at, 16
/* 04D3A4 7F018874 8FAD008C */  lw    $t5, 0x8c($sp)
/* 04D3A8 7F018878 55410009 */  bnel  $t2, $at, .L7F0188A0
/* 04D3AC 7F01887C 24010009 */   li    $at, 9
/* 04D3B0 7F018880 0C002914 */  jal   randomGetNext
/* 04D3B4 7F018884 00000000 */   nop
/* 04D3B8 7F018888 304B0001 */  andi  $t3, $v0, 1
/* 04D3BC 7F01888C 1160000C */  beqz  $t3, .L7F0188C0
/* 04D3C0 7F018890 240C004F */   li    $t4, 79
/* 04D3C4 7F018894 1000000A */  b     .L7F0188C0
/* 04D3C8 7F018898 AFAC008C */   sw    $t4, 0x8c($sp)
/* 04D3CC 7F01889C 24010009 */  li    $at, 9
.L7F0188A0:
/* 04D3D0 7F0188A0 55A10008 */  bnel  $t5, $at, .L7F0188C4
/* 04D3D4 7F0188A4 8FB90088 */   lw    $t9, 0x88($sp)
/* 04D3D8 7F0188A8 0C002914 */  jal   randomGetNext
/* 04D3DC 7F0188AC 00000000 */   nop
/* 04D3E0 7F0188B0 304E0001 */  andi  $t6, $v0, 1
/* 04D3E4 7F0188B4 11C00002 */  beqz  $t6, .L7F0188C0
/* 04D3E8 7F0188B8 24080008 */   li    $t0, 8
/* 04D3EC 7F0188BC AFA8008C */  sw    $t0, 0x8c($sp)
.L7F0188C0:
/* 04D3F0 7F0188C0 8FB90088 */  lw    $t9, 0x88($sp)
.L7F0188C4:
/* 04D3F4 7F0188C4 2401FF9F */  li    $at, -97
/* 04D3F8 7F0188C8 57210005 */  bnel  $t9, $at, .L7F0188E0
/* 04D3FC 7F0188CC 8FAF00B4 */   lw    $t7, 0xb4($sp)
/* 04D400 7F0188D0 0FC08D98 */  jal   get_random_head
/* 04D404 7F0188D4 8FA4008C */   lw    $a0, 0x8c($sp)
/* 04D408 7F0188D8 AFA20088 */  sw    $v0, 0x88($sp)
/* 04D40C 7F0188DC 8FAF00B4 */  lw    $t7, 0xb4($sp)
.L7F0188E0:
/* 04D410 7F0188E0 3C020003 */  lui   $v0, (0x00031160 >> 16) # lui $v0, 3
/* 04D414 7F0188E4 34421160 */  ori   $v0, (0x00031160 & 0xFFFF) # ori $v0, $v0, 0x1160
/* 04D418 7F0188E8 01E22021 */  addu  $a0, $t7, $v0
/* 04D41C 7F0188EC 2484003F */  addiu $a0, $a0, 0x3f
/* 04D420 7F0188F0 3498003F */  ori   $t8, $a0, 0x3f
/* 04D424 7F0188F4 3B04003F */  xori  $a0, $t8, 0x3f
/* 04D428 7F0188F8 AFA200B0 */  sw    $v0, 0xb0($sp)
/* 04D42C 7F0188FC 240501B8 */  li    $a1, 440
/* 04D430 7F018900 0FC34912 */  jal   zbufSetBuffer
/* 04D434 7F018904 2406014A */   li    $a2, 330
/* 04D438 7F018908 3C060001 */  lui   $a2, (0x00019000 >> 16) # lui $a2, 1
/* 04D43C 7F01890C 34C69000 */  ori   $a2, (0x00019000 & 0xFFFF) # ori $a2, $a2, 0x9000
/* 04D440 7F018910 27A40090 */  addiu $a0, $sp, 0x90
/* 04D444 7F018914 0FC32EBD */  jal   texInitPool
/* 04D448 7F018918 8FA500B4 */   lw    $a1, 0xb4($sp)
/* 04D44C 7F01891C 8FAA008C */  lw    $t2, 0x8c($sp)
/* 04D450 7F018920 3C0C8004 */  lui   $t4, %hi(c_item_entries)
/* 04D454 7F018924 8FA600B4 */  lw    $a2, 0xb4($sp)
/* 04D458 7F018928 000A5880 */  sll   $t3, $t2, 2
/* 04D45C 7F01892C 016A5821 */  addu  $t3, $t3, $t2
/* 04D460 7F018930 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 04D464 7F018934 3C030001 */  lui   $v1, (0x00019000 >> 16) # lui $v1, 1
/* 04D468 7F018938 000B5880 */  sll   $t3, $t3, 2
/* 04D46C 7F01893C 258CDE10 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
/* 04D470 7F018940 34639000 */  ori   $v1, (0x00019000 & 0xFFFF) # ori $v1, $v1, 0x9000
/* 04D474 7F018944 016C1021 */  addu  $v0, $t3, $t4
/* 04D478 7F018948 8C440000 */  lw    $a0, ($v0)
/* 04D47C 7F01894C 27AD0090 */  addiu $t5, $sp, 0x90
/* 04D480 7F018950 00C33021 */  addu  $a2, $a2, $v1
/* 04D484 7F018954 00E33823 */  subu  $a3, $a3, $v1
/* 04D488 7F018958 AFA700B0 */  sw    $a3, 0xb0($sp)
/* 04D48C 7F01895C AFA600B4 */  sw    $a2, 0xb4($sp)
/* 04D490 7F018960 AFAD0010 */  sw    $t5, 0x10($sp)
/* 04D494 7F018964 8C450004 */  lw    $a1, 4($v0)
/* 04D498 7F018968 AFA20024 */  sw    $v0, 0x24($sp)
/* 04D49C 7F01896C 0FC1D929 */  jal   load_object_fill_header
/* 04D4A0 7F018970 AFA40080 */   sw    $a0, 0x80($sp)
/* 04D4A4 7F018974 8FA20024 */  lw    $v0, 0x24($sp)
/* 04D4A8 7F018978 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 04D4AC 7F01897C 8C440004 */   lw    $a0, 4($v0)
/* 04D4B0 7F018980 2443003F */  addiu $v1, $v0, 0x3f
/* 04D4B4 7F018984 8FB900B0 */  lw    $t9, 0xb0($sp)
/* 04D4B8 7F018988 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 04D4BC 7F01898C 346E003F */  ori   $t6, $v1, 0x3f
/* 04D4C0 7F018990 8FAA0088 */  lw    $t2, 0x88($sp)
/* 04D4C4 7F018994 39C8003F */  xori  $t0, $t6, 0x3f
/* 04D4C8 7F018998 03287823 */  subu  $t7, $t9, $t0
/* 04D4CC 7F01899C 03084821 */  addu  $t1, $t8, $t0
/* 04D4D0 7F0189A0 AFAF00B0 */  sw    $t7, 0xb0($sp)
/* 04D4D4 7F0189A4 0540001C */  bltz  $t2, .L7F018A18
/* 04D4D8 7F0189A8 AFA900B4 */   sw    $t1, 0xb4($sp)
/* 04D4DC 7F0189AC 000A5880 */  sll   $t3, $t2, 2
/* 04D4E0 7F0189B0 016A5821 */  addu  $t3, $t3, $t2
/* 04D4E4 7F0189B4 3C0C8004 */  lui   $t4, %hi(c_item_entries)
/* 04D4E8 7F0189B8 258CDE10 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
/* 04D4EC 7F0189BC 000B5880 */  sll   $t3, $t3, 2
/* 04D4F0 7F0189C0 016C1021 */  addu  $v0, $t3, $t4
/* 04D4F4 7F0189C4 8C440000 */  lw    $a0, ($v0)
/* 04D4F8 7F0189C8 27AD0090 */  addiu $t5, $sp, 0x90
/* 04D4FC 7F0189CC AFAD0010 */  sw    $t5, 0x10($sp)
/* 04D500 7F0189D0 8C450004 */  lw    $a1, 4($v0)
/* 04D504 7F0189D4 AFA20024 */  sw    $v0, 0x24($sp)
/* 04D508 7F0189D8 01203025 */  move  $a2, $t1
/* 04D50C 7F0189DC 01E03825 */  move  $a3, $t7
/* 04D510 7F0189E0 0FC1D929 */  jal   load_object_fill_header
/* 04D514 7F0189E4 AFA4007C */   sw    $a0, 0x7c($sp)
/* 04D518 7F0189E8 8FA20024 */  lw    $v0, 0x24($sp)
/* 04D51C 7F0189EC 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 04D520 7F0189F0 8C440004 */   lw    $a0, 4($v0)
/* 04D524 7F0189F4 2443003F */  addiu $v1, $v0, 0x3f
/* 04D528 7F0189F8 8FB900B0 */  lw    $t9, 0xb0($sp)
/* 04D52C 7F0189FC 8FAA00B4 */  lw    $t2, 0xb4($sp)
/* 04D530 7F018A00 346E003F */  ori   $t6, $v1, 0x3f
/* 04D534 7F018A04 39C8003F */  xori  $t0, $t6, 0x3f
/* 04D538 7F018A08 0328C023 */  subu  $t8, $t9, $t0
/* 04D53C 7F018A0C 01485821 */  addu  $t3, $t2, $t0
/* 04D540 7F018A10 AFB800B0 */  sw    $t8, 0xb0($sp)
/* 04D544 7F018A14 AFAB00B4 */  sw    $t3, 0xb4($sp)
.L7F018A18:
/* 04D548 7F018A18 8FA4008C */  lw    $a0, 0x8c($sp)
/* 04D54C 7F018A1C 8FA50088 */  lw    $a1, 0x88($sp)
/* 04D550 7F018A20 8FA60080 */  lw    $a2, 0x80($sp)
/* 04D554 7F018A24 8FA7007C */  lw    $a3, 0x7c($sp)
/* 04D558 7F018A28 0FC08D2A */  jal   setup_chr_instance
/* 04D55C 7F018A2C AFA00010 */   sw    $zero, 0x10($sp)
/* 04D560 7F018A30 3C038003 */  lui   $v1, %hi(cast_model)
/* 04D564 7F018A34 2463B5F4 */  addiu $v1, %lo(cast_model) # addiu $v1, $v1, -0x4a0c
/* 04D568 7F018A38 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04D56C 7F018A3C AC620000 */  sw    $v0, ($v1)
/* 04D570 7F018A40 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04D574 7F018A44 0FC1B39E */  jal   modelSetScale
/* 04D578 7F018A48 00402025 */   move  $a0, $v0
/* 04D57C 7F018A4C 8FAC006C */  lw    $t4, 0x6c($sp)
/* 04D580 7F018A50 24010002 */  li    $at, 2
/* 04D584 7F018A54 1180007A */  beqz  $t4, .L7F018C40
/* 04D588 7F018A58 00000000 */   nop
/* 04D58C 7F018A5C 15810018 */  bne   $t4, $at, .L7F018AC0
/* 04D590 7F018A60 27B8002C */   addiu $t8, $sp, 0x2c
/* 04D594 7F018A64 3C0F8003 */  lui   $t7, %hi(random_rifles_in_intro)
/* 04D598 7F018A68 25EFBA38 */  addiu $t7, %lo(random_rifles_in_intro) # addiu $t7, $t7, -0x45c8
/* 04D59C 7F018A6C 8DE10000 */  lw    $at, ($t7)
/* 04D5A0 7F018A70 8DEE0004 */  lw    $t6, 4($t7)
/* 04D5A4 7F018A74 27A90054 */  addiu $t1, $sp, 0x54
/* 04D5A8 7F018A78 AD210000 */  sw    $at, ($t1)
/* 04D5AC 7F018A7C AD2E0004 */  sw    $t6, 4($t1)
/* 04D5B0 7F018A80 8DEE000C */  lw    $t6, 0xc($t7)
/* 04D5B4 7F018A84 8DE10008 */  lw    $at, 8($t7)
/* 04D5B8 7F018A88 AD2E000C */  sw    $t6, 0xc($t1)
/* 04D5BC 7F018A8C AD210008 */  sw    $at, 8($t1)
/* 04D5C0 7F018A90 8DE10010 */  lw    $at, 0x10($t7)
/* 04D5C4 7F018A94 8DEE0014 */  lw    $t6, 0x14($t7)
/* 04D5C8 7F018A98 AD210010 */  sw    $at, 0x10($t1)
/* 04D5CC 7F018A9C 0C002914 */  jal   randomGetNext
/* 04D5D0 7F018AA0 AD2E0014 */   sw    $t6, 0x14($t1)
/* 04D5D4 7F018AA4 24010006 */  li    $at, 6
/* 04D5D8 7F018AA8 0041001B */  divu  $zero, $v0, $at
/* 04D5DC 7F018AAC 00004010 */  mfhi  $t0
/* 04D5E0 7F018AB0 0008C880 */  sll   $t9, $t0, 2
/* 04D5E4 7F018AB4 03B91821 */  addu  $v1, $sp, $t9
/* 04D5E8 7F018AB8 10000016 */  b     .L7F018B14
/* 04D5EC 7F018ABC 8C630054 */   lw    $v1, 0x54($v1)
.L7F018AC0:
/* 04D5F0 7F018AC0 3C0A8003 */  lui   $t2, %hi(random_pistols_in_intro)
/* 04D5F4 7F018AC4 254ABA50 */  addiu $t2, %lo(random_pistols_in_intro) # addiu $t2, $t2, -0x45b0
/* 04D5F8 7F018AC8 254C0024 */  addiu $t4, $t2, 0x24
.L7F018ACC:
/* 04D5FC 7F018ACC 8D410000 */  lw    $at, ($t2)
/* 04D600 7F018AD0 254A000C */  addiu $t2, $t2, 0xc
/* 04D604 7F018AD4 2718000C */  addiu $t8, $t8, 0xc
/* 04D608 7F018AD8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 04D60C 7F018ADC 8D41FFF8 */  lw    $at, -8($t2)
/* 04D610 7F018AE0 AF01FFF8 */  sw    $at, -8($t8)
/* 04D614 7F018AE4 8D41FFFC */  lw    $at, -4($t2)
/* 04D618 7F018AE8 154CFFF8 */  bne   $t2, $t4, .L7F018ACC
/* 04D61C 7F018AEC AF01FFFC */   sw    $at, -4($t8)
/* 04D620 7F018AF0 8D410000 */  lw    $at, ($t2)
/* 04D624 7F018AF4 0C002914 */  jal   randomGetNext
/* 04D628 7F018AF8 AF010000 */   sw    $at, ($t8)
/* 04D62C 7F018AFC 2401000A */  li    $at, 10
/* 04D630 7F018B00 0041001B */  divu  $zero, $v0, $at
/* 04D634 7F018B04 00006810 */  mfhi  $t5
/* 04D638 7F018B08 000D4880 */  sll   $t1, $t5, 2
/* 04D63C 7F018B0C 03A91821 */  addu  $v1, $sp, $t1
/* 04D640 7F018B10 8C63002C */  lw    $v1, 0x2c($v1)
.L7F018B14:
/* 04D644 7F018B14 240100BE */  li    $at, 190
/* 04D648 7F018B18 54610007 */  bnel  $v1, $at, .L7F018B38
/* 04D64C 7F018B1C 240100BB */   li    $at, 187
/* 04D650 7F018B20 0FC07AB4 */  jal   fileIsCradleCompletedAnyFolder
/* 04D654 7F018B24 AFA30084 */   sw    $v1, 0x84($sp)
/* 04D658 7F018B28 14400002 */  bnez  $v0, .L7F018B34
/* 04D65C 7F018B2C 8FA30084 */   lw    $v1, 0x84($sp)
/* 04D660 7F018B30 240300BF */  li    $v1, 191
.L7F018B34:
/* 04D664 7F018B34 240100BB */  li    $at, 187
.L7F018B38:
/* 04D668 7F018B38 54610007 */  bnel  $v1, $at, .L7F018B58
/* 04D66C 7F018B3C 240100D0 */   li    $at, 208
/* 04D670 7F018B40 0FC07AC8 */  jal   check_aztec_completed_any_folder_secret_00
/* 04D674 7F018B44 AFA30084 */   sw    $v1, 0x84($sp)
/* 04D678 7F018B48 14400002 */  bnez  $v0, .L7F018B54
/* 04D67C 7F018B4C 8FA30084 */   lw    $v1, 0x84($sp)
/* 04D680 7F018B50 240300BF */  li    $v1, 191
.L7F018B54:
/* 04D684 7F018B54 240100D0 */  li    $at, 208
.L7F018B58:
/* 04D688 7F018B58 54610007 */  bnel  $v1, $at, .L7F018B78
/* 04D68C 7F018B5C 00037880 */   sll   $t7, $v1, 2
/* 04D690 7F018B60 0FC07ADC */  jal   fileIsEgyptCompletedOn00AnyFolder
/* 04D694 7F018B64 AFA30084 */   sw    $v1, 0x84($sp)
/* 04D698 7F018B68 14400002 */  bnez  $v0, .L7F018B74
/* 04D69C 7F018B6C 8FA30084 */   lw    $v1, 0x84($sp)
/* 04D6A0 7F018B70 240300BF */  li    $v1, 191
.L7F018B74:
/* 04D6A4 7F018B74 00037880 */  sll   $t7, $v1, 2
.L7F018B78:
/* 04D6A8 7F018B78 01E37823 */  subu  $t7, $t7, $v1
/* 04D6AC 7F018B7C 3C0E8004 */  lui   $t6, %hi(PitemZ_entries)
/* 04D6B0 7F018B80 25CEA228 */  addiu $t6, %lo(PitemZ_entries) # addiu $t6, $t6, -0x5dd8
/* 04D6B4 7F018B84 000F7880 */  sll   $t7, $t7, 2
/* 04D6B8 7F018B88 01EE1021 */  addu  $v0, $t7, $t6
/* 04D6BC 7F018B8C 8C440000 */  lw    $a0, ($v0)
/* 04D6C0 7F018B90 27A80090 */  addiu $t0, $sp, 0x90
/* 04D6C4 7F018B94 AFA80010 */  sw    $t0, 0x10($sp)
/* 04D6C8 7F018B98 8C450004 */  lw    $a1, 4($v0)
/* 04D6CC 7F018B9C AFA20024 */  sw    $v0, 0x24($sp)
/* 04D6D0 7F018BA0 8FA600B4 */  lw    $a2, 0xb4($sp)
/* 04D6D4 7F018BA4 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 04D6D8 7F018BA8 0FC1D929 */  jal   load_object_fill_header
/* 04D6DC 7F018BAC AFA40078 */   sw    $a0, 0x78($sp)
/* 04D6E0 7F018BB0 8FA20024 */  lw    $v0, 0x24($sp)
/* 04D6E4 7F018BB4 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 04D6E8 7F018BB8 8C440004 */   lw    $a0, 4($v0)
/* 04D6EC 7F018BBC 0FC1D73D */  jal   modelCalculateRwDataLen
/* 04D6F0 7F018BC0 8FA40078 */   lw    $a0, 0x78($sp)
/* 04D6F4 7F018BC4 0FC1B025 */  jal   get_obj_instance_controller_for_header
/* 04D6F8 7F018BC8 8FA40078 */   lw    $a0, 0x78($sp)
/* 04D6FC 7F018BCC 3C038003 */  lui   $v1, %hi(cast_model_weapon)
/* 04D700 7F018BD0 2463B5F8 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, -0x4a08
/* 04D704 7F018BD4 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04D708 7F018BD8 AC620000 */  sw    $v0, ($v1)
/* 04D70C 7F018BDC 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04D710 7F018BE0 0FC1B39E */  jal   modelSetScale
/* 04D714 7F018BE4 00402025 */   move  $a0, $v0
/* 04D718 7F018BE8 3C038003 */  lui   $v1, %hi(cast_model_weapon)
/* 04D71C 7F018BEC 3C068003 */  lui   $a2, %hi(cast_model)
/* 04D720 7F018BF0 24C6B5F4 */  addiu $a2, %lo(cast_model) # addiu $a2, $a2, -0x4a0c
/* 04D724 7F018BF4 2463B5F8 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, -0x4a08
/* 04D728 7F018BF8 8C6B0000 */  lw    $t3, ($v1)
/* 04D72C 7F018BFC 8CD90000 */  lw    $t9, ($a2)
/* 04D730 7F018C00 24020003 */  li    $v0, 3
/* 04D734 7F018C04 AD790018 */  sw    $t9, 0x18($t3)
/* 04D738 7F018C08 8FAC0070 */  lw    $t4, 0x70($sp)
/* 04D73C 7F018C0C 11800003 */  beqz  $t4, .L7F018C1C
/* 04D740 7F018C10 00000000 */   nop
/* 04D744 7F018C14 10000001 */  b     .L7F018C1C
/* 04D748 7F018C18 24020005 */   li    $v0, 5
.L7F018C1C:
/* 04D74C 7F018C1C 8CCA0000 */  lw    $t2, ($a2)
/* 04D750 7F018C20 00024880 */  sll   $t1, $v0, 2
/* 04D754 7F018C24 8C680000 */  lw    $t0, ($v1)
/* 04D758 7F018C28 8D580008 */  lw    $t8, 8($t2)
/* 04D75C 7F018C2C 8F0D0008 */  lw    $t5, 8($t8)
/* 04D760 7F018C30 01A97821 */  addu  $t7, $t5, $t1
/* 04D764 7F018C34 8DEE0000 */  lw    $t6, ($t7)
/* 04D768 7F018C38 10000006 */  b     .L7F018C54
/* 04D76C 7F018C3C AD0E001C */   sw    $t6, 0x1c($t0)
.L7F018C40:
/* 04D770 7F018C40 3C038003 */  lui   $v1, %hi(cast_model_weapon)
/* 04D774 7F018C44 2463B5F8 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, -0x4a08
/* 04D778 7F018C48 3C068003 */  lui   $a2, %hi(cast_model)
/* 04D77C 7F018C4C 24C6B5F4 */  addiu $a2, %lo(cast_model) # addiu $a2, $a2, -0x4a0c
/* 04D780 7F018C50 AC600000 */  sw    $zero, ($v1)
.L7F018C54:
/* 04D784 7F018C54 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04D788 7F018C58 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04D78C 7F018C5C 0FC1B3A1 */  jal   sub_GAME_7F06CE84
/* 04D790 7F018C60 8CC40000 */   lw    $a0, ($a2)
/* 04D794 7F018C64 3C048003 */  lui   $a0, %hi(cast_model)
/* 04D798 7F018C68 8C84B5F4 */  lw    $a0, %lo(cast_model)($a0)
/* 04D79C 7F018C6C 0FC1B303 */  jal   setsuboffset
/* 04D7A0 7F018C70 27A500A0 */   addiu $a1, $sp, 0xa0
/* 04D7A4 7F018C74 3C048003 */  lui   $a0, %hi(cast_model)
/* 04D7A8 7F018C78 8C84B5F4 */  lw    $a0, %lo(cast_model)($a0)
/* 04D7AC 7F018C7C 0FC1B34F */  jal   setsubroty
/* 04D7B0 7F018C80 24050000 */   li    $a1, 0
/* 04D7B4 7F018C84 3C048003 */  lui   $a0, %hi(cast_model)
/* 04D7B8 7F018C88 8C84B5F4 */  lw    $a0, %lo(cast_model)($a0)
/* 04D7BC 7F018C8C 3C053F00 */  lui   $a1, 0x3f00
/* 04D7C0 7F018C90 0FC1BFC6 */  jal   modelSetAnimPlaySpeed
/* 04D7C4 7F018C94 24060000 */   li    $a2, 0
/* 04D7C8 7F018C98 3C198003 */  lui   $t9, %hi(randomly_selected_intro_animation)
/* 04D7CC 7F018C9C 8F39B5EC */  lw    $t9, %lo(randomly_selected_intro_animation)($t9)
/* 04D7D0 7F018CA0 3C0C8003 */  lui   $t4, %hi(intro_animation_table)
/* 04D7D4 7F018CA4 258CB8BC */  addiu $t4, %lo(intro_animation_table) # addiu $t4, $t4, -0x4744
/* 04D7D8 7F018CA8 00195900 */  sll   $t3, $t9, 4
/* 04D7DC 7F018CAC 016C1021 */  addu  $v0, $t3, $t4
/* 04D7E0 7F018CB0 8C4A0000 */  lw    $t2, ($v0)
/* 04D7E4 7F018CB4 C4440008 */  lwc1  $f4, 8($v0)
/* 04D7E8 7F018CB8 44803000 */  mtc1  $zero, $f6
/* 04D7EC 7F018CBC 3C058003 */  lui   $a1, %hi(animation_table_ptrs1)
/* 04D7F0 7F018CC0 000AC080 */  sll   $t8, $t2, 2
/* 04D7F4 7F018CC4 00B82821 */  addu  $a1, $a1, $t8
/* 04D7F8 7F018CC8 3C048003 */  lui   $a0, %hi(cast_model)
/* 04D7FC 7F018CCC 8C84B5F4 */  lw    $a0, %lo(cast_model)($a0)
/* 04D800 7F018CD0 8CA59D6C */  lw    $a1, %lo(animation_table_ptrs1)($a1)
/* 04D804 7F018CD4 8C470004 */  lw    $a3, 4($v0)
/* 04D808 7F018CD8 8FA60070 */  lw    $a2, 0x70($sp)
/* 04D80C 7F018CDC E7A40010 */  swc1  $f4, 0x10($sp)
/* 04D810 7F018CE0 0FC1BF2A */  jal   modelSetAnimation
/* 04D814 7F018CE4 E7A60014 */   swc1  $f6, 0x14($sp)
/* 04D818 7F018CE8 3C018003 */  lui   $at, %hi(g_MenuTimer)
/* 04D81C 7F018CEC 0C002914 */  jal   randomGetNext
/* 04D820 7F018CF0 AC20A8CC */   sw    $zero, %lo(g_MenuTimer)($at)
/* 04D824 7F018CF4 44824000 */  mtc1  $v0, $f8
/* 04D828 7F018CF8 04410005 */  bgez  $v0, .L7F018D10
/* 04D82C 7F018CFC 468042A0 */   cvt.s.w $f10, $f8
/* 04D830 7F018D00 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D834 7F018D04 44818000 */  mtc1  $at, $f16
/* 04D838 7F018D08 00000000 */  nop
/* 04D83C 7F018D0C 46105280 */  add.s $f10, $f10, $f16
.L7F018D10:
/* 04D840 7F018D10 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D844 7F018D14 44819000 */  mtc1  $at, $f18
/* 04D848 7F018D18 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 04D84C 7F018D1C 44813000 */  mtc1  $at, $f6
/* 04D850 7F018D20 46125102 */  mul.s $f4, $f10, $f18
/* 04D854 7F018D24 3C01428C */  li    $at, 0x428C0000 # 70.000000
/* 04D858 7F018D28 44818000 */  mtc1  $at, $f16
/* 04D85C 7F018D2C 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A4)
/* 04D860 7F018D30 46062202 */  mul.s $f8, $f4, $f6
/* 04D864 7F018D34 46104280 */  add.s $f10, $f8, $f16
/* 04D868 7F018D38 0C002914 */  jal   randomGetNext
/* 04D86C 7F018D3C E42A95A4 */   swc1  $f10, %lo(flt_CODE_bss_800695A4)($at)
/* 04D870 7F018D40 44829000 */  mtc1  $v0, $f18
/* 04D874 7F018D44 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D878 7F018D48 04410004 */  bgez  $v0, .L7F018D5C
/* 04D87C 7F018D4C 46809120 */   cvt.s.w $f4, $f18
/* 04D880 7F018D50 44813000 */  mtc1  $at, $f6
/* 04D884 7F018D54 00000000 */  nop
/* 04D888 7F018D58 46062100 */  add.s $f4, $f4, $f6
.L7F018D5C:
/* 04D88C 7F018D5C 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D890 7F018D60 44814000 */  mtc1  $at, $f8
/* 04D894 7F018D64 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 04D898 7F018D68 44815000 */  mtc1  $at, $f10
/* 04D89C 7F018D6C 46082402 */  mul.s $f16, $f4, $f8
/* 04D8A0 7F018D70 3C01428C */  li    $at, 0x428C0000 # 70.000000
/* 04D8A4 7F018D74 44813000 */  mtc1  $at, $f6
/* 04D8A8 7F018D78 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A8)
/* 04D8AC 7F018D7C 460A8482 */  mul.s $f18, $f16, $f10
/* 04D8B0 7F018D80 46069100 */  add.s $f4, $f18, $f6
/* 04D8B4 7F018D84 0C002914 */  jal   randomGetNext
/* 04D8B8 7F018D88 E42495A8 */   swc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
/* 04D8BC 7F018D8C 44824000 */  mtc1  $v0, $f8
/* 04D8C0 7F018D90 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D8C4 7F018D94 04410004 */  bgez  $v0, .L7F018DA8
/* 04D8C8 7F018D98 46804420 */   cvt.s.w $f16, $f8
/* 04D8CC 7F018D9C 44815000 */  mtc1  $at, $f10
/* 04D8D0 7F018DA0 00000000 */  nop
/* 04D8D4 7F018DA4 460A8400 */  add.s $f16, $f16, $f10
.L7F018DA8:
/* 04D8D8 7F018DA8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D8DC 7F018DAC 44819000 */  mtc1  $at, $f18
/* 04D8E0 7F018DB0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 04D8E4 7F018DB4 44812000 */  mtc1  $at, $f4
/* 04D8E8 7F018DB8 46128182 */  mul.s $f6, $f16, $f18
/* 04D8EC 7F018DBC 3C018005 */  lui   $at, %hi(D_80051B00)
/* 04D8F0 7F018DC0 C42A1B00 */  lwc1  $f10, %lo(D_80051B00)($at)
/* 04D8F4 7F018DC4 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B0)
/* 04D8F8 7F018DC8 46043201 */  sub.s $f8, $f6, $f4
/* 04D8FC 7F018DCC 460A4402 */  mul.s $f16, $f8, $f10
/* 04D900 7F018DD0 0C002914 */  jal   randomGetNext
/* 04D904 7F018DD4 E43095B0 */   swc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
/* 04D908 7F018DD8 44829000 */  mtc1  $v0, $f18
/* 04D90C 7F018DDC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D910 7F018DE0 04410004 */  bgez  $v0, .L7F018DF4
/* 04D914 7F018DE4 468091A0 */   cvt.s.w $f6, $f18
/* 04D918 7F018DE8 44812000 */  mtc1  $at, $f4
/* 04D91C 7F018DEC 00000000 */  nop
/* 04D920 7F018DF0 46043180 */  add.s $f6, $f6, $f4
.L7F018DF4:
/* 04D924 7F018DF4 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D928 7F018DF8 44814000 */  mtc1  $at, $f8
/* 04D92C 7F018DFC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 04D930 7F018E00 44818000 */  mtc1  $at, $f16
/* 04D934 7F018E04 46083282 */  mul.s $f10, $f6, $f8
/* 04D938 7F018E08 3C018005 */  lui   $at, %hi(D_80051B04)
/* 04D93C 7F018E0C C4241B04 */  lwc1  $f4, %lo(D_80051B04)($at)
/* 04D940 7F018E10 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B4)
/* 04D944 7F018E14 46105481 */  sub.s $f18, $f10, $f16
/* 04D948 7F018E18 46049182 */  mul.s $f6, $f18, $f4
/* 04D94C 7F018E1C 0C002914 */  jal   randomGetNext
/* 04D950 7F018E20 E42695B4 */   swc1  $f6, %lo(flt_CODE_bss_800695B4)($at)
/* 04D954 7F018E24 44824000 */  mtc1  $v0, $f8
/* 04D958 7F018E28 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D95C 7F018E2C 04410004 */  bgez  $v0, .L7F018E40
/* 04D960 7F018E30 468042A0 */   cvt.s.w $f10, $f8
/* 04D964 7F018E34 44818000 */  mtc1  $at, $f16
/* 04D968 7F018E38 00000000 */  nop
/* 04D96C 7F018E3C 46105280 */  add.s $f10, $f10, $f16
.L7F018E40:
/* 04D970 7F018E40 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D974 7F018E44 44819000 */  mtc1  $at, $f18
/* 04D978 7F018E48 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 04D97C 7F018E4C 44813000 */  mtc1  $at, $f6
/* 04D980 7F018E50 46125102 */  mul.s $f4, $f10, $f18
/* 04D984 7F018E54 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 04D988 7F018E58 44818000 */  mtc1  $at, $f16
/* 04D98C 7F018E5C 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695BC)
/* 04D990 7F018E60 46062202 */  mul.s $f8, $f4, $f6
/* 04D994 7F018E64 46104280 */  add.s $f10, $f8, $f16
/* 04D998 7F018E68 0C002914 */  jal   randomGetNext
/* 04D99C 7F018E6C E42A95BC */   swc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
/* 04D9A0 7F018E70 44829000 */  mtc1  $v0, $f18
/* 04D9A4 7F018E74 3C038007 */  lui   $v1, %hi(flt_CODE_bss_800695E8)
/* 04D9A8 7F018E78 44800000 */  mtc1  $zero, $f0
/* 04D9AC 7F018E7C 246395E8 */  addiu $v1, %lo(flt_CODE_bss_800695E8) # addiu $v1, $v1, -0x6a18
/* 04D9B0 7F018E80 04410005 */  bgez  $v0, .L7F018E98
/* 04D9B4 7F018E84 46809120 */   cvt.s.w $f4, $f18
/* 04D9B8 7F018E88 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04D9BC 7F018E8C 44813000 */  mtc1  $at, $f6
/* 04D9C0 7F018E90 00000000 */  nop
/* 04D9C4 7F018E94 46062100 */  add.s $f4, $f4, $f6
.L7F018E98:
/* 04D9C8 7F018E98 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04D9CC 7F018E9C 44814000 */  mtc1  $at, $f8
/* 04D9D0 7F018EA0 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 04D9D4 7F018EA4 44815000 */  mtc1  $at, $f10
/* 04D9D8 7F018EA8 46082402 */  mul.s $f16, $f4, $f8
/* 04D9DC 7F018EAC 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 04D9E0 7F018EB0 44813000 */  mtc1  $at, $f6
/* 04D9E4 7F018EB4 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695C0)
/* 04D9E8 7F018EB8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 04D9EC 7F018EBC 240D0001 */  li    $t5, 1
/* 04D9F0 7F018EC0 460A8482 */  mul.s $f18, $f16, $f10
/* 04D9F4 7F018EC4 46069100 */  add.s $f4, $f18, $f6
/* 04D9F8 7F018EC8 E42495C0 */  swc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
/* 04D9FC 7F018ECC 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A4)
/* 04DA00 7F018ED0 C42895A4 */  lwc1  $f8, %lo(flt_CODE_bss_800695A4)($at)
/* 04DA04 7F018ED4 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A0)
/* 04DA08 7F018ED8 E42895A0 */  swc1  $f8, %lo(flt_CODE_bss_800695A0)($at)
/* 04DA0C 7F018EDC 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B0)
/* 04DA10 7F018EE0 C43095B0 */  lwc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
/* 04DA14 7F018EE4 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695AC)
/* 04DA18 7F018EE8 E43095AC */  swc1  $f16, %lo(flt_CODE_bss_800695AC)($at)
/* 04DA1C 7F018EEC 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695BC)
/* 04DA20 7F018EF0 C42A95BC */  lwc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
/* 04DA24 7F018EF4 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B8)
/* 04DA28 7F018EF8 27BD00B8 */  addiu $sp, $sp, 0xb8
/* 04DA2C 7F018EFC E42A95B8 */  swc1  $f10, %lo(flt_CODE_bss_800695B8)($at)
/* 04DA30 7F018F00 3C018007 */  lui   $at, %hi(bss_800695E4)
/* 04DA34 7F018F04 AC2D95E4 */  sw    $t5, %lo(bss_800695E4)($at)
/* 04DA38 7F018F08 E4600000 */  swc1  $f0, ($v1)
/* 04DA3C 7F018F0C E4600004 */  swc1  $f0, 4($v1)
/* 04DA40 7F018F10 03E00008 */  jr    $ra
/* 04DA44 7F018F14 E4600008 */   swc1  $f0, 8($v1)
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel jpt_intro_bond_head
 .word .L7F0188C0
 .word .L7F01881C
 .word .L7F018830
 .word .L7F018844
 .word .L7F018858
 .size jpt_intro_bond_head, . - jpt_intro_bond_head
glabel D_80051B00
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B04
.word 0x4020D97C /*2.5132742;*/


.text
glabel init_menu18_displaycast
/* 04B104 7F018714 3C0E8002 */  lui   $t6, %hi(ptr_logo_and_walletbond_DL) # $t6, 0x8002
/* 04B108 7F018718 8DCE5EA0 */  lw    $t6, %lo(ptr_logo_and_walletbond_DL)($t6)
/* 04B10C 7F01871C 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 04B110 7F018720 3C188002 */  lui   $t8, %hi(D_8002BA2C) # $t8, 0x8002
/* 04B114 7F018724 AFBF001C */  sw    $ra, 0x1c($sp)
/* 04B118 7F018728 27186F7C */  addiu $t8, %lo(D_8002BA2C) # addiu $t8, $t8, 0x6f7c
/* 04B11C 7F01872C AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 04B120 7F018730 8F010000 */  lw    $at, ($t8)
/* 04B124 7F018734 27AF00A0 */  addiu $t7, $sp, 0xa0
/* 04B128 7F018738 8F090004 */  lw    $t1, 4($t8)
/* 04B12C 7F01873C ADE10000 */  sw    $at, ($t7)
/* 04B130 7F018740 8F010008 */  lw    $at, 8($t8)
/* 04B134 7F018744 ADE90004 */  sw    $t1, 4($t7)
/* 04B138 7F018748 ADE10008 */  sw    $at, 8($t7)
/* 04B13C 7F01874C 0C00262C */  jal   randomGetNext
/* 04B140 7F018750 AFA0007C */   sw    $zero, 0x7c($sp)
/* 04B144 7F018754 3C0B8002 */  lui   $t3, %hi(full_actor_intro) # $t3, 0x8002
/* 04B148 7F018758 8D6B6B4C */  lw    $t3, %lo(full_actor_intro)($t3)
/* 04B14C 7F01875C 304A0001 */  andi  $t2, $v0, 1
/* 04B150 7F018760 AFAA0070 */  sw    $t2, 0x70($sp)
/* 04B154 7F018764 1160000A */  beqz  $t3, .L7F018790
/* 04B158 7F018768 3C0C8002 */   lui   $t4, %hi(intro_character_index) # $t4, 0x8002
/* 04B15C 7F01876C 8D8C6B38 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04B160 7F018770 15800007 */  bnez  $t4, .L7F018790
/* 04B164 7F018774 00000000 */   nop
/* 04B168 7F018778 0C001927 */  jal   musicTrack1ApplySeqpVol
/* 04B16C 7F01877C 24047FFF */   li    $a0, 32767
/* 04B170 7F018780 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade) # $at, 0x8002
/* 04B174 7F018784 AC2021DC */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 04B178 7F018788 0C0018B7 */  jal   musicTrack1Play
/* 04B17C 7F01878C 24040002 */   li    $a0, 2
.L7F018790:
/* 04B180 7F018790 3C048002 */  lui   $a0, %hi(intro_animation_table) # $a0, 0x8002
/* 04B184 7F018794 24846E0C */  addiu $a0, %lo(intro_animation_table) # addiu $a0, $a0, 0x6e0c
/* 04B188 7F018798 00006900 */  sll   $t5, $zero, 4
/* 04B18C 7F01879C 008D7021 */  addu  $t6, $a0, $t5
/* 04B190 7F0187A0 8DC80000 */  lw    $t0, ($t6)
/* 04B194 7F0187A4 3C038002 */  lui   $v1, %hi(intro_animation_count) # $v1, 0x8002
/* 04B198 7F0187A8 24636B40 */  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, 0x6b40
/* 04B19C 7F0187AC AC600000 */  sw    $zero, ($v1)
/* 04B1A0 7F0187B0 05000009 */  bltz  $t0, .L7F0187D8
/* 04B1A4 7F0187B4 00001025 */   move  $v0, $zero
/* 04B1A8 7F0187B8 24590001 */  addiu $t9, $v0, 1
.L7F0187BC:
/* 04B1AC 7F0187BC 00197900 */  sll   $t7, $t9, 4
/* 04B1B0 7F0187C0 008FC021 */  addu  $t8, $a0, $t7
/* 04B1B4 7F0187C4 8F090000 */  lw    $t1, ($t8)
/* 04B1B8 7F0187C8 AC790000 */  sw    $t9, ($v1)
/* 04B1BC 7F0187CC 03201025 */  move  $v0, $t9
/* 04B1C0 7F0187D0 0523FFFA */  bgezl $t1, .L7F0187BC
/* 04B1C4 7F0187D4 24590001 */   addiu $t9, $v0, 1
.L7F0187D8:
/* 04B1C8 7F0187D8 0C00262C */  jal   randomGetNext
/* 04B1CC 7F0187DC 00000000 */   nop
/* 04B1D0 7F0187E0 3C038002 */  lui   $v1, %hi(intro_animation_count) # $v1, 0x8002
/* 04B1D4 7F0187E4 24636B40 */  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, 0x6b40
/* 04B1D8 7F0187E8 8C6A0000 */  lw    $t2, ($v1)
/* 04B1DC 7F0187EC 3C0C8002 */  lui   $t4, %hi(intro_character_index) # $t4, 0x8002
/* 04B1E0 7F0187F0 8D8C6B38 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04B1E4 7F0187F4 004A001B */  divu  $zero, $v0, $t2
/* 04B1E8 7F0187F8 00005810 */  mfhi  $t3
/* 04B1EC 7F0187FC 3C018002 */  lui   $at, %hi(randomly_selected_intro_animation) # $at, 0x8002
/* 04B1F0 7F018800 AC2B6B3C */  sw    $t3, %lo(randomly_selected_intro_animation)($at)
/* 04B1F4 7F018804 3C0F8002 */  lui   $t7, %hi(randomly_selected_intro_animation) # $t7, 0x8002
/* 04B1F8 7F018808 000C6880 */  sll   $t5, $t4, 2
/* 04B1FC 7F01880C 8DEF6B3C */  lw    $t7, %lo(randomly_selected_intro_animation)($t7)
/* 04B200 7F018810 3C0E8002 */  lui   $t6, %hi(intro_char_table) # $t6, 0x8002
/* 04B204 7F018814 01AC6821 */  addu  $t5, $t5, $t4
/* 04B208 7F018818 000D6880 */  sll   $t5, $t5, 2
/* 04B20C 7F01881C 25CE6B50 */  addiu $t6, %lo(intro_char_table) # addiu $t6, $t6, 0x6b50
/* 04B210 7F018820 01AE2021 */  addu  $a0, $t5, $t6
/* 04B214 7F018824 8C880000 */  lw    $t0, ($a0)
/* 04B218 7F018828 3C098002 */  lui   $t1, %hi(intro_animation_table+12)
/* 04B21C 7F01882C 000FC100 */  sll   $t8, $t7, 4
/* 04B220 7F018830 01384821 */  addu  $t1, $t1, $t8
/* 04B224 7F018834 8C990004 */  lw    $t9, 4($a0)
/* 04B228 7F018838 8D296E18 */  lw    $t1, %lo(intro_animation_table+12)($t1)
/* 04B22C 7F01883C 24010016 */  li    $at, 22
/* 04B230 7F018840 15400002 */  bnez  $t2, .L7F01884C
/* 04B234 7F018844 00000000 */   nop
/* 04B238 7F018848 0007000D */  break 7
.L7F01884C:
/* 04B23C 7F01884C AFA8008C */  sw    $t0, 0x8c($sp)
/* 04B240 7F018850 01005025 */  move  $t2, $t0
/* 04B244 7F018854 AFB90088 */  sw    $t9, 0x88($sp)
/* 04B248 7F018858 15010022 */  bne   $t0, $at, .L7F0188E4
/* 04B24C 7F01885C AFA9006C */   sw    $t1, 0x6c($sp)
/* 04B250 7F018860 0C00262C */  jal   randomGetNext
/* 04B254 7F018864 00000000 */   nop
/* 04B258 7F018868 24010005 */  li    $at, 5
/* 04B25C 7F01886C 0041001B */  divu  $zero, $v0, $at
/* 04B260 7F018870 00005810 */  mfhi  $t3
/* 04B264 7F018874 2D610005 */  sltiu $at, $t3, 5
/* 04B268 7F018878 1020002F */  beqz  $at, .L7F018938
/* 04B26C 7F01887C 000B5880 */   sll   $t3, $t3, 2
/* 04B270 7F018880 3C018004 */  lui   $at, %hi(jpt_intro_bond_head)
/* 04B274 7F018884 002B0821 */  addu  $at, $at, $t3
/* 04B278 7F018888 8C2B7C14 */  lw    $t3, %lo(jpt_intro_bond_head)($at)
/* 04B27C 7F01888C 01600008 */  jr    $t3
/* 04B280 7F018890 00000000 */   nop
.L7F01881C:
/* 04B284 7F018894 240C0017 */  li    $t4, 23
/* 04B288 7F018898 240D004B */  li    $t5, 75
/* 04B28C 7F01889C AFAD0088 */  sw    $t5, 0x88($sp)
/* 04B290 7F0188A0 10000025 */  b     .L7F018938
/* 04B294 7F0188A4 AFAC008C */   sw    $t4, 0x8c($sp)
.L7F018830:
/* 04B298 7F0188A8 240E0018 */  li    $t6, 24
/* 04B29C 7F0188AC 2408004B */  li    $t0, 75
/* 04B2A0 7F0188B0 AFA80088 */  sw    $t0, 0x88($sp)
/* 04B2A4 7F0188B4 10000020 */  b     .L7F018938
/* 04B2A8 7F0188B8 AFAE008C */   sw    $t6, 0x8c($sp)
.L7F018844:
/* 04B2AC 7F0188BC 24190019 */  li    $t9, 25
/* 04B2B0 7F0188C0 240F004B */  li    $t7, 75
/* 04B2B4 7F0188C4 AFAF0088 */  sw    $t7, 0x88($sp)
/* 04B2B8 7F0188C8 1000001B */  b     .L7F018938
/* 04B2BC 7F0188CC AFB9008C */   sw    $t9, 0x8c($sp)
.L7F018858:
/* 04B2C0 7F0188D0 24180005 */  li    $t8, 5
/* 04B2C4 7F0188D4 2409004E */  li    $t1, 78
/* 04B2C8 7F0188D8 AFA90088 */  sw    $t1, 0x88($sp)
/* 04B2CC 7F0188DC 10000016 */  b     .L7F018938
/* 04B2D0 7F0188E0 AFB8008C */   sw    $t8, 0x8c($sp)
.L7F01886C:
.L7F0188E4:
/* 04B2D4 7F0188E4 8FAA008C */  lw    $t2, 0x8c($sp)
/* 04B2D8 7F0188E8 24010010 */  li    $at, 16
/* 04B2DC 7F0188EC 8FAD008C */  lw    $t5, 0x8c($sp)
/* 04B2E0 7F0188F0 55410009 */  bnel  $t2, $at, .L7F018918
/* 04B2E4 7F0188F4 24010009 */   li    $at, 9
/* 04B2E8 7F0188F8 0C00262C */  jal   randomGetNext
/* 04B2EC 7F0188FC 00000000 */   nop
/* 04B2F0 7F018900 304B0001 */  andi  $t3, $v0, 1
/* 04B2F4 7F018904 1160000C */  beqz  $t3, .L7F018938
/* 04B2F8 7F018908 240C004F */   li    $t4, 79
/* 04B2FC 7F01890C 1000000A */  b     .L7F018938
/* 04B300 7F018910 AFAC008C */   sw    $t4, 0x8c($sp)
/* 04B304 7F018914 24010009 */  li    $at, 9
.L7F018918:
/* 04B308 7F018918 55A10008 */  bnel  $t5, $at, .L7F01893C
/* 04B30C 7F01891C 8FB90088 */   lw    $t9, 0x88($sp)
/* 04B310 7F018920 0C00262C */  jal   randomGetNext
/* 04B314 7F018924 00000000 */   nop
/* 04B318 7F018928 304E0001 */  andi  $t6, $v0, 1
/* 04B31C 7F01892C 11C00002 */  beqz  $t6, .L7F018938
/* 04B320 7F018930 24080008 */   li    $t0, 8
/* 04B324 7F018934 AFA8008C */  sw    $t0, 0x8c($sp)
.L7F0188C0:
.L7F018938:
/* 04B328 7F018938 8FB90088 */  lw    $t9, 0x88($sp)
.L7F01893C:
/* 04B32C 7F01893C 2401FF9F */  li    $at, -97
/* 04B330 7F018940 57210005 */  bnel  $t9, $at, .L7F018958
/* 04B334 7F018944 8FAF00B4 */   lw    $t7, 0xb4($sp)
/* 04B338 7F018948 0FC08D90 */  jal   get_random_head
/* 04B33C 7F01894C 8FA4008C */   lw    $a0, 0x8c($sp)
/* 04B340 7F018950 AFA20088 */  sw    $v0, 0x88($sp)
/* 04B344 7F018954 8FAF00B4 */  lw    $t7, 0xb4($sp)
.L7F018958:
/* 04B348 7F018958 3C020003 */  lui   $v0, (0x00031160 >> 16) # lui $v0, 3
/* 04B34C 7F01895C 34421160 */  ori   $v0, (0x00031160 & 0xFFFF) # ori $v0, $v0, 0x1160
/* 04B350 7F018960 01E22021 */  addu  $a0, $t7, $v0
/* 04B354 7F018964 2484003F */  addiu $a0, $a0, 0x3f
/* 04B358 7F018968 3498003F */  ori   $t8, $a0, 0x3f
/* 04B35C 7F01896C 3B04003F */  xori  $a0, $t8, 0x3f
/* 04B360 7F018970 AFA200B0 */  sw    $v0, 0xb0($sp)
/* 04B364 7F018974 240501B8 */  li    $a1, 440
/* 04B368 7F018978 0FC3465A */  jal   zbufSetBuffer
/* 04B36C 7F01897C 2406014A */   li    $a2, 330
/* 04B370 7F018980 3C060001 */  lui   $a2, (0x00019000 >> 16) # lui $a2, 1
/* 04B374 7F018984 34C69000 */  ori   $a2, (0x00019000 & 0xFFFF) # ori $a2, $a2, 0x9000
/* 04B378 7F018988 27A40090 */  addiu $a0, $sp, 0x90
/* 04B37C 7F01898C 0FC32C05 */  jal   texInitPool
/* 04B380 7F018990 8FA500B4 */   lw    $a1, 0xb4($sp)
/* 04B384 7F018994 8FAA008C */  lw    $t2, 0x8c($sp)
/* 04B388 7F018998 3C0C8003 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8003
/* 04B38C 7F01899C 8FA600B4 */  lw    $a2, 0xb4($sp)
/* 04B390 7F0189A0 000A5880 */  sll   $t3, $t2, 2
/* 04B394 7F0189A4 016A5821 */  addu  $t3, $t3, $t2
/* 04B398 7F0189A8 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 04B39C 7F0189AC 3C030001 */  lui   $v1, (0x00019000 >> 16) # lui $v1, 1
/* 04B3A0 7F0189B0 000B5880 */  sll   $t3, $t3, 2
/* 04B3A4 7F0189B4 258C7A60 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, 0x7a60
/* 04B3A8 7F0189B8 34639000 */  ori   $v1, (0x00019000 & 0xFFFF) # ori $v1, $v1, 0x9000
/* 04B3AC 7F0189BC 016C1021 */  addu  $v0, $t3, $t4
/* 04B3B0 7F0189C0 8C440000 */  lw    $a0, ($v0)
/* 04B3B4 7F0189C4 27AD0090 */  addiu $t5, $sp, 0x90
/* 04B3B8 7F0189C8 00C33021 */  addu  $a2, $a2, $v1
/* 04B3BC 7F0189CC 00E33823 */  subu  $a3, $a3, $v1
/* 04B3C0 7F0189D0 AFA700B0 */  sw    $a3, 0xb0($sp)
/* 04B3C4 7F0189D4 AFA600B4 */  sw    $a2, 0xb4($sp)
/* 04B3C8 7F0189D8 AFAD0010 */  sw    $t5, 0x10($sp)
/* 04B3CC 7F0189DC 8C450004 */  lw    $a1, 4($v0)
/* 04B3D0 7F0189E0 AFA20024 */  sw    $v0, 0x24($sp)
/* 04B3D4 7F0189E4 0FC1D949 */  jal   load_object_fill_header
/* 04B3D8 7F0189E8 AFA40080 */   sw    $a0, 0x80($sp)
/* 04B3DC 7F0189EC 8FA20024 */  lw    $v0, 0x24($sp)
/* 04B3E0 7F0189F0 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 04B3E4 7F0189F4 8C440004 */   lw    $a0, 4($v0)
/* 04B3E8 7F0189F8 2443003F */  addiu $v1, $v0, 0x3f
/* 04B3EC 7F0189FC 8FB900B0 */  lw    $t9, 0xb0($sp)
/* 04B3F0 7F018A00 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 04B3F4 7F018A04 346E003F */  ori   $t6, $v1, 0x3f
/* 04B3F8 7F018A08 8FAA0088 */  lw    $t2, 0x88($sp)
/* 04B3FC 7F018A0C 39C8003F */  xori  $t0, $t6, 0x3f
/* 04B400 7F018A10 03287823 */  subu  $t7, $t9, $t0
/* 04B404 7F018A14 03084821 */  addu  $t1, $t8, $t0
/* 04B408 7F018A18 AFAF00B0 */  sw    $t7, 0xb0($sp)
/* 04B40C 7F018A1C 0540001C */  bltz  $t2, .L7F018A90
/* 04B410 7F018A20 AFA900B4 */   sw    $t1, 0xb4($sp)
/* 04B414 7F018A24 000A5880 */  sll   $t3, $t2, 2
/* 04B418 7F018A28 016A5821 */  addu  $t3, $t3, $t2
/* 04B41C 7F018A2C 3C0C8003 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8003
/* 04B420 7F018A30 258C7A60 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, 0x7a60
/* 04B424 7F018A34 000B5880 */  sll   $t3, $t3, 2
/* 04B428 7F018A38 016C1021 */  addu  $v0, $t3, $t4
/* 04B42C 7F018A3C 8C440000 */  lw    $a0, ($v0)
/* 04B430 7F018A40 27AD0090 */  addiu $t5, $sp, 0x90
/* 04B434 7F018A44 AFAD0010 */  sw    $t5, 0x10($sp)
/* 04B438 7F018A48 8C450004 */  lw    $a1, 4($v0)
/* 04B43C 7F018A4C AFA20024 */  sw    $v0, 0x24($sp)
/* 04B440 7F018A50 01203025 */  move  $a2, $t1
/* 04B444 7F018A54 01E03825 */  move  $a3, $t7
/* 04B448 7F018A58 0FC1D949 */  jal   load_object_fill_header
/* 04B44C 7F018A5C AFA4007C */   sw    $a0, 0x7c($sp)
/* 04B450 7F018A60 8FA20024 */  lw    $v0, 0x24($sp)
/* 04B454 7F018A64 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 04B458 7F018A68 8C440004 */   lw    $a0, 4($v0)
/* 04B45C 7F018A6C 2443003F */  addiu $v1, $v0, 0x3f
/* 04B460 7F018A70 8FB900B0 */  lw    $t9, 0xb0($sp)
/* 04B464 7F018A74 8FAA00B4 */  lw    $t2, 0xb4($sp)
/* 04B468 7F018A78 346E003F */  ori   $t6, $v1, 0x3f
/* 04B46C 7F018A7C 39C8003F */  xori  $t0, $t6, 0x3f
/* 04B470 7F018A80 0328C023 */  subu  $t8, $t9, $t0
/* 04B474 7F018A84 01485821 */  addu  $t3, $t2, $t0
/* 04B478 7F018A88 AFB800B0 */  sw    $t8, 0xb0($sp)
/* 04B47C 7F018A8C AFAB00B4 */  sw    $t3, 0xb4($sp)
.L7F018A90:
/* 04B480 7F018A90 8FA4008C */  lw    $a0, 0x8c($sp)
/* 04B484 7F018A94 8FA50088 */  lw    $a1, 0x88($sp)
/* 04B488 7F018A98 8FA60080 */  lw    $a2, 0x80($sp)
/* 04B48C 7F018A9C 8FA7007C */  lw    $a3, 0x7c($sp)
/* 04B490 7F018AA0 0FC08D22 */  jal   setup_chr_instance
/* 04B494 7F018AA4 AFA00010 */   sw    $zero, 0x10($sp)
/* 04B498 7F018AA8 3C038002 */  lui   $v1, %hi(cast_model) # $v1, 0x8002
/* 04B49C 7F018AAC 24636B44 */  addiu $v1, %lo(cast_model) # addiu $v1, $v1, 0x6b44
/* 04B4A0 7F018AB0 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04B4A4 7F018AB4 AC620000 */  sw    $v0, ($v1)
/* 04B4A8 7F018AB8 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04B4AC 7F018ABC 0FC1B4CF */  jal   modelSetScale
/* 04B4B0 7F018AC0 00402025 */   move  $a0, $v0
/* 04B4B4 7F018AC4 8FAC006C */  lw    $t4, 0x6c($sp)
/* 04B4B8 7F018AC8 24010002 */  li    $at, 2
/* 04B4BC 7F018ACC 1180007A */  beqz  $t4, .L7F018CB8
/* 04B4C0 7F018AD0 00000000 */   nop
/* 04B4C4 7F018AD4 15810018 */  bne   $t4, $at, .L7F018B38
/* 04B4C8 7F018AD8 27B8002C */   addiu $t8, $sp, 0x2c
/* 04B4CC 7F018ADC 3C0F8002 */  lui   $t7, %hi(random_rifles_in_intro) # $t7, 0x8002
/* 04B4D0 7F018AE0 25EF6F88 */  addiu $t7, %lo(random_rifles_in_intro) # addiu $t7, $t7, 0x6f88
/* 04B4D4 7F018AE4 8DE10000 */  lw    $at, ($t7)
/* 04B4D8 7F018AE8 8DEE0004 */  lw    $t6, 4($t7)
/* 04B4DC 7F018AEC 27A90054 */  addiu $t1, $sp, 0x54
/* 04B4E0 7F018AF0 AD210000 */  sw    $at, ($t1)
/* 04B4E4 7F018AF4 AD2E0004 */  sw    $t6, 4($t1)
/* 04B4E8 7F018AF8 8DEE000C */  lw    $t6, 0xc($t7)
/* 04B4EC 7F018AFC 8DE10008 */  lw    $at, 8($t7)
/* 04B4F0 7F018B00 AD2E000C */  sw    $t6, 0xc($t1)
/* 04B4F4 7F018B04 AD210008 */  sw    $at, 8($t1)
/* 04B4F8 7F018B08 8DE10010 */  lw    $at, 0x10($t7)
/* 04B4FC 7F018B0C 8DEE0014 */  lw    $t6, 0x14($t7)
/* 04B500 7F018B10 AD210010 */  sw    $at, 0x10($t1)
/* 04B504 7F018B14 0C00262C */  jal   randomGetNext
/* 04B508 7F018B18 AD2E0014 */   sw    $t6, 0x14($t1)
/* 04B50C 7F018B1C 24010006 */  li    $at, 6
/* 04B510 7F018B20 0041001B */  divu  $zero, $v0, $at
/* 04B514 7F018B24 00004010 */  mfhi  $t0
/* 04B518 7F018B28 0008C880 */  sll   $t9, $t0, 2
/* 04B51C 7F018B2C 03B91821 */  addu  $v1, $sp, $t9
/* 04B520 7F018B30 10000016 */  b     .L7F018B8C
/* 04B524 7F018B34 8C630054 */   lw    $v1, 0x54($v1)
.L7F018B38:
/* 04B528 7F018B38 3C0A8002 */  lui   $t2, %hi(random_pistols_in_intro) # $t2, 0x8002
/* 04B52C 7F018B3C 254A6FA0 */  addiu $t2, %lo(random_pistols_in_intro) # addiu $t2, $t2, 0x6fa0
/* 04B530 7F018B40 254C0024 */  addiu $t4, $t2, 0x24
.L7F018B44:
/* 04B534 7F018B44 8D410000 */  lw    $at, ($t2)
/* 04B538 7F018B48 254A000C */  addiu $t2, $t2, 0xc
/* 04B53C 7F018B4C 2718000C */  addiu $t8, $t8, 0xc
/* 04B540 7F018B50 AF01FFF4 */  sw    $at, -0xc($t8)
/* 04B544 7F018B54 8D41FFF8 */  lw    $at, -8($t2)
/* 04B548 7F018B58 AF01FFF8 */  sw    $at, -8($t8)
/* 04B54C 7F018B5C 8D41FFFC */  lw    $at, -4($t2)
/* 04B550 7F018B60 154CFFF8 */  bne   $t2, $t4, .L7F018B44
/* 04B554 7F018B64 AF01FFFC */   sw    $at, -4($t8)
/* 04B558 7F018B68 8D410000 */  lw    $at, ($t2)
/* 04B55C 7F018B6C 0C00262C */  jal   randomGetNext
/* 04B560 7F018B70 AF010000 */   sw    $at, ($t8)
/* 04B564 7F018B74 2401000A */  li    $at, 10
/* 04B568 7F018B78 0041001B */  divu  $zero, $v0, $at
/* 04B56C 7F018B7C 00006810 */  mfhi  $t5
/* 04B570 7F018B80 000D4880 */  sll   $t1, $t5, 2
/* 04B574 7F018B84 03A91821 */  addu  $v1, $sp, $t1
/* 04B578 7F018B88 8C63002C */  lw    $v1, 0x2c($v1)
.L7F018B8C:
/* 04B57C 7F018B8C 240100BE */  li    $at, 190
/* 04B580 7F018B90 54610007 */  bnel  $v1, $at, .L7F018BB0
/* 04B584 7F018B94 240100BB */   li    $at, 187
/* 04B588 7F018B98 0FC07A4C */  jal   fileIsCradleCompletedAnyFolder
/* 04B58C 7F018B9C AFA30084 */   sw    $v1, 0x84($sp)
/* 04B590 7F018BA0 14400002 */  bnez  $v0, .L7F018BAC
/* 04B594 7F018BA4 8FA30084 */   lw    $v1, 0x84($sp)
/* 04B598 7F018BA8 240300BF */  li    $v1, 191
.L7F018BAC:
/* 04B59C 7F018BAC 240100BB */  li    $at, 187
.L7F018BB0:
/* 04B5A0 7F018BB0 54610007 */  bnel  $v1, $at, .L7F018BD0
/* 04B5A4 7F018BB4 240100D0 */   li    $at, 208
/* 04B5A8 7F018BB8 0FC07A60 */  jal   check_aztec_completed_any_folder_secret_00
/* 04B5AC 7F018BBC AFA30084 */   sw    $v1, 0x84($sp)
/* 04B5B0 7F018BC0 14400002 */  bnez  $v0, .L7F018BCC
/* 04B5B4 7F018BC4 8FA30084 */   lw    $v1, 0x84($sp)
/* 04B5B8 7F018BC8 240300BF */  li    $v1, 191
.L7F018BCC:
/* 04B5BC 7F018BCC 240100D0 */  li    $at, 208
.L7F018BD0:
/* 04B5C0 7F018BD0 54610007 */  bnel  $v1, $at, .L7F018BF0
/* 04B5C4 7F018BD4 00037880 */   sll   $t7, $v1, 2
/* 04B5C8 7F018BD8 0FC07A74 */  jal   fileIsEgyptCompletedOn00AnyFolder
/* 04B5CC 7F018BDC AFA30084 */   sw    $v1, 0x84($sp)
/* 04B5D0 7F018BE0 14400002 */  bnez  $v0, .L7F018BEC
/* 04B5D4 7F018BE4 8FA30084 */   lw    $v1, 0x84($sp)
/* 04B5D8 7F018BE8 240300BF */  li    $v1, 191
.L7F018BEC:
/* 04B5DC 7F018BEC 00037880 */  sll   $t7, $v1, 2
.L7F018BF0:
/* 04B5E0 7F018BF0 01E37823 */  subu  $t7, $t7, $v1
/* 04B5E4 7F018BF4 3C0E8003 */  lui   $t6, %hi(PitemZ_entries) # $t6, 0x8003
/* 04B5E8 7F018BF8 25CE4D88 */  addiu $t6, %lo(PitemZ_entries) # addiu $t6, $t6, 0x4d88
/* 04B5EC 7F018BFC 000F7880 */  sll   $t7, $t7, 2
/* 04B5F0 7F018C00 01EE1021 */  addu  $v0, $t7, $t6
/* 04B5F4 7F018C04 8C440000 */  lw    $a0, ($v0)
/* 04B5F8 7F018C08 27A80090 */  addiu $t0, $sp, 0x90
/* 04B5FC 7F018C0C AFA80010 */  sw    $t0, 0x10($sp)
/* 04B600 7F018C10 8C450004 */  lw    $a1, 4($v0)
/* 04B604 7F018C14 AFA20024 */  sw    $v0, 0x24($sp)
/* 04B608 7F018C18 8FA600B4 */  lw    $a2, 0xb4($sp)
/* 04B60C 7F018C1C 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 04B610 7F018C20 0FC1D949 */  jal   load_object_fill_header
/* 04B614 7F018C24 AFA40078 */   sw    $a0, 0x78($sp)
/* 04B618 7F018C28 8FA20024 */  lw    $v0, 0x24($sp)
/* 04B61C 7F018C2C 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 04B620 7F018C30 8C440004 */   lw    $a0, 4($v0)
/* 04B624 7F018C34 0FC1D75F */  jal   modelCalculateRwDataLen
/* 04B628 7F018C38 8FA40078 */   lw    $a0, 0x78($sp)
/* 04B62C 7F018C3C 0FC1B1F5 */  jal   get_obj_instance_controller_for_header
/* 04B630 7F018C40 8FA40078 */   lw    $a0, 0x78($sp)
/* 04B634 7F018C44 3C038002 */  lui   $v1, %hi(cast_model_weapon) # $v1, 0x8002
/* 04B638 7F018C48 24636B48 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, 0x6b48
/* 04B63C 7F018C4C 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04B640 7F018C50 AC620000 */  sw    $v0, ($v1)
/* 04B644 7F018C54 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04B648 7F018C58 0FC1B4CF */  jal   modelSetScale
/* 04B64C 7F018C5C 00402025 */   move  $a0, $v0
/* 04B650 7F018C60 3C038002 */  lui   $v1, %hi(cast_model_weapon) # $v1, 0x8002
/* 04B654 7F018C64 3C068002 */  lui   $a2, %hi(cast_model) # $a2, 0x8002
/* 04B658 7F018C68 24C66B44 */  addiu $a2, %lo(cast_model) # addiu $a2, $a2, 0x6b44
/* 04B65C 7F018C6C 24636B48 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, 0x6b48
/* 04B660 7F018C70 8C6B0000 */  lw    $t3, ($v1)
/* 04B664 7F018C74 8CD90000 */  lw    $t9, ($a2)
/* 04B668 7F018C78 24020003 */  li    $v0, 3
/* 04B66C 7F018C7C AD790018 */  sw    $t9, 0x18($t3)
/* 04B670 7F018C80 8FAC0070 */  lw    $t4, 0x70($sp)
/* 04B674 7F018C84 11800003 */  beqz  $t4, .L7F018C94
/* 04B678 7F018C88 00000000 */   nop
/* 04B67C 7F018C8C 10000001 */  b     .L7F018C94
/* 04B680 7F018C90 24020005 */   li    $v0, 5
.L7F018C94:
/* 04B684 7F018C94 8CCA0000 */  lw    $t2, ($a2)
/* 04B688 7F018C98 00024880 */  sll   $t1, $v0, 2
/* 04B68C 7F018C9C 8C680000 */  lw    $t0, ($v1)
/* 04B690 7F018CA0 8D580008 */  lw    $t8, 8($t2)
/* 04B694 7F018CA4 8F0D0008 */  lw    $t5, 8($t8)
/* 04B698 7F018CA8 01A97821 */  addu  $t7, $t5, $t1
/* 04B69C 7F018CAC 8DEE0000 */  lw    $t6, ($t7)
/* 04B6A0 7F018CB0 10000006 */  b     .L7F018CCC
/* 04B6A4 7F018CB4 AD0E001C */   sw    $t6, 0x1c($t0)
.L7F018CB8:
/* 04B6A8 7F018CB8 3C038002 */  lui   $v1, %hi(cast_model_weapon) # $v1, 0x8002
/* 04B6AC 7F018CBC 24636B48 */  addiu $v1, %lo(cast_model_weapon) # addiu $v1, $v1, 0x6b48
/* 04B6B0 7F018CC0 3C068002 */  lui   $a2, %hi(cast_model) # $a2, 0x8002
/* 04B6B4 7F018CC4 24C66B44 */  addiu $a2, %lo(cast_model) # addiu $a2, $a2, 0x6b44
/* 04B6B8 7F018CC8 AC600000 */  sw    $zero, ($v1)
.L7F018CCC:
/* 04B6BC 7F018CCC 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 04B6C0 7F018CD0 34A5CCCD */  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 04B6C4 7F018CD4 0FC1B4D2 */  jal   sub_GAME_7F06CE84
/* 04B6C8 7F018CD8 8CC40000 */   lw    $a0, ($a2)
/* 04B6CC 7F018CDC 3C048002 */  lui   $a0, %hi(cast_model) # $a0, 0x8002
/* 04B6D0 7F018CE0 8C846B44 */  lw    $a0, %lo(cast_model)($a0)
/* 04B6D4 7F018CE4 0FC1B480 */  jal   setsuboffset
/* 04B6D8 7F018CE8 27A500A0 */   addiu $a1, $sp, 0xa0
/* 04B6DC 7F018CEC 3C048002 */  lui   $a0, %hi(cast_model) # $a0, 0x8002
/* 04B6E0 7F018CF0 8C846B44 */  lw    $a0, %lo(cast_model)($a0)
/* 04B6E4 7F018CF4 0FC1B49D */  jal   setsubroty
/* 04B6E8 7F018CF8 24050000 */   li    $a1, 0
/* 04B6EC 7F018CFC 3C048002 */  lui   $a0, %hi(cast_model) # $a0, 0x8002
/* 04B6F0 7F018D00 3C053F19 */  lui   $a1, (0x3F19999A >> 16) # lui $a1, 0x3f19
/* 04B6F4 7F018D04 34A5999A */  ori   $a1, (0x3F19999A & 0xFFFF) # ori $a1, $a1, 0x999a
/* 04B6F8 7F018D08 8C846B44 */  lw    $a0, %lo(cast_model)($a0)
/* 04B6FC 7F018D0C 0FC1C02E */  jal   modelSetAnimPlaySpeed
/* 04B700 7F018D10 24060000 */   li    $a2, 0
/* 04B704 7F018D14 3C198002 */  lui   $t9, %hi(randomly_selected_intro_animation) # $t9, 0x8002
/* 04B708 7F018D18 8F396B3C */  lw    $t9, %lo(randomly_selected_intro_animation)($t9)
/* 04B70C 7F018D1C 3C0C8002 */  lui   $t4, %hi(intro_animation_table) # $t4, 0x8002
/* 04B710 7F018D20 258C6E0C */  addiu $t4, %lo(intro_animation_table) # addiu $t4, $t4, 0x6e0c
/* 04B714 7F018D24 00195900 */  sll   $t3, $t9, 4
/* 04B718 7F018D28 016C1021 */  addu  $v0, $t3, $t4
/* 04B71C 7F018D2C 8C4A0000 */  lw    $t2, ($v0)
/* 04B720 7F018D30 C4440008 */  lwc1  $f4, 8($v0)
/* 04B724 7F018D34 44803000 */  mtc1  $zero, $f6
/* 04B728 7F018D38 3C058002 */  lui   $a1, %hi(animation_table_ptrs1)
/* 04B72C 7F018D3C 000AC080 */  sll   $t8, $t2, 2
/* 04B730 7F018D40 00B82821 */  addu  $a1, $a1, $t8
/* 04B734 7F018D44 3C048002 */  lui   $a0, %hi(cast_model) # $a0, 0x8002
/* 04B738 7F018D48 8C846B44 */  lw    $a0, %lo(cast_model)($a0)
/* 04B73C 7F018D4C 8CA552BC */  lw    $a1, %lo(animation_table_ptrs1)($a1)
/* 04B740 7F018D50 8C470004 */  lw    $a3, 4($v0)
/* 04B744 7F018D54 8FA60070 */  lw    $a2, 0x70($sp)
/* 04B748 7F018D58 E7A40010 */  swc1  $f4, 0x10($sp)
/* 04B74C 7F018D5C 0FC1BF92 */  jal   modelSetAnimation
/* 04B750 7F018D60 E7A60014 */   swc1  $f6, 0x14($sp)
/* 04B754 7F018D64 3C018002 */  lui   $at, %hi(g_MenuTimer) # $at, 0x8002
/* 04B758 7F018D68 0C00262C */  jal   randomGetNext
/* 04B75C 7F018D6C AC205E1C */   sw    $zero, %lo(g_MenuTimer)($at)
/* 04B760 7F018D70 44824000 */  mtc1  $v0, $f8
/* 04B764 7F018D74 04410005 */  bgez  $v0, .L7F018D8C
/* 04B768 7F018D78 468042A0 */   cvt.s.w $f10, $f8
/* 04B76C 7F018D7C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B770 7F018D80 44818000 */  mtc1  $at, $f16
/* 04B774 7F018D84 00000000 */  nop
/* 04B778 7F018D88 46105280 */  add.s $f10, $f10, $f16
.L7F018D8C:
/* 04B77C 7F018D8C 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B780 7F018D90 44819000 */  mtc1  $at, $f18
/* 04B784 7F018D94 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 04B788 7F018D98 44813000 */  mtc1  $at, $f6
/* 04B78C 7F018D9C 46125102 */  mul.s $f4, $f10, $f18
/* 04B790 7F018DA0 3C01428C */  li    $at, 0x428C0000 # 70.000000
/* 04B794 7F018DA4 44818000 */  mtc1  $at, $f16
/* 04B798 7F018DA8 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A4) # $at, 0x8006
/* 04B79C 7F018DAC 46062202 */  mul.s $f8, $f4, $f6
/* 04B7A0 7F018DB0 46104280 */  add.s $f10, $f8, $f16
/* 04B7A4 7F018DB4 0C00262C */  jal   randomGetNext
/* 04B7A8 7F018DB8 E42A84E4 */   swc1  $f10, %lo(flt_CODE_bss_800695A4)($at)
/* 04B7AC 7F018DBC 44829000 */  mtc1  $v0, $f18
/* 04B7B0 7F018DC0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B7B4 7F018DC4 04410004 */  bgez  $v0, .L7F018DD8
/* 04B7B8 7F018DC8 46809120 */   cvt.s.w $f4, $f18
/* 04B7BC 7F018DCC 44813000 */  mtc1  $at, $f6
/* 04B7C0 7F018DD0 00000000 */  nop
/* 04B7C4 7F018DD4 46062100 */  add.s $f4, $f4, $f6
.L7F018DD8:
/* 04B7C8 7F018DD8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B7CC 7F018DDC 44814000 */  mtc1  $at, $f8
/* 04B7D0 7F018DE0 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 04B7D4 7F018DE4 44815000 */  mtc1  $at, $f10
/* 04B7D8 7F018DE8 46082402 */  mul.s $f16, $f4, $f8
/* 04B7DC 7F018DEC 3C01428C */  li    $at, 0x428C0000 # 70.000000
/* 04B7E0 7F018DF0 44813000 */  mtc1  $at, $f6
/* 04B7E4 7F018DF4 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A8) # $at, 0x8006
/* 04B7E8 7F018DF8 460A8482 */  mul.s $f18, $f16, $f10
/* 04B7EC 7F018DFC 46069100 */  add.s $f4, $f18, $f6
/* 04B7F0 7F018E00 0C00262C */  jal   randomGetNext
/* 04B7F4 7F018E04 E42484E8 */   swc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
/* 04B7F8 7F018E08 44824000 */  mtc1  $v0, $f8
/* 04B7FC 7F018E0C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B800 7F018E10 04410004 */  bgez  $v0, .L7F018E24
/* 04B804 7F018E14 46804420 */   cvt.s.w $f16, $f8
/* 04B808 7F018E18 44815000 */  mtc1  $at, $f10
/* 04B80C 7F018E1C 00000000 */  nop
/* 04B810 7F018E20 460A8400 */  add.s $f16, $f16, $f10
.L7F018E24:
/* 04B814 7F018E24 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B818 7F018E28 44819000 */  mtc1  $at, $f18
/* 04B81C 7F018E2C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 04B820 7F018E30 44812000 */  mtc1  $at, $f4
/* 04B824 7F018E34 46128182 */  mul.s $f6, $f16, $f18
/* 04B828 7F018E38 3C018004 */  lui   $at, %hi(D_80051B00) # $at, 0x8004
/* 04B82C 7F018E3C C42A7C28 */  lwc1  $f10, %lo(D_80051B00)($at)
/* 04B830 7F018E40 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B0) # $at, 0x8006
/* 04B834 7F018E44 46043201 */  sub.s $f8, $f6, $f4
/* 04B838 7F018E48 460A4402 */  mul.s $f16, $f8, $f10
/* 04B83C 7F018E4C 0C00262C */  jal   randomGetNext
/* 04B840 7F018E50 E43084F0 */   swc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
/* 04B844 7F018E54 44829000 */  mtc1  $v0, $f18
/* 04B848 7F018E58 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B84C 7F018E5C 04410004 */  bgez  $v0, .L7F018E70
/* 04B850 7F018E60 468091A0 */   cvt.s.w $f6, $f18
/* 04B854 7F018E64 44812000 */  mtc1  $at, $f4
/* 04B858 7F018E68 00000000 */  nop
/* 04B85C 7F018E6C 46043180 */  add.s $f6, $f6, $f4
.L7F018E70:
/* 04B860 7F018E70 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B864 7F018E74 44814000 */  mtc1  $at, $f8
/* 04B868 7F018E78 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 04B86C 7F018E7C 44818000 */  mtc1  $at, $f16
/* 04B870 7F018E80 46083282 */  mul.s $f10, $f6, $f8
/* 04B874 7F018E84 3C018004 */  lui   $at, %hi(D_80051B04) # $at, 0x8004
/* 04B878 7F018E88 C4247C2C */  lwc1  $f4, %lo(D_80051B04)($at)
/* 04B87C 7F018E8C 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B4) # $at, 0x8006
/* 04B880 7F018E90 46105481 */  sub.s $f18, $f10, $f16
/* 04B884 7F018E94 46049182 */  mul.s $f6, $f18, $f4
/* 04B888 7F018E98 0C00262C */  jal   randomGetNext
/* 04B88C 7F018E9C E42684F4 */   swc1  $f6, %lo(flt_CODE_bss_800695B4)($at)
/* 04B890 7F018EA0 44824000 */  mtc1  $v0, $f8
/* 04B894 7F018EA4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B898 7F018EA8 04410004 */  bgez  $v0, .L7F018EBC
/* 04B89C 7F018EAC 468042A0 */   cvt.s.w $f10, $f8
/* 04B8A0 7F018EB0 44818000 */  mtc1  $at, $f16
/* 04B8A4 7F018EB4 00000000 */  nop
/* 04B8A8 7F018EB8 46105280 */  add.s $f10, $f10, $f16
.L7F018EBC:
/* 04B8AC 7F018EBC 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B8B0 7F018EC0 44819000 */  mtc1  $at, $f18
/* 04B8B4 7F018EC4 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 04B8B8 7F018EC8 44813000 */  mtc1  $at, $f6
/* 04B8BC 7F018ECC 46125102 */  mul.s $f4, $f10, $f18
/* 04B8C0 7F018ED0 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 04B8C4 7F018ED4 44818000 */  mtc1  $at, $f16
/* 04B8C8 7F018ED8 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695BC) # $at, 0x8006
/* 04B8CC 7F018EDC 46062202 */  mul.s $f8, $f4, $f6
/* 04B8D0 7F018EE0 46104280 */  add.s $f10, $f8, $f16
/* 04B8D4 7F018EE4 0C00262C */  jal   randomGetNext
/* 04B8D8 7F018EE8 E42A84FC */   swc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
/* 04B8DC 7F018EEC 44829000 */  mtc1  $v0, $f18
/* 04B8E0 7F018EF0 3C038006 */  lui   $v1, %hi(flt_CODE_bss_800695E8) # $v1, 0x8006
/* 04B8E4 7F018EF4 44800000 */  mtc1  $zero, $f0
/* 04B8E8 7F018EF8 24638528 */  addiu $v1, %lo(flt_CODE_bss_800695E8) # addiu $v1, $v1, -0x7ad8
/* 04B8EC 7F018EFC 04410005 */  bgez  $v0, .L7F018F14
/* 04B8F0 7F018F00 46809120 */   cvt.s.w $f4, $f18
/* 04B8F4 7F018F04 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 04B8F8 7F018F08 44813000 */  mtc1  $at, $f6
/* 04B8FC 7F018F0C 00000000 */  nop
/* 04B900 7F018F10 46062100 */  add.s $f4, $f4, $f6
.L7F018F14:
/* 04B904 7F018F14 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 04B908 7F018F18 44814000 */  mtc1  $at, $f8
/* 04B90C 7F018F1C 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 04B910 7F018F20 44815000 */  mtc1  $at, $f10
/* 04B914 7F018F24 46082402 */  mul.s $f16, $f4, $f8
/* 04B918 7F018F28 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 04B91C 7F018F2C 44813000 */  mtc1  $at, $f6
/* 04B920 7F018F30 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695C0) # $at, 0x8006
/* 04B924 7F018F34 8FBF001C */  lw    $ra, 0x1c($sp)
/* 04B928 7F018F38 240D0001 */  li    $t5, 1
/* 04B92C 7F018F3C 460A8482 */  mul.s $f18, $f16, $f10
/* 04B930 7F018F40 46069100 */  add.s $f4, $f18, $f6
/* 04B934 7F018F44 E4248500 */  swc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
/* 04B938 7F018F48 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A4) # $at, 0x8006
/* 04B93C 7F018F4C C42884E4 */  lwc1  $f8, %lo(flt_CODE_bss_800695A4)($at)
/* 04B940 7F018F50 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A0) # $at, 0x8006
/* 04B944 7F018F54 E42884E0 */  swc1  $f8, %lo(flt_CODE_bss_800695A0)($at)
/* 04B948 7F018F58 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B0) # $at, 0x8006
/* 04B94C 7F018F5C C43084F0 */  lwc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
/* 04B950 7F018F60 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695AC) # $at, 0x8006
/* 04B954 7F018F64 E43084EC */  swc1  $f16, %lo(flt_CODE_bss_800695AC)($at)
/* 04B958 7F018F68 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695BC) # $at, 0x8006
/* 04B95C 7F018F6C C42A84FC */  lwc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
/* 04B960 7F018F70 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B8) # $at, 0x8006
/* 04B964 7F018F74 27BD00B8 */  addiu $sp, $sp, 0xb8
/* 04B968 7F018F78 E42A84F8 */  swc1  $f10, %lo(flt_CODE_bss_800695B8)($at)
/* 04B96C 7F018F7C 3C018006 */  lui   $at, %hi(bss_800695E4) # $at, 0x8006
/* 04B970 7F018F80 AC2D8524 */  sw    $t5, %lo(bss_800695E4)($at)
/* 04B974 7F018F84 E4600000 */  swc1  $f0, ($v1)
/* 04B978 7F018F88 E4600004 */  swc1  $f0, 4($v1)
/* 04B97C 7F018F8C 03E00008 */  jr    $ra
/* 04B980 7F018F90 E4600008 */   swc1  $f0, 8($v1)
)
#endif
#endif



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




#ifdef NONMATCHING

// https://decomp.me/scratch/8VrOg 71.40%

typedef struct some_model_struct
{
    s16 val;
};

Gfx * constructor_menu18_displaycast(Gfx *DL)
{
    struct coord3d sp244;
    struct coord3d sp238;
    struct coord3d sp22C;
    s32 padding;
    Mtxf sp1E8;
    ModelRenderData sp1A8;
    s32 padding3;
    Mtxf sp160;
    s32 sp15C;
    s32 sp158;
    s32 sp154;
    s32 sp150;
    LookAt * temp_v0;
    s32 padding2;
    f32 sp148;
    f32 sp144;
    union ModelRwData *unmrd;
    struct coord3d sp134;
    struct coord3d sp128;
    struct some_model_struct *srecord;
    ModelNode *mnode;
    Mtx spE0;

    s32 var_s1;
    s32 i;
    struct coord3d temp_f2;
    u8 *temp_v0_6;
    s32 var_t4;

    // struct copies.
    sp244 = D_8002BA78;
    sp238 = D_8002BA84;
    sp22C = D_8002BA90;
    sp1A8 = D_8002BA9C;
    sp148 = g_MenuTimer / 180.0f;
    sp134 = D_8002BADC;
    // end struct copies.

    if ((g_MenuTimer < 0) || (g_MenuTimer >= 0xB4))
    {
        sp144 = 0.0f;
    }
    else if (g_MenuTimer < 0x1E)
    {
        sp144 = g_MenuTimer / 30.0f;
    }
    else if (g_MenuTimer >= 0x97)
    {
        sp144 = (f32) (0xB4 - g_MenuTimer) / 30.0f;
    }
    else
    {
        sp144 = 1.0f;
    }

    DL = viSetFillColor(DL, 0, 0, 0);
    DL = viFillScreen(DL);

    flt_CODE_bss_800695A0 = ((flt_CODE_bss_800695A8 - flt_CODE_bss_800695A4) * sp148) + flt_CODE_bss_800695A4;
    flt_CODE_bss_800695AC = ((flt_CODE_bss_800695B4 - flt_CODE_bss_800695B0) * sp148) + flt_CODE_bss_800695B0;
    flt_CODE_bss_800695B8 = ((flt_CODE_bss_800695C0 - flt_CODE_bss_800695BC) * sp148) + flt_CODE_bss_800695BC;

    if (flt_CODE_bss_800695AC < 0.0f)
    {
        flt_CODE_bss_800695AC += 6.2831855f;
    }

    sp244.f[0] = (flt_CODE_bss_800695A0 * sinf(flt_CODE_bss_800695AC)) + (0.2f * flt_CODE_bss_800695A0 * cosf(flt_CODE_bss_800695AC));
    sp244.f[1] = flt_CODE_bss_800695B8;
    sp244.f[2] = (flt_CODE_bss_800695A0 * cosf(flt_CODE_bss_800695AC)) - (0.2f * flt_CODE_bss_800695A0 * sinf(flt_CODE_bss_800695AC));
    sp238.f[0] += cosf(flt_CODE_bss_800695AC) * 0.2f * flt_CODE_bss_800695A0;
    sp238.f[2] += -sinf(flt_CODE_bss_800695AC) * 0.2f * flt_CODE_bss_800695A0;

    temp_v0 = (LookAt *)dynAllocate7F0BD6F8(2);
    guLookAtReflect(&spE0, temp_v0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    gSPNumLights(DL++, 1);
    gSPLight(DL++, &gelogolight.l[0], 1);
    gSPLight(DL++, &gelogolight.a, 2);
    gSPLookAtX(DL++, &temp_v0->l[0]);
    gSPLookAtY(DL++, &temp_v0->l[1]);

    modelTickAnimQuarterSpeed(cast_model, g_ClockTimer, 1);
    modelSetDistanceDisabled(1);
    sub_GAME_7F073FC8(0);
    subcalcpos(cast_model);

    if (cast_model_weapon != NULL)
    {
        mnode = cast_model_weapon->obj->Switches[0];

        if (mnode != NULL)
        {
            unmrd = modelGetNodeRwData(cast_model_weapon, mnode);
            srecord = (struct some_model_struct *)unmrd;
            srecord->val = 0;
        }
    }

    if (cast_model_weapon != NULL)
    {
        mnode = cast_model_weapon->obj->Switches[2];

        if (mnode != NULL)
        {
            unmrd = modelGetNodeRwData(cast_model_weapon, mnode);
            ((struct ModelRwData_SwitchRecord *)unmrd)->visible = 0;
        }
    }

    sp1A8.mtxlist = dynAllocate(cast_model->obj->numMatrices << 6);
    sp1A8.unk_matrix = &sp1E8;
    matrix_4x4_set_identity(&sp1E8);
    subcalcmatrices(&sp1A8, cast_model);
    getsuboffset(cast_model, &sp128);

    var_s1 = 0;
    if (bss_800695E4 != 0)
    {
        flt_CODE_bss_800695E8.f[1] = sp128.f[1];
    }

    sp134.f[0] = (sp128.f[0] - flt_CODE_bss_800695E8.f[0]) / g_GlobalTimerDelta;
    sp134.f[1] = (sp128.f[1] - flt_CODE_bss_800695E8.f[1]) / g_GlobalTimerDelta;
    sp134.f[2] = (sp128.f[2] - flt_CODE_bss_800695E8.f[2]) / g_GlobalTimerDelta;

    if (bss_800695E4 != 0)
    {
        flt_CODE_bss_80069608.f[0] = sp134.f[0] / 0.050000012f;
        flt_CODE_bss_80069608.f[1] = sp134.f[1] / 0.050000012f;
        flt_CODE_bss_80069608.f[2] = sp134.f[2] / 0.050000012f;
    }

    if (g_ClockTimer > 0)
    {
        var_s1 = 0;
        do
        {
            flt_CODE_bss_80069608.f[0] = (0.95f * flt_CODE_bss_80069608.f[0]) + sp134.f[0];
            flt_CODE_bss_80069608.f[1] = (0.95f * flt_CODE_bss_80069608.f[1]) + sp134.f[1];
            flt_CODE_bss_80069608.f[2] = (0.95f * flt_CODE_bss_80069608.f[2]) + sp134.f[2];
        }
        while (++var_s1 < g_ClockTimer);

        if (sp134.f[0]);
        if (sp134.f[1]);
        if (sp134.f[2]);

        var_s1 = 0;
    }

    flt_CODE_bss_800695F8.f[0] = flt_CODE_bss_80069608.f[0] * 0.050000012f;
    flt_CODE_bss_800695F8.f[1] = flt_CODE_bss_80069608.f[1] * 0.050000012f;
    flt_CODE_bss_800695F8.f[2] = flt_CODE_bss_80069608.f[2] * 0.050000012f;

    flt_CODE_bss_800695E8.f[0] += flt_CODE_bss_800695F8.f[0] * g_GlobalTimerDelta;
    flt_CODE_bss_800695E8.f[1] += flt_CODE_bss_800695F8.f[1] * g_GlobalTimerDelta;
    flt_CODE_bss_800695E8.f[2] += flt_CODE_bss_800695F8.f[2] * g_GlobalTimerDelta;

    mtx4TransformVecInPlace(&cast_model->render_pos->pos, (struct coord3d *) &sp134);

    sp134.f[0] -= flt_CODE_bss_800695E8.f[0];
    sp134.f[1] -= flt_CODE_bss_800695E8.f[1];
    sp134.f[2] -= flt_CODE_bss_800695E8.f[2];

    if (bss_800695E4 != 0)
    {
        bss_800695E4 = 0;
        flt_CODE_bss_800695D8.f[0] = (f32) (sp134.f[0] / 0.050000012f);
        flt_CODE_bss_800695D8.f[1] = (f32) (sp134.f[1] / 0.050000012f);
        flt_CODE_bss_800695D8.f[2] = (f32) (sp134.f[2] / 0.050000012f);
    }

    if (g_ClockTimer > 0)
    {
        var_s1 = 0;
        do
        {
            flt_CODE_bss_800695D8.f[0] = (0.95f * flt_CODE_bss_800695D8.f[0]) + sp134.f[0];
            flt_CODE_bss_800695D8.f[1] = (0.95f * flt_CODE_bss_800695D8.f[1]) + sp134.f[1];
            flt_CODE_bss_800695D8.f[2] = (0.95f * flt_CODE_bss_800695D8.f[2]) + sp134.f[2];
        }
        while (++var_s1 < g_ClockTimer);

        flt_CODE_bss_800695D8.f[0] = (0.95f * flt_CODE_bss_800695D8.f[0]) + sp134.f[0];
        flt_CODE_bss_800695D8.f[1] = (0.95f * flt_CODE_bss_800695D8.f[1]) + sp134.f[1];
        flt_CODE_bss_800695D8.f[2] = (0.95f * flt_CODE_bss_800695D8.f[2]) + sp134.f[2];

        var_s1 = 0;
    }

    flt_CODE_bss_800695C8.f[0] = flt_CODE_bss_800695D8.f[0] * 0.050000012f;
    flt_CODE_bss_800695C8.f[1] = flt_CODE_bss_800695D8.f[1] * 0.050000012f;
    flt_CODE_bss_800695C8.f[2] = flt_CODE_bss_800695D8.f[2] * 0.050000012f;

    sp134.f[2] = flt_CODE_bss_800695E8.f[2] + flt_CODE_bss_800695C8.f[2];
    sp238.f[0] += flt_CODE_bss_800695E8.f[0] + flt_CODE_bss_800695C8.f[0];
    sp244.f[0] += flt_CODE_bss_800695E8.f[0];
    sp238.f[2] += flt_CODE_bss_800695E8.f[2] + flt_CODE_bss_800695C8.f[2];
    sp244.f[2] += flt_CODE_bss_800695E8.f[1] + 52.5f;
    sp244.f[2] += flt_CODE_bss_800695E8.f[2];
    sp238.f[2] += (flt_CODE_bss_800695E8.f[1] + flt_CODE_bss_800695C8.f[1]) - 10.0f;
    sp134.f[0] = flt_CODE_bss_800695E8.f[0] + flt_CODE_bss_800695C8.f[0];
    sp134.f[2] = (flt_CODE_bss_800695E8.f[1] + flt_CODE_bss_800695C8.f[1]) - 10.0f;

    matrix_4x4_7F059694(&sp1E8, sp244.f[0], sp244.f[1], sp244.f[2], flt_CODE_bss_800695E8.f[1], sp238.f[2], sp238.f[2], sp22C.f[0], sp22C.f[1], sp22C.f[2]);

    sp1A8.unk_matrix = &sp1E8;
    sp1A8.mtxlist = dynAllocate(cast_model->obj->numMatrices << 6);
    subcalcmatrices((ModelRenderData *) &sp1A8, cast_model);

    if (cast_model_weapon != NULL)
    {
        sp1A8.unk_matrix = modelFindNodeMtx(cast_model, cast_model_weapon->attachedto_objinst, 0);

        if (cast_model_weapon->attachedto_objinst == cast_model->obj->Switches[5])
        {
            matrix_4x4_set_rotation_around_z(3.1415927f, &sp160);
            matrix_4x4_multiply_in_place(sp1A8.unk_matrix, &sp160);
            sp1A8.unk_matrix = &sp160;
        }

        sp1A8.mtxlist = dynAllocate(cast_model_weapon->obj->numMatrices << 6);
        instcalcmatrices((ModelRenderData *) &sp1A8, cast_model_weapon);
    }

    sp1A8.unk20 = 7;
    sp1A8.unk04 = 1;
    sp1A8.gdl = DL++;
    sp1A8.unk08 = 3;
    subdraw((ModelRenderData *) &sp1A8, cast_model);

    if (cast_model_weapon != NULL)
    {
        subdraw((ModelRenderData *) &sp1A8, cast_model_weapon);
    }

    modelSetDistanceDisabled(0);

    for (; var_s1<cast_model->obj->numMatrices; var_s1++)
    {
        // hack: source address steps by sizeof(Mtxf), but can't get that to match
        matrix_4x4_copy(&((s8*)cast_model->render_pos)[var_s1*0x40], &sp160);
        matrix_4x4_f32_to_s32(&sp160, &((Mtxf*)cast_model->render_pos)[var_s1]);
    }

    if (cast_model_weapon != NULL)
    {
        for (i=0; i<cast_model_weapon->obj->numMatrices; i++)
        {
            // hack: source address steps by sizeof(Mtxf), but can't get that to match
            matrix_4x4_copy(&((s8*)cast_model_weapon->render_pos)[i*0x40], &sp160);
            matrix_4x4_f32_to_s32(&sp160, &((Mtxf*)cast_model_weapon->render_pos)[i]);
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
    gDPSetPrimColor(DL++, 0, 0, 0x00, 0x00, 0x00, (0xFF - (s32) (255.0f * sp144)) & 0xFF);
    gDPFillRectangle(DL++, 0, 0, 440, 330);
    gDPPipeSync(DL++);
    gDPSetColorDither(DL++, G_CD_BAYER);
    gDPSetTexturePersp(DL++, G_TP_PERSP);
    gDPSetTextureLOD(DL++, G_TL_LOD);

    DL = microcode_constructor(DL);

    if (full_actor_intro == 0)
    {
        temp_v0_6 = langGet(intro_char_table[intro_character_index].text1);
        textMeasure(&sp150, &sp154, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, 0);

        sp158 = 0x6C;
        sp15C = 0x13B - (sp154 / 2);

        DL = microcode_constructor_related_to_menus(DL, sp15C, 0x6C, sp15C + sp154 + 1, sp150 + 0x6D, 0);
/*
        if (sp158 & 0x78)
        {
            if (!(sp158 & 0x78))
            {
                var_t4 = (255.0f * sp144) / 2147483647;
            }
            else
            {
                var_t4 = -1;
            }
        }
        else
        {
            var_t4 = 255.0f * sp144;
            if (var_t4 < 0)
            {
                var_t4 = -1;
            }
        }
*/
        if ((s32)sp144 & 0x78)
        {
            var_t4 = (255.0f * sp144) / 2147483647;
        }
        else
        {
            var_t4 = -1;
        }

        DL = textRender(DL, &sp15C, &sp158, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, var_t4 | ~0xFF, viGetX(), viGetY(), 0, 0);
    }
/*
    if (sp158 & 0x78)
    {
        if (!(sp158 & 0x78))
        {
            var_t4 = (255.0f * sp144) / 2147483647;
        }
        else
        {
            var_t4 = -1;
        }
    }
    else
    {
        var_t4 = 255.0f * sp144;
        if (var_t4 < 0)
        {
            var_t4 = -1;
        }
    }
*/

    temp_v0_6 = langGet(intro_char_table[intro_character_index].text2);
    textMeasure(&sp150, &sp154, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    sp158 = 0x98;
    sp15C = 0x13B - (sp154 / 2);
    DL = microcode_constructor_related_to_menus(DL, sp15C, 0x98, sp15C + sp154 + 1, sp150 + 0x99, 0);
    DL = textRender(DL, &sp15C, &sp158, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, var_t4 | ~0xFF, viGetX(), viGetY(), 0, 0);

    temp_v0_6 = langGet(intro_char_table[intro_character_index].text3);
    textMeasure(&sp150, &sp154, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, 0);
    sp158 = 0xAE;
    sp15C = 0x13B - (sp154 / 2);
    DL = microcode_constructor_related_to_menus(DL, sp15C, 0xAE, sp15C + sp154 + 1, sp150 + 0xAF, 0);
    DL = textRender(DL, &sp15C, &sp158, temp_v0_6, ptrFontZurichBoldChars, ptrFontZurichBold, var_t4 | ~0xFF, viGetX(), viGetY(), 0, 0);

    return DL;
}

#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051B0C
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B10
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B14
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B18
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B1C
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B20
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B24
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B28
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B2C
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B30
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B34
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B38
.word 0x40490FDB /*3.1415927;*/

.text
glabel constructor_menu18_displaycast
/* 04DE58 7F019328 27BDFDB0 */  addiu $sp, $sp, -0x250
/* 04DE5C 7F01932C 3C0E8003 */  lui   $t6, %hi(D_8002BA78)
/* 04DE60 7F019330 AFBF004C */  sw    $ra, 0x4c($sp)
/* 04DE64 7F019334 AFB40048 */  sw    $s4, 0x48($sp)
/* 04DE68 7F019338 AFB30044 */  sw    $s3, 0x44($sp)
/* 04DE6C 7F01933C AFB20040 */  sw    $s2, 0x40($sp)
/* 04DE70 7F019340 AFB1003C */  sw    $s1, 0x3c($sp)
/* 04DE74 7F019344 AFB00038 */  sw    $s0, 0x38($sp)
/* 04DE78 7F019348 25CEBA78 */  addiu $t6, %lo(D_8002BA78) # addiu $t6, $t6, -0x4588
/* 04DE7C 7F01934C 8DC10000 */  lw    $at, ($t6)
/* 04DE80 7F019350 27AF0244 */  addiu $t7, $sp, 0x244
/* 04DE84 7F019354 8DCC0004 */  lw    $t4, 4($t6)
/* 04DE88 7F019358 ADE10000 */  sw    $at, ($t7)
/* 04DE8C 7F01935C 8DC10008 */  lw    $at, 8($t6)
/* 04DE90 7F019360 3C0D8003 */  lui   $t5, %hi(D_8002BA84)
/* 04DE94 7F019364 25ADBA84 */  addiu $t5, %lo(D_8002BA84) # addiu $t5, $t5, -0x457c
/* 04DE98 7F019368 ADEC0004 */  sw    $t4, 4($t7)
/* 04DE9C 7F01936C ADE10008 */  sw    $at, 8($t7)
/* 04DEA0 7F019370 8DA10000 */  lw    $at, ($t5)
/* 04DEA4 7F019374 27B90238 */  addiu $t9, $sp, 0x238
/* 04DEA8 7F019378 8DAF0004 */  lw    $t7, 4($t5)
/* 04DEAC 7F01937C AF210000 */  sw    $at, ($t9)
/* 04DEB0 7F019380 8DA10008 */  lw    $at, 8($t5)
/* 04DEB4 7F019384 3C0C8003 */  lui   $t4, %hi(D_8002BA90)
/* 04DEB8 7F019388 258CBA90 */  addiu $t4, %lo(D_8002BA90) # addiu $t4, $t4, -0x4570
/* 04DEBC 7F01938C AF2F0004 */  sw    $t7, 4($t9)
/* 04DEC0 7F019390 AF210008 */  sw    $at, 8($t9)
/* 04DEC4 7F019394 8D810000 */  lw    $at, ($t4)
/* 04DEC8 7F019398 27AE022C */  addiu $t6, $sp, 0x22c
/* 04DECC 7F01939C 8D990004 */  lw    $t9, 4($t4)
/* 04DED0 7F0193A0 ADC10000 */  sw    $at, ($t6)
/* 04DED4 7F0193A4 8D810008 */  lw    $at, 8($t4)
/* 04DED8 7F0193A8 3C0F8003 */  lui   $t7, %hi(D_8002BA9C)
/* 04DEDC 7F0193AC 25EFBA9C */  addiu $t7, %lo(D_8002BA9C) # addiu $t7, $t7, -0x4564
/* 04DEE0 7F0193B0 ADD90004 */  sw    $t9, 4($t6)
/* 04DEE4 7F0193B4 ADC10008 */  sw    $at, 8($t6)
/* 04DEE8 7F0193B8 00809825 */  move  $s3, $a0
/* 04DEEC 7F0193BC 25EE003C */  addiu $t6, $t7, 0x3c
/* 04DEF0 7F0193C0 27AD01A8 */  addiu $t5, $sp, 0x1a8
.L7F0193C4:
/* 04DEF4 7F0193C4 8DE10000 */  lw    $at, ($t7)
/* 04DEF8 7F0193C8 25EF000C */  addiu $t7, $t7, 0xc
/* 04DEFC 7F0193CC 25AD000C */  addiu $t5, $t5, 0xc
/* 04DF00 7F0193D0 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 04DF04 7F0193D4 8DE1FFF8 */  lw    $at, -8($t7)
/* 04DF08 7F0193D8 ADA1FFF8 */  sw    $at, -8($t5)
/* 04DF0C 7F0193DC 8DE1FFFC */  lw    $at, -4($t7)
/* 04DF10 7F0193E0 15EEFFF8 */  bne   $t7, $t6, .L7F0193C4
/* 04DF14 7F0193E4 ADA1FFFC */   sw    $at, -4($t5)
/* 04DF18 7F0193E8 8DE10000 */  lw    $at, ($t7)
/* 04DF1C 7F0193EC 3C028003 */  lui   $v0, %hi(g_MenuTimer)
/* 04DF20 7F0193F0 3C198003 */  lui   $t9, %hi(D_8002BADC)
/* 04DF24 7F0193F4 ADA10000 */  sw    $at, ($t5)
/* 04DF28 7F0193F8 8C42A8CC */  lw    $v0, %lo(g_MenuTimer)($v0)
/* 04DF2C 7F0193FC 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 04DF30 7F019400 44819000 */  mtc1  $at, $f18
/* 04DF34 7F019404 44827000 */  mtc1  $v0, $f14
/* 04DF38 7F019408 2739BADC */  addiu $t9, %lo(D_8002BADC) # addiu $t9, $t9, -0x4524
/* 04DF3C 7F01940C 8F210000 */  lw    $at, ($t9)
/* 04DF40 7F019410 46807020 */  cvt.s.w $f0, $f14
/* 04DF44 7F019414 8F2E0004 */  lw    $t6, 4($t9)
/* 04DF48 7F019418 27AC0134 */  addiu $t4, $sp, 0x134
/* 04DF4C 7F01941C AD810000 */  sw    $at, ($t4)
/* 04DF50 7F019420 8F210008 */  lw    $at, 8($t9)
/* 04DF54 7F019424 AD8E0004 */  sw    $t6, 4($t4)
/* 04DF58 7F019428 46120403 */  div.s $f16, $f0, $f18
/* 04DF5C 7F01942C 04400004 */  bltz  $v0, .L7F019440
/* 04DF60 7F019430 AD810008 */   sw    $at, 8($t4)
/* 04DF64 7F019434 284100B4 */  slti  $at, $v0, 0xb4
/* 04DF68 7F019438 54200005 */  bnezl $at, .L7F019450
/* 04DF6C 7F01943C 2841001E */   slti  $at, $v0, 0x1e
.L7F019440:
/* 04DF70 7F019440 44802000 */  mtc1  $zero, $f4
/* 04DF74 7F019444 10000018 */  b     .L7F0194A8
/* 04DF78 7F019448 E7A40144 */   swc1  $f4, 0x144($sp)
/* 04DF7C 7F01944C 2841001E */  slti  $at, $v0, 0x1e
.L7F019450:
/* 04DF80 7F019450 10200006 */  beqz  $at, .L7F01946C
/* 04DF84 7F019454 3C0141F0 */   li    $at, 0x41F00000 # 30.000000
/* 04DF88 7F019458 44815000 */  mtc1  $at, $f10
/* 04DF8C 7F01945C 00000000 */  nop
/* 04DF90 7F019460 460A0203 */  div.s $f8, $f0, $f10
/* 04DF94 7F019464 10000010 */  b     .L7F0194A8
/* 04DF98 7F019468 E7A80144 */   swc1  $f8, 0x144($sp)
.L7F01946C:
/* 04DF9C 7F01946C 28410097 */  slti  $at, $v0, 0x97
/* 04DFA0 7F019470 14200009 */  bnez  $at, .L7F019498
/* 04DFA4 7F019474 240F00B4 */   li    $t7, 180
/* 04DFA8 7F019478 01E26823 */  subu  $t5, $t7, $v0
/* 04DFAC 7F01947C 448D3000 */  mtc1  $t5, $f6
/* 04DFB0 7F019480 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 04DFB4 7F019484 44815000 */  mtc1  $at, $f10
/* 04DFB8 7F019488 46803120 */  cvt.s.w $f4, $f6
/* 04DFBC 7F01948C 460A2203 */  div.s $f8, $f4, $f10
/* 04DFC0 7F019490 10000005 */  b     .L7F0194A8
/* 04DFC4 7F019494 E7A80144 */   swc1  $f8, 0x144($sp)
.L7F019498:
/* 04DFC8 7F019498 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 04DFCC 7F01949C 44813000 */  mtc1  $at, $f6
/* 04DFD0 7F0194A0 00000000 */  nop
/* 04DFD4 7F0194A4 E7A60144 */  swc1  $f6, 0x144($sp)
.L7F0194A8:
/* 04DFD8 7F0194A8 02602025 */  move  $a0, $s3
/* 04DFDC 7F0194AC 00002825 */  move  $a1, $zero
/* 04DFE0 7F0194B0 00003025 */  move  $a2, $zero
/* 04DFE4 7F0194B4 00003825 */  move  $a3, $zero
/* 04DFE8 7F0194B8 0C0011B4 */  jal   viSetFillColor
/* 04DFEC 7F0194BC E7B00148 */   swc1  $f16, 0x148($sp)
/* 04DFF0 7F0194C0 0C000FBE */  jal   viFillScreen
/* 04DFF4 7F0194C4 00402025 */   move  $a0, $v0
/* 04DFF8 7F0194C8 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A4)
/* 04DFFC 7F0194CC C42095A4 */  lwc1  $f0, %lo(flt_CODE_bss_800695A4)($at)
/* 04E000 7F0194D0 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695A8)
/* 04E004 7F0194D4 C42495A8 */  lwc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
/* 04E008 7F0194D8 C7B00148 */  lwc1  $f16, 0x148($sp)
/* 04E00C 7F0194DC 3C118007 */  lui   $s1, %hi(flt_CODE_bss_800695A0)
/* 04E010 7F0194E0 46002281 */  sub.s $f10, $f4, $f0
/* 04E014 7F0194E4 263195A0 */  addiu $s1, %lo(flt_CODE_bss_800695A0) # addiu $s1, $s1, -0x6a60
/* 04E018 7F0194E8 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B0)
/* 04E01C 7F0194EC 3C108007 */  lui   $s0, %hi(flt_CODE_bss_800695AC)
/* 04E020 7F0194F0 46105202 */  mul.s $f8, $f10, $f16
/* 04E024 7F0194F4 261095AC */  addiu $s0, %lo(flt_CODE_bss_800695AC) # addiu $s0, $s0, -0x6a54
/* 04E028 7F0194F8 3C128007 */  lui   $s2, %hi(flt_CODE_bss_800695B8)
/* 04E02C 7F0194FC 265295B8 */  addiu $s2, %lo(flt_CODE_bss_800695B8) # addiu $s2, $s2, -0x6a48
/* 04E030 7F019500 00409825 */  move  $s3, $v0
/* 04E034 7F019504 46004180 */  add.s $f6, $f8, $f0
/* 04E038 7F019508 E6260000 */  swc1  $f6, ($s1)
/* 04E03C 7F01950C C42295B0 */  lwc1  $f2, %lo(flt_CODE_bss_800695B0)($at)
/* 04E040 7F019510 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695B4)
/* 04E044 7F019514 C42495B4 */  lwc1  $f4, %lo(flt_CODE_bss_800695B4)($at)
/* 04E048 7F019518 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695BC)
/* 04E04C 7F01951C 46022281 */  sub.s $f10, $f4, $f2
/* 04E050 7F019520 46105202 */  mul.s $f8, $f10, $f16
/* 04E054 7F019524 46024180 */  add.s $f6, $f8, $f2
/* 04E058 7F019528 E6060000 */  swc1  $f6, ($s0)
/* 04E05C 7F01952C C42C95BC */  lwc1  $f12, %lo(flt_CODE_bss_800695BC)($at)
/* 04E060 7F019530 3C018007 */  lui   $at, %hi(flt_CODE_bss_800695C0)
/* 04E064 7F019534 C42495C0 */  lwc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
/* 04E068 7F019538 C60E0000 */  lwc1  $f14, ($s0)
/* 04E06C 7F01953C 460C2281 */  sub.s $f10, $f4, $f12
/* 04E070 7F019540 44802000 */  mtc1  $zero, $f4
/* 04E074 7F019544 46105202 */  mul.s $f8, $f10, $f16
/* 04E078 7F019548 4604703C */  c.lt.s $f14, $f4
/* 04E07C 7F01954C 460C4180 */  add.s $f6, $f8, $f12
/* 04E080 7F019550 45000006 */  bc1f  .L7F01956C
/* 04E084 7F019554 E6460000 */   swc1  $f6, ($s2)
/* 04E088 7F019558 3C018005 */  lui   $at, %hi(D_80051B0C)
/* 04E08C 7F01955C C42A1B0C */  lwc1  $f10, %lo(D_80051B0C)($at)
/* 04E090 7F019560 460A7200 */  add.s $f8, $f14, $f10
/* 04E094 7F019564 E6080000 */  swc1  $f8, ($s0)
/* 04E098 7F019568 C60E0000 */  lwc1  $f14, ($s0)
.L7F01956C:
/* 04E09C 7F01956C 0FC15FAB */  jal   sinf
/* 04E0A0 7F019570 46007306 */   mov.s $f12, $f14
/* 04E0A4 7F019574 E7A00078 */  swc1  $f0, 0x78($sp)
/* 04E0A8 7F019578 0FC15FA8 */  jal   cosf
/* 04E0AC 7F01957C C60C0000 */   lwc1  $f12, ($s0)
/* 04E0B0 7F019580 3C018005 */  lui   $at, %hi(D_80051B10)
/* 04E0B4 7F019584 C4261B10 */  lwc1  $f6, %lo(D_80051B10)($at)
/* 04E0B8 7F019588 C6220000 */  lwc1  $f2, ($s1)
/* 04E0BC 7F01958C C7A80078 */  lwc1  $f8, 0x78($sp)
/* 04E0C0 7F019590 46060102 */  mul.s $f4, $f0, $f6
/* 04E0C4 7F019594 C60C0000 */  lwc1  $f12, ($s0)
/* 04E0C8 7F019598 46022282 */  mul.s $f10, $f4, $f2
/* 04E0CC 7F01959C 00000000 */  nop
/* 04E0D0 7F0195A0 46081182 */  mul.s $f6, $f2, $f8
/* 04E0D4 7F0195A4 C6480000 */  lwc1  $f8, ($s2)
/* 04E0D8 7F0195A8 E7A80248 */  swc1  $f8, 0x248($sp)
/* 04E0DC 7F0195AC 46065100 */  add.s $f4, $f10, $f6
/* 04E0E0 7F0195B0 0FC15FA8 */  jal   cosf
/* 04E0E4 7F0195B4 E7A40244 */   swc1  $f4, 0x244($sp)
/* 04E0E8 7F0195B8 E7A00078 */  swc1  $f0, 0x78($sp)
/* 04E0EC 7F0195BC 0FC15FAB */  jal   sinf
/* 04E0F0 7F0195C0 C60C0000 */   lwc1  $f12, ($s0)
/* 04E0F4 7F0195C4 C6220000 */  lwc1  $f2, ($s1)
/* 04E0F8 7F0195C8 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 04E0FC 7F0195CC 3C018005 */  lui   $at, %hi(D_80051B14)
/* 04E100 7F0195D0 C4241B14 */  lwc1  $f4, %lo(D_80051B14)($at)
/* 04E104 7F0195D4 460A1182 */  mul.s $f6, $f2, $f10
/* 04E108 7F0195D8 C60C0000 */  lwc1  $f12, ($s0)
/* 04E10C 7F0195DC 46040202 */  mul.s $f8, $f0, $f4
/* 04E110 7F0195E0 00000000 */  nop
/* 04E114 7F0195E4 46024282 */  mul.s $f10, $f8, $f2
/* 04E118 7F0195E8 460A3101 */  sub.s $f4, $f6, $f10
/* 04E11C 7F0195EC 0FC15FA8 */  jal   cosf
/* 04E120 7F0195F0 E7A4024C */   swc1  $f4, 0x24c($sp)
/* 04E124 7F0195F4 3C018005 */  lui   $at, %hi(D_80051B18)
/* 04E128 7F0195F8 C4281B18 */  lwc1  $f8, %lo(D_80051B18)($at)
/* 04E12C 7F0195FC C62A0000 */  lwc1  $f10, ($s1)
/* 04E130 7F019600 C60C0000 */  lwc1  $f12, ($s0)
/* 04E134 7F019604 46080182 */  mul.s $f6, $f0, $f8
/* 04E138 7F019608 C7A80238 */  lwc1  $f8, 0x238($sp)
/* 04E13C 7F01960C 460A3102 */  mul.s $f4, $f6, $f10
/* 04E140 7F019610 46044180 */  add.s $f6, $f8, $f4
/* 04E144 7F019614 0FC15FAB */  jal   sinf
/* 04E148 7F019618 E7A60238 */   swc1  $f6, 0x238($sp)
/* 04E14C 7F01961C 3C018005 */  lui   $at, %hi(D_80051B1C)
/* 04E150 7F019620 C4281B1C */  lwc1  $f8, %lo(D_80051B1C)($at)
/* 04E154 7F019624 46000287 */  neg.s $f10, $f0
/* 04E158 7F019628 C6260000 */  lwc1  $f6, ($s1)
/* 04E15C 7F01962C 46085102 */  mul.s $f4, $f10, $f8
/* 04E160 7F019630 C7A80240 */  lwc1  $f8, 0x240($sp)
/* 04E164 7F019634 24040002 */  li    $a0, 2
/* 04E168 7F019638 46062282 */  mul.s $f10, $f4, $f6
/* 04E16C 7F01963C 460A4100 */  add.s $f4, $f8, $f10
/* 04E170 7F019640 0FC2F5BE */  jal   dynAllocate7F0BD6F8
/* 04E174 7F019644 E7A40240 */   swc1  $f4, 0x240($sp)
/* 04E178 7F019648 44800000 */  mtc1  $zero, $f0
/* 04E17C 7F01964C 3C01457A */  li    $at, 0x457A0000 # 4000.000000
/* 04E180 7F019650 44813000 */  mtc1  $at, $f6
/* 04E184 7F019654 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 04E188 7F019658 44814000 */  mtc1  $at, $f8
/* 04E18C 7F01965C 44060000 */  mfc1  $a2, $f0
/* 04E190 7F019660 44070000 */  mfc1  $a3, $f0
/* 04E194 7F019664 00408025 */  move  $s0, $v0
/* 04E198 7F019668 27A400E0 */  addiu $a0, $sp, 0xe0
/* 04E19C 7F01966C 00402825 */  move  $a1, $v0
/* 04E1A0 7F019670 E7A00014 */  swc1  $f0, 0x14($sp)
/* 04E1A4 7F019674 E7A00018 */  swc1  $f0, 0x18($sp)
/* 04E1A8 7F019678 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 04E1AC 7F01967C E7A00020 */  swc1  $f0, 0x20($sp)
/* 04E1B0 7F019680 E7A00028 */  swc1  $f0, 0x28($sp)
/* 04E1B4 7F019684 E7A60010 */  swc1  $f6, 0x10($sp)
/* 04E1B8 7F019688 0C005CDC */  jal   guLookAtReflect
/* 04E1BC 7F01968C E7A80024 */   swc1  $f8, 0x24($sp)
/* 04E1C0 7F019690 02601025 */  move  $v0, $s3
/* 04E1C4 7F019694 26730008 */  addiu $s3, $s3, 8
/* 04E1C8 7F019698 3C0BBC00 */  lui   $t3, (0xBC000002 >> 16) # lui $t3, 0xbc00
/* 04E1CC 7F01969C 3C188000 */  lui   $t8, (0x80000040 >> 16) # lui $t8, 0x8000
/* 04E1D0 7F0196A0 37180040 */  ori   $t8, (0x80000040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 04E1D4 7F0196A4 356B0002 */  ori   $t3, (0xBC000002 & 0xFFFF) # ori $t3, $t3, 2
/* 04E1D8 7F0196A8 02601825 */  move  $v1, $s3
/* 04E1DC 7F0196AC 26730008 */  addiu $s3, $s3, 8
/* 04E1E0 7F0196B0 AC4B0000 */  sw    $t3, ($v0)
/* 04E1E4 7F0196B4 AC580004 */  sw    $t8, 4($v0)
/* 04E1E8 7F0196B8 3C0C0386 */  lui   $t4, (0x03860010 >> 16) # lui $t4, 0x386
/* 04E1EC 7F0196BC 3C198003 */  lui   $t9, %hi(gelogolight + 0x8)
/* 04E1F0 7F0196C0 2739A978 */  addiu $t9, %lo(gelogolight + 0x8) # addiu $t9, $t9, -0x5688
/* 04E1F4 7F0196C4 358C0010 */  ori   $t4, (0x03860010 & 0xFFFF) # ori $t4, $t4, 0x10
/* 04E1F8 7F0196C8 02602025 */  move  $a0, $s3
/* 04E1FC 7F0196CC 26730008 */  addiu $s3, $s3, 8
/* 04E200 7F0196D0 AC6C0000 */  sw    $t4, ($v1)
/* 04E204 7F0196D4 AC790004 */  sw    $t9, 4($v1)
/* 04E208 7F0196D8 3C0E0388 */  lui   $t6, (0x03880010 >> 16) # lui $t6, 0x388
/* 04E20C 7F0196DC 3C0F8003 */  lui   $t7, %hi(gelogolight)
/* 04E210 7F0196E0 25EFA970 */  addiu $t7, %lo(gelogolight) # addiu $t7, $t7, -0x5690
/* 04E214 7F0196E4 35CE0010 */  ori   $t6, (0x03880010 & 0xFFFF) # ori $t6, $t6, 0x10
/* 04E218 7F0196E8 02602825 */  move  $a1, $s3
/* 04E21C 7F0196EC AC8E0000 */  sw    $t6, ($a0)
/* 04E220 7F0196F0 AC8F0004 */  sw    $t7, 4($a0)
/* 04E224 7F0196F4 3C0D0384 */  lui   $t5, (0x03840010 >> 16) # lui $t5, 0x384
/* 04E228 7F0196F8 35AD0010 */  ori   $t5, (0x03840010 & 0xFFFF) # ori $t5, $t5, 0x10
/* 04E22C 7F0196FC ACAD0000 */  sw    $t5, ($a1)
/* 04E230 7F019700 ACB00004 */  sw    $s0, 4($a1)
/* 04E234 7F019704 26730008 */  addiu $s3, $s3, 8
/* 04E238 7F019708 02603825 */  move  $a3, $s3
/* 04E23C 7F01970C 3C0B0382 */  lui   $t3, (0x03820010 >> 16) # lui $t3, 0x382
/* 04E240 7F019710 356B0010 */  ori   $t3, (0x03820010 & 0xFFFF) # ori $t3, $t3, 0x10
/* 04E244 7F019714 26180010 */  addiu $t8, $s0, 0x10
/* 04E248 7F019718 3C148003 */  lui   $s4, %hi(cast_model)
/* 04E24C 7F01971C 2694B5F4 */  addiu $s4, %lo(cast_model) # addiu $s4, $s4, -0x4a0c
/* 04E250 7F019720 ACF80004 */  sw    $t8, 4($a3)
/* 04E254 7F019724 ACEB0000 */  sw    $t3, ($a3)
/* 04E258 7F019728 3C058005 */  lui   $a1, %hi(g_ClockTimer)
/* 04E25C 7F01972C 26730008 */  addiu $s3, $s3, 8
/* 04E260 7F019730 8CA58374 */  lw    $a1, %lo(g_ClockTimer)($a1)
/* 04E264 7F019734 8E840000 */  lw    $a0, ($s4)
/* 04E268 7F019738 0FC1C2BB */  jal   modelTickAnimQuarterSpeed
/* 04E26C 7F01973C 24060001 */   li    $a2, 1
/* 04E270 7F019740 0FC1B100 */  jal   modelSetDistanceDisabled
/* 04E274 7F019744 24040001 */   li    $a0, 1
/* 04E278 7F019748 0FC1CFF2 */  jal   sub_GAME_7F073FC8
/* 04E27C 7F01974C 00002025 */   move  $a0, $zero
/* 04E280 7F019750 0FC1B5AC */  jal   subcalcpos
/* 04E284 7F019754 8E840000 */   lw    $a0, ($s4)
/* 04E288 7F019758 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E28C 7F01975C 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E290 7F019760 10E0000B */  beqz  $a3, .L7F019790
/* 04E294 7F019764 00000000 */   nop
/* 04E298 7F019768 8CEC0008 */  lw    $t4, 8($a3)
/* 04E29C 7F01976C 8D990008 */  lw    $t9, 8($t4)
/* 04E2A0 7F019770 8F250000 */  lw    $a1, ($t9)
/* 04E2A4 7F019774 10A00006 */  beqz  $a1, .L7F019790
/* 04E2A8 7F019778 00000000 */   nop
/* 04E2AC 7F01977C 0FC1B1E7 */  jal   modelGetNodeRwData
/* 04E2B0 7F019780 00E02025 */   move  $a0, $a3
/* 04E2B4 7F019784 A4400000 */  sh    $zero, ($v0)
/* 04E2B8 7F019788 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E2BC 7F01978C 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
.L7F019790:
/* 04E2C0 7F019790 50E0000A */  beql  $a3, $zero, .L7F0197BC
/* 04E2C4 7F019794 8E8D0000 */   lw    $t5, ($s4)
/* 04E2C8 7F019798 8CEE0008 */  lw    $t6, 8($a3)
/* 04E2CC 7F01979C 8DCF0008 */  lw    $t7, 8($t6)
/* 04E2D0 7F0197A0 8DE50008 */  lw    $a1, 8($t7)
/* 04E2D4 7F0197A4 50A00005 */  beql  $a1, $zero, .L7F0197BC
/* 04E2D8 7F0197A8 8E8D0000 */   lw    $t5, ($s4)
/* 04E2DC 7F0197AC 0FC1B1E7 */  jal   modelGetNodeRwData
/* 04E2E0 7F0197B0 00E02025 */   move  $a0, $a3
/* 04E2E4 7F0197B4 AC400000 */  sw    $zero, ($v0)
/* 04E2E8 7F0197B8 8E8D0000 */  lw    $t5, ($s4)
.L7F0197BC:
/* 04E2EC 7F0197BC 8DAB0008 */  lw    $t3, 8($t5)
/* 04E2F0 7F0197C0 8564000E */  lh    $a0, 0xe($t3)
/* 04E2F4 7F0197C4 0004C180 */  sll   $t8, $a0, 6
/* 04E2F8 7F0197C8 0FC2F5C5 */  jal   dynAllocate
/* 04E2FC 7F0197CC 03002025 */   move  $a0, $t8
/* 04E300 7F0197D0 27B201E8 */  addiu $s2, $sp, 0x1e8
/* 04E304 7F0197D4 AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04E308 7F0197D8 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 04E30C 7F0197DC 02402025 */   move  $a0, $s2
/* 04E310 7F0197E0 AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04E314 7F0197E4 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04E318 7F0197E8 0FC1BCBE */  jal   subcalcmatrices
/* 04E31C 7F0197EC 8E850000 */   lw    $a1, ($s4)
/* 04E320 7F0197F0 8E840000 */  lw    $a0, ($s4)
/* 04E324 7F0197F4 0FC1B2E6 */  jal   getsuboffset
/* 04E328 7F0197F8 27A50128 */   addiu $a1, $sp, 0x128
/* 04E32C 7F0197FC 3C068007 */  lui   $a2, %hi(bss_800695E4)
/* 04E330 7F019800 24C695E4 */  addiu $a2, %lo(bss_800695E4) # addiu $a2, $a2, -0x6a1c
/* 04E334 7F019804 8CC20000 */  lw    $v0, ($a2)
/* 04E338 7F019808 00008825 */  move  $s1, $zero
/* 04E33C 7F01980C 3C038005 */  lui   $v1, %hi(g_ClockTimer)
/* 04E340 7F019810 10400005 */  beqz  $v0, .L7F019828
/* 04E344 7F019814 00000000 */   nop
/* 04E348 7F019818 C7AA012C */  lwc1  $f10, 0x12c($sp)
/* 04E34C 7F01981C 3C108007 */  lui   $s0, %hi(flt_CODE_bss_800695E8)
/* 04E350 7F019820 261095E8 */  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x6a18
/* 04E354 7F019824 E60A0004 */  swc1  $f10, 4($s0)
.L7F019828:
/* 04E358 7F019828 3C108007 */  lui   $s0, %hi(flt_CODE_bss_800695E8)
/* 04E35C 7F01982C 261095E8 */  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x6a18
/* 04E360 7F019830 C6040000 */  lwc1  $f4, ($s0)
/* 04E364 7F019834 C7A60128 */  lwc1  $f6, 0x128($sp)
/* 04E368 7F019838 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 04E36C 7F01983C E7A4006C */  swc1  $f4, 0x6c($sp)
/* 04E370 7F019840 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 04E374 7F019844 C6040004 */  lwc1  $f4, 4($s0)
/* 04E378 7F019848 C4328378 */  lwc1  $f18, %lo(g_GlobalTimerDelta)($at)
/* 04E37C 7F01984C 46083281 */  sub.s $f10, $f6, $f8
/* 04E380 7F019850 E7A40064 */  swc1  $f4, 0x64($sp)
/* 04E384 7F019854 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 04E388 7F019858 C7A6012C */  lwc1  $f6, 0x12c($sp)
/* 04E38C 7F01985C C6040008 */  lwc1  $f4, 8($s0)
/* 04E390 7F019860 46125083 */  div.s $f2, $f10, $f18
/* 04E394 7F019864 E7A40060 */  swc1  $f4, 0x60($sp)
/* 04E398 7F019868 46083281 */  sub.s $f10, $f6, $f8
/* 04E39C 7F01986C C7A80060 */  lwc1  $f8, 0x60($sp)
/* 04E3A0 7F019870 C7A60130 */  lwc1  $f6, 0x130($sp)
/* 04E3A4 7F019874 46125303 */  div.s $f12, $f10, $f18
/* 04E3A8 7F019878 46083281 */  sub.s $f10, $f6, $f8
/* 04E3AC 7F01987C 1040000B */  beqz  $v0, .L7F0198AC
/* 04E3B0 7F019880 46125383 */   div.s $f14, $f10, $f18
/* 04E3B4 7F019884 3C018005 */  lui   $at, %hi(D_80051B20)
/* 04E3B8 7F019888 C4301B20 */  lwc1  $f16, %lo(D_80051B20)($at)
/* 04E3BC 7F01988C 3C028007 */  lui   $v0, %hi(flt_CODE_bss_80069608)
/* 04E3C0 7F019890 24429608 */  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x69f8
/* 04E3C4 7F019894 46101103 */  div.s $f4, $f2, $f16
/* 04E3C8 7F019898 46106183 */  div.s $f6, $f12, $f16
/* 04E3CC 7F01989C E4440000 */  swc1  $f4, ($v0)
/* 04E3D0 7F0198A0 46107203 */  div.s $f8, $f14, $f16
/* 04E3D4 7F0198A4 E4460004 */  swc1  $f6, 4($v0)
/* 04E3D8 7F0198A8 E4480008 */  swc1  $f8, 8($v0)
.L7F0198AC:
/* 04E3DC 7F0198AC 8C638374 */  lw    $v1, %lo(g_ClockTimer)($v1)
/* 04E3E0 7F0198B0 3C028007 */  lui   $v0, %hi(flt_CODE_bss_80069608)
/* 04E3E4 7F0198B4 3C018005 */  lui   $at, %hi(D_80051B24)
/* 04E3E8 7F0198B8 C4301B24 */  lwc1  $f16, %lo(D_80051B24)($at)
/* 04E3EC 7F0198BC 24429608 */  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x69f8
/* 04E3F0 7F0198C0 E7A20134 */  swc1  $f2, 0x134($sp)
/* 04E3F4 7F0198C4 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04E3F8 7F0198C8 18600025 */  blez  $v1, .L7F019960
/* 04E3FC 7F0198CC E7AE013C */   swc1  $f14, 0x13c($sp)
/* 04E400 7F0198D0 3C018005 */  lui   $at, %hi(D_80051B28)
/* 04E404 7F0198D4 C4201B28 */  lwc1  $f0, %lo(D_80051B28)($at)
/* 04E408 7F0198D8 C4440000 */  lwc1  $f4, ($v0)
/* 04E40C 7F0198DC 26310001 */  addiu $s1, $s1, 1
/* 04E410 7F0198E0 0223082A */  slt   $at, $s1, $v1
/* 04E414 7F0198E4 46040282 */  mul.s $f10, $f0, $f4
/* 04E418 7F0198E8 10200010 */  beqz  $at, .L7F01992C
/* 04E41C 7F0198EC C4480004 */   lwc1  $f8, 4($v0)
.L7F0198F0:
/* 04E420 7F0198F0 46080182 */  mul.s $f6, $f0, $f8
/* 04E424 7F0198F4 460A1100 */  add.s $f4, $f2, $f10
/* 04E428 7F0198F8 C4480008 */  lwc1  $f8, 8($v0)
/* 04E42C 7F0198FC 26310001 */  addiu $s1, $s1, 1
/* 04E430 7F019900 0223082A */  slt   $at, $s1, $v1
/* 04E434 7F019904 46080282 */  mul.s $f10, $f0, $f8
/* 04E438 7F019908 E4440000 */  swc1  $f4, ($v0)
/* 04E43C 7F01990C 46066180 */  add.s $f6, $f12, $f6
/* 04E440 7F019910 C4440000 */  lwc1  $f4, ($v0)
/* 04E444 7F019914 E4460004 */  swc1  $f6, 4($v0)
/* 04E448 7F019918 460A7180 */  add.s $f6, $f14, $f10
/* 04E44C 7F01991C 46040282 */  mul.s $f10, $f0, $f4
/* 04E450 7F019920 C4480004 */  lwc1  $f8, 4($v0)
/* 04E454 7F019924 1420FFF2 */  bnez  $at, .L7F0198F0
/* 04E458 7F019928 E4460008 */   swc1  $f6, 8($v0)
.L7F01992C:
/* 04E45C 7F01992C 46080182 */  mul.s $f6, $f0, $f8
/* 04E460 7F019930 C4480008 */  lwc1  $f8, 8($v0)
/* 04E464 7F019934 460A1100 */  add.s $f4, $f2, $f10
/* 04E468 7F019938 46080282 */  mul.s $f10, $f0, $f8
/* 04E46C 7F01993C E4440000 */  swc1  $f4, ($v0)
/* 04E470 7F019940 46066180 */  add.s $f6, $f12, $f6
/* 04E474 7F019944 E4460004 */  swc1  $f6, 4($v0)
/* 04E478 7F019948 460A7180 */  add.s $f6, $f14, $f10
/* 04E47C 7F01994C E4460008 */  swc1  $f6, 8($v0)
/* 04E480 7F019950 E7AE013C */  swc1  $f14, 0x13c($sp)
/* 04E484 7F019954 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04E488 7F019958 E7A20134 */  swc1  $f2, 0x134($sp)
/* 04E48C 7F01995C 00008825 */  move  $s1, $zero
.L7F019960:
/* 04E490 7F019960 C4440000 */  lwc1  $f4, ($v0)
/* 04E494 7F019964 C4480004 */  lwc1  $f8, 4($v0)
/* 04E498 7F019968 3C038007 */  lui   $v1, %hi(flt_CODE_bss_800695F8)
/* 04E49C 7F01996C 46102182 */  mul.s $f6, $f4, $f16
/* 04E4A0 7F019970 C4440008 */  lwc1  $f4, 8($v0)
/* 04E4A4 7F019974 246395F8 */  addiu $v1, %lo(flt_CODE_bss_800695F8) # addiu $v1, $v1, -0x6a08
/* 04E4A8 7F019978 46104282 */  mul.s $f10, $f8, $f16
/* 04E4AC 7F01997C C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 04E4B0 7F019980 8E8C0000 */  lw    $t4, ($s4)
/* 04E4B4 7F019984 27A50134 */  addiu $a1, $sp, 0x134
/* 04E4B8 7F019988 E4660000 */  swc1  $f6, ($v1)
/* 04E4BC 7F01998C 46102182 */  mul.s $f6, $f4, $f16
/* 04E4C0 7F019990 E46A0004 */  swc1  $f10, 4($v1)
/* 04E4C4 7F019994 C46A0000 */  lwc1  $f10, ($v1)
/* 04E4C8 7F019998 46125102 */  mul.s $f4, $f10, $f18
/* 04E4CC 7F01999C E4660008 */  swc1  $f6, 8($v1)
/* 04E4D0 7F0199A0 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 04E4D4 7F0199A4 46044180 */  add.s $f6, $f8, $f4
/* 04E4D8 7F0199A8 C4680004 */  lwc1  $f8, 4($v1)
/* 04E4DC 7F0199AC 46124102 */  mul.s $f4, $f8, $f18
/* 04E4E0 7F0199B0 E6060000 */  swc1  $f6, ($s0)
/* 04E4E4 7F0199B4 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 04E4E8 7F0199B8 46045180 */  add.s $f6, $f10, $f4
/* 04E4EC 7F0199BC C46A0008 */  lwc1  $f10, 8($v1)
/* 04E4F0 7F0199C0 46125102 */  mul.s $f4, $f10, $f18
/* 04E4F4 7F0199C4 E6060004 */  swc1  $f6, 4($s0)
/* 04E4F8 7F0199C8 46044180 */  add.s $f6, $f8, $f4
/* 04E4FC 7F0199CC E6060008 */  swc1  $f6, 8($s0)
/* 04E500 7F0199D0 0FC1611D */  jal   mtx4TransformVecInPlace
/* 04E504 7F0199D4 8D84000C */   lw    $a0, 0xc($t4)
/* 04E508 7F0199D8 C60A0004 */  lwc1  $f10, 4($s0)
/* 04E50C 7F0199DC C6040008 */  lwc1  $f4, 8($s0)
/* 04E510 7F0199E0 3C068007 */  lui   $a2, %hi(bss_800695E4)
/* 04E514 7F0199E4 24C695E4 */  addiu $a2, %lo(bss_800695E4) # addiu $a2, $a2, -0x6a1c
/* 04E518 7F0199E8 8CD90000 */  lw    $t9, ($a2)
/* 04E51C 7F0199EC 3C018005 */  lui   $at, %hi(D_80051B30)
/* 04E520 7F0199F0 E7AA0064 */  swc1  $f10, 0x64($sp)
/* 04E524 7F0199F4 E7A40060 */  swc1  $f4, 0x60($sp)
/* 04E528 7F0199F8 C7A20134 */  lwc1  $f2, 0x134($sp)
/* 04E52C 7F0199FC C7AC0138 */  lwc1  $f12, 0x138($sp)
/* 04E530 7F019A00 C7AE013C */  lwc1  $f14, 0x13c($sp)
/* 04E534 7F019A04 C6120000 */  lwc1  $f18, ($s0)
/* 04E538 7F019A08 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 04E53C 7F019A0C C7A60060 */  lwc1  $f6, 0x60($sp)
/* 04E540 7F019A10 C4201B30 */  lwc1  $f0, %lo(D_80051B30)($at)
/* 04E544 7F019A14 3C018005 */  lui   $at, %hi(D_80051B34)
/* 04E548 7F019A18 C4301B34 */  lwc1  $f16, %lo(D_80051B34)($at)
/* 04E54C 7F019A1C 46121081 */  sub.s $f2, $f2, $f18
/* 04E550 7F019A20 46086301 */  sub.s $f12, $f12, $f8
/* 04E554 7F019A24 1320000A */  beqz  $t9, .L7F019A50
/* 04E558 7F019A28 46067381 */   sub.s $f14, $f14, $f6
/* 04E55C 7F019A2C 46101283 */  div.s $f10, $f2, $f16
/* 04E560 7F019A30 3C028007 */  lui   $v0, %hi(flt_CODE_bss_800695D8)
/* 04E564 7F019A34 244295D8 */  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x6a28
/* 04E568 7F019A38 ACC00000 */  sw    $zero, ($a2)
/* 04E56C 7F019A3C 46106203 */  div.s $f8, $f12, $f16
/* 04E570 7F019A40 E44A0000 */  swc1  $f10, ($v0)
/* 04E574 7F019A44 46107103 */  div.s $f4, $f14, $f16
/* 04E578 7F019A48 E4480004 */  swc1  $f8, 4($v0)
/* 04E57C 7F019A4C E4440008 */  swc1  $f4, 8($v0)
.L7F019A50:
/* 04E580 7F019A50 3C038005 */  lui   $v1, %hi(g_ClockTimer)
/* 04E584 7F019A54 8C638374 */  lw    $v1, %lo(g_ClockTimer)($v1)
/* 04E588 7F019A58 3C028007 */  lui   $v0, %hi(flt_CODE_bss_800695D8)
/* 04E58C 7F019A5C 244295D8 */  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x6a28
/* 04E590 7F019A60 58600021 */  blezl $v1, .L7F019AE8
/* 04E594 7F019A64 C44A0000 */   lwc1  $f10, ($v0)
/* 04E598 7F019A68 C4440000 */  lwc1  $f4, ($v0)
/* 04E59C 7F019A6C 26310001 */  addiu $s1, $s1, 1
/* 04E5A0 7F019A70 0223082A */  slt   $at, $s1, $v1
/* 04E5A4 7F019A74 46040202 */  mul.s $f8, $f0, $f4
/* 04E5A8 7F019A78 10200010 */  beqz  $at, .L7F019ABC
/* 04E5AC 7F019A7C C44A0004 */   lwc1  $f10, 4($v0)
.L7F019A80:
/* 04E5B0 7F019A80 460A0182 */  mul.s $f6, $f0, $f10
/* 04E5B4 7F019A84 46081100 */  add.s $f4, $f2, $f8
/* 04E5B8 7F019A88 C44A0008 */  lwc1  $f10, 8($v0)
/* 04E5BC 7F019A8C 26310001 */  addiu $s1, $s1, 1
/* 04E5C0 7F019A90 0223082A */  slt   $at, $s1, $v1
/* 04E5C4 7F019A94 460A0202 */  mul.s $f8, $f0, $f10
/* 04E5C8 7F019A98 E4440000 */  swc1  $f4, ($v0)
/* 04E5CC 7F019A9C 46066180 */  add.s $f6, $f12, $f6
/* 04E5D0 7F019AA0 C4440000 */  lwc1  $f4, ($v0)
/* 04E5D4 7F019AA4 E4460004 */  swc1  $f6, 4($v0)
/* 04E5D8 7F019AA8 46087180 */  add.s $f6, $f14, $f8
/* 04E5DC 7F019AAC 46040202 */  mul.s $f8, $f0, $f4
/* 04E5E0 7F019AB0 C44A0004 */  lwc1  $f10, 4($v0)
/* 04E5E4 7F019AB4 1420FFF2 */  bnez  $at, .L7F019A80
/* 04E5E8 7F019AB8 E4460008 */   swc1  $f6, 8($v0)
.L7F019ABC:
/* 04E5EC 7F019ABC 460A0182 */  mul.s $f6, $f0, $f10
/* 04E5F0 7F019AC0 C44A0008 */  lwc1  $f10, 8($v0)
/* 04E5F4 7F019AC4 46081100 */  add.s $f4, $f2, $f8
/* 04E5F8 7F019AC8 460A0202 */  mul.s $f8, $f0, $f10
/* 04E5FC 7F019ACC E4440000 */  swc1  $f4, ($v0)
/* 04E600 7F019AD0 46066180 */  add.s $f6, $f12, $f6
/* 04E604 7F019AD4 E4460004 */  swc1  $f6, 4($v0)
/* 04E608 7F019AD8 46087180 */  add.s $f6, $f14, $f8
/* 04E60C 7F019ADC E4460008 */  swc1  $f6, 8($v0)
/* 04E610 7F019AE0 00008825 */  move  $s1, $zero
/* 04E614 7F019AE4 C44A0000 */  lwc1  $f10, ($v0)
.L7F019AE8:
/* 04E618 7F019AE8 C4440004 */  lwc1  $f4, 4($v0)
/* 04E61C 7F019AEC 3C038007 */  lui   $v1, %hi(flt_CODE_bss_800695C8)
/* 04E620 7F019AF0 46105202 */  mul.s $f8, $f10, $f16
/* 04E624 7F019AF4 C44A0008 */  lwc1  $f10, 8($v0)
/* 04E628 7F019AF8 246395C8 */  addiu $v1, %lo(flt_CODE_bss_800695C8) # addiu $v1, $v1, -0x6a38
/* 04E62C 7F019AFC 46102182 */  mul.s $f6, $f4, $f16
/* 04E630 7F019B00 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 04E634 7F019B04 C7A0023C */  lwc1  $f0, 0x23c($sp)
/* 04E638 7F019B08 02402025 */  move  $a0, $s2
/* 04E63C 7F019B0C E4680000 */  swc1  $f8, ($v1)
/* 04E640 7F019B10 46105202 */  mul.s $f8, $f10, $f16
/* 04E644 7F019B14 C4640000 */  lwc1  $f4, ($v1)
/* 04E648 7F019B18 E4660004 */  swc1  $f6, 4($v1)
/* 04E64C 7F019B1C C46A0004 */  lwc1  $f10, 4($v1)
/* 04E650 7F019B20 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 04E654 7F019B24 46049080 */  add.s $f2, $f18, $f4
/* 04E658 7F019B28 44812000 */  mtc1  $at, $f4
/* 04E65C 7F019B2C E4680008 */  swc1  $f8, 8($v1)
/* 04E660 7F019B30 460A3200 */  add.s $f8, $f6, $f10
/* 04E664 7F019B34 C7AA0060 */  lwc1  $f10, 0x60($sp)
/* 04E668 7F019B38 E7A60050 */  swc1  $f6, 0x50($sp)
/* 04E66C 7F019B3C 3C014252 */  li    $at, 0x42520000 # 52.500000
/* 04E670 7F019B40 46044301 */  sub.s $f12, $f8, $f4
/* 04E674 7F019B44 C4680008 */  lwc1  $f8, 8($v1)
/* 04E678 7F019B48 C7A40238 */  lwc1  $f4, 0x238($sp)
/* 04E67C 7F019B4C E7AA0054 */  swc1  $f10, 0x54($sp)
/* 04E680 7F019B50 46085380 */  add.s $f14, $f10, $f8
/* 04E684 7F019B54 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 04E688 7F019B58 C7A60244 */  lwc1  $f6, 0x244($sp)
/* 04E68C 7F019B5C 46022200 */  add.s $f8, $f4, $f2
/* 04E690 7F019B60 C7A40240 */  lwc1  $f4, 0x240($sp)
/* 04E694 7F019B64 E7AE013C */  swc1  $f14, 0x13c($sp)
/* 04E698 7F019B68 46123180 */  add.s $f6, $f6, $f18
/* 04E69C 7F019B6C E7A80238 */  swc1  $f8, 0x238($sp)
/* 04E6A0 7F019B70 E7A80050 */  swc1  $f8, 0x50($sp)
/* 04E6A4 7F019B74 44814000 */  mtc1  $at, $f8
/* 04E6A8 7F019B78 460E2100 */  add.s $f4, $f4, $f14
/* 04E6AC 7F019B7C E7A60244 */  swc1  $f6, 0x244($sp)
/* 04E6B0 7F019B80 44053000 */  mfc1  $a1, $f6
/* 04E6B4 7F019B84 46085280 */  add.s $f10, $f10, $f8
/* 04E6B8 7F019B88 C7A80248 */  lwc1  $f8, 0x248($sp)
/* 04E6BC 7F019B8C E7A40240 */  swc1  $f4, 0x240($sp)
/* 04E6C0 7F019B90 E7A40058 */  swc1  $f4, 0x58($sp)
/* 04E6C4 7F019B94 460A4200 */  add.s $f8, $f8, $f10
/* 04E6C8 7F019B98 C7AA024C */  lwc1  $f10, 0x24c($sp)
/* 04E6CC 7F019B9C C7A40054 */  lwc1  $f4, 0x54($sp)
/* 04E6D0 7F019BA0 460C0000 */  add.s $f0, $f0, $f12
/* 04E6D4 7F019BA4 E7A80248 */  swc1  $f8, 0x248($sp)
/* 04E6D8 7F019BA8 44064000 */  mfc1  $a2, $f8
/* 04E6DC 7F019BAC 46045280 */  add.s $f10, $f10, $f4
/* 04E6E0 7F019BB0 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 04E6E4 7F019BB4 C7A8022C */  lwc1  $f8, 0x22c($sp)
/* 04E6E8 7F019BB8 C7A60058 */  lwc1  $f6, 0x58($sp)
/* 04E6EC 7F019BBC E7AA024C */  swc1  $f10, 0x24c($sp)
/* 04E6F0 7F019BC0 44075000 */  mfc1  $a3, $f10
/* 04E6F4 7F019BC4 E7A40010 */  swc1  $f4, 0x10($sp)
/* 04E6F8 7F019BC8 C7A40234 */  lwc1  $f4, 0x234($sp)
/* 04E6FC 7F019BCC C7AA0230 */  lwc1  $f10, 0x230($sp)
/* 04E700 7F019BD0 E7A00014 */  swc1  $f0, 0x14($sp)
/* 04E704 7F019BD4 E7A0023C */  swc1  $f0, 0x23c($sp)
/* 04E708 7F019BD8 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04E70C 7F019BDC E7A20134 */  swc1  $f2, 0x134($sp)
/* 04E710 7F019BE0 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 04E714 7F019BE4 E7A60018 */  swc1  $f6, 0x18($sp)
/* 04E718 7F019BE8 E7A40024 */  swc1  $f4, 0x24($sp)
/* 04E71C 7F019BEC 0FC165A5 */  jal   matrix_4x4_7F059694
/* 04E720 7F019BF0 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 04E724 7F019BF4 8E8E0000 */  lw    $t6, ($s4)
/* 04E728 7F019BF8 AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04E72C 7F019BFC 8DCF0008 */  lw    $t7, 8($t6)
/* 04E730 7F019C00 85E4000E */  lh    $a0, 0xe($t7)
/* 04E734 7F019C04 00046980 */  sll   $t5, $a0, 6
/* 04E738 7F019C08 0FC2F5C5 */  jal   dynAllocate
/* 04E73C 7F019C0C 01A02025 */   move  $a0, $t5
/* 04E740 7F019C10 AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04E744 7F019C14 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04E748 7F019C18 0FC1BCBE */  jal   subcalcmatrices
/* 04E74C 7F019C1C 8E850000 */   lw    $a1, ($s4)
/* 04E750 7F019C20 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E754 7F019C24 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E758 7F019C28 50E00025 */  beql  $a3, $zero, .L7F019CC0
/* 04E75C 7F019C2C 24180007 */   li    $t8, 7
/* 04E760 7F019C30 8E840000 */  lw    $a0, ($s4)
/* 04E764 7F019C34 8CE5001C */  lw    $a1, 0x1c($a3)
/* 04E768 7F019C38 0FC1B198 */  jal   modelFindNodeMtx
/* 04E76C 7F019C3C 00003025 */   move  $a2, $zero
/* 04E770 7F019C40 8E980000 */  lw    $t8, ($s4)
/* 04E774 7F019C44 AFA201A8 */  sw    $v0, 0x1a8($sp)
/* 04E778 7F019C48 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E77C 7F019C4C 8F0C0008 */  lw    $t4, 8($t8)
/* 04E780 7F019C50 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E784 7F019C54 27B20160 */  addiu $s2, $sp, 0x160
/* 04E788 7F019C58 8D990008 */  lw    $t9, 8($t4)
/* 04E78C 7F019C5C 8CEB001C */  lw    $t3, 0x1c($a3)
/* 04E790 7F019C60 02402825 */  move  $a1, $s2
/* 04E794 7F019C64 8F2E0014 */  lw    $t6, 0x14($t9)
/* 04E798 7F019C68 3C018005 */  lui   $at, %hi(D_80051B38)
/* 04E79C 7F019C6C 556E000A */  bnel  $t3, $t6, .L7F019C98
/* 04E7A0 7F019C70 8CEF0008 */   lw    $t7, 8($a3)
/* 04E7A4 7F019C74 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 04E7A8 7F019C78 C42C1B38 */   lwc1  $f12, %lo(D_80051B38)($at)
/* 04E7AC 7F019C7C 8FA401A8 */  lw    $a0, 0x1a8($sp)
/* 04E7B0 7F019C80 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 04E7B4 7F019C84 02402825 */   move  $a1, $s2
/* 04E7B8 7F019C88 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E7BC 7F019C8C 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E7C0 7F019C90 AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04E7C4 7F019C94 8CEF0008 */  lw    $t7, 8($a3)
.L7F019C98:
/* 04E7C8 7F019C98 85E4000E */  lh    $a0, 0xe($t7)
/* 04E7CC 7F019C9C 00046980 */  sll   $t5, $a0, 6
/* 04E7D0 7F019CA0 0FC2F5C5 */  jal   dynAllocate
/* 04E7D4 7F019CA4 01A02025 */   move  $a0, $t5
/* 04E7D8 7F019CA8 3C058003 */  lui   $a1, %hi(cast_model_weapon)
/* 04E7DC 7F019CAC AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04E7E0 7F019CB0 8CA5B5F8 */  lw    $a1, %lo(cast_model_weapon)($a1)
/* 04E7E4 7F019CB4 0FC1BC92 */  jal   instcalcmatrices
/* 04E7E8 7F019CB8 27A401A8 */   addiu $a0, $sp, 0x1a8
/* 04E7EC 7F019CBC 24180007 */  li    $t8, 7
.L7F019CC0:
/* 04E7F0 7F019CC0 240C0001 */  li    $t4, 1
/* 04E7F4 7F019CC4 24190003 */  li    $t9, 3
/* 04E7F8 7F019CC8 27B20160 */  addiu $s2, $sp, 0x160
/* 04E7FC 7F019CCC AFB801D8 */  sw    $t8, 0x1d8($sp)
/* 04E800 7F019CD0 AFAC01AC */  sw    $t4, 0x1ac($sp)
/* 04E804 7F019CD4 AFB301B4 */  sw    $s3, 0x1b4($sp)
/* 04E808 7F019CD8 AFB901B0 */  sw    $t9, 0x1b0($sp)
/* 04E80C 7F019CDC 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04E810 7F019CE0 0FC1D1A1 */  jal   subdraw
/* 04E814 7F019CE4 8E850000 */   lw    $a1, ($s4)
/* 04E818 7F019CE8 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E81C 7F019CEC 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E820 7F019CF0 10E00003 */  beqz  $a3, .L7F019D00
/* 04E824 7F019CF4 27A401A8 */   addiu $a0, $sp, 0x1a8
/* 04E828 7F019CF8 0FC1D1A1 */  jal   subdraw
/* 04E82C 7F019CFC 00E02825 */   move  $a1, $a3
.L7F019D00:
/* 04E830 7F019D00 8FB301B4 */  lw    $s3, 0x1b4($sp)
/* 04E834 7F019D04 0FC1B100 */  jal   modelSetDistanceDisabled
/* 04E838 7F019D08 00002025 */   move  $a0, $zero
/* 04E83C 7F019D0C 8E820000 */  lw    $v0, ($s4)
/* 04E840 7F019D10 8C4B0008 */  lw    $t3, 8($v0)
/* 04E844 7F019D14 856E000E */  lh    $t6, 0xe($t3)
/* 04E848 7F019D18 19C00013 */  blez  $t6, .L7F019D68
/* 04E84C 7F019D1C 00008025 */   move  $s0, $zero
/* 04E850 7F019D20 8C4F000C */  lw    $t7, 0xc($v0)
.L7F019D24:
/* 04E854 7F019D24 02402825 */  move  $a1, $s2
/* 04E858 7F019D28 0FC16008 */  jal   matrix_4x4_copy
/* 04E85C 7F019D2C 01F02021 */   addu  $a0, $t7, $s0
/* 04E860 7F019D30 8E8D0000 */  lw    $t5, ($s4)
/* 04E864 7F019D34 00116180 */  sll   $t4, $s1, 6
/* 04E868 7F019D38 02402025 */  move  $a0, $s2
/* 04E86C 7F019D3C 8DB8000C */  lw    $t8, 0xc($t5)
/* 04E870 7F019D40 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 04E874 7F019D44 030C2821 */   addu  $a1, $t8, $t4
/* 04E878 7F019D48 8E820000 */  lw    $v0, ($s4)
/* 04E87C 7F019D4C 26310001 */  addiu $s1, $s1, 1
/* 04E880 7F019D50 26100040 */  addiu $s0, $s0, 0x40
/* 04E884 7F019D54 8C590008 */  lw    $t9, 8($v0)
/* 04E888 7F019D58 872B000E */  lh    $t3, 0xe($t9)
/* 04E88C 7F019D5C 022B082A */  slt   $at, $s1, $t3
/* 04E890 7F019D60 5420FFF0 */  bnezl $at, .L7F019D24
/* 04E894 7F019D64 8C4F000C */   lw    $t7, 0xc($v0)
.L7F019D68:
/* 04E898 7F019D68 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E89C 7F019D6C 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E8A0 7F019D70 50E0001C */  beql  $a3, $zero, .L7F019DE4
/* 04E8A4 7F019D74 02601025 */   move  $v0, $s3
/* 04E8A8 7F019D78 8CEE0008 */  lw    $t6, 8($a3)
/* 04E8AC 7F019D7C 00008825 */  move  $s1, $zero
/* 04E8B0 7F019D80 00008025 */  move  $s0, $zero
/* 04E8B4 7F019D84 85CF000E */  lh    $t7, 0xe($t6)
/* 04E8B8 7F019D88 59E00016 */  blezl $t7, .L7F019DE4
/* 04E8BC 7F019D8C 02601025 */   move  $v0, $s3
/* 04E8C0 7F019D90 8CED000C */  lw    $t5, 0xc($a3)
.L7F019D94:
/* 04E8C4 7F019D94 02402825 */  move  $a1, $s2
/* 04E8C8 7F019D98 0FC16008 */  jal   matrix_4x4_copy
/* 04E8CC 7F019D9C 01B02021 */   addu  $a0, $t5, $s0
/* 04E8D0 7F019DA0 3C188003 */  lui   $t8, %hi(cast_model_weapon)
/* 04E8D4 7F019DA4 8F18B5F8 */  lw    $t8, %lo(cast_model_weapon)($t8)
/* 04E8D8 7F019DA8 0011C980 */  sll   $t9, $s1, 6
/* 04E8DC 7F019DAC 02402025 */  move  $a0, $s2
/* 04E8E0 7F019DB0 8F0C000C */  lw    $t4, 0xc($t8)
/* 04E8E4 7F019DB4 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 04E8E8 7F019DB8 01992821 */   addu  $a1, $t4, $t9
/* 04E8EC 7F019DBC 3C078003 */  lui   $a3, %hi(cast_model_weapon)
/* 04E8F0 7F019DC0 8CE7B5F8 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04E8F4 7F019DC4 26310001 */  addiu $s1, $s1, 1
/* 04E8F8 7F019DC8 26100040 */  addiu $s0, $s0, 0x40
/* 04E8FC 7F019DCC 8CEB0008 */  lw    $t3, 8($a3)
/* 04E900 7F019DD0 856E000E */  lh    $t6, 0xe($t3)
/* 04E904 7F019DD4 022E082A */  slt   $at, $s1, $t6
/* 04E908 7F019DD8 5420FFEE */  bnezl $at, .L7F019D94
/* 04E90C 7F019DDC 8CED000C */   lw    $t5, 0xc($a3)
/* 04E910 7F019DE0 02601025 */  move  $v0, $s3
.L7F019DE4:
/* 04E914 7F019DE4 3C0D006E */  lui   $t5, (0x006E0528 >> 16) # lui $t5, 0x6e
/* 04E918 7F019DE8 35AD0528 */  ori   $t5, (0x006E0528 & 0xFFFF) # ori $t5, $t5, 0x528
/* 04E91C 7F019DEC 3C0FED00 */  lui   $t7, 0xed00
/* 04E920 7F019DF0 AC4F0000 */  sw    $t7, ($v0)
/* 04E924 7F019DF4 AC4D0004 */  sw    $t5, 4($v0)
/* 04E928 7F019DF8 26730008 */  addiu $s3, $s3, 8
/* 04E92C 7F019DFC 3C07E700 */  lui   $a3, 0xe700
/* 04E930 7F019E00 26640008 */  addiu $a0, $s3, 8
/* 04E934 7F019E04 AE670000 */  sw    $a3, ($s3)
/* 04E938 7F019E08 AE600004 */  sw    $zero, 4($s3)
/* 04E93C 7F019E0C 3C18BA00 */  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
/* 04E940 7F019E10 37181402 */  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
/* 04E944 7F019E14 AC980000 */  sw    $t8, ($a0)
/* 04E948 7F019E18 AC800004 */  sw    $zero, 4($a0)
/* 04E94C 7F019E1C 24850008 */  addiu $a1, $a0, 8
/* 04E950 7F019E20 3C08BA00 */  lui   $t0, (0xBA000602 >> 16) # lui $t0, 0xba00
/* 04E954 7F019E24 35080602 */  ori   $t0, (0xBA000602 & 0xFFFF) # ori $t0, $t0, 0x602
/* 04E958 7F019E28 24A60008 */  addiu $a2, $a1, 8
/* 04E95C 7F019E2C 240C00C0 */  li    $t4, 192
/* 04E960 7F019E30 3C09BA00 */  lui   $t1, (0xBA001301 >> 16) # lui $t1, 0xba00
/* 04E964 7F019E34 ACAC0004 */  sw    $t4, 4($a1)
/* 04E968 7F019E38 ACA80000 */  sw    $t0, ($a1)
/* 04E96C 7F019E3C 35291301 */  ori   $t1, (0xBA001301 & 0xFFFF) # ori $t1, $t1, 0x1301
/* 04E970 7F019E40 24C20008 */  addiu $v0, $a2, 8
/* 04E974 7F019E44 ACC90000 */  sw    $t1, ($a2)
/* 04E978 7F019E48 ACC00004 */  sw    $zero, 4($a2)
/* 04E97C 7F019E4C 3C19B900 */  lui   $t9, (0xB9000002 >> 16) # lui $t9, 0xb900
/* 04E980 7F019E50 37390002 */  ori   $t9, (0xB9000002 & 0xFFFF) # ori $t9, $t9, 2
/* 04E984 7F019E54 24430008 */  addiu $v1, $v0, 8
/* 04E988 7F019E58 3C0ABA00 */  lui   $t2, (0xBA001001 >> 16) # lui $t2, 0xba00
/* 04E98C 7F019E5C AC590000 */  sw    $t9, ($v0)
/* 04E990 7F019E60 AC400004 */  sw    $zero, 4($v0)
/* 04E994 7F019E64 354A1001 */  ori   $t2, (0xBA001001 & 0xFFFF) # ori $t2, $t2, 0x1001
/* 04E998 7F019E68 24730008 */  addiu $s3, $v1, 8
/* 04E99C 7F019E6C AC6A0000 */  sw    $t2, ($v1)
/* 04E9A0 7F019E70 AC600004 */  sw    $zero, 4($v1)
/* 04E9A4 7F019E74 02602025 */  move  $a0, $s3
/* 04E9A8 7F019E78 3C0BBA00 */  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
/* 04E9AC 7F019E7C 356B0C02 */  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
/* 04E9B0 7F019E80 240E2000 */  li    $t6, 8192
/* 04E9B4 7F019E84 AC8E0004 */  sw    $t6, 4($a0)
/* 04E9B8 7F019E88 AC8B0000 */  sw    $t3, ($a0)
/* 04E9BC 7F019E8C 26650008 */  addiu $a1, $s3, 8
/* 04E9C0 7F019E90 3C0FBA00 */  lui   $t7, (0xBA000903 >> 16) # lui $t7, 0xba00
/* 04E9C4 7F019E94 35EF0903 */  ori   $t7, (0xBA000903 & 0xFFFF) # ori $t7, $t7, 0x903
/* 04E9C8 7F019E98 ACAF0000 */  sw    $t7, ($a1)
/* 04E9CC 7F019E9C 24A60008 */  addiu $a2, $a1, 8
/* 04E9D0 7F019EA0 240D0C00 */  li    $t5, 3072
/* 04E9D4 7F019EA4 ACAD0004 */  sw    $t5, 4($a1)
/* 04E9D8 7F019EA8 3C18BA00 */  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
/* 04E9DC 7F019EAC 37180E02 */  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
/* 04E9E0 7F019EB0 24C20008 */  addiu $v0, $a2, 8
/* 04E9E4 7F019EB4 ACD80000 */  sw    $t8, ($a2)
/* 04E9E8 7F019EB8 ACC00004 */  sw    $zero, 4($a2)
/* 04E9EC 7F019EBC 3C190050 */  lui   $t9, (0x00504340 >> 16) # lui $t9, 0x50
/* 04E9F0 7F019EC0 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 04E9F4 7F019EC4 358C031D */  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 04E9F8 7F019EC8 37394340 */  ori   $t9, (0x00504340 & 0xFFFF) # ori $t9, $t9, 0x4340
/* 04E9FC 7F019ECC 24430008 */  addiu $v1, $v0, 8
/* 04EA00 7F019ED0 AC590004 */  sw    $t9, 4($v0)
/* 04EA04 7F019ED4 AC4C0000 */  sw    $t4, ($v0)
/* 04EA08 7F019ED8 3C0BFCFF */  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
/* 04EA0C 7F019EDC 3C0EFFFD */  lui   $t6, (0xFFFDF6FB >> 16) # lui $t6, 0xfffd
/* 04EA10 7F019EE0 35CEF6FB */  ori   $t6, (0xFFFDF6FB & 0xFFFF) # ori $t6, $t6, 0xf6fb
/* 04EA14 7F019EE4 356BFFFF */  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
/* 04EA18 7F019EE8 AC6B0000 */  sw    $t3, ($v1)
/* 04EA1C 7F019EEC AC6E0004 */  sw    $t6, 4($v1)
/* 04EA20 7F019EF0 24640008 */  addiu $a0, $v1, 8
/* 04EA24 7F019EF4 3C0FFA00 */  lui   $t7, 0xfa00
/* 04EA28 7F019EF8 AC8F0000 */  sw    $t7, ($a0)
/* 04EA2C 7F019EFC 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 04EA30 7F019F00 44813000 */  mtc1  $at, $f6
/* 04EA34 7F019F04 C7A80144 */  lwc1  $f8, 0x144($sp)
/* 04EA38 7F019F08 240C00FF */  li    $t4, 255
/* 04EA3C 7F019F0C 24930008 */  addiu $s3, $a0, 8
/* 04EA40 7F019F10 46083002 */  mul.s $f0, $f6, $f8
/* 04EA44 7F019F14 3C0EF66E */  lui   $t6, (0xF66E0528 >> 16) # lui $t6, 0xf66e
/* 04EA48 7F019F18 35CE0528 */  ori   $t6, (0xF66E0528 & 0xFFFF) # ori $t6, $t6, 0x528
/* 04EA4C 7F019F1C 26660008 */  addiu $a2, $s3, 8
/* 04EA50 7F019F20 24C20008 */  addiu $v0, $a2, 8
/* 04EA54 7F019F24 24430008 */  addiu $v1, $v0, 8
/* 04EA58 7F019F28 240F0040 */  li    $t7, 64
/* 04EA5C 7F019F2C 4600028D */  trunc.w.s $f10, $f0
/* 04EA60 7F019F30 3C0D0008 */  lui   $t5, 8
/* 04EA64 7F019F34 24650008 */  addiu $a1, $v1, 8
/* 04EA68 7F019F38 44185000 */  mfc1  $t8, $f10
/* 04EA6C 7F019F3C 00000000 */  nop
/* 04EA70 7F019F40 0198C823 */  subu  $t9, $t4, $t8
/* 04EA74 7F019F44 332B00FF */  andi  $t3, $t9, 0xff
/* 04EA78 7F019F48 AC8B0004 */  sw    $t3, 4($a0)
/* 04EA7C 7F019F4C AE600004 */  sw    $zero, 4($s3)
/* 04EA80 7F019F50 AE6E0000 */  sw    $t6, ($s3)
/* 04EA84 7F019F54 ACC00004 */  sw    $zero, 4($a2)
/* 04EA88 7F019F58 ACC70000 */  sw    $a3, ($a2)
/* 04EA8C 7F019F5C AC4F0004 */  sw    $t7, 4($v0)
/* 04EA90 7F019F60 AC480000 */  sw    $t0, ($v0)
/* 04EA94 7F019F64 AC6D0004 */  sw    $t5, 4($v1)
/* 04EA98 7F019F68 AC690000 */  sw    $t1, ($v1)
/* 04EA9C 7F019F6C 3C0C0001 */  lui   $t4, 1
/* 04EAA0 7F019F70 ACAC0004 */  sw    $t4, 4($a1)
/* 04EAA4 7F019F74 ACAA0000 */  sw    $t2, ($a1)
/* 04EAA8 7F019F78 24A40008 */  addiu $a0, $a1, 8
/* 04EAAC 7F019F7C 0FC2B366 */  jal   microcode_constructor
/* 04EAB0 7F019F80 E7A00070 */   swc1  $f0, 0x70($sp)
/* 04EAB4 7F019F84 3C188003 */  lui   $t8, %hi(full_actor_intro)
/* 04EAB8 7F019F88 8F18B5FC */  lw    $t8, %lo(full_actor_intro)($t8)
/* 04EABC 7F019F8C 00409825 */  move  $s3, $v0
/* 04EAC0 7F019F90 1700005F */  bnez  $t8, .L7F01A110
/* 04EAC4 7F019F94 3C198003 */   lui   $t9, %hi(intro_character_index)
/* 04EAC8 7F019F98 8F39B5E8 */  lw    $t9, %lo(intro_character_index)($t9)
/* 04EACC 7F019F9C 3C048003 */  lui   $a0, %hi(intro_char_table+8)
/* 04EAD0 7F019FA0 00195880 */  sll   $t3, $t9, 2
/* 04EAD4 7F019FA4 01795821 */  addu  $t3, $t3, $t9
/* 04EAD8 7F019FA8 000B5880 */  sll   $t3, $t3, 2
/* 04EADC 7F019FAC 008B2021 */  addu  $a0, $a0, $t3
/* 04EAE0 7F019FB0 0FC30776 */  jal   langGet
/* 04EAE4 7F019FB4 9484B608 */   lhu   $a0, %lo(intro_char_table+8)($a0)
/* 04EAE8 7F019FB8 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBold)
/* 04EAEC 7F019FBC 8DCE0EB4 */  lw    $t6, %lo(ptrFontZurichBold)($t6)
/* 04EAF0 7F019FC0 3C148004 */  lui   $s4, %hi(ptrFontZurichBoldChars)
/* 04EAF4 7F019FC4 26940EB8 */  addiu $s4, %lo(ptrFontZurichBoldChars) # addiu $s4, $s4, 0xeb8
/* 04EAF8 7F019FC8 00408825 */  move  $s1, $v0
/* 04EAFC 7F019FCC 8E870000 */  lw    $a3, ($s4)
/* 04EB00 7F019FD0 27A40150 */  addiu $a0, $sp, 0x150
/* 04EB04 7F019FD4 27A50154 */  addiu $a1, $sp, 0x154
/* 04EB08 7F019FD8 00403025 */  move  $a2, $v0
/* 04EB0C 7F019FDC AFA00014 */  sw    $zero, 0x14($sp)
/* 04EB10 7F019FE0 0FC2BA63 */  jal   textMeasure
/* 04EB14 7F019FE4 AFAE0010 */   sw    $t6, 0x10($sp)
/* 04EB18 7F019FE8 8FA20154 */  lw    $v0, 0x154($sp)
/* 04EB1C 7F019FEC 8FB80150 */  lw    $t8, 0x150($sp)
/* 04EB20 7F019FF0 240D013B */  li    $t5, 315
/* 04EB24 7F019FF4 04410003 */  bgez  $v0, .L7F01A004
/* 04EB28 7F019FF8 00027843 */   sra   $t7, $v0, 1
/* 04EB2C 7F019FFC 24410001 */  addiu $at, $v0, 1
/* 04EB30 7F01A000 00017843 */  sra   $t7, $at, 1
.L7F01A004:
/* 04EB34 7F01A004 01AF2823 */  subu  $a1, $t5, $t7
/* 04EB38 7F01A008 240C006C */  li    $t4, 108
/* 04EB3C 7F01A00C 00A23821 */  addu  $a3, $a1, $v0
/* 04EB40 7F01A010 2719006D */  addiu $t9, $t8, 0x6d
/* 04EB44 7F01A014 AFAC0158 */  sw    $t4, 0x158($sp)
/* 04EB48 7F01A018 AFB90010 */  sw    $t9, 0x10($sp)
/* 04EB4C 7F01A01C 24E70001 */  addiu $a3, $a3, 1
/* 04EB50 7F01A020 AFA5015C */  sw    $a1, 0x15c($sp)
/* 04EB54 7F01A024 02602025 */  move  $a0, $s3
/* 04EB58 7F01A028 2406006C */  li    $a2, 108
/* 04EB5C 7F01A02C 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 04EB60 7F01A030 AFA00014 */   sw    $zero, 0x14($sp)
/* 04EB64 7F01A034 0C001107 */  jal   viGetX
/* 04EB68 7F01A038 00409825 */   move  $s3, $v0
/* 04EB6C 7F01A03C 00028400 */  sll   $s0, $v0, 0x10
/* 04EB70 7F01A040 00105C03 */  sra   $t3, $s0, 0x10
/* 04EB74 7F01A044 0C00110B */  jal   viGetY
/* 04EB78 7F01A048 01608025 */   move  $s0, $t3
/* 04EB7C 7F01A04C 444FF800 */  cfc1  $t7, $31
/* 04EB80 7F01A050 240C0001 */  li    $t4, 1
/* 04EB84 7F01A054 44CCF800 */  ctc1  $t4, $31
/* 04EB88 7F01A058 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 04EB8C 7F01A05C 3C0D8004 */  lui   $t5, %hi(ptrFontZurichBold)
/* 04EB90 7F01A060 8DAD0EB4 */  lw    $t5, %lo(ptrFontZurichBold)($t5)
/* 04EB94 7F01A064 460021A4 */  cvt.w.s $f6, $f4
/* 04EB98 7F01A068 8E8E0000 */  lw    $t6, ($s4)
/* 04EB9C 7F01A06C 02602025 */  move  $a0, $s3
/* 04EBA0 7F01A070 27A5015C */  addiu $a1, $sp, 0x15c
/* 04EBA4 7F01A074 444CF800 */  cfc1  $t4, $31
/* 04EBA8 7F01A078 27A60158 */  addiu $a2, $sp, 0x158
/* 04EBAC 7F01A07C 02203825 */  move  $a3, $s1
/* 04EBB0 7F01A080 318C0078 */  andi  $t4, $t4, 0x78
/* 04EBB4 7F01A084 AFAD0014 */  sw    $t5, 0x14($sp)
/* 04EBB8 7F01A088 11800013 */  beqz  $t4, .L7F01A0D8
/* 04EBBC 7F01A08C AFAE0010 */   sw    $t6, 0x10($sp)
/* 04EBC0 7F01A090 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 04EBC4 7F01A094 44813000 */  mtc1  $at, $f6
/* 04EBC8 7F01A098 240C0001 */  li    $t4, 1
/* 04EBCC 7F01A09C 46062181 */  sub.s $f6, $f4, $f6
/* 04EBD0 7F01A0A0 44CCF800 */  ctc1  $t4, $31
/* 04EBD4 7F01A0A4 00000000 */  nop
/* 04EBD8 7F01A0A8 460031A4 */  cvt.w.s $f6, $f6
/* 04EBDC 7F01A0AC 444CF800 */  cfc1  $t4, $31
/* 04EBE0 7F01A0B0 00000000 */  nop
/* 04EBE4 7F01A0B4 318C0078 */  andi  $t4, $t4, 0x78
/* 04EBE8 7F01A0B8 15800005 */  bnez  $t4, .L7F01A0D0
/* 04EBEC 7F01A0BC 00000000 */   nop
/* 04EBF0 7F01A0C0 440C3000 */  mfc1  $t4, $f6
/* 04EBF4 7F01A0C4 3C018000 */  lui   $at, 0x8000
/* 04EBF8 7F01A0C8 10000007 */  b     .L7F01A0E8
/* 04EBFC 7F01A0CC 01816025 */   or    $t4, $t4, $at
.L7F01A0D0:
/* 04EC00 7F01A0D0 10000005 */  b     .L7F01A0E8
/* 04EC04 7F01A0D4 240CFFFF */   li    $t4, -1
.L7F01A0D8:
/* 04EC08 7F01A0D8 440C3000 */  mfc1  $t4, $f6
/* 04EC0C 7F01A0DC 00000000 */  nop
/* 04EC10 7F01A0E0 0580FFFB */  bltz  $t4, .L7F01A0D0
/* 04EC14 7F01A0E4 00000000 */   nop
.L7F01A0E8:
/* 04EC18 7F01A0E8 2401FF00 */  li    $at, -256
/* 04EC1C 7F01A0EC 0181C025 */  or    $t8, $t4, $at
/* 04EC20 7F01A0F0 44CFF800 */  ctc1  $t7, $31
/* 04EC24 7F01A0F4 AFB80018 */  sw    $t8, 0x18($sp)
/* 04EC28 7F01A0F8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 04EC2C 7F01A0FC AFA20020 */  sw    $v0, 0x20($sp)
/* 04EC30 7F01A100 AFA00024 */  sw    $zero, 0x24($sp)
/* 04EC34 7F01A104 0FC2B6AF */  jal   textRender
/* 04EC38 7F01A108 AFA00028 */   sw    $zero, 0x28($sp)
/* 04EC3C 7F01A10C 00409825 */  move  $s3, $v0
.L7F01A110:
/* 04EC40 7F01A110 444EF800 */  cfc1  $t6, $31
/* 04EC44 7F01A114 24120001 */  li    $s2, 1
/* 04EC48 7F01A118 44D2F800 */  ctc1  $s2, $31
/* 04EC4C 7F01A11C C7A80070 */  lwc1  $f8, 0x70($sp)
/* 04EC50 7F01A120 3C198003 */  lui   $t9, %hi(intro_character_index)
/* 04EC54 7F01A124 8F39B5E8 */  lw    $t9, %lo(intro_character_index)($t9)
/* 04EC58 7F01A128 460042A4 */  cvt.w.s $f10, $f8
/* 04EC5C 7F01A12C 3C048003 */  lui   $a0, %hi(intro_char_table+10)
/* 04EC60 7F01A130 00195880 */  sll   $t3, $t9, 2
/* 04EC64 7F01A134 01795821 */  addu  $t3, $t3, $t9
/* 04EC68 7F01A138 4452F800 */  cfc1  $s2, $31
/* 04EC6C 7F01A13C 000B5880 */  sll   $t3, $t3, 2
/* 04EC70 7F01A140 3C148004 */  lui   $s4, %hi(ptrFontZurichBoldChars)
/* 04EC74 7F01A144 008B2021 */  addu  $a0, $a0, $t3
/* 04EC78 7F01A148 32520078 */  andi  $s2, $s2, 0x78
/* 04EC7C 7F01A14C 26940EB8 */  addiu $s4, %lo(ptrFontZurichBoldChars) # addiu $s4, $s4, 0xeb8
/* 04EC80 7F01A150 12400013 */  beqz  $s2, .L7F01A1A0
/* 04EC84 7F01A154 9484B60A */   lhu   $a0, %lo(intro_char_table+10)($a0)
/* 04EC88 7F01A158 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 04EC8C 7F01A15C 44815000 */  mtc1  $at, $f10
/* 04EC90 7F01A160 24120001 */  li    $s2, 1
/* 04EC94 7F01A164 460A4281 */  sub.s $f10, $f8, $f10
/* 04EC98 7F01A168 44D2F800 */  ctc1  $s2, $31
/* 04EC9C 7F01A16C 00000000 */  nop
/* 04ECA0 7F01A170 460052A4 */  cvt.w.s $f10, $f10
/* 04ECA4 7F01A174 4452F800 */  cfc1  $s2, $31
/* 04ECA8 7F01A178 00000000 */  nop
/* 04ECAC 7F01A17C 32520078 */  andi  $s2, $s2, 0x78
/* 04ECB0 7F01A180 16400005 */  bnez  $s2, .L7F01A198
/* 04ECB4 7F01A184 00000000 */   nop
/* 04ECB8 7F01A188 44125000 */  mfc1  $s2, $f10
/* 04ECBC 7F01A18C 3C018000 */  lui   $at, 0x8000
/* 04ECC0 7F01A190 10000007 */  b     .L7F01A1B0
/* 04ECC4 7F01A194 02419025 */   or    $s2, $s2, $at
.L7F01A198:
/* 04ECC8 7F01A198 10000005 */  b     .L7F01A1B0
/* 04ECCC 7F01A19C 2412FFFF */   li    $s2, -1
.L7F01A1A0:
/* 04ECD0 7F01A1A0 44125000 */  mfc1  $s2, $f10
/* 04ECD4 7F01A1A4 00000000 */  nop
/* 04ECD8 7F01A1A8 0640FFFB */  bltz  $s2, .L7F01A198
/* 04ECDC 7F01A1AC 00000000 */   nop
.L7F01A1B0:
/* 04ECE0 7F01A1B0 2401FF00 */  li    $at, -256
/* 04ECE4 7F01A1B4 02416825 */  or    $t5, $s2, $at
/* 04ECE8 7F01A1B8 44CEF800 */  ctc1  $t6, $31
/* 04ECEC 7F01A1BC 0FC30776 */  jal   langGet
/* 04ECF0 7F01A1C0 01A09025 */   move  $s2, $t5
/* 04ECF4 7F01A1C4 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBold)
/* 04ECF8 7F01A1C8 8DEF0EB4 */  lw    $t7, %lo(ptrFontZurichBold)($t7)
/* 04ECFC 7F01A1CC 00408825 */  move  $s1, $v0
/* 04ED00 7F01A1D0 27A40150 */  addiu $a0, $sp, 0x150
/* 04ED04 7F01A1D4 27A50154 */  addiu $a1, $sp, 0x154
/* 04ED08 7F01A1D8 00403025 */  move  $a2, $v0
/* 04ED0C 7F01A1DC 8E870000 */  lw    $a3, ($s4)
/* 04ED10 7F01A1E0 AFA00014 */  sw    $zero, 0x14($sp)
/* 04ED14 7F01A1E4 0FC2BA63 */  jal   textMeasure
/* 04ED18 7F01A1E8 AFAF0010 */   sw    $t7, 0x10($sp)
/* 04ED1C 7F01A1EC 8FA20154 */  lw    $v0, 0x154($sp)
/* 04ED20 7F01A1F0 8FAB0150 */  lw    $t3, 0x150($sp)
/* 04ED24 7F01A1F4 2418013B */  li    $t8, 315
/* 04ED28 7F01A1F8 04410003 */  bgez  $v0, .L7F01A208
/* 04ED2C 7F01A1FC 00026043 */   sra   $t4, $v0, 1
/* 04ED30 7F01A200 24410001 */  addiu $at, $v0, 1
/* 04ED34 7F01A204 00016043 */  sra   $t4, $at, 1
.L7F01A208:
/* 04ED38 7F01A208 030C2823 */  subu  $a1, $t8, $t4
/* 04ED3C 7F01A20C 24190098 */  li    $t9, 152
/* 04ED40 7F01A210 00A23821 */  addu  $a3, $a1, $v0
/* 04ED44 7F01A214 256E0099 */  addiu $t6, $t3, 0x99
/* 04ED48 7F01A218 AFB90158 */  sw    $t9, 0x158($sp)
/* 04ED4C 7F01A21C AFAE0010 */  sw    $t6, 0x10($sp)
/* 04ED50 7F01A220 24E70001 */  addiu $a3, $a3, 1
/* 04ED54 7F01A224 AFA5015C */  sw    $a1, 0x15c($sp)
/* 04ED58 7F01A228 02602025 */  move  $a0, $s3
/* 04ED5C 7F01A22C 24060098 */  li    $a2, 152
/* 04ED60 7F01A230 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 04ED64 7F01A234 AFA00014 */   sw    $zero, 0x14($sp)
/* 04ED68 7F01A238 0C001107 */  jal   viGetX
/* 04ED6C 7F01A23C 00409825 */   move  $s3, $v0
/* 04ED70 7F01A240 00028400 */  sll   $s0, $v0, 0x10
/* 04ED74 7F01A244 00106C03 */  sra   $t5, $s0, 0x10
/* 04ED78 7F01A248 0C00110B */  jal   viGetY
/* 04ED7C 7F01A24C 01A08025 */   move  $s0, $t5
/* 04ED80 7F01A250 3C188004 */  lui   $t8, %hi(ptrFontZurichBold)
/* 04ED84 7F01A254 8F180EB4 */  lw    $t8, %lo(ptrFontZurichBold)($t8)
/* 04ED88 7F01A258 8E8F0000 */  lw    $t7, ($s4)
/* 04ED8C 7F01A25C 02602025 */  move  $a0, $s3
/* 04ED90 7F01A260 27A5015C */  addiu $a1, $sp, 0x15c
/* 04ED94 7F01A264 27A60158 */  addiu $a2, $sp, 0x158
/* 04ED98 7F01A268 02203825 */  move  $a3, $s1
/* 04ED9C 7F01A26C AFB20018 */  sw    $s2, 0x18($sp)
/* 04EDA0 7F01A270 AFB0001C */  sw    $s0, 0x1c($sp)
/* 04EDA4 7F01A274 AFA20020 */  sw    $v0, 0x20($sp)
/* 04EDA8 7F01A278 AFA00024 */  sw    $zero, 0x24($sp)
/* 04EDAC 7F01A27C AFA00028 */  sw    $zero, 0x28($sp)
/* 04EDB0 7F01A280 AFB80014 */  sw    $t8, 0x14($sp)
/* 04EDB4 7F01A284 0FC2B6AF */  jal   textRender
/* 04EDB8 7F01A288 AFAF0010 */   sw    $t7, 0x10($sp)
/* 04EDBC 7F01A28C 3C0C8003 */  lui   $t4, %hi(intro_character_index)
/* 04EDC0 7F01A290 8D8CB5E8 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04EDC4 7F01A294 3C048003 */  lui   $a0, %hi(intro_char_table+12)
/* 04EDC8 7F01A298 00409825 */  move  $s3, $v0
/* 04EDCC 7F01A29C 000CC880 */  sll   $t9, $t4, 2
/* 04EDD0 7F01A2A0 032CC821 */  addu  $t9, $t9, $t4
/* 04EDD4 7F01A2A4 0019C880 */  sll   $t9, $t9, 2
/* 04EDD8 7F01A2A8 00992021 */  addu  $a0, $a0, $t9
/* 04EDDC 7F01A2AC 0FC30776 */  jal   langGet
/* 04EDE0 7F01A2B0 9484B60C */   lhu   $a0, %lo(intro_char_table+12)($a0)
/* 04EDE4 7F01A2B4 3C0B8004 */  lui   $t3, %hi(ptrFontZurichBold)
/* 04EDE8 7F01A2B8 8D6B0EB4 */  lw    $t3, %lo(ptrFontZurichBold)($t3)
/* 04EDEC 7F01A2BC 00408825 */  move  $s1, $v0
/* 04EDF0 7F01A2C0 27A40150 */  addiu $a0, $sp, 0x150
/* 04EDF4 7F01A2C4 27A50154 */  addiu $a1, $sp, 0x154
/* 04EDF8 7F01A2C8 00403025 */  move  $a2, $v0
/* 04EDFC 7F01A2CC 8E870000 */  lw    $a3, ($s4)
/* 04EE00 7F01A2D0 AFA00014 */  sw    $zero, 0x14($sp)
/* 04EE04 7F01A2D4 0FC2BA63 */  jal   textMeasure
/* 04EE08 7F01A2D8 AFAB0010 */   sw    $t3, 0x10($sp)
/* 04EE0C 7F01A2DC 8FA20154 */  lw    $v0, 0x154($sp)
/* 04EE10 7F01A2E0 8FB80150 */  lw    $t8, 0x150($sp)
/* 04EE14 7F01A2E4 240D013B */  li    $t5, 315
/* 04EE18 7F01A2E8 04410003 */  bgez  $v0, .L7F01A2F8
/* 04EE1C 7F01A2EC 00027043 */   sra   $t6, $v0, 1
/* 04EE20 7F01A2F0 24410001 */  addiu $at, $v0, 1
/* 04EE24 7F01A2F4 00017043 */  sra   $t6, $at, 1
.L7F01A2F8:
/* 04EE28 7F01A2F8 01AE2823 */  subu  $a1, $t5, $t6
/* 04EE2C 7F01A2FC 240F00AE */  li    $t7, 174
/* 04EE30 7F01A300 00A23821 */  addu  $a3, $a1, $v0
/* 04EE34 7F01A304 270C00AF */  addiu $t4, $t8, 0xaf
/* 04EE38 7F01A308 AFAF0158 */  sw    $t7, 0x158($sp)
/* 04EE3C 7F01A30C AFAC0010 */  sw    $t4, 0x10($sp)
/* 04EE40 7F01A310 24E70001 */  addiu $a3, $a3, 1
/* 04EE44 7F01A314 AFA5015C */  sw    $a1, 0x15c($sp)
/* 04EE48 7F01A318 02602025 */  move  $a0, $s3
/* 04EE4C 7F01A31C 240600AE */  li    $a2, 174
/* 04EE50 7F01A320 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 04EE54 7F01A324 AFA00014 */   sw    $zero, 0x14($sp)
/* 04EE58 7F01A328 0C001107 */  jal   viGetX
/* 04EE5C 7F01A32C 00409825 */   move  $s3, $v0
/* 04EE60 7F01A330 00028400 */  sll   $s0, $v0, 0x10
/* 04EE64 7F01A334 0010CC03 */  sra   $t9, $s0, 0x10
/* 04EE68 7F01A338 0C00110B */  jal   viGetY
/* 04EE6C 7F01A33C 03208025 */   move  $s0, $t9
/* 04EE70 7F01A340 3C0D8004 */  lui   $t5, %hi(ptrFontZurichBold)
/* 04EE74 7F01A344 8DAD0EB4 */  lw    $t5, %lo(ptrFontZurichBold)($t5)
/* 04EE78 7F01A348 8E8B0000 */  lw    $t3, ($s4)
/* 04EE7C 7F01A34C 02602025 */  move  $a0, $s3
/* 04EE80 7F01A350 27A5015C */  addiu $a1, $sp, 0x15c
/* 04EE84 7F01A354 27A60158 */  addiu $a2, $sp, 0x158
/* 04EE88 7F01A358 02203825 */  move  $a3, $s1
/* 04EE8C 7F01A35C AFB20018 */  sw    $s2, 0x18($sp)
/* 04EE90 7F01A360 AFB0001C */  sw    $s0, 0x1c($sp)
/* 04EE94 7F01A364 AFA20020 */  sw    $v0, 0x20($sp)
/* 04EE98 7F01A368 AFA00024 */  sw    $zero, 0x24($sp)
/* 04EE9C 7F01A36C AFA00028 */  sw    $zero, 0x28($sp)
/* 04EEA0 7F01A370 AFAD0014 */  sw    $t5, 0x14($sp)
/* 04EEA4 7F01A374 0FC2B6AF */  jal   textRender
/* 04EEA8 7F01A378 AFAB0010 */   sw    $t3, 0x10($sp)
/* 04EEAC 7F01A37C 8FBF004C */  lw    $ra, 0x4c($sp)
/* 04EEB0 7F01A380 8FB00038 */  lw    $s0, 0x38($sp)
/* 04EEB4 7F01A384 8FB1003C */  lw    $s1, 0x3c($sp)
/* 04EEB8 7F01A388 8FB20040 */  lw    $s2, 0x40($sp)
/* 04EEBC 7F01A38C 8FB30044 */  lw    $s3, 0x44($sp)
/* 04EEC0 7F01A390 8FB40048 */  lw    $s4, 0x48($sp)
/* 04EEC4 7F01A394 03E00008 */  jr    $ra
/* 04EEC8 7F01A398 27BD0250 */   addiu $sp, $sp, 0x250
)
#endif




#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051B0C
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B10
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B14
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B18
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B1C
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B20
.word 0x3D748800 /* 0.0597000122070312 */
glabel D_80051B24
.word 0x3D748800 /* 0.0597000122070312 */
glabel D_80051B28
.word 0x3F70B780 /* 0.940299987792969 */
glabel D_80051B2C
.word 0x3F70B780 /* 0.940299987792969 */
glabel D_80051B30
.word 0x3F70B780 /* 0.940299987792969 */
glabel D_80051B34
.word 0x3D748800 /* 0.0597000122070312 */
glabel D_80051B38
.word 0x40490FDB /*3.1415927;*/

.text
glabel constructor_menu18_displaycast
/* 04BD94 7F0193A4 27BDFDB0 */  addiu $sp, $sp, -0x250
/* 04BD98 7F0193A8 3C0E8002 */  lui   $t6, %hi(D_8002BA78) # $t6, 0x8002
/* 04BD9C 7F0193AC AFBF004C */  sw    $ra, 0x4c($sp)
/* 04BDA0 7F0193B0 AFB40048 */  sw    $s4, 0x48($sp)
/* 04BDA4 7F0193B4 AFB30044 */  sw    $s3, 0x44($sp)
/* 04BDA8 7F0193B8 AFB20040 */  sw    $s2, 0x40($sp)
/* 04BDAC 7F0193BC AFB1003C */  sw    $s1, 0x3c($sp)
/* 04BDB0 7F0193C0 AFB00038 */  sw    $s0, 0x38($sp)
/* 04BDB4 7F0193C4 25CE6FC8 */  addiu $t6, %lo(D_8002BA78) # addiu $t6, $t6, 0x6fc8
/* 04BDB8 7F0193C8 8DC10000 */  lw    $at, ($t6)
/* 04BDBC 7F0193CC 27AF0244 */  addiu $t7, $sp, 0x244
/* 04BDC0 7F0193D0 8DCC0004 */  lw    $t4, 4($t6)
/* 04BDC4 7F0193D4 ADE10000 */  sw    $at, ($t7)
/* 04BDC8 7F0193D8 8DC10008 */  lw    $at, 8($t6)
/* 04BDCC 7F0193DC 3C0D8002 */  lui   $t5, %hi(D_8002BA84) # $t5, 0x8002
/* 04BDD0 7F0193E0 25AD6FD4 */  addiu $t5, %lo(D_8002BA84) # addiu $t5, $t5, 0x6fd4
/* 04BDD4 7F0193E4 ADEC0004 */  sw    $t4, 4($t7)
/* 04BDD8 7F0193E8 ADE10008 */  sw    $at, 8($t7)
/* 04BDDC 7F0193EC 8DA10000 */  lw    $at, ($t5)
/* 04BDE0 7F0193F0 27B90238 */  addiu $t9, $sp, 0x238
/* 04BDE4 7F0193F4 8DAF0004 */  lw    $t7, 4($t5)
/* 04BDE8 7F0193F8 AF210000 */  sw    $at, ($t9)
/* 04BDEC 7F0193FC 8DA10008 */  lw    $at, 8($t5)
/* 04BDF0 7F019400 3C0C8002 */  lui   $t4, %hi(D_8002BA90) # $t4, 0x8002
/* 04BDF4 7F019404 258C6FE0 */  addiu $t4, %lo(D_8002BA90) # addiu $t4, $t4, 0x6fe0
/* 04BDF8 7F019408 AF2F0004 */  sw    $t7, 4($t9)
/* 04BDFC 7F01940C AF210008 */  sw    $at, 8($t9)
/* 04BE00 7F019410 8D810000 */  lw    $at, ($t4)
/* 04BE04 7F019414 27AE022C */  addiu $t6, $sp, 0x22c
/* 04BE08 7F019418 8D990004 */  lw    $t9, 4($t4)
/* 04BE0C 7F01941C ADC10000 */  sw    $at, ($t6)
/* 04BE10 7F019420 8D810008 */  lw    $at, 8($t4)
/* 04BE14 7F019424 3C0F8002 */  lui   $t7, %hi(D_8002BA9C) # $t7, 0x8002
/* 04BE18 7F019428 25EF6FEC */  addiu $t7, %lo(D_8002BA9C) # addiu $t7, $t7, 0x6fec
/* 04BE1C 7F01942C ADD90004 */  sw    $t9, 4($t6)
/* 04BE20 7F019430 ADC10008 */  sw    $at, 8($t6)
/* 04BE24 7F019434 00809825 */  move  $s3, $a0
/* 04BE28 7F019438 25EE003C */  addiu $t6, $t7, 0x3c
/* 04BE2C 7F01943C 27AD01A8 */  addiu $t5, $sp, 0x1a8
.L7F019440:
/* 04BE30 7F019440 8DE10000 */  lw    $at, ($t7)
/* 04BE34 7F019444 25EF000C */  addiu $t7, $t7, 0xc
/* 04BE38 7F019448 25AD000C */  addiu $t5, $t5, 0xc
/* 04BE3C 7F01944C ADA1FFF4 */  sw    $at, -0xc($t5)
/* 04BE40 7F019450 8DE1FFF8 */  lw    $at, -8($t7)
/* 04BE44 7F019454 ADA1FFF8 */  sw    $at, -8($t5)
/* 04BE48 7F019458 8DE1FFFC */  lw    $at, -4($t7)
/* 04BE4C 7F01945C 15EEFFF8 */  bne   $t7, $t6, .L7F019440
/* 04BE50 7F019460 ADA1FFFC */   sw    $at, -4($t5)
/* 04BE54 7F019464 8DE10000 */  lw    $at, ($t7)
/* 04BE58 7F019468 3C028002 */  lui   $v0, %hi(g_MenuTimer) # $v0, 0x8002
/* 04BE5C 7F01946C 3C198002 */  lui   $t9, %hi(D_8002BADC) # $t9, 0x8002
/* 04BE60 7F019470 ADA10000 */  sw    $at, ($t5)
/* 04BE64 7F019474 8C425E1C */  lw    $v0, %lo(g_MenuTimer)($v0)
/* 04BE68 7F019478 3C014316 */  li    $at, 0x43160000 # 150.000000
/* 04BE6C 7F01947C 44819000 */  mtc1  $at, $f18
/* 04BE70 7F019480 44827000 */  mtc1  $v0, $f14
/* 04BE74 7F019484 2739702C */  addiu $t9, %lo(D_8002BADC) # addiu $t9, $t9, 0x702c
/* 04BE78 7F019488 8F210000 */  lw    $at, ($t9)
/* 04BE7C 7F01948C 46807020 */  cvt.s.w $f0, $f14
/* 04BE80 7F019490 8F2E0004 */  lw    $t6, 4($t9)
/* 04BE84 7F019494 27AC0134 */  addiu $t4, $sp, 0x134
/* 04BE88 7F019498 AD810000 */  sw    $at, ($t4)
/* 04BE8C 7F01949C 8F210008 */  lw    $at, 8($t9)
/* 04BE90 7F0194A0 AD8E0004 */  sw    $t6, 4($t4)
/* 04BE94 7F0194A4 46120403 */  div.s $f16, $f0, $f18
/* 04BE98 7F0194A8 04400004 */  bltz  $v0, .L7F0194BC
/* 04BE9C 7F0194AC AD810008 */   sw    $at, 8($t4)
/* 04BEA0 7F0194B0 28410096 */  slti  $at, $v0, 0x96
/* 04BEA4 7F0194B4 54200005 */  bnezl $at, .L7F0194CC
/* 04BEA8 7F0194B8 28410019 */   slti  $at, $v0, 0x19
.L7F0194BC:
/* 04BEAC 7F0194BC 44802000 */  mtc1  $zero, $f4
/* 04BEB0 7F0194C0 10000018 */  b     .L7F019524
/* 04BEB4 7F0194C4 E7A40144 */   swc1  $f4, 0x144($sp)
/* 04BEB8 7F0194C8 28410019 */  slti  $at, $v0, 0x19
.L7F0194CC:
/* 04BEBC 7F0194CC 10200006 */  beqz  $at, .L7F0194E8
/* 04BEC0 7F0194D0 3C0141C8 */   li    $at, 0x41C80000 # 25.000000
/* 04BEC4 7F0194D4 44815000 */  mtc1  $at, $f10
/* 04BEC8 7F0194D8 00000000 */  nop
/* 04BECC 7F0194DC 460A0203 */  div.s $f8, $f0, $f10
/* 04BED0 7F0194E0 10000010 */  b     .L7F019524
/* 04BED4 7F0194E4 E7A80144 */   swc1  $f8, 0x144($sp)
.L7F0194E8:
/* 04BED8 7F0194E8 2841007E */  slti  $at, $v0, 0x7e
/* 04BEDC 7F0194EC 14200009 */  bnez  $at, .L7F019514
/* 04BEE0 7F0194F0 240F0096 */   li    $t7, 150
/* 04BEE4 7F0194F4 01E26823 */  subu  $t5, $t7, $v0
/* 04BEE8 7F0194F8 448D3000 */  mtc1  $t5, $f6
/* 04BEEC 7F0194FC 3C0141C8 */  li    $at, 0x41C80000 # 25.000000
/* 04BEF0 7F019500 44815000 */  mtc1  $at, $f10
/* 04BEF4 7F019504 46803120 */  cvt.s.w $f4, $f6
/* 04BEF8 7F019508 460A2203 */  div.s $f8, $f4, $f10
/* 04BEFC 7F01950C 10000005 */  b     .L7F019524
/* 04BF00 7F019510 E7A80144 */   swc1  $f8, 0x144($sp)
.L7F019514:
/* 04BF04 7F019514 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 04BF08 7F019518 44813000 */  mtc1  $at, $f6
/* 04BF0C 7F01951C 00000000 */  nop
/* 04BF10 7F019520 E7A60144 */  swc1  $f6, 0x144($sp)
.L7F019524:
/* 04BF14 7F019524 02602025 */  move  $a0, $s3
/* 04BF18 7F019528 00002825 */  move  $a1, $zero
/* 04BF1C 7F01952C 00003025 */  move  $a2, $zero
/* 04BF20 7F019530 00003825 */  move  $a3, $zero
/* 04BF24 7F019534 0C001048 */  jal   viSetFillColor
/* 04BF28 7F019538 E7B00148 */   swc1  $f16, 0x148($sp)
/* 04BF2C 7F01953C 0C000E52 */  jal   viFillScreen
/* 04BF30 7F019540 00402025 */   move  $a0, $v0
/* 04BF34 7F019544 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A4) # $at, 0x8006
/* 04BF38 7F019548 C42084E4 */  lwc1  $f0, %lo(flt_CODE_bss_800695A4)($at)
/* 04BF3C 7F01954C 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695A8) # $at, 0x8006
/* 04BF40 7F019550 C42484E8 */  lwc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
/* 04BF44 7F019554 C7B00148 */  lwc1  $f16, 0x148($sp)
/* 04BF48 7F019558 3C118006 */  lui   $s1, %hi(flt_CODE_bss_800695A0) # $s1, 0x8006
/* 04BF4C 7F01955C 46002281 */  sub.s $f10, $f4, $f0
/* 04BF50 7F019560 263184E0 */  addiu $s1, %lo(flt_CODE_bss_800695A0) # addiu $s1, $s1, -0x7b20
/* 04BF54 7F019564 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B0) # $at, 0x8006
/* 04BF58 7F019568 3C108006 */  lui   $s0, %hi(flt_CODE_bss_800695AC) # $s0, 0x8006
/* 04BF5C 7F01956C 46105202 */  mul.s $f8, $f10, $f16
/* 04BF60 7F019570 261084EC */  addiu $s0, %lo(flt_CODE_bss_800695AC) # addiu $s0, $s0, -0x7b14
/* 04BF64 7F019574 3C128006 */  lui   $s2, %hi(flt_CODE_bss_800695B8) # $s2, 0x8006
/* 04BF68 7F019578 265284F8 */  addiu $s2, %lo(flt_CODE_bss_800695B8) # addiu $s2, $s2, -0x7b08
/* 04BF6C 7F01957C 00409825 */  move  $s3, $v0
/* 04BF70 7F019580 46004180 */  add.s $f6, $f8, $f0
/* 04BF74 7F019584 E6260000 */  swc1  $f6, ($s1)
/* 04BF78 7F019588 C42284F0 */  lwc1  $f2, %lo(flt_CODE_bss_800695B0)($at)
/* 04BF7C 7F01958C 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695B4) # $at, 0x8006
/* 04BF80 7F019590 C42484F4 */  lwc1  $f4, %lo(flt_CODE_bss_800695B4)($at)
/* 04BF84 7F019594 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695BC) # $at, 0x8006
/* 04BF88 7F019598 46022281 */  sub.s $f10, $f4, $f2
/* 04BF8C 7F01959C 46105202 */  mul.s $f8, $f10, $f16
/* 04BF90 7F0195A0 46024180 */  add.s $f6, $f8, $f2
/* 04BF94 7F0195A4 E6060000 */  swc1  $f6, ($s0)
/* 04BF98 7F0195A8 C42C84FC */  lwc1  $f12, %lo(flt_CODE_bss_800695BC)($at)
/* 04BF9C 7F0195AC 3C018006 */  lui   $at, %hi(flt_CODE_bss_800695C0) # $at, 0x8006
/* 04BFA0 7F0195B0 C4248500 */  lwc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
/* 04BFA4 7F0195B4 C60E0000 */  lwc1  $f14, ($s0)
/* 04BFA8 7F0195B8 460C2281 */  sub.s $f10, $f4, $f12
/* 04BFAC 7F0195BC 44802000 */  mtc1  $zero, $f4
/* 04BFB0 7F0195C0 46105202 */  mul.s $f8, $f10, $f16
/* 04BFB4 7F0195C4 4604703C */  c.lt.s $f14, $f4
/* 04BFB8 7F0195C8 460C4180 */  add.s $f6, $f8, $f12
/* 04BFBC 7F0195CC 45000006 */  bc1f  .L7F0195E8
/* 04BFC0 7F0195D0 E6460000 */   swc1  $f6, ($s2)
/* 04BFC4 7F0195D4 3C018004 */  lui   $at, %hi(D_80051B0C) # $at, 0x8004
/* 04BFC8 7F0195D8 C42A7C34 */  lwc1  $f10, %lo(D_80051B0C)($at)
/* 04BFCC 7F0195DC 460A7200 */  add.s $f8, $f14, $f10
/* 04BFD0 7F0195E0 E6080000 */  swc1  $f8, ($s0)
/* 04BFD4 7F0195E4 C60E0000 */  lwc1  $f14, ($s0)
.L7F0195E8:
/* 04BFD8 7F0195E8 0FC1606B */  jal   sinf
/* 04BFDC 7F0195EC 46007306 */   mov.s $f12, $f14
/* 04BFE0 7F0195F0 E7A00078 */  swc1  $f0, 0x78($sp)
/* 04BFE4 7F0195F4 0FC16068 */  jal   cosf
/* 04BFE8 7F0195F8 C60C0000 */   lwc1  $f12, ($s0)
/* 04BFEC 7F0195FC 3C018004 */  lui   $at, %hi(D_80051B10) # $at, 0x8004
/* 04BFF0 7F019600 C4267C38 */  lwc1  $f6, %lo(D_80051B10)($at)
/* 04BFF4 7F019604 C6220000 */  lwc1  $f2, ($s1)
/* 04BFF8 7F019608 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 04BFFC 7F01960C 46060102 */  mul.s $f4, $f0, $f6
/* 04C000 7F019610 C60C0000 */  lwc1  $f12, ($s0)
/* 04C004 7F019614 46022282 */  mul.s $f10, $f4, $f2
/* 04C008 7F019618 00000000 */  nop
/* 04C00C 7F01961C 46081182 */  mul.s $f6, $f2, $f8
/* 04C010 7F019620 C6480000 */  lwc1  $f8, ($s2)
/* 04C014 7F019624 E7A80248 */  swc1  $f8, 0x248($sp)
/* 04C018 7F019628 46065100 */  add.s $f4, $f10, $f6
/* 04C01C 7F01962C 0FC16068 */  jal   cosf
/* 04C020 7F019630 E7A40244 */   swc1  $f4, 0x244($sp)
/* 04C024 7F019634 E7A00078 */  swc1  $f0, 0x78($sp)
/* 04C028 7F019638 0FC1606B */  jal   sinf
/* 04C02C 7F01963C C60C0000 */   lwc1  $f12, ($s0)
/* 04C030 7F019640 C6220000 */  lwc1  $f2, ($s1)
/* 04C034 7F019644 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 04C038 7F019648 3C018004 */  lui   $at, %hi(D_80051B14) # $at, 0x8004
/* 04C03C 7F01964C C4247C3C */  lwc1  $f4, %lo(D_80051B14)($at)
/* 04C040 7F019650 460A1182 */  mul.s $f6, $f2, $f10
/* 04C044 7F019654 C60C0000 */  lwc1  $f12, ($s0)
/* 04C048 7F019658 46040202 */  mul.s $f8, $f0, $f4
/* 04C04C 7F01965C 00000000 */  nop
/* 04C050 7F019660 46024282 */  mul.s $f10, $f8, $f2
/* 04C054 7F019664 460A3101 */  sub.s $f4, $f6, $f10
/* 04C058 7F019668 0FC16068 */  jal   cosf
/* 04C05C 7F01966C E7A4024C */   swc1  $f4, 0x24c($sp)
/* 04C060 7F019670 3C018004 */  lui   $at, %hi(D_80051B18) # $at, 0x8004
/* 04C064 7F019674 C4287C40 */  lwc1  $f8, %lo(D_80051B18)($at)
/* 04C068 7F019678 C62A0000 */  lwc1  $f10, ($s1)
/* 04C06C 7F01967C C60C0000 */  lwc1  $f12, ($s0)
/* 04C070 7F019680 46080182 */  mul.s $f6, $f0, $f8
/* 04C074 7F019684 C7A80238 */  lwc1  $f8, 0x238($sp)
/* 04C078 7F019688 460A3102 */  mul.s $f4, $f6, $f10
/* 04C07C 7F01968C 46044180 */  add.s $f6, $f8, $f4
/* 04C080 7F019690 0FC1606B */  jal   sinf
/* 04C084 7F019694 E7A60238 */   swc1  $f6, 0x238($sp)
/* 04C088 7F019698 3C018004 */  lui   $at, %hi(D_80051B1C) # $at, 0x8004
/* 04C08C 7F01969C C4287C44 */  lwc1  $f8, %lo(D_80051B1C)($at)
/* 04C090 7F0196A0 46000287 */  neg.s $f10, $f0
/* 04C094 7F0196A4 C6260000 */  lwc1  $f6, ($s1)
/* 04C098 7F0196A8 46085102 */  mul.s $f4, $f10, $f8
/* 04C09C 7F0196AC C7A80240 */  lwc1  $f8, 0x240($sp)
/* 04C0A0 7F0196B0 24040002 */  li    $a0, 2
/* 04C0A4 7F0196B4 46062282 */  mul.s $f10, $f4, $f6
/* 04C0A8 7F0196B8 460A4100 */  add.s $f4, $f8, $f10
/* 04C0AC 7F0196BC 0FC2F2AA */  jal   dynAllocate7F0BD6F8
/* 04C0B0 7F0196C0 E7A40240 */   swc1  $f4, 0x240($sp)
/* 04C0B4 7F0196C4 44800000 */  mtc1  $zero, $f0
/* 04C0B8 7F0196C8 3C01457A */  li    $at, 0x457A0000 # 4000.000000
/* 04C0BC 7F0196CC 44813000 */  mtc1  $at, $f6
/* 04C0C0 7F0196D0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 04C0C4 7F0196D4 44814000 */  mtc1  $at, $f8
/* 04C0C8 7F0196D8 44060000 */  mfc1  $a2, $f0
/* 04C0CC 7F0196DC 44070000 */  mfc1  $a3, $f0
/* 04C0D0 7F0196E0 00408025 */  move  $s0, $v0
/* 04C0D4 7F0196E4 27A400E0 */  addiu $a0, $sp, 0xe0
/* 04C0D8 7F0196E8 00402825 */  move  $a1, $v0
/* 04C0DC 7F0196EC E7A00014 */  swc1  $f0, 0x14($sp)
/* 04C0E0 7F0196F0 E7A00018 */  swc1  $f0, 0x18($sp)
/* 04C0E4 7F0196F4 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 04C0E8 7F0196F8 E7A00020 */  swc1  $f0, 0x20($sp)
/* 04C0EC 7F0196FC E7A00028 */  swc1  $f0, 0x28($sp)
/* 04C0F0 7F019700 E7A60010 */  swc1  $f6, 0x10($sp)
/* 04C0F4 7F019704 0C005A84 */  jal   guLookAtReflect
/* 04C0F8 7F019708 E7A80024 */   swc1  $f8, 0x24($sp)
/* 04C0FC 7F01970C 02601025 */  move  $v0, $s3
/* 04C100 7F019710 26730008 */  addiu $s3, $s3, 8
/* 04C104 7F019714 3C0BBC00 */  lui   $t3, (0xBC000002 >> 16) # lui $t3, 0xbc00
/* 04C108 7F019718 3C188000 */  lui   $t8, (0x80000040 >> 16) # lui $t8, 0x8000
/* 04C10C 7F01971C 37180040 */  ori   $t8, (0x80000040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 04C110 7F019720 356B0002 */  ori   $t3, (0xBC000002 & 0xFFFF) # ori $t3, $t3, 2
/* 04C114 7F019724 02601825 */  move  $v1, $s3
/* 04C118 7F019728 26730008 */  addiu $s3, $s3, 8
/* 04C11C 7F01972C AC4B0000 */  sw    $t3, ($v0)
/* 04C120 7F019730 AC580004 */  sw    $t8, 4($v0)
/* 04C124 7F019734 3C0C0386 */  lui   $t4, (0x03860010 >> 16) # lui $t4, 0x386
/* 04C128 7F019738 3C198002 */  lui   $t9, %hi(gelogolight + 0x8) # $t9, 0x8002
/* 04C12C 7F01973C 27395EC8 */  addiu $t9, %lo(gelogolight + 0x8) # addiu $t9, $t9, 0x5ec8
/* 04C130 7F019740 358C0010 */  ori   $t4, (0x03860010 & 0xFFFF) # ori $t4, $t4, 0x10
/* 04C134 7F019744 02602025 */  move  $a0, $s3
/* 04C138 7F019748 26730008 */  addiu $s3, $s3, 8
/* 04C13C 7F01974C AC6C0000 */  sw    $t4, ($v1)
/* 04C140 7F019750 AC790004 */  sw    $t9, 4($v1)
/* 04C144 7F019754 3C0E0388 */  lui   $t6, (0x03880010 >> 16) # lui $t6, 0x388
/* 04C148 7F019758 3C0F8002 */  lui   $t7, %hi(gelogolight) # $t7, 0x8002
/* 04C14C 7F01975C 25EF5EC0 */  addiu $t7, %lo(gelogolight) # addiu $t7, $t7, 0x5ec0
/* 04C150 7F019760 35CE0010 */  ori   $t6, (0x03880010 & 0xFFFF) # ori $t6, $t6, 0x10
/* 04C154 7F019764 02602825 */  move  $a1, $s3
/* 04C158 7F019768 AC8E0000 */  sw    $t6, ($a0)
/* 04C15C 7F01976C AC8F0004 */  sw    $t7, 4($a0)
/* 04C160 7F019770 3C0D0384 */  lui   $t5, (0x03840010 >> 16) # lui $t5, 0x384
/* 04C164 7F019774 35AD0010 */  ori   $t5, (0x03840010 & 0xFFFF) # ori $t5, $t5, 0x10
/* 04C168 7F019778 ACAD0000 */  sw    $t5, ($a1)
/* 04C16C 7F01977C ACB00004 */  sw    $s0, 4($a1)
/* 04C170 7F019780 26730008 */  addiu $s3, $s3, 8
/* 04C174 7F019784 02603825 */  move  $a3, $s3
/* 04C178 7F019788 3C0B0382 */  lui   $t3, (0x03820010 >> 16) # lui $t3, 0x382
/* 04C17C 7F01978C 356B0010 */  ori   $t3, (0x03820010 & 0xFFFF) # ori $t3, $t3, 0x10
/* 04C180 7F019790 26180010 */  addiu $t8, $s0, 0x10
/* 04C184 7F019794 3C148002 */  lui   $s4, %hi(cast_model) # $s4, 0x8002
/* 04C188 7F019798 26946B44 */  addiu $s4, %lo(cast_model) # addiu $s4, $s4, 0x6b44
/* 04C18C 7F01979C ACF80004 */  sw    $t8, 4($a3)
/* 04C190 7F0197A0 ACEB0000 */  sw    $t3, ($a3)
/* 04C194 7F0197A4 3C058004 */  lui   $a1, %hi(g_ClockTimer) # $a1, 0x8004
/* 04C198 7F0197A8 26730008 */  addiu $s3, $s3, 8
/* 04C19C 7F0197AC 8CA50FF4 */  lw    $a1, %lo(g_ClockTimer)($a1)
/* 04C1A0 7F0197B0 8E840000 */  lw    $a0, ($s4)
/* 04C1A4 7F0197B4 0FC1C323 */  jal   modelTickAnimQuarterSpeed
/* 04C1A8 7F0197B8 24060001 */   li    $a2, 1
/* 04C1AC 7F0197BC 0FC1B2D0 */  jal   modelSetDistanceDisabled
/* 04C1B0 7F0197C0 24040001 */   li    $a0, 1
/* 04C1B4 7F0197C4 0FC1D037 */  jal   sub_GAME_7F073FC8
/* 04C1B8 7F0197C8 00002025 */   move  $a0, $zero
/* 04C1BC 7F0197CC 0FC1B6B8 */  jal   subcalcpos
/* 04C1C0 7F0197D0 8E840000 */   lw    $a0, ($s4)
/* 04C1C4 7F0197D4 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C1C8 7F0197D8 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C1CC 7F0197DC 10E0000B */  beqz  $a3, .L7F01980C
/* 04C1D0 7F0197E0 00000000 */   nop
/* 04C1D4 7F0197E4 8CEC0008 */  lw    $t4, 8($a3)
/* 04C1D8 7F0197E8 8D990008 */  lw    $t9, 8($t4)
/* 04C1DC 7F0197EC 8F250000 */  lw    $a1, ($t9)
/* 04C1E0 7F0197F0 10A00006 */  beqz  $a1, .L7F01980C
/* 04C1E4 7F0197F4 00000000 */   nop
/* 04C1E8 7F0197F8 0FC1B3A3 */  jal   modelGetNodeRwData
/* 04C1EC 7F0197FC 00E02025 */   move  $a0, $a3
/* 04C1F0 7F019800 A4400000 */  sh    $zero, ($v0)
/* 04C1F4 7F019804 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C1F8 7F019808 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
.L7F01980C:
/* 04C1FC 7F01980C 50E0000A */  beql  $a3, $zero, .L7F019838
/* 04C200 7F019810 8E8D0000 */   lw    $t5, ($s4)
/* 04C204 7F019814 8CEE0008 */  lw    $t6, 8($a3)
/* 04C208 7F019818 8DCF0008 */  lw    $t7, 8($t6)
/* 04C20C 7F01981C 8DE50008 */  lw    $a1, 8($t7)
/* 04C210 7F019820 50A00005 */  beql  $a1, $zero, .L7F019838
/* 04C214 7F019824 8E8D0000 */   lw    $t5, ($s4)
/* 04C218 7F019828 0FC1B3A3 */  jal   modelGetNodeRwData
/* 04C21C 7F01982C 00E02025 */   move  $a0, $a3
/* 04C220 7F019830 AC400000 */  sw    $zero, ($v0)
/* 04C224 7F019834 8E8D0000 */  lw    $t5, ($s4)
.L7F019838:
/* 04C228 7F019838 8DAB0008 */  lw    $t3, 8($t5)
/* 04C22C 7F01983C 8564000E */  lh    $a0, 0xe($t3)
/* 04C230 7F019840 0004C180 */  sll   $t8, $a0, 6
/* 04C234 7F019844 0FC2F2B1 */  jal   dynAllocate
/* 04C238 7F019848 03002025 */   move  $a0, $t8
/* 04C23C 7F01984C 27B201E8 */  addiu $s2, $sp, 0x1e8
/* 04C240 7F019850 AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04C244 7F019854 0FC1611E */  jal   matrix_4x4_set_identity
/* 04C248 7F019858 02402025 */   move  $a0, $s2
/* 04C24C 7F01985C AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04C250 7F019860 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04C254 7F019864 0FC1BD9C */  jal   subcalcmatrices
/* 04C258 7F019868 8E850000 */   lw    $a1, ($s4)
/* 04C25C 7F01986C 8E840000 */  lw    $a0, ($s4)
/* 04C260 7F019870 0FC1B476 */  jal   getsuboffset
/* 04C264 7F019874 27A50128 */   addiu $a1, $sp, 0x128
/* 04C268 7F019878 3C068006 */  lui   $a2, %hi(bss_800695E4) # $a2, 0x8006
/* 04C26C 7F01987C 24C68524 */  addiu $a2, %lo(bss_800695E4) # addiu $a2, $a2, -0x7adc
/* 04C270 7F019880 8CC20000 */  lw    $v0, ($a2)
/* 04C274 7F019884 00008825 */  move  $s1, $zero
/* 04C278 7F019888 3C038004 */  lui   $v1, %hi(g_ClockTimer) # $v1, 0x8004
/* 04C27C 7F01988C 10400005 */  beqz  $v0, .L7F0198A4
/* 04C280 7F019890 00000000 */   nop
/* 04C284 7F019894 C7AA012C */  lwc1  $f10, 0x12c($sp)
/* 04C288 7F019898 3C108006 */  lui   $s0, %hi(flt_CODE_bss_800695E8) # $s0, 0x8006
/* 04C28C 7F01989C 26108528 */  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x7ad8
/* 04C290 7F0198A0 E60A0004 */  swc1  $f10, 4($s0)
.L7F0198A4:
/* 04C294 7F0198A4 3C108006 */  lui   $s0, %hi(flt_CODE_bss_800695E8) # $s0, 0x8006
/* 04C298 7F0198A8 26108528 */  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x7ad8
/* 04C29C 7F0198AC C6040000 */  lwc1  $f4, ($s0)
/* 04C2A0 7F0198B0 C7A60128 */  lwc1  $f6, 0x128($sp)
/* 04C2A4 7F0198B4 3C018004 */  lui   $at, %hi(g_GlobalTimerDelta) # $at, 0x8004
/* 04C2A8 7F0198B8 E7A4006C */  swc1  $f4, 0x6c($sp)
/* 04C2AC 7F0198BC C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 04C2B0 7F0198C0 C6040004 */  lwc1  $f4, 4($s0)
/* 04C2B4 7F0198C4 C4321004 */  lwc1  $f18, %lo(g_GlobalTimerDelta)($at)
/* 04C2B8 7F0198C8 46083281 */  sub.s $f10, $f6, $f8
/* 04C2BC 7F0198CC E7A40064 */  swc1  $f4, 0x64($sp)
/* 04C2C0 7F0198D0 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 04C2C4 7F0198D4 C7A6012C */  lwc1  $f6, 0x12c($sp)
/* 04C2C8 7F0198D8 C6040008 */  lwc1  $f4, 8($s0)
/* 04C2CC 7F0198DC 46125083 */  div.s $f2, $f10, $f18
/* 04C2D0 7F0198E0 E7A40060 */  swc1  $f4, 0x60($sp)
/* 04C2D4 7F0198E4 46083281 */  sub.s $f10, $f6, $f8
/* 04C2D8 7F0198E8 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 04C2DC 7F0198EC C7A60130 */  lwc1  $f6, 0x130($sp)
/* 04C2E0 7F0198F0 46125303 */  div.s $f12, $f10, $f18
/* 04C2E4 7F0198F4 46083281 */  sub.s $f10, $f6, $f8
/* 04C2E8 7F0198F8 1040000B */  beqz  $v0, .L7F019928
/* 04C2EC 7F0198FC 46125383 */   div.s $f14, $f10, $f18
/* 04C2F0 7F019900 3C018004 */  lui   $at, %hi(D_80051B20) # $at, 0x8004
/* 04C2F4 7F019904 C4307C48 */  lwc1  $f16, %lo(D_80051B20)($at)
/* 04C2F8 7F019908 3C028006 */  lui   $v0, %hi(flt_CODE_bss_80069608) # $v0, 0x8006
/* 04C2FC 7F01990C 24428548 */  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x7ab8
/* 04C300 7F019910 46101103 */  div.s $f4, $f2, $f16
/* 04C304 7F019914 46106183 */  div.s $f6, $f12, $f16
/* 04C308 7F019918 E4440000 */  swc1  $f4, ($v0)
/* 04C30C 7F01991C 46107203 */  div.s $f8, $f14, $f16
/* 04C310 7F019920 E4460004 */  swc1  $f6, 4($v0)
/* 04C314 7F019924 E4480008 */  swc1  $f8, 8($v0)
.L7F019928:
/* 04C318 7F019928 8C630FF4 */  lw    $v1, %lo(g_ClockTimer)($v1)
/* 04C31C 7F01992C 3C028006 */  lui   $v0, %hi(flt_CODE_bss_80069608) # $v0, 0x8006
/* 04C320 7F019930 3C018004 */  lui   $at, %hi(D_80051B24) # $at, 0x8004
/* 04C324 7F019934 C4307C4C */  lwc1  $f16, %lo(D_80051B24)($at)
/* 04C328 7F019938 24428548 */  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x7ab8
/* 04C32C 7F01993C E7A20134 */  swc1  $f2, 0x134($sp)
/* 04C330 7F019940 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04C334 7F019944 18600025 */  blez  $v1, .L7F0199DC
/* 04C338 7F019948 E7AE013C */   swc1  $f14, 0x13c($sp)
/* 04C33C 7F01994C 3C018004 */  lui   $at, %hi(D_80051B28) # $at, 0x8004
/* 04C340 7F019950 C4207C50 */  lwc1  $f0, %lo(D_80051B28)($at)
/* 04C344 7F019954 C4440000 */  lwc1  $f4, ($v0)
/* 04C348 7F019958 26310001 */  addiu $s1, $s1, 1
/* 04C34C 7F01995C 0223082A */  slt   $at, $s1, $v1
/* 04C350 7F019960 46040282 */  mul.s $f10, $f0, $f4
/* 04C354 7F019964 10200010 */  beqz  $at, .L7F0199A8
/* 04C358 7F019968 C4480004 */   lwc1  $f8, 4($v0)
.L7F01996C:
/* 04C35C 7F01996C 46080182 */  mul.s $f6, $f0, $f8
/* 04C360 7F019970 460A1100 */  add.s $f4, $f2, $f10
/* 04C364 7F019974 C4480008 */  lwc1  $f8, 8($v0)
/* 04C368 7F019978 26310001 */  addiu $s1, $s1, 1
/* 04C36C 7F01997C 0223082A */  slt   $at, $s1, $v1
/* 04C370 7F019980 46080282 */  mul.s $f10, $f0, $f8
/* 04C374 7F019984 E4440000 */  swc1  $f4, ($v0)
/* 04C378 7F019988 46066180 */  add.s $f6, $f12, $f6
/* 04C37C 7F01998C C4440000 */  lwc1  $f4, ($v0)
/* 04C380 7F019990 E4460004 */  swc1  $f6, 4($v0)
/* 04C384 7F019994 460A7180 */  add.s $f6, $f14, $f10
/* 04C388 7F019998 46040282 */  mul.s $f10, $f0, $f4
/* 04C38C 7F01999C C4480004 */  lwc1  $f8, 4($v0)
/* 04C390 7F0199A0 1420FFF2 */  bnez  $at, .L7F01996C
/* 04C394 7F0199A4 E4460008 */   swc1  $f6, 8($v0)
.L7F0199A8:
/* 04C398 7F0199A8 46080182 */  mul.s $f6, $f0, $f8
/* 04C39C 7F0199AC C4480008 */  lwc1  $f8, 8($v0)
/* 04C3A0 7F0199B0 460A1100 */  add.s $f4, $f2, $f10
/* 04C3A4 7F0199B4 46080282 */  mul.s $f10, $f0, $f8
/* 04C3A8 7F0199B8 E4440000 */  swc1  $f4, ($v0)
/* 04C3AC 7F0199BC 46066180 */  add.s $f6, $f12, $f6
/* 04C3B0 7F0199C0 E4460004 */  swc1  $f6, 4($v0)
/* 04C3B4 7F0199C4 460A7180 */  add.s $f6, $f14, $f10
/* 04C3B8 7F0199C8 E4460008 */  swc1  $f6, 8($v0)
/* 04C3BC 7F0199CC E7AE013C */  swc1  $f14, 0x13c($sp)
/* 04C3C0 7F0199D0 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04C3C4 7F0199D4 E7A20134 */  swc1  $f2, 0x134($sp)
/* 04C3C8 7F0199D8 00008825 */  move  $s1, $zero
.L7F0199DC:
/* 04C3CC 7F0199DC C4440000 */  lwc1  $f4, ($v0)
/* 04C3D0 7F0199E0 C4480004 */  lwc1  $f8, 4($v0)
/* 04C3D4 7F0199E4 3C038006 */  lui   $v1, %hi(flt_CODE_bss_800695F8) # $v1, 0x8006
/* 04C3D8 7F0199E8 46102182 */  mul.s $f6, $f4, $f16
/* 04C3DC 7F0199EC C4440008 */  lwc1  $f4, 8($v0)
/* 04C3E0 7F0199F0 24638538 */  addiu $v1, %lo(flt_CODE_bss_800695F8) # addiu $v1, $v1, -0x7ac8
/* 04C3E4 7F0199F4 46104282 */  mul.s $f10, $f8, $f16
/* 04C3E8 7F0199F8 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 04C3EC 7F0199FC 8E8C0000 */  lw    $t4, ($s4)
/* 04C3F0 7F019A00 27A50134 */  addiu $a1, $sp, 0x134
/* 04C3F4 7F019A04 E4660000 */  swc1  $f6, ($v1)
/* 04C3F8 7F019A08 46102182 */  mul.s $f6, $f4, $f16
/* 04C3FC 7F019A0C E46A0004 */  swc1  $f10, 4($v1)
/* 04C400 7F019A10 C46A0000 */  lwc1  $f10, ($v1)
/* 04C404 7F019A14 46125102 */  mul.s $f4, $f10, $f18
/* 04C408 7F019A18 E4660008 */  swc1  $f6, 8($v1)
/* 04C40C 7F019A1C C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 04C410 7F019A20 46044180 */  add.s $f6, $f8, $f4
/* 04C414 7F019A24 C4680004 */  lwc1  $f8, 4($v1)
/* 04C418 7F019A28 46124102 */  mul.s $f4, $f8, $f18
/* 04C41C 7F019A2C E6060000 */  swc1  $f6, ($s0)
/* 04C420 7F019A30 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 04C424 7F019A34 46045180 */  add.s $f6, $f10, $f4
/* 04C428 7F019A38 C46A0008 */  lwc1  $f10, 8($v1)
/* 04C42C 7F019A3C 46125102 */  mul.s $f4, $f10, $f18
/* 04C430 7F019A40 E6060004 */  swc1  $f6, 4($s0)
/* 04C434 7F019A44 46044180 */  add.s $f6, $f8, $f4
/* 04C438 7F019A48 E6060008 */  swc1  $f6, 8($s0)
/* 04C43C 7F019A4C 0FC16247 */  jal   mtx4TransformVecInPlace
/* 04C440 7F019A50 8D84000C */   lw    $a0, 0xc($t4)
/* 04C444 7F019A54 C60A0004 */  lwc1  $f10, 4($s0)
/* 04C448 7F019A58 C6040008 */  lwc1  $f4, 8($s0)
/* 04C44C 7F019A5C 3C068006 */  lui   $a2, %hi(bss_800695E4) # $a2, 0x8006
/* 04C450 7F019A60 24C68524 */  addiu $a2, %lo(bss_800695E4) # addiu $a2, $a2, -0x7adc
/* 04C454 7F019A64 8CD90000 */  lw    $t9, ($a2)
/* 04C458 7F019A68 3C018004 */  lui   $at, %hi(D_80051B30) # $at, 0x8004
/* 04C45C 7F019A6C E7AA0064 */  swc1  $f10, 0x64($sp)
/* 04C460 7F019A70 E7A40060 */  swc1  $f4, 0x60($sp)
/* 04C464 7F019A74 C7A20134 */  lwc1  $f2, 0x134($sp)
/* 04C468 7F019A78 C7AC0138 */  lwc1  $f12, 0x138($sp)
/* 04C46C 7F019A7C C7AE013C */  lwc1  $f14, 0x13c($sp)
/* 04C470 7F019A80 C6120000 */  lwc1  $f18, ($s0)
/* 04C474 7F019A84 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 04C478 7F019A88 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 04C47C 7F019A8C C4207C58 */  lwc1  $f0, %lo(D_80051B30)($at)
/* 04C480 7F019A90 3C018004 */  lui   $at, %hi(D_80051B34) # $at, 0x8004
/* 04C484 7F019A94 C4307C5C */  lwc1  $f16, %lo(D_80051B34)($at)
/* 04C488 7F019A98 46121081 */  sub.s $f2, $f2, $f18
/* 04C48C 7F019A9C 46086301 */  sub.s $f12, $f12, $f8
/* 04C490 7F019AA0 1320000A */  beqz  $t9, .L7F019ACC
/* 04C494 7F019AA4 46067381 */   sub.s $f14, $f14, $f6
/* 04C498 7F019AA8 46101283 */  div.s $f10, $f2, $f16
/* 04C49C 7F019AAC 3C028006 */  lui   $v0, %hi(flt_CODE_bss_800695D8) # $v0, 0x8006
/* 04C4A0 7F019AB0 24428518 */  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x7ae8
/* 04C4A4 7F019AB4 ACC00000 */  sw    $zero, ($a2)
/* 04C4A8 7F019AB8 46106203 */  div.s $f8, $f12, $f16
/* 04C4AC 7F019ABC E44A0000 */  swc1  $f10, ($v0)
/* 04C4B0 7F019AC0 46107103 */  div.s $f4, $f14, $f16
/* 04C4B4 7F019AC4 E4480004 */  swc1  $f8, 4($v0)
/* 04C4B8 7F019AC8 E4440008 */  swc1  $f4, 8($v0)
.L7F019ACC:
/* 04C4BC 7F019ACC 3C038004 */  lui   $v1, %hi(g_ClockTimer) # $v1, 0x8004
/* 04C4C0 7F019AD0 8C630FF4 */  lw    $v1, %lo(g_ClockTimer)($v1)
/* 04C4C4 7F019AD4 3C028006 */  lui   $v0, %hi(flt_CODE_bss_800695D8) # $v0, 0x8006
/* 04C4C8 7F019AD8 24428518 */  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x7ae8
/* 04C4CC 7F019ADC 58600021 */  blezl $v1, .L7F019B64
/* 04C4D0 7F019AE0 C44A0000 */   lwc1  $f10, ($v0)
/* 04C4D4 7F019AE4 C4440000 */  lwc1  $f4, ($v0)
/* 04C4D8 7F019AE8 26310001 */  addiu $s1, $s1, 1
/* 04C4DC 7F019AEC 0223082A */  slt   $at, $s1, $v1
/* 04C4E0 7F019AF0 46040202 */  mul.s $f8, $f0, $f4
/* 04C4E4 7F019AF4 10200010 */  beqz  $at, .L7F019B38
/* 04C4E8 7F019AF8 C44A0004 */   lwc1  $f10, 4($v0)
.L7F019AFC:
/* 04C4EC 7F019AFC 460A0182 */  mul.s $f6, $f0, $f10
/* 04C4F0 7F019B00 46081100 */  add.s $f4, $f2, $f8
/* 04C4F4 7F019B04 C44A0008 */  lwc1  $f10, 8($v0)
/* 04C4F8 7F019B08 26310001 */  addiu $s1, $s1, 1
/* 04C4FC 7F019B0C 0223082A */  slt   $at, $s1, $v1
/* 04C500 7F019B10 460A0202 */  mul.s $f8, $f0, $f10
/* 04C504 7F019B14 E4440000 */  swc1  $f4, ($v0)
/* 04C508 7F019B18 46066180 */  add.s $f6, $f12, $f6
/* 04C50C 7F019B1C C4440000 */  lwc1  $f4, ($v0)
/* 04C510 7F019B20 E4460004 */  swc1  $f6, 4($v0)
/* 04C514 7F019B24 46087180 */  add.s $f6, $f14, $f8
/* 04C518 7F019B28 46040202 */  mul.s $f8, $f0, $f4
/* 04C51C 7F019B2C C44A0004 */  lwc1  $f10, 4($v0)
/* 04C520 7F019B30 1420FFF2 */  bnez  $at, .L7F019AFC
/* 04C524 7F019B34 E4460008 */   swc1  $f6, 8($v0)
.L7F019B38:
/* 04C528 7F019B38 460A0182 */  mul.s $f6, $f0, $f10
/* 04C52C 7F019B3C C44A0008 */  lwc1  $f10, 8($v0)
/* 04C530 7F019B40 46081100 */  add.s $f4, $f2, $f8
/* 04C534 7F019B44 460A0202 */  mul.s $f8, $f0, $f10
/* 04C538 7F019B48 E4440000 */  swc1  $f4, ($v0)
/* 04C53C 7F019B4C 46066180 */  add.s $f6, $f12, $f6
/* 04C540 7F019B50 E4460004 */  swc1  $f6, 4($v0)
/* 04C544 7F019B54 46087180 */  add.s $f6, $f14, $f8
/* 04C548 7F019B58 E4460008 */  swc1  $f6, 8($v0)
/* 04C54C 7F019B5C 00008825 */  move  $s1, $zero
/* 04C550 7F019B60 C44A0000 */  lwc1  $f10, ($v0)
.L7F019B64:
/* 04C554 7F019B64 C4440004 */  lwc1  $f4, 4($v0)
/* 04C558 7F019B68 3C038006 */  lui   $v1, %hi(flt_CODE_bss_800695C8) # $v1, 0x8006
/* 04C55C 7F019B6C 46105202 */  mul.s $f8, $f10, $f16
/* 04C560 7F019B70 C44A0008 */  lwc1  $f10, 8($v0)
/* 04C564 7F019B74 24638508 */  addiu $v1, %lo(flt_CODE_bss_800695C8) # addiu $v1, $v1, -0x7af8
/* 04C568 7F019B78 46102182 */  mul.s $f6, $f4, $f16
/* 04C56C 7F019B7C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 04C570 7F019B80 C7A0023C */  lwc1  $f0, 0x23c($sp)
/* 04C574 7F019B84 02402025 */  move  $a0, $s2
/* 04C578 7F019B88 E4680000 */  swc1  $f8, ($v1)
/* 04C57C 7F019B8C 46105202 */  mul.s $f8, $f10, $f16
/* 04C580 7F019B90 C4640000 */  lwc1  $f4, ($v1)
/* 04C584 7F019B94 E4660004 */  swc1  $f6, 4($v1)
/* 04C588 7F019B98 C46A0004 */  lwc1  $f10, 4($v1)
/* 04C58C 7F019B9C C7A60064 */  lwc1  $f6, 0x64($sp)
/* 04C590 7F019BA0 46049080 */  add.s $f2, $f18, $f4
/* 04C594 7F019BA4 44812000 */  mtc1  $at, $f4
/* 04C598 7F019BA8 E4680008 */  swc1  $f8, 8($v1)
/* 04C59C 7F019BAC 460A3200 */  add.s $f8, $f6, $f10
/* 04C5A0 7F019BB0 C7AA0060 */  lwc1  $f10, 0x60($sp)
/* 04C5A4 7F019BB4 E7A60050 */  swc1  $f6, 0x50($sp)
/* 04C5A8 7F019BB8 3C014252 */  li    $at, 0x42520000 # 52.500000
/* 04C5AC 7F019BBC 46044301 */  sub.s $f12, $f8, $f4
/* 04C5B0 7F019BC0 C4680008 */  lwc1  $f8, 8($v1)
/* 04C5B4 7F019BC4 C7A40238 */  lwc1  $f4, 0x238($sp)
/* 04C5B8 7F019BC8 E7AA0054 */  swc1  $f10, 0x54($sp)
/* 04C5BC 7F019BCC 46085380 */  add.s $f14, $f10, $f8
/* 04C5C0 7F019BD0 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 04C5C4 7F019BD4 C7A60244 */  lwc1  $f6, 0x244($sp)
/* 04C5C8 7F019BD8 46022200 */  add.s $f8, $f4, $f2
/* 04C5CC 7F019BDC C7A40240 */  lwc1  $f4, 0x240($sp)
/* 04C5D0 7F019BE0 E7AE013C */  swc1  $f14, 0x13c($sp)
/* 04C5D4 7F019BE4 46123180 */  add.s $f6, $f6, $f18
/* 04C5D8 7F019BE8 E7A80238 */  swc1  $f8, 0x238($sp)
/* 04C5DC 7F019BEC E7A80050 */  swc1  $f8, 0x50($sp)
/* 04C5E0 7F019BF0 44814000 */  mtc1  $at, $f8
/* 04C5E4 7F019BF4 460E2100 */  add.s $f4, $f4, $f14
/* 04C5E8 7F019BF8 E7A60244 */  swc1  $f6, 0x244($sp)
/* 04C5EC 7F019BFC 44053000 */  mfc1  $a1, $f6
/* 04C5F0 7F019C00 46085280 */  add.s $f10, $f10, $f8
/* 04C5F4 7F019C04 C7A80248 */  lwc1  $f8, 0x248($sp)
/* 04C5F8 7F019C08 E7A40240 */  swc1  $f4, 0x240($sp)
/* 04C5FC 7F019C0C E7A40058 */  swc1  $f4, 0x58($sp)
/* 04C600 7F019C10 460A4200 */  add.s $f8, $f8, $f10
/* 04C604 7F019C14 C7AA024C */  lwc1  $f10, 0x24c($sp)
/* 04C608 7F019C18 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 04C60C 7F019C1C 460C0000 */  add.s $f0, $f0, $f12
/* 04C610 7F019C20 E7A80248 */  swc1  $f8, 0x248($sp)
/* 04C614 7F019C24 44064000 */  mfc1  $a2, $f8
/* 04C618 7F019C28 46045280 */  add.s $f10, $f10, $f4
/* 04C61C 7F019C2C C7A40050 */  lwc1  $f4, 0x50($sp)
/* 04C620 7F019C30 C7A8022C */  lwc1  $f8, 0x22c($sp)
/* 04C624 7F019C34 C7A60058 */  lwc1  $f6, 0x58($sp)
/* 04C628 7F019C38 E7AA024C */  swc1  $f10, 0x24c($sp)
/* 04C62C 7F019C3C 44075000 */  mfc1  $a3, $f10
/* 04C630 7F019C40 E7A40010 */  swc1  $f4, 0x10($sp)
/* 04C634 7F019C44 C7A40234 */  lwc1  $f4, 0x234($sp)
/* 04C638 7F019C48 C7AA0230 */  lwc1  $f10, 0x230($sp)
/* 04C63C 7F019C4C E7A00014 */  swc1  $f0, 0x14($sp)
/* 04C640 7F019C50 E7A0023C */  swc1  $f0, 0x23c($sp)
/* 04C644 7F019C54 E7AC0138 */  swc1  $f12, 0x138($sp)
/* 04C648 7F019C58 E7A20134 */  swc1  $f2, 0x134($sp)
/* 04C64C 7F019C5C E7A8001C */  swc1  $f8, 0x1c($sp)
/* 04C650 7F019C60 E7A60018 */  swc1  $f6, 0x18($sp)
/* 04C654 7F019C64 E7A40024 */  swc1  $f4, 0x24($sp)
/* 04C658 7F019C68 0FC166CF */  jal   matrix_4x4_7F059694
/* 04C65C 7F019C6C E7AA0020 */   swc1  $f10, 0x20($sp)
/* 04C660 7F019C70 8E8E0000 */  lw    $t6, ($s4)
/* 04C664 7F019C74 AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04C668 7F019C78 8DCF0008 */  lw    $t7, 8($t6)
/* 04C66C 7F019C7C 85E4000E */  lh    $a0, 0xe($t7)
/* 04C670 7F019C80 00046980 */  sll   $t5, $a0, 6
/* 04C674 7F019C84 0FC2F2B1 */  jal   dynAllocate
/* 04C678 7F019C88 01A02025 */   move  $a0, $t5
/* 04C67C 7F019C8C AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04C680 7F019C90 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04C684 7F019C94 0FC1BD9C */  jal   subcalcmatrices
/* 04C688 7F019C98 8E850000 */   lw    $a1, ($s4)
/* 04C68C 7F019C9C 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C690 7F019CA0 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C694 7F019CA4 50E00025 */  beql  $a3, $zero, .L7F019D3C
/* 04C698 7F019CA8 24180007 */   li    $t8, 7
/* 04C69C 7F019CAC 8E840000 */  lw    $a0, ($s4)
/* 04C6A0 7F019CB0 8CE5001C */  lw    $a1, 0x1c($a3)
/* 04C6A4 7F019CB4 0FC1B366 */  jal   modelFindNodeMtx
/* 04C6A8 7F019CB8 00003025 */   move  $a2, $zero
/* 04C6AC 7F019CBC 8E980000 */  lw    $t8, ($s4)
/* 04C6B0 7F019CC0 AFA201A8 */  sw    $v0, 0x1a8($sp)
/* 04C6B4 7F019CC4 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C6B8 7F019CC8 8F0C0008 */  lw    $t4, 8($t8)
/* 04C6BC 7F019CCC 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C6C0 7F019CD0 27B20160 */  addiu $s2, $sp, 0x160
/* 04C6C4 7F019CD4 8D990008 */  lw    $t9, 8($t4)
/* 04C6C8 7F019CD8 8CEB001C */  lw    $t3, 0x1c($a3)
/* 04C6CC 7F019CDC 02402825 */  move  $a1, $s2
/* 04C6D0 7F019CE0 8F2E0014 */  lw    $t6, 0x14($t9)
/* 04C6D4 7F019CE4 3C018004 */  lui   $at, %hi(D_80051B38) # $at, 0x8004
/* 04C6D8 7F019CE8 556E000A */  bnel  $t3, $t6, .L7F019D14
/* 04C6DC 7F019CEC 8CEF0008 */   lw    $t7, 8($a3)
/* 04C6E0 7F019CF0 0FC162CC */  jal   matrix_4x4_set_rotation_around_z
/* 04C6E4 7F019CF4 C42C7C60 */   lwc1  $f12, %lo(D_80051B38)($at)
/* 04C6E8 7F019CF8 8FA401A8 */  lw    $a0, 0x1a8($sp)
/* 04C6EC 7F019CFC 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 04C6F0 7F019D00 02402825 */   move  $a1, $s2
/* 04C6F4 7F019D04 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C6F8 7F019D08 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C6FC 7F019D0C AFB201A8 */  sw    $s2, 0x1a8($sp)
/* 04C700 7F019D10 8CEF0008 */  lw    $t7, 8($a3)
.L7F019D14:
/* 04C704 7F019D14 85E4000E */  lh    $a0, 0xe($t7)
/* 04C708 7F019D18 00046980 */  sll   $t5, $a0, 6
/* 04C70C 7F019D1C 0FC2F2B1 */  jal   dynAllocate
/* 04C710 7F019D20 01A02025 */   move  $a0, $t5
/* 04C714 7F019D24 3C058002 */  lui   $a1, %hi(cast_model_weapon) # $a1, 0x8002
/* 04C718 7F019D28 AFA201B8 */  sw    $v0, 0x1b8($sp)
/* 04C71C 7F019D2C 8CA56B48 */  lw    $a1, %lo(cast_model_weapon)($a1)
/* 04C720 7F019D30 0FC1BD8D */  jal   instcalcmatrices
/* 04C724 7F019D34 27A401A8 */   addiu $a0, $sp, 0x1a8
/* 04C728 7F019D38 24180007 */  li    $t8, 7
.L7F019D3C:
/* 04C72C 7F019D3C 240C0001 */  li    $t4, 1
/* 04C730 7F019D40 24190003 */  li    $t9, 3
/* 04C734 7F019D44 27B20160 */  addiu $s2, $sp, 0x160
/* 04C738 7F019D48 AFB801D8 */  sw    $t8, 0x1d8($sp)
/* 04C73C 7F019D4C AFAC01AC */  sw    $t4, 0x1ac($sp)
/* 04C740 7F019D50 AFB301B4 */  sw    $s3, 0x1b4($sp)
/* 04C744 7F019D54 AFB901B0 */  sw    $t9, 0x1b0($sp)
/* 04C748 7F019D58 27A401A8 */  addiu $a0, $sp, 0x1a8
/* 04C74C 7F019D5C 0FC1D1D6 */  jal   subdraw
/* 04C750 7F019D60 8E850000 */   lw    $a1, ($s4)
/* 04C754 7F019D64 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C758 7F019D68 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C75C 7F019D6C 10E00003 */  beqz  $a3, .L7F019D7C
/* 04C760 7F019D70 27A401A8 */   addiu $a0, $sp, 0x1a8
/* 04C764 7F019D74 0FC1D1D6 */  jal   subdraw
/* 04C768 7F019D78 00E02825 */   move  $a1, $a3
.L7F019D7C:
/* 04C76C 7F019D7C 8FB301B4 */  lw    $s3, 0x1b4($sp)
/* 04C770 7F019D80 0FC1B2D0 */  jal   modelSetDistanceDisabled
/* 04C774 7F019D84 00002025 */   move  $a0, $zero
/* 04C778 7F019D88 8E820000 */  lw    $v0, ($s4)
/* 04C77C 7F019D8C 8C4B0008 */  lw    $t3, 8($v0)
/* 04C780 7F019D90 856E000E */  lh    $t6, 0xe($t3)
/* 04C784 7F019D94 19C00013 */  blez  $t6, .L7F019DE4
/* 04C788 7F019D98 00008025 */   move  $s0, $zero
/* 04C78C 7F019D9C 8C4F000C */  lw    $t7, 0xc($v0)
.L7F019DA0:
/* 04C790 7F019DA0 02402825 */  move  $a1, $s2
/* 04C794 7F019DA4 0FC16132 */  jal   matrix_4x4_copy
/* 04C798 7F019DA8 01F02021 */   addu  $a0, $t7, $s0
/* 04C79C 7F019DAC 8E8D0000 */  lw    $t5, ($s4)
/* 04C7A0 7F019DB0 00116180 */  sll   $t4, $s1, 6
/* 04C7A4 7F019DB4 02402025 */  move  $a0, $s2
/* 04C7A8 7F019DB8 8DB8000C */  lw    $t8, 0xc($t5)
/* 04C7AC 7F019DBC 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 04C7B0 7F019DC0 030C2821 */   addu  $a1, $t8, $t4
/* 04C7B4 7F019DC4 8E820000 */  lw    $v0, ($s4)
/* 04C7B8 7F019DC8 26310001 */  addiu $s1, $s1, 1
/* 04C7BC 7F019DCC 26100040 */  addiu $s0, $s0, 0x40
/* 04C7C0 7F019DD0 8C590008 */  lw    $t9, 8($v0)
/* 04C7C4 7F019DD4 872B000E */  lh    $t3, 0xe($t9)
/* 04C7C8 7F019DD8 022B082A */  slt   $at, $s1, $t3
/* 04C7CC 7F019DDC 5420FFF0 */  bnezl $at, .L7F019DA0
/* 04C7D0 7F019DE0 8C4F000C */   lw    $t7, 0xc($v0)
.L7F019DE4:
/* 04C7D4 7F019DE4 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C7D8 7F019DE8 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C7DC 7F019DEC 50E0001C */  beql  $a3, $zero, .L7F019E60
/* 04C7E0 7F019DF0 02601025 */   move  $v0, $s3
/* 04C7E4 7F019DF4 8CEE0008 */  lw    $t6, 8($a3)
/* 04C7E8 7F019DF8 00008825 */  move  $s1, $zero
/* 04C7EC 7F019DFC 00008025 */  move  $s0, $zero
/* 04C7F0 7F019E00 85CF000E */  lh    $t7, 0xe($t6)
/* 04C7F4 7F019E04 59E00016 */  blezl $t7, .L7F019E60
/* 04C7F8 7F019E08 02601025 */   move  $v0, $s3
/* 04C7FC 7F019E0C 8CED000C */  lw    $t5, 0xc($a3)
.L7F019E10:
/* 04C800 7F019E10 02402825 */  move  $a1, $s2
/* 04C804 7F019E14 0FC16132 */  jal   matrix_4x4_copy
/* 04C808 7F019E18 01B02021 */   addu  $a0, $t5, $s0
/* 04C80C 7F019E1C 3C188002 */  lui   $t8, %hi(cast_model_weapon) # $t8, 0x8002
/* 04C810 7F019E20 8F186B48 */  lw    $t8, %lo(cast_model_weapon)($t8)
/* 04C814 7F019E24 0011C980 */  sll   $t9, $s1, 6
/* 04C818 7F019E28 02402025 */  move  $a0, $s2
/* 04C81C 7F019E2C 8F0C000C */  lw    $t4, 0xc($t8)
/* 04C820 7F019E30 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 04C824 7F019E34 01992821 */   addu  $a1, $t4, $t9
/* 04C828 7F019E38 3C078002 */  lui   $a3, %hi(cast_model_weapon) # $a3, 0x8002
/* 04C82C 7F019E3C 8CE76B48 */  lw    $a3, %lo(cast_model_weapon)($a3)
/* 04C830 7F019E40 26310001 */  addiu $s1, $s1, 1
/* 04C834 7F019E44 26100040 */  addiu $s0, $s0, 0x40
/* 04C838 7F019E48 8CEB0008 */  lw    $t3, 8($a3)
/* 04C83C 7F019E4C 856E000E */  lh    $t6, 0xe($t3)
/* 04C840 7F019E50 022E082A */  slt   $at, $s1, $t6
/* 04C844 7F019E54 5420FFEE */  bnezl $at, .L7F019E10
/* 04C848 7F019E58 8CED000C */   lw    $t5, 0xc($a3)
/* 04C84C 7F019E5C 02601025 */  move  $v0, $s3
.L7F019E60:
/* 04C850 7F019E60 3C0D006E */  lui   $t5, (0x006E0528 >> 16) # lui $t5, 0x6e
/* 04C854 7F019E64 35AD0528 */  ori   $t5, (0x006E0528 & 0xFFFF) # ori $t5, $t5, 0x528
/* 04C858 7F019E68 3C0FED00 */  lui   $t7, 0xed00
/* 04C85C 7F019E6C AC4F0000 */  sw    $t7, ($v0)
/* 04C860 7F019E70 AC4D0004 */  sw    $t5, 4($v0)
/* 04C864 7F019E74 26730008 */  addiu $s3, $s3, 8
/* 04C868 7F019E78 3C07E700 */  lui   $a3, 0xe700
/* 04C86C 7F019E7C 26640008 */  addiu $a0, $s3, 8
/* 04C870 7F019E80 AE670000 */  sw    $a3, ($s3)
/* 04C874 7F019E84 AE600004 */  sw    $zero, 4($s3)
/* 04C878 7F019E88 3C18BA00 */  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
/* 04C87C 7F019E8C 37181402 */  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
/* 04C880 7F019E90 AC980000 */  sw    $t8, ($a0)
/* 04C884 7F019E94 AC800004 */  sw    $zero, 4($a0)
/* 04C888 7F019E98 24850008 */  addiu $a1, $a0, 8
/* 04C88C 7F019E9C 3C08BA00 */  lui   $t0, (0xBA000602 >> 16) # lui $t0, 0xba00
/* 04C890 7F019EA0 35080602 */  ori   $t0, (0xBA000602 & 0xFFFF) # ori $t0, $t0, 0x602
/* 04C894 7F019EA4 24A60008 */  addiu $a2, $a1, 8
/* 04C898 7F019EA8 240C00C0 */  li    $t4, 192
/* 04C89C 7F019EAC 3C09BA00 */  lui   $t1, (0xBA001301 >> 16) # lui $t1, 0xba00
/* 04C8A0 7F019EB0 ACAC0004 */  sw    $t4, 4($a1)
/* 04C8A4 7F019EB4 ACA80000 */  sw    $t0, ($a1)
/* 04C8A8 7F019EB8 35291301 */  ori   $t1, (0xBA001301 & 0xFFFF) # ori $t1, $t1, 0x1301
/* 04C8AC 7F019EBC 24C20008 */  addiu $v0, $a2, 8
/* 04C8B0 7F019EC0 ACC90000 */  sw    $t1, ($a2)
/* 04C8B4 7F019EC4 ACC00004 */  sw    $zero, 4($a2)
/* 04C8B8 7F019EC8 3C19B900 */  lui   $t9, (0xB9000002 >> 16) # lui $t9, 0xb900
/* 04C8BC 7F019ECC 37390002 */  ori   $t9, (0xB9000002 & 0xFFFF) # ori $t9, $t9, 2
/* 04C8C0 7F019ED0 24430008 */  addiu $v1, $v0, 8
/* 04C8C4 7F019ED4 3C0ABA00 */  lui   $t2, (0xBA001001 >> 16) # lui $t2, 0xba00
/* 04C8C8 7F019ED8 AC590000 */  sw    $t9, ($v0)
/* 04C8CC 7F019EDC AC400004 */  sw    $zero, 4($v0)
/* 04C8D0 7F019EE0 354A1001 */  ori   $t2, (0xBA001001 & 0xFFFF) # ori $t2, $t2, 0x1001
/* 04C8D4 7F019EE4 24730008 */  addiu $s3, $v1, 8
/* 04C8D8 7F019EE8 AC6A0000 */  sw    $t2, ($v1)
/* 04C8DC 7F019EEC AC600004 */  sw    $zero, 4($v1)
/* 04C8E0 7F019EF0 02602025 */  move  $a0, $s3
/* 04C8E4 7F019EF4 3C0BBA00 */  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
/* 04C8E8 7F019EF8 356B0C02 */  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
/* 04C8EC 7F019EFC 240E2000 */  li    $t6, 8192
/* 04C8F0 7F019F00 AC8E0004 */  sw    $t6, 4($a0)
/* 04C8F4 7F019F04 AC8B0000 */  sw    $t3, ($a0)
/* 04C8F8 7F019F08 26650008 */  addiu $a1, $s3, 8
/* 04C8FC 7F019F0C 3C0FBA00 */  lui   $t7, (0xBA000903 >> 16) # lui $t7, 0xba00
/* 04C900 7F019F10 35EF0903 */  ori   $t7, (0xBA000903 & 0xFFFF) # ori $t7, $t7, 0x903
/* 04C904 7F019F14 ACAF0000 */  sw    $t7, ($a1)
/* 04C908 7F019F18 24A60008 */  addiu $a2, $a1, 8
/* 04C90C 7F019F1C 240D0C00 */  li    $t5, 3072
/* 04C910 7F019F20 ACAD0004 */  sw    $t5, 4($a1)
/* 04C914 7F019F24 3C18BA00 */  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
/* 04C918 7F019F28 37180E02 */  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
/* 04C91C 7F019F2C 24C20008 */  addiu $v0, $a2, 8
/* 04C920 7F019F30 ACD80000 */  sw    $t8, ($a2)
/* 04C924 7F019F34 ACC00004 */  sw    $zero, 4($a2)
/* 04C928 7F019F38 3C190050 */  lui   $t9, (0x00504340 >> 16) # lui $t9, 0x50
/* 04C92C 7F019F3C 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 04C930 7F019F40 358C031D */  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 04C934 7F019F44 37394340 */  ori   $t9, (0x00504340 & 0xFFFF) # ori $t9, $t9, 0x4340
/* 04C938 7F019F48 24430008 */  addiu $v1, $v0, 8
/* 04C93C 7F019F4C AC590004 */  sw    $t9, 4($v0)
/* 04C940 7F019F50 AC4C0000 */  sw    $t4, ($v0)
/* 04C944 7F019F54 3C0BFCFF */  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
/* 04C948 7F019F58 3C0EFFFD */  lui   $t6, (0xFFFDF6FB >> 16) # lui $t6, 0xfffd
/* 04C94C 7F019F5C 35CEF6FB */  ori   $t6, (0xFFFDF6FB & 0xFFFF) # ori $t6, $t6, 0xf6fb
/* 04C950 7F019F60 356BFFFF */  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
/* 04C954 7F019F64 AC6B0000 */  sw    $t3, ($v1)
/* 04C958 7F019F68 AC6E0004 */  sw    $t6, 4($v1)
/* 04C95C 7F019F6C 24640008 */  addiu $a0, $v1, 8
/* 04C960 7F019F70 3C0FFA00 */  lui   $t7, 0xfa00
/* 04C964 7F019F74 AC8F0000 */  sw    $t7, ($a0)
/* 04C968 7F019F78 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 04C96C 7F019F7C 44813000 */  mtc1  $at, $f6
/* 04C970 7F019F80 C7A80144 */  lwc1  $f8, 0x144($sp)
/* 04C974 7F019F84 240C00FF */  li    $t4, 255
/* 04C978 7F019F88 24930008 */  addiu $s3, $a0, 8
/* 04C97C 7F019F8C 46083002 */  mul.s $f0, $f6, $f8
/* 04C980 7F019F90 3C0EF66E */  lui   $t6, (0xF66E0528 >> 16) # lui $t6, 0xf66e
/* 04C984 7F019F94 35CE0528 */  ori   $t6, (0xF66E0528 & 0xFFFF) # ori $t6, $t6, 0x528
/* 04C988 7F019F98 26660008 */  addiu $a2, $s3, 8
/* 04C98C 7F019F9C 24C20008 */  addiu $v0, $a2, 8
/* 04C990 7F019FA0 24430008 */  addiu $v1, $v0, 8
/* 04C994 7F019FA4 240F0040 */  li    $t7, 64
/* 04C998 7F019FA8 4600028D */  trunc.w.s $f10, $f0
/* 04C99C 7F019FAC 3C0D0008 */  lui   $t5, 8
/* 04C9A0 7F019FB0 24650008 */  addiu $a1, $v1, 8
/* 04C9A4 7F019FB4 44185000 */  mfc1  $t8, $f10
/* 04C9A8 7F019FB8 00000000 */  nop
/* 04C9AC 7F019FBC 0198C823 */  subu  $t9, $t4, $t8
/* 04C9B0 7F019FC0 332B00FF */  andi  $t3, $t9, 0xff
/* 04C9B4 7F019FC4 AC8B0004 */  sw    $t3, 4($a0)
/* 04C9B8 7F019FC8 AE600004 */  sw    $zero, 4($s3)
/* 04C9BC 7F019FCC AE6E0000 */  sw    $t6, ($s3)
/* 04C9C0 7F019FD0 ACC00004 */  sw    $zero, 4($a2)
/* 04C9C4 7F019FD4 ACC70000 */  sw    $a3, ($a2)
/* 04C9C8 7F019FD8 AC4F0004 */  sw    $t7, 4($v0)
/* 04C9CC 7F019FDC AC480000 */  sw    $t0, ($v0)
/* 04C9D0 7F019FE0 AC6D0004 */  sw    $t5, 4($v1)
/* 04C9D4 7F019FE4 AC690000 */  sw    $t1, ($v1)
/* 04C9D8 7F019FE8 3C0C0001 */  lui   $t4, 1
/* 04C9DC 7F019FEC ACAC0004 */  sw    $t4, 4($a1)
/* 04C9E0 7F019FF0 ACAA0000 */  sw    $t2, ($a1)
/* 04C9E4 7F019FF4 24A40008 */  addiu $a0, $a1, 8
/* 04C9E8 7F019FF8 0FC2B016 */  jal   microcode_constructor
/* 04C9EC 7F019FFC E7A00070 */   swc1  $f0, 0x70($sp)
/* 04C9F0 7F01A000 3C188002 */  lui   $t8, %hi(full_actor_intro) # $t8, 0x8002
/* 04C9F4 7F01A004 8F186B4C */  lw    $t8, %lo(full_actor_intro)($t8)
/* 04C9F8 7F01A008 00409825 */  move  $s3, $v0
/* 04C9FC 7F01A00C 1700005F */  bnez  $t8, .L7F01A18C
/* 04CA00 7F01A010 3C198002 */   lui   $t9, %hi(intro_character_index) # $t9, 0x8002
/* 04CA04 7F01A014 8F396B38 */  lw    $t9, %lo(intro_character_index)($t9)
/* 04CA08 7F01A018 3C048002 */  lui   $a0, %hi(intro_char_table+8)
/* 04CA0C 7F01A01C 00195880 */  sll   $t3, $t9, 2
/* 04CA10 7F01A020 01795821 */  addu  $t3, $t3, $t9
/* 04CA14 7F01A024 000B5880 */  sll   $t3, $t3, 2
/* 04CA18 7F01A028 008B2021 */  addu  $a0, $a0, $t3
/* 04CA1C 7F01A02C 0FC304AE */  jal   langGet
/* 04CA20 7F01A030 94846B58 */   lhu   $a0, %lo(intro_char_table+8)($a0)
/* 04CA24 7F01A034 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBold) # $t6, 0x8004
/* 04CA28 7F01A038 8DCEAB04 */  lw    $t6, %lo(ptrFontZurichBold)($t6)
/* 04CA2C 7F01A03C 3C148004 */  lui   $s4, %hi(ptrFontZurichBoldChars) # $s4, 0x8004
/* 04CA30 7F01A040 2694AB08 */  addiu $s4, %lo(ptrFontZurichBoldChars) # addiu $s4, $s4, -0x54f8
/* 04CA34 7F01A044 00408825 */  move  $s1, $v0
/* 04CA38 7F01A048 8E870000 */  lw    $a3, ($s4)
/* 04CA3C 7F01A04C 27A40150 */  addiu $a0, $sp, 0x150
/* 04CA40 7F01A050 27A50154 */  addiu $a1, $sp, 0x154
/* 04CA44 7F01A054 00403025 */  move  $a2, $v0
/* 04CA48 7F01A058 AFA00014 */  sw    $zero, 0x14($sp)
/* 04CA4C 7F01A05C 0FC2B713 */  jal   textMeasure
/* 04CA50 7F01A060 AFAE0010 */   sw    $t6, 0x10($sp)
/* 04CA54 7F01A064 8FA20154 */  lw    $v0, 0x154($sp)
/* 04CA58 7F01A068 8FB80150 */  lw    $t8, 0x150($sp)
/* 04CA5C 7F01A06C 240D013B */  li    $t5, 315
/* 04CA60 7F01A070 04410003 */  bgez  $v0, .L7F01A080
/* 04CA64 7F01A074 00027843 */   sra   $t7, $v0, 1
/* 04CA68 7F01A078 24410001 */  addiu $at, $v0, 1
/* 04CA6C 7F01A07C 00017843 */  sra   $t7, $at, 1
.L7F01A080:
/* 04CA70 7F01A080 01AF2823 */  subu  $a1, $t5, $t7
/* 04CA74 7F01A084 240C006C */  li    $t4, 108
/* 04CA78 7F01A088 00A23821 */  addu  $a3, $a1, $v0
/* 04CA7C 7F01A08C 2719006D */  addiu $t9, $t8, 0x6d
/* 04CA80 7F01A090 AFAC0158 */  sw    $t4, 0x158($sp)
/* 04CA84 7F01A094 AFB90010 */  sw    $t9, 0x10($sp)
/* 04CA88 7F01A098 24E70001 */  addiu $a3, $a3, 1
/* 04CA8C 7F01A09C AFA5015C */  sw    $a1, 0x15c($sp)
/* 04CA90 7F01A0A0 02602025 */  move  $a0, $s3
/* 04CA94 7F01A0A4 2406006C */  li    $a2, 108
/* 04CA98 7F01A0A8 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 04CA9C 7F01A0AC AFA00014 */   sw    $zero, 0x14($sp)
/* 04CAA0 7F01A0B0 0C000F9B */  jal   viGetX
/* 04CAA4 7F01A0B4 00409825 */   move  $s3, $v0
/* 04CAA8 7F01A0B8 00028400 */  sll   $s0, $v0, 0x10
/* 04CAAC 7F01A0BC 00105C03 */  sra   $t3, $s0, 0x10
/* 04CAB0 7F01A0C0 0C000F9F */  jal   viGetY
/* 04CAB4 7F01A0C4 01608025 */   move  $s0, $t3
/* 04CAB8 7F01A0C8 444FF800 */  cfc1  $t7, $31
/* 04CABC 7F01A0CC 240C0001 */  li    $t4, 1
/* 04CAC0 7F01A0D0 44CCF800 */  ctc1  $t4, $31
/* 04CAC4 7F01A0D4 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 04CAC8 7F01A0D8 3C0D8004 */  lui   $t5, %hi(ptrFontZurichBold) # $t5, 0x8004
/* 04CACC 7F01A0DC 8DADAB04 */  lw    $t5, %lo(ptrFontZurichBold)($t5)
/* 04CAD0 7F01A0E0 460021A4 */  cvt.w.s $f6, $f4
/* 04CAD4 7F01A0E4 8E8E0000 */  lw    $t6, ($s4)
/* 04CAD8 7F01A0E8 02602025 */  move  $a0, $s3
/* 04CADC 7F01A0EC 27A5015C */  addiu $a1, $sp, 0x15c
/* 04CAE0 7F01A0F0 444CF800 */  cfc1  $t4, $31
/* 04CAE4 7F01A0F4 27A60158 */  addiu $a2, $sp, 0x158
/* 04CAE8 7F01A0F8 02203825 */  move  $a3, $s1
/* 04CAEC 7F01A0FC 318C0078 */  andi  $t4, $t4, 0x78
/* 04CAF0 7F01A100 AFAD0014 */  sw    $t5, 0x14($sp)
/* 04CAF4 7F01A104 11800013 */  beqz  $t4, .L7F01A154
/* 04CAF8 7F01A108 AFAE0010 */   sw    $t6, 0x10($sp)
/* 04CAFC 7F01A10C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 04CB00 7F01A110 44813000 */  mtc1  $at, $f6
/* 04CB04 7F01A114 240C0001 */  li    $t4, 1
/* 04CB08 7F01A118 46062181 */  sub.s $f6, $f4, $f6
/* 04CB0C 7F01A11C 44CCF800 */  ctc1  $t4, $31
/* 04CB10 7F01A120 00000000 */  nop
/* 04CB14 7F01A124 460031A4 */  cvt.w.s $f6, $f6
/* 04CB18 7F01A128 444CF800 */  cfc1  $t4, $31
/* 04CB1C 7F01A12C 00000000 */  nop
/* 04CB20 7F01A130 318C0078 */  andi  $t4, $t4, 0x78
/* 04CB24 7F01A134 15800005 */  bnez  $t4, .L7F01A14C
/* 04CB28 7F01A138 00000000 */   nop
/* 04CB2C 7F01A13C 440C3000 */  mfc1  $t4, $f6
/* 04CB30 7F01A140 3C018000 */  lui   $at, 0x8000
/* 04CB34 7F01A144 10000007 */  b     .L7F01A164
/* 04CB38 7F01A148 01816025 */   or    $t4, $t4, $at
.L7F01A14C:
/* 04CB3C 7F01A14C 10000005 */  b     .L7F01A164
/* 04CB40 7F01A150 240CFFFF */   li    $t4, -1
.L7F01A154:
/* 04CB44 7F01A154 440C3000 */  mfc1  $t4, $f6
/* 04CB48 7F01A158 00000000 */  nop
/* 04CB4C 7F01A15C 0580FFFB */  bltz  $t4, .L7F01A14C
/* 04CB50 7F01A160 00000000 */   nop
.L7F01A164:
/* 04CB54 7F01A164 2401FF00 */  li    $at, -256
/* 04CB58 7F01A168 0181C025 */  or    $t8, $t4, $at
/* 04CB5C 7F01A16C 44CFF800 */  ctc1  $t7, $31
/* 04CB60 7F01A170 AFB80018 */  sw    $t8, 0x18($sp)
/* 04CB64 7F01A174 AFB0001C */  sw    $s0, 0x1c($sp)
/* 04CB68 7F01A178 AFA20020 */  sw    $v0, 0x20($sp)
/* 04CB6C 7F01A17C AFA00024 */  sw    $zero, 0x24($sp)
/* 04CB70 7F01A180 0FC2B35F */  jal   textRender
/* 04CB74 7F01A184 AFA00028 */   sw    $zero, 0x28($sp)
/* 04CB78 7F01A188 00409825 */  move  $s3, $v0
.L7F01A18C:
/* 04CB7C 7F01A18C 444EF800 */  cfc1  $t6, $31
/* 04CB80 7F01A190 24120001 */  li    $s2, 1
/* 04CB84 7F01A194 44D2F800 */  ctc1  $s2, $31
/* 04CB88 7F01A198 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 04CB8C 7F01A19C 3C198002 */  lui   $t9, %hi(intro_character_index) # $t9, 0x8002
/* 04CB90 7F01A1A0 8F396B38 */  lw    $t9, %lo(intro_character_index)($t9)
/* 04CB94 7F01A1A4 460042A4 */  cvt.w.s $f10, $f8
/* 04CB98 7F01A1A8 3C048002 */  lui   $a0, %hi(intro_char_table+10)
/* 04CB9C 7F01A1AC 00195880 */  sll   $t3, $t9, 2
/* 04CBA0 7F01A1B0 01795821 */  addu  $t3, $t3, $t9
/* 04CBA4 7F01A1B4 4452F800 */  cfc1  $s2, $31
/* 04CBA8 7F01A1B8 000B5880 */  sll   $t3, $t3, 2
/* 04CBAC 7F01A1BC 3C148004 */  lui   $s4, %hi(ptrFontZurichBoldChars) # $s4, 0x8004
/* 04CBB0 7F01A1C0 008B2021 */  addu  $a0, $a0, $t3
/* 04CBB4 7F01A1C4 32520078 */  andi  $s2, $s2, 0x78
/* 04CBB8 7F01A1C8 2694AB08 */  addiu $s4, %lo(ptrFontZurichBoldChars) # addiu $s4, $s4, -0x54f8
/* 04CBBC 7F01A1CC 12400013 */  beqz  $s2, .L7F01A21C
/* 04CBC0 7F01A1D0 94846B5A */   lhu   $a0, %lo(intro_char_table+10)($a0)
/* 04CBC4 7F01A1D4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 04CBC8 7F01A1D8 44815000 */  mtc1  $at, $f10
/* 04CBCC 7F01A1DC 24120001 */  li    $s2, 1
/* 04CBD0 7F01A1E0 460A4281 */  sub.s $f10, $f8, $f10
/* 04CBD4 7F01A1E4 44D2F800 */  ctc1  $s2, $31
/* 04CBD8 7F01A1E8 00000000 */  nop
/* 04CBDC 7F01A1EC 460052A4 */  cvt.w.s $f10, $f10
/* 04CBE0 7F01A1F0 4452F800 */  cfc1  $s2, $31
/* 04CBE4 7F01A1F4 00000000 */  nop
/* 04CBE8 7F01A1F8 32520078 */  andi  $s2, $s2, 0x78
/* 04CBEC 7F01A1FC 16400005 */  bnez  $s2, .L7F01A214
/* 04CBF0 7F01A200 00000000 */   nop
/* 04CBF4 7F01A204 44125000 */  mfc1  $s2, $f10
/* 04CBF8 7F01A208 3C018000 */  lui   $at, 0x8000
/* 04CBFC 7F01A20C 10000007 */  b     .L7F01A22C
/* 04CC00 7F01A210 02419025 */   or    $s2, $s2, $at
.L7F01A214:
/* 04CC04 7F01A214 10000005 */  b     .L7F01A22C
/* 04CC08 7F01A218 2412FFFF */   li    $s2, -1
.L7F01A21C:
/* 04CC0C 7F01A21C 44125000 */  mfc1  $s2, $f10
/* 04CC10 7F01A220 00000000 */  nop
/* 04CC14 7F01A224 0640FFFB */  bltz  $s2, .L7F01A214
/* 04CC18 7F01A228 00000000 */   nop
.L7F01A22C:
/* 04CC1C 7F01A22C 2401FF00 */  li    $at, -256
/* 04CC20 7F01A230 02416825 */  or    $t5, $s2, $at
/* 04CC24 7F01A234 44CEF800 */  ctc1  $t6, $31
/* 04CC28 7F01A238 0FC304AE */  jal   langGet
/* 04CC2C 7F01A23C 01A09025 */   move  $s2, $t5
/* 04CC30 7F01A240 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBold) # $t7, 0x8004
/* 04CC34 7F01A244 8DEFAB04 */  lw    $t7, %lo(ptrFontZurichBold)($t7)
/* 04CC38 7F01A248 00408825 */  move  $s1, $v0
/* 04CC3C 7F01A24C 27A40150 */  addiu $a0, $sp, 0x150
/* 04CC40 7F01A250 27A50154 */  addiu $a1, $sp, 0x154
/* 04CC44 7F01A254 00403025 */  move  $a2, $v0
/* 04CC48 7F01A258 8E870000 */  lw    $a3, ($s4)
/* 04CC4C 7F01A25C AFA00014 */  sw    $zero, 0x14($sp)
/* 04CC50 7F01A260 0FC2B713 */  jal   textMeasure
/* 04CC54 7F01A264 AFAF0010 */   sw    $t7, 0x10($sp)
/* 04CC58 7F01A268 8FA20154 */  lw    $v0, 0x154($sp)
/* 04CC5C 7F01A26C 8FAB0150 */  lw    $t3, 0x150($sp)
/* 04CC60 7F01A270 2418013B */  li    $t8, 315
/* 04CC64 7F01A274 04410003 */  bgez  $v0, .L7F01A284
/* 04CC68 7F01A278 00026043 */   sra   $t4, $v0, 1
/* 04CC6C 7F01A27C 24410001 */  addiu $at, $v0, 1
/* 04CC70 7F01A280 00016043 */  sra   $t4, $at, 1
.L7F01A284:
/* 04CC74 7F01A284 030C2823 */  subu  $a1, $t8, $t4
/* 04CC78 7F01A288 24190098 */  li    $t9, 152
/* 04CC7C 7F01A28C 00A23821 */  addu  $a3, $a1, $v0
/* 04CC80 7F01A290 256E0099 */  addiu $t6, $t3, 0x99
/* 04CC84 7F01A294 AFB90158 */  sw    $t9, 0x158($sp)
/* 04CC88 7F01A298 AFAE0010 */  sw    $t6, 0x10($sp)
/* 04CC8C 7F01A29C 24E70001 */  addiu $a3, $a3, 1
/* 04CC90 7F01A2A0 AFA5015C */  sw    $a1, 0x15c($sp)
/* 04CC94 7F01A2A4 02602025 */  move  $a0, $s3
/* 04CC98 7F01A2A8 24060098 */  li    $a2, 152
/* 04CC9C 7F01A2AC 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 04CCA0 7F01A2B0 AFA00014 */   sw    $zero, 0x14($sp)
/* 04CCA4 7F01A2B4 0C000F9B */  jal   viGetX
/* 04CCA8 7F01A2B8 00409825 */   move  $s3, $v0
/* 04CCAC 7F01A2BC 00028400 */  sll   $s0, $v0, 0x10
/* 04CCB0 7F01A2C0 00106C03 */  sra   $t5, $s0, 0x10
/* 04CCB4 7F01A2C4 0C000F9F */  jal   viGetY
/* 04CCB8 7F01A2C8 01A08025 */   move  $s0, $t5
/* 04CCBC 7F01A2CC 3C188004 */  lui   $t8, %hi(ptrFontZurichBold) # $t8, 0x8004
/* 04CCC0 7F01A2D0 8F18AB04 */  lw    $t8, %lo(ptrFontZurichBold)($t8)
/* 04CCC4 7F01A2D4 8E8F0000 */  lw    $t7, ($s4)
/* 04CCC8 7F01A2D8 02602025 */  move  $a0, $s3
/* 04CCCC 7F01A2DC 27A5015C */  addiu $a1, $sp, 0x15c
/* 04CCD0 7F01A2E0 27A60158 */  addiu $a2, $sp, 0x158
/* 04CCD4 7F01A2E4 02203825 */  move  $a3, $s1
/* 04CCD8 7F01A2E8 AFB20018 */  sw    $s2, 0x18($sp)
/* 04CCDC 7F01A2EC AFB0001C */  sw    $s0, 0x1c($sp)
/* 04CCE0 7F01A2F0 AFA20020 */  sw    $v0, 0x20($sp)
/* 04CCE4 7F01A2F4 AFA00024 */  sw    $zero, 0x24($sp)
/* 04CCE8 7F01A2F8 AFA00028 */  sw    $zero, 0x28($sp)
/* 04CCEC 7F01A2FC AFB80014 */  sw    $t8, 0x14($sp)
/* 04CCF0 7F01A300 0FC2B35F */  jal   textRender
/* 04CCF4 7F01A304 AFAF0010 */   sw    $t7, 0x10($sp)
/* 04CCF8 7F01A308 3C0C8002 */  lui   $t4, %hi(intro_character_index) # $t4, 0x8002
/* 04CCFC 7F01A30C 8D8C6B38 */  lw    $t4, %lo(intro_character_index)($t4)
/* 04CD00 7F01A310 3C048002 */  lui   $a0, %hi(intro_char_table+12)
/* 04CD04 7F01A314 00409825 */  move  $s3, $v0
/* 04CD08 7F01A318 000CC880 */  sll   $t9, $t4, 2
/* 04CD0C 7F01A31C 032CC821 */  addu  $t9, $t9, $t4
/* 04CD10 7F01A320 0019C880 */  sll   $t9, $t9, 2
/* 04CD14 7F01A324 00992021 */  addu  $a0, $a0, $t9
/* 04CD18 7F01A328 0FC304AE */  jal   langGet
/* 04CD1C 7F01A32C 94846B5C */   lhu   $a0, %lo(intro_char_table+12)($a0)
/* 04CD20 7F01A330 3C0B8004 */  lui   $t3, %hi(ptrFontZurichBold) # $t3, 0x8004
/* 04CD24 7F01A334 8D6BAB04 */  lw    $t3, %lo(ptrFontZurichBold)($t3)
/* 04CD28 7F01A338 00408825 */  move  $s1, $v0
/* 04CD2C 7F01A33C 27A40150 */  addiu $a0, $sp, 0x150
/* 04CD30 7F01A340 27A50154 */  addiu $a1, $sp, 0x154
/* 04CD34 7F01A344 00403025 */  move  $a2, $v0
/* 04CD38 7F01A348 8E870000 */  lw    $a3, ($s4)
/* 04CD3C 7F01A34C AFA00014 */  sw    $zero, 0x14($sp)
/* 04CD40 7F01A350 0FC2B713 */  jal   textMeasure
/* 04CD44 7F01A354 AFAB0010 */   sw    $t3, 0x10($sp)
/* 04CD48 7F01A358 8FA20154 */  lw    $v0, 0x154($sp)
/* 04CD4C 7F01A35C 8FB80150 */  lw    $t8, 0x150($sp)
/* 04CD50 7F01A360 240D013B */  li    $t5, 315
/* 04CD54 7F01A364 04410003 */  bgez  $v0, .L7F01A374
/* 04CD58 7F01A368 00027043 */   sra   $t6, $v0, 1
/* 04CD5C 7F01A36C 24410001 */  addiu $at, $v0, 1
/* 04CD60 7F01A370 00017043 */  sra   $t6, $at, 1
.L7F01A374:
/* 04CD64 7F01A374 01AE2823 */  subu  $a1, $t5, $t6
/* 04CD68 7F01A378 240F00AE */  li    $t7, 174
/* 04CD6C 7F01A37C 00A23821 */  addu  $a3, $a1, $v0
/* 04CD70 7F01A380 270C00AF */  addiu $t4, $t8, 0xaf
/* 04CD74 7F01A384 AFAF0158 */  sw    $t7, 0x158($sp)
/* 04CD78 7F01A388 AFAC0010 */  sw    $t4, 0x10($sp)
/* 04CD7C 7F01A38C 24E70001 */  addiu $a3, $a3, 1
/* 04CD80 7F01A390 AFA5015C */  sw    $a1, 0x15c($sp)
/* 04CD84 7F01A394 02602025 */  move  $a0, $s3
/* 04CD88 7F01A398 240600AE */  li    $a2, 174
/* 04CD8C 7F01A39C 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 04CD90 7F01A3A0 AFA00014 */   sw    $zero, 0x14($sp)
/* 04CD94 7F01A3A4 0C000F9B */  jal   viGetX
/* 04CD98 7F01A3A8 00409825 */   move  $s3, $v0
/* 04CD9C 7F01A3AC 00028400 */  sll   $s0, $v0, 0x10
/* 04CDA0 7F01A3B0 0010CC03 */  sra   $t9, $s0, 0x10
/* 04CDA4 7F01A3B4 0C000F9F */  jal   viGetY
/* 04CDA8 7F01A3B8 03208025 */   move  $s0, $t9
/* 04CDAC 7F01A3BC 3C0D8004 */  lui   $t5, %hi(ptrFontZurichBold) # $t5, 0x8004
/* 04CDB0 7F01A3C0 8DADAB04 */  lw    $t5, %lo(ptrFontZurichBold)($t5)
/* 04CDB4 7F01A3C4 8E8B0000 */  lw    $t3, ($s4)
/* 04CDB8 7F01A3C8 02602025 */  move  $a0, $s3
/* 04CDBC 7F01A3CC 27A5015C */  addiu $a1, $sp, 0x15c
/* 04CDC0 7F01A3D0 27A60158 */  addiu $a2, $sp, 0x158
/* 04CDC4 7F01A3D4 02203825 */  move  $a3, $s1
/* 04CDC8 7F01A3D8 AFB20018 */  sw    $s2, 0x18($sp)
/* 04CDCC 7F01A3DC AFB0001C */  sw    $s0, 0x1c($sp)
/* 04CDD0 7F01A3E0 AFA20020 */  sw    $v0, 0x20($sp)
/* 04CDD4 7F01A3E4 AFA00024 */  sw    $zero, 0x24($sp)
/* 04CDD8 7F01A3E8 AFA00028 */  sw    $zero, 0x28($sp)
/* 04CDDC 7F01A3EC AFAD0014 */  sw    $t5, 0x14($sp)
/* 04CDE0 7F01A3F0 0FC2B35F */  jal   textRender
/* 04CDE4 7F01A3F4 AFAB0010 */   sw    $t3, 0x10($sp)
/* 04CDE8 7F01A3F8 8FBF004C */  lw    $ra, 0x4c($sp)
/* 04CDEC 7F01A3FC 8FB00038 */  lw    $s0, 0x38($sp)
/* 04CDF0 7F01A400 8FB1003C */  lw    $s1, 0x3c($sp)
/* 04CDF4 7F01A404 8FB20040 */  lw    $s2, 0x40($sp)
/* 04CDF8 7F01A408 8FB30044 */  lw    $s3, 0x44($sp)
/* 04CDFC 7F01A40C 8FB40048 */  lw    $s4, 0x48($sp)
/* 04CE00 7F01A410 03E00008 */  jr    $ra
/* 04CE04 7F01A414 27BD0250 */   addiu $sp, $sp, 0x250
)
#endif
#endif



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


void update_menu19_spectrum(void) {
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
    DL = insert_imageDL(DL);

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
            case MENU_EYE_INTRO:              update_menu_03_eye();                 break;
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
            case MENU_EYE_INTRO:              init_menu03_eyeintro();               break;
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
            else if (selected_stage == LEVELID_CUBA)
            {
                do_extended_cast_display(1);
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


