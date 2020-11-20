#ifndef _BONDCONSTANTS_H_
#define _BONDCONSTANTS_H_
#include "ultra64.h"

#define GAME_TICKRATE 60
#define SECS_TO_TIMER60(SECS) (SECS * GAME_TICKRATE)
#define MINS_TO_TIMER60(MINS) (SECS_TO_TIMER60(MINS * GAME_TICKRATE))

/* special chr num IDs */
#define CHR_BOND_CINEMA -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE -7
#define CHR_SEE_SHOT -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE -5 /* stored as chr->chrseedie */
#define CHR_PRESET -4 /* stored as chr->chrpreset1 */
#define CHR_SELF -3

/* private chr ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE -2 /* objective ai list chr ID */
#define CHR_FREE -1 /* chr IDs when free'd (killed or removed from level) */
#define CHR_SPAWN_NUM_START 5000 /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START 10000 /* default chr num for cloed guards with ai command C1 */

#define PAD_PRESET 9000 /* stored as chr->padpreset1 */

#define OBJECTIVES_MAX 10

typedef u16 PAD;
typedef u16 PADEXTRA;

#define PADEXTRA_START 10000
#define PADEX(PAD) (PAD + PADEXTRA_START) /* used for setups */

typedef enum RGBA_ENUM {
    RED = 0,
    GREEN,
    BLUE,
    ALPHA
} RGBA_ENUM;

typedef enum MISSION_BRIEFING {
    BRIEF_OVERVIEW = 0,
    BRIEF_M,
    BRIEF_Q,
    BRIEF_MONEYPENNY
} MISSION_BRIEFING;

typedef enum DIFFICULTY {
    DIFFICULTY_AGENT = 0,
    DIFFICULTY_SECRET,
    DIFFICULTY_00,
    DIFFICULTY_007,
    DIFFICULTY_MULTI = 0xFFFFFFFF
} DIFFICULTY;

typedef enum LEVELID {
    LEVELID_BUNKER1 = 0x9,
    LEVELID_SILO = 0x14,
    LEVELID_STATUE = 0x16,
    LEVELID_CONTROL = 0x17,
    LEVELID_ARCHIVES = 0x18,
    LEVELID_TRAIN = 0x19,
    LEVELID_FRIGATE = 0x1A,
    LEVELID_BUNKER2 = 0x1B,
    LEVELID_AZTEC = 0x1C,
    LEVELID_STREETS = 0x1D,
    LEVELID_DEPOT = 0x1E,
    LEVELID_COMPLEX = 0x1F,
    LEVELID_EGYPT = 0x20,
    LEVELID_DAM = 0x21,
    LEVELID_FACILITY = 0x22,
    LEVELID_RUNWAY = 0x23,
    LEVELID_SURFACE = 0x24,
    LEVELID_JUNGLE = 0x25,
    LEVELID_TEMPLE = 0x26,
    LEVELID_CAVERNS = 0x27,
    LEVELID_CITADEL = 0x28,
    LEVELID_CRADLE = 0x29,
    LEVELID_SHO = 0x2A,
    LEVELID_SURFACE2 = 0x2B,
    LEVELID_ELD = 0x2C,
    LEVELID_BASEMENT = 0x2D,
    LEVELID_STACK = 0x2E,
    LEVELID_LUE = 0x2F,
    LEVELID_LIBRARY = 0x30,
    LEVELID_RIT = 0x31,
    LEVELID_CAVES = 0x32,
    LEVELID_EAR = 0x33,
    LEVELID_LEE = 0x34,
    LEVELID_LIP = 0x35,
    LEVELID_CUBA = 0x36,
    LEVELID_WAX = 0x37,
    LEVELID_PAM = 0x38,
    LEVELID_MAX = 0x39,
    LEVELID_TITLE = 0x5A,
    LEVELID_NONE = 0xFFFFFFFF
} LEVELID;

typedef enum LEVEL_SOLO_SEQUENCE
{
    SP_LEVEL_DAM = 0x1,
    SP_LEVEL_FACILITY,
    SP_LEVEL_RUNWAY,
    SP_LEVEL_SURFACE1,
    SP_LEVEL_BUNKER1,
    SP_LEVEL_SILO,
    SP_LEVEL_FRIGATE,
    SP_LEVEL_SURFACE2,
    SP_LEVEL_BUNKER2,
    SP_LEVEL_STATUE,
    SP_LEVEL_ARCHIVES,
    SP_LEVEL_STREETS,
    SP_LEVEL_DEPOT,
    SP_LEVEL_TRAIN,
    SP_LEVEL_JUNGLE,
    SP_LEVEL_CONTROL,
    SP_LEVEL_CAVERNS,
    SP_LEVEL_CRADLE,
    SP_LEVEL_AZTEC,
    SP_LEVEL_EGYPT
} LEVEL_SOLO_SEQUENCE;

typedef enum LEVEL_INDEX
{
    LEVEL_INDEX_SEVBUNKER = 0x0,
    LEVEL_INDEX_SILO = 0x1,
    LEVEL_INDEX_STATUE = 0x2,
    LEVEL_INDEX_CONTROL = 0x3,
    LEVEL_INDEX_ARCH = 0x4,
    LEVEL_INDEX_TRA = 0x5,
    LEVEL_INDEX_DEST = 0x6,
    LEVEL_INDEX_SEVB = 0x7,
    LEVEL_INDEX_AZT = 0x8,
    LEVEL_INDEX_PETE = 0x9,
    LEVEL_INDEX_DEPO = 0xA,
    LEVEL_INDEX_REF = 0xB,
    LEVEL_INDEX_CRYP = 0xC,
    LEVEL_INDEX_DAM = 0xD,
    LEVEL_INDEX_ARK = 0xE,
    LEVEL_INDEX_RUN = 0xF,
    LEVEL_INDEX_SEVX = 0x10,
    LEVEL_INDEX_JUN = 0x11,
    LEVEL_INDEX_DISH = 0x12,
    LEVEL_INDEX_CAVE = 0x13,
    LEVEL_INDEX_CAT = 0x14,
    LEVEL_INDEX_CRAD = 0x15,
    LEVEL_INDEX_SHO = 0x16,
    LEVEL_INDEX_SEVXB = 0x17,
    LEVEL_INDEX_ELD = 0x18,
    LEVEL_INDEX_IMP = 0x19,
    LEVEL_INDEX_ASH = 0x1A,
    LEVEL_INDEX_LUE = 0x1B,
    LEVEL_INDEX_AME = 0x1C,
    LEVEL_INDEX_RIT = 0x1D,
    LEVEL_INDEX_OAT = 0x1E,
    LEVEL_INDEX_EAR = 0x1F,
    LEVEL_INDEX_LEE = 0x20,
    LEVEL_INDEX_LIP = 0x21,
    LEVEL_INDEX_LEN = 0x22,
    LEVEL_INDEX_WAX = 0x23,
    LEVEL_INDEX_PAM = 0x24,
    LEVEL_INDEX_X = 0x25
} LEVEL_INDEX;

/* language file to slot allocation */
#define TEXT(TEXTBANK, TEXTSLOT) ((TEXTBANK * 0x0400U) + TEXTSLOT)

typedef enum TEXTBANK_LEVEL_INDEX
{
    LNULL = 0,   /* Null (unused) */
    LAME,        /* Library (multi) */
    LARCH,       /* Archives */
    LARK,        /* Facility */
    LASH,        /* Stack (multi) */
    LAZT,        /* Aztec */
    LCAT,        /* Citadel (multi) */
    LCAVE,       /* Caverns */
    LAREC,       /* Control */
    LCRAD,       /* Cradle */
    LCRYP,       /* Egypt */
    LDAM,        /* Dam */
    LDEPO,       /* Depot */
    LDEST,       /* Frigate */
    LDISH,       /* Temple (multi) */
    LEAR,        /* Ear (unused) */
    LELD,        /* Eld (unused) */
    LIMP,        /* Basement (multi) */
    LJUN,        /* Jungle */
    LLEE,        /* Lee (unused) */
    LLEN,        /* Cuba */
    LLIP,        /* Lip (unused) */
    LLUE,        /* Lue (unused) */
    LOAT,        /* Cave (multi) */
    LPAM,        /* Pam (unused) */
    LPETE,       /* Streets */
    LREF,        /* Complex (multi) */
    LRIT,        /* Rit (unused) */
    LRUN,        /* Runway */
    LSEVB,       /* Bunker 2 */
    LSEV,        /* Bunker 1 */
    LSEVX,       /* Surface 1 */
    LSEVXB,      /* Surface 2 */
    LSHO,        /* Sho (unused) */
    LSILO,       /* Silo */
    LSTAT,       /* Statue */
    LTRA,        /* Train */
    LWAX,        /* Wax (unused) */
    LGUN,        /* Guns */
    LTITLE,      /* Stage and menu titles */
    LMPMENU,     /* Multi menus */
    LPROPOBJ,    /* In-game pickups */
    LMPWEAPONS,  /* Multi weapon select */
    LOPTIONS,    /* Solo in-game menus */
    LMISC        /* Cheat options */
} TEXTBANK_LEVEL_INDEX;

typedef enum MP_STAGE_SELECTED {
    MP_STAGE_RANDOM = 0x0,
    MP_STAGE_TEMPLE = 0x1,
    MP_STAGE_COMPLEX = 0x2,
    MP_STAGE_CAVES = 0x3,
    MP_STAGE_LIBRARY = 0x4,
    MP_STAGE_BASEMENT = 0x5,
    MP_STAGE_STACK = 0x6,
    MP_STAGE_FACILITY = 0x7,
    MP_STAGE_BUNKER = 0x8,
    MP_STAGE_ARCHIVES = 0x9,
    MP_STAGE_CAVERNS = 0xA,
    MP_STAGE_EGYPT = 0xB
} MP_STAGE_SELECTED;

typedef enum GENDER {FEMALE=0, MALE } GENDER;

