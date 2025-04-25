// gcc -o build/aiparse tools/aiParse.c
// ./build/aiparse
//#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define _LANGUAGE_C
#define TARGET_N64
#include "../include/PR/ultratypes.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#pragma GCC diagnostic ignored "-Wformat="

//odd, I though this would differ on L-Endian
// Ahh, figured it out, this "makes" a number and the cpu stores it in a reg in its own endianness
#    define CharArrayTo16(val, index) (                                              val[index + 1]      | val[index] << 8)
#    define CharArrayTo24(val, index) (                       val[index + 1] << 8  | val[index + 2]      | val[index] << 16)
#    define CharArrayTo32(val, index) (val[index + 1] << 16 | val[index + 2] << 8  | val[index + 3]      | val[index] << 24)

#define ntohl(var)          CharArrayTo32(((unsigned char *)(&(var))), 0)
#define ntohs(var)          CharArrayTo16(((unsigned char *)(&(var))), 0)
#define btol(var)           *(unsigned int *)&(var) = ntohl(var)
#define btos(var)           *(unsigned int *)&(var) = ntohs(var)

#define isNotBoundPad(pad)  pad < 10000
#define getBoundPadNum(pad) pad - 10000
#define setBoundPadNum(pad) pad + 10000

#define M_TAU_F            6.2831855f
#define ByteToRadian(Byte) ((Byte * M_TAU_F) * (1.0f / 256.0f))
#define RadToDeg(RAD)      (float)((RAD) / M_TAU_F * 360.0f)

#define TARGET_BOND         0x0001 /* Set target to bond (ignores target argument)*/
#define TARGET_FRONT_OF_CHR 0x0002 /* Set target to front of chr*/
#define TARGET_CHR          0x0004 /* Set target type to chr_num*/
#define TARGET_PAD          0x0008 /* Set target type to pad*/
#define TARGET_COMPASS      0x0010 /* Set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000*/
#define TARGET_AIM_ONLY     0x0020 /* Aim at target instead of firing*/
#define TARGET_DONTTURN     0x0040 /* Limits target to 180 degrees in front of guard (cannot be used with TARGET_BOND flag)*/

char *HITTARGET_ToString[] = {
    "HIT_NULL_PART",         /* Null part, no reaction - 1x damage*/
    "HIT_LEFT_FOOT",         /* Left foot              - 1x damage*/
    "HIT_LEFT_LEG",          /* Left leg               - 1x damage*/
    "HIT_LEFT_THIGH",        /* Left thigh             - 1x damage*/
    "HIT_RIGHT_FOOT",        /* Right foot             - 1x damage*/
    "HIT_RIGHT_LEG",         /* Right leg              - 1x damage*/
    "HIT_RIGHT_THIGH",       /* Right thigh            - 1x damage*/
    "HIT_PELVIS",            /* Pelvis                 - 1x damage*/
    "HIT_HEAD",              /* Head                   - 4x damage*/
    "HIT_LEFT_HAND",         /* Left hand              - 1x damage*/
    "HIT_LEFT_ARM",          /* Left arm               - 1x damage*/
    "HIT_LEFT_SHOULDER",     /* Left shoulder          - 1x damage*/
    "HIT_RIGHT_HAND",        /* Right hand             - 1x damage*/
    "HIT_RIGHT_ARM",         /* Right arm              - 1x damage*/
    "HIT_RIGHT_SHOULDER",    /* Right shoulder         - 1x damage*/
    "HIT_CHEST",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "40",
    "41",
    "42",
    "43",
    "44",
    "45",
    "46",
    "47",
    "48",
    "49",
    "50",
    "51",
    "52",
    "53",
    "54",
    "55",
    "56",
    "57",
    "58",
    "59",
    "60",
    "61",
    "62",
    "63",
    "64",
    "65",
    "66",
    "67",
    "68",
    "69",
    "70",
    "71",
    "72",
    "73",
    "74",
    "75",
    "76",
    "77",
    "78",
    "79",
    "80",
    "81",
    "82",
    "83",
    "84",
    "85",
    "86",
    "87",
    "88",
    "89",
    "90",
    "91",
    "92",
    "93",
    "94",
    "95",
    "96",
    "97",
    "98",
    "99",
    "HIT_GUN",               /* GUN                    - 0x damage*/
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "107",
    "108",
    "109",
    "HIT_HAT",               /* HAT                    - 0x damage*/
    "111",
    "112",
    "113",
    "114",
    "115",
    "116",
    "117",
    "118",
    "119",
    "120",
    "121",
    "122",
    "123",
    "124",
    "125",
    "126",
    "127",
    "128",
    "129",
    "130",
    "131",
    "132",
    "133",
    "134",
    "135",
    "136",
    "137",
    "138",
    "139",
    "140",
    "141",
    "142",
    "143",
    "144",
    "145",
    "146",
    "147",
    "148",
    "149",
    "150",
    "151",
    "152",
    "153",
    "154",
    "155",
    "156",
    "157",
    "158",
    "159",
    "160",
    "161",
    "162",
    "163",
    "164",
    "165",
    "166",
    "167",
    "168",
    "169",
    "170",
    "171",
    "172",
    "173",
    "174",
    "175",
    "176",
    "177",
    "178",
    "179",
    "180",
    "181",
    "182",
    "183",
    "184",
    "185",
    "186",
    "187",
    "188",
    "189",
    "190",
    "191",
    "192",
    "193",
    "194",
    "195",
    "196",
    "197",
    "198",
    "199",
    "HIT_GENERAL",
    "HIT_GENERALHALF"};

    // command 68 - door states
char *DOORSTATE_ToString[] = {
    " AI_DOOR_STATE_CLOSED",  /* Closed*/
    " AI_DOOR_STATE_OPEN",    /* Opened*/
    " AI_DOOR_STATE_CLOSING", /* Closing*/
    " AI_DOOR_STATE_OPENING" /* Opening*/};

// command D7 - hud flags
#define HUD_HIDE_ALL           0x00 /* Hide all*/
#define HUD_SHOW_TEXT_TOP      0x01 /* Don't hide top text*/
#define HUD_SHOW_TEXT_BOTTOM   0x02 /* Don't hide bottom text*/
#define HUD_SHOW_HUD_COUNTDOWN 0x04 /* Don't hide hud countdown*/

/* special chr num IDs */
#define CHR_BOND_CINEMA -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE       -7
#define CHR_SEE_SHOT    -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE     -5 /* stored as chr->chrseedie */
#define CHR_PRESET      -4 /* stored as chr->chrpreset1 */
#define CHR_SELF        -3

/* private chr ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE        -2    /* objective ai list chr ID */
#define CHR_FREE             -1    /* chr IDs when free'd (killed or removed from level) */

char *CHR_ToString[] = {
    "",
    "CHR_FREE",
    "CHR_OBJECTIVE",
    "CHR_SELF",
    "CHR_PRESET",
    "CHR_SEE_DIE",
    "CHR_SEE_SHOT",
    "CHR_CLONE",
    "CHR_BOND_CINEMA"
};


#define CHR_SPAWN_NUM_START  5000  /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START 10000 /* default chr num for cloned guards with ai command C1 */
/* Special ID for selecting PadPreset in AI list */
#define PAD_PRESET1          9000 /* stored as chr->padpreset1 */

#define isGlobalAIListID(ID)  ((ID) <= 1024)
#define isBGAIListID(ID)      ((ID) >= 4096)
#define isChrAIListID(ID)     (!isGlobalAIListID(ID) && !isBGAIListID(ID))
#define setGlobalAIListID(ID) ((ID) + 0)
#define setChrAIListID(ID)    ((ID) + 1025)
#define setBGAIListID(ID)     ((ID) + 4096)
#define getGlobalAIListID(ID) ((ID)-0)
#define getChrAIListID(ID)    ((ID)-1025)
#define getBGAIListID(ID)     ((ID)-4096)

char *ANIMATIONS_ToString[] = {
    "ANIM_idle",
    "ANIM_fire_standing",
    "ANIM_fire_standing_fast",
    "ANIM_fire_hip",
    "ANIM_fire_shoulder_left",
    "ANIM_fire_turn_right1",
    "ANIM_fire_turn_right2",
    "ANIM_fire_kneel_right_leg",
    "ANIM_fire_kneel_left_leg",
    "ANIM_fire_kneel_left",
    "ANIM_fire_kneel_right",
    "ANIM_fire_roll_left",
    "ANIM_fire_roll_right1",
    "ANIM_fire_roll_left_fast",
    "ANIM_hit_left_shoulder",
    "ANIM_hit_right_shoulder",
    "ANIM_hit_left_arm",
    "ANIM_hit_right_arm",
    "ANIM_hit_left_hand",
    "ANIM_hit_right_hand",
    "ANIM_hit_left_leg",
    "ANIM_hit_right_leg",
    "ANIM_death_genitalia", /* Thank you Mr. Botwood", here is your award */
    "ANIM_hit_neck",
    "ANIM_death_neck",
    "ANIM_death_stagger_back_to_wall",
    "ANIM_death_forward_face_down",
    "ANIM_death_forward_spin_face_up",
    "ANIM_death_backward_fall_face_up1",
    "ANIM_death_backward_spin_face_down_right",
    "ANIM_death_backward_spin_face_up_right",
    "ANIM_death_backward_spin_face_down_left",
    "ANIM_death_backward_spin_face_up_left",
    "ANIM_death_forward_face_down_hard",
    "ANIM_death_forward_face_down_soft",
    "ANIM_death_fetal_position_right",
    "ANIM_death_fetal_position_left",
    "ANIM_death_backward_fall_face_up2",
    "ANIM_side_step_left",
    "ANIM_fire_roll_right2",
    "ANIM_walking",
    "ANIM_sprinting",
    "ANIM_running",
    "ANIM_bond_eye_walk",
    "ANIM_bond_eye_fire",
    "ANIM_bond_watch",
    "ANIM_surrendering_armed",
    "ANIM_surrendering_armed_drop_weapon",
    "ANIM_fire_walking",
    "ANIM_fire_running",
    "ANIM_null50", /* invalid slot */
    "ANIM_null51", /* invalid slot */
    "ANIM_fire_jump_to_side_left",
    "ANIM_fire_jump_to_side_right",
    "ANIM_hit_butt_long",
    "ANIM_hit_butt_short",
    "ANIM_death_head",
    "ANIM_death_left_leg",
    "ANIM_slide_right",
    "ANIM_slide_left",
    "ANIM_jump_backwards",
    "ANIM_extending_left_hand",
    "ANIM_fire_throw_grenade",
    "ANIM_spotting_bond", /* used by chr ai command guard_points_at_bond */
    "ANIM_look_around",   /* used by chr ai command GUARD_ANIM_LOOKS_AROUND_SELF */
    "ANIM_fire_standing_one_handed_weapon",
    "ANIM_fire_standing_draw_one_handed_weapon_fast",
    "ANIM_fire_standing_draw_one_handed_weapon_slow",
    "ANIM_fire_hip_one_handed_weapon_fast",
    "ANIM_fire_hip_one_handed_weapon_slow",
    "ANIM_fire_hip_forward_one_handed_weapon",
    "ANIM_fire_standing_right_one_handed_weapon",
    "ANIM_fire_step_right_one_handed_weapon",
    "ANIM_fire_standing_left_one_handed_weapon_slow",
    "ANIM_fire_standing_left_one_handed_weapon_fast",
    "ANIM_fire_kneel_forward_one_handed_weapon_slow",
    "ANIM_fire_kneel_forward_one_handed_weapon_fast",
    "ANIM_fire_kneel_right_one_handed_weapon_slow",
    "ANIM_fire_kneel_right_one_handed_weapon_fast",
    "ANIM_fire_kneel_left_one_handed_weapon_slow",
    "ANIM_fire_kneel_left_one_handed_weapon_fast",
    "ANIM_fire_kneel_left_one_handed_weapon",
    "ANIM_aim_walking_one_handed_weapon",
    "ANIM_aim_walking_left_one_handed_weapon",
    "ANIM_aim_walking_right_one_handed_weapon",
    "ANIM_aim_running_one_handed_weapon",
    "ANIM_aim_running_right_one_handed_weapon",
    "ANIM_aim_running_left_one_handed_weapon",
    "ANIM_aim_sprinting_one_handed_weapon",
    "ANIM_running_one_handed_weapon",
    "ANIM_sprinting_one_handed_weapon",
    "ANIM_null91", /* invalid slot */
    "ANIM_null92", /* invalid slot */
    "ANIM_null93", /* invalid slot */
    "ANIM_null94", /* invalid slot */
    "ANIM_null95", /* invalid slot */
    "ANIM_null96", /* invalid slot */
    "ANIM_draw_one_handed_weapon_and_look_around",
    "ANIM_draw_one_handed_weapon_and_stand_up",
    "ANIM_aim_one_handed_weapon_left_right",
    "ANIM_cock_one_handed_weapon_and_turn_around",
    "ANIM_holster_one_handed_weapon_and_cross_arms",
    "ANIM_cock_one_handed_weapon_turn_around_and_stand_up",
    "ANIM_draw_one_handed_weapon_and_turn_around",
    "ANIM_step_foward_and_hold_one_handed_weapon",
    "ANIM_holster_one_handed_weapon_and_adjust_suit",
    "ANIM_idle_unarmed",
    "ANIM_walking_unarmed",
    "ANIM_fire_walking_dual_wield",
    "ANIM_fire_walking_dual_wield_hands_crossed",
    "ANIM_fire_running_dual_wield",
    "ANIM_fire_running_dual_wield_hands_crossed",
    "ANIM_fire_sprinting_dual_wield",
    "ANIM_fire_sprinting_dual_wield_hands_crossed",
    "ANIM_walking_female",
    "ANIM_running_female",
    "ANIM_fire_kneel_dual_wield",
    "ANIM_fire_kneel_dual_wield_left",
    "ANIM_fire_kneel_dual_wield_right",
    "ANIM_fire_kneel_dual_wield_hands_crossed",
    "ANIM_fire_kneel_dual_wield_hands_crossed_left",
    "ANIM_fire_kneel_dual_wield_hands_crossed_right",
    "ANIM_fire_standing_dual_wield",
    "ANIM_fire_standing_dual_wield_left",
    "ANIM_fire_standing_dual_wield_right",
    "ANIM_fire_standing_dual_wield_hands_crossed_left",
    "ANIM_fire_standing_dual_wield_hands_crossed_right",
    "ANIM_fire_standing_aiming_down_sights",
    "ANIM_fire_kneel_aiming_down_sights",
    "ANIM_hit_taser", /* unused tazer boy hit reaction */
    "ANIM_death_explosion_forward",
    "ANIM_death_explosion_left1",
    "ANIM_death_explosion_back_left",
    "ANIM_death_explosion_back1",
    "ANIM_death_explosion_right",
    "ANIM_death_explosion_forward_right1",
    "ANIM_death_explosion_back2",
    "ANIM_death_explosion_forward_roll",
    "ANIM_death_explosion_forward_face_down",
    "ANIM_death_explosion_left2",
    "ANIM_death_explosion_forward_right2",
    "ANIM_death_explosion_forward_right2_alt", /* copy of right2 with different fall */
    "ANIM_death_explosion_forward_right3",
    "ANIM_null143", /* invalid slot */
    "ANIM_null144", /* invalid slot */
    "ANIM_null145", /* invalid slot */
    "ANIM_null146", /* invalid slot */
    "ANIM_running_hands_up",
    "ANIM_sprinting_hands_up",
    "ANIM_aim_and_blow_one_handed_weapon",
    "ANIM_aim_one_handed_weapon_left",
    "ANIM_aim_one_handed_weapon_right",
    "ANIM_conversation",
    "ANIM_drop_weapon_and_show_fight_stance", /* orthodox stance woo */
    "ANIM_yawning",
    "ANIM_swatting_flies",
    "ANIM_scratching_leg",
    "ANIM_scratching_butt",
    "ANIM_adjusting_crotch",
    "ANIM_sneeze",
    "ANIM_conversation_cleaned", /* cleaned up copy of "ANIM_conversation (compare left wrist) */
    "ANIM_conversation_listener",
    "ANIM_startled_and_looking_around",
    "ANIM_laughing_in_disbelief",
    "ANIM_surrendering_unarmed",
    "ANIM_coughing_standing",
    "ANIM_coughing_kneel1",
    "ANIM_coughing_kneel2",
    "ANIM_standing_up",
    "ANIM_null169", /* invalid slot */
    "ANIM_dancing",
    "ANIM_dancing_one_handed_weapon",
    "ANIM_keyboard_right_hand1",
    "ANIM_keyboard_right_hand2",
    "ANIM_keyboard_left_hand",
    "ANIM_keyboard_right_hand_tapping",
    "ANIM_bond_eye_fire_alt", /* unused */
    "ANIM_dam_jump",
    "ANIM_surface_vent_jump",
    "ANIM_cradle_jump",
    "ANIM_cradle_fall",
    "ANIM_credits_bond_kissing",
    "ANIM_credits_natalya_kissing"};

char *AIRCRAFT_ANIMATION_ToString[] = {
    "AIRCRAFT_ANIMATION_helicopter_cradle",
    "AIRCRAFT_ANIMATION_plane_runway",
    "AIRCRAFT_ANIMATION_helicopter_takeoff"};

// Add 1 to ID for correct string
char *DIFFICULTY_ToString[] = {
    "DIFFICULTY_MULTI", //-1
    "DIFFICULTY_AGENT",
    "DIFFICULTY_SECRET",
    "DIFFICULTY_00",
    "DIFFICULTY_007",
};

char *ITEM_IDS_ToString[] = {
    "ITEM_UNARMED",
    "ITEM_FIST",
    "ITEM_KNIFE",
    "ITEM_THROWKNIFE",
    "ITEM_WPPK",
    "ITEM_WPPKSIL",
    "ITEM_TT33",
    "ITEM_SKORPION",
    "ITEM_AK47",
    "ITEM_UZI",
    "ITEM_MP5K",
    "ITEM_MP5KSIL",
    "ITEM_SPECTRE",
    "ITEM_M16",
    "ITEM_FNP90",
    "ITEM_SHOTGUN",
    "ITEM_AUTOSHOT",
    "ITEM_SNIPERRIFLE",
    "ITEM_RUGER",
    "ITEM_GOLDENGUN",
    "ITEM_SILVERWPPK",
    "ITEM_GOLDWPPK",
    "ITEM_LASER",
    "ITEM_WATCHLASER",
    "ITEM_GRENADELAUNCH",
    "ITEM_ROCKETLAUNCH",
    "ITEM_GRENADE",
    "ITEM_TIMEDMINE",
    "ITEM_PROXIMITYMINE",
    "ITEM_REMOTEMINE",
    "ITEM_TRIGGER",
    "ITEM_TASER",
    "ITEM_TANKSHELLS",
    "ITEM_BOMBCASE",
    "ITEM_PLASTIQUE",
    "ITEM_FLAREPISTOL",
    "ITEM_PITONGUN",
    "ITEM_BUNGEE",
    "ITEM_DOORDECODER",
    "ITEM_BOMBDEFUSER",
    "ITEM_CAMERA",
    "ITEM_LOCKEXPLODER",
    "ITEM_DOOREXPLODER",
    "ITEM_BRIEFCASE",
    "ITEM_WEAPONCASE",
    "ITEM_SAFECRACKERCASE",
    "ITEM_KEYANALYSERCASE",
    "ITEM_BUG",
    "ITEM_MICROCAMERA",
    "ITEM_BUGDETECTOR",
    "ITEM_EXPLOSIVEFLOPPY",
    "ITEM_POLARIZEDGLASSES",
    "ITEM_DARKGLASSES",
    "ITEM_CREDITCARD",
    "ITEM_GASKEYRING",
    "ITEM_DATATHIEF",
    "ITEM_WATCHIDENTIFIER",
    "ITEM_WATCHCOMMUNICATOR",
    "ITEM_WATCHGEIGERCOUNTER",
    "ITEM_WATCHMAGNETREPEL",
    "ITEM_WATCHMAGNETATTRACT",
    "ITEM_GOLDENEYEKEY",
    "ITEM_BLACKBOX",
    "ITEM_CIRCUITBOARD",
    "ITEM_CLIPBOARD",
    "ITEM_STAFFLIST",
    "ITEM_DOSSIERRED",
    "ITEM_PLANS",
    "ITEM_SPYFILE",
    "ITEM_BLUEPRINTS",
    "ITEM_MAP",
    "ITEM_AUDIOTAPE",
    "ITEM_VIDEOTAPE",
    "ITEM_DATTAPE",
    "ITEM_SPOOLTAPE",
    "ITEM_MICROFILM",
    "ITEM_MICROCODE",
    "ITEM_LECTRE",
    "ITEM_MONEY",
    "ITEM_GOLDBAR",
    "ITEM_HEROIN",
    "ITEM_KEYCARD",
    "ITEM_KEYYALE",
    "ITEM_KEYBOLT",
    "ITEM_SUIT_LF_HAND",
    "ITEM_JOYPAD",
    "ITEM_NULL86",
    "ITEM_NULL87",
    "ITEM_TOKEN",
    "ITEM_IDS_MAX"};

char *PROPDEF_TYPE_ToString[] = {
    "PROPDEF_NOTHING",
    "PROPDEF_DOOR",
    "PROPDEF_DOOR_SCALE",
    "PROPDEF_PROP",
    "PROPDEF_KEY",
    "PROPDEF_ALARM",
    "PROPDEF_CCTV",
    "PROPDEF_MAGAZINE",
    "PROPDEF_COLLECTABLE",
    "PROPDEF_GUARD",
    "PROPDEF_MONITOR",
    "PROPDEF_MULTI_MONITOR",
    "PROPDEF_RACK",
    "PROPDEF_AUTOGUN",
    "PROPDEF_LINK",
    "PROPDEF_DEBRIS",
    "PROPDEF_UNK16",
    "PROPDEF_HAT",
    "PROPDEF_GUARD_ATTRIBUTE",
    "PROPDEF_SWITCH",
    "PROPDEF_AMMO",
    "PROPDEF_ARMOUR",
    "PROPDEF_TAG",
    "PROPDEF_OBJECTIVE_START",
    "PROPDEF_OBJECTIVE_END",
    "PROPDEF_OBJECTIVE_DESTROY_OBJECT",
    "PROPDEF_OBJECTIVE_COMPLETE_CONDITION",
    "PROPDEF_OBJECTIVE_FAIL_CONDITION",
    "PROPDEF_OBJECTIVE_COLLECT_OBJECT",
    "PROPDEF_OBJECTIVE_DEPOSIT_OBJECT",
    "PROPDEF_OBJECTIVE_PHOTOGRAPH",
    "PROPDEF_OBJECTIVE_NULL",
    "PROPDEF_OBJECTIVE_ENTER_ROOM",
    "PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM",
    "PROPDEF_OBJECTIVE_COPY_ITEM",
    "PROPDEF_WATCH_MENU_OBJECTIVE_TEXT",
    "PROPDEF_GAS_RELEASING",
    "PROPDEF_RENAME",
    "PROPDEF_LOCK_DOOR",
    "PROPDEF_VEHICHLE",
    "PROPDEF_AIRCRAFT",
    "PROPDEF_UNK41",
    "PROPDEF_GLASS",
    "PROPDEF_SAFE",
    "PROPDEF_SAFE_ITEM",
    "PROPDEF_TANK",
    "PROPDEF_CAMERAPOS", // canonical name
    "PROPDEF_TINTED_GLASS",
    "PROPDEF_END",
};

