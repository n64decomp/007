#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "ultra64.h"
#include "bondconstants.h"
struct rgba_val{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

struct rgba_valf32{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

typedef struct CHRdata CHRdata, *PCHRdata;

/* unfinished struct, WIP */
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
    /* 0x0010 */
    u8 grenadeprob;
    s8 flinchcnt;
    s16 hidden;
    s32 chrflags;
    void * pad;
    void * model;
    /* 0x0020 */
    void * field_20;
    f32 chrwidth;
    f32 chrheight;
    void * bondpos; /* HACK - reused as fadeout counter on death, checks if pointer at 7F02B774 */
    /* 0x0030 */
    int field_30;
    short field_34;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int path_target_position;
    /* 0x0040 */
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    /* 0x0050 */
    int field_50;
    int field_54;
    char type_of_motion;
    char distance_counter_or_something;
    short distance_to_target;
    int field_5C;
    /* 0x0060 */
    int target_position;
    int field_64;
    int field_68;
    int field_6C;
    /* 0x0070 */
    int path_segment_coverage;
    int path_segment_length;
    int field_78;
    int field_7C;
    /* 0x0080 */
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    /* 0x0090 */
    int field_90;
    int segment_coverage;
    int segment_length;
    int field_9C;
    /* 0x00A0 */
    int field_A0;
    f32 sumground;
    f32 manground;
    f32 ground;
    /* 0x00B0 */
    f32 fallspeed[3];
    f32 prevpos[3];
    /* 0x00B8 */
    s32 lastwalk60;
    s32 lastmoveok60;
    /* 0x00D0 */
    f32 visionrange;
    s32 lastseetarget60;
    f32 lastvisibletarg[3];
    /* 0x00E4 */
    void * field_E4;
    s32 timeshooter;
    f32 hearingscale;
    /* 0x00F0 */
    s32 lastheartarget60;
    u8 shadecol[4];
    u8 nextcol[4];
    f32 damage;
    /* 0x0100 */
    f32 maxdamage;
    void * ailist;
    u16 aioffset;
    u16 aireturnlist;
    u8 flags; /* used by ai commands 81-85 */
    u8 flags2; /* used by ai commands 86-8A */
    u8 BITFIELD;
    u8 random;
    /* 0x0110 */
    s32 timer60;
    u16 padpreset1; /* ID PAD_PRESET */
    u16 chrpreset1; /* ID CHR_PRESET */
    u16 chrseeshot; /* ID CHR_SEE_SHOT - ignores invincible/armoured guards */
    u16 chrseedie; /* ID CHR_SEE_DIE */
    /* 0x011C */
    f32 field_11C[2];
    f32 field_124[2];
    f32 field_12C[2];
    /* 0x0134 */
    int field_134;
    int field_138;
    f32 shotbondsum;
    /* 0x0140 */
    f32 aimuplshoulder;
    f32 aimuprshoulder;
    f32 aimupback;
    f32 aimsideback;
    /* 0x0150 */
    f32 aimendlshoulder;
    f32 aimendrshoulder;
    f32 aimendback;
    f32 aimendsideback;
    /* 0x0160 */
    int * handle_positiondata[2];
    int * ptr_SEbuffer1;
    int * ptr_SEbuffer2;
    /* 0x0170 */
    int * ptr_SEbuffer3;
    int * ptr_SEbuffer4;
    int field_178;
    int field_17C;
    /* 0x0180 */
    char field_180;
    char field_181;
    char field_182;
    char field_183;
    int field_184;
    int field_188;
    int field_18C;
    /* 0x0190 */
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    /* 0x01A0 */
    int field_1A0;
    int field_1A4;
    int field_1A8;
    char field_1AC;
    char field_1AD;
    char field_1AE;
    char field_1AF;
    /* 0x01B0 */
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    /* 0x01C0 */
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    /* 0x01D0 */
    int field_1D0;
    int field_1D4;
    int * handle_positiondata_hat;
};

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

struct watchMenuObjectiveText {
    u32 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16 text;
    struct watchMenuObjectiveText * nextentry;
};
//!FIXME all but text field cannot be trusted
struct objective_entry {
    u32 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16 text;
    struct watchMenuObjectiveText * nextentry;
};

typedef struct sImageTableEntry {
    u32 index;
    u8 width;
    u8 height;
    u8 level;
    u8 format;
    u8 depth;
    u8 flagsS;
    u8 flagsT;
    u8 pad;
} sImageTableEntry;

typedef struct sGlobalImageTable {
    u32 globalDL_0x000[30];
    u32 globalDL_0x078[42];
    u32 globalDL_0x120[42];
    u32 globalDL_0x1c8[42];
    u32 globalDL_0x270[42];
    u32 globalDL_0x318[42];
    u32 globalDL_0x3c0[42];
    u32 globalDL_0x468[42];
    u32 globalDL_0x510[42];
    u32 globalDL_0x5b8[42];
    u32 globalDL_0x660[42];
    u32 globalDL_0x708[42];
    u32 globalDL_0x7b0[42];
    u32 globalDL_0x858[42];
    u32 globalDL_0x900[42];
    u32 globalDL_0x9a8[42];
    u32 globalDL_0xa50[30];
    struct sImageTableEntry s_genericimage[1];
    struct sImageTableEntry s_impactimages[20];
    struct sImageTableEntry s_explosion_smokeimages[6];
    struct sImageTableEntry s_scattered_explosions[5];
    struct sImageTableEntry s_flareimage1[1];
    struct sImageTableEntry s_flareimage2[1];
    struct sImageTableEntry s_flareimage3[1];
    struct sImageTableEntry s_flareimage4[1];
    struct sImageTableEntry s_flareimage5[1];
    struct sImageTableEntry s_ammo9mmimage[1];
    struct sImageTableEntry s_rifleammoimage[1];
    struct sImageTableEntry s_shotgunammoimage[1];
    struct sImageTableEntry s_knifeammoimage[1];
    struct sImageTableEntry s_glammoimage[1];
    struct sImageTableEntry s_rocketammoimage[1];
    struct sImageTableEntry s_genericmineammoimage[1];
    struct sImageTableEntry s_grenadeammoimage[1];
    struct sImageTableEntry s_magnumammoimage[1];
    struct sImageTableEntry s_goldengunammoimage[1];
    struct sImageTableEntry s_remotemineammoimage[1];
    struct sImageTableEntry s_timedmineammoimage[1];
    struct sImageTableEntry s_proxmineammoimage[1];
    struct sImageTableEntry s_tankammoimage[1];
    struct sImageTableEntry s_crosshairimage[1];
    struct sImageTableEntry s_betacrosshairimage[1];
    struct sImageTableEntry s_glassoverlayimage[2];
    struct sImageTableEntry s_monitorimages[50];
    struct sImageTableEntry s_skywaterimages[3];
    struct sImageTableEntry s_mainfolderimages[6];
    struct sImageTableEntry s_mpradarimages[1];
    struct sImageTableEntry s_mpcharselimages[64];
    struct sImageTableEntry s_mpstageselimages[17];
} sGlobalImageTable;



#endif