typedef enum BODIES {
    BODY_Jungle_Commando = 0x0,
    BODY_St_Petersburg_Guard = 0x1,
    BODY_Russian_Soldier = 0x2,
    BODY_Russian_Infantry = 0x3,
    BODY_Janus_Special_Forces = 0x4,
    BODY_Tuxedo = 0x5,
    BODY_Boris = 0x6,
    BODY_Ourumov = 0x7,
    BODY_Trevelyan_Janus = 0x8,
    BODY_Trevelyan_006 = 0x9,
    BODY_Valentin_ = 0xA,
    BODY_Xenia = 0xB,
    BODY_Baron_Samedi = 0xC,
    BODY_Jaws = 0xD,
    BODY_Mayday = 0xE,
    BODY_Oddjob = 0xF,
    BODY_Natalya_Skirt = 0x10,
    BODY_Janus_Marine = 0x11,
    BODY_Russian_Commandant = 0x12,
    BODY_Siberian_Guard_1_Mishkin = 0x13,
    BODY_Naval_Officer = 0x14,
    BODY_Siberian_Special_Forces = 0x15,
    BODY_Special_Operations_Uniform = 0x16,
    BODY_Formal_Wear = 0x17,
    BODY_Jungle_Fatigues = 0x18,
    BODY_Parka = 0x19,
    BODY_Unused_Female = 0x1A,
    BODY_Rosika = 0x1B,
    BODY_Scientist_2_Female = 0x1C,
    BODY_Civilian_1_Female = 0x1D,
    BODY_Unused_Male_1 = 0x1E,
    BODY_Unused_Male_2 = 0x1F,
    BODY_Civilian_4 = 0x20,
    BODY_Civilian_2 = 0x21,
    BODY_Civilian_3 = 0x22,
    BODY_Scientist_1_Male = 0x23,
    BODY_Helicopter_Pilot = 0x24,
    BODY_Siberian_Guard_2 = 0x25,
    BODY_Arctic_Commando = 0x26,
    BODY_Moonraker_Elite_1_Male = 0x27,
    BODY_Moonraker_Elite_2_Female = 0x28,
    BODY_Left_Suit_Hand_Floating_Arm = 0x29,
    BODY_Male_Karl = 0x2A,
    BODY_Male_Alan = 0x2B,
    BODY_Male_Pete = 0x2C,
    BODY_Male_Martin = 0x2D,
    BODY_Male_Mark = 0x2E,
    BODY_Male_Duncan = 0x2F,
    BODY_Male_Shaun = 0x30,
    BODY_Male_Dwayne = 0x31,
    BODY_Male_B = 0x32,
    BODY_Male_Dave_Dr_Doak = 0x33,
    BODY_Male_Grant = 0x34,
    BODY_Male_Des = 0x35,
    BODY_Male_Chris = 0x36,
    BODY_Male_Lee = 0x37,
    BODY_Male_Neil = 0x38,
    BODY_Male_Jim = 0x39,
    BODY_Male_Robin = 0x3A,
    BODY_Male_Steve_H = 0x3B,
    BODY_Male_Terrorist = 0x3C,
    BODY_Male_Biker = 0x3D,
    BODY_Male_Graeme = 0x3E,
    BODY_Male_Steve_Ellis = 0x3F,
    BODY_Male_Joel = 0x40,
    BODY_Male_Scott = 0x41,
    BODY_Male_Joe_Altered = 0x42,
    BODY_Male_Ken = 0x43,
    BODY_Male_Joe = 0x44,
    BODY_Male_Mishkin = 0x45,
    BODY_Female_Sally = 0x46,
    BODY_Female_Marion_Rosika = 0x47,
    BODY_Female_Mandy = 0x48,
    BODY_Female_Vivien = 0x49,
    BODY_Male_Pierce_Bond_1 = 0x4A,
    BODY_Male_Pierce_Bond_2 = 0x4B,
    BODY_Male_Pierce_Bond_3 = 0x4C,
    BODY_Male_Pierce_Bond_Parka = 0x4D,
    BODY_Male_Pierce_Bond_Tuxedo = 0x4E,
    BODY_Natalya_Jungle_Fatigues = 0x4F
} BODIES;

typedef enum HEADS {
    HEAD_Male_Karl = 0x2A,
    HEAD_Male_Alan = 0x2B,
    HEAD_Male_Pete = 0x2C,
    HEAD_Male_Martin = 0x2D,
    HEAD_Male_Mark = 0x2E,
    HEAD_Male_Duncan = 0x2F,
    HEAD_Male_Shaun = 0x30,
    HEAD_Male_Dwayne = 0x31,
    HEAD_Male_B = 0x32,
    HEAD_Male_Dave_Dr_Doak = 0x33,
    HEAD_Male_Grant = 0x34,
    HEAD_Male_Des = 0x35,
    HEAD_Male_Chris = 0x36,
    HEAD_Male_Lee = 0x37,
    HEAD_Male_Neil = 0x38,
    HEAD_Male_Jim = 0x39,
    HEAD_Male_Robin = 0x3A,
    HEAD_Male_Steve_H = 0x3B,
    HEAD_Male_Terrorist = 0x3C,
    HEAD_Male_Biker = 0x3D,
    HEAD_Male_Graeme = 0x3E,
    HEAD_Male_Steve_Ellis = 0x3F,
    HEAD_Male_Joel = 0x40,
    HEAD_Male_Scott = 0x41,
    HEAD_Male_Joe_Altered = 0x42,
    HEAD_Male_Ken = 0x43,
    HEAD_Male_Joe = 0x44,
    HEAD_Male_Mishkin = 0x45,
    HEAD_Female_Sally = 0x46,
    HEAD_Female_Marion_Rosika = 0x47,
    HEAD_Female_Mandy = 0x48,
    HEAD_Female_Vivien = 0x49,
    HEAD_Male_Pierce_Bond_1 = 0x4A,
    HEAD_Male_Pierce_Bond_2 = 0x4B,
    HEAD_Male_Pierce_Bond_3 = 0x4C,
    HEAD_Male_Pierce_Bond_Parka = 0x4D,
    HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT = 0x4E,
    HEAD_Natalya_Jungle_Fatigues = 0x4F
} HEADS;

typedef enum mission_setup_type {
    MISSION_PART = 0,
    MISSION_HEADER
} mission_setup_type;

typedef enum MUSIC_TRACKS {
    M_ARCHIVES = 11,
    M_ARCHIVESX = 37,
    M_AZTEC = 25,
    M_AZTECX = 46,
    M_BUNKER1 = 15,
    M_BUNKER1X = 41,
    M_BUNKER2 = 16,
    M_BUNKER2X = 42,
    M_CITADEL = 6,
    M_CONTROL = 8,
    M_CONTROLX = 33,
    M_CRADLE = 19,
    M_CRADLEX = 48,
    M_CUBA = 49,
    M_DAM = 9,
    M_DAMX = 35,
    M_DEATHSOLO = 27,
    M_DEPOT = 4,
    M_DEPOTX = 32,
    M_EGYPTIAN = 22,
    M_EGYPTIANX = 39,
    M_EGYPTX = 47,
    M_ELEVATOR_CONTROL = 18,
    M_ELEVATOR_WC = 21,
    M_END_SOMETHING = 62,
    M_FACILITY = 7,
    M_FACILITYX = 31,
    M_FOLDERS = 23,
    M_FRIGATE = 10,
    M_FRIGATEX = 36,
    M_GUITARGLISS = 54,
    M_INTRO = 2,
    M_INTROSWOOSH = 44,
    M_JUNGLE = 55,
    M_JUNGLEX = 43,
    M_MPDEATH = 58,
    M_MPTHEME = 5,
    M_MPTHEME2 = 13,
    M_MPTHEME3 = 52,
    M_NONE = 0,
    M_RUNWAY = 50,
    M_RUNWAYPLANE = 51,
    M_RUNWAYX = 56,
    M_SHORT_SOLO_DEATH = 1,
    M_SILO = 12,
    M_SILOX = 38,
    M_STATUE = 17,
    M_STATUEPART = 61,
    M_STATUEX = 45,
    M_STREETS = 14,
    M_STREETSX = 40,
    M_SURFACE1 = 57,
    M_SURFACE2 = 28,
    M_SURFACE2END = 60,
    M_SURFACE2X = 59,
    M_TRAIN = 3,
    M_TRAINX = 29,
    M_UNK = 20,
    M_UNK2 = 30,
    M_WATCH = 24,
    M_WATERCAVERNS = 26,
    M_WATERCAVERNSX = 34,
    M_WIND = 53
} MUSIC_TRACKS;

typedef enum GAMEMODE {
    GAMEMODE_SOLO = 0x0,
    GAMEMODE_MULTI,
    GAMEMODE_CHEATS,
    GAMEMODE_INTRO = 0xFFFFFFFF
} GAMEMODE;

typedef enum MPSCENARIOS {
    SCENARIO_NORMAL=0,
    SCENARIO_YOLT,
    SCENARIO_TLD,
    SCENARIO_MWTGG,
    SCENARIO_LTK,
    SCENARIO_2v2,
    SCENARIO_3v1,
    SCENARIO_2v1
} MPSCENARIOS;

typedef enum WATCH_BRIEFING_PAGE {
    BRIEFING_TITLE = 0x0,
    BRIEFING_OVERVIEW,
    BRIEFING_M,
    BRIEFING_Q,
    BRIEFING_MONEYPENNY,
    BRIEFING_INVALID = -1
} WATCH_BRIEFING_PAGE;