char *PROP_ToString[] = {
    "PROP_ALARM1",              /* Beta Alarm / Default Multi Weapon         */
    "PROP_ALARM2",              /* Alarm                */
    "PROP_EXPLOSIONBIT",        /* White Pyramid (Explosion Bit)          */
    "PROP_AMMO_CRATE1",         /* Ammo Crate (Brown w/ Edge Brace", 6x240 Black)      */
    "PROP_AMMO_CRATE2",         /* Ammo Crate (Brown w/ Center Brace", 12x8 Black)      */
    "PROP_AMMO_CRATE3",         /* Ammo Crate (Green w/ Center Brace", 12x8 Brown)      */
    "PROP_AMMO_CRATE4",         /* Ammo Crate (Green w/ Edge Brace", 6x8 White)      */
    "PROP_AMMO_CRATE5",         /* Ammo Crate (Green w/ Double Brace", 24x60 Black)     */
    "PROP_BIN1",                /* Rusted Trash Bin             */
    "PROP_BLOTTER1",            /* Desk Blotter              */
    "PROP_BOOK1",               /* Red Book               */
    "PROP_BOOKSHELF1",          /* Bookshelf               */
    "PROP_BRIDGE_CONSOLE1A",    /* Bridge Console w/ Monitor", Navigation + Keyboard 1A    */
    "PROP_BRIDGE_CONSOLE1B",    /* Bridge Console w/ Navigation 1B         */
    "PROP_BRIDGE_CONSOLE2A",    /* Bridge Console w/ Navigation", Monitor + Keyboard 2A    */
    "PROP_BRIDGE_CONSOLE2B",    /* Bridge Console w/ Various Controls 2B        */
    "PROP_BRIDGE_CONSOLE3A",    /* Bridge Console w/ Monitor", Navigation + Keyboard 3A    */
    "PROP_BRIDGE_CONSOLE3B",    /* Bridge Console w/ Monitor", Keyboard + Navigation 3B    */
    "PROP_CARD_BOX1",           /* Cardboard Box", Kapto|Enb           */
    "PROP_CARD_BOX2",           /* Cardboard Box", Red Arrow", Bahko         */
    "PROP_CARD_BOX3",           /* Cardboard Box", Scrawled Text", Bahah        */
    "PROP_CARD_BOX4_LG",        /* Cardboard Box", Three Seams           */
    "PROP_CARD_BOX5_LG",        /* Cardboard Box", Two Seams", Bahah         */
    "PROP_CARD_BOX6_LG",        /* Cardboard Box", Bahko            */
    "PROP_CCTV",                /* Surveillance Camera            */
    "PROP_CONSOLE1",            /* Double Screen Consoles w/ Keyboards        */
    "PROP_CONSOLE2",            /* Double Screen Consoles w/ Left Keyboard       */
    "PROP_CONSOLE3",            /* Double Screen Consoles w/ Right Keyboard       */
    "PROP_CONSOLE_SEVA",        /* Console w/ Keyboard            */
    "PROP_CONSOLE_SEVB",        /* Console w/ Monitor + Keyboard          */
    "PROP_CONSOLE_SEVC",        /* Console w/ Switches            */
    "PROP_CONSOLE_SEVD",        /* Console w/ Five Gauges            */
    "PROP_CONSOLE_SEV2A",       /* Console w/ Four Faders            */
    "PROP_CONSOLE_SEV2B",       /* Console w/ Monitor", Keyboard + Switches       */
    "PROP_CONSOLE_SEV2C",       /* Console w/ Three Gauges           */
    "PROP_CONSOLE_SEV2D",       /* Console w/ Pressure Gauge           */
    "PROP_CONSOLE_SEV_GEA",     /* Console w/ GoldenEye Key Slot          */
    "PROP_CONSOLE_SEV_GEB",     /* Console w/ Faders + Pressure Gauge         */
    "PROP_DESK1",               /* Desk w/ Kickplate             */
    "PROP_DESK2",               /* Desk                */
    "PROP_DESK_LAMP2",          /* Desk Lamp               */
    "PROP_DISC_READER",         /* External Hard Drive            */
    "PROP_DISK_DRIVE1",         /* Floppy Disc Drive             */
    "PROP_FILING_CABINET1",     /* Filing Cabinet              */
    "PROP_JERRY_CAN1",          /* Jerrycan (Fuel Container)           */
    "PROP_KEYBOARD1",           /* Computer Keyboard             */
    "PROP_KIT_UNITS1",          /* Kitchen Cabinets             */
    "PROP_LETTER_TRAY1",        /* Letter Tray              */
    "PROP_MAINFRAME1",          /* Mainframe", Basic             */
    "PROP_MAINFRAME2",          /* Mainframe", Advanced            */
    "PROP_METAL_CHAIR1",        /* Chair (Metal)              */
    "PROP_METAL_CRATE1",        /* Metal Crate", 6 Top Corner           */
    "PROP_METAL_CRATE2",        /* Metal Crate", 6 Bottom Corner          */
    "PROP_METAL_CRATE3",        /* Metal Crate", Toxic Materials          */
    "PROP_METAL_CRATE4",        /* Metal Crate", Double Stripe - Class D1 Hazard      */
    "PROP_MISSILE_RACK",        /* Naval Harpoon Missile in Containment Rack       */
    "PROP_MISSILE_RACK2",       /* Naval Harpoon Missiles in Containment Racks x4      */
    "PROP_OIL_DRUM1",           /* Oil Drum", Single Stripe", Ribbed         */
    "PROP_OIL_DRUM2",           /* Oil Drum", Single Stripe", Ribbed - Class D1 Hazard     */
    "PROP_OIL_DRUM3",           /* Oil Drum", Single Stripe", Ribbed - Toxic Materials     */
    "PROP_OIL_DRUM5",           /* Oil Drum", Double Stripe - Toxic Materials       */
    "PROP_OIL_DRUM6",           /* Oil Drum - Toxic Materials           */
    "PROP_OIL_DRUM7",           /* Oil Drum", Double Dashes - Class D1 Hazard       */
    "PROP_PADLOCK",             /* Padlock               */
    "PROP_PHONE1",              /* Telephone               */
    "PROP_RADIO_UNIT1",         /* Radio Tuner w/ 1 Knob + 2 Gauges         */
    "PROP_RADIO_UNIT2",         /* Radio Tuner w/ 1 Knob + 5 Gauges         */
    "PROP_RADIO_UNIT3",         /* Radio Tuner w/ 3 Knobs + 5 Gauges         */
    "PROP_RADIO_UNIT4",         /* Radio Tuner w/ 3 Knobs + 2 Gauges         */
    "PROP_SAT1_REFLECT",        /* GoldenEye Satellite            */
    "PROP_SATDISH",             /* Satellite Dish (Arkangelsk)          */
    "PROP_SATBOX",              /* Uplink Box               */
    "PROP_STOOL1",              /* Wooden Stool              */
    "PROP_SWIVEL_CHAIR1",       /* Swivel Chair              */
    "PROP_TORPEDO_RACK",        /* Naval Torpedo Rack x3            */
    "PROP_TV1",                 /* Television Monitor             */
    "PROP_TV_HOLDER",           /* Hanging Monitor Rack            */
    "PROP_TVSCREEN",            /* Wall Monitor Screen            */
    "PROP_TV4SCREEN",           /* Wall Monitor Screens", 4-in-1          */
    "PROP_WOOD_LG_CRATE1",      /* Wooden Crate w/ #4 Label", Bahah         */
    "PROP_WOOD_LG_CRATE2",      /* Wooden Crate", Darker Shading", Kapto|Enb       */
    "PROP_WOOD_MD_CRATE3",      /* Wooden Crates x8", Bahko           */
    "PROP_WOOD_SM_CRATE4",      /* Wooden Crate w/ #2 Label", Bahko         */
    "PROP_WOOD_SM_CRATE5",      /* Wooden Crate w/ #4 Label", Darker Shading", Bahah     */
    "PROP_WOOD_SM_CRATE6",      /* Wooden Crate w/ UP Arrow", Kapto|Enb        */
    "PROP_WOODEN_TABLE1",       /* Wooden Table              */
    "PROP_SWIPE_CARD2",         /* Keycard               */
    "PROP_BORG_CRATE",          /* Blue and Gold Printed Circuit Cube (Borg Crate)     */
    "PROP_BOXES4X4",            /* Metal Crate Stack", 4x4            */
    "PROP_BOXES3X4",            /* Metal Crate Stack", 3x4            */
    "PROP_BOXES2X4",            /* Metal Crate Stack", 2x4            */
    "PROP_SEC_PANEL",           /* Security Card Panel            */
    "PROP_ICBM_NOSE",           /* Silo Missile (ICBM)", Nose Cone Only        */
    "PROP_ICBM",                /* Silo Missile (ICBM)            */
    "PROP_TUNING_CONSOLE1",     /* Dual Consoles on Castors           */
    "PROP_DESK_ARECIBO1",       /* Computer Work Desk             */
    "PROP_LOCKER3",             /* Lockers", Single Venting           */
    "PROP_LOCKER4",             /* Lockers", Double Venting           */
    "PROP_ROOFGUN",             /* Ceiling Mounted Drone Gun           */
    "PROP_DEST_ENGINE",         /* Frigate Engine              */
    "PROP_DEST_EXOCET",         /* Naval MK 29 Missile Launcher (Exocet)        */
    "PROP_DEST_GUN",            /* Naval 100 mm Gun Turret (TR 100)         */
    "PROP_DEST_HARPOON",        /* Naval MK 141 Launch Canisters (Harpoon)       */
    "PROP_DEST_SEAWOLF",        /* Naval MK 26 Dual Missile Launcher (Seawolf)      */
    "PROP_WINDOW",              /* Window Glass              */
    "PROP_WINDOW_LIB_LG1",      /* Window Glass", Lattice Frame", 4x10 (single-sided)     */
    "PROP_WINDOW_LIB_SM1",      /* Window Glass", Lattice Frame", 4x3 (double-sided)     */
    "PROP_WINDOW_COR11",        /* Window Glass", Lattice Frame", 4x4 (single-sided)     */
    "PROP_JUNGLE3_TREE",        /* Jungle Large Tree             */
    "PROP_PALM",                /* Jungle Palm Tree             */
    "PROP_PALMTREE",            /* Jungle Palm Tree", Resprouting After Loss of Fronds     */
    "PROP_PLANT2B",             /* Jungle Plant", Low Shrub           */
    "PROP_LABBENCH",            /* Laboratory Table w/ Sink Drains         */
    "PROP_GASBARREL",           /* White Bin               */
    "PROP_GASBARRELS",          /* White Bins x4              */
    "PROP_BODYARMOUR",          /* Body Armor               */
    "PROP_BODYARMOURVEST",      /* Body Armor (Vest)             */
    "PROP_GASTANK",             /* Bottling Tank              */
    "PROP_GLASSWARE1",          /* Glass Cup               */
    "PROP_HATCHBOLT",           /* Metallic Securing Strip (Hatch Bolt)        */
    "PROP_BRAKEUNIT",           /* Train Brake Controller            */
    "PROP_AK47MAG",             /* Gun Magazine (KF7 Soviet)           */
    "PROP_M16MAG",              /* Gun Magazine (AR33 Assault Rifle)         */
    "PROP_MP5KMAG",             /* Gun Magazine (D5K Deutsche)          */
    "PROP_SKORPIONMAG",         /* Gun Magazine (Klobb)            */
    "PROP_SPECTREMAG",          /* Gun Magazine (Phantom)            */
    "PROP_UZIMAG",              /* Gun Magazine (ZMG (9mm))           */
    "PROP_SILENCER",            /* Silencer               */
    "PROP_CHREXTINGUISHER",     /* Fire Extinguisher             */
    "PROP_BOXCARTRIDGES",       /* Box of Shells (Shotgun Cartridges)         */
    "PROP_FNP90MAG",            /* Gun Magazine (RC-P90)            */
    "PROP_GOLDENSHELLS",        /* Box of Shells (Golden Gun Bullets)         */
    "PROP_MAGNUMSHELLS",        /* Box of Shells (Magnum Rounds)          */
    "PROP_WPPKMAG",             /* Gun Magazine (PP7)             */
    "PROP_TT33MAG",             /* Gun Magazine (DD44 Dostovei)          */
    "PROP_SEV_DOOR",            /* Grey Containment Door w/ Caution Stripes and Window    */
    "PROP_SEV_DOOR3",           /* Grey Electronic Door w/ LEFT Arrow         */
    "PROP_SEV_DOOR3_WIND",      /* BETA Electronic Door w/ LEFT Arrow and Fake Window     */
    "PROP_SEV_DOOR4_WIND",      /* Grey Electronic Door w/ LEFT Arrow and Window      */
    "PROP_SEV_TRISLIDE",        /* Glass Door w/ Stone Frame           */
    "PROP_SEV_DOOR_V1",         /* Grey Electronic Door w/ UP Arrow         */
    "PROP_STEEL_DOOR1",         /* Silver Corrugated Door w/ Caution Stripes       */
    "PROP_STEEL_DOOR2",         /* Rusty Door w/ Handle            */
    "PROP_STEEL_DOOR3",         /* Double Cross Brace Door           */
    "PROP_SILO_LIFT_DOOR",      /* Elevator Door              */
    "PROP_STEEL_DOOR2B",        /* Rusty Door w/o Handle            */
    "PROP_DOOR_ROLLER1",        /* Blue Bay Door w/ Caution Stripes         */
    "PROP_DOOR_ROLLER2",        /* Blue Bay Door w/ Venting and Caution Stripes      */
    "PROP_DOOR_ROLLER3",        /* Blue Bay Door w/ Venting and Caution Stripes      */
    "PROP_DOOR_ROLLER4",        /* Cargo Bay Door w/ UP Arrow and Transportation Stripes    */
    "PROP_DOOR_ST_AREC1",       /* Blue Corrugated Door w/ Transportation Stripes      */
    "PROP_DOOR_ST_AREC2",       /* Blue Reversed Corrugated Door w/ Transportation Stripes   */
    "PROP_DOOR_DEST1",          /* Grey Frigate Door w/ Indents and Caution Stripes     */
    "PROP_DOOR_DEST2",          /* Grey Frigate Door w/ Indents", Caution Stripes and KEEP CLEAR Label */
    "PROP_GAS_PLANT_SW_DO1",    /* Grey Swinging Door w/ Blue Stripe         */
    "PROP_GAS_PLANT_SW2_DO1",   /* Grey Swinging Door", Darker           */
    "PROP_GAS_PLANT_SW3_DO1",   /* Grey Swinging Door", Lighter          */
    "PROP_GAS_PLANT_SW4_DO1",   /* Light Wooden Door (Looks Like Sand)        */
    "PROP_GAS_PLANT_MET1_DO1",  /* Brown Electronic Door            */
    "PROP_GAS_PLANT_WC_CUB1",   /* Bathroom Stall Door            */
    "PROP_GASPLANT_CLEAR_DOOR", /* Laboratory Glass Door            */
    "PROP_TRAIN_DOOR",          /* Dark Wooden Door             */
    "PROP_TRAIN_DOOR2",         /* Dark Wooden Door w/ Window           */
    "PROP_TRAIN_DOOR3",         /* Dark Wooden Door w/ Window + Shutter        */
    "PROP_DOOR_EYELID",         /* Eyelid Door              */
    "PROP_DOOR_IRIS",           /* Iris Door               */
    "PROP_SEVDOORWOOD",         /* Cabin Door               */
    "PROP_SEVDOORWIND",         /* Weathered Swinging Door w/ Window         */
    "PROP_SEVDOORNOWIND",       /* Weathered Swinging Door           */
    "PROP_SEVDOORMETSLIDE",     /* Brown Corrugated Electronic Door         */
    "PROP_CRYPTDOOR1A",         /* Stone Door w/ Prints (Set A)          */
    "PROP_CRYPTDOOR1B",         /* Sand Door w/ Damage (Set A)          */
    "PROP_CRYPTDOOR2A",         /* Stone Door w/ Prints", Darker (Set B)        */
    "PROP_CRYPTDOOR2B",         /* Sand Door w/ Damage", Darker (Set B)        */
    "PROP_CRYPTDOOR3",          /* Egyptian Moving Wall            */
    "PROP_CRYPTDOOR4",          /* Brown Sand Door (Temple)           */
    "PROP_VERTDOOR",            /* Blast Door (Control)            */
    "PROP_HATCHDOOR",           /* Train Floor Hatch             */
    "PROP_DAMGATEDOOR",         /* Security Gate (Dam)            */
    "PROP_DAMTUNDOOR",          /* Tunnel Flood Door (Dam)           */
    "PROP_DAMCHAINDOOR",        /* Mesh Gate               */
    "PROP_SILOTOPDOOR",         /* Launch Tube Ceiling Shutter (Silo)         */
    "PROP_DOORPRISON1",         /* Cell Door               */
    "PROP_DOORSTATGATE",        /* Park Gate               */
    "PROP_CHRKALASH",           /* KF7 Soviet               */
    "PROP_CHRGRENADELAUNCH",    /* Grenade Launcher             */
    "PROP_CHRKNIFE",            /* Hunting Knife              */
    "PROP_CHRLASER",            /* Moonraker Laser             */
    "PROP_CHRM16",              /* AR33 Assault Rifle             */
    "PROP_CHRMP5K",             /* D5K Deutsche              */
    "PROP_CHRRUGER",            /* Cougar Magnum              */
    "PROP_CHRWPPK",             /* PP7 Special Issue             */
    "PROP_CHRSHOTGUN",          /* Shotgun               */
    "PROP_CHRSKORPION",         /* Klobb                */
    "PROP_CHRSPECTRE",          /* Phantom               */
    "PROP_CHRUZI",              /* ZMG (9mm)               */
    "PROP_CHRGRENADE",          /* Hand Grenade              */
    "PROP_CHRFNP90",            /* RC-P90                */
    "PROP_CHRBRIEFCASE",        /* Briefcase               */
    "PROP_CHRREMOTEMINE",       /* Remote Mine              */
    "PROP_CHRPROXIMITYMINE",    /* Proximity Mine              */
    "PROP_CHRTIMEDMINE",        /* Timed Mine               */
    "PROP_CHRROCKET",           /* Rocket                */
    "PROP_CHRGRENADEROUND",     /* Grenade Round              */
    "PROP_CHRWPPKSIL",          /* PP7 (Silenced)              */
    "PROP_CHRTT33",             /* DD44 Dostovei              */
    "PROP_CHRMP5KSIL",          /* D5K (Silenced)              */
    "PROP_CHRAUTOSHOT",         /* Automatic Shotgun             */
    "PROP_CHRGOLDEN",           /* Golden Gun               */
    "PROP_CHRTHROWKNIFE",       /* Throwing Knife              */
    "PROP_CHRSNIPERRIFLE",      /* Sniper Rifle              */
    "PROP_CHRROCKETLAUNCH",     /* Rocket Launcher             */
    "PROP_HATFURRY",            /* Fur Hat", Blue              */
    "PROP_HATFURRYBROWN",       /* Fur Hat", Brown              */
    "PROP_HATFURRYBLACK",       /* Fur Hat", Black              */
    "PROP_HATTBIRD",            /* Side Cap", Light Green            */
    "PROP_HATTBIRDBROWN",       /* Side Cap", Dark Green            */
    "PROP_HATHELMET",           /* Combat Helmet", Green            */
    "PROP_HATHELMETGREY",       /* Combat Helmet", Grey            */
    "PROP_HATMOON",             /* Elite Headgear              */
    "PROP_HATBERET",            /* Special Forces Beret", Black          */
    "PROP_HATBERETBLUE",        /* Special Forces Beret", Navy           */
    "PROP_HATBERETRED",         /* Special Forces Beret", Burgundy          */
    "PROP_HATPEAKED",           /* Officer's Peaked Visor Cap           */
    "PROP_CHRWRISTDART",        /* Pchrwristdart (BETA)            */
    "PROP_CHREXPLOSIVEPEN",     /* Pchrexplosivepen (BETA)           */
    "PROP_CHRBOMBCASE",         /* Bomb Case (Briefcase Laying Down)         */
    "PROP_CHRFLAREPISTOL",      /* Pchrflarepistol (BETA Pickup)          */
    "PROP_CHRPITONGUN",         /* Pchrpitongun (BETA Pickup)           */
    "PROP_CHRFINGERGUN",        /* Pchrfingergun (BETA Pickup)          */
    "PROP_CHRSILVERWPPK",       /* Pchrsilverwppk (BETA Pickup)          */
    "PROP_CHRGOLDWPPK",         /* Pchrgoldwppk (BETA Pickup)           */
    "PROP_CHRDYNAMITE",         /* Pchrdynamite (BETA Pickup)           */
    "PROP_CHRBUNGEE",           /* Pchrbungee (BETA Pickup)           */
    "PROP_CHRDOORDECODER",      /* Door Decoder              */
    "PROP_CHRBOMBDEFUSER",      /* Bomb Defuser              */
    "PROP_CHRBUGDETECTOR",      /* Pchrbugdetector (BETA Pickup)          */
    "PROP_CHRSAFECRACKERCASE",  /* Safe Cracker Case (Briefcase Laying Down)       */
    "PROP_CHRCAMERA",           /* Photo Camera (007)             */
    "PROP_CHRLOCKEXPLODER",     /* Pchrlockexploder (BETA Pickup)          */
    "PROP_CHRDOOREXPLODER",     /* Pchrdoorexploder (BETA Pickup)          */
    "PROP_CHRKEYANALYSERCASE",  /* Key Analyzer Case (Briefcase Laying Down)       */
    "PROP_CHRWEAPONCASE",       /* Weapon Case (Briefcase Standing Up)        */
    "PROP_CHRKEYYALE",          /* Yale Key               */
    "PROP_CHRKEYBOLT",          /* Bolt Key               */
    "PROP_CHRBUG",              /* Covert Modem / Tracker Bug           */
    "PROP_CHRMICROCAMERA",      /* Micro Camera              */
    "PROP_FLOPPY",              /* Floppy Disc              */
    "PROP_CHRGOLDENEYEKEY",     /* GoldenEye Key              */
    "PROP_CHRPOLARIZEDGLASSES", /* Polarized Glasses             */
    "PROP_CHRCREDITCARD",       /* Pchrcreditcard (BETA Pickup)          */
    "PROP_CHRDARKGLASSES",      /* Pchrdarkglasses (BETA Pickup)          */
    "PROP_CHRGASKEYRING",       /* Gas Keyring              */
    "PROP_CHRDATATHIEF",        /* Datathief               */
    "PROP_SAFE",                /* Safe Body               */
    "PROP_BOMB",                /* Pbomb (BETA Pickup)            */
    "PROP_CHRPLANS",            /* Plans (Briefing Folder)           */
    "PROP_CHRSPYFILE",          /* Pchrspyfile (BETA Pickup)           */
    "PROP_CHRBLUEPRINTS",       /* Pirate Blueprints             */
    "PROP_CHRCIRCUITBOARD",     /* Circuitboard              */
    "PROP_CHRMAP",              /* Bunker Expansion Plans            */
    "PROP_CHRSPOOLTAPE",        /* Pchrspooltape (BETA Pickup)          */
    "PROP_CHRAUDIOTAPE",        /* Audiotape               */
    "PROP_CHRMICROFILM",        /* Pchrmicrofilm (BETA Pickup)          */
    "PROP_CHRMICROCODE",        /* Pchrmicrocode (BETA Pickup)          */
    "PROP_CHRLECTRE",           /* Pchrlectre (BETA Pickup)           */
    "PROP_CHRMONEY",            /* Pchrmoney (BETA Pickup)           */
    "PROP_CHRGOLDBAR",          /* Pchrgoldbar (BETA Pickup)           */
    "PROP_CHRHEROIN",           /* Pchrheroin (BETA Pickup)           */
    "PROP_CHRCLIPBOARD",        /* Clipboard               */
    "PROP_CHRDOSSIERRED",       /* Red Dossier              */
    "PROP_CHRSTAFFLIST",        /* Staff List               */
    "PROP_CHRDATTAPE",          /* DAT                */
    "PROP_CHRPLASTIQUE",        /* Plastique               */
    "PROP_CHRBLACKBOX",         /* Black Box (Orange Flight Recorder)         */
    "PROP_CHRVIDEOTAPE",        /* CCTV Tape (GoldenEye VHS)           */
    "PROP_NINTENDOLOGO",        /* Nintendo Logo              */
    "PROP_GOLDENEYELOGO",       /* GoldenEye Logo              */
    "PROP_WALLETBOND",          /* Classified Folder w/ Royal Crest (Folder Menus)     */
    "PROP_MILTRUCK",            /* Supply Truck              */
    "PROP_JEEP",                /* Military Jeep              */
    "PROP_ARTIC",               /* Red Prime Mover             */
    "PROP_HELICOPTER",          /* Transport Helicopter w/ Natalya         */
    "PROP_TIGER",               /* Pirate Euro Chopper            */
    "PROP_MILCOPTER",           /* Hound Helicopter             */
    "PROP_HIND",                /* Soviet Camouflage Chopper           */
    "PROP_ARTICTRAILER",        /* Black Trailer              */
    "PROP_MOTORBIKE",           /* Motorbike               */
    "PROP_TANK",                /* Tank                */
    "PROP_APC",                 /* Armored Personnel Carrier           */
    "PROP_SPEEDBOAT",           /* Speedboat               */
    "PROP_PLANE",               /* Aeroplane               */
    "PROP_GUN_RUNWAY1",         /* Heavy Gun Emplacement            */
    "PROP_SAFEDOOR",            /* Safe Door               */
    "PROP_KEY_HOLDER",          /* Key Rack               */
    "PROP_HATCHSEVX",           /* Grating (Ventshaft Hatch)           */
    "PROP_SEVDISH",             /* Satellite Dish (Severnaya)           */
    "PROP_ARCHSECDOOR1",        /* Archives Moving Wall (Dark)          */
    "PROP_ARCHSECDOOR2",        /* Archives Moving Wall (Light)          */
    "PROP_GROUNDGUN",           /* Free Standing Drone Gun           */
    "PROP_TRAINEXTDOOR",        /* Train Exterior Door            */
    "PROP_CARBMW",              /* White Car #1 (BMW)             */
    "PROP_CARESCORT",           /* White Car #2 (Escort)            */
    "PROP_CARGOLF",             /* White Car #3 (Golf)            */
    "PROP_CARWEIRD",            /* Red Car (Cadillac)             */
    "PROP_CARZIL",              /* Ourumov's Car (ZIL)            */
    "PROP_SHUTTLE_DOOR_L",      /* Exhaust Bay Doors", Left Side          */
    "PROP_SHUTTLE_DOOR_R",      /* Exhaust Bay Doors", Right Side          */
    "PROP_DEPOT_GATE_ENTRY",    /* Metallic Gate w/ Red Star           */
    "PROP_DEPOT_DOOR_STEEL",    /* Rusty Door w/ Handle (Lo-Res)          */
    "PROP_GLASSWARE2",          /* Beaker w/ Blue Topper            */
    "PROP_GLASSWARE3",          /* Erlenmeyer Flask             */
    "PROP_GLASSWARE4",          /* Set of Five Beakers            */
    "PROP_LANDMINE",            /* Land Mine               */
    "PROP_PLANT1",              /* Jungle Plant", Withered and Dying         */
    "PROP_PLANT11",             /* Jungle Plant", Turning Colour          */
    "PROP_PLANT2",              /* Jungle Plant", Healthy and Thick         */
    "PROP_PLANT3",              /* Jungle Plant", Tall Leaves           */
    "PROP_JUNGLE5_TREE",        /* Jungle Tree", Moss Covered           */
    "PROP_LEGALPAGE",           /* GoldenEye Certification Screen          */
    "PROP_ST_PETE_ROOM_1I",     /* Roads and Buildings #1 (stretch of road)       */
    "PROP_ST_PETE_ROOM_2I",     /* Roads and Buildings #2 (stretch of road)       */
    "PROP_ST_PETE_ROOM_3T",     /* Roads and Buildings #3 (intersection)        */
    "PROP_ST_PETE_ROOM_5C",     /* Roads and Buildings #4 (street corner)        */
    "PROP_ST_PETE_ROOM_6C",     /* Roads and Buildings #5 (street corner)        */
    "PROP_DOOR_ROLLERTRAIN",    /* Roller Door              */
    "PROP_DOOR_WIN",            /* Glass Sliding Door (Aztec)           */
    "PROP_DOOR_AZTEC",          /* Stone Sliding Door (Aztec)           */
    "PROP_SHUTTLE",             /* Moonraker Shuttle             */
    "PROP_DOOR_AZT_DESK",       /* Boardroom Table (Aztec Exhaust Bay)        */
    "PROP_DOOR_AZT_DESK_TOP",   /* Boardroom Table Extension (Aztec Exhaust Bay)      */
    "PROP_DOOR_AZT_CHAIR",      /* Boardroom Chair (Aztec Exhaust Bay)        */
    "PROP_DOOR_MF",             /* Mainframe Door              */
    "PROP_FLAG",                /* Flag Tag Token              */
    "PROP_BARRICADE",           /* Road Barricade              */
    "PROP_MODEMBOX",            /* Covert Modem Connection Screen          */
    "PROP_DOORPANEL",           /* Sliding Door Activation Switch          */
    "PROP_DOORCONSOLE",         /* Console w/ Activation Light          */
    "PROP_CHRTESTTUBE",         /* Glass Test Tube             */
    "PROP_BOLLARD",             /* Bollard               */
};

char *CAMERAMODE_ToString[] = {
    "CAMERAMODE_NONE",
    "CAMERAMODE_INTRO",
    "CAMERAMODE_FADESWIRL",
    "CAMERAMODE_SWIRL",
    "CAMERAMODE_FP",
    "CAMERAMODE_DEATH_CAM_SP",
    "CAMERAMODE_DEATH_CAM_MP",
    "CAMERAMODE_POSEND",
    "CAMERAMODE_FP_NOINPUT",
    "CAMERAMODE_MP",
    "CAMERAMODE_FADE_TO_TITLE",
};

char *INTRO_TYPE_ToString[] = {
    "INTROTYPE_SPAWN",
    "INTROTYPE_ITEM",
    "INTROTYPE_AMMO",
    "INTROTYPE_SWIRL",
    "INTROTYPE_ANIM",
    "INTROTYPE_CUFF",
    "INTROTYPE_CAMERA",
    "INTROTYPE_WATCH",
    "INTROTYPE_CREDITS",
    "INTROTYPE_END",
};

char *MISSION_STATE_IDS_ToString[] = {
    "MISSION_STATE_0",
    "MISSION_STATE_1",
    "MISSION_STATE_2",
    "MISSION_STATE_3",
    "MISSION_STATE_4",
    "MISSION_STATE_5",
    "MISSION_STATE_6"};

char *OBJECTIVESTATUS_ToString[] = {
    "OBJECTIVESTATUS_INCOMPLETE",
    "OBJECTIVESTATUS_COMPLETE",
    "OBJECTIVESTATUS_FAILED"};

char *GAILIST_ToString[] = {
    "GAILIST_AIM_AT_BOND",
    "GAILIST_DEAD_AI",
    "GAILIST_STANDARD_GUARD",
    "GAILIST_PLAY_IDLE_ANIMATION",
    "GAILIST_BASH_KEYBOARD",
    "GAILIST_SIMPLE_GUARD_DEAF",
    "GAILIST_ATTACK_BOND",
    "GAILIST_SIMPLE_GUARD",
    "GAILIST_RUN_TO_BOND",
    "GAILIST_SIMPLE_GUARD_ALARM_RAISER",
    "GAILIST_STARTLE_AND_RUN_TO_BOND",
    "GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND",
    "GAILIST_STANDARD_CLONE",
    "GAILIST_PERSISTENTLY_CHASE_AND_ATTACK_BOND",
    "GAILIST_WAIT_ONE_SECOND",
    "GAILIST_END_LEVEL",
    "GAILIST_DRAW_TT33_AND_ATTCK_BOND",
    "GAILIST_REMOVE_CHR"};

char *LEVELID_ToString[] = {
    "LEVELID_NONE",
    "LEVELID_DEFAULT",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "LEVELID_BUNKER1",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "LEVELID_SILO",
    "",
    "LEVELID_STATUE",
    "LEVELID_CONTROL",
    "LEVELID_ARCHIVES",
    "LEVELID_TRAIN",
    "LEVELID_FRIGATE",
    "LEVELID_BUNKER2",
    "LEVELID_AZTEC",
    "LEVELID_STREETS",
    "LEVELID_DEPOT",
    "LEVELID_COMPLEX",
    "LEVELID_EGYPT",
    "LEVELID_DAM",
    "LEVELID_FACILITY",
    "LEVELID_RUNWAY",
    "LEVELID_SURFACE",
    "LEVELID_JUNGLE",
    "LEVELID_TEMPLE",
    "LEVELID_CAVERNS",
    "LEVELID_CITADEL",
    "LEVELID_CRADLE",
    "LEVELID_SHO",
    "LEVELID_SURFACE2",
    "LEVELID_ELD",
    "LEVELID_BASEMENT",
    "LEVELID_STACK",
    "LEVELID_LUE",
    "LEVELID_LIBRARY",
    "LEVELID_RIT",
    "LEVELID_CAVES",
    "LEVELID_EAR",
    "LEVELID_LEE",
    "LEVELID_LIP",
    "LEVELID_CUBA",
    "LEVELID_WAX",
    "LEVELID_PAM",
    "LEVELID_MAX",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "LEVELID_TITLE"};

