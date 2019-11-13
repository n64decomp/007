#include "ultra64.h"
#include "game/debugmenu_090490.h"
#include "game/initgamedata.h"

// data
//D:80036BA0
u32 D_80036BA0 = 0;
//D:80036BA4
s32 mcm_column_groupings[] = {8, 0x13, 0x1E, 0x2B, 0x32, 0x39, 0x45, 0x4D, -1};

//D:80036BC8
struct mcm_layout mcm_onscreen_positions[] = {
    {8, 5},
    {8, 6},
    {8, 7},
    {8, 8},
    {8, 9},
    {8, 0xA},
    {8, 0xB},
    {8, 0xC},
    {0x19, 5},
    {0x19, 6},
    {0x19, 7},
    {0x19, 8},
    {0x19, 9},
    {0x19, 0xA},
    {0x19, 0xB},
    {0x19, 0xC},
    {0x19, 0xD},
    {0x19, 0xE},
    {0x19, 0xF},
    {0x28, 5},
    {0x28, 6},
    {0x28, 7},
    {0x28, 8},
    {0x28, 9},
    {0x28, 0xA},
    {0x28, 0xB},
    {0x28, 0xC},
    {0x28, 0xD},
    {0x28, 0xE},
    {0x28, 0xF},
    {0x39, 5},
    {0x39, 6},
    {0x39, 7},
    {0x39, 8},
    {0x39, 9},
    {0x39, 0xA},
    {0x39, 0xB},
    {0x39, 0xC},
    {0x39, 0xD},
    {0x39, 0xE},
    {0x39, 0xF},
    {0x39, 0x10},
    {0x39, 0x11},
    {8, 0x14},
    {8, 0x15},
    {8, 0x16},
    {8, 0x17},
    {8, 0x18},
    {8, 0x19},
    {8, 0x1A},
    {0x19, 0x14},
    {0x19, 0x15},
    {0x19, 0x16},
    {0x19, 0x17},
    {0x19, 0x18},
    {0x19, 0x19},
    {0x19, 0x1A},
    {0x28, 0x14},
    {0x28, 0x15},
    {0x28, 0x16},
    {0x28, 0x17},
    {0x28, 0x18},
    {0x28, 0x19},
    {0x28, 0x1A},
    {0x28, 0x1B},
    {0x28, 0x1C},
    {0x28, 0x1D},
    {0x28, 0x1E},
    {0x28, 0x1F},
    {0x39, 0x14},
    {0x39, 0x15},
    {0x39, 0x16},
    {0x39, 0x17},
    {0x39, 0x18},
    {0x39, 0x19},
    {0x39, 0x1A},
    {0x39, 0x1B}
};

//D:80036E30
char *mcm_strings[] = {
     "move view",
     "stan view",
     "bond view",
     "level",
     "region",
     "scale",
     "play title",
     "bond die",
     "select anim",
     "gun pos",
     "flash colour",
     "hit colour",
     "music",
     "sfx",
     "invincible",
     "visible",
     "collisions",
     "all guns",
     "max ammo",
     "display speed",
     "background",
     "props",
     "stan hit",
     "stan region",
     "stan problems",
     "print man pos",
     "port close",
     "port inf",
     "port approx",
     "pr room loads",
     "show mem use",
     "show mem bars",
     "grab rgb",
     "grab jpeg",
     "grab task",
     "rnd walk",
     "record ramrom",
     "record 1",
     "record 2",
     "record 3",
     "replay ramrom",
     "save ramrom",
     "load ramrom",
     "auto y aim",
     "auto x aim",
     "007",
     "agent",
     "all",
     "fast",
     "objectives",
     "marg top",
     "marg bot",
     "marg left",
     "marg right",
     "marg reset",
     "screen size",
     "screen pos",
     "show patrols",
     "intro",
     "intro edit",
     "intro pos",
     "world pos",
     "gun key pos",
     "vis cvg",
     "chr num",
     "room blocks",
     "profile",
     "obj load",
     "weapon load",
     "joy2 sky edit",
     "joy2 hits edit",
     "joy2 detail edit",
     "explosion info",
     "magic fog",
     "gun watch pos",
     "testing man pos",
     "fog"
};

//D:80036F64
s32 debug_render_raster = 2;
//D:80036F68
s32 debug_freeze_processing = 2;
//D:80036F6C
s32 debug_limit_controller_input = 2;
//D:80036F70
s32 debug_unknown = 2;
//D:80036F74
s32 memusage_display_flag = FALSE;
//D:80036F78
s32 debug_do_draw_bg = TRUE;
//D:80036F7C
s32 debug_do_draw_obj = TRUE;
//D:80036F80
s32 debug_unknown2 = 1;
//D:80036F84
s32 debug_stanhit_flag = FALSE;
//D:80036F88
s32 debug_stanregion_flag = FALSE;
//D:80036F8C
s32 turbo_mode_flag = FALSE;
//D:80036F90
s32 debug_man_pos_flag = 0;
//D:80036F94
s32 debug_prroomloads_flag = 0;
//D:80036F98
s32 debug_joy2skyedit_flag = 0;
//D:80036F9C
s32 debug_joy2hitsedit_flag = 0;
//D:80036FA0
s32 debug_joy2detailedit_flag = 0;
//D:80036FA4
s32 debug_explosioninfo_flag = 0;
//D:80036FA8
s32 debug_VisCVG_flag = 0;
//D:80036FAC
s32 debug_007_unlock_flag = 0;
//D:80036FB0
s32 debug_enable_agent_levels_flag = 0;
//D:80036FB4
s32 debug_enable_all_levels_flag = 0;
//D:80036FB8
s32 debug_chrnum_flag = 0;

//D:80036FBC
s32 debug_gunwatchpos_flags = 0;
//D:80036FC0
s32 debug_profile_flag = 0;
//D:80036FC4
s32 debug_enable_taskgrab_flag = 0;
//D:80036FC8
s32 debug_testingmanpos_flag = 0;
//D:80036FCC
s32 debug_fast_bond_flag = 0;
//D:80036FD0
s32 debug_all_obj_complete_flag = 0 ;
//D:80036FD4
s32 debug_portal_flag = 0;

//D:80036FD8
u32 dword_D_80036FD8[] = {
    0x80500000,
    0x40000,
    0x7F000000,
    0x7F100000
};

u32 dword_D_80036FE8[] = {
    0x80600000,
    0x40000,
    0x70000000,
    0x70100000
};

//D:80036FF8
s32 show_debug_menu_flag = 0;
//D:80036FFC
s32 grab_rgb_screenshot_flag = 0;
//D:80037000
s32 grab_jpeg_screenshot_flag = 0;
//D:80037004
s32 D_80037004 = 0;
//D:80037008
s32 D_80037008 = 0;
//D:8003700C
s32 D_8003700C = 0;



// rodata