typedef enum MENU {
    MENU_LEGAL_SCREEN = 0x0,
    MENU_NINTENDO_LOGO,
    MENU_RAREWARE_LOGO,
    MENU_EYE_INTRO,
    MENU_GOLDENEYE_LOGO,
    MENU_FILE_SELECT,
    MENU_MODE_SELECT,
    MENU_MISSION_SELECT,
    MENU_DIFFICULTY,
    MENU_007_OPTIONS,
    MENU_BRIEFING,
    MENU_RUN_STAGE,
    MENU_MISSION_FAILED,
    MENU_MISSION_COMPLETE,
    MENU_MP_OPTIONS,
    MENU_MP_CHAR_SELECT,
    MENU_MP_HANDICAP,
    MENU_MP_CONTROL_STYLE,
    MENU_MP_STAGE_SELECT,
    MENU_MP_SCENARIO_SELECT,
    MENU_MP_TEAMS,
    MENU_CHEAT,
    MENU_NO_CONTROLLERS,
    MENU_SWITCH_SCREENS,
    MENU_DISPLAY_CAST,
    MENU_SPECTRUM_EMU,
    MENU_INVALID = -1
} MENU;

typedef enum CONTROLLER_CONFIG
{
    CONTROLLER_CONFIG_HONEY = 0x0,
    CONTROLLER_CONFIG_SOLITARE,
    CONTROLLER_CONFIG_KISSY,
    CONTROLLER_CONFIG_GOODNIGHT,
    CONTROLLER_CONFIG_PLENTY,
    CONTROLLER_CONFIG_GALORE,
    CONTROLLER_CONFIG_DOMINO,
    CONTROLLER_CONFIG_GOODHEAD,
    CONTROLLER_CONFIG_CINEMA
} CONTROLLER_CONFIG;

typedef enum CUFF_TYPES
{
    CUFF_BLUE = 0x0,
    CUFF_TUX,
    CUFF_JUNGLE,
    CUFF_BOILER,
    CUFF_SNOW,
    CUFF_WHITE,
    CUFF_TUX6,
    CUFF_TUX7,
    CUFF_TUX8
} CUFF_TYPES;

typedef enum INV_ITEM_TYPE
{
    INV_ITEM_WEAPON = 1,
    INV_ITEM_PROP,
    INV_ITEM_DUAL
} INV_ITEM_TYPE;

typedef enum ITEM_IDS
{
    ITEM_UNARMED = 0x0,
    ITEM_FIST = 0x1,
    ITEM_KNIFE = 0x2,
    ITEM_THROWKNIFE = 0x3,
    ITEM_WPPK = 0x4,
    ITEM_WPPKSIL = 0x5,
    ITEM_TT33 = 0x6,
    ITEM_SKORPION = 0x7,
    ITEM_AK47 = 0x8,
    ITEM_UZI = 0x9,
    ITEM_MP5K = 0xA,
    ITEM_MP5KSIL = 0xB,
    ITEM_SPECTRE = 0xC,
    ITEM_M16 = 0xD,
    ITEM_FNP90 = 0xE,
    ITEM_SHOTGUN = 0xF,
    ITEM_AUTOSHOT = 0x10,
    ITEM_SNIPERRIFLE = 0x11,
    ITEM_RUGER = 0x12,
    ITEM_GOLDENGUN = 0x13,
    ITEM_SILVERWPPK = 0x14,
    ITEM_GOLDWPPK = 0x15,
    ITEM_LASER = 0x16,
    ITEM_WATCHLASER = 0x17,
    ITEM_GRENADELAUNCH = 0x18,
    ITEM_ROCKETLAUNCH = 0x19,
    ITEM_GRENADE = 0x1A,
    ITEM_TIMEDMINE = 0x1B,
    ITEM_PROXIMITYMINE = 0x1C,
    ITEM_REMOTEMINE = 0x1D,
    ITEM_TRIGGER = 0x1E,
    ITEM_TASER = 0x1F,
    ITEM_TANKSHELLS = 0x20,
    ITEM_BOMBCASE = 0x21,
    ITEM_PLASTIQUE = 0x22,
    ITEM_FLAREPISTOL = 0x23,
    ITEM_PITONGUN = 0x24,
    ITEM_BUNGEE = 0x25,
    ITEM_DOORDECODER = 0x26,
    ITEM_BOMBDEFUSER = 0x27,
    ITEM_CAMERA = 0x28,
    ITEM_LOCKEXPLODER = 0x29,
    ITEM_DOOREXPLODER = 0x2A,
    ITEM_BRIEFCASE = 0x2B,
    ITEM_WEAPONCASE = 0x2C,
    ITEM_SAFECRACKERCASE = 0x2D,
    ITEM_KEYANALYSERCASE = 0x2E,
    ITEM_BUG = 0x2F,
    ITEM_MICROCAMERA = 0x30,
    ITEM_BUGDETECTOR = 0x31,
    ITEM_EXPLOSIVEFLOPPY = 0x32,
    ITEM_POLARIZEDGLASSES = 0x33,
    ITEM_DARKGLASSES = 0x34,
    ITEM_CREDITCARD = 0x35,
    ITEM_GASKEYRING = 0x36,
    ITEM_DATATHIEF = 0x37,
    ITEM_WATCHIDENTIFIER = 0x38,
    ITEM_WATCHCOMMUNICATOR = 0x39,
    ITEM_WATCHGEIGERCOUNTER = 0x3A,
    ITEM_WATCHMAGNETREPEL = 0x3B,
    ITEM_WATCHMAGNETATTRACT = 0x3C,
    ITEM_GOLDENEYEKEY = 0x3D,
    ITEM_BLACKBOX = 0x3E,
    ITEM_CIRCUITBOARD = 0x3F,
    ITEM_CLIPBOARD = 0x40,
    ITEM_STAFFLIST = 0x41,
    ITEM_DOSSIERRED = 0x42,
    ITEM_PLANS = 0x43,
    ITEM_SPYFILE = 0x44,
    ITEM_BLUEPRINTS = 0x45,
    ITEM_MAP = 0x46,
    ITEM_AUDIOTAPE = 0x47,
    ITEM_VIDEOTAPE = 0x48,
    ITEM_DATTAPE = 0x49,
    ITEM_SPOOLTAPE = 0x4A,
    ITEM_MICROFILM = 0x4B,
    ITEM_MICROCODE = 0x4C,
    ITEM_LECTRE = 0x4D,
    ITEM_MONEY = 0x4E,
    ITEM_GOLDBAR = 0x4F,
    ITEM_HEROIN = 0x50,
    ITEM_KEYCARD = 0x51,
    ITEM_KEYYALE = 0x52,
    ITEM_KEYBOLT = 0x53,
    ITEM_SUIT_LF_HAND = 0x54,
    ITEM_JOYPAD = 0x55,
    ITEM_56 = 0x56,
    ITEM_57 = 0x57,
    ITEM_TOKEN = 0x58
} ITEM_IDS;