char *TEXTBANK_LEVEL_INDEX_ToString[] =
    {
        "LNULL",      /* Null (unused) */
        "LAME",       /* Library (multi) */
        "LARCH",      /* Archives */
        "LARK",       /* Facility */
        "LASH",       /* Stack (multi) */
        "LAZT",       /* Aztec */
        "LCAT",       /* Citadel (multi) */
        "LCAVE",      /* Caverns */
        "LAREC",      /* Control */
        "LCRAD",      /* Cradle */
        "LCRYP",      /* Egypt */
        "LDAM",       /* Dam */
        "LDEPO",      /* Depot */
        "LDEST",      /* Frigate */
        "LDISH",      /* Temple (multi) */
        "LEAR",       /* Ear (unused) */
        "LELD",       /* Eld (unused) */
        "LIMP",       /* Basement (multi) */
        "LJUN",       /* Jungle */
        "LLEE",       /* Lee (unused) */
        "LLEN",       /* Cuba */
        "LLIP",       /* Lip (unused) */
        "LLUE",       /* Lue (unused) */
        "LOAT",       /* Cave (multi) */
        "LPAM",       /* Pam (unused) */
        "LPETE",      /* Streets */
        "LREF",       /* Complex (multi) */
        "LRIT",       /* Rit (unused) */
        "LRUN",       /* Runway */
        "LSEVB",      /* Bunker 2 */
        "LSEV",       /* Bunker 1 */
        "LSEVX",      /* Surface 1 */
        "LSEVXB",     /* Surface 2 */
        "LSHO",       /* Sho (unused) */
        "LSILO",      /* Silo */
        "LSTAT",      /* Statue */
        "LTRA",       /* Train */
        "LWAX",       /* Wax (unused) */
        "LGUN",       /* Guns */
        "LTITLE",     /* Stage and menu titles */
        "LMPMENU",    /* Multi menus */
        "LPROPOBJ",   /* In-game pickups */
        "LMPWEAPONS", /* Multi weapon select */
        "LOPTIONS",   /* Solo in-game menus */
        "LMISC"       /* Cheat options */
};
#pragma region lengths
#define AI_GotoNext_LENGTH                                       2
#define AI_GotoFirst_LENGTH                                      2
#define AI_Label_LENGTH                                          2
#define AI_Yield_LENGTH                                          1
#define AI_EndList_LENGTH                                        /*canonical name*/ 1
#define AI_SetChrAiList_LENGTH                                   4
#define AI_SetReturnAiList_LENGTH                                3
#define AI_Return_LENGTH                                         1
#define AI_Stop_LENGTH                                           1
#define AI_Kneel_LENGTH                                          1
#define AI_PlayAnimation_LENGTH                                  9
#define AI_IFPlayingAnimation_LENGTH                             2
#define AI_PointAtBond_LENGTH                                    1
#define AI_LookSurprised_LENGTH                                  1
#define AI_TRYSidestepping_LENGTH                                2
#define AI_TRYSideHopping_LENGTH                                 2
#define AI_TRYSideRunning_LENGTH                                 2
#define AI_TRYFiringWalk_LENGTH                                  2
#define AI_TRYFiringRun_LENGTH                                   2
#define AI_TRYFiringRoll_LENGTH                                  2
#define AI_TRYFireOrAimAtTarget_LENGTH                           6
#define AI_TRYFireOrAimAtTargetKneel_LENGTH                      6
#define AI_IFImFiring_LENGTH                                     2
#define AI_IFImFiringAndLockedForward_LENGTH                     2
#define AI_TRYFireOrAimAtTargetUpdate_LENGTH                     6
#define AI_TRYFacingTarget_LENGTH                                6
#define AI_HitChrWithItem_LENGTH                                 4
#define AI_ChrHitChr_LENGTH                                      4
#define AI_TRYThrowingGrenade_LENGTH                             2
#define AI_TRYDroppingItem_LENGTH                                5
#define AI_RunToPad_LENGTH                                       3
#define AI_RunToPadPreset_LENGTH                                 1
#define AI_WalkToPad_LENGTH                                      3
#define AI_SprintToPad_LENGTH                                    3
#define AI_StartPatrol_LENGTH                                    2
#define AI_Surrender_LENGTH                                      1
#define AI_RemoveMe_LENGTH                                       1
#define AI_ChrRemoveInstant_LENGTH                               2
#define AI_TRYTriggeringAlarmAtPad_LENGTH                        4
#define AI_AlarmOn_LENGTH                                        1
#define AI_AlarmOff_LENGTH                                       1
#define AI_TRYRunFromBond_LENGTH                                 2
#define AI_TRYRunToBond_LENGTH                                   2
#define AI_TRYWalkToBond_LENGTH                                  2
#define AI_TRYSprintToBond_LENGTH                                2
#define AI_TRYFindCover_LENGTH                                   2
#define AI_TRYRunToChr_LENGTH                                    3
#define AI_TRYWalkToChr_LENGTH                                   3
#define AI_TRYSprintToChr_LENGTH                                 3
#define AI_IFImOnPatrolOrStopped_LENGTH                          2
#define AI_IFChrDyingOrDead_LENGTH                               3
#define AI_IFChrDoesNotExist_LENGTH                              3
#define AI_IFISeeBond_LENGTH                                     2
#define AI_SetNewRandom_LENGTH                                   1
#define AI_IFRandomLessThan_LENGTH                               3
#define AI_IFRandomGreaterThan_LENGTH                            3
#define AI_IFICanHearAlarm_LENGTH                                2
#define AI_IFAlarmIsOn_LENGTH                                    2
#define AI_IFGasIsLeaking_LENGTH                                 2
#define AI_IFIHeardBond_LENGTH                                   2
#define AI_IFISeeSomeoneShot_LENGTH                              2
#define AI_IFISeeSomeoneDie_LENGTH                               2
#define AI_IFICouldSeeBond_LENGTH                                2
#define AI_IFICouldSeeBondsStan_LENGTH                           2
#define AI_IFIWasShotRecently_LENGTH                             2
#define AI_IFIHeardBondRecently_LENGTH                           2
#define AI_IFImInRoomWithChr_LENGTH                              3
#define AI_IFIveNotBeenSeen_LENGTH                               2
#define AI_IFImOnScreen_LENGTH                                   2
#define AI_IFMyRoomIsOnScreen_LENGTH                             2
#define AI_IFRoomWithPadIsOnScreen_LENGTH                        4
#define AI_IFImTargetedByBond_LENGTH                             2
#define AI_IFBondMissedMe_LENGTH                                 2
#define AI_IFMyAngleToBondLessThan_LENGTH                        3
#define AI_IFMyAngleToBondGreaterThan_LENGTH                     3
#define AI_IFMyAngleFromBondLessThan_LENGTH                      3
#define AI_IFMyAngleFromBondGreaterThan_LENGTH                   3
#define AI_IFMyDistanceToBondLessThanDecimeter_LENGTH            4
#define AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH         4
#define AI_IFChrDistanceToPadLessThanDecimeter_LENGTH            7
#define AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH         7
#define AI_IFMyDistanceToChrLessThanDecimeter_LENGTH             5
#define AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH          5
#define AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH 4
#define AI_IFBondDistanceToPadLessThanDecimeter_LENGTH           6
#define AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH        6
#define AI_IFChrInRoomWithPad_LENGTH                             5
#define AI_IFBondInRoomWithPad_LENGTH                            4
#define AI_IFBondCollectedObject_LENGTH                          3
#define AI_IFKeyDropped_LENGTH                                   3
#define AI_IFItemIsAttachedToObject_LENGTH                       4
#define AI_IFBondHasItemEquipped_LENGTH                          3
#define AI_IFObjectExists_LENGTH                                 3
#define AI_IFObjectNotDestroyed_LENGTH                           3
#define AI_IFObjectWasActivated_LENGTH                           3
#define AI_IFBondUsedGadgetOnObject_LENGTH                       3
#define AI_ActivateObject_LENGTH                                 2
#define AI_DestroyObject_LENGTH                                  2
#define AI_DropObject_LENGTH                                     2
#define AI_ChrDropAllConcealedItems_LENGTH                       2
#define AI_ChrDropAllHeldItems_LENGTH                            2
#define AI_BondCollectObject_LENGTH                              2
#define AI_ChrEquipObject_LENGTH                                 3
#define AI_MoveObject_LENGTH                                     4
#define AI_DoorOpen_LENGTH                                       2
#define AI_DoorClose_LENGTH                                      2
#define AI_IFDoorStateEqual_LENGTH                               4
#define AI_IFDoorHasBeenOpenedBefore_LENGTH                      3
#define AI_DoorSetLock_LENGTH                                    3
#define AI_DoorUnsetLock_LENGTH                                  3
#define AI_IFDoorLockEqual_LENGTH                                4
#define AI_IFObjectiveNumComplete_LENGTH                         3
#define AI_TRYUnknown6e_LENGTH                                   3
#define AI_TRYUnknown6f_LENGTH                                   3
#define AI_IFGameDifficultyLessThan_LENGTH                       3
#define AI_IFGameDifficultyGreaterThan_LENGTH                    3
#define AI_IFMissionTimeLessThan_LENGTH                          4
#define AI_IFMissionTimeGreaterThan_LENGTH                       4
#define AI_IFSystemPowerTimeLessThan_LENGTH                      4
#define AI_IFSystemPowerTimeGreaterThan_LENGTH                   4
#define AI_IFLevelIdLessThan_LENGTH                              3
#define AI_IFLevelIdGreaterThan_LENGTH                           3
#define AI_IFMyNumArghsLessThan_LENGTH                           3
#define AI_IFMyNumArghsGreaterThan_LENGTH                        3
#define AI_IFMyNumCloseArghsLessThan_LENGTH                      3
#define AI_IFMyNumCloseArghsGreaterThan_LENGTH                   3
#define AI_IFChrHealthLessThan_LENGTH                            4
#define AI_IFChrHealthGreaterThan_LENGTH                         4
#define AI_IFChrWasDamagedSinceLastCheck_LENGTH                  3
#define AI_IFBondHealthLessThan_LENGTH                           3
#define AI_IFBondHealthGreaterThan_LENGTH                        3
#define AI_SetMyMorale_LENGTH                                    2
#define AI_AddToMyMorale_LENGTH                                  2
#define AI_SubtractFromMyMorale_LENGTH                           2
#define AI_IFMyMoraleLessThan_LENGTH                             3
#define AI_IFMyMoraleLessThanRandom_LENGTH                       2
#define AI_SetMyAlertness_LENGTH                                 2
#define AI_AddToMyAlertness_LENGTH                               2
#define AI_SubtractFromMyAlertness_LENGTH                        2
#define AI_IFMyAlertnessLessThan_LENGTH                          3
#define AI_IFMyAlertnessLessThanRandom_LENGTH                    2
#define AI_SetMyHearingScale_LENGTH                              3
#define AI_SetMyVisionRange_LENGTH                               2
#define AI_SetMyGrenadeProbability_LENGTH                        2
#define AI_SetMyChrNum_LENGTH                                    2
#define AI_SetMyHealthTotal_LENGTH                               3
#define AI_SetMyArmour_LENGTH                                    3
#define AI_SetMySpeedRating_LENGTH                               2
#define AI_SetMyArghRating_LENGTH                                2
#define AI_SetMyAccuracyRating_LENGTH                            2
#define AI_SetMyFlags2_LENGTH                                    2
#define AI_UnsetMyFlags2_LENGTH                                  2
#define AI_IFMyFlags2Has_LENGTH                                  3
#define AI_SetChrBitfield_LENGTH                                 3
#define AI_UnsetChrBitfield_LENGTH                               3
#define AI_IFChrBitfieldHas_LENGTH                               4
#define AI_SetObjectiveBitfield_LENGTH                           5
#define AI_UnsetObjectiveBitfield_LENGTH                         5
#define AI_IFObjectiveBitfieldHas_LENGTH                         6
#define AI_SetMychrflags_LENGTH                                  5
#define AI_UnsetMychrflags_LENGTH                                5
#define AI_IFMychrflagsHas_LENGTH                                6
#define AI_SetChrchrflags_LENGTH                                 6
#define AI_UnsetChrchrflags_LENGTH                               6
#define AI_IFChrchrflagsHas_LENGTH                               7
#define AI_SetObjectFlags_LENGTH                                 6
#define AI_UnsetObjectFlags_LENGTH                               6
#define AI_IFObjectFlagsHas_LENGTH                               7
#define AI_SetObjectFlags2_LENGTH                                6
#define AI_UnsetObjectFlags2_LENGTH                              6
#define AI_IFObjectFlags2Has_LENGTH                              7
#define AI_SetMyChrPreset_LENGTH                                 2
#define AI_SetChrChrPreset_LENGTH                                3
#define AI_SetMyPadPreset_LENGTH                                 3
#define AI_SetChrPadPreset_LENGTH                                4
#define AI_MyTimerStart_LENGTH                                   1
#define AI_MyTimerReset_LENGTH                                   1
#define AI_MyTimerPause_LENGTH                                   1
#define AI_MyTimerResume_LENGTH                                  1
#define AI_IFMyTimerIsNotRunning_LENGTH                          2
#define AI_IFMyTimerLessThanTicks_LENGTH                         5
#define AI_IFMyTimerGreaterThanTicks_LENGTH                      5
#define AI_HudCountdownShow_LENGTH                               1
#define AI_HudCountdownHide_LENGTH                               1
#define AI_HudCountdownSet_LENGTH                                3
#define AI_HudCountdownStop_LENGTH                               1
#define AI_HudCountdownStart_LENGTH                              1
#define AI_IFHudCountdownIsNotRunning_LENGTH                     2
#define AI_IFHudCountdownLessThan_LENGTH                         4
#define AI_IFHudCountdownGreaterThan_LENGTH                      4
#define AI_TRYSpawningChrAtPad_LENGTH                            12
#define AI_TRYSpawningChrNextToChr_LENGTH                        11
#define AI_TRYGiveMeItem_LENGTH                                  9
#define AI_TRYGiveMeHat_LENGTH                                   8
#define AI_TRYCloningChr_LENGTH                                  5
#define AI_TextPrintBottom_LENGTH                                3
#define AI_TextPrintTop_LENGTH                                   3
#define AI_SfxPlay_LENGTH                                        4
#define AI_SfxEmitFromObject_LENGTH                              5
#define AI_SfxEmitFromPad_LENGTH                                 6
#define AI_SfxSetChannelVolume_LENGTH                            6
#define AI_SfxFadeChannelVolume_LENGTH                           6
#define AI_SfxStopChannel_LENGTH                                 2
#define AI_IFSfxChannelVolumeLessThan_LENGTH                     5
#define AI_VehicleStartPath_LENGTH                               2
#define AI_VehicleSpeed_LENGTH                                   5
#define AI_AircraftRotorSpeed_LENGTH                             5
#define AI_IFCameraIsInIntro_LENGTH                              2
#define AI_IFCameraIsInBondSwirl_LENGTH                          2
#define AI_TvChangeScreenBank_LENGTH                             4
#define AI_IFBondInTank_LENGTH                                   /*canonical name*/ 2
#define AI_EndLevel_LENGTH                                       /* canonical name */ 1
#define AI_CameraReturnToBond_LENGTH                             1
#define AI_CameraLookAtBondFromPad_LENGTH                        3
#define AI_CameraSwitch_LENGTH                                   6
#define AI_IFBondYPosLessThan_LENGTH                             4
#define AI_BondDisableControl_LENGTH                             2
#define AI_BondEnableControl_LENGTH                              1
#define AI_TRYTeleportingChrToPad_LENGTH                         5
#define AI_ScreenFadeToBlack_LENGTH                              1
#define AI_ScreenFadeFromBlack_LENGTH                            1
#define AI_IFScreenFadeCompleted_LENGTH                          2
#define AI_HideAllChrs_LENGTH                                    1
#define AI_ShowAllChrs_LENGTH                                    1
#define AI_DoorOpenInstant_LENGTH                                2
#define AI_ChrRemoveItemInHand_LENGTH                            3
#define AI_IfNumberOfActivePlayersLessThan_LENGTH                3
#define AI_IFBondItemTotalAmmoLessThan_LENGTH                    4
#define AI_BondEquipItem_LENGTH                                  2
#define AI_BondEquipItemCinema_LENGTH                            2
#define AI_BondSetLockedVelocity_LENGTH                          3
#define AI_IFObjectInRoomWithPad_LENGTH                          5
#define AI_SwitchSky_LENGTH                                      1
#define AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH           1
#define AI_IFBondIsDead_LENGTH                                   2
#define AI_BondDisableDamageAndPickups_LENGTH                    1
#define AI_BondHideWeapons_LENGTH                                1
#define AI_CameraOrbitPad_LENGTH                                 13
#define AI_CreditsRoll_LENGTH                                    1
#define AI_IFCreditsHasCompleted_LENGTH                          2
#define AI_IFObjectiveAllCompleted_LENGTH                        2
#define AI_IFFolderActorIsEqual_LENGTH                           3
#define AI_IFBondDamageAndPickupsDisabled_LENGTH                 2
#define AI_MusicPlaySlot_LENGTH                                  4
#define AI_MusicStopSlot_LENGTH                                  2
#define AI_TriggerExplosionsAroundBond_LENGTH                    1
#define AI_IFKilledCiviliansGreaterThan_LENGTH                   3
#define AI_IFChrWasShotSinceLastCheck_LENGTH                     3
#define AI_BondKilledInAction_LENGTH                             1
#define AI_RaiseArms_LENGTH                                      1
#define AI_GasLeakAndFadeFog_LENGTH                              1
#define AI_ObjectRocketLaunch_LENGTH                             2
#pragma endregion //w

int AI_CMD_LENGTHS_ToInt[] = {
    AI_GotoNext_LENGTH,
    AI_GotoFirst_LENGTH,
    AI_Label_LENGTH,
    AI_Yield_LENGTH,
    AI_EndList_LENGTH,
    AI_SetChrAiList_LENGTH,
    AI_SetReturnAiList_LENGTH,
    AI_Return_LENGTH,
    AI_Stop_LENGTH,
    AI_Kneel_LENGTH,
    AI_PlayAnimation_LENGTH,
    AI_IFPlayingAnimation_LENGTH,
    AI_PointAtBond_LENGTH,
    AI_LookSurprised_LENGTH,
    AI_TRYSidestepping_LENGTH,
    AI_TRYSideHopping_LENGTH,
    AI_TRYSideRunning_LENGTH,
    AI_TRYFiringWalk_LENGTH,
    AI_TRYFiringRun_LENGTH,
    AI_TRYFiringRoll_LENGTH,
    AI_TRYFireOrAimAtTarget_LENGTH,
    AI_TRYFireOrAimAtTargetKneel_LENGTH,
    AI_TRYFireOrAimAtTargetUpdate_LENGTH,
    AI_TRYFacingTarget_LENGTH,
    AI_HitChrWithItem_LENGTH,
    AI_ChrHitChr_LENGTH,
    AI_TRYThrowingGrenade_LENGTH,
    AI_TRYDroppingItem_LENGTH,
    AI_RunToPad_LENGTH,
    AI_RunToPadPreset_LENGTH,
    AI_WalkToPad_LENGTH,
    AI_SprintToPad_LENGTH,
    AI_StartPatrol_LENGTH,
    AI_Surrender_LENGTH,
    AI_RemoveMe_LENGTH,
    AI_ChrRemoveInstant_LENGTH,
    AI_TRYTriggeringAlarmAtPad_LENGTH,
    AI_AlarmOn_LENGTH,
    AI_AlarmOff_LENGTH,
    AI_TRYRunFromBond_LENGTH,
    AI_TRYRunToBond_LENGTH,
    AI_TRYWalkToBond_LENGTH,
    AI_TRYSprintToBond_LENGTH,
    AI_TRYFindCover_LENGTH,
    AI_TRYRunToChr_LENGTH,
    AI_TRYWalkToChr_LENGTH,
    AI_TRYSprintToChr_LENGTH,
    AI_IFImOnPatrolOrStopped_LENGTH,
    AI_IFChrDyingOrDead_LENGTH,
    AI_IFChrDoesNotExist_LENGTH,
    AI_IFISeeBond_LENGTH,
    AI_SetNewRandom_LENGTH,
    AI_IFRandomLessThan_LENGTH,
    AI_IFRandomGreaterThan_LENGTH,
    AI_IFICanHearAlarm_LENGTH,
    AI_IFAlarmIsOn_LENGTH,
    AI_IFGasIsLeaking_LENGTH,
    AI_IFIHeardBond_LENGTH,
    AI_IFISeeSomeoneShot_LENGTH,
    AI_IFISeeSomeoneDie_LENGTH,
    AI_IFICouldSeeBond_LENGTH,
    AI_IFICouldSeeBondsStan_LENGTH,
    AI_IFIWasShotRecently_LENGTH,
    AI_IFIHeardBondRecently_LENGTH,
    AI_IFImInRoomWithChr_LENGTH,
    AI_IFIveNotBeenSeen_LENGTH,
    AI_IFImOnScreen_LENGTH,
    AI_IFMyRoomIsOnScreen_LENGTH,
    AI_IFRoomWithPadIsOnScreen_LENGTH,
    AI_IFImTargetedByBond_LENGTH,
    AI_IFBondMissedMe_LENGTH,
    AI_IFMyAngleToBondLessThan_LENGTH,
    AI_IFMyAngleToBondGreaterThan_LENGTH,
    AI_IFMyAngleFromBondLessThan_LENGTH,
    AI_IFMyAngleFromBondGreaterThan_LENGTH,
    AI_IFMyDistanceToBondLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH,
    AI_IFBondDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFChrInRoomWithPad_LENGTH,
    AI_IFBondInRoomWithPad_LENGTH,
    AI_IFBondCollectedObject_LENGTH,
    AI_IFKeyDropped_LENGTH,
    AI_IFItemIsAttachedToObject_LENGTH,
    AI_IFBondHasItemEquipped_LENGTH,
    AI_IFObjectExists_LENGTH,
    AI_IFObjectNotDestroyed_LENGTH,
    AI_IFObjectWasActivated_LENGTH,
    AI_IFBondUsedGadgetOnObject_LENGTH,
    AI_ActivateObject_LENGTH,
    AI_DestroyObject_LENGTH,
    AI_DropObject_LENGTH,
    AI_ChrDropAllConcealedItems_LENGTH,
    AI_ChrDropAllHeldItems_LENGTH,
    AI_BondCollectObject_LENGTH,
    AI_ChrEquipObject_LENGTH,
    AI_MoveObject_LENGTH,
    AI_DoorOpen_LENGTH,
    AI_DoorClose_LENGTH,
    AI_IFDoorStateEqual_LENGTH,
    AI_IFDoorHasBeenOpenedBefore_LENGTH,
    AI_DoorSetLock_LENGTH,
    AI_DoorUnsetLock_LENGTH,
    AI_IFDoorLockEqual_LENGTH,
    AI_IFObjectiveNumComplete_LENGTH,
    AI_TRYUnknown6e_LENGTH,
    AI_TRYUnknown6f_LENGTH,
    AI_IFGameDifficultyLessThan_LENGTH,
    AI_IFGameDifficultyGreaterThan_LENGTH,
    AI_IFMissionTimeLessThan_LENGTH,
    AI_IFMissionTimeGreaterThan_LENGTH,
    AI_IFSystemPowerTimeLessThan_LENGTH,
    AI_IFSystemPowerTimeGreaterThan_LENGTH,
    AI_IFLevelIdLessThan_LENGTH,
    AI_IFLevelIdGreaterThan_LENGTH,
    AI_IFMyNumArghsLessThan_LENGTH,
    AI_IFMyNumArghsGreaterThan_LENGTH,
    AI_IFMyNumCloseArghsLessThan_LENGTH,
    AI_IFMyNumCloseArghsGreaterThan_LENGTH,
    AI_IFChrHealthLessThan_LENGTH,
    AI_IFChrHealthGreaterThan_LENGTH,
    AI_IFChrWasDamagedSinceLastCheck_LENGTH,
    AI_IFBondHealthLessThan_LENGTH,
    AI_IFBondHealthGreaterThan_LENGTH,
    AI_SetMyMorale_LENGTH,
    AI_AddToMyMorale_LENGTH,
    AI_SubtractFromMyMorale_LENGTH,
    AI_IFMyMoraleLessThan_LENGTH,
    AI_IFMyMoraleLessThanRandom_LENGTH,
    AI_SetMyAlertness_LENGTH,
    AI_AddToMyAlertness_LENGTH,
    AI_SubtractFromMyAlertness_LENGTH,
    AI_IFMyAlertnessLessThan_LENGTH,
    AI_IFMyAlertnessLessThanRandom_LENGTH,
    AI_SetMyHearingScale_LENGTH,
    AI_SetMyVisionRange_LENGTH,
    AI_SetMyGrenadeProbability_LENGTH,
    AI_SetMyChrNum_LENGTH,
    AI_SetMyHealthTotal_LENGTH,
    AI_SetMyArmour_LENGTH,
    AI_SetMySpeedRating_LENGTH,
    AI_SetMyArghRating_LENGTH,
    AI_SetMyAccuracyRating_LENGTH,
    AI_SetMyFlags2_LENGTH,
    AI_UnsetMyFlags2_LENGTH,
    AI_IFMyFlags2Has_LENGTH,
    AI_SetChrBitfield_LENGTH,
    AI_UnsetChrBitfield_LENGTH,
    AI_IFChrBitfieldHas_LENGTH,
    AI_SetObjectiveBitfield_LENGTH,
    AI_UnsetObjectiveBitfield_LENGTH,
    AI_IFObjectiveBitfieldHas_LENGTH,
    AI_SetMychrflags_LENGTH,
    AI_UnsetMychrflags_LENGTH,
    AI_IFMychrflagsHas_LENGTH,
    AI_SetChrchrflags_LENGTH,
    AI_UnsetChrchrflags_LENGTH,
    AI_IFChrchrflagsHas_LENGTH,
    AI_SetObjectFlags_LENGTH,
    AI_UnsetObjectFlags_LENGTH,
    AI_IFObjectFlagsHas_LENGTH,
    AI_SetObjectFlags2_LENGTH,
    AI_UnsetObjectFlags2_LENGTH,
    AI_IFObjectFlags2Has_LENGTH,
    AI_SetMyChrPreset_LENGTH,
    AI_SetChrChrPreset_LENGTH,
    AI_SetMyPadPreset_LENGTH,
    AI_SetChrPadPreset_LENGTH,
    0,
    AI_MyTimerStart_LENGTH,
    AI_MyTimerReset_LENGTH,
    AI_MyTimerPause_LENGTH,
    AI_MyTimerResume_LENGTH,
    AI_IFMyTimerIsNotRunning_LENGTH,
    AI_IFMyTimerLessThanTicks_LENGTH,
    AI_IFMyTimerGreaterThanTicks_LENGTH,
    AI_HudCountdownShow_LENGTH,
    AI_HudCountdownHide_LENGTH,
    AI_HudCountdownSet_LENGTH,
    AI_HudCountdownStop_LENGTH,
    AI_HudCountdownStart_LENGTH,
    AI_IFHudCountdownIsNotRunning_LENGTH,
    AI_IFHudCountdownLessThan_LENGTH,
    AI_IFHudCountdownGreaterThan_LENGTH,
    AI_TRYSpawningChrAtPad_LENGTH,
    AI_TRYSpawningChrNextToChr_LENGTH,
    AI_TRYGiveMeItem_LENGTH,
    AI_TRYGiveMeHat_LENGTH,
    AI_TRYCloningChr_LENGTH,
    AI_TextPrintBottom_LENGTH,
    AI_TextPrintTop_LENGTH,
    AI_SfxPlay_LENGTH,
    AI_SfxEmitFromObject_LENGTH,
    AI_SfxEmitFromPad_LENGTH,
    AI_SfxSetChannelVolume_LENGTH,
    AI_SfxFadeChannelVolume_LENGTH,
    AI_SfxStopChannel_LENGTH,
    AI_IFSfxChannelVolumeLessThan_LENGTH,
    AI_VehicleStartPath_LENGTH,
    AI_VehicleSpeed_LENGTH,
    AI_AircraftRotorSpeed_LENGTH,
    AI_IFCameraIsInIntro_LENGTH,
    AI_IFCameraIsInBondSwirl_LENGTH,
    AI_TvChangeScreenBank_LENGTH,
    AI_IFBondInTank_LENGTH,
    AI_EndLevel_LENGTH,
    AI_CameraReturnToBond_LENGTH,
    AI_CameraLookAtBondFromPad_LENGTH,
    AI_CameraSwitch_LENGTH,
    AI_IFBondYPosLessThan_LENGTH,
    AI_BondDisableControl_LENGTH,
    AI_BondEnableControl_LENGTH,
    AI_TRYTeleportingChrToPad_LENGTH,
    AI_ScreenFadeToBlack_LENGTH,
    AI_ScreenFadeFromBlack_LENGTH,
    AI_IFScreenFadeCompleted_LENGTH,
    AI_HideAllChrs_LENGTH,
    AI_ShowAllChrs_LENGTH,
    AI_DoorOpenInstant_LENGTH,
    AI_ChrRemoveItemInHand_LENGTH,
    AI_IfNumberOfActivePlayersLessThan_LENGTH,
    AI_IFBondItemTotalAmmoLessThan_LENGTH,
    AI_BondEquipItem_LENGTH,
    AI_BondEquipItemCinema_LENGTH,
    AI_BondSetLockedVelocity_LENGTH,
    AI_IFObjectInRoomWithPad_LENGTH,
    AI_IFImFiringAndLockedForward_LENGTH,
    AI_IFImFiring_LENGTH,
    AI_SwitchSky_LENGTH,
    AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH,
    AI_IFBondIsDead_LENGTH,
    AI_BondDisableDamageAndPickups_LENGTH,
    AI_BondHideWeapons_LENGTH,
    AI_CameraOrbitPad_LENGTH,
    AI_CreditsRoll_LENGTH,
    AI_IFCreditsHasCompleted_LENGTH,
    AI_IFObjectiveAllCompleted_LENGTH,
    AI_IFFolderActorIsEqual_LENGTH,
    AI_IFBondDamageAndPickupsDisabled_LENGTH,
    AI_MusicPlaySlot_LENGTH,
    AI_MusicStopSlot_LENGTH,
    AI_TriggerExplosionsAroundBond_LENGTH,
    AI_IFKilledCiviliansGreaterThan_LENGTH,
    AI_IFChrWasShotSinceLastCheck_LENGTH,
    AI_BondKilledInAction_LENGTH,
    AI_RaiseArms_LENGTH,
    AI_GasLeakAndFadeFog_LENGTH,
    AI_ObjectRocketLaunch_LENGTH};

typedef enum AI_CMD
{
    AI_GotoNext,
    AI_GotoFirst,
    AI_Label,
    AI_Yield,
    AI_EndList,
    AI_SetChrAiList,
    AI_SetReturnAiList,
    AI_Return,
    AI_Stop,
    AI_Kneel,
    AI_PlayAnimation,
    AI_IFPlayingAnimation,
    AI_PointAtBond,
    AI_LookSurprised,
    AI_TRYSidestepping,
    AI_TRYSideHopping,
    AI_TRYSideRunning,
    AI_TRYFiringWalk,
    AI_TRYFiringRun,
    AI_TRYFiringRoll,
    AI_TRYFireOrAimAtTarget,
    AI_TRYFireOrAimAtTargetKneel,
    AI_TRYFireOrAimAtTargetUpdate,
    AI_TRYFacingTarget,
    AI_HitChrWithItem,
    AI_ChrHitChr,
    AI_TRYThrowingGrenade,
    AI_TRYDroppingItem,
    AI_RunToPad,
    AI_RunToPadPreset,
    AI_WalkToPad,
    AI_SprintToPad,
    AI_StartPatrol,
    AI_Surrender,
    AI_RemoveMe,
    AI_ChrRemoveInstant,
    AI_TRYTriggeringAlarmAtPad,
    AI_AlarmOn,
    AI_AlarmOff,
    AI_TRYRunFromBond,
    AI_TRYRunToBond,
    AI_TRYWalkToBond,
    AI_TRYSprintToBond,
    AI_TRYFindCover,
    AI_TRYRunToChr,
    AI_TRYWalkToChr,
    AI_TRYSprintToChr,
    AI_IFImOnPatrolOrStopped,
    AI_IFChrDyingOrDead,
    AI_IFChrDoesNotExist,
    AI_IFISeeBond,
    AI_SetNewRandom,
    AI_IFRandomLessThan,
    AI_IFRandomGreaterThan,
    AI_IFICanHearAlarm,
    AI_IFAlarmIsOn,
    AI_IFGasIsLeaking,
    AI_IFIHeardBond,
    AI_IFISeeSomeoneShot,
    AI_IFISeeSomeoneDie,
    AI_IFICouldSeeBond,
    AI_IFICouldSeeBondsStan,
    AI_IFIWasShotRecently,
    AI_IFIHeardBondRecently,
    AI_IFImInRoomWithChr,
    AI_IFIveNotBeenSeen,
    AI_IFImOnScreen,
    AI_IFMyRoomIsOnScreen,
    AI_IFRoomWithPadIsOnScreen,
    AI_IFImTargetedByBond,
    AI_IFBondMissedMe,
    AI_IFMyAngleToBondLessThan,
    AI_IFMyAngleToBondGreaterThan,
    AI_IFMyAngleFromBondLessThan,
    AI_IFMyAngleFromBondGreaterThan,
    AI_IFMyDistanceToBondLessThanDecimeter,
    AI_IFMyDistanceToBondGreaterThanDecimeter,
    AI_IFChrDistanceToPadLessThanDecimeter,
    AI_IFChrDistanceToPadGreaterThanDecimeter,
    AI_IFMyDistanceToChrLessThanDecimeter,
    AI_IFMyDistanceToChrGreaterThanDecimeter,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter,
    AI_IFBondDistanceToPadLessThanDecimeter,
    AI_IFBondDistanceToPadGreaterThanDecimeter,
    AI_IFChrInRoomWithPad,
    AI_IFBondInRoomWithPad,
    AI_IFBondCollectedObject,
    AI_IFKeyDropped,
    AI_IFItemIsAttachedToObject,
    AI_IFBondHasItemEquipped,
    AI_IFObjectExists,
    AI_IFObjectNotDestroyed,
    AI_IFObjectWasActivated,
    AI_IFBondUsedGadgetOnObject,
    AI_ActivateObject,
    AI_DestroyObject,
    AI_DropObject,
    AI_ChrDropAllConcealedItems,
    AI_ChrDropAllHeldItems,
    AI_BondCollectObject,
    AI_ChrEquipObject,
    AI_MoveObject,
    AI_DoorOpen,
    AI_DoorClose,
    AI_IFDoorStateEqual,
    AI_IFDoorHasBeenOpenedBefore,
    AI_DoorSetLock,
    AI_DoorUnsetLock,
    AI_IFDoorLockEqual,
    AI_IFObjectiveNumComplete,
    AI_TRYUnknown6e,
    AI_TRYUnknown6f,
    AI_IFGameDifficultyLessThan,
    AI_IFGameDifficultyGreaterThan,
    AI_IFMissionTimeLessThan,
    AI_IFMissionTimeGreaterThan,
    AI_IFSystemPowerTimeLessThan,
    AI_IFSystemPowerTimeGreaterThan,
    AI_IFLevelIdLessThan,
    AI_IFLevelIdGreaterThan,
    AI_IFMyNumArghsLessThan,
    AI_IFMyNumArghsGreaterThan,
    AI_IFMyNumCloseArghsLessThan,
    AI_IFMyNumCloseArghsGreaterThan,
    AI_IFChrHealthLessThan,
    AI_IFChrHealthGreaterThan,
    AI_IFChrWasDamagedSinceLastCheck,
    AI_IFBondHealthLessThan,
    AI_IFBondHealthGreaterThan,
    AI_SetMyMorale,
    AI_AddToMyMorale,
    AI_SubtractFromMyMorale,
    AI_IFMyMoraleLessThan,
    AI_IFMyMoraleLessThanRandom,
    AI_SetMyAlertness,
    AI_AddToMyAlertness,
    AI_SubtractFromMyAlertness,
    AI_IFMyAlertnessLessThan,
    AI_IFMyAlertnessLessThanRandom,
    AI_SetMyHearingScale,
    AI_SetMyVisionRange,
    AI_SetMyGrenadeProbability,
    AI_SetMyChrNum,
    AI_SetMyHealthTotal,
    AI_SetMyArmour,
    AI_SetMySpeedRating,
    AI_SetMyArghRating,
    AI_SetMyAccuracyRating,
    AI_SetMyFlags2,
    AI_UnsetMyFlags2,
    AI_IFMyFlags2Has,
    AI_SetChrBitfield,
    AI_UnsetChrBitfield,
    AI_IFChrBitfieldHas,
    AI_SetObjectiveBitfield,
    AI_UnsetObjectiveBitfield,
    AI_IFObjectiveBitfieldHas,
    AI_SetMychrflags,
    AI_UnsetMychrflags,
    AI_IFMychrflagsHas,
    AI_SetChrchrflags,
    AI_UnsetChrchrflags,
    AI_IFChrchrflagsHas,
    AI_SetObjectFlags,
    AI_UnsetObjectFlags,
    AI_IFObjectFlagsHas,
    AI_SetObjectFlags2,
    AI_UnsetObjectFlags2,
    AI_IFObjectFlags2Has,
    AI_SetMyChrPreset,
    AI_SetChrChrPreset,
    AI_SetMyPadPreset,
    AI_SetChrPadPreset,
    AI_PRINT,
    AI_MyTimerStart,
    AI_MyTimerReset,
    AI_MyTimerPause,
    AI_MyTimerResume,
    AI_IFMyTimerIsNotRunning,
    AI_IFMyTimerLessThanTicks,
    AI_IFMyTimerGreaterThanTicks,
    AI_HudCountdownShow,
    AI_HudCountdownHide,
    AI_HudCountdownSet,
    AI_HudCountdownStop,
    AI_HudCountdownStart,
    AI_IFHudCountdownIsNotRunning,
    AI_IFHudCountdownLessThan,
    AI_IFHudCountdownGreaterThan,
    AI_TRYSpawningChrAtPad,
    AI_TRYSpawningChrNextToChr,
    AI_TRYGiveMeItem,
    AI_TRYGiveMeHat,
    AI_TRYCloningChr,
    AI_TextPrintBottom,
    AI_TextPrintTop,
    AI_SfxPlay,
    AI_SfxEmitFromObject,
    AI_SfxEmitFromPad,
    AI_SfxSetChannelVolume,
    AI_SfxFadeChannelVolume,
    AI_SfxStopChannel,
    AI_IFSfxChannelVolumeLessThan,
    AI_VehicleStartPath,
    AI_VehicleSpeed,
    AI_AircraftRotorSpeed,
    AI_IFCameraIsInIntro,
    AI_IFCameraIsInBondSwirl,
    AI_TvChangeScreenBank,
    AI_IFBondInTank,
    AI_EndLevel,
    AI_CameraReturnToBond,
    AI_CameraLookAtBondFromPad,
    AI_CameraSwitch,
    AI_IFBondYPosLessThan,
    AI_BondDisableControl,
    AI_BondEnableControl,
    AI_TRYTeleportingChrToPad,
    AI_ScreenFadeToBlack,
    AI_ScreenFadeFromBlack,
    AI_IFScreenFadeCompleted,
    AI_HideAllChrs,
    AI_ShowAllChrs,
    AI_DoorOpenInstant,
    AI_ChrRemoveItemInHand,
    AI_IfNumberOfActivePlayersLessThan,
    AI_IFBondItemTotalAmmoLessThan,
    AI_BondEquipItem,
    AI_BondEquipItemCinema,
    AI_BondSetLockedVelocity,
    AI_IFObjectInRoomWithPad,
    AI_IFImFiringAndLockedForward,
    AI_IFImFiring,
    AI_SwitchSky,
    AI_TriggerFadeAndExitLevelOnButtonPress,
    AI_IFBondIsDead,
    AI_BondDisableDamageAndPickups,
    AI_BondHideWeapons,
    AI_CameraOrbitPad,
    AI_CreditsRoll,
    AI_IFCreditsHasCompleted,
    AI_IFObjectiveAllCompleted,
    AI_IFFolderActorIsEqual,
    AI_IFBondDamageAndPickupsDisabled,
    AI_MusicPlaySlot,
    AI_MusicStopSlot,
    AI_TriggerExplosionsAroundBond,
    AI_IFKilledCiviliansGreaterThan,
    AI_IFChrWasShotSinceLastCheck,
    AI_BondKilledInAction,
    AI_RaiseArms,
    AI_GasLeakAndFadeFog,
    AI_ObjectRocketLaunch,
    AI_CMD_COUNT
} AI_CMD;

