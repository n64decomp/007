#include <ultra64.h>
#include <bondconstants.h>
#include <boss.h>
#include <fr.h>
#include <music.h>
#include <os_extension.h>
#include <snd.h>
#include <random.h>
#include "watch.h"
#include "bondview.h"
#include "dyn.h"
#include "file.h"
#include "front.h"
#include "lvl_text.h"
#include "player.h"
#include "textrelated.h"
#include "unk_0A1DA0.h"
#include "unk_0C0A70.h"


#define WATCH_BACKGROUND_VERTEX_COUNT 30


// bss
Mtx gfx_background_8007B0A0;
Mtx gfx_background_8007B0E0;



u32 D_80040990 = 0;
u32 watch_screen_index = 0;
u32 controller_options_index = 0;
u32 game_options_index = 0;
// data
//D:800409A0
s32 mission_brief_index = BRIEF_INDEX_OBJECTIVES;
//D:800409A4
s32 D_800409A4 = 0;
//D:800409A8
s32 watch_item_is_actively_selected = 0;
//D:800409AC
s32 D_800409AC = 0;
//D:800409B0
s32 D_800409B0 = 0;
//D:800409B4
s32 D_800409B4 = 0;
//D:800409B8
s32 g_curWatchItemIndex = 0;
//D:800409BC
f32 D_800409BC = 0.0f;
//D:800409C0
s32 D_800409C0 = 0;
//D:800409C4
s32 D_800409C4 = 0;
//D:800409C8
f32 D_800409C8 = 0.0f;
//D:800409CC
f32 D_800409CC = 0.0f;
//D:800409D0
s32 D_800409D0 = -1;
//D:800409D4
f32 D_800409D4 = 0.0f;
//D:800409D8
s32 D_800409D8 = 8;
//D:800409DC
u16 D_800409DC[] = {
    /*1.1 honey*/    TEXT(LOPTIONS,0x9), /*weapon*/TEXT(LOPTIONS,0x3), /*action*/TEXT(LOPTIONS,0x2), /*fire*/TEXT(LOPTIONS,0x0),    /*aim*/TEXT(LOPTIONS,0x1),    /*aim*/TEXT(LOPTIONS,0x1), /*look*/TEXT(LOPTIONS,0x6), /*look*/TEXT(LOPTIONS,0x6), /*pause*/TEXT(LOPTIONS,0x4), /*move*/TEXT(LOPTIONS,0x5),
    /*1.2 solitaire*/TEXT(LOPTIONS,0xA), /*weapon*/TEXT(LOPTIONS,0x3), /*action*/TEXT(LOPTIONS,0x2), /*fire*/TEXT(LOPTIONS,0x0),    /*aim*/TEXT(LOPTIONS,0x1),    /*aim*/TEXT(LOPTIONS,0x1), /*move*/TEXT(LOPTIONS,0x5), /*move*/TEXT(LOPTIONS,0x5), /*pause*/TEXT(LOPTIONS,0x4), /*look*/TEXT(LOPTIONS,0x6),
    /*1.3 kissy*/    TEXT(LOPTIONS,0xB),   /*fire*/TEXT(LOPTIONS,0x0), /*action*/TEXT(LOPTIONS,0x2),  /*aim*/TEXT(LOPTIONS,0x1), /*weapon*/TEXT(LOPTIONS,0x3), /*weapon*/TEXT(LOPTIONS,0x3), /*look*/TEXT(LOPTIONS,0x6), /*look*/TEXT(LOPTIONS,0x6), /*pause*/TEXT(LOPTIONS,0x4), /*move*/TEXT(LOPTIONS,0x5),
    /*1.4 goodnight*/TEXT(LOPTIONS,0xC),   /*fire*/TEXT(LOPTIONS,0x0), /*action*/TEXT(LOPTIONS,0x2),  /*aim*/TEXT(LOPTIONS,0x1), /*weapon*/TEXT(LOPTIONS,0x3), /*weapon*/TEXT(LOPTIONS,0x3), /*move*/TEXT(LOPTIONS,0x5), /*move*/TEXT(LOPTIONS,0x5), /*pause*/TEXT(LOPTIONS,0x4), /*look*/TEXT(LOPTIONS,0x6),
    /*2.1 plenty*/   TEXT(LOPTIONS,0xD),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),     /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),
    /*2.2 galore*/   TEXT(LOPTIONS,0xE),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),     /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),
    /*2.3 domino*/   TEXT(LOPTIONS,0xF),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),     /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),
    /*2.4 goodhead*/ TEXT(LOPTIONS,0x10),     /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),      /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7),     /*?*/TEXT(LOPTIONS,0x7),    /*?*/TEXT(LOPTIONS,0x7)
};

struct game_options game_options_entries[] = {
    { {TEXT(LOPTIONS,0x11), TEXT(LOPTIONS,0x1C), TEXT(LOPTIONS,0x1B), 0}, 0}, //look up/down, reverse, upright
    { {TEXT(LOPTIONS,0x12), TEXT(LOPTIONS,0x1A), TEXT(LOPTIONS,0x19), 0}, 1}, //autoaim, off, on
    { {TEXT(LOPTIONS,0x14), TEXT(LOPTIONS,0x1E), TEXT(LOPTIONS,0x1D), 0}, 0}, //aim control, hold, toggle
    { {TEXT(LOPTIONS,0x15), TEXT(LOPTIONS,0x1A), TEXT(LOPTIONS,0x19), 0}, 1}, //sight on screen, off, on
    { {TEXT(LOPTIONS,0x13), TEXT(LOPTIONS,0x1A), TEXT(LOPTIONS,0x19), 0}, 1}, //look ahead, off, on
    { {TEXT(LOPTIONS,0x16), TEXT(LOPTIONS,0x1A), TEXT(LOPTIONS,0x19), 0}, 1}, //ammo on screen, off, on
    { {TEXT(LOPTIONS,0x17), TEXT(LOPTIONS,0x1F), TEXT(LOPTIONS,0x20), TEXT(LOPTIONS,0x21)}, 0}, //screen, full, wide, cinema
    { {TEXT(LOPTIONS,0x18), TEXT(LOPTIONS,0x22), TEXT(LOPTIONS,0x23), 0}, 0} //ratio, normal, 16:9
};

//D:80040ADC
u32 controlstick_lr_enabled = 0;
//D:80040AE0
u32 D_80040AE0 = 0;
//D:80040AE4
u32 D_80040AE4 = 0;
//D:80040AE8
f32 D_80040AE8 = 0.0f;
//D:80040AEC
f32 D_80040AEC = 0.0f;
//D:80040AF0
f32 D_80040AF0 = 45.0f;
//D:80040AF4
u32 D_80040AF4 = 0xFF00A0;
//D:80040AF8
u32 D_80040AF8 = 0xA;
//D:80040AFC
u32 D_80040AFC = 0xFF;

//D:80040B00
u32 D_80040B00 = 0xA;

//D:80040B04
s32 g_WatchBackgroundGreen = 0xE0;

//D:80040B08
u32 D_80040B08 = 0;

//D:80040B0C
u32 D_80040B0C = 0xFFA0;
//D:80040B10
u32 D_80040B10 = 0xF800;
//D:80040B14
f32 D_80040B14 = 0.0f;
//D:80040B18
f32 D_80040B18 = 0.0f;
//D:80040B1C
f32 D_80040B1C = 2.5f;
//D:80040B20
f32 D_80040B20 = 0.0f;
//D:80040B24
f32 D_80040B24 = 0.0f;
//D:80040B28
f32 D_80040B28 = 0.0f;
//D:80040B2C
u32 D_80040B2C = 0;
//D:80040B30
f32 D_80040B30 = 0.0f;
//D:80040B34
f32 D_80040B34 = 0.0f;
//D:80040B38
f32 D_80040B38 = 0.0f;
//D:80040B3C
u32 D_80040B3C = 0;
//D:80040B40
s32 D_80040B40 = 0;
//D:80040B44
u16 D_80040B44 = 0x1;
//D:80040B48
u32 D_80040B48 = 0x32;
//D:80040B4C
u32 D_80040B4C = 0x32;
//D:80040B50
u32 D_80040B50 = 0x32;
//D:80040B54
u32 D_80040B54 = 0x32;
//D:80040B58
u16 mTrack2Vol = 0x7FFF;

//D:80040B5C
f32 D_80040B5C = 0.0f;
//D:80040B60
f32 D_80040B60 = 200.0f;
//D:80040B64
f32 D_80040B64 = -200.0f;


//D:80040B68
f32 D_80040B68[] = {
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 
    -900.0f, 200.0f, -45.0f,
    715.0f, 200.0f, 393.0f,
    -875.0f, 200.0f, -210.0f,
    900.0f, 200.0f, -260.0f,
    900.0f, 200.0f, -160.0f,
    850.0f, 200.0f, -210.0f,
    950.0f, 200.0f, -210.0f,
    900.0f, 200.0f, 128.0f,
    900.0f, 200.0f, -45.0f,
    -820.0f, 200.0f, -389.0f,
    820.0f, 200.0f, -389.0f,
    -830.0f, 200.0f, 78.0f
};

//D:80040C44
f32 D_80040C44[] = {
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 
    0.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, -600.0f, 200.0f, 
    500.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, -600.0f, 200.0f, 
    240.0f, -600.0f, 200.0f, 
    110.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 
    2000.0f, -600.0f, 200.0f, 
    320.0f
};

//D:80040D20
f32 D_80040D20[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 0.0f, 
    0.0f, 0.0f, 0.0f, 0.0f, 
    2000.0f, 0.0f, 2000.0f, 2000.0f, 
    0.0f, 2000.0f, 600.0f, 200.0f, 
    500.0f, 2000.0f, 0.0f, 2000.0f, 
    2000.0f, 0.0f, 2000.0f, 2000.0f, 
    0.0f, 2000.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 2000.0f, 
    600.0f, 200.0f, 240.0f, 600.0f, 
    200.0f, 110.0f, 2000.0f, 0.0f, 
    2000.0f, 2000.0f, 0.0f, 2000.0f, 
    600.0f, 200.0f, 320.0f
};

//D:80040DFC
s32 D_80040DFC[] = {0x34, 0x2F, 0x2D, 0x2A, 0x28, 0x25, 0x25, 0x28, 0x2A, 0x2D, 0x2F, 0x34, 0x37, 0x40, 0xFFFFFFFF};

//D:80040E38
s32 D_80040E38 = 0x4B;
//D:80040E3C
s32 D_80040E3C = 0xFFFFFFFF;

//D:80040E40
s32 D_80040E40[] = {0x10E, 0x113, 0x116, 0x119, 0x11A, 0x11B, 0x11B, 0x11A, 0x119, 0x116, 0x113, 0x10E, 0x108, 0xFE, 0xFFFFFFFF};
//D:80040E7C
s32 D_80040E7C = 0;



// forward declarations

void set_page_rectangle_colors(s32 watch_screen_index, struct WatchVertex *arg2);
Gfx *draw_watch_mission_status_page(Gfx *gdl, Mtx *param_2);
Gfx *unused_draw_watch_inventory_page(Gfx *gdl, Mtx *param_2);
Gfx *draw_watch_inventory_page(Gfx *gdl, Mtx *param_2);
Gfx *draw_watch_control_options_page(Gfx *gdl, Mtx *param_2);
Gfx *draw_watch_game_options_page(Gfx *gdl, Mtx *param_2);
Gfx *draw_watch_mission_briefing_page(Gfx *gdl, Mtx *param_2);
Gfx *draw_background_health_and_armor_transitioning(Gfx *gdl, Mtx *param_2);
Gfx *draw_background_health_and_armor(Gfx *gdl, Mtx *arg1, s32 zoom_squish);
void sub_GAME_7F0A68D8(s32 *arg0);
void game_option_select_value(u32 *param_1, u32 param_2);

// end forward declarations



void nullsub_7F0A4860(void) 
{

}


void init_watch_at_start_of_stage(int stage)
{
    watch_screen_index = WATCH_INDEX_MISSION_STATUS;
    controller_options_index = CONTROLLER_OPTIONS_INDEX_STYLE;
    game_options_index = GAME_OPTIONS_INDEX_MUSIC;
    mission_brief_index = BRIEF_INDEX_OBJECTIVES;
    D_800409A4 = 0;
    watch_item_is_actively_selected = 0;
    D_800409AC = 0;
    D_800409B0 = 0;
    D_800409B4 = 0;
    g_curWatchItemIndex = 0;
    D_800409BC = 0.0f;
    D_800409C0 = 0;
    D_800409C4 = 0;
    D_800409C8 = 0.0f;
    D_800409CC = 0.0f;
    D_800409D0 = -1;
    D_800409D4 = 0.0f;

    if (j_text_trigger ? 1 : 0 && 1)
    {
    }

    g_CurrentPlayer->neg_vspacing_for_control_type_entry = 0;
    g_CurrentPlayer->cur_player_control_type_1 = 0;
    g_CurrentPlayer->cur_player_control_type_0 = 0;
    g_CurrentPlayer->cur_player_control_type_2 = 0.0f;
    g_CurrentPlayer->has_set_control_type_data = 1;
    D_800409D8 = 8;

    controlstick_lr_enabled = 0;
    D_80040AE0 = 0;
    D_80040AE4 = 0;
    D_80040AE8 = 0.0f;
    D_80040AEC = 0.0f;
    D_80040AF0 = 45.0f;
    D_80040AF4 = 0xff00a0;
    D_80040AF8 = 10;
    D_80040AFC = 0xff;
    D_80040B00 = 10;
    g_WatchBackgroundGreen = 0xe0;
    D_80040B08 = 0;
    D_80040B0C = 0xffa0;
    D_80040B10 = 0xf800;
    D_80040B14 = 0.0f;
    D_80040B18 = 0.0f;
    D_80040B1C = 2.5f;
    D_80040B20 = 0.0f;
    D_80040B24 = 0.0f;
    D_80040B28 = 0.0f;
    D_80040B2C = 0;
    D_80040B30 = 0.0f;
    D_80040B34 = 0.0f;
    D_80040B38 = 0.0f;
    D_80040B3C = 0;
    D_80040B40 = 0;
    D_80040B44 = 1;
    D_80040B48 = 0x32;
    D_80040B4C = 0x32;
    D_80040B50 = 0x32;
    D_80040B54 = 0x32;
    fileLoadSaveSettingsForSelectedFolder(stage);
    mission_failed_or_aborted = FALSE;
}



void controller_deadzone_related(void)
{
    if (10 < joyGetStickX(PLAYER_1))
    {
        D_80040B50 = D_80040B50 + 1;
    }
    if (joyGetStickX(PLAYER_1) < -10)
    {
        D_80040B50 = D_80040B50 + -1;
    }
    if (10 < joyGetStickY(PLAYER_1))
    {
        D_80040B54 = D_80040B54 + -1;
    }
    if (joyGetStickY(PLAYER_1) < -10)
    {
        D_80040B54 = D_80040B54 + 1;
    }
}





#ifdef NONMATCHING
//code seems to match, can't seem to get data lined up correctly
Gfx * sub_GAME_7F0A4B40(Gfx *DL)
{
    u8 buffer [0x16];
    int *fontTBL1;
    int *fontTBL2;
    
    u32 y;
    u32 x;
    
    if (10 < joyGetStickX(PLAYER_1)) {
        D_80040B48 += 1;
    }

    if (joyGetStickX(PLAYER_1) < -10) {
        D_80040B48 -= 1;
    }

    if (10 < joyGetStickY(PLAYER_1)) {
        D_80040B4C -= 1;
    }

    if (joyGetStickY(PLAYER_1) < -10) {
        D_80040B4C += 1;
    }
    gDPSetRenderMode(DL++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(DL++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(DL++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
    gDPFillRectangle(DL++, D_80040B48, D_80040B4C, D_80040B48+1, D_80040B4C+1);

    fontTBL1 = ptrFirstFontTableSmall;
    fontTBL2 = ptrSecondFontTableSmall;
    sprintf(buffer,"%d, %d\n",D_80040B48,D_80040B4C);

    DL = microcode_constructor(DL++);
    sub_GAME_7F0AE98C(x,y,buffer,fontTBL2,fontTBL1,0);
    DL = en_text_write_stuff(DL,&D_80040B48,&D_80040B4C,buffer,fontTBL2,fontTBL1, 0xff0000ff,y,x,0,0);
    D_80040B4C = (D_80040B4C - fontTBL2[0x224]) + 1;
    return DL;
}
#else
// rodata
//D:80057760
const char aDD[] =  "%d, %d\n";

GLOBAL_ASM(
.text
glabel sub_GAME_7F0A4B40
/* 0D9670 7F0A4B40 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0D9674 7F0A4B44 AFB00038 */  sw    $s0, 0x38($sp)
/* 0D9678 7F0A4B48 00808025 */  move  $s0, $a0
/* 0D967C 7F0A4B4C AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D9680 7F0A4B50 AFB20040 */  sw    $s2, 0x40($sp)
/* 0D9684 7F0A4B54 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0D9688 7F0A4B58 0C00303B */  jal   joyGetStickX
/* 0D968C 7F0A4B5C 00002025 */   move  $a0, $zero
/* 0D9690 7F0A4B60 2841000B */  slti  $at, $v0, 0xb
/* 0D9694 7F0A4B64 14200006 */  bnez  $at, .L7F0A4B80
/* 0D9698 7F0A4B68 00002025 */   move  $a0, $zero
/* 0D969C 7F0A4B6C 3C128004 */  lui   $s2, %hi(D_80040B48)
/* 0D96A0 7F0A4B70 26520B48 */  addiu $s2, %lo(D_80040B48) # addiu $s2, $s2, 0xb48
/* 0D96A4 7F0A4B74 8E4E0000 */  lw    $t6, ($s2)
/* 0D96A8 7F0A4B78 25CF0001 */  addiu $t7, $t6, 1
/* 0D96AC 7F0A4B7C AE4F0000 */  sw    $t7, ($s2)
.L7F0A4B80:
/* 0D96B0 7F0A4B80 3C128004 */  lui   $s2, %hi(D_80040B48)
/* 0D96B4 7F0A4B84 0C00303B */  jal   joyGetStickX
/* 0D96B8 7F0A4B88 26520B48 */   addiu $s2, %lo(D_80040B48) # addiu $s2, $s2, 0xb48
/* 0D96BC 7F0A4B8C 2841FFF6 */  slti  $at, $v0, -0xa
/* 0D96C0 7F0A4B90 10200004 */  beqz  $at, .L7F0A4BA4
/* 0D96C4 7F0A4B94 00000000 */   nop
/* 0D96C8 7F0A4B98 8E580000 */  lw    $t8, ($s2)
/* 0D96CC 7F0A4B9C 2719FFFF */  addiu $t9, $t8, -1
/* 0D96D0 7F0A4BA0 AE590000 */  sw    $t9, ($s2)
.L7F0A4BA4:
/* 0D96D4 7F0A4BA4 0C00307F */  jal   joyGetStickY
/* 0D96D8 7F0A4BA8 00002025 */   move  $a0, $zero
/* 0D96DC 7F0A4BAC 2841000B */  slti  $at, $v0, 0xb
/* 0D96E0 7F0A4BB0 14200006 */  bnez  $at, .L7F0A4BCC
/* 0D96E4 7F0A4BB4 00002025 */   move  $a0, $zero
/* 0D96E8 7F0A4BB8 3C118004 */  lui   $s1, %hi(D_80040B4C)
/* 0D96EC 7F0A4BBC 26310B4C */  addiu $s1, %lo(D_80040B4C) # addiu $s1, $s1, 0xb4c
/* 0D96F0 7F0A4BC0 8E2A0000 */  lw    $t2, ($s1)
/* 0D96F4 7F0A4BC4 254BFFFF */  addiu $t3, $t2, -1
/* 0D96F8 7F0A4BC8 AE2B0000 */  sw    $t3, ($s1)
.L7F0A4BCC:
/* 0D96FC 7F0A4BCC 3C118004 */  lui   $s1, %hi(D_80040B4C)
/* 0D9700 7F0A4BD0 0C00307F */  jal   joyGetStickY
/* 0D9704 7F0A4BD4 26310B4C */   addiu $s1, %lo(D_80040B4C) # addiu $s1, $s1, 0xb4c
/* 0D9708 7F0A4BD8 2841FFF6 */  slti  $at, $v0, -0xa
/* 0D970C 7F0A4BDC 10200004 */  beqz  $at, .L7F0A4BF0
/* 0D9710 7F0A4BE0 02001025 */   move  $v0, $s0
/* 0D9714 7F0A4BE4 8E2C0000 */  lw    $t4, ($s1)
/* 0D9718 7F0A4BE8 258D0001 */  addiu $t5, $t4, 1
/* 0D971C 7F0A4BEC AE2D0000 */  sw    $t5, ($s1)
.L7F0A4BF0:
/* 0D9720 7F0A4BF0 26100008 */  addiu $s0, $s0, 8
/* 0D9724 7F0A4BF4 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0D9728 7F0A4BF8 3C0F0050 */  lui   $t7, (0x00504240 >> 16) # lui $t7, 0x50
/* 0D972C 7F0A4BFC 35EF4240 */  ori   $t7, (0x00504240 & 0xFFFF) # ori $t7, $t7, 0x4240
/* 0D9730 7F0A4C00 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0D9734 7F0A4C04 02001825 */  move  $v1, $s0
/* 0D9738 7F0A4C08 AC4E0000 */  sw    $t6, ($v0)
/* 0D973C 7F0A4C0C AC4F0004 */  sw    $t7, 4($v0)
/* 0D9740 7F0A4C10 3C18FCFF */  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
/* 0D9744 7F0A4C14 3C19FFFD */  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
/* 0D9748 7F0A4C18 3739F6FB */  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
/* 0D974C 7F0A4C1C 3718FFFF */  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
/* 0D9750 7F0A4C20 26100008 */  addiu $s0, $s0, 8
/* 0D9754 7F0A4C24 AC780000 */  sw    $t8, ($v1)
/* 0D9758 7F0A4C28 AC790004 */  sw    $t9, 4($v1)
/* 0D975C 7F0A4C2C 02004025 */  move  $t0, $s0
/* 0D9760 7F0A4C30 3C0BFF00 */  lui   $t3, (0xFF0000FF >> 16) # lui $t3, 0xff00
/* 0D9764 7F0A4C34 356B00FF */  ori   $t3, (0xFF0000FF & 0xFFFF) # ori $t3, $t3, 0xff
/* 0D9768 7F0A4C38 3C0AFA00 */  lui   $t2, 0xfa00
/* 0D976C 7F0A4C3C AD0A0000 */  sw    $t2, ($t0)
/* 0D9770 7F0A4C40 AD0B0004 */  sw    $t3, 4($t0)
/* 0D9774 7F0A4C44 8E4C0000 */  lw    $t4, ($s2)
/* 0D9778 7F0A4C48 8E390000 */  lw    $t9, ($s1)
/* 0D977C 7F0A4C4C 3C01F600 */  lui   $at, 0xf600
/* 0D9780 7F0A4C50 258D0001 */  addiu $t5, $t4, 1
/* 0D9784 7F0A4C54 31AE03FF */  andi  $t6, $t5, 0x3ff
/* 0D9788 7F0A4C58 272A0001 */  addiu $t2, $t9, 1
/* 0D978C 7F0A4C5C 314B03FF */  andi  $t3, $t2, 0x3ff
/* 0D9790 7F0A4C60 000E7B80 */  sll   $t7, $t6, 0xe
/* 0D9794 7F0A4C64 26100008 */  addiu $s0, $s0, 8
/* 0D9798 7F0A4C68 01E1C025 */  or    $t8, $t7, $at
/* 0D979C 7F0A4C6C 000B6080 */  sll   $t4, $t3, 2
/* 0D97A0 7F0A4C70 030C6825 */  or    $t5, $t8, $t4
/* 0D97A4 7F0A4C74 02004825 */  move  $t1, $s0
/* 0D97A8 7F0A4C78 AD2D0000 */  sw    $t5, ($t1)
/* 0D97AC 7F0A4C7C 8E2A0000 */  lw    $t2, ($s1)
/* 0D97B0 7F0A4C80 8E4E0000 */  lw    $t6, ($s2)
/* 0D97B4 7F0A4C84 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall)
/* 0D97B8 7F0A4C88 314B03FF */  andi  $t3, $t2, 0x3ff
/* 0D97BC 7F0A4C8C 31CF03FF */  andi  $t7, $t6, 0x3ff
/* 0D97C0 7F0A4C90 000FCB80 */  sll   $t9, $t7, 0xe
/* 0D97C4 7F0A4C94 000BC080 */  sll   $t8, $t3, 2
/* 0D97C8 7F0A4C98 03386025 */  or    $t4, $t9, $t8
/* 0D97CC 7F0A4C9C AD2C0004 */  sw    $t4, 4($t1)
/* 0D97D0 7F0A4CA0 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall)
/* 0D97D4 7F0A4CA4 8DAD0EAC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0D97D8 7F0A4CA8 8DCE0EB0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0D97DC 7F0A4CAC 3C058005 */  lui   $a1, %hi(aDD)
/* 0D97E0 7F0A4CB0 26100008 */  addiu $s0, $s0, 8
/* 0D97E4 7F0A4CB4 24A57760 */  addiu $a1, %lo(aDD) # addiu $a1, $a1, 0x7760
/* 0D97E8 7F0A4CB8 8E270000 */  lw    $a3, ($s1)
/* 0D97EC 7F0A4CBC 8E460000 */  lw    $a2, ($s2)
/* 0D97F0 7F0A4CC0 27A4005C */  addiu $a0, $sp, 0x5c
/* 0D97F4 7F0A4CC4 AFAD0058 */  sw    $t5, 0x58($sp)
/* 0D97F8 7F0A4CC8 0C002B25 */  jal   sprintf
/* 0D97FC 7F0A4CCC AFAE0054 */   sw    $t6, 0x54($sp)
/* 0D9800 7F0A4CD0 0FC2B366 */  jal   microcode_constructor
/* 0D9804 7F0A4CD4 02002025 */   move  $a0, $s0
/* 0D9808 7F0A4CD8 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0D980C 7F0A4CDC 00408025 */  move  $s0, $v0
/* 0D9810 7F0A4CE0 27A4004C */  addiu $a0, $sp, 0x4c
/* 0D9814 7F0A4CE4 27A50050 */  addiu $a1, $sp, 0x50
/* 0D9818 7F0A4CE8 27A6005C */  addiu $a2, $sp, 0x5c
/* 0D981C 7F0A4CEC 8FA70054 */  lw    $a3, 0x54($sp)
/* 0D9820 7F0A4CF0 AFA00014 */  sw    $zero, 0x14($sp)
/* 0D9824 7F0A4CF4 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0D9828 7F0A4CF8 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0D982C 7F0A4CFC 8FAA0054 */  lw    $t2, 0x54($sp)
/* 0D9830 7F0A4D00 8FAB0058 */  lw    $t3, 0x58($sp)
/* 0D9834 7F0A4D04 8FB80050 */  lw    $t8, 0x50($sp)
/* 0D9838 7F0A4D08 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0D983C 7F0A4D0C 3C19FF00 */  lui   $t9, (0xFF0000FF >> 16) # lui $t9, 0xff00
/* 0D9840 7F0A4D10 373900FF */  ori   $t9, (0xFF0000FF & 0xFFFF) # ori $t9, $t9, 0xff
/* 0D9844 7F0A4D14 AFB90018 */  sw    $t9, 0x18($sp)
/* 0D9848 7F0A4D18 02002025 */  move  $a0, $s0
/* 0D984C 7F0A4D1C 02402825 */  move  $a1, $s2
/* 0D9850 7F0A4D20 02203025 */  move  $a2, $s1
/* 0D9854 7F0A4D24 27A7005C */  addiu $a3, $sp, 0x5c
/* 0D9858 7F0A4D28 AFA00024 */  sw    $zero, 0x24($sp)
/* 0D985C 7F0A4D2C AFA00028 */  sw    $zero, 0x28($sp)
/* 0D9860 7F0A4D30 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0D9864 7F0A4D34 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0D9868 7F0A4D38 AFB8001C */  sw    $t8, 0x1c($sp)
/* 0D986C 7F0A4D3C 0FC2B6AF */  jal   en_text_write_stuff
/* 0D9870 7F0A4D40 AFAC0020 */   sw    $t4, 0x20($sp)
/* 0D9874 7F0A4D44 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0D9878 7F0A4D48 8E2D0000 */  lw    $t5, ($s1)
/* 0D987C 7F0A4D4C 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D9880 7F0A4D50 8DCF0890 */  lw    $t7, 0x890($t6)
/* 0D9884 7F0A4D54 8FB00038 */  lw    $s0, 0x38($sp)
/* 0D9888 7F0A4D58 8FB20040 */  lw    $s2, 0x40($sp)
/* 0D988C 7F0A4D5C 01AF5023 */  subu  $t2, $t5, $t7
/* 0D9890 7F0A4D60 254B0001 */  addiu $t3, $t2, 1
/* 0D9894 7F0A4D64 AE2B0000 */  sw    $t3, ($s1)
/* 0D9898 7F0A4D68 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0D989C 7F0A4D6C 03E00008 */  jr    $ra
/* 0D98A0 7F0A4D70 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif






u32 controllerCheckDualControllerTypesAllowed(void)
{
    if (joyGetControllerCount() >= 2)
    {
        if (cur_player_get_control_type() >= 4)
        {
            return 1;
        }
    }
    return 0;
}

int cur_player_get_control_type(void){
  return g_CurrentPlayer->cur_player_control_type_0;
}


void cur_player_set_control_type(int type)
{
    int langsize;

    g_CurrentPlayer->cur_player_control_type_0 = type;
    g_CurrentPlayer->cur_player_control_type_1 = type;
    g_CurrentPlayer->cur_player_control_type_2 = (float)type;

    langsize = j_text_trigger ? 14 : 10;

    g_CurrentPlayer->neg_vspacing_for_control_type_entry = -(langsize * type);
    g_CurrentPlayer->has_set_control_type_data = 1;

}

u32 get_cur_player_look_vertical_inverted(void)
{
    return game_options_entries[PLAYER_OPTION_LOOK].current_value;
}

void set_cur_player_look_vertical_inverted(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_LOOK].current_value = param_1;
}

s32 cur_player_get_autoaim(void)
{
    return game_options_entries[PLAYER_OPTION_AUTOAIM].current_value;
}

void cur_player_set_autoaim(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_AUTOAIM].current_value = param_1;
}

u32 cur_player_get_lookahead(void)
{
    return game_options_entries[PLAYER_OPTION_LOOKAHEAD].current_value;
}

void cur_player_set_lookahead(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_LOOKAHEAD].current_value = param_1;
}

u32 cur_player_get_aim_control(void)
{
    return game_options_entries[PLAYER_OPTION_AIM].current_value;
}

void cur_player_set_aim_control(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_AIM].current_value = param_1;
}

u32 cur_player_get_sight_onscreen_control(void)
{
    return game_options_entries[PLAYER_OPTION_SIGHT].current_value;
}
void cur_player_set_sight_onscreen_control(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_SIGHT].current_value = param_1;
}

u32 cur_player_get_ammo_onscreen_setting(void)
{
    return game_options_entries[PLAYER_OPTION_AMMODISPLAY].current_value;
}
void cur_player_set_ammo_onscreen_setting(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_AMMODISPLAY].current_value = param_1;
}

u32 cur_player_get_screen_setting(void)
{
    return game_options_entries[PLAYER_OPTION_SCREEN].current_value;
}
void cur_player_set_screen_setting(u32 param_1)
{
    game_options_entries[PLAYER_OPTION_SCREEN].current_value = param_1;
}

SCREEN_RATIO_OPTION get_screen_ratio(void)
{
    return game_options_entries[PLAYER_OPTION_RATIO].current_value;
}

void set_screen_ratio(SCREEN_RATIO_OPTION ratio_option)
{
    game_options_entries[PLAYER_OPTION_RATIO].current_value = ratio_option;
}



void watch_play_beep_sound(void) {

    if (watch_item_is_actively_selected == 1) {
        watch_item_is_actively_selected = 0;

    } else {
        watch_item_is_actively_selected = 1;
        sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, 0);
    }
}

void reset_watch_item_is_actively_selected(void){
  watch_item_is_actively_selected = 0;
}

u32 is_holding_greater_than_2E_left_on_stick(void)
{
    return (joyGetStickX(PLAYER_1) < -0x2d);
}

u32 is_holding_greater_than_2E_right_on_stick(void)
{
    return ((joyGetStickX(PLAYER_1) < 0x2e) ^ 1);
}

u32 get_controlstick_lr_enabled(void) {
  return controlstick_lr_enabled;
}

void set_controlstick_lr_disabled(void) {
  controlstick_lr_enabled = 0;
}

s32 sub_GAME_7F0A4FB0(void)
{
    return is_holding_greater_than_2E_left_on_stick() && get_controlstick_lr_enabled();
}

s32 sub_GAME_7F0A4FEC(void)
{
    return is_holding_greater_than_2E_right_on_stick() && get_controlstick_lr_enabled();
}

u32 is_holding_greater_than_2E_up_on_stick(void)
{
  return (joyGetStickY(PLAYER_1) < 0x2e) ^ 1;
}

u32 is_holding_greater_than_2E_down_on_stick(void)
{
  return (joyGetStickY(PLAYER_1) < -0x2d);
}

u32 get_D_80040AE0(void)
{
  return D_80040AE0;
}

void set_D_80040AE0_0(void)
{
  D_80040AE0 = 0;
}

s32 sub_GAME_7F0A5088(void)
{
    return is_holding_greater_than_2E_up_on_stick() && get_D_80040AE0();
}

s32 sub_GAME_7F0A50C4(void)
{
    return is_holding_greater_than_2E_down_on_stick() && get_D_80040AE0();
}

u32 is_holding_less_than_10_up_on_stick(void)
{
  return (joyGetStickY(PLAYER_1) < 0x10) ^ 1;
}

u32 is_holding_less_than_10_down_on_stick(void)
{
  return (joyGetStickY(PLAYER_1) < -0xf);
}

u32 get_D_80040AE4(void) {
  return D_80040AE4;
}

void set_D_80040AE4_0(void) {
  D_80040AE4 = 0;
}


s32 sub_GAME_7F0A5160(void)
{
    return is_holding_less_than_10_up_on_stick() && get_D_80040AE4() == 0;
}

s32 sub_GAME_7F0A519C(void)
{
    return is_holding_less_than_10_down_on_stick() && get_D_80040AE4() == 0;
}

void sub_GAME_7F0A51D8(void)
{
    g_WatchBackgroundGreen = 0x80;
    sndPlaySfx(g_musicSfxBufferPtr, WATCH_STATIC_SFX, NULL);
    return;
}

void sub_GAME_7F0A5210(void)
{
    set_controlstick_lr_disabled();
    sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, NULL);
    if ((D_80040B10 << 0x10) < randomGetNext()) {
        sub_GAME_7F0A51D8();
    }
    return;
}

// initial pause screen: WATCH_INDEX_MISSION_STATUS
void watch_screen0_navigation(void)
{
    s32 goto_watch_screen_index_4;
    s32 goto_watch_screen_index_1;

    if (watch_item_is_actively_selected == 0)
    {
        goto_watch_screen_index_4 = FALSE;
        goto_watch_screen_index_1 = FALSE;

        if (get_debug_gunwatchpos_flag() == 0)
        {
            if (joyGetButtonsPressedThisFrame(PLAYER_1, L_TRIG|L_CBUTTONS))
            {
                goto_watch_screen_index_4 = TRUE;
            }
            if (joyGetButtonsPressedThisFrame(PLAYER_1, R_TRIG|R_CBUTTONS))
            {
                goto_watch_screen_index_1 = TRUE;
            }
        }

        if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_JPAD)) || (sub_GAME_7F0A4FB0()))
        {
            goto_watch_screen_index_4 = TRUE;
        }

        if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_JPAD)) || (sub_GAME_7F0A4FEC()))
        {
            goto_watch_screen_index_1 = TRUE;
        }

        if (goto_watch_screen_index_4)
        {
            watch_screen_index = WATCH_INDEX_MISSION_BRIEFING;
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM1, 15.0f);
        }

        if (goto_watch_screen_index_1)
        {
            watch_screen_index = WATCH_INDEX_INVENTORY;
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM1, 15.0f);
            return;
        }
    }
    else if ((D_800409A4) && (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON)))
    {
        D_800409A4 = 0;
        set_missionstate(MISSION_STATE_0);
        bossRunTitleStage();
        mission_failed_or_aborted = 1;
        deleteCurrentSelectedFolder();
    }
}

// pause screen: WATCH_INDEX_INVENTORY
void watch_screen1_navigation(void)
{
    s32 goto_watch_screen_index_0;
    s32 goto_watch_screen_index_2;

    if (watch_item_is_actively_selected == 0)
    {
        goto_watch_screen_index_0 = FALSE;
        goto_watch_screen_index_2 = FALSE;

        if (get_debug_gunwatchpos_flag() == FALSE)
        {
            if (joyGetButtonsPressedThisFrame(PLAYER_1, L_TRIG|L_CBUTTONS))
            {
                goto_watch_screen_index_0 = TRUE;
            }
            if (joyGetButtonsPressedThisFrame(PLAYER_1, R_TRIG|R_CBUTTONS))
            {
                goto_watch_screen_index_2 = TRUE;
            }
        }

        if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_JPAD)) || (sub_GAME_7F0A4FB0()))
        {
            goto_watch_screen_index_0 = TRUE;
        }

        if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_JPAD)) || (sub_GAME_7F0A4FEC()))
        {
            goto_watch_screen_index_2 = TRUE;
        }

        if (goto_watch_screen_index_0)
        {
            watch_screen_index = WATCH_INDEX_MISSION_STATUS;
            zero_D_800409A4();
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM2, 15.0f);

        }

        if (goto_watch_screen_index_2)
        {
            watch_screen_index = WATCH_INDEX_CONTROL_OPTIONS;
            set_controlstick_lr_disabled();
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM3, 15.0f);
        }
    }
}


void unused_watch_screen_navigation(void) {

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD)) || (sub_GAME_7F0A4FB0()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            watch_screen_index = WATCH_INDEX_INVENTORY;
            set_controlstick_lr_disabled();
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD)) || (sub_GAME_7F0A4FEC()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            watch_screen_index = WATCH_INDEX_CONTROL_OPTIONS;
            reset_controller_options_index();
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM3, 15.0f);
        }
    }
}

// WATCH_INDEX_CONTROL_OPTIONS
void watch_screen2_navigation(void) {

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD)) || (sub_GAME_7F0A4FB0()))
    {
        if ((joyGetButtons(PLAYER_1, Z_TRIG) == 0) && (watch_item_is_actively_selected == 0))
        {
            watch_screen_index = WATCH_INDEX_INVENTORY;
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM1, 15.0f);
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD)) || (sub_GAME_7F0A4FEC()))
    {
        if ((joyGetButtons(PLAYER_1, Z_TRIG) == 0) && (watch_item_is_actively_selected == 0))
        {
            watch_screen_index = WATCH_INDEX_GAME_OPTIONS;
            reset_game_options_index();
            set_controlstick_lr_disabled();
        }
    }
}

// WATCH_INDEX_GAME_OPTIONS
void watch_screen3_navigation(void) {

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD)) || (sub_GAME_7F0A4FB0()))
    {
        if ((joyGetButtons(PLAYER_1, Z_TRIG) == 0) && (watch_item_is_actively_selected == 0))
        {
            watch_screen_index = WATCH_INDEX_CONTROL_OPTIONS;
            reset_controller_options_index();
            set_controlstick_lr_disabled();
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD)) || (sub_GAME_7F0A4FEC()))
    {
        if ((joyGetButtons(PLAYER_1, Z_TRIG) == 0) && (watch_item_is_actively_selected == 0))
        {
            watch_screen_index = WATCH_INDEX_MISSION_BRIEFING;
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM1, 15.0f);
        }
    }
}

// WATCH_INDEX_MISSION_BRIEFING
void watch_screen4_navigation(void) {

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD)) || (sub_GAME_7F0A4FB0()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            watch_screen_index = WATCH_INDEX_GAME_OPTIONS;
            reset_game_options_index();
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM3, 15.0f);
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD)) || (sub_GAME_7F0A4FEC()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            watch_screen_index = WATCH_INDEX_MISSION_STATUS;
            zero_D_800409A4();
            sub_GAME_7F0A5210();
            trigger_watch_zoom(WATCHZOOM2, 15.0f);
        }
    }
}


void controller_options_controlstyle_navigation(void)
{
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD)) || (sub_GAME_7F0A5088()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            controller_options_index = CONTROLLER_OPTIONS_INDEX_INPUTS;
            set_D_80040AE0_0();
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD)) || (sub_GAME_7F0A50C4()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            controller_options_index = CONTROLLER_OPTIONS_INDEX_INPUTS;
            set_D_80040AE0_0();
        }
    }
}

void controller_options_inputs_navigation(void)
{
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD)) || (sub_GAME_7F0A5088()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            controller_options_index = CONTROLLER_OPTIONS_INDEX_STYLE;
            set_D_80040AE0_0();
            return;
        }
    }
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD)) || (sub_GAME_7F0A50C4()))
    {
        if (watch_item_is_actively_selected == 0)
        {
            controller_options_index = CONTROLLER_OPTIONS_INDEX_STYLE;
            set_D_80040AE0_0();
        }
    }
}

void sub_GAME_7F0A5998(void)
{
    s32 aux;

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD)) || (sub_GAME_7F0A5088()))
    {
        game_options_index = game_options_index - 1;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
    else if ((joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD)) || (sub_GAME_7F0A50C4()))
    {
        game_options_index = game_options_index + 1;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }

    aux = game_options_index;

    if (aux >= 10)
    {
        game_options_index = GAME_OPTIONS_INDEX_MUSIC;
        return;
    }

    if (aux < 0)
    {
        game_options_index = GAME_OPTIONS_INDEX_RATIO;
    }
}

void game_options_music_volume_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        game_options_index = GAME_OPTIONS_INDEX_RATIO;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        game_options_index = GAME_OPTIONS_INDEX_FX;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}

void game_options_fx_volume_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        game_options_index = GAME_OPTIONS_INDEX_MUSIC;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        game_options_index = GAME_OPTIONS_INDEX_LOOK_UPDOWN;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}


#ifdef NONMATCHING
//logically this is close, likely just finish reordering the if logic
void sub_GAME_7F0A5B80(void)
{
    f32 fVar1;
    int invItems;
    int watchDebugFlag;
    
    invItems = bondinvCountTotalItemsInInv();
    watchDebugFlag = get_debug_gunwatchpos_flag();
    if (watchDebugFlag == 0)
    {    
        if ((joyGetButtonsPressedThisFrame(PLAYER_1,U_CBUTTONS|U_JPAD) != 0) && (joyGetStickY(PLAYER_1) >= 0x47))
        {
            if ((D_800409BC > 0) && (watch_item_is_actively_selected == 0))
            {
                D_800409BC -= 1.0f;
            }
        }
        else
        {
            if ((((joyGetButtonsPressedThisFrame(PLAYER_1,D_CBUTTONS|D_JPAD) != 0) || (joyGetStickY(PLAYER_1) < -0x46)) && (D_800409BC < invItems - 1)) && (watch_item_is_actively_selected == 0))
            {
                D_800409BC += 1.0f;
            }
        }
        

        if (joyGetButtons(PLAYER_1,U_CBUTTONS|U_JPAD) != 0)
        {
            if ((0 < D_800409BC) && (watch_item_is_actively_selected == 0))
            {
                D_800409BC -= 0.1f;
            }
        }
        else
        {
            if (((joyGetButtons(PLAYER_1,D_CBUTTONS|D_JPAD) != 0) && (D_800409BC < invItems + -1)) && (watch_item_is_actively_selected == 0))
            {
                D_800409BC += 0.1f;
            }
        }
    }
    


    if ((joyGetStickY(PLAYER_1) >= 0x1F) && (joyGetStickY(PLAYER_1) < 0x46) && (g_curWatchItemIndex > 0) && (watch_item_is_actively_selected == 0))
    {
        D_800409BC -= joyGetStickY(PLAYER_1) / 300.0f;
    }
    else if ((joyGetStickY(PLAYER_1) < -0x1E) && (joyGetStickY(PLAYER_1) >= -0x45) && (D_800409BC < (invItems - 1)) && (watch_item_is_actively_selected == 0))
    {
        D_800409BC -= joyGetStickY(PLAYER_1) / 300.0f;
    }


    if ((sub_GAME_7F0A5160() != 0) && (g_curWatchItemIndex > 0) && (watch_item_is_actively_selected == 0))
    {
        D_800409BC -= 1.0f;
    }
    else if ((sub_GAME_7F0A519C() != 0) && (g_curWatchItemIndex < (invItems - 1)) && (watch_item_is_actively_selected == 0))
    {
        D_800409BC += 1.0f;
    }



    if ((is_holding_less_than_10_up_on_stick() == 0) && (is_holding_less_than_10_down_on_stick() == 0))
    {
        D_80040AE4 = 0;
    }
    else
    {
        D_80040AE4 = 1;
    }
    fVar1 = invItems - 0.5f;
    if (D_800409BC <= invItems - 0.5f)
    {
        fVar1 = D_800409BC;
    }
    D_800409BC = fVar1;
    if (D_800409BC < -0.5f)
    {
        D_800409BC = -0.5f;
    }
    g_curWatchItemIndex = D_800409BC;
    if (j_text_trigger == 0)
    {
        invItems = 0xc;
        watchDebugFlag = 0xc;
    }
    else {
        invItems = 0xe;
        watchDebugFlag = 0xe;
    }
    D_800409B4 = watchDebugFlag * 2 + -g_curWatchItemIndex * invItems;
    if (D_800409B4 < D_800409B0) {
        D_800409B0 = (D_800409B0 - (D_800409B0 - D_800409B4) / 3) + -1;
        D_800409C0 = 0;
    }
    else {
        if (D_800409B0 < D_800409B4) {
            D_800409B0 = D_800409B0 + (D_800409B4 - D_800409B0) / 3 + 1;
            D_800409C0 = 0;
        }
        else {
            D_800409C0 = 1;
        }
    }
    if ((D_800409BC <= g_curWatchItemIndex + 0.55f) || (joyGetButtons(PLAYER_1,ANY_BUTTON) != 0)) 
    {
        if ((D_800409BC <= g_curWatchItemIndex + 0.45f) && (joyGetButtons(PLAYER_1,ANY_BUTTON) == 0)) 
        {
            D_800409BC = D_800409BC + 0.1f;
        }
    }
    else {
        D_800409BC = D_800409BC - 0.1f;
    }
    return;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005847C
.word 0x3dcccccd /*0.1*/
glabel D_80058480
.word 0x3dcccccd /*0.1*/
glabel D_80058484
.word 0x3f0ccccd /*0.55000001*/
glabel D_80058488
.word 0x3dcccccd /*0.1*/
glabel D_8005848C
.word 0x3ee66666 /*0.44999999*/
glabel D_80058490
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F0A5B80
/* 0DA6B0 7F0A5B80 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DA6B4 7F0A5B84 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DA6B8 7F0A5B88 0FC2340E */  jal   bondinvCountTotalItemsInInv
/* 0DA6BC 7F0A5B8C 00000000 */   nop
/* 0DA6C0 7F0A5B90 0FC24415 */  jal   get_debug_gunwatchpos_flag
/* 0DA6C4 7F0A5B94 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0DA6C8 7F0A5B98 14400067 */  bnez  $v0, .L7F0A5D38
/* 0DA6CC 7F0A5B9C 00002025 */   move  $a0, $zero
/* 0DA6D0 7F0A5BA0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0DA6D4 7F0A5BA4 24050808 */   li    $a1, 2056
/* 0DA6D8 7F0A5BA8 14400005 */  bnez  $v0, .L7F0A5BC0
/* 0DA6DC 7F0A5BAC 00000000 */   nop
/* 0DA6E0 7F0A5BB0 0C00307F */  jal   joyGetStickY
/* 0DA6E4 7F0A5BB4 00002025 */   move  $a0, $zero
/* 0DA6E8 7F0A5BB8 28410047 */  slti  $at, $v0, 0x47
/* 0DA6EC 7F0A5BBC 14200012 */  bnez  $at, .L7F0A5C08
.L7F0A5BC0:
/* 0DA6F0 7F0A5BC0 3C068004 */   lui   $a2, %hi(D_800409BC)
/* 0DA6F4 7F0A5BC4 24C609BC */  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA6F8 7F0A5BC8 C4C00000 */  lwc1  $f0, ($a2)
/* 0DA6FC 7F0A5BCC 3C188004 */  lui   $t8, %hi(watch_item_is_actively_selected)
/* 0DA700 7F0A5BD0 4600010D */  trunc.w.s $f4, $f0
/* 0DA704 7F0A5BD4 440F2000 */  mfc1  $t7, $f4
/* 0DA708 7F0A5BD8 00000000 */  nop
/* 0DA70C 7F0A5BDC 59E0002B */  blezl $t7, .L7F0A5C8C
/* 0DA710 7F0A5BE0 00002025 */   move  $a0, $zero
/* 0DA714 7F0A5BE4 8F1809A8 */  lw    $t8, %lo(watch_item_is_actively_selected)($t8)
/* 0DA718 7F0A5BE8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA71C 7F0A5BEC 57000027 */  bnezl $t8, .L7F0A5C8C
/* 0DA720 7F0A5BF0 00002025 */   move  $a0, $zero
/* 0DA724 7F0A5BF4 44813000 */  mtc1  $at, $f6
/* 0DA728 7F0A5BF8 00000000 */  nop
/* 0DA72C 7F0A5BFC 46060201 */  sub.s $f8, $f0, $f6
/* 0DA730 7F0A5C00 10000021 */  b     .L7F0A5C88
/* 0DA734 7F0A5C04 E4C80000 */   swc1  $f8, ($a2)
.L7F0A5C08:
/* 0DA738 7F0A5C08 00002025 */  move  $a0, $zero
/* 0DA73C 7F0A5C0C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0DA740 7F0A5C10 24050404 */   li    $a1, 1028
/* 0DA744 7F0A5C14 14400008 */  bnez  $v0, .L7F0A5C38
/* 0DA748 7F0A5C18 00000000 */   nop
/* 0DA74C 7F0A5C1C 0C00307F */  jal   joyGetStickY
/* 0DA750 7F0A5C20 00002025 */   move  $a0, $zero
/* 0DA754 7F0A5C24 2841FFBA */  slti  $at, $v0, -0x46
/* 0DA758 7F0A5C28 14200003 */  bnez  $at, .L7F0A5C38
/* 0DA75C 7F0A5C2C 00000000 */   nop
/* 0DA760 7F0A5C30 10000016 */  b     .L7F0A5C8C
/* 0DA764 7F0A5C34 00002025 */   move  $a0, $zero
.L7F0A5C38:
/* 0DA768 7F0A5C38 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA76C 7F0A5C3C 24C609BC */  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA770 7F0A5C40 C4C00000 */  lwc1  $f0, ($a2)
/* 0DA774 7F0A5C44 8FAB001C */  lw    $t3, 0x1c($sp)
/* 0DA778 7F0A5C48 3C0D8004 */  lui   $t5, %hi(watch_item_is_actively_selected)
/* 0DA77C 7F0A5C4C 4600028D */  trunc.w.s $f10, $f0
/* 0DA780 7F0A5C50 256CFFFF */  addiu $t4, $t3, -1
/* 0DA784 7F0A5C54 440A5000 */  mfc1  $t2, $f10
/* 0DA788 7F0A5C58 00000000 */  nop
/* 0DA78C 7F0A5C5C 014C082A */  slt   $at, $t2, $t4
/* 0DA790 7F0A5C60 5020000A */  beql  $at, $zero, .L7F0A5C8C
/* 0DA794 7F0A5C64 00002025 */   move  $a0, $zero
/* 0DA798 7F0A5C68 8DAD09A8 */  lw    $t5, %lo(watch_item_is_actively_selected)($t5)
/* 0DA79C 7F0A5C6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA7A0 7F0A5C70 55A00006 */  bnezl $t5, .L7F0A5C8C
/* 0DA7A4 7F0A5C74 00002025 */   move  $a0, $zero
/* 0DA7A8 7F0A5C78 44818000 */  mtc1  $at, $f16
/* 0DA7AC 7F0A5C7C 00000000 */  nop
/* 0DA7B0 7F0A5C80 46100480 */  add.s $f18, $f0, $f16
/* 0DA7B4 7F0A5C84 E4D20000 */  swc1  $f18, ($a2)
.L7F0A5C88:
/* 0DA7B8 7F0A5C88 00002025 */  move  $a0, $zero
.L7F0A5C8C:
/* 0DA7BC 7F0A5C8C 0C0030C3 */  jal   joyGetButtons
/* 0DA7C0 7F0A5C90 24050808 */   li    $a1, 2056
/* 0DA7C4 7F0A5C94 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA7C8 7F0A5C98 10400010 */  beqz  $v0, .L7F0A5CDC
/* 0DA7CC 7F0A5C9C 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA7D0 7F0A5CA0 C4C00000 */  lwc1  $f0, ($a2)
/* 0DA7D4 7F0A5CA4 3C188004 */  lui   $t8, %hi(watch_item_is_actively_selected)
/* 0DA7D8 7F0A5CA8 4600010D */  trunc.w.s $f4, $f0
/* 0DA7DC 7F0A5CAC 440F2000 */  mfc1  $t7, $f4
/* 0DA7E0 7F0A5CB0 00000000 */  nop
/* 0DA7E4 7F0A5CB4 19E00020 */  blez  $t7, .L7F0A5D38
/* 0DA7E8 7F0A5CB8 00000000 */   nop
/* 0DA7EC 7F0A5CBC 8F1809A8 */  lw    $t8, %lo(watch_item_is_actively_selected)($t8)
/* 0DA7F0 7F0A5CC0 3C018006 */  lui   $at, %hi(D_8005847C)
/* 0DA7F4 7F0A5CC4 1700001C */  bnez  $t8, .L7F0A5D38
/* 0DA7F8 7F0A5CC8 00000000 */   nop
/* 0DA7FC 7F0A5CCC C426847C */  lwc1  $f6, %lo(D_8005847C)($at)
/* 0DA800 7F0A5CD0 46060201 */  sub.s $f8, $f0, $f6
/* 0DA804 7F0A5CD4 10000018 */  b     .L7F0A5D38
/* 0DA808 7F0A5CD8 E4C80000 */   swc1  $f8, ($a2)
.L7F0A5CDC:
/* 0DA80C 7F0A5CDC 00002025 */  move  $a0, $zero
/* 0DA810 7F0A5CE0 0C0030C3 */  jal   joyGetButtons
/* 0DA814 7F0A5CE4 24050404 */   li    $a1, 1028
/* 0DA818 7F0A5CE8 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA81C 7F0A5CEC 10400012 */  beqz  $v0, .L7F0A5D38
/* 0DA820 7F0A5CF0 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA824 7F0A5CF4 C4C00000 */  lwc1  $f0, ($a2)
/* 0DA828 7F0A5CF8 8FAA001C */  lw    $t2, 0x1c($sp)
/* 0DA82C 7F0A5CFC 3C0D8004 */  lui   $t5, %hi(watch_item_is_actively_selected)
/* 0DA830 7F0A5D00 4600028D */  trunc.w.s $f10, $f0
/* 0DA834 7F0A5D04 254CFFFF */  addiu $t4, $t2, -1
/* 0DA838 7F0A5D08 440B5000 */  mfc1  $t3, $f10
/* 0DA83C 7F0A5D0C 00000000 */  nop
/* 0DA840 7F0A5D10 016C082A */  slt   $at, $t3, $t4
/* 0DA844 7F0A5D14 10200008 */  beqz  $at, .L7F0A5D38
/* 0DA848 7F0A5D18 00000000 */   nop
/* 0DA84C 7F0A5D1C 8DAD09A8 */  lw    $t5, %lo(watch_item_is_actively_selected)($t5)
/* 0DA850 7F0A5D20 3C018006 */  lui   $at, %hi(D_80058480)
/* 0DA854 7F0A5D24 15A00004 */  bnez  $t5, .L7F0A5D38
/* 0DA858 7F0A5D28 00000000 */   nop
/* 0DA85C 7F0A5D2C C4308480 */  lwc1  $f16, %lo(D_80058480)($at)
/* 0DA860 7F0A5D30 46100480 */  add.s $f18, $f0, $f16
/* 0DA864 7F0A5D34 E4D20000 */  swc1  $f18, ($a2)
.L7F0A5D38:
/* 0DA868 7F0A5D38 0C00307F */  jal   joyGetStickY
/* 0DA86C 7F0A5D3C 00002025 */   move  $a0, $zero
/* 0DA870 7F0A5D40 2841001F */  slti  $at, $v0, 0x1f
/* 0DA874 7F0A5D44 1420001A */  bnez  $at, .L7F0A5DB0
/* 0DA878 7F0A5D48 00000000 */   nop
/* 0DA87C 7F0A5D4C 0C00307F */  jal   joyGetStickY
/* 0DA880 7F0A5D50 00002025 */   move  $a0, $zero
/* 0DA884 7F0A5D54 28410046 */  slti  $at, $v0, 0x46
/* 0DA888 7F0A5D58 10200015 */  beqz  $at, .L7F0A5DB0
/* 0DA88C 7F0A5D5C 3C0E8004 */   lui   $t6, %hi(g_curWatchItemIndex)
/* 0DA890 7F0A5D60 8DCE09B8 */  lw    $t6, %lo(g_curWatchItemIndex)($t6)
/* 0DA894 7F0A5D64 3C0F8004 */  lui   $t7, %hi(watch_item_is_actively_selected)
/* 0DA898 7F0A5D68 19C00011 */  blez  $t6, .L7F0A5DB0
/* 0DA89C 7F0A5D6C 00000000 */   nop
/* 0DA8A0 7F0A5D70 8DEF09A8 */  lw    $t7, %lo(watch_item_is_actively_selected)($t7)
/* 0DA8A4 7F0A5D74 15E0000E */  bnez  $t7, .L7F0A5DB0
/* 0DA8A8 7F0A5D78 00000000 */   nop
/* 0DA8AC 7F0A5D7C 0C00307F */  jal   joyGetStickY
/* 0DA8B0 7F0A5D80 00002025 */   move  $a0, $zero
/* 0DA8B4 7F0A5D84 44822000 */  mtc1  $v0, $f4
/* 0DA8B8 7F0A5D88 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0DA8BC 7F0A5D8C 44814000 */  mtc1  $at, $f8
/* 0DA8C0 7F0A5D90 468021A0 */  cvt.s.w $f6, $f4
/* 0DA8C4 7F0A5D94 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA8C8 7F0A5D98 24C609BC */  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA8CC 7F0A5D9C C4D00000 */  lwc1  $f16, ($a2)
/* 0DA8D0 7F0A5DA0 46083283 */  div.s $f10, $f6, $f8
/* 0DA8D4 7F0A5DA4 460A8481 */  sub.s $f18, $f16, $f10
/* 0DA8D8 7F0A5DA8 10000025 */  b     .L7F0A5E40
/* 0DA8DC 7F0A5DAC E4D20000 */   swc1  $f18, ($a2)
.L7F0A5DB0:
/* 0DA8E0 7F0A5DB0 0C00307F */  jal   joyGetStickY
/* 0DA8E4 7F0A5DB4 00002025 */   move  $a0, $zero
/* 0DA8E8 7F0A5DB8 2841FFE2 */  slti  $at, $v0, -0x1e
/* 0DA8EC 7F0A5DBC 10200020 */  beqz  $at, .L7F0A5E40
/* 0DA8F0 7F0A5DC0 00000000 */   nop
/* 0DA8F4 7F0A5DC4 0C00307F */  jal   joyGetStickY
/* 0DA8F8 7F0A5DC8 00002025 */   move  $a0, $zero
/* 0DA8FC 7F0A5DCC 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA900 7F0A5DD0 2841FFBB */  slti  $at, $v0, -0x45
/* 0DA904 7F0A5DD4 1420001A */  bnez  $at, .L7F0A5E40
/* 0DA908 7F0A5DD8 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA90C 7F0A5DDC C4C40000 */  lwc1  $f4, ($a2)
/* 0DA910 7F0A5DE0 8FAA001C */  lw    $t2, 0x1c($sp)
/* 0DA914 7F0A5DE4 3C0C8004 */  lui   $t4, %hi(watch_item_is_actively_selected)
/* 0DA918 7F0A5DE8 4600218D */  trunc.w.s $f6, $f4
/* 0DA91C 7F0A5DEC 254BFFFF */  addiu $t3, $t2, -1
/* 0DA920 7F0A5DF0 44193000 */  mfc1  $t9, $f6
/* 0DA924 7F0A5DF4 00000000 */  nop
/* 0DA928 7F0A5DF8 032B082A */  slt   $at, $t9, $t3
/* 0DA92C 7F0A5DFC 10200010 */  beqz  $at, .L7F0A5E40
/* 0DA930 7F0A5E00 00000000 */   nop
/* 0DA934 7F0A5E04 8D8C09A8 */  lw    $t4, %lo(watch_item_is_actively_selected)($t4)
/* 0DA938 7F0A5E08 1580000D */  bnez  $t4, .L7F0A5E40
/* 0DA93C 7F0A5E0C 00000000 */   nop
/* 0DA940 7F0A5E10 0C00307F */  jal   joyGetStickY
/* 0DA944 7F0A5E14 00002025 */   move  $a0, $zero
/* 0DA948 7F0A5E18 44824000 */  mtc1  $v0, $f8
/* 0DA94C 7F0A5E1C 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0DA950 7F0A5E20 44815000 */  mtc1  $at, $f10
/* 0DA954 7F0A5E24 46804420 */  cvt.s.w $f16, $f8
/* 0DA958 7F0A5E28 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA95C 7F0A5E2C 24C609BC */  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA960 7F0A5E30 C4C40000 */  lwc1  $f4, ($a2)
/* 0DA964 7F0A5E34 460A8483 */  div.s $f18, $f16, $f10
/* 0DA968 7F0A5E38 46122181 */  sub.s $f6, $f4, $f18
/* 0DA96C 7F0A5E3C E4C60000 */  swc1  $f6, ($a2)
.L7F0A5E40:
/* 0DA970 7F0A5E40 0FC29458 */  jal   sub_GAME_7F0A5160
/* 0DA974 7F0A5E44 00000000 */   nop
/* 0DA978 7F0A5E48 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA97C 7F0A5E4C 10400010 */  beqz  $v0, .L7F0A5E90
/* 0DA980 7F0A5E50 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA984 7F0A5E54 3C0D8004 */  lui   $t5, %hi(g_curWatchItemIndex)
/* 0DA988 7F0A5E58 8DAD09B8 */  lw    $t5, %lo(g_curWatchItemIndex)($t5)
/* 0DA98C 7F0A5E5C 3C0E8004 */  lui   $t6, %hi(watch_item_is_actively_selected)
/* 0DA990 7F0A5E60 19A0000B */  blez  $t5, .L7F0A5E90
/* 0DA994 7F0A5E64 00000000 */   nop
/* 0DA998 7F0A5E68 8DCE09A8 */  lw    $t6, %lo(watch_item_is_actively_selected)($t6)
/* 0DA99C 7F0A5E6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA9A0 7F0A5E70 15C00007 */  bnez  $t6, .L7F0A5E90
/* 0DA9A4 7F0A5E74 00000000 */   nop
/* 0DA9A8 7F0A5E78 C4C80000 */  lwc1  $f8, ($a2)
/* 0DA9AC 7F0A5E7C 44818000 */  mtc1  $at, $f16
/* 0DA9B0 7F0A5E80 00000000 */  nop
/* 0DA9B4 7F0A5E84 46104281 */  sub.s $f10, $f8, $f16
/* 0DA9B8 7F0A5E88 10000017 */  b     .L7F0A5EE8
/* 0DA9BC 7F0A5E8C E4CA0000 */   swc1  $f10, ($a2)
.L7F0A5E90:
/* 0DA9C0 7F0A5E90 0FC29467 */  jal   sub_GAME_7F0A519C
/* 0DA9C4 7F0A5E94 00000000 */   nop
/* 0DA9C8 7F0A5E98 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DA9CC 7F0A5E9C 10400012 */  beqz  $v0, .L7F0A5EE8
/* 0DA9D0 7F0A5EA0 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DA9D4 7F0A5EA4 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0DA9D8 7F0A5EA8 3C0F8004 */  lui   $t7, %hi(g_curWatchItemIndex)
/* 0DA9DC 7F0A5EAC 8DEF09B8 */  lw    $t7, %lo(g_curWatchItemIndex)($t7)
/* 0DA9E0 7F0A5EB0 270AFFFF */  addiu $t2, $t8, -1
/* 0DA9E4 7F0A5EB4 3C198004 */  lui   $t9, %hi(watch_item_is_actively_selected)
/* 0DA9E8 7F0A5EB8 01EA082A */  slt   $at, $t7, $t2
/* 0DA9EC 7F0A5EBC 1020000A */  beqz  $at, .L7F0A5EE8
/* 0DA9F0 7F0A5EC0 00000000 */   nop
/* 0DA9F4 7F0A5EC4 8F3909A8 */  lw    $t9, %lo(watch_item_is_actively_selected)($t9)
/* 0DA9F8 7F0A5EC8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA9FC 7F0A5ECC 17200006 */  bnez  $t9, .L7F0A5EE8
/* 0DAA00 7F0A5ED0 00000000 */   nop
/* 0DAA04 7F0A5ED4 C4C40000 */  lwc1  $f4, ($a2)
/* 0DAA08 7F0A5ED8 44819000 */  mtc1  $at, $f18
/* 0DAA0C 7F0A5EDC 00000000 */  nop
/* 0DAA10 7F0A5EE0 46122180 */  add.s $f6, $f4, $f18
/* 0DAA14 7F0A5EE4 E4C60000 */  swc1  $f6, ($a2)
.L7F0A5EE8:
/* 0DAA18 7F0A5EE8 0FC29440 */  jal   is_holding_less_than_10_up_on_stick
/* 0DAA1C 7F0A5EEC 00000000 */   nop
/* 0DAA20 7F0A5EF0 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DAA24 7F0A5EF4 14400006 */  bnez  $v0, .L7F0A5F10
/* 0DAA28 7F0A5EF8 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DAA2C 7F0A5EFC 0FC29449 */  jal   is_holding_less_than_10_down_on_stick
/* 0DAA30 7F0A5F00 00000000 */   nop
/* 0DAA34 7F0A5F04 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DAA38 7F0A5F08 10400005 */  beqz  $v0, .L7F0A5F20
/* 0DAA3C 7F0A5F0C 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
.L7F0A5F10:
/* 0DAA40 7F0A5F10 240B0001 */  li    $t3, 1
/* 0DAA44 7F0A5F14 3C018004 */  lui   $at, %hi(D_80040AE4)
/* 0DAA48 7F0A5F18 10000003 */  b     .L7F0A5F28
/* 0DAA4C 7F0A5F1C AC2B0AE4 */   sw    $t3, %lo(D_80040AE4)($at)
.L7F0A5F20:
/* 0DAA50 7F0A5F20 3C018004 */  lui    $at, %hi(D_80040AE4)
/* 0DAA54 7F0A5F24 AC200AE4 */  sw    $zero, %lo(D_80040AE4)($at)
.L7F0A5F28:
/* 0DAA58 7F0A5F28 8FAC001C */  lw    $t4, 0x1c($sp)
/* 0DAA5C 7F0A5F2C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DAA60 7F0A5F30 44815000 */  mtc1  $at, $f10
/* 0DAA64 7F0A5F34 448C4000 */  mtc1  $t4, $f8
/* 0DAA68 7F0A5F38 C4C00000 */  lwc1  $f0, ($a2)
/* 0DAA6C 7F0A5F3C 3C01BF00 */  li    $at, 0xBF000000 # -0.500000
/* 0DAA70 7F0A5F40 46804420 */  cvt.s.w $f16, $f8
/* 0DAA74 7F0A5F44 3C058004 */  lui   $a1, %hi(g_curWatchItemIndex)
/* 0DAA78 7F0A5F48 460A8081 */  sub.s $f2, $f16, $f10
/* 0DAA7C 7F0A5F4C 4600103C */  c.lt.s $f2, $f0
/* 0DAA80 7F0A5F50 00000000 */  nop
/* 0DAA84 7F0A5F54 45020004 */  bc1fl .L7F0A5F68
/* 0DAA88 7F0A5F58 44811000 */   mtc1  $at, $f2
/* 0DAA8C 7F0A5F5C E4C20000 */  swc1  $f2, ($a2)
/* 0DAA90 7F0A5F60 C4C00000 */  lwc1  $f0, ($a2)
/* 0DAA94 7F0A5F64 44811000 */  mtc1  $at, $f2
.L7F0A5F68:
/* 0DAA98 7F0A5F68 00000000 */  nop
/* 0DAA9C 7F0A5F6C 4602003C */  c.lt.s $f0, $f2
/* 0DAAA0 7F0A5F70 00000000 */  nop
/* 0DAAA4 7F0A5F74 45020004 */  bc1fl .L7F0A5F88
/* 0DAAA8 7F0A5F78 4600010D */   trunc.w.s $f4, $f0
/* 0DAAAC 7F0A5F7C E4C20000 */  swc1  $f2, ($a2)
/* 0DAAB0 7F0A5F80 C4C00000 */  lwc1  $f0, ($a2)
/* 0DAAB4 7F0A5F84 4600010D */  trunc.w.s $f4, $f0
.L7F0A5F88:
/* 0DAAB8 7F0A5F88 3C028005 */  lui   $v0, %hi(j_text_trigger)
/* 0DAABC 7F0A5F8C 8C4284D0 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0DAAC0 7F0A5F90 3C018004 */  lui   $at, %hi(g_curWatchItemIndex)
/* 0DAAC4 7F0A5F94 440E2000 */  mfc1  $t6, $f4
/* 0DAAC8 7F0A5F98 10400003 */  beqz  $v0, .L7F0A5FA8
/* 0DAACC 7F0A5F9C AC2E09B8 */   sw    $t6, %lo(g_curWatchItemIndex)($at)
/* 0DAAD0 7F0A5FA0 10000002 */  b     .L7F0A5FAC
/* 0DAAD4 7F0A5FA4 2407000E */   li    $a3, 14
.L7F0A5FA8:
/* 0DAAD8 7F0A5FA8 2407000C */  li    $a3, 12
.L7F0A5FAC:
/* 0DAADC 7F0A5FAC 50400004 */  beql  $v0, $zero, .L7F0A5FC0
/* 0DAAE0 7F0A5FB0 2404000C */   li    $a0, 12
/* 0DAAE4 7F0A5FB4 10000002 */  b     .L7F0A5FC0
/* 0DAAE8 7F0A5FB8 2404000E */   li    $a0, 14
/* 0DAAEC 7F0A5FBC 2404000C */  li    $a0, 12
.L7F0A5FC0:
/* 0DAAF0 7F0A5FC0 8CA509B8 */  lw    $a1, %lo(g_curWatchItemIndex)($a1)
/* 0DAAF4 7F0A5FC4 3C098004 */  lui   $t1, %hi(D_800409B0)
/* 0DAAF8 7F0A5FC8 252909B0 */  addiu $t1, %lo(D_800409B0) # addiu $t1, $t1, 0x9b0
/* 0DAAFC 7F0A5FCC 00057823 */  negu  $t7, $a1
/* 0DAB00 7F0A5FD0 01E70019 */  multu $t7, $a3
/* 0DAB04 7F0A5FD4 8D220000 */  lw    $v0, ($t1)
/* 0DAB08 7F0A5FD8 0004C040 */  sll   $t8, $a0, 1
/* 0DAB0C 7F0A5FDC 3C088004 */  lui   $t0, %hi(D_800409B4)
/* 0DAB10 7F0A5FE0 250809B4 */  addiu $t0, %lo(D_800409B4) # addiu $t0, $t0, 0x9b4
/* 0DAB14 7F0A5FE4 00005012 */  mflo  $t2
/* 0DAB18 7F0A5FE8 030AC821 */  addu  $t9, $t8, $t2
/* 0DAB1C 7F0A5FEC 0322082A */  slt   $at, $t9, $v0
/* 0DAB20 7F0A5FF0 AD190000 */  sw    $t9, ($t0)
/* 0DAB24 7F0A5FF4 1020000B */  beqz  $at, .L7F0A6024
/* 0DAB28 7F0A5FF8 03201825 */   move  $v1, $t9
/* 0DAB2C 7F0A5FFC 00595823 */  subu  $t3, $v0, $t9
/* 0DAB30 7F0A6000 24010003 */  li    $at, 3
/* 0DAB34 7F0A6004 0161001A */  div   $zero, $t3, $at
/* 0DAB38 7F0A6008 00006012 */  mflo  $t4
/* 0DAB3C 7F0A600C 004C6823 */  subu  $t5, $v0, $t4
/* 0DAB40 7F0A6010 25AEFFFF */  addiu $t6, $t5, -1
/* 0DAB44 7F0A6014 AD2E0000 */  sw    $t6, ($t1)
/* 0DAB48 7F0A6018 3C018004 */  lui   $at, %hi(D_800409C0)
/* 0DAB4C 7F0A601C 10000010 */  b     .L7F0A6060
/* 0DAB50 7F0A6020 AC2009C0 */   sw    $zero, %lo(D_800409C0)($at)
.L7F0A6024:
/* 0DAB54 7F0A6024 0043082A */  slt   $at, $v0, $v1
/* 0DAB58 7F0A6028 1020000A */  beqz  $at, .L7F0A6054
/* 0DAB5C 7F0A602C 00627823 */   subu  $t7, $v1, $v0
/* 0DAB60 7F0A6030 24010003 */  li    $at, 3
/* 0DAB64 7F0A6034 01E1001A */  div   $zero, $t7, $at
/* 0DAB68 7F0A6038 0000C012 */  mflo  $t8
/* 0DAB6C 7F0A603C 00585021 */  addu  $t2, $v0, $t8
/* 0DAB70 7F0A6040 25590001 */  addiu $t9, $t2, 1
/* 0DAB74 7F0A6044 AD390000 */  sw    $t9, ($t1)
/* 0DAB78 7F0A6048 3C018004 */  lui   $at, %hi(D_800409C0)
/* 0DAB7C 7F0A604C 10000004 */  b     .L7F0A6060
/* 0DAB80 7F0A6050 AC2009C0 */   sw    $zero, %lo(D_800409C0)($at)
.L7F0A6054:
/* 0DAB84 7F0A6054 240B0001 */  li    $t3, 1
/* 0DAB88 7F0A6058 3C018004 */  lui   $at, %hi(D_800409C0)
/* 0DAB8C 7F0A605C AC2B09C0 */  sw    $t3, %lo(D_800409C0)($at)
.L7F0A6060:
/* 0DAB90 7F0A6060 44859000 */  mtc1  $a1, $f18
/* 0DAB94 7F0A6064 3C018006 */  lui   $at, %hi(D_80058484)
/* 0DAB98 7F0A6068 C4288484 */  lwc1  $f8, %lo(D_80058484)($at)
/* 0DAB9C 7F0A606C 468091A0 */  cvt.s.w $f6, $f18
/* 0DABA0 7F0A6070 46083400 */  add.s $f16, $f6, $f8
/* 0DABA4 7F0A6074 4600803C */  c.lt.s $f16, $f0
/* 0DABA8 7F0A6078 00000000 */  nop
/* 0DABAC 7F0A607C 4500000C */  bc1f  .L7F0A60B0
/* 0DABB0 7F0A6080 00002025 */   move  $a0, $zero
/* 0DABB4 7F0A6084 0C0030C3 */  jal   joyGetButtons
/* 0DABB8 7F0A6088 3405FFFF */   li    $a1, 65535
/* 0DABBC 7F0A608C 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DABC0 7F0A6090 14400007 */  bnez  $v0, .L7F0A60B0
/* 0DABC4 7F0A6094 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DABC8 7F0A6098 3C018006 */  lui   $at, %hi(D_80058488)
/* 0DABCC 7F0A609C C4248488 */  lwc1  $f4, %lo(D_80058488)($at)
/* 0DABD0 7F0A60A0 C4CA0000 */  lwc1  $f10, ($a2)
/* 0DABD4 7F0A60A4 46045481 */  sub.s $f18, $f10, $f4
/* 0DABD8 7F0A60A8 10000018 */  b     .L7F0A610C
/* 0DABDC 7F0A60AC E4D20000 */   swc1  $f18, ($a2)
.L7F0A60B0:
/* 0DABE0 7F0A60B0 3C0C8004 */  lui   $t4, %hi(g_curWatchItemIndex)
/* 0DABE4 7F0A60B4 8D8C09B8 */  lw    $t4, %lo(g_curWatchItemIndex)($t4)
/* 0DABE8 7F0A60B8 3C018006 */  lui   $at, %hi(D_8005848C)
/* 0DABEC 7F0A60BC C430848C */  lwc1  $f16, %lo(D_8005848C)($at)
/* 0DABF0 7F0A60C0 448C3000 */  mtc1  $t4, $f6
/* 0DABF4 7F0A60C4 C4C40000 */  lwc1  $f4, ($a2)
/* 0DABF8 7F0A60C8 00002025 */  move  $a0, $zero
/* 0DABFC 7F0A60CC 46803220 */  cvt.s.w $f8, $f6
/* 0DAC00 7F0A60D0 46104280 */  add.s $f10, $f8, $f16
/* 0DAC04 7F0A60D4 460A203E */  c.le.s $f4, $f10
/* 0DAC08 7F0A60D8 00000000 */  nop
/* 0DAC0C 7F0A60DC 4502000C */  bc1fl .L7F0A6110
/* 0DAC10 7F0A60E0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0DAC14 7F0A60E4 0C0030C3 */  jal   joyGetButtons
/* 0DAC18 7F0A60E8 3405FFFF */   li    $a1, 65535
/* 0DAC1C 7F0A60EC 3C068004 */  lui   $a2, %hi(D_800409BC)
/* 0DAC20 7F0A60F0 14400006 */  bnez  $v0, .L7F0A610C
/* 0DAC24 7F0A60F4 24C609BC */   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
/* 0DAC28 7F0A60F8 3C018006 */  lui   $at, %hi(D_80058490)
/* 0DAC2C 7F0A60FC C4268490 */  lwc1  $f6, %lo(D_80058490)($at)
/* 0DAC30 7F0A6100 C4D20000 */  lwc1  $f18, ($a2)
/* 0DAC34 7F0A6104 46069200 */  add.s $f8, $f18, $f6
/* 0DAC38 7F0A6108 E4C80000 */  swc1  $f8, ($a2)
.L7F0A610C:
/* 0DAC3C 7F0A610C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0A6110:
/* 0DAC40 7F0A6110 27BD0020 */  addiu $sp, $sp, 0x20
/* 0DAC44 7F0A6114 03E00008 */  jr    $ra
/* 0DAC48 7F0A6118 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A611C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058494
.word 0x3dcccccd /*0.1*/
glabel D_80058498
.word 0x3dcccccd /*0.1*/
glabel D_8005849C
.word 0x3f0ccccd /*0.55000001*/
glabel D_800584A0
.word 0x3dcccccd /*0.1*/
glabel D_800584A4
.word 0x3ee66666 /*0.44999999*/
glabel D_800584A8
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F0A611C
/* 0DAC4C 7F0A611C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DAC50 7F0A6120 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0DAC54 7F0A6124 AFB00018 */  sw    $s0, 0x18($sp)
/* 0DAC58 7F0A6128 00808025 */  move  $s0, $a0
/* 0DAC5C 7F0A612C AFA50024 */  sw    $a1, 0x24($sp)
/* 0DAC60 7F0A6130 AFA60028 */  sw    $a2, 0x28($sp)
/* 0DAC64 7F0A6134 0FC24415 */  jal   get_debug_gunwatchpos_flag
/* 0DAC68 7F0A6138 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0DAC6C 7F0A613C 14400056 */  bnez  $v0, .L7F0A6298
/* 0DAC70 7F0A6140 00002025 */   move  $a0, $zero
/* 0DAC74 7F0A6144 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0DAC78 7F0A6148 24050808 */   li    $a1, 2056
/* 0DAC7C 7F0A614C 54400007 */  bnezl $v0, .L7F0A616C
/* 0DAC80 7F0A6150 C6000000 */   lwc1  $f0, ($s0)
/* 0DAC84 7F0A6154 0C00307F */  jal   joyGetStickY
/* 0DAC88 7F0A6158 00002025 */   move  $a0, $zero
/* 0DAC8C 7F0A615C 28410047 */  slti  $at, $v0, 0x47
/* 0DAC90 7F0A6160 1420000F */  bnez  $at, .L7F0A61A0
/* 0DAC94 7F0A6164 00002025 */   move  $a0, $zero
/* 0DAC98 7F0A6168 C6000000 */  lwc1  $f0, ($s0)
.L7F0A616C:
/* 0DAC9C 7F0A616C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 0DACA0 7F0A6170 4600010D */  trunc.w.s $f4, $f0
/* 0DACA4 7F0A6174 440F2000 */  mfc1  $t7, $f4
/* 0DACA8 7F0A6178 00000000 */  nop
/* 0DACAC 7F0A617C 59E00022 */  blezl $t7, .L7F0A6208
/* 0DACB0 7F0A6180 00002025 */   move  $a0, $zero
/* 0DACB4 7F0A6184 1300001F */  beqz  $t8, .L7F0A6204
/* 0DACB8 7F0A6188 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0DACBC 7F0A618C 44813000 */  mtc1  $at, $f6
/* 0DACC0 7F0A6190 00000000 */  nop
/* 0DACC4 7F0A6194 46060201 */  sub.s $f8, $f0, $f6
/* 0DACC8 7F0A6198 1000001A */  b     .L7F0A6204
/* 0DACCC 7F0A619C E6080000 */   swc1  $f8, ($s0)
.L7F0A61A0:
/* 0DACD0 7F0A61A0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0DACD4 7F0A61A4 24050404 */   li    $a1, 1028
/* 0DACD8 7F0A61A8 54400007 */  bnezl $v0, .L7F0A61C8
/* 0DACDC 7F0A61AC C6000000 */   lwc1  $f0, ($s0)
/* 0DACE0 7F0A61B0 0C00307F */  jal   joyGetStickY
/* 0DACE4 7F0A61B4 00002025 */   move  $a0, $zero
/* 0DACE8 7F0A61B8 2841FFBA */  slti  $at, $v0, -0x46
/* 0DACEC 7F0A61BC 50200012 */  beql  $at, $zero, .L7F0A6208
/* 0DACF0 7F0A61C0 00002025 */   move  $a0, $zero
/* 0DACF4 7F0A61C4 C6000000 */  lwc1  $f0, ($s0)
.L7F0A61C8:
/* 0DACF8 7F0A61C8 8FA90028 */  lw    $t1, 0x28($sp)
/* 0DACFC 7F0A61CC 8FAB003C */  lw    $t3, 0x3c($sp)
/* 0DAD00 7F0A61D0 4600028D */  trunc.w.s $f10, $f0
/* 0DAD04 7F0A61D4 252AFFFF */  addiu $t2, $t1, -1
/* 0DAD08 7F0A61D8 44085000 */  mfc1  $t0, $f10
/* 0DAD0C 7F0A61DC 00000000 */  nop
/* 0DAD10 7F0A61E0 010A082A */  slt   $at, $t0, $t2
/* 0DAD14 7F0A61E4 50200008 */  beql  $at, $zero, .L7F0A6208
/* 0DAD18 7F0A61E8 00002025 */   move  $a0, $zero
/* 0DAD1C 7F0A61EC 11600005 */  beqz  $t3, .L7F0A6204
/* 0DAD20 7F0A61F0 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0DAD24 7F0A61F4 44818000 */  mtc1  $at, $f16
/* 0DAD28 7F0A61F8 00000000 */  nop
/* 0DAD2C 7F0A61FC 46100480 */  add.s $f18, $f0, $f16
/* 0DAD30 7F0A6200 E6120000 */  swc1  $f18, ($s0)
.L7F0A6204:
/* 0DAD34 7F0A6204 00002025 */  move  $a0, $zero
.L7F0A6208:
/* 0DAD38 7F0A6208 0C0030C3 */  jal   joyGetButtons
/* 0DAD3C 7F0A620C 24050808 */   li    $a1, 2056
/* 0DAD40 7F0A6210 1040000E */  beqz  $v0, .L7F0A624C
/* 0DAD44 7F0A6214 00002025 */   move  $a0, $zero
/* 0DAD48 7F0A6218 C6000000 */  lwc1  $f0, ($s0)
/* 0DAD4C 7F0A621C 8FAE003C */  lw    $t6, 0x3c($sp)
/* 0DAD50 7F0A6220 4600010D */  trunc.w.s $f4, $f0
/* 0DAD54 7F0A6224 440D2000 */  mfc1  $t5, $f4
/* 0DAD58 7F0A6228 00000000 */  nop
/* 0DAD5C 7F0A622C 19A0001A */  blez  $t5, .L7F0A6298
/* 0DAD60 7F0A6230 00000000 */   nop
/* 0DAD64 7F0A6234 11C00018 */  beqz  $t6, .L7F0A6298
/* 0DAD68 7F0A6238 3C018006 */   lui   $at, %hi(D_80058494)
/* 0DAD6C 7F0A623C C4268494 */  lwc1  $f6, %lo(D_80058494)($at)
/* 0DAD70 7F0A6240 46060201 */  sub.s $f8, $f0, $f6
/* 0DAD74 7F0A6244 10000014 */  b     .L7F0A6298
/* 0DAD78 7F0A6248 E6080000 */   swc1  $f8, ($s0)
.L7F0A624C:
/* 0DAD7C 7F0A624C 0C0030C3 */  jal   joyGetButtons
/* 0DAD80 7F0A6250 24050404 */   li    $a1, 1028
/* 0DAD84 7F0A6254 10400010 */  beqz  $v0, .L7F0A6298
/* 0DAD88 7F0A6258 00000000 */   nop
/* 0DAD8C 7F0A625C C6000000 */  lwc1  $f0, ($s0)
/* 0DAD90 7F0A6260 8FB90028 */  lw    $t9, 0x28($sp)
/* 0DAD94 7F0A6264 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0DAD98 7F0A6268 4600028D */  trunc.w.s $f10, $f0
/* 0DAD9C 7F0A626C 2729FFFF */  addiu $t1, $t9, -1
/* 0DADA0 7F0A6270 44185000 */  mfc1  $t8, $f10
/* 0DADA4 7F0A6274 00000000 */  nop
/* 0DADA8 7F0A6278 0309082A */  slt   $at, $t8, $t1
/* 0DADAC 7F0A627C 10200006 */  beqz  $at, .L7F0A6298
/* 0DADB0 7F0A6280 00000000 */   nop
/* 0DADB4 7F0A6284 11000004 */  beqz  $t0, .L7F0A6298
/* 0DADB8 7F0A6288 3C018006 */   lui   $at, %hi(D_80058498)
/* 0DADBC 7F0A628C C4308498 */  lwc1  $f16, %lo(D_80058498)($at)
/* 0DADC0 7F0A6290 46100480 */  add.s $f18, $f0, $f16
/* 0DADC4 7F0A6294 E6120000 */  swc1  $f18, ($s0)
.L7F0A6298:
/* 0DADC8 7F0A6298 0C00307F */  jal   joyGetStickY
/* 0DADCC 7F0A629C 00002025 */   move  $a0, $zero
/* 0DADD0 7F0A62A0 2841001F */  slti  $at, $v0, 0x1f
/* 0DADD4 7F0A62A4 14200017 */  bnez  $at, .L7F0A6304
/* 0DADD8 7F0A62A8 00000000 */   nop
/* 0DADDC 7F0A62AC 0C00307F */  jal   joyGetStickY
/* 0DADE0 7F0A62B0 00002025 */   move  $a0, $zero
/* 0DADE4 7F0A62B4 28410046 */  slti  $at, $v0, 0x46
/* 0DADE8 7F0A62B8 10200012 */  beqz  $at, .L7F0A6304
/* 0DADEC 7F0A62BC 8FAA0024 */   lw    $t2, 0x24($sp)
/* 0DADF0 7F0A62C0 8D4B0000 */  lw    $t3, ($t2)
/* 0DADF4 7F0A62C4 8FAC003C */  lw    $t4, 0x3c($sp)
/* 0DADF8 7F0A62C8 1960000E */  blez  $t3, .L7F0A6304
/* 0DADFC 7F0A62CC 00000000 */   nop
/* 0DAE00 7F0A62D0 1180000C */  beqz  $t4, .L7F0A6304
/* 0DAE04 7F0A62D4 00000000 */   nop
/* 0DAE08 7F0A62D8 0C00307F */  jal   joyGetStickY
/* 0DAE0C 7F0A62DC 00002025 */   move  $a0, $zero
/* 0DAE10 7F0A62E0 44822000 */  mtc1  $v0, $f4
/* 0DAE14 7F0A62E4 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0DAE18 7F0A62E8 44814000 */  mtc1  $at, $f8
/* 0DAE1C 7F0A62EC 468021A0 */  cvt.s.w $f6, $f4
/* 0DAE20 7F0A62F0 C6100000 */  lwc1  $f16, ($s0)
/* 0DAE24 7F0A62F4 46083283 */  div.s $f10, $f6, $f8
/* 0DAE28 7F0A62F8 460A8481 */  sub.s $f18, $f16, $f10
/* 0DAE2C 7F0A62FC 10000021 */  b     .L7F0A6384
/* 0DAE30 7F0A6300 E6120000 */   swc1  $f18, ($s0)
.L7F0A6304:
/* 0DAE34 7F0A6304 0C00307F */  jal   joyGetStickY
/* 0DAE38 7F0A6308 00002025 */   move  $a0, $zero
/* 0DAE3C 7F0A630C 2841FFE2 */  slti  $at, $v0, -0x1e
/* 0DAE40 7F0A6310 1020001C */  beqz  $at, .L7F0A6384
/* 0DAE44 7F0A6314 00000000 */   nop
/* 0DAE48 7F0A6318 0C00307F */  jal   joyGetStickY
/* 0DAE4C 7F0A631C 00002025 */   move  $a0, $zero
/* 0DAE50 7F0A6320 2841FFBB */  slti  $at, $v0, -0x45
/* 0DAE54 7F0A6324 14200017 */  bnez  $at, .L7F0A6384
/* 0DAE58 7F0A6328 00000000 */   nop
/* 0DAE5C 7F0A632C C6040000 */  lwc1  $f4, ($s0)
/* 0DAE60 7F0A6330 8FAF0028 */  lw    $t7, 0x28($sp)
/* 0DAE64 7F0A6334 8FB8003C */  lw    $t8, 0x3c($sp)
/* 0DAE68 7F0A6338 4600218D */  trunc.w.s $f6, $f4
/* 0DAE6C 7F0A633C 25F9FFFF */  addiu $t9, $t7, -1
/* 0DAE70 7F0A6340 440E3000 */  mfc1  $t6, $f6
/* 0DAE74 7F0A6344 00000000 */  nop
/* 0DAE78 7F0A6348 01D9082A */  slt   $at, $t6, $t9
/* 0DAE7C 7F0A634C 1020000D */  beqz  $at, .L7F0A6384
/* 0DAE80 7F0A6350 00000000 */   nop
/* 0DAE84 7F0A6354 1300000B */  beqz  $t8, .L7F0A6384
/* 0DAE88 7F0A6358 00000000 */   nop
/* 0DAE8C 7F0A635C 0C00307F */  jal   joyGetStickY
/* 0DAE90 7F0A6360 00002025 */   move  $a0, $zero
/* 0DAE94 7F0A6364 44824000 */  mtc1  $v0, $f8
/* 0DAE98 7F0A6368 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0DAE9C 7F0A636C 44815000 */  mtc1  $at, $f10
/* 0DAEA0 7F0A6370 46804420 */  cvt.s.w $f16, $f8
/* 0DAEA4 7F0A6374 C6040000 */  lwc1  $f4, ($s0)
/* 0DAEA8 7F0A6378 460A8483 */  div.s $f18, $f16, $f10
/* 0DAEAC 7F0A637C 46122181 */  sub.s $f6, $f4, $f18
/* 0DAEB0 7F0A6380 E6060000 */  swc1  $f6, ($s0)
.L7F0A6384:
/* 0DAEB4 7F0A6384 0FC29458 */  jal   sub_GAME_7F0A5160
/* 0DAEB8 7F0A6388 00000000 */   nop
/* 0DAEBC 7F0A638C 1040000D */  beqz  $v0, .L7F0A63C4
/* 0DAEC0 7F0A6390 8FA90024 */   lw    $t1, 0x24($sp)
/* 0DAEC4 7F0A6394 8D280000 */  lw    $t0, ($t1)
/* 0DAEC8 7F0A6398 8FAA003C */  lw    $t2, 0x3c($sp)
/* 0DAECC 7F0A639C 19000009 */  blez  $t0, .L7F0A63C4
/* 0DAED0 7F0A63A0 00000000 */   nop
/* 0DAED4 7F0A63A4 11400007 */  beqz  $t2, .L7F0A63C4
/* 0DAED8 7F0A63A8 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0DAEDC 7F0A63AC C6080000 */  lwc1  $f8, ($s0)
/* 0DAEE0 7F0A63B0 44818000 */  mtc1  $at, $f16
/* 0DAEE4 7F0A63B4 00000000 */  nop
/* 0DAEE8 7F0A63B8 46104281 */  sub.s $f10, $f8, $f16
/* 0DAEEC 7F0A63BC 10000013 */  b     .L7F0A640C
/* 0DAEF0 7F0A63C0 E60A0000 */   swc1  $f10, ($s0)
.L7F0A63C4:
/* 0DAEF4 7F0A63C4 0FC29467 */  jal   sub_GAME_7F0A519C
/* 0DAEF8 7F0A63C8 00000000 */   nop
/* 0DAEFC 7F0A63CC 1040000F */  beqz  $v0, .L7F0A640C
/* 0DAF00 7F0A63D0 8FAB0024 */   lw    $t3, 0x24($sp)
/* 0DAF04 7F0A63D4 8FAD0028 */  lw    $t5, 0x28($sp)
/* 0DAF08 7F0A63D8 8D6C0000 */  lw    $t4, ($t3)
/* 0DAF0C 7F0A63DC 8FAE003C */  lw    $t6, 0x3c($sp)
/* 0DAF10 7F0A63E0 25AFFFFF */  addiu $t7, $t5, -1
/* 0DAF14 7F0A63E4 018F082A */  slt   $at, $t4, $t7
/* 0DAF18 7F0A63E8 10200008 */  beqz  $at, .L7F0A640C
/* 0DAF1C 7F0A63EC 00000000 */   nop
/* 0DAF20 7F0A63F0 11C00006 */  beqz  $t6, .L7F0A640C
/* 0DAF24 7F0A63F4 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0DAF28 7F0A63F8 C6040000 */  lwc1  $f4, ($s0)
/* 0DAF2C 7F0A63FC 44819000 */  mtc1  $at, $f18
/* 0DAF30 7F0A6400 00000000 */  nop
/* 0DAF34 7F0A6404 46122180 */  add.s $f6, $f4, $f18
/* 0DAF38 7F0A6408 E6060000 */  swc1  $f6, ($s0)
.L7F0A640C:
/* 0DAF3C 7F0A640C 0FC29440 */  jal   is_holding_less_than_10_up_on_stick
/* 0DAF40 7F0A6410 00000000 */   nop
/* 0DAF44 7F0A6414 54400006 */  bnezl $v0, .L7F0A6430
/* 0DAF48 7F0A6418 24190001 */   li    $t9, 1
/* 0DAF4C 7F0A641C 0FC29449 */  jal   is_holding_less_than_10_down_on_stick
/* 0DAF50 7F0A6420 00000000 */   nop
/* 0DAF54 7F0A6424 10400005 */  beqz  $v0, .L7F0A643C
/* 0DAF58 7F0A6428 3C018004 */   lui   $at, %hi(D_80040AE4)
/* 0DAF5C 7F0A642C 24190001 */  li    $t9, 1
.L7F0A6430:
/* 0DAF60 7F0A6430 3C018004 */  lui    $at, %hi(D_80040AE4)
/* 0DAF64 7F0A6434 10000002 */  b     .L7F0A6440
/* 0DAF68 7F0A6438 AC390AE4 */   sw    $t9, %lo(D_80040AE4)($at)
.L7F0A643C:
/* 0DAF6C 7F0A643C AC200AE4 */  sw    $zero, %lo(D_80040AE4)($at)
.L7F0A6440:
/* 0DAF70 7F0A6440 8FB80028 */  lw    $t8, 0x28($sp)
/* 0DAF74 7F0A6444 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DAF78 7F0A6448 44815000 */  mtc1  $at, $f10
/* 0DAF7C 7F0A644C 44984000 */  mtc1  $t8, $f8
/* 0DAF80 7F0A6450 C6000000 */  lwc1  $f0, ($s0)
/* 0DAF84 7F0A6454 3C01BF00 */  li    $at, 0xBF000000 # -0.500000
/* 0DAF88 7F0A6458 46804420 */  cvt.s.w $f16, $f8
/* 0DAF8C 7F0A645C 460A8081 */  sub.s $f2, $f16, $f10
/* 0DAF90 7F0A6460 4600103C */  c.lt.s $f2, $f0
/* 0DAF94 7F0A6464 00000000 */  nop
/* 0DAF98 7F0A6468 45020004 */  bc1fl .L7F0A647C
/* 0DAF9C 7F0A646C 44811000 */   mtc1  $at, $f2
/* 0DAFA0 7F0A6470 E6020000 */  swc1  $f2, ($s0)
/* 0DAFA4 7F0A6474 C6000000 */  lwc1  $f0, ($s0)
/* 0DAFA8 7F0A6478 44811000 */  mtc1  $at, $f2
.L7F0A647C:
/* 0DAFAC 7F0A647C 00000000 */  nop
/* 0DAFB0 7F0A6480 4602003C */  c.lt.s $f0, $f2
/* 0DAFB4 7F0A6484 00000000 */  nop
/* 0DAFB8 7F0A6488 45020004 */  bc1fl .L7F0A649C
/* 0DAFBC 7F0A648C 4600010D */   trunc.w.s $f4, $f0
/* 0DAFC0 7F0A6490 E6020000 */  swc1  $f2, ($s0)
/* 0DAFC4 7F0A6494 C6000000 */  lwc1  $f0, ($s0)
/* 0DAFC8 7F0A6498 4600010D */  trunc.w.s $f4, $f0
.L7F0A649C:
/* 0DAFCC 7F0A649C 8FA50040 */  lw    $a1, 0x40($sp)
/* 0DAFD0 7F0A64A0 8FAA0024 */  lw    $t2, 0x24($sp)
/* 0DAFD4 7F0A64A4 8FA40030 */  lw    $a0, 0x30($sp)
/* 0DAFD8 7F0A64A8 44082000 */  mfc1  $t0, $f4
/* 0DAFDC 7F0A64AC 8FA6002C */  lw    $a2, 0x2c($sp)
/* 0DAFE0 7F0A64B0 00085823 */  negu  $t3, $t0
/* 0DAFE4 7F0A64B4 01650019 */  multu $t3, $a1
/* 0DAFE8 7F0A64B8 AD480000 */  sw    $t0, ($t2)
/* 0DAFEC 7F0A64BC 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0DAFF0 7F0A64C0 00006812 */  mflo  $t5
/* 0DAFF4 7F0A64C4 00000000 */  nop
/* 0DAFF8 7F0A64C8 00000000 */  nop
/* 0DAFFC 7F0A64CC 01850019 */  multu $t4, $a1
/* 0DB000 7F0A64D0 00007812 */  mflo  $t7
/* 0DB004 7F0A64D4 01AF7021 */  addu  $t6, $t5, $t7
/* 0DB008 7F0A64D8 AC8E0000 */  sw    $t6, ($a0)
/* 0DB00C 7F0A64DC 8CC20000 */  lw    $v0, ($a2)
/* 0DB010 7F0A64E0 01C01825 */  move  $v1, $t6
/* 0DB014 7F0A64E4 00002025 */  move  $a0, $zero
/* 0DB018 7F0A64E8 01C2082A */  slt   $at, $t6, $v0
/* 0DB01C 7F0A64EC 1020000A */  beqz  $at, .L7F0A6518
/* 0DB020 7F0A64F0 004EC823 */   subu  $t9, $v0, $t6
/* 0DB024 7F0A64F4 24010003 */  li    $at, 3
/* 0DB028 7F0A64F8 0321001A */  div   $zero, $t9, $at
/* 0DB02C 7F0A64FC 0000C012 */  mflo  $t8
/* 0DB030 7F0A6500 00584823 */  subu  $t1, $v0, $t8
/* 0DB034 7F0A6504 252AFFFF */  addiu $t2, $t1, -1
/* 0DB038 7F0A6508 ACCA0000 */  sw    $t2, ($a2)
/* 0DB03C 7F0A650C 8FA80034 */  lw    $t0, 0x34($sp)
/* 0DB040 7F0A6510 10000010 */  b     .L7F0A6554
/* 0DB044 7F0A6514 AD000000 */   sw    $zero, ($t0)
.L7F0A6518:
/* 0DB048 7F0A6518 0043082A */  slt   $at, $v0, $v1
/* 0DB04C 7F0A651C 1020000B */  beqz  $at, .L7F0A654C
/* 0DB050 7F0A6520 8FB80034 */   lw    $t8, 0x34($sp)
/* 0DB054 7F0A6524 00625823 */  subu  $t3, $v1, $v0
/* 0DB058 7F0A6528 24010003 */  li    $at, 3
/* 0DB05C 7F0A652C 0161001A */  div   $zero, $t3, $at
/* 0DB060 7F0A6530 00006012 */  mflo  $t4
/* 0DB064 7F0A6534 004C6821 */  addu  $t5, $v0, $t4
/* 0DB068 7F0A6538 25AF0001 */  addiu $t7, $t5, 1
/* 0DB06C 7F0A653C ACCF0000 */  sw    $t7, ($a2)
/* 0DB070 7F0A6540 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0DB074 7F0A6544 10000003 */  b     .L7F0A6554
/* 0DB078 7F0A6548 ADC00000 */   sw    $zero, ($t6)
.L7F0A654C:
/* 0DB07C 7F0A654C 24190001 */  li    $t9, 1
/* 0DB080 7F0A6550 AF190000 */  sw    $t9, ($t8)
.L7F0A6554:
/* 0DB084 7F0A6554 8FA90024 */  lw    $t1, 0x24($sp)
/* 0DB088 7F0A6558 3C018006 */  lui   $at, %hi(D_8005849C)
/* 0DB08C 7F0A655C C428849C */  lwc1  $f8, %lo(D_8005849C)($at)
/* 0DB090 7F0A6560 8D2A0000 */  lw    $t2, ($t1)
/* 0DB094 7F0A6564 C60A0000 */  lwc1  $f10, ($s0)
/* 0DB098 7F0A6568 448A9000 */  mtc1  $t2, $f18
/* 0DB09C 7F0A656C 00000000 */  nop
/* 0DB0A0 7F0A6570 468091A0 */  cvt.s.w $f6, $f18
/* 0DB0A4 7F0A6574 46083400 */  add.s $f16, $f6, $f8
/* 0DB0A8 7F0A6578 460A803C */  c.lt.s $f16, $f10
/* 0DB0AC 7F0A657C 00000000 */  nop
/* 0DB0B0 7F0A6580 4502000B */  bc1fl .L7F0A65B0
/* 0DB0B4 7F0A6584 8FA80024 */   lw    $t0, 0x24($sp)
/* 0DB0B8 7F0A6588 0C0030C3 */  jal   joyGetButtons
/* 0DB0BC 7F0A658C 3405FFFF */   li    $a1, 65535
/* 0DB0C0 7F0A6590 14400006 */  bnez  $v0, .L7F0A65AC
/* 0DB0C4 7F0A6594 3C018006 */   lui   $at, %hi(D_800584A0)
/* 0DB0C8 7F0A6598 C6040000 */  lwc1  $f4, ($s0)
/* 0DB0CC 7F0A659C C43284A0 */  lwc1  $f18, %lo(D_800584A0)($at)
/* 0DB0D0 7F0A65A0 46122181 */  sub.s $f6, $f4, $f18
/* 0DB0D4 7F0A65A4 10000017 */  b     .L7F0A6604
/* 0DB0D8 7F0A65A8 E6060000 */   swc1  $f6, ($s0)
.L7F0A65AC:
/* 0DB0DC 7F0A65AC 8FA80024 */  lw    $t0, 0x24($sp)
.L7F0A65B0:
/* 0DB0E0 7F0A65B0 3C018006 */  lui   $at, %hi(D_800584A4)
/* 0DB0E4 7F0A65B4 C42A84A4 */  lwc1  $f10, %lo(D_800584A4)($at)
/* 0DB0E8 7F0A65B8 8D0B0000 */  lw    $t3, ($t0)
/* 0DB0EC 7F0A65BC C6120000 */  lwc1  $f18, ($s0)
/* 0DB0F0 7F0A65C0 00002025 */  move  $a0, $zero
/* 0DB0F4 7F0A65C4 448B4000 */  mtc1  $t3, $f8
/* 0DB0F8 7F0A65C8 00000000 */  nop
/* 0DB0FC 7F0A65CC 46804420 */  cvt.s.w $f16, $f8
/* 0DB100 7F0A65D0 460A8100 */  add.s $f4, $f16, $f10
/* 0DB104 7F0A65D4 4604903E */  c.le.s $f18, $f4
/* 0DB108 7F0A65D8 00000000 */  nop
/* 0DB10C 7F0A65DC 4502000A */  bc1fl .L7F0A6608
/* 0DB110 7F0A65E0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0DB114 7F0A65E4 0C0030C3 */  jal   joyGetButtons
/* 0DB118 7F0A65E8 3405FFFF */   li    $a1, 65535
/* 0DB11C 7F0A65EC 14400005 */  bnez  $v0, .L7F0A6604
/* 0DB120 7F0A65F0 3C018006 */   lui   $at, %hi(D_800584A8)
/* 0DB124 7F0A65F4 C6060000 */  lwc1  $f6, ($s0)
/* 0DB128 7F0A65F8 C42884A8 */  lwc1  $f8, %lo(D_800584A8)($at)
/* 0DB12C 7F0A65FC 46083400 */  add.s $f16, $f6, $f8
/* 0DB130 7F0A6600 E6100000 */  swc1  $f16, ($s0)
.L7F0A6604:
/* 0DB134 7F0A6604 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0A6608:
/* 0DB138 7F0A6608 8FB00018 */  lw    $s0, 0x18($sp)
/* 0DB13C 7F0A660C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0DB140 7F0A6610 03E00008 */  jr    $ra
/* 0DB144 7F0A6614 00000000 */   nop
)
#endif






void mission_brief_background_navigation(void)
{
    if ((joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD)) || (sub_GAME_7F0A5088()))
    {
        mission_brief_index = BRIEF_INDEX_OBJECTIVES;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }

    if ((joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD)) || (sub_GAME_7F0A50C4()))
    {
        mission_brief_index = BRIEF_INDEX_M;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}


void mission_brief_m_briefing_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        mission_brief_index = BRIEF_INDEX_BACKGROUND;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        mission_brief_index = BRIEF_INDEX_Q;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}


void mission_brief_q_branch_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        mission_brief_index = BRIEF_INDEX_M;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        mission_brief_index = BRIEF_INDEX_MONEYPENNY;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}

void mission_brief_moneypenny_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        mission_brief_index = BRIEF_INDEX_Q;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        mission_brief_index = BRIEF_INDEX_OBJECTIVES;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}

void mission_brief_objectives_navigation(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS|U_JPAD) || sub_GAME_7F0A5088())
    {
        mission_brief_index = BRIEF_INDEX_MONEYPENNY;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
        return;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS|D_JPAD) || sub_GAME_7F0A50C4())
    {
        mission_brief_index = BRIEF_INDEX_BACKGROUND;
        set_D_80040AE0_0();
        reset_watch_item_is_actively_selected();
    }
}


#ifdef NONMATCHING
void sub_GAME_7F0A68D8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800584AC
.word 0x48507100 /*213444.0*/
.text
glabel sub_GAME_7F0A68D8
/* 0DB408 7F0A68D8 3C098004 */  lui   $t1, %hi(D_80040B40)
/* 0DB40C 7F0A68DC 25290B40 */  addiu $t1, %lo(D_80040B40) # addiu $t1, $t1, 0xb40
/* 0DB410 7F0A68E0 8D220000 */  lw    $v0, ($t1)
/* 0DB414 7F0A68E4 3C018006 */  lui   $at, %hi(D_800584AC)
/* 0DB418 7F0A68E8 C42484AC */  lwc1  $f4, %lo(D_800584AC)($at)
/* 0DB41C 7F0A68EC 00420019 */  multu $v0, $v0
/* 0DB420 7F0A68F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DB424 7F0A68F4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DB428 7F0A68F8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0DB42C 7F0A68FC 00007012 */  mflo  $t6
/* 0DB430 7F0A6900 448E3000 */  mtc1  $t6, $f6
/* 0DB434 7F0A6904 00000000 */  nop
/* 0DB438 7F0A6908 46803220 */  cvt.s.w $f8, $f6
/* 0DB43C 7F0A690C 0C007DF8 */  jal   sqrtf
/* 0DB440 7F0A6910 46082301 */   sub.s $f12, $f4, $f8
/* 0DB444 7F0A6914 4600028D */  trunc.w.s $f10, $f0
/* 0DB448 7F0A6918 3C098004 */  lui   $t1, %hi(D_80040B40)
/* 0DB44C 7F0A691C 3C078004 */  lui   $a3, %hi(D_80040B08)
/* 0DB450 7F0A6920 25290B40 */  addiu $t1, %lo(D_80040B40) # addiu $t1, $t1, 0xb40
/* 0DB454 7F0A6924 44055000 */  mfc1  $a1, $f10
/* 0DB458 7F0A6928 8FA40018 */  lw    $a0, 0x18($sp)
/* 0DB45C 7F0A692C 24E70B08 */  addiu $a3, %lo(D_80040B08) # addiu $a3, $a3, 0xb08
/* 0DB460 7F0A6930 00001825 */  move  $v1, $zero
/* 0DB464 7F0A6934 240A0008 */  li    $t2, 8
/* 0DB468 7F0A6938 24080003 */  li    $t0, 3
/* 0DB46C 7F0A693C 240600A0 */  li    $a2, 160
/* 0DB470 7F0A6940 2402FFFF */  li    $v0, -1
.L7F0A6944:
/* 0DB474 7F0A6944 00A20019 */  multu $a1, $v0
/* 0DB478 7F0A6948 A4800002 */  sh    $zero, 2($a0)
/* 0DB47C 7F0A694C 24420002 */  addiu $v0, $v0, 2
/* 0DB480 7F0A6950 24840010 */  addiu $a0, $a0, 0x10
/* 0DB484 7F0A6954 0000C012 */  mflo  $t8
/* 0DB488 7F0A6958 A498FFF0 */  sh    $t8, -0x10($a0)
/* 0DB48C 7F0A695C 8D390000 */  lw    $t9, ($t1)
/* 0DB490 7F0A6960 A480FFF6 */  sh    $zero, -0xa($a0)
/* 0DB494 7F0A6964 A480FFF8 */  sh    $zero, -8($a0)
/* 0DB498 7F0A6968 00795821 */  addu  $t3, $v1, $t9
/* 0DB49C 7F0A696C A48BFFF4 */  sh    $t3, -0xc($a0)
/* 0DB4A0 7F0A6970 A480FFFA */  sh    $zero, -6($a0)
/* 0DB4A4 7F0A6974 A080FFFC */  sb    $zero, -4($a0)
/* 0DB4A8 7F0A6978 A086FFFD */  sb    $a2, -3($a0)
/* 0DB4AC 7F0A697C A080FFFE */  sb    $zero, -2($a0)
/* 0DB4B0 7F0A6980 8CEC0000 */  lw    $t4, ($a3)
/* 0DB4B4 7F0A6984 1448FFEF */  bne   $v0, $t0, .L7F0A6944
/* 0DB4B8 7F0A6988 A08CFFFF */   sb    $t4, -1($a0)
/* 0DB4BC 7F0A698C 24630004 */  addiu $v1, $v1, 4
/* 0DB4C0 7F0A6990 546AFFEC */  bnel  $v1, $t2, .L7F0A6944
/* 0DB4C4 7F0A6994 2402FFFF */   li    $v0, -1
/* 0DB4C8 7F0A6998 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DB4CC 7F0A699C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0DB4D0 7F0A69A0 03E00008 */  jr    $ra
/* 0DB4D4 7F0A69A4 00000000 */   nop
)
#endif



void sub_GAME_7F0A69A8(void)
{
    if (joyGetControllerCount() < 2)
    {
        D_800409D8 = 4;
    }
    else
    {
        D_800409D8 = 8;
    }
    reset_watch_item_is_actively_selected();
    watch_screen_index = WATCH_INDEX_MISSION_STATUS;
    mission_brief_index = BRIEF_INDEX_OBJECTIVES;
    D_800409C8 = 0.999f;
    D_800409CC = 0.9999f;
    bondinvDetermineEquippedItem();
}


/**
 * Address 0x7F0A6A2C. (VERSION_US, VERSION_JP)
 * Address 0x7F0A5D78. (VERSION_EU)
*/
f32 sub_GAME_7F0A6A2C(f32 arg0)
{
    if (arg0 > 3.1415927f)
    {
        arg0 = arg0 - M_TAU_F;
    }
    else if (arg0 < -3.1415927f)
    {
        arg0 = arg0 + M_TAU_F;
    }
    return arg0;
}


extern f32 jpD_800484D0;
void sub_GAME_7F0A6A80(void)
{
    u32 temp_1;
    s32 temp_2;
    s32 temp_3;
    u32 random_value;

    if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON))
    {
        set_open_close_solo_watch_menu_to1();
    }

    if (controlstick_lr_enabled == 0)
    {
        if ((joyGetStickX(PLAYER_1) >= -0xA) && (joyGetStickX(PLAYER_1) < 0xB))
        {
            controlstick_lr_enabled = 1;
        }
        else if ((joyGetStickX(PLAYER_1) < 0xB) && (joy7000C174(PLAYER_1) >= 0xB))
        {
            controlstick_lr_enabled = 1;
        }
        else if ((joyGetStickX(PLAYER_1) >= -0xA) && (joy7000C174(PLAYER_1) < -0xA))
        {
            controlstick_lr_enabled = 1;
        }
    }

    if (D_80040AE0 == 0)
    {
        if ((joyGetStickY(PLAYER_1) >= -0xA) && (joyGetStickY(PLAYER_1) < 0xB))
        {
            D_80040AE0 = 1;
        }
        else if ((joyGetStickY(PLAYER_1) < 0xB) && (joy7000C284(PLAYER_1) >= 0xB))
        {
            D_80040AE0 = 1;
        }
        else if ((joyGetStickY(PLAYER_1) >= -0xA) && (joy7000C284(PLAYER_1) < -0xA))
        {
            D_80040AE0 = 1;
        }
    }

    temp_2 = D_80040AF8;
    if (temp_2 < 0)
    {
        D_80040AF4 = D_80040AF4 + 0xFFF00000;
    }
    D_80040AF8 = temp_2 - 1;

    if (D_80040AF4 < 0x5F00A1U)
    {
        D_80040AF4 = 0xFF00A0U;
        D_80040AF8 = 0xF;
    }

    temp_3 = D_80040B00;
    if (temp_3 < 0)
    {
        D_80040AFC = D_80040AFC - 0x10;
    }
    D_80040B00 = temp_3 - 1;

    if (D_80040AFC < 0x60U)
    {
        D_80040AFC = 0xFFU;
        D_80040B00 = 0xF;
    }
    #ifdef VERSION_US
    D_80040B14 += ((D_80040B1C * speedgraphframes * M_TAU_F) / 360.0f);
    #else
    D_80040B14 += ((D_80040B1C * jpD_800484D0 * M_TAU_F) / 360.0f);
    #endif

    D_80040B14 = sub_GAME_7F0A6A2C(D_80040B14);

    temp_1 = D_80040B0C << 0x10;
    if (temp_1 < randomGetNext())
    {
        sub_GAME_7F0A51D8();
    }

    if (g_WatchBackgroundGreen < 0xE0)
    {
        random_value = randomGetNext();
        g_WatchBackgroundGreen += (random_value >> 0x1E);
    }

    if (g_WatchBackgroundGreen > 0xe0) {
        g_WatchBackgroundGreen = 0xe0;
    }

    D_80040B08 = ((-g_WatchBackgroundGreen * 4) + 0x380);
    D_80040B40 = D_80040B40 - 4;

    if (D_80040B40 >= 0x157) {
        D_80040B40 = -0x156;
    }

    if (D_80040B40 < -0x156) {
        D_80040B40 = 0x156;
    }

    D_80040B44 = (s16)D_80040B44 + 1;
    D_80040B44 = (s16)D_80040B44 & 1;

    switch (watch_screen_index)
    {
        case WATCH_INDEX_MISSION_STATUS:
            watch_screen0_navigation();
            break;

        case WATCH_INDEX_CONTROL_OPTIONS:
            switch (controller_options_index)
            {
                case CONTROLLER_OPTIONS_INDEX_STYLE:
                    controller_options_controlstyle_navigation();
                    break;

                case CONTROLLER_OPTIONS_INDEX_INPUTS:
                    controller_options_inputs_navigation();
            }
            watch_screen2_navigation();
            break;

        case WATCH_INDEX_GAME_OPTIONS:
            switch (game_options_index)
            {
                case GAME_OPTIONS_INDEX_MUSIC:
                    game_options_music_volume_navigation();
                    break;

                case GAME_OPTIONS_INDEX_FX:
                    game_options_fx_volume_navigation();
                    break;

                case GAME_OPTIONS_INDEX_LOOK_UPDOWN:
                case GAME_OPTIONS_INDEX_AUTO_AIM:
                case GAME_OPTIONS_INDEX_AIM_CONTROL:
                case GAME_OPTIONS_INDEX_SIGHT_ONSCREEN:
                case GAME_OPTIONS_INDEX_LOOK_AHEAD:
                case GAME_OPTIONS_INDEX_AMMO_ONSCREEN:
                case GAME_OPTIONS_INDEX_SCREEN_SIZE:
                case GAME_OPTIONS_INDEX_RATIO:
                    sub_GAME_7F0A5998();
            }
            watch_screen3_navigation();
            break;

        case WATCH_INDEX_MISSION_BRIEFING:
            watch_screen4_navigation();
            break;

        case WATCH_INDEX_INVENTORY:
            watch_screen1_navigation();
    }
}



Gfx *sub_GAME_7F0A6EE8(Gfx *DL)
{
    gSPSetGeometryMode(DL++, G_CULL_BACK);
    gDPSetCycleType(DL++, G_CYC_1CYCLE);
    gDPPipelineMode(DL++, G_PM_1PRIMITIVE);
    gDPSetScissor(DL++, G_SC_NON_INTERLACE, 0, 0,viGetX(), viGetY() );
    gDPSetTextureLOD(DL++, G_TL_TILE);
    gDPSetTextureLUT(DL++, G_TT_NONE);
    gDPSetTextureDetail(DL++, G_TD_CLAMP);
    gDPSetTexturePersp(DL++, G_TP_PERSP);
    gDPSetTextureFilter(DL++, G_TF_BILERP);
    gDPSetTextureConvert(DL++, G_TC_FILT);
    gDPSetCombineLERP(DL++, 0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE);
    gDPSetCombineKey(DL++, G_CK_NONE);
    gDPSetAlphaCompare(DL++, G_AC_NONE);
    gDPSetRenderMode(DL++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorDither(DL++, G_CD_MAGICSQ);

    return DL;
}


#ifdef NONMATCHING
/**
 * Decomp notes: match down to regalloc.
*/
void set_page_rectangle_colors(s32 watch_screen_index, struct WatchVertex *arg2)
{
    s32 i;
    s32 limit;

    // Default color for rectangle.
    for (i=0; i<(4 * WATCH_NUMBER_SCREENS); i++)
    {
        arg2[i].color.r = 0x20;
        arg2[i].color.g = 0x70;
        arg2[i].color.b = 0x20;
    }

    i = watch_screen_index * 4;
    limit = i + 3;
    for ( ; i <= limit; i++)
    {
        // Color of currently selected screen
        arg2[i].color.r = 0x50;
        arg2[i].color.g = 0xF0;
        arg2[i].color.b = 0x50;

        if (watch_item_is_actively_selected)
        {
            // Color of currently selected screen when a menu option is selected.
            // This applies on main screen, game options, controller options, objective status, but not inventory.
            arg2[i].color.r = 0x30;
            arg2[i].color.g = 0xA0;
            arg2[i].color.b = 0x30;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel set_page_rectangle_colors
/* 0DBBDC 7F0A70AC 00001025 */  move  $v0, $zero
/* 0DBBE0 7F0A70B0 00A01825 */  move  $v1, $a1
/* 0DBBE4 7F0A70B4 24070070 */  li    $a3, 112
/* 0DBBE8 7F0A70B8 24060020 */  li    $a2, 32
.L7F0A70BC:
/* 0DBBEC 7F0A70BC 24420001 */  addiu $v0, $v0, 1
/* 0DBBF0 7F0A70C0 28410014 */  slti  $at, $v0, 0x14
/* 0DBBF4 7F0A70C4 24630010 */  addiu $v1, $v1, 0x10
/* 0DBBF8 7F0A70C8 A066FFFC */  sb    $a2, -4($v1)
/* 0DBBFC 7F0A70CC A067FFFD */  sb    $a3, -3($v1)
/* 0DBC00 7F0A70D0 1420FFFA */  bnez  $at, .L7F0A70BC
/* 0DBC04 7F0A70D4 A066FFFE */   sb    $a2, -2($v1)
/* 0DBC08 7F0A70D8 00041880 */  sll   $v1, $a0, 2
/* 0DBC0C 7F0A70DC 24660003 */  addiu $a2, $v1, 3
/* 0DBC10 7F0A70E0 00C3082A */  slt   $at, $a2, $v1
/* 0DBC14 7F0A70E4 14200017 */  bnez  $at, .L7F0A7144
/* 0DBC18 7F0A70E8 00037100 */   sll   $t6, $v1, 4
/* 0DBC1C 7F0A70EC 00067900 */  sll   $t7, $a2, 4
/* 0DBC20 7F0A70F0 01E52021 */  addu  $a0, $t7, $a1
/* 0DBC24 7F0A70F4 3C068004 */  lui   $a2, %hi(watch_item_is_actively_selected)
/* 0DBC28 7F0A70F8 00AE1821 */  addu  $v1, $a1, $t6
/* 0DBC2C 7F0A70FC 240500F0 */  li    $a1, 240
/* 0DBC30 7F0A7100 24C609A8 */  addiu $a2, %lo(watch_item_is_actively_selected) # addiu $a2, $a2, 0x9a8
/* 0DBC34 7F0A7104 240800A0 */  li    $t0, 160
/* 0DBC38 7F0A7108 24070030 */  li    $a3, 48
/* 0DBC3C 7F0A710C 24020050 */  li    $v0, 80
/* 0DBC40 7F0A7110 A062000C */  sb    $v0, 0xc($v1)
.L7F0A7114:
/* 0DBC44 7F0A7114 A065000D */  sb    $a1, 0xd($v1)
/* 0DBC48 7F0A7118 A062000E */  sb    $v0, 0xe($v1)
/* 0DBC4C 7F0A711C 8CD80000 */  lw    $t8, ($a2)
/* 0DBC50 7F0A7120 53000005 */  beql  $t8, $zero, .L7F0A7138
/* 0DBC54 7F0A7124 24630010 */   addiu $v1, $v1, 0x10
/* 0DBC58 7F0A7128 A067000C */  sb    $a3, 0xc($v1)
/* 0DBC5C 7F0A712C A068000D */  sb    $t0, 0xd($v1)
/* 0DBC60 7F0A7130 A067000E */  sb    $a3, 0xe($v1)
/* 0DBC64 7F0A7134 24630010 */  addiu $v1, $v1, 0x10
.L7F0A7138:
/* 0DBC68 7F0A7138 0083082B */  sltu  $at, $a0, $v1
/* 0DBC6C 7F0A713C 5020FFF5 */  beql  $at, $zero, .L7F0A7114
/* 0DBC70 7F0A7140 A062000C */   sb    $v0, 0xc($v1)
.L7F0A7144:
/* 0DBC74 7F0A7144 03E00008 */  jr    $ra
/* 0DBC78 7F0A7148 00000000 */   nop
)
#endif





/**
 * @param gdl:
 * @param arg1: Something about watch view matrix.
 * @param zoom_squish: When set, will "unfold" the interior watch watch area (green + bars)
 * based on view distance during pause animation. This is used when starting to pause and bring
 * the watch up, and exiting pause menu to resume game play. If this is disabled then
 * the interior area will always be the same size as the watch container.
*/
Gfx *draw_background_health_and_armor(Gfx *gdl, Mtx *arg1, s32 zoom_squish)
{
    int i;
    struct WatchVertex *sp48;
    struct WatchVertex *sp44;
    Gfx *sp40;
    Gfx *sp3C;
    
    s32 stack_pad[6];
    
    f32 scale;

    sp48 = dynAllocate7F0BD6C4(WATCH_BACKGROUND_VERTEX_COUNT);
    sp44 = dynAllocate7F0BD6C4(WATCH_BACKGROUND_VERTEX_COUNT);
    sp40 = dynAllocate(0xF8);
    sp3C = dynAllocate(0xF8);

    /**
     * It seems at this point in rendering the background watch arms (hour,minute,second)
     * have already been drawn. Whatever is about to be drawn next is oriented
     * to the second hand of the watch.
     * The following commands reset the orientation for the background green
     * area and health bars. Or, commenting this out will draw the background
     * and slowly spin it around in sync with the second hand.
    */
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gDPSetPrimColor(gdl++, 0, 0, 0xE6, 0xE6, 0xE6, 0x00);
    gSPMatrix(gdl++, arg1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    // end initial setup.

    scale = 1;

    if (check_watch_page_transistion_running())
    {
        scale = (g_CurrentPlayer->zoomintime * (g_CurrentPlayer->zoominfovynew - g_CurrentPlayer->zoominfovyold)) 
            / g_CurrentPlayer->zoomintimemax;

        if (scale < 0.0f)
        {
            scale = -scale;
        }

        if (scale > 1)
        {
            scale = 1;
        }

        scale = scale * scale;
    }

    if (zoom_squish == 1)
    {
        scale = 0.05f;
        g_WatchBackgroundGreen = 0xE0;

        if (g_CurrentPlayer->watch_animation_state == 4 || g_CurrentPlayer->watch_animation_state == 6)
        {
            scale = bondviewWatchAnimationRelated();
        }
    }
    
    guScale(&gfx_background_8007B0A0, 0.25f, 0.25f, 0.25f);

    gSPMatrix(gdl++, &gfx_background_8007B0A0, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (zoom_squish == 0)
    {
        gSPClearGeometryMode(gdl++, G_CULL_BOTH);
        // draw body armor bars
        gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(&g_CurrentPlayer->watch_body_armor_bar_gdl));
        // draw health bars
        gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(&g_CurrentPlayer->watch_health_bar_gdl));
    }

    /**
     * This section renders main background, side health bar & body armor bars while zooming in or out.
    */
    guScale(&gfx_background_8007B0E0, 1, 1, scale);

    gSPMatrix(gdl++, &gfx_background_8007B0E0, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (zoom_squish == 1)
    {
        gSPClearGeometryMode(gdl++, G_CULL_BOTH);
        // draw body armor bars
        gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(&g_CurrentPlayer->watch_body_armor_bar_gdl));
        // draw health bars
        gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(&g_CurrentPlayer->watch_health_bar_gdl));
    }
    /**
     * End health bar zoom section
    */

    sub_GAME_7F0A33F8(sp44, WATCH_BACKGROUND_VERTEX_COUNT, 0.92f, 0);
    /*sp3C = */sub_GAME_7F0A3978(sp3C, OS_PHYSICAL_TO_K0(sp44), WATCH_BACKGROUND_VERTEX_COUNT, 0);

    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, 0x00, 0xFF, 0x00, 0x00);
    gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(sp3C));
    gDPPipeSync(gdl++);

    /**
     * This section renders the green background area of the watch menu.
    */
    if (g_WatchBackgroundGreen < 0xE0)
    {
        sub_GAME_7F0A33F8(sp48, WATCH_BACKGROUND_VERTEX_COUNT, 0.899999976158f, 0);
        /*sp40 = */sub_GAME_7F0A3978(sp40, OS_PHYSICAL_TO_K0(sp48), WATCH_BACKGROUND_VERTEX_COUNT, 0);

        gDPSetRenderMode(gdl++, G_RM_AA_PCL_SURF, G_RM_AA_PCL_SURF2);
    }
    else
    {
        sub_GAME_7F0A33F8(sp48, WATCH_BACKGROUND_VERTEX_COUNT, 0.899999976158f, 1);
        /*sp40 = */sub_GAME_7F0A3978(sp40, OS_PHYSICAL_TO_K0(sp48), WATCH_BACKGROUND_VERTEX_COUNT, 1);
        
        gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }

    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(sp40));
    /**
     * // end green background area.
    */

    /**
     * This section renders the green rectangles/page select at the bottom of the screen.
     * This is setup in bondview trigger_solo_watch_menu.
    */
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(g_CurrentPlayer->buffer_for_watch_greenbackdrop_DL));
    /**
     * // end green rectangles/page select section
    */

    for (i=0; i<WATCH_BACKGROUND_VERTEX_COUNT; i++)
    {
        sp48[i].color.a = (s8)g_WatchBackgroundGreen;
        sp44[i].color.a = (s8)g_WatchBackgroundGreen;
    }

    if (g_WatchBackgroundGreen < 0xE0)
    {
        sub_GAME_7F0A68D8(g_CurrentPlayer->buffer_for_watch_static_vertices);

        gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(g_CurrentPlayer->buffer_for_watch_static_DL));
    }

    return gdl;
}

Gfx *draw_background_health_and_armor_transitioning(Gfx *gdl, Mtx *param_2)
{
    return draw_background_health_and_armor(gdl, param_2, 1);
}


Gfx *draw_abort_cancel_confirm(Gfx *gdl)
{
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;

    s32 pFirstFontTable;
    s32 pSecondFontTable;
    s32 sp54;
    s32 sp50;
    s32 sp4C;

    pFirstFontTable = ptrFirstFontTableSmall;
    pSecondFontTable = ptrSecondFontTableSmall;
    sp54 = langGet(TEXT(LOPTIONS, 0x24)); //abort:
    sp50 = langGet(TEXT(LOPTIONS, 0x25)); //confirm
    sp4C = langGet(TEXT(LOPTIONS, 0x26)); //cancel
    sp7C = 0x51;

    sp78 = (j_text_trigger ? 0xF : 0) + 0xBD;
    
    sp74 = (j_text_trigger ? 0xA : 0) + 0x88;
    
    sp70 = sp6C = sp68 = (j_text_trigger ? 3 : 0) + (PAL ? 0x4E : 0x4C);

    if (watch_item_is_actively_selected != 0)
    {
        if (D_800409A4 == 0)
        {
            if ((joyGetStickX(PLAYER_1) >= 0x2E) || (joyGetButtons(PLAYER_1, 0x111) != 0))
            {
                D_800409A4 = 1;
            }
        }
        else
        {
            if (D_800409A4 != 0)
            {
                if ((joyGetStickX(PLAYER_1) < -0x2D) || (joyGetButtons(PLAYER_1, 0x222) != 0))
                {
                    D_800409A4 = 0;
                }
            }
        }
    }

    if (watch_item_is_actively_selected != 0)
    {
        sub_GAME_7F0AE98C(&sp60, &sp64, sp54, pSecondFontTable, pFirstFontTable, 0);

        gdl = en_text_write_stuff(gdl, &sp7C, &sp70, sp54, pSecondFontTable, pFirstFontTable, 0xA0FFA0F0, sp64, sp60, 0, 0);

        if (D_800409A4 != 0)
        {
            gdl = jp_text_write_stuff(gdl, &sp78, &sp6C, sp50, pSecondFontTable, pFirstFontTable, -1, 0x7000A0, viGetX(), viGetY(), 0, 0);
            gdl = en_text_write_stuff(gdl, &sp74, &sp68, sp4C, pSecondFontTable, pFirstFontTable, 0xFF00B0, viGetX(), viGetY(), 0, 0);
        }
        else
        {
            if (D_800409A4 == 0)
            {
                gdl = en_text_write_stuff(gdl, &sp78, &sp6C, sp50, pSecondFontTable, pFirstFontTable, 0xFF00B0, viGetX(), viGetY(), 0, 0);
                gdl = jp_text_write_stuff(gdl, &sp74, &sp68, sp4C, pSecondFontTable, pFirstFontTable, -1, 0x7000A0, viGetX(), viGetY(), 0, 0);
            }
        }
    }
    else
    {
        sub_GAME_7F0AE98C(&sp60, &sp64, sp54, pSecondFontTable, pFirstFontTable, 0);
        gdl = en_text_write_stuff(gdl, &sp7C, &sp70, sp54, pSecondFontTable, pFirstFontTable, 0x800080, sp64, sp60, 0, 0);
        gdl = en_text_write_stuff(gdl, &sp78, &sp6C, sp50, pSecondFontTable, pFirstFontTable, 0x800080, viGetX(), viGetY(), 0, 0);
        gdl = en_text_write_stuff(gdl, &sp74, &sp68, sp4C, pSecondFontTable, pFirstFontTable, 0x800080, viGetX(), viGetY(), 0, 0);
    }

    return gdl;
}


Gfx *draw_text_mission_status(Gfx *gdl)
{
    s32 txtptr_1;
    s32 txtptr_2;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 ptr_first_font;
    s32 ptr_second_font;
    s32 sp4C;
    s32 joffset;

    txtptr_1 = langGet(TEXT(LOPTIONS, 0x27)); //mission status:
    ptr_first_font = ptrFirstFontTableSmall;
    ptr_second_font = ptrSecondFontTableSmall;

    if (objectiveIsAllComplete())
    {
        sp4C = 0xFF00B0;
        txtptr_2 = langGet(TEXT(LOPTIONS, 0x28)); //complete
    }
    else
    {
        sp4C = D_80040AF4;
        txtptr_2 = langGet(TEXT(LOPTIONS, 0x29)); //incomplete
    }

    gdl = microcode_constructor(gdl);
    sub_GAME_7F0AE98C(&sp5C, &sp58, txtptr_1, ptr_second_font, ptr_first_font, 0);
    sp64 = 0x51;
    sp60 = YOFFSET_MISSIONSTATUS;
    gdl = en_text_write_stuff(gdl, &sp64, &sp60, txtptr_1, ptr_second_font, ptr_first_font, 0xFF00B0, sp58, sp5C, 0, 0);

    if (j_text_trigger)
    {
        joffset = 0x22;
    }
    else
    {
        joffset = 0;
    }

    sp64 = sp64 + sp58 + joffset + 4;
    sp60 = sp60 - sp5C;
    sub_GAME_7F0AE98C(&sp5C, &sp58, txtptr_2, ptr_second_font, ptr_first_font, 0);
    gdl = en_text_write_stuff(gdl, &sp64, &sp60, txtptr_2, ptr_second_font, ptr_first_font, sp4C, sp58, sp5C, 0, 0);
    gdl = draw_abort_cancel_confirm(gdl);

    return gdl;
}


Gfx *empty_draw_function(Gfx *gdl) {
  return gdl;
}


Gfx *draw_text_q_watch_v201_beta(Gfx *gdl)
{
    s32 txtptr;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 pFirstFontTable;
    s32 pSecondFontTable;
    s32 joffset;

    txtptr = langGet(TEXT(LOPTIONS, 0x2B)); //q watch v2.01 beta

    if (j_text_trigger)
    {
        joffset = -5;
    }
    else
    {
        joffset = 0;
    }
    sp50 = joffset + 0x65;
    sp4C = YOFFSET_7;
    sp48 = 0;
    sp44 = 0;
    pFirstFontTable = ptrFirstFontTableSmall;
    pSecondFontTable = ptrSecondFontTableSmall;
    gdl = microcode_constructor(gdl);
    sub_GAME_7F0AE98C(&sp48, &sp44, txtptr, pSecondFontTable, pFirstFontTable, 0);
    gdl = en_text_write_stuff(gdl, &sp50, &sp4C, txtptr, pSecondFontTable, pFirstFontTable, 0xFF00B0, sp44, sp48, 0, 0);
    return gdl;
}




#ifdef NONMATCHING
void draw_current_hand_item_and_ammo(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8005850C
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058510
.word 0x3f829cbc /*1.0204082*/
glabel D_80058514
.word 0x461c4000 /*10000.0*/
glabel D_80058518
.word 0x40c90fdb /*6.2831855*/
glabel D_8005851C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058520
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058524
.word 0x3f829cbc /*1.0204082*/
glabel D_80058528
.word 0x461c4000 /*10000.0*/
glabel D_8005852C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058530
.word 0x40c90fdb /*6.2831855*/
.text
glabel draw_current_hand_item_and_ammo
/* 0DC9D8 7F0A7EA8 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0DC9DC 7F0A7EAC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DC9E0 7F0A7EB0 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DC9E4 7F0A7EB4 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0DC9E8 7F0A7EB8 00808025 */   move  $s0, $a0
/* 0DC9EC 7F0A7EBC 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall)
/* 0DC9F0 7F0A7EC0 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall)
/* 0DC9F4 7F0A7EC4 8DCE0EAC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0DC9F8 7F0A7EC8 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0DC9FC 7F0A7ECC AFA20114 */  sw    $v0, 0x114($sp)
/* 0DCA00 7F0A7ED0 AFA00084 */  sw    $zero, 0x84($sp)
/* 0DCA04 7F0A7ED4 AFA00080 */  sw    $zero, 0x80($sp)
/* 0DCA08 7F0A7ED8 AFAE007C */  sw    $t6, 0x7c($sp)
/* 0DCA0C 7F0A7EDC 0FC23630 */  jal   bondinvGetCurEquippedItem
/* 0DCA10 7F0A7EE0 AFAF0078 */   sw    $t7, 0x78($sp)
/* 0DCA14 7F0A7EE4 AFA20074 */  sw    $v0, 0x74($sp)
/* 0DCA18 7F0A7EE8 0FC234AA */  jal   bondinvGetTextbyInvIndex
/* 0DCA1C 7F0A7EEC 00402025 */   move  $a0, $v0
/* 0DCA20 7F0A7EF0 AFA20070 */  sw    $v0, 0x70($sp)
/* 0DCA24 7F0A7EF4 0FC235F6 */  jal   bondinvGetVposWatchForIndex
/* 0DCA28 7F0A7EF8 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA2C 7F0A7EFC E7A0006C */  swc1  $f0, 0x6c($sp)
/* 0DCA30 7F0A7F00 0FC23600 */  jal   bondinvGetHposWatchForIndex
/* 0DCA34 7F0A7F04 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA38 7F0A7F08 E7A00068 */  swc1  $f0, 0x68($sp)
/* 0DCA3C 7F0A7F0C 0FC2360A */  jal   bondinvGetDepthWatchForIndex
/* 0DCA40 7F0A7F10 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA44 7F0A7F14 E7A00064 */  swc1  $f0, 0x64($sp)
/* 0DCA48 7F0A7F18 0FC235EC */  jal   bondinvGetDifferent45AngleForIndex
/* 0DCA4C 7F0A7F1C 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA50 7F0A7F20 E7A00060 */  swc1  $f0, 0x60($sp)
/* 0DCA54 7F0A7F24 0FC23614 */  jal   bondinvGetXrotWatchForIndex
/* 0DCA58 7F0A7F28 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA5C 7F0A7F2C E7A0005C */  swc1  $f0, 0x5c($sp)
/* 0DCA60 7F0A7F30 0FC2361E */  jal   bondinvGetYrotWatchForIndex
/* 0DCA64 7F0A7F34 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA68 7F0A7F38 E7A00058 */  swc1  $f0, 0x58($sp)
/* 0DCA6C 7F0A7F3C 0FC23572 */  jal   bondinvGetFirstTitlebyIndex
/* 0DCA70 7F0A7F40 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA74 7F0A7F44 AFA20054 */  sw    $v0, 0x54($sp)
/* 0DCA78 7F0A7F48 0FC235AF */  jal   bondinvGetSecondTitlebyIndex
/* 0DCA7C 7F0A7F4C 8FA40074 */   lw    $a0, 0x74($sp)
/* 0DCA80 7F0A7F50 0FC24415 */  jal   get_debug_gunwatchpos_flag
/* 0DCA84 7F0A7F54 AFA20050 */   sw    $v0, 0x50($sp)
/* 0DCA88 7F0A7F58 5040004C */  beql  $v0, $zero, .L7F0A808C
/* 0DCA8C 7F0A7F5C 3C014120 */   lui   $at, 0x4120
/* 0DCA90 7F0A7F60 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 0DCA94 7F0A7F64 00002025 */   move  $a0, $zero
/* 0DCA98 7F0A7F68 0002C0C0 */  sll   $t8, $v0, 3
/* 0DCA9C 7F0A7F6C 0302C023 */  subu  $t8, $t8, $v0
/* 0DCAA0 7F0A7F70 3C198003 */  lui   $t9, %hi(gitem_structs)
/* 0DCAA4 7F0A7F74 27393924 */  addiu $t9, %lo(gitem_structs) # addiu $t9, $t9, 0x3924
/* 0DCAA8 7F0A7F78 0018C0C0 */  sll   $t8, $t8, 3
/* 0DCAAC 7F0A7F7C 03191821 */  addu  $v1, $t8, $t9
/* 0DCAB0 7F0A7F80 AFA3004C */  sw    $v1, 0x4c($sp)
/* 0DCAB4 7F0A7F84 00002025 */  move  $a0, $zero
/* 0DCAB8 7F0A7F88 0C0030C3 */  jal   joyGetButtons
/* 0DCABC 7F0A7F8C 24050002 */   li    $a1, 2
/* 0DCAC0 7F0A7F90 10400006 */  beqz  $v0, .L7F0A7FAC
/* 0DCAC4 7F0A7F94 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCAC8 7F0A7F98 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DCACC 7F0A7F9C 44813000 */  mtc1  $at, $f6
/* 0DCAD0 7F0A7FA0 C4640018 */  lwc1  $f4, 0x18($v1)
/* 0DCAD4 7F0A7FA4 46062201 */  sub.s $f8, $f4, $f6
/* 0DCAD8 7F0A7FA8 E4680018 */  swc1  $f8, 0x18($v1)
.L7F0A7FAC:
/* 0DCADC 7F0A7FAC 00002025 */  move  $a0, $zero
/* 0DCAE0 7F0A7FB0 24050001 */  li    $a1, 1
/* 0DCAE4 7F0A7FB4 0C0030C3 */  jal   joyGetButtons
/* 0DCAE8 7F0A7FB8 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0DCAEC 7F0A7FBC 10400006 */  beqz  $v0, .L7F0A7FD8
/* 0DCAF0 7F0A7FC0 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCAF4 7F0A7FC4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DCAF8 7F0A7FC8 44818000 */  mtc1  $at, $f16
/* 0DCAFC 7F0A7FCC C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0DCB00 7F0A7FD0 46105480 */  add.s $f18, $f10, $f16
/* 0DCB04 7F0A7FD4 E4720018 */  swc1  $f18, 0x18($v1)
.L7F0A7FD8:
/* 0DCB08 7F0A7FD8 00002025 */  move  $a0, $zero
/* 0DCB0C 7F0A7FDC 24050004 */  li    $a1, 4
/* 0DCB10 7F0A7FE0 0C0030C3 */  jal   joyGetButtons
/* 0DCB14 7F0A7FE4 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0DCB18 7F0A7FE8 10400006 */  beqz  $v0, .L7F0A8004
/* 0DCB1C 7F0A7FEC 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCB20 7F0A7FF0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DCB24 7F0A7FF4 44813000 */  mtc1  $at, $f6
/* 0DCB28 7F0A7FF8 C4640014 */  lwc1  $f4, 0x14($v1)
/* 0DCB2C 7F0A7FFC 46062200 */  add.s $f8, $f4, $f6
/* 0DCB30 7F0A8000 E4680014 */  swc1  $f8, 0x14($v1)
.L7F0A8004:
/* 0DCB34 7F0A8004 00002025 */  move  $a0, $zero
/* 0DCB38 7F0A8008 24050008 */  li    $a1, 8
/* 0DCB3C 7F0A800C 0C0030C3 */  jal   joyGetButtons
/* 0DCB40 7F0A8010 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0DCB44 7F0A8014 10400006 */  beqz  $v0, .L7F0A8030
/* 0DCB48 7F0A8018 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCB4C 7F0A801C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DCB50 7F0A8020 44818000 */  mtc1  $at, $f16
/* 0DCB54 7F0A8024 C46A0014 */  lwc1  $f10, 0x14($v1)
/* 0DCB58 7F0A8028 46105481 */  sub.s $f18, $f10, $f16
/* 0DCB5C 7F0A802C E4720014 */  swc1  $f18, 0x14($v1)
.L7F0A8030:
/* 0DCB60 7F0A8030 00002025 */  move  $a0, $zero
/* 0DCB64 7F0A8034 24050020 */  li    $a1, 32
/* 0DCB68 7F0A8038 0C0030C3 */  jal   joyGetButtons
/* 0DCB6C 7F0A803C AFA3004C */   sw    $v1, 0x4c($sp)
/* 0DCB70 7F0A8040 10400006 */  beqz  $v0, .L7F0A805C
/* 0DCB74 7F0A8044 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCB78 7F0A8048 3C018006 */  lui   $at, %hi(D_8005850C)
/* 0DCB7C 7F0A804C C426850C */  lwc1  $f6, %lo(D_8005850C)($at)
/* 0DCB80 7F0A8050 C464001C */  lwc1  $f4, 0x1c($v1)
/* 0DCB84 7F0A8054 46062202 */  mul.s $f8, $f4, $f6
/* 0DCB88 7F0A8058 E468001C */  swc1  $f8, 0x1c($v1)
.L7F0A805C:
/* 0DCB8C 7F0A805C 00002025 */  move  $a0, $zero
/* 0DCB90 7F0A8060 24050010 */  li    $a1, 16
/* 0DCB94 7F0A8064 0C0030C3 */  jal   joyGetButtons
/* 0DCB98 7F0A8068 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0DCB9C 7F0A806C 10400006 */  beqz  $v0, .L7F0A8088
/* 0DCBA0 7F0A8070 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0DCBA4 7F0A8074 3C018006 */  lui   $at, %hi(D_80058510)
/* 0DCBA8 7F0A8078 C4308510 */  lwc1  $f16, %lo(D_80058510)($at)
/* 0DCBAC 7F0A807C C46A001C */  lwc1  $f10, 0x1c($v1)
/* 0DCBB0 7F0A8080 46105482 */  mul.s $f18, $f10, $f16
/* 0DCBB4 7F0A8084 E472001C */  swc1  $f18, 0x1c($v1)
.L7F0A8088:
/* 0DCBB8 7F0A8088 3C014120 */  li    $at, 0x41200000 # 10.000000
.L7F0A808C:
/* 0DCBBC 7F0A808C 44812000 */  mtc1  $at, $f4
/* 0DCBC0 7F0A8090 3C018006 */  lui   $at, %hi(D_80058514)
/* 0DCBC4 7F0A8094 C4268514 */  lwc1  $f6, %lo(D_80058514)($at)
/* 0DCBC8 7F0A8098 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DCBCC 7F0A809C 44814000 */  mtc1  $at, $f8
/* 0DCBD0 7F0A80A0 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0DCBD4 7F0A80A4 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0DCBD8 7F0A80A8 8FA40114 */  lw    $a0, 0x114($sp)
/* 0DCBDC 7F0A80AC 27A50112 */  addiu $a1, $sp, 0x112
/* 0DCBE0 7F0A80B0 8FA60060 */  lw    $a2, 0x60($sp)
/* 0DCBE4 7F0A80B4 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0DCBE8 7F0A80B8 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0DCBEC 7F0A80BC 0C003FAC */  jal   guPerspective
/* 0DCBF0 7F0A80C0 E7A80018 */   swc1  $f8, 0x18($sp)
/* 0DCBF4 7F0A80C4 3C080103 */  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
/* 0DCBF8 7F0A80C8 35080040 */  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0DCBFC 7F0A80CC 02001825 */  move  $v1, $s0
/* 0DCC00 7F0A80D0 AC680000 */  sw    $t0, ($v1)
/* 0DCC04 7F0A80D4 AFA30048 */  sw    $v1, 0x48($sp)
/* 0DCC08 7F0A80D8 8FA40114 */  lw    $a0, 0x114($sp)
/* 0DCC0C 7F0A80DC 0C003A2C */  jal   osVirtualToPhysical
/* 0DCC10 7F0A80E0 26100008 */   addiu $s0, $s0, 8
/* 0DCC14 7F0A80E4 8FA30048 */  lw    $v1, 0x48($sp)
/* 0DCC18 7F0A80E8 3C018006 */  lui   $at, %hi(D_80058518)
/* 0DCC1C 7F0A80EC 27A500D0 */  addiu $a1, $sp, 0xd0
/* 0DCC20 7F0A80F0 AC620004 */  sw    $v0, 4($v1)
/* 0DCC24 7F0A80F4 C4308518 */  lwc1  $f16, %lo(D_80058518)($at)
/* 0DCC28 7F0A80F8 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 0DCC2C 7F0A80FC 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DCC30 7F0A8100 44812000 */  mtc1  $at, $f4
/* 0DCC34 7F0A8104 46105482 */  mul.s $f18, $f10, $f16
/* 0DCC38 7F0A8108 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0DCC3C 7F0A810C 46049303 */   div.s $f12, $f18, $f4
/* 0DCC40 7F0A8110 3C018006 */  lui   $at, %hi(D_8005851C)
/* 0DCC44 7F0A8114 C420851C */  lwc1  $f0, %lo(D_8005851C)($at)
/* 0DCC48 7F0A8118 C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 0DCC4C 7F0A811C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DCC50 7F0A8120 44815000 */  mtc1  $at, $f10
/* 0DCC54 7F0A8124 46003202 */  mul.s $f8, $f6, $f0
/* 0DCC58 7F0A8128 27A50090 */  addiu $a1, $sp, 0x90
/* 0DCC5C 7F0A812C 460A4403 */  div.s $f16, $f8, $f10
/* 0DCC60 7F0A8130 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 0DCC64 7F0A8134 46100301 */   sub.s $f12, $f0, $f16
/* 0DCC68 7F0A8138 27A40090 */  addiu $a0, $sp, 0x90
/* 0DCC6C 7F0A813C 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0DCC70 7F0A8140 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0DCC74 7F0A8144 44800000 */  mtc1  $zero, $f0
/* 0DCC78 7F0A8148 C7A20068 */  lwc1  $f2, 0x68($sp)
/* 0DCC7C 7F0A814C C7AC006C */  lwc1  $f12, 0x6c($sp)
/* 0DCC80 7F0A8150 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DCC84 7F0A8154 44819000 */  mtc1  $at, $f18
/* 0DCC88 7F0A8158 44071000 */  mfc1  $a3, $f2
/* 0DCC8C 7F0A815C 44066000 */  mfc1  $a2, $f12
/* 0DCC90 7F0A8160 27A40090 */  addiu $a0, $sp, 0x90
/* 0DCC94 7F0A8164 8FA50064 */  lw    $a1, 0x64($sp)
/* 0DCC98 7F0A8168 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0DCC9C 7F0A816C E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DCCA0 7F0A8170 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0DCCA4 7F0A8174 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0DCCA8 7F0A8178 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 0DCCAC 7F0A817C 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0DCCB0 7F0A8180 E7B20020 */   swc1  $f18, 0x20($sp)
/* 0DCCB4 7F0A8184 27A40090 */  addiu $a0, $sp, 0x90
/* 0DCCB8 7F0A8188 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0DCCBC 7F0A818C 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0DCCC0 7F0A8190 0FC29BBA */  jal   sub_GAME_7F0A6EE8
/* 0DCCC4 7F0A8194 02002025 */   move  $a0, $s0
/* 0DCCC8 7F0A8198 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen)
/* 0DCCCC 7F0A819C 8C630B04 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0DCCD0 7F0A81A0 00408025 */  move  $s0, $v0
/* 0DCCD4 7F0A81A4 02002025 */  move  $a0, $s0
/* 0DCCD8 7F0A81A8 286100E0 */  slti  $at, $v1, 0xe0
/* 0DCCDC 7F0A81AC 1020000B */  beqz  $at, .L7F0A81DC
/* 0DCCE0 7F0A81B0 8FA50070 */   lw    $a1, 0x70($sp)
/* 0DCCE4 7F0A81B4 3C0964DC */  lui   $t1, (0x64DC6428 >> 16) # lui $t1, 0x64dc
/* 0DCCE8 7F0A81B8 35296428 */  ori   $t1, (0x64DC6428 & 0xFFFF) # ori $t1, $t1, 0x6428
/* 0DCCEC 7F0A81BC AFA90010 */  sw    $t1, 0x10($sp)
/* 0DCCF0 7F0A81C0 00402025 */  move  $a0, $v0
/* 0DCCF4 7F0A81C4 8FA50070 */  lw    $a1, 0x70($sp)
/* 0DCCF8 7F0A81C8 27A600D0 */  addiu $a2, $sp, 0xd0
/* 0DCCFC 7F0A81CC 0FC18C01 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0DCD00 7F0A81D0 24670001 */   addiu $a3, $v1, 1
/* 0DCD04 7F0A81D4 10000008 */  b     .L7F0A81F8
/* 0DCD08 7F0A81D8 00408025 */   move  $s0, $v0
.L7F0A81DC:
/* 0DCD0C 7F0A81DC 3C0A64DC */  lui   $t2, (0x64DC6428 >> 16) # lui $t2, 0x64dc
/* 0DCD10 7F0A81E0 354A6428 */  ori   $t2, (0x64DC6428 & 0xFFFF) # ori $t2, $t2, 0x6428
/* 0DCD14 7F0A81E4 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0DCD18 7F0A81E8 27A600D0 */  addiu $a2, $sp, 0xd0
/* 0DCD1C 7F0A81EC 0FC18C01 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0DCD20 7F0A81F0 240700FF */   li    $a3, 255
/* 0DCD24 7F0A81F4 00408025 */  move  $s0, $v0
.L7F0A81F8:
/* 0DCD28 7F0A81F8 0FC1A8CD */  jal   sub_GAME_7F06A334
/* 0DCD2C 7F0A81FC 02002025 */   move  $a0, $s0
/* 0DCD30 7F0A8200 0FC2B366 */  jal   microcode_constructor
/* 0DCD34 7F0A8204 00402025 */   move  $a0, $v0
/* 0DCD38 7F0A8208 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0DCD3C 7F0A820C 240B0060 */  li    $t3, 96
/* 0DCD40 7F0A8210 240C00A0 */  li    $t4, 160
/* 0DCD44 7F0A8214 00408025 */  move  $s0, $v0
/* 0DCD48 7F0A8218 AFAB008C */  sw    $t3, 0x8c($sp)
/* 0DCD4C 7F0A821C AFAC0088 */  sw    $t4, 0x88($sp)
/* 0DCD50 7F0A8220 27A40084 */  addiu $a0, $sp, 0x84
/* 0DCD54 7F0A8224 27A50080 */  addiu $a1, $sp, 0x80
/* 0DCD58 7F0A8228 8FA60054 */  lw    $a2, 0x54($sp)
/* 0DCD5C 7F0A822C 8FA70078 */  lw    $a3, 0x78($sp)
/* 0DCD60 7F0A8230 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DCD64 7F0A8234 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DCD68 7F0A8238 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0DCD6C 7F0A823C 8FAE0078 */  lw    $t6, 0x78($sp)
/* 0DCD70 7F0A8240 8FAF007C */  lw    $t7, 0x7c($sp)
/* 0DCD74 7F0A8244 8FB90080 */  lw    $t9, 0x80($sp)
/* 0DCD78 7F0A8248 8FA80084 */  lw    $t0, 0x84($sp)
/* 0DCD7C 7F0A824C 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0DCD80 7F0A8250 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DCD84 7F0A8254 AFB80018 */  sw    $t8, 0x18($sp)
/* 0DCD88 7F0A8258 02002025 */  move  $a0, $s0
/* 0DCD8C 7F0A825C 27A5008C */  addiu $a1, $sp, 0x8c
/* 0DCD90 7F0A8260 27A60088 */  addiu $a2, $sp, 0x88
/* 0DCD94 7F0A8264 8FA70054 */  lw    $a3, 0x54($sp)
/* 0DCD98 7F0A8268 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DCD9C 7F0A826C AFA00028 */  sw    $zero, 0x28($sp)
/* 0DCDA0 7F0A8270 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DCDA4 7F0A8274 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0DCDA8 7F0A8278 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0DCDAC 7F0A827C 0FC2B6AF */  jal   en_text_write_stuff
/* 0DCDB0 7F0A8280 AFA80020 */   sw    $t0, 0x20($sp)
/* 0DCDB4 7F0A8284 8FAA007C */  lw    $t2, 0x7c($sp)
/* 0DCDB8 7F0A8288 240900AA */  li    $t1, 170
/* 0DCDBC 7F0A828C 00408025 */  move  $s0, $v0
/* 0DCDC0 7F0A8290 AFA90088 */  sw    $t1, 0x88($sp)
/* 0DCDC4 7F0A8294 27A40084 */  addiu $a0, $sp, 0x84
/* 0DCDC8 7F0A8298 27A50080 */  addiu $a1, $sp, 0x80
/* 0DCDCC 7F0A829C 8FA60050 */  lw    $a2, 0x50($sp)
/* 0DCDD0 7F0A82A0 8FA70078 */  lw    $a3, 0x78($sp)
/* 0DCDD4 7F0A82A4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DCDD8 7F0A82A8 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DCDDC 7F0A82AC AFAA0010 */   sw    $t2, 0x10($sp)
/* 0DCDE0 7F0A82B0 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0DCDE4 7F0A82B4 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0DCDE8 7F0A82B8 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0DCDEC 7F0A82BC 8FAF0084 */  lw    $t7, 0x84($sp)
/* 0DCDF0 7F0A82C0 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0DCDF4 7F0A82C4 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0DCDF8 7F0A82C8 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DCDFC 7F0A82CC 02002025 */  move  $a0, $s0
/* 0DCE00 7F0A82D0 27A5008C */  addiu $a1, $sp, 0x8c
/* 0DCE04 7F0A82D4 27A60088 */  addiu $a2, $sp, 0x88
/* 0DCE08 7F0A82D8 8FA70050 */  lw    $a3, 0x50($sp)
/* 0DCE0C 7F0A82DC AFA00024 */  sw    $zero, 0x24($sp)
/* 0DCE10 7F0A82E0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DCE14 7F0A82E4 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DCE18 7F0A82E8 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0DCE1C 7F0A82EC AFAE001C */  sw    $t6, 0x1c($sp)
/* 0DCE20 7F0A82F0 0FC2B6AF */  jal   en_text_write_stuff
/* 0DCE24 7F0A82F4 AFAF0020 */   sw    $t7, 0x20($sp)
/* 0DCE28 7F0A82F8 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DCE2C 7F0A82FC 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DCE30 7F0A8300 27BD0118 */  addiu $sp, $sp, 0x118
/* 0DCE34 7F0A8304 03E00008 */  jr    $ra
/* 0DCE38 7F0A8308 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8005850C
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058510
.word 0x3f829cbc /*1.0204082*/
glabel D_80058514
.word 0x461c4000 /*10000.0*/
glabel D_80058518
.word 0x40c90fdb /*6.2831855*/
glabel D_8005851C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058520
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058524
.word 0x3f829cbc /*1.0204082*/
glabel D_80058528
.word 0x461c4000 /*10000.0*/
glabel D_8005852C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058530
.word 0x40c90fdb /*6.2831855*/
.text
glabel draw_current_hand_item_and_ammo
/* 0D9BB0 7F0A71C0 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0D9BB4 7F0A71C4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D9BB8 7F0A71C8 AFB00038 */  sw    $s0, 0x38($sp)
/* 0D9BBC 7F0A71CC 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0D9BC0 7F0A71D0 00808025 */   move  $s0, $a0
/* 0D9BC4 7F0A71D4 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
/* 0D9BC8 7F0A71D8 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0D9BCC 7F0A71DC 8DCEAAFC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0D9BD0 7F0A71E0 8DEFAB00 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0D9BD4 7F0A71E4 AFA20114 */  sw    $v0, 0x114($sp)
/* 0D9BD8 7F0A71E8 AFA00084 */  sw    $zero, 0x84($sp)
/* 0D9BDC 7F0A71EC AFA00080 */  sw    $zero, 0x80($sp)
/* 0D9BE0 7F0A71F0 AFAE007C */  sw    $t6, 0x7c($sp)
/* 0D9BE4 7F0A71F4 0FC2378A */  jal   bondinvGetCurEquippedItem
/* 0D9BE8 7F0A71F8 AFAF0078 */   sw    $t7, 0x78($sp)
/* 0D9BEC 7F0A71FC AFA20074 */  sw    $v0, 0x74($sp)
/* 0D9BF0 7F0A7200 0FC235B6 */  jal   bondinvGetTextbyInvIndex
/* 0D9BF4 7F0A7204 00402025 */   move  $a0, $v0
/* 0D9BF8 7F0A7208 AFA20070 */  sw    $v0, 0x70($sp)
/* 0D9BFC 7F0A720C 0FC23750 */  jal   bondinvGetVposWatchForIndex
/* 0D9C00 7F0A7210 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C04 7F0A7214 E7A0006C */  swc1  $f0, 0x6c($sp)
/* 0D9C08 7F0A7218 0FC2375A */  jal   bondinvGetHposWatchForIndex
/* 0D9C0C 7F0A721C 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C10 7F0A7220 E7A00068 */  swc1  $f0, 0x68($sp)
/* 0D9C14 7F0A7224 0FC23764 */  jal   bondinvGetDepthWatchForIndex
/* 0D9C18 7F0A7228 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C1C 7F0A722C E7A00064 */  swc1  $f0, 0x64($sp)
/* 0D9C20 7F0A7230 0FC23746 */  jal   bondinvGetDifferent45AngleForIndex
/* 0D9C24 7F0A7234 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C28 7F0A7238 E7A00060 */  swc1  $f0, 0x60($sp)
/* 0D9C2C 7F0A723C 0FC2376E */  jal   bondinvGetXrotWatchForIndex
/* 0D9C30 7F0A7240 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C34 7F0A7244 E7A0005C */  swc1  $f0, 0x5c($sp)
/* 0D9C38 7F0A7248 0FC23778 */  jal   bondinvGetYrotWatchForIndex
/* 0D9C3C 7F0A724C 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C40 7F0A7250 E7A00058 */  swc1  $f0, 0x58($sp)
/* 0D9C44 7F0A7254 0FC236AC */  jal   bondinvGetFirstTitlebyIndex
/* 0D9C48 7F0A7258 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C4C 7F0A725C AFA20054 */  sw    $v0, 0x54($sp)
/* 0D9C50 7F0A7260 0FC236F9 */  jal   bondinvGetSecondTitlebyIndex
/* 0D9C54 7F0A7264 8FA40074 */   lw    $a0, 0x74($sp)
/* 0D9C58 7F0A7268 0FC2412A */  jal   get_debug_gunwatchpos_flag
/* 0D9C5C 7F0A726C AFA20050 */   sw    $v0, 0x50($sp)
/* 0D9C60 7F0A7270 5040004C */  beql  $v0, $zero, .L7F0A73A4
/* 0D9C64 7F0A7274 3C014120 */   lui   $at, 0x4120
/* 0D9C68 7F0A7278 0FC177A2 */  jal   getCurrentPlayerWeaponId
/* 0D9C6C 7F0A727C 00002025 */   move  $a0, $zero
/* 0D9C70 7F0A7280 0002C0C0 */  sll   $t8, $v0, 3
/* 0D9C74 7F0A7284 0302C023 */  subu  $t8, $t8, $v0
/* 0D9C78 7F0A7288 3C198003 */  lui   $t9, %hi(gitem_structs) # $t9, 0x8003
/* 0D9C7C 7F0A728C 2739EE74 */  addiu $t9, %lo(gitem_structs) # addiu $t9, $t9, -0x118c
/* 0D9C80 7F0A7290 0018C0C0 */  sll   $t8, $t8, 3
/* 0D9C84 7F0A7294 03191821 */  addu  $v1, $t8, $t9
/* 0D9C88 7F0A7298 AFA3004C */  sw    $v1, 0x4c($sp)
/* 0D9C8C 7F0A729C 00002025 */  move  $a0, $zero
/* 0D9C90 7F0A72A0 0C002C20 */  jal   joyGetButtons
/* 0D9C94 7F0A72A4 24050002 */   li    $a1, 2
/* 0D9C98 7F0A72A8 10400006 */  beqz  $v0, .L7F0A72C4
/* 0D9C9C 7F0A72AC 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9CA0 7F0A72B0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D9CA4 7F0A72B4 44813000 */  mtc1  $at, $f6
/* 0D9CA8 7F0A72B8 C4640018 */  lwc1  $f4, 0x18($v1)
/* 0D9CAC 7F0A72BC 46062201 */  sub.s $f8, $f4, $f6
/* 0D9CB0 7F0A72C0 E4680018 */  swc1  $f8, 0x18($v1)
.L7F0A72C4:
/* 0D9CB4 7F0A72C4 00002025 */  move  $a0, $zero
/* 0D9CB8 7F0A72C8 24050001 */  li    $a1, 1
/* 0D9CBC 7F0A72CC 0C002C20 */  jal   joyGetButtons
/* 0D9CC0 7F0A72D0 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0D9CC4 7F0A72D4 10400006 */  beqz  $v0, .L7F0A72F0
/* 0D9CC8 7F0A72D8 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9CCC 7F0A72DC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D9CD0 7F0A72E0 44818000 */  mtc1  $at, $f16
/* 0D9CD4 7F0A72E4 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0D9CD8 7F0A72E8 46105480 */  add.s $f18, $f10, $f16
/* 0D9CDC 7F0A72EC E4720018 */  swc1  $f18, 0x18($v1)
.L7F0A72F0:
/* 0D9CE0 7F0A72F0 00002025 */  move  $a0, $zero
/* 0D9CE4 7F0A72F4 24050004 */  li    $a1, 4
/* 0D9CE8 7F0A72F8 0C002C20 */  jal   joyGetButtons
/* 0D9CEC 7F0A72FC AFA3004C */   sw    $v1, 0x4c($sp)
/* 0D9CF0 7F0A7300 10400006 */  beqz  $v0, .L7F0A731C
/* 0D9CF4 7F0A7304 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9CF8 7F0A7308 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D9CFC 7F0A730C 44813000 */  mtc1  $at, $f6
/* 0D9D00 7F0A7310 C4640014 */  lwc1  $f4, 0x14($v1)
/* 0D9D04 7F0A7314 46062200 */  add.s $f8, $f4, $f6
/* 0D9D08 7F0A7318 E4680014 */  swc1  $f8, 0x14($v1)
.L7F0A731C:
/* 0D9D0C 7F0A731C 00002025 */  move  $a0, $zero
/* 0D9D10 7F0A7320 24050008 */  li    $a1, 8
/* 0D9D14 7F0A7324 0C002C20 */  jal   joyGetButtons
/* 0D9D18 7F0A7328 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0D9D1C 7F0A732C 10400006 */  beqz  $v0, .L7F0A7348
/* 0D9D20 7F0A7330 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9D24 7F0A7334 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D9D28 7F0A7338 44818000 */  mtc1  $at, $f16
/* 0D9D2C 7F0A733C C46A0014 */  lwc1  $f10, 0x14($v1)
/* 0D9D30 7F0A7340 46105481 */  sub.s $f18, $f10, $f16
/* 0D9D34 7F0A7344 E4720014 */  swc1  $f18, 0x14($v1)
.L7F0A7348:
/* 0D9D38 7F0A7348 00002025 */  move  $a0, $zero
/* 0D9D3C 7F0A734C 24050020 */  li    $a1, 32
/* 0D9D40 7F0A7350 0C002C20 */  jal   joyGetButtons
/* 0D9D44 7F0A7354 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0D9D48 7F0A7358 10400006 */  beqz  $v0, .L7F0A7374
/* 0D9D4C 7F0A735C 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9D50 7F0A7360 3C018005 */  lui   $at, %hi(D_8005850C) # $at, 0x8005
/* 0D9D54 7F0A7364 C426CF60 */  lwc1  $f6, %lo(D_8005850C)($at)
/* 0D9D58 7F0A7368 C464001C */  lwc1  $f4, 0x1c($v1)
/* 0D9D5C 7F0A736C 46062202 */  mul.s $f8, $f4, $f6
/* 0D9D60 7F0A7370 E468001C */  swc1  $f8, 0x1c($v1)
.L7F0A7374:
/* 0D9D64 7F0A7374 00002025 */  move  $a0, $zero
/* 0D9D68 7F0A7378 24050010 */  li    $a1, 16
/* 0D9D6C 7F0A737C 0C002C20 */  jal   joyGetButtons
/* 0D9D70 7F0A7380 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0D9D74 7F0A7384 10400006 */  beqz  $v0, .L7F0A73A0
/* 0D9D78 7F0A7388 8FA3004C */   lw    $v1, 0x4c($sp)
/* 0D9D7C 7F0A738C 3C018005 */  lui   $at, %hi(D_80058510) # $at, 0x8005
/* 0D9D80 7F0A7390 C430CF64 */  lwc1  $f16, %lo(D_80058510)($at)
/* 0D9D84 7F0A7394 C46A001C */  lwc1  $f10, 0x1c($v1)
/* 0D9D88 7F0A7398 46105482 */  mul.s $f18, $f10, $f16
/* 0D9D8C 7F0A739C E472001C */  swc1  $f18, 0x1c($v1)
.L7F0A73A0:
/* 0D9D90 7F0A73A0 3C014120 */  li    $at, 0x41200000 # 10.000000
.L7F0A73A4:
/* 0D9D94 7F0A73A4 44812000 */  mtc1  $at, $f4
/* 0D9D98 7F0A73A8 3C018005 */  lui   $at, %hi(D_80058514) # $at, 0x8005
/* 0D9D9C 7F0A73AC C426CF68 */  lwc1  $f6, %lo(D_80058514)($at)
/* 0D9DA0 7F0A73B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D9DA4 7F0A73B4 44814000 */  mtc1  $at, $f8
/* 0D9DA8 7F0A73B8 3C073FA4 */  lui   $a3, (0x3FA45519 >> 16) # lui $a3, 0x3fa4
/* 0D9DAC 7F0A73BC 34E75519 */  ori   $a3, (0x3FA45519 & 0xFFFF) # ori $a3, $a3, 0x5519
/* 0D9DB0 7F0A73C0 8FA40114 */  lw    $a0, 0x114($sp)
/* 0D9DB4 7F0A73C4 27A50112 */  addiu $a1, $sp, 0x112
/* 0D9DB8 7F0A73C8 8FA60060 */  lw    $a2, 0x60($sp)
/* 0D9DBC 7F0A73CC E7A40010 */  swc1  $f4, 0x10($sp)
/* 0D9DC0 7F0A73D0 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0D9DC4 7F0A73D4 0C003DB8 */  jal   guPerspective
/* 0D9DC8 7F0A73D8 E7A80018 */   swc1  $f8, 0x18($sp)
/* 0D9DCC 7F0A73DC 3C080103 */  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
/* 0D9DD0 7F0A73E0 35080040 */  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0D9DD4 7F0A73E4 02001825 */  move  $v1, $s0
/* 0D9DD8 7F0A73E8 AC680000 */  sw    $t0, ($v1)
/* 0D9DDC 7F0A73EC AFA30048 */  sw    $v1, 0x48($sp)
/* 0D9DE0 7F0A73F0 8FA40114 */  lw    $a0, 0x114($sp)
/* 0D9DE4 7F0A73F4 0C003838 */  jal   osVirtualToPhysical
/* 0D9DE8 7F0A73F8 26100008 */   addiu $s0, $s0, 8
/* 0D9DEC 7F0A73FC 8FA30048 */  lw    $v1, 0x48($sp)
/* 0D9DF0 7F0A7400 3C018005 */  lui   $at, %hi(D_80058518) # $at, 0x8005
/* 0D9DF4 7F0A7404 27A500D0 */  addiu $a1, $sp, 0xd0
/* 0D9DF8 7F0A7408 AC620004 */  sw    $v0, 4($v1)
/* 0D9DFC 7F0A740C C430CF6C */  lwc1  $f16, %lo(D_80058518)($at)
/* 0D9E00 7F0A7410 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 0D9E04 7F0A7414 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0D9E08 7F0A7418 44812000 */  mtc1  $at, $f4
/* 0D9E0C 7F0A741C 46105482 */  mul.s $f18, $f10, $f16
/* 0D9E10 7F0A7420 0FC162A9 */  jal   matrix_4x4_set_rotation_around_y
/* 0D9E14 7F0A7424 46049303 */   div.s $f12, $f18, $f4
/* 0D9E18 7F0A7428 3C018005 */  lui   $at, %hi(D_8005851C) # $at, 0x8005
/* 0D9E1C 7F0A742C C420CF70 */  lwc1  $f0, %lo(D_8005851C)($at)
/* 0D9E20 7F0A7430 C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 0D9E24 7F0A7434 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0D9E28 7F0A7438 44815000 */  mtc1  $at, $f10
/* 0D9E2C 7F0A743C 46003202 */  mul.s $f8, $f6, $f0
/* 0D9E30 7F0A7440 27A50090 */  addiu $a1, $sp, 0x90
/* 0D9E34 7F0A7444 460A4403 */  div.s $f16, $f8, $f10
/* 0D9E38 7F0A7448 0FC162CC */  jal   matrix_4x4_set_rotation_around_z
/* 0D9E3C 7F0A744C 46100301 */   sub.s $f12, $f0, $f16
/* 0D9E40 7F0A7450 27A40090 */  addiu $a0, $sp, 0x90
/* 0D9E44 7F0A7454 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0D9E48 7F0A7458 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0D9E4C 7F0A745C 44800000 */  mtc1  $zero, $f0
/* 0D9E50 7F0A7460 C7A20068 */  lwc1  $f2, 0x68($sp)
/* 0D9E54 7F0A7464 C7AC006C */  lwc1  $f12, 0x6c($sp)
/* 0D9E58 7F0A7468 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D9E5C 7F0A746C 44819000 */  mtc1  $at, $f18
/* 0D9E60 7F0A7470 44071000 */  mfc1  $a3, $f2
/* 0D9E64 7F0A7474 44066000 */  mfc1  $a2, $f12
/* 0D9E68 7F0A7478 27A40090 */  addiu $a0, $sp, 0x90
/* 0D9E6C 7F0A747C 8FA50064 */  lw    $a1, 0x64($sp)
/* 0D9E70 7F0A7480 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0D9E74 7F0A7484 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0D9E78 7F0A7488 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0D9E7C 7F0A748C E7A00024 */  swc1  $f0, 0x24($sp)
/* 0D9E80 7F0A7490 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 0D9E84 7F0A7494 0FC166CF */  jal   matrix_4x4_7F059694
/* 0D9E88 7F0A7498 E7B20020 */   swc1  $f18, 0x20($sp)
/* 0D9E8C 7F0A749C 27A40090 */  addiu $a0, $sp, 0x90
/* 0D9E90 7F0A74A0 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0D9E94 7F0A74A4 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0D9E98 7F0A74A8 0FC29880 */  jal   sub_GAME_7F0A6EE8
/* 0D9E9C 7F0A74AC 02002025 */   move  $a0, $s0
/* 0D9EA0 7F0A74B0 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen) # $v1, 0x8004
/* 0D9EA4 7F0A74B4 8C63A754 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0D9EA8 7F0A74B8 00408025 */  move  $s0, $v0
/* 0D9EAC 7F0A74BC 02002025 */  move  $a0, $s0
/* 0D9EB0 7F0A74C0 286100E0 */  slti  $at, $v1, 0xe0
/* 0D9EB4 7F0A74C4 1020000B */  beqz  $at, .L7F0A74F4
/* 0D9EB8 7F0A74C8 8FA50070 */   lw    $a1, 0x70($sp)
/* 0D9EBC 7F0A74CC 3C0964DC */  lui   $t1, (0x64DC6428 >> 16) # lui $t1, 0x64dc
/* 0D9EC0 7F0A74D0 35296428 */  ori   $t1, (0x64DC6428 & 0xFFFF) # ori $t1, $t1, 0x6428
/* 0D9EC4 7F0A74D4 AFA90010 */  sw    $t1, 0x10($sp)
/* 0D9EC8 7F0A74D8 00402025 */  move  $a0, $v0
/* 0D9ECC 7F0A74DC 8FA50070 */  lw    $a1, 0x70($sp)
/* 0D9ED0 7F0A74E0 27A600D0 */  addiu $a2, $sp, 0xd0
/* 0D9ED4 7F0A74E4 0FC18D32 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0D9ED8 7F0A74E8 24670001 */   addiu $a3, $v1, 1
/* 0D9EDC 7F0A74EC 10000008 */  b     .L7F0A7510
/* 0D9EE0 7F0A74F0 00408025 */   move  $s0, $v0
.L7F0A74F4:
/* 0D9EE4 7F0A74F4 3C0A64DC */  lui   $t2, (0x64DC6428 >> 16) # lui $t2, 0x64dc
/* 0D9EE8 7F0A74F8 354A6428 */  ori   $t2, (0x64DC6428 & 0xFFFF) # ori $t2, $t2, 0x6428
/* 0D9EEC 7F0A74FC AFAA0010 */  sw    $t2, 0x10($sp)
/* 0D9EF0 7F0A7500 27A600D0 */  addiu $a2, $sp, 0xd0
/* 0D9EF4 7F0A7504 0FC18D32 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0D9EF8 7F0A7508 240700FF */   li    $a3, 255
/* 0D9EFC 7F0A750C 00408025 */  move  $s0, $v0
.L7F0A7510:
/* 0D9F00 7F0A7510 0FC1AAB2 */  jal   sub_GAME_7F06A334
/* 0D9F04 7F0A7514 02002025 */   move  $a0, $s0
/* 0D9F08 7F0A7518 0FC2B016 */  jal   microcode_constructor
/* 0D9F0C 7F0A751C 00402025 */   move  $a0, $v0
/* 0D9F10 7F0A7520 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0D9F14 7F0A7524 240B0060 */  li    $t3, 96
/* 0D9F18 7F0A7528 240C00BC */  li    $t4, 188
/* 0D9F1C 7F0A752C 00408025 */  move  $s0, $v0
/* 0D9F20 7F0A7530 AFAB008C */  sw    $t3, 0x8c($sp)
/* 0D9F24 7F0A7534 AFAC0088 */  sw    $t4, 0x88($sp)
/* 0D9F28 7F0A7538 27A40084 */  addiu $a0, $sp, 0x84
/* 0D9F2C 7F0A753C 27A50080 */  addiu $a1, $sp, 0x80
/* 0D9F30 7F0A7540 8FA60054 */  lw    $a2, 0x54($sp)
/* 0D9F34 7F0A7544 8FA70078 */  lw    $a3, 0x78($sp)
/* 0D9F38 7F0A7548 AFA00014 */  sw    $zero, 0x14($sp)
/* 0D9F3C 7F0A754C 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0D9F40 7F0A7550 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0D9F44 7F0A7554 8FAE0078 */  lw    $t6, 0x78($sp)
/* 0D9F48 7F0A7558 8FAF007C */  lw    $t7, 0x7c($sp)
/* 0D9F4C 7F0A755C 8FB90080 */  lw    $t9, 0x80($sp)
/* 0D9F50 7F0A7560 8FA80084 */  lw    $t0, 0x84($sp)
/* 0D9F54 7F0A7564 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0D9F58 7F0A7568 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0D9F5C 7F0A756C AFB80018 */  sw    $t8, 0x18($sp)
/* 0D9F60 7F0A7570 02002025 */  move  $a0, $s0
/* 0D9F64 7F0A7574 27A5008C */  addiu $a1, $sp, 0x8c
/* 0D9F68 7F0A7578 27A60088 */  addiu $a2, $sp, 0x88
/* 0D9F6C 7F0A757C 8FA70054 */  lw    $a3, 0x54($sp)
/* 0D9F70 7F0A7580 AFA00024 */  sw    $zero, 0x24($sp)
/* 0D9F74 7F0A7584 AFA00028 */  sw    $zero, 0x28($sp)
/* 0D9F78 7F0A7588 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0D9F7C 7F0A758C AFAF0014 */  sw    $t7, 0x14($sp)
/* 0D9F80 7F0A7590 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0D9F84 7F0A7594 0FC2B35F */  jal   en_text_write_stuff
/* 0D9F88 7F0A7598 AFA80020 */   sw    $t0, 0x20($sp)
/* 0D9F8C 7F0A759C 8FAA007C */  lw    $t2, 0x7c($sp)
/* 0D9F90 7F0A75A0 240900C6 */  li    $t1, 198
/* 0D9F94 7F0A75A4 00408025 */  move  $s0, $v0
/* 0D9F98 7F0A75A8 AFA90088 */  sw    $t1, 0x88($sp)
/* 0D9F9C 7F0A75AC 27A40084 */  addiu $a0, $sp, 0x84
/* 0D9FA0 7F0A75B0 27A50080 */  addiu $a1, $sp, 0x80
/* 0D9FA4 7F0A75B4 8FA60050 */  lw    $a2, 0x50($sp)
/* 0D9FA8 7F0A75B8 8FA70078 */  lw    $a3, 0x78($sp)
/* 0D9FAC 7F0A75BC AFA00014 */  sw    $zero, 0x14($sp)
/* 0D9FB0 7F0A75C0 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0D9FB4 7F0A75C4 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0D9FB8 7F0A75C8 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0D9FBC 7F0A75CC 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0D9FC0 7F0A75D0 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0D9FC4 7F0A75D4 8FAF0084 */  lw    $t7, 0x84($sp)
/* 0D9FC8 7F0A75D8 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0D9FCC 7F0A75DC 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0D9FD0 7F0A75E0 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0D9FD4 7F0A75E4 02002025 */  move  $a0, $s0
/* 0D9FD8 7F0A75E8 27A5008C */  addiu $a1, $sp, 0x8c
/* 0D9FDC 7F0A75EC 27A60088 */  addiu $a2, $sp, 0x88
/* 0D9FE0 7F0A75F0 8FA70050 */  lw    $a3, 0x50($sp)
/* 0D9FE4 7F0A75F4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0D9FE8 7F0A75F8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0D9FEC 7F0A75FC AFAB0010 */  sw    $t3, 0x10($sp)
/* 0D9FF0 7F0A7600 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0D9FF4 7F0A7604 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0D9FF8 7F0A7608 0FC2B35F */  jal   en_text_write_stuff
/* 0D9FFC 7F0A760C AFAF0020 */   sw    $t7, 0x20($sp)
/* 0DA000 7F0A7610 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DA004 7F0A7614 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DA008 7F0A7618 27BD0118 */  addiu $sp, $sp, 0x118
/* 0DA00C 7F0A761C 03E00008 */  jr    $ra
/* 0DA010 7F0A7620 00000000 */   nop   
)
#endif
#endif


Gfx *draw_watch_mission_status_page(Gfx *gdl, Mtx *param_2)
{
    gdl = draw_background_health_and_armor(gdl, param_2, 0);

    if (check_watch_page_transistion_running() != 1)
    {
        gdl = draw_text_q_watch_v201_beta(gdl);
        gdl = draw_text_mission_status(gdl);
        gdl = draw_current_hand_item_and_ammo(empty_draw_function(gdl));
    }
    else
    {
        check_watch_page_transistion_running();
    }

    return gdl;
}


void sub_GAME_7F0A8378(void)
{
    if (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON) == 0) {
        if (joyGetButtonsPressedThisFrame(PLAYER_1, START_BUTTON) == 0)
        {
            return;
        }

        if (getCurrentPlayerWeaponId(0) == bondinvGetTextbyInvIndex(g_curWatchItemIndex))
        {
            return;
        }
    }

    currentPlayerUnEquipWeaponWrapper(0, bondinvGetTextbyInvIndex(g_curWatchItemIndex));
    currentPlayerUnEquipWeaponWrapper(1, 0);
    bondinvSetCurEquippedItem(g_curWatchItemIndex);
    D_800409C4 = 10;
    sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, 0);
}


#ifdef NONMATCHING
void draw_watch_inventory_page(void) {

}
#else
//D:80057768
const char aDDDF[] =  "%d, %d\n%d %f\n";

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel draw_watch_inventory_page
/* 0DCF54 7F0A8424 27BDF6D8 */  addiu $sp, $sp, -0x928
/* 0DCF58 7F0A8428 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DCF5C 7F0A842C AFB00038 */  sw    $s0, 0x38($sp)
/* 0DCF60 7F0A8430 0FC29C53 */  jal   draw_background_health_and_armor
/* 0DCF64 7F0A8434 00003025 */   move  $a2, $zero
/* 0DCF68 7F0A8438 0FC1F97F */  jal   check_watch_page_transistion_running
/* 0DCF6C 7F0A843C AFA20928 */   sw    $v0, 0x928($sp)
/* 0DCF70 7F0A8440 24010001 */  li    $at, 1
/* 0DCF74 7F0A8444 504101AE */  beql  $v0, $at, .L7F0A8B00
/* 0DCF78 7F0A8448 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0DCF7C 7F0A844C 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0DCF80 7F0A8450 00000000 */   nop
/* 0DCF84 7F0A8454 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCF88 7F0A8458 AFA20924 */  sw    $v0, 0x924($sp)
/* 0DCF8C 7F0A845C 0FC2354A */  jal   bondinvGet45AngleForIndex
/* 0DCF90 7F0A8460 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCF94 7F0A8464 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCF98 7F0A8468 E7A00894 */  swc1  $f0, 0x894($sp)
/* 0DCF9C 7F0A846C 0FC23554 */  jal   bondinvGetHoffsetForIndex
/* 0DCFA0 7F0A8470 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFA4 7F0A8474 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCFA8 7F0A8478 E7A00890 */  swc1  $f0, 0x890($sp)
/* 0DCFAC 7F0A847C 0FC2355E */  jal   bondinvGetVoffsetForIndex
/* 0DCFB0 7F0A8480 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFB4 7F0A8484 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCFB8 7F0A8488 E7A0088C */  swc1  $f0, 0x88c($sp)
/* 0DCFBC 7F0A848C 0FC23568 */  jal   bondinvGetDepthForIndex
/* 0DCFC0 7F0A8490 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFC4 7F0A8494 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCFC8 7F0A8498 E7A00888 */  swc1  $f0, 0x888($sp)
/* 0DCFCC 7F0A849C 0FC234AA */  jal   bondinvGetTextbyInvIndex
/* 0DCFD0 7F0A84A0 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFD4 7F0A84A4 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCFD8 7F0A84A8 AFA20884 */  sw    $v0, 0x884($sp)
/* 0DCFDC 7F0A84AC 0FC23614 */  jal   bondinvGetXrotWatchForIndex
/* 0DCFE0 7F0A84B0 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFE4 7F0A84B4 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DCFE8 7F0A84B8 E7A00880 */  swc1  $f0, 0x880($sp)
/* 0DCFEC 7F0A84BC 0FC2361E */  jal   bondinvGetYrotWatchForIndex
/* 0DCFF0 7F0A84C0 8C8409B8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DCFF4 7F0A84C4 0FC24415 */  jal   get_debug_gunwatchpos_flag
/* 0DCFF8 7F0A84C8 E7A0087C */   swc1  $f0, 0x87c($sp)
/* 0DCFFC 7F0A84CC 50400040 */  beql  $v0, $zero, .L7F0A85D0
/* 0DD000 7F0A84D0 3C014120 */   lui   $at, 0x4120
/* 0DD004 7F0A84D4 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 0DD008 7F0A84D8 00002025 */   move  $a0, $zero
/* 0DD00C 7F0A84DC 000270C0 */  sll   $t6, $v0, 3
/* 0DD010 7F0A84E0 01C27023 */  subu  $t6, $t6, $v0
/* 0DD014 7F0A84E4 3C0F8003 */  lui   $t7, %hi(gitem_structs)
/* 0DD018 7F0A84E8 25EF3924 */  addiu $t7, %lo(gitem_structs) # addiu $t7, $t7, 0x3924
/* 0DD01C 7F0A84EC 000E70C0 */  sll   $t6, $t6, 3
/* 0DD020 7F0A84F0 01CF8021 */  addu  $s0, $t6, $t7
/* 0DD024 7F0A84F4 00002025 */  move  $a0, $zero
/* 0DD028 7F0A84F8 0C0030C3 */  jal   joyGetButtons
/* 0DD02C 7F0A84FC 24050002 */   li    $a1, 2
/* 0DD030 7F0A8500 10400006 */  beqz  $v0, .L7F0A851C
/* 0DD034 7F0A8504 00002025 */   move  $a0, $zero
/* 0DD038 7F0A8508 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DD03C 7F0A850C 44813000 */  mtc1  $at, $f6
/* 0DD040 7F0A8510 C604002C */  lwc1  $f4, 0x2c($s0)
/* 0DD044 7F0A8514 46062201 */  sub.s $f8, $f4, $f6
/* 0DD048 7F0A8518 E608002C */  swc1  $f8, 0x2c($s0)
.L7F0A851C:
/* 0DD04C 7F0A851C 0C0030C3 */  jal   joyGetButtons
/* 0DD050 7F0A8520 24050001 */   li    $a1, 1
/* 0DD054 7F0A8524 10400006 */  beqz  $v0, .L7F0A8540
/* 0DD058 7F0A8528 00002025 */   move  $a0, $zero
/* 0DD05C 7F0A852C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DD060 7F0A8530 44818000 */  mtc1  $at, $f16
/* 0DD064 7F0A8534 C60A002C */  lwc1  $f10, 0x2c($s0)
/* 0DD068 7F0A8538 46105480 */  add.s $f18, $f10, $f16
/* 0DD06C 7F0A853C E612002C */  swc1  $f18, 0x2c($s0)
.L7F0A8540:
/* 0DD070 7F0A8540 0C0030C3 */  jal   joyGetButtons
/* 0DD074 7F0A8544 24050004 */   li    $a1, 4
/* 0DD078 7F0A8548 10400006 */  beqz  $v0, .L7F0A8564
/* 0DD07C 7F0A854C 00002025 */   move  $a0, $zero
/* 0DD080 7F0A8550 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DD084 7F0A8554 44813000 */  mtc1  $at, $f6
/* 0DD088 7F0A8558 C6040030 */  lwc1  $f4, 0x30($s0)
/* 0DD08C 7F0A855C 46062200 */  add.s $f8, $f4, $f6
/* 0DD090 7F0A8560 E6080030 */  swc1  $f8, 0x30($s0)
.L7F0A8564:
/* 0DD094 7F0A8564 0C0030C3 */  jal   joyGetButtons
/* 0DD098 7F0A8568 24050008 */   li    $a1, 8
/* 0DD09C 7F0A856C 10400006 */  beqz  $v0, .L7F0A8588
/* 0DD0A0 7F0A8570 00002025 */   move  $a0, $zero
/* 0DD0A4 7F0A8574 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DD0A8 7F0A8578 44818000 */  mtc1  $at, $f16
/* 0DD0AC 7F0A857C C60A0030 */  lwc1  $f10, 0x30($s0)
/* 0DD0B0 7F0A8580 46105481 */  sub.s $f18, $f10, $f16
/* 0DD0B4 7F0A8584 E6120030 */  swc1  $f18, 0x30($s0)
.L7F0A8588:
/* 0DD0B8 7F0A8588 0C0030C3 */  jal   joyGetButtons
/* 0DD0BC 7F0A858C 24050020 */   li    $a1, 32
/* 0DD0C0 7F0A8590 10400006 */  beqz  $v0, .L7F0A85AC
/* 0DD0C4 7F0A8594 00002025 */   move  $a0, $zero
/* 0DD0C8 7F0A8598 3C018006 */  lui   $at, %hi(D_80058520)
/* 0DD0CC 7F0A859C C4268520 */  lwc1  $f6, %lo(D_80058520)($at)
/* 0DD0D0 7F0A85A0 C6040034 */  lwc1  $f4, 0x34($s0)
/* 0DD0D4 7F0A85A4 46062202 */  mul.s $f8, $f4, $f6
/* 0DD0D8 7F0A85A8 E6080034 */  swc1  $f8, 0x34($s0)
.L7F0A85AC:
/* 0DD0DC 7F0A85AC 0C0030C3 */  jal   joyGetButtons
/* 0DD0E0 7F0A85B0 24050010 */   li    $a1, 16
/* 0DD0E4 7F0A85B4 10400005 */  beqz  $v0, .L7F0A85CC
/* 0DD0E8 7F0A85B8 3C018006 */   lui   $at, %hi(D_80058524)
/* 0DD0EC 7F0A85BC C60A0034 */  lwc1  $f10, 0x34($s0)
/* 0DD0F0 7F0A85C0 C4308524 */  lwc1  $f16, %lo(D_80058524)($at)
/* 0DD0F4 7F0A85C4 46105482 */  mul.s $f18, $f10, $f16
/* 0DD0F8 7F0A85C8 E6120034 */  swc1  $f18, 0x34($s0)
.L7F0A85CC:
/* 0DD0FC 7F0A85CC 3C014120 */  li    $at, 0x41200000 # 10.000000
.L7F0A85D0:
/* 0DD100 7F0A85D0 44812000 */  mtc1  $at, $f4
/* 0DD104 7F0A85D4 3C018006 */  lui   $at, %hi(D_80058528)
/* 0DD108 7F0A85D8 C4268528 */  lwc1  $f6, %lo(D_80058528)($at)
/* 0DD10C 7F0A85DC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DD110 7F0A85E0 44814000 */  mtc1  $at, $f8
/* 0DD114 7F0A85E4 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0DD118 7F0A85E8 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0DD11C 7F0A85EC 8FA40924 */  lw    $a0, 0x924($sp)
/* 0DD120 7F0A85F0 27A50922 */  addiu $a1, $sp, 0x922
/* 0DD124 7F0A85F4 8FA60894 */  lw    $a2, 0x894($sp)
/* 0DD128 7F0A85F8 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0DD12C 7F0A85FC E7A60014 */  swc1  $f6, 0x14($sp)
/* 0DD130 7F0A8600 0C003FAC */  jal   guPerspective
/* 0DD134 7F0A8604 E7A80018 */   swc1  $f8, 0x18($sp)
/* 0DD138 7F0A8608 8FA20928 */  lw    $v0, 0x928($sp)
/* 0DD13C 7F0A860C 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0DD140 7F0A8610 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0DD144 7F0A8614 00408025 */  move  $s0, $v0
/* 0DD148 7F0A8618 AE180000 */  sw    $t8, ($s0)
/* 0DD14C 7F0A861C 24420008 */  addiu $v0, $v0, 8
/* 0DD150 7F0A8620 AFA20928 */  sw    $v0, 0x928($sp)
/* 0DD154 7F0A8624 0C003A2C */  jal   osVirtualToPhysical
/* 0DD158 7F0A8628 8FA40924 */   lw    $a0, 0x924($sp)
/* 0DD15C 7F0A862C AE020004 */  sw    $v0, 4($s0)
/* 0DD160 7F0A8630 3C018006 */  lui   $at, %hi(D_8005852C)
/* 0DD164 7F0A8634 C430852C */  lwc1  $f16, %lo(D_8005852C)($at)
/* 0DD168 7F0A8638 C7AA087C */  lwc1  $f10, 0x87c($sp)
/* 0DD16C 7F0A863C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DD170 7F0A8640 44812000 */  mtc1  $at, $f4
/* 0DD174 7F0A8644 46105482 */  mul.s $f18, $f10, $f16
/* 0DD178 7F0A8648 27A508E0 */  addiu $a1, $sp, 0x8e0
/* 0DD17C 7F0A864C 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0DD180 7F0A8650 46049303 */   div.s $f12, $f18, $f4
/* 0DD184 7F0A8654 3C018006 */  lui   $at, %hi(D_80058530)
/* 0DD188 7F0A8658 C4208530 */  lwc1  $f0, %lo(D_80058530)($at)
/* 0DD18C 7F0A865C C7A60880 */  lwc1  $f6, 0x880($sp)
/* 0DD190 7F0A8660 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DD194 7F0A8664 44815000 */  mtc1  $at, $f10
/* 0DD198 7F0A8668 46003202 */  mul.s $f8, $f6, $f0
/* 0DD19C 7F0A866C 27B008A0 */  addiu $s0, $sp, 0x8a0
/* 0DD1A0 7F0A8670 02002825 */  move  $a1, $s0
/* 0DD1A4 7F0A8674 460A4403 */  div.s $f16, $f8, $f10
/* 0DD1A8 7F0A8678 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 0DD1AC 7F0A867C 46100301 */   sub.s $f12, $f0, $f16
/* 0DD1B0 7F0A8680 02002025 */  move  $a0, $s0
/* 0DD1B4 7F0A8684 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0DD1B8 7F0A8688 27A508E0 */   addiu $a1, $sp, 0x8e0
/* 0DD1BC 7F0A868C 3C018004 */  lui   $at, %hi(D_80040B14)
/* 0DD1C0 7F0A8690 0FC15FA8 */  jal   cosf
/* 0DD1C4 7F0A8694 C42C0B14 */   lwc1  $f12, %lo(D_80040B14)($at)
/* 0DD1C8 7F0A8698 C7B20888 */  lwc1  $f18, 0x888($sp)
/* 0DD1CC 7F0A869C 3C018004 */  lui   $at, %hi(D_80040B14)
/* 0DD1D0 7F0A86A0 C42C0B14 */  lwc1  $f12, %lo(D_80040B14)($at)
/* 0DD1D4 7F0A86A4 46120102 */  mul.s $f4, $f0, $f18
/* 0DD1D8 7F0A86A8 0FC15FAB */  jal   sinf
/* 0DD1DC 7F0A86AC E7A4089C */   swc1  $f4, 0x89c($sp)
/* 0DD1E0 7F0A86B0 C7A60888 */  lwc1  $f6, 0x888($sp)
/* 0DD1E4 7F0A86B4 C7AE0890 */  lwc1  $f14, 0x890($sp)
/* 0DD1E8 7F0A86B8 44801000 */  mtc1  $zero, $f2
/* 0DD1EC 7F0A86BC 46060202 */  mul.s $f8, $f0, $f6
/* 0DD1F0 7F0A86C0 C7AC088C */  lwc1  $f12, 0x88c($sp)
/* 0DD1F4 7F0A86C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DD1F8 7F0A86C8 44818000 */  mtc1  $at, $f16
/* 0DD1FC 7F0A86CC 44066000 */  mfc1  $a2, $f12
/* 0DD200 7F0A86D0 02002025 */  move  $a0, $s0
/* 0DD204 7F0A86D4 8FA5089C */  lw    $a1, 0x89c($sp)
/* 0DD208 7F0A86D8 460E4280 */  add.s $f10, $f8, $f14
/* 0DD20C 7F0A86DC E7AE0018 */  swc1  $f14, 0x18($sp)
/* 0DD210 7F0A86E0 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0DD214 7F0A86E4 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DD218 7F0A86E8 44075000 */  mfc1  $a3, $f10
/* 0DD21C 7F0A86EC E7A20024 */  swc1  $f2, 0x24($sp)
/* 0DD220 7F0A86F0 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 0DD224 7F0A86F4 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0DD228 7F0A86F8 E7B00020 */   swc1  $f16, 0x20($sp)
/* 0DD22C 7F0A86FC 02002025 */  move  $a0, $s0
/* 0DD230 7F0A8700 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0DD234 7F0A8704 27A508E0 */   addiu $a1, $sp, 0x8e0
/* 0DD238 7F0A8708 0FC29BBA */  jal   sub_GAME_7F0A6EE8
/* 0DD23C 7F0A870C 8FA40928 */   lw    $a0, 0x928($sp)
/* 0DD240 7F0A8710 3C19A0FF */  lui   $t9, (0xA0FFA03C >> 16) # lui $t9, 0xa0ff
/* 0DD244 7F0A8714 3739A03C */  ori   $t9, (0xA0FFA03C & 0xFFFF) # ori $t9, $t9, 0xa03c
/* 0DD248 7F0A8718 AFB90010 */  sw    $t9, 0x10($sp)
/* 0DD24C 7F0A871C 00402025 */  move  $a0, $v0
/* 0DD250 7F0A8720 8FA50884 */  lw    $a1, 0x884($sp)
/* 0DD254 7F0A8724 27A608E0 */  addiu $a2, $sp, 0x8e0
/* 0DD258 7F0A8728 0FC18C01 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0DD25C 7F0A872C 24070040 */   li    $a3, 64
/* 0DD260 7F0A8730 3C098004 */  lui   $t1, %hi(ptrFirstFontTableSmall)
/* 0DD264 7F0A8734 3C0A8004 */  lui   $t2, %hi(ptrSecondFontTableSmall)
/* 0DD268 7F0A8738 8D290EAC */  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
/* 0DD26C 7F0A873C 8D4A0EB0 */  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
/* 0DD270 7F0A8740 AFA20928 */  sw    $v0, 0x928($sp)
/* 0DD274 7F0A8744 AFA00860 */  sw    $zero, 0x860($sp)
/* 0DD278 7F0A8748 AFA0085C */  sw    $zero, 0x85c($sp)
/* 0DD27C 7F0A874C A3A00084 */  sb    $zero, 0x84($sp)
/* 0DD280 7F0A8750 00008025 */  move  $s0, $zero
/* 0DD284 7F0A8754 AFA90858 */  sw    $t1, 0x858($sp)
/* 0DD288 7F0A8758 0FC2340E */  jal   bondinvCountTotalItemsInInv
/* 0DD28C 7F0A875C AFAA0854 */   sw    $t2, 0x854($sp)
/* 0DD290 7F0A8760 1840000B */  blez  $v0, .L7F0A8790
/* 0DD294 7F0A8764 00000000 */   nop
.L7F0A8768:
/* 0DD298 7F0A8768 0FC234D0 */  jal   bondinvGetNameByIndex
/* 0DD29C 7F0A876C 02002025 */   move  $a0, $s0
/* 0DD2A0 7F0A8770 27A40084 */  addiu $a0, $sp, 0x84
/* 0DD2A4 7F0A8774 0C0029FF */  jal   strcat
/* 0DD2A8 7F0A8778 00402825 */   move  $a1, $v0
/* 0DD2AC 7F0A877C 0FC2340E */  jal   bondinvCountTotalItemsInInv
/* 0DD2B0 7F0A8780 26100001 */   addiu $s0, $s0, 1
/* 0DD2B4 7F0A8784 0202082A */  slt   $at, $s0, $v0
/* 0DD2B8 7F0A8788 1420FFF7 */  bnez  $at, .L7F0A8768
/* 0DD2BC 7F0A878C 00000000 */   nop
.L7F0A8790:
/* 0DD2C0 7F0A8790 3C038004 */  lui   $v1, %hi(D_800409C4)
/* 0DD2C4 7F0A8794 246309C4 */  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, 0x9c4
/* 0DD2C8 7F0A8798 8C620000 */  lw    $v0, ($v1)
/* 0DD2CC 7F0A879C 18400002 */  blez  $v0, .L7F0A87A8
/* 0DD2D0 7F0A87A0 244BFFFF */   addiu $t3, $v0, -1
/* 0DD2D4 7F0A87A4 AC6B0000 */  sw    $t3, ($v1)
.L7F0A87A8:
/* 0DD2D8 7F0A87A8 0FC296E0 */  jal   sub_GAME_7F0A5B80
/* 0DD2DC 7F0A87AC 00000000 */   nop
/* 0DD2E0 7F0A87B0 3C0E8005 */  lui   $t6, %hi(j_text_trigger)
/* 0DD2E4 7F0A87B4 8DCE84D0 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0DD2E8 7F0A87B8 240C004E */  li    $t4, 78
/* 0DD2EC 7F0A87BC 240D008C */  li    $t5, 140
/* 0DD2F0 7F0A87C0 AFAC0870 */  sw    $t4, 0x870($sp)
/* 0DD2F4 7F0A87C4 11C00003 */  beqz  $t6, .L7F0A87D4
/* 0DD2F8 7F0A87C8 AFAD086C */   sw    $t5, 0x86c($sp)
/* 0DD2FC 7F0A87CC 10000002 */  b     .L7F0A87D8
/* 0DD300 7F0A87D0 2402000E */   li    $v0, 14
.L7F0A87D4:
/* 0DD304 7F0A87D4 2402000C */  li    $v0, 12
.L7F0A87D8:
/* 0DD308 7F0A87D8 00028040 */  sll   $s0, $v0, 1
/* 0DD30C 7F0A87DC 2610008D */  addiu $s0, $s0, 0x8d
/* 0DD310 7F0A87E0 0FC2B366 */  jal   microcode_constructor
/* 0DD314 7F0A87E4 8FA40928 */   lw    $a0, 0x928($sp)
/* 0DD318 7F0A87E8 3C0F8005 */  lui   $t7, %hi(j_text_trigger)
/* 0DD31C 7F0A87EC 8DEF84D0 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0DD320 7F0A87F0 AFA20928 */  sw    $v0, 0x928($sp)
/* 0DD324 7F0A87F4 27A40860 */  addiu $a0, $sp, 0x860
/* 0DD328 7F0A87F8 11E00003 */  beqz  $t7, .L7F0A8808
/* 0DD32C 7F0A87FC 27A5085C */   addiu $a1, $sp, 0x85c
/* 0DD330 7F0A8800 10000002 */  b     .L7F0A880C
/* 0DD334 7F0A8804 2402000E */   li    $v0, 14
.L7F0A8808:
/* 0DD338 7F0A8808 2402000C */  li    $v0, 12
.L7F0A880C:
/* 0DD33C 7F0A880C 8FB80858 */  lw    $t8, 0x858($sp)
/* 0DD340 7F0A8810 27A60084 */  addiu $a2, $sp, 0x84
/* 0DD344 7F0A8814 8FA70854 */  lw    $a3, 0x854($sp)
/* 0DD348 7F0A8818 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DD34C 7F0A881C 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DD350 7F0A8820 AFB80010 */   sw    $t8, 0x10($sp)
/* 0DD354 7F0A8824 3C198005 */  lui   $t9, %hi(j_text_trigger)
/* 0DD358 7F0A8828 8F3984D0 */  lw    $t9, %lo(j_text_trigger)($t9)
/* 0DD35C 7F0A882C 8FA40928 */  lw    $a0, 0x928($sp)
/* 0DD360 7F0A8830 2405004E */  li    $a1, 78
/* 0DD364 7F0A8834 13200003 */  beqz  $t9, .L7F0A8844
/* 0DD368 7F0A8838 2406008C */   li    $a2, 140
/* 0DD36C 7F0A883C 10000002 */  b     .L7F0A8848
/* 0DD370 7F0A8840 2402000E */   li    $v0, 14
.L7F0A8844:
/* 0DD374 7F0A8844 2402000C */  li    $v0, 12
.L7F0A8848:
/* 0DD378 7F0A8848 00024880 */  sll   $t1, $v0, 2
/* 0DD37C 7F0A884C 8FA7085C */  lw    $a3, 0x85c($sp)
/* 0DD380 7F0A8850 01224821 */  addu  $t1, $t1, $v0
/* 0DD384 7F0A8854 252A008C */  addiu $t2, $t1, 0x8c
/* 0DD388 7F0A8858 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0DD38C 7F0A885C AFA00014 */  sw    $zero, 0x14($sp)
/* 0DD390 7F0A8860 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0DD394 7F0A8864 24E7004E */   addiu $a3, $a3, 0x4e
/* 0DD398 7F0A8868 3C038005 */  lui   $v1, %hi(j_text_trigger)
/* 0DD39C 7F0A886C 8C6384D0 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DD3A0 7F0A8870 00402025 */  move  $a0, $v0
/* 0DD3A4 7F0A8874 27A50870 */  addiu $a1, $sp, 0x870
/* 0DD3A8 7F0A8878 10600003 */  beqz  $v1, .L7F0A8888
/* 0DD3AC 7F0A887C 27A6086C */   addiu $a2, $sp, 0x86c
/* 0DD3B0 7F0A8880 10000002 */  b     .L7F0A888C
/* 0DD3B4 7F0A8884 2408000E */   li    $t0, 14
.L7F0A8888:
/* 0DD3B8 7F0A8888 2408000C */  li    $t0, 12
.L7F0A888C:
/* 0DD3BC 7F0A888C 10600003 */  beqz  $v1, .L7F0A889C
/* 0DD3C0 7F0A8890 27A70084 */   addiu $a3, $sp, 0x84
/* 0DD3C4 7F0A8894 10000002 */  b     .L7F0A88A0
/* 0DD3C8 7F0A8898 2402000E */   li    $v0, 14
.L7F0A889C:
/* 0DD3CC 7F0A889C 2402000C */  li    $v0, 12
.L7F0A88A0:
/* 0DD3D0 7F0A88A0 8FAE085C */  lw    $t6, 0x85c($sp)
/* 0DD3D4 7F0A88A4 3C198004 */  lui   $t9, %hi(D_800409B0)
/* 0DD3D8 7F0A88A8 8F3909B0 */  lw    $t9, %lo(D_800409B0)($t9)
/* 0DD3DC 7F0A88AC 8FAB0854 */  lw    $t3, 0x854($sp)
/* 0DD3E0 7F0A88B0 8FAC0858 */  lw    $t4, 0x858($sp)
/* 0DD3E4 7F0A88B4 3C0D00AA */  lui   $t5, (0x00AA00B0 >> 16) # lui $t5, 0xaa
/* 0DD3E8 7F0A88B8 0008C080 */  sll   $t8, $t0, 2
/* 0DD3EC 7F0A88BC 0308C021 */  addu  $t8, $t8, $t0
/* 0DD3F0 7F0A88C0 35AD00B0 */  ori   $t5, (0x00AA00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0DD3F4 7F0A88C4 25CF0001 */  addiu $t7, $t6, 1
/* 0DD3F8 7F0A88C8 AFAF001C */  sw    $t7, 0x1c($sp)
/* 0DD3FC 7F0A88CC AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DD400 7F0A88D0 AFB80020 */  sw    $t8, 0x20($sp)
/* 0DD404 7F0A88D4 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DD408 7F0A88D8 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DD40C 7F0A88DC AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DD410 7F0A88E0 0FC2B6AF */  jal   en_text_write_stuff
/* 0DD414 7F0A88E4 AFAC0014 */   sw    $t4, 0x14($sp)
/* 0DD418 7F0A88E8 3C098005 */  lui   $t1, %hi(j_text_trigger)
/* 0DD41C 7F0A88EC 8D2984D0 */  lw    $t1, %lo(j_text_trigger)($t1)
/* 0DD420 7F0A88F0 00402025 */  move  $a0, $v0
/* 0DD424 7F0A88F4 2405004B */  li    $a1, 75
/* 0DD428 7F0A88F8 11200003 */  beqz  $t1, .L7F0A8908
/* 0DD42C 7F0A88FC 02003025 */   move  $a2, $s0
/* 0DD430 7F0A8900 10000002 */  b     .L7F0A890C
/* 0DD434 7F0A8904 2402000E */   li    $v0, 14
.L7F0A8908:
/* 0DD438 7F0A8908 2402000C */  li    $v0, 12
.L7F0A890C:
/* 0DD43C 7F0A890C 8FA7085C */  lw    $a3, 0x85c($sp)
/* 0DD440 7F0A8910 00505021 */  addu  $t2, $v0, $s0
/* 0DD444 7F0A8914 3C0C0080 */  lui   $t4, (0x00800050 >> 16) # lui $t4, 0x80
/* 0DD448 7F0A8918 358C0050 */  ori   $t4, (0x00800050 & 0xFFFF) # ori $t4, $t4, 0x50
/* 0DD44C 7F0A891C 254BFFFE */  addiu $t3, $t2, -2
/* 0DD450 7F0A8920 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DD454 7F0A8924 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0DD458 7F0A8928 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0DD45C 7F0A892C 24E70052 */   addiu $a3, $a3, 0x52
/* 0DD460 7F0A8930 3C0D8004 */  lui   $t5, %hi(ptrSecondFontTableSmall)
/* 0DD464 7F0A8934 8DAD0EB0 */  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
/* 0DD468 7F0A8938 3C108004 */  lui   $s0, %hi(ptrFirstFontTableSmall)
/* 0DD46C 7F0A893C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex)
/* 0DD470 7F0A8940 AFA20928 */  sw    $v0, 0x928($sp)
/* 0DD474 7F0A8944 8E100EAC */  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
/* 0DD478 7F0A8948 8C8409B8 */  lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DD47C 7F0A894C 0FC234D0 */  jal   bondinvGetNameByIndex
/* 0DD480 7F0A8950 AFAD0058 */   sw    $t5, 0x58($sp)
/* 0DD484 7F0A8954 3C018004 */  lui   $at, %hi(D_800409BC)
/* 0DD488 7F0A8958 C43209BC */  lwc1  $f18, %lo(D_800409BC)($at)
/* 0DD48C 7F0A895C 3C0E8004 */  lui   $t6, %hi(g_curWatchItemIndex)
/* 0DD490 7F0A8960 8DCE09B8 */  lw    $t6, %lo(g_curWatchItemIndex)($t6)
/* 0DD494 7F0A8964 46009121 */  cvt.d.s $f4, $f18
/* 0DD498 7F0A8968 3C058005 */  lui   $a1, %hi(aDDDF)
/* 0DD49C 7F0A896C 3C068004 */  lui   $a2, %hi(D_800409B0)
/* 0DD4A0 7F0A8970 3C078004 */  lui   $a3, %hi(D_800409B4)
/* 0DD4A4 7F0A8974 AFA2004C */  sw    $v0, 0x4c($sp)
/* 0DD4A8 7F0A8978 8CE709B4 */  lw    $a3, %lo(D_800409B4)($a3)
/* 0DD4AC 7F0A897C 8CC609B0 */  lw    $a2, %lo(D_800409B0)($a2)
/* 0DD4B0 7F0A8980 24A57768 */  addiu $a1, %lo(aDDDF) # addiu $a1, $a1, 0x7768
/* 0DD4B4 7F0A8984 F7A40018 */  sdc1  $f4, 0x18($sp)
/* 0DD4B8 7F0A8988 27A40060 */  addiu $a0, $sp, 0x60
/* 0DD4BC 7F0A898C 0C002B25 */  jal   sprintf
/* 0DD4C0 7F0A8990 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0DD4C4 7F0A8994 0FC2B366 */  jal   microcode_constructor
/* 0DD4C8 7F0A8998 8FA40928 */   lw    $a0, 0x928($sp)
/* 0DD4CC 7F0A899C AFA20928 */  sw    $v0, 0x928($sp)
/* 0DD4D0 7F0A89A0 27A40050 */  addiu $a0, $sp, 0x50
/* 0DD4D4 7F0A89A4 27A50054 */  addiu $a1, $sp, 0x54
/* 0DD4D8 7F0A89A8 27A60060 */  addiu $a2, $sp, 0x60
/* 0DD4DC 7F0A89AC 8FA70058 */  lw    $a3, 0x58($sp)
/* 0DD4E0 7F0A89B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DD4E4 7F0A89B4 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DD4E8 7F0A89B8 AFA00014 */   sw    $zero, 0x14($sp)
/* 0DD4EC 7F0A89BC 3C0F8004 */  lui   $t7, %hi(D_800409C0)
/* 0DD4F0 7F0A89C0 8DEF09C0 */  lw    $t7, %lo(D_800409C0)($t7)
/* 0DD4F4 7F0A89C4 3C188005 */  lui   $t8, %hi(j_text_trigger)
/* 0DD4F8 7F0A89C8 27A40050 */  addiu $a0, $sp, 0x50
/* 0DD4FC 7F0A89CC 11E0004B */  beqz  $t7, .L7F0A8AFC
/* 0DD500 7F0A89D0 27A50054 */   addiu $a1, $sp, 0x54
/* 0DD504 7F0A89D4 8F1884D0 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0DD508 7F0A89D8 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DD50C 7F0A89DC 8FA70058 */  lw    $a3, 0x58($sp)
/* 0DD510 7F0A89E0 13000003 */  beqz  $t8, .L7F0A89F0
/* 0DD514 7F0A89E4 2402000C */   li    $v0, 12
/* 0DD518 7F0A89E8 10000001 */  b     .L7F0A89F0
/* 0DD51C 7F0A89EC 2402000E */   li    $v0, 14
.L7F0A89F0:
/* 0DD520 7F0A89F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DD524 7F0A89F4 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DD528 7F0A89F8 AFA20014 */   sw    $v0, 0x14($sp)
/* 0DD52C 7F0A89FC 3C038005 */  lui   $v1, %hi(j_text_trigger)
/* 0DD530 7F0A8A00 8C6384D0 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DD534 7F0A8A04 2419004E */  li    $t9, 78
/* 0DD538 7F0A8A08 AFB90870 */  sw    $t9, 0x870($sp)
/* 0DD53C 7F0A8A0C 10600003 */  beqz  $v1, .L7F0A8A1C
/* 0DD540 7F0A8A10 3C0B8004 */   lui   $t3, %hi(D_800409C4)
/* 0DD544 7F0A8A14 10000002 */  b     .L7F0A8A20
/* 0DD548 7F0A8A18 2402000E */   li    $v0, 14
.L7F0A8A1C:
/* 0DD54C 7F0A8A1C 2402000C */  li    $v0, 12
.L7F0A8A20:
/* 0DD550 7F0A8A20 8D6B09C4 */  lw    $t3, %lo(D_800409C4)($t3)
/* 0DD554 7F0A8A24 00024840 */  sll   $t1, $v0, 1
/* 0DD558 7F0A8A28 252A008C */  addiu $t2, $t1, 0x8c
/* 0DD55C 7F0A8A2C 15600018 */  bnez  $t3, .L7F0A8A90
/* 0DD560 7F0A8A30 AFAA086C */   sw    $t2, 0x86c($sp)
/* 0DD564 7F0A8A34 10600003 */  beqz  $v1, .L7F0A8A44
/* 0DD568 7F0A8A38 8FA40928 */   lw    $a0, 0x928($sp)
/* 0DD56C 7F0A8A3C 10000002 */  b     .L7F0A8A48
/* 0DD570 7F0A8A40 2402000E */   li    $v0, 14
.L7F0A8A44:
/* 0DD574 7F0A8A44 2402000C */  li    $v0, 12
.L7F0A8A48:
/* 0DD578 7F0A8A48 8FAC0058 */  lw    $t4, 0x58($sp)
/* 0DD57C 7F0A8A4C 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0DD580 7F0A8A50 3C0DA0FF */  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
/* 0DD584 7F0A8A54 35ADA0F0 */  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
/* 0DD588 7F0A8A58 240F0064 */  li    $t7, 100
/* 0DD58C 7F0A8A5C AFAF0020 */  sw    $t7, 0x20($sp)
/* 0DD590 7F0A8A60 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DD594 7F0A8A64 27A50870 */  addiu $a1, $sp, 0x870
/* 0DD598 7F0A8A68 27A6086C */  addiu $a2, $sp, 0x86c
/* 0DD59C 7F0A8A6C 8FA7004C */  lw    $a3, 0x4c($sp)
/* 0DD5A0 7F0A8A70 AFB00014 */  sw    $s0, 0x14($sp)
/* 0DD5A4 7F0A8A74 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DD5A8 7F0A8A78 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DD5AC 7F0A8A7C AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DD5B0 7F0A8A80 0FC2B6AF */  jal   en_text_write_stuff
/* 0DD5B4 7F0A8A84 AFAE001C */   sw    $t6, 0x1c($sp)
/* 0DD5B8 7F0A8A88 1000001A */  b     .L7F0A8AF4
/* 0DD5BC 7F0A8A8C AFA20928 */   sw    $v0, 0x928($sp)
.L7F0A8A90:
/* 0DD5C0 7F0A8A90 10600003 */  beqz  $v1, .L7F0A8AA0
/* 0DD5C4 7F0A8A94 8FA40928 */   lw    $a0, 0x928($sp)
/* 0DD5C8 7F0A8A98 10000002 */  b     .L7F0A8AA4
/* 0DD5CC 7F0A8A9C 2402000E */   li    $v0, 14
.L7F0A8AA0:
/* 0DD5D0 7F0A8AA0 2402000C */  li    $v0, 12
.L7F0A8AA4:
/* 0DD5D4 7F0A8AA4 8FAA0054 */  lw    $t2, 0x54($sp)
/* 0DD5D8 7F0A8AA8 8FB80058 */  lw    $t8, 0x58($sp)
/* 0DD5DC 7F0A8AAC 3C090070 */  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
/* 0DD5E0 7F0A8AB0 352900A0 */  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
/* 0DD5E4 7F0A8AB4 2419FFFF */  li    $t9, -1
/* 0DD5E8 7F0A8AB8 240C0064 */  li    $t4, 100
/* 0DD5EC 7F0A8ABC 254B0001 */  addiu $t3, $t2, 1
/* 0DD5F0 7F0A8AC0 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0DD5F4 7F0A8AC4 AFAC0024 */  sw    $t4, 0x24($sp)
/* 0DD5F8 7F0A8AC8 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DD5FC 7F0A8ACC AFA9001C */  sw    $t1, 0x1c($sp)
/* 0DD600 7F0A8AD0 27A50870 */  addiu $a1, $sp, 0x870
/* 0DD604 7F0A8AD4 27A6086C */  addiu $a2, $sp, 0x86c
/* 0DD608 7F0A8AD8 8FA7004C */  lw    $a3, 0x4c($sp)
/* 0DD60C 7F0A8ADC AFB00014 */  sw    $s0, 0x14($sp)
/* 0DD610 7F0A8AE0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DD614 7F0A8AE4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0DD618 7F0A8AE8 0FC2B9BB */  jal   jp_text_write_stuff
/* 0DD61C 7F0A8AEC AFB80010 */   sw    $t8, 0x10($sp)
/* 0DD620 7F0A8AF0 AFA20928 */  sw    $v0, 0x928($sp)
.L7F0A8AF4:
/* 0DD624 7F0A8AF4 0FC2A0DE */  jal   sub_GAME_7F0A8378
/* 0DD628 7F0A8AF8 00000000 */   nop
.L7F0A8AFC:
/* 0DD62C 7F0A8AFC 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0A8B00:
/* 0DD630 7F0A8B00 8FA20928 */  lw    $v0, 0x928($sp)
/* 0DD634 7F0A8B04 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DD638 7F0A8B08 03E00008 */  jr    $ra
/* 0DD63C 7F0A8B0C 27BD0928 */   addiu $sp, $sp, 0x928
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel draw_watch_inventory_page
/* 0DDB2C 7F0A8FBC 27BDF6D0 */  addiu $sp, $sp, -0x930
/* 0DDB30 7F0A8FC0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DDB34 7F0A8FC4 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DDB38 7F0A8FC8 0FC29F39 */  jal   draw_background_health_and_armor
/* 0DDB3C 7F0A8FCC 00003025 */   move  $a2, $zero
/* 0DDB40 7F0A8FD0 0FC1FB08 */  jal   check_watch_page_transistion_running
/* 0DDB44 7F0A8FD4 AFA20930 */   sw    $v0, 0x930($sp)
/* 0DDB48 7F0A8FD8 24010001 */  li    $at, 1
/* 0DDB4C 7F0A8FDC 504101B8 */  beql  $v0, $at, .Ljp7F0A96C0
/* 0DDB50 7F0A8FE0 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0DDB54 7F0A8FE4 0FC2F8A4 */  jal   dynAllocateMatrix
/* 0DDB58 7F0A8FE8 00000000 */   nop
/* 0DDB5C 7F0A8FEC 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDB60 7F0A8FF0 AFA2092C */  sw    $v0, 0x92c($sp)
/* 0DDB64 7F0A8FF4 0FC237E4 */  jal   bondinvGet45AngleForIndex
/* 0DDB68 7F0A8FF8 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDB6C 7F0A8FFC 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDB70 7F0A9000 E7A0089C */  swc1  $f0, 0x89c($sp)
/* 0DDB74 7F0A9004 0FC237EE */  jal   bondinvGetHoffsetForIndex
/* 0DDB78 7F0A9008 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDB7C 7F0A900C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDB80 7F0A9010 E7A00898 */  swc1  $f0, 0x898($sp)
/* 0DDB84 7F0A9014 0FC237F8 */  jal   bondinvGetVoffsetForIndex
/* 0DDB88 7F0A9018 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDB8C 7F0A901C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDB90 7F0A9020 E7A00894 */  swc1  $f0, 0x894($sp)
/* 0DDB94 7F0A9024 0FC23802 */  jal   bondinvGetDepthForIndex
/* 0DDB98 7F0A9028 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDB9C 7F0A902C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDBA0 7F0A9030 E7A00890 */  swc1  $f0, 0x890($sp)
/* 0DDBA4 7F0A9034 0FC23716 */  jal   bondinvGetTextbyInvIndex
/* 0DDBA8 7F0A9038 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDBAC 7F0A903C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDBB0 7F0A9040 AFA2088C */  sw    $v0, 0x88c($sp)
/* 0DDBB4 7F0A9044 0FC238CE */  jal   bondinvGetXrotWatchForIndex
/* 0DDBB8 7F0A9048 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDBBC 7F0A904C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DDBC0 7F0A9050 E7A00888 */  swc1  $f0, 0x888($sp)
/* 0DDBC4 7F0A9054 0FC238D8 */  jal   bondinvGetYrotWatchForIndex
/* 0DDBC8 7F0A9058 8C8409E8 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DDBCC 7F0A905C 0FC246CD */  jal   get_debug_gunwatchpos_flag
/* 0DDBD0 7F0A9060 E7A00884 */   swc1  $f0, 0x884($sp)
/* 0DDBD4 7F0A9064 50400040 */  beql  $v0, $zero, .Ljp7F0A9168
/* 0DDBD8 7F0A9068 3C014120 */   lui   $at, 0x4120
/* 0DDBDC 7F0A906C 0FC177BC */  jal   getCurrentPlayerWeaponId
/* 0DDBE0 7F0A9070 00002025 */   move  $a0, $zero
/* 0DDBE4 7F0A9074 000270C0 */  sll   $t6, $v0, 3
/* 0DDBE8 7F0A9078 01C27023 */  subu  $t6, $t6, $v0
/* 0DDBEC 7F0A907C 3C0F8003 */  lui   $t7, %hi(gitem_structs) # $t7, 0x8003
/* 0DDBF0 7F0A9080 25EF3964 */  addiu $t7, %lo(gitem_structs) # addiu $t7, $t7, 0x3964
/* 0DDBF4 7F0A9084 000E70C0 */  sll   $t6, $t6, 3
/* 0DDBF8 7F0A9088 01CF8021 */  addu  $s0, $t6, $t7
/* 0DDBFC 7F0A908C 00002025 */  move  $a0, $zero
/* 0DDC00 7F0A9090 0C0030DC */  jal   joyGetButtons
/* 0DDC04 7F0A9094 24050002 */   li    $a1, 2
/* 0DDC08 7F0A9098 10400006 */  beqz  $v0, .Ljp7F0A90B4
/* 0DDC0C 7F0A909C 00002025 */   move  $a0, $zero
/* 0DDC10 7F0A90A0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DDC14 7F0A90A4 44813000 */  mtc1  $at, $f6
/* 0DDC18 7F0A90A8 C604002C */  lwc1  $f4, 0x2c($s0)
/* 0DDC1C 7F0A90AC 46062201 */  sub.s $f8, $f4, $f6
/* 0DDC20 7F0A90B0 E608002C */  swc1  $f8, 0x2c($s0)
.Ljp7F0A90B4:
/* 0DDC24 7F0A90B4 0C0030DC */  jal   joyGetButtons
/* 0DDC28 7F0A90B8 24050001 */   li    $a1, 1
/* 0DDC2C 7F0A90BC 10400006 */  beqz  $v0, .Ljp7F0A90D8
/* 0DDC30 7F0A90C0 00002025 */   move  $a0, $zero
/* 0DDC34 7F0A90C4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DDC38 7F0A90C8 44818000 */  mtc1  $at, $f16
/* 0DDC3C 7F0A90CC C60A002C */  lwc1  $f10, 0x2c($s0)
/* 0DDC40 7F0A90D0 46105480 */  add.s $f18, $f10, $f16
/* 0DDC44 7F0A90D4 E612002C */  swc1  $f18, 0x2c($s0)
.Ljp7F0A90D8:
/* 0DDC48 7F0A90D8 0C0030DC */  jal   joyGetButtons
/* 0DDC4C 7F0A90DC 24050004 */   li    $a1, 4
/* 0DDC50 7F0A90E0 10400006 */  beqz  $v0, .Ljp7F0A90FC
/* 0DDC54 7F0A90E4 00002025 */   move  $a0, $zero
/* 0DDC58 7F0A90E8 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DDC5C 7F0A90EC 44813000 */  mtc1  $at, $f6
/* 0DDC60 7F0A90F0 C6040030 */  lwc1  $f4, 0x30($s0)
/* 0DDC64 7F0A90F4 46062200 */  add.s $f8, $f4, $f6
/* 0DDC68 7F0A90F8 E6080030 */  swc1  $f8, 0x30($s0)
.Ljp7F0A90FC:
/* 0DDC6C 7F0A90FC 0C0030DC */  jal   joyGetButtons
/* 0DDC70 7F0A9100 24050008 */   li    $a1, 8
/* 0DDC74 7F0A9104 10400006 */  beqz  $v0, .Ljp7F0A9120
/* 0DDC78 7F0A9108 00002025 */   move  $a0, $zero
/* 0DDC7C 7F0A910C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DDC80 7F0A9110 44818000 */  mtc1  $at, $f16
/* 0DDC84 7F0A9114 C60A0030 */  lwc1  $f10, 0x30($s0)
/* 0DDC88 7F0A9118 46105481 */  sub.s $f18, $f10, $f16
/* 0DDC8C 7F0A911C E6120030 */  swc1  $f18, 0x30($s0)
.Ljp7F0A9120:
/* 0DDC90 7F0A9120 0C0030DC */  jal   joyGetButtons
/* 0DDC94 7F0A9124 24050020 */   li    $a1, 32
/* 0DDC98 7F0A9128 10400006 */  beqz  $v0, .Ljp7F0A9144
/* 0DDC9C 7F0A912C 00002025 */   move  $a0, $zero
/* 0DDCA0 7F0A9130 3C018006 */  lui   $at, %hi(D_80058520) # $at, 0x8006
/* 0DDCA4 7F0A9134 C4268560 */  lwc1  $f6, %lo(D_80058520)($at)
/* 0DDCA8 7F0A9138 C6040034 */  lwc1  $f4, 0x34($s0)
/* 0DDCAC 7F0A913C 46062202 */  mul.s $f8, $f4, $f6
/* 0DDCB0 7F0A9140 E6080034 */  swc1  $f8, 0x34($s0)
.Ljp7F0A9144:
/* 0DDCB4 7F0A9144 0C0030DC */  jal   joyGetButtons
/* 0DDCB8 7F0A9148 24050010 */   li    $a1, 16
/* 0DDCBC 7F0A914C 10400005 */  beqz  $v0, .Ljp7F0A9164
/* 0DDCC0 7F0A9150 3C018006 */   lui   $at, %hi(D_80058524) # $at, 0x8006
/* 0DDCC4 7F0A9154 C60A0034 */  lwc1  $f10, 0x34($s0)
/* 0DDCC8 7F0A9158 C4308564 */  lwc1  $f16, %lo(D_80058524)($at)
/* 0DDCCC 7F0A915C 46105482 */  mul.s $f18, $f10, $f16
/* 0DDCD0 7F0A9160 E6120034 */  swc1  $f18, 0x34($s0)
.Ljp7F0A9164:
/* 0DDCD4 7F0A9164 3C014120 */  li    $at, 0x41200000 # 10.000000
.Ljp7F0A9168:
/* 0DDCD8 7F0A9168 44812000 */  mtc1  $at, $f4
/* 0DDCDC 7F0A916C 3C018006 */  lui   $at, %hi(D_80058528) # $at, 0x8006
/* 0DDCE0 7F0A9170 C4268568 */  lwc1  $f6, %lo(D_80058528)($at)
/* 0DDCE4 7F0A9174 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DDCE8 7F0A9178 44814000 */  mtc1  $at, $f8
/* 0DDCEC 7F0A917C 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0DDCF0 7F0A9180 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0DDCF4 7F0A9184 8FA4092C */  lw    $a0, 0x92c($sp)
/* 0DDCF8 7F0A9188 27A5092A */  addiu $a1, $sp, 0x92a
/* 0DDCFC 7F0A918C 8FA6089C */  lw    $a2, 0x89c($sp)
/* 0DDD00 7F0A9190 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0DDD04 7F0A9194 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0DDD08 7F0A9198 0C003FBC */  jal   guPerspective
/* 0DDD0C 7F0A919C E7A80018 */   swc1  $f8, 0x18($sp)
/* 0DDD10 7F0A91A0 8FA20930 */  lw    $v0, 0x930($sp)
/* 0DDD14 7F0A91A4 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0DDD18 7F0A91A8 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0DDD1C 7F0A91AC 00408025 */  move  $s0, $v0
/* 0DDD20 7F0A91B0 AE180000 */  sw    $t8, ($s0)
/* 0DDD24 7F0A91B4 24420008 */  addiu $v0, $v0, 8
/* 0DDD28 7F0A91B8 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DDD2C 7F0A91BC 0C003A3C */  jal   osVirtualToPhysical
/* 0DDD30 7F0A91C0 8FA4092C */   lw    $a0, 0x92c($sp)
/* 0DDD34 7F0A91C4 AE020004 */  sw    $v0, 4($s0)
/* 0DDD38 7F0A91C8 3C018006 */  lui   $at, %hi(D_8005852C) # $at, 0x8006
/* 0DDD3C 7F0A91CC C430856C */  lwc1  $f16, %lo(D_8005852C)($at)
/* 0DDD40 7F0A91D0 C7AA0884 */  lwc1  $f10, 0x884($sp)
/* 0DDD44 7F0A91D4 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DDD48 7F0A91D8 44812000 */  mtc1  $at, $f4
/* 0DDD4C 7F0A91DC 46105482 */  mul.s $f18, $f10, $f16
/* 0DDD50 7F0A91E0 27A508E8 */  addiu $a1, $sp, 0x8e8
/* 0DDD54 7F0A91E4 0FC162C7 */  jal   matrix_4x4_set_rotation_around_y
/* 0DDD58 7F0A91E8 46049303 */   div.s $f12, $f18, $f4
/* 0DDD5C 7F0A91EC 3C018006 */  lui   $at, %hi(D_80058530) # $at, 0x8006
/* 0DDD60 7F0A91F0 C4208570 */  lwc1  $f0, %lo(D_80058530)($at)
/* 0DDD64 7F0A91F4 C7A60888 */  lwc1  $f6, 0x888($sp)
/* 0DDD68 7F0A91F8 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DDD6C 7F0A91FC 44815000 */  mtc1  $at, $f10
/* 0DDD70 7F0A9200 46003202 */  mul.s $f8, $f6, $f0
/* 0DDD74 7F0A9204 27B008A8 */  addiu $s0, $sp, 0x8a8
/* 0DDD78 7F0A9208 02002825 */  move  $a1, $s0
/* 0DDD7C 7F0A920C 460A4403 */  div.s $f16, $f8, $f10
/* 0DDD80 7F0A9210 0FC162EA */  jal   matrix_4x4_set_rotation_around_z
/* 0DDD84 7F0A9214 46100301 */   sub.s $f12, $f0, $f16
/* 0DDD88 7F0A9218 02002025 */  move  $a0, $s0
/* 0DDD8C 7F0A921C 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0DDD90 7F0A9220 27A508E8 */   addiu $a1, $sp, 0x8e8
/* 0DDD94 7F0A9224 3C018004 */  lui   $at, %hi(D_80040B14) # $at, 0x8004
/* 0DDD98 7F0A9228 0FC160F0 */  jal   cosf
/* 0DDD9C 7F0A922C C42C0B44 */   lwc1  $f12, %lo(D_80040B14)($at)
/* 0DDDA0 7F0A9230 C7B20890 */  lwc1  $f18, 0x890($sp)
/* 0DDDA4 7F0A9234 3C018004 */  lui   $at, %hi(D_80040B14) # $at, 0x8004
/* 0DDDA8 7F0A9238 C42C0B44 */  lwc1  $f12, %lo(D_80040B14)($at)
/* 0DDDAC 7F0A923C 46120102 */  mul.s $f4, $f0, $f18
/* 0DDDB0 7F0A9240 0FC160F3 */  jal   sinf
/* 0DDDB4 7F0A9244 E7A408A4 */   swc1  $f4, 0x8a4($sp)
/* 0DDDB8 7F0A9248 C7A60890 */  lwc1  $f6, 0x890($sp)
/* 0DDDBC 7F0A924C C7AE0898 */  lwc1  $f14, 0x898($sp)
/* 0DDDC0 7F0A9250 44801000 */  mtc1  $zero, $f2
/* 0DDDC4 7F0A9254 46060202 */  mul.s $f8, $f0, $f6
/* 0DDDC8 7F0A9258 C7AC0894 */  lwc1  $f12, 0x894($sp)
/* 0DDDCC 7F0A925C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DDDD0 7F0A9260 44818000 */  mtc1  $at, $f16
/* 0DDDD4 7F0A9264 44066000 */  mfc1  $a2, $f12
/* 0DDDD8 7F0A9268 02002025 */  move  $a0, $s0
/* 0DDDDC 7F0A926C 8FA508A4 */  lw    $a1, 0x8a4($sp)
/* 0DDDE0 7F0A9270 460E4280 */  add.s $f10, $f8, $f14
/* 0DDDE4 7F0A9274 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 0DDDE8 7F0A9278 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0DDDEC 7F0A927C E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DDDF0 7F0A9280 44075000 */  mfc1  $a3, $f10
/* 0DDDF4 7F0A9284 E7A20024 */  swc1  $f2, 0x24($sp)
/* 0DDDF8 7F0A9288 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 0DDDFC 7F0A928C 0FC166ED */  jal   matrix_4x4_7F059694
/* 0DDE00 7F0A9290 E7B00020 */   swc1  $f16, 0x20($sp)
/* 0DDE04 7F0A9294 02002025 */  move  $a0, $s0
/* 0DDE08 7F0A9298 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0DDE0C 7F0A929C 27A508E8 */   addiu $a1, $sp, 0x8e8
/* 0DDE10 7F0A92A0 0FC29EA0 */  jal   sub_GAME_7F0A6EE8
/* 0DDE14 7F0A92A4 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DDE18 7F0A92A8 3C19A0FF */  lui   $t9, (0xA0FFA03C >> 16) # lui $t9, 0xa0ff
/* 0DDE1C 7F0A92AC 3739A03C */  ori   $t9, (0xA0FFA03C & 0xFFFF) # ori $t9, $t9, 0xa03c
/* 0DDE20 7F0A92B0 AFB90010 */  sw    $t9, 0x10($sp)
/* 0DDE24 7F0A92B4 00402025 */  move  $a0, $v0
/* 0DDE28 7F0A92B8 8FA5088C */  lw    $a1, 0x88c($sp)
/* 0DDE2C 7F0A92BC 27A608E8 */  addiu $a2, $sp, 0x8e8
/* 0DDE30 7F0A92C0 0FC18D4C */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0DDE34 7F0A92C4 24070040 */   li    $a3, 64
/* 0DDE38 7F0A92C8 3C0B8005 */  lui   $t3, %hi(j_text_trigger) # $t3, 0x8005
/* 0DDE3C 7F0A92CC 8D6B8500 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0DDE40 7F0A92D0 3C098004 */  lui   $t1, %hi(ptrFirstFontTableSmall) # $t1, 0x8004
/* 0DDE44 7F0A92D4 3C0A8004 */  lui   $t2, %hi(ptrSecondFontTableSmall) # $t2, 0x8004
/* 0DDE48 7F0A92D8 8D290EDC */  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
/* 0DDE4C 7F0A92DC 8D4A0EE0 */  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
/* 0DDE50 7F0A92E0 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DDE54 7F0A92E4 AFA00868 */  sw    $zero, 0x868($sp)
/* 0DDE58 7F0A92E8 AFA00864 */  sw    $zero, 0x864($sp)
/* 0DDE5C 7F0A92EC AFA90860 */  sw    $t1, 0x860($sp)
/* 0DDE60 7F0A92F0 11600004 */  beqz  $t3, .Ljp7F0A9304
/* 0DDE64 7F0A92F4 AFAA085C */   sw    $t2, 0x85c($sp)
/* 0DDE68 7F0A92F8 240C0082 */  li    $t4, 130
/* 0DDE6C 7F0A92FC 10000003 */  b     .Ljp7F0A930C
/* 0DDE70 7F0A9300 AFAC0084 */   sw    $t4, 0x84($sp)
.Ljp7F0A9304:
/* 0DDE74 7F0A9304 240D008C */  li    $t5, 140
/* 0DDE78 7F0A9308 AFAD0084 */  sw    $t5, 0x84($sp)
.Ljp7F0A930C:
/* 0DDE7C 7F0A930C A3A0008C */  sb    $zero, 0x8c($sp)
/* 0DDE80 7F0A9310 0FC23667 */  jal   bondinvCountTotalItemsInInv
/* 0DDE84 7F0A9314 00008025 */   move  $s0, $zero
/* 0DDE88 7F0A9318 1840000B */  blez  $v0, .Ljp7F0A9348
/* 0DDE8C 7F0A931C 00000000 */   nop
.Ljp7F0A9320:
/* 0DDE90 7F0A9320 0FC2374A */  jal   bondinvGetNameByIndex
/* 0DDE94 7F0A9324 02002025 */   move  $a0, $s0
/* 0DDE98 7F0A9328 27A4008C */  addiu $a0, $sp, 0x8c
/* 0DDE9C 7F0A932C 0C002A03 */  jal   strcat
/* 0DDEA0 7F0A9330 00402825 */   move  $a1, $v0
/* 0DDEA4 7F0A9334 0FC23667 */  jal   bondinvCountTotalItemsInInv
/* 0DDEA8 7F0A9338 26100001 */   addiu $s0, $s0, 1
/* 0DDEAC 7F0A933C 0202082A */  slt   $at, $s0, $v0
/* 0DDEB0 7F0A9340 1420FFF7 */  bnez  $at, .Ljp7F0A9320
/* 0DDEB4 7F0A9344 00000000 */   nop
.Ljp7F0A9348:
/* 0DDEB8 7F0A9348 3C038004 */  lui   $v1, %hi(D_800409C4) # $v1, 0x8004
/* 0DDEBC 7F0A934C 246309F4 */  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, 0x9f4
/* 0DDEC0 7F0A9350 8C620000 */  lw    $v0, ($v1)
/* 0DDEC4 7F0A9354 18400002 */  blez  $v0, .Ljp7F0A9360
/* 0DDEC8 7F0A9358 244EFFFF */   addiu $t6, $v0, -1
/* 0DDECC 7F0A935C AC6E0000 */  sw    $t6, ($v1)
.Ljp7F0A9360:
/* 0DDED0 7F0A9360 0FC299C8 */  jal   sub_GAME_7F0A5B80
/* 0DDED4 7F0A9364 00000000 */   nop
/* 0DDED8 7F0A9368 3C188005 */  lui   $t8, %hi(j_text_trigger) # $t8, 0x8005
/* 0DDEDC 7F0A936C 8F188500 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0DDEE0 7F0A9370 8FA30084 */  lw    $v1, 0x84($sp)
/* 0DDEE4 7F0A9374 240F004E */  li    $t7, 78
/* 0DDEE8 7F0A9378 AFAF0878 */  sw    $t7, 0x878($sp)
/* 0DDEEC 7F0A937C 13000003 */  beqz  $t8, .Ljp7F0A938C
/* 0DDEF0 7F0A9380 AFA30874 */   sw    $v1, 0x874($sp)
/* 0DDEF4 7F0A9384 10000002 */  b     .Ljp7F0A9390
/* 0DDEF8 7F0A9388 2402000E */   li    $v0, 14
.Ljp7F0A938C:
/* 0DDEFC 7F0A938C 2402000C */  li    $v0, 12
.Ljp7F0A9390:
/* 0DDF00 7F0A9390 0002C840 */  sll   $t9, $v0, 1
/* 0DDF04 7F0A9394 03238021 */  addu  $s0, $t9, $v1
/* 0DDF08 7F0A9398 26100001 */  addiu $s0, $s0, 1
/* 0DDF0C 7F0A939C 0FC2B652 */  jal   microcode_constructor
/* 0DDF10 7F0A93A0 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DDF14 7F0A93A4 3C098005 */  lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
/* 0DDF18 7F0A93A8 8D298500 */  lw    $t1, %lo(j_text_trigger)($t1)
/* 0DDF1C 7F0A93AC AFA20930 */  sw    $v0, 0x930($sp)
/* 0DDF20 7F0A93B0 27A40868 */  addiu $a0, $sp, 0x868
/* 0DDF24 7F0A93B4 11200003 */  beqz  $t1, .Ljp7F0A93C4
/* 0DDF28 7F0A93B8 27A50864 */   addiu $a1, $sp, 0x864
/* 0DDF2C 7F0A93BC 10000002 */  b     .Ljp7F0A93C8
/* 0DDF30 7F0A93C0 2402000E */   li    $v0, 14
.Ljp7F0A93C4:
/* 0DDF34 7F0A93C4 2402000C */  li    $v0, 12
.Ljp7F0A93C8:
/* 0DDF38 7F0A93C8 8FAA0860 */  lw    $t2, 0x860($sp)
/* 0DDF3C 7F0A93CC 27A6008C */  addiu $a2, $sp, 0x8c
/* 0DDF40 7F0A93D0 8FA7085C */  lw    $a3, 0x85c($sp)
/* 0DDF44 7F0A93D4 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DDF48 7F0A93D8 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0DDF4C 7F0A93DC AFAA0010 */   sw    $t2, 0x10($sp)
/* 0DDF50 7F0A93E0 3C0B8005 */  lui   $t3, %hi(j_text_trigger) # $t3, 0x8005
/* 0DDF54 7F0A93E4 8D6B8500 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0DDF58 7F0A93E8 8FA60084 */  lw    $a2, 0x84($sp)
/* 0DDF5C 7F0A93EC 8FA40930 */  lw    $a0, 0x930($sp)
/* 0DDF60 7F0A93F0 11600003 */  beqz  $t3, .Ljp7F0A9400
/* 0DDF64 7F0A93F4 2405004E */   li    $a1, 78
/* 0DDF68 7F0A93F8 10000002 */  b     .Ljp7F0A9404
/* 0DDF6C 7F0A93FC 2402000E */   li    $v0, 14
.Ljp7F0A9400:
/* 0DDF70 7F0A9400 2402000C */  li    $v0, 12
.Ljp7F0A9404:
/* 0DDF74 7F0A9404 00026080 */  sll   $t4, $v0, 2
/* 0DDF78 7F0A9408 8FA70864 */  lw    $a3, 0x864($sp)
/* 0DDF7C 7F0A940C 01826021 */  addu  $t4, $t4, $v0
/* 0DDF80 7F0A9410 01866821 */  addu  $t5, $t4, $a2
/* 0DDF84 7F0A9414 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DDF88 7F0A9418 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DDF8C 7F0A941C 0FC2B6F1 */  jal   microcode_constructor_related_to_menus
/* 0DDF90 7F0A9420 24E7004E */   addiu $a3, $a3, 0x4e
/* 0DDF94 7F0A9424 3C038005 */  lui   $v1, %hi(j_text_trigger) # $v1, 0x8005
/* 0DDF98 7F0A9428 8C638500 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DDF9C 7F0A942C 00402025 */  move  $a0, $v0
/* 0DDFA0 7F0A9430 27A50878 */  addiu $a1, $sp, 0x878
/* 0DDFA4 7F0A9434 10600003 */  beqz  $v1, .Ljp7F0A9444
/* 0DDFA8 7F0A9438 27A60874 */   addiu $a2, $sp, 0x874
/* 0DDFAC 7F0A943C 10000002 */  b     .Ljp7F0A9448
/* 0DDFB0 7F0A9440 2408000E */   li    $t0, 14
.Ljp7F0A9444:
/* 0DDFB4 7F0A9444 2408000C */  li    $t0, 12
.Ljp7F0A9448:
/* 0DDFB8 7F0A9448 10600003 */  beqz  $v1, .Ljp7F0A9458
/* 0DDFBC 7F0A944C 27A7008C */   addiu $a3, $sp, 0x8c
/* 0DDFC0 7F0A9450 10000002 */  b     .Ljp7F0A945C
/* 0DDFC4 7F0A9454 2402000E */   li    $v0, 14
.Ljp7F0A9458:
/* 0DDFC8 7F0A9458 2402000C */  li    $v0, 12
.Ljp7F0A945C:
/* 0DDFCC 7F0A945C 8FB90864 */  lw    $t9, 0x864($sp)
/* 0DDFD0 7F0A9460 3C0B8004 */  lui   $t3, %hi(D_800409B0) # $t3, 0x8004
/* 0DDFD4 7F0A9464 8D6B09E0 */  lw    $t3, %lo(D_800409B0)($t3)
/* 0DDFD8 7F0A9468 8FAE085C */  lw    $t6, 0x85c($sp)
/* 0DDFDC 7F0A946C 8FAF0860 */  lw    $t7, 0x860($sp)
/* 0DDFE0 7F0A9470 3C1800AA */  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
/* 0DDFE4 7F0A9474 00085080 */  sll   $t2, $t0, 2
/* 0DDFE8 7F0A9478 01485021 */  addu  $t2, $t2, $t0
/* 0DDFEC 7F0A947C 371800B0 */  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DDFF0 7F0A9480 27290001 */  addiu $t1, $t9, 1
/* 0DDFF4 7F0A9484 AFA9001C */  sw    $t1, 0x1c($sp)
/* 0DDFF8 7F0A9488 AFB80018 */  sw    $t8, 0x18($sp)
/* 0DDFFC 7F0A948C AFAA0020 */  sw    $t2, 0x20($sp)
/* 0DE000 7F0A9490 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DE004 7F0A9494 AFAB0024 */  sw    $t3, 0x24($sp)
/* 0DE008 7F0A9498 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DE00C 7F0A949C 0FC2B99B */  jal   en_text_write_stuff
/* 0DE010 7F0A94A0 AFAF0014 */   sw    $t7, 0x14($sp)
/* 0DE014 7F0A94A4 3C0C8005 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
/* 0DE018 7F0A94A8 8D8C8500 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0DE01C 7F0A94AC 00402025 */  move  $a0, $v0
/* 0DE020 7F0A94B0 2405004B */  li    $a1, 75
/* 0DE024 7F0A94B4 11800003 */  beqz  $t4, .Ljp7F0A94C4
/* 0DE028 7F0A94B8 02003025 */   move  $a2, $s0
/* 0DE02C 7F0A94BC 10000002 */  b     .Ljp7F0A94C8
/* 0DE030 7F0A94C0 2402000E */   li    $v0, 14
.Ljp7F0A94C4:
/* 0DE034 7F0A94C4 2402000C */  li    $v0, 12
.Ljp7F0A94C8:
/* 0DE038 7F0A94C8 8FA70864 */  lw    $a3, 0x864($sp)
/* 0DE03C 7F0A94CC 00506821 */  addu  $t5, $v0, $s0
/* 0DE040 7F0A94D0 3C0F0080 */  lui   $t7, (0x00800050 >> 16) # lui $t7, 0x80
/* 0DE044 7F0A94D4 35EF0050 */  ori   $t7, (0x00800050 & 0xFFFF) # ori $t7, $t7, 0x50
/* 0DE048 7F0A94D8 25AEFFFE */  addiu $t6, $t5, -2
/* 0DE04C 7F0A94DC AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DE050 7F0A94E0 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0DE054 7F0A94E4 0FC2B6F1 */  jal   microcode_constructor_related_to_menus
/* 0DE058 7F0A94E8 24E70052 */   addiu $a3, $a3, 0x52
/* 0DE05C 7F0A94EC 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
/* 0DE060 7F0A94F0 8F180EE0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0DE064 7F0A94F4 3C108004 */  lui   $s0, %hi(ptrFirstFontTableSmall) # $s0, 0x8004
/* 0DE068 7F0A94F8 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DE06C 7F0A94FC AFA20930 */  sw    $v0, 0x930($sp)
/* 0DE070 7F0A9500 8E100EDC */  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
/* 0DE074 7F0A9504 8C8409E8 */  lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DE078 7F0A9508 0FC2374A */  jal   bondinvGetNameByIndex
/* 0DE07C 7F0A950C AFB8005C */   sw    $t8, 0x5c($sp)
/* 0DE080 7F0A9510 3C018004 */  lui   $at, %hi(D_800409BC) # $at, 0x8004
/* 0DE084 7F0A9514 C43209EC */  lwc1  $f18, %lo(D_800409BC)($at)
/* 0DE088 7F0A9518 3C198004 */  lui   $t9, %hi(g_curWatchItemIndex) # $t9, 0x8004
/* 0DE08C 7F0A951C 8F3909E8 */  lw    $t9, %lo(g_curWatchItemIndex)($t9)
/* 0DE090 7F0A9520 46009121 */  cvt.d.s $f4, $f18
/* 0DE094 7F0A9524 3C058005 */  lui   $a1, %hi(aDDDF) # $a1, 0x8005
/* 0DE098 7F0A9528 3C068004 */  lui   $a2, %hi(D_800409B0) # $a2, 0x8004
/* 0DE09C 7F0A952C 3C078004 */  lui   $a3, %hi(D_800409B4) # $a3, 0x8004
/* 0DE0A0 7F0A9530 AFA20050 */  sw    $v0, 0x50($sp)
/* 0DE0A4 7F0A9534 8CE709E4 */  lw    $a3, %lo(D_800409B4)($a3)
/* 0DE0A8 7F0A9538 8CC609E0 */  lw    $a2, %lo(D_800409B0)($a2)
/* 0DE0AC 7F0A953C 24A577A8 */  addiu $a1, %lo(aDDDF) # addiu $a1, $a1, 0x77a8
/* 0DE0B0 7F0A9540 F7A40018 */  sdc1  $f4, 0x18($sp)
/* 0DE0B4 7F0A9544 27A40064 */  addiu $a0, $sp, 0x64
/* 0DE0B8 7F0A9548 0C002B29 */  jal   sprintf
/* 0DE0BC 7F0A954C AFB90010 */   sw    $t9, 0x10($sp)
/* 0DE0C0 7F0A9550 0FC2B652 */  jal   microcode_constructor
/* 0DE0C4 7F0A9554 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DE0C8 7F0A9558 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DE0CC 7F0A955C 27A40054 */  addiu $a0, $sp, 0x54
/* 0DE0D0 7F0A9560 27A50058 */  addiu $a1, $sp, 0x58
/* 0DE0D4 7F0A9564 27A60064 */  addiu $a2, $sp, 0x64
/* 0DE0D8 7F0A9568 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DE0DC 7F0A956C AFB00010 */  sw    $s0, 0x10($sp)
/* 0DE0E0 7F0A9570 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0DE0E4 7F0A9574 AFA00014 */   sw    $zero, 0x14($sp)
/* 0DE0E8 7F0A9578 3C098004 */  lui   $t1, %hi(D_800409C0) # $t1, 0x8004
/* 0DE0EC 7F0A957C 8D2909F0 */  lw    $t1, %lo(D_800409C0)($t1)
/* 0DE0F0 7F0A9580 3C0A8005 */  lui   $t2, %hi(j_text_trigger) # $t2, 0x8005
/* 0DE0F4 7F0A9584 27A40054 */  addiu $a0, $sp, 0x54
/* 0DE0F8 7F0A9588 1120004C */  beqz  $t1, .Ljp7F0A96BC
/* 0DE0FC 7F0A958C 27A50058 */   addiu $a1, $sp, 0x58
/* 0DE100 7F0A9590 8D4A8500 */  lw    $t2, %lo(j_text_trigger)($t2)
/* 0DE104 7F0A9594 8FA60050 */  lw    $a2, 0x50($sp)
/* 0DE108 7F0A9598 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DE10C 7F0A959C 11400003 */  beqz  $t2, .Ljp7F0A95AC
/* 0DE110 7F0A95A0 2402000C */   li    $v0, 12
/* 0DE114 7F0A95A4 10000001 */  b     .Ljp7F0A95AC
/* 0DE118 7F0A95A8 2402000E */   li    $v0, 14
.Ljp7F0A95AC:
/* 0DE11C 7F0A95AC AFB00010 */  sw    $s0, 0x10($sp)
/* 0DE120 7F0A95B0 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0DE124 7F0A95B4 AFA20014 */   sw    $v0, 0x14($sp)
/* 0DE128 7F0A95B8 3C038005 */  lui   $v1, %hi(j_text_trigger) # $v1, 0x8005
/* 0DE12C 7F0A95BC 8C638500 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DE130 7F0A95C0 240B004E */  li    $t3, 78
/* 0DE134 7F0A95C4 AFAB0878 */  sw    $t3, 0x878($sp)
/* 0DE138 7F0A95C8 10600003 */  beqz  $v1, .Ljp7F0A95D8
/* 0DE13C 7F0A95CC 8FAD0084 */   lw    $t5, 0x84($sp)
/* 0DE140 7F0A95D0 10000002 */  b     .Ljp7F0A95DC
/* 0DE144 7F0A95D4 2402000E */   li    $v0, 14
.Ljp7F0A95D8:
/* 0DE148 7F0A95D8 2402000C */  li    $v0, 12
.Ljp7F0A95DC:
/* 0DE14C 7F0A95DC 3C0F8004 */  lui   $t7, %hi(D_800409C4) # $t7, 0x8004
/* 0DE150 7F0A95E0 8DEF09F4 */  lw    $t7, %lo(D_800409C4)($t7)
/* 0DE154 7F0A95E4 00026040 */  sll   $t4, $v0, 1
/* 0DE158 7F0A95E8 018D7021 */  addu  $t6, $t4, $t5
/* 0DE15C 7F0A95EC 15E00018 */  bnez  $t7, .Ljp7F0A9650
/* 0DE160 7F0A95F0 AFAE0874 */   sw    $t6, 0x874($sp)
/* 0DE164 7F0A95F4 10600003 */  beqz  $v1, .Ljp7F0A9604
/* 0DE168 7F0A95F8 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DE16C 7F0A95FC 10000002 */  b     .Ljp7F0A9608
/* 0DE170 7F0A9600 2402000E */   li    $v0, 14
.Ljp7F0A9604:
/* 0DE174 7F0A9604 2402000C */  li    $v0, 12
.Ljp7F0A9608:
/* 0DE178 7F0A9608 8FB8005C */  lw    $t8, 0x5c($sp)
/* 0DE17C 7F0A960C 8FA90058 */  lw    $t1, 0x58($sp)
/* 0DE180 7F0A9610 3C19A0FF */  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
/* 0DE184 7F0A9614 3739A0F0 */  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
/* 0DE188 7F0A9618 240A0064 */  li    $t2, 100
/* 0DE18C 7F0A961C AFAA0020 */  sw    $t2, 0x20($sp)
/* 0DE190 7F0A9620 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DE194 7F0A9624 27A50878 */  addiu $a1, $sp, 0x878
/* 0DE198 7F0A9628 27A60874 */  addiu $a2, $sp, 0x874
/* 0DE19C 7F0A962C 8FA70050 */  lw    $a3, 0x50($sp)
/* 0DE1A0 7F0A9630 AFB00014 */  sw    $s0, 0x14($sp)
/* 0DE1A4 7F0A9634 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE1A8 7F0A9638 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DE1AC 7F0A963C AFB80010 */  sw    $t8, 0x10($sp)
/* 0DE1B0 7F0A9640 0FC2B99B */  jal   en_text_write_stuff
/* 0DE1B4 7F0A9644 AFA9001C */   sw    $t1, 0x1c($sp)
/* 0DE1B8 7F0A9648 1000001A */  b     .Ljp7F0A96B4
/* 0DE1BC 7F0A964C AFA20930 */   sw    $v0, 0x930($sp)
.Ljp7F0A9650:
/* 0DE1C0 7F0A9650 10600003 */  beqz  $v1, .Ljp7F0A9660
/* 0DE1C4 7F0A9654 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DE1C8 7F0A9658 10000002 */  b     .Ljp7F0A9664
/* 0DE1CC 7F0A965C 2402000E */   li    $v0, 14
.Ljp7F0A9660:
/* 0DE1D0 7F0A9660 2402000C */  li    $v0, 12
.Ljp7F0A9664:
/* 0DE1D4 7F0A9664 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DE1D8 7F0A9668 8FAB005C */  lw    $t3, 0x5c($sp)
/* 0DE1DC 7F0A966C 3C0D0070 */  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
/* 0DE1E0 7F0A9670 35AD00A0 */  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
/* 0DE1E4 7F0A9674 240CFFFF */  li    $t4, -1
/* 0DE1E8 7F0A9678 24180064 */  li    $t8, 100
/* 0DE1EC 7F0A967C 25CF0001 */  addiu $t7, $t6, 1
/* 0DE1F0 7F0A9680 AFAF0020 */  sw    $t7, 0x20($sp)
/* 0DE1F4 7F0A9684 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DE1F8 7F0A9688 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0DE1FC 7F0A968C AFAD001C */  sw    $t5, 0x1c($sp)
/* 0DE200 7F0A9690 27A50878 */  addiu $a1, $sp, 0x878
/* 0DE204 7F0A9694 27A60874 */  addiu $a2, $sp, 0x874
/* 0DE208 7F0A9698 8FA70050 */  lw    $a3, 0x50($sp)
/* 0DE20C 7F0A969C AFB00014 */  sw    $s0, 0x14($sp)
/* 0DE210 7F0A96A0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DE214 7F0A96A4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0DE218 7F0A96A8 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0DE21C 7F0A96AC AFAB0010 */   sw    $t3, 0x10($sp)
/* 0DE220 7F0A96B0 AFA20930 */  sw    $v0, 0x930($sp)
.Ljp7F0A96B4:
/* 0DE224 7F0A96B4 0FC2A3C4 */  jal   sub_GAME_7F0A8378
/* 0DE228 7F0A96B8 00000000 */   nop
.Ljp7F0A96BC:
/* 0DE22C 7F0A96BC 8FBF003C */  lw    $ra, 0x3c($sp)
.Ljp7F0A96C0:
/* 0DE230 7F0A96C0 8FA20930 */  lw    $v0, 0x930($sp)
/* 0DE234 7F0A96C4 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DE238 7F0A96C8 03E00008 */  jr    $ra
/* 0DE23C 7F0A96CC 27BD0930 */   addiu $sp, $sp, 0x930
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel draw_watch_inventory_page
/* 0DA12C 7F0A773C 27BDF6D0 */  addiu $sp, $sp, -0x930
/* 0DA130 7F0A7740 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DA134 7F0A7744 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DA138 7F0A7748 0FC29919 */  jal   draw_background_health_and_armor
/* 0DA13C 7F0A774C 00003025 */   move  $a2, $zero
/* 0DA140 7F0A7750 0FC1F9B4 */  jal   check_watch_page_transistion_running
/* 0DA144 7F0A7754 AFA20930 */   sw    $v0, 0x930($sp)
/* 0DA148 7F0A7758 24010001 */  li    $at, 1
/* 0DA14C 7F0A775C 504101B8 */  beql  $v0, $at, .L7F0A7E40
/* 0DA150 7F0A7760 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0DA154 7F0A7764 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0DA158 7F0A7768 00000000 */   nop   
/* 0DA15C 7F0A776C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA160 7F0A7770 AFA2092C */  sw    $v0, 0x92c($sp)
/* 0DA164 7F0A7774 0FC23684 */  jal   bondinvGet45AngleForIndex
/* 0DA168 7F0A7778 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA16C 7F0A777C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA170 7F0A7780 E7A0089C */  swc1  $f0, 0x89c($sp)
/* 0DA174 7F0A7784 0FC2368E */  jal   bondinvGetHoffsetForIndex
/* 0DA178 7F0A7788 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA17C 7F0A778C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA180 7F0A7790 E7A00898 */  swc1  $f0, 0x898($sp)
/* 0DA184 7F0A7794 0FC23698 */  jal   bondinvGetVoffsetForIndex
/* 0DA188 7F0A7798 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA18C 7F0A779C 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA190 7F0A77A0 E7A00894 */  swc1  $f0, 0x894($sp)
/* 0DA194 7F0A77A4 0FC236A2 */  jal   bondinvGetDepthForIndex
/* 0DA198 7F0A77A8 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA19C 7F0A77AC 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA1A0 7F0A77B0 E7A00890 */  swc1  $f0, 0x890($sp)
/* 0DA1A4 7F0A77B4 0FC235B6 */  jal   bondinvGetTextbyInvIndex
/* 0DA1A8 7F0A77B8 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA1AC 7F0A77BC 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA1B0 7F0A77C0 AFA2088C */  sw    $v0, 0x88c($sp)
/* 0DA1B4 7F0A77C4 0FC2376E */  jal   bondinvGetXrotWatchForIndex
/* 0DA1B8 7F0A77C8 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA1BC 7F0A77CC 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA1C0 7F0A77D0 E7A00888 */  swc1  $f0, 0x888($sp)
/* 0DA1C4 7F0A77D4 0FC23778 */  jal   bondinvGetYrotWatchForIndex
/* 0DA1C8 7F0A77D8 8C84A608 */   lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA1CC 7F0A77DC 0FC2412A */  jal   get_debug_gunwatchpos_flag
/* 0DA1D0 7F0A77E0 E7A00884 */   swc1  $f0, 0x884($sp)
/* 0DA1D4 7F0A77E4 50400040 */  beql  $v0, $zero, .Leu7F0A78E8
/* 0DA1D8 7F0A77E8 3C014120 */   lui   $at, 0x4120
/* 0DA1DC 7F0A77EC 0FC177A2 */  jal   getCurrentPlayerWeaponId
/* 0DA1E0 7F0A77F0 00002025 */   move  $a0, $zero
/* 0DA1E4 7F0A77F4 000270C0 */  sll   $t6, $v0, 3
/* 0DA1E8 7F0A77F8 01C27023 */  subu  $t6, $t6, $v0
/* 0DA1EC 7F0A77FC 3C0F8003 */  lui   $t7, %hi(gitem_structs) # $t7, 0x8003
/* 0DA1F0 7F0A7800 25EFEE74 */  addiu $t7, %lo(gitem_structs) # addiu $t7, $t7, -0x118c
/* 0DA1F4 7F0A7804 000E70C0 */  sll   $t6, $t6, 3
/* 0DA1F8 7F0A7808 01CF8021 */  addu  $s0, $t6, $t7
/* 0DA1FC 7F0A780C 00002025 */  move  $a0, $zero
/* 0DA200 7F0A7810 0C002C20 */  jal   joyGetButtons
/* 0DA204 7F0A7814 24050002 */   li    $a1, 2
/* 0DA208 7F0A7818 10400006 */  beqz  $v0, .Leu7F0A7834
/* 0DA20C 7F0A781C 00002025 */   move  $a0, $zero
/* 0DA210 7F0A7820 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DA214 7F0A7824 44813000 */  mtc1  $at, $f6
/* 0DA218 7F0A7828 C604002C */  lwc1  $f4, 0x2c($s0)
/* 0DA21C 7F0A782C 46062201 */  sub.s $f8, $f4, $f6
/* 0DA220 7F0A7830 E608002C */  swc1  $f8, 0x2c($s0)
.Leu7F0A7834:
/* 0DA224 7F0A7834 0C002C20 */  jal   joyGetButtons
/* 0DA228 7F0A7838 24050001 */   li    $a1, 1
/* 0DA22C 7F0A783C 10400006 */  beqz  $v0, .L7F0A7858
/* 0DA230 7F0A7840 00002025 */   move  $a0, $zero
/* 0DA234 7F0A7844 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DA238 7F0A7848 44818000 */  mtc1  $at, $f16
/* 0DA23C 7F0A784C C60A002C */  lwc1  $f10, 0x2c($s0)
/* 0DA240 7F0A7850 46105480 */  add.s $f18, $f10, $f16
/* 0DA244 7F0A7854 E612002C */  swc1  $f18, 0x2c($s0)
.L7F0A7858:
/* 0DA248 7F0A7858 0C002C20 */  jal   joyGetButtons
/* 0DA24C 7F0A785C 24050004 */   li    $a1, 4
/* 0DA250 7F0A7860 10400006 */  beqz  $v0, .L7F0A787C
/* 0DA254 7F0A7864 00002025 */   move  $a0, $zero
/* 0DA258 7F0A7868 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DA25C 7F0A786C 44813000 */  mtc1  $at, $f6
/* 0DA260 7F0A7870 C6040030 */  lwc1  $f4, 0x30($s0)
/* 0DA264 7F0A7874 46062200 */  add.s $f8, $f4, $f6
/* 0DA268 7F0A7878 E6080030 */  swc1  $f8, 0x30($s0)
.L7F0A787C:
/* 0DA26C 7F0A787C 0C002C20 */  jal   joyGetButtons
/* 0DA270 7F0A7880 24050008 */   li    $a1, 8
/* 0DA274 7F0A7884 10400006 */  beqz  $v0, .L7F0A78A0
/* 0DA278 7F0A7888 00002025 */   move  $a0, $zero
/* 0DA27C 7F0A788C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0DA280 7F0A7890 44818000 */  mtc1  $at, $f16
/* 0DA284 7F0A7894 C60A0030 */  lwc1  $f10, 0x30($s0)
/* 0DA288 7F0A7898 46105481 */  sub.s $f18, $f10, $f16
/* 0DA28C 7F0A789C E6120030 */  swc1  $f18, 0x30($s0)
.L7F0A78A0:
/* 0DA290 7F0A78A0 0C002C20 */  jal   joyGetButtons
/* 0DA294 7F0A78A4 24050020 */   li    $a1, 32
/* 0DA298 7F0A78A8 10400006 */  beqz  $v0, .L7F0A78C4
/* 0DA29C 7F0A78AC 00002025 */   move  $a0, $zero
/* 0DA2A0 7F0A78B0 3C018005 */  lui   $at, %hi(D_80058520) # $at, 0x8005
/* 0DA2A4 7F0A78B4 C426CF74 */  lwc1  $f6, %lo(D_80058520)($at)
/* 0DA2A8 7F0A78B8 C6040034 */  lwc1  $f4, 0x34($s0)
/* 0DA2AC 7F0A78BC 46062202 */  mul.s $f8, $f4, $f6
/* 0DA2B0 7F0A78C0 E6080034 */  swc1  $f8, 0x34($s0)
.L7F0A78C4:
/* 0DA2B4 7F0A78C4 0C002C20 */  jal   joyGetButtons
/* 0DA2B8 7F0A78C8 24050010 */   li    $a1, 16
/* 0DA2BC 7F0A78CC 10400005 */  beqz  $v0, .L7F0A78E4
/* 0DA2C0 7F0A78D0 3C018005 */   lui   $at, %hi(D_80058524) # $at, 0x8005
/* 0DA2C4 7F0A78D4 C60A0034 */  lwc1  $f10, 0x34($s0)
/* 0DA2C8 7F0A78D8 C430CF78 */  lwc1  $f16, %lo(D_80058524)($at)
/* 0DA2CC 7F0A78DC 46105482 */  mul.s $f18, $f10, $f16
/* 0DA2D0 7F0A78E0 E6120034 */  swc1  $f18, 0x34($s0)
.L7F0A78E4:
/* 0DA2D4 7F0A78E4 3C014120 */  li    $at, 0x41200000 # 10.000000
.Leu7F0A78E8:
/* 0DA2D8 7F0A78E8 44812000 */  mtc1  $at, $f4
/* 0DA2DC 7F0A78EC 3C018005 */  lui   $at, %hi(D_80058528) # $at, 0x8005
/* 0DA2E0 7F0A78F0 C426CF7C */  lwc1  $f6, %lo(D_80058528)($at)
/* 0DA2E4 7F0A78F4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA2E8 7F0A78F8 44814000 */  mtc1  $at, $f8
/* 0DA2EC 7F0A78FC 3C073FA4 */  lui   $a3, (0x3FA45519 >> 16) # lui $a3, 0x3fa4
/* 0DA2F0 7F0A7900 34E75519 */  ori   $a3, (0x3FA45519 & 0xFFFF) # ori $a3, $a3, 0x5519
/* 0DA2F4 7F0A7904 8FA4092C */  lw    $a0, 0x92c($sp)
/* 0DA2F8 7F0A7908 27A5092A */  addiu $a1, $sp, 0x92a
/* 0DA2FC 7F0A790C 8FA6089C */  lw    $a2, 0x89c($sp)
/* 0DA300 7F0A7910 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0DA304 7F0A7914 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0DA308 7F0A7918 0C003DB8 */  jal   guPerspective
/* 0DA30C 7F0A791C E7A80018 */   swc1  $f8, 0x18($sp)
/* 0DA310 7F0A7920 8FA20930 */  lw    $v0, 0x930($sp)
/* 0DA314 7F0A7924 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0DA318 7F0A7928 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0DA31C 7F0A792C 00408025 */  move  $s0, $v0
/* 0DA320 7F0A7930 AE180000 */  sw    $t8, ($s0)
/* 0DA324 7F0A7934 24420008 */  addiu $v0, $v0, 8
/* 0DA328 7F0A7938 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DA32C 7F0A793C 0C003838 */  jal   osVirtualToPhysical
/* 0DA330 7F0A7940 8FA4092C */   lw    $a0, 0x92c($sp)
/* 0DA334 7F0A7944 AE020004 */  sw    $v0, 4($s0)
/* 0DA338 7F0A7948 3C018005 */  lui   $at, %hi(D_8005852C) # $at, 0x8005
/* 0DA33C 7F0A794C C430CF80 */  lwc1  $f16, %lo(D_8005852C)($at)
/* 0DA340 7F0A7950 C7AA0884 */  lwc1  $f10, 0x884($sp)
/* 0DA344 7F0A7954 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DA348 7F0A7958 44812000 */  mtc1  $at, $f4
/* 0DA34C 7F0A795C 46105482 */  mul.s $f18, $f10, $f16
/* 0DA350 7F0A7960 27A508E8 */  addiu $a1, $sp, 0x8e8
/* 0DA354 7F0A7964 0FC162A9 */  jal   matrix_4x4_set_rotation_around_y
/* 0DA358 7F0A7968 46049303 */   div.s $f12, $f18, $f4
/* 0DA35C 7F0A796C 3C018005 */  lui   $at, %hi(D_80058530) # $at, 0x8005
/* 0DA360 7F0A7970 C420CF84 */  lwc1  $f0, %lo(D_80058530)($at)
/* 0DA364 7F0A7974 C7A60888 */  lwc1  $f6, 0x888($sp)
/* 0DA368 7F0A7978 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DA36C 7F0A797C 44815000 */  mtc1  $at, $f10
/* 0DA370 7F0A7980 46003202 */  mul.s $f8, $f6, $f0
/* 0DA374 7F0A7984 27B008A8 */  addiu $s0, $sp, 0x8a8
/* 0DA378 7F0A7988 02002825 */  move  $a1, $s0
/* 0DA37C 7F0A798C 460A4403 */  div.s $f16, $f8, $f10
/* 0DA380 7F0A7990 0FC162CC */  jal   matrix_4x4_set_rotation_around_z
/* 0DA384 7F0A7994 46100301 */   sub.s $f12, $f0, $f16
/* 0DA388 7F0A7998 02002025 */  move  $a0, $s0
/* 0DA38C 7F0A799C 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0DA390 7F0A79A0 27A508E8 */   addiu $a1, $sp, 0x8e8
/* 0DA394 7F0A79A4 3C018004 */  lui   $at, %hi(D_80040B14) # $at, 0x8004
/* 0DA398 7F0A79A8 0FC16068 */  jal   cosf
/* 0DA39C 7F0A79AC C42CA764 */   lwc1  $f12, %lo(D_80040B14)($at)
/* 0DA3A0 7F0A79B0 C7B20890 */  lwc1  $f18, 0x890($sp)
/* 0DA3A4 7F0A79B4 3C018004 */  lui   $at, %hi(D_80040B14) # $at, 0x8004
/* 0DA3A8 7F0A79B8 C42CA764 */  lwc1  $f12, %lo(D_80040B14)($at)
/* 0DA3AC 7F0A79BC 46120102 */  mul.s $f4, $f0, $f18
/* 0DA3B0 7F0A79C0 0FC1606B */  jal   sinf
/* 0DA3B4 7F0A79C4 E7A408A4 */   swc1  $f4, 0x8a4($sp)
/* 0DA3B8 7F0A79C8 C7A60890 */  lwc1  $f6, 0x890($sp)
/* 0DA3BC 7F0A79CC C7AE0898 */  lwc1  $f14, 0x898($sp)
/* 0DA3C0 7F0A79D0 44801000 */  mtc1  $zero, $f2
/* 0DA3C4 7F0A79D4 46060202 */  mul.s $f8, $f0, $f6
/* 0DA3C8 7F0A79D8 C7AC0894 */  lwc1  $f12, 0x894($sp)
/* 0DA3CC 7F0A79DC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA3D0 7F0A79E0 44818000 */  mtc1  $at, $f16
/* 0DA3D4 7F0A79E4 44066000 */  mfc1  $a2, $f12
/* 0DA3D8 7F0A79E8 02002025 */  move  $a0, $s0
/* 0DA3DC 7F0A79EC 8FA508A4 */  lw    $a1, 0x8a4($sp)
/* 0DA3E0 7F0A79F0 460E4280 */  add.s $f10, $f8, $f14
/* 0DA3E4 7F0A79F4 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 0DA3E8 7F0A79F8 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0DA3EC 7F0A79FC E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DA3F0 7F0A7A00 44075000 */  mfc1  $a3, $f10
/* 0DA3F4 7F0A7A04 E7A20024 */  swc1  $f2, 0x24($sp)
/* 0DA3F8 7F0A7A08 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 0DA3FC 7F0A7A0C 0FC166CF */  jal   matrix_4x4_7F059694
/* 0DA400 7F0A7A10 E7B00020 */   swc1  $f16, 0x20($sp)
/* 0DA404 7F0A7A14 02002025 */  move  $a0, $s0
/* 0DA408 7F0A7A18 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0DA40C 7F0A7A1C 27A508E8 */   addiu $a1, $sp, 0x8e8
/* 0DA410 7F0A7A20 0FC29880 */  jal   sub_GAME_7F0A6EE8
/* 0DA414 7F0A7A24 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DA418 7F0A7A28 3C19A0FF */  lui   $t9, (0xA0FFA03C >> 16) # lui $t9, 0xa0ff
/* 0DA41C 7F0A7A2C 3739A03C */  ori   $t9, (0xA0FFA03C & 0xFFFF) # ori $t9, $t9, 0xa03c
/* 0DA420 7F0A7A30 AFB90010 */  sw    $t9, 0x10($sp)
/* 0DA424 7F0A7A34 00402025 */  move  $a0, $v0
/* 0DA428 7F0A7A38 8FA5088C */  lw    $a1, 0x88c($sp)
/* 0DA42C 7F0A7A3C 27A608E8 */  addiu $a2, $sp, 0x8e8
/* 0DA430 7F0A7A40 0FC18D32 */  jal   set_enviro_fog_for_items_in_solo_watch_menu
/* 0DA434 7F0A7A44 24070040 */   li    $a3, 64
/* 0DA438 7F0A7A48 3C0B8004 */  lui   $t3, %hi(j_text_trigger) # $t3, 0x8004
/* 0DA43C 7F0A7A4C 8D6B1150 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0DA440 7F0A7A50 3C098004 */  lui   $t1, %hi(ptrFirstFontTableSmall) # $t1, 0x8004
/* 0DA444 7F0A7A54 3C0A8004 */  lui   $t2, %hi(ptrSecondFontTableSmall) # $t2, 0x8004
/* 0DA448 7F0A7A58 8D29AAFC */  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
/* 0DA44C 7F0A7A5C 8D4AAB00 */  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
/* 0DA450 7F0A7A60 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DA454 7F0A7A64 AFA00868 */  sw    $zero, 0x868($sp)
/* 0DA458 7F0A7A68 AFA00864 */  sw    $zero, 0x864($sp)
/* 0DA45C 7F0A7A6C AFA90860 */  sw    $t1, 0x860($sp)
/* 0DA460 7F0A7A70 11600004 */  beqz  $t3, .L7F0A7A84
/* 0DA464 7F0A7A74 AFAA085C */   sw    $t2, 0x85c($sp)
/* 0DA468 7F0A7A78 240C0082 */  li    $t4, 130
/* 0DA46C 7F0A7A7C 10000003 */  b     .L7F0A7A8C
/* 0DA470 7F0A7A80 AFAC0084 */   sw    $t4, 0x84($sp)
.L7F0A7A84:
/* 0DA474 7F0A7A84 240D00AA */  li    $t5, 170
/* 0DA478 7F0A7A88 AFAD0084 */  sw    $t5, 0x84($sp)
.L7F0A7A8C:
/* 0DA47C 7F0A7A8C A3A0008C */  sb    $zero, 0x8c($sp)
/* 0DA480 7F0A7A90 0FC23507 */  jal   bondinvCountTotalItemsInInv
/* 0DA484 7F0A7A94 00008025 */   move  $s0, $zero
/* 0DA488 7F0A7A98 1840000B */  blez  $v0, .L7F0A7AC8
/* 0DA48C 7F0A7A9C 00000000 */   nop   
.L7F0A7AA0:
/* 0DA490 7F0A7AA0 0FC235EA */  jal   bondinvGetNameByIndex
/* 0DA494 7F0A7AA4 02002025 */   move  $a0, $s0
/* 0DA498 7F0A7AA8 27A4008C */  addiu $a0, $sp, 0x8c
/* 0DA49C 7F0A7AAC 0C002717 */  jal   strcat
/* 0DA4A0 7F0A7AB0 00402825 */   move  $a1, $v0
/* 0DA4A4 7F0A7AB4 0FC23507 */  jal   bondinvCountTotalItemsInInv
/* 0DA4A8 7F0A7AB8 26100001 */   addiu $s0, $s0, 1
/* 0DA4AC 7F0A7ABC 0202082A */  slt   $at, $s0, $v0
/* 0DA4B0 7F0A7AC0 1420FFF7 */  bnez  $at, .L7F0A7AA0
/* 0DA4B4 7F0A7AC4 00000000 */   nop   
.L7F0A7AC8:
/* 0DA4B8 7F0A7AC8 3C038004 */  lui   $v1, %hi(D_800409C4) # $v1, 0x8004
/* 0DA4BC 7F0A7ACC 2463A614 */  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, -0x59ec
/* 0DA4C0 7F0A7AD0 8C620000 */  lw    $v0, ($v1)
/* 0DA4C4 7F0A7AD4 18400002 */  blez  $v0, .L7F0A7AE0
/* 0DA4C8 7F0A7AD8 244EFFFF */   addiu $t6, $v0, -1
/* 0DA4CC 7F0A7ADC AC6E0000 */  sw    $t6, ($v1)
.L7F0A7AE0:
/* 0DA4D0 7F0A7AE0 0FC293A8 */  jal   sub_GAME_7F0A5B80
/* 0DA4D4 7F0A7AE4 00000000 */   nop   
/* 0DA4D8 7F0A7AE8 3C188004 */  lui   $t8, %hi(j_text_trigger) # $t8, 0x8004
/* 0DA4DC 7F0A7AEC 8F181150 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0DA4E0 7F0A7AF0 8FA30084 */  lw    $v1, 0x84($sp)
/* 0DA4E4 7F0A7AF4 240F004E */  li    $t7, 78
/* 0DA4E8 7F0A7AF8 AFAF0878 */  sw    $t7, 0x878($sp)
/* 0DA4EC 7F0A7AFC 13000003 */  beqz  $t8, .L7F0A7B0C
/* 0DA4F0 7F0A7B00 AFA30874 */   sw    $v1, 0x874($sp)
/* 0DA4F4 7F0A7B04 10000002 */  b     .L7F0A7B10
/* 0DA4F8 7F0A7B08 2402000E */   li    $v0, 14
.L7F0A7B0C:
/* 0DA4FC 7F0A7B0C 2402000C */  li    $v0, 12
.L7F0A7B10:
/* 0DA500 7F0A7B10 0002C840 */  sll   $t9, $v0, 1
/* 0DA504 7F0A7B14 03238021 */  addu  $s0, $t9, $v1
/* 0DA508 7F0A7B18 26100001 */  addiu $s0, $s0, 1
/* 0DA50C 7F0A7B1C 0FC2B016 */  jal   microcode_constructor
/* 0DA510 7F0A7B20 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DA514 7F0A7B24 3C098004 */  lui   $t1, %hi(j_text_trigger) # $t1, 0x8004
/* 0DA518 7F0A7B28 8D291150 */  lw    $t1, %lo(j_text_trigger)($t1)
/* 0DA51C 7F0A7B2C AFA20930 */  sw    $v0, 0x930($sp)
/* 0DA520 7F0A7B30 27A40868 */  addiu $a0, $sp, 0x868
/* 0DA524 7F0A7B34 11200003 */  beqz  $t1, .L7F0A7B44
/* 0DA528 7F0A7B38 27A50864 */   addiu $a1, $sp, 0x864
/* 0DA52C 7F0A7B3C 10000002 */  b     .L7F0A7B48
/* 0DA530 7F0A7B40 2402000E */   li    $v0, 14
.L7F0A7B44:
/* 0DA534 7F0A7B44 2402000C */  li    $v0, 12
.L7F0A7B48:
/* 0DA538 7F0A7B48 8FAA0860 */  lw    $t2, 0x860($sp)
/* 0DA53C 7F0A7B4C 27A6008C */  addiu $a2, $sp, 0x8c
/* 0DA540 7F0A7B50 8FA7085C */  lw    $a3, 0x85c($sp)
/* 0DA544 7F0A7B54 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DA548 7F0A7B58 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DA54C 7F0A7B5C AFAA0010 */   sw    $t2, 0x10($sp)
/* 0DA550 7F0A7B60 3C0B8004 */  lui   $t3, %hi(j_text_trigger) # $t3, 0x8004
/* 0DA554 7F0A7B64 8D6B1150 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0DA558 7F0A7B68 8FA60084 */  lw    $a2, 0x84($sp)
/* 0DA55C 7F0A7B6C 8FA40930 */  lw    $a0, 0x930($sp)
/* 0DA560 7F0A7B70 11600003 */  beqz  $t3, .L7F0A7B80
/* 0DA564 7F0A7B74 2405004E */   li    $a1, 78
/* 0DA568 7F0A7B78 10000002 */  b     .L7F0A7B84
/* 0DA56C 7F0A7B7C 2402000E */   li    $v0, 14
.L7F0A7B80:
/* 0DA570 7F0A7B80 2402000C */  li    $v0, 12
.L7F0A7B84:
/* 0DA574 7F0A7B84 00026080 */  sll   $t4, $v0, 2
/* 0DA578 7F0A7B88 8FA70864 */  lw    $a3, 0x864($sp)
/* 0DA57C 7F0A7B8C 01826021 */  addu  $t4, $t4, $v0
/* 0DA580 7F0A7B90 01866821 */  addu  $t5, $t4, $a2
/* 0DA584 7F0A7B94 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DA588 7F0A7B98 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DA58C 7F0A7B9C 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 0DA590 7F0A7BA0 24E7004E */   addiu $a3, $a3, 0x4e
/* 0DA594 7F0A7BA4 3C038004 */  lui   $v1, %hi(j_text_trigger) # $v1, 0x8004
/* 0DA598 7F0A7BA8 8C631150 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DA59C 7F0A7BAC 00402025 */  move  $a0, $v0
/* 0DA5A0 7F0A7BB0 27A50878 */  addiu $a1, $sp, 0x878
/* 0DA5A4 7F0A7BB4 10600003 */  beqz  $v1, .L7F0A7BC4
/* 0DA5A8 7F0A7BB8 27A60874 */   addiu $a2, $sp, 0x874
/* 0DA5AC 7F0A7BBC 10000002 */  b     .L7F0A7BC8
/* 0DA5B0 7F0A7BC0 2408000E */   li    $t0, 14
.L7F0A7BC4:
/* 0DA5B4 7F0A7BC4 2408000C */  li    $t0, 12
.L7F0A7BC8:
/* 0DA5B8 7F0A7BC8 10600003 */  beqz  $v1, .L7F0A7BD8
/* 0DA5BC 7F0A7BCC 27A7008C */   addiu $a3, $sp, 0x8c
/* 0DA5C0 7F0A7BD0 10000002 */  b     .L7F0A7BDC
/* 0DA5C4 7F0A7BD4 2402000E */   li    $v0, 14
.L7F0A7BD8:
/* 0DA5C8 7F0A7BD8 2402000C */  li    $v0, 12
.L7F0A7BDC:
/* 0DA5CC 7F0A7BDC 8FB90864 */  lw    $t9, 0x864($sp)
/* 0DA5D0 7F0A7BE0 3C0B8004 */  lui   $t3, %hi(D_800409B0) # $t3, 0x8004
/* 0DA5D4 7F0A7BE4 8D6BA600 */  lw    $t3, %lo(D_800409B0)($t3)
/* 0DA5D8 7F0A7BE8 8FAE085C */  lw    $t6, 0x85c($sp)
/* 0DA5DC 7F0A7BEC 8FAF0860 */  lw    $t7, 0x860($sp)
/* 0DA5E0 7F0A7BF0 3C1800AA */  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
/* 0DA5E4 7F0A7BF4 00085080 */  sll   $t2, $t0, 2
/* 0DA5E8 7F0A7BF8 01485021 */  addu  $t2, $t2, $t0
/* 0DA5EC 7F0A7BFC 371800B0 */  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DA5F0 7F0A7C00 27290001 */  addiu $t1, $t9, 1
/* 0DA5F4 7F0A7C04 AFA9001C */  sw    $t1, 0x1c($sp)
/* 0DA5F8 7F0A7C08 AFB80018 */  sw    $t8, 0x18($sp)
/* 0DA5FC 7F0A7C0C AFAA0020 */  sw    $t2, 0x20($sp)
/* 0DA600 7F0A7C10 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DA604 7F0A7C14 AFAB0024 */  sw    $t3, 0x24($sp)
/* 0DA608 7F0A7C18 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DA60C 7F0A7C1C 0FC2B35F */  jal   en_text_write_stuff
/* 0DA610 7F0A7C20 AFAF0014 */   sw    $t7, 0x14($sp)
/* 0DA614 7F0A7C24 3C0C8004 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8004
/* 0DA618 7F0A7C28 8D8C1150 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0DA61C 7F0A7C2C 00402025 */  move  $a0, $v0
/* 0DA620 7F0A7C30 2405004B */  li    $a1, 75
/* 0DA624 7F0A7C34 11800003 */  beqz  $t4, .L7F0A7C44
/* 0DA628 7F0A7C38 02003025 */   move  $a2, $s0
/* 0DA62C 7F0A7C3C 10000002 */  b     .L7F0A7C48
/* 0DA630 7F0A7C40 2402000E */   li    $v0, 14
.L7F0A7C44:
/* 0DA634 7F0A7C44 2402000C */  li    $v0, 12
.L7F0A7C48:
/* 0DA638 7F0A7C48 8FA70864 */  lw    $a3, 0x864($sp)
/* 0DA63C 7F0A7C4C 00506821 */  addu  $t5, $v0, $s0
/* 0DA640 7F0A7C50 3C0F0080 */  lui   $t7, (0x00800050 >> 16) # lui $t7, 0x80
/* 0DA644 7F0A7C54 35EF0050 */  ori   $t7, (0x00800050 & 0xFFFF) # ori $t7, $t7, 0x50
/* 0DA648 7F0A7C58 25AEFFFE */  addiu $t6, $t5, -2
/* 0DA64C 7F0A7C5C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DA650 7F0A7C60 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0DA654 7F0A7C64 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 0DA658 7F0A7C68 24E70052 */   addiu $a3, $a3, 0x52
/* 0DA65C 7F0A7C6C 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
/* 0DA660 7F0A7C70 8F18AB00 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0DA664 7F0A7C74 3C108004 */  lui   $s0, %hi(ptrFirstFontTableSmall) # $s0, 0x8004
/* 0DA668 7F0A7C78 3C048004 */  lui   $a0, %hi(g_curWatchItemIndex) # $a0, 0x8004
/* 0DA66C 7F0A7C7C AFA20930 */  sw    $v0, 0x930($sp)
/* 0DA670 7F0A7C80 8E10AAFC */  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
/* 0DA674 7F0A7C84 8C84A608 */  lw    $a0, %lo(g_curWatchItemIndex)($a0)
/* 0DA678 7F0A7C88 0FC235EA */  jal   bondinvGetNameByIndex
/* 0DA67C 7F0A7C8C AFB8005C */   sw    $t8, 0x5c($sp)
/* 0DA680 7F0A7C90 3C018004 */  lui   $at, %hi(D_800409BC) # $at, 0x8004
/* 0DA684 7F0A7C94 C432A60C */  lwc1  $f18, %lo(D_800409BC)($at)
/* 0DA688 7F0A7C98 3C198004 */  lui   $t9, %hi(g_curWatchItemIndex) # $t9, 0x8004
/* 0DA68C 7F0A7C9C 8F39A608 */  lw    $t9, %lo(g_curWatchItemIndex)($t9)
/* 0DA690 7F0A7CA0 46009121 */  cvt.d.s $f4, $f18
/* 0DA694 7F0A7CA4 3C058005 */  lui   $a1, %hi(aDDDF) # $a1, 0x8005
/* 0DA698 7F0A7CA8 3C068004 */  lui   $a2, %hi(D_800409B0) # $a2, 0x8004
/* 0DA69C 7F0A7CAC 3C078004 */  lui   $a3, %hi(D_800409B4) # $a3, 0x8004
/* 0DA6A0 7F0A7CB0 AFA20050 */  sw    $v0, 0x50($sp)
/* 0DA6A4 7F0A7CB4 8CE7A604 */  lw    $a3, %lo(D_800409B4)($a3)
/* 0DA6A8 7F0A7CB8 8CC6A600 */  lw    $a2, %lo(D_800409B0)($a2)
/* 0DA6AC 7F0A7CBC 24A5CE38 */  addiu $a1, %lo(aDDDF) # addiu $a1, $a1, -0x31c8
/* 0DA6B0 7F0A7CC0 F7A40018 */  sdc1  $f4, 0x18($sp)
/* 0DA6B4 7F0A7CC4 27A40064 */  addiu $a0, $sp, 0x64
/* 0DA6B8 7F0A7CC8 0C00283D */  jal   sprintf
/* 0DA6BC 7F0A7CCC AFB90010 */   sw    $t9, 0x10($sp)
/* 0DA6C0 7F0A7CD0 0FC2B016 */  jal   microcode_constructor
/* 0DA6C4 7F0A7CD4 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DA6C8 7F0A7CD8 AFA20930 */  sw    $v0, 0x930($sp)
/* 0DA6CC 7F0A7CDC 27A40054 */  addiu $a0, $sp, 0x54
/* 0DA6D0 7F0A7CE0 27A50058 */  addiu $a1, $sp, 0x58
/* 0DA6D4 7F0A7CE4 27A60064 */  addiu $a2, $sp, 0x64
/* 0DA6D8 7F0A7CE8 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DA6DC 7F0A7CEC AFB00010 */  sw    $s0, 0x10($sp)
/* 0DA6E0 7F0A7CF0 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DA6E4 7F0A7CF4 AFA00014 */   sw    $zero, 0x14($sp)
/* 0DA6E8 7F0A7CF8 3C098004 */  lui   $t1, %hi(D_800409C0) # $t1, 0x8004
/* 0DA6EC 7F0A7CFC 8D29A610 */  lw    $t1, %lo(D_800409C0)($t1)
/* 0DA6F0 7F0A7D00 3C0A8004 */  lui   $t2, %hi(j_text_trigger) # $t2, 0x8004
/* 0DA6F4 7F0A7D04 27A40054 */  addiu $a0, $sp, 0x54
/* 0DA6F8 7F0A7D08 1120004C */  beqz  $t1, .L7F0A7E3C
/* 0DA6FC 7F0A7D0C 27A50058 */   addiu $a1, $sp, 0x58
/* 0DA700 7F0A7D10 8D4A1150 */  lw    $t2, %lo(j_text_trigger)($t2)
/* 0DA704 7F0A7D14 8FA60050 */  lw    $a2, 0x50($sp)
/* 0DA708 7F0A7D18 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DA70C 7F0A7D1C 11400003 */  beqz  $t2, .L7F0A7D2C
/* 0DA710 7F0A7D20 2402000C */   li    $v0, 12
/* 0DA714 7F0A7D24 10000001 */  b     .L7F0A7D2C
/* 0DA718 7F0A7D28 2402000E */   li    $v0, 14
.L7F0A7D2C:
/* 0DA71C 7F0A7D2C AFB00010 */  sw    $s0, 0x10($sp)
/* 0DA720 7F0A7D30 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DA724 7F0A7D34 AFA20014 */   sw    $v0, 0x14($sp)
/* 0DA728 7F0A7D38 3C038004 */  lui   $v1, %hi(j_text_trigger) # $v1, 0x8004
/* 0DA72C 7F0A7D3C 8C631150 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0DA730 7F0A7D40 240B004E */  li    $t3, 78
/* 0DA734 7F0A7D44 AFAB0878 */  sw    $t3, 0x878($sp)
/* 0DA738 7F0A7D48 10600003 */  beqz  $v1, .L7F0A7D58
/* 0DA73C 7F0A7D4C 8FAD0084 */   lw    $t5, 0x84($sp)
/* 0DA740 7F0A7D50 10000002 */  b     .L7F0A7D5C
/* 0DA744 7F0A7D54 2402000E */   li    $v0, 14
.L7F0A7D58:
/* 0DA748 7F0A7D58 2402000C */  li    $v0, 12
.L7F0A7D5C:
/* 0DA74C 7F0A7D5C 3C0F8004 */  lui   $t7, %hi(D_800409C4) # $t7, 0x8004
/* 0DA750 7F0A7D60 8DEFA614 */  lw    $t7, %lo(D_800409C4)($t7)
/* 0DA754 7F0A7D64 00026040 */  sll   $t4, $v0, 1
/* 0DA758 7F0A7D68 018D7021 */  addu  $t6, $t4, $t5
/* 0DA75C 7F0A7D6C 15E00018 */  bnez  $t7, .L7F0A7DD0
/* 0DA760 7F0A7D70 AFAE0874 */   sw    $t6, 0x874($sp)
/* 0DA764 7F0A7D74 10600003 */  beqz  $v1, .L7F0A7D84
/* 0DA768 7F0A7D78 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DA76C 7F0A7D7C 10000002 */  b     .L7F0A7D88
/* 0DA770 7F0A7D80 2402000E */   li    $v0, 14
.L7F0A7D84:
/* 0DA774 7F0A7D84 2402000C */  li    $v0, 12
.L7F0A7D88:
/* 0DA778 7F0A7D88 8FB8005C */  lw    $t8, 0x5c($sp)
/* 0DA77C 7F0A7D8C 8FA90058 */  lw    $t1, 0x58($sp)
/* 0DA780 7F0A7D90 3C19A0FF */  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
/* 0DA784 7F0A7D94 3739A0F0 */  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
/* 0DA788 7F0A7D98 240A0064 */  li    $t2, 100
/* 0DA78C 7F0A7D9C AFAA0020 */  sw    $t2, 0x20($sp)
/* 0DA790 7F0A7DA0 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DA794 7F0A7DA4 27A50878 */  addiu $a1, $sp, 0x878
/* 0DA798 7F0A7DA8 27A60874 */  addiu $a2, $sp, 0x874
/* 0DA79C 7F0A7DAC 8FA70050 */  lw    $a3, 0x50($sp)
/* 0DA7A0 7F0A7DB0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0DA7A4 7F0A7DB4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DA7A8 7F0A7DB8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DA7AC 7F0A7DBC AFB80010 */  sw    $t8, 0x10($sp)
/* 0DA7B0 7F0A7DC0 0FC2B35F */  jal   en_text_write_stuff
/* 0DA7B4 7F0A7DC4 AFA9001C */   sw    $t1, 0x1c($sp)
/* 0DA7B8 7F0A7DC8 1000001A */  b     .L7F0A7E34
/* 0DA7BC 7F0A7DCC AFA20930 */   sw    $v0, 0x930($sp)
.L7F0A7DD0:
/* 0DA7C0 7F0A7DD0 10600003 */  beqz  $v1, .L7F0A7DE0
/* 0DA7C4 7F0A7DD4 8FA40930 */   lw    $a0, 0x930($sp)
/* 0DA7C8 7F0A7DD8 10000002 */  b     .L7F0A7DE4
/* 0DA7CC 7F0A7DDC 2402000E */   li    $v0, 14
.L7F0A7DE0:
/* 0DA7D0 7F0A7DE0 2402000C */  li    $v0, 12
.L7F0A7DE4:
/* 0DA7D4 7F0A7DE4 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DA7D8 7F0A7DE8 8FAB005C */  lw    $t3, 0x5c($sp)
/* 0DA7DC 7F0A7DEC 3C0D0070 */  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
/* 0DA7E0 7F0A7DF0 35AD00A0 */  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
/* 0DA7E4 7F0A7DF4 240CFFFF */  li    $t4, -1
/* 0DA7E8 7F0A7DF8 24180064 */  li    $t8, 100
/* 0DA7EC 7F0A7DFC 25CF0001 */  addiu $t7, $t6, 1
/* 0DA7F0 7F0A7E00 AFAF0020 */  sw    $t7, 0x20($sp)
/* 0DA7F4 7F0A7E04 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DA7F8 7F0A7E08 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0DA7FC 7F0A7E0C AFAD001C */  sw    $t5, 0x1c($sp)
/* 0DA800 7F0A7E10 27A50878 */  addiu $a1, $sp, 0x878
/* 0DA804 7F0A7E14 27A60874 */  addiu $a2, $sp, 0x874
/* 0DA808 7F0A7E18 8FA70050 */  lw    $a3, 0x50($sp)
/* 0DA80C 7F0A7E1C AFB00014 */  sw    $s0, 0x14($sp)
/* 0DA810 7F0A7E20 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DA814 7F0A7E24 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0DA818 7F0A7E28 0FC2B66B */  jal   jp_text_write_stuff
/* 0DA81C 7F0A7E2C AFAB0010 */   sw    $t3, 0x10($sp)
/* 0DA820 7F0A7E30 AFA20930 */  sw    $v0, 0x930($sp)
.L7F0A7E34:
/* 0DA824 7F0A7E34 0FC29DA4 */  jal   sub_GAME_7F0A8378
/* 0DA828 7F0A7E38 00000000 */   nop   
.L7F0A7E3C:
/* 0DA82C 7F0A7E3C 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0A7E40:
/* 0DA830 7F0A7E40 8FA20930 */  lw    $v0, 0x930($sp)
/* 0DA834 7F0A7E44 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DA838 7F0A7E48 03E00008 */  jr    $ra
/* 0DA83C 7F0A7E4C 27BD0930 */   addiu $sp, $sp, 0x930
)
#endif

#endif


Gfx *unused_draw_watch_inventory_page(Gfx *gdl, Mtx *param_2) {
    s32 temp_1;
    s32 sp70;
    s32 sp6C;
    s32 sp64,sp68; //unused?

    s32 sp60;
    s32 sp5C;    
    s32 sp58;
    s32 sp54;
    s32 ptr_first_font;
    s32 ptr_second_font;

    u16 *long_name;
    s32 temp_2;

    sp58 = 0;
    sp54 = 0;

    ptr_first_font = ptrFirstFontTableSmall;
    ptr_second_font = ptrSecondFontTableSmall;

    long_name = bondinvGetLongNameByIndex(g_curWatchItemIndex);
    gdl = draw_background_health_and_armor(gdl, param_2, 0);

    if (check_watch_page_transistion_running() != 1)
    {
        temp_1 = D_800409C4;
        if (temp_1 > 0)
        {
            D_800409C4 = temp_1 - 1;
        }

        sub_GAME_7F0A5B80();
        gdl = microcode_constructor(gdl);

        sub_GAME_7F0AE98C(&sp58, &sp54, long_name, ptr_second_font, ptr_first_font, 0);

        sp70 = ((s32) (0xAA - sp54) / 2) + 0x4B;
        temp_2 = sp70;

        sp6C = 0x1E;
        gdl = microcode_constructor_related_to_menus(gdl, temp_2, 0x1E, sp60, sp5C, 0x800050);

        if (D_800409C0 != 0)
        {
            sub_GAME_7F0A8378();
            if (D_800409C4 == 0)
            {
                gdl = en_text_write_stuff(gdl, &sp70, &sp6C, long_name, ptr_second_font, ptr_first_font, 0xA0FFA0F0, sp54, 0x64, 0, 0);
            }
            else
            {
                gdl = jp_text_write_stuff(gdl, &sp70, &sp6C, long_name, ptr_second_font, ptr_first_font, -1, 0x7000A0, sp54 + 1, 0x64, 0, 0);
            }
        }
        else
        {
            gdl = en_text_write_stuff(gdl, &sp70, &sp6C, long_name, ptr_second_font, ptr_first_font, 0xAA00B0, sp54, 0x64, 0, 0);
        }

    }

    return gdl;
}


#ifdef NONMATCHING
void sub_GAME_7F0A8D40(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058534
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F0A8D40
/* 0DD870 7F0A8D40 44862000 */  mtc1  $a2, $f4
/* 0DD874 7F0A8D44 3C018006 */  lui   $at, %hi(D_80058534)
/* 0DD878 7F0A8D48 44856000 */  mtc1  $a1, $f12
/* 0DD87C 7F0A8D4C C4288534 */  lwc1  $f8, %lo(D_80058534)($at)
/* 0DD880 7F0A8D50 468021A0 */  cvt.s.w $f6, $f4
/* 0DD884 7F0A8D54 848E0020 */  lh    $t6, 0x20($a0)
/* 0DD888 7F0A8D58 848F0040 */  lh    $t7, 0x40($a0)
/* 0DD88C 7F0A8D5C 00002825 */  move  $a1, $zero
/* 0DD890 7F0A8D60 00803825 */  move  $a3, $a0
/* 0DD894 7F0A8D64 460C4281 */  sub.s $f10, $f8, $f12
/* 0DD898 7F0A8D68 240900E0 */  li    $t1, 224
/* 0DD89C 7F0A8D6C 24080040 */  li    $t0, 64
/* 0DD8A0 7F0A8D70 24030020 */  li    $v1, 32
/* 0DD8A4 7F0A8D74 460A3402 */  mul.s $f16, $f6, $f10
/* 0DD8A8 7F0A8D78 01CF1023 */  subu  $v0, $t6, $t7
/* 0DD8AC 7F0A8D7C 4600848D */  trunc.w.s $f18, $f16
/* 0DD8B0 7F0A8D80 44069000 */  mfc1  $a2, $f18
/* 0DD8B4 7F0A8D84 00000000 */  nop
.L7F0A8D88:
/* 0DD8B8 7F0A8D88 24A50001 */  addiu $a1, $a1, 1
/* 0DD8BC 7F0A8D8C 28A10004 */  slti  $at, $a1, 4
/* 0DD8C0 7F0A8D90 24E70010 */  addiu $a3, $a3, 0x10
/* 0DD8C4 7F0A8D94 A0E3FFFC */  sb    $v1, -4($a3)
/* 0DD8C8 7F0A8D98 A0E8FFFD */  sb    $t0, -3($a3)
/* 0DD8CC 7F0A8D9C A0E3FFFE */  sb    $v1, -2($a3)
/* 0DD8D0 7F0A8DA0 1420FFF9 */  bnez  $at, .L7F0A8D88
/* 0DD8D4 7F0A8DA4 A0E9FFFF */   sb    $t1, -1($a3)
/* 0DD8D8 7F0A8DA8 3C0142C0 */  li    $at, 0x42C00000 # 96.000000
/* 0DD8DC 7F0A8DAC 44817000 */  mtc1  $at, $f14
/* 0DD8E0 7F0A8DB0 3C014240 */  li    $at, 0x42400000 # 48.000000
/* 0DD8E4 7F0A8DB4 44811000 */  mtc1  $at, $f2
/* 0DD8E8 7F0A8DB8 24050004 */  li    $a1, 4
/* 0DD8EC 7F0A8DBC 24870040 */  addiu $a3, $a0, 0x40
/* 0DD8F0 7F0A8DC0 2408000C */  li    $t0, 12
.L7F0A8DC4:
/* 0DD8F4 7F0A8DC4 28A1000A */  slti  $at, $a1, 0xa
/* 0DD8F8 7F0A8DC8 10200024 */  beqz  $at, .L7F0A8E5C
/* 0DD8FC 7F0A8DCC 00465021 */   addu  $t2, $v0, $a2
/* 0DD900 7F0A8DD0 460C1102 */  mul.s $f4, $f2, $f12
/* 0DD904 7F0A8DD4 28A10006 */  slti  $at, $a1, 6
/* 0DD908 7F0A8DD8 460C7182 */  mul.s $f6, $f14, $f12
/* 0DD90C 7F0A8DDC 4600220D */  trunc.w.s $f8, $f4
/* 0DD910 7F0A8DE0 4600328D */  trunc.w.s $f10, $f6
/* 0DD914 7F0A8DE4 44034000 */  mfc1  $v1, $f8
/* 0DD918 7F0A8DE8 440B5000 */  mfc1  $t3, $f10
/* 0DD91C 7F0A8DEC 24630040 */  addiu $v1, $v1, 0x40
/* 0DD920 7F0A8DF0 A0E3000C */  sb    $v1, 0xc($a3)
/* 0DD924 7F0A8DF4 256C0080 */  addiu $t4, $t3, 0x80
/* 0DD928 7F0A8DF8 A0EC000D */  sb    $t4, 0xd($a3)
/* 0DD92C 7F0A8DFC 1420002D */  bnez  $at, .L7F0A8EB4
/* 0DD930 7F0A8E00 A0E3000E */   sb    $v1, 0xe($a3)
/* 0DD934 7F0A8E04 44868000 */  mtc1  $a2, $f16
/* 0DD938 7F0A8E08 44824000 */  mtc1  $v0, $f8
/* 0DD93C 7F0A8E0C 848D0040 */  lh    $t5, 0x40($a0)
/* 0DD940 7F0A8E10 46808020 */  cvt.s.w $f0, $f16
/* 0DD944 7F0A8E14 448D9000 */  mtc1  $t5, $f18
/* 0DD948 7F0A8E18 468041A0 */  cvt.s.w $f6, $f8
/* 0DD94C 7F0A8E1C 46809120 */  cvt.s.w $f4, $f18
/* 0DD950 7F0A8E20 46003280 */  add.s $f10, $f6, $f0
/* 0DD954 7F0A8E24 460C5402 */  mul.s $f16, $f10, $f12
/* 0DD958 7F0A8E28 46102480 */  add.s $f18, $f4, $f16
/* 0DD95C 7F0A8E2C 46009201 */  sub.s $f8, $f18, $f0
/* 0DD960 7F0A8E30 4600418D */  trunc.w.s $f6, $f8
/* 0DD964 7F0A8E34 440F3000 */  mfc1  $t7, $f6
/* 0DD968 7F0A8E38 00000000 */  nop
/* 0DD96C 7F0A8E3C A4EF0000 */  sh    $t7, ($a3)
/* 0DD970 7F0A8E40 84F80000 */  lh    $t8, ($a3)
/* 0DD974 7F0A8E44 84830040 */  lh    $v1, 0x40($a0)
/* 0DD978 7F0A8E48 0303082A */  slt   $at, $t8, $v1
/* 0DD97C 7F0A8E4C 5020001A */  beql  $at, $zero, .L7F0A8EB8
/* 0DD980 7F0A8E50 24A50001 */   addiu $a1, $a1, 1
/* 0DD984 7F0A8E54 10000017 */  b     .L7F0A8EB4
/* 0DD988 7F0A8E58 A4E30000 */   sh    $v1, ($a3)
.L7F0A8E5C:
/* 0DD98C 7F0A8E5C 448A8000 */  mtc1  $t2, $f16
/* 0DD990 7F0A8E60 84990040 */  lh    $t9, 0x40($a0)
/* 0DD994 7F0A8E64 468084A0 */  cvt.s.w $f18, $f16
/* 0DD998 7F0A8E68 44995000 */  mtc1  $t9, $f10
/* 0DD99C 7F0A8E6C 00000000 */  nop
/* 0DD9A0 7F0A8E70 46805120 */  cvt.s.w $f4, $f10
/* 0DD9A4 7F0A8E74 460C9202 */  mul.s $f8, $f18, $f12
/* 0DD9A8 7F0A8E78 44865000 */  mtc1  $a2, $f10
/* 0DD9AC 7F0A8E7C 00000000 */  nop
/* 0DD9B0 7F0A8E80 46805420 */  cvt.s.w $f16, $f10
/* 0DD9B4 7F0A8E84 46082180 */  add.s $f6, $f4, $f8
/* 0DD9B8 7F0A8E88 46103480 */  add.s $f18, $f6, $f16
/* 0DD9BC 7F0A8E8C 4600910D */  trunc.w.s $f4, $f18
/* 0DD9C0 7F0A8E90 440C2000 */  mfc1  $t4, $f4
/* 0DD9C4 7F0A8E94 00000000 */  nop
/* 0DD9C8 7F0A8E98 A4EC0000 */  sh    $t4, ($a3)
/* 0DD9CC 7F0A8E9C 84ED0000 */  lh    $t5, ($a3)
/* 0DD9D0 7F0A8EA0 84830020 */  lh    $v1, 0x20($a0)
/* 0DD9D4 7F0A8EA4 006D082A */  slt   $at, $v1, $t5
/* 0DD9D8 7F0A8EA8 50200003 */  beql  $at, $zero, .L7F0A8EB8
/* 0DD9DC 7F0A8EAC 24A50001 */   addiu $a1, $a1, 1
/* 0DD9E0 7F0A8EB0 A4E30000 */  sh    $v1, ($a3)
.L7F0A8EB4:
/* 0DD9E4 7F0A8EB4 24A50001 */  addiu $a1, $a1, 1
.L7F0A8EB8:
/* 0DD9E8 7F0A8EB8 14A8FFC2 */  bne   $a1, $t0, .L7F0A8DC4
/* 0DD9EC 7F0A8EBC 24E70010 */   addiu $a3, $a3, 0x10
/* 0DD9F0 7F0A8EC0 848200A0 */  lh    $v0, 0xa0($a0)
/* 0DD9F4 7F0A8EC4 A4820010 */  sh    $v0, 0x10($a0)
/* 0DD9F8 7F0A8EC8 03E00008 */  jr    $ra
/* 0DD9FC 7F0A8ECC A4820000 */   sh    $v0, ($a0)
)
#endif

void sub_GAME_7F0A8ED0(u16* arg0) {
    s32 sp1C;
    s32 temp_v1;

    sp1C = joyGetStickX(PLAYER_1);
    temp_v1 = *arg0;
    
    if (joyGetButtons(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD)) {
        temp_v1 = temp_v1 + 0x400;
    } else if (joyGetButtons(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD)) {
        temp_v1 = temp_v1 - 0x400;
    }

    if (sp1C >= 0x47) {
        sp1C = 0x46;
    } else if (sp1C < -0x46) {
        sp1C = -0x46;
    }

    if (sp1C >= 8) {
        temp_v1 += (sp1C * 0x800 + -0x3800) / 0x46;
    } else if (sp1C < -7) {
        temp_v1 += (sp1C * 0x800 + 0x3800) / 0x46;
    }

    if (temp_v1 >= 0x8000) {
        *arg0 = 0x7FFF;
    } else if (temp_v1 < 0) {
        *arg0 = 0;
    } else {
        *arg0 = temp_v1;
    }
}





#ifdef NONMATCHING
void sub_GAME_7F0A8FEC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058538
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F0A8FEC
/* 0DDB1C 7F0A8FEC 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0DDB20 7F0A8FF0 AFB00028 */  sw    $s0, 0x28($sp)
/* 0DDB24 7F0A8FF4 00808025 */  move  $s0, $a0
/* 0DDB28 7F0A8FF8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0DDB2C 7F0A8FFC 0FC2F5B1 */  jal   dynAllocate7F0BD6C4
/* 0DDB30 7F0A9000 2404000C */   li    $a0, 12
/* 0DDB34 7F0A9004 0C002472 */  jal   sndGetSfxSlotFirstNaturalVolume
/* 0DDB38 7F0A9008 AFA2003C */   sw    $v0, 0x3c($sp)
/* 0DDB3C 7F0A900C 3C0E8004 */  lui   $t6, %hi(watch_item_is_actively_selected)
/* 0DDB40 7F0A9010 8DCE09A8 */  lw    $t6, %lo(watch_item_is_actively_selected)($t6)
/* 0DDB44 7F0A9014 A7A20046 */  sh    $v0, 0x46($sp)
/* 0DDB48 7F0A9018 3C0F8004 */  lui   $t7, %hi(game_options_index)
/* 0DDB4C 7F0A901C 51C00008 */  beql  $t6, $zero, .L7F0A9040
/* 0DDB50 7F0A9020 97B80046 */   lhu   $t8, 0x46($sp)
/* 0DDB54 7F0A9024 8DEF099C */  lw    $t7, %lo(game_options_index)($t7)
/* 0DDB58 7F0A9028 24010001 */  li    $at, 1
/* 0DDB5C 7F0A902C 55E10004 */  bnel  $t7, $at, .L7F0A9040
/* 0DDB60 7F0A9030 97B80046 */   lhu   $t8, 0x46($sp)
/* 0DDB64 7F0A9034 0FC2A3B4 */  jal   sub_GAME_7F0A8ED0
/* 0DDB68 7F0A9038 27A40046 */   addiu $a0, $sp, 0x46
/* 0DDB6C 7F0A903C 97B80046 */  lhu   $t8, 0x46($sp)
.L7F0A9040:
/* 0DDB70 7F0A9040 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DDB74 7F0A9044 44982000 */  mtc1  $t8, $f4
/* 0DDB78 7F0A9048 07010004 */  bgez  $t8, .L7F0A905C
/* 0DDB7C 7F0A904C 468021A0 */   cvt.s.w $f6, $f4
/* 0DDB80 7F0A9050 44814000 */  mtc1  $at, $f8
/* 0DDB84 7F0A9054 00000000 */  nop
/* 0DDB88 7F0A9058 46083180 */  add.s $f6, $f6, $f8
.L7F0A905C:
/* 0DDB8C 7F0A905C 3C018006 */  lui   $at, %hi(D_80058538)
/* 0DDB90 7F0A9060 C42A8538 */  lwc1  $f10, %lo(D_80058538)($at)
/* 0DDB94 7F0A9064 03002025 */  move  $a0, $t8
/* 0DDB98 7F0A9068 460A3403 */  div.s $f16, $f6, $f10
/* 0DDB9C 7F0A906C 0C00247A */  jal   sndApplyVolumeAllSfxSlot
/* 0DDBA0 7F0A9070 E7B00040 */   swc1  $f16, 0x40($sp)
/* 0DDBA4 7F0A9074 02001025 */  move  $v0, $s0
/* 0DDBA8 7F0A9078 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0DDBAC 7F0A907C 3C080050 */  lui   $t0, (0x00504240 >> 16) # lui $t0, 0x50
/* 0DDBB0 7F0A9080 35084240 */  ori   $t0, (0x00504240 & 0xFFFF) # ori $t0, $t0, 0x4240
/* 0DDBB4 7F0A9084 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0DDBB8 7F0A9088 AC590000 */  sw    $t9, ($v0)
/* 0DDBBC 7F0A908C AC480004 */  sw    $t0, 4($v0)
/* 0DDBC0 7F0A9090 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0DDBC4 7F0A9094 3C018000 */  lui   $at, 0x8000
/* 0DDBC8 7F0A9098 26040008 */  addiu $a0, $s0, 8
/* 0DDBCC 7F0A909C 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDBD0 7F0A90A0 00A12821 */   addu  $a1, $a1, $at
/* 0DDBD4 7F0A90A4 24090014 */  li    $t1, 20
/* 0DDBD8 7F0A90A8 240AFED5 */  li    $t2, -299
/* 0DDBDC 7F0A90AC 240BFF33 */  li    $t3, -205
/* 0DDBE0 7F0A90B0 00408025 */  move  $s0, $v0
/* 0DDBE4 7F0A90B4 AFAB0018 */  sw    $t3, 0x18($sp)
/* 0DDBE8 7F0A90B8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DDBEC 7F0A90BC AFA90010 */  sw    $t1, 0x10($sp)
/* 0DDBF0 7F0A90C0 8FA4003C */  lw    $a0, 0x3c($sp)
/* 0DDBF4 7F0A90C4 00002825 */  move  $a1, $zero
/* 0DDBF8 7F0A90C8 00003025 */  move  $a2, $zero
/* 0DDBFC 7F0A90CC 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDC00 7F0A90D0 24070258 */   li    $a3, 600
/* 0DDC04 7F0A90D4 3C018000 */  lui   $at, 0x8000
/* 0DDC08 7F0A90D8 AFA20038 */  sw    $v0, 0x38($sp)
/* 0DDC0C 7F0A90DC 00412821 */  addu  $a1, $v0, $at
/* 0DDC10 7F0A90E0 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDC14 7F0A90E4 02002025 */   move  $a0, $s0
/* 0DDC18 7F0A90E8 240C0014 */  li    $t4, 20
/* 0DDC1C 7F0A90EC 240DFED5 */  li    $t5, -299
/* 0DDC20 7F0A90F0 240EFF33 */  li    $t6, -205
/* 0DDC24 7F0A90F4 00408025 */  move  $s0, $v0
/* 0DDC28 7F0A90F8 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DDC2C 7F0A90FC AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DDC30 7F0A9100 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DDC34 7F0A9104 8FA40038 */  lw    $a0, 0x38($sp)
/* 0DDC38 7F0A9108 00002825 */  move  $a1, $zero
/* 0DDC3C 7F0A910C 00003025 */  move  $a2, $zero
/* 0DDC40 7F0A9110 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDC44 7F0A9114 24070258 */   li    $a3, 600
/* 0DDC48 7F0A9118 3C018000 */  lui   $at, 0x8000
/* 0DDC4C 7F0A911C AFA20038 */  sw    $v0, 0x38($sp)
/* 0DDC50 7F0A9120 00412821 */  addu  $a1, $v0, $at
/* 0DDC54 7F0A9124 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDC58 7F0A9128 02002025 */   move  $a0, $s0
/* 0DDC5C 7F0A912C 240F0014 */  li    $t7, 20
/* 0DDC60 7F0A9130 2418FED5 */  li    $t8, -299
/* 0DDC64 7F0A9134 2419FF33 */  li    $t9, -205
/* 0DDC68 7F0A9138 00408025 */  move  $s0, $v0
/* 0DDC6C 7F0A913C AFB90018 */  sw    $t9, 0x18($sp)
/* 0DDC70 7F0A9140 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DDC74 7F0A9144 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DDC78 7F0A9148 8FA40038 */  lw    $a0, 0x38($sp)
/* 0DDC7C 7F0A914C 00002825 */  move  $a1, $zero
/* 0DDC80 7F0A9150 00003025 */  move  $a2, $zero
/* 0DDC84 7F0A9154 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDC88 7F0A9158 24070258 */   li    $a3, 600
/* 0DDC8C 7F0A915C 8FA4003C */  lw    $a0, 0x3c($sp)
/* 0DDC90 7F0A9160 8FA50040 */  lw    $a1, 0x40($sp)
/* 0DDC94 7F0A9164 0FC2A350 */  jal   sub_GAME_7F0A8D40
/* 0DDC98 7F0A9168 2406001E */   li    $a2, 30
/* 0DDC9C 7F0A916C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0DDCA0 7F0A9170 02001025 */  move  $v0, $s0
/* 0DDCA4 7F0A9174 8FB00028 */  lw    $s0, 0x28($sp)
/* 0DDCA8 7F0A9178 03E00008 */  jr    $ra
/* 0DDCAC 7F0A917C 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif


u16 call_sndGetSfxSlotFirstNaturalVolume(void) {
    return sndGetSfxSlotFirstNaturalVolume();
}


void sub_GAME_7F0A91A0(u16 arg0) {
    sndApplyVolumeAllSfxSlot(arg0);
}


#ifdef NONMATCHING
void sub_GAME_7F0A91C8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005853C
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F0A91C8
/* 0DDCF8 7F0A91C8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0DDCFC 7F0A91CC AFB00028 */  sw    $s0, 0x28($sp)
/* 0DDD00 7F0A91D0 00808025 */  move  $s0, $a0
/* 0DDD04 7F0A91D4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0DDD08 7F0A91D8 0FC2F5B1 */  jal   dynAllocate7F0BD6C4
/* 0DDD0C 7F0A91DC 2404000C */   li    $a0, 12
/* 0DDD10 7F0A91E0 0FC2A4D6 */  jal   get_mTrack2Vol
/* 0DDD14 7F0A91E4 AFA2003C */   sw    $v0, 0x3c($sp)
/* 0DDD18 7F0A91E8 3C0E8004 */  lui   $t6, %hi(watch_item_is_actively_selected)
/* 0DDD1C 7F0A91EC 8DCE09A8 */  lw    $t6, %lo(watch_item_is_actively_selected)($t6)
/* 0DDD20 7F0A91F0 A7A20046 */  sh    $v0, 0x46($sp)
/* 0DDD24 7F0A91F4 3C0F8004 */  lui   $t7, %hi(game_options_index)
/* 0DDD28 7F0A91F8 51C00007 */  beql  $t6, $zero, .L7F0A9218
/* 0DDD2C 7F0A91FC 97B80046 */   lhu   $t8, 0x46($sp)
/* 0DDD30 7F0A9200 8DEF099C */  lw    $t7, %lo(game_options_index)($t7)
/* 0DDD34 7F0A9204 55E00004 */  bnezl $t7, .L7F0A9218
/* 0DDD38 7F0A9208 97B80046 */   lhu   $t8, 0x46($sp)
/* 0DDD3C 7F0A920C 0FC2A3B4 */  jal   sub_GAME_7F0A8ED0
/* 0DDD40 7F0A9210 27A40046 */   addiu $a0, $sp, 0x46
/* 0DDD44 7F0A9214 97B80046 */  lhu   $t8, 0x46($sp)
.L7F0A9218:
/* 0DDD48 7F0A9218 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DDD4C 7F0A921C 44982000 */  mtc1  $t8, $f4
/* 0DDD50 7F0A9220 07010004 */  bgez  $t8, .L7F0A9234
/* 0DDD54 7F0A9224 468021A0 */   cvt.s.w $f6, $f4
/* 0DDD58 7F0A9228 44814000 */  mtc1  $at, $f8
/* 0DDD5C 7F0A922C 00000000 */  nop
/* 0DDD60 7F0A9230 46083180 */  add.s $f6, $f6, $f8
.L7F0A9234:
/* 0DDD64 7F0A9234 3C018006 */  lui   $at, %hi(D_8005853C)
/* 0DDD68 7F0A9238 C42A853C */  lwc1  $f10, %lo(D_8005853C)($at)
/* 0DDD6C 7F0A923C 03002025 */  move  $a0, $t8
/* 0DDD70 7F0A9240 460A3403 */  div.s $f16, $f6, $f10
/* 0DDD74 7F0A9244 0FC2A4D9 */  jal   set_mTrack2Vol
/* 0DDD78 7F0A9248 E7B00040 */   swc1  $f16, 0x40($sp)
/* 0DDD7C 7F0A924C 02001025 */  move  $v0, $s0
/* 0DDD80 7F0A9250 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0DDD84 7F0A9254 3C080050 */  lui   $t0, (0x00504240 >> 16) # lui $t0, 0x50
/* 0DDD88 7F0A9258 35084240 */  ori   $t0, (0x00504240 & 0xFFFF) # ori $t0, $t0, 0x4240
/* 0DDD8C 7F0A925C 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0DDD90 7F0A9260 AC590000 */  sw    $t9, ($v0)
/* 0DDD94 7F0A9264 AC480004 */  sw    $t0, 4($v0)
/* 0DDD98 7F0A9268 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0DDD9C 7F0A926C 3C018000 */  lui   $at, 0x8000
/* 0DDDA0 7F0A9270 26040008 */  addiu $a0, $s0, 8
/* 0DDDA4 7F0A9274 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDDA8 7F0A9278 00A12821 */   addu  $a1, $a1, $at
/* 0DDDAC 7F0A927C 24090014 */  li    $t1, 20
/* 0DDDB0 7F0A9280 240AFED5 */  li    $t2, -299
/* 0DDDB4 7F0A9284 240BFEED */  li    $t3, -275
/* 0DDDB8 7F0A9288 00408025 */  move  $s0, $v0
/* 0DDDBC 7F0A928C AFAB0018 */  sw    $t3, 0x18($sp)
/* 0DDDC0 7F0A9290 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DDDC4 7F0A9294 AFA90010 */  sw    $t1, 0x10($sp)
/* 0DDDC8 7F0A9298 8FA4003C */  lw    $a0, 0x3c($sp)
/* 0DDDCC 7F0A929C 00002825 */  move  $a1, $zero
/* 0DDDD0 7F0A92A0 00003025 */  move  $a2, $zero
/* 0DDDD4 7F0A92A4 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDDD8 7F0A92A8 24070258 */   li    $a3, 600
/* 0DDDDC 7F0A92AC 3C018000 */  lui   $at, 0x8000
/* 0DDDE0 7F0A92B0 AFA20038 */  sw    $v0, 0x38($sp)
/* 0DDDE4 7F0A92B4 00412821 */  addu  $a1, $v0, $at
/* 0DDDE8 7F0A92B8 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDDEC 7F0A92BC 02002025 */   move  $a0, $s0
/* 0DDDF0 7F0A92C0 240C0014 */  li    $t4, 20
/* 0DDDF4 7F0A92C4 240DFED5 */  li    $t5, -299
/* 0DDDF8 7F0A92C8 240EFEED */  li    $t6, -275
/* 0DDDFC 7F0A92CC 00408025 */  move  $s0, $v0
/* 0DDE00 7F0A92D0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DDE04 7F0A92D4 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DDE08 7F0A92D8 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DDE0C 7F0A92DC 8FA40038 */  lw    $a0, 0x38($sp)
/* 0DDE10 7F0A92E0 00002825 */  move  $a1, $zero
/* 0DDE14 7F0A92E4 00003025 */  move  $a2, $zero
/* 0DDE18 7F0A92E8 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDE1C 7F0A92EC 24070258 */   li    $a3, 600
/* 0DDE20 7F0A92F0 3C018000 */  lui   $at, 0x8000
/* 0DDE24 7F0A92F4 AFA20038 */  sw    $v0, 0x38($sp)
/* 0DDE28 7F0A92F8 00412821 */  addu  $a1, $v0, $at
/* 0DDE2C 7F0A92FC 0FC28ED0 */  jal   sub_GAME_7F0A3B40
/* 0DDE30 7F0A9300 02002025 */   move  $a0, $s0
/* 0DDE34 7F0A9304 240F0014 */  li    $t7, 20
/* 0DDE38 7F0A9308 2418FED5 */  li    $t8, -299
/* 0DDE3C 7F0A930C 2419FEED */  li    $t9, -275
/* 0DDE40 7F0A9310 00408025 */  move  $s0, $v0
/* 0DDE44 7F0A9314 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DDE48 7F0A9318 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DDE4C 7F0A931C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DDE50 7F0A9320 8FA40038 */  lw    $a0, 0x38($sp)
/* 0DDE54 7F0A9324 00002825 */  move  $a1, $zero
/* 0DDE58 7F0A9328 00003025 */  move  $a2, $zero
/* 0DDE5C 7F0A932C 0FC28EAE */  jal   setup_watch_rectangles
/* 0DDE60 7F0A9330 24070258 */   li    $a3, 600
/* 0DDE64 7F0A9334 8FA4003C */  lw    $a0, 0x3c($sp)
/* 0DDE68 7F0A9338 8FA50040 */  lw    $a1, 0x40($sp)
/* 0DDE6C 7F0A933C 0FC2A350 */  jal   sub_GAME_7F0A8D40
/* 0DDE70 7F0A9340 2406001E */   li    $a2, 30
/* 0DDE74 7F0A9344 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0DDE78 7F0A9348 02001025 */  move  $v0, $s0
/* 0DDE7C 7F0A934C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0DDE80 7F0A9350 03E00008 */  jr    $ra
/* 0DDE84 7F0A9354 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif


u16 get_mTrack2Vol(void)
{
  return mTrack2Vol;
}

void set_mTrack2Vol(u16 param_1)
{
    mTrack2Vol = param_1;
    musicTrack2ApplySeqpVol(mTrack2Vol);
}


#ifdef NONMATCHING
void sub_GAME_7F0A9398(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A9398
/* 0DDEC8 7F0A9398 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0DDECC 7F0A939C AFA70074 */  sw    $a3, 0x74($sp)
/* 0DDED0 7F0A93A0 3C028004 */  lui   $v0, %hi(ptrFirstFontTableSmall)
/* 0DDED4 7F0A93A4 8C420EAC */  lw    $v0, %lo(ptrFirstFontTableSmall)($v0)
/* 0DDED8 7F0A93A8 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0DDEDC 7F0A93AC 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0DDEE0 7F0A93B0 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DDEE4 7F0A93B4 00808025 */  move  $s0, $a0
/* 0DDEE8 7F0A93B8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DDEEC 7F0A93BC AFA5006C */  sw    $a1, 0x6c($sp)
/* 0DDEF0 7F0A93C0 AFA60070 */  sw    $a2, 0x70($sp)
/* 0DDEF4 7F0A93C4 240E000A */  li    $t6, 10
/* 0DDEF8 7F0A93C8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DDEFC 7F0A93CC 8FA60074 */  lw    $a2, 0x74($sp)
/* 0DDF00 7F0A93D0 27A50058 */  addiu $a1, $sp, 0x58
/* 0DDF04 7F0A93D4 27A40054 */  addiu $a0, $sp, 0x54
/* 0DDF08 7F0A93D8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0DDF0C 7F0A93DC AFA20050 */  sw    $v0, 0x50($sp)
/* 0DDF10 7F0A93E0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DDF14 7F0A93E4 AFA7004C */   sw    $a3, 0x4c($sp)
/* 0DDF18 7F0A93E8 8FAF0084 */  lw    $t7, 0x84($sp)
/* 0DDF1C 7F0A93EC 8FA2006C */  lw    $v0, 0x6c($sp)
/* 0DDF20 7F0A93F0 8FAC0058 */  lw    $t4, 0x58($sp)
/* 0DDF24 7F0A93F4 11E00008 */  beqz  $t7, .L7F0A9418
/* 0DDF28 7F0A93F8 8FAD0070 */   lw    $t5, 0x70($sp)
/* 0DDF2C 7F0A93FC 8FB80058 */  lw    $t8, 0x58($sp)
/* 0DDF30 7F0A9400 07010003 */  bgez  $t8, .L7F0A9410
/* 0DDF34 7F0A9404 0018C843 */   sra   $t9, $t8, 1
/* 0DDF38 7F0A9408 27010001 */  addiu $at, $t8, 1
/* 0DDF3C 7F0A940C 0001C843 */  sra   $t9, $at, 1
.L7F0A9410:
/* 0DDF40 7F0A9410 10000008 */  b     .L7F0A9434
/* 0DDF44 7F0A9414 00594823 */   subu  $t1, $v0, $t9
.L7F0A9418:
/* 0DDF48 7F0A9418 8FAA0090 */  lw    $t2, 0x90($sp)
/* 0DDF4C 7F0A941C 8FAB0058 */  lw    $t3, 0x58($sp)
/* 0DDF50 7F0A9420 00404825 */  move  $t1, $v0
/* 0DDF54 7F0A9424 11400003 */  beqz  $t2, .L7F0A9434
/* 0DDF58 7F0A9428 00000000 */   nop
/* 0DDF5C 7F0A942C 10000001 */  b     .L7F0A9434
/* 0DDF60 7F0A9430 004B4823 */   subu  $t1, $v0, $t3
.L7F0A9434:
/* 0DDF64 7F0A9434 3C0F8004 */  lui   $t7, %hi(g_WatchBackgroundGreen)
/* 0DDF68 7F0A9438 8DEF0B04 */  lw    $t7, %lo(g_WatchBackgroundGreen)($t7)
/* 0DDF6C 7F0A943C 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0DDF70 7F0A9440 012C1821 */  addu  $v1, $t1, $t4
/* 0DDF74 7F0A9444 29E100E0 */  slti  $at, $t7, 0xe0
/* 0DDF78 7F0A9448 AFA90064 */  sw    $t1, 0x64($sp)
/* 0DDF7C 7F0A944C 1020000A */  beqz  $at, .L7F0A9478
/* 0DDF80 7F0A9450 01AE4021 */   addu  $t0, $t5, $t6
/* 0DDF84 7F0A9454 02001025 */  move  $v0, $s0
/* 0DDF88 7F0A9458 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0DDF8C 7F0A945C 3C190050 */  lui   $t9, (0x0050004B >> 16) # lui $t9, 0x50
/* 0DDF90 7F0A9460 3739004B */  ori   $t9, (0x0050004B & 0xFFFF) # ori $t9, $t9, 0x4b
/* 0DDF94 7F0A9464 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0DDF98 7F0A9468 AC580000 */  sw    $t8, ($v0)
/* 0DDF9C 7F0A946C AC590004 */  sw    $t9, 4($v0)
/* 0DDFA0 7F0A9470 10000009 */  b     .L7F0A9498
/* 0DDFA4 7F0A9474 26100008 */   addiu $s0, $s0, 8
.L7F0A9478:
/* 0DDFA8 7F0A9478 02001025 */  move  $v0, $s0
/* 0DDFAC 7F0A947C 3C0AB900 */  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
/* 0DDFB0 7F0A9480 3C0B0050 */  lui   $t3, (0x005041C8 >> 16) # lui $t3, 0x50
/* 0DDFB4 7F0A9484 356B41C8 */  ori   $t3, (0x005041C8 & 0xFFFF) # ori $t3, $t3, 0x41c8
/* 0DDFB8 7F0A9488 354A031D */  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
/* 0DDFBC 7F0A948C AC4A0000 */  sw    $t2, ($v0)
/* 0DDFC0 7F0A9490 AC4B0004 */  sw    $t3, 4($v0)
/* 0DDFC4 7F0A9494 26100008 */  addiu $s0, $s0, 8
.L7F0A9498:
/* 0DDFC8 7F0A9498 8FAC0088 */  lw    $t4, 0x88($sp)
/* 0DDFCC 7F0A949C 8FA90064 */  lw    $t1, 0x64($sp)
/* 0DDFD0 7F0A94A0 02002025 */  move  $a0, $s0
/* 0DDFD4 7F0A94A4 1180000D */  beqz  $t4, .L7F0A94DC
/* 0DDFD8 7F0A94A8 2525FFFF */   addiu $a1, $t1, -1
/* 0DDFDC 7F0A94AC 8FAD0070 */  lw    $t5, 0x70($sp)
/* 0DDFE0 7F0A94B0 8FAE007C */  lw    $t6, 0x7c($sp)
/* 0DDFE4 7F0A94B4 8FB8008C */  lw    $t8, 0x8c($sp)
/* 0DDFE8 7F0A94B8 250F0001 */  addiu $t7, $t0, 1
/* 0DDFEC 7F0A94BC 01AE3021 */  addu  $a2, $t5, $t6
/* 0DDFF0 7F0A94C0 24C60001 */  addiu $a2, $a2, 1
/* 0DDFF4 7F0A94C4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DDFF8 7F0A94C8 24670001 */  addiu $a3, $v1, 1
/* 0DDFFC 7F0A94CC AFA90064 */  sw    $t1, 0x64($sp)
/* 0DE000 7F0A94D0 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0DE004 7F0A94D4 AFB80014 */   sw    $t8, 0x14($sp)
/* 0DE008 7F0A94D8 00408025 */  move  $s0, $v0
.L7F0A94DC:
/* 0DE00C 7F0A94DC 02001025 */  move  $v0, $s0
/* 0DE010 7F0A94E0 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0DE014 7F0A94E4 3C0A0050 */  lui   $t2, (0x005041C8 >> 16) # lui $t2, 0x50
/* 0DE018 7F0A94E8 354A41C8 */  ori   $t2, (0x005041C8 & 0xFFFF) # ori $t2, $t2, 0x41c8
/* 0DE01C 7F0A94EC 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0DE020 7F0A94F0 AC590000 */  sw    $t9, ($v0)
/* 0DE024 7F0A94F4 AC4A0004 */  sw    $t2, 4($v0)
/* 0DE028 7F0A94F8 8FAB007C */  lw    $t3, 0x7c($sp)
/* 0DE02C 7F0A94FC 26100008 */  addiu $s0, $s0, 8
/* 0DE030 7F0A9500 02002025 */  move  $a0, $s0
/* 0DE034 7F0A9504 15600012 */  bnez  $t3, .L7F0A9550
/* 0DE038 7F0A9508 27A50064 */   addiu $a1, $sp, 0x64
/* 0DE03C 7F0A950C 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0DE040 7F0A9510 8FAD0050 */  lw    $t5, 0x50($sp)
/* 0DE044 7F0A9514 8FAE0078 */  lw    $t6, 0x78($sp)
/* 0DE048 7F0A9518 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0DE04C 7F0A951C 8FB80054 */  lw    $t8, 0x54($sp)
/* 0DE050 7F0A9520 2419000A */  li    $t9, 10
/* 0DE054 7F0A9524 AFB90028 */  sw    $t9, 0x28($sp)
/* 0DE058 7F0A9528 27A60070 */  addiu $a2, $sp, 0x70
/* 0DE05C 7F0A952C 8FA70074 */  lw    $a3, 0x74($sp)
/* 0DE060 7F0A9530 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE064 7F0A9534 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DE068 7F0A9538 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DE06C 7F0A953C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DE070 7F0A9540 AFAF001C */  sw    $t7, 0x1c($sp)
/* 0DE074 7F0A9544 0FC2B6AF */  jal   en_text_write_stuff
/* 0DE078 7F0A9548 AFB80020 */   sw    $t8, 0x20($sp)
/* 0DE07C 7F0A954C 00408025 */  move  $s0, $v0
.L7F0A9550:
/* 0DE080 7F0A9550 8FAA007C */  lw    $t2, 0x7c($sp)
/* 0DE084 7F0A9554 02002025 */  move  $a0, $s0
/* 0DE088 7F0A9558 27A50064 */  addiu $a1, $sp, 0x64
/* 0DE08C 7F0A955C 11400014 */  beqz  $t2, .L7F0A95B0
/* 0DE090 7F0A9560 27A60070 */   addiu $a2, $sp, 0x70
/* 0DE094 7F0A9564 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0DE098 7F0A9568 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0DE09C 7F0A956C 8FAC0050 */  lw    $t4, 0x50($sp)
/* 0DE0A0 7F0A9570 8FAD0078 */  lw    $t5, 0x78($sp)
/* 0DE0A4 7F0A9574 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0DE0A8 7F0A9578 8FB90054 */  lw    $t9, 0x54($sp)
/* 0DE0AC 7F0A957C 240A000A */  li    $t2, 10
/* 0DE0B0 7F0A9580 25F80001 */  addiu $t8, $t7, 1
/* 0DE0B4 7F0A9584 AFB80020 */  sw    $t8, 0x20($sp)
/* 0DE0B8 7F0A9588 AFAA002C */  sw    $t2, 0x2c($sp)
/* 0DE0BC 7F0A958C 8FA70074 */  lw    $a3, 0x74($sp)
/* 0DE0C0 7F0A9590 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DE0C4 7F0A9594 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DE0C8 7F0A9598 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0DE0CC 7F0A959C AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DE0D0 7F0A95A0 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0DE0D4 7F0A95A4 0FC2B9BB */  jal   jp_text_write_stuff
/* 0DE0D8 7F0A95A8 AFB90024 */   sw    $t9, 0x24($sp)
/* 0DE0DC 7F0A95AC 00408025 */  move  $s0, $v0
.L7F0A95B0:
/* 0DE0E0 7F0A95B0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DE0E4 7F0A95B4 02001025 */  move  $v0, $s0
/* 0DE0E8 7F0A95B8 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DE0EC 7F0A95BC 03E00008 */  jr    $ra
/* 0DE0F0 7F0A95C0 27BD0068 */   addiu $sp, $sp, 0x68
)
#endif



f32 sub_GAME_7F0A95C4(f32 param_1, f32 param_2, f32 param_3)
{
    if (param_1 < param_2) {
        param_1 += (param_2 - param_1) / param_3;
    } else if (param_2 < param_1) {
        param_1 -= (param_1 - param_2) / param_3;
    }

    return param_1;
}


s32 sub_GAME_7F0A9610(void) {

    if ((D_80040B24 < 0.1f) &&
        (D_80040B24 > -0.1f) &&
        (D_80040B20 < 0.1f) &&
        (D_80040B20 > -0.1f))
    {

        return 1;

    }
    return 0;
}

#ifdef NONMATCHING
void sub_GAME_7F0A9684(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80058548
.word 0x3e4ccccd /*0.2*/
glabel D_8005854C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0A9684
/* 0DE1B4 7F0A9684 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DE1B8 7F0A9688 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DE1BC 7F0A968C AFA40018 */  sw    $a0, 0x18($sp)
/* 0DE1C0 7F0A9690 AFA60020 */  sw    $a2, 0x20($sp)
/* 0DE1C4 7F0A9694 AFA70024 */  sw    $a3, 0x24($sp)
/* 0DE1C8 7F0A9698 83A4001B */  lb    $a0, 0x1b($sp)
/* 0DE1CC 7F0A969C 0C00303B */  jal   joyGetStickX
/* 0DE1D0 7F0A96A0 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0DE1D4 7F0A96A4 2841000A */  slti  $at, $v0, 0xa
/* 0DE1D8 7F0A96A8 10200007 */  beqz  $at, .L7F0A96C8
/* 0DE1DC 7F0A96AC 8FA5001C */   lw    $a1, 0x1c($sp)
/* 0DE1E0 7F0A96B0 83A4001B */  lb    $a0, 0x1b($sp)
/* 0DE1E4 7F0A96B4 0C00303B */  jal   joyGetStickX
/* 0DE1E8 7F0A96B8 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0DE1EC 7F0A96BC 2841FFF7 */  slti  $at, $v0, -9
/* 0DE1F0 7F0A96C0 1020000B */  beqz  $at, .L7F0A96F0
/* 0DE1F4 7F0A96C4 8FA5001C */   lw    $a1, 0x1c($sp)
.L7F0A96C8:
/* 0DE1F8 7F0A96C8 3C0E8004 */  lui   $t6, %hi(watch_item_is_actively_selected)
/* 0DE1FC 7F0A96CC 8DCE09A8 */  lw    $t6, %lo(watch_item_is_actively_selected)($t6)
/* 0DE200 7F0A96D0 3C0F8004 */  lui   $t7, %hi(controller_options_index)
/* 0DE204 7F0A96D4 51C00007 */  beql  $t6, $zero, .L7F0A96F4
/* 0DE208 7F0A96D8 8CA20000 */   lw    $v0, ($a1)
/* 0DE20C 7F0A96DC 8DEF0998 */  lw    $t7, %lo(controller_options_index)($t7)
/* 0DE210 7F0A96E0 24010001 */  li    $at, 1
/* 0DE214 7F0A96E4 00001025 */  move  $v0, $zero
/* 0DE218 7F0A96E8 51E10009 */  beql  $t7, $at, .L7F0A9710
/* 0DE21C 7F0A96EC ACA00000 */   sw    $zero, ($a1)
.L7F0A96F0:
/* 0DE220 7F0A96F0 8CA20000 */  lw    $v0, ($a1)
.L7F0A96F4:
/* 0DE224 7F0A96F4 28410064 */  slti  $at, $v0, 0x64
/* 0DE228 7F0A96F8 10200005 */  beqz  $at, .L7F0A9710
/* 0DE22C 7F0A96FC 24580001 */   addiu $t8, $v0, 1
/* 0DE230 7F0A9700 ACB80000 */  sw    $t8, ($a1)
/* 0DE234 7F0A9704 10000002 */  b     .L7F0A9710
/* 0DE238 7F0A9708 03001025 */   move  $v0, $t8
/* 0DE23C 7F0A970C ACA00000 */  sw    $zero, ($a1)
.L7F0A9710:
/* 0DE240 7F0A9710 28410064 */  slti  $at, $v0, 0x64
/* 0DE244 7F0A9714 1420000E */  bnez  $at, .L7F0A9750
/* 0DE248 7F0A9718 3C0A8004 */   lui   $t2, %hi(watch_item_is_actively_selected)
/* 0DE24C 7F0A971C 8FA80024 */  lw    $t0, 0x24($sp)
/* 0DE250 7F0A9720 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0DE254 7F0A9724 44814000 */  mtc1  $at, $f8
/* 0DE258 7F0A9728 C5040000 */  lwc1  $f4, ($t0)
/* 0DE25C 7F0A972C 8FB90020 */  lw    $t9, 0x20($sp)
/* 0DE260 7F0A9730 3C064080 */  lui   $a2, 0x4080
/* 0DE264 7F0A9734 46002187 */  neg.s $f6, $f4
/* 0DE268 7F0A9738 C72C0000 */  lwc1  $f12, ($t9)
/* 0DE26C 7F0A973C 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DE270 7F0A9740 46083383 */   div.s $f14, $f6, $f8
/* 0DE274 7F0A9744 8FA90020 */  lw    $t1, 0x20($sp)
/* 0DE278 7F0A9748 1000001D */  b     .L7F0A97C0
/* 0DE27C 7F0A974C E5200000 */   swc1  $f0, ($t1)
.L7F0A9750:
/* 0DE280 7F0A9750 8D4A09A8 */  lw    $t2, %lo(watch_item_is_actively_selected)($t2)
/* 0DE284 7F0A9754 3C0B8004 */  lui   $t3, %hi(controller_options_index)
/* 0DE288 7F0A9758 5140001A */  beql  $t2, $zero, .L7F0A97C4
/* 0DE28C 7F0A975C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0DE290 7F0A9760 8D6B0998 */  lw    $t3, %lo(controller_options_index)($t3)
/* 0DE294 7F0A9764 24010001 */  li    $at, 1
/* 0DE298 7F0A9768 55610016 */  bnel  $t3, $at, .L7F0A97C4
/* 0DE29C 7F0A976C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0DE2A0 7F0A9770 0C00303B */  jal   joyGetStickX
/* 0DE2A4 7F0A9774 83A4001B */   lb    $a0, 0x1b($sp)
/* 0DE2A8 7F0A9778 44825000 */  mtc1  $v0, $f10
/* 0DE2AC 7F0A977C 3C018006 */  lui   $at, %hi(D_80058548)
/* 0DE2B0 7F0A9780 C4248548 */  lwc1  $f4, %lo(D_80058548)($at)
/* 0DE2B4 7F0A9784 46805420 */  cvt.s.w $f16, $f10
/* 0DE2B8 7F0A9788 3C018006 */  lui   $at, %hi(D_8005854C)
/* 0DE2BC 7F0A978C C428854C */  lwc1  $f8, %lo(D_8005854C)($at)
/* 0DE2C0 7F0A9790 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DE2C4 7F0A9794 8FAC0020 */  lw    $t4, 0x20($sp)
/* 0DE2C8 7F0A9798 3C064080 */  lui   $a2, 0x4080
/* 0DE2CC 7F0A979C 46008487 */  neg.s $f18, $f16
/* 0DE2D0 7F0A97A0 44818000 */  mtc1  $at, $f16
/* 0DE2D4 7F0A97A4 46049182 */  mul.s $f6, $f18, $f4
/* 0DE2D8 7F0A97A8 C58C0000 */  lwc1  $f12, ($t4)
/* 0DE2DC 7F0A97AC 46083282 */  mul.s $f10, $f6, $f8
/* 0DE2E0 7F0A97B0 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DE2E4 7F0A97B4 46105383 */   div.s $f14, $f10, $f16
/* 0DE2E8 7F0A97B8 8FAD0020 */  lw    $t5, 0x20($sp)
/* 0DE2EC 7F0A97BC E5A00000 */  swc1  $f0, ($t5)
.L7F0A97C0:
/* 0DE2F0 7F0A97C0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0A97C4:
/* 0DE2F4 7F0A97C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0DE2F8 7F0A97C8 03E00008 */  jr    $ra
/* 0DE2FC 7F0A97CC 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A97D0(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A97D0
/* 0DE300 7F0A97D0 27BDF7B0 */  addiu $sp, $sp, -0x850
/* 0DE304 7F0A97D4 3C068004 */  lui   $a2, %hi(D_800409D8)
/* 0DE308 7F0A97D8 8CC609D8 */  lw    $a2, %lo(D_800409D8)($a2)
/* 0DE30C 7F0A97DC 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall)
/* 0DE310 7F0A97E0 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall)
/* 0DE314 7F0A97E4 8DCE0EAC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0DE318 7F0A97E8 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0DE31C 7F0A97EC AFB00034 */  sw    $s0, 0x34($sp)
/* 0DE320 7F0A97F0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DE324 7F0A97F4 AFB10038 */  sw    $s1, 0x38($sp)
/* 0DE328 7F0A97F8 AFA40850 */  sw    $a0, 0x850($sp)
/* 0DE32C 7F0A97FC AFA00060 */  sw    $zero, 0x60($sp)
/* 0DE330 7F0A9800 AFA0005C */  sw    $zero, 0x5c($sp)
/* 0DE334 7F0A9804 A3A00074 */  sb    $zero, 0x74($sp)
/* 0DE338 7F0A9808 00008025 */  move  $s0, $zero
/* 0DE33C 7F0A980C AFAE0058 */  sw    $t6, 0x58($sp)
/* 0DE340 7F0A9810 18C0000F */  blez  $a2, .L7F0A9850
/* 0DE344 7F0A9814 AFAF0054 */   sw    $t7, 0x54($sp)
/* 0DE348 7F0A9818 3C118004 */  lui   $s1, %hi(D_800409DC)
/* 0DE34C 7F0A981C 263109DC */  addiu $s1, %lo(D_800409DC) # addiu $s1, $s1, 0x9dc
.L7F0A9820:
/* 0DE350 7F0A9820 0FC30776 */  jal   langGet
/* 0DE354 7F0A9824 96240000 */   lhu   $a0, ($s1)
/* 0DE358 7F0A9828 27A40074 */  addiu $a0, $sp, 0x74
/* 0DE35C 7F0A982C 0C0029FF */  jal   strcat
/* 0DE360 7F0A9830 00402825 */   move  $a1, $v0
/* 0DE364 7F0A9834 3C068004 */  lui   $a2, %hi(D_800409D8)
/* 0DE368 7F0A9838 8CC609D8 */  lw    $a2, %lo(D_800409D8)($a2)
/* 0DE36C 7F0A983C 26100001 */  addiu $s0, $s0, 1
/* 0DE370 7F0A9840 26310014 */  addiu $s1, $s1, 0x14
/* 0DE374 7F0A9844 0206082A */  slt   $at, $s0, $a2
/* 0DE378 7F0A9848 1420FFF5 */  bnez  $at, .L7F0A9820
/* 0DE37C 7F0A984C 00000000 */   nop
.L7F0A9850:
/* 0DE380 7F0A9850 3C188004 */  lui   $t8, %hi(watch_item_is_actively_selected)
/* 0DE384 7F0A9854 8F1809A8 */  lw    $t8, %lo(watch_item_is_actively_selected)($t8)
/* 0DE388 7F0A9858 3C198004 */  lui   $t9, %hi(controller_options_index)
/* 0DE38C 7F0A985C 13000019 */  beqz  $t8, .L7F0A98C4
/* 0DE390 7F0A9860 00000000 */   nop
/* 0DE394 7F0A9864 8F390998 */  lw    $t9, %lo(controller_options_index)($t9)
/* 0DE398 7F0A9868 3C118005 */  lui   $s1, %hi(j_text_trigger)
/* 0DE39C 7F0A986C 263184D0 */  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, -0x7b30
/* 0DE3A0 7F0A9870 17200014 */  bnez  $t9, .L7F0A98C4
/* 0DE3A4 7F0A9874 3C038008 */   lui   $v1, %hi(g_CurrentPlayer)
/* 0DE3A8 7F0A9878 8E280000 */  lw    $t0, ($s1)
/* 0DE3AC 7F0A987C 240B0001 */  li    $t3, 1
/* 0DE3B0 7F0A9880 2402000A */  li    $v0, 10
/* 0DE3B4 7F0A9884 11000003 */  beqz  $t0, .L7F0A9894
/* 0DE3B8 7F0A9888 00000000 */   nop
/* 0DE3BC 7F0A988C 10000001 */  b     .L7F0A9894
/* 0DE3C0 7F0A9890 2402000E */   li    $v0, 14
.L7F0A9894:
/* 0DE3C4 7F0A9894 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0DE3C8 7F0A9898 AFA00018 */  sw    $zero, 0x18($sp)
/* 0DE3CC 7F0A989C AFAB001C */  sw    $t3, 0x1c($sp)
/* 0DE3D0 7F0A98A0 24692A5C */  addiu $t1, $v1, 0x2a5c
/* 0DE3D4 7F0A98A4 246A2A68 */  addiu $t2, $v1, 0x2a68
/* 0DE3D8 7F0A98A8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DE3DC 7F0A98AC AFA90010 */  sw    $t1, 0x10($sp)
/* 0DE3E0 7F0A98B0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0DE3E4 7F0A98B4 24642A60 */  addiu $a0, $v1, 0x2a60
/* 0DE3E8 7F0A98B8 24652A58 */  addiu $a1, $v1, 0x2a58
/* 0DE3EC 7F0A98BC 0FC29847 */  jal   sub_GAME_7F0A611C
/* 0DE3F0 7F0A98C0 24672A64 */   addiu $a3, $v1, 0x2a64
.L7F0A98C4:
/* 0DE3F4 7F0A98C4 3C118005 */  lui   $s1, %hi(j_text_trigger)
/* 0DE3F8 7F0A98C8 263184D0 */  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, -0x7b30
/* 0DE3FC 7F0A98CC 8E220000 */  lw    $v0, ($s1)
/* 0DE400 7F0A98D0 240C00AA */  li    $t4, 170
/* 0DE404 7F0A98D4 240D001A */  li    $t5, 26
/* 0DE408 7F0A98D8 AFAC0070 */  sw    $t4, 0x70($sp)
/* 0DE40C 7F0A98DC 10400003 */  beqz  $v0, .L7F0A98EC
/* 0DE410 7F0A98E0 AFAD006C */   sw    $t5, 0x6c($sp)
/* 0DE414 7F0A98E4 10000002 */  b     .L7F0A98F0
/* 0DE418 7F0A98E8 2402000E */   li    $v0, 14
.L7F0A98EC:
/* 0DE41C 7F0A98EC 2402000A */  li    $v0, 10
.L7F0A98F0:
/* 0DE420 7F0A98F0 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DE424 7F0A98F4 27A40060 */  addiu $a0, $sp, 0x60
/* 0DE428 7F0A98F8 27A5005C */  addiu $a1, $sp, 0x5c
/* 0DE42C 7F0A98FC 27A60074 */  addiu $a2, $sp, 0x74
/* 0DE430 7F0A9900 8FA70054 */  lw    $a3, 0x54($sp)
/* 0DE434 7F0A9904 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DE438 7F0A9908 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DE43C 7F0A990C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0DE440 7F0A9910 8E220000 */  lw    $v0, ($s1)
/* 0DE444 7F0A9914 8FA40850 */  lw    $a0, 0x850($sp)
/* 0DE448 7F0A9918 27A50070 */  addiu $a1, $sp, 0x70
/* 0DE44C 7F0A991C 10400003 */  beqz  $v0, .L7F0A992C
/* 0DE450 7F0A9920 27A6006C */   addiu $a2, $sp, 0x6c
/* 0DE454 7F0A9924 10000002 */  b     .L7F0A9930
/* 0DE458 7F0A9928 2410000E */   li    $s0, 14
.L7F0A992C:
/* 0DE45C 7F0A992C 2410000A */  li    $s0, 10
.L7F0A9930:
/* 0DE460 7F0A9930 10400003 */  beqz  $v0, .L7F0A9940
/* 0DE464 7F0A9934 27A70074 */   addiu $a3, $sp, 0x74
/* 0DE468 7F0A9938 10000002 */  b     .L7F0A9944
/* 0DE46C 7F0A993C 2402000E */   li    $v0, 14
.L7F0A9940:
/* 0DE470 7F0A9940 2402000A */  li    $v0, 10
.L7F0A9944:
/* 0DE474 7F0A9944 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0DE478 7F0A9948 8FB80058 */  lw    $t8, 0x58($sp)
/* 0DE47C 7F0A994C 8FA8005C */  lw    $t0, 0x5c($sp)
/* 0DE480 7F0A9950 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0DE484 7F0A9954 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DE488 7F0A9958 3C1900AA */  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
/* 0DE48C 7F0A995C 373900B0 */  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DE490 7F0A9960 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DE494 7F0A9964 AFB00020 */  sw    $s0, 0x20($sp)
/* 0DE498 7F0A9968 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DE49C 7F0A996C AFB80014 */  sw    $t8, 0x14($sp)
/* 0DE4A0 7F0A9970 AFA8001C */  sw    $t0, 0x1c($sp)
/* 0DE4A4 7F0A9974 8D2A2A64 */  lw    $t2, 0x2a64($t1)
/* 0DE4A8 7F0A9978 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DE4AC 7F0A997C 0FC2B6AF */  jal   en_text_write_stuff
/* 0DE4B0 7F0A9980 AFAA0024 */   sw    $t2, 0x24($sp)
/* 0DE4B4 7F0A9984 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0DE4B8 7F0A9988 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0DE4BC 7F0A998C AFA20850 */  sw    $v0, 0x850($sp)
/* 0DE4C0 7F0A9990 8C6B2A68 */  lw    $t3, 0x2a68($v1)
/* 0DE4C4 7F0A9994 51600043 */  beql  $t3, $zero, .L7F0A9AA4
/* 0DE4C8 7F0A9998 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0DE4CC 7F0A999C 8C6C2A58 */  lw    $t4, 0x2a58($v1)
/* 0DE4D0 7F0A99A0 3C048004 */  lui   $a0, %hi(D_800409DC)
/* 0DE4D4 7F0A99A4 000C6880 */  sll   $t5, $t4, 2
/* 0DE4D8 7F0A99A8 01AC6821 */  addu  $t5, $t5, $t4
/* 0DE4DC 7F0A99AC 000D6880 */  sll   $t5, $t5, 2
/* 0DE4E0 7F0A99B0 008D2021 */  addu  $a0, $a0, $t5
/* 0DE4E4 7F0A99B4 0FC30776 */  jal   langGet
/* 0DE4E8 7F0A99B8 948409DC */   lhu   $a0, %lo(D_800409DC)($a0)
/* 0DE4EC 7F0A99BC 8E2E0000 */  lw    $t6, ($s1)
/* 0DE4F0 7F0A99C0 00408025 */  move  $s0, $v0
/* 0DE4F4 7F0A99C4 27A40060 */  addiu $a0, $sp, 0x60
/* 0DE4F8 7F0A99C8 11C00003 */  beqz  $t6, .L7F0A99D8
/* 0DE4FC 7F0A99CC 27A5005C */   addiu $a1, $sp, 0x5c
/* 0DE500 7F0A99D0 10000002 */  b     .L7F0A99DC
/* 0DE504 7F0A99D4 2402000E */   li    $v0, 14
.L7F0A99D8:
/* 0DE508 7F0A99D8 2402000A */  li    $v0, 10
.L7F0A99DC:
/* 0DE50C 7F0A99DC 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0DE510 7F0A99E0 02003025 */  move  $a2, $s0
/* 0DE514 7F0A99E4 8FA70054 */  lw    $a3, 0x54($sp)
/* 0DE518 7F0A99E8 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DE51C 7F0A99EC 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0DE520 7F0A99F0 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0DE524 7F0A99F4 8E390000 */  lw    $t9, ($s1)
/* 0DE528 7F0A99F8 241800AA */  li    $t8, 170
/* 0DE52C 7F0A99FC AFB80070 */  sw    $t8, 0x70($sp)
/* 0DE530 7F0A9A00 13200003 */  beqz  $t9, .L7F0A9A10
/* 0DE534 7F0A9A04 3C098008 */   lui   $t1, %hi(g_CurrentPlayer)
/* 0DE538 7F0A9A08 10000001 */  b     .L7F0A9A10
/* 0DE53C 7F0A9A0C 00000000 */   nop
.L7F0A9A10:
/* 0DE540 7F0A9A10 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DE544 7F0A9A14 2408001A */  li    $t0, 26
/* 0DE548 7F0A9A18 AFA8006C */  sw    $t0, 0x6c($sp)
/* 0DE54C 7F0A9A1C 8D2A2A58 */  lw    $t2, 0x2a58($t1)
/* 0DE550 7F0A9A20 3C048004 */  lui   $a0, %hi(D_800409DC)
/* 0DE554 7F0A9A24 000A5880 */  sll   $t3, $t2, 2
/* 0DE558 7F0A9A28 016A5821 */  addu  $t3, $t3, $t2
/* 0DE55C 7F0A9A2C 000B5880 */  sll   $t3, $t3, 2
/* 0DE560 7F0A9A30 008B2021 */  addu  $a0, $a0, $t3
/* 0DE564 7F0A9A34 0FC30776 */  jal   langGet
/* 0DE568 7F0A9A38 948409DC */   lhu   $a0, %lo(D_800409DC)($a0)
/* 0DE56C 7F0A9A3C 8E2C0000 */  lw    $t4, ($s1)
/* 0DE570 7F0A9A40 00408025 */  move  $s0, $v0
/* 0DE574 7F0A9A44 8FA40850 */  lw    $a0, 0x850($sp)
/* 0DE578 7F0A9A48 11800003 */  beqz  $t4, .L7F0A9A58
/* 0DE57C 7F0A9A4C 27A50070 */   addiu $a1, $sp, 0x70
/* 0DE580 7F0A9A50 10000002 */  b     .L7F0A9A5C
/* 0DE584 7F0A9A54 2402000E */   li    $v0, 14
.L7F0A9A58:
/* 0DE588 7F0A9A58 2402000A */  li    $v0, 10
.L7F0A9A5C:
/* 0DE58C 7F0A9A5C 8FAD0054 */  lw    $t5, 0x54($sp)
/* 0DE590 7F0A9A60 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DE594 7F0A9A64 8FB8005C */  lw    $t8, 0x5c($sp)
/* 0DE598 7F0A9A68 3C0FA0FF */  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
/* 0DE59C 7F0A9A6C 35EFA0F0 */  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
/* 0DE5A0 7F0A9A70 24190064 */  li    $t9, 100
/* 0DE5A4 7F0A9A74 AFB90020 */  sw    $t9, 0x20($sp)
/* 0DE5A8 7F0A9A78 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DE5AC 7F0A9A7C 27A6006C */  addiu $a2, $sp, 0x6c
/* 0DE5B0 7F0A9A80 02003825 */  move  $a3, $s0
/* 0DE5B4 7F0A9A84 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE5B8 7F0A9A88 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DE5BC 7F0A9A8C AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DE5C0 7F0A9A90 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DE5C4 7F0A9A94 0FC2B6AF */  jal   en_text_write_stuff
/* 0DE5C8 7F0A9A98 AFB8001C */   sw    $t8, 0x1c($sp)
/* 0DE5CC 7F0A9A9C AFA20850 */  sw    $v0, 0x850($sp)
/* 0DE5D0 7F0A9AA0 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0A9AA4:
/* 0DE5D4 7F0A9AA4 8FA20850 */  lw    $v0, 0x850($sp)
/* 0DE5D8 7F0A9AA8 8FB00034 */  lw    $s0, 0x34($sp)
/* 0DE5DC 7F0A9AAC 8FB10038 */  lw    $s1, 0x38($sp)
/* 0DE5E0 7F0A9AB0 03E00008 */  jr    $ra
/* 0DE5E4 7F0A9AB4 27BD0850 */   addiu $sp, $sp, 0x850
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A97D0
/* 0DB500 7F0A8B10 27BDF7B0 */  addiu $sp, $sp, -0x850
/* 0DB504 7F0A8B14 3C068004 */  lui   $a2, %hi(D_800409D8) # $a2, 0x8004
/* 0DB508 7F0A8B18 8CC6A628 */  lw    $a2, %lo(D_800409D8)($a2)
/* 0DB50C 7F0A8B1C 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
/* 0DB510 7F0A8B20 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0DB514 7F0A8B24 8DCEAAFC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0DB518 7F0A8B28 8DEFAB00 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0DB51C 7F0A8B2C AFB00034 */  sw    $s0, 0x34($sp)
/* 0DB520 7F0A8B30 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DB524 7F0A8B34 AFB10038 */  sw    $s1, 0x38($sp)
/* 0DB528 7F0A8B38 AFA40850 */  sw    $a0, 0x850($sp)
/* 0DB52C 7F0A8B3C AFA00060 */  sw    $zero, 0x60($sp)
/* 0DB530 7F0A8B40 AFA0005C */  sw    $zero, 0x5c($sp)
/* 0DB534 7F0A8B44 A3A00074 */  sb    $zero, 0x74($sp)
/* 0DB538 7F0A8B48 00008025 */  move  $s0, $zero
/* 0DB53C 7F0A8B4C AFAE0058 */  sw    $t6, 0x58($sp)
/* 0DB540 7F0A8B50 18C0000F */  blez  $a2, .L7F0A8B90
/* 0DB544 7F0A8B54 AFAF0054 */   sw    $t7, 0x54($sp)
/* 0DB548 7F0A8B58 3C118004 */  lui   $s1, %hi(D_800409DC) # $s1, 0x8004
/* 0DB54C 7F0A8B5C 2631A62C */  addiu $s1, %lo(D_800409DC) # addiu $s1, $s1, -0x59d4
.L7F0A8B60:
/* 0DB550 7F0A8B60 0FC304AE */  jal   langGet
/* 0DB554 7F0A8B64 96240000 */   lhu   $a0, ($s1)
/* 0DB558 7F0A8B68 27A40074 */  addiu $a0, $sp, 0x74
/* 0DB55C 7F0A8B6C 0C002717 */  jal   strcat
/* 0DB560 7F0A8B70 00402825 */   move  $a1, $v0
/* 0DB564 7F0A8B74 3C068004 */  lui   $a2, %hi(D_800409D8) # $a2, 0x8004
/* 0DB568 7F0A8B78 8CC6A628 */  lw    $a2, %lo(D_800409D8)($a2)
/* 0DB56C 7F0A8B7C 26100001 */  addiu $s0, $s0, 1
/* 0DB570 7F0A8B80 26310014 */  addiu $s1, $s1, 0x14
/* 0DB574 7F0A8B84 0206082A */  slt   $at, $s0, $a2
/* 0DB578 7F0A8B88 1420FFF5 */  bnez  $at, .L7F0A8B60
/* 0DB57C 7F0A8B8C 00000000 */   nop   
.L7F0A8B90:
/* 0DB580 7F0A8B90 3C188004 */  lui   $t8, %hi(watch_item_is_actively_selected) # $t8, 0x8004
/* 0DB584 7F0A8B94 8F18A5F8 */  lw    $t8, %lo(watch_item_is_actively_selected)($t8)
/* 0DB588 7F0A8B98 3C198004 */  lui   $t9, %hi(controller_options_index) # $t9, 0x8004
/* 0DB58C 7F0A8B9C 13000019 */  beqz  $t8, .L7F0A8C04
/* 0DB590 7F0A8BA0 00000000 */   nop   
/* 0DB594 7F0A8BA4 8F39A5E8 */  lw    $t9, %lo(controller_options_index)($t9)
/* 0DB598 7F0A8BA8 3C118004 */  lui   $s1, %hi(j_text_trigger) # $s1, 0x8004
/* 0DB59C 7F0A8BAC 26311150 */  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, 0x1150
/* 0DB5A0 7F0A8BB0 17200014 */  bnez  $t9, .L7F0A8C04
/* 0DB5A4 7F0A8BB4 3C038007 */   lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0DB5A8 7F0A8BB8 8E280000 */  lw    $t0, ($s1)
/* 0DB5AC 7F0A8BBC 240B0001 */  li    $t3, 1
/* 0DB5B0 7F0A8BC0 2402000A */  li    $v0, 10
/* 0DB5B4 7F0A8BC4 11000003 */  beqz  $t0, .L7F0A8BD4
/* 0DB5B8 7F0A8BC8 00000000 */   nop   
/* 0DB5BC 7F0A8BCC 10000001 */  b     .L7F0A8BD4
/* 0DB5C0 7F0A8BD0 2402000E */   li    $v0, 14
.L7F0A8BD4:
/* 0DB5C4 7F0A8BD4 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0DB5C8 7F0A8BD8 AFA00018 */  sw    $zero, 0x18($sp)
/* 0DB5CC 7F0A8BDC AFAB001C */  sw    $t3, 0x1c($sp)
/* 0DB5D0 7F0A8BE0 24692A54 */  addiu $t1, $v1, 0x2a54
/* 0DB5D4 7F0A8BE4 246A2A60 */  addiu $t2, $v1, 0x2a60
/* 0DB5D8 7F0A8BE8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DB5DC 7F0A8BEC AFA90010 */  sw    $t1, 0x10($sp)
/* 0DB5E0 7F0A8BF0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0DB5E4 7F0A8BF4 24642A58 */  addiu $a0, $v1, 0x2a58
/* 0DB5E8 7F0A8BF8 24652A50 */  addiu $a1, $v1, 0x2a50
/* 0DB5EC 7F0A8BFC 0FC2950F */  jal   sub_GAME_7F0A611C
/* 0DB5F0 7F0A8C00 24672A5C */   addiu $a3, $v1, 0x2a5c
.L7F0A8C04:
/* 0DB5F4 7F0A8C04 3C118004 */  lui   $s1, %hi(j_text_trigger) # $s1, 0x8004
/* 0DB5F8 7F0A8C08 26311150 */  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, 0x1150
/* 0DB5FC 7F0A8C0C 8E220000 */  lw    $v0, ($s1)
/* 0DB600 7F0A8C10 240C00AA */  li    $t4, 170
/* 0DB604 7F0A8C14 240D001A */  li    $t5, 26
/* 0DB608 7F0A8C18 AFAC0070 */  sw    $t4, 0x70($sp)
/* 0DB60C 7F0A8C1C 10400003 */  beqz  $v0, .L7F0A8C2C
/* 0DB610 7F0A8C20 AFAD006C */   sw    $t5, 0x6c($sp)
/* 0DB614 7F0A8C24 10000002 */  b     .L7F0A8C30
/* 0DB618 7F0A8C28 2402000E */   li    $v0, 14
.L7F0A8C2C:
/* 0DB61C 7F0A8C2C 2402000A */  li    $v0, 10
.L7F0A8C30:
/* 0DB620 7F0A8C30 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DB624 7F0A8C34 27A40060 */  addiu $a0, $sp, 0x60
/* 0DB628 7F0A8C38 27A5005C */  addiu $a1, $sp, 0x5c
/* 0DB62C 7F0A8C3C 27A60074 */  addiu $a2, $sp, 0x74
/* 0DB630 7F0A8C40 8FA70054 */  lw    $a3, 0x54($sp)
/* 0DB634 7F0A8C44 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DB638 7F0A8C48 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DB63C 7F0A8C4C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0DB640 7F0A8C50 8E220000 */  lw    $v0, ($s1)
/* 0DB644 7F0A8C54 8FA40850 */  lw    $a0, 0x850($sp)
/* 0DB648 7F0A8C58 27A50070 */  addiu $a1, $sp, 0x70
/* 0DB64C 7F0A8C5C 10400003 */  beqz  $v0, .L7F0A8C6C
/* 0DB650 7F0A8C60 27A6006C */   addiu $a2, $sp, 0x6c
/* 0DB654 7F0A8C64 10000002 */  b     .L7F0A8C70
/* 0DB658 7F0A8C68 2410000E */   li    $s0, 14
.L7F0A8C6C:
/* 0DB65C 7F0A8C6C 2410000A */  li    $s0, 10
.L7F0A8C70:
/* 0DB660 7F0A8C70 10400003 */  beqz  $v0, .L7F0A8C80
/* 0DB664 7F0A8C74 27A70074 */   addiu $a3, $sp, 0x74
/* 0DB668 7F0A8C78 10000002 */  b     .L7F0A8C84
/* 0DB66C 7F0A8C7C 2402000E */   li    $v0, 14
.L7F0A8C80:
/* 0DB670 7F0A8C80 2402000A */  li    $v0, 10
.L7F0A8C84:
/* 0DB674 7F0A8C84 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0DB678 7F0A8C88 8FB80058 */  lw    $t8, 0x58($sp)
/* 0DB67C 7F0A8C8C 8FA8005C */  lw    $t0, 0x5c($sp)
/* 0DB680 7F0A8C90 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0DB684 7F0A8C94 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DB688 7F0A8C98 3C1900AA */  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
/* 0DB68C 7F0A8C9C 373900B0 */  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DB690 7F0A8CA0 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DB694 7F0A8CA4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0DB698 7F0A8CA8 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DB69C 7F0A8CAC AFB80014 */  sw    $t8, 0x14($sp)
/* 0DB6A0 7F0A8CB0 AFA8001C */  sw    $t0, 0x1c($sp)
/* 0DB6A4 7F0A8CB4 8D2A2A5C */  lw    $t2, 0x2a5c($t1)
/* 0DB6A8 7F0A8CB8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DB6AC 7F0A8CBC 0FC2B35F */  jal   en_text_write_stuff
/* 0DB6B0 7F0A8CC0 AFAA0024 */   sw    $t2, 0x24($sp)
/* 0DB6B4 7F0A8CC4 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0DB6B8 7F0A8CC8 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0DB6BC 7F0A8CCC AFA20850 */  sw    $v0, 0x850($sp)
/* 0DB6C0 7F0A8CD0 8C6B2A60 */  lw    $t3, 0x2a60($v1)
/* 0DB6C4 7F0A8CD4 51600043 */  beql  $t3, $zero, .L7F0A8DE4
/* 0DB6C8 7F0A8CD8 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0DB6CC 7F0A8CDC 8C6C2A50 */  lw    $t4, 0x2a50($v1)
/* 0DB6D0 7F0A8CE0 3C048004 */  lui   $a0, %hi(D_800409DC)
/* 0DB6D4 7F0A8CE4 000C6880 */  sll   $t5, $t4, 2
/* 0DB6D8 7F0A8CE8 01AC6821 */  addu  $t5, $t5, $t4
/* 0DB6DC 7F0A8CEC 000D6880 */  sll   $t5, $t5, 2
/* 0DB6E0 7F0A8CF0 008D2021 */  addu  $a0, $a0, $t5
/* 0DB6E4 7F0A8CF4 0FC304AE */  jal   langGet
/* 0DB6E8 7F0A8CF8 9484A62C */   lhu   $a0, %lo(D_800409DC)($a0)
/* 0DB6EC 7F0A8CFC 8E2E0000 */  lw    $t6, ($s1)
/* 0DB6F0 7F0A8D00 00408025 */  move  $s0, $v0
/* 0DB6F4 7F0A8D04 27A40060 */  addiu $a0, $sp, 0x60
/* 0DB6F8 7F0A8D08 11C00003 */  beqz  $t6, .L7F0A8D18
/* 0DB6FC 7F0A8D0C 27A5005C */   addiu $a1, $sp, 0x5c
/* 0DB700 7F0A8D10 10000002 */  b     .L7F0A8D1C
/* 0DB704 7F0A8D14 2402000E */   li    $v0, 14
.L7F0A8D18:
/* 0DB708 7F0A8D18 2402000A */  li    $v0, 10
.L7F0A8D1C:
/* 0DB70C 7F0A8D1C 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0DB710 7F0A8D20 02003025 */  move  $a2, $s0
/* 0DB714 7F0A8D24 8FA70054 */  lw    $a3, 0x54($sp)
/* 0DB718 7F0A8D28 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DB71C 7F0A8D2C 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DB720 7F0A8D30 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0DB724 7F0A8D34 8E390000 */  lw    $t9, ($s1)
/* 0DB728 7F0A8D38 241800AA */  li    $t8, 170
/* 0DB72C 7F0A8D3C AFB80070 */  sw    $t8, 0x70($sp)
/* 0DB730 7F0A8D40 13200003 */  beqz  $t9, .L7F0A8D50
/* 0DB734 7F0A8D44 3C098007 */   lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0DB738 7F0A8D48 10000001 */  b     .L7F0A8D50
/* 0DB73C 7F0A8D4C 00000000 */   nop   
.L7F0A8D50:
/* 0DB740 7F0A8D50 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DB744 7F0A8D54 2408001A */  li    $t0, 26
/* 0DB748 7F0A8D58 AFA8006C */  sw    $t0, 0x6c($sp)
/* 0DB74C 7F0A8D5C 8D2A2A50 */  lw    $t2, 0x2a50($t1)
/* 0DB750 7F0A8D60 3C048004 */  lui   $a0, %hi(D_800409DC)
/* 0DB754 7F0A8D64 000A5880 */  sll   $t3, $t2, 2
/* 0DB758 7F0A8D68 016A5821 */  addu  $t3, $t3, $t2
/* 0DB75C 7F0A8D6C 000B5880 */  sll   $t3, $t3, 2
/* 0DB760 7F0A8D70 008B2021 */  addu  $a0, $a0, $t3
/* 0DB764 7F0A8D74 0FC304AE */  jal   langGet
/* 0DB768 7F0A8D78 9484A62C */   lhu   $a0, %lo(D_800409DC)($a0)
/* 0DB76C 7F0A8D7C 8E2C0000 */  lw    $t4, ($s1)
/* 0DB770 7F0A8D80 00408025 */  move  $s0, $v0
/* 0DB774 7F0A8D84 8FA40850 */  lw    $a0, 0x850($sp)
/* 0DB778 7F0A8D88 11800003 */  beqz  $t4, .L7F0A8D98
/* 0DB77C 7F0A8D8C 27A50070 */   addiu $a1, $sp, 0x70
/* 0DB780 7F0A8D90 10000002 */  b     .L7F0A8D9C
/* 0DB784 7F0A8D94 2402000E */   li    $v0, 14
.L7F0A8D98:
/* 0DB788 7F0A8D98 2402000A */  li    $v0, 10
.L7F0A8D9C:
/* 0DB78C 7F0A8D9C 8FAD0054 */  lw    $t5, 0x54($sp)
/* 0DB790 7F0A8DA0 8FAE0058 */  lw    $t6, 0x58($sp)
/* 0DB794 7F0A8DA4 8FB8005C */  lw    $t8, 0x5c($sp)
/* 0DB798 7F0A8DA8 3C0FA0FF */  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
/* 0DB79C 7F0A8DAC 35EFA0F0 */  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
/* 0DB7A0 7F0A8DB0 24190064 */  li    $t9, 100
/* 0DB7A4 7F0A8DB4 AFB90020 */  sw    $t9, 0x20($sp)
/* 0DB7A8 7F0A8DB8 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DB7AC 7F0A8DBC 27A6006C */  addiu $a2, $sp, 0x6c
/* 0DB7B0 7F0A8DC0 02003825 */  move  $a3, $s0
/* 0DB7B4 7F0A8DC4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DB7B8 7F0A8DC8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0DB7BC 7F0A8DCC AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DB7C0 7F0A8DD0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DB7C4 7F0A8DD4 0FC2B35F */  jal   en_text_write_stuff
/* 0DB7C8 7F0A8DD8 AFB8001C */   sw    $t8, 0x1c($sp)
/* 0DB7CC 7F0A8DDC AFA20850 */  sw    $v0, 0x850($sp)
/* 0DB7D0 7F0A8DE0 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0A8DE4:
/* 0DB7D4 7F0A8DE4 8FA20850 */  lw    $v0, 0x850($sp)
/* 0DB7D8 7F0A8DE8 8FB00034 */  lw    $s0, 0x34($sp)
/* 0DB7DC 7F0A8DEC 8FB10038 */  lw    $s1, 0x38($sp)
/* 0DB7E0 7F0A8DF0 03E00008 */  jr    $ra
/* 0DB7E4 7F0A8DF4 27BD0850 */   addiu $sp, $sp, 0x850
)
#endif
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A9AB8(void) {

}
#else
//D:80057778
const char aA[] =  "(A)\n";
//D:80057780
const char aB[] =  "(B)\n";
//D:80057788
const char aZ[] =  "(Z)\n";
//D:80057790
const char aL[] =  "(L)\n";
//D:80057798
const char aR[] =  "(R)\n";
//D:800577A0
const char aC[] =  "(C)\n";
//D:800577A8
const char D_800577A8[] =  "(+)\n";
//D:800577B0
const char aS_0[] =  "(S)\n";
//D:800577B8
const char a3d[] =  "(3D)\n";

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
    
.text
glabel sub_GAME_7F0A9AB8
/* 0DE5E8 7F0A9AB8 3C0E8004 */  lui   $t6, %hi(game_options_entries)
/* 0DE5EC 7F0A9ABC 8DCE0A84 */  lw    $t6, %lo(game_options_entries + 0x8)($t6)
/* 0DE5F0 7F0A9AC0 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 0DE5F4 7F0A9AC4 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DE5F8 7F0A9AC8 24010001 */  li    $at, 1
/* 0DE5FC 7F0A9ACC 00808025 */  move  $s0, $a0
/* 0DE600 7F0A9AD0 15C10008 */  bne   $t6, $at, .L7F0A9AF4
/* 0DE604 7F0A9AD4 AFBF003C */   sw    $ra, 0x3c($sp)
/* 0DE608 7F0A9AD8 0FC30776 */  jal   langGet
/* 0DE60C 7F0A9ADC 3404AC2D */   li    $a0, 44077
/* 0DE610 7F0A9AE0 AFA200AC */  sw    $v0, 0xac($sp)
/* 0DE614 7F0A9AE4 0FC30776 */  jal   langGet
/* 0DE618 7F0A9AE8 3404AC2C */   li    $a0, 44076
/* 0DE61C 7F0A9AEC 10000007 */  b     .L7F0A9B0C
/* 0DE620 7F0A9AF0 AFA200A8 */   sw    $v0, 0xa8($sp)
.L7F0A9AF4:
/* 0DE624 7F0A9AF4 0FC30776 */  jal   langGet
/* 0DE628 7F0A9AF8 3404AC2C */   li    $a0, 44076
/* 0DE62C 7F0A9AFC AFA200AC */  sw    $v0, 0xac($sp)
/* 0DE630 7F0A9B00 0FC30776 */  jal   langGet
/* 0DE634 7F0A9B04 3404AC2D */   li    $a0, 44077
/* 0DE638 7F0A9B08 AFA200A8 */  sw    $v0, 0xa8($sp)
.L7F0A9B0C:
/* 0DE63C 7F0A9B0C 3C188005 */  lui   $t8, %hi(aA)
/* 0DE640 7F0A9B10 27187778 */  addiu $t8, %lo(aA) # addiu $t8, $t8, 0x7778
/* 0DE644 7F0A9B14 8F010000 */  lw    $at, ($t8)
/* 0DE648 7F0A9B18 27AF00A0 */  addiu $t7, $sp, 0xa0
/* 0DE64C 7F0A9B1C 3C0B8005 */  lui   $t3, %hi(aB)
/* 0DE650 7F0A9B20 ADE10000 */  sw    $at, ($t7)
/* 0DE654 7F0A9B24 93010004 */  lbu   $at, 4($t8)
/* 0DE658 7F0A9B28 256B7780 */  addiu $t3, %lo(aB) # addiu $t3, $t3, 0x7780
/* 0DE65C 7F0A9B2C 27AA0098 */  addiu $t2, $sp, 0x98
/* 0DE660 7F0A9B30 A1E10004 */  sb    $at, 4($t7)
/* 0DE664 7F0A9B34 8D610000 */  lw    $at, ($t3)
/* 0DE668 7F0A9B38 3C198005 */  lui   $t9, %hi(aZ)
/* 0DE66C 7F0A9B3C 27397788 */  addiu $t9, %lo(aZ) # addiu $t9, $t9, 0x7788
/* 0DE670 7F0A9B40 AD410000 */  sw    $at, ($t2)
/* 0DE674 7F0A9B44 91610004 */  lbu   $at, 4($t3)
/* 0DE678 7F0A9B48 27A80090 */  addiu $t0, $sp, 0x90
/* 0DE67C 7F0A9B4C 3C0C8005 */  lui   $t4, %hi(aL)
/* 0DE680 7F0A9B50 A1410004 */  sb    $at, 4($t2)
/* 0DE684 7F0A9B54 8F210000 */  lw    $at, ($t9)
/* 0DE688 7F0A9B58 258C7790 */  addiu $t4, %lo(aL) # addiu $t4, $t4, 0x7790
/* 0DE68C 7F0A9B5C 27AD0088 */  addiu $t5, $sp, 0x88
/* 0DE690 7F0A9B60 AD010000 */  sw    $at, ($t0)
/* 0DE694 7F0A9B64 93210004 */  lbu   $at, 4($t9)
/* 0DE698 7F0A9B68 3C0F8005 */  lui   $t7, %hi(aR)
/* 0DE69C 7F0A9B6C 25EF7798 */  addiu $t7, %lo(aR) # addiu $t7, $t7, 0x7798
/* 0DE6A0 7F0A9B70 A1010004 */  sb    $at, 4($t0)
/* 0DE6A4 7F0A9B74 8D810000 */  lw    $at, ($t4)
/* 0DE6A8 7F0A9B78 27B80080 */  addiu $t8, $sp, 0x80
/* 0DE6AC 7F0A9B7C 3C0A8005 */  lui   $t2, %hi(aC)
/* 0DE6B0 7F0A9B80 ADA10000 */  sw    $at, ($t5)
/* 0DE6B4 7F0A9B84 91810004 */  lbu   $at, 4($t4)
/* 0DE6B8 7F0A9B88 254A77A0 */  addiu $t2, %lo(aC) # addiu $t2, $t2, 0x77a0
/* 0DE6BC 7F0A9B8C 27AB0078 */  addiu $t3, $sp, 0x78
/* 0DE6C0 7F0A9B90 A1A10004 */  sb    $at, 4($t5)
/* 0DE6C4 7F0A9B94 8DE10000 */  lw    $at, ($t7)
/* 0DE6C8 7F0A9B98 3C088005 */  lui   $t0, %hi(D_800577A8)
/* 0DE6CC 7F0A9B9C 250877A8 */  addiu $t0, %lo(D_800577A8) # addiu $t0, $t0, 0x77a8
/* 0DE6D0 7F0A9BA0 AF010000 */  sw    $at, ($t8)
/* 0DE6D4 7F0A9BA4 91E10004 */  lbu   $at, 4($t7)
/* 0DE6D8 7F0A9BA8 27B90070 */  addiu $t9, $sp, 0x70
/* 0DE6DC 7F0A9BAC 3C0D8005 */  lui   $t5, %hi(aS_0)
/* 0DE6E0 7F0A9BB0 A3010004 */  sb    $at, 4($t8)
/* 0DE6E4 7F0A9BB4 8D410000 */  lw    $at, ($t2)
/* 0DE6E8 7F0A9BB8 25AD77B0 */  addiu $t5, %lo(aS_0) # addiu $t5, $t5, 0x77b0
/* 0DE6EC 7F0A9BBC 27AC0068 */  addiu $t4, $sp, 0x68
/* 0DE6F0 7F0A9BC0 AD610000 */  sw    $at, ($t3)
/* 0DE6F4 7F0A9BC4 91410004 */  lbu   $at, 4($t2)
/* 0DE6F8 7F0A9BC8 3C188005 */  lui   $t8, %hi(a3d)
/* 0DE6FC 7F0A9BCC 271877B8 */  addiu $t8, %lo(a3d) # addiu $t8, $t8, 0x77b8
/* 0DE700 7F0A9BD0 A1610004 */  sb    $at, 4($t3)
/* 0DE704 7F0A9BD4 8D010000 */  lw    $at, ($t0)
/* 0DE708 7F0A9BD8 27AF0060 */  addiu $t7, $sp, 0x60
/* 0DE70C 7F0A9BDC 02002025 */  move  $a0, $s0
/* 0DE710 7F0A9BE0 AF210000 */  sw    $at, ($t9)
/* 0DE714 7F0A9BE4 91010004 */  lbu   $at, 4($t0)
/* 0DE718 7F0A9BE8 A3210004 */  sb    $at, 4($t9)
/* 0DE71C 7F0A9BEC 8DA10000 */  lw    $at, ($t5)
/* 0DE720 7F0A9BF0 AD810000 */  sw    $at, ($t4)
/* 0DE724 7F0A9BF4 91A10004 */  lbu   $at, 4($t5)
/* 0DE728 7F0A9BF8 A1810004 */  sb    $at, 4($t4)
/* 0DE72C 7F0A9BFC 8F010000 */  lw    $at, ($t8)
/* 0DE730 7F0A9C00 ADE10000 */  sw    $at, ($t7)
/* 0DE734 7F0A9C04 97010004 */  lhu   $at, 4($t8)
/* 0DE738 7F0A9C08 A5E10004 */  sh    $at, 4($t7)
/* 0DE73C 7F0A9C0C 0FC2B366 */  jal   microcode_constructor
/* 0DE740 7F0A9C10 AFA00050 */   sw    $zero, 0x50($sp)
/* 0DE744 7F0A9C14 00408025 */  move  $s0, $v0
/* 0DE748 7F0A9C18 00002025 */  move  $a0, $zero
/* 0DE74C 7F0A9C1C 0C0030C3 */  jal   joyGetButtons
/* 0DE750 7F0A9C20 24050020 */   li    $a1, 32
/* 0DE754 7F0A9C24 1040002C */  beqz  $v0, .L7F0A9CD8
/* 0DE758 7F0A9C28 3C0A8008 */   lui   $t2, %hi(g_CurrentPlayer)
/* 0DE75C 7F0A9C2C 8D4AA0B0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0DE760 7F0A9C30 3C048004 */  lui   $a0, %hi(D_800409DC+8)
/* 0DE764 7F0A9C34 8D4B2A58 */  lw    $t3, 0x2a58($t2)
/* 0DE768 7F0A9C38 000B6080 */  sll   $t4, $t3, 2
/* 0DE76C 7F0A9C3C 018B6021 */  addu  $t4, $t4, $t3
/* 0DE770 7F0A9C40 000C6080 */  sll   $t4, $t4, 2
/* 0DE774 7F0A9C44 008C2021 */  addu  $a0, $a0, $t4
/* 0DE778 7F0A9C48 0FC30776 */  jal   langGet
/* 0DE77C 7F0A9C4C 948409E4 */   lhu   $a0, %lo(D_800409DC+8)($a0)
/* 0DE780 7F0A9C50 3C080070 */  lui   $t0, (0x007000A0 >> 16) # lui $t0, 0x70
/* 0DE784 7F0A9C54 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DE788 7F0A9C58 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DE78C 7F0A9C5C 350800A0 */  ori   $t0, (0x007000A0 & 0xFFFF) # ori $t0, $t0, 0xa0
/* 0DE790 7F0A9C60 240DFFFF */  li    $t5, -1
/* 0DE794 7F0A9C64 240E0001 */  li    $t6, 1
/* 0DE798 7F0A9C68 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DE79C 7F0A9C6C AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DE7A0 7F0A9C70 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DE7A4 7F0A9C74 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DE7A8 7F0A9C78 02002025 */  move  $a0, $s0
/* 0DE7AC 7F0A9C7C 24050032 */  li    $a1, 50
/* 0DE7B0 7F0A9C80 24060052 */  li    $a2, 82
/* 0DE7B4 7F0A9C84 00403825 */  move  $a3, $v0
/* 0DE7B8 7F0A9C88 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DE7BC 7F0A9C8C AFA00020 */  sw    $zero, 0x20($sp)
/* 0DE7C0 7F0A9C90 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DE7C4 7F0A9C94 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DE7C8 7F0A9C98 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0DE7CC 7F0A9C9C 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DE7D0 7F0A9CA0 3C0A8004 */  lui   $t2, %hi(D_800409DC+9)
/* 0DE7D4 7F0A9CA4 3401AC01 */  li    $at, 44033
/* 0DE7D8 7F0A9CA8 8DF82A58 */  lw    $t8, 0x2a58($t7)
/* 0DE7DC 7F0A9CAC 00408025 */  move  $s0, $v0
/* 0DE7E0 7F0A9CB0 240B0001 */  li    $t3, 1
/* 0DE7E4 7F0A9CB4 00184880 */  sll   $t1, $t8, 2
/* 0DE7E8 7F0A9CB8 01384821 */  addu  $t1, $t1, $t8
/* 0DE7EC 7F0A9CBC 00094880 */  sll   $t1, $t1, 2
/* 0DE7F0 7F0A9CC0 01495021 */  addu  $t2, $t2, $t1
/* 0DE7F4 7F0A9CC4 954A09E4 */  lhu   $t2, %lo(D_800409DC+8)($t2)
/* 0DE7F8 7F0A9CC8 1541001F */  bne   $t2, $at, .L7F0A9D48
/* 0DE7FC 7F0A9CCC 00000000 */   nop
/* 0DE800 7F0A9CD0 1000001D */  b     .L7F0A9D48
/* 0DE804 7F0A9CD4 AFAB0050 */   sw    $t3, 0x50($sp)
.L7F0A9CD8:
/* 0DE808 7F0A9CD8 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer)
/* 0DE80C 7F0A9CDC 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DE810 7F0A9CE0 3C048004 */  lui   $a0, %hi(D_800409DC+8)
/* 0DE814 7F0A9CE4 8D8D2A58 */  lw    $t5, 0x2a58($t4)
/* 0DE818 7F0A9CE8 000D7080 */  sll   $t6, $t5, 2
/* 0DE81C 7F0A9CEC 01CD7021 */  addu  $t6, $t6, $t5
/* 0DE820 7F0A9CF0 000E7080 */  sll   $t6, $t6, 2
/* 0DE824 7F0A9CF4 008E2021 */  addu  $a0, $a0, $t6
/* 0DE828 7F0A9CF8 0FC30776 */  jal   langGet
/* 0DE82C 7F0A9CFC 948409E4 */   lhu   $a0, %lo(D_800409DC+8)($a0)
/* 0DE830 7F0A9D00 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DE834 7F0A9D04 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DE838 7F0A9D08 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DE83C 7F0A9D0C 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DE840 7F0A9D10 2419FFFF */  li    $t9, -1
/* 0DE844 7F0A9D14 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DE848 7F0A9D18 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DE84C 7F0A9D1C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DE850 7F0A9D20 02002025 */  move  $a0, $s0
/* 0DE854 7F0A9D24 24050032 */  li    $a1, 50
/* 0DE858 7F0A9D28 24060052 */  li    $a2, 82
/* 0DE85C 7F0A9D2C 00403825 */  move  $a3, $v0
/* 0DE860 7F0A9D30 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DE864 7F0A9D34 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DE868 7F0A9D38 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DE86C 7F0A9D3C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DE870 7F0A9D40 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DE874 7F0A9D44 00408025 */  move  $s0, $v0
.L7F0A9D48:
/* 0DE878 7F0A9D48 3C098004 */  lui   $t1, %hi(controller_options_index)
/* 0DE87C 7F0A9D4C 8D290998 */  lw    $t1, %lo(controller_options_index)($t1)
/* 0DE880 7F0A9D50 2418006B */  li    $t8, 107
/* 0DE884 7F0A9D54 24010001 */  li    $at, 1
/* 0DE888 7F0A9D58 1521000A */  bne   $t1, $at, .L7F0A9D84
/* 0DE88C 7F0A9D5C AFB8004C */   sw    $t8, 0x4c($sp)
/* 0DE890 7F0A9D60 3C0A8004 */  lui   $t2, %hi(watch_item_is_actively_selected)
/* 0DE894 7F0A9D64 8D4A09A8 */  lw    $t2, %lo(watch_item_is_actively_selected)($t2)
/* 0DE898 7F0A9D68 00002025 */  move  $a0, $zero
/* 0DE89C 7F0A9D6C 11400005 */  beqz  $t2, .L7F0A9D84
/* 0DE8A0 7F0A9D70 00000000 */   nop
/* 0DE8A4 7F0A9D74 0C0030C3 */  jal   joyGetButtons
/* 0DE8A8 7F0A9D78 24050F00 */   li    $a1, 3840
/* 0DE8AC 7F0A9D7C 1440001E */  bnez  $v0, .L7F0A9DF8
/* 0DE8B0 7F0A9D80 00002025 */   move  $a0, $zero
.L7F0A9D84:
/* 0DE8B4 7F0A9D84 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0DE8B8 7F0A9D88 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DE8BC 7F0A9D8C 3C048004 */  lui   $a0, %hi(D_800409DC+14)
/* 0DE8C0 7F0A9D90 8D6C2A58 */  lw    $t4, 0x2a58($t3)
/* 0DE8C4 7F0A9D94 000C6880 */  sll   $t5, $t4, 2
/* 0DE8C8 7F0A9D98 01AC6821 */  addu  $t5, $t5, $t4
/* 0DE8CC 7F0A9D9C 000D6880 */  sll   $t5, $t5, 2
/* 0DE8D0 7F0A9DA0 008D2021 */  addu  $a0, $a0, $t5
/* 0DE8D4 7F0A9DA4 0FC30776 */  jal   langGet
/* 0DE8D8 7F0A9DA8 948409EA */   lhu   $a0, %lo(D_800409DC+14)($a0)
/* 0DE8DC 7F0A9DAC 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DE8E0 7F0A9DB0 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DE8E4 7F0A9DB4 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DE8E8 7F0A9DB8 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DE8EC 7F0A9DBC 2408FFFF */  li    $t0, -1
/* 0DE8F0 7F0A9DC0 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DE8F4 7F0A9DC4 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DE8F8 7F0A9DC8 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DE8FC 7F0A9DCC 02002025 */  move  $a0, $s0
/* 0DE900 7F0A9DD0 24050032 */  li    $a1, 50
/* 0DE904 7F0A9DD4 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DE908 7F0A9DD8 00403825 */  move  $a3, $v0
/* 0DE90C 7F0A9DDC AFA00014 */  sw    $zero, 0x14($sp)
/* 0DE910 7F0A9DE0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DE914 7F0A9DE4 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DE918 7F0A9DE8 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DE91C 7F0A9DEC AFA00028 */   sw    $zero, 0x28($sp)
/* 0DE920 7F0A9DF0 10000051 */  b     .L7F0A9F38
/* 0DE924 7F0A9DF4 00408025 */   move  $s0, $v0
.L7F0A9DF8:
/* 0DE928 7F0A9DF8 0C0030C3 */  jal   joyGetButtons
/* 0DE92C 7F0A9DFC 24050800 */   li    $a1, 2048
/* 0DE930 7F0A9E00 10400014 */  beqz  $v0, .L7F0A9E54
/* 0DE934 7F0A9E04 00002025 */   move  $a0, $zero
/* 0DE938 7F0A9E08 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0DE93C 7F0A9E0C 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DE940 7F0A9E10 3C0A8004 */  lui   $t2, %hi(D_800409DC+14)
/* 0DE944 7F0A9E14 3401AC05 */  li    $at, 44037
/* 0DE948 7F0A9E18 8DF82A58 */  lw    $t8, 0x2a58($t7)
/* 0DE94C 7F0A9E1C 8FA700AC */  lw    $a3, 0xac($sp)
/* 0DE950 7F0A9E20 00184880 */  sll   $t1, $t8, 2
/* 0DE954 7F0A9E24 01384821 */  addu  $t1, $t1, $t8
/* 0DE958 7F0A9E28 00094880 */  sll   $t1, $t1, 2
/* 0DE95C 7F0A9E2C 01495021 */  addu  $t2, $t2, $t1
/* 0DE960 7F0A9E30 954A09EA */  lhu   $t2, %lo(D_800409DC+14)($t2)
/* 0DE964 7F0A9E34 15410005 */  bne   $t2, $at, .L7F0A9E4C
/* 0DE968 7F0A9E38 00000000 */   nop
/* 0DE96C 7F0A9E3C 0FC30776 */  jal   langGet
/* 0DE970 7F0A9E40 3404AC30 */   li    $a0, 44080
/* 0DE974 7F0A9E44 10000001 */  b     .L7F0A9E4C
/* 0DE978 7F0A9E48 00403825 */   move  $a3, $v0
.L7F0A9E4C:
/* 0DE97C 7F0A9E4C 10000027 */  b     .L7F0A9EEC
/* 0DE980 7F0A9E50 AFA70058 */   sw    $a3, 0x58($sp)
.L7F0A9E54:
/* 0DE984 7F0A9E54 0C0030C3 */  jal   joyGetButtons
/* 0DE988 7F0A9E58 24050400 */   li    $a1, 1024
/* 0DE98C 7F0A9E5C 10400014 */  beqz  $v0, .L7F0A9EB0
/* 0DE990 7F0A9E60 00002025 */   move  $a0, $zero
/* 0DE994 7F0A9E64 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0DE998 7F0A9E68 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DE99C 7F0A9E6C 3C0E8004 */  lui   $t6, %hi(D_800409DC+14)
/* 0DE9A0 7F0A9E70 3401AC05 */  li    $at, 44037
/* 0DE9A4 7F0A9E74 8D6C2A58 */  lw    $t4, 0x2a58($t3)
/* 0DE9A8 7F0A9E78 8FA700A8 */  lw    $a3, 0xa8($sp)
/* 0DE9AC 7F0A9E7C 000C6880 */  sll   $t5, $t4, 2
/* 0DE9B0 7F0A9E80 01AC6821 */  addu  $t5, $t5, $t4
/* 0DE9B4 7F0A9E84 000D6880 */  sll   $t5, $t5, 2
/* 0DE9B8 7F0A9E88 01CD7021 */  addu  $t6, $t6, $t5
/* 0DE9BC 7F0A9E8C 95CE09EA */  lhu   $t6, %lo(D_800409DC+14)($t6)
/* 0DE9C0 7F0A9E90 15C10005 */  bne   $t6, $at, .L7F0A9EA8
/* 0DE9C4 7F0A9E94 00000000 */   nop
/* 0DE9C8 7F0A9E98 0FC30776 */  jal   langGet
/* 0DE9CC 7F0A9E9C 3404AC31 */   li    $a0, 44081
/* 0DE9D0 7F0A9EA0 10000001 */  b     .L7F0A9EA8
/* 0DE9D4 7F0A9EA4 00403825 */   move  $a3, $v0
.L7F0A9EA8:
/* 0DE9D8 7F0A9EA8 10000010 */  b     .L7F0A9EEC
/* 0DE9DC 7F0A9EAC AFA70058 */   sw    $a3, 0x58($sp)
.L7F0A9EB0:
/* 0DE9E0 7F0A9EB0 0C0030C3 */  jal   joyGetButtons
/* 0DE9E4 7F0A9EB4 24050200 */   li    $a1, 512
/* 0DE9E8 7F0A9EB8 10400005 */  beqz  $v0, .L7F0A9ED0
/* 0DE9EC 7F0A9EBC 00002025 */   move  $a0, $zero
/* 0DE9F0 7F0A9EC0 0FC30776 */  jal   langGet
/* 0DE9F4 7F0A9EC4 3404AC2F */   li    $a0, 44079
/* 0DE9F8 7F0A9EC8 10000008 */  b     .L7F0A9EEC
/* 0DE9FC 7F0A9ECC AFA20058 */   sw    $v0, 0x58($sp)
.L7F0A9ED0:
/* 0DEA00 7F0A9ED0 0C0030C3 */  jal   joyGetButtons
/* 0DEA04 7F0A9ED4 24050100 */   li    $a1, 256
/* 0DEA08 7F0A9ED8 50400005 */  beql  $v0, $zero, .L7F0A9EF0
/* 0DEA0C 7F0A9EDC 3C0F0070 */   lui   $t7, 0x70
/* 0DEA10 7F0A9EE0 0FC30776 */  jal   langGet
/* 0DEA14 7F0A9EE4 3404AC2E */   li    $a0, 44078
/* 0DEA18 7F0A9EE8 AFA20058 */  sw    $v0, 0x58($sp)
.L7F0A9EEC:
/* 0DEA1C 7F0A9EEC 3C0F0070 */  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
.L7F0A9EF0:
/* 0DEA20 7F0A9EF0 3C180030 */  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
/* 0DEA24 7F0A9EF4 371800B0 */  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DEA28 7F0A9EF8 35EF00A0 */  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
/* 0DEA2C 7F0A9EFC 2408FFFF */  li    $t0, -1
/* 0DEA30 7F0A9F00 24190001 */  li    $t9, 1
/* 0DEA34 7F0A9F04 8FA70058 */  lw    $a3, 0x58($sp)
/* 0DEA38 7F0A9F08 AFB90014 */  sw    $t9, 0x14($sp)
/* 0DEA3C 7F0A9F0C AFA80010 */  sw    $t0, 0x10($sp)
/* 0DEA40 7F0A9F10 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DEA44 7F0A9F14 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DEA48 7F0A9F18 02002025 */  move  $a0, $s0
/* 0DEA4C 7F0A9F1C 24050032 */  li    $a1, 50
/* 0DEA50 7F0A9F20 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEA54 7F0A9F24 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEA58 7F0A9F28 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DEA5C 7F0A9F2C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEA60 7F0A9F30 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DEA64 7F0A9F34 00408025 */  move  $s0, $v0
.L7F0A9F38:
/* 0DEA68 7F0A9F38 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0DEA6C 7F0A9F3C 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0DEA70 7F0A9F40 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DEA74 7F0A9F44 252A0019 */  addiu $t2, $t1, 0x19
/* 0DEA78 7F0A9F48 AFAA004C */  sw    $t2, 0x4c($sp)
/* 0DEA7C 7F0A9F4C 8D6C2A58 */  lw    $t4, 0x2a58($t3)
/* 0DEA80 7F0A9F50 3C048004 */  lui   $a0, %hi(D_800409DC+16)
/* 0DEA84 7F0A9F54 000C6880 */  sll   $t5, $t4, 2
/* 0DEA88 7F0A9F58 01AC6821 */  addu  $t5, $t5, $t4
/* 0DEA8C 7F0A9F5C 000D6880 */  sll   $t5, $t5, 2
/* 0DEA90 7F0A9F60 008D2021 */  addu  $a0, $a0, $t5
/* 0DEA94 7F0A9F64 0FC30776 */  jal   langGet
/* 0DEA98 7F0A9F68 948409EC */   lhu   $a0, %lo(D_800409DC+16)($a0)
/* 0DEA9C 7F0A9F6C 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DEAA0 7F0A9F70 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DEAA4 7F0A9F74 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DEAA8 7F0A9F78 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DEAAC 7F0A9F7C 2408FFFF */  li    $t0, -1
/* 0DEAB0 7F0A9F80 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DEAB4 7F0A9F84 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DEAB8 7F0A9F88 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DEABC 7F0A9F8C 02002025 */  move  $a0, $s0
/* 0DEAC0 7F0A9F90 24050032 */  li    $a1, 50
/* 0DEAC4 7F0A9F94 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEAC8 7F0A9F98 00403825 */  move  $a3, $v0
/* 0DEACC 7F0A9F9C AFA00014 */  sw    $zero, 0x14($sp)
/* 0DEAD0 7F0A9FA0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEAD4 7F0A9FA4 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DEAD8 7F0A9FA8 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEADC 7F0A9FAC AFA00028 */   sw    $zero, 0x28($sp)
/* 0DEAE0 7F0A9FB0 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0DEAE4 7F0A9FB4 00408025 */  move  $s0, $v0
/* 0DEAE8 7F0A9FB8 00002025 */  move  $a0, $zero
/* 0DEAEC 7F0A9FBC 25F80019 */  addiu $t8, $t7, 0x19
/* 0DEAF0 7F0A9FC0 AFB8004C */  sw    $t8, 0x4c($sp)
/* 0DEAF4 7F0A9FC4 0C0030C3 */  jal   joyGetButtons
/* 0DEAF8 7F0A9FC8 24052000 */   li    $a1, 8192
/* 0DEAFC 7F0A9FCC 1040002D */  beqz  $v0, .L7F0AA084
/* 0DEB00 7F0A9FD0 3C0B8008 */   lui   $t3, %hi(g_CurrentPlayer)
/* 0DEB04 7F0A9FD4 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0DEB08 7F0A9FD8 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DEB0C 7F0A9FDC 3C048004 */  lui   $a0, %hi(D_800409DC+0x6)
/* 0DEB10 7F0A9FE0 8D2A2A58 */  lw    $t2, 0x2a58($t1)
/* 0DEB14 7F0A9FE4 000A5880 */  sll   $t3, $t2, 2
/* 0DEB18 7F0A9FE8 016A5821 */  addu  $t3, $t3, $t2
/* 0DEB1C 7F0A9FEC 000B5880 */  sll   $t3, $t3, 2
/* 0DEB20 7F0A9FF0 008B2021 */  addu  $a0, $a0, $t3
/* 0DEB24 7F0A9FF4 0FC30776 */  jal   langGet
/* 0DEB28 7F0A9FF8 948409E2 */   lhu   $a0, %lo(D_800409DC+0x6)($a0)
/* 0DEB2C 7F0A9FFC 3C0E0070 */  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
/* 0DEB30 7F0AA000 3C080030 */  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
/* 0DEB34 7F0AA004 350800B0 */  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DEB38 7F0AA008 35CE00A0 */  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
/* 0DEB3C 7F0AA00C 240CFFFF */  li    $t4, -1
/* 0DEB40 7F0AA010 240D0001 */  li    $t5, 1
/* 0DEB44 7F0AA014 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DEB48 7F0AA018 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DEB4C 7F0AA01C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DEB50 7F0AA020 AFA80024 */  sw    $t0, 0x24($sp)
/* 0DEB54 7F0AA024 02002025 */  move  $a0, $s0
/* 0DEB58 7F0AA028 24050032 */  li    $a1, 50
/* 0DEB5C 7F0AA02C 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEB60 7F0AA030 00403825 */  move  $a3, $v0
/* 0DEB64 7F0AA034 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEB68 7F0AA038 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DEB6C 7F0AA03C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEB70 7F0AA040 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DEB74 7F0AA044 3C198008 */  lui   $t9, %hi(g_CurrentPlayer)
/* 0DEB78 7F0AA048 8F39A0B0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0DEB7C 7F0AA04C 3C098004 */  lui   $t1, %hi(D_800409DC+6)
/* 0DEB80 7F0AA050 3401AC01 */  li    $at, 44033
/* 0DEB84 7F0AA054 8F2F2A58 */  lw    $t7, 0x2a58($t9)
/* 0DEB88 7F0AA058 00408025 */  move  $s0, $v0
/* 0DEB8C 7F0AA05C 240A0001 */  li    $t2, 1
/* 0DEB90 7F0AA060 000FC080 */  sll   $t8, $t7, 2
/* 0DEB94 7F0AA064 030FC021 */  addu  $t8, $t8, $t7
/* 0DEB98 7F0AA068 0018C080 */  sll   $t8, $t8, 2
/* 0DEB9C 7F0AA06C 01384821 */  addu  $t1, $t1, $t8
/* 0DEBA0 7F0AA070 952909E2 */  lhu   $t1, %lo(D_800409DC+6)($t1)
/* 0DEBA4 7F0AA074 5521001F */  bnel  $t1, $at, .L7F0AA0F4
/* 0DEBA8 7F0AA078 8FAF004C */   lw    $t7, 0x4c($sp)
/* 0DEBAC 7F0AA07C 1000001C */  b     .L7F0AA0F0
/* 0DEBB0 7F0AA080 AFAA0050 */   sw    $t2, 0x50($sp)
.L7F0AA084:
/* 0DEBB4 7F0AA084 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DEBB8 7F0AA088 3C048004 */  lui   $a0, %hi(D_800409DC+6)
/* 0DEBBC 7F0AA08C 8D6C2A58 */  lw    $t4, 0x2a58($t3)
/* 0DEBC0 7F0AA090 000C6880 */  sll   $t5, $t4, 2
/* 0DEBC4 7F0AA094 01AC6821 */  addu  $t5, $t5, $t4
/* 0DEBC8 7F0AA098 000D6880 */  sll   $t5, $t5, 2
/* 0DEBCC 7F0AA09C 008D2021 */  addu  $a0, $a0, $t5
/* 0DEBD0 7F0AA0A0 0FC30776 */  jal   langGet
/* 0DEBD4 7F0AA0A4 948409E2 */   lhu   $a0, %lo(D_800409DC+6)($a0)
/* 0DEBD8 7F0AA0A8 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DEBDC 7F0AA0AC 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DEBE0 7F0AA0B0 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DEBE4 7F0AA0B4 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DEBE8 7F0AA0B8 2408FFFF */  li    $t0, -1
/* 0DEBEC 7F0AA0BC AFA80018 */  sw    $t0, 0x18($sp)
/* 0DEBF0 7F0AA0C0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DEBF4 7F0AA0C4 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DEBF8 7F0AA0C8 02002025 */  move  $a0, $s0
/* 0DEBFC 7F0AA0CC 24050032 */  li    $a1, 50
/* 0DEC00 7F0AA0D0 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEC04 7F0AA0D4 00403825 */  move  $a3, $v0
/* 0DEC08 7F0AA0D8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DEC0C 7F0AA0DC AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEC10 7F0AA0E0 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DEC14 7F0AA0E4 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEC18 7F0AA0E8 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DEC1C 7F0AA0EC 00408025 */  move  $s0, $v0
.L7F0AA0F0:
/* 0DEC20 7F0AA0F0 8FAF004C */  lw    $t7, 0x4c($sp)
.L7F0AA0F4:
/* 0DEC24 7F0AA0F4 00002025 */  move  $a0, $zero
/* 0DEC28 7F0AA0F8 24050010 */  li    $a1, 16
/* 0DEC2C 7F0AA0FC 25F8FFB5 */  addiu $t8, $t7, -0x4b
/* 0DEC30 7F0AA100 0C0030C3 */  jal   joyGetButtons
/* 0DEC34 7F0AA104 AFB8004C */   sw    $t8, 0x4c($sp)
/* 0DEC38 7F0AA108 1040002E */  beqz  $v0, .L7F0AA1C4
/* 0DEC3C 7F0AA10C 3C0C8008 */   lui   $t4, %hi(g_CurrentPlayer)
/* 0DEC40 7F0AA110 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0DEC44 7F0AA114 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DEC48 7F0AA118 3C048004 */  lui   $a0, %hi(D_800409DC+10)
/* 0DEC4C 7F0AA11C 8D2A2A58 */  lw    $t2, 0x2a58($t1)
/* 0DEC50 7F0AA120 000A5880 */  sll   $t3, $t2, 2
/* 0DEC54 7F0AA124 016A5821 */  addu  $t3, $t3, $t2
/* 0DEC58 7F0AA128 000B5880 */  sll   $t3, $t3, 2
/* 0DEC5C 7F0AA12C 008B2021 */  addu  $a0, $a0, $t3
/* 0DEC60 7F0AA130 0FC30776 */  jal   langGet
/* 0DEC64 7F0AA134 948409E6 */   lhu   $a0, %lo(D_800409DC+10)($a0)
/* 0DEC68 7F0AA138 3C0E0070 */  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
/* 0DEC6C 7F0AA13C 3C080030 */  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
/* 0DEC70 7F0AA140 350800B0 */  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DEC74 7F0AA144 35CE00A0 */  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
/* 0DEC78 7F0AA148 240CFFFF */  li    $t4, -1
/* 0DEC7C 7F0AA14C 240D0001 */  li    $t5, 1
/* 0DEC80 7F0AA150 24190001 */  li    $t9, 1
/* 0DEC84 7F0AA154 AFB90028 */  sw    $t9, 0x28($sp)
/* 0DEC88 7F0AA158 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DEC8C 7F0AA15C AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DEC90 7F0AA160 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DEC94 7F0AA164 AFA80024 */  sw    $t0, 0x24($sp)
/* 0DEC98 7F0AA168 02002025 */  move  $a0, $s0
/* 0DEC9C 7F0AA16C 2405010E */  li    $a1, 270
/* 0DECA0 7F0AA170 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DECA4 7F0AA174 00403825 */  move  $a3, $v0
/* 0DECA8 7F0AA178 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DECAC 7F0AA17C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DECB0 7F0AA180 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DECB4 7F0AA184 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0DECB8 7F0AA188 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DECBC 7F0AA18C 3C0A8004 */  lui   $t2, %hi(D_800409DC+10)
/* 0DECC0 7F0AA190 3401AC01 */  li    $at, 44033
/* 0DECC4 7F0AA194 8DF82A58 */  lw    $t8, 0x2a58($t7)
/* 0DECC8 7F0AA198 00408025 */  move  $s0, $v0
/* 0DECCC 7F0AA19C 240B0001 */  li    $t3, 1
/* 0DECD0 7F0AA1A0 00184880 */  sll   $t1, $t8, 2
/* 0DECD4 7F0AA1A4 01384821 */  addu  $t1, $t1, $t8
/* 0DECD8 7F0AA1A8 00094880 */  sll   $t1, $t1, 2
/* 0DECDC 7F0AA1AC 01495021 */  addu  $t2, $t2, $t1
/* 0DECE0 7F0AA1B0 954A09E6 */  lhu   $t2, %lo(D_800409DC+10)($t2)
/* 0DECE4 7F0AA1B4 55410020 */  bnel  $t2, $at, .L7F0AA238
/* 0DECE8 7F0AA1B8 8FA9004C */   lw    $t1, 0x4c($sp)
/* 0DECEC 7F0AA1BC 1000001D */  b     .L7F0AA234
/* 0DECF0 7F0AA1C0 AFAB0050 */   sw    $t3, 0x50($sp)
.L7F0AA1C4:
/* 0DECF4 7F0AA1C4 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DECF8 7F0AA1C8 3C048004 */  lui   $a0, %hi(D_800409DC+10)
/* 0DECFC 7F0AA1CC 8D8D2A58 */  lw    $t5, 0x2a58($t4)
/* 0DED00 7F0AA1D0 000D7080 */  sll   $t6, $t5, 2
/* 0DED04 7F0AA1D4 01CD7021 */  addu  $t6, $t6, $t5
/* 0DED08 7F0AA1D8 000E7080 */  sll   $t6, $t6, 2
/* 0DED0C 7F0AA1DC 008E2021 */  addu  $a0, $a0, $t6
/* 0DED10 7F0AA1E0 0FC30776 */  jal   langGet
/* 0DED14 7F0AA1E4 948409E6 */   lhu   $a0, %lo(D_800409DC+10)($a0)
/* 0DED18 7F0AA1E8 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DED1C 7F0AA1EC 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DED20 7F0AA1F0 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DED24 7F0AA1F4 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DED28 7F0AA1F8 2419FFFF */  li    $t9, -1
/* 0DED2C 7F0AA1FC 24180001 */  li    $t8, 1
/* 0DED30 7F0AA200 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DED34 7F0AA204 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DED38 7F0AA208 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DED3C 7F0AA20C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DED40 7F0AA210 02002025 */  move  $a0, $s0
/* 0DED44 7F0AA214 2405010E */  li    $a1, 270
/* 0DED48 7F0AA218 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DED4C 7F0AA21C 00403825 */  move  $a3, $v0
/* 0DED50 7F0AA220 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DED54 7F0AA224 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DED58 7F0AA228 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DED5C 7F0AA22C AFA00020 */   sw    $zero, 0x20($sp)
/* 0DED60 7F0AA230 00408025 */  move  $s0, $v0
.L7F0AA234:
/* 0DED64 7F0AA234 8FA9004C */  lw    $t1, 0x4c($sp)
.L7F0AA238:
/* 0DED68 7F0AA238 3C0B8004 */  lui   $t3, %hi(controller_options_index)
/* 0DED6C 7F0AA23C 8D6B0998 */  lw    $t3, %lo(controller_options_index)($t3)
/* 0DED70 7F0AA240 24010001 */  li    $at, 1
/* 0DED74 7F0AA244 252A0019 */  addiu $t2, $t1, 0x19
/* 0DED78 7F0AA248 1561000A */  bne   $t3, $at, .L7F0AA274
/* 0DED7C 7F0AA24C AFAA004C */   sw    $t2, 0x4c($sp)
/* 0DED80 7F0AA250 3C0C8004 */  lui   $t4, %hi(watch_item_is_actively_selected)
/* 0DED84 7F0AA254 8D8C09A8 */  lw    $t4, %lo(watch_item_is_actively_selected)($t4)
/* 0DED88 7F0AA258 00002025 */  move  $a0, $zero
/* 0DED8C 7F0AA25C 11800005 */  beqz  $t4, .L7F0AA274
/* 0DED90 7F0AA260 00000000 */   nop
/* 0DED94 7F0AA264 0C0030C3 */  jal   joyGetButtons
/* 0DED98 7F0AA268 2405000F */   li    $a1, 15
/* 0DED9C 7F0AA26C 1440001F */  bnez  $v0, .L7F0AA2EC
/* 0DEDA0 7F0AA270 00002025 */   move  $a0, $zero
.L7F0AA274:
/* 0DEDA4 7F0AA274 3C0D8008 */  lui   $t5, %hi(g_CurrentPlayer)
/* 0DEDA8 7F0AA278 8DADA0B0 */  lw    $t5, %lo(g_CurrentPlayer)($t5)
/* 0DEDAC 7F0AA27C 3C048004 */  lui   $a0, %hi(D_800409DC+12)
/* 0DEDB0 7F0AA280 8DAE2A58 */  lw    $t6, 0x2a58($t5)
/* 0DEDB4 7F0AA284 000E4080 */  sll   $t0, $t6, 2
/* 0DEDB8 7F0AA288 010E4021 */  addu  $t0, $t0, $t6
/* 0DEDBC 7F0AA28C 00084080 */  sll   $t0, $t0, 2
/* 0DEDC0 7F0AA290 00882021 */  addu  $a0, $a0, $t0
/* 0DEDC4 7F0AA294 0FC30776 */  jal   langGet
/* 0DEDC8 7F0AA298 948409E8 */   lhu   $a0, %lo(D_800409DC+12)($a0)
/* 0DEDCC 7F0AA29C 3C1900AA */  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
/* 0DEDD0 7F0AA2A0 3C180030 */  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
/* 0DEDD4 7F0AA2A4 371800B0 */  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DEDD8 7F0AA2A8 373900B0 */  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DEDDC 7F0AA2AC 240FFFFF */  li    $t7, -1
/* 0DEDE0 7F0AA2B0 24090001 */  li    $t1, 1
/* 0DEDE4 7F0AA2B4 AFA90028 */  sw    $t1, 0x28($sp)
/* 0DEDE8 7F0AA2B8 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DEDEC 7F0AA2BC AFB90010 */  sw    $t9, 0x10($sp)
/* 0DEDF0 7F0AA2C0 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DEDF4 7F0AA2C4 02002025 */  move  $a0, $s0
/* 0DEDF8 7F0AA2C8 2405010E */  li    $a1, 270
/* 0DEDFC 7F0AA2CC 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEE00 7F0AA2D0 00403825 */  move  $a3, $v0
/* 0DEE04 7F0AA2D4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DEE08 7F0AA2D8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEE0C 7F0AA2DC 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEE10 7F0AA2E0 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DEE14 7F0AA2E4 10000076 */  b     .L7F0AA4C0
/* 0DEE18 7F0AA2E8 00408025 */   move  $s0, $v0
.L7F0AA2EC:
/* 0DEE1C 7F0AA2EC 0C0030C3 */  jal   joyGetButtons
/* 0DEE20 7F0AA2F0 2405000F */   li    $a1, 15
/* 0DEE24 7F0AA2F4 244AFFFF */  addiu $t2, $v0, -1
/* 0DEE28 7F0AA2F8 004A5824 */  and   $t3, $v0, $t2
/* 0DEE2C 7F0AA2FC 15600054 */  bnez  $t3, .L7F0AA450
/* 0DEE30 7F0AA300 3C088008 */   lui   $t0, %hi(g_CurrentPlayer)
/* 0DEE34 7F0AA304 00002025 */  move  $a0, $zero
/* 0DEE38 7F0AA308 0C0030C3 */  jal   joyGetButtons
/* 0DEE3C 7F0AA30C 24050008 */   li    $a1, 8
/* 0DEE40 7F0AA310 10400014 */  beqz  $v0, .L7F0AA364
/* 0DEE44 7F0AA314 00002025 */   move  $a0, $zero
/* 0DEE48 7F0AA318 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer)
/* 0DEE4C 7F0AA31C 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DEE50 7F0AA320 3C088004 */  lui   $t0, %hi(D_800409DC+12)
/* 0DEE54 7F0AA324 3401AC05 */  li    $at, 44037
/* 0DEE58 7F0AA328 8D8D2A58 */  lw    $t5, 0x2a58($t4)
/* 0DEE5C 7F0AA32C 8FA700AC */  lw    $a3, 0xac($sp)
/* 0DEE60 7F0AA330 000D7080 */  sll   $t6, $t5, 2
/* 0DEE64 7F0AA334 01CD7021 */  addu  $t6, $t6, $t5
/* 0DEE68 7F0AA338 000E7080 */  sll   $t6, $t6, 2
/* 0DEE6C 7F0AA33C 010E4021 */  addu  $t0, $t0, $t6
/* 0DEE70 7F0AA340 950809E8 */  lhu   $t0, %lo(D_800409DC+12)($t0)
/* 0DEE74 7F0AA344 15010005 */  bne   $t0, $at, .L7F0AA35C
/* 0DEE78 7F0AA348 00000000 */   nop
/* 0DEE7C 7F0AA34C 0FC30776 */  jal   langGet
/* 0DEE80 7F0AA350 3404AC30 */   li    $a0, 44080
/* 0DEE84 7F0AA354 10000001 */  b     .L7F0AA35C
/* 0DEE88 7F0AA358 00403825 */   move  $a3, $v0
.L7F0AA35C:
/* 0DEE8C 7F0AA35C 10000027 */  b     .L7F0AA3FC
/* 0DEE90 7F0AA360 AFA7005C */   sw    $a3, 0x5c($sp)
.L7F0AA364:
/* 0DEE94 7F0AA364 0C0030C3 */  jal   joyGetButtons
/* 0DEE98 7F0AA368 24050004 */   li    $a1, 4
/* 0DEE9C 7F0AA36C 10400014 */  beqz  $v0, .L7F0AA3C0
/* 0DEEA0 7F0AA370 00002025 */   move  $a0, $zero
/* 0DEEA4 7F0AA374 3C198008 */  lui   $t9, %hi(g_CurrentPlayer)
/* 0DEEA8 7F0AA378 8F39A0B0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0DEEAC 7F0AA37C 3C098004 */  lui   $t1, %hi(D_800409DC+12)
/* 0DEEB0 7F0AA380 3401AC05 */  li    $at, 44037
/* 0DEEB4 7F0AA384 8F2F2A58 */  lw    $t7, 0x2a58($t9)
/* 0DEEB8 7F0AA388 8FA700A8 */  lw    $a3, 0xa8($sp)
/* 0DEEBC 7F0AA38C 000FC080 */  sll   $t8, $t7, 2
/* 0DEEC0 7F0AA390 030FC021 */  addu  $t8, $t8, $t7
/* 0DEEC4 7F0AA394 0018C080 */  sll   $t8, $t8, 2
/* 0DEEC8 7F0AA398 01384821 */  addu  $t1, $t1, $t8
/* 0DEECC 7F0AA39C 952909E8 */  lhu   $t1, %lo(D_800409DC+12)($t1)
/* 0DEED0 7F0AA3A0 15210005 */  bne   $t1, $at, .L7F0AA3B8
/* 0DEED4 7F0AA3A4 00000000 */   nop
/* 0DEED8 7F0AA3A8 0FC30776 */  jal   langGet
/* 0DEEDC 7F0AA3AC 3404AC31 */   li    $a0, 44081
/* 0DEEE0 7F0AA3B0 10000001 */  b     .L7F0AA3B8
/* 0DEEE4 7F0AA3B4 00403825 */   move  $a3, $v0
.L7F0AA3B8:
/* 0DEEE8 7F0AA3B8 10000010 */  b     .L7F0AA3FC
/* 0DEEEC 7F0AA3BC AFA7005C */   sw    $a3, 0x5c($sp)
.L7F0AA3C0:
/* 0DEEF0 7F0AA3C0 0C0030C3 */  jal   joyGetButtons
/* 0DEEF4 7F0AA3C4 24050002 */   li    $a1, 2
/* 0DEEF8 7F0AA3C8 10400005 */  beqz  $v0, .L7F0AA3E0
/* 0DEEFC 7F0AA3CC 00002025 */   move  $a0, $zero
/* 0DEF00 7F0AA3D0 0FC30776 */  jal   langGet
/* 0DEF04 7F0AA3D4 3404AC2F */   li    $a0, 44079
/* 0DEF08 7F0AA3D8 10000008 */  b     .L7F0AA3FC
/* 0DEF0C 7F0AA3DC AFA2005C */   sw    $v0, 0x5c($sp)
.L7F0AA3E0:
/* 0DEF10 7F0AA3E0 0C0030C3 */  jal   joyGetButtons
/* 0DEF14 7F0AA3E4 24050001 */   li    $a1, 1
/* 0DEF18 7F0AA3E8 50400005 */  beql  $v0, $zero, .L7F0AA400
/* 0DEF1C 7F0AA3EC 3C0C0070 */   lui   $t4, 0x70
/* 0DEF20 7F0AA3F0 0FC30776 */  jal   langGet
/* 0DEF24 7F0AA3F4 3404AC2E */   li    $a0, 44078
/* 0DEF28 7F0AA3F8 AFA2005C */  sw    $v0, 0x5c($sp)
.L7F0AA3FC:
/* 0DEF2C 7F0AA3FC 3C0C0070 */  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
.L7F0AA400:
/* 0DEF30 7F0AA400 3C0D0030 */  lui   $t5, (0x003000B0 >> 16) # lui $t5, 0x30
/* 0DEF34 7F0AA404 35AD00B0 */  ori   $t5, (0x003000B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0DEF38 7F0AA408 358C00A0 */  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
/* 0DEF3C 7F0AA40C 240AFFFF */  li    $t2, -1
/* 0DEF40 7F0AA410 240B0001 */  li    $t3, 1
/* 0DEF44 7F0AA414 240E0001 */  li    $t6, 1
/* 0DEF48 7F0AA418 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DEF4C 7F0AA41C AFAE0028 */  sw    $t6, 0x28($sp)
/* 0DEF50 7F0AA420 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0DEF54 7F0AA424 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0DEF58 7F0AA428 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0DEF5C 7F0AA42C AFAD0024 */  sw    $t5, 0x24($sp)
/* 0DEF60 7F0AA430 02002025 */  move  $a0, $s0
/* 0DEF64 7F0AA434 2405010E */  li    $a1, 270
/* 0DEF68 7F0AA438 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEF6C 7F0AA43C AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEF70 7F0AA440 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEF74 7F0AA444 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DEF78 7F0AA448 1000001D */  b     .L7F0AA4C0
/* 0DEF7C 7F0AA44C 00408025 */   move  $s0, $v0
.L7F0AA450:
/* 0DEF80 7F0AA450 8D08A0B0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0DEF84 7F0AA454 3C048004 */  lui   $a0, %hi(D_800409DC+12)
/* 0DEF88 7F0AA458 8D192A58 */  lw    $t9, 0x2a58($t0)
/* 0DEF8C 7F0AA45C 00197880 */  sll   $t7, $t9, 2
/* 0DEF90 7F0AA460 01F97821 */  addu  $t7, $t7, $t9
/* 0DEF94 7F0AA464 000F7880 */  sll   $t7, $t7, 2
/* 0DEF98 7F0AA468 008F2021 */  addu  $a0, $a0, $t7
/* 0DEF9C 7F0AA46C 0FC30776 */  jal   langGet
/* 0DEFA0 7F0AA470 948409E8 */   lhu   $a0, %lo(D_800409DC+12)($a0)
/* 0DEFA4 7F0AA474 3C1800AA */  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
/* 0DEFA8 7F0AA478 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DEFAC 7F0AA47C 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DEFB0 7F0AA480 371800B0 */  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DEFB4 7F0AA484 2409FFFF */  li    $t1, -1
/* 0DEFB8 7F0AA488 240B0001 */  li    $t3, 1
/* 0DEFBC 7F0AA48C AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DEFC0 7F0AA490 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DEFC4 7F0AA494 AFB80010 */  sw    $t8, 0x10($sp)
/* 0DEFC8 7F0AA498 AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DEFCC 7F0AA49C 02002025 */  move  $a0, $s0
/* 0DEFD0 7F0AA4A0 2405010E */  li    $a1, 270
/* 0DEFD4 7F0AA4A4 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DEFD8 7F0AA4A8 00403825 */  move  $a3, $v0
/* 0DEFDC 7F0AA4AC AFA00014 */  sw    $zero, 0x14($sp)
/* 0DEFE0 7F0AA4B0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DEFE4 7F0AA4B4 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DEFE8 7F0AA4B8 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DEFEC 7F0AA4BC 00408025 */  move  $s0, $v0
.L7F0AA4C0:
/* 0DEFF0 7F0AA4C0 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0DEFF4 7F0AA4C4 00002025 */  move  $a0, $zero
/* 0DEFF8 7F0AA4C8 24054000 */  li    $a1, 16384
/* 0DEFFC 7F0AA4CC 258D0019 */  addiu $t5, $t4, 0x19
/* 0DF000 7F0AA4D0 0C0030C3 */  jal   joyGetButtons
/* 0DF004 7F0AA4D4 AFAD004C */   sw    $t5, 0x4c($sp)
/* 0DF008 7F0AA4D8 10400020 */  beqz  $v0, .L7F0AA55C
/* 0DF00C 7F0AA4DC 3C0C8008 */   lui   $t4, %hi(g_CurrentPlayer)
/* 0DF010 7F0AA4E0 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0DF014 7F0AA4E4 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0DF018 7F0AA4E8 3C048004 */  lui   $a0, %hi(D_800409DC+4)
/* 0DF01C 7F0AA4EC 8DC82A58 */  lw    $t0, 0x2a58($t6)
/* 0DF020 7F0AA4F0 0008C880 */  sll   $t9, $t0, 2
/* 0DF024 7F0AA4F4 0328C821 */  addu  $t9, $t9, $t0
/* 0DF028 7F0AA4F8 0019C880 */  sll   $t9, $t9, 2
/* 0DF02C 7F0AA4FC 00992021 */  addu  $a0, $a0, $t9
/* 0DF030 7F0AA500 0FC30776 */  jal   langGet
/* 0DF034 7F0AA504 948409E0 */   lhu   $a0, %lo(D_800409DC+4)($a0)
/* 0DF038 7F0AA508 3C090070 */  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
/* 0DF03C 7F0AA50C 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DF040 7F0AA510 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DF044 7F0AA514 352900A0 */  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
/* 0DF048 7F0AA518 240FFFFF */  li    $t7, -1
/* 0DF04C 7F0AA51C 24180001 */  li    $t8, 1
/* 0DF050 7F0AA520 240B0001 */  li    $t3, 1
/* 0DF054 7F0AA524 AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DF058 7F0AA528 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DF05C 7F0AA52C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DF060 7F0AA530 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DF064 7F0AA534 AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DF068 7F0AA538 02002025 */  move  $a0, $s0
/* 0DF06C 7F0AA53C 2405010E */  li    $a1, 270
/* 0DF070 7F0AA540 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DF074 7F0AA544 00403825 */  move  $a3, $v0
/* 0DF078 7F0AA548 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF07C 7F0AA54C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF080 7F0AA550 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF084 7F0AA554 1000001D */  b     .L7F0AA5CC
/* 0DF088 7F0AA558 00408025 */   move  $s0, $v0
.L7F0AA55C:
/* 0DF08C 7F0AA55C 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DF090 7F0AA560 3C048004 */  lui   $a0, %hi(D_800409DC+4)
/* 0DF094 7F0AA564 8D8D2A58 */  lw    $t5, 0x2a58($t4)
/* 0DF098 7F0AA568 000D7080 */  sll   $t6, $t5, 2
/* 0DF09C 7F0AA56C 01CD7021 */  addu  $t6, $t6, $t5
/* 0DF0A0 7F0AA570 000E7080 */  sll   $t6, $t6, 2
/* 0DF0A4 7F0AA574 008E2021 */  addu  $a0, $a0, $t6
/* 0DF0A8 7F0AA578 0FC30776 */  jal   langGet
/* 0DF0AC 7F0AA57C 948409E0 */   lhu   $a0, %lo(D_800409DC+4)($a0)
/* 0DF0B0 7F0AA580 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DF0B4 7F0AA584 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DF0B8 7F0AA588 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DF0BC 7F0AA58C 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DF0C0 7F0AA590 2419FFFF */  li    $t9, -1
/* 0DF0C4 7F0AA594 24180001 */  li    $t8, 1
/* 0DF0C8 7F0AA598 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DF0CC 7F0AA59C AFB90018 */  sw    $t9, 0x18($sp)
/* 0DF0D0 7F0AA5A0 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DF0D4 7F0AA5A4 AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DF0D8 7F0AA5A8 02002025 */  move  $a0, $s0
/* 0DF0DC 7F0AA5AC 2405010E */  li    $a1, 270
/* 0DF0E0 7F0AA5B0 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DF0E4 7F0AA5B4 00403825 */  move  $a3, $v0
/* 0DF0E8 7F0AA5B8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DF0EC 7F0AA5BC AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF0F0 7F0AA5C0 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF0F4 7F0AA5C4 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF0F8 7F0AA5C8 00408025 */  move  $s0, $v0
.L7F0AA5CC:
/* 0DF0FC 7F0AA5CC 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0DF100 7F0AA5D0 00002025 */  move  $a0, $zero
/* 0DF104 7F0AA5D4 34058000 */  li    $a1, 32768
/* 0DF108 7F0AA5D8 252A0019 */  addiu $t2, $t1, 0x19
/* 0DF10C 7F0AA5DC 0C0030C3 */  jal   joyGetButtons
/* 0DF110 7F0AA5E0 AFAA004C */   sw    $t2, 0x4c($sp)
/* 0DF114 7F0AA5E4 10400020 */  beqz  $v0, .L7F0AA668
/* 0DF118 7F0AA5E8 3C098008 */   lui   $t1, %hi(g_CurrentPlayer)
/* 0DF11C 7F0AA5EC 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0DF120 7F0AA5F0 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DF124 7F0AA5F4 3C048004 */  lui   $a0, %hi(D_800409DC+2)
/* 0DF128 7F0AA5F8 8D6C2A58 */  lw    $t4, 0x2a58($t3)
/* 0DF12C 7F0AA5FC 000C6880 */  sll   $t5, $t4, 2
/* 0DF130 7F0AA600 01AC6821 */  addu  $t5, $t5, $t4
/* 0DF134 7F0AA604 000D6880 */  sll   $t5, $t5, 2
/* 0DF138 7F0AA608 008D2021 */  addu  $a0, $a0, $t5
/* 0DF13C 7F0AA60C 0FC30776 */  jal   langGet
/* 0DF140 7F0AA610 948409DE */   lhu   $a0, %lo(D_800409DC+2)($a0)
/* 0DF144 7F0AA614 3C190070 */  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
/* 0DF148 7F0AA618 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DF14C 7F0AA61C 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DF150 7F0AA620 373900A0 */  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0DF154 7F0AA624 240EFFFF */  li    $t6, -1
/* 0DF158 7F0AA628 24080001 */  li    $t0, 1
/* 0DF15C 7F0AA62C 24180001 */  li    $t8, 1
/* 0DF160 7F0AA630 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DF164 7F0AA634 AFA80014 */  sw    $t0, 0x14($sp)
/* 0DF168 7F0AA638 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DF16C 7F0AA63C AFB90018 */  sw    $t9, 0x18($sp)
/* 0DF170 7F0AA640 AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DF174 7F0AA644 02002025 */  move  $a0, $s0
/* 0DF178 7F0AA648 2405010E */  li    $a1, 270
/* 0DF17C 7F0AA64C 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DF180 7F0AA650 00403825 */  move  $a3, $v0
/* 0DF184 7F0AA654 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF188 7F0AA658 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF18C 7F0AA65C AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF190 7F0AA660 1000001D */  b     .L7F0AA6D8
/* 0DF194 7F0AA664 00408025 */   move  $s0, $v0
.L7F0AA668:
/* 0DF198 7F0AA668 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DF19C 7F0AA66C 3C048004 */  lui   $a0, %hi(D_800409DC+2)
/* 0DF1A0 7F0AA670 8D2A2A58 */  lw    $t2, 0x2a58($t1)
/* 0DF1A4 7F0AA674 000A5880 */  sll   $t3, $t2, 2
/* 0DF1A8 7F0AA678 016A5821 */  addu  $t3, $t3, $t2
/* 0DF1AC 7F0AA67C 000B5880 */  sll   $t3, $t3, 2
/* 0DF1B0 7F0AA680 008B2021 */  addu  $a0, $a0, $t3
/* 0DF1B4 7F0AA684 0FC30776 */  jal   langGet
/* 0DF1B8 7F0AA688 948409DE */   lhu   $a0, %lo(D_800409DC+2)($a0)
/* 0DF1BC 7F0AA68C 3C0C00AA */  lui   $t4, (0x00AA00B0 >> 16) # lui $t4, 0xaa
/* 0DF1C0 7F0AA690 3C0E0030 */  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
/* 0DF1C4 7F0AA694 35CE00B0 */  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DF1C8 7F0AA698 358C00B0 */  ori   $t4, (0x00AA00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0DF1CC 7F0AA69C 240DFFFF */  li    $t5, -1
/* 0DF1D0 7F0AA6A0 24080001 */  li    $t0, 1
/* 0DF1D4 7F0AA6A4 AFA80028 */  sw    $t0, 0x28($sp)
/* 0DF1D8 7F0AA6A8 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DF1DC 7F0AA6AC AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DF1E0 7F0AA6B0 AFAE0024 */  sw    $t6, 0x24($sp)
/* 0DF1E4 7F0AA6B4 02002025 */  move  $a0, $s0
/* 0DF1E8 7F0AA6B8 2405010E */  li    $a1, 270
/* 0DF1EC 7F0AA6BC 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DF1F0 7F0AA6C0 00403825 */  move  $a3, $v0
/* 0DF1F4 7F0AA6C4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DF1F8 7F0AA6C8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF1FC 7F0AA6CC 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF200 7F0AA6D0 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF204 7F0AA6D4 00408025 */  move  $s0, $v0
.L7F0AA6D8:
/* 0DF208 7F0AA6D8 8FB90050 */  lw    $t9, 0x50($sp)
/* 0DF20C 7F0AA6DC 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer)
/* 0DF210 7F0AA6E0 13200018 */  beqz  $t9, .L7F0AA744
/* 0DF214 7F0AA6E4 00000000 */   nop
/* 0DF218 7F0AA6E8 0FC30776 */  jal   langGet
/* 0DF21C 7F0AA6EC 3404AC08 */   li    $a0, 44040
/* 0DF220 7F0AA6F0 3C090070 */  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
/* 0DF224 7F0AA6F4 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DF228 7F0AA6F8 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DF22C 7F0AA6FC 352900A0 */  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
/* 0DF230 7F0AA700 240FFFFF */  li    $t7, -1
/* 0DF234 7F0AA704 24180001 */  li    $t8, 1
/* 0DF238 7F0AA708 240B0001 */  li    $t3, 1
/* 0DF23C 7F0AA70C AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DF240 7F0AA710 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DF244 7F0AA714 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DF248 7F0AA718 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DF24C 7F0AA71C AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DF250 7F0AA720 02002025 */  move  $a0, $s0
/* 0DF254 7F0AA724 240500FA */  li    $a1, 250
/* 0DF258 7F0AA728 240600C3 */  li    $a2, 195
/* 0DF25C 7F0AA72C 00403825 */  move  $a3, $v0
/* 0DF260 7F0AA730 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF264 7F0AA734 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF268 7F0AA738 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF26C 7F0AA73C 1000001D */  b     .L7F0AA7B4
/* 0DF270 7F0AA740 00408025 */   move  $s0, $v0
.L7F0AA744:
/* 0DF274 7F0AA744 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DF278 7F0AA748 3C048004 */  lui   $a0, %hi(D_800409DC+18)
/* 0DF27C 7F0AA74C 8D8D2A58 */  lw    $t5, 0x2a58($t4)
/* 0DF280 7F0AA750 000D7080 */  sll   $t6, $t5, 2
/* 0DF284 7F0AA754 01CD7021 */  addu  $t6, $t6, $t5
/* 0DF288 7F0AA758 000E7080 */  sll   $t6, $t6, 2
/* 0DF28C 7F0AA75C 008E2021 */  addu  $a0, $a0, $t6
/* 0DF290 7F0AA760 0FC30776 */  jal   langGet
/* 0DF294 7F0AA764 948409EE */   lhu   $a0, %lo(D_800409DC+18)($a0)
/* 0DF298 7F0AA768 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DF29C 7F0AA76C 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DF2A0 7F0AA770 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DF2A4 7F0AA774 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DF2A8 7F0AA778 2419FFFF */  li    $t9, -1
/* 0DF2AC 7F0AA77C 24180001 */  li    $t8, 1
/* 0DF2B0 7F0AA780 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DF2B4 7F0AA784 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DF2B8 7F0AA788 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DF2BC 7F0AA78C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DF2C0 7F0AA790 02002025 */  move  $a0, $s0
/* 0DF2C4 7F0AA794 240500FA */  li    $a1, 250
/* 0DF2C8 7F0AA798 240600C3 */  li    $a2, 195
/* 0DF2CC 7F0AA79C 00403825 */  move  $a3, $v0
/* 0DF2D0 7F0AA7A0 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DF2D4 7F0AA7A4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DF2D8 7F0AA7A8 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0DF2DC 7F0AA7AC AFA00020 */   sw    $zero, 0x20($sp)
/* 0DF2E0 7F0AA7B0 00408025 */  move  $s0, $v0
.L7F0AA7B4:
/* 0DF2E4 7F0AA7B4 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DF2E8 7F0AA7B8 02001025 */  move  $v0, $s0
/* 0DF2EC 7F0AA7BC 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DF2F0 7F0AA7C0 03E00008 */  jr    $ra
/* 0DF2F4 7F0AA7C4 27BD00B0 */   addiu $sp, $sp, 0xb0
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A9AB8
/* 0DB7E8 7F0A8DF8 3C0E8004 */  lui   $t6, %hi(game_options_entries) # $t6, 0x8004
/* 0DB7EC 7F0A8DFC 8DCEA6D4 */  lw    $t6, %lo(game_options_entries + 0x8)($t6)
/* 0DB7F0 7F0A8E00 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 0DB7F4 7F0A8E04 AFB00038 */  sw    $s0, 0x38($sp)
/* 0DB7F8 7F0A8E08 24010001 */  li    $at, 1
/* 0DB7FC 7F0A8E0C 00808025 */  move  $s0, $a0
/* 0DB800 7F0A8E10 15C10008 */  bne   $t6, $at, .L7F0A8E34
/* 0DB804 7F0A8E14 AFBF003C */   sw    $ra, 0x3c($sp)
/* 0DB808 7F0A8E18 0FC304AE */  jal   langGet
/* 0DB80C 7F0A8E1C 3404AC2D */   li    $a0, 44077
/* 0DB810 7F0A8E20 AFA200AC */  sw    $v0, 0xac($sp)
/* 0DB814 7F0A8E24 0FC304AE */  jal   langGet
/* 0DB818 7F0A8E28 3404AC2C */   li    $a0, 44076
/* 0DB81C 7F0A8E2C 10000007 */  b     .L7F0A8E4C
/* 0DB820 7F0A8E30 AFA200A8 */   sw    $v0, 0xa8($sp)
.L7F0A8E34:
/* 0DB824 7F0A8E34 0FC304AE */  jal   langGet
/* 0DB828 7F0A8E38 3404AC2C */   li    $a0, 44076
/* 0DB82C 7F0A8E3C AFA200AC */  sw    $v0, 0xac($sp)
/* 0DB830 7F0A8E40 0FC304AE */  jal   langGet
/* 0DB834 7F0A8E44 3404AC2D */   li    $a0, 44077
/* 0DB838 7F0A8E48 AFA200A8 */  sw    $v0, 0xa8($sp)
.L7F0A8E4C:
/* 0DB83C 7F0A8E4C 3C188005 */  lui   $t8, %hi(aA) # $t8, 0x8005
/* 0DB840 7F0A8E50 2718CE48 */  addiu $t8, %lo(aA) # addiu $t8, $t8, -0x31b8
/* 0DB844 7F0A8E54 8F010000 */  lw    $at, ($t8)
/* 0DB848 7F0A8E58 27AF00A0 */  addiu $t7, $sp, 0xa0
/* 0DB84C 7F0A8E5C 3C0B8005 */  lui   $t3, %hi(aB) # $t3, 0x8005
/* 0DB850 7F0A8E60 ADE10000 */  sw    $at, ($t7)
/* 0DB854 7F0A8E64 93010004 */  lbu   $at, 4($t8)
/* 0DB858 7F0A8E68 256BCE50 */  addiu $t3, %lo(aB) # addiu $t3, $t3, -0x31b0
/* 0DB85C 7F0A8E6C 27AA0098 */  addiu $t2, $sp, 0x98
/* 0DB860 7F0A8E70 A1E10004 */  sb    $at, 4($t7)
/* 0DB864 7F0A8E74 8D610000 */  lw    $at, ($t3)
/* 0DB868 7F0A8E78 3C198005 */  lui   $t9, %hi(aZ) # $t9, 0x8005
/* 0DB86C 7F0A8E7C 2739CE58 */  addiu $t9, %lo(aZ) # addiu $t9, $t9, -0x31a8
/* 0DB870 7F0A8E80 AD410000 */  sw    $at, ($t2)
/* 0DB874 7F0A8E84 91610004 */  lbu   $at, 4($t3)
/* 0DB878 7F0A8E88 27A80090 */  addiu $t0, $sp, 0x90
/* 0DB87C 7F0A8E8C 3C0C8005 */  lui   $t4, %hi(aL) # $t4, 0x8005
/* 0DB880 7F0A8E90 A1410004 */  sb    $at, 4($t2)
/* 0DB884 7F0A8E94 8F210000 */  lw    $at, ($t9)
/* 0DB888 7F0A8E98 258CCE60 */  addiu $t4, %lo(aL) # addiu $t4, $t4, -0x31a0
/* 0DB88C 7F0A8E9C 27AD0088 */  addiu $t5, $sp, 0x88
/* 0DB890 7F0A8EA0 AD010000 */  sw    $at, ($t0)
/* 0DB894 7F0A8EA4 93210004 */  lbu   $at, 4($t9)
/* 0DB898 7F0A8EA8 3C0F8005 */  lui   $t7, %hi(aR) # $t7, 0x8005
/* 0DB89C 7F0A8EAC 25EFCE68 */  addiu $t7, %lo(aR) # addiu $t7, $t7, -0x3198
/* 0DB8A0 7F0A8EB0 A1010004 */  sb    $at, 4($t0)
/* 0DB8A4 7F0A8EB4 8D810000 */  lw    $at, ($t4)
/* 0DB8A8 7F0A8EB8 27B80080 */  addiu $t8, $sp, 0x80
/* 0DB8AC 7F0A8EBC 3C0A8005 */  lui   $t2, %hi(aC) # $t2, 0x8005
/* 0DB8B0 7F0A8EC0 ADA10000 */  sw    $at, ($t5)
/* 0DB8B4 7F0A8EC4 91810004 */  lbu   $at, 4($t4)
/* 0DB8B8 7F0A8EC8 254ACE70 */  addiu $t2, %lo(aC) # addiu $t2, $t2, -0x3190
/* 0DB8BC 7F0A8ECC 27AB0078 */  addiu $t3, $sp, 0x78
/* 0DB8C0 7F0A8ED0 A1A10004 */  sb    $at, 4($t5)
/* 0DB8C4 7F0A8ED4 8DE10000 */  lw    $at, ($t7)
/* 0DB8C8 7F0A8ED8 3C088005 */  lui   $t0, %hi(D_800577A8) # $t0, 0x8005
/* 0DB8CC 7F0A8EDC 2508CE78 */  addiu $t0, %lo(D_800577A8) # addiu $t0, $t0, -0x3188
/* 0DB8D0 7F0A8EE0 AF010000 */  sw    $at, ($t8)
/* 0DB8D4 7F0A8EE4 91E10004 */  lbu   $at, 4($t7)
/* 0DB8D8 7F0A8EE8 27B90070 */  addiu $t9, $sp, 0x70
/* 0DB8DC 7F0A8EEC 3C0D8005 */  lui   $t5, %hi(aS_0) # $t5, 0x8005
/* 0DB8E0 7F0A8EF0 A3010004 */  sb    $at, 4($t8)
/* 0DB8E4 7F0A8EF4 8D410000 */  lw    $at, ($t2)
/* 0DB8E8 7F0A8EF8 25ADCE80 */  addiu $t5, %lo(aS_0) # addiu $t5, $t5, -0x3180
/* 0DB8EC 7F0A8EFC 27AC0068 */  addiu $t4, $sp, 0x68
/* 0DB8F0 7F0A8F00 AD610000 */  sw    $at, ($t3)
/* 0DB8F4 7F0A8F04 91410004 */  lbu   $at, 4($t2)
/* 0DB8F8 7F0A8F08 3C188005 */  lui   $t8, %hi(a3d) # $t8, 0x8005
/* 0DB8FC 7F0A8F0C 2718CE88 */  addiu $t8, %lo(a3d) # addiu $t8, $t8, -0x3178
/* 0DB900 7F0A8F10 A1610004 */  sb    $at, 4($t3)
/* 0DB904 7F0A8F14 8D010000 */  lw    $at, ($t0)
/* 0DB908 7F0A8F18 27AF0060 */  addiu $t7, $sp, 0x60
/* 0DB90C 7F0A8F1C 02002025 */  move  $a0, $s0
/* 0DB910 7F0A8F20 AF210000 */  sw    $at, ($t9)
/* 0DB914 7F0A8F24 91010004 */  lbu   $at, 4($t0)
/* 0DB918 7F0A8F28 A3210004 */  sb    $at, 4($t9)
/* 0DB91C 7F0A8F2C 8DA10000 */  lw    $at, ($t5)
/* 0DB920 7F0A8F30 AD810000 */  sw    $at, ($t4)
/* 0DB924 7F0A8F34 91A10004 */  lbu   $at, 4($t5)
/* 0DB928 7F0A8F38 A1810004 */  sb    $at, 4($t4)
/* 0DB92C 7F0A8F3C 8F010000 */  lw    $at, ($t8)
/* 0DB930 7F0A8F40 ADE10000 */  sw    $at, ($t7)
/* 0DB934 7F0A8F44 97010004 */  lhu   $at, 4($t8)
/* 0DB938 7F0A8F48 A5E10004 */  sh    $at, 4($t7)
/* 0DB93C 7F0A8F4C 0FC2B016 */  jal   microcode_constructor
/* 0DB940 7F0A8F50 AFA00050 */   sw    $zero, 0x50($sp)
/* 0DB944 7F0A8F54 00408025 */  move  $s0, $v0
/* 0DB948 7F0A8F58 00002025 */  move  $a0, $zero
/* 0DB94C 7F0A8F5C 0C002C20 */  jal   joyGetButtons
/* 0DB950 7F0A8F60 24050020 */   li    $a1, 32
/* 0DB954 7F0A8F64 1040002C */  beqz  $v0, .L7F0A9018
/* 0DB958 7F0A8F68 3C0A8007 */   lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8007
/* 0DB95C 7F0A8F6C 8D4A8BC0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0DB960 7F0A8F70 3C048004 */  lui   $a0, %hi(D_800409DC+8)
/* 0DB964 7F0A8F74 8D4B2A50 */  lw    $t3, 0x2a50($t2)
/* 0DB968 7F0A8F78 000B6080 */  sll   $t4, $t3, 2
/* 0DB96C 7F0A8F7C 018B6021 */  addu  $t4, $t4, $t3
/* 0DB970 7F0A8F80 000C6080 */  sll   $t4, $t4, 2
/* 0DB974 7F0A8F84 008C2021 */  addu  $a0, $a0, $t4
/* 0DB978 7F0A8F88 0FC304AE */  jal   langGet
/* 0DB97C 7F0A8F8C 9484A634 */   lhu   $a0, %lo(D_800409DC+8)($a0)
/* 0DB980 7F0A8F90 3C080070 */  lui   $t0, (0x007000A0 >> 16) # lui $t0, 0x70
/* 0DB984 7F0A8F94 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DB988 7F0A8F98 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DB98C 7F0A8F9C 350800A0 */  ori   $t0, (0x007000A0 & 0xFFFF) # ori $t0, $t0, 0xa0
/* 0DB990 7F0A8FA0 240DFFFF */  li    $t5, -1
/* 0DB994 7F0A8FA4 240E0001 */  li    $t6, 1
/* 0DB998 7F0A8FA8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DB99C 7F0A8FAC AFAD0010 */  sw    $t5, 0x10($sp)
/* 0DB9A0 7F0A8FB0 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DB9A4 7F0A8FB4 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DB9A8 7F0A8FB8 02002025 */  move  $a0, $s0
/* 0DB9AC 7F0A8FBC 24050032 */  li    $a1, 50
/* 0DB9B0 7F0A8FC0 2406005C */  li    $a2, 92
/* 0DB9B4 7F0A8FC4 00403825 */  move  $a3, $v0
/* 0DB9B8 7F0A8FC8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DB9BC 7F0A8FCC AFA00020 */  sw    $zero, 0x20($sp)
/* 0DB9C0 7F0A8FD0 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DB9C4 7F0A8FD4 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DB9C8 7F0A8FD8 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0DB9CC 7F0A8FDC 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DB9D0 7F0A8FE0 3C0A8004 */  lui   $t2, %hi(D_800409DC+9)
/* 0DB9D4 7F0A8FE4 3401AC01 */  li    $at, 44033
/* 0DB9D8 7F0A8FE8 8DF82A50 */  lw    $t8, 0x2a50($t7)
/* 0DB9DC 7F0A8FEC 00408025 */  move  $s0, $v0
/* 0DB9E0 7F0A8FF0 240B0001 */  li    $t3, 1
/* 0DB9E4 7F0A8FF4 00184880 */  sll   $t1, $t8, 2
/* 0DB9E8 7F0A8FF8 01384821 */  addu  $t1, $t1, $t8
/* 0DB9EC 7F0A8FFC 00094880 */  sll   $t1, $t1, 2
/* 0DB9F0 7F0A9000 01495021 */  addu  $t2, $t2, $t1
/* 0DB9F4 7F0A9004 954AA634 */  lhu   $t2, %lo(D_800409DC+8)($t2)
/* 0DB9F8 7F0A9008 1541001F */  bne   $t2, $at, .L7F0A9088
/* 0DB9FC 7F0A900C 00000000 */   nop   
/* 0DBA00 7F0A9010 1000001D */  b     .L7F0A9088
/* 0DBA04 7F0A9014 AFAB0050 */   sw    $t3, 0x50($sp)
.L7F0A9018:
/* 0DBA08 7F0A9018 3C0C8007 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0DBA0C 7F0A901C 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DBA10 7F0A9020 3C048004 */  lui   $a0, %hi(D_800409DC+8)
/* 0DBA14 7F0A9024 8D8D2A50 */  lw    $t5, 0x2a50($t4)
/* 0DBA18 7F0A9028 000D7080 */  sll   $t6, $t5, 2
/* 0DBA1C 7F0A902C 01CD7021 */  addu  $t6, $t6, $t5
/* 0DBA20 7F0A9030 000E7080 */  sll   $t6, $t6, 2
/* 0DBA24 7F0A9034 008E2021 */  addu  $a0, $a0, $t6
/* 0DBA28 7F0A9038 0FC304AE */  jal   langGet
/* 0DBA2C 7F0A903C 9484A634 */   lhu   $a0, %lo(D_800409DC+8)($a0)
/* 0DBA30 7F0A9040 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DBA34 7F0A9044 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DBA38 7F0A9048 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DBA3C 7F0A904C 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DBA40 7F0A9050 2419FFFF */  li    $t9, -1
/* 0DBA44 7F0A9054 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DBA48 7F0A9058 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DBA4C 7F0A905C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DBA50 7F0A9060 02002025 */  move  $a0, $s0
/* 0DBA54 7F0A9064 24050032 */  li    $a1, 50
/* 0DBA58 7F0A9068 2406005C */  li    $a2, 92
/* 0DBA5C 7F0A906C 00403825 */  move  $a3, $v0
/* 0DBA60 7F0A9070 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DBA64 7F0A9074 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBA68 7F0A9078 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBA6C 7F0A907C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBA70 7F0A9080 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBA74 7F0A9084 00408025 */  move  $s0, $v0
.L7F0A9088:
/* 0DBA78 7F0A9088 3C098004 */  lui   $t1, %hi(controller_options_index) # $t1, 0x8004
/* 0DBA7C 7F0A908C 8D29A5E8 */  lw    $t1, %lo(controller_options_index)($t1)
/* 0DBA80 7F0A9090 2418007A */  li    $t8, 122
/* 0DBA84 7F0A9094 24010001 */  li    $at, 1
/* 0DBA88 7F0A9098 1521000A */  bne   $t1, $at, .L7F0A90C4
/* 0DBA8C 7F0A909C AFB8004C */   sw    $t8, 0x4c($sp)
/* 0DBA90 7F0A90A0 3C0A8004 */  lui   $t2, %hi(watch_item_is_actively_selected) # $t2, 0x8004
/* 0DBA94 7F0A90A4 8D4AA5F8 */  lw    $t2, %lo(watch_item_is_actively_selected)($t2)
/* 0DBA98 7F0A90A8 00002025 */  move  $a0, $zero
/* 0DBA9C 7F0A90AC 11400005 */  beqz  $t2, .L7F0A90C4
/* 0DBAA0 7F0A90B0 00000000 */   nop   
/* 0DBAA4 7F0A90B4 0C002C20 */  jal   joyGetButtons
/* 0DBAA8 7F0A90B8 24050F00 */   li    $a1, 3840
/* 0DBAAC 7F0A90BC 1440001E */  bnez  $v0, .L7F0A9138
/* 0DBAB0 7F0A90C0 00002025 */   move  $a0, $zero
.L7F0A90C4:
/* 0DBAB4 7F0A90C4 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0DBAB8 7F0A90C8 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DBABC 7F0A90CC 3C048004 */  lui   $a0, %hi(D_800409DC+14)
/* 0DBAC0 7F0A90D0 8D6C2A50 */  lw    $t4, 0x2a50($t3)
/* 0DBAC4 7F0A90D4 000C6880 */  sll   $t5, $t4, 2
/* 0DBAC8 7F0A90D8 01AC6821 */  addu  $t5, $t5, $t4
/* 0DBACC 7F0A90DC 000D6880 */  sll   $t5, $t5, 2
/* 0DBAD0 7F0A90E0 008D2021 */  addu  $a0, $a0, $t5
/* 0DBAD4 7F0A90E4 0FC304AE */  jal   langGet
/* 0DBAD8 7F0A90E8 9484A63A */   lhu   $a0, %lo(D_800409DC+14)($a0)
/* 0DBADC 7F0A90EC 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DBAE0 7F0A90F0 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DBAE4 7F0A90F4 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DBAE8 7F0A90F8 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DBAEC 7F0A90FC 2408FFFF */  li    $t0, -1
/* 0DBAF0 7F0A9100 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DBAF4 7F0A9104 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DBAF8 7F0A9108 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DBAFC 7F0A910C 02002025 */  move  $a0, $s0
/* 0DBB00 7F0A9110 24050032 */  li    $a1, 50
/* 0DBB04 7F0A9114 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBB08 7F0A9118 00403825 */  move  $a3, $v0
/* 0DBB0C 7F0A911C AFA00014 */  sw    $zero, 0x14($sp)
/* 0DBB10 7F0A9120 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBB14 7F0A9124 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBB18 7F0A9128 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBB1C 7F0A912C AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBB20 7F0A9130 10000051 */  b     .L7F0A9278
/* 0DBB24 7F0A9134 00408025 */   move  $s0, $v0
.L7F0A9138:
/* 0DBB28 7F0A9138 0C002C20 */  jal   joyGetButtons
/* 0DBB2C 7F0A913C 24050800 */   li    $a1, 2048
/* 0DBB30 7F0A9140 10400014 */  beqz  $v0, .L7F0A9194
/* 0DBB34 7F0A9144 00002025 */   move  $a0, $zero
/* 0DBB38 7F0A9148 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0DBB3C 7F0A914C 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DBB40 7F0A9150 3C0A8004 */  lui   $t2, %hi(D_800409DC+14)
/* 0DBB44 7F0A9154 3401AC05 */  li    $at, 44037
/* 0DBB48 7F0A9158 8DF82A50 */  lw    $t8, 0x2a50($t7)
/* 0DBB4C 7F0A915C 8FA700AC */  lw    $a3, 0xac($sp)
/* 0DBB50 7F0A9160 00184880 */  sll   $t1, $t8, 2
/* 0DBB54 7F0A9164 01384821 */  addu  $t1, $t1, $t8
/* 0DBB58 7F0A9168 00094880 */  sll   $t1, $t1, 2
/* 0DBB5C 7F0A916C 01495021 */  addu  $t2, $t2, $t1
/* 0DBB60 7F0A9170 954AA63A */  lhu   $t2, %lo(D_800409DC+14)($t2)
/* 0DBB64 7F0A9174 15410005 */  bne   $t2, $at, .L7F0A918C
/* 0DBB68 7F0A9178 00000000 */   nop   
/* 0DBB6C 7F0A917C 0FC304AE */  jal   langGet
/* 0DBB70 7F0A9180 3404AC30 */   li    $a0, 44080
/* 0DBB74 7F0A9184 10000001 */  b     .L7F0A918C
/* 0DBB78 7F0A9188 00403825 */   move  $a3, $v0
.L7F0A918C:
/* 0DBB7C 7F0A918C 10000027 */  b     .L7F0A922C
/* 0DBB80 7F0A9190 AFA70058 */   sw    $a3, 0x58($sp)
.L7F0A9194:
/* 0DBB84 7F0A9194 0C002C20 */  jal   joyGetButtons
/* 0DBB88 7F0A9198 24050400 */   li    $a1, 1024
/* 0DBB8C 7F0A919C 10400014 */  beqz  $v0, .L7F0A91F0
/* 0DBB90 7F0A91A0 00002025 */   move  $a0, $zero
/* 0DBB94 7F0A91A4 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0DBB98 7F0A91A8 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DBB9C 7F0A91AC 3C0E8004 */  lui   $t6, %hi(D_800409DC+14)
/* 0DBBA0 7F0A91B0 3401AC05 */  li    $at, 44037
/* 0DBBA4 7F0A91B4 8D6C2A50 */  lw    $t4, 0x2a50($t3)
/* 0DBBA8 7F0A91B8 8FA700A8 */  lw    $a3, 0xa8($sp)
/* 0DBBAC 7F0A91BC 000C6880 */  sll   $t5, $t4, 2
/* 0DBBB0 7F0A91C0 01AC6821 */  addu  $t5, $t5, $t4
/* 0DBBB4 7F0A91C4 000D6880 */  sll   $t5, $t5, 2
/* 0DBBB8 7F0A91C8 01CD7021 */  addu  $t6, $t6, $t5
/* 0DBBBC 7F0A91CC 95CEA63A */  lhu   $t6, %lo(D_800409DC+14)($t6)
/* 0DBBC0 7F0A91D0 15C10005 */  bne   $t6, $at, .L7F0A91E8
/* 0DBBC4 7F0A91D4 00000000 */   nop   
/* 0DBBC8 7F0A91D8 0FC304AE */  jal   langGet
/* 0DBBCC 7F0A91DC 3404AC31 */   li    $a0, 44081
/* 0DBBD0 7F0A91E0 10000001 */  b     .L7F0A91E8
/* 0DBBD4 7F0A91E4 00403825 */   move  $a3, $v0
.L7F0A91E8:
/* 0DBBD8 7F0A91E8 10000010 */  b     .L7F0A922C
/* 0DBBDC 7F0A91EC AFA70058 */   sw    $a3, 0x58($sp)
.L7F0A91F0:
/* 0DBBE0 7F0A91F0 0C002C20 */  jal   joyGetButtons
/* 0DBBE4 7F0A91F4 24050200 */   li    $a1, 512
/* 0DBBE8 7F0A91F8 10400005 */  beqz  $v0, .L7F0A9210
/* 0DBBEC 7F0A91FC 00002025 */   move  $a0, $zero
/* 0DBBF0 7F0A9200 0FC304AE */  jal   langGet
/* 0DBBF4 7F0A9204 3404AC2F */   li    $a0, 44079
/* 0DBBF8 7F0A9208 10000008 */  b     .L7F0A922C
/* 0DBBFC 7F0A920C AFA20058 */   sw    $v0, 0x58($sp)
.L7F0A9210:
/* 0DBC00 7F0A9210 0C002C20 */  jal   joyGetButtons
/* 0DBC04 7F0A9214 24050100 */   li    $a1, 256
/* 0DBC08 7F0A9218 50400005 */  beql  $v0, $zero, .L7F0A9230
/* 0DBC0C 7F0A921C 3C0F0070 */   lui   $t7, 0x70
/* 0DBC10 7F0A9220 0FC304AE */  jal   langGet
/* 0DBC14 7F0A9224 3404AC2E */   li    $a0, 44078
/* 0DBC18 7F0A9228 AFA20058 */  sw    $v0, 0x58($sp)
.L7F0A922C:
/* 0DBC1C 7F0A922C 3C0F0070 */  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
.L7F0A9230:
/* 0DBC20 7F0A9230 3C180030 */  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
/* 0DBC24 7F0A9234 371800B0 */  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DBC28 7F0A9238 35EF00A0 */  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
/* 0DBC2C 7F0A923C 2408FFFF */  li    $t0, -1
/* 0DBC30 7F0A9240 24190001 */  li    $t9, 1
/* 0DBC34 7F0A9244 8FA70058 */  lw    $a3, 0x58($sp)
/* 0DBC38 7F0A9248 AFB90014 */  sw    $t9, 0x14($sp)
/* 0DBC3C 7F0A924C AFA80010 */  sw    $t0, 0x10($sp)
/* 0DBC40 7F0A9250 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DBC44 7F0A9254 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DBC48 7F0A9258 02002025 */  move  $a0, $s0
/* 0DBC4C 7F0A925C 24050032 */  li    $a1, 50
/* 0DBC50 7F0A9260 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBC54 7F0A9264 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBC58 7F0A9268 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBC5C 7F0A926C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBC60 7F0A9270 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBC64 7F0A9274 00408025 */  move  $s0, $v0
.L7F0A9278:
/* 0DBC68 7F0A9278 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0DBC6C 7F0A927C 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0DBC70 7F0A9280 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DBC74 7F0A9284 252A001E */  addiu $t2, $t1, 0x1e
/* 0DBC78 7F0A9288 AFAA004C */  sw    $t2, 0x4c($sp)
/* 0DBC7C 7F0A928C 8D6C2A50 */  lw    $t4, 0x2a50($t3)
/* 0DBC80 7F0A9290 3C048004 */  lui   $a0, %hi(D_800409DC+16)
/* 0DBC84 7F0A9294 000C6880 */  sll   $t5, $t4, 2
/* 0DBC88 7F0A9298 01AC6821 */  addu  $t5, $t5, $t4
/* 0DBC8C 7F0A929C 000D6880 */  sll   $t5, $t5, 2
/* 0DBC90 7F0A92A0 008D2021 */  addu  $a0, $a0, $t5
/* 0DBC94 7F0A92A4 0FC304AE */  jal   langGet
/* 0DBC98 7F0A92A8 9484A63C */   lhu   $a0, %lo(D_800409DC+16)($a0)
/* 0DBC9C 7F0A92AC 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DBCA0 7F0A92B0 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DBCA4 7F0A92B4 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DBCA8 7F0A92B8 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DBCAC 7F0A92BC 2408FFFF */  li    $t0, -1
/* 0DBCB0 7F0A92C0 AFA80018 */  sw    $t0, 0x18($sp)
/* 0DBCB4 7F0A92C4 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DBCB8 7F0A92C8 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DBCBC 7F0A92CC 02002025 */  move  $a0, $s0
/* 0DBCC0 7F0A92D0 24050032 */  li    $a1, 50
/* 0DBCC4 7F0A92D4 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBCC8 7F0A92D8 00403825 */  move  $a3, $v0
/* 0DBCCC 7F0A92DC AFA00014 */  sw    $zero, 0x14($sp)
/* 0DBCD0 7F0A92E0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBCD4 7F0A92E4 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBCD8 7F0A92E8 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBCDC 7F0A92EC AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBCE0 7F0A92F0 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0DBCE4 7F0A92F4 00408025 */  move  $s0, $v0
/* 0DBCE8 7F0A92F8 00002025 */  move  $a0, $zero
/* 0DBCEC 7F0A92FC 25F8001E */  addiu $t8, $t7, 0x1e
/* 0DBCF0 7F0A9300 AFB8004C */  sw    $t8, 0x4c($sp)
/* 0DBCF4 7F0A9304 0C002C20 */  jal   joyGetButtons
/* 0DBCF8 7F0A9308 24052000 */   li    $a1, 8192
/* 0DBCFC 7F0A930C 1040002D */  beqz  $v0, .L7F0A93C4
/* 0DBD00 7F0A9310 3C0B8007 */   lui   $t3, %hi(g_CurrentPlayer)
/* 0DBD04 7F0A9314 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0DBD08 7F0A9318 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DBD0C 7F0A931C 3C048004 */  lui   $a0, %hi(D_800409DC+0x6)
/* 0DBD10 7F0A9320 8D2A2A50 */  lw    $t2, 0x2a50($t1)
/* 0DBD14 7F0A9324 000A5880 */  sll   $t3, $t2, 2
/* 0DBD18 7F0A9328 016A5821 */  addu  $t3, $t3, $t2
/* 0DBD1C 7F0A932C 000B5880 */  sll   $t3, $t3, 2
/* 0DBD20 7F0A9330 008B2021 */  addu  $a0, $a0, $t3
/* 0DBD24 7F0A9334 0FC304AE */  jal   langGet
/* 0DBD28 7F0A9338 9484A632 */   lhu   $a0, %lo(D_800409DC+0x6)($a0)
/* 0DBD2C 7F0A933C 3C0E0070 */  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
/* 0DBD30 7F0A9340 3C080030 */  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
/* 0DBD34 7F0A9344 350800B0 */  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DBD38 7F0A9348 35CE00A0 */  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
/* 0DBD3C 7F0A934C 240CFFFF */  li    $t4, -1
/* 0DBD40 7F0A9350 240D0001 */  li    $t5, 1
/* 0DBD44 7F0A9354 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DBD48 7F0A9358 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DBD4C 7F0A935C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DBD50 7F0A9360 AFA80024 */  sw    $t0, 0x24($sp)
/* 0DBD54 7F0A9364 02002025 */  move  $a0, $s0
/* 0DBD58 7F0A9368 24050032 */  li    $a1, 50
/* 0DBD5C 7F0A936C 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBD60 7F0A9370 00403825 */  move  $a3, $v0
/* 0DBD64 7F0A9374 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBD68 7F0A9378 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBD6C 7F0A937C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBD70 7F0A9380 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBD74 7F0A9384 3C198007 */  lui   $t9, %hi(g_CurrentPlayer) # $t9, 0x8007
/* 0DBD78 7F0A9388 8F398BC0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0DBD7C 7F0A938C 3C098004 */  lui   $t1, %hi(D_800409DC+6)
/* 0DBD80 7F0A9390 3401AC01 */  li    $at, 44033
/* 0DBD84 7F0A9394 8F2F2A50 */  lw    $t7, 0x2a50($t9)
/* 0DBD88 7F0A9398 00408025 */  move  $s0, $v0
/* 0DBD8C 7F0A939C 240A0001 */  li    $t2, 1
/* 0DBD90 7F0A93A0 000FC080 */  sll   $t8, $t7, 2
/* 0DBD94 7F0A93A4 030FC021 */  addu  $t8, $t8, $t7
/* 0DBD98 7F0A93A8 0018C080 */  sll   $t8, $t8, 2
/* 0DBD9C 7F0A93AC 01384821 */  addu  $t1, $t1, $t8
/* 0DBDA0 7F0A93B0 9529A632 */  lhu   $t1, %lo(D_800409DC+6)($t1)
/* 0DBDA4 7F0A93B4 5521001F */  bnel  $t1, $at, .Leu7F0A9434
/* 0DBDA8 7F0A93B8 8FAF004C */   lw    $t7, 0x4c($sp)
/* 0DBDAC 7F0A93BC 1000001C */  b     .L7F0A9430
/* 0DBDB0 7F0A93C0 AFAA0050 */   sw    $t2, 0x50($sp)
.L7F0A93C4:
/* 0DBDB4 7F0A93C4 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DBDB8 7F0A93C8 3C048004 */  lui   $a0, %hi(D_800409DC+6)
/* 0DBDBC 7F0A93CC 8D6C2A50 */  lw    $t4, 0x2a50($t3)
/* 0DBDC0 7F0A93D0 000C6880 */  sll   $t5, $t4, 2
/* 0DBDC4 7F0A93D4 01AC6821 */  addu  $t5, $t5, $t4
/* 0DBDC8 7F0A93D8 000D6880 */  sll   $t5, $t5, 2
/* 0DBDCC 7F0A93DC 008D2021 */  addu  $a0, $a0, $t5
/* 0DBDD0 7F0A93E0 0FC304AE */  jal   langGet
/* 0DBDD4 7F0A93E4 9484A632 */   lhu   $a0, %lo(D_800409DC+6)($a0)
/* 0DBDD8 7F0A93E8 3C0E00AA */  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
/* 0DBDDC 7F0A93EC 3C190030 */  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
/* 0DBDE0 7F0A93F0 373900B0 */  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DBDE4 7F0A93F4 35CE00B0 */  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DBDE8 7F0A93F8 2408FFFF */  li    $t0, -1
/* 0DBDEC 7F0A93FC AFA80018 */  sw    $t0, 0x18($sp)
/* 0DBDF0 7F0A9400 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DBDF4 7F0A9404 AFB90024 */  sw    $t9, 0x24($sp)
/* 0DBDF8 7F0A9408 02002025 */  move  $a0, $s0
/* 0DBDFC 7F0A940C 24050032 */  li    $a1, 50
/* 0DBE00 7F0A9410 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBE04 7F0A9414 00403825 */  move  $a3, $v0
/* 0DBE08 7F0A9418 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DBE0C 7F0A941C AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBE10 7F0A9420 AFA00020 */  sw    $zero, 0x20($sp)
/* 0DBE14 7F0A9424 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBE18 7F0A9428 AFA00028 */   sw    $zero, 0x28($sp)
/* 0DBE1C 7F0A942C 00408025 */  move  $s0, $v0
.L7F0A9430:
/* 0DBE20 7F0A9430 8FAF004C */  lw    $t7, 0x4c($sp)
.Leu7F0A9434:
/* 0DBE24 7F0A9434 00002025 */  move  $a0, $zero
/* 0DBE28 7F0A9438 24050010 */  li    $a1, 16
/* 0DBE2C 7F0A943C 25F8FFA6 */  addiu $t8, $t7, -0x5a
/* 0DBE30 7F0A9440 0C002C20 */  jal   joyGetButtons
/* 0DBE34 7F0A9444 AFB8004C */   sw    $t8, 0x4c($sp)
/* 0DBE38 7F0A9448 1040002E */  beqz  $v0, .L7F0A9504
/* 0DBE3C 7F0A944C 3C0C8007 */   lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0DBE40 7F0A9450 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0DBE44 7F0A9454 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DBE48 7F0A9458 3C048004 */  lui   $a0, %hi(D_800409DC+10)
/* 0DBE4C 7F0A945C 8D2A2A50 */  lw    $t2, 0x2a50($t1)
/* 0DBE50 7F0A9460 000A5880 */  sll   $t3, $t2, 2
/* 0DBE54 7F0A9464 016A5821 */  addu  $t3, $t3, $t2
/* 0DBE58 7F0A9468 000B5880 */  sll   $t3, $t3, 2
/* 0DBE5C 7F0A946C 008B2021 */  addu  $a0, $a0, $t3
/* 0DBE60 7F0A9470 0FC304AE */  jal   langGet
/* 0DBE64 7F0A9474 9484A636 */   lhu   $a0, %lo(D_800409DC+10)($a0)
/* 0DBE68 7F0A9478 3C0E0070 */  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
/* 0DBE6C 7F0A947C 3C080030 */  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
/* 0DBE70 7F0A9480 350800B0 */  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DBE74 7F0A9484 35CE00A0 */  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
/* 0DBE78 7F0A9488 240CFFFF */  li    $t4, -1
/* 0DBE7C 7F0A948C 240D0001 */  li    $t5, 1
/* 0DBE80 7F0A9490 24190001 */  li    $t9, 1
/* 0DBE84 7F0A9494 AFB90028 */  sw    $t9, 0x28($sp)
/* 0DBE88 7F0A9498 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DBE8C 7F0A949C AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DBE90 7F0A94A0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DBE94 7F0A94A4 AFA80024 */  sw    $t0, 0x24($sp)
/* 0DBE98 7F0A94A8 02002025 */  move  $a0, $s0
/* 0DBE9C 7F0A94AC 2405010E */  li    $a1, 270
/* 0DBEA0 7F0A94B0 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBEA4 7F0A94B4 00403825 */  move  $a3, $v0
/* 0DBEA8 7F0A94B8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBEAC 7F0A94BC 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBEB0 7F0A94C0 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DBEB4 7F0A94C4 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0DBEB8 7F0A94C8 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0DBEBC 7F0A94CC 3C0A8004 */  lui   $t2, %hi(D_800409DC+10)
/* 0DBEC0 7F0A94D0 3401AC01 */  li    $at, 44033
/* 0DBEC4 7F0A94D4 8DF82A50 */  lw    $t8, 0x2a50($t7)
/* 0DBEC8 7F0A94D8 00408025 */  move  $s0, $v0
/* 0DBECC 7F0A94DC 240B0001 */  li    $t3, 1
/* 0DBED0 7F0A94E0 00184880 */  sll   $t1, $t8, 2
/* 0DBED4 7F0A94E4 01384821 */  addu  $t1, $t1, $t8
/* 0DBED8 7F0A94E8 00094880 */  sll   $t1, $t1, 2
/* 0DBEDC 7F0A94EC 01495021 */  addu  $t2, $t2, $t1
/* 0DBEE0 7F0A94F0 954AA636 */  lhu   $t2, %lo(D_800409DC+10)($t2)
/* 0DBEE4 7F0A94F4 55410020 */  bnel  $t2, $at, .L7F0A9578
/* 0DBEE8 7F0A94F8 8FA9004C */   lw    $t1, 0x4c($sp)
/* 0DBEEC 7F0A94FC 1000001D */  b     .L7F0A9574
/* 0DBEF0 7F0A9500 AFAB0050 */   sw    $t3, 0x50($sp)
.L7F0A9504:
/* 0DBEF4 7F0A9504 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DBEF8 7F0A9508 3C048004 */  lui   $a0, %hi(D_800409DC+10)
/* 0DBEFC 7F0A950C 8D8D2A50 */  lw    $t5, 0x2a50($t4)
/* 0DBF00 7F0A9510 000D7080 */  sll   $t6, $t5, 2
/* 0DBF04 7F0A9514 01CD7021 */  addu  $t6, $t6, $t5
/* 0DBF08 7F0A9518 000E7080 */  sll   $t6, $t6, 2
/* 0DBF0C 7F0A951C 008E2021 */  addu  $a0, $a0, $t6
/* 0DBF10 7F0A9520 0FC304AE */  jal   langGet
/* 0DBF14 7F0A9524 9484A636 */   lhu   $a0, %lo(D_800409DC+10)($a0)
/* 0DBF18 7F0A9528 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DBF1C 7F0A952C 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DBF20 7F0A9530 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DBF24 7F0A9534 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DBF28 7F0A9538 2419FFFF */  li    $t9, -1
/* 0DBF2C 7F0A953C 24180001 */  li    $t8, 1
/* 0DBF30 7F0A9540 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DBF34 7F0A9544 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DBF38 7F0A9548 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DBF3C 7F0A954C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DBF40 7F0A9550 02002025 */  move  $a0, $s0
/* 0DBF44 7F0A9554 2405010E */  li    $a1, 270
/* 0DBF48 7F0A9558 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DBF4C 7F0A955C 00403825 */  move  $a3, $v0
/* 0DBF50 7F0A9560 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DBF54 7F0A9564 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DBF58 7F0A9568 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DBF5C 7F0A956C AFA00020 */   sw    $zero, 0x20($sp)
/* 0DBF60 7F0A9570 00408025 */  move  $s0, $v0
.L7F0A9574:
/* 0DBF64 7F0A9574 8FA9004C */  lw    $t1, 0x4c($sp)
.L7F0A9578:
/* 0DBF68 7F0A9578 3C0B8004 */  lui   $t3, %hi(controller_options_index) # $t3, 0x8004
/* 0DBF6C 7F0A957C 8D6BA5E8 */  lw    $t3, %lo(controller_options_index)($t3)
/* 0DBF70 7F0A9580 24010001 */  li    $at, 1
/* 0DBF74 7F0A9584 252A001E */  addiu $t2, $t1, 0x1e
/* 0DBF78 7F0A9588 1561000A */  bne   $t3, $at, .L7F0A95B4
/* 0DBF7C 7F0A958C AFAA004C */   sw    $t2, 0x4c($sp)
/* 0DBF80 7F0A9590 3C0C8004 */  lui   $t4, %hi(watch_item_is_actively_selected) # $t4, 0x8004
/* 0DBF84 7F0A9594 8D8CA5F8 */  lw    $t4, %lo(watch_item_is_actively_selected)($t4)
/* 0DBF88 7F0A9598 00002025 */  move  $a0, $zero
/* 0DBF8C 7F0A959C 11800005 */  beqz  $t4, .L7F0A95B4
/* 0DBF90 7F0A95A0 00000000 */   nop   
/* 0DBF94 7F0A95A4 0C002C20 */  jal   joyGetButtons
/* 0DBF98 7F0A95A8 2405000F */   li    $a1, 15
/* 0DBF9C 7F0A95AC 1440001F */  bnez  $v0, .L7F0A962C
/* 0DBFA0 7F0A95B0 00002025 */   move  $a0, $zero
.L7F0A95B4:
/* 0DBFA4 7F0A95B4 3C0D8007 */  lui   $t5, %hi(g_CurrentPlayer) # $t5, 0x8007
/* 0DBFA8 7F0A95B8 8DAD8BC0 */  lw    $t5, %lo(g_CurrentPlayer)($t5)
/* 0DBFAC 7F0A95BC 3C048004 */  lui   $a0, %hi(D_800409DC+12)
/* 0DBFB0 7F0A95C0 8DAE2A50 */  lw    $t6, 0x2a50($t5)
/* 0DBFB4 7F0A95C4 000E4080 */  sll   $t0, $t6, 2
/* 0DBFB8 7F0A95C8 010E4021 */  addu  $t0, $t0, $t6
/* 0DBFBC 7F0A95CC 00084080 */  sll   $t0, $t0, 2
/* 0DBFC0 7F0A95D0 00882021 */  addu  $a0, $a0, $t0
/* 0DBFC4 7F0A95D4 0FC304AE */  jal   langGet
/* 0DBFC8 7F0A95D8 9484A638 */   lhu   $a0, %lo(D_800409DC+12)($a0)
/* 0DBFCC 7F0A95DC 3C1900AA */  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
/* 0DBFD0 7F0A95E0 3C180030 */  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
/* 0DBFD4 7F0A95E4 371800B0 */  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DBFD8 7F0A95E8 373900B0 */  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DBFDC 7F0A95EC 240FFFFF */  li    $t7, -1
/* 0DBFE0 7F0A95F0 24090001 */  li    $t1, 1
/* 0DBFE4 7F0A95F4 AFA90028 */  sw    $t1, 0x28($sp)
/* 0DBFE8 7F0A95F8 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0DBFEC 7F0A95FC AFB90010 */  sw    $t9, 0x10($sp)
/* 0DBFF0 7F0A9600 AFB80024 */  sw    $t8, 0x24($sp)
/* 0DBFF4 7F0A9604 02002025 */  move  $a0, $s0
/* 0DBFF8 7F0A9608 2405010E */  li    $a1, 270
/* 0DBFFC 7F0A960C 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC000 7F0A9610 00403825 */  move  $a3, $v0
/* 0DC004 7F0A9614 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DC008 7F0A9618 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC00C 7F0A961C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC010 7F0A9620 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC014 7F0A9624 10000076 */  b     .L7F0A9800
/* 0DC018 7F0A9628 00408025 */   move  $s0, $v0
.L7F0A962C:
/* 0DC01C 7F0A962C 0C002C20 */  jal   joyGetButtons
/* 0DC020 7F0A9630 2405000F */   li    $a1, 15
/* 0DC024 7F0A9634 244AFFFF */  addiu $t2, $v0, -1
/* 0DC028 7F0A9638 004A5824 */  and   $t3, $v0, $t2
/* 0DC02C 7F0A963C 15600054 */  bnez  $t3, .L7F0A9790
/* 0DC030 7F0A9640 3C088007 */   lui   $t0, %hi(g_CurrentPlayer)
/* 0DC034 7F0A9644 00002025 */  move  $a0, $zero
/* 0DC038 7F0A9648 0C002C20 */  jal   joyGetButtons
/* 0DC03C 7F0A964C 24050008 */   li    $a1, 8
/* 0DC040 7F0A9650 10400014 */  beqz  $v0, .L7F0A96A4
/* 0DC044 7F0A9654 00002025 */   move  $a0, $zero
/* 0DC048 7F0A9658 3C0C8007 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0DC04C 7F0A965C 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DC050 7F0A9660 3C088004 */  lui   $t0, %hi(D_800409DC+12)
/* 0DC054 7F0A9664 3401AC05 */  li    $at, 44037
/* 0DC058 7F0A9668 8D8D2A50 */  lw    $t5, 0x2a50($t4)
/* 0DC05C 7F0A966C 8FA700AC */  lw    $a3, 0xac($sp)
/* 0DC060 7F0A9670 000D7080 */  sll   $t6, $t5, 2
/* 0DC064 7F0A9674 01CD7021 */  addu  $t6, $t6, $t5
/* 0DC068 7F0A9678 000E7080 */  sll   $t6, $t6, 2
/* 0DC06C 7F0A967C 010E4021 */  addu  $t0, $t0, $t6
/* 0DC070 7F0A9680 9508A638 */  lhu   $t0, %lo(D_800409DC+12)($t0)
/* 0DC074 7F0A9684 15010005 */  bne   $t0, $at, .L7F0A969C
/* 0DC078 7F0A9688 00000000 */   nop   
/* 0DC07C 7F0A968C 0FC304AE */  jal   langGet
/* 0DC080 7F0A9690 3404AC30 */   li    $a0, 44080
/* 0DC084 7F0A9694 10000001 */  b     .L7F0A969C
/* 0DC088 7F0A9698 00403825 */   move  $a3, $v0
.L7F0A969C:
/* 0DC08C 7F0A969C 10000027 */  b     .L7F0A973C
/* 0DC090 7F0A96A0 AFA7005C */   sw    $a3, 0x5c($sp)
.L7F0A96A4:
/* 0DC094 7F0A96A4 0C002C20 */  jal   joyGetButtons
/* 0DC098 7F0A96A8 24050004 */   li    $a1, 4
/* 0DC09C 7F0A96AC 10400014 */  beqz  $v0, .L7F0A9700
/* 0DC0A0 7F0A96B0 00002025 */   move  $a0, $zero
/* 0DC0A4 7F0A96B4 3C198007 */  lui   $t9, %hi(g_CurrentPlayer) # $t9, 0x8007
/* 0DC0A8 7F0A96B8 8F398BC0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0DC0AC 7F0A96BC 3C098004 */  lui   $t1, %hi(D_800409DC+12)
/* 0DC0B0 7F0A96C0 3401AC05 */  li    $at, 44037
/* 0DC0B4 7F0A96C4 8F2F2A50 */  lw    $t7, 0x2a50($t9)
/* 0DC0B8 7F0A96C8 8FA700A8 */  lw    $a3, 0xa8($sp)
/* 0DC0BC 7F0A96CC 000FC080 */  sll   $t8, $t7, 2
/* 0DC0C0 7F0A96D0 030FC021 */  addu  $t8, $t8, $t7
/* 0DC0C4 7F0A96D4 0018C080 */  sll   $t8, $t8, 2
/* 0DC0C8 7F0A96D8 01384821 */  addu  $t1, $t1, $t8
/* 0DC0CC 7F0A96DC 9529A638 */  lhu   $t1, %lo(D_800409DC+12)($t1)
/* 0DC0D0 7F0A96E0 15210005 */  bne   $t1, $at, .L7F0A96F8
/* 0DC0D4 7F0A96E4 00000000 */   nop   
/* 0DC0D8 7F0A96E8 0FC304AE */  jal   langGet
/* 0DC0DC 7F0A96EC 3404AC31 */   li    $a0, 44081
/* 0DC0E0 7F0A96F0 10000001 */  b     .L7F0A96F8
/* 0DC0E4 7F0A96F4 00403825 */   move  $a3, $v0
.L7F0A96F8:
/* 0DC0E8 7F0A96F8 10000010 */  b     .L7F0A973C
/* 0DC0EC 7F0A96FC AFA7005C */   sw    $a3, 0x5c($sp)
.L7F0A9700:
/* 0DC0F0 7F0A9700 0C002C20 */  jal   joyGetButtons
/* 0DC0F4 7F0A9704 24050002 */   li    $a1, 2
/* 0DC0F8 7F0A9708 10400005 */  beqz  $v0, .L7F0A9720
/* 0DC0FC 7F0A970C 00002025 */   move  $a0, $zero
/* 0DC100 7F0A9710 0FC304AE */  jal   langGet
/* 0DC104 7F0A9714 3404AC2F */   li    $a0, 44079
/* 0DC108 7F0A9718 10000008 */  b     .L7F0A973C
/* 0DC10C 7F0A971C AFA2005C */   sw    $v0, 0x5c($sp)
.L7F0A9720:
/* 0DC110 7F0A9720 0C002C20 */  jal   joyGetButtons
/* 0DC114 7F0A9724 24050001 */   li    $a1, 1
/* 0DC118 7F0A9728 50400005 */  beql  $v0, $zero, .L7F0A9740
/* 0DC11C 7F0A972C 3C0C0070 */   lui   $t4, 0x70
/* 0DC120 7F0A9730 0FC304AE */  jal   langGet
/* 0DC124 7F0A9734 3404AC2E */   li    $a0, 44078
/* 0DC128 7F0A9738 AFA2005C */  sw    $v0, 0x5c($sp)
.L7F0A973C:
/* 0DC12C 7F0A973C 3C0C0070 */  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
.L7F0A9740:
/* 0DC130 7F0A9740 3C0D0030 */  lui   $t5, (0x003000B0 >> 16) # lui $t5, 0x30
/* 0DC134 7F0A9744 35AD00B0 */  ori   $t5, (0x003000B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0DC138 7F0A9748 358C00A0 */  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
/* 0DC13C 7F0A974C 240AFFFF */  li    $t2, -1
/* 0DC140 7F0A9750 240B0001 */  li    $t3, 1
/* 0DC144 7F0A9754 240E0001 */  li    $t6, 1
/* 0DC148 7F0A9758 8FA7005C */  lw    $a3, 0x5c($sp)
/* 0DC14C 7F0A975C AFAE0028 */  sw    $t6, 0x28($sp)
/* 0DC150 7F0A9760 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0DC154 7F0A9764 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0DC158 7F0A9768 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0DC15C 7F0A976C AFAD0024 */  sw    $t5, 0x24($sp)
/* 0DC160 7F0A9770 02002025 */  move  $a0, $s0
/* 0DC164 7F0A9774 2405010E */  li    $a1, 270
/* 0DC168 7F0A9778 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC16C 7F0A977C AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC170 7F0A9780 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC174 7F0A9784 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC178 7F0A9788 1000001D */  b     .L7F0A9800
/* 0DC17C 7F0A978C 00408025 */   move  $s0, $v0
.L7F0A9790:
/* 0DC180 7F0A9790 8D088BC0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0DC184 7F0A9794 3C048004 */  lui   $a0, %hi(D_800409DC+12)
/* 0DC188 7F0A9798 8D192A50 */  lw    $t9, 0x2a50($t0)
/* 0DC18C 7F0A979C 00197880 */  sll   $t7, $t9, 2
/* 0DC190 7F0A97A0 01F97821 */  addu  $t7, $t7, $t9
/* 0DC194 7F0A97A4 000F7880 */  sll   $t7, $t7, 2
/* 0DC198 7F0A97A8 008F2021 */  addu  $a0, $a0, $t7
/* 0DC19C 7F0A97AC 0FC304AE */  jal   langGet
/* 0DC1A0 7F0A97B0 9484A638 */   lhu   $a0, %lo(D_800409DC+12)($a0)
/* 0DC1A4 7F0A97B4 3C1800AA */  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
/* 0DC1A8 7F0A97B8 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DC1AC 7F0A97BC 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DC1B0 7F0A97C0 371800B0 */  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0DC1B4 7F0A97C4 2409FFFF */  li    $t1, -1
/* 0DC1B8 7F0A97C8 240B0001 */  li    $t3, 1
/* 0DC1BC 7F0A97CC AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DC1C0 7F0A97D0 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DC1C4 7F0A97D4 AFB80010 */  sw    $t8, 0x10($sp)
/* 0DC1C8 7F0A97D8 AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DC1CC 7F0A97DC 02002025 */  move  $a0, $s0
/* 0DC1D0 7F0A97E0 2405010E */  li    $a1, 270
/* 0DC1D4 7F0A97E4 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC1D8 7F0A97E8 00403825 */  move  $a3, $v0
/* 0DC1DC 7F0A97EC AFA00014 */  sw    $zero, 0x14($sp)
/* 0DC1E0 7F0A97F0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC1E4 7F0A97F4 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC1E8 7F0A97F8 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC1EC 7F0A97FC 00408025 */  move  $s0, $v0
.L7F0A9800:
/* 0DC1F0 7F0A9800 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0DC1F4 7F0A9804 00002025 */  move  $a0, $zero
/* 0DC1F8 7F0A9808 24054000 */  li    $a1, 16384
/* 0DC1FC 7F0A980C 258D001E */  addiu $t5, $t4, 0x1e
/* 0DC200 7F0A9810 0C002C20 */  jal   joyGetButtons
/* 0DC204 7F0A9814 AFAD004C */   sw    $t5, 0x4c($sp)
/* 0DC208 7F0A9818 10400020 */  beqz  $v0, .L7F0A989C
/* 0DC20C 7F0A981C 3C0C8007 */   lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0DC210 7F0A9820 3C0E8007 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0DC214 7F0A9824 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0DC218 7F0A9828 3C048004 */  lui   $a0, %hi(D_800409DC+4)
/* 0DC21C 7F0A982C 8DC82A50 */  lw    $t0, 0x2a50($t6)
/* 0DC220 7F0A9830 0008C880 */  sll   $t9, $t0, 2
/* 0DC224 7F0A9834 0328C821 */  addu  $t9, $t9, $t0
/* 0DC228 7F0A9838 0019C880 */  sll   $t9, $t9, 2
/* 0DC22C 7F0A983C 00992021 */  addu  $a0, $a0, $t9
/* 0DC230 7F0A9840 0FC304AE */  jal   langGet
/* 0DC234 7F0A9844 9484A630 */   lhu   $a0, %lo(D_800409DC+4)($a0)
/* 0DC238 7F0A9848 3C090070 */  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
/* 0DC23C 7F0A984C 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DC240 7F0A9850 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DC244 7F0A9854 352900A0 */  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
/* 0DC248 7F0A9858 240FFFFF */  li    $t7, -1
/* 0DC24C 7F0A985C 24180001 */  li    $t8, 1
/* 0DC250 7F0A9860 240B0001 */  li    $t3, 1
/* 0DC254 7F0A9864 AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DC258 7F0A9868 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DC25C 7F0A986C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DC260 7F0A9870 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DC264 7F0A9874 AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DC268 7F0A9878 02002025 */  move  $a0, $s0
/* 0DC26C 7F0A987C 2405010E */  li    $a1, 270
/* 0DC270 7F0A9880 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC274 7F0A9884 00403825 */  move  $a3, $v0
/* 0DC278 7F0A9888 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC27C 7F0A988C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC280 7F0A9890 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC284 7F0A9894 1000001D */  b     .L7F0A990C
/* 0DC288 7F0A9898 00408025 */   move  $s0, $v0
.L7F0A989C:
/* 0DC28C 7F0A989C 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DC290 7F0A98A0 3C048004 */  lui   $a0, %hi(D_800409DC+4)
/* 0DC294 7F0A98A4 8D8D2A50 */  lw    $t5, 0x2a50($t4)
/* 0DC298 7F0A98A8 000D7080 */  sll   $t6, $t5, 2
/* 0DC29C 7F0A98AC 01CD7021 */  addu  $t6, $t6, $t5
/* 0DC2A0 7F0A98B0 000E7080 */  sll   $t6, $t6, 2
/* 0DC2A4 7F0A98B4 008E2021 */  addu  $a0, $a0, $t6
/* 0DC2A8 7F0A98B8 0FC304AE */  jal   langGet
/* 0DC2AC 7F0A98BC 9484A630 */   lhu   $a0, %lo(D_800409DC+4)($a0)
/* 0DC2B0 7F0A98C0 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DC2B4 7F0A98C4 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DC2B8 7F0A98C8 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DC2BC 7F0A98CC 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DC2C0 7F0A98D0 2419FFFF */  li    $t9, -1
/* 0DC2C4 7F0A98D4 24180001 */  li    $t8, 1
/* 0DC2C8 7F0A98D8 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DC2CC 7F0A98DC AFB90018 */  sw    $t9, 0x18($sp)
/* 0DC2D0 7F0A98E0 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DC2D4 7F0A98E4 AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DC2D8 7F0A98E8 02002025 */  move  $a0, $s0
/* 0DC2DC 7F0A98EC 2405010E */  li    $a1, 270
/* 0DC2E0 7F0A98F0 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC2E4 7F0A98F4 00403825 */  move  $a3, $v0
/* 0DC2E8 7F0A98F8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DC2EC 7F0A98FC AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC2F0 7F0A9900 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC2F4 7F0A9904 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC2F8 7F0A9908 00408025 */  move  $s0, $v0
.L7F0A990C:
/* 0DC2FC 7F0A990C 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0DC300 7F0A9910 00002025 */  move  $a0, $zero
/* 0DC304 7F0A9914 34058000 */  li    $a1, 32768
/* 0DC308 7F0A9918 252A001E */  addiu $t2, $t1, 0x1e
/* 0DC30C 7F0A991C 0C002C20 */  jal   joyGetButtons
/* 0DC310 7F0A9920 AFAA004C */   sw    $t2, 0x4c($sp)
/* 0DC314 7F0A9924 10400020 */  beqz  $v0, .L7F0A99A8
/* 0DC318 7F0A9928 3C098007 */   lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0DC31C 7F0A992C 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0DC320 7F0A9930 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0DC324 7F0A9934 3C048004 */  lui   $a0, %hi(D_800409DC+2)
/* 0DC328 7F0A9938 8D6C2A50 */  lw    $t4, 0x2a50($t3)
/* 0DC32C 7F0A993C 000C6880 */  sll   $t5, $t4, 2
/* 0DC330 7F0A9940 01AC6821 */  addu  $t5, $t5, $t4
/* 0DC334 7F0A9944 000D6880 */  sll   $t5, $t5, 2
/* 0DC338 7F0A9948 008D2021 */  addu  $a0, $a0, $t5
/* 0DC33C 7F0A994C 0FC304AE */  jal   langGet
/* 0DC340 7F0A9950 9484A62E */   lhu   $a0, %lo(D_800409DC+2)($a0)
/* 0DC344 7F0A9954 3C190070 */  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
/* 0DC348 7F0A9958 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DC34C 7F0A995C 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DC350 7F0A9960 373900A0 */  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0DC354 7F0A9964 240EFFFF */  li    $t6, -1
/* 0DC358 7F0A9968 24080001 */  li    $t0, 1
/* 0DC35C 7F0A996C 24180001 */  li    $t8, 1
/* 0DC360 7F0A9970 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DC364 7F0A9974 AFA80014 */  sw    $t0, 0x14($sp)
/* 0DC368 7F0A9978 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DC36C 7F0A997C AFB90018 */  sw    $t9, 0x18($sp)
/* 0DC370 7F0A9980 AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DC374 7F0A9984 02002025 */  move  $a0, $s0
/* 0DC378 7F0A9988 2405010E */  li    $a1, 270
/* 0DC37C 7F0A998C 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC380 7F0A9990 00403825 */  move  $a3, $v0
/* 0DC384 7F0A9994 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC388 7F0A9998 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC38C 7F0A999C AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC390 7F0A99A0 1000001D */  b     .L7F0A9A18
/* 0DC394 7F0A99A4 00408025 */   move  $s0, $v0
.L7F0A99A8:
/* 0DC398 7F0A99A8 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0DC39C 7F0A99AC 3C048004 */  lui   $a0, %hi(D_800409DC+2)
/* 0DC3A0 7F0A99B0 8D2A2A50 */  lw    $t2, 0x2a50($t1)
/* 0DC3A4 7F0A99B4 000A5880 */  sll   $t3, $t2, 2
/* 0DC3A8 7F0A99B8 016A5821 */  addu  $t3, $t3, $t2
/* 0DC3AC 7F0A99BC 000B5880 */  sll   $t3, $t3, 2
/* 0DC3B0 7F0A99C0 008B2021 */  addu  $a0, $a0, $t3
/* 0DC3B4 7F0A99C4 0FC304AE */  jal   langGet
/* 0DC3B8 7F0A99C8 9484A62E */   lhu   $a0, %lo(D_800409DC+2)($a0)
/* 0DC3BC 7F0A99CC 3C0C00AA */  lui   $t4, (0x00AA00B0 >> 16) # lui $t4, 0xaa
/* 0DC3C0 7F0A99D0 3C0E0030 */  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
/* 0DC3C4 7F0A99D4 35CE00B0 */  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DC3C8 7F0A99D8 358C00B0 */  ori   $t4, (0x00AA00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0DC3CC 7F0A99DC 240DFFFF */  li    $t5, -1
/* 0DC3D0 7F0A99E0 24080001 */  li    $t0, 1
/* 0DC3D4 7F0A99E4 AFA80028 */  sw    $t0, 0x28($sp)
/* 0DC3D8 7F0A99E8 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0DC3DC 7F0A99EC AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DC3E0 7F0A99F0 AFAE0024 */  sw    $t6, 0x24($sp)
/* 0DC3E4 7F0A99F4 02002025 */  move  $a0, $s0
/* 0DC3E8 7F0A99F8 2405010E */  li    $a1, 270
/* 0DC3EC 7F0A99FC 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0DC3F0 7F0A9A00 00403825 */  move  $a3, $v0
/* 0DC3F4 7F0A9A04 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DC3F8 7F0A9A08 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC3FC 7F0A9A0C 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC400 7F0A9A10 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC404 7F0A9A14 00408025 */  move  $s0, $v0
.L7F0A9A18:
/* 0DC408 7F0A9A18 8FB90050 */  lw    $t9, 0x50($sp)
/* 0DC40C 7F0A9A1C 3C0C8007 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0DC410 7F0A9A20 13200018 */  beqz  $t9, .L7F0A9A84
/* 0DC414 7F0A9A24 00000000 */   nop   
/* 0DC418 7F0A9A28 0FC304AE */  jal   langGet
/* 0DC41C 7F0A9A2C 3404AC08 */   li    $a0, 44040
/* 0DC420 7F0A9A30 3C090070 */  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
/* 0DC424 7F0A9A34 3C0A0030 */  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
/* 0DC428 7F0A9A38 354A00B0 */  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0DC42C 7F0A9A3C 352900A0 */  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
/* 0DC430 7F0A9A40 240FFFFF */  li    $t7, -1
/* 0DC434 7F0A9A44 24180001 */  li    $t8, 1
/* 0DC438 7F0A9A48 240B0001 */  li    $t3, 1
/* 0DC43C 7F0A9A4C AFAB0028 */  sw    $t3, 0x28($sp)
/* 0DC440 7F0A9A50 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DC444 7F0A9A54 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DC448 7F0A9A58 AFA90018 */  sw    $t1, 0x18($sp)
/* 0DC44C 7F0A9A5C AFAA0024 */  sw    $t2, 0x24($sp)
/* 0DC450 7F0A9A60 02002025 */  move  $a0, $s0
/* 0DC454 7F0A9A64 240500FA */  li    $a1, 250
/* 0DC458 7F0A9A68 240600E1 */  li    $a2, 225
/* 0DC45C 7F0A9A6C 00403825 */  move  $a3, $v0
/* 0DC460 7F0A9A70 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC464 7F0A9A74 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC468 7F0A9A78 AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC46C 7F0A9A7C 1000001D */  b     .L7F0A9AF4
/* 0DC470 7F0A9A80 00408025 */   move  $s0, $v0
.L7F0A9A84:
/* 0DC474 7F0A9A84 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0DC478 7F0A9A88 3C048004 */  lui   $a0, %hi(D_800409DC+18)
/* 0DC47C 7F0A9A8C 8D8D2A50 */  lw    $t5, 0x2a50($t4)
/* 0DC480 7F0A9A90 000D7080 */  sll   $t6, $t5, 2
/* 0DC484 7F0A9A94 01CD7021 */  addu  $t6, $t6, $t5
/* 0DC488 7F0A9A98 000E7080 */  sll   $t6, $t6, 2
/* 0DC48C 7F0A9A9C 008E2021 */  addu  $a0, $a0, $t6
/* 0DC490 7F0A9AA0 0FC304AE */  jal   langGet
/* 0DC494 7F0A9AA4 9484A63E */   lhu   $a0, %lo(D_800409DC+18)($a0)
/* 0DC498 7F0A9AA8 3C0800AA */  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
/* 0DC49C 7F0A9AAC 3C0F0030 */  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
/* 0DC4A0 7F0A9AB0 35EF00B0 */  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0DC4A4 7F0A9AB4 350800B0 */  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
/* 0DC4A8 7F0A9AB8 2419FFFF */  li    $t9, -1
/* 0DC4AC 7F0A9ABC 24180001 */  li    $t8, 1
/* 0DC4B0 7F0A9AC0 AFB80028 */  sw    $t8, 0x28($sp)
/* 0DC4B4 7F0A9AC4 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DC4B8 7F0A9AC8 AFA80010 */  sw    $t0, 0x10($sp)
/* 0DC4BC 7F0A9ACC AFAF0024 */  sw    $t7, 0x24($sp)
/* 0DC4C0 7F0A9AD0 02002025 */  move  $a0, $s0
/* 0DC4C4 7F0A9AD4 240500FA */  li    $a1, 250
/* 0DC4C8 7F0A9AD8 240600E1 */  li    $a2, 225
/* 0DC4CC 7F0A9ADC 00403825 */  move  $a3, $v0
/* 0DC4D0 7F0A9AE0 AFA00014 */  sw    $zero, 0x14($sp)
/* 0DC4D4 7F0A9AE4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0DC4D8 7F0A9AE8 0FC2A1B6 */  jal   sub_GAME_7F0A9398
/* 0DC4DC 7F0A9AEC AFA00020 */   sw    $zero, 0x20($sp)
/* 0DC4E0 7F0A9AF0 00408025 */  move  $s0, $v0
.L7F0A9AF4:
/* 0DC4E4 7F0A9AF4 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DC4E8 7F0A9AF8 02001025 */  move  $v0, $s0
/* 0DC4EC 7F0A9AFC 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DC4F0 7F0A9B00 03E00008 */  jr    $ra
/* 0DC4F4 7F0A9B04 27BD00B0 */   addiu $sp, $sp, 0xb0
)
#endif
#endif



Gfx *display_text_buttons_dual_control(Gfx *gdl)
{
    s32 textptr_aux;

    gdl = microcode_constructor(gdl);

    if (joyGetButtons(PLAYER_1, A_BUTTON))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_WEAPTEXT, langGet(TEXT(LOPTIONS, 0x03)), -1, 1, 0x7000A0, 0, 0, 0x3000B0, 0); //weapon
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_WEAPTEXT, langGet(TEXT(LOPTIONS, 0x03)), 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 0); //weapon
    }

    if (joyGetButtons(PLAYER_1, B_BUTTON))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_ACTIONTEXT, langGet(TEXT(LOPTIONS, 0x02)), -1, 1, 0x7000A0, 0, 0, 0x3000B0, 0); //action
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_ACTIONTEXT, langGet(TEXT(LOPTIONS, 0x02)), 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 0); //action
    }

    if ((g_CurrentPlayer->cur_player_control_type_0 == 4) || (g_CurrentPlayer->cur_player_control_type_0 == 5))
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x00)); //fire
    }
    else
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x01)); //aim
    }

    if (joyGetButtons(PLAYER_1, Z_TRIG))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_5, textptr_aux, -1, 1, 0x7000A0, 0, 0, 0x3000B0, 0);
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_5, textptr_aux, 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 0);
    }

    if ((g_CurrentPlayer->cur_player_control_type_0 == 4) || (g_CurrentPlayer->cur_player_control_type_0 == 6))
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x05)); //move
    }
    else
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x06)); //look
    }

    gdl = sub_GAME_7F0A9398(gdl, 0x5A, YOFFSET_4, textptr_aux, 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 0);

    if (joyGetButtons(1, A_BUTTON))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_WEAPTEXT, langGet(TEXT(LOPTIONS, 0x03)), -1, 1, 0x7000A0, 0, 0, 0x3000B0, 1); //weapon
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_WEAPTEXT, langGet(TEXT(LOPTIONS, 0x03)), 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 1); //weapon
    }

    if (joyGetButtons(1, B_BUTTON))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_ACTIONTEXT, langGet(TEXT(LOPTIONS, 0x02)), -1, 1, 0x7000A0, 0, 0, 0x3000B0, 1); //action
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_ACTIONTEXT, langGet(TEXT(LOPTIONS, 0x02)), 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 1); //action
    }

    if ((g_CurrentPlayer->cur_player_control_type_0 == 4) || (g_CurrentPlayer->cur_player_control_type_0 == 5))
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x01)); //aim
    }
    else
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x00)); //fire
    }

    if (joyGetButtons(1, Z_TRIG))
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_5, textptr_aux, -1, 1, 0x7000A0, 0, 0, 0x3000B0, 1);
    }
    else
    {
        gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_5, textptr_aux, 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 1);
    }

    if ((g_CurrentPlayer->cur_player_control_type_0 == 4) || (g_CurrentPlayer->cur_player_control_type_0 == 6))
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x06)); //look
    }
    else
    {
        textptr_aux = langGet(TEXT(LOPTIONS, 0x05)); //move
    }

    gdl = sub_GAME_7F0A9398(gdl, 0xE6, YOFFSET_4, textptr_aux, 0xAA00B0, 0, -1, 0, 0, 0x3000B0, 1);
    return gdl;
}




#ifdef NONMATCHING
void sub_GAME_7F0AADC0(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80058550
.word 0x40c90fdb /*6.2831855*/
glabel D_80058554
.word 0x3f490fdb /*0.78539819*/
glabel D_80058558
.word 0x43f78000 /*495.0*/
glabel D_8005855C
.word 0x453b8000  /*3000.0*/
glabel D_80058560
.word 0x40c90fdb /*6.2831855*/
glabel D_80058564
.word 0x3f490fdb /*0.78539819*/
glabel D_80058568
.word 0xc3fc8000 /*-505.0*/
glabel D_8005856C
.word 0x453b8000  /*3000.0*/
.text
glabel sub_GAME_7F0AADC0
/* 0DF8F0 7F0AADC0 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 0DF8F4 7F0AADC4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0DF8F8 7F0AADC8 AFB00030 */  sw    $s0, 0x30($sp)
/* 0DF8FC 7F0AADCC 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0DF900 7F0AADD0 00808025 */   move  $s0, $a0
/* 0DF904 7F0AADD4 3C0F8004 */  lui   $t7, %hi(D_80040B5C)
/* 0DF908 7F0AADD8 AFA2053C */  sw    $v0, 0x53c($sp)
/* 0DF90C 7F0AADDC 25EF0B5C */  addiu $t7, %lo(D_80040B5C) # addiu $t7, $t7, 0xb5c
/* 0DF910 7F0AADE0 8DE10000 */  lw    $at, ($t7)
/* 0DF914 7F0AADE4 27AE0370 */  addiu $t6, $sp, 0x370
/* 0DF918 7F0AADE8 8DE80004 */  lw    $t0, 4($t7)
/* 0DF91C 7F0AADEC ADC10000 */  sw    $at, ($t6)
/* 0DF920 7F0AADF0 8DE10008 */  lw    $at, 8($t7)
/* 0DF924 7F0AADF4 3C0B8004 */  lui   $t3, %hi(D_80040B68)
/* 0DF928 7F0AADF8 ADC80004 */  sw    $t0, 4($t6)
/* 0DF92C 7F0AADFC ADC10008 */  sw    $at, 8($t6)
/* 0DF930 7F0AAE00 24090001 */  li    $t1, 1
/* 0DF934 7F0AAE04 256B0B68 */  addiu $t3, %lo(D_80040B68) # addiu $t3, $t3, 0xb68
/* 0DF938 7F0AAE08 A3A002E3 */  sb    $zero, 0x2e3($sp)
/* 0DF93C 7F0AAE0C A3A902E2 */  sb    $t1, 0x2e2($sp)
/* 0DF940 7F0AAE10 257900D8 */  addiu $t9, $t3, 0xd8
/* 0DF944 7F0AAE14 27AA0204 */  addiu $t2, $sp, 0x204
.L7F0AAE18:
/* 0DF948 7F0AAE18 8D610000 */  lw    $at, ($t3)
/* 0DF94C 7F0AAE1C 256B000C */  addiu $t3, $t3, 0xc
/* 0DF950 7F0AAE20 254A000C */  addiu $t2, $t2, 0xc
/* 0DF954 7F0AAE24 AD41FFF4 */  sw    $at, -0xc($t2)
/* 0DF958 7F0AAE28 8D61FFF8 */  lw    $at, -8($t3)
/* 0DF95C 7F0AAE2C AD41FFF8 */  sw    $at, -8($t2)
/* 0DF960 7F0AAE30 8D61FFFC */  lw    $at, -4($t3)
/* 0DF964 7F0AAE34 1579FFF8 */  bne   $t3, $t9, .L7F0AAE18
/* 0DF968 7F0AAE38 AD41FFFC */   sw    $at, -4($t2)
/* 0DF96C 7F0AAE3C 8D610000 */  lw    $at, ($t3)
/* 0DF970 7F0AAE40 3C0E8004 */  lui   $t6, %hi(D_80040C44)
/* 0DF974 7F0AAE44 25CE0C44 */  addiu $t6, %lo(D_80040C44) # addiu $t6, $t6, 0xc44
/* 0DF978 7F0AAE48 25C900D8 */  addiu $t1, $t6, 0xd8
/* 0DF97C 7F0AAE4C 27B80128 */  addiu $t8, $sp, 0x128
/* 0DF980 7F0AAE50 AD410000 */  sw    $at, ($t2)
.L7F0AAE54:
/* 0DF984 7F0AAE54 8DC10000 */  lw    $at, ($t6)
/* 0DF988 7F0AAE58 25CE000C */  addiu $t6, $t6, 0xc
/* 0DF98C 7F0AAE5C 2718000C */  addiu $t8, $t8, 0xc
/* 0DF990 7F0AAE60 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0DF994 7F0AAE64 8DC1FFF8 */  lw    $at, -8($t6)
/* 0DF998 7F0AAE68 AF01FFF8 */  sw    $at, -8($t8)
/* 0DF99C 7F0AAE6C 8DC1FFFC */  lw    $at, -4($t6)
/* 0DF9A0 7F0AAE70 15C9FFF8 */  bne   $t6, $t1, .L7F0AAE54
/* 0DF9A4 7F0AAE74 AF01FFFC */   sw    $at, -4($t8)
/* 0DF9A8 7F0AAE78 8DC10000 */  lw    $at, ($t6)
/* 0DF9AC 7F0AAE7C 3C0C8004 */  lui   $t4, %hi(D_80040D20)
/* 0DF9B0 7F0AAE80 258C0D20 */  addiu $t4, %lo(D_80040D20) # addiu $t4, $t4, 0xd20
/* 0DF9B4 7F0AAE84 258A00D8 */  addiu $t2, $t4, 0xd8
/* 0DF9B8 7F0AAE88 27AD004C */  addiu $t5, $sp, 0x4c
/* 0DF9BC 7F0AAE8C AF010000 */  sw    $at, ($t8)
.L7F0AAE90:
/* 0DF9C0 7F0AAE90 8D810000 */  lw    $at, ($t4)
/* 0DF9C4 7F0AAE94 258C000C */  addiu $t4, $t4, 0xc
/* 0DF9C8 7F0AAE98 25AD000C */  addiu $t5, $t5, 0xc
/* 0DF9CC 7F0AAE9C ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0DF9D0 7F0AAEA0 8D81FFF8 */  lw    $at, -8($t4)
/* 0DF9D4 7F0AAEA4 ADA1FFF8 */  sw    $at, -8($t5)
/* 0DF9D8 7F0AAEA8 8D81FFFC */  lw    $at, -4($t4)
/* 0DF9DC 7F0AAEAC 158AFFF8 */  bne   $t4, $t2, .L7F0AAE90
/* 0DF9E0 7F0AAEB0 ADA1FFFC */   sw    $at, -4($t5)
/* 0DF9E4 7F0AAEB4 8D810000 */  lw    $at, ($t4)
/* 0DF9E8 7F0AAEB8 3C058004 */  lui   $a1, %hi(D_80040B2C)
/* 0DF9EC 7F0AAEBC 3C068004 */  lui   $a2, %hi(D_80040B28)
/* 0DF9F0 7F0AAEC0 3C078004 */  lui   $a3, %hi(D_80040B24)
/* 0DF9F4 7F0AAEC4 24E70B24 */  addiu $a3, %lo(D_80040B24) # addiu $a3, $a3, 0xb24
/* 0DF9F8 7F0AAEC8 24C60B28 */  addiu $a2, %lo(D_80040B28) # addiu $a2, $a2, 0xb28
/* 0DF9FC 7F0AAECC 24A50B2C */  addiu $a1, %lo(D_80040B2C) # addiu $a1, $a1, 0xb2c
/* 0DFA00 7F0AAED0 00002025 */  move  $a0, $zero
/* 0DFA04 7F0AAED4 0FC2A5A1 */  jal   sub_GAME_7F0A9684
/* 0DFA08 7F0AAED8 ADA10000 */   sw    $at, ($t5)
/* 0DFA0C 7F0AAEDC 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0DFA10 7F0AAEE0 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0DFA14 7F0AAEE4 3C088005 */  lui   $t0, %hi(speedgraphframes)
/* 0DFA18 7F0AAEE8 8D088498 */  lw    $t0, %lo(speedgraphframes)($t0)
/* 0DFA1C 7F0AAEEC 3C018004 */  lui   $at, %hi(D_80040B28)
/* 0DFA20 7F0AAEF0 C4240B28 */  lwc1  $f4, %lo(D_80040B28)($at)
/* 0DFA24 7F0AAEF4 44883000 */  mtc1  $t0, $f6
/* 0DFA28 7F0AAEF8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DFA2C 7F0AAEFC 44818000 */  mtc1  $at, $f16
/* 0DFA30 7F0AAF00 46803220 */  cvt.s.w $f8, $f6
/* 0DFA34 7F0AAF04 3C028004 */  lui   $v0, %hi(D_80040B24)
/* 0DFA38 7F0AAF08 24420B24 */  addiu $v0, %lo(D_80040B24) # addiu $v0, $v0, 0xb24
/* 0DFA3C 7F0AAF0C C4460000 */  lwc1  $f6, ($v0)
/* 0DFA40 7F0AAF10 46082282 */  mul.s $f10, $f4, $f8
/* 0DFA44 7F0AAF14 00000000 */  nop
/* 0DFA48 7F0AAF18 46105482 */  mul.s $f18, $f10, $f16
/* 0DFA4C 7F0AAF1C 46123100 */  add.s $f4, $f6, $f18
/* 0DFA50 7F0AAF20 E4440000 */  swc1  $f4, ($v0)
/* 0DFA54 7F0AAF24 0FC29A8B */  jal   sub_GAME_7F0A6A2C
/* 0DFA58 7F0AAF28 C44C0000 */   lwc1  $f12, ($v0)
/* 0DFA5C 7F0AAF2C 3C018004 */  lui   $at, %hi(D_80040B24)
/* 0DFA60 7F0AAF30 E4200B24 */  swc1  $f0, %lo(D_80040B24)($at)
/* 0DFA64 7F0AAF34 C42C0B24 */  lwc1  $f12, %lo(D_80040B24)($at)
/* 0DFA68 7F0AAF38 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 0DFA6C 7F0AAF3C 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0DFA70 7F0AAF40 3C0F8004 */  lui   $t7, %hi(watch_item_is_actively_selected)
/* 0DFA74 7F0AAF44 8DEF09A8 */  lw    $t7, %lo(watch_item_is_actively_selected)($t7)
/* 0DFA78 7F0AAF48 11E00016 */  beqz  $t7, .L7F0AAFA4
/* 0DFA7C 7F0AAF4C 3C098004 */   lui   $t1, %hi(controller_options_index)
/* 0DFA80 7F0AAF50 8D290998 */  lw    $t1, %lo(controller_options_index)($t1)
/* 0DFA84 7F0AAF54 24010001 */  li    $at, 1
/* 0DFA88 7F0AAF58 15210012 */  bne   $t1, $at, .L7F0AAFA4
/* 0DFA8C 7F0AAF5C 00000000 */   nop
/* 0DFA90 7F0AAF60 0C00307F */  jal   joyGetStickY
/* 0DFA94 7F0AAF64 00002025 */   move  $a0, $zero
/* 0DFA98 7F0AAF68 44824000 */  mtc1  $v0, $f8
/* 0DFA9C 7F0AAF6C 3C018004 */  lui   $at, %hi(D_80040B20)
/* 0DFAA0 7F0AAF70 C42C0B20 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0DFAA4 7F0AAF74 468042A0 */  cvt.s.w $f10, $f8
/* 0DFAA8 7F0AAF78 3C018006 */  lui   $at, %hi(D_80058550)
/* 0DFAAC 7F0AAF7C C4308550 */  lwc1  $f16, %lo(D_80058550)($at)
/* 0DFAB0 7F0AAF80 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DFAB4 7F0AAF84 44819000 */  mtc1  $at, $f18
/* 0DFAB8 7F0AAF88 3C064080 */  lui   $a2, 0x4080
/* 0DFABC 7F0AAF8C 46105182 */  mul.s $f6, $f10, $f16
/* 0DFAC0 7F0AAF90 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DFAC4 7F0AAF94 46123383 */   div.s $f14, $f6, $f18
/* 0DFAC8 7F0AAF98 3C018004 */  lui   $at, %hi(D_80040B20)
/* 0DFACC 7F0AAF9C 10000008 */  b     .L7F0AAFC0
/* 0DFAD0 7F0AAFA0 E4200B20 */   swc1  $f0, %lo(D_80040B20)($at)
.L7F0AAFA4:
/* 0DFAD4 7F0AAFA4 3C018004 */  lui   $at, %hi(D_80040B20)
/* 0DFAD8 7F0AAFA8 44807000 */  mtc1  $zero, $f14
/* 0DFADC 7F0AAFAC C42C0B20 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0DFAE0 7F0AAFB0 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DFAE4 7F0AAFB4 3C064080 */   lui   $a2, 0x4080
/* 0DFAE8 7F0AAFB8 3C018004 */  lui   $at, %hi(D_80040B20)
/* 0DFAEC 7F0AAFBC E4200B20 */  swc1  $f0, %lo(D_80040B20)($at)
.L7F0AAFC0:
/* 0DFAF0 7F0AAFC0 3C018004 */  lui   $at, %hi(D_80040B20)
/* 0DFAF4 7F0AAFC4 C4240B20 */  lwc1  $f4, %lo(D_80040B20)($at)
/* 0DFAF8 7F0AAFC8 3C018006 */  lui   $at, %hi(D_80058554)
/* 0DFAFC 7F0AAFCC C42A8554 */  lwc1  $f10, %lo(D_80058554)($at)
/* 0DFB00 7F0AAFD0 46002207 */  neg.s $f8, $f4
/* 0DFB04 7F0AAFD4 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DFB08 7F0AAFD8 0FC1615C */  jal   matrix_4x4_set_rotation_around_x
/* 0DFB0C 7F0AAFDC 460A4301 */   sub.s $f12, $f8, $f10
/* 0DFB10 7F0AAFE0 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0DFB14 7F0AAFE4 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0DFB18 7F0AAFE8 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFB1C 7F0AAFEC 27A6043C */   addiu $a2, $sp, 0x43c
/* 0DFB20 7F0AAFF0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DFB24 7F0AAFF4 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DFB28 7F0AAFF8 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFB2C 7F0AAFFC 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0DFB30 7F0AB000 27A40370 */  addiu $a0, $sp, 0x370
/* 0DFB34 7F0AB004 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 0DFB38 7F0AB008 27A5043C */   addiu $a1, $sp, 0x43c
/* 0DFB3C 7F0AB00C 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DFB40 7F0AB010 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0DFB44 7F0AB014 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFB48 7F0AB018 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0DFB4C 7F0AB01C 0FC2935D */  jal   controllerCheckDualControllerTypesAllowed
/* 0DFB50 7F0AB020 00000000 */   nop
/* 0DFB54 7F0AB024 10400018 */  beqz  $v0, .L7F0AB088
/* 0DFB58 7F0AB028 3C01C0A0 */   lui   $at, 0xc0a0
/* 0DFB5C 7F0AB02C 3C018006 */  lui    $at, %hi(D_80058558)
/* 0DFB60 7F0AB030 C4208558 */  lwc1  $f0, %lo(D_80058558)($at)
/* 0DFB64 7F0AB034 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0DFB68 7F0AB038 44816000 */  mtc1  $at, $f12
/* 0DFB6C 7F0AB03C 44801000 */  mtc1  $zero, $f2
/* 0DFB70 7F0AB040 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DFB74 7F0AB044 44818000 */  mtc1  $at, $f16
/* 0DFB78 7F0AB048 27AE0128 */  addiu $t6, $sp, 0x128
/* 0DFB7C 7F0AB04C 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0DFB80 7F0AB050 44050000 */  mfc1  $a1, $f0
/* 0DFB84 7F0AB054 44076000 */  mfc1  $a3, $f12
/* 0DFB88 7F0AB058 AFAE02E8 */  sw    $t6, 0x2e8($sp)
/* 0DFB8C 7F0AB05C 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0DFB90 7F0AB060 27A4032C */  addiu $a0, $sp, 0x32c
/* 0DFB94 7F0AB064 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DFB98 7F0AB068 E7AC0018 */  swc1  $f12, 0x18($sp)
/* 0DFB9C 7F0AB06C E7A20014 */  swc1  $f2, 0x14($sp)
/* 0DFBA0 7F0AB070 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DFBA4 7F0AB074 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0DFBA8 7F0AB078 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0DFBAC 7F0AB07C E7B00024 */   swc1  $f16, 0x24($sp)
/* 0DFBB0 7F0AB080 10000017 */  b     .L7F0AB0E0
/* 0DFBB4 7F0AB084 27A4032C */   addiu $a0, $sp, 0x32c
.L7F0AB088:
/* 0DFBB8 7F0AB088 44810000 */  mtc1  $at, $f0
/* 0DFBBC 7F0AB08C 3C01C328 */  li    $at, 0xC3280000 # -168.000000
/* 0DFBC0 7F0AB090 44811000 */  mtc1  $at, $f2
/* 0DFBC4 7F0AB094 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DFBC8 7F0AB098 44814000 */  mtc1  $at, $f8
/* 0DFBCC 7F0AB09C 44803000 */  mtc1  $zero, $f6
/* 0DFBD0 7F0AB0A0 44809000 */  mtc1  $zero, $f18
/* 0DFBD4 7F0AB0A4 44802000 */  mtc1  $zero, $f4
/* 0DFBD8 7F0AB0A8 27B80204 */  addiu $t8, $sp, 0x204
/* 0DFBDC 7F0AB0AC 44050000 */  mfc1  $a1, $f0
/* 0DFBE0 7F0AB0B0 44071000 */  mfc1  $a3, $f2
/* 0DFBE4 7F0AB0B4 AFB802E8 */  sw    $t8, 0x2e8($sp)
/* 0DFBE8 7F0AB0B8 27A4032C */  addiu $a0, $sp, 0x32c
/* 0DFBEC 7F0AB0BC 3C0644FA */  lui   $a2, 0x44fa
/* 0DFBF0 7F0AB0C0 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DFBF4 7F0AB0C4 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0DFBF8 7F0AB0C8 E7A80024 */  swc1  $f8, 0x24($sp)
/* 0DFBFC 7F0AB0CC E7A60014 */  swc1  $f6, 0x14($sp)
/* 0DFC00 7F0AB0D0 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 0DFC04 7F0AB0D4 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0DFC08 7F0AB0D8 E7A40020 */   swc1  $f4, 0x20($sp)
/* 0DFC0C 7F0AB0DC 27A4032C */  addiu $a0, $sp, 0x32c
.L7F0AB0E0:
/* 0DFC10 7F0AB0E0 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0DFC14 7F0AB0E4 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFC18 7F0AB0E8 27A6037C */   addiu $a2, $sp, 0x37c
/* 0DFC1C 7F0AB0EC 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0DFC20 7F0AB0F0 44815000 */  mtc1  $at, $f10
/* 0DFC24 7F0AB0F4 3C018006 */  lui   $at, %hi(D_8005855C)
/* 0DFC28 7F0AB0F8 C430855C */  lwc1  $f16, %lo(D_8005855C)($at)
/* 0DFC2C 7F0AB0FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DFC30 7F0AB100 44813000 */  mtc1  $at, $f6
/* 0DFC34 7F0AB104 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0DFC38 7F0AB108 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0DFC3C 7F0AB10C 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DFC40 7F0AB110 27A5036E */  addiu $a1, $sp, 0x36e
/* 0DFC44 7F0AB114 3C06424A */  lui   $a2, 0x424a
/* 0DFC48 7F0AB118 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0DFC4C 7F0AB11C E7B00014 */  swc1  $f16, 0x14($sp)
/* 0DFC50 7F0AB120 0C003FAC */  jal   guPerspective
/* 0DFC54 7F0AB124 E7A60018 */   swc1  $f6, 0x18($sp)
/* 0DFC58 7F0AB128 3C0B0103 */  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
/* 0DFC5C 7F0AB12C 356B0040 */  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0DFC60 7F0AB130 02001825 */  move  $v1, $s0
/* 0DFC64 7F0AB134 AC6B0000 */  sw    $t3, ($v1)
/* 0DFC68 7F0AB138 AFA30048 */  sw    $v1, 0x48($sp)
/* 0DFC6C 7F0AB13C 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DFC70 7F0AB140 0C003A2C */  jal   osVirtualToPhysical
/* 0DFC74 7F0AB144 26100008 */   addiu $s0, $s0, 8
/* 0DFC78 7F0AB148 8FA30048 */  lw    $v1, 0x48($sp)
/* 0DFC7C 7F0AB14C 02002025 */  move  $a0, $s0
/* 0DFC80 7F0AB150 0FC29BBA */  jal   sub_GAME_7F0A6EE8
/* 0DFC84 7F0AB154 AC620004 */   sw    $v0, 4($v1)
/* 0DFC88 7F0AB158 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen)
/* 0DFC8C 7F0AB15C 8C630B04 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0DFC90 7F0AB160 00408025 */  move  $s0, $v0
/* 0DFC94 7F0AB164 02002025 */  move  $a0, $s0
/* 0DFC98 7F0AB168 286100E0 */  slti  $at, $v1, 0xe0
/* 0DFC9C 7F0AB16C 1020000C */  beqz  $at, .L7F0AB1A0
/* 0DFCA0 7F0AB170 27A5037C */   addiu $a1, $sp, 0x37c
/* 0DFCA4 7F0AB174 8FB902E8 */  lw    $t9, 0x2e8($sp)
/* 0DFCA8 7F0AB178 27AA02E3 */  addiu $t2, $sp, 0x2e3
/* 0DFCAC 7F0AB17C AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DFCB0 7F0AB180 00402025 */  move  $a0, $v0
/* 0DFCB4 7F0AB184 27A5037C */  addiu $a1, $sp, 0x37c
/* 0DFCB8 7F0AB188 2466FFFA */  addiu $a2, $v1, -6
/* 0DFCBC 7F0AB18C 24070001 */  li    $a3, 1
/* 0DFCC0 7F0AB190 0FC18D67 */  jal   sub_GAME_7F06359C
/* 0DFCC4 7F0AB194 AFB90010 */   sw    $t9, 0x10($sp)
/* 0DFCC8 7F0AB198 10000007 */  b     .L7F0AB1B8
/* 0DFCCC 7F0AB19C 00408025 */   move  $s0, $v0
.L7F0AB1A0:
/* 0DFCD0 7F0AB1A0 27AC02E3 */  addiu $t4, $sp, 0x2e3
/* 0DFCD4 7F0AB1A4 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DFCD8 7F0AB1A8 24060001 */  li    $a2, 1
/* 0DFCDC 7F0AB1AC 0FC190D9 */  jal   sub_GAME_7F064364
/* 0DFCE0 7F0AB1B0 8FA702E8 */   lw    $a3, 0x2e8($sp)
/* 0DFCE4 7F0AB1B4 00408025 */  move  $s0, $v0
.L7F0AB1B8:
/* 0DFCE8 7F0AB1B8 0FC2935D */  jal   controllerCheckDualControllerTypesAllowed
/* 0DFCEC 7F0AB1BC 00000000 */   nop
/* 0DFCF0 7F0AB1C0 104000A2 */  beqz  $v0, .L7F0AB44C
/* 0DFCF4 7F0AB1C4 24040001 */   li    $a0, 1
/* 0DFCF8 7F0AB1C8 3C058004 */  lui   $a1, %hi(D_80040B3C)
/* 0DFCFC 7F0AB1CC 3C068004 */  lui   $a2, %hi(D_80040B38)
/* 0DFD00 7F0AB1D0 3C078004 */  lui   $a3, %hi(D_80040B34)
/* 0DFD04 7F0AB1D4 24E70B34 */  addiu $a3, %lo(D_80040B34) # addiu $a3, $a3, 0xb34
/* 0DFD08 7F0AB1D8 24C60B38 */  addiu $a2, %lo(D_80040B38) # addiu $a2, $a2, 0xb38
/* 0DFD0C 7F0AB1DC 0FC2A5A1 */  jal   sub_GAME_7F0A9684
/* 0DFD10 7F0AB1E0 24A50B3C */   addiu $a1, %lo(D_80040B3C) # addiu $a1, $a1, 0xb3c
/* 0DFD14 7F0AB1E4 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0DFD18 7F0AB1E8 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0DFD1C 7F0AB1EC 3C0D8005 */  lui   $t5, %hi(speedgraphframes)
/* 0DFD20 7F0AB1F0 8DAD8498 */  lw    $t5, %lo(speedgraphframes)($t5)
/* 0DFD24 7F0AB1F4 3C018004 */  lui   $at, %hi(D_80040B38)
/* 0DFD28 7F0AB1F8 C4320B38 */  lwc1  $f18, %lo(D_80040B38)($at)
/* 0DFD2C 7F0AB1FC 448D2000 */  mtc1  $t5, $f4
/* 0DFD30 7F0AB200 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DFD34 7F0AB204 44818000 */  mtc1  $at, $f16
/* 0DFD38 7F0AB208 46802220 */  cvt.s.w $f8, $f4
/* 0DFD3C 7F0AB20C 3C028004 */  lui   $v0, %hi(D_80040B34)
/* 0DFD40 7F0AB210 24420B34 */  addiu $v0, %lo(D_80040B34) # addiu $v0, $v0, 0xb34
/* 0DFD44 7F0AB214 C4440000 */  lwc1  $f4, ($v0)
/* 0DFD48 7F0AB218 46089282 */  mul.s $f10, $f18, $f8
/* 0DFD4C 7F0AB21C 00000000 */  nop
/* 0DFD50 7F0AB220 46105182 */  mul.s $f6, $f10, $f16
/* 0DFD54 7F0AB224 46062480 */  add.s $f18, $f4, $f6
/* 0DFD58 7F0AB228 E4520000 */  swc1  $f18, ($v0)
/* 0DFD5C 7F0AB22C 0FC29A8B */  jal   sub_GAME_7F0A6A2C
/* 0DFD60 7F0AB230 C44C0000 */   lwc1  $f12, ($v0)
/* 0DFD64 7F0AB234 3C018004 */  lui   $at, %hi(D_80040B34)
/* 0DFD68 7F0AB238 E4200B34 */  swc1  $f0, %lo(D_80040B34)($at)
/* 0DFD6C 7F0AB23C C42C0B34 */  lwc1  $f12, %lo(D_80040B34)($at)
/* 0DFD70 7F0AB240 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 0DFD74 7F0AB244 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0DFD78 7F0AB248 3C088004 */  lui   $t0, %hi(watch_item_is_actively_selected)
/* 0DFD7C 7F0AB24C 8D0809A8 */  lw    $t0, %lo(watch_item_is_actively_selected)($t0)
/* 0DFD80 7F0AB250 11000016 */  beqz  $t0, .L7F0AB2AC
/* 0DFD84 7F0AB254 3C0F8004 */   lui   $t7, %hi(controller_options_index)
/* 0DFD88 7F0AB258 8DEF0998 */  lw    $t7, %lo(controller_options_index)($t7)
/* 0DFD8C 7F0AB25C 24010001 */  li    $at, 1
/* 0DFD90 7F0AB260 15E10012 */  bne   $t7, $at, .L7F0AB2AC
/* 0DFD94 7F0AB264 00000000 */   nop
/* 0DFD98 7F0AB268 0C00307F */  jal   joyGetStickY
/* 0DFD9C 7F0AB26C 24040001 */   li    $a0, 1
/* 0DFDA0 7F0AB270 44824000 */  mtc1  $v0, $f8
/* 0DFDA4 7F0AB274 3C018004 */  lui   $at, %hi(D_80040B30)
/* 0DFDA8 7F0AB278 C42C0B30 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0DFDAC 7F0AB27C 468042A0 */  cvt.s.w $f10, $f8
/* 0DFDB0 7F0AB280 3C018006 */  lui   $at, %hi(D_80058560)
/* 0DFDB4 7F0AB284 C4308560 */  lwc1  $f16, %lo(D_80058560)($at)
/* 0DFDB8 7F0AB288 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DFDBC 7F0AB28C 44813000 */  mtc1  $at, $f6
/* 0DFDC0 7F0AB290 3C064080 */  lui   $a2, 0x4080
/* 0DFDC4 7F0AB294 46105102 */  mul.s $f4, $f10, $f16
/* 0DFDC8 7F0AB298 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DFDCC 7F0AB29C 46062383 */   div.s $f14, $f4, $f6
/* 0DFDD0 7F0AB2A0 3C018004 */  lui   $at, %hi(D_80040B30)
/* 0DFDD4 7F0AB2A4 10000008 */  b     .L7F0AB2C8
/* 0DFDD8 7F0AB2A8 E4200B30 */   swc1  $f0, %lo(D_80040B30)($at)
.L7F0AB2AC:
/* 0DFDDC 7F0AB2AC 3C018004 */  lui   $at, %hi(D_80040B30)
/* 0DFDE0 7F0AB2B0 44807000 */  mtc1  $zero, $f14
/* 0DFDE4 7F0AB2B4 C42C0B30 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0DFDE8 7F0AB2B8 0FC2A571 */  jal   sub_GAME_7F0A95C4
/* 0DFDEC 7F0AB2BC 3C064080 */   lui   $a2, 0x4080
/* 0DFDF0 7F0AB2C0 3C018004 */  lui   $at, %hi(D_80040B30)
/* 0DFDF4 7F0AB2C4 E4200B30 */  swc1  $f0, %lo(D_80040B30)($at)
.L7F0AB2C8:
/* 0DFDF8 7F0AB2C8 3C018004 */  lui   $at, %hi(D_80040B30)
/* 0DFDFC 7F0AB2CC C4320B30 */  lwc1  $f18, %lo(D_80040B30)($at)
/* 0DFE00 7F0AB2D0 3C018006 */  lui   $at, %hi(D_80058564)
/* 0DFE04 7F0AB2D4 C42A8564 */  lwc1  $f10, %lo(D_80058564)($at)
/* 0DFE08 7F0AB2D8 46009207 */  neg.s $f8, $f18
/* 0DFE0C 7F0AB2DC 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DFE10 7F0AB2E0 0FC1615C */  jal   matrix_4x4_set_rotation_around_x
/* 0DFE14 7F0AB2E4 460A4301 */   sub.s $f12, $f8, $f10
/* 0DFE18 7F0AB2E8 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0DFE1C 7F0AB2EC 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0DFE20 7F0AB2F0 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFE24 7F0AB2F4 27A6043C */   addiu $a2, $sp, 0x43c
/* 0DFE28 7F0AB2F8 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DFE2C 7F0AB2FC 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DFE30 7F0AB300 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFE34 7F0AB304 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0DFE38 7F0AB308 27A40370 */  addiu $a0, $sp, 0x370
/* 0DFE3C 7F0AB30C 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 0DFE40 7F0AB310 27A5043C */   addiu $a1, $sp, 0x43c
/* 0DFE44 7F0AB314 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DFE48 7F0AB318 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0DFE4C 7F0AB31C 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFE50 7F0AB320 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0DFE54 7F0AB324 3C018006 */  lui   $at, %hi(D_80058568)
/* 0DFE58 7F0AB328 C4208568 */  lwc1  $f0, %lo(D_80058568)($at)
/* 0DFE5C 7F0AB32C 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0DFE60 7F0AB330 44801000 */  mtc1  $zero, $f2
/* 0DFE64 7F0AB334 44818000 */  mtc1  $at, $f16
/* 0DFE68 7F0AB338 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DFE6C 7F0AB33C 44812000 */  mtc1  $at, $f4
/* 0DFE70 7F0AB340 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0DFE74 7F0AB344 44050000 */  mfc1  $a1, $f0
/* 0DFE78 7F0AB348 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0DFE7C 7F0AB34C 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0DFE80 7F0AB350 3C074200 */  lui   $a3, 0x4200
/* 0DFE84 7F0AB354 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DFE88 7F0AB358 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0DFE8C 7F0AB35C E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DFE90 7F0AB360 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0DFE94 7F0AB364 E7B00018 */  swc1  $f16, 0x18($sp)
/* 0DFE98 7F0AB368 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0DFE9C 7F0AB36C E7A40024 */   swc1  $f4, 0x24($sp)
/* 0DFEA0 7F0AB370 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0DFEA4 7F0AB374 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0DFEA8 7F0AB378 0FC16032 */  jal   matrix_4x4_multiply
/* 0DFEAC 7F0AB37C 27A6037C */   addiu $a2, $sp, 0x37c
/* 0DFEB0 7F0AB380 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0DFEB4 7F0AB384 44813000 */  mtc1  $at, $f6
/* 0DFEB8 7F0AB388 3C018006 */  lui   $at, %hi(D_8005856C)
/* 0DFEBC 7F0AB38C C432856C */  lwc1  $f18, %lo(D_8005856C)($at)
/* 0DFEC0 7F0AB390 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DFEC4 7F0AB394 44814000 */  mtc1  $at, $f8
/* 0DFEC8 7F0AB398 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0DFECC 7F0AB39C 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0DFED0 7F0AB3A0 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DFED4 7F0AB3A4 27A5036E */  addiu $a1, $sp, 0x36e
/* 0DFED8 7F0AB3A8 3C06424A */  lui   $a2, 0x424a
/* 0DFEDC 7F0AB3AC E7A60010 */  swc1  $f6, 0x10($sp)
/* 0DFEE0 7F0AB3B0 E7B20014 */  swc1  $f18, 0x14($sp)
/* 0DFEE4 7F0AB3B4 0C003FAC */  jal   guPerspective
/* 0DFEE8 7F0AB3B8 E7A80018 */   swc1  $f8, 0x18($sp)
/* 0DFEEC 7F0AB3BC 3C090103 */  lui   $t1, (0x01030040 >> 16) # lui $t1, 0x103
/* 0DFEF0 7F0AB3C0 35290040 */  ori   $t1, (0x01030040 & 0xFFFF) # ori $t1, $t1, 0x40
/* 0DFEF4 7F0AB3C4 02001825 */  move  $v1, $s0
/* 0DFEF8 7F0AB3C8 AC690000 */  sw    $t1, ($v1)
/* 0DFEFC 7F0AB3CC AFA30044 */  sw    $v1, 0x44($sp)
/* 0DFF00 7F0AB3D0 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DFF04 7F0AB3D4 0C003A2C */  jal   osVirtualToPhysical
/* 0DFF08 7F0AB3D8 26100008 */   addiu $s0, $s0, 8
/* 0DFF0C 7F0AB3DC 8FA30044 */  lw    $v1, 0x44($sp)
/* 0DFF10 7F0AB3E0 02002025 */  move  $a0, $s0
/* 0DFF14 7F0AB3E4 0FC29BBA */  jal   sub_GAME_7F0A6EE8
/* 0DFF18 7F0AB3E8 AC620004 */   sw    $v0, 4($v1)
/* 0DFF1C 7F0AB3EC 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen)
/* 0DFF20 7F0AB3F0 8C630B04 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0DFF24 7F0AB3F4 00408025 */  move  $s0, $v0
/* 0DFF28 7F0AB3F8 02002025 */  move  $a0, $s0
/* 0DFF2C 7F0AB3FC 286100E0 */  slti  $at, $v1, 0xe0
/* 0DFF30 7F0AB400 1020000C */  beqz  $at, .L7F0AB434
/* 0DFF34 7F0AB404 27A5037C */   addiu $a1, $sp, 0x37c
/* 0DFF38 7F0AB408 27AE004C */  addiu $t6, $sp, 0x4c
/* 0DFF3C 7F0AB40C 27B802E2 */  addiu $t8, $sp, 0x2e2
/* 0DFF40 7F0AB410 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DFF44 7F0AB414 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DFF48 7F0AB418 00402025 */  move  $a0, $v0
/* 0DFF4C 7F0AB41C 27A5037C */  addiu $a1, $sp, 0x37c
/* 0DFF50 7F0AB420 2466FFFA */  addiu $a2, $v1, -6
/* 0DFF54 7F0AB424 0FC18D67 */  jal   sub_GAME_7F06359C
/* 0DFF58 7F0AB428 24070001 */   li    $a3, 1
/* 0DFF5C 7F0AB42C 10000007 */  b     .L7F0AB44C
/* 0DFF60 7F0AB430 00408025 */   move  $s0, $v0
.L7F0AB434:
/* 0DFF64 7F0AB434 27AB02E2 */  addiu $t3, $sp, 0x2e2
/* 0DFF68 7F0AB438 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DFF6C 7F0AB43C 24060001 */  li    $a2, 1
/* 0DFF70 7F0AB440 0FC190D9 */  jal   sub_GAME_7F064364
/* 0DFF74 7F0AB444 27A7004C */   addiu $a3, $sp, 0x4c
/* 0DFF78 7F0AB448 00408025 */  move  $s0, $v0
.L7F0AB44C:
/* 0DFF7C 7F0AB44C 0FC2935D */  jal   controllerCheckDualControllerTypesAllowed
/* 0DFF80 7F0AB450 00000000 */   nop
/* 0DFF84 7F0AB454 10400005 */  beqz  $v0, .L7F0AB46C
/* 0DFF88 7F0AB458 00000000 */   nop
/* 0DFF8C 7F0AB45C 0FC2A9F2 */  jal   display_text_buttons_dual_control
/* 0DFF90 7F0AB460 02002025 */   move  $a0, $s0
/* 0DFF94 7F0AB464 10000004 */  b     .L7F0AB478
/* 0DFF98 7F0AB468 00408025 */   move  $s0, $v0
.L7F0AB46C:
/* 0DFF9C 7F0AB46C 0FC2A6AE */  jal   sub_GAME_7F0A9AB8
/* 0DFFA0 7F0AB470 02002025 */   move  $a0, $s0
/* 0DFFA4 7F0AB474 00408025 */  move  $s0, $v0
.L7F0AB478:
/* 0DFFA8 7F0AB478 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0DFFAC 7F0AB47C 02001025 */  move  $v0, $s0
/* 0DFFB0 7F0AB480 8FB00030 */  lw    $s0, 0x30($sp)
/* 0DFFB4 7F0AB484 03E00008 */  jr    $ra
/* 0DFFB8 7F0AB488 27BD0540 */   addiu $sp, $sp, 0x540
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80058550
.word 0x40c90fdb /*6.2831855*/
glabel D_80058554
.word 0x3f490fdb /*0.78539819*/
glabel D_80058558
.word 0x43f78000 /*495.0*/
glabel D_8005855C
.word 0x453b8000  /*3000.0*/
glabel D_80058560
.word 0x40c90fdb /*6.2831855*/
glabel D_80058564
.word 0x3f490fdb /*0.78539819*/
glabel D_80058568
.word 0xc3fc8000 /*-505.0*/
glabel D_8005856C
.word 0x453b8000  /*3000.0*/
.text
glabel sub_GAME_7F0AADC0
/* 0E04F0 7F0AB980 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 0E04F4 7F0AB984 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0E04F8 7F0AB988 AFB00030 */  sw    $s0, 0x30($sp)
/* 0E04FC 7F0AB98C 0FC2F8A4 */  jal   dynAllocateMatrix
/* 0E0500 7F0AB990 00808025 */   move  $s0, $a0
/* 0E0504 7F0AB994 3C0F8004 */  lui   $t7, %hi(D_80040B5C) # $t7, 0x8004
/* 0E0508 7F0AB998 AFA2053C */  sw    $v0, 0x53c($sp)
/* 0E050C 7F0AB99C 25EF0B8C */  addiu $t7, %lo(D_80040B5C) # addiu $t7, $t7, 0xb8c
/* 0E0510 7F0AB9A0 8DE10000 */  lw    $at, ($t7)
/* 0E0514 7F0AB9A4 27AE0370 */  addiu $t6, $sp, 0x370
/* 0E0518 7F0AB9A8 8DE80004 */  lw    $t0, 4($t7)
/* 0E051C 7F0AB9AC ADC10000 */  sw    $at, ($t6)
/* 0E0520 7F0AB9B0 8DE10008 */  lw    $at, 8($t7)
/* 0E0524 7F0AB9B4 3C0B8004 */  lui   $t3, %hi(D_80040B68) # $t3, 0x8004
/* 0E0528 7F0AB9B8 ADC80004 */  sw    $t0, 4($t6)
/* 0E052C 7F0AB9BC ADC10008 */  sw    $at, 8($t6)
/* 0E0530 7F0AB9C0 24090001 */  li    $t1, 1
/* 0E0534 7F0AB9C4 256B0B98 */  addiu $t3, %lo(D_80040B68) # addiu $t3, $t3, 0xb98
/* 0E0538 7F0AB9C8 A3A002E3 */  sb    $zero, 0x2e3($sp)
/* 0E053C 7F0AB9CC A3A902E2 */  sb    $t1, 0x2e2($sp)
/* 0E0540 7F0AB9D0 257900D8 */  addiu $t9, $t3, 0xd8
/* 0E0544 7F0AB9D4 27AA0204 */  addiu $t2, $sp, 0x204
.Ljp7F0AB9D8:
/* 0E0548 7F0AB9D8 8D610000 */  lw    $at, ($t3)
/* 0E054C 7F0AB9DC 256B000C */  addiu $t3, $t3, 0xc
/* 0E0550 7F0AB9E0 254A000C */  addiu $t2, $t2, 0xc
/* 0E0554 7F0AB9E4 AD41FFF4 */  sw    $at, -0xc($t2)
/* 0E0558 7F0AB9E8 8D61FFF8 */  lw    $at, -8($t3)
/* 0E055C 7F0AB9EC AD41FFF8 */  sw    $at, -8($t2)
/* 0E0560 7F0AB9F0 8D61FFFC */  lw    $at, -4($t3)
/* 0E0564 7F0AB9F4 1579FFF8 */  bne   $t3, $t9, .Ljp7F0AB9D8
/* 0E0568 7F0AB9F8 AD41FFFC */   sw    $at, -4($t2)
/* 0E056C 7F0AB9FC 8D610000 */  lw    $at, ($t3)
/* 0E0570 7F0ABA00 3C0E8004 */  lui   $t6, %hi(D_80040C44) # $t6, 0x8004
/* 0E0574 7F0ABA04 25CE0C74 */  addiu $t6, %lo(D_80040C44) # addiu $t6, $t6, 0xc74
/* 0E0578 7F0ABA08 25C900D8 */  addiu $t1, $t6, 0xd8
/* 0E057C 7F0ABA0C 27B80128 */  addiu $t8, $sp, 0x128
/* 0E0580 7F0ABA10 AD410000 */  sw    $at, ($t2)
.Ljp7F0ABA14:
/* 0E0584 7F0ABA14 8DC10000 */  lw    $at, ($t6)
/* 0E0588 7F0ABA18 25CE000C */  addiu $t6, $t6, 0xc
/* 0E058C 7F0ABA1C 2718000C */  addiu $t8, $t8, 0xc
/* 0E0590 7F0ABA20 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0E0594 7F0ABA24 8DC1FFF8 */  lw    $at, -8($t6)
/* 0E0598 7F0ABA28 AF01FFF8 */  sw    $at, -8($t8)
/* 0E059C 7F0ABA2C 8DC1FFFC */  lw    $at, -4($t6)
/* 0E05A0 7F0ABA30 15C9FFF8 */  bne   $t6, $t1, .Ljp7F0ABA14
/* 0E05A4 7F0ABA34 AF01FFFC */   sw    $at, -4($t8)
/* 0E05A8 7F0ABA38 8DC10000 */  lw    $at, ($t6)
/* 0E05AC 7F0ABA3C 3C0C8004 */  lui   $t4, %hi(D_80040D20) # $t4, 0x8004
/* 0E05B0 7F0ABA40 258C0D50 */  addiu $t4, %lo(D_80040D20) # addiu $t4, $t4, 0xd50
/* 0E05B4 7F0ABA44 258A00D8 */  addiu $t2, $t4, 0xd8
/* 0E05B8 7F0ABA48 27AD004C */  addiu $t5, $sp, 0x4c
/* 0E05BC 7F0ABA4C AF010000 */  sw    $at, ($t8)
.Ljp7F0ABA50:
/* 0E05C0 7F0ABA50 8D810000 */  lw    $at, ($t4)
/* 0E05C4 7F0ABA54 258C000C */  addiu $t4, $t4, 0xc
/* 0E05C8 7F0ABA58 25AD000C */  addiu $t5, $t5, 0xc
/* 0E05CC 7F0ABA5C ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0E05D0 7F0ABA60 8D81FFF8 */  lw    $at, -8($t4)
/* 0E05D4 7F0ABA64 ADA1FFF8 */  sw    $at, -8($t5)
/* 0E05D8 7F0ABA68 8D81FFFC */  lw    $at, -4($t4)
/* 0E05DC 7F0ABA6C 158AFFF8 */  bne   $t4, $t2, .Ljp7F0ABA50
/* 0E05E0 7F0ABA70 ADA1FFFC */   sw    $at, -4($t5)
/* 0E05E4 7F0ABA74 8D810000 */  lw    $at, ($t4)
/* 0E05E8 7F0ABA78 3C058004 */  lui   $a1, %hi(D_80040B2C) # $a1, 0x8004
/* 0E05EC 7F0ABA7C 3C068004 */  lui   $a2, %hi(D_80040B28) # $a2, 0x8004
/* 0E05F0 7F0ABA80 3C078004 */  lui   $a3, %hi(D_80040B24) # $a3, 0x8004
/* 0E05F4 7F0ABA84 24E70B54 */  addiu $a3, %lo(D_80040B24) # addiu $a3, $a3, 0xb54
/* 0E05F8 7F0ABA88 24C60B58 */  addiu $a2, %lo(D_80040B28) # addiu $a2, $a2, 0xb58
/* 0E05FC 7F0ABA8C 24A50B5C */  addiu $a1, %lo(D_80040B2C) # addiu $a1, $a1, 0xb5c
/* 0E0600 7F0ABA90 00002025 */  move  $a0, $zero
/* 0E0604 7F0ABA94 0FC2A891 */  jal   sub_GAME_7F0A9684
/* 0E0608 7F0ABA98 ADA10000 */   sw    $at, ($t5)
/* 0E060C 7F0ABA9C 0FC1613C */  jal   matrix_4x4_set_identity
/* 0E0610 7F0ABAA0 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0E0614 7F0ABAA4 3C018004 */  lui   $at, %hi(D_80040B28) # $at, 0x8004
/* 0E0618 7F0ABAA8 C4240B58 */  lwc1  $f4, %lo(D_80040B28)($at)
/* 0E061C 7F0ABAAC 3C018005 */  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
/* 0E0620 7F0ABAB0 C42684D0 */  lwc1  $f6, %lo(jpD_800484D0)($at)
/* 0E0624 7F0ABAB4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0E0628 7F0ABAB8 44815000 */  mtc1  $at, $f10
/* 0E062C 7F0ABABC 46062202 */  mul.s $f8, $f4, $f6
/* 0E0630 7F0ABAC0 3C028004 */  lui   $v0, %hi(D_80040B24) # $v0, 0x8004
/* 0E0634 7F0ABAC4 24420B54 */  addiu $v0, %lo(D_80040B24) # addiu $v0, $v0, 0xb54
/* 0E0638 7F0ABAC8 C4520000 */  lwc1  $f18, ($v0)
/* 0E063C 7F0ABACC 460A4402 */  mul.s $f16, $f8, $f10
/* 0E0640 7F0ABAD0 46109100 */  add.s $f4, $f18, $f16
/* 0E0644 7F0ABAD4 E4440000 */  swc1  $f4, ($v0)
/* 0E0648 7F0ABAD8 0FC29D73 */  jal   sub_GAME_7F0A6A2C
/* 0E064C 7F0ABADC C44C0000 */   lwc1  $f12, ($v0)
/* 0E0650 7F0ABAE0 3C018004 */  lui   $at, %hi(D_80040B24) # $at, 0x8004
/* 0E0654 7F0ABAE4 E4200B54 */  swc1  $f0, %lo(D_80040B24)($at)
/* 0E0658 7F0ABAE8 C42C0B54 */  lwc1  $f12, %lo(D_80040B24)($at)
/* 0E065C 7F0ABAEC 0FC162EA */  jal   matrix_4x4_set_rotation_around_z
/* 0E0660 7F0ABAF0 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0E0664 7F0ABAF4 3C088004 */  lui   $t0, %hi(watch_item_is_actively_selected) # $t0, 0x8004
/* 0E0668 7F0ABAF8 8D0809D8 */  lw    $t0, %lo(watch_item_is_actively_selected)($t0)
/* 0E066C 7F0ABAFC 11000016 */  beqz  $t0, .Ljp7F0ABB58
/* 0E0670 7F0ABB00 3C0F8004 */   lui   $t7, %hi(controller_options_index) # $t7, 0x8004
/* 0E0674 7F0ABB04 8DEF09C8 */  lw    $t7, %lo(controller_options_index)($t7)
/* 0E0678 7F0ABB08 24010001 */  li    $at, 1
/* 0E067C 7F0ABB0C 15E10012 */  bne   $t7, $at, .Ljp7F0ABB58
/* 0E0680 7F0ABB10 00000000 */   nop
/* 0E0684 7F0ABB14 0C003098 */  jal   joyGetStickY
/* 0E0688 7F0ABB18 00002025 */   move  $a0, $zero
/* 0E068C 7F0ABB1C 44823000 */  mtc1  $v0, $f6
/* 0E0690 7F0ABB20 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0E0694 7F0ABB24 C42C0B50 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0E0698 7F0ABB28 46803220 */  cvt.s.w $f8, $f6
/* 0E069C 7F0ABB2C 3C018006 */  lui   $at, %hi(D_80058550) # $at, 0x8006
/* 0E06A0 7F0ABB30 C42A8590 */  lwc1  $f10, %lo(D_80058550)($at)
/* 0E06A4 7F0ABB34 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0E06A8 7F0ABB38 44818000 */  mtc1  $at, $f16
/* 0E06AC 7F0ABB3C 3C064080 */  lui   $a2, 0x4080
/* 0E06B0 7F0ABB40 460A4482 */  mul.s $f18, $f8, $f10
/* 0E06B4 7F0ABB44 0FC2A861 */  jal   sub_GAME_7F0A95C4
/* 0E06B8 7F0ABB48 46109383 */   div.s $f14, $f18, $f16
/* 0E06BC 7F0ABB4C 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0E06C0 7F0ABB50 10000008 */  b     .Ljp7F0ABB74
/* 0E06C4 7F0ABB54 E4200B50 */   swc1  $f0, %lo(D_80040B20)($at)
.Ljp7F0ABB58:
/* 0E06C8 7F0ABB58 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0E06CC 7F0ABB5C 44807000 */  mtc1  $zero, $f14
/* 0E06D0 7F0ABB60 C42C0B50 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0E06D4 7F0ABB64 0FC2A861 */  jal   sub_GAME_7F0A95C4
/* 0E06D8 7F0ABB68 3C064080 */   lui   $a2, 0x4080
/* 0E06DC 7F0ABB6C 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0E06E0 7F0ABB70 E4200B50 */  swc1  $f0, %lo(D_80040B20)($at)
.Ljp7F0ABB74:
/* 0E06E4 7F0ABB74 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0E06E8 7F0ABB78 C4240B50 */  lwc1  $f4, %lo(D_80040B20)($at)
/* 0E06EC 7F0ABB7C 3C018006 */  lui   $at, %hi(D_80058554) # $at, 0x8006
/* 0E06F0 7F0ABB80 C4288594 */  lwc1  $f8, %lo(D_80058554)($at)
/* 0E06F4 7F0ABB84 46002187 */  neg.s $f6, $f4
/* 0E06F8 7F0ABB88 27A5047C */  addiu $a1, $sp, 0x47c
/* 0E06FC 7F0ABB8C 0FC162A4 */  jal   matrix_4x4_set_rotation_around_x
/* 0E0700 7F0ABB90 46083301 */   sub.s $f12, $f6, $f8
/* 0E0704 7F0ABB94 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0E0708 7F0ABB98 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0E070C 7F0ABB9C 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0710 7F0ABBA0 27A6043C */   addiu $a2, $sp, 0x43c
/* 0E0714 7F0ABBA4 27A4043C */  addiu $a0, $sp, 0x43c
/* 0E0718 7F0ABBA8 27A5047C */  addiu $a1, $sp, 0x47c
/* 0E071C 7F0ABBAC 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0720 7F0ABBB0 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0E0724 7F0ABBB4 27A40370 */  addiu $a0, $sp, 0x370
/* 0E0728 7F0ABBB8 0FC163A1 */  jal   matrix_4x4_set_identity_and_position
/* 0E072C 7F0ABBBC 27A5043C */   addiu $a1, $sp, 0x43c
/* 0E0730 7F0ABBC0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0E0734 7F0ABBC4 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0E0738 7F0ABBC8 0FC1617A */  jal   matrix_4x4_multiply
/* 0E073C 7F0ABBCC 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0E0740 7F0ABBD0 0FC29645 */  jal   controllerCheckDualControllerTypesAllowed
/* 0E0744 7F0ABBD4 00000000 */   nop
/* 0E0748 7F0ABBD8 10400018 */  beqz  $v0, .Ljp7F0ABC3C
/* 0E074C 7F0ABBDC 3C01C0A0 */   lui   $at, 0xc0a0
/* 0E0750 7F0ABBE0 3C018006 */  lui    $at, %hi(D_80058558)
/* 0E0754 7F0ABBE4 C4208598 */  lwc1  $f0, %lo(D_80058558)($at)
/* 0E0758 7F0ABBE8 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0E075C 7F0ABBEC 44816000 */  mtc1  $at, $f12
/* 0E0760 7F0ABBF0 44801000 */  mtc1  $zero, $f2
/* 0E0764 7F0ABBF4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0E0768 7F0ABBF8 44815000 */  mtc1  $at, $f10
/* 0E076C 7F0ABBFC 27A90128 */  addiu $t1, $sp, 0x128
/* 0E0770 7F0ABC00 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0E0774 7F0ABC04 44050000 */  mfc1  $a1, $f0
/* 0E0778 7F0ABC08 44076000 */  mfc1  $a3, $f12
/* 0E077C 7F0ABC0C AFA902E8 */  sw    $t1, 0x2e8($sp)
/* 0E0780 7F0ABC10 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0E0784 7F0ABC14 27A4032C */  addiu $a0, $sp, 0x32c
/* 0E0788 7F0ABC18 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0E078C 7F0ABC1C E7AC0018 */  swc1  $f12, 0x18($sp)
/* 0E0790 7F0ABC20 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0E0794 7F0ABC24 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0E0798 7F0ABC28 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0E079C 7F0ABC2C 0FC166ED */  jal   matrix_4x4_7F059694
/* 0E07A0 7F0ABC30 E7AA0024 */   swc1  $f10, 0x24($sp)
/* 0E07A4 7F0ABC34 10000017 */  b     .Ljp7F0ABC94
/* 0E07A8 7F0ABC38 27A4032C */   addiu $a0, $sp, 0x32c
.Ljp7F0ABC3C:
/* 0E07AC 7F0ABC3C 44810000 */  mtc1  $at, $f0
/* 0E07B0 7F0ABC40 3C01C328 */  li    $at, 0xC3280000 # -168.000000
/* 0E07B4 7F0ABC44 44811000 */  mtc1  $at, $f2
/* 0E07B8 7F0ABC48 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0E07BC 7F0ABC4C 44813000 */  mtc1  $at, $f6
/* 0E07C0 7F0ABC50 44809000 */  mtc1  $zero, $f18
/* 0E07C4 7F0ABC54 44808000 */  mtc1  $zero, $f16
/* 0E07C8 7F0ABC58 44802000 */  mtc1  $zero, $f4
/* 0E07CC 7F0ABC5C 27AE0204 */  addiu $t6, $sp, 0x204
/* 0E07D0 7F0ABC60 44050000 */  mfc1  $a1, $f0
/* 0E07D4 7F0ABC64 44071000 */  mfc1  $a3, $f2
/* 0E07D8 7F0ABC68 AFAE02E8 */  sw    $t6, 0x2e8($sp)
/* 0E07DC 7F0ABC6C 27A4032C */  addiu $a0, $sp, 0x32c
/* 0E07E0 7F0ABC70 3C0644FA */  lui   $a2, 0x44fa
/* 0E07E4 7F0ABC74 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0E07E8 7F0ABC78 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0E07EC 7F0ABC7C E7A60024 */  swc1  $f6, 0x24($sp)
/* 0E07F0 7F0ABC80 E7B20014 */  swc1  $f18, 0x14($sp)
/* 0E07F4 7F0ABC84 E7B0001C */  swc1  $f16, 0x1c($sp)
/* 0E07F8 7F0ABC88 0FC166ED */  jal   matrix_4x4_7F059694
/* 0E07FC 7F0ABC8C E7A40020 */   swc1  $f4, 0x20($sp)
/* 0E0800 7F0ABC90 27A4032C */  addiu $a0, $sp, 0x32c
.Ljp7F0ABC94:
/* 0E0804 7F0ABC94 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0E0808 7F0ABC98 0FC1617A */  jal   matrix_4x4_multiply
/* 0E080C 7F0ABC9C 27A6037C */   addiu $a2, $sp, 0x37c
/* 0E0810 7F0ABCA0 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0E0814 7F0ABCA4 44814000 */  mtc1  $at, $f8
/* 0E0818 7F0ABCA8 3C018006 */  lui   $at, %hi(D_8005855C) # $at, 0x8006
/* 0E081C 7F0ABCAC C42A859C */  lwc1  $f10, %lo(D_8005855C)($at)
/* 0E0820 7F0ABCB0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E0824 7F0ABCB4 44819000 */  mtc1  $at, $f18
/* 0E0828 7F0ABCB8 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0E082C 7F0ABCBC 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0E0830 7F0ABCC0 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0E0834 7F0ABCC4 27A5036E */  addiu $a1, $sp, 0x36e
/* 0E0838 7F0ABCC8 3C06424A */  lui   $a2, 0x424a
/* 0E083C 7F0ABCCC E7A80010 */  swc1  $f8, 0x10($sp)
/* 0E0840 7F0ABCD0 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 0E0844 7F0ABCD4 0C003FBC */  jal   guPerspective
/* 0E0848 7F0ABCD8 E7B20018 */   swc1  $f18, 0x18($sp)
/* 0E084C 7F0ABCDC 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0E0850 7F0ABCE0 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0E0854 7F0ABCE4 02001825 */  move  $v1, $s0
/* 0E0858 7F0ABCE8 AC780000 */  sw    $t8, ($v1)
/* 0E085C 7F0ABCEC AFA30048 */  sw    $v1, 0x48($sp)
/* 0E0860 7F0ABCF0 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0E0864 7F0ABCF4 0C003A3C */  jal   osVirtualToPhysical
/* 0E0868 7F0ABCF8 26100008 */   addiu $s0, $s0, 8
/* 0E086C 7F0ABCFC 8FA30048 */  lw    $v1, 0x48($sp)
/* 0E0870 7F0ABD00 02002025 */  move  $a0, $s0
/* 0E0874 7F0ABD04 0FC29EA0 */  jal   sub_GAME_7F0A6EE8
/* 0E0878 7F0ABD08 AC620004 */   sw    $v0, 4($v1)
/* 0E087C 7F0ABD0C 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen) # $v1, 0x8004
/* 0E0880 7F0ABD10 8C630B34 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0E0884 7F0ABD14 00408025 */  move  $s0, $v0
/* 0E0888 7F0ABD18 02002025 */  move  $a0, $s0
/* 0E088C 7F0ABD1C 286100E0 */  slti  $at, $v1, 0xe0
/* 0E0890 7F0ABD20 1020000C */  beqz  $at, .Ljp7F0ABD54
/* 0E0894 7F0ABD24 27A5037C */   addiu $a1, $sp, 0x37c
/* 0E0898 7F0ABD28 8FAB02E8 */  lw    $t3, 0x2e8($sp)
/* 0E089C 7F0ABD2C 27B902E3 */  addiu $t9, $sp, 0x2e3
/* 0E08A0 7F0ABD30 AFB90014 */  sw    $t9, 0x14($sp)
/* 0E08A4 7F0ABD34 00402025 */  move  $a0, $v0
/* 0E08A8 7F0ABD38 27A5037C */  addiu $a1, $sp, 0x37c
/* 0E08AC 7F0ABD3C 2466FFFA */  addiu $a2, $v1, -6
/* 0E08B0 7F0ABD40 24070001 */  li    $a3, 1
/* 0E08B4 7F0ABD44 0FC18EB2 */  jal   sub_GAME_7F06359C
/* 0E08B8 7F0ABD48 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0E08BC 7F0ABD4C 10000007 */  b     .Ljp7F0ABD6C
/* 0E08C0 7F0ABD50 00408025 */   move  $s0, $v0
.Ljp7F0ABD54:
/* 0E08C4 7F0ABD54 27AA02E3 */  addiu $t2, $sp, 0x2e3
/* 0E08C8 7F0ABD58 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0E08CC 7F0ABD5C 24060001 */  li    $a2, 1
/* 0E08D0 7F0ABD60 0FC19224 */  jal   sub_GAME_7F064364
/* 0E08D4 7F0ABD64 8FA702E8 */   lw    $a3, 0x2e8($sp)
/* 0E08D8 7F0ABD68 00408025 */  move  $s0, $v0
.Ljp7F0ABD6C:
/* 0E08DC 7F0ABD6C 0FC29645 */  jal   controllerCheckDualControllerTypesAllowed
/* 0E08E0 7F0ABD70 00000000 */   nop
/* 0E08E4 7F0ABD74 1040009F */  beqz  $v0, .Ljp7F0ABFF4
/* 0E08E8 7F0ABD78 24040001 */   li    $a0, 1
/* 0E08EC 7F0ABD7C 3C058004 */  lui   $a1, %hi(D_80040B3C) # $a1, 0x8004
/* 0E08F0 7F0ABD80 3C068004 */  lui   $a2, %hi(D_80040B38) # $a2, 0x8004
/* 0E08F4 7F0ABD84 3C078004 */  lui   $a3, %hi(D_80040B34) # $a3, 0x8004
/* 0E08F8 7F0ABD88 24E70B64 */  addiu $a3, %lo(D_80040B34) # addiu $a3, $a3, 0xb64
/* 0E08FC 7F0ABD8C 24C60B68 */  addiu $a2, %lo(D_80040B38) # addiu $a2, $a2, 0xb68
/* 0E0900 7F0ABD90 0FC2A891 */  jal   sub_GAME_7F0A9684
/* 0E0904 7F0ABD94 24A50B6C */   addiu $a1, %lo(D_80040B3C) # addiu $a1, $a1, 0xb6c
/* 0E0908 7F0ABD98 0FC1613C */  jal   matrix_4x4_set_identity
/* 0E090C 7F0ABD9C 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0E0910 7F0ABDA0 3C018004 */  lui   $at, %hi(D_80040B38) # $at, 0x8004
/* 0E0914 7F0ABDA4 C4300B68 */  lwc1  $f16, %lo(D_80040B38)($at)
/* 0E0918 7F0ABDA8 3C018005 */  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
/* 0E091C 7F0ABDAC C42484D0 */  lwc1  $f4, %lo(jpD_800484D0)($at)
/* 0E0920 7F0ABDB0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0E0924 7F0ABDB4 44814000 */  mtc1  $at, $f8
/* 0E0928 7F0ABDB8 46048182 */  mul.s $f6, $f16, $f4
/* 0E092C 7F0ABDBC 3C028004 */  lui   $v0, %hi(D_80040B34) # $v0, 0x8004
/* 0E0930 7F0ABDC0 24420B64 */  addiu $v0, %lo(D_80040B34) # addiu $v0, $v0, 0xb64
/* 0E0934 7F0ABDC4 C4520000 */  lwc1  $f18, ($v0)
/* 0E0938 7F0ABDC8 46083282 */  mul.s $f10, $f6, $f8
/* 0E093C 7F0ABDCC 460A9400 */  add.s $f16, $f18, $f10
/* 0E0940 7F0ABDD0 E4500000 */  swc1  $f16, ($v0)
/* 0E0944 7F0ABDD4 0FC29D73 */  jal   sub_GAME_7F0A6A2C
/* 0E0948 7F0ABDD8 C44C0000 */   lwc1  $f12, ($v0)
/* 0E094C 7F0ABDDC 3C018004 */  lui   $at, %hi(D_80040B34) # $at, 0x8004
/* 0E0950 7F0ABDE0 E4200B64 */  swc1  $f0, %lo(D_80040B34)($at)
/* 0E0954 7F0ABDE4 C42C0B64 */  lwc1  $f12, %lo(D_80040B34)($at)
/* 0E0958 7F0ABDE8 0FC162EA */  jal   matrix_4x4_set_rotation_around_z
/* 0E095C 7F0ABDEC 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0E0960 7F0ABDF0 3C0C8004 */  lui   $t4, %hi(watch_item_is_actively_selected) # $t4, 0x8004
/* 0E0964 7F0ABDF4 8D8C09D8 */  lw    $t4, %lo(watch_item_is_actively_selected)($t4)
/* 0E0968 7F0ABDF8 11800016 */  beqz  $t4, .Ljp7F0ABE54
/* 0E096C 7F0ABDFC 3C0D8004 */   lui   $t5, %hi(controller_options_index) # $t5, 0x8004
/* 0E0970 7F0ABE00 8DAD09C8 */  lw    $t5, %lo(controller_options_index)($t5)
/* 0E0974 7F0ABE04 24010001 */  li    $at, 1
/* 0E0978 7F0ABE08 15A10012 */  bne   $t5, $at, .Ljp7F0ABE54
/* 0E097C 7F0ABE0C 00000000 */   nop
/* 0E0980 7F0ABE10 0C003098 */  jal   joyGetStickY
/* 0E0984 7F0ABE14 24040001 */   li    $a0, 1
/* 0E0988 7F0ABE18 44822000 */  mtc1  $v0, $f4
/* 0E098C 7F0ABE1C 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0E0990 7F0ABE20 C42C0B60 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0E0994 7F0ABE24 468021A0 */  cvt.s.w $f6, $f4
/* 0E0998 7F0ABE28 3C018006 */  lui   $at, %hi(D_80058560) # $at, 0x8006
/* 0E099C 7F0ABE2C C42885A0 */  lwc1  $f8, %lo(D_80058560)($at)
/* 0E09A0 7F0ABE30 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0E09A4 7F0ABE34 44815000 */  mtc1  $at, $f10
/* 0E09A8 7F0ABE38 3C064080 */  lui   $a2, 0x4080
/* 0E09AC 7F0ABE3C 46083482 */  mul.s $f18, $f6, $f8
/* 0E09B0 7F0ABE40 0FC2A861 */  jal   sub_GAME_7F0A95C4
/* 0E09B4 7F0ABE44 460A9383 */   div.s $f14, $f18, $f10
/* 0E09B8 7F0ABE48 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0E09BC 7F0ABE4C 10000008 */  b     .Ljp7F0ABE70
/* 0E09C0 7F0ABE50 E4200B60 */   swc1  $f0, %lo(D_80040B30)($at)
.Ljp7F0ABE54:
/* 0E09C4 7F0ABE54 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0E09C8 7F0ABE58 44807000 */  mtc1  $zero, $f14
/* 0E09CC 7F0ABE5C C42C0B60 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0E09D0 7F0ABE60 0FC2A861 */  jal   sub_GAME_7F0A95C4
/* 0E09D4 7F0ABE64 3C064080 */   lui   $a2, 0x4080
/* 0E09D8 7F0ABE68 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0E09DC 7F0ABE6C E4200B60 */  swc1  $f0, %lo(D_80040B30)($at)
.Ljp7F0ABE70:
/* 0E09E0 7F0ABE70 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0E09E4 7F0ABE74 C4300B60 */  lwc1  $f16, %lo(D_80040B30)($at)
/* 0E09E8 7F0ABE78 3C018006 */  lui   $at, %hi(D_80058564) # $at, 0x8006
/* 0E09EC 7F0ABE7C C42685A4 */  lwc1  $f6, %lo(D_80058564)($at)
/* 0E09F0 7F0ABE80 46008107 */  neg.s $f4, $f16
/* 0E09F4 7F0ABE84 27A5047C */  addiu $a1, $sp, 0x47c
/* 0E09F8 7F0ABE88 0FC162A4 */  jal   matrix_4x4_set_rotation_around_x
/* 0E09FC 7F0ABE8C 46062301 */   sub.s $f12, $f4, $f6
/* 0E0A00 7F0ABE90 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0E0A04 7F0ABE94 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0E0A08 7F0ABE98 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0A0C 7F0ABE9C 27A6043C */   addiu $a2, $sp, 0x43c
/* 0E0A10 7F0ABEA0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0E0A14 7F0ABEA4 27A5047C */  addiu $a1, $sp, 0x47c
/* 0E0A18 7F0ABEA8 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0A1C 7F0ABEAC 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0E0A20 7F0ABEB0 27A40370 */  addiu $a0, $sp, 0x370
/* 0E0A24 7F0ABEB4 0FC163A1 */  jal   matrix_4x4_set_identity_and_position
/* 0E0A28 7F0ABEB8 27A5043C */   addiu $a1, $sp, 0x43c
/* 0E0A2C 7F0ABEBC 27A4043C */  addiu $a0, $sp, 0x43c
/* 0E0A30 7F0ABEC0 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0E0A34 7F0ABEC4 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0A38 7F0ABEC8 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0E0A3C 7F0ABECC 3C018006 */  lui   $at, %hi(D_80058568) # $at, 0x8006
/* 0E0A40 7F0ABED0 C42085A8 */  lwc1  $f0, %lo(D_80058568)($at)
/* 0E0A44 7F0ABED4 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0E0A48 7F0ABED8 44801000 */  mtc1  $zero, $f2
/* 0E0A4C 7F0ABEDC 44814000 */  mtc1  $at, $f8
/* 0E0A50 7F0ABEE0 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0E0A54 7F0ABEE4 44819000 */  mtc1  $at, $f18
/* 0E0A58 7F0ABEE8 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0E0A5C 7F0ABEEC 44050000 */  mfc1  $a1, $f0
/* 0E0A60 7F0ABEF0 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0E0A64 7F0ABEF4 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0E0A68 7F0ABEF8 3C074200 */  lui   $a3, 0x4200
/* 0E0A6C 7F0ABEFC E7A00010 */  swc1  $f0, 0x10($sp)
/* 0E0A70 7F0ABF00 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0E0A74 7F0ABF04 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0E0A78 7F0ABF08 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0E0A7C 7F0ABF0C E7A80018 */  swc1  $f8, 0x18($sp)
/* 0E0A80 7F0ABF10 0FC166ED */  jal   matrix_4x4_7F059694
/* 0E0A84 7F0ABF14 E7B20024 */   swc1  $f18, 0x24($sp)
/* 0E0A88 7F0ABF18 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0E0A8C 7F0ABF1C 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0E0A90 7F0ABF20 0FC1617A */  jal   matrix_4x4_multiply
/* 0E0A94 7F0ABF24 27A6037C */   addiu $a2, $sp, 0x37c
/* 0E0A98 7F0ABF28 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0E0A9C 7F0ABF2C 44815000 */  mtc1  $at, $f10
/* 0E0AA0 7F0ABF30 3C018006 */  lui   $at, %hi(D_8005856C) # $at, 0x8006
/* 0E0AA4 7F0ABF34 C43085AC */  lwc1  $f16, %lo(D_8005856C)($at)
/* 0E0AA8 7F0ABF38 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E0AAC 7F0ABF3C 44812000 */  mtc1  $at, $f4
/* 0E0AB0 7F0ABF40 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 0E0AB4 7F0ABF44 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 0E0AB8 7F0ABF48 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0E0ABC 7F0ABF4C 27A5036E */  addiu $a1, $sp, 0x36e
/* 0E0AC0 7F0ABF50 3C06424A */  lui   $a2, 0x424a
/* 0E0AC4 7F0ABF54 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0E0AC8 7F0ABF58 E7B00014 */  swc1  $f16, 0x14($sp)
/* 0E0ACC 7F0ABF5C 0C003FBC */  jal   guPerspective
/* 0E0AD0 7F0ABF60 E7A40018 */   swc1  $f4, 0x18($sp)
/* 0E0AD4 7F0ABF64 3C080103 */  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
/* 0E0AD8 7F0ABF68 35080040 */  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0E0ADC 7F0ABF6C 02001825 */  move  $v1, $s0
/* 0E0AE0 7F0ABF70 AC680000 */  sw    $t0, ($v1)
/* 0E0AE4 7F0ABF74 AFA30044 */  sw    $v1, 0x44($sp)
/* 0E0AE8 7F0ABF78 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0E0AEC 7F0ABF7C 0C003A3C */  jal   osVirtualToPhysical
/* 0E0AF0 7F0ABF80 26100008 */   addiu $s0, $s0, 8
/* 0E0AF4 7F0ABF84 8FA30044 */  lw    $v1, 0x44($sp)
/* 0E0AF8 7F0ABF88 02002025 */  move  $a0, $s0
/* 0E0AFC 7F0ABF8C 0FC29EA0 */  jal   sub_GAME_7F0A6EE8
/* 0E0B00 7F0ABF90 AC620004 */   sw    $v0, 4($v1)
/* 0E0B04 7F0ABF94 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen) # $v1, 0x8004
/* 0E0B08 7F0ABF98 8C630B34 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0E0B0C 7F0ABF9C 00408025 */  move  $s0, $v0
/* 0E0B10 7F0ABFA0 02002025 */  move  $a0, $s0
/* 0E0B14 7F0ABFA4 286100E0 */  slti  $at, $v1, 0xe0
/* 0E0B18 7F0ABFA8 1020000C */  beqz  $at, .Ljp7F0ABFDC
/* 0E0B1C 7F0ABFAC 27A5037C */   addiu $a1, $sp, 0x37c
/* 0E0B20 7F0ABFB0 27AF004C */  addiu $t7, $sp, 0x4c
/* 0E0B24 7F0ABFB4 27A902E2 */  addiu $t1, $sp, 0x2e2
/* 0E0B28 7F0ABFB8 AFA90014 */  sw    $t1, 0x14($sp)
/* 0E0B2C 7F0ABFBC AFAF0010 */  sw    $t7, 0x10($sp)
/* 0E0B30 7F0ABFC0 00402025 */  move  $a0, $v0
/* 0E0B34 7F0ABFC4 27A5037C */  addiu $a1, $sp, 0x37c
/* 0E0B38 7F0ABFC8 2466FFFA */  addiu $a2, $v1, -6
/* 0E0B3C 7F0ABFCC 0FC18EB2 */  jal   sub_GAME_7F06359C
/* 0E0B40 7F0ABFD0 24070001 */   li    $a3, 1
/* 0E0B44 7F0ABFD4 10000007 */  b     .Ljp7F0ABFF4
/* 0E0B48 7F0ABFD8 00408025 */   move  $s0, $v0
.Ljp7F0ABFDC:
/* 0E0B4C 7F0ABFDC 27AE02E2 */  addiu $t6, $sp, 0x2e2
/* 0E0B50 7F0ABFE0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0E0B54 7F0ABFE4 24060001 */  li    $a2, 1
/* 0E0B58 7F0ABFE8 0FC19224 */  jal   sub_GAME_7F064364
/* 0E0B5C 7F0ABFEC 27A7004C */   addiu $a3, $sp, 0x4c
/* 0E0B60 7F0ABFF0 00408025 */  move  $s0, $v0
.Ljp7F0ABFF4:
/* 0E0B64 7F0ABFF4 0FC29645 */  jal   controllerCheckDualControllerTypesAllowed
/* 0E0B68 7F0ABFF8 00000000 */   nop
/* 0E0B6C 7F0ABFFC 10400005 */  beqz  $v0, .Ljp7F0AC014
/* 0E0B70 7F0AC000 00000000 */   nop
/* 0E0B74 7F0AC004 0FC2ACE2 */  jal   display_text_buttons_dual_control
/* 0E0B78 7F0AC008 02002025 */   move  $a0, $s0
/* 0E0B7C 7F0AC00C 10000004 */  b     .Ljp7F0AC020
/* 0E0B80 7F0AC010 00408025 */   move  $s0, $v0
.Ljp7F0AC014:
/* 0E0B84 7F0AC014 0FC2A99E */  jal   sub_GAME_7F0A9AB8
/* 0E0B88 7F0AC018 02002025 */   move  $a0, $s0
/* 0E0B8C 7F0AC01C 00408025 */  move  $s0, $v0
.Ljp7F0AC020:
/* 0E0B90 7F0AC020 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0E0B94 7F0AC024 02001025 */  move  $v0, $s0
/* 0E0B98 7F0AC028 8FB00030 */  lw    $s0, 0x30($sp)
/* 0E0B9C 7F0AC02C 03E00008 */  jr    $ra
/* 0E0BA0 7F0AC030 27BD0540 */   addiu $sp, $sp, 0x540
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80058550
.word 0x40c90fdb /*6.2831855*/
glabel D_80058554
.word 0x3f490fdb /*0.78539819*/
glabel D_80058558
.word 0x43f78000 /*495.0*/
glabel D_8005855C
.word 0x453b8000  /*3000.0*/
glabel D_80058560
.word 0x40c90fdb /*6.2831855*/
glabel D_80058564
.word 0x3f490fdb /*0.78539819*/
glabel D_80058568
.word 0xc3fc8000 /*-505.0*/
glabel D_8005856C
.word 0x453b8000  /*3000.0*/
.text
glabel sub_GAME_7F0AADC0
/* 0DCAF0 7F0AA100 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 0DCAF4 7F0AA104 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0DCAF8 7F0AA108 AFB00030 */  sw    $s0, 0x30($sp)
/* 0DCAFC 7F0AA10C 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0DCB00 7F0AA110 00808025 */   move  $s0, $a0
/* 0DCB04 7F0AA114 3C0F8004 */  lui   $t7, %hi(D_80040B5C) # $t7, 0x8004
/* 0DCB08 7F0AA118 AFA2053C */  sw    $v0, 0x53c($sp)
/* 0DCB0C 7F0AA11C 25EFA7AC */  addiu $t7, %lo(D_80040B5C) # addiu $t7, $t7, -0x5854
/* 0DCB10 7F0AA120 8DE10000 */  lw    $at, ($t7)
/* 0DCB14 7F0AA124 27AE0370 */  addiu $t6, $sp, 0x370
/* 0DCB18 7F0AA128 8DE80004 */  lw    $t0, 4($t7)
/* 0DCB1C 7F0AA12C ADC10000 */  sw    $at, ($t6)
/* 0DCB20 7F0AA130 8DE10008 */  lw    $at, 8($t7)
/* 0DCB24 7F0AA134 3C0B8004 */  lui   $t3, %hi(D_80040B68) # $t3, 0x8004
/* 0DCB28 7F0AA138 ADC80004 */  sw    $t0, 4($t6)
/* 0DCB2C 7F0AA13C ADC10008 */  sw    $at, 8($t6)
/* 0DCB30 7F0AA140 24090001 */  li    $t1, 1
/* 0DCB34 7F0AA144 256BA7B8 */  addiu $t3, %lo(D_80040B68) # addiu $t3, $t3, -0x5848
/* 0DCB38 7F0AA148 A3A002E3 */  sb    $zero, 0x2e3($sp)
/* 0DCB3C 7F0AA14C A3A902E2 */  sb    $t1, 0x2e2($sp)
/* 0DCB40 7F0AA150 257900D8 */  addiu $t9, $t3, 0xd8
/* 0DCB44 7F0AA154 27AA0204 */  addiu $t2, $sp, 0x204
.L7F0AA158:
/* 0DCB48 7F0AA158 8D610000 */  lw    $at, ($t3)
/* 0DCB4C 7F0AA15C 256B000C */  addiu $t3, $t3, 0xc
/* 0DCB50 7F0AA160 254A000C */  addiu $t2, $t2, 0xc
/* 0DCB54 7F0AA164 AD41FFF4 */  sw    $at, -0xc($t2)
/* 0DCB58 7F0AA168 8D61FFF8 */  lw    $at, -8($t3)
/* 0DCB5C 7F0AA16C AD41FFF8 */  sw    $at, -8($t2)
/* 0DCB60 7F0AA170 8D61FFFC */  lw    $at, -4($t3)
/* 0DCB64 7F0AA174 1579FFF8 */  bne   $t3, $t9, .L7F0AA158
/* 0DCB68 7F0AA178 AD41FFFC */   sw    $at, -4($t2)
/* 0DCB6C 7F0AA17C 8D610000 */  lw    $at, ($t3)
/* 0DCB70 7F0AA180 3C0E8004 */  lui   $t6, %hi(D_80040C44) # $t6, 0x8004
/* 0DCB74 7F0AA184 25CEA894 */  addiu $t6, %lo(D_80040C44) # addiu $t6, $t6, -0x576c
/* 0DCB78 7F0AA188 25C900D8 */  addiu $t1, $t6, 0xd8
/* 0DCB7C 7F0AA18C 27B80128 */  addiu $t8, $sp, 0x128
/* 0DCB80 7F0AA190 AD410000 */  sw    $at, ($t2)
.L7F0AA194:
/* 0DCB84 7F0AA194 8DC10000 */  lw    $at, ($t6)
/* 0DCB88 7F0AA198 25CE000C */  addiu $t6, $t6, 0xc
/* 0DCB8C 7F0AA19C 2718000C */  addiu $t8, $t8, 0xc
/* 0DCB90 7F0AA1A0 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0DCB94 7F0AA1A4 8DC1FFF8 */  lw    $at, -8($t6)
/* 0DCB98 7F0AA1A8 AF01FFF8 */  sw    $at, -8($t8)
/* 0DCB9C 7F0AA1AC 8DC1FFFC */  lw    $at, -4($t6)
/* 0DCBA0 7F0AA1B0 15C9FFF8 */  bne   $t6, $t1, .L7F0AA194
/* 0DCBA4 7F0AA1B4 AF01FFFC */   sw    $at, -4($t8)
/* 0DCBA8 7F0AA1B8 8DC10000 */  lw    $at, ($t6)
/* 0DCBAC 7F0AA1BC 3C0C8004 */  lui   $t4, %hi(D_80040D20) # $t4, 0x8004
/* 0DCBB0 7F0AA1C0 258CA970 */  addiu $t4, %lo(D_80040D20) # addiu $t4, $t4, -0x5690
/* 0DCBB4 7F0AA1C4 258A00D8 */  addiu $t2, $t4, 0xd8
/* 0DCBB8 7F0AA1C8 27AD004C */  addiu $t5, $sp, 0x4c
/* 0DCBBC 7F0AA1CC AF010000 */  sw    $at, ($t8)
.L7F0AA1D0:
/* 0DCBC0 7F0AA1D0 8D810000 */  lw    $at, ($t4)
/* 0DCBC4 7F0AA1D4 258C000C */  addiu $t4, $t4, 0xc
/* 0DCBC8 7F0AA1D8 25AD000C */  addiu $t5, $t5, 0xc
/* 0DCBCC 7F0AA1DC ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0DCBD0 7F0AA1E0 8D81FFF8 */  lw    $at, -8($t4)
/* 0DCBD4 7F0AA1E4 ADA1FFF8 */  sw    $at, -8($t5)
/* 0DCBD8 7F0AA1E8 8D81FFFC */  lw    $at, -4($t4)
/* 0DCBDC 7F0AA1EC 158AFFF8 */  bne   $t4, $t2, .L7F0AA1D0
/* 0DCBE0 7F0AA1F0 ADA1FFFC */   sw    $at, -4($t5)
/* 0DCBE4 7F0AA1F4 8D810000 */  lw    $at, ($t4)
/* 0DCBE8 7F0AA1F8 3C058004 */  lui   $a1, %hi(D_80040B2C) # $a1, 0x8004
/* 0DCBEC 7F0AA1FC 3C068004 */  lui   $a2, %hi(D_80040B28) # $a2, 0x8004
/* 0DCBF0 7F0AA200 3C078004 */  lui   $a3, %hi(D_80040B24) # $a3, 0x8004
/* 0DCBF4 7F0AA204 24E7A774 */  addiu $a3, %lo(D_80040B24) # addiu $a3, $a3, -0x588c
/* 0DCBF8 7F0AA208 24C6A778 */  addiu $a2, %lo(D_80040B28) # addiu $a2, $a2, -0x5888
/* 0DCBFC 7F0AA20C 24A5A77C */  addiu $a1, %lo(D_80040B2C) # addiu $a1, $a1, -0x5884
/* 0DCC00 7F0AA210 00002025 */  move  $a0, $zero
/* 0DCC04 7F0AA214 0FC2A271 */  jal   sub_GAME_7F0A9684
/* 0DCC08 7F0AA218 ADA10000 */   sw    $at, ($t5)
/* 0DCC0C 7F0AA21C 0FC1611E */  jal   matrix_4x4_set_identity
/* 0DCC10 7F0AA220 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0DCC14 7F0AA224 3C018004 */  lui   $at, %hi(D_80040B28) # $at, 0x8004
/* 0DCC18 7F0AA228 C424A778 */  lwc1  $f4, %lo(D_80040B28)($at)
/* 0DCC1C 7F0AA22C 3C018004 */  lui   $at, %hi(jpD_800484D0) # $at, 0x8004
/* 0DCC20 7F0AA230 C4261120 */  lwc1  $f6, %lo(jpD_800484D0)($at)
/* 0DCC24 7F0AA234 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DCC28 7F0AA238 44815000 */  mtc1  $at, $f10
/* 0DCC2C 7F0AA23C 46062202 */  mul.s $f8, $f4, $f6
/* 0DCC30 7F0AA240 3C028004 */  lui   $v0, %hi(D_80040B24) # $v0, 0x8004
/* 0DCC34 7F0AA244 2442A774 */  addiu $v0, %lo(D_80040B24) # addiu $v0, $v0, -0x588c
/* 0DCC38 7F0AA248 C4520000 */  lwc1  $f18, ($v0)
/* 0DCC3C 7F0AA24C 460A4402 */  mul.s $f16, $f8, $f10
/* 0DCC40 7F0AA250 46109100 */  add.s $f4, $f18, $f16
/* 0DCC44 7F0AA254 E4440000 */  swc1  $f4, ($v0)
/* 0DCC48 7F0AA258 0FC29753 */  jal   sub_GAME_7F0A6A2C
/* 0DCC4C 7F0AA25C C44C0000 */   lwc1  $f12, ($v0)
/* 0DCC50 7F0AA260 3C018004 */  lui   $at, %hi(D_80040B24) # $at, 0x8004
/* 0DCC54 7F0AA264 E420A774 */  swc1  $f0, %lo(D_80040B24)($at)
/* 0DCC58 7F0AA268 C42CA774 */  lwc1  $f12, %lo(D_80040B24)($at)
/* 0DCC5C 7F0AA26C 0FC162CC */  jal   matrix_4x4_set_rotation_around_z
/* 0DCC60 7F0AA270 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0DCC64 7F0AA274 3C088004 */  lui   $t0, %hi(watch_item_is_actively_selected) # $t0, 0x8004
/* 0DCC68 7F0AA278 8D08A5F8 */  lw    $t0, %lo(watch_item_is_actively_selected)($t0)
/* 0DCC6C 7F0AA27C 11000016 */  beqz  $t0, .L7F0AA2D8
/* 0DCC70 7F0AA280 3C0F8004 */   lui   $t7, %hi(controller_options_index) # $t7, 0x8004
/* 0DCC74 7F0AA284 8DEFA5E8 */  lw    $t7, %lo(controller_options_index)($t7)
/* 0DCC78 7F0AA288 24010001 */  li    $at, 1
/* 0DCC7C 7F0AA28C 15E10012 */  bne   $t7, $at, .L7F0AA2D8
/* 0DCC80 7F0AA290 00000000 */   nop   
/* 0DCC84 7F0AA294 0C002BDC */  jal   joyGetStickY
/* 0DCC88 7F0AA298 00002025 */   move  $a0, $zero
/* 0DCC8C 7F0AA29C 44823000 */  mtc1  $v0, $f6
/* 0DCC90 7F0AA2A0 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0DCC94 7F0AA2A4 C42CA770 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0DCC98 7F0AA2A8 46803220 */  cvt.s.w $f8, $f6
/* 0DCC9C 7F0AA2AC 3C018005 */  lui   $at, %hi(D_80058550) # $at, 0x8005
/* 0DCCA0 7F0AA2B0 C42ACFA4 */  lwc1  $f10, %lo(D_80058550)($at)
/* 0DCCA4 7F0AA2B4 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DCCA8 7F0AA2B8 44818000 */  mtc1  $at, $f16
/* 0DCCAC 7F0AA2BC 3C064080 */  lui   $a2, 0x4080
/* 0DCCB0 7F0AA2C0 460A4482 */  mul.s $f18, $f8, $f10
/* 0DCCB4 7F0AA2C4 0FC2A241 */  jal   sub_GAME_7F0A95C4
/* 0DCCB8 7F0AA2C8 46109383 */   div.s $f14, $f18, $f16
/* 0DCCBC 7F0AA2CC 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0DCCC0 7F0AA2D0 10000008 */  b     .L7F0AA2F4
/* 0DCCC4 7F0AA2D4 E420A770 */   swc1  $f0, %lo(D_80040B20)($at)
.L7F0AA2D8:
/* 0DCCC8 7F0AA2D8 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0DCCCC 7F0AA2DC 44807000 */  mtc1  $zero, $f14
/* 0DCCD0 7F0AA2E0 C42CA770 */  lwc1  $f12, %lo(D_80040B20)($at)
/* 0DCCD4 7F0AA2E4 0FC2A241 */  jal   sub_GAME_7F0A95C4
/* 0DCCD8 7F0AA2E8 3C064080 */   lui   $a2, 0x4080
/* 0DCCDC 7F0AA2EC 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0DCCE0 7F0AA2F0 E420A770 */  swc1  $f0, %lo(D_80040B20)($at)
.L7F0AA2F4:
/* 0DCCE4 7F0AA2F4 3C018004 */  lui   $at, %hi(D_80040B20) # $at, 0x8004
/* 0DCCE8 7F0AA2F8 C424A770 */  lwc1  $f4, %lo(D_80040B20)($at)
/* 0DCCEC 7F0AA2FC 3C018005 */  lui   $at, %hi(D_80058554) # $at, 0x8005
/* 0DCCF0 7F0AA300 C428CFA8 */  lwc1  $f8, %lo(D_80058554)($at)
/* 0DCCF4 7F0AA304 46002187 */  neg.s $f6, $f4
/* 0DCCF8 7F0AA308 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DCCFC 7F0AA30C 0FC16286 */  jal   matrix_4x4_set_rotation_around_x
/* 0DCD00 7F0AA310 46083301 */   sub.s $f12, $f6, $f8
/* 0DCD04 7F0AA314 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0DCD08 7F0AA318 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0DCD0C 7F0AA31C 0FC1615C */  jal   matrix_4x4_multiply
/* 0DCD10 7F0AA320 27A6043C */   addiu $a2, $sp, 0x43c
/* 0DCD14 7F0AA324 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DCD18 7F0AA328 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DCD1C 7F0AA32C 0FC1615C */  jal   matrix_4x4_multiply
/* 0DCD20 7F0AA330 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0DCD24 7F0AA334 27A40370 */  addiu $a0, $sp, 0x370
/* 0DCD28 7F0AA338 0FC16383 */  jal   matrix_4x4_set_identity_and_position
/* 0DCD2C 7F0AA33C 27A5043C */   addiu $a1, $sp, 0x43c
/* 0DCD30 7F0AA340 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DCD34 7F0AA344 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0DCD38 7F0AA348 0FC1615C */  jal   matrix_4x4_multiply
/* 0DCD3C 7F0AA34C 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0DCD40 7F0AA350 0FC29025 */  jal   controllerCheckDualControllerTypesAllowed
/* 0DCD44 7F0AA354 00000000 */   nop   
/* 0DCD48 7F0AA358 10400018 */  beqz  $v0, .L7F0AA3BC
/* 0DCD4C 7F0AA35C 3C01C0A0 */   lui   $at, 0xc0a0
/* 0DCD50 7F0AA360 3C018005 */  li    $at, 0x80050000 # -0.000000
/* 0DCD54 7F0AA364 C420CFAC */  lwc1  $f0, %lo(D_80058558)($at)
/* 0DCD58 7F0AA368 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0DCD5C 7F0AA36C 44816000 */  mtc1  $at, $f12
/* 0DCD60 7F0AA370 44801000 */  mtc1  $zero, $f2
/* 0DCD64 7F0AA374 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DCD68 7F0AA378 44815000 */  mtc1  $at, $f10
/* 0DCD6C 7F0AA37C 27A90128 */  addiu $t1, $sp, 0x128
/* 0DCD70 7F0AA380 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0DCD74 7F0AA384 44050000 */  mfc1  $a1, $f0
/* 0DCD78 7F0AA388 44076000 */  mfc1  $a3, $f12
/* 0DCD7C 7F0AA38C AFA902E8 */  sw    $t1, 0x2e8($sp)
/* 0DCD80 7F0AA390 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0DCD84 7F0AA394 27A4032C */  addiu $a0, $sp, 0x32c
/* 0DCD88 7F0AA398 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DCD8C 7F0AA39C E7AC0018 */  swc1  $f12, 0x18($sp)
/* 0DCD90 7F0AA3A0 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0DCD94 7F0AA3A4 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DCD98 7F0AA3A8 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0DCD9C 7F0AA3AC 0FC166CF */  jal   matrix_4x4_7F059694
/* 0DCDA0 7F0AA3B0 E7AA0024 */   swc1  $f10, 0x24($sp)
/* 0DCDA4 7F0AA3B4 10000017 */  b     .L7F0AA414
/* 0DCDA8 7F0AA3B8 27A4032C */   addiu $a0, $sp, 0x32c
.L7F0AA3BC:
/* 0DCDAC 7F0AA3BC 44810000 */  mtc1  $at, $f0
/* 0DCDB0 7F0AA3C0 3C01C328 */  li    $at, 0xC3280000 # -168.000000
/* 0DCDB4 7F0AA3C4 44811000 */  mtc1  $at, $f2
/* 0DCDB8 7F0AA3C8 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DCDBC 7F0AA3CC 44813000 */  mtc1  $at, $f6
/* 0DCDC0 7F0AA3D0 44809000 */  mtc1  $zero, $f18
/* 0DCDC4 7F0AA3D4 44808000 */  mtc1  $zero, $f16
/* 0DCDC8 7F0AA3D8 44802000 */  mtc1  $zero, $f4
/* 0DCDCC 7F0AA3DC 27AE0204 */  addiu $t6, $sp, 0x204
/* 0DCDD0 7F0AA3E0 44050000 */  mfc1  $a1, $f0
/* 0DCDD4 7F0AA3E4 44071000 */  mfc1  $a3, $f2
/* 0DCDD8 7F0AA3E8 AFAE02E8 */  sw    $t6, 0x2e8($sp)
/* 0DCDDC 7F0AA3EC 27A4032C */  addiu $a0, $sp, 0x32c
/* 0DCDE0 7F0AA3F0 3C0644FA */  lui   $a2, 0x44fa
/* 0DCDE4 7F0AA3F4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DCDE8 7F0AA3F8 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0DCDEC 7F0AA3FC E7A60024 */  swc1  $f6, 0x24($sp)
/* 0DCDF0 7F0AA400 E7B20014 */  swc1  $f18, 0x14($sp)
/* 0DCDF4 7F0AA404 E7B0001C */  swc1  $f16, 0x1c($sp)
/* 0DCDF8 7F0AA408 0FC166CF */  jal   matrix_4x4_7F059694
/* 0DCDFC 7F0AA40C E7A40020 */   swc1  $f4, 0x20($sp)
/* 0DCE00 7F0AA410 27A4032C */  addiu $a0, $sp, 0x32c
.L7F0AA414:
/* 0DCE04 7F0AA414 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0DCE08 7F0AA418 0FC1615C */  jal   matrix_4x4_multiply
/* 0DCE0C 7F0AA41C 27A6037C */   addiu $a2, $sp, 0x37c
/* 0DCE10 7F0AA420 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0DCE14 7F0AA424 44814000 */  mtc1  $at, $f8
/* 0DCE18 7F0AA428 3C018005 */  lui   $at, %hi(D_8005855C) # $at, 0x8005
/* 0DCE1C 7F0AA42C C42ACFB0 */  lwc1  $f10, %lo(D_8005855C)($at)
/* 0DCE20 7F0AA430 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DCE24 7F0AA434 44819000 */  mtc1  $at, $f18
/* 0DCE28 7F0AA438 3C073FA4 */  lui   $a3, (0x3FA45519 >> 16) # lui $a3, 0x3fa4
/* 0DCE2C 7F0AA43C 34E75519 */  ori   $a3, (0x3FA45519 & 0xFFFF) # ori $a3, $a3, 0x5519
/* 0DCE30 7F0AA440 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DCE34 7F0AA444 27A5036E */  addiu $a1, $sp, 0x36e
/* 0DCE38 7F0AA448 3C064252 */  lui   $a2, 0x4252
/* 0DCE3C 7F0AA44C E7A80010 */  swc1  $f8, 0x10($sp)
/* 0DCE40 7F0AA450 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 0DCE44 7F0AA454 0C003DB8 */  jal   guPerspective
/* 0DCE48 7F0AA458 E7B20018 */   swc1  $f18, 0x18($sp)
/* 0DCE4C 7F0AA45C 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0DCE50 7F0AA460 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0DCE54 7F0AA464 02001825 */  move  $v1, $s0
/* 0DCE58 7F0AA468 AC780000 */  sw    $t8, ($v1)
/* 0DCE5C 7F0AA46C AFA30048 */  sw    $v1, 0x48($sp)
/* 0DCE60 7F0AA470 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DCE64 7F0AA474 0C003838 */  jal   osVirtualToPhysical
/* 0DCE68 7F0AA478 26100008 */   addiu $s0, $s0, 8
/* 0DCE6C 7F0AA47C 8FA30048 */  lw    $v1, 0x48($sp)
/* 0DCE70 7F0AA480 02002025 */  move  $a0, $s0
/* 0DCE74 7F0AA484 0FC29880 */  jal   sub_GAME_7F0A6EE8
/* 0DCE78 7F0AA488 AC620004 */   sw    $v0, 4($v1)
/* 0DCE7C 7F0AA48C 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen) # $v1, 0x8004
/* 0DCE80 7F0AA490 8C63A754 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0DCE84 7F0AA494 00408025 */  move  $s0, $v0
/* 0DCE88 7F0AA498 02002025 */  move  $a0, $s0
/* 0DCE8C 7F0AA49C 286100E0 */  slti  $at, $v1, 0xe0
/* 0DCE90 7F0AA4A0 1020000C */  beqz  $at, .L7F0AA4D4
/* 0DCE94 7F0AA4A4 27A5037C */   addiu $a1, $sp, 0x37c
/* 0DCE98 7F0AA4A8 8FAB02E8 */  lw    $t3, 0x2e8($sp)
/* 0DCE9C 7F0AA4AC 27B902E3 */  addiu $t9, $sp, 0x2e3
/* 0DCEA0 7F0AA4B0 AFB90014 */  sw    $t9, 0x14($sp)
/* 0DCEA4 7F0AA4B4 00402025 */  move  $a0, $v0
/* 0DCEA8 7F0AA4B8 27A5037C */  addiu $a1, $sp, 0x37c
/* 0DCEAC 7F0AA4BC 2466FFFA */  addiu $a2, $v1, -6
/* 0DCEB0 7F0AA4C0 24070001 */  li    $a3, 1
/* 0DCEB4 7F0AA4C4 0FC18E98 */  jal   sub_GAME_7F06359C
/* 0DCEB8 7F0AA4C8 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0DCEBC 7F0AA4CC 10000007 */  b     .L7F0AA4EC
/* 0DCEC0 7F0AA4D0 00408025 */   move  $s0, $v0
.L7F0AA4D4:
/* 0DCEC4 7F0AA4D4 27AA02E3 */  addiu $t2, $sp, 0x2e3
/* 0DCEC8 7F0AA4D8 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0DCECC 7F0AA4DC 24060001 */  li    $a2, 1
/* 0DCED0 7F0AA4E0 0FC1920A */  jal   sub_GAME_7F064364
/* 0DCED4 7F0AA4E4 8FA702E8 */   lw    $a3, 0x2e8($sp)
/* 0DCED8 7F0AA4E8 00408025 */  move  $s0, $v0
.L7F0AA4EC:
/* 0DCEDC 7F0AA4EC 0FC29025 */  jal   controllerCheckDualControllerTypesAllowed
/* 0DCEE0 7F0AA4F0 00000000 */   nop   
/* 0DCEE4 7F0AA4F4 1040009F */  beqz  $v0, .L7F0AA774
/* 0DCEE8 7F0AA4F8 24040001 */   li    $a0, 1
/* 0DCEEC 7F0AA4FC 3C058004 */  lui   $a1, %hi(D_80040B3C) # $a1, 0x8004
/* 0DCEF0 7F0AA500 3C068004 */  lui   $a2, %hi(D_80040B38) # $a2, 0x8004
/* 0DCEF4 7F0AA504 3C078004 */  lui   $a3, %hi(D_80040B34) # $a3, 0x8004
/* 0DCEF8 7F0AA508 24E7A784 */  addiu $a3, %lo(D_80040B34) # addiu $a3, $a3, -0x587c
/* 0DCEFC 7F0AA50C 24C6A788 */  addiu $a2, %lo(D_80040B38) # addiu $a2, $a2, -0x5878
/* 0DCF00 7F0AA510 0FC2A271 */  jal   sub_GAME_7F0A9684
/* 0DCF04 7F0AA514 24A5A78C */   addiu $a1, %lo(D_80040B3C) # addiu $a1, $a1, -0x5874
/* 0DCF08 7F0AA518 0FC1611E */  jal   matrix_4x4_set_identity
/* 0DCF0C 7F0AA51C 27A404FC */   addiu $a0, $sp, 0x4fc
/* 0DCF10 7F0AA520 3C018004 */  lui   $at, %hi(D_80040B38) # $at, 0x8004
/* 0DCF14 7F0AA524 C430A788 */  lwc1  $f16, %lo(D_80040B38)($at)
/* 0DCF18 7F0AA528 3C018004 */  lui   $at, %hi(jpD_800484D0) # $at, 0x8004
/* 0DCF1C 7F0AA52C C4241120 */  lwc1  $f4, %lo(jpD_800484D0)($at)
/* 0DCF20 7F0AA530 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DCF24 7F0AA534 44814000 */  mtc1  $at, $f8
/* 0DCF28 7F0AA538 46048182 */  mul.s $f6, $f16, $f4
/* 0DCF2C 7F0AA53C 3C028004 */  lui   $v0, %hi(D_80040B34) # $v0, 0x8004
/* 0DCF30 7F0AA540 2442A784 */  addiu $v0, %lo(D_80040B34) # addiu $v0, $v0, -0x587c
/* 0DCF34 7F0AA544 C4520000 */  lwc1  $f18, ($v0)
/* 0DCF38 7F0AA548 46083282 */  mul.s $f10, $f6, $f8
/* 0DCF3C 7F0AA54C 460A9400 */  add.s $f16, $f18, $f10
/* 0DCF40 7F0AA550 E4500000 */  swc1  $f16, ($v0)
/* 0DCF44 7F0AA554 0FC29753 */  jal   sub_GAME_7F0A6A2C
/* 0DCF48 7F0AA558 C44C0000 */   lwc1  $f12, ($v0)
/* 0DCF4C 7F0AA55C 3C018004 */  lui   $at, %hi(D_80040B34) # $at, 0x8004
/* 0DCF50 7F0AA560 E420A784 */  swc1  $f0, %lo(D_80040B34)($at)
/* 0DCF54 7F0AA564 C42CA784 */  lwc1  $f12, %lo(D_80040B34)($at)
/* 0DCF58 7F0AA568 0FC162CC */  jal   matrix_4x4_set_rotation_around_z
/* 0DCF5C 7F0AA56C 27A504BC */   addiu $a1, $sp, 0x4bc
/* 0DCF60 7F0AA570 3C0C8004 */  lui   $t4, %hi(watch_item_is_actively_selected) # $t4, 0x8004
/* 0DCF64 7F0AA574 8D8CA5F8 */  lw    $t4, %lo(watch_item_is_actively_selected)($t4)
/* 0DCF68 7F0AA578 11800016 */  beqz  $t4, .L7F0AA5D4
/* 0DCF6C 7F0AA57C 3C0D8004 */   lui   $t5, %hi(controller_options_index) # $t5, 0x8004
/* 0DCF70 7F0AA580 8DADA5E8 */  lw    $t5, %lo(controller_options_index)($t5)
/* 0DCF74 7F0AA584 24010001 */  li    $at, 1
/* 0DCF78 7F0AA588 15A10012 */  bne   $t5, $at, .L7F0AA5D4
/* 0DCF7C 7F0AA58C 00000000 */   nop   
/* 0DCF80 7F0AA590 0C002BDC */  jal   joyGetStickY
/* 0DCF84 7F0AA594 24040001 */   li    $a0, 1
/* 0DCF88 7F0AA598 44822000 */  mtc1  $v0, $f4
/* 0DCF8C 7F0AA59C 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0DCF90 7F0AA5A0 C42CA780 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0DCF94 7F0AA5A4 468021A0 */  cvt.s.w $f6, $f4
/* 0DCF98 7F0AA5A8 3C018005 */  lui   $at, %hi(D_80058560) # $at, 0x8005
/* 0DCF9C 7F0AA5AC C428CFB4 */  lwc1  $f8, %lo(D_80058560)($at)
/* 0DCFA0 7F0AA5B0 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0DCFA4 7F0AA5B4 44815000 */  mtc1  $at, $f10
/* 0DCFA8 7F0AA5B8 3C064080 */  lui   $a2, 0x4080
/* 0DCFAC 7F0AA5BC 46083482 */  mul.s $f18, $f6, $f8
/* 0DCFB0 7F0AA5C0 0FC2A241 */  jal   sub_GAME_7F0A95C4
/* 0DCFB4 7F0AA5C4 460A9383 */   div.s $f14, $f18, $f10
/* 0DCFB8 7F0AA5C8 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0DCFBC 7F0AA5CC 10000008 */  b     .L7F0AA5F0
/* 0DCFC0 7F0AA5D0 E420A780 */   swc1  $f0, %lo(D_80040B30)($at)
.L7F0AA5D4:
/* 0DCFC4 7F0AA5D4 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0DCFC8 7F0AA5D8 44807000 */  mtc1  $zero, $f14
/* 0DCFCC 7F0AA5DC C42CA780 */  lwc1  $f12, %lo(D_80040B30)($at)
/* 0DCFD0 7F0AA5E0 0FC2A241 */  jal   sub_GAME_7F0A95C4
/* 0DCFD4 7F0AA5E4 3C064080 */   lui   $a2, 0x4080
/* 0DCFD8 7F0AA5E8 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0DCFDC 7F0AA5EC E420A780 */  swc1  $f0, %lo(D_80040B30)($at)
.L7F0AA5F0:
/* 0DCFE0 7F0AA5F0 3C018004 */  lui   $at, %hi(D_80040B30) # $at, 0x8004
/* 0DCFE4 7F0AA5F4 C430A780 */  lwc1  $f16, %lo(D_80040B30)($at)
/* 0DCFE8 7F0AA5F8 3C018005 */  lui   $at, %hi(D_80058564) # $at, 0x8005
/* 0DCFEC 7F0AA5FC C426CFB8 */  lwc1  $f6, %lo(D_80058564)($at)
/* 0DCFF0 7F0AA600 46008107 */  neg.s $f4, $f16
/* 0DCFF4 7F0AA604 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DCFF8 7F0AA608 0FC16286 */  jal   matrix_4x4_set_rotation_around_x
/* 0DCFFC 7F0AA60C 46062301 */   sub.s $f12, $f4, $f6
/* 0DD000 7F0AA610 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0DD004 7F0AA614 27A504BC */  addiu $a1, $sp, 0x4bc
/* 0DD008 7F0AA618 0FC1615C */  jal   matrix_4x4_multiply
/* 0DD00C 7F0AA61C 27A6043C */   addiu $a2, $sp, 0x43c
/* 0DD010 7F0AA620 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DD014 7F0AA624 27A5047C */  addiu $a1, $sp, 0x47c
/* 0DD018 7F0AA628 0FC1615C */  jal   matrix_4x4_multiply
/* 0DD01C 7F0AA62C 27A603FC */   addiu $a2, $sp, 0x3fc
/* 0DD020 7F0AA630 27A40370 */  addiu $a0, $sp, 0x370
/* 0DD024 7F0AA634 0FC16383 */  jal   matrix_4x4_set_identity_and_position
/* 0DD028 7F0AA638 27A5043C */   addiu $a1, $sp, 0x43c
/* 0DD02C 7F0AA63C 27A4043C */  addiu $a0, $sp, 0x43c
/* 0DD030 7F0AA640 27A503FC */  addiu $a1, $sp, 0x3fc
/* 0DD034 7F0AA644 0FC1615C */  jal   matrix_4x4_multiply
/* 0DD038 7F0AA648 27A603BC */   addiu $a2, $sp, 0x3bc
/* 0DD03C 7F0AA64C 3C018005 */  lui   $at, %hi(D_80058568) # $at, 0x8005
/* 0DD040 7F0AA650 C420CFBC */  lwc1  $f0, %lo(D_80058568)($at)
/* 0DD044 7F0AA654 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0DD048 7F0AA658 44801000 */  mtc1  $zero, $f2
/* 0DD04C 7F0AA65C 44814000 */  mtc1  $at, $f8
/* 0DD050 7F0AA660 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0DD054 7F0AA664 44819000 */  mtc1  $at, $f18
/* 0DD058 7F0AA668 3C06451C */  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
/* 0DD05C 7F0AA66C 44050000 */  mfc1  $a1, $f0
/* 0DD060 7F0AA670 34C64000 */  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
/* 0DD064 7F0AA674 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0DD068 7F0AA678 3C074200 */  lui   $a3, 0x4200
/* 0DD06C 7F0AA67C E7A00010 */  swc1  $f0, 0x10($sp)
/* 0DD070 7F0AA680 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0DD074 7F0AA684 E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0DD078 7F0AA688 E7A20020 */  swc1  $f2, 0x20($sp)
/* 0DD07C 7F0AA68C E7A80018 */  swc1  $f8, 0x18($sp)
/* 0DD080 7F0AA690 0FC166CF */  jal   matrix_4x4_7F059694
/* 0DD084 7F0AA694 E7B20024 */   swc1  $f18, 0x24($sp)
/* 0DD088 7F0AA698 27A402EC */  addiu $a0, $sp, 0x2ec
/* 0DD08C 7F0AA69C 27A503BC */  addiu $a1, $sp, 0x3bc
/* 0DD090 7F0AA6A0 0FC1615C */  jal   matrix_4x4_multiply
/* 0DD094 7F0AA6A4 27A6037C */   addiu $a2, $sp, 0x37c
/* 0DD098 7F0AA6A8 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0DD09C 7F0AA6AC 44815000 */  mtc1  $at, $f10
/* 0DD0A0 7F0AA6B0 3C018005 */  lui   $at, %hi(D_8005856C) # $at, 0x8005
/* 0DD0A4 7F0AA6B4 C430CFC0 */  lwc1  $f16, %lo(D_8005856C)($at)
/* 0DD0A8 7F0AA6B8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DD0AC 7F0AA6BC 44812000 */  mtc1  $at, $f4
/* 0DD0B0 7F0AA6C0 3C073FA4 */  lui   $a3, (0x3FA45519 >> 16) # lui $a3, 0x3fa4
/* 0DD0B4 7F0AA6C4 34E75519 */  ori   $a3, (0x3FA45519 & 0xFFFF) # ori $a3, $a3, 0x5519
/* 0DD0B8 7F0AA6C8 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DD0BC 7F0AA6CC 27A5036E */  addiu $a1, $sp, 0x36e
/* 0DD0C0 7F0AA6D0 3C064252 */  lui   $a2, 0x4252
/* 0DD0C4 7F0AA6D4 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0DD0C8 7F0AA6D8 E7B00014 */  swc1  $f16, 0x14($sp)
/* 0DD0CC 7F0AA6DC 0C003DB8 */  jal   guPerspective
/* 0DD0D0 7F0AA6E0 E7A40018 */   swc1  $f4, 0x18($sp)
/* 0DD0D4 7F0AA6E4 3C080103 */  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
/* 0DD0D8 7F0AA6E8 35080040 */  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0DD0DC 7F0AA6EC 02001825 */  move  $v1, $s0
/* 0DD0E0 7F0AA6F0 AC680000 */  sw    $t0, ($v1)
/* 0DD0E4 7F0AA6F4 AFA30044 */  sw    $v1, 0x44($sp)
/* 0DD0E8 7F0AA6F8 8FA4053C */  lw    $a0, 0x53c($sp)
/* 0DD0EC 7F0AA6FC 0C003838 */  jal   osVirtualToPhysical
/* 0DD0F0 7F0AA700 26100008 */   addiu $s0, $s0, 8
/* 0DD0F4 7F0AA704 8FA30044 */  lw    $v1, 0x44($sp)
/* 0DD0F8 7F0AA708 02002025 */  move  $a0, $s0
/* 0DD0FC 7F0AA70C 0FC29880 */  jal   sub_GAME_7F0A6EE8
/* 0DD100 7F0AA710 AC620004 */   sw    $v0, 4($v1)
/* 0DD104 7F0AA714 3C038004 */  lui   $v1, %hi(g_WatchBackgroundGreen) # $v1, 0x8004
/* 0DD108 7F0AA718 8C63A754 */  lw    $v1, %lo(g_WatchBackgroundGreen)($v1)
/* 0DD10C 7F0AA71C 00408025 */  move  $s0, $v0
/* 0DD110 7F0AA720 02002025 */  move  $a0, $s0
/* 0DD114 7F0AA724 286100E0 */  slti  $at, $v1, 0xe0
/* 0DD118 7F0AA728 1020000C */  beqz  $at, .L7F0AA75C
/* 0DD11C 7F0AA72C 27A5037C */   addiu $a1, $sp, 0x37c
/* 0DD120 7F0AA730 27AF004C */  addiu $t7, $sp, 0x4c
/* 0DD124 7F0AA734 27A902E2 */  addiu $t1, $sp, 0x2e2
/* 0DD128 7F0AA738 AFA90014 */  sw    $t1, 0x14($sp)
/* 0DD12C 7F0AA73C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DD130 7F0AA740 00402025 */  move  $a0, $v0
/* 0DD134 7F0AA744 27A5037C */  addiu $a1, $sp, 0x37c
/* 0DD138 7F0AA748 2466FFFA */  addiu $a2, $v1, -6
/* 0DD13C 7F0AA74C 0FC18E98 */  jal   sub_GAME_7F06359C
/* 0DD140 7F0AA750 24070001 */   li    $a3, 1
/* 0DD144 7F0AA754 10000007 */  b     .L7F0AA774
/* 0DD148 7F0AA758 00408025 */   move  $s0, $v0
.L7F0AA75C:
/* 0DD14C 7F0AA75C 27AE02E2 */  addiu $t6, $sp, 0x2e2
/* 0DD150 7F0AA760 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0DD154 7F0AA764 24060001 */  li    $a2, 1
/* 0DD158 7F0AA768 0FC1920A */  jal   sub_GAME_7F064364
/* 0DD15C 7F0AA76C 27A7004C */   addiu $a3, $sp, 0x4c
/* 0DD160 7F0AA770 00408025 */  move  $s0, $v0
.L7F0AA774:
/* 0DD164 7F0AA774 0FC29025 */  jal   controllerCheckDualControllerTypesAllowed
/* 0DD168 7F0AA778 00000000 */   nop   
/* 0DD16C 7F0AA77C 10400005 */  beqz  $v0, .L7F0AA794
/* 0DD170 7F0AA780 00000000 */   nop   
/* 0DD174 7F0AA784 0FC2A6C2 */  jal   display_text_buttons_dual_control
/* 0DD178 7F0AA788 02002025 */   move  $a0, $s0
/* 0DD17C 7F0AA78C 10000004 */  b     .L7F0AA7A0
/* 0DD180 7F0AA790 00408025 */   move  $s0, $v0
.L7F0AA794:
/* 0DD184 7F0AA794 0FC2A37E */  jal   sub_GAME_7F0A9AB8
/* 0DD188 7F0AA798 02002025 */   move  $a0, $s0
/* 0DD18C 7F0AA79C 00408025 */  move  $s0, $v0
.L7F0AA7A0:
/* 0DD190 7F0AA7A0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0DD194 7F0AA7A4 02001025 */  move  $v0, $s0
/* 0DD198 7F0AA7A8 8FB00030 */  lw    $s0, 0x30($sp)
/* 0DD19C 7F0AA7AC 03E00008 */  jr    $ra
/* 0DD1A0 7F0AA7B0 27BD0540 */   addiu $sp, $sp, 0x540
)
#endif

#endif





void reset_controller_options_index(void) {
    controller_options_index = 0;
}


void reset_game_options_index(void) {
    game_options_index = 0;
}


void zero_D_800409A4(void) {
    D_800409A4 = 0;
}


u32 return_arg0_7F0AB4B0(u32 uParm1) {
    return uParm1;
}


Gfx *draw_watch_control_options_page(Gfx *gdl, Mtx *param_2) {
    s32 phi_s1;
    u16 *textptr;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 ptr_first_font;
    s32 ptr_second_font;

    gdl = draw_background_health_and_armor(gdl, param_2, 0);
    
    if (check_watch_page_transistion_running() != 1) {
        
        gdl = sub_GAME_7F0AADC0(gdl);
        ptr_first_font = ptrFirstFontTableSmall;
        ptr_second_font = ptrSecondFontTableSmall;
        
        gdl = microcode_constructor(gdl);
        textptr = langGet(TEXT(LOPTIONS, 0x32)); //control style
    
        sp5C = XOFFSET_1;
        sp58 = 0x1A;
        phi_s1 = 0xFF00B0;
        if (controller_options_index == 0)
        {
            phi_s1 = 0xA0FFA0F0;
            if (watch_item_is_actively_selected != 0)
            {
                phi_s1 = -1;
            }
        }
        
        sub_GAME_7F0AE98C(&sp50, &sp54, textptr, ptr_second_font, ptr_first_font, 0);
        
        if ((watch_item_is_actively_selected != 0) && (controller_options_index == 0))
        {
            gdl = jp_text_write_stuff(gdl, &sp5C, &sp58, textptr, ptr_second_font, ptr_first_font, phi_s1, 0x7000A0, sp54 + 1, sp50, 0, 0);
        } else
        {
            gdl = en_text_write_stuff(gdl, &sp5C, &sp58, textptr, ptr_second_font, ptr_first_font, phi_s1, sp54, sp50, 0, 0);
        }
        
        gdl = sub_GAME_7F0A97D0(gdl);
        textptr = langGet(TEXT(LOPTIONS, 0x33)); //controller;
        
        phi_s1 = 0xFF00B0;
        
        if (controllerCheckDualControllerTypesAllowed())
        {
            textptr = langGet(TEXT(LOPTIONS, 0x34)); //controllers;
        }
        sp5C = XOFFSET_1;
        sp58 = 0x2B;
        
        if (controller_options_index == 1)
        {
            phi_s1 = 0xA0FFA0F0;
            if (watch_item_is_actively_selected != 0)
            {
                phi_s1 = -1;
            }
        }
        
        sub_GAME_7F0AE98C(&sp50, &sp54, textptr, ptr_second_font, ptr_first_font, 0);

        if ((watch_item_is_actively_selected != 0) && (controller_options_index == 1))
        {
            gdl = jp_text_write_stuff(gdl, &sp5C, &sp58, textptr, ptr_second_font, ptr_first_font, phi_s1, 0x7000A0, sp54 + 1, sp50, 0, 0);
        } else
        {
            gdl = en_text_write_stuff(gdl, &sp5C, &sp58, textptr, ptr_second_font, ptr_first_font, phi_s1, sp54, sp50, 0, 0);
        }
        
    }
    return gdl;
}


void game_option_select_value(u32 *param_1, u32 param_2)
{
    *param_1 = param_2;
    set_controlstick_lr_disabled();
    sndPlaySfx(g_musicSfxBufferPtr, OPTION_CHOOSE_SFX, NULL);
}


void game_option_toggle_input(s32 option_index)
{
    if ( (joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS|L_TRIG|L_JPAD) || sub_GAME_7F0A4FB0()) && watch_item_is_actively_selected )
    {
        if (game_options_entries[option_index].current_value == 1)
        {
            game_option_select_value(&game_options_entries[option_index].current_value, 0);
        }
        else if (game_options_entries[option_index].current_value == 2)
        {
            game_option_select_value(&game_options_entries[option_index].current_value, 1);
        }
    }
    else
    {
        if ( (joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS|R_TRIG|R_JPAD) || sub_GAME_7F0A4FEC()) && watch_item_is_actively_selected )
        {
            if (game_options_entries[option_index].current_value == 0)
            {
                game_option_select_value(&game_options_entries[option_index].current_value, 1);
            }
            else if ( (game_options_entries[option_index].current_value == 1) && game_options_entries[option_index].text[3] )
            {
                game_option_select_value(&game_options_entries[option_index].current_value, 2);
            }
        }
    }
}




#ifdef NONMATCHING
void sub_GAME_7F0AB908(s32 param_1, u32 param_2, int param_3, s32 param_4)
{
//   u32 uVar1;
  u8 pbVar2;
  u32 puVar3;
  u32 uVar4;

  //s32 puVar5;
  s32 puVar6;
  s32 puVar7;

  u32 local_res0;
  u32 local_14;
  s32 local_c;

  puVar7 = 0x800080;
  puVar6 = 0x800080;
  local_c = 0x800080;

    if (j_text_trigger != 0)
    {
        uVar4 = 0xAA;
    }
    else
    {
        uVar4 = 0xB4;
    }

    if (j_text_trigger != 0)
    {
        local_14 = 0xDC;
    }
    else
    {
        local_14 = 0xE1;
    }


    //L7F0AB958 - GOOD TEXT
    if (param_4 != 0) {

        if (param_4 != 1) {

            if (param_4 != 2) {

                // puVar5 = game_options_entries[param_3];
                // puVar6 = puVar7;

                puVar6 = 0x800080;
                puVar7 = 0x800080;

            } else {

                game_option_toggle_input(param_3);

                // puVar5 = game_options_entries[param_3];
                // uVar1 = game_options_entries[param_3].current_value;

                puVar6 = 0x800080;
                puVar7 = 0x800080;

                if (game_options_entries[param_3].current_value == 0) {
                    puVar6 = 0xa0ffa0f0;
                }
                else {
                    if (game_options_entries[param_3].current_value == 1) {
                        puVar7 = 0xa0ffa0f0;
                    }
                    else {
                        if (game_options_entries[param_3].current_value == 2) {
                            local_c = 0xa0ffa0f0;
                        }
                    }
                }
            }

        }
        else {
            //   puVar5 = game_options_entries[param_3].text;
            // uVar1 = game_options_entries[param_3].current_value;
            if (game_options_entries[param_3].current_value == 0) {
                puVar6 = 0xff00b0;
            }
            else {
                if (game_options_entries[param_3].current_value == 1) {
                    puVar7 = 0xff00b0;
                }
                else {
                    if (game_options_entries[param_3].current_value == 2) {
                        local_c = 0xff00b0;
                    }
                }
            }
        }

    } else {
        // puVar5 = game_options_entries[param_3].text;
        // uVar1 = game_options_entries[param_3].current_value;

        if (game_options_entries[param_3].current_value == 0) {
            puVar6 = 0xff00b0;
        }

        else {
            if (game_options_entries[param_3].current_value == 1) {
                puVar7 = 0xff00b0;
            }
            else {
                if (game_options_entries[param_3].current_value == 2) {
                    local_c = 0xff00b0;
                }
            }
        }
    }


    if (game_options_entries[param_3].text[3] == 0)
    {
        uVar4 = 0xC8;
        if (j_text_trigger != 0)
        {
            uVar4 = 0xBE;
        }

        if (j_text_trigger != 0)
        {
            local_14 = 0xFA;
        }
        else
        {
            local_14 = 0xFA;
        }
    }



  pbVar2 = langGet(game_options_entries[param_3].text[1]);
  puVar3 = proc_7F0A9398(param_1, uVar4, param_2, pbVar2, puVar6, 0, 0xffffffff,1,0, 0x3000B0,0);
  //arg0 = sub_GAME_7F0A9398(arg0, phi_a1_2, arg1, langGet(game_options_entries[PLAYER_OPTION_AUTOAIM].text, phi_a1_2, arg2), phi_t1, 0, -1, 1, 0, 0x3000B0, 0);

  pbVar2 = langGet(game_options_entries[param_3].text[2]);
  local_res0 = proc_7F0A9398(puVar3, local_14, param_2, pbVar2, puVar7,0,0xffffffff,1,0, 0x3000B0, 0);

  if (game_options_entries[param_3].text[3] != 0) {
    pbVar2 = langGet(game_options_entries[param_3].text[3]);
    local_res0 = proc_7F0A9398(local_res0, 0x10e, param_2, pbVar2, local_c,0,0xffffffff,1,0, 0x3000B0, 0);
  }

  //return local_res0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AB908
/* 0E0438 7F0AB908 3C038005 */  lui   $v1, %hi(j_text_trigger)
/* 0E043C 7F0AB90C 8C6384D0 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0E0440 7F0AB910 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0E0444 7F0AB914 3C020080 */  lui   $v0, 0x80
/* 0E0448 7F0AB918 344A0080 */  ori   $t2, $v0, 0x80
/* 0E044C 7F0AB91C AFBF0034 */  sw    $ra, 0x34($sp)
/* 0E0450 7F0AB920 AFA40060 */  sw    $a0, 0x60($sp)
/* 0E0454 7F0AB924 AFA50064 */  sw    $a1, 0x64($sp)
/* 0E0458 7F0AB928 01404825 */  move  $t1, $t2
/* 0E045C 7F0AB92C 10600003 */  beqz  $v1, .L7F0AB93C
/* 0E0460 7F0AB930 AFAA0054 */   sw    $t2, 0x54($sp)
/* 0E0464 7F0AB934 10000002 */  b     .L7F0AB940
/* 0E0468 7F0AB938 240500AA */   li    $a1, 170
.L7F0AB93C:
/* 0E046C 7F0AB93C 240500B4 */  li    $a1, 180
.L7F0AB940:
/* 0E0470 7F0AB940 10600004 */  beqz  $v1, .L7F0AB954
/* 0E0474 7F0AB944 240F00E1 */   li    $t7, 225
/* 0E0478 7F0AB948 240E00DC */  li    $t6, 220
/* 0E047C 7F0AB94C 10000002 */  b     .L7F0AB958
/* 0E0480 7F0AB950 AFAE004C */   sw    $t6, 0x4c($sp)
.L7F0AB954:
/* 0E0484 7F0AB954 AFAF004C */  sw    $t7, 0x4c($sp)
.L7F0AB958:
/* 0E0488 7F0AB958 10E0000D */  beqz  $a3, .L7F0AB990
/* 0E048C 7F0AB95C 00065880 */   sll   $t3, $a2, 2
/* 0E0490 7F0AB960 24030001 */  li    $v1, 1
/* 0E0494 7F0AB964 10E30020 */  beq   $a3, $v1, .L7F0AB9E8
/* 0E0498 7F0AB968 00067080 */   sll   $t6, $a2, 2
/* 0E049C 7F0AB96C 24010002 */  li    $at, 2
/* 0E04A0 7F0AB970 10E10032 */  beq   $a3, $at, .L7F0ABA3C
/* 0E04A4 7F0AB974 0006C080 */   sll   $t8, $a2, 2
/* 0E04A8 7F0AB978 0306C023 */  subu  $t8, $t8, $a2
/* 0E04AC 7F0AB97C 3C198004 */  lui   $t9, %hi(game_options_entries)
/* 0E04B0 7F0AB980 27390A7C */  addiu $t9, %lo(game_options_entries) # addiu $t9, $t9, 0xa7c
/* 0E04B4 7F0AB984 0018C080 */  sll   $t8, $t8, 2
/* 0E04B8 7F0AB988 1000004B */  b     .L7F0ABAB8
/* 0E04BC 7F0AB98C 03194021 */   addu  $t0, $t8, $t9
.L7F0AB990:
/* 0E04C0 7F0AB990 01665823 */  subu  $t3, $t3, $a2
/* 0E04C4 7F0AB994 3C0C8004 */  lui   $t4, %hi(game_options_entries)
/* 0E04C8 7F0AB998 258C0A7C */  addiu $t4, %lo(game_options_entries) # addiu $t4, $t4, 0xa7c
/* 0E04CC 7F0AB99C 000B5880 */  sll   $t3, $t3, 2
/* 0E04D0 7F0AB9A0 016C4021 */  addu  $t0, $t3, $t4
/* 0E04D4 7F0AB9A4 8D020008 */  lw    $v0, 8($t0)
/* 0E04D8 7F0AB9A8 24030001 */  li    $v1, 1
/* 0E04DC 7F0AB9AC 14400004 */  bnez  $v0, .L7F0AB9C0
/* 0E04E0 7F0AB9B0 00000000 */   nop
/* 0E04E4 7F0AB9B4 3C0900FF */  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
/* 0E04E8 7F0AB9B8 1000003F */  b     .L7F0ABAB8
/* 0E04EC 7F0AB9BC 352900B0 */   ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
.L7F0AB9C0:
/* 0E04F0 7F0AB9C0 14620004 */  bne   $v1, $v0, .L7F0AB9D4
/* 0E04F4 7F0AB9C4 24010002 */   li    $at, 2
/* 0E04F8 7F0AB9C8 3C0A00FF */  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
/* 0E04FC 7F0AB9CC 1000003A */  b     .L7F0ABAB8
/* 0E0500 7F0AB9D0 354A00B0 */   ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
.L7F0AB9D4:
/* 0E0504 7F0AB9D4 14410038 */  bne   $v0, $at, .L7F0ABAB8
/* 0E0508 7F0AB9D8 3C0D00FF */   lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0E050C 7F0AB9DC 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0E0510 7F0AB9E0 10000035 */  b     .L7F0ABAB8
/* 0E0514 7F0AB9E4 AFAD0054 */   sw    $t5, 0x54($sp)
.L7F0AB9E8:
/* 0E0518 7F0AB9E8 01C67023 */  subu  $t6, $t6, $a2
/* 0E051C 7F0AB9EC 3C0F8004 */  lui   $t7, %hi(game_options_entries)
/* 0E0520 7F0AB9F0 25EF0A7C */  addiu $t7, %lo(game_options_entries) # addiu $t7, $t7, 0xa7c
/* 0E0524 7F0AB9F4 000E7080 */  sll   $t6, $t6, 2
/* 0E0528 7F0AB9F8 01CF4021 */  addu  $t0, $t6, $t7
/* 0E052C 7F0AB9FC 8D020008 */  lw    $v0, 8($t0)
/* 0E0530 7F0ABA00 14400004 */  bnez  $v0, .L7F0ABA14
/* 0E0534 7F0ABA04 00000000 */   nop
/* 0E0538 7F0ABA08 3C0900FF */  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
/* 0E053C 7F0ABA0C 1000002A */  b     .L7F0ABAB8
/* 0E0540 7F0ABA10 352900B0 */   ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
.L7F0ABA14:
/* 0E0544 7F0ABA14 14620004 */  bne   $v1, $v0, .L7F0ABA28
/* 0E0548 7F0ABA18 24010002 */   li    $at, 2
/* 0E054C 7F0ABA1C 3C0A00FF */  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
/* 0E0550 7F0ABA20 10000025 */  b     .L7F0ABAB8
/* 0E0554 7F0ABA24 354A00B0 */   ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
.L7F0ABA28:
/* 0E0558 7F0ABA28 14410023 */  bne   $v0, $at, .L7F0ABAB8
/* 0E055C 7F0ABA2C 3C1800FF */   lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0E0560 7F0ABA30 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0E0564 7F0ABA34 10000020 */  b     .L7F0ABAB8
/* 0E0568 7F0ABA38 AFB80054 */   sw    $t8, 0x54($sp)
.L7F0ABA3C:
/* 0E056C 7F0ABA3C 00C02025 */  move  $a0, $a2
/* 0E0570 7F0ABA40 AFA50050 */  sw    $a1, 0x50($sp)
/* 0E0574 7F0ABA44 AFA60068 */  sw    $a2, 0x68($sp)
/* 0E0578 7F0ABA48 AFA9005C */  sw    $t1, 0x5c($sp)
/* 0E057C 7F0ABA4C 0FC2ADF6 */  jal   game_option_toggle_input
/* 0E0580 7F0ABA50 AFAA0058 */   sw    $t2, 0x58($sp)
/* 0E0584 7F0ABA54 8FA60068 */  lw    $a2, 0x68($sp)
/* 0E0588 7F0ABA58 3C0B8004 */  lui   $t3, %hi(game_options_entries)
/* 0E058C 7F0ABA5C 256B0A7C */  addiu $t3, %lo(game_options_entries) # addiu $t3, $t3, 0xa7c
/* 0E0590 7F0ABA60 0006C880 */  sll   $t9, $a2, 2
/* 0E0594 7F0ABA64 0326C823 */  subu  $t9, $t9, $a2
/* 0E0598 7F0ABA68 0019C880 */  sll   $t9, $t9, 2
/* 0E059C 7F0ABA6C 032B4021 */  addu  $t0, $t9, $t3
/* 0E05A0 7F0ABA70 8D020008 */  lw    $v0, 8($t0)
/* 0E05A4 7F0ABA74 24030001 */  li    $v1, 1
/* 0E05A8 7F0ABA78 8FA50050 */  lw    $a1, 0x50($sp)
/* 0E05AC 7F0ABA7C 8FA9005C */  lw    $t1, 0x5c($sp)
/* 0E05B0 7F0ABA80 14400004 */  bnez  $v0, .L7F0ABA94
/* 0E05B4 7F0ABA84 8FAA0058 */   lw    $t2, 0x58($sp)
/* 0E05B8 7F0ABA88 3C09A0FF */  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
/* 0E05BC 7F0ABA8C 1000000A */  b     .L7F0ABAB8
/* 0E05C0 7F0ABA90 3529A0F0 */   ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
.L7F0ABA94:
/* 0E05C4 7F0ABA94 14620004 */  bne   $v1, $v0, .L7F0ABAA8
/* 0E05C8 7F0ABA98 24010002 */   li    $at, 2
/* 0E05CC 7F0ABA9C 3C0AA0FF */  lui   $t2, (0xA0FFA0F0 >> 16) # lui $t2, 0xa0ff
/* 0E05D0 7F0ABAA0 10000005 */  b     .L7F0ABAB8
/* 0E05D4 7F0ABAA4 354AA0F0 */   ori   $t2, (0xA0FFA0F0 & 0xFFFF) # ori $t2, $t2, 0xa0f0
.L7F0ABAA8:
/* 0E05D8 7F0ABAA8 14410003 */  bne   $v0, $at, .L7F0ABAB8
/* 0E05DC 7F0ABAAC 3C0CA0FF */   lui   $t4, (0xA0FFA0F0 >> 16) # lui $t4, 0xa0ff
/* 0E05E0 7F0ABAB0 358CA0F0 */  ori   $t4, (0xA0FFA0F0 & 0xFFFF) # ori $t4, $t4, 0xa0f0
/* 0E05E4 7F0ABAB4 AFAC0054 */  sw    $t4, 0x54($sp)
.L7F0ABAB8:
/* 0E05E8 7F0ABAB8 950D0006 */  lhu   $t5, 6($t0)
/* 0E05EC 7F0ABABC 15A0000D */  bnez  $t5, .L7F0ABAF4
/* 0E05F0 7F0ABAC0 3C038005 */   lui   $v1, %hi(j_text_trigger)
/* 0E05F4 7F0ABAC4 8C6384D0 */  lw    $v1, %lo(j_text_trigger)($v1)
/* 0E05F8 7F0ABAC8 240500C8 */  li    $a1, 200
/* 0E05FC 7F0ABACC 240F00FA */  li    $t7, 250
/* 0E0600 7F0ABAD0 10600003 */  beqz  $v1, .L7F0ABAE0
/* 0E0604 7F0ABAD4 240E00FA */   li    $t6, 250
/* 0E0608 7F0ABAD8 10000001 */  b     .L7F0ABAE0
/* 0E060C 7F0ABADC 240500BE */   li    $a1, 190
.L7F0ABAE0:
/* 0E0610 7F0ABAE0 50600004 */  beql  $v1, $zero, .L7F0ABAF4
/* 0E0614 7F0ABAE4 AFAF004C */   sw    $t7, 0x4c($sp)
/* 0E0618 7F0ABAE8 10000002 */  b     .L7F0ABAF4
/* 0E061C 7F0ABAEC AFAE004C */   sw    $t6, 0x4c($sp)
/* 0E0620 7F0ABAF0 AFAF004C */  sw    $t7, 0x4c($sp)
.L7F0ABAF4:
/* 0E0624 7F0ABAF4 95040002 */  lhu   $a0, 2($t0)
/* 0E0628 7F0ABAF8 AFA50050 */  sw    $a1, 0x50($sp)
/* 0E062C 7F0ABAFC AFA8003C */  sw    $t0, 0x3c($sp)
/* 0E0630 7F0ABB00 AFA9005C */  sw    $t1, 0x5c($sp)
/* 0E0634 7F0ABB04 0FC30776 */  jal   langGet
/* 0E0638 7F0ABB08 AFAA0058 */   sw    $t2, 0x58($sp)
/* 0E063C 7F0ABB0C 8FA9005C */  lw    $t1, 0x5c($sp)
/* 0E0640 7F0ABB10 3C0B0030 */  lui   $t3, (0x003000B0 >> 16) # lui $t3, 0x30
/* 0E0644 7F0ABB14 356B00B0 */  ori   $t3, (0x003000B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0E0648 7F0ABB18 2418FFFF */  li    $t8, -1
/* 0E064C 7F0ABB1C 24190001 */  li    $t9, 1
/* 0E0650 7F0ABB20 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0E0654 7F0ABB24 AFB80018 */  sw    $t8, 0x18($sp)
/* 0E0658 7F0ABB28 AFAB0024 */  sw    $t3, 0x24($sp)
/* 0E065C 7F0ABB2C 8FA50050 */  lw    $a1, 0x50($sp)
/* 0E0660 7F0ABB30 8FA40060 */  lw    $a0, 0x60($sp)
/* 0E0664 7F0ABB34 8FA60064 */  lw    $a2, 0x64($sp)
/* 0E0668 7F0ABB38 00403825 */  move  $a3, $v0
/* 0E066C 7F0ABB3C AFA00014 */  sw    $zero, 0x14($sp)
/* 0E0670 7F0ABB40 AFA00020 */  sw    $zero, 0x20($sp)
/* 0E0674 7F0ABB44 AFA00028 */  sw    $zero, 0x28($sp)
/* 0E0678 7F0ABB48 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0E067C 7F0ABB4C AFA90010 */   sw    $t1, 0x10($sp)
/* 0E0680 7F0ABB50 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0E0684 7F0ABB54 AFA20060 */  sw    $v0, 0x60($sp)
/* 0E0688 7F0ABB58 0FC30776 */  jal   langGet
/* 0E068C 7F0ABB5C 95040004 */   lhu   $a0, 4($t0)
/* 0E0690 7F0ABB60 8FAA0058 */  lw    $t2, 0x58($sp)
/* 0E0694 7F0ABB64 3C0E0030 */  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
/* 0E0698 7F0ABB68 35CE00B0 */  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0E069C 7F0ABB6C 240CFFFF */  li    $t4, -1
/* 0E06A0 7F0ABB70 240D0001 */  li    $t5, 1
/* 0E06A4 7F0ABB74 AFAD001C */  sw    $t5, 0x1c($sp)
/* 0E06A8 7F0ABB78 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0E06AC 7F0ABB7C AFAE0024 */  sw    $t6, 0x24($sp)
/* 0E06B0 7F0ABB80 8FA40060 */  lw    $a0, 0x60($sp)
/* 0E06B4 7F0ABB84 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0E06B8 7F0ABB88 8FA60064 */  lw    $a2, 0x64($sp)
/* 0E06BC 7F0ABB8C 00403825 */  move  $a3, $v0
/* 0E06C0 7F0ABB90 AFA00014 */  sw    $zero, 0x14($sp)
/* 0E06C4 7F0ABB94 AFA00020 */  sw    $zero, 0x20($sp)
/* 0E06C8 7F0ABB98 AFA00028 */  sw    $zero, 0x28($sp)
/* 0E06CC 7F0ABB9C 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0E06D0 7F0ABBA0 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0E06D4 7F0ABBA4 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0E06D8 7F0ABBA8 AFA20060 */  sw    $v0, 0x60($sp)
/* 0E06DC 7F0ABBAC 95030006 */  lhu   $v1, 6($t0)
/* 0E06E0 7F0ABBB0 50600016 */  beql  $v1, $zero, .L7F0ABC0C
/* 0E06E4 7F0ABBB4 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0E06E8 7F0ABBB8 0FC30776 */  jal   langGet
/* 0E06EC 7F0ABBBC 00602025 */   move  $a0, $v1
/* 0E06F0 7F0ABBC0 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0E06F4 7F0ABBC4 3C0B0030 */  lui   $t3, (0x003000B0 >> 16) # lui $t3, 0x30
/* 0E06F8 7F0ABBC8 356B00B0 */  ori   $t3, (0x003000B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0E06FC 7F0ABBCC 2418FFFF */  li    $t8, -1
/* 0E0700 7F0ABBD0 24190001 */  li    $t9, 1
/* 0E0704 7F0ABBD4 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0E0708 7F0ABBD8 AFB80018 */  sw    $t8, 0x18($sp)
/* 0E070C 7F0ABBDC AFAB0024 */  sw    $t3, 0x24($sp)
/* 0E0710 7F0ABBE0 8FA40060 */  lw    $a0, 0x60($sp)
/* 0E0714 7F0ABBE4 2405010E */  li    $a1, 270
/* 0E0718 7F0ABBE8 8FA60064 */  lw    $a2, 0x64($sp)
/* 0E071C 7F0ABBEC 00403825 */  move  $a3, $v0
/* 0E0720 7F0ABBF0 AFA00014 */  sw    $zero, 0x14($sp)
/* 0E0724 7F0ABBF4 AFA00020 */  sw    $zero, 0x20($sp)
/* 0E0728 7F0ABBF8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0E072C 7F0ABBFC 0FC2A4E6 */  jal   sub_GAME_7F0A9398
/* 0E0730 7F0ABC00 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0E0734 7F0ABC04 AFA20060 */  sw    $v0, 0x60($sp)
/* 0E0738 7F0ABC08 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F0ABC0C:
/* 0E073C 7F0ABC0C 8FA20060 */  lw    $v0, 0x60($sp)
/* 0E0740 7F0ABC10 27BD0060 */  addiu $sp, $sp, 0x60
/* 0E0744 7F0ABC14 03E00008 */  jr    $ra
/* 0E0748 7F0ABC18 00000000 */   nop
)
#endif





Gfx *draw_toggle_options(Gfx *gdl)
{
    s32 y_offset;
    s32 i;

    gdl = microcode_constructor(gdl);

    for (i = 0, y_offset = YOFFSET_1; i < 8; i = i + 1, y_offset = y_offset + YINC) {

        if ( i == game_options_index - 2)
        {
            if (watch_item_is_actively_selected)
            {
                gdl = sub_GAME_7F0AB908(sub_GAME_7F0A9398(gdl, XOFFSET_1, y_offset, langGet(game_options_entries[i].text[0]), -1, 1, 0x7000A0, 0, 0, 0x3000B0, 0), y_offset, i, 2);
            }
            else
            {

                gdl = sub_GAME_7F0AB908(sub_GAME_7F0A9398(gdl, XOFFSET_1, y_offset, langGet(game_options_entries[i].text[0]), 0xA0FFA0F0, 0, -1, 0, 0, 0x3000B0, 0), y_offset, i, 1);
            }
        }
        else
        {
            gdl = sub_GAME_7F0AB908(sub_GAME_7F0A9398(gdl, XOFFSET_1, y_offset, langGet(game_options_entries[i].text[0]), 0xFF00B0, 0, -1, 0, 0, 0x3000B0, 0), y_offset, i, 0);
        }

    }

    return gdl;
}


Gfx *draw_watch_game_options_page(Gfx *gdl, Mtx *param_2) {
    s32 sp5C;
    u16 *textptr;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;

    s32 ptr_first_font;
    s32 ptr_second_font;
    
    gdl = draw_background_health_and_armor(gdl, param_2, 0);

    if (check_watch_page_transistion_running() != 1)
    {
        gdl = sub_GAME_7F0A91C8(gdl);
        gdl = sub_GAME_7F0A8FEC(gdl);
        ptr_first_font = ptrFirstFontTableSmall;
        ptr_second_font = ptrSecondFontTableSmall;
        gdl = microcode_constructor(gdl);

        textptr = langGet(TEXT(LOPTIONS, 0x35)); //music

        sp54 = XOFFSET_1;
        sp50 = YOFFSET_8;
        
        sp5C = 0xFF00B0;

        if (game_options_index == 0)
        {
            sp5C = 0xA0FFA0F0;
            if (watch_item_is_actively_selected != 0)
            {
                sp5C = -1;
            }
        }

        sub_GAME_7F0AE98C(&sp48, &sp4C, textptr, ptr_second_font, ptr_first_font, 0);

        if ((watch_item_is_actively_selected != 0) && (game_options_index == 0))
        {
            gdl = jp_text_write_stuff(gdl, &sp54, &sp50, textptr, ptr_second_font, ptr_first_font, sp5C, 0x7000A0, sp4C + 1, sp48, 0, 0);
        }
        else
        {
            gdl = en_text_write_stuff(gdl, &sp54, &sp50, textptr, ptr_second_font, ptr_first_font, sp5C, sp4C, sp48, 0, 0);
        }

        sp5C = 0xFF00B0;
        textptr = langGet(TEXT(LOPTIONS, 0x36)); //fx

        sp54 = XOFFSET_1;
        sp50 = YOFFSET_9;


        if (game_options_index == 1)
        {
            sp5C = 0xA0FFA0F0;
            if (watch_item_is_actively_selected != 0)
            {
                sp5C = -1;
            }
        }

        sub_GAME_7F0AE98C(&sp48, &sp4C, textptr, ptr_second_font, ptr_first_font, 0);

        if ((watch_item_is_actively_selected != 0) && (game_options_index == 1))
        {
            gdl = jp_text_write_stuff(gdl, &sp54, &sp50, textptr, ptr_second_font, ptr_first_font, sp5C, 0x7000A0, sp4C + 1, sp48, 0, 0);
        }
        else
        {
            gdl = en_text_write_stuff(gdl, &sp54, &sp50, textptr, ptr_second_font, ptr_first_font, sp5C, sp4C, sp48, 0, 0);
        }

        gdl = draw_toggle_options(gdl);
    }

    return gdl;
}


int sub_GAME_7F0AC0E8(u8 *arg) {
    u8 cVar1;
    int count;

    cVar1 = *arg;
    count = 0;

    while (cVar1) {

        if (cVar1 == 0xA) {
            count = count + 1;
        }

        cVar1 = arg[1];
        arg += 1;
    }

    return count;
}


#ifndef VERSION_EU
u8 *sub_GAME_7F0AC120(u8 *arg)
{
    u8 cVar1;
    u8 *pcVar2;

    cVar1 = *arg;
    pcVar2 = arg;

    while (cVar1) {

        if (cVar1 == 0xA) {
            arg += 1;

            if (arg[0]) {
                pcVar2 = arg;
            }
        }

        cVar1 = arg[1];
        arg += 1;
    }

    return pcVar2;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AC120
/* 0DDE38 7F0AB448 90820000 */  lbu   $v0, ($a0)
/* 0DDE3C 7F0AB44C 00801825 */  move  $v1, $a0
/* 0DDE40 7F0AB450 2405000A */  li    $a1, 10
/* 0DDE44 7F0AB454 1040000D */  beqz  $v0, .L7F0AB48C
/* 0DDE48 7F0AB458 00000000 */   nop   
.L7F0AB45C:
/* 0DDE4C 7F0AB45C 54A20008 */  bnel  $a1, $v0, .L7F0AB480
/* 0DDE50 7F0AB460 24840001 */   addiu $a0, $a0, 1
/* 0DDE54 7F0AB464 90820001 */  lbu   $v0, 1($a0)
/* 0DDE58 7F0AB468 24840001 */  addiu $a0, $a0, 1
/* 0DDE5C 7F0AB46C 10400005 */  beqz  $v0, .L7F0AB484
/* 0DDE60 7F0AB470 00000000 */   nop   
/* 0DDE64 7F0AB474 10000003 */  b     .L7F0AB484
/* 0DDE68 7F0AB478 00801825 */   move  $v1, $a0
/* 0DDE6C 7F0AB47C 24840001 */  addiu $a0, $a0, 1
.L7F0AB480:
/* 0DDE70 7F0AB480 90820000 */  lbu   $v0, ($a0)
.L7F0AB484:
/* 0DDE74 7F0AB484 1440FFF5 */  bnez  $v0, .L7F0AB45C
/* 0DDE78 7F0AB488 00000000 */   nop   
.L7F0AB48C:
/* 0DDE7C 7F0AB48C 03E00008 */  jr    $ra
/* 0DDE80 7F0AB490 00601025 */   move  $v0, $v1
)
#endif


#ifdef NONMATCHING
void draw_watch_mission_briefing_page(void) {

}
#else
//D:800577C0
const char D_800577C0[] =  "\n";
//these 2 blocks are wrong splits most likely, investigate and cleanup
#if defined(LEFTOVERDEBUG)
//D:800577C4
const u32 D_800577C4[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};
//D:80057FC0
const u32 D_80057FC0[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
#endif
//D:80058440
const char D_80058440[] = " \n";
//D:80058444
const char D_80058444[] = " \n\n";
//D:80058448
const char aC_2[] = "%c: ";
//D:80058450
const char D_80058450[] = " \n";
//D:80058454
const char D_80058454[] = " \n\n";

#if defined(LEFTOVERDEBUG)

GLOBAL_ASM(
.late_rodata
/*D:80058570*/
glabel jpt_80058570
.word .L7F0AC3B8
.word .L7F0AC400
.word .L7F0AC448
.word .L7F0AC490
.word .L7F0AC4D8

.text
glabel draw_watch_mission_briefing_page
/* 0E0C98 7F0AC168 27BDF218 */  addiu $sp, $sp, -0xde8
/* 0E0C9C 7F0AC16C AFBF005C */  sw    $ra, 0x5c($sp)
/* 0E0CA0 7F0AC170 AFBE0058 */  sw    $fp, 0x58($sp)
/* 0E0CA4 7F0AC174 AFB70054 */  sw    $s7, 0x54($sp)
/* 0E0CA8 7F0AC178 AFB60050 */  sw    $s6, 0x50($sp)
/* 0E0CAC 7F0AC17C AFB5004C */  sw    $s5, 0x4c($sp)
/* 0E0CB0 7F0AC180 AFB40048 */  sw    $s4, 0x48($sp)
/* 0E0CB4 7F0AC184 AFB30044 */  sw    $s3, 0x44($sp)
/* 0E0CB8 7F0AC188 AFB20040 */  sw    $s2, 0x40($sp)
/* 0E0CBC 7F0AC18C AFB1003C */  sw    $s1, 0x3c($sp)
/* 0E0CC0 7F0AC190 AFB00038 */  sw    $s0, 0x38($sp)
/* 0E0CC4 7F0AC194 0FC29C53 */  jal   draw_background_health_and_armor
/* 0E0CC8 7F0AC198 00003025 */   move  $a2, $zero
/* 0E0CCC 7F0AC19C 0FC1F97F */  jal   check_watch_page_transistion_running
/* 0E0CD0 7F0AC1A0 AFA20DE8 */   sw    $v0, 0xde8($sp)
/* 0E0CD4 7F0AC1A4 24010001 */  li    $at, 1
/* 0E0CD8 7F0AC1A8 10410212 */  beq   $v0, $at, .L7F0AC9F4
/* 0E0CDC 7F0AC1AC 27AE0DAC */   addiu $t6, $sp, 0xdac
/* 0E0CE0 7F0AC1B0 3C0F8004 */  lui   $t7, %hi(D_80040DFC)
/* 0E0CE4 7F0AC1B4 25EF0DFC */  addiu $t7, %lo(D_80040DFC) # addiu $t7, $t7, 0xdfc
/* 0E0CE8 7F0AC1B8 25F9003C */  addiu $t9, $t7, 0x3c
.L7F0AC1BC:
/* 0E0CEC 7F0AC1BC 8DE10000 */  lw    $at, ($t7)
/* 0E0CF0 7F0AC1C0 25EF000C */  addiu $t7, $t7, 0xc
/* 0E0CF4 7F0AC1C4 25CE000C */  addiu $t6, $t6, 0xc
/* 0E0CF8 7F0AC1C8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0E0CFC 7F0AC1CC 8DE1FFF8 */  lw    $at, -8($t7)
/* 0E0D00 7F0AC1D0 ADC1FFF8 */  sw    $at, -8($t6)
/* 0E0D04 7F0AC1D4 8DE1FFFC */  lw    $at, -4($t7)
/* 0E0D08 7F0AC1D8 15F9FFF8 */  bne   $t7, $t9, .L7F0AC1BC
/* 0E0D0C 7F0AC1DC ADC1FFFC */   sw    $at, -4($t6)
/* 0E0D10 7F0AC1E0 3C098004 */  lui   $t1, %hi(D_80040E38)
/* 0E0D14 7F0AC1E4 25290E38 */  addiu $t1, %lo(D_80040E38) # addiu $t1, $t1, 0xe38
/* 0E0D18 7F0AC1E8 8D210000 */  lw    $at, ($t1)
/* 0E0D1C 7F0AC1EC 8D2B0004 */  lw    $t3, 4($t1)
/* 0E0D20 7F0AC1F0 27A80DA4 */  addiu $t0, $sp, 0xda4
/* 0E0D24 7F0AC1F4 3C0D8004 */  lui   $t5, %hi(D_80040E40)
/* 0E0D28 7F0AC1F8 25AD0E40 */  addiu $t5, %lo(D_80040E40) # addiu $t5, $t5, 0xe40
/* 0E0D2C 7F0AC1FC 25B9003C */  addiu $t9, $t5, 0x3c
/* 0E0D30 7F0AC200 27AC0D68 */  addiu $t4, $sp, 0xd68
/* 0E0D34 7F0AC204 AD010000 */  sw    $at, ($t0)
/* 0E0D38 7F0AC208 AD0B0004 */  sw    $t3, 4($t0)
.L7F0AC20C:
/* 0E0D3C 7F0AC20C 8DA10000 */  lw    $at, ($t5)
/* 0E0D40 7F0AC210 25AD000C */  addiu $t5, $t5, 0xc
/* 0E0D44 7F0AC214 258C000C */  addiu $t4, $t4, 0xc
/* 0E0D48 7F0AC218 AD81FFF4 */  sw    $at, -0xc($t4)
/* 0E0D4C 7F0AC21C 8DA1FFF8 */  lw    $at, -8($t5)
/* 0E0D50 7F0AC220 AD81FFF8 */  sw    $at, -8($t4)
/* 0E0D54 7F0AC224 8DA1FFFC */  lw    $at, -4($t5)
/* 0E0D58 7F0AC228 15B9FFF8 */  bne   $t5, $t9, .L7F0AC20C
/* 0E0D5C 7F0AC22C AD81FFFC */   sw    $at, -4($t4)
/* 0E0D60 7F0AC230 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall)
/* 0E0D64 7F0AC234 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall)
/* 0E0D68 7F0AC238 8DEF0EAC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0E0D6C 7F0AC23C 8DCE0EB0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0E0D70 7F0AC240 3C088005 */  lui   $t0, %hi(D_800577C0)
/* 0E0D74 7F0AC244 250877C0 */  addiu $t0, %lo(D_800577C0) # addiu $t0, $t0, 0x77c0
/* 0E0D78 7F0AC248 AFA00D54 */  sw    $zero, 0xd54($sp)
/* 0E0D7C 7F0AC24C AFA00D50 */  sw    $zero, 0xd50($sp)
/* 0E0D80 7F0AC250 25180BB8 */  addiu $t8, $t0, 0xbb8
/* 0E0D84 7F0AC254 27AA0190 */  addiu $t2, $sp, 0x190
/* 0E0D88 7F0AC258 AFAF0D4C */  sw    $t7, 0xd4c($sp)
/* 0E0D8C 7F0AC25C AFAE0D48 */  sw    $t6, 0xd48($sp)
.L7F0AC260:
/* 0E0D90 7F0AC260 8D010000 */  lw    $at, ($t0)
/* 0E0D94 7F0AC264 2508000C */  addiu $t0, $t0, 0xc
/* 0E0D98 7F0AC268 254A000C */  addiu $t2, $t2, 0xc
/* 0E0D9C 7F0AC26C AD41FFF4 */  sw    $at, -0xc($t2)
/* 0E0DA0 7F0AC270 8D01FFF8 */  lw    $at, -8($t0)
/* 0E0DA4 7F0AC274 AD41FFF8 */  sw    $at, -8($t2)
/* 0E0DA8 7F0AC278 8D01FFFC */  lw    $at, -4($t0)
/* 0E0DAC 7F0AC27C 1518FFF8 */  bne   $t0, $t8, .L7F0AC260
/* 0E0DB0 7F0AC280 AD41FFFC */   sw    $at, -4($t2)
/* 0E0DB4 7F0AC284 0FC30776 */  jal   langGet
/* 0E0DB8 7F0AC288 3404AC28 */   li    $a0, 44072
/* 0E0DBC 7F0AC28C AFA2016C */  sw    $v0, 0x16c($sp)
/* 0E0DC0 7F0AC290 0FC30776 */  jal   langGet
/* 0E0DC4 7F0AC294 3404AC29 */   li    $a0, 44073
/* 0E0DC8 7F0AC298 AFA20168 */  sw    $v0, 0x168($sp)
/* 0E0DCC 7F0AC29C 0FC30776 */  jal   langGet
/* 0E0DD0 7F0AC2A0 3404AC37 */   li    $a0, 44087
/* 0E0DD4 7F0AC2A4 AFA20164 */  sw    $v0, 0x164($sp)
/* 0E0DD8 7F0AC2A8 0FC15C41 */  jal   get_ptr_text_for_watch_breifing_page
/* 0E0DDC 7F0AC2AC 00002025 */   move  $a0, $zero
/* 0E0DE0 7F0AC2B0 00408025 */  move  $s0, $v0
/* 0E0DE4 7F0AC2B4 0FC2B366 */  jal   microcode_constructor
/* 0E0DE8 7F0AC2B8 8FA40DE8 */   lw    $a0, 0xde8($sp)
/* 0E0DEC 7F0AC2BC 8FB90D4C */  lw    $t9, 0xd4c($sp)
/* 0E0DF0 7F0AC2C0 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0E0DF4 7F0AC2C4 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0E0DF8 7F0AC2C8 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0E0DFC 7F0AC2CC 02003025 */  move  $a2, $s0
/* 0E0E00 7F0AC2D0 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E0E04 7F0AC2D4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0E0E08 7F0AC2D8 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E0E0C 7F0AC2DC AFB90010 */   sw    $t9, 0x10($sp)
/* 0E0E10 7F0AC2E0 8FA20D50 */  lw    $v0, 0xd50($sp)
/* 0E0E14 7F0AC2E4 240D00AA */  li    $t5, 170
/* 0E0E18 7F0AC2E8 8FAB0D54 */  lw    $t3, 0xd54($sp)
/* 0E0E1C 7F0AC2EC 01A21823 */  subu  $v1, $t5, $v0
/* 0E0E20 7F0AC2F0 04610003 */  bgez  $v1, .L7F0AC300
/* 0E0E24 7F0AC2F4 00036043 */   sra   $t4, $v1, 1
/* 0E0E28 7F0AC2F8 24610001 */  addiu $at, $v1, 1
/* 0E0E2C 7F0AC2FC 00016043 */  sra   $t4, $at, 1
.L7F0AC300:
/* 0E0E30 7F0AC300 2583004B */  addiu $v1, $t4, 0x4b
/* 0E0E34 7F0AC304 240F001E */  li    $t7, 30
/* 0E0E38 7F0AC308 27B80D58 */  addiu $t8, $sp, 0xd58
/* 0E0E3C 7F0AC30C 00627021 */  addu  $t6, $v1, $v0
/* 0E0E40 7F0AC310 2569001E */  addiu $t1, $t3, 0x1e
/* 0E0E44 7F0AC314 AFAF0D60 */  sw    $t7, 0xd60($sp)
/* 0E0E48 7F0AC318 AFAE0D5C */  sw    $t6, 0xd5c($sp)
/* 0E0E4C 7F0AC31C AFA90D58 */  sw    $t1, 0xd58($sp)
/* 0E0E50 7F0AC320 AFB80010 */  sw    $t8, 0x10($sp)
/* 0E0E54 7F0AC324 AFA30D64 */  sw    $v1, 0xd64($sp)
/* 0E0E58 7F0AC328 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0E0E5C 7F0AC32C 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0E0E60 7F0AC330 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0E0E64 7F0AC334 0FC2B3D3 */  jal   draw_blackbox_to_screen
/* 0E0E68 7F0AC338 27A70D5C */   addiu $a3, $sp, 0xd5c
/* 0E0E6C 7F0AC33C 8FA80D48 */  lw    $t0, 0xd48($sp)
/* 0E0E70 7F0AC340 8FAA0D4C */  lw    $t2, 0xd4c($sp)
/* 0E0E74 7F0AC344 8FAD0D50 */  lw    $t5, 0xd50($sp)
/* 0E0E78 7F0AC348 8FAC0D54 */  lw    $t4, 0xd54($sp)
/* 0E0E7C 7F0AC34C 3C19A0FF */  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
/* 0E0E80 7F0AC350 3739A0F0 */  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
/* 0E0E84 7F0AC354 AFB90018 */  sw    $t9, 0x18($sp)
/* 0E0E88 7F0AC358 00402025 */  move  $a0, $v0
/* 0E0E8C 7F0AC35C 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0E0E90 7F0AC360 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0E0E94 7F0AC364 02003825 */  move  $a3, $s0
/* 0E0E98 7F0AC368 AFA00024 */  sw    $zero, 0x24($sp)
/* 0E0E9C 7F0AC36C AFA00028 */  sw    $zero, 0x28($sp)
/* 0E0EA0 7F0AC370 AFA80010 */  sw    $t0, 0x10($sp)
/* 0E0EA4 7F0AC374 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0E0EA8 7F0AC378 AFAD001C */  sw    $t5, 0x1c($sp)
/* 0E0EAC 7F0AC37C 0FC2B6AF */  jal   en_text_write_stuff
/* 0E0EB0 7F0AC380 AFAC0020 */   sw    $t4, 0x20($sp)
/* 0E0EB4 7F0AC384 3C0F8004 */  lui   $t7, %hi(mission_brief_index)
/* 0E0EB8 7F0AC388 8DEF09A0 */  lw    $t7, %lo(mission_brief_index)($t7)
/* 0E0EBC 7F0AC38C 24030041 */  li    $v1, 65
/* 0E0EC0 7F0AC390 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0E0EC4 7F0AC394 2DE10005 */  sltiu $at, $t7, 5
/* 0E0EC8 7F0AC398 10200154 */  beqz  $at, .L7F0AC8EC
/* 0E0ECC 7F0AC39C AFA30D64 */   sw    $v1, 0xd64($sp)
/* 0E0ED0 7F0AC3A0 000F7880 */  sll   $t7, $t7, 2
/* 0E0ED4 7F0AC3A4 3C018006 */  lui   $at, %hi(jpt_80058570)
/* 0E0ED8 7F0AC3A8 002F0821 */  addu  $at, $at, $t7
/* 0E0EDC 7F0AC3AC 8C2F8570 */  lw    $t7, %lo(jpt_80058570)($at)
/* 0E0EE0 7F0AC3B0 01E00008 */  jr    $t7
/* 0E0EE4 7F0AC3B4 00000000 */   nop
.L7F0AC3B8:
/* 0E0EE8 7F0AC3B8 0FC30776 */  jal   langGet
/* 0E0EEC 7F0AC3BC 3404AC38 */   li    $a0, 44088
/* 0E0EF0 7F0AC3C0 27A40170 */  addiu $a0, $sp, 0x170
/* 0E0EF4 7F0AC3C4 0C002B25 */  jal   sprintf
/* 0E0EF8 7F0AC3C8 00402825 */   move  $a1, $v0
/* 0E0EFC 7F0AC3CC 0FC15C41 */  jal   get_ptr_text_for_watch_breifing_page
/* 0E0F00 7F0AC3D0 24040001 */   li    $a0, 1
/* 0E0F04 7F0AC3D4 8FAE0D4C */  lw    $t6, 0xd4c($sp)
/* 0E0F08 7F0AC3D8 240400D2 */  li    $a0, 210
/* 0E0F0C 7F0AC3DC 00402825 */  move  $a1, $v0
/* 0E0F10 7F0AC3E0 27A60190 */  addiu $a2, $sp, 0x190
/* 0E0F14 7F0AC3E4 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E0F18 7F0AC3E8 0FC2BAD9 */  jal   sub_GAME_7F0AEB64
/* 0E0F1C 7F0AC3EC AFAE0010 */   sw    $t6, 0x10($sp)
/* 0E0F20 7F0AC3F0 0FC29986 */  jal   mission_brief_background_navigation
/* 0E0F24 7F0AC3F4 00000000 */   nop
/* 0E0F28 7F0AC3F8 1000013D */  b     .L7F0AC8F0
/* 0E0F2C 7F0AC3FC 8FAA0D4C */   lw    $t2, 0xd4c($sp)
.L7F0AC400:
/* 0E0F30 7F0AC400 0FC30776 */  jal   langGet
/* 0E0F34 7F0AC404 3404AC39 */   li    $a0, 44089
/* 0E0F38 7F0AC408 27A40170 */  addiu $a0, $sp, 0x170
/* 0E0F3C 7F0AC40C 0C002B25 */  jal   sprintf
/* 0E0F40 7F0AC410 00402825 */   move  $a1, $v0
/* 0E0F44 7F0AC414 0FC15C41 */  jal   get_ptr_text_for_watch_breifing_page
/* 0E0F48 7F0AC418 24040002 */   li    $a0, 2
/* 0E0F4C 7F0AC41C 8FAB0D4C */  lw    $t3, 0xd4c($sp)
/* 0E0F50 7F0AC420 240400D2 */  li    $a0, 210
/* 0E0F54 7F0AC424 00402825 */  move  $a1, $v0
/* 0E0F58 7F0AC428 27A60190 */  addiu $a2, $sp, 0x190
/* 0E0F5C 7F0AC42C 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E0F60 7F0AC430 0FC2BAD9 */  jal   sub_GAME_7F0AEB64
/* 0E0F64 7F0AC434 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0E0F68 7F0AC438 0FC299A8 */  jal   mission_brief_m_briefing_navigation
/* 0E0F6C 7F0AC43C 00000000 */   nop
/* 0E0F70 7F0AC440 1000012B */  b     .L7F0AC8F0
/* 0E0F74 7F0AC444 8FAA0D4C */   lw    $t2, 0xd4c($sp)
.L7F0AC448:
/* 0E0F78 7F0AC448 0FC30776 */  jal   langGet
/* 0E0F7C 7F0AC44C 3404AC3A */   li    $a0, 44090
/* 0E0F80 7F0AC450 27A40170 */  addiu $a0, $sp, 0x170
/* 0E0F84 7F0AC454 0C002B25 */  jal   sprintf
/* 0E0F88 7F0AC458 00402825 */   move  $a1, $v0
/* 0E0F8C 7F0AC45C 0FC15C41 */  jal   get_ptr_text_for_watch_breifing_page
/* 0E0F90 7F0AC460 24040003 */   li    $a0, 3
/* 0E0F94 7F0AC464 8FA90D4C */  lw    $t1, 0xd4c($sp)
/* 0E0F98 7F0AC468 240400D2 */  li    $a0, 210
/* 0E0F9C 7F0AC46C 00402825 */  move  $a1, $v0
/* 0E0FA0 7F0AC470 27A60190 */  addiu $a2, $sp, 0x190
/* 0E0FA4 7F0AC474 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E0FA8 7F0AC478 0FC2BAD9 */  jal   sub_GAME_7F0AEB64
/* 0E0FAC 7F0AC47C AFA90010 */   sw    $t1, 0x10($sp)
/* 0E0FB0 7F0AC480 0FC299CB */  jal   mission_brief_q_branch_navigation
/* 0E0FB4 7F0AC484 00000000 */   nop
/* 0E0FB8 7F0AC488 10000119 */  b     .L7F0AC8F0
/* 0E0FBC 7F0AC48C 8FAA0D4C */   lw    $t2, 0xd4c($sp)
.L7F0AC490:
/* 0E0FC0 7F0AC490 0FC30776 */  jal   langGet
/* 0E0FC4 7F0AC494 3404AC3B */   li    $a0, 44091
/* 0E0FC8 7F0AC498 27A40170 */  addiu $a0, $sp, 0x170
/* 0E0FCC 7F0AC49C 0C002B25 */  jal   sprintf
/* 0E0FD0 7F0AC4A0 00402825 */   move  $a1, $v0
/* 0E0FD4 7F0AC4A4 0FC15C41 */  jal   get_ptr_text_for_watch_breifing_page
/* 0E0FD8 7F0AC4A8 24040004 */   li    $a0, 4
/* 0E0FDC 7F0AC4AC 8FB80D4C */  lw    $t8, 0xd4c($sp)
/* 0E0FE0 7F0AC4B0 240400D2 */  li    $a0, 210
/* 0E0FE4 7F0AC4B4 00402825 */  move  $a1, $v0
/* 0E0FE8 7F0AC4B8 27A60190 */  addiu $a2, $sp, 0x190
/* 0E0FEC 7F0AC4BC 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E0FF0 7F0AC4C0 0FC2BAD9 */  jal   sub_GAME_7F0AEB64
/* 0E0FF4 7F0AC4C4 AFB80010 */   sw    $t8, 0x10($sp)
/* 0E0FF8 7F0AC4C8 0FC299EF */  jal   mission_brief_moneypenny_navigation
/* 0E0FFC 7F0AC4CC 00000000 */   nop
/* 0E1000 7F0AC4D0 10000107 */  b     .L7F0AC8F0
/* 0E1004 7F0AC4D4 8FAA0D4C */   lw    $t2, 0xd4c($sp)
.L7F0AC4D8:
/* 0E1008 7F0AC4D8 3C088006 */  lui   $t0, %hi(D_80057FC0+0x3B8)
/* 0E100C 7F0AC4DC 27B10088 */  addiu $s1, $sp, 0x88
/* 0E1010 7F0AC4E0 25088378 */  addiu $t0, %lo(D_80057FC0+0x3B8) # addiu $t0, $t0, -0x7c88
/* 0E1014 7F0AC4E4 250D00C0 */  addiu $t5, $t0, 0xc0
/* 0E1018 7F0AC4E8 02206025 */  move  $t4, $s1
.L7F0AC4EC:
/* 0E101C 7F0AC4EC 8D010000 */  lw    $at, ($t0)
/* 0E1020 7F0AC4F0 2508000C */  addiu $t0, $t0, 0xc
/* 0E1024 7F0AC4F4 258C000C */  addiu $t4, $t4, 0xc
/* 0E1028 7F0AC4F8 AD81FFF4 */  sw    $at, -0xc($t4)
/* 0E102C 7F0AC4FC 8D01FFF8 */  lw    $at, -8($t0)
/* 0E1030 7F0AC500 AD81FFF8 */  sw    $at, -8($t4)
/* 0E1034 7F0AC504 8D01FFFC */  lw    $at, -4($t0)
/* 0E1038 7F0AC508 150DFFF8 */  bne   $t0, $t5, .L7F0AC4EC
/* 0E103C 7F0AC50C AD81FFFC */   sw    $at, -4($t4)
/* 0E1040 7F0AC510 8D010000 */  lw    $at, ($t0)
/* 0E1044 7F0AC514 3C0F8005 */  lui   $t7, %hi(j_text_trigger)
/* 0E1048 7F0AC518 24120001 */  li    $s2, 1
/* 0E104C 7F0AC51C AD810000 */  sw    $at, ($t4)
/* 0E1050 7F0AC520 8D0D0004 */  lw    $t5, 4($t0)
/* 0E1054 7F0AC524 00009825 */  move  $s3, $zero
/* 0E1058 7F0AC528 24040005 */  li    $a0, 5
/* 0E105C 7F0AC52C AD8D0004 */  sw    $t5, 4($t4)
/* 0E1060 7F0AC530 8DEF84D0 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0E1064 7F0AC534 AFA00074 */  sw    $zero, 0x74($sp)
/* 0E1068 7F0AC538 11E00003 */  beqz  $t7, .L7F0AC548
/* 0E106C 7F0AC53C 00000000 */   nop
/* 0E1070 7F0AC540 10000001 */  b     .L7F0AC548
/* 0E1074 7F0AC544 24040001 */   li    $a0, 1
.L7F0AC548:
/* 0E1078 7F0AC548 0FC2B2E8 */  jal   setTextOverlapCorrection
/* 0E107C 7F0AC54C 00000000 */   nop
/* 0E1080 7F0AC550 0FC30776 */  jal   langGet
/* 0E1084 7F0AC554 3404AC3C */   li    $a0, 44092
/* 0E1088 7F0AC558 27A40170 */  addiu $a0, $sp, 0x170
/* 0E108C 7F0AC55C 0C002B25 */  jal   sprintf
/* 0E1090 7F0AC560 00402825 */   move  $a1, $v0
/* 0E1094 7F0AC564 0FC15C6A */  jal   objectiveGetCount
/* 0E1098 7F0AC568 0000F025 */   move  $fp, $zero
/* 0E109C 7F0AC56C 184000DB */  blez  $v0, .L7F0AC8DC
/* 0E10A0 7F0AC570 3C178006 */   lui   $s7, %hi(D_80058454)
/* 0E10A4 7F0AC574 3C168006 */  lui   $s6, %hi(D_80058450)
/* 0E10A8 7F0AC578 3C158006 */  lui   $s5, %hi(D_80058444)
/* 0E10AC 7F0AC57C 3C148006 */  lui   $s4, %hi(D_80058440)
/* 0E10B0 7F0AC580 26948440 */  addiu $s4, %lo(D_80058440) # addiu $s4, $s4, -0x7bc0
/* 0E10B4 7F0AC584 26B58444 */  addiu $s5, %lo(D_80058444) # addiu $s5, $s5, -0x7bbc
/* 0E10B8 7F0AC588 26D68450 */  addiu $s6, %lo(D_80058450) # addiu $s6, $s6, -0x7bb0
/* 0E10BC 7F0AC58C 26F78454 */  addiu $s7, %lo(D_80058454) # addiu $s7, $s7, -0x7bac
.L7F0AC590:
/* 0E10C0 7F0AC590 0FC15C81 */  jal   get_difficulty_for_objective
/* 0E10C4 7F0AC594 03C02025 */   move  $a0, $fp
/* 0E10C8 7F0AC598 0FC2FF04 */  jal   lvlGetSelectedDifficulty
/* 0E10CC 7F0AC59C AFA20068 */   sw    $v0, 0x68($sp)
/* 0E10D0 7F0AC5A0 8FA40068 */  lw    $a0, 0x68($sp)
/* 0E10D4 7F0AC5A4 0044082A */  slt   $at, $v0, $a0
/* 0E10D8 7F0AC5A8 142000C7 */  bnez  $at, .L7F0AC8C8
/* 0E10DC 7F0AC5AC 03C02025 */   move  $a0, $fp
/* 0E10E0 7F0AC5B0 0FC15C6E */  jal   get_text_for_objective
/* 0E10E4 7F0AC5B4 00008025 */   move  $s0, $zero
/* 0E10E8 7F0AC5B8 AFA20078 */  sw    $v0, 0x78($sp)
/* 0E10EC 7F0AC5BC 1A400008 */  blez  $s2, .L7F0AC5E0
/* 0E10F0 7F0AC5C0 A3A00088 */   sb    $zero, 0x88($sp)
/* 0E10F4 7F0AC5C4 02202025 */  move  $a0, $s1
.L7F0AC5C8:
/* 0E10F8 7F0AC5C8 0C0029FF */  jal   strcat
/* 0E10FC 7F0AC5CC 02802825 */   move  $a1, $s4
/* 0E1100 7F0AC5D0 26100001 */  addiu $s0, $s0, 1
/* 0E1104 7F0AC5D4 5612FFFC */  bnel  $s0, $s2, .L7F0AC5C8
/* 0E1108 7F0AC5D8 02202025 */   move  $a0, $s1
/* 0E110C 7F0AC5DC 00008025 */  move  $s0, $zero
.L7F0AC5E0:
/* 0E1110 7F0AC5E0 1A600007 */  blez  $s3, .L7F0AC600
/* 0E1114 7F0AC5E4 02202025 */   move  $a0, $s1
.L7F0AC5E8:
/* 0E1118 7F0AC5E8 0C0029FF */  jal   strcat
/* 0E111C 7F0AC5EC 02A02825 */   move  $a1, $s5
/* 0E1120 7F0AC5F0 26100001 */  addiu $s0, $s0, 1
/* 0E1124 7F0AC5F4 5613FFFC */  bnel  $s0, $s3, .L7F0AC5E8
/* 0E1128 7F0AC5F8 02202025 */   move  $a0, $s1
/* 0E112C 7F0AC5FC 00008025 */  move  $s0, $zero
.L7F0AC600:
/* 0E1130 7F0AC600 0C004E1F */  jal   strlen
/* 0E1134 7F0AC604 02202025 */   move  $a0, $s1
/* 0E1138 7F0AC608 8FA60074 */  lw    $a2, 0x74($sp)
/* 0E113C 7F0AC60C 00512021 */  addu  $a0, $v0, $s1
/* 0E1140 7F0AC610 3C058006 */  lui   $a1, %hi(aC_2)
/* 0E1144 7F0AC614 AFA4006C */  sw    $a0, 0x6c($sp)
/* 0E1148 7F0AC618 24A58448 */  addiu $a1, %lo(aC_2) # addiu $a1, $a1, -0x7bb8
/* 0E114C 7F0AC61C 0C002B25 */  jal   sprintf
/* 0E1150 7F0AC620 24C60061 */   addiu $a2, $a2, 0x61
/* 0E1154 7F0AC624 02202025 */  move  $a0, $s1
/* 0E1158 7F0AC628 0C0029FF */  jal   strcat
/* 0E115C 7F0AC62C 8FA50078 */   lw    $a1, 0x78($sp)
/* 0E1160 7F0AC630 3C0E8005 */  lui   $t6, %hi(j_text_trigger)
/* 0E1164 7F0AC634 8DCE84D0 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0E1168 7F0AC638 8FAB0D60 */  lw    $t3, 0xd60($sp)
/* 0E116C 7F0AC63C 24040005 */  li    $a0, 5
/* 0E1170 7F0AC640 11C00003 */  beqz  $t6, .L7F0AC650
/* 0E1174 7F0AC644 2418003C */   li    $t8, 60
/* 0E1178 7F0AC648 10000001 */  b     .L7F0AC650
/* 0E117C 7F0AC64C 24040001 */   li    $a0, 1
.L7F0AC650:
/* 0E1180 7F0AC650 008B4821 */  addu  $t1, $a0, $t3
/* 0E1184 7F0AC654 AFA90154 */  sw    $t1, 0x154($sp)
/* 0E1188 7F0AC658 0C001107 */  jal   viGetX
/* 0E118C 7F0AC65C AFB80150 */   sw    $t8, 0x150($sp)
/* 0E1190 7F0AC660 0C00110B */  jal   viGetY
/* 0E1194 7F0AC664 A7A20064 */   sh    $v0, 0x64($sp)
/* 0E1198 7F0AC668 8FB90D48 */  lw    $t9, 0xd48($sp)
/* 0E119C 7F0AC66C 8FAA0D4C */  lw    $t2, 0xd4c($sp)
/* 0E11A0 7F0AC670 87A80064 */  lh    $t0, 0x64($sp)
/* 0E11A4 7F0AC674 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0E11A8 7F0AC678 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0E11AC 7F0AC67C 240C000A */  li    $t4, 10
/* 0E11B0 7F0AC680 AFAC0028 */  sw    $t4, 0x28($sp)
/* 0E11B4 7F0AC684 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0E11B8 7F0AC688 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0E11BC 7F0AC68C 27A50150 */  addiu $a1, $sp, 0x150
/* 0E11C0 7F0AC690 27A60154 */  addiu $a2, $sp, 0x154
/* 0E11C4 7F0AC694 02203825 */  move  $a3, $s1
/* 0E11C8 7F0AC698 AFA20020 */  sw    $v0, 0x20($sp)
/* 0E11CC 7F0AC69C AFA00024 */  sw    $zero, 0x24($sp)
/* 0E11D0 7F0AC6A0 AFB90010 */  sw    $t9, 0x10($sp)
/* 0E11D4 7F0AC6A4 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0E11D8 7F0AC6A8 0FC2B6AF */  jal   en_text_write_stuff
/* 0E11DC 7F0AC6AC AFA8001C */   sw    $t0, 0x1c($sp)
/* 0E11E0 7F0AC6B0 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0E11E4 7F0AC6B4 0FC2B03A */  jal   sub_GAME_7F0AC0E8
/* 0E11E8 7F0AC6B8 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0E11EC 7F0AC6BC 02429021 */  addu  $s2, $s2, $v0
/* 0E11F0 7F0AC6C0 0FC2B048 */  jal   sub_GAME_7F0AC120
/* 0E11F4 7F0AC6C4 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0E11F8 7F0AC6C8 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0E11FC 7F0AC6CC 240E000A */  li    $t6, 10
/* 0E1200 7F0AC6D0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0E1204 7F0AC6D4 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0E1208 7F0AC6D8 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0E120C 7F0AC6DC 00403025 */  move  $a2, $v0
/* 0E1210 7F0AC6E0 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E1214 7F0AC6E4 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E1218 7F0AC6E8 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0E121C 7F0AC6EC 0C001107 */  jal   viGetX
/* 0E1220 7F0AC6F0 00000000 */   nop
/* 0E1224 7F0AC6F4 8FA90D50 */  lw    $t1, 0xd50($sp)
/* 0E1228 7F0AC6F8 04410003 */  bgez  $v0, .L7F0AC708
/* 0E122C 7F0AC6FC 00025843 */   sra   $t3, $v0, 1
/* 0E1230 7F0AC700 24410001 */  addiu $at, $v0, 1
/* 0E1234 7F0AC704 00015843 */  sra   $t3, $at, 1
.L7F0AC708:
/* 0E1238 7F0AC708 2538003C */  addiu $t8, $t1, 0x3c
/* 0E123C 7F0AC70C 030B082A */  slt   $at, $t8, $t3
/* 0E1240 7F0AC710 10200002 */  beqz  $at, .L7F0AC71C
/* 0E1244 7F0AC714 00000000 */   nop
/* 0E1248 7F0AC718 2652FFFF */  addiu $s2, $s2, -1
.L7F0AC71C:
/* 0E124C 7F0AC71C 1A400008 */  blez  $s2, .L7F0AC740
/* 0E1250 7F0AC720 A3A00088 */   sb    $zero, 0x88($sp)
/* 0E1254 7F0AC724 02202025 */  move  $a0, $s1
.L7F0AC728:
/* 0E1258 7F0AC728 0C0029FF */  jal   strcat
/* 0E125C 7F0AC72C 02C02825 */   move  $a1, $s6
/* 0E1260 7F0AC730 26100001 */  addiu $s0, $s0, 1
/* 0E1264 7F0AC734 5612FFFC */  bnel  $s0, $s2, .L7F0AC728
/* 0E1268 7F0AC738 02202025 */   move  $a0, $s1
/* 0E126C 7F0AC73C 00008025 */  move  $s0, $zero
.L7F0AC740:
/* 0E1270 7F0AC740 1A600006 */  blez  $s3, .L7F0AC75C
/* 0E1274 7F0AC744 02202025 */   move  $a0, $s1
.L7F0AC748:
/* 0E1278 7F0AC748 0C0029FF */  jal   strcat
/* 0E127C 7F0AC74C 02E02825 */   move  $a1, $s7
/* 0E1280 7F0AC750 26100001 */  addiu $s0, $s0, 1
/* 0E1284 7F0AC754 5613FFFC */  bnel  $s0, $s3, .L7F0AC748
/* 0E1288 7F0AC758 02202025 */   move  $a0, $s1
.L7F0AC75C:
/* 0E128C 7F0AC75C 0FC15C8E */  jal   get_status_of_objective
/* 0E1290 7F0AC760 03C02025 */   move  $a0, $fp
/* 0E1294 7F0AC764 10400009 */  beqz  $v0, .L7F0AC78C
/* 0E1298 7F0AC768 02202025 */   move  $a0, $s1
/* 0E129C 7F0AC76C 24010001 */  li    $at, 1
/* 0E12A0 7F0AC770 10410010 */  beq   $v0, $at, .L7F0AC7B4
/* 0E12A4 7F0AC774 02202025 */   move  $a0, $s1
/* 0E12A8 7F0AC778 24010002 */  li    $at, 2
/* 0E12AC 7F0AC77C 10410014 */  beq   $v0, $at, .L7F0AC7D0
/* 0E12B0 7F0AC780 02202025 */   move  $a0, $s1
/* 0E12B4 7F0AC784 1000001F */  b     .L7F0AC804
/* 0E12B8 7F0AC788 8FA90D4C */   lw    $t1, 0xd4c($sp)
.L7F0AC78C:
/* 0E12BC 7F0AC78C 0C0029FF */  jal   strcat
/* 0E12C0 7F0AC790 8FA50168 */   lw    $a1, 0x168($sp)
/* 0E12C4 7F0AC794 3C198004 */  lui   $t9, %hi(D_80040AFC)
/* 0E12C8 7F0AC798 8F390AFC */  lw    $t9, %lo(D_80040AFC)($t9)
/* 0E12CC 7F0AC79C 3C014000 */  lui   $at, (0x400040FF >> 16) # lui $at, 0x4000
/* 0E12D0 7F0AC7A0 342140FF */  ori   $at, (0x400040FF & 0xFFFF) # ori $at, $at, 0x40ff
/* 0E12D4 7F0AC7A4 00195400 */  sll   $t2, $t9, 0x10
/* 0E12D8 7F0AC7A8 01416825 */  or    $t5, $t2, $at
/* 0E12DC 7F0AC7AC 10000014 */  b     .L7F0AC800
/* 0E12E0 7F0AC7B0 AFAD0084 */   sw    $t5, 0x84($sp)
.L7F0AC7B4:
/* 0E12E4 7F0AC7B4 3C08A0FF */  lui   $t0, (0xA0FFA0F0 >> 16) # lui $t0, 0xa0ff
/* 0E12E8 7F0AC7B8 3508A0F0 */  ori   $t0, (0xA0FFA0F0 & 0xFFFF) # ori $t0, $t0, 0xa0f0
/* 0E12EC 7F0AC7BC AFA80084 */  sw    $t0, 0x84($sp)
/* 0E12F0 7F0AC7C0 0C0029FF */  jal   strcat
/* 0E12F4 7F0AC7C4 8FA5016C */   lw    $a1, 0x16c($sp)
/* 0E12F8 7F0AC7C8 1000000E */  b     .L7F0AC804
/* 0E12FC 7F0AC7CC 8FA90D4C */   lw    $t1, 0xd4c($sp)
.L7F0AC7D0:
/* 0E1300 7F0AC7D0 0C0029FF */  jal   strcat
/* 0E1304 7F0AC7D4 8FA50164 */   lw    $a1, 0x164($sp)
/* 0E1308 7F0AC7D8 3C0C8005 */  lui   $t4, %hi(j_text_trigger)
/* 0E130C 7F0AC7DC 8D8C84D0 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0E1310 7F0AC7E0 3C0E00FF */  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
/* 0E1314 7F0AC7E4 3C0FA0FF */  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
/* 0E1318 7F0AC7E8 11800004 */  beqz  $t4, .L7F0AC7FC
/* 0E131C 7F0AC7EC 35CE00B0 */   ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0E1320 7F0AC7F0 35EFA0F0 */  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
/* 0E1324 7F0AC7F4 10000002 */  b     .L7F0AC800
/* 0E1328 7F0AC7F8 AFAF0084 */   sw    $t7, 0x84($sp)
.L7F0AC7FC:
/* 0E132C 7F0AC7FC AFAE0084 */  sw    $t6, 0x84($sp)
.L7F0AC800:
/* 0E1330 7F0AC800 8FA90D4C */  lw    $t1, 0xd4c($sp)
.L7F0AC804:
/* 0E1334 7F0AC804 240B000A */  li    $t3, 10
/* 0E1338 7F0AC808 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0E133C 7F0AC80C 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0E1340 7F0AC810 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0E1344 7F0AC814 02203025 */  move  $a2, $s1
/* 0E1348 7F0AC818 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E134C 7F0AC81C 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E1350 7F0AC820 AFA90010 */   sw    $t1, 0x10($sp)
/* 0E1354 7F0AC824 3C028005 */  lui   $v0, %hi(j_text_trigger)
/* 0E1358 7F0AC828 8C4284D0 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0E135C 7F0AC82C 8FB80D60 */  lw    $t8, 0xd60($sp)
/* 0E1360 7F0AC830 24040005 */  li    $a0, 5
/* 0E1364 7F0AC834 10400003 */  beqz  $v0, .L7F0AC844
/* 0E1368 7F0AC838 240C00AF */   li    $t4, 175
/* 0E136C 7F0AC83C 10000001 */  b     .L7F0AC844
/* 0E1370 7F0AC840 24040001 */   li    $a0, 1
.L7F0AC844:
/* 0E1374 7F0AC844 0098C821 */  addu  $t9, $a0, $t8
/* 0E1378 7F0AC848 10400006 */  beqz  $v0, .L7F0AC864
/* 0E137C 7F0AC84C AFB90154 */   sw    $t9, 0x154($sp)
/* 0E1380 7F0AC850 8FAA0D50 */  lw    $t2, 0xd50($sp)
/* 0E1384 7F0AC854 240D00F5 */  li    $t5, 245
/* 0E1388 7F0AC858 01AA4023 */  subu  $t0, $t5, $t2
/* 0E138C 7F0AC85C 10000002 */  b     .L7F0AC868
/* 0E1390 7F0AC860 AFA80150 */   sw    $t0, 0x150($sp)
.L7F0AC864:
/* 0E1394 7F0AC864 AFAC0150 */  sw    $t4, 0x150($sp)
.L7F0AC868:
/* 0E1398 7F0AC868 0C00110B */  jal   viGetY
/* 0E139C 7F0AC86C 00000000 */   nop
/* 0E13A0 7F0AC870 8FAF0D48 */  lw    $t7, 0xd48($sp)
/* 0E13A4 7F0AC874 8FAE0D4C */  lw    $t6, 0xd4c($sp)
/* 0E13A8 7F0AC878 8FA90084 */  lw    $t1, 0x84($sp)
/* 0E13AC 7F0AC87C 240B00D2 */  li    $t3, 210
/* 0E13B0 7F0AC880 2418000A */  li    $t8, 10
/* 0E13B4 7F0AC884 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E13B8 7F0AC888 AFAB001C */  sw    $t3, 0x1c($sp)
/* 0E13BC 7F0AC88C 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0E13C0 7F0AC890 27A50150 */  addiu $a1, $sp, 0x150
/* 0E13C4 7F0AC894 27A60154 */  addiu $a2, $sp, 0x154
/* 0E13C8 7F0AC898 02203825 */  move  $a3, $s1
/* 0E13CC 7F0AC89C AFA20020 */  sw    $v0, 0x20($sp)
/* 0E13D0 7F0AC8A0 AFA00024 */  sw    $zero, 0x24($sp)
/* 0E13D4 7F0AC8A4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0E13D8 7F0AC8A8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0E13DC 7F0AC8AC 0FC2B6AF */  jal   en_text_write_stuff
/* 0E13E0 7F0AC8B0 AFA90018 */   sw    $t1, 0x18($sp)
/* 0E13E4 7F0AC8B4 8FB90074 */  lw    $t9, 0x74($sp)
/* 0E13E8 7F0AC8B8 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0E13EC 7F0AC8BC 26730001 */  addiu $s3, $s3, 1
/* 0E13F0 7F0AC8C0 272D0001 */  addiu $t5, $t9, 1
/* 0E13F4 7F0AC8C4 AFAD0074 */  sw    $t5, 0x74($sp)
.L7F0AC8C8:
/* 0E13F8 7F0AC8C8 0FC15C6A */  jal   objectiveGetCount
/* 0E13FC 7F0AC8CC 27DE0001 */   addiu $fp, $fp, 1
/* 0E1400 7F0AC8D0 03C2082A */  slt   $at, $fp, $v0
/* 0E1404 7F0AC8D4 1420FF2E */  bnez  $at, .L7F0AC590
/* 0E1408 7F0AC8D8 00000000 */   nop
.L7F0AC8DC:
/* 0E140C 7F0AC8DC 0FC2B2E8 */  jal   setTextOverlapCorrection
/* 0E1410 7F0AC8E0 2404FFFF */   li    $a0, -1
/* 0E1414 7F0AC8E4 0FC29A13 */  jal   mission_brief_objectives_navigation
/* 0E1418 7F0AC8E8 00000000 */   nop
.L7F0AC8EC:
/* 0E141C 7F0AC8EC 8FAA0D4C */  lw    $t2, 0xd4c($sp)
.L7F0AC8F0:
/* 0E1420 7F0AC8F0 2408000A */  li    $t0, 10
/* 0E1424 7F0AC8F4 AFA80014 */  sw    $t0, 0x14($sp)
/* 0E1428 7F0AC8F8 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0E142C 7F0AC8FC 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0E1430 7F0AC900 27A60170 */  addiu $a2, $sp, 0x170
/* 0E1434 7F0AC904 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E1438 7F0AC908 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E143C 7F0AC90C AFAA0010 */   sw    $t2, 0x10($sp)
/* 0E1440 7F0AC910 8FAC0D48 */  lw    $t4, 0xd48($sp)
/* 0E1444 7F0AC914 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0E1448 7F0AC918 3C0EA0FF */  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
/* 0E144C 7F0AC91C 35CEA0F0 */  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
/* 0E1450 7F0AC920 240900D2 */  li    $t1, 210
/* 0E1454 7F0AC924 240B0082 */  li    $t3, 130
/* 0E1458 7F0AC928 2418000A */  li    $t8, 10
/* 0E145C 7F0AC92C AFB80028 */  sw    $t8, 0x28($sp)
/* 0E1460 7F0AC930 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0E1464 7F0AC934 AFA9001C */  sw    $t1, 0x1c($sp)
/* 0E1468 7F0AC938 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0E146C 7F0AC93C 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0E1470 7F0AC940 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0E1474 7F0AC944 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0E1478 7F0AC948 27A70170 */  addiu $a3, $sp, 0x170
/* 0E147C 7F0AC94C AFA00024 */  sw    $zero, 0x24($sp)
/* 0E1480 7F0AC950 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0E1484 7F0AC954 0FC2B6AF */  jal   en_text_write_stuff
/* 0E1488 7F0AC958 AFAF0014 */   sw    $t7, 0x14($sp)
/* 0E148C 7F0AC95C 8FB90D60 */  lw    $t9, 0xd60($sp)
/* 0E1490 7F0AC960 8FAA0D4C */  lw    $t2, 0xd4c($sp)
/* 0E1494 7F0AC964 2403003C */  li    $v1, 60
/* 0E1498 7F0AC968 2408000A */  li    $t0, 10
/* 0E149C 7F0AC96C 272D0005 */  addiu $t5, $t9, 5
/* 0E14A0 7F0AC970 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0E14A4 7F0AC974 AFAD0D60 */  sw    $t5, 0xd60($sp)
/* 0E14A8 7F0AC978 AFA80014 */  sw    $t0, 0x14($sp)
/* 0E14AC 7F0AC97C AFA30D64 */  sw    $v1, 0xd64($sp)
/* 0E14B0 7F0AC980 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0E14B4 7F0AC984 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0E14B8 7F0AC988 27A60190 */  addiu $a2, $sp, 0x190
/* 0E14BC 7F0AC98C 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0E14C0 7F0AC990 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E14C4 7F0AC994 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0E14C8 7F0AC998 0C001107 */  jal   viGetX
/* 0E14CC 7F0AC99C 00000000 */   nop
/* 0E14D0 7F0AC9A0 0C00110B */  jal   viGetY
/* 0E14D4 7F0AC9A4 A7A20064 */   sh    $v0, 0x64($sp)
/* 0E14D8 7F0AC9A8 8FAC0D48 */  lw    $t4, 0xd48($sp)
/* 0E14DC 7F0AC9AC 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0E14E0 7F0AC9B0 87A90064 */  lh    $t1, 0x64($sp)
/* 0E14E4 7F0AC9B4 3C0E00FF */  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
/* 0E14E8 7F0AC9B8 35CE00B0 */  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0E14EC 7F0AC9BC 240B000A */  li    $t3, 10
/* 0E14F0 7F0AC9C0 AFAB0028 */  sw    $t3, 0x28($sp)
/* 0E14F4 7F0AC9C4 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0E14F8 7F0AC9C8 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0E14FC 7F0AC9CC 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0E1500 7F0AC9D0 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0E1504 7F0AC9D4 27A70190 */  addiu $a3, $sp, 0x190
/* 0E1508 7F0AC9D8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0E150C 7F0AC9DC AFA00024 */  sw    $zero, 0x24($sp)
/* 0E1510 7F0AC9E0 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0E1514 7F0AC9E4 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0E1518 7F0AC9E8 0FC2B6AF */  jal   en_text_write_stuff
/* 0E151C 7F0AC9EC AFA9001C */   sw    $t1, 0x1c($sp)
/* 0E1520 7F0AC9F0 AFA20DE8 */  sw    $v0, 0xde8($sp)
.L7F0AC9F4:
/* 0E1524 7F0AC9F4 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0E1528 7F0AC9F8 8FA20DE8 */  lw    $v0, 0xde8($sp)
/* 0E152C 7F0AC9FC 8FB00038 */  lw    $s0, 0x38($sp)
/* 0E1530 7F0ACA00 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0E1534 7F0ACA04 8FB20040 */  lw    $s2, 0x40($sp)
/* 0E1538 7F0ACA08 8FB30044 */  lw    $s3, 0x44($sp)
/* 0E153C 7F0ACA0C 8FB40048 */  lw    $s4, 0x48($sp)
/* 0E1540 7F0ACA10 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0E1544 7F0ACA14 8FB60050 */  lw    $s6, 0x50($sp)
/* 0E1548 7F0ACA18 8FB70054 */  lw    $s7, 0x54($sp)
/* 0E154C 7F0ACA1C 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0E1550 7F0ACA20 03E00008 */  jr    $ra
/* 0E1554 7F0ACA24 27BD0DE8 */   addiu $sp, $sp, 0xde8
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata

/* .rodata references a variable defined above. */

/*D:80058570*/
glabel jpt_80058570
.word .L7F0AC3B8
.word .L7F0AC400
.word .L7F0AC448
.word .L7F0AC490
.word .L7F0AC4D8

.text
glabel draw_watch_mission_briefing_page
/* 0DDE84 7F0AB494 27BDF218 */  addiu $sp, $sp, -0xde8
/* 0DDE88 7F0AB498 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0DDE8C 7F0AB49C AFBE0058 */  sw    $fp, 0x58($sp)
/* 0DDE90 7F0AB4A0 AFB70054 */  sw    $s7, 0x54($sp)
/* 0DDE94 7F0AB4A4 AFB60050 */  sw    $s6, 0x50($sp)
/* 0DDE98 7F0AB4A8 AFB5004C */  sw    $s5, 0x4c($sp)
/* 0DDE9C 7F0AB4AC AFB40048 */  sw    $s4, 0x48($sp)
/* 0DDEA0 7F0AB4B0 AFB30044 */  sw    $s3, 0x44($sp)
/* 0DDEA4 7F0AB4B4 AFB20040 */  sw    $s2, 0x40($sp)
/* 0DDEA8 7F0AB4B8 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0DDEAC 7F0AB4BC AFB00038 */  sw    $s0, 0x38($sp)
/* 0DDEB0 7F0AB4C0 0FC29919 */  jal   draw_background_health_and_armor
/* 0DDEB4 7F0AB4C4 00003025 */   move  $a2, $zero
/* 0DDEB8 7F0AB4C8 0FC1F9B4 */  jal   check_watch_page_transistion_running
/* 0DDEBC 7F0AB4CC AFA20DE8 */   sw    $v0, 0xde8($sp)
/* 0DDEC0 7F0AB4D0 24010001 */  li    $at, 1
/* 0DDEC4 7F0AB4D4 104101F7 */  beq   $v0, $at, .L7F0ABCB4
/* 0DDEC8 7F0AB4D8 27AE0DAC */   addiu $t6, $sp, 0xdac
/* 0DDECC 7F0AB4DC 3C0F8004 */  lui   $t7, %hi(D_80040DFC) # $t7, 0x8004
/* 0DDED0 7F0AB4E0 25EFAA4C */  addiu $t7, %lo(D_80040DFC) # addiu $t7, $t7, -0x55b4
/* 0DDED4 7F0AB4E4 25F9003C */  addiu $t9, $t7, 0x3c
.L7F0AB4E8:
/* 0DDED8 7F0AB4E8 8DE10000 */  lw    $at, ($t7)
/* 0DDEDC 7F0AB4EC 25EF000C */  addiu $t7, $t7, 0xc
/* 0DDEE0 7F0AB4F0 25CE000C */  addiu $t6, $t6, 0xc
/* 0DDEE4 7F0AB4F4 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0DDEE8 7F0AB4F8 8DE1FFF8 */  lw    $at, -8($t7)
/* 0DDEEC 7F0AB4FC ADC1FFF8 */  sw    $at, -8($t6)
/* 0DDEF0 7F0AB500 8DE1FFFC */  lw    $at, -4($t7)
/* 0DDEF4 7F0AB504 15F9FFF8 */  bne   $t7, $t9, .L7F0AB4E8
/* 0DDEF8 7F0AB508 ADC1FFFC */   sw    $at, -4($t6)
/* 0DDEFC 7F0AB50C 3C098004 */  lui   $t1, %hi(D_80040E38) # $t1, 0x8004
/* 0DDF00 7F0AB510 2529AA88 */  addiu $t1, %lo(D_80040E38) # addiu $t1, $t1, -0x5578
/* 0DDF04 7F0AB514 8D210000 */  lw    $at, ($t1)
/* 0DDF08 7F0AB518 8D2B0004 */  lw    $t3, 4($t1)
/* 0DDF0C 7F0AB51C 27A80DA4 */  addiu $t0, $sp, 0xda4
/* 0DDF10 7F0AB520 3C0D8004 */  lui   $t5, %hi(D_80040E40) # $t5, 0x8004
/* 0DDF14 7F0AB524 25ADAA90 */  addiu $t5, %lo(D_80040E40) # addiu $t5, $t5, -0x5570
/* 0DDF18 7F0AB528 25B9003C */  addiu $t9, $t5, 0x3c
/* 0DDF1C 7F0AB52C 27AC0D68 */  addiu $t4, $sp, 0xd68
/* 0DDF20 7F0AB530 AD010000 */  sw    $at, ($t0)
/* 0DDF24 7F0AB534 AD0B0004 */  sw    $t3, 4($t0)
.L7F0AB538:
/* 0DDF28 7F0AB538 8DA10000 */  lw    $at, ($t5)
/* 0DDF2C 7F0AB53C 25AD000C */  addiu $t5, $t5, 0xc
/* 0DDF30 7F0AB540 258C000C */  addiu $t4, $t4, 0xc
/* 0DDF34 7F0AB544 AD81FFF4 */  sw    $at, -0xc($t4)
/* 0DDF38 7F0AB548 8DA1FFF8 */  lw    $at, -8($t5)
/* 0DDF3C 7F0AB54C AD81FFF8 */  sw    $at, -8($t4)
/* 0DDF40 7F0AB550 8DA1FFFC */  lw    $at, -4($t5)
/* 0DDF44 7F0AB554 15B9FFF8 */  bne   $t5, $t9, .L7F0AB538
/* 0DDF48 7F0AB558 AD81FFFC */   sw    $at, -4($t4)
/* 0DDF4C 7F0AB55C 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0DDF50 7F0AB560 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
/* 0DDF54 7F0AB564 8DEFAAFC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0DDF58 7F0AB568 8DCEAB00 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0DDF5C 7F0AB56C AFA00D54 */  sw    $zero, 0xd54($sp)
/* 0DDF60 7F0AB570 AFA00D50 */  sw    $zero, 0xd50($sp)
/* 0DDF64 7F0AB574 3404AC28 */  li    $a0, 44072
/* 0DDF68 7F0AB578 AFAF0D4C */  sw    $t7, 0xd4c($sp)
/* 0DDF6C 7F0AB57C 0FC304AE */  jal   langGet
/* 0DDF70 7F0AB580 AFAE0D48 */   sw    $t6, 0xd48($sp)
/* 0DDF74 7F0AB584 AFA2016C */  sw    $v0, 0x16c($sp)
/* 0DDF78 7F0AB588 0FC304AE */  jal   langGet
/* 0DDF7C 7F0AB58C 3404AC29 */   li    $a0, 44073
/* 0DDF80 7F0AB590 AFA20168 */  sw    $v0, 0x168($sp)
/* 0DDF84 7F0AB594 0FC304AE */  jal   langGet
/* 0DDF88 7F0AB598 3404AC37 */   li    $a0, 44087
/* 0DDF8C 7F0AB59C AFA20164 */  sw    $v0, 0x164($sp)
/* 0DDF90 7F0AB5A0 0FC15CF9 */  jal   get_ptr_text_for_watch_breifing_page
/* 0DDF94 7F0AB5A4 00002025 */   move  $a0, $zero
/* 0DDF98 7F0AB5A8 3C058005 */  lui   $a1, %hi(D_800577C0) # $a1, 0x8005
/* 0DDF9C 7F0AB5AC 00408025 */  move  $s0, $v0
/* 0DDFA0 7F0AB5B0 24A5CE90 */  addiu $a1, %lo(D_800577C0) # addiu $a1, $a1, -0x3170
/* 0DDFA4 7F0AB5B4 0C0026F4 */  jal   strcpy
/* 0DDFA8 7F0AB5B8 27A40190 */   addiu $a0, $sp, 0x190
/* 0DDFAC 7F0AB5BC 0FC2B016 */  jal   microcode_constructor
/* 0DDFB0 7F0AB5C0 8FA40DE8 */   lw    $a0, 0xde8($sp)
/* 0DDFB4 7F0AB5C4 8FAA0D4C */  lw    $t2, 0xd4c($sp)
/* 0DDFB8 7F0AB5C8 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0DDFBC 7F0AB5CC 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0DDFC0 7F0AB5D0 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0DDFC4 7F0AB5D4 02003025 */  move  $a2, $s0
/* 0DDFC8 7F0AB5D8 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DDFCC 7F0AB5DC AFA00014 */  sw    $zero, 0x14($sp)
/* 0DDFD0 7F0AB5E0 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DDFD4 7F0AB5E4 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0DDFD8 7F0AB5E8 8FA20D50 */  lw    $v0, 0xd50($sp)
/* 0DDFDC 7F0AB5EC 240800AA */  li    $t0, 170
/* 0DDFE0 7F0AB5F0 8FB90D54 */  lw    $t9, 0xd54($sp)
/* 0DDFE4 7F0AB5F4 01021823 */  subu  $v1, $t0, $v0
/* 0DDFE8 7F0AB5F8 04610003 */  bgez  $v1, .L7F0AB608
/* 0DDFEC 7F0AB5FC 00034843 */   sra   $t1, $v1, 1
/* 0DDFF0 7F0AB600 24610001 */  addiu $at, $v1, 1
/* 0DDFF4 7F0AB604 00014843 */  sra   $t1, $at, 1
.L7F0AB608:
/* 0DDFF8 7F0AB608 2523004B */  addiu $v1, $t1, 0x4b
/* 0DDFFC 7F0AB60C 240B001E */  li    $t3, 30
/* 0DE000 7F0AB610 27AC0D58 */  addiu $t4, $sp, 0xd58
/* 0DE004 7F0AB614 0062C021 */  addu  $t8, $v1, $v0
/* 0DE008 7F0AB618 272D001E */  addiu $t5, $t9, 0x1e
/* 0DE00C 7F0AB61C AFAB0D60 */  sw    $t3, 0xd60($sp)
/* 0DE010 7F0AB620 AFB80D5C */  sw    $t8, 0xd5c($sp)
/* 0DE014 7F0AB624 AFAD0D58 */  sw    $t5, 0xd58($sp)
/* 0DE018 7F0AB628 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DE01C 7F0AB62C AFA30D64 */  sw    $v1, 0xd64($sp)
/* 0DE020 7F0AB630 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0DE024 7F0AB634 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0DE028 7F0AB638 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0DE02C 7F0AB63C 0FC2B083 */  jal   draw_blackbox_to_screen
/* 0DE030 7F0AB640 27A70D5C */   addiu $a3, $sp, 0xd5c
/* 0DE034 7F0AB644 8FAF0D48 */  lw    $t7, 0xd48($sp)
/* 0DE038 7F0AB648 8FAE0D4C */  lw    $t6, 0xd4c($sp)
/* 0DE03C 7F0AB64C 8FA80D50 */  lw    $t0, 0xd50($sp)
/* 0DE040 7F0AB650 8FA90D54 */  lw    $t1, 0xd54($sp)
/* 0DE044 7F0AB654 3C0AA0FF */  lui   $t2, (0xA0FFA0F0 >> 16) # lui $t2, 0xa0ff
/* 0DE048 7F0AB658 354AA0F0 */  ori   $t2, (0xA0FFA0F0 & 0xFFFF) # ori $t2, $t2, 0xa0f0
/* 0DE04C 7F0AB65C AFAA0018 */  sw    $t2, 0x18($sp)
/* 0DE050 7F0AB660 00402025 */  move  $a0, $v0
/* 0DE054 7F0AB664 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0DE058 7F0AB668 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0DE05C 7F0AB66C 02003825 */  move  $a3, $s0
/* 0DE060 7F0AB670 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE064 7F0AB674 AFA00028 */  sw    $zero, 0x28($sp)
/* 0DE068 7F0AB678 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DE06C 7F0AB67C AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DE070 7F0AB680 AFA8001C */  sw    $t0, 0x1c($sp)
/* 0DE074 7F0AB684 0FC2B35F */  jal   en_text_write_stuff
/* 0DE078 7F0AB688 AFA90020 */   sw    $t1, 0x20($sp)
/* 0DE07C 7F0AB68C 3C0B8004 */  lui   $t3, %hi(mission_brief_index) # $t3, 0x8004
/* 0DE080 7F0AB690 8D6BA5F0 */  lw    $t3, %lo(mission_brief_index)($t3)
/* 0DE084 7F0AB694 24030041 */  li    $v1, 65
/* 0DE088 7F0AB698 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0DE08C 7F0AB69C 2D610005 */  sltiu $at, $t3, 5
/* 0DE090 7F0AB6A0 10200142 */  beqz  $at, .L7F0ABBAC
/* 0DE094 7F0AB6A4 AFA30D64 */   sw    $v1, 0xd64($sp)
/* 0DE098 7F0AB6A8 000B5880 */  sll   $t3, $t3, 2
/* 0DE09C 7F0AB6AC 3C018005 */  lui   $at, %hi(jpt_80058570)
/* 0DE0A0 7F0AB6B0 002B0821 */  addu  $at, $at, $t3
/* 0DE0A4 7F0AB6B4 8C2BCFC4 */  lw    $t3, %lo(jpt_80058570)($at)
/* 0DE0A8 7F0AB6B8 01600008 */  jr    $t3
/* 0DE0AC 7F0AB6BC 00000000 */   nop   
.L7F0AC3B8:
/* 0DE0B0 7F0AB6C0 0FC304AE */  jal   langGet
/* 0DE0B4 7F0AB6C4 3404AC38 */   li    $a0, 44088
/* 0DE0B8 7F0AB6C8 27A40170 */  addiu $a0, $sp, 0x170
/* 0DE0BC 7F0AB6CC 0C00283D */  jal   sprintf
/* 0DE0C0 7F0AB6D0 00402825 */   move  $a1, $v0
/* 0DE0C4 7F0AB6D4 0FC15CF9 */  jal   get_ptr_text_for_watch_breifing_page
/* 0DE0C8 7F0AB6D8 24040001 */   li    $a0, 1
/* 0DE0CC 7F0AB6DC 8FB80D4C */  lw    $t8, 0xd4c($sp)
/* 0DE0D0 7F0AB6E0 240400D2 */  li    $a0, 210
/* 0DE0D4 7F0AB6E4 00402825 */  move  $a1, $v0
/* 0DE0D8 7F0AB6E8 27A60190 */  addiu $a2, $sp, 0x190
/* 0DE0DC 7F0AB6EC 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE0E0 7F0AB6F0 0FC2B789 */  jal   sub_GAME_7F0AEB64
/* 0DE0E4 7F0AB6F4 AFB80010 */   sw    $t8, 0x10($sp)
/* 0DE0E8 7F0AB6F8 0FC2964E */  jal   mission_brief_background_navigation
/* 0DE0EC 7F0AB6FC 00000000 */   nop   
/* 0DE0F0 7F0AB700 1000012B */  b     .L7F0ABBB0
/* 0DE0F4 7F0AB704 8FB80D4C */   lw    $t8, 0xd4c($sp)
.L7F0AC400:
/* 0DE0F8 7F0AB708 0FC304AE */  jal   langGet
/* 0DE0FC 7F0AB70C 3404AC39 */   li    $a0, 44089
/* 0DE100 7F0AB710 27A40170 */  addiu $a0, $sp, 0x170
/* 0DE104 7F0AB714 0C00283D */  jal   sprintf
/* 0DE108 7F0AB718 00402825 */   move  $a1, $v0
/* 0DE10C 7F0AB71C 0FC15CF9 */  jal   get_ptr_text_for_watch_breifing_page
/* 0DE110 7F0AB720 24040002 */   li    $a0, 2
/* 0DE114 7F0AB724 8FB90D4C */  lw    $t9, 0xd4c($sp)
/* 0DE118 7F0AB728 240400D2 */  li    $a0, 210
/* 0DE11C 7F0AB72C 00402825 */  move  $a1, $v0
/* 0DE120 7F0AB730 27A60190 */  addiu $a2, $sp, 0x190
/* 0DE124 7F0AB734 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE128 7F0AB738 0FC2B789 */  jal   sub_GAME_7F0AEB64
/* 0DE12C 7F0AB73C AFB90010 */   sw    $t9, 0x10($sp)
/* 0DE130 7F0AB740 0FC29670 */  jal   mission_brief_m_briefing_navigation
/* 0DE134 7F0AB744 00000000 */   nop   
/* 0DE138 7F0AB748 10000119 */  b     .L7F0ABBB0
/* 0DE13C 7F0AB74C 8FB80D4C */   lw    $t8, 0xd4c($sp)
.L7F0AC448:
/* 0DE140 7F0AB750 0FC304AE */  jal   langGet
/* 0DE144 7F0AB754 3404AC3A */   li    $a0, 44090
/* 0DE148 7F0AB758 27A40170 */  addiu $a0, $sp, 0x170
/* 0DE14C 7F0AB75C 0C00283D */  jal   sprintf
/* 0DE150 7F0AB760 00402825 */   move  $a1, $v0
/* 0DE154 7F0AB764 0FC15CF9 */  jal   get_ptr_text_for_watch_breifing_page
/* 0DE158 7F0AB768 24040003 */   li    $a0, 3
/* 0DE15C 7F0AB76C 8FAD0D4C */  lw    $t5, 0xd4c($sp)
/* 0DE160 7F0AB770 240400D2 */  li    $a0, 210
/* 0DE164 7F0AB774 00402825 */  move  $a1, $v0
/* 0DE168 7F0AB778 27A60190 */  addiu $a2, $sp, 0x190
/* 0DE16C 7F0AB77C 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE170 7F0AB780 0FC2B789 */  jal   sub_GAME_7F0AEB64
/* 0DE174 7F0AB784 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0DE178 7F0AB788 0FC29693 */  jal   mission_brief_q_branch_navigation
/* 0DE17C 7F0AB78C 00000000 */   nop   
/* 0DE180 7F0AB790 10000107 */  b     .L7F0ABBB0
/* 0DE184 7F0AB794 8FB80D4C */   lw    $t8, 0xd4c($sp)
.L7F0AC490:
/* 0DE188 7F0AB798 0FC304AE */  jal   langGet
/* 0DE18C 7F0AB79C 3404AC3B */   li    $a0, 44091
/* 0DE190 7F0AB7A0 27A40170 */  addiu $a0, $sp, 0x170
/* 0DE194 7F0AB7A4 0C00283D */  jal   sprintf
/* 0DE198 7F0AB7A8 00402825 */   move  $a1, $v0
/* 0DE19C 7F0AB7AC 0FC15CF9 */  jal   get_ptr_text_for_watch_breifing_page
/* 0DE1A0 7F0AB7B0 24040004 */   li    $a0, 4
/* 0DE1A4 7F0AB7B4 8FAC0D4C */  lw    $t4, 0xd4c($sp)
/* 0DE1A8 7F0AB7B8 240400D2 */  li    $a0, 210
/* 0DE1AC 7F0AB7BC 00402825 */  move  $a1, $v0
/* 0DE1B0 7F0AB7C0 27A60190 */  addiu $a2, $sp, 0x190
/* 0DE1B4 7F0AB7C4 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE1B8 7F0AB7C8 0FC2B789 */  jal   sub_GAME_7F0AEB64
/* 0DE1BC 7F0AB7CC AFAC0010 */   sw    $t4, 0x10($sp)
/* 0DE1C0 7F0AB7D0 0FC296B7 */  jal   mission_brief_moneypenny_navigation
/* 0DE1C4 7F0AB7D4 00000000 */   nop   
/* 0DE1C8 7F0AB7D8 100000F5 */  b     .L7F0ABBB0
/* 0DE1CC 7F0AB7DC 8FB80D4C */   lw    $t8, 0xd4c($sp)
.L7F0AC4D8:
/* 0DE1D0 7F0AB7E0 3C0F8004 */  lui   $t7, %hi(j_text_trigger) # $t7, 0x8004
/* 0DE1D4 7F0AB7E4 8DEF1150 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0DE1D8 7F0AB7E8 24120001 */  li    $s2, 1
/* 0DE1DC 7F0AB7EC 00009825 */  move  $s3, $zero
/* 0DE1E0 7F0AB7F0 11E00003 */  beqz  $t7, .L7F0AB800
/* 0DE1E4 7F0AB7F4 AFA00074 */   sw    $zero, 0x74($sp)
/* 0DE1E8 7F0AB7F8 10000002 */  b     .L7F0AB804
/* 0DE1EC 7F0AB7FC 24040001 */   li    $a0, 1
.L7F0AB800:
/* 0DE1F0 7F0AB800 24040005 */  li    $a0, 5
.L7F0AB804:
/* 0DE1F4 7F0AB804 0FC2AF98 */  jal   setTextOverlapCorrection
/* 0DE1F8 7F0AB808 00000000 */   nop   
/* 0DE1FC 7F0AB80C 0FC304AE */  jal   langGet
/* 0DE200 7F0AB810 3404AC3C */   li    $a0, 44092
/* 0DE204 7F0AB814 27A40170 */  addiu $a0, $sp, 0x170
/* 0DE208 7F0AB818 0C00283D */  jal   sprintf
/* 0DE20C 7F0AB81C 00402825 */   move  $a1, $v0
/* 0DE210 7F0AB820 0FC15D22 */  jal   objectiveGetCount
/* 0DE214 7F0AB824 0000F025 */   move  $fp, $zero
/* 0DE218 7F0AB828 184000DC */  blez  $v0, .L7F0ABB9C
/* 0DE21C 7F0AB82C 3C178005 */   lui   $s7, %hi(D_80058454) # $s7, 0x8005
/* 0DE220 7F0AB830 3C168005 */  lui   $s6, %hi(D_80058450) # $s6, 0x8005
/* 0DE224 7F0AB834 3C158005 */  lui   $s5, %hi(D_80058444) # $s5, 0x8005
/* 0DE228 7F0AB838 3C148005 */  lui   $s4, %hi(D_80058440) # $s4, 0x8005
/* 0DE22C 7F0AB83C 2694CE94 */  addiu $s4, %lo(D_80058440) # addiu $s4, $s4, -0x316c
/* 0DE230 7F0AB840 26B5CE98 */  addiu $s5, %lo(D_80058444) # addiu $s5, $s5, -0x3168
/* 0DE234 7F0AB844 26D6CEA4 */  addiu $s6, %lo(D_80058450) # addiu $s6, $s6, -0x315c
/* 0DE238 7F0AB848 26F7CEA8 */  addiu $s7, %lo(D_80058454) # addiu $s7, $s7, -0x3158
/* 0DE23C 7F0AB84C 27B10088 */  addiu $s1, $sp, 0x88
.L7F0AB850:
/* 0DE240 7F0AB850 0FC15D39 */  jal   get_difficulty_for_objective
/* 0DE244 7F0AB854 03C02025 */   move  $a0, $fp
/* 0DE248 7F0AB858 0FC2FC21 */  jal   lvlGetSelectedDifficulty
/* 0DE24C 7F0AB85C AFA20068 */   sw    $v0, 0x68($sp)
/* 0DE250 7F0AB860 8FA40068 */  lw    $a0, 0x68($sp)
/* 0DE254 7F0AB864 0044082A */  slt   $at, $v0, $a0
/* 0DE258 7F0AB868 142000C7 */  bnez  $at, .L7F0ABB88
/* 0DE25C 7F0AB86C 03C02025 */   move  $a0, $fp
/* 0DE260 7F0AB870 0FC15D26 */  jal   get_text_for_objective
/* 0DE264 7F0AB874 00008025 */   move  $s0, $zero
/* 0DE268 7F0AB878 AFA20078 */  sw    $v0, 0x78($sp)
/* 0DE26C 7F0AB87C 1A400008 */  blez  $s2, .L7F0AB8A0
/* 0DE270 7F0AB880 A3A00088 */   sb    $zero, 0x88($sp)
/* 0DE274 7F0AB884 02202025 */  move  $a0, $s1
.L7F0AB888:
/* 0DE278 7F0AB888 0C002717 */  jal   strcat
/* 0DE27C 7F0AB88C 02802825 */   move  $a1, $s4
/* 0DE280 7F0AB890 26100001 */  addiu $s0, $s0, 1
/* 0DE284 7F0AB894 5612FFFC */  bnel  $s0, $s2, .L7F0AB888
/* 0DE288 7F0AB898 02202025 */   move  $a0, $s1
/* 0DE28C 7F0AB89C 00008025 */  move  $s0, $zero
.L7F0AB8A0:
/* 0DE290 7F0AB8A0 1A600007 */  blez  $s3, .L7F0AB8C0
/* 0DE294 7F0AB8A4 02202025 */   move  $a0, $s1
.L7F0AB8A8:
/* 0DE298 7F0AB8A8 0C002717 */  jal   strcat
/* 0DE29C 7F0AB8AC 02A02825 */   move  $a1, $s5
/* 0DE2A0 7F0AB8B0 26100001 */  addiu $s0, $s0, 1
/* 0DE2A4 7F0AB8B4 5613FFFC */  bnel  $s0, $s3, .L7F0AB8A8
/* 0DE2A8 7F0AB8B8 02202025 */   move  $a0, $s1
/* 0DE2AC 7F0AB8BC 00008025 */  move  $s0, $zero
.L7F0AB8C0:
/* 0DE2B0 7F0AB8C0 0C004C2B */  jal   strlen
/* 0DE2B4 7F0AB8C4 02202025 */   move  $a0, $s1
/* 0DE2B8 7F0AB8C8 8FA60074 */  lw    $a2, 0x74($sp)
/* 0DE2BC 7F0AB8CC 00512021 */  addu  $a0, $v0, $s1
/* 0DE2C0 7F0AB8D0 3C058005 */  lui   $a1, %hi(aC_2) # $a1, 0x8005
/* 0DE2C4 7F0AB8D4 AFA4006C */  sw    $a0, 0x6c($sp)
/* 0DE2C8 7F0AB8D8 24A5CE9C */  addiu $a1, %lo(aC_2) # addiu $a1, $a1, -0x3164
/* 0DE2CC 7F0AB8DC 0C00283D */  jal   sprintf
/* 0DE2D0 7F0AB8E0 24C60061 */   addiu $a2, $a2, 0x61
/* 0DE2D4 7F0AB8E4 02202025 */  move  $a0, $s1
/* 0DE2D8 7F0AB8E8 0C002717 */  jal   strcat
/* 0DE2DC 7F0AB8EC 8FA50078 */   lw    $a1, 0x78($sp)
/* 0DE2E0 7F0AB8F0 3C0E8004 */  lui   $t6, %hi(j_text_trigger) # $t6, 0x8004
/* 0DE2E4 7F0AB8F4 8DCE1150 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0DE2E8 7F0AB8F8 8FAA0D60 */  lw    $t2, 0xd60($sp)
/* 0DE2EC 7F0AB8FC 24040005 */  li    $a0, 5
/* 0DE2F0 7F0AB900 11C00003 */  beqz  $t6, .L7F0AB910
/* 0DE2F4 7F0AB904 2409003C */   li    $t1, 60
/* 0DE2F8 7F0AB908 10000001 */  b     .L7F0AB910
/* 0DE2FC 7F0AB90C 24040001 */   li    $a0, 1
.L7F0AB910:
/* 0DE300 7F0AB910 008A4021 */  addu  $t0, $a0, $t2
/* 0DE304 7F0AB914 AFA80154 */  sw    $t0, 0x154($sp)
/* 0DE308 7F0AB918 0C000F9B */  jal   viGetX
/* 0DE30C 7F0AB91C AFA90150 */   sw    $t1, 0x150($sp)
/* 0DE310 7F0AB920 0C000F9F */  jal   viGetY
/* 0DE314 7F0AB924 A7A20064 */   sh    $v0, 0x64($sp)
/* 0DE318 7F0AB928 8FAB0D48 */  lw    $t3, 0xd48($sp)
/* 0DE31C 7F0AB92C 8FB80D4C */  lw    $t8, 0xd4c($sp)
/* 0DE320 7F0AB930 87AD0064 */  lh    $t5, 0x64($sp)
/* 0DE324 7F0AB934 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0DE328 7F0AB938 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0DE32C 7F0AB93C 240C000A */  li    $t4, 10
/* 0DE330 7F0AB940 AFAC0028 */  sw    $t4, 0x28($sp)
/* 0DE334 7F0AB944 AFB90018 */  sw    $t9, 0x18($sp)
/* 0DE338 7F0AB948 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0DE33C 7F0AB94C 27A50150 */  addiu $a1, $sp, 0x150
/* 0DE340 7F0AB950 27A60154 */  addiu $a2, $sp, 0x154
/* 0DE344 7F0AB954 02203825 */  move  $a3, $s1
/* 0DE348 7F0AB958 AFA20020 */  sw    $v0, 0x20($sp)
/* 0DE34C 7F0AB95C AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE350 7F0AB960 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0DE354 7F0AB964 AFB80014 */  sw    $t8, 0x14($sp)
/* 0DE358 7F0AB968 0FC2B35F */  jal   en_text_write_stuff
/* 0DE35C 7F0AB96C AFAD001C */   sw    $t5, 0x1c($sp)
/* 0DE360 7F0AB970 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0DE364 7F0AB974 0FC2AD04 */  jal   sub_GAME_7F0AC0E8
/* 0DE368 7F0AB978 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0DE36C 7F0AB97C 02429021 */  addu  $s2, $s2, $v0
/* 0DE370 7F0AB980 0FC2AD12 */  jal   sub_GAME_7F0AC120
/* 0DE374 7F0AB984 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0DE378 7F0AB988 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0DE37C 7F0AB98C 240E000A */  li    $t6, 10
/* 0DE380 7F0AB990 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DE384 7F0AB994 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0DE388 7F0AB998 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0DE38C 7F0AB99C 00403025 */  move  $a2, $v0
/* 0DE390 7F0AB9A0 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE394 7F0AB9A4 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DE398 7F0AB9A8 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0DE39C 7F0AB9AC 0C000F9B */  jal   viGetX
/* 0DE3A0 7F0AB9B0 00000000 */   nop   
/* 0DE3A4 7F0AB9B4 8FA80D50 */  lw    $t0, 0xd50($sp)
/* 0DE3A8 7F0AB9B8 04410003 */  bgez  $v0, .L7F0AB9C8
/* 0DE3AC 7F0AB9BC 00025043 */   sra   $t2, $v0, 1
/* 0DE3B0 7F0AB9C0 24410001 */  addiu $at, $v0, 1
/* 0DE3B4 7F0AB9C4 00015043 */  sra   $t2, $at, 1
.L7F0AB9C8:
/* 0DE3B8 7F0AB9C8 2509003C */  addiu $t1, $t0, 0x3c
/* 0DE3BC 7F0AB9CC 012A082A */  slt   $at, $t1, $t2
/* 0DE3C0 7F0AB9D0 10200002 */  beqz  $at, .L7F0AB9DC
/* 0DE3C4 7F0AB9D4 00000000 */   nop   
/* 0DE3C8 7F0AB9D8 2652FFFF */  addiu $s2, $s2, -1
.L7F0AB9DC:
/* 0DE3CC 7F0AB9DC 1A400008 */  blez  $s2, .L7F0ABA00
/* 0DE3D0 7F0AB9E0 A3A00088 */   sb    $zero, 0x88($sp)
/* 0DE3D4 7F0AB9E4 02202025 */  move  $a0, $s1
.Leu7F0AB9E8:
/* 0DE3D8 7F0AB9E8 0C002717 */  jal   strcat
/* 0DE3DC 7F0AB9EC 02C02825 */   move  $a1, $s6
/* 0DE3E0 7F0AB9F0 26100001 */  addiu $s0, $s0, 1
/* 0DE3E4 7F0AB9F4 5612FFFC */  bnel  $s0, $s2, .Leu7F0AB9E8
/* 0DE3E8 7F0AB9F8 02202025 */   move  $a0, $s1
/* 0DE3EC 7F0AB9FC 00008025 */  move  $s0, $zero
.L7F0ABA00:
/* 0DE3F0 7F0ABA00 1A600006 */  blez  $s3, .L7F0ABA1C
/* 0DE3F4 7F0ABA04 02202025 */   move  $a0, $s1
.L7F0ABA08:
/* 0DE3F8 7F0ABA08 0C002717 */  jal   strcat
/* 0DE3FC 7F0ABA0C 02E02825 */   move  $a1, $s7
/* 0DE400 7F0ABA10 26100001 */  addiu $s0, $s0, 1
/* 0DE404 7F0ABA14 5613FFFC */  bnel  $s0, $s3, .L7F0ABA08
/* 0DE408 7F0ABA18 02202025 */   move  $a0, $s1
.L7F0ABA1C:
/* 0DE40C 7F0ABA1C 0FC15D46 */  jal   get_status_of_objective
/* 0DE410 7F0ABA20 03C02025 */   move  $a0, $fp
/* 0DE414 7F0ABA24 10400009 */  beqz  $v0, .L7F0ABA4C
/* 0DE418 7F0ABA28 02202025 */   move  $a0, $s1
/* 0DE41C 7F0ABA2C 24010001 */  li    $at, 1
/* 0DE420 7F0ABA30 10410010 */  beq   $v0, $at, .L7F0ABA74
/* 0DE424 7F0ABA34 02202025 */   move  $a0, $s1
/* 0DE428 7F0ABA38 24010002 */  li    $at, 2
/* 0DE42C 7F0ABA3C 10410014 */  beq   $v0, $at, .L7F0ABA90
/* 0DE430 7F0ABA40 02202025 */   move  $a0, $s1
/* 0DE434 7F0ABA44 1000001F */  b     .L7F0ABAC4
/* 0DE438 7F0ABA48 8FA80D4C */   lw    $t0, 0xd4c($sp)
.L7F0ABA4C:
/* 0DE43C 7F0ABA4C 0C002717 */  jal   strcat
/* 0DE440 7F0ABA50 8FA50168 */   lw    $a1, 0x168($sp)
/* 0DE444 7F0ABA54 3C0B8004 */  lui   $t3, %hi(D_80040AFC) # $t3, 0x8004
/* 0DE448 7F0ABA58 8D6BA74C */  lw    $t3, %lo(D_80040AFC)($t3)
/* 0DE44C 7F0ABA5C 3C014000 */  lui   $at, (0x400040FF >> 16) # lui $at, 0x4000
/* 0DE450 7F0ABA60 342140FF */  ori   $at, (0x400040FF & 0xFFFF) # ori $at, $at, 0x40ff
/* 0DE454 7F0ABA64 000BC400 */  sll   $t8, $t3, 0x10
/* 0DE458 7F0ABA68 0301C825 */  or    $t9, $t8, $at
/* 0DE45C 7F0ABA6C 10000014 */  b     .L7F0ABAC0
/* 0DE460 7F0ABA70 AFB90084 */   sw    $t9, 0x84($sp)
.L7F0ABA74:
/* 0DE464 7F0ABA74 3C0DA0FF */  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
/* 0DE468 7F0ABA78 35ADA0F0 */  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
/* 0DE46C 7F0ABA7C AFAD0084 */  sw    $t5, 0x84($sp)
/* 0DE470 7F0ABA80 0C002717 */  jal   strcat
/* 0DE474 7F0ABA84 8FA5016C */   lw    $a1, 0x16c($sp)
/* 0DE478 7F0ABA88 1000000E */  b     .L7F0ABAC4
/* 0DE47C 7F0ABA8C 8FA80D4C */   lw    $t0, 0xd4c($sp)
.L7F0ABA90:
/* 0DE480 7F0ABA90 0C002717 */  jal   strcat
/* 0DE484 7F0ABA94 8FA50164 */   lw    $a1, 0x164($sp)
/* 0DE488 7F0ABA98 3C0C8004 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8004
/* 0DE48C 7F0ABA9C 8D8C1150 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0DE490 7F0ABAA0 3C0E00FF */  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
/* 0DE494 7F0ABAA4 3C0FA0FF */  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
/* 0DE498 7F0ABAA8 11800004 */  beqz  $t4, .L7F0ABABC
/* 0DE49C 7F0ABAAC 35CE00B0 */   ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DE4A0 7F0ABAB0 35EFA0F0 */  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
/* 0DE4A4 7F0ABAB4 10000002 */  b     .L7F0ABAC0
/* 0DE4A8 7F0ABAB8 AFAF0084 */   sw    $t7, 0x84($sp)
.L7F0ABABC:
/* 0DE4AC 7F0ABABC AFAE0084 */  sw    $t6, 0x84($sp)
.L7F0ABAC0:
/* 0DE4B0 7F0ABAC0 8FA80D4C */  lw    $t0, 0xd4c($sp)
.L7F0ABAC4:
/* 0DE4B4 7F0ABAC4 240A000A */  li    $t2, 10
/* 0DE4B8 7F0ABAC8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0DE4BC 7F0ABACC 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0DE4C0 7F0ABAD0 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0DE4C4 7F0ABAD4 02203025 */  move  $a2, $s1
/* 0DE4C8 7F0ABAD8 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE4CC 7F0ABADC 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DE4D0 7F0ABAE0 AFA80010 */   sw    $t0, 0x10($sp)
/* 0DE4D4 7F0ABAE4 3C028004 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8004
/* 0DE4D8 7F0ABAE8 8C421150 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0DE4DC 7F0ABAEC 8FA90D60 */  lw    $t1, 0xd60($sp)
/* 0DE4E0 7F0ABAF0 24040005 */  li    $a0, 5
/* 0DE4E4 7F0ABAF4 10400003 */  beqz  $v0, .L7F0ABB04
/* 0DE4E8 7F0ABAF8 240C00AF */   li    $t4, 175
/* 0DE4EC 7F0ABAFC 10000001 */  b     .L7F0ABB04
/* 0DE4F0 7F0ABB00 24040001 */   li    $a0, 1
.L7F0ABB04:
/* 0DE4F4 7F0ABB04 00895821 */  addu  $t3, $a0, $t1
/* 0DE4F8 7F0ABB08 10400006 */  beqz  $v0, .L7F0ABB24
/* 0DE4FC 7F0ABB0C AFAB0154 */   sw    $t3, 0x154($sp)
/* 0DE500 7F0ABB10 8FB80D50 */  lw    $t8, 0xd50($sp)
/* 0DE504 7F0ABB14 241900F5 */  li    $t9, 245
/* 0DE508 7F0ABB18 03386823 */  subu  $t5, $t9, $t8
/* 0DE50C 7F0ABB1C 10000002 */  b     .L7F0ABB28
/* 0DE510 7F0ABB20 AFAD0150 */   sw    $t5, 0x150($sp)
.L7F0ABB24:
/* 0DE514 7F0ABB24 AFAC0150 */  sw    $t4, 0x150($sp)
.L7F0ABB28:
/* 0DE518 7F0ABB28 0C000F9F */  jal   viGetY
/* 0DE51C 7F0ABB2C 00000000 */   nop   
/* 0DE520 7F0ABB30 8FAF0D48 */  lw    $t7, 0xd48($sp)
/* 0DE524 7F0ABB34 8FAE0D4C */  lw    $t6, 0xd4c($sp)
/* 0DE528 7F0ABB38 8FA80084 */  lw    $t0, 0x84($sp)
/* 0DE52C 7F0ABB3C 240A00D2 */  li    $t2, 210
/* 0DE530 7F0ABB40 2409000A */  li    $t1, 10
/* 0DE534 7F0ABB44 AFA90028 */  sw    $t1, 0x28($sp)
/* 0DE538 7F0ABB48 AFAA001C */  sw    $t2, 0x1c($sp)
/* 0DE53C 7F0ABB4C 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0DE540 7F0ABB50 27A50150 */  addiu $a1, $sp, 0x150
/* 0DE544 7F0ABB54 27A60154 */  addiu $a2, $sp, 0x154
/* 0DE548 7F0ABB58 02203825 */  move  $a3, $s1
/* 0DE54C 7F0ABB5C AFA20020 */  sw    $v0, 0x20($sp)
/* 0DE550 7F0ABB60 AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE554 7F0ABB64 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0DE558 7F0ABB68 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0DE55C 7F0ABB6C 0FC2B35F */  jal   en_text_write_stuff
/* 0DE560 7F0ABB70 AFA80018 */   sw    $t0, 0x18($sp)
/* 0DE564 7F0ABB74 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0DE568 7F0ABB78 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0DE56C 7F0ABB7C 26730001 */  addiu $s3, $s3, 1
/* 0DE570 7F0ABB80 25790001 */  addiu $t9, $t3, 1
/* 0DE574 7F0ABB84 AFB90074 */  sw    $t9, 0x74($sp)
.L7F0ABB88:
/* 0DE578 7F0ABB88 0FC15D22 */  jal   objectiveGetCount
/* 0DE57C 7F0ABB8C 27DE0001 */   addiu $fp, $fp, 1
/* 0DE580 7F0ABB90 03C2082A */  slt   $at, $fp, $v0
/* 0DE584 7F0ABB94 1420FF2E */  bnez  $at, .L7F0AB850
/* 0DE588 7F0ABB98 00000000 */   nop   
.L7F0ABB9C:
/* 0DE58C 7F0ABB9C 0FC2AF98 */  jal   setTextOverlapCorrection
/* 0DE590 7F0ABBA0 2404FFFF */   li    $a0, -1
/* 0DE594 7F0ABBA4 0FC296DB */  jal   mission_brief_objectives_navigation
/* 0DE598 7F0ABBA8 00000000 */   nop   
.L7F0ABBAC:
/* 0DE59C 7F0ABBAC 8FB80D4C */  lw    $t8, 0xd4c($sp)
.L7F0ABBB0:
/* 0DE5A0 7F0ABBB0 240D000A */  li    $t5, 10
/* 0DE5A4 7F0ABBB4 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DE5A8 7F0ABBB8 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0DE5AC 7F0ABBBC 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0DE5B0 7F0ABBC0 27A60170 */  addiu $a2, $sp, 0x170
/* 0DE5B4 7F0ABBC4 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE5B8 7F0ABBC8 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DE5BC 7F0ABBCC AFB80010 */   sw    $t8, 0x10($sp)
/* 0DE5C0 7F0ABBD0 8FAC0D48 */  lw    $t4, 0xd48($sp)
/* 0DE5C4 7F0ABBD4 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0DE5C8 7F0ABBD8 3C0EA0FF */  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
/* 0DE5CC 7F0ABBDC 35CEA0F0 */  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
/* 0DE5D0 7F0ABBE0 240800D2 */  li    $t0, 210
/* 0DE5D4 7F0ABBE4 240A0082 */  li    $t2, 130
/* 0DE5D8 7F0ABBE8 2409000A */  li    $t1, 10
/* 0DE5DC 7F0ABBEC AFA90028 */  sw    $t1, 0x28($sp)
/* 0DE5E0 7F0ABBF0 AFAA0020 */  sw    $t2, 0x20($sp)
/* 0DE5E4 7F0ABBF4 AFA8001C */  sw    $t0, 0x1c($sp)
/* 0DE5E8 7F0ABBF8 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DE5EC 7F0ABBFC 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0DE5F0 7F0ABC00 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0DE5F4 7F0ABC04 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0DE5F8 7F0ABC08 27A70170 */  addiu $a3, $sp, 0x170
/* 0DE5FC 7F0ABC0C AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE600 7F0ABC10 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DE604 7F0ABC14 0FC2B35F */  jal   en_text_write_stuff
/* 0DE608 7F0ABC18 AFAF0014 */   sw    $t7, 0x14($sp)
/* 0DE60C 7F0ABC1C 8FAB0D60 */  lw    $t3, 0xd60($sp)
/* 0DE610 7F0ABC20 8FB80D4C */  lw    $t8, 0xd4c($sp)
/* 0DE614 7F0ABC24 2403003C */  li    $v1, 60
/* 0DE618 7F0ABC28 240D000A */  li    $t5, 10
/* 0DE61C 7F0ABC2C 25790005 */  addiu $t9, $t3, 5
/* 0DE620 7F0ABC30 AFA20DE8 */  sw    $v0, 0xde8($sp)
/* 0DE624 7F0ABC34 AFB90D60 */  sw    $t9, 0xd60($sp)
/* 0DE628 7F0ABC38 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0DE62C 7F0ABC3C AFA30D64 */  sw    $v1, 0xd64($sp)
/* 0DE630 7F0ABC40 27A40D54 */  addiu $a0, $sp, 0xd54
/* 0DE634 7F0ABC44 27A50D50 */  addiu $a1, $sp, 0xd50
/* 0DE638 7F0ABC48 27A60190 */  addiu $a2, $sp, 0x190
/* 0DE63C 7F0ABC4C 8FA70D48 */  lw    $a3, 0xd48($sp)
/* 0DE640 7F0ABC50 0FC2B713 */  jal   sub_GAME_7F0AE98C
/* 0DE644 7F0ABC54 AFB80010 */   sw    $t8, 0x10($sp)
/* 0DE648 7F0ABC58 0C000F9B */  jal   viGetX
/* 0DE64C 7F0ABC5C 00000000 */   nop   
/* 0DE650 7F0ABC60 0C000F9F */  jal   viGetY
/* 0DE654 7F0ABC64 A7A20064 */   sh    $v0, 0x64($sp)
/* 0DE658 7F0ABC68 8FAC0D48 */  lw    $t4, 0xd48($sp)
/* 0DE65C 7F0ABC6C 8FAF0D4C */  lw    $t7, 0xd4c($sp)
/* 0DE660 7F0ABC70 87A80064 */  lh    $t0, 0x64($sp)
/* 0DE664 7F0ABC74 3C0E00FF */  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
/* 0DE668 7F0ABC78 35CE00B0 */  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0DE66C 7F0ABC7C 240A000A */  li    $t2, 10
/* 0DE670 7F0ABC80 AFAA0028 */  sw    $t2, 0x28($sp)
/* 0DE674 7F0ABC84 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0DE678 7F0ABC88 8FA40DE8 */  lw    $a0, 0xde8($sp)
/* 0DE67C 7F0ABC8C 27A50D64 */  addiu $a1, $sp, 0xd64
/* 0DE680 7F0ABC90 27A60D60 */  addiu $a2, $sp, 0xd60
/* 0DE684 7F0ABC94 27A70190 */  addiu $a3, $sp, 0x190
/* 0DE688 7F0ABC98 AFA20020 */  sw    $v0, 0x20($sp)
/* 0DE68C 7F0ABC9C AFA00024 */  sw    $zero, 0x24($sp)
/* 0DE690 7F0ABCA0 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0DE694 7F0ABCA4 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0DE698 7F0ABCA8 0FC2B35F */  jal   en_text_write_stuff
/* 0DE69C 7F0ABCAC AFA8001C */   sw    $t0, 0x1c($sp)
/* 0DE6A0 7F0ABCB0 AFA20DE8 */  sw    $v0, 0xde8($sp)
.L7F0ABCB4:
/* 0DE6A4 7F0ABCB4 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0DE6A8 7F0ABCB8 8FA20DE8 */  lw    $v0, 0xde8($sp)
/* 0DE6AC 7F0ABCBC 8FB00038 */  lw    $s0, 0x38($sp)
/* 0DE6B0 7F0ABCC0 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0DE6B4 7F0ABCC4 8FB20040 */  lw    $s2, 0x40($sp)
/* 0DE6B8 7F0ABCC8 8FB30044 */  lw    $s3, 0x44($sp)
/* 0DE6BC 7F0ABCCC 8FB40048 */  lw    $s4, 0x48($sp)
/* 0DE6C0 7F0ABCD0 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0DE6C4 7F0ABCD4 8FB60050 */  lw    $s6, 0x50($sp)
/* 0DE6C8 7F0ABCD8 8FB70054 */  lw    $s7, 0x54($sp)
/* 0DE6CC 7F0ABCDC 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0DE6D0 7F0ABCE0 03E00008 */  jr    $ra
/* 0DE6D4 7F0ABCE4 27BD0DE8 */   addiu $sp, $sp, 0xde8
)
#endif

#endif


Gfx *sub_GAME_7F0ACA28(Gfx *gdl, Mtx *arg1, s32 watch_transitioning)
{
    set_page_rectangle_colors(watch_screen_index, (struct WatchVertex *)g_CurrentPlayer->buffer_for_watch_greenbackdrop_vertices);

    if (watch_transitioning == TRUE)
    {
        set_BONDdata_outside_watch_menu_flag(0);
        sub_GAME_7F0BD8FC(0);

        // Handle A or Z button click when in any page but inventory page
        if ((watch_screen_index != WATCH_INDEX_INVENTORY) && (joyGetButtonsPressedThisFrame(PLAYER_1, Z_TRIG|A_BUTTON)))
        {
            watch_play_beep_sound();
        }

        switch (watch_screen_index)
        {
            case WATCH_INDEX_MISSION_STATUS:
                gdl = draw_watch_mission_status_page(gdl, arg1);
                break;
            case WATCH_INDEX_INVENTORY:
                gdl = draw_watch_inventory_page(gdl, arg1);
                break;
            case WATCH_INDEX_CONTROL_OPTIONS:
                gdl = draw_watch_control_options_page(gdl, arg1);
                break;
            case WATCH_INDEX_GAME_OPTIONS:
                gdl = draw_watch_game_options_page(gdl, arg1);
                break;
            case WATCH_INDEX_MISSION_BRIEFING:
                gdl = draw_watch_mission_briefing_page(gdl, arg1);
        }
    }
    else if (watch_transitioning == FALSE)
    {
        sub_GAME_7F0BD8FC(1);
        set_BONDdata_outside_watch_menu_flag(1);
        gdl = draw_background_health_and_armor_transitioning(gdl, arg1);
    }

    return gdl;
}