typedef enum PROPS {
    PROP_alarm1                  = 0, /* Beta Alarm / Default Multi Weapon */
    PROP_alarm2                  = 1, /* Alarm */
    PROP_explosionbit            = 2, /* White Pyramid (Explosion Bit) */
    PROP_ammo_crate1             = 3, /* Ammo Crate (Brown w/ Edge Brace, 6x240 Black) */
    PROP_ammo_crate2             = 4, /* Ammo Crate (Brown w/ Center Brace, 12x8 Black) */
    PROP_ammo_crate3             = 5, /* Ammo Crate (Green w/ Center Brace, 12x8 Brown) */
    PROP_ammo_crate4             = 6, /* Ammo Crate (Green w/ Edge Brace, 6x8 White) */
    PROP_ammo_crate5             = 7, /* Ammo Crate (Green w/ Double Brace, 24x60 Black) */
    PROP_bin1                    = 8, /* Rusted Trash Bin */
    PROP_blotter1                = 9, /* Desk Blotter */
    PROP_book1                  = 10, /* Red Book */
    PROP_bookshelf1             = 11, /* Bookshelf */
    PROP_bridge_console1a       = 12, /* Bridge Console w/ Monitor, Navigation + Keyboard 1A */
    PROP_bridge_console1b       = 13, /* Bridge Console w/ Navigation 1B */
    PROP_bridge_console2a       = 14, /* Bridge Console w/ Navigation, Monitor + Keyboard 2A */
    PROP_bridge_console2b       = 15, /* Bridge Console w/ Various Controls 2B */
    PROP_bridge_console3a       = 16, /* Bridge Console w/ Monitor, Navigation + Keyboard 3A */
    PROP_bridge_console3b       = 17, /* Bridge Console w/ Monitor, Keyboard + Navigation 3B */
    PROP_card_box1              = 18, /* Cardboard Box, Kapto|Enb */
    PROP_card_box2              = 19, /* Cardboard Box, Red Arrow, Bahko */
    PROP_card_box3              = 20, /* Cardboard Box, Scrawled Text, Bahah */
    PROP_card_box4_lg           = 21, /* Cardboard Box, Three Seams */
    PROP_card_box5_lg           = 22, /* Cardboard Box, Two Seams, Bahah */
    PROP_card_box6_lg           = 23, /* Cardboard Box, Bahko */
    PROP_cctv                   = 24, /* Surveillance Camera */
    PROP_console1               = 25, /* Double Screen Consoles w/ Keyboards */
    PROP_console2               = 26, /* Double Screen Consoles w/ Left Keyboard */
    PROP_console3               = 27, /* Double Screen Consoles w/ Right Keyboard */
    PROP_console_seva           = 28, /* Console w/ Keyboard */
    PROP_console_sevb           = 29, /* Console w/ Monitor + Keyboard */
    PROP_console_sevc           = 30, /* Console w/ Switches */
    PROP_console_sevd           = 31, /* Console w/ Five Gauges */
    PROP_console_sev2a          = 32, /* Console w/ Four Faders */
    PROP_console_sev2b          = 33, /* Console w/ Monitor, Keyboard + Switches */
    PROP_console_sev2c          = 34, /* Console w/ Three Gauges */
    PROP_console_sev2d          = 35, /* Console w/ Pressure Gauge */
    PROP_console_sev_GEa        = 36, /* Console w/ GoldenEye Key Slot */
    PROP_console_sev_GEb        = 37, /* Console w/ Faders + Pressure Gauge */
    PROP_desk1                  = 38, /* Desk w/ Kickplate */
    PROP_desk2                  = 39, /* Desk */
    PROP_desk_lamp2             = 40, /* Desk Lamp */
    PROP_disc_reader            = 41, /* External Hard Drive */
    PROP_disk_drive1            = 42, /* Floppy Disc Drive */
    PROP_filing_cabinet1        = 43, /* Filing Cabinet */
    PROP_jerry_can1             = 44, /* Jerrycan (Fuel Container) */
    PROP_keyboard1              = 45, /* Computer Keyboard */
    PROP_kit_units1             = 46, /* Kitchen Cabinets */
    PROP_letter_tray1           = 47, /* Letter Tray */
    PROP_mainframe1             = 48, /* Mainframe, Basic */
    PROP_mainframe2             = 49, /* Mainframe, Advanced */
    PROP_metal_chair1           = 50, /* Chair (Metal) */
    PROP_metal_crate1           = 51, /* Metal Crate, 6 Top Corner */
    PROP_metal_crate2           = 52, /* Metal Crate, 6 Bottom Corner */
    PROP_metal_crate3           = 53, /* Metal Crate, Toxic Materials */
    PROP_metal_crate4           = 54, /* Metal Crate, Double Stripe - Class D1 Hazard */
    PROP_missile_rack           = 55, /* Naval Harpoon Missile in Containment Rack */
    PROP_missile_rack2          = 56, /* Naval Harpoon Missiles in Containment Racks x4 */
    PROP_oil_drum1              = 57, /* Oil Drum, Single Stripe, Ribbed */
    PROP_oil_drum2              = 58, /* Oil Drum, Single Stripe, Ribbed - Class D1 Hazard */
    PROP_oil_drum3              = 59, /* Oil Drum, Single Stripe, Ribbed - Toxic Materials */
    PROP_oil_drum5              = 60, /* Oil Drum, Double Stripe - Toxic Materials */
    PROP_oil_drum6              = 61, /* Oil Drum - Toxic Materials */
    PROP_oil_drum7              = 62, /* Oil Drum, Double Dashes - Class D1 Hazard */
    PROP_padlock                = 63, /* Padlock */
    PROP_phone1                 = 64, /* Telephone */
    PROP_radio_unit1            = 65, /* Radio Tuner w/ 1 Knob + 2 Gauges */
    PROP_radio_unit2            = 66, /* Radio Tuner w/ 1 Knob + 5 Gauges */
    PROP_radio_unit3            = 67, /* Radio Tuner w/ 3 Knobs + 5 Gauges */
    PROP_radio_unit4            = 68, /* Radio Tuner w/ 3 Knobs + 2 Gauges */
    PROP_sat1_reflect           = 69, /* GoldenEye Satellite */
    PROP_satdish                = 70, /* Satellite Dish (Arkangelsk) */
    PROP_satbox                 = 71, /* Uplink Box */
    PROP_stool1                 = 72, /* Wooden Stool */
    PROP_swivel_chair1          = 73, /* Swivel Chair */
    PROP_torpedo_rack           = 74, /* Naval Torpedo Rack x3 */
    PROP_tv1                    = 75, /* Television Monitor */
    PROP_tv_holder              = 76, /* Hanging Monitor Rack */
    PROP_tvscreen               = 77, /* Wall Monitor Screen */
    PROP_tv4screen              = 78, /* Wall Monitor Screens, 4-in-1 */
    PROP_wood_lg_crate1         = 79, /* Wooden Crate w/ #4 Label, Bahah */
    PROP_wood_lg_crate2         = 80, /* Wooden Crate, Darker Shading, Kapto|Enb */
    PROP_wood_md_crate3         = 81, /* Wooden Crates x8, Bahko */
    PROP_wood_sm_crate4         = 82, /* Wooden Crate w/ #2 Label, Bahko */
    PROP_wood_sm_crate5         = 83, /* Wooden Crate w/ #4 Label, Darker Shading, Bahah */
    PROP_wood_sm_crate6         = 84, /* Wooden Crate w/ UP Arrow, Kapto|Enb */
    PROP_wooden_table1          = 85, /* Wooden Table */
    PROP_swipe_card2            = 86, /* Keycard */
    PROP_borg_crate             = 87, /* Blue and Gold Printed Circuit Cube (Borg Crate) */
    PROP_boxes4x4               = 88, /* Metal Crate Stack, 4x4 */
    PROP_boxes3x4               = 89, /* Metal Crate Stack, 3x4 */
    PROP_boxes2x4               = 90, /* Metal Crate Stack, 2x4 */
    PROP_sec_panel              = 91, /* Security Card Panel */
    PROP_ICBM_nose              = 92, /* Silo Missile (ICBM), Nose Cone Only */
    PROP_ICBM                   = 93, /* Silo Missile (ICBM) */
    PROP_tuning_console1        = 94, /* Dual Consoles on Castors */
    PROP_desk_arecibo1          = 95, /* Computer Work Desk */
    PROP_locker3                = 96, /* Lockers, Single Venting */
    PROP_locker4                = 97, /* Lockers, Double Venting */
    PROP_roofgun                = 98, /* Ceiling Mounted Drone Gun */
    PROP_dest_engine            = 99, /* Frigate Engine */
    PROP_dest_exocet           = 100, /* Naval MK 29 Missile Launcher (Exocet) */
    PROP_dest_gun              = 101, /* Naval 100 mm Gun Turret (TR 100) */
    PROP_dest_harpoon          = 102, /* Naval MK 141 Launch Canisters (Harpoon) */
    PROP_dest_seawolf          = 103, /* Naval MK 26 Dual Missile Launcher (Seawolf) */
    PROP_window                = 104, /* Window Glass */
    PROP_window_lib_lg1        = 105, /* Window Glass, Lattice Frame, 4x10 (single-sided) */
    PROP_window_lib_sm1        = 106, /* Window Glass, Lattice Frame, 4x3 (double-sided) */
    PROP_window_cor11          = 107, /* Window Glass, Lattice Frame, 4x4 (single-sided) */
    PROP_jungle3_tree          = 108, /* Jungle Large Tree */
    PROP_palm                  = 109, /* Jungle Palm Tree */
    PROP_palmtree              = 110, /* Jungle Palm Tree, Resprouting After Loss of Fronds */
    PROP_plant2b               = 111, /* Jungle Plant, Low Shrub */
    PROP_labbench              = 112, /* Laboratory Table w/ Sink Drains */
    PROP_gasbarrel             = 113, /* White Bin */
    PROP_gasbarrels            = 114, /* White Bins x4 */
    PROP_bodyarmour            = 115, /* Body Armor */
    PROP_bodyarmourvest        = 116, /* Body Armor (Vest) */
    PROP_gastank               = 117, /* Bottling Tank */
    PROP_glassware1            = 118, /* Glass Cup */
    PROP_hatchbolt             = 119, /* Metallic Securing Strip (Hatch Bolt) */
    PROP_brakeunit             = 120, /* Train Brake Controller */
    PROP_ak47mag               = 121, /* Gun Magazine (KF7 Soviet) */
    PROP_m16mag                = 122, /* Gun Magazine (AR33 Assault Rifle) */
    PROP_mp5kmag               = 123, /* Gun Magazine (D5K Deutsche) */
    PROP_skorpionmag           = 124, /* Gun Magazine (Klobb) */
    PROP_spectremag            = 125, /* Gun Magazine (Phantom) */
    PROP_uzimag                = 126, /* Gun Magazine (ZMG (9mm)) */
    PROP_silencer              = 127, /* Silencer */
    PROP_chrextinguisher       = 128, /* Fire Extinguisher */
    PROP_boxcartridges         = 129, /* Box of Shells (Shotgun Cartridges) */
    PROP_fnp90mag              = 130, /* Gun Magazine (RC-P90) */
    PROP_goldenshells          = 131, /* Box of Shells (Golden Gun Bullets) */
    PROP_magnumshells          = 132, /* Box of Shells (Magnum Rounds) */
    PROP_wppkmag               = 133, /* Gun Magazine (PP7) */
    PROP_tt33mag               = 134, /* Gun Magazine (DD44 Dostovei) */
    PROP_sev_door              = 135, /* Grey Containment Door w/ Caution Stripes and Window */
    PROP_sev_door3             = 136, /* Grey Electronic Door w/ LEFT Arrow */
    PROP_sev_door3_wind        = 137, /* BETA Electronic Door w/ LEFT Arrow and Fake Window */
    PROP_sev_door4_wind        = 138, /* Grey Electronic Door w/ LEFT Arrow and Window */
    PROP_sev_trislide          = 139, /* Glass Door w/ Stone Frame */
    PROP_sev_door_v1           = 140, /* Grey Electronic Door w/ UP Arrow */
    PROP_steel_door1           = 141, /* Silver Corrugated Door w/ Caution Stripes */
    PROP_steel_door2           = 142, /* Rusty Door w/ Handle */
    PROP_steel_door3           = 143, /* Double Cross Brace Door */
    PROP_silo_lift_door        = 144, /* Elevator Door */
    PROP_steel_door2b          = 145, /* Rusty Door w/o Handle */
    PROP_door_roller1          = 146, /* Blue Bay Door w/ Caution Stripes */
    PROP_door_roller2          = 147, /* Blue Bay Door w/ Venting and Caution Stripes */
    PROP_door_roller3          = 148, /* Blue Bay Door w/ Venting and Caution Stripes */
    PROP_door_roller4          = 149, /* Cargo Bay Door w/ UP Arrow and Transportation Stripes */
    PROP_door_st_arec1         = 150, /* Blue Corrugated Door w/ Transportation Stripes */
    PROP_door_st_arec2         = 151, /* Blue Reversed Corrugated Door w/ Transportation Stripes */
    PROP_door_dest1            = 152, /* Grey Frigate Door w/ Indents and Caution Stripes */
    PROP_door_dest2            = 153, /* Grey Frigate Door w/ Indents, Caution Stripes and KEEP CLEAR Label */
    PROP_gas_plant_sw_do1      = 154, /* Grey Swinging Door w/ Blue Stripe */
    PROP_gas_plant_sw2_do1     = 155, /* Grey Swinging Door, Darker */
    PROP_gas_plant_sw3_do1     = 156, /* Grey Swinging Door, Lighter */
    PROP_gas_plant_sw4_do1     = 157, /* Light Wooden Door (Looks Like Sand) */
    PROP_gas_plant_met1_do1    = 158, /* Brown Electronic Door */
    PROP_gas_plant_wc_cub1     = 159, /* Bathroom Stall Door */
    PROP_gasplant_clear_door   = 160, /* Laboratory Glass Door */
    PROP_train_door            = 161, /* Dark Wooden Door */
    PROP_train_door2           = 162, /* Dark Wooden Door w/ Window */
    PROP_train_door3           = 163, /* Dark Wooden Door w/ Window + Shutter */
    PROP_door_eyelid           = 164, /* Eyelid Door */
    PROP_door_iris             = 165, /* Iris Door */
    PROP_sevdoorwood           = 166, /* Cabin Door */
    PROP_sevdoorwind           = 167, /* Weathered Swinging Door w/ Window */
    PROP_sevdoornowind         = 168, /* Weathered Swinging Door */
    PROP_sevdoormetslide       = 169, /* Brown Corrugated Electronic Door */
    PROP_cryptdoor1a           = 170, /* Stone Door w/ Prints (Set A) */
    PROP_cryptdoor1b           = 171, /* Sand Door w/ Damage (Set A) */
    PROP_cryptdoor2a           = 172, /* Stone Door w/ Prints, Darker (Set B) */
    PROP_cryptdoor2b           = 173, /* Sand Door w/ Damage, Darker (Set B) */
    PROP_cryptdoor3            = 174, /* Egyptian Moving Wall */
    PROP_cryptdoor4            = 175, /* Brown Sand Door (Temple) */
    PROP_vertdoor              = 176, /* Blast Door (Control) */
    PROP_hatchdoor             = 177, /* Train Floor Hatch */
    PROP_damgatedoor           = 178, /* Security Gate (Dam) */
    PROP_damtundoor            = 179, /* Tunnel Flood Door (Dam) */
    PROP_damchaindoor          = 180, /* Mesh Gate */
    PROP_silotopdoor           = 181, /* Launch Tube Ceiling Shutter (Silo) */
    PROP_doorprison1           = 182, /* Cell Door */
    PROP_doorstatgate          = 183, /* Park Gate */
    PROP_chrkalash             = 184, /* KF7 Soviet */
    PROP_chrgrenadelaunch      = 185, /* Grenade Launcher */
    PROP_chrknife              = 186, /* Hunting Knife */
    PROP_chrlaser              = 187, /* Moonraker Laser */
    PROP_chrm16                = 188, /* AR33 Assault Rifle */
    PROP_chrmp5k               = 189, /* D5K Deutsche */
    PROP_chrruger              = 190, /* Cougar Magnum */
    PROP_chrwppk               = 191, /* PP7 Special Issue */
    PROP_chrshotgun            = 192, /* Shotgun */
    PROP_chrskorpion           = 193, /* Klobb */
    PROP_chrspectre            = 194, /* Phantom */
    PROP_chruzi                = 195, /* ZMG (9mm) */
    PROP_chrgrenade            = 196, /* Hand Grenade */
    PROP_chrfnp90              = 197, /* RC-P90 */
    PROP_chrbriefcase          = 198, /* Briefcase */
    PROP_chrremotemine         = 199, /* Remote Mine */
    PROP_chrproximitymine      = 200, /* Proximity Mine */
    PROP_chrtimedmine          = 201, /* Timed Mine */
    PROP_chrrocket             = 202, /* Rocket */
    PROP_chrgrenaderound       = 203, /* Grenade Round */
    PROP_chrwppksil            = 204, /* PP7 (Silenced) */
    PROP_chrtt33               = 205, /* DD44 Dostovei */
    PROP_chrmp5ksil            = 206, /* D5K (Silenced) */
    PROP_chrautoshot           = 207, /* Automatic Shotgun */
    PROP_chrgolden             = 208, /* Golden Gun */
    PROP_chrthrowknife         = 209, /* Throwing Knife */
    PROP_chrsniperrifle        = 210, /* Sniper Rifle */
    PROP_chrrocketlaunch       = 211, /* Rocket Launcher */
    PROP_hatfurry              = 212, /* Fur Hat, Blue */
    PROP_hatfurrybrown         = 213, /* Fur Hat, Brown */
    PROP_hatfurryblack         = 214, /* Fur Hat, Black */
    PROP_hattbird              = 215, /* Side Cap, Light Green */
    PROP_hattbirdbrown         = 216, /* Side Cap, Dark Green */
    PROP_hathelmet             = 217, /* Combat Helmet, Green */
    PROP_hathelmetgrey         = 218, /* Combat Helmet, Grey */
    PROP_hatmoon               = 219, /* Elite Headgear */
    PROP_hatberet              = 220, /* Special Forces Beret, Black */
    PROP_hatberetblue          = 221, /* Special Forces Beret, Navy */
    PROP_hatberetred           = 222, /* Special Forces Beret, Burgundy */
    PROP_hatpeaked             = 223, /* Officer's Peaked Visor Cap */
    PROP_chrwristdart          = 224, /* Pchrwristdart (BETA) */
    PROP_chrexplosivepen       = 225, /* Pchrexplosivepen (BETA) */
    PROP_chrbombcase           = 226, /* Bomb Case (Briefcase Laying Down) */
    PROP_chrflarepistol        = 227, /* Pchrflarepistol (BETA Pickup) */
    PROP_chrpitongun           = 228, /* Pchrpitongun (BETA Pickup) */
    PROP_chrfingergun          = 229, /* Pchrfingergun (BETA Pickup) */
    PROP_chrsilverwppk         = 230, /* Pchrsilverwppk (BETA Pickup) */
    PROP_chrgoldwppk           = 231, /* Pchrgoldwppk (BETA Pickup) */
    PROP_chrdynamite           = 232, /* Pchrdynamite (BETA Pickup) */
    PROP_chrbungee             = 233, /* Pchrbungee (BETA Pickup) */
    PROP_chrdoordecoder        = 234, /* Door Decoder */
    PROP_chrbombdefuser        = 235, /* Bomb Defuser */
    PROP_chrbugdetector        = 236, /* Pchrbugdetector (BETA Pickup) */
    PROP_chrsafecrackercase    = 237, /* Safe Cracker Case (Briefcase Laying Down) */
    PROP_chrcamera             = 238, /* Photo Camera (007) */
    PROP_chrlockexploder       = 239, /* Pchrlockexploder (BETA Pickup) */
    PROP_chrdoorexploder       = 240, /* Pchrdoorexploder (BETA Pickup) */
    PROP_chrkeyanalysercase    = 241, /* Key Analyzer Case (Briefcase Laying Down) */
    PROP_chrweaponcase         = 242, /* Weapon Case (Briefcase Standing Up) */
    PROP_chrkeyyale            = 243, /* Yale Key */
    PROP_chrkeybolt            = 244, /* Bolt Key */
    PROP_chrbug                = 245, /* Covert Modem / Tracker Bug */
    PROP_chrmicrocamera        = 246, /* Micro Camera */
    PROP_floppy                = 247, /* Floppy Disc */
    PROP_chrgoldeneyekey       = 248, /* GoldenEye Key */
    PROP_chrpolarizedglasses   = 249, /* Polarized Glasses */
    PROP_chrcreditcard         = 250, /* Pchrcreditcard (BETA Pickup) */
    PROP_chrdarkglasses        = 251, /* Pchrdarkglasses (BETA Pickup) */
    PROP_chrgaskeyring         = 252, /* Gas Keyring */
    PROP_chrdatathief          = 253, /* Datathief */
    PROP_safe                  = 254, /* Safe Body */
    PROP_bomb                  = 255, /* Pbomb (BETA Pickup) */
    PROP_chrplans              = 256, /* Plans (Briefing Folder) */
    PROP_chrspyfile            = 257, /* Pchrspyfile (BETA Pickup) */
    PROP_chrblueprints         = 258, /* Pirate Blueprints */
    PROP_chrcircuitboard       = 259, /* Circuitboard */
    PROP_chrmap                = 260, /* Bunker Expansion Plans */
    PROP_chrspooltape          = 261, /* Pchrspooltape (BETA Pickup) */
    PROP_chraudiotape          = 262, /* Audiotape */
    PROP_chrmicrofilm          = 263, /* Pchrmicrofilm (BETA Pickup) */
    PROP_chrmicrocode          = 264, /* Pchrmicrocode (BETA Pickup) */
    PROP_chrlectre             = 265, /* Pchrlectre (BETA Pickup) */
    PROP_chrmoney              = 266, /* Pchrmoney (BETA Pickup) */
    PROP_chrgoldbar            = 267, /* Pchrgoldbar (BETA Pickup) */
    PROP_chrheroin             = 268, /* Pchrheroin (BETA Pickup) */
    PROP_chrclipboard          = 269, /* Clipboard */
    PROP_chrdossierred         = 270, /* Red Dossier */
    PROP_chrstafflist          = 271, /* Staff List */
    PROP_chrdattape            = 272, /* DAT */
    PROP_chrplastique          = 273, /* Plastique */
    PROP_chrblackbox           = 274, /* Black Box (Orange Flight Recorder) */
    PROP_chrvideotape          = 275, /* CCTV Tape (GoldenEye VHS) */
    PROP_nintendologo          = 276, /* Nintendo Logo */
    PROP_goldeneyelogo         = 277, /* GoldenEye Logo */
    PROP_walletbond            = 278, /* Classified Folder w/ Royal Crest (Folder Menus) */
    PROP_miltruck              = 279, /* Supply Truck */
    PROP_jeep                  = 280, /* Military Jeep */
    PROP_artic                 = 281, /* Red Prime Mover */
    PROP_helicopter            = 282, /* Transport Helicopter w/ Natalya */
    PROP_tiger                 = 283, /* Pirate Euro Chopper */
    PROP_milcopter             = 284, /* Hound Helicopter */
    PROP_hind                  = 285, /* Soviet Camouflage Chopper */
    PROP_artictrailer          = 286, /* Black Trailer */
    PROP_motorbike             = 287, /* Motorbike */
    PROP_tank                  = 288, /* Tank */
    PROP_apc                   = 289, /* Armored Personnel Carrier */
    PROP_speedboat             = 290, /* Speedboat */
    PROP_plane                 = 291, /* Aeroplane */
    PROP_gun_runway1           = 292, /* Heavy Gun Emplacement */
    PROP_safedoor              = 293, /* Safe Door */
    PROP_key_holder            = 294, /* Key Rack */
    PROP_hatchsevx             = 295, /* Grating (Ventshaft Hatch) */
    PROP_sevdish               = 296, /* Satellite Dish (Severnaya) */
    PROP_archsecdoor1          = 297, /* Archives Moving Wall (Dark) */
    PROP_archsecdoor2          = 298, /* Archives Moving Wall (Light) */
    PROP_groundgun             = 299, /* Free Standing Drone Gun */
    PROP_trainextdoor          = 300, /* Train Exterior Door */
    PROP_carbmw                = 301, /* White Car #1 (BMW) */
    PROP_carescort             = 302, /* White Car #2 (Escort) */
    PROP_cargolf               = 303, /* White Car #3 (Golf) */
    PROP_carweird              = 304, /* Red Car (Cadillac) */
    PROP_carzil                = 305, /* Ourumov's Car (ZIL) */
    PROP_shuttle_door_l        = 306, /* Exhaust Bay Doors, Left Side */
    PROP_shuttle_door_r        = 307, /* Exhaust Bay Doors, Right Side */
    PROP_depot_gate_entry      = 308, /* Metallic Gate w/ Red Star */
    PROP_depot_door_steel      = 309, /* Rusty Door w/ Handle (Lo-Res) */
    PROP_glassware2            = 310, /* Beaker w/ Blue Topper */
    PROP_glassware3            = 311, /* Erlenmeyer Flask */
    PROP_glassware4            = 312, /* Set of Five Beakers */
    PROP_landmine              = 313, /* Land Mine */
    PROP_plant1                = 314, /* Jungle Plant, Withered and Dying */
    PROP_plant11               = 315, /* Jungle Plant, Turning Colour */
    PROP_plant2                = 316, /* Jungle Plant, Healthy and Thick */
    PROP_plant3                = 317, /* Jungle Plant, Tall Leaves */
    PROP_jungle5_tree          = 318, /* Jungle Tree, Moss Covered */
    PROP_legalpage             = 319, /* GoldenEye Certification Screen */
    PROP_st_pete_room_1i       = 320, /* Roads and Buildings #1 (stretch of road) */
    PROP_st_pete_room_2i       = 321, /* Roads and Buildings #2 (stretch of road) */
    PROP_st_pete_room_3t       = 322, /* Roads and Buildings #3 (intersection) */
    PROP_st_pete_room_5c       = 323, /* Roads and Buildings #4 (street corner) */
    PROP_st_pete_room_6c       = 324, /* Roads and Buildings #5 (street corner) */
    PROP_door_rollertrain      = 325, /* Roller Door */
    PROP_door_win              = 326, /* Glass Sliding Door (Aztec) */
    PROP_door_aztec            = 327, /* Stone Sliding Door (Aztec) */
    PROP_shuttle               = 328, /* Moonraker Shuttle */
    PROP_door_azt_desk         = 329, /* Boardroom Table (Aztec Exhaust Bay) */
    PROP_door_azt_desk_top     = 330, /* Boardroom Table Extension (Aztec Exhaust Bay) */
    PROP_door_azt_chair        = 331, /* Boardroom Chair (Aztec Exhaust Bay) */
    PROP_door_mf               = 332, /* Mainframe Door */
    PROP_flag                  = 333, /* Flag Tag Token */
    PROP_barricade             = 334, /* Road Barricade */
    PROP_modembox              = 335, /* Covert Modem Connection Screen */
    PROP_doorpanel             = 336, /* Sliding Door Activation Switch */
    PROP_doorconsole           = 337, /* Console w/ Activation Light */
    PROP_chrtesttube           = 338, /* Glass Test Tube */
    PROP_bollard               = 339  /* Bollard */
} PROPS;