char *AI_CMD_ToString[] = {
    "GotoNext",
    "GotoFirst",
    "Label",
    "Yield",
    "EndList",
    "SetChrAiList",
    "SetReturnAiList",
    "Return",
    "Stop",
    "Kneel",
    "PlayAnimation",
    "IFPlayingAnimation",
    "PointAtBond",
    "LookSurprised",
    "TRYSidestepping",
    "TRYSideHopping",
    "TRYSideRunning",
    "TRYFiringWalk",
    "TRYFiringRun",
    "TRYFiringRoll",
    "TRYFireOrAimAtTarget",
    "TRYFireOrAimAtTargetKneel",
    "TRYFireOrAimAtTargetUpdate",
    "TRYFacingTarget",
    "HitChrWithItem",
    "ChrHitChr",
    "TRYThrowingGrenade",
    "TRYDroppingItem",
    "RunToPad",
    "RunToPadPreset",
    "WalkToPad",
    "SprintToPad",
    "StartPatrol",
    "Surrender",
    "RemoveMe",
    "ChrRemoveInstant",
    "TRYTriggeringAlarmAtPad",
    "AlarmOn",
    "AlarmOff",
    "TRYRunFromBond",
    "TRYRunToBond",
    "TRYWalkToBond",
    "TRYSprintToBond",
    "TRYFindCover",
    "TRYRunToChr",
    "TRYWalkToChr",
    "TRYSprintToChr",
    "IFImOnPatrolOrStopped",
    "IFChrDyingOrDead",
    "IFChrDoesNotExist",
    "IFISeeBond",
    "SetNewRandom",
    "IFRandomLessThan",
    "IFRandomGreaterThan",
    "IFICanHearAlarm",
    "IFAlarmIsOn",
    "IFGasIsLeaking",
    "IFIHeardBond",
    "IFISeeSomeoneShot",
    "IFISeeSomeoneDie",
    "IFICouldSeeBond",
    "IFICouldSeeBondsStan",
    "IFIWasShotRecently",
    "IFIHeardBondRecently",
    "IFImInRoomWithChr",
    "IFIveNotBeenSeen",
    "IFImOnScreen",
    "IFMyRoomIsOnScreen",
    "IFRoomWithPadIsOnScreen",
    "IFImTargetedByBond",
    "IFBondMissedMe",
    "IFMyAngleToBondLessThan",
    "IFMyAngleToBondGreaterThan",
    "IFMyAngleFromBondLessThan",
    "IFMyAngleFromBondGreaterThan",
    "IFMyDistanceToBondLessThanDecimeter",
    "IFMyDistanceToBondGreaterThanDecimeter",
    "IFChrDistanceToPadLessThanDecimeter",
    "IFChrDistanceToPadGreaterThanDecimeter",
    "IFMyDistanceToChrLessThanDecimeter",
    "IFMyDistanceToChrGreaterThanDecimeter",
    "TRYSettingMyPresetToChrWithinDistanceDecimeter",
    "IFBondDistanceToPadLessThanDecimeter",
    "IFBondDistanceToPadGreaterThanDecimeter",
    "IFChrInRoomWithPad",
    "IFBondInRoomWithPad",
    "IFBondCollectedObject",
    "IFKeyDropped",
    "IFItemIsAttachedToObject",
    "IFBondHasItemEquipped",
    "IFObjectExists",
    "IFObjectNotDestroyed",
    "IFObjectWasActivated",
    "IFBondUsedGadgetOnObject",
    "ActivateObject",
    "DestroyObject",
    "DropObject",
    "ChrDropAllConcealedItems",
    "ChrDropAllHeldItems",
    "BondCollectObject",
    "ChrEquipObject",
    "MoveObject",
    "DoorOpen",
    "DoorClose",
    "IFDoorStateEqual",
    "IFDoorHasBeenOpenedBefore",
    "DoorSetLock",
    "DoorUnsetLock",
    "IFDoorLockEqual",
    "IFObjectiveNumComplete",
    "TRYUnknown6e",
    "TRYUnknown6f",
    "IFGameDifficultyLessThan",
    "IFGameDifficultyGreaterThan",
    "IFMissionTimeLessThan",
    "IFMissionTimeGreaterThan",
    "IFSystemPowerTimeLessThan",
    "IFSystemPowerTimeGreaterThan",
    "IFLevelIdLessThan",
    "IFLevelIdGreaterThan",
    "IFMyNumArghsLessThan",
    "IFMyNumArghsGreaterThan",
    "IFMyNumCloseArghsLessThan",
    "IFMyNumCloseArghsGreaterThan",
    "IFChrHealthLessThan",
    "IFChrHealthGreaterThan",
    "IFChrWasDamagedSinceLastCheck",
    "IFBondHealthLessThan",
    "IFBondHealthGreaterThan",
    "SetMyMorale",
    "AddToMyMorale",
    "SubtractFromMyMorale",
    "IFMyMoraleLessThan",
    "IFMyMoraleLessThanRandom",
    "SetMyAlertness",
    "AddToMyAlertness",
    "SubtractFromMyAlertness",
    "IFMyAlertnessLessThan",
    "IFMyAlertnessLessThanRandom",
    "SetMyHearingScale",
    "SetMyVisionRange",
    "SetMyGrenadeProbability",
    "SetMyChrNum",
    "SetMyHealthTotal",
    "SetMyArmour",
    "SetMySpeedRating",
    "SetMyArghRating",
    "SetMyAccuracyRating",
    "SetMyFlags2",
    "UnsetMyFlags2",
    "IFMyFlags2Has",
    "SetChrBitfield",
    "UnsetChrBitfield",
    "IFChrBitfieldHas",
    "SetObjectiveBitfield",
    "UnsetObjectiveBitfield",
    "IFObjectiveBitfieldHas",
    "SetMychrflags",
    "UnsetMychrflags",
    "IFMychrflagsHas",
    "SetChrchrflags",
    "UnsetChrchrflags",
    "IFChrchrflagsHas",
    "SetObjectFlags",
    "UnsetObjectFlags",
    "IFObjectFlagsHas",
    "SetObjectFlags2",
    "UnsetObjectFlags2",
    "IFObjectFlags2Has",
    "SetMyChrPreset",
    "SetChrChrPreset",
    "SetMyPadPreset",
    "SetChrPadPreset",
    "PRINT",
    "MyTimerStart",
    "MyTimerReset",
    "MyTimerPause",
    "MyTimerResume",
    "IFMyTimerIsNotRunning",
    "IFMyTimerLessThanTicks",
    "IFMyTimerGreaterThanTicks",
    "HudCountdownShow",
    "HudCountdownHide",
    "HudCountdownSet",
    "HudCountdownStop",
    "HudCountdownStart",
    "IFHudCountdownIsNotRunning",
    "IFHudCountdownLessThan",
    "IFHudCountdownGreaterThan",
    "TRYSpawningChrAtPad",
    "TRYSpawningChrNextToChr",
    "TRYGiveMeItem",
    "TRYGiveMeHat",
    "TRYCloningChr",
    "TextPrintBottom",
    "TextPrintTop",
    "SfxPlay",
    "SfxEmitFromObject",
    "SfxEmitFromPad",
    "SfxSetChannelVolume",
    "SfxFadeChannelVolume",
    "SfxStopChannel",
    "IFSfxChannelVolumeLessThan",
    "VehicleStartPath",
    "VehicleSpeed",
    "AircraftRotorSpeed",
    "IFCameraIsInIntro",
    "IFCameraIsInBondSwirl",
    "TvChangeScreenBank",
    "IFBondInTank",
    "EndLevel",
    "CameraReturnToBond",
    "CameraLookAtBondFromPad",
    "CameraSwitch",
    "IFBondYPosLessThan",
    "BondDisableControl",
    "BondEnableControl",
    "TRYTeleportingChrToPad",
    "ScreenFadeToBlack",
    "ScreenFadeFromBlack",
    "IFScreenFadeCompleted",
    "HideAllChrs",
    "ShowAllChrs",
    "DoorOpenInstant",
    "ChrRemoveItemInHand",
    "IfNumberOfActivePlayersLessThan",
    "IFBondItemTotalAmmoLessThan",
    "BondEquipItem",
    "BondEquipItemCinema",
    "BondSetLockedVelocity",
    "IFObjectInRoomWithPad",
    "IFImFiringAndLockedForward",
    "IFImFiring",
    "SwitchSky",
    "TriggerFadeAndExitLevelOnButtonPress",
    "IFBondIsDead",
    "BondDisableDamageAndPickups",
    "BondHideWeapons",
    "CameraOrbitPad",
    "CreditsRoll",
    "IFCreditsHasCompleted",
    "IFObjectiveAllCompleted",
    "IFFolderActorIsEqual",
    "IFBondDamageAndPickupsDisabled",
    "MusicPlaySlot",
    "MusicStopSlot",
    "TriggerExplosionsAroundBond",
    "IFKilledCiviliansGreaterThan",
    "IFChrWasShotSinceLastCheck",
    "BondKilledInAction",
    "RaiseArms",
    "GasLeakAndFadeFog",
    "ObjectRocketLaunch"};


#pragma pack(1)

typedef struct AiGotoNextRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiGotoNextRecord;

typedef struct AiGotoFirstRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiGotoFirstRecord;

typedef struct AiLabelRecord
{
    u8 cmd;
    u8 ID;
} AiLabelRecord;

typedef struct AiYieldRecord
{
    u8 cmd;
} AiYieldRecord;

typedef struct AiEndListRecord
{
    u8 cmd;
} AiEndListRecord;

typedef struct AiSetChrAiListRecord
{
    u8  cmd;
    s8  CHR_NUM;
    s16 AI_LIST_ID;
} AiSetChrAiListRecord;

typedef struct AiSetReturnAiListRecord
{
    u8  cmd;
    s16 AI_LIST_ID;
} AiSetReturnAiListRecord;

typedef struct AiReturnRecord
{
    u8 cmd;
} AiReturnRecord;

typedef struct AiStopRecord
{
    u8 cmd;
} AiStopRecord;

typedef struct AiKneelRecord
{
    u8 cmd;
} AiKneelRecord;

typedef struct AiPlayAnimationRecord
{
    u8  cmd;
    s16 ANIMATION_ID;
    s16 START_TIME30;
    s16 END_TIME30;
    u8  BITFIELD;
    u8  INTERPOL_TIME60;
} AiPlayAnimationRecord;

typedef struct AiIFPlayingAnimationRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFPlayingAnimationRecord;

typedef struct AiPointAtBondRecord
{
    u8 cmd;
} AiPointAtBondRecord;

typedef struct AiLookSurprisedRecord
{
    u8 cmd;
} AiLookSurprisedRecord;

typedef struct AiTRYSidesteppingRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYSidesteppingRecord;

typedef struct AiTRYSideHoppingRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYSideHoppingRecord;

typedef struct AiTRYSideRunningRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYSideRunningRecord;

typedef struct AiTRYFiringWalkRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYFiringWalkRecord;

typedef struct AiTRYFiringRunRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYFiringRunRecord;

typedef struct AiTRYFiringRollRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYFiringRollRecord;

typedef struct AiTRYFireOrAimAtTargetRecord
{
    u8  cmd;
    s16 BITFIELD;
    s16 TARGET;
    u8  GOTOLABEL;
} AiTRYFireOrAimAtTargetRecord;

typedef struct AiTRYFireOrAimAtTargetKneelRecord
{
    u8  cmd;
    s16 BITFIELD;
    s16 TARGET;
    u8  GOTOLABEL;
} AiTRYFireOrAimAtTargetKneelRecord;

typedef struct AiTRYFireOrAimAtTargetUpdateRecord
{
    u8  cmd;
    s16 BITFIELD;
    s16 TARGET;
    u8  GOTOLABEL;
} AiTRYFireOrAimAtTargetUpdateRecord;

typedef struct AiTRYFacingTargetRecord
{
    u8  cmd;
    s16 BITFIELD;
    s16 TARGET;
    u8  GOTOLABEL;
} AiTRYFacingTargetRecord;

typedef struct AiHitChrWithItemRecord
{
    u8 cmd;
    u8 CHR_NUM;
    s8 PART_NUM;
    u8 ITEM_NUM;
} AiHitChrWithItemRecord;

typedef struct AiChrHitChrRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 CHR_NUM_TARGET;
    s8 PART_NUM;
} AiChrHitChrRecord;

typedef struct AiTRYThrowingGrenadeRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYThrowingGrenadeRecord;

typedef struct AiTRYDroppingItemRecord
{
    u8  cmd;
    s16 PROP_NUM;
    u8  ITEM_NUM;
    u8  GOTOLABEL;
} AiTRYDroppingItemRecord;

typedef struct AiRunToPadRecord
{
    u8  cmd;
    s16 PAD;
} AiRunToPadRecord;

typedef struct AiRunToPadPresetRecord
{
    u8 cmd;
} AiRunToPadPresetRecord;

typedef struct AiWalkToPadRecord
{
    u8  cmd;
    s16 PAD;
} AiWalkToPadRecord;

typedef struct AiSprintToPadRecord
{
    u8  cmd;
    s16 PAD;
} AiSprintToPadRecord;

typedef struct AiStartPatrolRecord
{
    u8 cmd;
    u8 PATH_NUM;
} AiStartPatrolRecord;

typedef struct AiSurrenderRecord
{
    u8 cmd;
} AiSurrenderRecord;

typedef struct AiRemoveMeRecord
{
    u8 cmd;
} AiRemoveMeRecord;

typedef struct AiChrRemoveInstantRecord
{
    u8 cmd;
    u8 CHR_NUM;
} AiChrRemoveInstantRecord;

typedef struct AiTRYTriggeringAlarmAtPadRecord
{
    u8  cmd;
    s16 PAD;
    u8  GOTOLABEL;
} AiTRYTriggeringAlarmAtPadRecord;

typedef struct AiAlarmOnRecord
{
    u8 cmd;
} AiAlarmOnRecord;

typedef struct AiAlarmOffRecord
{
    u8 cmd;
} AiAlarmOffRecord;

typedef struct AiTRYRunFromBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYRunFromBondRecord;

typedef struct AiTRYRunToBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYRunToBondRecord;

typedef struct AiTRYWalkToBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYWalkToBondRecord;

typedef struct AiTRYSprintToBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYSprintToBondRecord;

typedef struct AiTRYFindCoverRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiTRYFindCoverRecord;

typedef struct AiTRYRunToChrRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiTRYRunToChrRecord;

typedef struct AiTRYWalkToChrRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiTRYWalkToChrRecord;

typedef struct AiTRYSprintToChrRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiTRYSprintToChrRecord;

typedef struct AiIFImOnPatrolOrStoppedRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFImOnPatrolOrStoppedRecord;

typedef struct AiIFChrDyingOrDeadRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiIFChrDyingOrDeadRecord;

typedef struct AiIFChrDoesNotExistRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiIFChrDoesNotExistRecord;

typedef struct AiIFISeeBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFISeeBondRecord;

typedef struct AiSetNewRandomRecord
{
    u8 cmd;
} AiSetNewRandomRecord;

typedef struct AiIFRandomLessThanRecord
{
    u8 cmd;
    u8 BYTE;
    u8 GOTOLABEL;
} AiIFRandomLessThanRecord;

typedef struct AiIFRandomGreaterThanRecord
{
    u8 cmd;
    u8 BYTE;
    u8 GOTOLABEL;
} AiIFRandomGreaterThanRecord;

typedef struct AiIFICanHearAlarmRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFICanHearAlarmRecord;

typedef struct AiIFAlarmIsOnRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFAlarmIsOnRecord;

typedef struct AiIFGasIsLeakingRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFGasIsLeakingRecord;

typedef struct AiIFIHeardBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFIHeardBondRecord;

typedef struct AiIFISeeSomeoneShotRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFISeeSomeoneShotRecord;

typedef struct AiIFISeeSomeoneDieRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFISeeSomeoneDieRecord;

typedef struct AiIFICouldSeeBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFICouldSeeBondRecord;

typedef struct AiIFICouldSeeBondsStanRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFICouldSeeBondsStanRecord;

typedef struct AiIFIWasShotRecentlyRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFIWasShotRecentlyRecord;

typedef struct AiIFIHeardBondRecentlyRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFIHeardBondRecentlyRecord;

typedef struct AiIFImInRoomWithChrRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiIFImInRoomWithChrRecord;

typedef struct AiIFIveNotBeenSeenRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFIveNotBeenSeenRecord;

typedef struct AiIFImOnScreenRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFImOnScreenRecord;

typedef struct AiIFMyRoomIsOnScreenRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFMyRoomIsOnScreenRecord;

typedef struct AiIFRoomWithPadIsOnScreenRecord
{
    u8  cmd;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFRoomWithPadIsOnScreenRecord;

typedef struct AiIFImTargetedByBondRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFImTargetedByBondRecord;

typedef struct AiIFBondMissedMeRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFBondMissedMeRecord;

typedef struct AiIFMyAngleToBondLessThanRecord
{
    u8 cmd;
    u8 ANGLE;
    u8 GOTOLABEL;
} AiIFMyAngleToBondLessThanRecord;

typedef struct AiIFMyAngleToBondGreaterThanRecord
{
    u8 cmd;
    u8 ANGLE;
    u8 GOTOLABEL;
} AiIFMyAngleToBondGreaterThanRecord;

typedef struct AiIFMyAngleFromBondLessThanRecord
{
    u8 cmd;
    u8 ANGLE;
    u8 GOTOLABEL;
} AiIFMyAngleFromBondLessThanRecord;

typedef struct AiIFMyAngleFromBondGreaterThanRecord
{
    u8 cmd;
    u8 ANGLE;
    u8 GOTOLABEL;
} AiIFMyAngleFromBondGreaterThanRecord;

typedef struct AiIFMyDistanceToBondLessThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    u8  GOTOLABEL;
} AiIFMyDistanceToBondLessThanDecimeterRecord;

typedef struct AiIFMyDistanceToBondGreaterThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    u8  GOTOLABEL;
} AiIFMyDistanceToBondGreaterThanDecimeterRecord;

typedef struct AiIFChrDistanceToPadLessThanDecimeterRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 DISTANCE;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFChrDistanceToPadLessThanDecimeterRecord;

typedef struct AiIFChrDistanceToPadGreaterThanDecimeterRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 DISTANCE;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFChrDistanceToPadGreaterThanDecimeterRecord;

typedef struct AiIFMyDistanceToChrLessThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    u8  CHR_NUM;
    u8  GOTOLABEL;
} AiIFMyDistanceToChrLessThanDecimeterRecord;

typedef struct AiIFMyDistanceToChrGreaterThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    u8  CHR_NUM;
    u8  GOTOLABEL;
} AiIFMyDistanceToChrGreaterThanDecimeterRecord;

typedef struct AiTRYSettingMyPresetToChrWithinDistanceDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    u8  GOTOLABEL;
} AiTRYSettingMyPresetToChrWithinDistanceDecimeterRecord;

typedef struct AiIFBondDistanceToPadLessThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFBondDistanceToPadLessThanDecimeterRecord;

typedef struct AiIFBondDistanceToPadGreaterThanDecimeterRecord
{
    u8  cmd;
    s16 DISTANCE;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFBondDistanceToPadGreaterThanDecimeterRecord;

typedef struct AiIFChrInRoomWithPadRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFChrInRoomWithPadRecord;

typedef struct AiIFBondInRoomWithPadRecord
{
    u8  cmd;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFBondInRoomWithPadRecord;

typedef struct AiIFBondCollectedObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFBondCollectedObjectRecord;

typedef struct AiIFKeyDroppedRecord
{
    u8 cmd;
    u8 KEY_ID;
    u8 GOTOLABEL;
} AiIFKeyDroppedRecord;

typedef struct AiIFItemIsAttachedToObjectRecord
{
    u8 cmd;
    u8 ITEM_NUM;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFItemIsAttachedToObjectRecord;

typedef struct AiIFBondHasItemEquippedRecord
{
    u8 cmd;
    u8 ITEM_NUM;
    u8 GOTOLABEL;
} AiIFBondHasItemEquippedRecord;

typedef struct AiIFObjectExistsRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFObjectExistsRecord;

typedef struct AiIFObjectNotDestroyedRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFObjectNotDestroyedRecord;

typedef struct AiIFObjectWasActivatedRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFObjectWasActivatedRecord;

typedef struct AiIFBondUsedGadgetOnObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFBondUsedGadgetOnObjectRecord;

typedef struct AiActivateObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiActivateObjectRecord;

typedef struct AiDestroyObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiDestroyObjectRecord;

typedef struct AiDropObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiDropObjectRecord;

typedef struct AiChrDropAllConcealedItemsRecord
{
    u8 cmd;
    u8 CHR_NUM;
} AiChrDropAllConcealedItemsRecord;

typedef struct AiChrDropAllHeldItemsRecord
{
    u8 cmd;
    u8 CHR_NUM;
} AiChrDropAllHeldItemsRecord;

typedef struct AiBondCollectObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiBondCollectObjectRecord;

typedef struct AiChrEquipObjectRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 CHR_NUM;
} AiChrEquipObjectRecord;

typedef struct AiMoveObjectRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s16 PAD;
} AiMoveObjectRecord;

typedef struct AiDoorOpenRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiDoorOpenRecord;

typedef struct AiDoorCloseRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiDoorCloseRecord;

typedef struct AiIFDoorStateEqualRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 DOOR_STATE;
    u8 GOTOLABEL;
} AiIFDoorStateEqualRecord;

typedef struct AiIFDoorHasBeenOpenedBeforeRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 GOTOLABEL;
} AiIFDoorHasBeenOpenedBeforeRecord;

typedef struct AiDoorSetLockRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 LOCK_FLAG;
} AiDoorSetLockRecord;

typedef struct AiDoorUnsetLockRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 LOCK_FLAG;
} AiDoorUnsetLockRecord;

typedef struct AiIFDoorLockEqualRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 LOCK_FLAG;
    u8 GOTOLABEL;
} AiIFDoorLockEqualRecord;

typedef struct AiIFObjectiveNumCompleteRecord
{
    u8 cmd;
    u8 OBJ_NUM;
    u8 GOTOLABEL;
} AiIFObjectiveNumCompleteRecord;

typedef struct AiTRYUnknown6eRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiTRYUnknown6eRecord;

typedef struct AiTRYUnknown6fRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiTRYUnknown6fRecord;

typedef struct AiIFGameDifficultyLessThanRecord
{
    u8 cmd;
    u8 DIFICULTY_ID;
    u8 GOTOLABEL;
} AiIFGameDifficultyLessThanRecord;

typedef struct AiIFGameDifficultyGreaterThanRecord
{
    u8 cmd;
    u8 DIFICULTY_ID;
    u8 GOTOLABEL;
} AiIFGameDifficultyGreaterThanRecord;

typedef struct AiIFMissionTimeLessThanRecord
{
    u8  cmd;
    s16 SECONDS;
    u8  GOTOLABEL;
} AiIFMissionTimeLessThanRecord;

typedef struct AiIFMissionTimeGreaterThanRecord
{
    u8  cmd;
    s16 SECONDS;
    u8  GOTOLABEL;
} AiIFMissionTimeGreaterThanRecord;

typedef struct AiIFSystemPowerTimeLessThanRecord
{
    u8  cmd;
    s16 MINUTES;
    u8  GOTOLABEL;
} AiIFSystemPowerTimeLessThanRecord;

typedef struct AiIFSystemPowerTimeGreaterThanRecord
{
    u8  cmd;
    s16 MINUTES;
    u8  GOTOLABEL;
} AiIFSystemPowerTimeGreaterThanRecord;

typedef struct AiIFLevelIdLessThanRecord
{
    u8 cmd;
    u8 LEVEL_ID;
    u8 GOTOLABEL;
} AiIFLevelIdLessThanRecord;

typedef struct AiIFLevelIdGreaterThanRecord
{
    u8 cmd;
    u8 LEVEL_ID;
    u8 GOTOLABEL;
} AiIFLevelIdGreaterThanRecord;

typedef struct AiIFMyNumArghsLessThanRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiIFMyNumArghsLessThanRecord;

typedef struct AiIFMyNumArghsGreaterThanRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiIFMyNumArghsGreaterThanRecord;

typedef struct AiIFMyNumCloseArghsLessThanRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiIFMyNumCloseArghsLessThanRecord;

typedef struct AiIFMyNumCloseArghsGreaterThanRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiIFMyNumCloseArghsGreaterThanRecord;

typedef struct AiIFChrHealthLessThanRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 HEALTH;
    u8 GOTOLABEL;
} AiIFChrHealthLessThanRecord;

typedef struct AiIFChrHealthGreaterThanRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 HEALTH;
    u8 GOTOLABEL;
} AiIFChrHealthGreaterThanRecord;

typedef struct AiIFChrWasDamagedSinceLastCheckRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiIFChrWasDamagedSinceLastCheckRecord;

typedef struct AiIFBondHealthLessThanRecord
{
    u8 cmd;
    u8 HEALTH;
    u8 GOTOLABEL;
} AiIFBondHealthLessThanRecord;

typedef struct AiIFBondHealthGreaterThanRecord
{
    u8 cmd;
    u8 HEALTH;
    u8 GOTOLABEL;
} AiIFBondHealthGreaterThanRecord;

typedef struct AiSetMyMoraleRecord
{
    u8 cmd;
    u8 val;
} AiSetMyMoraleRecord;

typedef struct AiAddToMyMoraleRecord
{
    u8 cmd;
    u8 val;
} AiAddToMyMoraleRecord;

typedef struct AiSubtractFromMyMoraleRecord
{
    u8 cmd;
    u8 val;
} AiSubtractFromMyMoraleRecord;

typedef struct AiIFMyMoraleLessThanRecord
{
    u8 cmd;
    u8 val;
    u8 GOTOLABEL;
} AiIFMyMoraleLessThanRecord;

typedef struct AiIFMyMoraleLessThanRandomRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFMyMoraleLessThanRandomRecord;

typedef struct AiSetMyAlertnessRecord
{
    u8 cmd;
    u8 val;
} AiSetMyAlertnessRecord;

typedef struct AiAddToMyAlertnessRecord
{
    u8 cmd;
    u8 val;
} AiAddToMyAlertnessRecord;

typedef struct AiSubtractFromMyAlertnessRecord
{
    u8 cmd;
    u8 val;
} AiSubtractFromMyAlertnessRecord;

typedef struct AiIFMyAlertnessLessThanRecord
{
    u8 cmd;
    u8 CHRBYTE;
    u8 GOTOLABEL;
} AiIFMyAlertnessLessThanRecord;

typedef struct AiIFMyAlertnessLessThanRandomRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFMyAlertnessLessThanRandomRecord;

typedef struct AiSetMyHearingScaleRecord
{
    u8  cmd;
    s16 HEARING_SCALE;
} AiSetMyHearingScaleRecord;

typedef struct AiSetMyVisionRangeRecord
{
    u8 cmd;
    u8 VISION_RANGE;
} AiSetMyVisionRangeRecord;

typedef struct AiSetMyGrenadeProbabilityRecord
{
    u8 cmd;
    u8 GRENADE_PROB;
} AiSetMyGrenadeProbabilityRecord;

typedef struct AiSetMyChrNumRecord
{
    u8 cmd;
    u8 CHR_NUM;
} AiSetMyChrNumRecord;

typedef struct AiSetMyHealthTotalRecord
{
    u8  cmd;
    s16 HEALTH;
} AiSetMyHealthTotalRecord;

typedef struct AiSetMyArmourRecord
{
    u8  cmd;
    s16 AMOUNT;
} AiSetMyArmourRecord;

typedef struct AiSetMySpeedRatingRecord
{
    u8 cmd;
    s8 val;
} AiSetMySpeedRatingRecord;

typedef struct AiSetMyArghRatingRecord
{
    u8 cmd;
    s8 val;
} AiSetMyArghRatingRecord;

typedef struct AiSetMyAccuracyRatingRecord
{
    u8 cmd;
    s8 val;
} AiSetMyAccuracyRatingRecord;

typedef struct AiSetMyFlags2Record
{
    u8 cmd;
    u8 BITS;
} AiSetMyFlags2Record;

typedef struct AiUnsetMyFlags2Record
{
    u8 cmd;
    u8 BITS;
} AiUnsetMyFlags2Record;

typedef struct AiIFMyFlags2HasRecord
{
    u8 cmd;
    u8 BITS;
    u8 GOTOLABEL;
} AiIFMyFlags2HasRecord;

typedef struct AiSetChrBitfieldRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 BITS;
} AiSetChrBitfieldRecord;

typedef struct AiUnsetChrBitfieldRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 BITS;
} AiUnsetChrBitfieldRecord;

typedef struct AiIFChrBitfieldHasRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 BITS;
    u8 GOTOLABEL;
} AiIFChrBitfieldHasRecord;

typedef struct AiSetObjectiveBitfieldRecord
{
    u8  cmd;
    s32 BITFIELD;
} AiSetObjectiveBitfieldRecord;

typedef struct AiUnsetObjectiveBitfieldRecord
{
    u8  cmd;
    s32 BITFIELD;
} AiUnsetObjectiveBitfieldRecord;