#ifdef NONMATCHING
void display_debug_menu_text_onscreen(void)
{
  init_debug_menu_values((char *)mcm_strings,mcm_onscreen_positions,mcm_column_groupings);
}
#else
GLOBAL_ASM(
.text
glabel display_debug_menu_text_onscreen
/* 0C4FC0 7F090490 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C4FC4 7F090494 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C4FC8 7F090498 3C048003 */  lui   $a0, %hi(mcm_strings)
/* 0C4FCC 7F09049C 3C058003 */  lui   $a1, %hi(mcm_onscreen_positions)
/* 0C4FD0 7F0904A0 3C068003 */  lui   $a2, %hi(mcm_column_groupings)
/* 0C4FD4 7F0904A4 24C66BA4 */  addiu $a2, %lo(mcm_column_groupings) # addiu $a2, $a2, 0x6ba4
/* 0C4FD8 7F0904A8 24A56BC8 */  addiu $a1, %lo(mcm_onscreen_positions) # addiu $a1, $a1, 0x6bc8
/* 0C4FDC 7F0904AC 0FC23F85 */  jal   init_debug_menu_values
/* 0C4FE0 7F0904B0 24846E30 */   addiu $a0, %lo(mcm_strings) # addiu $a0, $a0, 0x6e30
/* 0C4FE4 7F0904B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C4FE8 7F0904B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C4FEC 7F0904BC 03E00008 */  jr    $ra
/* 0C4FF0 7F0904C0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0904C4(void) {
    ? temp_ret;

    // Node 0
    sub_GAME_7F0916F4();
    temp_ret = get_highlighted_debug_option();
    debug_unknown = temp_ret;
    debug_freeze_processing = temp_ret;
    debug_render_raster = temp_ret;
    return temp_ret;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0904C4
/* 0C4FF4 7F0904C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C4FF8 7F0904C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C4FFC 7F0904CC 0FC245BD */  jal   sub_GAME_7F0916F4
/* 0C5000 7F0904D0 00000000 */   nop   
/* 0C5004 7F0904D4 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5008 7F0904D8 00000000 */   nop   
/* 0C500C 7F0904DC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C5010 7F0904E0 3C038003 */  lui   $v1, %hi(debug_unknown)
/* 0C5014 7F0904E4 3C048003 */  lui   $a0, %hi(debug_freeze_processing)
/* 0C5018 7F0904E8 24846F68 */  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
/* 0C501C 7F0904EC 24636F70 */  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
/* 0C5020 7F0904F0 AC620000 */  sw    $v0, ($v1)
/* 0C5024 7F0904F4 AC820000 */  sw    $v0, ($a0)
/* 0C5028 7F0904F8 3C018003 */  lui   $at, %hi(debug_render_raster)
/* 0C502C 7F0904FC AC226F64 */  sw    $v0, %lo(debug_render_raster)($at)
/* 0C5030 7F090500 03E00008 */  jr    $ra
/* 0C5034 7F090504 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F090508(void) {
    ? temp_ret;

    // Node 0
    maybe_solo_intro_camera_handler();
    temp_ret = get_highlighted_debug_option();
    debug_unknown = temp_ret;
    debug_freeze_processing = temp_ret;
    debug_render_raster = temp_ret;
    return temp_ret;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F090508
/* 0C5038 7F090508 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C503C 7F09050C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C5040 7F090510 0FC1E928 */  jal   maybe_solo_intro_camera_handler
/* 0C5044 7F090514 00000000 */   nop   
/* 0C5048 7F090518 0FC2406C */  jal   get_highlighted_debug_option
/* 0C504C 7F09051C 00000000 */   nop   
/* 0C5050 7F090520 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C5054 7F090524 3C038003 */  lui   $v1, %hi(debug_unknown)
/* 0C5058 7F090528 3C048003 */  lui   $a0, %hi(debug_freeze_processing)
/* 0C505C 7F09052C 24846F68 */  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
/* 0C5060 7F090530 24636F70 */  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
/* 0C5064 7F090534 AC620000 */  sw    $v0, ($v1)
/* 0C5068 7F090538 AC820000 */  sw    $v0, ($a0)
/* 0C506C 7F09053C 3C018003 */  lui   $at, %hi(debug_render_raster)
/* 0C5070 7F090540 AC226F64 */  sw    $v0, %lo(debug_render_raster)($at)
/* 0C5074 7F090544 03E00008 */  jr    $ra
/* 0C5078 7F090548 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09054C(void) {
    ? temp_ret;

    // Node 0
    maybe_solo_intro_camera_handler();
    temp_ret = get_highlighted_debug_option();
    debug_unknown = temp_ret;
    debug_freeze_processing = temp_ret;
    debug_render_raster = temp_ret;
    return temp_ret;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09054C
/* 0C507C 7F09054C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C5080 7F090550 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C5084 7F090554 0FC1E928 */  jal   maybe_solo_intro_camera_handler
/* 0C5088 7F090558 00000000 */   nop   
/* 0C508C 7F09055C 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5090 7F090560 00000000 */   nop   
/* 0C5094 7F090564 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C5098 7F090568 3C038003 */  lui   $v1, %hi(debug_unknown)
/* 0C509C 7F09056C 3C048003 */  lui   $a0, %hi(debug_freeze_processing)
/* 0C50A0 7F090570 24846F68 */  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
/* 0C50A4 7F090574 24636F70 */  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
/* 0C50A8 7F090578 AC620000 */  sw    $v0, ($v1)
/* 0C50AC 7F09057C AC820000 */  sw    $v0, ($a0)
/* 0C50B0 7F090580 3C018003 */  lui   $at, %hi(debug_render_raster)
/* 0C50B4 7F090584 AC226F64 */  sw    $v0, %lo(debug_render_raster)($at)
/* 0C50B8 7F090588 03E00008 */  jr    $ra
/* 0C50BC 7F09058C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif



void unknown_libname_68(void) {
    return;
}

void nullsub_35(void) {
    return;
}






#ifdef NONMATCHING
void debug_menu_processor(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:800556FC*/
glabel jpt_debug_menu_options
.word debug_stanview
.word debug_bondview
.word .L7F090798
.word debug_level
.word .L7F0907BC
.word debug_scale
.word debug_playtitle
.word debug_bonddie
.word debug_selectanim
.word debug_gunpos
.word debug_flashcolor
.word debug_hitcolor
.word debug_music
.word debug_sfx
.word debug_invincible
.word debug_visible
.word debug_collisions
.word debug_allguns
.word debug_maxammo
.word debug_displayspeed
.word debug_dodrawbg
.word debug_dodrawobj
.word debug_stanhit
.word debug_stanregion
.word debug_turbo
.word debug_printmanpos
.word portal_close_inf_approx
.word portal_close_inf_approx
.word portal_close_inf_approx
.word debug_prroomloads
.word debug_showmemuse
.word debug_showmembars
.word debug_grabrgb
.word debug_grabjpeg
.word debug_taskgrab
.word def_7F090770
.word debug_recordramrom
.word debug_ramrom_record1
.word debug_ramrom_record2
.word debug_ramrom_record3
.word debug_replayramrom
.word debug_saveramrom
.word debug_loadramrom
.word debug_autoyaim
.word debug_autoxaim
.word debug_007
.word debug_agent
.word debug_all
.word fast_bond_debug
.word debug_objectives
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word .L7F090834
.word debug_screenpos
.word debug_showpatrols
.word debug_intro
.word debug_introedit
.word debug_intropos
.word debug_worldpos
.word debug_chrkeypos
.word debug_viscvg
.word debug_chrnum
.word debug_roomblocks
.word debug_profile
.word debug_objload
.word debug_weaponload
.word debug_joy2skyedit
.word debug_joy2hitsedit
.word debug_joy2detailedit
.word debug_explosioninfo
.word debug_magicfog
.word debug_gunwatchpos
.word debug_testingmanpos
.word debug_fog

/*D:80055830*/
glabel jpt_80055830
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8

.text
glabel debug_menu_processor
/* 0C50D0 7F0905A0 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0C50D4 7F0905A4 3C038003 */  lui   $v1, %hi(grab_rgb_screenshot_flag)
/* 0C50D8 7F0905A8 8C636FFC */  lw    $v1, %lo(grab_rgb_screenshot_flag)($v1)
/* 0C50DC 7F0905AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C50E0 7F0905B0 AFA40060 */  sw    $a0, 0x60($sp)
/* 0C50E4 7F0905B4 AFA50064 */  sw    $a1, 0x64($sp)
/* 0C50E8 7F0905B8 AFA60068 */  sw    $a2, 0x68($sp)
/* 0C50EC 7F0905BC 1060000D */  beqz  $v1, .L7F0905F4
/* 0C50F0 7F0905C0 AFA7006C */   sw    $a3, 0x6c($sp)
/* 0C50F4 7F0905C4 38620003 */  xori  $v0, $v1, 3
/* 0C50F8 7F0905C8 24630001 */  addiu $v1, $v1, 1
/* 0C50FC 7F0905CC 3C018003 */  lui   $at, %hi(grab_rgb_screenshot_flag)
/* 0C5100 7F0905D0 14400008 */  bnez  $v0, .L7F0905F4
/* 0C5104 7F0905D4 AC236FFC */   sw    $v1, %lo(grab_rgb_screenshot_flag)($at)
/* 0C5108 7F0905D8 0C0012ED */  jal   indy_grab_rgb_32bit
/* 0C510C 7F0905DC 00000000 */   nop   
/* 0C5110 7F0905E0 3C018003 */  lui   $at, %hi(grab_rgb_screenshot_flag)
/* 0C5114 7F0905E4 0C000F00 */  jal   set_coloroutputmode_16bit
/* 0C5118 7F0905E8 AC206FFC */   sw    $zero, %lo(grab_rgb_screenshot_flag)($at)
/* 0C511C 7F0905EC 0C0038B4 */  jal   osViBlack
/* 0C5120 7F0905F0 00002025 */   move  $a0, $zero
.L7F0905F4:
/* 0C5124 7F0905F4 3C038003 */  lui   $v1, %hi(grab_jpeg_screenshot_flag)
/* 0C5128 7F0905F8 8C637000 */  lw    $v1, %lo(grab_jpeg_screenshot_flag)($v1)
/* 0C512C 7F0905FC 3C018003 */  lui   $at, %hi(grab_jpeg_screenshot_flag)
/* 0C5130 7F090600 1060000B */  beqz  $v1, .L7F090630
/* 0C5134 7F090604 38620003 */   xori  $v0, $v1, 3
/* 0C5138 7F090608 24630001 */  addiu $v1, $v1, 1
/* 0C513C 7F09060C 14400008 */  bnez  $v0, .L7F090630
/* 0C5140 7F090610 AC237000 */   sw    $v1, %lo(grab_jpeg_screenshot_flag)($at)
/* 0C5144 7F090614 0C001235 */  jal   indy_grab_jpg_32bit
/* 0C5148 7F090618 00000000 */   nop   
/* 0C514C 7F09061C 3C018003 */  lui   $at, %hi(grab_jpeg_screenshot_flag)
/* 0C5150 7F090620 0C000F00 */  jal   set_coloroutputmode_16bit
/* 0C5154 7F090624 AC207000 */   sw    $zero, %lo(grab_jpeg_screenshot_flag)($at)
/* 0C5158 7F090628 0C0038B4 */  jal   osViBlack
/* 0C515C 7F09062C 00002025 */   move  $a0, $zero
.L7F090630:
/* 0C5160 7F090630 3C0E8003 */  lui   $t6, %hi(show_debug_menu_flag) 
/* 0C5164 7F090634 8DCE6FF8 */  lw    $t6, %lo(show_debug_menu_flag)($t6)
/* 0C5168 7F090638 3C048003 */  lui   $a0, %hi(debug_limit_controller_input)
/* 0C516C 7F09063C 3C018003 */  lui   $at, %hi(show_debug_menu_flag)
/* 0C5170 7F090640 15C00010 */  bnez  $t6, .L7F090684
/* 0C5174 7F090644 24846F6C */   addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
/* 0C5178 7F090648 97A4006A */  lhu   $a0, 0x6a($sp)
/* 0C517C 7F09064C 30830008 */  andi  $v1, $a0, 8
/* 0C5180 7F090650 0003102B */  sltu  $v0, $zero, $v1
/* 0C5184 7F090654 10400004 */  beqz  $v0, .L7F090668
/* 0C5188 7F090658 00000000 */   nop   
/* 0C518C 7F09065C 30820004 */  andi  $v0, $a0, 4
/* 0C5190 7F090660 0002C02B */  sltu  $t8, $zero, $v0
/* 0C5194 7F090664 03001025 */  move  $v0, $t8
.L7F090668:
/* 0C5198 7F090668 10400003 */  beqz  $v0, .L7F090678
/* 0C519C 7F09066C AC226FF8 */   sw    $v0, %lo(show_debug_menu_flag)($at)
/* 0C51A0 7F090670 0FC301F5 */  jal   stop_recording_ramrom
/* 0C51A4 7F090674 00000000 */   nop   
.L7F090678:
/* 0C51A8 7F090678 3C028003 */  lui   $v0, %hi(show_debug_menu_flag)
/* 0C51AC 7F09067C 1000021B */  b     .L7F090EEC
/* 0C51B0 7F090680 8C426FF8 */   lw    $v0, %lo(show_debug_menu_flag)($v0)
.L7F090684:
/* 0C51B4 7F090684 8C820000 */  lw    $v0, ($a0)
/* 0C51B8 7F090688 2403FFFE */  li    $v1, -2
/* 0C51BC 7F09068C 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C51C0 7F090690 50620004 */  beql  $v1, $v0, .L7F0906A4
/* 0C51C4 7F090694 97B9006E */   lhu   $t9, 0x6e($sp)
/* 0C51C8 7F090698 AC226F70 */  sw    $v0, %lo(debug_unknown)($at)
/* 0C51CC 7F09069C AC830000 */  sw    $v1, ($a0)
/* 0C51D0 7F0906A0 97B9006E */  lhu   $t9, 0x6e($sp)
.L7F0906A4:
/* 0C51D4 7F0906A4 33280200 */  andi  $t0, $t9, 0x200
/* 0C51D8 7F0906A8 11000007 */  beqz  $t0, .L7F0906C8
/* 0C51DC 7F0906AC AFB90018 */   sw    $t9, 0x18($sp)
/* 0C51E0 7F0906B0 0FC240E7 */  jal   sub_GAME_7F09039C
/* 0C51E4 7F0906B4 00000000 */   nop   
/* 0C51E8 7F0906B8 3C048003 */  lui   $a0, %hi(debug_limit_controller_input)
/* 0C51EC 7F0906BC 24846F6C */  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
/* 0C51F0 7F0906C0 2403FFFE */  li    $v1, -2
/* 0C51F4 7F0906C4 AC830000 */  sw    $v1, ($a0)
.L7F0906C8:
/* 0C51F8 7F0906C8 8FA90018 */  lw    $t1, 0x18($sp)
/* 0C51FC 7F0906CC 312A0100 */  andi  $t2, $t1, 0x100
/* 0C5200 7F0906D0 51400008 */  beql  $t2, $zero, .L7F0906F4
/* 0C5204 7F0906D4 8FAB0018 */   lw    $t3, 0x18($sp)
/* 0C5208 7F0906D8 0FC240B0 */  jal   sub_GAME_7F0902C0
/* 0C520C 7F0906DC 00000000 */   nop   
/* 0C5210 7F0906E0 3C048003 */  lui   $a0, %hi(debug_limit_controller_input)
/* 0C5214 7F0906E4 24846F6C */  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
/* 0C5218 7F0906E8 2403FFFE */  li    $v1, -2
/* 0C521C 7F0906EC AC830000 */  sw    $v1, ($a0)
/* 0C5220 7F0906F0 8FAB0018 */  lw    $t3, 0x18($sp)
.L7F0906F4:
/* 0C5224 7F0906F4 316C0800 */  andi  $t4, $t3, 0x800
/* 0C5228 7F0906F8 51800008 */  beql  $t4, $zero, .L7F09071C
/* 0C522C 7F0906FC 8FAD0018 */   lw    $t5, 0x18($sp)
/* 0C5230 7F090700 0FC24072 */  jal   sub_GAME_7F0901C8
/* 0C5234 7F090704 00000000 */   nop   
/* 0C5238 7F090708 3C048003 */  lui   $a0, %hi(debug_limit_controller_input)
/* 0C523C 7F09070C 24846F6C */  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
/* 0C5240 7F090710 2403FFFE */  li    $v1, -2
/* 0C5244 7F090714 AC830000 */  sw    $v1, ($a0)
/* 0C5248 7F090718 8FAD0018 */  lw    $t5, 0x18($sp)
.L7F09071C:
/* 0C524C 7F09071C 31AE0400 */  andi  $t6, $t5, 0x400
/* 0C5250 7F090720 51C00008 */  beql  $t6, $zero, .L7F090744
/* 0C5254 7F090724 8FAF0018 */   lw    $t7, 0x18($sp)
/* 0C5258 7F090728 0FC24092 */  jal   sub_GAME_7F090248
/* 0C525C 7F09072C 00000000 */   nop   
/* 0C5260 7F090730 3C048003 */  lui   $a0, %hi(debug_limit_controller_input)
/* 0C5264 7F090734 24846F6C */  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
/* 0C5268 7F090738 2403FFFE */  li    $v1, -2
/* 0C526C 7F09073C AC830000 */  sw    $v1, ($a0)
/* 0C5270 7F090740 8FAF0018 */  lw    $t7, 0x18($sp)
.L7F090744:
/* 0C5274 7F090744 31F89000 */  andi  $t8, $t7, 0x9000
/* 0C5278 7F090748 530001CB */  beql  $t8, $zero, .L7F090E78
/* 0C527C 7F09074C 8FB80018 */   lw    $t8, 0x18($sp)
/* 0C5280 7F090750 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5284 7F090754 00000000 */   nop   
/* 0C5288 7F090758 2C41004D */  sltiu $at, $v0, 0x4d
/* 0C528C 7F09075C 102001C5 */  beqz  $at, .L7F090E74
/* 0C5290 7F090760 0002C880 */   sll   $t9, $v0, 2
/* 0C5294 7F090764 3C018005 */  lui   $at, %hi(jpt_debug_menu_options)
/* 0C5298 7F090768 00390821 */  addu  $at, $at, $t9
/* 0C529C 7F09076C 8C3956FC */  lw    $t9, %lo(jpt_debug_menu_options)($at)
/* 0C52A0 7F090770 03200008 */  jr    $t9
/* 0C52A4 7F090774 00000000 */   nop   
debug_stanview:
/* 0C52A8 7F090778 0FC24131 */  jal   sub_GAME_7F0904C4
/* 0C52AC 7F09077C 00000000 */   nop   
/* 0C52B0 7F090780 100001BD */  b     .L7F090E78
/* 0C52B4 7F090784 8FB80018 */   lw    $t8, 0x18($sp)
debug_bondview:
/* 0C52B8 7F090788 0FC24142 */  jal   sub_GAME_7F090508
/* 0C52BC 7F09078C 00000000 */   nop   
/* 0C52C0 7F090790 100001B9 */  b     .L7F090E78
/* 0C52C4 7F090794 8FB80018 */   lw    $t8, 0x18($sp)
.L7F090798:
/* 0C52C8 7F090798 0FC24153 */  jal   sub_GAME_7F09054C
/* 0C52CC 7F09079C 00000000 */   nop   
/* 0C52D0 7F0907A0 100001B5 */  b     .L7F090E78
/* 0C52D4 7F0907A4 8FB80018 */   lw    $t8, 0x18($sp)
debug_level:
/* 0C52D8 7F0907A8 0FC2406C */  jal   get_highlighted_debug_option
/* 0C52DC 7F0907AC 00000000 */   nop   
/* 0C52E0 7F0907B0 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C52E4 7F0907B4 100001AF */  b     .L7F090E74
/* 0C52E8 7F0907B8 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
.L7F0907BC:
/* 0C52EC 7F0907BC 0FC2406C */  jal   get_highlighted_debug_option
/* 0C52F0 7F0907C0 00000000 */   nop   
/* 0C52F4 7F0907C4 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C52F8 7F0907C8 100001AA */  b     .L7F090E74
/* 0C52FC 7F0907CC AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_scale:
/* 0C5300 7F0907D0 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5304 7F0907D4 00000000 */   nop   
/* 0C5308 7F0907D8 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C530C 7F0907DC 100001A5 */  b     .L7F090E74
/* 0C5310 7F0907E0 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_selectanim:
/* 0C5314 7F0907E4 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5318 7F0907E8 00000000 */   nop   
/* 0C531C 7F0907EC 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5320 7F0907F0 100001A0 */  b     .L7F090E74
/* 0C5324 7F0907F4 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_gunpos:
/* 0C5328 7F0907F8 0FC2406C */  jal   get_highlighted_debug_option
/* 0C532C 7F0907FC 00000000 */   nop   
/* 0C5330 7F090800 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5334 7F090804 1000019B */  b     .L7F090E74
/* 0C5338 7F090808 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_flashcolor:
/* 0C533C 7F09080C 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5340 7F090810 00000000 */   nop   
/* 0C5344 7F090814 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5348 7F090818 10000196 */  b     .L7F090E74
/* 0C534C 7F09081C AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_hitcolor:
/* 0C5350 7F090820 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5354 7F090824 00000000 */   nop   
/* 0C5358 7F090828 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C535C 7F09082C 10000191 */  b     .L7F090E74
/* 0C5360 7F090830 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
.L7F090834:
/* 0C5364 7F090834 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5368 7F090838 00000000 */   nop   
/* 0C536C 7F09083C 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5370 7F090840 1000018C */  b     .L7F090E74
/* 0C5374 7F090844 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_screenpos:
/* 0C5378 7F090848 0FC2406C */  jal   get_highlighted_debug_option
/* 0C537C 7F09084C 00000000 */   nop   
/* 0C5380 7F090850 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5384 7F090854 10000187 */  b     .L7F090E74
/* 0C5388 7F090858 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_music:
/* 0C538C 7F09085C 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5390 7F090860 00000000 */   nop   
/* 0C5394 7F090864 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5398 7F090868 10000182 */  b     .L7F090E74
/* 0C539C 7F09086C AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
portal_close_inf_approx:
/* 0C53A0 7F090870 3C028003 */  lui   $v0, %hi(debug_portal_flag)
/* 0C53A4 7F090874 24426FD4 */  addiu $v0, %lo(debug_portal_flag) # addiu $v0, $v0, 0x6fd4
/* 0C53A8 7F090878 8C480000 */  lw    $t0, ($v0)
/* 0C53AC 7F09087C 39090001 */  xori  $t1, $t0, 1
/* 0C53B0 7F090880 1000017C */  b     .L7F090E74
/* 0C53B4 7F090884 AC490000 */   sw    $t1, ($v0)
debug_sfx:
/* 0C53B8 7F090888 0FC2406C */  jal   get_highlighted_debug_option
/* 0C53BC 7F09088C 00000000 */   nop   
/* 0C53C0 7F090890 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C53C4 7F090894 10000177 */  b     .L7F090E74
/* 0C53C8 7F090898 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_invincible:
/* 0C53CC 7F09089C 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C53D0 7F0908A0 00000000 */   nop   
/* 0C53D4 7F0908A4 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C53D8 7F0908A8 2C440001 */   sltiu $a0, $v0, 1
/* 0C53DC 7F0908AC 10000172 */  b     .L7F090E78
/* 0C53E0 7F0908B0 8FB80018 */   lw    $t8, 0x18($sp)
debug_visible:
/* 0C53E4 7F0908B4 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C53E8 7F0908B8 00000000 */   nop   
/* 0C53EC 7F0908BC 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C53F0 7F0908C0 2C440001 */   sltiu $a0, $v0, 1
/* 0C53F4 7F0908C4 1000016C */  b     .L7F090E78
/* 0C53F8 7F0908C8 8FB80018 */   lw    $t8, 0x18($sp)
debug_collisions:
/* 0C53FC 7F0908CC 0FC227E3 */  jal   get_obj_collision_flag
/* 0C5400 7F0908D0 00000000 */   nop   
/* 0C5404 7F0908D4 0FC227E0 */  jal   set_obj_collision_flag
/* 0C5408 7F0908D8 2C440001 */   sltiu $a0, $v0, 1
/* 0C540C 7F0908DC 10000166 */  b     .L7F090E78
/* 0C5410 7F0908E0 8FB80018 */   lw    $t8, 0x18($sp)
debug_allguns:
/* 0C5414 7F0908E4 0FC26919 */  jal   get_num_players
/* 0C5418 7F0908E8 AFA0005C */   sw    $zero, 0x5c($sp)
/* 0C541C 7F0908EC 58400162 */  blezl $v0, .L7F090E78
/* 0C5420 7F0908F0 8FB80018 */   lw    $t8, 0x18($sp)
.L7F0908F4:
/* 0C5424 7F0908F4 0FC26C43 */  jal   set_cur_player
/* 0C5428 7F0908F8 8FA4005C */   lw    $a0, 0x5c($sp)
/* 0C542C 7F0908FC 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C5430 7F090900 00000000 */   nop   
/* 0C5434 7F090904 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C5438 7F090908 2C440001 */   sltiu $a0, $v0, 1
/* 0C543C 7F09090C 8FAA005C */  lw    $t2, 0x5c($sp)
/* 0C5440 7F090910 254B0001 */  addiu $t3, $t2, 1
/* 0C5444 7F090914 0FC26919 */  jal   get_num_players
/* 0C5448 7F090918 AFAB005C */   sw    $t3, 0x5c($sp)
/* 0C544C 7F09091C 8FAC005C */  lw    $t4, 0x5c($sp)
/* 0C5450 7F090920 0182082A */  slt   $at, $t4, $v0
/* 0C5454 7F090924 1420FFF3 */  bnez  $at, .L7F0908F4
/* 0C5458 7F090928 00000000 */   nop   
/* 0C545C 7F09092C 10000152 */  b     .L7F090E78
/* 0C5460 7F090930 8FB80018 */   lw    $t8, 0x18($sp)
debug_maxammo:
/* 0C5464 7F090934 0FC26C54 */  jal   get_cur_playernum
/* 0C5468 7F090938 00000000 */   nop   
/* 0C546C 7F09093C AFA20054 */  sw    $v0, 0x54($sp)
/* 0C5470 7F090940 0FC26919 */  jal   get_num_players
/* 0C5474 7F090944 AFA00058 */   sw    $zero, 0x58($sp)
/* 0C5478 7F090948 1840000D */  blez  $v0, .L7F090980
/* 0C547C 7F09094C 00000000 */   nop   
.L7F090950:
/* 0C5480 7F090950 0FC26C43 */  jal   set_cur_player
/* 0C5484 7F090954 8FA40058 */   lw    $a0, 0x58($sp)
/* 0C5488 7F090958 0FC1A4BC */  jal   set_max_ammo_for_cur_player
/* 0C548C 7F09095C 00000000 */   nop   
/* 0C5490 7F090960 8FAD0058 */  lw    $t5, 0x58($sp)
/* 0C5494 7F090964 25AE0001 */  addiu $t6, $t5, 1
/* 0C5498 7F090968 0FC26919 */  jal   get_num_players
/* 0C549C 7F09096C AFAE0058 */   sw    $t6, 0x58($sp)
/* 0C54A0 7F090970 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0C54A4 7F090974 01E2082A */  slt   $at, $t7, $v0
/* 0C54A8 7F090978 1420FFF5 */  bnez  $at, .L7F090950
/* 0C54AC 7F09097C 00000000 */   nop   
.L7F090980:
/* 0C54B0 7F090980 0FC26C43 */  jal   set_cur_player
/* 0C54B4 7F090984 8FA40054 */   lw    $a0, 0x54($sp)
/* 0C54B8 7F090988 1000013B */  b     .L7F090E78
/* 0C54BC 7F09098C 8FB80018 */   lw    $t8, 0x18($sp)
debug_displayspeed:
/* 0C54C0 7F090990 3C028003 */  lui   $v0, %hi(memusage_display_flag)
/* 0C54C4 7F090994 24426F74 */  addiu $v0, %lo(memusage_display_flag) # addiu $v0, $v0, 0x6f74
/* 0C54C8 7F090998 8C580000 */  lw    $t8, ($v0)
/* 0C54CC 7F09099C 3B190001 */  xori  $t9, $t8, 1
/* 0C54D0 7F0909A0 17200134 */  bnez  $t9, .L7F090E74
/* 0C54D4 7F0909A4 AC590000 */   sw    $t9, ($v0)
/* 0C54D8 7F0909A8 0C002BC0 */  jal   blank_debug_buffer_chars
/* 0C54DC 7F0909AC 00000000 */   nop   
/* 0C54E0 7F0909B0 10000131 */  b     .L7F090E78
/* 0C54E4 7F0909B4 8FB80018 */   lw    $t8, 0x18($sp)
debug_dodrawbg:
/* 0C54E8 7F0909B8 3C028003 */  lui   $v0, %hi(debug_do_draw_bg)
/* 0C54EC 7F0909BC 24426F78 */  addiu $v0, %lo(debug_do_draw_bg) # addiu $v0, $v0, 0x6f78
/* 0C54F0 7F0909C0 8C490000 */  lw    $t1, ($v0)
/* 0C54F4 7F0909C4 392A0001 */  xori  $t2, $t1, 1
/* 0C54F8 7F0909C8 1000012A */  b     .L7F090E74
/* 0C54FC 7F0909CC AC4A0000 */   sw    $t2, ($v0)
debug_dodrawobj:
/* 0C5500 7F0909D0 3C028003 */  lui   $v0, %hi(debug_do_draw_obj)
/* 0C5504 7F0909D4 24426F7C */  addiu $v0, %lo(debug_do_draw_obj) # addiu $v0, $v0, 0x6f7c
/* 0C5508 7F0909D8 8C4B0000 */  lw    $t3, ($v0)
/* 0C550C 7F0909DC 396C0001 */  xori  $t4, $t3, 1
/* 0C5510 7F0909E0 10000124 */  b     .L7F090E74
/* 0C5514 7F0909E4 AC4C0000 */   sw    $t4, ($v0)
debug_stanhit:
/* 0C5518 7F0909E8 3C028003 */  lui   $v0, %hi(debug_stanhit_flag)
/* 0C551C 7F0909EC 24426F84 */  addiu $v0, %lo(debug_stanhit_flag) # addiu $v0, $v0, 0x6f84
/* 0C5520 7F0909F0 8C4D0000 */  lw    $t5, ($v0)
/* 0C5524 7F0909F4 39AE0001 */  xori  $t6, $t5, 1
/* 0C5528 7F0909F8 1000011E */  b     .L7F090E74
/* 0C552C 7F0909FC AC4E0000 */   sw    $t6, ($v0)
debug_stanregion:
/* 0C5530 7F090A00 3C028003 */  lui   $v0, %hi(debug_stanregion_flag)
/* 0C5534 7F090A04 24426F88 */  addiu $v0, %lo(debug_stanregion_flag) # addiu $v0, $v0, 0x6f88
/* 0C5538 7F090A08 8C4F0000 */  lw    $t7, ($v0)
/* 0C553C 7F090A0C 39F80001 */  xori  $t8, $t7, 1
/* 0C5540 7F090A10 10000118 */  b     .L7F090E74
/* 0C5544 7F090A14 AC580000 */   sw    $t8, ($v0)
debug_turbo:
/* 0C5548 7F090A18 3C028003 */  lui   $v0, %hi(turbo_mode_flag)
/* 0C554C 7F090A1C 24426F8C */  addiu $v0, %lo(turbo_mode_flag) # addiu $v0, $v0, 0x6f8c
/* 0C5550 7F090A20 8C590000 */  lw    $t9, ($v0)
/* 0C5554 7F090A24 3B280001 */  xori  $t0, $t9, 1
/* 0C5558 7F090A28 10000112 */  b     .L7F090E74
/* 0C555C 7F090A2C AC480000 */   sw    $t0, ($v0)
debug_printmanpos:
/* 0C5560 7F090A30 3C028003 */  lui   $v0, %hi(debug_man_pos_flag)
/* 0C5564 7F090A34 24426F90 */  addiu $v0, %lo(debug_man_pos_flag) # addiu $v0, $v0, 0x6f90
/* 0C5568 7F090A38 8C490000 */  lw    $t1, ($v0)
/* 0C556C 7F090A3C 392A0001 */  xori  $t2, $t1, 1
/* 0C5570 7F090A40 1000010C */  b     .L7F090E74
/* 0C5574 7F090A44 AC4A0000 */   sw    $t2, ($v0)
debug_testingmanpos:
/* 0C5578 7F090A48 3C028003 */  lui   $v0, %hi(debug_testingmanpos_flag)
/* 0C557C 7F090A4C 24426FC8 */  addiu $v0, %lo(debug_testingmanpos_flag) # addiu $v0, $v0, 0x6fc8
/* 0C5580 7F090A50 8C4B0000 */  lw    $t3, ($v0)
/* 0C5584 7F090A54 396C0001 */  xori  $t4, $t3, 1
/* 0C5588 7F090A58 10000106 */  b     .L7F090E74
/* 0C558C 7F090A5C AC4C0000 */   sw    $t4, ($v0)
debug_playtitle:
/* 0C5590 7F090A60 0C001A54 */  jal   set_loaded_stage
/* 0C5594 7F090A64 2404005A */   li    $a0, 90
/* 0C5598 7F090A68 10000103 */  b     .L7F090E78
/* 0C559C 7F090A6C 8FB80018 */   lw    $t8, 0x18($sp)
debug_bonddie:
/* 0C55A0 7F090A70 0FC225EA */  jal   kill_current_player
/* 0C55A4 7F090A74 00000000 */   nop   
/* 0C55A8 7F090A78 100000FF */  b     .L7F090E78
/* 0C55AC 7F090A7C 8FB80018 */   lw    $t8, 0x18($sp)
debug_prroomloads:
/* 0C55B0 7F090A80 3C028003 */  lui   $v0, %hi(debug_prroomloads_flag)
/* 0C55B4 7F090A84 24426F94 */  addiu $v0, %lo(debug_prroomloads_flag) # addiu $v0, $v0, 0x6f94
/* 0C55B8 7F090A88 8C4D0000 */  lw    $t5, ($v0)
/* 0C55BC 7F090A8C 39AE0001 */  xori  $t6, $t5, 1
/* 0C55C0 7F090A90 100000F8 */  b     .L7F090E74
/* 0C55C4 7F090A94 AC4E0000 */   sw    $t6, ($v0)
debug_showmemuse:
/* 0C55C8 7F090A98 0C0017FD */  jal   enable_show_mem_use_flag
/* 0C55CC 7F090A9C 00000000 */   nop   
/* 0C55D0 7F090AA0 100000F5 */  b     .L7F090E78
/* 0C55D4 7F090AA4 8FB80018 */   lw    $t8, 0x18($sp)
debug_showmembars:
/* 0C55D8 7F090AA8 0C001801 */  jal   mem_bars_flag_toggle
/* 0C55DC 7F090AAC 00000000 */   nop   
/* 0C55E0 7F090AB0 100000F1 */  b     .L7F090E78
/* 0C55E4 7F090AB4 8FB80018 */   lw    $t8, 0x18($sp)
debug_grabrgb:
/* 0C55E8 7F090AB8 24030001 */  li    $v1, 1
/* 0C55EC 7F090ABC 3C018003 */  lui   $at, %hi(grab_rgb_screenshot_flag)
/* 0C55F0 7F090AC0 AC236FFC */  sw    $v1, %lo(grab_rgb_screenshot_flag)($at)
/* 0C55F4 7F090AC4 0C0038B4 */  jal   osViBlack
/* 0C55F8 7F090AC8 24040001 */   li    $a0, 1
/* 0C55FC 7F090ACC 0C000F04 */  jal   set_coloroutputmode_32bit
/* 0C5600 7F090AD0 00000000 */   nop   
/* 0C5604 7F090AD4 100000E8 */  b     .L7F090E78
/* 0C5608 7F090AD8 8FB80018 */   lw    $t8, 0x18($sp)
debug_grabjpeg:
/* 0C560C 7F090ADC 24030001 */  li    $v1, 1
/* 0C5610 7F090AE0 3C018003 */  lui   $at, %hi(grab_jpeg_screenshot_flag)
/* 0C5614 7F090AE4 AC237000 */  sw    $v1, %lo(grab_jpeg_screenshot_flag)($at)
/* 0C5618 7F090AE8 0C0038B4 */  jal   osViBlack
/* 0C561C 7F090AEC 24040001 */   li    $a0, 1
/* 0C5620 7F090AF0 0C000F04 */  jal   set_coloroutputmode_32bit
/* 0C5624 7F090AF4 00000000 */   nop   
/* 0C5628 7F090AF8 100000DF */  b     .L7F090E78
/* 0C562C 7F090AFC 8FB80018 */   lw    $t8, 0x18($sp)
debug_taskgrab:
/* 0C5630 7F090B00 3C028003 */  lui   $v0, %hi(debug_enable_taskgrab_flag)
/* 0C5634 7F090B04 24426FC4 */  addiu $v0, %lo(debug_enable_taskgrab_flag) # addiu $v0, $v0, 0x6fc4
/* 0C5638 7F090B08 8C4F0000 */  lw    $t7, ($v0)
/* 0C563C 7F090B0C 39F80001 */  xori  $t8, $t7, 1
/* 0C5640 7F090B10 100000D8 */  b     .L7F090E74
/* 0C5644 7F090B14 AC580000 */   sw    $t8, ($v0)
debug_recordramrom:
/* 0C5648 7F090B18 0FC301EF */  jal   setRamRomRecordSlot
/* 0C564C 7F090B1C 00002025 */   move  $a0, $zero
/* 0C5650 7F090B20 100000D5 */  b     .L7F090E78
/* 0C5654 7F090B24 8FB80018 */   lw    $t8, 0x18($sp)
debug_ramrom_record1:
/* 0C5658 7F090B28 0FC301EF */  jal   setRamRomRecordSlot
/* 0C565C 7F090B2C 24040001 */   li    $a0, 1
/* 0C5660 7F090B30 100000D1 */  b     .L7F090E78
/* 0C5664 7F090B34 8FB80018 */   lw    $t8, 0x18($sp)
debug_ramrom_record2:
/* 0C5668 7F090B38 0FC301EF */  jal   setRamRomRecordSlot
/* 0C566C 7F090B3C 24040002 */   li    $a0, 2
/* 0C5670 7F090B40 100000CD */  b     .L7F090E78
/* 0C5674 7F090B44 8FB80018 */   lw    $t8, 0x18($sp)
debug_ramrom_record3:
/* 0C5678 7F090B48 0FC301EF */  jal   setRamRomRecordSlot
/* 0C567C 7F090B4C 24040003 */   li    $a0, 3
/* 0C5680 7F090B50 100000C9 */  b     .L7F090E78
/* 0C5684 7F090B54 8FB80018 */   lw    $t8, 0x18($sp)
debug_replayramrom:
/* 0C5688 7F090B58 0FC3022A */  jal   replay_recorded_ramrom_from_indy
/* 0C568C 7F090B5C 00000000 */   nop   
/* 0C5690 7F090B60 100000C5 */  b     .L7F090E78
/* 0C5694 7F090B64 8FB80018 */   lw    $t8, 0x18($sp)
debug_saveramrom:
/* 0C5698 7F090B68 0FC2FF58 */  jal   save_ramrom_to_devtool
/* 0C569C 7F090B6C 00000000 */   nop   
/* 0C56A0 7F090B70 100000C1 */  b     .L7F090E78
/* 0C56A4 7F090B74 8FB80018 */   lw    $t8, 0x18($sp)
debug_loadramrom:
/* 0C56A8 7F090B78 0FC2FF80 */  jal   load_ramrom_from_devtool
/* 0C56AC 7F090B7C 00000000 */   nop   
/* 0C56B0 7F090B80 100000BD */  b     .L7F090E78
/* 0C56B4 7F090B84 8FB80018 */   lw    $t8, 0x18($sp)
debug_autoyaim:
/* 0C56B8 7F090B88 0FC1F160 */  jal   get_BONDdata_autoaim_y
/* 0C56BC 7F090B8C 00000000 */   nop   
/* 0C56C0 7F090B90 0FC1F15C */  jal   set_BONDdata_autoaim_y
/* 0C56C4 7F090B94 2C440001 */   sltiu $a0, $v0, 1
/* 0C56C8 7F090B98 100000B7 */  b     .L7F090E78
/* 0C56CC 7F090B9C 8FB80018 */   lw    $t8, 0x18($sp)
debug_autoxaim:
/* 0C56D0 7F090BA0 0FC1F19A */  jal   get_BONDdata_autoaim_x
/* 0C56D4 7F090BA4 00000000 */   nop   
/* 0C56D8 7F090BA8 0FC1F196 */  jal   set_BONDdata_autoaim_x
/* 0C56DC 7F090BAC 2C440001 */   sltiu $a0, $v0, 1
/* 0C56E0 7F090BB0 100000B1 */  b     .L7F090E78
/* 0C56E4 7F090BB4 8FB80018 */   lw    $t8, 0x18($sp)
debug_007:
/* 0C56E8 7F090BB8 3C028003 */  lui   $v0, %hi(debug_007_unlock_flag)
/* 0C56EC 7F090BBC 24426FAC */  addiu $v0, %lo(debug_007_unlock_flag) # addiu $v0, $v0, 0x6fac
/* 0C56F0 7F090BC0 8C590000 */  lw    $t9, ($v0)
/* 0C56F4 7F090BC4 3B280001 */  xori  $t0, $t9, 1
/* 0C56F8 7F090BC8 100000AA */  b     .L7F090E74
/* 0C56FC 7F090BCC AC480000 */   sw    $t0, ($v0)
debug_agent:
/* 0C5700 7F090BD0 3C028003 */  lui   $v0, %hi(debug_enable_agent_levels_flag)
/* 0C5704 7F090BD4 24426FB0 */  addiu $v0, %lo(debug_enable_agent_levels_flag) # addiu $v0, $v0, 0x6fb0
/* 0C5708 7F090BD8 8C490000 */  lw    $t1, ($v0)
/* 0C570C 7F090BDC 392A0001 */  xori  $t2, $t1, 1
/* 0C5710 7F090BE0 100000A4 */  b     .L7F090E74
/* 0C5714 7F090BE4 AC4A0000 */   sw    $t2, ($v0)
debug_all:
/* 0C5718 7F090BE8 3C028003 */  lui   $v0, %hi(debug_enable_all_levels_flag)
/* 0C571C 7F090BEC 24426FB4 */  addiu $v0, %lo(debug_enable_all_levels_flag) # addiu $v0, $v0, 0x6fb4
/* 0C5720 7F090BF0 8C4B0000 */  lw    $t3, ($v0)
/* 0C5724 7F090BF4 396C0001 */  xori  $t4, $t3, 1
/* 0C5728 7F090BF8 1000009E */  b     .L7F090E74
/* 0C572C 7F090BFC AC4C0000 */   sw    $t4, ($v0)
fast_bond_debug:
/* 0C5730 7F090C00 3C028003 */  lui   $v0, %hi(debug_fast_bond_flag)
/* 0C5734 7F090C04 24426FCC */  addiu $v0, %lo(debug_fast_bond_flag) # addiu $v0, $v0, 0x6fcc
/* 0C5738 7F090C08 8C4D0000 */  lw    $t5, ($v0)
/* 0C573C 7F090C0C 39AE0001 */  xori  $t6, $t5, 1
/* 0C5740 7F090C10 10000098 */  b     .L7F090E74
/* 0C5744 7F090C14 AC4E0000 */   sw    $t6, ($v0)
debug_objectives:
/* 0C5748 7F090C18 3C028003 */  lui   $v0, %hi(debug_all_obj_complete_flag)
/* 0C574C 7F090C1C 24426FD0 */  addiu $v0, %lo(debug_all_obj_complete_flag) # addiu $v0, $v0, 0x6fd0
/* 0C5750 7F090C20 8C4F0000 */  lw    $t7, ($v0)
/* 0C5754 7F090C24 39F80001 */  xori  $t8, $t7, 1
/* 0C5758 7F090C28 10000092 */  b     .L7F090E74
/* 0C575C 7F090C2C AC580000 */   sw    $t8, ($v0)
debug_showpatrols:
/* 0C5760 7F090C30 0FC07D5A */  jal   get_show_patrols_flag
/* 0C5764 7F090C34 00000000 */   nop   
/* 0C5768 7F090C38 0FC07D57 */  jal   set_show_patrols_flag
/* 0C576C 7F090C3C 2C440001 */   sltiu $a0, $v0, 1
/* 0C5770 7F090C40 1000008D */  b     .L7F090E78
/* 0C5774 7F090C44 8FB80018 */   lw    $t8, 0x18($sp)
debug_intro:
/* 0C5778 7F090C48 0FC1EA6E */  jal   set_camera_mode
/* 0C577C 7F090C4C 24040003 */   li    $a0, 3
/* 0C5780 7F090C50 10000089 */  b     .L7F090E78
/* 0C5784 7F090C54 8FB80018 */   lw    $t8, 0x18($sp)
debug_intropos:
/* 0C5788 7F090C58 3C198003 */  lui   $t9, %hi(debug_render_raster) 
/* 0C578C 7F090C5C 8F396F64 */  lw    $t9, %lo(debug_render_raster)($t9)
/* 0C5790 7F090C60 57200085 */  bnezl $t9, .L7F090E78
/* 0C5794 7F090C64 8FB80018 */   lw    $t8, 0x18($sp)
/* 0C5798 7F090C68 0FC24586 */  jal   sub_GAME_7F091618
/* 0C579C 7F090C6C 00000000 */   nop   
/* 0C57A0 7F090C70 10000081 */  b     .L7F090E78
/* 0C57A4 7F090C74 8FB80018 */   lw    $t8, 0x18($sp)
debug_worldpos:
/* 0C57A8 7F090C78 3C088003 */  lui   $t0, %hi(debug_render_raster) 
/* 0C57AC 7F090C7C 8D086F64 */  lw    $t0, %lo(debug_render_raster)($t0)
/* 0C57B0 7F090C80 15000005 */  bnez  $t0, .L7F090C98
/* 0C57B4 7F090C84 00000000 */   nop   
/* 0C57B8 7F090C88 0FC2459B */  jal   sub_GAME_7F09166C
/* 0C57BC 7F090C8C 00000000 */   nop   
/* 0C57C0 7F090C90 10000079 */  b     .L7F090E78
/* 0C57C4 7F090C94 8FB80018 */   lw    $t8, 0x18($sp)
.L7F090C98:
/* 0C57C8 7F090C98 0FC225E6 */  jal   get_curplayer_positiondata
/* 0C57CC 7F090C9C 00000000 */   nop   
/* 0C57D0 7F090CA0 10400074 */  beqz  $v0, .L7F090E74
/* 0C57D4 7F090CA4 00401825 */   move  $v1, $v0
/* 0C57D8 7F090CA8 3C028003 */  lui   $v0, %hi(D_80037004)
/* 0C57DC 7F090CAC 24427004 */  addiu $v0, %lo(D_80037004) # addiu $v0, $v0, 0x7004
/* 0C57E0 7F090CB0 C4460000 */  lwc1  $f6, ($v0)
/* 0C57E4 7F090CB4 C4640008 */  lwc1  $f4, 8($v1)
/* 0C57E8 7F090CB8 C44A0004 */  lwc1  $f10, 4($v0)
/* 0C57EC 7F090CBC C468000C */  lwc1  $f8, 0xc($v1)
/* 0C57F0 7F090CC0 46062001 */  sub.s $f0, $f4, $f6
/* 0C57F4 7F090CC4 C4520008 */  lwc1  $f18, 8($v0)
/* 0C57F8 7F090CC8 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0C57FC 7F090CCC 460A4081 */  sub.s $f2, $f8, $f10
/* 0C5800 7F090CD0 46000102 */  mul.s $f4, $f0, $f0
/* 0C5804 7F090CD4 AFA30050 */  sw    $v1, 0x50($sp)
/* 0C5808 7F090CD8 46128381 */  sub.s $f14, $f16, $f18
/* 0C580C 7F090CDC 46021182 */  mul.s $f6, $f2, $f2
/* 0C5810 7F090CE0 46062200 */  add.s $f8, $f4, $f6
/* 0C5814 7F090CE4 460E7282 */  mul.s $f10, $f14, $f14
/* 0C5818 7F090CE8 0C007DF8 */  jal   sqrtf
/* 0C581C 7F090CEC 460A4300 */   add.s $f12, $f8, $f10
/* 0C5820 7F090CF0 8FA30050 */  lw    $v1, 0x50($sp)
/* 0C5824 7F090CF4 3C028003 */  lui   $v0, %hi(D_80037004)
/* 0C5828 7F090CF8 24427004 */  addiu $v0, %lo(D_80037004) # addiu $v0, $v0, 0x7004
/* 0C582C 7F090CFC C4700008 */  lwc1  $f16, 8($v1)
/* 0C5830 7F090D00 E4500000 */  swc1  $f16, ($v0)
/* 0C5834 7F090D04 C472000C */  lwc1  $f18, 0xc($v1)
/* 0C5838 7F090D08 E4520004 */  swc1  $f18, 4($v0)
/* 0C583C 7F090D0C C4640010 */  lwc1  $f4, 0x10($v1)
/* 0C5840 7F090D10 10000058 */  b     .L7F090E74
/* 0C5844 7F090D14 E4440008 */   swc1  $f4, 8($v0)
debug_chrkeypos:
/* 0C5848 7F090D18 0FC2406C */  jal   get_highlighted_debug_option
/* 0C584C 7F090D1C 00000000 */   nop   
/* 0C5850 7F090D20 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C5854 7F090D24 10000053 */  b     .L7F090E74
/* 0C5858 7F090D28 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_chrnum:
/* 0C585C 7F090D2C 3C028003 */  lui   $v0, %hi(debug_chrnum_flag)
/* 0C5860 7F090D30 24426FB8 */  addiu $v0, %lo(debug_chrnum_flag) # addiu $v0, $v0, 0x6fb8
/* 0C5864 7F090D34 8C490000 */  lw    $t1, ($v0)
/* 0C5868 7F090D38 392A0001 */  xori  $t2, $t1, 1
/* 0C586C 7F090D3C 1000004D */  b     .L7F090E74
/* 0C5870 7F090D40 AC4A0000 */   sw    $t2, ($v0)
debug_viscvg:
/* 0C5874 7F090D44 3C028003 */  lui   $v0, %hi(debug_VisCVG_flag)
/* 0C5878 7F090D48 24426FA8 */  addiu $v0, %lo(debug_VisCVG_flag) # addiu $v0, $v0, 0x6fa8
/* 0C587C 7F090D4C 8C4B0000 */  lw    $t3, ($v0)
/* 0C5880 7F090D50 396C0001 */  xori  $t4, $t3, 1
/* 0C5884 7F090D54 10000047 */  b     .L7F090E74
/* 0C5888 7F090D58 AC4C0000 */   sw    $t4, ($v0)
debug_joy2skyedit:
/* 0C588C 7F090D5C 3C028003 */  lui   $v0, %hi(debug_joy2skyedit_flag)
/* 0C5890 7F090D60 24426F98 */  addiu $v0, %lo(debug_joy2skyedit_flag) # addiu $v0, $v0, 0x6f98
/* 0C5894 7F090D64 8C4D0000 */  lw    $t5, ($v0)
/* 0C5898 7F090D68 39AE0001 */  xori  $t6, $t5, 1
/* 0C589C 7F090D6C 10000041 */  b     .L7F090E74
/* 0C58A0 7F090D70 AC4E0000 */   sw    $t6, ($v0)
debug_joy2hitsedit:
/* 0C58A4 7F090D74 3C028003 */  lui   $v0, %hi(debug_joy2hitsedit_flag)
/* 0C58A8 7F090D78 24426F9C */  addiu $v0, %lo(debug_joy2hitsedit_flag) # addiu $v0, $v0, 0x6f9c
/* 0C58AC 7F090D7C 8C4F0000 */  lw    $t7, ($v0)
/* 0C58B0 7F090D80 39F80001 */  xori  $t8, $t7, 1
/* 0C58B4 7F090D84 1000003B */  b     .L7F090E74
/* 0C58B8 7F090D88 AC580000 */   sw    $t8, ($v0)
debug_joy2detailedit:
/* 0C58BC 7F090D8C 3C028003 */  lui   $v0, %hi(debug_joy2detailedit_flag)
/* 0C58C0 7F090D90 24426FA0 */  addiu $v0, %lo(debug_joy2detailedit_flag) # addiu $v0, $v0, 0x6fa0
/* 0C58C4 7F090D94 8C590000 */  lw    $t9, ($v0)
/* 0C58C8 7F090D98 3B280001 */  xori  $t0, $t9, 1
/* 0C58CC 7F090D9C 10000035 */  b     .L7F090E74
/* 0C58D0 7F090DA0 AC480000 */   sw    $t0, ($v0)
debug_explosioninfo:
/* 0C58D4 7F090DA4 3C028003 */  lui   $v0, %hi(debug_explosioninfo_flag)
/* 0C58D8 7F090DA8 24426FA4 */  addiu $v0, %lo(debug_explosioninfo_flag) # addiu $v0, $v0, 0x6fa4
/* 0C58DC 7F090DAC 8C490000 */  lw    $t1, ($v0)
/* 0C58E0 7F090DB0 392A0001 */  xori  $t2, $t1, 1
/* 0C58E4 7F090DB4 1000002F */  b     .L7F090E74
/* 0C58E8 7F090DB8 AC4A0000 */   sw    $t2, ($v0)
debug_magicfog:
/* 0C58EC 7F090DBC 0FC2406C */  jal   get_highlighted_debug_option
/* 0C58F0 7F090DC0 00000000 */   nop   
/* 0C58F4 7F090DC4 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C58F8 7F090DC8 1000002A */  b     .L7F090E74
/* 0C58FC 7F090DCC AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_fog:
/* 0C5900 7F090DD0 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5904 7F090DD4 00000000 */   nop   
/* 0C5908 7F090DD8 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C590C 7F090DDC 10000025 */  b     .L7F090E74
/* 0C5910 7F090DE0 AC226F70 */   sw    $v0, %lo(debug_unknown)($at)
debug_gunwatchpos:
/* 0C5914 7F090DE4 3C028003 */  lui   $v0, %hi(debug_gunwatchpos_flags)
/* 0C5918 7F090DE8 24426FBC */  addiu $v0, %lo(debug_gunwatchpos_flags) # addiu $v0, $v0, 0x6fbc
/* 0C591C 7F090DEC 8C4B0000 */  lw    $t3, ($v0)
/* 0C5920 7F090DF0 396C0001 */  xori  $t4, $t3, 1
/* 0C5924 7F090DF4 1000001F */  b     .L7F090E74
/* 0C5928 7F090DF8 AC4C0000 */   sw    $t4, ($v0)
debug_roomblocks:
/* 0C592C 7F090DFC 0FC0F9A6 */  jal   removed_debug_roomblocks_feature
/* 0C5930 7F090E00 00000000 */   nop   
/* 0C5934 7F090E04 1000001C */  b     .L7F090E78
/* 0C5938 7F090E08 8FB80018 */   lw    $t8, 0x18($sp)
debug_profile:
/* 0C593C 7F090E0C 3C028003 */  lui   $v0, %hi(debug_profile_flag)
/* 0C5940 7F090E10 24426FC0 */  addiu $v0, %lo(debug_profile_flag) # addiu $v0, $v0, 0x6fc0
/* 0C5944 7F090E14 8C4D0000 */  lw    $t5, ($v0)
/* 0C5948 7F090E18 39AE0001 */  xori  $t6, $t5, 1
/* 0C594C 7F090E1C 11C00005 */  beqz  $t6, .L7F090E34
/* 0C5950 7F090E20 AC4E0000 */   sw    $t6, ($v0)
/* 0C5954 7F090E24 0FC24164 */  jal   unknown_libname_68
/* 0C5958 7F090E28 00000000 */   nop   
/* 0C595C 7F090E2C 10000012 */  b     .L7F090E78
/* 0C5960 7F090E30 8FB80018 */   lw    $t8, 0x18($sp)
.L7F090E34:
/* 0C5964 7F090E34 0FC24166 */  jal   nullsub_35
/* 0C5968 7F090E38 00000000 */   nop   
/* 0C596C 7F090E3C 1000000E */  b     .L7F090E78
/* 0C5970 7F090E40 8FB80018 */   lw    $t8, 0x18($sp)
debug_objload:
/* 0C5974 7F090E44 0FC00496 */  jal   debug_object_load_all_models
/* 0C5978 7F090E48 00000000 */   nop   
/* 0C597C 7F090E4C 1000000A */  b     .L7F090E78
/* 0C5980 7F090E50 8FB80018 */   lw    $t8, 0x18($sp)
debug_weaponload:
/* 0C5984 7F090E54 0FC00503 */  jal   debug_weapon_load_table
/* 0C5988 7F090E58 00000000 */   nop   
/* 0C598C 7F090E5C 10000006 */  b     .L7F090E78
/* 0C5990 7F090E60 8FB80018 */   lw    $t8, 0x18($sp)
debug_introedit:
/* 0C5994 7F090E64 0FC2406C */  jal   get_highlighted_debug_option
/* 0C5998 7F090E68 00000000 */   nop   
/* 0C599C 7F090E6C 3C018003 */  lui   $at, %hi(debug_unknown)
/* 0C59A0 7F090E70 AC226F70 */  sw    $v0, %lo(debug_unknown)($at)
def_7F090770:
.L7F090E74:
/* 0C59A4 7F090E74 8FB80018 */  lw    $t8, 0x18($sp)
.L7F090E78:
/* 0C59A8 7F090E78 33190003 */  andi  $t9, $t8, 3
/* 0C59AC 7F090E7C 5320000D */  beql  $t9, $zero, .L7F090EB4
/* 0C59B0 7F090E80 8FA90018 */   lw    $t1, 0x18($sp)
/* 0C59B4 7F090E84 0FC2406C */  jal   get_highlighted_debug_option
/* 0C59B8 7F090E88 00000000 */   nop   
/* 0C59BC 7F090E8C 2448FFCE */  addiu $t0, $v0, -0x32
/* 0C59C0 7F090E90 2D010005 */  sltiu $at, $t0, 5
/* 0C59C4 7F090E94 10200006 */  beqz  $at, .L7F090EB0
/* 0C59C8 7F090E98 00084080 */   sll   $t0, $t0, 2
/* 0C59CC 7F090E9C 3C018005 */  lui   $at, %hi(jpt_80055830)
/* 0C59D0 7F090EA0 00280821 */  addu  $at, $at, $t0
/* 0C59D4 7F090EA4 8C285830 */  lw    $t0, %lo(jpt_80055830)($at)
/* 0C59D8 7F090EA8 01000008 */  jr    $t0
/* 0C59DC 7F090EAC 00000000 */   nop   
def_7F090EA8:
.L7F090EB0:
/* 0C59E0 7F090EB0 8FA90018 */  lw    $t1, 0x18($sp)
.L7F090EB4:
/* 0C59E4 7F090EB4 3C0B8003 */  lui   $t3, %hi(show_debug_menu_flag) 
/* 0C59E8 7F090EB8 312A1000 */  andi  $t2, $t1, 0x1000
/* 0C59EC 7F090EBC 11400009 */  beqz  $t2, .L7F090EE4
/* 0C59F0 7F090EC0 00000000 */   nop   
/* 0C59F4 7F090EC4 8D6B6FF8 */  lw    $t3, %lo(show_debug_menu_flag)($t3)
/* 0C59F8 7F090EC8 24010001 */  li    $at, 1
/* 0C59FC 7F090ECC 15610003 */  bne   $t3, $at, .L7F090EDC
/* 0C5A00 7F090ED0 00000000 */   nop   
/* 0C5A04 7F090ED4 0C002BC0 */  jal   blank_debug_buffer_chars
/* 0C5A08 7F090ED8 00000000 */   nop   
.L7F090EDC:
/* 0C5A0C 7F090EDC 3C018003 */  lui   $at, %hi(show_debug_menu_flag)
/* 0C5A10 7F090EE0 AC206FF8 */  sw    $zero, %lo(show_debug_menu_flag)($at)
.L7F090EE4:
/* 0C5A14 7F090EE4 3C028003 */  lui   $v0, %hi(show_debug_menu_flag)
/* 0C5A18 7F090EE8 8C426FF8 */  lw    $v0, %lo(show_debug_menu_flag)($v0)
.L7F090EEC:
/* 0C5A1C 7F090EEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C5A20 7F090EF0 27BD0060 */  addiu $sp, $sp, 0x60
/* 0C5A24 7F090EF4 03E00008 */  jr    $ra
/* 0C5A28 7F090EF8 00000000 */   nop   
)
#endif