typedef enum PROJECTILES
{
  PROJECTILES_MAX = 0x2E,
  PROJECTILES_TYPE_KNIFE = PROP_chrknife,
  PROJECTILES_TYPE_GRENADE = PROP_chrgrenade,
  PROJECTILES_TYPE_REMOTE_MINE = PROP_chrremotemine,
  PROJECTILES_TYPE_PROX_MINE = PROP_chrproximitymine,
  PROJECTILES_TYPE_TIMED_MINE = PROP_chrtimedmine,
  PROJECTILES_TYPE_ROCKET_ROUND = PROP_chrrocket,
  PROJECTILES_TYPE_ROCKET_ROUND2 = PROP_chrrocket,
  PROJECTILES_TYPE_GLAUNCH_ROUND = PROP_chrgrenaderound,
  PROJECTILES_TYPE_BOMBCASE = PROP_chrbombcase,
  PROJECTILES_TYPE_BUG = PROP_chrbug,
  PROJECTILES_TYPE_MICROCAMERA = PROP_chrmicrocamera,
  PROJECTILES_TYPE_GE_KEY = PROP_chrgoldeneyekey,
  PROJECTILES_TYPE_PLASTIQUE = PROP_chrplastique
} PROJECTILES;

typedef enum AMMOTYPES {
    AMMO_NONE = 0,
    AMMO_9MM = 1,
    AMMO_9MM_2 = 2,
    AMMO_RIFLE = 3,
    AMMO_SHOTGUN = 4,
    AMMO_GRENADE = 5,
    AMMO_ROCKETS = 6,
    AMMO_REMOTEMINE = 7,
    AMMO_PROXMINE = 8,
    AMMO_TIMEDMINE = 9,
    AMMO_KNIFE = 10,
    AMMO_GRENADEROUND = 11,
    AMMO_MAGNUM = 12,
    AMMO_GGUN = 13,
    AMMO_DARTS = 14,
    AMMO_EXPLOSIVEPEN = 15,
    AMMO_BOMBCASE = 16,
    AMMO_FLARE = 17,
    AMMO_PITON = 18,
    AMMO_DYNAMITE = 19,
    AMMO_BUG = 20,
    AMMO_MICRO_CAMERA = 21,
    AMMO_GEKEY = 22,
    AMMO_PLASTIQUE = 23,
    AMMO_WATCH_LASER = 24,
    AMMO_WATCH_MAGNET = 25,
    AMMO_UNK = 26,
    AMMO_CAMERA = 27,
    AMMO_TANK = 28,
    AMMO_TOKEN = 29
} AMMOTYPES;