typedef struct AiIFObjectiveBitfieldHasRecord
{
    u8  cmd;
    s32 BITS;
    u8  GOTOLABEL;
} AiIFObjectiveBitfieldHasRecord;

typedef struct AiSetMychrflagsRecord
{
    u8  cmd;
    s32 CHRFLAGS;
} AiSetMychrflagsRecord;

typedef struct AiUnsetMychrflagsRecord
{
    u8  cmd;
    s32 CHRFLAGS;
} AiUnsetMychrflagsRecord;

typedef struct AiIFMychrflagsHasRecord
{
    u8  cmd;
    s32 CHRFLAGS;
    u8  GOTOLABEL;
} AiIFMychrflagsHasRecord;

typedef struct AiSetChrchrflagsRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s32 CHRFLAGS;
} AiSetChrchrflagsRecord;

typedef struct AiUnsetChrchrflagsRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s32 CHRFLAGS;
} AiUnsetChrchrflagsRecord;

typedef struct AiIFChrchrflagsHasRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s32 CHRFLAGS;
    u8  GOTOLABEL;
} AiIFChrchrflagsHasRecord;

typedef struct AiSetObjectFlagsRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITFIELD;
} AiSetObjectFlagsRecord;

typedef struct AiUnsetObjectFlagsRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITFIELD;
} AiUnsetObjectFlagsRecord;

typedef struct AiIFObjectFlagsHasRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITS;
    u8  GOTOLABEL;
} AiIFObjectFlagsHasRecord;

typedef struct AiSetObjectFlags2Record
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITS;
} AiSetObjectFlags2Record;

typedef struct AiUnsetObjectFlags2Record
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITS;
} AiUnsetObjectFlags2Record;

typedef struct AiIFObjectFlags2HasRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s32 BITFIELD;
    u8  GOTOLABEL;
} AiIFObjectFlags2HasRecord;

typedef struct AiSetMyChrPresetRecord
{
    u8 cmd;
    u8 PRESET;
} AiSetMyChrPresetRecord;

typedef struct AiSetChrChrPresetRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 PRESET;
} AiSetChrChrPresetRecord;

typedef struct AiSetMyPadPresetRecord
{
    u8  cmd;
    s16 PAD_PRESET;
} AiSetMyPadPresetRecord;

typedef struct AiSetChrPadPresetRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 PAD_PRESET;
} AiSetChrPadPresetRecord;

typedef struct AiPRINTRecord
{
    u8 cmd;
    u8 val[];
} AiPRINTRecord;

typedef struct AiMyTimerStartRecord
{
    u8 cmd;
} AiMyTimerStartRecord;

typedef struct AiMyTimerResetRecord
{
    u8 cmd;
} AiMyTimerResetRecord;

typedef struct AiMyTimerPauseRecord
{
    u8 cmd;
} AiMyTimerPauseRecord;

typedef struct AiMyTimerResumeRecord
{
    u8 cmd;
} AiMyTimerResumeRecord;

typedef struct AiIFMyTimerIsNotRunningRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFMyTimerIsNotRunningRecord;

typedef struct AiIFMyTimerLessThanTicksRecord
{
    u8 cmd;
    u8 TICKS[3];
    u8 GOTOLABEL;
} AiIFMyTimerLessThanTicksRecord;

typedef struct AiIFMyTimerGreaterThanTicksRecord
{
    u8 cmd;
    u8 TICKS[3];
    u8 GOTOLABEL;
} AiIFMyTimerGreaterThanTicksRecord;

typedef struct AiHudCountdownShowRecord
{
    u8 cmd;
} AiHudCountdownShowRecord;

typedef struct AiHudCountdownHideRecord
{
    u8 cmd;
} AiHudCountdownHideRecord;

typedef struct AiHudCountdownSetRecord
{
    u8  cmd;
    s16 SECONDS;
} AiHudCountdownSetRecord;

typedef struct AiHudCountdownStopRecord
{
    u8 cmd;
} AiHudCountdownStopRecord;

typedef struct AiHudCountdownStartRecord
{
    u8 cmd;
} AiHudCountdownStartRecord;

typedef struct AiIFHudCountdownIsNotRunningRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFHudCountdownIsNotRunningRecord;

typedef struct AiIFHudCountdownLessThanRecord
{
    u8  cmd;
    s16 SECONDS;
    u8  GOTOLABEL;
} AiIFHudCountdownLessThanRecord;

typedef struct AiIFHudCountdownGreaterThanRecord
{
    u8  cmd;
    s16 SECONDS;
    u8  GOTOLABEL;
} AiIFHudCountdownGreaterThanRecord;

typedef struct AiTRYSpawningChrAtPadRecord
{
    u8  cmd;
    u8  BODY_NUM;
    s8  HEAD_NUM;
    s16 PAD;
    s16 AI_LIST_ID;
    s32 BITFIELD;
    u8  GOTOLABEL;
} AiTRYSpawningChrAtPadRecord;

typedef struct AiTRYSpawningChrNextToChrRecord
{
    u8  cmd;
    u8  BODY_NUM;
    s8  HEAD_NUM;
    u8  CHR_NUM_TARGET;
    s16 AI_LIST_ID;
    s32 BITFIELD;
    u8  GOTOLABEL;
} AiTRYSpawningChrNextToChrRecord;

typedef struct AiTRYGiveMeItemRecord
{
    u8  cmd;
    s16 PROP_NUM;
    u8  ITEM_NUM;
    s32 PROPFLAG;
    u8  GOTOLABEL;
} AiTRYGiveMeItemRecord;

typedef struct AiTRYGiveMeHatRecord
{
    u8  cmd;
    s16 PROP_NUM;
    s32 PROP_BITFIELD;
    u8  GOTOLABEL;
} AiTRYGiveMeHatRecord;

typedef struct AiTRYCloningChrRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 AI_LIST_ID;
    u8  GOTOLABEL;
} AiTRYCloningChrRecord;

typedef struct AiTextPrintBottomRecord
{
    u8  cmd;
    s16 txt;
} AiTextPrintBottomRecord;

typedef struct AiTextPrintTopRecord
{
    u8  cmd;
    s16 txt;
} AiTextPrintTopRecord;

typedef struct AiSfxPlayRecord
{
    u8  cmd;
    s16 SOUND_NUM;
    s8  CHANNEL_NUM;
} AiSfxPlayRecord;

typedef struct AiSfxEmitFromObjectRecord
{
    u8  cmd;
    s8  slotID;
    u8  OBJECT_TAG;
    s16 sfxID;
} AiSfxEmitFromObjectRecord;

typedef struct AiSfxEmitFromPadRecord
{
    u8  cmd;
    s8  slotID;
    s16 PAD;
    s16 sfxID;
} AiSfxEmitFromPadRecord;

typedef struct AiSfxSetChannelVolumeRecord
{
    u8  cmd;
    s8  slotID;
    s16 TARGET_VOLUME;
    s16 sfxID;
} AiSfxSetChannelVolumeRecord;

typedef struct AiSfxFadeChannelVolumeRecord
{
    u8  cmd;
    s8  slotID;
    s16 TARGET_VOLUME;
    s16 sfxID;
} AiSfxFadeChannelVolumeRecord;

typedef struct AiSfxStopChannelRecord
{
    u8 cmd;
    s8 CHANNEL_NUM;
} AiSfxStopChannelRecord;

typedef struct AiIFSfxChannelVolumeLessThanRecord
{
    u8  cmd;
    s8  slotID;
    s16 VOLUME;
    u8  GOTOLABEL;
} AiIFSfxChannelVolumeLessThanRecord;

typedef struct AiVehicleStartPathRecord
{
    u8 cmd;
    u8 PATH_NUM;
} AiVehicleStartPathRecord;

typedef struct AiVehicleSpeedRecord
{
    u8  cmd;
    s16 TOP_SPEED;
    s16 ACCELERATION_TIME60;
} AiVehicleSpeedRecord;

typedef struct AiAircraftRotorSpeedRecord
{
    u8  cmd;
    s16 ROTOR_SPEED;
    s16 ACCELERATION_TIME60;
} AiAircraftRotorSpeedRecord;

typedef struct AiIFCameraIsInIntroRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFCameraIsInIntroRecord;

typedef struct AiIFCameraIsInBondSwirlRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFCameraIsInBondSwirlRecord;

typedef struct AiTvChangeScreenBankRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
    u8 SCREEN_INDEX;
    u8 SCREEN_BANK;
} AiTvChangeScreenBankRecord;

typedef struct AiIFBondInTankRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFBondInTankRecord;

typedef struct AiEndLevelRecord
{
    u8 cmd;
} AiEndLevelRecord;

typedef struct AiCameraReturnToBondRecord
{
    u8 cmd;
} AiCameraReturnToBondRecord;

typedef struct AiCameraLookAtBondFromPadRecord
{
    u8  cmd;
    s16 PAD;
} AiCameraLookAtBondFromPadRecord;

typedef struct AiCameraSwitchRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s16 LOOK_AT_BOND_FLAG;
    s16 UNUSED_FLAG;
} AiCameraSwitchRecord;

typedef struct AiIFBondYPosLessThanRecord
{
    u8  cmd;
    s16 Y_POS;
    u8  GOTOLABEL;
} AiIFBondYPosLessThanRecord;

typedef struct AiBondDisableControlRecord
{
    u8 cmd;
    u8 val;
} AiBondDisableControlRecord;

typedef struct AiBondEnableControlRecord
{
    u8 cmd;
} AiBondEnableControlRecord;

typedef struct AiTRYTeleportingChrToPadRecord
{
    u8  cmd;
    u8  CHR_NUM;
    s16 PAD;
    u8  GOTOLABEL;
} AiTRYTeleportingChrToPadRecord;

typedef struct AiScreenFadeToBlackRecord
{
    u8 cmd;
} AiScreenFadeToBlackRecord;

typedef struct AiScreenFadeFromBlackRecord
{
    u8 cmd;
} AiScreenFadeFromBlackRecord;

typedef struct AiIFScreenFadeCompletedRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFScreenFadeCompletedRecord;

typedef struct AiHideAllChrsRecord
{
    u8 cmd;
} AiHideAllChrsRecord;

typedef struct AiShowAllChrsRecord
{
    u8 cmd;
} AiShowAllChrsRecord;

typedef struct AiDoorOpenInstantRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiDoorOpenInstantRecord;

typedef struct AiChrRemoveItemInHandRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 HAND_INDEX;
} AiChrRemoveItemInHandRecord;

typedef struct AiIfNumberOfActivePlayersLessThanRecord
{
    u8 cmd;
    s8 NUMBER;
    u8 GOTOLABEL;
} AiIfNumberOfActivePlayersLessThanRecord;

typedef struct AiIFBondItemTotalAmmoLessThanRecord
{
    u8 cmd;
    s8 ITEM_NUM;
    s8 AMMO_TOTAL;
    u8 GOTOLABEL;
} AiIFBondItemTotalAmmoLessThanRecord;

typedef struct AiBondEquipItemRecord
{
    u8 cmd;
    s8 ITEM_NUM;
} AiBondEquipItemRecord;

typedef struct AiBondEquipItemCinemaRecord
{
    u8 cmd;
    s8 ITEM_NUM;
} AiBondEquipItemCinemaRecord;

typedef struct AiBondSetLockedVelocityRecord
{
    u8 cmd;
    s8 X_SPEED60;
    s8 Z_SPEED60;
} AiBondSetLockedVelocityRecord;

typedef struct AiIFObjectInRoomWithPadRecord
{
    u8  cmd;
    u8  OBJECT_TAG;
    s16 PAD;
    u8  GOTOLABEL;
} AiIFObjectInRoomWithPadRecord;

typedef struct AiIFImFiringAndLockedForwardRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFImFiringAndLockedForwardRecord;

typedef struct AiIFImFiringRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFImFiringRecord;

typedef struct AiSwitchSkyRecord
{
    u8 cmd;
} AiSwitchSkyRecord;

typedef struct AiTriggerFadeAndExitLevelOnButtonPressRecord
{
    u8 cmd;
} AiTriggerFadeAndExitLevelOnButtonPressRecord;

typedef struct AiIFBondIsDeadRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFBondIsDeadRecord;

typedef struct AiBondDisableDamageAndPickupsRecord
{
    u8 cmd;
} AiBondDisableDamageAndPickupsRecord;

typedef struct AiBondHideWeaponsRecord
{
    u8 cmd;
} AiBondHideWeaponsRecord;

typedef struct AiCameraOrbitPadRecord
{
    u8  cmd;
    s16 LAT_DISTANCE;
    s16 VERT_DISTANCE;
    s16 ORBIT_SPEED60;
    s16 PAD;
    s16 Y_POS_OFFSET;
    s16 INITIAL_ROTATION;
} AiCameraOrbitPadRecord;

typedef struct AiCreditsRollRecord
{
    u8 cmd;
} AiCreditsRollRecord;

typedef struct AiIFCreditsHasCompletedRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFCreditsHasCompletedRecord;

typedef struct AiIFObjectiveAllCompletedRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFObjectiveAllCompletedRecord;

typedef struct AiIFFolderActorIsEqualRecord
{
    u8 cmd;
    s8 BOND_ACTOR_INDEX;
    u8 GOTOLABEL;
} AiIFFolderActorIsEqualRecord;

typedef struct AiIFBondDamageAndPickupsDisabledRecord
{
    u8 cmd;
    u8 GOTOLABEL;
} AiIFBondDamageAndPickupsDisabledRecord;

typedef struct AiMusicPlaySlotRecord
{
    u8 cmd;
    s8 MUSIC_SLOT;
    u8 SECONDS_STOPPED_DURATION;
    u8 SECONDS_TOTAL_DURATION;
} AiMusicPlaySlotRecord;

typedef struct AiMusicStopSlotRecord
{
    u8 cmd;
    s8 MUSIC_SLOT;
} AiMusicStopSlotRecord;

typedef struct AiTriggerExplosionsAroundBondRecord
{
    u8 cmd;
} AiTriggerExplosionsAroundBondRecord;

typedef struct AiIFKilledCiviliansGreaterThanRecord
{
    u8 cmd;
    u8 CIVILIANS_KILLED;
    u8 GOTOLABEL;
} AiIFKilledCiviliansGreaterThanRecord;

typedef struct AiIFChrWasShotSinceLastCheckRecord
{
    u8 cmd;
    u8 CHR_NUM;
    u8 GOTOLABEL;
} AiIFChrWasShotSinceLastCheckRecord;

typedef struct AiBondKilledInActionRecord
{
    u8 cmd;
} AiBondKilledInActionRecord;

typedef struct AiRaiseArmsRecord
{
    u8 cmd;
} AiRaiseArmsRecord;

typedef struct AiGasLeakAndFadeFogRecord
{
    u8 cmd;
} AiGasLeakAndFadeFogRecord;

typedef struct AiObjectRocketLaunchRecord
{
    u8 cmd;
    u8 OBJECT_TAG;
} AiObjectRocketLaunchRecord;

#pragma pack(0)

typedef struct coord3d
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float AsArray[3];
    };
} coord3d;

typedef struct bbox
{
    union
    {
        struct
        {
            float xmin;
            float xmax;
            float ymin;
            float ymax;
            float zmin;
            float zmax;
        };
        float AsArray[6];
    };
} bbox;

typedef struct PropDefHeaderRecord
{
    unsigned short extrascale; /*0x0 Fixed-Point format char.8 eg: 0x03.80 = 3.5*/
    char           state;
    char           type; /*0x3*/
} PropDefHeaderRecord;

typedef struct AIListRecord
{
    char *ailist;
    int   ID;
} AIListRecord;
typedef struct PadRecord /*0x2c (44) long confirmed*/
{
    coord3d pos;   /*0x00*/
    coord3d up;    /*0x0c*/
    coord3d look;  /*0x18*/
    char   *plink; /*0x24 canonical name */
    void   *stan;  /*0x28 canonical name */
} PadRecord;

/**
 * Bound Pads hold an extra Bounding Box which any prop assigned will try to
 * fill (non-uniform scaling).
 */
typedef struct BoundPadRecord /*0x44 (68) long confirmed*/
{
    // inherits PadRecord; /*0x00 confirmed*/
    coord3d pos;   /*0x00*/
    coord3d up;    /*0x0c*/
    coord3d look;  /*0x18*/
    char   *plink; /*0x24 canonical name */
    void   *stan;  /*0x28 canonical name */
    // temporary fix for no inheritance support by glibtools
    bbox    bbox; /*0x2c - 0x40 confirmed*/
} BoundPadRecord;
typedef struct waypoint
{
    int  padID;      // Pad ID to anchor waypoint to.
    int *neighbours; // Array of neighbouring (connected) waypoint IDs (ending in -1)
    int  groupNum;   // index entry in the waygroup table that contains this path entry
    int  dist;       // Initialise to 0, used by engine for pathfinding Heuristics between waypoints within a set.
} waypoint;

/**
 * The Subset waygroup table which lists the IDs of the waypoints that
 * belong to each group as well as any connected groups
 */
typedef struct waygroup
{
    int *neighbours; // Array of neighbouring (connected) waygroup IDs (ending in -1)
    int *waypoints;  // Array of waypoint IDs (ending in -1)
    int  dist;       // Initialise to 0, used by engine for pathfinding Heuristics between sets
} waygroup;

/**
 * Path for guard to patrol (loop) or get from A to B (linear)
 */
typedef struct PathRecord
{
    int  *waypoints; // array of waypoint IDs in path (ending in -1)
    char  ID;        // path ID
    char  isLoop;    // 0x05 Path loops
    short len;       /*0x06 unused*/
} PathRecord;

typedef struct stagesetup
{
    waypoint            *pathwaypoints;
    waygroup            *waypointgroups;
    void                *intro;
    PropDefHeaderRecord *propDefs;
    PathRecord          *patrolpaths;
    AIListRecord        *ailists;
    PadRecord           *pads;
    BoundPadRecord      *boundpads;
    char               **padnames;
    char               **boundpadnames;
} stagesetup;

#define MAX 10

int  top = -1;
char stack[MAX];

typedef struct
{
    int id;
    int used;
    int num0s;
} LLEnum;
LLEnum labels[100];
LLEnum tags[100];
LLEnum keys[100];
LLEnum chrs[100];
LLEnum pads[1000];
LLEnum SubIDs[100];

char *hasName;



/*PUSH FUNCTION*/
int    push(int item)
{
    if (top == (MAX - 1))
    {
        return 0;
    }
    else
    {
        ++top;
        stack[top] = item;
        return 1;
    }
}

/*POP */
int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        --top;
        return stack[top + 1];
    }
}

/*Sniff */
int sniff()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return stack[top];
    }
}
int stackFind(int find)
{
    int i;
    if (top == -1)
    {
        return -1;
    }
    else
    {
        for (i = top; i >= 0; --i)
        {
            if (stack[i] == find) return i;
        }
    }
    return -1;
}
int stackFindAndremove(int find)
{
    int i = stackFind(find);
    if (i >= 0)
    {
        for (; i <= top; i++)
        {
            stack[i] = i < MAX ? stack[i + 1] : 0;
        }
        top--;
        return 1;
    }
    return 0;
}
void displayStack()
{
    int i;

    printf("\nThe label Stack is: ");

    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        for (i = top; i >= 0; --i)
        {
            printf("\n%3d", stack[i]);
        }
    }

    printf("\n---------------\n\n");
}
void _AddLabel(int lbl, void *ptr)
{
    int     i      = 0;
    int     found  = 0;
    LLEnum *labels = ptr;
    if (lbl == 0)
    {
        labels[0].num0s++;
        return;
    }

    while (labels[i].id != 0)
    {
        if (lbl == labels[i].id)
        {
            found = 1;
            labels[i].used++;
        }
        i++;
    }

    if (!found)
    {
        labels[i].id = lbl;
        labels[i].used++;
    }
}
void AddLabel(char lbl)
{
    _AddLabel(lbl, labels);
}
void AddTag(char lbl)
{
    _AddLabel(lbl, tags);
}
void AddKey(char lbl)
{
    _AddLabel(lbl, keys);
}
void AddChr(char lbl)
{
    _AddLabel(lbl, chrs);
}
void AddPad(short lbl)
{
    _AddLabel(lbl, pads);
}
void AddSubID(int lbl)
{
    _AddLabel(lbl, SubIDs);
}

void SortEnums(LLEnum *labels)
{
    int i, j, tempid, tempnum;

    for (i = 0; i < 100; ++i)
    {
        if (labels[i].id != 0)
        {
            for (j = i + 1; j < 100; ++j)
            {
                if (labels[j].id != 0)
                {
                    if (labels[i].id > labels[j].id)
                    {
                        tempid         = labels[i].id;
                        tempnum        = labels[i].used;
                        labels[i].id   = labels[j].id;
                        labels[i].used = labels[j].used;
                        labels[j].id   = tempid;
                        labels[j].used = tempnum;
                    }
                }
            }
        }
    }
}

void printenum(LLEnum labels[], char *enumname)
{
    int i = 0;
    if (labels[0].num0s || labels[i].id)
    {
        printf("    enum %s\n    {\n", enumname);
        if (labels[0].num0s) printf("        %s0, //used %d times\n", enumname, labels[0].num0s);
        while (labels[i].id != 0)
        {
            if (!(enumname == "chr" && ((signed char)labels[i].id < 0 && (signed char)labels[i].id > -9)))
            {
                if ((i > 0 && labels[i - 1].id == labels[i].id - 1)||(i==0 && labels[0].num0s && labels[0].id ==1))
                {
                    printf("        %s%u, //Used %d times\n", enumname, labels[i].id, labels[i].used);
                }
                else
                {
                    printf("        %s%u = %u, //Used %d times\n", enumname, labels[i].id, labels[i].id, labels[i].used);
                }
            }
            i++;
        }
        printf("    };\n");
    }
}

int getDataSize(FILE *pfile ,void *pointer, int endtag)
{
    int i = 0;

    fseek(pfile, (int)pointer, SEEK_SET);

    // scan for end of Record (NULL or -1)
    do
    {
        fread(&i, 4, 1, pfile);

    } while (i != endtag);

    return  (ftell(pfile) ) - (int)pointer;
}

