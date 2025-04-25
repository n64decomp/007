#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <bondconstants.h>
#include <deb.h>
#include <fr.h>
#include <memp.h>
#include "bg.h"
#include "bondview.h"
#include "debugmenu_handler.h"
#include "decompress.h"
#include "fog.h"
#include "lvl.h"
#include "math_ceil.h"
#include "matrixmath.h"
#include "player.h"
#include "explosions.h"
#include "unk_0BC530.h"


#define BG_STACK_SIZE 20

// bss
//CODE.bss:8007BF90
s32 ptr_bg_data;

//CODE.bss:8007BF94
s32 gptr_stan;

/**
 * address 8007BF98
 * EU .bss 80079ee8
*/
s32 dword_CODE_bss_8007BF98;

#ifdef VERSION_EU
s32 eu_bss_80079EEC;
#endif

/**
 * address 8007BFA0
 * EU .bss 80079ef0
*/
#ifdef VERSION_EU
char list_visible_rooms_in_cur_global_vis_packet[0x8c];
#else
char list_visible_rooms_in_cur_global_vis_packet[0x98];
#endif

/**
 * address 8007C038
 * EU .bss 80079f7c
*/
s32 num_visible_rooms_in_cur_global_vis_packet;

/**
 * address 8007C040
 * EU .bss 80079f80
*/
char bgDebPortalOutBuffer[10][9];

s16 bss_pad_8007C09A; /* not required, but making alignment explicit */
s32 bss_pad_8007C09C; /* not required, but making alignment explicit */

/**
 * address 8007C0A0
 * EU .bss 80079FE0
*/
char bgDebRoomOutBuffer[10][9];

s16 bss_pad_8007C0FA; /* not required, but making alignment explicit */
s32 bss_pad_8007C0FC; /* not required, but making alignment explicit */

/**
 * address 8007C100
 * EU .bss 8007A040
*/
#ifdef VERSION_EU
char dword_CODE_bss_8007C100[0x1388];
#else
char dword_CODE_bss_8007C100[0x3e80];
#endif

/**
 * address 8007FF80
 * EU .bss 8007B3C8
*/
bg_portal_data_entry* g_BgPortals;

//CODE.bss:8007FF84
s32 ptr_bgdata_offsets;

//CODE.bss:8007FF88
s32 dword_CODE_bss_8007FF88;

/**
 * address 8007FF8C
 * EU .bss 8007B3D4
*/
bg_room_data * ptr_bgdata_room_fileposition_list;

//CODE.bss:8007FF90
s32 dword_CODE_bss_8007FF90;

//CODE.bss:8007FF94
f32* dword_CODE_bss_8007FF94;

#ifndef VERSION_EU
//CODE.bss:8007FF98
s32 dword_CODE_bss_8007FF98;

//CODE.bss:8007FF9C
s32 dword_CODE_bss_8007FF9C;
#endif

#ifdef VERSION_EU
/* sizeof(struct s_bound_info) = 7 words */
/**
 * EU .bss 8007B3E0
*/
s_bound_info dword_CODE_bss_8007FFA0[124];
//this doesnt FEEL correct
u32 missingeubytes[4];
#else
s_bound_info dword_CODE_bss_8007FFA0[204];
#endif

// 7ca30??

s32 dword_CODE_bss_800815f0;
s32 dword_CODE_bss_800815f4;
s32 dword_CODE_bss_800815f8;

#ifdef VERSION_EU
s32 eu_bss_8007BFA0;
s32 eu_bss_8007BFA4;
#endif

/**
 * address 80081600
 * EU .bss 8007BFA8
*/
char dword_CODE_bss_80081600[0x18];

//CODE.bss:80081618
struct unk_portalstruct table_for_portals[200];


// data
/* D:800413F0 Level gCurrentLevel = {0, 1.0, 1.0, 1.0, 1}; cant check this
   anymore however will concede seperate vars since below gets match? */
s32 *ptr_bg_c_debug_debug_notice_list = 0;
//D:800413F4
f32 room_data_float1 = 1.0;
//D:800413F8
f32 room_data_float2 = 1.0;
//D:800413FC Private member - use bgGetLevelVisibilityScale outside this file
f32 mCurrentLevelVisibilityScale = 1.0;
//D:80041400
s32 levelentry_index = 1;

/**
 * Something related to player screen.
 * Maybe x, y, width, height.
 * DefaultScreenXMin = 1; //always 1 (related to getvideosettings) Xmin
 * DefaultScreenYMin = 1; //always 1 (related to getvideosettings)Ymin
 * SubtractFromWidth = -1; //always -1 (related to getvideosettings)
 * SubtractFromHeight = -1; //always -1 (related to getvideosettings)
 * Address 0x80041404.
 */
s32 bgViewRelated[] = { 1, 1, -1, -1 };


/**
 * Array of info about all the rooms on the level
 * Some info is different according to which player is being rendered
 * This array is also why there's a 150 is room limit
 * Canonical name: roominf
 * Address 0x80041414
*/
s_room_info g_BgRoomInfo[MAXROOMCOUNT] = {0};
//D:800442F4
s32 g_MaxNumRooms = MAXROOMCOUNT;


//D:800442F8
s32 D_800442F8 = 0;
//D:800442FC
s32 D_800442FC[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
//D:800443C4
s32 D_800443C4[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};



//D:8004448C
struct levelentry levelinfotable[] = {
/*  levelID;            bg_seg_filename;        bg_stan_filename;      levelscale;  visibility; unknownfloat;*/
    {LEVELID_BUNKER1,  "bg/bg_sev_all_p.seg",  "Tbg_sev_all_p_stanZ",  0.53931433,  1.0,        23.148148},
    {LEVELID_SILO,     "bg/bg_silo_all_p.seg", "Tbg_silo_all_p_stanZ", 0.47256002,  1.0,        29.069},
    {LEVELID_STATUE,   "bg/bg_stat_all_p.seg", "Tbg_stat_all_p_stanZ", 0.107202865, 1.0,        0.0801},
    {LEVELID_CONTROL,  "bg/bg_arec_all_p.seg", "Tbg_arec_all_p_stanZ", 0.49886572,  1.0,        80.645164},
    {LEVELID_ARCHIVES, "bg/bg_arch_all_p.seg", "Tbg_arch_all_p_stanZ", 0.50678575,  1.0,        54.347824},
    {LEVELID_TRAIN,    "bg/bg_tra_all_p.seg",  "Tbg_tra_all_p_stanZ",  0.15019713,  1.0,        19.53125},
    {LEVELID_FRIGATE,  "bg/bg_dest_all_p.seg", "Tbg_dest_all_p_stanZ", 0.44757429,  1.0,        36.764706},
    {LEVELID_BUNKER2,  "bg/bg_sevb_all_p.seg", "Tbg_sevb_all_p_stanZ", 0.53931433,  1.0,        23.148148},
    {LEVELID_AZTEC,    "bg/bg_azt_all_p.seg",  "Tbg_azt_all_p_stanZ",  0.35300568,  1.0,        52.083332},
    {LEVELID_STREETS,  "bg/bg_pete_all_p.seg", "Tbg_pete_all_p_stanZ", 0.34187999,  1.0,        42.372883},
    {LEVELID_DEPOT,    "bg/bg_depo_all_p.seg", "Tbg_depo_all_p_stanZ", 0.21847887,  1.0,        17.605633},
    {LEVELID_COMPLEX,  "bg/bg_ref_all_p.seg",  "Tbg_ref_all_p_stanZ",  0.94285715,  1.0,        37.878788},
    {LEVELID_EGYPT,    "bg/bg_cryp_all_p.seg", "Tbg_cryp_all_p_stanZ", 0.25608,     1.0,        23.584906},
    {LEVELID_DAM,      "bg/bg_dam_all_p.seg",  "Tbg_dam_all_p_stanZ",  0.23363999,  0.2,        100.0},
    {LEVELID_FACILITY, "bg/bg_ark_all_p.seg",  "Tbg_ark_all_p_stanZ",  1.20648,     1.0,        64.102562},
    {LEVELID_RUNWAY,   "bg/bg_run_all_p.seg",  "Tbg_run_all_p_stanZ",  0.089571431, 1.0,        4.5537338},
    {LEVELID_SURFACE,  "bg/bg_sevx_all_p.seg", "Tbg_sevx_all_p_stanZ", 0.45445713,  0.2,        22.603975},
    {LEVELID_JUNGLE,   "bg/bg_jun_all_p.seg",  "Tbg_jun_all_p_stanZ",  0.094662853, 1.0,        6.6844921},
    {LEVELID_TEMPLE,   "bg/bg_dish_all_p.seg", "Tbg_dish_all_p_stanZ", 0.47142857,  1.0,        147.05882},
    {LEVELID_CAVERNS,  "bg/bg_cave_all_p.seg", "Tbg_cave_all_p_stanZ", 0.26824287,  1.0,        13.44086},
    {LEVELID_CITADEL,  "bg/bg_cat_all_p.seg",  "Tbg_cat_all_p_stanZ",  0.76852286,  1.0,        38.461536},
    {LEVELID_CRADLE,   "bg/bg_crad_all_p.seg", "Tbg_crad_all_p_stanZ", 0.23571429,  1.0,        43.103451},
    {LEVELID_SHO,      "bg/bg_sho_all_p.seg",  "Tbg_sho_all_p_stanZ",  0.528,       1.0,        21.18644},
    {LEVELID_SURFACE2, "bg/bg_sevx_all_p.seg", "Tbg_sevx_all_p_stanZ", 0.45445713,  0.2,        22.603975},
    {LEVELID_ELD,      "bg/bg_eld_all_p.seg",  "Tbg_eld_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_BASEMENT, "bg/bg_ame_all_p.seg",  "Tbg_ame_all_p_stanZ",  0.65999997,  1.0,        37.878788},
    {LEVELID_STACK,    "bg/bg_ame_all_p.seg",  "Tbg_ame_all_p_stanZ",  0.65999997,  1.0,        37.878788},
    {LEVELID_LUE,      "bg/bg_lue_all_p.seg",  "Tbg_lue_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_LIBRARY,  "bg/bg_ame_all_p.seg",  "Tbg_ame_all_p_stanZ",  0.65999997,  1.0,        37.878788},
    {LEVELID_RIT,      "bg/bg_rit_all_p.seg",  "Tbg_rit_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_CAVES,    "bg/bg_oat_all_p.seg",  "Tbg_oat_all_p_stanZ",  0.14142857,  1.0,        10.123456},
    {LEVELID_EAR,      "bg/bg_ear_all_p.seg",  "Tbg_ear_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_LEE,      "bg/bg_lee_all_p.seg",  "Tbg_lee_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_LIP,      "bg/bg_lip_all_p.seg",  "Tbg_lip_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_CUBA,     "bg/bg_len_all_p.seg",  "Tbg_len_all_p_stanZ",  0.094662853, 1.0,        6.6844921},
    {LEVELID_WAX,      "bg/bg_wax_all_p.seg",  "Tbg_wax_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_PAM,      "bg/bg_pam_all_p.seg",  "Tbg_pam_all_p_stanZ",  0.94285715,  1.0,        10.123456},
    {LEVELID_MAX,      "bg/bgx.seg",           "TbgxZ",                0.94285715,  1.0,        1.0}
};

//D:8004481C
u32 D_8004481C[] = {0x1000100, 0};

//D:80044824
s_specialportal specialportalarray[] = {
    {0x03,
        {0x2C,0x2E,0x32, 0x37,0x3E,0x3F,0x4E, 0x56,0x59,0x5D,0x72, 0x76,0x79,0x7A,0xFF}},
    {0x11,
        {0x00,0x3A,0xFF}}
};

/**
 * Bond's current room.
 * Address 0x80044838
*/
s32 g_BgCurrentRoom = 1;

/**
 * Total number of rooms drawn for the current frame.
 * Address 0x8004483C
*/
s32 g_BgNumberOfRoomsDrawn = 0;

#if defined(VERSION_EU)
s32 eu_cdata_0x1f0d0 = 0;
s32 eu_cdata_0x1f0d4 = 0;
#endif

//D:80044840
Lights1 GlobalLight = gdSPDefLights1(
    150,150,150,        /* ambient color grey */ //D:80044840
    255,255,255,
    77,77,46    /* white light from the upper west-south-west (42 up, 244') */ //D:80044848
);



//D:80044858
s32 D_80044858 = 0;
//D:8004485C
s32 D_8004485C = 1;
//D:80044860
s32 bgDebPortalOutLineNum = 0;
//D:80044864
s32 bgDebRoomOutLineNum = 0;
//D:80044868
s32 D_80044868 = 0x7FFF;
//D:8004486C
s32 D_8004486C = 0x7FFF;
//D:80044870
s32 D_80044870 = 0x7FFF;
//D:80044874
s32 D_80044874 = 0xFFFF8000;
//D:80044878
s32 D_80044878 = 0xFFFF8000;
//D:8004487C
s32 D_8004487C = 0xFFFF8000;
//D:80044880
s32 D_80044880 = 0x7FFF;
//D:80044884
s32 D_80044884 = 0x7FFF;
//D:80044888
s32 D_80044888 = 0x7FFF;
//D:8004488C
s32 D_8004488C = 0xFFFF8000;
//D:80044890
s32 D_80044890 = 0xFFFF8000;
//D:80044894
s32 D_80044894 = 0xFFFF8000;
//D:80044898
s32 D_80044898 = 0;
//D:8004489C
s32 D_8004489C = 0xF;
//D:800448A0
s32 D_800448A0 = 0;
//D:800448A4
s32 D_800448A4 = 0;

/**
 * Local stack.
 *
 * Address 0x800448A8.
 */
s32 g_BgStack[BG_STACK_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**
 * Current top of the stack.
 *
 * Address 0x800448F8.
 */
s32 g_BgStackCount = 0;

//D:800448FC
s32 current_visibility = 0;

//D:80044900
f32 D_80044900 = 0;

//D:80044904
s32 D_80044904 = 0x7F7FFFFF;
//D:80044908
s32 D_80044908 = 0x7F7FFFFF;
//D:8004490C
s32 D_8004490C = 0x7F7FFFFF;
//D:80044910
s32 D_80044910 = 0xFF7FFFFF;
//D:80044914
s32 D_80044914 = 0xFF7FFFFF;
//D:80044918
s32 D_80044918 = 0xFF7FFFFF;
//D:8004491C
u32 D_8004491C = 0;
//D:80044920
u32 D_80044920 = 0;
//D:80044924
u32 D_80044924 = 0;

#if defined(VERSION_EU)
s32 eu_cdata_0x1f1c0 = 0;
s32 eu_cdata_0x1f1c4 = 0;
#endif

// forward declarations

void unload_rooms(void);
Gfx *sub_GAME_7F0B8D78(Gfx *arg0);
Gfx *sub_GAME_7F0B3C8C(Gfx *arg0);
s32 bgCheckIfRoomModelNeedsLoad(s32 roomID);
void sub_GAME_7F0B6368(s32 room);
Gfx *sub_GAME_7F0B677C(Gfx *arg0, s32 room_index);
Gfx *sub_GAME_7F0B6898(Gfx *arg0, s32 room_index);

Gfx *bgScissorCurrentPlayerView(Gfx *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

// end forward declarations


/*
    //###RenderMode / Combiner Look - Up - Tables
    The reason for this LUT is to dynamicly change the rendermode and combiner to
    FOG / NoFog or any other setting they might have wanted to test during development
    as it applies during runtime

//###Reminder:
    1cycle combiners repeat both cycles
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA2)

    combiner macros are a list of parameters that form a mathematical sum.
                            (       -  )*     +  ,  (       -  )*     +
    G_CC_MODULATERGBA2	    COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0
*/
#if 0
//New Defines to be added to gbi.h
/*custom combiner for triangle alpha*/
#define	ModulateRGB_EnvA 	TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
/*custom combiner for triangle alpha*/
#define	ModulateRGB_EnvA2 	COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
/*custom combiner for Texture*triangle alpha*/
#define	ModulateRGBA_EnvA 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0
/*custom combiner for texture*triangle alpha*/
#define	ModulateRGBA_EnvA2 	COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0
/*custom combiner for triangle alpha*/
#define	SHADE_EnvA 		    0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
/*Tri-linear filter colour, flat tile alpha (for cutouts)*/
#define TLRGB_ATile1        TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0
#endif
//D:80044928
Gfx DL_LUT_UNKNOWN[] = {
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, 0, SCALE, 0,  TEXEL1, 0, PRIM_LOD_FRAC, 0,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    0,0
};

//D:80044940 - Primary
Gfx DL_LUT_PRIMARY_ADDFOG[] = {
    //Add FOG to all rendermodes
    //Standard HiQuality Surface to Standard Fogable HiQuality Surface
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    //Terrain to Fogable Terrain
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_TERR2),
    //Standard DECAL to FOG DECAL
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
    //Transparent DECAL to  FOG Transparent DECAL
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    //Transparent Surface to FOG Transparent Surface
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    // Billboard Cut-out to FOG Billboard Cut-out - eg, Mario Tree or Depot lamp
    // See PGDLists\Transparent Textures.htm for more info
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    //Standard Z-Less OPA to Standard FOG Z-Less OPA
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_SURF2),
    //Z-Less OPA Terrain to Z-Less Fog OPA Terrain
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_TERR2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_TERR2),
    0x0, 0x0
};

//D:800449C8 - Secondary
Gfx DL_LUT_SECONDARY_ADDFOG[] = {
    //Add FOG to Rendermodes
    //Transparent DECAL to  FOG Transparent DECAL
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    //Transparent Surface to FOG Transparent Surface
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),

    // Billboard Cut-out to FOG Billboard Cut-out - eg, Mario Tree or Depot lamp
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),

    // Swap all refrences to Shade in Alpha to Environment
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),//gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT), //gsDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_SHADE_EnvA),
    // This one is an oddball... its extra here AND is weird using Tile1 only for Alpha
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    0x0,
    0x0
};

//D:80044AB0
// Loaded once on first time entering level, only once ever
// Swap all refrences to Shade in Alpha to Environment
Gfx DL_LUT_PRIMARY[] = {
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT),
    0,0
};

//D:80044B58
// Loaded once on first time entering level, only once ever
// Swap all refrences to Shade in Alpha to Environment
Gfx DL_LUT_SECONDARY[] = {
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT,  0, 0, 0, SHADE,  0, 0, 0, ENVIRONMENT),
    0,0
};

//D:80044C00
Gfx DL_LUT_BILLBOARD[] = {
    //Transparent 1Cycle to  BillBoard 1Cycle
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2), gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    //Transparent Surface to Billboard
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2), gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    0x0,0x0
};

//D:80044C28
//water
Gfx DL_LUT_WATER[] = {
    0xB900031D, 0x00552078, 0xB900031D, 0x00502078,
    0xB900031D, 0x0C192078, 0xB900031D, 0x0C182078,
    /*
    //1 Cycle Opa to Particle
    gsDPSetRenderMode(RM_AA_ZB_OPA_SURF, RM_AA_ZB_OPA_SURF2), gDPSetRenderMode(G_RM_AA_ZB_PCL_SURF, G_RM_AA_ZB_PCL_SURF2),
    //2 cycle Opa to Particle
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2), gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_PCL_SURF2),
    */
    0x0, 0
};

//D:80044C50
Gfx DL_LUT_CLOUD[] = {
    //Transparent to Cloud (Saves AA - Stops Jaggies from appearing behind BillBoard)
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2), gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    0,0
};

//D:80044C68
//(Wallet Bond - Main Menu)
Gfx DL_LUT_WALLETBOND[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCycleType(G_CYC_2CYCLE), //1Cycle --> 2Cycle
    0xB900031D, 0x00502048,
    0xB900031D, 0x08D02048,
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    /*
    //1 Cycle particle Surface to 2 Cycle colour + 1-a*Fog ???
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_AA_PCL_SURF, G_RM_AA_PCL_SURF2), gDPSetRenderMode(AA_EN | IM_RD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_OPA | GBL_c1(G_BL_CLR_IN, G_BL_A_SHADE, G_BL_CLR_FOG, G_BL_1MA) | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_PASS2), gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2),
    */
    0x0, 0
};

//D:80044CA0
Gfx DL_LUT_FIXFOGALPHA3[] = {
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SCALE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE,  TEXEL0, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT,  TEXEL0, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0,  TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, SCALE, 0,  TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(CENTER, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT,  CENTER, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SCALE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  COMBINED, 0, SCALE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SCALE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  0, 0, 0, SHADE),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  1, 0, TEXEL1, 0,  COMBINED, 0, SCALE, 0,  COMBINED, 0, ENVIRONMENT, 0),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    gsDPSetCombineLERP(CENTER, 0, SCALE, 0,  0, 0, 0, ENVIRONMENT,  0, 0, 0, COMBINED,  0, 0, 0, COMBINED),
    0,0
};

//D:80044D88
Gfx *ptrDynamic_CC_RM_LUT[] = {
    &DL_LUT_UNKNOWN, &DL_LUT_PRIMARY_ADDFOG, &DL_LUT_BILLBOARD, &DL_LUT_WATER, &DL_LUT_CLOUD,
    &DL_LUT_SECONDARY_ADDFOG, &DL_LUT_PRIMARY, &DL_LUT_SECONDARY, &DL_LUT_WALLETBOND, &DL_LUT_FIXFOGALPHA3
};



// rodata




void bgInit(void) {
    debTryAdd(&ptr_bg_c_debug_debug_notice_list, "bg_c_debug");
}





#ifdef NONMATCHING
// 91.60% mostly reg alloc
// https://decomp.me/scratch/puCqt
void sub_GAME_7F0B37EC(void) {
    s_specialportal* currentPortal;
    u8* portalList;
    u8 portalId;
    s32 portalIndex;
    s32 portalIndex2;
    bg_portal_data_entry* portalData;
    u8 controlByte;
    u8 tempByte;

    currentPortal = specialportalarray;
    do {
        portalList = currentPortal->portallist;
        if (levelentry_index == currentPortal->levelid) {
            portalId = *portalList;
            do {
                portalIndex = portalId & 0xFF;
                portalIndex2 = portalIndex;
                if ((s32) portalList[1] >= portalIndex) {
                    do {
                        portalData = &g_BgPortals[portalIndex2];
                        controlByte = portalData->controlbytes1;
                        portalIndex2 = (portalIndex + 1) & 0xFF;
                        portalIndex = portalIndex2;
                        portalData->controlbytes1 = controlByte | 2;
                    } while ((s32) portalList[1] >= portalIndex2);
                }
                portalId = portalList[2];
                portalList += 2;
            } while (portalId != 0xFF);
        } else {
            do {
                tempByte = portalList[2];
                portalList += 2;
            } while (tempByte != 0xFF);
        }
        currentPortal = (s_specialportal* ) (portalList + 1);
    } while ((u32) currentPortal < (u32) &g_BgCurrentRoom);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B37EC
/* 0E831C 7F0B37EC 3C028004 */  lui   $v0, %hi(specialportalarray)
/* 0E8320 7F0B37F0 3C038004 */  lui   $v1, %hi(g_BgCurrentRoom)
/* 0E8324 7F0B37F4 3C088008 */  lui   $t0, %hi(g_BgPortals)
/* 0E8328 7F0B37F8 3C078004 */  lui   $a3, %hi(levelentry_index)
/* 0E832C 7F0B37FC 24424824 */  addiu $v0, %lo(specialportalarray) # addiu $v0, $v0, 0x4824
/* 0E8330 7F0B3800 24634838 */  addiu $v1, %lo(g_BgCurrentRoom) # addiu $v1, $v1, 0x4838
/* 0E8334 7F0B3804 24E71400 */  addiu $a3, %lo(levelentry_index) # addiu $a3, $a3, 0x1400
/* 0E8338 7F0B3808 2508FF80 */  addiu $t0, %lo(g_BgPortals) # addiu $t0, $t0, -0x80
/* 0E833C 7F0B380C 240900FF */  li    $t1, 255
/* 0E8340 7F0B3810 8CEE0000 */  lw    $t6, ($a3)
.L7F0B3814:
/* 0E8344 7F0B3814 904F0000 */  lbu   $t7, ($v0)
/* 0E8348 7F0B3818 24420001 */  addiu $v0, $v0, 1
/* 0E834C 7F0B381C 55CF001C */  bnel  $t6, $t7, .L7F0B3890
/* 0E8350 7F0B3820 904F0002 */   lbu   $t7, 2($v0)
/* 0E8354 7F0B3824 90440000 */  lbu   $a0, ($v0)
/* 0E8358 7F0B3828 90580001 */  lbu   $t8, 1($v0)
.L7F0B382C:
/* 0E835C 7F0B382C 308500FF */  andi  $a1, $a0, 0xff
/* 0E8360 7F0B3830 00A03025 */  move  $a2, $a1
/* 0E8364 7F0B3834 0305082A */  slt   $at, $t8, $a1
/* 0E8368 7F0B3838 5420000F */  bnezl $at, .L7F0B3878
/* 0E836C 7F0B383C 90440002 */   lbu   $a0, 2($v0)
/* 0E8370 7F0B3840 8D190000 */  lw    $t9, ($t0)
.L7F0B3844:
/* 0E8374 7F0B3844 000650C0 */  sll   $t2, $a2, 3
/* 0E8378 7F0B3848 24A50001 */  addiu $a1, $a1, 1
/* 0E837C 7F0B384C 032A2021 */  addu  $a0, $t9, $t2
/* 0E8380 7F0B3850 908B0006 */  lbu   $t3, 6($a0)
/* 0E8384 7F0B3854 30A600FF */  andi  $a2, $a1, 0xff
/* 0E8388 7F0B3858 00C02825 */  move  $a1, $a2
/* 0E838C 7F0B385C 356C0002 */  ori   $t4, $t3, 2
/* 0E8390 7F0B3860 A08C0006 */  sb    $t4, 6($a0)
/* 0E8394 7F0B3864 904E0001 */  lbu   $t6, 1($v0)
/* 0E8398 7F0B3868 01C6082A */  slt   $at, $t6, $a2
/* 0E839C 7F0B386C 5020FFF5 */  beql  $at, $zero, .L7F0B3844
/* 0E83A0 7F0B3870 8D190000 */   lw    $t9, ($t0)
/* 0E83A4 7F0B3874 90440002 */  lbu   $a0, 2($v0)
.L7F0B3878:
/* 0E83A8 7F0B3878 24420002 */  addiu $v0, $v0, 2
/* 0E83AC 7F0B387C 5524FFEB */  bnel  $t1, $a0, .L7F0B382C
/* 0E83B0 7F0B3880 90580001 */   lbu   $t8, 1($v0)
/* 0E83B4 7F0B3884 10000006 */  b     .L7F0B38A0
/* 0E83B8 7F0B3888 24420001 */   addiu $v0, $v0, 1
/* 0E83BC 7F0B388C 904F0002 */  lbu   $t7, 2($v0)
.L7F0B3890:
/* 0E83C0 7F0B3890 24420002 */  addiu $v0, $v0, 2
/* 0E83C4 7F0B3894 552FFFFE */  bnel  $t1, $t7, .L7F0B3890
/* 0E83C8 7F0B3898 904F0002 */   lbu   $t7, 2($v0)
/* 0E83CC 7F0B389C 24420001 */  addiu $v0, $v0, 1
.L7F0B38A0:
/* 0E83D0 7F0B38A0 0043082B */  sltu  $at, $v0, $v1
/* 0E83D4 7F0B38A4 5420FFDB */  bnezl $at, .L7F0B3814
/* 0E83D8 7F0B38A8 8CEE0000 */   lw    $t6, ($a3)
/* 0E83DC 7F0B38AC 03E00008 */  jr    $ra
/* 0E83E0 7F0B38B0 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B38B4(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B38B4
/* 0E83E4 7F0B38B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E83E8 7F0B38B8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0E83EC 7F0B38BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E83F0 7F0B38C0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0E83F4 7F0B38C4 00A08025 */  move  $s0, $a1
/* 0E83F8 7F0B38C8 90A20000 */  lbu   $v0, ($a1)
/* 0E83FC 7F0B38CC 308300FF */  andi  $v1, $a0, 0xff
/* 0E8400 7F0B38D0 02002025 */  move  $a0, $s0
.L7F0B38D4:
/* 0E8404 7F0B38D4 1062000B */  beq   $v1, $v0, .L7F0B3904
/* 0E8408 7F0B38D8 00000000 */   nop
/* 0E840C 7F0B38DC 92020001 */  lbu   $v0, 1($s0)
/* 0E8410 7F0B38E0 26100001 */  addiu $s0, $s0, 1
/* 0E8414 7F0B38E4 1440FFFB */  bnez  $v0, .L7F0B38D4
/* 0E8418 7F0B38E8 00000000 */   nop
/* 0E841C 7F0B38EC 920E0001 */  lbu   $t6, 1($s0)
.L7F0B38F0:
/* 0E8420 7F0B38F0 26100001 */  addiu $s0, $s0, 1
/* 0E8424 7F0B38F4 55C0FFFE */  bnezl $t6, .L7F0B38F0
/* 0E8428 7F0B38F8 920E0001 */   lbu   $t6, 1($s0)
/* 0E842C 7F0B38FC 10000027 */  b     .L7F0B399C
/* 0E8430 7F0B3900 26100001 */   addiu $s0, $s0, 1
.L7F0B3904:
/* 0E8434 7F0B3904 3C118008 */  lui   $s1, %hi(g_CurrentPlayer)
/* 0E8438 7F0B3908 00808025 */  move  $s0, $a0
/* 0E843C 7F0B390C 2631A0B0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x5f50
/* 0E8440 7F0B3910 90820000 */  lbu   $v0, ($a0)
/* 0E8444 7F0B3914 8E250000 */  lw    $a1, ($s1)
.L7F0B3918:
/* 0E8448 7F0B3918 00402025 */  move  $a0, $v0
/* 0E844C 7F0B391C 0FC2D482 */  jal   sub_GAME_7F0B5208
/* 0E8450 7F0B3920 24A51118 */   addiu $a1, $a1, 0x1118
/* 0E8454 7F0B3924 10400006 */  beqz  $v0, .L7F0B3940
/* 0E8458 7F0B3928 00002825 */   move  $a1, $zero
/* 0E845C 7F0B392C 8E260000 */  lw    $a2, ($s1)
/* 0E8460 7F0B3930 92040000 */  lbu   $a0, ($s0)
/* 0E8464 7F0B3934 24070001 */  li    $a3, 1
/* 0E8468 7F0B3938 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0E846C 7F0B393C 24C61118 */   addiu $a2, $a2, 0x1118
.L7F0B3940:
/* 0E8470 7F0B3940 92020001 */  lbu   $v0, 1($s0)
/* 0E8474 7F0B3944 26100001 */  addiu $s0, $s0, 1
/* 0E8478 7F0B3948 5440FFF3 */  bnezl $v0, .L7F0B3918
/* 0E847C 7F0B394C 8E250000 */   lw    $a1, ($s1)
/* 0E8480 7F0B3950 26100001 */  addiu $s0, $s0, 1
/* 0E8484 7F0B3954 92020000 */  lbu   $v0, ($s0)
/* 0E8488 7F0B3958 8E250000 */  lw    $a1, ($s1)
.L7F0B395C:
/* 0E848C 7F0B395C 00402025 */  move  $a0, $v0
/* 0E8490 7F0B3960 0FC2D482 */  jal   sub_GAME_7F0B5208
/* 0E8494 7F0B3964 24A51118 */   addiu $a1, $a1, 0x1118
/* 0E8498 7F0B3968 10400006 */  beqz  $v0, .L7F0B3984
/* 0E849C 7F0B396C 00002825 */   move  $a1, $zero
/* 0E84A0 7F0B3970 8E260000 */  lw    $a2, ($s1)
/* 0E84A4 7F0B3974 92040000 */  lbu   $a0, ($s0)
/* 0E84A8 7F0B3978 24070001 */  li    $a3, 1
/* 0E84AC 7F0B397C 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0E84B0 7F0B3980 24C61118 */   addiu $a2, $a2, 0x1118
.L7F0B3984:
/* 0E84B4 7F0B3984 92020001 */  lbu   $v0, 1($s0)
/* 0E84B8 7F0B3988 26100001 */  addiu $s0, $s0, 1
/* 0E84BC 7F0B398C 5440FFF3 */  bnezl $v0, .L7F0B395C
/* 0E84C0 7F0B3990 8E250000 */   lw    $a1, ($s1)
/* 0E84C4 7F0B3994 10000005 */  b     .L7F0B39AC
/* 0E84C8 7F0B3998 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0B399C:
/* 0E84CC 7F0B399C 92020000 */  lbu   $v0, ($s0)
/* 0E84D0 7F0B39A0 5440FFCC */  bnezl $v0, .L7F0B38D4
/* 0E84D4 7F0B39A4 02002025 */   move  $a0, $s0
/* 0E84D8 7F0B39A8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0B39AC:
/* 0E84DC 7F0B39AC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0E84E0 7F0B39B0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0E84E4 7F0B39B4 03E00008 */  jr    $ra
/* 0E84E8 7F0B39B8 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B38B4
/* 0E5564 7F0B2B74 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E5568 7F0B2B78 AFB00014 */  sw    $s0, 0x14($sp)
/* 0E556C 7F0B2B7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E5570 7F0B2B80 AFB10018 */  sw    $s1, 0x18($sp)
/* 0E5574 7F0B2B84 00A08025 */  move  $s0, $a1
/* 0E5578 7F0B2B88 90A20000 */  lbu   $v0, ($a1)
/* 0E557C 7F0B2B8C 308300FF */  andi  $v1, $a0, 0xff
/* 0E5580 7F0B2B90 02002025 */  move  $a0, $s0
.L7F0B2B94:
/* 0E5584 7F0B2B94 1062000B */  beq   $v1, $v0, .L7F0B2BC4
/* 0E5588 7F0B2B98 00000000 */   nop
/* 0E558C 7F0B2B9C 92020001 */  lbu   $v0, 1($s0)
/* 0E5590 7F0B2BA0 26100001 */  addiu $s0, $s0, 1
/* 0E5594 7F0B2BA4 1440FFFB */  bnez  $v0, .L7F0B2B94
/* 0E5598 7F0B2BA8 00000000 */   nop
/* 0E559C 7F0B2BAC 920E0001 */  lbu   $t6, 1($s0)
.L7F0B2BB0:
/* 0E55A0 7F0B2BB0 26100001 */  addiu $s0, $s0, 1
/* 0E55A4 7F0B2BB4 55C0FFFE */  bnezl $t6, .L7F0B2BB0
/* 0E55A8 7F0B2BB8 920E0001 */   lbu   $t6, 1($s0)
/* 0E55AC 7F0B2BBC 10000027 */  b     .L7F0B2C5C
/* 0E55B0 7F0B2BC0 26100001 */   addiu $s0, $s0, 1
.L7F0B2BC4:
/* 0E55B4 7F0B2BC4 3C118007 */  lui   $s1, %hi(g_CurrentPlayer) # $s1, 0x8007
/* 0E55B8 7F0B2BC8 00808025 */  move  $s0, $a0
/* 0E55BC 7F0B2BCC 26318BC0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x7440
/* 0E55C0 7F0B2BD0 90820000 */  lbu   $v0, ($a0)
/* 0E55C4 7F0B2BD4 8E250000 */  lw    $a1, ($s1)
.L7F0B2BD8:
/* 0E55C8 7F0B2BD8 00402025 */  move  $a0, $v0
/* 0E55CC 7F0B2BDC 0FC2D151 */  jal   sub_GAME_7F0B5208
/* 0E55D0 7F0B2BE0 24A51110 */   addiu $a1, $a1, 0x1110
/* 0E55D4 7F0B2BE4 10400006 */  beqz  $v0, .L7F0B2C00
/* 0E55D8 7F0B2BE8 00002825 */   move  $a1, $zero
/* 0E55DC 7F0B2BEC 8E260000 */  lw    $a2, ($s1)
/* 0E55E0 7F0B2BF0 92040000 */  lbu   $a0, ($s0)
/* 0E55E4 7F0B2BF4 24070001 */  li    $a3, 1
/* 0E55E8 7F0B2BF8 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0E55EC 7F0B2BFC 24C61110 */   addiu $a2, $a2, 0x1110
.L7F0B2C00:
/* 0E55F0 7F0B2C00 92020001 */  lbu   $v0, 1($s0)
/* 0E55F4 7F0B2C04 26100001 */  addiu $s0, $s0, 1
/* 0E55F8 7F0B2C08 5440FFF3 */  bnezl $v0, .L7F0B2BD8
/* 0E55FC 7F0B2C0C 8E250000 */   lw    $a1, ($s1)
/* 0E5600 7F0B2C10 26100001 */  addiu $s0, $s0, 1
/* 0E5604 7F0B2C14 92020000 */  lbu   $v0, ($s0)
/* 0E5608 7F0B2C18 8E250000 */  lw    $a1, ($s1)
.L7F0B2C1C:
/* 0E560C 7F0B2C1C 00402025 */  move  $a0, $v0
/* 0E5610 7F0B2C20 0FC2D151 */  jal   sub_GAME_7F0B5208
/* 0E5614 7F0B2C24 24A51110 */   addiu $a1, $a1, 0x1110
/* 0E5618 7F0B2C28 10400006 */  beqz  $v0, .L7F0B2C44
/* 0E561C 7F0B2C2C 00002825 */   move  $a1, $zero
/* 0E5620 7F0B2C30 8E260000 */  lw    $a2, ($s1)
/* 0E5624 7F0B2C34 92040000 */  lbu   $a0, ($s0)
/* 0E5628 7F0B2C38 24070001 */  li    $a3, 1
/* 0E562C 7F0B2C3C 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0E5630 7F0B2C40 24C61110 */   addiu $a2, $a2, 0x1110
.L7F0B2C44:
/* 0E5634 7F0B2C44 92020001 */  lbu   $v0, 1($s0)
/* 0E5638 7F0B2C48 26100001 */  addiu $s0, $s0, 1
/* 0E563C 7F0B2C4C 5440FFF3 */  bnezl $v0, .L7F0B2C1C
/* 0E5640 7F0B2C50 8E250000 */   lw    $a1, ($s1)
/* 0E5644 7F0B2C54 10000005 */  b     .L7F0B2C6C
/* 0E5648 7F0B2C58 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0B2C5C:
/* 0E564C 7F0B2C5C 92020000 */  lbu   $v0, ($s0)
/* 0E5650 7F0B2C60 5440FFCC */  bnezl $v0, .L7F0B2B94
/* 0E5654 7F0B2C64 02002025 */   move  $a0, $s0
/* 0E5658 7F0B2C68 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0B2C6C:
/* 0E565C 7F0B2C6C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0E5660 7F0B2C70 8FB10018 */  lw    $s1, 0x18($sp)
/* 0E5664 7F0B2C74 03E00008 */  jr    $ra
/* 0E5668 7F0B2C78 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif
#endif





#ifdef NONMATCHING
/**
 * Address 0x7F0B39BC.
 *
 * decomp status:
 * - compiles: ?
 * - stack resize: ?
 * - identical instructions: fail
 * - identical registers: fail
 *
 * https://decomp.me/scratch/GKQcb
 *
*/
s32 sub_GAME_7F0B39BC(int curroom,int unk1, bbox2d * screensize, s32 next)
{
    int i;
    int temp;

    g_BgRoomInfo[curroom].room_rendered = '\x01';

    if (g_BgRoomInfo[curroom].room_loaded_mask != '\0') {
        return 0;
    }

    // Need g_BgNumberOfRoomsDrawn in a3
    for (i = 0; i < g_BgNumberOfRoomsDrawn; i++)
    {
        if (curroom == dword_CODE_bss_8007FFA0[i].roomid) {
            if (dword_CODE_bss_8007FFA0[i].unk1 < unk1) {
                dword_CODE_bss_8007FFA0[i].unk1 = unk1;
            }
            sub_GAME_7F0B5CC0(screensize,&dword_CODE_bss_8007FFA0[i].bbox);
            temp = dword_CODE_bss_8007FFA0[i].next;
            dword_CODE_bss_8007FFA0[i].bbox.min.x = screensize->min.x;
            dword_CODE_bss_8007FFA0[i].bbox.min.y = screensize->min.y;
            dword_CODE_bss_8007FFA0[i].bbox.max.x = screensize->max.x;
            dword_CODE_bss_8007FFA0[i].bbox.max.y = screensize->max.y;
            dword_CODE_bss_8007FFA0[i].next = temp | next;

            return temp;
        }
    }
    
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].roomid = curroom;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].unk1 = unk1;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].bbox.min.x = screensize->min.x;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].bbox.min.y = screensize->min.y;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].bbox.max.x = screensize->max.x;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].bbox.max.y = screensize->max.y;
    dword_CODE_bss_8007FFA0[g_BgNumberOfRoomsDrawn].next = next;
    g_BgNumberOfRoomsDrawn++;

    // FAKE puts g_BgNumberOfRoomsDrawn in a3
    if (g_BgNumberOfRoomsDrawn) {}
    
    return 0;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B39BC
/* 0E84EC 7F0B39BC 00047080 */  sll   $t6, $a0, 2
/* 0E84F0 7F0B39C0 01C47021 */  addu  $t6, $t6, $a0
/* 0E84F4 7F0B39C4 3C0F8004 */  lui   $t7, %hi(g_BgRoomInfo)
/* 0E84F8 7F0B39C8 25EF1414 */  addiu $t7, %lo(g_BgRoomInfo) # addiu $t7, $t7, 0x1414
/* 0E84FC 7F0B39CC 000E7100 */  sll   $t6, $t6, 4
/* 0E8500 7F0B39D0 01CF1021 */  addu  $v0, $t6, $t7
/* 0E8504 7F0B39D4 90590034 */  lbu   $t9, 0x34($v0)
/* 0E8508 7F0B39D8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E850C 7F0B39DC AFB00018 */  sw    $s0, 0x18($sp)
/* 0E8510 7F0B39E0 24180001 */  li    $t8, 1
/* 0E8514 7F0B39E4 00808025 */  move  $s0, $a0
/* 0E8518 7F0B39E8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E851C 7F0B39EC AFA7003C */  sw    $a3, 0x3c($sp)
/* 0E8520 7F0B39F0 13200003 */  beqz  $t9, .L7F0B3A00
/* 0E8524 7F0B39F4 A0580000 */   sb    $t8, ($v0)
/* 0E8528 7F0B39F8 1000003D */  b     .L7F0B3AF0
/* 0E852C 7F0B39FC 00001025 */   move  $v0, $zero
.L7F0B3A00:
/* 0E8530 7F0B3A00 3C078004 */  lui   $a3, %hi(g_BgNumberOfRoomsDrawn)
/* 0E8534 7F0B3A04 24E7483C */  addiu $a3, %lo(g_BgNumberOfRoomsDrawn) # addiu $a3, $a3, 0x483c
/* 0E8538 7F0B3A08 8CE40000 */  lw    $a0, ($a3)
/* 0E853C 7F0B3A0C 00001025 */  move  $v0, $zero
/* 0E8540 7F0B3A10 3C0D8008 */  lui   $t5, %hi(dword_CODE_bss_8007FFA0)
/* 0E8544 7F0B3A14 18800023 */  blez  $a0, .L7F0B3AA4
/* 0E8548 7F0B3A18 000460C0 */   sll   $t4, $a0, 3
/* 0E854C 7F0B3A1C 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007FFA0)
/* 0E8550 7F0B3A20 2463FFA0 */  addiu $v1, %lo(dword_CODE_bss_8007FFA0) # addiu $v1, $v1, -0x60
.L7F0B3A24:
/* 0E8554 7F0B3A24 8C680000 */  lw    $t0, ($v1)
/* 0E8558 7F0B3A28 24420001 */  addiu $v0, $v0, 1
/* 0E855C 7F0B3A2C 0044082A */  slt   $at, $v0, $a0
/* 0E8560 7F0B3A30 1608001A */  bne   $s0, $t0, .L7F0B3A9C
/* 0E8564 7F0B3A34 00000000 */   nop
/* 0E8568 7F0B3A38 8C690004 */  lw    $t1, 4($v1)
/* 0E856C 7F0B3A3C 00C02025 */  move  $a0, $a2
/* 0E8570 7F0B3A40 0125082A */  slt   $at, $t1, $a1
/* 0E8574 7F0B3A44 50200003 */  beql  $at, $zero, .L7F0B3A54
/* 0E8578 7F0B3A48 24650008 */   addiu $a1, $v1, 8
/* 0E857C 7F0B3A4C AC650004 */  sw    $a1, 4($v1)
/* 0E8580 7F0B3A50 24650008 */  addiu $a1, $v1, 8
.L7F0B3A54:
/* 0E8584 7F0B3A54 AFA30020 */  sw    $v1, 0x20($sp)
/* 0E8588 7F0B3A58 0FC2D730 */  jal   sub_GAME_7F0B5CC0
/* 0E858C 7F0B3A5C AFA60038 */   sw    $a2, 0x38($sp)
/* 0E8590 7F0B3A60 8FA60038 */  lw    $a2, 0x38($sp)
/* 0E8594 7F0B3A64 8FA30020 */  lw    $v1, 0x20($sp)
/* 0E8598 7F0B3A68 8FAA003C */  lw    $t2, 0x3c($sp)
/* 0E859C 7F0B3A6C C4C40000 */  lwc1  $f4, ($a2)
/* 0E85A0 7F0B3A70 8C620018 */  lw    $v0, 0x18($v1)
/* 0E85A4 7F0B3A74 E4640008 */  swc1  $f4, 8($v1)
/* 0E85A8 7F0B3A78 C4C60004 */  lwc1  $f6, 4($a2)
/* 0E85AC 7F0B3A7C 004A5825 */  or    $t3, $v0, $t2
/* 0E85B0 7F0B3A80 E466000C */  swc1  $f6, 0xc($v1)
/* 0E85B4 7F0B3A84 C4C80008 */  lwc1  $f8, 8($a2)
/* 0E85B8 7F0B3A88 E4680010 */  swc1  $f8, 0x10($v1)
/* 0E85BC 7F0B3A8C C4CA000C */  lwc1  $f10, 0xc($a2)
/* 0E85C0 7F0B3A90 AC6B0018 */  sw    $t3, 0x18($v1)
/* 0E85C4 7F0B3A94 10000016 */  b     .L7F0B3AF0
/* 0E85C8 7F0B3A98 E46A0014 */   swc1  $f10, 0x14($v1)
.L7F0B3A9C:
/* 0E85CC 7F0B3A9C 1420FFE1 */  bnez  $at, .L7F0B3A24
/* 0E85D0 7F0B3AA0 2463001C */   addiu $v1, $v1, 0x1c
.L7F0B3AA4:
/* 0E85D4 7F0B3AA4 01846023 */  subu  $t4, $t4, $a0
/* 0E85D8 7F0B3AA8 000C6080 */  sll   $t4, $t4, 2
/* 0E85DC 7F0B3AAC 25ADFFA0 */  addiu $t5, %lo(dword_CODE_bss_8007FFA0) # addiu $t5, $t5, -0x60
/* 0E85E0 7F0B3AB0 018D1821 */  addu  $v1, $t4, $t5
/* 0E85E4 7F0B3AB4 AC700000 */  sw    $s0, ($v1)
/* 0E85E8 7F0B3AB8 AC650004 */  sw    $a1, 4($v1)
/* 0E85EC 7F0B3ABC C4D00000 */  lwc1  $f16, ($a2)
/* 0E85F0 7F0B3AC0 8FAE003C */  lw    $t6, 0x3c($sp)
/* 0E85F4 7F0B3AC4 248F0001 */  addiu $t7, $a0, 1
/* 0E85F8 7F0B3AC8 E4700008 */  swc1  $f16, 8($v1)
/* 0E85FC 7F0B3ACC C4D20004 */  lwc1  $f18, 4($a2)
/* 0E8600 7F0B3AD0 00001025 */  move  $v0, $zero
/* 0E8604 7F0B3AD4 E472000C */  swc1  $f18, 0xc($v1)
/* 0E8608 7F0B3AD8 C4C40008 */  lwc1  $f4, 8($a2)
/* 0E860C 7F0B3ADC E4640010 */  swc1  $f4, 0x10($v1)
/* 0E8610 7F0B3AE0 C4C6000C */  lwc1  $f6, 0xc($a2)
/* 0E8614 7F0B3AE4 ACEF0000 */  sw    $t7, ($a3)
/* 0E8618 7F0B3AE8 AC6E0018 */  sw    $t6, 0x18($v1)
/* 0E861C 7F0B3AEC E4660014 */  swc1  $f6, 0x14($v1)
.L7F0B3AF0:
/* 0E8620 7F0B3AF0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8624 7F0B3AF4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E8628 7F0B3AF8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0E862C 7F0B3AFC 03E00008 */  jr    $ra
/* 0E8630 7F0B3B00 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B39BC
/* 0E566C 7F0B2C7C 00047080 */  sll   $t6, $a0, 2
/* 0E5670 7F0B2C80 01C47021 */  addu  $t6, $t6, $a0
/* 0E5674 7F0B2C84 3C0F8004 */  lui   $t7, %hi(g_BgRoomInfo) # $t7, 0x8004
/* 0E5678 7F0B2C88 25EFAC64 */  addiu $t7, %lo(g_BgRoomInfo) # addiu $t7, $t7, -0x539c
/* 0E567C 7F0B2C8C 000E7100 */  sll   $t6, $t6, 4
/* 0E5680 7F0B2C90 01CF1021 */  addu  $v0, $t6, $t7
/* 0E5684 7F0B2C94 90590034 */  lbu   $t9, 0x34($v0)
/* 0E5688 7F0B2C98 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E568C 7F0B2C9C AFB00018 */  sw    $s0, 0x18($sp)
/* 0E5690 7F0B2CA0 24180001 */  li    $t8, 1
/* 0E5694 7F0B2CA4 00808025 */  move  $s0, $a0
/* 0E5698 7F0B2CA8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E569C 7F0B2CAC AFA50034 */  sw    $a1, 0x34($sp)
/* 0E56A0 7F0B2CB0 13200003 */  beqz  $t9, .L7F0B2CC0
/* 0E56A4 7F0B2CB4 A0580000 */   sb    $t8, ($v0)
/* 0E56A8 7F0B2CB8 10000049 */  b     .L7F0B2DE0
/* 0E56AC 7F0B2CBC 00001025 */   move  $v0, $zero
.L7F0B2CC0:
/* 0E56B0 7F0B2CC0 3C088004 */  lui   $t0, %hi(g_BgNumberOfRoomsDrawn) # $t0, 0x8004
/* 0E56B4 7F0B2CC4 2508DD1C */  addiu $t0, %lo(g_BgNumberOfRoomsDrawn) # addiu $t0, $t0, -0x22e4
/* 0E56B8 7F0B2CC8 8D040000 */  lw    $a0, ($t0)
/* 0E56BC 7F0B2CCC 3C0E8007 */  lui   $t6, %hi(dword_CODE_bss_8007FFA0) # $t6, 0x8007
/* 0E56C0 7F0B2CD0 00001025 */  move  $v0, $zero
/* 0E56C4 7F0B2CD4 18800025 */  blez  $a0, .L7F0B2D6C
/* 0E56C8 7F0B2CD8 25CEB3E0 */   addiu $t6, %lo(dword_CODE_bss_8007FFA0) # addiu $t6, $t6, -0x4c20
/* 0E56CC 7F0B2CDC 3C038007 */  lui   $v1, %hi(dword_CODE_bss_8007FFA0) # $v1, 0x8007
/* 0E56D0 7F0B2CE0 2463B3E0 */  addiu $v1, %lo(dword_CODE_bss_8007FFA0) # addiu $v1, $v1, -0x4c20
.L7F0B2CE4:
/* 0E56D4 7F0B2CE4 90690000 */  lbu   $t1, ($v1)
/* 0E56D8 7F0B2CE8 24420001 */  addiu $v0, $v0, 1
/* 0E56DC 7F0B2CEC 0044082A */  slt   $at, $v0, $a0
/* 0E56E0 7F0B2CF0 1609001C */  bne   $s0, $t1, .L7F0B2D64
/* 0E56E4 7F0B2CF4 00000000 */   nop
/* 0E56E8 7F0B2CF8 846A0002 */  lh    $t2, 2($v1)
/* 0E56EC 7F0B2CFC 8FAB0034 */  lw    $t3, 0x34($sp)
/* 0E56F0 7F0B2D00 00C02025 */  move  $a0, $a2
/* 0E56F4 7F0B2D04 24650008 */  addiu $a1, $v1, 8
/* 0E56F8 7F0B2D08 014B082A */  slt   $at, $t2, $t3
/* 0E56FC 7F0B2D0C 50200003 */  beql  $at, $zero, .L7F0B2D1C
/* 0E5700 7F0B2D10 AFA30020 */   sw    $v1, 0x20($sp)
/* 0E5704 7F0B2D14 A46B0002 */  sh    $t3, 2($v1)
/* 0E5708 7F0B2D18 AFA30020 */  sw    $v1, 0x20($sp)
.L7F0B2D1C:
/* 0E570C 7F0B2D1C AFA60038 */  sw    $a2, 0x38($sp)
/* 0E5710 7F0B2D20 0FC2D3FF */  jal   sub_GAME_7F0B5CC0
/* 0E5714 7F0B2D24 AFA7003C */   sw    $a3, 0x3c($sp)
/* 0E5718 7F0B2D28 8FA60038 */  lw    $a2, 0x38($sp)
/* 0E571C 7F0B2D2C 8FA30020 */  lw    $v1, 0x20($sp)
/* 0E5720 7F0B2D30 8FA7003C */  lw    $a3, 0x3c($sp)
/* 0E5724 7F0B2D34 C4C40000 */  lwc1  $f4, ($a2)
/* 0E5728 7F0B2D38 90620004 */  lbu   $v0, 4($v1)
/* 0E572C 7F0B2D3C E4640008 */  swc1  $f4, 8($v1)
/* 0E5730 7F0B2D40 C4C60004 */  lwc1  $f6, 4($a2)
/* 0E5734 7F0B2D44 00476025 */  or    $t4, $v0, $a3
/* 0E5738 7F0B2D48 E466000C */  swc1  $f6, 0xc($v1)
/* 0E573C 7F0B2D4C C4C80008 */  lwc1  $f8, 8($a2)
/* 0E5740 7F0B2D50 E4680010 */  swc1  $f8, 0x10($v1)
/* 0E5744 7F0B2D54 C4CA000C */  lwc1  $f10, 0xc($a2)
/* 0E5748 7F0B2D58 A06C0004 */  sb    $t4, 4($v1)
/* 0E574C 7F0B2D5C 10000020 */  b     .L7F0B2DE0
/* 0E5750 7F0B2D60 E46A0014 */   swc1  $f10, 0x14($v1)
.L7F0B2D64:
/* 0E5754 7F0B2D64 1420FFDF */  bnez  $at, .L7F0B2CE4
/* 0E5758 7F0B2D68 24630018 */   addiu $v1, $v1, 0x18
.L7F0B2D6C:
/* 0E575C 7F0B2D6C 28810078 */  slti  $at, $a0, 0x78
/* 0E5760 7F0B2D70 14200002 */  bnez  $at, .L7F0B2D7C
/* 0E5764 7F0B2D74 00801025 */   move  $v0, $a0
/* 0E5768 7F0B2D78 24020077 */  li    $v0, 119
.L7F0B2D7C:
/* 0E576C 7F0B2D7C 00026880 */  sll   $t5, $v0, 2
/* 0E5770 7F0B2D80 01A26823 */  subu  $t5, $t5, $v0
/* 0E5774 7F0B2D84 8FAF0034 */  lw    $t7, 0x34($sp)
/* 0E5778 7F0B2D88 000D68C0 */  sll   $t5, $t5, 3
/* 0E577C 7F0B2D8C 01AE1821 */  addu  $v1, $t5, $t6
/* 0E5780 7F0B2D90 A0700000 */  sb    $s0, ($v1)
/* 0E5784 7F0B2D94 A46F0002 */  sh    $t7, 2($v1)
/* 0E5788 7F0B2D98 C4D00000 */  lwc1  $f16, ($a2)
/* 0E578C 7F0B2D9C 3C048004 */  lui   $a0, %hi(eu_cdata_0x1f0d0) # $a0, 0x8004
/* 0E5790 7F0B2DA0 2484DD20 */  addiu $a0, %lo(eu_cdata_0x1f0d0) # addiu $a0, $a0, -0x22e0
/* 0E5794 7F0B2DA4 E4700008 */  swc1  $f16, 8($v1)
/* 0E5798 7F0B2DA8 C4D20004 */  lwc1  $f18, 4($a2)
/* 0E579C 7F0B2DAC 8C980000 */  lw    $t8, ($a0)
/* 0E57A0 7F0B2DB0 00001025 */  move  $v0, $zero
/* 0E57A4 7F0B2DB4 E472000C */  swc1  $f18, 0xc($v1)
/* 0E57A8 7F0B2DB8 C4C40008 */  lwc1  $f4, 8($a2)
/* 0E57AC 7F0B2DBC 27190001 */  addiu $t9, $t8, 1
/* 0E57B0 7F0B2DC0 2B210078 */  slti  $at, $t9, 0x78
/* 0E57B4 7F0B2DC4 E4640010 */  swc1  $f4, 0x10($v1)
/* 0E57B8 7F0B2DC8 C4C6000C */  lwc1  $f6, 0xc($a2)
/* 0E57BC 7F0B2DCC A0670004 */  sb    $a3, 4($v1)
/* 0E57C0 7F0B2DD0 AC990000 */  sw    $t9, ($a0)
/* 0E57C4 7F0B2DD4 10200002 */  beqz  $at, .L7F0B2DE0
/* 0E57C8 7F0B2DD8 E4660014 */   swc1  $f6, 0x14($v1)
/* 0E57CC 7F0B2DDC AD190000 */  sw    $t9, ($t0)
.L7F0B2DE0:
/* 0E57D0 7F0B2DE0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E57D4 7F0B2DE4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E57D8 7F0B2DE8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0E57DC 7F0B2DEC 03E00008 */  jr    $ra
/* 0E57E0 7F0B2DF0 00000000 */   nop
)
#endif

#endif




void bgZeroPortalsToRoom(s32 roomnum)
{
  g_BgRoomInfo[roomnum].portals_to_room_count = '\0';
}







s32 sub_GAME_7F0B3B20(void)
{
    s32 i;

    for (i=0;i<MAXROOMCOUNT;i++)
    {
        if (g_BgRoomInfo[i].portals_to_room_count) {
            return i;
        };
    }
    return -1;
}





#ifdef NONMATCHING
//unrolled sb are in reverse order
void sub_GAME_7F0B3BC4(void)
{
  s32 i;

  g_BgNumberOfRoomsDrawn = 0;
  for (i=0;i!=MAXROOMCOUNT;i++)
  {
    g_BgRoomInfo[i].portals_to_room_count = '\0';
  }
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3BC4
/* 0E86F4 7F0B3BC4 3C018004 */  lui   $at, %hi(g_BgNumberOfRoomsDrawn)
/* 0E86F8 7F0B3BC8 AC20483C */  sw    $zero, %lo(g_BgNumberOfRoomsDrawn)($at)
/* 0E86FC 7F0B3BCC 3C018004 */  lui   $at, %hi(g_BgRoomInfo+0x3)
/* 0E8700 7F0B3BD0 A0201417 */  sb    $zero, %lo(g_BgRoomInfo+0x3)($at)
/* 0E8704 7F0B3BD4 3C018004 */  lui   $at, %hi(g_BgRoomInfo + 0x53)
/* 0E8708 7F0B3BD8 3C038004 */  lui   $v1, %hi(g_BgRoomInfo + 0xA0)
/* 0E870C 7F0B3BDC 3C028004 */  lui   $v0, %hi(g_MaxNumRooms)
/* 0E8710 7F0B3BE0 244242F4 */  addiu $v0, %lo(g_MaxNumRooms) # addiu $v0, $v0, 0x42f4
/* 0E8714 7F0B3BE4 246314B4 */  addiu $v1, %lo(g_BgRoomInfo + 0xA0) # addiu $v1, $v1, 0x14b4
/* 0E8718 7F0B3BE8 A0201467 */  sb    $zero, %lo(g_BgRoomInfo + 0x53)($at)
.L7F0B3BEC:
/* 0E871C 7F0B3BEC 24630140 */  addiu $v1, $v1, 0x140
/* 0E8720 7F0B3BF0 A060FEC3 */  sb    $zero, -0x13d($v1)
/* 0E8724 7F0B3BF4 A060FF13 */  sb    $zero, -0xed($v1)
/* 0E8728 7F0B3BF8 A060FF63 */  sb    $zero, -0x9d($v1)
/* 0E872C 7F0B3BFC 1462FFFB */  bne   $v1, $v0, .L7F0B3BEC
/* 0E8730 7F0B3C00 A060FFB3 */   sb    $zero, -0x4d($v1)
/* 0E8734 7F0B3C04 03E00008 */  jr    $ra
/* 0E8738 7F0B3C08 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3BC4
/* 0E58BC 7F0B2ECC 3C018004 */  lui   $at, %hi(g_BgNumberOfRoomsDrawn) # $at, 0x8004
/* 0E58C0 7F0B2ED0 AC20DD1C */  sw    $zero, %lo(g_BgNumberOfRoomsDrawn)($at)
/* 0E58C4 7F0B2ED4 3C018004 */  lui   $at, %hi(eu_cdata_0x1f0d0) # $at, 0x8004
/* 0E58C8 7F0B2ED8 AC20DD20 */  sw    $zero, %lo(eu_cdata_0x1f0d0)($at)
/* 0E58CC 7F0B2EDC 3C018004 */  lui   $at, %hi(g_BgRoomInfo+0x3) # $at, 0x8004
/* 0E58D0 7F0B2EE0 A020AC67 */  sb    $zero, %lo(g_BgRoomInfo+0x3)($at)
/* 0E58D4 7F0B2EE4 3C018004 */  lui   $at, %hi(g_BgRoomInfo + 0x53) # $at, 0x8004
/* 0E58D8 7F0B2EE8 A020ACB7 */  sb    $zero, %lo(g_BgRoomInfo + 0x53)($at)
/* 0E58DC 7F0B2EEC 3C018004 */  lui   $at, %hi(g_BgRoomInfo + 0xA3) # $at, 0x8004
/* 0E58E0 7F0B2EF0 3C038004 */  lui   $v1, %hi(g_BgRoomInfo + 0xf0) # $v1, 0x8004
/* 0E58E4 7F0B2EF4 3C028004 */  lui   $v0, %hi(g_MaxNumRooms) # $v0, 0x8004
/* 0E58E8 7F0B2EF8 2442D7D4 */  addiu $v0, %lo(g_MaxNumRooms) # addiu $v0, $v0, -0x282c
/* 0E58EC 7F0B2EFC 2463AD54 */  addiu $v1, %lo(g_BgRoomInfo + 0xf0) # addiu $v1, $v1, -0x52ac
/* 0E58F0 7F0B2F00 A020AD07 */  sb    $zero, %lo(g_BgRoomInfo + 0xA3)($at)
.L7F0B2F04:
/* 0E58F4 7F0B2F04 24630140 */  addiu $v1, $v1, 0x140
/* 0E58F8 7F0B2F08 A060FEC3 */  sb    $zero, -0x13d($v1)
/* 0E58FC 7F0B2F0C A060FF13 */  sb    $zero, -0xed($v1)
/* 0E5900 7F0B2F10 A060FF63 */  sb    $zero, -0x9d($v1)
/* 0E5904 7F0B2F14 1462FFFB */  bne   $v1, $v0, .L7F0B2F04
/* 0E5908 7F0B2F18 A060FFB3 */   sb    $zero, -0x4d($v1)
/* 0E590C 7F0B2F1C 03E00008 */  jr    $ra
/* 0E5910 7F0B2F20 00000000 */   nop
)
#endif


#endif




/**
 * Searches dword_CODE_bss_8007FFA0 for matching id.
 * If found, sets result to 2d bbox and returns 1.
 * Otherwise result is set to empty 2d bbox and returns 0.
 *
 * @param room_id: room id to search for.
 * @param result: Out parameter. Contains result 2d bbox.
 *
 * Address 0x7F0B3C0C.
*/
s32 bgGet2dBboxByRoomId(s32 room_id, struct bbox2d *result)
{
    s32 i;
    for (i=0; i<g_BgNumberOfRoomsDrawn; i++)
    {
        if (room_id == dword_CODE_bss_8007FFA0[i].roomid)
        {
            result->f[0][0] = dword_CODE_bss_8007FFA0[i].bbox.f[0][0];
            result->f[0][1] = dword_CODE_bss_8007FFA0[i].bbox.f[0][1];
            result->f[1][0] = dword_CODE_bss_8007FFA0[i].bbox.f[1][0];
            result->f[1][1] = dword_CODE_bss_8007FFA0[i].bbox.f[1][1];

            return 1;
        }
    }

    result->f[0][0] = 0.0f;
    result->f[0][1] = 0.0f;
    result->f[1][0] = 0.0f;
    result->f[1][1] = 0.0f;

    return 0;
}





#ifdef NONMATCHING
/**
 * Address 0x7F0B3C8C.
 *
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * Should be equivalent.
 * https://decomp.me/scratch/hw6En
 *
 * notes: can't read g_BgNumberOfRoomsDrawn the correct number of times.
*/
Gfx *sub_GAME_7F0B3C8C(Gfx *gdl)
{
    s32 i;
    s32 j;
    s32 b_max;
    s32 b_min;
    b_min = 99999999;
    b_max = 0;

    for (j=0; j<g_BgNumberOfRoomsDrawn; j++)
    {
        b_max = (b_max < dword_CODE_bss_8007FFA0[j].unk1) ? dword_CODE_bss_8007FFA0[j].unk1 : b_max;
        b_min = (dword_CODE_bss_8007FFA0[j].unk1 < b_min) ? dword_CODE_bss_8007FFA0[j].unk1 : b_min;
    }

    for (i=b_min; i <= b_max; i++)
    {
#ifdef DEBUG
notdone = g_BgNumberOfRoomsDrawn;
#endif

        for (j=0; j<g_BgNumberOfRoomsDrawn; j++)
        {
            if (i == dword_CODE_bss_8007FFA0[j].unk1)
            {
                gSPMatrix(gdl++, osVirtualToPhysical((void*)currentPlayerGetProjectionMatrix()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
                gdl = fogRenderClearFogMode(gdl);

                if (get_debug_do_draw_obj())
                {
                    if (sub_GAME_7F0BD8F0())
                    {
                        gdl = chrpropsRenderPass(gdl, dword_CODE_bss_8007FFA0[j].roomid, 0);
                    }
                }

                gSPMatrix(gdl++, osVirtualToPhysical((void*)get_BONDdata_field_10E0()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
                gdl = fogSetRenderFogColor(
                    bgScissorCurrentPlayerViewF(
                        gdl++,
                        dword_CODE_bss_8007FFA0[j].bbox.f[0][0],
                        dword_CODE_bss_8007FFA0[j].bbox.f[0][1],
                        dword_CODE_bss_8007FFA0[j].bbox.f[1][0],
                        dword_CODE_bss_8007FFA0[j].bbox.f[1][1]),
                    0);

                if (get_debug_do_draw_bg())
                {
                    if (sub_GAME_7F0BD8F0())
                    {
                        gdl = sub_GAME_7F0B677C(gdl, dword_CODE_bss_8007FFA0[j].roomid);
                    }
                }

                gSPMatrix(gdl++, osVirtualToPhysical((void*)currentPlayerGetProjectionMatrix()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
                gdl = fogRenderClearFogMode(gdl);

                if (get_debug_do_draw_obj())
                {
                    if (sub_GAME_7F0BD8F0())
                    {
                        gdl = chrpropsRenderPass(gdl, dword_CODE_bss_8007FFA0[j].roomid, 2);
                    }
                }
            }
            #ifdef DEBUG
notdone --;
#endif

        }
    }
    #ifdef DEBUG
    assert(notdone==0);
    #endif

    gdl = bgScissorCurrentPlayerViewDefault(fogRenderClearFogMode(gdl));
    gSPMatrix(gdl++, osVirtualToPhysical((void*)get_BONDdata_field_10E0()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));

    if (sub_GAME_7F0BD8F0())
    {
        gdl = explosionCallRenderBulletImpactOnProp(explosionRenderScorchBuffer(gdl));
    }

    for (i=b_max; i >= b_min; i--)
    {
   #ifdef DEBUG
notdone = g_BgNumberOfRoomsDrawn;
#endif


        for (j=0; j<g_BgNumberOfRoomsDrawn; j++)
        {
            if (i == dword_CODE_bss_8007FFA0[j].unk1)
            {
                gSPMatrix(gdl++, osVirtualToPhysical((void*)get_BONDdata_field_10E0()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
                gdl = fogSetRenderFogColor(
                    bgScissorCurrentPlayerViewF(
                        gdl++,
                        dword_CODE_bss_8007FFA0[j].bbox.f[0][0],
                        dword_CODE_bss_8007FFA0[j].bbox.f[0][1],
                        dword_CODE_bss_8007FFA0[j].bbox.f[1][0],
                        dword_CODE_bss_8007FFA0[j].bbox.f[1][1]),
                    1);

                if (get_debug_do_draw_bg())
                {
                    if (sub_GAME_7F0BD8F0())
                    {
                        gdl = sub_GAME_7F0B6898(gdl, dword_CODE_bss_8007FFA0[j].roomid);
                    }
                }

                gSPMatrix(gdl++, osVirtualToPhysical((void*)currentPlayerGetProjectionMatrix()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
                gdl = fogRenderClearFogMode(gdl);

                if (get_debug_do_draw_obj())
                {
                    if (sub_GAME_7F0BD8F0())
                    {
                        gdl = chrpropsRenderPass(gdl, dword_CODE_bss_8007FFA0[j].roomid, 1);
                    }
                }
            }
            #ifdef DEBUG
notdone --;
#endif

        }
    }
        #ifdef DEBUG
    assert(notdone==0);
    #endif

    return gdl;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3C8C
/* 0E87BC 7F0B3C8C 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0E87C0 7F0B3C90 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn)
/* 0E87C4 7F0B3C94 8C42483C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E87C8 7F0B3C98 AFB70038 */  sw    $s7, 0x38($sp)
/* 0E87CC 7F0B3C9C AFB60034 */  sw    $s6, 0x34($sp)
/* 0E87D0 7F0B3CA0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0E87D4 7F0B3CA4 3C1705F5 */  lui   $s7, (0x05F5E0FF >> 16) # lui $s7, 0x5f5
/* 0E87D8 7F0B3CA8 00808025 */  move  $s0, $a0
/* 0E87DC 7F0B3CAC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E87E0 7F0B3CB0 AFB50030 */  sw    $s5, 0x30($sp)
/* 0E87E4 7F0B3CB4 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0E87E8 7F0B3CB8 AFB30028 */  sw    $s3, 0x28($sp)
/* 0E87EC 7F0B3CBC AFB20024 */  sw    $s2, 0x24($sp)
/* 0E87F0 7F0B3CC0 AFB10020 */  sw    $s1, 0x20($sp)
/* 0E87F4 7F0B3CC4 36F7E0FF */  ori   $s7, (0x05F5E0FF & 0xFFFF) # ori $s7, $s7, 0xe0ff
/* 0E87F8 7F0B3CC8 18400014 */  blez  $v0, .L7F0B3D1C
/* 0E87FC 7F0B3CCC 0000B025 */   move  $s6, $zero
/* 0E8800 7F0B3CD0 000278C0 */  sll   $t7, $v0, 3
/* 0E8804 7F0B3CD4 01E27823 */  subu  $t7, $t7, $v0
/* 0E8808 7F0B3CD8 3C0E8008 */  lui   $t6, %hi(dword_CODE_bss_8007FFA0)
/* 0E880C 7F0B3CDC 25D2FFA0 */  addiu $s2, $t6, %lo(dword_CODE_bss_8007FFA0)
/* 0E8810 7F0B3CE0 000F7880 */  sll   $t7, $t7, 2
/* 0E8814 7F0B3CE4 01F22021 */  addu  $a0, $t7, $s2
/* 0E8818 7F0B3CE8 8E430004 */  lw    $v1, 4($s2)
.L7F0B3CEC:
/* 0E881C 7F0B3CEC 2652001C */  addiu $s2, $s2, 0x1c
/* 0E8820 7F0B3CF0 02C3082A */  slt   $at, $s6, $v1
/* 0E8824 7F0B3CF4 50200003 */  beql  $at, $zero, .L7F0B3D04
/* 0E8828 7F0B3CF8 0077082A */   slt   $at, $v1, $s7
/* 0E882C 7F0B3CFC 0060B025 */  move  $s6, $v1
/* 0E8830 7F0B3D00 0077082A */  slt   $at, $v1, $s7
.L7F0B3D04:
/* 0E8834 7F0B3D04 50200003 */  beql  $at, $zero, .L7F0B3D14
/* 0E8838 7F0B3D08 0244082B */   sltu  $at, $s2, $a0
/* 0E883C 7F0B3D0C 0060B825 */  move  $s7, $v1
/* 0E8840 7F0B3D10 0244082B */  sltu  $at, $s2, $a0
.L7F0B3D14:
/* 0E8844 7F0B3D14 5420FFF5 */  bnezl $at, .L7F0B3CEC
/* 0E8848 7F0B3D18 8E430004 */   lw    $v1, 4($s2)
.L7F0B3D1C:
/* 0E884C 7F0B3D1C 02D7082A */  slt   $at, $s6, $s7
/* 0E8850 7F0B3D20 1420005C */  bnez  $at, .L7F0B3E94
/* 0E8854 7F0B3D24 02E0A825 */   move  $s5, $s7
/* 0E8858 7F0B3D28 26D80001 */  addiu $t8, $s6, 1
/* 0E885C 7F0B3D2C 3C140103 */  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
/* 0E8860 7F0B3D30 36940040 */  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
/* 0E8864 7F0B3D34 AFB80044 */  sw    $t8, 0x44($sp)
.L7F0B3D38:
/* 0E8868 7F0B3D38 18400052 */  blez  $v0, .L7F0B3E84
/* 0E886C 7F0B3D3C 00009825 */   move  $s3, $zero
/* 0E8870 7F0B3D40 3C128008 */  lui   $s2, %hi(dword_CODE_bss_8007FFA0)
/* 0E8874 7F0B3D44 2652FFA0 */  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x60
.L7F0B3D48:
/* 0E8878 7F0B3D48 8E590004 */  lw    $t9, 4($s2)
/* 0E887C 7F0B3D4C 02008825 */  move  $s1, $s0
/* 0E8880 7F0B3D50 56B90049 */  bnel  $s5, $t9, .L7F0B3E78
/* 0E8884 7F0B3D54 26730001 */   addiu $s3, $s3, 1
/* 0E8888 7F0B3D58 26100008 */  addiu $s0, $s0, 8
/* 0E888C 7F0B3D5C 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0E8890 7F0B3D60 AE340000 */   sw    $s4, ($s1)
/* 0E8894 7F0B3D64 0C003A2C */  jal   osVirtualToPhysical
/* 0E8898 7F0B3D68 00402025 */   move  $a0, $v0
/* 0E889C 7F0B3D6C AE220004 */  sw    $v0, 4($s1)
/* 0E88A0 7F0B3D70 0FC2ECA6 */  jal   fogRenderClearFogMode
/* 0E88A4 7F0B3D74 02002025 */   move  $a0, $s0
/* 0E88A8 7F0B3D78 0FC243D3 */  jal   get_debug_do_draw_obj
/* 0E88AC 7F0B3D7C 00408025 */   move  $s0, $v0
/* 0E88B0 7F0B3D80 5040000A */  beql  $v0, $zero, .L7F0B3DAC
/* 0E88B4 7F0B3D84 02008825 */   move  $s1, $s0
/* 0E88B8 7F0B3D88 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E88BC 7F0B3D8C 00000000 */   nop
/* 0E88C0 7F0B3D90 10400005 */  beqz  $v0, .L7F0B3DA8
/* 0E88C4 7F0B3D94 02002025 */   move  $a0, $s0
/* 0E88C8 7F0B3D98 8E450000 */  lw    $a1, ($s2)
/* 0E88CC 7F0B3D9C 0FC0E9BD */  jal   chrpropsRenderPass
/* 0E88D0 7F0B3DA0 00003025 */   move  $a2, $zero
/* 0E88D4 7F0B3DA4 00408025 */  move  $s0, $v0
.L7F0B3DA8:
/* 0E88D8 7F0B3DA8 02008825 */  move  $s1, $s0
.L7F0B3DAC:
/* 0E88DC 7F0B3DAC AE340000 */  sw    $s4, ($s1)
/* 0E88E0 7F0B3DB0 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0E88E4 7F0B3DB4 26100008 */   addiu $s0, $s0, 8
/* 0E88E8 7F0B3DB8 0C003A2C */  jal   osVirtualToPhysical
/* 0E88EC 7F0B3DBC 00402025 */   move  $a0, $v0
/* 0E88F0 7F0B3DC0 AE220004 */  sw    $v0, 4($s1)
/* 0E88F4 7F0B3DC4 C6440014 */  lwc1  $f4, 0x14($s2)
/* 0E88F8 7F0B3DC8 8E470010 */  lw    $a3, 0x10($s2)
/* 0E88FC 7F0B3DCC 8E46000C */  lw    $a2, 0xc($s2)
/* 0E8900 7F0B3DD0 8E450008 */  lw    $a1, 8($s2)
/* 0E8904 7F0B3DD4 02002025 */  move  $a0, $s0
/* 0E8908 7F0B3DD8 0FC2D3FD */  jal   bgScissorCurrentPlayerViewF
/* 0E890C 7F0B3DDC E7A40010 */   swc1  $f4, 0x10($sp)
/* 0E8910 7F0B3DE0 00402025 */  move  $a0, $v0
/* 0E8914 7F0B3DE4 0FC2EC1C */  jal   fogSetRenderFogColor
/* 0E8918 7F0B3DE8 00002825 */   move  $a1, $zero
/* 0E891C 7F0B3DEC 0FC243D0 */  jal   get_debug_do_draw_bg
/* 0E8920 7F0B3DF0 00408025 */   move  $s0, $v0
/* 0E8924 7F0B3DF4 50400009 */  beql  $v0, $zero, .L7F0B3E1C
/* 0E8928 7F0B3DF8 02008825 */   move  $s1, $s0
/* 0E892C 7F0B3DFC 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E8930 7F0B3E00 00000000 */   nop
/* 0E8934 7F0B3E04 10400004 */  beqz  $v0, .L7F0B3E18
/* 0E8938 7F0B3E08 02002025 */   move  $a0, $s0
/* 0E893C 7F0B3E0C 0FC2D9DF */  jal   sub_GAME_7F0B677C
/* 0E8940 7F0B3E10 8E450000 */   lw    $a1, ($s2)
/* 0E8944 7F0B3E14 00408025 */  move  $s0, $v0
.L7F0B3E18:
/* 0E8948 7F0B3E18 02008825 */  move  $s1, $s0
.L7F0B3E1C:
/* 0E894C 7F0B3E1C AE340000 */  sw    $s4, ($s1)
/* 0E8950 7F0B3E20 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0E8954 7F0B3E24 26100008 */   addiu $s0, $s0, 8
/* 0E8958 7F0B3E28 0C003A2C */  jal   osVirtualToPhysical
/* 0E895C 7F0B3E2C 00402025 */   move  $a0, $v0
/* 0E8960 7F0B3E30 AE220004 */  sw    $v0, 4($s1)
/* 0E8964 7F0B3E34 0FC2ECA6 */  jal   fogRenderClearFogMode
/* 0E8968 7F0B3E38 02002025 */   move  $a0, $s0
/* 0E896C 7F0B3E3C 0FC243D3 */  jal   get_debug_do_draw_obj
/* 0E8970 7F0B3E40 00408025 */   move  $s0, $v0
/* 0E8974 7F0B3E44 10400009 */  beqz  $v0, .L7F0B3E6C
/* 0E8978 7F0B3E48 00000000 */   nop
/* 0E897C 7F0B3E4C 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E8980 7F0B3E50 00000000 */   nop
/* 0E8984 7F0B3E54 10400005 */  beqz  $v0, .L7F0B3E6C
/* 0E8988 7F0B3E58 02002025 */   move  $a0, $s0
/* 0E898C 7F0B3E5C 8E450000 */  lw    $a1, ($s2)
/* 0E8990 7F0B3E60 0FC0E9BD */  jal   chrpropsRenderPass
/* 0E8994 7F0B3E64 24060002 */   li    $a2, 2
/* 0E8998 7F0B3E68 00408025 */  move  $s0, $v0
.L7F0B3E6C:
/* 0E899C 7F0B3E6C 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn)
/* 0E89A0 7F0B3E70 8C42483C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E89A4 7F0B3E74 26730001 */  addiu $s3, $s3, 1
.L7F0B3E78:
/* 0E89A8 7F0B3E78 0262082A */  slt   $at, $s3, $v0
/* 0E89AC 7F0B3E7C 1420FFB2 */  bnez  $at, .L7F0B3D48
/* 0E89B0 7F0B3E80 2652001C */   addiu $s2, $s2, 0x1c
.L7F0B3E84:
/* 0E89B4 7F0B3E84 8FA80044 */  lw    $t0, 0x44($sp)
/* 0E89B8 7F0B3E88 26B50001 */  addiu $s5, $s5, 1
/* 0E89BC 7F0B3E8C 1515FFAA */  bne   $t0, $s5, .L7F0B3D38
/* 0E89C0 7F0B3E90 00000000 */   nop
.L7F0B3E94:
/* 0E89C4 7F0B3E94 3C140103 */  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
/* 0E89C8 7F0B3E98 36940040 */  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
/* 0E89CC 7F0B3E9C 0FC2ECA6 */  jal   fogRenderClearFogMode
/* 0E89D0 7F0B3EA0 02002025 */   move  $a0, $s0
/* 0E89D4 7F0B3EA4 0FC2D3ED */  jal   bgScissorCurrentPlayerViewDefault
/* 0E89D8 7F0B3EA8 00402025 */   move  $a0, $v0
/* 0E89DC 7F0B3EAC 00408825 */  move  $s1, $v0
/* 0E89E0 7F0B3EB0 24500008 */  addiu $s0, $v0, 8
/* 0E89E4 7F0B3EB4 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0E89E8 7F0B3EB8 AC540000 */   sw    $s4, ($v0)
/* 0E89EC 7F0B3EBC 0C003A2C */  jal   osVirtualToPhysical
/* 0E89F0 7F0B3EC0 00402025 */   move  $a0, $v0
/* 0E89F4 7F0B3EC4 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E89F8 7F0B3EC8 AE220004 */   sw    $v0, 4($s1)
/* 0E89FC 7F0B3ECC 10400006 */  beqz  $v0, .L7F0B3EE8
/* 0E8A00 7F0B3ED0 00000000 */   nop
/* 0E8A04 7F0B3ED4 0FC282AD */  jal   explosionRenderScorchBuffer
/* 0E8A08 7F0B3ED8 02002025 */   move  $a0, $s0
/* 0E8A0C 7F0B3EDC 0FC2875E */  jal   explosionCallRenderBulletImpactOnProp
/* 0E8A10 7F0B3EE0 00402025 */   move  $a0, $v0
/* 0E8A14 7F0B3EE4 00408025 */  move  $s0, $v0
.L7F0B3EE8:
/* 0E8A18 7F0B3EE8 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn)
/* 0E8A1C 7F0B3EEC 02D7082A */  slt   $at, $s6, $s7
/* 0E8A20 7F0B3EF0 8C42483C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E8A24 7F0B3EF4 14200043 */  bnez  $at, .L7F0B4004
/* 0E8A28 7F0B3EF8 02C0A825 */   move  $s5, $s6
/* 0E8A2C 7F0B3EFC 26F6FFFF */  addiu $s6, $s7, -1
.L7F0B3F00:
/* 0E8A30 7F0B3F00 1840003D */  blez  $v0, .L7F0B3FF8
/* 0E8A34 7F0B3F04 00009825 */   move  $s3, $zero
/* 0E8A38 7F0B3F08 3C128008 */  lui   $s2, %hi(dword_CODE_bss_8007FFA0)
/* 0E8A3C 7F0B3F0C 2652FFA0 */  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x60
.L7F0B3F10:
/* 0E8A40 7F0B3F10 8E490004 */  lw    $t1, 4($s2)
/* 0E8A44 7F0B3F14 02008825 */  move  $s1, $s0
/* 0E8A48 7F0B3F18 56A90034 */  bnel  $s5, $t1, .L7F0B3FEC
/* 0E8A4C 7F0B3F1C 26730001 */   addiu $s3, $s3, 1
/* 0E8A50 7F0B3F20 26100008 */  addiu $s0, $s0, 8
/* 0E8A54 7F0B3F24 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0E8A58 7F0B3F28 AE340000 */   sw    $s4, ($s1)
/* 0E8A5C 7F0B3F2C 0C003A2C */  jal   osVirtualToPhysical
/* 0E8A60 7F0B3F30 00402025 */   move  $a0, $v0
/* 0E8A64 7F0B3F34 AE220004 */  sw    $v0, 4($s1)
/* 0E8A68 7F0B3F38 C6460014 */  lwc1  $f6, 0x14($s2)
/* 0E8A6C 7F0B3F3C 8E470010 */  lw    $a3, 0x10($s2)
/* 0E8A70 7F0B3F40 8E46000C */  lw    $a2, 0xc($s2)
/* 0E8A74 7F0B3F44 8E450008 */  lw    $a1, 8($s2)
/* 0E8A78 7F0B3F48 02002025 */  move  $a0, $s0
/* 0E8A7C 7F0B3F4C 0FC2D3FD */  jal   bgScissorCurrentPlayerViewF
/* 0E8A80 7F0B3F50 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0E8A84 7F0B3F54 00402025 */  move  $a0, $v0
/* 0E8A88 7F0B3F58 0FC2EC1C */  jal   fogSetRenderFogColor
/* 0E8A8C 7F0B3F5C 24050001 */   li    $a1, 1
/* 0E8A90 7F0B3F60 0FC243D0 */  jal   get_debug_do_draw_bg
/* 0E8A94 7F0B3F64 00408025 */   move  $s0, $v0
/* 0E8A98 7F0B3F68 50400009 */  beql  $v0, $zero, .L7F0B3F90
/* 0E8A9C 7F0B3F6C 02008825 */   move  $s1, $s0
/* 0E8AA0 7F0B3F70 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E8AA4 7F0B3F74 00000000 */   nop
/* 0E8AA8 7F0B3F78 10400004 */  beqz  $v0, .L7F0B3F8C
/* 0E8AAC 7F0B3F7C 02002025 */   move  $a0, $s0
/* 0E8AB0 7F0B3F80 0FC2DA26 */  jal   sub_GAME_7F0B6898
/* 0E8AB4 7F0B3F84 8E450000 */   lw    $a1, ($s2)
/* 0E8AB8 7F0B3F88 00408025 */  move  $s0, $v0
.L7F0B3F8C:
/* 0E8ABC 7F0B3F8C 02008825 */  move  $s1, $s0
.L7F0B3F90:
/* 0E8AC0 7F0B3F90 AE340000 */  sw    $s4, ($s1)
/* 0E8AC4 7F0B3F94 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0E8AC8 7F0B3F98 26100008 */   addiu $s0, $s0, 8
/* 0E8ACC 7F0B3F9C 0C003A2C */  jal   osVirtualToPhysical
/* 0E8AD0 7F0B3FA0 00402025 */   move  $a0, $v0
/* 0E8AD4 7F0B3FA4 AE220004 */  sw    $v0, 4($s1)
/* 0E8AD8 7F0B3FA8 0FC2ECA6 */  jal   fogRenderClearFogMode
/* 0E8ADC 7F0B3FAC 02002025 */   move  $a0, $s0
/* 0E8AE0 7F0B3FB0 0FC243D3 */  jal   get_debug_do_draw_obj
/* 0E8AE4 7F0B3FB4 00408025 */   move  $s0, $v0
/* 0E8AE8 7F0B3FB8 10400009 */  beqz  $v0, .L7F0B3FE0
/* 0E8AEC 7F0B3FBC 00000000 */   nop
/* 0E8AF0 7F0B3FC0 0FC2F63C */  jal   sub_GAME_7F0BD8F0
/* 0E8AF4 7F0B3FC4 00000000 */   nop
/* 0E8AF8 7F0B3FC8 10400005 */  beqz  $v0, .L7F0B3FE0
/* 0E8AFC 7F0B3FCC 02002025 */   move  $a0, $s0
/* 0E8B00 7F0B3FD0 8E450000 */  lw    $a1, ($s2)
/* 0E8B04 7F0B3FD4 0FC0E9BD */  jal   chrpropsRenderPass
/* 0E8B08 7F0B3FD8 24060001 */   li    $a2, 1
/* 0E8B0C 7F0B3FDC 00408025 */  move  $s0, $v0
.L7F0B3FE0:
/* 0E8B10 7F0B3FE0 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn)
/* 0E8B14 7F0B3FE4 8C42483C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E8B18 7F0B3FE8 26730001 */  addiu $s3, $s3, 1
.L7F0B3FEC:
/* 0E8B1C 7F0B3FEC 0262082A */  slt   $at, $s3, $v0
/* 0E8B20 7F0B3FF0 1420FFC7 */  bnez  $at, .L7F0B3F10
/* 0E8B24 7F0B3FF4 2652001C */   addiu $s2, $s2, 0x1c
.L7F0B3FF8:
/* 0E8B28 7F0B3FF8 26B5FFFF */  addiu $s5, $s5, -1
/* 0E8B2C 7F0B3FFC 16B6FFC0 */  bne   $s5, $s6, .L7F0B3F00
/* 0E8B30 7F0B4000 00000000 */   nop
.L7F0B4004:
/* 0E8B34 7F0B4004 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E8B38 7F0B4008 02001025 */  move  $v0, $s0
/* 0E8B3C 7F0B400C 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0E8B40 7F0B4010 8FB10020 */  lw    $s1, 0x20($sp)
/* 0E8B44 7F0B4014 8FB20024 */  lw    $s2, 0x24($sp)
/* 0E8B48 7F0B4018 8FB30028 */  lw    $s3, 0x28($sp)
/* 0E8B4C 7F0B401C 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0E8B50 7F0B4020 8FB50030 */  lw    $s5, 0x30($sp)
/* 0E8B54 7F0B4024 8FB60034 */  lw    $s6, 0x34($sp)
/* 0E8B58 7F0B4028 8FB70038 */  lw    $s7, 0x38($sp)
/* 0E8B5C 7F0B402C 03E00008 */  jr    $ra
/* 0E8B60 7F0B4030 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3C8C
/* 0E5994 7F0B2FA4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0E5998 7F0B2FA8 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn) # $v0, 0x8004
/* 0E599C 7F0B2FAC 8C42DD1C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E59A0 7F0B2FB0 AFB70038 */  sw    $s7, 0x38($sp)
/* 0E59A4 7F0B2FB4 AFB60034 */  sw    $s6, 0x34($sp)
/* 0E59A8 7F0B2FB8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0E59AC 7F0B2FBC 00808025 */  move  $s0, $a0
/* 0E59B0 7F0B2FC0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E59B4 7F0B2FC4 AFB50030 */  sw    $s5, 0x30($sp)
/* 0E59B8 7F0B2FC8 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0E59BC 7F0B2FCC AFB30028 */  sw    $s3, 0x28($sp)
/* 0E59C0 7F0B2FD0 AFB20024 */  sw    $s2, 0x24($sp)
/* 0E59C4 7F0B2FD4 AFB10020 */  sw    $s1, 0x20($sp)
/* 0E59C8 7F0B2FD8 0000B025 */  move  $s6, $zero
/* 0E59CC 7F0B2FDC 18400018 */  blez  $v0, .L7F0B3040
/* 0E59D0 7F0B2FE0 24177FFF */   li    $s7, 32767
/* 0E59D4 7F0B2FE4 00027880 */  sll   $t7, $v0, 2
/* 0E59D8 7F0B2FE8 01E27823 */  subu  $t7, $t7, $v0
/* 0E59DC 7F0B2FEC 3C0E8007 */  lui   $t6, %hi(dword_CODE_bss_8007FFA0)
/* 0E59E0 7F0B2FF0 25D2B3E0 */  addiu $s2, $t6, %lo(dword_CODE_bss_8007FFA0)
/* 0E59E4 7F0B2FF4 000F78C0 */  sll   $t7, $t7, 3
/* 0E59E8 7F0B2FF8 01F22021 */  addu  $a0, $t7, $s2
/* 0E59EC 7F0B2FFC 86430002 */  lh    $v1, 2($s2)
.L7F0B3000:
/* 0E59F0 7F0B3000 26520018 */  addiu $s2, $s2, 0x18
/* 0E59F4 7F0B3004 02C3082A */  slt   $at, $s6, $v1
/* 0E59F8 7F0B3008 50200005 */  beql  $at, $zero, .L7F0B3020
/* 0E59FC 7F0B300C 0077082A */   slt   $at, $v1, $s7
/* 0E5A00 7F0B3010 0003B400 */  sll   $s6, $v1, 0x10
/* 0E5A04 7F0B3014 0016C403 */  sra   $t8, $s6, 0x10
/* 0E5A08 7F0B3018 0300B025 */  move  $s6, $t8
/* 0E5A0C 7F0B301C 0077082A */  slt   $at, $v1, $s7
.L7F0B3020:
/* 0E5A10 7F0B3020 50200005 */  beql  $at, $zero, .L7F0B3038
/* 0E5A14 7F0B3024 0244082B */   sltu  $at, $s2, $a0
/* 0E5A18 7F0B3028 0003BC00 */  sll   $s7, $v1, 0x10
/* 0E5A1C 7F0B302C 0017CC03 */  sra   $t9, $s7, 0x10
/* 0E5A20 7F0B3030 0320B825 */  move  $s7, $t9
/* 0E5A24 7F0B3034 0244082B */  sltu  $at, $s2, $a0
.L7F0B3038:
/* 0E5A28 7F0B3038 5420FFF1 */  bnezl $at, .L7F0B3000
/* 0E5A2C 7F0B303C 86430002 */   lh    $v1, 2($s2)
.L7F0B3040:
/* 0E5A30 7F0B3040 0017AC00 */  sll   $s5, $s7, 0x10
/* 0E5A34 7F0B3044 00154403 */  sra   $t0, $s5, 0x10
/* 0E5A38 7F0B3048 02D7082A */  slt   $at, $s6, $s7
/* 0E5A3C 7F0B304C 1420005C */  bnez  $at, .L7F0B31C0
/* 0E5A40 7F0B3050 0100A825 */   move  $s5, $t0
/* 0E5A44 7F0B3054 3C140103 */  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
/* 0E5A48 7F0B3058 36940040 */  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
.L7F0B305C:
/* 0E5A4C 7F0B305C 18400052 */  blez  $v0, .L7F0B31A8
/* 0E5A50 7F0B3060 00009825 */   move  $s3, $zero
/* 0E5A54 7F0B3064 3C128007 */  lui   $s2, %hi(dword_CODE_bss_8007FFA0) # $s2, 0x8007
/* 0E5A58 7F0B3068 2652B3E0 */  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x4c20
.L7F0B306C:
/* 0E5A5C 7F0B306C 86490002 */  lh    $t1, 2($s2)
/* 0E5A60 7F0B3070 02008825 */  move  $s1, $s0
/* 0E5A64 7F0B3074 56A90049 */  bnel  $s5, $t1, .L7F0B319C
/* 0E5A68 7F0B3078 26730001 */   addiu $s3, $s3, 1
/* 0E5A6C 7F0B307C 26100008 */  addiu $s0, $s0, 8
/* 0E5A70 7F0B3080 0FC1E0FD */  jal   currentPlayerGetProjectionMatrix
/* 0E5A74 7F0B3084 AE340000 */   sw    $s4, ($s1)
/* 0E5A78 7F0B3088 0C003838 */  jal   osVirtualToPhysical
/* 0E5A7C 7F0B308C 00402025 */   move  $a0, $v0
/* 0E5A80 7F0B3090 AE220004 */  sw    $v0, 4($s1)
/* 0E5A84 7F0B3094 0FC2E9A6 */  jal   fogRenderClearFogMode
/* 0E5A88 7F0B3098 02002025 */   move  $a0, $s0
/* 0E5A8C 7F0B309C 0FC24104 */  jal   get_debug_do_draw_obj
/* 0E5A90 7F0B30A0 00408025 */   move  $s0, $v0
/* 0E5A94 7F0B30A4 5040000A */  beql  $v0, $zero, .L7F0B30D0
/* 0E5A98 7F0B30A8 02008825 */   move  $s1, $s0
/* 0E5A9C 7F0B30AC 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5AA0 7F0B30B0 00000000 */   nop
/* 0E5AA4 7F0B30B4 10400005 */  beqz  $v0, .L7F0B30CC
/* 0E5AA8 7F0B30B8 02002025 */   move  $a0, $s0
/* 0E5AAC 7F0B30BC 92450000 */  lbu   $a1, ($s2)
/* 0E5AB0 7F0B30C0 0FC0E9ED */  jal   chrpropsRenderPass
/* 0E5AB4 7F0B30C4 00003025 */   move  $a2, $zero
/* 0E5AB8 7F0B30C8 00408025 */  move  $s0, $v0
.L7F0B30CC:
/* 0E5ABC 7F0B30CC 02008825 */  move  $s1, $s0
.L7F0B30D0:
/* 0E5AC0 7F0B30D0 AE340000 */  sw    $s4, ($s1)
/* 0E5AC4 7F0B30D4 0FC1E105 */  jal   get_BONDdata_field_10E0
/* 0E5AC8 7F0B30D8 26100008 */   addiu $s0, $s0, 8
/* 0E5ACC 7F0B30DC 0C003838 */  jal   osVirtualToPhysical
/* 0E5AD0 7F0B30E0 00402025 */   move  $a0, $v0
/* 0E5AD4 7F0B30E4 AE220004 */  sw    $v0, 4($s1)
/* 0E5AD8 7F0B30E8 C6440014 */  lwc1  $f4, 0x14($s2)
/* 0E5ADC 7F0B30EC 8E470010 */  lw    $a3, 0x10($s2)
/* 0E5AE0 7F0B30F0 8E46000C */  lw    $a2, 0xc($s2)
/* 0E5AE4 7F0B30F4 8E450008 */  lw    $a1, 8($s2)
/* 0E5AE8 7F0B30F8 02002025 */  move  $a0, $s0
/* 0E5AEC 7F0B30FC 0FC2D0CC */  jal   bgScissorCurrentPlayerViewF
/* 0E5AF0 7F0B3100 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0E5AF4 7F0B3104 00402025 */  move  $a0, $v0
/* 0E5AF8 7F0B3108 0FC2E91C */  jal   fogSetRenderFogColor
/* 0E5AFC 7F0B310C 00002825 */   move  $a1, $zero
/* 0E5B00 7F0B3110 0FC24102 */  jal   get_debug_do_draw_bg
/* 0E5B04 7F0B3114 00408025 */   move  $s0, $v0
/* 0E5B08 7F0B3118 50400009 */  beql  $v0, $zero, .L7F0B3140
/* 0E5B0C 7F0B311C 02008825 */   move  $s1, $s0
/* 0E5B10 7F0B3120 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5B14 7F0B3124 00000000 */   nop
/* 0E5B18 7F0B3128 10400004 */  beqz  $v0, .L7F0B313C
/* 0E5B1C 7F0B312C 02002025 */   move  $a0, $s0
/* 0E5B20 7F0B3130 0FC2D6AE */  jal   sub_GAME_7F0B677C
/* 0E5B24 7F0B3134 92450000 */   lbu   $a1, ($s2)
/* 0E5B28 7F0B3138 00408025 */  move  $s0, $v0
.L7F0B313C:
/* 0E5B2C 7F0B313C 02008825 */  move  $s1, $s0
.L7F0B3140:
/* 0E5B30 7F0B3140 AE340000 */  sw    $s4, ($s1)
/* 0E5B34 7F0B3144 0FC1E0FD */  jal   currentPlayerGetProjectionMatrix
/* 0E5B38 7F0B3148 26100008 */   addiu $s0, $s0, 8
/* 0E5B3C 7F0B314C 0C003838 */  jal   osVirtualToPhysical
/* 0E5B40 7F0B3150 00402025 */   move  $a0, $v0
/* 0E5B44 7F0B3154 AE220004 */  sw    $v0, 4($s1)
/* 0E5B48 7F0B3158 0FC2E9A6 */  jal   fogRenderClearFogMode
/* 0E5B4C 7F0B315C 02002025 */   move  $a0, $s0
/* 0E5B50 7F0B3160 0FC24104 */  jal   get_debug_do_draw_obj
/* 0E5B54 7F0B3164 00408025 */   move  $s0, $v0
/* 0E5B58 7F0B3168 10400009 */  beqz  $v0, .L7F0B3190
/* 0E5B5C 7F0B316C 00000000 */   nop
/* 0E5B60 7F0B3170 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5B64 7F0B3174 00000000 */   nop
/* 0E5B68 7F0B3178 10400005 */  beqz  $v0, .L7F0B3190
/* 0E5B6C 7F0B317C 02002025 */   move  $a0, $s0
/* 0E5B70 7F0B3180 92450000 */  lbu   $a1, ($s2)
/* 0E5B74 7F0B3184 0FC0E9ED */  jal   chrpropsRenderPass
/* 0E5B78 7F0B3188 24060002 */   li    $a2, 2
/* 0E5B7C 7F0B318C 00408025 */  move  $s0, $v0
.L7F0B3190:
/* 0E5B80 7F0B3190 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn) # $v0, 0x8004
/* 0E5B84 7F0B3194 8C42DD1C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E5B88 7F0B3198 26730001 */  addiu $s3, $s3, 1
.L7F0B319C:
/* 0E5B8C 7F0B319C 0262082A */  slt   $at, $s3, $v0
/* 0E5B90 7F0B31A0 1420FFB2 */  bnez  $at, .L7F0B306C
/* 0E5B94 7F0B31A4 26520018 */   addiu $s2, $s2, 0x18
.L7F0B31A8:
/* 0E5B98 7F0B31A8 26B50001 */  addiu $s5, $s5, 1
/* 0E5B9C 7F0B31AC 00155400 */  sll   $t2, $s5, 0x10
/* 0E5BA0 7F0B31B0 000AAC03 */  sra   $s5, $t2, 0x10
/* 0E5BA4 7F0B31B4 02D5082A */  slt   $at, $s6, $s5
/* 0E5BA8 7F0B31B8 1020FFA8 */  beqz  $at, .L7F0B305C
/* 0E5BAC 7F0B31BC 00000000 */   nop
.L7F0B31C0:
/* 0E5BB0 7F0B31C0 3C140103 */  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
/* 0E5BB4 7F0B31C4 36940040 */  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
/* 0E5BB8 7F0B31C8 0FC2E9A6 */  jal   fogRenderClearFogMode
/* 0E5BBC 7F0B31CC 02002025 */   move  $a0, $s0
/* 0E5BC0 7F0B31D0 0FC2D0BC */  jal   bgScissorCurrentPlayerViewDefault
/* 0E5BC4 7F0B31D4 00402025 */   move  $a0, $v0
/* 0E5BC8 7F0B31D8 00408825 */  move  $s1, $v0
/* 0E5BCC 7F0B31DC 24500008 */  addiu $s0, $v0, 8
/* 0E5BD0 7F0B31E0 0FC1E105 */  jal   get_BONDdata_field_10E0
/* 0E5BD4 7F0B31E4 AC540000 */   sw    $s4, ($v0)
/* 0E5BD8 7F0B31E8 0C003838 */  jal   osVirtualToPhysical
/* 0E5BDC 7F0B31EC 00402025 */   move  $a0, $v0
/* 0E5BE0 7F0B31F0 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5BE4 7F0B31F4 AE220004 */   sw    $v0, 4($s1)
/* 0E5BE8 7F0B31F8 50400007 */  beql  $v0, $zero, .L7F0B3218
/* 0E5BEC 7F0B31FC 0016AC00 */   sll   $s5, $s6, 0x10
/* 0E5BF0 7F0B3200 0FC27FFE */  jal   explosionRenderScorchBuffer
/* 0E5BF4 7F0B3204 02002025 */   move  $a0, $s0
/* 0E5BF8 7F0B3208 0FC284AF */  jal   explosionCallRenderBulletImpactOnProp
/* 0E5BFC 7F0B320C 00402025 */   move  $a0, $v0
/* 0E5C00 7F0B3210 00408025 */  move  $s0, $v0
/* 0E5C04 7F0B3214 0016AC00 */  sll   $s5, $s6, 0x10
.L7F0B3218:
/* 0E5C08 7F0B3218 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn) # $v0, 0x8004
/* 0E5C0C 7F0B321C 00156403 */  sra   $t4, $s5, 0x10
/* 0E5C10 7F0B3220 02D7082A */  slt   $at, $s6, $s7
/* 0E5C14 7F0B3224 8C42DD1C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E5C18 7F0B3228 14200045 */  bnez  $at, .L7F0B3340
/* 0E5C1C 7F0B322C 0180A825 */   move  $s5, $t4
.L7F0B3230:
/* 0E5C20 7F0B3230 1840003D */  blez  $v0, .L7F0B3328
/* 0E5C24 7F0B3234 00009825 */   move  $s3, $zero
/* 0E5C28 7F0B3238 3C128007 */  lui   $s2, %hi(dword_CODE_bss_8007FFA0) # $s2, 0x8007
/* 0E5C2C 7F0B323C 2652B3E0 */  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x4c20
.L7F0B3240:
/* 0E5C30 7F0B3240 864D0002 */  lh    $t5, 2($s2)
/* 0E5C34 7F0B3244 02008825 */  move  $s1, $s0
/* 0E5C38 7F0B3248 56AD0034 */  bnel  $s5, $t5, .L7F0B331C
/* 0E5C3C 7F0B324C 26730001 */   addiu $s3, $s3, 1
/* 0E5C40 7F0B3250 26100008 */  addiu $s0, $s0, 8
/* 0E5C44 7F0B3254 0FC1E105 */  jal   get_BONDdata_field_10E0
/* 0E5C48 7F0B3258 AE340000 */   sw    $s4, ($s1)
/* 0E5C4C 7F0B325C 0C003838 */  jal   osVirtualToPhysical
/* 0E5C50 7F0B3260 00402025 */   move  $a0, $v0
/* 0E5C54 7F0B3264 AE220004 */  sw    $v0, 4($s1)
/* 0E5C58 7F0B3268 C6460014 */  lwc1  $f6, 0x14($s2)
/* 0E5C5C 7F0B326C 8E470010 */  lw    $a3, 0x10($s2)
/* 0E5C60 7F0B3270 8E46000C */  lw    $a2, 0xc($s2)
/* 0E5C64 7F0B3274 8E450008 */  lw    $a1, 8($s2)
/* 0E5C68 7F0B3278 02002025 */  move  $a0, $s0
/* 0E5C6C 7F0B327C 0FC2D0CC */  jal   bgScissorCurrentPlayerViewF
/* 0E5C70 7F0B3280 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0E5C74 7F0B3284 00402025 */  move  $a0, $v0
/* 0E5C78 7F0B3288 0FC2E91C */  jal   fogSetRenderFogColor
/* 0E5C7C 7F0B328C 24050001 */   li    $a1, 1
/* 0E5C80 7F0B3290 0FC24102 */  jal   get_debug_do_draw_bg
/* 0E5C84 7F0B3294 00408025 */   move  $s0, $v0
/* 0E5C88 7F0B3298 50400009 */  beql  $v0, $zero, .L7F0B32C0
/* 0E5C8C 7F0B329C 02008825 */   move  $s1, $s0
/* 0E5C90 7F0B32A0 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5C94 7F0B32A4 00000000 */   nop
/* 0E5C98 7F0B32A8 10400004 */  beqz  $v0, .L7F0B32BC
/* 0E5C9C 7F0B32AC 02002025 */   move  $a0, $s0
/* 0E5CA0 7F0B32B0 0FC2D6F5 */  jal   sub_GAME_7F0B6898
/* 0E5CA4 7F0B32B4 92450000 */   lbu   $a1, ($s2)
/* 0E5CA8 7F0B32B8 00408025 */  move  $s0, $v0
.L7F0B32BC:
/* 0E5CAC 7F0B32BC 02008825 */  move  $s1, $s0
.L7F0B32C0:
/* 0E5CB0 7F0B32C0 AE340000 */  sw    $s4, ($s1)
/* 0E5CB4 7F0B32C4 0FC1E0FD */  jal   currentPlayerGetProjectionMatrix
/* 0E5CB8 7F0B32C8 26100008 */   addiu $s0, $s0, 8
/* 0E5CBC 7F0B32CC 0C003838 */  jal   osVirtualToPhysical
/* 0E5CC0 7F0B32D0 00402025 */   move  $a0, $v0
/* 0E5CC4 7F0B32D4 AE220004 */  sw    $v0, 4($s1)
/* 0E5CC8 7F0B32D8 0FC2E9A6 */  jal   fogRenderClearFogMode
/* 0E5CCC 7F0B32DC 02002025 */   move  $a0, $s0
/* 0E5CD0 7F0B32E0 0FC24104 */  jal   get_debug_do_draw_obj
/* 0E5CD4 7F0B32E4 00408025 */   move  $s0, $v0
/* 0E5CD8 7F0B32E8 10400009 */  beqz  $v0, .L7F0B3310
/* 0E5CDC 7F0B32EC 00000000 */   nop
/* 0E5CE0 7F0B32F0 0FC2F328 */  jal   sub_GAME_7F0BD8F0
/* 0E5CE4 7F0B32F4 00000000 */   nop
/* 0E5CE8 7F0B32F8 10400005 */  beqz  $v0, .L7F0B3310
/* 0E5CEC 7F0B32FC 02002025 */   move  $a0, $s0
/* 0E5CF0 7F0B3300 92450000 */  lbu   $a1, ($s2)
/* 0E5CF4 7F0B3304 0FC0E9ED */  jal   chrpropsRenderPass
/* 0E5CF8 7F0B3308 24060001 */   li    $a2, 1
/* 0E5CFC 7F0B330C 00408025 */  move  $s0, $v0
.L7F0B3310:
/* 0E5D00 7F0B3310 3C028004 */  lui   $v0, %hi(g_BgNumberOfRoomsDrawn) # $v0, 0x8004
/* 0E5D04 7F0B3314 8C42DD1C */  lw    $v0, %lo(g_BgNumberOfRoomsDrawn)($v0)
/* 0E5D08 7F0B3318 26730001 */  addiu $s3, $s3, 1
.L7F0B331C:
/* 0E5D0C 7F0B331C 0262082A */  slt   $at, $s3, $v0
/* 0E5D10 7F0B3320 1420FFC7 */  bnez  $at, .L7F0B3240
/* 0E5D14 7F0B3324 26520018 */   addiu $s2, $s2, 0x18
.L7F0B3328:
/* 0E5D18 7F0B3328 26B5FFFF */  addiu $s5, $s5, -1
/* 0E5D1C 7F0B332C 00157C00 */  sll   $t7, $s5, 0x10
/* 0E5D20 7F0B3330 000FAC03 */  sra   $s5, $t7, 0x10
/* 0E5D24 7F0B3334 02B7082A */  slt   $at, $s5, $s7
/* 0E5D28 7F0B3338 1020FFBD */  beqz  $at, .L7F0B3230
/* 0E5D2C 7F0B333C 00000000 */   nop
.L7F0B3340:
/* 0E5D30 7F0B3340 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E5D34 7F0B3344 02001025 */  move  $v0, $s0
/* 0E5D38 7F0B3348 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0E5D3C 7F0B334C 8FB10020 */  lw    $s1, 0x20($sp)
/* 0E5D40 7F0B3350 8FB20024 */  lw    $s2, 0x24($sp)
/* 0E5D44 7F0B3354 8FB30028 */  lw    $s3, 0x28($sp)
/* 0E5D48 7F0B3358 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0E5D4C 7F0B335C 8FB50030 */  lw    $s5, 0x30($sp)
/* 0E5D50 7F0B3360 8FB60034 */  lw    $s6, 0x34($sp)
/* 0E5D54 7F0B3364 8FB70038 */  lw    $s7, 0x38($sp)
/* 0E5D58 7F0B3368 03E00008 */  jr    $ra
/* 0E5D5C 7F0B336C 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

#endif





s32 sub_GAME_7F0B4034(s32 room)
{
    int i = room;
    while (ptr_bgdata_room_fileposition_list[i].pPriMappingBin == 0)
    {
        i++;
    }
    return i;
}


s32 sub_GAME_7F0B4084(s32 room)
{
    int i = room;
    while (ptr_bgdata_room_fileposition_list[i].pSecMappingBin == 0)
    {
        i++;
    }
    return i;
}


s32 sub_GAME_7F0B40D4(s32 room)
{
    int i = room;
    while (ptr_bgdata_room_fileposition_list[i].pPointTableBin == 0)
    {
        i++;
    }
    return i;
}






#ifdef NONMATCHING
void load_bg_file(LEVEL_INDEX stagenum)
{

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel load_bg_file
/* 0E8C54 7F0B4124 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0E8C58 7F0B4128 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E8C5C 7F0B412C 3C128004 */  lui   $s2, %hi(levelentry_index)
/* 0E8C60 7F0B4130 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E8C64 7F0B4134 26521400 */  addiu $s2, %lo(levelentry_index) # addiu $s2, $s2, 0x1400
/* 0E8C68 7F0B4138 3C108004 */  lui   $s0, %hi(g_BgRoomInfo)
/* 0E8C6C 7F0B413C 3C028004 */  lui   $v0, %hi(g_MaxNumRooms)
/* 0E8C70 7F0B4140 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E8C74 7F0B4144 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E8C78 7F0B4148 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E8C7C 7F0B414C AFB60030 */  sw    $s6, 0x30($sp)
/* 0E8C80 7F0B4150 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E8C84 7F0B4154 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E8C88 7F0B4158 AFB30024 */  sw    $s3, 0x24($sp)
/* 0E8C8C 7F0B415C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E8C90 7F0B4160 AE400000 */  sw    $zero, ($s2)
/* 0E8C94 7F0B4164 244242F4 */  addiu $v0, %lo(g_MaxNumRooms) # addiu $v0, $v0, 0x42f4
/* 0E8C98 7F0B4168 26101414 */  addiu $s0, %lo(g_BgRoomInfo) # addiu $s0, $s0, 0x1414
.L7F0B416C:
/* 0E8C9C 7F0B416C 26100050 */  addiu $s0, $s0, 0x50
/* 0E8CA0 7F0B4170 0202082B */  sltu  $at, $s0, $v0
/* 0E8CA4 7F0B4174 1420FFFD */  bnez  $at, .L7F0B416C
/* 0E8CA8 7F0B4178 AE00FFDC */   sw    $zero, -0x24($s0)
/* 0E8CAC 7F0B417C 3C028004 */  lui   $v0, %hi(levelinfotable)
/* 0E8CB0 7F0B4180 2442448C */  addiu $v0, %lo(levelinfotable) # addiu $v0, $v0, 0x448c
/* 0E8CB4 7F0B4184 00008825 */  move  $s1, $zero
.L7F0B4188:
/* 0E8CB8 7F0B4188 8C4E0000 */  lw    $t6, ($v0)
/* 0E8CBC 7F0B418C 548E0003 */  bnel  $a0, $t6, .L7F0B419C
/* 0E8CC0 7F0B4190 26310001 */   addiu $s1, $s1, 1
/* 0E8CC4 7F0B4194 AE510000 */  sw    $s1, ($s2)
/* 0E8CC8 7F0B4198 26310001 */  addiu $s1, $s1, 1
.L7F0B419C:
/* 0E8CCC 7F0B419C 2A210026 */  slti  $at, $s1, 0x26
/* 0E8CD0 7F0B41A0 1420FFF9 */  bnez  $at, .L7F0B4188
/* 0E8CD4 7F0B41A4 24420018 */   addiu $v0, $v0, 0x18
/* 0E8CD8 7F0B41A8 0FC2ED34 */  jal   init_lightfixture_tables
/* 0E8CDC 7F0B41AC AFA400B8 */   sw    $a0, 0xb8($sp)
/* 0E8CE0 7F0B41B0 8E580000 */  lw    $t8, ($s2)
/* 0E8CE4 7F0B41B4 24140018 */  li    $s4, 24
/* 0E8CE8 7F0B41B8 3C118004 */  lui   $s1, %hi(levelinfotable)
/* 0E8CEC 7F0B41BC 03140019 */  multu $t8, $s4
/* 0E8CF0 7F0B41C0 2631448C */  addiu $s1, %lo(levelinfotable) # addiu $s1, $s1, 0x448c
/* 0E8CF4 7F0B41C4 3C178008 */  lui   $s7, %hi(ptr_bg_data)
/* 0E8CF8 7F0B41C8 26F7BF90 */  addiu $s7, %lo(ptr_bg_data) # addiu $s7, $s7, -0x4070
/* 0E8CFC 7F0B41CC 27A50070 */  addiu $a1, $sp, 0x70
/* 0E8D00 7F0B41D0 AEE50000 */  sw    $a1, ($s7)
/* 0E8D04 7F0B41D4 00003025 */  move  $a2, $zero
/* 0E8D08 7F0B41D8 24070040 */  li    $a3, 64
/* 0E8D0C 7F0B41DC 0000C812 */  mflo  $t9
/* 0E8D10 7F0B41E0 02394021 */  addu  $t0, $s1, $t9
/* 0E8D14 7F0B41E4 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0E8D18 7F0B41E8 8D040004 */   lw    $a0, 4($t0)
/* 0E8D1C 7F0B41EC 8EE20000 */  lw    $v0, ($s7)
/* 0E8D20 7F0B41F0 3C168008 */  lui   $s6, %hi(ptr_bgdata_offsets)
/* 0E8D24 7F0B41F4 26D6FF84 */  addiu $s6, %lo(ptr_bgdata_offsets) # addiu $s6, $s6, -0x7c
/* 0E8D28 7F0B41F8 AEC20000 */  sw    $v0, ($s6)
/* 0E8D2C 7F0B41FC 8C4A0004 */  lw    $t2, 4($v0)
/* 0E8D30 7F0B4200 3C13F100 */  lui   $s3, 0xf100
/* 0E8D34 7F0B4204 3C158008 */  lui   $s5, %hi(ptr_bgdata_room_fileposition_list)
/* 0E8D38 7F0B4208 01425821 */  addu  $t3, $t2, $v0
/* 0E8D3C 7F0B420C 26B5FF8C */  addiu $s5, %lo(ptr_bgdata_room_fileposition_list) # addiu $s5, $s5, -0x74
/* 0E8D40 7F0B4210 01736021 */  addu  $t4, $t3, $s3
/* 0E8D44 7F0B4214 AEAC0000 */  sw    $t4, ($s5)
/* 0E8D48 7F0B4218 8D900018 */  lw    $s0, 0x18($t4)
/* 0E8D4C 7F0B421C 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0E8D50 7F0B4220 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0E8D54 7F0B4224 02017024 */  and   $t6, $s0, $at
/* 0E8D58 7F0B4228 25D0FFFF */  addiu $s0, $t6, -1
/* 0E8D5C 7F0B422C 360F000F */  ori   $t7, $s0, 0xf
/* 0E8D60 7F0B4230 25F00001 */  addiu $s0, $t7, 1
/* 0E8D64 7F0B4234 02002025 */  move  $a0, $s0
/* 0E8D68 7F0B4238 0C0025C8 */  jal   mempAllocBytesInBank
/* 0E8D6C 7F0B423C 24050004 */   li    $a1, 4
/* 0E8D70 7F0B4240 8E580000 */  lw    $t8, ($s2)
/* 0E8D74 7F0B4244 AEE20000 */  sw    $v0, ($s7)
/* 0E8D78 7F0B4248 00402825 */  move  $a1, $v0
/* 0E8D7C 7F0B424C 03140019 */  multu $t8, $s4
/* 0E8D80 7F0B4250 00003025 */  move  $a2, $zero
/* 0E8D84 7F0B4254 02003825 */  move  $a3, $s0
/* 0E8D88 7F0B4258 0000C812 */  mflo  $t9
/* 0E8D8C 7F0B425C 02394021 */  addu  $t0, $s1, $t9
/* 0E8D90 7F0B4260 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0E8D94 7F0B4264 8D040004 */   lw    $a0, 4($t0)
/* 0E8D98 7F0B4268 8E490000 */  lw    $t1, ($s2)
/* 0E8D9C 7F0B426C 24050002 */  li    $a1, 2
/* 0E8DA0 7F0B4270 00003025 */  move  $a2, $zero
/* 0E8DA4 7F0B4274 01340019 */  multu $t1, $s4
/* 0E8DA8 7F0B4278 24070004 */  li    $a3, 4
/* 0E8DAC 7F0B427C 00005012 */  mflo  $t2
/* 0E8DB0 7F0B4280 022A5821 */  addu  $t3, $s1, $t2
/* 0E8DB4 7F0B4284 0FC2F341 */  jal   _fileNameLoadToBank
/* 0E8DB8 7F0B4288 8D640008 */   lw    $a0, 8($t3)
/* 0E8DBC 7F0B428C 3C108008 */  lui   $s0, %hi(gptr_stan)
/* 0E8DC0 7F0B4290 2610BF94 */  addiu $s0, %lo(gptr_stan) # addiu $s0, $s0, -0x406c
/* 0E8DC4 7F0B4294 AE020000 */  sw    $v0, ($s0)
/* 0E8DC8 7F0B4298 00402025 */  move  $a0, $v0
/* 0E8DCC 7F0B429C 00002825 */  move  $a1, $zero
/* 0E8DD0 7F0B42A0 0FC2CBCB */  jal   stanDetermineEOF
/* 0E8DD4 7F0B42A4 00403025 */   move  $a2, $v0
/* 0E8DD8 7F0B42A8 0FC2BD6E */  jal   stanLoadFile
/* 0E8DDC 7F0B42AC 8E040000 */   lw    $a0, ($s0)
/* 0E8DE0 7F0B42B0 8E4C0000 */  lw    $t4, ($s2)
/* 0E8DE4 7F0B42B4 01940019 */  multu $t4, $s4
/* 0E8DE8 7F0B42B8 00006812 */  mflo  $t5
/* 0E8DEC 7F0B42BC 022D7021 */  addu  $t6, $s1, $t5
/* 0E8DF0 7F0B42C0 0FC2D204 */  jal   sub_GAME_7F0B4810
/* 0E8DF4 7F0B42C4 C5CC000C */   lwc1  $f12, 0xc($t6)
/* 0E8DF8 7F0B42C8 8E4F0000 */  lw    $t7, ($s2)
/* 0E8DFC 7F0B42CC 01F40019 */  multu $t7, $s4
/* 0E8E00 7F0B42D0 0000C012 */  mflo  $t8
/* 0E8E04 7F0B42D4 0238C821 */  addu  $t9, $s1, $t8
/* 0E8E08 7F0B42D8 0FC2CA54 */  jal   setLevelScale
/* 0E8E0C 7F0B42DC C72C000C */   lwc1  $f12, 0xc($t9)
/* 0E8E10 7F0B42E0 8E480000 */  lw    $t0, ($s2)
/* 0E8E14 7F0B42E4 01140019 */  multu $t0, $s4
/* 0E8E18 7F0B42E8 00004812 */  mflo  $t1
/* 0E8E1C 7F0B42EC 02295021 */  addu  $t2, $s1, $t1
/* 0E8E20 7F0B42F0 0FC2456F */  jal   setDebugCameraScale
/* 0E8E24 7F0B42F4 C54C000C */   lwc1  $f12, 0xc($t2)
/* 0E8E28 7F0B42F8 8E4B0000 */  lw    $t3, ($s2)
/* 0E8E2C 7F0B42FC 01740019 */  multu $t3, $s4
/* 0E8E30 7F0B4300 00006012 */  mflo  $t4
/* 0E8E34 7F0B4304 022C6821 */  addu  $t5, $s1, $t4
/* 0E8E38 7F0B4308 0FC08B87 */  jal    chrRemoved7F022E1C
/* 0E8E3C 7F0B430C C5AC000C */   lwc1  $f12, 0xc($t5)
/* 0E8E40 7F0B4310 8E4E0000 */  lw    $t6, ($s2)
/* 0E8E44 7F0B4314 3C108004 */  lui   $s0, %hi(mCurrentLevelVisibilityScale)
/* 0E8E48 7F0B4318 261013FC */  addiu $s0, %lo(mCurrentLevelVisibilityScale) # addiu $s0, $s0, 0x13fc
/* 0E8E4C 7F0B431C 01D40019 */  multu $t6, $s4
/* 0E8E50 7F0B4320 00007812 */  mflo  $t7
/* 0E8E54 7F0B4324 022FC021 */  addu  $t8, $s1, $t7
/* 0E8E58 7F0B4328 C7040010 */  lwc1  $f4, 0x10($t8)
/* 0E8E5C 7F0B432C E6040000 */  swc1  $f4, ($s0)
/* 0E8E60 7F0B4330 0FC225DB */  jal   sub_GAME_7F08976C
/* 0E8E64 7F0B4334 C60C0000 */   lwc1  $f12, ($s0)
/* 0E8E68 7F0B4338 0FC16313 */  jal   matrix_4x4_7F058C4C
/* 0E8E6C 7F0B433C C60C0000 */   lwc1  $f12, ($s0)
/* 0E8E70 7F0B4340 8EE20000 */  lw    $v0, ($s7)
/* 0E8E74 7F0B4344 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007BF98)
/* 0E8E78 7F0B4348 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007FF88)
/* 0E8E7C 7F0B434C 8C590000 */  lw    $t9, ($v0)
/* 0E8E80 7F0B4350 2484FF88 */  addiu $a0, %lo(dword_CODE_bss_8007FF88) # addiu $a0, $a0, -0x78
/* 0E8E84 7F0B4354 2463BF98 */  addiu $v1, %lo(dword_CODE_bss_8007BF98) # addiu $v1, $v1, -0x4068
/* 0E8E88 7F0B4358 24080001 */  li    $t0, 1
/* 0E8E8C 7F0B435C AC880000 */  sw    $t0, ($a0)
/* 0E8E90 7F0B4360 1720010E */  bnez  $t9, .L7F0B479C
/* 0E8E94 7F0B4364 AC790000 */   sw    $t9, ($v1)
/* 0E8E98 7F0B4368 240A0002 */  li    $t2, 2
/* 0E8E9C 7F0B436C AC8A0000 */  sw    $t2, ($a0)
/* 0E8EA0 7F0B4370 AEC20000 */  sw    $v0, ($s6)
/* 0E8EA4 7F0B4374 8C4B0004 */  lw    $t3, 4($v0)
/* 0E8EA8 7F0B4378 3C168004 */  lui   $s6, %hi(g_MaxNumRooms)
/* 0E8EAC 7F0B437C 26D642F4 */  addiu $s6, %lo(g_MaxNumRooms) # addiu $s6, $s6, 0x42f4
/* 0E8EB0 7F0B4380 01626021 */  addu  $t4, $t3, $v0
/* 0E8EB4 7F0B4384 01936821 */  addu  $t5, $t4, $s3
/* 0E8EB8 7F0B4388 AEAD0000 */  sw    $t5, ($s5)
/* 0E8EBC 7F0B438C AEC00000 */  sw    $zero, ($s6)
/* 0E8EC0 7F0B4390 8DAE001C */  lw    $t6, 0x1c($t5)
/* 0E8EC4 7F0B4394 00402825 */  move  $a1, $v0
/* 0E8EC8 7F0B4398 11C00008 */  beqz  $t6, .L7F0B43BC
/* 0E8ECC 7F0B439C 25A40018 */   addiu $a0, $t5, 0x18
/* 0E8ED0 7F0B43A0 8ECF0000 */  lw    $t7, ($s6)
.L7F0B43A4:
/* 0E8ED4 7F0B43A4 24840018 */  addiu $a0, $a0, 0x18
/* 0E8ED8 7F0B43A8 25F80001 */  addiu $t8, $t7, 1
/* 0E8EDC 7F0B43AC AED80000 */  sw    $t8, ($s6)
/* 0E8EE0 7F0B43B0 8C990004 */  lw    $t9, 4($a0)
/* 0E8EE4 7F0B43B4 5720FFFB */  bnezl $t9, .L7F0B43A4
/* 0E8EE8 7F0B43B8 8ECF0000 */   lw    $t7, ($s6)
.L7F0B43BC:
/* 0E8EEC 7F0B43BC 8CA80008 */  lw    $t0, 8($a1)
/* 0E8EF0 7F0B43C0 3C1E8008 */  lui   $fp, %hi(g_BgPortals)
/* 0E8EF4 7F0B43C4 27DEFF80 */  addiu $fp, %lo(g_BgPortals) # addiu $fp, $fp, -0x80
/* 0E8EF8 7F0B43C8 01024821 */  addu  $t1, $t0, $v0
/* 0E8EFC 7F0B43CC 01335021 */  addu  $t2, $t1, $s3
/* 0E8F00 7F0B43D0 AFCA0000 */  sw    $t2, ($fp)
/* 0E8F04 7F0B43D4 8CA3000C */  lw    $v1, 0xc($a1)
/* 0E8F08 7F0B43D8 14600004 */  bnez  $v1, .L7F0B43EC
/* 0E8F0C 7F0B43DC 3C128008 */   lui   $s2, %hi(dword_CODE_bss_8007FF90)
/* 0E8F10 7F0B43E0 2652FF90 */  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x70
/* 0E8F14 7F0B43E4 1000000F */  b     .L7F0B4424
/* 0E8F18 7F0B43E8 AE400000 */   sw    $zero, ($s2)
.L7F0B43EC:
/* 0E8F1C 7F0B43EC 3C128008 */  lui   $s2, %hi(dword_CODE_bss_8007FF90)
/* 0E8F20 7F0B43F0 00625821 */  addu  $t3, $v1, $v0
/* 0E8F24 7F0B43F4 2652FF90 */  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x70
/* 0E8F28 7F0B43F8 01736021 */  addu  $t4, $t3, $s3
/* 0E8F2C 7F0B43FC AE4C0000 */  sw    $t4, ($s2)
/* 0E8F30 7F0B4400 8CA40010 */  lw    $a0, 0x10($a1)
/* 0E8F34 7F0B4404 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007FF94)
/* 0E8F38 7F0B4408 14800004 */  bnez  $a0, .L7F0B441C
/* 0E8F3C 7F0B440C 00826821 */   addu  $t5, $a0, $v0
/* 0E8F40 7F0B4410 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007FF94)
/* 0E8F44 7F0B4414 10000003 */  b     .L7F0B4424
/* 0E8F48 7F0B4418 AC20FF94 */   sw    $zero, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B441C:
/* 0E8F4C 7F0B441C 01B37021 */  addu  $t6, $t5, $s3
/* 0E8F50 7F0B4420 AC2EFF94 */  sw    $t6, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B4424:
/* 0E8F54 7F0B4424 8FC40000 */  lw    $a0, ($fp)
/* 0E8F58 7F0B4428 00008025 */  move  $s0, $zero
/* 0E8F5C 7F0B442C 8C8F0000 */  lw    $t7, ($a0)
/* 0E8F60 7F0B4430 00801025 */  move  $v0, $a0
/* 0E8F64 7F0B4434 11E0000B */  beqz  $t7, .L7F0B4464
/* 0E8F68 7F0B4438 01E01825 */   move  $v1, $t7
/* 0E8F6C 7F0B443C 8EF80000 */  lw    $t8, ($s7)
.L7F0B4440:
/* 0E8F70 7F0B4440 26100008 */  addiu $s0, $s0, 8
/* 0E8F74 7F0B4444 0078C821 */  addu  $t9, $v1, $t8
/* 0E8F78 7F0B4448 03334021 */  addu  $t0, $t9, $s3
/* 0E8F7C 7F0B444C AC480000 */  sw    $t0, ($v0)
/* 0E8F80 7F0B4450 8FC90000 */  lw    $t1, ($fp)
/* 0E8F84 7F0B4454 01301021 */  addu  $v0, $t1, $s0
/* 0E8F88 7F0B4458 8C430000 */  lw    $v1, ($v0)
/* 0E8F8C 7F0B445C 5460FFF8 */  bnezl $v1, .L7F0B4440
/* 0E8F90 7F0B4460 8EF80000 */   lw    $t8, ($s7)
.L7F0B4464:
/* 0E8F94 7F0B4464 8E440000 */  lw    $a0, ($s2)
/* 0E8F98 7F0B4468 50800019 */  beql  $a0, $zero, .L7F0B44D0
/* 0E8F9C 7F0B446C 8ED90000 */   lw    $t9, ($s6)
/* 0E8FA0 7F0B4470 908A0000 */  lbu   $t2, ($a0)
/* 0E8FA4 7F0B4474 00008025 */  move  $s0, $zero
/* 0E8FA8 7F0B4478 00801825 */  move  $v1, $a0
/* 0E8FAC 7F0B447C 11400013 */  beqz  $t2, .L7F0B44CC
/* 0E8FB0 7F0B4480 314200FF */   andi  $v0, $t2, 0xff
/* 0E8FB4 7F0B4484 24110064 */  li    $s1, 100
.L7F0B4488:
/* 0E8FB8 7F0B4488 5622000C */  bnel  $s1, $v0, .L7F0B44BC
/* 0E8FBC 7F0B448C 90620008 */   lbu   $v0, 8($v1)
/* 0E8FC0 7F0B4490 8C6B0004 */  lw    $t3, 4($v1)
/* 0E8FC4 7F0B4494 8EEC0000 */  lw    $t4, ($s7)
/* 0E8FC8 7F0B4498 016C6821 */  addu  $t5, $t3, $t4
/* 0E8FCC 7F0B449C 0FC2D7A2 */  jal   getIndexOfPORTALID
/* 0E8FD0 7F0B44A0 01B32021 */   addu  $a0, $t5, $s3
/* 0E8FD4 7F0B44A4 8E4E0000 */  lw    $t6, ($s2)
/* 0E8FD8 7F0B44A8 01D07821 */  addu  $t7, $t6, $s0
/* 0E8FDC 7F0B44AC ADE20004 */  sw    $v0, 4($t7)
/* 0E8FE0 7F0B44B0 8E580000 */  lw    $t8, ($s2)
/* 0E8FE4 7F0B44B4 03101821 */  addu  $v1, $t8, $s0
/* 0E8FE8 7F0B44B8 90620008 */  lbu   $v0, 8($v1)
.L7F0B44BC:
/* 0E8FEC 7F0B44BC 26100008 */  addiu $s0, $s0, 8
/* 0E8FF0 7F0B44C0 24630008 */  addiu $v1, $v1, 8
/* 0E8FF4 7F0B44C4 1440FFF0 */  bnez  $v0, .L7F0B4488
/* 0E8FF8 7F0B44C8 00000000 */   nop
.L7F0B44CC:
/* 0E8FFC 7F0B44CC 8ED90000 */  lw    $t9, ($s6)
.L7F0B44D0:
/* 0E9000 7F0B44D0 3C108004 */  lui   $s0, %hi(g_BgRoomInfo + 0x10 +0x40)
/* 0E9004 7F0B44D4 26101464 */  addiu $s0, %lo(g_BgRoomInfo + 0x10 +0x40) # addiu $s0, $s0, 0x1464
/* 0E9008 7F0B44D8 2B210002 */  slti  $at, $t9, 2
/* 0E900C 7F0B44DC 14200064 */  bnez  $at, .L7F0B4670
/* 0E9010 7F0B44E0 24110001 */   li    $s1, 1
/* 0E9014 7F0B44E4 8EA40000 */  lw    $a0, ($s5)
/* 0E9018 7F0B44E8 24130018 */  li    $s3, 24
/* 0E901C 7F0B44EC 2417FFFF */  li    $s7, -1
/* 0E9020 7F0B44F0 24840018 */  addiu $a0, $a0, 0x18
.L7F0B44F4:
/* 0E9024 7F0B44F4 A2000002 */  sb    $zero, 2($s0)
/* 0E9028 7F0B44F8 A2000035 */  sb    $zero, 0x35($s0)
/* 0E902C 7F0B44FC 8C880004 */  lw    $t0, 4($a0)
/* 0E9030 7F0B4500 26320001 */  addiu $s2, $s1, 1
/* 0E9034 7F0B4504 51000020 */  beql  $t0, $zero, .L7F0B4588
/* 0E9038 7F0B4508 AE000014 */   sw    $zero, 0x14($s0)
/* 0E903C 7F0B450C 26320001 */  addiu $s2, $s1, 1
/* 0E9040 7F0B4510 0FC2D00D */  jal   sub_GAME_7F0B4034
/* 0E9044 7F0B4514 02402025 */   move  $a0, $s2
/* 0E9048 7F0B4518 02202025 */  move  $a0, $s1
/* 0E904C 7F0B451C 0FC2D021 */  jal   sub_GAME_7F0B4084
/* 0E9050 7F0B4520 AFA20068 */   sw    $v0, 0x68($sp)
/* 0E9054 7F0B4524 8FA50068 */  lw    $a1, 0x68($sp)
/* 0E9058 7F0B4528 0045082A */  slt   $at, $v0, $a1
/* 0E905C 7F0B452C 1420000B */  bnez  $at, .L7F0B455C
/* 0E9060 7F0B4530 00000000 */   nop
/* 0E9064 7F0B4534 00B40019 */  multu $a1, $s4
/* 0E9068 7F0B4538 8EA30000 */  lw    $v1, ($s5)
/* 0E906C 7F0B453C 00732021 */  addu  $a0, $v1, $s3
/* 0E9070 7F0B4540 8C8C0004 */  lw    $t4, 4($a0)
/* 0E9074 7F0B4544 00004812 */  mflo  $t1
/* 0E9078 7F0B4548 00695021 */  addu  $t2, $v1, $t1
/* 0E907C 7F0B454C 8D4B0004 */  lw    $t3, 4($t2)
/* 0E9080 7F0B4550 016C6823 */  subu  $t5, $t3, $t4
/* 0E9084 7F0B4554 1000000C */  b     .L7F0B4588
/* 0E9088 7F0B4558 AE0D0014 */   sw    $t5, 0x14($s0)
.L7F0B455C:
/* 0E908C 7F0B455C 00540019 */  multu $v0, $s4
/* 0E9090 7F0B4560 8EA30000 */  lw    $v1, ($s5)
/* 0E9094 7F0B4564 00732021 */  addu  $a0, $v1, $s3
/* 0E9098 7F0B4568 8C990004 */  lw    $t9, 4($a0)
/* 0E909C 7F0B456C 00007012 */  mflo  $t6
/* 0E90A0 7F0B4570 006E7821 */  addu  $t7, $v1, $t6
/* 0E90A4 7F0B4574 8DF80008 */  lw    $t8, 8($t7)
/* 0E90A8 7F0B4578 03194023 */  subu  $t0, $t8, $t9
/* 0E90AC 7F0B457C 10000002 */  b     .L7F0B4588
/* 0E90B0 7F0B4580 AE080014 */   sw    $t0, 0x14($s0)
/* 0E90B4 7F0B4584 AE000014 */  sw    $zero, 0x14($s0)
.L7F0B4588:
/* 0E90B8 7F0B4588 8C890008 */  lw    $t1, 8($a0)
/* 0E90BC 7F0B458C 5120001E */  beql  $t1, $zero, .L7F0B4608
/* 0E90C0 7F0B4590 AE000018 */   sw    $zero, 0x18($s0)
/* 0E90C4 7F0B4594 0FC2D00D */  jal   sub_GAME_7F0B4034
/* 0E90C8 7F0B4598 02402025 */   move  $a0, $s2
/* 0E90CC 7F0B459C 00408825 */  move  $s1, $v0
/* 0E90D0 7F0B45A0 0FC2D021 */  jal   sub_GAME_7F0B4084
/* 0E90D4 7F0B45A4 02402025 */   move  $a0, $s2
/* 0E90D8 7F0B45A8 0051082A */  slt   $at, $v0, $s1
/* 0E90DC 7F0B45AC 1420000B */  bnez  $at, .L7F0B45DC
/* 0E90E0 7F0B45B0 00000000 */   nop
/* 0E90E4 7F0B45B4 02340019 */  multu $s1, $s4
/* 0E90E8 7F0B45B8 8EA30000 */  lw    $v1, ($s5)
/* 0E90EC 7F0B45BC 00732021 */  addu  $a0, $v1, $s3
/* 0E90F0 7F0B45C0 8C8D0008 */  lw    $t5, 8($a0)
/* 0E90F4 7F0B45C4 00005012 */  mflo  $t2
/* 0E90F8 7F0B45C8 006A5821 */  addu  $t3, $v1, $t2
/* 0E90FC 7F0B45CC 8D6C0004 */  lw    $t4, 4($t3)
/* 0E9100 7F0B45D0 018D7023 */  subu  $t6, $t4, $t5
/* 0E9104 7F0B45D4 1000000C */  b     .L7F0B4608
/* 0E9108 7F0B45D8 AE0E0018 */   sw    $t6, 0x18($s0)
.L7F0B45DC:
/* 0E910C 7F0B45DC 00540019 */  multu $v0, $s4
/* 0E9110 7F0B45E0 8EA30000 */  lw    $v1, ($s5)
/* 0E9114 7F0B45E4 00732021 */  addu  $a0, $v1, $s3
/* 0E9118 7F0B45E8 8C880008 */  lw    $t0, 8($a0)
/* 0E911C 7F0B45EC 00007812 */  mflo  $t7
/* 0E9120 7F0B45F0 006FC021 */  addu  $t8, $v1, $t7
/* 0E9124 7F0B45F4 8F190008 */  lw    $t9, 8($t8)
/* 0E9128 7F0B45F8 03284823 */  subu  $t1, $t9, $t0
/* 0E912C 7F0B45FC 10000002 */  b     .L7F0B4608
/* 0E9130 7F0B4600 AE090018 */   sw    $t1, 0x18($s0)
/* 0E9134 7F0B4604 AE000018 */  sw    $zero, 0x18($s0)
.L7F0B4608:
/* 0E9138 7F0B4608 8C8A0000 */  lw    $t2, ($a0)
/* 0E913C 7F0B460C 5140000F */  beql  $t2, $zero, .L7F0B464C
/* 0E9140 7F0B4610 AE000010 */   sw    $zero, 0x10($s0)
/* 0E9144 7F0B4614 0FC2D035 */  jal   sub_GAME_7F0B40D4
/* 0E9148 7F0B4618 02402025 */   move  $a0, $s2
/* 0E914C 7F0B461C 00540019 */  multu $v0, $s4
/* 0E9150 7F0B4620 8EA30000 */  lw    $v1, ($s5)
/* 0E9154 7F0B4624 8EC50000 */  lw    $a1, ($s6)
/* 0E9158 7F0B4628 00732021 */  addu  $a0, $v1, $s3
/* 0E915C 7F0B462C 8C8E0000 */  lw    $t6, ($a0)
/* 0E9160 7F0B4630 00005812 */  mflo  $t3
/* 0E9164 7F0B4634 006B6021 */  addu  $t4, $v1, $t3
/* 0E9168 7F0B4638 8D8D0000 */  lw    $t5, ($t4)
/* 0E916C 7F0B463C 01AE7823 */  subu  $t7, $t5, $t6
/* 0E9170 7F0B4640 10000003 */  b     .L7F0B4650
/* 0E9174 7F0B4644 AE0F0010 */   sw    $t7, 0x10($s0)
/* 0E9178 7F0B4648 AE000010 */  sw    $zero, 0x10($s0)
.L7F0B464C:
/* 0E917C 7F0B464C 8EC50000 */  lw    $a1, ($s6)
.L7F0B4650:
/* 0E9180 7F0B4650 0245082A */  slt   $at, $s2, $a1
/* 0E9184 7F0B4654 02408825 */  move  $s1, $s2
/* 0E9188 7F0B4658 26100050 */  addiu $s0, $s0, 0x50
/* 0E918C 7F0B465C 26730018 */  addiu $s3, $s3, 0x18
/* 0E9190 7F0B4660 24840018 */  addiu $a0, $a0, 0x18
/* 0E9194 7F0B4664 1420FFA3 */  bnez  $at, .L7F0B44F4
/* 0E9198 7F0B4668 AE17FFD8 */   sw    $s7, -0x28($s0)
/* 0E919C 7F0B466C 24110001 */  li    $s1, 1
.L7F0B4670:
/* 0E91A0 7F0B4670 0FC2F14C */  jal   initializeRoomData
/* 0E91A4 7F0B4674 00000000 */   nop
/* 0E91A8 7F0B4678 8ED80000 */  lw    $t8, ($s6)
/* 0E91AC 7F0B467C 2B010002 */  slti  $at, $t8, 2
/* 0E91B0 7F0B4680 54200009 */  bnezl $at, .L7F0B46A8
/* 0E91B4 7F0B4684 8FC40000 */   lw    $a0, ($fp)
.L7F0B4688:
/* 0E91B8 7F0B4688 0FC2E4CE */  jal   sub_GAME_7F0B9338
/* 0E91BC 7F0B468C 02202025 */   move  $a0, $s1
/* 0E91C0 7F0B4690 8ED90000 */  lw    $t9, ($s6)
/* 0E91C4 7F0B4694 26310001 */  addiu $s1, $s1, 1
/* 0E91C8 7F0B4698 0239082A */  slt   $at, $s1, $t9
/* 0E91CC 7F0B469C 1420FFFA */  bnez  $at, .L7F0B4688
/* 0E91D0 7F0B46A0 00000000 */   nop
/* 0E91D4 7F0B46A4 8FC40000 */  lw    $a0, ($fp)
.L7F0B46A8:
/* 0E91D8 7F0B46A8 3C038004 */  lui   $v1, %hi(D_800443C4)
/* 0E91DC 7F0B46AC 246343C4 */  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, 0x43c4
/* 0E91E0 7F0B46B0 8C820000 */  lw    $v0, ($a0)
/* 0E91E4 7F0B46B4 00008825 */  move  $s1, $zero
/* 0E91E8 7F0B46B8 00008025 */  move  $s0, $zero
/* 0E91EC 7F0B46BC 10400010 */  beqz  $v0, .L7F0B4700
/* 0E91F0 7F0B46C0 00000000 */   nop
/* 0E91F4 7F0B46C4 02202025 */  move  $a0, $s1
.L7F0B46C8:
/* 0E91F8 7F0B46C8 0FC2E64F */  jal   sub_GAME_7F0B993C
/* 0E91FC 7F0B46CC AFA3004C */   sw    $v1, 0x4c($sp)
/* 0E9200 7F0B46D0 8FC40000 */  lw    $a0, ($fp)
/* 0E9204 7F0B46D4 8FA3004C */  lw    $v1, 0x4c($sp)
/* 0E9208 7F0B46D8 26100008 */  addiu $s0, $s0, 8
/* 0E920C 7F0B46DC 00904021 */  addu  $t0, $a0, $s0
/* 0E9210 7F0B46E0 A0620000 */  sb    $v0, ($v1)
/* 0E9214 7F0B46E4 8D090000 */  lw    $t1, ($t0)
/* 0E9218 7F0B46E8 26310001 */  addiu $s1, $s1, 1
/* 0E921C 7F0B46EC 24630001 */  addiu $v1, $v1, 1
/* 0E9220 7F0B46F0 5520FFF5 */  bnezl $t1, .L7F0B46C8
/* 0E9224 7F0B46F4 02202025 */   move  $a0, $s1
/* 0E9228 7F0B46F8 00008825 */  move  $s1, $zero
/* 0E922C 7F0B46FC 8C820000 */  lw    $v0, ($a0)
.L7F0B4700:
/* 0E9230 7F0B4700 1040000B */  beqz  $v0, .L7F0B4730
/* 0E9234 7F0B4704 00008025 */   move  $s0, $zero
.L7F0B4708:
/* 0E9238 7F0B4708 0FC2E6E5 */  jal   sub_GAME_7F0B9B94
/* 0E923C 7F0B470C 02202025 */   move  $a0, $s1
/* 0E9240 7F0B4710 8FC40000 */  lw    $a0, ($fp)
/* 0E9244 7F0B4714 26100008 */  addiu $s0, $s0, 8
/* 0E9248 7F0B4718 26310001 */  addiu $s1, $s1, 1
/* 0E924C 7F0B471C 00905021 */  addu  $t2, $a0, $s0
/* 0E9250 7F0B4720 8D4B0000 */  lw    $t3, ($t2)
/* 0E9254 7F0B4724 1560FFF8 */  bnez  $t3, .L7F0B4708
/* 0E9258 7F0B4728 00000000 */   nop
/* 0E925C 7F0B472C 00008825 */  move  $s1, $zero
.L7F0B4730:
/* 0E9260 7F0B4730 8ECC0000 */  lw    $t4, ($s6)
/* 0E9264 7F0B4734 5980000A */  blezl $t4, .L7F0B4760
/* 0E9268 7F0B4738 8C8E0000 */   lw    $t6, ($a0)
.L7F0B473C:
/* 0E926C 7F0B473C 0FC2E576 */  jal   sub_GAME_7F0B95D8
/* 0E9270 7F0B4740 02202025 */   move  $a0, $s1
/* 0E9274 7F0B4744 8ECD0000 */  lw    $t5, ($s6)
/* 0E9278 7F0B4748 26310001 */  addiu $s1, $s1, 1
/* 0E927C 7F0B474C 022D082A */  slt   $at, $s1, $t5
/* 0E9280 7F0B4750 1420FFFA */  bnez  $at, .L7F0B473C
/* 0E9284 7F0B4754 00000000 */   nop
/* 0E9288 7F0B4758 8FC40000 */  lw    $a0, ($fp)
/* 0E928C 7F0B475C 8C8E0000 */  lw    $t6, ($a0)
.L7F0B4760:
/* 0E9290 7F0B4760 00008025 */  move  $s0, $zero
/* 0E9294 7F0B4764 00801025 */  move  $v0, $a0
/* 0E9298 7F0B4768 11C0000A */  beqz  $t6, .L7F0B4794
/* 0E929C 7F0B476C 00000000 */   nop
/* 0E92A0 7F0B4770 904F0006 */  lbu   $t7, 6($v0)
.L7F0B4774:
/* 0E92A4 7F0B4774 26100008 */  addiu $s0, $s0, 8
/* 0E92A8 7F0B4778 31F800FE */  andi  $t8, $t7, 0xfe
/* 0E92AC 7F0B477C A0580006 */  sb    $t8, 6($v0)
/* 0E92B0 7F0B4780 8FD90000 */  lw    $t9, ($fp)
/* 0E92B4 7F0B4784 03301021 */  addu  $v0, $t9, $s0
/* 0E92B8 7F0B4788 8C480000 */  lw    $t0, ($v0)
/* 0E92BC 7F0B478C 5500FFF9 */  bnezl $t0, .L7F0B4774
/* 0E92C0 7F0B4790 904F0006 */   lbu   $t7, 6($v0)
.L7F0B4794:
/* 0E92C4 7F0B4794 0FC2CDFB */  jal   sub_GAME_7F0B37EC
/* 0E92C8 7F0B4798 00000000 */   nop
.L7F0B479C:
/* 0E92CC 7F0B479C 0FC2EA97 */  jal   fogRemoved7F0BAA5C
/* 0E92D0 7F0B47A0 8FA400B8 */   lw    $a0, 0xb8($sp)
/* 0E92D4 7F0B47A4 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E92D8 7F0B47A8 240900C8 */  li    $t1, 200
/* 0E92DC 7F0B47AC 3C018004 */  lui   $at, %hi(D_800442F8)
/* 0E92E0 7F0B47B0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E92E4 7F0B47B4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E92E8 7F0B47B8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E92EC 7F0B47BC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E92F0 7F0B47C0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E92F4 7F0B47C4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E92F8 7F0B47C8 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E92FC 7F0B47CC 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E9300 7F0B47D0 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E9304 7F0B47D4 AC2942F8 */  sw    $t1, %lo(D_800442F8)($at)
/* 0E9308 7F0B47D8 03E00008 */  jr    $ra
/* 0E930C 7F0B47DC 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel load_bg_file
/* 0E5E50 7F0B3460 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0E5E54 7F0B3464 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E5E58 7F0B3468 3C128004 */  lui   $s2, %hi(levelentry_index) # $s2, 0x8004
/* 0E5E5C 7F0B346C AFB00018 */  sw    $s0, 0x18($sp)
/* 0E5E60 7F0B3470 2652AC50 */  addiu $s2, %lo(levelentry_index) # addiu $s2, $s2, -0x53b0
/* 0E5E64 7F0B3474 3C108004 */  lui   $s0, %hi(g_BgRoomInfo) # $s0, 0x8004
/* 0E5E68 7F0B3478 3C028004 */  lui   $v0, %hi(g_MaxNumRooms) # $v0, 0x8004
/* 0E5E6C 7F0B347C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E5E70 7F0B3480 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E5E74 7F0B3484 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E5E78 7F0B3488 AFB60030 */  sw    $s6, 0x30($sp)
/* 0E5E7C 7F0B348C AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E5E80 7F0B3490 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E5E84 7F0B3494 AFB30024 */  sw    $s3, 0x24($sp)
/* 0E5E88 7F0B3498 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E5E8C 7F0B349C AE400000 */  sw    $zero, ($s2)
/* 0E5E90 7F0B34A0 2442D7D4 */  addiu $v0, %lo(g_MaxNumRooms) # addiu $v0, $v0, -0x282c
/* 0E5E94 7F0B34A4 2610AC64 */  addiu $s0, %lo(g_BgRoomInfo) # addiu $s0, $s0, -0x539c
.L7F0B34A8:
/* 0E5E98 7F0B34A8 26100050 */  addiu $s0, $s0, 0x50
/* 0E5E9C 7F0B34AC 0202082B */  sltu  $at, $s0, $v0
/* 0E5EA0 7F0B34B0 1420FFFD */  bnez  $at, .L7F0B34A8
/* 0E5EA4 7F0B34B4 AE00FFDC */   sw    $zero, -0x24($s0)
/* 0E5EA8 7F0B34B8 3C028004 */  lui   $v0, %hi(levelinfotable) # $v0, 0x8004
/* 0E5EAC 7F0B34BC 2442D96C */  addiu $v0, %lo(levelinfotable) # addiu $v0, $v0, -0x2694
/* 0E5EB0 7F0B34C0 00008825 */  move  $s1, $zero
.L7F0B34C4:
/* 0E5EB4 7F0B34C4 8C4E0000 */  lw    $t6, ($v0)
/* 0E5EB8 7F0B34C8 548E0003 */  bnel  $a0, $t6, .L7F0B34D8
/* 0E5EBC 7F0B34CC 26310001 */   addiu $s1, $s1, 1
/* 0E5EC0 7F0B34D0 AE510000 */  sw    $s1, ($s2)
/* 0E5EC4 7F0B34D4 26310001 */  addiu $s1, $s1, 1
.L7F0B34D8:
/* 0E5EC8 7F0B34D8 2A210026 */  slti  $at, $s1, 0x26
/* 0E5ECC 7F0B34DC 1420FFF9 */  bnez  $at, .L7F0B34C4
/* 0E5ED0 7F0B34E0 24420018 */   addiu $v0, $v0, 0x18
/* 0E5ED4 7F0B34E4 0FC2EA34 */  jal   init_lightfixture_tables
/* 0E5ED8 7F0B34E8 AFA400B8 */   sw    $a0, 0xb8($sp)
/* 0E5EDC 7F0B34EC 8E580000 */  lw    $t8, ($s2)
/* 0E5EE0 7F0B34F0 24140018 */  li    $s4, 24
/* 0E5EE4 7F0B34F4 3C118004 */  lui   $s1, %hi(levelinfotable) # $s1, 0x8004
/* 0E5EE8 7F0B34F8 03140019 */  multu $t8, $s4
/* 0E5EEC 7F0B34FC 2631D96C */  addiu $s1, %lo(levelinfotable) # addiu $s1, $s1, -0x2694
/* 0E5EF0 7F0B3500 3C178007 */  lui   $s7, %hi(ptr_bg_data) # $s7, 0x8007
/* 0E5EF4 7F0B3504 26F79EE0 */  addiu $s7, %lo(ptr_bg_data) # addiu $s7, $s7, -0x6120
/* 0E5EF8 7F0B3508 27A50070 */  addiu $a1, $sp, 0x70
/* 0E5EFC 7F0B350C AEE50000 */  sw    $a1, ($s7)
/* 0E5F00 7F0B3510 00003025 */  move  $a2, $zero
/* 0E5F04 7F0B3514 24070040 */  li    $a3, 64
/* 0E5F08 7F0B3518 0000C812 */  mflo  $t9
/* 0E5F0C 7F0B351C 02394021 */  addu  $t0, $s1, $t9
/* 0E5F10 7F0B3520 0FC2F02F */  jal   obLoadBGFileBytesAtOffset
/* 0E5F14 7F0B3524 8D040004 */   lw    $a0, 4($t0)
/* 0E5F18 7F0B3528 8EE20000 */  lw    $v0, ($s7)
/* 0E5F1C 7F0B352C 3C168007 */  lui   $s6, %hi(ptr_bgdata_offsets) # $s6, 0x8007
/* 0E5F20 7F0B3530 26D6B3CC */  addiu $s6, %lo(ptr_bgdata_offsets) # addiu $s6, $s6, -0x4c34
/* 0E5F24 7F0B3534 AEC20000 */  sw    $v0, ($s6)
/* 0E5F28 7F0B3538 8C4A0004 */  lw    $t2, 4($v0)
/* 0E5F2C 7F0B353C 3C13F100 */  lui   $s3, 0xf100
/* 0E5F30 7F0B3540 3C158007 */  lui   $s5, %hi(ptr_bgdata_room_fileposition_list) # $s5, 0x8007
/* 0E5F34 7F0B3544 01425821 */  addu  $t3, $t2, $v0
/* 0E5F38 7F0B3548 26B5B3D4 */  addiu $s5, %lo(ptr_bgdata_room_fileposition_list) # addiu $s5, $s5, -0x4c2c
/* 0E5F3C 7F0B354C 01736021 */  addu  $t4, $t3, $s3
/* 0E5F40 7F0B3550 AEAC0000 */  sw    $t4, ($s5)
/* 0E5F44 7F0B3554 8D900018 */  lw    $s0, 0x18($t4)
/* 0E5F48 7F0B3558 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0E5F4C 7F0B355C 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0E5F50 7F0B3560 02017024 */  and   $t6, $s0, $at
/* 0E5F54 7F0B3564 25D0FFFF */  addiu $s0, $t6, -1
/* 0E5F58 7F0B3568 360F000F */  ori   $t7, $s0, 0xf
/* 0E5F5C 7F0B356C 25F00001 */  addiu $s0, $t7, 1
/* 0E5F60 7F0B3570 02002025 */  move  $a0, $s0
/* 0E5F64 7F0B3574 0C0022E0 */  jal   mempAllocBytesInBank
/* 0E5F68 7F0B3578 24050004 */   li    $a1, 4
/* 0E5F6C 7F0B357C 8E580000 */  lw    $t8, ($s2)
/* 0E5F70 7F0B3580 AEE20000 */  sw    $v0, ($s7)
/* 0E5F74 7F0B3584 00402825 */  move  $a1, $v0
/* 0E5F78 7F0B3588 03140019 */  multu $t8, $s4
/* 0E5F7C 7F0B358C 00003025 */  move  $a2, $zero
/* 0E5F80 7F0B3590 02003825 */  move  $a3, $s0
/* 0E5F84 7F0B3594 0000C812 */  mflo  $t9
/* 0E5F88 7F0B3598 02394021 */  addu  $t0, $s1, $t9
/* 0E5F8C 7F0B359C 0FC2F02F */  jal   obLoadBGFileBytesAtOffset
/* 0E5F90 7F0B35A0 8D040004 */   lw    $a0, 4($t0)
/* 0E5F94 7F0B35A4 8E490000 */  lw    $t1, ($s2)
/* 0E5F98 7F0B35A8 24050002 */  li    $a1, 2
/* 0E5F9C 7F0B35AC 00003025 */  move  $a2, $zero
/* 0E5FA0 7F0B35B0 01340019 */  multu $t1, $s4
/* 0E5FA4 7F0B35B4 24070004 */  li    $a3, 4
/* 0E5FA8 7F0B35B8 00005012 */  mflo  $t2
/* 0E5FAC 7F0B35BC 022A5821 */  addu  $t3, $s1, $t2
/* 0E5FB0 7F0B35C0 0FC2F053 */  jal   _fileNameLoadToBank
/* 0E5FB4 7F0B35C4 8D640008 */   lw    $a0, 8($t3)
/* 0E5FB8 7F0B35C8 3C108007 */  lui   $s0, %hi(gptr_stan) # $s0, 0x8007
/* 0E5FBC 7F0B35CC 26109EE4 */  addiu $s0, %lo(gptr_stan) # addiu $s0, $s0, -0x611c
/* 0E5FC0 7F0B35D0 AE020000 */  sw    $v0, ($s0)
/* 0E5FC4 7F0B35D4 00402025 */  move  $a0, $v0
/* 0E5FC8 7F0B35D8 00002825 */  move  $a1, $zero
/* 0E5FCC 7F0B35DC 0FC2C87B */  jal   stanDetermineEOF
/* 0E5FD0 7F0B35E0 00403025 */   move  $a2, $v0
/* 0E5FD4 7F0B35E4 0FC2BA1E */  jal   stanLoadFile
/* 0E5FD8 7F0B35E8 8E040000 */   lw    $a0, ($s0)
/* 0E5FDC 7F0B35EC 8E4C0000 */  lw    $t4, ($s2)
/* 0E5FE0 7F0B35F0 01940019 */  multu $t4, $s4
/* 0E5FE4 7F0B35F4 00006812 */  mflo  $t5
/* 0E5FE8 7F0B35F8 022D7021 */  addu  $t6, $s1, $t5
/* 0E5FEC 7F0B35FC 0FC2CED3 */  jal   sub_GAME_7F0B4810
/* 0E5FF0 7F0B3600 C5CC000C */   lwc1  $f12, 0xc($t6)
/* 0E5FF4 7F0B3604 8E4F0000 */  lw    $t7, ($s2)
/* 0E5FF8 7F0B3608 01F40019 */  multu $t7, $s4
/* 0E5FFC 7F0B360C 0000C012 */  mflo  $t8
/* 0E6000 7F0B3610 0238C821 */  addu  $t9, $s1, $t8
/* 0E6004 7F0B3614 0FC2C704 */  jal   setLevelScale
/* 0E6008 7F0B3618 C72C000C */   lwc1  $f12, 0xc($t9)
/* 0E600C 7F0B361C 8E480000 */  lw    $t0, ($s2)
/* 0E6010 7F0B3620 01140019 */  multu $t0, $s4
/* 0E6014 7F0B3624 00004812 */  mflo  $t1
/* 0E6018 7F0B3628 02295021 */  addu  $t2, $s1, $t1
/* 0E601C 7F0B362C 0FC2428F */  jal   setDebugCameraScale
/* 0E6020 7F0B3630 C54C000C */   lwc1  $f12, 0xc($t2)
/* 0E6024 7F0B3634 8E4B0000 */  lw    $t3, ($s2)
/* 0E6028 7F0B3638 01740019 */  multu $t3, $s4
/* 0E602C 7F0B363C 00006012 */  mflo  $t4
/* 0E6030 7F0B3640 022C6821 */  addu  $t5, $s1, $t4
/* 0E6034 7F0B3644 0FC08B79 */  jal   chrRemoved7F022E1C
/* 0E6038 7F0B3648 C5AC000C */   lwc1  $f12, 0xc($t5)
/* 0E603C 7F0B364C 8E4E0000 */  lw    $t6, ($s2)
/* 0E6040 7F0B3650 3C108004 */  lui   $s0, %hi(mCurrentLevelVisibilityScale) # $s0, 0x8004
/* 0E6044 7F0B3654 2610AC4C */  addiu $s0, %lo(mCurrentLevelVisibilityScale) # addiu $s0, $s0, -0x53b4
/* 0E6048 7F0B3658 01D40019 */  multu $t6, $s4
/* 0E604C 7F0B365C 00007812 */  mflo  $t7
/* 0E6050 7F0B3660 022FC021 */  addu  $t8, $s1, $t7
/* 0E6054 7F0B3664 C7040010 */  lwc1  $f4, 0x10($t8)
/* 0E6058 7F0B3668 E6040000 */  swc1  $f4, ($s0)
/* 0E605C 7F0B366C 0FC22635 */  jal   sub_GAME_7F08976C
/* 0E6060 7F0B3670 C60C0000 */   lwc1  $f12, ($s0)
/* 0E6064 7F0B3674 0FC1643D */  jal   matrix_4x4_7F058C4C
/* 0E6068 7F0B3678 C60C0000 */   lwc1  $f12, ($s0)
/* 0E606C 7F0B367C 8EE20000 */  lw    $v0, ($s7)
/* 0E6070 7F0B3680 3C038007 */  lui   $v1, %hi(dword_CODE_bss_8007BF98) # $v1, 0x8007
/* 0E6074 7F0B3684 3C048007 */  lui   $a0, %hi(dword_CODE_bss_8007FF88) # $a0, 0x8007
/* 0E6078 7F0B3688 8C590000 */  lw    $t9, ($v0)
/* 0E607C 7F0B368C 2484B3D0 */  addiu $a0, %lo(dword_CODE_bss_8007FF88) # addiu $a0, $a0, -0x4c30
/* 0E6080 7F0B3690 24639EE8 */  addiu $v1, %lo(dword_CODE_bss_8007BF98) # addiu $v1, $v1, -0x6118
/* 0E6084 7F0B3694 24080001 */  li    $t0, 1
/* 0E6088 7F0B3698 AC880000 */  sw    $t0, ($a0)
/* 0E608C 7F0B369C 1720010E */  bnez  $t9, .L7F0B3AD8
/* 0E6090 7F0B36A0 AC790000 */   sw    $t9, ($v1)
/* 0E6094 7F0B36A4 240A0002 */  li    $t2, 2
/* 0E6098 7F0B36A8 AC8A0000 */  sw    $t2, ($a0)
/* 0E609C 7F0B36AC AEC20000 */  sw    $v0, ($s6)
/* 0E60A0 7F0B36B0 8C4B0004 */  lw    $t3, 4($v0)
/* 0E60A4 7F0B36B4 3C168004 */  lui   $s6, %hi(g_MaxNumRooms) # $s6, 0x8004
/* 0E60A8 7F0B36B8 26D6D7D4 */  addiu $s6, %lo(g_MaxNumRooms) # addiu $s6, $s6, -0x282c
/* 0E60AC 7F0B36BC 01626021 */  addu  $t4, $t3, $v0
/* 0E60B0 7F0B36C0 01936821 */  addu  $t5, $t4, $s3
/* 0E60B4 7F0B36C4 AEAD0000 */  sw    $t5, ($s5)
/* 0E60B8 7F0B36C8 AEC00000 */  sw    $zero, ($s6)
/* 0E60BC 7F0B36CC 8DAE001C */  lw    $t6, 0x1c($t5)
/* 0E60C0 7F0B36D0 00402825 */  move  $a1, $v0
/* 0E60C4 7F0B36D4 11C00008 */  beqz  $t6, .L7F0B36F8
/* 0E60C8 7F0B36D8 25A40018 */   addiu $a0, $t5, 0x18
/* 0E60CC 7F0B36DC 8ECF0000 */  lw    $t7, ($s6)
.L7F0B36E0:
/* 0E60D0 7F0B36E0 24840018 */  addiu $a0, $a0, 0x18
/* 0E60D4 7F0B36E4 25F80001 */  addiu $t8, $t7, 1
/* 0E60D8 7F0B36E8 AED80000 */  sw    $t8, ($s6)
/* 0E60DC 7F0B36EC 8C990004 */  lw    $t9, 4($a0)
/* 0E60E0 7F0B36F0 5720FFFB */  bnezl $t9, .L7F0B36E0
/* 0E60E4 7F0B36F4 8ECF0000 */   lw    $t7, ($s6)
.L7F0B36F8:
/* 0E60E8 7F0B36F8 8CA80008 */  lw    $t0, 8($a1)
/* 0E60EC 7F0B36FC 3C1E8007 */  lui   $fp, %hi(g_BgPortals) # $fp, 0x8007
/* 0E60F0 7F0B3700 27DEB3C8 */  addiu $fp, %lo(g_BgPortals) # addiu $fp, $fp, -0x4c38
/* 0E60F4 7F0B3704 01024821 */  addu  $t1, $t0, $v0
/* 0E60F8 7F0B3708 01335021 */  addu  $t2, $t1, $s3
/* 0E60FC 7F0B370C AFCA0000 */  sw    $t2, ($fp)
/* 0E6100 7F0B3710 8CA3000C */  lw    $v1, 0xc($a1)
/* 0E6104 7F0B3714 14600004 */  bnez  $v1, .L7F0B3728
/* 0E6108 7F0B3718 3C128007 */   lui   $s2, %hi(dword_CODE_bss_8007FF90) # $s2, 0x8007
/* 0E610C 7F0B371C 2652B3D8 */  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x4c28
/* 0E6110 7F0B3720 1000000F */  b     .L7F0B3760
/* 0E6114 7F0B3724 AE400000 */   sw    $zero, ($s2)
.L7F0B3728:
/* 0E6118 7F0B3728 3C128007 */  lui   $s2, %hi(dword_CODE_bss_8007FF90) # $s2, 0x8007
/* 0E611C 7F0B372C 00625821 */  addu  $t3, $v1, $v0
/* 0E6120 7F0B3730 2652B3D8 */  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x4c28
/* 0E6124 7F0B3734 01736021 */  addu  $t4, $t3, $s3
/* 0E6128 7F0B3738 AE4C0000 */  sw    $t4, ($s2)
/* 0E612C 7F0B373C 8CA40010 */  lw    $a0, 0x10($a1)
/* 0E6130 7F0B3740 3C018007 */  lui   $at, %hi(dword_CODE_bss_8007FF94)
/* 0E6134 7F0B3744 14800004 */  bnez  $a0, .L7F0B3758
/* 0E6138 7F0B3748 00826821 */   addu  $t5, $a0, $v0
/* 0E613C 7F0B374C 3C018007 */  lui   $at, %hi(dword_CODE_bss_8007FF94) # $at, 0x8007
/* 0E6140 7F0B3750 10000003 */  b     .L7F0B3760
/* 0E6144 7F0B3754 AC20B3DC */   sw    $zero, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B3758:
/* 0E6148 7F0B3758 01B37021 */  addu  $t6, $t5, $s3
/* 0E614C 7F0B375C AC2EB3DC */  sw    $t6, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B3760:
/* 0E6150 7F0B3760 8FC40000 */  lw    $a0, ($fp)
/* 0E6154 7F0B3764 00008025 */  move  $s0, $zero
/* 0E6158 7F0B3768 8C8F0000 */  lw    $t7, ($a0)
/* 0E615C 7F0B376C 00801025 */  move  $v0, $a0
/* 0E6160 7F0B3770 11E0000B */  beqz  $t7, .L7F0B37A0
/* 0E6164 7F0B3774 01E01825 */   move  $v1, $t7
/* 0E6168 7F0B3778 8EF80000 */  lw    $t8, ($s7)
.L7F0B377C:
/* 0E616C 7F0B377C 26100008 */  addiu $s0, $s0, 8
/* 0E6170 7F0B3780 0078C821 */  addu  $t9, $v1, $t8
/* 0E6174 7F0B3784 03334021 */  addu  $t0, $t9, $s3
/* 0E6178 7F0B3788 AC480000 */  sw    $t0, ($v0)
/* 0E617C 7F0B378C 8FC90000 */  lw    $t1, ($fp)
/* 0E6180 7F0B3790 01301021 */  addu  $v0, $t1, $s0
/* 0E6184 7F0B3794 8C430000 */  lw    $v1, ($v0)
/* 0E6188 7F0B3798 5460FFF8 */  bnezl $v1, .L7F0B377C
/* 0E618C 7F0B379C 8EF80000 */   lw    $t8, ($s7)
.L7F0B37A0:
/* 0E6190 7F0B37A0 8E440000 */  lw    $a0, ($s2)
/* 0E6194 7F0B37A4 50800019 */  beql  $a0, $zero, .L7F0B380C
/* 0E6198 7F0B37A8 8ED90000 */   lw    $t9, ($s6)
/* 0E619C 7F0B37AC 908A0000 */  lbu   $t2, ($a0)
/* 0E61A0 7F0B37B0 00008025 */  move  $s0, $zero
/* 0E61A4 7F0B37B4 00801825 */  move  $v1, $a0
/* 0E61A8 7F0B37B8 11400013 */  beqz  $t2, .L7F0B3808
/* 0E61AC 7F0B37BC 314200FF */   andi  $v0, $t2, 0xff
/* 0E61B0 7F0B37C0 24110064 */  li    $s1, 100
.L7F0B37C4:
/* 0E61B4 7F0B37C4 5622000C */  bnel  $s1, $v0, .L7F0B37F8
/* 0E61B8 7F0B37C8 90620008 */   lbu   $v0, 8($v1)
/* 0E61BC 7F0B37CC 8C6B0004 */  lw    $t3, 4($v1)
/* 0E61C0 7F0B37D0 8EEC0000 */  lw    $t4, ($s7)
/* 0E61C4 7F0B37D4 016C6821 */  addu  $t5, $t3, $t4
/* 0E61C8 7F0B37D8 0FC2D471 */  jal   getIndexOfPORTALID
/* 0E61CC 7F0B37DC 01B32021 */   addu  $a0, $t5, $s3
/* 0E61D0 7F0B37E0 8E4E0000 */  lw    $t6, ($s2)
/* 0E61D4 7F0B37E4 01D07821 */  addu  $t7, $t6, $s0
/* 0E61D8 7F0B37E8 ADE20004 */  sw    $v0, 4($t7)
/* 0E61DC 7F0B37EC 8E580000 */  lw    $t8, ($s2)
/* 0E61E0 7F0B37F0 03101821 */  addu  $v1, $t8, $s0
/* 0E61E4 7F0B37F4 90620008 */  lbu   $v0, 8($v1)
.L7F0B37F8:
/* 0E61E8 7F0B37F8 26100008 */  addiu $s0, $s0, 8
/* 0E61EC 7F0B37FC 24630008 */  addiu $v1, $v1, 8
/* 0E61F0 7F0B3800 1440FFF0 */  bnez  $v0, .L7F0B37C4
/* 0E61F4 7F0B3804 00000000 */   nop
.L7F0B3808:
/* 0E61F8 7F0B3808 8ED90000 */  lw    $t9, ($s6)
.L7F0B380C:
/* 0E61FC 7F0B380C 3C108004 */  lui   $s0, %hi(g_BgRoomInfo + 0x10 +0x40) # $s0, 0x8004
/* 0E6200 7F0B3810 2610ACB4 */  addiu $s0, %lo(g_BgRoomInfo + 0x10 +0x40) # addiu $s0, $s0, -0x534c
/* 0E6204 7F0B3814 2B210002 */  slti  $at, $t9, 2
/* 0E6208 7F0B3818 14200064 */  bnez  $at, .L7F0B39AC
/* 0E620C 7F0B381C 24110001 */   li    $s1, 1
/* 0E6210 7F0B3820 8EA40000 */  lw    $a0, ($s5)
/* 0E6214 7F0B3824 24130018 */  li    $s3, 24
/* 0E6218 7F0B3828 2417FFFF */  li    $s7, -1
/* 0E621C 7F0B382C 24840018 */  addiu $a0, $a0, 0x18
.L7F0B3830:
/* 0E6220 7F0B3830 A2000002 */  sb    $zero, 2($s0)
/* 0E6224 7F0B3834 A2000035 */  sb    $zero, 0x35($s0)
/* 0E6228 7F0B3838 8C880004 */  lw    $t0, 4($a0)
/* 0E622C 7F0B383C 26320001 */  addiu $s2, $s1, 1
/* 0E6230 7F0B3840 51000020 */  beql  $t0, $zero, .L7F0B38C4
/* 0E6234 7F0B3844 AE000014 */   sw    $zero, 0x14($s0)
/* 0E6238 7F0B3848 26320001 */  addiu $s2, $s1, 1
/* 0E623C 7F0B384C 0FC2CCDC */  jal   sub_GAME_7F0B4034
/* 0E6240 7F0B3850 02402025 */   move  $a0, $s2
/* 0E6244 7F0B3854 02202025 */  move  $a0, $s1
/* 0E6248 7F0B3858 0FC2CCF0 */  jal   sub_GAME_7F0B4084
/* 0E624C 7F0B385C AFA20068 */   sw    $v0, 0x68($sp)
/* 0E6250 7F0B3860 8FA50068 */  lw    $a1, 0x68($sp)
/* 0E6254 7F0B3864 0045082A */  slt   $at, $v0, $a1
/* 0E6258 7F0B3868 1420000B */  bnez  $at, .L7F0B3898
/* 0E625C 7F0B386C 00000000 */   nop
/* 0E6260 7F0B3870 00B40019 */  multu $a1, $s4
/* 0E6264 7F0B3874 8EA30000 */  lw    $v1, ($s5)
/* 0E6268 7F0B3878 00732021 */  addu  $a0, $v1, $s3
/* 0E626C 7F0B387C 8C8C0004 */  lw    $t4, 4($a0)
/* 0E6270 7F0B3880 00004812 */  mflo  $t1
/* 0E6274 7F0B3884 00695021 */  addu  $t2, $v1, $t1
/* 0E6278 7F0B3888 8D4B0004 */  lw    $t3, 4($t2)
/* 0E627C 7F0B388C 016C6823 */  subu  $t5, $t3, $t4
/* 0E6280 7F0B3890 1000000C */  b     .L7F0B38C4
/* 0E6284 7F0B3894 AE0D0014 */   sw    $t5, 0x14($s0)
.L7F0B3898:
/* 0E6288 7F0B3898 00540019 */  multu $v0, $s4
/* 0E628C 7F0B389C 8EA30000 */  lw    $v1, ($s5)
/* 0E6290 7F0B38A0 00732021 */  addu  $a0, $v1, $s3
/* 0E6294 7F0B38A4 8C990004 */  lw    $t9, 4($a0)
/* 0E6298 7F0B38A8 00007012 */  mflo  $t6
/* 0E629C 7F0B38AC 006E7821 */  addu  $t7, $v1, $t6
/* 0E62A0 7F0B38B0 8DF80008 */  lw    $t8, 8($t7)
/* 0E62A4 7F0B38B4 03194023 */  subu  $t0, $t8, $t9
/* 0E62A8 7F0B38B8 10000002 */  b     .L7F0B38C4
/* 0E62AC 7F0B38BC AE080014 */   sw    $t0, 0x14($s0)
/* 0E62B0 7F0B38C0 AE000014 */  sw    $zero, 0x14($s0)
.L7F0B38C4:
/* 0E62B4 7F0B38C4 8C890008 */  lw    $t1, 8($a0)
/* 0E62B8 7F0B38C8 5120001E */  beql  $t1, $zero, .L7F0B3944
/* 0E62BC 7F0B38CC AE000018 */   sw    $zero, 0x18($s0)
/* 0E62C0 7F0B38D0 0FC2CCDC */  jal   sub_GAME_7F0B4034
/* 0E62C4 7F0B38D4 02402025 */   move  $a0, $s2
/* 0E62C8 7F0B38D8 00408825 */  move  $s1, $v0
/* 0E62CC 7F0B38DC 0FC2CCF0 */  jal   sub_GAME_7F0B4084
/* 0E62D0 7F0B38E0 02402025 */   move  $a0, $s2
/* 0E62D4 7F0B38E4 0051082A */  slt   $at, $v0, $s1
/* 0E62D8 7F0B38E8 1420000B */  bnez  $at, .L7F0B3918
/* 0E62DC 7F0B38EC 00000000 */   nop
/* 0E62E0 7F0B38F0 02340019 */  multu $s1, $s4
/* 0E62E4 7F0B38F4 8EA30000 */  lw    $v1, ($s5)
/* 0E62E8 7F0B38F8 00732021 */  addu  $a0, $v1, $s3
/* 0E62EC 7F0B38FC 8C8D0008 */  lw    $t5, 8($a0)
/* 0E62F0 7F0B3900 00005012 */  mflo  $t2
/* 0E62F4 7F0B3904 006A5821 */  addu  $t3, $v1, $t2
/* 0E62F8 7F0B3908 8D6C0004 */  lw    $t4, 4($t3)
/* 0E62FC 7F0B390C 018D7023 */  subu  $t6, $t4, $t5
/* 0E6300 7F0B3910 1000000C */  b     .L7F0B3944
/* 0E6304 7F0B3914 AE0E0018 */   sw    $t6, 0x18($s0)
.L7F0B3918:
/* 0E6308 7F0B3918 00540019 */  multu $v0, $s4
/* 0E630C 7F0B391C 8EA30000 */  lw    $v1, ($s5)
/* 0E6310 7F0B3920 00732021 */  addu  $a0, $v1, $s3
/* 0E6314 7F0B3924 8C880008 */  lw    $t0, 8($a0)
/* 0E6318 7F0B3928 00007812 */  mflo  $t7
/* 0E631C 7F0B392C 006FC021 */  addu  $t8, $v1, $t7
/* 0E6320 7F0B3930 8F190008 */  lw    $t9, 8($t8)
/* 0E6324 7F0B3934 03284823 */  subu  $t1, $t9, $t0
/* 0E6328 7F0B3938 10000002 */  b     .L7F0B3944
/* 0E632C 7F0B393C AE090018 */   sw    $t1, 0x18($s0)
/* 0E6330 7F0B3940 AE000018 */  sw    $zero, 0x18($s0)
.L7F0B3944:
/* 0E6334 7F0B3944 8C8A0000 */  lw    $t2, ($a0)
/* 0E6338 7F0B3948 5140000F */  beql  $t2, $zero, .L7F0B3988
/* 0E633C 7F0B394C AE000010 */   sw    $zero, 0x10($s0)
/* 0E6340 7F0B3950 0FC2CD04 */  jal   sub_GAME_7F0B40D4
/* 0E6344 7F0B3954 02402025 */   move  $a0, $s2
/* 0E6348 7F0B3958 00540019 */  multu $v0, $s4
/* 0E634C 7F0B395C 8EA30000 */  lw    $v1, ($s5)
/* 0E6350 7F0B3960 8EC50000 */  lw    $a1, ($s6)
/* 0E6354 7F0B3964 00732021 */  addu  $a0, $v1, $s3
/* 0E6358 7F0B3968 8C8E0000 */  lw    $t6, ($a0)
/* 0E635C 7F0B396C 00005812 */  mflo  $t3
/* 0E6360 7F0B3970 006B6021 */  addu  $t4, $v1, $t3
/* 0E6364 7F0B3974 8D8D0000 */  lw    $t5, ($t4)
/* 0E6368 7F0B3978 01AE7823 */  subu  $t7, $t5, $t6
/* 0E636C 7F0B397C 10000003 */  b     .L7F0B398C
/* 0E6370 7F0B3980 AE0F0010 */   sw    $t7, 0x10($s0)
/* 0E6374 7F0B3984 AE000010 */  sw    $zero, 0x10($s0)
.L7F0B3988:
/* 0E6378 7F0B3988 8EC50000 */  lw    $a1, ($s6)
.L7F0B398C:
/* 0E637C 7F0B398C 0245082A */  slt   $at, $s2, $a1
/* 0E6380 7F0B3990 02408825 */  move  $s1, $s2
/* 0E6384 7F0B3994 26100050 */  addiu $s0, $s0, 0x50
/* 0E6388 7F0B3998 26730018 */  addiu $s3, $s3, 0x18
/* 0E638C 7F0B399C 24840018 */  addiu $a0, $a0, 0x18
/* 0E6390 7F0B39A0 1420FFA3 */  bnez  $at, .L7F0B3830
/* 0E6394 7F0B39A4 AE17FFD8 */   sw    $s7, -0x28($s0)
/* 0E6398 7F0B39A8 24110001 */  li    $s1, 1
.L7F0B39AC:
/* 0E639C 7F0B39AC 0FC2EE4C */  jal   initializeRoomData
/* 0E63A0 7F0B39B0 00000000 */   nop
/* 0E63A4 7F0B39B4 8ED80000 */  lw    $t8, ($s6)
/* 0E63A8 7F0B39B8 2B010002 */  slti  $at, $t8, 2
/* 0E63AC 7F0B39BC 54200009 */  bnezl $at, .L7F0B39E4
/* 0E63B0 7F0B39C0 8FC40000 */   lw    $a0, ($fp)
.L7F0B39C4:
/* 0E63B4 7F0B39C4 0FC2E175 */  jal   sub_GAME_7F0B9338
/* 0E63B8 7F0B39C8 02202025 */   move  $a0, $s1
/* 0E63BC 7F0B39CC 8ED90000 */  lw    $t9, ($s6)
/* 0E63C0 7F0B39D0 26310001 */  addiu $s1, $s1, 1
/* 0E63C4 7F0B39D4 0239082A */  slt   $at, $s1, $t9
/* 0E63C8 7F0B39D8 1420FFFA */  bnez  $at, .L7F0B39C4
/* 0E63CC 7F0B39DC 00000000 */   nop
/* 0E63D0 7F0B39E0 8FC40000 */  lw    $a0, ($fp)
.L7F0B39E4:
/* 0E63D4 7F0B39E4 3C038004 */  lui   $v1, %hi(D_800443C4) # $v1, 0x8004
/* 0E63D8 7F0B39E8 2463D8A4 */  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, -0x275c
/* 0E63DC 7F0B39EC 8C820000 */  lw    $v0, ($a0)
/* 0E63E0 7F0B39F0 00008825 */  move  $s1, $zero
/* 0E63E4 7F0B39F4 00008025 */  move  $s0, $zero
/* 0E63E8 7F0B39F8 10400010 */  beqz  $v0, .L7F0B3A3C
/* 0E63EC 7F0B39FC 00000000 */   nop
/* 0E63F0 7F0B3A00 02202025 */  move  $a0, $s1
.L7F0B3A04:
/* 0E63F4 7F0B3A04 0FC2E2F6 */  jal   sub_GAME_7F0B993C
/* 0E63F8 7F0B3A08 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0E63FC 7F0B3A0C 8FC40000 */  lw    $a0, ($fp)
/* 0E6400 7F0B3A10 8FA3004C */  lw    $v1, 0x4c($sp)
/* 0E6404 7F0B3A14 26100008 */  addiu $s0, $s0, 8
/* 0E6408 7F0B3A18 00904021 */  addu  $t0, $a0, $s0
/* 0E640C 7F0B3A1C A0620000 */  sb    $v0, ($v1)
/* 0E6410 7F0B3A20 8D090000 */  lw    $t1, ($t0)
/* 0E6414 7F0B3A24 26310001 */  addiu $s1, $s1, 1
/* 0E6418 7F0B3A28 24630001 */  addiu $v1, $v1, 1
/* 0E641C 7F0B3A2C 5520FFF5 */  bnezl $t1, .L7F0B3A04
/* 0E6420 7F0B3A30 02202025 */   move  $a0, $s1
/* 0E6424 7F0B3A34 00008825 */  move  $s1, $zero
/* 0E6428 7F0B3A38 8C820000 */  lw    $v0, ($a0)
.L7F0B3A3C:
/* 0E642C 7F0B3A3C 1040000B */  beqz  $v0, .L7F0B3A6C
/* 0E6430 7F0B3A40 00008025 */   move  $s0, $zero
.L7F0B3A44:
/* 0E6434 7F0B3A44 0FC2E38C */  jal   sub_GAME_7F0B9B94
/* 0E6438 7F0B3A48 02202025 */   move  $a0, $s1
/* 0E643C 7F0B3A4C 8FC40000 */  lw    $a0, ($fp)
/* 0E6440 7F0B3A50 26100008 */  addiu $s0, $s0, 8
/* 0E6444 7F0B3A54 26310001 */  addiu $s1, $s1, 1
/* 0E6448 7F0B3A58 00905021 */  addu  $t2, $a0, $s0
/* 0E644C 7F0B3A5C 8D4B0000 */  lw    $t3, ($t2)
/* 0E6450 7F0B3A60 1560FFF8 */  bnez  $t3, .L7F0B3A44
/* 0E6454 7F0B3A64 00000000 */   nop
/* 0E6458 7F0B3A68 00008825 */  move  $s1, $zero
.L7F0B3A6C:
/* 0E645C 7F0B3A6C 8ECC0000 */  lw    $t4, ($s6)
/* 0E6460 7F0B3A70 5980000A */  blezl $t4, .L7F0B3A9C
/* 0E6464 7F0B3A74 8C8E0000 */   lw    $t6, ($a0)
.L7F0B3A78:
/* 0E6468 7F0B3A78 0FC2E21D */  jal   sub_GAME_7F0B95D8
/* 0E646C 7F0B3A7C 02202025 */   move  $a0, $s1
/* 0E6470 7F0B3A80 8ECD0000 */  lw    $t5, ($s6)
/* 0E6474 7F0B3A84 26310001 */  addiu $s1, $s1, 1
/* 0E6478 7F0B3A88 022D082A */  slt   $at, $s1, $t5
/* 0E647C 7F0B3A8C 1420FFFA */  bnez  $at, .L7F0B3A78
/* 0E6480 7F0B3A90 00000000 */   nop
/* 0E6484 7F0B3A94 8FC40000 */  lw    $a0, ($fp)
/* 0E6488 7F0B3A98 8C8E0000 */  lw    $t6, ($a0)
.L7F0B3A9C:
/* 0E648C 7F0B3A9C 00008025 */  move  $s0, $zero
/* 0E6490 7F0B3AA0 00801025 */  move  $v0, $a0
/* 0E6494 7F0B3AA4 11C0000A */  beqz  $t6, .L7F0B3AD0
/* 0E6498 7F0B3AA8 00000000 */   nop
/* 0E649C 7F0B3AAC 904F0006 */  lbu   $t7, 6($v0)
.L7F0B3AB0:
/* 0E64A0 7F0B3AB0 26100008 */  addiu $s0, $s0, 8
/* 0E64A4 7F0B3AB4 31F800FE */  andi  $t8, $t7, 0xfe
/* 0E64A8 7F0B3AB8 A0580006 */  sb    $t8, 6($v0)
/* 0E64AC 7F0B3ABC 8FD90000 */  lw    $t9, ($fp)
/* 0E64B0 7F0B3AC0 03301021 */  addu  $v0, $t9, $s0
/* 0E64B4 7F0B3AC4 8C480000 */  lw    $t0, ($v0)
/* 0E64B8 7F0B3AC8 5500FFF9 */  bnezl $t0, .L7F0B3AB0
/* 0E64BC 7F0B3ACC 904F0006 */   lbu   $t7, 6($v0)
.L7F0B3AD0:
/* 0E64C0 7F0B3AD0 0FC2CAAB */  jal   sub_GAME_7F0B37EC
/* 0E64C4 7F0B3AD4 00000000 */   nop
.L7F0B3AD8:
/* 0E64C8 7F0B3AD8 0FC2E78B */  jal   fogRemoved7F0BAA5C
/* 0E64CC 7F0B3ADC 8FA400B8 */   lw    $a0, 0xb8($sp)
/* 0E64D0 7F0B3AE0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E64D4 7F0B3AE4 240900C8 */  li    $t1, 200
/* 0E64D8 7F0B3AE8 3C018004 */  lui   $at, %hi(D_800442F8) # $at, 0x8004
/* 0E64DC 7F0B3AEC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E64E0 7F0B3AF0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E64E4 7F0B3AF4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E64E8 7F0B3AF8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E64EC 7F0B3AFC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E64F0 7F0B3B00 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E64F4 7F0B3B04 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E64F8 7F0B3B08 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E64FC 7F0B3B0C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E6500 7F0B3B10 AC29D7D8 */  sw    $t1, %lo(D_800442F8)($at)
/* 0E6504 7F0B3B14 03E00008 */  jr    $ra
/* 0E6508 7F0B3B18 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif

#endif






void cleanup_rooms(void) {
    unload_rooms();
    matrix_4x4_7F058C4C(1.0);
}






void sub_GAME_7F0B4810(f32 arg0) {
    room_data_float1 = arg0;
    room_data_float2 = (f32) (1.0f / arg0);
}


f32 get_room_data_float2(void){
  return room_data_float2;
}

f32 get_room_data_float1(void){
  return room_data_float1;
}


f32 sub_GAME_7F0B4848(void)
{
    return levelinfotable[levelentry_index].unknownfloat / levelinfotable[levelentry_index].levelscale;
}


//sub_GAME_7F0B4878
f32 bgGetLevelVisibilityScale(void) {
    return mCurrentLevelVisibilityScale;
}






#ifdef NONMATCHING
void bgRoomVisibilityRelated(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80058C58*/
glabel jpt_80058C58
.word .L7F0B4914
.word .L7F0B4914
.word .L7F0B4914
.word .L7F0B491C
.word .L7F0B491C
.word .L7F0B491C
.word .L7F0B4914
.word .L7F0B491C
.word .L7F0B4914

.text
glabel bgRoomVisibilityRelated
/* 0E93B4 7F0B4884 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0E93B8 7F0B4888 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E93BC 7F0B488C AFB60030 */  sw    $s6, 0x30($sp)
/* 0E93C0 7F0B4890 3C018008 */  lui   $at, %hi(num_visible_rooms_in_cur_global_vis_packet)
/* 0E93C4 7F0B4894 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E93C8 7F0B4898 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E93CC 7F0B489C AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E93D0 7F0B48A0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E93D4 7F0B48A4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0E93D8 7F0B48A8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E93DC 7F0B48AC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E93E0 7F0B48B0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E93E4 7F0B48B4 2416FFFF */  li    $s6, -1
/* 0E93E8 7F0B48B8 0FC26C54 */  jal   get_cur_playernum
/* 0E93EC 7F0B48BC AC20C038 */   sw    $zero, %lo(num_visible_rooms_in_cur_global_vis_packet)($at)
/* 0E93F0 7F0B48C0 0FC26D36 */  jal   sub_GAME_7F09B4D8
/* 0E93F4 7F0B48C4 00402025 */   move  $a0, $v0
/* 0E93F8 7F0B48C8 14400003 */  bnez  $v0, .L7F0B48D8
/* 0E93FC 7F0B48CC 00000000 */   nop
/* 0E9400 7F0B48D0 0FC2D9BA */  jal   sub_GAME_7F0B66E8
/* 0E9404 7F0B48D4 00000000 */   nop
.L7F0B48D8:
/* 0E9408 7F0B48D8 0FC1E94A */  jal   bondviewGetCameraMode
/* 0E940C 7F0B48DC 00000000 */   nop
/* 0E9410 7F0B48E0 3C038004 */  lui   $v1, %hi(D_800442F8)
/* 0E9414 7F0B48E4 244FFFFF */  addiu $t7, $v0, -1
/* 0E9418 7F0B48E8 246342F8 */  addiu $v1, %lo(D_800442F8) # addiu $v1, $v1, 0x42f8
/* 0E941C 7F0B48EC 240E0003 */  li    $t6, 3
/* 0E9420 7F0B48F0 2DE10009 */  sltiu $at, $t7, 9
/* 0E9424 7F0B48F4 10200009 */  beqz  $at, .L7F0B491C
/* 0E9428 7F0B48F8 AC6E0000 */   sw    $t6, ($v1)
/* 0E942C 7F0B48FC 000F7880 */  sll   $t7, $t7, 2
/* 0E9430 7F0B4900 3C018006 */  lui   $at, %hi(jpt_80058C58)
/* 0E9434 7F0B4904 002F0821 */  addu  $at, $at, $t7
/* 0E9438 7F0B4908 8C2F8C58 */  lw    $t7, %lo(jpt_80058C58)($at)
.L7F0B490C:
/* 0E943C 7F0B490C 01E00008 */  jr    $t7
/* 0E9440 7F0B4910 00000000 */   nop
.L7F0B4914:
/* 0E9444 7F0B4914 241800C8 */  li    $t8, 200
/* 0E9448 7F0B4918 AC780000 */  sw    $t8, ($v1)
def_7F0B490C:
.L7F0B491C:
/* 0E944C 7F0B491C 0FC227E6 */  jal   bondviewGetCurrentPlayersRoom
/* 0E9450 7F0B4920 00000000 */   nop
/* 0E9454 7F0B4924 3C018004 */  lui   $at, %hi(g_BgCurrentRoom)
/* 0E9458 7F0B4928 00409825 */  move  $s3, $v0
/* 0E945C 7F0B492C 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0E9460 7F0B4930 AC224838 */   sw    $v0, %lo(g_BgCurrentRoom)($at)
/* 0E9464 7F0B4934 0FC22800 */  jal   bondviewGetCurrentPlayersPosition3
/* 0E9468 7F0B4938 0040A025 */   move  $s4, $v0
/* 0E946C 7F0B493C 3C038008 */  lui   $v1, %hi(g_BgPortals)
/* 0E9470 7F0B4940 0040A825 */  move  $s5, $v0
/* 0E9474 7F0B4944 8C63FF80 */  lw    $v1, %lo(g_BgPortals)($v1)
/* 0E9478 7F0B4948 0000B825 */  move  $s7, $zero
/* 0E947C 7F0B494C 241E000B */  li    $fp, 11
/* 0E9480 7F0B4950 8C790000 */  lw    $t9, ($v1)
.L7F0B4954:
/* 0E9484 7F0B4954 3C128004 */  lui   $s2, %hi(D_800443C4)
/* 0E9488 7F0B4958 265243C4 */  addiu $s2, %lo(D_800443C4) # addiu $s2, $s2, 0x43c4
/* 0E948C 7F0B495C 13200025 */  beqz  $t9, .L7F0B49F4
/* 0E9490 7F0B4960 00008025 */   move  $s0, $zero
/* 0E9494 7F0B4964 00008825 */  move  $s1, $zero
/* 0E9498 7F0B4968 00601025 */  move  $v0, $v1
.L7F0B496C:
/* 0E949C 7F0B496C 92480000 */  lbu   $t0, ($s2)
/* 0E94A0 7F0B4970 5500001B */  bnezl $t0, .L7F0B49E0
/* 0E94A4 7F0B4974 8C4E0008 */   lw    $t6, 8($v0)
/* 0E94A8 7F0B4978 52160019 */  beql  $s0, $s6, .L7F0B49E0
/* 0E94AC 7F0B497C 8C4E0008 */   lw    $t6, 8($v0)
/* 0E94B0 7F0B4980 90490004 */  lbu   $t1, 4($v0)
/* 0E94B4 7F0B4984 02002025 */  move  $a0, $s0
/* 0E94B8 7F0B4988 02802825 */  move  $a1, $s4
/* 0E94BC 7F0B498C 12690004 */  beq   $s3, $t1, .L7F0B49A0
/* 0E94C0 7F0B4990 00000000 */   nop
/* 0E94C4 7F0B4994 904A0005 */  lbu   $t2, 5($v0)
/* 0E94C8 7F0B4998 166A000D */  bne   $s3, $t2, .L7F0B49D0
/* 0E94CC 7F0B499C 00000000 */   nop
.L7F0B49A0:
/* 0E94D0 7F0B49A0 0FC2E7C5 */  jal   sub_GAME_7F0B9F14
/* 0E94D4 7F0B49A4 02A03025 */   move  $a2, $s5
/* 0E94D8 7F0B49A8 10400009 */  beqz  $v0, .L7F0B49D0
/* 0E94DC 7F0B49AC 3C038008 */   lui   $v1, %hi(g_BgPortals)
/* 0E94E0 7F0B49B0 8C63FF80 */  lw    $v1, %lo(g_BgPortals)($v1)
/* 0E94E4 7F0B49B4 0200B025 */  move  $s6, $s0
/* 0E94E8 7F0B49B8 00711021 */  addu  $v0, $v1, $s1
/* 0E94EC 7F0B49BC 904C0004 */  lbu   $t4, 4($v0)
/* 0E94F0 7F0B49C0 904B0005 */  lbu   $t3, 5($v0)
/* 0E94F4 7F0B49C4 026C6826 */  xor   $t5, $s3, $t4
/* 0E94F8 7F0B49C8 1000000A */  b     .L7F0B49F4
/* 0E94FC 7F0B49CC 016D9826 */   xor   $s3, $t3, $t5
.L7F0B49D0:
/* 0E9500 7F0B49D0 3C038008 */  lui   $v1, %hi(g_BgPortals)
/* 0E9504 7F0B49D4 8C63FF80 */  lw    $v1, %lo(g_BgPortals)($v1)
/* 0E9508 7F0B49D8 00711021 */  addu  $v0, $v1, $s1
/* 0E950C 7F0B49DC 8C4E0008 */  lw    $t6, 8($v0)
.L7F0B49E0:
/* 0E9510 7F0B49E0 26100001 */  addiu $s0, $s0, 1
/* 0E9514 7F0B49E4 26520001 */  addiu $s2, $s2, 1
/* 0E9518 7F0B49E8 26310008 */  addiu $s1, $s1, 8
/* 0E951C 7F0B49EC 15C0FFDF */  bnez  $t6, .L7F0B496C
/* 0E9520 7F0B49F0 24420008 */   addiu $v0, $v0, 8
.L7F0B49F4:
/* 0E9524 7F0B49F4 001078C0 */  sll   $t7, $s0, 3
/* 0E9528 7F0B49F8 006FC021 */  addu  $t8, $v1, $t7
/* 0E952C 7F0B49FC 8F190000 */  lw    $t9, ($t8)
/* 0E9530 7F0B4A00 26F70001 */  addiu $s7, $s7, 1
/* 0E9534 7F0B4A04 13200003 */  beqz  $t9, .L7F0B4A14
/* 0E9538 7F0B4A08 00000000 */   nop
/* 0E953C 7F0B4A0C 56FEFFD1 */  bnel  $s7, $fp, .L7F0B4954
/* 0E9540 7F0B4A10 8C790000 */   lw    $t9, ($v1)
.L7F0B4A14:
/* 0E9544 7F0B4A14 3C018004 */  lui   $at, %hi(g_BgCurrentRoom)
/* 0E9548 7F0B4A18 0FC2E29B */  jal   sub_GAME_7F0B8A6C
/* 0E954C 7F0B4A1C AC334838 */   sw    $s3, %lo(g_BgCurrentRoom)($at)
/* 0E9550 7F0B4A20 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E9554 7F0B4A24 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E9558 7F0B4A28 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E955C 7F0B4A2C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E9560 7F0B4A30 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E9564 7F0B4A34 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E9568 7F0B4A38 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E956C 7F0B4A3C 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E9570 7F0B4A40 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E9574 7F0B4A44 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E9578 7F0B4A48 03E00008 */  jr    $ra
/* 0E957C 7F0B4A4C 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



void addToByteSetMaxSize15(u8* set, u8 newElement) {
    s32 i = 0;

    while (i < 0x10 && set[i] != 0xFF) {
        if (newElement == set[i]) {
            return;
        }
        i++;
    }

    if (i < 0xF) {
        set[i] = newElement;
        set[i+1] = -1;
    }
    return;
}




#ifdef NONMATCHING
void sub_GAME_7F0B4AB4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B4AB4
/* 0E95E4 7F0B4AB4 27BDFEA0 */  addiu $sp, $sp, -0x160
/* 0E95E8 7F0B4AB8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E95EC 7F0B4ABC 3C158008 */  lui   $s5, %hi(g_BgPortals)
/* 0E95F0 7F0B4AC0 26B5FF80 */  addiu $s5, %lo(g_BgPortals) # addiu $s5, $s5, -0x80
/* 0E95F4 7F0B4AC4 8EA80000 */  lw    $t0, ($s5)
/* 0E95F8 7F0B4AC8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E95FC 7F0B4ACC AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E9600 7F0B4AD0 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E9604 7F0B4AD4 AFB60030 */  sw    $s6, 0x30($sp)
/* 0E9608 7F0B4AD8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E960C 7F0B4ADC AFB30024 */  sw    $s3, 0x24($sp)
/* 0E9610 7F0B4AE0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E9614 7F0B4AE4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E9618 7F0B4AE8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E961C 7F0B4AEC AFA7016C */  sw    $a3, 0x16c($sp)
/* 0E9620 7F0B4AF0 8D0E0000 */  lw    $t6, ($t0)
/* 0E9624 7F0B4AF4 00809825 */  move  $s3, $a0
/* 0E9628 7F0B4AF8 00A0A025 */  move  $s4, $a1
/* 0E962C 7F0B4AFC 11C00013 */  beqz  $t6, .L7F0B4B4C
/* 0E9630 7F0B4B00 00C0B025 */   move  $s6, $a2
/* 0E9634 7F0B4B04 27B1005C */  addiu $s1, $sp, 0x5c
/* 0E9638 7F0B4B08 00009025 */  move  $s2, $zero
/* 0E963C 7F0B4B0C AFA0012C */  sw    $zero, 0x12c($sp)
/* 0E9640 7F0B4B10 8FA4012C */  lw    $a0, 0x12c($sp)
.L7F0B4B14:
/* 0E9644 7F0B4B14 02602825 */  move  $a1, $s3
/* 0E9648 7F0B4B18 0FC2E7C5 */  jal   sub_GAME_7F0B9F14
/* 0E964C 7F0B4B1C 02803025 */   move  $a2, $s4
/* 0E9650 7F0B4B20 A2220000 */  sb    $v0, ($s1)
/* 0E9654 7F0B4B24 8FAF012C */  lw    $t7, 0x12c($sp)
/* 0E9658 7F0B4B28 8EA80000 */  lw    $t0, ($s5)
/* 0E965C 7F0B4B2C 26520008 */  addiu $s2, $s2, 8
/* 0E9660 7F0B4B30 25F80001 */  addiu $t8, $t7, 1
/* 0E9664 7F0B4B34 AFB8012C */  sw    $t8, 0x12c($sp)
/* 0E9668 7F0B4B38 0112C821 */  addu  $t9, $t0, $s2
/* 0E966C 7F0B4B3C 8F290000 */  lw    $t1, ($t9)
/* 0E9670 7F0B4B40 26310001 */  addiu $s1, $s1, 1
/* 0E9674 7F0B4B44 5520FFF3 */  bnezl $t1, .L7F0B4B14
/* 0E9678 7F0B4B48 8FA4012C */   lw    $a0, 0x12c($sp)
.L7F0B4B4C:
/* 0E967C 7F0B4B4C 27A30150 */  addiu $v1, $sp, 0x150
/* 0E9680 7F0B4B50 02C02025 */  move  $a0, $s6
/* 0E9684 7F0B4B54 27A20158 */  addiu $v0, $sp, 0x158
.L7F0B4B58:
/* 0E9688 7F0B4B58 908A0000 */  lbu   $t2, ($a0)
/* 0E968C 7F0B4B5C 24630001 */  addiu $v1, $v1, 1
/* 0E9690 7F0B4B60 0062082B */  sltu  $at, $v1, $v0
/* 0E9694 7F0B4B64 24840001 */  addiu $a0, $a0, 1
/* 0E9698 7F0B4B68 1420FFFB */  bnez  $at, .L7F0B4B58
/* 0E969C 7F0B4B6C A06AFFFF */   sb    $t2, -1($v1)
/* 0E96A0 7F0B4B70 02C02025 */  move  $a0, $s6
/* 0E96A4 7F0B4B74 27A20130 */  addiu $v0, $sp, 0x130
/* 0E96A8 7F0B4B78 27A30138 */  addiu $v1, $sp, 0x138
.L7F0B4B7C:
/* 0E96AC 7F0B4B7C 908B0000 */  lbu   $t3, ($a0)
/* 0E96B0 7F0B4B80 24420001 */  addiu $v0, $v0, 1
/* 0E96B4 7F0B4B84 0043082B */  sltu  $at, $v0, $v1
/* 0E96B8 7F0B4B88 24840001 */  addiu $a0, $a0, 1
/* 0E96BC 7F0B4B8C 1420FFFB */  bnez  $at, .L7F0B4B7C
/* 0E96C0 7F0B4B90 A04BFFFF */   sb    $t3, -1($v0)
/* 0E96C4 7F0B4B94 93AC0150 */  lbu   $t4, 0x150($sp)
/* 0E96C8 7F0B4B98 240500FF */  li    $a1, 255
/* 0E96CC 7F0B4B9C AFA00124 */  sw    $zero, 0x124($sp)
/* 0E96D0 7F0B4BA0 10AC0009 */  beq   $a1, $t4, .L7F0B4BC8
/* 0E96D4 7F0B4BA4 27BE0160 */   addiu $fp, $sp, 0x160
/* 0E96D8 7F0B4BA8 27A30150 */  addiu $v1, $sp, 0x150
/* 0E96DC 7F0B4BAC 27A20160 */  addiu $v0, $sp, 0x160
/* 0E96E0 7F0B4BB0 906D0001 */  lbu   $t5, 1($v1)
.L7F0B4BB4:
/* 0E96E4 7F0B4BB4 24630001 */  addiu $v1, $v1, 1
/* 0E96E8 7F0B4BB8 50AD0004 */  beql  $a1, $t5, .L7F0B4BCC
/* 0E96EC 7F0B4BBC AFA00124 */   sw    $zero, 0x124($sp)
/* 0E96F0 7F0B4BC0 5462FFFC */  bnel  $v1, $v0, .L7F0B4BB4
/* 0E96F4 7F0B4BC4 906D0001 */   lbu   $t5, 1($v1)
.L7F0B4BC8:
/* 0E96F8 7F0B4BC8 AFA00124 */  sw    $zero, 0x124($sp)
.L7F0B4BCC:
/* 0E96FC 7F0B4BCC 24170002 */  li    $s7, 2
/* 0E9700 7F0B4BD0 24160001 */  li    $s6, 1
/* 0E9704 7F0B4BD4 27B40130 */  addiu $s4, $sp, 0x130
/* 0E9708 7F0B4BD8 27B30140 */  addiu $s3, $sp, 0x140
.L7F0B4BDC:
/* 0E970C 7F0B4BDC 240E00FF */  li    $t6, 255
/* 0E9710 7F0B4BE0 A3AE0140 */  sb    $t6, 0x140($sp)
/* 0E9714 7F0B4BE4 AFA0012C */  sw    $zero, 0x12c($sp)
/* 0E9718 7F0B4BE8 8D0F0000 */  lw    $t7, ($t0)
/* 0E971C 7F0B4BEC 00009025 */  move  $s2, $zero
/* 0E9720 7F0B4BF0 01001825 */  move  $v1, $t0
/* 0E9724 7F0B4BF4 51E0003D */  beql  $t7, $zero, .L7F0B4CEC
/* 0E9728 7F0B4BF8 93A40140 */   lbu   $a0, 0x140($sp)
/* 0E972C 7F0B4BFC 93B80150 */  lbu   $t8, 0x150($sp)
.L7F0B4C00:
/* 0E9730 7F0B4C00 8FB9012C */  lw    $t9, 0x12c($sp)
/* 0E9734 7F0B4C04 27A9005C */  addiu $t1, $sp, 0x5c
/* 0E9738 7F0B4C08 10B8002E */  beq   $a1, $t8, .L7F0B4CC4
/* 0E973C 7F0B4C0C 03298821 */   addu  $s1, $t9, $t1
/* 0E9740 7F0B4C10 27AA0150 */  addiu $t2, $sp, 0x150
/* 0E9744 7F0B4C14 000A8021 */  addu  $s0, $zero, $t2
/* 0E9748 7F0B4C18 92220000 */  lbu   $v0, ($s1)
.L7F0B4C1C:
/* 0E974C 7F0B4C1C 16C20011 */  bne   $s6, $v0, .L7F0B4C64
/* 0E9750 7F0B4C20 00000000 */   nop
/* 0E9754 7F0B4C24 906B0004 */  lbu   $t3, 4($v1)
/* 0E9758 7F0B4C28 920C0000 */  lbu   $t4, ($s0)
/* 0E975C 7F0B4C2C 02602025 */  move  $a0, $s3
/* 0E9760 7F0B4C30 156C000C */  bne   $t3, $t4, .L7F0B4C64
/* 0E9764 7F0B4C34 00000000 */   nop
/* 0E9768 7F0B4C38 0FC2D294 */  jal   addToByteSetMaxSize15
/* 0E976C 7F0B4C3C 90650005 */   lbu   $a1, 5($v1)
/* 0E9770 7F0B4C40 8EAD0000 */  lw    $t5, ($s5)
/* 0E9774 7F0B4C44 02802025 */  move  $a0, $s4
/* 0E9778 7F0B4C48 01B27021 */  addu  $t6, $t5, $s2
/* 0E977C 7F0B4C4C 0FC2D294 */  jal   addToByteSetMaxSize15
/* 0E9780 7F0B4C50 91C50005 */   lbu   $a1, 5($t6)
/* 0E9784 7F0B4C54 8EA80000 */  lw    $t0, ($s5)
/* 0E9788 7F0B4C58 A2200000 */  sb    $zero, ($s1)
/* 0E978C 7F0B4C5C 300200FF */  andi  $v0, $zero, 0xff
/* 0E9790 7F0B4C60 01121821 */  addu  $v1, $t0, $s2
.L7F0B4C64:
/* 0E9794 7F0B4C64 56E20011 */  bnel  $s7, $v0, .L7F0B4CAC
/* 0E9798 7F0B4C68 920A0001 */   lbu   $t2, 1($s0)
/* 0E979C 7F0B4C6C 906F0005 */  lbu   $t7, 5($v1)
/* 0E97A0 7F0B4C70 92180000 */  lbu   $t8, ($s0)
/* 0E97A4 7F0B4C74 02602025 */  move  $a0, $s3
/* 0E97A8 7F0B4C78 55F8000C */  bnel  $t7, $t8, .L7F0B4CAC
/* 0E97AC 7F0B4C7C 920A0001 */   lbu   $t2, 1($s0)
/* 0E97B0 7F0B4C80 0FC2D294 */  jal   addToByteSetMaxSize15
/* 0E97B4 7F0B4C84 90650004 */   lbu   $a1, 4($v1)
/* 0E97B8 7F0B4C88 8EB90000 */  lw    $t9, ($s5)
/* 0E97BC 7F0B4C8C 02802025 */  move  $a0, $s4
/* 0E97C0 7F0B4C90 03324821 */  addu  $t1, $t9, $s2
/* 0E97C4 7F0B4C94 0FC2D294 */  jal   addToByteSetMaxSize15
/* 0E97C8 7F0B4C98 91250004 */   lbu   $a1, 4($t1)
/* 0E97CC 7F0B4C9C 8EA80000 */  lw    $t0, ($s5)
/* 0E97D0 7F0B4CA0 A2200000 */  sb    $zero, ($s1)
/* 0E97D4 7F0B4CA4 01121821 */  addu  $v1, $t0, $s2
/* 0E97D8 7F0B4CA8 920A0001 */  lbu   $t2, 1($s0)
.L7F0B4CAC:
/* 0E97DC 7F0B4CAC 240100FF */  li    $at, 255
/* 0E97E0 7F0B4CB0 26100001 */  addiu $s0, $s0, 1
/* 0E97E4 7F0B4CB4 51410004 */  beql  $t2, $at, .L7F0B4CC8
/* 0E97E8 7F0B4CB8 8FAB012C */   lw    $t3, 0x12c($sp)
/* 0E97EC 7F0B4CBC 561EFFD7 */  bnel  $s0, $fp, .L7F0B4C1C
/* 0E97F0 7F0B4CC0 92220000 */   lbu   $v0, ($s1)
.L7F0B4CC4:
/* 0E97F4 7F0B4CC4 8FAB012C */  lw    $t3, 0x12c($sp)
.L7F0B4CC8:
/* 0E97F8 7F0B4CC8 26520008 */  addiu $s2, $s2, 8
/* 0E97FC 7F0B4CCC 24630008 */  addiu $v1, $v1, 8
/* 0E9800 7F0B4CD0 256C0001 */  addiu $t4, $t3, 1
/* 0E9804 7F0B4CD4 AFAC012C */  sw    $t4, 0x12c($sp)
/* 0E9808 7F0B4CD8 8C6D0000 */  lw    $t5, ($v1)
/* 0E980C 7F0B4CDC 240500FF */  li    $a1, 255
/* 0E9810 7F0B4CE0 55A0FFC7 */  bnezl $t5, .L7F0B4C00
/* 0E9814 7F0B4CE4 93B80150 */   lbu   $t8, 0x150($sp)
/* 0E9818 7F0B4CE8 93A40140 */  lbu   $a0, 0x140($sp)
.L7F0B4CEC:
/* 0E981C 7F0B4CEC 27A30150 */  addiu $v1, $sp, 0x150
/* 0E9820 7F0B4CF0 27A20140 */  addiu $v0, $sp, 0x140
/* 0E9824 7F0B4CF4 14A40003 */  bne   $a1, $a0, .L7F0B4D04
/* 0E9828 7F0B4CF8 00000000 */   nop
/* 0E982C 7F0B4CFC 10000015 */  b     .L7F0B4D54
/* 0E9830 7F0B4D00 93A20150 */   lbu   $v0, 0x150($sp)
.L7F0B4D04:
/* 0E9834 7F0B4D04 904E0000 */  lbu   $t6, ($v0)
/* 0E9838 7F0B4D08 24420001 */  addiu $v0, $v0, 1
/* 0E983C 7F0B4D0C 27AF0150 */  addiu $t7, $sp, 0x150
/* 0E9840 7F0B4D10 004F082B */  sltu  $at, $v0, $t7
/* 0E9844 7F0B4D14 24630001 */  addiu $v1, $v1, 1
/* 0E9848 7F0B4D18 1420FFFA */  bnez  $at, .L7F0B4D04
/* 0E984C 7F0B4D1C A06EFFFF */   sb    $t6, -1($v1)
/* 0E9850 7F0B4D20 10A40009 */  beq   $a1, $a0, .L7F0B4D48
/* 0E9854 7F0B4D24 AFA00124 */   sw    $zero, 0x124($sp)
/* 0E9858 7F0B4D28 02601025 */  move  $v0, $s3
/* 0E985C 7F0B4D2C 90580001 */  lbu   $t8, 1($v0)
.L7F0B4D30:
/* 0E9860 7F0B4D30 24420001 */  addiu $v0, $v0, 1
/* 0E9864 7F0B4D34 27B90150 */  addiu $t9, $sp, 0x150
/* 0E9868 7F0B4D38 10B80003 */  beq   $a1, $t8, .L7F0B4D48
/* 0E986C 7F0B4D3C 00000000 */   nop
/* 0E9870 7F0B4D40 5459FFFB */  bnel  $v0, $t9, .L7F0B4D30
/* 0E9874 7F0B4D44 90580001 */   lbu   $t8, 1($v0)
.L7F0B4D48:
/* 0E9878 7F0B4D48 14A4FFA4 */  bne   $a1, $a0, .L7F0B4BDC
/* 0E987C 7F0B4D4C AFA00124 */   sw    $zero, 0x124($sp)
/* 0E9880 7F0B4D50 93A20150 */  lbu   $v0, 0x150($sp)
.L7F0B4D54:
/* 0E9884 7F0B4D54 10A20011 */  beq   $a1, $v0, .L7F0B4D9C
/* 0E9888 7F0B4D58 8FA90124 */   lw    $t1, 0x124($sp)
/* 0E988C 7F0B4D5C 8FAB016C */  lw    $t3, 0x16c($sp)
/* 0E9890 7F0B4D60 27AA0150 */  addiu $t2, $sp, 0x150
/* 0E9894 7F0B4D64 012A1821 */  addu  $v1, $t1, $t2
/* 0E9898 7F0B4D68 90620000 */  lbu   $v0, ($v1)
/* 0E989C 7F0B4D6C 01692021 */  addu  $a0, $t3, $t1
/* 0E98A0 7F0B4D70 A0820000 */  sb    $v0, ($a0)
.L7F0B4D74:
/* 0E98A4 7F0B4D74 8FAD0124 */  lw    $t5, 0x124($sp)
/* 0E98A8 7F0B4D78 24630001 */  addiu $v1, $v1, 1
/* 0E98AC 7F0B4D7C 24840001 */  addiu $a0, $a0, 1
/* 0E98B0 7F0B4D80 25AE0001 */  addiu $t6, $t5, 1
/* 0E98B4 7F0B4D84 29C10007 */  slti  $at, $t6, 7
/* 0E98B8 7F0B4D88 10200004 */  beqz  $at, .L7F0B4D9C
/* 0E98BC 7F0B4D8C AFAE0124 */   sw    $t6, 0x124($sp)
/* 0E98C0 7F0B4D90 90620000 */  lbu   $v0, ($v1)
/* 0E98C4 7F0B4D94 54A2FFF7 */  bnel  $a1, $v0, .L7F0B4D74
/* 0E98C8 7F0B4D98 A0820000 */   sb    $v0, ($a0)
.L7F0B4D9C:
/* 0E98CC 7F0B4D9C 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0E98D0 7F0B4DA0 8FB90124 */  lw    $t9, 0x124($sp)
/* 0E98D4 7F0B4DA4 8FA60178 */  lw    $a2, 0x178($sp)
/* 0E98D8 7F0B4DA8 240F00FF */  li    $t7, 255
/* 0E98DC 7F0B4DAC 03194821 */  addu  $t1, $t8, $t9
/* 0E98E0 7F0B4DB0 A12F0000 */  sb    $t7, ($t1)
/* 0E98E4 7F0B4DB4 18C00013 */  blez  $a2, .L7F0B4E04
/* 0E98E8 7F0B4DB8 AFA00124 */   sw    $zero, 0x124($sp)
/* 0E98EC 7F0B4DBC 93AA0130 */  lbu   $t2, 0x130($sp)
/* 0E98F0 7F0B4DC0 27A20130 */  addiu $v0, $sp, 0x130
/* 0E98F4 7F0B4DC4 8FA40170 */  lw    $a0, 0x170($sp)
/* 0E98F8 7F0B4DC8 50AA000F */  beql  $a1, $t2, .L7F0B4E08
/* 0E98FC 7F0B4DCC 8FAD0124 */   lw    $t5, 0x124($sp)
/* 0E9900 7F0B4DD0 90430000 */  lbu   $v1, ($v0)
/* 0E9904 7F0B4DD4 AC830000 */  sw    $v1, ($a0)
.L7F0B4DD8:
/* 0E9908 7F0B4DD8 8FAB0124 */  lw    $t3, 0x124($sp)
/* 0E990C 7F0B4DDC 24420001 */  addiu $v0, $v0, 1
/* 0E9910 7F0B4DE0 24840004 */  addiu $a0, $a0, 4
/* 0E9914 7F0B4DE4 256C0001 */  addiu $t4, $t3, 1
/* 0E9918 7F0B4DE8 0186082A */  slt   $at, $t4, $a2
/* 0E991C 7F0B4DEC 10200005 */  beqz  $at, .L7F0B4E04
/* 0E9920 7F0B4DF0 AFAC0124 */   sw    $t4, 0x124($sp)
/* 0E9924 7F0B4DF4 90430000 */  lbu   $v1, ($v0)
/* 0E9928 7F0B4DF8 240100FF */  li    $at, 255
/* 0E992C 7F0B4DFC 5461FFF6 */  bnel  $v1, $at, .L7F0B4DD8
/* 0E9930 7F0B4E00 AC830000 */   sw    $v1, ($a0)
.L7F0B4E04:
/* 0E9934 7F0B4E04 8FAD0124 */  lw    $t5, 0x124($sp)
.L7F0B4E08:
/* 0E9938 7F0B4E08 8FAE0174 */  lw    $t6, 0x174($sp)
/* 0E993C 7F0B4E0C ADCD0000 */  sw    $t5, ($t6)
/* 0E9940 7F0B4E10 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E9944 7F0B4E14 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E9948 7F0B4E18 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E994C 7F0B4E1C 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E9950 7F0B4E20 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E9954 7F0B4E24 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E9958 7F0B4E28 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E995C 7F0B4E2C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E9960 7F0B4E30 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E9964 7F0B4E34 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E9968 7F0B4E38 03E00008 */  jr    $ra
/* 0E996C 7F0B4E3C 27BD0160 */   addiu $sp, $sp, 0x160
)
#endif





/**
 * Address 0x7F0B4E40.
*/
Gfx *bgLevelRender(Gfx *arg0)
{
    gSPSetLights1(arg0++, GlobalLight);
    gSPLookAt(arg0++, sub_GAME_7F078474());
    gSPSegment(arg0++, SPSEGMENT_BG_DL, ptr_bg_data);

    if (dword_CODE_bss_8007FF88 == 1)
    {
        gSPDisplayList(arg0++, dword_CODE_bss_8007BF98);
    }
    else
    {
        arg0 = fogRenderClearFogMode(bgScissorCurrentPlayerViewDefault(sub_GAME_7F0B8D78(fogSetRenderFogColor(arg0, 0))));
    }

    gSPMatrix(arg0++, g_viProjectionMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    return bondviewGfxPlayerField5cMatrix(arg0++);
}





f32 sub_GAME_7F0B4F9C(s32 arg0)
{
	return dword_CODE_bss_8007FF94[arg0 + 1];
}






/**
 * Calls @see bgScissorCurrentPlayerView with default current player values.
 * Address 0x7F0B4FB4.
 */
Gfx* bgScissorCurrentPlayerViewDefault(Gfx* arg0)
{
    return bgScissorCurrentPlayerView(
        arg0,
        g_CurrentPlayer->viewleft,
        g_CurrentPlayer->viewtop,
        g_CurrentPlayer->viewleft + g_CurrentPlayer->viewx,
        g_CurrentPlayer->viewtop + g_CurrentPlayer->viewy);
}





/**
 * Same as @see bgScissorCurrentPlayerView, but accepts float parameters.
 * Address 0x7F0B4FF4.
 */
Gfx* bgScissorCurrentPlayerViewF(Gfx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return bgScissorCurrentPlayerView(
        arg0,
        (s32)arg1,
        (s32)arg2,
        ceilFloatToInt(arg3),
        ceilFloatToInt(arg4));
}





/**
 * Specifies the drawing area (the scissoring box).
 * View is bound to current player view properties, but parameters can clip to smaller area.
 *
 * @param arg0: Display list pointer
 * @param left: Screen's left edge coordinates. Must be >= g_CurrentPlayer->viewleft otherwise ignored.
 * @param top: Screen's top edge coordinates. Must be >= g_CurrentPlayer->viewtop otherwise ignored.
 * @param width: Screen's right edge coordinates. Must be <= g_CurrentPlayer->viewleft+viewx otherwise ignored.
 * @param height: Screen's left bottom coordinates. Must be <= g_CurrentPlayer->viewtop+viewy otherwise ignored.
 *
 * Address 0x7F0B5058.
*/
Gfx *bgScissorCurrentPlayerView(Gfx *arg0, s32 left, s32 top, s32 width, s32 height)
{
    struct player *temp_v0;

    temp_v0 = g_CurrentPlayer;

    if (left < (s32) temp_v0->viewleft)
    {
        left = (s32) temp_v0->viewleft;
    }

    if (top < (s32) temp_v0->viewtop)
    {
        top = (s32) temp_v0->viewtop;
    }

    if (temp_v0->viewleft + temp_v0->viewx < width)
    {
        width = temp_v0->viewleft + temp_v0->viewx;
    }

    if (temp_v0->viewtop + temp_v0->viewy < height)
    {
        height = temp_v0->viewtop + temp_v0->viewy;
    }

    gDPSetScissor(arg0++, G_SC_NON_INTERLACE, left, top, width, height);

    return arg0;
}





void sub_GAME_7F0B5168(void) {
    s32 i;

    for (i = 0; i < 200; i++) {
        table_for_portals[i].unk0 = -1;
    }
}





/**
 * Unreferenced.
 *
 * Loosely checks that arg1 surrounds arg0. Requires points be ordered according to min/max.
 *
 * Address 0x7F0B519C.
 */
s32 bgRectIsInside(struct bbox2d *arg0, struct bbox2d *arg1)
{
    if (arg1->min.x <= arg0->min.x)
    {
        if (arg0->min.x <= arg1->max.x)
        {
            if (arg1->min.y <= arg0->min.y)
            {
                if (arg0->min.y <= arg1->max.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}



#ifdef NONMATCHING
void sub_GAME_7F0B5208(s32 arg0, void *arg1) {
    ? sp3C;
    f32 sp40;
    f32 sp5C;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    s32 sp74;
    ? temp_ret;
    s32 temp_v1;
    s32 phi_v1;
    void *phi_a2;
    s32 phi_s6;
    s32 phi_s1;
    s32 phi_s2;
    s32 phi_s3;
    s32 phi_s4;
    s32 phi_s5;
    s32 phi_s6_2;
    s32 phi_s1_2;
    s32 phi_s2_2;
    s32 phi_s3_2;
    s32 phi_s4_2;
    s32 phi_s5_2;
    s32 phi_s1_3;
    s32 phi_s2_3;
    s32 phi_s3_3;

    // Node 0
    viGetZRange(&sp3C);
    sp40 = (f32) (sp40 / mCurrentLevelVisibilityScale);
    phi_v1 = 0;
    phi_a2 = ((arg0 * 0x50) + &g_BgRoomInfo);
    phi_s6_2 = 0;
    phi_s4_2 = 0;
    phi_s5_2 = 0;
    phi_s1_3 = 0;
    phi_s2_3 = 0;
    phi_s3_3 = 0;
loop_1:
    // Node 1
    if ((phi_v1 & 1) != 0)
    {
        // Node 2
        sp5C = (f32) phi_a2->unk38;
    }
    else
    {
        // Node 3
        sp5C = (f32) phi_a2->unk44;
    }
    // Node 4
    if ((phi_v1 & 2) != 0)
    {
        // Node 5
        sp60 = (f32) phi_a2->unk3C;
    }
    else
    {
        // Node 6
        sp60 = (f32) phi_a2->unk48;
    }
    // Node 7
    if ((phi_v1 & 4) != 0)
    {
        // Node 8
        sp64 = (f32) phi_a2->unk40;
    }
    else
    {
        // Node 9
        sp64 = (f32) phi_a2->unk4C;
    }
    // Node 10
    sp74 = (s32) phi_v1;
    temp_ret = sub_GAME_7F0B5488(&sp5C, &sp68, phi_a2);
    if (temp_ret == 0)
    {
        // Node 11
        phi_s1 = phi_s1_3;
        if (sp40 <= -sp70)
        {
            // Node 12
            phi_s1 = (phi_s1_3 + 1);
        }
        // Node 13
        phi_s2 = phi_s2_3;
        if (*arg1 <= sp68)
        {
            // Node 14
            phi_s2 = (phi_s2_3 + 1);
        }
        // Node 15
        phi_s3 = phi_s3_3;
        if (sp68 <= arg1->unk8)
        {
            // Node 16
            phi_s3 = (phi_s3_3 + 1);
        }
        // Node 17
        phi_s4 = phi_s4_2;
        if (arg1->unk4 <= sp6C)
        {
            // Node 18
            phi_s4 = (phi_s4_2 + 1);
        }
        // Node 19
        phi_s5 = phi_s5_2;
        if (sp6C <= arg1->unkC)
        {
            // Node 20
            phi_s5 = (phi_s5_2 + 1);
        }
        // Node 21
        phi_s6 = (phi_s6_2 + 1);
    }
    else
    {
        // Node 22
        phi_s1_2 = phi_s1_3;
        if (sp40 <= -sp70)
        {
            // Node 23
            phi_s1_2 = (phi_s1_3 + 1);
        }
        // Node 24
        if (sp68 <= *arg1)
        {
            // Node 25
            phi_s2_2 = (phi_s2_3 + 1);
            phi_s3_2 = phi_s3_3;
        }
        else
        {
            // Node 26
            phi_s2_2 = phi_s2_3;
            phi_s3_2 = phi_s3_3;
            if (arg1->unk8 <= sp68)
            {
                // Node 27
                phi_s2_2 = phi_s2_3;
                phi_s3_2 = (phi_s3_3 + 1);
            }
        }
        // Node 28
        if (sp6C <= arg1->unk4)
        {
            // Node 29
            phi_s6 = phi_s6_2;
            phi_s1 = phi_s1_2;
            phi_s2 = phi_s2_2;
            phi_s3 = phi_s3_2;
            phi_s4 = (phi_s4_2 + 1);
            phi_s5 = phi_s5_2;
        }
        else
        {
            // Node 30
            phi_s6 = phi_s6_2;
            phi_s1 = phi_s1_2;
            phi_s2 = phi_s2_2;
            phi_s3 = phi_s3_2;
            phi_s4 = phi_s4_2;
            phi_s5 = phi_s5_2;
            if (arg1->unkC <= sp6C)
            {
                // Node 31
                phi_s6 = phi_s6_2;
                phi_s1 = phi_s1_2;
                phi_s2 = phi_s2_2;
                phi_s3 = phi_s3_2;
                phi_s4 = phi_s4_2;
                phi_s5 = (phi_s5_2 + 1);
            }
        }
    }
    // Node 32
    temp_v1 = (phi_v1 + 1);
    phi_v1 = temp_v1;
    phi_a2 = sp38;
    phi_s6_2 = phi_s6;
    phi_s4_2 = phi_s4;
    phi_s5_2 = phi_s5;
    phi_s1_3 = phi_s1;
    phi_s2_3 = phi_s2;
    phi_s3_3 = phi_s3;
    if (temp_v1 != 8)
    {
        goto loop_1;
    }
    // Node 33
    if ((((((phi_s6 == 8) || (phi_s1 == 8)) || (phi_s2 == 8)) || (phi_s3 == 8)) || (phi_s4 == 8)) || (phi_s5 == 8))
    {
        // Node 39
    }
    else
    {

    }
    // Node 40
    return temp_ret;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B5208
/* 0E9D38 7F0B5208 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0E9D3C 7F0B520C AFBF0034 */  sw    $ra, 0x34($sp)
/* 0E9D40 7F0B5210 AFB60030 */  sw    $s6, 0x30($sp)
/* 0E9D44 7F0B5214 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E9D48 7F0B5218 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E9D4C 7F0B521C AFB30024 */  sw    $s3, 0x24($sp)
/* 0E9D50 7F0B5220 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E9D54 7F0B5224 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E9D58 7F0B5228 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E9D5C 7F0B522C AFA40078 */  sw    $a0, 0x78($sp)
/* 0E9D60 7F0B5230 00A08025 */  move  $s0, $a1
/* 0E9D64 7F0B5234 00008825 */  move  $s1, $zero
/* 0E9D68 7F0B5238 0000B025 */  move  $s6, $zero
/* 0E9D6C 7F0B523C 00009025 */  move  $s2, $zero
/* 0E9D70 7F0B5240 00009825 */  move  $s3, $zero
/* 0E9D74 7F0B5244 0000A025 */  move  $s4, $zero
/* 0E9D78 7F0B5248 0000A825 */  move  $s5, $zero
/* 0E9D7C 7F0B524C 0C0011AB */  jal   viGetZRange
/* 0E9D80 7F0B5250 27A4003C */   addiu $a0, $sp, 0x3c
/* 0E9D84 7F0B5254 3C018004 */  lui   $at, %hi(mCurrentLevelVisibilityScale)
/* 0E9D88 7F0B5258 C42613FC */  lwc1  $f6, %lo(mCurrentLevelVisibilityScale)($at)
/* 0E9D8C 7F0B525C C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0E9D90 7F0B5260 8FAE0078 */  lw    $t6, 0x78($sp)
/* 0E9D94 7F0B5264 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0E9D98 7F0B5268 46062203 */  div.s $f8, $f4, $f6
/* 0E9D9C 7F0B526C 000E7880 */  sll   $t7, $t6, 2
/* 0E9DA0 7F0B5270 01EE7821 */  addu  $t7, $t7, $t6
/* 0E9DA4 7F0B5274 000F7900 */  sll   $t7, $t7, 4
/* 0E9DA8 7F0B5278 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0E9DAC 7F0B527C 01F83021 */  addu  $a2, $t7, $t8
/* 0E9DB0 7F0B5280 00001825 */  move  $v1, $zero
/* 0E9DB4 7F0B5284 E7A80040 */  swc1  $f8, 0x40($sp)
/* 0E9DB8 7F0B5288 30790001 */  andi  $t9, $v1, 1
.L7F0B528C:
/* 0E9DBC 7F0B528C 13200004 */  beqz  $t9, .L7F0B52A0
/* 0E9DC0 7F0B5290 30680002 */   andi  $t0, $v1, 2
/* 0E9DC4 7F0B5294 C4CA0038 */  lwc1  $f10, 0x38($a2)
/* 0E9DC8 7F0B5298 10000003 */  b     .L7F0B52A8
/* 0E9DCC 7F0B529C E7AA005C */   swc1  $f10, 0x5c($sp)
.L7F0B52A0:
/* 0E9DD0 7F0B52A0 C4D00044 */  lwc1  $f16, 0x44($a2)
/* 0E9DD4 7F0B52A4 E7B0005C */  swc1  $f16, 0x5c($sp)
.L7F0B52A8:
/* 0E9DD8 7F0B52A8 11000004 */  beqz  $t0, .L7F0B52BC
/* 0E9DDC 7F0B52AC 30690004 */   andi  $t1, $v1, 4
/* 0E9DE0 7F0B52B0 C4D2003C */  lwc1  $f18, 0x3c($a2)
/* 0E9DE4 7F0B52B4 10000003 */  b     .L7F0B52C4
/* 0E9DE8 7F0B52B8 E7B20060 */   swc1  $f18, 0x60($sp)
.L7F0B52BC:
/* 0E9DEC 7F0B52BC C4C40048 */  lwc1  $f4, 0x48($a2)
/* 0E9DF0 7F0B52C0 E7A40060 */  swc1  $f4, 0x60($sp)
.L7F0B52C4:
/* 0E9DF4 7F0B52C4 11200004 */  beqz  $t1, .L7F0B52D8
/* 0E9DF8 7F0B52C8 27A4005C */   addiu $a0, $sp, 0x5c
/* 0E9DFC 7F0B52CC C4C60040 */  lwc1  $f6, 0x40($a2)
/* 0E9E00 7F0B52D0 10000003 */  b     .L7F0B52E0
/* 0E9E04 7F0B52D4 E7A60064 */   swc1  $f6, 0x64($sp)
.L7F0B52D8:
/* 0E9E08 7F0B52D8 C4C8004C */  lwc1  $f8, 0x4c($a2)
/* 0E9E0C 7F0B52DC E7A80064 */  swc1  $f8, 0x64($sp)
.L7F0B52E0:
/* 0E9E10 7F0B52E0 27A50068 */  addiu $a1, $sp, 0x68
/* 0E9E14 7F0B52E4 AFA30074 */  sw    $v1, 0x74($sp)
/* 0E9E18 7F0B52E8 0FC2D522 */  jal   sub_GAME_7F0B5488
/* 0E9E1C 7F0B52EC AFA60038 */   sw    $a2, 0x38($sp)
/* 0E9E20 7F0B52F0 8FA30074 */  lw    $v1, 0x74($sp)
/* 0E9E24 7F0B52F4 8FA60038 */  lw    $a2, 0x38($sp)
/* 0E9E28 7F0B52F8 14400025 */  bnez  $v0, .L7F0B5390
/* 0E9E2C 7F0B52FC 24070008 */   li    $a3, 8
/* 0E9E30 7F0B5300 C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 0E9E34 7F0B5304 C7B20040 */  lwc1  $f18, 0x40($sp)
/* 0E9E38 7F0B5308 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0E9E3C 7F0B530C 46005407 */  neg.s $f16, $f10
/* 0E9E40 7F0B5310 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0E9E44 7F0B5314 4610903E */  c.le.s $f18, $f16
/* 0E9E48 7F0B5318 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0E9E4C 7F0B531C 45020003 */  bc1fl .L7F0B532C
/* 0E9E50 7F0B5320 C6060000 */   lwc1  $f6, ($s0)
/* 0E9E54 7F0B5324 26310001 */  addiu $s1, $s1, 1
/* 0E9E58 7F0B5328 C6060000 */  lwc1  $f6, ($s0)
.L7F0B532C:
/* 0E9E5C 7F0B532C 4604303E */  c.le.s $f6, $f4
/* 0E9E60 7F0B5330 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0E9E64 7F0B5334 45020003 */  bc1fl .L7F0B5344
/* 0E9E68 7F0B5338 C6080008 */   lwc1  $f8, 8($s0)
/* 0E9E6C 7F0B533C 26520001 */  addiu $s2, $s2, 1
/* 0E9E70 7F0B5340 C6080008 */  lwc1  $f8, 8($s0)
.L7F0B5344:
/* 0E9E74 7F0B5344 4608503E */  c.le.s $f10, $f8
/* 0E9E78 7F0B5348 00000000 */  nop
/* 0E9E7C 7F0B534C 45020003 */  bc1fl .L7F0B535C
/* 0E9E80 7F0B5350 C6120004 */   lwc1  $f18, 4($s0)
/* 0E9E84 7F0B5354 26730001 */  addiu $s3, $s3, 1
/* 0E9E88 7F0B5358 C6120004 */  lwc1  $f18, 4($s0)
.L7F0B535C:
/* 0E9E8C 7F0B535C 4610903E */  c.le.s $f18, $f16
/* 0E9E90 7F0B5360 00000000 */  nop
/* 0E9E94 7F0B5364 45020003 */  bc1fl .L7F0B5374
/* 0E9E98 7F0B5368 C604000C */   lwc1  $f4, 0xc($s0)
/* 0E9E9C 7F0B536C 26940001 */  addiu $s4, $s4, 1
/* 0E9EA0 7F0B5370 C604000C */  lwc1  $f4, 0xc($s0)
.L7F0B5374:
/* 0E9EA4 7F0B5374 4604303E */  c.le.s $f6, $f4
/* 0E9EA8 7F0B5378 00000000 */  nop
/* 0E9EAC 7F0B537C 45000002 */  bc1f  .L7F0B5388
/* 0E9EB0 7F0B5380 00000000 */   nop
/* 0E9EB4 7F0B5384 26B50001 */  addiu $s5, $s5, 1
.L7F0B5388:
/* 0E9EB8 7F0B5388 10000025 */  b     .L7F0B5420
/* 0E9EBC 7F0B538C 26D60001 */   addiu $s6, $s6, 1
.L7F0B5390:
/* 0E9EC0 7F0B5390 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0E9EC4 7F0B5394 C7B00040 */  lwc1  $f16, 0x40($sp)
/* 0E9EC8 7F0B5398 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0E9ECC 7F0B539C 46004287 */  neg.s $f10, $f8
/* 0E9ED0 7F0B53A0 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0E9ED4 7F0B53A4 460A803E */  c.le.s $f16, $f10
/* 0E9ED8 7F0B53A8 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0E9EDC 7F0B53AC 45020003 */  bc1fl .L7F0B53BC
/* 0E9EE0 7F0B53B0 C6120000 */   lwc1  $f18, ($s0)
/* 0E9EE4 7F0B53B4 26310001 */  addiu $s1, $s1, 1
/* 0E9EE8 7F0B53B8 C6120000 */  lwc1  $f18, ($s0)
.L7F0B53BC:
/* 0E9EEC 7F0B53BC 4612203E */  c.le.s $f4, $f18
/* 0E9EF0 7F0B53C0 C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0E9EF4 7F0B53C4 45020004 */  bc1fl .L7F0B53D8
/* 0E9EF8 7F0B53C8 C6080008 */   lwc1  $f8, 8($s0)
/* 0E9EFC 7F0B53CC 10000007 */  b     .L7F0B53EC
/* 0E9F00 7F0B53D0 26520001 */   addiu $s2, $s2, 1
/* 0E9F04 7F0B53D4 C6080008 */  lwc1  $f8, 8($s0)
.L7F0B53D8:
/* 0E9F08 7F0B53D8 4606403E */  c.le.s $f8, $f6
/* 0E9F0C 7F0B53DC 00000000 */  nop
/* 0E9F10 7F0B53E0 45020003 */  bc1fl .L7F0B53F0
/* 0E9F14 7F0B53E4 C60A0004 */   lwc1  $f10, 4($s0)
/* 0E9F18 7F0B53E8 26730001 */  addiu $s3, $s3, 1
.L7F0B53EC:
/* 0E9F1C 7F0B53EC C60A0004 */  lwc1  $f10, 4($s0)
.L7F0B53F0:
/* 0E9F20 7F0B53F0 460A803E */  c.le.s $f16, $f10
/* 0E9F24 7F0B53F4 00000000 */  nop
/* 0E9F28 7F0B53F8 45020004 */  bc1fl .L7F0B540C
/* 0E9F2C 7F0B53FC C604000C */   lwc1  $f4, 0xc($s0)
/* 0E9F30 7F0B5400 10000007 */  b     .L7F0B5420
/* 0E9F34 7F0B5404 26940001 */   addiu $s4, $s4, 1
/* 0E9F38 7F0B5408 C604000C */  lwc1  $f4, 0xc($s0)
.L7F0B540C:
/* 0E9F3C 7F0B540C 4612203E */  c.le.s $f4, $f18
/* 0E9F40 7F0B5410 00000000 */  nop
/* 0E9F44 7F0B5414 45020003 */  bc1fl .L7F0B5424
/* 0E9F48 7F0B5418 24630001 */   addiu $v1, $v1, 1
/* 0E9F4C 7F0B541C 26B50001 */  addiu $s5, $s5, 1
.L7F0B5420:
/* 0E9F50 7F0B5420 24630001 */  addiu $v1, $v1, 1
.L7F0B5424:
/* 0E9F54 7F0B5424 5467FF99 */  bnel  $v1, $a3, .L7F0B528C
/* 0E9F58 7F0B5428 30790001 */   andi  $t9, $v1, 1
/* 0E9F5C 7F0B542C 12C7000B */  beq   $s6, $a3, .L7F0B545C
/* 0E9F60 7F0B5430 8FB00018 */   lw    $s0, 0x18($sp)
/* 0E9F64 7F0B5434 12270009 */  beq   $s1, $a3, .L7F0B545C
/* 0E9F68 7F0B5438 00000000 */   nop
/* 0E9F6C 7F0B543C 12470007 */  beq   $s2, $a3, .L7F0B545C
/* 0E9F70 7F0B5440 00000000 */   nop
/* 0E9F74 7F0B5444 12670005 */  beq   $s3, $a3, .L7F0B545C
/* 0E9F78 7F0B5448 00000000 */   nop
/* 0E9F7C 7F0B544C 12870003 */  beq   $s4, $a3, .L7F0B545C
/* 0E9F80 7F0B5450 00000000 */   nop
/* 0E9F84 7F0B5454 16A70003 */  bne   $s5, $a3, .L7F0B5464
/* 0E9F88 7F0B5458 24020001 */   li    $v0, 1
.L7F0B545C:
/* 0E9F8C 7F0B545C 10000001 */  b     .L7F0B5464
/* 0E9F90 7F0B5460 00001025 */   move  $v0, $zero
.L7F0B5464:
/* 0E9F94 7F0B5464 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0E9F98 7F0B5468 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E9F9C 7F0B546C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E9FA0 7F0B5470 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E9FA4 7F0B5474 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E9FA8 7F0B5478 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E9FAC 7F0B547C 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E9FB0 7F0B5480 03E00008 */  jr    $ra
/* 0E9FB4 7F0B5484 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif


s32 sub_GAME_7F0B5488(coord3d* arg0, coord3d* arg1)
{
    Mtxf* temp_a0;
    s32 var_v0;

    temp_a0 = camGetWorldToScreenMtxf();
    arg1->x = arg0->x * room_data_float2;
    arg1->y = arg0->y * room_data_float2;
    arg1->z = arg0->z * room_data_float2;
    mtx4TransformVecInPlace(temp_a0, arg1);

    transform3Dto2DWithZScaling(arg1, arg1);

    if (arg1->z > 0.0f)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


#ifdef NONMATCHING
void sub_GAME_7F0B5528(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058C7C
.word 0x3f666666 /*0.89999998*/
.text
glabel sub_GAME_7F0B5528
/* 0EA058 7F0B5528 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 0EA05C 7F0B552C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0EA060 7F0B5530 4485A000 */  mtc1  $a1, $f20
/* 0EA064 7F0B5534 AFBF0054 */  sw    $ra, 0x54($sp)
/* 0EA068 7F0B5538 AFB60048 */  sw    $s6, 0x48($sp)
/* 0EA06C 7F0B553C 00C0B025 */  move  $s6, $a2
/* 0EA070 7F0B5540 AFBE0050 */  sw    $fp, 0x50($sp)
/* 0EA074 7F0B5544 AFB7004C */  sw    $s7, 0x4c($sp)
/* 0EA078 7F0B5548 AFB50044 */  sw    $s5, 0x44($sp)
/* 0EA07C 7F0B554C AFB40040 */  sw    $s4, 0x40($sp)
/* 0EA080 7F0B5550 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0EA084 7F0B5554 AFB20038 */  sw    $s2, 0x38($sp)
/* 0EA088 7F0B5558 AFB10034 */  sw    $s1, 0x34($sp)
/* 0EA08C 7F0B555C AFB00030 */  sw    $s0, 0x30($sp)
/* 0EA090 7F0B5560 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0EA094 7F0B5564 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0EA098 7F0B5568 0FC1E0F1 */  jal   camGetWorldToScreenMtxf
/* 0EA09C 7F0B556C AFA400B0 */   sw    $a0, 0xb0($sp)
/* 0EA0A0 7F0B5570 AFA200AC */  sw    $v0, 0xac($sp)
/* 0EA0A4 7F0B5574 241E0001 */  li    $fp, 1
/* 0EA0A8 7F0B5578 0C0011AB */  jal   viGetZRange
/* 0EA0AC 7F0B557C 27A40098 */   addiu $a0, $sp, 0x98
/* 0EA0B0 7F0B5580 3C018004 */  lui   $at, %hi(mCurrentLevelVisibilityScale)
/* 0EA0B4 7F0B5584 C42613FC */  lwc1  $f6, %lo(mCurrentLevelVisibilityScale)($at)
/* 0EA0B8 7F0B5588 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0EA0BC 7F0B558C 3C138008 */  lui   $s3, %hi(g_BgPortals)
/* 0EA0C0 7F0B5590 8FB500B0 */  lw    $s5, 0xb0($sp)
/* 0EA0C4 7F0B5594 46062203 */  div.s $f8, $f4, $f6
/* 0EA0C8 7F0B5598 2673FF80 */  addiu $s3, %lo(g_BgPortals) # addiu $s3, $s3, -0x80
/* 0EA0CC 7F0B559C 8E6F0000 */  lw    $t7, ($s3)
/* 0EA0D0 7F0B55A0 001570C0 */  sll   $t6, $s5, 3
/* 0EA0D4 7F0B55A4 01C0A825 */  move  $s5, $t6
/* 0EA0D8 7F0B55A8 01EEC021 */  addu  $t8, $t7, $t6
/* 0EA0DC 7F0B55AC 00009025 */  move  $s2, $zero
/* 0EA0E0 7F0B55B0 02C08025 */  move  $s0, $s6
/* 0EA0E4 7F0B55B4 E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0EA0E8 7F0B55B8 8F020000 */  lw    $v0, ($t8)
/* 0EA0EC 7F0B55BC 90440000 */  lbu   $a0, ($v0)
/* 0EA0F0 7F0B55C0 5880004E */  blezl $a0, .L7F0B56FC
/* 0EA0F4 7F0B55C4 4480B000 */   mtc1  $zero, $f22
/* 0EA0F8 7F0B55C8 3C018006 */  lui   $at, %hi(D_80058C7C)
/* 0EA0FC 7F0B55CC 3C148004 */  lui   $s4, %hi(room_data_float2)
/* 0EA100 7F0B55D0 4480B000 */  mtc1  $zero, $f22
/* 0EA104 7F0B55D4 269413F8 */  addiu $s4, %lo(room_data_float2) # addiu $s4, $s4, 0x13f8
/* 0EA108 7F0B55D8 C4388C7C */  lwc1  $f24, %lo(D_80058C7C)($at)
/* 0EA10C 7F0B55DC 00008825 */  move  $s1, $zero
/* 0EA110 7F0B55E0 27B70080 */  addiu $s7, $sp, 0x80
/* 0EA114 7F0B55E4 0051C821 */  addu  $t9, $v0, $s1
.L7F0B55E8:
/* 0EA118 7F0B55E8 C72A0004 */  lwc1  $f10, 4($t9)
/* 0EA11C 7F0B55EC 4616A032 */  c.eq.s $f20, $f22
/* 0EA120 7F0B55F0 02E02825 */  move  $a1, $s7
/* 0EA124 7F0B55F4 E60A0000 */  swc1  $f10, ($s0)
/* 0EA128 7F0B55F8 8E680000 */  lw    $t0, ($s3)
/* 0EA12C 7F0B55FC 01154821 */  addu  $t1, $t0, $s5
/* 0EA130 7F0B5600 8D2A0000 */  lw    $t2, ($t1)
/* 0EA134 7F0B5604 01515821 */  addu  $t3, $t2, $s1
/* 0EA138 7F0B5608 C5720008 */  lwc1  $f18, 8($t3)
/* 0EA13C 7F0B560C E6120004 */  swc1  $f18, 4($s0)
/* 0EA140 7F0B5610 8E6C0000 */  lw    $t4, ($s3)
/* 0EA144 7F0B5614 01956821 */  addu  $t5, $t4, $s5
/* 0EA148 7F0B5618 8DAE0000 */  lw    $t6, ($t5)
/* 0EA14C 7F0B561C 01D17821 */  addu  $t7, $t6, $s1
/* 0EA150 7F0B5620 C5E4000C */  lwc1  $f4, 0xc($t7)
/* 0EA154 7F0B5624 45010012 */  bc1t  .L7F0B5670
/* 0EA158 7F0B5628 E6040008 */   swc1  $f4, 8($s0)
/* 0EA15C 7F0B562C 0FC2E5B3 */  jal   sub_GAME_7F0B96CC
/* 0EA160 7F0B5630 8FA400B0 */   lw    $a0, 0xb0($sp)
/* 0EA164 7F0B5634 C7A80080 */  lwc1  $f8, 0x80($sp)
/* 0EA168 7F0B5638 C6060000 */  lwc1  $f6, ($s0)
/* 0EA16C 7F0B563C C6040004 */  lwc1  $f4, 4($s0)
/* 0EA170 7F0B5640 46144282 */  mul.s $f10, $f8, $f20
/* 0EA174 7F0B5644 460A3480 */  add.s $f18, $f6, $f10
/* 0EA178 7F0B5648 E6120000 */  swc1  $f18, ($s0)
/* 0EA17C 7F0B564C C7A80084 */  lwc1  $f8, 0x84($sp)
/* 0EA180 7F0B5650 C6120008 */  lwc1  $f18, 8($s0)
/* 0EA184 7F0B5654 46144182 */  mul.s $f6, $f8, $f20
/* 0EA188 7F0B5658 46062280 */  add.s $f10, $f4, $f6
/* 0EA18C 7F0B565C E60A0004 */  swc1  $f10, 4($s0)
/* 0EA190 7F0B5660 C7A80088 */  lwc1  $f8, 0x88($sp)
/* 0EA194 7F0B5664 46144102 */  mul.s $f4, $f8, $f20
/* 0EA198 7F0B5668 46049180 */  add.s $f6, $f18, $f4
/* 0EA19C 7F0B566C E6060008 */  swc1  $f6, 8($s0)
.L7F0B5670:
/* 0EA1A0 7F0B5670 C60A0000 */  lwc1  $f10, ($s0)
/* 0EA1A4 7F0B5674 C6880000 */  lwc1  $f8, ($s4)
/* 0EA1A8 7F0B5678 C6040004 */  lwc1  $f4, 4($s0)
/* 0EA1AC 7F0B567C 02002825 */  move  $a1, $s0
/* 0EA1B0 7F0B5680 46085482 */  mul.s $f18, $f10, $f8
/* 0EA1B4 7F0B5684 C6080008 */  lwc1  $f8, 8($s0)
/* 0EA1B8 7F0B5688 E6120000 */  swc1  $f18, ($s0)
/* 0EA1BC 7F0B568C C6860000 */  lwc1  $f6, ($s4)
/* 0EA1C0 7F0B5690 46062282 */  mul.s $f10, $f4, $f6
/* 0EA1C4 7F0B5694 E60A0004 */  swc1  $f10, 4($s0)
/* 0EA1C8 7F0B5698 C6920000 */  lwc1  $f18, ($s4)
/* 0EA1CC 7F0B569C 46124102 */  mul.s $f4, $f8, $f18
/* 0EA1D0 7F0B56A0 E6040008 */  swc1  $f4, 8($s0)
/* 0EA1D4 7F0B56A4 0FC1611D */  jal   mtx4TransformVecInPlace
/* 0EA1D8 7F0B56A8 8FA400AC */   lw    $a0, 0xac($sp)
/* 0EA1DC 7F0B56AC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0EA1E0 7F0B56B0 C6120008 */  lwc1  $f18, 8($s0)
/* 0EA1E4 7F0B56B4 46003287 */  neg.s $f10, $f6
/* 0EA1E8 7F0B56B8 46185202 */  mul.s $f8, $f10, $f24
/* 0EA1EC 7F0B56BC 4612403C */  c.lt.s $f8, $f18
/* 0EA1F0 7F0B56C0 00000000 */  nop
/* 0EA1F4 7F0B56C4 45020003 */  bc1fl .L7F0B56D4
/* 0EA1F8 7F0B56C8 8E780000 */   lw    $t8, ($s3)
/* 0EA1FC 7F0B56CC 0000F025 */  move  $fp, $zero
/* 0EA200 7F0B56D0 8E780000 */  lw    $t8, ($s3)
.L7F0B56D4:
/* 0EA204 7F0B56D4 26520001 */  addiu $s2, $s2, 1
/* 0EA208 7F0B56D8 2631000C */  addiu $s1, $s1, 0xc
/* 0EA20C 7F0B56DC 0315C821 */  addu  $t9, $t8, $s5
/* 0EA210 7F0B56E0 8F220000 */  lw    $v0, ($t9)
/* 0EA214 7F0B56E4 2610000C */  addiu $s0, $s0, 0xc
/* 0EA218 7F0B56E8 90440000 */  lbu   $a0, ($v0)
/* 0EA21C 7F0B56EC 0244082A */  slt   $at, $s2, $a0
/* 0EA220 7F0B56F0 5420FFBD */  bnezl $at, .L7F0B55E8
/* 0EA224 7F0B56F4 0051C821 */   addu  $t9, $v0, $s1
/* 0EA228 7F0B56F8 4480B000 */  mtc1  $zero, $f22
.L7F0B56FC:
/* 0EA22C 7F0B56FC 13C00003 */  beqz  $fp, .L7F0B570C
/* 0EA230 7F0B5700 00803825 */   move  $a3, $a0
/* 0EA234 7F0B5704 10000048 */  b     .L7F0B5828
/* 0EA238 7F0B5708 00001025 */   move  $v0, $zero
.L7F0B570C:
/* 0EA23C 7F0B570C 18800045 */  blez  $a0, .L7F0B5824
/* 0EA240 7F0B5710 00009025 */   move  $s2, $zero
/* 0EA244 7F0B5714 02C08025 */  move  $s0, $s6
/* 0EA248 7F0B5718 2406000C */  li    $a2, 12
.L7F0B571C:
/* 0EA24C 7F0B571C 26450001 */  addiu $a1, $s2, 1
/* 0EA250 7F0B5720 00A4001A */  div   $zero, $a1, $a0
/* 0EA254 7F0B5724 C6100008 */  lwc1  $f16, 8($s0)
/* 0EA258 7F0B5728 00001810 */  mfhi  $v1
/* 0EA25C 7F0B572C 00A09025 */  move  $s2, $a1
/* 0EA260 7F0B5730 4610B03C */  c.lt.s $f22, $f16
/* 0EA264 7F0B5734 14800002 */  bnez  $a0, .L7F0B5740
/* 0EA268 7F0B5738 00000000 */   nop
/* 0EA26C 7F0B573C 0007000D */  break 7
.L7F0B5740:
/* 0EA270 7F0B5740 2401FFFF */  li    $at, -1
/* 0EA274 7F0B5744 14810004 */  bne   $a0, $at, .L7F0B5758
/* 0EA278 7F0B5748 3C018000 */   lui   $at, 0x8000
/* 0EA27C 7F0B574C 14A10002 */  bne   $a1, $at, .L7F0B5758
/* 0EA280 7F0B5750 00000000 */   nop
/* 0EA284 7F0B5754 0006000D */  break 6
.L7F0B5758:
/* 0EA288 7F0B5758 4502000A */  bc1fl .L7F0B5784
/* 0EA28C 7F0B575C 4616803E */   c.le.s $f16, $f22
/* 0EA290 7F0B5760 00660019 */  multu $v1, $a2
/* 0EA294 7F0B5764 00004012 */  mflo  $t0
/* 0EA298 7F0B5768 02C81021 */  addu  $v0, $s6, $t0
/* 0EA29C 7F0B576C C44E0008 */  lwc1  $f14, 8($v0)
/* 0EA2A0 7F0B5770 4616703E */  c.le.s $f14, $f22
/* 0EA2A4 7F0B5774 00000000 */  nop
/* 0EA2A8 7F0B5778 4503000E */  bc1tl .L7F0B57B4
/* 0EA2AC 7F0B577C 46107181 */   sub.s $f6, $f14, $f16
/* 0EA2B0 7F0B5780 4616803E */  c.le.s $f16, $f22
.L7F0B5784:
/* 0EA2B4 7F0B5784 00000000 */  nop
/* 0EA2B8 7F0B5788 45020024 */  bc1fl .L7F0B581C
/* 0EA2BC 7F0B578C 00A4082A */   slt   $at, $a1, $a0
/* 0EA2C0 7F0B5790 00660019 */  multu $v1, $a2
/* 0EA2C4 7F0B5794 00004812 */  mflo  $t1
/* 0EA2C8 7F0B5798 02C91021 */  addu  $v0, $s6, $t1
/* 0EA2CC 7F0B579C C44E0008 */  lwc1  $f14, 8($v0)
/* 0EA2D0 7F0B57A0 460EB03C */  c.lt.s $f22, $f14
/* 0EA2D4 7F0B57A4 00000000 */  nop
/* 0EA2D8 7F0B57A8 4502001C */  bc1fl .L7F0B581C
/* 0EA2DC 7F0B57AC 00A4082A */   slt   $at, $a1, $a0
/* 0EA2E0 7F0B57B0 46107181 */  sub.s $f6, $f14, $f16
.L7F0B57B4:
/* 0EA2E4 7F0B57B4 C6000000 */  lwc1  $f0, ($s0)
/* 0EA2E8 7F0B57B8 C44A0000 */  lwc1  $f10, ($v0)
/* 0EA2EC 7F0B57BC 46008107 */  neg.s $f4, $f16
/* 0EA2F0 7F0B57C0 00E60019 */  multu $a3, $a2
/* 0EA2F4 7F0B57C4 46062303 */  div.s $f12, $f4, $f6
/* 0EA2F8 7F0B57C8 3C0B8008 */  lui   $t3, %hi(g_BgPortals)
/* 0EA2FC 7F0B57CC 24E70001 */  addiu $a3, $a3, 1
/* 0EA300 7F0B57D0 46005201 */  sub.s $f8, $f10, $f0
/* 0EA304 7F0B57D4 00005012 */  mflo  $t2
/* 0EA308 7F0B57D8 02CA1821 */  addu  $v1, $s6, $t2
/* 0EA30C 7F0B57DC 2463000C */  addiu $v1, $v1, 0xc
/* 0EA310 7F0B57E0 460C4482 */  mul.s $f18, $f8, $f12
/* 0EA314 7F0B57E4 46009100 */  add.s $f4, $f18, $f0
/* 0EA318 7F0B57E8 E464FFF4 */  swc1  $f4, -0xc($v1)
/* 0EA31C 7F0B57EC C4460004 */  lwc1  $f6, 4($v0)
/* 0EA320 7F0B57F0 C6020004 */  lwc1  $f2, 4($s0)
/* 0EA324 7F0B57F4 E476FFFC */  swc1  $f22, -4($v1)
/* 0EA328 7F0B57F8 46023281 */  sub.s $f10, $f6, $f2
/* 0EA32C 7F0B57FC 460C5202 */  mul.s $f8, $f10, $f12
/* 0EA330 7F0B5800 46024480 */  add.s $f18, $f8, $f2
/* 0EA334 7F0B5804 E472FFF8 */  swc1  $f18, -8($v1)
/* 0EA338 7F0B5808 8D6BFF80 */  lw    $t3, %lo(g_BgPortals)($t3)
/* 0EA33C 7F0B580C 01756021 */  addu  $t4, $t3, $s5
/* 0EA340 7F0B5810 8D8D0000 */  lw    $t5, ($t4)
/* 0EA344 7F0B5814 91A40000 */  lbu   $a0, ($t5)
/* 0EA348 7F0B5818 00A4082A */  slt   $at, $a1, $a0
.L7F0B581C:
/* 0EA34C 7F0B581C 1420FFBF */  bnez  $at, .L7F0B571C
/* 0EA350 7F0B5820 2610000C */   addiu $s0, $s0, 0xc
.L7F0B5824:
/* 0EA354 7F0B5824 00E01025 */  move  $v0, $a3
.L7F0B5828:
/* 0EA358 7F0B5828 8FBF0054 */  lw    $ra, 0x54($sp)
/* 0EA35C 7F0B582C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0EA360 7F0B5830 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0EA364 7F0B5834 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0EA368 7F0B5838 8FB00030 */  lw    $s0, 0x30($sp)
/* 0EA36C 7F0B583C 8FB10034 */  lw    $s1, 0x34($sp)
/* 0EA370 7F0B5840 8FB20038 */  lw    $s2, 0x38($sp)
/* 0EA374 7F0B5844 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0EA378 7F0B5848 8FB40040 */  lw    $s4, 0x40($sp)
/* 0EA37C 7F0B584C 8FB50044 */  lw    $s5, 0x44($sp)
/* 0EA380 7F0B5850 8FB60048 */  lw    $s6, 0x48($sp)
/* 0EA384 7F0B5854 8FB7004C */  lw    $s7, 0x4c($sp)
/* 0EA388 7F0B5858 8FBE0050 */  lw    $fp, 0x50($sp)
/* 0EA38C 7F0B585C 03E00008 */  jr    $ra
/* 0EA390 7F0B5860 27BD00B0 */   addiu $sp, $sp, 0xb0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B5864(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B5864
/* 0EA394 7F0B5864 27BDFE90 */  addiu $sp, $sp, -0x170
/* 0EA398 7F0B5868 00047080 */  sll   $t6, $a0, 2
/* 0EA39C 7F0B586C 01C47021 */  addu  $t6, $t6, $a0
/* 0EA3A0 7F0B5870 3C0F8008 */  lui   $t7, %hi(table_for_portals)
/* 0EA3A4 7F0B5874 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0EA3A8 7F0B5878 25EF1618 */  addiu $t7, %lo(table_for_portals) # addiu $t7, $t7, 0x1618
/* 0EA3AC 7F0B587C 000E7080 */  sll   $t6, $t6, 2
/* 0EA3B0 7F0B5880 01CFA821 */  addu  $s5, $t6, $t7
/* 0EA3B4 7F0B5884 8EB80000 */  lw    $t8, ($s5)
/* 0EA3B8 7F0B5888 AFB60040 */  sw    $s6, 0x40($sp)
/* 0EA3BC 7F0B588C AFB00028 */  sw    $s0, 0x28($sp)
/* 0EA3C0 7F0B5890 00808025 */  move  $s0, $a0
/* 0EA3C4 7F0B5894 00A0B025 */  move  $s6, $a1
/* 0EA3C8 7F0B5898 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0EA3CC 7F0B589C AFB40038 */  sw    $s4, 0x38($sp)
/* 0EA3D0 7F0B58A0 AFB30034 */  sw    $s3, 0x34($sp)
/* 0EA3D4 7F0B58A4 AFB20030 */  sw    $s2, 0x30($sp)
/* 0EA3D8 7F0B58A8 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0EA3DC 7F0B58AC F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0EA3E0 7F0B58B0 0700000B */  bltz  $t8, .L7F0B58E0
/* 0EA3E4 7F0B58B4 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0EA3E8 7F0B58B8 C6A40004 */  lwc1  $f4, 4($s5)
/* 0EA3EC 7F0B58BC E4A40000 */  swc1  $f4, ($a1)
/* 0EA3F0 7F0B58C0 C6A60008 */  lwc1  $f6, 8($s5)
/* 0EA3F4 7F0B58C4 E4A60004 */  swc1  $f6, 4($a1)
/* 0EA3F8 7F0B58C8 C6A8000C */  lwc1  $f8, 0xc($s5)
/* 0EA3FC 7F0B58CC E4A80008 */  swc1  $f8, 8($a1)
/* 0EA400 7F0B58D0 C6AA0010 */  lwc1  $f10, 0x10($s5)
/* 0EA404 7F0B58D4 E4AA000C */  swc1  $f10, 0xc($a1)
/* 0EA408 7F0B58D8 10000082 */  b     .L7F0B5AE4
/* 0EA40C 7F0B58DC 8EA20000 */   lw    $v0, ($s5)
.L7F0B58E0:
/* 0EA410 7F0B58E0 0FC2E664 */  jal   sub_GAME_7F0B9990
/* 0EA414 7F0B58E4 02002025 */   move  $a0, $s0
/* 0EA418 7F0B58E8 27B10080 */  addiu $s1, $sp, 0x80
/* 0EA41C 7F0B58EC 44050000 */  mfc1  $a1, $f0
/* 0EA420 7F0B58F0 46000586 */  mov.s $f22, $f0
/* 0EA424 7F0B58F4 02203025 */  move  $a2, $s1
/* 0EA428 7F0B58F8 0FC2D54A */  jal   sub_GAME_7F0B5528
/* 0EA42C 7F0B58FC 02002025 */   move  $a0, $s0
/* 0EA430 7F0B5900 4480A000 */  mtc1  $zero, $f20
/* 0EA434 7F0B5904 0002C880 */  sll   $t9, $v0, 2
/* 0EA438 7F0B5908 00409825 */  move  $s3, $v0
/* 0EA43C 7F0B590C 4616A03C */  c.lt.s $f20, $f22
/* 0EA440 7F0B5910 0322C823 */  subu  $t9, $t9, $v0
/* 0EA444 7F0B5914 02002025 */  move  $a0, $s0
/* 0EA448 7F0B5918 45020008 */  bc1fl .L7F0B593C
/* 0EA44C 7F0B591C 00009025 */   move  $s2, $zero
/* 0EA450 7F0B5920 4600B107 */  neg.s $f4, $f22
/* 0EA454 7F0B5924 0019C880 */  sll   $t9, $t9, 2
/* 0EA458 7F0B5928 44052000 */  mfc1  $a1, $f4
/* 0EA45C 7F0B592C 0FC2D54A */  jal   sub_GAME_7F0B5528
/* 0EA460 7F0B5930 02393021 */   addu  $a2, $s1, $t9
/* 0EA464 7F0B5934 02629821 */  addu  $s3, $s3, $v0
/* 0EA468 7F0B5938 00009025 */  move  $s2, $zero
.L7F0B593C:
/* 0EA46C 7F0B593C 1A600039 */  blez  $s3, .L7F0B5A24
/* 0EA470 7F0B5940 00008825 */   move  $s1, $zero
/* 0EA474 7F0B5944 27B00080 */  addiu $s0, $sp, 0x80
/* 0EA478 7F0B5948 27B40078 */  addiu $s4, $sp, 0x78
.L7F0B594C:
/* 0EA47C 7F0B594C C6060008 */  lwc1  $f6, 8($s0)
/* 0EA480 7F0B5950 C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0EA484 7F0B5954 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0EA488 7F0B5958 4614303E */  c.le.s $f6, $f20
/* 0EA48C 7F0B595C C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0EA490 7F0B5960 C7B60068 */  lwc1  $f22, 0x68($sp)
/* 0EA494 7F0B5964 02002025 */  move  $a0, $s0
/* 0EA498 7F0B5968 45020024 */  bc1fl .L7F0B59FC
/* 0EA49C 7F0B596C 26310001 */   addiu $s1, $s1, 1
/* 0EA4A0 7F0B5970 0FC1E018 */  jal   transform3Dto2DWithZScaling
/* 0EA4A4 7F0B5974 02802825 */   move  $a1, $s4
/* 0EA4A8 7F0B5978 16400006 */  bnez  $s2, .L7F0B5994
/* 0EA4AC 7F0B597C C7A20078 */   lwc1  $f2, 0x78($sp)
/* 0EA4B0 7F0B5980 C7B60078 */  lwc1  $f22, 0x78($sp)
/* 0EA4B4 7F0B5984 C7B0007C */  lwc1  $f16, 0x7c($sp)
/* 0EA4B8 7F0B5988 4600B486 */  mov.s $f18, $f22
/* 0EA4BC 7F0B598C 10000019 */  b     .L7F0B59F4
/* 0EA4C0 7F0B5990 46008386 */   mov.s $f14, $f16
.L7F0B5994:
/* 0EA4C4 7F0B5994 C7B60068 */  lwc1  $f22, 0x68($sp)
/* 0EA4C8 7F0B5998 C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0EA4CC 7F0B599C C7AC007C */  lwc1  $f12, 0x7c($sp)
/* 0EA4D0 7F0B59A0 4616103C */  c.lt.s $f2, $f22
/* 0EA4D4 7F0B59A4 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0EA4D8 7F0B59A8 C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0EA4DC 7F0B59AC 45020003 */  bc1fl .L7F0B59BC
/* 0EA4E0 7F0B59B0 4602903C */   c.lt.s $f18, $f2
/* 0EA4E4 7F0B59B4 46001586 */  mov.s $f22, $f2
/* 0EA4E8 7F0B59B8 4602903C */  c.lt.s $f18, $f2
.L7F0B59BC:
/* 0EA4EC 7F0B59BC 00000000 */  nop
/* 0EA4F0 7F0B59C0 45020003 */  bc1fl .L7F0B59D0
/* 0EA4F4 7F0B59C4 4610603C */   c.lt.s $f12, $f16
/* 0EA4F8 7F0B59C8 46001486 */  mov.s $f18, $f2
/* 0EA4FC 7F0B59CC 4610603C */  c.lt.s $f12, $f16
.L7F0B59D0:
/* 0EA500 7F0B59D0 00000000 */  nop
/* 0EA504 7F0B59D4 45020003 */  bc1fl .L7F0B59E4
/* 0EA508 7F0B59D8 460C703C */   c.lt.s $f14, $f12
/* 0EA50C 7F0B59DC 46006406 */  mov.s $f16, $f12
/* 0EA510 7F0B59E0 460C703C */  c.lt.s $f14, $f12
.L7F0B59E4:
/* 0EA514 7F0B59E4 00000000 */  nop
/* 0EA518 7F0B59E8 45020003 */  bc1fl .L7F0B59F8
/* 0EA51C 7F0B59EC 26520001 */   addiu $s2, $s2, 1
/* 0EA520 7F0B59F0 46006386 */  mov.s $f14, $f12
.L7F0B59F4:
/* 0EA524 7F0B59F4 26520001 */  addiu $s2, $s2, 1
.L7F0B59F8:
/* 0EA528 7F0B59F8 26310001 */  addiu $s1, $s1, 1
.L7F0B59FC:
/* 0EA52C 7F0B59FC 2610000C */  addiu $s0, $s0, 0xc
/* 0EA530 7F0B5A00 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0EA534 7F0B5A04 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0EA538 7F0B5A08 E7B20070 */  swc1  $f18, 0x70($sp)
/* 0EA53C 7F0B5A0C 1633FFCF */  bne   $s1, $s3, .L7F0B594C
/* 0EA540 7F0B5A10 E7B60068 */   swc1  $f22, 0x68($sp)
/* 0EA544 7F0B5A14 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0EA548 7F0B5A18 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0EA54C 7F0B5A1C E7B20070 */  swc1  $f18, 0x70($sp)
/* 0EA550 7F0B5A20 E7B60068 */  swc1  $f22, 0x68($sp)
.L7F0B5A24:
/* 0EA554 7F0B5A24 C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0EA558 7F0B5A28 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0EA55C 7F0B5A2C C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0EA560 7F0B5A30 16400006 */  bnez  $s2, .L7F0B5A4C
/* 0EA564 7F0B5A34 C7B60068 */   lwc1  $f22, 0x68($sp)
/* 0EA568 7F0B5A38 E7B40074 */  swc1  $f20, 0x74($sp)
/* 0EA56C 7F0B5A3C E7B4006C */  swc1  $f20, 0x6c($sp)
/* 0EA570 7F0B5A40 E7B40070 */  swc1  $f20, 0x70($sp)
/* 0EA574 7F0B5A44 10000015 */  b     .L7F0B5A9C
/* 0EA578 7F0B5A48 E7B40068 */   swc1  $f20, 0x68($sp)
.L7F0B5A4C:
/* 0EA57C 7F0B5A4C 4616903E */  c.le.s $f18, $f22
/* 0EA580 7F0B5A50 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0EA584 7F0B5A54 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0EA588 7F0B5A58 E7B20070 */  swc1  $f18, 0x70($sp)
/* 0EA58C 7F0B5A5C 45010005 */  bc1t  .L7F0B5A74
/* 0EA590 7F0B5A60 E7B60068 */   swc1  $f22, 0x68($sp)
/* 0EA594 7F0B5A64 4610703E */  c.le.s $f14, $f16
/* 0EA598 7F0B5A68 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0EA59C 7F0B5A6C E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0EA5A0 7F0B5A70 4500000A */  bc1f  .L7F0B5A9C
.L7F0B5A74:
/* 0EA5A4 7F0B5A74 3C028008 */   lui   $v0, %hi(g_CurrentPlayer)
/* 0EA5A8 7F0B5A78 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0EA5AC 7F0B5A7C C4481118 */  lwc1  $f8, 0x1118($v0)
/* 0EA5B0 7F0B5A80 E7A80068 */  swc1  $f8, 0x68($sp)
/* 0EA5B4 7F0B5A84 C44A111C */  lwc1  $f10, 0x111c($v0)
/* 0EA5B8 7F0B5A88 E7AA006C */  swc1  $f10, 0x6c($sp)
/* 0EA5BC 7F0B5A8C C4441120 */  lwc1  $f4, 0x1120($v0)
/* 0EA5C0 7F0B5A90 E7A40070 */  swc1  $f4, 0x70($sp)
/* 0EA5C4 7F0B5A94 C4461124 */  lwc1  $f6, 0x1124($v0)
/* 0EA5C8 7F0B5A98 E7A60074 */  swc1  $f6, 0x74($sp)
.L7F0B5A9C:
/* 0EA5CC 7F0B5A9C C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0EA5D0 7F0B5AA0 02401025 */  move  $v0, $s2
/* 0EA5D4 7F0B5AA4 E6C80000 */  swc1  $f8, ($s6)
/* 0EA5D8 7F0B5AA8 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0EA5DC 7F0B5AAC C6C80000 */  lwc1  $f8, ($s6)
/* 0EA5E0 7F0B5AB0 E6CA0004 */  swc1  $f10, 4($s6)
/* 0EA5E4 7F0B5AB4 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0EA5E8 7F0B5AB8 E6C40008 */  swc1  $f4, 8($s6)
/* 0EA5EC 7F0B5ABC C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0EA5F0 7F0B5AC0 E6C6000C */  swc1  $f6, 0xc($s6)
/* 0EA5F4 7F0B5AC4 E6A80004 */  swc1  $f8, 4($s5)
/* 0EA5F8 7F0B5AC8 C6CA0004 */  lwc1  $f10, 4($s6)
/* 0EA5FC 7F0B5ACC E6AA0008 */  swc1  $f10, 8($s5)
/* 0EA600 7F0B5AD0 C6C40008 */  lwc1  $f4, 8($s6)
/* 0EA604 7F0B5AD4 E6A4000C */  swc1  $f4, 0xc($s5)
/* 0EA608 7F0B5AD8 C6C6000C */  lwc1  $f6, 0xc($s6)
/* 0EA60C 7F0B5ADC AEB20000 */  sw    $s2, ($s5)
/* 0EA610 7F0B5AE0 E6A60010 */  swc1  $f6, 0x10($s5)
.L7F0B5AE4:
/* 0EA614 7F0B5AE4 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0EA618 7F0B5AE8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0EA61C 7F0B5AEC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0EA620 7F0B5AF0 8FB00028 */  lw    $s0, 0x28($sp)
/* 0EA624 7F0B5AF4 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0EA628 7F0B5AF8 8FB20030 */  lw    $s2, 0x30($sp)
/* 0EA62C 7F0B5AFC 8FB30034 */  lw    $s3, 0x34($sp)
/* 0EA630 7F0B5B00 8FB40038 */  lw    $s4, 0x38($sp)
/* 0EA634 7F0B5B04 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0EA638 7F0B5B08 8FB60040 */  lw    $s6, 0x40($sp)
/* 0EA63C 7F0B5B0C 03E00008 */  jr    $ra
/* 0EA640 7F0B5B10 27BD0170 */   addiu $sp, $sp, 0x170
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B5864
/* 0E7590 7F0B4BA0 27BDFE90 */  addiu $sp, $sp, -0x170
/* 0E7594 7F0B4BA4 00047080 */  sll   $t6, $a0, 2
/* 0E7598 7F0B4BA8 01C47021 */  addu  $t6, $t6, $a0
/* 0E759C 7F0B4BAC 3C0F8007 */  lui   $t7, %hi(table_for_portals) # $t7, 0x8007
/* 0E75A0 7F0B4BB0 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0E75A4 7F0B4BB4 25EFBFC0 */  addiu $t7, %lo(table_for_portals) # addiu $t7, $t7, -0x4040
/* 0E75A8 7F0B4BB8 000E7080 */  sll   $t6, $t6, 2
/* 0E75AC 7F0B4BBC 01CFA821 */  addu  $s5, $t6, $t7
/* 0E75B0 7F0B4BC0 8EB80000 */  lw    $t8, ($s5)
/* 0E75B4 7F0B4BC4 AFB60040 */  sw    $s6, 0x40($sp)
/* 0E75B8 7F0B4BC8 AFB00028 */  sw    $s0, 0x28($sp)
/* 0E75BC 7F0B4BCC 00808025 */  move  $s0, $a0
/* 0E75C0 7F0B4BD0 00A0B025 */  move  $s6, $a1
/* 0E75C4 7F0B4BD4 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0E75C8 7F0B4BD8 AFB40038 */  sw    $s4, 0x38($sp)
/* 0E75CC 7F0B4BDC AFB30034 */  sw    $s3, 0x34($sp)
/* 0E75D0 7F0B4BE0 AFB20030 */  sw    $s2, 0x30($sp)
/* 0E75D4 7F0B4BE4 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0E75D8 7F0B4BE8 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0E75DC 7F0B4BEC 0700000B */  bltz  $t8, .Leu7F0B4C1C
/* 0E75E0 7F0B4BF0 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0E75E4 7F0B4BF4 C6A40004 */  lwc1  $f4, 4($s5)
/* 0E75E8 7F0B4BF8 E4A40000 */  swc1  $f4, ($a1)
/* 0E75EC 7F0B4BFC C6A60008 */  lwc1  $f6, 8($s5)
/* 0E75F0 7F0B4C00 E4A60004 */  swc1  $f6, 4($a1)
/* 0E75F4 7F0B4C04 C6A8000C */  lwc1  $f8, 0xc($s5)
/* 0E75F8 7F0B4C08 E4A80008 */  swc1  $f8, 8($a1)
/* 0E75FC 7F0B4C0C C6AA0010 */  lwc1  $f10, 0x10($s5)
/* 0E7600 7F0B4C10 E4AA000C */  swc1  $f10, 0xc($a1)
/* 0E7604 7F0B4C14 10000082 */  b     .L7F0B4E20
/* 0E7608 7F0B4C18 8EA20000 */   lw    $v0, ($s5)
.Leu7F0B4C1C:
/* 0E760C 7F0B4C1C 0FC2E30B */  jal   sub_GAME_7F0B9990
/* 0E7610 7F0B4C20 02002025 */   move  $a0, $s0
/* 0E7614 7F0B4C24 27B10080 */  addiu $s1, $sp, 0x80
/* 0E7618 7F0B4C28 44050000 */  mfc1  $a1, $f0
/* 0E761C 7F0B4C2C 46000586 */  mov.s $f22, $f0
/* 0E7620 7F0B4C30 02203025 */  move  $a2, $s1
/* 0E7624 7F0B4C34 0FC2D219 */  jal   sub_GAME_7F0B5528
/* 0E7628 7F0B4C38 02002025 */   move  $a0, $s0
/* 0E762C 7F0B4C3C 4480A000 */  mtc1  $zero, $f20
/* 0E7630 7F0B4C40 0002C880 */  sll   $t9, $v0, 2
/* 0E7634 7F0B4C44 00409825 */  move  $s3, $v0
/* 0E7638 7F0B4C48 4616A03C */  c.lt.s $f20, $f22
/* 0E763C 7F0B4C4C 0322C823 */  subu  $t9, $t9, $v0
/* 0E7640 7F0B4C50 02002025 */  move  $a0, $s0
/* 0E7644 7F0B4C54 45020008 */  bc1fl .L7F0B4C78
/* 0E7648 7F0B4C58 00009025 */   move  $s2, $zero
/* 0E764C 7F0B4C5C 4600B107 */  neg.s $f4, $f22
/* 0E7650 7F0B4C60 0019C880 */  sll   $t9, $t9, 2
/* 0E7654 7F0B4C64 44052000 */  mfc1  $a1, $f4
/* 0E7658 7F0B4C68 0FC2D219 */  jal   sub_GAME_7F0B5528
/* 0E765C 7F0B4C6C 02393021 */   addu  $a2, $s1, $t9
/* 0E7660 7F0B4C70 02629821 */  addu  $s3, $s3, $v0
/* 0E7664 7F0B4C74 00009025 */  move  $s2, $zero
.L7F0B4C78:
/* 0E7668 7F0B4C78 1A600039 */  blez  $s3, .L7F0B4D60
/* 0E766C 7F0B4C7C 00008825 */   move  $s1, $zero
/* 0E7670 7F0B4C80 27B00080 */  addiu $s0, $sp, 0x80
/* 0E7674 7F0B4C84 27B40078 */  addiu $s4, $sp, 0x78
.L7F0B4C88:
/* 0E7678 7F0B4C88 C6060008 */  lwc1  $f6, 8($s0)
/* 0E767C 7F0B4C8C C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0E7680 7F0B4C90 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0E7684 7F0B4C94 4614303E */  c.le.s $f6, $f20
/* 0E7688 7F0B4C98 C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0E768C 7F0B4C9C C7B60068 */  lwc1  $f22, 0x68($sp)
/* 0E7690 7F0B4CA0 02002025 */  move  $a0, $s0
/* 0E7694 7F0B4CA4 45020024 */  bc1fl .L7F0B4D38
/* 0E7698 7F0B4CA8 26310001 */   addiu $s1, $s1, 1
/* 0E769C 7F0B4CAC 0FC1E038 */  jal   transform3Dto2DWithZScaling
/* 0E76A0 7F0B4CB0 02802825 */   move  $a1, $s4
/* 0E76A4 7F0B4CB4 16400006 */  bnez  $s2, .L7F0B4CD0
/* 0E76A8 7F0B4CB8 C7A20078 */   lwc1  $f2, 0x78($sp)
/* 0E76AC 7F0B4CBC C7B60078 */  lwc1  $f22, 0x78($sp)
/* 0E76B0 7F0B4CC0 C7B0007C */  lwc1  $f16, 0x7c($sp)
/* 0E76B4 7F0B4CC4 4600B486 */  mov.s $f18, $f22
/* 0E76B8 7F0B4CC8 10000019 */  b     .Leu7F0B4D30
/* 0E76BC 7F0B4CCC 46008386 */   mov.s $f14, $f16
.L7F0B4CD0:
/* 0E76C0 7F0B4CD0 C7B60068 */  lwc1  $f22, 0x68($sp)
/* 0E76C4 7F0B4CD4 C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0E76C8 7F0B4CD8 C7AC007C */  lwc1  $f12, 0x7c($sp)
/* 0E76CC 7F0B4CDC 4616103C */  c.lt.s $f2, $f22
/* 0E76D0 7F0B4CE0 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0E76D4 7F0B4CE4 C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0E76D8 7F0B4CE8 45020003 */  bc1fl .L7F0B4CF8
/* 0E76DC 7F0B4CEC 4602903C */   c.lt.s $f18, $f2
/* 0E76E0 7F0B4CF0 46001586 */  mov.s $f22, $f2
/* 0E76E4 7F0B4CF4 4602903C */  c.lt.s $f18, $f2
.L7F0B4CF8:
/* 0E76E8 7F0B4CF8 00000000 */  nop
/* 0E76EC 7F0B4CFC 45020003 */  bc1fl .L7F0B4D0C
/* 0E76F0 7F0B4D00 4610603C */   c.lt.s $f12, $f16
/* 0E76F4 7F0B4D04 46001486 */  mov.s $f18, $f2
/* 0E76F8 7F0B4D08 4610603C */  c.lt.s $f12, $f16
.L7F0B4D0C:
/* 0E76FC 7F0B4D0C 00000000 */  nop
/* 0E7700 7F0B4D10 45020003 */  bc1fl .L7F0B4D20
/* 0E7704 7F0B4D14 460C703C */   c.lt.s $f14, $f12
/* 0E7708 7F0B4D18 46006406 */  mov.s $f16, $f12
/* 0E770C 7F0B4D1C 460C703C */  c.lt.s $f14, $f12
.L7F0B4D20:
/* 0E7710 7F0B4D20 00000000 */  nop
/* 0E7714 7F0B4D24 45020003 */  bc1fl .L7F0B4D34
/* 0E7718 7F0B4D28 26520001 */   addiu $s2, $s2, 1
/* 0E771C 7F0B4D2C 46006386 */  mov.s $f14, $f12
.Leu7F0B4D30:
/* 0E7720 7F0B4D30 26520001 */  addiu $s2, $s2, 1
.L7F0B4D34:
/* 0E7724 7F0B4D34 26310001 */  addiu $s1, $s1, 1
.L7F0B4D38:
/* 0E7728 7F0B4D38 2610000C */  addiu $s0, $s0, 0xc
/* 0E772C 7F0B4D3C E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0E7730 7F0B4D40 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0E7734 7F0B4D44 E7B20070 */  swc1  $f18, 0x70($sp)
/* 0E7738 7F0B4D48 1633FFCF */  bne   $s1, $s3, .L7F0B4C88
/* 0E773C 7F0B4D4C E7B60068 */   swc1  $f22, 0x68($sp)
/* 0E7740 7F0B4D50 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0E7744 7F0B4D54 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0E7748 7F0B4D58 E7B20070 */  swc1  $f18, 0x70($sp)
/* 0E774C 7F0B4D5C E7B60068 */  swc1  $f22, 0x68($sp)
.L7F0B4D60:
/* 0E7750 7F0B4D60 C7AE0074 */  lwc1  $f14, 0x74($sp)
/* 0E7754 7F0B4D64 C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 0E7758 7F0B4D68 C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0E775C 7F0B4D6C 16400006 */  bnez  $s2, .L7F0B4D88
/* 0E7760 7F0B4D70 C7B60068 */   lwc1  $f22, 0x68($sp)
/* 0E7764 7F0B4D74 E7B40074 */  swc1  $f20, 0x74($sp)
/* 0E7768 7F0B4D78 E7B4006C */  swc1  $f20, 0x6c($sp)
/* 0E776C 7F0B4D7C E7B40070 */  swc1  $f20, 0x70($sp)
/* 0E7770 7F0B4D80 10000015 */  b     .Leu7F0B4DD8
/* 0E7774 7F0B4D84 E7B40068 */   swc1  $f20, 0x68($sp)
.L7F0B4D88:
/* 0E7778 7F0B4D88 4616903E */  c.le.s $f18, $f22
/* 0E777C 7F0B4D8C E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0E7780 7F0B4D90 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0E7784 7F0B4D94 E7B20070 */  swc1  $f18, 0x70($sp)
/* 0E7788 7F0B4D98 45010005 */  bc1t  .L7F0B4DB0
/* 0E778C 7F0B4D9C E7B60068 */   swc1  $f22, 0x68($sp)
/* 0E7790 7F0B4DA0 4610703E */  c.le.s $f14, $f16
/* 0E7794 7F0B4DA4 E7AE0074 */  swc1  $f14, 0x74($sp)
/* 0E7798 7F0B4DA8 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0E779C 7F0B4DAC 4500000A */  bc1f  .Leu7F0B4DD8
.L7F0B4DB0:
/* 0E77A0 7F0B4DB0 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0E77A4 7F0B4DB4 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0E77A8 7F0B4DB8 C4481110 */  lwc1  $f8, 0x1110($v0)
/* 0E77AC 7F0B4DBC E7A80068 */  swc1  $f8, 0x68($sp)
/* 0E77B0 7F0B4DC0 C44A1114 */  lwc1  $f10, 0x1114($v0)
/* 0E77B4 7F0B4DC4 E7AA006C */  swc1  $f10, 0x6c($sp)
/* 0E77B8 7F0B4DC8 C4441118 */  lwc1  $f4, 0x1118($v0)
/* 0E77BC 7F0B4DCC E7A40070 */  swc1  $f4, 0x70($sp)
/* 0E77C0 7F0B4DD0 C446111C */  lwc1  $f6, 0x111c($v0)
/* 0E77C4 7F0B4DD4 E7A60074 */  swc1  $f6, 0x74($sp)
.Leu7F0B4DD8:
/* 0E77C8 7F0B4DD8 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0E77CC 7F0B4DDC 02401025 */  move  $v0, $s2
/* 0E77D0 7F0B4DE0 E6C80000 */  swc1  $f8, ($s6)
/* 0E77D4 7F0B4DE4 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0E77D8 7F0B4DE8 C6C80000 */  lwc1  $f8, ($s6)
/* 0E77DC 7F0B4DEC E6CA0004 */  swc1  $f10, 4($s6)
/* 0E77E0 7F0B4DF0 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0E77E4 7F0B4DF4 E6C40008 */  swc1  $f4, 8($s6)
/* 0E77E8 7F0B4DF8 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0E77EC 7F0B4DFC E6C6000C */  swc1  $f6, 0xc($s6)
/* 0E77F0 7F0B4E00 E6A80004 */  swc1  $f8, 4($s5)
/* 0E77F4 7F0B4E04 C6CA0004 */  lwc1  $f10, 4($s6)
/* 0E77F8 7F0B4E08 E6AA0008 */  swc1  $f10, 8($s5)
/* 0E77FC 7F0B4E0C C6C40008 */  lwc1  $f4, 8($s6)
/* 0E7800 7F0B4E10 E6A4000C */  swc1  $f4, 0xc($s5)
/* 0E7804 7F0B4E14 C6C6000C */  lwc1  $f6, 0xc($s6)
/* 0E7808 7F0B4E18 AEB20000 */  sw    $s2, ($s5)
/* 0E780C 7F0B4E1C E6A60010 */  swc1  $f6, 0x10($s5)
.L7F0B4E20:
/* 0E7810 7F0B4E20 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0E7814 7F0B4E24 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0E7818 7F0B4E28 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0E781C 7F0B4E2C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0E7820 7F0B4E30 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0E7824 7F0B4E34 8FB20030 */  lw    $s2, 0x30($sp)
/* 0E7828 7F0B4E38 8FB30034 */  lw    $s3, 0x34($sp)
/* 0E782C 7F0B4E3C 8FB40038 */  lw    $s4, 0x38($sp)
/* 0E7830 7F0B4E40 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0E7834 7F0B4E44 8FB60040 */  lw    $s6, 0x40($sp)
/* 0E7838 7F0B4E48 03E00008 */  jr    $ra
/* 0E783C 7F0B4E4C 27BD0170 */   addiu $sp, $sp, 0x170
)
#endif
#endif





/**
 * Unreferenced.
 *
 * Address 0x7F0B5B14.
 */
Gfx *bgFillRectangle(Gfx *gdl, s32 ulx, s32 uly, s32 lrx, s32 lry)
{
    gDPFillRectangle(gdl++, ulx, uly, lrx + 1, lry + 1);
    return gdl;
}





/**
 * Unreferenced.
 */
void bgFillRectangleWithSides(Gfx *gdl, s32 ulx, s32 uly, s32 lrx, s32 lry)
{
    bgFillRectangle(
        bgFillRectangle(
            bgFillRectangle(
                bgFillRectangle(gdl,
                ulx, uly, lrx, uly), /* full rectangle */
                lrx, uly, lrx, lry), /* right side */
                ulx, lry, lrx, lry), /* bottom */
                ulx, uly, ulx, lry); /* top */
}



/**
 * Determines if two rectangles overlap, adjusting first argument to be the intersection.
 *
 * Returns 0 if no intersection (or edge equality), 1 otherwise.
 *
 * Address 0x7F0B5BDC.
 */
s32 bgRectIntersect(struct bbox2d *a, struct bbox2d *b)
{
	a->min.x = a->min.x > b->min.x ? a->min.x : b->min.x;
	a->min.y = a->min.y > b->min.y ? a->min.y : b->min.y;
	a->max.x = b->max.x > a->max.x ? a->max.x : b->max.x;
	a->max.y = b->max.y > a->max.y ? a->max.y : b->max.y;

	if (a->min.x >= a->max.x) {
		a->min.x = a->max.x;
		return FALSE;
	}

	if (a->max.y <= a->min.y) {
		a->min.y = a->max.y;
		return FALSE;
	}

	return TRUE;
}






void sub_GAME_7F0B5CC0(struct bbox2d *a, struct bbox2d *b)
{
    (a->min).x = ((a->min).x < (b->min).x) ? (a->min).x : (b->min).x;
    (a->min).y = ((a->min).y < (b->min).y) ? (a->min).y : (b->min).y;
    (a->max).x = ((a->max).x > (b->max).x) ? (a->max).x : (b->max).x;
    (a->max).y = ((a->max).y > (b->max).y) ? (a->max).y : (b->max).y;
}

void bbox2dCopy(struct bbox2d *a, struct bbox2d *b)
{
    (a->min).x = (b->min).x;
    (a->min).y = (b->min).y;
    (a->max).x = (b->max).x;
    (a->max).y = (b->max).y;
}





#ifdef NONMATCHING
char *bgDebPrintPORTALID(s32 portID)
{
    s32 temp_hi = (bgDebPortalOutLineNum + 1) % 0xA;

    bgDebPortalOutLineNum = temp_hi;
    sprintf(&bgDebPortalOutBuffer[temp_hi], "PORT%d", portID);
    return &bgDebPortalOutBuffer[temp_hi];
}
#else
GLOBAL_ASM(
.rdata
/*D:80058C48*/
glabel aPortD
/*"PORT%d"*/
.word 0x504F5254, 0x25640000



.text
glabel bgDebPrintPORTALID
/* 0EA8AC 7F0B5D7C 3C028004 */  lui   $v0, %hi(bgDebPortalOutLineNum)
/* 0EA8B0 7F0B5D80 8C424860 */  lw    $v0, %lo(bgDebPortalOutLineNum)($v0)
/* 0EA8B4 7F0B5D84 2401000A */  li    $at, 10
/* 0EA8B8 7F0B5D88 3C188008 */  lui   $t8, %hi(bgDebPortalOutBuffer)
/* 0EA8BC 7F0B5D8C 24420001 */  addiu $v0, $v0, 1
/* 0EA8C0 7F0B5D90 0041001A */  div   $zero, $v0, $at
/* 0EA8C4 7F0B5D94 00007010 */  mfhi  $t6
/* 0EA8C8 7F0B5D98 000E78C0 */  sll   $t7, $t6, 3
/* 0EA8CC 7F0B5D9C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA8D0 7F0B5DA0 00803025 */  move  $a2, $a0
/* 0EA8D4 7F0B5DA4 01EE7821 */  addu  $t7, $t7, $t6
/* 0EA8D8 7F0B5DA8 2718C040 */  addiu $t8, %lo(bgDebPortalOutBuffer) # addiu $t8, $t8, -0x3fc0
/* 0EA8DC 7F0B5DAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EA8E0 7F0B5DB0 01F82021 */  addu  $a0, $t7, $t8
/* 0EA8E4 7F0B5DB4 3C018004 */  lui   $at, %hi(bgDebPortalOutLineNum)
/* 0EA8E8 7F0B5DB8 3C058006 */  lui   $a1, %hi(aPortD)
/* 0EA8EC 7F0B5DBC AFA4001C */  sw    $a0, 0x1c($sp)
/* 0EA8F0 7F0B5DC0 24A58C48 */  addiu $a1, %lo(aPortD) # addiu $a1, $a1, -0x73b8
/* 0EA8F4 7F0B5DC4 0C002B25 */  jal   sprintf
/* 0EA8F8 7F0B5DC8 AC2E4860 */   sw    $t6, %lo(bgDebPortalOutLineNum)($at)
/* 0EA8FC 7F0B5DCC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EA900 7F0B5DD0 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0EA904 7F0B5DD4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0EA908 7F0B5DD8 03E00008 */  jr    $ra
/* 0EA90C 7F0B5DDC 00000000 */   nop
)
#endif





#ifdef NONMATCHING
char *bgDebPrintROOMID(s32 roomID)
{
    s32 temp_hi = (bgDebRoomOutLineNum + 1) % 0xA;

    bgDebRoomOutLineNum = temp_hi;
    sprintf(&bgDebRoomOutBuffer[temp_hi], "ROOM%d", roomID);
    return &bgDebRoomOutBuffer[temp_hi];
}
#else
GLOBAL_ASM(
.rdata
/*D:80058C50*/
glabel aRoomD
/*"ROOM%d"*/
.word 0x524F4F4D, 0x25640000

.text
glabel bgDebPrintROOMID
/* 0EA910 7F0B5DE0 3C028004 */  lui   $v0, %hi(bgDebRoomOutLineNum)
/* 0EA914 7F0B5DE4 8C424864 */  lw    $v0, %lo(bgDebRoomOutLineNum)($v0)
/* 0EA918 7F0B5DE8 2401000A */  li    $at, 10
/* 0EA91C 7F0B5DEC 3C188008 */  lui   $t8, %hi(bgDebRoomOutBuffer)
/* 0EA920 7F0B5DF0 24420001 */  addiu $v0, $v0, 1
/* 0EA924 7F0B5DF4 0041001A */  div   $zero, $v0, $at
/* 0EA928 7F0B5DF8 00007010 */  mfhi  $t6
/* 0EA92C 7F0B5DFC 000E78C0 */  sll   $t7, $t6, 3
/* 0EA930 7F0B5E00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA934 7F0B5E04 00803025 */  move  $a2, $a0
/* 0EA938 7F0B5E08 01EE7821 */  addu  $t7, $t7, $t6
/* 0EA93C 7F0B5E0C 2718C0A0 */  addiu $t8, %lo(bgDebRoomOutBuffer) # addiu $t8, $t8, -0x3f60
/* 0EA940 7F0B5E10 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EA944 7F0B5E14 01F82021 */  addu  $a0, $t7, $t8
/* 0EA948 7F0B5E18 3C018004 */  lui   $at, %hi(bgDebRoomOutLineNum)
/* 0EA94C 7F0B5E1C 3C058006 */  lui   $a1, %hi(aRoomD)
/* 0EA950 7F0B5E20 AFA4001C */  sw    $a0, 0x1c($sp)
/* 0EA954 7F0B5E24 24A58C50 */  addiu $a1, %lo(aRoomD) # addiu $a1, $a1, -0x73b0
/* 0EA958 7F0B5E28 0C002B25 */  jal   sprintf
/* 0EA95C 7F0B5E2C AC2E4864 */   sw    $t6, %lo(bgDebRoomOutLineNum)($at)
/* 0EA960 7F0B5E30 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EA964 7F0B5E34 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0EA968 7F0B5E38 27BD0020 */  addiu $sp, $sp, 0x20
/* 0EA96C 7F0B5E3C 03E00008 */  jr    $ra
/* 0EA970 7F0B5E40 00000000 */   nop
)
#endif






s32 getMaxNumRooms(void) {
    return g_MaxNumRooms;
}

/*
 * Return butflags0 (confirmed u8)
 */
u8 getROOMID_isRendered(s32 roomID)
{
    return g_BgRoomInfo[roomID].room_rendered;
}

/*
 * Return butflags1 (confirmed u8)
 */
u8 getROOMID_isNeighborToRendered(s32 roomID)
{
    return g_BgRoomInfo[roomID].room_neighbor_to_rendered;
}


s32 getIndexOfPORTALID(s32 portalID)
{
    s32 i;

    for(i = 0; g_BgPortals[i].offset_portal != NULL; i++)
    {
        if (portalID == (s32)g_BgPortals[i].offset_portal)
        {
            return i;
        }
    }
    #ifdef DEBUG
    osSyncPrintf("bg: bgPortalIndexFromPtr(): No portal found for %08x ",portalID);
    #endif
    return 0;
}




#ifdef NONMATCHING

void roomsHandleStateDebugging(void) {
    ? sp29;
    ? temp_ret;
    void *phi_v1;
    s32 phi_a0;
    void *phi_v0;
    s32 phi_a0_2;
    s32 phi_a0_3;

    // Node 0
    temp_ret = debugIsRoomStateDebugEnabled();
    if (temp_ret != 0)
    {
        // Node 1
        phi_a0_3 = 1;
        if (g_MaxNumRooms >= 2)
        {
            // Node 2
            phi_v1 = &g_BgRoomInfo + 0x10 +0x40;
            phi_a0 = 1;
            phi_v0 = &sp29;
loop_3:
            // Node 3
            if (phi_v1->unk2 != 0)
            {
                // Node 4
                *phi_v0 = (s8) (((s32) phi_a0 % 0xa) + 0x30);
                phi_a0_2 = (phi_a0 + 1);
            }
            else
            {
                // Node 5
                *phi_v0 = (u8)0x2e;
                phi_a0_2 = (phi_a0 + 1);
            }
            // Node 6
            phi_v1 = (phi_v1 + 0x50);
            phi_a0 = phi_a0_2;
            phi_v0 = (phi_v0 + 1);
            phi_a0_3 = phi_a0_2;
            if (phi_a0_2 < g_MaxNumRooms)
            {
                goto loop_3;
            }
        }
        // Node 7
        (sp + phi_a0_3)->unk28 = (u8)0;
    }
    // Node 8
    return temp_ret;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel roomsHandleStateDebugging
/* 0EAA08 7F0B5ED8 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0EAA0C 7F0B5EDC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAA10 7F0B5EE0 0FC243F4 */  jal   debugIsRoomStateDebugEnabled
/* 0EAA14 7F0B5EE4 00000000 */   nop
/* 0EAA18 7F0B5EE8 10400024 */  beqz  $v0, .L7F0B5F7C
/* 0EAA1C 7F0B5EEC 3C078004 */   lui   $a3, %hi(g_MaxNumRooms)
/* 0EAA20 7F0B5EF0 8CE742F4 */  lw    $a3, %lo(g_MaxNumRooms)($a3)
/* 0EAA24 7F0B5EF4 3C038004 */  lui   $v1, %hi(g_BgRoomInfo + 0x10 +0x40)
/* 0EAA28 7F0B5EF8 24631464 */  addiu $v1, %lo(g_BgRoomInfo + 0x10 +0x40) # addiu $v1, $v1, 0x1464
/* 0EAA2C 7F0B5EFC 28E10002 */  slti  $at, $a3, 2
/* 0EAA30 7F0B5F00 1420001C */  bnez  $at, .L7F0B5F74
/* 0EAA34 7F0B5F04 24040001 */   li    $a0, 1
/* 0EAA38 7F0B5F08 27A20029 */  addiu $v0, $sp, 0x29
/* 0EAA3C 7F0B5F0C 2406002E */  li    $a2, 46
/* 0EAA40 7F0B5F10 2405000A */  li    $a1, 10
.L7F0B5F14:
/* 0EAA44 7F0B5F14 906E0002 */  lbu   $t6, 2($v1)
/* 0EAA48 7F0B5F18 24630050 */  addiu $v1, $v1, 0x50
/* 0EAA4C 7F0B5F1C 51C00011 */  beql  $t6, $zero, .L7F0B5F64
/* 0EAA50 7F0B5F20 A0460000 */   sb    $a2, ($v0)
/* 0EAA54 7F0B5F24 0085001A */  div   $zero, $a0, $a1
/* 0EAA58 7F0B5F28 00007810 */  mfhi  $t7
/* 0EAA5C 7F0B5F2C 25F80030 */  addiu $t8, $t7, 0x30
/* 0EAA60 7F0B5F30 14A00002 */  bnez  $a1, .L7F0B5F3C
/* 0EAA64 7F0B5F34 00000000 */   nop
/* 0EAA68 7F0B5F38 0007000D */  break 7
.L7F0B5F3C:
/* 0EAA6C 7F0B5F3C 2401FFFF */  li    $at, -1
/* 0EAA70 7F0B5F40 14A10004 */  bne   $a1, $at, .L7F0B5F54
/* 0EAA74 7F0B5F44 3C018000 */   lui   $at, 0x8000
/* 0EAA78 7F0B5F48 14810002 */  bne   $a0, $at, .L7F0B5F54
/* 0EAA7C 7F0B5F4C 00000000 */   nop
/* 0EAA80 7F0B5F50 0006000D */  break 6
.L7F0B5F54:
/* 0EAA84 7F0B5F54 A0580000 */  sb    $t8, ($v0)
/* 0EAA88 7F0B5F58 10000003 */  b     .L7F0B5F68
/* 0EAA8C 7F0B5F5C 24840001 */   addiu $a0, $a0, 1
/* 0EAA90 7F0B5F60 A0460000 */  sb    $a2, ($v0)
.L7F0B5F64:
/* 0EAA94 7F0B5F64 24840001 */  addiu $a0, $a0, 1
.L7F0B5F68:
/* 0EAA98 7F0B5F68 0087082A */  slt   $at, $a0, $a3
/* 0EAA9C 7F0B5F6C 1420FFE9 */  bnez  $at, .L7F0B5F14
/* 0EAAA0 7F0B5F70 24420001 */   addiu $v0, $v0, 1
.L7F0B5F74:
/* 0EAAA4 7F0B5F74 03A4C821 */  addu  $t9, $sp, $a0
/* 0EAAA8 7F0B5F78 A3200028 */  sb    $zero, 0x28($t9)
.L7F0B5F7C:
/* 0EAAAC 7F0B5F7C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EAAB0 7F0B5F80 27BD00C0 */  addiu $sp, $sp, 0xc0
/* 0EAAB4 7F0B5F84 03E00008 */  jr    $ra
/* 0EAAB8 7F0B5F88 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel roomsHandleStateDebugging
/* 0E7C04 7F0B5214 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0E7C08 7F0B5218 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E7C0C 7F0B521C 0FC2411A */  jal   debugIsRoomStateDebugEnabled
/* 0E7C10 7F0B5220 00000000 */   nop
/* 0E7C14 7F0B5224 10400024 */  beqz  $v0, .L7F0B52B8
/* 0E7C18 7F0B5228 3C078004 */   lui   $a3, %hi(g_MaxNumRooms) # $a3, 0x8004
/* 0E7C1C 7F0B522C 8CE7D7D4 */  lw    $a3, %lo(g_MaxNumRooms)($a3)
/* 0E7C20 7F0B5230 3C038004 */  lui   $v1, %hi(g_BgRoomInfo + 0x10 +0x40) # $v1, 0x8004
/* 0E7C24 7F0B5234 2463ACB4 */  addiu $v1, %lo(g_BgRoomInfo + 0x10 +0x40) # addiu $v1, $v1, -0x534c
/* 0E7C28 7F0B5238 28E10002 */  slti  $at, $a3, 2
/* 0E7C2C 7F0B523C 1420001C */  bnez  $at, .L7F0B52B0
/* 0E7C30 7F0B5240 24040001 */   li    $a0, 1
/* 0E7C34 7F0B5244 27A2002D */  addiu $v0, $sp, 0x2d
/* 0E7C38 7F0B5248 2406002E */  li    $a2, 46
/* 0E7C3C 7F0B524C 2405000A */  li    $a1, 10
.L7F0B5250:
/* 0E7C40 7F0B5250 906E0002 */  lbu   $t6, 2($v1)
/* 0E7C44 7F0B5254 24630050 */  addiu $v1, $v1, 0x50
/* 0E7C48 7F0B5258 51C00011 */  beql  $t6, $zero, .Leu7F0B52A0
/* 0E7C4C 7F0B525C A0460000 */   sb    $a2, ($v0)
/* 0E7C50 7F0B5260 0085001A */  div   $zero, $a0, $a1
/* 0E7C54 7F0B5264 00007810 */  mfhi  $t7
/* 0E7C58 7F0B5268 25F80030 */  addiu $t8, $t7, 0x30
/* 0E7C5C 7F0B526C 14A00002 */  bnez  $a1, .L7F0B5278
/* 0E7C60 7F0B5270 00000000 */   nop
/* 0E7C64 7F0B5274 0007000D */  break 7
.L7F0B5278:
/* 0E7C68 7F0B5278 2401FFFF */  li    $at, -1
/* 0E7C6C 7F0B527C 14A10004 */  bne   $a1, $at, .L7F0B5290
/* 0E7C70 7F0B5280 3C018000 */   lui   $at, 0x8000
/* 0E7C74 7F0B5284 14810002 */  bne   $a0, $at, .L7F0B5290
/* 0E7C78 7F0B5288 00000000 */   nop
/* 0E7C7C 7F0B528C 0006000D */  break 6
.L7F0B5290:
/* 0E7C80 7F0B5290 A0580000 */  sb    $t8, ($v0)
/* 0E7C84 7F0B5294 10000003 */  b     .L7F0B52A4
/* 0E7C88 7F0B5298 24840001 */   addiu $a0, $a0, 1
/* 0E7C8C 7F0B529C A0460000 */  sb    $a2, ($v0)
.Leu7F0B52A0:
/* 0E7C90 7F0B52A0 24840001 */  addiu $a0, $a0, 1
.L7F0B52A4:
/* 0E7C94 7F0B52A4 0087082A */  slt   $at, $a0, $a3
/* 0E7C98 7F0B52A8 1420FFE9 */  bnez  $at, .L7F0B5250
/* 0E7C9C 7F0B52AC 24420001 */   addiu $v0, $v0, 1
.L7F0B52B0:
/* 0E7CA0 7F0B52B0 03A4C821 */  addu  $t9, $sp, $a0
/* 0E7CA4 7F0B52B4 A320002C */  sb    $zero, 0x2c($t9)
.L7F0B52B8:
/* 0E7CA8 7F0B52B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E7CAC 7F0B52BC 27BD00B8 */  addiu $sp, $sp, 0xb8
/* 0E7CB0 7F0B52C0 03E00008 */  jr    $ra
/* 0E7CB4 7F0B52C4 00000000 */   nop
)
#endif
#endif




u32 bgDecompress(u8* source, u8 *target)
{
    u8 buffer[0x2100];
    return decompressdata(source, target, buffer);
}





#ifdef NONMATCHING
void* sub_GAME_7F0B5FAC(int roomID, int* data, int size)
{
    void *source;
    void* dest;

    s32 len;



    len = g_BgRoomInfo[roomID].csize_point_index_binary + 0xfU & 0xfffffff0;
    if (size < len + 0x20) {
        dest = -1;
    }
    else {
        source = (size - len) + data;
        obLoadBGFileBytesAtOffset(levelinfotable[levelentry_index].bg_seg_filename, source,
            (ptr_bg_data+ &ptr_bgdata_room_fileposition_list[roomID] - ptr_bg_data) + 0xF1000000, len);
        dest = bgDecompress(source,data);
        g_BgRoomInfo[roomID].usize_point_index_binary = dest;
        g_BgRoomInfo[roomID].ptr_point_index = data;
    }
    return dest;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B5FAC
/* 0EAADC 7F0B5FAC 00047880 */  sll   $t7, $a0, 2
/* 0EAAE0 7F0B5FB0 01E47821 */  addu  $t7, $t7, $a0
/* 0EAAE4 7F0B5FB4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EAAE8 7F0B5FB8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EAAEC 7F0B5FBC 000F7900 */  sll   $t7, $t7, 4
/* 0EAAF0 7F0B5FC0 01F81821 */  addu  $v1, $t7, $t8
/* 0EAAF4 7F0B5FC4 8C670010 */  lw    $a3, 0x10($v1)
/* 0EAAF8 7F0B5FC8 2401FFF0 */  li    $at, -16
/* 0EAAFC 7F0B5FCC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EAB00 7F0B5FD0 24E7000F */  addiu $a3, $a3, 0xf
/* 0EAB04 7F0B5FD4 00E1C824 */  and   $t9, $a3, $at
/* 0EAB08 7F0B5FD8 272A0020 */  addiu $t2, $t9, 0x20
/* 0EAB0C 7F0B5FDC 00CA082A */  slt   $at, $a2, $t2
/* 0EAB10 7F0B5FE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAB14 7F0B5FE4 AFA40030 */  sw    $a0, 0x30($sp)
/* 0EAB18 7F0B5FE8 AFA50034 */  sw    $a1, 0x34($sp)
/* 0EAB1C 7F0B5FEC AFA60038 */  sw    $a2, 0x38($sp)
/* 0EAB20 7F0B5FF0 10200003 */  beqz  $at, .L7F0B6000
/* 0EAB24 7F0B5FF4 03203825 */   move  $a3, $t9
/* 0EAB28 7F0B5FF8 10000024 */  b     .L7F0B608C
/* 0EAB2C 7F0B5FFC 2402FFFF */   li    $v0, -1
.L7F0B6000:
/* 0EAB30 7F0B6000 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0EAB34 7F0B6004 24080018 */  li    $t0, 24
/* 0EAB38 7F0B6008 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAB3C 7F0B600C 01880019 */  multu $t4, $t0
/* 0EAB40 7F0B6010 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAB44 7F0B6014 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAB48 7F0B6018 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAB4C 7F0B601C 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAB50 7F0B6020 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAB54 7F0B6024 8FAA0038 */  lw    $t2, 0x38($sp)
/* 0EAB58 7F0B6028 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAB5C 7F0B602C 3C01F100 */  lui   $at, 0xf100
/* 0EAB60 7F0B6030 01476023 */  subu  $t4, $t2, $a3
/* 0EAB64 7F0B6034 00006812 */  mflo  $t5
/* 0EAB68 7F0B6038 016D7021 */  addu  $t6, $t3, $t5
/* 0EAB6C 7F0B603C 8DCF0000 */  lw    $t7, ($t6)
/* 0EAB70 7F0B6040 03280019 */  multu $t9, $t0
/* 0EAB74 7F0B6044 8FAB0034 */  lw    $t3, 0x34($sp)
/* 0EAB78 7F0B6048 01E2C021 */  addu  $t8, $t7, $v0
/* 0EAB7C 7F0B604C 03023023 */  subu  $a2, $t8, $v0
/* 0EAB80 7F0B6050 018B2821 */  addu  $a1, $t4, $t3
/* 0EAB84 7F0B6054 00C13021 */  addu  $a2, $a2, $at
/* 0EAB88 7F0B6058 AFA50018 */  sw    $a1, 0x18($sp)
/* 0EAB8C 7F0B605C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAB90 7F0B6060 00004812 */  mflo  $t1
/* 0EAB94 7F0B6064 00892021 */  addu  $a0, $a0, $t1
/* 0EAB98 7F0B6068 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EAB9C 7F0B606C 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EABA0 7F0B6070 8FA40018 */  lw    $a0, 0x18($sp)
/* 0EABA4 7F0B6074 0FC2D7E3 */  jal   bgDecompress
/* 0EABA8 7F0B6078 8FA50034 */   lw    $a1, 0x34($sp)
/* 0EABAC 7F0B607C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EABB0 7F0B6080 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0EABB4 7F0B6084 AC62001C */  sw    $v0, 0x1c($v1)
/* 0EABB8 7F0B6088 AC6D0004 */  sw    $t5, 4($v1)
.L7F0B608C:
/* 0EABBC 7F0B608C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EABC0 7F0B6090 27BD0030 */  addiu $sp, $sp, 0x30
/* 0EABC4 7F0B6094 03E00008 */  jr    $ra
/* 0EABC8 7F0B6098 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B5FAC
/* 0EAADC 7F0B5FAC 00047880 */  sll   $t7, $a0, 2
/* 0EAAE0 7F0B5FB0 01E47821 */  addu  $t7, $t7, $a0
/* 0EAAE4 7F0B5FB4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EAAE8 7F0B5FB8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EAAEC 7F0B5FBC 000F7900 */  sll   $t7, $t7, 4
/* 0EAAF0 7F0B5FC0 01F81821 */  addu  $v1, $t7, $t8
/* 0EAAF4 7F0B5FC4 8C670010 */  lw    $a3, 0x10($v1)
/* 0EAAF8 7F0B5FC8 2401FFF0 */  li    $at, -16
/* 0EAAFC 7F0B5FCC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EAB00 7F0B5FD0 24E7000F */  addiu $a3, $a3, 0xf
/* 0EAB04 7F0B5FD4 00E1C824 */  and   $t9, $a3, $at
/* 0EAB08 7F0B5FD8 272A0020 */  addiu $t2, $t9, 0x20
/* 0EAB0C 7F0B5FDC 00CA082A */  slt   $at, $a2, $t2
/* 0EAB10 7F0B5FE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAB14 7F0B5FE4 AFA40030 */  sw    $a0, 0x30($sp)
/* 0EAB18 7F0B5FE8 AFA50034 */  sw    $a1, 0x34($sp)
/* 0EAB1C 7F0B5FEC AFA60038 */  sw    $a2, 0x38($sp)
/* 0EAB20 7F0B5FF0 10200003 */  beqz  $at, .L7F0B6000
/* 0EAB24 7F0B5FF4 03203825 */   move  $a3, $t9
/* 0EAB28 7F0B5FF8 10000024 */  b     .L7F0B608C
/* 0EAB2C 7F0B5FFC 2402FFFF */   li    $v0, -1
.L7F0B6000:
/* 0EAB30 7F0B6000 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0EAB34 7F0B6004 24080018 */  li    $t0, 24
/* 0EAB38 7F0B6008 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAB3C 7F0B600C 01880019 */  multu $t4, $t0
/* 0EAB40 7F0B6010 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAB44 7F0B6014 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAB48 7F0B6018 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAB4C 7F0B601C 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAB50 7F0B6020 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAB54 7F0B6024 8FAA0038 */  lw    $t2, 0x38($sp)
/* 0EAB58 7F0B6028 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAB5C 7F0B602C 3C01F100 */  lui   $at, 0xf100
/* 0EAB60 7F0B6030 01476023 */  subu  $t4, $t2, $a3
/* 0EAB64 7F0B6034 00006812 */  mflo  $t5
/* 0EAB68 7F0B6038 016D7021 */  addu  $t6, $t3, $t5
/* 0EAB6C 7F0B603C 8DCF0000 */  lw    $t7, ($t6)
/* 0EAB70 7F0B6040 03280019 */  multu $t9, $t0
/* 0EAB74 7F0B6044 8FAB0034 */  lw    $t3, 0x34($sp)
/* 0EAB78 7F0B6048 01E2C021 */  addu  $t8, $t7, $v0
/* 0EAB7C 7F0B604C 03023023 */  subu  $a2, $t8, $v0
/* 0EAB80 7F0B6050 018B2821 */  addu  $a1, $t4, $t3
/* 0EAB84 7F0B6054 00C13021 */  addu  $a2, $a2, $at
/* 0EAB88 7F0B6058 AFA50018 */  sw    $a1, 0x18($sp)
/* 0EAB8C 7F0B605C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAB90 7F0B6060 00004812 */  mflo  $t1
/* 0EAB94 7F0B6064 00892021 */  addu  $a0, $a0, $t1
/* 0EAB98 7F0B6068 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EAB9C 7F0B606C 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EABA0 7F0B6070 8FA40018 */  lw    $a0, 0x18($sp)
/* 0EABA4 7F0B6074 0FC2D7E3 */  jal   bgDecompress
/* 0EABA8 7F0B6078 8FA50034 */   lw    $a1, 0x34($sp)
/* 0EABAC 7F0B607C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EABB0 7F0B6080 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0EABB4 7F0B6084 AC62001C */  sw    $v0, 0x1c($v1)
/* 0EABB8 7F0B6088 AC6D0004 */  sw    $t5, 4($v1)
.L7F0B608C:
/* 0EABBC 7F0B608C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EABC0 7F0B6090 27BD0030 */  addiu $sp, $sp, 0x30
/* 0EABC4 7F0B6094 03E00008 */  jr    $ra
/* 0EABC8 7F0B6098 00000000 */   nop
)
#endif

#endif





#ifdef NONMATCHING
u32 * sub_GAME_7F0B609C(int roomID, int *data, u32 size)
{
  u32 dest;
  u32 puVar1;
  u8 *source;
  u32 len;

  len = g_BgRoomInfo[roomID].csize_primary_DL_binary + 0xfU & 0xfffffff0;
  if (size < len + 0x20) {
    dest = 0xffffffff;
  }
  else {
    source = (size - len) + data;
    obLoadBGFileBytesAtOffset
              (levelinfotable[levelentry_index].bg_seg_filename,source,
               &ptr_bgdata_room_fileposition_list[roomID] + -0xf000000,len);
    dest = bgDecompress(source,data);
    puVar1 = (size - dest) + data;
    texCopyGdls(data,puVar1,dest);
    clear_light_fixturetable_in_room(roomID);
    puVar1 = texLoadFromGdl(puVar1,dest,data,NULL);
    if (dest < puVar1) {
      dest = puVar1;
    }
    g_BgRoomInfo[roomID].ptr_expanded_mapping_info = data;
    g_BgRoomInfo[roomID].usize_primary_DL_binary = dest;
  }
  return dest;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B609C
/* 0EABCC 7F0B609C 00047880 */  sll   $t7, $a0, 2
/* 0EABD0 7F0B60A0 01E47821 */  addu  $t7, $t7, $a0
/* 0EABD4 7F0B60A4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EABD8 7F0B60A8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EABDC 7F0B60AC 000F7900 */  sll   $t7, $t7, 4
/* 0EABE0 7F0B60B0 01F84021 */  addu  $t0, $t7, $t8
/* 0EABE4 7F0B60B4 8D070014 */  lw    $a3, 0x14($t0)
/* 0EABE8 7F0B60B8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EABEC 7F0B60BC 2401FFF0 */  li    $at, -16
/* 0EABF0 7F0B60C0 24E7000F */  addiu $a3, $a3, 0xf
/* 0EABF4 7F0B60C4 00E1C824 */  and   $t9, $a3, $at
/* 0EABF8 7F0B60C8 272A0020 */  addiu $t2, $t9, 0x20
/* 0EABFC 7F0B60CC AFB00014 */  sw    $s0, 0x14($sp)
/* 0EAC00 7F0B60D0 00CA082A */  slt   $at, $a2, $t2
/* 0EAC04 7F0B60D4 00A08025 */  move  $s0, $a1
/* 0EAC08 7F0B60D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAC0C 7F0B60DC AFB10018 */  sw    $s1, 0x18($sp)
/* 0EAC10 7F0B60E0 AFA40038 */  sw    $a0, 0x38($sp)
/* 0EAC14 7F0B60E4 AFA60040 */  sw    $a2, 0x40($sp)
/* 0EAC18 7F0B60E8 10200003 */  beqz  $at, .L7F0B60F8
/* 0EAC1C 7F0B60EC 03203825 */   move  $a3, $t9
/* 0EAC20 7F0B60F0 10000035 */  b     .L7F0B61C8
/* 0EAC24 7F0B60F4 2402FFFF */   li    $v0, -1
.L7F0B60F8:
/* 0EAC28 7F0B60F8 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0EAC2C 7F0B60FC 24030018 */  li    $v1, 24
/* 0EAC30 7F0B6100 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAC34 7F0B6104 01830019 */  multu $t4, $v1
/* 0EAC38 7F0B6108 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAC3C 7F0B610C 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAC40 7F0B6110 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAC44 7F0B6114 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAC48 7F0B6118 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAC4C 7F0B611C 8FAA0040 */  lw    $t2, 0x40($sp)
/* 0EAC50 7F0B6120 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAC54 7F0B6124 3C01F100 */  lui   $at, 0xf100
/* 0EAC58 7F0B6128 01476023 */  subu  $t4, $t2, $a3
/* 0EAC5C 7F0B612C 00006812 */  mflo  $t5
/* 0EAC60 7F0B6130 016D7021 */  addu  $t6, $t3, $t5
/* 0EAC64 7F0B6134 8DCF0004 */  lw    $t7, 4($t6)
/* 0EAC68 7F0B6138 03230019 */  multu $t9, $v1
/* 0EAC6C 7F0B613C 01908821 */  addu  $s1, $t4, $s0
/* 0EAC70 7F0B6140 01E2C021 */  addu  $t8, $t7, $v0
/* 0EAC74 7F0B6144 03023023 */  subu  $a2, $t8, $v0
/* 0EAC78 7F0B6148 00C13021 */  addu  $a2, $a2, $at
/* 0EAC7C 7F0B614C 02202825 */  move  $a1, $s1
/* 0EAC80 7F0B6150 AFA80020 */  sw    $t0, 0x20($sp)
/* 0EAC84 7F0B6154 00004812 */  mflo  $t1
/* 0EAC88 7F0B6158 00892021 */  addu  $a0, $a0, $t1
/* 0EAC8C 7F0B615C 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EAC90 7F0B6160 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EAC94 7F0B6164 02202025 */  move  $a0, $s1
/* 0EAC98 7F0B6168 0FC2D7E3 */  jal   bgDecompress
/* 0EAC9C 7F0B616C 02002825 */   move  $a1, $s0
/* 0EACA0 7F0B6170 8FAB0040 */  lw    $t3, 0x40($sp)
/* 0EACA4 7F0B6174 00408825 */  move  $s1, $v0
/* 0EACA8 7F0B6178 02002025 */  move  $a0, $s0
/* 0EACAC 7F0B617C 01626823 */  subu  $t5, $t3, $v0
/* 0EACB0 7F0B6180 01B02821 */  addu  $a1, $t5, $s0
/* 0EACB4 7F0B6184 AFA50028 */  sw    $a1, 0x28($sp)
/* 0EACB8 7F0B6188 0FC339E5 */  jal   texCopyGdls
/* 0EACBC 7F0B618C 00403025 */   move  $a2, $v0
/* 0EACC0 7F0B6190 0FC2F131 */  jal   clear_light_fixturetable_in_room
/* 0EACC4 7F0B6194 8FA40038 */   lw    $a0, 0x38($sp)
/* 0EACC8 7F0B6198 8FA40028 */  lw    $a0, 0x28($sp)
/* 0EACCC 7F0B619C 02202825 */  move  $a1, $s1
/* 0EACD0 7F0B61A0 02003025 */  move  $a2, $s0
/* 0EACD4 7F0B61A4 0FC33846 */  jal   texLoadFromGdl
/* 0EACD8 7F0B61A8 00003825 */   move  $a3, $zero
/* 0EACDC 7F0B61AC 0222082A */  slt   $at, $s1, $v0
/* 0EACE0 7F0B61B0 10200002 */  beqz  $at, .L7F0B61BC
/* 0EACE4 7F0B61B4 8FA30020 */   lw    $v1, 0x20($sp)
/* 0EACE8 7F0B61B8 00408825 */  move  $s1, $v0
.L7F0B61BC:
/* 0EACEC 7F0B61BC AC700008 */  sw    $s0, 8($v1)
/* 0EACF0 7F0B61C0 AC710020 */  sw    $s1, 0x20($v1)
/* 0EACF4 7F0B61C4 02201025 */  move  $v0, $s1
.L7F0B61C8:
/* 0EACF8 7F0B61C8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EACFC 7F0B61CC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EAD00 7F0B61D0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EAD04 7F0B61D4 03E00008 */  jr    $ra
/* 0EAD08 7F0B61D8 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B609C
/* 0EABCC 7F0B609C 00047880 */  sll   $t7, $a0, 2
/* 0EABD0 7F0B60A0 01E47821 */  addu  $t7, $t7, $a0
/* 0EABD4 7F0B60A4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EABD8 7F0B60A8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EABDC 7F0B60AC 000F7900 */  sll   $t7, $t7, 4
/* 0EABE0 7F0B60B0 01F84021 */  addu  $t0, $t7, $t8
/* 0EABE4 7F0B60B4 8D070014 */  lw    $a3, 0x14($t0)
/* 0EABE8 7F0B60B8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EABEC 7F0B60BC 2401FFF0 */  li    $at, -16
/* 0EABF0 7F0B60C0 24E7000F */  addiu $a3, $a3, 0xf
/* 0EABF4 7F0B60C4 00E1C824 */  and   $t9, $a3, $at
/* 0EABF8 7F0B60C8 272A0020 */  addiu $t2, $t9, 0x20
/* 0EABFC 7F0B60CC AFB00014 */  sw    $s0, 0x14($sp)
/* 0EAC00 7F0B60D0 00CA082A */  slt   $at, $a2, $t2
/* 0EAC04 7F0B60D4 00A08025 */  move  $s0, $a1
/* 0EAC08 7F0B60D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAC0C 7F0B60DC AFB10018 */  sw    $s1, 0x18($sp)
/* 0EAC10 7F0B60E0 AFA40038 */  sw    $a0, 0x38($sp)
/* 0EAC14 7F0B60E4 AFA60040 */  sw    $a2, 0x40($sp)
/* 0EAC18 7F0B60E8 10200003 */  beqz  $at, .L7F0B60F8
/* 0EAC1C 7F0B60EC 03203825 */   move  $a3, $t9
/* 0EAC20 7F0B60F0 10000035 */  b     .L7F0B61C8
/* 0EAC24 7F0B60F4 2402FFFF */   li    $v0, -1
.L7F0B60F8:
/* 0EAC28 7F0B60F8 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0EAC2C 7F0B60FC 24030018 */  li    $v1, 24
/* 0EAC30 7F0B6100 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAC34 7F0B6104 01830019 */  multu $t4, $v1
/* 0EAC38 7F0B6108 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAC3C 7F0B610C 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAC40 7F0B6110 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAC44 7F0B6114 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAC48 7F0B6118 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAC4C 7F0B611C 8FAA0040 */  lw    $t2, 0x40($sp)
/* 0EAC50 7F0B6120 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAC54 7F0B6124 3C01F100 */  lui   $at, 0xf100
/* 0EAC58 7F0B6128 01476023 */  subu  $t4, $t2, $a3
/* 0EAC5C 7F0B612C 00006812 */  mflo  $t5
/* 0EAC60 7F0B6130 016D7021 */  addu  $t6, $t3, $t5
/* 0EAC64 7F0B6134 8DCF0004 */  lw    $t7, 4($t6)
/* 0EAC68 7F0B6138 03230019 */  multu $t9, $v1
/* 0EAC6C 7F0B613C 01908821 */  addu  $s1, $t4, $s0
/* 0EAC70 7F0B6140 01E2C021 */  addu  $t8, $t7, $v0
/* 0EAC74 7F0B6144 03023023 */  subu  $a2, $t8, $v0
/* 0EAC78 7F0B6148 00C13021 */  addu  $a2, $a2, $at
/* 0EAC7C 7F0B614C 02202825 */  move  $a1, $s1
/* 0EAC80 7F0B6150 AFA80020 */  sw    $t0, 0x20($sp)
/* 0EAC84 7F0B6154 00004812 */  mflo  $t1
/* 0EAC88 7F0B6158 00892021 */  addu  $a0, $a0, $t1
/* 0EAC8C 7F0B615C 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EAC90 7F0B6160 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EAC94 7F0B6164 02202025 */  move  $a0, $s1
/* 0EAC98 7F0B6168 0FC2D7E3 */  jal   bgDecompress
/* 0EAC9C 7F0B616C 02002825 */   move  $a1, $s0
/* 0EACA0 7F0B6170 8FAB0040 */  lw    $t3, 0x40($sp)
/* 0EACA4 7F0B6174 00408825 */  move  $s1, $v0
/* 0EACA8 7F0B6178 02002025 */  move  $a0, $s0
/* 0EACAC 7F0B617C 01626823 */  subu  $t5, $t3, $v0
/* 0EACB0 7F0B6180 01B02821 */  addu  $a1, $t5, $s0
/* 0EACB4 7F0B6184 AFA50028 */  sw    $a1, 0x28($sp)
/* 0EACB8 7F0B6188 0FC339E5 */  jal   texCopyGdls
/* 0EACBC 7F0B618C 00403025 */   move  $a2, $v0
/* 0EACC0 7F0B6190 0FC2F131 */  jal   clear_light_fixturetable_in_room
/* 0EACC4 7F0B6194 8FA40038 */   lw    $a0, 0x38($sp)
/* 0EACC8 7F0B6198 8FA40028 */  lw    $a0, 0x28($sp)
/* 0EACCC 7F0B619C 02202825 */  move  $a1, $s1
/* 0EACD0 7F0B61A0 02003025 */  move  $a2, $s0
/* 0EACD4 7F0B61A4 0FC33846 */  jal   texLoadFromGdl
/* 0EACD8 7F0B61A8 00003825 */   move  $a3, $zero
/* 0EACDC 7F0B61AC 0222082A */  slt   $at, $s1, $v0
/* 0EACE0 7F0B61B0 10200002 */  beqz  $at, .L7F0B61BC
/* 0EACE4 7F0B61B4 8FA30020 */   lw    $v1, 0x20($sp)
/* 0EACE8 7F0B61B8 00408825 */  move  $s1, $v0
.L7F0B61BC:
/* 0EACEC 7F0B61BC AC700008 */  sw    $s0, 8($v1)
/* 0EACF0 7F0B61C0 AC710020 */  sw    $s1, 0x20($v1)
/* 0EACF4 7F0B61C4 02201025 */  move  $v0, $s1
.L7F0B61C8:
/* 0EACF8 7F0B61C8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EACFC 7F0B61CC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EAD00 7F0B61D0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EAD04 7F0B61D4 03E00008 */  jr    $ra
/* 0EAD08 7F0B61D8 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#endif





#ifdef NONMATCHING
u32 sub_GAME_7F0B61DC(s32 roomID, u32 *data, s32 size)
{
    u32 dest;
    u32 puVar1;
    u8 *source;
    u32 len;

    len = g_BgRoomInfo[roomID].csize_secondary_DL_binary + 0xfU & 0xfffffff0;
    if (size < len + 0x20)
    {
        dest = 0xffffffff;
    }
    else
    {
        source = (size - len) + data;
        obLoadBGFileBytesAtOffset(levelinfotable[levelentry_index].bg_seg_filename,source, ptr_bgdata_room_fileposition_list[roomID].pos.z + -0xf000000,len);
        dest = bgDecompress(source,data);
        puVar1 = (size - dest) + data;
        texCopyGdls(data,puVar1,dest);
        puVar1 = texLoadFromGdl(puVar1,dest,data,NULL);
        if (dest < puVar1) {
            dest = puVar1;
        }
        g_BgRoomInfo[roomID].ptr_secondary_expanded_mapping_info = data;
        g_BgRoomInfo[roomID].usize_secondary_DL_binary = dest;
    }
    return dest;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B61DC
/* 0EAD0C 7F0B61DC 00047880 */  sll   $t7, $a0, 2
/* 0EAD10 7F0B61E0 01E47821 */  addu  $t7, $t7, $a0
/* 0EAD14 7F0B61E4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EAD18 7F0B61E8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EAD1C 7F0B61EC 000F7900 */  sll   $t7, $t7, 4
/* 0EAD20 7F0B61F0 01F84021 */  addu  $t0, $t7, $t8
/* 0EAD24 7F0B61F4 8D070018 */  lw    $a3, 0x18($t0)
/* 0EAD28 7F0B61F8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EAD2C 7F0B61FC 2401FFF0 */  li    $at, -16
/* 0EAD30 7F0B6200 24E7000F */  addiu $a3, $a3, 0xf
/* 0EAD34 7F0B6204 00E1C824 */  and   $t9, $a3, $at
/* 0EAD38 7F0B6208 272A0020 */  addiu $t2, $t9, 0x20
/* 0EAD3C 7F0B620C AFB10018 */  sw    $s1, 0x18($sp)
/* 0EAD40 7F0B6210 00CA082A */  slt   $at, $a2, $t2
/* 0EAD44 7F0B6214 00A08825 */  move  $s1, $a1
/* 0EAD48 7F0B6218 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAD4C 7F0B621C AFB00014 */  sw    $s0, 0x14($sp)
/* 0EAD50 7F0B6220 AFA40038 */  sw    $a0, 0x38($sp)
/* 0EAD54 7F0B6224 AFA60040 */  sw    $a2, 0x40($sp)
/* 0EAD58 7F0B6228 10200003 */  beqz  $at, .L7F0B6238
/* 0EAD5C 7F0B622C 03203825 */   move  $a3, $t9
/* 0EAD60 7F0B6230 10000033 */  b     .L7F0B6300
/* 0EAD64 7F0B6234 2402FFFF */   li    $v0, -1
.L7F0B6238:
/* 0EAD68 7F0B6238 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0EAD6C 7F0B623C 24030018 */  li    $v1, 24
/* 0EAD70 7F0B6240 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAD74 7F0B6244 01830019 */  multu $t4, $v1
/* 0EAD78 7F0B6248 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAD7C 7F0B624C 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAD80 7F0B6250 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAD84 7F0B6254 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAD88 7F0B6258 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAD8C 7F0B625C 8FAA0040 */  lw    $t2, 0x40($sp)
/* 0EAD90 7F0B6260 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAD94 7F0B6264 3C01F100 */  lui   $at, 0xf100
/* 0EAD98 7F0B6268 01476023 */  subu  $t4, $t2, $a3
/* 0EAD9C 7F0B626C 00006812 */  mflo  $t5
/* 0EADA0 7F0B6270 016D7021 */  addu  $t6, $t3, $t5
/* 0EADA4 7F0B6274 8DCF0008 */  lw    $t7, 8($t6)
/* 0EADA8 7F0B6278 03230019 */  multu $t9, $v1
/* 0EADAC 7F0B627C 01918021 */  addu  $s0, $t4, $s1
/* 0EADB0 7F0B6280 01E2C021 */  addu  $t8, $t7, $v0
/* 0EADB4 7F0B6284 03023023 */  subu  $a2, $t8, $v0
/* 0EADB8 7F0B6288 00C13021 */  addu  $a2, $a2, $at
/* 0EADBC 7F0B628C 02002825 */  move  $a1, $s0
/* 0EADC0 7F0B6290 AFA80020 */  sw    $t0, 0x20($sp)
/* 0EADC4 7F0B6294 00004812 */  mflo  $t1
/* 0EADC8 7F0B6298 00892021 */  addu  $a0, $a0, $t1
/* 0EADCC 7F0B629C 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EADD0 7F0B62A0 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EADD4 7F0B62A4 02002025 */  move  $a0, $s0
/* 0EADD8 7F0B62A8 0FC2D7E3 */  jal   bgDecompress
/* 0EADDC 7F0B62AC 02202825 */   move  $a1, $s1
/* 0EADE0 7F0B62B0 8FAB0040 */  lw    $t3, 0x40($sp)
/* 0EADE4 7F0B62B4 00408025 */  move  $s0, $v0
/* 0EADE8 7F0B62B8 02202025 */  move  $a0, $s1
/* 0EADEC 7F0B62BC 01626823 */  subu  $t5, $t3, $v0
/* 0EADF0 7F0B62C0 01B12821 */  addu  $a1, $t5, $s1
/* 0EADF4 7F0B62C4 AFA50028 */  sw    $a1, 0x28($sp)
/* 0EADF8 7F0B62C8 0FC339E5 */  jal   texCopyGdls
/* 0EADFC 7F0B62CC 00403025 */   move  $a2, $v0
/* 0EAE00 7F0B62D0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0EAE04 7F0B62D4 02002825 */  move  $a1, $s0
/* 0EAE08 7F0B62D8 02203025 */  move  $a2, $s1
/* 0EAE0C 7F0B62DC 0FC33846 */  jal   texLoadFromGdl
/* 0EAE10 7F0B62E0 00003825 */   move  $a3, $zero
/* 0EAE14 7F0B62E4 0202082A */  slt   $at, $s0, $v0
/* 0EAE18 7F0B62E8 10200002 */  beqz  $at, .L7F0B62F4
/* 0EAE1C 7F0B62EC 8FA30020 */   lw    $v1, 0x20($sp)
/* 0EAE20 7F0B62F0 00408025 */  move  $s0, $v0
.L7F0B62F4:
/* 0EAE24 7F0B62F4 AC71000C */  sw    $s1, 0xc($v1)
/* 0EAE28 7F0B62F8 AC700024 */  sw    $s0, 0x24($v1)
/* 0EAE2C 7F0B62FC 02001025 */  move  $v0, $s0
.L7F0B6300:
/* 0EAE30 7F0B6300 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAE34 7F0B6304 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EAE38 7F0B6308 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EAE3C 7F0B630C 03E00008 */  jr    $ra
/* 0EAE40 7F0B6310 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B61DC
/* 0EAD0C 7F0B61DC 00047880 */  sll   $t7, $a0, 2
/* 0EAD10 7F0B61E0 01E47821 */  addu  $t7, $t7, $a0
/* 0EAD14 7F0B61E4 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EAD18 7F0B61E8 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EAD1C 7F0B61EC 000F7900 */  sll   $t7, $t7, 4
/* 0EAD20 7F0B61F0 01F84021 */  addu  $t0, $t7, $t8
/* 0EAD24 7F0B61F4 8D070018 */  lw    $a3, 0x18($t0)
/* 0EAD28 7F0B61F8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EAD2C 7F0B61FC 2401FFF0 */  li    $at, -16
/* 0EAD30 7F0B6200 24E7000F */  addiu $a3, $a3, 0xf
/* 0EAD34 7F0B6204 00E1C824 */  and   $t9, $a3, $at
/* 0EAD38 7F0B6208 272A0020 */  addiu $t2, $t9, 0x20
/* 0EAD3C 7F0B620C AFB10018 */  sw    $s1, 0x18($sp)
/* 0EAD40 7F0B6210 00CA082A */  slt   $at, $a2, $t2
/* 0EAD44 7F0B6214 00A08825 */  move  $s1, $a1
/* 0EAD48 7F0B6218 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAD4C 7F0B621C AFB00014 */  sw    $s0, 0x14($sp)
/* 0EAD50 7F0B6220 AFA40038 */  sw    $a0, 0x38($sp)
/* 0EAD54 7F0B6224 AFA60040 */  sw    $a2, 0x40($sp)
/* 0EAD58 7F0B6228 10200003 */  beqz  $at, .L7F0B6238
/* 0EAD5C 7F0B622C 03203825 */   move  $a3, $t9
/* 0EAD60 7F0B6230 10000033 */  b     .L7F0B6300
/* 0EAD64 7F0B6234 2402FFFF */   li    $v0, -1
.L7F0B6238:
/* 0EAD68 7F0B6238 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0EAD6C 7F0B623C 24030018 */  li    $v1, 24
/* 0EAD70 7F0B6240 3C198004 */  lui   $t9, %hi(levelentry_index)
/* 0EAD74 7F0B6244 01830019 */  multu $t4, $v1
/* 0EAD78 7F0B6248 8F391400 */  lw    $t9, %lo(levelentry_index)($t9)
/* 0EAD7C 7F0B624C 3C0B8008 */  lui   $t3, %hi(ptr_bgdata_room_fileposition_list)
/* 0EAD80 7F0B6250 8D6BFF8C */  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
/* 0EAD84 7F0B6254 3C028008 */  lui   $v0, %hi(ptr_bg_data)
/* 0EAD88 7F0B6258 8C42BF90 */  lw    $v0, %lo(ptr_bg_data)($v0)
/* 0EAD8C 7F0B625C 8FAA0040 */  lw    $t2, 0x40($sp)
/* 0EAD90 7F0B6260 3C048004 */  lui   $a0, %hi(levelinfotable)
/* 0EAD94 7F0B6264 3C01F100 */  lui   $at, 0xf100
/* 0EAD98 7F0B6268 01476023 */  subu  $t4, $t2, $a3
/* 0EAD9C 7F0B626C 00006812 */  mflo  $t5
/* 0EADA0 7F0B6270 016D7021 */  addu  $t6, $t3, $t5
/* 0EADA4 7F0B6274 8DCF0008 */  lw    $t7, 8($t6)
/* 0EADA8 7F0B6278 03230019 */  multu $t9, $v1
/* 0EADAC 7F0B627C 01918021 */  addu  $s0, $t4, $s1
/* 0EADB0 7F0B6280 01E2C021 */  addu  $t8, $t7, $v0
/* 0EADB4 7F0B6284 03023023 */  subu  $a2, $t8, $v0
/* 0EADB8 7F0B6288 00C13021 */  addu  $a2, $a2, $at
/* 0EADBC 7F0B628C 02002825 */  move  $a1, $s0
/* 0EADC0 7F0B6290 AFA80020 */  sw    $t0, 0x20($sp)
/* 0EADC4 7F0B6294 00004812 */  mflo  $t1
/* 0EADC8 7F0B6298 00892021 */  addu  $a0, $a0, $t1
/* 0EADCC 7F0B629C 0FC2F35F */  jal   obLoadBGFileBytesAtOffset
/* 0EADD0 7F0B62A0 8C844490 */   lw    $a0, %lo(levelinfotable+4)($a0)
/* 0EADD4 7F0B62A4 02002025 */  move  $a0, $s0
/* 0EADD8 7F0B62A8 0FC2D7E3 */  jal   bgDecompress
/* 0EADDC 7F0B62AC 02202825 */   move  $a1, $s1
/* 0EADE0 7F0B62B0 8FAB0040 */  lw    $t3, 0x40($sp)
/* 0EADE4 7F0B62B4 00408025 */  move  $s0, $v0
/* 0EADE8 7F0B62B8 02202025 */  move  $a0, $s1
/* 0EADEC 7F0B62BC 01626823 */  subu  $t5, $t3, $v0
/* 0EADF0 7F0B62C0 01B12821 */  addu  $a1, $t5, $s1
/* 0EADF4 7F0B62C4 AFA50028 */  sw    $a1, 0x28($sp)
/* 0EADF8 7F0B62C8 0FC339E5 */  jal   texCopyGdls
/* 0EADFC 7F0B62CC 00403025 */   move  $a2, $v0
/* 0EAE00 7F0B62D0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0EAE04 7F0B62D4 02002825 */  move  $a1, $s0
/* 0EAE08 7F0B62D8 02203025 */  move  $a2, $s1
/* 0EAE0C 7F0B62DC 0FC33846 */  jal   texLoadFromGdl
/* 0EAE10 7F0B62E0 00003825 */   move  $a3, $zero
/* 0EAE14 7F0B62E4 0202082A */  slt   $at, $s0, $v0
/* 0EAE18 7F0B62E8 10200002 */  beqz  $at, .L7F0B62F4
/* 0EAE1C 7F0B62EC 8FA30020 */   lw    $v1, 0x20($sp)
/* 0EAE20 7F0B62F0 00408025 */  move  $s0, $v0
.L7F0B62F4:
/* 0EAE24 7F0B62F4 AC71000C */  sw    $s1, 0xc($v1)
/* 0EAE28 7F0B62F8 AC700024 */  sw    $s0, 0x24($v1)
/* 0EAE2C 7F0B62FC 02001025 */  move  $v0, $s0
.L7F0B6300:
/* 0EAE30 7F0B6300 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAE34 7F0B6304 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EAE38 7F0B6308 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EAE3C 7F0B630C 03E00008 */  jr    $ra
/* 0EAE40 7F0B6310 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#endif





s32 bgCheckIfRoomModelNeedsLoad(s32 roomID)
{
    g_BgRoomInfo[roomID].field_35 = 1;
    if (g_BgRoomInfo[roomID].model_bin_loaded == FALSE)
    {
        sub_GAME_7F0B6368(roomID);
        return 1;
    }
    return 0;
}





#ifdef NONMATCHING
/*
* Allocates memory for room and update its display lists
* Address: 7F0B6368
*/
void sub_GAME_7F0B6368(s32 room) {
    void *sp1C;
    s32 sp20;
    s32 sp28;
    s32 sp2C;
    void *temp_v1;
    ? temp_ret;
    void *temp_v1_2;
    ? temp_ret_2;
    ? temp_ret_3;
    void *temp_v1_5;
    ? temp_ret_4;
    void *temp_v1_6;
    s32 temp_t1;
    s32 temp_a0;
    void *temp_v1_3;
    s32 temp_a0_2;
    void *temp_v1_4;
    void *phi_v1;
    s32 phi_a3;
    s32 phi_a3_2;
    void *phi_v1_2;
    void *phi_v1_3;

    // Node 0
    if (room < g_MaxNumRooms)
    {
        // Node 1
        temp_v1 = ((room * 0x50) + &g_BgRoomInfo);
        if (temp_v1->unk2 == 0)
        {
            // Node 2
            if (temp_v1->unk28 > 0)
            {
                // Node 3
                sp2C = (s32) temp_v1->unk28;
                sp1C = temp_v1;
                sp28 = 0;
                if (get_debug_joy2detailedit_flag(0) != 0)
                {
                    // Node 4
                    sp2C = (s32) (sp2C + 0x400);
                }
            }
            else
            {
                // Node 5
                sp1C = temp_v1;
                sp2C = memaGetLongestFree(0);
            }
            // Node 6
            sp1C = (void *) temp_v1;
            temp_ret = memaAlloc(sp2C, sp28);
            temp_v1_2 = temp_v1;
            sp20 = temp_ret;
            if (temp_ret != 0)
            {
                // Node 7
                if (temp_v1_2->unk10 != 0)
                {
                    // Node 8
                    sp1C = temp_v1_2;
                    temp_ret_2 = sub_GAME_7F0B5FAC(room, temp_ret, sp2C, sp28);
                    if (temp_ret_2 >= 0)
                    {
                        // Node 9
                        sp1C = temp_v1_2;
                        sp28 = temp_ret_2;
                        redarken_lights_in_room(room, sp28);
                    }
                }
                else
                {
                    // Node 10
                    temp_v1_2->unk4 = 0;
                    temp_v1_2->unk1C = 0;
                }
                // Node 11
                phi_v1 = temp_v1_2;
                phi_a3 = sp28;
                if (temp_v1_2->unk14 != 0)
                {
                    // Node 12
                    sp1C = (void *) temp_v1_2;
                    temp_ret_3 = sub_GAME_7F0B609C(room, (sp20 + sp28), (sp2C - sp28), sp28);
                    temp_v1_5 = temp_v1_2;
                    phi_v1 = temp_v1_5;
                    phi_a3 = sp28;
                    if (temp_ret_3 >= 0)
                    {
                        // Node 13
                        phi_v1 = temp_v1_5;
                        phi_a3 = (sp28 + temp_ret_3);
                    }
                }
                // Node 14
                if (phi_v1->unk18 != 0)
                {
                    // Node 15
                    sp1C = (void *) phi_v1;
                    temp_ret_4 = sub_GAME_7F0B61DC(room, (sp20 + phi_a3), (sp2C - phi_a3), phi_a3);
                    temp_v1_6 = phi_v1;
                    phi_a3_2 = sp28;
                    phi_v1_2 = temp_v1_6;
                    if (temp_ret_4 > 0)
                    {
                        // Node 16
                        phi_a3_2 = (sp28 + temp_ret_4);
                        phi_v1_2 = temp_v1_6;
                    }
                }
                else
                {
                    // Node 17
                    phi_v1->unkC = 0;
                    phi_a3_2 = phi_a3;
                    phi_v1_2 = phi_v1;
                }
                // Node 18
                temp_t1 = ((phi_a3_2 + 0x20) & -0x10);
                phi_v1_2->unk28 = temp_t1;
                phi_v1_2->unk2 = (u8)1;
                phi_v1_3 = phi_v1_2;
                if (sp2C != temp_t1)
                {
                    // Node 19
                    sp1C = (void *) phi_v1_2;
                    memaRealloc(sp20, sp2C, temp_t1, phi_a3_2);
                    phi_v1_3 = phi_v1_2;
                }
                // Node 20
                if (g_FogSkyIsEnabled != 0)
                {
                    // Node 21
                    temp_a0 = phi_v1_3->unk8;
                    sp1C = (void *) phi_v1_3;
                    bgLoadFromDynamicCCRMLUT(temp_a0, (phi_v1_3->unk20 + temp_a0), CCRMLUT_PRIMARY_ADDFOG);
                    temp_v1_3 = phi_v1_3;
                    if (temp_v1_3->unkC != 0)
                    {
                        // Node 22
                        bgLoadFromDynamicCCRMLUT(temp_v1_3->unkC, (temp_v1_3->unk24 + temp_v1_3->unkC), CCRMLUT_SECONDARY_ADDFOG);
                    }
                }
                else
                {
                    // Node 23
                    temp_a0_2 = phi_v1_3->unk8;
                    sp1C = (void *) phi_v1_3;
                    bgLoadFromDynamicCCRMLUT(temp_a0_2, (phi_v1_3->unk20 + temp_a0_2), CCRMLUT_PRIMARY);
                    temp_v1_4 = phi_v1_3;
                    if (temp_v1_4->unkC != 0)
                    {
                        // Node 24
                        bgLoadFromDynamicCCRMLUT(temp_v1_4->unkC, (temp_v1_4->unk24 + temp_v1_4->unkC), CCRMLUT_SECONDARY);
                    }
                }
                // Node 25
                sub_GAME_7F0B6994(room);
                roomsHandleStateDebugging();
            }
        }
    }
    // Node 26
    return;
}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B6368
/* 0EAE98 7F0B6368 3C0F8004 */  lui   $t7, %hi(g_MaxNumRooms)
/* 0EAE9C 7F0B636C 8DEF42F4 */  lw    $t7, %lo(g_MaxNumRooms)($t7)
/* 0EAEA0 7F0B6370 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EAEA4 7F0B6374 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAEA8 7F0B6378 008F082A */  slt   $at, $a0, $t7
/* 0EAEAC 7F0B637C AFA40030 */  sw    $a0, 0x30($sp)
/* 0EAEB0 7F0B6380 1020008C */  beqz  $at, .L7F0B65B4
/* 0EAEB4 7F0B6384 00003825 */   move  $a3, $zero
/* 0EAEB8 7F0B6388 0004C880 */  sll   $t9, $a0, 2
/* 0EAEBC 7F0B638C 0324C821 */  addu  $t9, $t9, $a0
/* 0EAEC0 7F0B6390 3C088004 */  lui   $t0, %hi(g_BgRoomInfo)
/* 0EAEC4 7F0B6394 25081414 */  addiu $t0, %lo(g_BgRoomInfo) # addiu $t0, $t0, 0x1414
/* 0EAEC8 7F0B6398 0019C900 */  sll   $t9, $t9, 4
/* 0EAECC 7F0B639C 03281821 */  addu  $v1, $t9, $t0
/* 0EAED0 7F0B63A0 90690002 */  lbu   $t1, 2($v1)
/* 0EAED4 7F0B63A4 55200084 */  bnezl $t1, .L7F0B65B8
/* 0EAED8 7F0B63A8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0EAEDC 7F0B63AC 8C620028 */  lw    $v0, 0x28($v1)
/* 0EAEE0 7F0B63B0 5840000D */  blezl $v0, .L7F0B63E8
/* 0EAEE4 7F0B63B4 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0EAEE8 7F0B63B8 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0EAEEC 7F0B63BC AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAEF0 7F0B63C0 0FC243EE */  jal   get_debug_joy2detailedit_flag
/* 0EAEF4 7F0B63C4 AFA00028 */   sw    $zero, 0x28($sp)
/* 0EAEF8 7F0B63C8 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAEFC 7F0B63CC 1040000B */  beqz  $v0, .L7F0B63FC
/* 0EAF00 7F0B63D0 8FA70028 */   lw    $a3, 0x28($sp)
/* 0EAF04 7F0B63D4 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0EAF08 7F0B63D8 254B0400 */  addiu $t3, $t2, 0x400
/* 0EAF0C 7F0B63DC 10000007 */  b     .L7F0B63FC
/* 0EAF10 7F0B63E0 AFAB002C */   sw    $t3, 0x2c($sp)
/* 0EAF14 7F0B63E4 AFA3001C */  sw    $v1, 0x1c($sp)
.L7F0B63E8:
/* 0EAF18 7F0B63E8 0C0028DC */  jal   memaGetLongestFree
/* 0EAF1C 7F0B63EC AFA70028 */   sw    $a3, 0x28($sp)
/* 0EAF20 7F0B63F0 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAF24 7F0B63F4 8FA70028 */  lw    $a3, 0x28($sp)
/* 0EAF28 7F0B63F8 AFA2002C */  sw    $v0, 0x2c($sp)
.L7F0B63FC:
/* 0EAF2C 7F0B63FC 8FA4002C */  lw    $a0, 0x2c($sp)
/* 0EAF30 7F0B6400 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAF34 7F0B6404 0C00278D */  jal   memaAlloc
/* 0EAF38 7F0B6408 AFA70028 */   sw    $a3, 0x28($sp)
/* 0EAF3C 7F0B640C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAF40 7F0B6410 8FA70028 */  lw    $a3, 0x28($sp)
/* 0EAF44 7F0B6414 10400067 */  beqz  $v0, .L7F0B65B4
/* 0EAF48 7F0B6418 AFA20020 */   sw    $v0, 0x20($sp)
/* 0EAF4C 7F0B641C 8C6C0010 */  lw    $t4, 0x10($v1)
/* 0EAF50 7F0B6420 8FA40030 */  lw    $a0, 0x30($sp)
/* 0EAF54 7F0B6424 00402825 */  move  $a1, $v0
/* 0EAF58 7F0B6428 1180000E */  beqz  $t4, .L7F0B6464
/* 0EAF5C 7F0B642C 8FA6002C */   lw    $a2, 0x2c($sp)
/* 0EAF60 7F0B6430 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAF64 7F0B6434 0FC2D7EB */  jal   sub_GAME_7F0B5FAC
/* 0EAF68 7F0B6438 AFA70028 */   sw    $a3, 0x28($sp)
/* 0EAF6C 7F0B643C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAF70 7F0B6440 0440000A */  bltz  $v0, .L7F0B646C
/* 0EAF74 7F0B6444 8FA70028 */   lw    $a3, 0x28($sp)
/* 0EAF78 7F0B6448 8FA40030 */  lw    $a0, 0x30($sp)
/* 0EAF7C 7F0B644C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAF80 7F0B6450 0FC2EE5E */  jal   redarken_lights_in_room
/* 0EAF84 7F0B6454 AFA20028 */   sw    $v0, 0x28($sp)
/* 0EAF88 7F0B6458 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAF8C 7F0B645C 10000003 */  b     .L7F0B646C
/* 0EAF90 7F0B6460 8FA70028 */   lw    $a3, 0x28($sp)
.L7F0B6464:
/* 0EAF94 7F0B6464 AC600004 */  sw    $zero, 4($v1)
/* 0EAF98 7F0B6468 AC60001C */  sw    $zero, 0x1c($v1)
.L7F0B646C:
/* 0EAF9C 7F0B646C 8C6D0014 */  lw    $t5, 0x14($v1)
/* 0EAFA0 7F0B6470 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0EAFA4 7F0B6474 8FA40030 */  lw    $a0, 0x30($sp)
/* 0EAFA8 7F0B6478 11A0000A */  beqz  $t5, .L7F0B64A4
/* 0EAFAC 7F0B647C 01C72821 */   addu  $a1, $t6, $a3
/* 0EAFB0 7F0B6480 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0EAFB4 7F0B6484 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAFB8 7F0B6488 AFA70028 */  sw    $a3, 0x28($sp)
/* 0EAFBC 7F0B648C 0FC2D827 */  jal   sub_GAME_7F0B609C
/* 0EAFC0 7F0B6490 01E73023 */   subu  $a2, $t7, $a3
/* 0EAFC4 7F0B6494 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EAFC8 7F0B6498 04400002 */  bltz  $v0, .L7F0B64A4
/* 0EAFCC 7F0B649C 8FA70028 */   lw    $a3, 0x28($sp)
/* 0EAFD0 7F0B64A0 00E23821 */  addu  $a3, $a3, $v0
.L7F0B64A4:
/* 0EAFD4 7F0B64A4 8C780018 */  lw    $t8, 0x18($v1)
/* 0EAFD8 7F0B64A8 8FB90020 */  lw    $t9, 0x20($sp)
/* 0EAFDC 7F0B64AC 8FA40030 */  lw    $a0, 0x30($sp)
/* 0EAFE0 7F0B64B0 1300000B */  beqz  $t8, .L7F0B64E0
/* 0EAFE4 7F0B64B4 03272821 */   addu  $a1, $t9, $a3
/* 0EAFE8 7F0B64B8 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0EAFEC 7F0B64BC AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EAFF0 7F0B64C0 AFA70028 */  sw    $a3, 0x28($sp)
/* 0EAFF4 7F0B64C4 0FC2D877 */  jal   sub_GAME_7F0B61DC
/* 0EAFF8 7F0B64C8 01073023 */   subu  $a2, $t0, $a3
/* 0EAFFC 7F0B64CC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EB000 7F0B64D0 18400004 */  blez  $v0, .L7F0B64E4
/* 0EB004 7F0B64D4 8FA70028 */   lw    $a3, 0x28($sp)
/* 0EB008 7F0B64D8 10000002 */  b     .L7F0B64E4
/* 0EB00C 7F0B64DC 00E23821 */   addu  $a3, $a3, $v0
.L7F0B64E0:
/* 0EB010 7F0B64E0 AC60000C */  sw    $zero, 0xc($v1)
.L7F0B64E4:
/* 0EB014 7F0B64E4 8FAB002C */  lw    $t3, 0x2c($sp)
/* 0EB018 7F0B64E8 24E20020 */  addiu $v0, $a3, 0x20
/* 0EB01C 7F0B64EC 2401FFF0 */  li    $at, -16
/* 0EB020 7F0B64F0 00414824 */  and   $t1, $v0, $at
/* 0EB024 7F0B64F4 240A0001 */  li    $t2, 1
/* 0EB028 7F0B64F8 AC690028 */  sw    $t1, 0x28($v1)
/* 0EB02C 7F0B64FC 11690007 */  beq   $t3, $t1, .L7F0B651C
/* 0EB030 7F0B6500 A06A0002 */   sb    $t2, 2($v1)
/* 0EB034 7F0B6504 8FA40020 */  lw    $a0, 0x20($sp)
/* 0EB038 7F0B6508 01602825 */  move  $a1, $t3
/* 0EB03C 7F0B650C 01203025 */  move  $a2, $t1
/* 0EB040 7F0B6510 0C0028F7 */  jal   memaRealloc
/* 0EB044 7F0B6514 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0EB048 7F0B6518 8FA3001C */  lw    $v1, 0x1c($sp)
.L7F0B651C:
/* 0EB04C 7F0B651C 3C0C8008 */  lui   $t4, %hi(g_FogSkyIsEnabled)
/* 0EB050 7F0B6520 8D8C25C0 */  lw    $t4, %lo(g_FogSkyIsEnabled)($t4)
/* 0EB054 7F0B6524 24060006 */  li    $a2, 6
/* 0EB058 7F0B6528 51800012 */  beql  $t4, $zero, .L7F0B6574
/* 0EB05C 7F0B652C 8C640008 */   lw    $a0, 8($v1)
/* 0EB060 7F0B6530 8C640008 */  lw    $a0, 8($v1)
/* 0EB064 7F0B6534 8C6D0020 */  lw    $t5, 0x20($v1)
/* 0EB068 7F0B6538 24060001 */  li    $a2, 1
/* 0EB06C 7F0B653C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EB070 7F0B6540 0FC2E990 */  jal   bgLoadFromDynamicCCRMLUT
/* 0EB074 7F0B6544 01A42821 */   addu  $a1, $t5, $a0
/* 0EB078 7F0B6548 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EB07C 7F0B654C 8C64000C */  lw    $a0, 0xc($v1)
/* 0EB080 7F0B6550 10800014 */  beqz  $a0, .L7F0B65A4
/* 0EB084 7F0B6554 00000000 */   nop
/* 0EB088 7F0B6558 8C6E0024 */  lw    $t6, 0x24($v1)
/* 0EB08C 7F0B655C 24060005 */  li    $a2, 5
/* 0EB090 7F0B6560 0FC2E990 */  jal   bgLoadFromDynamicCCRMLUT
/* 0EB094 7F0B6564 01C42821 */   addu  $a1, $t6, $a0
/* 0EB098 7F0B6568 1000000E */  b     .L7F0B65A4
/* 0EB09C 7F0B656C 00000000 */   nop
/* 0EB0A0 7F0B6570 8C640008 */  lw    $a0, 8($v1)
.L7F0B6574:
/* 0EB0A4 7F0B6574 8C6F0020 */  lw    $t7, 0x20($v1)
/* 0EB0A8 7F0B6578 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EB0AC 7F0B657C 0FC2E990 */  jal   bgLoadFromDynamicCCRMLUT
/* 0EB0B0 7F0B6580 01E42821 */   addu  $a1, $t7, $a0
/* 0EB0B4 7F0B6584 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EB0B8 7F0B6588 8C64000C */  lw    $a0, 0xc($v1)
/* 0EB0BC 7F0B658C 10800005 */  beqz  $a0, .L7F0B65A4
/* 0EB0C0 7F0B6590 00000000 */   nop
/* 0EB0C4 7F0B6594 8C780024 */  lw    $t8, 0x24($v1)
/* 0EB0C8 7F0B6598 24060007 */  li    $a2, 7
/* 0EB0CC 7F0B659C 0FC2E990 */  jal   bgLoadFromDynamicCCRMLUT
/* 0EB0D0 7F0B65A0 03042821 */   addu  $a1, $t8, $a0
.L7F0B65A4:
/* 0EB0D4 7F0B65A4 0FC2DA65 */  jal   sub_GAME_7F0B6994
/* 0EB0D8 7F0B65A8 8FA40030 */   lw    $a0, 0x30($sp)
/* 0EB0DC 7F0B65AC 0FC2D7B6 */  jal   roomsHandleStateDebugging
/* 0EB0E0 7F0B65B0 00000000 */   nop
.L7F0B65B4:
/* 0EB0E4 7F0B65B4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0B65B8:
/* 0EB0E8 7F0B65B8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0EB0EC 7F0B65BC 03E00008 */  jr    $ra
/* 0EB0F0 7F0B65C0 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B6368
/* 0E8094 7F0B56A4 3C0F8004 */  lui   $t7, %hi(g_MaxNumRooms) # $t7, 0x8004
/* 0E8098 7F0B56A8 8DEFD7D4 */  lw    $t7, %lo(g_MaxNumRooms)($t7)
/* 0E809C 7F0B56AC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E80A0 7F0B56B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E80A4 7F0B56B4 008F082A */  slt   $at, $a0, $t7
/* 0E80A8 7F0B56B8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0E80AC 7F0B56BC 1020008C */  beqz  $at, .L7F0B58F0
/* 0E80B0 7F0B56C0 00003825 */   move  $a3, $zero
/* 0E80B4 7F0B56C4 0004C880 */  sll   $t9, $a0, 2
/* 0E80B8 7F0B56C8 0324C821 */  addu  $t9, $t9, $a0
/* 0E80BC 7F0B56CC 3C088004 */  lui   $t0, %hi(g_BgRoomInfo) # $t0, 0x8004
/* 0E80C0 7F0B56D0 2508AC64 */  addiu $t0, %lo(g_BgRoomInfo) # addiu $t0, $t0, -0x539c
/* 0E80C4 7F0B56D4 0019C900 */  sll   $t9, $t9, 4
/* 0E80C8 7F0B56D8 03281821 */  addu  $v1, $t9, $t0
/* 0E80CC 7F0B56DC 90690002 */  lbu   $t1, 2($v1)
/* 0E80D0 7F0B56E0 55200084 */  bnezl $t1, .L7F0B58F4
/* 0E80D4 7F0B56E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0E80D8 7F0B56E8 8C620028 */  lw    $v0, 0x28($v1)
/* 0E80DC 7F0B56EC 5840000D */  blezl $v0, .L7F0B5724
/* 0E80E0 7F0B56F0 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0E80E4 7F0B56F4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0E80E8 7F0B56F8 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E80EC 7F0B56FC 0FC24116 */  jal   get_debug_joy2detailedit_flag
/* 0E80F0 7F0B5700 AFA00028 */   sw    $zero, 0x28($sp)
/* 0E80F4 7F0B5704 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E80F8 7F0B5708 1040000B */  beqz  $v0, .L7F0B5738
/* 0E80FC 7F0B570C 8FA70028 */   lw    $a3, 0x28($sp)
/* 0E8100 7F0B5710 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0E8104 7F0B5714 254B0400 */  addiu $t3, $t2, 0x400
/* 0E8108 7F0B5718 10000007 */  b     .L7F0B5738
/* 0E810C 7F0B571C AFAB002C */   sw    $t3, 0x2c($sp)
/* 0E8110 7F0B5720 AFA3001C */  sw    $v1, 0x1c($sp)
.L7F0B5724:
/* 0E8114 7F0B5724 0C0025F4 */  jal   memaGetLongestFree
/* 0E8118 7F0B5728 AFA70028 */   sw    $a3, 0x28($sp)
/* 0E811C 7F0B572C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E8120 7F0B5730 8FA70028 */  lw    $a3, 0x28($sp)
/* 0E8124 7F0B5734 AFA2002C */  sw    $v0, 0x2c($sp)
.L7F0B5738:
/* 0E8128 7F0B5738 8FA4002C */  lw    $a0, 0x2c($sp)
/* 0E812C 7F0B573C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E8130 7F0B5740 0C0024A5 */  jal   memaAlloc
/* 0E8134 7F0B5744 AFA70028 */   sw    $a3, 0x28($sp)
/* 0E8138 7F0B5748 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E813C 7F0B574C 8FA70028 */  lw    $a3, 0x28($sp)
/* 0E8140 7F0B5750 10400067 */  beqz  $v0, .L7F0B58F0
/* 0E8144 7F0B5754 AFA20020 */   sw    $v0, 0x20($sp)
/* 0E8148 7F0B5758 8C6C0010 */  lw    $t4, 0x10($v1)
/* 0E814C 7F0B575C 8FA40030 */  lw    $a0, 0x30($sp)
/* 0E8150 7F0B5760 00402825 */  move  $a1, $v0
/* 0E8154 7F0B5764 1180000E */  beqz  $t4, .L7F0B57A0
/* 0E8158 7F0B5768 8FA6002C */   lw    $a2, 0x2c($sp)
/* 0E815C 7F0B576C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E8160 7F0B5770 0FC2D4BA */  jal   sub_GAME_7F0B5FAC
/* 0E8164 7F0B5774 AFA70028 */   sw    $a3, 0x28($sp)
/* 0E8168 7F0B5778 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E816C 7F0B577C 0440000A */  bltz  $v0, .L7F0B57A8
/* 0E8170 7F0B5780 8FA70028 */   lw    $a3, 0x28($sp)
/* 0E8174 7F0B5784 8FA40030 */  lw    $a0, 0x30($sp)
/* 0E8178 7F0B5788 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E817C 7F0B578C 0FC2EB5E */  jal   redarken_lights_in_room
/* 0E8180 7F0B5790 AFA20028 */   sw    $v0, 0x28($sp)
/* 0E8184 7F0B5794 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E8188 7F0B5798 10000003 */  b     .L7F0B57A8
/* 0E818C 7F0B579C 8FA70028 */   lw    $a3, 0x28($sp)
.L7F0B57A0:
/* 0E8190 7F0B57A0 AC600004 */  sw    $zero, 4($v1)
/* 0E8194 7F0B57A4 AC60001C */  sw    $zero, 0x1c($v1)
.L7F0B57A8:
/* 0E8198 7F0B57A8 8C6D0014 */  lw    $t5, 0x14($v1)
/* 0E819C 7F0B57AC 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0E81A0 7F0B57B0 8FA40030 */  lw    $a0, 0x30($sp)
/* 0E81A4 7F0B57B4 11A0000A */  beqz  $t5, .L7F0B57E0
/* 0E81A8 7F0B57B8 01C72821 */   addu  $a1, $t6, $a3
/* 0E81AC 7F0B57BC 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0E81B0 7F0B57C0 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E81B4 7F0B57C4 AFA70028 */  sw    $a3, 0x28($sp)
/* 0E81B8 7F0B57C8 0FC2D4F6 */  jal   sub_GAME_7F0B609C
/* 0E81BC 7F0B57CC 01E73023 */   subu  $a2, $t7, $a3
/* 0E81C0 7F0B57D0 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E81C4 7F0B57D4 04400002 */  bltz  $v0, .L7F0B57E0
/* 0E81C8 7F0B57D8 8FA70028 */   lw    $a3, 0x28($sp)
/* 0E81CC 7F0B57DC 00E23821 */  addu  $a3, $a3, $v0
.L7F0B57E0:
/* 0E81D0 7F0B57E0 8C780018 */  lw    $t8, 0x18($v1)
/* 0E81D4 7F0B57E4 8FB90020 */  lw    $t9, 0x20($sp)
/* 0E81D8 7F0B57E8 8FA40030 */  lw    $a0, 0x30($sp)
/* 0E81DC 7F0B57EC 1300000B */  beqz  $t8, .Leu7F0B581C
/* 0E81E0 7F0B57F0 03272821 */   addu  $a1, $t9, $a3
/* 0E81E4 7F0B57F4 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0E81E8 7F0B57F8 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E81EC 7F0B57FC AFA70028 */  sw    $a3, 0x28($sp)
/* 0E81F0 7F0B5800 0FC2D546 */  jal   sub_GAME_7F0B61DC
/* 0E81F4 7F0B5804 01073023 */   subu  $a2, $t0, $a3
/* 0E81F8 7F0B5808 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E81FC 7F0B580C 18400004 */  blez  $v0, .L7F0B5820
/* 0E8200 7F0B5810 8FA70028 */   lw    $a3, 0x28($sp)
/* 0E8204 7F0B5814 10000002 */  b     .L7F0B5820
/* 0E8208 7F0B5818 00E23821 */   addu  $a3, $a3, $v0
.Leu7F0B581C:
/* 0E820C 7F0B581C AC60000C */  sw    $zero, 0xc($v1)
.L7F0B5820:
/* 0E8210 7F0B5820 8FAB002C */  lw    $t3, 0x2c($sp)
/* 0E8214 7F0B5824 24E20020 */  addiu $v0, $a3, 0x20
/* 0E8218 7F0B5828 2401FFF0 */  li    $at, -16
/* 0E821C 7F0B582C 00414824 */  and   $t1, $v0, $at
/* 0E8220 7F0B5830 240A0001 */  li    $t2, 1
/* 0E8224 7F0B5834 AC690028 */  sw    $t1, 0x28($v1)
/* 0E8228 7F0B5838 11690007 */  beq   $t3, $t1, .L7F0B5858
/* 0E822C 7F0B583C A06A0002 */   sb    $t2, 2($v1)
/* 0E8230 7F0B5840 8FA40020 */  lw    $a0, 0x20($sp)
/* 0E8234 7F0B5844 01602825 */  move  $a1, $t3
/* 0E8238 7F0B5848 01203025 */  move  $a2, $t1
/* 0E823C 7F0B584C 0C00260F */  jal   memaRealloc
/* 0E8240 7F0B5850 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0E8244 7F0B5854 8FA3001C */  lw    $v1, 0x1c($sp)
.L7F0B5858:
/* 0E8248 7F0B5858 3C0C8007 */  lui   $t4, %hi(g_FogSkyIsEnabled) # $t4, 0x8007
/* 0E824C 7F0B585C 8D8CCF60 */  lw    $t4, %lo(g_FogSkyIsEnabled)($t4)
/* 0E8250 7F0B5860 24060006 */  li    $a2, 6
/* 0E8254 7F0B5864 51800012 */  beql  $t4, $zero, .L7F0B58B0
/* 0E8258 7F0B5868 8C640008 */   lw    $a0, 8($v1)
/* 0E825C 7F0B586C 8C640008 */  lw    $a0, 8($v1)
/* 0E8260 7F0B5870 8C6D0020 */  lw    $t5, 0x20($v1)
/* 0E8264 7F0B5874 24060001 */  li    $a2, 1
/* 0E8268 7F0B5878 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E826C 7F0B587C 0FC2E638 */  jal   bgLoadFromDynamicCCRMLUT
/* 0E8270 7F0B5880 01A42821 */   addu  $a1, $t5, $a0
/* 0E8274 7F0B5884 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E8278 7F0B5888 8C64000C */  lw    $a0, 0xc($v1)
/* 0E827C 7F0B588C 10800014 */  beqz  $a0, .L7F0B58E0
/* 0E8280 7F0B5890 00000000 */   nop
/* 0E8284 7F0B5894 8C6E0024 */  lw    $t6, 0x24($v1)
/* 0E8288 7F0B5898 24060005 */  li    $a2, 5
/* 0E828C 7F0B589C 0FC2E638 */  jal   bgLoadFromDynamicCCRMLUT
/* 0E8290 7F0B58A0 01C42821 */   addu  $a1, $t6, $a0
/* 0E8294 7F0B58A4 1000000E */  b     .L7F0B58E0
/* 0E8298 7F0B58A8 00000000 */   nop
/* 0E829C 7F0B58AC 8C640008 */  lw    $a0, 8($v1)
.L7F0B58B0:
/* 0E82A0 7F0B58B0 8C6F0020 */  lw    $t7, 0x20($v1)
/* 0E82A4 7F0B58B4 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0E82A8 7F0B58B8 0FC2E638 */  jal   bgLoadFromDynamicCCRMLUT
/* 0E82AC 7F0B58BC 01E42821 */   addu  $a1, $t7, $a0
/* 0E82B0 7F0B58C0 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E82B4 7F0B58C4 8C64000C */  lw    $a0, 0xc($v1)
/* 0E82B8 7F0B58C8 10800005 */  beqz  $a0, .L7F0B58E0
/* 0E82BC 7F0B58CC 00000000 */   nop
/* 0E82C0 7F0B58D0 8C780024 */  lw    $t8, 0x24($v1)
/* 0E82C4 7F0B58D4 24060007 */  li    $a2, 7
/* 0E82C8 7F0B58D8 0FC2E638 */  jal   bgLoadFromDynamicCCRMLUT
/* 0E82CC 7F0B58DC 03042821 */   addu  $a1, $t8, $a0
.L7F0B58E0:
/* 0E82D0 7F0B58E0 0FC2D734 */  jal   sub_GAME_7F0B6994
/* 0E82D4 7F0B58E4 8FA40030 */   lw    $a0, 0x30($sp)
/* 0E82D8 7F0B58E8 0FC2D485 */  jal   roomsHandleStateDebugging
/* 0E82DC 7F0B58EC 00000000 */   nop
.L7F0B58F0:
/* 0E82E0 7F0B58F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0B58F4:
/* 0E82E4 7F0B58F4 27BD0030 */  addiu $sp, $sp, 0x30
/* 0E82E8 7F0B58F8 03E00008 */  jr    $ra
/* 0E82EC 7F0B58FC 00000000 */   nop
)
#endif

#endif


#ifdef NONMATCHING
void delete_room_data(s32 roomID)
{

    if (g_BgRoomInfo[roomID].ptr_unique_collision_points)
    {
        memaFree(g_BgRoomInfo[roomID].ptr_unique_collision_points, (((s16)g_BgRoomInfo[roomID].bitflags3 * 0x1C) + 0xF) & ~0xF);
        g_BgRoomInfo[roomID].ptr_unique_collision_points = 0;
    }

    if ( 0 < g_BgRoomInfo[roomID].cur_room_totalsize)
    {
        if (g_BgRoomInfo[roomID].ptr_point_index)
        {
            memaFree(g_BgRoomInfo[roomID].ptr_point_index, g_BgRoomInfo[roomID].cur_room_totalsize);
        }
        else
        {
            memaFree(g_BgRoomInfo[roomID].ptr_expanded_mapping_info, g_BgRoomInfo[roomID].cur_room_totalsize);
        }
        g_BgRoomInfo[roomID].ptr_point_index = 0;
        g_BgRoomInfo[roomID].ptr_expanded_mapping_info = 0;
        g_BgRoomInfo[roomID].ptr_secondary_expanded_mapping_info = 0;
    }
    g_BgRoomInfo[roomID].model_bin_loaded = 0;
    roomsHandleStateDebugging();
}
#else
GLOBAL_ASM(
.text
glabel delete_room_data
/* 0EB0F4 7F0B65C4 00047080 */  sll   $t6, $a0, 2
/* 0EB0F8 7F0B65C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EB0FC 7F0B65CC 01C47021 */  addu  $t6, $t6, $a0
/* 0EB100 7F0B65D0 3C0F8004 */  lui   $t7, %hi(g_BgRoomInfo)
/* 0EB104 7F0B65D4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EB108 7F0B65D8 25EF1414 */  addiu $t7, %lo(g_BgRoomInfo) # addiu $t7, $t7, 0x1414
/* 0EB10C 7F0B65DC 000E7100 */  sll   $t6, $t6, 4
/* 0EB110 7F0B65E0 01CF8021 */  addu  $s0, $t6, $t7
/* 0EB114 7F0B65E4 8E06002C */  lw    $a2, 0x2c($s0)
/* 0EB118 7F0B65E8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EB11C 7F0B65EC 50C0000D */  beql  $a2, $zero, .L7F0B6624
/* 0EB120 7F0B65F0 8E020028 */   lw    $v0, 0x28($s0)
/* 0EB124 7F0B65F4 86050030 */  lh    $a1, 0x30($s0)
/* 0EB128 7F0B65F8 2401FFF0 */  li    $at, -16
/* 0EB12C 7F0B65FC 00C02025 */  move  $a0, $a2
/* 0EB130 7F0B6600 0005C0C0 */  sll   $t8, $a1, 3
/* 0EB134 7F0B6604 0305C023 */  subu  $t8, $t8, $a1
/* 0EB138 7F0B6608 0018C080 */  sll   $t8, $t8, 2
/* 0EB13C 7F0B660C 2705000F */  addiu $a1, $t8, 0xf
/* 0EB140 7F0B6610 00A1C824 */  and   $t9, $a1, $at
/* 0EB144 7F0B6614 0C002808 */  jal   memaFree
/* 0EB148 7F0B6618 03202825 */   move  $a1, $t9
/* 0EB14C 7F0B661C AE00002C */  sw    $zero, 0x2c($s0)
/* 0EB150 7F0B6620 8E020028 */  lw    $v0, 0x28($s0)
.L7F0B6624:
/* 0EB154 7F0B6624 1840000E */  blez  $v0, .L7F0B6660
/* 0EB158 7F0B6628 00000000 */   nop
/* 0EB15C 7F0B662C 8E040004 */  lw    $a0, 4($s0)
/* 0EB160 7F0B6630 00402825 */  move  $a1, $v0
/* 0EB164 7F0B6634 10800005 */  beqz  $a0, .L7F0B664C
/* 0EB168 7F0B6638 00000000 */   nop
/* 0EB16C 7F0B663C 0C002808 */  jal   memaFree
/* 0EB170 7F0B6640 00402825 */   move  $a1, $v0
/* 0EB174 7F0B6644 10000004 */  b     .L7F0B6658
/* 0EB178 7F0B6648 AE000004 */   sw    $zero, 4($s0)
.L7F0B664C:
/* 0EB17C 7F0B664C 0C002808 */  jal   memaFree
/* 0EB180 7F0B6650 8E040008 */   lw    $a0, 8($s0)
/* 0EB184 7F0B6654 AE000004 */  sw    $zero, 4($s0)
.L7F0B6658:
/* 0EB188 7F0B6658 AE000008 */  sw    $zero, 8($s0)
/* 0EB18C 7F0B665C AE00000C */  sw    $zero, 0xc($s0)
.L7F0B6660:
/* 0EB190 7F0B6660 0FC2D7B6 */  jal   roomsHandleStateDebugging
/* 0EB194 7F0B6664 A2000002 */   sb    $zero, 2($s0)
/* 0EB198 7F0B6668 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EB19C 7F0B666C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EB1A0 7F0B6670 27BD0020 */  addiu $sp, $sp, 0x20
/* 0EB1A4 7F0B6674 03E00008 */  jr    $ra
/* 0EB1A8 7F0B6678 00000000 */   nop
)
#endif






void unload_rooms(void)
{
    s32 i;

    for(i = 1; i < g_MaxNumRooms; i++)
    {
        if (g_BgRoomInfo[i].model_bin_loaded)
        {
            delete_room_data(i);
        }
    }
}



void sub_GAME_7F0B66E8(void)
{
    s32 i;

    for(i = 1; i < g_MaxNumRooms; i++)
    {
        if (g_BgRoomInfo[i].field_35 == 0)
        {
            if (g_BgRoomInfo[i].model_bin_loaded == 4)
            {
                delete_room_data(i);
            }
            else if (g_BgRoomInfo[i].model_bin_loaded != 0)
            {
                g_BgRoomInfo[i].model_bin_loaded = g_BgRoomInfo[i].model_bin_loaded + 1;
            }
        }
 }
}





/**
 * Address 0x7F0B677C.
*/
Gfx *sub_GAME_7F0B677C(Gfx *arg0, s32 room_index)
{
    if (room_index >= g_MaxNumRooms)
    {
        return arg0;
    }

    if ((D_8004485C != 0) || (D_80044858 == (room_index % 10)))
    {
        if (g_BgRoomInfo[room_index].model_bin_loaded == 0)
        {
            if (D_800442F8 > 0)
            {
                D_800442F8--;
                sub_GAME_7F0B6368(room_index);
            }
        }

        if (g_BgRoomInfo[room_index].model_bin_loaded == 0)
        {
            return arg0;
        }
        else
        {
            arg0 = applyRoomMatrixToDisplayList(arg0, room_index);

            gSPSegment(arg0++, SPSEGMENT_BG_VTX, OS_K0_TO_PHYSICAL(g_BgRoomInfo[room_index].ptr_point_index));
            gSPDisplayList(arg0++, OS_K0_TO_PHYSICAL(g_BgRoomInfo[room_index].ptr_expanded_mapping_info));

            g_BgRoomInfo[room_index].model_bin_loaded = 1;
        }
    }

    return arg0;
}



/**
 * Address 0x7F0B6898.
*/
Gfx *sub_GAME_7F0B6898(Gfx *arg0, s32 room_index)
{
    if (room_index >= g_MaxNumRooms)
    {
        return arg0;
    }

    if (g_BgRoomInfo[room_index].ptr_secondary_expanded_mapping_info == 0)
    {
        return arg0;
    }
    else if ((D_8004485C != 0) || (D_80044858 == (room_index % 10)))
    {
        if (g_BgRoomInfo[room_index].model_bin_loaded != 0)
        {
            arg0 = applyRoomMatrixToDisplayList(arg0, room_index);

            gSPSegment(arg0++, SPSEGMENT_BG_VTX, OS_K0_TO_PHYSICAL(g_BgRoomInfo[room_index].ptr_point_index));
            gSPDisplayList(arg0++, OS_K0_TO_PHYSICAL(g_BgRoomInfo[room_index].ptr_secondary_expanded_mapping_info));

            g_BgRoomInfo[room_index].model_bin_loaded = 1;
        }
        else
        {
            sub_GAME_7F0B6368(room_index);
        }
    }

    return arg0;
}



#ifdef NONMATCHING
/*
* Is this related to room collisions? (for bullets)
* Address: 7F0B6994
*/
void sub_GAME_7F0B6994(s32 arg0) {
    s32 sp24;
    s32 sp3C;
    s32 sp44;
    void *temp_a1;
    s32 temp_v1_8;
    s32 temp_t8;
    ? temp_ret;
    void *temp_a0;
    s32 temp_t2;
    s32 temp_a2;
    void *temp_v1;
    s32 temp_a3;
    s32 temp_v1_2;
    s32 temp_a2_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_9;
    s32 phi_v1;
    void *phi_t3;
    s32 phi_t5;
    s32 phi_v1_2;
    s16 phi_ra;
    s32 phi_t5_2;
    void *phi_v1_3;
    s32 phi_a2;
    void *phi_t3_2;
    void *phi_a1;
    s32 phi_a2_2;
    s32 phi_t5_3;
    s32 phi_t5_4;

    // Node 0
    temp_a1 = ((arg0 * 0x50) + &g_BgRoomInfo);
    if (temp_a1->unk2C == 0)
    {
        // Node 1
        sp44 = (s32) temp_a1->unk4;
        phi_t5 = 0;
        if (-0x48 != *temp_a1->unk8)
        {
            // Node 2
            phi_v1 = *temp_a1->unk8;
            phi_t3 = temp_a1->unk8;
            phi_t5_4 = 0;
loop_3:
            // Node 3
            phi_t5_3 = phi_t5_4;
            if (4 == phi_v1)
            {
                // Node 4
                phi_t5_3 = (phi_t5_4 + 1);
            }
            // Node 5
            temp_v1_8 = phi_t3->unk8;
            phi_v1 = temp_v1_8;
            phi_t3 = (phi_t3 + 8);
            phi_t5 = phi_t5_3;
            phi_t5_4 = phi_t5_3;
            if (-0x48 != temp_v1_8)
            {
                goto loop_3;
            }
        }
        // Node 6
        temp_t8 = (((((phi_t5 * 8) - phi_t5) * 4) + 0xf) & -0x10);
        sp24 = temp_t8;
        sp3C = (s32) phi_t5;
        temp_ret = memaAlloc(temp_t8, temp_a1, temp_a1->unk8);
        if (temp_ret != 0)
        {
            // Node 7
            sp28->unk2C = temp_ret;
            sp28->unk30 = (s16) phi_t5;
            if (-0x48 != *sp48)
            {
                // Node 8
                phi_v1_2 = *sp48;
                phi_ra = (u16)0;
                phi_t5_2 = 0;
                phi_t3_2 = sp48;
loop_9:
                // Node 9
                phi_t5_2 = phi_t5_2;
                if (4 == phi_v1_2)
                {
                    // Node 10
                    temp_a0 = (temp_ret + (((phi_t5_2 * 8) - phi_t5_2) * 4));
                    *temp_a0 = (s16) phi_ra;
                    temp_t2 = (arg0 * 0x18);
                    phi_v1_3 = (temp_ret + (((phi_t5_2 * 8) - phi_t5_2) * 4));
                    phi_a2 = 0;
loop_11:
                    // Node 11
                    temp_a2 = (phi_a2 + 1);
                    temp_v1 = (phi_v1_3 + 4);
                    *temp_v1 = 0x7fff;
                    temp_v1->unkC = -0x8000;
                    phi_v1_3 = temp_v1;
                    phi_a2 = temp_a2;
                    if (temp_a2 < 3)
                    {
                        goto loop_11;
                    }
                    // Node 12
                    temp_a3 = ((((u32) phi_t3_2->unk1 >> 4) & 0xf) + 1);
                    if (temp_a3 > 0)
                    {
                        // Node 13
                        phi_a1 = ((phi_t3_2->unk4 & 0xffffff) + sp44);
                        phi_a2_2 = 0;
loop_14:
                        // Node 14
                        temp_v1_2 = *phi_a1;
                        temp_a2_2 = (phi_a2_2 + 1);
                        if (temp_v1_2 < temp_a0->unk4)
                        {
                            // Node 15
                            temp_a0->unk4 = temp_v1_2;
                        }
                        // Node 16
                        temp_v1_3 = phi_a1->unk2;
                        if (temp_v1_3 < temp_a0->unk8)
                        {
                            // Node 17
                            temp_a0->unk8 = temp_v1_3;
                        }
                        // Node 18
                        temp_v1_4 = phi_a1->unk4;
                        if (temp_v1_4 < temp_a0->unkC)
                        {
                            // Node 19
                            temp_a0->unkC = temp_v1_4;
                        }
                        // Node 20
                        temp_v1_5 = *phi_a1;
                        if (temp_a0->unk10 < temp_v1_5)
                        {
                            // Node 21
                            temp_a0->unk10 = temp_v1_5;
                        }
                        // Node 22
                        temp_v1_6 = phi_a1->unk2;
                        if (temp_a0->unk14 < temp_v1_6)
                        {
                            // Node 23
                            temp_a0->unk14 = temp_v1_6;
                        }
                        // Node 24
                        temp_v1_7 = phi_a1->unk4;
                        if (temp_a0->unk18 < temp_v1_7)
                        {
                            // Node 25
                            temp_a0->unk18 = temp_v1_7;
                        }
                        // Node 26
                        phi_a1 = (phi_a1 + 0x10);
                        phi_a2_2 = temp_a2_2;
                        if (temp_a2_2 != temp_a3)
                        {
                            goto loop_14;
                        }
                    }
                    // Node 27
                    if (temp_a0->unk4 == temp_a0->unk10)
                    {
                        // Node 28
                        temp_a0->unk10 = (s32) (temp_a0->unk10 + 1);
                    }
                    // Node 29
                    if (temp_a0->unk8 == temp_a0->unk14)
                    {
                        // Node 30
                        temp_a0->unk14 = (s32) (temp_a0->unk14 + 1);
                    }
                    // Node 31
                    if (temp_a0->unkC == temp_a0->unk18)
                    {
                        // Node 32
                        temp_a0->unk18 = (s32) (temp_a0->unk18 + 1);
                    }
                    // Node 33
                    temp_a0->unk4 = (s32) (temp_a0->unk4 + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unkC);
                    temp_a0->unk8 = (s32) (temp_a0->unk8 + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unk10);
                    temp_a0->unkC = (s32) (temp_a0->unkC + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unk14);
                    temp_a0->unk10 = (s32) (temp_a0->unk10 + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unkC);
                    temp_a0->unk14 = (s32) (temp_a0->unk14 + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unk10);
                    temp_a0->unk18 = (s32) (temp_a0->unk18 + (s32) (ptr_bgdata_room_fileposition_list + temp_t2)->unk14);
                    phi_t5_2 = (phi_t5_2 + 1);
                }
                // Node 34
                temp_v1_9 = phi_t3_2->unk8;
                phi_v1_2 = temp_v1_9;
                phi_ra = (phi_ra + 1);
                phi_t3_2 = (phi_t3_2 + 8);
                if (-0x48 != temp_v1_9)
                {
                    goto loop_9;
                }
            }
        }
    }
    // Node 35
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B6994
/* 0EB4C4 7F0B6994 00047880 */  sll   $t7, $a0, 2
/* 0EB4C8 7F0B6998 01E47821 */  addu  $t7, $t7, $a0
/* 0EB4CC 7F0B699C 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EB4D0 7F0B69A0 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EB4D4 7F0B69A4 000F7900 */  sll   $t7, $t7, 4
/* 0EB4D8 7F0B69A8 01F82821 */  addu  $a1, $t7, $t8
/* 0EB4DC 7F0B69AC 8CB9002C */  lw    $t9, 0x2c($a1)
/* 0EB4E0 7F0B69B0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0EB4E4 7F0B69B4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EB4E8 7F0B69B8 AFB10018 */  sw    $s1, 0x18($sp)
/* 0EB4EC 7F0B69BC AFB00014 */  sw    $s0, 0x14($sp)
/* 0EB4F0 7F0B69C0 172000C5 */  bnez  $t9, .L7F0B6CD8
/* 0EB4F4 7F0B69C4 AFA40050 */   sw    $a0, 0x50($sp)
/* 0EB4F8 7F0B69C8 8CAE0004 */  lw    $t6, 4($a1)
/* 0EB4FC 7F0B69CC 8CA60008 */  lw    $a2, 8($a1)
/* 0EB500 7F0B69D0 2410FFB8 */  li    $s0, -72
/* 0EB504 7F0B69D4 AFAE0044 */  sw    $t6, 0x44($sp)
/* 0EB508 7F0B69D8 80CF0000 */  lb    $t7, ($a2)
/* 0EB50C 7F0B69DC 00006825 */  move  $t5, $zero
/* 0EB510 7F0B69E0 2401FFF0 */  li    $at, -16
/* 0EB514 7F0B69E4 120F000A */  beq   $s0, $t7, .L7F0B6A10
/* 0EB518 7F0B69E8 00C05825 */   move  $t3, $a2
/* 0EB51C 7F0B69EC 80C30000 */  lb    $v1, ($a2)
/* 0EB520 7F0B69F0 24110004 */  li    $s1, 4
.L7F0B69F4:
/* 0EB524 7F0B69F4 56230003 */  bnel  $s1, $v1, .L7F0B6A04
/* 0EB528 7F0B69F8 81630008 */   lb    $v1, 8($t3)
/* 0EB52C 7F0B69FC 25AD0001 */  addiu $t5, $t5, 1
/* 0EB530 7F0B6A00 81630008 */  lb    $v1, 8($t3)
.L7F0B6A04:
/* 0EB534 7F0B6A04 256B0008 */  addiu $t3, $t3, 8
/* 0EB538 7F0B6A08 1603FFFA */  bne   $s0, $v1, .L7F0B69F4
/* 0EB53C 7F0B6A0C 00000000 */   nop
.L7F0B6A10:
/* 0EB540 7F0B6A10 000D20C0 */  sll   $a0, $t5, 3
/* 0EB544 7F0B6A14 008D2023 */  subu  $a0, $a0, $t5
/* 0EB548 7F0B6A18 00042080 */  sll   $a0, $a0, 2
/* 0EB54C 7F0B6A1C 2484000F */  addiu $a0, $a0, 0xf
/* 0EB550 7F0B6A20 0081C024 */  and   $t8, $a0, $at
/* 0EB554 7F0B6A24 24110004 */  li    $s1, 4
/* 0EB558 7F0B6A28 03002025 */  move  $a0, $t8
/* 0EB55C 7F0B6A2C AFB80024 */  sw    $t8, 0x24($sp)
/* 0EB560 7F0B6A30 AFA50028 */  sw    $a1, 0x28($sp)
/* 0EB564 7F0B6A34 AFA60048 */  sw    $a2, 0x48($sp)
/* 0EB568 7F0B6A38 0C00278D */  jal   memaAlloc
/* 0EB56C 7F0B6A3C AFAD003C */   sw    $t5, 0x3c($sp)
/* 0EB570 7F0B6A40 8FA50028 */  lw    $a1, 0x28($sp)
/* 0EB574 7F0B6A44 8FA60048 */  lw    $a2, 0x48($sp)
/* 0EB578 7F0B6A48 104000A3 */  beqz  $v0, .L7F0B6CD8
/* 0EB57C 7F0B6A4C 8FAD003C */   lw    $t5, 0x3c($sp)
/* 0EB580 7F0B6A50 ACA2002C */  sw    $v0, 0x2c($a1)
/* 0EB584 7F0B6A54 A4AD0030 */  sh    $t5, 0x30($a1)
/* 0EB588 7F0B6A58 80D90000 */  lb    $t9, ($a2)
/* 0EB58C 7F0B6A5C 00006825 */  move  $t5, $zero
/* 0EB590 7F0B6A60 0000F825 */  move  $ra, $zero
/* 0EB594 7F0B6A64 1219009C */  beq   $s0, $t9, .L7F0B6CD8
/* 0EB598 7F0B6A68 00C05825 */   move  $t3, $a2
/* 0EB59C 7F0B6A6C 3C0C8008 */  lui   $t4, %hi(ptr_bgdata_room_fileposition_list)
/* 0EB5A0 7F0B6A70 258CFF8C */  addiu $t4, %lo(ptr_bgdata_room_fileposition_list) # addiu $t4, $t4, -0x74
/* 0EB5A4 7F0B6A74 80C30000 */  lb    $v1, ($a2)
/* 0EB5A8 7F0B6A78 24098000 */  li    $t1, -32768
/* 0EB5AC 7F0B6A7C 24087FFF */  li    $t0, 32767
.L7F0B6A80:
/* 0EB5B0 7F0B6A80 16230090 */  bne   $s1, $v1, .L7F0B6CC4
/* 0EB5B4 7F0B6A84 000D70C0 */   sll   $t6, $t5, 3
/* 0EB5B8 7F0B6A88 01CD7023 */  subu  $t6, $t6, $t5
/* 0EB5BC 7F0B6A8C 000E7080 */  sll   $t6, $t6, 2
/* 0EB5C0 7F0B6A90 004E2021 */  addu  $a0, $v0, $t6
/* 0EB5C4 7F0B6A94 A49F0000 */  sh    $ra, ($a0)
/* 0EB5C8 7F0B6A98 8FAA0050 */  lw    $t2, 0x50($sp)
/* 0EB5CC 7F0B6A9C 000DC0C0 */  sll   $t8, $t5, 3
/* 0EB5D0 7F0B6AA0 030DC023 */  subu  $t8, $t8, $t5
/* 0EB5D4 7F0B6AA4 000A7880 */  sll   $t7, $t2, 2
/* 0EB5D8 7F0B6AA8 0018C080 */  sll   $t8, $t8, 2
/* 0EB5DC 7F0B6AAC 01EA7823 */  subu  $t7, $t7, $t2
/* 0EB5E0 7F0B6AB0 000F50C0 */  sll   $t2, $t7, 3
/* 0EB5E4 7F0B6AB4 00581821 */  addu  $v1, $v0, $t8
/* 0EB5E8 7F0B6AB8 00003025 */  move  $a2, $zero
.L7F0B6ABC:
/* 0EB5EC 7F0B6ABC 24C60001 */  addiu $a2, $a2, 1
/* 0EB5F0 7F0B6AC0 28C10003 */  slti  $at, $a2, 3
/* 0EB5F4 7F0B6AC4 24630004 */  addiu $v1, $v1, 4
/* 0EB5F8 7F0B6AC8 AC680000 */  sw    $t0, ($v1)
/* 0EB5FC 7F0B6ACC 1420FFFB */  bnez  $at, .L7F0B6ABC
/* 0EB600 7F0B6AD0 AC69000C */   sw    $t1, 0xc($v1)
/* 0EB604 7F0B6AD4 91670001 */  lbu   $a3, 1($t3)
/* 0EB608 7F0B6AD8 8D6F0004 */  lw    $t7, 4($t3)
/* 0EB60C 7F0B6ADC 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0EB610 7F0B6AE0 0007C902 */  srl   $t9, $a3, 4
/* 0EB614 7F0B6AE4 332E000F */  andi  $t6, $t9, 0xf
/* 0EB618 7F0B6AE8 8FB90044 */  lw    $t9, 0x44($sp)
/* 0EB61C 7F0B6AEC 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0EB620 7F0B6AF0 25C70001 */  addiu $a3, $t6, 1
/* 0EB624 7F0B6AF4 01E1C024 */  and   $t8, $t7, $at
/* 0EB628 7F0B6AF8 00003025 */  move  $a2, $zero
/* 0EB62C 7F0B6AFC 18E00029 */  blez  $a3, .L7F0B6BA4
/* 0EB630 7F0B6B00 03191821 */   addu  $v1, $t8, $t9
/* 0EB634 7F0B6B04 00602825 */  move  $a1, $v1
.L7F0B6B08:
/* 0EB638 7F0B6B08 84A30000 */  lh    $v1, ($a1)
/* 0EB63C 7F0B6B0C 8C8E0004 */  lw    $t6, 4($a0)
/* 0EB640 7F0B6B10 24C60001 */  addiu $a2, $a2, 1
/* 0EB644 7F0B6B14 006E082A */  slt   $at, $v1, $t6
/* 0EB648 7F0B6B18 50200003 */  beql  $at, $zero, .L7F0B6B28
/* 0EB64C 7F0B6B1C 84A30002 */   lh    $v1, 2($a1)
/* 0EB650 7F0B6B20 AC830004 */  sw    $v1, 4($a0)
/* 0EB654 7F0B6B24 84A30002 */  lh    $v1, 2($a1)
.L7F0B6B28:
/* 0EB658 7F0B6B28 8C8F0008 */  lw    $t7, 8($a0)
/* 0EB65C 7F0B6B2C 006F082A */  slt   $at, $v1, $t7
/* 0EB660 7F0B6B30 50200003 */  beql  $at, $zero, .L7F0B6B40
/* 0EB664 7F0B6B34 84A30004 */   lh    $v1, 4($a1)
/* 0EB668 7F0B6B38 AC830008 */  sw    $v1, 8($a0)
/* 0EB66C 7F0B6B3C 84A30004 */  lh    $v1, 4($a1)
.L7F0B6B40:
/* 0EB670 7F0B6B40 8C98000C */  lw    $t8, 0xc($a0)
/* 0EB674 7F0B6B44 0078082A */  slt   $at, $v1, $t8
/* 0EB678 7F0B6B48 50200003 */  beql  $at, $zero, .L7F0B6B58
/* 0EB67C 7F0B6B4C 84A30000 */   lh    $v1, ($a1)
/* 0EB680 7F0B6B50 AC83000C */  sw    $v1, 0xc($a0)
/* 0EB684 7F0B6B54 84A30000 */  lh    $v1, ($a1)
.L7F0B6B58:
/* 0EB688 7F0B6B58 8C990010 */  lw    $t9, 0x10($a0)
/* 0EB68C 7F0B6B5C 0323082A */  slt   $at, $t9, $v1
/* 0EB690 7F0B6B60 50200003 */  beql  $at, $zero, .L7F0B6B70
/* 0EB694 7F0B6B64 84A30002 */   lh    $v1, 2($a1)
/* 0EB698 7F0B6B68 AC830010 */  sw    $v1, 0x10($a0)
/* 0EB69C 7F0B6B6C 84A30002 */  lh    $v1, 2($a1)
.L7F0B6B70:
/* 0EB6A0 7F0B6B70 8C8E0014 */  lw    $t6, 0x14($a0)
/* 0EB6A4 7F0B6B74 01C3082A */  slt   $at, $t6, $v1
/* 0EB6A8 7F0B6B78 50200003 */  beql  $at, $zero, .L7F0B6B88
/* 0EB6AC 7F0B6B7C 84A30004 */   lh    $v1, 4($a1)
/* 0EB6B0 7F0B6B80 AC830014 */  sw    $v1, 0x14($a0)
/* 0EB6B4 7F0B6B84 84A30004 */  lh    $v1, 4($a1)
.L7F0B6B88:
/* 0EB6B8 7F0B6B88 8C8F0018 */  lw    $t7, 0x18($a0)
/* 0EB6BC 7F0B6B8C 01E3082A */  slt   $at, $t7, $v1
/* 0EB6C0 7F0B6B90 10200002 */  beqz  $at, .L7F0B6B9C
/* 0EB6C4 7F0B6B94 00000000 */   nop
/* 0EB6C8 7F0B6B98 AC830018 */  sw    $v1, 0x18($a0)
.L7F0B6B9C:
/* 0EB6CC 7F0B6B9C 14C7FFDA */  bne   $a2, $a3, .L7F0B6B08
/* 0EB6D0 7F0B6BA0 24A50010 */   addiu $a1, $a1, 0x10
.L7F0B6BA4:
/* 0EB6D4 7F0B6BA4 8C830010 */  lw    $v1, 0x10($a0)
/* 0EB6D8 7F0B6BA8 8C980004 */  lw    $t8, 4($a0)
/* 0EB6DC 7F0B6BAC 24790001 */  addiu $t9, $v1, 1
/* 0EB6E0 7F0B6BB0 57030003 */  bnel  $t8, $v1, .L7F0B6BC0
/* 0EB6E4 7F0B6BB4 8C830014 */   lw    $v1, 0x14($a0)
/* 0EB6E8 7F0B6BB8 AC990010 */  sw    $t9, 0x10($a0)
/* 0EB6EC 7F0B6BBC 8C830014 */  lw    $v1, 0x14($a0)
.L7F0B6BC0:
/* 0EB6F0 7F0B6BC0 8C8E0008 */  lw    $t6, 8($a0)
/* 0EB6F4 7F0B6BC4 246F0001 */  addiu $t7, $v1, 1
/* 0EB6F8 7F0B6BC8 55C30003 */  bnel  $t6, $v1, .L7F0B6BD8
/* 0EB6FC 7F0B6BCC 8C83000C */   lw    $v1, 0xc($a0)
/* 0EB700 7F0B6BD0 AC8F0014 */  sw    $t7, 0x14($a0)
/* 0EB704 7F0B6BD4 8C83000C */  lw    $v1, 0xc($a0)
.L7F0B6BD8:
/* 0EB708 7F0B6BD8 8C850018 */  lw    $a1, 0x18($a0)
/* 0EB70C 7F0B6BDC 14650003 */  bne   $v1, $a1, .L7F0B6BEC
/* 0EB710 7F0B6BE0 24B80001 */   addiu $t8, $a1, 1
/* 0EB714 7F0B6BE4 AC980018 */  sw    $t8, 0x18($a0)
/* 0EB718 7F0B6BE8 8C83000C */  lw    $v1, 0xc($a0)
.L7F0B6BEC:
/* 0EB71C 7F0B6BEC 8D8E0000 */  lw    $t6, ($t4)
/* 0EB720 7F0B6BF0 8C990004 */  lw    $t9, 4($a0)
/* 0EB724 7F0B6BF4 8C980008 */  lw    $t8, 8($a0)
/* 0EB728 7F0B6BF8 01CA7821 */  addu  $t7, $t6, $t2
/* 0EB72C 7F0B6BFC C5E4000C */  lwc1  $f4, 0xc($t7)
/* 0EB730 7F0B6C00 25AD0001 */  addiu $t5, $t5, 1
/* 0EB734 7F0B6C04 4600218D */  trunc.w.s $f6, $f4
/* 0EB738 7F0B6C08 440E3000 */  mfc1  $t6, $f6
/* 0EB73C 7F0B6C0C 00000000 */  nop
/* 0EB740 7F0B6C10 032E7821 */  addu  $t7, $t9, $t6
/* 0EB744 7F0B6C14 AC8F0004 */  sw    $t7, 4($a0)
/* 0EB748 7F0B6C18 8D990000 */  lw    $t9, ($t4)
/* 0EB74C 7F0B6C1C 032A7021 */  addu  $t6, $t9, $t2
/* 0EB750 7F0B6C20 C5C80010 */  lwc1  $f8, 0x10($t6)
/* 0EB754 7F0B6C24 4600428D */  trunc.w.s $f10, $f8
/* 0EB758 7F0B6C28 44195000 */  mfc1  $t9, $f10
/* 0EB75C 7F0B6C2C 00000000 */  nop
/* 0EB760 7F0B6C30 03197021 */  addu  $t6, $t8, $t9
/* 0EB764 7F0B6C34 AC8E0008 */  sw    $t6, 8($a0)
/* 0EB768 7F0B6C38 8D8F0000 */  lw    $t7, ($t4)
/* 0EB76C 7F0B6C3C 01EAC021 */  addu  $t8, $t7, $t2
/* 0EB770 7F0B6C40 C7100014 */  lwc1  $f16, 0x14($t8)
/* 0EB774 7F0B6C44 8C980010 */  lw    $t8, 0x10($a0)
/* 0EB778 7F0B6C48 4600848D */  trunc.w.s $f18, $f16
/* 0EB77C 7F0B6C4C 440E9000 */  mfc1  $t6, $f18
/* 0EB780 7F0B6C50 00000000 */  nop
/* 0EB784 7F0B6C54 006E7821 */  addu  $t7, $v1, $t6
/* 0EB788 7F0B6C58 AC8F000C */  sw    $t7, 0xc($a0)
/* 0EB78C 7F0B6C5C 8D990000 */  lw    $t9, ($t4)
/* 0EB790 7F0B6C60 8C8F0014 */  lw    $t7, 0x14($a0)
/* 0EB794 7F0B6C64 032A7021 */  addu  $t6, $t9, $t2
/* 0EB798 7F0B6C68 C5C4000C */  lwc1  $f4, 0xc($t6)
/* 0EB79C 7F0B6C6C 4600218D */  trunc.w.s $f6, $f4
/* 0EB7A0 7F0B6C70 44193000 */  mfc1  $t9, $f6
/* 0EB7A4 7F0B6C74 00000000 */  nop
/* 0EB7A8 7F0B6C78 03197021 */  addu  $t6, $t8, $t9
/* 0EB7AC 7F0B6C7C AC8E0010 */  sw    $t6, 0x10($a0)
/* 0EB7B0 7F0B6C80 8D980000 */  lw    $t8, ($t4)
/* 0EB7B4 7F0B6C84 8C8E0018 */  lw    $t6, 0x18($a0)
/* 0EB7B8 7F0B6C88 030AC821 */  addu  $t9, $t8, $t2
/* 0EB7BC 7F0B6C8C C7280010 */  lwc1  $f8, 0x10($t9)
/* 0EB7C0 7F0B6C90 4600428D */  trunc.w.s $f10, $f8
/* 0EB7C4 7F0B6C94 44185000 */  mfc1  $t8, $f10
/* 0EB7C8 7F0B6C98 00000000 */  nop
/* 0EB7CC 7F0B6C9C 01F8C821 */  addu  $t9, $t7, $t8
/* 0EB7D0 7F0B6CA0 AC990014 */  sw    $t9, 0x14($a0)
/* 0EB7D4 7F0B6CA4 8D8F0000 */  lw    $t7, ($t4)
/* 0EB7D8 7F0B6CA8 01EAC021 */  addu  $t8, $t7, $t2
/* 0EB7DC 7F0B6CAC C7100014 */  lwc1  $f16, 0x14($t8)
/* 0EB7E0 7F0B6CB0 4600848D */  trunc.w.s $f18, $f16
/* 0EB7E4 7F0B6CB4 440F9000 */  mfc1  $t7, $f18
/* 0EB7E8 7F0B6CB8 00000000 */  nop
/* 0EB7EC 7F0B6CBC 01CFC021 */  addu  $t8, $t6, $t7
/* 0EB7F0 7F0B6CC0 AC980018 */  sw    $t8, 0x18($a0)
.L7F0B6CC4:
/* 0EB7F4 7F0B6CC4 81630008 */  lb    $v1, 8($t3)
/* 0EB7F8 7F0B6CC8 27FF0001 */  addiu $ra, $ra, 1
/* 0EB7FC 7F0B6CCC 256B0008 */  addiu $t3, $t3, 8
/* 0EB800 7F0B6CD0 1603FF6B */  bne   $s0, $v1, .L7F0B6A80
/* 0EB804 7F0B6CD4 00000000 */   nop
.L7F0B6CD8:
/* 0EB808 7F0B6CD8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EB80C 7F0B6CDC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EB810 7F0B6CE0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EB814 7F0B6CE4 03E00008 */  jr    $ra
/* 0EB818 7F0B6CE8 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif


bool bgTestLineIntersectsBbox(coord3d *arg0, coord3d *arg1, s32 *arg2, s32 *arg3)
{
    coord3d arg2f;
    coord3d arg3f;
    u32 stack[4];
    f32 f0;
    f32 f0_2;
    f32 f2;
    f32 f2_2;
    f32 f6;
    f32 f10;
    f32 sp34;
    f32 sp30;
    f32 f16;
    f32 f18;
    f32 f18_2;
    f32 sp20;
    f32 f12;
    f32 f12_2;
    f32 f14;
    f32 f14_2;

    arg2f.f[0] = arg2[0];
    arg2f.f[1] = arg2[1];
    arg2f.f[2] = arg2[2];

    arg3f.f[0] = arg3[0];
    arg3f.f[1] = arg3[1];
    arg3f.f[2] = arg3[2];

    // x
    f18 = arg1->x;
    f16 = arg3f.x - arg0->x;
    f14 = arg2f.x - arg0->x;

    if (f18 < 0.0f)
    {
        f18 = -f18;
        f14 = -f14;
        f16 = -f16;
    }

    if (f14 < 0.0f && f16 < 0.0f)
    {
        return FALSE;
    }

    if (f16 < f14)
    {
        f32 tmp = f14;
        f14 = f16;
        f16 = tmp;
    }

    // y
    f12 = arg1->y;
    f2 = arg3f.y - arg0->y;
    f0 = arg2f.y - arg0->y;

    if (f12 < 0.0f)
    {
        f12 = -f12;
        f0 = -f0;
        f2 = -f2;
    }

    if (f0 < 0.0f && f2 < 0.0f)
    {
        return FALSE;
    }

    if (f2 < f0)
    {
        sp20 = f0;
        f0 = f2;
        f2 = sp20;
    }

    f6 = f14 * f12;
    f10 = f0 * f18;

    if (f10 < f6)
    {
        if (f2 * f18 < f6)
        {
            return FALSE;
        }

        sp34 = f14;
        sp30 = f18;
    }
    else
    {
        if (f16 * f12 < f10)
        {
            return FALSE;
        }

        sp34 = f0;
        sp30 = f12;
    }

    if (f16 * f12 < f2 * f18)
    {
        f0_2 = f16;
        f14_2 = f18;
    }
    else
    {
        f0_2 = f2;
        f14_2 = f12;
    }

    // z
    f2_2 = arg1->z;
    f12_2 = arg3f.z - arg0->z;
    f18_2 = arg2f.z - arg0->z;

    if (f2_2 < 0.0f)
    {
        f2_2 = -f2_2;
        f18_2 = -f18_2;
        f12_2 = -f12_2;
    }

    if (f18_2 < 0.0f && f12_2 < 0.0f)
    {
        return FALSE;
    }

    if (f12_2 < f18_2)
    {
        f32 tmp = f18_2;
        f18_2 = f12_2;
        f12_2 = tmp;
    }

    if (sp34 * f2_2 < f18_2 * sp30)
    {
        if (f0_2 * f2_2 < f18_2 * f14_2)
        {
            return FALSE;
        }
    }
    else
    {
        if (f12_2 * sp30 < sp34 * f2_2)
        {
            return FALSE;
        }
    }

    return TRUE;
}


#ifdef NONMATCHING
?32 bgTestLineIntersectionInRoom(void *arg0, s32 arg1, ?32 arg2, void *arg3, s32 arg4, void *arg5) {
    s32 sp54;
    void *sp64;
    s32 sp80;
    s32 sp84;
    s32 sp88;
    s32 sp8C;
    s32 sp90;
    s32 sp94;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    ? spA8;
    s32 spC8;
    s32 spCC;
    s32 spD0;
    s32 spD4;
    s32 spD8;
    s32 spDC;
    s32 spE4;
    s32 spE8;
    s32 spEC;
    s32 spF0;
    f32 spF8;
    ?32 sp12C;
    void *temp_t0;
    void *temp_s3;
    s32 temp_t2;
    s32 temp_s1;
    void *temp_a0;
    void *temp_v1;
    void *temp_v0;
    void *temp_v0_4;
    u32 temp_v0_5;
    void *temp_a0_2;
    void *temp_v1_2;
    void *temp_v0_2;
    void *temp_v0_6;
    u32 temp_v0_7;
    s32 temp_s5;
    s32 temp_v0_3;
    s32 phi_v0;
    void *phi_s3;
    void *phi_a0;
    void *phi_v0_2;
    void *phi_v0_3;
    s16 phi_s0;
    s32 phi_s5;
    void *phi_a0_2;
    void *phi_t0;
    void *phi_v0_4;
    void *phi_v0_5;
    s16 phi_s0_2;
    void *phi_t0_2;

    // Node 0
    temp_t0 = ((arg4 * 0x50) + &g_BgRoomInfo);
    temp_s3 = ((*arg3 * 8) + temp_t0->unk8);
    spF0 = 0x7fffffff;
    sp12C = 0;
    temp_t2 = (temp_s3->unk1 & 0xf);
    temp_s1 = ((temp_s3->unk4 & 0xffffff) + temp_t0->unk4);
    if (temp_s3->unk8 != 4)
    {
        // Node 1
        if (temp_s3->unk8 != -0x48)
        {
            // Node 2
            sp64 = temp_t0;
            phi_v0 = temp_s3->unk8;
            phi_s3 = (temp_s3 + 8);
            phi_t0_2 = &spA8;
loop_3:
            // Node 3
            if (phi_v0 == -0x41)
            {
                // Node 4
                spD4 = (?32) D_80044868;
                spD4.unk4 = (?32) D_80044868.unk4;
                spD4.unk8 = (?32) D_80044868.unk8;
                spC8 = (?32) D_80044874;
                spC8.unk4 = (?32) D_80044874.unk4;
                spC8.unk8 = (?32) D_80044874.unk8;
                spE4 = (s32) (((s32) phi_s3->unk5 / 0xa) - temp_t2);
                spE8 = (s32) (((s32) phi_s3->unk6 / 0xa) - temp_t2);
                spEC = (s32) (((s32) phi_s3->unk7 / 0xa) - temp_t2);
                sp54 = (s32) (arg4 * 0x18);
                phi_a0 = &spE4;
loop_5:
                // Node 5
                temp_a0 = (phi_a0 + 4);
                temp_v1 = (temp_s1 + (*phi_a0 * 0x10));
                if (*temp_v1 < spD4)
                {
                    // Node 6
                    spD4 = (s32) *temp_v1;
                }
                // Node 7
                if (spC8 < *temp_v1)
                {
                    // Node 8
                    spC8 = (s32) *temp_v1;
                }
                // Node 9
                if (temp_v1->unk2 < spD8)
                {
                    // Node 10
                    spD8 = (s32) temp_v1->unk2;
                }
                // Node 11
                if (spCC < temp_v1->unk2)
                {
                    // Node 12
                    spCC = (s32) temp_v1->unk2;
                }
                // Node 13
                if (temp_v1->unk4 < spDC)
                {
                    // Node 14
                    spDC = (s32) temp_v1->unk4;
                }
                // Node 15
                if (spD0 < temp_v1->unk4)
                {
                    // Node 16
                    spD0 = (s32) temp_v1->unk4;
                }
                // Node 17
                phi_a0 = temp_a0;
                if (temp_a0 != &spF0)
                {
                    goto loop_5;
                }
                // Node 18
                temp_v0 = (ptr_bgdata_room_fileposition_list + sp54);
                spD4 = (s32) (spD4 + (s32) temp_v0->unkC);
                spD8 = (s32) (spD8 + (s32) temp_v0->unk10);
                spDC = (s32) (spDC + (s32) temp_v0->unk14);
                spC8 = (s32) (spC8 + (s32) temp_v0->unkC);
                spCC = (s32) (spCC + (s32) temp_v0->unk10);
                spD0 = (s32) (spD0 + (s32) temp_v0->unk14);
                phi_t0_2 = &spA8;
                if (bgTestLineIntersectsBbox(arg0, arg2, &spD4, &spC8) != 0)
                {
                    // Node 19
                    phi_t0_2 = &spA8;
                    if (intersectLineTriangle((temp_s1 + (spE4 * 0x10)), (temp_s1 + (spE8 * 0x10)), (temp_s1 + (spEC * 0x10)), ((sp54 + ptr_bgdata_room_fileposition_list) + 0xc), arg0, arg1, arg2, &spF8) != 0)
                    {
                        // Node 20
                        temp_v0_4 = phi_s3;
                        sp12C = 1;
                        phi_v0_3 = temp_v0_4;
                        if (0xfd != *phi_s3)
                        {
                            // Node 21
                            phi_v0_2 = temp_v0_4;
                            phi_v0_3 = temp_v0_4;
                            if ((u32) sp64->unk8 < (u32) phi_s3)
                            {
loop_22:
                                // Node 22
                                temp_v0_5 = (phi_v0_2 + -8);
                                phi_v0_3 = temp_v0_5;
                                if (0xfd != phi_v0_2->unk-8)
                                {
                                    // Node 23
                                    phi_v0_2 = temp_v0_5;
                                    phi_v0_3 = temp_v0_5;
                                    if ((u32) sp64->unk8 < temp_v0_5)
                                    {
                                        goto loop_22;
                                    }
                                }
                            }
                        }
                        // Node 24
                        if (phi_v0_3 == sp64->unk8)
                        {
                            // Node 25
                            phi_s0 = (u16)-1;
                        }
                        else
                        {
                            // Node 26
                            phi_s0 = *((phi_v0_3->unk4 + -8) | 0x80000000);
                        }
                        // Node 27
                        if (check_if_imageID_is_light(phi_s0, ((s32) sp100 - (s32) arg0->unk8), arg0) != 0)
                        {
                            // Node 28
                        }
                        // Node 29
                        phi_t0_2 = &spA8;
                        if (0x4fd != 0)
                        {
                            // Node 30
                            phi_t0_2 = &spA8;
                            if (phi_s0 != 0x4fd)
                            {
                                // Node 31
                                *arg5 = spF8;
                                arg5->unk4 = spFC;
                                arg5->unk8 = sp100;
                                arg5->unkC = sp104;
                                arg5->unk10 = sp108;
                                arg5->unk14 = sp10C;
                                arg5->unk18 = (s32) ((spE4 * 0x10) + temp_s1);
                                arg5->unk1C = (s32) ((spE8 * 0x10) + temp_s1);
                                arg5->unk2A = (s16) phi_s0;
                                arg5->unk24 = (void *) phi_s3;
                                arg5->unk20 = (s32) ((spEC * 0x10) + temp_s1);
                                arg5->unk28 = (u16)0;
                                phi_t0_2 = &spA8;
                            }
                        }
                    }
                }
            }
            else
            {
                // Node 32
                phi_t0_2 = phi_t0_2;
                if (phi_v0 == -0x4f)
                {
                    // Node 33
                    sp54 = (s32) (arg4 * 0x18);
                    phi_s5 = 0;
                    phi_t0 = phi_t0_2;
loop_34:
                    // Node 34
                    sp8C = (?32) D_80044880;
                    sp8C.unk4 = (?32) D_80044880.unk4;
                    sp8C.unk8 = (?32) D_80044880.unk8;
                    sp80 = (?32) D_8004488C;
                    sp80.unk4 = (?32) D_8004488C.unk4;
                    sp80.unk8 = (?32) D_8004488C.unk8;
                    if (phi_s5 == 0)
                    {
                        // Node 35
                        sp9C = (s32) ((phi_s3->unk4 & 0xf) - temp_t2);
                        spA0 = (s32) (((u32) phi_s3->unk7 >> 4) - temp_t2);
                        spA4 = (s32) ((*phi_s3 & 0xf) - temp_t2);
                    }
                    else
                    {
                        // Node 36
                        if (phi_s5 == 1)
                        {
                            // Node 37
                            sp9C = (s32) ((phi_s3->unk6 & 0xf) - temp_t2);
                            spA0 = (s32) (((u32) phi_s3->unk6 >> 0xc) - temp_t2);
                            spA4 = (s32) (((u32) phi_s3->unk3 >> 4) - temp_t2);
                        }
                        else
                        {
                            // Node 38
                            if (phi_s5 == 2)
                            {
                                // Node 39
                                sp9C = (s32) ((phi_s3->unk4 & 0xf) - temp_t2);
                                spA0 = (s32) (((u32) phi_s3->unk5 >> 4) - temp_t2);
                                spA4 = (s32) ((phi_s3->unk2 & 0xf) - temp_t2);
                            }
                            else
                            {
                                // Node 40
                                sp9C = (s32) ((phi_s3->unk4 & 0xf) - temp_t2);
                                spA0 = (s32) (((u32) phi_s3->unk4 >> 0x1c) - temp_t2);
                                spA4 = (s32) (((u32) phi_s3->unk2 >> 0xc) - temp_t2);
                            }
                        }
                    }
                    // Node 41
                    phi_a0_2 = &sp9C;
loop_42:
                    // Node 42
                    temp_a0_2 = (phi_a0_2 + 4);
                    temp_v1_2 = (temp_s1 + (*phi_a0_2 * 0x10));
                    if (*temp_v1_2 < sp8C)
                    {
                        // Node 43
                        sp8C = (s32) *temp_v1_2;
                    }
                    // Node 44
                    if (sp80 < *temp_v1_2)
                    {
                        // Node 45
                        sp80 = (s32) *temp_v1_2;
                    }
                    // Node 46
                    if (temp_v1_2->unk2 < sp90)
                    {
                        // Node 47
                        sp90 = (s32) temp_v1_2->unk2;
                    }
                    // Node 48
                    if (sp84 < temp_v1_2->unk2)
                    {
                        // Node 49
                        sp84 = (s32) temp_v1_2->unk2;
                    }
                    // Node 50
                    if (temp_v1_2->unk4 < sp94)
                    {
                        // Node 51
                        sp94 = (s32) temp_v1_2->unk4;
                    }
                    // Node 52
                    if (sp88 < temp_v1_2->unk4)
                    {
                        // Node 53
                        sp88 = (s32) temp_v1_2->unk4;
                    }
                    // Node 54
                    phi_a0_2 = temp_a0_2;
                    if (temp_a0_2 != phi_t0)
                    {
                        goto loop_42;
                    }
                    // Node 55
                    temp_v0_2 = (ptr_bgdata_room_fileposition_list + sp54);
                    sp8C = (s32) (sp8C + (s32) temp_v0_2->unkC);
                    sp90 = (s32) (sp90 + (s32) temp_v0_2->unk10);
                    sp94 = (s32) (sp94 + (s32) temp_v0_2->unk14);
                    sp80 = (s32) (sp80 + (s32) temp_v0_2->unkC);
                    sp84 = (s32) (sp84 + (s32) temp_v0_2->unk10);
                    sp88 = (s32) (sp88 + (s32) temp_v0_2->unk14);
                    if (bgTestLineIntersectsBbox(arg0, arg2, &sp8C, &sp80) != 0)
                    {
                        // Node 56
                        if (intersectLineTriangle((temp_s1 + (sp9C * 0x10)), (temp_s1 + (spA0 * 0x10)), (temp_s1 + (spA4 * 0x10)), ((sp54 + ptr_bgdata_room_fileposition_list) + 0xc), arg0, arg1, arg2, &spF8) != 0)
                        {
                            // Node 57
                            temp_v0_6 = phi_s3;
                            sp12C = 1;
                            phi_v0_5 = temp_v0_6;
                            if (0xfd != *phi_s3)
                            {
                                // Node 58
                                phi_v0_4 = temp_v0_6;
                                phi_v0_5 = temp_v0_6;
                                if ((u32) sp64->unk8 < (u32) phi_s3)
                                {
loop_59:
                                    // Node 59
                                    temp_v0_7 = (phi_v0_4 + -8);
                                    phi_v0_5 = temp_v0_7;
                                    if (0xfd != phi_v0_4->unk-8)
                                    {
                                        // Node 60
                                        phi_v0_4 = temp_v0_7;
                                        phi_v0_5 = temp_v0_7;
                                        if ((u32) sp64->unk8 < temp_v0_7)
                                        {
                                            goto loop_59;
                                        }
                                    }
                                }
                            }
                            // Node 61
                            if (phi_v0_5 == sp64->unk8)
                            {
                                // Node 62
                                phi_s0_2 = (u16)-1;
                            }
                            else
                            {
                                // Node 63
                                phi_s0_2 = *((phi_v0_5->unk4 + -8) | 0x80000000);
                            }
                            // Node 64
                            if (check_if_imageID_is_light(phi_s0_2, ((s32) sp100 - (s32) arg0->unk8), arg0) != 0)
                            {
                                // Node 65
                            }
                            // Node 66
                            if (0x4fd != 0)
                            {
                                // Node 67
                                if (phi_s0_2 != 0x4fd)
                                {
                                    // Node 68
                                    *arg5 = spF8;
                                    arg5->unk4 = spFC;
                                    arg5->unk8 = sp100;
                                    arg5->unkC = sp104;
                                    arg5->unk10 = sp108;
                                    arg5->unk14 = sp10C;
                                    arg5->unk18 = (s32) ((sp9C * 0x10) + temp_s1);
                                    arg5->unk1C = (s32) ((spA0 * 0x10) + temp_s1);
                                    arg5->unk2A = (s16) phi_s0_2;
                                    arg5->unk24 = (void *) phi_s3;
                                    arg5->unk20 = (s32) ((spA4 * 0x10) + temp_s1);
                                    arg5->unk28 = (s16) (phi_s5 + 1);
                                }
                            }
                        }
                    }
                    // Node 69
                    temp_s5 = (phi_s5 + 1);
                    phi_s5 = temp_s5;
                    phi_t0 = &spA8;
                    phi_t0_2 = &spA8;
                    if (temp_s5 != 4)
                    {
                        goto loop_34;
                    }
                }
            }
            // Node 70
            temp_v0_3 = phi_s3->unk8;
            if (temp_v0_3 != -0x48)
            {
                // Node 71
                phi_v0 = temp_v0_3;
                phi_s3 = (phi_s3 + 8);
                if (temp_v0_3 != -0x48)
                {
                    goto loop_3;
                }
            }
        }
    }
    // Node 72
    return sp12C;
}
#else
GLOBAL_ASM(
.text
glabel bgTestLineIntersectionInRoom
/* 0EBB40 7F0B7010 27BDFEC0 */  addiu $sp, $sp, -0x140
/* 0EBB44 7F0B7014 8FAE0150 */  lw    $t6, 0x150($sp)
/* 0EBB48 7F0B7018 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EBB4C 7F0B701C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0EBB50 7F0B7020 000E7880 */  sll   $t7, $t6, 2
/* 0EBB54 7F0B7024 01EE7821 */  addu  $t7, $t7, $t6
/* 0EBB58 7F0B7028 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0EBB5C 7F0B702C AFB70044 */  sw    $s7, 0x44($sp)
/* 0EBB60 7F0B7030 AFB60040 */  sw    $s6, 0x40($sp)
/* 0EBB64 7F0B7034 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0EBB68 7F0B7038 AFB40038 */  sw    $s4, 0x38($sp)
/* 0EBB6C 7F0B703C AFB30034 */  sw    $s3, 0x34($sp)
/* 0EBB70 7F0B7040 AFB20030 */  sw    $s2, 0x30($sp)
/* 0EBB74 7F0B7044 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0EBB78 7F0B7048 AFB00028 */  sw    $s0, 0x28($sp)
/* 0EBB7C 7F0B704C AFA40140 */  sw    $a0, 0x140($sp)
/* 0EBB80 7F0B7050 AFA50144 */  sw    $a1, 0x144($sp)
/* 0EBB84 7F0B7054 AFA60148 */  sw    $a2, 0x148($sp)
/* 0EBB88 7F0B7058 000F7900 */  sll   $t7, $t7, 4
/* 0EBB8C 7F0B705C 27181414 */  addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EBB90 7F0B7060 84F90000 */  lh    $t9, ($a3)
/* 0EBB94 7F0B7064 01F84021 */  addu  $t0, $t7, $t8
/* 0EBB98 7F0B7068 8D130008 */  lw    $s3, 8($t0)
/* 0EBB9C 7F0B706C 001948C0 */  sll   $t1, $t9, 3
/* 0EBBA0 7F0B7070 3C0D7FFF */  lui   $t5, (0x7FFFFFFF >> 16) # lui $t5, 0x7fff
/* 0EBBA4 7F0B7074 01339821 */  addu  $s3, $t1, $s3
/* 0EBBA8 7F0B7078 8E6B0004 */  lw    $t3, 4($s3)
/* 0EBBAC 7F0B707C 92770001 */  lbu   $s7, 1($s3)
/* 0EBBB0 7F0B7080 35ADFFFF */  ori   $t5, (0x7FFFFFFF & 0xFFFF) # ori $t5, $t5, 0xffff
/* 0EBBB4 7F0B7084 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0EBBB8 7F0B7088 AFAD00F0 */  sw    $t5, 0xf0($sp)
/* 0EBBBC 7F0B708C AFA0012C */  sw    $zero, 0x12c($sp)
/* 0EBBC0 7F0B7090 82620008 */  lb    $v0, 8($s3)
/* 0EBBC4 7F0B7094 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0EBBC8 7F0B7098 8D030004 */  lw    $v1, 4($t0)
/* 0EBBCC 7F0B709C 01616024 */  and   $t4, $t3, $at
/* 0EBBD0 7F0B70A0 24010004 */  li    $at, 4
/* 0EBBD4 7F0B70A4 32EA000F */  andi  $t2, $s7, 0xf
/* 0EBBD8 7F0B70A8 0140B825 */  move  $s7, $t2
/* 0EBBDC 7F0B70AC 26730008 */  addiu $s3, $s3, 8
/* 0EBBE0 7F0B70B0 10410264 */  beq   $v0, $at, .L7F0B7A44
/* 0EBBE4 7F0B70B4 01838821 */   addu  $s1, $t4, $v1
/* 0EBBE8 7F0B70B8 2401FFB8 */  li    $at, -72
/* 0EBBEC 7F0B70BC 10410261 */  beq   $v0, $at, .L7F0B7A44
/* 0EBBF0 7F0B70C0 241600FD */   li    $s6, 253
/* 0EBBF4 7F0B70C4 AFA80064 */  sw    $t0, 0x64($sp)
/* 0EBBF8 7F0B70C8 27A800A8 */  addiu $t0, $sp, 0xa8
/* 0EBBFC 7F0B70CC 8FB40154 */  lw    $s4, 0x154($sp)
/* 0EBC00 7F0B70D0 2401FFBF */  li    $at, -65
.L7F0B70D4:
/* 0EBC04 7F0B70D4 1441011F */  bne   $v0, $at, .L7F0B7554
/* 0EBC08 7F0B70D8 3C0E8004 */   lui   $t6, %hi(D_80044868)
/* 0EBC0C 7F0B70DC 25CE4868 */  addiu $t6, %lo(D_80044868) # addiu $t6, $t6, 0x4868
/* 0EBC10 7F0B70E0 8DC10000 */  lw    $at, ($t6)
/* 0EBC14 7F0B70E4 27A600D4 */  addiu $a2, $sp, 0xd4
/* 0EBC18 7F0B70E8 3C198004 */  lui   $t9, %hi(D_80044874)
/* 0EBC1C 7F0B70EC ACC10000 */  sw    $at, ($a2)
/* 0EBC20 7F0B70F0 8DD80004 */  lw    $t8, 4($t6)
/* 0EBC24 7F0B70F4 27394874 */  addiu $t9, %lo(D_80044874) # addiu $t9, $t9, 0x4874
/* 0EBC28 7F0B70F8 27A700C8 */  addiu $a3, $sp, 0xc8
/* 0EBC2C 7F0B70FC ACD80004 */  sw    $t8, 4($a2)
/* 0EBC30 7F0B7100 8DC10008 */  lw    $at, 8($t6)
/* 0EBC34 7F0B7104 2405000A */  li    $a1, 10
/* 0EBC38 7F0B7108 00001025 */  move  $v0, $zero
/* 0EBC3C 7F0B710C ACC10008 */  sw    $at, 8($a2)
/* 0EBC40 7F0B7110 8F210000 */  lw    $at, ($t9)
/* 0EBC44 7F0B7114 27A400E4 */  addiu $a0, $sp, 0xe4
/* 0EBC48 7F0B7118 ACE10000 */  sw    $at, ($a3)
/* 0EBC4C 7F0B711C 8F2A0004 */  lw    $t2, 4($t9)
/* 0EBC50 7F0B7120 ACEA0004 */  sw    $t2, 4($a3)
/* 0EBC54 7F0B7124 8F210008 */  lw    $at, 8($t9)
/* 0EBC58 7F0B7128 ACE10008 */  sw    $at, 8($a3)
/* 0EBC5C 7F0B712C 926B0005 */  lbu   $t3, 5($s3)
/* 0EBC60 7F0B7130 0165001A */  div   $zero, $t3, $a1
/* 0EBC64 7F0B7134 00006012 */  mflo  $t4
/* 0EBC68 7F0B7138 01976823 */  subu  $t5, $t4, $s7
/* 0EBC6C 7F0B713C AFAD00E4 */  sw    $t5, 0xe4($sp)
/* 0EBC70 7F0B7140 926F0006 */  lbu   $t7, 6($s3)
/* 0EBC74 7F0B7144 14A00002 */  bnez  $a1, .L7F0B7150
/* 0EBC78 7F0B7148 00000000 */   nop
/* 0EBC7C 7F0B714C 0007000D */  break 7
.L7F0B7150:
/* 0EBC80 7F0B7150 2401FFFF */  li    $at, -1
/* 0EBC84 7F0B7154 14A10004 */  bne   $a1, $at, .L7F0B7168
/* 0EBC88 7F0B7158 3C018000 */   lui   $at, 0x8000
/* 0EBC8C 7F0B715C 15610002 */  bne   $t3, $at, .L7F0B7168
/* 0EBC90 7F0B7160 00000000 */   nop
/* 0EBC94 7F0B7164 0006000D */  break 6
.L7F0B7168:
/* 0EBC98 7F0B7168 01E5001A */  div   $zero, $t7, $a1
/* 0EBC9C 7F0B716C 00007012 */  mflo  $t6
/* 0EBCA0 7F0B7170 01D7C023 */  subu  $t8, $t6, $s7
/* 0EBCA4 7F0B7174 AFB800E8 */  sw    $t8, 0xe8($sp)
/* 0EBCA8 7F0B7178 92690007 */  lbu   $t1, 7($s3)
/* 0EBCAC 7F0B717C 14A00002 */  bnez  $a1, .L7F0B7188
/* 0EBCB0 7F0B7180 00000000 */   nop
/* 0EBCB4 7F0B7184 0007000D */  break 7
.L7F0B7188:
/* 0EBCB8 7F0B7188 2401FFFF */  li    $at, -1
/* 0EBCBC 7F0B718C 14A10004 */  bne   $a1, $at, .L7F0B71A0
/* 0EBCC0 7F0B7190 3C018000 */   lui   $at, 0x8000
/* 0EBCC4 7F0B7194 15E10002 */  bne   $t7, $at, .L7F0B71A0
/* 0EBCC8 7F0B7198 00000000 */   nop
/* 0EBCCC 7F0B719C 0006000D */  break 6
.L7F0B71A0:
/* 0EBCD0 7F0B71A0 0125001A */  div   $zero, $t1, $a1
/* 0EBCD4 7F0B71A4 8FAB0150 */  lw    $t3, 0x150($sp)
/* 0EBCD8 7F0B71A8 0000C812 */  mflo  $t9
/* 0EBCDC 7F0B71AC 03375023 */  subu  $t2, $t9, $s7
/* 0EBCE0 7F0B71B0 000B6080 */  sll   $t4, $t3, 2
/* 0EBCE4 7F0B71B4 018B6023 */  subu  $t4, $t4, $t3
/* 0EBCE8 7F0B71B8 000C60C0 */  sll   $t4, $t4, 3
/* 0EBCEC 7F0B71BC AFAA00EC */  sw    $t2, 0xec($sp)
/* 0EBCF0 7F0B71C0 AFAC0054 */  sw    $t4, 0x54($sp)
/* 0EBCF4 7F0B71C4 14A00002 */  bnez  $a1, .L7F0B71D0
/* 0EBCF8 7F0B71C8 00000000 */   nop
/* 0EBCFC 7F0B71CC 0007000D */  break 7
.L7F0B71D0:
/* 0EBD00 7F0B71D0 2401FFFF */  li    $at, -1
/* 0EBD04 7F0B71D4 14A10004 */  bne   $a1, $at, .L7F0B71E8
/* 0EBD08 7F0B71D8 3C018000 */   lui   $at, 0x8000
/* 0EBD0C 7F0B71DC 15210002 */  bne   $t1, $at, .L7F0B71E8
/* 0EBD10 7F0B71E0 00000000 */   nop
/* 0EBD14 7F0B71E4 0006000D */  break 6
.L7F0B71E8:
/* 0EBD18 7F0B71E8 8C8D0000 */  lw    $t5, ($a0)
.L7F0B71EC:
/* 0EBD1C 7F0B71EC 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0EBD20 7F0B71F0 24840004 */  addiu $a0, $a0, 4
/* 0EBD24 7F0B71F4 000D7900 */  sll   $t7, $t5, 4
/* 0EBD28 7F0B71F8 022F1821 */  addu  $v1, $s1, $t7
/* 0EBD2C 7F0B71FC 84620000 */  lh    $v0, ($v1)
/* 0EBD30 7F0B7200 27AC00F0 */  addiu $t4, $sp, 0xf0
/* 0EBD34 7F0B7204 004E082A */  slt   $at, $v0, $t6
/* 0EBD38 7F0B7208 50200004 */  beql  $at, $zero, .L7F0B721C
/* 0EBD3C 7F0B720C 8FB800C8 */   lw    $t8, 0xc8($sp)
/* 0EBD40 7F0B7210 AFA200D4 */  sw    $v0, 0xd4($sp)
/* 0EBD44 7F0B7214 84620000 */  lh    $v0, ($v1)
/* 0EBD48 7F0B7218 8FB800C8 */  lw    $t8, 0xc8($sp)
.L7F0B721C:
/* 0EBD4C 7F0B721C 0302082A */  slt   $at, $t8, $v0
/* 0EBD50 7F0B7220 50200003 */  beql  $at, $zero, .L7F0B7230
/* 0EBD54 7F0B7224 84620002 */   lh    $v0, 2($v1)
/* 0EBD58 7F0B7228 AFA200C8 */  sw    $v0, 0xc8($sp)
/* 0EBD5C 7F0B722C 84620002 */  lh    $v0, 2($v1)
.L7F0B7230:
/* 0EBD60 7F0B7230 8FA900D8 */  lw    $t1, 0xd8($sp)
/* 0EBD64 7F0B7234 0049082A */  slt   $at, $v0, $t1
/* 0EBD68 7F0B7238 50200004 */  beql  $at, $zero, .L7F0B724C
/* 0EBD6C 7F0B723C 8FB900CC */   lw    $t9, 0xcc($sp)
/* 0EBD70 7F0B7240 AFA200D8 */  sw    $v0, 0xd8($sp)
/* 0EBD74 7F0B7244 84620002 */  lh    $v0, 2($v1)
/* 0EBD78 7F0B7248 8FB900CC */  lw    $t9, 0xcc($sp)
.L7F0B724C:
/* 0EBD7C 7F0B724C 0322082A */  slt   $at, $t9, $v0
/* 0EBD80 7F0B7250 50200003 */  beql  $at, $zero, .L7F0B7260
/* 0EBD84 7F0B7254 84620004 */   lh    $v0, 4($v1)
/* 0EBD88 7F0B7258 AFA200CC */  sw    $v0, 0xcc($sp)
/* 0EBD8C 7F0B725C 84620004 */  lh    $v0, 4($v1)
.L7F0B7260:
/* 0EBD90 7F0B7260 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0EBD94 7F0B7264 004A082A */  slt   $at, $v0, $t2
/* 0EBD98 7F0B7268 50200004 */  beql  $at, $zero, .L7F0B727C
/* 0EBD9C 7F0B726C 8FAB00D0 */   lw    $t3, 0xd0($sp)
/* 0EBDA0 7F0B7270 AFA200DC */  sw    $v0, 0xdc($sp)
/* 0EBDA4 7F0B7274 84620004 */  lh    $v0, 4($v1)
/* 0EBDA8 7F0B7278 8FAB00D0 */  lw    $t3, 0xd0($sp)
.L7F0B727C:
/* 0EBDAC 7F0B727C 0162082A */  slt   $at, $t3, $v0
/* 0EBDB0 7F0B7280 10200002 */  beqz  $at, .L7F0B728C
/* 0EBDB4 7F0B7284 00000000 */   nop
/* 0EBDB8 7F0B7288 AFA200D0 */  sw    $v0, 0xd0($sp)
.L7F0B728C:
/* 0EBDBC 7F0B728C 548CFFD7 */  bnel  $a0, $t4, .L7F0B71EC
/* 0EBDC0 7F0B7290 8C8D0000 */   lw    $t5, ($a0)
/* 0EBDC4 7F0B7294 3C0D8008 */  lui   $t5, %hi(ptr_bgdata_room_fileposition_list)
/* 0EBDC8 7F0B7298 8DADFF8C */  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
/* 0EBDCC 7F0B729C 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0EBDD0 7F0B72A0 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0EBDD4 7F0B72A4 8FAA00D8 */  lw    $t2, 0xd8($sp)
/* 0EBDD8 7F0B72A8 01AF1021 */  addu  $v0, $t5, $t7
/* 0EBDDC 7F0B72AC C444000C */  lwc1  $f4, 0xc($v0)
/* 0EBDE0 7F0B72B0 8FAF00DC */  lw    $t7, 0xdc($sp)
/* 0EBDE4 7F0B72B4 8FA40140 */  lw    $a0, 0x140($sp)
/* 0EBDE8 7F0B72B8 4600218D */  trunc.w.s $f6, $f4
/* 0EBDEC 7F0B72BC 8FA50148 */  lw    $a1, 0x148($sp)
/* 0EBDF0 7F0B72C0 44093000 */  mfc1  $t1, $f6
/* 0EBDF4 7F0B72C4 00000000 */  nop
/* 0EBDF8 7F0B72C8 01C9C821 */  addu  $t9, $t6, $t1
/* 0EBDFC 7F0B72CC AFB900D4 */  sw    $t9, 0xd4($sp)
/* 0EBE00 7F0B72D0 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0EBE04 7F0B72D4 8FB900C8 */  lw    $t9, 0xc8($sp)
/* 0EBE08 7F0B72D8 4600428D */  trunc.w.s $f10, $f8
/* 0EBE0C 7F0B72DC 440C5000 */  mfc1  $t4, $f10
/* 0EBE10 7F0B72E0 00000000 */  nop
/* 0EBE14 7F0B72E4 014C6821 */  addu  $t5, $t2, $t4
/* 0EBE18 7F0B72E8 AFAD00D8 */  sw    $t5, 0xd8($sp)
/* 0EBE1C 7F0B72EC C4500014 */  lwc1  $f16, 0x14($v0)
/* 0EBE20 7F0B72F0 8FAD00CC */  lw    $t5, 0xcc($sp)
/* 0EBE24 7F0B72F4 4600848D */  trunc.w.s $f18, $f16
/* 0EBE28 7F0B72F8 440E9000 */  mfc1  $t6, $f18
/* 0EBE2C 7F0B72FC 00000000 */  nop
/* 0EBE30 7F0B7300 01EE4821 */  addu  $t1, $t7, $t6
/* 0EBE34 7F0B7304 AFA900DC */  sw    $t1, 0xdc($sp)
/* 0EBE38 7F0B7308 C444000C */  lwc1  $f4, 0xc($v0)
/* 0EBE3C 7F0B730C 8FA900D0 */  lw    $t1, 0xd0($sp)
/* 0EBE40 7F0B7310 4600218D */  trunc.w.s $f6, $f4
/* 0EBE44 7F0B7314 440A3000 */  mfc1  $t2, $f6
/* 0EBE48 7F0B7318 00000000 */  nop
/* 0EBE4C 7F0B731C 032A6021 */  addu  $t4, $t9, $t2
/* 0EBE50 7F0B7320 AFAC00C8 */  sw    $t4, 0xc8($sp)
/* 0EBE54 7F0B7324 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0EBE58 7F0B7328 4600428D */  trunc.w.s $f10, $f8
/* 0EBE5C 7F0B732C 440F5000 */  mfc1  $t7, $f10
/* 0EBE60 7F0B7330 00000000 */  nop
/* 0EBE64 7F0B7334 01AF7021 */  addu  $t6, $t5, $t7
/* 0EBE68 7F0B7338 AFAE00CC */  sw    $t6, 0xcc($sp)
/* 0EBE6C 7F0B733C C4500014 */  lwc1  $f16, 0x14($v0)
/* 0EBE70 7F0B7340 4600848D */  trunc.w.s $f18, $f16
/* 0EBE74 7F0B7344 44199000 */  mfc1  $t9, $f18
/* 0EBE78 7F0B7348 00000000 */  nop
/* 0EBE7C 7F0B734C 01395021 */  addu  $t2, $t1, $t9
/* 0EBE80 7F0B7350 0FC2DB3B */  jal   bgTestLineIntersectsBbox
/* 0EBE84 7F0B7354 AFAA00D0 */   sw    $t2, 0xd0($sp)
/* 0EBE88 7F0B7358 104001B3 */  beqz  $v0, .L7F0B7A28
/* 0EBE8C 7F0B735C 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EBE90 7F0B7360 8FAC00E4 */  lw    $t4, 0xe4($sp)
/* 0EBE94 7F0B7364 8FAD00E8 */  lw    $t5, 0xe8($sp)
/* 0EBE98 7F0B7368 3C198008 */  lui   $t9, %hi(ptr_bgdata_room_fileposition_list)
/* 0EBE9C 7F0B736C 000CC100 */  sll   $t8, $t4, 4
/* 0EBEA0 7F0B7370 8F39FF8C */  lw    $t9, %lo(ptr_bgdata_room_fileposition_list)($t9)
/* 0EBEA4 7F0B7374 8FAE00EC */  lw    $t6, 0xec($sp)
/* 0EBEA8 7F0B7378 8FA90054 */  lw    $t1, 0x54($sp)
/* 0EBEAC 7F0B737C 02382021 */  addu  $a0, $s1, $t8
/* 0EBEB0 7F0B7380 8FB80148 */  lw    $t8, 0x148($sp)
/* 0EBEB4 7F0B7384 8FAC0144 */  lw    $t4, 0x144($sp)
/* 0EBEB8 7F0B7388 8FAA0140 */  lw    $t2, 0x140($sp)
/* 0EBEBC 7F0B738C 000D7900 */  sll   $t7, $t5, 4
/* 0EBEC0 7F0B7390 27AD00F8 */  addiu $t5, $sp, 0xf8
/* 0EBEC4 7F0B7394 000E5900 */  sll   $t3, $t6, 4
/* 0EBEC8 7F0B7398 01393821 */  addu  $a3, $t1, $t9
/* 0EBECC 7F0B739C 24E7000C */  addiu $a3, $a3, 0xc
/* 0EBED0 7F0B73A0 022B3021 */  addu  $a2, $s1, $t3
/* 0EBED4 7F0B73A4 AFAD001C */  sw    $t5, 0x1c($sp)
/* 0EBED8 7F0B73A8 022F2821 */  addu  $a1, $s1, $t7
/* 0EBEDC 7F0B73AC AFB80018 */  sw    $t8, 0x18($sp)
/* 0EBEE0 7F0B73B0 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0EBEE4 7F0B73B4 0FC24A24 */  jal   intersectLineTriangle
/* 0EBEE8 7F0B73B8 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0EBEEC 7F0B73BC 1040019A */  beqz  $v0, .L7F0B7A28
/* 0EBEF0 7F0B73C0 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EBEF4 7F0B73C4 8FA60140 */  lw    $a2, 0x140($sp)
/* 0EBEF8 7F0B73C8 C7A400F8 */  lwc1  $f4, 0xf8($sp)
/* 0EBEFC 7F0B73CC C7B000FC */  lwc1  $f16, 0xfc($sp)
/* 0EBF00 7F0B73D0 C4C80000 */  lwc1  $f8, ($a2)
/* 0EBF04 7F0B73D4 4600218D */  trunc.w.s $f6, $f4
/* 0EBF08 7F0B73D8 C4C40004 */  lwc1  $f4, 4($a2)
/* 0EBF0C 7F0B73DC 02601025 */  move  $v0, $s3
/* 0EBF10 7F0B73E0 4600428D */  trunc.w.s $f10, $f8
/* 0EBF14 7F0B73E4 440E3000 */  mfc1  $t6, $f6
/* 0EBF18 7F0B73E8 C7A80100 */  lwc1  $f8, 0x100($sp)
/* 0EBF1C 7F0B73EC 4600848D */  trunc.w.s $f18, $f16
/* 0EBF20 7F0B73F0 44095000 */  mfc1  $t1, $f10
/* 0EBF24 7F0B73F4 C4D00008 */  lwc1  $f16, 8($a2)
/* 0EBF28 7F0B73F8 4600218D */  trunc.w.s $f6, $f4
/* 0EBF2C 7F0B73FC 01C91823 */  subu  $v1, $t6, $t1
/* 0EBF30 7F0B7400 00630019 */  multu $v1, $v1
/* 0EBF34 7F0B7404 440A9000 */  mfc1  $t2, $f18
/* 0EBF38 7F0B7408 44183000 */  mfc1  $t8, $f6
/* 0EBF3C 7F0B740C 4600428D */  trunc.w.s $f10, $f8
/* 0EBF40 7F0B7410 8FAB0064 */  lw    $t3, 0x64($sp)
/* 0EBF44 7F0B7414 01582023 */  subu  $a0, $t2, $t8
/* 0EBF48 7F0B7418 4600848D */  trunc.w.s $f18, $f16
/* 0EBF4C 7F0B741C 440F5000 */  mfc1  $t7, $f10
/* 0EBF50 7F0B7420 24180001 */  li    $t8, 1
/* 0EBF54 7F0B7424 AFB8012C */  sw    $t8, 0x12c($sp)
/* 0EBF58 7F0B7428 00004812 */  mflo  $t1
/* 0EBF5C 7F0B742C 440E9000 */  mfc1  $t6, $f18
/* 0EBF60 7F0B7430 926D0000 */  lbu   $t5, ($s3)
/* 0EBF64 7F0B7434 00840019 */  multu $a0, $a0
/* 0EBF68 7F0B7438 01EE2823 */  subu  $a1, $t7, $t6
/* 0EBF6C 7F0B743C 8FAE0064 */  lw    $t6, 0x64($sp)
/* 0EBF70 7F0B7440 0000C812 */  mflo  $t9
/* 0EBF74 7F0B7444 01396021 */  addu  $t4, $t1, $t9
/* 0EBF78 7F0B7448 00000000 */  nop
/* 0EBF7C 7F0B744C 00A50019 */  multu $a1, $a1
/* 0EBF80 7F0B7450 00005012 */  mflo  $t2
/* 0EBF84 7F0B7454 018A9021 */  addu  $s2, $t4, $t2
/* 0EBF88 7F0B7458 12CD000C */  beq   $s6, $t5, .L7F0B748C
/* 0EBF8C 7F0B745C 0240F025 */   move  $fp, $s2
/* 0EBF90 7F0B7460 8D630008 */  lw    $v1, 8($t3)
/* 0EBF94 7F0B7464 0073082B */  sltu  $at, $v1, $s3
/* 0EBF98 7F0B7468 50200009 */  beql  $at, $zero, .L7F0B7490
/* 0EBF9C 7F0B746C 8DC90008 */   lw    $t1, 8($t6)
/* 0EBFA0 7F0B7470 904FFFF8 */  lbu   $t7, -8($v0)
.L7F0B7474:
/* 0EBFA4 7F0B7474 2442FFF8 */  addiu $v0, $v0, -8
/* 0EBFA8 7F0B7478 0062082B */  sltu  $at, $v1, $v0
/* 0EBFAC 7F0B747C 52CF0004 */  beql  $s6, $t7, .L7F0B7490
/* 0EBFB0 7F0B7480 8DC90008 */   lw    $t1, 8($t6)
/* 0EBFB4 7F0B7484 5420FFFB */  bnezl $at, .L7F0B7474
/* 0EBFB8 7F0B7488 904FFFF8 */   lbu   $t7, -8($v0)
.L7F0B748C:
/* 0EBFBC 7F0B748C 8DC90008 */  lw    $t1, 8($t6)
.L7F0B7490:
/* 0EBFC0 7F0B7490 54490004 */  bnel  $v0, $t1, .L7F0B74A4
/* 0EBFC4 7F0B7494 8C430004 */   lw    $v1, 4($v0)
/* 0EBFC8 7F0B7498 10000006 */  b     .L7F0B74B4
/* 0EBFCC 7F0B749C 2410FFFF */   li    $s0, -1
/* 0EBFD0 7F0B74A0 8C430004 */  lw    $v1, 4($v0)
.L7F0B74A4:
/* 0EBFD4 7F0B74A4 3C018000 */  lui   $at, 0x8000
/* 0EBFD8 7F0B74A8 2463FFF8 */  addiu $v1, $v1, -8
/* 0EBFDC 7F0B74AC 0061C825 */  or    $t9, $v1, $at
/* 0EBFE0 7F0B74B0 97300000 */  lhu   $s0, ($t9)
.L7F0B74B4:
/* 0EBFE4 7F0B74B4 0FC2ED8C */  jal   check_if_imageID_is_light
/* 0EBFE8 7F0B74B8 02002025 */   move  $a0, $s0
/* 0EBFEC 7F0B74BC 10400002 */  beqz  $v0, .L7F0B74C8
/* 0EBFF0 7F0B74C0 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EBFF4 7F0B74C4 265EFFFC */  addiu $fp, $s2, -4
.L7F0B74C8:
/* 0EBFF8 7F0B74C8 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0EBFFC 7F0B74CC 03CC082A */  slt   $at, $fp, $t4
/* 0EC000 7F0B74D0 10200155 */  beqz  $at, .L7F0B7A28
/* 0EC004 7F0B74D4 240104FD */   li    $at, 1277
/* 0EC008 7F0B74D8 52010154 */  beql  $s0, $at, .L7F0B7A2C
/* 0EC00C 7F0B74DC 82620008 */   lb    $v0, 8($s3)
/* 0EC010 7F0B74E0 C7A400F8 */  lwc1  $f4, 0xf8($sp)
/* 0EC014 7F0B74E4 AFBE00F0 */  sw    $fp, 0xf0($sp)
/* 0EC018 7F0B74E8 E6840000 */  swc1  $f4, ($s4)
/* 0EC01C 7F0B74EC C7A600FC */  lwc1  $f6, 0xfc($sp)
/* 0EC020 7F0B74F0 E6860004 */  swc1  $f6, 4($s4)
/* 0EC024 7F0B74F4 C7A80100 */  lwc1  $f8, 0x100($sp)
/* 0EC028 7F0B74F8 E6880008 */  swc1  $f8, 8($s4)
/* 0EC02C 7F0B74FC C7AA0104 */  lwc1  $f10, 0x104($sp)
/* 0EC030 7F0B7500 E68A000C */  swc1  $f10, 0xc($s4)
/* 0EC034 7F0B7504 C7B00108 */  lwc1  $f16, 0x108($sp)
/* 0EC038 7F0B7508 E6900010 */  swc1  $f16, 0x10($s4)
/* 0EC03C 7F0B750C C7B2010C */  lwc1  $f18, 0x10c($sp)
/* 0EC040 7F0B7510 E6920014 */  swc1  $f18, 0x14($s4)
/* 0EC044 7F0B7514 8FAA00E4 */  lw    $t2, 0xe4($sp)
/* 0EC048 7F0B7518 000AC100 */  sll   $t8, $t2, 4
/* 0EC04C 7F0B751C 03116821 */  addu  $t5, $t8, $s1
/* 0EC050 7F0B7520 AE8D0018 */  sw    $t5, 0x18($s4)
/* 0EC054 7F0B7524 8FAB00E8 */  lw    $t3, 0xe8($sp)
/* 0EC058 7F0B7528 000B7900 */  sll   $t7, $t3, 4
/* 0EC05C 7F0B752C 01F17021 */  addu  $t6, $t7, $s1
/* 0EC060 7F0B7530 AE8E001C */  sw    $t6, 0x1c($s4)
/* 0EC064 7F0B7534 8FA900EC */  lw    $t1, 0xec($sp)
/* 0EC068 7F0B7538 A690002A */  sh    $s0, 0x2a($s4)
/* 0EC06C 7F0B753C AE930024 */  sw    $s3, 0x24($s4)
/* 0EC070 7F0B7540 0009C900 */  sll   $t9, $t1, 4
/* 0EC074 7F0B7544 03316021 */  addu  $t4, $t9, $s1
/* 0EC078 7F0B7548 AE8C0020 */  sw    $t4, 0x20($s4)
/* 0EC07C 7F0B754C 10000136 */  b     .L7F0B7A28
/* 0EC080 7F0B7550 A6800028 */   sh    $zero, 0x28($s4)
.L7F0B7554:
/* 0EC084 7F0B7554 2401FFB1 */  li    $at, -79
/* 0EC088 7F0B7558 14410133 */  bne   $v0, $at, .L7F0B7A28
/* 0EC08C 7F0B755C 8FAA0150 */   lw    $t2, 0x150($sp)
/* 0EC090 7F0B7560 000AC080 */  sll   $t8, $t2, 2
/* 0EC094 7F0B7564 030AC023 */  subu  $t8, $t8, $t2
/* 0EC098 7F0B7568 0018C0C0 */  sll   $t8, $t8, 3
/* 0EC09C 7F0B756C AFB80054 */  sw    $t8, 0x54($sp)
/* 0EC0A0 7F0B7570 0000A825 */  move  $s5, $zero
.L7F0B7574:
/* 0EC0A4 7F0B7574 3C0B8004 */  lui   $t3, %hi(D_80044880)
/* 0EC0A8 7F0B7578 256B4880 */  addiu $t3, %lo(D_80044880) # addiu $t3, $t3, 0x4880
/* 0EC0AC 7F0B757C 8D610000 */  lw    $at, ($t3)
/* 0EC0B0 7F0B7580 27AD008C */  addiu $t5, $sp, 0x8c
/* 0EC0B4 7F0B7584 8D690004 */  lw    $t1, 4($t3)
/* 0EC0B8 7F0B7588 ADA10000 */  sw    $at, ($t5)
/* 0EC0BC 7F0B758C 8D610008 */  lw    $at, 8($t3)
/* 0EC0C0 7F0B7590 3C0C8004 */  lui   $t4, %hi(D_8004488C)
/* 0EC0C4 7F0B7594 258C488C */  addiu $t4, %lo(D_8004488C) # addiu $t4, $t4, 0x488c
/* 0EC0C8 7F0B7598 ADA90004 */  sw    $t1, 4($t5)
/* 0EC0CC 7F0B759C ADA10008 */  sw    $at, 8($t5)
/* 0EC0D0 7F0B75A0 8D810000 */  lw    $at, ($t4)
/* 0EC0D4 7F0B75A4 27B90080 */  addiu $t9, $sp, 0x80
/* 0EC0D8 7F0B75A8 8D8E0004 */  lw    $t6, 4($t4)
/* 0EC0DC 7F0B75AC AF210000 */  sw    $at, ($t9)
/* 0EC0E0 7F0B75B0 8D810008 */  lw    $at, 8($t4)
/* 0EC0E4 7F0B75B4 AF2E0004 */  sw    $t6, 4($t9)
/* 0EC0E8 7F0B75B8 16A0000E */  bnez  $s5, .L7F0B75F4
/* 0EC0EC 7F0B75BC AF210008 */   sw    $at, 8($t9)
/* 0EC0F0 7F0B75C0 8E6F0004 */  lw    $t7, 4($s3)
/* 0EC0F4 7F0B75C4 31ED000F */  andi  $t5, $t7, 0xf
/* 0EC0F8 7F0B75C8 01B75823 */  subu  $t3, $t5, $s7
/* 0EC0FC 7F0B75CC AFAB009C */  sw    $t3, 0x9c($sp)
/* 0EC100 7F0B75D0 92690007 */  lbu   $t1, 7($s3)
/* 0EC104 7F0B75D4 0009C102 */  srl   $t8, $t1, 4
/* 0EC108 7F0B75D8 03175023 */  subu  $t2, $t8, $s7
/* 0EC10C 7F0B75DC AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0EC110 7F0B75E0 8E790000 */  lw    $t9, ($s3)
/* 0EC114 7F0B75E4 332C000F */  andi  $t4, $t9, 0xf
/* 0EC118 7F0B75E8 01977023 */  subu  $t6, $t4, $s7
/* 0EC11C 7F0B75EC 1000002D */  b     .L7F0B76A4
/* 0EC120 7F0B75F0 AFAE00A4 */   sw    $t6, 0xa4($sp)
.L7F0B75F4:
/* 0EC124 7F0B75F4 24010001 */  li    $at, 1
/* 0EC128 7F0B75F8 56A1000F */  bnel  $s5, $at, .L7F0B7638
/* 0EC12C 7F0B75FC 24010002 */   li    $at, 2
/* 0EC130 7F0B7600 926F0006 */  lbu   $t7, 6($s3)
/* 0EC134 7F0B7604 31ED000F */  andi  $t5, $t7, 0xf
/* 0EC138 7F0B7608 01B75823 */  subu  $t3, $t5, $s7
/* 0EC13C 7F0B760C AFAB009C */  sw    $t3, 0x9c($sp)
/* 0EC140 7F0B7610 96690006 */  lhu   $t1, 6($s3)
/* 0EC144 7F0B7614 0009C302 */  srl   $t8, $t1, 0xc
/* 0EC148 7F0B7618 03175023 */  subu  $t2, $t8, $s7
/* 0EC14C 7F0B761C AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0EC150 7F0B7620 92790003 */  lbu   $t9, 3($s3)
/* 0EC154 7F0B7624 00196102 */  srl   $t4, $t9, 4
/* 0EC158 7F0B7628 01977023 */  subu  $t6, $t4, $s7
/* 0EC15C 7F0B762C 1000001D */  b     .L7F0B76A4
/* 0EC160 7F0B7630 AFAE00A4 */   sw    $t6, 0xa4($sp)
/* 0EC164 7F0B7634 24010002 */  li    $at, 2
.L7F0B7638:
/* 0EC168 7F0B7638 56A1000F */  bnel  $s5, $at, .L7F0B7678
/* 0EC16C 7F0B763C 926F0004 */   lbu   $t7, 4($s3)
/* 0EC170 7F0B7640 966F0004 */  lhu   $t7, 4($s3)
/* 0EC174 7F0B7644 31ED000F */  andi  $t5, $t7, 0xf
/* 0EC178 7F0B7648 01B75823 */  subu  $t3, $t5, $s7
/* 0EC17C 7F0B764C AFAB009C */  sw    $t3, 0x9c($sp)
/* 0EC180 7F0B7650 92690005 */  lbu   $t1, 5($s3)
/* 0EC184 7F0B7654 0009C102 */  srl   $t8, $t1, 4
/* 0EC188 7F0B7658 03175023 */  subu  $t2, $t8, $s7
/* 0EC18C 7F0B765C AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0EC190 7F0B7660 92790002 */  lbu   $t9, 2($s3)
/* 0EC194 7F0B7664 332C000F */  andi  $t4, $t9, 0xf
/* 0EC198 7F0B7668 01977023 */  subu  $t6, $t4, $s7
/* 0EC19C 7F0B766C 1000000D */  b     .L7F0B76A4
/* 0EC1A0 7F0B7670 AFAE00A4 */   sw    $t6, 0xa4($sp)
/* 0EC1A4 7F0B7674 926F0004 */  lbu   $t7, 4($s3)
.L7F0B7678:
/* 0EC1A8 7F0B7678 31ED000F */  andi  $t5, $t7, 0xf
/* 0EC1AC 7F0B767C 01B75823 */  subu  $t3, $t5, $s7
/* 0EC1B0 7F0B7680 AFAB009C */  sw    $t3, 0x9c($sp)
/* 0EC1B4 7F0B7684 8E690004 */  lw    $t1, 4($s3)
/* 0EC1B8 7F0B7688 0009C702 */  srl   $t8, $t1, 0x1c
/* 0EC1BC 7F0B768C 03175023 */  subu  $t2, $t8, $s7
/* 0EC1C0 7F0B7690 AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0EC1C4 7F0B7694 96790002 */  lhu   $t9, 2($s3)
/* 0EC1C8 7F0B7698 00196302 */  srl   $t4, $t9, 0xc
/* 0EC1CC 7F0B769C 01977023 */  subu  $t6, $t4, $s7
/* 0EC1D0 7F0B76A0 AFAE00A4 */  sw    $t6, 0xa4($sp)
.L7F0B76A4:
/* 0EC1D4 7F0B76A4 27A4009C */  addiu $a0, $sp, 0x9c
/* 0EC1D8 7F0B76A8 8C8F0000 */  lw    $t7, ($a0)
.L7F0B76AC:
/* 0EC1DC 7F0B76AC 8FAB008C */  lw    $t3, 0x8c($sp)
/* 0EC1E0 7F0B76B0 24840004 */  addiu $a0, $a0, 4
/* 0EC1E4 7F0B76B4 000F6900 */  sll   $t5, $t7, 4
/* 0EC1E8 7F0B76B8 022D1821 */  addu  $v1, $s1, $t5
/* 0EC1EC 7F0B76BC 84620000 */  lh    $v0, ($v1)
/* 0EC1F0 7F0B76C0 004B082A */  slt   $at, $v0, $t3
/* 0EC1F4 7F0B76C4 50200004 */  beql  $at, $zero, .L7F0B76D8
/* 0EC1F8 7F0B76C8 8FA90080 */   lw    $t1, 0x80($sp)
/* 0EC1FC 7F0B76CC AFA2008C */  sw    $v0, 0x8c($sp)
/* 0EC200 7F0B76D0 84620000 */  lh    $v0, ($v1)
/* 0EC204 7F0B76D4 8FA90080 */  lw    $t1, 0x80($sp)
.L7F0B76D8:
/* 0EC208 7F0B76D8 0122082A */  slt   $at, $t1, $v0
/* 0EC20C 7F0B76DC 50200003 */  beql  $at, $zero, .L7F0B76EC
/* 0EC210 7F0B76E0 84620002 */   lh    $v0, 2($v1)
/* 0EC214 7F0B76E4 AFA20080 */  sw    $v0, 0x80($sp)
/* 0EC218 7F0B76E8 84620002 */  lh    $v0, 2($v1)
.L7F0B76EC:
/* 0EC21C 7F0B76EC 8FB80090 */  lw    $t8, 0x90($sp)
/* 0EC220 7F0B76F0 0058082A */  slt   $at, $v0, $t8
/* 0EC224 7F0B76F4 50200004 */  beql  $at, $zero, .L7F0B7708
/* 0EC228 7F0B76F8 8FAA0084 */   lw    $t2, 0x84($sp)
/* 0EC22C 7F0B76FC AFA20090 */  sw    $v0, 0x90($sp)
/* 0EC230 7F0B7700 84620002 */  lh    $v0, 2($v1)
/* 0EC234 7F0B7704 8FAA0084 */  lw    $t2, 0x84($sp)
.L7F0B7708:
/* 0EC238 7F0B7708 0142082A */  slt   $at, $t2, $v0
/* 0EC23C 7F0B770C 50200003 */  beql  $at, $zero, .L7F0B771C
/* 0EC240 7F0B7710 84620004 */   lh    $v0, 4($v1)
/* 0EC244 7F0B7714 AFA20084 */  sw    $v0, 0x84($sp)
/* 0EC248 7F0B7718 84620004 */  lh    $v0, 4($v1)
.L7F0B771C:
/* 0EC24C 7F0B771C 8FB90094 */  lw    $t9, 0x94($sp)
/* 0EC250 7F0B7720 0059082A */  slt   $at, $v0, $t9
/* 0EC254 7F0B7724 50200004 */  beql  $at, $zero, .L7F0B7738
/* 0EC258 7F0B7728 8FAC0088 */   lw    $t4, 0x88($sp)
/* 0EC25C 7F0B772C AFA20094 */  sw    $v0, 0x94($sp)
/* 0EC260 7F0B7730 84620004 */  lh    $v0, 4($v1)
/* 0EC264 7F0B7734 8FAC0088 */  lw    $t4, 0x88($sp)
.L7F0B7738:
/* 0EC268 7F0B7738 0182082A */  slt   $at, $t4, $v0
/* 0EC26C 7F0B773C 10200002 */  beqz  $at, .L7F0B7748
/* 0EC270 7F0B7740 00000000 */   nop
/* 0EC274 7F0B7744 AFA20088 */  sw    $v0, 0x88($sp)
.L7F0B7748:
/* 0EC278 7F0B7748 5488FFD8 */  bnel  $a0, $t0, .L7F0B76AC
/* 0EC27C 7F0B774C 8C8F0000 */   lw    $t7, ($a0)
/* 0EC280 7F0B7750 3C0E8008 */  lui   $t6, %hi(ptr_bgdata_room_fileposition_list)
/* 0EC284 7F0B7754 8DCEFF8C */  lw    $t6, %lo(ptr_bgdata_room_fileposition_list)($t6)
/* 0EC288 7F0B7758 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0EC28C 7F0B775C 8FAD008C */  lw    $t5, 0x8c($sp)
/* 0EC290 7F0B7760 8FAA0090 */  lw    $t2, 0x90($sp)
/* 0EC294 7F0B7764 01CF1021 */  addu  $v0, $t6, $t7
/* 0EC298 7F0B7768 C444000C */  lwc1  $f4, 0xc($v0)
/* 0EC29C 7F0B776C 8FAF0094 */  lw    $t7, 0x94($sp)
/* 0EC2A0 7F0B7770 8FA40140 */  lw    $a0, 0x140($sp)
/* 0EC2A4 7F0B7774 4600218D */  trunc.w.s $f6, $f4
/* 0EC2A8 7F0B7778 8FA50148 */  lw    $a1, 0x148($sp)
/* 0EC2AC 7F0B777C 27A6008C */  addiu $a2, $sp, 0x8c
/* 0EC2B0 7F0B7780 27A70080 */  addiu $a3, $sp, 0x80
/* 0EC2B4 7F0B7784 44093000 */  mfc1  $t1, $f6
/* 0EC2B8 7F0B7788 00000000 */  nop
/* 0EC2BC 7F0B778C 01A9C021 */  addu  $t8, $t5, $t1
/* 0EC2C0 7F0B7790 AFB8008C */  sw    $t8, 0x8c($sp)
/* 0EC2C4 7F0B7794 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0EC2C8 7F0B7798 8FB80080 */  lw    $t8, 0x80($sp)
/* 0EC2CC 7F0B779C 4600428D */  trunc.w.s $f10, $f8
/* 0EC2D0 7F0B77A0 440C5000 */  mfc1  $t4, $f10
/* 0EC2D4 7F0B77A4 00000000 */  nop
/* 0EC2D8 7F0B77A8 014C7021 */  addu  $t6, $t2, $t4
/* 0EC2DC 7F0B77AC AFAE0090 */  sw    $t6, 0x90($sp)
/* 0EC2E0 7F0B77B0 C4500014 */  lwc1  $f16, 0x14($v0)
/* 0EC2E4 7F0B77B4 8FAE0084 */  lw    $t6, 0x84($sp)
/* 0EC2E8 7F0B77B8 4600848D */  trunc.w.s $f18, $f16
/* 0EC2EC 7F0B77BC 440D9000 */  mfc1  $t5, $f18
/* 0EC2F0 7F0B77C0 00000000 */  nop
/* 0EC2F4 7F0B77C4 01ED4821 */  addu  $t1, $t7, $t5
/* 0EC2F8 7F0B77C8 AFA90094 */  sw    $t1, 0x94($sp)
/* 0EC2FC 7F0B77CC C444000C */  lwc1  $f4, 0xc($v0)
/* 0EC300 7F0B77D0 8FA90088 */  lw    $t1, 0x88($sp)
/* 0EC304 7F0B77D4 4600218D */  trunc.w.s $f6, $f4
/* 0EC308 7F0B77D8 440A3000 */  mfc1  $t2, $f6
/* 0EC30C 7F0B77DC 00000000 */  nop
/* 0EC310 7F0B77E0 030A6021 */  addu  $t4, $t8, $t2
/* 0EC314 7F0B77E4 AFAC0080 */  sw    $t4, 0x80($sp)
/* 0EC318 7F0B77E8 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0EC31C 7F0B77EC 4600428D */  trunc.w.s $f10, $f8
/* 0EC320 7F0B77F0 440F5000 */  mfc1  $t7, $f10
/* 0EC324 7F0B77F4 00000000 */  nop
/* 0EC328 7F0B77F8 01CF6821 */  addu  $t5, $t6, $t7
/* 0EC32C 7F0B77FC AFAD0084 */  sw    $t5, 0x84($sp)
/* 0EC330 7F0B7800 C4500014 */  lwc1  $f16, 0x14($v0)
/* 0EC334 7F0B7804 4600848D */  trunc.w.s $f18, $f16
/* 0EC338 7F0B7808 44189000 */  mfc1  $t8, $f18
/* 0EC33C 7F0B780C 00000000 */  nop
/* 0EC340 7F0B7810 01385021 */  addu  $t2, $t1, $t8
/* 0EC344 7F0B7814 0FC2DB3B */  jal   bgTestLineIntersectsBbox
/* 0EC348 7F0B7818 AFAA0088 */   sw    $t2, 0x88($sp)
/* 0EC34C 7F0B781C 1040007E */  beqz  $v0, .L7F0B7A18
/* 0EC350 7F0B7820 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EC354 7F0B7824 8FAC009C */  lw    $t4, 0x9c($sp)
/* 0EC358 7F0B7828 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0EC35C 7F0B782C 3C188008 */  lui   $t8, %hi(ptr_bgdata_room_fileposition_list)
/* 0EC360 7F0B7830 000C5900 */  sll   $t3, $t4, 4
/* 0EC364 7F0B7834 8F18FF8C */  lw    $t8, %lo(ptr_bgdata_room_fileposition_list)($t8)
/* 0EC368 7F0B7838 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 0EC36C 7F0B783C 8FA90054 */  lw    $t1, 0x54($sp)
/* 0EC370 7F0B7840 022B2021 */  addu  $a0, $s1, $t3
/* 0EC374 7F0B7844 8FAB0148 */  lw    $t3, 0x148($sp)
/* 0EC378 7F0B7848 8FAC0144 */  lw    $t4, 0x144($sp)
/* 0EC37C 7F0B784C 8FAA0140 */  lw    $t2, 0x140($sp)
/* 0EC380 7F0B7850 000E7900 */  sll   $t7, $t6, 4
/* 0EC384 7F0B7854 27AE00F8 */  addiu $t6, $sp, 0xf8
/* 0EC388 7F0B7858 000DC900 */  sll   $t9, $t5, 4
/* 0EC38C 7F0B785C 01383821 */  addu  $a3, $t1, $t8
/* 0EC390 7F0B7860 24E7000C */  addiu $a3, $a3, 0xc
/* 0EC394 7F0B7864 02393021 */  addu  $a2, $s1, $t9
/* 0EC398 7F0B7868 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0EC39C 7F0B786C 022F2821 */  addu  $a1, $s1, $t7
/* 0EC3A0 7F0B7870 AFAB0018 */  sw    $t3, 0x18($sp)
/* 0EC3A4 7F0B7874 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0EC3A8 7F0B7878 0FC24A24 */  jal   intersectLineTriangle
/* 0EC3AC 7F0B787C AFAA0010 */   sw    $t2, 0x10($sp)
/* 0EC3B0 7F0B7880 10400065 */  beqz  $v0, .L7F0B7A18
/* 0EC3B4 7F0B7884 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EC3B8 7F0B7888 8FA60140 */  lw    $a2, 0x140($sp)
/* 0EC3BC 7F0B788C C7A400F8 */  lwc1  $f4, 0xf8($sp)
/* 0EC3C0 7F0B7890 C7B000FC */  lwc1  $f16, 0xfc($sp)
/* 0EC3C4 7F0B7894 C4C80000 */  lwc1  $f8, ($a2)
/* 0EC3C8 7F0B7898 4600218D */  trunc.w.s $f6, $f4
/* 0EC3CC 7F0B789C C4C40004 */  lwc1  $f4, 4($a2)
/* 0EC3D0 7F0B78A0 02601025 */  move  $v0, $s3
/* 0EC3D4 7F0B78A4 4600428D */  trunc.w.s $f10, $f8
/* 0EC3D8 7F0B78A8 440D3000 */  mfc1  $t5, $f6
/* 0EC3DC 7F0B78AC C7A80100 */  lwc1  $f8, 0x100($sp)
/* 0EC3E0 7F0B78B0 4600848D */  trunc.w.s $f18, $f16
/* 0EC3E4 7F0B78B4 44095000 */  mfc1  $t1, $f10
/* 0EC3E8 7F0B78B8 C4D00008 */  lwc1  $f16, 8($a2)
/* 0EC3EC 7F0B78BC 4600218D */  trunc.w.s $f6, $f4
/* 0EC3F0 7F0B78C0 01A91823 */  subu  $v1, $t5, $t1
/* 0EC3F4 7F0B78C4 00630019 */  multu $v1, $v1
/* 0EC3F8 7F0B78C8 440A9000 */  mfc1  $t2, $f18
/* 0EC3FC 7F0B78CC 440B3000 */  mfc1  $t3, $f6
/* 0EC400 7F0B78D0 4600428D */  trunc.w.s $f10, $f8
/* 0EC404 7F0B78D4 8FB90064 */  lw    $t9, 0x64($sp)
/* 0EC408 7F0B78D8 014B2023 */  subu  $a0, $t2, $t3
/* 0EC40C 7F0B78DC 4600848D */  trunc.w.s $f18, $f16
/* 0EC410 7F0B78E0 440F5000 */  mfc1  $t7, $f10
/* 0EC414 7F0B78E4 240B0001 */  li    $t3, 1
/* 0EC418 7F0B78E8 AFAB012C */  sw    $t3, 0x12c($sp)
/* 0EC41C 7F0B78EC 00004812 */  mflo  $t1
/* 0EC420 7F0B78F0 440D9000 */  mfc1  $t5, $f18
/* 0EC424 7F0B78F4 926E0000 */  lbu   $t6, ($s3)
/* 0EC428 7F0B78F8 00840019 */  multu $a0, $a0
/* 0EC42C 7F0B78FC 01ED2823 */  subu  $a1, $t7, $t5
/* 0EC430 7F0B7900 8FAD0064 */  lw    $t5, 0x64($sp)
/* 0EC434 7F0B7904 0000C012 */  mflo  $t8
/* 0EC438 7F0B7908 01386021 */  addu  $t4, $t1, $t8
/* 0EC43C 7F0B790C 00000000 */  nop
/* 0EC440 7F0B7910 00A50019 */  multu $a1, $a1
/* 0EC444 7F0B7914 00005012 */  mflo  $t2
/* 0EC448 7F0B7918 018A9021 */  addu  $s2, $t4, $t2
/* 0EC44C 7F0B791C 12CE000C */  beq   $s6, $t6, .L7F0B7950
/* 0EC450 7F0B7920 0240F025 */   move  $fp, $s2
/* 0EC454 7F0B7924 8F230008 */  lw    $v1, 8($t9)
/* 0EC458 7F0B7928 0073082B */  sltu  $at, $v1, $s3
/* 0EC45C 7F0B792C 50200009 */  beql  $at, $zero, .L7F0B7954
/* 0EC460 7F0B7930 8DA90008 */   lw    $t1, 8($t5)
/* 0EC464 7F0B7934 904FFFF8 */  lbu   $t7, -8($v0)
.L7F0B7938:
/* 0EC468 7F0B7938 2442FFF8 */  addiu $v0, $v0, -8
/* 0EC46C 7F0B793C 0062082B */  sltu  $at, $v1, $v0
/* 0EC470 7F0B7940 52CF0004 */  beql  $s6, $t7, .L7F0B7954
/* 0EC474 7F0B7944 8DA90008 */   lw    $t1, 8($t5)
/* 0EC478 7F0B7948 5420FFFB */  bnezl $at, .L7F0B7938
/* 0EC47C 7F0B794C 904FFFF8 */   lbu   $t7, -8($v0)
.L7F0B7950:
/* 0EC480 7F0B7950 8DA90008 */  lw    $t1, 8($t5)
.L7F0B7954:
/* 0EC484 7F0B7954 54490004 */  bnel  $v0, $t1, .L7F0B7968
/* 0EC488 7F0B7958 8C430004 */   lw    $v1, 4($v0)
/* 0EC48C 7F0B795C 10000006 */  b     .L7F0B7978
/* 0EC490 7F0B7960 2410FFFF */   li    $s0, -1
/* 0EC494 7F0B7964 8C430004 */  lw    $v1, 4($v0)
.L7F0B7968:
/* 0EC498 7F0B7968 3C018000 */  lui   $at, 0x8000
/* 0EC49C 7F0B796C 2463FFF8 */  addiu $v1, $v1, -8
/* 0EC4A0 7F0B7970 0061C025 */  or    $t8, $v1, $at
/* 0EC4A4 7F0B7974 97100000 */  lhu   $s0, ($t8)
.L7F0B7978:
/* 0EC4A8 7F0B7978 0FC2ED8C */  jal   check_if_imageID_is_light
/* 0EC4AC 7F0B797C 02002025 */   move  $a0, $s0
/* 0EC4B0 7F0B7980 10400002 */  beqz  $v0, .L7F0B798C
/* 0EC4B4 7F0B7984 27A800A8 */   addiu $t0, $sp, 0xa8
/* 0EC4B8 7F0B7988 265EFFFC */  addiu $fp, $s2, -4
.L7F0B798C:
/* 0EC4BC 7F0B798C 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0EC4C0 7F0B7990 03CC082A */  slt   $at, $fp, $t4
/* 0EC4C4 7F0B7994 10200020 */  beqz  $at, .L7F0B7A18
/* 0EC4C8 7F0B7998 240104FD */   li    $at, 1277
/* 0EC4CC 7F0B799C 5201001F */  beql  $s0, $at, .L7F0B7A1C
/* 0EC4D0 7F0B79A0 26B50001 */   addiu $s5, $s5, 1
/* 0EC4D4 7F0B79A4 C7A400F8 */  lwc1  $f4, 0xf8($sp)
/* 0EC4D8 7F0B79A8 AFBE00F0 */  sw    $fp, 0xf0($sp)
/* 0EC4DC 7F0B79AC E6840000 */  swc1  $f4, ($s4)
/* 0EC4E0 7F0B79B0 C7A600FC */  lwc1  $f6, 0xfc($sp)
/* 0EC4E4 7F0B79B4 E6860004 */  swc1  $f6, 4($s4)
/* 0EC4E8 7F0B79B8 C7A80100 */  lwc1  $f8, 0x100($sp)
/* 0EC4EC 7F0B79BC E6880008 */  swc1  $f8, 8($s4)
/* 0EC4F0 7F0B79C0 C7AA0104 */  lwc1  $f10, 0x104($sp)
/* 0EC4F4 7F0B79C4 E68A000C */  swc1  $f10, 0xc($s4)
/* 0EC4F8 7F0B79C8 C7B00108 */  lwc1  $f16, 0x108($sp)
/* 0EC4FC 7F0B79CC E6900010 */  swc1  $f16, 0x10($s4)
/* 0EC500 7F0B79D0 C7B2010C */  lwc1  $f18, 0x10c($sp)
/* 0EC504 7F0B79D4 E6920014 */  swc1  $f18, 0x14($s4)
/* 0EC508 7F0B79D8 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0EC50C 7F0B79DC 000A5900 */  sll   $t3, $t2, 4
/* 0EC510 7F0B79E0 01717021 */  addu  $t6, $t3, $s1
/* 0EC514 7F0B79E4 AE8E0018 */  sw    $t6, 0x18($s4)
/* 0EC518 7F0B79E8 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0EC51C 7F0B79EC 26AA0001 */  addiu $t2, $s5, 1
/* 0EC520 7F0B79F0 00197900 */  sll   $t7, $t9, 4
/* 0EC524 7F0B79F4 01F16821 */  addu  $t5, $t7, $s1
/* 0EC528 7F0B79F8 AE8D001C */  sw    $t5, 0x1c($s4)
/* 0EC52C 7F0B79FC 8FA900A4 */  lw    $t1, 0xa4($sp)
/* 0EC530 7F0B7A00 A690002A */  sh    $s0, 0x2a($s4)
/* 0EC534 7F0B7A04 AE930024 */  sw    $s3, 0x24($s4)
/* 0EC538 7F0B7A08 0009C100 */  sll   $t8, $t1, 4
/* 0EC53C 7F0B7A0C 03116021 */  addu  $t4, $t8, $s1
/* 0EC540 7F0B7A10 AE8C0020 */  sw    $t4, 0x20($s4)
/* 0EC544 7F0B7A14 A68A0028 */  sh    $t2, 0x28($s4)
.L7F0B7A18:
/* 0EC548 7F0B7A18 26B50001 */  addiu $s5, $s5, 1
.L7F0B7A1C:
/* 0EC54C 7F0B7A1C 24010004 */  li    $at, 4
/* 0EC550 7F0B7A20 16A1FED4 */  bne   $s5, $at, .L7F0B7574
/* 0EC554 7F0B7A24 00000000 */   nop
.L7F0B7A28:
/* 0EC558 7F0B7A28 82620008 */  lb    $v0, 8($s3)
.L7F0B7A2C:
/* 0EC55C 7F0B7A2C 24010004 */  li    $at, 4
/* 0EC560 7F0B7A30 26730008 */  addiu $s3, $s3, 8
/* 0EC564 7F0B7A34 10410003 */  beq   $v0, $at, .L7F0B7A44
/* 0EC568 7F0B7A38 2401FFB8 */   li    $at, -72
/* 0EC56C 7F0B7A3C 5441FDA5 */  bnel  $v0, $at, .L7F0B70D4
/* 0EC570 7F0B7A40 2401FFBF */   li    $at, -65
.L7F0B7A44:
/* 0EC574 7F0B7A44 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0EC578 7F0B7A48 8FA2012C */  lw    $v0, 0x12c($sp)
/* 0EC57C 7F0B7A4C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0EC580 7F0B7A50 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0EC584 7F0B7A54 8FB20030 */  lw    $s2, 0x30($sp)
/* 0EC588 7F0B7A58 8FB30034 */  lw    $s3, 0x34($sp)
/* 0EC58C 7F0B7A5C 8FB40038 */  lw    $s4, 0x38($sp)
/* 0EC590 7F0B7A60 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0EC594 7F0B7A64 8FB60040 */  lw    $s6, 0x40($sp)
/* 0EC598 7F0B7A68 8FB70044 */  lw    $s7, 0x44($sp)
/* 0EC59C 7F0B7A6C 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0EC5A0 7F0B7A70 03E00008 */  jr    $ra
/* 0EC5A4 7F0B7A74 27BD0140 */   addiu $sp, $sp, 0x140
)
#endif





#ifdef NONMATCHING
void bgTestBulletHitBackground(void) {

}
#else
GLOBAL_ASM(
.text
glabel bgTestBulletHitBackground
/* 0EC5A8 7F0B7A78 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 0EC5AC 7F0B7A7C 3C0E7FFF */  lui   $t6, (0x7FFFFFFF >> 16) # lui $t6, 0x7fff
/* 0EC5B0 7F0B7A80 35CEFFFF */  ori   $t6, (0x7FFFFFFF & 0xFFFF) # ori $t6, $t6, 0xffff
/* 0EC5B4 7F0B7A84 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0EC5B8 7F0B7A88 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0EC5BC 7F0B7A8C AFB7003C */  sw    $s7, 0x3c($sp)
/* 0EC5C0 7F0B7A90 AFB60038 */  sw    $s6, 0x38($sp)
/* 0EC5C4 7F0B7A94 AFB50034 */  sw    $s5, 0x34($sp)
/* 0EC5C8 7F0B7A98 AFB40030 */  sw    $s4, 0x30($sp)
/* 0EC5CC 7F0B7A9C AFB3002C */  sw    $s3, 0x2c($sp)
/* 0EC5D0 7F0B7AA0 AFB20028 */  sw    $s2, 0x28($sp)
/* 0EC5D4 7F0B7AA4 AFB10024 */  sw    $s1, 0x24($sp)
/* 0EC5D8 7F0B7AA8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0EC5DC 7F0B7AAC AFA600E0 */  sw    $a2, 0xe0($sp)
/* 0EC5E0 7F0B7AB0 AFA0006C */  sw    $zero, 0x6c($sp)
/* 0EC5E4 7F0B7AB4 AFAE0074 */  sw    $t6, 0x74($sp)
/* 0EC5E8 7F0B7AB8 3C018004 */  lui   $at, %hi(room_data_float1)
/* 0EC5EC 7F0B7ABC C42013F4 */  lwc1  $f0, %lo(room_data_float1)($at)
/* 0EC5F0 7F0B7AC0 C4840000 */  lwc1  $f4, ($a0)
/* 0EC5F4 7F0B7AC4 0006C080 */  sll   $t8, $a2, 2
/* 0EC5F8 7F0B7AC8 0306C021 */  addu  $t8, $t8, $a2
/* 0EC5FC 7F0B7ACC 46002182 */  mul.s $f6, $f4, $f0
/* 0EC600 7F0B7AD0 3C198004 */  lui   $t9, %hi(g_BgRoomInfo)
/* 0EC604 7F0B7AD4 27391414 */  addiu $t9, %lo(g_BgRoomInfo) # addiu $t9, $t9, 0x1414
/* 0EC608 7F0B7AD8 0018C100 */  sll   $t8, $t8, 4
/* 0EC60C 7F0B7ADC 03194021 */  addu  $t0, $t8, $t9
/* 0EC610 7F0B7AE0 8D02002C */  lw    $v0, 0x2c($t0)
/* 0EC614 7F0B7AE4 00E08825 */  move  $s1, $a3
/* 0EC618 7F0B7AE8 E7A600C4 */  swc1  $f6, 0xc4($sp)
/* 0EC61C 7F0B7AEC C4880004 */  lwc1  $f8, 4($a0)
/* 0EC620 7F0B7AF0 46004282 */  mul.s $f10, $f8, $f0
/* 0EC624 7F0B7AF4 E7AA00C8 */  swc1  $f10, 0xc8($sp)
/* 0EC628 7F0B7AF8 C4900008 */  lwc1  $f16, 8($a0)
/* 0EC62C 7F0B7AFC 46008482 */  mul.s $f18, $f16, $f0
/* 0EC630 7F0B7B00 E7B200CC */  swc1  $f18, 0xcc($sp)
/* 0EC634 7F0B7B04 C4A40000 */  lwc1  $f4, ($a1)
/* 0EC638 7F0B7B08 46002182 */  mul.s $f6, $f4, $f0
/* 0EC63C 7F0B7B0C E7A600B8 */  swc1  $f6, 0xb8($sp)
/* 0EC640 7F0B7B10 C4A80004 */  lwc1  $f8, 4($a1)
/* 0EC644 7F0B7B14 C7A400B8 */  lwc1  $f4, 0xb8($sp)
/* 0EC648 7F0B7B18 C7A600C4 */  lwc1  $f6, 0xc4($sp)
/* 0EC64C 7F0B7B1C 46004282 */  mul.s $f10, $f8, $f0
/* 0EC650 7F0B7B20 46062201 */  sub.s $f8, $f4, $f6
/* 0EC654 7F0B7B24 C7A600CC */  lwc1  $f6, 0xcc($sp)
/* 0EC658 7F0B7B28 E7AA00BC */  swc1  $f10, 0xbc($sp)
/* 0EC65C 7F0B7B2C C4B00008 */  lwc1  $f16, 8($a1)
/* 0EC660 7F0B7B30 C7AA00BC */  lwc1  $f10, 0xbc($sp)
/* 0EC664 7F0B7B34 E7A800AC */  swc1  $f8, 0xac($sp)
/* 0EC668 7F0B7B38 46008482 */  mul.s $f18, $f16, $f0
/* 0EC66C 7F0B7B3C C7B000C8 */  lwc1  $f16, 0xc8($sp)
/* 0EC670 7F0B7B40 E7B200C0 */  swc1  $f18, 0xc0($sp)
/* 0EC674 7F0B7B44 C7A400C0 */  lwc1  $f4, 0xc0($sp)
/* 0EC678 7F0B7B48 46105481 */  sub.s $f18, $f10, $f16
/* 0EC67C 7F0B7B4C 46062201 */  sub.s $f8, $f4, $f6
/* 0EC680 7F0B7B50 E7B200B0 */  swc1  $f18, 0xb0($sp)
/* 0EC684 7F0B7B54 14400003 */  bnez  $v0, .L7F0B7B64
/* 0EC688 7F0B7B58 E7A800B4 */   swc1  $f8, 0xb4($sp)
/* 0EC68C 7F0B7B5C 10000081 */  b     .L7F0B7D64
/* 0EC690 7F0B7B60 00001025 */   move  $v0, $zero
.L7F0B7B64:
/* 0EC694 7F0B7B64 85030030 */  lh    $v1, 0x30($t0)
/* 0EC698 7F0B7B68 0000A025 */  move  $s4, $zero
/* 0EC69C 7F0B7B6C 00409825 */  move  $s3, $v0
/* 0EC6A0 7F0B7B70 1860005A */  blez  $v1, .L7F0B7CDC
/* 0EC6A4 7F0B7B74 24550004 */   addiu $s5, $v0, 4
/* 0EC6A8 7F0B7B78 24560010 */  addiu $s6, $v0, 0x10
/* 0EC6AC 7F0B7B7C A7A300D2 */  sh    $v1, 0xd2($sp)
/* 0EC6B0 7F0B7B80 AFA80058 */  sw    $t0, 0x58($sp)
/* 0EC6B4 7F0B7B84 27BE00AC */  addiu $fp, $sp, 0xac
/* 0EC6B8 7F0B7B88 27B700C4 */  addiu $s7, $sp, 0xc4
.L7F0B7B8C:
/* 0EC6BC 7F0B7B8C 02E02025 */  move  $a0, $s7
/* 0EC6C0 7F0B7B90 03C02825 */  move  $a1, $fp
/* 0EC6C4 7F0B7B94 02A03025 */  move  $a2, $s5
/* 0EC6C8 7F0B7B98 0FC2DB3B */  jal   bgTestLineIntersectsBbox
/* 0EC6CC 7F0B7B9C 02C03825 */   move  $a3, $s6
/* 0EC6D0 7F0B7BA0 10400047 */  beqz  $v0, .L7F0B7CC0
/* 0EC6D4 7F0B7BA4 02E02025 */   move  $a0, $s7
/* 0EC6D8 7F0B7BA8 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0EC6DC 7F0B7BAC 27AA007C */  addiu $t2, $sp, 0x7c
/* 0EC6E0 7F0B7BB0 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0EC6E4 7F0B7BB4 27A500B8 */  addiu $a1, $sp, 0xb8
/* 0EC6E8 7F0B7BB8 03C03025 */  move  $a2, $fp
/* 0EC6EC 7F0B7BBC 02603825 */  move  $a3, $s3
/* 0EC6F0 7F0B7BC0 0FC2DC04 */  jal   bgTestLineIntersectionInRoom
/* 0EC6F4 7F0B7BC4 AFA90010 */   sw    $t1, 0x10($sp)
/* 0EC6F8 7F0B7BC8 1040003D */  beqz  $v0, .L7F0B7CC0
/* 0EC6FC 7F0B7BCC C7AA007C */   lwc1  $f10, 0x7c($sp)
/* 0EC700 7F0B7BD0 C7B000C4 */  lwc1  $f16, 0xc4($sp)
/* 0EC704 7F0B7BD4 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0EC708 7F0B7BD8 C7A800C8 */  lwc1  $f8, 0xc8($sp)
/* 0EC70C 7F0B7BDC 46105481 */  sub.s $f18, $f10, $f16
/* 0EC710 7F0B7BE0 24090001 */  li    $t1, 1
/* 0EC714 7F0B7BE4 AFA9006C */  sw    $t1, 0x6c($sp)
/* 0EC718 7F0B7BE8 46083281 */  sub.s $f10, $f6, $f8
/* 0EC71C 7F0B7BEC 87A400A6 */  lh    $a0, 0xa6($sp)
/* 0EC720 7F0B7BF0 4600910D */  trunc.w.s $f4, $f18
/* 0EC724 7F0B7BF4 C7B20084 */  lwc1  $f18, 0x84($sp)
/* 0EC728 7F0B7BF8 4600540D */  trunc.w.s $f16, $f10
/* 0EC72C 7F0B7BFC 44022000 */  mfc1  $v0, $f4
/* 0EC730 7F0B7C00 C7A400CC */  lwc1  $f4, 0xcc($sp)
/* 0EC734 7F0B7C04 00420019 */  multu $v0, $v0
/* 0EC738 7F0B7C08 44038000 */  mfc1  $v1, $f16
/* 0EC73C 7F0B7C0C 46049181 */  sub.s $f6, $f18, $f4
/* 0EC740 7F0B7C10 4600320D */  trunc.w.s $f8, $f6
/* 0EC744 7F0B7C14 00007012 */  mflo  $t6
/* 0EC748 7F0B7C18 44054000 */  mfc1  $a1, $f8
/* 0EC74C 7F0B7C1C 00000000 */  nop
/* 0EC750 7F0B7C20 00630019 */  multu $v1, $v1
/* 0EC754 7F0B7C24 00007812 */  mflo  $t7
/* 0EC758 7F0B7C28 01CFC021 */  addu  $t8, $t6, $t7
/* 0EC75C 7F0B7C2C 00000000 */  nop
/* 0EC760 7F0B7C30 00A50019 */  multu $a1, $a1
/* 0EC764 7F0B7C34 0000C812 */  mflo  $t9
/* 0EC768 7F0B7C38 03199021 */  addu  $s2, $t8, $t9
/* 0EC76C 7F0B7C3C 0FC2ED8C */  jal   check_if_imageID_is_light
/* 0EC770 7F0B7C40 02408025 */   move  $s0, $s2
/* 0EC774 7F0B7C44 10400002 */  beqz  $v0, .L7F0B7C50
/* 0EC778 7F0B7C48 8FAA0074 */   lw    $t2, 0x74($sp)
/* 0EC77C 7F0B7C4C 2650FFFC */  addiu $s0, $s2, -4
.L7F0B7C50:
/* 0EC780 7F0B7C50 020A082A */  slt   $at, $s0, $t2
/* 0EC784 7F0B7C54 5020001B */  beql  $at, $zero, .L7F0B7CC4
/* 0EC788 7F0B7C58 87B900D2 */   lh    $t9, 0xd2($sp)
/* 0EC78C 7F0B7C5C C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0EC790 7F0B7C60 AFB00074 */  sw    $s0, 0x74($sp)
/* 0EC794 7F0B7C64 E62A0000 */  swc1  $f10, ($s1)
/* 0EC798 7F0B7C68 C7B00080 */  lwc1  $f16, 0x80($sp)
/* 0EC79C 7F0B7C6C E6300004 */  swc1  $f16, 4($s1)
/* 0EC7A0 7F0B7C70 C7B20084 */  lwc1  $f18, 0x84($sp)
/* 0EC7A4 7F0B7C74 E6320008 */  swc1  $f18, 8($s1)
/* 0EC7A8 7F0B7C78 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0EC7AC 7F0B7C7C E624000C */  swc1  $f4, 0xc($s1)
/* 0EC7B0 7F0B7C80 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 0EC7B4 7F0B7C84 E6260010 */  swc1  $f6, 0x10($s1)
/* 0EC7B8 7F0B7C88 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 0EC7BC 7F0B7C8C E6280014 */  swc1  $f8, 0x14($s1)
/* 0EC7C0 7F0B7C90 8FAB0094 */  lw    $t3, 0x94($sp)
/* 0EC7C4 7F0B7C94 AE2B0018 */  sw    $t3, 0x18($s1)
/* 0EC7C8 7F0B7C98 8FAC0098 */  lw    $t4, 0x98($sp)
/* 0EC7CC 7F0B7C9C AE2C001C */  sw    $t4, 0x1c($s1)
/* 0EC7D0 7F0B7CA0 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0EC7D4 7F0B7CA4 AE2D0020 */  sw    $t5, 0x20($s1)
/* 0EC7D8 7F0B7CA8 87AE00A6 */  lh    $t6, 0xa6($sp)
/* 0EC7DC 7F0B7CAC A62E002A */  sh    $t6, 0x2a($s1)
/* 0EC7E0 7F0B7CB0 8FAF00A0 */  lw    $t7, 0xa0($sp)
/* 0EC7E4 7F0B7CB4 AE2F0024 */  sw    $t7, 0x24($s1)
/* 0EC7E8 7F0B7CB8 87B800A4 */  lh    $t8, 0xa4($sp)
/* 0EC7EC 7F0B7CBC A6380028 */  sh    $t8, 0x28($s1)
.L7F0B7CC0:
/* 0EC7F0 7F0B7CC0 87B900D2 */  lh    $t9, 0xd2($sp)
.L7F0B7CC4:
/* 0EC7F4 7F0B7CC4 26940001 */  addiu $s4, $s4, 1
/* 0EC7F8 7F0B7CC8 2673001C */  addiu $s3, $s3, 0x1c
/* 0EC7FC 7F0B7CCC 26B5001C */  addiu $s5, $s5, 0x1c
/* 0EC800 7F0B7CD0 1699FFAE */  bne   $s4, $t9, .L7F0B7B8C
/* 0EC804 7F0B7CD4 26D6001C */   addiu $s6, $s6, 0x1c
/* 0EC808 7F0B7CD8 8FA80058 */  lw    $t0, 0x58($sp)
.L7F0B7CDC:
/* 0EC80C 7F0B7CDC 8FA9006C */  lw    $t1, 0x6c($sp)
/* 0EC810 7F0B7CE0 51200020 */  beql  $t1, $zero, .L7F0B7D64
/* 0EC814 7F0B7CE4 8FA2006C */   lw    $v0, 0x6c($sp)
/* 0EC818 7F0B7CE8 8E220024 */  lw    $v0, 0x24($s1)
/* 0EC81C 7F0B7CEC 240400F5 */  li    $a0, 245
/* 0EC820 7F0B7CF0 904A0000 */  lbu   $t2, ($v0)
/* 0EC824 7F0B7CF4 508A000D */  beql  $a0, $t2, .L7F0B7D2C
/* 0EC828 7F0B7CF8 8D0C0008 */   lw    $t4, 8($t0)
/* 0EC82C 7F0B7CFC 8D030008 */  lw    $v1, 8($t0)
/* 0EC830 7F0B7D00 0062082B */  sltu  $at, $v1, $v0
/* 0EC834 7F0B7D04 50200009 */  beql  $at, $zero, .L7F0B7D2C
/* 0EC838 7F0B7D08 8D0C0008 */   lw    $t4, 8($t0)
/* 0EC83C 7F0B7D0C 904BFFF8 */  lbu   $t3, -8($v0)
.L7F0B7D10:
/* 0EC840 7F0B7D10 2442FFF8 */  addiu $v0, $v0, -8
/* 0EC844 7F0B7D14 0062082B */  sltu  $at, $v1, $v0
/* 0EC848 7F0B7D18 508B0004 */  beql  $a0, $t3, .L7F0B7D2C
/* 0EC84C 7F0B7D1C 8D0C0008 */   lw    $t4, 8($t0)
/* 0EC850 7F0B7D20 5420FFFB */  bnezl $at, .L7F0B7D10
/* 0EC854 7F0B7D24 904BFFF8 */   lbu   $t3, -8($v0)
/* 0EC858 7F0B7D28 8D0C0008 */  lw    $t4, 8($t0)
.L7F0B7D2C:
/* 0EC85C 7F0B7D2C 544C0006 */  bnel  $v0, $t4, .L7F0B7D48
/* 0EC860 7F0B7D30 904D0001 */   lbu   $t5, 1($v0)
/* 0EC864 7F0B7D34 2402FFFF */  li    $v0, -1
/* 0EC868 7F0B7D38 A622002C */  sh    $v0, 0x2c($s1)
/* 0EC86C 7F0B7D3C 10000008 */  b     .L7F0B7D60
/* 0EC870 7F0B7D40 A622002E */   sh    $v0, 0x2e($s1)
/* 0EC874 7F0B7D44 904D0001 */  lbu   $t5, 1($v0)
.L7F0B7D48:
/* 0EC878 7F0B7D48 000D7142 */  srl   $t6, $t5, 5
/* 0EC87C 7F0B7D4C A62E002C */  sh    $t6, 0x2c($s1)
/* 0EC880 7F0B7D50 8C4F0000 */  lw    $t7, ($v0)
/* 0EC884 7F0B7D54 000FC2C0 */  sll   $t8, $t7, 0xb
/* 0EC888 7F0B7D58 0018CF82 */  srl   $t9, $t8, 0x1e
/* 0EC88C 7F0B7D5C A639002E */  sh    $t9, 0x2e($s1)
.L7F0B7D60:
/* 0EC890 7F0B7D60 8FA2006C */  lw    $v0, 0x6c($sp)
.L7F0B7D64:
/* 0EC894 7F0B7D64 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0EC898 7F0B7D68 8FB00020 */  lw    $s0, 0x20($sp)
/* 0EC89C 7F0B7D6C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0EC8A0 7F0B7D70 8FB20028 */  lw    $s2, 0x28($sp)
/* 0EC8A4 7F0B7D74 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0EC8A8 7F0B7D78 8FB40030 */  lw    $s4, 0x30($sp)
/* 0EC8AC 7F0B7D7C 8FB50034 */  lw    $s5, 0x34($sp)
/* 0EC8B0 7F0B7D80 8FB60038 */  lw    $s6, 0x38($sp)
/* 0EC8B4 7F0B7D84 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0EC8B8 7F0B7D88 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0EC8BC 7F0B7D8C 03E00008 */  jr    $ra
/* 0EC8C0 7F0B7D90 27BD00D8 */   addiu $sp, $sp, 0xd8
)
#endif






void sub_GAME_7F0B7D94(void) {
    D_800448A0 = 0;
    D_800448A4 = 0;
}


u8 sub_GAME_7F0B7DA8(s32 arg0)
{
    s_room_info* room_info;
    u8 tmp_flags;
    u8 bitflags;
    u8 out;

    room_info = &g_BgRoomInfo[arg0];
    bitflags = room_info->portals_to_room_count;
    out = bitflags;

    if ((s32) bitflags < 0xFF)
    {
        tmp_flags = bitflags + 1;
        room_info->portals_to_room_count = tmp_flags;
        out = tmp_flags & 0xFF;
    }

    return out;
}


#ifdef NONMATCHING
void sub_GAME_7F0B7DE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    void *sp1C;
    void *temp_v1;
    void *temp_v0;
    s32 temp_a0;
    s32 phi_a0;

    // Node 0
    temp_v1 = ((D_800448A0 << 5) + &dword_CODE_bss_8007C100);
    if ((arg3 < 2) || (sub_GAME_7F0B7DA8(((temp_v0->unk4 ^ temp_v0->unk5) ^ arg1)) < 9))
    {
        // Node 2
        *temp_v1 = arg0;
        temp_v1->unk4 = arg1;
        temp_v1->unkC = (s32) arg3;
        temp_v1->unk8 = arg2;
        temp_v1->unk10 = (f32) *arg4;
        temp_v1->unk14 = (f32) arg4->unk4;
        temp_v1->unk18 = (f32) arg4->unk8;
        temp_v1->unk1C = (f32) arg4->unkC;
        temp_a0 = D_800448A4;
        *&D_800448A0 = temp_a0;
        phi_a0 = temp_a0;
        if (temp_a0 == 0x1f4)
        {
            // Node 3
            *&D_800448A0 = 0;
            phi_a0 = 0;
        }
        // Node 4
        if (D_800448A4 == phi_a0)
        {
            // Node 5
            #ifdef DEBUG
            osSyncPrintf("bg: pstackat: Overflow ");
            #endif
            *&D_800448A0 = (s32) (phi_a0 + -1);
        }
    }
    else
    {

    }
    // Node 6
    return;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7DE4
/* 0EC914 7F0B7DE4 3C088004 */  lui   $t0, %hi(D_800448A0)
/* 0EC918 7F0B7DE8 250848A0 */  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, 0x48a0
/* 0EC91C 7F0B7DEC 8D0E0000 */  lw    $t6, ($t0)
/* 0EC920 7F0B7DF0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EC924 7F0B7DF4 3C188008 */  lui   $t8, %hi(dword_CODE_bss_8007C100)
/* 0EC928 7F0B7DF8 2718C100 */  addiu $t8, %lo(dword_CODE_bss_8007C100) # addiu $t8, $t8, -0x3f00
/* 0EC92C 7F0B7DFC 28E10002 */  slti  $at, $a3, 2
/* 0EC930 7F0B7E00 000E7940 */  sll   $t7, $t6, 5
/* 0EC934 7F0B7E04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EC938 7F0B7E08 AFA40020 */  sw    $a0, 0x20($sp)
/* 0EC93C 7F0B7E0C AFA50024 */  sw    $a1, 0x24($sp)
/* 0EC940 7F0B7E10 AFA60028 */  sw    $a2, 0x28($sp)
/* 0EC944 7F0B7E14 14200012 */  bnez  $at, .L7F0B7E60
/* 0EC948 7F0B7E18 01F81821 */   addu  $v1, $t7, $t8
/* 0EC94C 7F0B7E1C 3C198008 */  lui   $t9, %hi(g_BgPortals)
/* 0EC950 7F0B7E20 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0EC954 7F0B7E24 000650C0 */  sll   $t2, $a2, 3
/* 0EC958 7F0B7E28 032A1021 */  addu  $v0, $t9, $t2
/* 0EC95C 7F0B7E2C 904B0004 */  lbu   $t3, 4($v0)
/* 0EC960 7F0B7E30 904C0005 */  lbu   $t4, 5($v0)
/* 0EC964 7F0B7E34 AFA7002C */  sw    $a3, 0x2c($sp)
/* 0EC968 7F0B7E38 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0EC96C 7F0B7E3C 016C6826 */  xor   $t5, $t3, $t4
/* 0EC970 7F0B7E40 0FC2DF6A */  jal   sub_GAME_7F0B7DA8
/* 0EC974 7F0B7E44 01A52026 */   xor   $a0, $t5, $a1
/* 0EC978 7F0B7E48 3C088004 */  lui   $t0, %hi(D_800448A0)
/* 0EC97C 7F0B7E4C 28410009 */  slti  $at, $v0, 9
/* 0EC980 7F0B7E50 250848A0 */  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, 0x48a0
/* 0EC984 7F0B7E54 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EC988 7F0B7E58 1020001E */  beqz  $at, .L7F0B7ED4
/* 0EC98C 7F0B7E5C 8FA7002C */   lw    $a3, 0x2c($sp)
.L7F0B7E60:
/* 0EC990 7F0B7E60 8FAF0020 */  lw    $t7, 0x20($sp)
/* 0EC994 7F0B7E64 8FA20030 */  lw    $v0, 0x30($sp)
/* 0EC998 7F0B7E68 240101F4 */  li    $at, 500
/* 0EC99C 7F0B7E6C AC6F0000 */  sw    $t7, ($v1)
/* 0EC9A0 7F0B7E70 8FB80024 */  lw    $t8, 0x24($sp)
/* 0EC9A4 7F0B7E74 3C0B8004 */  lui   $t3, %hi(D_800448A4)
/* 0EC9A8 7F0B7E78 AC780004 */  sw    $t8, 4($v1)
/* 0EC9AC 7F0B7E7C 8FA90028 */  lw    $t1, 0x28($sp)
/* 0EC9B0 7F0B7E80 AC67000C */  sw    $a3, 0xc($v1)
/* 0EC9B4 7F0B7E84 AC690008 */  sw    $t1, 8($v1)
/* 0EC9B8 7F0B7E88 C4440000 */  lwc1  $f4, ($v0)
/* 0EC9BC 7F0B7E8C E4640010 */  swc1  $f4, 0x10($v1)
/* 0EC9C0 7F0B7E90 C4460004 */  lwc1  $f6, 4($v0)
/* 0EC9C4 7F0B7E94 E4660014 */  swc1  $f6, 0x14($v1)
/* 0EC9C8 7F0B7E98 C4480008 */  lwc1  $f8, 8($v0)
/* 0EC9CC 7F0B7E9C E4680018 */  swc1  $f8, 0x18($v1)
/* 0EC9D0 7F0B7EA0 C44A000C */  lwc1  $f10, 0xc($v0)
/* 0EC9D4 7F0B7EA4 E46A001C */  swc1  $f10, 0x1c($v1)
/* 0EC9D8 7F0B7EA8 8D190000 */  lw    $t9, ($t0)
/* 0EC9DC 7F0B7EAC 27240001 */  addiu $a0, $t9, 1
/* 0EC9E0 7F0B7EB0 14810003 */  bne   $a0, $at, .L7F0B7EC0
/* 0EC9E4 7F0B7EB4 AD040000 */   sw    $a0, ($t0)
/* 0EC9E8 7F0B7EB8 AD000000 */  sw    $zero, ($t0)
/* 0EC9EC 7F0B7EBC 00002025 */  move  $a0, $zero
.L7F0B7EC0:
/* 0EC9F0 7F0B7EC0 8D6B48A4 */  lw    $t3, %lo(D_800448A4)($t3)
/* 0EC9F4 7F0B7EC4 248CFFFF */  addiu $t4, $a0, -1
/* 0EC9F8 7F0B7EC8 55640003 */  bnel  $t3, $a0, .L7F0B7ED8
/* 0EC9FC 7F0B7ECC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0ECA00 7F0B7ED0 AD0C0000 */  sw    $t4, ($t0)
.L7F0B7ED4:
/* 0ECA04 7F0B7ED4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0B7ED8:
/* 0ECA08 7F0B7ED8 27BD0020 */  addiu $sp, $sp, 0x20
/* 0ECA0C 7F0B7EDC 03E00008 */  jr    $ra
/* 0ECA10 7F0B7EE0 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7DE4
/* 0E9B10 7F0B7120 3C088004 */  lui   $t0, %hi(D_800448A0) # $t0, 0x8004
/* 0E9B14 7F0B7124 2508DD88 */  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, -0x2278
/* 0E9B18 7F0B7128 8D0E0000 */  lw    $t6, ($t0)
/* 0E9B1C 7F0B712C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9B20 7F0B7130 3C188007 */  lui   $t8, %hi(dword_CODE_bss_8007C100) # $t8, 0x8007
/* 0E9B24 7F0B7134 000E7880 */  sll   $t7, $t6, 2
/* 0E9B28 7F0B7138 01EE7821 */  addu  $t7, $t7, $t6
/* 0E9B2C 7F0B713C 000F7880 */  sll   $t7, $t7, 2
/* 0E9B30 7F0B7140 2718A040 */  addiu $t8, %lo(dword_CODE_bss_8007C100) # addiu $t8, $t8, -0x5fc0
/* 0E9B34 7F0B7144 28C10002 */  slti  $at, $a2, 2
/* 0E9B38 7F0B7148 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9B3C 7F0B714C AFA40020 */  sw    $a0, 0x20($sp)
/* 0E9B40 7F0B7150 AFA50024 */  sw    $a1, 0x24($sp)
/* 0E9B44 7F0B7154 14200014 */  bnez  $at, .L7F0B71A8
/* 0E9B48 7F0B7158 01F81821 */   addu  $v1, $t7, $t8
/* 0E9B4C 7F0B715C 3C198007 */  lui   $t9, %hi(g_BgPortals) # $t9, 0x8007
/* 0E9B50 7F0B7160 8F39B3C8 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0E9B54 7F0B7164 000550C0 */  sll   $t2, $a1, 3
/* 0E9B58 7F0B7168 032A1021 */  addu  $v0, $t9, $t2
/* 0E9B5C 7F0B716C 904B0004 */  lbu   $t3, 4($v0)
/* 0E9B60 7F0B7170 904C0005 */  lbu   $t4, 5($v0)
/* 0E9B64 7F0B7174 AFA7002C */  sw    $a3, 0x2c($sp)
/* 0E9B68 7F0B7178 AFA60028 */  sw    $a2, 0x28($sp)
/* 0E9B6C 7F0B717C 016C6826 */  xor   $t5, $t3, $t4
/* 0E9B70 7F0B7180 01A42026 */  xor   $a0, $t5, $a0
/* 0E9B74 7F0B7184 0FC2DC39 */  jal   sub_GAME_7F0B7DA8
/* 0E9B78 7F0B7188 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0E9B7C 7F0B718C 3C088004 */  lui   $t0, %hi(D_800448A0) # $t0, 0x8004
/* 0E9B80 7F0B7190 28410009 */  slti  $at, $v0, 9
/* 0E9B84 7F0B7194 2508DD88 */  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, -0x2278
/* 0E9B88 7F0B7198 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0E9B8C 7F0B719C 8FA60028 */  lw    $a2, 0x28($sp)
/* 0E9B90 7F0B71A0 1020001B */  beqz  $at, .L7F0B7210
/* 0E9B94 7F0B71A4 8FA7002C */   lw    $a3, 0x2c($sp)
.L7F0B71A8:
/* 0E9B98 7F0B71A8 8FAF0020 */  lw    $t7, 0x20($sp)
/* 0E9B9C 7F0B71AC 240100FA */  li    $at, 250
/* 0E9BA0 7F0B71B0 3C0A8004 */  lui   $t2, %hi(D_800448A4) # $t2, 0x8004
/* 0E9BA4 7F0B71B4 A06F0000 */  sb    $t7, ($v1)
/* 0E9BA8 7F0B71B8 8FB80024 */  lw    $t8, 0x24($sp)
/* 0E9BAC 7F0B71BC A4660002 */  sh    $a2, 2($v1)
/* 0E9BB0 7F0B71C0 A0780001 */  sb    $t8, 1($v1)
/* 0E9BB4 7F0B71C4 C4E40000 */  lwc1  $f4, ($a3)
/* 0E9BB8 7F0B71C8 E4640004 */  swc1  $f4, 4($v1)
/* 0E9BBC 7F0B71CC C4E60004 */  lwc1  $f6, 4($a3)
/* 0E9BC0 7F0B71D0 E4660008 */  swc1  $f6, 8($v1)
/* 0E9BC4 7F0B71D4 C4E80008 */  lwc1  $f8, 8($a3)
/* 0E9BC8 7F0B71D8 E468000C */  swc1  $f8, 0xc($v1)
/* 0E9BCC 7F0B71DC C4EA000C */  lwc1  $f10, 0xc($a3)
/* 0E9BD0 7F0B71E0 E46A0010 */  swc1  $f10, 0x10($v1)
/* 0E9BD4 7F0B71E4 8D090000 */  lw    $t1, ($t0)
/* 0E9BD8 7F0B71E8 25220001 */  addiu $v0, $t1, 1
/* 0E9BDC 7F0B71EC 14410003 */  bne   $v0, $at, .L7F0B71FC
/* 0E9BE0 7F0B71F0 AD020000 */   sw    $v0, ($t0)
/* 0E9BE4 7F0B71F4 AD000000 */  sw    $zero, ($t0)
/* 0E9BE8 7F0B71F8 00001025 */  move  $v0, $zero
.L7F0B71FC:
/* 0E9BEC 7F0B71FC 8D4ADD8C */  lw    $t2, %lo(D_800448A4)($t2)
/* 0E9BF0 7F0B7200 244BFFFF */  addiu $t3, $v0, -1
/* 0E9BF4 7F0B7204 55420003 */  bnel  $t2, $v0, .L7F0B7214
/* 0E9BF8 7F0B7208 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0E9BFC 7F0B720C AD0B0000 */  sw    $t3, ($t0)
.L7F0B7210:
/* 0E9C00 7F0B7210 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0B7214:
/* 0E9C04 7F0B7214 27BD0020 */  addiu $sp, $sp, 0x20
/* 0E9C08 7F0B7218 03E00008 */  jr    $ra
/* 0E9C0C 7F0B721C 00000000 */   nop
)
#endif

#endif





#ifdef NONMATCHING
void sub_GAME_7F0B7EE4(void) {
  int iVar1;
  undefined8 uVar2;

  if (_D_800448A4 == _D_800448A0)
  {
    uVar2 = 0;
  }
  else
  {
    iVar1 = _D_800448A4 * 0x14;
    bgPortalDescend(*(&QWORD_83aa1dd0 + iVar1),*(&QWORD_83aa1dd0 + iVar1 + 1),
                    *(&QWORD_83aa1dd0 + iVar1 + 2),&QWORD_83aa1dd0 + iVar1 + 4);
    _D_800448A4 += 1;
    if (_D_800448A4 == 0xfa)
    {
      _D_800448A4 = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7EE4
/* 0ECA14 7F0B7EE4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0ECA18 7F0B7EE8 3C038004 */  lui   $v1, %hi(D_800448A4)
/* 0ECA1C 7F0B7EEC 246348A4 */  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, 0x48a4
/* 0ECA20 7F0B7EF0 3C188004 */  lui   $t8, %hi(D_800448A0)
/* 0ECA24 7F0B7EF4 8F1848A0 */  lw    $t8, %lo(D_800448A0)($t8)
/* 0ECA28 7F0B7EF8 8C680000 */  lw    $t0, ($v1)
/* 0ECA2C 7F0B7EFC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0ECA30 7F0B7F00 AFA40028 */  sw    $a0, 0x28($sp)
/* 0ECA34 7F0B7F04 8C8F0000 */  lw    $t7, ($a0)
/* 0ECA38 7F0B7F08 0008C940 */  sll   $t9, $t0, 5
/* 0ECA3C 7F0B7F0C 17080003 */  bne   $t8, $t0, .L7F0B7F1C
/* 0ECA40 7F0B7F10 AFAF0020 */   sw    $t7, 0x20($sp)
/* 0ECA44 7F0B7F14 10000017 */  b     .L7F0B7F74
/* 0ECA48 7F0B7F18 00001025 */   move  $v0, $zero
.L7F0B7F1C:
/* 0ECA4C 7F0B7F1C 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007C100)
/* 0ECA50 7F0B7F20 2529C100 */  addiu $t1, %lo(dword_CODE_bss_8007C100) # addiu $t1, $t1, -0x3f00
/* 0ECA54 7F0B7F24 03291021 */  addu  $v0, $t9, $t1
/* 0ECA58 7F0B7F28 8C450004 */  lw    $a1, 4($v0)
/* 0ECA5C 7F0B7F2C 8C460008 */  lw    $a2, 8($v0)
/* 0ECA60 7F0B7F30 8C47000C */  lw    $a3, 0xc($v0)
/* 0ECA64 7F0B7F34 244A0010 */  addiu $t2, $v0, 0x10
/* 0ECA68 7F0B7F38 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0ECA6C 7F0B7F3C 0FC2DFE1 */  jal   sub_GAME_7F0B7F84
/* 0ECA70 7F0B7F40 8FA40020 */   lw    $a0, 0x20($sp)
/* 0ECA74 7F0B7F44 3C038004 */  lui   $v1, %hi(D_800448A4)
/* 0ECA78 7F0B7F48 246348A4 */  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, 0x48a4
/* 0ECA7C 7F0B7F4C 8C6B0000 */  lw    $t3, ($v1)
/* 0ECA80 7F0B7F50 240101F4 */  li    $at, 500
/* 0ECA84 7F0B7F54 00402025 */  move  $a0, $v0
/* 0ECA88 7F0B7F58 256C0001 */  addiu $t4, $t3, 1
/* 0ECA8C 7F0B7F5C 15810002 */  bne   $t4, $at, .L7F0B7F68
/* 0ECA90 7F0B7F60 AC6C0000 */   sw    $t4, ($v1)
/* 0ECA94 7F0B7F64 AC600000 */  sw    $zero, ($v1)
.L7F0B7F68:
/* 0ECA98 7F0B7F68 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0ECA9C 7F0B7F6C 24020001 */  li    $v0, 1
/* 0ECAA0 7F0B7F70 ADC40000 */  sw    $a0, ($t6)
.L7F0B7F74:
/* 0ECAA4 7F0B7F74 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0ECAA8 7F0B7F78 27BD0028 */  addiu $sp, $sp, 0x28
/* 0ECAAC 7F0B7F7C 03E00008 */  jr    $ra
/* 0ECAB0 7F0B7F80 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7EE4
/* 0E9C10 7F0B7220 3C038004 */  lui   $v1, %hi(D_800448A4) # $v1, 0x8004
/* 0E9C14 7F0B7224 2463DD8C */  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, -0x2274
/* 0E9C18 7F0B7228 3C0E8004 */  lui   $t6, %hi(D_800448A0) # $t6, 0x8004
/* 0E9C1C 7F0B722C 8DCEDD88 */  lw    $t6, %lo(D_800448A0)($t6)
/* 0E9C20 7F0B7230 8C680000 */  lw    $t0, ($v1)
/* 0E9C24 7F0B7234 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9C28 7F0B7238 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9C2C 7F0B723C 15C80003 */  bne   $t6, $t0, .Leu7F0B724C
/* 0E9C30 7F0B7240 00087880 */   sll   $t7, $t0, 2
/* 0E9C34 7F0B7244 10000014 */  b     .L7F0B7298
/* 0E9C38 7F0B7248 00001025 */   move  $v0, $zero
.Leu7F0B724C:
/* 0E9C3C 7F0B724C 01E87821 */  addu  $t7, $t7, $t0
/* 0E9C40 7F0B7250 3C188007 */  lui   $t8, %hi(dword_CODE_bss_8007C100) # $t8, 0x8007
/* 0E9C44 7F0B7254 2718A040 */  addiu $t8, %lo(dword_CODE_bss_8007C100) # addiu $t8, $t8, -0x5fc0
/* 0E9C48 7F0B7258 000F7880 */  sll   $t7, $t7, 2
/* 0E9C4C 7F0B725C 01F81021 */  addu  $v0, $t7, $t8
/* 0E9C50 7F0B7260 90440000 */  lbu   $a0, ($v0)
/* 0E9C54 7F0B7264 90450001 */  lbu   $a1, 1($v0)
/* 0E9C58 7F0B7268 84460002 */  lh    $a2, 2($v0)
/* 0E9C5C 7F0B726C 0FC2DCAA */  jal   sub_GAME_7F0B7F84
/* 0E9C60 7F0B7270 24470004 */   addiu $a3, $v0, 4
/* 0E9C64 7F0B7274 3C038004 */  lui   $v1, %hi(D_800448A4) # $v1, 0x8004
/* 0E9C68 7F0B7278 2463DD8C */  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, -0x2274
/* 0E9C6C 7F0B727C 8C790000 */  lw    $t9, ($v1)
/* 0E9C70 7F0B7280 240100FA */  li    $at, 250
/* 0E9C74 7F0B7284 24020001 */  li    $v0, 1
/* 0E9C78 7F0B7288 27290001 */  addiu $t1, $t9, 1
/* 0E9C7C 7F0B728C 15210002 */  bne   $t1, $at, .L7F0B7298
/* 0E9C80 7F0B7290 AC690000 */   sw    $t1, ($v1)
/* 0E9C84 7F0B7294 AC600000 */  sw    $zero, ($v1)
.L7F0B7298:
/* 0E9C88 7F0B7298 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E9C8C 7F0B729C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0E9C90 7F0B72A0 03E00008 */  jr    $ra
/* 0E9C94 7F0B72A4 00000000 */   nop
)
#endif

#endif




#define PORTMAX 200
#ifdef NONMATCHING
//bgPortalDesend
void sub_GAME_7F0B7F84(void, int p, int arg2) {
    if (arg2 > 100)
        {
        osSyncPrintf("bg: << Deep\n");
    }
    assert(p<PORTMAX);
    osSyncPrintf("bg: << bgPortalDescend: Inside out portal \'%s\' ",bgDebPrintPORTALID(p)    );
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7F84
/* 0ECAB4 7F0B7F84 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0ECAB8 7F0B7F88 3C028004 */  lui   $v0, %hi(D_80044898)
/* 0ECABC 7F0B7F8C 24424898 */  addiu $v0, %lo(D_80044898) # addiu $v0, $v0, 0x4898
/* 0ECAC0 7F0B7F90 8C4E0000 */  lw    $t6, ($v0)
/* 0ECAC4 7F0B7F94 AFB40030 */  sw    $s4, 0x30($sp)
/* 0ECAC8 7F0B7F98 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0ECACC 7F0B7F9C AFB20028 */  sw    $s2, 0x28($sp)
/* 0ECAD0 7F0B7FA0 28E10065 */  slti  $at, $a3, 0x65
/* 0ECAD4 7F0B7FA4 25CF0001 */  addiu $t7, $t6, 1
/* 0ECAD8 7F0B7FA8 00809025 */  move  $s2, $a0
/* 0ECADC 7F0B7FAC 00E09825 */  move  $s3, $a3
/* 0ECAE0 7F0B7FB0 00C0A025 */  move  $s4, $a2
/* 0ECAE4 7F0B7FB4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0ECAE8 7F0B7FB8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0ECAEC 7F0B7FBC AFB00020 */  sw    $s0, 0x20($sp)
/* 0ECAF0 7F0B7FC0 AFA50084 */  sw    $a1, 0x84($sp)
/* 0ECAF4 7F0B7FC4 14200003 */  bnez  $at, .L7F0B7FD4
/* 0ECAF8 7F0B7FC8 AC4F0000 */   sw    $t7, ($v0)
/* 0ECAFC 7F0B7FCC 100000E1 */  b     .L7F0B8354
/* 0ECB00 7F0B7FD0 00801025 */   move  $v0, $a0
.L7F0B7FD4:
/* 0ECB04 7F0B7FD4 3C188004 */  lui   $t8, %hi(D_8004489C)
/* 0ECB08 7F0B7FD8 8F18489C */  lw    $t8, %lo(D_8004489C)($t8)
/* 0ECB0C 7F0B7FDC 0313082A */  slt   $at, $t8, $s3
/* 0ECB10 7F0B7FE0 50200004 */  beql  $at, $zero, .L7F0B7FF4
/* 0ECB14 7F0B7FE4 2A610010 */   slti  $at, $s3, 0x10
/* 0ECB18 7F0B7FE8 100000DA */  b     .L7F0B8354
/* 0ECB1C 7F0B7FEC 02401025 */   move  $v0, $s2
/* 0ECB20 7F0B7FF0 2A610010 */  slti  $at, $s3, 0x10
.L7F0B7FF4:
/* 0ECB24 7F0B7FF4 14200003 */  bnez  $at, .L7F0B8004
/* 0ECB28 7F0B7FF8 3C198008 */   lui   $t9, %hi(g_BgPortals)
/* 0ECB2C 7F0B7FFC 100000D5 */  b     .L7F0B8354
/* 0ECB30 7F0B8000 02401025 */   move  $v0, $s2
.L7F0B8004:
/* 0ECB34 7F0B8004 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0ECB38 7F0B8008 001410C0 */  sll   $v0, $s4, 3
/* 0ECB3C 7F0B800C 3C0B8004 */  lui   $t3, %hi(D_800442FC)
/* 0ECB40 7F0B8010 03224021 */  addu  $t0, $t9, $v0
/* 0ECB44 7F0B8014 91090006 */  lbu   $t1, 6($t0)
/* 0ECB48 7F0B8018 256B42FC */  addiu $t3, %lo(D_800442FC) # addiu $t3, $t3, 0x42fc
/* 0ECB4C 7F0B801C 028B1821 */  addu  $v1, $s4, $t3
/* 0ECB50 7F0B8020 312A0001 */  andi  $t2, $t1, 1
/* 0ECB54 7F0B8024 51400004 */  beql  $t2, $zero, .L7F0B8038
/* 0ECB58 7F0B8028 AFA20044 */   sw    $v0, 0x44($sp)
/* 0ECB5C 7F0B802C 100000C9 */  b     .L7F0B8354
/* 0ECB60 7F0B8030 02401025 */   move  $v0, $s2
/* 0ECB64 7F0B8034 AFA20044 */  sw    $v0, 0x44($sp)
.L7F0B8038:
/* 0ECB68 7F0B8038 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0ECB6C 7F0B803C AFA3003C */   sw    $v1, 0x3c($sp)
/* 0ECB70 7F0B8040 00408025 */  move  $s0, $v0
/* 0ECB74 7F0B8044 02802025 */  move  $a0, $s4
/* 0ECB78 7F0B8048 0FC2E5B3 */  jal   sub_GAME_7F0B96CC
/* 0ECB7C 7F0B804C 27A50054 */   addiu $a1, $sp, 0x54
/* 0ECB80 7F0B8050 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 0ECB84 7F0B8054 C6060000 */  lwc1  $f6, ($s0)
/* 0ECB88 7F0B8058 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 0ECB8C 7F0B805C C6100004 */  lwc1  $f16, 4($s0)
/* 0ECB90 7F0B8060 46062202 */  mul.s $f8, $f4, $f6
/* 0ECB94 7F0B8064 C6060008 */  lwc1  $f6, 8($s0)
/* 0ECB98 7F0B8068 3C018004 */  lui   $at, %hi(room_data_float1)
/* 0ECB9C 7F0B806C 46105482 */  mul.s $f18, $f10, $f16
/* 0ECBA0 7F0B8070 C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0ECBA4 7F0B8074 02802025 */  move  $a0, $s4
/* 0ECBA8 7F0B8078 460A3402 */  mul.s $f16, $f6, $f10
/* 0ECBAC 7F0B807C 46124100 */  add.s $f4, $f8, $f18
/* 0ECBB0 7F0B8080 C43213F4 */  lwc1  $f18, %lo(room_data_float1)($at)
/* 0ECBB4 7F0B8084 46048200 */  add.s $f8, $f16, $f4
/* 0ECBB8 7F0B8088 46124082 */  mul.s $f2, $f8, $f18
/* 0ECBBC 7F0B808C 0FC2E664 */  jal   sub_GAME_7F0B9990
/* 0ECBC0 7F0B8090 E7A20050 */   swc1  $f2, 0x50($sp)
/* 0ECBC4 7F0B8094 3C0C8008 */  lui   $t4, %hi(g_BgPortals)
/* 0ECBC8 7F0B8098 8D8CFF80 */  lw    $t4, %lo(g_BgPortals)($t4)
/* 0ECBCC 7F0B809C 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0ECBD0 7F0B80A0 8FAE0084 */  lw    $t6, 0x84($sp)
/* 0ECBD4 7F0B80A4 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0ECBD8 7F0B80A8 018D1021 */  addu  $v0, $t4, $t5
/* 0ECBDC 7F0B80AC 90430004 */  lbu   $v1, 4($v0)
/* 0ECBE0 7F0B80B0 55C3000B */  bnel  $t6, $v1, .L7F0B80E0
/* 0ECBE4 7F0B80B4 46001100 */   add.s $f4, $f2, $f0
/* 0ECBE8 7F0B80B8 46001181 */  sub.s $f6, $f2, $f0
/* 0ECBEC 7F0B80BC C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0ECBF0 7F0B80C0 90510005 */  lbu   $s1, 5($v0)
/* 0ECBF4 7F0B80C4 4606503E */  c.le.s $f10, $f6
/* 0ECBF8 7F0B80C8 00000000 */  nop
/* 0ECBFC 7F0B80CC 4502000D */  bc1fl .L7F0B8104
/* 0ECC00 7F0B80D0 C7A80060 */   lwc1  $f8, 0x60($sp)
/* 0ECC04 7F0B80D4 1000009F */  b     .L7F0B8354
/* 0ECC08 7F0B80D8 02401025 */   move  $v0, $s2
/* 0ECC0C 7F0B80DC 46001100 */  add.s $f4, $f2, $f0
.L7F0B80E0:
/* 0ECC10 7F0B80E0 C7B00060 */  lwc1  $f16, 0x60($sp)
/* 0ECC14 7F0B80E4 00608825 */  move  $s1, $v1
/* 0ECC18 7F0B80E8 4610203E */  c.le.s $f4, $f16
/* 0ECC1C 7F0B80EC 00000000 */  nop
/* 0ECC20 7F0B80F0 45020004 */  bc1fl .L7F0B8104
/* 0ECC24 7F0B80F4 C7A80060 */   lwc1  $f8, 0x60($sp)
/* 0ECC28 7F0B80F8 10000096 */  b     .L7F0B8354
/* 0ECC2C 7F0B80FC 02401025 */   move  $v0, $s2
/* 0ECC30 7F0B8100 C7A80060 */  lwc1  $f8, 0x60($sp)
.L7F0B8104:
/* 0ECC34 7F0B8104 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0ECC38 7F0B8108 46004481 */  sub.s $f18, $f8, $f0
/* 0ECC3C 7F0B810C 4602903C */  c.lt.s $f18, $f2
/* 0ECC40 7F0B8110 00000000 */  nop
/* 0ECC44 7F0B8114 45020012 */  bc1fl .L7F0B8160
/* 0ECC48 7F0B8118 904F0006 */   lbu   $t7, 6($v0)
/* 0ECC4C 7F0B811C 46003280 */  add.s $f10, $f6, $f0
/* 0ECC50 7F0B8120 460A103C */  c.lt.s $f2, $f10
/* 0ECC54 7F0B8124 00000000 */  nop
/* 0ECC58 7F0B8128 4502000D */  bc1fl .L7F0B8160
/* 0ECC5C 7F0B812C 904F0006 */   lbu   $t7, 6($v0)
/* 0ECC60 7F0B8130 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0ECC64 7F0B8134 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0ECC68 7F0B8138 C4501118 */  lwc1  $f16, 0x1118($v0)
/* 0ECC6C 7F0B813C E7B00070 */  swc1  $f16, 0x70($sp)
/* 0ECC70 7F0B8140 C444111C */  lwc1  $f4, 0x111c($v0)
/* 0ECC74 7F0B8144 E7A40074 */  swc1  $f4, 0x74($sp)
/* 0ECC78 7F0B8148 C4481120 */  lwc1  $f8, 0x1120($v0)
/* 0ECC7C 7F0B814C E7A80078 */  swc1  $f8, 0x78($sp)
/* 0ECC80 7F0B8150 C4521124 */  lwc1  $f18, 0x1124($v0)
/* 0ECC84 7F0B8154 10000042 */  b     .L7F0B8260
/* 0ECC88 7F0B8158 E7B2007C */   swc1  $f18, 0x7c($sp)
/* 0ECC8C 7F0B815C 904F0006 */  lbu   $t7, 6($v0)
.L7F0B8160:
/* 0ECC90 7F0B8160 27A50070 */  addiu $a1, $sp, 0x70
/* 0ECC94 7F0B8164 02802025 */  move  $a0, $s4
/* 0ECC98 7F0B8168 31F80002 */  andi  $t8, $t7, 2
/* 0ECC9C 7F0B816C 13000021 */  beqz  $t8, .L7F0B81F4
/* 0ECCA0 7F0B8170 00000000 */   nop
/* 0ECCA4 7F0B8174 0FC2D619 */  jal   sub_GAME_7F0B5864
/* 0ECCA8 7F0B8178 02802025 */   move  $a0, $s4
/* 0ECCAC 7F0B817C 14400003 */  bnez  $v0, .L7F0B818C
/* 0ECCB0 7F0B8180 3C198008 */   lui   $t9, %hi(g_BgPortals)
/* 0ECCB4 7F0B8184 10000073 */  b     .L7F0B8354
/* 0ECCB8 7F0B8188 02401025 */   move  $v0, $s2
.L7F0B818C:
/* 0ECCBC 7F0B818C 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0ECCC0 7F0B8190 8FA80044 */  lw    $t0, 0x44($sp)
/* 0ECCC4 7F0B8194 8FAC0084 */  lw    $t4, 0x84($sp)
/* 0ECCC8 7F0B8198 27A50070 */  addiu $a1, $sp, 0x70
/* 0ECCCC 7F0B819C 03281021 */  addu  $v0, $t9, $t0
/* 0ECCD0 7F0B81A0 90490005 */  lbu   $t1, 5($v0)
/* 0ECCD4 7F0B81A4 904A0004 */  lbu   $t2, 4($v0)
/* 0ECCD8 7F0B81A8 012A5826 */  xor   $t3, $t1, $t2
/* 0ECCDC 7F0B81AC 016C8826 */  xor   $s1, $t3, $t4
/* 0ECCE0 7F0B81B0 0FC2D482 */  jal   sub_GAME_7F0B5208
/* 0ECCE4 7F0B81B4 02202025 */   move  $a0, $s1
/* 0ECCE8 7F0B81B8 14400003 */  bnez  $v0, .L7F0B81C8
/* 0ECCEC 7F0B81BC 00000000 */   nop
/* 0ECCF0 7F0B81C0 10000064 */  b     .L7F0B8354
/* 0ECCF4 7F0B81C4 02401025 */   move  $v0, $s2
.L7F0B81C8:
/* 0ECCF8 7F0B81C8 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0ECCFC 7F0B81CC 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0ECD00 7F0B81D0 C4461118 */  lwc1  $f6, 0x1118($v0)
/* 0ECD04 7F0B81D4 E7A60070 */  swc1  $f6, 0x70($sp)
/* 0ECD08 7F0B81D8 C44A111C */  lwc1  $f10, 0x111c($v0)
/* 0ECD0C 7F0B81DC E7AA0074 */  swc1  $f10, 0x74($sp)
/* 0ECD10 7F0B81E0 C4501120 */  lwc1  $f16, 0x1120($v0)
/* 0ECD14 7F0B81E4 E7B00078 */  swc1  $f16, 0x78($sp)
/* 0ECD18 7F0B81E8 C4441124 */  lwc1  $f4, 0x1124($v0)
/* 0ECD1C 7F0B81EC 1000000E */  b     .L7F0B8228
/* 0ECD20 7F0B81F0 E7A4007C */   swc1  $f4, 0x7c($sp)
.L7F0B81F4:
/* 0ECD24 7F0B81F4 0FC2D619 */  jal   sub_GAME_7F0B5864
/* 0ECD28 7F0B81F8 27A50070 */   addiu $a1, $sp, 0x70
/* 0ECD2C 7F0B81FC 14400003 */  bnez  $v0, .L7F0B820C
/* 0ECD30 7F0B8200 27A40070 */   addiu $a0, $sp, 0x70
/* 0ECD34 7F0B8204 10000053 */  b     .L7F0B8354
/* 0ECD38 7F0B8208 02401025 */   move  $v0, $s2
.L7F0B820C:
/* 0ECD3C 7F0B820C 0FC2D6F7 */  jal   bgRectIntersect
/* 0ECD40 7F0B8210 8FA50090 */   lw    $a1, 0x90($sp)
/* 0ECD44 7F0B8214 3C058008 */  lui   $a1, %hi(g_CurrentPlayer)
/* 0ECD48 7F0B8218 8CA5A0B0 */  lw    $a1, %lo(g_CurrentPlayer)($a1)
/* 0ECD4C 7F0B821C 27A40070 */  addiu $a0, $sp, 0x70
/* 0ECD50 7F0B8220 0FC2D6F7 */  jal   bgRectIntersect
/* 0ECD54 7F0B8224 24A51118 */   addiu $a1, $a1, 0x1118
.L7F0B8228:
/* 0ECD58 7F0B8228 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0ECD5C 7F0B822C C7B20078 */  lwc1  $f18, 0x78($sp)
/* 0ECD60 7F0B8230 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0ECD64 7F0B8234 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0ECD68 7F0B8238 4608903E */  c.le.s $f18, $f8
/* 0ECD6C 7F0B823C 00000000 */  nop
/* 0ECD70 7F0B8240 45010005 */  bc1t  .L7F0B8258
/* 0ECD74 7F0B8244 00000000 */   nop
/* 0ECD78 7F0B8248 4606503E */  c.le.s $f10, $f6
/* 0ECD7C 7F0B824C 00000000 */  nop
/* 0ECD80 7F0B8250 45020004 */  bc1fl .L7F0B8264
/* 0ECD84 7F0B8254 8FAD003C */   lw    $t5, 0x3c($sp)
.L7F0B8258:
/* 0ECD88 7F0B8258 1000003E */  b     .L7F0B8354
/* 0ECD8C 7F0B825C 02401025 */   move  $v0, $s2
.L7F0B8260:
/* 0ECD90 7F0B8260 8FAD003C */  lw    $t5, 0x3c($sp)
.L7F0B8264:
/* 0ECD94 7F0B8264 A1B30000 */  sb    $s3, ($t5)
/* 0ECD98 7F0B8268 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0ECD9C 7F0B826C C7B00070 */  lwc1  $f16, 0x70($sp)
/* 0ECDA0 7F0B8270 C7B2007C */  lwc1  $f18, 0x7c($sp)
/* 0ECDA4 7F0B8274 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0ECDA8 7F0B8278 4604803C */  c.lt.s $f16, $f4
/* 0ECDAC 7F0B827C 00000000 */  nop
/* 0ECDB0 7F0B8280 45000013 */  bc1f  .L7F0B82D0
/* 0ECDB4 7F0B8284 00000000 */   nop
/* 0ECDB8 7F0B8288 4612403C */  c.lt.s $f8, $f18
/* 0ECDBC 7F0B828C 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0ECDC0 7F0B8290 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0ECDC4 7F0B8294 4500000E */  bc1f  .L7F0B82D0
/* 0ECDC8 7F0B8298 00000000 */   nop
/* 0ECDCC 7F0B829C 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0ECDD0 7F0B82A0 02202025 */  move  $a0, $s1
/* 0ECDD4 7F0B82A4 02602825 */  move  $a1, $s3
/* 0ECDD8 7F0B82A8 01CFC021 */  addu  $t8, $t6, $t7
/* 0ECDDC 7F0B82AC 93070006 */  lbu   $a3, 6($t8)
/* 0ECDE0 7F0B82B0 27A60070 */  addiu $a2, $sp, 0x70
/* 0ECDE4 7F0B82B4 30F90002 */  andi  $t9, $a3, 2
/* 0ECDE8 7F0B82B8 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ECDEC 7F0B82BC 03203825 */   move  $a3, $t9
/* 0ECDF0 7F0B82C0 10400005 */  beqz  $v0, .L7F0B82D8
/* 0ECDF4 7F0B82C4 3C048008 */   lui   $a0, %hi(g_BgPortals)
/* 0ECDF8 7F0B82C8 10000022 */  b     .L7F0B8354
/* 0ECDFC 7F0B82CC 02401025 */   move  $v0, $s2
.L7F0B82D0:
/* 0ECE00 7F0B82D0 10000020 */  b     .L7F0B8354
/* 0ECE04 7F0B82D4 02401025 */   move  $v0, $s2
.L7F0B82D8:
/* 0ECE08 7F0B82D8 8C84FF80 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0ECE0C 7F0B82DC 00008025 */  move  $s0, $zero
/* 0ECE10 7F0B82E0 00001825 */  move  $v1, $zero
/* 0ECE14 7F0B82E4 8C880000 */  lw    $t0, ($a0)
/* 0ECE18 7F0B82E8 00801025 */  move  $v0, $a0
/* 0ECE1C 7F0B82EC 51000019 */  beql  $t0, $zero, .L7F0B8354
/* 0ECE20 7F0B82F0 02401025 */   move  $v0, $s2
.L7F0B82F4:
/* 0ECE24 7F0B82F4 52140012 */  beql  $s0, $s4, .L7F0B8340
/* 0ECE28 7F0B82F8 8C4D0008 */   lw    $t5, 8($v0)
/* 0ECE2C 7F0B82FC 90490004 */  lbu   $t1, 4($v0)
/* 0ECE30 7F0B8300 02402025 */  move  $a0, $s2
/* 0ECE34 7F0B8304 02202825 */  move  $a1, $s1
/* 0ECE38 7F0B8308 12290003 */  beq   $s1, $t1, .L7F0B8318
/* 0ECE3C 7F0B830C 02003025 */   move  $a2, $s0
/* 0ECE40 7F0B8310 904A0005 */  lbu   $t2, 5($v0)
/* 0ECE44 7F0B8314 162A0009 */  bne   $s1, $t2, .L7F0B833C
.L7F0B8318:
/* 0ECE48 7F0B8318 27AB0070 */   addiu $t3, $sp, 0x70
/* 0ECE4C 7F0B831C AFAB0010 */  sw    $t3, 0x10($sp)
/* 0ECE50 7F0B8320 26670001 */  addiu $a3, $s3, 1
/* 0ECE54 7F0B8324 0FC2DF79 */  jal   sub_GAME_7F0B7DE4
/* 0ECE58 7F0B8328 AFA30040 */   sw    $v1, 0x40($sp)
/* 0ECE5C 7F0B832C 3C0C8008 */  lui   $t4, %hi(g_BgPortals)
/* 0ECE60 7F0B8330 8D8CFF80 */  lw    $t4, %lo(g_BgPortals)($t4)
/* 0ECE64 7F0B8334 8FA30040 */  lw    $v1, 0x40($sp)
/* 0ECE68 7F0B8338 01831021 */  addu  $v0, $t4, $v1
.L7F0B833C:
/* 0ECE6C 7F0B833C 8C4D0008 */  lw    $t5, 8($v0)
.L7F0B8340:
/* 0ECE70 7F0B8340 26100001 */  addiu $s0, $s0, 1
/* 0ECE74 7F0B8344 24630008 */  addiu $v1, $v1, 8
/* 0ECE78 7F0B8348 15A0FFEA */  bnez  $t5, .L7F0B82F4
/* 0ECE7C 7F0B834C 24420008 */   addiu $v0, $v0, 8
/* 0ECE80 7F0B8350 02401025 */  move  $v0, $s2
.L7F0B8354:
/* 0ECE84 7F0B8354 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0ECE88 7F0B8358 8FB00020 */  lw    $s0, 0x20($sp)
/* 0ECE8C 7F0B835C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0ECE90 7F0B8360 8FB20028 */  lw    $s2, 0x28($sp)
/* 0ECE94 7F0B8364 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0ECE98 7F0B8368 8FB40030 */  lw    $s4, 0x30($sp)
/* 0ECE9C 7F0B836C 03E00008 */  jr    $ra
/* 0ECEA0 7F0B8370 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B7F84
/* 0E9C98 7F0B72A8 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0E9C9C 7F0B72AC 3C028004 */  lui   $v0, %hi(D_80044898) # $v0, 0x8004
/* 0E9CA0 7F0B72B0 2442DD80 */  addiu $v0, %lo(D_80044898) # addiu $v0, $v0, -0x2280
/* 0E9CA4 7F0B72B4 8C4E0000 */  lw    $t6, ($v0)
/* 0E9CA8 7F0B72B8 AFB30020 */  sw    $s3, 0x20($sp)
/* 0E9CAC 7F0B72BC AFB2001C */  sw    $s2, 0x1c($sp)
/* 0E9CB0 7F0B72C0 28C10065 */  slti  $at, $a2, 0x65
/* 0E9CB4 7F0B72C4 25CF0001 */  addiu $t7, $t6, 1
/* 0E9CB8 7F0B72C8 00C09025 */  move  $s2, $a2
/* 0E9CBC 7F0B72CC 00A09825 */  move  $s3, $a1
/* 0E9CC0 7F0B72D0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0E9CC4 7F0B72D4 AFB10018 */  sw    $s1, 0x18($sp)
/* 0E9CC8 7F0B72D8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0E9CCC 7F0B72DC AFA40070 */  sw    $a0, 0x70($sp)
/* 0E9CD0 7F0B72E0 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0E9CD4 7F0B72E4 102000C8 */  beqz  $at, .L7F0B7608
/* 0E9CD8 7F0B72E8 AC4F0000 */   sw    $t7, ($v0)
/* 0E9CDC 7F0B72EC 3C188004 */  lui   $t8, %hi(D_8004489C) # $t8, 0x8004
/* 0E9CE0 7F0B72F0 8F18DD84 */  lw    $t8, %lo(D_8004489C)($t8)
/* 0E9CE4 7F0B72F4 0306082A */  slt   $at, $t8, $a2
/* 0E9CE8 7F0B72F8 142000C3 */  bnez  $at, .L7F0B7608
/* 0E9CEC 7F0B72FC 28C10010 */   slti  $at, $a2, 0x10
/* 0E9CF0 7F0B7300 102000C1 */  beqz  $at, .L7F0B7608
/* 0E9CF4 7F0B7304 3C198007 */   lui   $t9, %hi(g_BgPortals) # $t9, 0x8007
/* 0E9CF8 7F0B7308 8F39B3C8 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0E9CFC 7F0B730C 000510C0 */  sll   $v0, $a1, 3
/* 0E9D00 7F0B7310 3C0B8004 */  lui   $t3, %hi(D_800442FC) # $t3, 0x8004
/* 0E9D04 7F0B7314 03224021 */  addu  $t0, $t9, $v0
/* 0E9D08 7F0B7318 91090006 */  lbu   $t1, 6($t0)
/* 0E9D0C 7F0B731C 256BD7DC */  addiu $t3, %lo(D_800442FC) # addiu $t3, $t3, -0x2824
/* 0E9D10 7F0B7320 00AB1821 */  addu  $v1, $a1, $t3
/* 0E9D14 7F0B7324 312A0001 */  andi  $t2, $t1, 1
/* 0E9D18 7F0B7328 554000B8 */  bnezl $t2, .L7F0B760C
/* 0E9D1C 7F0B732C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9D20 7F0B7330 AFA20034 */  sw    $v0, 0x34($sp)
/* 0E9D24 7F0B7334 0FC22868 */  jal   bondviewGetCurrentPlayersPosition
/* 0E9D28 7F0B7338 AFA3002C */   sw    $v1, 0x2c($sp)
/* 0E9D2C 7F0B733C 00408025 */  move  $s0, $v0
/* 0E9D30 7F0B7340 02602025 */  move  $a0, $s3
/* 0E9D34 7F0B7344 0FC2E25A */  jal   sub_GAME_7F0B96CC
/* 0E9D38 7F0B7348 27A50044 */   addiu $a1, $sp, 0x44
/* 0E9D3C 7F0B734C C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0E9D40 7F0B7350 C6060000 */  lwc1  $f6, ($s0)
/* 0E9D44 7F0B7354 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0E9D48 7F0B7358 C6100004 */  lwc1  $f16, 4($s0)
/* 0E9D4C 7F0B735C 46062202 */  mul.s $f8, $f4, $f6
/* 0E9D50 7F0B7360 C6060008 */  lwc1  $f6, 8($s0)
/* 0E9D54 7F0B7364 3C018004 */  lui   $at, %hi(room_data_float1) # $at, 0x8004
/* 0E9D58 7F0B7368 46105482 */  mul.s $f18, $f10, $f16
/* 0E9D5C 7F0B736C C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0E9D60 7F0B7370 02602025 */  move  $a0, $s3
/* 0E9D64 7F0B7374 460A3402 */  mul.s $f16, $f6, $f10
/* 0E9D68 7F0B7378 46124100 */  add.s $f4, $f8, $f18
/* 0E9D6C 7F0B737C C432AC44 */  lwc1  $f18, %lo(room_data_float1)($at)
/* 0E9D70 7F0B7380 46048200 */  add.s $f8, $f16, $f4
/* 0E9D74 7F0B7384 46124082 */  mul.s $f2, $f8, $f18
/* 0E9D78 7F0B7388 0FC2E30B */  jal   sub_GAME_7F0B9990
/* 0E9D7C 7F0B738C E7A20040 */   swc1  $f2, 0x40($sp)
/* 0E9D80 7F0B7390 3C0C8007 */  lui   $t4, %hi(g_BgPortals) # $t4, 0x8007
/* 0E9D84 7F0B7394 8D8CB3C8 */  lw    $t4, %lo(g_BgPortals)($t4)
/* 0E9D88 7F0B7398 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0E9D8C 7F0B739C 8FAE0070 */  lw    $t6, 0x70($sp)
/* 0E9D90 7F0B73A0 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 0E9D94 7F0B73A4 018D1021 */  addu  $v0, $t4, $t5
/* 0E9D98 7F0B73A8 90430004 */  lbu   $v1, 4($v0)
/* 0E9D9C 7F0B73AC 55C3000B */  bnel  $t6, $v1, .L7F0B73DC
/* 0E9DA0 7F0B73B0 46001100 */   add.s $f4, $f2, $f0
/* 0E9DA4 7F0B73B4 46001181 */  sub.s $f6, $f2, $f0
/* 0E9DA8 7F0B73B8 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 0E9DAC 7F0B73BC 90510005 */  lbu   $s1, 5($v0)
/* 0E9DB0 7F0B73C0 4606503E */  c.le.s $f10, $f6
/* 0E9DB4 7F0B73C4 00000000 */  nop
/* 0E9DB8 7F0B73C8 4502000B */  bc1fl .L7F0B73F8
/* 0E9DBC 7F0B73CC C7A80050 */   lwc1  $f8, 0x50($sp)
/* 0E9DC0 7F0B73D0 1000008E */  b     .L7F0B760C
/* 0E9DC4 7F0B73D4 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9DC8 7F0B73D8 46001100 */  add.s $f4, $f2, $f0
.L7F0B73DC:
/* 0E9DCC 7F0B73DC C7B00050 */  lwc1  $f16, 0x50($sp)
/* 0E9DD0 7F0B73E0 00608825 */  move  $s1, $v1
/* 0E9DD4 7F0B73E4 4610203E */  c.le.s $f4, $f16
/* 0E9DD8 7F0B73E8 00000000 */  nop
/* 0E9DDC 7F0B73EC 45030087 */  bc1tl .L7F0B760C
/* 0E9DE0 7F0B73F0 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9DE4 7F0B73F4 C7A80050 */  lwc1  $f8, 0x50($sp)
.L7F0B73F8:
/* 0E9DE8 7F0B73F8 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 0E9DEC 7F0B73FC 46004481 */  sub.s $f18, $f8, $f0
/* 0E9DF0 7F0B7400 4602903C */  c.lt.s $f18, $f2
/* 0E9DF4 7F0B7404 00000000 */  nop
/* 0E9DF8 7F0B7408 45020012 */  bc1fl .L7F0B7454
/* 0E9DFC 7F0B740C 904F0006 */   lbu   $t7, 6($v0)
/* 0E9E00 7F0B7410 46003280 */  add.s $f10, $f6, $f0
/* 0E9E04 7F0B7414 460A103C */  c.lt.s $f2, $f10
/* 0E9E08 7F0B7418 00000000 */  nop
/* 0E9E0C 7F0B741C 4502000D */  bc1fl .L7F0B7454
/* 0E9E10 7F0B7420 904F0006 */   lbu   $t7, 6($v0)
/* 0E9E14 7F0B7424 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0E9E18 7F0B7428 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0E9E1C 7F0B742C C4501110 */  lwc1  $f16, 0x1110($v0)
/* 0E9E20 7F0B7430 E7B00060 */  swc1  $f16, 0x60($sp)
/* 0E9E24 7F0B7434 C4441114 */  lwc1  $f4, 0x1114($v0)
/* 0E9E28 7F0B7438 E7A40064 */  swc1  $f4, 0x64($sp)
/* 0E9E2C 7F0B743C C4481118 */  lwc1  $f8, 0x1118($v0)
/* 0E9E30 7F0B7440 E7A80068 */  swc1  $f8, 0x68($sp)
/* 0E9E34 7F0B7444 C452111C */  lwc1  $f18, 0x111c($v0)
/* 0E9E38 7F0B7448 10000039 */  b     .L7F0B7530
/* 0E9E3C 7F0B744C E7B2006C */   swc1  $f18, 0x6c($sp)
/* 0E9E40 7F0B7450 904F0006 */  lbu   $t7, 6($v0)
.L7F0B7454:
/* 0E9E44 7F0B7454 27A50060 */  addiu $a1, $sp, 0x60
/* 0E9E48 7F0B7458 02602025 */  move  $a0, $s3
/* 0E9E4C 7F0B745C 31F80002 */  andi  $t8, $t7, 2
/* 0E9E50 7F0B7460 1300001C */  beqz  $t8, .L7F0B74D4
/* 0E9E54 7F0B7464 00000000 */   nop
/* 0E9E58 7F0B7468 0FC2D2E8 */  jal   sub_GAME_7F0B5864
/* 0E9E5C 7F0B746C 02602025 */   move  $a0, $s3
/* 0E9E60 7F0B7470 10400065 */  beqz  $v0, .L7F0B7608
/* 0E9E64 7F0B7474 3C198007 */   lui   $t9, %hi(g_BgPortals) # $t9, 0x8007
/* 0E9E68 7F0B7478 8F39B3C8 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0E9E6C 7F0B747C 8FA80034 */  lw    $t0, 0x34($sp)
/* 0E9E70 7F0B7480 8FAC0070 */  lw    $t4, 0x70($sp)
/* 0E9E74 7F0B7484 27A50060 */  addiu $a1, $sp, 0x60
/* 0E9E78 7F0B7488 03281021 */  addu  $v0, $t9, $t0
/* 0E9E7C 7F0B748C 90490005 */  lbu   $t1, 5($v0)
/* 0E9E80 7F0B7490 904A0004 */  lbu   $t2, 4($v0)
/* 0E9E84 7F0B7494 012A5826 */  xor   $t3, $t1, $t2
/* 0E9E88 7F0B7498 016C8826 */  xor   $s1, $t3, $t4
/* 0E9E8C 7F0B749C 0FC2D151 */  jal   sub_GAME_7F0B5208
/* 0E9E90 7F0B74A0 02202025 */   move  $a0, $s1
/* 0E9E94 7F0B74A4 10400058 */  beqz  $v0, .L7F0B7608
/* 0E9E98 7F0B74A8 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0E9E9C 7F0B74AC 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0E9EA0 7F0B74B0 C4461110 */  lwc1  $f6, 0x1110($v0)
/* 0E9EA4 7F0B74B4 E7A60060 */  swc1  $f6, 0x60($sp)
/* 0E9EA8 7F0B74B8 C44A1114 */  lwc1  $f10, 0x1114($v0)
/* 0E9EAC 7F0B74BC E7AA0064 */  swc1  $f10, 0x64($sp)
/* 0E9EB0 7F0B74C0 C4501118 */  lwc1  $f16, 0x1118($v0)
/* 0E9EB4 7F0B74C4 E7B00068 */  swc1  $f16, 0x68($sp)
/* 0E9EB8 7F0B74C8 C444111C */  lwc1  $f4, 0x111c($v0)
/* 0E9EBC 7F0B74CC 1000000C */  b     .L7F0B7500
/* 0E9EC0 7F0B74D0 E7A4006C */   swc1  $f4, 0x6c($sp)
.L7F0B74D4:
/* 0E9EC4 7F0B74D4 0FC2D2E8 */  jal   sub_GAME_7F0B5864
/* 0E9EC8 7F0B74D8 27A50060 */   addiu $a1, $sp, 0x60
/* 0E9ECC 7F0B74DC 1040004A */  beqz  $v0, .L7F0B7608
/* 0E9ED0 7F0B74E0 27A40060 */   addiu $a0, $sp, 0x60
/* 0E9ED4 7F0B74E4 0FC2D3C6 */  jal   bgRectIntersect
/* 0E9ED8 7F0B74E8 8FA5007C */   lw    $a1, 0x7c($sp)
/* 0E9EDC 7F0B74EC 3C058007 */  lui   $a1, %hi(g_CurrentPlayer) # $a1, 0x8007
/* 0E9EE0 7F0B74F0 8CA58BC0 */  lw    $a1, %lo(g_CurrentPlayer)($a1)
/* 0E9EE4 7F0B74F4 27A40060 */  addiu $a0, $sp, 0x60
/* 0E9EE8 7F0B74F8 0FC2D3C6 */  jal   bgRectIntersect
/* 0E9EEC 7F0B74FC 24A51110 */   addiu $a1, $a1, 0x1110
.L7F0B7500:
/* 0E9EF0 7F0B7500 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0E9EF4 7F0B7504 C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0E9EF8 7F0B7508 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0E9EFC 7F0B750C C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0E9F00 7F0B7510 4608903E */  c.le.s $f18, $f8
/* 0E9F04 7F0B7514 00000000 */  nop
/* 0E9F08 7F0B7518 4503003C */  bc1tl .L7F0B760C
/* 0E9F0C 7F0B751C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9F10 7F0B7520 4606503E */  c.le.s $f10, $f6
/* 0E9F14 7F0B7524 00000000 */  nop
/* 0E9F18 7F0B7528 45030038 */  bc1tl .L7F0B760C
/* 0E9F1C 7F0B752C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F0B7530:
/* 0E9F20 7F0B7530 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0E9F24 7F0B7534 A1B20000 */  sb    $s2, ($t5)
/* 0E9F28 7F0B7538 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0E9F2C 7F0B753C C7B00060 */  lwc1  $f16, 0x60($sp)
/* 0E9F30 7F0B7540 C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0E9F34 7F0B7544 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0E9F38 7F0B7548 4604803C */  c.lt.s $f16, $f4
/* 0E9F3C 7F0B754C 00000000 */  nop
/* 0E9F40 7F0B7550 4502002E */  bc1fl .L7F0B760C
/* 0E9F44 7F0B7554 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9F48 7F0B7558 4612403C */  c.lt.s $f8, $f18
/* 0E9F4C 7F0B755C 3C0E8007 */  lui   $t6, %hi(g_BgPortals) # $t6, 0x8007
/* 0E9F50 7F0B7560 8FAF0034 */  lw    $t7, 0x34($sp)
/* 0E9F54 7F0B7564 45020029 */  bc1fl .L7F0B760C
/* 0E9F58 7F0B7568 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0E9F5C 7F0B756C 8DCEB3C8 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0E9F60 7F0B7570 02202025 */  move  $a0, $s1
/* 0E9F64 7F0B7574 02402825 */  move  $a1, $s2
/* 0E9F68 7F0B7578 01CFC021 */  addu  $t8, $t6, $t7
/* 0E9F6C 7F0B757C 93070006 */  lbu   $a3, 6($t8)
/* 0E9F70 7F0B7580 27A60060 */  addiu $a2, $sp, 0x60
/* 0E9F74 7F0B7584 30F90002 */  andi  $t9, $a3, 2
/* 0E9F78 7F0B7588 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0E9F7C 7F0B758C 03203825 */   move  $a3, $t9
/* 0E9F80 7F0B7590 1440001D */  bnez  $v0, .L7F0B7608
/* 0E9F84 7F0B7594 3C048007 */   lui   $a0, %hi(g_BgPortals) # $a0, 0x8007
/* 0E9F88 7F0B7598 8C84B3C8 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0E9F8C 7F0B759C 00008025 */  move  $s0, $zero
/* 0E9F90 7F0B75A0 00001825 */  move  $v1, $zero
/* 0E9F94 7F0B75A4 8C880000 */  lw    $t0, ($a0)
/* 0E9F98 7F0B75A8 00801025 */  move  $v0, $a0
/* 0E9F9C 7F0B75AC 51000017 */  beql  $t0, $zero, .L7F0B760C
/* 0E9FA0 7F0B75B0 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F0B75B4:
/* 0E9FA4 7F0B75B4 52130010 */  beql  $s0, $s3, .L7F0B75F8
/* 0E9FA8 7F0B75B8 8C4C0008 */   lw    $t4, 8($v0)
/* 0E9FAC 7F0B75BC 90490004 */  lbu   $t1, 4($v0)
/* 0E9FB0 7F0B75C0 02202025 */  move  $a0, $s1
/* 0E9FB4 7F0B75C4 02002825 */  move  $a1, $s0
/* 0E9FB8 7F0B75C8 12290003 */  beq   $s1, $t1, .L7F0B75D8
/* 0E9FBC 7F0B75CC 26460001 */   addiu $a2, $s2, 1
/* 0E9FC0 7F0B75D0 904A0005 */  lbu   $t2, 5($v0)
/* 0E9FC4 7F0B75D4 162A0007 */  bne   $s1, $t2, .Leu7F0B75F4
.L7F0B75D8:
/* 0E9FC8 7F0B75D8 27A70060 */   addiu $a3, $sp, 0x60
/* 0E9FCC 7F0B75DC 0FC2DC48 */  jal   sub_GAME_7F0B7DE4
/* 0E9FD0 7F0B75E0 AFA30030 */   sw    $v1, 0x30($sp)
/* 0E9FD4 7F0B75E4 3C0B8007 */  lui   $t3, %hi(g_BgPortals) # $t3, 0x8007
/* 0E9FD8 7F0B75E8 8D6BB3C8 */  lw    $t3, %lo(g_BgPortals)($t3)
/* 0E9FDC 7F0B75EC 8FA30030 */  lw    $v1, 0x30($sp)
/* 0E9FE0 7F0B75F0 01631021 */  addu  $v0, $t3, $v1
.Leu7F0B75F4:
/* 0E9FE4 7F0B75F4 8C4C0008 */  lw    $t4, 8($v0)
.L7F0B75F8:
/* 0E9FE8 7F0B75F8 26100001 */  addiu $s0, $s0, 1
/* 0E9FEC 7F0B75FC 24630008 */  addiu $v1, $v1, 8
/* 0E9FF0 7F0B7600 1580FFEC */  bnez  $t4, .L7F0B75B4
/* 0E9FF4 7F0B7604 24420008 */   addiu $v0, $v0, 8
.L7F0B7608:
/* 0E9FF8 7F0B7608 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F0B760C:
/* 0E9FFC 7F0B760C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EA000 7F0B7610 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EA004 7F0B7614 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0EA008 7F0B7618 8FB30020 */  lw    $s3, 0x20($sp)
/* 0EA00C 7F0B761C 03E00008 */  jr    $ra
/* 0EA010 7F0B7620 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif

#endif





/**
 * Add to stack. Push and then increment position. Will wrap on overflow.
 *
 * Address 0x7F0B8374.
 */
s32 bgStackPush(s32 arg0)
{
    g_BgStack[g_BgStackCount] = arg0;
    g_BgStackCount = (s32) (g_BgStackCount + 1) % BG_STACK_SIZE;
    return arg0;
}




/**
 * Pop from stack. Decrement position and retrieve from there. Wraps on underflow.
 *
 * Address 0x7F0B83B0.
 */
s32 bgStackPop(void)
{
    s32 val;

    // ok, who thought this was a good idea
    val = g_BgStack[g_BgStackCount = (g_BgStackCount + (BG_STACK_SIZE-1)) % BG_STACK_SIZE];
    return val;
}



s32 bgStackGetNthValueFromEnd(s32 n) {
    return g_BgStack[((g_BgStackCount - n) + (BG_STACK_SIZE - 1)) % BG_STACK_SIZE];
}





#ifdef NONMATCHING
void parse_global_vis_command_list(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
/*D:80058C80*/
glabel jpt_80058C80
.word if_statement
.word dont_exec_commands_even_on_return
.word endif_continue_exec
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word if_statement_pull_from_stack
.word toggle_exec_vs_ro
.word endif

/*D:80058CB4*/
glabel vis_command_jpt
.word break
.word push_to_stack
.word pull_from_stack
.word and_merge_last_two_on_stack
.word or_merge_last_two_on_stack
.word not_merge_last_two_on_stack
.word carrot_merge_last_two_on_stack
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word push_tf_if_in_range_rooms
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word force_visible
.word match_portal_vis
.word add_visible_room
.word remove_vis
.word visible_if_seen_through_portal
.word not_visible_if_seen_through_portal
.word disable_room
.word disable_room_range
.word preload_room
.word preload_room_range
.text
glabel parse_global_vis_command_list
/* 0ECF44 7F0B8414 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0ECF48 7F0B8418 AFB30024 */  sw    $s3, 0x24($sp)
/* 0ECF4C 7F0B841C AFB20020 */  sw    $s2, 0x20($sp)
/* 0ECF50 7F0B8420 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0ECF54 7F0B8424 3C018008 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
/* 0ECF58 7F0B8428 00808825 */  move  $s1, $a0
/* 0ECF5C 7F0B842C 00A09025 */  move  $s2, $a1
/* 0ECF60 7F0B8430 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0ECF64 7F0B8434 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0ECF68 7F0B8438 AFB70034 */  sw    $s7, 0x34($sp)
/* 0ECF6C 7F0B843C AFB60030 */  sw    $s6, 0x30($sp)
/* 0ECF70 7F0B8440 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0ECF74 7F0B8444 AFB40028 */  sw    $s4, 0x28($sp)
/* 0ECF78 7F0B8448 AFB00018 */  sw    $s0, 0x18($sp)
/* 0ECF7C 7F0B844C 24130001 */  li    $s3, 1
/* 0ECF80 7F0B8450 14800003 */  bnez  $a0, .L7F0B8460
/* 0ECF84 7F0B8454 AC201610 */   sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
/* 0ECF88 7F0B8458 10000166 */  b     .L7F0B89F4
/* 0ECF8C 7F0B845C 00801025 */   move  $v0, $a0
.L7F0B8460:
/* 0ECF90 7F0B8460 3C1E8008 */  lui   $fp, %hi(g_CurrentPlayer)
/* 0ECF94 7F0B8464 3C168008 */  lui   $s6, %hi(dword_CODE_bss_80081600)
/* 0ECF98 7F0B8468 3C148004 */  lui   $s4, %hi(current_visibility)
/* 0ECF9C 7F0B846C 269448FC */  addiu $s4, %lo(current_visibility) # addiu $s4, $s4, 0x48fc
/* 0ECFA0 7F0B8470 26D61600 */  addiu $s6, %lo(dword_CODE_bss_80081600) # addiu $s6, $s6, 0x1600
/* 0ECFA4 7F0B8474 27DEA0B0 */  addiu $fp, %lo(g_CurrentPlayer) # addiu $fp, $fp, -0x5f50
/* 0ECFA8 7F0B8478 24170001 */  li    $s7, 1
/* 0ECFAC 7F0B847C 24150001 */  li    $s5, 1
.L7F0B8480:
/* 0ECFB0 7F0B8480 92240000 */  lbu   $a0, ($s1)
.L7F0B8484:
/* 0ECFB4 7F0B8484 28810028 */  slti  $at, $a0, 0x28
/* 0ECFB8 7F0B8488 14200009 */  bnez  $at, .L7F0B84B0
/* 0ECFBC 7F0B848C 248EFFB0 */   addiu $t6, $a0, -0x50
/* 0ECFC0 7F0B8490 2DC1000D */  sltiu $at, $t6, 0xd
/* 0ECFC4 7F0B8494 10200156 */  beqz  $at, .L7F0B89F0
/* 0ECFC8 7F0B8498 000E7080 */   sll   $t6, $t6, 2
/* 0ECFCC 7F0B849C 3C018006 */  lui   $at, %hi(jpt_80058C80)
/* 0ECFD0 7F0B84A0 002E0821 */  addu  $at, $at, $t6
/* 0ECFD4 7F0B84A4 8C2E8C80 */  lw    $t6, %lo(jpt_80058C80)($at)
/* 0ECFD8 7F0B84A8 01C00008 */  jr    $t6
/* 0ECFDC 7F0B84AC 00000000 */   nop
.L7F0B84B0:
/* 0ECFE0 7F0B84B0 2C810028 */  sltiu $at, $a0, 0x28
/* 0ECFE4 7F0B84B4 1020014E */  beqz  $at, .L7F0B89F0
/* 0ECFE8 7F0B84B8 00047880 */   sll   $t7, $a0, 2
/* 0ECFEC 7F0B84BC 3C018006 */  lui   $at, %hi(vis_command_jpt)
/* 0ECFF0 7F0B84C0 002F0821 */  addu  $at, $at, $t7
/* 0ECFF4 7F0B84C4 8C2F8CB4 */  lw    $t7, %lo(vis_command_jpt)($at)
/* 0ECFF8 7F0B84C8 01E00008 */  jr    $t7
/* 0ECFFC 7F0B84CC 00000000 */   nop
break:
/* 0ED000 7F0B84D0 10000148 */  b     .L7F0B89F4
/* 0ED004 7F0B84D4 02201025 */   move  $v0, $s1
push_to_stack:
/* 0ED008 7F0B84D8 52400004 */  beql  $s2, $zero, .L7F0B84EC
/* 0ED00C 7F0B84DC 92380001 */   lbu   $t8, 1($s1)
/* 0ED010 7F0B84E0 0FC2E0DD */  jal   bgStackPush
/* 0ED014 7F0B84E4 8E240004 */   lw    $a0, 4($s1)
/* 0ED018 7F0B84E8 92380001 */  lbu   $t8, 1($s1)
.L7F0B84EC:
/* 0ED01C 7F0B84EC 0018C8C0 */  sll   $t9, $t8, 3
/* 0ED020 7F0B84F0 1000FFE3 */  b     .L7F0B8480
/* 0ED024 7F0B84F4 02398821 */   addu  $s1, $s1, $t9
pull_from_stack:
/* 0ED028 7F0B84F8 52400004 */  beql  $s2, $zero, .L7F0B850C
/* 0ED02C 7F0B84FC 92280001 */   lbu   $t0, 1($s1)
/* 0ED030 7F0B8500 0FC2E0EC */  jal   bgStackPop
/* 0ED034 7F0B8504 00000000 */   nop
/* 0ED038 7F0B8508 92280001 */  lbu   $t0, 1($s1)
.L7F0B850C:
/* 0ED03C 7F0B850C 000848C0 */  sll   $t1, $t0, 3
/* 0ED040 7F0B8510 1000FFDB */  b     .L7F0B8480
/* 0ED044 7F0B8514 02298821 */   addu  $s1, $s1, $t1
and_merge_last_two_on_stack:
/* 0ED048 7F0B8518 52400008 */  beql  $s2, $zero, .L7F0B853C
/* 0ED04C 7F0B851C 922A0001 */   lbu   $t2, 1($s1)
/* 0ED050 7F0B8520 0FC2E0EC */  jal   bgStackPop
/* 0ED054 7F0B8524 00000000 */   nop
/* 0ED058 7F0B8528 0FC2E0EC */  jal   bgStackPop
/* 0ED05C 7F0B852C 00408025 */   move  $s0, $v0
/* 0ED060 7F0B8530 0FC2E0DD */  jal   bgStackPush
/* 0ED064 7F0B8534 00502024 */   and   $a0, $v0, $s0
/* 0ED068 7F0B8538 922A0001 */  lbu   $t2, 1($s1)
.L7F0B853C:
/* 0ED06C 7F0B853C 000A58C0 */  sll   $t3, $t2, 3
/* 0ED070 7F0B8540 1000FFCF */  b     .L7F0B8480
/* 0ED074 7F0B8544 022B8821 */   addu  $s1, $s1, $t3
or_merge_last_two_on_stack:
/* 0ED078 7F0B8548 52400008 */  beql  $s2, $zero, .L7F0B856C
/* 0ED07C 7F0B854C 922C0001 */   lbu   $t4, 1($s1)
/* 0ED080 7F0B8550 0FC2E0EC */  jal   bgStackPop
/* 0ED084 7F0B8554 00000000 */   nop
/* 0ED088 7F0B8558 0FC2E0EC */  jal   bgStackPop
/* 0ED08C 7F0B855C 00408025 */   move  $s0, $v0
/* 0ED090 7F0B8560 0FC2E0DD */  jal   bgStackPush
/* 0ED094 7F0B8564 00502025 */   or    $a0, $v0, $s0
/* 0ED098 7F0B8568 922C0001 */  lbu   $t4, 1($s1)
.L7F0B856C:
/* 0ED09C 7F0B856C 000C68C0 */  sll   $t5, $t4, 3
/* 0ED0A0 7F0B8570 1000FFC3 */  b     .L7F0B8480
/* 0ED0A4 7F0B8574 022D8821 */   addu  $s1, $s1, $t5
not_merge_last_two_on_stack:
/* 0ED0A8 7F0B8578 52400006 */  beql  $s2, $zero, .L7F0B8594
/* 0ED0AC 7F0B857C 922E0001 */   lbu   $t6, 1($s1)
/* 0ED0B0 7F0B8580 0FC2E0EC */  jal   bgStackPop
/* 0ED0B4 7F0B8584 00000000 */   nop
/* 0ED0B8 7F0B8588 0FC2E0DD */  jal   bgStackPush
/* 0ED0BC 7F0B858C 2C440001 */   sltiu $a0, $v0, 1
/* 0ED0C0 7F0B8590 922E0001 */  lbu   $t6, 1($s1)
.L7F0B8594:
/* 0ED0C4 7F0B8594 000E78C0 */  sll   $t7, $t6, 3
/* 0ED0C8 7F0B8598 1000FFB9 */  b     .L7F0B8480
/* 0ED0CC 7F0B859C 022F8821 */   addu  $s1, $s1, $t7
carrot_merge_last_two_on_stack:
/* 0ED0D0 7F0B85A0 52400008 */  beql  $s2, $zero, .L7F0B85C4
/* 0ED0D4 7F0B85A4 92380001 */   lbu   $t8, 1($s1)
/* 0ED0D8 7F0B85A8 0FC2E0EC */  jal   bgStackPop
/* 0ED0DC 7F0B85AC 00000000 */   nop
/* 0ED0E0 7F0B85B0 0FC2E0EC */  jal   bgStackPop
/* 0ED0E4 7F0B85B4 00408025 */   move  $s0, $v0
/* 0ED0E8 7F0B85B8 0FC2E0DD */  jal   bgStackPush
/* 0ED0EC 7F0B85BC 00502026 */   xor   $a0, $v0, $s0
/* 0ED0F0 7F0B85C0 92380001 */  lbu   $t8, 1($s1)
.L7F0B85C4:
/* 0ED0F4 7F0B85C4 0018C8C0 */  sll   $t9, $t8, 3
/* 0ED0F8 7F0B85C8 1000FFAD */  b     .L7F0B8480
/* 0ED0FC 7F0B85CC 02398821 */   addu  $s1, $s1, $t9
push_tf_if_in_range_rooms:
/* 0ED100 7F0B85D0 1240000C */  beqz  $s2, .L7F0B8604
/* 0ED104 7F0B85D4 3C028004 */   lui   $v0, %hi(g_BgCurrentRoom)
/* 0ED108 7F0B85D8 8C424838 */  lw    $v0, %lo(g_BgCurrentRoom)($v0)
/* 0ED10C 7F0B85DC 8E28000C */  lw    $t0, 0xc($s1)
/* 0ED110 7F0B85E0 0048202A */  slt   $a0, $v0, $t0
/* 0ED114 7F0B85E4 38840001 */  xori  $a0, $a0, 1
/* 0ED118 7F0B85E8 10800004 */  beqz  $a0, .L7F0B85FC
/* 0ED11C 7F0B85EC 00000000 */   nop
/* 0ED120 7F0B85F0 8E290014 */  lw    $t1, 0x14($s1)
/* 0ED124 7F0B85F4 0122202A */  slt   $a0, $t1, $v0
/* 0ED128 7F0B85F8 38840001 */  xori  $a0, $a0, 1
.L7F0B85FC:
/* 0ED12C 7F0B85FC 0FC2E0DD */  jal   bgStackPush
/* 0ED130 7F0B8600 00000000 */   nop
.L7F0B8604:
/* 0ED134 7F0B8604 922A0001 */  lbu   $t2, 1($s1)
/* 0ED138 7F0B8608 000A58C0 */  sll   $t3, $t2, 3
/* 0ED13C 7F0B860C 1000FF9C */  b     .L7F0B8480
/* 0ED140 7F0B8610 022B8821 */   addu  $s1, $s1, $t3
force_visible:
/* 0ED144 7F0B8614 5240000C */  beql  $s2, $zero, .L7F0B8648
/* 0ED148 7F0B8618 922C0001 */   lbu   $t4, 1($s1)
/* 0ED14C 7F0B861C 8FC20000 */  lw    $v0, ($fp)
/* 0ED150 7F0B8620 C4441118 */  lwc1  $f4, 0x1118($v0)
/* 0ED154 7F0B8624 E6C40000 */  swc1  $f4, ($s6)
/* 0ED158 7F0B8628 C446111C */  lwc1  $f6, 0x111c($v0)
/* 0ED15C 7F0B862C E6C60004 */  swc1  $f6, 4($s6)
/* 0ED160 7F0B8630 C4481120 */  lwc1  $f8, 0x1120($v0)
/* 0ED164 7F0B8634 E6C80008 */  swc1  $f8, 8($s6)
/* 0ED168 7F0B8638 C44A1124 */  lwc1  $f10, 0x1124($v0)
/* 0ED16C 7F0B863C AE800000 */  sw    $zero, ($s4)
/* 0ED170 7F0B8640 E6CA000C */  swc1  $f10, 0xc($s6)
/* 0ED174 7F0B8644 922C0001 */  lbu   $t4, 1($s1)
.L7F0B8648:
/* 0ED178 7F0B8648 000C68C0 */  sll   $t5, $t4, 3
/* 0ED17C 7F0B864C 1000FF8C */  b     .L7F0B8480
/* 0ED180 7F0B8650 022D8821 */   addu  $s1, $s1, $t5
match_portal_vis:
/* 0ED184 7F0B8654 12400010 */  beqz  $s2, .L7F0B8698
/* 0ED188 7F0B8658 02C02825 */   move  $a1, $s6
/* 0ED18C 7F0B865C 0FC2D619 */  jal   sub_GAME_7F0B5864
/* 0ED190 7F0B8660 8E24000C */   lw    $a0, 0xc($s1)
/* 0ED194 7F0B8664 54400004 */  bnezl $v0, .L7F0B8678
/* 0ED198 7F0B8668 8FC50000 */   lw    $a1, ($fp)
/* 0ED19C 7F0B866C 1000000A */  b     .L7F0B8698
/* 0ED1A0 7F0B8670 AE970000 */   sw    $s7, ($s4)
/* 0ED1A4 7F0B8674 8FC50000 */  lw    $a1, ($fp)
.L7F0B8678:
/* 0ED1A8 7F0B8678 02C02025 */  move  $a0, $s6
/* 0ED1AC 7F0B867C 0FC2D6F7 */  jal   bgRectIntersect
/* 0ED1B0 7F0B8680 24A51118 */   addiu $a1, $a1, 0x1118
/* 0ED1B4 7F0B8684 54400004 */  bnezl $v0, .L7F0B8698
/* 0ED1B8 7F0B8688 AE800000 */   sw    $zero, ($s4)
/* 0ED1BC 7F0B868C 10000002 */  b     .L7F0B8698
/* 0ED1C0 7F0B8690 AE970000 */   sw    $s7, ($s4)
/* 0ED1C4 7F0B8694 AE800000 */  sw    $zero, ($s4)
.L7F0B8698:
/* 0ED1C8 7F0B8698 922E0001 */  lbu   $t6, 1($s1)
/* 0ED1CC 7F0B869C 000E78C0 */  sll   $t7, $t6, 3
/* 0ED1D0 7F0B86A0 1000FF77 */  b     .L7F0B8480
/* 0ED1D4 7F0B86A4 022F8821 */   addu  $s1, $s1, $t7
visible_if_seen_through_portal:
/* 0ED1D8 7F0B86A8 12400016 */  beqz  $s2, .L7F0B8704
/* 0ED1DC 7F0B86AC 27A50068 */   addiu $a1, $sp, 0x68
/* 0ED1E0 7F0B86B0 0FC2D619 */  jal   sub_GAME_7F0B5864
/* 0ED1E4 7F0B86B4 8E24000C */   lw    $a0, 0xc($s1)
/* 0ED1E8 7F0B86B8 50400013 */  beql  $v0, $zero, .L7F0B8708
/* 0ED1EC 7F0B86BC 92390001 */   lbu   $t9, 1($s1)
/* 0ED1F0 7F0B86C0 8FC50000 */  lw    $a1, ($fp)
/* 0ED1F4 7F0B86C4 27A40068 */  addiu $a0, $sp, 0x68
/* 0ED1F8 7F0B86C8 0FC2D6F7 */  jal   bgRectIntersect
/* 0ED1FC 7F0B86CC 24A51118 */   addiu $a1, $a1, 0x1118
/* 0ED200 7F0B86D0 5040000D */  beql  $v0, $zero, .L7F0B8708
/* 0ED204 7F0B86D4 92390001 */   lbu   $t9, 1($s1)
/* 0ED208 7F0B86D8 8E980000 */  lw    $t8, ($s4)
/* 0ED20C 7F0B86DC 27A50068 */  addiu $a1, $sp, 0x68
/* 0ED210 7F0B86E0 02C02025 */  move  $a0, $s6
/* 0ED214 7F0B86E4 13000005 */  beqz  $t8, .L7F0B86FC
/* 0ED218 7F0B86E8 00000000 */   nop
/* 0ED21C 7F0B86EC 0FC2D756 */  jal   bbox2dCopy
/* 0ED220 7F0B86F0 02C02025 */   move  $a0, $s6
/* 0ED224 7F0B86F4 10000003 */  b     .L7F0B8704
/* 0ED228 7F0B86F8 AE800000 */   sw    $zero, ($s4)
.L7F0B86FC:
/* 0ED22C 7F0B86FC 0FC2D730 */  jal   sub_GAME_7F0B5CC0
/* 0ED230 7F0B8700 27A50068 */   addiu $a1, $sp, 0x68
.L7F0B8704:
/* 0ED234 7F0B8704 92390001 */  lbu   $t9, 1($s1)
.L7F0B8708:
/* 0ED238 7F0B8708 001940C0 */  sll   $t0, $t9, 3
/* 0ED23C 7F0B870C 1000FF5C */  b     .L7F0B8480
/* 0ED240 7F0B8710 02288821 */   addu  $s1, $s1, $t0
not_visible_if_seen_through_portal:
/* 0ED244 7F0B8714 52400019 */  beql  $s2, $zero, .L7F0B877C
/* 0ED248 7F0B8718 922A0001 */   lbu   $t2, 1($s1)
/* 0ED24C 7F0B871C 8E890000 */  lw    $t1, ($s4)
/* 0ED250 7F0B8720 27A50058 */  addiu $a1, $sp, 0x58
/* 0ED254 7F0B8724 55200015 */  bnezl $t1, .L7F0B877C
/* 0ED258 7F0B8728 922A0001 */   lbu   $t2, 1($s1)
/* 0ED25C 7F0B872C 0FC2D619 */  jal   sub_GAME_7F0B5864
/* 0ED260 7F0B8730 8E24000C */   lw    $a0, 0xc($s1)
/* 0ED264 7F0B8734 54400004 */  bnezl $v0, .L7F0B8748
/* 0ED268 7F0B8738 8FC50000 */   lw    $a1, ($fp)
/* 0ED26C 7F0B873C 1000000E */  b     .L7F0B8778
/* 0ED270 7F0B8740 AE970000 */   sw    $s7, ($s4)
/* 0ED274 7F0B8744 8FC50000 */  lw    $a1, ($fp)
.L7F0B8748:
/* 0ED278 7F0B8748 27A40058 */  addiu $a0, $sp, 0x58
/* 0ED27C 7F0B874C 0FC2D6F7 */  jal   bgRectIntersect
/* 0ED280 7F0B8750 24A51118 */   addiu $a1, $a1, 0x1118
/* 0ED284 7F0B8754 14400003 */  bnez  $v0, .L7F0B8764
/* 0ED288 7F0B8758 02C02025 */   move  $a0, $s6
/* 0ED28C 7F0B875C 10000006 */  b     .L7F0B8778
/* 0ED290 7F0B8760 AE970000 */   sw    $s7, ($s4)
.L7F0B8764:
/* 0ED294 7F0B8764 0FC2D6F7 */  jal   bgRectIntersect
/* 0ED298 7F0B8768 27A50058 */   addiu $a1, $sp, 0x58
/* 0ED29C 7F0B876C 54400003 */  bnezl $v0, .L7F0B877C
/* 0ED2A0 7F0B8770 922A0001 */   lbu   $t2, 1($s1)
/* 0ED2A4 7F0B8774 AE970000 */  sw    $s7, ($s4)
.L7F0B8778:
/* 0ED2A8 7F0B8778 922A0001 */  lbu   $t2, 1($s1)
.L7F0B877C:
/* 0ED2AC 7F0B877C 000A58C0 */  sll   $t3, $t2, 3
/* 0ED2B0 7F0B8780 1000FF3F */  b     .L7F0B8480
/* 0ED2B4 7F0B8784 022B8821 */   addu  $s1, $s1, $t3
add_visible_room:
/* 0ED2B8 7F0B8788 52400017 */  beql  $s2, $zero, .L7F0B87E8
/* 0ED2BC 7F0B878C 922F0001 */   lbu   $t7, 1($s1)
/* 0ED2C0 7F0B8790 8E8C0000 */  lw    $t4, ($s4)
/* 0ED2C4 7F0B8794 02C02825 */  move  $a1, $s6
/* 0ED2C8 7F0B8798 55800013 */  bnezl $t4, .L7F0B87E8
/* 0ED2CC 7F0B879C 922F0001 */   lbu   $t7, 1($s1)
/* 0ED2D0 7F0B87A0 0FC2D482 */  jal   sub_GAME_7F0B5208
/* 0ED2D4 7F0B87A4 8E24000C */   lw    $a0, 0xc($s1)
/* 0ED2D8 7F0B87A8 1040000E */  beqz  $v0, .L7F0B87E4
/* 0ED2DC 7F0B87AC 00002825 */   move  $a1, $zero
/* 0ED2E0 7F0B87B0 8E24000C */  lw    $a0, 0xc($s1)
/* 0ED2E4 7F0B87B4 02C03025 */  move  $a2, $s6
/* 0ED2E8 7F0B87B8 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ED2EC 7F0B87BC 00003825 */   move  $a3, $zero
/* 0ED2F0 7F0B87C0 3C038008 */  lui   $v1, %hi(num_visible_rooms_in_cur_global_vis_packet)
/* 0ED2F4 7F0B87C4 8C63C038 */  lw    $v1, %lo(num_visible_rooms_in_cur_global_vis_packet)($v1)
/* 0ED2F8 7F0B87C8 8E2D000C */  lw    $t5, 0xc($s1)
/* 0ED2FC 7F0B87CC 3C018008 */  lui   $at, %hi(list_visible_rooms_in_cur_global_vis_packet)
/* 0ED300 7F0B87D0 00230821 */  addu  $at, $at, $v1
/* 0ED304 7F0B87D4 A02DBFA0 */  sb    $t5, %lo(list_visible_rooms_in_cur_global_vis_packet)($at)
/* 0ED308 7F0B87D8 3C018008 */  lui   $at, %hi(num_visible_rooms_in_cur_global_vis_packet)
/* 0ED30C 7F0B87DC 246E0001 */  addiu $t6, $v1, 1
/* 0ED310 7F0B87E0 AC2EC038 */  sw    $t6, %lo(num_visible_rooms_in_cur_global_vis_packet)($at)
.L7F0B87E4:
/* 0ED314 7F0B87E4 922F0001 */  lbu   $t7, 1($s1)
.L7F0B87E8:
/* 0ED318 7F0B87E8 000FC0C0 */  sll   $t8, $t7, 3
/* 0ED31C 7F0B87EC 1000FF24 */  b     .L7F0B8480
/* 0ED320 7F0B87F0 02388821 */   addu  $s1, $s1, $t8
disable_room:
/* 0ED324 7F0B87F4 52400009 */  beql  $s2, $zero, .L7F0B881C
/* 0ED328 7F0B87F8 92290001 */   lbu   $t1, 1($s1)
/* 0ED32C 7F0B87FC 8E39000C */  lw    $t9, 0xc($s1)
/* 0ED330 7F0B8800 3C018004 */  lui   $at, %hi(g_BgRoomInfo + 0x10 +0x24)
/* 0ED334 7F0B8804 00194080 */  sll   $t0, $t9, 2
/* 0ED338 7F0B8808 01194021 */  addu  $t0, $t0, $t9
/* 0ED33C 7F0B880C 00084100 */  sll   $t0, $t0, 4
/* 0ED340 7F0B8810 00280821 */  addu  $at, $at, $t0
/* 0ED344 7F0B8814 A0351448 */  sb    $s5, %lo(g_BgRoomInfo + 0x10 +0x24)($at)
/* 0ED348 7F0B8818 92290001 */  lbu   $t1, 1($s1)
.L7F0B881C:
/* 0ED34C 7F0B881C 000950C0 */  sll   $t2, $t1, 3
/* 0ED350 7F0B8820 1000FF17 */  b     .L7F0B8480
/* 0ED354 7F0B8824 022A8821 */   addu  $s1, $s1, $t2
disable_room_range:
/* 0ED358 7F0B8828 52400013 */  beql  $s2, $zero, .L7F0B8878
/* 0ED35C 7F0B882C 922F0001 */   lbu   $t7, 1($s1)
/* 0ED360 7F0B8830 8E22000C */  lw    $v0, 0xc($s1)
/* 0ED364 7F0B8834 8E2B0014 */  lw    $t3, 0x14($s1)
/* 0ED368 7F0B8838 3C0D8004 */  lui   $t5, %hi(g_BgRoomInfo)
/* 0ED36C 7F0B883C 00026080 */  sll   $t4, $v0, 2
/* 0ED370 7F0B8840 0162082A */  slt   $at, $t3, $v0
/* 0ED374 7F0B8844 1420000B */  bnez  $at, .L7F0B8874
/* 0ED378 7F0B8848 01826021 */   addu  $t4, $t4, $v0
/* 0ED37C 7F0B884C 000C6100 */  sll   $t4, $t4, 4
/* 0ED380 7F0B8850 25AD1414 */  addiu $t5, %lo(g_BgRoomInfo) # addiu $t5, $t5, 0x1414
/* 0ED384 7F0B8854 018D1821 */  addu  $v1, $t4, $t5
/* 0ED388 7F0B8858 A0750034 */  sb    $s5, 0x34($v1)
.L7F0B885C:
/* 0ED38C 7F0B885C 8E2E0014 */  lw    $t6, 0x14($s1)
/* 0ED390 7F0B8860 24420001 */  addiu $v0, $v0, 1
/* 0ED394 7F0B8864 24630050 */  addiu $v1, $v1, 0x50
/* 0ED398 7F0B8868 01C2082A */  slt   $at, $t6, $v0
/* 0ED39C 7F0B886C 5020FFFB */  beql  $at, $zero, .L7F0B885C
/* 0ED3A0 7F0B8870 A0750034 */   sb    $s5, 0x34($v1)
.L7F0B8874:
/* 0ED3A4 7F0B8874 922F0001 */  lbu   $t7, 1($s1)
.L7F0B8878:
/* 0ED3A8 7F0B8878 000FC0C0 */  sll   $t8, $t7, 3
/* 0ED3AC 7F0B887C 1000FF00 */  b     .L7F0B8480
/* 0ED3B0 7F0B8880 02388821 */   addu  $s1, $s1, $t8
preload_room:
/* 0ED3B4 7F0B8884 52400009 */  beql  $s2, $zero, .L7F0B88AC
/* 0ED3B8 7F0B8888 92280001 */   lbu   $t0, 1($s1)
/* 0ED3BC 7F0B888C 52600007 */  beql  $s3, $zero, .L7F0B88AC
/* 0ED3C0 7F0B8890 92280001 */   lbu   $t0, 1($s1)
/* 0ED3C4 7F0B8894 0FC2D8C5 */  jal   bgCheckIfRoomModelNeedsLoad
/* 0ED3C8 7F0B8898 8E24000C */   lw    $a0, 0xc($s1)
/* 0ED3CC 7F0B889C 2C530001 */  sltiu $s3, $v0, 1
/* 0ED3D0 7F0B88A0 327900FF */  andi  $t9, $s3, 0xff
/* 0ED3D4 7F0B88A4 03209825 */  move  $s3, $t9
/* 0ED3D8 7F0B88A8 92280001 */  lbu   $t0, 1($s1)
.L7F0B88AC:
/* 0ED3DC 7F0B88AC 000848C0 */  sll   $t1, $t0, 3
/* 0ED3E0 7F0B88B0 1000FEF3 */  b     .L7F0B8480
/* 0ED3E4 7F0B88B4 02298821 */   addu  $s1, $s1, $t1
preload_room_range:
/* 0ED3E8 7F0B88B8 52400013 */  beql  $s2, $zero, .L7F0B8908
/* 0ED3EC 7F0B88BC 922B0001 */   lbu   $t3, 1($s1)
/* 0ED3F0 7F0B88C0 8E30000C */  lw    $s0, 0xc($s1)
/* 0ED3F4 7F0B88C4 8E230014 */  lw    $v1, 0x14($s1)
/* 0ED3F8 7F0B88C8 0070082A */  slt   $at, $v1, $s0
/* 0ED3FC 7F0B88CC 5420000E */  bnezl $at, .L7F0B8908
/* 0ED400 7F0B88D0 922B0001 */   lbu   $t3, 1($s1)
.L7F0B88D4:
/* 0ED404 7F0B88D4 52600008 */  beql  $s3, $zero, .L7F0B88F8
/* 0ED408 7F0B88D8 26100001 */   addiu $s0, $s0, 1
/* 0ED40C 7F0B88DC 0FC2D8C5 */  jal   bgCheckIfRoomModelNeedsLoad
/* 0ED410 7F0B88E0 02002025 */   move  $a0, $s0
/* 0ED414 7F0B88E4 2C530001 */  sltiu $s3, $v0, 1
/* 0ED418 7F0B88E8 326A00FF */  andi  $t2, $s3, 0xff
/* 0ED41C 7F0B88EC 01409825 */  move  $s3, $t2
/* 0ED420 7F0B88F0 8E230014 */  lw    $v1, 0x14($s1)
/* 0ED424 7F0B88F4 26100001 */  addiu $s0, $s0, 1
.L7F0B88F8:
/* 0ED428 7F0B88F8 0070082A */  slt   $at, $v1, $s0
/* 0ED42C 7F0B88FC 1020FFF5 */  beqz  $at, .L7F0B88D4
/* 0ED430 7F0B8900 00000000 */   nop
/* 0ED434 7F0B8904 922B0001 */  lbu   $t3, 1($s1)
.L7F0B8908:
/* 0ED438 7F0B8908 000B60C0 */  sll   $t4, $t3, 3
/* 0ED43C 7F0B890C 1000FEDC */  b     .L7F0B8480
/* 0ED440 7F0B8910 022C8821 */   addu  $s1, $s1, $t4
remove_vis:
/* 0ED444 7F0B8914 52400003 */  beql  $s2, $zero, .L7F0B8924
/* 0ED448 7F0B8918 922D0001 */   lbu   $t5, 1($s1)
/* 0ED44C 7F0B891C AE970000 */  sw    $s7, ($s4)
/* 0ED450 7F0B8920 922D0001 */  lbu   $t5, 1($s1)
.L7F0B8924:
/* 0ED454 7F0B8924 000D70C0 */  sll   $t6, $t5, 3
/* 0ED458 7F0B8928 1000FED5 */  b     .L7F0B8480
/* 0ED45C 7F0B892C 022E8821 */   addu  $s1, $s1, $t6
if_statement:
/* 0ED460 7F0B8930 922F0001 */  lbu   $t7, 1($s1)
/* 0ED464 7F0B8934 02402825 */  move  $a1, $s2
/* 0ED468 7F0B8938 000FC0C0 */  sll   $t8, $t7, 3
/* 0ED46C 7F0B893C 0FC2E105 */  jal   parse_global_vis_command_list
/* 0ED470 7F0B8940 03112021 */   addu  $a0, $t8, $s1
/* 0ED474 7F0B8944 90590001 */  lbu   $t9, 1($v0)
/* 0ED478 7F0B8948 001940C0 */  sll   $t0, $t9, 3
/* 0ED47C 7F0B894C 1000FECC */  b     .L7F0B8480
/* 0ED480 7F0B8950 00488821 */   addu  $s1, $v0, $t0
endif_continue_exec:
/* 0ED484 7F0B8954 92290001 */  lbu   $t1, 1($s1)
/* 0ED488 7F0B8958 3C018008 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
/* 0ED48C 7F0B895C AC201610 */  sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
/* 0ED490 7F0B8960 000950C0 */  sll   $t2, $t1, 3
/* 0ED494 7F0B8964 10000023 */  b     .L7F0B89F4
/* 0ED498 7F0B8968 022A1021 */   addu  $v0, $s1, $t2
dont_exec_commands_even_on_return:
/* 0ED49C 7F0B896C 922B0001 */  lbu   $t3, 1($s1)
/* 0ED4A0 7F0B8970 0012102B */  sltu  $v0, $zero, $s2
/* 0ED4A4 7F0B8974 00009025 */  move  $s2, $zero
/* 0ED4A8 7F0B8978 000B60C0 */  sll   $t4, $t3, 3
/* 0ED4AC 7F0B897C 1040FEC0 */  beqz  $v0, .L7F0B8480
/* 0ED4B0 7F0B8980 022C8821 */   addu  $s1, $s1, $t4
/* 0ED4B4 7F0B8984 3C018008 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
/* 0ED4B8 7F0B8988 1000FEBD */  b     .L7F0B8480
/* 0ED4BC 7F0B898C AC371610 */   sw    $s7, %lo(dword_CODE_bss_80081600 + 0x10)($at)
if_statement_pull_from_stack:
/* 0ED4C0 7F0B8990 0FC2E0EC */  jal   bgStackPop
/* 0ED4C4 7F0B8994 00000000 */   nop
/* 0ED4C8 7F0B8998 922D0001 */  lbu   $t5, 1($s1)
/* 0ED4CC 7F0B899C 00522824 */  and   $a1, $v0, $s2
/* 0ED4D0 7F0B89A0 000D70C0 */  sll   $t6, $t5, 3
/* 0ED4D4 7F0B89A4 0FC2E105 */  jal   parse_global_vis_command_list
/* 0ED4D8 7F0B89A8 01D12021 */   addu  $a0, $t6, $s1
/* 0ED4DC 7F0B89AC 3C0F8008 */  lui   $t7, %hi(dword_CODE_bss_80081600 + 0x10)
/* 0ED4E0 7F0B89B0 8DEF1610 */  lw    $t7, %lo(dword_CODE_bss_80081600 + 0x10)($t7)
/* 0ED4E4 7F0B89B4 00408825 */  move  $s1, $v0
/* 0ED4E8 7F0B89B8 51E0FEB2 */  beql  $t7, $zero, .L7F0B8484
/* 0ED4EC 7F0B89BC 92240000 */   lbu   $a0, ($s1)
/* 0ED4F0 7F0B89C0 1000FEAF */  b     .L7F0B8480
/* 0ED4F4 7F0B89C4 00009025 */   move  $s2, $zero
toggle_exec_vs_ro:
/* 0ED4F8 7F0B89C8 92390001 */  lbu   $t9, 1($s1)
/* 0ED4FC 7F0B89CC 3A580001 */  xori  $t8, $s2, 1
/* 0ED500 7F0B89D0 03009025 */  move  $s2, $t8
/* 0ED504 7F0B89D4 001940C0 */  sll   $t0, $t9, 3
/* 0ED508 7F0B89D8 1000FEA9 */  b     .L7F0B8480
/* 0ED50C 7F0B89DC 02288821 */   addu  $s1, $s1, $t0
endif:
/* 0ED510 7F0B89E0 92290001 */  lbu   $t1, 1($s1)
/* 0ED514 7F0B89E4 000950C0 */  sll   $t2, $t1, 3
/* 0ED518 7F0B89E8 10000002 */  b     .L7F0B89F4
/* 0ED51C 7F0B89EC 022A1021 */   addu  $v0, $s1, $t2
invalid_type_terminate:
.L7F0B89F0:
/* 0ED520 7F0B89F0 02201025 */  move  $v0, $s1
.L7F0B89F4:
/* 0ED524 7F0B89F4 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0ED528 7F0B89F8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0ED52C 7F0B89FC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0ED530 7F0B8A00 8FB20020 */  lw    $s2, 0x20($sp)
/* 0ED534 7F0B8A04 8FB30024 */  lw    $s3, 0x24($sp)
/* 0ED538 7F0B8A08 8FB40028 */  lw    $s4, 0x28($sp)
/* 0ED53C 7F0B8A0C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0ED540 7F0B8A10 8FB60030 */  lw    $s6, 0x30($sp)
/* 0ED544 7F0B8A14 8FB70034 */  lw    $s7, 0x34($sp)
/* 0ED548 7F0B8A18 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0ED54C 7F0B8A1C 03E00008 */  jr    $ra
/* 0ED550 7F0B8A20 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
/*D:80058C80*/
glabel jpt_80058C80
.word if_statement
.word dont_exec_commands_even_on_return
.word endif_continue_exec
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word if_statement_pull_from_stack
.word toggle_exec_vs_ro
.word endif

/*D:80058CB4*/
glabel vis_command_jpt
.word break
.word push_to_stack
.word pull_from_stack
.word and_merge_last_two_on_stack
.word or_merge_last_two_on_stack
.word not_merge_last_two_on_stack
.word carrot_merge_last_two_on_stack
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word push_tf_if_in_range_rooms
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word force_visible
.word match_portal_vis
.word add_visible_room
.word remove_vis
.word visible_if_seen_through_portal
.word not_visible_if_seen_through_portal
.word disable_room
.word disable_room_range
.word preload_room
.word preload_room_range
.text
glabel parse_global_vis_command_list
/* 0EA0B4 7F0B76C4 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0EA0B8 7F0B76C8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0EA0BC 7F0B76CC AFB20020 */  sw    $s2, 0x20($sp)
/* 0EA0C0 7F0B76D0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0EA0C4 7F0B76D4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10) # $at, 0x8007
/* 0EA0C8 7F0B76D8 00808825 */  move  $s1, $a0
/* 0EA0CC 7F0B76DC 00A09025 */  move  $s2, $a1
/* 0EA0D0 7F0B76E0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0EA0D4 7F0B76E4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0EA0D8 7F0B76E8 AFB70034 */  sw    $s7, 0x34($sp)
/* 0EA0DC 7F0B76EC AFB60030 */  sw    $s6, 0x30($sp)
/* 0EA0E0 7F0B76F0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0EA0E4 7F0B76F4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0EA0E8 7F0B76F8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EA0EC 7F0B76FC 24130001 */  li    $s3, 1
/* 0EA0F0 7F0B7700 14800003 */  bnez  $a0, .L7F0B7710
/* 0EA0F4 7F0B7704 AC20BFB8 */   sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
/* 0EA0F8 7F0B7708 10000166 */  b     .L7F0B7CA4
/* 0EA0FC 7F0B770C 00801025 */   move  $v0, $a0
.L7F0B7710:
/* 0EA100 7F0B7710 3C1E8007 */  lui   $fp, %hi(g_CurrentPlayer) # $fp, 0x8007
/* 0EA104 7F0B7714 3C168007 */  lui   $s6, %hi(dword_CODE_bss_80081600) # $s6, 0x8007
/* 0EA108 7F0B7718 3C148004 */  lui   $s4, %hi(current_visibility) # $s4, 0x8004
/* 0EA10C 7F0B771C 2694DDE4 */  addiu $s4, %lo(current_visibility) # addiu $s4, $s4, -0x221c
/* 0EA110 7F0B7720 26D6BFA8 */  addiu $s6, %lo(dword_CODE_bss_80081600) # addiu $s6, $s6, -0x4058
/* 0EA114 7F0B7724 27DE8BC0 */  addiu $fp, %lo(g_CurrentPlayer) # addiu $fp, $fp, -0x7440
/* 0EA118 7F0B7728 24170001 */  li    $s7, 1
/* 0EA11C 7F0B772C 24150001 */  li    $s5, 1
.L7F0B7730:
/* 0EA120 7F0B7730 92240000 */  lbu   $a0, ($s1)
.L7F0B7734:
/* 0EA124 7F0B7734 28810028 */  slti  $at, $a0, 0x28
/* 0EA128 7F0B7738 14200009 */  bnez  $at, .L7F0B7760
/* 0EA12C 7F0B773C 248EFFB0 */   addiu $t6, $a0, -0x50
/* 0EA130 7F0B7740 2DC1000D */  sltiu $at, $t6, 0xd
/* 0EA134 7F0B7744 10200156 */  beqz  $at, .L7F0B7CA0
/* 0EA138 7F0B7748 000E7080 */   sll   $t6, $t6, 2
/* 0EA13C 7F0B774C 3C018005 */  lui   $at, %hi(jpt_80058C80)
/* 0EA140 7F0B7750 002E0821 */  addu  $at, $at, $t6
/* 0EA144 7F0B7754 8C2ED6D0 */  lw    $t6, %lo(jpt_80058C80)($at)
/* 0EA148 7F0B7758 01C00008 */  jr    $t6
/* 0EA14C 7F0B775C 00000000 */   nop
.L7F0B7760:
/* 0EA150 7F0B7760 2C810028 */  sltiu $at, $a0, 0x28
/* 0EA154 7F0B7764 1020014E */  beqz  $at, .L7F0B7CA0
/* 0EA158 7F0B7768 00047880 */   sll   $t7, $a0, 2
/* 0EA15C 7F0B776C 3C018005 */  lui   $at, %hi(vis_command_jpt)
/* 0EA160 7F0B7770 002F0821 */  addu  $at, $at, $t7
/* 0EA164 7F0B7774 8C2FD704 */  lw    $t7, %lo(vis_command_jpt)($at)
/* 0EA168 7F0B7778 01E00008 */  jr    $t7
/* 0EA16C 7F0B777C 00000000 */   nop
break:
/* 0EA170 7F0B7780 10000148 */  b     .L7F0B7CA4
/* 0EA174 7F0B7784 02201025 */   move  $v0, $s1
push_to_stack:
/* 0EA178 7F0B7788 52400004 */  beql  $s2, $zero, .L7F0B779C
/* 0EA17C 7F0B778C 92380001 */   lbu   $t8, 1($s1)
/* 0EA180 7F0B7790 0FC2DD89 */  jal   bgStackPush
/* 0EA184 7F0B7794 8E240004 */   lw    $a0, 4($s1)
/* 0EA188 7F0B7798 92380001 */  lbu   $t8, 1($s1)
.L7F0B779C:
/* 0EA18C 7F0B779C 0018C8C0 */  sll   $t9, $t8, 3
/* 0EA190 7F0B77A0 1000FFE3 */  b     .L7F0B7730
/* 0EA194 7F0B77A4 02398821 */   addu  $s1, $s1, $t9
pull_from_stack:
/* 0EA198 7F0B77A8 52400004 */  beql  $s2, $zero, .L7F0B77BC
/* 0EA19C 7F0B77AC 92280001 */   lbu   $t0, 1($s1)
/* 0EA1A0 7F0B77B0 0FC2DD98 */  jal   bgStackPop
/* 0EA1A4 7F0B77B4 00000000 */   nop
/* 0EA1A8 7F0B77B8 92280001 */  lbu   $t0, 1($s1)
.L7F0B77BC:
/* 0EA1AC 7F0B77BC 000848C0 */  sll   $t1, $t0, 3
/* 0EA1B0 7F0B77C0 1000FFDB */  b     .L7F0B7730
/* 0EA1B4 7F0B77C4 02298821 */   addu  $s1, $s1, $t1
and_merge_last_two_on_stack:
/* 0EA1B8 7F0B77C8 52400008 */  beql  $s2, $zero, .L7F0B77EC
/* 0EA1BC 7F0B77CC 922A0001 */   lbu   $t2, 1($s1)
/* 0EA1C0 7F0B77D0 0FC2DD98 */  jal   bgStackPop
/* 0EA1C4 7F0B77D4 00000000 */   nop
/* 0EA1C8 7F0B77D8 0FC2DD98 */  jal   bgStackPop
/* 0EA1CC 7F0B77DC 00408025 */   move  $s0, $v0
/* 0EA1D0 7F0B77E0 0FC2DD89 */  jal   bgStackPush
/* 0EA1D4 7F0B77E4 00502024 */   and   $a0, $v0, $s0
/* 0EA1D8 7F0B77E8 922A0001 */  lbu   $t2, 1($s1)
.L7F0B77EC:
/* 0EA1DC 7F0B77EC 000A58C0 */  sll   $t3, $t2, 3
/* 0EA1E0 7F0B77F0 1000FFCF */  b     .L7F0B7730
/* 0EA1E4 7F0B77F4 022B8821 */   addu  $s1, $s1, $t3
or_merge_last_two_on_stack:
/* 0EA1E8 7F0B77F8 52400008 */  beql  $s2, $zero, .L7F0B781C
/* 0EA1EC 7F0B77FC 922C0001 */   lbu   $t4, 1($s1)
/* 0EA1F0 7F0B7800 0FC2DD98 */  jal   bgStackPop
/* 0EA1F4 7F0B7804 00000000 */   nop
/* 0EA1F8 7F0B7808 0FC2DD98 */  jal   bgStackPop
/* 0EA1FC 7F0B780C 00408025 */   move  $s0, $v0
/* 0EA200 7F0B7810 0FC2DD89 */  jal   bgStackPush
/* 0EA204 7F0B7814 00502025 */   or    $a0, $v0, $s0
/* 0EA208 7F0B7818 922C0001 */  lbu   $t4, 1($s1)
.L7F0B781C:
/* 0EA20C 7F0B781C 000C68C0 */  sll   $t5, $t4, 3
/* 0EA210 7F0B7820 1000FFC3 */  b     .L7F0B7730
/* 0EA214 7F0B7824 022D8821 */   addu  $s1, $s1, $t5
not_merge_last_two_on_stack:
/* 0EA218 7F0B7828 52400006 */  beql  $s2, $zero, .L7F0B7844
/* 0EA21C 7F0B782C 922E0001 */   lbu   $t6, 1($s1)
/* 0EA220 7F0B7830 0FC2DD98 */  jal   bgStackPop
/* 0EA224 7F0B7834 00000000 */   nop
/* 0EA228 7F0B7838 0FC2DD89 */  jal   bgStackPush
/* 0EA22C 7F0B783C 2C440001 */   sltiu $a0, $v0, 1
/* 0EA230 7F0B7840 922E0001 */  lbu   $t6, 1($s1)
.L7F0B7844:
/* 0EA234 7F0B7844 000E78C0 */  sll   $t7, $t6, 3
/* 0EA238 7F0B7848 1000FFB9 */  b     .L7F0B7730
/* 0EA23C 7F0B784C 022F8821 */   addu  $s1, $s1, $t7
carrot_merge_last_two_on_stack:
/* 0EA240 7F0B7850 52400008 */  beql  $s2, $zero, .L7F0B7874
/* 0EA244 7F0B7854 92380001 */   lbu   $t8, 1($s1)
/* 0EA248 7F0B7858 0FC2DD98 */  jal   bgStackPop
/* 0EA24C 7F0B785C 00000000 */   nop
/* 0EA250 7F0B7860 0FC2DD98 */  jal   bgStackPop
/* 0EA254 7F0B7864 00408025 */   move  $s0, $v0
/* 0EA258 7F0B7868 0FC2DD89 */  jal   bgStackPush
/* 0EA25C 7F0B786C 00502026 */   xor   $a0, $v0, $s0
/* 0EA260 7F0B7870 92380001 */  lbu   $t8, 1($s1)
.L7F0B7874:
/* 0EA264 7F0B7874 0018C8C0 */  sll   $t9, $t8, 3
/* 0EA268 7F0B7878 1000FFAD */  b     .L7F0B7730
/* 0EA26C 7F0B787C 02398821 */   addu  $s1, $s1, $t9
push_tf_if_in_range_rooms:
/* 0EA270 7F0B7880 1240000C */  beqz  $s2, .L7F0B78B4
/* 0EA274 7F0B7884 3C028004 */   lui   $v0, %hi(g_BgCurrentRoom) # $v0, 0x8004
/* 0EA278 7F0B7888 8C42DD18 */  lw    $v0, %lo(g_BgCurrentRoom)($v0)
/* 0EA27C 7F0B788C 8E28000C */  lw    $t0, 0xc($s1)
/* 0EA280 7F0B7890 0048202A */  slt   $a0, $v0, $t0
/* 0EA284 7F0B7894 38840001 */  xori  $a0, $a0, 1
/* 0EA288 7F0B7898 10800004 */  beqz  $a0, .L7F0B78AC
/* 0EA28C 7F0B789C 00000000 */   nop
/* 0EA290 7F0B78A0 8E290014 */  lw    $t1, 0x14($s1)
/* 0EA294 7F0B78A4 0122202A */  slt   $a0, $t1, $v0
/* 0EA298 7F0B78A8 38840001 */  xori  $a0, $a0, 1
.L7F0B78AC:
/* 0EA29C 7F0B78AC 0FC2DD89 */  jal   bgStackPush
/* 0EA2A0 7F0B78B0 00000000 */   nop
.L7F0B78B4:
/* 0EA2A4 7F0B78B4 922A0001 */  lbu   $t2, 1($s1)
/* 0EA2A8 7F0B78B8 000A58C0 */  sll   $t3, $t2, 3
/* 0EA2AC 7F0B78BC 1000FF9C */  b     .L7F0B7730
/* 0EA2B0 7F0B78C0 022B8821 */   addu  $s1, $s1, $t3
force_visible:
/* 0EA2B4 7F0B78C4 5240000C */  beql  $s2, $zero, .L7F0B78F8
/* 0EA2B8 7F0B78C8 922C0001 */   lbu   $t4, 1($s1)
/* 0EA2BC 7F0B78CC 8FC20000 */  lw    $v0, ($fp)
/* 0EA2C0 7F0B78D0 C4441110 */  lwc1  $f4, 0x1110($v0)
/* 0EA2C4 7F0B78D4 E6C40000 */  swc1  $f4, ($s6)
/* 0EA2C8 7F0B78D8 C4461114 */  lwc1  $f6, 0x1114($v0)
/* 0EA2CC 7F0B78DC E6C60004 */  swc1  $f6, 4($s6)
/* 0EA2D0 7F0B78E0 C4481118 */  lwc1  $f8, 0x1118($v0)
/* 0EA2D4 7F0B78E4 E6C80008 */  swc1  $f8, 8($s6)
/* 0EA2D8 7F0B78E8 C44A111C */  lwc1  $f10, 0x111c($v0)
/* 0EA2DC 7F0B78EC AE800000 */  sw    $zero, ($s4)
/* 0EA2E0 7F0B78F0 E6CA000C */  swc1  $f10, 0xc($s6)
/* 0EA2E4 7F0B78F4 922C0001 */  lbu   $t4, 1($s1)
.L7F0B78F8:
/* 0EA2E8 7F0B78F8 000C68C0 */  sll   $t5, $t4, 3
/* 0EA2EC 7F0B78FC 1000FF8C */  b     .L7F0B7730
/* 0EA2F0 7F0B7900 022D8821 */   addu  $s1, $s1, $t5
match_portal_vis:
/* 0EA2F4 7F0B7904 12400010 */  beqz  $s2, .L7F0B7948
/* 0EA2F8 7F0B7908 02C02825 */   move  $a1, $s6
/* 0EA2FC 7F0B790C 0FC2D2E8 */  jal   sub_GAME_7F0B5864
/* 0EA300 7F0B7910 8E24000C */   lw    $a0, 0xc($s1)
/* 0EA304 7F0B7914 54400004 */  bnezl $v0, .L7F0B7928
/* 0EA308 7F0B7918 8FC50000 */   lw    $a1, ($fp)
/* 0EA30C 7F0B791C 1000000A */  b     .L7F0B7948
/* 0EA310 7F0B7920 AE970000 */   sw    $s7, ($s4)
/* 0EA314 7F0B7924 8FC50000 */  lw    $a1, ($fp)
.L7F0B7928:
/* 0EA318 7F0B7928 02C02025 */  move  $a0, $s6
/* 0EA31C 7F0B792C 0FC2D3C6 */  jal   bgRectIntersect
/* 0EA320 7F0B7930 24A51110 */   addiu $a1, $a1, 0x1110
/* 0EA324 7F0B7934 54400004 */  bnezl $v0, .L7F0B7948
/* 0EA328 7F0B7938 AE800000 */   sw    $zero, ($s4)
/* 0EA32C 7F0B793C 10000002 */  b     .L7F0B7948
/* 0EA330 7F0B7940 AE970000 */   sw    $s7, ($s4)
/* 0EA334 7F0B7944 AE800000 */  sw    $zero, ($s4)
.L7F0B7948:
/* 0EA338 7F0B7948 922E0001 */  lbu   $t6, 1($s1)
/* 0EA33C 7F0B794C 000E78C0 */  sll   $t7, $t6, 3
/* 0EA340 7F0B7950 1000FF77 */  b     .L7F0B7730
/* 0EA344 7F0B7954 022F8821 */   addu  $s1, $s1, $t7
visible_if_seen_through_portal:
/* 0EA348 7F0B7958 12400016 */  beqz  $s2, .L7F0B79B4
/* 0EA34C 7F0B795C 27A50068 */   addiu $a1, $sp, 0x68
/* 0EA350 7F0B7960 0FC2D2E8 */  jal   sub_GAME_7F0B5864
/* 0EA354 7F0B7964 8E24000C */   lw    $a0, 0xc($s1)
/* 0EA358 7F0B7968 50400013 */  beql  $v0, $zero, .L7F0B79B8
/* 0EA35C 7F0B796C 92390001 */   lbu   $t9, 1($s1)
/* 0EA360 7F0B7970 8FC50000 */  lw    $a1, ($fp)
/* 0EA364 7F0B7974 27A40068 */  addiu $a0, $sp, 0x68
/* 0EA368 7F0B7978 0FC2D3C6 */  jal   bgRectIntersect
/* 0EA36C 7F0B797C 24A51110 */   addiu $a1, $a1, 0x1110
/* 0EA370 7F0B7980 5040000D */  beql  $v0, $zero, .L7F0B79B8
/* 0EA374 7F0B7984 92390001 */   lbu   $t9, 1($s1)
/* 0EA378 7F0B7988 8E980000 */  lw    $t8, ($s4)
/* 0EA37C 7F0B798C 27A50068 */  addiu $a1, $sp, 0x68
/* 0EA380 7F0B7990 02C02025 */  move  $a0, $s6
/* 0EA384 7F0B7994 13000005 */  beqz  $t8, .L7F0B79AC
/* 0EA388 7F0B7998 00000000 */   nop
/* 0EA38C 7F0B799C 0FC2D425 */  jal   bbox2dCopy
/* 0EA390 7F0B79A0 02C02025 */   move  $a0, $s6
/* 0EA394 7F0B79A4 10000003 */  b     .L7F0B79B4
/* 0EA398 7F0B79A8 AE800000 */   sw    $zero, ($s4)
.L7F0B79AC:
/* 0EA39C 7F0B79AC 0FC2D3FF */  jal   sub_GAME_7F0B5CC0
/* 0EA3A0 7F0B79B0 27A50068 */   addiu $a1, $sp, 0x68
.L7F0B79B4:
/* 0EA3A4 7F0B79B4 92390001 */  lbu   $t9, 1($s1)
.L7F0B79B8:
/* 0EA3A8 7F0B79B8 001940C0 */  sll   $t0, $t9, 3
/* 0EA3AC 7F0B79BC 1000FF5C */  b     .L7F0B7730
/* 0EA3B0 7F0B79C0 02288821 */   addu  $s1, $s1, $t0
not_visible_if_seen_through_portal:
/* 0EA3B4 7F0B79C4 52400019 */  beql  $s2, $zero, .Leu7F0B7A2C
/* 0EA3B8 7F0B79C8 922A0001 */   lbu   $t2, 1($s1)
/* 0EA3BC 7F0B79CC 8E890000 */  lw    $t1, ($s4)
/* 0EA3C0 7F0B79D0 27A50058 */  addiu $a1, $sp, 0x58
/* 0EA3C4 7F0B79D4 55200015 */  bnezl $t1, .Leu7F0B7A2C
/* 0EA3C8 7F0B79D8 922A0001 */   lbu   $t2, 1($s1)
/* 0EA3CC 7F0B79DC 0FC2D2E8 */  jal   sub_GAME_7F0B5864
/* 0EA3D0 7F0B79E0 8E24000C */   lw    $a0, 0xc($s1)
/* 0EA3D4 7F0B79E4 54400004 */  bnezl $v0, .L7F0B79F8
/* 0EA3D8 7F0B79E8 8FC50000 */   lw    $a1, ($fp)
/* 0EA3DC 7F0B79EC 1000000E */  b     .Leu7F0B7A28
/* 0EA3E0 7F0B79F0 AE970000 */   sw    $s7, ($s4)
/* 0EA3E4 7F0B79F4 8FC50000 */  lw    $a1, ($fp)
.L7F0B79F8:
/* 0EA3E8 7F0B79F8 27A40058 */  addiu $a0, $sp, 0x58
/* 0EA3EC 7F0B79FC 0FC2D3C6 */  jal   bgRectIntersect
/* 0EA3F0 7F0B7A00 24A51110 */   addiu $a1, $a1, 0x1110
/* 0EA3F4 7F0B7A04 14400003 */  bnez  $v0, .L7F0B7A14
/* 0EA3F8 7F0B7A08 02C02025 */   move  $a0, $s6
/* 0EA3FC 7F0B7A0C 10000006 */  b     .Leu7F0B7A28
/* 0EA400 7F0B7A10 AE970000 */   sw    $s7, ($s4)
.L7F0B7A14:
/* 0EA404 7F0B7A14 0FC2D3C6 */  jal   bgRectIntersect
/* 0EA408 7F0B7A18 27A50058 */   addiu $a1, $sp, 0x58
/* 0EA40C 7F0B7A1C 54400003 */  bnezl $v0, .Leu7F0B7A2C
/* 0EA410 7F0B7A20 922A0001 */   lbu   $t2, 1($s1)
/* 0EA414 7F0B7A24 AE970000 */  sw    $s7, ($s4)
.Leu7F0B7A28:
/* 0EA418 7F0B7A28 922A0001 */  lbu   $t2, 1($s1)
.Leu7F0B7A2C:
/* 0EA41C 7F0B7A2C 000A58C0 */  sll   $t3, $t2, 3
/* 0EA420 7F0B7A30 1000FF3F */  b     .L7F0B7730
/* 0EA424 7F0B7A34 022B8821 */   addu  $s1, $s1, $t3
add_visible_room:
/* 0EA428 7F0B7A38 52400017 */  beql  $s2, $zero, .L7F0B7A98
/* 0EA42C 7F0B7A3C 922F0001 */   lbu   $t7, 1($s1)
/* 0EA430 7F0B7A40 8E8C0000 */  lw    $t4, ($s4)
/* 0EA434 7F0B7A44 02C02825 */  move  $a1, $s6
/* 0EA438 7F0B7A48 55800013 */  bnezl $t4, .L7F0B7A98
/* 0EA43C 7F0B7A4C 922F0001 */   lbu   $t7, 1($s1)
/* 0EA440 7F0B7A50 0FC2D151 */  jal   sub_GAME_7F0B5208
/* 0EA444 7F0B7A54 8E24000C */   lw    $a0, 0xc($s1)
/* 0EA448 7F0B7A58 1040000E */  beqz  $v0, .L7F0B7A94
/* 0EA44C 7F0B7A5C 00002825 */   move  $a1, $zero
/* 0EA450 7F0B7A60 8E24000C */  lw    $a0, 0xc($s1)
/* 0EA454 7F0B7A64 02C03025 */  move  $a2, $s6
/* 0EA458 7F0B7A68 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0EA45C 7F0B7A6C 00003825 */   move  $a3, $zero
/* 0EA460 7F0B7A70 3C038007 */  lui   $v1, %hi(num_visible_rooms_in_cur_global_vis_packet) # $v1, 0x8007
/* 0EA464 7F0B7A74 8C639F7C */  lw    $v1, %lo(num_visible_rooms_in_cur_global_vis_packet)($v1)
/* 0EA468 7F0B7A78 8E2D000C */  lw    $t5, 0xc($s1)
/* 0EA46C 7F0B7A7C 3C018007 */  lui   $at, %hi(list_visible_rooms_in_cur_global_vis_packet)
/* 0EA470 7F0B7A80 00230821 */  addu  $at, $at, $v1
/* 0EA474 7F0B7A84 A02D9EF0 */  sb    $t5, %lo(list_visible_rooms_in_cur_global_vis_packet)($at)
/* 0EA478 7F0B7A88 3C018007 */  lui   $at, %hi(num_visible_rooms_in_cur_global_vis_packet) # $at, 0x8007
/* 0EA47C 7F0B7A8C 246E0001 */  addiu $t6, $v1, 1
/* 0EA480 7F0B7A90 AC2E9F7C */  sw    $t6, %lo(num_visible_rooms_in_cur_global_vis_packet)($at)
.L7F0B7A94:
/* 0EA484 7F0B7A94 922F0001 */  lbu   $t7, 1($s1)
.L7F0B7A98:
/* 0EA488 7F0B7A98 000FC0C0 */  sll   $t8, $t7, 3
/* 0EA48C 7F0B7A9C 1000FF24 */  b     .L7F0B7730
/* 0EA490 7F0B7AA0 02388821 */   addu  $s1, $s1, $t8
disable_room:
/* 0EA494 7F0B7AA4 52400009 */  beql  $s2, $zero, .L7F0B7ACC
/* 0EA498 7F0B7AA8 92290001 */   lbu   $t1, 1($s1)
/* 0EA49C 7F0B7AAC 8E39000C */  lw    $t9, 0xc($s1)
/* 0EA4A0 7F0B7AB0 3C018004 */  lui   $at, %hi(g_BgRoomInfo + 0x10 +0x24)
/* 0EA4A4 7F0B7AB4 00194080 */  sll   $t0, $t9, 2
/* 0EA4A8 7F0B7AB8 01194021 */  addu  $t0, $t0, $t9
/* 0EA4AC 7F0B7ABC 00084100 */  sll   $t0, $t0, 4
/* 0EA4B0 7F0B7AC0 00280821 */  addu  $at, $at, $t0
/* 0EA4B4 7F0B7AC4 A035AC98 */  sb    $s5, %lo(g_BgRoomInfo + 0x10 +0x24)($at)
/* 0EA4B8 7F0B7AC8 92290001 */  lbu   $t1, 1($s1)
.L7F0B7ACC:
/* 0EA4BC 7F0B7ACC 000950C0 */  sll   $t2, $t1, 3
/* 0EA4C0 7F0B7AD0 1000FF17 */  b     .L7F0B7730
/* 0EA4C4 7F0B7AD4 022A8821 */   addu  $s1, $s1, $t2
disable_room_range:
/* 0EA4C8 7F0B7AD8 52400013 */  beql  $s2, $zero, .L7F0B7B28
/* 0EA4CC 7F0B7ADC 922F0001 */   lbu   $t7, 1($s1)
/* 0EA4D0 7F0B7AE0 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA4D4 7F0B7AE4 8E2B0014 */  lw    $t3, 0x14($s1)
/* 0EA4D8 7F0B7AE8 3C0D8004 */  lui   $t5, %hi(g_BgRoomInfo) # $t5, 0x8004
/* 0EA4DC 7F0B7AEC 00026080 */  sll   $t4, $v0, 2
/* 0EA4E0 7F0B7AF0 0162082A */  slt   $at, $t3, $v0
/* 0EA4E4 7F0B7AF4 1420000B */  bnez  $at, .L7F0B7B24
/* 0EA4E8 7F0B7AF8 01826021 */   addu  $t4, $t4, $v0
/* 0EA4EC 7F0B7AFC 000C6100 */  sll   $t4, $t4, 4
/* 0EA4F0 7F0B7B00 25ADAC64 */  addiu $t5, %lo(g_BgRoomInfo) # addiu $t5, $t5, -0x539c
/* 0EA4F4 7F0B7B04 018D1821 */  addu  $v1, $t4, $t5
/* 0EA4F8 7F0B7B08 A0750034 */  sb    $s5, 0x34($v1)
.L7F0B7B0C:
/* 0EA4FC 7F0B7B0C 8E2E0014 */  lw    $t6, 0x14($s1)
/* 0EA500 7F0B7B10 24420001 */  addiu $v0, $v0, 1
/* 0EA504 7F0B7B14 24630050 */  addiu $v1, $v1, 0x50
/* 0EA508 7F0B7B18 01C2082A */  slt   $at, $t6, $v0
/* 0EA50C 7F0B7B1C 5020FFFB */  beql  $at, $zero, .L7F0B7B0C
/* 0EA510 7F0B7B20 A0750034 */   sb    $s5, 0x34($v1)
.L7F0B7B24:
/* 0EA514 7F0B7B24 922F0001 */  lbu   $t7, 1($s1)
.L7F0B7B28:
/* 0EA518 7F0B7B28 000FC0C0 */  sll   $t8, $t7, 3
/* 0EA51C 7F0B7B2C 1000FF00 */  b     .L7F0B7730
/* 0EA520 7F0B7B30 02388821 */   addu  $s1, $s1, $t8
preload_room:
/* 0EA524 7F0B7B34 52400009 */  beql  $s2, $zero, .L7F0B7B5C
/* 0EA528 7F0B7B38 92280001 */   lbu   $t0, 1($s1)
/* 0EA52C 7F0B7B3C 52600007 */  beql  $s3, $zero, .L7F0B7B5C
/* 0EA530 7F0B7B40 92280001 */   lbu   $t0, 1($s1)
/* 0EA534 7F0B7B44 0FC2D594 */  jal   bgCheckIfRoomModelNeedsLoad
/* 0EA538 7F0B7B48 8E24000C */   lw    $a0, 0xc($s1)
/* 0EA53C 7F0B7B4C 2C530001 */  sltiu $s3, $v0, 1
/* 0EA540 7F0B7B50 327900FF */  andi  $t9, $s3, 0xff
/* 0EA544 7F0B7B54 03209825 */  move  $s3, $t9
/* 0EA548 7F0B7B58 92280001 */  lbu   $t0, 1($s1)
.L7F0B7B5C:
/* 0EA54C 7F0B7B5C 000848C0 */  sll   $t1, $t0, 3
/* 0EA550 7F0B7B60 1000FEF3 */  b     .L7F0B7730
/* 0EA554 7F0B7B64 02298821 */   addu  $s1, $s1, $t1
preload_room_range:
/* 0EA558 7F0B7B68 52400013 */  beql  $s2, $zero, .L7F0B7BB8
/* 0EA55C 7F0B7B6C 922B0001 */   lbu   $t3, 1($s1)
/* 0EA560 7F0B7B70 8E30000C */  lw    $s0, 0xc($s1)
/* 0EA564 7F0B7B74 8E230014 */  lw    $v1, 0x14($s1)
/* 0EA568 7F0B7B78 0070082A */  slt   $at, $v1, $s0
/* 0EA56C 7F0B7B7C 5420000E */  bnezl $at, .L7F0B7BB8
/* 0EA570 7F0B7B80 922B0001 */   lbu   $t3, 1($s1)
.L7F0B7B84:
/* 0EA574 7F0B7B84 52600008 */  beql  $s3, $zero, .L7F0B7BA8
/* 0EA578 7F0B7B88 26100001 */   addiu $s0, $s0, 1
/* 0EA57C 7F0B7B8C 0FC2D594 */  jal   bgCheckIfRoomModelNeedsLoad
/* 0EA580 7F0B7B90 02002025 */   move  $a0, $s0
/* 0EA584 7F0B7B94 2C530001 */  sltiu $s3, $v0, 1
/* 0EA588 7F0B7B98 326A00FF */  andi  $t2, $s3, 0xff
/* 0EA58C 7F0B7B9C 01409825 */  move  $s3, $t2
/* 0EA590 7F0B7BA0 8E230014 */  lw    $v1, 0x14($s1)
/* 0EA594 7F0B7BA4 26100001 */  addiu $s0, $s0, 1
.L7F0B7BA8:
/* 0EA598 7F0B7BA8 0070082A */  slt   $at, $v1, $s0
/* 0EA59C 7F0B7BAC 1020FFF5 */  beqz  $at, .L7F0B7B84
/* 0EA5A0 7F0B7BB0 00000000 */   nop
/* 0EA5A4 7F0B7BB4 922B0001 */  lbu   $t3, 1($s1)
.L7F0B7BB8:
/* 0EA5A8 7F0B7BB8 000B60C0 */  sll   $t4, $t3, 3
/* 0EA5AC 7F0B7BBC 1000FEDC */  b     .L7F0B7730
/* 0EA5B0 7F0B7BC0 022C8821 */   addu  $s1, $s1, $t4
remove_vis:
/* 0EA5B4 7F0B7BC4 52400003 */  beql  $s2, $zero, .L7F0B7BD4
/* 0EA5B8 7F0B7BC8 922D0001 */   lbu   $t5, 1($s1)
/* 0EA5BC 7F0B7BCC AE970000 */  sw    $s7, ($s4)
/* 0EA5C0 7F0B7BD0 922D0001 */  lbu   $t5, 1($s1)
.L7F0B7BD4:
/* 0EA5C4 7F0B7BD4 000D70C0 */  sll   $t6, $t5, 3
/* 0EA5C8 7F0B7BD8 1000FED5 */  b     .L7F0B7730
/* 0EA5CC 7F0B7BDC 022E8821 */   addu  $s1, $s1, $t6
if_statement:
/* 0EA5D0 7F0B7BE0 922F0001 */  lbu   $t7, 1($s1)
/* 0EA5D4 7F0B7BE4 02402825 */  move  $a1, $s2
/* 0EA5D8 7F0B7BE8 000FC0C0 */  sll   $t8, $t7, 3
/* 0EA5DC 7F0B7BEC 0FC2DDB1 */  jal   parse_global_vis_command_list
/* 0EA5E0 7F0B7BF0 03112021 */   addu  $a0, $t8, $s1
/* 0EA5E4 7F0B7BF4 90590001 */  lbu   $t9, 1($v0)
/* 0EA5E8 7F0B7BF8 001940C0 */  sll   $t0, $t9, 3
/* 0EA5EC 7F0B7BFC 1000FECC */  b     .L7F0B7730
/* 0EA5F0 7F0B7C00 00488821 */   addu  $s1, $v0, $t0
endif_continue_exec:
/* 0EA5F4 7F0B7C04 92290001 */  lbu   $t1, 1($s1)
/* 0EA5F8 7F0B7C08 3C018007 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10) # $at, 0x8007
/* 0EA5FC 7F0B7C0C AC20BFB8 */  sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
/* 0EA600 7F0B7C10 000950C0 */  sll   $t2, $t1, 3
/* 0EA604 7F0B7C14 10000023 */  b     .L7F0B7CA4
/* 0EA608 7F0B7C18 022A1021 */   addu  $v0, $s1, $t2
dont_exec_commands_even_on_return:
/* 0EA60C 7F0B7C1C 922B0001 */  lbu   $t3, 1($s1)
/* 0EA610 7F0B7C20 0012102B */  sltu  $v0, $zero, $s2
/* 0EA614 7F0B7C24 00009025 */  move  $s2, $zero
/* 0EA618 7F0B7C28 000B60C0 */  sll   $t4, $t3, 3
/* 0EA61C 7F0B7C2C 1040FEC0 */  beqz  $v0, .L7F0B7730
/* 0EA620 7F0B7C30 022C8821 */   addu  $s1, $s1, $t4
/* 0EA624 7F0B7C34 3C018007 */  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10) # $at, 0x8007
/* 0EA628 7F0B7C38 1000FEBD */  b     .L7F0B7730
/* 0EA62C 7F0B7C3C AC37BFB8 */   sw    $s7, %lo(dword_CODE_bss_80081600 + 0x10)($at)
if_statement_pull_from_stack:
/* 0EA630 7F0B7C40 0FC2DD98 */  jal   bgStackPop
/* 0EA634 7F0B7C44 00000000 */   nop
/* 0EA638 7F0B7C48 922D0001 */  lbu   $t5, 1($s1)
/* 0EA63C 7F0B7C4C 00522824 */  and   $a1, $v0, $s2
/* 0EA640 7F0B7C50 000D70C0 */  sll   $t6, $t5, 3
/* 0EA644 7F0B7C54 0FC2DDB1 */  jal   parse_global_vis_command_list
/* 0EA648 7F0B7C58 01D12021 */   addu  $a0, $t6, $s1
/* 0EA64C 7F0B7C5C 3C0F8007 */  lui   $t7, %hi(dword_CODE_bss_80081600 + 0x10) # $t7, 0x8007
/* 0EA650 7F0B7C60 8DEFBFB8 */  lw    $t7, %lo(dword_CODE_bss_80081600 + 0x10)($t7)
/* 0EA654 7F0B7C64 00408825 */  move  $s1, $v0
/* 0EA658 7F0B7C68 51E0FEB2 */  beql  $t7, $zero, .L7F0B7734
/* 0EA65C 7F0B7C6C 92240000 */   lbu   $a0, ($s1)
/* 0EA660 7F0B7C70 1000FEAF */  b     .L7F0B7730
/* 0EA664 7F0B7C74 00009025 */   move  $s2, $zero
toggle_exec_vs_ro:
/* 0EA668 7F0B7C78 92390001 */  lbu   $t9, 1($s1)
/* 0EA66C 7F0B7C7C 3A580001 */  xori  $t8, $s2, 1
/* 0EA670 7F0B7C80 03009025 */  move  $s2, $t8
/* 0EA674 7F0B7C84 001940C0 */  sll   $t0, $t9, 3
/* 0EA678 7F0B7C88 1000FEA9 */  b     .L7F0B7730
/* 0EA67C 7F0B7C8C 02288821 */   addu  $s1, $s1, $t0
endif:
/* 0EA680 7F0B7C90 92290001 */  lbu   $t1, 1($s1)
/* 0EA684 7F0B7C94 000950C0 */  sll   $t2, $t1, 3
/* 0EA688 7F0B7C98 10000002 */  b     .L7F0B7CA4
/* 0EA68C 7F0B7C9C 022A1021 */   addu  $v0, $s1, $t2
invalid_type_terminate:
.L7F0B7CA0:
/* 0EA690 7F0B7CA0 02201025 */  move  $v0, $s1
.L7F0B7CA4:
/* 0EA694 7F0B7CA4 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0EA698 7F0B7CA8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EA69C 7F0B7CAC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0EA6A0 7F0B7CB0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0EA6A4 7F0B7CB4 8FB30024 */  lw    $s3, 0x24($sp)
/* 0EA6A8 7F0B7CB8 8FB40028 */  lw    $s4, 0x28($sp)
/* 0EA6AC 7F0B7CBC 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0EA6B0 7F0B7CC0 8FB60030 */  lw    $s6, 0x30($sp)
/* 0EA6B4 7F0B7CC4 8FB70034 */  lw    $s7, 0x34($sp)
/* 0EA6B8 7F0B7CC8 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0EA6BC 7F0B7CCC 03E00008 */  jr    $ra
/* 0EA6C0 7F0B7CD0 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif
#endif


#define RS_STOP 0


// Something about portals. Void* are structs.
void *sub_GAME_7F0B8A24(s32 *pc) {

    current_visibility = 0;
    if (!pc)
    {
        return pc;
    }

    bgStackGetNthValueFromEnd(0);
    #ifdef DEBUG
    assert( pc->type==RS_STOP)
    #endif

    return parse_global_vis_command_list(pc, 1);
}





#ifdef NONMATCHING
void sub_GAME_7F0B8A6C(void) {

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8A6C
/* 0ED59C 7F0B8A6C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0ED5A0 7F0B8A70 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0ED5A4 7F0B8A74 AFB10020 */  sw    $s1, 0x20($sp)
/* 0ED5A8 7F0B8A78 0FC2E423 */  jal   bgUpdateCurrentPlayerScreenMinMax
/* 0ED5AC 7F0B8A7C AFB0001C */   sw    $s0, 0x1c($sp)
/* 0ED5B0 7F0B8A80 3C118008 */  lui   $s1, %hi(g_CurrentPlayer)
/* 0ED5B4 7F0B8A84 2631A0B0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x5f50
/* 0ED5B8 7F0B8A88 8E220000 */  lw    $v0, ($s1)
/* 0ED5BC 7F0B8A8C C4441118 */  lwc1  $f4, 0x1118($v0)
/* 0ED5C0 7F0B8A90 E7A40050 */  swc1  $f4, 0x50($sp)
/* 0ED5C4 7F0B8A94 C446111C */  lwc1  $f6, 0x111c($v0)
/* 0ED5C8 7F0B8A98 E7A60054 */  swc1  $f6, 0x54($sp)
/* 0ED5CC 7F0B8A9C C4481120 */  lwc1  $f8, 0x1120($v0)
/* 0ED5D0 7F0B8AA0 E7A80058 */  swc1  $f8, 0x58($sp)
/* 0ED5D4 7F0B8AA4 C44A1124 */  lwc1  $f10, 0x1124($v0)
/* 0ED5D8 7F0B8AA8 0FC2CEF1 */  jal   sub_GAME_7F0B3BC4
/* 0ED5DC 7F0B8AAC E7AA005C */   swc1  $f10, 0x5c($sp)
/* 0ED5E0 7F0B8AB0 3C028004 */  lui   $v0, %hi(g_BgRoomInfo)
/* 0ED5E4 7F0B8AB4 3C038004 */  lui   $v1, %hi(g_MaxNumRooms)
/* 0ED5E8 7F0B8AB8 246342F4 */  addiu $v1, %lo(g_MaxNumRooms) # addiu $v1, $v1, 0x42f4
/* 0ED5EC 7F0B8ABC 24421414 */  addiu $v0, %lo(g_BgRoomInfo) # addiu $v0, $v0, 0x1414
.L7F0B8AC0:
/* 0ED5F0 7F0B8AC0 24420050 */  addiu $v0, $v0, 0x50
/* 0ED5F4 7F0B8AC4 0043082B */  sltu  $at, $v0, $v1
/* 0ED5F8 7F0B8AC8 A040FFB0 */  sb    $zero, -0x50($v0)
/* 0ED5FC 7F0B8ACC A040FFB1 */  sb    $zero, -0x4f($v0)
/* 0ED600 7F0B8AD0 1420FFFB */  bnez  $at, .L7F0B8AC0
/* 0ED604 7F0B8AD4 A040FFE4 */   sb    $zero, -0x1c($v0)
/* 0ED608 7F0B8AD8 3C028004 */  lui   $v0, %hi(D_800442FC)
/* 0ED60C 7F0B8ADC 3C038004 */  lui   $v1, %hi(D_800443C4)
/* 0ED610 7F0B8AE0 246343C4 */  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, 0x43c4
/* 0ED614 7F0B8AE4 244242FC */  addiu $v0, %lo(D_800442FC) # addiu $v0, $v0, 0x42fc
.L7F0B8AE8:
/* 0ED618 7F0B8AE8 24420004 */  addiu $v0, $v0, 4
/* 0ED61C 7F0B8AEC A040FFFD */  sb    $zero, -3($v0)
/* 0ED620 7F0B8AF0 A040FFFE */  sb    $zero, -2($v0)
/* 0ED624 7F0B8AF4 A040FFFF */  sb    $zero, -1($v0)
/* 0ED628 7F0B8AF8 1443FFFB */  bne   $v0, $v1, .L7F0B8AE8
/* 0ED62C 7F0B8AFC A040FFFC */   sb    $zero, -4($v0)
/* 0ED630 7F0B8B00 3C028004 */  lui   $v0, %hi(D_80044858)
/* 0ED634 7F0B8B04 24424858 */  addiu $v0, %lo(D_80044858) # addiu $v0, $v0, 0x4858
/* 0ED638 7F0B8B08 8C4E0000 */  lw    $t6, ($v0)
/* 0ED63C 7F0B8B0C 2401000A */  li    $at, 10
/* 0ED640 7F0B8B10 25CF0001 */  addiu $t7, $t6, 1
/* 0ED644 7F0B8B14 01E1001A */  div   $zero, $t7, $at
/* 0ED648 7F0B8B18 0000C010 */  mfhi  $t8
/* 0ED64C 7F0B8B1C AC580000 */  sw    $t8, ($v0)
/* 0ED650 7F0B8B20 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007FF98)
/* 0ED654 7F0B8B24 AC20FF98 */  sw    $zero, %lo(dword_CODE_bss_8007FF98)($at)
/* 0ED658 7F0B8B28 3C018004 */  lui   $at, %hi(D_80044898)
/* 0ED65C 7F0B8B2C 0FC2DF65 */  jal   sub_GAME_7F0B7D94
/* 0ED660 7F0B8B30 AC204898 */   sw    $zero, %lo(D_80044898)($at)
/* 0ED664 7F0B8B34 0FC2D45A */  jal   sub_GAME_7F0B5168
/* 0ED668 7F0B8B38 00000000 */   nop
/* 0ED66C 7F0B8B3C 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007FF90)
/* 0ED670 7F0B8B40 0FC2E289 */  jal   sub_GAME_7F0B8A24
/* 0ED674 7F0B8B44 8C84FF90 */   lw    $a0, %lo(dword_CODE_bss_8007FF90)($a0)
/* 0ED678 7F0B8B48 3C028004 */  lui   $v0, %hi(levelentry_index)
/* 0ED67C 7F0B8B4C 8C421400 */  lw    $v0, %lo(levelentry_index)($v0)
/* 0ED680 7F0B8B50 24030015 */  li    $v1, 21
/* 0ED684 7F0B8B54 3C198008 */  lui   $t9, %hi(g_BgPortals)
/* 0ED688 7F0B8B58 10620005 */  beq   $v1, $v0, .L7F0B8B70
/* 0ED68C 7F0B8B5C 00000000 */   nop
/* 0ED690 7F0B8B60 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0ED694 7F0B8B64 8F2A0000 */  lw    $t2, ($t9)
/* 0ED698 7F0B8B68 15400023 */  bnez  $t2, .L7F0B8BF8
/* 0ED69C 7F0B8B6C 00000000 */   nop
.L7F0B8B70:
/* 0ED6A0 7F0B8B70 14620006 */  bne   $v1, $v0, .L7F0B8B8C
/* 0ED6A4 7F0B8B74 24040009 */   li    $a0, 9
/* 0ED6A8 7F0B8B78 8E260000 */  lw    $a2, ($s1)
/* 0ED6AC 7F0B8B7C 00002825 */  move  $a1, $zero
/* 0ED6B0 7F0B8B80 24070001 */  li    $a3, 1
/* 0ED6B4 7F0B8B84 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ED6B8 7F0B8B88 24C61118 */   addiu $a2, $a2, 0x1118
.L7F0B8B8C:
/* 0ED6BC 7F0B8B8C 3C0B8004 */  lui   $t3, %hi(g_MaxNumRooms)
/* 0ED6C0 7F0B8B90 8D6B42F4 */  lw    $t3, %lo(g_MaxNumRooms)($t3)
/* 0ED6C4 7F0B8B94 24100001 */  li    $s0, 1
/* 0ED6C8 7F0B8B98 29610002 */  slti  $at, $t3, 2
/* 0ED6CC 7F0B8B9C 14200012 */  bnez  $at, .L7F0B8BE8
/* 0ED6D0 7F0B8BA0 00000000 */   nop
/* 0ED6D4 7F0B8BA4 8E250000 */  lw    $a1, ($s1)
.L7F0B8BA8:
/* 0ED6D8 7F0B8BA8 02002025 */  move  $a0, $s0
/* 0ED6DC 7F0B8BAC 0FC2D482 */  jal   sub_GAME_7F0B5208
/* 0ED6E0 7F0B8BB0 24A51118 */   addiu $a1, $a1, 0x1118
/* 0ED6E4 7F0B8BB4 10400006 */  beqz  $v0, .L7F0B8BD0
/* 0ED6E8 7F0B8BB8 02002025 */   move  $a0, $s0
/* 0ED6EC 7F0B8BBC 8E260000 */  lw    $a2, ($s1)
/* 0ED6F0 7F0B8BC0 00002825 */  move  $a1, $zero
/* 0ED6F4 7F0B8BC4 24070001 */  li    $a3, 1
/* 0ED6F8 7F0B8BC8 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ED6FC 7F0B8BCC 24C61118 */   addiu $a2, $a2, 0x1118
.L7F0B8BD0:
/* 0ED700 7F0B8BD0 3C0C8004 */  lui   $t4, %hi(g_MaxNumRooms)
/* 0ED704 7F0B8BD4 8D8C42F4 */  lw    $t4, %lo(g_MaxNumRooms)($t4)
/* 0ED708 7F0B8BD8 26100001 */  addiu $s0, $s0, 1
/* 0ED70C 7F0B8BDC 020C082A */  slt   $at, $s0, $t4
/* 0ED710 7F0B8BE0 5420FFF1 */  bnezl $at, .L7F0B8BA8
/* 0ED714 7F0B8BE4 8E250000 */   lw    $a1, ($s1)
.L7F0B8BE8:
/* 0ED718 7F0B8BE8 3C048008 */  lui   $a0, %hi(g_BgPortals)
/* 0ED71C 7F0B8BEC 8C84FF80 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0ED720 7F0B8BF0 10000039 */  b     .L7F0B8CD8
/* 0ED724 7F0B8BF4 8C820000 */   lw    $v0, ($a0)
.L7F0B8BF8:
/* 0ED728 7F0B8BF8 14620006 */  bne   $v1, $v0, .L7F0B8C14
/* 0ED72C 7F0B8BFC 24040009 */   li    $a0, 9
/* 0ED730 7F0B8C00 8E260000 */  lw    $a2, ($s1)
/* 0ED734 7F0B8C04 00002825 */  move  $a1, $zero
/* 0ED738 7F0B8C08 24070001 */  li    $a3, 1
/* 0ED73C 7F0B8C0C 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ED740 7F0B8C10 24C61118 */   addiu $a2, $a2, 0x1118
.L7F0B8C14:
/* 0ED744 7F0B8C14 8E260000 */  lw    $a2, ($s1)
/* 0ED748 7F0B8C18 3C048004 */  lui   $a0, %hi(g_BgCurrentRoom)
/* 0ED74C 7F0B8C1C 8C844838 */  lw    $a0, %lo(g_BgCurrentRoom)($a0)
/* 0ED750 7F0B8C20 00002825 */  move  $a1, $zero
/* 0ED754 7F0B8C24 24070001 */  li    $a3, 1
/* 0ED758 7F0B8C28 0FC2CE6F */  jal   sub_GAME_7F0B39BC
/* 0ED75C 7F0B8C2C 24C61118 */   addiu $a2, $a2, 0x1118
/* 0ED760 7F0B8C30 3C048008 */  lui   $a0, %hi(g_BgPortals)
/* 0ED764 7F0B8C34 8C84FF80 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0ED768 7F0B8C38 00008025 */  move  $s0, $zero
/* 0ED76C 7F0B8C3C 00001825 */  move  $v1, $zero
/* 0ED770 7F0B8C40 8C8D0000 */  lw    $t5, ($a0)
/* 0ED774 7F0B8C44 00801025 */  move  $v0, $a0
/* 0ED778 7F0B8C48 11A00016 */  beqz  $t5, .L7F0B8CA4
.L7F0B8C4C:
/* 0ED77C 7F0B8C4C 3C058004 */   lui   $a1, %hi(g_BgCurrentRoom)
/* 0ED780 7F0B8C50 8CA54838 */  lw    $a1, %lo(g_BgCurrentRoom)($a1)
/* 0ED784 7F0B8C54 904E0004 */  lbu   $t6, 4($v0)
/* 0ED788 7F0B8C58 00002025 */  move  $a0, $zero
/* 0ED78C 7F0B8C5C 02003025 */  move  $a2, $s0
/* 0ED790 7F0B8C60 10AE0003 */  beq   $a1, $t6, .L7F0B8C70
/* 0ED794 7F0B8C64 24070001 */   li    $a3, 1
/* 0ED798 7F0B8C68 904F0005 */  lbu   $t7, 5($v0)
/* 0ED79C 7F0B8C6C 14AF0008 */  bne   $a1, $t7, .L7F0B8C90
.L7F0B8C70:
/* 0ED7A0 7F0B8C70 27B80050 */   addiu $t8, $sp, 0x50
/* 0ED7A4 7F0B8C74 AFB80010 */  sw    $t8, 0x10($sp)
/* 0ED7A8 7F0B8C78 0FC2DF79 */  jal   sub_GAME_7F0B7DE4
/* 0ED7AC 7F0B8C7C AFA30034 */   sw    $v1, 0x34($sp)
/* 0ED7B0 7F0B8C80 3C198008 */  lui   $t9, %hi(g_BgPortals)
/* 0ED7B4 7F0B8C84 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0ED7B8 7F0B8C88 8FA30034 */  lw    $v1, 0x34($sp)
/* 0ED7BC 7F0B8C8C 03231021 */  addu  $v0, $t9, $v1
.L7F0B8C90:
/* 0ED7C0 7F0B8C90 8C4A0008 */  lw    $t2, 8($v0)
/* 0ED7C4 7F0B8C94 26100001 */  addiu $s0, $s0, 1
/* 0ED7C8 7F0B8C98 24630008 */  addiu $v1, $v1, 8
/* 0ED7CC 7F0B8C9C 1540FFEB */  bnez  $t2, .L7F0B8C4C
/* 0ED7D0 7F0B8CA0 24420008 */   addiu $v0, $v0, 8
.L7F0B8CA4:
/* 0ED7D4 7F0B8CA4 27B00044 */  addiu $s0, $sp, 0x44
/* 0ED7D8 7F0B8CA8 AFA00044 */  sw    $zero, 0x44($sp)
/* 0ED7DC 7F0B8CAC 0FC2DFB9 */  jal   sub_GAME_7F0B7EE4
/* 0ED7E0 7F0B8CB0 02002025 */   move  $a0, $s0
/* 0ED7E4 7F0B8CB4 10400005 */  beqz  $v0, .L7F0B8CCC
/* 0ED7E8 7F0B8CB8 00000000 */   nop
.L7F0B8CBC:
/* 0ED7EC 7F0B8CBC 0FC2DFB9 */  jal   sub_GAME_7F0B7EE4
/* 0ED7F0 7F0B8CC0 02002025 */   move  $a0, $s0
/* 0ED7F4 7F0B8CC4 1440FFFD */  bnez  $v0, .L7F0B8CBC
/* 0ED7F8 7F0B8CC8 00000000 */   nop
.L7F0B8CCC:
/* 0ED7FC 7F0B8CCC 3C048008 */  lui   $a0, %hi(g_BgPortals)
/* 0ED800 7F0B8CD0 8C84FF80 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0ED804 7F0B8CD4 8C820000 */  lw    $v0, ($a0)
.L7F0B8CD8:
/* 0ED808 7F0B8CD8 10400022 */  beqz  $v0, .L7F0B8D64
/* 0ED80C 7F0B8CDC 24090001 */   li    $t1, 1
/* 0ED810 7F0B8CE0 3C078004 */  lui   $a3, %hi(g_BgRoomInfo)
/* 0ED814 7F0B8CE4 24E71414 */  addiu $a3, %lo(g_BgRoomInfo) # addiu $a3, $a3, 0x1414
/* 0ED818 7F0B8CE8 00801025 */  move  $v0, $a0
/* 0ED81C 7F0B8CEC 24080050 */  li    $t0, 80
/* 0ED820 7F0B8CF0 90430004 */  lbu   $v1, 4($v0)
.L7F0B8CF4:
/* 0ED824 7F0B8CF4 90440005 */  lbu   $a0, 5($v0)
/* 0ED828 7F0B8CF8 00680019 */  multu $v1, $t0
/* 0ED82C 7F0B8CFC 00005812 */  mflo  $t3
/* 0ED830 7F0B8D00 00EB2821 */  addu  $a1, $a3, $t3
/* 0ED834 7F0B8D04 90A60000 */  lbu   $a2, ($a1)
/* 0ED838 7F0B8D08 10C00009 */  beqz  $a2, .L7F0B8D30
/* 0ED83C 7F0B8D0C 00000000 */   nop
/* 0ED840 7F0B8D10 00880019 */  multu $a0, $t0
/* 0ED844 7F0B8D14 00006012 */  mflo  $t4
/* 0ED848 7F0B8D18 00EC1821 */  addu  $v1, $a3, $t4
/* 0ED84C 7F0B8D1C 906D0000 */  lbu   $t5, ($v1)
/* 0ED850 7F0B8D20 15A00003 */  bnez  $t5, .L7F0B8D30
/* 0ED854 7F0B8D24 00000000 */   nop
/* 0ED858 7F0B8D28 1000000A */  b     .L7F0B8D54
/* 0ED85C 7F0B8D2C A0690001 */   sb    $t1, 1($v1)
.L7F0B8D30:
/* 0ED860 7F0B8D30 00880019 */  multu $a0, $t0
/* 0ED864 7F0B8D34 00007012 */  mflo  $t6
/* 0ED868 7F0B8D38 00EE7821 */  addu  $t7, $a3, $t6
/* 0ED86C 7F0B8D3C 91F80000 */  lbu   $t8, ($t7)
/* 0ED870 7F0B8D40 53000005 */  beql  $t8, $zero, .L7F0B8D58
/* 0ED874 7F0B8D44 8C590008 */   lw    $t9, 8($v0)
/* 0ED878 7F0B8D48 54C00003 */  bnezl $a2, .L7F0B8D58
/* 0ED87C 7F0B8D4C 8C590008 */   lw    $t9, 8($v0)
/* 0ED880 7F0B8D50 A0A90001 */  sb    $t1, 1($a1)
.L7F0B8D54:
/* 0ED884 7F0B8D54 8C590008 */  lw    $t9, 8($v0)
.L7F0B8D58:
/* 0ED888 7F0B8D58 24420008 */  addiu $v0, $v0, 8
/* 0ED88C 7F0B8D5C 5720FFE5 */  bnezl $t9, .L7F0B8CF4
/* 0ED890 7F0B8D60 90430004 */   lbu   $v1, 4($v0)
.L7F0B8D64:
/* 0ED894 7F0B8D64 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0ED898 7F0B8D68 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0ED89C 7F0B8D6C 8FB10020 */  lw    $s1, 0x20($sp)
/* 0ED8A0 7F0B8D70 03E00008 */  jr    $ra
/* 0ED8A4 7F0B8D74 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8A6C
/* 0EA70C 7F0B7D1C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0EA710 7F0B7D20 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA714 7F0B7D24 AFB10018 */  sw    $s1, 0x18($sp)
/* 0EA718 7F0B7D28 0FC2E0CA */  jal   bgUpdateCurrentPlayerScreenMinMax
/* 0EA71C 7F0B7D2C AFB00014 */   sw    $s0, 0x14($sp)
/* 0EA720 7F0B7D30 3C118007 */  lui   $s1, %hi(g_CurrentPlayer) # $s1, 0x8007
/* 0EA724 7F0B7D34 26318BC0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x7440
/* 0EA728 7F0B7D38 8E220000 */  lw    $v0, ($s1)
/* 0EA72C 7F0B7D3C C4441110 */  lwc1  $f4, 0x1110($v0)
/* 0EA730 7F0B7D40 E7A40040 */  swc1  $f4, 0x40($sp)
/* 0EA734 7F0B7D44 C4461114 */  lwc1  $f6, 0x1114($v0)
/* 0EA738 7F0B7D48 E7A60044 */  swc1  $f6, 0x44($sp)
/* 0EA73C 7F0B7D4C C4481118 */  lwc1  $f8, 0x1118($v0)
/* 0EA740 7F0B7D50 E7A80048 */  swc1  $f8, 0x48($sp)
/* 0EA744 7F0B7D54 C44A111C */  lwc1  $f10, 0x111c($v0)
/* 0EA748 7F0B7D58 0FC2CBB3 */  jal   sub_GAME_7F0B3BC4
/* 0EA74C 7F0B7D5C E7AA004C */   swc1  $f10, 0x4c($sp)
/* 0EA750 7F0B7D60 3C028004 */  lui   $v0, %hi(g_BgRoomInfo) # $v0, 0x8004
/* 0EA754 7F0B7D64 3C038004 */  lui   $v1, %hi(g_MaxNumRooms) # $v1, 0x8004
/* 0EA758 7F0B7D68 2463D7D4 */  addiu $v1, %lo(g_MaxNumRooms) # addiu $v1, $v1, -0x282c
/* 0EA75C 7F0B7D6C 2442AC64 */  addiu $v0, %lo(g_BgRoomInfo) # addiu $v0, $v0, -0x539c
.L7F0B7D70:
/* 0EA760 7F0B7D70 24420050 */  addiu $v0, $v0, 0x50
/* 0EA764 7F0B7D74 0043082B */  sltu  $at, $v0, $v1
/* 0EA768 7F0B7D78 A040FFB0 */  sb    $zero, -0x50($v0)
/* 0EA76C 7F0B7D7C A040FFB1 */  sb    $zero, -0x4f($v0)
/* 0EA770 7F0B7D80 1420FFFB */  bnez  $at, .L7F0B7D70
/* 0EA774 7F0B7D84 A040FFE4 */   sb    $zero, -0x1c($v0)
/* 0EA778 7F0B7D88 3C028004 */  lui   $v0, %hi(D_800442FC) # $v0, 0x8004
/* 0EA77C 7F0B7D8C 3C038004 */  lui   $v1, %hi(D_800443C4) # $v1, 0x8004
/* 0EA780 7F0B7D90 2463D8A4 */  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, -0x275c
/* 0EA784 7F0B7D94 2442D7DC */  addiu $v0, %lo(D_800442FC) # addiu $v0, $v0, -0x2824
.L7F0B7D98:
/* 0EA788 7F0B7D98 24420004 */  addiu $v0, $v0, 4
/* 0EA78C 7F0B7D9C A040FFFD */  sb    $zero, -3($v0)
/* 0EA790 7F0B7DA0 A040FFFE */  sb    $zero, -2($v0)
/* 0EA794 7F0B7DA4 A040FFFF */  sb    $zero, -1($v0)
/* 0EA798 7F0B7DA8 1443FFFB */  bne   $v0, $v1, .L7F0B7D98
/* 0EA79C 7F0B7DAC A040FFFC */   sb    $zero, -4($v0)
/* 0EA7A0 7F0B7DB0 3C028004 */  lui   $v0, %hi(D_80044858) # $v0, 0x8004
/* 0EA7A4 7F0B7DB4 2442DD40 */  addiu $v0, %lo(D_80044858) # addiu $v0, $v0, -0x22c0
/* 0EA7A8 7F0B7DB8 8C4E0000 */  lw    $t6, ($v0)
/* 0EA7AC 7F0B7DBC 2401000A */  li    $at, 10
/* 0EA7B0 7F0B7DC0 25CF0001 */  addiu $t7, $t6, 1
/* 0EA7B4 7F0B7DC4 01E1001A */  div   $zero, $t7, $at
/* 0EA7B8 7F0B7DC8 0000C010 */  mfhi  $t8
/* 0EA7BC 7F0B7DCC AC580000 */  sw    $t8, ($v0)
/* 0EA7C0 7F0B7DD0 3C018007 */  lui   $at, %hi(dword_CODE_bss_8007FFA0 + 0xb40) # $at, 0x8007
/* 0EA7C4 7F0B7DD4 AC20BF20 */  sw    $zero, %lo(dword_CODE_bss_8007FFA0 + 0xb40)($at)
/* 0EA7C8 7F0B7DD8 3C018004 */  lui   $at, %hi(D_80044898) # $at, 0x8004
/* 0EA7CC 7F0B7DDC 0FC2DC34 */  jal   sub_GAME_7F0B7D94
/* 0EA7D0 7F0B7DE0 AC20DD80 */   sw    $zero, %lo(D_80044898)($at)
/* 0EA7D4 7F0B7DE4 0FC2D129 */  jal   sub_GAME_7F0B5168
/* 0EA7D8 7F0B7DE8 00000000 */   nop
/* 0EA7DC 7F0B7DEC 3C048007 */  lui   $a0, %hi(dword_CODE_bss_8007FF90) # $a0, 0x8007
/* 0EA7E0 7F0B7DF0 0FC2DF35 */  jal   sub_GAME_7F0B8A24
/* 0EA7E4 7F0B7DF4 8C84B3D8 */   lw    $a0, %lo(dword_CODE_bss_8007FF90)($a0)
/* 0EA7E8 7F0B7DF8 3C028004 */  lui   $v0, %hi(levelentry_index) # $v0, 0x8004
/* 0EA7EC 7F0B7DFC 8C42AC50 */  lw    $v0, %lo(levelentry_index)($v0)
/* 0EA7F0 7F0B7E00 24030015 */  li    $v1, 21
/* 0EA7F4 7F0B7E04 3C198007 */  lui   $t9, %hi(g_BgPortals) # $t9, 0x8007
/* 0EA7F8 7F0B7E08 10620005 */  beq   $v1, $v0, .L7F0B7E20
/* 0EA7FC 7F0B7E0C 00000000 */   nop
/* 0EA800 7F0B7E10 8F39B3C8 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0EA804 7F0B7E14 8F2A0000 */  lw    $t2, ($t9)
/* 0EA808 7F0B7E18 15400021 */  bnez  $t2, .L7F0B7EA0
/* 0EA80C 7F0B7E1C 00000000 */   nop
.L7F0B7E20:
/* 0EA810 7F0B7E20 14620006 */  bne   $v1, $v0, .L7F0B7E3C
/* 0EA814 7F0B7E24 24040009 */   li    $a0, 9
/* 0EA818 7F0B7E28 8E260000 */  lw    $a2, ($s1)
/* 0EA81C 7F0B7E2C 00002825 */  move  $a1, $zero
/* 0EA820 7F0B7E30 24070001 */  li    $a3, 1
/* 0EA824 7F0B7E34 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0EA828 7F0B7E38 24C61110 */   addiu $a2, $a2, 0x1110
.L7F0B7E3C:
/* 0EA82C 7F0B7E3C 3C0B8004 */  lui   $t3, %hi(g_MaxNumRooms) # $t3, 0x8004
/* 0EA830 7F0B7E40 8D6BD7D4 */  lw    $t3, %lo(g_MaxNumRooms)($t3)
/* 0EA834 7F0B7E44 24100001 */  li    $s0, 1
/* 0EA838 7F0B7E48 29610002 */  slti  $at, $t3, 2
/* 0EA83C 7F0B7E4C 14200012 */  bnez  $at, .L7F0B7E98
/* 0EA840 7F0B7E50 00000000 */   nop
/* 0EA844 7F0B7E54 8E250000 */  lw    $a1, ($s1)
.L7F0B7E58:
/* 0EA848 7F0B7E58 02002025 */  move  $a0, $s0
/* 0EA84C 7F0B7E5C 0FC2D151 */  jal   sub_GAME_7F0B5208
/* 0EA850 7F0B7E60 24A51110 */   addiu $a1, $a1, 0x1110
/* 0EA854 7F0B7E64 10400006 */  beqz  $v0, .L7F0B7E80
/* 0EA858 7F0B7E68 02002025 */   move  $a0, $s0
/* 0EA85C 7F0B7E6C 8E260000 */  lw    $a2, ($s1)
/* 0EA860 7F0B7E70 00002825 */  move  $a1, $zero
/* 0EA864 7F0B7E74 24070001 */  li    $a3, 1
/* 0EA868 7F0B7E78 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0EA86C 7F0B7E7C 24C61110 */   addiu $a2, $a2, 0x1110
.L7F0B7E80:
/* 0EA870 7F0B7E80 3C0C8004 */  lui   $t4, %hi(g_MaxNumRooms) # $t4, 0x8004
/* 0EA874 7F0B7E84 8D8CD7D4 */  lw    $t4, %lo(g_MaxNumRooms)($t4)
/* 0EA878 7F0B7E88 26100001 */  addiu $s0, $s0, 1
/* 0EA87C 7F0B7E8C 020C082A */  slt   $at, $s0, $t4
/* 0EA880 7F0B7E90 5420FFF1 */  bnezl $at, .L7F0B7E58
/* 0EA884 7F0B7E94 8E250000 */   lw    $a1, ($s1)
.L7F0B7E98:
/* 0EA888 7F0B7E98 10000033 */  b     .L7F0B7F68
/* 0EA88C 7F0B7E9C 00000000 */   nop
.L7F0B7EA0:
/* 0EA890 7F0B7EA0 14620006 */  bne   $v1, $v0, .L7F0B7EBC
/* 0EA894 7F0B7EA4 24040009 */   li    $a0, 9
/* 0EA898 7F0B7EA8 8E260000 */  lw    $a2, ($s1)
/* 0EA89C 7F0B7EAC 00002825 */  move  $a1, $zero
/* 0EA8A0 7F0B7EB0 24070001 */  li    $a3, 1
/* 0EA8A4 7F0B7EB4 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0EA8A8 7F0B7EB8 24C61110 */   addiu $a2, $a2, 0x1110
.L7F0B7EBC:
/* 0EA8AC 7F0B7EBC 8E260000 */  lw    $a2, ($s1)
/* 0EA8B0 7F0B7EC0 3C048004 */  lui   $a0, %hi(g_BgCurrentRoom) # $a0, 0x8004
/* 0EA8B4 7F0B7EC4 8C84DD18 */  lw    $a0, %lo(g_BgCurrentRoom)($a0)
/* 0EA8B8 7F0B7EC8 00002825 */  move  $a1, $zero
/* 0EA8BC 7F0B7ECC 24070001 */  li    $a3, 1
/* 0EA8C0 7F0B7ED0 0FC2CB1F */  jal   sub_GAME_7F0B39BC
/* 0EA8C4 7F0B7ED4 24C61110 */   addiu $a2, $a2, 0x1110
/* 0EA8C8 7F0B7ED8 3C048007 */  lui   $a0, %hi(g_BgPortals) # $a0, 0x8007
/* 0EA8CC 7F0B7EDC 8C84B3C8 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0EA8D0 7F0B7EE0 00008025 */  move  $s0, $zero
/* 0EA8D4 7F0B7EE4 00001825 */  move  $v1, $zero
/* 0EA8D8 7F0B7EE8 8C8D0000 */  lw    $t5, ($a0)
/* 0EA8DC 7F0B7EEC 00801025 */  move  $v0, $a0
/* 0EA8E0 7F0B7EF0 11A00015 */  beqz  $t5, .L7F0B7F48
.L7F0B7EF4:
/* 0EA8E4 7F0B7EF4 3C048004 */   lui   $a0, %hi(g_BgCurrentRoom) # $a0, 0x8004
/* 0EA8E8 7F0B7EF8 8C84DD18 */  lw    $a0, %lo(g_BgCurrentRoom)($a0)
/* 0EA8EC 7F0B7EFC 904E0004 */  lbu   $t6, 4($v0)
/* 0EA8F0 7F0B7F00 02002825 */  move  $a1, $s0
/* 0EA8F4 7F0B7F04 24060001 */  li    $a2, 1
/* 0EA8F8 7F0B7F08 108E0004 */  beq   $a0, $t6, .L7F0B7F1C
/* 0EA8FC 7F0B7F0C 27A70040 */   addiu $a3, $sp, 0x40
/* 0EA900 7F0B7F10 904F0005 */  lbu   $t7, 5($v0)
/* 0EA904 7F0B7F14 548F0008 */  bnel  $a0, $t7, .L7F0B7F38
/* 0EA908 7F0B7F18 8C590008 */   lw    $t9, 8($v0)
.L7F0B7F1C:
/* 0EA90C 7F0B7F1C 0FC2DC48 */  jal   sub_GAME_7F0B7DE4
/* 0EA910 7F0B7F20 AFA30028 */   sw    $v1, 0x28($sp)
/* 0EA914 7F0B7F24 3C188007 */  lui   $t8, %hi(g_BgPortals) # $t8, 0x8007
/* 0EA918 7F0B7F28 8F18B3C8 */  lw    $t8, %lo(g_BgPortals)($t8)
/* 0EA91C 7F0B7F2C 8FA30028 */  lw    $v1, 0x28($sp)
/* 0EA920 7F0B7F30 03031021 */  addu  $v0, $t8, $v1
/* 0EA924 7F0B7F34 8C590008 */  lw    $t9, 8($v0)
.L7F0B7F38:
/* 0EA928 7F0B7F38 26100001 */  addiu $s0, $s0, 1
/* 0EA92C 7F0B7F3C 24630008 */  addiu $v1, $v1, 8
/* 0EA930 7F0B7F40 1720FFEC */  bnez  $t9, .L7F0B7EF4
/* 0EA934 7F0B7F44 24420008 */   addiu $v0, $v0, 8
.L7F0B7F48:
/* 0EA938 7F0B7F48 0FC2DC88 */  jal   sub_GAME_7F0B7EE4
/* 0EA93C 7F0B7F4C 00000000 */   nop
/* 0EA940 7F0B7F50 10400005 */  beqz  $v0, .L7F0B7F68
/* 0EA944 7F0B7F54 00000000 */   nop
.L7F0B7F58:
/* 0EA948 7F0B7F58 0FC2DC88 */  jal   sub_GAME_7F0B7EE4
/* 0EA94C 7F0B7F5C 00000000 */   nop
/* 0EA950 7F0B7F60 1440FFFD */  bnez  $v0, .L7F0B7F58
/* 0EA954 7F0B7F64 00000000 */   nop
.L7F0B7F68:
/* 0EA958 7F0B7F68 3C048007 */  lui   $a0, %hi(g_BgPortals) # $a0, 0x8007
/* 0EA95C 7F0B7F6C 8C84B3C8 */  lw    $a0, %lo(g_BgPortals)($a0)
/* 0EA960 7F0B7F70 3C078004 */  lui   $a3, %hi(g_BgRoomInfo) # $a3, 0x8004
/* 0EA964 7F0B7F74 24E7AC64 */  addiu $a3, %lo(g_BgRoomInfo) # addiu $a3, $a3, -0x539c
/* 0EA968 7F0B7F78 8C8A0000 */  lw    $t2, ($a0)
/* 0EA96C 7F0B7F7C 24090001 */  li    $t1, 1
/* 0EA970 7F0B7F80 24080050 */  li    $t0, 80
/* 0EA974 7F0B7F84 1140001E */  beqz  $t2, .L7F0B8000
/* 0EA978 7F0B7F88 00801025 */   move  $v0, $a0
/* 0EA97C 7F0B7F8C 90430004 */  lbu   $v1, 4($v0)
.L7F0B7F90:
/* 0EA980 7F0B7F90 90440005 */  lbu   $a0, 5($v0)
/* 0EA984 7F0B7F94 00680019 */  multu $v1, $t0
/* 0EA988 7F0B7F98 00005812 */  mflo  $t3
/* 0EA98C 7F0B7F9C 00EB2821 */  addu  $a1, $a3, $t3
/* 0EA990 7F0B7FA0 90A60000 */  lbu   $a2, ($a1)
/* 0EA994 7F0B7FA4 10C00009 */  beqz  $a2, .L7F0B7FCC
/* 0EA998 7F0B7FA8 00000000 */   nop
/* 0EA99C 7F0B7FAC 00880019 */  multu $a0, $t0
/* 0EA9A0 7F0B7FB0 00006012 */  mflo  $t4
/* 0EA9A4 7F0B7FB4 00EC1821 */  addu  $v1, $a3, $t4
/* 0EA9A8 7F0B7FB8 906D0000 */  lbu   $t5, ($v1)
/* 0EA9AC 7F0B7FBC 15A00003 */  bnez  $t5, .L7F0B7FCC
/* 0EA9B0 7F0B7FC0 00000000 */   nop
/* 0EA9B4 7F0B7FC4 1000000A */  b     .L7F0B7FF0
/* 0EA9B8 7F0B7FC8 A0690001 */   sb    $t1, 1($v1)
.L7F0B7FCC:
/* 0EA9BC 7F0B7FCC 00880019 */  multu $a0, $t0
/* 0EA9C0 7F0B7FD0 00007012 */  mflo  $t6
/* 0EA9C4 7F0B7FD4 00EE7821 */  addu  $t7, $a3, $t6
/* 0EA9C8 7F0B7FD8 91F80000 */  lbu   $t8, ($t7)
/* 0EA9CC 7F0B7FDC 53000005 */  beql  $t8, $zero, .L7F0B7FF4
/* 0EA9D0 7F0B7FE0 8C590008 */   lw    $t9, 8($v0)
/* 0EA9D4 7F0B7FE4 54C00003 */  bnezl $a2, .L7F0B7FF4
/* 0EA9D8 7F0B7FE8 8C590008 */   lw    $t9, 8($v0)
/* 0EA9DC 7F0B7FEC A0A90001 */  sb    $t1, 1($a1)
.L7F0B7FF0:
/* 0EA9E0 7F0B7FF0 8C590008 */  lw    $t9, 8($v0)
.L7F0B7FF4:
/* 0EA9E4 7F0B7FF4 24420008 */  addiu $v0, $v0, 8
/* 0EA9E8 7F0B7FF8 5720FFE5 */  bnezl $t9, .L7F0B7F90
/* 0EA9EC 7F0B7FFC 90430004 */   lbu   $v1, 4($v0)
.L7F0B8000:
/* 0EA9F0 7F0B8000 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA9F4 7F0B8004 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EA9F8 7F0B8008 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EA9FC 7F0B800C 03E00008 */  jr    $ra
/* 0EAA00 7F0B8010 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif

#endif





/**
 * Address 0x7F0B8D78.
*/
Gfx *sub_GAME_7F0B8D78(Gfx *arg0)
{
    s32 i;
    if (levelentry_index == LEVEL_INDEX_DAM)
    {
        for (i=0; i<g_BgNumberOfRoomsDrawn; i++)
        {
            // The lake in dam is a single giant room, id 0x23
            if (dword_CODE_bss_8007FFA0[i].roomid == 0x23)
            {
                // speculation in discord: unk1 is probably draw order or similar,
                // this is a hack to draw the lake first.
                dword_CODE_bss_8007FFA0[i].unk1 = 0;
                break;
            }
        }
    }

    return bgScissorCurrentPlayerViewDefault(sub_GAME_7F0B3C8C(arg0));
}



#ifdef NONMATCHING
void sub_GAME_7F0B8DF4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8DF4
/* 0ED924 7F0B8DF4 3C088008 */  lui   $t0, %hi(g_BgPortals)
/* 0ED928 7F0B8DF8 2508FF80 */  addiu $t0, %lo(g_BgPortals) # addiu $t0, $t0, -0x80
/* 0ED92C 7F0B8DFC 8D070000 */  lw    $a3, ($t0)
/* 0ED930 7F0B8E00 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0ED934 7F0B8E04 AFB1000C */  sw    $s1, 0xc($sp)
/* 0ED938 7F0B8E08 AFB00008 */  sw    $s0, 8($sp)
/* 0ED93C 7F0B8E0C 8CEE0000 */  lw    $t6, ($a3)
/* 0ED940 7F0B8E10 00A08025 */  move  $s0, $a1
/* 0ED944 7F0B8E14 00C08825 */  move  $s1, $a2
/* 0ED948 7F0B8E18 00001825 */  move  $v1, $zero
/* 0ED94C 7F0B8E1C 11C00019 */  beqz  $t6, .L7F0B8E84
/* 0ED950 7F0B8E20 00001025 */   move  $v0, $zero
/* 0ED954 7F0B8E24 00002825 */  move  $a1, $zero
/* 0ED958 7F0B8E28 00E03025 */  move  $a2, $a3
/* 0ED95C 7F0B8E2C 90CF0004 */  lbu   $t7, 4($a2)
.L7F0B8E30:
/* 0ED960 7F0B8E30 0003C880 */  sll   $t9, $v1, 2
/* 0ED964 7F0B8E34 02194821 */  addu  $t1, $s0, $t9
/* 0ED968 7F0B8E38 508F0005 */  beql  $a0, $t7, .L7F0B8E50
/* 0ED96C 7F0B8E3C AD220000 */   sw    $v0, ($t1)
/* 0ED970 7F0B8E40 90D80005 */  lbu   $t8, 5($a2)
/* 0ED974 7F0B8E44 54980004 */  bnel  $a0, $t8, .L7F0B8E58
/* 0ED978 7F0B8E48 0071082A */   slt   $at, $v1, $s1
/* 0ED97C 7F0B8E4C AD220000 */  sw    $v0, ($t1)
.L7F0B8E50:
/* 0ED980 7F0B8E50 24630001 */  addiu $v1, $v1, 1
/* 0ED984 7F0B8E54 0071082A */  slt   $at, $v1, $s1
.L7F0B8E58:
/* 0ED988 7F0B8E58 54200004 */  bnezl $at, .L7F0B8E6C
/* 0ED98C 7F0B8E5C 8D0A0000 */   lw    $t2, ($t0)
/* 0ED990 7F0B8E60 10000009 */  b     .L7F0B8E88
/* 0ED994 7F0B8E64 00601025 */   move  $v0, $v1
/* 0ED998 7F0B8E68 8D0A0000 */  lw    $t2, ($t0)
.L7F0B8E6C:
/* 0ED99C 7F0B8E6C 24A50008 */  addiu $a1, $a1, 8
/* 0ED9A0 7F0B8E70 24420001 */  addiu $v0, $v0, 1
/* 0ED9A4 7F0B8E74 01453021 */  addu  $a2, $t2, $a1
/* 0ED9A8 7F0B8E78 8CCB0000 */  lw    $t3, ($a2)
/* 0ED9AC 7F0B8E7C 5560FFEC */  bnezl $t3, .L7F0B8E30
/* 0ED9B0 7F0B8E80 90CF0004 */   lbu   $t7, 4($a2)
.L7F0B8E84:
/* 0ED9B4 7F0B8E84 00601025 */  move  $v0, $v1
.L7F0B8E88:
/* 0ED9B8 7F0B8E88 8FB00008 */  lw    $s0, 8($sp)
/* 0ED9BC 7F0B8E8C 8FB1000C */  lw    $s1, 0xc($sp)
/* 0ED9C0 7F0B8E90 03E00008 */  jr    $ra
/* 0ED9C4 7F0B8E94 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0B8E98(s32 arg0, s32 arg1) {
    s32 temp_v1;
    void *temp_v0;
    s32 temp_at;
    void *phi_a2;
    void *phi_v0;
    s32 phi_v1;
    s32 phi_v1_2;

    // Node 0
    phi_v1_2 = 0;
    if (num_visible_rooms_in_cur_global_vis_packet > 0)
    {
        // Node 1
        phi_v1_2 = 0;
        if (arg1 > 0)
        {
            // Node 2
            phi_a2 = (0 + &list_visible_rooms_in_cur_global_vis_packet);
            phi_v0 = (arg0 + (0 * 4));
            phi_v1 = 0;
loop_3:
            // Node 3
            temp_v1 = (phi_v1 + 1);
            temp_v0 = (phi_v0 + 4);
            temp_v0->unk-4 = (?32) *phi_a2;
            temp_at = (temp_v1 < arg1);
            phi_v1_2 = temp_v1;
            if (temp_at != 0)
            {
                // Node 4
                phi_a2 = (phi_a2 + 1);
                phi_v0 = temp_v0;
                phi_v1 = temp_v1;
                phi_v1_2 = temp_v1;
                if (temp_at != 0)
                {
                    goto loop_3;
                }
            }
        }
    }
    // Node 5
    return phi_v1_2;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8E98
/* 0ED9C8 7F0B8E98 3C078008 */  lui   $a3, %hi(num_visible_rooms_in_cur_global_vis_packet)
/* 0ED9CC 7F0B8E9C 24E7C038 */  addiu $a3, %lo(num_visible_rooms_in_cur_global_vis_packet) # addiu $a3, $a3, -0x3fc8
/* 0ED9D0 7F0B8EA0 8CEE0000 */  lw    $t6, ($a3)
/* 0ED9D4 7F0B8EA4 00001825 */  move  $v1, $zero
/* 0ED9D8 7F0B8EA8 19C00012 */  blez  $t6, .L7F0B8EF4
/* 0ED9DC 7F0B8EAC 00000000 */   nop
/* 0ED9E0 7F0B8EB0 18A00010 */  blez  $a1, .L7F0B8EF4
/* 0ED9E4 7F0B8EB4 00007880 */   sll   $t7, $zero, 2
/* 0ED9E8 7F0B8EB8 3C188008 */  lui   $t8, %hi(list_visible_rooms_in_cur_global_vis_packet)
/* 0ED9EC 7F0B8EBC 2718BFA0 */  addiu $t8, %lo(list_visible_rooms_in_cur_global_vis_packet) # addiu $t8, $t8, -0x4060
/* 0ED9F0 7F0B8EC0 00183021 */  addu  $a2, $zero, $t8
/* 0ED9F4 7F0B8EC4 008F1021 */  addu  $v0, $a0, $t7
/* 0ED9F8 7F0B8EC8 90D90000 */  lbu   $t9, ($a2)
.L7F0B8ECC:
/* 0ED9FC 7F0B8ECC 24630001 */  addiu $v1, $v1, 1
/* 0EDA00 7F0B8ED0 24420004 */  addiu $v0, $v0, 4
/* 0EDA04 7F0B8ED4 AC59FFFC */  sw    $t9, -4($v0)
/* 0EDA08 7F0B8ED8 8CE80000 */  lw    $t0, ($a3)
/* 0EDA0C 7F0B8EDC 24C60001 */  addiu $a2, $a2, 1
/* 0EDA10 7F0B8EE0 0068082A */  slt   $at, $v1, $t0
/* 0EDA14 7F0B8EE4 10200003 */  beqz  $at, .L7F0B8EF4
/* 0EDA18 7F0B8EE8 0065082A */   slt   $at, $v1, $a1
/* 0EDA1C 7F0B8EEC 5420FFF7 */  bnezl $at, .L7F0B8ECC
/* 0EDA20 7F0B8EF0 90D90000 */   lbu   $t9, ($a2)
.L7F0B8EF4:
/* 0EDA24 7F0B8EF4 03E00008 */  jr    $ra
/* 0EDA28 7F0B8EF8 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B8EFC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8EFC
/* 0EDA2C 7F0B8EFC 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0EDA30 7F0B8F00 3C078008 */  lui   $a3, %hi(g_BgPortals)
/* 0EDA34 7F0B8F04 8CE7FF80 */  lw    $a3, %lo(g_BgPortals)($a3)
/* 0EDA38 7F0B8F08 AFB2000C */  sw    $s2, 0xc($sp)
/* 0EDA3C 7F0B8F0C AFB10008 */  sw    $s1, 8($sp)
/* 0EDA40 7F0B8F10 AFB00004 */  sw    $s0, 4($sp)
/* 0EDA44 7F0B8F14 8CEE0000 */  lw    $t6, ($a3)
/* 0EDA48 7F0B8F18 00808025 */  move  $s0, $a0
/* 0EDA4C 7F0B8F1C 00A08825 */  move  $s1, $a1
/* 0EDA50 7F0B8F20 00C09025 */  move  $s2, $a2
/* 0EDA54 7F0B8F24 11C00024 */  beqz  $t6, .L7F0B8FB8
/* 0EDA58 7F0B8F28 00001825 */   move  $v1, $zero
/* 0EDA5C 7F0B8F2C 00002025 */  move  $a0, $zero
/* 0EDA60 7F0B8F30 00E02825 */  move  $a1, $a3
/* 0EDA64 7F0B8F34 90A20004 */  lbu   $v0, 4($a1)
.L7F0B8F38:
/* 0EDA68 7F0B8F38 90A60005 */  lbu   $a2, 5($a1)
/* 0EDA6C 7F0B8F3C 14500003 */  bne   $v0, $s0, .L7F0B8F4C
/* 0EDA70 7F0B8F40 00000000 */   nop
/* 0EDA74 7F0B8F44 00C01025 */  move  $v0, $a2
/* 0EDA78 7F0B8F48 02003025 */  move  $a2, $s0
.L7F0B8F4C:
/* 0EDA7C 7F0B8F4C 54D00016 */  bnel  $a2, $s0, .L7F0B8FA8
/* 0EDA80 7F0B8F50 8CA90008 */   lw    $t1, 8($a1)
/* 0EDA84 7F0B8F54 18600008 */  blez  $v1, .L7F0B8F78
/* 0EDA88 7F0B8F58 00003025 */   move  $a2, $zero
/* 0EDA8C 7F0B8F5C 02203825 */  move  $a3, $s1
.L7F0B8F60:
/* 0EDA90 7F0B8F60 8CEF0000 */  lw    $t7, ($a3)
/* 0EDA94 7F0B8F64 24C60001 */  addiu $a2, $a2, 1
/* 0EDA98 7F0B8F68 504F000F */  beql  $v0, $t7, .L7F0B8FA8
/* 0EDA9C 7F0B8F6C 8CA90008 */   lw    $t1, 8($a1)
/* 0EDAA0 7F0B8F70 14C3FFFB */  bne   $a2, $v1, .L7F0B8F60
/* 0EDAA4 7F0B8F74 24E70004 */   addiu $a3, $a3, 4
.L7F0B8F78:
/* 0EDAA8 7F0B8F78 0003C080 */  sll   $t8, $v1, 2
/* 0EDAAC 7F0B8F7C 24630001 */  addiu $v1, $v1, 1
/* 0EDAB0 7F0B8F80 0238C821 */  addu  $t9, $s1, $t8
/* 0EDAB4 7F0B8F84 0072082A */  slt   $at, $v1, $s2
/* 0EDAB8 7F0B8F88 14200003 */  bnez  $at, .L7F0B8F98
/* 0EDABC 7F0B8F8C AF220000 */   sw    $v0, ($t9)
/* 0EDAC0 7F0B8F90 1000000A */  b     .L7F0B8FBC
/* 0EDAC4 7F0B8F94 00601025 */   move  $v0, $v1
.L7F0B8F98:
/* 0EDAC8 7F0B8F98 3C088008 */  lui   $t0, %hi(g_BgPortals)
/* 0EDACC 7F0B8F9C 8D08FF80 */  lw    $t0, %lo(g_BgPortals)($t0)
/* 0EDAD0 7F0B8FA0 01042821 */  addu  $a1, $t0, $a0
/* 0EDAD4 7F0B8FA4 8CA90008 */  lw    $t1, 8($a1)
.L7F0B8FA8:
/* 0EDAD8 7F0B8FA8 24840008 */  addiu $a0, $a0, 8
/* 0EDADC 7F0B8FAC 24A50008 */  addiu $a1, $a1, 8
/* 0EDAE0 7F0B8FB0 5520FFE1 */  bnezl $t1, .L7F0B8F38
/* 0EDAE4 7F0B8FB4 90A20004 */   lbu   $v0, 4($a1)
.L7F0B8FB8:
/* 0EDAE8 7F0B8FB8 00601025 */  move  $v0, $v1
.L7F0B8FBC:
/* 0EDAEC 7F0B8FBC 8FB00004 */  lw    $s0, 4($sp)
/* 0EDAF0 7F0B8FC0 8FB10008 */  lw    $s1, 8($sp)
/* 0EDAF4 7F0B8FC4 8FB2000C */  lw    $s2, 0xc($sp)
/* 0EDAF8 7F0B8FC8 03E00008 */  jr    $ra
/* 0EDAFC 7F0B8FCC 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B8FD0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    void *phi_a0;

    // Node 0
    phi_a0 = g_BgPortals;
    if (*g_BgPortals != 0)
    {
loop_1:
        // Node 1
        temp_v0 = phi_a0->unk4;
        temp_v1 = phi_a0->unk5;
        if (temp_v0 == arg0)
        {
            // Node 2
            if (temp_v1 == arg1)
            {
                // Node 3
                return 1;
            }
        }
        // Node 4
        if (temp_v1 == arg0)
        {
            // Node 5
            if (temp_v0 == arg1)
            {
                // Node 6
                return 1;
            }
        }
        // Node 7
        phi_a0 = (phi_a0 + 8);
        if (phi_a0->unk8 != 0)
        {
            goto loop_1;
        }
    }
    // Node 8
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B8FD0
/* 0EDB00 7F0B8FD0 3C038008 */  lui   $v1, %hi(g_BgPortals)
/* 0EDB04 7F0B8FD4 8C63FF80 */  lw    $v1, %lo(g_BgPortals)($v1)
/* 0EDB08 7F0B8FD8 00803025 */  move  $a2, $a0
/* 0EDB0C 7F0B8FDC 8C6E0000 */  lw    $t6, ($v1)
/* 0EDB10 7F0B8FE0 00602025 */  move  $a0, $v1
/* 0EDB14 7F0B8FE4 51C00014 */  beql  $t6, $zero, .L7F0B9038
/* 0EDB18 7F0B8FE8 00001025 */   move  $v0, $zero
/* 0EDB1C 7F0B8FEC 90820004 */  lbu   $v0, 4($a0)
.L7F0B8FF0:
/* 0EDB20 7F0B8FF0 90830005 */  lbu   $v1, 5($a0)
/* 0EDB24 7F0B8FF4 14460005 */  bne   $v0, $a2, .L7F0B900C
/* 0EDB28 7F0B8FF8 00000000 */   nop
/* 0EDB2C 7F0B8FFC 14650003 */  bne   $v1, $a1, .L7F0B900C
/* 0EDB30 7F0B9000 00000000 */   nop
/* 0EDB34 7F0B9004 03E00008 */  jr    $ra
/* 0EDB38 7F0B9008 24020001 */   li    $v0, 1

.L7F0B900C:
/* 0EDB3C 7F0B900C 54660006 */  bnel  $v1, $a2, .L7F0B9028
/* 0EDB40 7F0B9010 8C8F0008 */   lw    $t7, 8($a0)
/* 0EDB44 7F0B9014 54450004 */  bnel  $v0, $a1, .L7F0B9028
/* 0EDB48 7F0B9018 8C8F0008 */   lw    $t7, 8($a0)
/* 0EDB4C 7F0B901C 03E00008 */  jr    $ra
/* 0EDB50 7F0B9020 24020001 */   li    $v0, 1

/* 0EDB54 7F0B9024 8C8F0008 */  lw    $t7, 8($a0)
.L7F0B9028:
/* 0EDB58 7F0B9028 24840008 */  addiu $a0, $a0, 8
/* 0EDB5C 7F0B902C 55E0FFF0 */  bnezl $t7, .L7F0B8FF0
/* 0EDB60 7F0B9030 90820004 */   lbu   $v0, 4($a0)
/* 0EDB64 7F0B9034 00001025 */  move  $v0, $zero
.L7F0B9038:
/* 0EDB68 7F0B9038 03E00008 */  jr    $ra
/* 0EDB6C 7F0B903C 00000000 */   nop
)
#endif





/**
 * Unreferenced.
 *
 * Adjusts value in bgViewRelated and returns the new value.
 *
 * @param index: index into bgViewRelated.
 * @param times: multiples value by this amount first.
 * @param add: then adds this.
 *
 * Address 0x7F0B9040.
 */
f32 bgTimesAddViewRelatedMaybe(s32 index, f32 times, f32 add)
{
    bgViewRelated[index] = (s32) (((f32) bgViewRelated[index] * times) + add);
    return (f32) bgViewRelated[index];
}





/**
 * Address 0x7F0B908C.
 */
void bgUpdateCurrentPlayerScreenMinMax(void)
{
    f32 fx;
    f32 fwidth;
    f32 fy;
    f32 fheight;

    fx = (f32) bgViewRelated[0];
    fy = (f32) bgViewRelated[1];
    fwidth = (f32) viGetX() + (f32) bgViewRelated[2];
    fheight = (f32) viGetY() + (f32) bgViewRelated[3];

    g_CurrentPlayer->screenxminf = (f32) viGetViewLeft();

    if (g_CurrentPlayer->screenxminf < fx)
    {
        g_CurrentPlayer->screenxminf = fx;
    }

    if (fwidth < g_CurrentPlayer->screenxminf)
    {
        g_CurrentPlayer->screenxminf = fwidth;
    }

    g_CurrentPlayer->screenyminf = (f32) viGetViewTop();

    if (g_CurrentPlayer->screenyminf < fy)
    {
        g_CurrentPlayer->screenyminf = fy;
    }

    if (fheight < g_CurrentPlayer->screenyminf)
    {
        g_CurrentPlayer->screenyminf = fheight;
    }

    g_CurrentPlayer->screenxmaxf = (f32) (viGetViewLeft() + viGetViewWidth());

    if (g_CurrentPlayer->screenxmaxf < fx)
    {
        g_CurrentPlayer->screenxmaxf = fx;
    }

    if (fwidth < g_CurrentPlayer->screenxmaxf)
    {
        g_CurrentPlayer->screenxmaxf = fwidth;
    }

    g_CurrentPlayer->screenymaxf = (f32) (viGetViewTop() + viGetViewHeight());

    if (g_CurrentPlayer->screenymaxf < fy)
    {
        g_CurrentPlayer->screenymaxf = fy;
    }

    if (fheight < g_CurrentPlayer->screenymaxf)
    {
        g_CurrentPlayer->screenymaxf = fheight;
    }
}





#ifdef NONMATCHING
s32 sub_GAME_7F0B92B4(s32 arg0, void *arg1)
{
    void *temp_a2;
    s32 temp_v0;
    f32 temp_f18;
    void *temp_a2_2;
    s32 temp_v0_2;
    void *temp_v1;
    f32 temp_f18_2;
    f32 phi_f18;
    void *phi_v1;
    s32 phi_v0;
    f32 phi_f18_2;
    void *phi_v1_2;
    void *phi_a2;

    //try this, its just a guess but its only a loop of 3 and I think its unrolled
    for (i = 0; i < 3; i++)
    {
        arg1[i]->room_id = arg0[i]->roomid + arg0[i]->next->roomid/2;
    }
    // Node 0

    temp_a2 = ((arg0 * 0x50) + &g_BgRoomInfo);
    temp_v0 = (0 + 1);
    temp_f18 = ((temp_a2->unk44 + temp_a2->unk38) * 0.5f);
    phi_f18 = temp_f18;
    phi_v1 = arg1;
    phi_v0 = temp_v0;
    phi_f18_2 = temp_f18;
    phi_v1_2 = arg1;
    phi_a2 = temp_a2;
    if (temp_v0 != 3)
    {
loop_1:
        // Node 1
        *phi_v1 = (f32) phi_f18;
        temp_a2_2 = (phi_a2 + 4);
        temp_v0_2 = (phi_v0 + 1);
        temp_v1 = (phi_v1 + 4);
        temp_f18_2 = ((phi_a2->unk48 + temp_a2_2->unk38) * 0.5f);
        phi_f18 = temp_f18_2;
        phi_v1 = temp_v1;
        phi_v0 = temp_v0_2;
        phi_f18_2 = temp_f18_2;
        phi_v1_2 = temp_v1;
        phi_a2 = temp_a2_2;
        if (temp_v0_2 != 3)
        {
            goto loop_1;
        }
    }
    // Node 2
    (phi_v1_2 + 4)->unk-4 = (f32) phi_f18_2;
    return temp_v0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B92B4
/* 0EDDE4 7F0B92B4 00047080 */  sll   $t6, $a0, 2
/* 0EDDE8 7F0B92B8 01C47021 */  addu  $t6, $t6, $a0
/* 0EDDEC 7F0B92BC 3C0F8004 */  lui   $t7, %hi(g_BgRoomInfo)
/* 0EDDF0 7F0B92C0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0EDDF4 7F0B92C4 25EF1414 */  addiu $t7, %lo(g_BgRoomInfo) # addiu $t7, $t7, 0x1414
/* 0EDDF8 7F0B92C8 000E7100 */  sll   $t6, $t6, 4
/* 0EDDFC 7F0B92CC 44810000 */  mtc1  $at, $f0
/* 0EDE00 7F0B92D0 01CF3021 */  addu  $a2, $t6, $t7
/* 0EDE04 7F0B92D4 24040003 */  li    $a0, 3
/* 0EDE08 7F0B92D8 00001025 */  move  $v0, $zero
/* 0EDE0C 7F0B92DC 00A01825 */  move  $v1, $a1
/* 0EDE10 7F0B92E0 C4D00044 */  lwc1  $f16, 0x44($a2)
/* 0EDE14 7F0B92E4 C4CE0038 */  lwc1  $f14, 0x38($a2)
/* 0EDE18 7F0B92E8 24420001 */  addiu $v0, $v0, 1
/* 0EDE1C 7F0B92EC 460E8380 */  add.s $f14, $f16, $f14
/* 0EDE20 7F0B92F0 46007482 */  mul.s $f18, $f14, $f0
/* 0EDE24 7F0B92F4 5044000C */  beql  $v0, $a0, .L7F0B9328
/* 0EDE28 7F0B92F8 24C60004 */   addiu $a2, $a2, 4
/* 0EDE2C 7F0B92FC E4720000 */  swc1  $f18, ($v1)
.L7F0B9300:
/* 0EDE30 7F0B9300 C4D00048 */  lwc1  $f16, 0x48($a2)
/* 0EDE34 7F0B9304 24C60004 */  addiu $a2, $a2, 4
/* 0EDE38 7F0B9308 C4CE0038 */  lwc1  $f14, 0x38($a2)
/* 0EDE3C 7F0B930C 24420001 */  addiu $v0, $v0, 1
/* 0EDE40 7F0B9310 24630004 */  addiu $v1, $v1, 4
/* 0EDE44 7F0B9314 460E8380 */  add.s $f14, $f16, $f14
/* 0EDE48 7F0B9318 46007482 */  mul.s $f18, $f14, $f0
/* 0EDE4C 7F0B931C 5444FFF8 */  bnel  $v0, $a0, .L7F0B9300
/* 0EDE50 7F0B9320 E4720000 */   swc1  $f18, ($v1)
/* 0EDE54 7F0B9324 24C60004 */  addiu $a2, $a2, 4
.L7F0B9328:
/* 0EDE58 7F0B9328 24630004 */  addiu $v1, $v1, 4
/* 0EDE5C 7F0B932C E472FFFC */  swc1  $f18, -4($v1)
/* 0EDE60 7F0B9330 03E00008 */  jr    $ra
/* 0EDE64 7F0B9334 00000000 */   nop
)
#endif





#ifdef NONMATCHING
//bgRoomCalcBB
void sub_GAME_7F0B9338(int room) {
    if ((room < dword_CODE_bss_8007B9DC) && (firststaninroom[room] != NULL))
    #ifdef DEBUG
        else
    {
          osSyncPrintf("bg: bgRoomCalcBB: ROOM%d has no gfx, and no stans! Can\'t make bb & roomoffset ", room);
          }
    #endif
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9338
/* 0EDE68 7F0B9338 3C088008 */  lui   $t0, %hi(ptr_bgdata_room_fileposition_list)
/* 0EDE6C 7F0B933C 2508FF8C */  addiu $t0, %lo(ptr_bgdata_room_fileposition_list) # addiu $t0, $t0, -0x74
/* 0EDE70 7F0B9340 8D0E0000 */  lw    $t6, ($t0)
/* 0EDE74 7F0B9344 00041080 */  sll   $v0, $a0, 2
/* 0EDE78 7F0B9348 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0EDE7C 7F0B934C 00441023 */  subu  $v0, $v0, $a0
/* 0EDE80 7F0B9350 000210C0 */  sll   $v0, $v0, 3
/* 0EDE84 7F0B9354 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EDE88 7F0B9358 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EDE8C 7F0B935C 01C24821 */  addu  $t1, $t6, $v0
/* 0EDE90 7F0B9360 8D2F0000 */  lw    $t7, ($t1)
/* 0EDE94 7F0B9364 3C188004 */  lui   $t8, %hi(g_BgRoomInfo)
/* 0EDE98 7F0B9368 00808025 */  move  $s0, $a0
/* 0EDE9C 7F0B936C 15E00035 */  bnez  $t7, .L7F0B9444
/* 0EDEA0 7F0B9370 27181414 */   addiu $t8, %lo(g_BgRoomInfo) # addiu $t8, $t8, 0x1414
/* 0EDEA4 7F0B9374 3C188008 */  lui   $t8, %hi(dword_CODE_bss_8007B9DC)
/* 0EDEA8 7F0B9378 8F18B9DC */  lw    $t8, %lo(dword_CODE_bss_8007B9DC)($t8)
/* 0EDEAC 7F0B937C 0004C880 */  sll   $t9, $a0, 2
/* 0EDEB0 7F0B9380 3C0B8008 */  lui   $t3, %hi(firststaninroom)
/* 0EDEB4 7F0B9384 0098082A */  slt   $at, $a0, $t8
/* 0EDEB8 7F0B9388 1020008E */  beqz  $at, .L7F0B95C4
/* 0EDEBC 7F0B938C 01795821 */   addu  $t3, $t3, $t9
/* 0EDEC0 7F0B9390 8D6BB128 */  lw    $t3, %lo(firststaninroom)($t3)
/* 0EDEC4 7F0B9394 00106080 */  sll   $t4, $s0, 2
/* 0EDEC8 7F0B9398 01906021 */  addu  $t4, $t4, $s0
/* 0EDECC 7F0B939C 11600089 */  beqz  $t3, .L7F0B95C4
/* 0EDED0 7F0B93A0 00002025 */   move  $a0, $zero
/* 0EDED4 7F0B93A4 00107080 */  sll   $t6, $s0, 2
/* 0EDED8 7F0B93A8 01D07023 */  subu  $t6, $t6, $s0
/* 0EDEDC 7F0B93AC 3C0D8004 */  lui   $t5, %hi(g_BgRoomInfo)
/* 0EDEE0 7F0B93B0 3C0F8008 */  lui   $t7, %hi(dword_CODE_bss_8007B358)
/* 0EDEE4 7F0B93B4 25EFB358 */  addiu $t7, %lo(dword_CODE_bss_8007B358) # addiu $t7, $t7, -0x4ca8
/* 0EDEE8 7F0B93B8 25AD1414 */  addiu $t5, %lo(g_BgRoomInfo) # addiu $t5, $t5, 0x1414
/* 0EDEEC 7F0B93BC 000E7080 */  sll   $t6, $t6, 2
/* 0EDEF0 7F0B93C0 000C6100 */  sll   $t4, $t4, 4
/* 0EDEF4 7F0B93C4 018D2821 */  addu  $a1, $t4, $t5
/* 0EDEF8 7F0B93C8 01CF3021 */  addu  $a2, $t6, $t7
/* 0EDEFC 7F0B93CC 2407000C */  li    $a3, 12
.L7F0B93D0:
/* 0EDF00 7F0B93D0 84C20000 */  lh    $v0, ($a2)
/* 0EDF04 7F0B93D4 84C30006 */  lh    $v1, 6($a2)
/* 0EDF08 7F0B93D8 8D0B0000 */  lw    $t3, ($t0)
/* 0EDF0C 7F0B93DC 44822000 */  mtc1  $v0, $f4
/* 0EDF10 7F0B93E0 44834000 */  mtc1  $v1, $f8
/* 0EDF14 7F0B93E4 0062C021 */  addu  $t8, $v1, $v0
/* 0EDF18 7F0B93E8 468021A0 */  cvt.s.w $f6, $f4
/* 0EDF1C 7F0B93EC 00106080 */  sll   $t4, $s0, 2
/* 0EDF20 7F0B93F0 01906023 */  subu  $t4, $t4, $s0
/* 0EDF24 7F0B93F4 000C60C0 */  sll   $t4, $t4, 3
/* 0EDF28 7F0B93F8 016C6821 */  addu  $t5, $t3, $t4
/* 0EDF2C 7F0B93FC 468042A0 */  cvt.s.w $f10, $f8
/* 0EDF30 7F0B9400 01A47021 */  addu  $t6, $t5, $a0
/* 0EDF34 7F0B9404 24840004 */  addiu $a0, $a0, 4
/* 0EDF38 7F0B9408 E4A60038 */  swc1  $f6, 0x38($a1)
/* 0EDF3C 7F0B940C 24A50004 */  addiu $a1, $a1, 4
/* 0EDF40 7F0B9410 24C60002 */  addiu $a2, $a2, 2
/* 0EDF44 7F0B9414 E4AA0040 */  swc1  $f10, 0x40($a1)
/* 0EDF48 7F0B9418 07010003 */  bgez  $t8, .L7F0B9428
/* 0EDF4C 7F0B941C 0018C843 */   sra   $t9, $t8, 1
/* 0EDF50 7F0B9420 27010001 */  addiu $at, $t8, 1
/* 0EDF54 7F0B9424 0001C843 */  sra   $t9, $at, 1
.L7F0B9428:
/* 0EDF58 7F0B9428 44998000 */  mtc1  $t9, $f16
/* 0EDF5C 7F0B942C 00000000 */  nop
/* 0EDF60 7F0B9430 468084A0 */  cvt.s.w $f18, $f16
/* 0EDF64 7F0B9434 1487FFE6 */  bne   $a0, $a3, .L7F0B93D0
/* 0EDF68 7F0B9438 E5D2000C */   swc1  $f18, 0xc($t6)
/* 0EDF6C 7F0B943C 10000062 */  b     .L7F0B95C8
/* 0EDF70 7F0B9440 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0B9444:
/* 0EDF74 7F0B9444 00107880 */  sll   $t7, $s0, 2
/* 0EDF78 7F0B9448 01F07821 */  addu  $t7, $t7, $s0
/* 0EDF7C 7F0B944C 000F7900 */  sll   $t7, $t7, 4
/* 0EDF80 7F0B9450 01F84021 */  addu  $t0, $t7, $t8
/* 0EDF84 7F0B9454 910A0002 */  lbu   $t2, 2($t0)
/* 0EDF88 7F0B9458 02002025 */  move  $a0, $s0
/* 0EDF8C 7F0B945C 5540000C */  bnezl $t2, .L7F0B9490
/* 0EDF90 7F0B9460 8D060004 */   lw    $a2, 4($t0)
/* 0EDF94 7F0B9464 AFA20030 */  sw    $v0, 0x30($sp)
/* 0EDF98 7F0B9468 AFA80028 */  sw    $t0, 0x28($sp)
/* 0EDF9C 7F0B946C 0FC2D8DA */  jal   sub_GAME_7F0B6368
/* 0EDFA0 7F0B9470 A3AA0037 */   sb    $t2, 0x37($sp)
/* 0EDFA4 7F0B9474 3C198008 */  lui   $t9, %hi(ptr_bgdata_room_fileposition_list)
/* 0EDFA8 7F0B9478 8F39FF8C */  lw    $t9, %lo(ptr_bgdata_room_fileposition_list)($t9)
/* 0EDFAC 7F0B947C 8FA20030 */  lw    $v0, 0x30($sp)
/* 0EDFB0 7F0B9480 8FA80028 */  lw    $t0, 0x28($sp)
/* 0EDFB4 7F0B9484 93AA0037 */  lbu   $t2, 0x37($sp)
/* 0EDFB8 7F0B9488 03224821 */  addu  $t1, $t9, $v0
/* 0EDFBC 7F0B948C 8D060004 */  lw    $a2, 4($t0)
.L7F0B9490:
/* 0EDFC0 7F0B9490 8D19001C */  lw    $t9, 0x1c($t0)
/* 0EDFC4 7F0B9494 240B7FFF */  li    $t3, 32767
/* 0EDFC8 7F0B9498 240C7FFF */  li    $t4, 32767
/* 0EDFCC 7F0B949C 03263821 */  addu  $a3, $t9, $a2
/* 0EDFD0 7F0B94A0 240D7FFF */  li    $t5, 32767
/* 0EDFD4 7F0B94A4 240E8001 */  li    $t6, -32767
/* 0EDFD8 7F0B94A8 240F8001 */  li    $t7, -32767
/* 0EDFDC 7F0B94AC 24188001 */  li    $t8, -32767
/* 0EDFE0 7F0B94B0 00C7082B */  sltu  $at, $a2, $a3
/* 0EDFE4 7F0B94B4 A7AB0038 */  sh    $t3, 0x38($sp)
/* 0EDFE8 7F0B94B8 A7AC003A */  sh    $t4, 0x3a($sp)
/* 0EDFEC 7F0B94BC A7AD003C */  sh    $t5, 0x3c($sp)
/* 0EDFF0 7F0B94C0 A7AE003E */  sh    $t6, 0x3e($sp)
/* 0EDFF4 7F0B94C4 A7AF0040 */  sh    $t7, 0x40($sp)
/* 0EDFF8 7F0B94C8 10200017 */  beqz  $at, .L7F0B9528
/* 0EDFFC 7F0B94CC A7B80042 */   sh    $t8, 0x42($sp)
/* 0EE000 7F0B94D0 27A5003E */  addiu $a1, $sp, 0x3e
/* 0EE004 7F0B94D4 00C02025 */  move  $a0, $a2
.L7F0B94D8:
/* 0EE008 7F0B94D8 27A30038 */  addiu $v1, $sp, 0x38
.L7F0B94DC:
/* 0EE00C 7F0B94DC 84820000 */  lh    $v0, ($a0)
/* 0EE010 7F0B94E0 846B0000 */  lh    $t3, ($v1)
/* 0EE014 7F0B94E4 004B082A */  slt   $at, $v0, $t3
/* 0EE018 7F0B94E8 50200004 */  beql  $at, $zero, .L7F0B94FC
/* 0EE01C 7F0B94EC 846C0006 */   lh    $t4, 6($v1)
/* 0EE020 7F0B94F0 A4620000 */  sh    $v0, ($v1)
/* 0EE024 7F0B94F4 84820000 */  lh    $v0, ($a0)
/* 0EE028 7F0B94F8 846C0006 */  lh    $t4, 6($v1)
.L7F0B94FC:
/* 0EE02C 7F0B94FC 0182082A */  slt   $at, $t4, $v0
/* 0EE030 7F0B9500 50200003 */  beql  $at, $zero, .L7F0B9510
/* 0EE034 7F0B9504 24630002 */   addiu $v1, $v1, 2
/* 0EE038 7F0B9508 A4620006 */  sh    $v0, 6($v1)
/* 0EE03C 7F0B950C 24630002 */  addiu $v1, $v1, 2
.L7F0B9510:
/* 0EE040 7F0B9510 1465FFF2 */  bne   $v1, $a1, .L7F0B94DC
/* 0EE044 7F0B9514 24840002 */   addiu $a0, $a0, 2
/* 0EE048 7F0B9518 24C60010 */  addiu $a2, $a2, 0x10
/* 0EE04C 7F0B951C 00C7082B */  sltu  $at, $a2, $a3
/* 0EE050 7F0B9520 5420FFED */  bnezl $at, .L7F0B94D8
/* 0EE054 7F0B9524 00C02025 */   move  $a0, $a2
.L7F0B9528:
/* 0EE058 7F0B9528 87AD0038 */  lh    $t5, 0x38($sp)
/* 0EE05C 7F0B952C 87AE003A */  lh    $t6, 0x3a($sp)
/* 0EE060 7F0B9530 C524000C */  lwc1  $f4, 0xc($t1)
/* 0EE064 7F0B9534 448D3000 */  mtc1  $t5, $f6
/* 0EE068 7F0B9538 448E9000 */  mtc1  $t6, $f18
/* 0EE06C 7F0B953C 87AF003C */  lh    $t7, 0x3c($sp)
/* 0EE070 7F0B9540 46803220 */  cvt.s.w $f8, $f6
/* 0EE074 7F0B9544 87B8003E */  lh    $t8, 0x3e($sp)
/* 0EE078 7F0B9548 87B90040 */  lh    $t9, 0x40($sp)
/* 0EE07C 7F0B954C 87AB0042 */  lh    $t3, 0x42($sp)
/* 0EE080 7F0B9550 468091A0 */  cvt.s.w $f6, $f18
/* 0EE084 7F0B9554 46082280 */  add.s $f10, $f4, $f8
/* 0EE088 7F0B9558 E50A0038 */  swc1  $f10, 0x38($t0)
/* 0EE08C 7F0B955C C5300010 */  lwc1  $f16, 0x10($t1)
/* 0EE090 7F0B9560 448F5000 */  mtc1  $t7, $f10
/* 0EE094 7F0B9564 46068100 */  add.s $f4, $f16, $f6
/* 0EE098 7F0B9568 468054A0 */  cvt.s.w $f18, $f10
/* 0EE09C 7F0B956C E504003C */  swc1  $f4, 0x3c($t0)
/* 0EE0A0 7F0B9570 C5280014 */  lwc1  $f8, 0x14($t1)
/* 0EE0A4 7F0B9574 44982000 */  mtc1  $t8, $f4
/* 0EE0A8 7F0B9578 46124400 */  add.s $f16, $f8, $f18
/* 0EE0AC 7F0B957C 468022A0 */  cvt.s.w $f10, $f4
/* 0EE0B0 7F0B9580 E5100040 */  swc1  $f16, 0x40($t0)
/* 0EE0B4 7F0B9584 C526000C */  lwc1  $f6, 0xc($t1)
/* 0EE0B8 7F0B9588 44998000 */  mtc1  $t9, $f16
/* 0EE0BC 7F0B958C 460A3200 */  add.s $f8, $f6, $f10
/* 0EE0C0 7F0B9590 46808120 */  cvt.s.w $f4, $f16
/* 0EE0C4 7F0B9594 E5080044 */  swc1  $f8, 0x44($t0)
/* 0EE0C8 7F0B9598 C5320010 */  lwc1  $f18, 0x10($t1)
/* 0EE0CC 7F0B959C 448B4000 */  mtc1  $t3, $f8
/* 0EE0D0 7F0B95A0 46049180 */  add.s $f6, $f18, $f4
/* 0EE0D4 7F0B95A4 46804420 */  cvt.s.w $f16, $f8
/* 0EE0D8 7F0B95A8 E5060048 */  swc1  $f6, 0x48($t0)
/* 0EE0DC 7F0B95AC C52A0014 */  lwc1  $f10, 0x14($t1)
/* 0EE0E0 7F0B95B0 46105480 */  add.s $f18, $f10, $f16
/* 0EE0E4 7F0B95B4 15400003 */  bnez  $t2, .L7F0B95C4
/* 0EE0E8 7F0B95B8 E512004C */   swc1  $f18, 0x4c($t0)
/* 0EE0EC 7F0B95BC 0FC2D971 */  jal   delete_room_data
/* 0EE0F0 7F0B95C0 02002025 */   move  $a0, $s0
.L7F0B95C4:
/* 0EE0F4 7F0B95C4 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0B95C8:
/* 0EE0F8 7F0B95C8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EE0FC 7F0B95CC 27BD0050 */  addiu $sp, $sp, 0x50
/* 0EE100 7F0B95D0 03E00008 */  jr    $ra
/* 0EE104 7F0B95D4 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B95D8(s32 arg0) {
    void *temp_a2;
    void *temp_t8;
    s32 temp_t0;
    void *temp_a2_2;
    s32 temp_a1;
    void *phi_v1;
    void *phi_a2;
    s32 phi_a1;
    s32 phi_t0;
    void *phi_t2;

    // Node 0
    phi_v1 = g_BgPortals;
    if (*g_BgPortals != 0)
    {
loop_1:
        // Node 1
        if ((arg0 == phi_v1->unk4) || (arg0 == phi_v1->unk5))
        {
            // Node 3
            temp_a2 = *phi_v1;
            if (*temp_a2 > 0)
            {
                // Node 4
                phi_a1 = 0;
                phi_a2 = temp_a2;
loop_5:
                // Node 5
                phi_t0 = 0;
                phi_t2 = ((arg0 * 0x50) + &g_BgRoomInfo);
loop_6:
                // Node 6
                temp_t8 = ((phi_a2 + (((phi_a1 * 4) - phi_a1) * 4)) + phi_t0);
                temp_t0 = (phi_t0 + 4);
                if (temp_t8->unk4 < phi_t2->unk38)
                {
                    // Node 7
                    phi_t2->unk38 = (f32) temp_t8->unk4;
                }
                // Node 8
                if (phi_t2->unk44 < temp_t8->unk4)
                {
                    // Node 9
                    phi_t2->unk44 = (f32) temp_t8->unk4;
                }
                // Node 10
                temp_a2_2 = *phi_v1;
                phi_a2 = temp_a2_2;
                phi_t0 = temp_t0;
                phi_t2 = (phi_t2 + 4);
                if (temp_t0 != 0xc)
                {
                    goto loop_6;
                }
                // Node 11
                temp_a1 = (phi_a1 + 1);
                phi_a1 = temp_a1;
                phi_a2 = temp_a2_2;
                if (temp_a1 < *temp_a2_2)
                {
                    goto loop_5;
                }
            }
        }
        else
        {

        }
        // Node 12
        phi_v1 = (phi_v1 + 8);
        if (phi_v1->unk8 != 0)
        {
            goto loop_1;
        }
    }
    // Node 13
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B95D8
/* 0EE108 7F0B95D8 3C058008 */  lui   $a1, %hi(g_BgPortals)
/* 0EE10C 7F0B95DC 8CA5FF80 */  lw    $a1, %lo(g_BgPortals)($a1)
/* 0EE110 7F0B95E0 00001025 */  move  $v0, $zero
/* 0EE114 7F0B95E4 240B000C */  li    $t3, 12
/* 0EE118 7F0B95E8 8CAE0000 */  lw    $t6, ($a1)
/* 0EE11C 7F0B95EC 00A01825 */  move  $v1, $a1
/* 0EE120 7F0B95F0 11C00034 */  beqz  $t6, .L7F0B96C4
/* 0EE124 7F0B95F4 00000000 */   nop
/* 0EE128 7F0B95F8 906F0004 */  lbu   $t7, 4($v1)
.L7F0B95FC:
/* 0EE12C 7F0B95FC 508F0005 */  beql  $a0, $t7, .L7F0B9614
/* 0EE130 7F0B9600 8C660000 */   lw    $a2, ($v1)
/* 0EE134 7F0B9604 90780005 */  lbu   $t8, 5($v1)
/* 0EE138 7F0B9608 5498002B */  bnel  $a0, $t8, .L7F0B96B8
/* 0EE13C 7F0B960C 8C790008 */   lw    $t9, 8($v1)
/* 0EE140 7F0B9610 8C660000 */  lw    $a2, ($v1)
.L7F0B9614:
/* 0EE144 7F0B9614 00046080 */  sll   $t4, $a0, 2
/* 0EE148 7F0B9618 01846021 */  addu  $t4, $t4, $a0
/* 0EE14C 7F0B961C 90D90000 */  lbu   $t9, ($a2)
/* 0EE150 7F0B9620 000C6100 */  sll   $t4, $t4, 4
/* 0EE154 7F0B9624 00002825 */  move  $a1, $zero
/* 0EE158 7F0B9628 1B200022 */  blez  $t9, .L7F0B96B4
/* 0EE15C 7F0B962C 3C0D8004 */   lui   $t5, %hi(g_BgRoomInfo)
/* 0EE160 7F0B9630 25AD1414 */  addiu $t5, %lo(g_BgRoomInfo) # addiu $t5, $t5, 0x1414
/* 0EE164 7F0B9634 018D4821 */  addu  $t1, $t4, $t5
/* 0EE168 7F0B9638 00004025 */  move  $t0, $zero
.L7F0B963C:
/* 0EE16C 7F0B963C 01205025 */  move  $t2, $t1
.L7F0B9640:
/* 0EE170 7F0B9640 00057080 */  sll   $t6, $a1, 2
/* 0EE174 7F0B9644 01C57023 */  subu  $t6, $t6, $a1
/* 0EE178 7F0B9648 000E7080 */  sll   $t6, $t6, 2
/* 0EE17C 7F0B964C 00CE7821 */  addu  $t7, $a2, $t6
/* 0EE180 7F0B9650 01E8C021 */  addu  $t8, $t7, $t0
/* 0EE184 7F0B9654 C7000004 */  lwc1  $f0, 4($t8)
/* 0EE188 7F0B9658 C5440038 */  lwc1  $f4, 0x38($t2)
/* 0EE18C 7F0B965C 25080004 */  addiu $t0, $t0, 4
/* 0EE190 7F0B9660 4604003C */  c.lt.s $f0, $f4
/* 0EE194 7F0B9664 00000000 */  nop
/* 0EE198 7F0B9668 45020004 */  bc1fl .L7F0B967C
/* 0EE19C 7F0B966C C5460044 */   lwc1  $f6, 0x44($t2)
/* 0EE1A0 7F0B9670 E5400038 */  swc1  $f0, 0x38($t2)
/* 0EE1A4 7F0B9674 24420001 */  addiu $v0, $v0, 1
/* 0EE1A8 7F0B9678 C5460044 */  lwc1  $f6, 0x44($t2)
.L7F0B967C:
/* 0EE1AC 7F0B967C 4600303C */  c.lt.s $f6, $f0
/* 0EE1B0 7F0B9680 00000000 */  nop
/* 0EE1B4 7F0B9684 45020004 */  bc1fl .L7F0B9698
/* 0EE1B8 7F0B9688 254A0004 */   addiu $t2, $t2, 4
/* 0EE1BC 7F0B968C E5400044 */  swc1  $f0, 0x44($t2)
/* 0EE1C0 7F0B9690 24420001 */  addiu $v0, $v0, 1
/* 0EE1C4 7F0B9694 254A0004 */  addiu $t2, $t2, 4
.L7F0B9698:
/* 0EE1C8 7F0B9698 150BFFE9 */  bne   $t0, $t3, .L7F0B9640
/* 0EE1CC 7F0B969C 8C660000 */   lw    $a2, ($v1)
/* 0EE1D0 7F0B96A0 90C70000 */  lbu   $a3, ($a2)
/* 0EE1D4 7F0B96A4 24A50001 */  addiu $a1, $a1, 1
/* 0EE1D8 7F0B96A8 00A7082A */  slt   $at, $a1, $a3
/* 0EE1DC 7F0B96AC 5420FFE3 */  bnezl $at, .L7F0B963C
/* 0EE1E0 7F0B96B0 00004025 */   move  $t0, $zero
.L7F0B96B4:
/* 0EE1E4 7F0B96B4 8C790008 */  lw    $t9, 8($v1)
.L7F0B96B8:
/* 0EE1E8 7F0B96B8 24630008 */  addiu $v1, $v1, 8
/* 0EE1EC 7F0B96BC 5720FFCF */  bnezl $t9, .L7F0B95FC
/* 0EE1F0 7F0B96C0 906F0004 */   lbu   $t7, 4($v1)
.L7F0B96C4:
/* 0EE1F4 7F0B96C4 03E00008 */  jr    $ra
/* 0EE1F8 7F0B96C8 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B96CC(int p) {
    #ifdef
    assert(levelportals[p].p->n>=3)
    #endif
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058D54
.word 0x7f7fffff /*3.4028235e38*/
glabel D_80058D58
.word 0xff7fffff /*-3.4028235e38*/
.text
glabel sub_GAME_7F0B96CC
/* 0EE1FC 7F0B96CC 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0EE200 7F0B96D0 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0EE204 7F0B96D4 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EE208 7F0B96D8 000440C0 */  sll   $t0, $a0, 3
/* 0EE20C 7F0B96DC AFB00020 */  sw    $s0, 0x20($sp)
/* 0EE210 7F0B96E0 00A08025 */  move  $s0, $a1
/* 0EE214 7F0B96E4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EE218 7F0B96E8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0EE21C 7F0B96EC 27A40078 */  addiu $a0, $sp, 0x78
/* 0EE220 7F0B96F0 27A6006C */  addiu $a2, $sp, 0x6c
/* 0EE224 7F0B96F4 00001025 */  move  $v0, $zero
/* 0EE228 7F0B96F8 01C83821 */  addu  $a3, $t6, $t0
/* 0EE22C 7F0B96FC 24C60004 */  addiu $a2, $a2, 4
/* 0EE230 7F0B9700 00C4082B */  sltu  $at, $a2, $a0
/* 0EE234 7F0B9704 1020000B */  beqz  $at, .L7F0B9734
/* 0EE238 7F0B9708 8CEF0000 */   lw    $t7, ($a3)
.L7F0B970C:
/* 0EE23C 7F0B970C 01E21821 */  addu  $v1, $t7, $v0
/* 0EE240 7F0B9710 C4740004 */  lwc1  $f20, 4($v1)
/* 0EE244 7F0B9714 C4720010 */  lwc1  $f18, 0x10($v1)
/* 0EE248 7F0B9718 24C60004 */  addiu $a2, $a2, 4
/* 0EE24C 7F0B971C 00C4082B */  sltu  $at, $a2, $a0
/* 0EE250 7F0B9720 4612A481 */  sub.s $f18, $f20, $f18
/* 0EE254 7F0B9724 24420004 */  addiu $v0, $v0, 4
/* 0EE258 7F0B9728 E4D2FFF8 */  swc1  $f18, -8($a2)
/* 0EE25C 7F0B972C 1420FFF7 */  bnez  $at, .L7F0B970C
/* 0EE260 7F0B9730 8CEF0000 */   lw    $t7, ($a3)
.L7F0B9734:
/* 0EE264 7F0B9734 01E21821 */  addu  $v1, $t7, $v0
/* 0EE268 7F0B9738 C4740004 */  lwc1  $f20, 4($v1)
/* 0EE26C 7F0B973C C4720010 */  lwc1  $f18, 0x10($v1)
/* 0EE270 7F0B9740 24420004 */  addiu $v0, $v0, 4
/* 0EE274 7F0B9744 4612A481 */  sub.s $f18, $f20, $f18
/* 0EE278 7F0B9748 E4D2FFFC */  swc1  $f18, -4($a2)
/* 0EE27C 7F0B974C 00001025 */  move  $v0, $zero
/* 0EE280 7F0B9750 27A40060 */  addiu $a0, $sp, 0x60
/* 0EE284 7F0B9754 27A5006C */  addiu $a1, $sp, 0x6c
/* 0EE288 7F0B9758 24840004 */  addiu $a0, $a0, 4
/* 0EE28C 7F0B975C 0085082B */  sltu  $at, $a0, $a1
/* 0EE290 7F0B9760 1020000B */  beqz  $at, .L7F0B9790
/* 0EE294 7F0B9764 8CF80000 */   lw    $t8, ($a3)
.L7F0B9768:
/* 0EE298 7F0B9768 03021821 */  addu  $v1, $t8, $v0
/* 0EE29C 7F0B976C C474001C */  lwc1  $f20, 0x1c($v1)
/* 0EE2A0 7F0B9770 C4720010 */  lwc1  $f18, 0x10($v1)
/* 0EE2A4 7F0B9774 24840004 */  addiu $a0, $a0, 4
/* 0EE2A8 7F0B9778 0085082B */  sltu  $at, $a0, $a1
/* 0EE2AC 7F0B977C 4612A481 */  sub.s $f18, $f20, $f18
/* 0EE2B0 7F0B9780 24420004 */  addiu $v0, $v0, 4
/* 0EE2B4 7F0B9784 E492FFF8 */  swc1  $f18, -8($a0)
/* 0EE2B8 7F0B9788 1420FFF7 */  bnez  $at, .L7F0B9768
/* 0EE2BC 7F0B978C 8CF80000 */   lw    $t8, ($a3)
.L7F0B9790:
/* 0EE2C0 7F0B9790 03021821 */  addu  $v1, $t8, $v0
/* 0EE2C4 7F0B9794 C474001C */  lwc1  $f20, 0x1c($v1)
/* 0EE2C8 7F0B9798 C4720010 */  lwc1  $f18, 0x10($v1)
/* 0EE2CC 7F0B979C 24420004 */  addiu $v0, $v0, 4
/* 0EE2D0 7F0B97A0 4612A481 */  sub.s $f18, $f20, $f18
/* 0EE2D4 7F0B97A4 E492FFFC */  swc1  $f18, -4($a0)
/* 0EE2D8 7F0B97A8 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0EE2DC 7F0B97AC C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0EE2E0 7F0B97B0 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0EE2E4 7F0B97B4 460A4102 */  mul.s $f4, $f8, $f10
/* 0EE2E8 7F0B97B8 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0EE2EC 7F0B97BC 46083282 */  mul.s $f10, $f6, $f8
/* 0EE2F0 7F0B97C0 460A2181 */  sub.s $f6, $f4, $f10
/* 0EE2F4 7F0B97C4 E6060000 */  swc1  $f6, ($s0)
/* 0EE2F8 7F0B97C8 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0EE2FC 7F0B97CC C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0EE300 7F0B97D0 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0EE304 7F0B97D4 C6100000 */  lwc1  $f16, ($s0)
/* 0EE308 7F0B97D8 46044282 */  mul.s $f10, $f8, $f4
/* 0EE30C 7F0B97DC C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 0EE310 7F0B97E0 46083102 */  mul.s $f4, $f6, $f8
/* 0EE314 7F0B97E4 46045181 */  sub.s $f6, $f10, $f4
/* 0EE318 7F0B97E8 E6060004 */  swc1  $f6, 4($s0)
/* 0EE31C 7F0B97EC C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0EE320 7F0B97F0 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 0EE324 7F0B97F4 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0EE328 7F0B97F8 C6120004 */  lwc1  $f18, 4($s0)
/* 0EE32C 7F0B97FC 460A4102 */  mul.s $f4, $f8, $f10
/* 0EE330 7F0B9800 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0EE334 7F0B9804 46083282 */  mul.s $f10, $f6, $f8
/* 0EE338 7F0B9808 460A2181 */  sub.s $f6, $f4, $f10
/* 0EE33C 7F0B980C 46108202 */  mul.s $f8, $f16, $f16
/* 0EE340 7F0B9810 00000000 */  nop
/* 0EE344 7F0B9814 46129102 */  mul.s $f4, $f18, $f18
/* 0EE348 7F0B9818 E6060008 */  swc1  $f6, 8($s0)
/* 0EE34C 7F0B981C C60E0008 */  lwc1  $f14, 8($s0)
/* 0EE350 7F0B9820 AFA80040 */  sw    $t0, 0x40($sp)
/* 0EE354 7F0B9824 460E7182 */  mul.s $f6, $f14, $f14
/* 0EE358 7F0B9828 46044280 */  add.s $f10, $f8, $f4
/* 0EE35C 7F0B982C 0C007DF8 */  jal   sqrtf
/* 0EE360 7F0B9830 460A3300 */   add.s $f12, $f6, $f10
/* 0EE364 7F0B9834 44804000 */  mtc1  $zero, $f8
/* 0EE368 7F0B9838 8FA80040 */  lw    $t0, 0x40($sp)
/* 0EE36C 7F0B983C 46000506 */  mov.s $f20, $f0
/* 0EE370 7F0B9840 46080032 */  c.eq.s $f0, $f8
/* 0EE374 7F0B9844 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EE378 7F0B9848 00001825 */  move  $v1, $zero
/* 0EE37C 7F0B984C 45030005 */  bc1tl .L7F0B9864
/* 0EE380 7F0B9850 C6060000 */   lwc1  $f6, ($s0)
/* 0EE384 7F0B9854 44812000 */  mtc1  $at, $f4
/* 0EE388 7F0B9858 00000000 */  nop
/* 0EE38C 7F0B985C 46002503 */  div.s $f20, $f4, $f0
/* 0EE390 7F0B9860 C6060000 */  lwc1  $f6, ($s0)
.L7F0B9864:
/* 0EE394 7F0B9864 C6080004 */  lwc1  $f8, 4($s0)
/* 0EE398 7F0B9868 3C198008 */  lui   $t9, %hi(g_BgPortals)
/* 0EE39C 7F0B986C 46143282 */  mul.s $f10, $f6, $f20
/* 0EE3A0 7F0B9870 C6060008 */  lwc1  $f6, 8($s0)
/* 0EE3A4 7F0B9874 3C018006 */  lui   $at, %hi(D_80058D54)
/* 0EE3A8 7F0B9878 46144102 */  mul.s $f4, $f8, $f20
/* 0EE3AC 7F0B987C E60A0000 */  swc1  $f10, ($s0)
/* 0EE3B0 7F0B9880 46143282 */  mul.s $f10, $f6, $f20
/* 0EE3B4 7F0B9884 E6040004 */  swc1  $f4, 4($s0)
/* 0EE3B8 7F0B9888 E60A0008 */  swc1  $f10, 8($s0)
/* 0EE3BC 7F0B988C 8F39FF80 */  lw    $t9, %lo(g_BgPortals)($t9)
/* 0EE3C0 7F0B9890 C4228D54 */  lwc1  $f2, %lo(D_80058D54)($at)
/* 0EE3C4 7F0B9894 3C018006 */  lui   $at, %hi(D_80058D58)
/* 0EE3C8 7F0B9898 03284821 */  addu  $t1, $t9, $t0
/* 0EE3CC 7F0B989C 8D250000 */  lw    $a1, ($t1)
/* 0EE3D0 7F0B98A0 C42C8D58 */  lwc1  $f12, %lo(D_80058D58)($at)
/* 0EE3D4 7F0B98A4 90A60000 */  lbu   $a2, ($a1)
/* 0EE3D8 7F0B98A8 00A01025 */  move  $v0, $a1
/* 0EE3DC 7F0B98AC 18C0001C */  blez  $a2, .L7F0B9920
/* 0EE3E0 7F0B98B0 00062080 */   sll   $a0, $a2, 2
/* 0EE3E4 7F0B98B4 00862023 */  subu  $a0, $a0, $a2
/* 0EE3E8 7F0B98B8 00042080 */  sll   $a0, $a0, 2
/* 0EE3EC 7F0B98BC C60E0008 */  lwc1  $f14, 8($s0)
/* 0EE3F0 7F0B98C0 C6100000 */  lwc1  $f16, ($s0)
/* 0EE3F4 7F0B98C4 C6120004 */  lwc1  $f18, 4($s0)
.L7F0B98C8:
/* 0EE3F8 7F0B98C8 C4480004 */  lwc1  $f8, 4($v0)
/* 0EE3FC 7F0B98CC C4460008 */  lwc1  $f6, 8($v0)
/* 0EE400 7F0B98D0 2463000C */  addiu $v1, $v1, 0xc
/* 0EE404 7F0B98D4 46104102 */  mul.s $f4, $f8, $f16
/* 0EE408 7F0B98D8 0064082A */  slt   $at, $v1, $a0
/* 0EE40C 7F0B98DC 46123282 */  mul.s $f10, $f6, $f18
/* 0EE410 7F0B98E0 C446000C */  lwc1  $f6, 0xc($v0)
/* 0EE414 7F0B98E4 460A2200 */  add.s $f8, $f4, $f10
/* 0EE418 7F0B98E8 46067102 */  mul.s $f4, $f14, $f6
/* 0EE41C 7F0B98EC 46082000 */  add.s $f0, $f4, $f8
/* 0EE420 7F0B98F0 4602003C */  c.lt.s $f0, $f2
/* 0EE424 7F0B98F4 00000000 */  nop
/* 0EE428 7F0B98F8 45020003 */  bc1fl .L7F0B9908
/* 0EE42C 7F0B98FC 4600603C */   c.lt.s $f12, $f0
/* 0EE430 7F0B9900 46000086 */  mov.s $f2, $f0
/* 0EE434 7F0B9904 4600603C */  c.lt.s $f12, $f0
.L7F0B9908:
/* 0EE438 7F0B9908 00000000 */  nop
/* 0EE43C 7F0B990C 45000002 */  bc1f  .L7F0B9918
/* 0EE440 7F0B9910 00000000 */   nop
/* 0EE444 7F0B9914 46000306 */  mov.s $f12, $f0
.L7F0B9918:
/* 0EE448 7F0B9918 1420FFEB */  bnez  $at, .L7F0B98C8
/* 0EE44C 7F0B991C 2442000C */   addiu $v0, $v0, 0xc
.L7F0B9920:
/* 0EE450 7F0B9920 E602000C */  swc1  $f2, 0xc($s0)
/* 0EE454 7F0B9924 E60C0010 */  swc1  $f12, 0x10($s0)
/* 0EE458 7F0B9928 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EE45C 7F0B992C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0EE460 7F0B9930 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0EE464 7F0B9934 03E00008 */  jr    $ra
/* 0EE468 7F0B9938 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif





/**
 * Unknown, makes use of sub_GAME_7F0B96CC.
 *
 * Address 0x7F0B993C.
 */
s32 sub_GAME_7F0B993C(s32 arg0)
{
    struct PortalMetric metric;
    s32 padding;

    sub_GAME_7F0B96CC(arg0, &metric);

    if (((metric.normal.f[0] * metric.normal.f[0]) + (metric.normal.f[2] * metric.normal.f[2])) < 0.999f)
    {
        return 0;
    }

    return 1;
}






#ifdef NONMATCHING
f32 sub_GAME_7F0B9990(s32 arg0) {
    void *temp_t8;
    s32 temp_t9;
    s32 temp_a0;
    f32 temp_f2;
    s32 temp_v1;
    f32 temp_f2_6;
    f32 temp_f2_2;
    s32 temp_v1_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    s32 phi_v1;
    s32 phi_v1_2;
    f32 phi_f2;
    f32 phi_f2_2;
    f32 phi_f2_3;

    // Node 0
    temp_t8 = (g_BgPortals + (arg0 * 8));
    temp_t9 = (((s32) temp_t8->unk7 >> 4) & 0xf);
    temp_a0 = -(s32) (temp_t9 & 3);
    temp_f2 = ((f32) (temp_t8->unk7 & 0xf) * 0.25f);
    phi_f2 = temp_f2;
    if (temp_t9 != 0)
    {
        // Node 1
        phi_v1 = temp_t9;
        phi_v1_2 = temp_t9;
        phi_f2_2 = temp_f2;
        phi_f2_3 = temp_f2;
        if (((temp_a0 == 0) || ((temp_a0 + temp_t9) != temp_v1)) || (temp_v1 != 0))
        {
loop_4:
            // Node 4
            temp_f2_2 = (phi_f2_2 + phi_f2_2);
            temp_v1_2 = (phi_v1_2 + -4);
            temp_f2_3 = (temp_f2_2 + temp_f2_2);
            temp_f2_4 = (temp_f2_3 + temp_f2_3);
            temp_f2_5 = (temp_f2_4 + temp_f2_4);
            phi_v1_2 = temp_v1_2;
            phi_f2 = temp_f2_5;
            phi_f2_2 = temp_f2_5;
            if (temp_v1_2 != 0)
            {
                goto loop_4;
            }
        }
        else
        {

        }
    }
    // Node 5
    return phi_f2;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9990
/* 0EE4C0 7F0B9990 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0EE4C4 7F0B9994 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EE4C8 7F0B9998 000478C0 */  sll   $t7, $a0, 3
/* 0EE4CC 7F0B999C 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0EE4D0 7F0B99A0 01CFC021 */  addu  $t8, $t6, $t7
/* 0EE4D4 7F0B99A4 93020007 */  lbu   $v0, 7($t8)
/* 0EE4D8 7F0B99A8 44814000 */  mtc1  $at, $f8
/* 0EE4DC 7F0B99AC 3048000F */  andi  $t0, $v0, 0xf
/* 0EE4E0 7F0B99B0 44882000 */  mtc1  $t0, $f4
/* 0EE4E4 7F0B99B4 00022903 */  sra   $a1, $v0, 4
/* 0EE4E8 7F0B99B8 30B9000F */  andi  $t9, $a1, 0xf
/* 0EE4EC 7F0B99BC 468021A0 */  cvt.s.w $f6, $f4
/* 0EE4F0 7F0B99C0 33240003 */  andi  $a0, $t9, 3
/* 0EE4F4 7F0B99C4 03201825 */  move  $v1, $t9
/* 0EE4F8 7F0B99C8 00042023 */  negu  $a0, $a0
/* 0EE4FC 7F0B99CC 46083082 */  mul.s $f2, $f6, $f8
/* 0EE500 7F0B99D0 1320000E */  beqz  $t9, .L7F0B9A0C
/* 0EE504 7F0B99D4 00000000 */   nop
/* 0EE508 7F0B99D8 10800006 */  beqz  $a0, .L7F0B99F4
/* 0EE50C 7F0B99DC 00991021 */   addu  $v0, $a0, $t9
.L7F0B99E0:
/* 0EE510 7F0B99E0 2463FFFF */  addiu $v1, $v1, -1
/* 0EE514 7F0B99E4 1443FFFE */  bne   $v0, $v1, .L7F0B99E0
/* 0EE518 7F0B99E8 46021080 */   add.s $f2, $f2, $f2
/* 0EE51C 7F0B99EC 10600007 */  beqz  $v1, .L7F0B9A0C
/* 0EE520 7F0B99F0 00000000 */   nop
.L7F0B99F4:
/* 0EE524 7F0B99F4 46021080 */  add.s $f2, $f2, $f2
/* 0EE528 7F0B99F8 2463FFFC */  addiu $v1, $v1, -4
/* 0EE52C 7F0B99FC 46021080 */  add.s $f2, $f2, $f2
/* 0EE530 7F0B9A00 46021080 */  add.s $f2, $f2, $f2
/* 0EE534 7F0B9A04 1460FFFB */  bnez  $v1, .L7F0B99F4
/* 0EE538 7F0B9A08 46021080 */   add.s $f2, $f2, $f2
.L7F0B9A0C:
/* 0EE53C 7F0B9A0C 03E00008 */  jr    $ra
/* 0EE540 7F0B9A10 46001006 */   mov.s $f0, $f2
)
#endif




/**
 * Unreferenced.
 *
 * Address 0x7F0B9A14.
 */
u8 bgGetDataPortalsControlBytes2(s32 p)
{
    return g_BgPortals[p].controlbytes2;
}





#ifdef NONMATCHING
s32 sub_GAME_7F0B9A2C(s32 p)
{
     byte byte2;

    if (g_BgPortals[p].controlbytes2 == -1)
    {
        byte2 = 0xff;
    }
    else
    {
        byte2 = g_BgPortals[p].controlbytes2 + 1;
        if (byte2 >> 4 != 0)
        {
            byte2 |= 8;
        }
    }
    g_BgPortals[p].controlbytes2 = byte2;
  return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9A2C
/* 0EE55C 7F0B9A2C 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0EE560 7F0B9A30 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EE564 7F0B9A34 000478C0 */  sll   $t7, $a0, 3
/* 0EE568 7F0B9A38 01CF1821 */  addu  $v1, $t6, $t7
/* 0EE56C 7F0B9A3C 90620007 */  lbu   $v0, 7($v1)
/* 0EE570 7F0B9A40 284100FF */  slti  $at, $v0, 0xff
/* 0EE574 7F0B9A44 14200003 */  bnez  $at, .L7F0B9A54
/* 0EE578 7F0B9A48 24420001 */   addiu $v0, $v0, 1
/* 0EE57C 7F0B9A4C 10000009 */  b     .L7F0B9A74
/* 0EE580 7F0B9A50 240200FF */   li    $v0, 255
.L7F0B9A54:
/* 0EE584 7F0B9A54 305800FF */  andi  $t8, $v0, 0xff
/* 0EE588 7F0B9A58 0018C903 */  sra   $t9, $t8, 4
/* 0EE58C 7F0B9A5C 3328000F */  andi  $t0, $t9, 0xf
/* 0EE590 7F0B9A60 19000004 */  blez  $t0, .L7F0B9A74
/* 0EE594 7F0B9A64 03001025 */   move  $v0, $t8
/* 0EE598 7F0B9A68 37020008 */  ori   $v0, $t8, 8
/* 0EE59C 7F0B9A6C 304900FF */  andi  $t1, $v0, 0xff
/* 0EE5A0 7F0B9A70 01201025 */  move  $v0, $t1
.L7F0B9A74:
/* 0EE5A4 7F0B9A74 03E00008 */  jr    $ra
/* 0EE5A8 7F0B9A78 A0620007 */   sb    $v0, 7($v1)
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0B9A7C(s32 p)
{
    if (g_BgPortals[p].controlbytes2 >> 4 == 0)
    {
        byte22 = g_BgPortals[p].controlbytes2;
        if (byte2 != 0)
        {
            byte22 = g_BgPortals[p].controlbytes2 - 1;
        }
    }
    else
    {
        byte22 = g_BgPortals[p].controlbytes2 - 1;
        if ((g_BgPortals[p].controlbytes2 - 1 & 0xf) < 8)
        {
            byte22 = g_BgPortals[p].controlbytes2 - 9;
        }
    }
    g_BgPortals[p].controlbytes2] = byte22;
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9A7C
/* 0EE5AC 7F0B9A7C 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0EE5B0 7F0B9A80 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EE5B4 7F0B9A84 000478C0 */  sll   $t7, $a0, 3
/* 0EE5B8 7F0B9A88 01CF1821 */  addu  $v1, $t6, $t7
/* 0EE5BC 7F0B9A8C 90620007 */  lbu   $v0, 7($v1)
/* 0EE5C0 7F0B9A90 0002C103 */  sra   $t8, $v0, 4
/* 0EE5C4 7F0B9A94 3319000F */  andi  $t9, $t8, 0xf
/* 0EE5C8 7F0B9A98 17200007 */  bnez  $t9, .L7F0B9AB8
/* 0EE5CC 7F0B9A9C 00402825 */   move  $a1, $v0
/* 0EE5D0 7F0B9AA0 18A0000E */  blez  $a1, .L7F0B9ADC
/* 0EE5D4 7F0B9AA4 00000000 */   nop
/* 0EE5D8 7F0B9AA8 2442FFFF */  addiu $v0, $v0, -1
/* 0EE5DC 7F0B9AAC 304800FF */  andi  $t0, $v0, 0xff
/* 0EE5E0 7F0B9AB0 1000000A */  b     .L7F0B9ADC
/* 0EE5E4 7F0B9AB4 01001025 */   move  $v0, $t0
.L7F0B9AB8:
/* 0EE5E8 7F0B9AB8 2442FFFF */  addiu $v0, $v0, -1
/* 0EE5EC 7F0B9ABC 304900FF */  andi  $t1, $v0, 0xff
/* 0EE5F0 7F0B9AC0 312A000F */  andi  $t2, $t1, 0xf
/* 0EE5F4 7F0B9AC4 29410008 */  slti  $at, $t2, 8
/* 0EE5F8 7F0B9AC8 10200004 */  beqz  $at, .L7F0B9ADC
/* 0EE5FC 7F0B9ACC 01201025 */   move  $v0, $t1
/* 0EE600 7F0B9AD0 2522FFF8 */  addiu $v0, $t1, -8
/* 0EE604 7F0B9AD4 304B00FF */  andi  $t3, $v0, 0xff
/* 0EE608 7F0B9AD8 01601025 */  move  $v0, $t3
.L7F0B9ADC:
/* 0EE60C 7F0B9ADC 03E00008 */  jr    $ra
/* 0EE610 7F0B9AE0 A0620007 */   sb    $v0, 7($v1)
)
#endif



/**
 * @param index: index into portal array.
 *
 * Address 0x7F0B9AE4.
 */
s32 bgGetDataPortalsControlBytes1Bit1(s32 index)
{
    return g_BgPortals[index].controlbytes1 & 1;
}



/**
 * @param index: index into portal array.
 *
 * Address 0x7F0B9B04.
 */
s32 bgGetDataPortalsControlBytes1Bit2(s32 index)
{
    return g_BgPortals[index].controlbytes1 & 2;
}



/**
 * @param index: index into portal array.
 *
 * Address 0x7F0B9B24.
 */
void bgSetDataPortalsControlBytes1Bit2(s32 index)
{
    g_BgPortals[index].controlbytes1 |= 2;
}



/**
 * @param index: index into portal array.
 *
 * Address 0x7F0B9B44.
 */
void bgClearDataPortalsControlBytes1Low2Bits(s32 index)
{
    g_BgPortals[index].controlbytes1 &= 0xFD;
}



/**
 * Swaps connected rooms.
 *
 * @param index: index into portal array.
 *
 * Address 0x7F0B9B64.
 */
s8 bgSwapConnectedRooms(s32 index)
{
    u8 t;

    t = g_BgPortals[index].connectedRoom1;
    g_BgPortals[index].connectedRoom1 = g_BgPortals[index].connectedRoom2;
    g_BgPortals[index].connectedRoom2 = t;
}





#ifdef NONMATCHING
//bgorderPortal
f32 sub_GAME_7F0B9B94(s32 arg0) {
    s32 sp24;
    ?32 sp28;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp48;
    f32 sp54;
    void *temp_v0;
    f32 temp_f0;
    f32 phi_f16;
    f32 phi_f18;
    f32 phi_f14;
    s32 phi_v0;
    f32 phi_f12;
    f32 phi_return;

    // Node 0
    temp_v0 = (g_BgPortals + (arg0 * 8));
    sp28 = (?32) temp_v0->unk5;
    sub_GAME_7F0B92B4(temp_v0->unk4, &sp54);
    sub_GAME_7F0B92B4(sp28, &sp48);
    sub_GAME_7F0B96CC(arg0, &sp34); //possible float return
    #ifdef DEBUG
    if (0.1 < local_50 - local_54)
    {
        iVar4  = osSyncPrintf("bg: bgOrderPortal: Portal \'%s\' not planar by %5.2f\n", bgDebPrintPORTALID(param_1), local_50 - local_54);
    }
    #endif

    phi_f16 = sp3C;
    phi_f18 = sp34;
    phi_f14 = sp40;
    phi_v0 = 0;
    phi_f12 = sp44;
    if (sp44 < ((sp5C * sp3C) + ((sp34 * sp54) + (sp38 * sp58))))
    {
        // Node 1
        sp24 = 1;
        bgSwapConnectedRooms(sp44, sp40, arg0);
        sp38 = (f32) -sp38;
        phi_f16 = -sp3C;
        phi_f18 = -sp34;
        phi_f14 = -sp44;
        phi_v0 = 1;
        phi_f12 = -sp40;
    }
    // Node 2
    sp3C = (f32) phi_f16;
    sp34 = (f32) phi_f18;
    temp_f0 = ((sp50 * phi_f16) + ((phi_f18 * sp48) + (sp38 * sp4C)));
    phi_return = temp_f0;
    if (temp_f0 <= phi_f14)
    {
        // Node 3
        phi_return = temp_f0;
        if (phi_v0 != 0)
        {
            // Node 4
            sp24 = (s32) phi_v0;
            phi_return = bgSwapConnectedRooms(phi_f12, phi_f14, arg0);
        }
    }
    // Node 5
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9B94
/* 0EE6C4 7F0B9B94 3C0E8008 */  lui   $t6, %hi(g_BgPortals)
/* 0EE6C8 7F0B9B98 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EE6CC 7F0B9B9C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0EE6D0 7F0B9BA0 0004C0C0 */  sll   $t8, $a0, 3
/* 0EE6D4 7F0B9BA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EE6D8 7F0B9BA8 AFA40060 */  sw    $a0, 0x60($sp)
/* 0EE6DC 7F0B9BAC 01D81021 */  addu  $v0, $t6, $t8
/* 0EE6E0 7F0B9BB0 90590005 */  lbu   $t9, 5($v0)
/* 0EE6E4 7F0B9BB4 90440004 */  lbu   $a0, 4($v0)
/* 0EE6E8 7F0B9BB8 27A50054 */  addiu $a1, $sp, 0x54
/* 0EE6EC 7F0B9BBC 0FC2E4AD */  jal   sub_GAME_7F0B92B4
/* 0EE6F0 7F0B9BC0 AFB90028 */   sw    $t9, 0x28($sp)
/* 0EE6F4 7F0B9BC4 8FA40028 */  lw    $a0, 0x28($sp)
/* 0EE6F8 7F0B9BC8 0FC2E4AD */  jal   sub_GAME_7F0B92B4
/* 0EE6FC 7F0B9BCC 27A50048 */   addiu $a1, $sp, 0x48
/* 0EE700 7F0B9BD0 8FA40060 */  lw    $a0, 0x60($sp)
/* 0EE704 7F0B9BD4 0FC2E5B3 */  jal   sub_GAME_7F0B96CC
/* 0EE708 7F0B9BD8 27A50034 */   addiu $a1, $sp, 0x34
/* 0EE70C 7F0B9BDC C7A40038 */  lwc1  $f4, 0x38($sp)
/* 0EE710 7F0B9BE0 C7A60058 */  lwc1  $f6, 0x58($sp)
/* 0EE714 7F0B9BE4 C7B20034 */  lwc1  $f18, 0x34($sp)
/* 0EE718 7F0B9BE8 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 0EE71C 7F0B9BEC 46062202 */  mul.s $f8, $f4, $f6
/* 0EE720 7F0B9BF0 C7B0003C */  lwc1  $f16, 0x3c($sp)
/* 0EE724 7F0B9BF4 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0EE728 7F0B9BF8 460A9102 */  mul.s $f4, $f18, $f10
/* 0EE72C 7F0B9BFC C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0EE730 7F0B9C00 C7AE0040 */  lwc1  $f14, 0x40($sp)
/* 0EE734 7F0B9C04 00001025 */  move  $v0, $zero
/* 0EE738 7F0B9C08 8FA40060 */  lw    $a0, 0x60($sp)
/* 0EE73C 7F0B9C0C 46082180 */  add.s $f6, $f4, $f8
/* 0EE740 7F0B9C10 46105102 */  mul.s $f4, $f10, $f16
/* 0EE744 7F0B9C14 46062080 */  add.s $f2, $f4, $f6
/* 0EE748 7F0B9C18 4602603C */  c.lt.s $f12, $f2
/* 0EE74C 7F0B9C1C 00000000 */  nop
/* 0EE750 7F0B9C20 45020012 */  bc1fl .L7F0B9C6C
/* 0EE754 7F0B9C24 C7A40038 */   lwc1  $f4, 0x38($sp)
/* 0EE758 7F0B9C28 24020001 */  li    $v0, 1
/* 0EE75C 7F0B9C2C 0FC2E6D9 */  jal   bgSwapConnectedRooms
/* 0EE760 7F0B9C30 AFA20024 */   sw    $v0, 0x24($sp)
/* 0EE764 7F0B9C34 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0EE768 7F0B9C38 C7A00040 */  lwc1  $f0, 0x40($sp)
/* 0EE76C 7F0B9C3C C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0EE770 7F0B9C40 C7B0003C */  lwc1  $f16, 0x3c($sp)
/* 0EE774 7F0B9C44 C7B20034 */  lwc1  $f18, 0x34($sp)
/* 0EE778 7F0B9C48 46006387 */  neg.s $f14, $f12
/* 0EE77C 7F0B9C4C 46000307 */  neg.s $f12, $f0
/* 0EE780 7F0B9C50 46004287 */  neg.s $f10, $f8
/* 0EE784 7F0B9C54 8FA20024 */  lw    $v0, 0x24($sp)
/* 0EE788 7F0B9C58 E7AA0038 */  swc1  $f10, 0x38($sp)
/* 0EE78C 7F0B9C5C E7AC0044 */  swc1  $f12, 0x44($sp)
/* 0EE790 7F0B9C60 46008407 */  neg.s $f16, $f16
/* 0EE794 7F0B9C64 46009487 */  neg.s $f18, $f18
/* 0EE798 7F0B9C68 C7A40038 */  lwc1  $f4, 0x38($sp)
.L7F0B9C6C:
/* 0EE79C 7F0B9C6C C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 0EE7A0 7F0B9C70 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0EE7A4 7F0B9C74 E7AE0040 */  swc1  $f14, 0x40($sp)
/* 0EE7A8 7F0B9C78 46062202 */  mul.s $f8, $f4, $f6
/* 0EE7AC 7F0B9C7C E7B0003C */  swc1  $f16, 0x3c($sp)
/* 0EE7B0 7F0B9C80 E7B20034 */  swc1  $f18, 0x34($sp)
/* 0EE7B4 7F0B9C84 460A9102 */  mul.s $f4, $f18, $f10
/* 0EE7B8 7F0B9C88 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 0EE7BC 7F0B9C8C 46082180 */  add.s $f6, $f4, $f8
/* 0EE7C0 7F0B9C90 46105102 */  mul.s $f4, $f10, $f16
/* 0EE7C4 7F0B9C94 46062000 */  add.s $f0, $f4, $f6
/* 0EE7C8 7F0B9C98 460E003E */  c.le.s $f0, $f14
/* 0EE7CC 7F0B9C9C 00000000 */  nop
/* 0EE7D0 7F0B9CA0 45020006 */  bc1fl .L7F0B9CBC
/* 0EE7D4 7F0B9CA4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0EE7D8 7F0B9CA8 10400003 */  beqz  $v0, .L7F0B9CB8
/* 0EE7DC 7F0B9CAC 8FA40060 */   lw    $a0, 0x60($sp)
/* 0EE7E0 7F0B9CB0 0FC2E6D9 */  jal   bgSwapConnectedRooms
/* 0EE7E4 7F0B9CB4 AFA20024 */   sw    $v0, 0x24($sp)
.L7F0B9CB8:
/* 0EE7E8 7F0B9CB8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0B9CBC:
/* 0EE7EC 7F0B9CBC 27BD0060 */  addiu $sp, $sp, 0x60
/* 0EE7F0 7F0B9CC0 03E00008 */  jr    $ra
/* 0EE7F4 7F0B9CC4 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B9CC8(void) {
    if (something == -1) osSyncPrintf("bg: bgGetPortalBetweenRooms(): No portal joins room \'%s\' and \'%s\'\n", bgDebPrintROOMID(), bgDebPrintROOMID());

    //if reach end
    osSyncPrintf("bg: bgGetPortalBetweenRooms(): Multiple portals join room \'%s\' and \'%s\'\ n", bgDebPrintROOMID(), bgDebPrintROOMID());
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9CC8
/* 0EE7F8 7F0B9CC8 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0EE7FC 7F0B9CCC AFBE0038 */  sw    $fp, 0x38($sp)
/* 0EE800 7F0B9CD0 3C1E8008 */  lui   $fp, %hi(g_BgPortals)
/* 0EE804 7F0B9CD4 27DEFF80 */  addiu $fp, %lo(g_BgPortals) # addiu $fp, $fp, -0x80
/* 0EE808 7F0B9CD8 8FC30000 */  lw    $v1, ($fp)
/* 0EE80C 7F0B9CDC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0EE810 7F0B9CE0 AFB70034 */  sw    $s7, 0x34($sp)
/* 0EE814 7F0B9CE4 AFB60030 */  sw    $s6, 0x30($sp)
/* 0EE818 7F0B9CE8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0EE81C 7F0B9CEC AFB40028 */  sw    $s4, 0x28($sp)
/* 0EE820 7F0B9CF0 AFB30024 */  sw    $s3, 0x24($sp)
/* 0EE824 7F0B9CF4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0EE828 7F0B9CF8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0EE82C 7F0B9CFC AFB00018 */  sw    $s0, 0x18($sp)
/* 0EE830 7F0B9D00 8C6E0000 */  lw    $t6, ($v1)
/* 0EE834 7F0B9D04 00809025 */  move  $s2, $a0
/* 0EE838 7F0B9D08 00A09825 */  move  $s3, $a1
/* 0EE83C 7F0B9D0C 00C0B025 */  move  $s6, $a2
/* 0EE840 7F0B9D10 00E0B825 */  move  $s7, $a3
/* 0EE844 7F0B9D14 2414FFFF */  li    $s4, -1
/* 0EE848 7F0B9D18 11C0001B */  beqz  $t6, .L7F0B9D88
/* 0EE84C 7F0B9D1C 00008025 */   move  $s0, $zero
/* 0EE850 7F0B9D20 00008825 */  move  $s1, $zero
/* 0EE854 7F0B9D24 00601025 */  move  $v0, $v1
/* 0EE858 7F0B9D28 90430004 */  lbu   $v1, 4($v0)
.L7F0B9D2C:
/* 0EE85C 7F0B9D2C 16430004 */  bne   $s2, $v1, .L7F0B9D40
/* 0EE860 7F0B9D30 00000000 */   nop
/* 0EE864 7F0B9D34 904F0005 */  lbu   $t7, 5($v0)
/* 0EE868 7F0B9D38 526F0006 */  beql  $s3, $t7, .L7F0B9D54
/* 0EE86C 7F0B9D3C 02002025 */   move  $a0, $s0
.L7F0B9D40:
/* 0EE870 7F0B9D40 5663000B */  bnel  $s3, $v1, .L7F0B9D70
/* 0EE874 7F0B9D44 8FD90000 */   lw    $t9, ($fp)
/* 0EE878 7F0B9D48 90580005 */  lbu   $t8, 5($v0)
/* 0EE87C 7F0B9D4C 16580007 */  bne   $s2, $t8, .L7F0B9D6C
/* 0EE880 7F0B9D50 02002025 */   move  $a0, $s0
.L7F0B9D54:
/* 0EE884 7F0B9D54 02C02825 */  move  $a1, $s6
/* 0EE888 7F0B9D58 0FC2E7C5 */  jal   sub_GAME_7F0B9F14
/* 0EE88C 7F0B9D5C 02E03025 */   move  $a2, $s7
/* 0EE890 7F0B9D60 50400003 */  beql  $v0, $zero, .L7F0B9D70
/* 0EE894 7F0B9D64 8FD90000 */   lw    $t9, ($fp)
/* 0EE898 7F0B9D68 0200A025 */  move  $s4, $s0
.L7F0B9D6C:
/* 0EE89C 7F0B9D6C 8FD90000 */  lw    $t9, ($fp)
.L7F0B9D70:
/* 0EE8A0 7F0B9D70 26310008 */  addiu $s1, $s1, 8
/* 0EE8A4 7F0B9D74 26100001 */  addiu $s0, $s0, 1
/* 0EE8A8 7F0B9D78 03311021 */  addu  $v0, $t9, $s1
/* 0EE8AC 7F0B9D7C 8C480000 */  lw    $t0, ($v0)
/* 0EE8B0 7F0B9D80 5500FFEA */  bnezl $t0, .L7F0B9D2C
/* 0EE8B4 7F0B9D84 90430004 */   lbu   $v1, 4($v0)
.L7F0B9D88:
/* 0EE8B8 7F0B9D88 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0EE8BC 7F0B9D8C 02801025 */  move  $v0, $s4
/* 0EE8C0 7F0B9D90 8FB40028 */  lw    $s4, 0x28($sp)
/* 0EE8C4 7F0B9D94 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EE8C8 7F0B9D98 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0EE8CC 7F0B9D9C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0EE8D0 7F0B9DA0 8FB30024 */  lw    $s3, 0x24($sp)
/* 0EE8D4 7F0B9DA4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0EE8D8 7F0B9DA8 8FB60030 */  lw    $s6, 0x30($sp)
/* 0EE8DC 7F0B9DAC 8FB70034 */  lw    $s7, 0x34($sp)
/* 0EE8E0 7F0B9DB0 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0EE8E4 7F0B9DB4 03E00008 */  jr    $ra
/* 0EE8E8 7F0B9DB8 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





/**
 * Toggles control bytes 1 lowest bit, based on toggle parameter.
 *
 * @param index: index into data portals.
 * @param toggle: When zero, sets lowest bit. Otherwise, clears lowest bit.
 *
 * Address 0x7F0B9DBC.
 */
void bgToggleDataPortalsContrlBytes1Bit1(s32 portal, s32 toggle)
{
    #ifdef DEBUG
    assert(portal<PORTMAX);
    #endif
    g_BgPortals[portal].controlbytes1 = (g_BgPortals[portal].controlbytes1 | 1) ^ (toggle != 0);
}




/**
 * Debug method, called from lvl.c.
 * Something to do with portals.
 *
 * Address 0x7F0B9DE4.
 */
s32 bgDebugRemoved7F0B9DE4(s32 arg0, s32 arg1, s32 arg2)
{
#if DEBUG
    // removed
#endif

    return arg0;
}




/**
 * Debug method, called from lvl.c.
 * Something to do with portals.
 *
 * Address 0x7F0B9DF4.
 */
void bgRemoved7F0B9DF4(s32 arg0)
{
#if DEBUG
    // removed
#endif

    return;
}

/**
 * Unreferenced.
 *
 * Address 0x7F0B9DFC.
 */
void bgRemoved7F0B9DFC(s32 p)
{
#if DEBUG
        osSyncPrintf("bg: Error: Multiple portals intersect line; \'%s\' dropped ", bgDebPrintPORTALID(p));
#endif

    return;
}
//bg_consider_window82397B18
s32 sub_GAME_7F0B9E04(coord3d *arg0, coord3d *arg1)
{
    s32 bestportalnum = -1;
    s32 count = 0;
    f32 bestthing = MAXFLOAT;
    f32 thisthing;
    s32 i;

    for (i = 0; g_BgPortals[i].offset_portal; i++)
    {
        if (sub_GAME_7F0B9F14(i, arg0, arg1) != 0)
        {
            thisthing = D_80044900;

            if (thisthing < 0)
            {
                thisthing = -thisthing;
#if DEBUG
                osSyncPrintf("bg: Portal \'%s\' briefly considered for window\n", bgDebPrintPORTALID(i));
#endif
            }

            if (thisthing < bestthing)
            {
                if (count)
                {
#if DEBUG
                    osSyncPrintf("bg: Portal \'%s\' briefly considered for window\n", bgDebPrintPORTALID(i));
#endif
                }
                if (i);
                bestportalnum = i;
                bestthing = thisthing;
                count++;
            }
        }
    }

    return bestportalnum;
}


#ifdef NONMATCHING
s32 sub_GAME_7F0B9F14(s32 portalnum, struct coord *arg1, struct coord *arg2) {

}
#else
s32 sub_GAME_7F0B9F14(s32 portalnum, struct coord *arg1, struct coord *arg2);
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B9F14
/* 0EEA44 7F0B9F14 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 0EEA48 7F0B9F18 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EEA4C 7F0B9F1C 00A08025 */  move  $s0, $a1
/* 0EEA50 7F0B9F20 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EEA54 7F0B9F24 AFA400A0 */  sw    $a0, 0xa0($sp)
/* 0EEA58 7F0B9F28 27A50060 */  addiu $a1, $sp, 0x60
/* 0EEA5C 7F0B9F2C AFA600A8 */  sw    $a2, 0xa8($sp)
/* 0EEA60 7F0B9F30 A3A0004B */  sb    $zero, 0x4b($sp)
/* 0EEA64 7F0B9F34 0FC2E5B3 */  jal   sub_GAME_7F0B96CC
/* 0EEA68 7F0B9F38 A3A0004A */   sb    $zero, 0x4a($sp)
/* 0EEA6C 7F0B9F3C 8FA600A8 */  lw    $a2, 0xa8($sp)
/* 0EEA70 7F0B9F40 C6100000 */  lwc1  $f16, ($s0)
/* 0EEA74 7F0B9F44 3C018004 */  lui   $at, %hi(room_data_float1)
/* 0EEA78 7F0B9F48 C4CA0000 */  lwc1  $f10, ($a2)
/* 0EEA7C 7F0B9F4C C42C13F4 */  lwc1  $f12, %lo(room_data_float1)($at)
/* 0EEA80 7F0B9F50 93AA004B */  lbu   $t2, 0x4b($sp)
/* 0EEA84 7F0B9F54 46105181 */  sub.s $f6, $f10, $f16
/* 0EEA88 7F0B9F58 93AB004A */  lbu   $t3, 0x4a($sp)
/* 0EEA8C 7F0B9F5C E7A6008C */  swc1  $f6, 0x8c($sp)
/* 0EEA90 7F0B9F60 C6080004 */  lwc1  $f8, 4($s0)
/* 0EEA94 7F0B9F64 C4C40004 */  lwc1  $f4, 4($a2)
/* 0EEA98 7F0B9F68 46082481 */  sub.s $f18, $f4, $f8
/* 0EEA9C 7F0B9F6C C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0EEAA0 7F0B9F70 E7B20090 */  swc1  $f18, 0x90($sp)
/* 0EEAA4 7F0B9F74 C6100008 */  lwc1  $f16, 8($s0)
/* 0EEAA8 7F0B9F78 C4CA0008 */  lwc1  $f10, 8($a2)
/* 0EEAAC 7F0B9F7C 46105181 */  sub.s $f6, $f10, $f16
/* 0EEAB0 7F0B9F80 C7B00064 */  lwc1  $f16, 0x64($sp)
/* 0EEAB4 7F0B9F84 E7A60094 */  swc1  $f6, 0x94($sp)
/* 0EEAB8 7F0B9F88 C6040000 */  lwc1  $f4, ($s0)
/* 0EEABC 7F0B9F8C C60A0004 */  lwc1  $f10, 4($s0)
/* 0EEAC0 7F0B9F90 46082482 */  mul.s $f18, $f4, $f8
/* 0EEAC4 7F0B9F94 00000000 */  nop
/* 0EEAC8 7F0B9F98 46105182 */  mul.s $f6, $f10, $f16
/* 0EEACC 7F0B9F9C C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0EEAD0 7F0B9FA0 46069100 */  add.s $f4, $f18, $f6
/* 0EEAD4 7F0B9FA4 C6120008 */  lwc1  $f18, 8($s0)
/* 0EEAD8 7F0B9FA8 46125182 */  mul.s $f6, $f10, $f18
/* 0EEADC 7F0B9FAC 46043480 */  add.s $f18, $f6, $f4
/* 0EEAE0 7F0B9FB0 C4C60000 */  lwc1  $f6, ($a2)
/* 0EEAE4 7F0B9FB4 460C9382 */  mul.s $f14, $f18, $f12
/* 0EEAE8 7F0B9FB8 C4D20004 */  lwc1  $f18, 4($a2)
/* 0EEAEC 7F0B9FBC 46083102 */  mul.s $f4, $f6, $f8
/* 0EEAF0 7F0B9FC0 00000000 */  nop
/* 0EEAF4 7F0B9FC4 46109182 */  mul.s $f6, $f18, $f16
/* 0EEAF8 7F0B9FC8 C4D20008 */  lwc1  $f18, 8($a2)
/* 0EEAFC 7F0B9FCC 46125402 */  mul.s $f16, $f10, $f18
/* 0EEB00 7F0B9FD0 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0EEB04 7F0B9FD4 46062200 */  add.s $f8, $f4, $f6
/* 0EEB08 7F0B9FD8 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0EEB0C 7F0B9FDC 46088100 */  add.s $f4, $f16, $f8
/* 0EEB10 7F0B9FE0 4606703C */  c.lt.s $f14, $f6
/* 0EEB14 7F0B9FE4 460C2002 */  mul.s $f0, $f4, $f12
/* 0EEB18 7F0B9FE8 45000005 */  bc1f  .L7F0BA000
/* 0EEB1C 7F0B9FEC 00000000 */   nop
/* 0EEB20 7F0B9FF0 4606003C */  c.lt.s $f0, $f6
/* 0EEB24 7F0B9FF4 00000000 */  nop
/* 0EEB28 7F0B9FF8 45010009 */  bc1t  .L7F0BA020
/* 0EEB2C 7F0B9FFC 00000000 */   nop
.L7F0BA000:
/* 0EEB30 7F0BA000 460E503C */  c.lt.s $f10, $f14
/* 0EEB34 7F0BA004 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0EEB38 7F0BA008 45020008 */  bc1fl .L7F0BA02C
/* 0EEB3C 7F0BA00C 46007480 */   add.s $f18, $f14, $f0
/* 0EEB40 7F0BA010 4600503C */  c.lt.s $f10, $f0
/* 0EEB44 7F0BA014 00000000 */  nop
/* 0EEB48 7F0BA018 45020004 */  bc1fl .L7F0BA02C
/* 0EEB4C 7F0BA01C 46007480 */   add.s $f18, $f14, $f0
.L7F0BA020:
/* 0EEB50 7F0BA020 1000008D */  b     .L7F0BA258
/* 0EEB54 7F0BA024 00001025 */   move  $v0, $zero
/* 0EEB58 7F0BA028 46007480 */  add.s $f18, $f14, $f0
.L7F0BA02C:
/* 0EEB5C 7F0BA02C 44818000 */  mtc1  $at, $f16
/* 0EEB60 7F0BA030 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 0EEB64 7F0BA034 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0EEB68 7F0BA038 46109202 */  mul.s $f8, $f18, $f16
/* 0EEB6C 7F0BA03C 3C0F8008 */  lui   $t7, %hi(g_BgPortals)
/* 0EEB70 7F0BA040 8DEFFF80 */  lw    $t7, %lo(g_BgPortals)($t7)
/* 0EEB74 7F0BA044 3C018004 */  lui   $at, %hi(D_80044900)
/* 0EEB78 7F0BA048 000EC0C0 */  sll   $t8, $t6, 3
/* 0EEB7C 7F0BA04C 01F84021 */  addu  $t0, $t7, $t8
/* 0EEB80 7F0BA050 00003825 */  move  $a3, $zero
/* 0EEB84 7F0BA054 46044181 */  sub.s $f6, $f8, $f4
/* 0EEB88 7F0BA058 00002025 */  move  $a0, $zero
/* 0EEB8C 7F0BA05C E4264900 */  swc1  $f6, %lo(D_80044900)($at)
/* 0EEB90 7F0BA060 8D020000 */  lw    $v0, ($t0)
/* 0EEB94 7F0BA064 90460000 */  lbu   $a2, ($v0)
/* 0EEB98 7F0BA068 58C00073 */  blezl $a2, .L7F0BA238
/* 0EEB9C 7F0BA06C C7B2006C */   lwc1  $f18, 0x6c($sp)
/* 0EEBA0 7F0BA070 44801000 */  mtc1  $zero, $f2
/* 0EEBA4 7F0BA074 240C000C */  li    $t4, 12
/* 0EEBA8 7F0BA078 24E90001 */  addiu $t1, $a3, 1
.L7F0BA07C:
/* 0EEBAC 7F0BA07C 0126001A */  div   $zero, $t1, $a2
/* 0EEBB0 7F0BA080 00002810 */  mfhi  $a1
/* 0EEBB4 7F0BA084 00446821 */  addu  $t5, $v0, $a0
/* 0EEBB8 7F0BA088 C5B20004 */  lwc1  $f18, 4($t5)
/* 0EEBBC 7F0BA08C 00AC0019 */  multu $a1, $t4
/* 0EEBC0 7F0BA090 14C00002 */  bnez  $a2, .L7F0BA09C
/* 0EEBC4 7F0BA094 00000000 */   nop
/* 0EEBC8 7F0BA098 0007000D */  break 7
.L7F0BA09C:
/* 0EEBCC 7F0BA09C 2401FFFF */  li    $at, -1
/* 0EEBD0 7F0BA0A0 14C10004 */  bne   $a2, $at, .L7F0BA0B4
/* 0EEBD4 7F0BA0A4 3C018000 */   lui   $at, 0x8000
/* 0EEBD8 7F0BA0A8 15210002 */  bne   $t1, $at, .L7F0BA0B4
/* 0EEBDC 7F0BA0AC 00000000 */   nop
/* 0EEBE0 7F0BA0B0 0006000D */  break 6
.L7F0BA0B4:
/* 0EEBE4 7F0BA0B4 00001812 */  mflo  $v1
/* 0EEBE8 7F0BA0B8 0043C821 */  addu  $t9, $v0, $v1
/* 0EEBEC 7F0BA0BC C72A0004 */  lwc1  $f10, 4($t9)
/* 0EEBF0 7F0BA0C0 46125401 */  sub.s $f16, $f10, $f18
/* 0EEBF4 7F0BA0C4 E7B00074 */  swc1  $f16, 0x74($sp)
/* 0EEBF8 7F0BA0C8 8D020000 */  lw    $v0, ($t0)
/* 0EEBFC 7F0BA0CC 00437021 */  addu  $t6, $v0, $v1
/* 0EEC00 7F0BA0D0 00447821 */  addu  $t7, $v0, $a0
/* 0EEC04 7F0BA0D4 C5E40008 */  lwc1  $f4, 8($t7)
/* 0EEC08 7F0BA0D8 C5C80008 */  lwc1  $f8, 8($t6)
/* 0EEC0C 7F0BA0DC 46044181 */  sub.s $f6, $f8, $f4
/* 0EEC10 7F0BA0E0 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0EEC14 7F0BA0E4 E7A60078 */  swc1  $f6, 0x78($sp)
/* 0EEC18 7F0BA0E8 8D020000 */  lw    $v0, ($t0)
/* 0EEC1C 7F0BA0EC C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0EEC20 7F0BA0F0 0043C021 */  addu  $t8, $v0, $v1
/* 0EEC24 7F0BA0F4 0044C821 */  addu  $t9, $v0, $a0
/* 0EEC28 7F0BA0F8 C732000C */  lwc1  $f18, 0xc($t9)
/* 0EEC2C 7F0BA0FC C70A000C */  lwc1  $f10, 0xc($t8)
/* 0EEC30 7F0BA100 46044182 */  mul.s $f6, $f8, $f4
/* 0EEC34 7F0BA104 E7A80020 */  swc1  $f8, 0x20($sp)
/* 0EEC38 7F0BA108 46125401 */  sub.s $f16, $f10, $f18
/* 0EEC3C 7F0BA10C C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0EEC40 7F0BA110 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0EEC44 7F0BA114 E7B0007C */  swc1  $f16, 0x7c($sp)
/* 0EEC48 7F0BA118 C7B2007C */  lwc1  $f18, 0x7c($sp)
/* 0EEC4C 7F0BA11C 46125402 */  mul.s $f16, $f10, $f18
/* 0EEC50 7F0BA120 46103181 */  sub.s $f6, $f6, $f16
/* 0EEC54 7F0BA124 C7B0008C */  lwc1  $f16, 0x8c($sp)
/* 0EEC58 7F0BA128 46109482 */  mul.s $f18, $f18, $f16
/* 0EEC5C 7F0BA12C E7A60050 */  swc1  $f6, 0x50($sp)
/* 0EEC60 7F0BA130 46082102 */  mul.s $f4, $f4, $f8
/* 0EEC64 7F0BA134 46049481 */  sub.s $f18, $f18, $f4
/* 0EEC68 7F0BA138 460A4102 */  mul.s $f4, $f8, $f10
/* 0EEC6C 7F0BA13C C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0EEC70 7F0BA140 E7B20054 */  swc1  $f18, 0x54($sp)
/* 0EEC74 7F0BA144 46088282 */  mul.s $f10, $f16, $f8
/* 0EEC78 7F0BA148 460A2401 */  sub.s $f16, $f4, $f10
/* 0EEC7C 7F0BA14C 46063202 */  mul.s $f8, $f6, $f6
/* 0EEC80 7F0BA150 00000000 */  nop
/* 0EEC84 7F0BA154 46129102 */  mul.s $f4, $f18, $f18
/* 0EEC88 7F0BA158 E7B00058 */  swc1  $f16, 0x58($sp)
/* 0EEC8C 7F0BA15C 46108182 */  mul.s $f6, $f16, $f16
/* 0EEC90 7F0BA160 46044280 */  add.s $f10, $f8, $f4
/* 0EEC94 7F0BA164 460A3000 */  add.s $f0, $f6, $f10
/* 0EEC98 7F0BA168 46020032 */  c.eq.s $f0, $f2
/* 0EEC9C 7F0BA16C 00000000 */  nop
/* 0EECA0 7F0BA170 45000003 */  bc1f  .L7F0BA180
/* 0EECA4 7F0BA174 00000000 */   nop
/* 0EECA8 7F0BA178 10000037 */  b     .L7F0BA258
/* 0EECAC 7F0BA17C 00001025 */   move  $v0, $zero
.L7F0BA180:
/* 0EECB0 7F0BA180 8D0D0000 */  lw    $t5, ($t0)
/* 0EECB4 7F0BA184 C7B20050 */  lwc1  $f18, 0x50($sp)
/* 0EECB8 7F0BA188 C7B00054 */  lwc1  $f16, 0x54($sp)
/* 0EECBC 7F0BA18C 01A41021 */  addu  $v0, $t5, $a0
/* 0EECC0 7F0BA190 C4480004 */  lwc1  $f8, 4($v0)
/* 0EECC4 7F0BA194 C4460008 */  lwc1  $f6, 8($v0)
/* 0EECC8 7F0BA198 46089102 */  mul.s $f4, $f18, $f8
/* 0EECCC 7F0BA19C 00000000 */  nop
/* 0EECD0 7F0BA1A0 46068282 */  mul.s $f10, $f16, $f6
/* 0EECD4 7F0BA1A4 C446000C */  lwc1  $f6, 0xc($v0)
/* 0EECD8 7F0BA1A8 460A2200 */  add.s $f8, $f4, $f10
/* 0EECDC 7F0BA1AC C7A40058 */  lwc1  $f4, 0x58($sp)
/* 0EECE0 7F0BA1B0 46043282 */  mul.s $f10, $f6, $f4
/* 0EECE4 7F0BA1B4 46085180 */  add.s $f6, $f10, $f8
/* 0EECE8 7F0BA1B8 E7A6005C */  swc1  $f6, 0x5c($sp)
/* 0EECEC 7F0BA1BC C60A0000 */  lwc1  $f10, ($s0)
/* 0EECF0 7F0BA1C0 460A9202 */  mul.s $f8, $f18, $f10
/* 0EECF4 7F0BA1C4 C6120004 */  lwc1  $f18, 4($s0)
/* 0EECF8 7F0BA1C8 46128282 */  mul.s $f10, $f16, $f18
/* 0EECFC 7F0BA1CC C6120008 */  lwc1  $f18, 8($s0)
/* 0EED00 7F0BA1D0 460A4400 */  add.s $f16, $f8, $f10
/* 0EED04 7F0BA1D4 46049202 */  mul.s $f8, $f18, $f4
/* 0EED08 7F0BA1D8 46104280 */  add.s $f10, $f8, $f16
/* 0EED0C 7F0BA1DC 460C5002 */  mul.s $f0, $f10, $f12
/* 0EED10 7F0BA1E0 4606003C */  c.lt.s $f0, $f6
/* 0EED14 7F0BA1E4 00000000 */  nop
/* 0EED18 7F0BA1E8 45000007 */  bc1f  .L7F0BA208
/* 0EED1C 7F0BA1EC 00000000 */   nop
/* 0EED20 7F0BA1F0 11600003 */  beqz  $t3, .L7F0BA200
/* 0EED24 7F0BA1F4 00000000 */   nop
/* 0EED28 7F0BA1F8 10000017 */  b     .L7F0BA258
/* 0EED2C 7F0BA1FC 00001025 */   move  $v0, $zero
.L7F0BA200:
/* 0EED30 7F0BA200 10000005 */  b     .L7F0BA218
/* 0EED34 7F0BA204 240A0001 */   li    $t2, 1
.L7F0BA208:
/* 0EED38 7F0BA208 11400003 */  beqz  $t2, .L7F0BA218
/* 0EED3C 7F0BA20C 240B0001 */   li    $t3, 1
/* 0EED40 7F0BA210 10000011 */  b     .L7F0BA258
/* 0EED44 7F0BA214 00001025 */   move  $v0, $zero
.L7F0BA218:
/* 0EED48 7F0BA218 8D020000 */  lw    $v0, ($t0)
/* 0EED4C 7F0BA21C 01203825 */  move  $a3, $t1
/* 0EED50 7F0BA220 2484000C */  addiu $a0, $a0, 0xc
/* 0EED54 7F0BA224 90460000 */  lbu   $a2, ($v0)
/* 0EED58 7F0BA228 0126082A */  slt   $at, $t1, $a2
/* 0EED5C 7F0BA22C 5420FF93 */  bnezl $at, .L7F0BA07C
/* 0EED60 7F0BA230 24E90001 */   addiu $t1, $a3, 1
/* 0EED64 7F0BA234 C7B2006C */  lwc1  $f18, 0x6c($sp)
.L7F0BA238:
/* 0EED68 7F0BA238 24030002 */  li    $v1, 2
/* 0EED6C 7F0BA23C 4612703C */  c.lt.s $f14, $f18
/* 0EED70 7F0BA240 00000000 */  nop
/* 0EED74 7F0BA244 45000003 */  bc1f  .L7F0BA254
/* 0EED78 7F0BA248 00000000 */   nop
/* 0EED7C 7F0BA24C 10000001 */  b     .L7F0BA254
/* 0EED80 7F0BA250 24030001 */   li    $v1, 1
.L7F0BA254:
/* 0EED84 7F0BA254 00601025 */  move  $v0, $v1
.L7F0BA258:
/* 0EED88 7F0BA258 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EED8C 7F0BA25C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EED90 7F0BA260 27BD00A0 */  addiu $sp, $sp, 0xa0
/* 0EED94 7F0BA264 03E00008 */  jr    $ra
/* 0EED98 7F0BA268 00000000 */   nop
)
#endif


bool bgIsBboxOverlapping(coord3d *portalbbmin, coord3d *portalbbmax, coord3d *propbbmin, coord3d *propbbmax)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (propbbmin->f[i] > portalbbmax->f[i] || propbbmax->f[i] < portalbbmin->f[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}


#ifdef NONMATCHING
void sub_GAME_7F0BA2D4(void *arg0, void *arg1, s32 *arg2, s32 *arg3, s32 arg4)
{
    f32   spA8;
    f32   spA4;
    f32   spA0;
    f32   sp9C;
    f32   sp98;
    f32   sp94;
    s32   sp8C;
    s32   sp7C;
    f32   sp70;
    f32   sp64;
    s32  *sp5C;
    f32  *var_v0;
    f32  *var_v1;
    f32   temp_f0;
    s32  *var_v0_2;
    s32   temp_s3;
    s32   temp_t2;
    s32   var_a0;
    s32   var_a2;
    s32   var_s1;
    s32   var_s2;
    s32   var_t0;
    s32   var_t0_2;
    u8  **temp_v0;
    u8  **var_a3;
    u8    temp_v0_2;
    u8    var_v1_2;
    void *temp_a3;

    var_s1 = *arg3;
    var_t0 = 0;
    spA0   = arg0->unk0 * room_data_float1;
    spA4   = arg0->unk4 * room_data_float1;
    spA8   = arg0->unk8 * room_data_float1;
    sp94   = arg1->unk0 * room_data_float1;
    sp98   = arg1->unk4 * room_data_float1;
    sp7C   = var_s1;
    sp9C   = arg1->unk8 * room_data_float1;
loop_1:
    if (var_t0 < var_s1)
    {
        temp_v0 = g_BgPortals;
        sp5C    = arg2 + (var_t0 * 4);
loop_3:
        var_s2  = 0;
        temp_s3 = *sp5C;
        if (*temp_v0 != NULL)
        {
            sp8C   = var_t0;
            var_a3 = temp_v0;
loop_5:
            if (!(var_a3->unk6 & 1) && ((temp_s3 == var_a3->unk4) || (temp_s3 == var_a3->unk5)))
            {
                sp70.unk0 = D_80044904.unk0;
                sp70.unk4 = D_80044904.unk4;
                sp70.unk8 = D_80044904.unk8;
                var_a2    = 0;
                sp64.unk0 = D_80044910.unk0;
                sp64.unk4 = D_80044910.unk4;
                sp64.unk8 = D_80044910.unk8;
                if (*var_a3->unk0 > 0) //g_BgRoomInfo->numportals 0x47 in debug, 0x0 in retail... maybesomething comes before ?
                {
                    do
                    {
                        var_a0 = 0;
                        var_v1 = &sp70;
                        var_v0 = &sp64;
loop_10:
                        temp_f0 = (var_a3->unk0 + (var_a2 * 0xC) + var_a0)->unk4;
                        var_a0 += 4;
                        if (temp_f0 < *var_v1)
                        {
                            *var_v1 = temp_f0;
                        }
                        var_v1 += 4;
                        if (*var_v0 < temp_f0)
                        {
                            *var_v0 = temp_f0;
                        }
                        var_v0 += 4;
                        if (var_v0 != &sp70)
                        {
                            goto loop_10;
                        }
                        var_a2 += 1;
                    } while (var_a2 < *var_a3->unk0);
                }
                if (bgIsBboxOverlapping(&sp70, &sp64, &spA0, &sp94) != 0)
                {
                    var_t0_2  = 0;
                    temp_a3   = g_BgPortals + var_s2;
                    temp_v0_2 = temp_a3->unk4;
                    var_v1_2  = temp_v0_2;
                    if (temp_s3 == temp_v0_2)
                    {
                        var_v1_2 = temp_a3->unk5;
                    }
                    var_v0_2 = arg2;
                    if (var_s1 > 0)
                    {
loop_20:
                        if (var_v1_2 != *var_v0_2)
                        {
                            var_t0_2 += 1;
                            var_v0_2 += 4;
                            if (var_t0_2 != var_s1)
                            {
                                goto loop_20;
                            }
                        }
                    }
                    if (var_t0_2 == var_s1)
                    {
                        if (var_s1 < arg4)
                        {
                            *(arg2 + (var_s1 * 4)) = var_v1_2;
                            var_s1 += 1;
                        }
                        if (var_s1 >= arg4)
                        {
                            *arg3 = var_s1;
                            return;
                        }
                        goto block_27;
                    }
                    goto block_27;
                }
block_27:
                var_a3 = g_BgPortals + var_s2;
                goto block_28;
            }
block_28:
            temp_t2 = var_a3->unk8;
            var_s2 += 8;
            var_a3 += 8;
            if (temp_t2 == 0)
            {
                var_t0 = sp8C;
                goto block_30;
            }
            goto loop_5;
        }
block_30:
        var_t0 += 1;
        sp5C += 4;
        if (var_t0 >= sp7C)
        {
            goto block_31;
        }
        goto loop_3;
    }
block_31:
    if (var_s1 != sp7C)
    {
        sp7C = var_s1;
        goto loop_1;
    }
    *arg3 = var_s1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BA2D4
/* 0EEE04 7F0BA2D4 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0EEE08 7F0BA2D8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0EEE0C 7F0BA2DC AFBE0038 */  sw    $fp, 0x38($sp)
/* 0EEE10 7F0BA2E0 AFB70034 */  sw    $s7, 0x34($sp)
/* 0EEE14 7F0BA2E4 AFB60030 */  sw    $s6, 0x30($sp)
/* 0EEE18 7F0BA2E8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0EEE1C 7F0BA2EC AFB40028 */  sw    $s4, 0x28($sp)
/* 0EEE20 7F0BA2F0 AFB30024 */  sw    $s3, 0x24($sp)
/* 0EEE24 7F0BA2F4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0EEE28 7F0BA2F8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0EEE2C 7F0BA2FC AFB00018 */  sw    $s0, 0x18($sp)
/* 0EEE30 7F0BA300 AFA700C4 */  sw    $a3, 0xc4($sp)
/* 0EEE34 7F0BA304 3C018004 */  lui   $at, %hi(room_data_float1)
/* 0EEE38 7F0BA308 C42013F4 */  lwc1  $f0, %lo(room_data_float1)($at)
/* 0EEE3C 7F0BA30C C4840000 */  lwc1  $f4, ($a0)
/* 0EEE40 7F0BA310 8CF10000 */  lw    $s1, ($a3)
/* 0EEE44 7F0BA314 3C1E8004 */  lui   $fp, %hi(D_80044904)
/* 0EEE48 7F0BA318 46002182 */  mul.s $f6, $f4, $f0
/* 0EEE4C 7F0BA31C 00C0A025 */  move  $s4, $a2
/* 0EEE50 7F0BA320 00004025 */  move  $t0, $zero
/* 0EEE54 7F0BA324 27DE4904 */  addiu $fp, %lo(D_80044904) # addiu $fp, $fp, 0x4904
/* 0EEE58 7F0BA328 27B00070 */  addiu $s0, $sp, 0x70
/* 0EEE5C 7F0BA32C 8FB500C8 */  lw    $s5, 0xc8($sp)
/* 0EEE60 7F0BA330 27B60070 */  addiu $s6, $sp, 0x70
/* 0EEE64 7F0BA334 E7A600A0 */  swc1  $f6, 0xa0($sp)
/* 0EEE68 7F0BA338 C4880004 */  lwc1  $f8, 4($a0)
/* 0EEE6C 7F0BA33C 27B70064 */  addiu $s7, $sp, 0x64
/* 0EEE70 7F0BA340 46004282 */  mul.s $f10, $f8, $f0
/* 0EEE74 7F0BA344 E7AA00A4 */  swc1  $f10, 0xa4($sp)
/* 0EEE78 7F0BA348 C4900008 */  lwc1  $f16, 8($a0)
/* 0EEE7C 7F0BA34C 46008482 */  mul.s $f18, $f16, $f0
/* 0EEE80 7F0BA350 E7B200A8 */  swc1  $f18, 0xa8($sp)
/* 0EEE84 7F0BA354 C4A40000 */  lwc1  $f4, ($a1)
/* 0EEE88 7F0BA358 46002182 */  mul.s $f6, $f4, $f0
/* 0EEE8C 7F0BA35C E7A60094 */  swc1  $f6, 0x94($sp)
/* 0EEE90 7F0BA360 C4A80004 */  lwc1  $f8, 4($a1)
/* 0EEE94 7F0BA364 46004282 */  mul.s $f10, $f8, $f0
/* 0EEE98 7F0BA368 E7AA0098 */  swc1  $f10, 0x98($sp)
/* 0EEE9C 7F0BA36C C4B00008 */  lwc1  $f16, 8($a1)
/* 0EEEA0 7F0BA370 AFB1007C */  sw    $s1, 0x7c($sp)
/* 0EEEA4 7F0BA374 46008482 */  mul.s $f18, $f16, $f0
/* 0EEEA8 7F0BA378 E7B2009C */  swc1  $f18, 0x9c($sp)
.L7F0BA37C:
/* 0EEEAC 7F0BA37C 0111082A */  slt   $at, $t0, $s1
/* 0EEEB0 7F0BA380 1020007C */  beqz  $at, .L7F0BA574
/* 0EEEB4 7F0BA384 00087880 */   sll   $t7, $t0, 2
/* 0EEEB8 7F0BA388 028FC021 */  addu  $t8, $s4, $t7
/* 0EEEBC 7F0BA38C 3C028008 */  lui   $v0, %hi(g_BgPortals)
/* 0EEEC0 7F0BA390 8C42FF80 */  lw    $v0, %lo(g_BgPortals)($v0)
/* 0EEEC4 7F0BA394 AFB8005C */  sw    $t8, 0x5c($sp)
.L7F0BA398:
/* 0EEEC8 7F0BA398 8C490000 */  lw    $t1, ($v0)
/* 0EEECC 7F0BA39C 8FB9005C */  lw    $t9, 0x5c($sp)
/* 0EEED0 7F0BA3A0 00009025 */  move  $s2, $zero
/* 0EEED4 7F0BA3A4 1120006C */  beqz  $t1, .L7F0BA558
/* 0EEED8 7F0BA3A8 8F330000 */   lw    $s3, ($t9)
/* 0EEEDC 7F0BA3AC AFA8008C */  sw    $t0, 0x8c($sp)
/* 0EEEE0 7F0BA3B0 00403825 */  move  $a3, $v0
/* 0EEEE4 7F0BA3B4 90EA0006 */  lbu   $t2, 6($a3)
.L7F0BA3B8:
/* 0EEEE8 7F0BA3B8 314B0001 */  andi  $t3, $t2, 1
/* 0EEEEC 7F0BA3BC 55600061 */  bnezl $t3, .L7F0BA544
/* 0EEEF0 7F0BA3C0 8CEA0008 */   lw    $t2, 8($a3)
/* 0EEEF4 7F0BA3C4 90EC0004 */  lbu   $t4, 4($a3)
/* 0EEEF8 7F0BA3C8 526C0005 */  beql  $s3, $t4, .L7F0BA3E0
/* 0EEEFC 7F0BA3CC 8FC10000 */   lw    $at, ($fp)
/* 0EEF00 7F0BA3D0 90ED0005 */  lbu   $t5, 5($a3)
/* 0EEF04 7F0BA3D4 566D005B */  bnel  $s3, $t5, .L7F0BA544
/* 0EEF08 7F0BA3D8 8CEA0008 */   lw    $t2, 8($a3)
/* 0EEF0C 7F0BA3DC 8FC10000 */  lw    $at, ($fp)
.L7F0BA3E0:
/* 0EEF10 7F0BA3E0 8FCF0004 */  lw    $t7, 4($fp)
/* 0EEF14 7F0BA3E4 3C188004 */  lui   $t8, %hi(D_80044910)
/* 0EEF18 7F0BA3E8 AEC10000 */  sw    $at, ($s6)
/* 0EEF1C 7F0BA3EC 8FC10008 */  lw    $at, 8($fp)
/* 0EEF20 7F0BA3F0 27184910 */  addiu $t8, %lo(D_80044910) # addiu $t8, $t8, 0x4910
/* 0EEF24 7F0BA3F4 AECF0004 */  sw    $t7, 4($s6)
/* 0EEF28 7F0BA3F8 AEC10008 */  sw    $at, 8($s6)
/* 0EEF2C 7F0BA3FC 8F010000 */  lw    $at, ($t8)
/* 0EEF30 7F0BA400 00003025 */  move  $a2, $zero
/* 0EEF34 7F0BA404 AEE10000 */  sw    $at, ($s7)
/* 0EEF38 7F0BA408 8F090004 */  lw    $t1, 4($t8)
/* 0EEF3C 7F0BA40C AEE90004 */  sw    $t1, 4($s7)
/* 0EEF40 7F0BA410 8F010008 */  lw    $at, 8($t8)
/* 0EEF44 7F0BA414 AEE10008 */  sw    $at, 8($s7)
/* 0EEF48 7F0BA418 8CE50000 */  lw    $a1, ($a3)
/* 0EEF4C 7F0BA41C 90AA0000 */  lbu   $t2, ($a1)
/* 0EEF50 7F0BA420 1940001F */  blez  $t2, .L7F0BA4A0
/* 0EEF54 7F0BA424 00002025 */   move  $a0, $zero
.L7F0BA428:
/* 0EEF58 7F0BA428 27A30070 */  addiu $v1, $sp, 0x70
/* 0EEF5C 7F0BA42C 27A20064 */  addiu $v0, $sp, 0x64
.L7F0BA430:
/* 0EEF60 7F0BA430 00065880 */  sll   $t3, $a2, 2
/* 0EEF64 7F0BA434 01665823 */  subu  $t3, $t3, $a2
/* 0EEF68 7F0BA438 000B5880 */  sll   $t3, $t3, 2
/* 0EEF6C 7F0BA43C 00AB6021 */  addu  $t4, $a1, $t3
/* 0EEF70 7F0BA440 01846821 */  addu  $t5, $t4, $a0
/* 0EEF74 7F0BA444 C5A00004 */  lwc1  $f0, 4($t5)
/* 0EEF78 7F0BA448 C4640000 */  lwc1  $f4, ($v1)
/* 0EEF7C 7F0BA44C 24840004 */  addiu $a0, $a0, 4
/* 0EEF80 7F0BA450 4604003C */  c.lt.s $f0, $f4
/* 0EEF84 7F0BA454 00000000 */  nop
/* 0EEF88 7F0BA458 45020003 */  bc1fl .L7F0BA468
/* 0EEF8C 7F0BA45C C4460000 */   lwc1  $f6, ($v0)
/* 0EEF90 7F0BA460 E4600000 */  swc1  $f0, ($v1)
/* 0EEF94 7F0BA464 C4460000 */  lwc1  $f6, ($v0)
.L7F0BA468:
/* 0EEF98 7F0BA468 24630004 */  addiu $v1, $v1, 4
/* 0EEF9C 7F0BA46C 4600303C */  c.lt.s $f6, $f0
/* 0EEFA0 7F0BA470 00000000 */  nop
/* 0EEFA4 7F0BA474 45020003 */  bc1fl .L7F0BA484
/* 0EEFA8 7F0BA478 24420004 */   addiu $v0, $v0, 4
/* 0EEFAC 7F0BA47C E4400000 */  swc1  $f0, ($v0)
/* 0EEFB0 7F0BA480 24420004 */  addiu $v0, $v0, 4
.L7F0BA484:
/* 0EEFB4 7F0BA484 1450FFEA */  bne   $v0, $s0, .L7F0BA430
/* 0EEFB8 7F0BA488 8CE50000 */   lw    $a1, ($a3)
/* 0EEFBC 7F0BA48C 90A20000 */  lbu   $v0, ($a1)
/* 0EEFC0 7F0BA490 24C60001 */  addiu $a2, $a2, 1
/* 0EEFC4 7F0BA494 00C2082A */  slt   $at, $a2, $v0
/* 0EEFC8 7F0BA498 5420FFE3 */  bnezl $at, .L7F0BA428
/* 0EEFCC 7F0BA49C 00002025 */   move  $a0, $zero
.L7F0BA4A0:
/* 0EEFD0 7F0BA4A0 02C02025 */  move  $a0, $s6
/* 0EEFD4 7F0BA4A4 02E02825 */  move  $a1, $s7
/* 0EEFD8 7F0BA4A8 27A600A0 */  addiu $a2, $sp, 0xa0
/* 0EEFDC 7F0BA4AC 0FC2E89B */  jal   bgIsBboxOverlapping
/* 0EEFE0 7F0BA4B0 27A70094 */   addiu $a3, $sp, 0x94
/* 0EEFE4 7F0BA4B4 1040001F */  beqz  $v0, .L7F0BA534
/* 0EEFE8 7F0BA4B8 3C0E8008 */   lui   $t6, %hi(g_BgPortals)
/* 0EEFEC 7F0BA4BC 8DCEFF80 */  lw    $t6, %lo(g_BgPortals)($t6)
/* 0EEFF0 7F0BA4C0 00004025 */  move  $t0, $zero
/* 0EEFF4 7F0BA4C4 0235082A */  slt   $at, $s1, $s5
/* 0EEFF8 7F0BA4C8 01D23821 */  addu  $a3, $t6, $s2
/* 0EEFFC 7F0BA4CC 90E20004 */  lbu   $v0, 4($a3)
/* 0EF000 7F0BA4D0 16620003 */  bne   $s3, $v0, .L7F0BA4E0
/* 0EF004 7F0BA4D4 00401825 */   move  $v1, $v0
/* 0EF008 7F0BA4D8 10000001 */  b     .L7F0BA4E0
/* 0EF00C 7F0BA4DC 90E30005 */   lbu   $v1, 5($a3)
.L7F0BA4E0:
/* 0EF010 7F0BA4E0 1A200007 */  blez  $s1, .L7F0BA500
/* 0EF014 7F0BA4E4 02801025 */   move  $v0, $s4
.L7F0BA4E8:
/* 0EF018 7F0BA4E8 8C4F0000 */  lw    $t7, ($v0)
/* 0EF01C 7F0BA4EC 106F0004 */  beq   $v1, $t7, .L7F0BA500
/* 0EF020 7F0BA4F0 00000000 */   nop
/* 0EF024 7F0BA4F4 25080001 */  addiu $t0, $t0, 1
/* 0EF028 7F0BA4F8 1511FFFB */  bne   $t0, $s1, .L7F0BA4E8
/* 0EF02C 7F0BA4FC 24420004 */   addiu $v0, $v0, 4
.L7F0BA500:
/* 0EF030 7F0BA500 1511000C */  bne   $t0, $s1, .L7F0BA534
/* 0EF034 7F0BA504 00000000 */   nop
/* 0EF038 7F0BA508 10200004 */  beqz  $at, .L7F0BA51C
/* 0EF03C 7F0BA50C 0011C880 */   sll   $t9, $s1, 2
/* 0EF040 7F0BA510 0299C021 */  addu  $t8, $s4, $t9
/* 0EF044 7F0BA514 AF030000 */  sw    $v1, ($t8)
/* 0EF048 7F0BA518 26310001 */  addiu $s1, $s1, 1
.L7F0BA51C:
/* 0EF04C 7F0BA51C 0235082A */  slt   $at, $s1, $s5
/* 0EF050 7F0BA520 14200004 */  bnez  $at, .L7F0BA534
/* 0EF054 7F0BA524 00000000 */   nop
/* 0EF058 7F0BA528 8FA900C4 */  lw    $t1, 0xc4($sp)
/* 0EF05C 7F0BA52C 10000018 */  b     .L7F0BA590
/* 0EF060 7F0BA530 AD310000 */   sw    $s1, ($t1)
.L7F0BA534:
/* 0EF064 7F0BA534 3C028008 */  lui   $v0, %hi(g_BgPortals)
/* 0EF068 7F0BA538 8C42FF80 */  lw    $v0, %lo(g_BgPortals)($v0)
/* 0EF06C 7F0BA53C 00523821 */  addu  $a3, $v0, $s2
/* 0EF070 7F0BA540 8CEA0008 */  lw    $t2, 8($a3)
.L7F0BA544:
/* 0EF074 7F0BA544 26520008 */  addiu $s2, $s2, 8
/* 0EF078 7F0BA548 24E70008 */  addiu $a3, $a3, 8
/* 0EF07C 7F0BA54C 5540FF9A */  bnezl $t2, .L7F0BA3B8
/* 0EF080 7F0BA550 90EA0006 */   lbu   $t2, 6($a3)
/* 0EF084 7F0BA554 8FA8008C */  lw    $t0, 0x8c($sp)
.L7F0BA558:
/* 0EF088 7F0BA558 8FAB005C */  lw    $t3, 0x5c($sp)
/* 0EF08C 7F0BA55C 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0EF090 7F0BA560 25080001 */  addiu $t0, $t0, 1
/* 0EF094 7F0BA564 256C0004 */  addiu $t4, $t3, 4
/* 0EF098 7F0BA568 010D082A */  slt   $at, $t0, $t5
/* 0EF09C 7F0BA56C 1420FF8A */  bnez  $at, .L7F0BA398
/* 0EF0A0 7F0BA570 AFAC005C */   sw    $t4, 0x5c($sp)
.L7F0BA574:
/* 0EF0A4 7F0BA574 8FAE007C */  lw    $t6, 0x7c($sp)
/* 0EF0A8 7F0BA578 522E0004 */  beql  $s1, $t6, .L7F0BA58C
/* 0EF0AC 7F0BA57C 8FAF00C4 */   lw    $t7, 0xc4($sp)
/* 0EF0B0 7F0BA580 1000FF7E */  b     .L7F0BA37C
/* 0EF0B4 7F0BA584 AFB1007C */   sw    $s1, 0x7c($sp)
/* 0EF0B8 7F0BA588 8FAF00C4 */  lw    $t7, 0xc4($sp)
.L7F0BA58C:
/* 0EF0BC 7F0BA58C ADF10000 */  sw    $s1, ($t7)
.L7F0BA590:
/* 0EF0C0 7F0BA590 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0EF0C4 7F0BA594 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EF0C8 7F0BA598 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0EF0CC 7F0BA59C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0EF0D0 7F0BA5A0 8FB30024 */  lw    $s3, 0x24($sp)
/* 0EF0D4 7F0BA5A4 8FB40028 */  lw    $s4, 0x28($sp)
/* 0EF0D8 7F0BA5A8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0EF0DC 7F0BA5AC 8FB60030 */  lw    $s6, 0x30($sp)
/* 0EF0E0 7F0BA5B0 8FB70034 */  lw    $s7, 0x34($sp)
/* 0EF0E4 7F0BA5B4 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0EF0E8 7F0BA5B8 03E00008 */  jr    $ra
/* 0EF0EC 7F0BA5BC 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif







