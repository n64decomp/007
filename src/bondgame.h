#ifndef _BOND_H_
#define _BOND_H_
#include "ultra64.h"

extern u16 cfb_16_a[];
extern u16 cfb_16_b[];

extern u32 *_codeSegmentStart;
extern u32 *_codeSegmentEnd;
extern u32 *_codeSegmentRomStart;
extern u32 *_codeSegmentRomEnd;

extern u32 *_csegmentSegmentStart;
extern u32 *_csegmentSegmentEnd;
extern u32 *_cdataSegmentRomStart;
extern u32 *_cdataSegmentRomEnd;

extern u32 *_rarezipSegmentVaddrStart;
extern u32 *_rarezipSegmentVaddrEnd;
extern u32 *_rarezipSegmentRomStart;
extern u32 *_rarezipSegmentRomEnd;

extern u32 *_gameSegmentVaddrStart;
extern u32 *_gameSegmentVaddrEnd;
extern u32 *_gameSegmentRomStart;
extern u32 *_gameSegmentRomEnd;


extern u8 sp_boot[];
extern u8 sp_rmon[];
extern u8 sp_idle[];
extern u8 sp_shed[];
extern u8 sp_main[];
extern u8 sp_audi[];
extern u8 sp_debug[];

struct rgba_val{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

#define OBJECTIVES_MAX 10

typedef enum MISSION_BRIEFING {BRIEF_OVERVIEW = 0, BRIEF_M, BRIEF_Q, BRIEF_MONEYPENNY} MISSION_BRIEFING;
typedef enum DIFFICULTY {DIFFICULTY_AGENT = 0, DIFFICULTY_SECRET, DIFFICULTY_00, DIFFICULTY_007, DIFFICULTY_MULTI = 0xFFFFFFFF} DIFFICULTY;

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
    M_ARCHIVES=11,
    M_ARCHIVESX=37,
    M_AZTEC=25,
    M_AZTECX=46,
    M_BUNKER1=15,
    M_BUNKER1X=41,
    M_BUNKER2=16,
    M_BUNKER2X=42,
    M_CITADEL=6,
    M_CONTROL=8,
    M_CONTROLX=33,
    M_CRADLE=19,
    M_CRADLEX=48,
    M_CUBA=49,
    M_DAM=9,
    M_DAMX=35,
    M_DEATHSOLO=27,
    M_DEPOT=4,
    M_DEPOTX=32,
    M_EGYPTIAN=22,
    M_EGYPTIANX=39,
    M_EGYPTX=47,
    M_ELEVATOR_CONTROL=18,
    M_ELEVATOR_WC=21,
    M_END_SOMETHING=62,
    M_FACILITY=7,
    M_FACILITYX=31,
    M_FOLDERS=23,
    M_FRIGATE=10,
    M_FRIGATEX=36,
    M_GUITARGLISS=54,
    M_INTRO=2,
    M_INTROSWOOSH=44,
    M_JUNGLE=55,
    M_JUNGLEX=43,
    M_MPDEATH=58,
    M_MPTHEME=5,
    M_MPTHEME2=13,
    M_MPTHEME3=52,
    M_NONE=0,
    M_RUNWAY=50,
    M_RUNWAYPLANE=51,
    M_RUNWAYX=56,
    M_SHORT_SOLO_DEATH=1,
    M_SILO=12,
    M_SILOX=38,
    M_STATUE=17,
    M_STATUEPART=61,
    M_STATUEX=45,
    M_STREETS=14,
    M_STREETSX=40,
    M_SURFACE1=57,
    M_SURFACE2=28,
    M_SURFACE2END=60,
    M_SURFACE2X=59,
    M_TRAIN=3,
    M_TRAINX=29,
    M_UNK=20,
    M_UNK2=30,
    M_WATCH=24,
    M_WATERCAVERNS=26,
    M_WATERCAVERNSX=34,
    M_WIND=53
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
    BRIEFING_MONEYPENNY
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
    MENU_SPECTRUM_EMU
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

typedef enum PROJECTILES
{
  PROJECTILES_MAX = 0x2E,
  PROJECTILES_TYPE_KNIFE = 0xBA,
  PROJECTILES_TYPE_GRENADE = 0xC4,
  PROJECTILES_TYPE_REMOTE_MINE = 0xC7,
  PROJECTILES_TYPE_PROX_MINE = 0xC8,
  PROJECTILES_TYPE_TIMED_MINE = 0xC9,
  PROJECTILES_TYPE_ROCKET_ROUND = 0xCA,
  PROJECTILES_TYPE_ROCKET_ROUND2 = 0xCA,
  PROJECTILES_TYPE_GLAUNCH_ROUND = 0xCB,
  PROJECTILES_TYPE_BOMBCASE = 0xE2,
  PROJECTILES_TYPE_BUG = 0xF5,
  PROJECTILES_TYPE_MICROCAMERA = 0xF6,
  PROJECTILES_TYPE_GE_KEY = 0xF8,
  PROJECTILES_TYPE_PLASTIQUE = 0x111
} PROJECTILES;

typedef enum AMMOTYPES {
    AMMO_9MM=1,
    AMMO_9MM_2=2,
    AMMO_RIFLE=3,
    AMMO_SHOTGUN=4,
    AMMO_GRENADE=5,
    AMMO_ROCKETS=6,
    AMMO_REMOTEMINE=7,
    AMMO_PROXMINE=8,
    AMMO_TIMEDMINE=9,
    AMMO_KNIFE=10,
    AMMO_GRENADEROUND=11,
    AMMO_MAGNUM=12,
    AMMO_GGUN=13,
    AMMO_DARTS=14,
    AMMO_EXPLOSIVEPEN=15,
    AMMO_BOMBCASE=16,
    AMMO_FLARE=17,
    AMMO_PITON=18,
    AMMO_DYNAMITE=19,
    AMMO_BUG=20,
    AMMO_MICRO_CAMERA=21,
    AMMO_GEKEY=22,
    AMMO_PLASTIQUE=23,
    AMMO_WATCH_LASER=24,
    AMMO_WATCH_MAGNET=25,
    AMMO_UNK=26,
    AMMO_CAMERA=27,
    AMMO_TANK=28,
    AMMO_TOKEN=29
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
    INTRO_CAM=1,
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

typedef enum guard_action_type {
    None=0,
    dying=4,
    fade_away=5,
    freeze=2,
    freeze_anim=17,
    gettingshot=6,
    limping=7,
    look_around=18,
    moving=15,
    run_roll_fire=10,
    sidehop=12,
    siderun=13,
    sidestep=11,
    standing=1,
    standstill_fire=8,
    surrendering=16,
    swattingflies=3,
    throw_grenade=20,
    trigger_alarm=19,
    walk_fire=9,
    walk_path=14
} guard_action_type;


#endif