int chraiitemsize(unsigned char *AIList, int offset)
{
    switch (AIList[offset])
    {
        case AI_GotoNext:
            return sizeof(AiGotoNextRecord);
        case AI_GotoFirst:
            return sizeof(AiGotoFirstRecord);
        case AI_Label:
            return sizeof(AiLabelRecord);
        case AI_Yield:
            return sizeof(AiYieldRecord);
        case AI_EndList:
            return sizeof(AiEndListRecord);
        case AI_SetChrAiList:
            return sizeof(AiSetChrAiListRecord);
        case AI_SetReturnAiList:
            return sizeof(AiSetReturnAiListRecord);
        case AI_Return:
            return sizeof(AiReturnRecord);
        case AI_Stop:
            return sizeof(AiStopRecord);
        case AI_Kneel:
            return sizeof(AiKneelRecord);
        case AI_PlayAnimation:
            return sizeof(AiPlayAnimationRecord);
        case AI_IFPlayingAnimation:
            return sizeof(AiIFPlayingAnimationRecord);
        case AI_PointAtBond:
            return sizeof(AiPointAtBondRecord);
        case AI_LookSurprised:
            return sizeof(AiLookSurprisedRecord);
        case AI_TRYSidestepping:
            return sizeof(AiTRYSidesteppingRecord);
        case AI_TRYSideHopping:
            return sizeof(AiTRYSideHoppingRecord);
        case AI_TRYSideRunning:
            return sizeof(AiTRYSideRunningRecord);
        case AI_TRYFiringWalk:
            return sizeof(AiTRYFiringWalkRecord);
        case AI_TRYFiringRun:
            return sizeof(AiTRYFiringRunRecord);
        case AI_TRYFiringRoll:
            return sizeof(AiTRYFiringRollRecord);
        case AI_TRYFireOrAimAtTarget:
            return sizeof(AiTRYFireOrAimAtTargetRecord);
        case AI_TRYFireOrAimAtTargetKneel:
            return sizeof(AiTRYFireOrAimAtTargetKneelRecord);
        case AI_IFImFiring:
            return sizeof(AiIFImFiringRecord);
        case AI_IFImFiringAndLockedForward:
            return sizeof(AiIFImFiringAndLockedForwardRecord);
        case AI_TRYFireOrAimAtTargetUpdate:
            return sizeof(AiTRYFireOrAimAtTargetUpdateRecord);
        case AI_TRYFacingTarget:
            return sizeof(AiTRYFacingTargetRecord);
        case AI_HitChrWithItem:
            return sizeof(AiHitChrWithItemRecord);
        case AI_ChrHitChr:
            return sizeof(AiChrHitChrRecord);
        case AI_TRYThrowingGrenade:
            return sizeof(AiTRYThrowingGrenadeRecord);
        case AI_TRYDroppingItem:
            return sizeof(AiTRYDroppingItemRecord);
        case AI_RunToPad:
            return sizeof(AiRunToPadRecord);
        case AI_RunToPadPreset:
            return sizeof(AiRunToPadPresetRecord);
        case AI_WalkToPad:
            return sizeof(AiWalkToPadRecord);
        case AI_SprintToPad:
            return sizeof(AiSprintToPadRecord);
        case AI_StartPatrol:
            return sizeof(AiStartPatrolRecord);
        case AI_Surrender:
            return sizeof(AiSurrenderRecord);
        case AI_RemoveMe:
            return sizeof(AiRemoveMeRecord);
        case AI_ChrRemoveInstant:
            return sizeof(AiChrRemoveInstantRecord);
        case AI_TRYTriggeringAlarmAtPad:
            return sizeof(AiTRYTriggeringAlarmAtPadRecord);
        case AI_AlarmOn:
            return sizeof(AiAlarmOnRecord);
        case AI_AlarmOff:
            return sizeof(AiAlarmOffRecord);
        case AI_TRYRunFromBond:
            return sizeof(AiTRYRunFromBondRecord);
        case AI_TRYRunToBond:
            return sizeof(AiTRYRunToBondRecord);
        case AI_TRYWalkToBond:
            return sizeof(AiTRYWalkToBondRecord);
        case AI_TRYSprintToBond:
            return sizeof(AiTRYSprintToBondRecord);
        case AI_TRYFindCover:
            return sizeof(AiTRYFindCoverRecord);
        case AI_TRYRunToChr:
            return sizeof(AiTRYRunToChrRecord);
        case AI_TRYWalkToChr:
            return sizeof(AiTRYWalkToChrRecord);
        case AI_TRYSprintToChr:
            return sizeof(AiTRYSprintToChrRecord);
        case AI_IFImOnPatrolOrStopped:
            return sizeof(AiIFImOnPatrolOrStoppedRecord);
        case AI_IFChrDyingOrDead:
            return sizeof(AiIFChrDyingOrDeadRecord);
        case AI_IFChrDoesNotExist:
            return sizeof(AiIFChrDoesNotExistRecord);
        case AI_IFISeeBond:
            return sizeof(AiIFISeeBondRecord);
        case AI_SetNewRandom:
            return sizeof(AiSetNewRandomRecord);
        case AI_IFRandomLessThan:
            return sizeof(AiIFRandomLessThanRecord);
        case AI_IFRandomGreaterThan:
            return sizeof(AiIFRandomGreaterThanRecord);
        case AI_IFICanHearAlarm:
            return sizeof(AiIFICanHearAlarmRecord);
        case AI_IFAlarmIsOn:
            return sizeof(AiIFAlarmIsOnRecord);
        case AI_IFGasIsLeaking:
            return sizeof(AiIFGasIsLeakingRecord);
        case AI_IFIHeardBond:
            return sizeof(AiIFIHeardBondRecord);
        case AI_IFISeeSomeoneShot:
            return sizeof(AiIFISeeSomeoneShotRecord);
        case AI_IFISeeSomeoneDie:
            return sizeof(AiIFISeeSomeoneDieRecord);
        case AI_IFICouldSeeBond:
            return sizeof(AiIFICouldSeeBondRecord);
        case AI_IFICouldSeeBondsStan:
            return sizeof(AiIFICouldSeeBondsStanRecord);
        case AI_IFIWasShotRecently:
            return sizeof(AiIFIWasShotRecentlyRecord);
        case AI_IFIHeardBondRecently:
            return sizeof(AiIFIHeardBondRecentlyRecord);
        case AI_IFImInRoomWithChr:
            return sizeof(AiIFImInRoomWithChrRecord);
        case AI_IFIveNotBeenSeen:
            return sizeof(AiIFIveNotBeenSeenRecord);
        case AI_IFImOnScreen:
            return sizeof(AiIFImOnScreenRecord);
        case AI_IFMyRoomIsOnScreen:
            return sizeof(AiIFMyRoomIsOnScreenRecord);
        case AI_IFRoomWithPadIsOnScreen:
            return sizeof(AiIFRoomWithPadIsOnScreenRecord);
        case AI_IFImTargetedByBond:
            return sizeof(AiIFImTargetedByBondRecord);
        case AI_IFBondMissedMe:
            return sizeof(AiIFBondMissedMeRecord);
        case AI_IFMyAngleToBondLessThan:
            return sizeof(AiIFMyAngleToBondLessThanRecord);
        case AI_IFMyAngleToBondGreaterThan:
            return sizeof(AiIFMyAngleToBondGreaterThanRecord);
        case AI_IFMyAngleFromBondLessThan:
            return sizeof(AiIFMyAngleFromBondLessThanRecord);
        case AI_IFMyAngleFromBondGreaterThan:
            return sizeof(AiIFMyAngleFromBondGreaterThanRecord);
        case AI_IFMyDistanceToBondLessThanDecimeter:
            return sizeof(AiIFMyDistanceToBondLessThanDecimeterRecord);
        case AI_IFMyDistanceToBondGreaterThanDecimeter:
            return sizeof(AiIFMyDistanceToBondGreaterThanDecimeterRecord);
        case AI_IFChrDistanceToPadLessThanDecimeter:
            return sizeof(AiIFChrDistanceToPadLessThanDecimeterRecord);
        case AI_IFChrDistanceToPadGreaterThanDecimeter:
            return sizeof(AiIFChrDistanceToPadGreaterThanDecimeterRecord);
        case AI_IFMyDistanceToChrLessThanDecimeter:
            return sizeof(AiIFMyDistanceToChrLessThanDecimeterRecord);
        case AI_IFMyDistanceToChrGreaterThanDecimeter:
            return sizeof(AiIFMyDistanceToChrGreaterThanDecimeterRecord);
        case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter:
            return sizeof(AiTRYSettingMyPresetToChrWithinDistanceDecimeterRecord);
        case AI_IFBondDistanceToPadLessThanDecimeter:
            return sizeof(AiIFBondDistanceToPadLessThanDecimeterRecord);
        case AI_IFBondDistanceToPadGreaterThanDecimeter:
            return sizeof(AiIFBondDistanceToPadGreaterThanDecimeterRecord);
        case AI_IFChrInRoomWithPad:
            return sizeof(AiIFChrInRoomWithPadRecord);
        case AI_IFBondInRoomWithPad:
            return sizeof(AiIFBondInRoomWithPadRecord);
        case AI_IFBondCollectedObject:
            return sizeof(AiIFBondCollectedObjectRecord);
        case AI_IFKeyDropped:
            return sizeof(AiIFKeyDroppedRecord);
        case AI_IFItemIsAttachedToObject:
            return sizeof(AiIFItemIsAttachedToObjectRecord);
        case AI_IFBondHasItemEquipped:
            return sizeof(AiIFBondHasItemEquippedRecord);
        case AI_IFObjectExists:
            return sizeof(AiIFObjectExistsRecord);
        case AI_IFObjectNotDestroyed:
            return sizeof(AiIFObjectNotDestroyedRecord);
        case AI_IFObjectWasActivated:
            return sizeof(AiIFObjectWasActivatedRecord);
        case AI_IFBondUsedGadgetOnObject:
            return sizeof(AiIFBondUsedGadgetOnObjectRecord);
        case AI_ActivateObject:
            return sizeof(AiActivateObjectRecord);
        case AI_DestroyObject:
            return sizeof(AiDestroyObjectRecord);
        case AI_DropObject:
            return sizeof(AiDropObjectRecord);
        case AI_ChrDropAllConcealedItems:
            return sizeof(AiChrDropAllConcealedItemsRecord);
        case AI_ChrDropAllHeldItems:
            return sizeof(AiChrDropAllHeldItemsRecord);
        case AI_BondCollectObject:
            return sizeof(AiBondCollectObjectRecord);
        case AI_ChrEquipObject:
            return sizeof(AiChrEquipObjectRecord);
        case AI_MoveObject:
            return sizeof(AiMoveObjectRecord);
        case AI_DoorOpen:
            return sizeof(AiDoorOpenRecord);
        case AI_DoorClose:
            return sizeof(AiDoorCloseRecord);
        case AI_IFDoorStateEqual:
            return sizeof(AiIFDoorStateEqualRecord);
        case AI_IFDoorHasBeenOpenedBefore:
            return sizeof(AiIFDoorHasBeenOpenedBeforeRecord);
        case AI_DoorSetLock:
            return sizeof(AiDoorSetLockRecord);
        case AI_DoorUnsetLock:
            return sizeof(AiDoorUnsetLockRecord);
        case AI_IFDoorLockEqual:
            return sizeof(AiIFDoorLockEqualRecord);
        case AI_IFObjectiveNumComplete:
            return sizeof(AiIFObjectiveNumCompleteRecord);
        case AI_TRYUnknown6e:
            return sizeof(AiTRYUnknown6eRecord);
        case AI_TRYUnknown6f:
            return sizeof(AiTRYUnknown6fRecord);
        case AI_IFGameDifficultyLessThan:
            return sizeof(AiIFGameDifficultyLessThanRecord);
        case AI_IFGameDifficultyGreaterThan:
            return sizeof(AiIFGameDifficultyGreaterThanRecord);
        case AI_IFMissionTimeLessThan:
            return sizeof(AiIFMissionTimeLessThanRecord);
        case AI_IFMissionTimeGreaterThan:
            return sizeof(AiIFMissionTimeGreaterThanRecord);
        case AI_IFSystemPowerTimeLessThan:
            return sizeof(AiIFSystemPowerTimeLessThanRecord);
        case AI_IFSystemPowerTimeGreaterThan:
            return sizeof(AiIFSystemPowerTimeGreaterThanRecord);
        case AI_IFLevelIdLessThan:
            return sizeof(AiIFLevelIdLessThanRecord);
        case AI_IFLevelIdGreaterThan:
            return sizeof(AiIFLevelIdGreaterThanRecord);
        case AI_IFMyNumArghsLessThan:
            return sizeof(AiIFMyNumArghsLessThanRecord);
        case AI_IFMyNumArghsGreaterThan:
            return sizeof(AiIFMyNumArghsGreaterThanRecord);
        case AI_IFMyNumCloseArghsLessThan:
            return sizeof(AiIFMyNumCloseArghsLessThanRecord);
        case AI_IFMyNumCloseArghsGreaterThan:
            return sizeof(AiIFMyNumCloseArghsGreaterThanRecord);
        case AI_IFChrHealthLessThan:
            return sizeof(AiIFChrHealthLessThanRecord);
        case AI_IFChrHealthGreaterThan:
            return sizeof(AiIFChrHealthGreaterThanRecord);
        case AI_IFChrWasDamagedSinceLastCheck:
            return sizeof(AiIFChrWasDamagedSinceLastCheckRecord);
        case AI_IFBondHealthLessThan:
            return sizeof(AiIFBondHealthLessThanRecord);
        case AI_IFBondHealthGreaterThan:
            return sizeof(AiIFBondHealthGreaterThanRecord);
        case AI_SetMyMorale:
            return sizeof(AiSetMyMoraleRecord);
        case AI_AddToMyMorale:
            return sizeof(AiAddToMyMoraleRecord);
        case AI_SubtractFromMyMorale:
            return sizeof(AiSubtractFromMyMoraleRecord);
        case AI_IFMyMoraleLessThan:
            return sizeof(AiIFMyMoraleLessThanRecord);
        case AI_IFMyMoraleLessThanRandom:
            return sizeof(AiIFMyMoraleLessThanRandomRecord);
        case AI_SetMyAlertness:
            return sizeof(AiSetMyAlertnessRecord);
        case AI_AddToMyAlertness:
            return sizeof(AiAddToMyAlertnessRecord);
        case AI_SubtractFromMyAlertness:
            return sizeof(AiSubtractFromMyAlertnessRecord);
        case AI_IFMyAlertnessLessThan:
            return sizeof(AiIFMyAlertnessLessThanRecord);
        case AI_IFMyAlertnessLessThanRandom:
            return sizeof(AiIFMyAlertnessLessThanRandomRecord);
        case AI_SetMyHearingScale:
            return sizeof(AiSetMyHearingScaleRecord);
        case AI_SetMyVisionRange:
            return sizeof(AiSetMyVisionRangeRecord);
        case AI_SetMyGrenadeProbability:
            return sizeof(AiSetMyGrenadeProbabilityRecord);
        case AI_SetMyChrNum:
            return sizeof(AiSetMyChrNumRecord);
        case AI_SetMyHealthTotal:
            return sizeof(AiSetMyHealthTotalRecord);
        case AI_SetMyArmour:
            return sizeof(AiSetMyArmourRecord);
        case AI_SetMySpeedRating:
            return sizeof(AiSetMySpeedRatingRecord);
        case AI_SetMyArghRating:
            return sizeof(AiSetMyArghRatingRecord);
        case AI_SetMyAccuracyRating:
            return sizeof(AiSetMyAccuracyRatingRecord);
        case AI_SetMyFlags2:
            return sizeof(AiSetMyFlags2Record);
        case AI_UnsetMyFlags2:
            return sizeof(AiUnsetMyFlags2Record);
        case AI_IFMyFlags2Has:
            return sizeof(AiIFMyFlags2HasRecord);
        case AI_SetChrBitfield:
            return sizeof(AiSetChrBitfieldRecord);
        case AI_UnsetChrBitfield:
            return sizeof(AiUnsetChrBitfieldRecord);
        case AI_IFChrBitfieldHas:
            return sizeof(AiIFChrBitfieldHasRecord);
        case AI_SetObjectiveBitfield:
            return sizeof(AiSetObjectiveBitfieldRecord);
        case AI_UnsetObjectiveBitfield:
            return sizeof(AiUnsetObjectiveBitfieldRecord);
        case AI_IFObjectiveBitfieldHas:
            return sizeof(AiIFObjectiveBitfieldHasRecord);
        case AI_SetMychrflags:
            return sizeof(AiSetMychrflagsRecord);
        case AI_UnsetMychrflags:
            return sizeof(AiUnsetMychrflagsRecord);
        case AI_IFMychrflagsHas:
            return sizeof(AiIFMychrflagsHasRecord);
        case AI_SetChrchrflags:
            return sizeof(AiSetChrchrflagsRecord);
        case AI_UnsetChrchrflags:
            return sizeof(AiUnsetChrchrflagsRecord);
        case AI_IFChrchrflagsHas:
            return sizeof(AiIFChrchrflagsHasRecord);
        case AI_SetObjectFlags:
            return sizeof(AiSetObjectFlagsRecord);
        case AI_UnsetObjectFlags:
            return sizeof(AiUnsetObjectFlagsRecord);
        case AI_IFObjectFlagsHas:
            return sizeof(AiIFObjectFlagsHasRecord);
        case AI_SetObjectFlags2:
            return sizeof(AiSetObjectFlags2Record);
        case AI_UnsetObjectFlags2:
            return sizeof(AiUnsetObjectFlags2Record);
        case AI_IFObjectFlags2Has:
            return sizeof(AiIFObjectFlags2HasRecord);
        case AI_SetMyChrPreset:
            return sizeof(AiSetMyChrPresetRecord);
        case AI_SetChrChrPreset:
            return sizeof(AiSetChrChrPresetRecord);
        case AI_SetMyPadPreset:
            return sizeof(AiSetMyPadPresetRecord);
        case AI_SetChrPadPreset:
            return sizeof(AiSetChrPadPresetRecord);
        case AI_MyTimerStart:
            return sizeof(AiMyTimerStartRecord);
        case AI_MyTimerReset:
            return sizeof(AiMyTimerResetRecord);
        case AI_MyTimerPause:
            return sizeof(AiMyTimerPauseRecord);
        case AI_MyTimerResume:
            return sizeof(AiMyTimerResumeRecord);
        case AI_IFMyTimerIsNotRunning:
            return sizeof(AiIFMyTimerIsNotRunningRecord);
        case AI_IFMyTimerLessThanTicks:
            return sizeof(AiIFMyTimerLessThanTicksRecord);
        case AI_IFMyTimerGreaterThanTicks:
            return sizeof(AiIFMyTimerGreaterThanTicksRecord);
        case AI_HudCountdownShow:
            return sizeof(AiHudCountdownShowRecord);
        case AI_HudCountdownHide:
            return sizeof(AiHudCountdownHideRecord);
        case AI_HudCountdownSet:
            return sizeof(AiHudCountdownSetRecord);
        case AI_HudCountdownStop:
            return sizeof(AiHudCountdownStopRecord);
        case AI_HudCountdownStart:
            return sizeof(AiHudCountdownStartRecord);
        case AI_IFHudCountdownIsNotRunning:
            return sizeof(AiIFHudCountdownIsNotRunningRecord);
        case AI_IFHudCountdownLessThan:
            return sizeof(AiIFHudCountdownLessThanRecord);
        case AI_IFHudCountdownGreaterThan:
            return sizeof(AiIFHudCountdownGreaterThanRecord);
        case AI_TRYSpawningChrAtPad:
            return sizeof(AiTRYSpawningChrAtPadRecord);
        case AI_TRYSpawningChrNextToChr:
            return sizeof(AiTRYSpawningChrNextToChrRecord);
        case AI_TRYGiveMeItem:
            return sizeof(AiTRYGiveMeItemRecord);
        case AI_TRYGiveMeHat:
            return sizeof(AiTRYGiveMeHatRecord);
        case AI_TRYCloningChr:
            return sizeof(AiTRYCloningChrRecord);
        case AI_TextPrintBottom:
            return sizeof(AiTextPrintBottomRecord);
        case AI_TextPrintTop:
            return sizeof(AiTextPrintTopRecord);
        case AI_SfxPlay:
            return sizeof(AiSfxPlayRecord);
        case AI_SfxEmitFromObject:
            return sizeof(AiSfxEmitFromObjectRecord);
        case AI_SfxEmitFromPad:
            return sizeof(AiSfxEmitFromPadRecord);
        case AI_SfxSetChannelVolume:
            return sizeof(AiSfxSetChannelVolumeRecord);
        case AI_SfxFadeChannelVolume:
            return sizeof(AiSfxFadeChannelVolumeRecord);
        case AI_SfxStopChannel:
            return sizeof(AiSfxStopChannelRecord);
        case AI_IFSfxChannelVolumeLessThan:
            return sizeof(AiIFSfxChannelVolumeLessThanRecord);
        case AI_VehicleStartPath:
            return sizeof(AiVehicleStartPathRecord);
        case AI_VehicleSpeed:
            return sizeof(AiVehicleSpeedRecord);
        case AI_AircraftRotorSpeed:
            return sizeof(AiAircraftRotorSpeedRecord);
        case AI_IFCameraIsInIntro:
            return sizeof(AiIFCameraIsInIntroRecord);
        case AI_IFCameraIsInBondSwirl:
            return sizeof(AiIFCameraIsInBondSwirlRecord);
        case AI_TvChangeScreenBank:
            return sizeof(AiTvChangeScreenBankRecord);
        case AI_IFBondInTank:
            return sizeof(AiIFBondInTankRecord);
        case AI_EndLevel:
            return sizeof(AiEndLevelRecord);
        case AI_CameraReturnToBond:
            return sizeof(AiCameraReturnToBondRecord);
        case AI_CameraLookAtBondFromPad:
            return sizeof(AiCameraLookAtBondFromPadRecord);
        case AI_CameraSwitch:
            return sizeof(AiCameraSwitchRecord);
        case AI_IFBondYPosLessThan:
            return sizeof(AiIFBondYPosLessThanRecord);
        case AI_BondDisableControl:
            return sizeof(AiBondDisableControlRecord);
        case AI_BondEnableControl:
            return sizeof(AiBondEnableControlRecord);
        case AI_TRYTeleportingChrToPad:
            return sizeof(AiTRYTeleportingChrToPadRecord);
        case AI_ScreenFadeToBlack:
            return sizeof(AiScreenFadeToBlackRecord);
        case AI_ScreenFadeFromBlack:
            return sizeof(AiScreenFadeFromBlackRecord);
        case AI_IFScreenFadeCompleted:
            return sizeof(AiIFScreenFadeCompletedRecord);
        case AI_HideAllChrs:
            return sizeof(AiHideAllChrsRecord);
        case AI_ShowAllChrs:
            return sizeof(AiShowAllChrsRecord);
        case AI_DoorOpenInstant:
            return sizeof(AiDoorOpenInstantRecord);
        case AI_ChrRemoveItemInHand:
            return sizeof(AiChrRemoveItemInHandRecord);
        case AI_IfNumberOfActivePlayersLessThan:
            return sizeof(AiIfNumberOfActivePlayersLessThanRecord);
        case AI_IFBondItemTotalAmmoLessThan:
            return sizeof(AiIFBondItemTotalAmmoLessThanRecord);
        case AI_BondEquipItem:
            return sizeof(AiBondEquipItemRecord);
        case AI_BondEquipItemCinema:
            return sizeof(AiBondEquipItemCinemaRecord);
        case AI_BondSetLockedVelocity:
            return sizeof(AiBondSetLockedVelocityRecord);
        case AI_IFObjectInRoomWithPad:
            return sizeof(AiIFObjectInRoomWithPadRecord);
        case AI_SwitchSky:
            return sizeof(AiSwitchSkyRecord);
        case AI_TriggerFadeAndExitLevelOnButtonPress:
            return sizeof(AiTriggerFadeAndExitLevelOnButtonPressRecord);
        case AI_IFBondIsDead:
            return sizeof(AiIFBondIsDeadRecord);
        case AI_BondDisableDamageAndPickups:
            return sizeof(AiBondDisableDamageAndPickupsRecord);
        case AI_BondHideWeapons:
            return sizeof(AiBondHideWeaponsRecord);
        case AI_CameraOrbitPad:
            return sizeof(AiCameraOrbitPadRecord);
        case AI_CreditsRoll:
            return sizeof(AiCreditsRollRecord);
        case AI_IFCreditsHasCompleted:
            return sizeof(AiIFCreditsHasCompletedRecord);
        case AI_IFObjectiveAllCompleted:
            return sizeof(AiIFObjectiveAllCompletedRecord);
        case AI_IFFolderActorIsEqual:
            return sizeof(AiIFFolderActorIsEqualRecord);
        case AI_IFBondDamageAndPickupsDisabled:
            return sizeof(AiIFBondDamageAndPickupsDisabledRecord);
        case AI_MusicPlaySlot:
            return sizeof(AiMusicPlaySlotRecord);
        case AI_MusicStopSlot:
            return sizeof(AiMusicStopSlotRecord);
        case AI_TriggerExplosionsAroundBond:
            return sizeof(AiTriggerExplosionsAroundBondRecord);
        case AI_IFKilledCiviliansGreaterThan:
            return sizeof(AiIFKilledCiviliansGreaterThanRecord);
        case AI_IFChrWasShotSinceLastCheck:
            return sizeof(AiIFChrWasShotSinceLastCheckRecord);
        case AI_BondKilledInAction:
            return sizeof(AiBondKilledInActionRecord);
        case AI_RaiseArms:
            return sizeof(AiRaiseArmsRecord);
        case AI_GasLeakAndFadeFog:
            return sizeof(AiGasLeakAndFadeFogRecord);
        case AI_ObjectRocketLaunch:
            return sizeof(AiObjectRocketLaunchRecord);
        case AI_PRINT:
        {
            int pos = offset + 1;
            while (AIList[pos] != 0)
            {
                ++pos;
            }
            return (pos - offset) + 1;
        }
        default:
            printf("chraiitemsize: unknown type %d!\n", AIList[offset]);
            printf("%d,%d,%d,[%d],%d,%d,%d\n", AIList[offset - 3], AIList[offset - 2], AIList[offset - 1], AIList[offset ], AIList[offset +1], AIList[offset + 2], AIList[offset +3]);
            return 1;
    }
}

#define EraseCommand printf("\r%*s\r", (int)strlen(AI_CMD_ToString[AiList[Offset]]) + ((int)strlen((char *)tabs) + 1), "")
//#define NOMACROS
/**
 * @brief Parse AI list and print out C Macros
 * @param AiList: Bytestream for ai
 * @param ID: List ID
 */
