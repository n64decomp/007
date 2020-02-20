typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long double    longdouble;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef signed char    schar;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef struct save_file save_file, *Psave_file;

typedef ulong u32;

typedef uchar u8;

typedef enum controller_config_type {
    1_1_honey=0,
    1_2_solitaire=1,
    1_3_kissy=2,
    1_4_goodnight=3,
    2_1_plenty=4,
    2_2_galore=5,
    2_3_domino=6,
    2_4_goodhead=7,
    screenmode_cinema=8
} controller_config_type;

struct save_file {
    u32 checksum1;
    u32 checksum2;
    u8 completion_bitflags;
    u8 bitflags;
    u8 music_vol;
    u8 sfx_vol;
    enum controller_config_type controller_config;
    u8 options;
    u8 unlocked_cheats1;
    u8 unlocked_cheats2;
    u8 unlocked_cheats3;
    u8 padding;
    u8 time_dam_agent[5];
    u8 field_0x17[5];
    u8 field_0x1c[5];
    u8 field_0x21[5];
    u8 field_0x26[5];
    u8 field_0x2b[5];
    u8 field_0x30[5];
    u8 field_0x35[5];
    u8 field_0x3a[5];
    u8 field_0x3f[5];
    u8 field_0x44[5];
    u8 field_0x49[5];
    u8 field_0x4e[5];
    u8 field_0x53[5];
    u8 field_0x58[5];
    u8 field_0x5d[3];
};

typedef struct hit_header hit_header, *Phit_header;

typedef ushort u16;

struct hit_header {
    u16 * pImageIDArray;
    u8 * ptrarray2;
    u16 imgcount;
    u16 count2;
};

typedef enum MPSCENARIOS {
    SCENARIO_2v1=7,
    SCENARIO_2v2=5,
    SCENARIO_3v1=6,
    SCENARIO_LTK=4,
    SCENARIO_MWTGG=3,
    SCENARIO_NORMAL=0,
    SCENARIO_TLD=2,
    SCENARIO_YOLT=1
} MPSCENARIOS;

typedef enum Elf32_GPRMask_MIPS {
    gpr_a0=16,
    gpr_a1=32,
    gpr_a2=64,
    gpr_a3=128,
    gpr_at=2,
    gpr_fp=1073741824,
    gpr_gp=268435456,
    gpr_k0=67108864,
    gpr_k1=134217728,
    gpr_ra=2147483648,
    gpr_s0=65536,
    gpr_s1=131072,
    gpr_s2=262144,
    gpr_s3=524288,
    gpr_s4=1048576,
    gpr_s5=2097152,
    gpr_s6=4194304,
    gpr_s7=8388608,
    gpr_sp=536870912,
    gpr_t0=256,
    gpr_t1=512,
    gpr_t2=1024,
    gpr_t3=2048,
    gpr_t4=4096,
    gpr_t5=8192,
    gpr_t6=16384,
    gpr_t7=32768,
    gpr_t8=16777216,
    gpr_t9=33554432,
    gpr_v0=4,
    gpr_v1=8,
    gpr_zero=1
} Elf32_GPRMask_MIPS;

typedef enum HAND {
    HAND_LEFT=1,
    HAND_RIGHT=0
} HAND;

typedef struct sImageTableEntry sImageTableEntry, *PsImageTableEntry;

struct sImageTableEntry {
    u32 index;
    u8 width;
    u8 height;
    u8 level;
    u8 format;
    u8 depth;
    u8 flagsS;
    u8 flagsT;
    u8 pad;
};

typedef struct prop_pos_data prop_pos_data, *Pprop_pos_data;

struct prop_pos_data {
    u16 x;
    u16 y;
    u16 z;
};

typedef struct s_mem_alloc_entry s_mem_alloc_entry, *Ps_mem_alloc_entry;

typedef long s32;

struct s_mem_alloc_entry {
    s32 addr;
    s32 size;
};

typedef struct bondstruct_unk_80036634 bondstruct_unk_80036634, *Pbondstruct_unk_80036634;

typedef float f32;

struct bondstruct_unk_80036634 {
    u32 u32_0x0;
    u32 u32_0x4;
    u32 u32_0x8;
    f32 f32_0xC;
    u32 u32_0x10;
    u32 u32_0x14;
    u32 u32_0x18;
    f32 f32_0x1c;
    u32 u32_0x20;
    u32 u32_0x24;
    u32 u32_0x28;
};

typedef struct s_pBONDData s_pBONDData, *Ps_pBONDData;

typedef struct Player Player, *PPlayer;

typedef enum CUFF_TYPES {
    CUFF_BLUE=0,
    CUFF_BOILER=3,
    CUFF_JUNGLE=2,
    CUFF_SNOW=4,
    CUFF_TUX=1,
    CUFF_TUX6=6,
    CUFF_TUX7=7,
    CUFF_TUX8=8,
    CUFF_WHITE=5
} CUFF_TYPES;

typedef struct Player_SubStruct_7D0 Player_SubStruct_7D0, *PPlayer_SubStruct_7D0;

typedef enum ITEM_IDS {
    ITEM_56=86,
    ITEM_57=87,
    ITEM_AK47=8,
    ITEM_AUDIOTAPE=71,
    ITEM_AUTOSHOT=16,
    ITEM_BLACKBOX=62,
    ITEM_BLUEPRINTS=69,
    ITEM_BOMBCASE=33,
    ITEM_BOMBDEFUSER=39,
    ITEM_BRIEFCASE=43,
    ITEM_BUG=47,
    ITEM_BUGDETECTOR=49,
    ITEM_BUNGEE=37,
    ITEM_CAMERA=40,
    ITEM_CIRCUITBOARD=63,
    ITEM_CLIPBOARD=64,
    ITEM_CREDITCARD=53,
    ITEM_DARKGLASSES=52,
    ITEM_DATATHIEF=55,
    ITEM_DATTAPE=73,
    ITEM_DOORDECODER=38,
    ITEM_DOOREXPLODER=42,
    ITEM_DOSSIERRED=66,
    ITEM_END=89,
    ITEM_EXPLOSIVEFLOPPY=50,
    ITEM_FIST=1,
    ITEM_FLAREPISTOL=35,
    ITEM_FNP90=14,
    ITEM_GASKEYRING=54,
    ITEM_GOLDBAR=79,
    ITEM_GOLDENEYEKEY=61,
    ITEM_GOLDENGUN=19,
    ITEM_GOLDWPPK=21,
    ITEM_GRENADE=26,
    ITEM_GRENADELAUNCH=24,
    ITEM_HEROIN=80,
    ITEM_JOYPAD=85,
    ITEM_KEYANALYSERCASE=46,
    ITEM_KEYBOLT=83,
    ITEM_KEYCARD=81,
    ITEM_KEYYALE=82,
    ITEM_KNIFE=2,
    ITEM_LASER=22,
    ITEM_LECTRE=77,
    ITEM_LOCKEXPLODER=41,
    ITEM_M16=13,
    ITEM_MAP=70,
    ITEM_MICROCAMERA=48,
    ITEM_MICROCODE=76,
    ITEM_MICROFILM=75,
    ITEM_MONEY=78,
    ITEM_MP5K=10,
    ITEM_MP5KSIL=11,
    ITEM_PITONGUN=36,
    ITEM_PLANS=67,
    ITEM_PLASTIQUE=34,
    ITEM_POLARIZEDGLASSES=51,
    ITEM_PROXIMITYMINE=28,
    ITEM_REMOTEMINE=29,
    ITEM_ROCKETLAUNCH=25,
    ITEM_RUGER=18,
    ITEM_SAFECRACKERCASE=45,
    ITEM_SHOTGUN=15,
    ITEM_SILVERWPPK=20,
    ITEM_SKORPION=7,
    ITEM_SNIPERRIFLE=17,
    ITEM_SPECTRE=12,
    ITEM_SPOOLTAPE=74,
    ITEM_SPYFILE=68,
    ITEM_STAFFLIST=65,
    ITEM_SUIT_LF_HAND=84,
    ITEM_TANKSHELLS=32,
    ITEM_TASER=31,
    ITEM_THROWKNIFE=3,
    ITEM_TIMEDMINE=27,
    ITEM_TOKEN=88,
    ITEM_TRIGGER=30,
    ITEM_TT33=6,
    ITEM_UNARMED=0,
    ITEM_UZI=9,
    ITEM_VIDEOTAPE=72,
    ITEM_WATCHCOMMUNICATOR=57,
    ITEM_WATCHGEIGERCOUNTER=58,
    ITEM_WATCHIDENTIFIER=56,
    ITEM_WATCHLASER=23,
    ITEM_WATCHMAGNETATTRACT=60,
    ITEM_WATCHMAGNETREPEL=59,
    ITEM_WEAPONCASE=44,
    ITEM_WPPK=4,
    ITEM_WPPKSIL=5
} ITEM_IDS;

typedef struct xyzpoint xyzpoint, *Pxyzpoint;

struct s_pBONDData {
    struct Player * p1;
    struct Player * p2;
    struct Player * p3;
    struct Player * p4;
};

struct xyzpoint {
    f32 x;
    f32 y;
    f32 z;
};

struct Player_SubStruct_7D0 {
    u16 field_7D0;
    u16 field_7D2;
    u16 field_7D4;
    u16 field_7D6;
    u16 field_7D8;
    u16 field_7DA;
    u16 field_7DC;
    u16 field_7DE;
};

struct Player {
    int unknown;
    f32 xpos;
    f32 ypos;
    f32 zpos;
    f32 xpos2;
    f32 ypos2;
    f32 zpos2;
    f32 xoffset;
    f32 yoffset;
    f32 zoffset;
    f32 xpos3;
    f32 ypos3;
    f32 zpos3;
    int room_pointer;
    f32 current_model_xpos;
    f32 current_model_ypos;
    f32 current_model_zpos;
    f32 previous_model_xpos;
    f32 previous_model_ypos;
    f32 previous_model_zpos;
    f32 current_room_xpos;
    f32 current_room_ypos;
    f32 current_room_zpos;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    f32 field_6C;
    f32 field_70;
    f32 clipping_height;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    int field_8C;
    f32 field_90;
    int field_94;
    f32 field_98;
    int crouchposition;
    f32 ducking_height_offset;
    f32 field_A4;
    int position_data_pointer;
    int field_AC;
    int field_B0;
    int zpos_0;
    int xpos_0;
    int field_BC;
    int field_C0;
    int zpos_1;
    int xpos_1;
    int field_CC;
    int field_D0;
    int ptr_char_objectinstance;
    int bonddead;
    f32 bondhealth;
    f32 bondarmour;
    f32 oldhealth;
    f32 oldarmour;
    f32 apparenthealth;
    f32 apparentarmour;
    int damageshowtime;
    int healthshowtime;
    int healthshowmode;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int movecentrerelease;
    int lookaheadcentreenabled;
    int automovecentreenabled;
    int fastmovecentreenabled;
    int automovecentre;
    int insightaimmode;
    int autoyaimenabled;
    float autoaimy;
    int autoyaimtime;
    int autoyaimtime60;
    int autoxaimenabled;
    float autoaimx;
    int autoxaimtime;
    int autoxaimtime60;
    float vv_theta;
    float speedtheta;
    f32 vv_costheta;
    f32 vv_sintheta;
    float vv_verta;
    f32 vv_verta360;
    float speedverta;
    f32 vv_cosverta;
    f32 vv_sinverta;
    float speedsideways;
    float speedstrafe;
    float speedforwards;
    f32 speedboost;
    int speedmaxtime60;
    f32 boost_factor_x;
    f32 boost_factor_y;
    f32 boost_factor_z;
    f32 viewport_alpha;
    f32 bondfadetime60;
    f32 bondfadetimemax;
    f32 bondfadefracold;
    f32 bondfadefracnew;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int pause_animation_state;
    int paused_flag;
    int open_close_solo_watch_menu;
    f32 field_1D4;
    f32 field_1D8;
    f32 pause_watch_position;
    f32 field_1E0;
    f32 field_1E4;
    f32 field_1E8;
    f32 field_1EC;
    f32 field_1F0;
    f32 field_1F4;
    int field_1F8;
    int field_1FC;
    int pausing_flag;
    f32 pause_starting_angle;
    f32 field_208;
    f32 pause_target_angle;
    f32 field_210;
    f32 field_214;
    int field_218;
    int field_21C;
    int step_in_view_watch_animation;
    f32 pause_animation_counter;
    int field_228;
    int field_22C;
    int something_with_watch_object_instance;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int watch_scale_destination;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    int field_3B0;
    short field_3B4;
    short field_3B6;
    f32 field_3B8;
    f32 field_3BC;
    int field_3C0;
    f32 field_3C4;
    f32 field_3C8;
    f32 field_3CC;
    u32 tint_red;
    u32 tint_green;
    u32 tint_blue;
    float tint_alpha;
    f32 field_3E0;
    float timer_for_fade;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
    f32 field_400;
    f32 field_404;
    int field_408;
    int field_40C;
    int field_410;
    int field_414;
    int field_418;
    enum CUFF_TYPES cuff_value;
    int field_420;
    int field_424;
    int field_428;
    int field_42C;
    int controlstyle;
    int field_434;
    int field_438;
    int field_43C;
    int field_440;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    int field_454;
    int field_458;
    int field_45C;
    int field_460;
    int field_464;
    int field_468;
    int field_46C;
    int field_470;
    int field_474;
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int ptr_tile_printmanpos;
    f32 positionx;
    int positiony;
    int positionz;
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    int field_4AC;
    int collision_radius;
    int field_4B4;
    int field_4B8;
    int field_4BC;
    int field_4C0;
    int field_4C4;
    int field_4C8;
    int field_4CC;
    int field_4D0;
    int field_4D4;
    int room_tile_ptr;
    int field_4DC;
    int field_4E0;
    int field_4E4;
    int field_4E8;
    f32 field_4EC;
    int field_4F0;
    f32 field_4F4;
    f32 field_4F8;
    f32 scaled_velocity;
    f32 field_500;
    f32 field_504;
    f32 field_508;
    f32 field_50C;
    f32 field_510;
    f32 field_514;
    f32 field_518;
    f32 field_51C;
    f32 velocity;
    f32 field_524;
    f32 field_528;
    f32 field_52C;
    f32 field_530;
    int field_534;
    int field_538;
    f32 field_53C;
    f32 field_540;
    f32 field_544;
    f32 field_548;
    f32 field_54C;
    f32 stationary_ground_offset;
    f32 field_554;
    f32 field_558;
    f32 field_55C;
    f32 field_560;
    f32 field_564;
    f32 field_568;
    f32 field_56C;
    f32 field_570;
    f32 field_574;
    f32 field_578;
    f32 field_57C;
    f32 field_580;
    f32 field_584;
    f32 field_588;
    f32 field_58C;
    f32 field_590;
    int field_594;
    int field_598;
    int field_59C;
    int field_5A0;
    int field_5A4;
    int field_5A8;
    int field_5AC;
    int field_5B0;
    int field_5B4;
    int field_5B8;
    int field_5BC;
    int field_5C0;
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4;
    int field_5D8;
    int field_5DC;
    int field_5E0;
    int field_5E4;
    int field_5E8;
    int field_5EC;
    int field_5F0;
    int field_5F4;
    int field_5F8;
    int field_5FC;
    int field_600;
    int field_604;
    int field_608;
    int field_60C;
    int field_610;
    int field_614;
    int field_618;
    int field_61C;
    int field_620;
    int field_624;
    int field_628;
    int field_62C;
    int field_630;
    int field_634;
    int field_638;
    int field_63C;
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
    int field_654;
    int field_658;
    int field_65C;
    int field_660;
    int field_664;
    int field_668;
    int field_66C;
    int field_670;
    int field_674;
    int field_678;
    int field_67C;
    int field_680;
    int field_684;
    int field_688;
    int field_68C;
    int field_690;
    int field_694;
    int field_698;
    int field_69C;
    int field_6A0;
    int field_6A4;
    int field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
    int field_6D4;
    int field_6D8;
    int field_6DC;
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
    int field_700;
    int field_704;
    int field_708;
    int field_70C;
    int field_710;
    int field_714;
    int field_718;
    int field_71C;
    int field_720;
    int field_724;
    int field_728;
    int field_72C;
    int field_730;
    int field_734;
    int field_738;
    int field_73C;
    int field_740;
    int field_744;
    int field_748;
    int field_74C;
    int field_750;
    int field_754;
    int field_758;
    int field_75C;
    int field_760;
    int field_764;
    int field_768;
    int field_76C;
    int field_770;
    int field_774;
    int field_778;
    int field_77C;
    int field_780;
    int field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    int field_798;
    int field_79C;
    int field_7A0;
    int field_7A4;
    int field_7A8;
    int field_7AC;
    int field_7B0;
    int field_7B4;
    int field_7B8;
    int field_7BC;
    int field_7C0;
    int field_7C4;
    int field_7C8;
    int field_7CC;
    struct Player_SubStruct_7D0 field_7D0;
    struct Player_SubStruct_7D0 field_7E0;
    short viewx;
    short viewy;
    short viewleft;
    short viewtop;
    int hand_invisible[2];
    enum ITEM_IDS hand_item[2];
    u8 * ptr_hand_weapon_buffer[2];
    int copy_of_body_obj_header[8];
    int copy_of_right_weapon_obj_header[8];
    int field_850;
    int field_854;
    int field_858;
    int field_85C;
    int field_860;
    int right_item_related1;
    int right_item_related2;
    int right_item_related3;
    int right_weapon;
    int right_weapon_attack;
    int previous_right_weapon;
    int right_weapon_firing_status;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int when_detonating_mines_is_0;
    int right_weapon_current_animation;
    int right_weapon_ammo_in_magazine;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int right_weapon_next_weapon;
    int field_8B0;
    int right_weapon_animation_trigger;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;
    int field_910;
    int field_914;
    int field_918;
    int field_91C;
    int field_920;
    int field_924;
    int field_928;
    int field_92C;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    int field_960;
    int field_964;
    int field_968;
    int field_96C;
    int field_970;
    int field_974;
    int field_978;
    int field_97C;
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;
    int field_9B0;
    int field_9B4;
    int field_9B8;
    int field_9BC;
    int field_9C0;
    int field_9C4;
    int field_9C8;
    int field_9CC;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;
    int field_9E0;
    int field_9E4;
    int field_9E8;
    int field_9EC;
    int field_9F0;
    int field_9F4;
    int field_9F8;
    int field_9FC;
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    int field_A40;
    int field_A44;
    int field_A48;
    int field_A4C;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int noise;
    int field_A84;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
    int field_AB4;
    int field_AB8;
    int field_ABC;
    int field_AC0;
    int field_AC4;
    int field_AC8;
    int field_ACC;
    int field_AD0;
    int field_AD4;
    int field_AD8;
    int field_ADC;
    int field_AE0;
    int field_AE4;
    int field_AE8;
    int field_AEC;
    int field_AF0;
    int field_AF4;
    int field_AF8;
    int field_AFC;
    int field_B00;
    int field_B04;
    int field_B08;
    int field_B0C;
    int field_B10;
    int field_B14;
    int field_B18;
    int field_B1C;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;
    int field_B80;
    int field_B84;
    int field_B88;
    int field_B8C;
    int field_B90;
    int field_B94;
    int field_B98;
    int field_B9C;
    int field_BA0;
    int field_BA4;
    int field_BA8;
    int field_BAC;
    int field_BB0;
    int field_BB4;
    int field_BB8;
    int field_BBC;
    int field_BC0;
    int field_BC4;
    int field_BC8;
    int field_BCC;
    int field_BD0;
    int field_BD4;
    int field_BD8;
    int field_BDC;
    int field_BE0;
    int field_BE4;
    int field_BE8;
    int field_BEC;
    int field_BF0;
    int field_BF4;
    int field_BF8;
    int field_BFC;
    int field_C00;
    int field_C04;
    int field_C08;
    int left_item_related1;
    int left_item_related2;
    int left_item_related3;
    int left_weapon;
    int left_weapon_attack;
    int left_weapon_previous;
    int left_weapon_firing_status;
    int field_C28;
    int field_C2C;
    int field_C30;
    int field_C34;
    int field_C38;
    int field_C3C;
    int left_weapon_animation;
    int left_weapon_ammo_in_magazine;
    int field_C48;
    int field_C4C;
    int field_C50;
    int left_weapon_next_weapon;
    int field_C58;
    int left_weapon_animation_trigger;
    int field_C60;
    int field_C64;
    int field_C68;
    int field_C6C;
    int field_C70;
    int field_C74;
    int field_C78;
    int field_C7C;
    int field_C80;
    int field_C84;
    int field_C88;
    int field_C8C;
    int field_C90;
    int field_C94;
    int field_C98;
    int field_C9C;
    int field_CA0;
    int field_CA4;
    int field_CA8;
    int field_CAC;
    int field_CB0;
    int field_CB4;
    int field_CB8;
    int field_CBC;
    int field_CC0;
    int field_CC4;
    int field_CC8;
    int field_CCC;
    int field_CD0;
    int field_CD4;
    int field_CD8;
    int field_CDC;
    int field_CE0;
    int field_CE4;
    int field_CE8;
    int field_CEC;
    int field_CF0;
    int field_CF4;
    int field_CF8;
    int field_CFC;
    int field_D00;
    int field_D04;
    int field_D08;
    int field_D0C;
    int field_D10;
    int field_D14;
    int field_D18;
    int field_D1C;
    int field_D20;
    int field_D24;
    int field_D28;
    int field_D2C;
    int field_D30;
    int field_D34;
    int field_D38;
    int field_D3C;
    int field_D40;
    int field_D44;
    int field_D48;
    int field_D4C;
    int field_D50;
    int field_D54;
    int field_D58;
    int field_D5C;
    int field_D60;
    int field_D64;
    int field_D68;
    int field_D6C;
    int field_D70;
    int field_D74;
    int field_D78;
    int field_D7C;
    int field_D80;
    int field_D84;
    int field_D88;
    int field_D8C;
    int field_D90;
    int field_D94;
    int field_D98;
    int field_D9C;
    int field_DA0;
    int field_DA4;
    int field_DA8;
    int field_DAC;
    int field_DB0;
    int field_DB4;
    int field_DB8;
    int field_DBC;
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;
    int field_DD0;
    int field_DD4;
    int field_DD8;
    int field_DDC;
    int field_DE0;
    int field_DE4;
    int field_DE8;
    int field_DEC;
    int field_DF0;
    int field_DF4;
    int field_DF8;
    int field_DFC;
    int field_E00;
    int field_E04;
    int field_E08;
    int field_E0C;
    int field_E10;
    int field_E14;
    int field_E18;
    int field_E1C;
    int field_E20;
    int field_E24;
    int field_E28;
    int field_E2C;
    int field_E30;
    int field_E34;
    int field_E38;
    int field_E3C;
    int field_E40;
    int field_E44;
    int field_E48;
    int field_E4C;
    int field_E50;
    int field_E54;
    int field_E58;
    int field_E5C;
    int field_E60;
    int field_E64;
    int field_E68;
    int field_E6C;
    int field_E70;
    int field_E74;
    int field_E78;
    int field_E7C;
    int field_E80;
    int field_E84;
    int field_E88;
    int field_E8C;
    int field_E90;
    int field_E94;
    int field_E98;
    int field_E9C;
    int field_EA0;
    int field_EA4;
    int field_EA8;
    int field_EAC;
    int field_EB0;
    int field_EB4;
    int field_EB8;
    int field_EBC;
    int field_EC0;
    int field_EC4;
    int field_EC8;
    int field_ECC;
    int field_ED0;
    int field_ED4;
    int field_ED8;
    int field_EDC;
    int field_EE0;
    int field_EE4;
    int field_EE8;
    int field_EEC;
    int field_EF0;
    int field_EF4;
    int field_EF8;
    int field_EFC;
    int field_F00;
    int field_F04;
    int field_F08;
    int field_F0C;
    int field_F10;
    int field_F14;
    int field_F18;
    int field_F1C;
    int field_F20;
    int field_F24;
    int field_F28;
    int field_F2C;
    int field_F30;
    int field_F34;
    int field_F38;
    int field_F3C;
    int field_F40;
    int field_F44;
    int field_F48;
    int field_F4C;
    int field_F50;
    int field_F54;
    int field_F58;
    int field_F5C;
    int field_F60;
    int field_F64;
    int field_F68;
    int field_F6C;
    int field_F70;
    int field_F74;
    int field_F78;
    int field_F7C;
    int field_F80;
    int field_F84;
    int field_F88;
    int field_F8C;
    int field_F90;
    int field_F94;
    int field_F98;
    int field_F9C;
    int field_FA0;
    int field_FA4;
    int field_FA8;
    int field_FAC;
    int field_FB0;
    int field_FB4;
    int field_FB8;
    int field_FBC;
    float field_FC0;
    float field_FC4;
    int field_FC8;
    int field_FCC;
    int field_FD0;
    int field_FD4;
    int field_FD8;
    char field_FDC;
    char field_FDD;
    char field_FDE;
    char field_FDF;
    int field_FE0;
    int field_FE4;
    float field_FE8;
    float field_FEC;
    float field_FF0;
    float field_FF4;
    f32 field_FF8;
    float field_FFC;
    float field_1000;
    float field_1004;
    float field_1008;
    f32 field_100C;
    float field_1010;
    f32 holds_neg_pi;
    float field_1018;
    int field_101C;
    int field_1020;
    int field_1024;
    int field_1028;
    int field_102C;
    int field_1030;
    int field_1034;
    int field_1038;
    int field_103C;
    int field_1040;
    int field_1044;
    int field_1048;
    int field_104C;
    int field_1050;
    int field_1054;
    int field_1058;
    int field_105C;
    int copiedgoldeneye;
    int somekinda_flags;
    int field_1068;
    float field_106C;
    float field_1070;
    float field_1074;
    int field_1078;
    float field_107C;
    float field_1080;
    float sniper_zoom;
    float camera_zoom;
    int field_108C;
    float c_screenwidth;
    float c_screenheight;
    float c_screenleft;
    float c_screentop;
    float c_perspnear;
    float c_perspfovy;
    float c_perspaspect;
    float c_halfwidth;
    float c_halfheight;
    f32 c_scalex;
    f32 c_scaley;
    f32 c_recipscalex;
    f32 c_recipscaley;
    int field_10C4;
    int field_10C8;
    int field_10CC;
    int field_10D0;
    int field_10D4;
    int field_10D8;
    int field_10DC;
    int field_10E0;
    int field_10E4;
    int field_10E8;
    int field_10EC;
    f32 c_scalelod60;
    f32 c_scalelod;
    f32 c_lodscalez;
    int c_lodscalezu32;
    struct xyzpoint c_cameratopnorm;
    struct xyzpoint c_cameraleftnorm;
    float screenxminf;
    float screenyminf;
    float screenxmaxf;
    float screenymaxf;
    int somekinda_bitflags;
    int field_112C;
    int ammoheldarr[30];
    int bloodcnt;
    int field_11AC;
    int field_11B0;
    int field_11B4;
    int field_11B8;
    f32 zoomintime;
    f32 zoomintimemax;
    f32 zoominfovy;
    f32 zoominfovyold;
    f32 zoominfovynew;
    f32 fovy;
    f32 aspect;
    int hudmessoff;
    int bondmesscnt;
    int ptr_inventory_first_in_cycle;
    int p_itemcur;
    int equipmaxitems;
    int equipallguns;
    int field_11F0;
    int field_11F4;
    int index_time_spent_using_item;
    int field_11FC;
    int field_1200;
    int field_1204;
    int field_1208;
    int field_120C;
    int field_1210;
    int field_1214;
    int field_1218;
    int field_121C;
    int field_1220;
    int field_1224;
    int field_1228;
    int field_122C;
    int field_1230;
    int field_1234;
    int field_1238;
    int field_123C;
    int field_1240;
    int field_1244;
    int field_1248;
    int field_124C;
    int field_1250;
    int field_1254;
    int field_1258;
    int field_125C;
    int field_1260;
    int field_1264;
    int field_1268;
    int field_126C;
    int field_1270;
    f32 field_1274;
    f32 field_1278;
    f32 field_127C;
    int field_1280;
    int players_cur_animation;
    f32 field_1288;
    int field_128C;
    int field_1290;
    int field_1294;
    int field_1298;
    int field_129C;
    int field_12A0;
    int field_12A4;
    int field_12A8;
    int field_12AC;
    int field_12B0;
    char something_with_cheat_text;
    char can_display_cheat_text;
    char bondinvincible;
    char field_12B7;
    int healthdamagetype;
    int field_12BC;
    int field_12C0;
    int field_12C4;
    int field_12C8;
    int field_12CC;
    int field_12D0;
    int field_12D4;
    int field_12D8;
    int field_12DC;
    int field_12E0;
    int field_12E4;
    int field_12E8;
    int field_12EC;
    int field_12F0;
    int field_12F4;
    int field_12F8;
    int field_12FC;
    int field_1300;
    int field_1304;
    int field_1308;
    int field_130C;
    int field_1310;
    int field_1314;
    int field_1318;
    int field_131C;
    int field_1320;
    int field_1324;
    int field_1328;
    int field_132C;
    int field_1330;
    int field_1334;
    int field_1338;
    int field_133C;
    int field_1340;
    int field_1344;
    int field_1348;
    int field_134C;
    int field_1350;
    int field_1354;
    int field_1358;
    int field_135C;
    int field_1360;
    int field_1364;
    int field_1368;
    int field_136C;
    int field_1370;
    int field_1374;
    int field_1378;
    int field_137C;
    int field_1380;
    int field_1384;
    int field_1388;
    int field_138C;
    int field_1390;
    int field_1394;
    int field_1398;
    int field_139C;
    int field_13A0;
    int field_13A4;
    int field_13A8;
    int field_13AC;
    int field_13B0;
    int field_13B4;
    int field_13B8;
    int field_13BC;
    int field_13C0;
    int field_13C4;
    int field_13C8;
    int field_13CC;
    int field_13D0;
    int field_13D4;
    int field_13D8;
    int field_13DC;
    int field_13E0;
    int field_13E4;
    int field_13E8;
    int field_13EC;
    int field_13F0;
    int field_13F4;
    int field_13F8;
    int field_13FC;
    int field_1400;
    int field_1404;
    int field_1408;
    int field_140C;
    int field_1410;
    int field_1414;
    int field_1418;
    int field_141C;
    int field_1420;
    int field_1424;
    int field_1428;
    int field_142C;
    int field_1430;
    int field_1434;
    int field_1438;
    int field_143C;
    int field_1440;
    int field_1444;
    int field_1448;
    int field_144C;
    int field_1450;
    int field_1454;
    int field_1458;
    int field_145C;
    int field_1460;
    int field_1464;
    int field_1468;
    int field_146C;
    int field_1470;
    int field_1474;
    int field_1478;
    int field_147C;
    int field_1480;
    int field_1484;
    int field_1488;
    int field_148C;
    int field_1490;
    int field_1494;
    int field_1498;
    int field_149C;
    int field_14A0;
    int field_14A4;
    int field_14A8;
    int field_14AC;
    int field_14B0;
    int field_14B4;
    int field_14B8;
    int field_14BC;
    int field_14C0;
    int field_14C4;
    int field_14C8;
    int field_14CC;
    int field_14D0;
    int field_14D4;
    int field_14D8;
    int field_14DC;
    int field_14E0;
    int field_14E4;
    int field_14E8;
    int field_14EC;
    int field_14F0;
    int field_14F4;
    int field_14F8;
    int field_14FC;
    int field_1500;
    int field_1504;
    int field_1508;
    int field_150C;
    int field_1510;
    int field_1514;
    int field_1518;
    int field_151C;
    int field_1520;
    int field_1524;
    int field_1528;
    int field_152C;
    int field_1530;
    int field_1534;
    int field_1538;
    int field_153C;
    int field_1540;
    int field_1544;
    int field_1548;
    int field_154C;
    int field_1550;
    int field_1554;
    int field_1558;
    int field_155C;
    int field_1560;
    int field_1564;
    int field_1568;
    int field_156C;
    int field_1570;
    int field_1574;
    int field_1578;
    int field_157C;
    int field_1580;
    int field_1584;
    int field_1588;
    int field_158C;
    int field_1590;
    int field_1594;
    int related_to_health_display;
    int field_159C;
    int field_15A0;
    int field_15A4;
    int field_15A8;
    int field_15AC;
    int field_15B0;
    int field_15B4;
    int field_15B8;
    int field_15BC;
    int field_15C0;
    int field_15C4;
    int field_15C8;
    int field_15CC;
    int field_15D0;
    int field_15D4;
    int field_15D8;
    int field_15DC;
    int field_15E0;
    int field_15E4;
    int field_15E8;
    int field_15EC;
    int field_15F0;
    int field_15F4;
    int field_15F8;
    int field_15FC;
    int field_1600;
    int field_1604;
    int field_1608;
    int field_160C;
    int field_1610;
    int field_1614;
    int field_1618;
    int field_161C;
    int field_1620;
    int field_1624;
    int field_1628;
    int field_162C;
    int field_1630;
    int field_1634;
    int field_1638;
    int field_163C;
    int field_1640;
    int field_1644;
    int field_1648;
    int field_164C;
    int field_1650;
    int field_1654;
    int field_1658;
    int field_165C;
    int field_1660;
    int field_1664;
    int field_1668;
    int field_166C;
    int field_1670;
    int field_1674;
    int field_1678;
    int field_167C;
    int field_1680;
    int field_1684;
    int field_1688;
    int field_168C;
    int field_1690;
    int field_1694;
    int field_1698;
    int field_169C;
    int field_16A0;
    int field_16A4;
    int field_16A8;
    int field_16AC;
    int field_16B0;
    int field_16B4;
    int field_16B8;
    int field_16BC;
    int field_16C0;
    int field_16C4;
    int field_16C8;
    int field_16CC;
    int field_16D0;
    int field_16D4;
    int field_16D8;
    int field_16DC;
    int field_16E0;
    int field_16E4;
    int field_16E8;
    int field_16EC;
    int field_16F0;
    int field_16F4;
    int field_16F8;
    int field_16FC;
    int field_1700;
    int field_1704;
    int field_1708;
    int field_170C;
    int field_1710;
    int field_1714;
    int field_1718;
    int field_171C;
    int field_1720;
    int field_1724;
    int field_1728;
    int field_172C;
    int field_1730;
    int field_1734;
    int field_1738;
    int field_173C;
    int field_1740;
    int field_1744;
    int field_1748;
    int field_174C;
    int field_1750;
    int field_1754;
    int field_1758;
    int field_175C;
    int field_1760;
    int field_1764;
    int field_1768;
    int field_176C;
    int field_1770;
    int field_1774;
    int field_1778;
    int field_177C;
    int field_1780;
    int field_1784;
    int field_1788;
    int field_178C;
    int field_1790;
    int field_1794;
    int field_1798;
    int field_179C;
    int field_17A0;
    int field_17A4;
    int field_17A8;
    int field_17AC;
    int field_17B0;
    int field_17B4;
    int field_17B8;
    int field_17BC;
    int field_17C0;
    int field_17C4;
    int field_17C8;
    int field_17CC;
    int field_17D0;
    int field_17D4;
    int field_17D8;
    int field_17DC;
    int field_17E0;
    int field_17E4;
    int field_17E8;
    int field_17EC;
    int field_17F0;
    int field_17F4;
    int field_17F8;
    int field_17FC;
    int field_1800;
    int field_1804;
    int field_1808;
    int field_180C;
    int field_1810;
    int field_1814;
    int field_1818;
    int field_181C;
    int field_1820;
    int field_1824;
    int field_1828;
    int field_182C;
    int field_1830;
    int field_1834;
    int field_1838;
    int field_183C;
    int field_1840;
    int field_1844;
    int field_1848;
    int field_184C;
    int field_1850;
    int field_1854;
    int field_1858;
    int field_185C;
    int field_1860;
    int field_1864;
    int field_1868;
    int field_186C;
    int field_1870;
    int field_1874;
    int buffer_for_watch_greenbackdrop_vertices;
    int field_187C;
    int field_1880;
    int field_1884;
    int field_1888;
    int field_188C;
    int field_1890;
    int field_1894;
    int field_1898;
    int field_189C;
    int field_18A0;
    int field_18A4;
    int field_18A8;
    int field_18AC;
    int field_18B0;
    int field_18B4;
    int field_18B8;
    int field_18BC;
    int field_18C0;
    int field_18C4;
    int field_18C8;
    int field_18CC;
    int field_18D0;
    int field_18D4;
    int field_18D8;
    int field_18DC;
    int field_18E0;
    int field_18E4;
    int field_18E8;
    int field_18EC;
    int field_18F0;
    int field_18F4;
    int field_18F8;
    int field_18FC;
    int field_1900;
    int field_1904;
    int field_1908;
    int field_190C;
    int field_1910;
    int field_1914;
    int field_1918;
    int field_191C;
    int field_1920;
    int field_1924;
    int field_1928;
    int field_192C;
    int field_1930;
    int field_1934;
    int field_1938;
    int field_193C;
    int field_1940;
    int field_1944;
    int field_1948;
    int field_194C;
    int field_1950;
    int field_1954;
    int field_1958;
    int field_195C;
    int field_1960;
    int field_1964;
    int field_1968;
    int field_196C;
    int field_1970;
    int field_1974;
    int field_1978;
    int field_197C;
    int field_1980;
    int field_1984;
    int field_1988;
    int field_198C;
    int field_1990;
    int field_1994;
    int field_1998;
    int field_199C;
    int field_19A0;
    int field_19A4;
    int field_19A8;
    int field_19AC;
    int field_19B0;
    int field_19B4;
    int field_19B8;
    int field_19BC;
    int field_19C0;
    int field_19C4;
    int field_19C8;
    int field_19CC;
    int field_19D0;
    int field_19D4;
    int field_19D8;
    int field_19DC;
    int field_19E0;
    int field_19E4;
    int field_19E8;
    int field_19EC;
    int field_19F0;
    int field_19F4;
    int field_19F8;
    int field_19FC;
    int field_1A00;
    int field_1A04;
    int field_1A08;
    int field_1A0C;
    int field_1A10;
    int field_1A14;
    int field_1A18;
    int field_1A1C;
    int field_1A20;
    int field_1A24;
    int field_1A28;
    int field_1A2C;
    int field_1A30;
    int field_1A34;
    int field_1A38;
    int field_1A3C;
    int field_1A40;
    int field_1A44;
    int field_1A48;
    int field_1A4C;
    int field_1A50;
    int field_1A54;
    int field_1A58;
    int field_1A5C;
    int field_1A60;
    int field_1A64;
    int field_1A68;
    int field_1A6C;
    int field_1A70;
    int field_1A74;
    int field_1A78;
    int field_1A7C;
    int field_1A80;
    int field_1A84;
    int field_1A88;
    int field_1A8C;
    int field_1A90;
    int field_1A94;
    int field_1A98;
    int field_1A9C;
    int field_1AA0;
    int field_1AA4;
    int field_1AA8;
    int field_1AAC;
    int field_1AB0;
    int field_1AB4;
    int field_1AB8;
    int field_1ABC;
    int field_1AC0;
    int field_1AC4;
    int field_1AC8;
    int field_1ACC;
    int field_1AD0;
    int field_1AD4;
    int field_1AD8;
    int field_1ADC;
    int field_1AE0;
    int field_1AE4;
    int field_1AE8;
    int field_1AEC;
    int field_1AF0;
    int field_1AF4;
    int field_1AF8;
    int field_1AFC;
    int field_1B00;
    int field_1B04;
    int field_1B08;
    int field_1B0C;
    int field_1B10;
    int field_1B14;
    int field_1B18;
    int field_1B1C;
    int field_1B20;
    int field_1B24;
    int field_1B28;
    int field_1B2C;
    int field_1B30;
    int field_1B34;
    int field_1B38;
    int field_1B3C;
    int field_1B40;
    int field_1B44;
    int field_1B48;
    int field_1B4C;
    int field_1B50;
    int field_1B54;
    int field_1B58;
    int field_1B5C;
    int field_1B60;
    int field_1B64;
    int field_1B68;
    int field_1B6C;
    int field_1B70;
    int field_1B74;
    int field_1B78;
    int field_1B7C;
    int field_1B80;
    int field_1B84;
    int field_1B88;
    int field_1B8C;
    int field_1B90;
    int field_1B94;
    int field_1B98;
    int field_1B9C;
    int field_1BA0;
    int field_1BA4;
    int field_1BA8;
    int field_1BAC;
    int field_1BB0;
    int field_1BB4;
    int field_1BB8;
    int field_1BBC;
    int field_1BC0;
    int field_1BC4;
    int field_1BC8;
    int field_1BCC;
    int field_1BD0;
    int field_1BD4;
    int field_1BD8;
    int field_1BDC;
    int field_1BE0;
    int field_1BE4;
    int field_1BE8;
    int field_1BEC;
    int field_1BF0;
    int field_1BF4;
    int field_1BF8;
    int field_1BFC;
    int field_1C00;
    int field_1C04;
    int field_1C08;
    int field_1C0C;
    int field_1C10;
    int field_1C14;
    int field_1C18;
    int field_1C1C;
    int field_1C20;
    int field_1C24;
    int field_1C28;
    int field_1C2C;
    int field_1C30;
    int field_1C34;
    int field_1C38;
    int field_1C3C;
    int field_1C40;
    int field_1C44;
    int field_1C48;
    int field_1C4C;
    int field_1C50;
    int field_1C54;
    int field_1C58;
    int field_1C5C;
    int field_1C60;
    int field_1C64;
    int field_1C68;
    int field_1C6C;
    int field_1C70;
    int field_1C74;
    int field_1C78;
    int field_1C7C;
    int field_1C80;
    int field_1C84;
    int field_1C88;
    int field_1C8C;
    int field_1C90;
    int field_1C94;
    int field_1C98;
    int field_1C9C;
    int field_1CA0;
    int field_1CA4;
    int field_1CA8;
    int field_1CAC;
    int field_1CB0;
    int field_1CB4;
    int field_1CB8;
    int field_1CBC;
    int field_1CC0;
    int field_1CC4;
    int field_1CC8;
    int field_1CCC;
    int field_1CD0;
    int field_1CD4;
    int field_1CD8;
    int field_1CDC;
    int field_1CE0;
    int field_1CE4;
    int field_1CE8;
    int field_1CEC;
    int field_1CF0;
    int field_1CF4;
    int field_1CF8;
    int field_1CFC;
    int field_1D00;
    int field_1D04;
    int field_1D08;
    int field_1D0C;
    int field_1D10;
    int field_1D14;
    int field_1D18;
    int field_1D1C;
    int field_1D20;
    int field_1D24;
    int field_1D28;
    int field_1D2C;
    int field_1D30;
    int field_1D34;
    int field_1D38;
    int field_1D3C;
    int field_1D40;
    int field_1D44;
    int field_1D48;
    int field_1D4C;
    int field_1D50;
    int field_1D54;
    int field_1D58;
    int field_1D5C;
    int field_1D60;
    int field_1D64;
    int field_1D68;
    int field_1D6C;
    int field_1D70;
    int field_1D74;
    int field_1D78;
    int field_1D7C;
    int field_1D80;
    int field_1D84;
    int field_1D88;
    int field_1D8C;
    int field_1D90;
    int field_1D94;
    int field_1D98;
    int field_1D9C;
    int field_1DA0;
    int field_1DA4;
    int field_1DA8;
    int field_1DAC;
    int field_1DB0;
    int field_1DB4;
    int field_1DB8;
    int field_1DBC;
    int field_1DC0;
    int field_1DC4;
    int field_1DC8;
    int field_1DCC;
    int field_1DD0;
    int field_1DD4;
    int field_1DD8;
    int field_1DDC;
    int field_1DE0;
    int field_1DE4;
    int field_1DE8;
    int field_1DEC;
    int field_1DF0;
    int field_1DF4;
    int field_1DF8;
    int field_1DFC;
    int field_1E00;
    int field_1E04;
    int field_1E08;
    int field_1E0C;
    int field_1E10;
    int field_1E14;
    int field_1E18;
    int field_1E1C;
    int field_1E20;
    int field_1E24;
    int field_1E28;
    int field_1E2C;
    int field_1E30;
    int field_1E34;
    int field_1E38;
    int field_1E3C;
    int field_1E40;
    int field_1E44;
    int field_1E48;
    int field_1E4C;
    int field_1E50;
    int field_1E54;
    int field_1E58;
    int field_1E5C;
    int field_1E60;
    int field_1E64;
    int field_1E68;
    int field_1E6C;
    int field_1E70;
    int field_1E74;
    int field_1E78;
    int field_1E7C;
    int field_1E80;
    int field_1E84;
    int field_1E88;
    int field_1E8C;
    int field_1E90;
    int field_1E94;
    int field_1E98;
    int field_1E9C;
    int field_1EA0;
    int field_1EA4;
    int field_1EA8;
    int field_1EAC;
    int field_1EB0;
    int field_1EB4;
    int field_1EB8;
    int field_1EBC;
    int field_1EC0;
    int field_1EC4;
    int field_1EC8;
    int field_1ECC;
    int field_1ED0;
    int field_1ED4;
    int field_1ED8;
    int field_1EDC;
    int field_1EE0;
    int field_1EE4;
    int field_1EE8;
    int field_1EEC;
    int field_1EF0;
    int field_1EF4;
    int field_1EF8;
    int field_1EFC;
    int field_1F00;
    int field_1F04;
    int field_1F08;
    int field_1F0C;
    int field_1F10;
    int field_1F14;
    int field_1F18;
    int field_1F1C;
    int field_1F20;
    int field_1F24;
    int field_1F28;
    int field_1F2C;
    int field_1F30;
    int field_1F34;
    int field_1F38;
    int field_1F3C;
    int field_1F40;
    int field_1F44;
    int field_1F48;
    int field_1F4C;
    int field_1F50;
    int field_1F54;
    int field_1F58;
    int field_1F5C;
    int field_1F60;
    int field_1F64;
    int field_1F68;
    int field_1F6C;
    int field_1F70;
    int field_1F74;
    int field_1F78;
    int field_1F7C;
    int field_1F80;
    int field_1F84;
    int field_1F88;
    int field_1F8C;
    int field_1F90;
    int field_1F94;
    int field_1F98;
    int field_1F9C;
    int field_1FA0;
    int field_1FA4;
    int field_1FA8;
    int field_1FAC;
    int field_1FB0;
    int field_1FB4;
    int field_1FB8;
    int field_1FBC;
    int field_1FC0;
    int field_1FC4;
    int field_1FC8;
    int field_1FCC;
    int field_1FD0;
    int field_1FD4;
    int field_1FD8;
    int field_1FDC;
    int field_1FE0;
    int field_1FE4;
    int field_1FE8;
    int field_1FEC;
    int field_1FF0;
    int field_1FF4;
    int field_1FF8;
    int field_1FFC;
    int field_2000;
    int field_2004;
    int field_2008;
    int field_200C;
    int field_2010;
    int field_2014;
    int field_2018;
    int field_201C;
    int field_2020;
    int field_2024;
    int field_2028;
    int field_202C;
    int field_2030;
    int field_2034;
    int field_2038;
    int field_203C;
    int field_2040;
    int field_2044;
    int field_2048;
    int field_204C;
    int field_2050;
    int field_2054;
    int field_2058;
    int field_205C;
    int field_2060;
    int field_2064;
    int field_2068;
    int field_206C;
    int field_2070;
    int field_2074;
    int field_2078;
    int field_207C;
    int field_2080;
    int field_2084;
    int field_2088;
    int field_208C;
    int field_2090;
    int field_2094;
    int field_2098;
    int field_209C;
    int field_20A0;
    int field_20A4;
    int field_20A8;
    int field_20AC;
    int field_20B0;
    int field_20B4;
    int field_20B8;
    int field_20BC;
    int field_20C0;
    int field_20C4;
    int field_20C8;
    int field_20CC;
    int field_20D0;
    int field_20D4;
    int field_20D8;
    int field_20DC;
    int field_20E0;
    int field_20E4;
    int field_20E8;
    int field_20EC;
    int field_20F0;
    int field_20F4;
    int field_20F8;
    int field_20FC;
    int field_2100;
    int field_2104;
    int field_2108;
    int field_210C;
    int field_2110;
    int field_2114;
    int field_2118;
    int field_211C;
    int field_2120;
    int field_2124;
    int field_2128;
    int field_212C;
    int field_2130;
    int field_2134;
    int field_2138;
    int field_213C;
    int field_2140;
    int field_2144;
    int field_2148;
    int field_214C;
    int field_2150;
    int field_2154;
    int field_2158;
    int field_215C;
    int field_2160;
    int field_2164;
    int field_2168;
    int field_216C;
    int field_2170;
    int field_2174;
    int field_2178;
    int field_217C;
    int field_2180;
    int field_2184;
    int field_2188;
    int field_218C;
    int field_2190;
    int field_2194;
    int field_2198;
    int field_219C;
    int field_21A0;
    int field_21A4;
    int field_21A8;
    int field_21AC;
    int field_21B0;
    int field_21B4;
    int field_21B8;
    int field_21BC;
    int field_21C0;
    int field_21C4;
    int field_21C8;
    int field_21CC;
    int field_21D0;
    int field_21D4;
    int field_21D8;
    int field_21DC;
    int field_21E0;
    int field_21E4;
    int field_21E8;
    int field_21EC;
    int field_21F0;
    int field_21F4;
    int field_21F8;
    int field_21FC;
    int field_2200;
    int field_2204;
    int field_2208;
    int field_220C;
    int field_2210;
    int field_2214;
    int field_2218;
    int field_221C;
    int field_2220;
    int field_2224;
    int field_2228;
    int field_222C;
    int field_2230;
    int field_2234;
    int field_2238;
    int field_223C;
    int field_2240;
    int field_2244;
    int field_2248;
    int field_224C;
    int field_2250;
    int field_2254;
    int field_2258;
    int field_225C;
    int field_2260;
    int field_2264;
    int field_2268;
    int field_226C;
    int field_2270;
    int field_2274;
    int field_2278;
    int field_227C;
    int field_2280;
    int field_2284;
    int field_2288;
    int field_228C;
    int field_2290;
    int field_2294;
    int field_2298;
    int field_229C;
    int field_22A0;
    int field_22A4;
    int field_22A8;
    int field_22AC;
    int field_22B0;
    int field_22B4;
    int field_22B8;
    int field_22BC;
    int field_22C0;
    int field_22C4;
    int field_22C8;
    int field_22CC;
    int field_22D0;
    int field_22D4;
    int field_22D8;
    int field_22DC;
    int field_22E0;
    int field_22E4;
    int field_22E8;
    int field_22EC;
    int field_22F0;
    int field_22F4;
    int field_22F8;
    int field_22FC;
    int field_2300;
    int field_2304;
    int field_2308;
    int field_230C;
    int field_2310;
    int field_2314;
    int field_2318;
    int field_231C;
    int field_2320;
    int field_2324;
    int field_2328;
    int field_232C;
    int field_2330;
    int field_2334;
    int field_2338;
    int field_233C;
    int field_2340;
    int field_2344;
    int field_2348;
    int field_234C;
    int field_2350;
    int field_2354;
    int field_2358;
    int field_235C;
    int field_2360;
    int field_2364;
    int field_2368;
    int field_236C;
    int field_2370;
    int field_2374;
    int field_2378;
    int field_237C;
    int field_2380;
    int field_2384;
    int field_2388;
    int field_238C;
    int field_2390;
    int field_2394;
    int field_2398;
    int field_239C;
    int field_23A0;
    int field_23A4;
    int field_23A8;
    int field_23AC;
    int field_23B0;
    int field_23B4;
    int field_23B8;
    int field_23BC;
    int field_23C0;
    int field_23C4;
    int field_23C8;
    int field_23CC;
    int field_23D0;
    int field_23D4;
    int field_23D8;
    int field_23DC;
    int field_23E0;
    int field_23E4;
    int field_23E8;
    int field_23EC;
    int field_23F0;
    int field_23F4;
    int field_23F8;
    int field_23FC;
    int field_2400;
    int field_2404;
    int field_2408;
    int field_240C;
    int field_2410;
    int field_2414;
    int field_2418;
    int field_241C;
    int field_2420;
    int field_2424;
    int field_2428;
    int field_242C;
    int field_2430;
    int field_2434;
    int field_2438;
    int field_243C;
    int field_2440;
    int field_2444;
    int field_2448;
    int field_244C;
    int field_2450;
    int field_2454;
    int field_2458;
    int field_245C;
    int field_2460;
    int field_2464;
    int field_2468;
    int field_246C;
    int field_2470;
    int field_2474;
    int field_2478;
    int field_247C;
    int field_2480;
    int field_2484;
    int field_2488;
    int field_248C;
    int field_2490;
    int field_2494;
    int field_2498;
    int field_249C;
    int field_24A0;
    int field_24A4;
    int field_24A8;
    int field_24AC;
    int field_24B0;
    int field_24B4;
    int field_24B8;
    int field_24BC;
    int field_24C0;
    int field_24C4;
    int field_24C8;
    int field_24CC;
    int field_24D0;
    int field_24D4;
    int field_24D8;
    int field_24DC;
    int field_24E0;
    int field_24E4;
    int field_24E8;
    int field_24EC;
    int field_24F0;
    int field_24F4;
    int field_24F8;
    int field_24FC;
    int field_2500;
    int field_2504;
    int field_2508;
    int field_250C;
    int field_2510;
    int field_2514;
    int field_2518;
    int field_251C;
    int field_2520;
    int field_2524;
    int field_2528;
    int field_252C;
    int field_2530;
    int field_2534;
    int field_2538;
    int field_253C;
    int field_2540;
    int field_2544;
    int field_2548;
    int field_254C;
    int field_2550;
    int field_2554;
    int field_2558;
    int field_255C;
    int field_2560;
    int field_2564;
    int field_2568;
    int field_256C;
    int field_2570;
    int field_2574;
    int field_2578;
    int field_257C;
    int field_2580;
    int field_2584;
    int field_2588;
    int field_258C;
    int field_2590;
    int field_2594;
    int field_2598;
    int field_259C;
    int field_25A0;
    int field_25A4;
    int field_25A8;
    int field_25AC;
    int field_25B0;
    int field_25B4;
    int field_25B8;
    int field_25BC;
    int field_25C0;
    int field_25C4;
    int field_25C8;
    int field_25CC;
    int field_25D0;
    int field_25D4;
    int field_25D8;
    int field_25DC;
    int field_25E0;
    int field_25E4;
    int field_25E8;
    int field_25EC;
    int field_25F0;
    int field_25F4;
    int field_25F8;
    int field_25FC;
    int field_2600;
    int field_2604;
    int field_2608;
    int field_260C;
    int field_2610;
    int field_2614;
    int field_2618;
    int field_261C;
    int field_2620;
    int field_2624;
    int field_2628;
    int field_262C;
    int field_2630;
    int field_2634;
    int field_2638;
    int field_263C;
    int field_2640;
    int field_2644;
    int field_2648;
    int field_264C;
    int field_2650;
    int field_2654;
    int field_2658;
    int field_265C;
    int field_2660;
    int field_2664;
    int field_2668;
    int field_266C;
    int field_2670;
    int field_2674;
    int field_2678;
    int field_267C;
    int field_2680;
    int field_2684;
    int field_2688;
    int field_268C;
    int field_2690;
    int field_2694;
    int field_2698;
    int field_269C;
    int field_26A0;
    int field_26A4;
    int field_26A8;
    int field_26AC;
    int field_26B0;
    int field_26B4;
    int field_26B8;
    int field_26BC;
    int field_26C0;
    int field_26C4;
    int field_26C8;
    int field_26CC;
    int field_26D0;
    int field_26D4;
    int field_26D8;
    int field_26DC;
    int field_26E0;
    int field_26E4;
    int field_26E8;
    int field_26EC;
    int field_26F0;
    int field_26F4;
    int field_26F8;
    int field_26FC;
    int field_2700;
    int field_2704;
    int field_2708;
    int field_270C;
    int field_2710;
    int field_2714;
    int field_2718;
    int field_271C;
    int field_2720;
    int field_2724;
    int field_2728;
    int field_272C;
    int field_2730;
    int field_2734;
    int field_2738;
    int field_273C;
    int field_2740;
    int field_2744;
    int field_2748;
    int field_274C;
    int field_2750;
    int field_2754;
    int field_2758;
    int field_275C;
    int field_2760;
    int field_2764;
    int field_2768;
    int field_276C;
    int field_2770;
    int field_2774;
    int field_2778;
    int field_277C;
    int field_2780;
    int field_2784;
    int field_2788;
    int field_278C;
    int field_2790;
    int field_2794;
    int field_2798;
    int field_279C;
    int field_27A0;
    int field_27A4;
    int field_27A8;
    int field_27AC;
    int field_27B0;
    int field_27B4;
    int field_27B8;
    int field_27BC;
    int field_27C0;
    int field_27C4;
    int field_27C8;
    int field_27CC;
    int field_27D0;
    int field_27D4;
    int field_27D8;
    int field_27DC;
    int field_27E0;
    int field_27E4;
    int field_27E8;
    int field_27EC;
    int field_27F0;
    int field_27F4;
    int field_27F8;
    int field_27FC;
    int field_2800;
    int field_2804;
    int field_2808;
    int field_280C;
    int field_2810;
    int field_2814;
    int field_2818;
    int field_281C;
    int field_2820;
    int field_2824;
    int field_2828;
    int field_282C;
    int field_2830;
    int field_2834;
    int field_2838;
    int field_283C;
    int field_2840;
    int field_2844;
    int field_2848;
    int field_284C;
    int field_2850;
    int field_2854;
    int buffer_for_watch_greenbackdrop_DL;
    int field_285C;
    int field_2860;
    int field_2864;
    int field_2868;
    int field_286C;
    int field_2870;
    int field_2874;
    int field_2878;
    int field_287C;
    int field_2880;
    int field_2884;
    int field_2888;
    int field_288C;
    int field_2890;
    int field_2894;
    int field_2898;
    int field_289C;
    int field_28A0;
    int field_28A4;
    int field_28A8;
    int field_28AC;
    int field_28B0;
    int field_28B4;
    int field_28B8;
    int field_28BC;
    int field_28C0;
    int field_28C4;
    int field_28C8;
    int field_28CC;
    int field_28D0;
    int field_28D4;
    int field_28D8;
    int field_28DC;
    int field_28E0;
    int field_28E4;
    int field_28E8;
    int field_28EC;
    int field_28F0;
    int field_28F4;
    int field_28F8;
    int field_28FC;
    int field_2900;
    int field_2904;
    int field_2908;
    int field_290C;
    int field_2910;
    int field_2914;
    int field_2918;
    int field_291C;
    int field_2920;
    int field_2924;
    int field_2928;
    int field_292C;
    int field_2930;
    int field_2934;
    int field_2938;
    int field_293C;
    int field_2940;
    int field_2944;
    int field_2948;
    int field_294C;
    int field_2950;
    int field_2954;
    int field_2958;
    int field_295C;
    int field_2960;
    int field_2964;
    int field_2968;
    int field_296C;
    int field_2970;
    int field_2974;
    int field_2978;
    int field_297C;
    int field_2980;
    int field_2984;
    int field_2988;
    int field_298C;
    int field_2990;
    int field_2994;
    int field_2998;
    int field_299C;
    int field_29A0;
    int field_29A4;
    int field_29A8;
    int field_29AC;
    int field_29B0;
    int field_29B4;
    int field_29B8;
    f32 field_29BC;
    f32 field_29C0;
    int mpmenuon;
    int mpmenumode;
    int mpquitconfirm;
    int mpjoywascentre;
    int damagetype;
    int deathcount;
    int num_suicides;
    int field_29E0;
    int last_kill_time;
    int field_29E8;
    int field_29EC;
    int field_29F0;
    int field_29F4;
    int field_29F8;
    int field_29FC;
    int healthdisplaytime;
    int field_2A04;
    f32 field_2A08;
    f32 field_2A0C;
    int ptr_text_first_mp_award;
    int ptr_text_second_mp_award;
    int field_2A18;
    int field_2A1C;
    int field_2A20;
    int field_2A24;
    int field_2A28;
    int field_2A2C;
    int field_2A30;
    int field_2A34;
    int cur_item_weapon_getname;
    f32 actual_health;
    f32 actual_armor;
    int field_2A44[2];
    f32 field_2A4C;
    int lock_hand_model[2];
    int cur_player_control_type_0;
    int cur_player_control_type_1;
    float cur_player_control_type_2;
    int neg_vspacing_for_control_type_entry;
    int has_set_control_type_data;
    int field_2A6C;
    int field_2A70;
    int field_2A74;
    int field_2A78;
    int field_2A7C;
};

typedef struct indy_resource_entry indy_resource_entry, *Pindy_resource_entry;

struct indy_resource_entry {
    u32 resourceID;
    s32 type;
    s32 size;
    s32 readsize;
    s32 writesize;
};

typedef struct s_mempBANK s_mempBANK, *Ps_mempBANK;

struct s_mempBANK {
    s32 bankstart;
    s32 nextentry;
    s32 bankend;
    void * data2;
};

typedef struct player_gait_header player_gait_header, *Pplayer_gait_header;

typedef struct player_gait_object_entry player_gait_object_entry, *Pplayer_gait_object_entry;

typedef struct player_gait_pos_header player_gait_pos_header, *Pplayer_gait_pos_header;

typedef struct player_gait_position_entry player_gait_position_entry, *Pplayer_gait_position_entry;

struct player_gait_object_entry {
    u32 field_0x0;
    struct player_gait_header * ptr_header;
    u32 field_0x8;
    u32 field_0xc;
};

struct player_gait_position_entry {
    float flt_1;
    float flt_2;
    float flt_3;
    u16 field_0xc;
    u16 field_0xe;
    u16 field_0x10;
    u16 field_0x12;
    struct player_gait_header * ptr_header;
    u32 field_0x18;
};

struct player_gait_pos_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    struct player_gait_position_entry * entry;
    struct player_gait_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_header * next;
};

struct player_gait_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    struct player_gait_object_entry * entry;
    struct player_gait_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_pos_header * next;
};

typedef struct LnameX_table_entry LnameX_table_entry, *PLnameX_table_entry;

struct LnameX_table_entry {
    string * extext;
    string * jtext;
};

typedef struct portal_table_entry portal_table_entry, *Pportal_table_entry;


// WARNING! conflicting data type names: /types.h/s32 - /ultratypes.h/s32

struct portal_table_entry {
    s32 id;
    s32 x_min;
    s32 y_min;
    s32 x_max;
    s32 y_max;
};

typedef struct resource_lookup_data_entry resource_lookup_data_entry, *Presource_lookup_data_entry;

struct resource_lookup_data_entry {
    u32 rom_size;
    s32 pc_remaining;
    u32 pc_size;
    u32 buffer_remaining;
    u8 loaded_bank;
    u8 unk_11;
    u16 reserved;
};

typedef struct firing_anim_struct firing_anim_struct, *Pfiring_anim_struct;

struct firing_anim_struct {
    pointer pointer;
    dword anim;
    f32 x;
    f32 y;
    f32 z;
};

typedef struct fog_element fog_element, *Pfog_element;

struct fog_element {
    u32 stageID;
    f32 blendmultiplier;
    f32 farfog;
    f32 nearfog;
    f32 maxvisrange;
    f32 maxobfuscationrange;
    f32 minvisrange;
    u32 intensity;
    u32 dif_in_light;
    u32 far_ambiantlight;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    u16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    u16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

typedef struct s_mainloop_unk s_mainloop_unk, *Ps_mainloop_unk;

struct s_mainloop_unk {
    undefined4 dword_80024304;
    undefined4 dword_80024308;
    undefined4 dword_8002430C;
    undefined4 dword_80024310;
    undefined4 dword_80024314;
    undefined4 dword_80024318;
    undefined4 dword_8002431C;
    undefined4 dword_80024320;
};

typedef enum STAGENUM {
    SP_STAGE_ARCHIVES=10,
    SP_STAGE_AZTEK=18,
    SP_STAGE_BUNKER1=4,
    SP_STAGE_BUNKER2=8,
    SP_STAGE_CAVERNS=16,
    SP_STAGE_CONTROL=15,
    SP_STAGE_CRADLE=17,
    SP_STAGE_DAM=0,
    SP_STAGE_DEPOT=12,
    SP_STAGE_EGYPT=19,
    SP_STAGE_FACILITY=1,
    SP_STAGE_FRIGATE=6,
    SP_STAGE_JUNGLE=14,
    SP_STAGE_MAX=20,
    SP_STAGE_RUNWAY=2,
    SP_STAGE_SILO=5,
    SP_STAGE_STATUE=9,
    SP_STAGE_STREETS=11,
    SP_STAGE_SURFACE1=3,
    SP_STAGE_SURFACE2=7,
    SP_STAGE_TRAIN=13
} STAGENUM;

typedef enum PLAYER_ID {
    PLAYER1=0,
    PLAYER2=1,
    PLAYER3=2,
    PLAYER4=3
} PLAYER_ID;

typedef struct indy_read_buf indy_read_buf, *Pindy_read_buf;


// WARNING! conflicting data type names: /types.h/u32 - /ultratypes.h/u32

struct indy_read_buf {
    u32 resourceID;
    s32 type;
    s32 size;
};

typedef struct sfxdata sfxdata, *Psfxdata;

struct sfxdata {
    s32 target_volume;
    s32 audio_range_time;
    s32 initial_volume;
    void * preset_emitter;
    void * object_emitter;
};

typedef struct ramromfilestructure ramromfilestructure, *Pramromfilestructure;

typedef double f64;

typedef enum LEVELID {
    LEVELID_ARCHIVES=24,
    LEVELID_AZTEC=28,
    LEVELID_BASEMENT=45,
    LEVELID_BUNKER1=9,
    LEVELID_BUNKER2=27,
    LEVELID_CAVERNS=39,
    LEVELID_CAVES=50,
    LEVELID_CITADEL=40,
    LEVELID_COMPLEX=31,
    LEVELID_CONTROL=23,
    LEVELID_CRADLE=41,
    LEVELID_CUBA=54,
    LEVELID_DAM=33,
    LEVELID_DEPOT=30,
    LEVELID_EAR=51,
    LEVELID_EGYPT=32,
    LEVELID_ELD=44,
    LEVELID_FACILITY=34,
    LEVELID_FRIGATE=26,
    LEVELID_JUNGLE=37,
    LEVELID_LEE=52,
    LEVELID_LIBRARY=48,
    LEVELID_LIP=53,
    LEVELID_LUE=47,
    LEVELID_MAX=57,
    LEVELID_NONE=-1,
    LEVELID_PAM=56,
    LEVELID_RIT=49,
    LEVELID_RUNWAY=35,
    LEVELID_SHO=42,
    LEVELID_SILO=20,
    LEVELID_STACK=46,
    LEVELID_STATUE=22,
    LEVELID_STREETS=29,
    LEVELID_SURFACE=36,
    LEVELID_SURFACE2=43,
    LEVELID_TEMPLE=38,
    LEVELID_TITLE=90,
    LEVELID_TRAIN=25,
    LEVELID_WAX=55
} LEVELID;

typedef enum DIFFICULTY {
    DIFFICULTY_00=2,
    DIFFICULTY_007=3,
    DIFFICULTY_AGENT=0,
    DIFFICULTY_MULTI=-1,
    DIFFICULTY_SECRET=1
} DIFFICULTY;

typedef enum GAMEMODE {
    GAMEMODE_CHEATS=2,
    GAMEMODE_INTRO=-1,
    GAMEMODE_MULTI=1,
    GAMEMODE_SOLO=0
} GAMEMODE;

struct ramromfilestructure {
    f64 randomseed;
    f64 randomizer;
    enum LEVELID stagenum;
    enum DIFFICULTY difficulty;
    u32 size_cmds;
    struct save_file savefile;
    f32 totaltime_ms;
    u32 filesize;
    enum GAMEMODE mode;
    u32 slotnum;
    u32 numplayers;
    u32 scenario;
    u32 mpstage_sel;
    u32 gamelength;
    u32 mp_weapon_set;
    u32 p1_mp_char;
    u32 p2_mp_char;
    u32 p3_mp_char;
    u32 p4_mp_char;
    u32 p1_handi;
    u32 p2_handi;
    u32 p3_handi;
    u32 p4_handi;
    u32 p1_contstyle;
    u32 p2_contstyle;
    u32 p3_contstyle;
    u32 p4_contstyle;
    u32 aim_option;
    u32 p1_flags;
    u32 p2_flags;
    u32 p3_flags;
    u32 p4_flags;
    u32 controlerstatepackets;
};

typedef struct s_mem_alloc_table s_mem_alloc_table, *Ps_mem_alloc_table;

struct s_mem_alloc_table {
    struct s_mem_alloc_entry entries[512];
};

typedef struct bg_portal_entry bg_portal_entry, *Pbg_portal_entry;

struct bg_portal_entry {
    u8 numPoints;
    u8 padding[3];
    struct xyzpoint point;
};

typedef struct bg_data_header bg_data_header, *Pbg_data_header;

typedef struct bg_room_data bg_room_data, *Pbg_room_data;

typedef struct bg_portal_data_entry bg_portal_data_entry, *Pbg_portal_data_entry;

struct bg_data_header {
    u32 RESERVED;
    struct bg_room_data * pRoomDataTable;
    struct bg_portal_data_entry * pPortalDataTable;
    void * pGlobalVisCmds;
};

struct bg_portal_data_entry {
    struct bg_portal_entry * offset_portal;
    u8 connectedRoom1;
    u8 connectedRoom2;
    u16 controlbytes;
};

struct bg_room_data {
    f32 xpos;
    f32 ypos;
    f32 zpos;
    void * pPointTableBin;
    void * pPriMappingBin;
    void * pSecMappingBin;
};

typedef enum PROPTYPE {
    New_Name=0
} PROPTYPE;

typedef struct indy_resource_entry_type6 indy_resource_entry_type6, *Pindy_resource_entry_type6;

struct indy_resource_entry_type6 {
    struct indy_resource_entry entry;
    u32 data1;
    u32 data2;
};

typedef struct indy_resource_entry_type3 indy_resource_entry_type3, *Pindy_resource_entry_type3;

struct indy_resource_entry_type3 {
    struct indy_resource_entry entry;
    u8 strbuffer[255];
    u32 data;
};

typedef struct indy_resource_entry_type4 indy_resource_entry_type4, *Pindy_resource_entry_type4;

struct indy_resource_entry_type4 {
    struct indy_resource_entry entry;
    u32 data;
};

typedef struct structunknown structunknown, *Pstructunknown;

struct structunknown {
    float field_0x0;
    float field_0x4;
    float field_0x8;
};

typedef struct sfx_register_struct sfx_register_struct, *Psfx_register_struct;

struct sfx_register_struct {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;
    undefined4 field_0x10;
    undefined4 field_0x14;
};

typedef enum AMMOTYPES {
    AMMO_9MM=1,
    AMMO_9MM_2=2,
    AMMO_BOMBCASE=16,
    AMMO_BUG=20,
    AMMO_CAMERA=27,
    AMMO_DARTS=14,
    AMMO_DYNAMITE=19,
    AMMO_EXPLOSIVEPEN=15,
    AMMO_FLARE=17,
    AMMO_GEKEY=22,
    AMMO_GGUN=13,
    AMMO_GRENADE=5,
    AMMO_GRENADEROUND=11,
    AMMO_KNIFE=10,
    AMMO_MAGNUM=12,
    AMMO_MICRO_CAMERA=21,
    AMMO_PITON=18,
    AMMO_PLASTIQUE=23,
    AMMO_PROXMINE=8,
    AMMO_REMOTEMINE=7,
    AMMO_RIFLE=3,
    AMMO_ROCKETS=6,
    AMMO_SHOTGUN=4,
    AMMO_TANK=28,
    AMMO_TIMEDMINE=9,
    AMMO_TOKEN=29,
    AMMO_UNK=26,
    AMMO_WATCH_LASER=24,
    AMMO_WATCH_MAGNET=25
} AMMOTYPES;

typedef enum WEAPONID {
    CHOP=1,
    GOLDGUN=19,
    HKNIFE=2,
    New_Name=4,
    New_Name_(1)=5,
    New_Name_(10)=14,
    New_Name_(11)=15,
    New_Name_(12)=16,
    New_Name_(13)=17,
    New_Name_(14)=18,
    New_Name_(15)=20,
    New_Name_(16)=21,
    New_Name_(17)=22,
    New_Name_(18)=23,
    New_Name_(19)=24,
    New_Name_(2)=6,
    New_Name_(20)=25,
    New_Name_(21)=26,
    New_Name_(22)=27,
    New_Name_(23)=28,
    New_Name_(24)=29,
    New_Name_(25)=30,
    New_Name_(26)=31,
    New_Name_(27)=32,
    New_Name_(28)=33,
    New_Name_(29)=34,
    New_Name_(3)=7,
    New_Name_(30)=35,
    New_Name_(31)=36,
    New_Name_(32)=37,
    New_Name_(33)=38,
    New_Name_(34)=39,
    New_Name_(35)=40,
    New_Name_(36)=41,
    New_Name_(37)=42,
    New_Name_(38)=43,
    New_Name_(39)=44,
    New_Name_(4)=8,
    New_Name_(40)=45,
    New_Name_(41)=46,
    New_Name_(42)=47,
    New_Name_(43)=48,
    New_Name_(44)=49,
    New_Name_(45)=50,
    New_Name_(46)=51,
    New_Name_(47)=52,
    New_Name_(48)=53,
    New_Name_(49)=54,
    New_Name_(5)=9,
    New_Name_(50)=55,
    New_Name_(51)=56,
    New_Name_(52)=57,
    New_Name_(53)=58,
    New_Name_(54)=59,
    New_Name_(55)=60,
    New_Name_(56)=61,
    New_Name_(57)=62,
    New_Name_(58)=63,
    New_Name_(59)=64,
    New_Name_(6)=10,
    New_Name_(60)=65,
    New_Name_(61)=66,
    New_Name_(62)=67,
    New_Name_(63)=68,
    New_Name_(64)=69,
    New_Name_(65)=70,
    New_Name_(66)=71,
    New_Name_(67)=72,
    New_Name_(68)=73,
    New_Name_(69)=74,
    New_Name_(7)=11,
    New_Name_(70)=75,
    New_Name_(71)=76,
    New_Name_(72)=77,
    New_Name_(73)=78,
    New_Name_(74)=79,
    New_Name_(75)=80,
    New_Name_(76)=81,
    New_Name_(77)=82,
    New_Name_(78)=83,
    New_Name_(79)=84,
    New_Name_(8)=12,
    New_Name_(80)=85,
    New_Name_(81)=86,
    New_Name_(82)=87,
    New_Name_(9)=13,
    TKNIFE=3,
    UNARMED=0
} WEAPONID;

typedef enum CAMERAMODE {
    FADESWIRL_CAM=2,
    FP_CAM=4,
    FP_NOINPUT_CAM=8,
    INTRO_CAM=1,
    MP_CAM=9,
    POSEND_CAM=7,
    SWIRL_CAM=3,
    UNK10_CAM=10,
    UNK5_CAM=5,
    UNK6_CAM=6
} CAMERAMODE;

typedef enum COLORMODE {
    16BIT=1,
    32BIT=0
} COLORMODE;

typedef uchar uch;

typedef struct fog_element2 fog_element2, *Pfog_element2;

struct fog_element2 {
    u32 stageID;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    u16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    u16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

typedef enum enumOSEventMsg {
    PRE_NMI_MSG=669,
    RDP_DONE_MSG=668,
    RSP_DONE_MSG=667,
    VIDEO_MSG=666
} enumOSEventMsg;

typedef enum TEXTFILESTRINGS {
    "E R R O R\n"=45097,
    "\n"=45099,
    "completed\n"=45101,
    "failed\n"=45103,
    "incomplete\n"=45102,
    "no briefing for this mission\n"=45098,
    "objective"=45100
} TEXTFILESTRINGS;

typedef struct sSecondFontTableController sSecondFontTableController, *PsSecondFontTableController;

struct sSecondFontTableController {
    u8 field_0x0[20];
    u8 field_0x14[24];
    u8 field_0x2c[24];
    u8 font_second_font_table_controller_large[12912];
};

typedef ulong ulg;

typedef enum SCHEDTASKS {
    M_AUDTASK=2,
    M_GFXTASK=1,
    M_VIDTASK=3
} SCHEDTASKS;

typedef struct struct_8007ffa0_entry struct_8007ffa0_entry, *Pstruct_8007ffa0_entry;

struct struct_8007ffa0_entry {
    s32 index;
    s32 field_0x4;
    f32 field_0x8;
    f32 field_0xc;
    f32 field_0x10;
    f32 field_0x14;
    s32 field_0x18;
};

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

typedef struct sFontTableControllerLarge sFontTableControllerLarge, *PsFontTableControllerLarge;

typedef struct sFirstFontTableController sFirstFontTableController, *PsFirstFontTableController;

struct sFirstFontTableController {
    undefined1 font_first_font_table_controller_large[676];
};

struct sFontTableControllerLarge {
    struct sFirstFontTableController font_first_font_table_controller_large;
    struct sSecondFontTableController font_second_font_table_controller_large;
};

typedef ushort ush;

typedef struct headHat headHat, *PheadHat;

struct headHat {
    f32 xoffset;
    f32 yoffset;
    f32 zoffset;
    f32 xsize;
    f32 ysize;
    f32 zsize;
};

typedef enum CHEAT_IDS {
    CHEAT_05=5,
    CHEAT_ALLGUNS=3,
    CHEAT_EXTRA_MP_CHARS=1,
    CHEAT_INVINCIBILITY=2,
    CHEAT_LINEMODE=7,
    CHEAT_MAXAMMO=4,
    CHEAT_REMOVE_INVINCIBILITY=6,
    NULL=0,
    UNLOCK_CHEATS=54,
    UNLOCK_STAGES=74,
    UNUSED_17=23,
    UNUSED_1C=28,
    UNUSED_23=35,
    UNUSED_24=36,
    UNUSED_25=37,
    UNUSED_26=38,
    UNUSED_27=39,
    UNUSED_28=40,
    UNUSED_29=41,
    UNUSED_2A=42,
    UNUSED_2B=43,
    UNUSED_2C=44,
    UNUSED_2D=45,
    UNUSED_2E=46,
    UNUSED_2F=47,
    UNUSED_30=48,
    UNUSED_31=49,
    UNUSED_32=50,
    UNUSED_33=51,
    UNUSED_34=52,
    UNUSED_35=53,
    UNUSED_37=55,
    UNUSED_38=56,
    UNUSED_39=57,
    UNUSED_3A=58,
    UNUSED_3B=59,
    UNUSED_3C=60,
    UNUSED_3D=61,
    UNUSED_3E=62,
    UNUSED_3F=63,
    UNUSED_40=64,
    UNUSED_41=65,
    UNUSED_42=66,
    UNUSED_43=67,
    UNUSED_44=68,
    UNUSED_45=69,
    UNUSED_46=70,
    UNUSED_47=71,
    UNUSED_48=72,
    UNUSED_49=73,
    cheats_cheat_10x_health=16,
    cheats_cheat_2x_armor=9,
    cheats_cheat_2x_health=8,
    cheats_cheat_dk_mode=12,
    cheats_cheat_extra_weapons=13,
    cheats_cheat_fast=24,
    cheats_cheat_goldengun=19,
    cheats_cheat_goldpp7=21,
    cheats_cheat_infinite_ammo=11,
    cheats_cheat_invisibility=10,
    cheats_cheat_invisibility_mp=22,
    cheats_cheat_laser=18,
    cheats_cheat_magnum=17,
    cheats_cheat_paintball=15,
    cheats_cheat_silverpp7=20,
    cheats_cheat_tiny_bond=14,
    cheats_debug_2x_grenade_launch=30,
    cheats_debug_2x_hunting_knife=33,
    cheats_debug_2x_laser=34,
    cheats_debug_2x_rcp90=31,
    cheats_debug_2x_rockets=29,
    cheats_debug_2x_throwing_knife=32,
    cheats_debug_fast_ani=26,
    cheats_debug_pos=25,
    cheats_debug_slow_ani=27
} CHEAT_IDS;

typedef struct s_memstarts s_memstarts, *Ps_memstarts;

struct s_memstarts {
    undefined4 bank1start;
    undefined4 bank2start;
    undefined4 bank3start;
    undefined4 bank4start;
    undefined4 bank5start;
    undefined4 bank6start;
    undefined4 bank7start;
};

typedef struct s_mempMVALS s_mempMVALS, *Ps_mempMVALS;

struct s_mempMVALS {
    dword field_0x0;
    undefined4 dword_80024414;
    undefined4 mf;
    undefined4 dword_8002441C;
    undefined4 ml;
    undefined4 dword_80024424;
    undefined4 me;
    undefined4 dword_8002442C;
    undefined4 dword_80024430;
};

typedef union union_indy_resource union_indy_resource, *Punion_indy_resource;

union union_indy_resource {
    struct indy_resource_entry field0;
    struct indy_resource_entry_type3 field1;
    struct indy_resource_entry_type4 field2;
    struct indy_resource_entry_type6 field3;
};

typedef struct LnameX_name_entry LnameX_name_entry, *PLnameX_name_entry;

struct LnameX_name_entry {
    char * en_file;
    char * jp_file;
};

typedef struct playerfavoriteweapon playerfavoriteweapon, *Pplayerfavoriteweapon;

struct playerfavoriteweapon {
    u32 right;
    u32 left;
};

#define OS_TASK_SIZE 64

#define OS_TASK_OFF_UBOOT_SZ 12

#define OS_TASK_OFF_YIELD_SZ 60

#define OS_TASK_OFF_OUTBUFF 40

#define OS_TASK_OFF_DATA_SZ 52

#define OS_TASK_OFF_YIELD 56

#define OS_TASK_OFF_UCODE 16

#define OS_TASK_OFF_OUTBUFF_SZ 44

#define OS_TASK_OFF_UDATA 24

#define OS_TASK_OFF_DATA 48

#define OS_TASK_OFF_STACK_SZ 36

#define OS_TASK_OFF_UDATA_SZ 28

#define OS_TASK_OFF_UCODE_SZ 20

#define OS_TASK_OFF_FLAGS 4

#define OS_TASK_OFF_TYPE 0

#define OS_TASK_OFF_STACK 32

#define OS_TASK_OFF_UBOOT 8

#define __WORDSIZE 32

typedef uint _Sizet;

#define _D0 0

#define _NULL 0

#define _DOFF 4

#define _DBIAS 1023

#define _LONG_DOUBLE 0

#define _DLONG 0

#define _LBIAS 1023

typedef ulonglong u64;

typedef u64 vu64;

typedef longlong s64;

typedef s64 vs64;

typedef union Mtx Mtx, *PMtx;

typedef long Mtx_t[4][4];

union Mtx {
    Mtx_t m;
    longlong forc_structure_alignment;
};

typedef u16 vu16;

typedef short s16;

typedef s16 vs16;

typedef u8 vu8;

typedef char s8;

typedef s8 vs8;

typedef u32 vu32;

typedef s32 vs32;

#define FALSE 0

#define TRUE 1

#define NULL 0

typedef struct rdbPacket rdbPacket, *PrdbPacket;

typedef union anon__struct_183_bitfield_1 anon__struct_183_bitfield_1, *Panon__struct_183_bitfield_1;

union anon__struct_183_bitfield_1 {
    uint type:6; // : bits 0-5
    uint length:2; // : bits 6-7
};

struct rdbPacket {
    union anon__struct_183_bitfield_1 field_0x0;
    char buf[3];
};

#define RDB_TYPE_HtoG_KDEBUG 20

#define RDB_TYPE_GtoH_RAMROM 9

#define RDB_TYPE_GtoH_PRINT 1

#define RDB_BASE_REG 3221225472

#define RDB_TYPE_INVALID 0

#define RDB_WRITE_INTR_REG 3221225480

#define DEBUG_COMMAND_MEMORY 1

#define RDB_LOG_MAX_BLOCK_SIZE 32768

#define RDB_TYPE_HtoG_DATA 16

#define PROF_BLOCK_SIZE 2048

#define RDB_TYPE_GtoH_FAULT 2

#define DEBUG_STATE_RECEIVE 1

#define GIO_RDB_BASE_REG 3209166848

#define RDB_TYPE_GtoH_DEBUG_READY 11

#define RDB_DATA_MAX_BLOCK_SIZE 32768

#define RDB_TYPE_GtoH_KDEBUG 12

#define RDB_TYPE_GtoH_READY_FOR_DATA 5

#define RDB_TYPE_GtoH_DEBUG_DONE 10

#define RDB_TYPE_GtoH_DATA_CT 6

#define RDB_TYPE_HtoG_LOG_DONE 13

#define GIO_RDB_READ_INTR_REG 3209166860

#define RDB_BASE_VIRTUAL_ADDR 2147483648

#define DEBUG_STATE_INVALID 255

#define RDB_TYPE_GtoH_LOG_CT 3

#define RDB_PROF_FLUSH_SIG 2

#define DEBUG_STATE_NULL 0

#define RDB_READ_INTR_REG 3221225484

#define GIO_RDB_READ_INTR_BIT 1073741824

#define RDB_TYPE_HtoG_DEBUG 14

#define RDB_TYPE_GtoH_PROF_DATA 22

#define RDB_TYPE_GtoH_DATA 7

#define RDB_TYPE_GtoH_LOG 4

#define RDB_TYPE_HtoG_REQ_RAMROM 18

#define RDB_TYPE_HtoG_FREE_RAMROM 19

#define RDB_TYPE_HtoG_DEBUG_CT 15

#define DEBUG_COMMAND_NULL 0

#define RDB_PROF_ACK_SIG 1

#define GIO_RDB_DEBUG_MINOR 2

#define DEBUG_COMMAND_REGISTER 2

#define GIO_RDB_PRINT_MINOR 1

#define RDB_TYPE_HtoG_PROF_SIGNAL 21

#define DEBUG_COMMAND_INVALID 255

#define RDB_TYPE_HtoG_DATA_DONE 17

#define GIO_RDB_WRITE_INTR_BIT 2147483648

#define RDB_TYPE_GtoH_DEBUG 8

#define GIO_RDB_WRITE_INTR_REG 3209166856

typedef struct bitmap bitmap, *Pbitmap;

typedef struct bitmap Bitmap;

struct bitmap {
    s16 width;
    s16 width_img;
    s16 s;
    s16 t;
    void * buf;
    s16 actualHeight;
    s16 LUToffset;
};

typedef struct sprite sprite, *Psprite;

typedef struct sprite Sprite;

typedef union Gfx Gfx, *PGfx;

typedef struct Gwords Gwords, *PGwords;

struct sprite {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    f32 scalex;
    f32 scaley;
    s16 expx;
    s16 expy;
    u16 attr;
    s16 zdepth;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    s16 startTLUT;
    s16 nTLUT;
    int * LUT;
    s16 istart;
    s16 istep;
    s16 nbitmaps;
    s16 ndisplist;
    s16 bmheight;
    s16 bmHreal;
    u8 bmfmt;
    u8 bmsiz;
    Bitmap * bitmap;
    union Gfx * rsp_dl;
    union Gfx * rsp_dl_next;
    s16 frac_s;
    s16 frac_t;
};

struct Gwords {
    uint w0;
    uint w1;
};

union Gfx {
    struct Gwords words;
    longlong force_structure_alignment;
};

#define DL_SPRITE_OVERHEAD 24

#define SP_FASTCOPY 32

#define SP_OVERLAP 64

#define SP_CUTOUT 2

#define SP_FRACPOS 256

#define SP_TEXSHIFT 128

#define SP_EXTERN 1024

#define SP_TEXSHUF 512

#define DL_BM_OVERHEAD 12

#define SP_SCALE 16

#define SP_TRANSPARENT 1

#define SP_Z 8

#define SP_HIDDEN 4

typedef void * __gnuc_va_list;

typedef __gnuc_va_list va_list;

#define SP_DRAM_STACK_SIZE64 128

#define SP_UCODE_SIZE 4096

#define SP_DRAM_STACK_SIZE8 1024

#define SP_UCODE_DATA_SIZE 2048

typedef enum AIRCRAFT_ANIMATIONS {
    ANIM_helicopter_cradle=0,
    ANIM_helicopter_takeoff=2,
    ANIM_plane_runway=1
} AIRCRAFT_ANIMATIONS;

typedef enum LEVEL_SOLO_SEQUENCE {
    SP_LEVEL_ARCHIVES=11,
    SP_LEVEL_AZTEC=19,
    SP_LEVEL_BUNKER1=5,
    SP_LEVEL_BUNKER2=9,
    SP_LEVEL_CAVERNS=17,
    SP_LEVEL_CONTROL=16,
    SP_LEVEL_CRADLE=18,
    SP_LEVEL_DAM=1,
    SP_LEVEL_DEPOT=13,
    SP_LEVEL_EGYPT=20,
    SP_LEVEL_FACILITY=2,
    SP_LEVEL_FRIGATE=7,
    SP_LEVEL_JUNGLE=15,
    SP_LEVEL_RUNWAY=3,
    SP_LEVEL_SILO=6,
    SP_LEVEL_STATUE=10,
    SP_LEVEL_STREETS=12,
    SP_LEVEL_SURFACE1=4,
    SP_LEVEL_SURFACE2=8,
    SP_LEVEL_TRAIN=14
} LEVEL_SOLO_SEQUENCE;

typedef enum WATCH_BRIEFING_PAGE {
    BRIEFING_M=2,
    BRIEFING_MONEYPENNY=4,
    BRIEFING_OVERVIEW=1,
    BRIEFING_Q=3,
    BRIEFING_TITLE=0
} WATCH_BRIEFING_PAGE;

typedef enum MP_STAGE_SELECTED {
    MP_STAGE_ARCHIVES=9,
    MP_STAGE_BASEMENT=5,
    MP_STAGE_BUNKER=8,
    MP_STAGE_CAVERNS=10,
    MP_STAGE_CAVES=3,
    MP_STAGE_COMPLEX=2,
    MP_STAGE_EGYPT=11,
    MP_STAGE_FACILITY=7,
    MP_STAGE_LIBRARY=4,
    MP_STAGE_RANDOM=0,
    MP_STAGE_STACK=6,
    MP_STAGE_TEMPLE=1
} MP_STAGE_SELECTED;

typedef enum CONTROLLER_CONFIG {
    CONTROLLER_CONFIG_CINEMA=8,
    CONTROLLER_CONFIG_DOMINO=6,
    CONTROLLER_CONFIG_GALORE=5,
    CONTROLLER_CONFIG_GOODHEAD=7,
    CONTROLLER_CONFIG_GOODNIGHT=3,
    CONTROLLER_CONFIG_HONEY=0,
    CONTROLLER_CONFIG_KISSY=2,
    CONTROLLER_CONFIG_PLENTY=4,
    CONTROLLER_CONFIG_SOLITARE=1
} CONTROLLER_CONFIG;

typedef struct rgba_val rgba_val, *Prgba_val;

struct rgba_val {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

typedef enum MISSION_BRIEFING {
    BRIEF_M=1,
    BRIEF_MONEYPENNY=3,
    BRIEF_OVERVIEW=0,
    BRIEF_Q=2
} MISSION_BRIEFING;

typedef enum PROPS {
    PROP_ICBM=93,
    PROP_ICBM_nose=92,
    PROP_ak47mag=121,
    PROP_alarm1=0,
    PROP_alarm2=1,
    PROP_ammo_crate1=3,
    PROP_ammo_crate2=4,
    PROP_ammo_crate3=5,
    PROP_ammo_crate4=6,
    PROP_ammo_crate5=7,
    PROP_apc=289,
    PROP_archsecdoor1=297,
    PROP_archsecdoor2=298,
    PROP_artic=281,
    PROP_artictrailer=286,
    PROP_barricade=334,
    PROP_bin1=8,
    PROP_blotter1=9,
    PROP_bodyarmour=115,
    PROP_bodyarmourvest=116,
    PROP_bollard=339,
    PROP_bomb=255,
    PROP_book1=10,
    PROP_bookshelf1=11,
    PROP_borg_crate=87,
    PROP_boxcartridges=129,
    PROP_boxes2x4=90,
    PROP_boxes3x4=89,
    PROP_boxes4x4=88,
    PROP_brakeunit=120,
    PROP_bridge_console1a=12,
    PROP_bridge_console1b=13,
    PROP_bridge_console2a=14,
    PROP_bridge_console2b=15,
    PROP_bridge_console3a=16,
    PROP_bridge_console3b=17,
    PROP_carbmw=301,
    PROP_card_box1=18,
    PROP_card_box2=19,
    PROP_card_box3=20,
    PROP_card_box4_lg=21,
    PROP_card_box5_lg=22,
    PROP_card_box6_lg=23,
    PROP_carescort=302,
    PROP_cargolf=303,
    PROP_carweird=304,
    PROP_carzil=305,
    PROP_cctv=24,
    PROP_chraudiotape=262,
    PROP_chrautoshot=207,
    PROP_chrblackbox=274,
    PROP_chrblueprints=258,
    PROP_chrbombcase=226,
    PROP_chrbombdefuser=235,
    PROP_chrbriefcase=198,
    PROP_chrbug=245,
    PROP_chrbugdetector=236,
    PROP_chrbungee=233,
    PROP_chrcamera=238,
    PROP_chrcircuitboard=259,
    PROP_chrclipboard=269,
    PROP_chrcreditcard=250,
    PROP_chrdarkglasses=251,
    PROP_chrdatathief=253,
    PROP_chrdattape=272,
    PROP_chrdoordecoder=234,
    PROP_chrdoorexploder=240,
    PROP_chrdossierred=270,
    PROP_chrdynamite=232,
    PROP_chrexplosivepen=225,
    PROP_chrextinguisher=128,
    PROP_chrfingergun=229,
    PROP_chrflarepistol=227,
    PROP_chrfnp90=197,
    PROP_chrgaskeyring=252,
    PROP_chrgoldbar=267,
    PROP_chrgolden=208,
    PROP_chrgoldeneyekey=248,
    PROP_chrgoldwppk=231,
    PROP_chrgrenade=196,
    PROP_chrgrenadelaunch=185,
    PROP_chrgrenaderound=203,
    PROP_chrheroin=268,
    PROP_chrkalash=184,
    PROP_chrkeyanalysercase=241,
    PROP_chrkeybolt=244,
    PROP_chrkeyyale=243,
    PROP_chrknife=186,
    PROP_chrlaser=187,
    PROP_chrlectre=265,
    PROP_chrlockexploder=239,
    PROP_chrm16=188,
    PROP_chrmap=260,
    PROP_chrmicrocamera=246,
    PROP_chrmicrocode=264,
    PROP_chrmicrofilm=263,
    PROP_chrmoney=266,
    PROP_chrmp5k=189,
    PROP_chrmp5ksil=206,
    PROP_chrpitongun=228,
    PROP_chrplans=256,
    PROP_chrplastique=273,
    PROP_chrpolarizedglasses=249,
    PROP_chrproximitymine=200,
    PROP_chrremotemine=199,
    PROP_chrrocket=202,
    PROP_chrrocketlaunch=211,
    PROP_chrruger=190,
    PROP_chrsafecrackercase=237,
    PROP_chrshotgun=192,
    PROP_chrsilverwppk=230,
    PROP_chrskorpion=193,
    PROP_chrsniperrifle=210,
    PROP_chrspectre=194,
    PROP_chrspooltape=261,
    PROP_chrspyfile=257,
    PROP_chrstafflist=271,
    PROP_chrtesttube=338,
    PROP_chrthrowknife=209,
    PROP_chrtimedmine=201,
    PROP_chrtt33=205,
    PROP_chruzi=195,
    PROP_chrvideotape=275,
    PROP_chrweaponcase=242,
    PROP_chrwppk=191,
    PROP_chrwppksil=204,
    PROP_chrwristdart=224,
    PROP_console1=25,
    PROP_console2=26,
    PROP_console3=27,
    PROP_console_sev2a=32,
    PROP_console_sev2b=33,
    PROP_console_sev2c=34,
    PROP_console_sev2d=35,
    PROP_console_sev_GEa=36,
    PROP_console_sev_GEb=37,
    PROP_console_seva=28,
    PROP_console_sevb=29,
    PROP_console_sevc=30,
    PROP_console_sevd=31,
    PROP_cryptdoor1a=170,
    PROP_cryptdoor1b=171,
    PROP_cryptdoor2a=172,
    PROP_cryptdoor2b=173,
    PROP_cryptdoor3=174,
    PROP_cryptdoor4=175,
    PROP_damchaindoor=180,
    PROP_damgatedoor=178,
    PROP_damtundoor=179,
    PROP_depot_door_steel=309,
    PROP_depot_gate_entry=308,
    PROP_desk1=38,
    PROP_desk2=39,
    PROP_desk_arecibo1=95,
    PROP_desk_lamp2=40,
    PROP_dest_engine=99,
    PROP_dest_exocet=100,
    PROP_dest_gun=101,
    PROP_dest_harpoon=102,
    PROP_dest_seawolf=103,
    PROP_disc_reader=41,
    PROP_disk_drive1=42,
    PROP_door_azt_chair=331,
    PROP_door_azt_desk=329,
    PROP_door_azt_desk_top=330,
    PROP_door_aztec=327,
    PROP_door_dest1=152,
    PROP_door_dest2=153,
    PROP_door_eyelid=164,
    PROP_door_iris=165,
    PROP_door_mf=332,
    PROP_door_roller1=146,
    PROP_door_roller2=147,
    PROP_door_roller3=148,
    PROP_door_roller4=149,
    PROP_door_rollertrain=325,
    PROP_door_st_arec1=150,
    PROP_door_st_arec2=151,
    PROP_door_win=326,
    PROP_doorconsole=337,
    PROP_doorpanel=336,
    PROP_doorprison1=182,
    PROP_doorstatgate=183,
    PROP_explosionbit=2,
    PROP_filing_cabinet1=43,
    PROP_flag=333,
    PROP_floppy=247,
    PROP_fnp90mag=130,
    PROP_gas_plant_met1_do1=158,
    PROP_gas_plant_sw2_do1=155,
    PROP_gas_plant_sw3_do1=156,
    PROP_gas_plant_sw4_do1=157,
    PROP_gas_plant_sw_do1=154,
    PROP_gas_plant_wc_cub1=159,
    PROP_gasbarrel=113,
    PROP_gasbarrels=114,
    PROP_gasplant_clear_door=160,
    PROP_gastank=117,
    PROP_glassware1=118,
    PROP_glassware2=310,
    PROP_glassware3=311,
    PROP_glassware4=312,
    PROP_goldeneyelogo=277,
    PROP_goldenshells=131,
    PROP_groundgun=299,
    PROP_gun_runway1=292,
    PROP_hatberet=220,
    PROP_hatberetblue=221,
    PROP_hatberetred=222,
    PROP_hatchbolt=119,
    PROP_hatchdoor=177,
    PROP_hatchsevx=295,
    PROP_hatfurry=212,
    PROP_hatfurryblack=214,
    PROP_hatfurrybrown=213,
    PROP_hathelmet=217,
    PROP_hathelmetgrey=218,
    PROP_hatmoon=219,
    PROP_hatpeaked=223,
    PROP_hattbird=215,
    PROP_hattbirdbrown=216,
    PROP_helicopter=282,
    PROP_hind=285,
    PROP_jeep=280,
    PROP_jerry_can1=44,
    PROP_jungle3_tree=108,
    PROP_jungle5_tree=318,
    PROP_key_holder=294,
    PROP_keyboard1=45,
    PROP_kit_units1=46,
    PROP_labbench=112,
    PROP_landmine=313,
    PROP_legalpage=319,
    PROP_letter_tray1=47,
    PROP_locker3=96,
    PROP_locker4=97,
    PROP_m16mag=122,
    PROP_magnumshells=132,
    PROP_mainframe1=48,
    PROP_mainframe2=49,
    PROP_metal_chair1=50,
    PROP_metal_crate1=51,
    PROP_metal_crate2=52,
    PROP_metal_crate3=53,
    PROP_metal_crate4=54,
    PROP_milcopter=284,
    PROP_miltruck=279,
    PROP_missile_rack=55,
    PROP_missile_rack2=56,
    PROP_modembox=335,
    PROP_motorbike=287,
    PROP_mp5kmag=123,
    PROP_nintendologo=276,
    PROP_oil_drum1=57,
    PROP_oil_drum2=58,
    PROP_oil_drum3=59,
    PROP_oil_drum5=60,
    PROP_oil_drum6=61,
    PROP_oil_drum7=62,
    PROP_padlock=63,
    PROP_palm=109,
    PROP_palmtree=110,
    PROP_phone1=64,
    PROP_plane=291,
    PROP_plant1=314,
    PROP_plant11=315,
    PROP_plant2=316,
    PROP_plant2b=111,
    PROP_plant3=317,
    PROP_radio_unit1=65,
    PROP_radio_unit2=66,
    PROP_radio_unit3=67,
    PROP_radio_unit4=68,
    PROP_roofgun=98,
    PROP_safe=254,
    PROP_safedoor=293,
    PROP_sat1_reflect=69,
    PROP_satbox=71,
    PROP_satdish=70,
    PROP_sec_panel=91,
    PROP_sev_door=135,
    PROP_sev_door3=136,
    PROP_sev_door3_wind=137,
    PROP_sev_door4_wind=138,
    PROP_sev_door_v1=140,
    PROP_sev_trislide=139,
    PROP_sevdish=296,
    PROP_sevdoormetslide=169,
    PROP_sevdoornowind=168,
    PROP_sevdoorwind=167,
    PROP_sevdoorwood=166,
    PROP_shuttle=328,
    PROP_shuttle_door_l=306,
    PROP_shuttle_door_r=307,
    PROP_silencer=127,
    PROP_silo_lift_door=144,
    PROP_silotopdoor=181,
    PROP_skorpionmag=124,
    PROP_spectremag=125,
    PROP_speedboat=290,
    PROP_st_pete_room_1i=320,
    PROP_st_pete_room_2i=321,
    PROP_st_pete_room_3t=322,
    PROP_st_pete_room_5c=323,
    PROP_st_pete_room_6c=324,
    PROP_steel_door1=141,
    PROP_steel_door2=142,
    PROP_steel_door2b=145,
    PROP_steel_door3=143,
    PROP_stool1=72,
    PROP_swipe_card2=86,
    PROP_swivel_chair1=73,
    PROP_tank=288,
    PROP_tiger=283,
    PROP_torpedo_rack=74,
    PROP_train_door=161,
    PROP_train_door2=162,
    PROP_train_door3=163,
    PROP_trainextdoor=300,
    PROP_tt33mag=134,
    PROP_tuning_console1=94,
    PROP_tv1=75,
    PROP_tv4screen=78,
    PROP_tv_holder=76,
    PROP_tvscreen=77,
    PROP_uzimag=126,
    PROP_vertdoor=176,
    PROP_walletbond=278,
    PROP_window=104,
    PROP_window_cor11=107,
    PROP_window_lib_lg1=105,
    PROP_window_lib_sm1=106,
    PROP_wood_lg_crate1=79,
    PROP_wood_lg_crate2=80,
    PROP_wood_md_crate3=81,
    PROP_wood_sm_crate4=82,
    PROP_wood_sm_crate5=83,
    PROP_wood_sm_crate6=84,
    PROP_wooden_table1=85,
    PROP_wppkmag=133
} PROPS;

typedef enum ANIMATIONS {
    ANIM_adjusting_crotch=158,
    ANIM_aim_and_blow_one_handed_weapon=149,
    ANIM_aim_one_handed_weapon_left=150,
    ANIM_aim_one_handed_weapon_left_right=99,
    ANIM_aim_one_handed_weapon_right=151,
    ANIM_aim_running_left_one_handed_weapon=87,
    ANIM_aim_running_one_handed_weapon=85,
    ANIM_aim_running_right_one_handed_weapon=86,
    ANIM_aim_sprinting_one_handed_weapon=88,
    ANIM_aim_walking_left_one_handed_weapon=83,
    ANIM_aim_walking_one_handed_weapon=82,
    ANIM_aim_walking_right_one_handed_weapon=84,
    ANIM_bond_eye_fire=44,
    ANIM_bond_eye_fire_alt=176,
    ANIM_bond_eye_walk=43,
    ANIM_bond_watch=45,
    ANIM_cock_one_handed_weapon_and_turn_around=100,
    ANIM_cock_one_handed_weapon_turn_around_and_stand_up=102,
    ANIM_conversation=152,
    ANIM_conversation_cleaned=160,
    ANIM_conversation_listener=161,
    ANIM_coughing_kneel1=166,
    ANIM_coughing_kneel2=167,
    ANIM_coughing_standing=165,
    ANIM_cradle_fall=180,
    ANIM_cradle_jump=179,
    ANIM_credits_bond_kissing=181,
    ANIM_credits_natalya_kissing=182,
    ANIM_dam_jump=177,
    ANIM_dancing=170,
    ANIM_dancing_one_handed_weapon=171,
    ANIM_death_backward_fall_face_up1=28,
    ANIM_death_backward_fall_face_up2=37,
    ANIM_death_backward_spin_face_down_left=31,
    ANIM_death_backward_spin_face_down_right=29,
    ANIM_death_backward_spin_face_up_left=32,
    ANIM_death_backward_spin_face_up_right=30,
    ANIM_death_explosion_back1=133,
    ANIM_death_explosion_back2=136,
    ANIM_death_explosion_back_left=132,
    ANIM_death_explosion_forward=130,
    ANIM_death_explosion_forward_face_down=138,
    ANIM_death_explosion_forward_right1=135,
    ANIM_death_explosion_forward_right2=140,
    ANIM_death_explosion_forward_right2_alt=141,
    ANIM_death_explosion_forward_right3=142,
    ANIM_death_explosion_forward_roll=137,
    ANIM_death_explosion_left1=131,
    ANIM_death_explosion_left2=139,
    ANIM_death_explosion_right=134,
    ANIM_death_fetal_position_left=36,
    ANIM_death_fetal_position_right=35,
    ANIM_death_forward_face_down=26,
    ANIM_death_forward_face_down_hard=33,
    ANIM_death_forward_face_down_soft=34,
    ANIM_death_forward_spin_face_up=27,
    ANIM_death_genitalia=22,
    ANIM_death_head=56,
    ANIM_death_left_leg=57,
    ANIM_death_neck=24,
    ANIM_death_stagger_back_to_wall=25,
    ANIM_draw_one_handed_weapon_and_look_around=97,
    ANIM_draw_one_handed_weapon_and_stand_up=98,
    ANIM_draw_one_handed_weapon_and_turn_around=103,
    ANIM_drop_weapon_and_show_fight_stance=153,
    ANIM_extending_left_hand=61,
    ANIM_fire_hip=3,
    ANIM_fire_hip_forward_one_handed_weapon=70,
    ANIM_fire_hip_one_handed_weapon_fast=68,
    ANIM_fire_hip_one_handed_weapon_slow=69,
    ANIM_fire_jump_to_side_left=52,
    ANIM_fire_jump_to_side_right=53,
    ANIM_fire_kneel_aiming_down_sights=128,
    ANIM_fire_kneel_dual_wield=116,
    ANIM_fire_kneel_dual_wield_hands_crossed=119,
    ANIM_fire_kneel_dual_wield_hands_crossed_left=120,
    ANIM_fire_kneel_dual_wield_hands_crossed_right=121,
    ANIM_fire_kneel_dual_wield_left=117,
    ANIM_fire_kneel_dual_wield_right=118,
    ANIM_fire_kneel_forward_one_handed_weapon_fast=76,
    ANIM_fire_kneel_forward_one_handed_weapon_slow=75,
    ANIM_fire_kneel_left=9,
    ANIM_fire_kneel_left_leg=8,
    ANIM_fire_kneel_left_one_handed_weapon=81,
    ANIM_fire_kneel_left_one_handed_weapon_fast=80,
    ANIM_fire_kneel_left_one_handed_weapon_slow=79,
    ANIM_fire_kneel_right=10,
    ANIM_fire_kneel_right_leg=7,
    ANIM_fire_kneel_right_one_handed_weapon_fast=78,
    ANIM_fire_kneel_right_one_handed_weapon_slow=77,
    ANIM_fire_roll_left=11,
    ANIM_fire_roll_left_fast=13,
    ANIM_fire_roll_right1=12,
    ANIM_fire_roll_right2=39,
    ANIM_fire_running=49,
    ANIM_fire_running_dual_wield=110,
    ANIM_fire_running_dual_wield_hands_crossed=111,
    ANIM_fire_shoulder_left=4,
    ANIM_fire_sprinting_dual_wield=112,
    ANIM_fire_sprinting_dual_wield_hands_crossed=113,
    ANIM_fire_standing=1,
    ANIM_fire_standing_aiming_down_sights=127,
    ANIM_fire_standing_draw_one_handed_weapon_fast=66,
    ANIM_fire_standing_draw_one_handed_weapon_slow=67,
    ANIM_fire_standing_dual_wield=122,
    ANIM_fire_standing_dual_wield_hands_crossed_left=125,
    ANIM_fire_standing_dual_wield_hands_crossed_right=126,
    ANIM_fire_standing_dual_wield_left=123,
    ANIM_fire_standing_dual_wield_right=124,
    ANIM_fire_standing_fast=2,
    ANIM_fire_standing_left_one_handed_weapon_fast=74,
    ANIM_fire_standing_left_one_handed_weapon_slow=73,
    ANIM_fire_standing_one_handed_weapon=65,
    ANIM_fire_standing_right_one_handed_weapon=71,
    ANIM_fire_step_right_one_handed_weapon=72,
    ANIM_fire_throw_grenade=62,
    ANIM_fire_turn_right1=5,
    ANIM_fire_turn_right2=6,
    ANIM_fire_walking=48,
    ANIM_fire_walking_dual_wield=108,
    ANIM_fire_walking_dual_wield_hands_crossed=109,
    ANIM_hit_butt_long=54,
    ANIM_hit_butt_short=55,
    ANIM_hit_left_arm=16,
    ANIM_hit_left_hand=18,
    ANIM_hit_left_leg=20,
    ANIM_hit_left_shoulder=14,
    ANIM_hit_neck=23,
    ANIM_hit_right_arm=17,
    ANIM_hit_right_hand=19,
    ANIM_hit_right_leg=21,
    ANIM_hit_right_shoulder=15,
    ANIM_hit_taser=129,
    ANIM_holster_one_handed_weapon_and_adjust_suit=105,
    ANIM_holster_one_handed_weapon_and_cross_arms=101,
    ANIM_idle=0,
    ANIM_idle_unarmed=106,
    ANIM_jogging_one_handed_weapon=89,
    ANIM_jump_backwards=60,
    ANIM_keyboard_left_hand=174,
    ANIM_keyboard_right_hand1=172,
    ANIM_keyboard_right_hand2=173,
    ANIM_keyboard_right_hand_tapping=175,
    ANIM_laughing_in_disbelief=163,
    ANIM_look_around=64,
    ANIM_null143=143,
    ANIM_null144=144,
    ANIM_null145=145,
    ANIM_null146=146,
    ANIM_null169=169,
    ANIM_null50=50,
    ANIM_null51=51,
    ANIM_null91=91,
    ANIM_null92=92,
    ANIM_null93=93,
    ANIM_null94=94,
    ANIM_null95=95,
    ANIM_null96=96,
    ANIM_running=42,
    ANIM_running_female=115,
    ANIM_running_hands_up=147,
    ANIM_scratching_butt=157,
    ANIM_scratching_leg=156,
    ANIM_side_step_left=38,
    ANIM_slide_left=59,
    ANIM_slide_right=58,
    ANIM_sneeze=159,
    ANIM_spotting_bond=63,
    ANIM_sprinting=41,
    ANIM_sprinting_hands_up=148,
    ANIM_sprinting_one_handed_weapon=90,
    ANIM_standing_up=168,
    ANIM_startled_and_looking_around=162,
    ANIM_step_foward_and_hold_one_handed_weapon=104,
    ANIM_surface_vent_jump=178,
    ANIM_surrendering_armed=46,
    ANIM_surrendering_armed_drop_weapon=47,
    ANIM_surrendering_unarmed=164,
    ANIM_swatting_flies=155,
    ANIM_walking=40,
    ANIM_walking_female=114,
    ANIM_walking_unarmed=107,
    ANIM_yawning=154
} ANIMATIONS;


// WARNING! conflicting data type names: /bondgame.h/COLORMODE - /COLORMODE

typedef enum PROJECTILES {
    PROJECTILES_MAX=46,
    PROJECTILES_TYPE_BOMBCASE=55,
    PROJECTILES_TYPE_BUG=56,
    PROJECTILES_TYPE_GE_KEY=58,
    PROJECTILES_TYPE_GLAUNCH_ROUND=54,
    PROJECTILES_TYPE_GRENADE=48,
    PROJECTILES_TYPE_KNIFE=47,
    PROJECTILES_TYPE_MICROCAMERA=57,
    PROJECTILES_TYPE_PLASTIQUE=59,
    PROJECTILES_TYPE_PROX_MINE=50,
    PROJECTILES_TYPE_REMOTE_MINE=49,
    PROJECTILES_TYPE_ROCKET_ROUND=52,
    PROJECTILES_TYPE_ROCKET_ROUND2=53,
    PROJECTILES_TYPE_TIMED_MINE=51
} PROJECTILES;

typedef enum GENDER {
    FEMALE=0,
    MALE=1
} GENDER;

typedef enum BODIES {
    BODY_Arctic_Commando=38,
    BODY_Baron_Samedi=12,
    BODY_Boris=6,
    BODY_Civilian_1_Female=29,
    BODY_Civilian_2=33,
    BODY_Civilian_3=34,
    BODY_Civilian_4=32,
    BODY_Female_Mandy=72,
    BODY_Female_Marion_Rosika=71,
    BODY_Female_Sally=70,
    BODY_Female_Vivien=73,
    BODY_Formal_Wear=23,
    BODY_Helicopter_Pilot=36,
    BODY_Janus_Marine=17,
    BODY_Janus_Special_Forces=4,
    BODY_Jaws=13,
    BODY_Jungle_Commando=0,
    BODY_Jungle_Fatigues=24,
    BODY_Left_Suit_Hand_Floating_Arm=41,
    BODY_Male_Alan=43,
    BODY_Male_B=50,
    BODY_Male_Biker=61,
    BODY_Male_Chris=54,
    BODY_Male_Dave_Dr_Doak=51,
    BODY_Male_Des=53,
    BODY_Male_Duncan=47,
    BODY_Male_Dwayne=49,
    BODY_Male_Graeme=62,
    BODY_Male_Grant=52,
    BODY_Male_Jim=57,
    BODY_Male_Joe=68,
    BODY_Male_Joe_Altered=66,
    BODY_Male_Joel=64,
    BODY_Male_Karl=42,
    BODY_Male_Ken=67,
    BODY_Male_Lee=55,
    BODY_Male_Mark=46,
    BODY_Male_Martin=45,
    BODY_Male_Mishkin=69,
    BODY_Male_Neil=56,
    BODY_Male_Pete=44,
    BODY_Male_Pierce_Bond_1=74,
    BODY_Male_Pierce_Bond_2=75,
    BODY_Male_Pierce_Bond_3=76,
    BODY_Male_Pierce_Bond_Parka=77,
    BODY_Male_Pierce_Bond_Tuxedo=78,
    BODY_Male_Robin=58,
    BODY_Male_Scott=65,
    BODY_Male_Shaun=48,
    BODY_Male_Steve_Ellis=63,
    BODY_Male_Steve_H=59,
    BODY_Male_Terrorist=60,
    BODY_Mayday=14,
    BODY_Moonraker_Elite_1_Male=39,
    BODY_Moonraker_Elite_2_Female=40,
    BODY_Natalya_Jungle_Fatigues=79,
    BODY_Natalya_Skirt=16,
    BODY_Naval_Officer=20,
    BODY_Oddjob=15,
    BODY_Ourumov=7,
    BODY_Parka=25,
    BODY_Rosika=27,
    BODY_Russian_Commandant=18,
    BODY_Russian_Infantry=3,
    BODY_Russian_Soldier=2,
    BODY_Scientist_1_Male=35,
    BODY_Scientist_2_Female=28,
    BODY_Siberian_Guard_1_Mishkin=19,
    BODY_Siberian_Guard_2=37,
    BODY_Siberian_Special_Forces=21,
    BODY_Special_Operations_Uniform=22,
    BODY_St_Petersburg_Guard=1,
    BODY_Trevelyan_006=9,
    BODY_Trevelyan_Janus=8,
    BODY_Tuxedo=5,
    BODY_Unused_Female=26,
    BODY_Unused_Male_1=30,
    BODY_Unused_Male_2=31,
    BODY_Valentin_=10,
    BODY_Xenia=11
} BODIES;

typedef enum TEXTBANK_LEVEL_INDEX {
    LAME=1,
    LARCH=2,
    LAREC=8,
    LARK=3,
    LASH=4,
    LAZT=5,
    LCAT=6,
    LCAVE=7,
    LCRAD=9,
    LCRYP=10,
    LDAM=11,
    LDEPO=12,
    LDEST=13,
    LDISH=14,
    LEAR=15,
    LELD=16,
    LGUN=38,
    LIMP=17,
    LJUN=18,
    LLEE=19,
    LLEN=20,
    LLIP=21,
    LLUE=22,
    LMISC=44,
    LMPMENU=40,
    LMPWEAPONS=42,
    LNULL=0,
    LOAT=23,
    LOPTIONS=43,
    LPAM=24,
    LPETE=25,
    LPROPOBJ=41,
    LREF=26,
    LRIT=27,
    LRUN=28,
    LSEV=30,
    LSEVB=29,
    LSEVX=31,
    LSEVXB=32,
    LSHO=33,
    LSILO=34,
    LSTAT=35,
    LTITLE=39,
    LTRA=36,
    LWAX=37
} TEXTBANK_LEVEL_INDEX;

typedef enum DOORSTATE {
    CLOSED=2,
    OPEN=1
} DOORSTATE;

typedef enum HEADS {
    HEAD_Female_Mandy=72,
    HEAD_Female_Marion_Rosika=71,
    HEAD_Female_Sally=70,
    HEAD_Female_Vivien=73,
    HEAD_Male_Alan=43,
    HEAD_Male_B=50,
    HEAD_Male_Biker=61,
    HEAD_Male_Chris=54,
    HEAD_Male_Dave_Dr_Doak=51,
    HEAD_Male_Des=53,
    HEAD_Male_Duncan=47,
    HEAD_Male_Dwayne=49,
    HEAD_Male_Graeme=62,
    HEAD_Male_Grant=52,
    HEAD_Male_Jim=57,
    HEAD_Male_Joe=68,
    HEAD_Male_Joe_Altered=66,
    HEAD_Male_Joel=64,
    HEAD_Male_Karl=42,
    HEAD_Male_Ken=67,
    HEAD_Male_Lee=55,
    HEAD_Male_Mark=46,
    HEAD_Male_Martin=45,
    HEAD_Male_Mishkin=69,
    HEAD_Male_Neil=56,
    HEAD_Male_Pete=44,
    HEAD_Male_Pierce_Bond_1=74,
    HEAD_Male_Pierce_Bond_2=75,
    HEAD_Male_Pierce_Bond_3=76,
    HEAD_Male_Pierce_Bond_Parka=77,
    HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT=78,
    HEAD_Male_Robin=58,
    HEAD_Male_Scott=65,
    HEAD_Male_Shaun=48,
    HEAD_Male_Steve_Ellis=63,
    HEAD_Male_Steve_H=59,
    HEAD_Male_Terrorist=60,
    HEAD_Natalya_Jungle_Fatigues=79
} HEADS;

typedef enum mission_setup_type {
    MISSION_HEADER=1,
    MISSION_PART=0
} mission_setup_type;

typedef enum LEVEL_INDEX {
    LEVEL_INDEX_AME=28,
    LEVEL_INDEX_ARCH=4,
    LEVEL_INDEX_ARK=14,
    LEVEL_INDEX_ASH=26,
    LEVEL_INDEX_AZT=8,
    LEVEL_INDEX_CAT=20,
    LEVEL_INDEX_CAVE=19,
    LEVEL_INDEX_CONTROL=3,
    LEVEL_INDEX_CRAD=21,
    LEVEL_INDEX_CRYP=12,
    LEVEL_INDEX_DAM=13,
    LEVEL_INDEX_DEPO=10,
    LEVEL_INDEX_DEST=6,
    LEVEL_INDEX_DISH=18,
    LEVEL_INDEX_EAR=31,
    LEVEL_INDEX_ELD=24,
    LEVEL_INDEX_IMP=25,
    LEVEL_INDEX_JUN=17,
    LEVEL_INDEX_LEE=32,
    LEVEL_INDEX_LEN=34,
    LEVEL_INDEX_LIP=33,
    LEVEL_INDEX_LUE=27,
    LEVEL_INDEX_OAT=30,
    LEVEL_INDEX_PAM=36,
    LEVEL_INDEX_PETE=9,
    LEVEL_INDEX_REF=11,
    LEVEL_INDEX_RIT=29,
    LEVEL_INDEX_RUN=15,
    LEVEL_INDEX_SEVB=7,
    LEVEL_INDEX_SEVBUNKER=0,
    LEVEL_INDEX_SEVX=16,
    LEVEL_INDEX_SEVXB=23,
    LEVEL_INDEX_SHO=22,
    LEVEL_INDEX_SILO=1,
    LEVEL_INDEX_STATUE=2,
    LEVEL_INDEX_TRA=5,
    LEVEL_INDEX_WAX=35,
    LEVEL_INDEX_X=37
} LEVEL_INDEX;

typedef enum SCREEN_SIZE {
    SCREEN_SIZE_320x240=0,
    SCREEN_SIZE_440x330=1
} SCREEN_SIZE;

typedef u16 PAD;

typedef enum MENU {
    MENU_007_OPTIONS=9,
    MENU_BRIEFING=10,
    MENU_CHEAT=21,
    MENU_DIFFICULTY=8,
    MENU_DISPLAY_CAST=24,
    MENU_EYE_INTRO=3,
    MENU_FILE_SELECT=5,
    MENU_GOLDENEYE_LOGO=4,
    MENU_LEGAL_SCREEN=0,
    MENU_MISSION_COMPLETE=13,
    MENU_MISSION_FAILED=12,
    MENU_MISSION_SELECT=7,
    MENU_MODE_SELECT=6,
    MENU_MP_CHAR_SELECT=15,
    MENU_MP_CONTROL_STYLE=17,
    MENU_MP_HANDICAP=16,
    MENU_MP_OPTIONS=14,
    MENU_MP_SCENARIO_SELECT=19,
    MENU_MP_STAGE_SELECT=18,
    MENU_MP_TEAMS=20,
    MENU_NINTENDO_LOGO=1,
    MENU_NO_CONTROLLERS=22,
    MENU_RAREWARE_LOGO=2,
    MENU_RUN_STAGE=11,
    MENU_SPECTRUM_EMU=25,
    MENU_SWITCH_SCREENS=23
} MENU;

#define OBJECTIVES_MAX 10


// WARNING! conflicting data type names: /bondconstants.h/ITEM_IDS - /bondgame.h/ITEM_IDS

typedef u16 PADEXTRA;

typedef enum IMAGE_BITDEPTH {
    D_16BIT=2,
    D_32BIT=3,
    D_4BIT=0,
    D_8BIT=1
} IMAGE_BITDEPTH;

typedef enum CM_FLAGS {
    CLAMP=1,
    MIRROR=2
} CM_FLAGS;

typedef enum RGBA_ENUM {
    ALPHA=3,
    BLUE=2,
    GREEN=1,
    RED=0
} RGBA_ENUM;

typedef enum ACT_TYPE {
    ACT_ANIM=3,
    ACT_ARGH=6,
    ACT_ATTACK=8,
    ACT_ATTACKROLL=10,
    ACT_ATTACKWALK=9,
    ACT_DEAD=5,
    ACT_DIE=4,
    ACT_GOPOS=15,
    ACT_INIT=0,
    ACT_JUMPOUT=12,
    ACT_KNEEL=2,
    ACT_LOOKATTARGET=17,
    ACT_NULL=23,
    ACT_PATROL=14,
    ACT_PREARGH=7,
    ACT_RUNPOS=13,
    ACT_SIDESTEP=11,
    ACT_STAND=1,
    ACT_STARTALARM=19,
    ACT_SURPRISED=18,
    ACT_SURRENDER=16,
    ACT_TEST=22,
    ACT_THROWGRENADE=20,
    ACT_TURNDIR=21
} ACT_TYPE;

typedef enum HANDEDNESS {
    LEFT_HAND=1,
    RIGHT_HAND=0
} HANDEDNESS;


// WARNING! conflicting data type names: /bondconstants.h/ANIMATIONS - /bondgame.h/ANIMATIONS


// WARNING! conflicting data type names: /bondconstants.h/COLORMODE - /COLORMODE

typedef enum IMAGE_FORMAT {
    F_CI=2,
    F_I=4,
    F_IA=3,
    F_RGBA=0,
    F_YUV=1
} IMAGE_FORMAT;

#define DOOR_LOCK_0 1

#define PROPFLAG2_00800000 8388608

#define CHR_FREE -1

#define DOOR_LOCK_2 4

#define DOOR_LOCK_1 2

#define DOOR_LOCK_4 16

#define DOOR_LOCK_3 8

#define DOOR_LOCK_6 64

#define CHR_BOND_CINEMA -8

#define DOOR_LOCK_5 32

#define PROPFLAG_00100000 1048576

#define CHRFLAG_NO_AUTOAIM 2048

#define CHRFLAG_CULL_USING_HITBOX 8388608

#define DOOR_LOCK_7 128

#define PROPFLAG_00020000 131072

#define PROPFLAG_00000400 1024

#define PROPFLAG2_00004000 16384

#define CHRFLAG_NO_SHADOW 8192

#define PROPFLAG_00000080 128

#define PROPFLAG_00008000 32768

#define PROPFLAG2_00000400 1024

#define PROPFLAG2_00400000 4194304

#define CHRFLAG_COUNT_DEATH_AS_CIVILIAN 1048576

#define PAD_PRESET 9000

#define CHR_PRESET -4

#define PROPFLAG2_00020000 131072

#define PROPFLAG_00002000 8192

#define PROPFLAG_10000000 268435456

#define CHRFLAG_INVINCIBLE 16

#define CHR_SEE_DIE -5

#define CHRFLAG_HIDDEN 1024

#define PROPFLAG_00010000 65536

#define PROPFLAG2_08000000 134217728

#define PROPFLAG2_00000100 256

#define CHRFLAG_00000004 4

#define CHRFLAG_00000001 1

#define CHRFLAG_10000000 268435456

#define PROPFLAG2_80000000 2147483648

#define CHRFLAG_80000000 2147483648

#define CHRFLAG_HAS_BEEN_ON_SCREEN 8

#define PROPFLAG2_20000000 536870912

#define PROPFLAG_00004000 16384

#define PROPFLAG_00000200 512

#define CHR_OBJECTIVE -2

#define PROPFLAG_00400000 4194304

#define CHRFLAG_01000000 16777216

#define PROPFLAG2_00000200 512

#define CHRFLAG_SUNGLASSES 2

#define CHRFLAG_00000020 32

#define CHRFLAG_00040000 262144

#define PROPFLAG2_00010000 65536

#define CHR_CLONE -7

#define CHRFLAG_02000000 33554432

#define PROPFLAG_08000000 134217728

#define CHRFLAG_WAS_DAMAGED 256

#define PROPFLAG_80000000 2147483648

#define PROPFLAG2_00001000 4096

#define CHR_SEE_SHOT -6

#define CHRFLAG_00000200 512

#define CHRFLAG_00010000 65536

#define CHRFLAG_CAN_SHOOT_CHRS 64

#define PROPFLAG_00000004 4

#define PADEXTRA_START 10000

#define CHR_SELF -3

#define PROPFLAG_00000800 2048

#define PROPFLAG_00000008 8

#define PROPFLAG2_00000040 64

#define CHRFLAG_INCREASE_SPRINT_SPEED 524288

#define PROPFLAG_20000000 536870912

#define PROPFLAG_40000000 1073741824

#define PROPFLAG_00000001 1

#define PROPFLAG_00000002 2

#define CHRFLAG_04000000 67108864

#define PROPFLAG2_00000010 16

#define PROPFLAG2_00000001 1

#define PROPFLAG2_00000002 2

#define PROPFLAG2_00000004 4

#define PROPFLAG2_00000800 2048

#define PROPFLAG2_00000008 8

#define CHR_CLONED_NUM_START 9000

#define PROPFLAG_00200000 2097152

#define PROPFLAG2_00000020 32

#define PROPFLAG_00000100 256

#define PROPFLAG2_01000000 16777216

#define GAME_TICKRATE 60

#define PROPFLAG_04000000 67108864

#define PROPFLAG2_00200000 2097152

#define CHRFLAG_LOCK_Y_POS 4096

#define PROPFLAG2_00040000 262144

#define PROPFLAG_00001000 4096

#define PROPFLAG_01000000 16777216

#define CHRFLAG_20000000 536870912

#define PROPFLAG2_00100000 1048576

#define PROPFLAG_00800000 8388608

#define CHRFLAG_IGNORE_ANIM_TRANSLATION 16384

#define PROPFLAG2_02000000 33554432

#define CHRFLAG_00000080 128

#define CHRFLAG_00008000 32768

#define CHR_SPAWN_NUM_START 5000

#define CHRFLAG_40000000 1073741824

#define PROPFLAG2_00000080 128

#define PROPFLAG2_40000000 1073741824

#define PROPFLAG2_00008000 32768

#define CHRFLAG_WAS_HIT 2097152

#define PROPFLAG_00000040 64

#define CHRFLAG_00020000 131072

#define PROPFLAG_00080000 524288

#define PROPFLAG2_00080000 524288

#define PROPFLAG_02000000 33554432

#define PROPFLAG_00000010 16

#define CHRFLAG_08000000 134217728

#define PROPFLAG_00040000 262144

#define PROPFLAG2_10000000 268435456

#define PROPFLAG2_00002000 8192

#define PROPFLAG2_04000000 67108864

#define PROPFLAG_00000020 32

#define CHRFLAG_00400000 4194304

typedef struct IMAGE IMAGE, *PIMAGE;

struct IMAGE {
    ushort imagic;
    ushort type;
    ushort dim;
    ushort xsize;
    ushort ysize;
    ushort zsize;
    ulong min;
    ulong max;
    ulong wastebytes;
    char name[80];
    ulong colormap;
    long file;
    ushort flags;
    short dorev;
    short x;
    short y;
    short z;
    short cnt;
    ushort * ptr;
    ushort * base;
    ushort * tmpbuf;
    ulong offset;
    ulong rleend;
    ulong * rowstart;
    long * rowsize;
};

#define CM_COLORMAP 3

#define TYPEMASK 65280

#define ITYPE_VERBATIM 0

#define ITYPE_RLE 256

#define CM_DITHERED 1

#define IMAGIC 474

#define RLE_NOP 0

#define CM_SCREEN 2

#define BPPMASK 255

#define CM_NORMAL 0

typedef struct _Region_s _Region_s, *P_Region_s;

struct _Region_s {
    u8 * r_startBufferAddress;
    u8 * r_endAddress;
    s32 r_bufferSize;
    s32 r_bufferCount;
    u16 r_freeList;
    u16 r_alignSize;
};

typedef struct _Region_s OSRegion;

#define OS_RG_ALIGN_DEFAULT 8

#define MAX_BUFCOUNT 32768

#define OS_RG_ALIGN_16B 16

#define OS_RG_ALIGN_4B 4

#define OS_RG_ALIGN_2B 2

#define OS_RG_ALIGN_8B 8

#define BUF_FREE_WO_NEXT 32768

#define GT_STATE_OFF_VTXCOUNT 8

#define GT_STATE_OFF_TRANSFORM 24

#define GT_STATE_OFF_RENDSTATE 0

#define GT_STATE_OFF_TRICOUNT 10

#define GT_STATE_OFF_VTXV0 9

#define GT_STATE_SIZE 88

#define GT_STATE_OFF_TEXSTATE 4

#define GT_STATE_OFF_OTHERMODE 16

#define GT_STATE_OFF_RDPCMDS 12

#define M_GFXTASK 1

#define G_OFF 0

#define G_ON 1

#define M_VIDTASK 3

#define NUM_SEGMENTS 16

#define M_AUDTASK 2

typedef void (* OSErrorHandler)(s16, s16, ...);

#define ERR_OSPISTARTDMA_PIMGR 28

#define ERR_OSCREATETHREAD_PRI 2

#define ERR_OSVISETXSCALE_VALUE 39

#define ERR_ALMODDELAYOVERFLOW 133

#define ERR_OSVIGETNEXTFRAMEBUFFER 38

#define ERR_OSSETTLBASID 13

#define ERR_OSVIGETCURRENTFRAMEBUFFER 37

#define ERR_ALEVENTNOFREE 124

#define ERR_OSPISTARTDMA_DIR 30

#define ERR_OSSETTHREADPRI 4

#define ERR_OSSETTIME 75

#define ERR_OSREADHOST_ADDR 70

#define ERR_OSPROFILESTART_TIME 66

#define ERR_OSVISETMODE 45

#define ERR_ALSYN_NO_UPDATE 106

#define ERR_ALSEQSYSEX 119

#define ERR_OSFREE_REGION 53

#define ERR_OSGETREGIONBUFCOUNT 55

#define ERR_OSPISTARTDMA_PRI 29

#define ERR_OSMAPTLB_INDEX 10

#define ERR_OSCREATEVIMANAGER 49

#define ERR_ALSEQMETA 120

#define ERR_ALBNKFNEW 113

#define ERR_ALCSEQZEROSTATUS 128

#define ERR_OSPISTARTDMA_DEVADDR 31

#define ERR_OSSETEVENTMESG 9

#define ERR_ALHEAPNOFREE 125

#define ERR_OSAISETNEXTBUFFER_ADDR 15

#define ERR_OSSTARTTHREAD 3

#define ERR_OSREADHOST_SIZE 71

#define ERR_ALSEQPUNMAP 123

#define ERR_OSUNMAPTLB 12

#define ERR_OSAISETNEXTBUFFER_SIZE 16

#define ERR_ALSNDPSETSOUND 110

#define ERR_OSVISWAPBUFFER_VIMGR 48

#define ERR_ALSEQNOTMIDI0 115

#define ERR_OSPROFILEINIT_STR 61

#define ERR_OSPROFILESTART_FLAG 67

#define ERR_OSMAPTLB_ASID 11

#define ERR_OSCREATETHREAD_SP 1

#define ERR_OSGETREGIONBUFSIZE 56

#define ERR_OSVISETEVENT 46

#define ERR_OSVISETSPECIAL_VALUE 43

#define ERR_OSVISETYSCALE_VALUE 41

#define ERR_OSPIRAWSTARTDMA_DIR 21

#define ERR_OSPIRAWWRITEIO 20

#define ERR_OSPROFILESTOP_FLAG 68

#define ERR_ALCSEQZEROVEL 129

#define ERR_OSMALLOC 52

#define ERR_OSSPTASKLOAD_OUTSIZE 59

#define ERR_ALSEQNOTMIDI 114

#define ERR_OSVIGETCURRENTMODE 36

#define ERR_OSPIRAWSTARTDMA_ADDR 23

#define ERR_OSCREATEREGION_SIZE 51

#define ERR_OSPIRAWSTARTDMA_SIZE 24

#define ERR_OSVISETXSCALE_VIMGR 40

#define ERR_ALCSPVNOTFREE 130

#define ERR_OSJAMMESG 7

#define ERR_OSPISTARTDMA_RANGE 34

#define ERR_ALSEQPINVALIDPROG 121

#define ERR_OSPIWRITEIO 27

#define ERR_OSPROFILEINIT_ORD 64

#define ERR_OSPROFILEINIT_SIZ 65

#define ERR_OSPIREADIO 26

#define ERR_OSSPTASKLOAD_YIELD 60

#define ERR_OSSTOPTIMER 77

#define ERR_OSSENDMESG 6

#define ERR_OSPISTARTDMA_ADDR 32

#define ERR_OSVISETSPECIAL_VIMGR 44

#define ERR_ALSEQTRACKHDR 118

#define ERR_OSSPTASKLOAD_DRAM 57

#define ERR_OSPROFILESTOP_TIMER 69

#define ERR_OSAISETFREQUENCY 14

#define ERR_ALSEQP_MAP_VOICE 102

#define ERR_OSFREE_ADDR 54

#define ERR_OSDPSETNEXTBUFFER_ADDR 17

#define ERR_OSDPSETNEXTBUFFER_SIZE 18

#define ERR_ALSNDPDELETE 108

#define ERR_OSSPTASKLOAD_OUT 58

#define ERR_OSPIRAWSTARTDMA_DEVADDR 22

#define ERR_OSCREATEMESGQUEUE 5

#define ERR_ALSNDPSETPRIORITY 111

#define ERR_ALHEAPFIRSTBLOCK 127

#define OS_ERROR_MAGIC 1801548921

#define ERR_OSPIRAWSTARTDMA_RANGE 25

#define ERR_ALSNDPSETPAR 112

#define ERR_OSSETTIMER 76

#define ERR_OSGETTIME 74

#define ERR_ALSEQP_NO_SOUND 100

#define ERR_ALSNDPDEALLOCATE 107

#define ERR_ALSEQNUMTRACKS 116

#define ERR_OSCREATEREGION_ALIGN 50

#define ERR_ALSEQP_POLY_VOICE 104

#define ERR_OSVISWAPBUFFER_ADDR 47

#define ERR_ALSNDP_NO_VOICE 105

#define ERR_ALHEAPCORRUPT 126

#define ERR_ALSEQTIME 117

#define ERR_ALSNDPPLAY 109

#define ERR_OSPIRAWREADIO 19

#define ERR_OSAISETNEXTBUFFER_ENDADDR 132

#define ERR_OSPROFILEINIT_ALN 63

#define ERR_OSWRITEHOST_ADDR 72

#define ERR_OSWRITEHOST_SIZE 73

#define ERR_ALSEQPUNKNOWNMIDI 122

#define ERR_OSCREATEPIMANAGER 35

#define ERR_ALSEQP_NO_VOICE 101

#define ERR_ALSEQOVERRUN 131

#define ERR_OSPISTARTDMA_SIZE 33

#define ERR_OSPROFILEINIT_CNT 62

#define ERR_ALSEQP_OFF_VOICE 103

#define ERR_OSRECVMESG 8

#define ERR_OSVISETYSCALE_VIMGR 42

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
};

typedef struct OSThread_s OSThread_s, *POSThread_s;

typedef s32 OSPri;

typedef s32 OSId;

typedef struct __OSThreadprofile_s __OSThreadprofile_s, *P__OSThreadprofile_s;

typedef struct __OSThreadContext __OSThreadContext, *P__OSThreadContext;

typedef union __OSfp __OSfp, *P__OSfp;

typedef struct _struct_3 _struct_3, *P_struct_3;

struct _struct_3 {
    f32 f_odd;
    f32 f_even;
};

union __OSfp {
    struct _struct_3 f;
};

struct __OSThreadContext {
    u64 at;
    u64 v0;
    u64 v1;
    u64 a0;
    u64 a1;
    u64 a2;
    u64 a3;
    u64 t0;
    u64 t1;
    u64 t2;
    u64 t3;
    u64 t4;
    u64 t5;
    u64 t6;
    u64 t7;
    u64 s0;
    u64 s1;
    u64 s2;
    u64 s3;
    u64 s4;
    u64 s5;
    u64 s6;
    u64 s7;
    u64 t8;
    u64 t9;
    u64 gp;
    u64 sp;
    u64 s8;
    u64 ra;
    u64 lo;
    u64 hi;
    u32 sr;
    u32 pc;
    u32 cause;
    u32 badvaddr;
    u32 rcp;
    u32 fpcsr;
    union __OSfp fp0;
    union __OSfp fp2;
    union __OSfp fp4;
    union __OSfp fp6;
    union __OSfp fp8;
    union __OSfp fp10;
    union __OSfp fp12;
    union __OSfp fp14;
    union __OSfp fp16;
    union __OSfp fp18;
    union __OSfp fp20;
    union __OSfp fp22;
    union __OSfp fp24;
    union __OSfp fp26;
    union __OSfp fp28;
    union __OSfp fp30;
};

struct OSThread_s {
    struct OSThread_s * next;
    OSPri priority;
    struct OSThread_s * * queue;
    struct OSThread_s * tlnext;
    u16 state;
    u16 flags;
    OSId id;
    int fp;
    struct __OSThreadprofile_s * thprof;
    struct __OSThreadContext context;
};

struct __OSThreadprofile_s {
    u32 flag;
    u32 count;
    u64 time;
};

typedef struct OSThread_s OSThread;

#define OS_PRIORITY_APPMAX 127

#define OS_STATE_RUNNING 4

#define OS_PRIORITY_RMON 250

#define OS_PRIORITY_PIMGR 150

#define OS_PRIORITY_IDLE 0

#define OS_PRIORITY_MAX 255

#define OS_STATE_STOPPED 1

#define OS_PRIORITY_VIMGR 254

#define OS_STATE_RUNNABLE 2

#define OS_STATE_WAITING 8

#define OS_PRIORITY_SIMGR 140

#define OS_PRIORITY_RMONSPIN 200

typedef struct __OSEventState __OSEventState, *P__OSEventState;

typedef struct OSMesgQueue_s OSMesgQueue_s, *POSMesgQueue_s;

typedef struct OSMesgQueue_s OSMesgQueue;

typedef void * OSMesg;


// WARNING! conflicting data type names: /os.h/OSThread - /thread.h/OSThread

struct __OSEventState {
    OSMesgQueue * messageQueue;
    OSMesg message;
};

struct OSMesgQueue_s {
    OSThread * mtqueue;
    OSThread * fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg * msg;
};

typedef struct __OSThreadTail __OSThreadTail, *P__OSThreadTail;


// WARNING! conflicting data type names: /os.h/OSPri - /thread.h/OSPri

struct __OSThreadTail {
    OSThread * next;
    OSPri priority;
};

typedef struct guDLPrintCB guDLPrintCB, *PguDLPrintCB;

struct guDLPrintCB {
    int dataSize;
    int dlType;
    int flags;
    u32 paddr;
};

typedef struct PositionalLight PositionalLight, *PPositionalLight;

struct PositionalLight {
    float col[3];
    float pos[3];
    float a1;
    float a2;
};

typedef struct Image Image, *PImage;

struct Image {
    uchar * base;
    int fmt;
    int siz;
    int xsize;
    int ysize;
    int lsize;
    int addr;
    int w;
    int h;
    int s;
    int t;
};

#define GU_PARSE_GBI_TYPE 1

#define GU_PARSE_MEM_BLOCK 4

#define GU_PARSEGBI_NONEST 2

#define GU_BLINKRDP_HILITE 1

#define GU_PARSEGBI_ROWMAJOR 1

#define GU_PARSEGBI_ALLMTX 16

#define GU_PARSERDP_VERBOSE 1

#define GU_PARSE_RDP_TYPE 2

#define GU_BLINKRDP_EXTRACT 2

#define GU_PARSE_READY 3

#define GU_PARSERDP_PRHISTO 4

#define FILTER_CLAMP 1

#define GU_PARSEGBI_DUMPONLY 32

#define GU_PARSEGBI_SHOWDMA 8

#define GU_PARSERDP_DUMPONLY 32

#define GU_PARSEGBI_FLTMTX 4

#define GU_PARSE_ABI_TYPE 5

#define GU_PARSERDP_PRAREA 2

#define FILTER_WRAP 0

#define GU_PARSE_STRING_TYPE 6

typedef struct huft huft, *Phuft;

typedef union _union_2 _union_2, *P_union_2;

union _union_2 {
    ush n;
    struct huft * t;
};

struct huft {
    uch e;
    uch b;
    union _union_2 v;
};

#define BMAX 16

#define N_MAX 288

typedef struct OSPifRam OSPifRam, *POSPifRam;

struct OSPifRam {
    u32 ramarray[15];
    u32 pifstatus;
};

typedef union __OSInodeUnit __OSInodeUnit, *P__OSInodeUnit;

typedef struct _struct_195 _struct_195, *P_struct_195;

struct _struct_195 {
    u8 bank;
    u8 page;
};

union __OSInodeUnit {
    struct _struct_195 inode_t;
    u16 ipage;
};

typedef struct __OSContEepromFormat __OSContEepromFormat, *P__OSContEepromFormat;

struct __OSContEepromFormat {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 address;
    u8 data[8];
};

typedef struct __OSContReadFormat __OSContReadFormat, *P__OSContReadFormat;

struct __OSContReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    s8 stick_x;
    s8 stick_y;
};

typedef struct __OSContRamReadFormat __OSContRamReadFormat, *P__OSContRamReadFormat;

struct __OSContRamReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
};

typedef struct __OSInode __OSInode, *P__OSInode;

struct __OSInode {
    union __OSInodeUnit inode_page[128];
};

typedef struct __OSContRequesFormat __OSContRequesFormat, *P__OSContRequesFormat;

struct __OSContRequesFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
};

typedef struct __OSDir __OSDir, *P__OSDir;

struct __OSDir {
    u32 game_code;
    u16 company_code;
    union __OSInodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    char ext_name[4];
    char game_name[16];
};

typedef struct __OSPackId __OSPackId, *P__OSPackId;

struct __OSPackId {
    u32 repaired;
    u32 random;
    u64 serial_mid;
    u64 serial_low;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
};

typedef struct __OSInodeCache __OSInodeCache, *P__OSInodeCache;

struct __OSInodeCache {
    struct __OSInode inode;
    u8 bank;
    u8 map[256];
};

#define CONT_EEPROM_READ 4

#define CONT_SETCH 254

#define PFS_64K_RAM 2

#define PFS_INODE_DIST_MAP 256

#define PFS_FORCE 1

#define CONT_FORMAT 1

#define PFS_ID_1AREA 3

#define PFS_EOF 1

#define PFS_SECTOR_PER_BANK 32

#define EEPROM_WAIT 12000

#define PFS_INODE_SIZE_PER_PAGE 128

#define PFS_ID_2AREA 4

#define FORMAT_END 254

#define PFS_ID_3AREA 6

#define CONT_RESET 255

#define PFS_DELETE 1

#define PFS_PAGE_SIZE 256

#define PFS_SIZE_LOC 24

#define PFS_32K_RAM 1

#define CONT_READ 1

#define PFS_LABEL_AREA 7

#define CONT_RAM_READ 2

#define PIFRAMSIZE 16

#define PFS_PAGE_NOT_EXIST 2

#define CONT_EEPROM_WRITE 5

#define PFS_PAGE_NOT_USED 3

#define PFS_BANK_LAPPED_BY 8

#define CONT_RAM_WRITE 3

#define PFS_ID_PAGE 0

#define PFS_SECTOR_SIZE 4

#define CHANNEL_RESET 253

#define CONT_REQUEST 0

#define DEF_DIR_PAGES 2

#define PFS_ID_0AREA 1

#define PFS_WRITTEN 2

#define CON_ERR_MASK 192

typedef struct debug_processor_error_entry debug_processor_error_entry, *Pdebug_processor_error_entry;

struct debug_processor_error_entry {
    u32 val1;
    u32 val2;
    void * string;
};

typedef struct debug_handler_entry debug_handler_entry, *Pdebug_handler_entry;

struct debug_handler_entry {
    void * address;
    char * ptr_name;
};

#define RMON_STACKSIZE 4096

#define RMON_DBG_BUF_SIZE 2048


// WARNING! conflicting data type names: /message.h/OSMesgQueue_s - /os.h/OSMesgQueue_s

typedef u32 OSEvent;


// WARNING! conflicting data type names: /message.h/OSMesgQueue - /os.h/OSMesgQueue

#define OS_EVENT_CART 2

#define OS_EVENT_VI 7

#define OS_EVENT_FAULT 12

#define OS_EVENT_AI 6

#define OS_EVENT_THREADSTATUS 13

#define OS_EVENT_CPU_BREAK 10

#define OS_MESG_NOBLOCK 0

#define OS_EVENT_PI 8

#define OS_EVENT_COUNTER 3

#define OS_EVENT_DP 9

#define OS_MESG_BLOCK 1

#define OS_EVENT_SP 4

#define OS_EVENT_SP_BREAK 11

#define OS_EVENT_SI 5

#define OS_EVENT_PRENMI 14

#define OS_EVENT_SW2 1

#define OS_EVENT_SW1 0

typedef struct OSTimer_str OSTimer_str, *POSTimer_str;

struct OSTimer_str {
    struct OSTimer_str * next;
    struct OSTimer_str * prev;
    u64 interval;
    u64 remaining;
    OSMesgQueue * mq;
    OSMesg * msg;
};

typedef struct OSTimer_str OSTimer;

typedef u32 OSIntMask;

typedef struct Elf32_RegInfo_MIPS Elf32_RegInfo_MIPS, *PElf32_RegInfo_MIPS;

struct Elf32_RegInfo_MIPS {
    enum Elf32_GPRMask_MIPS ri_gprmask;
    dword field_0x4[4];
    dword ri_gp_value;
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

typedef enum Elf_SectionHeaderType_MIPS {
    =1879048203,
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_MIPS_ABIFLAGS=1879048234,
    SHT_MIPS_AUXSYM=1879048214,
    SHT_MIPS_CONFLICT=1879048194,
    SHT_MIPS_CONTENT=1879048204,
    SHT_MIPS_DEBUG=1879048197,
    SHT_MIPS_DELTACLASS=1879048221,
    SHT_MIPS_DELTADECL=1879048223,
    SHT_MIPS_DELTAINST=1879048220,
    SHT_MIPS_DELTASYM=1879048219,
    SHT_MIPS_DENSE=1879048211,
    SHT_MIPS_DWARF=1879048222,
    SHT_MIPS_EH_REGION=1879048231,
    SHT_MIPS_EVENTS=1879048225,
    SHT_MIPS_EXTSYM=1879048210,
    SHT_MIPS_FDESC=1879048209,
    SHT_MIPS_GPTAB=1879048195,
    SHT_MIPS_LIBLIST=1879048192,
    SHT_MIPS_LINE=1879048217,
    SHT_MIPS_LOCSTR=1879048216,
    SHT_MIPS_LOCSYM=1879048213,
    SHT_MIPS_MSYM=1879048193,
    SHT_MIPS_OPTIONS=1879048205,
    SHT_MIPS_OPTSYM=1879048215,
    SHT_MIPS_PACKAGE=1879048199,
    SHT_MIPS_PACKSYM=1879048200,
    SHT_MIPS_PDESC=1879048212,
    SHT_MIPS_PDR_EXCEPTION=1879048233,
    SHT_MIPS_PIXIE=1879048227,
    SHT_MIPS_REGINFO=1879048198,
    SHT_MIPS_RELD=1879048201,
    SHT_MIPS_RFDESC=1879048218,
    SHT_MIPS_SHDR=1879048208,
    SHT_MIPS_SYMBOL_LIB=1879048224,
    SHT_MIPS_TRANSLATE=1879048226,
    SHT_MIPS_UCODE=1879048196,
    SHT_MIPS_WHIRL=1879048230,
    SHT_MIPS_XLATE=1879048228,
    SHT_MIPS_XLATE_DEBUG=1879048229,
    SHT_MIPS_XLATE_OLD=1879048232,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType_MIPS;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_MIPS sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_MIPS {
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_MIPS_ABIFLAGS=1879048195,
    PT_MIPS_OPTIONS=1879048194,
    PT_MIPS_REGINFO=1879048192,
    PT_MIPS_RTPROC=1879048193,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType_MIPS;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_MIPS p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_pad[9];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

#define SAFE_EXP 1023

#define _DMASK 32752

#define _D3 3

#define _D2 2

#define _D1 1

#define _DNAN 65528

#define _DFRAC 15

#define _DMAX 2047

#define NAN 2

#define _DSIGN 32768

#define INF 1

#define FINITE -1

#define HUGE_EXP 1842

typedef char * voidp;

typedef int file_t;

#define RESERVED 192

#define seekable 0

#define PACKED 2

#define DIST_BUFSIZE 32768

#define DEFLATED 8

#define WARNING 2

#define ORIG_NAME 8

#define translate_eol 0

#define MAX_MATCH 258

#define CONTINUATION 2

#define MIN_MATCH 3

#define STORED 0

#define COMMENT 16

#define WSIZE 32768

#define MIN_LOOKAHEAD 262

#define EXTRA_FIELD 4

#define ASCII 1

#define INBUFSIZ 32768

#define OUTBUF_EXTRA 2048

#define OK 0

#define MAX_DIST 32506

#define ASCII_FLAG 1

#define MAX_METHODS 9

#define ENCRYPTED 32

#define LZHED 3

#define NO_FILE -1

#define OUTBUFSIZ 16384

#define COMPRESSED 1

#define INBUF_EXTRA 64

#define ERROR 1

#define UNKNOWN 65535

#define BINARY 0

typedef struct OSIoMesg OSIoMesg, *POSIoMesg;

typedef struct OSIoMesgHdr OSIoMesgHdr, *POSIoMesgHdr;

typedef struct OSPiHandle_s OSPiHandle_s, *POSPiHandle_s;

typedef struct OSPiHandle_s OSPiHandle;

typedef struct __OSTranxInfo __OSTranxInfo, *P__OSTranxInfo;

typedef struct __OSBlockInfo __OSBlockInfo, *P__OSBlockInfo;

struct OSIoMesgHdr {
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue * retQueue;
};

struct OSIoMesg {
    struct OSIoMesgHdr hdr;
    void * dramAddr;
    u32 devAddr;
    u32 size;
    OSPiHandle * piHandle;
};

struct __OSBlockInfo {
    u32 errStatus;
    void * dramAddr;
    void * C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
};

struct __OSTranxInfo {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    struct __OSBlockInfo block[2];
};

struct OSPiHandle_s {
    struct OSPiHandle_s * next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    struct __OSTranxInfo transferInfo;
};

typedef struct OSPiInfo OSPiInfo, *POSPiInfo;

struct OSPiInfo {
    u8 type;
    u32 address;
};

#define OS_MESG_PRI_HIGH 1

#define OS_WRITE 1

#define OS_READ 0

#define OS_MESG_PRI_NORMAL 0

#define DPS_REG_BASE 2753560576

#define DPC_REG_BASE 2752512000

typedef struct RamRomBuffer RamRomBuffer, *PRamRomBuffer;

struct RamRomBuffer {
    long type;
    long length;
    long magic;
    char userdata[24573];
};

#define RAMROM_BUF_SIZE 4096

#define RAMROM_FONTDATA_SIZE 1152

#define GAME_APP_DATA_READY 10

#define HOST_FAULT_ACK 15

#define RAMROM_MSG_ADDR 16752640

#define HOST_LOG_ACK 8

#define RAMROM_RMON_WRITE_ADDR 16764928

#define HOST_PIACCESS_REQ 1

#define RAMROM_FONTDATA_OFFSET 2928

#define RAMROM_PIF2BOOTSTRAP_OFFSET 4096

#define RAMROM_CLOCKRATE_MASK 4294967280

#define GAME_PRINTF_SEND 5

#define HOST_PROF_ACK 13

#define GAME_EXIT 16

#define HOST_PROF_REQ 11

#define RAMROM_BOOTADDR_OFFSET 8

#define HOST_DBG_DATA_ACK 4

#define GAME_LOG_SEND 7

#define HOST_DBG_CMD_READY 2

#define RAMROM_SIZE 16777216

#define RAMROM_APP_WRITE_ADDR 16756736

#define RAMROM_BOOTSTRAP_OFFSET 64

#define HOST_PRINTF_ACK 6

#define RAMROM_CLOCKRATE_OFFSET 4

#define RAMROM_MSG_SIZE 24576

#define RAMROM_RMON_READ_ADDR 16760832

#define GAME_FAULT_SEND 14

#define RAMROM_PRINTF_ADDR 16769024

#define GAME_PROF_SEND 12

#define HOST_APP_CMD_READY 9

#define RAMROM_LOG_ADDR 16773120

#define HOST_DATA_ACK 17

#define RAMROM_GAME_OFFSET 4096

#define GAME_DBG_DATA_SEND 3

#define RAMROM_APP_READ_ADDR 16752640

#define RAMROM_RELEASE_OFFSET 12


// WARNING! conflicting data type names: /_CAPTURED_FROM_ge007.u.old.elf/__OSPackId - /CONTROLLER.H/__OSPackId

typedef struct struct struct, *Pstruct;

typedef struct OSViMode OSViMode, *POSViMode;

typedef struct OSViCommonRegs OSViCommonRegs, *POSViCommonRegs;

typedef struct OSViFieldRegs OSViFieldRegs, *POSViFieldRegs;

struct struct {
    u16 field_0x0;
    u16 field_0x2;
    void * field_0x4;
    struct OSViMode * field_0x8;
    u32 field_0xc;
    OSMesgQueue * field_0x10;
    OSMesg field_0x14;
};

struct OSViCommonRegs {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
};

struct OSViFieldRegs {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
};

struct OSViMode {
    u8 type;
    struct OSViCommonRegs comRegs;
    struct OSViFieldRegs fldRegs[2];
};

typedef struct PVoice PVoice, *PPVoice;

typedef struct ALLink_s ALLink_s, *PALLink_s;

typedef struct ALLink_s ALLink;

typedef struct ALVoice_s ALVoice_s, *PALVoice_s;

typedef struct ALFilter_s ALFilter_s, *PALFilter_s;

typedef struct ALADPCMFilter ALADPCMFilter, *PALADPCMFilter;

typedef struct ALResampler ALResampler, *PALResampler;

typedef struct ALEnvMixer_s ALEnvMixer_s, *PALEnvMixer_s;

typedef struct PVoice_s PVoice_s, *PPVoice_s;

typedef struct ALWaveTable_s ALWaveTable_s, *PALWaveTable_s;

typedef struct ALWaveTable_s ALWaveTable;

typedef short ADPCM_STATE[16];

typedef struct $039A3EC5794421300707C77A911A1BDF $039A3EC5794421300707C77A911A1BDF, *P$039A3EC5794421300707C77A911A1BDF;

typedef struct $039A3EC5794421300707C77A911A1BDF ALADPCMloop;

typedef s32 (* ALDMAproc)(s32, s32, void *);


// WARNING! conflicting data type names: /_CAPTURED_FROM_ge007.u.old.elf/ALFilter_s - /libaudio.h/ALFilter_s

typedef short RESAMPLE_STATE[16];

typedef struct ALParam_s ALParam_s, *PALParam_s;

typedef short ENVMIX_STATE[40];

typedef union _union_109 _union_109, *P_union_109;

typedef struct ALADPCMWaveInfo ALADPCMWaveInfo, *PALADPCMWaveInfo;

typedef struct ALRAWWaveInfo ALRAWWaveInfo, *PALRAWWaveInfo;


// WARNING! conflicting data type names: /libaudio.h/ALADPCMloop - /GE Current Master.h/ALADPCMloop

typedef struct ALADPCMBook ALADPCMBook, *PALADPCMBook;

typedef struct ALRawLoop ALRawLoop, *PALRawLoop;

struct PVoice_s {
};

struct $039A3EC5794421300707C77A911A1BDF {
};

struct ALResampler {
    struct ALFilter_s filter;
    RESAMPLE_STATE state;
    float ratio;
    int upitch;
    float delta;
    int first;
    struct ALParam_s * ctrlList;
    struct ALParam_s * ctrlTail;
};

struct ALFilter_s {
};

struct ALADPCMBook {
    s32 order;
    s32 npredictors;
    s16 book[1];
};

struct ALADPCMWaveInfo {
    struct ALADPCMloop * loop;
    struct ALADPCMBook * book;
};

struct ALRAWWaveInfo {
    struct ALRawLoop * loop;
};

union _union_109 {
    struct ALADPCMWaveInfo adpcmWave;
    struct ALRAWWaveInfo rawWave;
};

struct ALWaveTable_s {
    u8 * base;
    s32 len;
    u8 type;
    u8 flags;
    union _union_109 waveInfo;
};

struct ALLink_s {
    struct ALLink_s * next;
    struct ALLink_s * prev;
};

struct ALVoice_s {
    ALLink node;
    struct PVoice_s * pvoice;
    ALWaveTable * table;
    void * clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
};

struct ALEnvMixer_s {
    struct ALFilter_s filter;
    ENVMIX_STATE state;
    short pan;
    short volume;
    short cvolL;
    short cvolR;
    short dryamt;
    short wetamt;
    ushort lratl;
    short lratm;
    short ltgt;
    ushort rratl;
    short rratm;
    short rtgt;
    int delta;
    int segEnd;
    int first;
    struct ALParam_s * ctrlList;
    struct ALParam_s * ctrlTail;
    struct ALFilter_s * * sources;
    int motion;
};

struct ALRawLoop {
    u32 start;
    u32 end;
    u32 count;
};

struct ALADPCMFilter {
    struct ALFilter_s filter;
    ADPCM_STATE state[AL_MAX_ADPCM_STATES];
    ALADPCMloop loop;
    struct ALWaveTable_s * table;
    int bookSize;
    ALDMAproc dma;
    int current;
    int sample;
    int lastsam;
    int first;
    int memin;
    int dramstart;
};

struct ALParam_s {
};

struct PVoice {
    ALLink node;
    struct ALVoice_s * vvoice;
    void * rspCode;
    struct ALFilter_s * sourceKnob;
    struct ALFilter_s * channelKnob;
    struct ALADPCMFilter decoder;
    struct ALResampler resampler;
    struct ALEnvMixer_s envmixer;
};

typedef int * ALSetParam;

typedef enum DEBUG_MENU_FLAGS {
    FLAG_4=4,
    FLAG_8=8
} DEBUG_MENU_FLAGS;

typedef struct __OSViContext __OSViContext, *P__OSViContext;

typedef struct __OSViScale __OSViScale, *P__OSViScale;

struct __OSViScale {
    f32 factor;
    u16 offset;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
};

struct __OSViContext {
    u16 state;
    u16 retraceCount;
    void * framep;
    struct OSViMode * modep;
    u32 control;
    OSMesgQueue * msgq;
    OSMesg msg;
    struct __OSViScale x;
    struct __OSViScale y;
    u32 pad;
};


// WARNING! conflicting data type names: /_CAPTURED_FROM_ge007.u.old.elf/debug_handler_entry - /init.h/debug_handler_entry

typedef enum BOOL {
    FALSE=0,
    TRUE=1
} BOOL;

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

typedef union Acmd Acmd, *PAcmd;

typedef union Acmd ALCmdHandler;

typedef struct Awords Awords, *PAwords;

typedef struct Aadpcm Aadpcm, *PAadpcm;

typedef struct Apolef Apolef, *PApolef;

typedef struct Aclearbuff Aclearbuff, *PAclearbuff;

typedef struct Aenvelope Aenvelope, *PAenvelope;

typedef struct Ainterleave Ainterleave, *PAinterleave;

typedef struct Aloadbuff Aloadbuff, *PAloadbuff;

typedef struct Aenvmixer Aenvmixer, *PAenvmixer;

typedef struct Aresample Aresample, *PAresample;

typedef struct Areverb Areverb, *PAreverb;

typedef struct Asavebuff Asavebuff, *PAsavebuff;

typedef struct Asegment Asegment, *PAsegment;

typedef struct Asetbuff Asetbuff, *PAsetbuff;

typedef struct Asetvol Asetvol, *PAsetvol;

typedef struct Admemmove Admemmove, *PAdmemmove;

typedef struct Aloadadpcm Aloadadpcm, *PAloadadpcm;

typedef struct Amixer Amixer, *PAmixer;

typedef struct Asetloop Asetloop, *PAsetloop;

typedef union anon__struct_76_bitfield_1 anon__struct_76_bitfield_1, *Panon__struct_76_bitfield_1;

typedef union anon__struct_77_bitfield_1 anon__struct_77_bitfield_1, *Panon__struct_77_bitfield_1;

typedef union anon__struct_79_bitfield_1 anon__struct_79_bitfield_1, *Panon__struct_79_bitfield_1;

typedef union anon__struct_79_bitfield_2 anon__struct_79_bitfield_2, *Panon__struct_79_bitfield_2;

typedef union anon__struct_78_bitfield_1 anon__struct_78_bitfield_1, *Panon__struct_78_bitfield_1;

typedef union anon__struct_80_bitfield_1 anon__struct_80_bitfield_1, *Panon__struct_80_bitfield_1;

typedef union anon__struct_80_bitfield_2 anon__struct_80_bitfield_2, *Panon__struct_80_bitfield_2;

typedef union anon__struct_81_bitfield_1 anon__struct_81_bitfield_1, *Panon__struct_81_bitfield_1;

typedef union anon__struct_82_bitfield_1 anon__struct_82_bitfield_1, *Panon__struct_82_bitfield_1;

typedef union anon__struct_85_bitfield_1 anon__struct_85_bitfield_1, *Panon__struct_85_bitfield_1;

typedef union anon__struct_86_bitfield_1 anon__struct_86_bitfield_1, *Panon__struct_86_bitfield_1;

typedef union anon__struct_87_bitfield_1 anon__struct_87_bitfield_1, *Panon__struct_87_bitfield_1;

typedef union anon__struct_88_bitfield_1 anon__struct_88_bitfield_1, *Panon__struct_88_bitfield_1;

typedef union anon__struct_88_bitfield_2 anon__struct_88_bitfield_2, *Panon__struct_88_bitfield_2;

typedef union anon__struct_89_bitfield_1 anon__struct_89_bitfield_1, *Panon__struct_89_bitfield_1;

typedef union anon__struct_89_bitfield_2 anon__struct_89_bitfield_2, *Panon__struct_89_bitfield_2;

typedef union anon__struct_90_bitfield_1 anon__struct_90_bitfield_1, *Panon__struct_90_bitfield_1;

typedef union anon__struct_90_bitfield_2 anon__struct_90_bitfield_2, *Panon__struct_90_bitfield_2;

typedef union anon__struct_91_bitfield_1 anon__struct_91_bitfield_1, *Panon__struct_91_bitfield_1;

typedef union anon__struct_91_bitfield_2 anon__struct_91_bitfield_2, *Panon__struct_91_bitfield_2;

typedef union anon__struct_92_bitfield_1 anon__struct_92_bitfield_1, *Panon__struct_92_bitfield_1;

typedef union anon__struct_83_bitfield_1 anon__struct_83_bitfield_1, *Panon__struct_83_bitfield_1;

typedef union anon__struct_83_bitfield_2 anon__struct_83_bitfield_2, *Panon__struct_83_bitfield_2;

typedef union anon__struct_93_bitfield_1 anon__struct_93_bitfield_1, *Panon__struct_93_bitfield_1;

union anon__struct_78_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint pad1:16; // : bits 16-31
};

union anon__struct_81_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:24; // : bits 8-31
};

union anon__struct_88_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:24; // : bits 8-31
};

union anon__struct_91_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:8; // : bits 8-15
    uint dmemin:16; // : bits 16-31
};

union anon__struct_80_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:8; // : bits 8-15
    uint pad2:16; // : bits 16-31
};

union anon__struct_80_bitfield_2 {
    uint inL:16; // : bits 0-15
    uint inR:16; // : bits 16-31
};

struct Ainterleave {
    union anon__struct_80_bitfield_1 field_0x0;
    union anon__struct_80_bitfield_2 field_0x4;
};

union anon__struct_88_bitfield_2 {
    uint pad2:2; // : bits 0-1
    uint number:4; // : bits 2-5
    uint base:24; // : bits 6-29
};

struct Asegment {
    union anon__struct_88_bitfield_1 field_0x0;
    union anon__struct_88_bitfield_2 field_0x4;
};

union anon__struct_91_bitfield_2 {
    uint dmemout:16; // : bits 0-15
    uint count:16; // : bits 16-31
};

union anon__struct_77_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint gain:16; // : bits 16-31
};

struct Apolef {
    union anon__struct_77_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_83_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint gain:16; // : bits 16-31
};

union anon__struct_83_bitfield_2 {
    uint dmemi:16; // : bits 0-15
    uint dmemo:16; // : bits 16-31
};

struct Amixer {
    union anon__struct_83_bitfield_1 field_0x0;
    union anon__struct_83_bitfield_2 field_0x4;
};

struct Awords {
    uint w0;
    uint w1;
};

union anon__struct_85_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint pitch:16; // : bits 16-31
};

struct Aresample {
    union anon__struct_85_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_89_bitfield_2 {
    uint dmemout:16; // : bits 0-15
    uint count:16; // : bits 16-31
};

union anon__struct_89_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint dmemin:16; // : bits 16-31
};

struct Asetbuff {
    union anon__struct_89_bitfield_1 field_0x0;
    union anon__struct_89_bitfield_2 field_0x4;
};

struct Aenvelope {
    union anon__struct_78_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_86_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint pad1:16; // : bits 16-31
};

struct Areverb {
    union anon__struct_86_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_82_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint pad1:16; // : bits 16-31
};

struct Aenvmixer {
    union anon__struct_82_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_90_bitfield_2 {
    uint voltgt:16; // : bits 0-15
    uint volrate:16; // : bits 16-31
};

union anon__struct_90_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint vol:16; // : bits 16-31
};

struct Asetvol {
    union anon__struct_90_bitfield_1 field_0x0;
    union anon__struct_90_bitfield_2 field_0x4;
};

union anon__struct_76_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint gain:16; // : bits 16-31
};

struct Aadpcm {
    union anon__struct_76_bitfield_1 field_0x0;
    uint addr;
};

struct Admemmove {
    union anon__struct_91_bitfield_1 field_0x0;
    union anon__struct_91_bitfield_2 field_0x4;
};

union anon__struct_92_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:8; // : bits 8-15
    uint count:16; // : bits 16-31
};

struct Aloadadpcm {
    union anon__struct_92_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_79_bitfield_2 {
    uint pad2:16; // : bits 0-15
    uint count:16; // : bits 16-31
};

union anon__struct_79_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:8; // : bits 8-15
    uint dmem:16; // : bits 16-31
};

struct Aclearbuff {
    union anon__struct_79_bitfield_1 field_0x0;
    union anon__struct_79_bitfield_2 field_0x4;
};

struct Aloadbuff {
    union anon__struct_81_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_87_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:24; // : bits 8-31
};

struct Asavebuff {
    union anon__struct_87_bitfield_1 field_0x0;
    uint addr;
};

union anon__struct_93_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint pad1:8; // : bits 8-15
    uint pad2:16; // : bits 16-31
};

struct Asetloop {
    union anon__struct_93_bitfield_1 field_0x0;
    uint addr;
};

union Acmd {
    struct Awords words;
    struct Aadpcm adpcm;
    struct Apolef polef;
    struct Aclearbuff clearbuff;
    struct Aenvelope envelope;
    struct Ainterleave interleave;
    struct Aloadbuff loadbuff;
    struct Aenvmixer envmixer;
    struct Aresample resample;
    struct Areverb reverb;
    struct Asavebuff savebuff;
    struct Asegment segment;
    struct Asetbuff setbuff;
    struct Asetvol setvol;
    struct Admemmove dmemmove;
    struct Aloadadpcm loadadpcm;
    struct Amixer mixer;
    struct Asetloop setloop;
    longlong force_union_align;
};

typedef enum enum_179 {
    GT_ALPHACOMPARE=1,
    GT_ALPHADITHER=4,
    GT_CLEAR=0,
    GT_COMBKEY=6,
    GT_CYCLETYPE=13,
    GT_PIPELINE=14,
    GT_RENDERMODE=3,
    GT_RGBDITHER=5,
    GT_TEXTCONV=7,
    GT_TEXTDETAIL=11,
    GT_TEXTFILT=8,
    GT_TEXTLOD=10,
    GT_TEXTLUT=9,
    GT_TEXTPERSP=12,
    GT_ZSRCSEL=2
} enum_179;

typedef union gtVtxOut gtVtxOut, *PgtVtxOut;

typedef struct gtVtxOut_t gtVtxOut_t, *PgtVtxOut_t;

struct gtVtxOut_t {
    short xscrn;
    short yscrn;
    int zscrn;
    short s;
    short t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

union gtVtxOut {
    struct gtVtxOut_t v;
    longlong force_structure_alignment;
};

typedef enum enum_179 gtStateOthermode_t;

typedef union gtGlobState gtGlobState, *PgtGlobState;

typedef struct gtGlobState_t gtGlobState_t, *PgtGlobState_t;

typedef union Vp Vp, *PVp;

typedef struct Vp_t Vp_t, *PVp_t;

struct Vp_t {
    short vscale[4];
    short vtrans[4];
};

union Vp {
    struct Vp_t vp;
    longlong force_structure_alignment;
};

struct gtGlobState_t {
    u16 perspNorm;
    u16 pad0;
    u32 flag;
    union Gfx rdpOthermode;
    u32 segBases[16];
    union Vp viewport;
    union Gfx * rdpCmds;
};

union gtGlobState {
    struct gtGlobState_t sp;
    longlong force_structure_alignment;
};

typedef union gtState gtState, *PgtState;

typedef struct gtState_t gtState_t, *PgtState_t;


// WARNING! conflicting data type names: /gbi.h/Mtx - /types.h/Mtx

struct gtState_t {
    u32 renderState;
    u32 textureState;
    u8 vtxCount;
    u8 vtxV0;
    u8 triCount;
    u8 flag;
    union Gfx * rdpCmds;
    union Gfx rdpOthermode;
    union Mtx transform;
};

union gtState {
    struct gtState_t sp;
    longlong force_structure_alignment;
};

typedef struct gtTriN gtTriN, *PgtTriN;

struct gtTriN {
    u8 v0;
    u8 v1;
    u8 v2;
    u8 flag;
};

typedef struct gtStateL_t gtStateL_t, *PgtStateL_t;

struct gtStateL_t {
    u32 renderState;
    u32 textureState;
    u8 vtxCount;
    u8 vtxV0;
    u8 triCount;
    u8 flag;
    union Gfx * rdpCmds;
    union Gfx rdpOthermode;
};

typedef struct gtGfx_t gtGfx_t, *PgtGfx_t;

typedef union Vtx Vtx, *PVtx;

typedef struct Vtx_t Vtx_t, *PVtx_t;

typedef struct Vtx_tn Vtx_tn, *PVtx_tn;

struct Vtx_t {
    short ob[3];
    ushort flag;
    short tc[2];
    uchar cn[4];
};

struct Vtx_tn {
    short ob[3];
    ushort flag;
    short tc[2];
    char n[3];
    uchar a;
};

union Vtx {
    struct Vtx_t v;
    struct Vtx_tn n;
    longlong force_structure_alignment;
};

struct gtGfx_t {
    union gtGlobState * gstatep;
    union gtState * statep;
    union Vtx * vtxp;
    struct gtTriN * trip;
};

typedef union gtGfx gtGfx, *PgtGfx;

union gtGfx {
    struct gtGfx_t obj;
    longlong force_structure_alignment;
};

typedef union gtStateL gtStateL, *PgtStateL;

union gtStateL {
    struct gtStateL_t sp;
    longlong force_structure_alignment;
};

#define GT_CULL_BACK 8192

#define GT_ZBUFFER 1

#define GT_DUMPTURBO_HANGAFTER 64

#define GT_FLAG_NO_XFM 2

#define GT_FLAG_NOMTX 1

#define GT_TEXTURE 2

#define GT_DUMPTURBO_NOTEXTURES 128

#define GT_FLAG_XFM_ONLY 4

#define GT_SHADING_SMOOTH 512

typedef struct sGlobalImageTable sGlobalImageTable, *PsGlobalImageTable;

struct sGlobalImageTable {
    char field_0x0[120];
    undefined field_0x78[168];
    undefined field_0x120[168];
    undefined field_0x1c8[168];
    undefined field_0x270[168];
    undefined field_0x318[168];
    undefined field_0x3c0[168];
    undefined field_0x468[168];
    undefined field_0x510[168];
    undefined field_0x5b8[168];
    undefined field_0x660[168];
    undefined field_0x708[168];
    undefined field_0x7b0[168];
    undefined field_0x858[168];
    undefined field_0x900[168];
    undefined field_0x9a8[168];
    undefined field_0xa50[120];
    struct sImageTableEntry genericimage[1];
    struct sImageTableEntry impactimages[20];
    struct sImageTableEntry explosion_smokeimages[6];
    struct sImageTableEntry scattered_explosions[5];
    struct sImageTableEntry flareimage1[1];
    struct sImageTableEntry flareimage2[1];
    struct sImageTableEntry flareimage3[1];
    struct sImageTableEntry flareimage4[1];
    struct sImageTableEntry flareimage5[1];
    struct sImageTableEntry ammo9mmimage[1];
    struct sImageTableEntry rifleammoimage[1];
    struct sImageTableEntry shotgunammoimage[1];
    struct sImageTableEntry knifeammoimage[1];
    struct sImageTableEntry glammoimage[1];
    struct sImageTableEntry rocketammoimage[1];
    struct sImageTableEntry genericmineammoimage[1];
    struct sImageTableEntry grenadeammoimage[1];
    struct sImageTableEntry magnumammoimage[1];
    struct sImageTableEntry goldengunammoimage[1];
    struct sImageTableEntry remotemineammoimage[1];
    struct sImageTableEntry timedmineammoimage[1];
    struct sImageTableEntry proxmineammoimage[1];
    struct sImageTableEntry tankammoimage[1];
    struct sImageTableEntry crosshairimage[1];
    struct sImageTableEntry betacrosshairimage[1];
    struct sImageTableEntry glassoverlayimage[2];
    struct sImageTableEntry monitorimages[50];
    struct sImageTableEntry skywaterimages[3];
    struct sImageTableEntry mainfolderimages[6];
    struct sImageTableEntry mpradarimages[1];
    struct sImageTableEntry mpcharselimages[64];
    struct sImageTableEntry mpstageselimages[17];
};

typedef struct astruct astruct, *Pastruct;

struct astruct {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined1 txtClipW; // Created by retype action
    undefined field_0x5;
    undefined1 txtClipH; // Created by retype action
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined1 aspect; // Created by retype action
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined1 width; // Created by retype action
    undefined field_0x1d;
    undefined1 height; // Created by retype action
    undefined field_0x1f;
    undefined1 ulx; // Created by retype action
    undefined field_0x21;
    undefined1 uly; // Created by retype action
    undefined field_0x23;
    int field_0x24;
};

typedef struct vis_command vis_command, *Pvis_command;

struct vis_command {
    byte type;
    byte size;
    undefined field_0x2;
    undefined field_0x3;
    int room;
};

typedef struct watchMenuObjectiveText watchMenuObjectiveText, *PwatchMenuObjectiveText;

typedef ushort u16.conflict;

struct watchMenuObjectiveText {
    u8 field_0x0;
    u8 field_0x1;
    u8 field_0x2;
    u8 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16.conflict text;
    struct watchMenuObjectiveText * nextentry;
};

typedef struct astruct_2 astruct_2, *Pastruct_2;

struct astruct_2 {
    u32 field_0x0;
    u32 field_0x4;
    float x;
    float y;
    float z;
};

typedef struct astruct_1 astruct_1, *Pastruct_1;

struct astruct_1 {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    undefined field_0x1d0;
    undefined field_0x1d1;
    undefined field_0x1d2;
    undefined field_0x1d3;
    undefined field_0x1d4;
    undefined field_0x1d5;
    undefined field_0x1d6;
    undefined field_0x1d7;
    undefined field_0x1d8;
    undefined field_0x1d9;
    undefined field_0x1da;
    undefined field_0x1db;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    undefined field_0x1e0;
    undefined field_0x1e1;
    undefined field_0x1e2;
    undefined field_0x1e3;
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    undefined field_0x1e8;
    undefined field_0x1e9;
    undefined field_0x1ea;
    undefined field_0x1eb;
    undefined field_0x1ec;
    undefined field_0x1ed;
    undefined field_0x1ee;
    undefined field_0x1ef;
    undefined field_0x1f0;
    undefined field_0x1f1;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    undefined field_0x1f8;
    undefined field_0x1f9;
    undefined field_0x1fa;
    undefined field_0x1fb;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    undefined field_0x200;
    undefined field_0x201;
    undefined field_0x202;
    undefined field_0x203;
    undefined field_0x204;
    undefined field_0x205;
    undefined field_0x206;
    undefined field_0x207;
    undefined field_0x208;
    undefined field_0x209;
    undefined field_0x20a;
    undefined field_0x20b;
    undefined field_0x20c;
    undefined field_0x20d;
    undefined field_0x20e;
    undefined field_0x20f;
    undefined field_0x210;
    undefined field_0x211;
    undefined field_0x212;
    undefined field_0x213;
    undefined field_0x214;
    undefined field_0x215;
    undefined field_0x216;
    undefined field_0x217;
    undefined field_0x218;
    undefined field_0x219;
    undefined field_0x21a;
    undefined field_0x21b;
    undefined field_0x21c;
    undefined field_0x21d;
    undefined field_0x21e;
    undefined field_0x21f;
    undefined field_0x220;
    undefined field_0x221;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    undefined field_0x228;
    undefined field_0x229;
    undefined field_0x22a;
    undefined field_0x22b;
    undefined field_0x22c;
    undefined field_0x22d;
    undefined field_0x22e;
    undefined field_0x22f;
    undefined field_0x230;
    undefined field_0x231;
    undefined field_0x232;
    undefined field_0x233;
    undefined field_0x234;
    undefined field_0x235;
    undefined field_0x236;
    undefined field_0x237;
    undefined field_0x238;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    undefined field_0x240;
    undefined field_0x241;
    undefined field_0x242;
    undefined field_0x243;
    undefined field_0x244;
    undefined field_0x245;
    undefined field_0x246;
    undefined field_0x247;
    undefined field_0x248;
    undefined field_0x249;
    undefined field_0x24a;
    undefined field_0x24b;
    undefined field_0x24c;
    undefined field_0x24d;
    undefined field_0x24e;
    undefined field_0x24f;
    undefined field_0x250;
    undefined field_0x251;
    undefined field_0x252;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    undefined field_0x258;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    undefined field_0x260;
    undefined field_0x261;
    undefined field_0x262;
    undefined field_0x263;
    undefined field_0x264;
    undefined field_0x265;
    undefined field_0x266;
    undefined field_0x267;
    undefined field_0x268;
    undefined field_0x269;
    undefined field_0x26a;
    undefined field_0x26b;
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    undefined field_0x274;
    undefined field_0x275;
    undefined field_0x276;
    undefined field_0x277;
    undefined field_0x278;
    undefined field_0x279;
    undefined field_0x27a;
    undefined field_0x27b;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    undefined field_0x280;
    undefined field_0x281;
    undefined field_0x282;
    undefined field_0x283;
    undefined field_0x284;
    undefined field_0x285;
    undefined field_0x286;
    undefined field_0x287;
    undefined field_0x288;
    undefined field_0x289;
    undefined field_0x28a;
    undefined field_0x28b;
    undefined field_0x28c;
    undefined field_0x28d;
    undefined field_0x28e;
    undefined field_0x28f;
    undefined field_0x290;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    undefined field_0x294;
    undefined field_0x295;
    undefined field_0x296;
    undefined field_0x297;
    undefined field_0x298;
    undefined field_0x299;
    undefined field_0x29a;
    undefined field_0x29b;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    undefined field_0x2a0;
    undefined field_0x2a1;
    undefined field_0x2a2;
    undefined field_0x2a3;
    undefined field_0x2a4;
    undefined field_0x2a5;
    undefined field_0x2a6;
    undefined field_0x2a7;
    undefined field_0x2a8;
    undefined field_0x2a9;
    undefined field_0x2aa;
    undefined field_0x2ab;
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    undefined field_0x2b0;
    undefined field_0x2b1;
    undefined field_0x2b2;
    undefined field_0x2b3;
    undefined field_0x2b4;
    undefined field_0x2b5;
    undefined field_0x2b6;
    undefined field_0x2b7;
    undefined field_0x2b8;
    undefined field_0x2b9;
    undefined field_0x2ba;
    undefined field_0x2bb;
    undefined field_0x2bc;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    undefined field_0x2c0;
    undefined field_0x2c1;
    undefined field_0x2c2;
    undefined field_0x2c3;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    undefined field_0x2c8;
    undefined field_0x2c9;
    undefined field_0x2ca;
    undefined field_0x2cb;
    undefined field_0x2cc;
    undefined field_0x2cd;
    undefined field_0x2ce;
    undefined field_0x2cf;
    undefined field_0x2d0;
    undefined field_0x2d1;
    undefined field_0x2d2;
    undefined field_0x2d3;
    undefined field_0x2d4;
    undefined field_0x2d5;
    undefined field_0x2d6;
    undefined field_0x2d7;
    undefined field_0x2d8;
    undefined field_0x2d9;
    undefined field_0x2da;
    undefined field_0x2db;
    undefined field_0x2dc;
    undefined field_0x2dd;
    undefined field_0x2de;
    undefined field_0x2df;
    undefined field_0x2e0;
    undefined field_0x2e1;
    undefined field_0x2e2;
    undefined field_0x2e3;
    undefined field_0x2e4;
    undefined field_0x2e5;
    undefined field_0x2e6;
    undefined field_0x2e7;
    undefined field_0x2e8;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;
    undefined field_0x2ec;
    undefined field_0x2ed;
    undefined field_0x2ee;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
    undefined field_0x2f4;
    undefined field_0x2f5;
    undefined field_0x2f6;
    undefined field_0x2f7;
    undefined field_0x2f8;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    undefined field_0x300;
    undefined field_0x301;
    undefined field_0x302;
    undefined field_0x303;
    undefined field_0x304;
    undefined field_0x305;
    undefined field_0x306;
    undefined field_0x307;
    undefined field_0x308;
    undefined field_0x309;
    undefined field_0x30a;
    undefined field_0x30b;
    undefined field_0x30c;
    undefined field_0x30d;
    undefined field_0x30e;
    undefined field_0x30f;
    undefined field_0x310;
    undefined field_0x311;
    undefined field_0x312;
    undefined field_0x313;
    undefined field_0x314;
    undefined field_0x315;
    undefined field_0x316;
    undefined field_0x317;
    undefined field_0x318;
    undefined field_0x319;
    undefined field_0x31a;
    undefined field_0x31b;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    undefined field_0x320;
    undefined field_0x321;
    undefined field_0x322;
    undefined field_0x323;
    undefined field_0x324;
    undefined field_0x325;
    undefined field_0x326;
    undefined field_0x327;
    undefined field_0x328;
    undefined field_0x329;
    undefined field_0x32a;
    undefined field_0x32b;
    undefined field_0x32c;
    undefined field_0x32d;
    undefined field_0x32e;
    undefined field_0x32f;
    undefined field_0x330;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    undefined field_0x338;
    undefined field_0x339;
    undefined field_0x33a;
    undefined field_0x33b;
    undefined field_0x33c;
    undefined field_0x33d;
    undefined field_0x33e;
    undefined field_0x33f;
    undefined field_0x340;
    undefined field_0x341;
    undefined field_0x342;
    undefined field_0x343;
    undefined field_0x344;
    undefined field_0x345;
    undefined field_0x346;
    undefined field_0x347;
    undefined field_0x348;
    undefined field_0x349;
    undefined field_0x34a;
    undefined field_0x34b;
    undefined field_0x34c;
    undefined field_0x34d;
    undefined field_0x34e;
    undefined field_0x34f;
    undefined field_0x350;
    undefined field_0x351;
    undefined field_0x352;
    undefined field_0x353;
    undefined field_0x354;
    undefined field_0x355;
    undefined field_0x356;
    undefined field_0x357;
    undefined field_0x358;
    undefined field_0x359;
    undefined field_0x35a;
    undefined field_0x35b;
    undefined field_0x35c;
    undefined field_0x35d;
    undefined field_0x35e;
    undefined field_0x35f;
    undefined field_0x360;
    undefined field_0x361;
    undefined field_0x362;
    undefined field_0x363;
    undefined field_0x364;
    undefined field_0x365;
    undefined field_0x366;
    undefined field_0x367;
    undefined field_0x368;
    undefined field_0x369;
    undefined field_0x36a;
    undefined field_0x36b;
    undefined field_0x36c;
    undefined field_0x36d;
    undefined field_0x36e;
    undefined field_0x36f;
    undefined field_0x370;
    undefined field_0x371;
    undefined field_0x372;
    undefined field_0x373;
    undefined field_0x374;
    undefined field_0x375;
    undefined field_0x376;
    undefined field_0x377;
    undefined field_0x378;
    undefined field_0x379;
    undefined field_0x37a;
    undefined field_0x37b;
    undefined field_0x37c;
    undefined field_0x37d;
    undefined field_0x37e;
    undefined field_0x37f;
    undefined field_0x380;
    undefined field_0x381;
    undefined field_0x382;
    undefined field_0x383;
    undefined field_0x384;
    undefined field_0x385;
    undefined field_0x386;
    undefined field_0x387;
    undefined field_0x388;
    undefined field_0x389;
    undefined field_0x38a;
    undefined field_0x38b;
    undefined field_0x38c;
    undefined field_0x38d;
    undefined field_0x38e;
    undefined field_0x38f;
    undefined field_0x390;
    undefined field_0x391;
    undefined field_0x392;
    undefined field_0x393;
    undefined field_0x394;
    undefined field_0x395;
    undefined field_0x396;
    undefined field_0x397;
    undefined field_0x398;
    undefined field_0x399;
    undefined field_0x39a;
    undefined field_0x39b;
    undefined field_0x39c;
    undefined field_0x39d;
    undefined field_0x39e;
    undefined field_0x39f;
    undefined field_0x3a0;
    undefined field_0x3a1;
    undefined field_0x3a2;
    undefined field_0x3a3;
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
    undefined field_0x3a8;
    undefined field_0x3a9;
    undefined field_0x3aa;
    undefined field_0x3ab;
    undefined field_0x3ac;
    undefined field_0x3ad;
    undefined field_0x3ae;
    undefined field_0x3af;
    undefined field_0x3b0;
    undefined field_0x3b1;
    undefined field_0x3b2;
    undefined field_0x3b3;
    undefined field_0x3b4;
    undefined field_0x3b5;
    undefined field_0x3b6;
    undefined field_0x3b7;
    undefined field_0x3b8;
    undefined field_0x3b9;
    undefined field_0x3ba;
    undefined field_0x3bb;
    undefined field_0x3bc;
    undefined field_0x3bd;
    undefined field_0x3be;
    undefined field_0x3bf;
    undefined field_0x3c0;
    undefined field_0x3c1;
    undefined field_0x3c2;
    undefined field_0x3c3;
    undefined field_0x3c4;
    undefined field_0x3c5;
    undefined field_0x3c6;
    undefined field_0x3c7;
    undefined field_0x3c8;
    undefined field_0x3c9;
    undefined field_0x3ca;
    undefined field_0x3cb;
    undefined field_0x3cc;
    undefined field_0x3cd;
    undefined field_0x3ce;
    undefined field_0x3cf;
    undefined field_0x3d0;
    undefined field_0x3d1;
    undefined field_0x3d2;
    undefined field_0x3d3;
    undefined field_0x3d4;
    undefined field_0x3d5;
    undefined field_0x3d6;
    undefined field_0x3d7;
    undefined field_0x3d8;
    undefined field_0x3d9;
    undefined field_0x3da;
    undefined field_0x3db;
    undefined field_0x3dc;
    undefined field_0x3dd;
    undefined field_0x3de;
    undefined field_0x3df;
    undefined field_0x3e0;
    undefined field_0x3e1;
    undefined field_0x3e2;
    undefined field_0x3e3;
    undefined field_0x3e4;
    undefined field_0x3e5;
    undefined field_0x3e6;
    undefined field_0x3e7;
    undefined field_0x3e8;
    undefined field_0x3e9;
    undefined field_0x3ea;
    undefined field_0x3eb;
    undefined field_0x3ec;
    undefined field_0x3ed;
    undefined field_0x3ee;
    undefined field_0x3ef;
    undefined field_0x3f0;
    undefined field_0x3f1;
    undefined field_0x3f2;
    undefined field_0x3f3;
    undefined field_0x3f4;
    undefined field_0x3f5;
    undefined field_0x3f6;
    undefined field_0x3f7;
    undefined field_0x3f8;
    undefined field_0x3f9;
    undefined field_0x3fa;
    undefined field_0x3fb;
    undefined field_0x3fc;
    undefined field_0x3fd;
    undefined field_0x3fe;
    undefined field_0x3ff;
    undefined field_0x400;
    undefined field_0x401;
    undefined field_0x402;
    undefined field_0x403;
    undefined field_0x404;
    undefined field_0x405;
    undefined field_0x406;
    undefined field_0x407;
    undefined field_0x408;
    undefined field_0x409;
    undefined field_0x40a;
    undefined field_0x40b;
    undefined field_0x40c;
    undefined field_0x40d;
    undefined field_0x40e;
    undefined field_0x40f;
    undefined field_0x410;
    undefined field_0x411;
    undefined field_0x412;
    undefined field_0x413;
    undefined field_0x414;
    undefined field_0x415;
    undefined field_0x416;
    undefined field_0x417;
    undefined field_0x418;
    undefined field_0x419;
    undefined field_0x41a;
    undefined field_0x41b;
    undefined field_0x41c;
    undefined field_0x41d;
    undefined field_0x41e;
    undefined field_0x41f;
    undefined field_0x420;
    undefined field_0x421;
    undefined field_0x422;
    undefined field_0x423;
    undefined field_0x424;
    undefined field_0x425;
    undefined field_0x426;
    undefined field_0x427;
    undefined field_0x428;
    undefined field_0x429;
    undefined field_0x42a;
    undefined field_0x42b;
    undefined field_0x42c;
    undefined field_0x42d;
    undefined field_0x42e;
    undefined field_0x42f;
    undefined field_0x430;
    undefined field_0x431;
    undefined field_0x432;
    undefined field_0x433;
    undefined field_0x434;
    undefined field_0x435;
    undefined field_0x436;
    undefined field_0x437;
    undefined field_0x438;
    undefined field_0x439;
    undefined field_0x43a;
    undefined field_0x43b;
    undefined field_0x43c;
    undefined field_0x43d;
    undefined field_0x43e;
    undefined field_0x43f;
    undefined field_0x440;
    undefined field_0x441;
    undefined field_0x442;
    undefined field_0x443;
    undefined field_0x444;
    undefined field_0x445;
    undefined field_0x446;
    undefined field_0x447;
    undefined field_0x448;
    undefined field_0x449;
    undefined field_0x44a;
    undefined field_0x44b;
    undefined field_0x44c;
    undefined field_0x44d;
    undefined field_0x44e;
    undefined field_0x44f;
    undefined field_0x450;
    undefined field_0x451;
    undefined field_0x452;
    undefined field_0x453;
    undefined field_0x454;
    undefined field_0x455;
    undefined field_0x456;
    undefined field_0x457;
    undefined field_0x458;
    undefined field_0x459;
    undefined field_0x45a;
    undefined field_0x45b;
    undefined field_0x45c;
    undefined field_0x45d;
    undefined field_0x45e;
    undefined field_0x45f;
    undefined field_0x460;
    undefined field_0x461;
    undefined field_0x462;
    undefined field_0x463;
    undefined field_0x464;
    undefined field_0x465;
    undefined field_0x466;
    undefined field_0x467;
    undefined field_0x468;
    undefined field_0x469;
    undefined field_0x46a;
    undefined field_0x46b;
    undefined field_0x46c;
    undefined field_0x46d;
    undefined field_0x46e;
    undefined field_0x46f;
    undefined field_0x470;
    undefined field_0x471;
    undefined field_0x472;
    undefined field_0x473;
    undefined field_0x474;
    undefined field_0x475;
    undefined field_0x476;
    undefined field_0x477;
    undefined field_0x478;
    undefined field_0x479;
    undefined field_0x47a;
    undefined field_0x47b;
    undefined field_0x47c;
    undefined field_0x47d;
    undefined field_0x47e;
    undefined field_0x47f;
    undefined field_0x480;
    undefined field_0x481;
    undefined field_0x482;
    undefined field_0x483;
    undefined field_0x484;
    undefined field_0x485;
    undefined field_0x486;
    undefined field_0x487;
    undefined field_0x488;
    undefined field_0x489;
    undefined field_0x48a;
    undefined field_0x48b;
    undefined field_0x48c;
    undefined field_0x48d;
    undefined field_0x48e;
    undefined field_0x48f;
    undefined field_0x490;
    undefined field_0x491;
    undefined field_0x492;
    undefined field_0x493;
    undefined field_0x494;
    undefined field_0x495;
    undefined field_0x496;
    undefined field_0x497;
    undefined field_0x498;
    undefined field_0x499;
    undefined field_0x49a;
    undefined field_0x49b;
    undefined field_0x49c;
    undefined field_0x49d;
    undefined field_0x49e;
    undefined field_0x49f;
    undefined field_0x4a0;
    undefined field_0x4a1;
    undefined field_0x4a2;
    undefined field_0x4a3;
    undefined field_0x4a4;
    undefined field_0x4a5;
    undefined field_0x4a6;
    undefined field_0x4a7;
    undefined field_0x4a8;
    undefined field_0x4a9;
    undefined field_0x4aa;
    undefined field_0x4ab;
    undefined field_0x4ac;
    undefined field_0x4ad;
    undefined field_0x4ae;
    undefined field_0x4af;
    undefined field_0x4b0;
    undefined field_0x4b1;
    undefined field_0x4b2;
    undefined field_0x4b3;
    undefined field_0x4b4;
    undefined field_0x4b5;
    undefined field_0x4b6;
    undefined field_0x4b7;
    undefined field_0x4b8;
    undefined field_0x4b9;
    undefined field_0x4ba;
    undefined field_0x4bb;
    undefined field_0x4bc;
    undefined field_0x4bd;
    undefined field_0x4be;
    undefined field_0x4bf;
    undefined field_0x4c0;
    undefined field_0x4c1;
    undefined field_0x4c2;
    undefined field_0x4c3;
    undefined field_0x4c4;
    undefined field_0x4c5;
    undefined field_0x4c6;
    undefined field_0x4c7;
    undefined field_0x4c8;
    undefined field_0x4c9;
    undefined field_0x4ca;
    undefined field_0x4cb;
    undefined field_0x4cc;
    undefined field_0x4cd;
    undefined field_0x4ce;
    undefined field_0x4cf;
    undefined field_0x4d0;
    undefined field_0x4d1;
    undefined field_0x4d2;
    undefined field_0x4d3;
    undefined field_0x4d4;
    undefined field_0x4d5;
    undefined field_0x4d6;
    undefined field_0x4d7;
    undefined field_0x4d8;
    undefined field_0x4d9;
    undefined field_0x4da;
    undefined field_0x4db;
    undefined field_0x4dc;
    undefined field_0x4dd;
    undefined field_0x4de;
    undefined field_0x4df;
    undefined field_0x4e0;
    undefined field_0x4e1;
    undefined field_0x4e2;
    undefined field_0x4e3;
    undefined field_0x4e4;
    undefined field_0x4e5;
    undefined field_0x4e6;
    undefined field_0x4e7;
    undefined field_0x4e8;
    undefined field_0x4e9;
    undefined field_0x4ea;
    undefined field_0x4eb;
    undefined field_0x4ec;
    undefined field_0x4ed;
    undefined field_0x4ee;
    undefined field_0x4ef;
    undefined field_0x4f0;
    undefined field_0x4f1;
    undefined field_0x4f2;
    undefined field_0x4f3;
    undefined field_0x4f4;
    undefined field_0x4f5;
    undefined field_0x4f6;
    undefined field_0x4f7;
    undefined field_0x4f8;
    undefined field_0x4f9;
    undefined field_0x4fa;
    undefined field_0x4fb;
    undefined field_0x4fc;
    undefined field_0x4fd;
    undefined field_0x4fe;
    undefined field_0x4ff;
    undefined field_0x500;
    undefined field_0x501;
    undefined field_0x502;
    undefined field_0x503;
    undefined field_0x504;
    undefined field_0x505;
    undefined field_0x506;
    undefined field_0x507;
    undefined field_0x508;
    undefined field_0x509;
    undefined field_0x50a;
    undefined field_0x50b;
    undefined field_0x50c;
    undefined field_0x50d;
    undefined field_0x50e;
    undefined field_0x50f;
    undefined field_0x510;
    undefined field_0x511;
    undefined field_0x512;
    undefined field_0x513;
    undefined field_0x514;
    undefined field_0x515;
    undefined field_0x516;
    undefined field_0x517;
    undefined field_0x518;
    undefined field_0x519;
    undefined field_0x51a;
    undefined field_0x51b;
    undefined field_0x51c;
    undefined field_0x51d;
    undefined field_0x51e;
    undefined field_0x51f;
    undefined field_0x520;
    undefined field_0x521;
    undefined field_0x522;
    undefined field_0x523;
    undefined field_0x524;
    undefined field_0x525;
    undefined field_0x526;
    undefined field_0x527;
    undefined field_0x528;
    undefined field_0x529;
    undefined field_0x52a;
    undefined field_0x52b;
    undefined field_0x52c;
    undefined field_0x52d;
    undefined field_0x52e;
    undefined field_0x52f;
    undefined field_0x530;
    undefined field_0x531;
    undefined field_0x532;
    undefined field_0x533;
    undefined field_0x534;
    undefined field_0x535;
    undefined field_0x536;
    undefined field_0x537;
    undefined field_0x538;
    undefined field_0x539;
    undefined field_0x53a;
    undefined field_0x53b;
    undefined field_0x53c;
    undefined field_0x53d;
    undefined field_0x53e;
    undefined field_0x53f;
    undefined field_0x540;
    undefined field_0x541;
    undefined field_0x542;
    undefined field_0x543;
    undefined field_0x544;
    undefined field_0x545;
    undefined field_0x546;
    undefined field_0x547;
    undefined field_0x548;
    undefined field_0x549;
    undefined field_0x54a;
    undefined field_0x54b;
    undefined field_0x54c;
    undefined field_0x54d;
    undefined field_0x54e;
    undefined field_0x54f;
    undefined field_0x550;
    undefined field_0x551;
    undefined field_0x552;
    undefined field_0x553;
    undefined field_0x554;
    undefined field_0x555;
    undefined field_0x556;
    undefined field_0x557;
    undefined field_0x558;
    undefined field_0x559;
    undefined field_0x55a;
    undefined field_0x55b;
    undefined field_0x55c;
    undefined field_0x55d;
    undefined field_0x55e;
    undefined field_0x55f;
    undefined field_0x560;
    undefined field_0x561;
    undefined field_0x562;
    undefined field_0x563;
    undefined field_0x564;
    undefined field_0x565;
    undefined field_0x566;
    undefined field_0x567;
    undefined field_0x568;
    undefined field_0x569;
    undefined field_0x56a;
    undefined field_0x56b;
    undefined field_0x56c;
    undefined field_0x56d;
    undefined field_0x56e;
    undefined field_0x56f;
    undefined field_0x570;
    undefined field_0x571;
    undefined field_0x572;
    undefined field_0x573;
    undefined field_0x574;
    undefined field_0x575;
    undefined field_0x576;
    undefined field_0x577;
    undefined field_0x578;
    undefined field_0x579;
    undefined field_0x57a;
    undefined field_0x57b;
    undefined field_0x57c;
    undefined field_0x57d;
    undefined field_0x57e;
    undefined field_0x57f;
    undefined field_0x580;
    undefined field_0x581;
    undefined field_0x582;
    undefined field_0x583;
    undefined field_0x584;
    undefined field_0x585;
    undefined field_0x586;
    undefined field_0x587;
    undefined field_0x588;
    undefined field_0x589;
    undefined field_0x58a;
    undefined field_0x58b;
    undefined field_0x58c;
    undefined field_0x58d;
    undefined field_0x58e;
    undefined field_0x58f;
    undefined field_0x590;
    undefined field_0x591;
    undefined field_0x592;
    undefined field_0x593;
    undefined field_0x594;
    undefined field_0x595;
    undefined field_0x596;
    undefined field_0x597;
    undefined field_0x598;
    undefined field_0x599;
    undefined field_0x59a;
    undefined field_0x59b;
    undefined field_0x59c;
    undefined field_0x59d;
    undefined field_0x59e;
    undefined field_0x59f;
    undefined field_0x5a0;
    undefined field_0x5a1;
    undefined field_0x5a2;
    undefined field_0x5a3;
    undefined field_0x5a4;
    undefined field_0x5a5;
    undefined field_0x5a6;
    undefined field_0x5a7;
    undefined field_0x5a8;
    undefined field_0x5a9;
    undefined field_0x5aa;
    undefined field_0x5ab;
    undefined field_0x5ac;
    undefined field_0x5ad;
    undefined field_0x5ae;
    undefined field_0x5af;
    undefined field_0x5b0;
    undefined field_0x5b1;
    undefined field_0x5b2;
    undefined field_0x5b3;
    undefined field_0x5b4;
    undefined field_0x5b5;
    undefined field_0x5b6;
    undefined field_0x5b7;
    undefined field_0x5b8;
    undefined field_0x5b9;
    undefined field_0x5ba;
    undefined field_0x5bb;
    undefined field_0x5bc;
    undefined field_0x5bd;
    undefined field_0x5be;
    undefined field_0x5bf;
    undefined field_0x5c0;
    undefined field_0x5c1;
    undefined field_0x5c2;
    undefined field_0x5c3;
    undefined field_0x5c4;
    undefined field_0x5c5;
    undefined field_0x5c6;
    undefined field_0x5c7;
    undefined field_0x5c8;
    undefined field_0x5c9;
    undefined field_0x5ca;
    undefined field_0x5cb;
    undefined field_0x5cc;
    undefined field_0x5cd;
    undefined field_0x5ce;
    undefined field_0x5cf;
    undefined field_0x5d0;
    undefined field_0x5d1;
    undefined field_0x5d2;
    undefined field_0x5d3;
    undefined field_0x5d4;
    undefined field_0x5d5;
    undefined field_0x5d6;
    undefined field_0x5d7;
    undefined field_0x5d8;
    undefined field_0x5d9;
    undefined field_0x5da;
    undefined field_0x5db;
    undefined field_0x5dc;
    undefined field_0x5dd;
    undefined field_0x5de;
    undefined field_0x5df;
    undefined field_0x5e0;
    undefined field_0x5e1;
    undefined field_0x5e2;
    undefined field_0x5e3;
    undefined field_0x5e4;
    undefined field_0x5e5;
    undefined field_0x5e6;
    undefined field_0x5e7;
    undefined field_0x5e8;
    undefined field_0x5e9;
    undefined field_0x5ea;
    undefined field_0x5eb;
    undefined field_0x5ec;
    undefined field_0x5ed;
    undefined field_0x5ee;
    undefined field_0x5ef;
    undefined field_0x5f0;
    undefined field_0x5f1;
    undefined field_0x5f2;
    undefined field_0x5f3;
    undefined field_0x5f4;
    undefined field_0x5f5;
    undefined field_0x5f6;
    undefined field_0x5f7;
    undefined field_0x5f8;
    undefined field_0x5f9;
    undefined field_0x5fa;
    undefined field_0x5fb;
    undefined field_0x5fc;
    undefined field_0x5fd;
    undefined field_0x5fe;
    undefined field_0x5ff;
    undefined field_0x600;
    undefined field_0x601;
    undefined field_0x602;
    undefined field_0x603;
    undefined field_0x604;
    undefined field_0x605;
    undefined field_0x606;
    undefined field_0x607;
    undefined field_0x608;
    undefined field_0x609;
    undefined field_0x60a;
    undefined field_0x60b;
    undefined field_0x60c;
    undefined field_0x60d;
    undefined field_0x60e;
    undefined field_0x60f;
    undefined field_0x610;
    undefined field_0x611;
    undefined field_0x612;
    undefined field_0x613;
    undefined field_0x614;
    undefined field_0x615;
    undefined field_0x616;
    undefined field_0x617;
    undefined field_0x618;
    undefined field_0x619;
    undefined field_0x61a;
    undefined field_0x61b;
    undefined field_0x61c;
    undefined field_0x61d;
    undefined field_0x61e;
    undefined field_0x61f;
    undefined field_0x620;
    undefined field_0x621;
    undefined field_0x622;
    undefined field_0x623;
    undefined field_0x624;
    undefined field_0x625;
    undefined field_0x626;
    undefined field_0x627;
    undefined field_0x628;
    undefined field_0x629;
    undefined field_0x62a;
    undefined field_0x62b;
    undefined field_0x62c;
    undefined field_0x62d;
    undefined field_0x62e;
    undefined field_0x62f;
    undefined field_0x630;
    undefined field_0x631;
    undefined field_0x632;
    undefined field_0x633;
    undefined field_0x634;
    undefined field_0x635;
    undefined field_0x636;
    undefined field_0x637;
    undefined field_0x638;
    undefined field_0x639;
    undefined field_0x63a;
    undefined field_0x63b;
    undefined field_0x63c;
    undefined field_0x63d;
    undefined field_0x63e;
    undefined field_0x63f;
    undefined field_0x640;
    undefined field_0x641;
    undefined field_0x642;
    undefined field_0x643;
    undefined field_0x644;
    undefined field_0x645;
    undefined field_0x646;
    undefined field_0x647;
    undefined field_0x648;
    undefined field_0x649;
    undefined field_0x64a;
    undefined field_0x64b;
    undefined field_0x64c;
    undefined field_0x64d;
    undefined field_0x64e;
    undefined field_0x64f;
    undefined field_0x650;
    undefined field_0x651;
    undefined field_0x652;
    undefined field_0x653;
    undefined field_0x654;
    undefined field_0x655;
    undefined field_0x656;
    undefined field_0x657;
    undefined field_0x658;
    undefined field_0x659;
    undefined field_0x65a;
    undefined field_0x65b;
    undefined field_0x65c;
    undefined field_0x65d;
    undefined field_0x65e;
    undefined field_0x65f;
    undefined field_0x660;
    undefined field_0x661;
    undefined field_0x662;
    undefined field_0x663;
    undefined field_0x664;
    undefined field_0x665;
    undefined field_0x666;
    undefined field_0x667;
    undefined field_0x668;
    undefined field_0x669;
    undefined field_0x66a;
    undefined field_0x66b;
    undefined field_0x66c;
    undefined field_0x66d;
    undefined field_0x66e;
    undefined field_0x66f;
    undefined field_0x670;
    undefined field_0x671;
    undefined field_0x672;
    undefined field_0x673;
    undefined field_0x674;
    undefined field_0x675;
    undefined field_0x676;
    undefined field_0x677;
    undefined field_0x678;
    undefined field_0x679;
    undefined field_0x67a;
    undefined field_0x67b;
    undefined field_0x67c;
    undefined field_0x67d;
    undefined field_0x67e;
    undefined field_0x67f;
    undefined field_0x680;
    undefined field_0x681;
    undefined field_0x682;
    undefined field_0x683;
    undefined field_0x684;
    undefined field_0x685;
    undefined field_0x686;
    undefined field_0x687;
    undefined field_0x688;
    undefined field_0x689;
    undefined field_0x68a;
    undefined field_0x68b;
    undefined field_0x68c;
    undefined field_0x68d;
    undefined field_0x68e;
    undefined field_0x68f;
    undefined field_0x690;
    undefined field_0x691;
    undefined field_0x692;
    undefined field_0x693;
    undefined field_0x694;
    undefined field_0x695;
    undefined field_0x696;
    undefined field_0x697;
    undefined field_0x698;
    undefined field_0x699;
    undefined field_0x69a;
    undefined field_0x69b;
    undefined field_0x69c;
    undefined field_0x69d;
    undefined field_0x69e;
    undefined field_0x69f;
    undefined field_0x6a0;
    undefined field_0x6a1;
    undefined field_0x6a2;
    undefined field_0x6a3;
    undefined field_0x6a4;
    undefined field_0x6a5;
    undefined field_0x6a6;
    undefined field_0x6a7;
    undefined field_0x6a8;
    undefined field_0x6a9;
    undefined field_0x6aa;
    undefined field_0x6ab;
    undefined field_0x6ac;
    undefined field_0x6ad;
    undefined field_0x6ae;
    undefined field_0x6af;
    undefined field_0x6b0;
    undefined field_0x6b1;
    undefined field_0x6b2;
    undefined field_0x6b3;
    undefined field_0x6b4;
    undefined field_0x6b5;
    undefined field_0x6b6;
    undefined field_0x6b7;
    undefined field_0x6b8;
    undefined field_0x6b9;
    undefined field_0x6ba;
    undefined field_0x6bb;
    undefined field_0x6bc;
    undefined field_0x6bd;
    undefined field_0x6be;
    undefined field_0x6bf;
    undefined field_0x6c0;
    undefined field_0x6c1;
    undefined field_0x6c2;
    undefined field_0x6c3;
    undefined field_0x6c4;
    undefined field_0x6c5;
    undefined field_0x6c6;
    undefined field_0x6c7;
    undefined field_0x6c8;
    undefined field_0x6c9;
    undefined field_0x6ca;
    undefined field_0x6cb;
    undefined field_0x6cc;
    undefined field_0x6cd;
    undefined field_0x6ce;
    undefined field_0x6cf;
    undefined field_0x6d0;
    undefined field_0x6d1;
    undefined field_0x6d2;
    undefined field_0x6d3;
    undefined field_0x6d4;
    undefined field_0x6d5;
    undefined field_0x6d6;
    undefined field_0x6d7;
    undefined field_0x6d8;
    undefined field_0x6d9;
    undefined field_0x6da;
    undefined field_0x6db;
    undefined field_0x6dc;
    undefined field_0x6dd;
    undefined field_0x6de;
    undefined field_0x6df;
    undefined field_0x6e0;
    undefined field_0x6e1;
    undefined field_0x6e2;
    undefined field_0x6e3;
    undefined field_0x6e4;
    undefined field_0x6e5;
    undefined field_0x6e6;
    undefined field_0x6e7;
    undefined field_0x6e8;
    undefined field_0x6e9;
    undefined field_0x6ea;
    undefined field_0x6eb;
    undefined field_0x6ec;
    undefined field_0x6ed;
    undefined field_0x6ee;
    undefined field_0x6ef;
    undefined field_0x6f0;
    undefined field_0x6f1;
    undefined field_0x6f2;
    undefined field_0x6f3;
    undefined field_0x6f4;
    undefined field_0x6f5;
    undefined field_0x6f6;
    undefined field_0x6f7;
    undefined field_0x6f8;
    undefined field_0x6f9;
    undefined field_0x6fa;
    undefined field_0x6fb;
    undefined field_0x6fc;
    undefined field_0x6fd;
    undefined field_0x6fe;
    undefined field_0x6ff;
    undefined field_0x700;
    undefined field_0x701;
    undefined field_0x702;
    undefined field_0x703;
    undefined field_0x704;
    undefined field_0x705;
    undefined field_0x706;
    undefined field_0x707;
    undefined field_0x708;
    undefined field_0x709;
    undefined field_0x70a;
    undefined field_0x70b;
    undefined field_0x70c;
    undefined field_0x70d;
    undefined field_0x70e;
    undefined field_0x70f;
    undefined field_0x710;
    undefined field_0x711;
    undefined field_0x712;
    undefined field_0x713;
    undefined field_0x714;
    undefined field_0x715;
    undefined field_0x716;
    undefined field_0x717;
    undefined field_0x718;
    undefined field_0x719;
    undefined field_0x71a;
    undefined field_0x71b;
    undefined field_0x71c;
    undefined field_0x71d;
    undefined field_0x71e;
    undefined field_0x71f;
    undefined field_0x720;
    undefined field_0x721;
    undefined field_0x722;
    undefined field_0x723;
    undefined field_0x724;
    undefined field_0x725;
    undefined field_0x726;
    undefined field_0x727;
    undefined field_0x728;
    undefined field_0x729;
    undefined field_0x72a;
    undefined field_0x72b;
    undefined field_0x72c;
    undefined field_0x72d;
    undefined field_0x72e;
    undefined field_0x72f;
    undefined field_0x730;
    undefined field_0x731;
    undefined field_0x732;
    undefined field_0x733;
    undefined field_0x734;
    undefined field_0x735;
    undefined field_0x736;
    undefined field_0x737;
    undefined field_0x738;
    undefined field_0x739;
    undefined field_0x73a;
    undefined field_0x73b;
    undefined field_0x73c;
    undefined field_0x73d;
    undefined field_0x73e;
    undefined field_0x73f;
    undefined field_0x740;
    undefined field_0x741;
    undefined field_0x742;
    undefined field_0x743;
    undefined field_0x744;
    undefined field_0x745;
    undefined field_0x746;
    undefined field_0x747;
    undefined field_0x748;
    undefined field_0x749;
    undefined field_0x74a;
    undefined field_0x74b;
    undefined field_0x74c;
    undefined field_0x74d;
    undefined field_0x74e;
    undefined field_0x74f;
    undefined field_0x750;
    undefined field_0x751;
    undefined field_0x752;
    undefined field_0x753;
    undefined field_0x754;
    undefined field_0x755;
    undefined field_0x756;
    undefined field_0x757;
    undefined field_0x758;
    undefined field_0x759;
    undefined field_0x75a;
    undefined field_0x75b;
    undefined field_0x75c;
    undefined field_0x75d;
    undefined field_0x75e;
    undefined field_0x75f;
    undefined field_0x760;
    undefined field_0x761;
    undefined field_0x762;
    undefined field_0x763;
    undefined field_0x764;
    undefined field_0x765;
    undefined field_0x766;
    undefined field_0x767;
    undefined field_0x768;
    undefined field_0x769;
    undefined field_0x76a;
    undefined field_0x76b;
    undefined field_0x76c;
    undefined field_0x76d;
    undefined field_0x76e;
    undefined field_0x76f;
    undefined field_0x770;
    undefined field_0x771;
    undefined field_0x772;
    undefined field_0x773;
    undefined field_0x774;
    undefined field_0x775;
    undefined field_0x776;
    undefined field_0x777;
    undefined field_0x778;
    undefined field_0x779;
    undefined field_0x77a;
    undefined field_0x77b;
    undefined field_0x77c;
    undefined field_0x77d;
    undefined field_0x77e;
    undefined field_0x77f;
    undefined field_0x780;
    undefined field_0x781;
    undefined field_0x782;
    undefined field_0x783;
    undefined field_0x784;
    undefined field_0x785;
    undefined field_0x786;
    undefined field_0x787;
    undefined field_0x788;
    undefined field_0x789;
    undefined field_0x78a;
    undefined field_0x78b;
    undefined field_0x78c;
    undefined field_0x78d;
    undefined field_0x78e;
    undefined field_0x78f;
    undefined field_0x790;
    undefined field_0x791;
    undefined field_0x792;
    undefined field_0x793;
    undefined field_0x794;
    undefined field_0x795;
    undefined field_0x796;
    undefined field_0x797;
    undefined field_0x798;
    undefined field_0x799;
    undefined field_0x79a;
    undefined field_0x79b;
    undefined field_0x79c;
    undefined field_0x79d;
    undefined field_0x79e;
    undefined field_0x79f;
    undefined field_0x7a0;
    undefined field_0x7a1;
    undefined field_0x7a2;
    undefined field_0x7a3;
    undefined field_0x7a4;
    undefined field_0x7a5;
    undefined field_0x7a6;
    undefined field_0x7a7;
    undefined field_0x7a8;
    undefined field_0x7a9;
    undefined field_0x7aa;
    undefined field_0x7ab;
    undefined field_0x7ac;
    undefined field_0x7ad;
    undefined field_0x7ae;
    undefined field_0x7af;
    undefined field_0x7b0;
    undefined field_0x7b1;
    undefined field_0x7b2;
    undefined field_0x7b3;
    undefined field_0x7b4;
    undefined field_0x7b5;
    undefined field_0x7b6;
    undefined field_0x7b7;
    undefined field_0x7b8;
    undefined field_0x7b9;
    undefined field_0x7ba;
    undefined field_0x7bb;
    undefined field_0x7bc;
    undefined field_0x7bd;
    undefined field_0x7be;
    undefined field_0x7bf;
    undefined field_0x7c0;
    undefined field_0x7c1;
    undefined field_0x7c2;
    undefined field_0x7c3;
    undefined field_0x7c4;
    undefined field_0x7c5;
    undefined field_0x7c6;
    undefined field_0x7c7;
    undefined field_0x7c8;
    undefined field_0x7c9;
    undefined field_0x7ca;
    undefined field_0x7cb;
    undefined field_0x7cc;
    undefined field_0x7cd;
    undefined field_0x7ce;
    undefined field_0x7cf;
    undefined field_0x7d0;
    undefined field_0x7d1;
    undefined field_0x7d2;
    undefined field_0x7d3;
    undefined field_0x7d4;
    undefined field_0x7d5;
    undefined field_0x7d6;
    undefined field_0x7d7;
    undefined field_0x7d8;
    undefined field_0x7d9;
    undefined field_0x7da;
    undefined field_0x7db;
    undefined field_0x7dc;
    undefined field_0x7dd;
    undefined field_0x7de;
    undefined field_0x7df;
    undefined field_0x7e0;
    undefined field_0x7e1;
    undefined field_0x7e2;
    undefined field_0x7e3;
    undefined field_0x7e4;
    undefined field_0x7e5;
    undefined field_0x7e6;
    undefined field_0x7e7;
    undefined field_0x7e8;
    undefined field_0x7e9;
    undefined field_0x7ea;
    undefined field_0x7eb;
    undefined field_0x7ec;
    undefined field_0x7ed;
    undefined field_0x7ee;
    undefined field_0x7ef;
    undefined2 vidwidth;
    undefined2 vidheight;
    short vidulx;
    word viduly;
};


// WARNING! conflicting data type names: /SYNTHINTERNALS.H/ALResampler - /_CAPTURED_FROM_ge007.u.old.elf/ALResampler


// WARNING! conflicting data type names: /SYNTHINTERNALS.H/ALEnvMixer_s - /_CAPTURED_FROM_ge007.u.old.elf/ALEnvMixer_s

typedef struct ALEnvMixer_s ALEnvMixer;

typedef struct ALSave_s ALSave_s, *PALSave_s;

typedef struct ALSave_s ALSave;

typedef struct ALFilter_s ALFilter;

struct ALSave_s {
    ALFilter filter;
    s32 dramout;
    s32 first;
};

typedef struct ALFreeParam ALFreeParam, *PALFreeParam;

struct ALFreeParam {
    struct ALParam_s * next;
    s32 delta;
    s16 type;
    struct PVoice_s * pvoice;
};

typedef struct ALParam_s ALParam;

typedef struct ALDelay ALDelay, *PALDelay;

typedef struct ALLowPass ALLowPass, *PALLowPass;

typedef union _union_213 _union_213, *P_union_213;

typedef short POLEF_STATE[4];

struct ALDelay {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    struct ALLowPass * lp;
    ALResampler * rs;
};

union _union_213 {
    s16 fccoef[16];
    s64 force_aligned;
};

struct ALLowPass {
    s16 fc;
    s16 fgain;
    union _union_213 fcvec;
    POLEF_STATE * fstate;
    s32 first;
};

typedef struct ALAuxBus_s ALAuxBus_s, *PALAuxBus_s;

typedef struct ALAuxBus_s ALAuxBus;

struct ALAuxBus_s {
};

typedef struct ALFx ALFx, *PALFx;

typedef s32 (* ALSetFXParam)(void *, s32, void *);

struct ALFx {
    struct ALFilter_s filter;
    s16 * base;
    s16 * input;
    u32 length;
    struct ALDelay * delay;
    u8 section_count;
    ALSetFXParam paramHdl;
};

typedef struct ALLoadFilter ALLoadFilter, *PALLoadFilter;

struct ALLoadFilter {
    ALFilter filter;
    ADPCM_STATE * state;
    ADPCM_STATE * lstate;
    struct ALRawLoop loop;
    struct ALWaveTable_s * table;
    s32 bookSize;
    ALDMAproc dma;
    void * dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
};

typedef struct ALMainBus_s ALMainBus_s, *PALMainBus_s;

typedef struct ALMainBus_s ALMainBus;

struct ALMainBus_s {
};

typedef struct HeapInfo HeapInfo, *PHeapInfo;

struct HeapInfo {
    s32 magic;
    s32 size;
    u8 * file;
    s32 line;
    s32 count;
    s32 pad0;
    s32 pad1;
    s32 pad2;
};


// WARNING! conflicting data type names: /SYNTHINTERNALS.H/PVoice - /_CAPTURED_FROM_ge007.u.old.elf/PVoice


// WARNING! conflicting data type names: /SYNTHINTERNALS.H/ALSetParam - /_CAPTURED_FROM_ge007.u.old.elf/ALSetParam

typedef union _union_196 _union_196, *P_union_196;

union _union_196 {
    f32 f;
    s32 i;
};

typedef union _union_195 _union_195, *P_union_195;

union _union_195 {
    f32 f;
    s32 i;
};

typedef union _union_194 _union_194, *P_union_194;

union _union_194 {
    f32 f;
    s32 i;
};

typedef enum enum_191 {
    AL_ADPCM=0,
    AL_AUXBUS=6,
    AL_BUFFER=2,
    AL_ENVMIX=4,
    AL_FX=5,
    AL_MAINBUS=7,
    AL_RESAMPLE=1,
    AL_SAVE=3
} enum_191;

typedef enum enum_190 {
    AL_FILTER_ADD_SOURCE=2,
    AL_FILTER_ADD_UPDATE=3,
    AL_FILTER_FREE_VOICE=0,
    AL_FILTER_RESET=4,
    AL_FILTER_SET_DRAM=6,
    AL_FILTER_SET_FXAMT=16,
    AL_FILTER_SET_PAN=12,
    AL_FILTER_SET_PITCH=7,
    AL_FILTER_SET_SOURCE=1,
    AL_FILTER_SET_STATE=10,
    AL_FILTER_SET_UNITY_PITCH=8,
    AL_FILTER_SET_VOLUME=11,
    AL_FILTER_SET_WAVETABLE=5,
    AL_FILTER_START=9,
    AL_FILTER_START_VOICE=14,
    AL_FILTER_START_VOICE_ALT=13,
    AL_FILTER_STOP_VOICE=15
} enum_190;

typedef struct ALStartParamAlt ALStartParamAlt, *PALStartParamAlt;

typedef u8 ALPan;

struct ALStartParamAlt {
    struct ALParam_s * next;
    s32 delta;
    s16 type;
    s16 unity;
    f32 pitch;
    s16 volume;
    ALPan pan;
    u8 fxMix;
    s32 samples;
    struct ALWaveTable_s * wave;
};

typedef struct ALStartParam ALStartParam, *PALStartParam;

struct ALStartParam {
    struct ALParam_s * next;
    s32 delta;
    s16 type;
    s16 unity;
    struct ALWaveTable_s * wave;
};

typedef struct ALResampler_s ALResampler_s, *PALResampler_s;

struct ALResampler_s {
    ALFilter filter;
    RESAMPLE_STATE * state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
    ALParam * ctrlList;
    ALParam * ctrlTail;
    s32 motion;
};


// WARNING! conflicting data type names: /SYNTHINTERNALS.H/ALCmdHandler - /_CAPTURED_FROM_ge007.u.old.elf/ALCmdHandler

typedef union _union_197 _union_197, *P_union_197;

union _union_197 {
    f32 f;
    s32 i;
};

#define AL_AUX_R_OUT 2048

#define AL_MAIN_R_OUT 1408

#define AL_AUX_L_OUT 1728

#define AL_MAX_AUX_BUS_SOURCES 8

#define AL_MAX_MAIN_BUS_SOURCES 1

#define AL_MAX_ADPCM_STATES 3

#define AL_DECODER_IN 0

#define AL_RESAMPLER_OUT 0

#define AL_MAX_AUX_BUS_FX 1

#define AL_DECODER_OUT 320

#define AL_CACHE_ALIGN 15

#define AL_MAX_RSP_SAMPLES 160

#define AL_MAIN_L_OUT 1088

#define AL_TEMP_0 0

#define AL_TEMP_2 640

#define AL_TEMP_1 320

#define ai_list_end 4

#define SPAWN_00001000 4096

#define if_door_has_been_opened_before_LENGTH 3

#define bond_equip_item_cinema_LENGTH 2

#define guard_try_fire_or_aim_at_target_update_LENGTH 6

#define screen_fade_from_black_ID 219

#define GLIST_FIRE_RAND_ANIM_SUBROUTINE 6

#define jump_to_ai_list_LENGTH 4

#define guard_runs_to_pad_ID 28

#define bond_hide_weapons_ID 237

#define if_system_power_time_less_than_ID 116

#define bond_killed_in_action_LENGTH 1

#define object_flags_2_set_on_LENGTH 6

#define guard_kneel_ID 9

#define if_level_id_less_than_LENGTH 3

#define if_local_byte_1_less_than_ID 132

#define trigger_fade_and_exit_level_on_button_press_LENGTH 1

#define hud_countdown_start_LENGTH 1

#define hud_show_all_and_unlock_controls_and_resume_mission_time_ID 216

#define if_bond_y_pos_less_than_LENGTH 4

#define if_guard_in_room_with_chr_ID 64

#define object_drop_from_chr_LENGTH 2

#define guard_set_grenade_probability_LENGTH 2

#define ANIM_REVERSE_LOOPING_ANIMATION 128

#define camera_look_at_bond_from_pad_LENGTH 3

#define if_guard_heard_bond_within_last_10_secs_ID 63

#define ai_list_end_ID 4

#define ANIM_PLAY_SFX 8

#define hud_countdown_hide_LENGTH 1

#define if_level_id_greater_than_ID 119

#define if_object_exists_LENGTH 3

#define if_object_was_activated_ID 92

#define SPAWN_02000000 33554432

#define goto_next_LENGTH 2

#define guard_try_spawning_hat_LENGTH 8

#define if_chr_health_greater_than_LENGTH 4

#define vehicle_start_path_LENGTH 2

#define guard_sprints_to_pad_LENGTH 3

#define guard_set_argh_rating_ID 146

#define if_item_is_stationary_within_level_LENGTH 3

#define guard_try_running_to_chr_position_LENGTH 3

#define chr_try_spawning_clone_ID 193

#define local_byte_2_subtract_LENGTH 2

#define if_local_byte_1_less_than_random_seed_ID 133

#define if_guard_distance_to_chr_greater_than_ID 80

#define guard_walks_to_pad_ID 30

#define SPAWN_SUNGLASSES 1

#define guard_set_chr_num_LENGTH 2

#define if_chr_distance_to_pad_greater_than_ID 78

#define chr_equip_object_LENGTH 3

#define if_local_byte_2_less_than_ID 137

#define if_chr_distance_to_pad_greater_than_LENGTH 7

#define hud_hide_and_lock_controls_and_pause_mission_time_ID 215

#define objective_bitfield_set_on_LENGTH 5

#define if_level_id_greater_than_LENGTH 3

#define guard_try_firing_roll_ID 19

#define chr_drop_all_held_items_ID 98

#define trigger_fade_and_exit_level_on_button_press_ID 234

#define if_guard_hits_less_than_LENGTH 3

#define hud_countdown_start_ID 185

#define if_chr_does_not_exist_ID 49

#define guard_try_spawning_item_LENGTH 9

#define if_guard_is_on_screen_ID 66

#define guard_looks_around_self_LENGTH 1

#define GLIST_END_ROUTINE 1

#define if_door_state_equal_LENGTH 4

#define object_activate_LENGTH 2

#define chr_hit_body_part_with_item_damage_ID 24

#define jump_to_ai_list_ID 5

#define if_game_difficulty_less_than_LENGTH 3

#define object_flags_1_set_on_LENGTH 6

#define guard_surrenders_ID 33

#define tv_change_screen_bank_ID 208

#define if_hud_countdown_less_than_LENGTH 4

#define SPAWN_00000100 256

#define guard_remove_fade_ID 34

#define GLIST_RUN_TO_BOND_SUBROUTINE 8

#define if_item_is_attached_to_object_ID 88

#define chr_hit_chr_body_part_with_held_item_LENGTH 4

#define bond_collect_object_ID 99

#define guard_try_running_to_bond_position_ID 40

#define guard_play_animation_LENGTH 9

#define HIT_RIGHT_HAND 12

#define guard_try_walking_to_bond_position_LENGTH 2

#define door_set_lock_LENGTH 3

#define guard_set_accuracy_rating_LENGTH 2

#define if_guard_counter_clockwise_direction_from_bond_greater_than_ID 74

#define AI_LIST_OBJ_START 4096

#define alarm_on_LENGTH 1

#define object_flags_1_set_off_ID 164

#define if_bond_health_greater_than_LENGTH 3

#define AI_LIST_CHR_START 1025

#define if_bond_collected_object_LENGTH 3

#define if_room_containing_pad_is_on_screen_ID 68

#define if_chr_was_damaged_since_last_check_ID 126

#define guard_try_spawning_hat_ID 192

#define exit_level_ID 210

#define guard_try_throwing_grenade_ID 26

#define if_bond_item_total_ammo_less_than_ID 226

#define if_chr_bitfield_is_set_on_ID 153

#define jump_to_return_ai_list_ID 7

#define TARGET_FRONT_OF_CHR 2

#define if_chr_health_less_than_LENGTH 4

#define guard_try_throwing_grenade_LENGTH 2

#define guard_try_sprinting_to_bond_position_LENGTH 2

#define HIT_RIGHT_THIGH 6

#define chr_remove_item_in_hand_ID 224

#define chr_hit_chr_body_part_with_held_item_ID 25

#define if_bond_item_total_ammo_less_than_LENGTH 4

#define chr_flags_set_on_LENGTH 6

#define if_guard_counter_clockwise_direction_from_bond_less_than_ID 73

#define local_timer_reset_LENGTH 1

#define if_bond_in_room_with_pad_LENGTH 4

#define object_destroy_LENGTH 2

#define guard_sprints_to_pad_ID 31

#define GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE 2

#define hud_show_all_and_unlock_controls_and_resume_mission_time_LENGTH 1

#define guard_flags_set_on_ID 157

#define sfx_stop_channel_ID 201

#define if_level_id_less_than_ID 118

#define HIT_LEFT_FOOT 1

#define removed_command27_LENGTH 2

#define guard_set_armour_ID 144

#define gas_leak_and_fade_fog_LENGTH 1

#define goto_first_ID 1

#define chr_remove_instant_ID 35

#define if_bond_used_gadget_on_object_LENGTH 3

#define if_bond_health_less_than_LENGTH 3

#define local_byte_1_set_ID 129

#define ANIM_MIRROR 1

#define hud_countdown_set_ID 183

#define guard_try_firing_run_ID 18

#define bond_collect_object_LENGTH 2

#define if_random_seed_less_than_LENGTH 3

#define if_guard_counter_clockwise_direction_to_bond_greater_than_LENGTH 3

#define vehicle_speed_ID 204

#define SPAWN_00008000 32768

#define HIT_HEAD 8

#define SPAWN_40000000 1073741824

#define ANIM_UNKNOWN 2

#define ANIM_NO_TRANSLATION 64

#define chr_drop_all_concealed_items_ID 97

#define if_objective_all_completed_LENGTH 2

#define vehicle_start_path_ID 203

#define if_object_flags_2_is_set_on_LENGTH 7

#define if_guard_hits_missed_less_than_LENGTH 3

#define object_move_to_pad_ID 101

#define removed_command2B_LENGTH 2

#define local_timer_reset_start_ID 174

#define chr_show_all_LENGTH 1

#define DOOR_STATE_OPEN 2

#define if_local_byte_2_less_than_random_seed_ID 138

#define if_guard_heard_bond_ID 57

#define if_sfx_channel_volume_less_than_ID 202

#define chr_show_all_ID 222

#define if_guard_distance_to_chr_greater_than_LENGTH 5

#define if_hud_countdown_has_stopped_LENGTH 2

#define guard_set_pad_preset_LENGTH 3

#define debug_log_LENGTH 50

#define guard_try_walking_to_chr_position_ID 45

#define hud_countdown_hide_ID 182

#define chr_hide_all_LENGTH 1

#define SPAWN_01000000 16777216

#define screen_fade_to_black_ID 218

#define guard_try_setting_chr_preset_to_guard_within_distance_ID 81

#define if_chr_was_shot_since_last_check_ID 248

#define guard_set_health_total_LENGTH 3

#define HUD_SHOW_TEXT_BOTTOM 2

#define HIT_RIGHT_ARM 13

#define guard_try_fire_or_aim_at_target_update_ID 22

#define if_system_power_time_greater_than_ID 117

#define sfx_fade_channel_volume_ID 200

#define if_chr_does_not_exist_LENGTH 3

#define guard_try_sprinting_to_chr_position_ID 46

#define if_number_of_active_players_less_than_ID 225

#define GLIST_SPAWN_CLONE_OR_RUN_TO_BOND 11

#define guard_runs_to_pad_preset_LENGTH 1

#define goto_next_ID 0

#define exit_level_LENGTH 1

#define if_door_has_been_opened_before_ID 105

#define if_folder_actor_is_equal_LENGTH 3

#define if_local_byte_2_less_than_random_seed_LENGTH 2

#define local_byte_1_subtract_LENGTH 2

#define HIT_LEFT_THIGH 3

#define if_guard_room_containing_self_is_on_screen_LENGTH 2

#define if_item_is_attached_to_object_LENGTH 4

#define guard_try_sidestepping_ID 14

#define if_guard_sees_bond_LENGTH 2

#define if_bond_damage_and_pickups_disabled_ID 243

#define if_guard_hits_missed_greater_than_ID 123

#define DOOR_STATE_OPENING 8

#define guard_try_unknown6E_LENGTH 3

#define door_open_LENGTH 2

#define ANIM_IDLE_POSE_WHEN_COMPLETE 16

#define if_camera_is_in_intro_ID 206

#define if_random_seed_less_than_ID 52

#define if_guard_and_bond_within_line_of_sight_LENGTH 2

#define if_guard_sees_bond_ID 50

#define if_alarm_is_on_ID 55

#define if_guard_is_firing_ID 232

#define ANIM_DEFAULT_INTERPOLATION 16

#define SPAWN_20000000 536870912

#define if_guard_bitfield_is_set_on_LENGTH 3

#define chr_bitfield_set_on_LENGTH 3

#define guard_try_fire_or_aim_at_target_LENGTH 6

#define guard_set_hearing_scale_LENGTH 3

#define hud_countdown_show_ID 181

#define chr_flags_set_off_ID 161

#define if_object_exists_ID 90

#define if_guard_heard_bond_LENGTH 2

#define if_chr_dying_or_dead_ID 48

#define guard_walks_to_pad_LENGTH 3

#define guard_try_sidestepping_LENGTH 2

#define local_byte_1_set_LENGTH 2

#define music_xtrack_play_ID 244

#define alarm_on_ID 37

#define local_byte_1_add_ID 130

#define ai_list_end_LENGTH 1

#define object_flags_2_set_off_ID 167

#define sfx_set_channel_volume_LENGTH 6

#define guard_remove_fade_LENGTH 1

#define if_bond_distance_to_pad_greater_than_LENGTH 6

#define guard_try_fire_or_aim_at_target_kneel_ID 21

#define if_guard_hits_greater_than_ID 121

#define if_guard_hits_less_than_ID 120

#define if_guard_flags_is_set_on_ID 159

#define DOOR_STATE_CLOSING 4

#define if_guard_distance_to_bond_less_than_LENGTH 4

#define if_guard_see_another_guard_die_ID 59

#define if_local_timer_less_than_ID 179

#define if_alarm_is_on_unused_LENGTH 2

#define if_chr_health_greater_than_ID 125

#define if_local_timer_less_than_LENGTH 5

#define object_rocket_launch_LENGTH 2

#define if_bond_collected_object_ID 86

#define guard_try_facing_target_ID 23

#define SPAWN_00004000 16384

#define screen_fade_to_black_LENGTH 1

#define if_guard_and_bond_within_line_of_sight_ID 60

#define sfx_emit_from_pad_LENGTH 6

#define SPAWN_04000000 67108864

#define if_local_timer_has_stopped_LENGTH 2

#define if_bond_distance_to_pad_less_than_LENGTH 6

#define alarm_off_ID 38

#define TARGET_PAD 8

#define if_local_timer_greater_than_LENGTH 5

#define if_guard_room_containing_self_is_on_screen_ID 67

#define camera_return_to_bond_ID 211

#define ANIM_LOOP_HOLD_LAST_FRAME 4

#define local_timer_start_LENGTH 1

#define GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE 4

#define sfx_emit_from_pad_ID 198

#define guard_try_running_to_side_LENGTH 2

#define TARGET_CHR 4

#define guard_raises_arms_LENGTH 1

#define guard_try_sprinting_to_chr_position_LENGTH 3

#define if_bond_used_gadget_on_object_ID 93

#define SPAWN_00400000 4194304

#define if_objective_bitfield_is_set_on_ID 156

#define local_byte_1_add_LENGTH 2

#define if_chr_flags_is_set_on_ID 162

#define SPAWN_08000000 134217728

#define if_door_lock_equal_LENGTH 4

#define sfx_emit_from_object_ID 197

#define sfx_play_ID 196

#define door_open_ID 102

#define if_object_in_room_with_pad_ID 230

#define if_chr_flags_is_set_on_LENGTH 7

#define if_guard_heard_bond_within_last_10_secs_LENGTH 2

#define object_move_to_pad_LENGTH 4

#define door_close_LENGTH 2

#define if_mission_time_greater_than_LENGTH 4

#define SPAWN_00000080 128

#define guard_set_armour_LENGTH 3

#define if_objective_all_completed_ID 241

#define local_timer_reset_start_LENGTH 1

#define door_unset_lock_ID 107

#define if_guard_counter_clockwise_direction_to_bond_greater_than_ID 72

#define credits_roll_LENGTH 1

#define sfx_set_channel_volume_ID 199

#define guard_flags_set_off_LENGTH 5

#define vehicle_speed_LENGTH 5

#define chr_try_spawning_clone_LENGTH 5

#define if_object_was_activated_LENGTH 3

#define text_print_bottom_ID 194

#define guard_try_triggering_alarm_at_pad_LENGTH 4

#define chr_try_spawning_next_to_unseen_chr_LENGTH 11

#define sfx_stop_channel_LENGTH 2

#define camera_return_to_bond_LENGTH 1

#define if_object_flags_2_is_set_on_ID 168

#define gas_leak_and_switch_fog_LENGTH 1

#define GLIST_RUN_TO_BOND_AND_FIRE 12

#define text_print_bottom_LENGTH 3

#define SPAWN_00002000 8192

#define bond_set_locked_velocity_LENGTH 3

#define if_chr_was_damaged_since_last_check_LENGTH 3

#define if_guard_see_another_guard_shot_LENGTH 2

#define if_guard_shot_from_bond_missed_LENGTH 2

#define bond_killed_in_action_ID 249

#define if_camera_is_in_bond_swirl_ID 207

#define SPAWN_SUNGLASSES_RANDOM 2

#define trigger_explosions_around_bond_LENGTH 1

#define if_game_difficulty_greater_than_LENGTH 3

#define if_chr_was_shot_since_last_check_LENGTH 3

#define chr_try_spawning_at_pad_LENGTH 12

#define screen_fade_from_black_LENGTH 1

#define bond_hide_weapons_LENGTH 1

#define HUD_SHOW_TEXT_TOP 1

#define if_chr_distance_to_pad_less_than_LENGTH 7

#define local_byte_2_set_LENGTH 2

#define if_game_difficulty_less_than_ID 112

#define if_door_lock_equal_ID 108

#define if_gas_is_leaking_LENGTH 2

#define SPAWN_00000040 64

#define if_guard_shot_from_bond_missed_ID 70

#define goto_first_LENGTH 2

#define guard_points_at_bond_ID 12

#define local_timer_stop_ID 176

#define if_bond_distance_to_pad_greater_than_ID 83

#define SPAWN_IGNORE_PAD_SIGHT_CHECK 16

#define music_xtrack_play_LENGTH 4

#define if_guard_is_targeted_by_bond_LENGTH 2

#define object_activate_ID 94

#define if_guard_counter_clockwise_direction_to_bond_less_than_ID 71

#define guard_set_pad_preset_ID 171

#define object_flags_1_set_on_ID 163

#define chr_remove_instant_LENGTH 2

#define bond_equip_item_cinema_ID 228

#define GLIST_REMOVE_CHR 17

#define if_bond_in_tank_LENGTH 2

#define local_timer_reset_ID 175

#define if_hud_countdown_greater_than_LENGTH 4

#define if_object_not_destroyed_ID 91

#define GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY 13

#define door_unset_lock_LENGTH 3

#define HIT_RIGHT_SHOULDER 14

#define label_LENGTH 2

#define guard_runs_to_pad_LENGTH 3

#define SPAWN_00000020 32

#define if_guard_playing_animation_LENGTH 2

#define guard_try_dropping_item_ID 27

#define camera_orbit_pad_ID 238

#define if_screen_fade_completed_LENGTH 2

#define guard_bitfield_set_on_LENGTH 2

#define if_chr_dying_or_dead_LENGTH 3

#define set_return_ai_list_LENGTH 3

#define HIT_LEFT_ARM 10

#define if_guard_and_bond_within_partial_line_of_sight_ID 61

#define local_byte_2_set_ID 134

#define guard_try_hopping_sideways_LENGTH 2

#define if_guard_distance_to_bond_less_than_ID 75

#define if_camera_is_in_intro_LENGTH 2

#define HUD_HIDE_ALL 0

#define guard_try_sprinting_to_bond_position_ID 42

#define if_credits_has_completed_ID 240

#define SPAWN_80000000 2147483648

#define SPAWN_00000004 4

#define door_open_instant_LENGTH 2

#define SPAWN_00000008 8

#define guard_surrenders_LENGTH 1

#define chr_set_pad_preset_ID 172

#define guard_bitfield_set_on_ID 148

#define if_hud_countdown_has_stopped_ID 186

#define guard_kneel_LENGTH 1

#define if_local_byte_2_less_than_LENGTH 3

#define GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM 5

#define hud_countdown_set_LENGTH 3

#define if_guard_in_room_with_chr_LENGTH 3

#define if_game_difficulty_greater_than_ID 113

#define if_alarm_is_on_LENGTH 2

#define guard_raises_arms_ID 250

#define HIT_LEFT_LEG 2

#define gas_leak_and_fade_fog_ID 251

#define if_sfx_channel_volume_less_than_LENGTH 5

#define camera_switch_LENGTH 6

#define if_guard_is_targeted_by_bond_ID 69

#define text_print_top_LENGTH 3

#define guard_try_spawning_item_ID 191

#define ANIM_TRANSLATION_SCALE_4X 32

#define if_number_of_active_players_less_than_LENGTH 3

#define guard_set_chr_preset_LENGTH 2

#define object_destroy_ID 95

#define guard_set_vision_range_LENGTH 2

#define AI_LIST_GLOBAL_START 0

#define SPAWN_00800000 8388608

#define if_door_state_equal_ID 104

#define camera_switch_ID 213

#define if_credits_has_completed_LENGTH 2

#define if_system_power_time_greater_than_LENGTH 4

#define if_guard_hits_missed_less_than_ID 122

#define if_guard_distance_to_bond_greater_than_LENGTH 4

#define if_chr_health_less_than_ID 124

#define if_guard_distance_to_bond_greater_than_ID 76

#define SPAWN_00000200 512

#define if_bond_damage_and_pickups_disabled_LENGTH 2

#define if_gas_is_leaking_ID 56

#define chr_try_spawning_at_pad_ID 189

#define SPAWN_00010000 65536

#define chr_hit_body_part_with_item_damage_LENGTH 4

#define HIT_RIGHT_FOOT 4

#define guard_set_chr_num_ID 142

#define if_guard_hits_missed_greater_than_LENGTH 3

#define if_guard_see_another_guard_die_LENGTH 2

#define if_random_seed_greater_than_LENGTH 3

#define if_camera_is_in_bond_swirl_LENGTH 2

#define guard_bitfield_set_off_LENGTH 2

#define if_chr_in_room_with_pad_LENGTH 5

#define guard_set_hearing_scale_ID 139

#define chr_set_chr_preset_LENGTH 3

#define if_objective_num_complete_LENGTH 3

#define guard_try_fire_or_aim_at_target_ID 20

#define bond_set_locked_velocity_ID 229

#define guard_try_unknown6F_ID 111

#define local_timer_stop_LENGTH 1

#define guard_bitfield_set_off_ID 149

#define HIT_LEFT_HAND 9

#define AI_CMDS_TOTAL 253

#define if_guard_distance_to_chr_less_than_LENGTH 5

#define chr_flags_set_off_LENGTH 6

#define tv_change_screen_bank_LENGTH 4

#define guard_set_accuracy_rating_ID 147

#define object_drop_from_chr_ID 96

#define bond_disable_damage_and_pickups_ID 236

#define if_random_seed_greater_than_ID 53

#define guard_try_firing_roll_LENGTH 2

#define guard_try_running_to_bond_position_LENGTH 2

#define SPAWN_00100000 1048576

#define guard_try_unknown6F_LENGTH 3

#define music_xtrack_stop_LENGTH 2

#define alarm_off_LENGTH 1

#define GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE 10

#define sfx_play_LENGTH 4

#define guard_try_hopping_sideways_ID 15

#define aircraft_rotor_speed_LENGTH 5

#define guard_try_walking_to_bond_position_ID 41

#define chr_set_pad_preset_LENGTH 4

#define local_timer_start_ID 177

#define BITFIELD_DONT_POINT_AT_BOND 1

#define objective_bitfield_set_off_LENGTH 5

#define local_byte_2_subtract_ID 136

#define ai_sleep_ID 3

#define chr_try_teleporting_to_pad_ID 217

#define if_bond_has_item_equipped_ID 89

#define SPAWN_00000400 1024

#define SPAWN_00020000 131072

#define chr_hide_all_ID 221

#define guard_start_patrol_ID 32

#define chr_remove_item_in_hand_LENGTH 3

#define if_bond_has_item_equipped_LENGTH 3

#define hud_countdown_show_LENGTH 1

#define if_guard_is_on_screen_LENGTH 2

#define HIT_NULL_PART 0

#define chr_equip_object_ID 100

#define objective_bitfield_set_off_ID 155

#define debug_log_ID 173

#define chr_set_chr_preset_ID 170

#define guard_try_dropping_item_LENGTH 5

#define if_item_is_stationary_within_level_ID 87

#define if_guard_playing_animation_ID 11

#define if_bond_is_dead_ID 235

#define HIT_RIGHT_LEG 5

#define if_guard_bitfield_is_set_on_ID 150

#define if_guard_counter_clockwise_direction_to_bond_less_than_LENGTH 3

#define GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM 9

#define aircraft_rotor_speed_ID 205

#define guard_play_animation_ID 10

#define if_hud_countdown_greater_than_ID 188

#define text_print_top_ID 195

#define credits_roll_ID 239

#define chr_try_teleporting_to_pad_LENGTH 5

#define if_bond_in_room_with_pad_ID 85

#define if_mission_time_less_than_ID 114

#define object_flags_2_set_off_LENGTH 6

#define chr_bitfield_set_on_ID 151

#define jump_to_return_ai_list_LENGTH 1

#define guard_try_firing_walk_LENGTH 2

#define music_xtrack_stop_ID 245

#define if_chr_distance_to_pad_less_than_ID 77

#define guard_set_speed_rating_LENGTH 2

#define guard_animation_stop_ID 8

#define if_guard_has_stopped_moving_ID 47

#define if_guard_flags_is_set_on_LENGTH 6

#define object_rocket_launch_ID 252

#define if_guard_hits_greater_than_LENGTH 3

#define guard_points_at_bond_LENGTH 1

#define GLIST_WAIT_ONE_SECOND_SUBROUTINE 14

#define object_flags_1_set_off_LENGTH 6

#define DOOR_STATE_CLOSED 1

#define chr_drop_all_concealed_items_LENGTH 2

#define if_bond_health_greater_than_ID 128

#define if_alarm_is_on_unused_ID 54

#define if_system_power_time_less_than_LENGTH 4

#define GLIST_IDLE_RAND_ANIM_SUBROUTINE 3

#define if_local_timer_has_stopped_ID 178

#define guard_set_chr_preset_ID 169

#define if_local_byte_1_less_than_LENGTH 3

#define guard_try_triggering_alarm_at_pad_ID 36

#define if_objective_num_complete_ID 109

#define if_mission_time_less_than_LENGTH 4

#define if_chr_in_room_with_pad_ID 84

#define if_guard_and_bond_within_partial_line_of_sight_LENGTH 2

#define local_byte_2_add_LENGTH 2

#define if_objective_bitfield_is_set_on_LENGTH 6

#define if_guard_counter_clockwise_direction_from_bond_greater_than_LENGTH 3

#define if_mission_time_greater_than_ID 115

#define label_ID 2

#define if_guard_was_shot_within_last_10_secs_ID 62

#define camera_look_at_bond_from_pad_ID 212

#define guard_set_grenade_probability_ID 141

#define guard_try_firing_walk_ID 17

#define HIT_LEFT_SHOULDER 11

#define guard_try_facing_target_LENGTH 6

#define guard_flags_set_on_LENGTH 5

#define hud_countdown_stop_LENGTH 1

#define HIT_PELVIS 7

#define if_chr_bitfield_is_set_on_LENGTH 4

#define SPAWN_00040000 262144

#define if_killed_civilians_greater_than_LENGTH 3

#define guard_start_patrol_LENGTH 2

#define if_room_containing_pad_is_on_screen_LENGTH 4

#define if_guard_has_not_been_seen_ID 65

#define HUD_SHOW_HUD_COUNTDOWN 4

#define chr_flags_set_on_ID 160

#define guard_set_argh_rating_LENGTH 2

#define SPAWN_00000800 2048

#define local_byte_1_subtract_ID 131

#define if_guard_has_not_been_seen_LENGTH 2

#define random_generate_seed_ID 51

#define door_close_ID 103

#define guard_set_health_total_ID 143

#define GLIST_AIM_AT_BOND 0

#define guard_flags_set_off_ID 158

#define if_guard_is_firing_and_unknown_flag_ID 231

#define sfx_emit_from_object_LENGTH 5

#define guard_set_vision_range_ID 140

#define guard_try_running_to_chr_position_ID 44

#define if_object_in_room_with_pad_LENGTH 5

#define objective_bitfield_set_on_ID 154

#define if_guard_is_firing_and_unknown_flag_LENGTH 2

#define guard_try_unknown6E_ID 110

#define TARGET_BOND 1

#define chr_bitfield_set_off_LENGTH 3

#define TARGET_AIM_ONLY 32

#define bond_equip_item_LENGTH 2

#define GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM 7

#define guard_try_setting_chr_preset_to_guard_within_distance_LENGTH 4

#define if_killed_civilians_greater_than_ID 247

#define if_bond_y_pos_less_than_ID 214

#define if_folder_actor_is_equal_ID 242

#define GLIST_EXIT_LEVEL 15

#define if_guard_see_another_guard_shot_ID 58

#define if_screen_fade_completed_ID 220

#define if_bond_in_tank_ID 209

#define removed_command27_ID 39

#define set_return_ai_list_ID 6

#define chr_drop_all_held_items_LENGTH 2

#define bond_equip_item_ID 227

#define if_object_flags_1_is_set_on_LENGTH 7

#define guard_looks_around_self_ID 13

#define SPAWN_00080000 524288

#define if_object_not_destroyed_LENGTH 3

#define if_guard_is_firing_LENGTH 2

#define if_guard_counter_clockwise_direction_from_bond_less_than_LENGTH 3

#define if_local_timer_greater_than_ID 180

#define guard_try_firing_run_LENGTH 2

#define local_byte_2_add_ID 135

#define GLIST_DRAW_DD44_AND_FIRE 16

#define if_hud_countdown_less_than_ID 187

#define hud_countdown_stop_ID 184

#define hud_hide_and_lock_controls_and_pause_mission_time_LENGTH 2

#define guard_try_fire_or_aim_at_target_kneel_LENGTH 6

#define if_guard_has_stopped_moving_LENGTH 2

#define guard_try_running_to_side_ID 16

#define SPAWN_00200000 2097152

#define door_set_lock_ID 106

#define if_object_flags_1_is_set_on_ID 165

#define guard_runs_to_pad_preset_ID 29

#define TARGET_COMPASS 16

#define random_generate_seed_LENGTH 1

#define bond_disable_damage_and_pickups_LENGTH 1

#define guard_set_speed_rating_ID 145

#define if_local_byte_1_less_than_random_seed_LENGTH 2

#define removed_command2B_ID 43

#define if_bond_is_dead_LENGTH 2

#define chr_bitfield_set_off_ID 152

#define sfx_fade_channel_volume_LENGTH 6

#define if_bond_distance_to_pad_less_than_ID 82

#define trigger_explosions_around_bond_ID 246

#define object_flags_2_set_on_ID 166

#define chr_try_spawning_next_to_unseen_chr_ID 190

#define gas_leak_and_switch_fog_ID 233

#define ai_sleep_LENGTH 1

#define door_open_instant_ID 223

#define SPAWN_10000000 268435456

#define guard_animation_stop_LENGTH 1

#define camera_orbit_pad_LENGTH 13

#define guard_try_walking_to_chr_position_LENGTH 3

#define HIT_CHEST 15

#define if_guard_distance_to_chr_less_than_ID 79

#define if_bond_health_less_than_ID 127

#define if_guard_was_shot_within_last_10_secs_LENGTH 2

#define C0_CONTEXT 4

#define ICACHE_LINEMASK 31

#define EXC_DBE 28

#define C0_CAUSE 13

#define CONFIG_EC_1_1 6

#define SR_IBIT8 32768

#define SR_IBIT3 1024

#define SR_IBIT2 512

#define SR_IBIT1 256

#define TLBINX_INXSHIFT 0

#define EXC_BREAK 36

#define SR_IBIT7 16384

#define SR_IBIT6 8192

#define SR_IBIT5 4096

#define SR_IBIT4 2048

#define CONFIG_BE 32768

#define TLBLO_CACHSHIFT 3

#define CACHERR_PIDX_MASK 7

#define C0_EPC 14

#define EXC_INT 0

#define TLBLO_EXLWR 40

#define C0_SR 12

#define TLBHI_NPID 255

#define TLBHI_PIDSHIFT 0

#define E_VEC 2147484032

#define CACHERR_SIDX_MASK 4194296

#define TLBLO_NONCOHRNT 24

#define SADDRMASK 4294959104

#define CAUSE_CEMASK 805306368

#define C0_REVMASK 255

#define TLBCTXT_VPNMASK 8388592

#define K2BASE 3221225472

#define EXC_RADE 16

#define CAUSE_EXCMASK 124

#define SINVALID 0

#define CONFIG_IC_SHFT 9

#define C0_MAJREVSHIFT 4

#define CONFIG_EC_3_2 7

#define CONFIG_EC_3_1 1

#define TLBCTXT_BASEMASK 4286578688

#define C0_BADVADDR 8

#define TLBLO_PFNMASK 1073741760

#define PADDRMASK 4294967040

#define C0_PAGEMASK 5

#define TLBCTXT_VPNSHIFT 4

#define EXC_WMISS 12

#define PSTATEMASK 192

#define SR_ERL 4

#define C_FILL 20

#define CAUSE_IPSHIFT 8

#define CONFIG_EC_2_1 0

#define SIZE_EXCVEC 128

#define C0_MINREVMASK 15

#define WATCHLO_ADDRMASK 4294967288

#define DCACHE_LINESIZE 16

#define PCLEANEXCL 128

#define CONFIG_IC 3584

#define CONFIG_IB 32

#define C0_ENTRYLO0 2

#define C0_ENTRYLO1 3

#define CONFIG_K0 7

#define CACH_SI 2

#define CAUSE_SW1 256

#define FPCSR_C 8388608

#define CAUSE_SW2 512

#define CACH_SD 3

#define SR_IMASK0 65280

#define C0_TAGHI 29

#define SR_IMASK7 32768

#define C0_PRID 15

#define SR_IMASK8 0

#define SR_IMASK5 57344

#define SR_IMASK6 49152

#define SR_IMASK3 63488

#define SR_IMASK4 61440

#define SR_IMASK1 65024

#define SR_IMASK2 64512

#define CAUSE_CESHIFT 28

#define CAUSE_EXCSHIFT 2

#define C0_IMPMASK 65280

#define TLBLO_CACHMASK 56

#define PINVALID 0

#define EXC_FPE 60

#define SR_KSU_MASK 24

#define SR_KSU_USR 16

#define EXC_WATCH 92

#define SR_TS 2097152

#define CONFIG_DC 448

#define CONFIG_DB 16

#define C0_MAJREVMASK 240

#define WATCHLO_WTRAP 1

#define TLBLO_UNCACHED 16

#define CONFIG_CU 8

#define SR_EXL 2

#define CONFIG_CM 2147483648

#define SR_SX 64

#define SR_CU1 536870912

#define SR_UX 32

#define SR_CU0 268435456

#define SR_CU3 2147483648

#define SR_CU2 1073741824

#define CONFIG_EC 1879048192

#define CONFIG_EB 8192

#define NTLBENTRIES 31

#define TLBPGMASK_64K 122880

#define C0_READI 1

#define SR_RP 134217728

#define CACHERR_ET 268435456

#define SR_RE 33554432

#define CACHERR_ES 134217728

#define CACHERR_ER 2147483648

#define CONFIG_EW 786432

#define CACHERR_EI 16777216

#define CONFIG_EP 251658240

#define CACHERR_EE 67108864

#define CONFIG_EM 16384

#define CACHERR_ED 536870912

#define CACHERR_EC 1073741824

#define CACHERR_EB 33554432

#define SR_CUMASK 4026531840

#define ICACHE_SIZE 16384

#define SR_SR 1048576

#define C0_RFE 16

#define WATCHLO_VALIDMASK 4294967291

#define FPCSR_EV 2048

#define C0_WRITER 6

#define CONFIG_BE_SHFT 15

#define FPCSR_EU 256

#define FPCSR_EO 512

#define C0_WATCHHI 19

#define FPCSR_EI 128

#define C_CDX 12

#define C0_LLADDR 17

#define C0_ECC 26

#define SR_IE 1

#define EXC_CPU 44

#define SR_IMASK 65280

#define DCACHE_LINEMASK 15

#define TLBPGMASK_16K 24576

#define C_IWBINV 0

#define EXC_II 40

#define C0_WRITEI 2

#define FPCSR_CZ 32768

#define FPCSR_CU 8192

#define FPCSR_CV 65536

#define FPCSR_CO 16384

#define FPCSR_CI 4096

#define K1SIZE 536870912

#define FPCSR_RM_MASK 3

#define TLBRAND_RANDMASK 63

#define FPCSR_CE 131072

#define CONFIG_SW 1048576

#define CONFIG_SS 2097152

#define C_IST 8

#define K0BASE 2147483648

#define KUSIZE 2147483648

#define CONFIG_SM 65536

#define CONFIG_SC 131072

#define CONFIG_SB 12582912

#define SR_FR 67108864

#define EXC_VCEI 56

#define TLBHI_VPN2SHIFT 13

#define TLBCTXT_BASEBITS 9

#define C_ILT 4

#define SCLEANEXCL 4096

#define TLBRAND_RANDSHIFT 0

#define C0_WATCHLO 18

#define SR_KX 128

#define PPARITY_MASK 1

#define XUT_VEC 2147483776

#define C0_INX 0

#define CONFIG_NONCOHRNT 3

#define PDIRTYEXCL 192

#define SADDR_SHIFT 4

#define SDIRTYEXCL 5120

#define TLBHI_PIDMASK 255

#define SSTATEMASK 7168

#define KUBASE 0

#define EXC_WADE 20

#define CONFIG_UNCACHED 2

#define TLBLO_D 4

#define SR_KSU_SUP 8

#define SVINDEXMASK 896

#define SR_KSU_KER 0

#define C0_TAGLO 28

#define UT_VEC 2147483648

#define FPCSR_RM_RZ 1

#define TLBLO_G 1

#define C0_IMPSHIFT 8

#define FPCSR_FZ 32

#define FPCSR_FS 16777216

#define EXC_IBE 24

#define FPCSR_RM_RP 2

#define K1BASE 2684354560

#define FPCSR_FU 8

#define FPCSR_RM_RM 3

#define FPCSR_FV 64

#define FPCSR_RM_RN 0

#define FPCSR_FO 16

#define TLBLO_V 2

#define CACH_PD 1

#define EXC_RMISS 8

#define CAUSE_BD 2147483648

#define FPCSR_FI 4

#define CACH_PI 0

#define FPCSR_EZ 1024

#define C0_WIRED 6

#define C0_ENTRYHI 10

#define ICACHE_LINESIZE 32

#define C_HWB 24

#define SR_BEV 4194304

#define SECC_MASK 127

#define EXC_SYSCALL 32

#define CAUSE_IPMASK 65280

#define C0_CONFIG 16

#define SR_ITS 16777216

#define K0SIZE 536870912

#define CONFIG_COHRNT_EXLWR 5

#define SR_IMASKSHIFT 8

#define TLBHI_VPN2MASK 4294959104

#define C0_COMPARE 11

#define DCACHE_SIZE 8192

#define ECC_VEC 2147483904

#define C_HWBINV 20

#define CONFIG_SB_SHFT 22

#define TLBLO_PFNSHIFT 6

#define EXC_TRAP 52

#define TLBCTXT_BASESHIFT 23

#define CONFIG_DC_SHFT 6

#define EXC_OV 48

#define WATCHLO_RTRAP 2

#define C0_COUNT 9

#define SR_DE 65536

#define EXC_VCED 124

#define C_IINV 0

#define TLBINX_PROBE 2147483648

#define C0_PROBE 8

#define WATCHHI_VALIDMASK 15

#define EXC_MOD 4

#define SR_CH 262144

#define TLBWIRED_WIREDMASK 63

#define C_HSV 28

#define C0_CACHE_ERR 27

#define TLBPGMASK_4K 0

#define C0_RAND 1

#define C0_ERROR_EPC 30

#define PADDR_SHIFT 4

#define R_VEC 3217031168

#define K2SIZE 536870912

#define SR_CE 131072

#define CACHERR_PIDX_SHIFT 12

#define TLBINX_INXMASK 63

#define CAUSE_IP3 1024

#define CAUSE_IP4 2048

#define C_HINV 16

#define CAUSE_IP7 16384

#define CAUSE_IP8 32768

#define CAUSE_IP5 4096

#define CAUSE_IP6 8192

typedef struct Gtexture Gtexture, *PGtexture;

struct Gtexture {
    uchar cmd;
    uchar lodscale;
    uchar tile;
    uchar on;
    ushort s;
    ushort t;
};

typedef struct Light_t Light_t, *PLight_t;

struct Light_t {
    uchar col[3];
    char pad1;
    uchar colc[3];
    char pad2;
    char dir[3];
    char pad3;
};

typedef struct Gsegment Gsegment, *PGsegment;

typedef union anon__struct_60_bitfield_1 anon__struct_60_bitfield_1, *Panon__struct_60_bitfield_1;

typedef union anon__struct_60_bitfield_2 anon__struct_60_bitfield_2, *Panon__struct_60_bitfield_2;

union anon__struct_60_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad0:8; // : bits 8-15
    int mw_index:8; // : bits 16-23
    int number:8; // : bits 24-31
};

union anon__struct_60_bitfield_2 {
    int pad1:8; // : bits 0-7
    int base:24; // : bits 8-31
};

struct Gsegment {
    union anon__struct_60_bitfield_1 field_0x0;
    union anon__struct_60_bitfield_2 field_0x4;
};

typedef struct Gsetcolor Gsetcolor, *PGsetcolor;

typedef union anon__struct_68_bitfield_1 anon__struct_68_bitfield_1, *Panon__struct_68_bitfield_1;

union anon__struct_68_bitfield_1 {
    int cmd:8; // : bits 0-7
};

struct Gsetcolor {
    union anon__struct_68_bitfield_1 field_0x0;
    uchar pad;
    uchar prim_min_level;
    uchar prim_level;
    ulong color;
};

typedef struct Gtri Gtri, *PGtri;

typedef union anon__struct_58_bitfield_1 anon__struct_58_bitfield_1, *Panon__struct_58_bitfield_1;

typedef struct Tri Tri, *PTri;

union anon__struct_58_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad:24; // : bits 8-31
};

struct Tri {
    uchar flag;
    uchar v[3];
};

struct Gtri {
    union anon__struct_58_bitfield_1 field_0x0;
    struct Tri tri;
};

typedef struct TexRect TexRect, *PTexRect;

struct TexRect {
    ulong w0;
    ulong w1;
    ulong w2;
    ulong w3;
};

typedef struct Gsetcombine Gsetcombine, *PGsetcombine;

typedef union anon__struct_67_bitfield_1 anon__struct_67_bitfield_1, *Panon__struct_67_bitfield_1;

typedef union anon__struct_67_bitfield_2 anon__struct_67_bitfield_2, *Panon__struct_67_bitfield_2;

typedef union anon__struct_67_bitfield_3 anon__struct_67_bitfield_3, *Panon__struct_67_bitfield_3;

union anon__struct_67_bitfield_1 {
    int cmd:8; // : bits 0-7
};

union anon__struct_67_bitfield_2 {
    uint muxs0:24; // : bits 0-23
};

union anon__struct_67_bitfield_3 {
    uint muxs1:32; // : bits 0-31
};

struct Gsetcombine {
    union anon__struct_67_bitfield_1 field_0x0;
    union anon__struct_67_bitfield_2 field_0x4;
    union anon__struct_67_bitfield_3 field_0x8;
};

typedef union anon__struct_69_bitfield_2 anon__struct_69_bitfield_2, *Panon__struct_69_bitfield_2;

union anon__struct_69_bitfield_2 {
    uint pad:8; // : bits 0-7
};

typedef union anon__struct_69_bitfield_3 anon__struct_69_bitfield_3, *Panon__struct_69_bitfield_3;

union anon__struct_69_bitfield_3 {
    int x1:10; // : bits 0-9
    int x1frac:2; // : bits 10-11
    int y1:10; // : bits 12-21
    int y1frac:2; // : bits 22-23
};

typedef union anon__struct_69_bitfield_1 anon__struct_69_bitfield_1, *Panon__struct_69_bitfield_1;

union anon__struct_69_bitfield_1 {
    int cmd:8; // : bits 0-7
    int x0:10; // : bits 8-17
    int x0frac:2; // : bits 18-19
    int y0:10; // : bits 20-29
    int y0frac:2; // : bits 30-31
};

typedef union anon__struct_59_bitfield_3 anon__struct_59_bitfield_3, *Panon__struct_59_bitfield_3;

union anon__struct_59_bitfield_3 {
    uchar param:8; // : bits 0-7
};

typedef union anon__struct_59_bitfield_2 anon__struct_59_bitfield_2, *Panon__struct_59_bitfield_2;

union anon__struct_59_bitfield_2 {
    int pad2:24; // : bits 0-23
};

typedef union anon__struct_59_bitfield_1 anon__struct_59_bitfield_1, *Panon__struct_59_bitfield_1;

union anon__struct_59_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad1:24; // : bits 8-31
};

typedef struct Gsettile Gsettile, *PGsettile;

typedef union anon__struct_70_bitfield_1 anon__struct_70_bitfield_1, *Panon__struct_70_bitfield_1;

typedef union anon__struct_70_bitfield_2 anon__struct_70_bitfield_2, *Panon__struct_70_bitfield_2;

typedef union anon__struct_70_bitfield_3 anon__struct_70_bitfield_3, *Panon__struct_70_bitfield_3;

union anon__struct_70_bitfield_1 {
    int cmd:8; // : bits 0-7
};

union anon__struct_70_bitfield_2 {
    uint fmt:3; // : bits 0-2
    uint siz:2; // : bits 3-4
    uint pad0:1; // : bits 5
    uint line:9; // : bits 6-14
    uint tmem:9; // : bits 15-23
    uint pad1:5; // : bits 24-28
    uint tile:3; // : bits 29-31
};

union anon__struct_70_bitfield_3 {
    uint palette:4; // : bits 0-3
    uint ct:1; // : bits 4
    uint mt:1; // : bits 5
    uint maskt:4; // : bits 6-9
    uint shiftt:4; // : bits 10-13
    uint cs:1; // : bits 14
    uint ms:1; // : bits 15
    uint masks:4; // : bits 16-19
    uint shifts:4; // : bits 20-23
};

struct Gsettile {
    union anon__struct_70_bitfield_1 field_0x0;
    union anon__struct_70_bitfield_2 field_0x4;
    union anon__struct_70_bitfield_3 field_0x8;
};

typedef struct Gline3D Gline3D, *PGline3D;

typedef union anon__struct_64_bitfield_1 anon__struct_64_bitfield_1, *Panon__struct_64_bitfield_1;

union anon__struct_64_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad:24; // : bits 8-31
};

struct Gline3D {
    union anon__struct_64_bitfield_1 field_0x0;
    struct Tri line;
};

typedef struct Gloadtile Gloadtile, *PGloadtile;

typedef struct Gloadtile Gloadblock;

typedef union anon__struct_71_bitfield_1 anon__struct_71_bitfield_1, *Panon__struct_71_bitfield_1;

typedef union anon__struct_71_bitfield_2 anon__struct_71_bitfield_2, *Panon__struct_71_bitfield_2;

typedef union anon__struct_71_bitfield_3 anon__struct_71_bitfield_3, *Panon__struct_71_bitfield_3;

typedef union anon__struct_71_bitfield_4 anon__struct_71_bitfield_4, *Panon__struct_71_bitfield_4;

union anon__struct_71_bitfield_1 {
    int cmd:8; // : bits 0-7
};

union anon__struct_71_bitfield_2 {
    uint sl:12; // : bits 0-11
    uint tl:12; // : bits 12-23
};

union anon__struct_71_bitfield_3 {
    int pad:5; // : bits 0-4
};

union anon__struct_71_bitfield_4 {
    uint tile:3; // : bits 0-2
    uint sh:12; // : bits 3-14
    uint th:12; // : bits 15-26
};

struct Gloadtile {
    union anon__struct_71_bitfield_1 field_0x0;
    union anon__struct_71_bitfield_2 field_0x4;
    union anon__struct_71_bitfield_3 field_0x8;
    union anon__struct_71_bitfield_4 field_0xc;
};

typedef union Ambient Ambient, *PAmbient;

typedef struct Ambient_t Ambient_t, *PAmbient_t;

struct Ambient_t {
    uchar col[3];
    char pad1;
    uchar colc[3];
    char pad2;
};

union Ambient {
    struct Ambient_t l;
    longlong force_structure_alignment[1];
};

typedef struct Gtexrect Gtexrect, *PGtexrect;

typedef union anon__struct_72_bitfield_1 anon__struct_72_bitfield_1, *Panon__struct_72_bitfield_1;

typedef union anon__struct_72_bitfield_2 anon__struct_72_bitfield_2, *Panon__struct_72_bitfield_2;

typedef union anon__struct_72_bitfield_3 anon__struct_72_bitfield_3, *Panon__struct_72_bitfield_3;

typedef union anon__struct_72_bitfield_4 anon__struct_72_bitfield_4, *Panon__struct_72_bitfield_4;

union anon__struct_72_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint xl:12; // : bits 8-19
    uint yl:12; // : bits 20-31
};

union anon__struct_72_bitfield_3 {
    uint s:16; // : bits 0-15
    uint t:16; // : bits 16-31
};

union anon__struct_72_bitfield_2 {
    uint pad1:5; // : bits 0-4
    uint tile:3; // : bits 5-7
    uint xh:12; // : bits 8-19
    uint yh:12; // : bits 20-31
};

union anon__struct_72_bitfield_4 {
    uint dsdx:16; // : bits 0-15
    uint dtdy:16; // : bits 16-31
};

struct Gtexrect {
    union anon__struct_72_bitfield_1 field_0x0;
    union anon__struct_72_bitfield_2 field_0x4;
    union anon__struct_72_bitfield_3 field_0x8;
    union anon__struct_72_bitfield_4 field_0xc;
};

typedef union anon__struct_62_bitfield_1 anon__struct_62_bitfield_1, *Panon__struct_62_bitfield_1;

union anon__struct_62_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad0:8; // : bits 8-15
    int sft:8; // : bits 16-23
    int len:8; // : bits 24-31
};

typedef union Light Light, *PLight;

union Light {
    struct Light_t l;
    longlong force_structure_alignment[2];
};

typedef union anon__struct_62_bitfield_2 anon__struct_62_bitfield_2, *Panon__struct_62_bitfield_2;

union anon__struct_62_bitfield_2 {
    uint data:32; // : bits 0-31
};

typedef union uSprite uSprite, *PuSprite;

typedef struct uSprite_t uSprite_t, *PuSprite_t;

struct uSprite_t {
    void * SourceImagePointer;
    void * TlutPointer;
    short Stride;
    short SubImageWidth;
    short SubImageHeight;
    char SourceImageType;
    char SourceImageBitSize;
    short ScaleX;
    short ScaleY;
    char FlipTextureX;
    char FlipTextureY;
    short SourceImageOffsetS;
    short SourceImageOffsetT;
    short PScreenX;
    short PScreenY;
    char dummy[2];
};

union uSprite {
    struct uSprite_t s;
    longlong force_structure_allignment[4];
};

typedef struct Lightsn Lightsn, *PLightsn;

struct Lightsn {
    union Ambient a;
    union Light l[7];
};

typedef struct Gfillrect Gfillrect, *PGfillrect;

struct Gfillrect {
    union anon__struct_69_bitfield_1 field_0x0;
    union anon__struct_69_bitfield_2 field_0x4;
    union anon__struct_69_bitfield_3 field_0x8;
};

typedef struct LookAt LookAt, *PLookAt;

struct LookAt {
    union Light l[2];
};

typedef union anon__struct_57_bitfield_2 anon__struct_57_bitfield_2, *Panon__struct_57_bitfield_2;

union anon__struct_57_bitfield_2 {
    uint par:8; // : bits 0-7
    uint len:16; // : bits 8-23
};

typedef union anon__struct_66_bitfield_2 anon__struct_66_bitfield_2, *Panon__struct_66_bitfield_2;

union anon__struct_66_bitfield_2 {
    uint fmt:3; // : bits 0-2
    uint siz:2; // : bits 3-4
    uint pad:7; // : bits 5-11
    uint wd:12; // : bits 12-23
};

typedef union anon__struct_57_bitfield_1 anon__struct_57_bitfield_1, *Panon__struct_57_bitfield_1;

union anon__struct_57_bitfield_1 {
    int cmd:8; // : bits 0-7
};

typedef union anon__struct_66_bitfield_1 anon__struct_66_bitfield_1, *Panon__struct_66_bitfield_1;

union anon__struct_66_bitfield_1 {
    int cmd:8; // : bits 0-7
};

typedef struct Gloadtile Gsettilesize;

typedef struct Lights0 Lights0, *PLights0;

struct Lights0 {
    union Ambient a;
    union Light l[1];
};

typedef struct Lights3 Lights3, *PLights3;

struct Lights3 {
    union Ambient a;
    union Light l[3];
};

typedef struct Lights4 Lights4, *PLights4;

struct Lights4 {
    union Ambient a;
    union Light l[4];
};

typedef struct Gsetimg Gsetimg, *PGsetimg;

struct Gsetimg {
    union anon__struct_66_bitfield_1 field_0x0;
    union anon__struct_66_bitfield_2 field_0x4;
    uint dram;
};

typedef struct Lights1 Lights1, *PLights1;

struct Lights1 {
    union Ambient a;
    union Light l[1];
};

typedef struct Lights2 Lights2, *PLights2;

struct Lights2 {
    union Ambient a;
    union Light l[2];
};

typedef struct Lights7 Lights7, *PLights7;

struct Lights7 {
    union Ambient a;
    union Light l[7];
};

typedef struct Lights5 Lights5, *PLights5;

struct Lights5 {
    union Ambient a;
    union Light l[5];
};

typedef struct Lights6 Lights6, *PLights6;

struct Lights6 {
    union Ambient a;
    union Light l[6];
};

typedef struct GsetothermodeL GsetothermodeL, *PGsetothermodeL;

typedef union anon__struct_61_bitfield_1 anon__struct_61_bitfield_1, *Panon__struct_61_bitfield_1;

typedef union anon__struct_61_bitfield_2 anon__struct_61_bitfield_2, *Panon__struct_61_bitfield_2;

union anon__struct_61_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad0:8; // : bits 8-15
    int sft:8; // : bits 16-23
    int len:8; // : bits 24-31
};

union anon__struct_61_bitfield_2 {
    uint data:32; // : bits 0-31
};

struct GsetothermodeL {
    union anon__struct_61_bitfield_1 field_0x0;
    union anon__struct_61_bitfield_2 field_0x4;
};

typedef struct GsetothermodeH GsetothermodeH, *PGsetothermodeH;

struct GsetothermodeH {
    union anon__struct_62_bitfield_1 field_0x0;
    union anon__struct_62_bitfield_2 field_0x4;
};

typedef struct Gloadtile Gloadtlut;

typedef struct Gdma Gdma, *PGdma;

struct Gdma {
    union anon__struct_57_bitfield_1 field_0x0;
    union anon__struct_57_bitfield_2 field_0x4;
    uint addr;
};

typedef union anon__struct_65_bitfield_1 anon__struct_65_bitfield_1, *Panon__struct_65_bitfield_1;

union anon__struct_65_bitfield_1 {
    int cmd:8; // : bits 0-7
    int pad1:24; // : bits 8-31
};

typedef struct Hilite_t Hilite_t, *PHilite_t;

struct Hilite_t {
    int x1;
    int y1;
    int x2;
    int y2;
};

typedef struct Gpopmtx Gpopmtx, *PGpopmtx;

struct Gpopmtx {
    union anon__struct_59_bitfield_1 field_0x0;
    union anon__struct_59_bitfield_2 field_0x4;
    union anon__struct_59_bitfield_3 field_0x8;
};

typedef union Hilite Hilite, *PHilite;

union Hilite {
    struct Hilite_t h;
    long force_alignmnet[4];
};

typedef struct Gperspnorm Gperspnorm, *PGperspnorm;

struct Gperspnorm {
    union anon__struct_65_bitfield_1 field_0x0;
    short pad2;
    short scale;
};

#define G_LOADBLOCK 243

#define G_DMACMDSIZ 128

#define G_MWO_NUMLIGHT 0

#define G_TX_LOADTILE 7

#define G_CYC_FILL 3145728

#define G_IM_FMT_IA 3

#define G_TEXTURE_SCALE_FRAC 16

#define G_BL_CLR_MEM 1

#define G_MOVEMEM 3

#define G_CCMUX_K4 7

#define G_MWO_aLIGHT_5 128

#define G_CCMUX_K5 15

#define G_MWO_aLIGHT_4 96

#define G_MWO_aLIGHT_7 192

#define G_MWO_aLIGHT_6 160

#define G_MWO_aLIGHT_8 224

#define G_TRI_SHADE_ZBUFF 205

#define G_ACMUX_0 7

#define G_MDSFT_TEXTCONV 9

#define G_AD_NOTPATTERN 16

#define G_RM_NOOP2 0

#define G_ACMUX_1 6

#define G_IM_SIZ_4b 0

#define G_MDSFT_CYCLETYPE 20

#define G_SETSCISSOR 237

#define G_PM_1PRIMITIVE 8388608

#define ZMODE_XLU 2048

#define G_MWO_CLIP_RNY 12

#define ZMODE_DEC 3072

#define G_MWO_CLIP_RNX 4

#define G_MWO_MATRIX_YX_YY_I 8

#define G_MWO_aLIGHT_1 0

#define G_MTX_MODELVIEW 0

#define G_MWO_aLIGHT_3 64

#define G_MWO_aLIGHT_2 32

#define G_TP_PERSP 524288

#define G_TX_CLAMP 2

#define G_TT_IA16 49152

#define G_POPMTX -67

#define G_TX_NOMIRROR 0

#define G_CD_DISABLE 192

#define G_MWO_MATRIX_YX_YY_F 40

#define G_RDPTILESYNC 232

#define G_PM_NPRIMITIVE 0

#define G_CYC_2CYCLE 1048576

#define G_MDSFT_COMBKEY 8

#define G_IM_SIZ_16b_SHIFT 0

#define G_CULLDL -66

#define FR_POS_FRUSTRATIO_2 65534

#define FR_POS_FRUSTRATIO_3 65533

#define G_RDPPIPESYNC 231

#define FR_POS_FRUSTRATIO_1 65535

#define G_MDSFT_BLENDER 16

#define G_MWO_CLIP_RPY 28

#define G_MWO_CLIP_RPX 20

#define G_ACMUX_PRIMITIVE 3

#define G_CCMUX_CENTER 6

#define G_SETKEYR 235

#define G_CCMUX_COMBINED_ALPHA 7

#define G_IM_SIZ_8b_SHIFT 1

#define G_MWO_MATRIX_WZ_WW_F 60

#define G_MDSFT_TEXTLOD 16

#define G_CK_KEY 256

#define G_MWO_MATRIX_WZ_WW_I 28

#define FR_POS_FRUSTRATIO_6 65530

#define FR_POS_FRUSTRATIO_4 65532

#define FR_POS_FRUSTRATIO_5 65531

#define G_CD_MAGICSQ 0

#define G_IM_SIZ_32b_INCR 0

#define G_CCMUX_PRIM_LOD_FRAC 14

#define G_IMMFIRST -65

#define G_MDSFT_COLORDITHER 22

#define G_TEXRECT 228

#define G_BL_A_SHADE 2

#define G_IM_FMT_YUV 1

#define G_CK_NONE 0

#define G_MTX 1

#define G_IM_SIZ_8b 1

#define G_TC_CONV 0

#define G_MV_TXTATT 150

#define G_ACMUX_SHADE 4

#define G_MWO_MATRIX_XZ_XW_F 36

#define CVG_DST_SAVE 768

#define G_DL_PUSH 0

#define G_MWO_MATRIX_XZ_XW_I 4

#define G_TEXTURE_GEN 262144

#define G_RDPCMDSIZ 64

#define G_SETCONVERT 236

#define G_CCMUX_NOISE 7

#define G_CCMUX_ENV_ALPHA 12

#define G_AC_THRESHOLD 1

#define G_IM_FMT_I 4

#define BOWTIE_VAL 0

#define G_MTX_PROJECTION 1

#define FORCE_BL 16384

#define G_CLIPPING 8388608

#define G_MWO_POINT_RGBA 16

#define G_IM_SIZ_32b_LINE_BYTES 2

#define G_IM_SIZ_8b_LINE_BYTES 1

#define G_IM_SIZ_4b_LINE_BYTES 0

#define CVG_X_ALPHA 4096

#define G_TD_SHARPEN 131072

#define G_LIGHTING 131072

#define CVG_DST_WRAP 256

#define G_SHADE 4

#define G_MTX_PUSH 4

#define G_MAXZ 1023

#define G_RDP_TRI_FILL_MASK 8

#define G_SETGEOMETRYMODE -73

#define G_TRI_FILL_ZBUFF 201

#define G_IM_FMT_CI 2

#define G_IM_SIZ_8b_INCR 1

#define G_MWO_bLIGHT_3 68

#define G_MWO_bLIGHT_4 100

#define G_MWO_bLIGHT_1 4

#define G_TX_NOMASK 0

#define G_MWO_bLIGHT_2 36

#define G_MDSFT_TEXTLUT 14

#define G_IM_SIZ_8b_BYTES 1

#define G_SETCIMG 255

#define G_VTX 4

#define G_MWO_bLIGHT_7 196

#define G_MWO_bLIGHT_8 228

#define G_MWO_bLIGHT_5 132

#define G_MWO_bLIGHT_6 164

#define G_MDSFT_PIPELINE 23

#define G_RDPHALF_2 -77

#define G_CULL_BOTH 12288

#define G_CCMUX_0 31

#define G_TX_LDBLK_MAX_TXL 2047

#define G_CCMUX_1 6

#define G_RDPHALF_1 -76

#define G_SHADING_SMOOTH 512

#define G_CCMUX_SHADE 4

#define G_SPRITE2D 9

#define G_CCMUX_ENVIRONMENT 5

#define G_CULL_FRONT 4096

#define G_LOADTILE 244

#define G_FOG 65536

#define G_SETPRIMDEPTH 238

#define G_MV_LOOKATX 132

#define G_MV_LOOKATY 130

#define G_SC_NON_INTERLACE 0

#define G_MDSFT_BLENDMASK 0

#define G_MW_FOG 8

#define G_CD_ENABLE 128

#define G_TEXTURE_ENABLE 2

#define G_MDSFT_RENDERMODE 3

#define G_MWO_MATRIX_ZZ_ZW_I 20

#define G_MWO_MATRIX_ZZ_ZW_F 52

#define G_BL_1MA 0

#define G_SPNOOP 0

#define G_TF_BILERP 8192

#define G_SETZIMG 254

#define G_MV_VIEWPORT 128

#define G_NOOP 192

#define Z_UPD 32

#define G_ENDDL -72

#define G_ROTATE_FRAC 16

#define G_SETTILESIZE 242

#define G_RM_NOOP 0

#define G_RESERVED2 7

#define G_TD_DETAIL 262144

#define G_RESERVED3 8

#define G_RESERVED0 2

#define G_RESERVED1 5

#define G_CLEARGEOMETRYMODE -74

#define G_BL_A_FOG 1

#define G_BL_CLR_FOG 3

#define G_MW_SEGMENT 6

#define Z_CMP 16

#define AA_EN 8

#define G_LOADTLUT 240

#define NUMLIGHTS_5 5

#define NUMLIGHTS_4 4

#define NUMLIGHTS_7 7

#define NUMLIGHTS_6 6

#define G_MWO_MATRIX_YZ_YW_F 44

#define NUMLIGHTS_1 1

#define NUMLIGHTS_0 1

#define NUMLIGHTS_3 3

#define G_MWO_MATRIX_YZ_YW_I 12

#define NUMLIGHTS_2 2

#define G_SETOTHERMODE_H.conflict 186

#define G_SETFILLCOLOR 247

#define G_DL 6

#define G_BL_CLR_BL 2

#define G_CYC_COPY 2097152

#define G_MWO_SEGMENT_A 10

#define CLR_ON_CVG 128

#define G_RDP_ADDR_FIXUP 3

#define G_SETFOGCOLOR 248

#define G_MWO_SEGMENT_8 8

#define G_MWO_SEGMENT_9 9

#define G_MWO_SEGMENT_6 6

#define G_MWO_SEGMENT_7 7

#define G_MWO_SEGMENT_4 4

#define G_MWO_SEGMENT_5 5

#define G_MWO_SEGMENT_2 2

#define G_MWO_SEGMENT_3 3

#define G_MWO_SEGMENT_0 0

#define G_IMMCMDSIZ 64

#define G_MWO_SEGMENT_1 1

#define G_ACMUX_LOD_FRACTION 0

#define G_IM_SIZ_16b_TILE_BYTES 2

#define G_ACMUX_COMBINED 0

#define G_TL_TILE 0

#define G_MDSFT_TEXTPERSP 19

#define G_ACMUX_ENVIRONMENT 5

#define G_IM_SIZ_8b_TILE_BYTES 1

#define G_MWO_MATRIX_WX_WY_I 24

#define G_ACMUX_TEXEL1 2

#define G_SC_EVEN_INTERLACE 2

#define G_MDSFT_TEXTFILT 12

#define G_IM_SIZ_16b 2

#define LIGHT_6 6

#define LIGHT_5 5

#define G_TL_LOD 65536

#define LIGHT_8 8

#define LIGHT_7 7

#define LIGHT_2 2

#define LIGHT_1 1

#define G_IM_SIZ_4b_TILE_BYTES 0

#define LIGHT_4 4

#define G_MWO_SEGMENT_F 15

#define G_ACMUX_TEXEL0 1

#define G_MW_CLIP 4

#define LIGHT_3 3

#define G_MWO_SEGMENT_D 13

#define G_SCALE_FRAC 8

#define G_MWO_SEGMENT_E 14

#define G_MWO_SEGMENT_B 11

#define G_IM_SIZ_32b_TILE_BYTES 2

#define G_TT_NONE 0

#define G_MWO_SEGMENT_C 12

#define G_AD_PATTERN 0

#define G_TX_RENDERTILE 0

#define G_IM_SIZ_8b_LOAD_BLOCK 2

#define G_SC_ODD_INTERLACE 3

#define G_IM_SIZ_4b_LOAD_BLOCK 2

#define G_CD_NOISE 128

#define G_TRI_FILL 200

#define G_FILLRECT 246

#define G_SETPRIMCOLOR 250

#define G_TEXRECTFLIP 229

#define G_MWO_MATRIX_WX_WY_F 56

#define G_MDSFT_ZSRCSEL 2

#define G_RDPSETOTHERMODE 239

#define G_IM_SIZ_16b_LINE_BYTES 2

#define G_TRI_SHADE_TXTR_ZBUFF 207

#define G_TF_POINT 0

#define G_CCMUX_SCALE 6

#define G_MWO_MATRIX_ZX_ZY_I 16

#define TEX_EDGE 0

#define G_MOVEWORD -68

#define G_RM_PASS 201850880

#define G_MAXFBZ 16383

#define CVG_DST_CLAMP 0

#define G_RDPFULLSYNC 233

#define G_DL_NOPUSH 1

#define G_CCMUX_COMBINED 0

#define G_TX_WRAP 0

#define G_MWO_POINT_ST 20

#define G_TRI_TXTR_ZBUFF 203

#define G_TRI1 -65

#define ZMODE_INTER 1024

#define G_SETOTHERMODE_L.conflict 185

#define G_MDSFT_ALPHACOMPARE 0

#define G_IM_SIZ_32b_SHIFT 0

#define G_AC_DITHER 3

#define G_TC_FILTCONV 2560

#define G_MTX_LOAD 2

#define G_CCMUX_PRIMITIVE 3

#define G_MW_LIGHTCOL 10

#define G_MW_POINTS 12

#define G_TC_FILT 3072

#define G_IM_SIZ_4b_INCR 3

#define G_MDSFT_ALPHADITHER 4

#define G_CCMUX_SHADE_ALPHA 11

#define ZMODE_OPA 0

#define G_BL_A_MEM 1

#define G_MWO_MATRIX_ZX_ZY_F 48

#define G_TP_NONE 0

#define G_SETOTHERMODE_H -70

#define FR_NEG_FRUSTRATIO_6 6

#define G_RDP_TRI_TXTR_MASK 2

#define FR_NEG_FRUSTRATIO_5 5

#define G_SETOTHERMODE_L -71

#define FR_NEG_FRUSTRATIO_4 4

#define FR_NEG_FRUSTRATIO_3 3

#define FR_NEG_FRUSTRATIO_2 2

#define FR_NEG_FRUSTRATIO_1 1

#define G_MWO_MATRIX_XX_XY_I 0

#define G_TX_DXT_FRAC 11

#define G_TT_RGBA16 32768

#define G_ZS_PIXEL 0

#define G_MW_MATRIX 0

#define G_CCMUX_PRIMITIVE_ALPHA 10

#define G_LOD 1048576

#define G_TRI_SHADE 204

#define G_MV_L5 144

#define G_CYC_1CYCLE 0

#define G_MV_L4 142

#define G_MV_L3 140

#define G_SETCOMBINE 252

#define G_MV_L2 138

#define G_IM_SIZ_16b_LOAD_BLOCK 2

#define G_MV_L7 148

#define G_MV_L6 146

#define G_CCMUX_LOD_FRACTION 13

#define G_RDP_TRI_ZBUFF_MASK 1

#define G_TEXTURE -69

#define G_TEXTURE_IMAGE_FRAC 2

#define G_MW_NUMLIGHT 2

#define G_TD_CLAMP 0

#define G_MDSFT_TEXTDETAIL 17

#define G_IM_FMT_RGBA 0

#define G_SETTILE 245

#define G_CCMUX_TEXEL1_ALPHA 9

#define G_BL_A_IN 0

#define G_MV_L1 136

#define G_MV_L0 134

#define G_IM_SIZ_32b 3

#define G_AD_DISABLE 48

#define G_IM_SIZ_4b_BYTES 0

#define IM_RD 64

#define G_IM_SIZ_16b_BYTES 2

#define G_CCMUX_TEXEL1 2

#define G_CCMUX_TEXEL0 1

#define G_BL_CLR_IN 0

#define G_CD_BAYER 64

#define G_SETENVCOLOR 251

#define G_MV_MATRIX_4 156

#define G_MWO_POINT_ZSCREEN 28

#define G_RDPLOADSYNC 230

#define G_ZS_PRIM 4

#define G_MDSFT_RGBDITHER 6

#define G_RDPHALF_CONT -78

#define G_RM_FOG_SHADE_A 3355443200

#define G_AC_NONE 0

#define G_IM_SIZ_4b_SHIFT 2

#define G_MV_MATRIX_3 154

#define G_TF_AVERAGE 12288

#define G_MV_MATRIX_2 152

#define G_MV_MATRIX_1 158

#define G_CCMUX_TEXEL0_ALPHA 8

#define G_TX_NOLOD 0

#define G_MW_PERSPNORM 14

#define G_SETKEYGB 234

#define G_IM_SIZ_32b_LOAD_BLOCK 3

#define G_SETBLENDCOLOR 249

#define G_SETTIMG 253

#define G_CV_K2 -89

#define G_CV_K1 -43

#define G_CV_K0 175

#define G_RM_FOG_PRIM_A 3288334336

#define G_BL_0 3

#define G_TRI_SHADE_TXTR 206

#define G_LINE3D -75

#define G_BL_1 2

#define G_TEXTURE_GEN_LINEAR 524288

#define G_CV_K5 42

#define G_TX_MIRROR 1

#define G_CV_K4 114

#define G_CV_K3 222

#define G_RDP_TRI_SHADE_MASK 4

#define G_IM_SIZ_16b_INCR 0

#define G_TRI_TXTR 202

#define ALPHA_CVG_SEL 8192

#define CVG_DST_FULL 512

#define G_CULL_BACK 8192

#define G_MTX_NOPUSH 0

#define G_MTX_MUL 0

#define G_IM_SIZ_32b_BYTES 4

#define G_AD_NOISE 32

#define G_IM_SIZ_DD 5

#define G_ACMUX_PRIM_LOD_FRAC 6

#define G_MWO_FOG 0

#define G_MWO_POINT_XYSCREEN 24

#define G_MWO_MATRIX_XX_XY_F 32

#define G_ZBUFFER 1

typedef ulong size_t;

typedef struct exception exception, *Pexception;

struct exception {
    int anonymous_0;
    int anonymous_1;
    void * error;
};

typedef struct c_itementry c_itementry, *Pc_itementry;

typedef struct object_header object_header, *Pobject_header;

typedef struct object_standard object_standard, *Pobject_standard;

struct object_standard {
    u16 extrascale:2;
    u8 hidden2:1;
    u8 type:1;
    u16 obj;
    u16 pad;
    u32 flags;
    u32 flags2;
    void * runtime_ptr_obj_posdata;
    void * runtime_ptr_obj_instance_controller;
    void * runtime_MATRIX0;
    void * runtime_MATRIX1;
    void * runtime_MATRIX2;
    void * runtime_MATRIX3;
    void * runtime_MATRIX4;
    void * runtime_MATRIX5;
    void * runtime_MATRIX6;
    void * runtime_MATRIX7;
    void * runtime_MATRIX8;
    void * runtime_MATRIX9;
    void * runtime_MATRIXA;
    void * runtime_MATRIXB;
    void * runtime_MATRIXC;
    void * runtime_MATRIXD;
    void * runtime_MATRIXE;
    void * runtime_MATRIXF;
    f32 runtime_x_pos;
    f32 runtime_y_pos;
    f32 runtime_z_pos;
    int runtime_bitflags;
    int ptr_allocated_collisiondata_block;
    int field_6C;
    float field_70;
    short damage;
    short maxdamage;
    char field_78;
    char field_79;
    char field_7A;
    char field_7B;
    char field_7C;
    char field_7D;
    char field_7E;
    char field_7F;
};

struct c_itementry {
    struct object_header * header;
    void * filename;
    float anonymous_1;
    float anonymous_2;
    int anonymous_3;
};

struct object_header {
    int offset_obj_table;
    struct object_standard * ptr_archetype;
    int offset_obj_offset_block;
    short num_offset_entries;
    short num_object_grps;
    float anonymous_4;
    short num_table_entries;
    short num_image_entries;
    int offset_img_declaration;
    int is_loaded_in_mem;
};

typedef struct $732F89B2624665A943E52F38E86E4CBC $732F89B2624665A943E52F38E86E4CBC, *P$732F89B2624665A943E52F38E86E4CBC;

struct $732F89B2624665A943E52F38E86E4CBC {
};

typedef struct fileentry fileentry, *Pfileentry;

struct fileentry {
    s32 index;
    string * filename;
    s32 hw_address;
};

typedef enum KSEG {
} KSEG;

typedef struct $B84834CAACFDCE10B1334219ADA11FDA $B84834CAACFDCE10B1334219ADA11FDA, *P$B84834CAACFDCE10B1334219ADA11FDA;

typedef struct $B84834CAACFDCE10B1334219ADA11FDA ALGlobals;

typedef struct ALSynth ALSynth, *PALSynth;

typedef struct ALPlayer_s ALPlayer_s, *PALPlayer_s;

typedef struct ALPlayer_s ALPlayer;

typedef ALDMAproc (* ALDMANew)(void *);

typedef struct ALHeap ALHeap, *PALHeap;

typedef s32 ALMicroTime;

typedef ALMicroTime (* ALVoiceHandler)(void *);

struct ALSynth {
    ALPlayer * head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    struct ALHeap * heap;
    struct ALParam_s * paramList;
    struct ALMainBus_s * mainBus;
    struct ALAuxBus_s * auxBus;
    struct ALFilter_s * outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};

struct $B84834CAACFDCE10B1334219ADA11FDA {
    struct ALSynth drvr;
};

struct ALHeap {
    u8 * base;
    u8 * cur;
    s32 len;
    s32 count;
};

struct ALPlayer_s {
    struct ALPlayer_s * next;
    void * clientData;
    ALVoiceHandler handler;
    ALMicroTime callTime;
    s32 samplesLeft;
};

typedef struct p_itementry p_itementry, *Pp_itementry;

typedef struct PitemZ_header PitemZ_header, *PPitemZ_header;

typedef struct item_related item_related, *Pitem_related;

struct item_related {
    short num_entries_in_block;
    short field_2;
    struct prop_pos_data * ptr_block;
    short total_cmd_indexval;
    short field_A;
};

struct PitemZ_header {
    int microcode_entry_num;
    struct item_related * anonymous_1;
    short anonymous_2;
    short field_E;
    float drawdistance;
    float anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
};

struct p_itementry {
    struct PitemZ_header * header;
    void * filename;
    float scale;
};

typedef struct lightfixture lightfixture, *Plightfixture;

struct lightfixture {
    short index;
    short RESERVED;
    union Gfx * ptr_start_pertinent_DL;
    int ptr_end_pertinent_DL;
};

typedef struct weapon_firing_animation_table weapon_firing_animation_table, *Pweapon_firing_animation_table;

struct weapon_firing_animation_table {
    s32 anonymous_0;
    f32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;
    f32 anonymous_4;
    f32 anonymous_5;
    f32 anonymous_6;
    f32 anonymous_7;
    f32 anonymous_8;
    f32 anonymous_9;
    f32 anonymous_10;
    f32 anonymous_11;
    f32 anonymous_12;
    f32 anonymous_13;
    f32 anonymous_14;
    f32 anonymous_15;
    f32 anonymous_16;
    f32 anonymous_17;
};

typedef struct Gitemheader Gitemheader, *PGitemheader;

typedef struct model_data model_data, *Pmodel_data;

struct Gitemheader {
    int offset_objtable;
    struct model_data * guntype_modeldata;
    int offset_objblock;
    short num05soffset_entries;
    short num_objgroups;
    float drawdistance;
    u16 num_entries;
    u16 num_images;
    int offset_imgdecl;
    u32 isloaded;
};

struct model_data {
    u32 anonymous_0;
    struct prop_pos_data * anonymous_1;
    u32 anonymous_2;
};

typedef struct mp_weaponset_weapon mp_weaponset_weapon, *Pmp_weaponset_weapon;

struct mp_weaponset_weapon {
    int anonymous_0;
    int anonymous_1;
    float anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
};

typedef struct ramrom_struct ramrom_struct, *Pramrom_struct;

typedef struct ramrom_entry ramrom_entry, *Pramrom_entry;

struct ramrom_entry {
    int ROMaddress;
    int is_locked;
};

struct ramrom_struct {
    struct ramrom_entry dam1;
    struct ramrom_entry dam2;
    struct ramrom_entry facility1;
    struct ramrom_entry facility2;
    struct ramrom_entry facility3;
    struct ramrom_entry runway1;
    struct ramrom_entry runway2;
    struct ramrom_entry bunker1_1;
    struct ramrom_entry bunker1_2;
    struct ramrom_entry silo1;
    struct ramrom_entry silo2;
    struct ramrom_entry frigate1;
    struct ramrom_entry frigate2;
    struct ramrom_entry train;
    struct ramrom_entry null;
};

typedef struct $9574A80C820E0B95666ECD0A99E160BE $9574A80C820E0B95666ECD0A99E160BE, *P$9574A80C820E0B95666ECD0A99E160BE;

typedef struct $9574A80C820E0B95666ECD0A99E160BE ALSeqData;

struct $9574A80C820E0B95666ECD0A99E160BE {
    u8 * offset;
};

typedef struct mp_stage_playercount mp_stage_playercount, *Pmp_stage_playercount;

struct mp_stage_playercount {
    short stage;
    char min;
    char max;
};

typedef struct music_setup music_setup, *Pmusic_setup;

struct music_setup {
    short stage_id;
    short main_music;
    short bg_sound;
    short xtrack;
};

typedef struct MP_game_length_settings MP_game_length_settings, *PMP_game_length_settings;

struct MP_game_length_settings {
    u16 text_preset;
    u16 padding;
    int time;
    int points;
};


// WARNING! conflicting data type names: /GE Current Master.h/ALVoiceHandler - /libaudio.h/ALVoiceHandler

typedef struct memoryallocation memoryallocation, *Pmemoryallocation;

struct memoryallocation {
    int number;
    void * string;
};

typedef struct $62F109188EB304B8EC258AA93B51CC96 $62F109188EB304B8EC258AA93B51CC96, *P$62F109188EB304B8EC258AA93B51CC96;

struct $62F109188EB304B8EC258AA93B51CC96 {
};


// WARNING! conflicting data type names: /GE Current Master.h/rgba_val - /bondgame.h/rgba_val


// WARNING! conflicting data type names: /GE Current Master.h/LEVEL_SOLO_SEQUENCE - /bondgame.h/LEVEL_SOLO_SEQUENCE

typedef struct mcm_layout mcm_layout, *Pmcm_layout;

struct mcm_layout {
    int xpos;
    int ypos;
};

typedef struct GUARDdata GUARDdata, *PGUARDdata;

struct GUARDdata {
    u16 chrnum;
    char accuracyrating;
    char speedrating;
    char firecount.left;
    char firecount.right;
    char headnum;
    enum guard_action_type actiontype;
    char sleep;
    char invalidmove;
    char numclosearghs;
    char numarghs;
    char fadealpha;
    char field_D;
    char field_E;
    char bodynum;
    char beligerancy;
    char field_11;
    short special_bitflags;
    int guard_bitflags;
    int POSdata_pointer;
    int MODELdata_pointer;
    int pertains_to_action61;
    f32 chrwidth;
    int chrheight;
    int bond_position;
    int field_30;
    short field_34;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int path_target_position;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    char type_of_motion;
    char distance_counter_or_something;
    short distance_to_target;
    int field_5C;
    int target_position;
    int field_64;
    int field_68;
    int field_6C;
    int path_segment_coverage;
    int path_segment_length;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int segment_coverage;
    int segment_length;
    int field_9C;
    int field_A0;
    float field_A4;
    float field_A8;
    float clipping_height;
    float field_B0;
    float field_B4;
    float field_B8;
    struct xyzpoint prevpos;
    int field_C8;
    int field_CC;
    float reaction_time;
    int last_bond_detection_time;
    float field_D8;
    float field_DC;
    float field_E0;
    int lastshooter;
    int timeshooter;
    float hearingscale;
    int field_F0;
    char field_F4;
    char field_F5;
    char field_F6;
    char field_F7;
    char field_F8;
    char field_F9;
    char field_FA;
    char field_FB;
    int damage;
    f32 maxdamage;
    int action_block_pointer;
    short action_block_offset;
    short action_block_return;
    char userbyte1;
    char userbyte2;
    char guardtype_bitflags_scientist;
    char randomvalue;
    int loopcounter;
    short preset_of_2328_object_to_interact_with;
    short FC_target;
    short FA_target;
    short FB_target;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    float field_13C;
    float field_140;
    float field_144;
    float field_148;
    float field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int handle_positiondata[2];
    int ptr_SEbuffer1;
    int ptr_SEbuffer2;
    int ptr_SEbuffer3;
    int ptr_SEbuffer4;
    int field_178;
    int field_17C;
    char field_180;
    char field_181;
    char field_182;
    char field_183;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    char field_1AC;
    char field_1AD;
    char field_1AE;
    char field_1AF;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int handle_positiondata_hat;
};

typedef struct intro_animation intro_animation, *Pintro_animation;

struct intro_animation {
    enum ANIMATIONS animID;
    float startframeoffset;
    float playback_speed;
    int camera_preset;
};

typedef struct $4BEAA6302150DFF77A6D6B5C2F812979 $4BEAA6302150DFF77A6D6B5C2F812979, *P$4BEAA6302150DFF77A6D6B5C2F812979;

struct $4BEAA6302150DFF77A6D6B5C2F812979 {
    float col[3];
    float pos[3];
    float a1;
    float a2;
};

typedef struct playerperm playerperm, *Pplayerperm;

struct playerperm {
    int shotcount[7];
    int killcount;
    int ggkillcount;
    int kills[4];
    int drawplayercount;
    float distance;
    int backshotcount;
    float armourcount;
    int fastest2kills;
    int slowest2kills;
    int longestlife;
    s32 shortestlife;
    int most_killed_one_life;
    int most_killed_one_time;
    float handicap;
    int flag_counter;
    float player_perspective_height;
    char order_out_in_yolt;
    char have_token_or_goldengun;
    char autoaim;
    char sight;
    int killed_civilians;
};

typedef struct $B24B31290AB3F51AC02030577BB60BEE $B24B31290AB3F51AC02030577BB60BEE, *P$B24B31290AB3F51AC02030577BB60BEE;

struct $B24B31290AB3F51AC02030577BB60BEE {
};

typedef struct $1D3114E51680E29F8350BFE921C29711 $1D3114E51680E29F8350BFE921C29711, *P$1D3114E51680E29F8350BFE921C29711;

typedef struct $1D3114E51680E29F8350BFE921C29711 ALKeyMap;

struct $1D3114E51680E29F8350BFE921C29711 {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
};

typedef struct enviroment_struct enviroment_struct, *Penviroment_struct;

struct enviroment_struct {
    int index;
    float anonymous_0;
    float anonymous_1;
    float anonymous_2;
    float anonymous_3;
    float anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
    int anonymous_8;
    int anonymous_9;
    float anonymous_10;
    int anonymous_11;
    float anonymous_12;
    float anonymous_13;
    float anonymous_14;
    int anonymous_15;
    float anonymous_16;
    int anonymous_17;
    int anonymous_18;
    float anonymous_19;
    float anonymous_20;
    float anonymous_21;
};


// WARNING! conflicting data type names: /GE Current Master.h/BODIES - /bondgame.h/BODIES

typedef struct $2903A050EBC6442F98207E1AE6ED2D96 $2903A050EBC6442F98207E1AE6ED2D96, *P$2903A050EBC6442F98207E1AE6ED2D96;

typedef struct $2903A050EBC6442F98207E1AE6ED2D96 ALSndPlayer;

typedef struct ALEventQueue ALEventQueue, *PALEventQueue;

typedef struct ALEvent ALEvent, *PALEvent;

typedef union _union_144 _union_144, *P_union_144;

typedef struct ALMIDIEvent ALMIDIEvent, *PALMIDIEvent;

typedef struct ALTempoEvent ALTempoEvent, *PALTempoEvent;

typedef struct ALEndEvent ALEndEvent, *PALEndEvent;

typedef struct ALNoteEvent ALNoteEvent, *PALNoteEvent;

typedef struct ALVolumeEvent ALVolumeEvent, *PALVolumeEvent;

typedef struct ALSeqpLoopEvent ALSeqpLoopEvent, *PALSeqpLoopEvent;

typedef struct ALSeqpVolEvent ALSeqpVolEvent, *PALSeqpVolEvent;

typedef struct ALSeqpPriorityEvent ALSeqpPriorityEvent, *PALSeqpPriorityEvent;

typedef struct ALSeqpSeqEvent ALSeqpSeqEvent, *PALSeqpSeqEvent;

typedef struct ALSeqpBankEvent ALSeqpBankEvent, *PALSeqpBankEvent;

typedef struct ALOscEvent ALOscEvent, *PALOscEvent;

typedef struct ALSeqMarker ALSeqMarker, *PALSeqMarker;

typedef struct ALBank_s ALBank_s, *PALBank_s;

typedef struct ALBank_s ALBank;

typedef struct ALVoiceState_s ALVoiceState_s, *PALVoiceState_s;

typedef struct ALInstrument ALInstrument, *PALInstrument;

typedef struct ALVoice_s ALVoice;

typedef struct ALSound_s ALSound_s, *PALSound_s;

typedef struct ALSound_s ALSound;

typedef struct ALEnvelope ALEnvelope, *PALEnvelope;


// WARNING! conflicting data type names: /libaudio.h/ALKeyMap - /GE Current Master.h/ALKeyMap

struct ALSeqpSeqEvent {
    void * seq;
};

struct ALVolumeEvent {
    struct ALVoice_s * voice;
    ALMicroTime delta;
    u8 vol;
};

struct ALSeqpPriorityEvent {
    u8 chan;
    u8 priority;
};

struct ALSeqpBankEvent {
    ALBank * bank;
};

struct ALMIDIEvent {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
};

struct ALOscEvent {
    struct ALVoiceState_s * vs;
    void * oscState;
    u8 chan;
};

struct ALTempoEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
};

struct ALSeqpLoopEvent {
    struct ALSeqMarker * start;
    struct ALSeqMarker * end;
    s32 count;
};

struct ALNoteEvent {
    struct ALVoice_s * voice;
};

struct ALEndEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
};

struct ALSeqpVolEvent {
    s16 vol;
};

union _union_144 {
    struct ALMIDIEvent midi;
    struct ALTempoEvent tempo;
    struct ALEndEvent end;
    struct ALNoteEvent note;
    struct ALVolumeEvent vol;
    struct ALSeqpLoopEvent loop;
    struct ALSeqpVolEvent spvol;
    struct ALSeqpPriorityEvent sppriority;
    struct ALSeqpSeqEvent spseq;
    struct ALSeqpBankEvent spbank;
    struct ALOscEvent osc;
};

struct ALEvent {
    s16 type;
    union _union_144 msg;
};

struct ALBank_s {
    s16 instCount;
    u8 flags;
    u8 pad;
    s32 sampleRate;
    struct ALInstrument * percussion;
    struct ALInstrument * instArray[1];
};

struct ALInstrument {
    u8 volume;
    ALPan pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSound * soundArray[1];
};

struct ALEventQueue {
    ALLink freeList;
    ALLink allocList;
    s32 eventCount;
};

struct ALVoiceState_s {
    struct ALVoiceState_s * next;
    ALVoice voice;
    ALSound * sound;
    ALMicroTime envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
};

struct ALEnvelope {
    ALMicroTime attackTime;
    ALMicroTime decayTime;
    ALMicroTime releaseTime;
    u8 attackVolume;
    u8 decayVolume;
};

struct ALSound_s {
    struct ALEnvelope * envelope;
    struct ALKeyMap * keyMap;
    ALWaveTable * wavetable;
    ALPan samplePan;
    u8 sampleVolume;
    u8 flags;
};

struct ALSeqMarker {
    u8 * curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
};

struct $2903A050EBC6442F98207E1AE6ED2D96 {
    ALPlayer node;
    struct ALEventQueue evtq;
    struct ALEvent nextEvent;
    struct ALSynth * drvr;
    void * sndState;
};


// WARNING! conflicting data type names: /GE Current Master.h/PROJECTILES - /bondgame.h/PROJECTILES

typedef struct solo_target_times solo_target_times, *Psolo_target_times;

struct solo_target_times {
    short agent_time;
    short secret_agent_time;
    short OO_agent_time;
};


// WARNING! conflicting data type names: /GE Current Master.h/video_settings - /video.h/video_settings


// WARNING! conflicting data type names: /GE Current Master.h/LEVEL_INDEX - /bondgame.h/LEVEL_INDEX

typedef struct ejected_cart ejected_cart, *Pejected_cart;

struct ejected_cart {
    struct Gitemheader * header;
    u8 * text;
};

typedef struct mission_folder_setup mission_folder_setup, *Pmission_folder_setup;

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

typedef struct MP_selectable_chars MP_selectable_chars, *PMP_selectable_chars;


// WARNING! conflicting data type names: /GE Current Master.h/HEADS - /bondgame.h/HEADS

struct MP_selectable_chars {
    short text_preset;
    char gender;
    char select_photo;
    short body;
    enum HEADS head;
    f32 pov;
};

typedef struct $DD54060F307CC511C1231C522D614BD1 $DD54060F307CC511C1231C522D614BD1, *P$DD54060F307CC511C1231C522D614BD1;

struct $DD54060F307CC511C1231C522D614BD1 {
    uchar * base;
    int fmt;
    int siz;
    int xsize;
    int ysize;
    int lsize;
    int addr;
    int w;
    int h;
    int s;
    int t;
};

typedef struct explosion_death_animation explosion_death_animation, *Pexplosion_death_animation;

struct explosion_death_animation {
    int anonymous_0;
    int anonymous_1;
    float anonymous_2;
    float anonymous_3;
    float anonymous_4;
    float anonymous_5;
    float anonymous_6;
};


// WARNING! conflicting data type names: /GE Current Master.h/ALDMAproc - /libaudio.h/ALDMAproc

typedef struct $5B527B901AC7720CA636E505FD36A43E $5B527B901AC7720CA636E505FD36A43E, *P$5B527B901AC7720CA636E505FD36A43E;

typedef struct $5B527B901AC7720CA636E505FD36A43E ALCSeqMarker;

struct $5B527B901AC7720CA636E505FD36A43E {
    u8 * curLoc[16];
    u8 * curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
};

typedef struct MP_sight_aim_settings MP_sight_aim_settings, *PMP_sight_aim_settings;

struct MP_sight_aim_settings {
    char anonymous_0;
    char field_1;
    char sight;
    char autoaim;
};

typedef struct $4131C7287544E0031FFD60902D16EE66 $4131C7287544E0031FFD60902D16EE66, *P$4131C7287544E0031FFD60902D16EE66;

struct $4131C7287544E0031FFD60902D16EE66 {
};

typedef struct mp_weapon_set_text_entry mp_weapon_set_text_entry, *Pmp_weapon_set_text_entry;

struct mp_weapon_set_text_entry {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
    struct mp_weaponset_weapon * entries;
};

typedef struct room_index room_index, *Proom_index;

struct room_index {
    short bitflags;
    char model_bin_loaded;
    char bitflags2;
    void * ptr_point_index;
    void * ptr_expanded_mapping_info;
    void * ptr_secondary_expanded_mapping_info;
    int csize_point_index_binary;
    int csize_primary_DL_binary;
    int csize_secondary_DL_binary;
    int usize_point_index_binary;
    int usize_primary_DL_binary;
    int usize_secondary_DL_binary;
    int cur_room_totalsize;
    void * ptr_unique_collision_points;
    int bitflags3;
    char room_loaded_mask;
    char field_35;
    short field_36;
    float minxbounds;
    float minybounds;
    float minzbounds;
    float maxxbounds;
    float maxybounds;
    float maxzbounds;
};


// WARNING! conflicting data type names: /GE Current Master.h/vu32 - /types.h/vu32

typedef struct weapon_stats weapon_stats, *Pweapon_stats;

struct weapon_stats {
    float field_0;
    struct xyzpoint position;
    float field_0x10;
    float field_0x14;
    float field_0x18;
    enum AMMOTYPES ammotype;
    short mag_size;
    short time_between_shots;
    char objects_shoot_through;
    char field_25;
    short sound;
    struct Gitemheader * ptr_cartridge_struct;
    float destruction_amount;
    float inaccuracy;
    float zoom;
    float field_0x38;
    float field_0x3c;
    float sway;
    int recoilspeed;
    float recoil_back;
    float recoil_up;
    float bolt_recoil_back;
    float loudness;
    float loudness2;
    float field_0x5c;
    float field_0x60;
    float field_0x64;
    int field_68;
    int bitflags;
};


// WARNING! conflicting data type names: /GE Current Master.h/ALDMANew - /libaudio.h/ALDMANew


// WARNING! conflicting data type names: /GE Current Master.h/RamRomBuffer - /ramrom.h/RamRomBuffer

typedef struct resource_lookup_data resource_lookup_data, *Presource_lookup_data;

struct resource_lookup_data {
    int ROM_filesize;
    int temp_copy_remaining;
    int temp_filesize_PC_file;
    int remaining_buf_size;
    char membank_loaded_to;
    char field_11;
    short RESERVED;
};

typedef struct $9B76E6653943F067895E1B40895EE2D1 $9B76E6653943F067895E1B40895EE2D1, *P$9B76E6653943F067895E1B40895EE2D1;

struct $9B76E6653943F067895E1B40895EE2D1 {
    struct ALADPCMloop * loop;
    struct ALADPCMBook * book;
};

typedef struct MP_controller_configuration_menu MP_controller_configuration_menu, *PMP_controller_configuration_menu;

struct MP_controller_configuration_menu {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
};

typedef struct intro_char intro_char, *Pintro_char;

struct intro_char {
    int body;
    int head;
    short text1;
    short text2;
    short text3;
    short RESERVED;
    int flag;
};

typedef struct $4FA29701263D2EF277B845E0B6B9C553 $4FA29701263D2EF277B845E0B6B9C553, *P$4FA29701263D2EF277B845E0B6B9C553;

struct $4FA29701263D2EF277B845E0B6B9C553 {
    short type;
    char misc[30];
};


// WARNING! conflicting data type names: /GE Current Master.h/ALEnvelope - /libaudio.h/ALEnvelope

typedef struct TLB_manager_table TLB_manager_table, *PTLB_manager_table;

typedef struct TLB_manager_table_entry TLB_manager_table_entry, *PTLB_manager_table_entry;

struct TLB_manager_table_entry {
    int context_value;
    int pagenum;
    longlong reserved;
};

struct TLB_manager_table {
    struct TLB_manager_table_entry entry[128];
};

typedef struct $732F89B2624665A943E52F38E86E4CBC OSLogFileHdr;

typedef struct image_entry image_entry, *Pimage_entry;

struct image_entry {
    char flag1;
    char flag2;
    short size;
    char flag3;
    char flag4;
    char flag5;
    char flag6;
};

typedef struct tile_rgb tile_rgb, *Ptile_rgb;

struct tile_rgb {
    u8 red;
    u8 green;
    u8 blue;
};

typedef enum BODY_MODELS {
    BODY_MODELS_0=0,
    BODY_MODELS_1=1,
    BODY_MODELS_10=16,
    BODY_MODELS_11=17,
    BODY_MODELS_12=18,
    BODY_MODELS_13=19,
    BODY_MODELS_14=20,
    BODY_MODELS_15=21,
    BODY_MODELS_17=23,
    BODY_MODELS_18=24,
    BODY_MODELS_1A=26,
    BODY_MODELS_1B=27,
    BODY_MODELS_1C=28,
    BODY_MODELS_1D=29,
    BODY_MODELS_1E=30,
    BODY_MODELS_1F=31,
    BODY_MODELS_2=2,
    BODY_MODELS_20=32,
    BODY_MODELS_21=33,
    BODY_MODELS_22=34,
    BODY_MODELS_23=35,
    BODY_MODELS_24=36,
    BODY_MODELS_25=37,
    BODY_MODELS_26=38,
    BODY_MODELS_27=39,
    BODY_MODELS_28=40,
    BODY_MODELS_29=-1,
    BODY_MODELS_3=3,
    BODY_MODELS_4=4,
    BODY_MODELS_5=5,
    BODY_MODELS_6=6,
    BODY_MODELS_7=7,
    BODY_MODELS_8=8,
    BODY_MODELS_9=9,
    BODY_MODELS_A=10,
    BODY_MODELS_B=11,
    BODY_MODELS_C=12,
    BODY_MODELS_D=13,
    BODY_MODELS_E=14,
    BODY_MODELS_F=15,
    BOILER_SUIT=22,
    JUNGLE_SUIT=0,
    SNOWSUIT=25
} BODY_MODELS;

typedef struct mp_stage_setup mp_stage_setup, *Pmp_stage_setup;

struct mp_stage_setup {
    short folder_text_preset;
    short select_screen_text_preset;
    int photo;
    int stage_id;
    int unlock_after;
    int min_player;
    int max_player;
};

typedef struct $3DC209F5817990864D0852F5D77FEFB7 $3DC209F5817990864D0852F5D77FEFB7, *P$3DC209F5817990864D0852F5D77FEFB7;

struct $3DC209F5817990864D0852F5D77FEFB7 {
};

typedef struct struct_1 struct_1, *Pstruct_1;

struct struct_1 {
    int anonymous_0;
    float anonymous_1;
    float anonymous_2;
    float anonymous_3;
    float anonymous_4;
    float anonymous_5;
    float anonymous_6;
    float anonymous_7;
    float anonymous_8;
    float anonymous_9;
    float anonymous_10;
    float anonymous_11;
    float anonymous_12;
    float anonymous_13;
    float anonymous_14;
    float anonymous_15;
    float anonymous_16;
    float anonymous_17;
};

typedef struct struct_0 struct_0, *Pstruct_0;

struct struct_0 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    void * anonymous_5;
    int anonymous_6;
};

typedef struct struct_5 struct_5, *Pstruct_5;

struct struct_5 {
    int anonymous_0;
    void * anonymous_1;
    int anonymous_2;
};


// WARNING! conflicting data type names: /GE Current Master.h/vs32 - /types.h/vs32

typedef struct struct_4 struct_4, *Pstruct_4;

struct struct_4 {
    int anonymous_0;
    float anonymous_1;
    float anonymous_2;
    float anonymous_3;
};

typedef struct object_animation_controller object_animation_controller, *Pobject_animation_controller;

struct object_animation_controller {
    void * ptranimation;
    u16 offsettocurcmd;
    u16 waitcounter;
    u32 imagenum;
    f32 rotation;
    f32 curzoomx;
    f32 startzoomx;
    f32 zoomxtimer;
    f32 initialzoomx;
    f32 finalzoomx;
    f32 curzoomy;
    f32 startzoomy;
    f32 zoomytimer;
    f32 initialzoomy;
    f32 finalzoomy;
    f32 curhorizontalpos;
    f32 starthorscroll;
    f32 horscrolltimer;
    f32 horinitpos;
    f32 horfinalpos;
    f32 curverpos;
    f32 startverscroll;
    f32 verscrolltimer;
    f32 verinitpos;
    f32 verfinalpos;
    u8 curredcomponant;
    u8 initredcomponant;
    u8 finalredcomponant;
    u8 curgreencomponant;
    u8 initgreencomponant;
    u8 finalgreencomponant;
    u8 curbluecomponant;
    u8 initbluecomponant;
    u8 finalbluecomponant;
    u8 curalphacomponant;
    u8 initalphacomponant;
    u8 finalalphacomponant;
    f32 startcolorshift;
    f32 colorshifttimer;
};

typedef struct struct_6 struct_6, *Pstruct_6;

struct struct_6 {
    int anonymous_0;
    char anonymous_1;
    char field_5;
    char field_6;
    char field_7;
    void * anonymous_2;
    int anonymous_3;
};

typedef struct struct_9 struct_9, *Pstruct_9;

struct struct_9 {
    void * address;
    void * ptr_name;
};

typedef struct explosion_animation explosion_animation, *Pexplosion_animation;

struct explosion_animation {
    void * direction;
    int count;
};


// WARNING! conflicting data type names: /GE Current Master.h/object_standard - /bondtypes.h/object_standard

typedef struct MP_handicap_menu MP_handicap_menu, *PMP_handicap_menu;

struct MP_handicap_menu {
    short text_preset;
    short padding;
    float damage_modifier;
};

typedef struct struck_animation_table struck_animation_table, *Pstruck_animation_table;

struct struck_animation_table {
    int anonymous_0;
    int anonymous_1;
    float anonymous_2;
    float anonymous_3;
    int anonymous_4;
    float anonymous_5;
    float anonymous_6;
};

typedef enum OS_SC {
} OS_SC;

typedef struct $3875EDF92ACCFC55C5A87BF2DE611375 $3875EDF92ACCFC55C5A87BF2DE611375, *P$3875EDF92ACCFC55C5A87BF2DE611375;

typedef struct $3875EDF92ACCFC55C5A87BF2DE611375 ALSeqPlayer;

typedef struct ALSeq_s ALSeq_s, *PALSeq_s;

typedef struct ALSeq_s ALSeq;

typedef struct ALChanState ALChanState, *PALChanState;

typedef struct ALVoiceState_s ALVoiceState;

typedef ALMicroTime (* ALOscInit)(void * *, f32 *, u8, u8, u8, u8);

typedef ALMicroTime (* ALOscUpdate)(void *, f32 *);

typedef void (* ALOscStop)(void *);

typedef u8 ALFxId;

struct ALSeq_s {
    u8 * base;
    u8 * trackStart;
    u8 * curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
};

struct ALChanState {
    struct ALInstrument * instrument;
    s16 bendRange;
    ALFxId fxId;
    ALPan pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
};

struct $3875EDF92ACCFC55C5A87BF2DE611375 {
    ALPlayer node;
    struct ALSynth * drvr;
    ALSeq * target;
    ALBank * bank;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    struct ALEvent nextEvent;
    struct ALEventQueue evtq;
    struct ALChanState * chanState;
    ALVoiceState * vAllocHead;
    ALVoiceState * vAllocTail;
    ALVoiceState * vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
    struct ALSeqMarker * loopStart;
    struct ALSeqMarker * loopEnd;
};

typedef struct $8A2C38822146935C7EE1F49BBD28923A $8A2C38822146935C7EE1F49BBD28923A, *P$8A2C38822146935C7EE1F49BBD28923A;

struct $8A2C38822146935C7EE1F49BBD28923A {
    u8 * base;
    u8 * cur;
};

typedef struct $4DC9E63407FE56118E8436A326234A26 $4DC9E63407FE56118E8436A326234A26, *P$4DC9E63407FE56118E8436A326234A26;

typedef struct OSScMsg OSScMsg, *POSScMsg;

typedef struct SCClient_s SCClient_s, *PSCClient_s;

typedef struct SCClient_s OSScClient;

typedef struct OSScTask_s OSScTask_s, *POSScTask_s;

typedef struct OSScTask_s OSScTask;

typedef union OSTask OSTask, *POSTask;

typedef struct OSTask_t OSTask_t, *POSTask_t;

struct OSTask_t {
    u32 type;
    u32 flags;
    u64 * ucode_boot;
    u32 ucode_boot_size;
    u64 * ucode;
    u32 ucode_size;
    u64 * ucode_data;
    u32 ucode_data_size;
    u64 * dram_stack;
    u32 dram_stack_size;
    u64 * output_buff;
    u64 * output_buff_size;
    u64 * data_ptr;
    u32 data_size;
    u64 * yield_data_ptr;
    u32 yield_data_size;
};

union OSTask {
    struct OSTask_t t;
    longlong force_structure_alignment;
};

struct SCClient_s {
    struct SCClient_s * next;
    OSMesgQueue * msgQ;
};

struct OSScMsg {
    short type;
    char misc[30];
};

struct OSScTask_s {
    struct OSScTask_s * next;
    u32 state;
    u32 flags;
    void * framebuffer;
    union OSTask list;
    OSMesgQueue * msgQ;
    OSMesg msg;
};

struct $4DC9E63407FE56118E8436A326234A26 {
    struct OSScMsg retraceMsg;
    struct OSScMsg prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg intBuf[8];
    OSMesgQueue cmdQ;
    OSMesg cmdMsgBuf[8];
    OSThread thread;
    OSScClient * clientList;
    OSScTask * audioListHead;
    OSScTask * gfxListHead;
    OSScTask * audioListTail;
    OSScTask * gfxListTail;
    OSScTask * curRSPTask;
    OSScTask * curRDPTask;
};

typedef struct $31E12A8E501C96F6AFEABF3D9309C7AB $31E12A8E501C96F6AFEABF3D9309C7AB, *P$31E12A8E501C96F6AFEABF3D9309C7AB;

struct $31E12A8E501C96F6AFEABF3D9309C7AB {
};

typedef struct animation_something animation_something, *Panimation_something;

struct animation_something {
    int anonymous_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    struct struck_animation_table * field_1C;
    int field_20;
    struct struck_animation_table * field_24;
    int field_28;
};

typedef struct mp_weaponset_set mp_weaponset_set, *Pmp_weaponset_set;

struct mp_weaponset_set {
    struct mp_weaponset_weapon weaponsetarray[8];
};

typedef enum $115CA7B869C920C2EED53D2D8B5DF62E {
    AL_ADPCM_WAVE=0,
    AL_RAW16_WAVE=1
} $115CA7B869C920C2EED53D2D8B5DF62E;

typedef struct $62F109188EB304B8EC258AA93B51CC96 OSLog;

typedef struct $BC3F5F751EBDF5236FD20B6F16C102B1 $BC3F5F751EBDF5236FD20B6F16C102B1, *P$BC3F5F751EBDF5236FD20B6F16C102B1;

typedef struct $BC3F5F751EBDF5236FD20B6F16C102B1 ALSeqFile;


// WARNING! conflicting data type names: /libaudio.h/ALSeqData - /GE Current Master.h/ALSeqData

struct $BC3F5F751EBDF5236FD20B6F16C102B1 {
    s16 revision;
    s16 seqCount;
    struct ALSeqData seqArray[1];
};

typedef struct struct_17 struct_17, *Pstruct_17;

struct struct_17 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
};

typedef struct struct_18 struct_18, *Pstruct_18;

struct struct_18 {
    int BONDdata_item_control_blocks_initdata;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    float field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    float field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    float field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    float field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    float field_D4;
    int field_D8;
    float field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    float field_F8;
    int field_FC;
    float field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    float field_140;
    int field_144;
    int field_148;
    float field_14C;
    int field_150;
    int field_154;
    float field_158;
    int field_15C;
    int field_160;
    float field_164;
    int field_168;
    float field_16C;
    int field_170;
    int field_174;
    float field_178;
    int field_17C;
    int field_180;
    float field_184;
    int field_188;
    int field_18C;
    float field_190;
    int field_194;
    int field_198;
    int field_19C;
    float field_1A0;
    float field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    float field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int anonymous_0;
};

typedef struct struct_19 struct_19, *Pstruct_19;

struct struct_19 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
};

typedef enum controller_buttons {
    A_BUTTON=32768,
    B_BUTTON=16384,
    DUMMY_1=128,
    DUMMY_2=64,
    D_CBUTTONS=4,
    D_JPAD=1024,
    L_CBUTTONS=2,
    L_JPAD=512,
    L_TRIG=32,
    NONE=0,
    R_CBUTTONS=1,
    R_JPAD=256,
    R_TRIG=16,
    START_BUTTON=4096,
    U_CBUTTONS=8,
    U_JPAD=2048,
    Z_TRIG=8192
} controller_buttons;

typedef struct struct_13 struct_13, *Pstruct_13;

struct struct_13 {
    void * anonymous_0;
    int anonymous_1;
};

typedef struct struct_14 struct_14, *Pstruct_14;

struct struct_14 {
    int anonymous_0;
    void * anonymous_1;
    void * anonymous_2;
    void * anonymous_3;
    void * anonymous_4;
    void * anonymous_5;
};

typedef struct struct_15 struct_15, *Pstruct_15;

struct struct_15 {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
    void * anonymous_1;
    int anonymous_2;
    int anonymous_3;
};

typedef struct struct_16 struct_16, *Pstruct_16;

struct struct_16 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
    void * anonymous_6;
};

typedef struct struct_10 struct_10, *Pstruct_10;

struct struct_10 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    short anonymous_3;
    short field_E;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int field_1C;
};

typedef struct struct_11 struct_11, *Pstruct_11;

struct struct_11 {
    int anonymous_0;
    int anonymous_1;
};

typedef struct struct_12 struct_12, *Pstruct_12;

struct struct_12 {
    int anonymous_0;
    char anonymous_1;
    char anonymous_2;
    char anonymous_3;
    char anonymous_4;
    int anonymous_5;
    int anonymous_6;
    void * anonymous_7;
};

typedef struct displaylist displaylist, *Pdisplaylist;

struct displaylist {
    int rdp_pipesync_U;
    int rdp_pipesync_L;
    int rsp_uc05_setothermode_h_U;
    int rsp_uc05_setothermode_h_L;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

typedef struct $4DC9E63407FE56118E8436A326234A26 OSSched;

typedef struct $1E48F79B8290AAF3593C164F3AF34576 $1E48F79B8290AAF3593C164F3AF34576, *P$1E48F79B8290AAF3593C164F3AF34576;

typedef struct $1E48F79B8290AAF3593C164F3AF34576 ALSndpConfig;

struct $1E48F79B8290AAF3593C164F3AF34576 {
    struct ALHeap * heap;
};


// WARNING! conflicting data type names: /GE Current Master.h/ALRawLoop - /libaudio.h/ALRawLoop

typedef struct $329C5B53EB9FEB10BAB0FE888CF3CA8C $329C5B53EB9FEB10BAB0FE888CF3CA8C, *P$329C5B53EB9FEB10BAB0FE888CF3CA8C;

struct $329C5B53EB9FEB10BAB0FE888CF3CA8C {
    int type;
    int length;
    int magic;
    char userdata[24564];
};

typedef struct struct_20 struct_20, *Pstruct_20;

struct struct_20 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
    int anonymous_8;
    int anonymous_9;
    int anonymous_10;
    int anonymous_11;
    int anonymous_12;
    int anonymous_13;
    int anonymous_14;
    int anonymous_15;
    int anonymous_16;
    int anonymous_17;
    int anonymous_18;
    void * anonymous_19;
};

typedef struct struct_21 struct_21, *Pstruct_21;

struct struct_21 {
    int anonymous_0;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
    int anonymous_8;
    int anonymous_9;
    int anonymous_10;
};

typedef struct $4D1BF14BE913BD460FFC9CE94281257F $4D1BF14BE913BD460FFC9CE94281257F, *P$4D1BF14BE913BD460FFC9CE94281257F;

struct $4D1BF14BE913BD460FFC9CE94281257F {
    u8 maxChannels;
    u8 debugFlags;
    struct ALHeap * heap;
    void * initOsc;
    void * updateOsc;
    void * stopOsc;
};

typedef struct struct_22 struct_22, *Pstruct_22;

struct struct_22 {
    int fast3d_related;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    void * field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
};

typedef struct struct_23 struct_23, *Pstruct_23;

struct struct_23 {
    float anonymous_0;
    float anonymous_1;
    float anonymous_2;
    float anonymous_3;
    int field_10;
    int field_14;
};

typedef struct stderr stderr, *Pstderr;

struct stderr {
    int unknown;
    int enable;
    int activated;
    int permitted;
};

typedef struct $A6BB81027E0A18168D58CC4F88C0D058 $A6BB81027E0A18168D58CC4F88C0D058, *P$A6BB81027E0A18168D58CC4F88C0D058;

struct $A6BB81027E0A18168D58CC4F88C0D058 {
};

typedef struct legal_screen_text legal_screen_text, *Plegal_screen_text;

struct legal_screen_text {
    int h_pos;
    int v_pos;
    int flag;
    int flag2;
    short txtID;
    short anonymous_5;
};

typedef struct $EF3ACF09A692D55A7037B16E3DC74014 $EF3ACF09A692D55A7037B16E3DC74014, *P$EF3ACF09A692D55A7037B16E3DC74014;

struct $EF3ACF09A692D55A7037B16E3DC74014 {
    u16 argCount;
    u16 eventID;
};


// WARNING! conflicting data type names: /GE Current Master.h/ALADPCMBook - /libaudio.h/ALADPCMBook

typedef struct $FB5AB5E3B9B01BC4F889CA5C39D284F7 $FB5AB5E3B9B01BC4F889CA5C39D284F7, *P$FB5AB5E3B9B01BC4F889CA5C39D284F7;

struct $FB5AB5E3B9B01BC4F889CA5C39D284F7 {
    struct ALRawLoop * loop;
};

typedef struct sound_related_table sound_related_table, *Psound_related_table;

struct sound_related_table {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
};

typedef struct $06EEA20094C84D54E40B4D9293011B48 $06EEA20094C84D54E40B4D9293011B48, *P$06EEA20094C84D54E40B4D9293011B48;

struct $06EEA20094C84D54E40B4D9293011B48 {
};

typedef struct $1B6B96FDBA53C58847AE432534475AD7 $1B6B96FDBA53C58847AE432534475AD7, *P$1B6B96FDBA53C58847AE432534475AD7;

struct $1B6B96FDBA53C58847AE432534475AD7 {
};

typedef struct levelentry levelentry, *Plevelentry;

struct levelentry {
    int levelID;
    string * bg_seg_filename;
    string * bg_stan_filename;
    f32 levelscale;
    float visibility;
    float unknownfloat;
};

typedef struct $698E1586F824213C2C7D30F8DE84E678 $698E1586F824213C2C7D30F8DE84E678, *P$698E1586F824213C2C7D30F8DE84E678;

struct $698E1586F824213C2C7D30F8DE84E678 {
    void * dmaproc;
    struct ALHeap * heap;
    ALFxId fxType;
};

typedef struct $0120AC1DF4EE79E1F66D1E961D6B23AA $0120AC1DF4EE79E1F66D1E961D6B23AA, *P$0120AC1DF4EE79E1F66D1E961D6B23AA;

struct $0120AC1DF4EE79E1F66D1E961D6B23AA {
    u8 attackVolume;
    u8 decayVolume;
};

typedef struct $698E1586F824213C2C7D30F8DE84E678 ALSynConfig;

typedef struct $EF3ACF09A692D55A7037B16E3DC74014 OSLogItem;

typedef struct displaymode displaymode, *Pdisplaymode;

struct displaymode {
    char anonymous_0;
    char field_1;
    short field_2;
    int anonymous_1;
    int anonymous_2;
    int anonymous_3;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
    int anonymous_8;
    int anonymous_9;
    int anonymous_10;
    int anonymous_11;
    int anonymous_12;
    int anonymous_13;
    int anonymous_14;
    int anonymous_15;
    int anonymous_16;
    int anonymous_17;
    int anonymous_18;
    int anonymous_19;
};

typedef enum LOGIC {
} LOGIC;


// WARNING! conflicting data type names: /GE Current Master.h/ITEM_IDS - /bondgame.h/ITEM_IDS


// WARNING! conflicting data type names: /GE Current Master.h/ALHeap - /libaudio.h/ALHeap

typedef struct $4D1BF14BE913BD460FFC9CE94281257F ALSeqpConfig;

typedef struct struc_3 struc_3, *Pstruc_3;

struct struc_3 {
    int anonymous_0;
    short anonymous_1;
    short anonymous_2;
    float anonymous_3;
    float anonymous_4;
    float aspect;
    float anonymous_6;
    short anonymous_7;
    short anonymous_8;
    short anonymous_9;
    short anonymous_10;
    int anonymous_11;
    int anonymous_12;
    int anonymous_13;
};

typedef struct $1ACCFE7BBF73F7F736AAAE9683E0ED58 $1ACCFE7BBF73F7F736AAAE9683E0ED58, *P$1ACCFE7BBF73F7F736AAAE9683E0ED58;

struct $1ACCFE7BBF73F7F736AAAE9683E0ED58 {
    int dataSize;
    int dlType;
    int flags;
};

typedef struct $35766A9B07B6F07DD8AC188CB6DFE885 $35766A9B07B6F07DD8AC188CB6DFE885, *P$35766A9B07B6F07DD8AC188CB6DFE885;

struct $35766A9B07B6F07DD8AC188CB6DFE885 {
    s16 book[1];
};

typedef struct gitem_data_struct gitem_data_struct, *Pgitem_data_struct;

struct gitem_data_struct {
    struct Gitemheader * item_header;
    string * item_file_name;
    u32 no_model;
    struct weapon_stats * item_weapon_stats;
    short upper_watch_text;
    short lower_watch_text;
    float watch_pos_x;
    float watch_pos_y;
    float watch_pos_z;
    float x_rotation;
    float y_rotation;
    short weapon_of_choice_text;
    short watch_equipment_text;
    float equip_watch_x;
    float equip_watch_y;
    float equip_watch_z;
};

typedef struct save_data save_data, *Psave_data;

struct save_data {
    int chksum1;
    int chksum2;
    char completion_bitflags;
    char flag_007;
    char music_vol;
    char sfx_vol;
    char controller_config;
    char options;
    char unlocked_cheats_1;
    char unlocked_cheats_2;
    char unlocked_cheats_3;
    char field_11;
    char agent_dam_time;
    char field_13;
    char field_14;
    char field_15;
    char field_16;
    char agent_bunker1_time;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    char agent_bunker2_time;
    char field_1D;
    char field_1E;
    char field_1F;
    char field_20;
    char agent_depot_time;
    char field_22;
    char field_23;
    char field_24;
    char field_25;
    char agent_caverns_time;
    char field_27;
    char field_28;
    char field_29;
    char field_2A;
    char secretagent_dam_time;
    char field_2C;
    char field_2D;
    char field_2E;
    char field_2F;
    char secretagent_bunker1_time;
    char field_31;
    char field_32;
    char field_33;
    char field_34;
    char secretagent_bunker2_time;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char secretagent_depot_time;
    char field_3B;
    char field_3C;
    char field_3D;
    char field_3E;
    char secretagent_caverns_time;
    char field_40;
    char field_41;
    char field_42;
    char field_43;
    char agent00_dam_time;
    char field_45;
    char field_46;
    char field_47;
    char field_48;
    char agent00_bunker1_time;
    char field_4A;
    char field_4B;
    char field_4C;
    char field_4D;
    char agent00_bunker2_time;
    char field_4F;
    char field_50;
    char field_51;
    char field_52;
    char agent00_depot_time;
    char field_54;
    char field_55;
    char field_56;
    char field_57;
    char agent00_caverns_time;
    char field_59;
    char field_5A;
    char field_5B;
    char field_5C;
    char unused1;
    char unused2;
    char unused3;
};


// WARNING! conflicting data type names: /GE Current Master.h/guDLPrintCB - /gu.h/guDLPrintCB

typedef struct point_table point_table, *Ppoint_table;

struct point_table {
    short x;
    short y;
    short z;
    short reserved;
    short s_val;
    short t_val;
    char red;
    char green;
    char blue;
    char alpha;
};


// WARNING! conflicting data type names: /sched.h/OSSched - /GE Current Master.h/OSSched

typedef enum enum {
    PRE_NMI_MSG=669,
    RDP_DONE_MSG=668,
    RSP_DONE_MSG=667,
    VIDEO_MSG=666
} enum;

#define OS_SC_RETRACE_MSG 1

#define OS_SC_LAST_TASK 32

#define OS_SC_RDP_DONE_MSG 3

#define OS_SC_RCP_MASK 3

#define OS_SC_PRE_NMI_MSG 4

#define OS_SC_DONE_MSG 2

#define OS_SC_LAST_MSG 4

#define OS_SC_TYPE_MASK 7

#define OS_SC_SWAPBUFFER 64

#define OS_SC_MAX_MESGS 8

#define OS_SC_NEEDS_RSP 2

#define OS_SC_STACKSIZE 8192

#define OS_SC_PARALLEL_TASK 16

#define OS_SC_DRAM_DLIST 4

#define OS_SC_NEEDS_RDP 1


// WARNING! conflicting data type names: /memp.h/s_mempBANK - /s_mempBANK

typedef struct s_mempMEMSTARTS s_mempMEMSTARTS, *Ps_mempMEMSTARTS;

struct s_mempMEMSTARTS {
    s32 bank1start;
    s32 bank2start;
    s32 bank3start;
    s32 bank4start;
    s32 bank5start;
    s32 bank6start;
    s32 bank7start;
};


// WARNING! conflicting data type names: /memp.h/s_mempMVALS - /s_mempMVALS


// WARNING! conflicting data type names: /ultralog.h/OSLog - /GE Current Master.h/OSLog


// WARNING! conflicting data type names: /ultralog.h/OSLogItem - /GE Current Master.h/OSLogItem


// WARNING! conflicting data type names: /ultralog.h/OSLogFileHdr - /GE Current Master.h/OSLogFileHdr

#define OS_LOG_MAGIC 544434803

#define OS_LOG_MAX_ARGS 16

#define OS_LOG_VERSION 1

typedef u32 OSYieldResult;

#define M_TASK_FLAG0 1

#define SPSTATUS_SIGNAL7_SET 16384

#define M_TASK_FLAG1 2

#define SPSTATUS_SIGNAL3_SET 1024

#define OS_YIELD_DATA_SIZE 2304

#define M_HVQTASK 6

#define SPSTATUS_SET_SSTEP 64

#define SPSTATUS_SIGNAL5_SET 4096

#define SPSTATUS_IO_FULL 16

#define SPSTATUS_SIGNAL1_SET 256

#define SPSTATUS_SET_INTR 16

#define OS_TASK_YIELDED 1

#define OS_TASK_DP_WAIT 2

#define SPSTATUS_SINGLE_STEP 32

#define SPSTATUS_SET_HALT 2

#define SPSTATUS_DMA_FULL 8

#define SPSTATUS_CLEAR_BROKE 4

#define SPSTATUS_SIGNAL6_SET 8192

#define SPSTATUS_INTERRUPT_ON_BREAK 64

#define SPSTATUS_CLEAR_INTR 8

#define SPSTATUS_DMA_BUSY 4

#define SPSTATUS_CLEAR_SSTEP 32

#define SPSTATUS_SIGNAL4_SET 2048

#define SPSTATUS_CLEAR_INTR_ON_BREAK 128

#define M_HVQMTASK 7

#define OS_TASK_USR3 128

#define OS_TASK_USR2 64

#define OS_TASK_USR1 32

#define SPSTATUS_BROKE 2

#define SPSTATUS_CLEAR_HALT 1

#define SPSTATUS_SIGNAL0_SET 128

#define SPSTATUS_SET_SIGNAL6 8388608

#define SPSTATUS_SET_SIGNAL5 1048576

#define OS_YIELD_AUDIO_SIZE 1024

#define SPSTATUS_SET_SIGNAL7 33554432

#define SPSTATUS_SET_SIGNAL2 16384

#define SPSTATUS_SET_SIGNAL1 4096

#define SPSTATUS_SET_SIGNAL4 262144

#define SPSTATUS_SET_SIGNAL3 65536

#define SPSTATUS_HALT 1

#define SPSTATUS_SIGNAL2_SET 512

#define SPSTATUS_CLEAR_SIGNAL2 8192

#define SPSTATUS_CLEAR_SIGNAL3 32768

#define SPSTATUS_CLEAR_SIGNAL4 131072

#define SPSTATUS_CLEAR_SIGNAL5 524288

#define SPSTATUS_CLEAR_SIGNAL0 512

#define SPSTATUS_CLEAR_SIGNAL1 2048

#define SPSTATUS_SET_SIGNAL0 1024

#define SPSTATUS_CLEAR_SIGNAL6 2097152

#define SPSTATUS_CLEAR_SIGNAL7 16777216

#define SPSTATUS_SET_INTR_ON_BREAK 256

#define OS_TASK_USR0 16

typedef struct lldiv_t lldiv_t, *Plldiv_t;

struct lldiv_t {
    longlong quot;
    longlong rem;
};

typedef struct ldiv_t ldiv_t, *Pldiv_t;

struct ldiv_t {
    long quot;
    long rem;
};

typedef struct OSEepromUnknownStruct0 OSEepromUnknownStruct0, *POSEepromUnknownStruct0;

struct OSEepromUnknownStruct0 {
    u16 unk00;
    u16 unk01;
};

typedef struct amConfig amConfig, *PamConfig;

struct amConfig {
    u32 outputRate;
    u32 framesPerField;
    u32 maxACMDSize;
};

#define DMA_BUFFER_LENGTH 2048

#define MAX_SEQ_LENGTH 20000

#define NUM_DMA_BUFFERS 24

#define MAX_UPDATES 32

#define EXTRA_SAMPLES 80

#define QUIT_MSG 10

#define AUDIO_STACKSIZE 8192

#define MAX_EVENTS 32

#define AUDIO_HEAP_SIZE 300000

#define NUM_DMA_MESSAGES 32

#define NUM_OUTPUT_BUFFERS 3

#define FRAME_LAG 1

#define OUTPUT_RATE 44100

#define NUM_ACMD_LISTS 2

#define MAX_RSP_CMDS 4096

#define MAX_MESGS 8

#define MAX_VOICES 22

#define UP_CELLNL 32

#define UP_MAXCELLS 50

#define UP_MAXPVERTS 16

#define UP_OBNL 32

typedef struct AMDMAState AMDMAState, *PAMDMAState;

typedef struct AMDMABuffer AMDMABuffer, *PAMDMABuffer;

struct AMDMABuffer {
    ALLink node;
    u32 startAddr;
    u32 lastFrame;
    char * ptr;
};

struct AMDMAState {
    u8 initialized;
    struct AMDMABuffer * firstUsed;
    struct AMDMABuffer * firstFree;
};

typedef struct AudioInfo_s AudioInfo_s, *PAudioInfo_s;

typedef struct AudioInfo_s AudioInfo;

typedef union AudioMsg AudioMsg, *PAudioMsg;

typedef struct _struct_197 _struct_197, *P_struct_197;

typedef struct _struct_198 _struct_198, *P_struct_198;

struct _struct_198 {
    short type;
    struct AudioInfo_s * info;
};

struct _struct_197 {
    short type;
};

union AudioMsg {
    struct _struct_197 gen;
    struct _struct_198 done;
    struct OSScMsg app;
};

struct AudioInfo_s {
    short * data;
    short frameSamples;
    OSScTask task;
    union AudioMsg msg;
};

typedef struct AMAudioMgr AMAudioMgr, *PAMAudioMgr;


// WARNING! conflicting data type names: /libaudio.h/ALGlobals - /GE Current Master.h/ALGlobals

struct AMAudioMgr {
    union Acmd * ACMDList[2];
    AudioInfo * audioInfo[3];
    OSThread thread;
    OSMesgQueue audioFrameMsgQ;
    OSMesg audioFrameMsgBuf[8];
    OSMesgQueue audioReplyMsgQ;
    OSMesg audioReplyMsgBuf[8];
    struct ALGlobals g;
};

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct evp_pkey_ctx_st {
};


// WARNING! conflicting data type names: /vi.h/OSViFieldRegs - /os.h/OSViFieldRegs


// WARNING! conflicting data type names: /vi.h/OSViCommonRegs - /os.h/OSViCommonRegs

typedef struct OSViContext OSViContext, *POSViContext;


// WARNING! conflicting data type names: /vi.h/OSViMode - /os.h/OSViMode

struct OSViContext {
    u16 unk00;
    u16 retraceCount;
    void * buffer;
    struct OSViMode * unk08;
    u32 features;
    OSMesgQueue * mq;
    OSMesg * msg;
    u32 unk18;
    u32 unk1c;
    u32 unk20;
    f32 unk24;
    u16 unk28;
    u32 unk2c;
};

#define OS_VI_PAL_HPF2 27

#define OS_VI_MPAL_HPN1 36

#define OS_VI_PAL_HPF1 23

#define OS_VI_MPAL_HPN2 40

#define OS_VI_UNK100 256

#define OS_VI_NTSC_LAN1 2

#define OS_VI_NTSC_LAN2 6

#define OS_VI_FPAL_LAN2 48

#define OS_VI_FPAL_LAN1 44

#define OS_VI_PAL_HPN2 26

#define OS_VI_PAL_HPN1 22

#define OS_VI_MPAL_HPF1 37

#define OS_VI_MPAL_HPF2 41

#define OS_VI_NTSC_LAF1 3

#define OS_VI_NTSC_LAF2 7

#define OS_VI_GAMMA_DITHER 4

#define OS_VI_FPAL_LAF2 49

#define OS_VI_NTSC_HPF2 13

#define OS_VI_FPAL_LAF1 45

#define OS_VI_DIVOT 16

#define OS_VI_NTSC_HPF1 9

#define OS_VI_NTSC_HPN2 12

#define OS_VI_NTSC_HPN1 8

#define OS_VI_GAMMA 8

#define OS_VI_GAMMA_ON 1

#define OS_VI_UNK200 512

#define OS_VI_FPAL_HPN2 54

#define OS_VI_FPAL_HPN1 50

#define OS_VI_FPAL_HPF2 55

#define OS_VI_FPAL_HPF1 51

#define OS_VI_PAL_LAF1 17

#define OS_VI_MPAL_LAN1 30

#define OS_VI_MPAL_LAN2 34

#define OS_VI_PAL_LAF2 21

#define OS_VI_GAMMA_DITHER_ON 4

#define OS_VI_PAL_LAN1 16

#define OS_VI_MPAL_LAF1 31

#define OS_VI_PAL_LAN2 20

#define OS_VI_MPAL_LAF2 35

#define OS_VI_MPAL_LPN1 28

#define OS_VI_PAL_LPF2 19

#define OS_VI_PAL_LPF1 15

#define OS_VI_MPAL_LPN2 32

#define OS_VI_MPAL_LPF1 29

#define OS_VI_PAL_LPN2 18

#define OS_VI_PAL_LPN1 14

#define OS_VI_DITHER_FILTER_OFF 128

#define OS_VI_MPAL_LPF2 33

#define OS_VI_FPAL_HAN1 52

#define OS_VI_DIVOT_OFF 32

#define OS_VI_FPAL_HAF1 53

#define OS_VI_GAMMA_DITHER_OFF 8

#define OS_VI_GAMMA_OFF 2

#define OS_VI_MPAL_HAF1 39

#define OS_VI_DITHER_FILTER 65536

#define OS_VI_DIVOT_ON 16

#define OS_VI_NTSC_LPN1 0

#define OS_VI_NTSC_LPN2 4

#define OS_VI_FPAL_LPN2 46

#define OS_VI_FPAL_LPN1 42

#define OS_VI_NTSC_LPF1 1

#define OS_VI_NTSC_LPF2 5

#define OS_VI_NTSC_HAF1 11

#define OS_VI_FPAL_LPF2 47

#define OS_VI_FPAL_LPF1 43

#define OS_VI_NTSC_HAN1 10

#define OS_VI_DITHER_FILTER_ON 64

#define OS_VI_PAL_HAF1 25

#define OS_VI_MPAL_HAN1 38

#define OS_VI_PAL_HAN1 24

#define TV_TYPE_PAL 0

#define RESET_TYPE_BOOT_DISK 2

#define TV_TYPE_MPAL 2

#define RESET_TYPE_COLD_RESET 0

#define TV_TYPE_NTSC 1

#define RESET_TYPE_NMI 1

#define LOG_SCHEDULE_GFX_TASK 101

#define LOG_RDP_DONE 102

#define INIT_PRIORITY 10

#define STACKSIZEBYTES 8192

#define UTIL_PRIORITY 1

#define LOG_RETRACE 103

#define DMA_QUEUE_SIZE 200

#define NUM_FIELDS 1

#define STATIC_SEGMENT 1

#define GAME_PRIORITY 10

#define AUDIO_PRIORITY 12

#define SIMPLE_CONTROLLER_MSG 5

#define LOG_INTR 104

#define DYNAMIC_SEGMENT 2

#define SCHEDULER_PRIORITY 13


// WARNING! conflicting data type names: /ultratypes.h/vs64 - /types.h/vs64


// WARNING! conflicting data type names: /ultratypes.h/vu16 - /types.h/vu16


// WARNING! conflicting data type names: /ultratypes.h/vs8 - /types.h/vs8


// WARNING! conflicting data type names: /ultratypes.h/vu8 - /types.h/vu8


// WARNING! conflicting data type names: /ultratypes.h/vu32 - /types.h/vu32


// WARNING! conflicting data type names: /ultratypes.h/vu64 - /types.h/vu64


// WARNING! conflicting data type names: /ultratypes.h/vs16 - /types.h/vs16


// WARNING! conflicting data type names: /ultratypes.h/vs32 - /types.h/vs32


// WARNING! conflicting data type names: /mema.h/s_mem_alloc_table - /s_mem_alloc_table


// WARNING! conflicting data type names: /mema.h/s_mem_alloc_entry - /s_mem_alloc_entry

#define R_JPAD 256

#define A_BUTTON 32768

#define L_CBUTTONS 2

#define U_JPAD 2048

#define Z_TRIG 8192

#define D_CBUTTONS 4

#define B_BUTTON 16384

#define D_JPAD 1024

#define START_BUTTON 4096

#define R_CBUTTONS 1

#define U_CBUTTONS 8

#define DUMMY_1 128

#define DUMMY_2 64

#define R_TRIG 16

#define L_TRIG 32

#define L_JPAD 512

typedef struct Apan Apan, *PApan;

typedef union anon__struct_84_bitfield_1 anon__struct_84_bitfield_1, *Panon__struct_84_bitfield_1;

union anon__struct_84_bitfield_1 {
    uint cmd:8; // : bits 0-7
    uint flags:8; // : bits 8-15
    uint dmem2:16; // : bits 16-31
};

struct Apan {
    union anon__struct_84_bitfield_1 field_0x0;
    uint addr;
};

#define A_MAIN 0

#define A_CONTINUE 0

#define ADPCMFSIZE 16

#define A_SETBUFF 8

#define A_LOOP 2

#define A_MIXER 12

#define A_SAVEBUFF 6

#define A_POLEF 14

#define A_INIT 1

#define ACMD_SIZE 32

#define A_LEFT 2

#define A_SPNOOP 0

#define A_LOADBUFF 4

#define A_DMEMMOVE 10

#define ADPCMVSIZE 8

#define A_AUX 8

#define A_RIGHT 0

#define A_CLEARBUFF 2

#define A_NOAUX 0

#define A_SEGMENT 7

#define A_OUT 2

#define A_LOADADPCM 11

#define A_VOL 4

#define A_MIX 16

#define UNITY_PITCH 32768

#define A_RATE 0

#define A_INTERLEAVE 13

#define A_SETLOOP 15

#define A_SETVOL 9

#define A_ENVMIXER 3

#define A_ADPCM 1

#define A_RESAMPLE 5

typedef struct Dynamic Dynamic, *PDynamic;

struct Dynamic {
    union Mtx projection;
    union Mtx viewing;
    union Mtx bg_model;
    union Mtx logo_scale;
    union Mtx logo_rotate;
    union Mtx logo_trans;
    union Gfx glist[512];
};

typedef union GFXMsg GFXMsg, *PGFXMsg;

typedef struct _struct_193 _struct_193, *P_struct_193;

typedef struct _struct_194 _struct_194, *P_struct_194;

struct _struct_193 {
    short type;
};

struct _struct_194 {
    short type;
};

union GFXMsg {
    struct _struct_193 gen;
    struct _struct_194 done;
    struct OSScMsg app;
};

typedef struct GFXInfo GFXInfo, *PGFXInfo;

struct GFXInfo {
    OSScTask task;
    struct Dynamic dp;
    union GFXMsg msg;
    u16 * cfb;
};

#define SCREEN_WD 320

#define SCREEN_HT 240

#define GFX_DL_BUF_SIZE 6000

typedef struct OSProf OSProf, *POSProf;

struct OSProf {
    u16 * histo_base;
    u32 histo_size;
    u32 * text_start;
    u32 * text_end;
};


// WARNING! conflicting data type names: /os.h/OSThread_s - /thread.h/OSThread_s

typedef struct OSPfsState OSPfsState, *POSPfsState;

struct OSPfsState {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    char ext_name[4];
    char game_name[16];
};

typedef u32 OSHWIntr;

typedef struct OSContPad OSContPad, *POSContPad;

struct OSContPad {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 errno;
};


// WARNING! conflicting data type names: /os.h/__OSBlockInfo - /pi.h/__OSBlockInfo

typedef struct OSContRamIo OSContRamIo, *POSContRamIo;

struct OSContRamIo {
    void * address;
    u8 databuffer[32];
    u8 addressCrc;
    u8 dataCrc;
    u8 errno;
};

typedef struct OSDevMgr OSDevMgr, *POSDevMgr;


// WARNING! conflicting data type names: /os.h/OSPiHandle - /pi.h/OSPiHandle

struct OSDevMgr {
    s32 active;
    OSThread * thread;
    OSMesgQueue * cmdQueue;
    OSMesgQueue * evtQueue;
    OSMesgQueue * acsQueue;
    s32 (* dma)(s32, u32, void *, u32);
    s32 (* edma)(OSPiHandle *, s32, u32, void *, u32);
};

typedef struct OSPfs OSPfs, *POSPfs;

struct OSPfs {
    int status;
    OSMesgQueue * queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

typedef struct OSTimer_s OSTimer_s, *POSTimer_s;

typedef u64 OSTime;

struct OSTimer_s {
    struct OSTimer_s * next;
    struct OSTimer_s * prev;
    OSTime interval;
    OSTime value;
    OSMesgQueue * mq;
    OSMesg msg;
};


// WARNING! conflicting data type names: /os.h/OSId - /thread.h/OSId


// WARNING! conflicting data type names: /os.h/OSIoMesgHdr - /pi.h/OSIoMesgHdr

typedef struct OSContStatus OSContStatus, *POSContStatus;

struct OSContStatus {
    u16 type;
    u8 status;
    u8 errno;
};

typedef enum enumOSEvent {
    OS_EVENT_AI=6,
    OS_EVENT_CART=2,
    OS_EVENT_COUNTER=3,
    OS_EVENT_CPU_BREAK=10,
    OS_EVENT_DP=9,
    OS_EVENT_FAULT=12,
    OS_EVENT_PI=8,
    OS_EVENT_PRENMI=14,
    OS_EVENT_RDB_READ_OK=15,
    OS_EVENT_SI=5,
    OS_EVENT_SP=4,
    OS_EVENT_SP_BREAK=11,
    OS_EVENT_SW1=0,
    OS_EVENT_SW2=1,
    OS_EVENT_THREADSTATUS=13,
    OS_EVENT_VI=7
} enumOSEvent;


// WARNING! conflicting data type names: /os.h/OSIoMesg - /pi.h/OSIoMesg


// WARNING! conflicting data type names: /os.h/__OSThreadContext - /thread.h/__OSThreadContext


// WARNING! conflicting data type names: /os.h/OSPiHandle_s - /pi.h/OSPiHandle_s


// WARNING! conflicting data type names: /os.h/OSTimer - /time.h/OSTimer

typedef struct _struct_2 _struct_2, *P_struct_2;

struct _struct_2 {
    f32 f_odd;
    f32 f_even;
};


// WARNING! conflicting data type names: /os.h/OSEvent - /message.h/OSEvent


// WARNING! conflicting data type names: /os.h/__OSTranxInfo - /pi.h/__OSTranxInfo


// WARNING! conflicting data type names: /os.h/OSPiInfo - /pi.h/OSPiInfo


// WARNING! conflicting data type names: /os.h/__OSfp - /thread.h/__OSfp

typedef u32 OSPageMask;


// WARNING! conflicting data type names: /os.h/OSIntMask - /interrupt.h/OSIntMask

#define OS_MESG_TYPE_BASE 10

#define OS_FLAG_FAULT 2

#define OS_MESG_TYPE_LOOPBACK 10

#define CONT_RELATIVE 2

#define OS_EVENT_RDB_DATA_DONE 17

#define CONT_START 4096

#define CONT_EEPROM 32768

#define LEO_BLOCK_MODE 1

#define OS_VI_BIT_32PIXEL 128

#define PFS_ERR_ID_FATAL 10

#define OS_IM_PI 1049601

#define PFS_ERR_INVALID 5

#define OS_SIM_STACKSIZE 4096

#define OS_MESG_TYPE_DMAWRITE 12

#define OS_VI_BIT_NONINTERLACE 1

#define BLOCKSIZE 32

#define EEPROM_MAXBLOCKS 64

#define MAXCONTROLLERS 4

#define OS_VI_BIT_16PIXEL 64

#define OS_PM_1M 2088960

#define OS_IM_SP 66561

#define BOOT_ADDRESS_COSIM 2147491840

#define CONT_OVERRUN_ERROR 4

#define OS_IM_ALL 4194049

#define PFS_ERR_EXIST 9

#define OS_IM_CPU 65281

#define OS_APP_NMI_BUFSIZE 64

#define OS_MESG_TYPE_EDMAWRITE 16

#define PFS_ERR_BAD_DATA 6

#define BOOT_ADDRESS_INDY 2282749952

#define OS_TV_PAL 0

#define PFS_ERR_NOPACK 1

#define OS_PM_16M 33546240

#define PFS_INITIALIZED 1

#define OS_PM_16K 24576

#define OS_NUM_EVENTS.conflict 15

#define OS_IM_SI 132097

#define OS_MESG_TYPE_COUNTER 14

#define PFS_WRITE 1

#define OS_PM_256K 516096

#define LEO_SECTOR_MODE 3

#define OS_VI_BIT_LORES 256

#define CONT_DOWN 1024

#define OS_IM_VI 525313

#define PFS_MAX_BANKS 62

#define CONT_UP 2048

#define OS_IM_RDBREAD 17409

#define CONT_ABSOLUTE 1

#define OS_VIM_STACKSIZE 4096

#define OS_IM_SW2 1537

#define OS_IM_SW1 1281

#define PFS_ERR_NEW_PACK 2

#define OS_MESG_TYPE_VRETRACE 13

#define OS_IM_PRENMI 5121

#define PFS_FILE_NAME_LEN 16

#define PFS_DIR_FULL 8

#define OS_OTHERS 2

#define OS_EVENT_RDB_LOG_DONE 16

#define PFS_ERR_INCONSISTENT 3

#define PROF_MIN_INTERVAL 50

#define PFS_FILE_EXT_LEN 4

#define CONT_CARD_ON 1

#define OS_VI_BIT_ANTIALIAS 16

#define PFS_READ 0

#define PFS_DATA_FULL 7

#define EEPROM_BLOCK_SIZE 8

#define OS_EVENT_RDB_ACK_PROF 22

#define CONT_NO_RESPONSE_ERROR 8

#define CONT_ADDR_CRC_ER 4

#define OS_VI_BIT_PAL 2048

#define CONT_E 8

#define CONT_F 1

#define CONT_G 8192

#define CONT_A 32768

#define OS_TV_NTSC 1

#define CONT_B 16384

#define CONT_C 2

#define CONT_RIGHT 256

#define CONT_D 4

#define OS_VI_BIT_NORMALINTERLACE 4

#define OS_EVENT_RDB_REQ_RAMROM 18

#define CONT_L 32

#define CONT_R 16

#define OS_EVENT_RDB_READ_DONE 15

#define OS_FLAG_CPU_BREAK 1

#define OS_PM_4M 8380416

#define OS_PM_64K 122880

#define OS_PM_4K 0

#define OS_VI_BIT_HIRES 512

#define OS_EVENT_RDB_FLUSH_PROF 21

#define PFS_ONE_PAGE 8

#define CONT_LEFT 512

#define LEO_TRACK_MODE 2

#define RCP_IMASKSHIFT 16

#define OS_MESG_TYPE_EDMAREAD 15

#define OS_VI_BIT_DEFLICKINTERLACE 8

#define PFS_ERR_CONTRFAIL 4

#define OS_IM_DP 2098177

#define BOOT_ADDRESS_ULTRA 2147484672

#define CONT_CARD_PULL 2

#define CONT_EEPROM_BUSY 128

#define OS_VI_BIT_INTERLACE 2

#define OS_NUM_EVENTS 23

#define OS_IM_CART 3073

#define OS_MIN_STACKSIZE 72

#define OS_IM_AI 263169

#define OS_VI_BIT_NTSC 1024

#define OS_MESG_TYPE_DMAREAD 11

#define OS_IM_NONE 1

#define OS_EVENT_RDB_DBG_DONE 20

#define OS_EVENT_RDB_FREE_RAMROM 19

#define OS_VI_BIT_POINTSAMPLE 32

#define RCP_IMASK 4128768

#define PFS_CORRUPTED 2

#define PFS_CREATE 2

#define BOOT_ADDRESS_EMU 536936448

#define OS_PIM_STACKSIZE 4096

#define CONT_JOYPORT 4

#define PFS_ERR_DEVICE 11

#define OS_IM_COUNTER 33793

#define OS_TV_MPAL 2

#define OS_IM_RDBWRITE 9217

#define SP_CLR_YIELDED 2048

#define VI_TIMING_REG 71303188

#define GIO_GIO_INTR_REG 402653184

#define VI_H_SYNC_REG 71303196

#define RDRAM_ACTIVE_MODE 1

#define DPS_TBIST_CHECK 1

#define PI_DOM_PWD_OFS 4

#define DPC_STATUS_FLUSH 4

#define PI_SET_RESET 1

#define VI_CTRL_GAMMA_DITHER_ON 4

#define RDRAM_0_END 2097151

#define AI_PAL_MIN_FREQ 3050

#define PI_STATUS_ERROR 4

#define SP_SET_YIELD 1024

#define SP_CLR_BROKE 4

#define RDRAM_END 4194303

#define DPS_TBIST_DONE 4

#define VI_V_SYNC_REG 71303192

#define PI_CART_ADDR_REG 73400324

#define RDRAM_DEVICE_MANUF_REG 66060324

#define CHNL_ERR_NORESP 128

#define SP_IMEM_START 67112960

#define MI_INTR_MASK_CLR_DP 1024

#define VI_H_SYNC_LEAP_REG 71303200

#define SP_STATUS_IO_FULL 16

#define SP_IBIST_REG 67633156

#define SP_CLR_TASKDONE 8192

#define DPC_PIPEBUSY_REG 68157464

#define MI_SET_EBUS 1024

#define DEVICE_TYPE_BULK 1

#define MI_INTR_MASK_SP 1

#define MI_BASE_REG 70254592

#define RDRAM_0_BASE_ADDRESS 0

#define MI_INTR_PI 16

#define SP_DMEM_START 67108864

#define SP_STATUS_HALT 1

#define MI_CLR_DP_INTR 2048

#define RDRAM_0_CONFIG 0

#define RDRAM_MIN_INTERVAL_REG 66060316

#define MI_INTR_MASK_SI 2

#define AI_MIN_BIT_RATE 2

#define DPC_CLOCK_REG 68157456

#define PIF_ROM_START 532676608

#define RI_REFRESH_REG 74448912

#define VI_CTRL_TYPE_16 2

#define AI_MPAL_MAX_FREQ 368000

#define MI_INTR_MASK_SET_PI 512

#define SP_SET_TASKDONE 16384

#define DPC_CURRENT_REG 68157448

#define VI_CONTROL_REG 71303168

#define MI_CLR_RDRAM 4096

#define SI_DRAM_ADDR_REG 75497472

#define AI_NTSC_MIN_FREQ 3000

#define SI_BASE_REG 75497472

#define DPC_CLR_TMEM_CTR 64

#define PI_BSD_DOM1_LAT_REG 73400340

#define SP_MEM_ADDR_REG 67371008

#define MI_CLR_INIT 128

#define DPC_CLR_XBUS_DMEM_DMA 1

#define MI_INTR_MASK_PI 16

#define VI_CTRL_TYPE_32 3

#define DPC_END_REG 68157444

#define MI_INTR_SP 1

#define SP_CLR_SSTEP 32

#define MI_INTR_SI 2

#define VI_V_INTR_REG 71303180

#define PI_STATUS_REG 73400336

#define DPS_TBIST_CLEAR 4

#define SP_IBIST_GO 2

#define VI_V_BURST_REG 71303212

#define PI_DOM_PGS_OFS 8

#define SP_STATUS_DMA_FULL 8

#define MI_SET_INIT 256

#define PI_DMA_BUFFER_SIZE 128

#define MI_INTR_VI 8

#define PI_DOM2_ADDR1 83886080

#define MI_INTR_MASK_DP 32

#define PI_DOM2_ADDR2 134217728

#define MI_INTR_MASK_SET_DP 2048

#define SP_SET_YIELDED 4096

#define VI_ORIGIN_REG 71303172

#define MI_MODE_RDRAM 512

#define RDRAM_DELAY_REG 66060296

#define AI_CONTROL_DMA_ON 1

#define DPC_CLR_FLUSH 16

#define SP_SET_HALT 2

#define RDRAM_0_DEVICE_ID 0

#define PI_STATUS_CLR_INTR 2

#define AI_STATUS_FIFO_FULL 2147483648

#define SI_STATUS_DMA_BUSY 1

#define VI_V_CURRENT_LINE_REG 71303184

#define MI_CLR_EBUS 512

#define PI_DOM_RLS_OFS 12

#define PI_RD_LEN_REG 73400328

#define SP_DRAM_ADDR_REG 67371012

#define MI_INTR_MASK_CLR_SP 1

#define RDRAM_1_DEVICE_ID 1

#define RI_CURRENT_LOAD_REG 74448904

#define PI_STATUS_DMA_BUSY 1

#define PI_STATUS_IO_BUSY 2

#define VI_V_VIDEO_REG 71303208

#define CHNL_ERR_FRAME 128

#define SP_SEMAPHORE_REG 67371036

#define MI_INTR_MASK_CLR_SI 4

#define AI_MAX_DAC_RATE 16384

#define SP_SET_SSTEP 64

#define SI_STATUS_RD_BUSY 2

#define GIO_GIO_SYNC_REG 402654208

#define SP_CLR_INTR_BREAK 128

#define RI_SELECT_REG 74448908

#define DPC_SET_FLUSH 32

#define RDRAM_START 0

#define VI_INTR_REG 71303180

#define RDRAM_ADDR_SELECT_REG 66060320

#define SP_STATUS_INTR_BREAK 64

#define AI_STATUS_REG 72351756

#define SP_IBIST_CHECK 1

#define SP_DMA_DMEM 0

#define SP_CLR_HALT 1

#define DPC_CLR_CMD_CTR 256

#define AI_PAL_MAX_FREQ 376000

#define AI_CONTROL_REG 72351752

#define RDRAM_RESET_MODE 0

#define DPC_STATUS_PIPE_BUSY 32

#define SP_STATUS_YIELD 128

#define VI_BASE_REG 71303168

#define DPS_BUFTEST_ADDR_REG 69206024

#define RDRAM_STANDBY_MODE 2

#define MI_NOOP_REG 70254596

#define AI_STATUS_DMA_BUSY 1073741824

#define SP_STATUS_SIG0 128

#define SP_STATUS_SIG1 256

#define SP_STATUS_SIG6 8192

#define GIO_BASE_REG 402653184

#define SP_STATUS_SIG7 16384

#define SP_STATUS_SIG4 2048

#define DPC_STATUS_REG 68157452

#define SP_STATUS_SIG5 4096

#define SI_STATUS_DMA_ERROR 8

#define SP_STATUS_SIG2 512

#define SP_STATUS_SIG3 1024

#define PIF_ROM_END 532678591

#define MI_INTR_MASK_CLR_PI 256

#define DPS_BASE_REG 69206016

#define DPC_STATUS_DMA_BUSY 256

#define PI_WR_LEN_REG 73400332

#define SP_PC_REG 67633152

#define GIO_CART_INTR_REG 402655232

#define DPC_STATUS_CBUF_READY 128

#define DPC_STATUS_TMEM_BUSY 16

#define PI_BSD_DOM2_PGS_REG 73400364

#define DPC_CLR_FREEZE 4

#define AI_MAX_BIT_RATE 16

#define DPC_BUFBUSY_REG 68157460

#define SP_DMA_IMEM 4096

#define AI_BASE_REG 72351744

#define RI_MODE_REG 74448896

#define RI_BASE_REG 74448896

#define VI_LEAP_REG 71303200

#define PI_DOM_LAT_OFS 0

#define VI_MPAL_CLOCK 48628316

#define MI_INTR_MASK_CLR_VI 64

#define DEVICE_TYPE_CART 0

#define CHNL_ERR_COLLISION 64

#define DPC_STATUS_XBUS_DMEM_DMA 1

#define RDRAM_DEVICE_TYPE_REG 66060288

#define MI_SET_RDRAM 8192

#define DPC_SET_FREEZE 8

#define PIF_RAM_END 532678655

#define MI_MODE_EBUS 256

#define DPC_STATUS_CMD_BUSY 64

#define AI_MIN_DAC_RATE 132

#define DPC_CLR_PIPE_CTR 128

#define AI_DACRATE_REG 72351760

#define SP_BASE_REG 67371008

#define SP_DMA_FULL_REG 67371028

#define PI_DOM1_ADDR3 533725184

#define RDRAM_GLOBAL_CONFIG 524288

#define PI_DOM1_ADDR2 268435456

#define MI_VERSION_REG 70254596

#define PI_DOM1_ADDR1 100663296

#define AI_MPAL_MIN_FREQ 3000

#define AI_NTSC_MAX_FREQ 368000

#define VI_H_VIDEO_REG 71303204

#define RDRAM_1_CONFIG 1024

#define VI_WIDTH_REG 71303176

#define SP_STATUS_DMA_BUSY 4

#define VI_CTRL_DIVOT_ON 16

#define VI_CTRL_DITHER_FILTER_ON 65536

#define RI_WERROR_REG 74448924

#define VI_PAL_CLOCK 49656530

#define PI_BSD_DOM2_RLS_REG 73400368

#define DPS_TBIST_GO 2

#define RI_CONFIG_REG 74448900

#define PI_CLR_INTR 2

#define DPC_TMEM_REG 68157468

#define VI_CTRL_GAMMA_ON 8

#define RDRAM_DEVICE_ID_REG 66060292

#define PI_STATUS_RESET 1

#define SP_IBIST_FAILED 120

#define MI_INTR_MASK_SET_AI 32

#define SP_WR_LEN_REG 67371020

#define SP_DMA_BUSY_REG 67371032

#define AI_LEN_REG 72351748

#define AI_DRAM_ADDR_REG 72351744

#define SI_STATUS_INTERRUPT 4096

#define PI_DRAM_ADDR_REG 73400320

#define MI_INTR_MASK_AI 4

#define SP_STATUS_BROKE 2

#define VI_H_START_REG 71303204

#define SP_SET_SIG5 1048576

#define SP_SET_SIG4 262144

#define SP_SET_SIG3 65536

#define SP_SET_SIG2 16384

#define SP_SET_SIG1 4096

#define SP_SET_SIG0 1024

#define VI_NTSC_CLOCK 48681812

#define DEVICE_TYPE_64DD 2

#define MI_INTR_AI 4

#define MI_INTR_REG 70254600

#define VI_Y_SCALE_REG 71303220

#define RDRAM_CONFIG_REG 66060288

#define RDRAM_REF_ROW_REG 66060308

#define DPC_STATUS_END_VALID 512

#define SP_SET_SIG7 16777216

#define SP_SET_SIG6 4194304

#define DPC_STATUS_START_GCLK 8

#define MI_INTR_MASK_SET_VI 128

#define RI_COUNT_REG 74448912

#define SI_PIF_ADDR_RD64B_REG 75497476

#define MI_INTR_MASK_REG 70254604

#define MI_MODE_INIT 128

#define SP_SET_INTR 16

#define SP_STATUS_TASKDONE 512

#define PI_BSD_DOM2_PWD_REG 73400360

#define DPC_START_REG 68157440

#define VI_X_SCALE_REG 71303216

#define VI_CTRL_SERRATE_ON 64

#define SP_CLR_SIG7 8388608

#define SP_IBIST_DONE 4

#define SP_CLR_SIG5 524288

#define SP_CLR_SIG6 2097152

#define SP_CLR_SIG3 32768

#define SP_CLR_SIG4 131072

#define SP_CLR_SIG1 2048

#define SP_CLR_SIG2 8192

#define SP_CLR_SIG0 512

#define SP_STATUS_REG 67371024

#define CHNL_ERR_OVERRUN 64

#define SP_DMEM_END 67112959

#define MI_INIT_MODE_REG 70254592

#define VI_STATUS_REG 71303168

#define MI_INTR_MASK_VI 8

#define VI_CTRL_ANTIALIAS_MASK 768

#define SI_STATUS_REG 75497496

#define DPC_STATUS_FREEZE 2

#define PI_DOMAIN1_REG 73400340

#define RDRAM_1_BASE_ADDRESS 2097152

#define RI_LATENCY_REG 74448916

#define VI_CURRENT_REG 71303184

#define DPS_BUFTEST_DATA_REG 69206028

#define CHNL_ERR_MASK 192

#define RDRAM_RAS_INTERVAL_REG 66060312

#define VI_H_WIDTH_REG 71303176

#define SP_SET_INTR_BREAK 256

#define DPS_TBIST_FAILED 2040

#define MI_MODE_REG 70254592

#define DPS_TBIST_REG 69206016

#define MI_INTR_MASK_SET_SI 8

#define DPC_CLR_CLOCK_CTR 512

#define RDRAM_MODE_REG 66060300

#define VI_DRAM_ADDR_REG 71303172

#define MI_INTR_MASK_SET_SP 2

#define SP_IBIST_CLEAR 4

#define MI_INTR_DP 32

#define DPC_BASE_REG 68157440

#define RDRAM_REF_INTERVAL_REG 66060304

#define SI_PIF_ADDR_WR64B_REG 75497488

#define RI_RERROR_REG 74448920

#define RDRAM_1_START 2097152

#define RDRAM_LENGTH 2097152

#define SP_CLR_YIELD 512

#define RDRAM_1_END 4194303

#define DPC_SET_XBUS_DMEM_DMA 2

#define VI_V_START_REG 71303208

#define PIF_RAM_START 532678592

#define PI_BSD_DOM2_LAT_REG 73400356

#define RDRAM_0_START 0

#define SP_IMEM_END 67117055

#define SP_RD_LEN_REG 67371016

#define MI_INTR_MASK_CLR_AI 16

#define AI_BITRATE_REG 72351764

#define PI_BSD_DOM1_PWD_REG 73400344

#define PI_DOMAIN2_REG 73400356

#define DPS_TEST_MODE_REG 69206020

#define PI_BSD_DOM1_PGS_REG 73400348

#define SP_STATUS_SSTEP 32

#define PI_BSD_DOM1_RLS_REG 73400352

#define VI_BURST_REG 71303188

#define RDRAM_BASE_REG 66060288

#define SP_CLR_INTR 8

#define DPC_STATUS_START_VALID 1024

#define SP_STATUS_YIELDED 256

#define PI_BASE_REG 73400320

#define AI_CONTROL_DMA_OFF 0

typedef struct _Pft _Pft, *P_Pft;

typedef union _union_225 _union_225, *P_union_225;


// WARNING! conflicting data type names: /XSTDIO.H/size_t - /stddef.h/size_t

typedef double ldouble;

union _union_225 {
    longlong ll;
    ldouble ld;
};

struct _Pft {
    union _union_225 v;
    char * s;
    int n0;
    int nz0;
    int n1;
    int nz1;
    int n2;
    int nz2;
    int prec;
    int width;
    size_t nchar;
    uint flags;
    char qual;
};

#define _WMAX 999

#define _FZE 16

#define _FNO 8

#define _FSP 1

#define _FPL 2

#define _FMI 4


// WARNING! conflicting data type names: /tlb.h/OSPageMask - /os.h/OSPageMask

#define TASKBASELO 4224

#define DRAM_STACK_LO 64512

#define RSP_DMEM_BASE 67108864

#define RSP_IMEM_BASE 67112960

#define TASKBASEHI 1024

#define DRAM_STACK_HI 31

#define rsp_TRIG_BASEHI 4097

#define rsp_TRIG_BASELO 0

#define rsp_TRIG_BASE 268500992

#define _RSP_H_ 1

#define RDP_BUFF_HI 8192

#define RSP_SCRATCH_BASE 536870912

#define DCACHEBASEHI 1024

#define RDP_BUFF_LO 0

#define DCACHEBASELO 0

#define RSPBOOTBASEHI 1024

#define RSPBOOTBASELO 4096

#define rsp_DRAM_STACK_HI 32

#define rsp_DRAM_STACK_LO 0


// WARNING! conflicting data type names: /bondtypes.h/sImageTableEntry - /sImageTableEntry

typedef struct objective_entry objective_entry, *Pobjective_entry;


// WARNING! conflicting data type names: /bondtypes.h/watchMenuObjectiveText - /auto_structs/watchMenuObjectiveText

struct objective_entry {
    u32 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16 text;
    struct watchMenuObjectiveText * nextentry;
};

typedef struct CHRdata CHRdata, *PCHRdata;

struct CHRdata {
    u16 chrnum;
    s8 accuracyrating;
    s8 speedrating;
    u8 firecountleft;
    u8 firecountright;
    s8 headnum;
    s8 actiontype;
    s8 sleep;
    s8 invalidmove;
    s8 numclosearghs;
    s8 numarghs;
    u8 fadealpha;
    s8 arghrating;
    s8 aimendcount;
    s8 bodynum;
    u8 grenadeprob;
    s8 flinchcnt;
    s16 hidden;
    s32 chrflags;
    void * pad;
    void * model;
    void * field_20;
    f32 chrwidth;
    f32 chrheight;
    void * bondpos;
    int field_30;
    short field_34;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int path_target_position;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    char type_of_motion;
    char distance_counter_or_something;
    short distance_to_target;
    int field_5C;
    int target_position;
    int field_64;
    int field_68;
    int field_6C;
    int path_segment_coverage;
    int path_segment_length;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int segment_coverage;
    int segment_length;
    int field_9C;
    int field_A0;
    f32 sumground;
    f32 manground;
    f32 ground;
    f32 fallspeed[3];
    f32 prevpos[3];
    s32 lastwalk60;
    s32 lastmoveok60;
    f32 visionrange;
    s32 lastseetarget60;
    f32 lastvisibletarg[3];
    void * field_E4;
    s32 timeshooter;
    f32 hearingscale;
    s32 lastheartarget60;
    u8 shadecol[4];
    u8 nextcol[4];
    f32 damage;
    f32 maxdamage;
    void * ailist;
    u16 aioffset;
    u16 aireturnlist;
    u8 flags;
    u8 flags2;
    u8 BITFIELD;
    u8 random;
    s32 timer60;
    u16 padpreset1;
    u16 chrpreset1;
    u16 chrseeshot;
    u16 chrseedie;
    f32 field_11C[2];
    f32 field_124[2];
    f32 field_12C[2];
    int field_134;
    int field_138;
    f32 shotbondsum;
    f32 aimuplshoulder;
    f32 aimuprshoulder;
    f32 aimupback;
    f32 aimsideback;
    f32 aimendlshoulder;
    f32 aimendrshoulder;
    f32 aimendback;
    f32 aimendsideback;
    int * handle_positiondata[2];
    int * ptr_SEbuffer1;
    int * ptr_SEbuffer2;
    int * ptr_SEbuffer3;
    int * ptr_SEbuffer4;
    int field_178;
    int field_17C;
    char field_180;
    char field_181;
    char field_182;
    char field_183;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    char field_1AC;
    char field_1AD;
    char field_1AE;
    char field_1AF;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int * handle_positiondata_hat;
};

typedef struct rgba_valf32 rgba_valf32, *Prgba_valf32;

struct rgba_valf32 {
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};


// WARNING! conflicting data type names: /bondtypes.h/sGlobalImageTable - /auto_structs/sGlobalImageTable

#define MIN_PART 3

#define OS_CODE 3

#define RECORD_IO 0

#define MAX_SUFFIX 30

typedef s16 ALSndId;


// WARNING! conflicting data type names: /libaudio.h/ALSeqPlayer - /GE Current Master.h/ALSeqPlayer

typedef struct ALCMidiHdr ALCMidiHdr, *PALCMidiHdr;

struct ALCMidiHdr {
    u32 trackOffset[16];
    u32 division;
};


// WARNING! conflicting data type names: /libaudio.h/ALSeqFile - /GE Current Master.h/ALSeqFile


// WARNING! conflicting data type names: /libaudio.h/ALSndPlayer - /GE Current Master.h/ALSndPlayer

typedef enum AL_MIDIstatus {
    AL_MIDI_ActiveSensing=254,
    AL_MIDI_ChannelMask=15,
    AL_MIDI_ChannelModeSelect=176,
    AL_MIDI_ChannelPressure=208,
    AL_MIDI_ChannelVoice=128,
    AL_MIDI_Continue=251,
    AL_MIDI_ControlChange=176,
    AL_MIDI_EOX=247,
    AL_MIDI_Meta=255,
    AL_MIDI_NoteOff=128,
    AL_MIDI_NoteOn=144,
    AL_MIDI_PitchBendChange=224,
    AL_MIDI_PolyKeyPressure=160,
    AL_MIDI_ProgramChange=192,
    AL_MIDI_SongPositionPointer=242,
    AL_MIDI_SongSelect=243,
    AL_MIDI_Start=250,
    AL_MIDI_StatusMask=240,
    AL_MIDI_Stop=252,
    AL_MIDI_SysEx=240,
    AL_MIDI_SystemCommon=241,
    AL_MIDI_SystemRealTime=248,
    AL_MIDI_SystemReset=255,
    AL_MIDI_TimeCodeQuarterFrame=241,
    AL_MIDI_TimingClock=248,
    AL_MIDI_TuneRequest=246,
    AL_MIDI_Undefined1=244,
    AL_MIDI_Undefined2=245,
    AL_MIDI_Undefined3=249,
    AL_MIDI_Undefined4=253
} AL_MIDIstatus;


// WARNING! conflicting data type names: /libaudio.h/ALSndpConfig - /GE Current Master.h/ALSndpConfig

typedef struct ALCSeq_s ALCSeq_s, *PALCSeq_s;

struct ALCSeq_s {
    struct ALCMidiHdr * base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 * curLoc[16];
    u8 * curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
};

typedef struct ALVoiceConfig_s ALVoiceConfig_s, *PALVoiceConfig_s;

struct ALVoiceConfig_s {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
};

typedef struct ALVoiceConfig_s ALVoiceConfig;

typedef struct ALCSPlayer ALCSPlayer, *PALCSPlayer;

typedef struct ALCSeq_s ALCSeq;

struct ALCSPlayer {
    ALPlayer node;
    struct ALSynth * drvr;
    ALCSeq * target;
    ALMicroTime curTime;
    ALBank * bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    struct ALEvent nextEvent;
    struct ALEventQueue evtq;
    ALMicroTime frameTime;
    struct ALChanState * chanState;
    ALVoiceState * vAllocHead;
    ALVoiceState * vAllocTail;
    ALVoiceState * vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
};

typedef void * ALFxRef;

typedef struct ALBankFile ALBankFile, *PALBankFile;

struct ALBankFile {
    s16 revision;
    s16 bankCount;
    ALBank * bankArray[1];
};

typedef struct ALEventListItem ALEventListItem, *PALEventListItem;

struct ALEventListItem {
    ALLink node;
    ALMicroTime delta;
    struct ALEvent evt;
};

typedef enum ALMsg {
    AL_CSP_LOOPEND=20,
    AL_CSP_LOOPSTART=19,
    AL_CSP_NOTEOFF_EVT=21,
    AL_NOTE_END_EVT=5,
    AL_SEQP_API_EVT=9,
    AL_SEQP_BANK_EVT=14,
    AL_SEQP_ENV_EVT=6,
    AL_SEQP_LOOP_EVT=11,
    AL_SEQP_META_EVT=7,
    AL_SEQP_MIDI_EVT=2,
    AL_SEQP_PLAY_EVT=15,
    AL_SEQP_PRIORITY_EVT=12,
    AL_SEQP_PROG_EVT=8,
    AL_SEQP_SEQ_EVT=13,
    AL_SEQP_STOPPING_EVT=17,
    AL_SEQP_STOP_EVT=16,
    AL_SEQP_VOL_EVT=10,
    AL_SEQ_END_EVT=4,
    AL_SEQ_MIDI_EVT=1,
    AL_SEQ_REF_EVT=0,
    AL_TEMPO_EVT=3,
    AL_TRACK_END=18,
    AL_TREM_OSC_EVT=22,
    AL_VIB_OSC_EVT=23
} ALMsg;


// WARNING! conflicting data type names: /libaudio.h/ALSeqpConfig - /GE Current Master.h/ALSeqpConfig


// WARNING! conflicting data type names: /libaudio.h/ALSynConfig - /GE Current Master.h/ALSynConfig

typedef enum enum_100 {
    AL_ADPCM_WAVE=0,
    AL_RAW16_WAVE=1
} enum_100;


// WARNING! conflicting data type names: /libaudio.h/ALCSeqMarker - /GE Current Master.h/ALCSeqMarker

typedef enum AL_MIDIctrl {
    AL_MIDI_FX1_CTRL=91,
    AL_MIDI_FX3_CTRL=93,
    AL_MIDI_FX_CTRL_0=20,
    AL_MIDI_FX_CTRL_1=21,
    AL_MIDI_FX_CTRL_2=22,
    AL_MIDI_FX_CTRL_3=23,
    AL_MIDI_FX_CTRL_4=24,
    AL_MIDI_FX_CTRL_5=25,
    AL_MIDI_FX_CTRL_6=26,
    AL_MIDI_FX_CTRL_7=27,
    AL_MIDI_FX_CTRL_8=28,
    AL_MIDI_FX_CTRL_9=29,
    AL_MIDI_PAN_CTRL=10,
    AL_MIDI_PRIORITY_CTRL=16,
    AL_MIDI_SUSTAIN_CTRL=64,
    AL_MIDI_VOLUME_CTRL=7
} AL_MIDIctrl;

typedef enum AL_MIDImeta {
    AL_MIDI_META_EOT=47,
    AL_MIDI_META_TEMPO=81
} AL_MIDImeta;

#define AL_PAN_LEFT 0

#define AL_MAX_PRIORITY 127

#define AL_PLAYING 1

#define AL_SUSTAIN 63

#define AL_PHASE_SUSTREL 4

#define AL_FX_CUSTOM 6

#define AL_FX_BIGROOM 2

#define AL_STOPPED 0

#define AL_PAN_RIGHT 127

#define AL_FX_FLANGE 4

#define AL_PHASE_NOTEON 0

#define AL_VOL_FULL 127

#define AL_DEFAULT_FXMIX 0

#define AL_PHASE_RELEASE 3

#define AL_USEC_PER_FRAME 16000

#define AL_CMIDI_CNTRL_LOOPEND 103

#define AL_PAN_CENTER 64

#define AL_CMIDI_CNTRL_LOOPSTART 102

#define AL_DEFAULT_PRIORITY 5

#define AL_STOPPING 2

#define AL_EVTQ_END 2147483647

#define AL_CMIDI_LOOPEND_CODE 45

#define AL_CMIDI_BLOCK_CODE 254

#define NO_VOICE_ERR_MASK 4

#define AL_PHASE_ATTACK 0

#define AL_FX_BUFFER_SIZE 8192

#define AL_GAIN_CHANGE_TIME 1000

#define AL_DEFAULT_VOICE 0

#define AL_PHASE_DECAY 1

#define AL_HEAP_MAGIC 544434803

#define AL_MAX_CHANNELS 16

#define NO_SOUND_ERR_MASK 1

#define AL_FRAME_INIT -1

#define AL_KEY_MAX 127

#define AL_FX_NONE 0

#define AL_CMIDI_LOOPSTART_CODE 46

#define AL_FX_CHORUS 3

#define AL_FX_SMALLROOM 1

#define NOTE_OFF_ERR_MASK 2

#define AL_HEAP_DEBUG 1

#define AL_CMIDI_CNTRL_LOOPCOUNT_BIG 105

#define AL_FX_ECHO 5

#define AL_KEY_MIN 0

#define AL_CMIDI_CNTRL_LOOPCOUNT_SM 104

#define AL_PHASE_SUSTAIN 2

#define AL_HEAP_INIT 0

#define DG_TINYMON_READ_OP 1

#define PI_BASE_REG_UPPER 1120

#define DG_RAMROM_CMD_READY 3

#define GIO_BASE_REG_UPPER 6144

#define DG_RAMROM_CMD_DONE 4

#define GIO_SYNC_REG_OFFSET 1024

#define DG_RAMROM_REQUEST 1

#define CART_INTR_REG_OFFSET 2048

#define PI_STATUS_REG_OFFSET 16

#define DG_CARTREG_MASK 63

#define RAMROM_BASE_UPPER 4096

#define DG_TINYMON_DMA_READ_OP 3

#define GIO_BASE_REG_UPPER_K1 47104

#define PIFMON_WRITE_ADDR 264241200

#define DG_TINYMON_DMA_WRITE_OP 4

#define RAMROM_BASE_UPPER_K1 45056

#define DG_RAMROM_GRANT 2

#define GIO_INTR_REG_OFFSET 0

#define DG_TINYMON_WRITE_OP 2

#define PI_BASE_REG_UPPER_K1 42080




u32 * get_cdata_vaddr(void);
u32 * get_cdata_rom_start(void);
u32 * get_cdata_rom_end(void);
u32 * get_RareZipASMRomstart(void);
u32 get_RareZipASMRomend(void);
void jump_decompressfile(int source,int target,int buffer);
int init(EVP_PKEY_CTX *ctx);
void * set_stack_entry(void *stack,s32 size);
void set_hw_address_and_unknown(void);
void thread1_idle(void);
void start_idle_thread(void);
void start_rmon_thread(void);
void init_scheduler(void);
void main_entry(void);
void setuplastentryofdebughandler(void);
void activate_stderr(BOOL flag);
void enable_stderr(BOOL flag);
void permit_stderr(BOOL flag);
void setUserCompareValue(u32 value);
void CheckDisplayErrorBuffer(void *frameBufPtr);
void CheckDisplayErrorBufferEvery16Frames(u32 framecount);
void setcurrentcount(void);
void osCreateScheduler(OSSched *s,void *stack,u8 mode,u8 numFields);
void osScAddClient(OSSched *s,OSScClient *c,OSMesgQueue *msgQ);
void osScRemoveClient(OSSched *s,OSScClient *c);
OSMesgQueue * osScGetCmdQ(OSSched *s);
void __scMain(OSSched *sc);
void __scHandleRetrace(OSSched *sc);
void __scHandleRSP(OSSched *sc);
void * get_counters(void);
void __scHandleRDP(OSSched *sc);
OSScTask * *__scTaskReady(OSScTask *__return_storage_ptr__,OSScTask *t);
s32 __scTaskComplete(OSSched *sc,OSScTask *t);
void __scAppendList(OSSched *sc,OSScTask *t);
void __scExec(OSSched *sc,OSScTask *sp,OSScTask *dp);
void __scYield(OSSched *sc);
s32 __scSchedule(OSSched *sc,OSScTask **sp,OSScTask **dp,s32 availRCP);
void osMapTLBRdb(void);
void establish_TLB_buffer_management_table(void);
u32 mp_tlb_related(void);
s32 return_TLB_index_for_entry(int param_1);
void find_remove_TLB_entry(int entry);
void remove_TLB_entry_from_table(int param_1);
void translate_load_rom_from_TLBaddress(void *address);
undefined * getptr_TLBallocatedblock(void);
u32 return_tlb_random_value(void);
void resolve_TLBaddress_for_InvalidHit(void);
void set_hardwire_TLB_to_2(void);
void amCreateAudioMgr(ALSynConfig *c,OSPri priority,amConfig *amc);
void startaudithread(void);
void _amMain(void);
u32 __amHandleFrameMsg(AudioInfo *info,AudioInfo *lastInfo);
void __amHandleDoneMsg(AudioInfo *info);
s32 __amDMA(s32 addr,s32 len,void *state);
ALDMAproc __amDmaNew(AMDMAState **state);
void __clearAudioDMA(void);
void displaylist_related(void);
void video_related_1(void);
void video_related_2(void);
void video_related_3(uint param_1);
undefined4 * display_speed_graph(void);
void video_DL_related_4(void);
void init_video_settings(void);
void init_both_video_buffers(void);
void video_store_A0_plus_2_to_off_D_800232BC(int param_1);
void video_related_7(void);
void video_related_8(void);
void video_related_9(float param_1);
void receive_vi_c_msgs(int msgcount);
void setVideoWidthHeightToMode(char videomode);
void set_coloroutputmode_16bit(void);
void set_coloroutputmode_32bit(void);
u8 * get_video_settings2_frameb(void);
u8 * get_video_settings1_frameb(void);
void set_video_settings2_frameb(u8 *framebuffer);
ulonglong get_80060824(void);
uint * proc_70003C58(uint *param_1);
undefined4 * proc_70003EB4(undefined4 *param_1);
undefined4 * insert_generic_fillrect(undefined4 *param_1);
uint * setupscreensfornumplayers(undefined4 *param_1);
void set_video_mp_related_800232A0(s32 param_1);
s32 get_video_mp_related_800232A0(void);
void set_video_mp_related_8002329C(undefined4 param_1);
undefined4 get_video_mp_related_8002329C(void);
void set_video2_settings_offset_18_1A(short param_1,short param_2);
short get_video2_settings_offset_18(void);
short get_video2_settings_offset_1A(void);
void set_video2_text_clip_size(short txtClipW,short txtClipH);
s16 get_video2_settings_txtClipW(void);
short get_video2_settings_txtClipH(void);
void set_video2_width_height(short width,short height);
short get_video2_settings_width(void);
short get_video2_settings_height(void);
void set_video2_ulx_uly(short ulx,short uly);
short get_video2_settings_ulx(void);
short get_video2_settings_uly(void);
void set_video2_settings_offset_24(int param_1);
void setvideo_far(f32 param_1);
void video_related_21(f32 param_1);
undefined4 video_related_23(void);
void video_related_24(float param_1,float param_2,float param_3);
void set_page_height(f32 aspect,f32 height);
void video_related_27(undefined4 *param_1);
undefined4 * set_setfillcolor(undefined4 *DL,uint red,uint green,int blue);
void indy_grab_jpg_16bit(void);
void indy_grab_jpg_32bit(void);
void indy_grab_rgb_16bit(void);
void indy_grab_rgb_32bit(void);
int * return_match_in_debug_notice_list(char *name,char *data);
void get_entry_of_size_in_debug_notice_list(int size);
void add_new_entry_to_debug_notice_list(dword name,dword data);
void add_debug_notice_deb_c_debug(void);
void get_ptr_debug_notice_list_entry(void *data,char *name);
void scan_debug_notice_list_till_NULL(void);
void proc_70004EBC(void);
void debug_removed(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void init_tlb(void);
void translate_7F_address(void *param_1);
int debug_related_8(uint *op_cur,uint *op_start,int fn_sp,undefined4 *fn_reg);
BOOL was_opcode_a_jal_r_within_70000450_70020D90(u32 *function);
int return_strlen(char *str);
uint indy_file_get_address_subsequent_data(int hardware_address);
undefined8 scan_load_resourceID_from_indy_read_buf(uint resourceID);
ulonglong is_valid_indy_read_buf_resourceID(void);
void debug_indy_stub(void);
void debug_indy_stub_0(void);
void debug_indy_stub_1(void);
undefined4 return_indy_read_buf_resourceID(void);
uint debug_sp_related_11(void *addressspace,u32 entrynum);
uint debug_sp_related_12(void *addressspace,u32 entrynum);
BOOL _is_normal_single_precision_float(f32 fnum);
void is_normal_single_precision_float(undefined8 target,uint float);
void set_normality_of_single_precision_floats(u64 target,f32 param_2,f32 param_3,f32 param_4,f32 param_5);
void proc_70005628(void);
void write_char_to_pos_stderr(int xpos,int ypos,byte letter);
u32 __osRdbSend(u8 *buf,u32 size,u32 type);
void scroll_stderr_oneline(longlong ypos);
void print_to_vidbuff1(int xpos,int ypos,byte char);
void set_ptr_video_buffers(uint *buffer1,uint *buffer2);
void set_video_buffer_pointers(void);
void write_stderr_to_buffer(void *buffer);
s32 return_last_RA_saved_to_stack(undefined4 param_1);
void romCreateMesgQueue(void);
void doRomCopy(void *target,void *source,u32 size);
void romReceiveMesg(void);
void romCopy(char *src,char *dest,int len);
s32 romCopyAligned(void *target,void *source,s32 length);
void doRomWrite(void *source,void *target,u32 size);
void romWrite(void *source,void *target,u32 size);
void init_mainthread_data(void);
void enable_show_mem_use_flag(void);
void mem_bars_flag_toggle(void);
void setup_gamevalues_and_launchmainloop(void);
void mainloop(void);
void run_title_stage(void);
void set_loaded_stage(LEVELID stage);
LEVELID get_stage_num(void);
void return_to_title_from_level_end(void);
undefined4 get_debug_parse_flag(void);
void something_with_boss_c_debug(void);
void audio_related(void *datatable,int numsamples);
void setupaudio(void);
void musicTrack1Play(MUSIC_TRACKS track);
void musicTrack1Stop(void);
ulonglong get_music1vol(void);
void musicTrack1Vol(s16 param_1);
void music_related_0(void);
void music_related_1(f32 rate);
void music_related_3(float rate,s32 param_2,short length);
void music_related_2nd_block(int param_1);
void musicTrack2Stop(void);
ulonglong get_music2vol(void);
void musicTrack2Vol(s16 param_1);
void music_related_5(void);
void music_related_6(float param_1);
void music_related_8(float param_1,undefined8 param_2,short param_3);
void music_related_3rd_block(int param_1);
void musicTrack3Stop(void);
ulonglong get_music3vol(void);
void musicTrack3Vol(ulonglong param_1);
void music_related_10(void);
void music_related_11(float param_1);
void music_related_13(float param_1,undefined8 param_2,short param_3);
void music_related_15(void);
void music_related_16(uint *param_1);
ALMicroTime _sndpVoiceHandler(ALSndPlayer *node);
void _handleEvent(ALSndPlayer *sndp,u32 *event);
void music_related_19(int **param_1);
void music_related_20(int param_1);
void _removeEvents(ALEventQueue *evtq,u32 *state);
uint music_related_22(short *param_1,short *param_2);
ALLink * music_related_23(void *buffer,ALLink_s *param_2);
void music_related_24(int **param_1);
void music_related_25(int param_1,undefined param_2);
ulonglong sfxGetArg0Unk3F(ALLink_s *param_1);
void play_sfx_a1(void *buffer,short entry,ALSndPlayer *data);
void sfxDeactivate(int param_1);
void music_related_29(byte param_1);
void music_related_30(void);
void music_related_32(void);
void music_related_34(void);
void music_related_36(longlong param_1,s16 param_2,undefined4 param_3);
u32 sfx_c_700091C8(void);
void music_related_38(ulonglong param_1);
void music_related_39(f32 param_1);
ulonglong music_related_40(uint param_1);
void music_related_42(ulonglong param_1,ulonglong param_2);
void something_with_memp_c_debug(void);
void mempCheckMemflagTokens(int bstart,int bsize);
void mempSetBankStarts(int *banks);
uint mempAllocBytesInBank(u32 bytes,u8 bank);
u32 memAddEntryOfSizeToBank(u8 *ptrdata,int size,uint bank);
void nulled_list_all8_mem_alloc_banks_sizes(void);
s32 memGetBankSizeLeft(u8 bank);
uint memAllocPackedBytesInBank(uint param_1);
void mempResetBank(u8 bank);
void mempNullNextEntryInBank(u8 bank);
void memaSwap(u8 *a,u8 *b);
void memaMerge(int param_1,undefined4 *param_2);
s32 memaSortMergeEntries(s_mem_alloc_table *param_1);
void memaSortMergeAllEntries(void);
s_mem_alloc_entry * memaFindOpening(s_mem_alloc_table *param_1);
void memaAllocRoomBuffer(u32 addr,u32 size);
void something_with_mema_c_debug(void);
void mempInitMallocTable(void *ptr_allocmem,u32 size);
void mem_related_calls_sort_merge_entries(void);
int mem_related_something_find_first(uint size);
int mem_related_something_find_first_0(int addr,uint size);
void mem_related_model_room_buffers_0(u32 addr,u32 size);
void mem_related_allocated_table_related(void);
float mem_related_something_first_related(void);
void generate_list_alloc_mem(void);
void memaGenerateListsBeforeAfterMerge(void);
void mem_related_something_first_related_0(undefined *param_1);
uint mem_related_0(void);
u32 mem_related_1(int addr,u32 length,u32 maxsize);
u32 get_random_value(void);
void increment_random_num(longlong param_1);
u32 lotsa_shifting_random_related(ulonglong *param_1);
byte * check_string_something(byte *param_1);
char * strtok(char *__s,char *__delim);
void check_boot_switches(void);
byte * check_token(int param_1,byte *param_2);
char * textpointer_load_parse_something(char *param_1,char *param_2);
char * something_with_strings(char *param_1,char *param_2,int size);
void string_append_from_obseg_textbank(char *buffer,char *textfiletext);
undefined8 something_with_strings_0(byte *param_1,char *param_2);
void dummy7000A890(void);
undefined8 string_related(byte *param_1,byte *param_2,longlong param_3);
u8 strtol_related(u8 param_1);
u8 strtol_related_0(u8 param_1);
u8 strtol_related_1(u8 param_1);
ulonglong strtol_related_2(char param_1);
long strtol(char *__nptr,char **__endptr,int __base);
int proutSprintf(void *s,char *buf,size_t n);
int sprintf(char *__s,char *__format,...);
void start_pi_manager(void);
void removed_7000ad30(void);
void something_with_vi_c_debug(void);
undefined8 removed_7000AD80(undefined4 param_1,undefined4 param_2);
undefined8 removed_7000AD90(undefined4 param_1,undefined4 param_2);
void removed_7000ada0(void);
void removed_7000ada8(void);
void debug_text_related_2(void);
void display_text_to_coord(int x,int y,char char);
void debugMenuSetTextPOStoOffset(void);
void blank_debug_buffer_chars(void);
void removed_7000af84(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int something_debug_info_related(int param_1);
void set_final_debug_text_positions(s32 xadjust,s32 yadjust);
void set_debug_text_color(s32 red,s32 blue,s32 green,s32 alpha);
void set_color_speedgraph(int red,int green,int blue,int alpha);
void write_char_to_screen(byte character);
void debug_printcharatpos(int x,int y,byte letter);
void write_string_stdout(u8 *string);
void debug_text_related(int x,int y,byte *character);
uint * read_screen_display_block_and_write_chars(uint *param_1);
void something_with_joy_c_debug(void);
void test_controller_presence(void);
s32 osPfsChecker(OSPfs *param_1);
void controller_7000B734(uint param_1);
void controller_check_for_rumble_maybe(void);
u64 get_attached_controller_count(void);
ulonglong get_num_controllers_plugged_in(void);
void controller_rumble_related(void);
void set_disable_all_rumble_and_something(undefined4 param_1,undefined4 param_2);
void set_ptr_tlb_ramrom_record(undefined4 param_1);
void probably_ramrom_related(int param_1);
void redirect_to_ramrom_replay_and_record_handlers_if_set(void);
longlong controllerSchedulerRelated(void);
s32 get_cur_controller_horz_stick_pos(char param_1);
undefined controller_7000C174(char param_1);
s32 get_cur_controller_vert_stick_pos(char param_1);
undefined controller_7000C284(char param_1);
u32 get_controller_buttons_held(char param_1,controller_buttons param_2);
u32 get_controller_buttons_pressed(char param_1,controller_buttons param_2);
void proc_7000C430(char *param_1,uint param_2);
void proc_7000C470(void);
int get_controller_3dstick_L_R(char param_1,int param_2,int param_3);
int get_controller_3dstick_U_D(char param_1,int param_2,int param_3);
float controller_7000C59C(char param_1,float param_2,float param_3);
float controller_7000C60C(char param_1,float param_2,float param_3);
void controller_7000C67C(void);
void controller_7000C6BC(void);
s32 save_7000C6FC(void);
int save_7000C734(byte param_1,undefined *param_2);
int save_7000C778(byte param_1,undefined *param_2);
s32 save_7000C7BC(byte param_1,save_file *param_2,int param_3);
s32 save_7000C808(byte address,u8 *buffer,int length);
void controller_7000C854(int param_1,s32 param_2);
void reset_cont_rumble_detect(void);
void controller_7000C930(int param_1);
int controller_7000C954(void);
int send_rumble_off_to_PIF(int param_1);
int controller_7000CAAC(int param_1);
void controller_7000CBDC(uint channel,uint param_2,undefined *param_3,undefined4 *param_4);
int controller_7000CD38(OSMesgQueue *mq,undefined4 *param_2,uint channel);
void rmon_entry(void);
BOOL rmon_debug_is_final_build(void);
s32 rmon_debug_returns_neg_1(void);
void removed_7000ceb8(void);
void rmon_debug_stub_0(void);
void removed_7000cec8(void);
void removed_7000ced0(void);
void removed_7000ced8(void);
void removed_7000cee0(void);
void * proutSyncPrintf(void *str,char *buf,size_t n);
void osSyncPrintf(char *fmt,...);
s32 osPiRawStartDma(s32 direction,u32 devAddr,void *dramAddr,u32 size);
u32 osPiGetStatus(void);
void osInitialize(void);
void osWritebackDCacheAll(void);
void osInvalICache(void *addr,int nbytes);
void osUnmapTLB(int index);
u32 __osGetFpcCsr(void);
u32 __osSetFpcCsr(u32 param_1);
void osCreateThread(OSThread *t,OSId id,void *entry,void *arg,void *sp,OSPri p);
void osStartThread(OSThread *t);
void osCreateMesgQueue(OSMesgQueue *mq,OSMesg *msg,s32 msgCount);
void osStopThread(OSThread *t);
void osSetThreadPri(OSThread *t,OSPri p);
u32 osGetCount(void);
void osCreateViManager(OSPri pri);
void viMgrMain(int param_1);
void osCreateViManager_sub(undefined param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined4 param_7,undefined4 param_8);
void osSetEventMesg(OSEvent param_1,OSMesgQueue *param_2,OSMesg param_3);
void osViSetEvent(OSMesgQueue *mq,OSMesg m,u32 retraceCount);
OSIntMask osSetIntMask(OSIntMask param_1);
s32 osRecvMesg(OSMesgQueue *mq,OSMesg *msg,s32 flags);
s32 osSendMesg(OSMesgQueue *mq,OSMesg msg,s32 flags);
undefined8 FUN_7000df3c(void);
void osViSetMode(OSViMode *modep);
void osViSetXScale(f32 value);
void osViSetYScale(f32 value);
void osViRepeatLine(char param_1);
void osViBlack(u32 active);
OSYieldResult osSpTaskYielded(OSTask *tp);
void osDpGetCounters(u32 *array);
void * osViGetCurrentFramebuffer(void);
void * osViGetNextFramebuffer(void);
void osViSwapBuffer(void *frameBufPtr);
void osDpSetStatus(u32 data);
OSTask * _VirtualToPhysicalTask(OSTask *intp);
void osSpTaskLoad(OSTask *intp);
void osSpTaskStartGo(OSTask *tp);
s32 osDpSetNextBuffer(void *bufPtr,u64 size);
void osSpTaskYield(void);
u32 __osGetTLBHi(s32 index);
u32 osVirtualToPhysical(void *virtualAddress);
s32 osAiSetFrequency(u32 frequency);
void alUnlink(ALLink *a);
void alLink(ALLink *a,ALLink *b);
void alClose(ALGlobals *glob);
void alInit(ALGlobals *g,ALSynConfig *c);
void *alHeapDBAlloc(u8 *file,s32 line,ALHeap *hp,s32 num,s32 size);
OSTime osGetTime(void);
longlong __ull_rshift(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
longlong __ull_rem(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
ulonglong __ull_div(undefined4 left_u,undefined4 left_l,undefined4 right_u,undefined4 right_l);
longlong __ll_lshift(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
longlong __ll_rem(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
longlong __ll_div(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
longlong __ll_mul(undefined4 left_u,undefined4 left_l,undefined4 right_u,undefined4 right_l);
void __ull_divremi(ulonglong *param_1,ulonglong *param_2,undefined4 param_3,undefined4 param_4,short param_5);
undefined4 __ll_mod(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);
longlong __ll_lshift(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
s32 osAiSetNextBuffer(void *bufPtr,u32 size);
undefined4 osAiGetLength(void);
void dummy7000EFBC(void);
int _timeToSamples(ALSynth *synth,int micros);
void _freePVoice(ALSynth *drvr,PVoice *pvoice);
void _collectPVoices(ALSynth *drvr);
void __freeParam(ALParam *param);
ALParam *__allocParam(void);
void dummy7000F100(void);
Acmd * alAudioFrame(Acmd *cmdList,s32 *cmdLen,s16 *outBuf,s32 outLen);
void alSynNew(ALSynth *drvr,ALSynConfig *c);
s32 osPiStartDma(OSIoMesg *mb,s32 priority,s32 direction,u32 devAddr,void *dramAddr,u32 size,OSMesgQueue *mq);
void osViSetSpecialFeatures(u32 func);
void _bcopy(void *__src,void *__dest,size_t __n);
void guPerspective(Mtx *m,u16 *perspNorm,float fovy,float aspect,float near,float far,float scale);
void guMtxF2L(float mf [4] [4],Mtx *m);
void guMtxIdentF(float mf [4] [4]);
void guMtxIdent(Mtx *m);
void guMtxL2F(float mf[4][4],Mtx *m);
OSThread * __osGetCurrFaultedThread(void);
void __osExceptionPreamble(void);
void __osException(void);
void FUN_7001067c(void);
void send_mesg(void);
void handle_CpU(void);
void __osEnqueueAndYield(OSThread **queue);
void __osEnqueueThread(OSThread **queue,OSThread *new);
OSThread * __osPopThread(OSThread *list);
undefined8 __osDispatchThread(void);
undefined8 __osDispatchThreadSave(void);
void __osCleanupThread(void);
void __osDequeueThread(OSThread **queue,OSThread *t);
void osYieldThread(void);
void osInvalDCache(void *addr,int nbytes);
void osWritebackDCache(void *addr,s32 nbytes);
int osSetTimer(OSTimer *t,OSTime value,OSTime interval,OSMesgQueue *mq,OSMesg msg);
void alHeapInit(ALHeap *hp,u8 *base,s32 len);
void removed_70010D70(void);
void removed_70010D78(void);
void _bnkfPatchInst(ALInstrument *inst,s32 offset,s32 table);
void removed_70010E6C(void);
void alBnkfNew(ALBankFile *file,char *table);
void alSeqFileNew(ALSeqFile *file,u8 *base);
void __CSPPostNextSeqEvent(ALCSPlayer *seqp);
void __setUsptFromTempo(ALCSPlayer *seqp,f32 tempo);
void proc_70011064(void);
void __CSPRepostEvent(ALEventQueue *evtq,ALEventListItem *item);
void __CSPHandleMIDIMsg(ALCSPlayer *seqp,ALEvent *event);
void proc_70011A64(void);
void __CSPHandleNextSeqEvent(ALCSPlayer *seqp);
void alCSPNew(ALCSPlayer *seqp,ALSeqpConfig *c);
void alCSPSetBank(ALCSPlayer *seqp,ALBank *b);
s32 alCSPGetState(ALCSPlayer *seqp);
void alCSeqGetLoc(ALCSeq *seq,ALCSeqMarker *marker);
void alCSeqSetLoc(ALCSeq *seq,ALCSeqMarker *m);
u8 __getTrackByte(ALCSeq *seq,u32 track);
u32 __readVarLen(ALCSeq *seq,u32 track);
void proc_7001249C(void);
u32 __alCSeqGetTrackEvent(ALCSeq *seq,u32 track,ALEvent *event);
void alCSeqNew(ALCSeq *seq,u8 *ptr);
void alCSeqNewMarker(ALCSeq *seq,ALCSeqMarker *m,u32 ticks);
s32 alCSeqGetTicks(ALCSeq *seq);
u32 alCSeqSecToTicks(ALCSeq *seq,f32 sec,u32 tempo);
f32 alCSeqTicksToSec(ALCSeq *seq,s32 ticks,u32 tempo);
char __alCSeqNextDelta(ALCSeq *seq,s32 *pDeltaTicks);
void alCSPSetSeq(ALCSPlayer *seqp,ALCSeq *seq);
void alCSPPlay(ALCSPlayer *seqp);
void alSeqpStop(ALSeqPlayer *seqp);
void alCSPSetVol(ALCSPlayer *seqp,s16 vol);
void alEvtqFlushType(ALEventQueue *evtq,s16 type);
void alEvtqFlush(ALEventQueue *evtq);
void alEvtqPostEvent(ALEventQueue *evtq,ALEvent *evt,ALMicroTime delta);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq,ALEvent *evt);
void alEvtqNew(ALEventQueue *evtq,ALEventListItem *items,s32 itemCount);
void alSynAddPlayer(ALSynth *drvr,ALPlayer *client);
s32 _allocatePVoice(int param_1,int **param_2,short param_3);
s32 alSynAllocVoice(ALSynth *drvr,ALVoice *voice,ALVoiceConfig *vc);
void alSynSetVol(ALSynth *synth,ALVoice *v,s16 volume,ALMicroTime t);
void alSynStartVoice(ALSynth *synth,ALVoice *voice,ALWaveTable *table);
void alSynSetPan(ALSynth *synth,ALVoice *v,u8 pan);
void alSynSetPitch(ALSynth *synth,ALVoice *v,f32 pitch);
void alSynSetFXMix(ALSynth *synth,ALVoice *v,u8 fxmix);
void alSynStopVoice(ALSynth *synth,ALVoice *v);
void alSynFreeVoice(ALSynth *drvr,ALVoice *voice);
f32 alCents2Ratio(s32 cents);
s32 osPiReadIo(u32 devAddr,u32 *data);
void * memcpy(void *__dest,void *__src,size_t __n);
size_t strlen(char *__s);
char * strchr(char *__s,int __c);
void _Putfld(undefined8 param_1,ulonglong param_2,uint **param_3,int param_4);
byte * _Printf(undefined *param_1,longlong param_2,byte *param_3,uint *param_4);
void osCreatePiManager(OSPri pri,OSMesgQueue *cmdQ,OSMesg *cmdBuf,s32 cmdMsgCnt);
s32 osPfsInit(OSMesgQueue *queue,OSPfs *pfs,int channel);
s32 __osPfsGetStatus(OSMesgQueue *queue,int channel);
s32 osContInit(OSMesgQueue *mq,u8 *bitpattern,OSContStatus *data);
void __osContGetInitData(u8 *pattern,OSContStatus *data);
void __osPackRequestData(u8 cmd);
s32 osContStartQuery(OSMesgQueue *mq);
void osContGetQuery(OSContStatus *data);
s32 osContStartReadData(OSMesgQueue *mq);
void osContGetReadData(OSContPad *data);
void __osPackReadData(void);
s32 osEepromProbe(OSMesgQueue *mq);
s32 osEepromRead(OSMesgQueue *mq,u8 address,u8 *buffer);
void __osPackEepReadData(u8 address);
s32 osEepromWrite(OSMesgQueue *mq,u8 address,u8 *buffer);
void __osPackEepWriteData(u8 address,u8 *buffer);
s32 __osEepStatus(OSMesgQueue *mq,OSContStatus *data);
s32 osEepromLongRead(OSMesgQueue *mq,u8 address,u8 *buffer,int length);
s32 osEepromLongWrite(OSMesgQueue *mq,u8 address,u8 *buffer,int length);
s32 osPfsIsPlug(OSMesgQueue *queue,u8 *pattern);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern,OSContStatus *data);
void __osSiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 __osSiRawStartDma(s32 direction,void *dramAddr);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8 *data);
s32 __osContRamWrite(OSMesgQueue *mq,int channel,u16 address,u8 *buffer,int force);
void __osPackRamWriteData(int channel,u16 address,u8 *buffer);
s32 __osContRamRead(OSMesgQueue *mq,int channel,u16 address,u8 *buffer);
void __osPackRamReadData(int channel,u16 address);
void guAlignF(float mf [4] [4],float a,float x,float y,float z);
void guAlign(Mtx *m,float a,float x,float y,float z);
void guOrthoF(float mf [4] [4],float l,float r,float b,float t,float n,float f,float scale);
void guOrtho(Mtx *m,float l,float r,float b,float t,float n,float f,float scale);
short coss(ushort x);
short sins(ushort x);
void guTranslateF(float mf[4][4],float x,float y,float z);
void guTranslate(Mtx *m,float x,float y,float z);
int _bcmp(void *__s1,void *__s2,size_t __n);
void guScaleF(float mf[4][4],float x,float y,float z);
void guScale(Mtx *m,float x,float y,float z);
void guLookAtReflectF(float mf [4] [4],LookAt *l,float xEye,float yEye,float zEye,float xAt,float yAt,float zAt,float xUp,float yUp,float zUp);
void guLookAtReflect(Mtx *m,LookAt *l,float xEye,float yEye,float zEye,float xAt,float yAt,float zAt,float xUp,float yUp,float zUp);
void guLookAtF(float mf [4] [4],float xEye,float yEye,float zEye,float xAt,float yAt,float zAt,float xUp,float yUp,float zUp);
void guLookAt(Mtx *m,float xEye,float yEye,float zEye,float xAt,float yAt,float zAt,float xUp,float yUp,float zUp);
void guRotateF(float mf [4] [4],float a,float x,float y,float z);
void guRotate(Mtx *m,float a,float x,float y,float z);
longlong __d_to_ll(double param_1);
longlong __f_to_ll(float param_1);
longlong __d_to_ull(double param_1);
longlong __f_to_ull(float param_1);
double __ll_to_d(undefined4 param_1,undefined4 param_2);
float __ll_to_f(undefined4 param_1,undefined4 param_2);
double __ull_to_d(int param_1,undefined4 param_2);
float __ull_to_f(int param_1,undefined4 param_2);
void __osSetSR(u32 param_1);
u32 __osGetSR(void);
s32 __osSiRawReadIo(u32 devAddr,u32 *data);
s32 __osSpRawWriteIo(u32 param_1,u32 param_2);
s32 osPiRawReadIo(u32 devAddr,u32 *data);
void bzero(void *__s,size_t __n);
void __osSetHWIntrRoutine(OSHWIntr interrupt,s32 *handler);
s32 __osLeoInterrupt(void);
void __osLeoAbnormalResume(void);
void __osLeoResume(void);
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
void __osTimerServicesInit(void);
void __osTimerInterrupt(void);
void __osSetTimerIntr(OSTime tim);
OSTime __osInsertTimer(OSTimer *t);
OSPri osGetThreadPri(OSThread *t);
void __osViInit(void);
__OSViContext * __osViGetCurrentContext(void);
void __osViSwapContext(void);
u32 __osSpGetStatus(void);
void __osSpSetStatus(u32 data);
s32 __osSpSetPc(u32 data);
s32 __osSpRawStartDma(s32 direction,u32 devAddr,void *dramAddr,u32 size);
int __osSpDeviceBusy(void);
ulonglong __osDpDeviceBusy(void);
u32 __osProbeTLB(void *vaddr);
void alSynDelete(ALSynth *drvr);
ulonglong __osAiDeviceBusy(void);
void alSaveNew(ALSave *f);
void alMainBusNew(ALMainBus *m,void *sources,int maxSources);
void alAuxBusNew(ALAuxBus *m,void *sources,int maxSources);
void alResampleNew(ALResampler *r,ALHeap *hp);
void alLoadNew(ALLoadFilter *f,ALDMANew dmaNew,ALHeap *hp);
void alEnvmixerNew(ALEnvMixer *e,ALHeap *hp);
void init_lpfilter(undefined8 param_1,short *param_2);
void alFxNew(ALFx *r,ALSynConfig *c,ALHeap *hp);
ALFxRef *alSynAllocFX(ALSynth *s,s16 bus,ALSynConfig *c,ALHeap *hp);
s32 alMainBusParam(void *filter,s32 paramID,void *param);
longlong *alMainBusPull(void *filter,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
s32 alLoadParam(void *filter,s32 paramID,void *param);
longlong *alRaw16Pull(void *filter,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
uint * proc_7001A030(void);
uint * alAdpcmPull(int param_1,short *param_2,uint param_3,undefined8 param_4,uint *param_5);
s32 alResampleParam(void *filter,s32 paramID,void *param);
uint * alResamplePull(int *param_1,short *param_2,longlong param_3,undefined8 param_4,uint *param_5);
float _ldexpf(float __x,int __exponent);
float _frexpf(float __x,int *__exponent);
s32 alEnvmixerParam(void *filter,s32 paramID,void *param);
int proc_7001AAF4(float param_1,float param_2,longlong param_3,undefined2 *param_4);
Acmd * _pullSubFrame(void *filter,s16 *inp,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
void proc_7001AE54(void);
Acmd * *alEnvmixerPull(void *f,s16 *outp,s32 out,s32 sampleOffset,Acmd *p);
s32 alAuxBusParam(void *filter,s32 paramID,void *param);
Acmd * *alAuxBusPull(void *f,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
s32 alSaveParam(void *filter,s32 paramID,void *param);
longlong *alSavePull(void *filter,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
s32 osJamMesg(OSMesgQueue *mq,OSMesg msg,s32 flags);
OSMesgQueue * osPiGetCmdQueue(void);
ulonglong proc_7001B830(void);
ulonglong proc_7001B9A0(void);
void osDestroyThread(OSThread *t);
void __setInstChanState(int param_1,undefined *param_2,int param_3);
void __resetPerfChanState(int param_1,int param_2);
void __initFromBank(int param_1,int param_2);
void proc_7001BDE8(void);
int __vsDelta(int param_1,int param_2);
undefined2 __vsVol(int param_1,int param_2);
void __seqpReleaseVoice(int param_1,int *param_2,int *param_3);
undefined8 __voiceNeedsNoteKill(int param_1,int *param_2,int param_3);
void __unmapVoice(int param_1,int param_2);
void __postNextSeqEvent(int param_1);
void proc_7001C1BC(int param_1,int param_2);
uint __vsPan(int param_1,int param_2);
undefined4 * *__lookupVoice(int param_1,char param_2,char param_3);
undefined4 * *__mapVoice(int param_1,undefined param_2,undefined param_3,undefined param_4);
int __lookupSoundQuick(int param_1,byte param_2,byte param_3,uint param_4);
void __handleMIDIMsg(ALSeqPlayer *seqp,ALEvent *event);
void proc_7001CC74(void);
ALMicroTime __seqpVoiceHandler(void *node);
void __seqpStopOsc(int param_1,int *param_2);
void __initChanState(int param_1);
void alSeqpNew(ALSeqPlayer *seqp,ALSeqpConfig *c);
void alSynStartVoiceParams(ALSynth *s,ALVoice *v,ALWaveTable *w,f32 pitch,s16 vol,ALPan pan,u8 fxmix,ALMicroTime t);
void alCopy(void *src,void *dest,s32 len);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
void _Litob(_Pft *px,char code);
void _Genld(_Pft *px,char code,char *p,short nsig,short xexp);
void dummy7001DFD8(void);
void _Ldtob(_Pft *px,char code);
s32 osEPiRawStartDma(OSPiHandle *pihandle,s32 direction,u32 devAddr,void *dramAddr,u32 size);
void __osDevMgrMain(void *arg);
void proc_7001E9B0(undefined param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined4 param_8);
u16 __osSumcalc(u8 *ptr,int length);
s32 __osIdCheckSum(u16 *ptr,u16 *csum,u16 *icsum);
int __osRepairPackId(int param_1,int param_2,undefined4 *param_3);
int __osCheckPackId(int param_1,byte *param_2);
s32 __osGetId(OSPfs *pfs);
s32 __osCheckId(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs,__OSInode *inode,u8 flag,u8 bank);
s32 __osPfsSelectBank(OSPfs *pfs);
int __osSiDeviceBusy(void);
void guNormalize(float *x,float *y,float *z);
float sqrtf(float __x);
OSPiHandle * osLeoDiskInit(void);
void __osSetCompare(u32 param_1);
void alFilterNew(ALFilter *f,ALCmdHandler h,ALSetParam s,int type);
ulonglong _doModFunc(void);
uint * *_filterBuffer(int param_1,uint param_2,uint param_3,uint *param_4);
undefined4 * *_saveBuffer(int param_1,uint param_2,int param_3,int param_4,undefined4 *param_5);
uint * *_loadBuffer(int param_1,uint param_2,uint param_3,int param_4,uint *param_5);
uint * *_loadOutputBuffer(int param_1,int *param_2,uint param_3,undefined8 param_4,uint *param_5);
s32 alFxParamHdl(void *filter,s32 paramID,void *param);
s32 alFxParam(void *filter,s32 paramID,void *param);
longlong *alFxPull(void *filter,s16 *outp,s32 outCount,s32 sampleOffset,Acmd *p);
uint * alFxParam(int *param_1,undefined8 param_2,undefined8 param_3,undefined param_4,undefined4 param_5,undefined param_6,undefined param_7,undefined param_8,undefined4 param_9,undefined param_10,undefined4 param_11,undefined4 param_12);
uint * alFxPull(int param_1,undefined param_2,undefined param_3,undefined param_4,undefined4 param_5,undefined param_6,undefined param_7,undefined param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21);
void alSeqGetLoc(ALSeq *seq,ALSeqMarker *m);
void alSeqSetLoc(ALSeq *seq,ALSeqMarker *m);
s32 alSeqGetTicks(ALSeq *seq);
void dummy70020560(void);
s32 readVarLen(ALSeq *seq);
void alSeqNextEvent(ALSeq *seq,ALEvent *event);
void alSeqNewMarker(ALSeq *seq,ALSeqMarker *m,u32 ticks);
u32 alSeqSecToTicks(ALSeq *seq,f32 sec,u32 tempo);
f32 alSeqTicksToSec(ALSeq *seq,s32 ticks,u32 tempo);
ulonglong __alSeqNextDelta(int *param_1,undefined4 *param_2);
s32 read32(ALSeq *seq);
s16 read16(ALSeq *seq);
void alSeqNew(ALSeq *seq,u8 *ptr,s32 len);
void alSynSetPriority(ALSynth *s,ALVoice *voice,s16 priority);
lldiv_t * lldiv(lldiv_t *__return_storage_ptr__,longlong __numer,longlong __denom);
ldiv_t ldiv(long __numer,long __denom);
void __osResetGlobalIntMask(OSHWIntr interrupt);
s32 osEPiRawWriteIo(OSPiHandle *pihandle,u32 devAddr,u32 data);
int huft_build(char b,char n,char s,char d,undefined e,undefined t,undefined m);
int inflate_codes(char tl,char td,char bl,char bd);
int inflate_stored(void);
int inflate_fixed(void);
int inflate_dynamic(void);
int inflate_block(char e);
int inflate(void);
void decompress.entry(int source,int target,int buffer);
void initGameData(void);
void init_weapon_animation_groups_maybe(void);
void reset_counter_rand_body_head(void);
uint proc_7F0001F0(int param_1,int param_2,int param_3);
int proc_7F000290(int param_1,int param_2,int param_3);
int proc_7F00032C(int *param_1);
void proc_7F00046C(int **param_1);
int proc_7F0004D0(int *param_1);
void somethingwith_weapon_animation_groups(void);
void proc_7F000980(void);
void proc_7F0009A0(void);
void removed_7f0009d0(void);
void proc_7F0009E0(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void expand_ani_table_entries(int **param_1);
void alloc_load_expand_ani_table(void);
void setup_ptr_playergait(void);
void set_gu_scale(void);
void removed_7f000bc0(void);
void image_entries_load(void);
void alloc_intro_matrices(void);
void init_menus_or_reset(void);
void initguards(void);
void alloc_init_GUARDdata_entries(int guard_count);
void set_new_rand_head_bodies(void);
void init_obj_register_difficulty_vals(void);
void alloc_false_GUARDdata_to_exec_global_action(void);
void debug_object_load_all_models(void);
void debug_weapon_load_table(void);
void init_sound_effects_registers(void);
void init_load_objpos_table(void);
void alloc_lookup_buffers(void);
void reinit_between_menus(void);
void proc_7F001910(int param_1);
void proc_7F001928(int param_1);
void proc_7F001940(int param_1);
void write_monitor_ani_control_blocks(void);
void initialize_temp_mine_table(void);
int load_proptype(PROPTYPE param_1);
void proc_7F001BD4(float *param_1,float *param_2);
void prepare_load_objects(undefined8 param_1,ushort *param_2);
void expand_08_obj_set_guard_MP_weapons(int param_1,ushort *param_2);
void expand_type_0D_MP_weapon_expansion_routine(undefined8 param_1,ushort *param_2);
void expand_type_04_object(undefined8 param_1,ushort *param_2);
void expand_type_06_object(undefined8 param_1,ushort *param_2);
void expand_type_0D_object_autoturret(undefined8 param_1,ushort *param_2);
void expand_type_0C_object(undefined8 param_1,ushort *param_2);
void expand_type_0A_object(int param_1,ushort *param_2,int param_3);
void expand_type_0B_object(int param_1,ushort *param_2);
void proc_7F00324C(void);
void expand_type_01_object(void);
void proplvreset2(longlong levelid);
void something_with_stage_objectives(void);
void set_parent_cur_tag_entry(int param_1);
void setup_briefing_text_entry_parent(int param_1);
void add_ptr_to_objective(int param_1);
void set_parent_cur_obj_enter_room(int param_1);
void set_parent_cur_obj_deposited_in_room(int param_1);
void set_parent_cur_obj_photograph(int param_1);
void something_with_ejected_cartridges(void);
void init_player_BONDdata_stats(void);
void proc_7F005450(void);
void proc_7F005520(void);
void proc_7F005534(undefined4 param_1);
void proc_7F005540(int param_1);
void proc_7F005624(int param_1);
ulonglong set_weapon_model_generated_thrown_object(undefined4 param_1);
void load_camera_intro_type_values(void);
void proc_7F0061F0(void);
void alloc_additional_item_slots(int additionalentries);
void proc_7F0062C0(int param_1,int param_2,int param_3,int *param_4);
void sets_a_bunch_of_BONDdata_values_to_default(void);
ulonglong init_pathtable_something(float *param_1,byte *param_2,int **param_3);
void init_path_table_links(void);
void alloc_explosion_smoke_casing_scorch_impact_buffers(void);
void proc_7F007180(void);
void proc_7F007290(void);
void proc_7F0072B0(void);
void disable_onscreen_cheat_text(void);
void set_mt_tex_alloc(void);
void unload_loop_all_guards(void);
void unload_loop_all_sfx(void);
void unload_alarms_something(void);
void cleanupObjects(void);
void cleanupObjectives(void);
void unload_music_related(void);
void proc_7F007770(void);
void unload_loop_all_objects(void);
void unload_something_7f007920(void);
void unload_removed_7f007970(void);
void unload_music_related_7F007980(void);
undefined4 * something_with_gunbarrel_and_rareware_logo_matrix_manip(undefined4 *displaylist);
undefined4 * insert_sight_backdrop_eye_intro(undefined4 *param_1);
undefined4 * proc_7F007CC8(undefined4 *param_1,int param_2,int *param_3,int *param_4);
undefined4 * insert_sniper_sight_eye_intro(undefined4 *param_1);
undefined4 * proc_7F007E70(undefined4 *param_1,uint param_2);
undefined4 proc_7F007F30(void);
void insert_bond_eye_intro(undefined4 *param_1);
undefined4 *load_display_rare_logo(undefined4 *param_1,undefined8 param_2,undefined8 param_3,int param_4,uint param_5);
void proc_7F008B58(ulonglong param_1);
void retrieve_display_rareware_logo(undefined4 *param_1);
ulonglong proc_7F008DD0(void);
void proc_7F008DE4(ushort **param_1,int *param_2);
void proc_7F008E80(short *param_1,int param_2);
void proc_7F00920C(void);
longlong proc_7F009254(longlong param_1);
ulonglong proc_7F009744(void);
uint * write_text_at_abs_coord(uint *param_1,uint *param_2,uint *param_3,byte *param_4,int param_5,int param_6,uint param_7,int param_8,int param_9,int param_10,int param_11);
ulonglong check_if_cheat_available(u32 cheat);
int getplayerfavoredweapon(int param_1,int param_2);
int menu_control_stick_tracking(void);
undefined4 load_draw_selected_icon_folder_select(undefined4 param_1);
uint * add_tab1_start(undefined4 *param_1);
undefined8 isontab1(void);
uint * add_tab3_previous(undefined4 *param_1);
undefined8 isontab3(void);
void set_cursor_pos_tab2(void);
uint * add_tab2_next(undefined4 *param_1);
undefined8 isontab2(void);
void init_menu00_legalscreen(void);
void update_menu00_legalscreen(void);
void interface_menu00_legalscreen(void);
uint * display_aligned_white_text_to_screen(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6,int param_7,int param_8);
void constructor_menu00_legalscreen(Gfx *param_1);
void reset_menutimer(void);
void dummy7F00AAF8(void);
void interface_menu17_switchscreens(void);
void constructor_menu17_switchscreens(Gfx *param_1);
void init_menu01_nintendo(void);
void update_menu01_nintendo(void);
void interface_menu01_nintendo(void);
void constructor_menu01_nintendo(Gfx *param_1);
int ** init_menu02_rareware(void);
void update_menu02_rareware(void);
void interface_menu02_rareware(void);
void constructor_menu02_rareware(Gfx *param_1);
void init_menu03_eyeintro(void);
void update_menu_03_eyeintro(void);
void interface_menu03_eyeintro(void);
void constructor_menu03_eyeintro(Gfx *param_1);
void init_menu04_goldeneyelogo(void);
void update_menu04_goldeneyelogo(void);
void interface_menu04_goldeneyelogo(void);
void constructor_menu04_goldeneyelogo(Gfx *param_1);
void disable_all_switches(int param_1);
void set_item_visibility_in_objinstance(int objinstance,int item,undefined4 mode);
void select_load_bond_picture(int objinstance,u32 bondID);
void load_walletbond(void);
void proc_7F00B990(void);
void init_menu05_filesel(void);
void update_menu05_filesel(void);
int get_chapter_briefing_entry(int briefing);
void toggle_deletion_menu_for_folder(int param_1);
void interface_menu05_filesel(void);
int get_ptr_difficulty_name(DIFFICULTY difficulty);
void constructor_menu05_filesel(Gfx *param_1);
void init_menu06_modesel(void);
void update_menu06_modesel(void);
void interface_menu06_modesel(void);
undefined4 proc_7F00D5E8(undefined4 param_1);
void set_menu_cursor_pos_to_setting(int setting);
void constructor_menu06_modesel(Gfx *param_1);
int pull_and_display_text_for_folder_a0(LEVELID param_1);
BOOL check_if_stage_completed_on_difficulty(int stage,DIFFICULTY difficulty);
longlong get_highest_unlocked_difficulty_for_level(longlong stage);
void init_menu07_missionsel(void);
void update_menu07_missionsel(void);
void interface_menu07_missionsel(void);
void set_cursor_to_stage_solo(longlong param_1);
void constructor_menu07_missionsel(Gfx *param_1);
void init_menu08_difficulty(void);
void update_menu08_difficulty(void);
void interface_menu08_difficulty(void);
uint * print_current_solo_briefing_stage_name(uint *param_1,byte *param_2);
void set_cursor_pos_difficulty(int difficulty);
void constructor_menu08_difficulty(Gfx *param_1);
void init_menu09_007options(void);
void update_menu09_007options(void);
void interface_menu09_007options(void);
void constructor_menu09_007options(Gfx *param_1);
u32 get_player_control_style(int playernum);
BOOL check_if_mp_stage_unlocked(int stage);
void select_game_length(void);
void copy_aim_settings_to_playerdata(void);
void advance_aim_settings_selection(void);
void unlock_mp_chars(void);
u32 get_selected_num_players(void);
HEADS get_player_mp_char_head(int player);
u8 get_player_mp_char_gender(int player);
BODIES get_player_mp_char_body(int player);
f32 get_player_mp_handicap(int player);
f32 get_player_mp_char_height(int player);
int get_mp_timelimit(void);
int get_mp_pointlimit(void);
void reset_mp_options_for_scenario(MPSCENARIOS scenarioid);
void init_mp_options_for_scenario(u32 numplayers);
void init_menu0E_mpoptions(void);
void update_menu0E_mpoptions(void);
void interface_menu0E_mpoptions(void);
void constructor_menu0E_mpoptions(Gfx *param_1);
BOOL hasPlayerSelectedMPChar(int playerchar);
void init_menu0f_mpcharsel(void);
void update_menu0F_mpcharsel(void);
void interface_menu0F_mpcharsel(void);
int proc_7F0122A8(int param_1,int param_2,int param_3);
undefined4 * proc_7F01231C(void);
void constructor_menu0F_mpcharsel(Gfx *param_1);
void init_menu10_mphandicap(void);
void update_menu10_mphandicap(void);
void interface_menu10_mphandicap(void);
void constructor_menu10_mphandicap(Gfx *param_1);
void init_menu11_mpcontrol(void);
void update_menu11_mpcontrols(void);
void interface_menu11_mpcontrols(void);
void constructor_menu11_mpcontrol(Gfx *param_1);
void init_menu12_mpstage(void);
void update_menu12_mpstage(void);
void interface_menu12_mpstage(void);
void constructor_menu12_mpstage(Gfx *param_1);
MPSCENARIOS get_scenario(void);
void init_menu13_mpscenariosel(void);
void update_menu13_mpscenario(void);
void interface_menu13_mpscenario(void);
void constructor_menu13_mpscenario(Gfx *param_1);
ulonglong get_players_team_or_scenario_item_flag(int player);
void set_players_team_or_scenario_item_flag(int player,char flag);
void init_menu14_mpteamsel(void);
void update_menu14_mpteams(void);
ulonglong interface_menu14_mpteams(void);
void constructor_menu14_mpteams(Gfx *param_1);
void set_briefing_page(WATCH_BRIEFING_PAGE page);
void load_briefing_text_for_stage(void);
void init_menu0A_briefing(void);
void update_menu0A_briefing(void);
void interface_menu0A_briefing(void);
uint * print_objectives_and_status_to_menu(uint *param_1,int param_2,byte *param_3,int param_4);
void constructor_menu0A_briefing(Gfx *param_1);
void init_menu0B_runstage(void);
void init_menu0C_missionfailed(void);
void update_menu0C_missionfailed(void);
void interface_menu0C_missionfailed(void);
undefined8 proc_7F01631C(void);
void constructor_menu0C_missionfailed(Gfx *param_1);
void init_menu0D_missioncomplete(void);
void update_menu0D_missioncomplete(void);
void interface_menu0D_missioncomplete(void);
void constructor_menu0D_missioncomplete(Gfx *param_1);
void init_menu15_cheat(void);
void update_menu15_cheat(void);
void interface_menu15_cheat(void);
void constructor_menu15_cheat(Gfx *param_1);
void init_menu16_nocontroller(void);
void update_menu16_nocontrollers(void);
void interface_menu16_nocontrollers(void);
void constructor_menu16_nocontrollers(Gfx *param_1);
void do_extended_cast_display(longlong param_1);
void init_menu18_displaycast(void);
void update_menu18_displaycast(void);
void interface_menu18_displaycast(void);
void constructor_menu18_displaycast(Gfx *param_1);
void init_menu19_spectrum(void);
void update_menu19_spectrum(void);
void interface_menu19_spectrum(void);
void constructor_menu19_spectrum(Gfx *param_1);
void set_menu_to_mode(MENU param_1,u32 param_2);
MENU get_currentmenu(void);
void menu_init(undefined8 param_1,undefined8 param_2);
void menu_jump_constructor_handler(Gfx *DL);
void proc_7F01B0E0(ushort *param_1,byte *param_2);
void proc_7F01B134(ushort *param_1,ushort *param_2);
void proc_7F01B1C8(ushort *param_1,byte *param_2);
undefined4 *proc_7F01B240(undefined4 *param_1,int param_2,longlong param_3,int *param_4,int *param_5);
undefined4 * proc_7F01B6E0(undefined4 *param_1,int param_2,int param_3);
void proc_7F01BAE0(short *param_1,int param_2);
uint * proc_7F01BFF8(uint *param_1,uint param_2,int param_3);
undefined4 * insert_imageDL(Gfx *param_1);
undefined4 * proc_7F01C1A4(undefined4 *param_1);
ulonglong die_blood_image_routine(void);
undefined4 * proc_7F01C400(undefined4 *param_1);
undefined4 * proc_7F01C670(undefined4 *param_1);
undefined4 * proc_7F01CA18(undefined4 *param_1);
byte * decrypt_bleeding_animation_data(char *param_1,byte param_2,uint param_3,byte *param_4,char *param_5);
void proc_7F01CC94(byte *param_1,short param_2,byte *param_3);
void proc_7F01CCEC(int param_1,uint param_2,uint param_3,int param_4,byte param_5);
void proc_7F01CEEC(int param_1,int param_2,int param_3);
void proc_7F01D02C(int param_1,int param_2,int param_3);
void proc_7F01D16C(undefined *param_1,int param_2,int param_3,undefined *param_4);
byte * proc_7F01D1C0(byte *param_1,int param_2,int param_3,byte *param_4);
f32 get_007_reaction_speed(void);
f32 get_007_health_mod(void);
f32 get_007_damage_mod(void);
f32 get_007_accuracy_mod(void);
void end_of_mission_briefing(void);
void sub_GAME_7F01D500(void);
void deleteCurrentSelectedFolder(void);
void copyCurrentEEPROMtoStack(void);
u8 getSelectedFolderBond(void);
void set_selected_folder_num(u32 foldernum);
void set_selected_difficulty(DIFFICULTY difficulty);
void set_solo_and_ptr_briefing(LEVELID level);
void proc_7F01D61C(undefined4 *param_1);
void proc_7F01D644(undefined4 *param_1);
void store_favorite_weapon_current_player(u32 right,u32 left);
undefined4 proc_7F01D6C0(void);
void proc_7F01D6E0(void);
int proc_7F01D758(uint *param_1);
void proc_7F01D7A0(uint *param_1);
void proc_7F01D840(uint *param_1);
u32 getEEPROMFoldernum(save_file *eeprom);
void setEEPROMtoFoldernum(save_file *eeprom,byte folder);
int set_eeprom_flag_0x18(save_file *folder);
void reset_eeprom_flag_0x18(save_file *folder,int value);
int get_selected_bond(save_file *folder);
void set_selected_bond(save_file *folder,int bond);
ulonglong check_if_eeprom_flag_set_0x80(save_file *folder);
void toggle_eeprom_flag_set_0x80(save_file *folder,longlong mode);
ulonglong get_eeprom_stage_complete_time_for_difficulty(save_file *eepromfile,STAGENUM stage,DIFFICULTY difficulty);
void proc_7F01DAE4(int param_1,longlong param_2,longlong param_3,longlong param_4);
BOOL doesSaveHaveStageCompletedOnDifficulty(save_file *folder,STAGENUM stage,DIFFICULTY difficulty);
void proc_7F01DCB0(int param_1,longlong param_2,longlong param_3,int param_4);
ulonglong check_if_cheat_unlocked(save_file *folder,longlong cheat);
void proc_7F01DD74(int param_1,longlong param_2);
save_file * getEEPROMforFoldernum(u32 foldernum);
int proc_7F01DE50(void);
void proc_7F01DEB4(int param_1);
void proc_7F01DF90(void);
BOOL check_if_valid_folder_num(int folder);
s32 isStageUnlockedAtDifficulty(int foldernum,STAGENUM stageid,DIFFICULTY difficulty);
void proc_7F01E504(uint *param_1,undefined4 *param_2);
void unlock_stage_in_folder_on_difficulty(int folder,longlong stagenum,longlong selecteddifficulty,int maxtime);
void proc_7F01E760(u32 folder,CHEAT_IDS cheat);
void get_highest_stage_difficulty_completed_in_folder(int foldernum,STAGENUM *stagenum,DIFFICULTY *difficulty);
u32 check_egypt_completed_in_folder(int folder);
u32 check_egypt_completed_any_folder(void);
u32 check_cradle_completed_in_folder(u32 folder);
u32 check_aztec_completed_in_folder_secret_00(u32 folder);
u32 check_egypt_completed_in_folder_00(int folder);
u32 check_cradle_completed_any_folder(void);
BOOL check_aztec_completed_any_folder_secret_00(void);
BOOL check_egypt_completed_any_folder_00(void);
u32 removed_would_have_returned_bond_for_folder_num(u32 folder);
void set_selected_bond_to_folder(u32 folder,u32 bond);
void proc_7F01EBF4(void);
void proc_7F01EBFC(void);
void delete_eeprom_folder(int foldernum);
void proc_7F01ED10(ulonglong param_1);
void proc_7F01EDA0(ulonglong param_1);
void update_eeprom_to_current_solo_watch_settings(save_file *eepromsave);
void get_screen_ratio_settings_for_mpgame_from_folder(int folder);
void delete_update_eeprom_file(int folder);
void copy_eeprom_to_stack_set_folder_num(int foldernum);
void copy_eeprom_from_to(int from,int to);
void copy_eepromfile_a0_from_a1_to_buffer(longlong param_1,save_file *param_2);
BOOL is007ModeUnlockedinFolder(u32 foldernum);
undefined4 get_numguards(void);
void get_ptr_allocated_block_for_weapon_vertices(int param_1);
void set_show_patrols_flag(BOOL flag);
undefined4 get_show_patrols_flag(void);
undefined4 proc_7F01F574(void);
void set_or_unset_GUARDdata_flag(GUARDdata *guard,int param_2);
int proc_7F01F614(int param_1,int param_2,float *param_3,float *param_4,int param_5);
undefined8 proc_7F01FC10(int param_1,float *param_2,float *param_3,float *param_4);
int get_next_available_guardID(void);
void proc_7F020018(void);
f32 get_guard_health(GUARDdata *param_1);
void guard_calc_final_damage_recieved(GUARDdata *guard,u32 damage);
float proc_7F020090(GUARDdata *param_1);
u32 init_GUARDdata_with_set_values(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
int replace_GUARDdata_with_actual_values(u32 param_1,u32 param_2,u32 param_3,undefined4 param_4,undefined4 param_5);
void disable_sounds_attached_to_player_then_something(int param_1);
void animation_speed_related(f32 rate);
f32 get_animation_rate(void);
void proc_7F0205F0(int param_1);
void proc_7F0206D4(int param_1);
float proc_7F020794(int param_1);
void proc_7F02083C(int param_1,float *param_2);
void proc_7F020D94(int param_1);
void proc_7F020E40(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);
ulonglong proc_7F020EF0(char *param_1,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F021B20(int param_1);
void proc_7F021BB4(undefined *param_1);
void proc_7F021BD8(undefined *param_1);
longlong proc_7F021BFC(char *param_1,uint *param_2,uint param_3);
void proc_7F022078(int param_1,longlong param_2,float *param_3,undefined4 *param_4);
void proc_7F0221DC(int param_1,int param_2,ushort *param_3,float *param_4);
void proc_7F022648(int param_1,float *param_2,undefined4 param_3,undefined4 param_4);
void proc_7F022980(float *param_1,float *param_2);
void removed_tooklevelscale(f32 param_1);
void proc_7F022E24(undefined4 param_1);
void proc_7F022E30(void);
void proc_7F022E90(void);
void proc_7F022EC8(void);
void proc_7F022EE0(undefined4 param_1);
void proc_7F022EEC(void);
GUARDdata * check_if_guardnum_loaded_get_ptr_GUARDdata(short guardnum);
int something_with_weaponpos_of_guarddata_hand(GUARDdata *guard,int hand);
int is_weapon_in_guarddata_hand(GUARDdata *guard,int hand);
void proc_7F02308C(int param_1,int *param_2,undefined4 *param_3,float *param_4,float *param_5);
void proc_7F023160(int param_1,undefined4 *param_2,float *param_3,undefined4 *param_4);
undefined4 proc_7F023188(int param_1);
undefined8 proc_7F023194(int param_1,float *param_2,float *param_3,float *param_4);
ulonglong load_body_head_if_not_loaded(int model);
uint maybe_load_models_for_guards(int body,int head,object_header *bodyheader,object_header *headheader,int sunglasses,uint object_controller);
uint setup_chr_instance(int body,int head,object_header *body_header,object_header *head_header,int sunglasses);
uint retrieve_header_for_body_and_head(int body,int head,ulonglong bitflags);
undefined4 get_current_random_body(void);
undefined4 select_psuedorandom_heads(int param_1);
u32 get_random_head(int bodyID);
void expand_09_characters(void);
ulonglong check_if_item_held_like_pistol(int param_1);
void proc_7F023948(int param_1,float param_2);
void proc_7F023A94(int param_1,float param_2);
undefined4 proc_7F023B5C(void);
int proc_7F023BC0(void);
undefined4 proc_7F023C54(void);
void proc_7F023CB8(void);
void proc_7F023E14(int param_1,float param_2);
void proc_7F023E48(int param_1);
void actor_kneel(void);
void perform_animation_for_actor(GUARDdata *guard,int param_2,int param_3,int param_4,byte param_5,int param_6);
void proc_7F024150(int param_1);
void throw_weapon_in_guard_hand(void);
void proc_7F024334(void);
void actor_shuffle_feet(void);
void proc_7F0244AC(void);
void proc_7F024548(void);
void proc_7F024648(int param_1);
void proc_7F0247B8(int param_1);
void proc_7F024800(void);
void proc_7F024A84(void);
void proc_7F024CF8(int param_1,float *param_2);
void proc_7F024F00(int param_1);
void proc_7F024F8C(int param_1);
float proc_7F0250BC(void);
void proc_7F02516C(int param_1,int param_2,int param_3,int *param_4,uint param_5,undefined4 param_6,undefined4 param_7);
void proc_7F025560(int param_1,uint param_2,undefined4 param_3);
void proc_7F0256F0(int param_1,uint param_2,undefined4 param_3);
void proc_7F02587C(int param_1,longlong param_2);
void proc_7F025C40(void);
void proc_7F026130(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5);
void proc_7F02624C(float *param_1,float *param_2,float *param_3);
void proc_7F026298(float *param_1,float *param_2,float *param_3);
float proc_7F026364(int param_1,float param_2,float param_3,float param_4,float param_5,undefined4 param_6);
undefined proc_7F0264B0(int param_1,float param_2,float param_3);
void proc_7F026508(void);
undefined4 proc_7F026F30(void);
void proc_7F027060(int param_1);
undefined8 proc_7F02727C(void);
undefined8 proc_7F027804(void);
int * proc_7F027BF4(int param_1);
ulonglong proc_7F027C60(int param_1);
float proc_7F027C84(float *param_1,int *param_2);
int * proc_7F027CD4(float *param_1,undefined4 param_2);
void proc_7F027DB0(int param_1,float *param_2,int param_3);
void proc_7F027E70(int param_1,float *param_2);
void proc_7F027E90(int param_1,undefined *param_2,float *param_3);
void proc_7F027F20(int param_1,undefined4 *param_2,undefined4 *param_3);
float proc_7F027FA8(int param_1);
int proc_7F028144(int param_1);
void proc_7F0281F4(int param_1);
void proc_7F0281FC(int param_1);
void proc_7F02828C(int param_1);
void proc_7F0282E0(int param_1);
int proc_7F028348(int param_1,int *param_2,int param_3);
int proc_7F0283FC(int param_1,int param_2);
int proc_7F028474(int param_1);
void proc_7F028494(int param_1);
void proc_7F0284DC(int param_1);
undefined8 proc_7F028510(float *param_1,int param_2);
void proc_7F028600(int param_1,undefined *param_2,float param_3,float *param_4,int param_5);
void proc_7F028894(int param_1,float *param_2);
void proc_7F028A5C(int param_1,int param_2,int param_3);
void proc_7F028DA0(int param_1);
undefined8 proc_7F028DDC(int param_1,float *param_2,undefined4 param_3,char param_4);
void proc_7F028FAC(int param_1);
void proc_7F0290F8(int param_1,int **param_2);
void proc_7F029298(int param_1);
undefined4 proc_7F0292A8(short *param_1,undefined4 *param_2,int param_3);
undefined4 proc_7F0294BC(int param_1);
undefined4 proc_7F0295D0(int param_1,undefined4 *param_2,int param_3);
undefined4 proc_7F02969C(void);
undefined4 proc_7F029760(int param_1);
undefined4 proc_7F02982C(int param_1,float *param_2,float *param_3);
undefined4 proc_7F029A94(int param_1,float *param_2,float param_3);
undefined4 proc_7F029AF0(int param_1,float *param_2);
void proc_7F029BB0(int param_1);
void proc_7F029C00(int param_1);
undefined8 proc_7F029C5C(void);
ulonglong proc_7F029D70(void);
void proc_7F02A044(int param_1,int param_2,float *param_3);
undefined4 proc_7F02A0EC(int param_1,int param_2,float param_3);
void proc_7F02A15C(int param_1,uint param_2,float *param_3,undefined4 param_4);
undefined4 proc_7F02A1E8(int param_1,uint param_2,float param_3);
undefined8 true_if_actor_is_dying_fading_limping_shot(GUARDdata *actor);
s32 true_if_actor_dying_fading(GUARDdata *chr);
undefined8 proc_7F02A2C8(void);
undefined8 proc_7F02A428(void);
undefined8 proc_7F02A588(int param_1);
undefined8 proc_7F02A704(int param_1);
undefined8 proc_7F02A7F8(int param_1);
ulonglong proc_7F02A8EC(int param_1);
undefined8 proc_7F02AA1C(int param_1,uint param_2,undefined4 param_3);
undefined8 proc_7F02AA88(int param_1,uint param_2,undefined4 param_3);
undefined8 proc_7F02AAF4(int param_1,undefined4 param_2,undefined4 param_3);
undefined8 proc_7F02AB44(int param_1,undefined4 param_2,undefined4 param_3);
undefined8 proc_7F02ABB4(int param_1,longlong param_2,char param_3);
undefined8 proc_7F02AD54(int param_1,longlong param_2);
void proc_7F02AD98(void);
void proc_7F02B4E0(int param_1);
void proc_7F02B4E8(void);
void proc_7F02B638(int param_1);
void proc_7F02B774(int param_1);
void proc_7F02B800(undefined2 *param_1,longlong param_2);
void proc_7F02B9A4(void);
void proc_7F02BC80(void);
void proc_7F02BD20(void);
void proc_7F02BDA4(void);
void proc_7F02BE00(void);
void proc_7F02BE58(void);
void proc_7F02BEA8(void);
void proc_7F02BF24(void);
void proc_7F02BFE4(int param_1,int param_2,int param_3);
float proc_7F02C190(void);
float proc_7F02C27C(int param_1);
undefined4 proc_7F02C2B0(void);
undefined4 proc_7F02C4C0(short *param_1,int param_2,int param_3,int param_4,float param_5);
void proc_7F02D048(int param_1,int param_2,longlong param_3,longlong param_4,float param_5);
void proc_7F02D0F8(int param_1);
void proc_7F02D118(int param_1,int param_2,undefined4 param_3);
longlong proc_7F02D148(int param_1,int param_2);
void proc_7F02D184(int param_1);
void proc_7F02D1C4(int param_1,longlong param_2,longlong param_3);
undefined4 proc_7F02D244(float param_1);
void proc_7F02D2E4(int param_1,uint *param_2,undefined4 *param_3,int param_4);
undefined8 proc_7F02D630(int param_1,int param_2,float *param_3);
void proc_7F02D734(short *param_1,int param_2);
void proc_7F02E26C(short *param_1);
undefined8 proc_7F02E2E0(void);
void proc_7F02E3B8(void);
void proc_7F02E4C0(void);
void proc_7F02EBFC(void);
void proc_7F02EEE0(void);
void proc_7F02F3F8(void);
void proc_7F02F5A4(void);
void proc_7F02F688(void);
uint proc_7F02F690(int param_1,float *param_2,int param_3,float *param_4);
void proc_7F02F888(void);
undefined8 proc_7F02FC34(float *param_1,float *param_2,float *param_3,float param_4);
undefined8 proc_7F02FD50(float *param_1,float *param_2,float *param_3,float param_4);
void proc_7F02FE78(void);
undefined4 proc_7F030128(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4,int param_5,undefined4 param_6);
undefined4 proc_7F0301FC(int param_1,float *param_2,u32 param_3,float *param_4,float param_5,float param_6);
undefined4 proc_7F0304AC(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4,undefined4 *param_5,int param_6,undefined4 param_7);
void proc_7F0305E0(int param_1,float *param_2,u32 param_3,float *param_4,float *param_5,float param_6,undefined4 param_7);
void proc_7F03074C(float *param_1,float *param_2,float *param_3);
undefined4 proc_7F03081C(int param_1,float *param_2,u32 param_3,float *param_4,float *param_5,float *param_6,float param_7,float param_8,undefined4 param_9);
undefined4 proc_7F030D70(int param_1,float *param_2,u32 param_3,float *param_4,float *param_5,float *param_6,float param_7,float param_8,undefined4 param_9);
ulonglong proc_7F03130C(int param_1,float *param_2,longlong param_3,float *param_4,float param_5,int param_6,undefined4 *param_7,int param_8,float param_9,int param_10,int param_11);
void proc_7F0315A4(int param_1,float *param_2,undefined8 param_3,char *param_4);
void proc_7F032088(void);
void proc_7F032548(int param_1);
void proc_7F0326BC(int param_1);
void proc_7F03291C(void);
undefined8 proc_7F032B68(int param_1);
undefined8 proc_7F032BA0(int param_1);
float proc_7F032BD8(void);
void proc_7F032C4C(undefined4 param_1);
int proc_7F032C78(short *param_1,ulonglong param_2,longlong param_3,undefined4 *param_4);
float proc_7F032D70(int param_1);
void proc_7F032DE4(int param_1);
void proc_7F032E48(int param_1,short param_2);
ulonglong proc_7F032EFC(int param_1,short param_2);
short proc_7F032F94(int param_1,short param_2);
longlong proc_7F032FAC(short *param_1,longlong param_2);
int proc_7F033040(short *param_1,longlong param_2);
float proc_7F0330C4(short *param_1,longlong param_2);
void proc_7F033154(int param_1,short param_2);
void proc_7F033218(int param_1,byte param_2);
void proc_7F03322C(int param_1,byte param_2);
ulonglong proc_7F033244(int param_1,byte param_2);
void proc_7F033260(short *param_1,longlong param_2,byte param_3);
void proc_7F033290(short *param_1,longlong param_2,byte param_3);
ulonglong proc_7F0332C0(short *param_1,longlong param_2,byte param_3);
void proc_7F0332FC(undefined8 param_1,uint param_2);
void proc_7F033318(undefined8 param_1,uint param_2);
ulonglong proc_7F033338(undefined8 param_1,uint param_2);
ulonglong proc_7F033354(int param_1);
ulonglong proc_7F033364(int param_1);
undefined8 proc_7F0333A0(int param_1);
void proc_7F0333C4(int param_1);
float proc_7F0333D8(int param_1);
ulonglong proc_7F0333F8(int param_1);
ulonglong proc_7F033490(int param_1);
undefined8 proc_7F0334A0(int param_1,char param_2);
undefined8 proc_7F03350C(short *param_1,int param_2,char param_3);
undefined proc_7F0335A4(int param_1);
undefined proc_7F0335AC(int param_1);
ulonglong proc_7F0335B4(int param_1);
ulonglong proc_7F0335C4(int param_1);
ulonglong proc_7F0335D4(int param_1);
ulonglong proc_7F033610(int param_1);
ulonglong proc_7F03364C(int param_1);
ulonglong proc_7F033688(int param_1);
ulonglong proc_7F0336C4(int param_1);
ulonglong proc_7F033700(int param_1,int param_2,int param_3,int param_4,byte param_5,int param_6);
void proc_7F033760(void);
undefined8 proc_7F033780(int *param_1,float *param_2,float param_3);
longlong proc_7F033834(float *param_1,undefined4 param_2,float param_3,char param_4);
undefined8 proc_7F033998(void);
ulonglong proc_7F033AAC(int param_1,ulonglong param_2);
undefined8 proc_7F033B38(undefined2 *param_1,float param_2);
void proc_7F033CF4(short *param_1,longlong param_2);
void proc_7F033D1C(short *param_1,longlong param_2,int param_3);
void proc_7F033D5C(int param_1,short param_2);
void proc_7F033D84(short *param_1,longlong param_2,short param_3);
undefined8 proc_7F033DC4(int param_1);
longlong proc_7F033EAC(float *param_1,int param_2);
undefined8 proc_7F033F48(float *param_1,int *param_2,float param_3,longlong param_4);
longlong proc_7F03415C(int param_1,uint param_2,float *param_3,int param_4,float param_5,int param_6,uint param_7);
void proc_7F034258(int param_1,int param_2,uint param_3,short param_4,uint param_5,uint param_6);
undefined8 proc_7F034308(void);
undefined8 proc_7F034388(short *param_1,longlong param_2,short param_3);
undefined8 proc_7F03444C(int param_1,short param_2);
undefined8 proc_7F0344FC(void);
undefined8 proc_7F034508(void);
undefined8 proc_7F034514(int param_1,short param_2);
undefined8 proc_7F03457C(void);
undefined8 proc_7F0346FC(int param_1,int param_2,char param_3);
void proc_7F0347A0(int param_1);
void loop_set_sound_effect_all_slots(void);
int ** proc_7F034924(longlong param_1,short param_2);
void proc_7F0349BC(longlong param_1);
int get_length_of_action_block(int param_1,int param_2);
undefined * proc_7F035244(undefined *param_1,undefined4 *param_2);
int proc_7F0352F0(undefined *param_1,int param_2,char param_3);
undefined * proc_7F035398(undefined *param_1);
int * get_ptr_path_for_pathnum(ulonglong pathnum);
void proc_7F03A240(void);
void set_stateflag_0x04_for_posdata(int param_1);
void unset_stateflag_0x04_for_posdata(int param_1);
object_standard * get_ptr_obj_pos_list_current_entry(void);
object_standard * remove_last_obj_pos_data_entry(void);
void set_last_obj_pos_data(object_standard *param_1);
void set_current_objposdata_plus_0x28(object_standard *param_1);
void proc_7F03A4F0(int param_1);
void proc_7F03A538(int param_1);
void proc_7F03A5A4(int param_1,int param_2);
void proc_7F03A5D0(int param_1);
undefined8 proc_7F03A62C(undefined8 param_1,char *param_2,longlong param_3);
longlong proc_7F03A6F4(longlong param_1,uint param_2,longlong param_3);
undefined8 proc_7F03A97C(int param_1,float *param_2,float *param_3);
void proc_7F03AA44(void);
uint proc_7F03AB58(void);
ulonglong proc_7F03ADF4(byte param_1,float *param_2,float *param_3,float *param_4,float *param_5,int param_6,float *param_7);
int proc_7F03AF5C(void);
void proc_7F03B15C(undefined8 param_1);
void proc_7F03B9C0(int param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,undefined4 *param_6,undefined4 *param_7,undefined4 param_8,undefined4 param_9,int param_10,int param_11);
void proc_7F03BDEC(undefined4 param_1,longlong param_2);
void proc_7F03C0F0(undefined8 param_1);
void proc_7F03C294(void);
void proc_7F03C2BC(char *param_1,longlong param_2);
undefined4 proc_7F03C3FC(void);
undefined8 proc_7F03C4F0(void);
undefined4 proc_7F03C574(int param_1);
void handle_mp_respawn_and_some_things(void);
void determing_type_of_object_and_detection(void);
void proc_7F03CB8C(char *param_1,uint *param_2);
void proc_7F03CC20(char *param_1,int **param_2,undefined4 *param_3,float *param_4,float *param_5);
void proc_7F03CCB0(char *param_1,int **param_2,undefined4 *param_3);
undefined8 proc_7F03CCD8(float *param_1,float *param_2,uint param_3);
void proc_7F03CF88(char *param_1,undefined4 *param_2,float *param_3,undefined4 *param_4);
ulonglong proc_7F03CFE8(byte *param_1);
void proc_7F03D058(char *param_1,longlong param_2);
void proc_7F03D0D4(void);
float proc_7F03D188(void);
void proc_7F03D78C(void);
ulonglong proc_7F03D9EC(int param_1);
undefined4 proc_7F03DA50(char *param_1,uint param_2);
undefined8 proc_7F03DB70(int *param_1,int *param_2);
undefined8 proc_7F03DBCC(short param_1,int param_2);
int proc_7F03DCB8(int param_1,longlong param_2);
void proc_7F03DD9C(int param_1,short param_2);
void proc_7F03DE94(int param_1,short param_2);
void proc_7F03E134(char *param_1);
void proc_7F03E18C(int param_1);
void proc_7F03E210(int param_1);
void proc_7F03E27C(char *param_1,float *param_2,float *param_3,float param_4);
void proc_7F03E3FC(int *param_1);
void proc_7F03E4F0(void);
void removed_debug_roomblocks_feature(void);
void proc_7F03E6A0(int param_1);
undefined8 proc_7F03E718(int param_1);
undefined8 proc_7F03E7AC(int param_1);
void proc_7F03E830(int param_1);
undefined4 proc_7F03E85C(int param_1);
undefined4 proc_7F03E864(int param_1);
undefined4 proc_7F03E86C(int param_1);
undefined4 proc_7F03E874(int param_1);
float proc_7F03E87C(int param_1,float *param_2);
float proc_7F03E91C(int param_1,float *param_2);
float proc_7F03E9BC(int param_1,int param_2);
float proc_7F03EA5C(int param_1,int param_2);
float proc_7F03EAFC(int param_1,int param_2);
float proc_7F03EB9C(int param_1,int param_2);
void proc_7F03EC3C(int param_1,int param_2,undefined4 *param_3);
void proc_7F03ECC0(float param_1,undefined8 param_2,undefined8 param_3,float param_4,undefined8 param_5,float param_6,float param_7,float *param_8,float *param_9,uint *param_10);
void proc_7F03F540(undefined8 param_1,undefined8 param_2,float *param_3,uint *param_4);
undefined8 proc_7F03F598(float *param_1,float param_2,float *param_3);
void proc_7F03F748(int param_1,float *param_2,float *param_3,longlong param_4);
void proc_7F03F90C(int param_1,float *param_2,float *param_3,float *param_4,float *param_5);
void proc_7F03F948(float *param_1,float *param_2,undefined4 *param_3,float *param_4,float *param_5);
int scan_position_data_table_for_normal_object_at_preset(short param_1);
undefined4 proc_7F03FAB0(float *param_1,ulonglong param_2);
void proc_7F03FB70(uint *param_1);
void proc_7F03FBFC(undefined4 *param_1);
undefined4 * proc_7F03FC80(void);
void proc_7F03FDA8(int param_1);
void proc_7F03FE14(int param_1);
void proc_7F03FE88(uint *param_1);
int proc_7F03FE98(void);
int proc_7F03FF60(int param_1);
int do_something_if_object_destroyed(int param_1);
undefined4 proc_7F03FFF8(int *param_1);
undefined4 proc_7F040078(int param_1);
void proc_7F04009C(int param_1,byte *param_2);
void proc_7F0402B4(int param_1,byte *param_2);
void proc_7F040310(byte *param_1,byte *param_2);
void proc_7F040384(int *param_1,longlong param_2,float *param_3);
void proc_7F040484(int param_1);
undefined *init_standard_object(object_standard *objdata,object_header *modelheader,object_standard *targetposdata,uint controller);
undefined * init_object_no_default_pos_controller(object_standard *object,object_header *header);
undefined * proc_7F04071C(int param_1);
void proc_7F040754(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4);
void proc_7F0407F4(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4);
void proc_7F04088C(void);
void proc_7F040BA0(void);
void proc_7F040CF0(int param_1);
void proc_7F040D98(object_standard *param_1,int param_2,longlong param_3);
void proc_7F041024(object_standard *param_1,int param_2);
undefined4 proc_7F041044(int param_1);
undefined8 proc_7F041074(float *param_1,float *param_2,float *param_3,float param_4);
undefined8 proc_7F041160(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,int *param_6,ushort **param_7);
undefined8 proc_7F041400(char *param_1,float *param_2,float *param_3,float *param_4,float *param_5,float *param_6,float *param_7);
ulonglong proc_7F0417DC(int param_1,float *param_2,float *param_3,float *param_4,float param_5,float *param_6,float *param_7,float *param_8,float *param_9,float *param_10,int *param_11,ushort **param_12);
undefined8 proc_7F0419E4(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,float param_5,float *param_6,float *param_7,float *param_8,float *param_9,float *param_10);
undefined8 proc_7F041BB8(int param_1,float *param_2,float *param_3,float param_4,float *param_5,float *param_6,float *param_7,float *param_8,float *param_9);
longlong proc_7F041E0C(char *param_1,undefined8 param_2,float *param_3,ulonglong param_4,float *param_5,float *param_6,int *param_7);
int handles_projectile_motion(int param_1,float *param_2,float *param_3,float *param_4,int param_5,int param_6);
undefined4 proc_7F042A0C(void);
int proc_7F042EB4(int param_1,float *param_2,float *param_3,float *param_4,int param_5,int param_6);
void proc_7F042F18(float *param_1,float param_2,float *param_3,float param_4,float param_5,float param_6);
void proc_7F04310C(float *param_1,float param_2,float *param_3,float param_4,float param_5,float param_6);
void proc_7F0431E4(int param_1,float *param_2);
void proc_7F043650(int param_1);
void proc_7F043838(float *param_1,int param_2);
void proc_7F0439B8(void);
undefined8 proc_7F043A6C(int param_1,int param_2,int param_3,ushort *param_4);
void generate_explosion_at_position(object_header *object,uint param_2,undefined8 param_3,undefined4 param_4);
void handle_thrown_explosive_detonation(object_header *param_1);
void proc_7F044200(int param_1);
void proc_7F04424C(object_header *param_1);
void proc_7F0442DC(object_header *param_1);
undefined8 proc_7F044414(float *param_1,int param_2,float *param_3,uint param_4);
undefined8 proc_7F0446B8(float *param_1,uint param_2,float *param_3,uint param_4);
undefined8 proc_7F044718(undefined8 param_1,undefined8 param_2,float *param_3,int param_4);
undefined8 proc_7F0448A8(void);
int proc_7F044B38(undefined8 param_1);
int proc_7F0451DC(float *param_1,float param_2,float param_3,float param_4);
undefined4 * proc_7F049B58(undefined4 *param_1);
void set_ptr_monitor_img_to_obj_ani_slot(undefined4 *slot,undefined4 image);
void set_ptr_monitor_img_to_obj_ani_slot(undefined4 *param_1,undefined4 param_2);
void save_img_index_to_obj_ani_slot(int slot,undefined4 index);
uint * process_monitor_animation_microcode(void);
void proc_7F04AC20(int param_1,int param_2,uint param_3);
longlong proc_7F04B150(char *param_1,uint *param_2,uint param_3);
ushort * proc_7F04B478(int param_1);
undefined8 proc_7F04B590(int param_1,int param_2);
void proc_7F04B610(int param_1,int param_2);
void proc_7F04BCDC(int param_1,float *param_2);
void proc_7F04BFD0(int param_1,undefined4 param_2);
void proc_7F04C044(int param_1);
undefined8 proc_7F04C130(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F04CA44(int param_1,undefined8 param_2);
void proc_7F04CD04(object_header *param_1,undefined8 param_2);
void object_explosion_related(object_standard *param_1,float *param_2,int param_3);
undefined4 proc_7F04D16C(float *param_1,float *param_2,float *param_3,uint *param_4,uint *param_5,int param_6,float *param_7);
int proc_7F04D9B0(int param_1,ushort *param_2,float *param_3,float *param_4,float *param_5,int *param_6,ushort **param_7);
void proc_7F04DCB4(object_standard *param_1);
void proc_7F04DD68(object_standard *param_1);
void proc_7F04DE18(object_standard *param_1);
void proc_7F04DEFC(int param_1,float param_2,undefined8 param_3,undefined8 param_4,int param_5);
undefined8 check_if_destroyable_object_type(int param_1);
undefined8 check_if_collectable_object(int objdata);
undefined8 check_if_destroyable_not_invincible(int object);
void proc_7F04E0CC(int param_1,float param_2,float *param_3,int param_4,int param_5);
void maybe_detonate_object(object_standard *objdata,float param_2,float *param_3,int param_4,int param_5);
void proc_7F04E720(object_standard *param_1,float *param_2);
void proc_7F04E9BC(object_standard *param_1,float *param_2);
void proc_7F04EA68(float *param_1,float *param_2);
ulonglong check_if_object_has_not_been_destroyed(int param_1);
undefined8 proc_7F04EF58(int param_1);
undefined4 proc_7F04F170(char *param_1);
void proc_7F04F218(int param_1,longlong param_2);
void proc_7F04F244(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5);
void append_text_picked_up(u8 *buffer,u8 *param_2,u8 *param_3);
void append_text_ammo_amount_word(u8 *buffer,AMMOTYPES ammotype,u32 amount);
void apped_text_ammotype(u8 *buffer,AMMOTYPES ammotype,u32 amount);
void set_sound_effect_for_ammo_collection(AMMOTYPES ammotype);
void set_sound_effect_for_weapontype_collection(ITEM_IDS weapontype);
void prepare_ammo_type_collection_text(u8 *finaltext,AMMOTYPES ammotype,u32 quantity);
void display_text_when_ammo_collected(AMMOTYPES ammotype,u32 amount);
void add_ammo_to_inventory(AMMOTYPES ammotype,int amount,int doplaysound,int dodisplaytext);
uint get_ammo_in_magazine(int objdata);
uint ammo_collected_from_weapon(void *objdata);
void generate_language_specific_text_for_weapon(char *finalstring,ITEM_IDS itemtype);
void display_text_for_weapon_in_lower_left_corner(ITEM_IDS weaponid);
undefined8 collect_or_interact_object(char *param_1,int param_2);
void object_collectability_routine(object_standard *param_1);
undefined8 proc_7F050D30(int param_1,undefined4 *param_2,float *param_3,float *param_4);
void proc_7F050DE8(int param_1);
undefined *proc_7F050F50(ushort *param_1,int param_2,ushort **param_3,undefined *param_4,uint param_5);
void proc_7F051028(ushort *param_1,int param_2);
void proc_7F051084(ushort *param_1,int param_2);
void proc_7F0510C0(undefined2 *param_1,int item,uint param_3);
int proc_7F05126C(int param_1,longlong param_2,int param_3);
int proc_7F051588(void);
int proc_7F0515B0(longlong param_1,longlong param_2,int param_3);
int proc_7F0518A8(void);
object_standard * proc_7F0518D0(void);
void trigger_remote_mine_detonation(void);
int check_if_entry_is_collectable(char type,char *objposdata);
int check_if_item_deposited(char item);
void add_obj_to_temp_proxmine_table(undefined4 *objdata);
void remove_obj_from_temp_proxmine_table(undefined4 *objdata);
void detonate_proxmine_within_range(xyzpoint *xyzpos);
void check_guard_detonate_proxmine(void);
void link_objects(int *objdata1,int *objdata2);
undefined *complete_object_data_block_return_position_entry(int *objdata,int *modelheader,int *targetposdata,int controller);
undefined * proc_7F051DD8(int param_1,ushort **param_2);
undefined8 proc_7F051E1C(int param_1,int param_2);
undefined *proc_7F051F30(ushort *param_1,int param_2,ushort **param_3,undefined *param_4,uint param_5);
undefined * proc_7F051FD4(ushort *param_1,int param_2);
undefined * proc_7F052030(ushort *param_1,int param_2);
undefined4 * create_new_item_instance_of_model(int model,int iteminstance);
void set_0x4_in_runtime_flags_for_item_in_guards_hand(int *GUARDdata,int hand);
undefined *create_held_weapon(undefined2 *param_1,int param_2,undefined param_3,uint param_4,undefined4 *param_5,ushort **param_6);
undefined *actor_draws_weapon_with_model(undefined2 *param_1,int param_2,undefined param_3,uint param_4);
void proc_7F0523F8(int param_1,int param_2,int **param_3);
void redirect_object_collectability_routines(void);
void proc_7F052574(int param_1,undefined4 param_2);
longlong proc_7F052604(int param_1);
undefined8 get_hat_model(int param_1);
void proc_7F0526EC(int param_1,float *param_2);
void proc_7F052B00(int param_1);
void proc_7F052D8C(int param_1);
void proc_7F053598(int param_1);
void proc_7F0535C4(int param_1);
undefined *initialize_door(int *stdobject,int *xyzpos,int matrix,int *tile,int param_5,int *runtimexyzpos);
int proc_7F0537B8(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5);
int proc_7F053894(float *param_1,float param_2,float param_3);
void proc_7F05396C(int param_1,float *param_2,float param_3,float param_4);
int proc_7F0539B8(float param_1,undefined8 param_2,undefined8 param_3);
void proc_7F0539E4(float *param_1);
void sub_GAME_7F053A10(int param_1,float *param_2);
void proc_7F053A3C(void);
void proc_7F053B10(int param_1);
void play_door_opening_soundeffect_0(int param_1);
void play_door_opening_soundeffect_(int param_1);
void play_door_closing_soundeffect_0(int param_1);
void play_door_closing_soundeffect_1(int param_1);
void set_door_state(int *objdata,DOORSTATE state);
void proc_7F0547DC(int param_1);
void proc_7F05480C(int param_1);
void proc_7F05487C(int param_1);
void proc_7F0548A4(int param_1,int param_2);
void proc_7F054988(int param_1,longlong param_2);
ulonglong proc_7F054A20(int param_1);
longlong proc_7F054A64(char *param_1,float *param_2);
int proc_7F054B80(int param_1);
undefined4 proc_7F054C58(void);
uint proc_7F054D6C(char *param_1,float *param_2,float param_3,int param_4);
undefined8 proc_7F054EA8(int param_1);
void proc_7F054FB4(int param_1);
void proc_7F05522C(int param_1,float *param_2,float *param_3,int param_4);
undefined4 proc_7F0555F8(int param_1,int param_2);
int proc_7F055804(char *param_1);
void proc_7F05599C(int param_1);
undefined8 proc_7F055A70(int param_1,int param_2);
void proc_7F055B78(int param_1,int param_2);
undefined8 proc_7F055C40(int param_1);
void start_alarm(void);
void deactivate_alarm_sound_effect(void);
void stop_alarm(void);
s32 is_alarm_on(void);
void init_trigger_toxic_gas_effect(undefined4 *param_1);
void proc_7F055EF8(void);
u32 check_if_toxic_gas_activated(void);
void handle_gas_damage(void);
void set_unset_clock_lock_bits(int clocklockbits,int flag);
u32 is_clock_drawn_onscreen(void);
void set_clock_time(f32 time);
f32 get_clock_time(void);
void set_clock_enable(int enable);
undefined4 get_clock_enable(void);
void if_enabled_reset_clock(void);
undefined4 * proc_7F056210(undefined4 *param_1);
void handle_alarm_gas_timer_calldamage(void);
void proc_7F056690(void);
void drop_inventory(void);
undefined8 proc_7F056850(undefined4 *param_1,longlong param_2,float param_3,undefined4 *param_4,undefined4 *param_5);
u32 get_size_of_setup_object_type(u8 *object);
int proc_7F056A88(int param_1);
int proc_7F056B1C(object_standard *param_1);
int proc_7F056BA8(int param_1);
u32 load_model(int modelid);
void proc_7F056CA0(int param_1);
int proc_7F056EA0(undefined8 param_1,int param_2);
int proc_7F056F08(ulonglong param_1,int *param_2,int *param_3,longlong param_4,int param_5,int param_6);
int proc_7F057080(short param_1);
int get_handle_to_tagged_object(int object);
char * get_ptr_text_for_watch_breifing_page(WATCH_BRIEFING_PAGE page);
u32 add_objective(void);
u8 * get_text_for_objective(int objective);
DIFFICULTY get_difficulty_for_objective(int objective);
int get_status_of_objective(s32 objective);
u32 check_objectives_complete(void);
void display_objective_status_text_on_status_change(void);
void proc_7F057744(ulonglong param_1);
void proc_7F0577E8(int param_1,ulonglong param_2);
void objectiveHandlePhotograph(void);
void proc_7F057AC0(float *param_1);
void proc_7F057C14(float *param_1,float *param_2);
void proc_7F057D44(float *param_1,float *param_2,float param_3);
void proc_7F057D88(float *param_1,float *param_2,float param_3);
void sub_GAME_7F057DF8(float *param_1,float *param_2,int param_3);
void proc_7F057E58(float *param_1,float *param_2,float *param_3,float *param_4,int param_5);
float cosf(float __x);
float sinf(float __x);
void guMtxIdentF_unrolled(float (*param_1) [4] [4]);
void proc_7F058020(float (*param_1) [4] [4],float (*param_2) [4]);
void proc_7F058068(float *param_1,float *param_2);
void sub_GAME_7F058098(float *param_1,float *param_2);
void proc_7F0580C8(float *param_1,float *param_2,int param_3);
void proc_7F05818C(float *param_1,float *param_2,int param_3);
void proc_7F058274(float *param_1,float *param_2,float *param_3);
void proc_7F058380(float *param_1,float *param_2,float *param_3);
void proc_7F0583D8(float *param_1,float *param_2);
void proc_7F058418(float *param_1,float *param_2,float *param_3);
void proc_7F058474(float *param_1,float *param_2);
void proc_7F0584D0(float *param_1,float param_2,float *param_3);
void proc_7F058570(float param_1,undefined8 param_2,undefined4 *param_3);
void proc_7F0585FC(float param_1,undefined8 param_2,float *param_3);
void proc_7F058688(float param_1,undefined8 param_2,float *param_3);
void proc_7F058714(float *param_1,float *param_2);
void proc_7F058860(float *param_1,float *param_2);
void proc_7F05892C(undefined4 *param_1,float *param_2,float *param_3);
void init_something_copy_posdata_to_it(xyzpoint *posdata,int *dest);
void copies_first_3_floats_from_a0_to_a1_plus_0x30(xyzpoint *posdata,int dest);
void proc_7F0589B4(float param_1,undefined8 param_2,float *param_3);
void proc_7F0589E4(float param_1,undefined8 param_2,int param_3);
void proc_7F058A14(float param_1,undefined8 param_2,int param_3);
void proc_7F058A4C(float param_1,undefined8 param_2,int param_3);
void matrix_multiply_A1_by_F12(float param_1,undefined8 param_2,float *param_3);
void proc_7F058B10(float param_1,undefined8 param_2,float *param_3);
void proc_7F058B80(float param_1,undefined8 param_2,int param_3);
void proc_7F058BB8(float param_1,undefined8 param_2,float *param_3);
void proc_7F058C4C(float param_1);
void proc_7F058C64(void);
void proc_7F058C88(void);
void proc_7F058C9C(int param_1,uint *param_2);
void proc_7F058E78(uint *param_1,int param_2);
void proc_7F059044(float *param_1,int *param_2);
void proc_7F05914C(int *param_1,float *param_2);
void proc_7F059244(int param_1,uint *param_2);
void proc_7F059334(uint *param_1,int param_2);
void proc_7F059424(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10);
void proc_7F059694(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10);
void proc_7F059708(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10);
void proc_7F059908(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10);
uint proc_7F05997C(float param_1,float param_2);
void proc_7F059A48(float *param_1,undefined2 *param_2,float param_3,float param_4,float param_5,float param_6,float param_7);
void proc_7F059B58(float *param_1,float a,float x,float y,float z);
void proc_7F059CE8(float *param_1,float param_2,float param_3,float param_4,float param_5);
void proc_7F059D30(void);
void proc_7F059D38(undefined4 *param_1,undefined4 *param_2);
void proc_7F059DAC(float *param_1,float *param_2);
void proc_7F059E64(float *param_1,float *param_2);
void proc_7F059FB8(float *param_1,float *param_2);
void proc_7F05A250(undefined8 param_1,undefined8 param_2);
void proc_7F05A310(undefined8 param_1,undefined8 param_2);
float proc_7F05A774(undefined8 param_1,undefined8 param_2);
float proc_7F05A928(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10,float param_11);
float proc_7F05A9B8(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6);
void proc_7F05A9E0(float param_1);
float convert_angle_using_inverse(f32 vector1,f32 vector2);
int proc_7F05AB70(uint param_1);
uint proc_7F05ABF0(short param_1);
short proc_7F05AC44(short param_1);
float proc_7F05ACB0(float param_1);
float proc_7F05AD5C(float param_1);
void proc_7F05AE00(float *param_1,float *param_2,float param_3,float *param_4);
float proc_7F05AE50(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7);
void proc_7F05AEFC(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float *param_6);
void proc_7F05B024(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float param_6,float *param_7);
float proc_7F05B154(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7);
void proc_7F05B1D4(ushort *param_1,float *param_2);
void proc_7F05B3F4(float *param_1,float *param_2);
void proc_7F05B528(float param_1,undefined8 param_2,float *param_3);
void proc_7F05B57C(float param_1,undefined8 param_2,float *param_3);
void proc_7F05B5D4(float param_1,undefined8 param_2,float *param_3);
void proc_7F05B628(float *param_1,float *param_2);
void proc_7F05B798(float *param_1,float *param_2);
void proc_7F05B9B4(float *param_1,float *param_2,float *param_3);
void proc_7F05BA08(float *param_1,float *param_2,float param_3,float *param_4);
void proc_7F05BC68(float *param_1,float param_2,float *param_3);
void proc_7F05BE10(float *param_1,float *param_2);
void proc_7F05BE88(float *param_1,float *param_2,float *param_3);
void proc_7F05BF8C(float *param_1,float *param_2);
void proc_7F05BFD4(float *param_1,undefined4 *param_2);
void proc_7F05C068(int param_1,float *param_2);
void proc_7F05C138(float *param_1,float *param_2,float *param_3,float *param_4);
void proc_7F05C250(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float *param_6);
void proc_7F05C2F0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float *param_6);
float truncf(float __x);
int proc_7F05C3D8(float param_1);
float proc_7F05C440(float param_1);
int proc_7F05C4B8(float param_1);
void set_cartridges_eject(u32 param_1);
undefined4 get_cartridges_eject(void);
void nullsub_73(void);
void proc_7F05C540(float *param_1);
void proc_7F05C594(float *param_1);
void proc_7F05C614(void);
void proc_7F05C6B8(void);
undefined8 proc_7F05C6FC(int param_1,float param_2,float *param_3,int param_4);
weapon_stats * get_ptr_item_statistics(ITEM_IDS item);
void copy_item_in_hand(xyzpoint *param_1);
void copy_item_in_hand_to_main_list(undefined4 *param_1);
void unknown_takes_playerhand(int hand);
ulonglong proc_7F05CEBC(int param_1);
ITEM_IDS get_itemtype_in_hand(HAND hand);
Gitemheader * get_ptr_itemheader_in_hand(HAND hand);
u8 * getPlayerWeaponBufferForHand(HAND hand);
u32 getSizeBufferWeaponInHand(HAND param_1);
void remove_item_in_hand(HAND hand);
void place_item_in_hand_swap_and_make_visible(HAND hand,ITEM_IDS item);
char * get_ptr_item_text_call_line(int item);
Gitemheader * get_ptr_weapon_model_header_line(int weapon);
int getCurrentWeaponOrItem(void);
void used_to_load_1st_person_model_on_demand(int param_1);
longlong proc_7F05D334(longlong param_1,int param_2);
ITEM_IDS get_next_weapon_in_cycle_for_hand(HAND hand,s32 direction);
void likely_change_weapon_in_hand(HAND hand,int weapon,s32 direction);
void proc_7F05D610(int param_1);
void proc_7F05D650(int param_1);
void proc_7F05D690(void);
void advance_through_inventory(void);
void backstep_through_inventory(void);
void autoadvance_on_deplete_all_ammo(void);
void draw_item_in_hand_has_more_ammo(HAND hand,ITEM_IDS item);
void attempt_reload_item_in_hand(int hand);
ITEM_IDS get_item_in_hand(int hand);
void draw_item_in_hand(int param_1,int param_2);
ITEM_IDS return_ammo_in_hand(HAND hand);
void proc_7F05DA8C(int param_1,int param_2);
void proc_7F05DAE4(int param_1);
void remove_hands_item(HAND param_1,int param_2);
undefined get_hands_firing_status(int hand);
f32 proc_7F05DCB8(int param_1);
f32 proc_7F05DCE8(longlong param_1);
weapon_stats * proc_7F05DD38(void);
void camera_sniper_zoom(float zoom);
void proc_7F05DE94(float param_1);
weapon_stats * proc_7F05DF84(int param_1);
weapon_stats * proc_7F05DFA8(int param_1);
undefined proc_7F05DFCC(int param_1);
ulonglong proc_7F05DFF0(int param_1);
ulonglong proc_7F05E014(int param_1);
ulonglong proc_7F05E038(int param_1);
BOOL check_if_have_ammo_for_item(int item);
uint check_special_attributes(int item,uint mask);
void proc_7F05E0E4(void);
void proc_7F05E5F0(float param_1);
ITEM_IDS get_value_if_watch_is_on_hand_or_not(int hand);
int * proc_7F05E6B4(void);
void proc_7F05E808(int param_1);
void proc_7F05E83C(int param_1);
void proc_7F05E978(int param_1,undefined4 param_2);
void proc_7F05EA94(int param_1,undefined4 param_2);
void proc_7F05EB0C(int param_1,undefined4 *param_2,undefined4 param_3,float *param_4,undefined4 *param_5,undefined4 *param_6,undefined4 param_7);
void proc_7F05EC1C(void);
void proc_7F05EE24(int param_1);
void proc_7F05F09C(int param_1);
void generate_player_thrown_object(int param_1);
void proc_7F05F73C(int param_1);
void proc_7F05F928(int param_1);
void proc_7F05FA7C(int param_1);
void proc_7F05FB00(int param_1);
int ** proc_7F05FB64(int param_1);
void handles_firing_or_throwing_weapon_in_hand(HAND hand);
void proc_7F061920(void);
void proc_7F061948(undefined *param_1,int param_2,float *param_3,float *param_4);
void proc_7F061BF4(int param_1);
undefined4 * proc_7F061E18(undefined4 *param_1,char *param_2,int param_3);
void proc_7F062B00(char *param_1);
void proc_7F062BE4(undefined4 *param_1);
undefined4 *set_enviro_fog_for_items_in_solo_watch_menu(undefined4 *DL,longlong param_2,float *buffer,int param_4,int rgba);
undefined4 * proc_7F0634D8(undefined4 *param_1,longlong param_2,float *param_3,int param_4);
undefined4 * proc_7F0634FC(undefined4 *param_1,longlong param_2,float *param_3);
void proc_7F06351C(undefined4 *param_1,float *param_2,float *param_3,float *param_4,undefined4 *param_5,float *param_6,float *param_7);
undefined4 proc_7F06359C(undefined4 param_1,float *param_2,longlong param_3,longlong param_4,int param_5,char *param_6);
undefined4 proc_7F064364(undefined4 param_1,float *param_2,longlong param_3,int param_4,char *param_5);
undefined4 * proc_7F0643A0(void);
void recall_joy2_hits_edit_detail_edit_flag(void);
void proc_7F064720(float *param_1);
void recall_joy2_hits_edit_flag(int param_1,float *param_2,int param_3);
void proc_7F064934(longlong param_1);
undefined4 proc_7F0649AC(longlong param_1);
void proc_7F0649D8(int param_1);
void proc_7F066E64(void);
int get_keyanalyzer_flag(void);
void proc_7F066F08(void);
f32 get_vertical_position_solo_watch_menu_main_page_for_item(int item);
f32 get_lateral_position_solo_watch_menu_main_page_for_item(int item);
f32 get_depth_on_solo_watch_menu_page_for_item(int item);
f32 get_zrotation_solo_watch_menu_for_item(int item);
f32 get_xrotation_solo_watch_menu_for_item(int item);
f32 get_45_degree_angle(void);
int get_ptr_first_title_line_item(int item);
int get_ptr_second_title_line_item(int item);
int get_ptr_short_watch_text_for_item(int item);
int get_ptr_long_watch_text_for_item(int item);
f32 get_45_degree_angle_0(void);
f32 get_horizontal_offset_on_solo_watch_menu_for_item(int item);
f32 get_vertical_offset_on_solo_watch_menu_for_item(int item);
f32 get_depth_offset_solo_watch_menu_inventory_page_for_item(int item);
undefined4 proc_7F067174(int param_1);
void proc_7F0671A4(void);
ulonglong proc_7F0673B4(int param_1);
void proc_7F067420(int param_1);
void proc_7F067AA4(int param_1);
void proc_7F067AB4(void);
void proc_7F067B4C(undefined4 *param_1);
void caclulate_gun_crosshair_position_rotation(void);
void proc_7F067F58(undefined4 param_1,undefined4 param_2);
void proc_7F067FBC(undefined4 param_1,undefined4 param_2);
void proc_7F068008(undefined4 *param_1,undefined4 *param_2);
void proc_7F06802C(void);
void proc_7F0680D4(float *param_1);
void proc_7F068190(undefined4 *param_1,float *param_2);
void proc_7F0681CC(void);
undefined * proc_7F068420(undefined4 param_1,undefined4 *param_2);
void proc_7F068508(int param_1,undefined4 param_2);
void proc_7F068D20(float *param_1);
void proc_7F068E6C(void);
void proc_7F068EC4(int param_1,undefined4 *param_2);
void proc_7F06908C(undefined4 *param_1);
void set_unset_ammo_on_screen_setting(int flags,int isset);
void give_cur_player_ammo(AMMOTYPES type,int amount);
int check_cur_player_ammo_amount_in_inventory(AMMOTYPES type);
int check_cur_player_ammo_amount_total(int type);
int get_max_ammo_for_type(AMMOTYPES type);
void set_max_ammo_for_cur_player(void);
int get_ammo_in_hands_magazine(int hand);
int get_ammo_in_hands_weapon(int hand);
AMMOTYPES get_ammo_type_for_weapon(ITEM_IDS weapon);
int get_ammo_count_for_weapon(int weapon);
void add_ammo_to_weapon(int weapon,int ammo);
undefined4 get_max_ammo_for_weapon(int weapon);
undefined4 *microcode_generation_ammo_related(int *buffer,int *imagedeclaration,f32 hpos,f32 param_4,f32 vpos,f32 param_6,f32 voffset,int param_8,int red,int green,int blue,int alpha);
void set_rgba_redirect_generate_microcode(int *buffer,int *imagedeclaration,f32 param_3,f32 param_4,f32 hoffset,f32 param_6,f32 voffset,int param_8);
uint * proc_7F069A50(undefined4 *param_1,byte *param_2,uint param_3,int param_4,uint param_5,int param_6,int param_7);
uint * display_ammo_total_in_a1(undefined4 *param_1,undefined8 param_2,uint param_3,int param_4,uint param_5,int param_6,int param_7);
u32 * generate_ammo_total_microcode(void);
undefined4 * proc_7F06A334(undefined4 *param_1);
void set_unset_bitflags(int bitflags,int flag);
void proc_7F06A5E4(uint **param_1);
void inc_curplayer_hitcount_with_weapon(int weapon,int hitcount);
int get_curplayer_shot_register(int statsregister);
void inc_cur_civilian_casualties(void);
int get_civilian_casualties(void);
void increment_num_kills_display_text_in_MP(void);
int get_curplay_killcount(void);
void increment_num_times_killed_MwtGC(void);
int get_times_killed_mwtgx(void);
void increment_num_deaths(void);
int get_curplayer_numdeaths(void);
void increment_num_suicides_display_MP(void);
int get_curplayer_numsuicides(void);
void proc_7F06ABB0(int *DL,float *xypos,float *width,int height,int rotateleft90,int fliph,int flipv,int red);
void display_image_at_on_screen_coord(int *DL,int *xypos,f32 wdivh,int width,int height,int rotateleft90,int fliph,int flipv,int red,int green,int blue,int alpha,int format,int param_14);
int * proc_7F06B120(int *param_1,int param_2);
void proc_7F06B248(int param_1);
void proc_7F06B29C(int *param_1);
int proc_7F06BB28(int param_1);
void drawjointlist(int param_1,uint *param_2,undefined4 param_3,int param_4);
undefined4 probably_damage_detail_blood_effect_related(int **param_1,float *param_2,float *param_3,int *param_4,ushort **param_5);
undefined4 proc_7F06C010(int **param_1,float *param_2,float *param_3,int *param_4,ushort **param_5);
ulonglong proc_7F06C060(int param_1,int param_2);
uint get_obj_instance_controller_for_header(object_header *objheader);
void set_obj_instance_scale_to_zero(int *ptrobjinstance);
uint get_aircraft_obj_instance_controller(object_header *objheader);
void proc_7F06C3B4(int param_1,ushort *param_2,ushort **param_3);
void set_aircraft_obj_inst_scale_to_zero(int *objinstance);
void set_80036084(s32 param_1);
void set_flt_80036088(f32 param_1);
void proc_7F06C418(undefined4 *param_1,undefined4 *param_2);
void set_8003608C(undefined4 param_1);
void return_null(void);
void proc_7F06C474(int param_1,float *param_2,undefined4 param_3,undefined4 param_4);
void proc_7F06C550(int param_1,float *param_2,undefined4 param_3,undefined4 param_4);
undefined2 proc_7F06C570(ushort *param_1,longlong param_2);
int proc_7F06C660(int objinst,ushort *param_2,longlong param_3);
int getsubmatrix(int objinst,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F06C710(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4);
float proc_7F06C768(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);
int extract_id_from_object_structure_microcode(int objinst,ushort *partdesc);
void getpartoffset(longlong objinst,ushort *partdesc,undefined4 *param_3,undefined4 param_4);
void setpartoffset(longlong objinst,ushort *partedesc,float *param_3,undefined4 param_4);
void getsuboffset(int objinst,undefined4 *param_2,undefined4 param_3,undefined4 param_4);
void setsuboffset(int objinst,xyzpoint *param_2);
ushort ** getsubroty(int objinst,uint param_2,undefined4 param_3,undefined4 param_4);
void setsubroty(int objinst,float param_2,float param_3,undefined4 param_4);
void set_obj_instance_controller_scale(int instancecontroller,f32 scale);
void proc_7F06CE84(int param_1,undefined4 param_2);
float getjointsize(int objinst,ushort *param_2,undefined8 param_3,undefined4 param_4);
float getinstsize(int objinst,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F06D07C(float *param_1,float *param_2,float param_3);
float proc_7F06D0CC(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5);
void proc_7F06D160(undefined8 param_1,undefined8 param_2,float param_3);
uint proc_7F06D1CC(int param_1,int param_2,int param_3);
uint proc_7F06D2E4(int param_1,longlong param_2,int param_3,int param_4,int param_5,short *param_6);
float proc_7F06D3F4(int param_1,longlong param_2,int param_3,int param_4,int param_5,float *param_6);
void proc_7F06D490(int param_1,ushort *param_2);
void subcalcpos(int objanim,uint param_2,undefined4 param_3,undefined4 param_4);
void process_01_group_heading(float **param_1,int objinst,ushort *partdesc);
void proc_7F06D8B0(void);
void proc_7F06DB5C(float **param_1,int param_2,ushort *param_3,float *param_4);
uint proc_7F06DE04(int param_1,uint param_2,uint param_3);
void proc_7F06DEC0(int param_1,longlong param_2,int param_3,int param_4,int param_5,float *param_6);
void process_02_position(float **param_1,int param_2,ushort *param_3);
void proc_7F06E2B8(void);
float proc_7F06E540(int param_1,longlong param_2,int param_3,int param_4,int param_5);
void process_03_unknown(undefined4 param_1,int param_2,int param_3);
void process_15_subposition(float **param_1,int param_2,int param_3);
void process_08_distance_triggers(void);
void proc_7F06E970(int param_1,ushort *param_2);
void process_12_handle_switch(int param_1,ushort *param_2);
void process_17_pointer_to_head(int param_1,ushort *param_2);
void proc_7F06EA54(int param_1,longlong param_2);
void proc_7F06EB10(int param_1,ushort *param_2);
void process_09_head_hat_placement_interlink(int param_1,ushort *param_2);
void process_07_unknown(int param_1,ushort *param_2);
void proc_7F06EEA4(undefined8 param_1,int param_2);
void proc_7F06EFC4(int param_1);
void proc_7F06F0D0(float **param_1,int param_2);
void instcalcmatrices(float **param_1,uint param_2,undefined4 param_3,undefined4 param_4);
void subcalcmatrices(float **param_1,uint param_2,undefined4 param_3,undefined4 param_4);
undefined4 proc_7F06F5AC(int param_1);
undefined proc_7F06F5B4(int param_1);
undefined4 proc_7F06F5BC(int param_1);
float proc_7F06F5C4(int param_1);
undefined4 proc_7F06F610(int param_1);
float proc_7F06F618(int param_1);
undefined4 proc_7F06F640(int param_1);
longlong proc_7F06F66C(longlong param_1,int param_2,float param_3);
void proc_7F06F780(int param_1,float param_2);
void proc_7F06F878(int param_1,undefined4 param_2,undefined param_3,float param_4,float param_5,undefined4 param_6);
void proc_7F06FC4C(int param_1,undefined4 param_2,undefined param_3,float param_4,undefined4 param_5,float param_6,int param_7);
void proc_7F06FCA8(int param_1,undefined4 param_2,undefined param_3,float param_4,undefined4 param_5,float param_6);
void proc_7F06FCFC(undefined4 *param_1,undefined4 *param_2);
void proc_7F06FDCC(int param_1,undefined4 param_2,undefined4 param_3);
void proc_7F06FDE8(int param_1,float param_2);
void proc_7F06FE3C(int param_1,undefined4 param_2);
void proc_7F06FE44(int param_1,undefined4 param_2);
void proc_7F06FE4C(int param_1,undefined4 param_2,float param_3);
void proc_7F06FE90(int param_1,float param_2,float param_3);
void proc_7F06FF18(int param_1,undefined4 param_2,float param_3);
void proc_7F06FF5C(int param_1,undefined4 param_2);
void proc_7F06FF64(int param_1,float param_2);
void proc_7F070090(int param_1,float param_2,float param_3);
void proc_7F0701D4(undefined4 param_1);
undefined4 proc_7F0701E0(void);
void proc_7F0701EC(int param_1,float param_2,float param_3,float param_4,float param_5);
void proc_7F070AEC(int param_1,int param_2,int param_3);
void proc_7F070F80(int param_1);
void proc_7F071030(int param_1,longlong param_2);
void proc_7F071B44(int param_1,longlong param_2);
void proc_7F072644(int param_1);
void proc_7F0726F8(int param_1);
void proc_7F072784(int param_1,int param_2);
void proc_7F072984(int param_1,int param_2,ushort *param_3);
void proc_7F072C10(void);
void dorottex(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F073038(int param_1,uint *param_2,int param_3);
void proc_7F07306C(void);
void dotube(int param_1,int param_2,ushort *param_3);
void proc_7F0737EC(void);
void proc_7F0737FC(void);
void dogfnegx(int param_1,int param_2,ushort *param_3);
void proc_7F073FC8(undefined4 param_1);
void doshadow(int param_1,int param_2,ushort *param_3);
void proc_7F074514(void);
void proc_7F074524(void);
void proc_7F074534(int param_1,int param_2,ushort *param_3);
void subdraw(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);
void proc_7F074790(float **param_1,uint param_2,undefined4 param_3,undefined4 param_4);
undefined8 proc_7F0747D0(int param_1,float *param_2,float *param_3,float *param_4);
void proc_7F074C68(int param_1,ushort *param_2,float *param_3,float *param_4);
undefined8 proc_7F074CAC(int param_1,ushort *param_2,float *param_3,float *param_4);
undefined4 proc_7F0752FC(int param_1,float *param_2,float *param_3,ushort **param_4);
undefined4 proc_7F07549C(int param_1,float *param_2,float *param_3,ushort **param_4);
uint proc_7F0754BC(int *param_1,int param_2);
void proc_7F0755B0(void);
void convert_obj_microcode_offset_to_rdram_addr(ushort *param_1,int param_2,int param_3);
void proc_7F075A90(object_header *objheader,int param_2,int param_3);
void proc_7F075B08(void);
uint set_microcode_entry_numbers(ushort *param_1);
void set_objuse_flag_compute_grp_nums_set_obj_loaded(object_header *objheader);
void unknown_object_microcode_handler(int param_1,ushort *param_2);
void proc_7F075F68(int param_1,ushort **param_2,undefined4 param_3);
void proc_7F075FAC(int param_1,ushort **param_2,undefined4 param_3);
void proc_7F076030(int param_1,int param_2,ushort *param_3,ushort **param_4);
void proc_7F0760C4(object_header *objheader,ushort **param_2,int *param_3);
void proc_7F07623C(object_header *objheader,ushort *param_2,int param_3,int param_4);
void proc_7F0762E0(object_header *objheader,u8 *objectstring,int targetloc,uint *buffer);
void load_object_fill_header(object_header *objheader,u8 *recallstring,int targetloc,int sizeleft,int buffer);
void load_object_into_memory(object_header *header,u8 *recallstring);
void load_object_into_memory_unused_maybe(object_header *header,int *recallstring,int targetloc,int sizeleft);
s32 is_less_than_certain_power_of_2(int number);
int ceil8000(int width);
int ceil4000(int width);
int ceil2000(int width);
int ceil1000(int width);
int proc_7F0767D8(int param_1,int param_2,int param_3);
int proc_7F076848(int param_1,int param_2,int param_3);
int proc_7F0768B8(int param_1,int param_2,int param_3);
int proc_7F076928(int param_1,int param_2,int param_3);
void generate_microcode_for_othermode_setting(undefined4 *DL,int param_2,longlong param_3,longlong bowtie);
void append_image_to_DL(uint **DLtarget,sImageTableEntry *imgcall,int param_3,longlong bowtie,uint ul_s_t);
void proc_7F077BB8(s32 param_1,s32 param_2,s32 param_3);
void proc_7F077BD0(void);
void set_BONDdata_screensize(float width,float height);
void set_ulx_uly(f32 ulx,f32 uly);
void sub_GAME_7F077C30(f32 pnear,f32 pfovy,f32 paspect);
void proc_7F077C5C(void);
void proc_7F077EEC(float *param_1,float *param_2,float param_3);
void proc_7F077FB4(float *param_1,float param_2,float *param_3);
void proc_7F077FF4(float *param_1,float *param_2);
void proc_7F078060(float *param_1,float *param_2);
void proc_7F0780F0(float *param_1,float param_2,float *param_3);
void proc_7F078140(float *param_1,float *param_2,float param_3,float param_4,float param_5);
void proc_7F078258(float *param_1,float *param_2,float param_3,float param_4);
void set_BONDdata_field_10C4(int param_1);
int get_BONDdata_field_10C4(void);
void set_BONDdata_field_10C8(int param_1);
int get_BONDdata_field_10C8(void);
void set_BONDdata_field_10D8(int param_1);
int get_BONDdata_field_10D8(void);
void set_BONDdata_field_10E0(int param_1);
int get_BONDdata_field_10E0(void);
void copy_BONDdata_field_10CC_to_10E8_set_10CC(int param_1);
int get_BONDdata_field_10CC(void);
void set_BONDdata_field_10DC(int param_1);
int get_BONDdata_field_10DC(void);
int get_BONDdata_field_10E8(void);
void set_BONDdata_field_10D0(int param_1);
int get_BONDdata_field_10D0(void);
void proc_7F078424(int param_1);
int get_BONDdata_field_10D4(void);
int get_BONDdata_field_10EC(void);
void set_BONDdata_field_10E4(int param_1);
int get_BONDdata_field_10E4(void);
f32 getPlayer_c_lodscalez(void);
int getPlayer_c_lodscalezu32(void);
f32 getPlayer_c_screenwidth(void);
f32 getPlayer_c_screenheight(void);
f32 getPlayer_c_screenleft(void);
f32 getPlayer_c_screentop(void);
f32 getPlayer_c_perspfovy(void);
f32 getPlayer_c_perspaspect(void);
void setpointtocameratopnorm(xyzpoint *param_1);
void setpointtocameratopnorminvertedy(xyzpoint *param_1);
void setpointtocameraleftnorm(xyzpoint *param_1);
void setpointtocameraleftnorminvertedx(xyzpoint *param_1);
f32 getPlayer_c_perspnear(void);
void proc_7F0785DC(void);
void proc_7F078950(xyzpoint *param_1,undefined4 *param_2);
void proc_7F078980(undefined4 *param_1,undefined4 *param_2);
void proc_7F0789B0(undefined4 *param_1,undefined4 *param_2);
void proc_7F0789E0(undefined4 *param_1,undefined4 *param_2);
void proc_7F078A10(undefined4 *param_1,undefined4 *param_2);
undefined8 proc_7F078A58(float *param_1,float param_2);
undefined8 proc_7F078BF4(float *param_1,float param_2,float *param_3);
uint proc_7F0790F0(void);
void init_player_BONDdata(void);
void proc_7F0798B8(void);
void proc_7F079988(int param_1);
void change_crouch_position(int position);
int proc_7F0799F0(void);
int proc_7F079A1C(int param_1);
void proc_7F079A50(int param_1);
void proc_7F079A60(float *param_1,float *param_2,float *param_3,int param_4,float *param_5);
void solo_char_load(void);
void maybe_solo_intro_camera_handler(void);
CAMERAMODE get_camera_mode(void);
longlong proc_7F07A534(undefined4 param_1,float *param_2,char *param_3,float *param_4,u32 param_5,float param_6);
void set_camera_mode(CAMERAMODE param_1);
void proc_7F07B1A4(void);
void proc_7F07B2A0(int param_1,float param_2,float *param_3,float *param_4);
void proc_7F07B56C(void);
void proc_7F07C540(int param_1);
void set_BONDdata_lookahead_setting(int param_1);
int get_BONDdata_lookahead_setting(void);
void set_BONDdata_autoaim_y(int param_1);
ulonglong get_BONDdata_autoaim_y(void);
void redirect_get_BONDdata_autoaim(void);
int get_BONDdata_is_aiming(void);
void proc_7F07C5F0(int param_1,float param_2);
void set_BONDdata_autoaim_x(int param_1);
ulonglong get_BONDdata_autoaim_x(void);
void redirect_get_BONDdata_autoaim_x(void);
void proc_7F07C6C8(int param_1,float param_2);
void change_player_pos_to_target(int *target_posblock,int *src_pos,int *tile);
void proc_7F07C7B4(void);
void proc_7F07C888(float *param_1,float *param_2,float param_3);
longlong proc_7F07CA2C(undefined8 param_1,f32 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 *param_7,undefined4 *param_8);
undefined4 proc_7F07CAC8(float *param_1,undefined4 param_2,float param_3,undefined4 *param_4,undefined4 *param_5);
void proc_7F07CDA8(float *param_1,undefined4 param_2,float param_3);
undefined8 related_printmanpos(float *param_1,float param_2,undefined4 *param_3);
BOOL get_intank_flag(void);
undefined4 get_ptr_for_players_tank(void);
void proc_7F07CEB0(float *param_1);
undefined4 proc_7F07CF80(void);
undefined4 proc_7F07CF8C(void);
ulonglong proc_7F07D234(undefined4 *param_1,float *param_2,float *param_3);
undefined8 proc_7F07D2B4(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5);
undefined8 proc_7F07D4C0(float *param_1,float *param_2,float *param_3);
undefined8 proc_7F07D61C(float *param_1,float *param_2,float *param_3);
undefined4 proc_7F07D954(undefined4 param_1);
void proc_7F07D960(float *param_1,int param_2);
void proc_7F07DE64(int param_1);
void proc_7F07DE9C(int param_1);
void proc_7F07DEFC(void);
float proc_7F07DF28(longlong param_1);
void proc_7F07E010(undefined4 param_1);
void proc_7F07E03C(undefined4 param_1);
ulonglong proc_7F07E068(void);
void proc_7F07E090(void);
float proc_7F07E388(void);
void trigger_watch_zoom(f32 final,f32 time);
Player * proc_7F07E438(void);
void proc_7F07E46C(void);
void proc_7F07E504(void);
void zoom_to_watch_on_open(void);
void zoom_from_watch_on_exit(void);
ulonglong check_watch_page_transistion_running(void);
void proc_7F07E62C(void);
float proc_7F07E740(void);
void proc_7F07E7CC(void);
void proc_7F07E8B0(float param_1);
void proc_7F07E910(float param_1);
void proc_7F07E964(void);
float proc_7F07EA78(void);
void set_BONDdata_paused_flag(int ispaused);
int get_BONDdata_paused_flag(void);
void proc_7F07EAF0(void);
void probably_look_at_watch(void);
void set_open_close_solo_watch_menu_to_1(void);
void trigger_solo_watch_menu(longlong param_1);
void proc_7F07FCC4(longlong param_1);
void proc_7F07FE1C(longlong param_1);
float proc_7F07FF74(void);
void proc_7F080010(void);
float proc_7F080228(void);
void proc_7F0802C4(void);
undefined4 * proc_7F0804E0(undefined4 *param_1);
void proc_7F0807B0(u32 param_1,u32 param_2,u32 param_3,float param_4);
void proc_7F0807E0(undefined4 param_1,undefined8 param_2,int param_3,int param_4,f32 param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,undefined4 param_11);
void fade_to_over_seconds(f32 seconds,f32 fadeto);
ulonglong check_if_fade_to_black_complete(void);
void proc_7F0808BC(void);
void set_curplayer_fade(f32 timer,f32 finalamount);
void proc_7F080A80(void);
void proc_7F080B34(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5);
float proc_7F080D60(undefined8 param_1,undefined4 param_2,undefined4 param_3);
void proc_7F080DF8(void);
void proc_7F081478(void);
void proc_7F081790(void);
void controller_gameplay_interaction(void);
void proc_7F083FC8(void);
void proc_7F084360(void);
void MoveBond(char param_1,char param_2,ushort param_3,ushort param_4);
void proc_7F086990(undefined8 param_1,undefined8 param_2,ushort param_3,ushort param_4);
int getWidth320or440(void);
int getHeight330or240(void);
s32 get_curplayer_viewport_width(void);
undefined8 get_curplayer_viewport_ulx(void);
int get_curplayer_viewport_height(void);
int get_curplayer_viewport_uly(void);
void possibly_reset_viewport_options_for_player(char param_1,char param_2,ushort param_3);
void proc_7F0875E4(s32 roomindex);
void store_BONDdata_curpos_to_previous(void);
void proc_7F0876C4(float *param_1,float *param_2,float *param_3);
undefined4 proc_7F087A08(undefined4 param_1);
void seems_to_load_cuff_microcode(void *instance,Gitemheader *header,void *param_3);
undefined4 * proc_7F087E74(undefined4 *param_1);
undefined4 * proc_7F088618(undefined4 *param_1);
void proc_7F0888E8(void);
undefined4 * proc_7F088CD8(undefined4 *param_1);
undefined4 * maybe_mp_interface(void);
undefined8 write_stan_tiles_in_yellow(undefined8 param_1);
void proc_7F089718(float param_1);
void proc_7F08976C(undefined4 param_1);
f32 proc_7F089778(int param_1);
float proc_7F089780(int param_1);
int get_curplayer_positiondata(void);
void kill_current_player(void);
int proc_7F0898E8(void);
void record_damage_kills(f32 arg0,f32 arg1,f32 arg2,s32 arg3,f32 arg4);
void proc_7F089E4C(f32 param_1,float param_2,f32 param_3);
ulonglong check_if_bond_is_invincible(void);
ulonglong check_if_healthbar_timer_greater_than_0(void);
f32 get_BONDdata_bondfadefracnew(void);
float get_curplay_horizontal_rotation_in_degrees(void);
float get_curplay_vertical_rotation_in_degrees(void);
int proc_7F089F38(void);
void set_bondata_invincible_flag(char flag);
ulonglong get_bondata_invincible_flag(void);
void set_invisible_to_guards_flag(BOOL param_1);
BOOL get_invisible_to_guards_flag(void);
void set_obj_collision_flag(int flag);
BOOL get_obj_collision_flag(void);
ulonglong get_cur_players_room(void);
xyzpoint * get_BONDdata_position(void);
int * get_BONDdata_position3(void);
int proc_7F08A02C(void);
void proc_7F08A03C(int param_1,int param_2);
void proc_7F08A0B0(int param_1,int **param_2,undefined4 *param_3,float *param_4,float *param_5);
void proc_7F08A19C(void);
void proc_7F08A274(int param_1,undefined4 *param_2,float *param_3,undefined4 *param_4);
f32 get_BONDdata_watch_health(void);
f32 get_BONDdata_watch_armor(void);
void add_BONDdata_watch_armor(f32 amount);
void reset_intro_camera_message_dialogs_for_BONDdata(void);
void proc_7F08A380(uint param_1);
void set_flags_in_BONDdata_stationary_intro_cam(uint param_1);
void proc_7F08A3B4(undefined4 param_1,undefined4 param_2);
void display_string_in_lower_left_corner(char *text,...);
void proc_7F08A4E4(void);
undefined4 * proc_7F08A5FC(undefined4 *param_1);
void proc_7F08A900(void);
void proc_7F08A928(uint param_1);
void proc_7F08A944(uint param_1);
void display_string_at_top_of_screen(char *text);
void proc_7F08A9F8(void);
u32 * print_player_xyz_info(void);
undefined4 proc_7F08B0F0(char *param_1);
undefined8 proc_7F08BCB8(undefined8 param_1);
undefined8 proc_7F08BCC0(char *param_1,undefined8 param_2,uint param_3);
undefined4 * proc_7F08BCF4(undefined4 *param_1);
void proc_7F08BD18(uint *param_1);
void proc_7F08BD48(undefined4 *param_1,int param_2);
void proc_7F08BDC4(uint *param_1);
void proc_7F08BE2C(undefined4 *param_1,int param_2);
void proc_7F08BEEC(float *param_1,int param_2);
int getMissiontime(void);
void trigger_explosions_around_player(int delay);
void reinit_BONDdata_inventory(void);
void proc_7F08C054(int *param_1);
void add_additional_weapon_slot_to_player_inventory_documentation_guess(int *param_1);
void reorder_inventory_ptrs_based_on_id_code(undefined4 *param_1);
int get_ptr_next_available_weapon(void);
void set_BONDdata_allguns_flag(int param_1);
int get_BONDdata_allguns_flag(void);
int * get_ptr_inventory_item(ITEM_IDS item);
BOOL is_weapon_in_inv(ITEM_IDS item);
int * get_ptr_inventory_for_item_in_hand(int item,int hand);
ulonglong is_item_for_hand_in_inventory(int item,int hand);
ulonglong check_if_item_available(ITEM_IDS weaponid);
ulonglong check_if_item_for_hand_available(ITEM_IDS item,int hand);
BOOL add_item_to_inventory(ITEM_IDS item);
undefined8 add_doubles_item_to_inventory(int right,int left);
int proc_7F08C570(char param_1);
void proc_7F08C61C(longlong param_1);
undefined8 proc_7F08C724(int param_1);
ulonglong proc_7F08C764(char *param_1);
void proc_7F08C86C(int *nextright,int *nextleft,s32 direction);
void proc_7F08CB10(int *param_1,int *param_2,longlong param_3);
undefined8 proc_7F08CE70(uint param_1);
undefined8 proc_7F08CF0C(void);
ulonglong proc_7F08CF80(void);
void checkforgoldengun(void);
undefined8 proc_7F08CFE0(int param_1);
int proc_7F08D038(void);
int * proc_7F08D108(int param_1);
int proc_7F08D21C(int param_1);
int proc_7F08D25C(int param_1);
int proc_7F08D2A8(int param_1);
int proc_7F08D340(int param_1);
int proc_7F08D434(int param_1);
int proc_7F08D528(int param_1);
int proc_7F08D550(int param_1);
int proc_7F08D578(int param_1);
int proc_7F08D5A0(int param_1);
int proc_7F08D5C8(int param_1);
int proc_7F08D6BC(int param_1);
int proc_7F08D7B0(int param_1);
int proc_7F08D7D8(int param_1);
int proc_7F08D800(int param_1);
int proc_7F08D828(int param_1);
int proc_7F08D850(int param_1);
int proc_7F08D878(int param_1);
void proc_7F08D8A0(int param_1);
int proc_7F08D8C0(void);
void proc_7F08D8D0(int param_1);
void proc_7F08D8E0(void);
int proc_7F08D95C(int param_1);
int proc_7F08D9A4(int param_1);
void proc_7F08D9EC(int param_1,int param_2);
void proc_7F08DB08(undefined4 *param_1,undefined4 *param_2);
void proc_7F08DBB0(void);
void proc_7F08DBC8(void);
void proc_7F08DE48(float *param_1);
void proc_7F08DF44(float *param_1,float *param_2);
void proc_7F08E164(float param_1);
void proc_7F08E240(float param_1,float param_2);
void proc_7F08E8BC(float param_1);
void proc_7F08EA48(undefined4 param_1,undefined param_2,float param_3,float param_4);
void proc_7F08EAB8(float param_1);
float proc_7F08EAF8(void);
int * proc_7F08EBD0(float *param_1);
int * proc_7F08EC8C(float *param_1,undefined8 param_2,int *param_3);
int proc_7F08ED60(int *param_1,int param_2);
void proc_7F08EDB4(int *param_1,undefined4 param_2);
undefined8 proc_7F08EE00(int **param_1,int *param_2);
longlong proc_7F08EE70(int param_1,int param_2,int **param_3,longlong param_4);
undefined4 proc_7F08EF1C(int param_1,int **param_2,int **param_3);
int proc_7F08EFA0(int **param_1,int **param_2,int **param_3,longlong param_4);
int proc_7F08F090(int *param_1,int param_2,int param_3);
void proc_7F08F0E8(int *param_1,undefined4 param_2,int param_3);
undefined8 proc_7F08F138(int *param_1,int param_2,int param_3);
void proc_7F08F1D8(int param_1,int param_2,longlong param_3);
void proc_7F08F2CC(int param_1,int param_2);
int proc_7F08F350(int param_1,int param_2,int *param_3,longlong param_4);
void proc_7F08F438(int param_1,int param_2,int *param_3,int *param_4);
int proc_7F08F4F0(int param_1,int param_2,int *param_3,longlong param_4);
void proc_7F08F67C(void);
int proc_7F08F6B0(int *param_1,int param_2);
int proc_7F08F908(int *param_1,int param_2);
int proc_7F08FB90(int param_1,int param_2);
void proc_7F08FD1C(void);
void nullsub_32(void);
void proc_7F08FE08(undefined4 param_1);
void init_debug_menu_values(char *strings,mcm_layout *positions,u32 *columns);
undefined4 print_debug_mcm_to_stdout(undefined4 counter);
void proc_7F09000C(void);
u32 get_highlighted_debug_option(void);
void set_highlighted_debug_option(u32 option);
void gotoAboveDebugOption(void);
void gotoBelowDebugOption(void);
void gotoRightDebugOption(void);
void gotoLeftDebugOption(void);
void display_debug_menu_text_onscreen(void);
void handle_debug_stanview(void);
void handle_debug_bondview(void);
void handle_debug_case_2(void);
void removed_do_debug_profile_flag_false(void);
void removed_do_debug_profile_flag_true(void);
void debug_menu_processor(u32 stick_h,u32 stick_v,controller_buttons button_held,controller_buttons button_pressed);
u32 get_debug_render_raster(void);
u32 get_debug_freeze_processing(void);
u32 get_debug_limit_controller_input(void);
void set_debug_limit_controller_input(void);
BOOL get_memusage_display_flag(void);
BOOL get_debug_do_draw_bg(void);
BOOL get_debug_do_draw_obj(void);
BOOL get_debug_stanhit_flag(void);
BOOL get_debug_stanregion_flag(void);
BOOL get_turbo_mode_flag(void);
BOOL get_debug_man_pos_flag(void);
BOOL get_debug_testingmanpos_flag(void);
void set_debug_testingmanpos_flag(BOOL flag);
BOOL get_debug_joy2skyedit_flag(void);
BOOL get_debug_joy2hitsedit_flag(void);
BOOL get_debug_joy2detailedit_flag(void);
BOOL get_debug_explosioninfo_flag(void);
BOOL get_debug_prroomloads_flag(void);
BOOL get_linemode_flag(void);
void set_linemode_flag(BOOL param_1);
BOOL get_debug_007_unlock_flag(void);
BOOL get_debug_enable_agent_levels_flag(void);
BOOL get_debug_enable_all_levels_flag(void);
BOOL get_debug_fast_bond_flag(void);
void set_debug_fast_bond_flag(BOOL param_1);
BOOL get_debug_all_obj_complete_flag(void);
BOOL getdebug_portal_flag(void);
BOOL get_debug_chrnum_flag(void);
BOOL get_debug_gunwatchpos_flag(void);
BOOL get_debug_profile_flag(void);
BOOL get_debug_taskgrab_val(void);
void proc_7F091080(char param_1,char param_2,ushort param_3);
undefined4 proc_7F091580(undefined4 param_1);
void proc_7F0915BC(float param_1);
void handle_debug_intropos(void);
void handle_debug_worldpos(void);
void stanStoreBondCoord(void);
int cheatButton_7F091740(controller_buttons *param_1);
void cheatButton_7F09177C(void);
void cheat_buttons_mp_related(void);
u32 is_cheat_index_equal_to_1C(u32 cheatindex);
u32 cheatCheckIfMPCheat(CHEAT_IDS cheat);
void turn_on_cheat_for_players(u32 cheatindex);
void handle_cheats_turned_on(CHEAT_IDS cheat);
void cheatDisplayMessageActivateCheat(CHEAT_IDS cheat);
void cheatDisableAllCheats(void);
int cheatGetMenuTextPointer(CHEAT_IDS cheat);
uint cheatCheckIfOn(CHEAT_IDS cheat);
void set_DKMode(s32 param_1);
undefined8 proc_7F092890(short *param_1,short *param_2,short *param_3,float *param_4,float *param_5,float *param_6,float *param_7,float *param_8);
void proc_7F092E50(void);
undefined4 * proc_7F09343C(undefined4 *param_1,longlong param_2);
undefined4 * proc_7F09365C(undefined4 *param_1,longlong param_2);
void proc_7F093880(void);
undefined8 proc_7F0938FC(float *param_1,float *param_2,float *param_3);
undefined8 proc_7F093A78(float *param_1,float *param_2,float *param_3);
void proc_7F093BFC(float *param_1,float *param_2,float *param_3);
float proc_7F093C48(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5);
float addpoint5tofloat(float param_1);
void proc_7F093CB0(int param_1,float param_2);
void proc_7F093FA4(int param_1,float param_2);
uint proc_7F094298(float param_1);
void store_stagenum_to_copyof_stagenum(STAGENUM stagenum);
void proc_7F094438(void);
uint * proc_7F094488(void);
void proc_7F097388(float *param_1,float *param_2,uint param_3,float param_4,float param_5,float *param_6);
ulonglong proc_7F0977B4(int param_1,int param_2);
undefined4 *proc_7F097818(undefined4 *param_1,int param_2,int param_3,int param_4,float param_5,int param_6);
undefined4 *proc_7F098A2C(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,float param_6);
void default_player_perspective_and_height(void);
void reset_play_data_ptrs(void);
void init_player_data_ptrs_construct_viewports(int playercount);
s32 get_num_players(void);
void initBONDdataforPlayer(PLAYER_ID player);
void set_cur_player(PLAYER_ID playernum);
u32 get_cur_playernum(void);
void proc_7F09B15C(int position_data_pointer);
void set_cur_player_screen_size(short width,short height);
void set_cur_player_viewport_size(short ulx,short uly);
void set_cur_player_fovy(f32 fovy);
void set_cur_player_aspect(f32 aspect);
f32 get_cur_player_fovy(void);
s32 proc_7F09B244(ITEM_IDS param_1);
void proc_7F09B368(int param_1);
longlong proc_7F09B398(uint param_1);
void proc_7F09B41C(void);
int proc_7F09B4D8(int param_1);
int proc_7F09B528(int param_1);
void proc_7F09B600(byte *param_1,byte *param_2,uint *param_3);
undefined4 proc_7F09B740(void);
void proc_7F09B788(u64 param_1);
void removed_7f09b7a0(void);
void proc_7F09B7A8(void);
void proc_7F09B7E4(void);
void proc_7F09B820(void);
void proc_7F09BAC4(int param_1,int param_2);
void proc_7F09BBBC(void);
int proc_7F09BE4C(longlong param_1,longlong param_2,int param_3,int param_4);
void proc_7F09C044(uint param_1);
void proc_7F09C250(int param_1,float *param_2,int param_3,undefined4 param_4,int param_5,undefined param_6,char *param_7,int param_8);
void proc_7F09C7AC(void);
void proc_7F09C7C4(float *param_1,float *param_2,float *param_3);
void proc_7F09C9D8(char *param_1,float param_2,float param_3);
undefined8 proc_7F09CEE8(char *param_1);
undefined8 proc_7F09D4EC(int param_1);
longlong proc_7F09D5A0(char *param_1,longlong param_2,longlong param_3);
undefined4 * proc_7F09D82C(float *param_1,undefined4 *param_2,float *param_3);
undefined4 * proc_7F09DDA4(int param_1,float *param_2,undefined4 *param_3,float *param_4);
void proc_7F09E700(undefined4 *param_1,int param_2,short param_3,char *param_4,int param_5);
undefined8 proc_7F09E8AC(char *param_1);
undefined8 proc_7F09EF9C(int param_1);
longlong proc_7F09F03C(char *param_1,longlong param_2,longlong param_3);
void proc_7F09F254(float *param_1,float param_2,float param_3,float param_4,float param_5);
void proc_7F09FD3C(void);
undefined4 * proc_7F0A0034(undefined4 *param_1);
void proc_7F0A027C(float *param_1,float param_2,short param_3);
undefined4 * proc_7F0A0AB4(undefined4 *param_1);
int proc_7F0A0C74(float param_1);
void proc_7F0A0CCC(int param_1,char param_2);
void proc_7F0A0D90(int param_1);
void proc_7F0A0E98(int param_1);
void proc_7F0A108C(float *param_1,float *param_2,short param_3,short param_4,int param_5,char param_6,undefined param_7);
undefined4 * proc_7F0A1A94(undefined4 *param_1,int param_2,uint param_3);
void proc_7F0A1D78(undefined4 *param_1);
void proc_7F0A1DA0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float param_6,float param_7,float param_8);
void proc_7F0A2160(undefined4 *param_1,undefined4 param_2,float param_3);
void proc_7F0A28D4(void);
undefined4 * proc_7F0A2C44(undefined4 *param_1);
void proc_7F0A2F30(short *param_1,undefined8 param_2,longlong param_3,float param_4);
undefined4 * proc_7F0A3330(undefined4 *param_1,int param_2,longlong param_3);
void proc_7F0A33F8(short *param_1,int param_2,float param_3,longlong param_4);
undefined4 * proc_7F0A3978(undefined4 *param_1,int param_2,undefined8 param_3,longlong param_4);
short * proc_7F0A3AB8(short *param_1,short param_2,short param_3,short param_4,short param_5,short param_6,short param_7);
undefined4 * proc_7F0A3B40(undefined4 *param_1,undefined4 param_2);
void proc_7F0A3B70(int param_1,undefined *param_2);
void proc_7F0A3BA4(int param_1,undefined *param_2);
void proc_7F0A3BD8(void);
void proc_7F0A3C08(undefined4 *param_1,undefined4 *param_2,int param_3,float param_4,short param_5);
undefined4 * proc_7F0A3E1C(undefined4 *param_1,int param_2,float param_3,short param_4);
void proc_7F0A3EA0(void);
void proc_7F0A3F04(void);
void proc_7F0A4528(undefined8 param_1,undefined8 param_2);
float proc_7F0A4594(int param_1);
void proc_7F0A45D8(void);
undefined4 *proc_7F0A4600(undefined4 *param_1,undefined4 *param_2,int param_3,float param_4,float param_5,undefined2 param_6);
void proc_7F0A46A0(void);
void proc_7F0A4768(undefined8 param_1,undefined8 param_2);
void proc_7F0A47D4(void);
void proc_7F0A47FC(void);
void proc_7F0A4824(undefined8 param_1,undefined8 param_2);
void proc_7F0A4860(void);
void init_watch_at_start_of_stage(void);
void controller_deadzone_related(void);
void proc_7F0A4B40(undefined4 *param_1);
u32 controllerCheckControllerTypesAllowed(void);
s32 cur_player_get_control_type(void);
void cur_player_set_control_type(int type);
u32 get_cur_player_look_vertical_inverted(void);
void set_cur_player_look_vertical_inverted(u32 param_1);
u32 cur_player_get_autoaim(void);
void cur.player.set.autoaim(u32 param_1);
undefined4 cur.player.get.lookahead(void);
void cur.player.set.lookahead(undefined4 param_1);
undefined4 cur.player.get.aim.control(void);
void cur.player.set.aim.control(undefined4 param_1);
undefined4 cur.player.get.sight.onscreen.control(void);
void cur.player.set.sight.onscreen.control(undefined4 param_1);
undefined4 cur.player.get.ammo.onscreen.setting(void);
void cur.player.set.ammo.onscreen.setting(undefined4 param_1);
undefined4 cur.player.get.screen.setting(void);
void cur.player.set.screen.setting(undefined4 param_1);
undefined4 get.screen_ratio(void);
void set.screen_ratio(undefined4 param_1);
int ** proc_7F0A4EF8(void);
void sub_GAME_7F0A4F44(void);
u32 is_holding_greater_than_2E_left_on_stick(void);
u32 is_holding_greater_than_2E_right_on_stick(void);
u32 get_controlstick_lr_enabled(void);
void set_controlstick_lr_disabled(void);
bool sub_GAME_7F0A4FB0(void);
bool proc_7F0A4FEC(void);
ulonglong is_holding_greater_than_2E_up_on_stick(void);
ulonglong is_holding_greater_than_2E_down_on_stick(void);
undefined4 get_D_80040AE0(void);
void set_D_80040AE0_0(void);
ulonglong sub_GAME_7F0A5088(void);
ulonglong sub_GAME_7F0A50C4(void);
ulonglong is_holding_less_than_10_up_on_stick(void);
ulonglong is_holding_less_than_10_down_on_stick(void);
undefined4 get_D_80040AE4(void);
void set_D_80040AE4_0(void);
ulonglong proc_7F0A5160(void);
ulonglong proc_7F0A519C(void);
void sub_GAME_7F0A51D8(void);
void proc_7F0A5210(void);
void proc_7F0A526C(void);
void proc_7F0A53D8(void);
void proc_7F0A5504(void);
void proc_7F0A55C4(void);
void proc_7F0A56A4(void);
void proc_7F0A5784(void);
void sub_GAME_7F0A5860(void);
void proc_7F0A5900(void);
void proc_7F0A5998(void);
void sub_GAME_7F0A5A64(void);
void sub_GAME_7F0A5AF4(void);
void proc_7F0A5B80(void);
void proc_7F0A611C(float *controltype_2,int *controltype_0,int param_3,int *negvspacing,int *controltype_1,undefined4 *controltype_set,int param_7,int param_8,int param_9);
void proc_7F0A6618(void);
void proc_7F0A66A0(void);
void proc_7F0A672C(void);
void proc_7F0A67BC(void);
void proc_7F0A684C(void);
void proc_7F0A68D8(short *param_1);
void proc_7F0A69A8(void);
float proc_7F0A6A2C(float param_1);
void proc_7F0A6A80(void);
undefined4 * proc_7F0A6EE8(undefined4 *param_1);
void proc_7F0A70AC(int param_1,int param_2);
u32 * proc_7F0A714C(u32 *DL,u32 param_2,u32 param_3);
void proc_7F0A77A8(undefined8 param_1,undefined8 param_2);
void proc_7F0A77C8(undefined4 *param_1);
void proc_7F0A7C18(undefined4 *param_1);
u32 stub_return_param_7F0A7DBC(u32 param_1);
uint * proc_7F0A7DC4(undefined4 *param_1);
void debug_gun_watch_move_related(void);
void proc_7F0A830C(undefined8 param_1,undefined8 param_2);
int ** proc_7F0A8378(void);
uint * debug_gun_watch_move_related2(undefined8 param_1,undefined8 param_2);
uint * proc_7F0A8B10(undefined8 param_1,u32 param_2);
void proc_7F0A8D40(undefined2 *param_1,float param_2,int param_3);
void proc_7F0A8ED0(ushort *param_1);
undefined4 * proc_7F0A8FEC(void);
void call_sfx_c_700091C8(void);
void proc_7F0A91A0(ulonglong param_1);
undefined4 * proc_7F0A91C8(void);
u16 proc_7F0A9358(void);
void proc_7F0A9364(ushort param_1);
void proc_7F0A9398(undefined4 *param_1,uint param_2,uint param_3,byte *param_4,uint param_5,int param_6,uint param_7,int param_8,int param_9,uint param_10,int param_11);
float sub_GAME_7F0A95C4(float param_1,float param_2,float param_3);
undefined8 proc_7F0A9610(void);
void proc_7F0A9684(char param_1,int *param_2,float *param_3,float *param_4);
uint * proc_7F0A97D0(undefined4 *param_1);
uint * proc_7F0A9AB8(undefined4 *param_1);
void sub_GAME_7F0AA7C8(u32 *DisplayList);
void proc_7F0AADC0(u32 *DL);
void zero_D_80040998(void);
void zero_D_8004099C(void);
void zero_D_800409A4(void);
u32 return_arg0_7F0AB4B0(u32 param_1);
void proc_7F0AB4B8(u32 *DL,u32 param_2);
void set_pparam1toparam2_disablejoylr_playsfx(u32 *param_1,u32 param_2);
ulonglong proc_7F0AB7D8(int param_1);
uint * proc_7F0AB908(undefined4 *param_1,uint param_2,int param_3,longlong param_4);
uint * proc_7F0ABC1C(undefined4 *param_1);
uint * proc_7F0ABDFC(undefined8 param_1,undefined8 param_2);
int proc_7F0AC0E8(char *param_1);
char * proc_7F0AC120(char *param_1);
uint * proc_7F0AC168(undefined8 param_1,undefined8 param_2);
longlong proc_7F0ACA28(longlong param_1,int param_2,int param_3);
void null_init_main_7f0acb70(void);
void setTextSpacingInverted(int spacing);
void setTextOrientation(s32 param_1);
void setTextWordWrap(s32 param_1);
void setTextOverlapCorrection(s32 param_1);
void load_font_tables(void);
void microcode_constructor(u32 *DL);
undefined4 * combiner_bayer_lod_perspective(undefined4 *DL);
undefined4 *draw_blackbox_to_screen(undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5);
undefined4 *microcode_constructor_related_to_menus(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,uint param_5,uint param_6);
uint * construct_fontchar_microcode(void *DL,int xpos,int ypos,void *ptr_tbl2entry,void *ptr_unk,void *ptr_tbl1,int ulx,int uly,int lrx,int lry,int unk);
void en_text_write_stuff(undefined4 *param_1,int *param_2,int *param_3,byte *param_4,int param_5,int param_6,uint param_7,int param_8,int param_9,int param_10,int param_11);
uint * proc_7F0ADDAC(uint *param_1,uint *param_2,int *param_3,uint *param_4,int param_5,int param_6,int param_7,uint param_8,uint param_9,uint param_10,int param_11,int param_12,int param_13);
uint * proc_7F0AE45C(uint *param_1,uint param_2,int param_3,int param_4,int param_5,uint param_6,int param_7,int param_8);
void jp_text_stuff(uint *param_1,uint *param_2,uint *param_3,byte *param_4,int param_5,int param_6,uint param_7,uint param_8,int param_9,int param_10,int param_11,int param_12);
void proc_7F0AE98C(int *param_1,int *param_2,byte *param_3,int param_4,int *param_5,int param_6);
void find_width_word_in_string(int max_width,byte *text,byte *textbuffer,int secondfonttable,int *firstfonttable);
void proc_7F0AEF0C(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
u32 sub_GAME_7F0AEF20(u32 param_1,u32 param_2);
f32 proc_7F0AEF30(f32 param_1);
char * proc_7F0AEF3C(ushort *param_1);
char * proc_7F0AEFE0(ushort *param_1);
undefined8 proc_7F0AF000(void);
void something_stan_c_debug_related(void);
void proc_7F0AF038(void);
int * proc_7F0AF20C(float *param_1,byte *param_2,float *param_3);
void proc_7F0AF5B8(int param_1);
void removed_7F0AF630(int param_1);
int proc_7F0AF638(ushort *param_1,uint param_2,ushort **param_3);
ulonglong proc_7F0AF760(int param_1);
int * proc_7F0AF808(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6);
void proc_7F0AF924(int param_1,float *param_2);
void proc_7F0AFA1C(int param_1,undefined8 param_2,float *param_3);
float proc_7F0AFB1C(float *param_1,float *param_2);
int * proc_7F0AFB78(float *param_1,undefined4 *param_2,float *param_3,float param_4);
float proc_7F0AFD1C(int param_1,int param_2,float param_3,float param_4);
float proc_7F0AFE70(int param_1,longlong param_2,float param_3,float param_4);
undefined proc_7F0AFFCC(int param_1,int param_2,float param_3,float param_4);
undefined proc_7F0B0018(int param_1,longlong param_2,float param_3,float param_4);
void proc_7F0B0064(int param_1,int param_2,float param_3,float param_4);
float proc_7F0B00C4(int param_1,int param_2,float param_3,float param_4);
float proc_7F0B0140(int param_1,int param_2,float param_3,float param_4);
ulonglong proc_7F0B0198(int param_1,int param_2,float param_3,float param_4);
undefined8 proc_7F0B02D8(void);
u32 proc_7F0B036C(u32 param_1,f32 param_2,f32 param_3);
float proc_7F0B0400(int param_1,longlong param_2,float param_3,float param_4);
undefined8 proc_7F0B0518(int param_1,float param_2,float param_3);
undefined8 proc_7F0B05C0(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6);
ulonglong proc_7F0B0688(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10);
uint proc_7F0B07BC(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7,float param_8,float param_9,float param_10,int param_11);
undefined8 proc_7F0B0914(int *param_1,float param_2,float param_3,float param_4,float param_5,undefined *param_6,float param_7);
void proc_7F0B0BE4(int *param_1,float param_2,float param_3,float param_4,float param_5);
void proc_7F0B0C24(int *param_1,float param_2,float param_3,float param_4,float param_5,undefined *param_6,undefined4 *param_7,undefined4 param_8);
void proc_7F0B0C98(int param_1,undefined8 param_2,uint **param_3);
void proc_7F0B0CEC(int param_1,undefined8 param_2,uint **param_3);
int proc_7F0B0D0C(int param_1,float param_2,float param_3,int *param_4,float param_5,float param_6,uint *param_7,int param_8);
undefined4 proc_7F0B0E24(u32 *param_1,f32 param_2,f32 param_3,f32 param_4);
char * proc_7F0B1410(int param_1,float param_2,float param_3,float param_4,float param_5,uint param_6);
float proc_7F0B16C4(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7,float param_8);
void proc_7F0B1794(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6);
ulonglong proc_7F0B17E4(float param_1,float param_2,undefined8 param_3,undefined8 param_4,float param_5,float param_6,float param_7,float param_8);
longlong proc_7F0B18B8(void);
void proc_7F0B1CC4(void);
undefined4 proc_7F0B1CE0(void);
undefined4 proc_7F0B1CEC(void);
void proc_7F0B1CF8(int param_1,int param_2,float *param_3,float *param_4);
undefined8 proc_7F0B1DDC(int *param_1,float param_2,float param_3,float param_4,undefined *param_5,undefined *param_6,undefined *param_7,code *param_8);
void proc_7F0B20D0(int *param_1,float param_2,float param_3,float param_4);
undefined8 proc_7F0B2110(int param_1,int **param_2);
undefined8 proc_7F0B2194(undefined8 param_1,undefined8 param_2,int param_3);
undefined8 proc_7F0B21B0(int *param_1,float param_2,float param_3,float param_4,float param_5,undefined4 *param_6,undefined4 param_7);
undefined8 proc_7F0B2244(int param_1,undefined4 *param_2);
undefined8 proc_7F0B2274(int param_1,int param_2,undefined param_3,undefined param_4,undefined param_5,undefined4 *param_6);
uint proc_7F0B2314(int *param_1,float param_2,float param_3,float param_4,undefined4 *param_5);
undefined4 proc_7F0B239C(undefined4 *param_1);
undefined4 proc_7F0B23A4(int param_1);
void proc_7F0B23AC(int param_1,undefined8 param_2,float *param_3);
void proc_7F0B2420(int *param_1,int *param_2,int param_3);
undefined8 proc_7F0B260C(int param_1,int param_2,undefined param_3,undefined param_4,undefined param_5,float *param_6);
void proc_7F0B26B8(int *param_1,float param_2,float param_3,float param_4,float param_5);
int proc_7F0B2718(int param_1,undefined *param_2);
undefined8 proc_7F0B28B0(float *param_1,float *param_2);
void proc_7F0B2950(float param_1);
ulonglong proc_7F0B2970(void);
void copy_tile_RGB_as_24bit(int *tile,int posx,int posz,tile_rgb *target);
void proc_7F0B2C74(int param_1,float *param_2);
float proc_7F0B2D14(int param_1);
void removed_7F0B2D38(u32 param_1,u32 param_2,u32 param_3);
undefined8 proc_7F0B2D48(undefined8 param_1);
void proc_7F0B2D50(byte *param_1,ushort *param_2,byte *param_3);
int * stanMatchTileName(byte *param_1);
void proc_7F0B2F00(int **param_1);
void load_stan(int param_1,int param_2,int param_3);
ulonglong proc_7F0B2FD8(int param_1);
uint proc_7F0B2FE0(int param_1);
void proc_7F0B3004(int param_1);
undefined8 proc_7F0B3024(undefined8 param_1);
undefined8 proc_7F0B3034(undefined8 param_1);
undefined8 stan_problems_removed(undefined8 param_1);
undefined4 proc_7F0B3044(int param_1);
undefined8 stan_region_removed(undefined8 param_1);
void proc_7F0B3138(undefined8 param_1,undefined8 param_2,f32 param_3,f32 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9);
void proc_7F0B31A4(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
float proc_7F0B3200(float *param_1,float *param_2,float *param_3,float *param_4);
float proc_7F0B32D8(float *param_1,float *param_2,float *param_3);
float proc_7F0B33DC(float *param_1,float *param_2,float *param_3,float *param_4);
void something_with_bg_c_debug(void);
void proc_7F0B37EC(void);
void proc_7F0B38B4(byte param_1,byte *param_2);
uint proc_7F0B39BC(int param_1,int param_2,float *param_3,uint param_4);
void proc_7F0B3B04(int param_1);
int proc_7F0B3B20(void);
void proc_7F0B3BC4(void);
undefined8 proc_7F0B3C0C(int param_1,int *param_2);
longlong proc_7F0B3C8C(longlong param_1);
int proc_7F0B4034(int param_1);
int proc_7F0B4084(int param_1);
int proc_7F0B40D4(int param_1);
void load_bg_file(STAGENUM stagenum);
void proc_7F0B47E0(void);
void proc_7F0B4810(float param_1);
f32 proc_7F0B4830(void);
f32 proc_7F0B483C(void);
float proc_7F0B4848(void);
f32 proc_7F0B4878(void);
void proc_7F0B4884(void);
void proc_7F0B4A50(char *param_1,char param_2);
void proc_7F0B4AB4(float *param_1,float *param_2,byte *param_3,int param_4,uint *param_5,int *param_6,int param_7);
undefined4 * proc_7F0B4E40(undefined4 *param_1);
f32 proc_7F0B4F9C(int param_1);
uint * proc_7F0B4FB4(uint *param_1);
uint * proc_7F0B4FF4(uint *param_1,float param_2,float param_3,float param_4,float param_5);
uint * proc_7F0B5058(uint *param_1,longlong param_2,longlong param_3,int param_4,int param_5);
void proc_7F0B5168(void);
undefined8 proc_7F0B519C(float *param_1,float *param_2);
undefined8 proc_7F0B5208(int param_1,float *param_2);
ulonglong proc_7F0B5488(float *param_1,float *param_2);
ulonglong proc_7F0B5528(int param_1,float param_2,float *param_3);
s32 proc_7F0B5864(void);
uint * proc_7F0B5B14(uint *param_1,undefined8 param_2,undefined8 param_3,int param_4,int param_5);
uint * proc_7F0B5B60(uint *param_1,undefined8 param_2,undefined8 param_3,int param_4,int param_5);
undefined8 vis_is_inline_of_sight(float *param_1,float *param_2);
void proc_7F0B5CC0(float *param_1,float *param_2);
void proc_7F0B5D58(undefined4 *param_1,undefined4 *param_2);
char * print_port(undefined8 param_1);
char * printroom(undefined8 param_1);
u32 get_max_num_rooms(void);
ulonglong proc_7F0B5E50(int param_1);
ulonglong proc_7F0B5E6C(int param_1);
int proc_7F0B5E88(int param_1);
void generate_room_load_string(void);
u8 * decompressdata_with_8448buffer(int source,u8 *target);
int proc_7F0B5FAC(int param_1,int param_2,int param_3);
uint * proc_7F0B609C(int param_1,uint *param_2,int param_3);
uint * proc_7F0B61DC(int param_1,uint *param_2,int param_3);
ulonglong proc_7F0B6314(int param_1);
void proc_7F0B6368(int param_1);
void proc_7F0B65C4(int param_1);
void unload_rooms(void);
void proc_7F0B66E8(void);
undefined4 * proc_7F0B677C(undefined4 *param_1,int param_2);
undefined4 * proc_7F0B6898(undefined4 *param_1,int param_2);
void proc_7F0B6994(int param_1);
undefined8 proc_7F0B6CEC(float *param_1,float *param_2,int *param_3,int *param_4);
undefined4 proc_7F0B7010(float *param_1,float *param_2,float *param_3,short *param_4,int param_5,float *param_6);
int proc_7F0B7A78(float *param_1,float *param_2,int param_3,float *param_4);
void proc_7F0B7D94(void);
ulonglong proc_7F0B7DA8(int param_1);
void proc_7F0B7DE4(undefined4 param_1,uint param_2,int param_3,int param_4,undefined4 *param_5);
undefined8 proc_7F0B7EE4(int *param_1);
undefined8 proc_7F0B7F84(undefined8 param_1,int param_2,int param_3,int param_4,float *param_5);
undefined8 push_arg_to_table(undefined8 param_1);
undefined4 pull_arg_from_stack(void);
undefined4 proc_7F0B83E4(int param_1);
byte * parse_global_vis_command_list(vis_command *cmd,uint mode);
byte * proc_7F0B8A24(byte *param_1);
void proc_7F0B8A6C(void);
uint * proc_7F0B8D78(longlong param_1);
int proc_7F0B8DF4(ulonglong param_1,int param_2,int param_3);
int proc_7F0B8E98(uint *param_1,int param_2);
int proc_7F0B8EFC(ulonglong param_1,int *param_2,int param_3);
undefined8 proc_7F0B8FD0(ulonglong param_1,ulonglong param_2);
float proc_7F0B9040(int param_1,float param_2,float param_3);
void proc_7F0B908C(void);
void proc_7F0B92B4(int param_1,float *param_2);
void proc_7F0B9338(int param_1);
int proc_7F0B95D8(ulonglong param_1);
void proc_7F0B96CC(int param_1,float *param_2);
ulonglong proc_7F0B993C(int param_1);
float proc_7F0B9990(int param_1);
ulonglong proc_7F0B9A14(int param_1);
void proc_7F0B9A2C(int param_1);
void proc_7F0B9A7C(int param_1);
ulonglong proc_7F0B9AE4(int param_1);
ulonglong proc_7F0B9B04(int param_1);
void proc_7F0B9B24(int param_1);
void proc_7F0B9B44(int param_1);
void proc_7F0B9B64(int param_1);
void proc_7F0B9B94(int param_1);
int proc_7F0B9CC8(ulonglong param_1,ulonglong param_2,float *param_3,float *param_4);
void proc_7F0B9DBC(int param_1,longlong param_2);
undefined8 proc_7F0B9DE4(undefined8 param_1);
void proc_7F0B9DF4(void);
void proc_7F0B9DFC(void);
int proc_7F0B9E04(float *param_1,float *param_2);
undefined8 proc_7F0B9F14(int param_1,float *param_2,float *param_3);
undefined8 proc_7F0BA26C(int param_1,float *param_2,float *param_3,int param_4);
void proc_7F0BA2D4(float *param_1,float *param_2,int *param_3,int *param_4,int param_5);
void proc_7F0BA5C0(int *param_1,int *param_2);
void proc_7F0BA640(int *param_1,int *param_2,int param_3);
void proc_7F0BA720(void);
undefined4 * get_ptr_currentdata(void);
f32 get_near_fog_value(void);
float square_near_fog_value(void);
void copy_table1_env_to_current(void);
void copy_table2_env_to_current(int param_1);
void proc_7F0BAA5C(void);
void load_enviroment(int param_1,int param_2);
void switch_to_solosky2(float param_1);
undefined4 * proc_7F0BB070(undefined4 *param_1,longlong param_2);
undefined4 * proc_7F0BB298(undefined4 *param_1);
undefined8 proc_7F0BB2C8(float *param_1,float param_2);
undefined4 return_nearfog_values(void);
undefined8 if_sky_present_convert_values(int param_1,float *param_2);
void init_lightfixture_tables(void);
int get_index_of_current_entry_in_init_lightfixture_table(void);
void add_entry_to_init_lightfixture_table(Gfx *DL);
void save_ptrDL_enpoint_to_current_init_lightfixture_table(int param_1);
undefined8 check_if_imageID_is_light(longlong imageID);
uint return_ptr_vertex_of_entry_room(char *entry,int room);
void proc_7F0BB6F4(undefined8 param_1,ulonglong param_2);
void proc_7F0BB874(undefined8 param_1,ulonglong param_2,int param_3,undefined2 *param_4,undefined2 *param_5,undefined2 *param_6);
void proc_7F0BB978(ulonglong param_1);
void proc_7F0BBA20(int param_1,ulonglong param_2);
undefined8 proc_7F0BBADC(int param_1,ulonglong param_2);
void proc_7F0BBBA8(undefined8 param_1,ulonglong param_2,int param_3);
int proc_7F0BBC30(undefined8 param_1,ulonglong param_2,int param_3);
undefined8 proc_7F0BBCCC(void);
void proc_7F0BBE0C(ulonglong param_1,ulonglong param_2,short param_3);
void proc_7F0BC4C4(short param_1);
void proc_7F0BC530(void);
void proc_7F0BC624(int param_1);
void proc_7F0BC634(int param_1,int param_2);
void proc_7F0BC660(int param_1,int param_2);
void proc_7F0BC690(int param_1);
int proc_7F0BC6F0(void);
void proc_7F0BC7D4(void);
longlong proc_7F0BC85C(int param_1);
undefined4 * proc_7F0BC9C4(undefined4 *param_1,int param_2);
int proc_7F0BCA14(int param_1);
void proc_7F0BCA34(int index,float *param_2);
void load_resource(u8 *ptrdata,u32 bytes,fileentry *srcfile,resource_lookup_data_entry *lookupdata);
void load_resource_from_indy(u8 *ptrdata,u32 bytes,fileentry *srcfile,resource_lookup_data_entry *lookupdata);
void ob_c_debug_setup(void);
void _load_rom_index_to_membank(int index,longlong param_2,int size,byte bank);
undefined * _load_resource_index_to_membank(int fileid,longlong param_2,undefined *param_3,int bank);
u8 * _load_resource_named_to_membank(byte *filename,int param_2,int size,byte bank);
u8 * _load_resource_named_to_buffer(byte *filename,int param_2,undefined *param_3,int param_4);
void load_bg_bytes_at_offset_to_membank(byte *bgname,char *src,int offset,int len);
u8 * load_rom_resource_index_to_membank(int index,longlong param_2,int size,byte bank);
void load_resource_index_to_buffer(int index,longlong param_2,u8 *ptrdata,int bytes);
s32 get_pc_remaining_buffer_for_index(int index);
u32 get_rom_remaining_buffer_for_index(int param_1);
void proc_7F0BD138(int index,u8 *ptrdata,int size,longlong param_4);
s32 get_pc_buffer_remaining_value(byte *name);
void something_mem_bank_a0(byte param_1);
void proc_7F0BD234(void);
int get_index_num_of_named_resource(byte *filename);
void removed_handle_filetable_entry(int param_1);
void removed_loop_handle_filetable_entries(void);
void removed_loop_filetableentries(void);
void proc_7F0BD410(void);
void something_with_dyn_c_debug(void);
void set_vtx_gfx_mem_alloc(void);
Gfx * get_ptr_displaylist(void);
int allocate_something_in_mgfx(int param_1);
void proc_7F0BD6C4(int param_1);
void proc_7F0BD6E0(void);
void proc_7F0BD6F8(int param_1);
void proc_7F0BD714(int param_1);
void allocate_something_in_mvtx(void);
void removed_debug_routine(int param_1);
int num_microcode_cmds_that_fit(int ptr_DLtarget);
int proc_7F0BD7A4(void);
char * compute_membar_display_string(char *string,int commandsused,int commandsavailable);
char * draw_membars(void);
undefined4 proc_7F0BD8F0(void);
void proc_7F0BD8FC(undefined4 param_1);
void something_with_lvl_c_debug(void);
void playrandommusictrack1(void);
void playmusictrack1(MUSIC_TRACKS track);
void music_append_play_solo_death_short(void);
void music_append_play_endtheme(void);
void proc_7F0BDA84(void);
void stage_load(LEVELID stagenum);
STAGENUM proc_7F0BDF04(void);
undefined4 proc_7F0BDF10(longlong param_1);
uint * proc_7F0BE30C(Gfx *param_1);
void proc_7F0BE8D0(void);
void manage_mp_game(void);
void proc_7F0BF800(void);
void unload_stage_text_data(void);
void set_controls_locked_flag(undefined4 flag);
undefined4 get_controls_locked_flag(void);
DIFFICULTY get_current_difficulty(void);
void set_difficulty(undefined4 param_1);
void set_mp_time(undefined4 time);
void set_mp_point(undefined4 point);
f32 get_cur_mp_sec(void);
f32 get_cur_mp_min(void);
f32 get_stage_time_sec(void);
f32 get_poweron_time_sec(void);
void clear_ramrom_block_buffer_heading_ptrs(void);
undefined4 get_is_ramrom_flag(void);
u32 get_recording_ramrom_flag(void);
undefined4 interface_menu0B_runstage(void);
void finalize_ramrom_on_hw(void);
void save_ramrom_to_devtool(void);
void load_ramrom_from_devtool(void);
void record_player_input_as_packet(int param_1,int param_2,int param_3);
int ramrom_replay_handler(int param_1,int param_2);
void iterate_ramrom_entries_handle_camera_out(void);
void copy_current_ingame_registers_before_ramrom_playback(ramromfilestructure *param_1);
void copy_recorded_ramrom_registers_to_proper_place_ingame(ramromfilestructure *demo);
void test_if_replaying_or_recording_demos_this_stage_load(LEVELID param_1,DIFFICULTY param_2);
void record_next_movie_to_slot(undefined4 slotnum);
void stop_recording_ramrom(void);
void replay_recorded_ramrom_at_address(uint param_1);
void replay_recorded_ramrom_from_indy(void);
void check_set_cameramode_to_A(void);
void stop_demo_playback(void);
void select_ramrom_to_play(void);
undefined4 check_ramrom_flags(void);
void store_osgetcount(void);
void proc_7F0C0AA0(int param_1);
void proc_7F0C0B4C(void);
void proc_7F0C0BE4(undefined4 param_1);
void proc_7F0C0BF0(void);
void proc_7F0C0C10(void);
undefined4 get_mission_state(void);
void set_missionstate(ulonglong param_1);
void sub_GAME_7F0C11FC(s16 param_1);
void setmissionstate_to_zero(void);
void proc_7F0C1288(void);
void proc_7F0C12CC(void);
void proc_7F0C1310(void);
void proc_7F0C1340(void);
void proc_7F0C1364(void);
void reset_all_music_slots(void);
void set_musicslot_time(int slot,int min,int sec);
void reset_music_in_slot(u32 param_1);
undefined8 get_textbank_number_for_stagenum(LEVELID param_1);
void init_LnameX(void);
void something_with_LnameJ(void);
int something_with_LnameX(uint param_1);
void load_mission_text_bank(u32 param_1);
void load_briefing_text_bank(int lnameID,undefined *target,int size);
void blank_text_bank(int param_1);
u8 * get_textptr_for_textID(TEXTFILESTRINGS id);
undefined8 MP_menu_page_adv_right(void);
undefined8 MP_menu_page_adv_left(void);
s32 check_if_player_is_pressing_anything_right(char param_1);
undefined8 check_if_player_is_pressing_anything_left(char param_1);
int ** play_watch_sfx_beep(void);
void unpause_game(void);
undefined4 proc_7F0C2024(int param_1,int param_2,int param_3,int param_4,int param_5);
undefined4 proc_7F0C2114(int param_1,int param_2,int param_3,int param_4,int param_5);
undefined4 proc_7F0C2204(int param_1,float param_2,float param_3,float param_4,float param_5);
undefined4 proc_7F0C234C(int param_1,float param_2,float param_3,float param_4,float param_5);
void proc_7F0C2494(void);
undefined8 proc_7F0C24BC(void);
void set_stopplay_flag(void);
void proc_7F0C2530(longlong param_1);
int ** proc_7F0C2E80(void);
uint * display_text_for_playerdata_on_MP_menu(uint *param_1,int param_2,uint param_3,undefined8 param_4,undefined4 param_5);
int get_points_for_mp_player(uint param_1);
int write_playerrank_to_buffer(char *buffer,uint player);
undefined8 true_if_displaying_rank_in_mp(int param_1);
undefined8 true_if_displaying_score_in_mp(void);
uint * mp_watch_menu_display(uint *param_1);
ulonglong proc_7F0C6048(void);
undefined4 get_ispaused(void);
undefined4 * display_red_blue_on_radar(undefined4 *param_1);
void advance_mp_weapon_set_by_one_save_value(void);
mp_weaponset_set * get_mpweaponset(void);
mp_weaponset_weapon * get_ptr_mp_weapon_set_data(void);
void set_mp_weapon_set(u32 param_1);
u32 get_mp_weapon_set(void);
void nullsub_41(void);
uint image_related_calls_decompressdata(undefined4 param_1,byte *param_2,int param_3,int param_4,int param_5);
undefined *copy_loaded_image_to_final_mem_location(undefined *param_1,int param_2,int param_3,longlong param_4,undefined *param_5);
int proc_7F0C6C70(byte *param_1,int param_2,int param_3,int param_4,int param_5,ushort *param_6,uint param_7);
uint proc_7F0C77AC(ushort *param_1,uint param_2,int param_3,int param_4,int param_5,uint param_6);
uint proc_7F0C7BD8(ushort *param_1,uint param_2,int param_3,uint param_4);
int process_huffman_compressed_images(undefined4 param_1,uint *param_2,int param_3,int param_4,int param_5);
int image_decompresion_related(uint *param_1,int param_2,int param_3,int param_4,uint param_5);
void generate_sample_table(int param_1,int param_2,ulonglong param_3);
void type4_7_9_getsamples(int param_1,int param_2);
uint type5_6_7_getsamples(uint *param_1,longlong param_2);
int proc_7F0C9A24(int param_1);
void image_get_alpha_values(undefined *param_1,int param_2);
undefined8 image_compression0_expand(void);
int generate_link_final_image(int param_1,uint param_2,int param_3,uint *param_4,undefined4 param_5);
int type5_generate_link_final_image(int param_1,int param_2,int *param_3,int param_4,int param_5,undefined4 param_6);
int type6_7_generate_link_final_image(ushort *param_1,uint param_2,int param_3,uint *param_4,int param_5,int param_6,undefined4 param_7);
void proc_7F0CB67C(int param_1,int param_2,int param_3,int param_4);
void type8_9_doohick(int param_1,int param_2,int param_3,undefined4 param_4,int param_5);
void proc_7F0CBAF4(int *param_1,int param_2,int param_3);
uint * proc_7F0CBB0C(uint imageid,undefined4 *buffer);
int proc_7F0CBB64(int param_1);
void check_load_image_to_buffer(char *image,uint *buffer);
void load_image_to_buffer(uint *image,uint *buffer);
void proc_7F0CBE50(object_header *objheader,uint *buffer);
void calls_load_image_to_buffer(uint image,uint *buffer);
void proc_7F0CBF10(undefined *param_1);
uint proc_7F0CBF2C(uint bits);
void load_prepare_global_image_bank(void);
void proc_7F0CC4C0(void);
void proc_7F0CC4C8(void);
undefined * proc_7F0CC51C(undefined *param_1,int param_2,undefined *param_3);
undefined8 proc_7F0CC548(int param_1);
undefined8 proc_7F0CC574(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8,int param_9,int param_10,int param_11);
undefined8 proc_7F0CC690(int param_1,int param_2,int param_3,int param_4,int param_5);
ulonglong proc_7F0CC714(uint *param_1,ulonglong param_2);
ulonglong proc_7F0CC7FC(uint *param_1,ulonglong param_2);
int proc_7F0CC8E4(uint *param_1,ulonglong param_2);
int proc_7F0CC994(uint *param_1,ulonglong param_2);
void proc_7F0CC9D4(uint *param_1,undefined4 *param_2,int *param_3);
int proc_7F0CCA9C(int param_1);
undefined8 proc_7F0CCACC(longlong param_1);
int proc_7F0CCAFC(float param_1);
int proc_7F0CCB38(uint *param_1);
uint * proc_7F0CCC50(uint *param_1,uint *param_2,int param_3,uint param_4,uint param_5,uint param_6);
uint * proc_7F0CCFBC(uint *param_1,uint *param_2,int param_3,longlong param_4);
uint * expland_c0_DL_psuedocommands(uint *command,uint *facemapperimage,uint param_3);
uint * proc_7F0CD430(uint *param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6,uint param_7);
uint * proc_7F0CD7AC(uint *param_1,uint *param_2);
uint * proc_7F0CDB64(uint *param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6);
uint * proc_7F0CDE18(uint *command,uint *facemapper_entry,int s_flags,int t_flags,int settilesize_offset);
uint * proc_7F0CDEA8(uint *param_1,uint *param_2,int param_3,int param_4,int param_5,uint *param_6,uint param_7,uint param_8,uint param_9);
uint * proc_7F0CDFA8(uint *param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6,uint param_7,uint param_8);
uint * proc_7F0CE064(uint *param_1,uint *param_2,int param_3,int param_4,int param_5);
uint * proc_7F0CE0AC(uint *param_1,uint *param_2,int param_3,int param_4,int param_5);
uint * process_microcode_sort_display_modes_expand_image_calls(uint *param_1,int param_2,uint *param_3,uint *param_4);
void proc_7F0CE794(int param_1,int param_2,int param_3);
u8 * decompressdata(u8 *source,u8 *target,u8 *buffer);
int proc_7F0CE894(void);
ulonglong proc_7F0CE8B0(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,uint *param_7);
undefined8 proc_7F0CEEF0(int param_1,int param_2,ulonglong param_3,uint param_4);
undefined8 zlib_decompressor_type0(void);
undefined8 zlib_decompressor_type1(void);
undefined8 zlib_decompressor_type2(void);
undefined8 _inflate_block(uint *param_1);
longlong loop_to_decompress_entire_file(void);
void something_with_rsp_c_debug(void);
void allocate_init_rsp_buffers(void);
void load_rsp_microcode(int param_1,int param_2,undefined8 param_3,undefined4 param_4);
void init_indy_if_not_ready(void);
void dummy7F0CFF64(void);
void init_indy_if_ready(void);
void indy_load_resource(char *filename,u8 *targetloc);
void indy_send_capture_data(char *name,undefined *param_2,uint size);
void indy_load_ramrom_file(char *filename,u8 *target,s32 size);
void check_file_exported(char *param_1,undefined4 param_2,undefined4 param_3);
u8 * check_file_found_on_indy(char *name,undefined4 *size);
u32 send_command_string(char *param_1);
void proc_7F0D0124(void);
u32 send_indy_close_port_cmd(void);
void sub_GAME_7F0D0180(u8 *buffer,u32 size);
void proc_7F0D01D0(u8 *buffer,u32 size);
undefined8 postindyresourcecommand(indy_resource_entry *cmd,u32 size);
u32 send2indyresourcecommands(indy_resource_entry *entry1,uint size1,indy_resource_entry *entry2,uint size2);
void post_type1_indyrescmd_sizenextcmd(s32 readsize,s32 writesize);
void post_type2_indyrescmd_cmds_rdy_to_proc(s32 readsize,s32 writesize);
void post_type0_indyrescmd_init(s32 readsize,s32 writesize);
void post_type3_indyrescmd(s32 rsize,s32 wsize,char *strptr);
void post_type4_indyrescmd_data_recieved(s32 param_1,s32 param_2,u32 param_3);
void post_type5_indyrescmd_printfsend(s32 param_1,s32 param_2,char *param_3);
void post_type6_indyrescmd_printfrecieved(s32 rsize,s32 wsize,u32 data1,u32 data2);
void post_type7_indyrescmd_log_send(u32 param_1,u32 param_2,u8 *strptr,u32 param_4);
void post_type8_indyrescmd_log_recieved(s32 rsize,s32 wsize,undefined4 data1,undefined4 data2,uint cmd2size,indy_resource_entry *cmd2);
void post_type9_indyrescmd_app_command_ready(s32 rsize,s32 wsize,char *strptr,uint size2,indy_resource_entry *cmd2);
void post_typeA_indyrescmd_app_command_recieved(s32 readsize,s32 writesize,u32 data);
void post_typeF_indyrescmd_fault_send(u32 rsize,u32 wsize,char *name,u32 filesize,u32 ptarget);
void post_type10_indyrescmd_fault_ack_by_host(s32 rsize,s32 wsize,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void post_typeD_indyrescmd_prof_send_filename(u32 rsize,u32 wsize,u8 *ptrstr,u32 size,u8 *hwaddress);
void post_typeE_indyrescmd_prof_recv(s32 readsize,s32 writesize,u32 data);
void post_typeB_indyrescmd_host_prof_req(s32 rsize,s32 wsize,char *strptr);
void post_typeC_indyrescmd_prof_send(s32 readsize,s32 writesize,u32 data);
void post_typeA_indyrescmd_app_data_recieved(s32 readsize,s32 writesize,u32 data);
undefined8 post_indy__res_cmd_initialize_seq(void);
u32 post_indyrescmd_game_data_send(char *strptr);
u32 post_indyrescmd_debug_data_recv(u32 data);
u32 post_indyrescmd_game_printf_send(char *strptr);
u32 post_indyrescmd_debug_printf_recv(u32 data1,u32 data2);
u32 post_indyrescmd_req_filename_size(u8 *filename,u32 size);
u32 post_indyrescmd_1_8_2(u32 data1,u32 data2,u32 size2,indy_resource_entry *cmd2);
u32 post_indyrescmd_send_capture_data(char *string,uint size,indy_resource_entry *data);
u32 post_indyrescmd_recv_capture_data_success(u32 data);
u32 post_indyrescmd_request_ramrom_file(char *name,u32 ptarget,u32 filesize);
u32 post_indyrescmd_1_10_2(u32 param_1,u32 param_2,u32 param_3);
u32 post_indyrescmd_game_prof_sendfile(char *strptr,u8 *phwaddr,u32 size);
u32 post_indyrescmd_host_prof_recv(u32 data);
u32 post_indyrescmd_1_B_2(char *strptr);
u32 post_indyrescmd_1_C_2(u32 data);
u32 post_indyrescmd_1_A_2(u32 data);
undefined8 post_indyrescmd_read_command(indy_resource_entry *param_1,uint param_2);
u32 post_indyrescmd_read_2commands(u8 *buffer1,u32 size1,u8 *buffer2,u32 size2);
u32 post_indyrescmd_istype1_correctsize(int readsize,int writesize);
u32 post_indyrescmd_istype2_correctvalue(int readsize,int writesize);
undefined8 post_indyrescmd_istype4_correctvalue(int param_1,int param_2,u8 *response);
undefined8 post_indyrescmd_istype6_correctvalue(int param_1,int param_2,u8 *response1,u8 *response2);
undefined8 post_indyrescmd_istype8_correctvalue(int param_1,int param_2,u8 *response1,u8 *response2,u32 childsize,u8 *child);
undefined8 post_indyrescmd_istypeA_correctvalue(int param_1,int param_2,u8 *response);
undefined8 post_indyrescmd_istype10_correctvalue(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5);
undefined8 post_indyrescmd_istypeE_correctvalue(int param_1,int param_2,u8 *param_3);
undefined8 post_indyrescmd_istypeC_correctvalue(int param_1,int param_2,u8 *param_3);
u32 response_indyrescmd_1_4_2(u8 *response);
u32 response_indyrescmd_1_6_2(u8 *response1,u8 *response2);
u32 response_indyrescmd_1_8_2(u8 *response1,u8 *response2,u32 datasize,u8 *data);
u32 response_indyrescmd_1_A_2(u8 *param_1);
u32 response_indyrescmd_1_10_2(u32 *param_1,u32 *param_2,u32 *param_3);
u32 response_indyrescmd_1_E_2(u8 *response);
u32 response_indyrescmd_1_C_2(u8 *response);
u32 response_indyrescmd_curr_matches_expected(int readsize,int writesize);
void something_game_c_debug_related(void);
void reset_mem_bank_5(void);
void proc_7F0D1A7C(void);
char * get_compile_time(void);
undefined4 * proc_7F0D1AC0(undefined4 *param_1);
void proc_7F0D1B94(uint *param_1,float param_2,uint param_3,uint param_4,int param_5);
uint * proc_7F0D1BD0(uint *param_1,float param_2,uint param_3,uint param_4,int param_5,int param_6,int param_7);
void proc_7F0D1DCC(float param_1);
void proc_7F0D1DFC(uint *param_1,float param_2,uint param_3,uint param_4,int param_5);
void proc_7F0D1E44(uint *param_1,float param_2,uint param_3,uint param_4,int param_5,int param_6,int param_7);
uint * proc_7F0D1E98(undefined4 *param_1,undefined8 param_2,undefined8 param_3,int param_4);
void proc_7F0D2320(void);
void remove_viewport_buffer(void);
void allocate_viewport_buffer(void);
void proc_7F0D2448(undefined4 param_1,undefined4 param_2,undefined4 param_3);
undefined4 * proc_7F0D2464(undefined4 *param_1);
undefined4 * proc_7F0D2518(undefined4 *param_1);
MUSIC_TRACKS getmusictrack_or_randomtrack(u32 stagenum);
short sub_GAME_7F0D2848(short param_1);
short proc_7F0D2890(short param_1);
void proc_7F0D28E0(int param_1,int param_2,undefined8 param_3,byte *param_4);
void proc_7F0D2A84(int param_1,int param_2);
void spectrum_p1controller_to_kempston(void);
void init_spectrum_game(byte param_1);
void run_spectrum_game(void);
undefined4 * spectrum_draw_screen(undefined4 *param_1);
ulonglong spectrum_input_handling(undefined8 param_1,uint param_2,char param_3);
void dummy7F0D37D4(void);
undefined8 proc_7F0D37DC(undefined8 param_1,undefined8 param_2,char param_3,byte param_4);
void spectrum_hw_emulation(void);
void entry(void);
void boot(void);
void rspbootTextStart(void)