s32 get_debug_render_raster(void) {
    return debug_render_raster;
}

s32 get_debug_freeze_processing(void) {
    return debug_freeze_processing;
}

s32 get_debug_limit_controller_input(void) {
    return debug_limit_controller_input;
}

void set_debug_limit_controller_input(void) {
    debug_limit_controller_input = debug_unknown;
}

s32 get_memusage_display_flag(void) {
    return memusage_display_flag;
}

s32 get_debug_do_draw_bg(void) {
    return debug_do_draw_bg;
}

s32 get_debug_do_draw_obj(void) {
    return debug_do_draw_obj;
}

s32 get_debug_stanhit_flag(void) {
    return debug_stanhit_flag;
}

s32 get_debug_stanregion_flag(void) {
    return debug_stanregion_flag;
}

s32 get_turbo_mode_flag(void) {
    return turbo_mode_flag;
}

s32 get_debug_man_pos_flag(void) {
    return debug_man_pos_flag;
}

s32 get_debug_testingmanpos_flag(void) {
    return debug_testingmanpos_flag;
}

void set_debug_testingmanpos_flag(s32 flag) {
    debug_testingmanpos_flag = flag;
}

s32 get_debug_joy2skyedit_flag(void) {
    return debug_joy2skyedit_flag;
}