typedef enum DOORSTATE
{
  OPEN = 0x1,
  CLOSED = 0x2
} DOORSTATE;

typedef enum SCREEN_SIZE
{
  SCREEN_SIZE_320x240 = 0x0,
  SCREEN_SIZE_440x330 = 0x1
} SCREEN_SIZE;

typedef enum COLORMODE
{
  MODE_32BIT = 0x0,
  MODE_16BIT = 0x1
} COLORMODE;

typedef enum CAMERAMODE {
    INTRO_CAM = 1,
    FADESWIRL_CAM,
    SWIRL_CAM,
    FP_CAM,
    UNK5_CAM,
    UNK6_CAM,
    POSEND_CAM,
    FP_NOINPUT_CAM,
    MP_CAM,
    UNK10_CAM
} CAMERAMODE;

/* motion capture actor: duncan botwood */
/* motion capture assistance: b jones */
/* recorded using 'flock of birds' system by ascension technology corporation, in a freezing metal barn in the depths of winter */
/* note: animations are double handed weapon (KF7) unless specified (unarmed, one_handed_weapon, dual_wield) */
typedef enum ANIMATIONS {
    ANIM_idle = 0,
    ANIM_fire_standing = 1,
    ANIM_fire_standing_fast = 2,
    ANIM_fire_hip = 3,
    ANIM_fire_shoulder_left = 4,
    ANIM_fire_turn_right1 = 5,
    ANIM_fire_turn_right2 = 6,
    ANIM_fire_kneel_right_leg = 7,
    ANIM_fire_kneel_left_leg = 8,
    ANIM_fire_kneel_left = 9,
    ANIM_fire_kneel_right = 10,
    ANIM_fire_roll_left = 11,
    ANIM_fire_roll_right1 = 12,
    ANIM_fire_roll_left_fast = 13,
    ANIM_hit_left_shoulder = 14,
    ANIM_hit_right_shoulder = 15,
    ANIM_hit_left_arm = 16,
    ANIM_hit_right_arm = 17,
    ANIM_hit_left_hand = 18,
    ANIM_hit_right_hand = 19,
    ANIM_hit_left_leg = 20,
    ANIM_hit_right_leg = 21,
    ANIM_death_genitalia = 22, /* thank you mr. botwood, here is your award */
    ANIM_hit_neck = 23,
    ANIM_death_neck = 24,
    ANIM_death_stagger_back_to_wall = 25,
    ANIM_death_forward_face_down = 26,
    ANIM_death_forward_spin_face_up = 27,
    ANIM_death_backward_fall_face_up1 = 28,
    ANIM_death_backward_spin_face_down_right = 29,
    ANIM_death_backward_spin_face_up_right = 30,
    ANIM_death_backward_spin_face_down_left = 31,
    ANIM_death_backward_spin_face_up_left = 32,
    ANIM_death_forward_face_down_hard = 33,
    ANIM_death_forward_face_down_soft = 34,
    ANIM_death_fetal_position_right = 35,
    ANIM_death_fetal_position_left = 36,
    ANIM_death_backward_fall_face_up2 = 37,
    ANIM_side_step_left = 38,
    ANIM_fire_roll_right2 = 39,
    ANIM_walking = 40,
    ANIM_sprinting = 41,
    ANIM_running = 42,
    ANIM_bond_eye_walk = 43,
    ANIM_bond_eye_fire = 44,
    ANIM_bond_watch = 45,
    ANIM_surrendering_armed = 46,
    ANIM_surrendering_armed_drop_weapon = 47,
    ANIM_fire_walking = 48,
    ANIM_fire_running = 49,
    ANIM_null50 = 50, /* invalid slot */
    ANIM_null51 = 51, /* invalid slot */
    ANIM_fire_jump_to_side_left = 52,
    ANIM_fire_jump_to_side_right = 53,
    ANIM_hit_butt_long = 54,
    ANIM_hit_butt_short = 55,
    ANIM_death_head = 56,
    ANIM_death_left_leg = 57,
    ANIM_slide_right = 58,
    ANIM_slide_left = 59,
    ANIM_jump_backwards = 60, 
    ANIM_extending_left_hand = 61,
    ANIM_fire_throw_grenade = 62,
    ANIM_spotting_bond = 63, /* used by chr ai command guard_points_at_bond */
    ANIM_look_around = 64, /* used by chr ai command guard_animation_looks_around_self */
    ANIM_fire_standing_one_handed_weapon = 65,
    ANIM_fire_standing_draw_one_handed_weapon_fast = 66,
    ANIM_fire_standing_draw_one_handed_weapon_slow = 67,
    ANIM_fire_hip_one_handed_weapon_fast = 68,
    ANIM_fire_hip_one_handed_weapon_slow = 69,
    ANIM_fire_hip_forward_one_handed_weapon = 70,
    ANIM_fire_standing_right_one_handed_weapon = 71,
    ANIM_fire_step_right_one_handed_weapon = 72,
    ANIM_fire_standing_left_one_handed_weapon_slow = 73,
    ANIM_fire_standing_left_one_handed_weapon_fast = 74,
    ANIM_fire_kneel_forward_one_handed_weapon_slow = 75,
    ANIM_fire_kneel_forward_one_handed_weapon_fast = 76,
    ANIM_fire_kneel_right_one_handed_weapon_slow = 77,
    ANIM_fire_kneel_right_one_handed_weapon_fast = 78,
    ANIM_fire_kneel_left_one_handed_weapon_slow = 79,
    ANIM_fire_kneel_left_one_handed_weapon_fast = 80,
    ANIM_fire_kneel_left_one_handed_weapon = 81,
    ANIM_aim_walking_one_handed_weapon = 82,
    ANIM_aim_walking_left_one_handed_weapon = 83,
    ANIM_aim_walking_right_one_handed_weapon = 84,
    ANIM_aim_running_one_handed_weapon = 85,
    ANIM_aim_running_right_one_handed_weapon = 86,
    ANIM_aim_running_left_one_handed_weapon = 87,
    ANIM_aim_sprinting_one_handed_weapon = 88,
    ANIM_running_one_handed_weapon = 89,
    ANIM_sprinting_one_handed_weapon = 90,
    ANIM_null91 = 91, /* invalid slot */
    ANIM_null92 = 92, /* invalid slot */
    ANIM_null93 = 93, /* invalid slot */
    ANIM_null94 = 94, /* invalid slot */
    ANIM_null95 = 95, /* invalid slot */
    ANIM_null96 = 96, /* invalid slot */
    ANIM_draw_one_handed_weapon_and_look_around = 97,
    ANIM_draw_one_handed_weapon_and_stand_up = 98,
    ANIM_aim_one_handed_weapon_left_right = 99,
    ANIM_cock_one_handed_weapon_and_turn_around = 100,
    ANIM_holster_one_handed_weapon_and_cross_arms = 101,
    ANIM_cock_one_handed_weapon_turn_around_and_stand_up = 102,
    ANIM_draw_one_handed_weapon_and_turn_around = 103,
    ANIM_step_forward_and_hold_one_handed_weapon = 104,
    ANIM_holster_one_handed_weapon_and_adjust_suit = 105,
    ANIM_idle_unarmed = 106,
    ANIM_walking_unarmed = 107,
    ANIM_fire_walking_dual_wield = 108,
    ANIM_fire_walking_dual_wield_hands_crossed = 109,
    ANIM_fire_running_dual_wield = 110,
    ANIM_fire_running_dual_wield_hands_crossed = 111,
    ANIM_fire_sprinting_dual_wield = 112,
    ANIM_fire_sprinting_dual_wield_hands_crossed = 113,
    ANIM_walking_female = 114,
    ANIM_running_female = 115,
    ANIM_fire_kneel_dual_wield = 116,
    ANIM_fire_kneel_dual_wield_left = 117,
    ANIM_fire_kneel_dual_wield_right = 118,
    ANIM_fire_kneel_dual_wield_hands_crossed = 119,
    ANIM_fire_kneel_dual_wield_hands_crossed_left = 120,
    ANIM_fire_kneel_dual_wield_hands_crossed_right = 121,
    ANIM_fire_standing_dual_wield = 122,
    ANIM_fire_standing_dual_wield_left = 123,
    ANIM_fire_standing_dual_wield_right = 124,
    ANIM_fire_standing_dual_wield_hands_crossed_left = 125,
    ANIM_fire_standing_dual_wield_hands_crossed_right = 126,
    ANIM_fire_standing_aiming_down_sights = 127,
    ANIM_fire_kneel_aiming_down_sights = 128,
    ANIM_hit_taser = 129, /* unused tazer boy hit reaction */
    ANIM_death_explosion_forward = 130,
    ANIM_death_explosion_left1 = 131,
    ANIM_death_explosion_back_left = 132,
    ANIM_death_explosion_back1 = 133,
    ANIM_death_explosion_right = 134,
    ANIM_death_explosion_forward_right1 = 135,
    ANIM_death_explosion_back2 = 136,
    ANIM_death_explosion_forward_roll = 137,
    ANIM_death_explosion_forward_face_down = 138,
    ANIM_death_explosion_left2 = 139,
    ANIM_death_explosion_forward_right2 = 140,
    ANIM_death_explosion_forward_right2_alt = 141, /* copy of right2 with different fall */
    ANIM_death_explosion_forward_right3 = 142,
    ANIM_null143 = 143, /* invalid slot */
    ANIM_null144 = 144, /* invalid slot */
    ANIM_null145 = 145, /* invalid slot */
    ANIM_null146 = 146, /* invalid slot */
    ANIM_running_hands_up = 147,
    ANIM_sprinting_hands_up = 148,
    ANIM_aim_and_blow_one_handed_weapon = 149, /* reversed animation? */
    ANIM_aim_one_handed_weapon_left = 150,
    ANIM_aim_one_handed_weapon_right = 151,
    ANIM_conversation = 152,
    ANIM_drop_weapon_and_show_fight_stance = 153, /* orthodox stance woo */
    ANIM_yawning = 154,
    ANIM_swatting_flies = 155,
    ANIM_scratching_leg = 156,
    ANIM_scratching_butt = 157,
    ANIM_adjusting_crotch = 158,
    ANIM_sneeze = 159,
    ANIM_conversation_cleaned = 160, /* cleaned up copy of ANIM_conversation (compare left wrist) */
    ANIM_conversation_listener = 161,
    ANIM_startled_and_looking_around = 162,
    ANIM_laughing_in_disbelief = 163,
    ANIM_surrendering_unarmed = 164,
    ANIM_coughing_standing = 165,
    ANIM_coughing_kneel1 = 166,
    ANIM_coughing_kneel2 = 167,
    ANIM_standing_up = 168,
    ANIM_null169 = 169, /* invalid slot */
    ANIM_dancing = 170, 
    ANIM_dancing_one_handed_weapon = 171,
    ANIM_keyboard_right_hand1 = 172,
    ANIM_keyboard_right_hand2 = 173,
    ANIM_keyboard_left_hand = 174,
    ANIM_keyboard_right_hand_tapping = 175,
    ANIM_bond_eye_fire_alt = 176, /* unused */
    ANIM_dam_jump = 177,
    ANIM_surface_vent_jump = 178,
    ANIM_cradle_jump = 179,
    ANIM_cradle_fall = 180,
    ANIM_credits_bond_kissing = 181,
    ANIM_credits_natalya_kissing = 182
} ANIMATIONS;