void ai(unsigned char *AiList, short ID)
{
    for (int Offset = 0;;)
    {
        int hasClosingBrace = FALSE;
        int hasLabel        = FALSE;
        int hasMacro        = FALSE;
        int tabs[MAX + 1]; // 4 char wide string
        int i;
        for ( i = 0; i < MAX; i++)
        {
            tabs[i] = 0;
        }
        for ( i = 0; i < top + 2 && i < MAX; i++)
        {
            tabs[i] = 0x20202020; // 4 spaces
        }

        printf("%s%s(", (char *)tabs, AI_CMD_ToString[AiList[Offset]]);

        switch (AiList[Offset])
        {
            case AI_GotoFirst: // BYTE(LABEL)
            {
                 AiGotoFirstRecord *ai = &AiList+Offset;
                int lbl = AiList[Offset + 1];
                #ifndef NOMACROS
                if (lbl == sniff()) //either contnue or loop
                {
                    int found = 0;
                    for (i = Offset; AiList[i] != AI_EndList; i += chraiitemsize(AiList, i))
                    {
                        if (AiList[i] == AI_GotoFirst && AiList[i+1] == lbl) found++;
                    }

                    EraseCommand;
                    if (found ==1)
                    {
                        pop();
                        for ( i = top + 2; i < MAX; i++)
                        {
                            tabs[i] = 0;
                        }
                        printf("%sLOOP(", (char *)tabs);
                    }
                    else
                    {
                        printf("%sCONTINUE(", (char *)tabs);
                    }
                }
                #endif
                printf("lbl%d)\n\n",lbl);
                AddLabel(lbl);
                hasClosingBrace = TRUE;
                break;
            }
            case AI_Label: // BYTE(ID)
            {
                 AiLabelRecord *ai = &AiList+Offset;

                int lbl = AiList[Offset + 1];
#ifndef NOMACROS
                Offset += AI_Label_LENGTH;
                hasMacro = TRUE;
                if (AiList[Offset] == AI_Yield)
                {
                    int hasLoop = FALSE;
                    Offset += AI_Yield_LENGTH;
                    for (i = Offset; AiList[i] != AI_EndList; i += chraiitemsize(AiList, i))
                    {
                        if (AiList[i] == AI_GotoFirst && AiList[i + 1] == lbl) hasLoop = TRUE;
                    }
                    if (hasLoop)
                    {
                        EraseCommand;
                        if (AiList[Offset] != AI_GotoFirst)
                        {
                            push(lbl);

                            printf("\n%sDO(", (char *)tabs);
                        }
                        else
                        {
                            printf("\n%sYIELD_FOREVER( lbl%d )\n\n", (char *)tabs, lbl);
                            Offset += AI_GotoFirst_LENGTH;
                            hasClosingBrace = TRUE;
                        }
                    }
                    else
                    {
                        Offset -= AI_Yield_LENGTH;
                    }
                }
                #endif

                if(!hasClosingBrace) printf(" lbl%d ", lbl);
                AddLabel(lbl);
                break;
            }

            case AI_EndList /*canonical name*/: // /*NONE*/
            {
                 AiEndListRecord *ai = &AiList+Offset;
                printf(")\n\n");

                return;
            }
            case AI_SetChrAiList: // BYTE(CHR_NUM), DBYTE(AI_LIST_ID)
            {
                 AiSetChrAiListRecord *ai = &AiList+Offset;
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1 + 1));
                signed char    CHR_NUM    = AiList[Offset + 1];

                if (CHR_NUM < 0 && CHR_NUM > -10)
                {
                    EraseCommand;

                    switch (CHR_NUM)
                    {
                        case CHR_SELF:
                        {
                            int found = 0;
                            i         = Offset;
                            while (i > 0)
                            {
                                if (AiList[i] == AI_SetReturnAiList &&
                                    CharArrayTo16(AiList, i + 1) == ID)
                                {
                                    found = 1;
                                    if (i < Offset - AI_SetReturnAiList_LENGTH) printf("// tentative, Please confirm\n");
                                    break;
                                }
                                i --;
                            }
                            if (found)
                            {
                                printf("%s%s(", (char *)tabs, "CALL");
                            }
                            else
                            {
                                printf("%s%s(", (char *)tabs, "JumpTo");
                            }
                            break;
                        }
                        case CHR_BOND_CINEMA:
                        {
                            printf("%s%s(", (char *)tabs, "SetBondsAiList");
                            break;
                        }
                        case CHR_CLONE:
                        {
                            printf("%s%s(", (char *)tabs, "SetMyClonesAiList");
                            break;
                        }
                    }
                }
                else
                {
                    if (CHR_NUM < 0 && CHR_NUM > -10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM);
                    }
                }

                if (isGlobalAIListID(AI_LIST_ID))
                {
                    printf("%s", GAILIST_ToString[AI_LIST_ID]);
                }
                else if (isBGAIListID(AI_LIST_ID))
                {
                    printf("bgai_%hd", getBGAIListID(AI_LIST_ID));
                }
                else
                {
                    printf("chrai_%hd", getChrAIListID(AI_LIST_ID));
                }

                if (hasClosingBrace) printf(")\n\n");

                break;
            }
            case AI_SetReturnAiList: // DBYTE(AI_LIST_ID)
            {
                 AiSetReturnAiListRecord *ai = &AiList+Offset;
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1));

                if (!(AiList[Offset + AI_SetReturnAiList_LENGTH] == AI_SetChrAiList &&
                      AI_LIST_ID == ID &&
                      (signed char)AiList[Offset + AI_SetReturnAiList_LENGTH + 1] == CHR_SELF))
                {
                    if (isGlobalAIListID(AI_LIST_ID))
                    {
                        printf("%s", GAILIST_ToString[AI_LIST_ID]);
                    }
                    else if (isBGAIListID(AI_LIST_ID))
                    {
                        printf("bgai_%hd", getBGAIListID(AI_LIST_ID));
                    }
                    else
                    {
                        printf("chrai_%hd", getChrAIListID(AI_LIST_ID));
                    }
                }
                else
                {
                    EraseCommand; // CALL should already be printed
                    hasClosingBrace = TRUE;
                }

                break;
            }
            case AI_Return: // /*NONE*/
            {
                 AiReturnRecord *ai = &AiList+Offset;
                AddSubID(ID);
                break;
            }

            case AI_PlayAnimation: // DBYTE(ANIMATION_ID), DBYTE(START_TIME30),DBYTE(END_TIME30), BYTE(BITFIELD), BYTE(INTERPOL_TIME60)
            {
                 AiPlayAnimationRecord *ai = &AiList+Offset;
                int  anim_id, zero ;
                 short startframe, endframe;
                anim_id    = CharArrayTo16(AiList, Offset + 1 + 0);
                startframe = CharArrayTo16(AiList, Offset + 1 + 2);
                endframe   = CharArrayTo16(AiList, Offset + 1 + 4);
                if (startframe == -1 && endframe == -1 && AiList[Offset + 1 + 6] == 6 && AiList[Offset + 1 + 7] == 16)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "PlayAnimationSimple");
                    printf("%s", ANIMATIONS_ToString[anim_id]);
                }
                else
                {
                    printf("%s,%d,%d,0x%02X,%d", ANIMATIONS_ToString[anim_id], startframe, endframe, AiList[Offset + 1 + 6], AiList[Offset + 1 + 7]);
                }

                break;
            }
            case AI_IFChrDyingOrDead: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFChrDyingOrDeadRecord *ai = &AiList+Offset;
                signed char chr = AiList[Offset + 1];
                if (chr == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "IFImDyingOrDead");
                }
                else
                {
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }

                hasLabel = TRUE;

                break;
            }
            case AI_IFChrDoesNotExist: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFChrDoesNotExistRecord *ai = &AiList+Offset;
                signed char chr = AiList[Offset + 1];
                switch (chr)
                {
                    case CHR_SELF:
                    {
                        EraseCommand;
                        printf("%s%s(", (char *)tabs, "IFIDoNotExist");
                        break;
                    }
                    case CHR_CLONE:
                    {
                        EraseCommand;
                        printf("%s%s(", (char *)tabs, "IFMyCloneDoesNotExist");
                        break;
                    }
                    default:
                    {
                        if (chr < 0 && chr > -10)
                        {
                                printf("%s,", CHR_ToString[abs(chr)]);
                        }
                        else
                        {
                                printf("chr%hd,", chr);
                                AddChr(chr);
                        }
                    }
                }

                hasLabel = TRUE;
                break;
            }

            case AI_TRYFireOrAimAtTarget: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                 AiTRYFireOrAimAtTargetRecord *ai = &AiList+Offset;
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == TARGET_BOND)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYFireAtBond");
                }
                else if (targettype == TARGET_PAD)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYFireAtPad");
                    printf("%d", targetid);
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_BOND)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYAimAtBond");
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_PAD)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYAimAtPad");
                    printf("%d", targetid);
                }
                else
                {
                    printf("%04X,", targettype);
                    printf("chr%d", targetid);
                    AddChr(targetid);
                }
                hasLabel = TRUE;
                break;
            }
            case AI_TRYFireOrAimAtTargetKneel: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                 AiTRYFireOrAimAtTargetKneelRecord *ai = &AiList+Offset;
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == TARGET_BOND)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFireAtBondKneeling");
                }
                else if (targettype == TARGET_PAD)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFireAtPadKneeling");
                    printf("%d", targetid);
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_BOND)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYAimAtBondKneeling");
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_PAD)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYAimAtPadKneeling");
                    printf("%d", targetid);
                }
                else
                {
                    printf("%04X,", targettype);
                    printf("chr%d", targetid);
                    AddChr(targetid);
                }

                hasLabel = TRUE;
                break;
            }

            case AI_TRYFireOrAimAtTargetUpdate: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                 AiTRYFireOrAimAtTargetUpdateRecord *ai = &AiList+Offset;
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == TARGET_BOND)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFireAtBondUpdate");
                }
                else if (targettype == TARGET_PAD)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFireAtPadUpdate");
                    printf("%d", targetid);
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_BOND)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYAimAtBondUpdate");
                }
                else if (targettype == TARGET_AIM_ONLY | TARGET_PAD)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYAimAtPadUpdate");
                    printf("%d", targetid);
                }
                else
                {
                    printf("%04X,", targettype);
                    printf("chr%d", targetid);
                    AddChr(targetid);
                }

                hasLabel = TRUE;

                break;
            }
            case AI_TRYFacingTarget: // DBYTE(BITFIELD),DBYTE(TARGET),BYTE(GOTOLABEL)
            {
                 AiTRYFacingTargetRecord *ai = &AiList+Offset;
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == TARGET_BOND)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFacingBond");
                }
                else if (targettype == TARGET_PAD)
                {
                    EraseCommand;

                    printf("%s%s(", (char *)tabs, "TRYFacingPad");
                    printf("%d", targetid);
                }
                else
                {
                    printf("%04X,", targettype);
                    printf("chr%d", targetid);
                    AddChr(targetid);
                }

                hasLabel = TRUE;
                break;
            }
            case AI_HitChrWithItem: // BYTE(CHR_NUM),BYTE(PART_NUM),BYTE(ITEM_NUM)
            {
                 AiHitChrWithItemRecord *ai = &AiList+Offset;
                signed char CHR_NUM = AiList[Offset + 1];

                if (CHR_NUM == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "HitMeWithItem");
                    printf("%d,%d", AiList[Offset + 2], AiList[Offset + 1 + 2]);
                }
                else
                {
                    if (CHR_NUM<0 && CHR_NUM> - 10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM);
                        AddChr(CHR_NUM);
                    }
                    printf("%s,%s",  HITTARGET_ToString[AiList[Offset + 1 + 1]], ITEM_IDS_ToString[AiList[Offset + 1 + 2]]);
                }

                break;
            }
            case AI_ChrHitChr: // BYTE(CHR_NUM),BYTE(CHR_NUM_TARGET),BYTE(PART_NUM)
            {
                 AiChrHitChrRecord *ai = &AiList+Offset;
                signed char CHR_NUM = AiList[Offset + 1];
                signed char CHR_NUM2 = AiList[Offset + 2];
                char        PART_NUM = AiList[Offset + 3];

                if (CHR_NUM == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "IHitChr");
                    if (CHR_NUM2 < 0 && CHR_NUM2 > -10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM2)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM2);
                        AddChr(CHR_NUM2);
                    }
                }
                else if (CHR_NUM2 == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "ChrHitMe");
                    if (CHR_NUM < 0 && CHR_NUM > -10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM);
                        AddChr(CHR_NUM);
                    }
                }
                else
                {
                    if (CHR_NUM < 0 && CHR_NUM > -10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM);
                        AddChr(CHR_NUM);
                    }
                    if (CHR_NUM2 < 0 && CHR_NUM2 > -10)
                    {
                        printf("%s,", CHR_ToString[abs(CHR_NUM2)]);
                    }
                    else
                    {
                        printf("chr%hd,", CHR_NUM2);
                        AddChr(CHR_NUM2);
                    }
                }
                printf("%s", HITTARGET_ToString[PART_NUM]);
                break;
            }

            case AI_TRYDroppingItem: // DBYTE(PROP_NUM),BYTE(ITEM_NUM),BYTE(GOTOLABEL)
            {
                 AiTRYDroppingItemRecord *ai = &AiList+Offset;
                unsigned short modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s,%s", PROP_ToString[modelnum], ITEM_IDS_ToString[AiList[Offset + 1 + 2]]);

                hasLabel = TRUE;

                break;
            }
            case AI_ChrRemoveInstant: // BYTE(CHR_NUM)
            {
                AiChrRemoveInstantRecord *ai  = AiList[Offset];
                signed char               chr = AiList[Offset + 1];

                if (chr == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "RemoveMeInstantly");
                }
                else
                {
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }

                break;
            }
            case AI_TRYTriggeringAlarmAtPad: // DBYTE(PAD),BYTE(GOTOLABEL)
            {
                 AiTRYTriggeringAlarmAtPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }

            case AI_TRYRunToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiTRYRunToChrRecord *ai = &AiList+Offset;
                signed char          chr = AiList[Offset + 1];

                if (chr == CHR_PRESET)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYRunToPresetChr");
                }
                else
                {
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }

                hasLabel = TRUE;
                break;
            }
            case AI_TRYWalkToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiTRYWalkToChrRecord *ai = &AiList+Offset;
                signed char           chr = AiList[Offset + 1];

                if (chr == CHR_PRESET)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYWalkToPresetChr");
                }
                else
                {
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }

                hasLabel = TRUE;

                break;
            }
            case AI_TRYSprintToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiTRYSprintToChrRecord *ai = &AiList+Offset;
                signed char             chr = AiList[Offset + 1];

                if (chr == CHR_PRESET)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "TRYSprintToPresetChr");
                }
                else
                {
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }
                hasLabel = TRUE;

                break;
            }
            case AI_SetNewRandom:
            {
                 AiSetNewRandomRecord *ai = &AiList+Offset;
                if (AiList[Offset + 1] == AI_IFRandomLessThan || AiList[Offset + 1] == AI_IFRandomGreaterThan)
                {
                    EraseCommand;
                    hasClosingBrace = TRUE;
                }
                break;
            }
            case AI_IFRandomLessThan: // BYTE(BYTE), BYTE(GOTOLABEL)
            {
                 AiIFRandomLessThanRecord *ai = &AiList+Offset;
                if (AiList[Offset - 1] == AI_SetNewRandom)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "IFNewRandomLessThan");
                }
                hasLabel = TRUE;
                break;
            }
            case AI_IFRandomGreaterThan: // BYTE(BYTE), BYTE(GOTOLABEL)
            {
                 AiIFRandomGreaterThanRecord *ai = &AiList+Offset;
                if (AiList[Offset - 1] == AI_SetNewRandom)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "IFNewRandomGreaterThan");
                }
                hasLabel = TRUE;
                break;
            }
            case AI_RunToPad: // DBYTE(PAD)
            {
                 AiRunToPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }

                break;
            }

            case AI_WalkToPad: // DBYTE(PAD)
            {
                 AiWalkToPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }

                break;
            }
            case AI_SprintToPad: // DBYTE(PAD)
            {
                 AiSprintToPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }

                break;
            }
            case AI_StartPatrol: // BYTE(PATH_NUM)
            {
                 AiStartPatrolRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }

            case AI_IFImInRoomWithChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFImInRoomWithChrRecord *ai = &AiList+Offset;
                signed char                chr = AiList[Offset + 1];

                if (chr < 0 && chr > -10)
                {
                    printf("%s,", CHR_ToString[abs(chr)]);
                }
                else
                {
                    printf("chr%hd,", chr);
                    AddChr(chr);
                }
                hasLabel = TRUE;
                break;
            }

            case AI_IFRoomWithPadIsOnScreen: // DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFRoomWithPadIsOnScreenRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }

            case AI_IFMyAngleToBondLessThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                 AiIFMyAngleToBondLessThanRecord *ai = &AiList+Offset;
                EraseCommand;
                printf("%s%sDeg(", (char *)tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))));

                hasLabel = TRUE;

                break;
            }
            case AI_IFMyAngleToBondGreaterThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                 AiIFMyAngleToBondGreaterThanRecord *ai = &AiList+Offset;
                EraseCommand;

                printf("%s%sDeg(", (char *)tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))));
                hasLabel = TRUE;

                break;
            }
            case AI_IFMyAngleFromBondLessThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                 AiIFMyAngleFromBondLessThanRecord *ai = &AiList+Offset;
                EraseCommand;

                printf("%s%sDeg(", (char *)tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))));
                hasLabel = TRUE;

                break;
            }
            case AI_IFMyAngleFromBondGreaterThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                 AiIFMyAngleFromBondGreaterThanRecord *ai = &AiList+Offset;
                EraseCommand;

                printf("%s%sDeg(", (char *)tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))));

                hasLabel = TRUE;
                break;
            }
            case AI_IFMyDistanceToBondLessThanDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                 AiIFMyDistanceToBondLessThanDecimeterRecord *ai = &AiList+Offset;
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                EraseCommand;

                printf("%s%s(", (char *)tabs, "IFMyDistanceToBondLessThanMeter");
                printf("%f,", distance / 100);
                hasLabel = TRUE;

                break;
            }
            case AI_IFMyDistanceToBondGreaterThanDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                 AiIFMyDistanceToBondGreaterThanDecimeterRecord *ai = &AiList+Offset;
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                EraseCommand;

                printf("%s%s(", (char *)tabs, "IFMyDistanceToBondGreaterThanMeter");
                printf("%f,", distance / 100);

                hasLabel = TRUE;
                break;
            }
            case AI_IFChrDistanceToPadLessThanDecimeter: // BYTE(CHR_NUM), DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFChrDistanceToPadLessThanDecimeterRecord *ai = &AiList+Offset;
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                float          value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;
                signed char                                   chr   = AiList[Offset + 1];

                EraseCommand;

                if (chr == CHR_SELF)
                {
                    printf("%s%s(", (char *)tabs, "IFMyDistanceToPadLessThanMeter");
                }
                else
                {
                    printf("%s%s(", (char *)tabs, "IFChrDistanceToPadLessThanMeter");
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }
                    printf("%f,", value / 100);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }
            case AI_IFChrDistanceToPadGreaterThanDecimeter: // BYTE(CHR_NUM), DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFChrDistanceToPadGreaterThanDecimeterRecord *ai = &AiList+Offset;
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                 float                                           value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;
                 signed char                                     chr   = AiList[Offset + 1];

                EraseCommand;

                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    printf("%s%s(", (char *)tabs, "IFMyDistanceToPadGreaterThanMeter");
                }
                else
                {
                    printf("%s%s(", (char *)tabs, "IFChrDistanceToPadGreaterThanMeter");
                    if (chr < 0 && chr > -10)
                    {
                        printf("%s,", CHR_ToString[abs(chr)]);
                    }
                    else
                    {
                        printf("chr%hd,", chr);
                        AddChr(chr);
                    }
                }
                    printf("%f,", value / 100);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                hasLabel = TRUE;
                break;
            }
            case AI_IFMyDistanceToChrLessThanDecimeter: // DBYTE(DISTANCE), BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyDistanceToChrLessThanDecimeterRecord *ai = &AiList+Offset;
                float cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                 signed char                                 chr    = AiList[Offset + 3];
                 EraseCommand;

                printf("%s%s(", (char *)tabs, "AIFMyDistanceToChrLessThanMeter");
                printf("%f,", cutoff / 100 );
                if (chr < 0 && chr > -10)
                {
                    printf("%s,", CHR_ToString[abs(chr)]);
                }
                else
                {
                    printf("chr%hd,", chr);
                    AddChr(chr);
                }


                hasLabel = TRUE;
                break;
            }
            case AI_IFMyDistanceToChrGreaterThanDecimeter: // DBYTE(DISTANCE), BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyDistanceToChrGreaterThanDecimeterRecord *ai = &AiList+Offset;
                float                                          cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                signed char                                    chr    = AiList[Offset + 3];

                EraseCommand;

                printf("%s%s(", (char *)tabs, "AIFMyDistanceToChrGreaterThanMeter");
                printf("%f,", cutoff / 100);
                if (chr < 0 && chr > -10)
                {
                    printf("%s,", CHR_ToString[abs(chr)]);
                }
                else
                {
                    printf("chr%hd,", chr);
                    AddChr(chr);
                }

                hasLabel = TRUE;
                break;
            }
            case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                 AiTRYSettingMyPresetToChrWithinDistanceDecimeterRecord *ai = &AiList+Offset;
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                EraseCommand;

                printf("%s%s(", (char *)tabs, "TRYSettingMyPresetToChrWithinDistanceMeter");
                printf("%f,", distance / 100);

                hasLabel = TRUE;
                break;
            }
            case AI_IFBondDistanceToPadLessThanDecimeter: // DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFBondDistanceToPadLessThanDecimeterRecord *ai = &AiList+Offset;
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                EraseCommand;

                printf("%s%s(", (char *)tabs, "IFBondDistanceToPadLessThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }
            case AI_IFBondDistanceToPadGreaterThanDecimeter: // DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFBondDistanceToPadGreaterThanDecimeterRecord *ai = &AiList+Offset;
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;
                EraseCommand;

                printf("%s%s(", (char *)tabs, "IFBondDistanceToPadGreaterThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }
            case AI_IFChrInRoomWithPad: // BYTE(CHR_NUM), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFChrInRoomWithPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);
                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    EraseCommand;
                    printf("%s%s(", (char *)tabs, "IFImInRoomWithPad");
                }
                else
                {
                    printf("%d,", AiList[Offset + 1 + 0]);
                }
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }
            case AI_IFBondInRoomWithPad: // DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFBondInRoomWithPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;
                break;
            }
            case AI_IFBondCollectedObject: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFBondCollectedObjectRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                AddTag(AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_IFKeyDropped: // BYTE(KEY_ID), BYTE(GOTOLABEL)
            {
                 AiIFKeyDroppedRecord *ai = &AiList+Offset;
                printf("key%d,", AiList[Offset + 1]);

                AddKey(AiList[Offset + 1]);
                hasLabel = TRUE;

                break;
            }
            case AI_IFItemIsAttachedToObject: // BYTE(ITEM_NUM), BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFItemIsAttachedToObjectRecord *ai = &AiList+Offset;
                printf("%s,tag%d,", ITEM_IDS_ToString[AiList[Offset + 1]], AiList[Offset + 2]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 2]);

                break;
            }
            case AI_IFBondHasItemEquipped: // BYTE(ITEM_NUM), BYTE(GOTOLABEL)
            {
                 AiIFBondHasItemEquippedRecord *ai = &AiList+Offset;
                printf("%s,", ITEM_IDS_ToString[AiList[Offset + 1]]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFObjectExists: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFObjectExistsRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);
                break;
            }
            case AI_IFObjectNotDestroyed: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFObjectNotDestroyedRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFObjectWasActivated: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFObjectWasActivatedRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFBondUsedGadgetOnObject: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFBondUsedGadgetOnObjectRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_ActivateObject: // BYTE(OBJECT_TAG)
            {
                 AiActivateObjectRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);

                break;
            }
            case AI_DestroyObject: // BYTE(OBJECT_TAG)
            {
                 AiDestroyObjectRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);

                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_DropObject: // BYTE(OBJECT_TAG)
            {
                 AiDropObjectRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_ChrDropAllConcealedItems: // BYTE(CHR_NUM)
            {
                 AiChrDropAllConcealedItemsRecord *ai = &AiList+Offset;
                printf("chr%d", AiList[Offset + 1]);
                AddChr(AiList[Offset + 1]);

                break;
            }
            case AI_ChrDropAllHeldItems: // BYTE(CHR_NUM)
            {
                 AiChrDropAllHeldItemsRecord *ai = &AiList+Offset;
                printf("chr%d", AiList[Offset + 1]);
                AddChr(AiList[Offset + 1]);

                break;
            }
            case AI_BondCollectObject: // BYTE(OBJECT_TAG)
            {
                 AiBondCollectObjectRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_ChrEquipObject: // BYTE(OBJECT_TAG), BYTE(CHR_NUM)
            {
                 AiChrEquipObjectRecord *ai = &AiList+Offset;
                printf("tag%d,chr%d", AiList[Offset + 1], AiList[Offset + 2]);
                AddTag(AiList[Offset + 1]);
                AddChr(AiList[Offset + 2]);

                break;
            }
            case AI_MoveObject: // BYTE(OBJECT_TAG), DBYTE(PAD)
            {
                 AiMoveObjectRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("tag%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                AddTag(AiList[Offset + 1]);
                AddPad(pad);

                break;
            }
            case AI_DoorOpen: // BYTE(OBJECT_TAG)
            {
                 AiDoorOpenRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_DoorClose: // BYTE(OBJECT_TAG)
            {
                 AiDoorCloseRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFDoorStateEqual: // BYTE(OBJECT_TAG), BYTE(DOOR_STATE), BYTE(GOTOLABEL)
            {
                 AiIFDoorStateEqualRecord *ai = &AiList+Offset;
                printf("tag%d,%s,", AiList[Offset + 1], DOORSTATE_ToString[AiList[Offset + 2] >> 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFDoorHasBeenOpenedBefore: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                 AiIFDoorHasBeenOpenedBeforeRecord *ai = &AiList+Offset;
                printf("tag%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_DoorSetLock: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG)
            {
                 AiDoorSetLockRecord *ai = &AiList+Offset;
                printf("tag%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_DoorUnsetLock: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG)
            {
                 AiDoorUnsetLockRecord *ai = &AiList+Offset;
                printf("tag%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFDoorLockEqual: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG), BYTE(GOTOLABEL)
            {
                 AiIFDoorLockEqualRecord *ai = &AiList+Offset;
                printf("tag%d,%d,%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                AddTag(AiList[Offset + 1]);

                break;
            }
            case AI_IFObjectiveNumComplete: // BYTE(OBJ_NUM), BYTE(GOTOLABEL)
            {
                 AiIFObjectiveNumCompleteRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_TRYUnknown6e: // BYTE(UNKNOWN_FLAG), BYTE(GOTOLABEL)
            {
                 AiTRYUnknown6eRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_TRYUnknown6f: // BYTE(UNKNOWN_FLAG), BYTE(GOTOLABEL)
            {
                 AiTRYUnknown6fRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFMyNumArghsLessThan: // BYTE(HIT_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyNumArghsLessThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFMyNumArghsGreaterThan: // BYTE(HIT_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyNumArghsGreaterThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);
                hasLabel = TRUE;
                break;
            }
            case AI_IFMyNumCloseArghsLessThan: // BYTE(MISSED_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyNumCloseArghsLessThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFMyNumCloseArghsGreaterThan: // BYTE(MISSED_NUM), BYTE(GOTOLABEL)
            {
                 AiIFMyNumCloseArghsGreaterThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFChrHealthLessThan: // BYTE(CHR_NUM), BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                 AiIFChrHealthLessThanRecord *ai = &AiList+Offset;
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%d,%f,", AiList[Offset + 1], value * 10);

                hasLabel = TRUE;
                AddChr(AiList[Offset + 1]);

                break;
            }
            case AI_IFChrHealthGreaterThan: // BYTE(CHR_NUM), BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                 AiIFChrHealthGreaterThanRecord *ai = &AiList+Offset;
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%d,%f,", AiList[Offset + 1], value * 10);

                hasLabel = TRUE;
                AddChr(AiList[Offset + 1]);

                break;
            }
            case AI_IFChrWasDamagedSinceLastCheck: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFChrWasDamagedSinceLastCheckRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                AddChr(AiList[Offset + 1]);

                break;
            }
            case AI_IFBondHealthLessThan: // BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                 AiIFBondHealthLessThanRecord *ai = &AiList+Offset;
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%f,", val * 255);

                hasLabel = TRUE;
                break;
            }
            case AI_IFBondHealthGreaterThan: // BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                 AiIFBondHealthGreaterThanRecord *ai = &AiList+Offset;
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%f,", val * 255);

                hasLabel = TRUE;
                break;
            }
            case AI_IFGameDifficultyLessThan: // BYTE(DIFICULTY_ID), BYTE(GOTOLABEL)
            {
                 AiIFGameDifficultyLessThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFGameDifficultyGreaterThan: // BYTE(DIFICULTY_ID), BYTE(GOTOLABEL)
            {
                 AiIFGameDifficultyGreaterThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFMissionTimeLessThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                 AiIFMissionTimeLessThanRecord *ai = &AiList+Offset;
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", target);

                hasLabel = TRUE;
                break;
            }
            case AI_IFMissionTimeGreaterThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                 AiIFMissionTimeGreaterThanRecord *ai = &AiList+Offset;
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", target);

                hasLabel = TRUE;
                break;
            }
            case AI_IFSystemPowerTimeLessThan: // DBYTE(MINUTES), BYTE(GOTOLABEL)
            {
                 AiIFSystemPowerTimeLessThanRecord *ai = &AiList+Offset;
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", target);

                break;
            }
            case AI_IFSystemPowerTimeGreaterThan: // DBYTE(MINUTES), BYTE(GOTOLABEL)
            {
                 AiIFSystemPowerTimeGreaterThanRecord *ai = &AiList+Offset;
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", target);

                hasLabel = TRUE;
                break;
            }
            case AI_IFLevelIdLessThan: // BYTE(LEVEL_ID), BYTE(GOTOLABEL)
            {
                 AiIFLevelIdLessThanRecord *ai = &AiList+Offset;
                printf("%s,", LEVELID_ToString[AiList[Offset + 1] + 1]);

                hasLabel = TRUE;
                break;
            }
            case AI_IFLevelIdGreaterThan: // BYTE(LEVEL_ID), BYTE(GOTOLABEL)
            {
                 AiIFLevelIdGreaterThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_SetMyMorale: // BYTE(CHRBYTE)
            {
                 AiSetMyMoraleRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_AddToMyMorale: // BYTE(CHRBYTE)
            {
                 AiAddToMyMoraleRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SubtractFromMyMorale: // BYTE(CHRBYTE)
            {
                 AiSubtractFromMyMoraleRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_IFMyMoraleLessThan: // BYTE(CHRBYTE), BYTE(GOTOLABEL)
            {
                 AiIFMyMoraleLessThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }

            case AI_SetMyAlertness: // BYTE(CHRBYTE)
            {
                 AiSetMyAlertnessRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_AddToMyAlertness: // BYTE(CHRBYTE)
            {
                 AiAddToMyAlertnessRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SubtractFromMyAlertness: // BYTE(CHRBYTE)
            {
                 AiSubtractFromMyAlertnessRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_IFMyAlertnessLessThan: // BYTE(CHRBYTE), BYTE(GOTOLABEL)
            {
                 AiIFMyAlertnessLessThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_SetMyHearingScale: // DBYTE(HEARING_SCALE)
            {
                 AiSetMyHearingScaleRecord *ai = &AiList+Offset;
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) / 1000.0f;

                printf("%f", distance * 1000);

                break;
            }
            case AI_SetMyVisionRange: // BYTE(VISION_RANGE)
            {
                 AiSetMyVisionRangeRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyGrenadeProbability: // BYTE(GRENADE_PROB)
            {
                 AiSetMyGrenadeProbabilityRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyChrNum: // BYTE(CHR_NUM)
            {
                 AiSetMyChrNumRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyHealthTotal: // DBYTE(HEALTH)
            {
                 AiSetMyHealthTotalRecord *ai = &AiList+Offset;
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f;

                printf("%f", amount * 10);

                break;
            }
            case AI_SetMyArmour: // DBYTE(AMOUNT)
            {
                 AiSetMyArmourRecord *ai = &AiList+Offset;
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f; /*if (cheatIsActive(CHEAT_ENEMYSHIELDS)) { amount = amount < 8 ? 8 : amount; } */

                printf("%f", amount * 10);

                break;
            }
            case AI_SetMySpeedRating: // BYTE(SPEED_RATING)
            {
                 AiSetMySpeedRatingRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyArghRating: // BYTE(ARGH_RATING)
            {
                 AiSetMyArghRatingRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyAccuracyRating: // BYTE(ACCURACY_RATING)
            {
                 AiSetMyAccuracyRatingRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetMyFlags2: // BYTE(BITS)
            {
                 AiSetMyFlags2Record *ai = &AiList+Offset;
                printf("0x%x", AiList[Offset + 1]);

                break;
            }
            case AI_UnsetMyFlags2: // BYTE(BITS)
            {
                 AiUnsetMyFlags2Record *ai = &AiList+Offset;
                printf("0x%x", AiList[Offset + 1]);

                break;
            }
            case AI_IFMyFlags2Has: // BYTE(BITS) BYTE(GOTOLABEL)
            {
                 AiIFMyFlags2HasRecord *ai = &AiList+Offset;
                printf("0x%x,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_SetChrBitfield: // BYTE(CHR_NUM), BYTE(BITS)
            {
                 AiSetChrBitfieldRecord *ai = &AiList+Offset;
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);

                break;
            }
            case AI_UnsetChrBitfield: // BYTE(CHR_NUM), BYTE(BITS)
            {
                 AiUnsetChrBitfieldRecord *ai = &AiList+Offset;
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);

                break;
            }
            case AI_IFChrBitfieldHas: // BYTE(CHR_NUM), BYTE(BITS), BYTE(GOTOLABEL)
            {
                 AiIFChrBitfieldHasRecord *ai = &AiList+Offset;
                printf("%d,0x%x,", AiList[Offset + 1], AiList[Offset + 2]);

                hasLabel = TRUE;

                break;
            }
            case AI_SetObjectiveBitfield: // QBYTE(BITFIELD)
            {
                 AiSetObjectiveBitfieldRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x", flags);

                break;
            }
            case AI_UnsetObjectiveBitfield: // QBYTE(BITFIELD)
            {
                 AiUnsetObjectiveBitfieldRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x", flags);

                break;
            }
            case AI_IFObjectiveBitfieldHas: // QBYTE(BITS), BYTE(GOTOLABEL)
            {
                 AiIFObjectiveBitfieldHasRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x,", flags);

                hasLabel = TRUE;

                break;
            }
            case AI_SetMychrflags: // QBYTE(CHRFLAGS)
            {
                 AiSetMychrflagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x", flags);

                break;
            }
            case AI_UnsetMychrflags: // QBYTE(CHRFLAGS)
            {
                 AiUnsetMychrflagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x", flags);

                break;
            }
            case AI_IFMychrflagsHas: // QBYTE(CHRFLAGS), BYTE(GOTOLABEL)
            {
                 AiIFMychrflagsHasRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("0x%x,", flags);

                hasLabel = TRUE;

                break;
            }
            case AI_SetChrchrflags: // BYTE(CHR_NUM), QBYTE(CHRFLAGS)
            {
                 AiSetChrchrflagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_UnsetChrchrflags: // BYTE(CHR_NUM), QBYTE(CHRFLAGS)
            {
                 AiUnsetChrchrflagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_IFChrchrflagsHas: // BYTE(CHR_NUM), QBYTE(CHRFLAGS), BYTE(GOTOLABEL)
            {
                 AiIFChrchrflagsHasRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x,", AiList[Offset + 1], flags);

                hasLabel = TRUE;

                break;
            }
            case AI_SetObjectFlags: // BYTE(OBJECT_TAG), QBYTE(BITFIELD)
            {
                 AiSetObjectFlagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_UnsetObjectFlags: // BYTE(OBJECT_TAG), QBYTE(BITFIELD)
            {
                 AiUnsetObjectFlagsRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_IFObjectFlagsHas: // BYTE(OBJECT_TAG), QBYTE(BITS), BYTE(GOTOLABEL)
            {
                 AiIFObjectFlagsHasRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x,", AiList[Offset + 1], flags);

                hasLabel = TRUE;

                break;
            }
            case AI_SetObjectFlags2: // BYTE(OBJECT_TAG), QBYTE(BITS)
            {
                 AiSetObjectFlags2Record *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_UnsetObjectFlags2: // BYTE(OBJECT_TAG), QBYTE(BITS)
            {
                 AiUnsetObjectFlags2Record *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x", AiList[Offset + 1], flags);

                break;
            }
            case AI_IFObjectFlags2Has: // BYTE(OBJECT_TAG), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                 AiIFObjectFlags2HasRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%d,0x%x,", AiList[Offset + 1], flags);

                hasLabel = TRUE;

                break;
            }
            case AI_SetMyChrPreset: // BYTE(CHR_PRESET)
            {
                 AiSetMyChrPresetRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }
            case AI_SetChrChrPreset: // BYTE(CHR_NUM), BYTE(CHR_PRESET)
            {
                 AiSetChrChrPresetRecord *ai = &AiList+Offset;
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);

                break;
            }
            case AI_SetMyPadPreset: // DBYTE(PAD_PRESET)
            {
                 AiSetMyPadPresetRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }

                break;
            }
            case AI_SetChrPadPreset: // BYTE(CHR_NUM), DBYTE(PAD_PRESET)
            {
                 AiSetChrPadPresetRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s(%d,", AI_CMD_ToString[AiList[Offset]], AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }

                break;
            }
            case AI_PRINT:
            {
                 AiPRINTRecord *ai = &AiList+Offset;
                int j = 1;
                printf("\"");
                for (; AiList[Offset + j] != 0; j++)
                {
                    if (AiList[Offset + j] == '\n')
                    {
                        printf("\\n");
                    }
                    else
                    {
                        printf("%c", AiList[Offset + j]);
                    }
                }
                if (!hasName)
                {
                    hasName = malloc(j);
                    hasName = &AiList[Offset + 1];
                }

                printf("\"");
                break;
            }

            case AI_IFMyTimerLessThanTicks: // TBYTE(TICKS), BYTE(GOTOLABEL)
            {
                 AiIFMyTimerLessThanTicksRecord *ai = &AiList+Offset;
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%f,", valf);

                hasLabel = TRUE;

                break;
            }
            case AI_IFMyTimerGreaterThanTicks: // TBYTE(TICKS), BYTE(GOTOLABEL)
            {
                 AiIFMyTimerGreaterThanTicksRecord *ai = &AiList+Offset;
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%f,", valf);

                hasLabel = TRUE;

                break;
            }

            case AI_HudCountdownSet: // DBYTE(SECONDS)
            {
                 AiHudCountdownSetRecord *ai = &AiList+Offset;
                float seconds = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f", seconds);

                break;
            }

            case AI_IFHudCountdownLessThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                 AiIFHudCountdownLessThanRecord *ai = &AiList+Offset;
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", value);

                hasLabel = TRUE;

                break;
            }
            case AI_IFHudCountdownGreaterThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                 AiIFHudCountdownGreaterThanRecord *ai = &AiList+Offset;
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", value);

                hasLabel = TRUE;

                break;
            }
            case AI_TRYSpawningChrAtPad: // BYTE(BODY_NUM), BYTE(HEAD_NUM), DBYTE(PAD), DBYTE(AI_LIST_ID), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                 AiTRYSpawningChrAtPadRecord *ai = &AiList+Offset;
                unsigned short pad      = CharArrayTo16(AiList, Offset + 1 + 2);
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 6);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 4);

                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,0x%x,%d,", ailistid, flags, AiList[Offset + 10]);

                hasLabel = TRUE;

                break;
            }
            case AI_TRYSpawningChrNextToChr: // BYTE(BODY_NUM), BYTE(HEAD_NUM), BYTE(CHR_NUM_TARGET), DBYTE(AI_LIST_ID), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                 AiTRYSpawningChrNextToChrRecord *ai = &AiList+Offset;
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 5);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 3);

                printf("%d,%d,%d,%d,0x%x,", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2], ailistid, flags);

                hasLabel = TRUE;
                break;
            }
            case AI_TRYGiveMeItem: // DBYTE(PROP_NUM), BYTE(ITEM_NUM), QBYTE(PROPFLAG), BYTE(GOTOLABEL)
            {
                 AiTRYGiveMeItemRecord *ai = &AiList+Offset;
                int flags = CharArrayTo32(AiList, Offset + 1 + 3);
                int model = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%d,%d,0x%x,", model, AiList[Offset + 1 + 2], flags);

                hasLabel = TRUE;

                break;
            }
            case AI_TRYGiveMeHat: // DBYTE(PROP_NUM), QBYTE(PROP_BITFIELD), BYTE(GOTOLABEL)
            {
                 AiTRYGiveMeHatRecord *ai = &AiList+Offset;
                int flags    = CharArrayTo32(AiList, Offset + 1 + 2);
                int modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%d,0x%x,", modelnum, flags);

                hasLabel = TRUE;
                break;
            }
            case AI_TRYCloningChr: // BYTE(CHR_NUM), DBYTE(AI_LIST_ID), BYTE(GOTOLABEL)
            {
                 AiTRYCloningChrRecord *ai = &AiList+Offset;
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%d,%d,", AiList[Offset + 4], ailistid);

                hasLabel = TRUE;
                break;
            }
            case AI_TextPrintBottom: // DBYTE(TEXT_SLOT)
            {
                 AiTextPrintBottomRecord *ai = &AiList+Offset;
                // printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));

                printf("TEXT(%s,%d)", TEXTBANK_LEVEL_INDEX_ToString[(CharArrayTo16(AiList, Offset + 1 + 0)) / 1024], (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);

                break;
            }
            case AI_TextPrintTop: // DBYTE(TEXT_SLOT)
            {
                 AiTextPrintTopRecord *ai = &AiList+Offset;
                // printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));

                printf("TEXT(%s,%d)", TEXTBANK_LEVEL_INDEX_ToString[(CharArrayTo16(AiList, Offset + 1 + 0)) / 1024], (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);

                break;
            }
            case AI_SfxPlay: // DBYTE(SOUND_NUM), BYTE(CHANNEL_NUM)
            {
                 AiSfxPlayRecord *ai = &AiList+Offset;
                short audio_id = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%d,%d", audio_id, AiList[Offset + 3]);

                break;
            }
            case AI_SfxStopChannel: // BYTE(CHANNEL_NUM)
            {
                 AiSfxStopChannelRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 3]);

                break;
            }
            case AI_SfxSetChannelVolume: // BYTE(CHANNEL_NUM), DBYTE(TARGET_VOLUME), DBYTE(TRANSITION_TIME60)
            {
                 AiSfxSetChannelVolumeRecord *ai = &AiList+Offset;
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);

                break;
            }
            case AI_SfxFadeChannelVolume: // BYTE(CHANNEL_NUM), DBYTE(TARGET_VOLUME), DBYTE(TRANSITION_TIME60)
            {
                 AiSfxFadeChannelVolumeRecord *ai = &AiList+Offset;
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);

                break;
            }
            case AI_SfxEmitFromObject: // BYTE(CHANNEL_NUM), BYTE(OBJECT_TAG), DBYTE(VOL_DECAY_TIME60)
            {
                 AiSfxEmitFromObjectRecord *ai = &AiList+Offset;
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 1);

                printf("%d, %d,%d", AiList[Offset + 1], AiList[Offset + 2], sfxID);

                break;
            }
            case AI_SfxEmitFromPad: // BYTE(CHANNEL_NUM), DBYTE(PAD), DBYTE(VOL_DECAY_TIME60)
            {
                 AiSfxEmitFromPadRecord *ai = &AiList+Offset;
                unsigned short pad   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("%d", sfxID);

                break;
            }
            case AI_IFSfxChannelVolumeLessThan: // BYTE(CHANNEL_NUM), DBYTE(VOLUME), BYTE(GOTOLABEL)
            {
                 AiIFSfxChannelVolumeLessThanRecord *ai = &AiList+Offset;
                short vol = CharArrayTo16(AiList, Offset + 2 + 0);

                printf("%d, %d,", AiList[Offset + 1], vol);

                hasLabel = TRUE;
                break;
            }
            case AI_VehicleStartPath: // BYTE(PATH_NUM)
            {
                 AiVehicleStartPathRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1 + 0]);

                break;
            }
            case AI_VehicleSpeed: // DBYTE(TOP_SPEED), DBYTE(ACCELERATION_TIME60)
            {
                 AiVehicleSpeedRecord *ai = &AiList+Offset;
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * 100.0f / 15360.0f;

                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);

                break;
            }
            case AI_AircraftRotorSpeed: // DBYTE(ROTOR_SPEED), DBYTE(ACCELERATION_TIME60)
            {
                 AiAircraftRotorSpeedRecord *ai = &AiList+Offset;
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * M_TAU_F / 3600.0f;

                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);

                break;
            }
            case AI_TvChangeScreenBank: // BYTE(OBJECT_TAG), BYTE(SCREEN_INDEX), BYTE(SCREEN_BANK)
            {
                 AiTvChangeScreenBankRecord *ai = &AiList+Offset;
                printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);

                break;
            }

            case AI_CameraLookAtBondFromPad: // DBYTE(PAD)
            {
                 AiCameraLookAtBondFromPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                break;
            }
            case AI_CameraSwitch: // BYTE(OBJECT_TAG), DBYTE(LOOK_AT_BOND_FLAG), DBYTE(UNUSED_FLAG)
            {
                 AiCameraSwitchRecord *ai = &AiList+Offset;
                printf("%d,%d,%d", AiList[Offset + 1 + 0], CharArrayTo16(AiList, Offset + 1 + 1), CharArrayTo16(AiList, Offset + 1 + 3));

                break;
            }
            case AI_IFBondYPosLessThan: // DBYTE(Y_POS), BYTE(GOTOLABEL)
            {
                 AiIFBondYPosLessThanRecord *ai = &AiList+Offset;
                float bondpos = (short)CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%f,", bondpos );
                hasLabel = TRUE;

                break;
            }
            case AI_BondDisableControl: // BYTE(BITFIELD)
            {
                 AiBondDisableControlRecord *ai = &AiList+Offset;
                printf("%d", AiList[Offset + 1]);

                break;
            }

            case AI_TRYTeleportingChrToPad: // BYTE(CHR_NUM), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiTRYTeleportingChrToPadRecord *ai = &AiList+Offset;
                int pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                hasLabel = TRUE;

                break;
            }

            case AI_DoorOpenInstant: // BYTE(OBJECT_TAG)
            {
                 AiDoorOpenInstantRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);

                break;
            }
            case AI_ChrRemoveItemInHand: // BYTE(CHR_NUM), BYTE(HAND_INDEX)
            {
                 AiChrRemoveItemInHandRecord *ai = &AiList+Offset;
                printf("chr%d,%s", AiList[Offset + 1], AiList[Offset + 2] == 0 ? "GUNRIGHT" : "GUNLEFT");

                break;
            }
            case AI_IfNumberOfActivePlayersLessThan: // BYTE(NUMBER), BYTE(GOTOLABEL)
            {
                 AiIfNumberOfActivePlayersLessThanRecord *ai = &AiList+Offset;
                if (AiList[Offset + 1] == 2)
                {
                    printf("%sIFSinglePlayer(", (char *)tabs);
                }
                else
                {
                    printf("%d,", AiList[Offset + 1]);
                }

                hasLabel = TRUE;

                break;
            }
            case AI_IFBondItemTotalAmmoLessThan: // BYTE(ITEM_NUM), BYTE(AMMO_TOTAL), BYTE(GOTOLABEL)
            {
                 AiIFBondItemTotalAmmoLessThanRecord *ai = &AiList+Offset;
                printf("%s,%d,", ITEM_IDS_ToString[AiList[Offset + 1]], AiList[Offset + 2]);

                hasLabel = TRUE;

                break;
            }
            case AI_BondEquipItem: // BYTE(ITEM_NUM)
            {
                 AiBondEquipItemRecord *ai = &AiList+Offset;
                printf("%s", ITEM_IDS_ToString[AiList[Offset + 1]]);

                break;
            }
            case AI_BondEquipItemCinema: // BYTE(ITEM_NUM)
            {
                 AiBondEquipItemCinemaRecord *ai = &AiList+Offset;
                printf("%s", ITEM_IDS_ToString[ AiList[Offset + 1]]);

                break;
            }
            case AI_BondSetLockedVelocity: // BYTE(X_SPEED60), BYTE(Z_SPEED60)
            {
                 AiBondSetLockedVelocityRecord *ai = &AiList+Offset;
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);

                break;
            }
            case AI_IFObjectInRoomWithPad: // BYTE(OBJECT_TAG), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                 AiIFObjectInRoomWithPadRecord *ai = &AiList+Offset;
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("tag%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                hasLabel = TRUE;

                break;
            }

            case AI_CameraOrbitPad:
            {
                 AiCameraOrbitPadRecord *ai = &AiList+Offset;
                int pad;
                int speed60;
                int camDististance;
                int targetHeight;
                int camHeight;
                int start;
                camDististance = CharArrayTo16(AiList, Offset + 1 + 0);
                camHeight      = (short)CharArrayTo16(AiList, Offset + 1 + 2);
                speed60        = (short)CharArrayTo16(AiList, Offset + 1 + 4);
                pad            = CharArrayTo16(AiList, Offset + 1 + 6);
                targetHeight   = (short)CharArrayTo16(AiList, Offset + 1 + 8);
                start          = CharArrayTo16(AiList, Offset + 1 + 10);

                printf("%d,%d,%d,", camDististance, camHeight, speed60);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,%d", targetHeight, start);

                break;
            }

            case AI_IFFolderActorIsEqual: // BYTE(BOND_ACTOR_INDEX), BYTE(GOTOLABEL)
            {
                 AiIFFolderActorIsEqualRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }

            case AI_MusicPlaySlot: // BYTE(MUSIC_SLOT), BYTE(SECONDS_STOPPED_DURATION), BYTE(SECONDS_TOTAL_DURATION)
            {
                 AiMusicPlaySlotRecord *ai = &AiList+Offset;
                // printf("/*ai: enery tune on (%d, %d, %d)*/", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);

                printf("%d,%d,%d", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);

                break;
            }
            case AI_MusicStopSlot:
            {
                 AiMusicStopSlotRecord *ai = &AiList+Offset;
                // printf("/*ai: enery tune off (%d)*/", AiList[Offset + 1 + 0]);

                printf("%d", AiList[Offset + 1 + 0]);

                break;
            }
            case AI_IFKilledCiviliansGreaterThan:
            {
                 AiIFKilledCiviliansGreaterThanRecord *ai = &AiList+Offset;
                printf("%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_IFChrWasShotSinceLastCheck: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                 AiIFChrWasShotSinceLastCheckRecord *ai = &AiList+Offset;
                printf("chr%d,", AiList[Offset + 1]);

                hasLabel = TRUE;

                break;
            }
            case AI_ObjectRocketLaunch: // BYTE(OBJECT_TAG)
            {
                 AiObjectRocketLaunchRecord *ai = &AiList+Offset;
                printf("tag%d", AiList[Offset + 1]);

                break;
            }
            case AI_GotoNext:                    // BYTE(LABEL)
            case AI_IFPlayingAnimation:          // BYTE(GOTOLABEL)
            case AI_IFImOnPatrolOrStopped:       // BYTE(GOTOLABEL)
            case AI_IFISeeBond:                  // BYTE(GOTOLABEL)
            case AI_TRYSidestepping:             // BYTE(GOTOLABEL)
            case AI_TRYSideHopping:              // BYTE(GOTOLABEL)
            case AI_TRYSideRunning:              // BYTE(GOTOLABEL)
            case AI_TRYFiringWalk:               // BYTE(GOTOLABEL)
            case AI_TRYFiringRun:                // BYTE(GOTOLABEL)
            case AI_TRYFiringRoll:               // BYTE(GOTOLABEL)
            case AI_IFImFiringAndLockedForward:  // BYTE(GOTOLABEL)
            case AI_IFImFiring:                  // BYTE(GOTOLABEL)
            case AI_TRYThrowingGrenade:          // BYTE(GOTOLABEL)
            case AI_TRYRunFromBond:              // BYTE(GOTOLABEL)
            case AI_TRYRunToBond:                // BYTE(GOTOLABEL)
            case AI_TRYWalkToBond:               // BYTE(GOTOLABEL)
            case AI_TRYSprintToBond:             // BYTE(GOTOLABEL)
            case AI_TRYFindCover:                // BYTE(GOTOLABEL)
            case AI_IFICanHearAlarm:             // BYTE(GOTOLABEL)
            case AI_IFAlarmIsOn:                 // BYTE(GOTOLABEL)
            case AI_IFGasIsLeaking:              // BYTE(GOTOLABEL)
            case AI_IFIHeardBond:                // BYTE(GOTOLABEL)
            case AI_IFISeeSomeoneShot:           // BYTE(GOTOLABEL)
            case AI_IFISeeSomeoneDie:            // BYTE(GOTOLABEL)
            case AI_IFICouldSeeBond:             // BYTE(GOTOLABEL)
            case AI_IFICouldSeeBondsStan:        // BYTE(GOTOLABEL)
            case AI_IFIWasShotRecently:          // BYTE(GOTOLABEL)
            case AI_IFIHeardBondRecently:        // BYTE(GOTOLABEL)
            case AI_IFIveNotBeenSeen:            // BYTE(GOTOLABEL)
            case AI_IFImOnScreen:                // BYTE(GOTOLABEL)
            case AI_IFMyRoomIsOnScreen:          // BYTE(GOTOLABEL)
            case AI_IFImTargetedByBond:          // BYTE(GOTOLABEL)
            case AI_IFBondMissedMe:              // BYTE(GOTOLABEL)
            case AI_IFMyMoraleLessThanRandom:    // BYTE(GOTOLABEL)
            case AI_IFMyAlertnessLessThanRandom: // BYTE(GOTOLABEL)
            case AI_IFMyTimerIsNotRunning:       // BYTE(GOTOLABEL)
            case AI_IFHudCountdownIsNotRunning:  // BYTE(GOTOLABEL)
            case AI_IFCameraIsInIntro:           // BYTE(GOTOLABEL)
            case AI_IFCameraIsInBondSwirl:       // BYTE(GOTOLABEL)
            case AI_IFBondInTank:                // canonical name
            case AI_IFScreenFadeCompleted:       // BYTE(GOTOLABEL)
            case AI_IFBondIsDead:
            case AI_IFCreditsHasCompleted:
            case AI_IFObjectiveAllCompleted:
            case AI_IFBondDamageAndPickupsDisabled:
            {
                 AiIFBondDamageAndPickupsDisabledRecord *ai = &AiList+Offset;
                hasLabel = TRUE;
                break;
            }
            case AI_Yield:         // /*NONE*/
            case AI_Stop:          // /*NONE*/
            case AI_Kneel:         // /*NONE*/
            case AI_PointAtBond:   // /*NONE*/
            case AI_LookSurprised: // /*NONE*/
            case AI_Surrender:     // /*NONE*/
            case AI_RemoveMe:      // /*NONE*/
            case AI_AlarmOn:
            case AI_AlarmOff:
            case AI_RunToPadPreset: // /*NONE*/
            case AI_MyTimerStart:
            case AI_MyTimerReset:
            case AI_MyTimerPause:
            case AI_MyTimerResume:
            case AI_HudCountdownShow:
            case AI_HudCountdownHide:
            case AI_HudCountdownStop:
            case AI_HudCountdownStart:
            case AI_EndLevel: // canonical name
            case AI_CameraReturnToBond:
            case AI_BondEnableControl:
            case AI_ScreenFadeToBlack:
            case AI_ScreenFadeFromBlack:
            case AI_HideAllChrs:
            case AI_ShowAllChrs:
            case AI_TriggerFadeAndExitLevelOnButtonPress:
            case AI_BondDisableDamageAndPickups:
            case AI_BondHideWeapons:
            case AI_CreditsRoll:
            case AI_SwitchSky:
            case AI_BondKilledInAction:
            case AI_RaiseArms:
            case AI_TriggerExplosionsAroundBond:
            case AI_GasLeakAndFadeFog:
            default:
            {
                break;
            }

        } // switch
        if(!hasMacro)Offset += chraiitemsize(AiList, Offset);
        if (hasLabel)
        {
            printf(" lbl%d ", AiList[Offset - 1]);
            AddLabel(AiList[Offset - 1]);
        }
        if (!hasClosingBrace) printf(")\n");
    }
}

void hexDump(char *desc, void *addr, int len)
{
    int            i;
    unsigned char  buff[17];
    unsigned char *pc = (unsigned char *)addr;

    // Output description if given.
    if (desc != NULL)
        printf("%s:\n", desc);

    // Process every byte in the data.
    for (i = 0; i < len; i++)
    {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0)
        {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf("  %s\n", buff);

            // Output the offset.
            printf("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf(" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
        {
            buff[i % 16] = '.';
        }
        else
        {
            buff[i % 16] = pc[i];
        }

        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0)
    {
        printf("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf("  %s\n", buff);
}

int main(int argc, char *argv[])
{
#define PRINTDEBUG
    char                    fname[1000];
    FILE                   *pfile;
    char                    cwd[1000];
    void                   *g_ptrStageSetupFile, *lastAddr;
    int                     fsize;


    int                     i,j;
    time_t                  current_time;
    time(&current_time);

    getcwd(cwd, sizeof(cwd));

    if (argc > 1)
    {
        strcat(cwd, "/");
        strcat(cwd, argv[1]);
        strcpy(fname,argv[1]);
    }
    else
    {
        printf("Enter a filename:\n");
        scanf("%99s", fname);
        strcat(cwd, "/");
        strcat(cwd, fname);
    }

    for (i=strlen(fname); i>0; i-- )
    {
        j = i+1;
        if (fname[i] == '/')  break;
    }

    for (i = 0; i < strlen(fname); i++, j++)
    {
        if (fname[j] == '.')
        {
            fname[i] = 0;
            break;
        }
        fname[i] = fname[j];
    }
    pfile = fopen(cwd, "rb");

    if (!pfile)
    {
        printf("Error! opening file: %s\n", cwd);
        // exit from program if file pointer returns NULL.
        return 0;
    }

    // Get file size
    fseek(pfile, 0, SEEK_END);
    fsize = ftell(pfile);
    rewind(pfile);

    //allocate setup file
    g_ptrStageSetupFile = malloc(fsize);
    rewind(pfile);

    //Load setup file
    if (1 != fread(g_ptrStageSetupFile, fsize, 1, pfile))
    {
        fclose(pfile);
        free(g_ptrStageSetupFile);
        printf("entire read fails\n");
        return 0;
    }
    fclose(pfile);

    {
        stagesetup g_chraiCurrentSetup = *(stagesetup *)g_ptrStageSetupFile;

        // convert to host endian and turn file pointer to RAM pointer
        g_chraiCurrentSetup.pathwaypoints  = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.pathwaypoints);
        g_chraiCurrentSetup.waypointgroups = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.waypointgroups);
        g_chraiCurrentSetup.intro          = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.intro);
        g_chraiCurrentSetup.propDefs       = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.propDefs);
        g_chraiCurrentSetup.patrolpaths    = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.patrolpaths);
        g_chraiCurrentSetup.ailists        = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.ailists);
        g_chraiCurrentSetup.pads           = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.pads);
        g_chraiCurrentSetup.boundpads      = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.boundpads);
        g_chraiCurrentSetup.padnames       = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.padnames);
        g_chraiCurrentSetup.boundpadnames  = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.boundpadnames);

        // iterate over all items and sub-items converting from file to ram pointer
#pragma region "foreach item in setupheader"
        if (g_chraiCurrentSetup.pathwaypoints)
        {
            // NAV Points - use Pads as NavPoints
            for (i = 0; g_chraiCurrentSetup.pathwaypoints[i].padID >= 0; i++)
            {
                btol(g_chraiCurrentSetup.pathwaypoints[i].padID);
                g_chraiCurrentSetup.pathwaypoints[i].neighbours = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.pathwaypoints[i].neighbours);
                btol(g_chraiCurrentSetup.pathwaypoints[i].groupNum);
                btol(g_chraiCurrentSetup.pathwaypoints[i].dist);
#ifdef PRINTDEBUG
                printf("\nwaypoint %d: pad %d, nb %X, GN %d, dst%d\n", i, g_chraiCurrentSetup.pathwaypoints[i].padID, g_chraiCurrentSetup.pathwaypoints[i].neighbours, g_chraiCurrentSetup.pathwaypoints[i].groupNum, g_chraiCurrentSetup.pathwaypoints[i].dist);
#endif
                for (j = 0; g_chraiCurrentSetup.pathwaypoints[i].neighbours[j] >= 0; j++)
                {
                    btol(g_chraiCurrentSetup.pathwaypoints[i].neighbours[j]);
#ifdef PRINTDEBUG
                    printf("%d, ", g_chraiCurrentSetup.pathwaypoints[i].neighbours[j]);
#endif
                }
            }
        }

        if (g_chraiCurrentSetup.waypointgroups)
        {
            // NAV Mesh, make a mesh from NAV Points
            for (i = 0; g_chraiCurrentSetup.waypointgroups[i].neighbours; i++)
            {
                g_chraiCurrentSetup.waypointgroups[i].neighbours = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.waypointgroups[i].neighbours);
                g_chraiCurrentSetup.waypointgroups[i].waypoints  = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.waypointgroups[i].waypoints);