s32 get_debug_joy2hitsedit_flag(void) {
    return debug_joy2hitsedit_flag;
}

s32 get_debug_joy2detailedit_flag(void) {
    return debug_joy2detailedit_flag;
}

s32 get_debug_explosioninfo_flag(void) {
    return debug_explosioninfo_flag;
}

s32 get_debug_prroomloads_flag(void) {
    return debug_prroomloads_flag;
}

// Get Current Status of VisCVG (True/False)
s32 get_debug_VisCVG_flag(void) {
    return debug_VisCVG_flag;
}

// Set VisCVG (True/False)
void set_debug_VisCVG_flag(s32 flag) {
    debug_VisCVG_flag = flag;
}

s32 get_debug_007_unlock_flag(void) {
    return debug_007_unlock_flag;
}

s32 get_debug_enable_agent_levels_flag(void) {
    return debug_enable_agent_levels_flag;
}

s32 get_debug_enable_all_levels_flag(void) {
    return debug_enable_all_levels_flag;
}

s32 get_debug_fast_bond_flag(void) {
    return debug_fast_bond_flag;
}

void set_debug_fast_bond_flag(s32 flag) {
    debug_fast_bond_flag = flag;
}

s32 get_debug_all_obj_complete_flag(void) {
    return debug_all_obj_complete_flag;
}

s32 get_debug_portal_flag(void) {
    return debug_portal_flag;
}

s32 get_debug_chrnum_flag(void) {
    return debug_chrnum_flag;
}

s32 get_debug_gunwatchpos_flag(void) {
    return debug_gunwatchpos_flags;
}

s32  get_debug_profile_flag(void) {
    return debug_profile_flag;
}

s32 get_debug_taskgrab_val(void) {
    return debug_enable_taskgrab_flag;
}




