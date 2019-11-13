#ifndef _CHROBJDATA_H_
#define _CHROBJDATA_H_
#include "ultra64.h"

struct prop_pos_data {
    u16 x;
    u16 y;
    u16 z;
};

struct item_related {
    short num_entries_in_block;
    short field_2;
    struct prop_pos_data * ptr_block;
    short total_cmd_indexval;
    short field_A;
};

struct Gitemheader {
    int offset_objtable;
    void * guntype_modeldata;
    int offset_objblock;
    u16 num05soffset_entries;
    u16 num_objgroups;
    float drawdistance;
    u16 num_entries;
    u16 num_images;
    int offset_imgdecl;
    u32 isloaded;
};


struct PitemZ_header {
    s32 microcode_entry_num;
    struct item_related * anonymous_1;
    short anonymous_2;
    short field_E;
    s32 drawdistance;
    float anonymous_4;
    s32 anonymous_5;
    s32 anonymous_6;
    s32 anonymous_7;
};

struct p_itementry {
    struct PitemZ_header * header;
    char * filename;
    float scale;
};

struct object_header {
    int offset_obj_table;
    void * ptr_archetype;
    int offset_obj_offset_block;
    short num_offset_entries;
    short num_object_grps;
    float anonymous_4;
    short num_table_entries;
    short num_image_entries;
    int offset_img_declaration;
    int is_loaded_in_mem;
};

struct c_itementry {
    struct object_header * header;
    char * filename;
    float anonymous_1;
    float anonymous_2;
    int anonymous_3;
};

struct model_data {
    u32  anonymous_0;
    u32 *propposdata;
    u32  anonymous_2;
};

struct player_gait_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    struct player_gait_object_entry * field_0x4;
    struct player_gait_pos_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_pos_header * next;
};

struct player_gait_pos_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    struct player_gait_position_entry * field_0x4;
    struct player_gait_pos_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_pos_header * next;
};

struct player_gait_object_entry {
    u32 field_0x0;
    struct player_gait_pos_header * ptr_header;
    u32 field_0x8;
    u32 field_0xc;
};

struct player_gait_position_entry {
    float z_scale;
    float y_offset;
    float xy_scale;
    u16 field_0xc;
    u16 field_0xe;
    u16 field_0x10;
    u16 field_0x12;
    struct player_gait_pos_header * ptr_header;
    u32 field_0x18;
};

struct struct_13 {
    void * ailist;
    int ailistid;
};

struct headHat
{
    float xoffset;
    float yoffset;
    float zoffset;
    float xsize;
    float ysize;
    float zsize;
};

extern struct item_related prop_cctv_related;
extern struct item_related prop_console_one_screen_related;
extern struct item_related prop_console_four_screen_related;
extern struct item_related prop_tv_holder_related;
extern struct item_related prop_rotating_stuff_related;
extern struct item_related prop_eyelid_door_related;
extern struct item_related prop_iris_door_related;
extern struct item_related prop_walletbond_related;
extern struct item_related prop_car_related;
extern struct item_related prop_flying_related;
extern struct item_related prop_door_related;
extern struct item_related item_tank_related;
extern struct item_related item_hat_related;
extern struct item_related model_object_standard_object;
extern struct item_related prop_weapon_related;
extern struct model_data model_guard_character;
extern struct player_gait_header player_gait_hdr;
extern struct player_gait_pos_header player_gait_pos_hdr_1;
extern struct player_gait_pos_header player_gait_pos_hdr_2;
extern struct player_gait_pos_header player_gait_pos_hdr_3;
extern struct player_gait_object_entry player_gait_obj;
extern struct player_gait_position_entry player_gait_pos_1;
extern struct player_gait_position_entry player_gait_pos_2;
extern struct player_gait_position_entry player_gait_pos_3;

extern struct object_header player_gait_object;