#ifdef PRINTDEBUG
                printf("\nwaygrp %d: nb %X, wp%X, dst%d\n", i, g_chraiCurrentSetup.waypointgroups[i].neighbours, g_chraiCurrentSetup.waypointgroups[i].waypoints, g_chraiCurrentSetup.waypointgroups[i].dist);
#endif
                for (j = 0; g_chraiCurrentSetup.waypointgroups[i].neighbours[j] >= 0; j++)
                {
                    btol(g_chraiCurrentSetup.waypointgroups[i].neighbours[j]);
#ifdef PRINTDEBUG
                    printf("%d, ", g_chraiCurrentSetup.waypointgroups[i].neighbours[j]);
#endif
                }
#ifdef PRINTDEBUG
                printf("\n");
#endif
                for (j = 0; g_chraiCurrentSetup.waypointgroups[i].waypoints[j] >= 0; j++)
                {
                    btol(g_chraiCurrentSetup.waypointgroups[i].waypoints[j]);
#ifdef PRINTDEBUG
                    printf("%d, ", g_chraiCurrentSetup.waypointgroups[i].waypoints[j]);
#endif
                }
            }
        }

        if (g_chraiCurrentSetup.intro)
        {
            //g_chraiCurrentSetup.intro = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.intro);
#ifdef PRINTDEBUG
            printf("\nintro %X: \n", g_chraiCurrentSetup.intro);
#endif
        }

        if (g_chraiCurrentSetup.propDefs)
        {
           // g_chraiCurrentSetup.propDefs = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.propDefs);
#ifdef PRINTDEBUG
            printf("\npropDefs %X: \n", g_chraiCurrentSetup.propDefs);
#endif
        }

        if (g_chraiCurrentSetup.patrolpaths)
        {
            for (i = 0; g_chraiCurrentSetup.patrolpaths[i].waypoints; i++)
            {
                g_chraiCurrentSetup.patrolpaths[i].waypoints = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.patrolpaths[i].waypoints);

#ifdef PRINTDEBUG
                printf("path %d: wp %X, ID%d, isLoop %d, len %d\n", i, g_chraiCurrentSetup.patrolpaths[i].waypoints, g_chraiCurrentSetup.patrolpaths[i].ID, g_chraiCurrentSetup.patrolpaths[i].isLoop, g_chraiCurrentSetup.patrolpaths[i].len);
#endif
                for (j = 0; g_chraiCurrentSetup.patrolpaths[i].waypoints[j] > -1; j++)
                {
                    g_chraiCurrentSetup.patrolpaths[i].waypoints[j] = ntohl(g_chraiCurrentSetup.patrolpaths[i].waypoints[j]);
#ifdef PRINTDEBUG
                    printf("wp %d: %d\n", j, g_chraiCurrentSetup.patrolpaths[i].waypoints[j]);
#endif
                }
                g_chraiCurrentSetup.patrolpaths[i].len = j;
            }
        }

        if (g_chraiCurrentSetup.ailists)
        {
            for (i = 0; g_chraiCurrentSetup.ailists[i].ailist; i++)
            {
                g_chraiCurrentSetup.ailists[i].ailist = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.ailists[i].ailist);
                btol(g_chraiCurrentSetup.ailists[i].ID);
#ifdef PRINTDEBUG
                printf("\nAI %d: Lst %X, ID%d\n", i, g_chraiCurrentSetup.ailists[i].ailist, g_chraiCurrentSetup.ailists[i].ID);
#endif
            }
        }

        if (g_chraiCurrentSetup.pads)
        {
            for (i = 0; g_chraiCurrentSetup.pads[i].plink; i++)
            {

                for (j = 0; j < 3; j++)
                {
                    btol(g_chraiCurrentSetup.pads[i].pos.AsArray[j]);
                    btol(g_chraiCurrentSetup.pads[i].up.AsArray[j]);
                    btol(g_chraiCurrentSetup.pads[i].look.AsArray[j]);
                }

                g_chraiCurrentSetup.pads[i].plink = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.pads[i].plink);

                if (g_chraiCurrentSetup.pads[i].plink == 0)
                {
                    printf("pad number %d has no stan! (%s)\n", i, g_chraiCurrentSetup.pads[i].plink);
                }

            }
        }
        if (g_chraiCurrentSetup.boundpads)
        {
            for (i = 0; g_chraiCurrentSetup.boundpads[i].plink; i++)
            {

                for (j = 0; j < 6; j++)
                {
                    if (j < 3)
                    {
                        btol(g_chraiCurrentSetup.boundpads[i].pos.AsArray[j]);
                        btol(g_chraiCurrentSetup.boundpads[i].up.AsArray[j]);
                        btol(g_chraiCurrentSetup.boundpads[i].look.AsArray[j]);
                    }
                    btol(g_chraiCurrentSetup.boundpads[i].bbox.AsArray[j]);
                }
                g_chraiCurrentSetup.boundpads[i].plink = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.boundpads[i].plink);

                if (g_chraiCurrentSetup.boundpads[i].plink == 0)
                {
                    printf("vol number %d has no stan! (%s)\n", i, g_chraiCurrentSetup.boundpads[i].plink);
                }
            }
        }

        if (g_chraiCurrentSetup.padnames)
        {
            for (i = 0; g_chraiCurrentSetup.padnames[i]; i++)
            {
                g_chraiCurrentSetup.padnames[i] = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.padnames[i]);
#ifdef PRINTDEBUG
                printf("\nNAVPoint %d: %s\n", i, g_chraiCurrentSetup.padnames[i]);
#endif
            }
        }

        if (g_chraiCurrentSetup.boundpadnames)
        {
            for (i = 0; g_chraiCurrentSetup.boundpadnames[i]; i++)
            {
                g_chraiCurrentSetup.boundpadnames[i] = g_ptrStageSetupFile + ntohl(g_chraiCurrentSetup.boundpadnames[i]);
#ifdef PRINTDEBUG
                printf("\nNAVMesh %d: %s\n", i, g_chraiCurrentSetup.boundpadnames[i]);
#endif
            }
        }

#pragma endregion // foreach item in setupheader

        printf("/*\n* This file was automatically generated from %s\n*\n* $Date: %s*/\n\n#include <bondtypes.h>\n#include <bondaicommands.h>\n\n// forward declarations\nwaypoint       pathwaypoints[];\nwaygroup       pathsets[];\ns32            intro[];\ns32            propDefs[];\nPathRecord     patrolpaths[];\nAIListRecord   ailists[];\nPadRecord      pads[];\nBoundPadRecord vols[];\nchar          *NAVPADs[];\nchar          *NAVnames[];\n\nstagesetup %s = {\n    &pathwaypoints,\n    &pathsets,\n    &intro,\n    &propDefs,\n    &patrolpaths,\n    &ailists,\n    &pads,\n    &vols,\n    &NAVPADs,\n    &NAVnames\n};\n\n", fname, ctime(&current_time), fname);

        //retain file-order
        for (lastAddr = g_ptrStageSetupFile; lastAddr < g_ptrStageSetupFile + fsize; lastAddr += 4)
        {
            if (g_chraiCurrentSetup.pathwaypoints && lastAddr == &g_chraiCurrentSetup.pathwaypoints[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }
            if (g_chraiCurrentSetup.waypointgroups && lastAddr == &g_chraiCurrentSetup.waypointgroups[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }
            if (g_chraiCurrentSetup.intro && lastAddr == &g_chraiCurrentSetup.intro[0])
            {
                printf("char intro[] = {\n");
                
                printf("   };\n //nothing to see here yet");
            }
            if (g_chraiCurrentSetup.propDefs && lastAddr == &g_chraiCurrentSetup.propDefs[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }
            if (g_chraiCurrentSetup.patrolpaths && lastAddr == &g_chraiCurrentSetup.patrolpaths[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }

            if (g_chraiCurrentSetup.ailists)
            {
                for (i = 0; g_chraiCurrentSetup.ailists[i].ailist; i++)
                {
                    if (lastAddr == g_chraiCurrentSetup.ailists[i].ailist)
                    {
                        if (isChrAIListID(g_chraiCurrentSetup.ailists[i].ID))
                        {
                                printf("u8 chrAI_%hd[] = {\n    #define THIS chrai_%hd\n\n", getChrAIListID(g_chraiCurrentSetup.ailists[i].ID), getChrAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                        else
                        {
                                printf("u8 bgAi_%hd[] = {\n    #define THIS bgai_%hd\n\n", getBGAIListID(g_chraiCurrentSetup.ailists[i].ID), getBGAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                        hasName = 0;
                        ai(g_chraiCurrentSetup.ailists[i].ailist, g_chraiCurrentSetup.ailists[i].ID);

                        // un-closed loops
                        if (top != -1) printf("\nUnused Labels Found!"), displayStack();
                        top = -1;

                        printf("    #undef THIS \n};%s%s\n\n", hasName ? " //Possible Name " : "", hasName ? hasName : "");
                    }
                }
            }

            if (g_chraiCurrentSetup.ailists && lastAddr == &g_chraiCurrentSetup.ailists[0])
            {
                printf("AIListRecord ailists[] = {\n");
                for (i = 0; g_chraiCurrentSetup.ailists[i].ailist; i++)
                {
                    if (isChrAIListID(g_chraiCurrentSetup.ailists[i].ID))
                    {
                        printf("    { &chrAI_%hd, chrai_%hd }, \n", getChrAIListID(g_chraiCurrentSetup.ailists[i].ID), getChrAIListID(g_chraiCurrentSetup.ailists[i].ID));
                    }
                    else if (isBGAIListID(g_chraiCurrentSetup.ailists[i].ID))
                    {
                        printf("    { &bgAi_%hd, bgai_%hd },\n", getBGAIListID(g_chraiCurrentSetup.ailists[i].ID), getBGAIListID(g_chraiCurrentSetup.ailists[i].ID));
                    }
                    else
                    {
                        printf("    /*Invalid ID*/{ &Ai_%hd, %hd }, //index %d\n", g_chraiCurrentSetup.ailists[i].ID, g_chraiCurrentSetup.ailists[i].ID, i);
                    }
                }
                printf("    { NULL, 0 }\n};\n");
            }

            if (g_chraiCurrentSetup.pads && lastAddr == &g_chraiCurrentSetup.pads[0])
            {
                printf("PadRecord pads[] = {\n    //%30s%30s%40s%40s\tstan\n", "pos", "up", "look", "plink");
                for (i = 0; g_chraiCurrentSetup.pads[i].plink; i++)
                {
                    printf("    {{%# 10gf, %# 10gf, %# 10gf},\t{%# 10gf, %# 10gf, %# 10gf},\t{%# 10gf, %# 10gf, %# 10gf}, \t\"%#s\", NULL }, \n", g_chraiCurrentSetup.pads[i].pos.x, g_chraiCurrentSetup.pads[i].pos.y, g_chraiCurrentSetup.pads[i].pos.z, g_chraiCurrentSetup.pads[i].up.x, g_chraiCurrentSetup.pads[i].up.y, g_chraiCurrentSetup.pads[i].up.z, g_chraiCurrentSetup.pads[i].look.x, g_chraiCurrentSetup.pads[i].look.y, g_chraiCurrentSetup.pads[i].look.z, g_chraiCurrentSetup.pads[i].plink);
                }
                printf("    {  0 }\n};\n");
            }
            if (g_chraiCurrentSetup.boundpads && lastAddr == &g_chraiCurrentSetup.boundpads[0])
            {
                printf("BoundPadRecord boundpads[] = {\n    //%30s%30s%40s%40s\tstan\tbbox\n", "pos", "up", "look", "plink");
                for (i = 0; g_chraiCurrentSetup.boundpads[i].plink; i++)
                {
                    printf("    {{%# 10gf, %# 10gf, %# 10gf},\t{%# 10gf, %# 10gf, %# 10gf},\t{%# 10gf, %# 10gf, %# 10gf}, \t\"%#s\", NULL, {%# 10gf, %# 10gf, %# 10gf, %# 10gf, %# 10gf, %# 10gf} }, \n", g_chraiCurrentSetup.boundpads[i].pos.x, g_chraiCurrentSetup.boundpads[i].pos.y, g_chraiCurrentSetup.boundpads[i].pos.z, g_chraiCurrentSetup.boundpads[i].up.x, g_chraiCurrentSetup.boundpads[i].up.y, g_chraiCurrentSetup.boundpads[i].up.z, g_chraiCurrentSetup.boundpads[i].look.x, g_chraiCurrentSetup.boundpads[i].look.y, g_chraiCurrentSetup.boundpads[i].look.z, g_chraiCurrentSetup.boundpads[i].plink, g_chraiCurrentSetup.boundpads[i].bbox.AsArray[0], g_chraiCurrentSetup.boundpads[i].bbox.AsArray[1], g_chraiCurrentSetup.boundpads[i].bbox.AsArray[2], g_chraiCurrentSetup.boundpads[i].bbox.AsArray[3], g_chraiCurrentSetup.boundpads[i].bbox.AsArray[4], g_chraiCurrentSetup.boundpads[i].bbox.AsArray[5]);
                }
                printf("    {  0 }\n};\n");
            }
            if (g_chraiCurrentSetup.padnames && lastAddr == &g_chraiCurrentSetup.padnames[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }
            if (g_chraiCurrentSetup.boundpadnames && lastAddr == &g_chraiCurrentSetup.boundpadnames[0])
            {
                printf("char propDefs[] = {\n");

                printf("   };\n //nothing to see here yet");
            }

        }


        printf("#pragma region Enums \n //Move the following Enums to the top of file\n");

        if (g_chraiCurrentSetup.ailists)
        {
            printf("    enum chrAilist\n    {\n");
            for (i = 0; g_chraiCurrentSetup.ailists[i].ailist; i++)
            {
                if (g_chraiCurrentSetup.ailists[i].ID)
                {
                    if (isChrAIListID(g_chraiCurrentSetup.ailists[i].ID))
                    {
                        if (getChrAIListID(g_chraiCurrentSetup.ailists[i].ID))
                        {
                                printf("        chrai_%hd,\n", getChrAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                        else
                        {
                                printf("        chrai_%hd = setChrAIListID(%hd),\n", getChrAIListID(g_chraiCurrentSetup.ailists[i].ID), getChrAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                    }
                }
            }
            printf("    };\n");
        }
        if (g_chraiCurrentSetup.ailists)
        {
            printf("    enum bgAilist\n    {\n");
            for (i = 0; g_chraiCurrentSetup.ailists[i].ailist; i++)
            {
                if (g_chraiCurrentSetup.ailists[i].ID)
                {
                    if (isBGAIListID(g_chraiCurrentSetup.ailists[i].ID))
                    {
                        if (getBGAIListID(g_chraiCurrentSetup.ailists[i].ID))
                        {
                                printf("        bgai_%hd,\n", getBGAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                        else
                        {
                                printf("        bgai_%hd = setBGAIListID(%hd),\n", getBGAIListID(g_chraiCurrentSetup.ailists[i].ID), getBGAIListID(g_chraiCurrentSetup.ailists[i].ID));
                        }
                    }
                }
            }
            printf("    };\n");
        }

        SortEnums(labels);
        SortEnums(keys);
        SortEnums(tags);
        SortEnums(chrs);
        SortEnums(pads);

        printenum(labels, "lbl");
        printenum(tags, "tag");
        printenum(keys, "key");
        printenum(chrs, "chr");
        printenum(pads, "pad");
        i = 0;

        if (SubIDs[i].id)
        {
            printf("    #define SETUPSUBROUTINES(ID) ");
            while (SubIDs[i].id != 0)
            {
                if (isBGAIListID(SubIDs[i].id))
                {
                    printf("        (ID == bgai_%hd)", getBGAIListID(SubIDs[i].id));
                }
                else
                {
                    printf("        (ID == chrai_%hd)", getChrAIListID(SubIDs[i].id));
                }
                i++;
                if (SubIDs[i].id) printf(" | \\\n");
            }
            printf("\n");
        }
        printf("#pragma endregion\n");
    }

    free(g_ptrStageSetupFile);

    return 0;
}