typedef enum AIRCRAFT_ANIMATIONS {
    ANIM_helicopter_cradle = 0,
    ANIM_plane_runway = 1,
    ANIM_helicopter_takeoff = 2
} AIRCRAFT_ANIMATIONS;

typedef enum HANDEDNESS {
    RIGHT_HAND = 0,
    LEFT_HAND = 1
} HANDEDNESS;

// used by characters
typedef enum ACT_TYPE {
    ACT_INIT = 0,
    ACT_STAND,
    ACT_KNEEL,
    ACT_ANIM,
    ACT_DIE,
    ACT_DEAD,
    ACT_ARGH,
    ACT_PREARGH,
    ACT_ATTACK,
    ACT_ATTACKWALK,
    ACT_ATTACKROLL,
    ACT_SIDESTEP,
    ACT_JUMPOUT,
    ACT_RUNPOS,
    ACT_PATROL,
    ACT_GOPOS,
    ACT_SURRENDER,
    ACT_LOOKATTARGET,
    ACT_SURPRISED,
    ACT_STARTALARM,
    ACT_THROWGRENADE,
    ACT_TURNDIR,
    ACT_TEST,
    ACT_NULL
} ACT_TYPE;

// character flags
#define CHRHIDDEN_DROP_HELD_ITEMS       0x0001 // drop held items/weapons
#define CHRHIDDEN_0002                  0x0002 // unknown
#define CHRHIDDEN_FIRE_WEAPON_LEFT      0x0004 // firing left weapon
#define CHRHIDDEN_FIRE_WEAPON_RIGHT     0x0008 // firing right weapon
#define CHRHIDDEN_0010                  0x0010 // unknown
#define CHRHIDDEN_REMOVE                0x0020 // remove character
#define CHRHIDDEN_TIMER_ACTIVE          0x0040 // chr timer is active
#define CHRHIDDEN_FIRE_TRACER           0x0080 // spawn a tracer
#define CHRHIDDEN_MOVING                0x0100 // moving
#define CHRHIDDEN_0200                  0x0200 // unknown
#define CHRHIDDEN_0400                  0x0400 // unknown
#define CHRHIDDEN_FREEZE                0x0800 // freeze current animation state
#define CHRHIDDEN_1000                  0x1000 // unknown
#define CHRHIDDEN_2000                  0x2000 // unknown
#define CHRHIDDEN_4000                  0x4000 // unknown
#define CHRHIDDEN_8000                  0x8000 // unknown