extern struct Gitemheader GwppkZ_struct;
extern struct Gitemheader GwppksilZ_struct;
extern struct Gitemheader Gtt33Z_struct;
extern struct Gitemheader GskorpianZ_struct;
extern struct Gitemheader Gak47Z_struct;
extern struct Gitemheader GuziZ_struct;
extern struct Gitemheader Gmp5kZ_struct;
extern struct Gitemheader Gmp5ksilZ_struct;
extern struct Gitemheader Gm16Z_struct;
extern struct Gitemheader Gfnp90Z_struct;
extern struct Gitemheader G8003C900_struct;
extern struct Gitemheader GrugerZ_struct;
extern struct Gitemheader GgoldengunZ_struct;
extern struct Gitemheader GshotgunZ_struct;
extern struct Gitemheader GautoshotZ_struct;
extern struct Gitemheader GgrenadelaunchZ_struct;
extern struct Gitemheader GspectreZ_struct;
extern struct Gitemheader GlaserZ_struct;
extern struct Gitemheader GrocketlaunchZ_struct;
extern struct Gitemheader GknifeZ_header;
extern struct Gitemheader GthrowknifeZ_struct;
extern struct Gitemheader GtaserZ_struct;
extern struct Gitemheader GremotemineZ_struct;
extern struct Gitemheader GproximitymineZ_struct;
extern struct Gitemheader GtimedmineZ_struct;
extern struct Gitemheader GtriggerZ_struct;
extern struct Gitemheader GgrenadeZ_struct;
extern struct Gitemheader GfistZ_header;
extern struct Gitemheader GsniperrifleZ_struct;
extern struct Gitemheader GcartridgeZ_struct;
extern struct Gitemheader GcartrifleZ_struct;
extern struct Gitemheader GcartblueZ_struct;
extern struct Gitemheader GcartshellZ_struct;
extern struct Gitemheader GjoypadZ_struct;
extern struct Gitemheader G8003CC00_struct;
extern struct Gitemheader G8003CC20_struct;
extern struct Gitemheader GbombcaseZ_struct;
extern struct Gitemheader GflarepistolZ_struct;
extern struct Gitemheader GpitongunZ_struct;
extern struct Gitemheader G8003CCA0_struct;
extern struct Gitemheader GsilverwppkZ_struct;
extern struct Gitemheader GgoldwppkZ_struct;
extern struct Gitemheader G8003CD00_struct;
extern struct Gitemheader GbungeeZ_struct;
extern struct Gitemheader GdoordecoderZ_struct;
extern struct Gitemheader GbombdefuserZ_struct;
extern struct Gitemheader GbugdetectorZ_struct;
extern struct Gitemheader GsafecrackercaseZ_struct;
extern struct Gitemheader GcameraZ_struct;
extern struct Gitemheader GlockexploderZ_struct;
extern struct Gitemheader GdoorexploderZ_struct;
extern struct Gitemheader GkeyanalysercaseZ_struct;
extern struct Gitemheader GweaponcaseZ_struct;
extern struct Gitemheader GkeycardZ_struct;
extern struct Gitemheader GkeyyaleZ_struct;
extern struct Gitemheader GkeyboltZ_struct;
extern struct Gitemheader GbugZ_struct;
extern struct Gitemheader GmicrocameraZ_struct;
extern struct Gitemheader GexplosivefloppyZ_struct;
extern struct Gitemheader GgoldeneyekeyZ_struct;
extern struct Gitemheader GpolarizedglassesZ_struct;
extern struct Gitemheader GcreditcardZ_struct;
extern struct Gitemheader GdarkglassesZ_struct;
extern struct Gitemheader GwatchidentifierZ_struct;
extern struct Gitemheader GwatchcommunicatorZ_struct;
extern struct Gitemheader GwatchlaserZ_struct;
extern struct Gitemheader GwatchgeigercounterZ_struct;
extern struct Gitemheader GwatchmagnetrepelZ_struct;
extern struct Gitemheader GwatchmagnetattractZ_struct;
extern struct Gitemheader GgaskeyringZ_struct;
extern struct Gitemheader GdatathiefZ_struct;
extern struct Gitemheader GbriefcaseZ_struct;
extern struct Gitemheader GblackboxZ_struct;
extern struct Gitemheader GplastiqueZ_struct;
extern struct Gitemheader GvideotapeZ_struct;
extern struct Gitemheader GclipboardZ_struct;
extern struct Gitemheader GstafflistZ_struct;
extern struct Gitemheader GdossierredZ_struct;
extern struct Gitemheader GaudiotapeZ_struct;
extern struct Gitemheader GdattapeZ_struct;
extern struct Gitemheader GplansZ_struct;
extern struct Gitemheader GspyfileZ_struct;
extern struct Gitemheader GblueprintsZ_struct;
extern struct Gitemheader GcircuitboardZ_struct;
extern struct Gitemheader GmapZ_struct;
extern struct Gitemheader GspooltapeZ_struct;
extern struct Gitemheader GmicrofilmZ_struct;
extern struct Gitemheader GmicrocodeZ_struct;
extern struct Gitemheader GlectreZ_struct;
extern struct Gitemheader GmoneyZ_struct;
extern struct Gitemheader GgoldbarZ_struct;
extern struct Gitemheader GheroinZ_struct;
extern struct model_data weapon_gun_controller;