#define CHRFLAG_INIT                         0x00000001 // initialize chr
#define CHRFLAG_CLONE                        0x00000002 // clone on heard gunfire (used by GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
#define CHRFLAG_NEAR_MISS                    0x00000004 // chr was just nearly shot (sometimes set on direct hit)
#define CHRFLAG_HAS_BEEN_ON_SCREEN           0x00000008 // chr has been on screen before
#define CHRFLAG_INVINCIBLE                   0x00000010 // invincible
#define CHRFLAG_00000020                     0x00000020 // unknown
#define CHRFLAG_CAN_SHOOT_CHRS               0x00000040 // can shoot other guards
#define CHRFLAG_00000080                     0x00000080 // unknown
#define CHRFLAG_WAS_DAMAGED                  0x00000100 // chr has taken damage (not invincible)
#define CHRFLAG_00000200                     0x00000200 // unknown
#define CHRFLAG_HIDDEN                       0x00000400 // hidden
#define CHRFLAG_NO_AUTOAIM                   0x00000800 // no autoaim
#define CHRFLAG_LOCK_Y_POS                   0x00001000 // lock y position (no gravity, used for dam/cradle jump)
#define CHRFLAG_NO_SHADOW                    0x00002000 // no shadow
#define CHRFLAG_IGNORE_ANIM_TRANSLATION      0x00004000 // ignore animation translation
#define CHRFLAG_00008000                     0x00008000 // unknown
#define CHRFLAG_00010000                     0x00010000 // unknown
#define CHRFLAG_00020000                     0x00020000 // unknown
#define CHRFLAG_00040000                     0x00040000 // unknown
#define CHRFLAG_INCREASE_SPRINT_SPEED        0x00080000 // increase sprinting speed (used by trevelyan)
#define CHRFLAG_COUNT_DEATH_AS_CIVILIAN      0x00100000 // count death as civilian killed
#define CHRFLAG_WAS_HIT                      0x00200000 // chr has been hit (even if invincible)
#define CHRFLAG_00400000                     0x00400000 // unknown
#define CHRFLAG_CULL_USING_HITBOX            0x00800000 // cull chr using hitbox instead of tile/clipping (useful with lock y pos flag)
#define CHRFLAG_01000000                     0x01000000 // unknown
#define CHRFLAG_02000000                     0x02000000 // unknown
#define CHRFLAG_04000000                     0x04000000 // unknown
#define CHRFLAG_08000000                     0x08000000 // unknown
#define CHRFLAG_10000000                     0x10000000 // unknown
#define CHRFLAG_20000000                     0x20000000 // unknown
#define CHRFLAG_40000000                     0x40000000 // unknown
#define CHRFLAG_80000000                     0x80000000 // unknown

// prop/object flags
#define PROPFLAG_00000001                    0x00000001 // unknown
#define PROPFLAG_00000002                    0x00000002 // unknown
#define PROPFLAG_00000004                    0x00000004 // unknown
#define PROPFLAG_00000008                    0x00000008 // unknown
#define PROPFLAG_00000010                    0x00000010 // unknown
#define PROPFLAG_00000020                    0x00000020 // unknown
#define PROPFLAG_00000040                    0x00000040 // unknown
#define PROPFLAG_00000080                    0x00000080 // unknown
#define PROPFLAG_00000100                    0x00000100 // unknown
#define PROPFLAG_00000200                    0x00000200 // unknown
#define PROPFLAG_00000400                    0x00000400 // unknown
#define PROPFLAG_00000800                    0x00000800 // unknown
#define PROPFLAG_00001000                    0x00001000 // unknown
#define PROPFLAG_00002000                    0x00002000 // unknown
#define PROPFLAG_00004000                    0x00004000 // unknown
#define PROPFLAG_00008000                    0x00008000 // unknown
#define PROPFLAG_00010000                    0x00010000 // unknown
#define PROPFLAG_00020000                    0x00020000 // unknown
#define PROPFLAG_00040000                    0x00040000 // unknown
#define PROPFLAG_00080000                    0x00080000 // unknown
#define PROPFLAG_00100000                    0x00100000 // unknown
#define PROPFLAG_00200000                    0x00200000 // unknown
#define PROPFLAG_00400000                    0x00400000 // unknown
#define PROPFLAG_00800000                    0x00800000 // unknown
#define PROPFLAG_01000000                    0x01000000 // unknown
#define PROPFLAG_02000000                    0x02000000 // unknown
#define PROPFLAG_04000000                    0x04000000 // unknown
#define PROPFLAG_08000000                    0x08000000 // unknown
#define PROPFLAG_10000000                    0x10000000 // unknown
#define PROPFLAG_20000000                    0x20000000 // unknown
#define PROPFLAG_40000000                    0x40000000 // unknown
#define PROPFLAG_80000000                    0x80000000 // unknown

#define PROPFLAG2_00000001                   0x00000001 // unknown
#define PROPFLAG2_00000002                   0x00000002 // unknown
#define PROPFLAG2_00000004                   0x00000004 // unknown
#define PROPFLAG2_00000008                   0x00000008 // unknown
#define PROPFLAG2_00000010                   0x00000010 // unknown
#define PROPFLAG2_00000020                   0x00000020 // unknown
#define PROPFLAG2_00000040                   0x00000040 // unknown
#define PROPFLAG2_00000080                   0x00000080 // unknown
#define PROPFLAG2_00000100                   0x00000100 // unknown
#define PROPFLAG2_00000200                   0x00000200 // unknown
#define PROPFLAG2_00000400                   0x00000400 // unknown
#define PROPFLAG2_00000800                   0x00000800 // unknown
#define PROPFLAG2_00001000                   0x00001000 // unknown
#define PROPFLAG2_00002000                   0x00002000 // unknown
#define PROPFLAG2_00004000                   0x00004000 // unknown
#define PROPFLAG2_00008000                   0x00008000 // unknown
#define PROPFLAG2_00010000                   0x00010000 // unknown
#define PROPFLAG2_00020000                   0x00020000 // unknown
#define PROPFLAG2_00040000                   0x00040000 // unknown
#define PROPFLAG2_00080000                   0x00080000 // unknown
#define PROPFLAG2_00100000                   0x00100000 // unknown
#define PROPFLAG2_00200000                   0x00200000 // unknown
#define PROPFLAG2_00400000                   0x00400000 // unknown
#define PROPFLAG2_00800000                   0x00800000 // unknown
#define PROPFLAG2_01000000                   0x01000000 // unknown
#define PROPFLAG2_02000000                   0x02000000 // unknown
#define PROPFLAG2_04000000                   0x04000000 // unknown
#define PROPFLAG2_08000000                   0x08000000 // unknown
#define PROPFLAG2_10000000                   0x10000000 // unknown
#define PROPFLAG2_20000000                   0x20000000 // unknown
#define PROPFLAG2_40000000                   0x40000000 // unknown
#define PROPFLAG2_80000000                   0x80000000 // unknown

// door lock flags
#define DOOR_LOCK_0 0x01
#define DOOR_LOCK_1 0x02
#define DOOR_LOCK_2 0x04
#define DOOR_LOCK_3 0x08
#define DOOR_LOCK_4 0x10
#define DOOR_LOCK_5 0x20
#define DOOR_LOCK_6 0x40
#define DOOR_LOCK_7 0x80

#define OBJECTTYPE_00 0x00
#define OBJECTTYPE_01 0x01
#define OBJECTTYPE_02 0x02
#define OBJECTTYPE_03 0x03
#define OBJECTTYPE_04 0x04
#define OBJECTTYPE_05 0x05
#define OBJECTTYPE_06 0x06
#define OBJECTTYPE_07 0x07
#define OBJECTTYPE_WEAPON 0x08
#define OBJECTTYPE_09 0x09
#define OBJECTTYPE_10 0x10
#define OBJECTTYPE_11 0x11
#define OBJECTTYPE_12 0x12
#define OBJECTTYPE_13 0x13
#define OBJECTTYPE_14 0x14
#define OBJECTTYPE_15 0x15
#define OBJECTTYPE_16 0x16
#define OBJECTTYPE_17 0x17
#define OBJECTTYPE_18 0x18
#define OBJECTTYPE_19 0x19
#define OBJECTTYPE_20 0x20
#define OBJECTTYPE_21 0x21
#define OBJECTTYPE_22 0x22
#define OBJECTTYPE_23 0x23
#define OBJECTTYPE_24 0x24
#define OBJECTTYPE_25 0x25
#define OBJECTTYPE_26 0x26
#define OBJECTTYPE_27 0x27
#define OBJECTTYPE_28 0x28
#define OBJECTTYPE_29 0x29
#define OBJECTTYPE_30 0x30
#define OBJECTTYPE_31 0x31
#define OBJECTTYPE_32 0x32
#define OBJECTTYPE_33 0x33
#define OBJECTTYPE_34 0x34
#define OBJECTTYPE_35 0x35
#define OBJECTTYPE_36 0x36



#endif