extern struct object_header CcamguardZ_struct;
extern struct object_header CgreyguardZ_struct;
extern struct object_header ColiveguardZ_struct;
extern struct object_header CrusguardZ_struct;
extern struct object_header CtrevguardZ_struct;
extern struct object_header CborisZ_struct;
extern struct object_header CorumovZ_struct;
extern struct object_header CtrevelyanZ_struct;
extern struct object_header CboilertrevZ_struct;
extern struct object_header CvalentinZ_struct;
extern struct object_header CxeniaZ_struct;
extern struct object_header CbaronsamediZ_struct;
extern struct object_header CjawsZ_struct;
extern struct object_header CmaydayZ_struct;
extern struct object_header CoddjobZ_struct;
extern struct object_header CnatalyaZ_struct;
extern struct object_header CarmourguardZ_struct;
extern struct object_header CcommguardZ_struct;
extern struct object_header CgreatguardZ_struct;
extern struct object_header CnavyguardZ_struct;
extern struct object_header CsnowguardZ_struct;
extern struct object_header CbluewomanZ_struct;
extern struct object_header CfattechwomanZ_struct;
extern struct object_header CtechwomanZ_struct;
extern struct object_header CjeanwomanZ_struct;
extern struct object_header CgreymanZ_struct;
extern struct object_header CbluemanZ_struct;
extern struct object_header CredmanZ_struct;
extern struct object_header CcardimanZ_struct;
extern struct object_header CcheckmanZ_struct;
extern struct object_header CtechmanZ_struct;
extern struct object_header CpilotZ_struct;
extern struct object_header Cgreatguard2Z_struct;
extern struct object_header CbluecamguardZ_struct;
extern struct object_header CmoonguardZ_struct;
extern struct object_header CmoonfemaleZ_struct;
extern struct object_header CboilerbondZ_struct;
extern struct object_header CsuitbondZ_struct;
extern struct object_header CtimberbondZ_struct;
extern struct object_header CsnowbondZ_struct;
extern struct object_header CdjbondZ_struct;
extern struct object_header Csuit_lf_handz_struct;
extern struct object_header CheadkarlZ_struct;
extern struct object_header CheadalanZ_struct;
extern struct object_header CheadpeteZ_struct;
extern struct object_header CheadmartinZ_struct;
extern struct object_header stru_D_8003D9D0;
extern struct object_header stru_D_8003D9F0;
extern struct object_header stru_D_8003DA10;
extern struct object_header stru_D_8003DA30;
extern struct object_header stru_D_8003DA50;
extern struct object_header stru_D_8003DA70;
extern struct object_header stru_D_8003DA90;
extern struct object_header stru_D_8003DAB0;
extern struct object_header stru_D_8003DAD0;
extern struct object_header stru_D_8003DAF0;
extern struct object_header stru_D_8003DB10;
extern struct object_header stru_D_8003DB30;
extern struct object_header stru_D_8003DB50;
extern struct object_header stru_D_8003DB70;
extern struct object_header stru_D_8003DB90;
extern struct object_header stru_D_8003DBB0;
extern struct object_header stru_D_8003DBD0;
extern struct object_header stru_D_8003DBF0;
extern struct object_header stru_D_8003DC10;
extern struct object_header stru_D_8003DC30;
extern struct object_header stru_D_8003DC50;
extern struct object_header stru_D_8003DC70;
extern struct object_header stru_D_8003DC90;
extern struct object_header stru_D_8003DCB0;
extern struct object_header stru_D_8003DCD0;
extern struct object_header stru_D_8003DCF0;
extern struct object_header stru_D_8003DD10;
extern struct object_header stru_D_8003DD30;
extern struct object_header stru_D_8003DD50;
extern struct object_header CheadbrosnansuitZ_struct;
extern struct object_header CheadbrosnantimberZ_struct;
extern struct object_header CheadbrosnansnowZ_struct;
extern struct object_header CheadbrosnanZ_struct;
extern struct object_header CspicebondZ_struct;

#endif
