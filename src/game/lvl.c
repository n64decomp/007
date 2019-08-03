#include "ultra64.h"
#include "game/debugmenu_090490.h"
#include "game/lvl.h"
#include "game/initunk_0072B0.h"
#include "game/mainmenu.h"

// bss
//CODE.bss:8008C260
u32 *ptr_jfont_DL;
//CODE.bss:8008C264
s32 dword_CODE_bss_8008C264;
s32 dword_CODE_bss_8008C268;
s32 dword_CODE_bss_8008C26C;
//CODE.bss:8008C270
char ramrom_data_target[0x380];
//CODE.bss:8008C5F0
s32 record_slot_num;
//CODE.bss:8008C5F4
s32 *address_demo_loaded;
//CODE.bss:8008C5F8
s32 dword_CODE_bss_8008C5F8;


// data
//D:80048360
s32 lvl_c_debug_notice_list = 0;
//D:80048364
s32 current_stage_to_load = 0;
//D:80048368
f32 D_80048368 = 1.0;
//D:8004836C
s32 D_8004836C = 0;
//D:80048370
s32 controls_locked_flag = 0;
//D:80048374
s32 clock_timer = 0;
//D:80048378
s32 global_timer_delta = 0;
//D:8004837C
s32 global_timer = 0;
//D:80048380
s32 D_80048380 = 0;
//D:80048384
s32 difficulty_0 = 0;
//D:80048388
s32 D_80048388 = 0;
//D:8004838C
s32 D_8004838C = 0;
//D:80048390
s32 D_80048390 = 0;
//D:80048394
s32 D_80048394 = 0;
//D:80048398
s32 mp_time = 0x8CA0;
//D:8004839C
s32 mp_point = 0xA;
//D:800483A0
s32 D_800483A0 = 0;
//D:800483A4
f32 cur_mp_sec = 0.0;
//D:800483A8
s32 D_800483A8 = 0;
//D:800483AC
f32 cur_mp_min = 0.0;
//D:800483B0
s32 D_800483B0 = 0;
//D:800483B4
f32 stage_time_sec = 0;
//D:800483B8
s32 D_800483B8 = 0;
//D:800483BC
f32 poweron_time_sec = 0;
//D:800483C0
s32 D_800483C0 = 1;
//D:800483C4
s32 D_800483C4 = 0xFFFFFFFF;
//D:800483C8
s32 D_800483C8 = 0;
//D:800483CC
s32 D_800483CC = 0;
//D:800483D0
s32 D_800483D0 = 0;
//D:800483D4
s32 D_800483D4 = 0;
//D:800483D8
s32 D_800483D8 = 0;
//D:800483DC
s32 D_800483DC = 0;
//D:800483E0
s32 D_800483E0 = 0;
//D:800483E4
s32 D_800483E4 = 0;
//D:800483E8
//maybe alignment
s32 D_800483E8 = 0;
//D:800483EC
//maybe alignment
s32 D_800483EC = 0;



// rodata
//D:8005B6B0
const char aLv_c_debug[] = "lv_c_debug";
//D:8005B6BC
const char aStanshow_[] = "-stanshow_";
//D:8005B6C8
const char aStanshow__5[] = "-stanshow_";
//D:8005B6D4
const char aStanshow__0[] = "-stanshow_";
//D:8005B6E0
const char aStanshow__1[] = "-stanshow_";
//D:8005B6EC
const char aStanshow__2[] = "-stanshow_";
//D:8005B6F8
const char aStanshow__3[] = "-stanshow_";
//D:8005B704
const char aOneMinuteLeft[] = "One minute left";
//D:8005B714
const char aSetdetailDDDDDDDDD[] = "setdetail %d %d %d %d %d %d %d %d %d";







s32 sub_GAME_7F0BD8F0(void) {
    return D_800483C0;
}

void sub_GAME_7F0BD8FC(s32 arg0) {
    D_800483C0 = arg0;
}






#ifdef NONMATCHING
void something_with_lvl_c_debug(void) {
    s32 temp_a2;
    ? temp_ret;

    // Node 0
    get_ptr_debug_notice_list_entry(&lvl_c_debug_notice_list, &aLv_c_debug);
    temp_a2 = (&_jfontdlSegmentEnd - &_jfontdlSegmentStart);
    lvl_c_debug_notice_list = 1;
    temp_ret = allocate_bytes_in_bank(temp_a2, 6, temp_a2);
    ptr_jfont_DL = temp_ret;
    romCopy(temp_ret, &_jfontdlSegmentStart, sp18);
}

#else
GLOBAL_ASM(
.text
glabel something_with_lvl_c_debug
/* 0F2438 7F0BD908 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F243C 7F0BD90C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2440 7F0BD910 3C048005 */  lui   $a0, %hi(lvl_c_debug_notice_list) # $a0, 0x8005
/* 0F2444 7F0BD914 3C058006 */  lui   $a1, %hi(aLv_c_debug) # $a1, 0x8006
/* 0F2448 7F0BD918 24A5B6B0 */  addiu $a1, %lo(aLv_c_debug) # addiu $a1, $a1, -0x4950
/* 0F244C 7F0BD91C 0C001398 */  jal   get_ptr_debug_notice_list_entry
/* 0F2450 7F0BD920 24848360 */   addiu $a0, %lo(lvl_c_debug_notice_list) # addiu $a0, $a0, -0x7ca0
/* 0F2454 7F0BD924 3C0F0011 */  lui   $t7, %hi(_jfontdlSegmentEnd) # $t7, 0x11
/* 0F2458 7F0BD928 3C180011 */  lui   $t8, %hi(_jfontdlSegmentStart) # $t8, 0x11
/* 0F245C 7F0BD92C 27187880 */  addiu $t8, %lo(_jfontdlSegmentStart) # addiu $t8, $t8, 0x7880
/* 0F2460 7F0BD930 25EF7940 */  addiu $t7, %lo(_jfontdlSegmentEnd) # addiu $t7, $t7, 0x7940
/* 0F2464 7F0BD934 240E0001 */  li    $t6, 1
/* 0F2468 7F0BD938 3C018005 */  lui   $at, %hi(lvl_c_debug_notice_list) # $at, 0x8005
/* 0F246C 7F0BD93C 01F83023 */  subu  $a2, $t7, $t8
/* 0F2470 7F0BD940 AC2E8360 */  sw    $t6, %lo(lvl_c_debug_notice_list)($at)
/* 0F2474 7F0BD944 00C02025 */  move  $a0, $a2
/* 0F2478 7F0BD948 AFA60018 */  sw    $a2, 0x18($sp)
/* 0F247C 7F0BD94C 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F2480 7F0BD950 24050006 */   li    $a1, 6
/* 0F2484 7F0BD954 3C038009 */  lui   $v1, %hi(ptr_jfont_DL) # $v1, 0x8009
/* 0F2488 7F0BD958 2463C260 */  addiu $v1, %lo(ptr_jfont_DL) # addiu $v1, $v1, -0x3da0
/* 0F248C 7F0BD95C 3C050011 */  lui   $a1, %hi(_jfontdlSegmentStart) # $a1, 0x11
/* 0F2490 7F0BD960 AC620000 */  sw    $v0, ($v1)
/* 0F2494 7F0BD964 8FA60018 */  lw    $a2, 0x18($sp)
/* 0F2498 7F0BD968 24A57880 */  addiu $a1, %lo(_jfontdlSegmentStart) # addiu $a1, $a1, 0x7880
/* 0F249C 7F0BD96C 0C001707 */  jal   romCopy
/* 0F24A0 7F0BD970 00402025 */   move  $a0, $v0
/* 0F24A4 7F0BD974 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F24A8 7F0BD978 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F24AC 7F0BD97C 03E00008 */  jr    $ra
/* 0F24B0 7F0BD980 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD984(void) {
    s32 temp_a0;

    // Node 0
    temp_a0 = ((get_random_value() % 0x3dU) + 2);
    D_8004836C = temp_a0;
    return musicTrack1Play(temp_a0);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD984
/* 0F24B4 7F0BD984 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F24B8 7F0BD988 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F24BC 7F0BD98C 0C002914 */  jal   get_random_value
/* 0F24C0 7F0BD990 00000000 */   nop   
/* 0F24C4 7F0BD994 2401003D */  li    $at, 61
/* 0F24C8 7F0BD998 0041001B */  divu  $zero, $v0, $at
/* 0F24CC 7F0BD99C 00007010 */  mfhi  $t6
/* 0F24D0 7F0BD9A0 3C038005 */  lui   $v1, %hi(D_8004836C) # $v1, 0x8005
/* 0F24D4 7F0BD9A4 2463836C */  addiu $v1, %lo(D_8004836C) # addiu $v1, $v1, -0x7c94
/* 0F24D8 7F0BD9A8 25C40002 */  addiu $a0, $t6, 2
/* 0F24DC 7F0BD9AC 0C001B9F */  jal   musicTrack1Play
/* 0F24E0 7F0BD9B0 AC640000 */   sw    $a0, ($v1)
/* 0F24E4 7F0BD9B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F24E8 7F0BD9B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F24EC 7F0BD9BC 03E00008 */  jr    $ra
/* 0F24F0 7F0BD9C0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD9C4(s32 arg0) {
    // Node 0
    D_8004836C = arg0;
    return musicTrack1Play();
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD9C4
/* 0F24F4 7F0BD9C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F24F8 7F0BD9C8 3C028005 */  lui   $v0, %hi(D_8004836C) # $v0, 0x8005
/* 0F24FC 7F0BD9CC 2442836C */  addiu $v0, %lo(D_8004836C) # addiu $v0, $v0, -0x7c94
/* 0F2500 7F0BD9D0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2504 7F0BD9D4 0C001B9F */  jal   musicTrack1Play
/* 0F2508 7F0BD9D8 AC440000 */   sw    $a0, ($v0)
/* 0F250C 7F0BD9DC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F2510 7F0BD9E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F2514 7F0BD9E4 03E00008 */  jr    $ra
/* 0F2518 7F0BD9E8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD9EC(void) {
    s32 temp_hi;
    s32 phi_a0;

    // Node 0
    temp_hi = ((s32) (D_8004836C + 1) % 0x3f);
    D_8004836C = temp_hi;
    phi_a0 = temp_hi;
    if (temp_hi == 0)
    {
        // Node 1
        D_8004836C = 1;
        phi_a0 = 1;
    }
    // Node 2
    return musicTrack1Play(phi_a0);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD9EC
/* 0F251C 7F0BD9EC 3C028005 */  lui   $v0, %hi(D_8004836C) # $v0, 0x8005
/* 0F2520 7F0BD9F0 2442836C */  addiu $v0, %lo(D_8004836C) # addiu $v0, $v0, -0x7c94
/* 0F2524 7F0BD9F4 8C4E0000 */  lw    $t6, ($v0)
/* 0F2528 7F0BD9F8 2401003F */  li    $at, 63
/* 0F252C 7F0BD9FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F2530 7F0BDA00 25CF0001 */  addiu $t7, $t6, 1
/* 0F2534 7F0BDA04 01E1001A */  div   $zero, $t7, $at
/* 0F2538 7F0BDA08 00002010 */  mfhi  $a0
/* 0F253C 7F0BDA0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2540 7F0BDA10 14800003 */  bnez  $a0, .L7F0BDA20
/* 0F2544 7F0BDA14 AC440000 */   sw    $a0, ($v0)
/* 0F2548 7F0BDA18 24040001 */  li    $a0, 1
/* 0F254C 7F0BDA1C AC440000 */  sw    $a0, ($v0)
.L7F0BDA20:
/* 0F2550 7F0BDA20 0C001B9F */  jal   musicTrack1Play
/* 0F2554 7F0BDA24 00000000 */   nop   
/* 0F2558 7F0BDA28 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F255C 7F0BDA2C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F2560 7F0BDA30 03E00008 */  jr    $ra
/* 0F2564 7F0BDA34 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BDA38(void) {
    s32 temp_hi;
    s32 phi_a0;

    // Node 0
    temp_hi = ((s32) (D_8004836C + 0x3e) % 0x3f);
    D_8004836C = temp_hi;
    phi_a0 = temp_hi;
    if (temp_hi == 0)
    {
        // Node 1
        D_8004836C = 0x3e;
        phi_a0 = 0x3e;
    }
    // Node 2
    return musicTrack1Play(phi_a0);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BDA38
/* 0F2568 7F0BDA38 3C028005 */  lui   $v0, %hi(D_8004836C) # $v0, 0x8005
/* 0F256C 7F0BDA3C 2442836C */  addiu $v0, %lo(D_8004836C) # addiu $v0, $v0, -0x7c94
/* 0F2570 7F0BDA40 8C4E0000 */  lw    $t6, ($v0)
/* 0F2574 7F0BDA44 2401003F */  li    $at, 63
/* 0F2578 7F0BDA48 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F257C 7F0BDA4C 25CF003E */  addiu $t7, $t6, 0x3e
/* 0F2580 7F0BDA50 01E1001A */  div   $zero, $t7, $at
/* 0F2584 7F0BDA54 00002010 */  mfhi  $a0
/* 0F2588 7F0BDA58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F258C 7F0BDA5C 14800003 */  bnez  $a0, .L7F0BDA6C
/* 0F2590 7F0BDA60 AC440000 */   sw    $a0, ($v0)
/* 0F2594 7F0BDA64 2404003E */  li    $a0, 62
/* 0F2598 7F0BDA68 AC440000 */  sw    $a0, ($v0)
.L7F0BDA6C:
/* 0F259C 7F0BDA6C 0C001B9F */  jal   musicTrack1Play
/* 0F25A0 7F0BDA70 00000000 */   nop   
/* 0F25A4 7F0BDA74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F25A8 7F0BDA78 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F25AC 7F0BDA7C 03E00008 */  jr    $ra
/* 0F25B0 7F0BDA80 00000000 */   nop   
)
#endif





void sub_GAME_7F0BDA84(void) {
    sub_GAME_7F0BD9C4(sub_GAME_7F0D2720(current_stage_to_load));
}





#ifdef NONMATCHING
void stage_load(void) {

}
#else
GLOBAL_ASM(
.text
glabel stage_load
/* 0F25E0 7F0BDAB0 3C018005 */  lui   $at, %hi(current_stage_to_load) # $at, 0x8005
/* 0F25E4 7F0BDAB4 AC248364 */  sw    $a0, %lo(current_stage_to_load)($at)
/* 0F25E8 7F0BDAB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F25EC 7F0BDABC 44816000 */  mtc1  $at, $f12
/* 0F25F0 7F0BDAC0 24020001 */  li    $v0, 1
/* 0F25F4 7F0BDAC4 3C018005 */  lui   $at, %hi(D_800483C0) # $at, 0x8005
/* 0F25F8 7F0BDAC8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F25FC 7F0BDACC AC2283C0 */  sw    $v0, %lo(D_800483C0)($at)
/* 0F2600 7F0BDAD0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F2604 7F0BDAD4 3C018005 */  lui   $at, %hi(controls_locked_flag) # $at, 0x8005
/* 0F2608 7F0BDAD8 3C118005 */  lui   $s1, %hi(clock_timer) # $s1, 0x8005
/* 0F260C 7F0BDADC AC208370 */  sw    $zero, %lo(controls_locked_flag)($at)
/* 0F2610 7F0BDAE0 26318374 */  addiu $s1, %lo(clock_timer) # addiu $s1, $s1, -0x7c8c
/* 0F2614 7F0BDAE4 AE220000 */  sw    $v0, ($s1)
/* 0F2618 7F0BDAE8 3C018005 */  lui   $at, %hi(global_timer_delta) # $at, 0x8005
/* 0F261C 7F0BDAEC E42C8378 */  swc1  $f12, %lo(global_timer_delta)($at)
/* 0F2620 7F0BDAF0 3C018005 */  lui   $at, %hi(D_80048380) # $at, 0x8005
/* 0F2624 7F0BDAF4 AC208380 */  sw    $zero, %lo(D_80048380)($at)
/* 0F2628 7F0BDAF8 3C018005 */  lui   $at, %hi(global_timer) # $at, 0x8005
/* 0F262C 7F0BDAFC AC20837C */  sw    $zero, %lo(global_timer)($at)
/* 0F2630 7F0BDB00 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F2634 7F0BDB04 AC208388 */  sw    $zero, %lo(D_80048388)($at)
/* 0F2638 7F0BDB08 3C018005 */  lui   $at, %hi(D_8004838C) # $at, 0x8005
/* 0F263C 7F0BDB0C AC20838C */  sw    $zero, %lo(D_8004838C)($at)
/* 0F2640 7F0BDB10 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F2644 7F0BDB14 3C018005 */  lui   $at, %hi(D_80048390) # $at, 0x8005
/* 0F2648 7F0BDB18 44800000 */  mtc1  $zero, $f0
/* 0F264C 7F0BDB1C 3C108005 */  lui   $s0, %hi(D_80048394) # $s0, 0x8005
/* 0F2650 7F0BDB20 AC208390 */  sw    $zero, %lo(D_80048390)($at)
/* 0F2654 7F0BDB24 26108394 */  addiu $s0, %lo(D_80048394) # addiu $s0, $s0, -0x7c6c
/* 0F2658 7F0BDB28 AE000000 */  sw    $zero, ($s0)
/* 0F265C 7F0BDB2C 3C018005 */  lui   $at, %hi(cur_mp_sec) # $at, 0x8005
/* 0F2660 7F0BDB30 E42083A4 */  swc1  $f0, %lo(cur_mp_sec)($at)
/* 0F2664 7F0BDB34 3C018005 */  lui   $at, %hi(D_800483B0) # $at, 0x8005
/* 0F2668 7F0BDB38 AC2083B0 */  sw    $zero, %lo(D_800483B0)($at)
/* 0F266C 7F0BDB3C 3C018005 */  lui   $at, %hi(stage_time_sec) # $at, 0x8005
/* 0F2670 7F0BDB40 E42083B4 */  swc1  $f0, %lo(stage_time_sec)($at)
/* 0F2674 7F0BDB44 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F2678 7F0BDB48 3C018005 */  lui   $at, %hi(D_800483A0) # $at, 0x8005
/* 0F267C 7F0BDB4C AFB40030 */  sw    $s4, 0x30($sp)
/* 0F2680 7F0BDB50 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F2684 7F0BDB54 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F2688 7F0BDB58 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F268C 7F0BDB5C AFA40038 */  sw    $a0, 0x38($sp)
/* 0F2690 7F0BDB60 0C00248E */  jal   sfx_c_70009238
/* 0F2694 7F0BDB64 AC2083A0 */   sw    $zero, %lo(D_800483A0)($at)
/* 0F2698 7F0BDB68 0C001C0F */  jal   musicTrack1Vol
/* 0F269C 7F0BDB6C 24047FFF */   li    $a0, 32767
/* 0F26A0 7F0BDB70 0C001CF1 */  jal   musicTrack2Vol
/* 0F26A4 7F0BDB74 24047FFF */   li    $a0, 32767
/* 0F26A8 7F0BDB78 0C001DD3 */  jal   musicTrack3Vol
/* 0F26AC 7F0BDB7C 24047FFF */   li    $a0, 32767
/* 0F26B0 7F0BDB80 0FC304D9 */  jal   sub_GAME_7F0C1364
/* 0F26B4 7F0BDB84 00000000 */   nop   
/* 0F26B8 7F0BDB88 0FC0154D */  jal   set_contents_of_80036078
/* 0F26BC 7F0BDB8C 24040001 */   li    $a0, 1
/* 0F26C0 7F0BDB90 0FC01CC8 */  jal   set_mt_tex_alloc
/* 0F26C4 7F0BDB94 00000000 */   nop   
/* 0F26C8 7F0BDB98 0FC291F5 */  jal   sub_GAME_7F0A47D4
/* 0F26CC 7F0BDB9C 00000000 */   nop   
/* 0F26D0 7F0BDBA0 0FC32FEC */  jal   load_prepare_global_image_bank
/* 0F26D4 7F0BDBA4 00000000 */   nop   
/* 0F26D8 7F0BDBA8 0FC2B2EB */  jal   load_font_tables
/* 0F26DC 7F0BDBAC 00000000 */   nop   
/* 0F26E0 7F0BDBB0 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0F26E4 7F0BDBB4 2401005A */  li    $at, 90
/* 0F26E8 7F0BDBB8 15E10005 */  bne   $t7, $at, .L7F0BDBD0
/* 0F26EC 7F0BDBBC 00000000 */   nop   
/* 0F26F0 7F0BDBC0 0FC00348 */  jal   init_menus_or_reset
/* 0F26F4 7F0BDBC4 00000000 */   nop   
/* 0F26F8 7F0BDBC8 10000073 */  b     .L7F0BDD98
/* 0F26FC 7F0BDBCC 00000000 */   nop   
.L7F0BDBD0:
/* 0F2700 7F0BDBD0 3C048005 */  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
/* 0F2704 7F0BDBD4 8C848364 */  lw    $a0, %lo(current_stage_to_load)($a0)
/* 0F2708 7F0BDBD8 3C018007 */  lui    $at, %hi(newcheatunlocked) # -0.000000
/* 0F270C 7F0BDBDC AC209790 */  sw    $zero, %lo(newcheatunlocked)($at)
/* 0F2710 7F0BDBE0 2401005A */  li    $at, 90
/* 0F2714 7F0BDBE4 1081001C */  beq   $a0, $at, .L7F0BDC58
/* 0F2718 7F0BDBE8 00000000 */   nop   
/* 0F271C 7F0BDBEC 8E180000 */  lw    $t8, ($s0)
/* 0F2720 7F0BDBF0 17000019 */  bnez  $t8, .L7F0BDC58
/* 0F2724 7F0BDBF4 00000000 */   nop   
/* 0F2728 7F0BDBF8 8E390000 */  lw    $t9, ($s1)
/* 0F272C 7F0BDBFC 3C088003 */  lui   $t0, %hi(append_cheat_sp) # $t0, 0x8003
/* 0F2730 7F0BDC00 1B200015 */  blez  $t9, .L7F0BDC58
/* 0F2734 7F0BDC04 00000000 */   nop   
/* 0F2738 7F0BDC08 8D08A900 */  lw    $t0, %lo(append_cheat_sp)($t0)
/* 0F273C 7F0BDC0C 3C118007 */  lui   $s1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS) # $s1, 0x8007
/* 0F2740 7F0BDC10 263196A1 */  addiu $s1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $s1, $s1, -0x695f
/* 0F2744 7F0BDC14 11000010 */  beqz  $t0, .L7F0BDC58
/* 0F2748 7F0BDC18 24100001 */   li    $s0, 1
/* 0F274C 7F0BDC1C 2412004B */  li    $s2, 75
.L7F0BDC20:
/* 0F2750 7F0BDC20 92290000 */  lbu   $t1, ($s1)
/* 0F2754 7F0BDC24 51200008 */  beql  $t1, $zero, .L7F0BDC48
/* 0F2758 7F0BDC28 26100001 */   addiu $s0, $s0, 1
/* 0F275C 7F0BDC2C 0FC24697 */  jal   sub_GAME_7F091A5C
/* 0F2760 7F0BDC30 02002025 */   move  $a0, $s0
/* 0F2764 7F0BDC34 50400004 */  beql  $v0, $zero, .L7F0BDC48
/* 0F2768 7F0BDC38 26100001 */   addiu $s0, $s0, 1
/* 0F276C 7F0BDC3C 0FC246AB */  jal   sub_GAME_7F091AAC
/* 0F2770 7F0BDC40 02002025 */   move  $a0, $s0
/* 0F2774 7F0BDC44 26100001 */  addiu $s0, $s0, 1
.L7F0BDC48:
/* 0F2778 7F0BDC48 1612FFF5 */  bne   $s0, $s2, .L7F0BDC20
/* 0F277C 7F0BDC4C 26310001 */   addiu $s1, $s1, 1
/* 0F2780 7F0BDC50 3C048005 */  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
/* 0F2784 7F0BDC54 8C848364 */  lw    $a0, %lo(current_stage_to_load)($a0)
.L7F0BDC58:
/* 0F2788 7F0BDC58 0FC2D049 */  jal   sub_GAME_7F0B4124
/* 0F278C 7F0BDC5C 00000000 */   nop   
/* 0F2790 7F0BDC60 3C048005 */  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
/* 0F2794 7F0BDC64 0FC2510B */  jal   sub_GAME_7F09442C
/* 0F2798 7F0BDC68 8C848364 */   lw    $a0, %lo(current_stage_to_load)($a0)
/* 0F279C 7F0BDC6C 0FC2921A */  jal   init_watch_at_start_of_stage
/* 0F27A0 7F0BDC70 00000000 */   nop   
/* 0F27A4 7F0BDC74 0FC3047F */  jal   sub_GAME_7F0C11FC
/* 0F27A8 7F0BDC78 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F27AC 7F0BDC7C 3C0A8008 */  lui   $t2, %hi(player1_player_data)
/* 0F27B0 7F0BDC80 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0F27B4 7F0BDC84 25529EF0 */  addiu $s2, $t2, %lo(player1_player_data)
/* 0F27B8 7F0BDC88 4481A000 */  mtc1  $at, $f20
/* 0F27BC 7F0BDC8C 0240A025 */  move  $s4, $s2
/* 0F27C0 7F0BDC90 24130004 */  li    $s3, 4
.L7F0BDC94:
/* 0F27C4 7F0BDC94 0FC26919 */  jal   get_num_players
/* 0F27C8 7F0BDC98 00000000 */   nop   
/* 0F27CC 7F0BDC9C 24010001 */  li    $at, 1
/* 0F27D0 7F0BDCA0 14410009 */  bne   $v0, $at, .L7F0BDCC8
/* 0F27D4 7F0BDCA4 00008025 */   move  $s0, $zero
/* 0F27D8 7F0BDCA8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F27DC 7F0BDCAC 44812000 */  mtc1  $at, $f4
/* 0F27E0 7F0BDCB0 44813000 */  mtc1  $at, $f6
/* 0F27E4 7F0BDCB4 A280006A */  sb    $zero, 0x6a($s4)
/* 0F27E8 7F0BDCB8 A280006B */  sb    $zero, 0x6b($s4)
/* 0F27EC 7F0BDCBC E684005C */  swc1  $f4, 0x5c($s4)
/* 0F27F0 7F0BDCC0 1000001C */  b     .L7F0BDD34
/* 0F27F4 7F0BDCC4 E6860064 */   swc1  $f6, 0x64($s4)
.L7F0BDCC8:
/* 0F27F8 7F0BDCC8 3C118008 */  lui   $s1, %hi(player1_player_data) # $s1, 0x8008
/* 0F27FC 7F0BDCCC 26319EF0 */  addiu $s1, %lo(player1_player_data) # addiu $s1, $s1, -0x6110
.L7F0BDCD0:
/* 0F2800 7F0BDCD0 0FC051D6 */  jal   get_scenario
/* 0F2804 7F0BDCD4 00000000 */   nop   
/* 0F2808 7F0BDCD8 14530003 */  bne   $v0, $s3, .L7F0BDCE8
/* 0F280C 7F0BDCDC 00000000 */   nop   
/* 0F2810 7F0BDCE0 10000004 */  b     .L7F0BDCF4
/* 0F2814 7F0BDCE4 E634005C */   swc1  $f20, 0x5c($s1)
.L7F0BDCE8:
/* 0F2818 7F0BDCE8 0FC040EB */  jal   get_player_mp_handicap
/* 0F281C 7F0BDCEC 02002025 */   move  $a0, $s0
/* 0F2820 7F0BDCF0 E620005C */  swc1  $f0, 0x5c($s1)
.L7F0BDCF4:
/* 0F2824 7F0BDCF4 0FC040F4 */  jal   get_player_mp_char_height
/* 0F2828 7F0BDCF8 02002025 */   move  $a0, $s0
/* 0F282C 7F0BDCFC 26100001 */  addiu $s0, $s0, 1
/* 0F2830 7F0BDD00 26310070 */  addiu $s1, $s1, 0x70
/* 0F2834 7F0BDD04 1613FFF2 */  bne   $s0, $s3, .L7F0BDCD0
/* 0F2838 7F0BDD08 E620FFF4 */   swc1  $f0, -0xc($s1)
/* 0F283C 7F0BDD0C 0FC04108 */  jal   get_mp_timelimit
/* 0F2840 7F0BDD10 00000000 */   nop   
/* 0F2844 7F0BDD14 0FC2FF0A */  jal   set_mp_time
/* 0F2848 7F0BDD18 00402025 */   move  $a0, $v0
/* 0F284C 7F0BDD1C 0FC04111 */  jal   get_mp_pointlimit
/* 0F2850 7F0BDD20 00000000 */   nop   
/* 0F2854 7F0BDD24 0FC2FF0D */  jal   set_mp_point
/* 0F2858 7F0BDD28 00402025 */   move  $a0, $v0
/* 0F285C 7F0BDD2C 0FC04076 */  jal   copy_aim_settings_to_playerdata
/* 0F2860 7F0BDD30 00000000 */   nop   
.L7F0BDD34:
/* 0F2864 7F0BDD34 44804000 */  mtc1  $zero, $f8
/* 0F2868 7F0BDD38 44805000 */  mtc1  $zero, $f10
/* 0F286C 7F0BDD3C 3C027FFF */  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
/* 0F2870 7F0BDD40 3442FFFF */  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
/* 0F2874 7F0BDD44 AE800034 */  sw    $zero, 0x34($s4)
/* 0F2878 7F0BDD48 AE80003C */  sw    $zero, 0x3c($s4)
/* 0F287C 7F0BDD4C AE820044 */  sw    $v0, 0x44($s4)
/* 0F2880 7F0BDD50 AE800048 */  sw    $zero, 0x48($s4)
/* 0F2884 7F0BDD54 AE800054 */  sw    $zero, 0x54($s4)
/* 0F2888 7F0BDD58 AE800058 */  sw    $zero, 0x58($s4)
/* 0F288C 7F0BDD5C AE80004C */  sw    $zero, 0x4c($s4)
/* 0F2890 7F0BDD60 AE820050 */  sw    $v0, 0x50($s4)
/* 0F2894 7F0BDD64 A2800068 */  sb    $zero, 0x68($s4)
/* 0F2898 7F0BDD68 AE800060 */  sw    $zero, 0x60($s4)
/* 0F289C 7F0BDD6C E6880038 */  swc1  $f8, 0x38($s4)
/* 0F28A0 7F0BDD70 E68A0040 */  swc1  $f10, 0x40($s4)
/* 0F28A4 7F0BDD74 3C0B8008 */  lui   $t3, %hi(ptr_BONDdata) # $t3, 0x8008
/* 0F28A8 7F0BDD78 256BA0B0 */  addiu $t3, %lo(ptr_BONDdata) # addiu $t3, $t3, -0x5f50
/* 0F28AC 7F0BDD7C 26520070 */  addiu $s2, $s2, 0x70
/* 0F28B0 7F0BDD80 26940070 */  addiu $s4, $s4, 0x70
/* 0F28B4 7F0BDD84 AE40FFC0 */  sw    $zero, -0x40($s2)
/* 0F28B8 7F0BDD88 AE40FFBC */  sw    $zero, -0x44($s2)
/* 0F28BC 7F0BDD8C AE40FFB8 */  sw    $zero, -0x48($s2)
/* 0F28C0 7F0BDD90 164BFFC0 */  bne   $s2, $t3, .L7F0BDC94
/* 0F28C4 7F0BDD94 AE40FFB4 */   sw    $zero, -0x4c($s2)
.L7F0BDD98:
/* 0F28C8 7F0BDD98 0FC013B0 */  jal   something_with_stage_objectives
/* 0F28CC 7F0BDD9C 00000000 */   nop   
/* 0F28D0 7F0BDDA0 0FC30802 */  jal   unpause_game
/* 0F28D4 7F0BDDA4 00000000 */   nop   
/* 0F28D8 7F0BDDA8 0FC26E08 */  jal   sub_GAME_7F09B820
/* 0F28DC 7F0BDDAC 00000000 */   nop   
/* 0F28E0 7F0BDDB0 0FC01514 */  jal   sub_GAME_7F005450
/* 0F28E4 7F0BDDB4 00000000 */   nop   
/* 0F28E8 7F0BDDB8 0FC01548 */  jal   zero_contents_of_80036070_74
/* 0F28EC 7F0BDDBC 00000000 */   nop   
/* 0F28F0 7F0BDDC0 0FC00538 */  jal   init_load_objpos_table
/* 0F28F4 7F0BDDC4 00000000 */   nop   
/* 0F28F8 7F0BDDC8 0FC005D4 */  jal   reinit_between_menus
/* 0F28FC 7F0BDDCC 00000000 */   nop   
/* 0F2900 7F0BDDD0 0FC0052C */  jal   init_sound_effects_registers
/* 0F2904 7F0BDDD4 00000000 */   nop   
/* 0F2908 7F0BDDD8 0FC00390 */  jal   init_guards
/* 0F290C 7F0BDDDC 00000000 */   nop   
/* 0F2910 7F0BDDE0 0FC003D4 */  jal   set_new_rand_head_bodies
/* 0F2914 7F0BDDE4 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F2918 7F0BDDE8 0FC00EFC */  jal   stage_loading_setup_objparse_cleanupafter
/* 0F291C 7F0BDDEC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F2920 7F0BDDF0 0FC01B64 */  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
/* 0F2924 7F0BDDF4 00000000 */   nop   
/* 0F2928 7F0BDDF8 0FC01C60 */  jal   sub_GAME_7F007180
/* 0F292C 7F0BDDFC 00000000 */   nop   
/* 0F2930 7F0BDE00 0FC01CA4 */  jal   sub_GAME_7F007290
/* 0F2934 7F0BDE04 00000000 */   nop   
/* 0F2938 7F0BDE08 0FC01CAC */  jal   sub_GAME_7F0072B0
/* 0F293C 7F0BDE0C 00000000 */   nop   
/* 0F2940 7F0BDE10 3C0C8005 */  lui   $t4, %hi(current_stage_to_load) # $t4, 0x8005
/* 0F2944 7F0BDE14 8D8C8364 */  lw    $t4, %lo(current_stage_to_load)($t4)
/* 0F2948 7F0BDE18 2401005A */  li    $at, 90
/* 0F294C 7F0BDE1C 15810005 */  bne   $t4, $at, .L7F0BDE34
/* 0F2950 7F0BDE20 00000000 */   nop   
/* 0F2954 7F0BDE24 0FC01CBE */  jal   disable_onscreen_cheat_text
/* 0F2958 7F0BDE28 00000000 */   nop   
/* 0F295C 7F0BDE2C 10000020 */  b     .L7F0BDEB0
/* 0F2960 7F0BDE30 00000000 */   nop   
.L7F0BDE34:
/* 0F2964 7F0BDE34 0FC01A24 */  jal   init_path_table_links
/* 0F2968 7F0BDE38 00000000 */   nop   
/* 0F296C 7F0BDE3C 0FC01410 */  jal   something_with_ejected_cartridges
/* 0F2970 7F0BDE40 00000000 */   nop   
/* 0F2974 7F0BDE44 0FC26919 */  jal   get_num_players
/* 0F2978 7F0BDE48 00008025 */   move  $s0, $zero
/* 0F297C 7F0BDE4C 18400016 */  blez  $v0, .L7F0BDEA8
/* 0F2980 7F0BDE50 00000000 */   nop   
.L7F0BDE54:
/* 0F2984 7F0BDE54 0FC26C43 */  jal   set_cur_player
/* 0F2988 7F0BDE58 02002025 */   move  $a0, $s0
/* 0F298C 7F0BDE5C 0FC0187C */  jal   sub_GAME_7F0061F0
/* 0F2990 7F0BDE60 00000000 */   nop   
/* 0F2994 7F0BDE64 0FC01434 */  jal   init_player_BONDdata_stats
/* 0F2998 7F0BDE68 00000000 */   nop   
/* 0F299C 7F0BDE6C 0FC1E4FB */  jal   init_player_BONDdata
/* 0F29A0 7F0BDE70 00000000 */   nop   
/* 0F29A4 7F0BDE74 0FC015F1 */  jal   load_camera_intro_type_values
/* 0F29A8 7F0BDE78 00000000 */   nop   
/* 0F29AC 7F0BDE7C 0FC1E62E */  jal   sub_GAME_7F0798B8
/* 0F29B0 7F0BDE80 00000000 */   nop   
/* 0F29B4 7F0BDE84 0FC018E3 */  jal   sets_a_bunch_of_BONDdata_values_to_default
/* 0F29B8 7F0BDE88 00000000 */   nop   
/* 0F29BC 7F0BDE8C 0FC01CBE */  jal   disable_onscreen_cheat_text
/* 0F29C0 7F0BDE90 00000000 */   nop   
/* 0F29C4 7F0BDE94 0FC26919 */  jal   get_num_players
/* 0F29C8 7F0BDE98 26100001 */   addiu $s0, $s0, 1
/* 0F29CC 7F0BDE9C 0202082A */  slt   $at, $s0, $v0
/* 0F29D0 7F0BDEA0 1420FFEC */  bnez  $at, .L7F0BDE54
/* 0F29D4 7F0BDEA4 00000000 */   nop   
.L7F0BDEA8:
/* 0F29D8 7F0BDEA8 0FC26C43 */  jal   set_cur_player
/* 0F29DC 7F0BDEAC 00002025 */   move  $a0, $zero
.L7F0BDEB0:
/* 0F29E0 7F0BDEB0 0FC0154D */  jal   set_contents_of_80036078
/* 0F29E4 7F0BDEB4 00002025 */   move  $a0, $zero
/* 0F29E8 7F0BDEB8 0FC348E0 */  jal   remove_viewport_buffer
/* 0F29EC 7F0BDEBC 00000000 */   nop   
/* 0F29F0 7F0BDEC0 0C000EEC */  jal   setVideoWidthHeightToMode
/* 0F29F4 7F0BDEC4 24040001 */   li    $a0, 1
/* 0F29F8 7F0BDEC8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F29FC 7F0BDECC 44818000 */  mtc1  $at, $f16
/* 0F2A00 7F0BDED0 3C018005 */  lui   $at, %hi(D_80048368) # $at, 0x8005
/* 0F2A04 7F0BDED4 00002025 */  move  $a0, $zero
/* 0F2A08 7F0BDED8 0FC2FEFE */  jal   set_controls_locked_flag
/* 0F2A0C 7F0BDEDC E4308368 */   swc1  $f16, %lo(D_80048368)($at)
/* 0F2A10 7F0BDEE0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F2A14 7F0BDEE4 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F2A18 7F0BDEE8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F2A1C 7F0BDEEC 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F2A20 7F0BDEF0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F2A24 7F0BDEF4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F2A28 7F0BDEF8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F2A2C 7F0BDEFC 03E00008 */  jr    $ra
/* 0F2A30 7F0BDF00 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





s32 sub_GAME_7F0BDF04(void) {
    return current_stage_to_load;
}





#ifdef NONMATCHING
void sub_GAME_7F0BDF10(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BDF10
/* 0F2A40 7F0BDF10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F2A44 7F0BDF14 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2A48 7F0BDF18 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F2A4C 7F0BDF1C 1080003B */  beqz  $a0, .L7F0BE00C
/* 0F2A50 7F0BDF20 AFA00020 */   sw    $zero, 0x20($sp)
/* 0F2A54 7F0BDF24 3C058005 */  lui   $a1, %hi(D_800483CC) # $a1, 0x8005
/* 0F2A58 7F0BDF28 8CA583CC */  lw    $a1, %lo(D_800483CC)($a1)
/* 0F2A5C 7F0BDF2C 0FC2E779 */  jal   sub_GAME_7F0B9DE4
/* 0F2A60 7F0BDF30 2406FFFF */   li    $a2, -1
/* 0F2A64 7F0BDF34 3C0E8005 */  lui   $t6, %hi(D_800483D4) # $t6, 0x8005
/* 0F2A68 7F0BDF38 8DCE83D4 */  lw    $t6, %lo(D_800483D4)($t6)
/* 0F2A6C 7F0BDF3C 3C0F8005 */  lui   $t7, %hi(D_800483D8) # $t7, 0x8005
/* 0F2A70 7F0BDF40 8DEF83D8 */  lw    $t7, %lo(D_800483D8)($t7)
/* 0F2A74 7F0BDF44 3C018005 */  lui   $at, %hi(D_800483D0) # $at, 0x8005
/* 0F2A78 7F0BDF48 3C188005 */  lui   $t8, %hi(D_800483DC) # $t8, 0x8005
/* 0F2A7C 7F0BDF4C AC2E83D0 */  sw    $t6, %lo(D_800483D0)($at)
/* 0F2A80 7F0BDF50 8F1883DC */  lw    $t8, %lo(D_800483DC)($t8)
/* 0F2A84 7F0BDF54 3C018005 */  lui   $at, %hi(D_800483D4) # $at, 0x8005
/* 0F2A88 7F0BDF58 AC2F83D4 */  sw    $t7, %lo(D_800483D4)($at)
/* 0F2A8C 7F0BDF5C 3C038005 */  lui   $v1, %hi(D_800483E0) # $v1, 0x8005
/* 0F2A90 7F0BDF60 3C018005 */  lui   $at, %hi(D_800483D8) # $at, 0x8005
/* 0F2A94 7F0BDF64 8C6383E0 */  lw    $v1, %lo(D_800483E0)($v1)
/* 0F2A98 7F0BDF68 AC3883D8 */  sw    $t8, %lo(D_800483D8)($at)
/* 0F2A9C 7F0BDF6C 3C018005 */  lui   $at, %hi(D_800483DC) # $at, 0x8005
/* 0F2AA0 7F0BDF70 AFA20028 */  sw    $v0, 0x28($sp)
/* 0F2AA4 7F0BDF74 00002025 */  move  $a0, $zero
/* 0F2AA8 7F0BDF78 34058000 */  li    $a1, 32768
/* 0F2AAC 7F0BDF7C 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2AB0 7F0BDF80 AC2383DC */   sw    $v1, %lo(D_800483DC)($at)
/* 0F2AB4 7F0BDF84 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2AB8 7F0BDF88 24040001 */  li    $a0, 1
/* 0F2ABC 7F0BDF8C 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2AC0 7F0BDF90 34058000 */   li    $a1, 32768
/* 0F2AC4 7F0BDF94 3C198005 */  lui   $t9, %hi(D_800483DC) # $t9, 0x8005
/* 0F2AC8 7F0BDF98 8F3983DC */  lw    $t9, %lo(D_800483DC)($t9)
/* 0F2ACC 7F0BDF9C 00501825 */  or    $v1, $v0, $s0
/* 0F2AD0 7F0BDFA0 3C0B8005 */  lui   $t3, %hi(D_800483D0) # $t3, 0x8005
/* 0F2AD4 7F0BDFA4 13230006 */  beq   $t9, $v1, .L7F0BDFC0
/* 0F2AD8 7F0BDFA8 3C0C8005 */   lui   $t4, %hi(D_800483D4) # $t4, 0x8005
/* 0F2ADC 7F0BDFAC 3C028005 */  lui   $v0, %hi(D_800483C0) # $v0, 0x8005
/* 0F2AE0 7F0BDFB0 244283C0 */  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
/* 0F2AE4 7F0BDFB4 8C490000 */  lw    $t1, ($v0)
/* 0F2AE8 7F0BDFB8 392A0001 */  xori  $t2, $t1, 1
/* 0F2AEC 7F0BDFBC AC4A0000 */  sw    $t2, ($v0)
.L7F0BDFC0:
/* 0F2AF0 7F0BDFC0 8D6B83D0 */  lw    $t3, %lo(D_800483D0)($t3)
/* 0F2AF4 7F0BDFC4 8D8C83D4 */  lw    $t4, %lo(D_800483D4)($t4)
/* 0F2AF8 7F0BDFC8 3C028005 */  lui   $v0, %hi(D_800483C0) # $v0, 0x8005
/* 0F2AFC 7F0BDFCC 244283C0 */  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
/* 0F2B00 7F0BDFD0 116C0004 */  beq   $t3, $t4, .L7F0BDFE4
/* 0F2B04 7F0BDFD4 3C018005 */   lui   $at, %hi(D_800483E0) # $at, 0x8005
/* 0F2B08 7F0BDFD8 8C4E0000 */  lw    $t6, ($v0)
/* 0F2B0C 7F0BDFDC 39CF0001 */  xori  $t7, $t6, 1
/* 0F2B10 7F0BDFE0 AC4F0000 */  sw    $t7, ($v0)
.L7F0BDFE4:
/* 0F2B14 7F0BDFE4 10600004 */  beqz  $v1, .L7F0BDFF8
/* 0F2B18 7F0BDFE8 AC2383E0 */   sw    $v1, %lo(D_800483E0)($at)
/* 0F2B1C 7F0BDFEC 3C048005 */  lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2B20 7F0BDFF0 10000002 */  b     .L7F0BDFFC
/* 0F2B24 7F0BDFF4 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BDFF8:
/* 0F2B28 7F0BDFF8 2404FFFF */  li    $a0, -1
.L7F0BDFFC:
/* 0F2B2C 7F0BDFFC 0FC2E77D */  jal   sub_GAME_7F0B9DF4
/* 0F2B30 7F0BE000 00000000 */   nop   
/* 0F2B34 7F0BE004 100000BC */  b     .L7F0BE2F8
/* 0F2B38 7F0BE008 8FA20028 */   lw    $v0, 0x28($sp)
.L7F0BE00C:
/* 0F2B3C 7F0BE00C 00002025 */  move  $a0, $zero
/* 0F2B40 7F0BE010 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2B44 7F0BE014 24050200 */   li    $a1, 512
/* 0F2B48 7F0BE018 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2B4C 7F0BE01C 24040001 */  li    $a0, 1
/* 0F2B50 7F0BE020 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2B54 7F0BE024 24050200 */   li    $a1, 512
/* 0F2B58 7F0BE028 0050C025 */  or    $t8, $v0, $s0
/* 0F2B5C 7F0BE02C 1300000B */  beqz  $t8, .L7F0BE05C
/* 0F2B60 7F0BE030 24050100 */   li    $a1, 256
/* 0F2B64 7F0BE034 3C048005 */  lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2B68 7F0BE038 8C8483CC */  lw    $a0, %lo(D_800483CC)($a0)
/* 0F2B6C 7F0BE03C 24190001 */  li    $t9, 1
/* 0F2B70 7F0BE040 3C018005 */  lui   $at, %hi(D_800483CC) # $at, 0x8005
/* 0F2B74 7F0BE044 2484FFFF */  addiu $a0, $a0, -1
/* 0F2B78 7F0BE048 AC2483CC */  sw    $a0, %lo(D_800483CC)($at)
/* 0F2B7C 7F0BE04C 04810003 */  bgez  $a0, .L7F0BE05C
/* 0F2B80 7F0BE050 AFB90020 */   sw    $t9, 0x20($sp)
/* 0F2B84 7F0BE054 3C018005 */  lui   $at, %hi(D_800483CC) # $at, 0x8005
/* 0F2B88 7F0BE058 AC2083CC */  sw    $zero, %lo(D_800483CC)($at)
.L7F0BE05C:
/* 0F2B8C 7F0BE05C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2B90 7F0BE060 00002025 */   move  $a0, $zero
/* 0F2B94 7F0BE064 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2B98 7F0BE068 24040001 */  li    $a0, 1
/* 0F2B9C 7F0BE06C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2BA0 7F0BE070 24050100 */   li    $a1, 256
/* 0F2BA4 7F0BE074 00504025 */  or    $t0, $v0, $s0
/* 0F2BA8 7F0BE078 11000008 */  beqz  $t0, .L7F0BE09C
/* 0F2BAC 7F0BE07C 24050010 */   li    $a1, 16
/* 0F2BB0 7F0BE080 3C048005 */  lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2BB4 7F0BE084 8C8483CC */  lw    $a0, %lo(D_800483CC)($a0)
/* 0F2BB8 7F0BE088 24090001 */  li    $t1, 1
/* 0F2BBC 7F0BE08C 3C018005 */  lui   $at, %hi(D_800483CC) # $at, 0x8005
/* 0F2BC0 7F0BE090 24840001 */  addiu $a0, $a0, 1
/* 0F2BC4 7F0BE094 AC2483CC */  sw    $a0, %lo(D_800483CC)($at)
/* 0F2BC8 7F0BE098 AFA90020 */  sw    $t1, 0x20($sp)
.L7F0BE09C:
/* 0F2BCC 7F0BE09C 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2BD0 7F0BE0A0 00002025 */   move  $a0, $zero
/* 0F2BD4 7F0BE0A4 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2BD8 7F0BE0A8 24040001 */  li    $a0, 1
/* 0F2BDC 7F0BE0AC 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2BE0 7F0BE0B0 24050010 */   li    $a1, 16
/* 0F2BE4 7F0BE0B4 00505025 */  or    $t2, $v0, $s0
/* 0F2BE8 7F0BE0B8 11400012 */  beqz  $t2, .L7F0BE104
/* 0F2BEC 7F0BE0BC 00002025 */   move  $a0, $zero
/* 0F2BF0 7F0BE0C0 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2BF4 7F0BE0C4 24050020 */   li    $a1, 32
/* 0F2BF8 7F0BE0C8 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2BFC 7F0BE0CC 24040001 */  li    $a0, 1
/* 0F2C00 7F0BE0D0 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2C04 7F0BE0D4 24050020 */   li    $a1, 32
/* 0F2C08 7F0BE0D8 00505825 */  or    $t3, $v0, $s0
/* 0F2C0C 7F0BE0DC 11600009 */  beqz  $t3, .L7F0BE104
/* 0F2C10 7F0BE0E0 00002025 */   move  $a0, $zero
/* 0F2C14 7F0BE0E4 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2C18 7F0BE0E8 24050400 */   li    $a1, 1024
/* 0F2C1C 7F0BE0EC 10400081 */  beqz  $v0, .L7F0BE2F4
/* 0F2C20 7F0BE0F0 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2C24 7F0BE0F4 0FC2E6D9 */  jal   sub_GAME_7F0B9B64
/* 0F2C28 7F0BE0F8 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2C2C 7F0BE0FC 1000007E */  b     .L7F0BE2F8
/* 0F2C30 7F0BE100 00001025 */   move  $v0, $zero
.L7F0BE104:
/* 0F2C34 7F0BE104 00002025 */  move  $a0, $zero
/* 0F2C38 7F0BE108 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2C3C 7F0BE10C 24050010 */   li    $a1, 16
/* 0F2C40 7F0BE110 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2C44 7F0BE114 24040001 */  li    $a0, 1
/* 0F2C48 7F0BE118 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2C4C 7F0BE11C 24050010 */   li    $a1, 16
/* 0F2C50 7F0BE120 00506025 */  or    $t4, $v0, $s0
/* 0F2C54 7F0BE124 11800029 */  beqz  $t4, .L7F0BE1CC
/* 0F2C58 7F0BE128 00002025 */   move  $a0, $zero
/* 0F2C5C 7F0BE12C 00002025 */  move  $a0, $zero
/* 0F2C60 7F0BE130 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2C64 7F0BE134 24050400 */   li    $a1, 1024
/* 0F2C68 7F0BE138 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2C6C 7F0BE13C 24040001 */  li    $a0, 1
/* 0F2C70 7F0BE140 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2C74 7F0BE144 24050400 */   li    $a1, 1024
/* 0F2C78 7F0BE148 00506825 */  or    $t5, $v0, $s0
/* 0F2C7C 7F0BE14C 11A0000A */  beqz  $t5, .L7F0BE178
/* 0F2C80 7F0BE150 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2C84 7F0BE154 0FC2E6B9 */  jal   sub_GAME_7F0B9AE4
/* 0F2C88 7F0BE158 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2C8C 7F0BE15C 14400006 */  bnez  $v0, .L7F0BE178
/* 0F2C90 7F0BE160 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2C94 7F0BE164 240E0001 */  li    $t6, 1
/* 0F2C98 7F0BE168 AFAE0020 */  sw    $t6, 0x20($sp)
/* 0F2C9C 7F0BE16C 8C8483CC */  lw    $a0, %lo(D_800483CC)($a0)
/* 0F2CA0 7F0BE170 0FC2E76F */  jal   sub_GAME_7F0B9DBC
/* 0F2CA4 7F0BE174 00002825 */   move  $a1, $zero
.L7F0BE178:
/* 0F2CA8 7F0BE178 00002025 */  move  $a0, $zero
/* 0F2CAC 7F0BE17C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2CB0 7F0BE180 24050800 */   li    $a1, 2048
/* 0F2CB4 7F0BE184 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2CB8 7F0BE188 24040001 */  li    $a0, 1
/* 0F2CBC 7F0BE18C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2CC0 7F0BE190 24050800 */   li    $a1, 2048
/* 0F2CC4 7F0BE194 00507825 */  or    $t7, $v0, $s0
/* 0F2CC8 7F0BE198 11E00056 */  beqz  $t7, .L7F0BE2F4
/* 0F2CCC 7F0BE19C 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2CD0 7F0BE1A0 0FC2E6B9 */  jal   sub_GAME_7F0B9AE4
/* 0F2CD4 7F0BE1A4 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2CD8 7F0BE1A8 10400052 */  beqz  $v0, .L7F0BE2F4
/* 0F2CDC 7F0BE1AC 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2CE0 7F0BE1B0 24180001 */  li    $t8, 1
/* 0F2CE4 7F0BE1B4 AFB80020 */  sw    $t8, 0x20($sp)
/* 0F2CE8 7F0BE1B8 8C8483CC */  lw    $a0, %lo(D_800483CC)($a0)
/* 0F2CEC 7F0BE1BC 0FC2E76F */  jal   sub_GAME_7F0B9DBC
/* 0F2CF0 7F0BE1C0 24050001 */   li    $a1, 1
/* 0F2CF4 7F0BE1C4 1000004C */  b     .L7F0BE2F8
/* 0F2CF8 7F0BE1C8 00001025 */   move  $v0, $zero
.L7F0BE1CC:
/* 0F2CFC 7F0BE1CC 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2D00 7F0BE1D0 24050020 */   li    $a1, 32
/* 0F2D04 7F0BE1D4 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D08 7F0BE1D8 24040001 */  li    $a0, 1
/* 0F2D0C 7F0BE1DC 0C0030C3 */  jal   get_controller_buttons_held
/* 0F2D10 7F0BE1E0 24050020 */   li    $a1, 32
/* 0F2D14 7F0BE1E4 0050C825 */  or    $t9, $v0, $s0
/* 0F2D18 7F0BE1E8 13200027 */  beqz  $t9, .L7F0BE288
/* 0F2D1C 7F0BE1EC 00002025 */   move  $a0, $zero
/* 0F2D20 7F0BE1F0 00002025 */  move  $a0, $zero
/* 0F2D24 7F0BE1F4 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2D28 7F0BE1F8 24050400 */   li    $a1, 1024
/* 0F2D2C 7F0BE1FC 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D30 7F0BE200 24040001 */  li    $a0, 1
/* 0F2D34 7F0BE204 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2D38 7F0BE208 24050400 */   li    $a1, 1024
/* 0F2D3C 7F0BE20C 00504025 */  or    $t0, $v0, $s0
/* 0F2D40 7F0BE210 11000009 */  beqz  $t0, .L7F0BE238
/* 0F2D44 7F0BE214 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2D48 7F0BE218 0FC2E6C1 */  jal   sub_GAME_7F0B9B04
/* 0F2D4C 7F0BE21C 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2D50 7F0BE220 10400005 */  beqz  $v0, .L7F0BE238
/* 0F2D54 7F0BE224 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2D58 7F0BE228 24090001 */  li    $t1, 1
/* 0F2D5C 7F0BE22C AFA90020 */  sw    $t1, 0x20($sp)
/* 0F2D60 7F0BE230 0FC2E6D1 */  jal   sub_GAME_7F0B9B44
/* 0F2D64 7F0BE234 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE238:
/* 0F2D68 7F0BE238 00002025 */  move  $a0, $zero
/* 0F2D6C 7F0BE23C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2D70 7F0BE240 24050800 */   li    $a1, 2048
/* 0F2D74 7F0BE244 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D78 7F0BE248 24040001 */  li    $a0, 1
/* 0F2D7C 7F0BE24C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2D80 7F0BE250 24050800 */   li    $a1, 2048
/* 0F2D84 7F0BE254 00505025 */  or    $t2, $v0, $s0
/* 0F2D88 7F0BE258 11400026 */  beqz  $t2, .L7F0BE2F4
/* 0F2D8C 7F0BE25C 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2D90 7F0BE260 0FC2E6C1 */  jal   sub_GAME_7F0B9B04
/* 0F2D94 7F0BE264 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2D98 7F0BE268 14400022 */  bnez  $v0, .L7F0BE2F4
/* 0F2D9C 7F0BE26C 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2DA0 7F0BE270 240B0001 */  li    $t3, 1
/* 0F2DA4 7F0BE274 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0F2DA8 7F0BE278 0FC2E6C9 */  jal   sub_GAME_7F0B9B24
/* 0F2DAC 7F0BE27C 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
/* 0F2DB0 7F0BE280 1000001D */  b     .L7F0BE2F8
/* 0F2DB4 7F0BE284 00001025 */   move  $v0, $zero
.L7F0BE288:
/* 0F2DB8 7F0BE288 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2DBC 7F0BE28C 24050400 */   li    $a1, 1024
/* 0F2DC0 7F0BE290 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2DC4 7F0BE294 24040001 */  li    $a0, 1
/* 0F2DC8 7F0BE298 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2DCC 7F0BE29C 24050400 */   li    $a1, 1024
/* 0F2DD0 7F0BE2A0 00506025 */  or    $t4, $v0, $s0
/* 0F2DD4 7F0BE2A4 11800005 */  beqz  $t4, .L7F0BE2BC
/* 0F2DD8 7F0BE2A8 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2DDC 7F0BE2AC 240D0001 */  li    $t5, 1
/* 0F2DE0 7F0BE2B0 AFAD0020 */  sw    $t5, 0x20($sp)
/* 0F2DE4 7F0BE2B4 0FC2E69F */  jal   sub_GAME_7F0B9A7C
/* 0F2DE8 7F0BE2B8 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE2BC:
/* 0F2DEC 7F0BE2BC 00002025 */  move  $a0, $zero
/* 0F2DF0 7F0BE2C0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2DF4 7F0BE2C4 24050800 */   li    $a1, 2048
/* 0F2DF8 7F0BE2C8 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2DFC 7F0BE2CC 24040001 */  li    $a0, 1
/* 0F2E00 7F0BE2D0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F2E04 7F0BE2D4 24050800 */   li    $a1, 2048
/* 0F2E08 7F0BE2D8 00507025 */  or    $t6, $v0, $s0
/* 0F2E0C 7F0BE2DC 11C00005 */  beqz  $t6, .L7F0BE2F4
/* 0F2E10 7F0BE2E0 3C048005 */   lui   $a0, %hi(D_800483CC) # $a0, 0x8005
/* 0F2E14 7F0BE2E4 240F0001 */  li    $t7, 1
/* 0F2E18 7F0BE2E8 AFAF0020 */  sw    $t7, 0x20($sp)
/* 0F2E1C 7F0BE2EC 0FC2E68B */  jal   sub_GAME_7F0B9A2C
/* 0F2E20 7F0BE2F0 8C8483CC */   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE2F4:
/* 0F2E24 7F0BE2F4 00001025 */  move  $v0, $zero
.L7F0BE2F8:
/* 0F2E28 7F0BE2F8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F2E2C 7F0BE2FC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F2E30 7F0BE300 27BD0028 */  addiu $sp, $sp, 0x28
/* 0F2E34 7F0BE304 03E00008 */  jr    $ra
/* 0F2E38 7F0BE308 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BE30C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BE30C
/* 0F2E3C 7F0BE30C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0F2E40 7F0BE310 AFA40060 */  sw    $a0, 0x60($sp)
/* 0F2E44 7F0BE314 248F0008 */  addiu $t7, $a0, 8
/* 0F2E48 7F0BE318 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2E4C 7F0BE31C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F2E50 7F0BE320 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F2E54 7F0BE324 AFAF0060 */  sw    $t7, 0x60($sp)
/* 0F2E58 7F0BE328 3C18BC00 */  lui   $t8, (0xBC000006 >> 16) # lui $t8, 0xbc00
/* 0F2E5C 7F0BE32C 37180006 */  ori   $t8, (0xBC000006 & 0xFFFF) # ori $t8, $t8, 6
/* 0F2E60 7F0BE330 AC980000 */  sw    $t8, ($a0)
/* 0F2E64 7F0BE334 AC800004 */  sw    $zero, 4($a0)
/* 0F2E68 7F0BE338 8FB00060 */  lw    $s0, 0x60($sp)
/* 0F2E6C 7F0BE33C 3C0ABC00 */  lui   $t2, (0xBC000406 >> 16) # lui $t2, 0xbc00
/* 0F2E70 7F0BE340 354A0406 */  ori   $t2, (0xBC000406 & 0xFFFF) # ori $t2, $t2, 0x406
/* 0F2E74 7F0BE344 26090008 */  addiu $t1, $s0, 8
/* 0F2E78 7F0BE348 AFA90060 */  sw    $t1, 0x60($sp)
/* 0F2E7C 7F0BE34C 3C048009 */  lui   $a0, %hi(ptr_jfont_DL) # $a0, 0x8009
/* 0F2E80 7F0BE350 AE0A0000 */  sw    $t2, ($s0)
/* 0F2E84 7F0BE354 0C003A2C */  jal   osVirtualToPhysical
/* 0F2E88 7F0BE358 8C84C260 */   lw    $a0, %lo(ptr_jfont_DL)($a0)
/* 0F2E8C 7F0BE35C AE020004 */  sw    $v0, 4($s0)
/* 0F2E90 7F0BE360 8FAB0060 */  lw    $t3, 0x60($sp)
/* 0F2E94 7F0BE364 3C0D0100 */  lui   $t5, 0x100
/* 0F2E98 7F0BE368 3C050600 */  lui   $a1, 0x600
/* 0F2E9C 7F0BE36C 256C0008 */  addiu $t4, $t3, 8
/* 0F2EA0 7F0BE370 AFAC0060 */  sw    $t4, 0x60($sp)
/* 0F2EA4 7F0BE374 25AD0040 */  addiu $t5, $t5, 0x40
/* 0F2EA8 7F0BE378 AD6D0004 */  sw    $t5, 4($t3)
/* 0F2EAC 7F0BE37C AD650000 */  sw    $a1, ($t3)
/* 0F2EB0 7F0BE380 8FAE0060 */  lw    $t6, 0x60($sp)
/* 0F2EB4 7F0BE384 3C180100 */  lui   $t8, 0x100
/* 0F2EB8 7F0BE388 27180020 */  addiu $t8, $t8, 0x20
/* 0F2EBC 7F0BE38C 25CF0008 */  addiu $t7, $t6, 8
/* 0F2EC0 7F0BE390 AFAF0060 */  sw    $t7, 0x60($sp)
/* 0F2EC4 7F0BE394 3C198005 */  lui   $t9, %hi(current_stage_to_load) # $t9, 0x8005
/* 0F2EC8 7F0BE398 ADD80004 */  sw    $t8, 4($t6)
/* 0F2ECC 7F0BE39C ADC50000 */  sw    $a1, ($t6)
/* 0F2ED0 7F0BE3A0 8F398364 */  lw    $t9, %lo(current_stage_to_load)($t9)
/* 0F2ED4 7F0BE3A4 2401005A */  li    $at, 90
/* 0F2ED8 7F0BE3A8 17210025 */  bne   $t9, $at, .L7F0BE440
/* 0F2EDC 7F0BE3AC 00000000 */   nop   
/* 0F2EE0 7F0BE3B0 0C000FAD */  jal   video_related_10
/* 0F2EE4 7F0BE3B4 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F2EE8 7F0BE3B8 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F2EEC 7F0BE3BC 0C000F16 */  jal   video_related_F
/* 0F2EF0 7F0BE3C0 00402025 */   move  $a0, $v0
/* 0F2EF4 7F0BE3C4 24490008 */  addiu $t1, $v0, 8
/* 0F2EF8 7F0BE3C8 AFA90060 */  sw    $t1, 0x60($sp)
/* 0F2EFC 7F0BE3CC 3C0AED00 */  lui   $t2, 0xed00
/* 0F2F00 7F0BE3D0 AC4A0000 */  sw    $t2, ($v0)
/* 0F2F04 7F0BE3D4 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F2F08 7F0BE3D8 00408025 */   move  $s0, $v0
/* 0F2F0C 7F0BE3DC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F2F10 7F0BE3E0 A7A20022 */   sh    $v0, 0x22($sp)
/* 0F2F14 7F0BE3E4 87B10022 */  lh    $s1, 0x22($sp)
/* 0F2F18 7F0BE3E8 44822000 */  mtc1  $v0, $f4
/* 0F2F1C 7F0BE3EC 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0F2F20 7F0BE3F0 44918000 */  mtc1  $s1, $f16
/* 0F2F24 7F0BE3F4 468021A0 */  cvt.s.w $f6, $f4
/* 0F2F28 7F0BE3F8 44810000 */  mtc1  $at, $f0
/* 0F2F2C 7F0BE3FC 468084A0 */  cvt.s.w $f18, $f16
/* 0F2F30 7F0BE400 46003202 */  mul.s $f8, $f6, $f0
/* 0F2F34 7F0BE404 00000000 */  nop   
/* 0F2F38 7F0BE408 46009102 */  mul.s $f4, $f18, $f0
/* 0F2F3C 7F0BE40C 4600428D */  trunc.w.s $f10, $f8
/* 0F2F40 7F0BE410 4600218D */  trunc.w.s $f6, $f4
/* 0F2F44 7F0BE414 440C5000 */  mfc1  $t4, $f10
/* 0F2F48 7F0BE418 440F3000 */  mfc1  $t7, $f6
/* 0F2F4C 7F0BE41C 318D0FFF */  andi  $t5, $t4, 0xfff
/* 0F2F50 7F0BE420 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0F2F54 7F0BE424 0018CB00 */  sll   $t9, $t8, 0xc
/* 0F2F58 7F0BE428 01B94825 */  or    $t1, $t5, $t9
/* 0F2F5C 7F0BE42C AE090004 */  sw    $t1, 4($s0)
/* 0F2F60 7F0BE430 0FC06BBF */  jal   menu_jump_constructor_handler
/* 0F2F64 7F0BE434 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F2F68 7F0BE438 10000102 */  b     .L7F0BE844
/* 0F2F6C 7F0BE43C AFA20060 */   sw    $v0, 0x60($sp)
.L7F0BE440:
/* 0F2F70 7F0BE440 0FC26919 */  jal   get_num_players
/* 0F2F74 7F0BE444 00000000 */   nop   
/* 0F2F78 7F0BE448 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0F2F7C 7F0BE44C AFA20044 */  sw    $v0, 0x44($sp)
/* 0F2F80 7F0BE450 3C0CBC00 */  lui   $t4, (0xBC000404 >> 16) # lui $t4, 0xbc00
/* 0F2F84 7F0BE454 254B0008 */  addiu $t3, $t2, 8
/* 0F2F88 7F0BE458 AFAB0060 */  sw    $t3, 0x60($sp)
/* 0F2F8C 7F0BE45C 24070002 */  li    $a3, 2
/* 0F2F90 7F0BE460 358C0404 */  ori   $t4, (0xBC000404 & 0xFFFF) # ori $t4, $t4, 0x404
/* 0F2F94 7F0BE464 AD4C0000 */  sw    $t4, ($t2)
/* 0F2F98 7F0BE468 AD470004 */  sw    $a3, 4($t2)
/* 0F2F9C 7F0BE46C 8FAE0060 */  lw    $t6, 0x60($sp)
/* 0F2FA0 7F0BE470 3C18BC00 */  lui   $t8, (0xBC000C04 >> 16) # lui $t8, 0xbc00
/* 0F2FA4 7F0BE474 37180C04 */  ori   $t8, (0xBC000C04 & 0xFFFF) # ori $t8, $t8, 0xc04
/* 0F2FA8 7F0BE478 25CF0008 */  addiu $t7, $t6, 8
/* 0F2FAC 7F0BE47C AFAF0060 */  sw    $t7, 0x60($sp)
/* 0F2FB0 7F0BE480 ADC70004 */  sw    $a3, 4($t6)
/* 0F2FB4 7F0BE484 ADD80000 */  sw    $t8, ($t6)
/* 0F2FB8 7F0BE488 8FAD0060 */  lw    $t5, 0x60($sp)
/* 0F2FBC 7F0BE48C 3C09BC00 */  lui   $t1, (0xBC001404 >> 16) # lui $t1, 0xbc00
/* 0F2FC0 7F0BE490 3408FFFE */  li    $t0, 65534
/* 0F2FC4 7F0BE494 25B90008 */  addiu $t9, $t5, 8
/* 0F2FC8 7F0BE498 AFB90060 */  sw    $t9, 0x60($sp)
/* 0F2FCC 7F0BE49C 35291404 */  ori   $t1, (0xBC001404 & 0xFFFF) # ori $t1, $t1, 0x1404
/* 0F2FD0 7F0BE4A0 ADA90000 */  sw    $t1, ($t5)
/* 0F2FD4 7F0BE4A4 ADA80004 */  sw    $t0, 4($t5)
/* 0F2FD8 7F0BE4A8 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0F2FDC 7F0BE4AC 3C0CBC00 */  lui   $t4, (0xBC001C04 >> 16) # lui $t4, 0xbc00
/* 0F2FE0 7F0BE4B0 358C1C04 */  ori   $t4, (0xBC001C04 & 0xFFFF) # ori $t4, $t4, 0x1c04
/* 0F2FE4 7F0BE4B4 254B0008 */  addiu $t3, $t2, 8
/* 0F2FE8 7F0BE4B8 AFAB0060 */  sw    $t3, 0x60($sp)
/* 0F2FEC 7F0BE4BC 00008825 */  move  $s1, $zero
/* 0F2FF0 7F0BE4C0 AD480004 */  sw    $t0, 4($t2)
/* 0F2FF4 7F0BE4C4 184000DF */  blez  $v0, .L7F0BE844
/* 0F2FF8 7F0BE4C8 AD4C0000 */   sw    $t4, ($t2)
/* 0F2FFC 7F0BE4CC 3C108008 */  lui   $s0, %hi(ptr_BONDdata) # $s0, 0x8008
/* 0F3000 7F0BE4D0 2610A0B0 */  addiu $s0, %lo(ptr_BONDdata) # addiu $s0, $s0, -0x5f50
.L7F0BE4D4:
/* 0F3004 7F0BE4D4 0FC26D4A */  jal   sub_GAME_7F09B528
/* 0F3008 7F0BE4D8 02202025 */   move  $a0, $s1
/* 0F300C 7F0BE4DC 0FC26C43 */  jal   set_cur_player
/* 0F3010 7F0BE4E0 00402025 */   move  $a0, $v0
/* 0F3014 7F0BE4E4 8E020000 */  lw    $v0, ($s0)
/* 0F3018 7F0BE4E8 844407F0 */  lh    $a0, 0x7f0($v0)
/* 0F301C 7F0BE4EC 0C00110F */  jal   set_video2_width_height
/* 0F3020 7F0BE4F0 844507F2 */   lh    $a1, 0x7f2($v0)
/* 0F3024 7F0BE4F4 8E020000 */  lw    $v0, ($s0)
/* 0F3028 7F0BE4F8 844407F4 */  lh    $a0, 0x7f4($v0)
/* 0F302C 7F0BE4FC 0C00112F */  jal   set_video2_ulx_uly
/* 0F3030 7F0BE500 844507F6 */   lh    $a1, 0x7f6($v0)
/* 0F3034 7F0BE504 8E0E0000 */  lw    $t6, ($s0)
/* 0F3038 7F0BE508 0C001151 */  jal   video_related_1F
/* 0F303C 7F0BE50C C5CC11D0 */   lwc1  $f12, 0x11d0($t6)
/* 0F3040 7F0BE510 8E0F0000 */  lw    $t7, ($s0)
/* 0F3044 7F0BE514 0C001164 */  jal   video_related_21
/* 0F3048 7F0BE518 C5EC11D4 */   lwc1  $f12, 0x11d4($t7)
/* 0F304C 7F0BE51C 0C000FAD */  jal   video_related_10
/* 0F3050 7F0BE520 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3054 7F0BE524 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F3058 7F0BE528 0C000F16 */  jal   video_related_F
/* 0F305C 7F0BE52C 00402025 */   move  $a0, $v0
/* 0F3060 7F0BE530 0FC243BF */  jal   get_debug_render_raster
/* 0F3064 7F0BE534 AFA20060 */   sw    $v0, 0x60($sp)
/* 0F3068 7F0BE538 14400004 */  bnez  $v0, .L7F0BE54C
/* 0F306C 7F0BE53C 00000000 */   nop   
/* 0F3070 7F0BE540 0FC24560 */  jal   sub_GAME_7F091580
/* 0F3074 7F0BE544 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3078 7F0BE548 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE54C:
/* 0F307C 7F0BE54C 0FC243BF */  jal   get_debug_render_raster
/* 0F3080 7F0BE550 00000000 */   nop   
/* 0F3084 7F0BE554 24010001 */  li    $at, 1
/* 0F3088 7F0BE558 14410004 */  bne   $v0, $at, .L7F0BE56C
/* 0F308C 7F0BE55C 00000000 */   nop   
/* 0F3090 7F0BE560 0FC2CB52 */  jal   sub_GAME_7F0B2D48
/* 0F3094 7F0BE564 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3098 7F0BE568 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE56C:
/* 0F309C 7F0BE56C 0FC243BF */  jal   get_debug_render_raster
/* 0F30A0 7F0BE570 00000000 */   nop   
/* 0F30A4 7F0BE574 24010002 */  li    $at, 2
/* 0F30A8 7F0BE578 14410004 */  bne   $v0, $at, .L7F0BE58C
/* 0F30AC 7F0BE57C 00000000 */   nop   
/* 0F30B0 7F0BE580 0FC21E82 */  jal   sub_GAME_7F087A08
/* 0F30B4 7F0BE584 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F30B8 7F0BE588 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE58C:
/* 0F30BC 7F0BE58C 0C000FD9 */  jal   setupscreensfornumplayers
/* 0F30C0 7F0BE590 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F30C4 7F0BE594 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F30C8 7F0BE598 0FC25122 */  jal   sub_GAME_7F094488
/* 0F30CC 7F0BE59C 00402025 */   move  $a0, $v0
/* 0F30D0 7F0BE5A0 0FC2D221 */  jal   sub_GAME_7F0B4884
/* 0F30D4 7F0BE5A4 AFA20060 */   sw    $v0, 0x60($sp)
/* 0F30D8 7F0BE5A8 0FC0F28C */  jal   determing_type_of_object_and_detection
/* 0F30DC 7F0BE5AC 00000000 */   nop   
/* 0F30E0 7F0BE5B0 0FC0E890 */  jal   sub_GAME_7F03A240
/* 0F30E4 7F0BE5B4 00000000 */   nop   
/* 0F30E8 7F0BE5B8 0FC0F5E3 */  jal   sub_GAME_7F03D78C
/* 0F30EC 7F0BE5BC 00000000 */   nop   
/* 0F30F0 7F0BE5C0 0FC0F0A5 */  jal   sub_GAME_7F03C294
/* 0F30F4 7F0BE5C4 00000000 */   nop   
/* 0F30F8 7F0BE5C8 0FC227CE */  jal   sub_GAME_7F089F38
/* 0F30FC 7F0BE5CC 00000000 */   nop   
/* 0F3100 7F0BE5D0 10400009 */  beqz  $v0, .L7F0BE5F8
/* 0F3104 7F0BE5D4 00000000 */   nop   
/* 0F3108 7F0BE5D8 0FC0F13C */  jal   sub_GAME_7F03C4F0
/* 0F310C 7F0BE5DC 00000000 */   nop   
/* 0F3110 7F0BE5E0 10400005 */  beqz  $v0, .L7F0BE5F8
/* 0F3114 7F0BE5E4 00000000 */   nop   
/* 0F3118 7F0BE5E8 0FC17659 */  jal   attempt_reload_item_in_hand
/* 0F311C 7F0BE5EC 00002025 */   move  $a0, $zero
/* 0F3120 7F0BE5F0 0FC17659 */  jal   attempt_reload_item_in_hand
/* 0F3124 7F0BE5F4 24040001 */   li    $a0, 1
.L7F0BE5F8:
/* 0F3128 7F0BE5F8 0FC0F435 */  jal   sub_GAME_7F03D0D4
/* 0F312C 7F0BE5FC 00000000 */   nop   
/* 0F3130 7F0BE600 0FC2D390 */  jal   sub_GAME_7F0B4E40
/* 0F3134 7F0BE604 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3138 7F0BE608 0FC2440F */  jal   get_debug_portal_flag
/* 0F313C 7F0BE60C AFA20060 */   sw    $v0, 0x60($sp)
/* 0F3140 7F0BE610 10400004 */  beqz  $v0, .L7F0BE624
/* 0F3144 7F0BE614 00000000 */   nop   
/* 0F3148 7F0BE618 0FC2F7C4 */  jal   sub_GAME_7F0BDF10
/* 0F314C 7F0BE61C 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3150 7F0BE620 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE624:
/* 0F3154 7F0BE624 0FC243DC */  jal   get_turbo_mode_flag
/* 0F3158 7F0BE628 00000000 */   nop   
/* 0F315C 7F0BE62C 10400004 */  beqz  $v0, .L7F0BE640
/* 0F3160 7F0BE630 00000000 */   nop   
/* 0F3164 7F0BE634 0FC2CC0F */  jal   sub_GAME_7F0B303C
/* 0F3168 7F0BE638 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F316C 7F0BE63C AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE640:
/* 0F3170 7F0BE640 0FC243D6 */  jal   get_debug_stanhit_flag
/* 0F3174 7F0BE644 00000000 */   nop   
/* 0F3178 7F0BE648 10400007 */  beqz  $v0, .L7F0BE668
/* 0F317C 7F0BE64C 00000000 */   nop   
/* 0F3180 7F0BE650 0FC2CC0D */  jal   sub_GAME_7F0B3034
/* 0F3184 7F0BE654 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3188 7F0BE658 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F318C 7F0BE65C 0FC225B0 */  jal   write_stan_tiles_in_yellow
/* 0F3190 7F0BE660 00402025 */   move  $a0, $v0
/* 0F3194 7F0BE664 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE668:
/* 0F3198 7F0BE668 0FC243D9 */  jal   get_debug_stanregion_flag
/* 0F319C 7F0BE66C 00000000 */   nop   
/* 0F31A0 7F0BE670 10400008 */  beqz  $v0, .L7F0BE694
/* 0F31A4 7F0BE674 00000000 */   nop   
/* 0F31A8 7F0BE678 0FC2CC0D */  jal   sub_GAME_7F0B3034
/* 0F31AC 7F0BE67C 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F31B0 7F0BE680 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F31B4 7F0BE684 00402025 */  move  $a0, $v0
/* 0F31B8 7F0BE688 0FC2CC4B */  jal   sub_GAME_7F0B312C
/* 0F31BC 7F0BE68C 24058040 */   li    $a1, -32704
/* 0F31C0 7F0BE690 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE694:
/* 0F31C4 7F0BE694 3C058006 */  lui   $a1, %hi(aStanshow_) # $a1, 0x8006
/* 0F31C8 7F0BE698 24A5B6BC */  addiu $a1, %lo(aStanshow_) # addiu $a1, $a1, -0x4944
/* 0F31CC 7F0BE69C 0C0029A8 */  jal   check_token
/* 0F31D0 7F0BE6A0 24040001 */   li    $a0, 1
/* 0F31D4 7F0BE6A4 10400011 */  beqz  $v0, .L7F0BE6EC
/* 0F31D8 7F0BE6A8 24040001 */   li    $a0, 1
/* 0F31DC 7F0BE6AC 3C058006 */  lui   $a1, %hi(aStanshow__5) # $a1, 0x8006
/* 0F31E0 7F0BE6B0 0C0029A8 */  jal   check_token
/* 0F31E4 7F0BE6B4 24A5B6C8 */   addiu $a1, %lo(aStanshow__5) # addiu $a1, $a1, -0x4938
/* 0F31E8 7F0BE6B8 0FC2CB96 */  jal   stanMatchTileName
/* 0F31EC 7F0BE6BC 00402025 */   move  $a0, $v0
/* 0F31F0 7F0BE6C0 1040000A */  beqz  $v0, .L7F0BE6EC
/* 0F31F4 7F0BE6C4 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F31F8 7F0BE6C8 0FC2CC0D */  jal   sub_GAME_7F0B3034
/* 0F31FC 7F0BE6CC AFA20030 */   sw    $v0, 0x30($sp)
/* 0F3200 7F0BE6D0 3C06FF00 */  lui   $a2, (0xFF0000FF >> 16) # lui $a2, 0xff00
/* 0F3204 7F0BE6D4 8FA50030 */  lw    $a1, 0x30($sp)
/* 0F3208 7F0BE6D8 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F320C 7F0BE6DC 34C600FF */  ori   $a2, (0xFF0000FF & 0xFFFF) # ori $a2, $a2, 0xff
/* 0F3210 7F0BE6E0 0FC2CC09 */  jal   sub_GAME_7F0B3024
/* 0F3214 7F0BE6E4 00402025 */   move  $a0, $v0
/* 0F3218 7F0BE6E8 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE6EC:
/* 0F321C 7F0BE6EC 3C058006 */  lui   $a1, %hi(aStanshow__0) # $a1, 0x8006
/* 0F3220 7F0BE6F0 24A5B6D4 */  addiu $a1, %lo(aStanshow__0) # addiu $a1, $a1, -0x492c
/* 0F3224 7F0BE6F4 0C0029A8 */  jal   check_token
/* 0F3228 7F0BE6F8 24040002 */   li    $a0, 2
/* 0F322C 7F0BE6FC 10400011 */  beqz  $v0, .L7F0BE744
/* 0F3230 7F0BE700 24040002 */   li    $a0, 2
/* 0F3234 7F0BE704 3C058006 */  lui   $a1, %hi(aStanshow__1) # $a1, 0x8006
/* 0F3238 7F0BE708 0C0029A8 */  jal   check_token
/* 0F323C 7F0BE70C 24A5B6E0 */   addiu $a1, %lo(aStanshow__1) # addiu $a1, $a1, -0x4920
/* 0F3240 7F0BE710 0FC2CB96 */  jal   stanMatchTileName
/* 0F3244 7F0BE714 00402025 */   move  $a0, $v0
/* 0F3248 7F0BE718 1040000A */  beqz  $v0, .L7F0BE744
/* 0F324C 7F0BE71C 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3250 7F0BE720 0FC2CC0D */  jal   sub_GAME_7F0B3034
/* 0F3254 7F0BE724 AFA2002C */   sw    $v0, 0x2c($sp)
/* 0F3258 7F0BE728 3C0600FF */  lui   $a2, (0x00FF00FF >> 16) # lui $a2, 0xff
/* 0F325C 7F0BE72C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F3260 7F0BE730 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F3264 7F0BE734 34C600FF */  ori   $a2, (0x00FF00FF & 0xFFFF) # ori $a2, $a2, 0xff
/* 0F3268 7F0BE738 0FC2CC09 */  jal   sub_GAME_7F0B3024
/* 0F326C 7F0BE73C 00402025 */   move  $a0, $v0
/* 0F3270 7F0BE740 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE744:
/* 0F3274 7F0BE744 3C058006 */  lui   $a1, %hi(aStanshow__2) # $a1, 0x8006
/* 0F3278 7F0BE748 24A5B6EC */  addiu $a1, %lo(aStanshow__2) # addiu $a1, $a1, -0x4914
/* 0F327C 7F0BE74C 0C0029A8 */  jal   check_token
/* 0F3280 7F0BE750 24040003 */   li    $a0, 3
/* 0F3284 7F0BE754 10400010 */  beqz  $v0, .L7F0BE798
/* 0F3288 7F0BE758 24040003 */   li    $a0, 3
/* 0F328C 7F0BE75C 3C058006 */  lui   $a1, %hi(aStanshow__3) # $a1, 0x8006
/* 0F3290 7F0BE760 0C0029A8 */  jal   check_token
/* 0F3294 7F0BE764 24A5B6F8 */   addiu $a1, %lo(aStanshow__3) # addiu $a1, $a1, -0x4908
/* 0F3298 7F0BE768 0FC2CB96 */  jal   stanMatchTileName
/* 0F329C 7F0BE76C 00402025 */   move  $a0, $v0
/* 0F32A0 7F0BE770 10400009 */  beqz  $v0, .L7F0BE798
/* 0F32A4 7F0BE774 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F32A8 7F0BE778 0FC2CC0D */  jal   sub_GAME_7F0B3034
/* 0F32AC 7F0BE77C AFA20028 */   sw    $v0, 0x28($sp)
/* 0F32B0 7F0BE780 8FA50028 */  lw    $a1, 0x28($sp)
/* 0F32B4 7F0BE784 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F32B8 7F0BE788 00402025 */  move  $a0, $v0
/* 0F32BC 7F0BE78C 0FC2CC09 */  jal   sub_GAME_7F0B3024
/* 0F32C0 7F0BE790 3406FFFF */   li    $a2, 65535
/* 0F32C4 7F0BE794 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE798:
/* 0F32C8 7F0BE798 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F32CC 7F0BE79C 00000000 */   nop   
/* 0F32D0 7F0BE7A0 38440008 */  xori  $a0, $v0, 8
/* 0F32D4 7F0BE7A4 0FC08B89 */  jal   sub_GAME_7F022E24
/* 0F32D8 7F0BE7A8 2C840001 */   sltiu $a0, $a0, 1
/* 0F32DC 7F0BE7AC 0FC126D6 */  jal   sub_GAME_7F049B58
/* 0F32E0 7F0BE7B0 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F32E4 7F0BE7B4 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F32E8 7F0BE7B8 27A40060 */  addiu $a0, $sp, 0x60
/* 0F32EC 7F0BE7BC 0FC29209 */  jal   sub_GAME_7F0A4824
/* 0F32F0 7F0BE7C0 24050001 */   li    $a1, 1
/* 0F32F4 7F0BE7C4 0FC28B11 */  jal   sub_GAME_7F0A2C44
/* 0F32F8 7F0BE7C8 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F32FC 7F0BE7CC AFA20060 */  sw    $v0, 0x60($sp)
/* 0F3300 7F0BE7D0 0FC2800D */  jal   sub_GAME_7F0A0034
/* 0F3304 7F0BE7D4 00402025 */   move  $a0, $v0
/* 0F3308 7F0BE7D8 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F330C 7F0BE7DC 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0F3310 7F0BE7E0 2404000B */   li    $a0, 11
/* 0F3314 7F0BE7E4 10400003 */  beqz  $v0, .L7F0BE7F4
/* 0F3318 7F0BE7E8 00000000 */   nop   
/* 0F331C 7F0BE7EC 0FC1A4BC */  jal   set_max_ammo_for_cur_player
/* 0F3320 7F0BE7F0 00000000 */   nop   
.L7F0BE7F4:
/* 0F3324 7F0BE7F4 0FC243BF */  jal   get_debug_render_raster
/* 0F3328 7F0BE7F8 00000000 */   nop   
/* 0F332C 7F0BE7FC 24010002 */  li    $at, 2
/* 0F3330 7F0BE800 14410005 */  bne   $v0, $at, .L7F0BE818
/* 0F3334 7F0BE804 00000000 */   nop   
/* 0F3338 7F0BE808 0FC22482 */  jal   maybe_mp_interface
/* 0F333C 7F0BE80C 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3340 7F0BE810 10000004 */  b     .L7F0BE824
/* 0F3344 7F0BE814 AFA20060 */   sw    $v0, 0x60($sp)
.L7F0BE818:
/* 0F3348 7F0BE818 0FC22F2E */  jal   sub_GAME_7F08BCB8
/* 0F334C 7F0BE81C 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F3350 7F0BE820 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0BE824:
/* 0F3354 7F0BE824 0FC31009 */  jal   mp_watch_menu_display
/* 0F3358 7F0BE828 8FA40060 */   lw    $a0, 0x60($sp)
/* 0F335C 7F0BE82C 8FB80044 */  lw    $t8, 0x44($sp)
/* 0F3360 7F0BE830 26310001 */  addiu $s1, $s1, 1
/* 0F3364 7F0BE834 AFA20060 */  sw    $v0, 0x60($sp)
/* 0F3368 7F0BE838 0238082A */  slt   $at, $s1, $t8
/* 0F336C 7F0BE83C 1420FF25 */  bnez  $at, .L7F0BE4D4
/* 0F3370 7F0BE840 00000000 */   nop   
.L7F0BE844:
/* 0F3374 7F0BE844 8FB00060 */  lw    $s0, 0x60($sp)
/* 0F3378 7F0BE848 3C09ED00 */  lui   $t1, 0xed00
/* 0F337C 7F0BE84C 26190008 */  addiu $t9, $s0, 8
/* 0F3380 7F0BE850 AFB90060 */  sw    $t9, 0x60($sp)
/* 0F3384 7F0BE854 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F3388 7F0BE858 AE090000 */   sw    $t1, ($s0)
/* 0F338C 7F0BE85C 00028C00 */  sll   $s1, $v0, 0x10
/* 0F3390 7F0BE860 00115403 */  sra   $t2, $s1, 0x10
/* 0F3394 7F0BE864 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F3398 7F0BE868 01408825 */   move  $s1, $t2
/* 0F339C 7F0BE86C 44824000 */  mtc1  $v0, $f8
/* 0F33A0 7F0BE870 44913000 */  mtc1  $s1, $f6
/* 0F33A4 7F0BE874 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0F33A8 7F0BE878 468042A0 */  cvt.s.w $f10, $f8
/* 0F33AC 7F0BE87C 44818000 */  mtc1  $at, $f16
/* 0F33B0 7F0BE880 46803220 */  cvt.s.w $f8, $f6
/* 0F33B4 7F0BE884 46105482 */  mul.s $f18, $f10, $f16
/* 0F33B8 7F0BE888 44815000 */  mtc1  $at, $f10
/* 0F33BC 7F0BE88C 00000000 */  nop   
/* 0F33C0 7F0BE890 460A4402 */  mul.s $f16, $f8, $f10
/* 0F33C4 7F0BE894 4600910D */  trunc.w.s $f4, $f18
/* 0F33C8 7F0BE898 4600848D */  trunc.w.s $f18, $f16
/* 0F33CC 7F0BE89C 440C2000 */  mfc1  $t4, $f4
/* 0F33D0 7F0BE8A0 44189000 */  mfc1  $t8, $f18
/* 0F33D4 7F0BE8A4 318E0FFF */  andi  $t6, $t4, 0xfff
/* 0F33D8 7F0BE8A8 330D0FFF */  andi  $t5, $t8, 0xfff
/* 0F33DC 7F0BE8AC 000DCB00 */  sll   $t9, $t5, 0xc
/* 0F33E0 7F0BE8B0 01D94825 */  or    $t1, $t6, $t9
/* 0F33E4 7F0BE8B4 AE090004 */  sw    $t1, 4($s0)
/* 0F33E8 7F0BE8B8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F33EC 7F0BE8BC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F33F0 7F0BE8C0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F33F4 7F0BE8C4 8FA20060 */  lw    $v0, 0x60($sp)
/* 0F33F8 7F0BE8C8 03E00008 */  jr    $ra
/* 0F33FC 7F0BE8CC 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BE8D0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005B73C
.word 0x3f19999a /*0.60000002*/
glabel D_8005B740
.word 0x3ef33334 /*0.47500002*/
glabel D_8005B744
.word 0x3f19999a /*0.60000002*/
glabel D_8005B748
.word 0x3e4ccccd /*0.2*/
glabel D_8005B74C
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F0BE8D0
/* 0F3400 7F0BE8D0 3C028005 */  lui   $v0, %hi(difficulty_0) # $v0, 0x8005
/* 0F3404 7F0BE8D4 8C428384 */  lw    $v0, %lo(difficulty_0)($v0)
/* 0F3408 7F0BE8D8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F340C 7F0BE8DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F3410 7F0BE8E0 14400048 */  bnez  $v0, .L7F0BEA04
/* 0F3414 7F0BE8E4 24010001 */   li    $at, 1
/* 0F3418 7F0BE8E8 0FC228BB */  jal   get_BONDdata_watch_health
/* 0F341C 7F0BE8EC 00000000 */   nop   
/* 0F3420 7F0BE8F0 0FC228BF */  jal   get_BONDdata_watch_armor
/* 0F3424 7F0BE8F4 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 0F3428 7F0BE8F8 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0F342C 7F0BE8FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F3430 7F0BE900 44816000 */  mtc1  $at, $f12
/* 0F3434 7F0BE904 46040380 */  add.s $f14, $f0, $f4
/* 0F3438 7F0BE908 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 0F343C 7F0BE90C 44818000 */  mtc1  $at, $f16
/* 0F3440 7F0BE910 3C018006 */  lui   $at, %hi(D_8005B73C)
/* 0F3444 7F0BE914 4610703E */  c.le.s $f14, $f16
/* 0F3448 7F0BE918 00000000 */  nop   
/* 0F344C 7F0BE91C 45000005 */  bc1f  .L7F0BE934
/* 0F3450 7F0BE920 00000000 */   nop   
/* 0F3454 7F0BE924 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F3458 7F0BE928 44816000 */  mtc1  $at, $f12
/* 0F345C 7F0BE92C 1000000F */  b     .L7F0BE96C
/* 0F3460 7F0BE930 3C014000 */   lui   $at, 0x4000
.L7F0BE934:
/* 0F3464 7F0BE934 C426B73C */  lwc1  $f6, %lo(D_8005B73C)($at)
/* 0F3468 7F0BE938 3C013F00 */  lui   $at, 0x3f00
/* 0F346C 7F0BE93C 4606703E */  c.le.s $f14, $f6
/* 0F3470 7F0BE940 00000000 */  nop   
/* 0F3474 7F0BE944 45020009 */  bc1fl .L7F0BE96C
/* 0F3478 7F0BE948 3C014000 */   li    $at, 0x40000000 # 2.000000
/* 0F347C 7F0BE94C 46107201 */  sub.s $f8, $f14, $f16
/* 0F3480 7F0BE950 44819000 */  mtc1  $at, $f18
/* 0F3484 7F0BE954 3C018006 */  lui   $at, %hi(D_8005B740) # $at, 0x8006
/* 0F3488 7F0BE958 C424B740 */  lwc1  $f4, %lo(D_8005B740)($at)
/* 0F348C 7F0BE95C 46124282 */  mul.s $f10, $f8, $f18
/* 0F3490 7F0BE960 46045183 */  div.s $f6, $f10, $f4
/* 0F3494 7F0BE964 46123300 */  add.s $f12, $f6, $f18
/* 0F3498 7F0BE968 3C014000 */  li    $at, 0x40000000 # 2.000000
.L7F0BE96C:
/* 0F349C 7F0BE96C 44811000 */  mtc1  $at, $f2
/* 0F34A0 7F0BE970 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F34A4 7F0BE974 44819000 */  mtc1  $at, $f18
/* 0F34A8 7F0BE978 3C018003 */  lui   $at, %hi(D_80030B14) # $at, 0x8003
/* 0F34AC 7F0BE97C E4220B14 */  swc1  $f2, %lo(D_80030B14)($at)
/* 0F34B0 7F0BE980 460C9002 */  mul.s $f0, $f18, $f12
/* 0F34B4 7F0BE984 3C018003 */  lui   $at, %hi(D_80030B18) # $at, 0x8003
/* 0F34B8 7F0BE988 E4220B18 */  swc1  $f2, %lo(D_80030B18)($at)
/* 0F34BC 7F0BE98C 3C018003 */  lui   $at, %hi(D_80030B1C) # $at, 0x8003
/* 0F34C0 7F0BE990 E4200B1C */  swc1  $f0, %lo(D_80030B1C)($at)
/* 0F34C4 7F0BE994 3C018003 */  lui   $at, %hi(D_80030B20) # $at, 0x8003
/* 0F34C8 7F0BE998 E4200B20 */  swc1  $f0, %lo(D_80030B20)($at)
/* 0F34CC 7F0BE99C 3C018003 */  lui   $at, %hi(D_80030B24) # $at, 0x8003
/* 0F34D0 7F0BE9A0 E4220B24 */  swc1  $f2, %lo(D_80030B24)($at)
/* 0F34D4 7F0BE9A4 3C018006 */  lui   $at, %hi(D_8005B744) # $at, 0x8006
/* 0F34D8 7F0BE9A8 C428B744 */  lwc1  $f8, %lo(D_8005B744)($at)
/* 0F34DC 7F0BE9AC 3C018003 */  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
/* 0F34E0 7F0BE9B0 E428CE40 */  swc1  $f8, %lo(ai_accuracy_modifier)($at)
/* 0F34E4 7F0BE9B4 3C018003 */  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
/* 0F34E8 7F0BE9B8 E420CE44 */  swc1  $f0, %lo(ai_damage_modifier)($at)
/* 0F34EC 7F0BE9BC 3C018003 */  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
/* 0F34F0 7F0BE9C0 E422CE48 */  swc1  $f2, %lo(ai_health_modifier)($at)
/* 0F34F4 7F0BE9C4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0F34F8 7F0BE9C8 44815000 */  mtc1  $at, $f10
/* 0F34FC 7F0BE9CC 3C018004 */  lui   $at, %hi(D_80040178) # $at, 0x8004
/* 0F3500 7F0BE9D0 460C5102 */  mul.s $f4, $f10, $f12
/* 0F3504 7F0BE9D4 E4240178 */  swc1  $f4, %lo(D_80040178)($at)
/* 0F3508 7F0BE9D8 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0F350C 7F0BE9DC 44813000 */  mtc1  $at, $f6
/* 0F3510 7F0BE9E0 3C018003 */  lui   $at, %hi(difficulty) # $at, 0x8003
/* 0F3514 7F0BE9E4 E4260AAC */  swc1  $f6, %lo(difficulty)($at)
/* 0F3518 7F0BE9E8 3C018003 */  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
/* 0F351C 7F0BE9EC E4220B28 */  swc1  $f2, %lo(solo_ammo_multiplier)($at)
/* 0F3520 7F0BE9F0 3C018006 */  lui   $at, %hi(D_8005B748) # $at, 0x8006
/* 0F3524 7F0BE9F4 C428B748 */  lwc1  $f8, %lo(D_8005B748)($at)
/* 0F3528 7F0BE9F8 3C018003 */  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
/* 0F352C 7F0BE9FC 1000005E */  b     .L7F0BEB78
/* 0F3530 7F0BEA00 E428CE4C */   swc1  $f8, %lo(ai_reaction_speed)($at)
.L7F0BEA04:
/* 0F3534 7F0BEA04 14410021 */  bne   $v0, $at, .L7F0BEA8C
/* 0F3538 7F0BEA08 3C013F40 */   li    $at, 0x3F400000 # 0.750000
/* 0F353C 7F0BEA0C 44810000 */  mtc1  $at, $f0
/* 0F3540 7F0BEA10 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F3544 7F0BEA14 44811000 */  mtc1  $at, $f2
/* 0F3548 7F0BEA18 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F354C 7F0BEA1C 44819000 */  mtc1  $at, $f18
/* 0F3550 7F0BEA20 3C018003 */  lui   $at, %hi(D_80030B14) # $at, 0x8003
/* 0F3554 7F0BEA24 E4220B14 */  swc1  $f2, %lo(D_80030B14)($at)
/* 0F3558 7F0BEA28 3C018003 */  lui   $at, %hi(D_80030B18) # $at, 0x8003
/* 0F355C 7F0BEA2C E4220B18 */  swc1  $f2, %lo(D_80030B18)($at)
/* 0F3560 7F0BEA30 3C018003 */  lui   $at, %hi(D_80030B1C) # $at, 0x8003
/* 0F3564 7F0BEA34 E4200B1C */  swc1  $f0, %lo(D_80030B1C)($at)
/* 0F3568 7F0BEA38 3C018003 */  lui   $at, %hi(D_80030B20) # $at, 0x8003
/* 0F356C 7F0BEA3C E4200B20 */  swc1  $f0, %lo(D_80030B20)($at)
/* 0F3570 7F0BEA40 3C018003 */  lui   $at, %hi(D_80030B24) # $at, 0x8003
/* 0F3574 7F0BEA44 E4220B24 */  swc1  $f2, %lo(D_80030B24)($at)
/* 0F3578 7F0BEA48 3C018003 */  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
/* 0F357C 7F0BEA4C E420CE40 */  swc1  $f0, %lo(ai_accuracy_modifier)($at)
/* 0F3580 7F0BEA50 3C018003 */  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
/* 0F3584 7F0BEA54 E420CE44 */  swc1  $f0, %lo(ai_damage_modifier)($at)
/* 0F3588 7F0BEA58 3C018003 */  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
/* 0F358C 7F0BEA5C E422CE48 */  swc1  $f2, %lo(ai_health_modifier)($at)
/* 0F3590 7F0BEA60 3C018004 */  lui   $at, %hi(D_80040178) # $at, 0x8004
/* 0F3594 7F0BEA64 E4200178 */  swc1  $f0, %lo(D_80040178)($at)
/* 0F3598 7F0BEA68 3C018003 */  lui   $at, %hi(difficulty) # $at, 0x8003
/* 0F359C 7F0BEA6C E4200AAC */  swc1  $f0, %lo(difficulty)($at)
/* 0F35A0 7F0BEA70 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0F35A4 7F0BEA74 44815000 */  mtc1  $at, $f10
/* 0F35A8 7F0BEA78 3C018003 */  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
/* 0F35AC 7F0BEA7C E42A0B28 */  swc1  $f10, %lo(solo_ammo_multiplier)($at)
/* 0F35B0 7F0BEA80 3C018003 */  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
/* 0F35B4 7F0BEA84 1000003C */  b     .L7F0BEB78
/* 0F35B8 7F0BEA88 E432CE4C */   swc1  $f18, %lo(ai_reaction_speed)($at)
.L7F0BEA8C:
/* 0F35BC 7F0BEA8C 24010002 */  li    $at, 2
/* 0F35C0 7F0BEA90 1441001D */  bne   $v0, $at, .L7F0BEB08
/* 0F35C4 7F0BEA94 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0F35C8 7F0BEA98 44811000 */  mtc1  $at, $f2
/* 0F35CC 7F0BEA9C 3C018003 */  lui   $at, %hi(D_80030B14) # $at, 0x8003
/* 0F35D0 7F0BEAA0 E4220B14 */  swc1  $f2, %lo(D_80030B14)($at)
/* 0F35D4 7F0BEAA4 3C018003 */  lui   $at, %hi(D_80030B18) # $at, 0x8003
/* 0F35D8 7F0BEAA8 E4220B18 */  swc1  $f2, %lo(D_80030B18)($at)
/* 0F35DC 7F0BEAAC 3C018003 */  lui   $at, %hi(D_80030B1C) # $at, 0x8003
/* 0F35E0 7F0BEAB0 E4220B1C */  swc1  $f2, %lo(D_80030B1C)($at)
/* 0F35E4 7F0BEAB4 3C018003 */  lui   $at, %hi(D_80030B20) # $at, 0x8003
/* 0F35E8 7F0BEAB8 E4220B20 */  swc1  $f2, %lo(D_80030B20)($at)
/* 0F35EC 7F0BEABC 3C018003 */  lui   $at, %hi(D_80030B24) # $at, 0x8003
/* 0F35F0 7F0BEAC0 E4220B24 */  swc1  $f2, %lo(D_80030B24)($at)
/* 0F35F4 7F0BEAC4 3C018003 */  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
/* 0F35F8 7F0BEAC8 E422CE40 */  swc1  $f2, %lo(ai_accuracy_modifier)($at)
/* 0F35FC 7F0BEACC 3C018003 */  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
/* 0F3600 7F0BEAD0 E422CE44 */  swc1  $f2, %lo(ai_damage_modifier)($at)
/* 0F3604 7F0BEAD4 3C018003 */  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
/* 0F3608 7F0BEAD8 E422CE48 */  swc1  $f2, %lo(ai_health_modifier)($at)
/* 0F360C 7F0BEADC 3C018004 */  lui   $at, %hi(D_80040178) # $at, 0x8004
/* 0F3610 7F0BEAE0 E4220178 */  swc1  $f2, %lo(D_80040178)($at)
/* 0F3614 7F0BEAE4 3C018006 */  lui   $at, %hi(D_8005B74C) # $at, 0x8006
/* 0F3618 7F0BEAE8 C424B74C */  lwc1  $f4, %lo(D_8005B74C)($at)
/* 0F361C 7F0BEAEC 3C018003 */  lui   $at, %hi(difficulty) # $at, 0x8003
/* 0F3620 7F0BEAF0 E4240AAC */  swc1  $f4, %lo(difficulty)($at)
/* 0F3624 7F0BEAF4 3C018003 */  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
/* 0F3628 7F0BEAF8 E4220B28 */  swc1  $f2, %lo(solo_ammo_multiplier)($at)
/* 0F362C 7F0BEAFC 3C018003 */  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
/* 0F3630 7F0BEB00 1000001D */  b     .L7F0BEB78
/* 0F3634 7F0BEB04 E422CE4C */   swc1  $f2, %lo(ai_reaction_speed)($at)
.L7F0BEB08:
/* 0F3638 7F0BEB08 24010003 */  li    $at, 3
/* 0F363C 7F0BEB0C 1441001A */  bne   $v0, $at, .L7F0BEB78
/* 0F3640 7F0BEB10 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0F3644 7F0BEB14 44811000 */  mtc1  $at, $f2
/* 0F3648 7F0BEB18 3C018003 */  lui   $at, %hi(D_80030B14) # $at, 0x8003
/* 0F364C 7F0BEB1C E4220B14 */  swc1  $f2, %lo(D_80030B14)($at)
/* 0F3650 7F0BEB20 3C018003 */  lui   $at, %hi(D_80030B18) # $at, 0x8003
/* 0F3654 7F0BEB24 E4220B18 */  swc1  $f2, %lo(D_80030B18)($at)
/* 0F3658 7F0BEB28 3C018003 */  lui   $at, %hi(D_80030B1C) # $at, 0x8003
/* 0F365C 7F0BEB2C E4220B1C */  swc1  $f2, %lo(D_80030B1C)($at)
/* 0F3660 7F0BEB30 3C018003 */  lui   $at, %hi(D_80030B20) # $at, 0x8003
/* 0F3664 7F0BEB34 E4220B20 */  swc1  $f2, %lo(D_80030B20)($at)
/* 0F3668 7F0BEB38 3C018003 */  lui   $at, %hi(D_80030B24) # $at, 0x8003
/* 0F366C 7F0BEB3C E4220B24 */  swc1  $f2, %lo(D_80030B24)($at)
/* 0F3670 7F0BEB40 3C018003 */  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
/* 0F3674 7F0BEB44 E422CE40 */  swc1  $f2, %lo(ai_accuracy_modifier)($at)
/* 0F3678 7F0BEB48 3C018003 */  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
/* 0F367C 7F0BEB4C E422CE44 */  swc1  $f2, %lo(ai_damage_modifier)($at)
/* 0F3680 7F0BEB50 3C018003 */  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
/* 0F3684 7F0BEB54 E422CE48 */  swc1  $f2, %lo(ai_health_modifier)($at)
/* 0F3688 7F0BEB58 3C018004 */  lui   $at, %hi(D_80040178) # $at, 0x8004
/* 0F368C 7F0BEB5C E4220178 */  swc1  $f2, %lo(D_80040178)($at)
/* 0F3690 7F0BEB60 3C018003 */  lui   $at, %hi(difficulty) # $at, 0x8003
/* 0F3694 7F0BEB64 E4220AAC */  swc1  $f2, %lo(difficulty)($at)
/* 0F3698 7F0BEB68 3C018003 */  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
/* 0F369C 7F0BEB6C E4220B28 */  swc1  $f2, %lo(solo_ammo_multiplier)($at)
/* 0F36A0 7F0BEB70 3C018003 */  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
/* 0F36A4 7F0BEB74 E422CE4C */  swc1  $f2, %lo(ai_reaction_speed)($at)
.L7F0BEB78:
/* 0F36A8 7F0BEB78 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F36AC 7F0BEB7C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0F36B0 7F0BEB80 03E00008 */  jr    $ra
/* 0F36B4 7F0BEB84 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void manage_mp_game(void) {

}
#else
GLOBAL_ASM(
.text
glabel manage_mp_game
/* 0F36B8 7F0BEB88 27BDFE68 */  addiu $sp, $sp, -0x198
/* 0F36BC 7F0BEB8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F36C0 7F0BEB90 0C000626 */  jal   mp_tlb_related
/* 0F36C4 7F0BEB94 00000000 */   nop   
/* 0F36C8 7F0BEB98 3C0E8005 */  lui   $t6, %hi(controls_locked_flag) # $t6, 0x8005
/* 0F36CC 7F0BEB9C 8DCE8370 */  lw    $t6, %lo(controls_locked_flag)($t6)
/* 0F36D0 7F0BEBA0 3C018005 */  lui   $at, %hi(clock_timer) # $at, 0x8005
/* 0F36D4 7F0BEBA4 11C00003 */  beqz  $t6, .L7F0BEBB4
/* 0F36D8 7F0BEBA8 00000000 */   nop   
/* 0F36DC 7F0BEBAC 10000010 */  b     .L7F0BEBF0
/* 0F36E0 7F0BEBB0 AC208374 */   sw    $zero, %lo(clock_timer)($at)
.L7F0BEBB4:
/* 0F36E4 7F0BEBB4 0FC31820 */  jal   checkGamePaused
/* 0F36E8 7F0BEBB8 00000000 */   nop   
/* 0F36EC 7F0BEBBC 10400004 */  beqz  $v0, .L7F0BEBD0
/* 0F36F0 7F0BEBC0 3C0F8005 */   lui   $t7, %hi(D_80048498) # $t7, 0x8005
/* 0F36F4 7F0BEBC4 3C018005 */  lui   $at, %hi(clock_timer) # $at, 0x8005
/* 0F36F8 7F0BEBC8 10000009 */  b     .L7F0BEBF0
/* 0F36FC 7F0BEBCC AC208374 */   sw    $zero, %lo(clock_timer)($at)
.L7F0BEBD0:
/* 0F3700 7F0BEBD0 8DEF8498 */  lw    $t7, %lo(D_80048498)($t7)
/* 0F3704 7F0BEBD4 3C028005 */  lui   $v0, %hi(D_80048380) # $v0, 0x8005
/* 0F3708 7F0BEBD8 3C018005 */  lui   $at, %hi(clock_timer) # $at, 0x8005
/* 0F370C 7F0BEBDC 24428380 */  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, -0x7c80
/* 0F3710 7F0BEBE0 AC2F8374 */  sw    $t7, %lo(clock_timer)($at)
/* 0F3714 7F0BEBE4 8C580000 */  lw    $t8, ($v0)
/* 0F3718 7F0BEBE8 27190001 */  addiu $t9, $t8, 1
/* 0F371C 7F0BEBEC AC590000 */  sw    $t9, ($v0)
.L7F0BEBF0:
/* 0F3720 7F0BEBF0 3C028005 */  lui   $v0, %hi(clock_timer) # $v0, 0x8005
/* 0F3724 7F0BEBF4 8C428374 */  lw    $v0, %lo(clock_timer)($v0)
/* 0F3728 7F0BEBF8 3C038005 */  lui   $v1, %hi(global_timer) # $v1, 0x8005
/* 0F372C 7F0BEBFC 3C018005 */  lui   $at, %hi(global_timer_delta) # $at, 0x8005
/* 0F3730 7F0BEC00 44822000 */  mtc1  $v0, $f4
/* 0F3734 7F0BEC04 2463837C */  addiu $v1, %lo(global_timer) # addiu $v1, $v1, -0x7c84
/* 0F3738 7F0BEC08 3C188005 */  lui   $t8, %hi(current_stage_to_load) # $t8, 0x8005
/* 0F373C 7F0BEC0C 468021A0 */  cvt.s.w $f6, $f4
/* 0F3740 7F0BEC10 3C198005 */  lui   $t9, %hi(D_80048394) # $t9, 0x8005
/* 0F3744 7F0BEC14 E4268378 */  swc1  $f6, %lo(global_timer_delta)($at)
/* 0F3748 7F0BEC18 8C6E0000 */  lw    $t6, ($v1)
/* 0F374C 7F0BEC1C 2401005A */  li    $at, 90
/* 0F3750 7F0BEC20 01C27821 */  addu  $t7, $t6, $v0
/* 0F3754 7F0BEC24 AC6F0000 */  sw    $t7, ($v1)
/* 0F3758 7F0BEC28 8F188364 */  lw    $t8, %lo(current_stage_to_load)($t8)
/* 0F375C 7F0BEC2C 1301001D */  beq   $t8, $at, .L7F0BECA4
/* 0F3760 7F0BEC30 00000000 */   nop   
/* 0F3764 7F0BEC34 8F398394 */  lw    $t9, %lo(D_80048394)($t9)
/* 0F3768 7F0BEC38 1720001A */  bnez  $t9, .L7F0BECA4
/* 0F376C 7F0BEC3C 00000000 */   nop   
/* 0F3770 7F0BEC40 18400018 */  blez  $v0, .L7F0BECA4
/* 0F3774 7F0BEC44 3C0E8003 */   lui   $t6, %hi(append_cheat_sp) # $t6, 0x8003
/* 0F3778 7F0BEC48 8DCEA900 */  lw    $t6, %lo(append_cheat_sp)($t6)
/* 0F377C 7F0BEC4C 3C038007 */  lui   $v1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS) # $v1, 0x8007
/* 0F3780 7F0BEC50 246396A1 */  addiu $v1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $v1, $v1, -0x695f
/* 0F3784 7F0BEC54 11C00013 */  beqz  $t6, .L7F0BECA4
/* 0F3788 7F0BEC58 24040001 */   li    $a0, 1
.L7F0BEC5C:
/* 0F378C 7F0BEC5C 906F0000 */  lbu   $t7, ($v1)
/* 0F3790 7F0BEC60 51E0000D */  beql  $t7, $zero, .L7F0BEC98
/* 0F3794 7F0BEC64 24840001 */   addiu $a0, $a0, 1
/* 0F3798 7F0BEC68 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F379C 7F0BEC6C 0FC24697 */  jal   sub_GAME_7F091A5C
/* 0F37A0 7F0BEC70 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F37A4 7F0BEC74 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F37A8 7F0BEC78 14400006 */  bnez  $v0, .L7F0BEC94
/* 0F37AC 7F0BEC7C 8FA40194 */   lw    $a0, 0x194($sp)
/* 0F37B0 7F0BEC80 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F37B4 7F0BEC84 0FC246AB */  jal   sub_GAME_7F091AAC
/* 0F37B8 7F0BEC88 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F37BC 7F0BEC8C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F37C0 7F0BEC90 8FA40194 */  lw    $a0, 0x194($sp)
.L7F0BEC94:
/* 0F37C4 7F0BEC94 24840001 */  addiu $a0, $a0, 1
.L7F0BEC98:
/* 0F37C8 7F0BEC98 2401004B */  li    $at, 75
/* 0F37CC 7F0BEC9C 1481FFEF */  bne   $a0, $at, .L7F0BEC5C
/* 0F37D0 7F0BECA0 24630001 */   addiu $v1, $v1, 1
.L7F0BECA4:
/* 0F37D4 7F0BECA4 0FC26919 */  jal   get_num_players
/* 0F37D8 7F0BECA8 00000000 */   nop   
/* 0F37DC 7F0BECAC 28410002 */  slti  $at, $v0, 2
/* 0F37E0 7F0BECB0 1420014B */  bnez  $at, .L7F0BF1E0
/* 0F37E4 7F0BECB4 3C188005 */   lui   $t8, %hi(current_stage_to_load) # $t8, 0x8005
/* 0F37E8 7F0BECB8 8F188364 */  lw    $t8, %lo(current_stage_to_load)($t8)
/* 0F37EC 7F0BECBC 2401005A */  li    $at, 90
/* 0F37F0 7F0BECC0 13010147 */  beq   $t8, $at, .L7F0BF1E0
/* 0F37F4 7F0BECC4 00000000 */   nop   
/* 0F37F8 7F0BECC8 0FC3030C */  jal   get_mission_state
/* 0F37FC 7F0BECCC 00000000 */   nop   
/* 0F3800 7F0BECD0 24010006 */  li    $at, 6
/* 0F3804 7F0BECD4 14410029 */  bne   $v0, $at, .L7F0BED7C
/* 0F3808 7F0BECD8 00000000 */   nop   
/* 0F380C 7F0BECDC AFA00190 */  sw    $zero, 0x190($sp)
/* 0F3810 7F0BECE0 AFA0018C */  sw    $zero, 0x18c($sp)
/* 0F3814 7F0BECE4 0FC26919 */  jal   get_num_players
/* 0F3818 7F0BECE8 AFA00188 */   sw    $zero, 0x188($sp)
/* 0F381C 7F0BECEC 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F3820 7F0BECF0 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F3824 7F0BECF4 1840001B */  blez  $v0, .L7F0BED64
/* 0F3828 7F0BECF8 8FA60188 */   lw    $a2, 0x188($sp)
/* 0F382C 7F0BECFC 3C0E8008 */  lui   $t6, %hi(ptr_BONDdata_p1) # $t6, 0x8008
/* 0F3830 7F0BED00 25CE9EE0 */  addiu $t6, %lo(ptr_BONDdata_p1) # addiu $t6, $t6, -0x6120
/* 0F3834 7F0BED04 0003C880 */  sll   $t9, $v1, 2
/* 0F3838 7F0BED08 032E2021 */  addu  $a0, $t9, $t6
.L7F0BED0C:
/* 0F383C 7F0BED0C 8C820000 */  lw    $v0, ($a0)
/* 0F3840 7F0BED10 24630001 */  addiu $v1, $v1, 1
/* 0F3844 7F0BED14 24840004 */  addiu $a0, $a0, 4
/* 0F3848 7F0BED18 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F384C 7F0BED1C 51E00007 */  beql  $t7, $zero, .L7F0BED3C
/* 0F3850 7F0BED20 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F3854 7F0BED24 8C580424 */  lw    $t8, 0x424($v0)
/* 0F3858 7F0BED28 24A50001 */  addiu $a1, $a1, 1
/* 0F385C 7F0BED2C 53000003 */  beql  $t8, $zero, .L7F0BED3C
/* 0F3860 7F0BED30 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F3864 7F0BED34 24C60001 */  addiu $a2, $a2, 1
/* 0F3868 7F0BED38 AFA30190 */  sw    $v1, 0x190($sp)
.L7F0BED3C:
/* 0F386C 7F0BED3C AFA4001C */  sw    $a0, 0x1c($sp)
/* 0F3870 7F0BED40 AFA5018C */  sw    $a1, 0x18c($sp)
/* 0F3874 7F0BED44 0FC26919 */  jal   get_num_players
/* 0F3878 7F0BED48 AFA60188 */   sw    $a2, 0x188($sp)
/* 0F387C 7F0BED4C 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F3880 7F0BED50 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F3884 7F0BED54 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F3888 7F0BED58 0062082A */  slt   $at, $v1, $v0
/* 0F388C 7F0BED5C 1420FFEB */  bnez  $at, .L7F0BED0C
/* 0F3890 7F0BED60 8FA60188 */   lw    $a2, 0x188($sp)
.L7F0BED64:
/* 0F3894 7F0BED64 18A00005 */  blez  $a1, .L7F0BED7C
/* 0F3898 7F0BED68 00000000 */   nop   
/* 0F389C 7F0BED6C 14A60003 */  bne   $a1, $a2, .L7F0BED7C
/* 0F38A0 7F0BED70 00000000 */   nop   
/* 0F38A4 7F0BED74 0FC3030F */  jal   set_missionstate
/* 0F38A8 7F0BED78 24040001 */   li    $a0, 1
.L7F0BED7C:
/* 0F38AC 7F0BED7C 3C038005 */  lui   $v1, %hi(mp_time) # $v1, 0x8005
/* 0F38B0 7F0BED80 8C638398 */  lw    $v1, %lo(mp_time)($v1)
/* 0F38B4 7F0BED84 3C028005 */  lui   $v0, %hi(D_80048394) # $v0, 0x8005
/* 0F38B8 7F0BED88 3C198005 */  lui   $t9, %hi(clock_timer) # $t9, 0x8005
/* 0F38BC 7F0BED8C 18600049 */  blez  $v1, .L7F0BEEB4
/* 0F38C0 7F0BED90 00000000 */   nop   
/* 0F38C4 7F0BED94 8C428394 */  lw    $v0, %lo(D_80048394)($v0)
/* 0F38C8 7F0BED98 8F398374 */  lw    $t9, %lo(clock_timer)($t9)
/* 0F38CC 7F0BED9C 2464F1F0 */  addiu $a0, $v1, -0xe10
/* 0F38D0 7F0BEDA0 0044082A */  slt   $at, $v0, $a0
/* 0F38D4 7F0BEDA4 03227021 */  addu  $t6, $t9, $v0
/* 0F38D8 7F0BEDA8 AFAE0180 */  sw    $t6, 0x180($sp)
/* 0F38DC 7F0BEDAC 10200015 */  beqz  $at, .L7F0BEE04
/* 0F38E0 7F0BEDB0 AFA20184 */   sw    $v0, 0x184($sp)
/* 0F38E4 7F0BEDB4 01C4082A */  slt   $at, $t6, $a0
/* 0F38E8 7F0BEDB8 14200012 */  bnez  $at, .L7F0BEE04
/* 0F38EC 7F0BEDBC 00000000 */   nop   
/* 0F38F0 7F0BEDC0 0FC26919 */  jal   get_num_players
/* 0F38F4 7F0BEDC4 AFA0017C */   sw    $zero, 0x17c($sp)
/* 0F38F8 7F0BEDC8 1840000E */  blez  $v0, .L7F0BEE04
/* 0F38FC 7F0BEDCC 00000000 */   nop   
.L7F0BEDD0:
/* 0F3900 7F0BEDD0 0FC26C43 */  jal   set_cur_player
/* 0F3904 7F0BEDD4 8FA4017C */   lw    $a0, 0x17c($sp)
/* 0F3908 7F0BEDD8 3C048006 */  lui   $a0, %hi(aOneMinuteLeft) # $a0, 0x8006
/* 0F390C 7F0BEDDC 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0F3910 7F0BEDE0 2484B704 */   addiu $a0, %lo(aOneMinuteLeft) # addiu $a0, $a0, -0x48fc
/* 0F3914 7F0BEDE4 8FAF017C */  lw    $t7, 0x17c($sp)
/* 0F3918 7F0BEDE8 25F80001 */  addiu $t8, $t7, 1
/* 0F391C 7F0BEDEC 0FC26919 */  jal   get_num_players
/* 0F3920 7F0BEDF0 AFB8017C */   sw    $t8, 0x17c($sp)
/* 0F3924 7F0BEDF4 8FB9017C */  lw    $t9, 0x17c($sp)
/* 0F3928 7F0BEDF8 0322082A */  slt   $at, $t9, $v0
/* 0F392C 7F0BEDFC 1420FFF4 */  bnez  $at, .L7F0BEDD0
/* 0F3930 7F0BEE00 00000000 */   nop   
.L7F0BEE04:
/* 0F3934 7F0BEE04 3C0F8005 */  lui   $t7, %hi(mp_time) # $t7, 0x8005
/* 0F3938 7F0BEE08 8DEF8398 */  lw    $t7, %lo(mp_time)($t7)
/* 0F393C 7F0BEE0C 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F3940 7F0BEE10 3C198005 */  lui   $t9, %hi(D_800483A0) # $t9, 0x8005
/* 0F3944 7F0BEE14 25F8FDA8 */  addiu $t8, $t7, -0x258
/* 0F3948 7F0BEE18 01D8082A */  slt   $at, $t6, $t8
/* 0F394C 7F0BEE1C 1420000D */  bnez  $at, .L7F0BEE54
/* 0F3950 7F0BEE20 00000000 */   nop   
/* 0F3954 7F0BEE24 8F3983A0 */  lw    $t9, %lo(D_800483A0)($t9)
/* 0F3958 7F0BEE28 1720000A */  bnez  $t9, .L7F0BEE54
/* 0F395C 7F0BEE2C 00000000 */   nop   
/* 0F3960 7F0BEE30 0FC2FF01 */  jal   get_controls_locked_flag
/* 0F3964 7F0BEE34 00000000 */   nop   
/* 0F3968 7F0BEE38 14400006 */  bnez  $v0, .L7F0BEE54
/* 0F396C 7F0BEE3C 3C048006 */   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0F3970 7F0BEE40 3C068005 */  lui   $a2, %hi(D_800483A0) # $a2, 0x8005
/* 0F3974 7F0BEE44 24C683A0 */  addiu $a2, %lo(D_800483A0) # addiu $a2, $a2, -0x7c60
/* 0F3978 7F0BEE48 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0F397C 7F0BEE4C 0C002382 */  jal   play_sfx_a1
/* 0F3980 7F0BEE50 240500A1 */   li    $a1, 161
.L7F0BEE54:
/* 0F3984 7F0BEE54 0FC2FF01 */  jal   get_controls_locked_flag
/* 0F3988 7F0BEE58 00000000 */   nop   
/* 0F398C 7F0BEE5C 1040000A */  beqz  $v0, .L7F0BEE88
/* 0F3990 7F0BEE60 3C048005 */   lui   $a0, %hi(D_800483A0) # $a0, 0x8005
/* 0F3994 7F0BEE64 8C8483A0 */  lw    $a0, %lo(D_800483A0)($a0)
/* 0F3998 7F0BEE68 10800007 */  beqz  $a0, .L7F0BEE88
/* 0F399C 7F0BEE6C 00000000 */   nop   
/* 0F39A0 7F0BEE70 0C00237C */  jal   sfxGetArg0Unk3F
/* 0F39A4 7F0BEE74 00000000 */   nop   
/* 0F39A8 7F0BEE78 10400003 */  beqz  $v0, .L7F0BEE88
/* 0F39AC 7F0BEE7C 3C048005 */   lui   $a0, %hi(D_800483A0) # $a0, 0x8005
/* 0F39B0 7F0BEE80 0C002408 */  jal   sfxDeactivate
/* 0F39B4 7F0BEE84 8C8483A0 */   lw    $a0, %lo(D_800483A0)($a0)
.L7F0BEE88:
/* 0F39B8 7F0BEE88 3C038005 */  lui   $v1, %hi(mp_time) # $v1, 0x8005
/* 0F39BC 7F0BEE8C 8C638398 */  lw    $v1, %lo(mp_time)($v1)
/* 0F39C0 7F0BEE90 8FAF0184 */  lw    $t7, 0x184($sp)
/* 0F39C4 7F0BEE94 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F39C8 7F0BEE98 01E3082A */  slt   $at, $t7, $v1
/* 0F39CC 7F0BEE9C 10200005 */  beqz  $at, .L7F0BEEB4
/* 0F39D0 7F0BEEA0 01C3082A */   slt   $at, $t6, $v1
/* 0F39D4 7F0BEEA4 14200003 */  bnez  $at, .L7F0BEEB4
/* 0F39D8 7F0BEEA8 00000000 */   nop   
/* 0F39DC 7F0BEEAC 0FC3094C */  jal   sub_GAME_7F0C2530
/* 0F39E0 7F0BEEB0 00002025 */   move  $a0, $zero
.L7F0BEEB4:
/* 0F39E4 7F0BEEB4 3C188005 */  lui   $t8, %hi(mp_point) # $t8, 0x8005
/* 0F39E8 7F0BEEB8 8F18839C */  lw    $t8, %lo(mp_point)($t8)
/* 0F39EC 7F0BEEBC 3C198005 */  lui   $t9, %hi(clock_timer) # $t9, 0x8005
/* 0F39F0 7F0BEEC0 1B00003D */  blez  $t8, .L7F0BEFB8
/* 0F39F4 7F0BEEC4 00000000 */   nop   
/* 0F39F8 7F0BEEC8 8F398374 */  lw    $t9, %lo(clock_timer)($t9)
/* 0F39FC 7F0BEECC 1320003A */  beqz  $t9, .L7F0BEFB8
/* 0F3A00 7F0BEED0 00000000 */   nop   
/* 0F3A04 7F0BEED4 0FC26919 */  jal   get_num_players
/* 0F3A08 7F0BEED8 00000000 */   nop   
/* 0F3A0C 7F0BEEDC 00403825 */  move  $a3, $v0
/* 0F3A10 7F0BEEE0 00002825 */  move  $a1, $zero
/* 0F3A14 7F0BEEE4 00003025 */  move  $a2, $zero
/* 0F3A18 7F0BEEE8 18400029 */  blez  $v0, .L7F0BEF90
/* 0F3A1C 7F0BEEEC 00002025 */   move  $a0, $zero
/* 0F3A20 7F0BEEF0 3C038008 */  lui   $v1, %hi(ptr_BONDdata_p1) # $v1, 0x8008
/* 0F3A24 7F0BEEF4 44800000 */  mtc1  $zero, $f0
/* 0F3A28 7F0BEEF8 24639EE0 */  addiu $v1, %lo(ptr_BONDdata_p1) # addiu $v1, $v1, -0x6120
.L7F0BEEFC:
/* 0F3A2C 7F0BEEFC 8C620000 */  lw    $v0, ($v1)
/* 0F3A30 7F0BEF00 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F3A34 7F0BEF04 51E0000E */  beql  $t7, $zero, .L7F0BEF40
/* 0F3A38 7F0BEF08 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F3A3C 7F0BEF0C 8C4E0424 */  lw    $t6, 0x424($v0)
/* 0F3A40 7F0BEF10 51C0000A */  beql  $t6, $zero, .L7F0BEF3C
/* 0F3A44 7F0BEF14 24A50001 */   addiu $a1, $a1, 1
/* 0F3A48 7F0BEF18 8C580428 */  lw    $t8, 0x428($v0)
/* 0F3A4C 7F0BEF1C 53000007 */  beql  $t8, $zero, .L7F0BEF3C
/* 0F3A50 7F0BEF20 24A50001 */   addiu $a1, $a1, 1
/* 0F3A54 7F0BEF24 C44803E4 */  lwc1  $f8, 0x3e4($v0)
/* 0F3A58 7F0BEF28 4608003E */  c.le.s $f0, $f8
/* 0F3A5C 7F0BEF2C 00000000 */  nop   
/* 0F3A60 7F0BEF30 45020003 */  bc1fl .L7F0BEF40
/* 0F3A64 7F0BEF34 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F3A68 7F0BEF38 24A50001 */  addiu $a1, $a1, 1
.L7F0BEF3C:
/* 0F3A6C 7F0BEF3C AFA3001C */  sw    $v1, 0x1c($sp)
.L7F0BEF40:
/* 0F3A70 7F0BEF40 AFA40174 */  sw    $a0, 0x174($sp)
/* 0F3A74 7F0BEF44 AFA50170 */  sw    $a1, 0x170($sp)
/* 0F3A78 7F0BEF48 AFA6016C */  sw    $a2, 0x16c($sp)
/* 0F3A7C 7F0BEF4C 0FC30E36 */  jal   get_points_for_mp_player
/* 0F3A80 7F0BEF50 AFA70178 */   sw    $a3, 0x178($sp)
/* 0F3A84 7F0BEF54 3C198005 */  lui   $t9, %hi(mp_point) # $t9, 0x8005
/* 0F3A88 7F0BEF58 8F39839C */  lw    $t9, %lo(mp_point)($t9)
/* 0F3A8C 7F0BEF5C 44800000 */  mtc1  $zero, $f0
/* 0F3A90 7F0BEF60 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F3A94 7F0BEF64 0059082A */  slt   $at, $v0, $t9
/* 0F3A98 7F0BEF68 8FA40174 */  lw    $a0, 0x174($sp)
/* 0F3A9C 7F0BEF6C 8FA50170 */  lw    $a1, 0x170($sp)
/* 0F3AA0 7F0BEF70 8FA6016C */  lw    $a2, 0x16c($sp)
/* 0F3AA4 7F0BEF74 14200002 */  bnez  $at, .L7F0BEF80
/* 0F3AA8 7F0BEF78 8FA70178 */   lw    $a3, 0x178($sp)
/* 0F3AAC 7F0BEF7C 24C60001 */  addiu $a2, $a2, 1
.L7F0BEF80:
/* 0F3AB0 7F0BEF80 24840001 */  addiu $a0, $a0, 1
/* 0F3AB4 7F0BEF84 0087082A */  slt   $at, $a0, $a3
/* 0F3AB8 7F0BEF88 1420FFDC */  bnez  $at, .L7F0BEEFC
/* 0F3ABC 7F0BEF8C 24630004 */   addiu $v1, $v1, 4
.L7F0BEF90:
/* 0F3AC0 7F0BEF90 18C00009 */  blez  $a2, .L7F0BEFB8
/* 0F3AC4 7F0BEF94 00000000 */   nop   
/* 0F3AC8 7F0BEF98 14A00005 */  bnez  $a1, .L7F0BEFB0
/* 0F3ACC 7F0BEF9C 00000000 */   nop   
/* 0F3AD0 7F0BEFA0 0FC3094C */  jal   sub_GAME_7F0C2530
/* 0F3AD4 7F0BEFA4 00002025 */   move  $a0, $zero
/* 0F3AD8 7F0BEFA8 10000003 */  b     .L7F0BEFB8
/* 0F3ADC 7F0BEFAC 00000000 */   nop   
.L7F0BEFB0:
/* 0F3AE0 7F0BEFB0 0FC30948 */  jal   set_stopplay_flag
/* 0F3AE4 7F0BEFB4 00000000 */   nop   
.L7F0BEFB8:
/* 0F3AE8 7F0BEFB8 0FC051D6 */  jal   get_scenario
/* 0F3AEC 7F0BEFBC 00000000 */   nop   
/* 0F3AF0 7F0BEFC0 24010001 */  li    $at, 1
/* 0F3AF4 7F0BEFC4 14410086 */  bne   $v0, $at, .L7F0BF1E0
/* 0F3AF8 7F0BEFC8 3C0F8005 */   lui   $t7, %hi(clock_timer) # $t7, 0x8005
/* 0F3AFC 7F0BEFCC 8DEF8374 */  lw    $t7, %lo(clock_timer)($t7)
/* 0F3B00 7F0BEFD0 11E00083 */  beqz  $t7, .L7F0BF1E0
/* 0F3B04 7F0BEFD4 00000000 */   nop   
/* 0F3B08 7F0BEFD8 0FC26919 */  jal   get_num_players
/* 0F3B0C 7F0BEFDC 00000000 */   nop   
/* 0F3B10 7F0BEFE0 44800000 */  mtc1  $zero, $f0
/* 0F3B14 7F0BEFE4 00405025 */  move  $t2, $v0
/* 0F3B18 7F0BEFE8 00006825 */  move  $t5, $zero
/* 0F3B1C 7F0BEFEC 0000F825 */  move  $ra, $zero
/* 0F3B20 7F0BEFF0 1840006E */  blez  $v0, .L7F0BF1AC
/* 0F3B24 7F0BEFF4 00006025 */   move  $t4, $zero
/* 0F3B28 7F0BEFF8 00002825 */  move  $a1, $zero
.L7F0BEFFC:
/* 0F3B2C 7F0BEFFC 00003025 */  move  $a2, $zero
/* 0F3B30 7F0BF000 18400048 */  blez  $v0, .L7F0BF124
/* 0F3B34 7F0BF004 00003825 */   move  $a3, $zero
/* 0F3B38 7F0BF008 30490003 */  andi  $t1, $v0, 3
/* 0F3B3C 7F0BF00C 11200019 */  beqz  $t1, .L7F0BF074
/* 0F3B40 7F0BF010 000C5880 */   sll   $t3, $t4, 2
/* 0F3B44 7F0BF014 3C188008 */  lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
/* 0F3B48 7F0BF018 27189EE0 */  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
/* 0F3B4C 7F0BF01C 00007080 */  sll   $t6, $zero, 2
/* 0F3B50 7F0BF020 0000C8C0 */  sll   $t9, $zero, 3
/* 0F3B54 7F0BF024 0320C823 */  subu  $t9, $t9, $zero
/* 0F3B58 7F0BF028 01D81821 */  addu  $v1, $t6, $t8
/* 0F3B5C 7F0BF02C 3C0E8008 */  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
/* 0F3B60 7F0BF030 0019C900 */  sll   $t9, $t9, 4
/* 0F3B64 7F0BF034 032B7821 */  addu  $t7, $t9, $t3
/* 0F3B68 7F0BF038 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0F3B6C 7F0BF03C 01EE2021 */  addu  $a0, $t7, $t6
/* 0F3B70 7F0BF040 01204025 */  move  $t0, $t1
.L7F0BF044:
/* 0F3B74 7F0BF044 8C780000 */  lw    $t8, ($v1)
/* 0F3B78 7F0BF048 24E70001 */  addiu $a3, $a3, 1
/* 0F3B7C 7F0BF04C 24630004 */  addiu $v1, $v1, 4
/* 0F3B80 7F0BF050 8F1900D8 */  lw    $t9, 0xd8($t8)
/* 0F3B84 7F0BF054 57200003 */  bnezl $t9, .L7F0BF064
/* 0F3B88 7F0BF058 8C8F0024 */   lw    $t7, 0x24($a0)
/* 0F3B8C 7F0BF05C 24C60001 */  addiu $a2, $a2, 1
/* 0F3B90 7F0BF060 8C8F0024 */  lw    $t7, 0x24($a0)
.L7F0BF064:
/* 0F3B94 7F0BF064 24840070 */  addiu $a0, $a0, 0x70
/* 0F3B98 7F0BF068 1507FFF6 */  bne   $t0, $a3, .L7F0BF044
/* 0F3B9C 7F0BF06C 00AF2821 */   addu  $a1, $a1, $t7
/* 0F3BA0 7F0BF070 10E2002C */  beq   $a3, $v0, .L7F0BF124
.L7F0BF074:
/* 0F3BA4 7F0BF074 3C188008 */   lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
/* 0F3BA8 7F0BF078 0007C8C0 */  sll   $t9, $a3, 3
/* 0F3BAC 7F0BF07C 0327C823 */  subu  $t9, $t9, $a3
/* 0F3BB0 7F0BF080 27189EE0 */  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
/* 0F3BB4 7F0BF084 00077080 */  sll   $t6, $a3, 2
/* 0F3BB8 7F0BF088 01D81821 */  addu  $v1, $t6, $t8
/* 0F3BBC 7F0BF08C 0019C900 */  sll   $t9, $t9, 4
/* 0F3BC0 7F0BF090 032B7821 */  addu  $t7, $t9, $t3
/* 0F3BC4 7F0BF094 3C0E8008 */  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
/* 0F3BC8 7F0BF098 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0F3BCC 7F0BF09C 000AC880 */  sll   $t9, $t2, 2
/* 0F3BD0 7F0BF0A0 03384021 */  addu  $t0, $t9, $t8
/* 0F3BD4 7F0BF0A4 01EE2021 */  addu  $a0, $t7, $t6
.L7F0BF0A8:
/* 0F3BD8 7F0BF0A8 8C6F0000 */  lw    $t7, ($v1)
/* 0F3BDC 7F0BF0AC 8DEE00D8 */  lw    $t6, 0xd8($t7)
/* 0F3BE0 7F0BF0B0 55C00003 */  bnezl $t6, .L7F0BF0C0
/* 0F3BE4 7F0BF0B4 8C780004 */   lw    $t8, 4($v1)
/* 0F3BE8 7F0BF0B8 24C60001 */  addiu $a2, $a2, 1
/* 0F3BEC 7F0BF0BC 8C780004 */  lw    $t8, 4($v1)
.L7F0BF0C0:
/* 0F3BF0 7F0BF0C0 8C990024 */  lw    $t9, 0x24($a0)
/* 0F3BF4 7F0BF0C4 8F0F00D8 */  lw    $t7, 0xd8($t8)
/* 0F3BF8 7F0BF0C8 00B92821 */  addu  $a1, $a1, $t9
/* 0F3BFC 7F0BF0CC 55E00003 */  bnezl $t7, .L7F0BF0DC
/* 0F3C00 7F0BF0D0 8C790008 */   lw    $t9, 8($v1)
/* 0F3C04 7F0BF0D4 24C60001 */  addiu $a2, $a2, 1
/* 0F3C08 7F0BF0D8 8C790008 */  lw    $t9, 8($v1)
.L7F0BF0DC:
/* 0F3C0C 7F0BF0DC 8C8E0094 */  lw    $t6, 0x94($a0)
/* 0F3C10 7F0BF0E0 8F3800D8 */  lw    $t8, 0xd8($t9)
/* 0F3C14 7F0BF0E4 00AE2821 */  addu  $a1, $a1, $t6
/* 0F3C18 7F0BF0E8 57000003 */  bnezl $t8, .L7F0BF0F8
/* 0F3C1C 7F0BF0EC 8C6E000C */   lw    $t6, 0xc($v1)
/* 0F3C20 7F0BF0F0 24C60001 */  addiu $a2, $a2, 1
/* 0F3C24 7F0BF0F4 8C6E000C */  lw    $t6, 0xc($v1)
.L7F0BF0F8:
/* 0F3C28 7F0BF0F8 8C8F0104 */  lw    $t7, 0x104($a0)
/* 0F3C2C 7F0BF0FC 24630010 */  addiu $v1, $v1, 0x10
/* 0F3C30 7F0BF100 8DD900D8 */  lw    $t9, 0xd8($t6)
/* 0F3C34 7F0BF104 00AF2821 */  addu  $a1, $a1, $t7
/* 0F3C38 7F0BF108 57200003 */  bnezl $t9, .L7F0BF118
/* 0F3C3C 7F0BF10C 8C980174 */   lw    $t8, 0x174($a0)
/* 0F3C40 7F0BF110 24C60001 */  addiu $a2, $a2, 1
/* 0F3C44 7F0BF114 8C980174 */  lw    $t8, 0x174($a0)
.L7F0BF118:
/* 0F3C48 7F0BF118 248401C0 */  addiu $a0, $a0, 0x1c0
/* 0F3C4C 7F0BF11C 1468FFE2 */  bne   $v1, $t0, .L7F0BF0A8
/* 0F3C50 7F0BF120 00B82821 */   addu  $a1, $a1, $t8
.L7F0BF124:
/* 0F3C54 7F0BF124 28A10002 */  slti  $at, $a1, 2
/* 0F3C58 7F0BF128 1420001C */  bnez  $at, .L7F0BF19C
/* 0F3C5C 7F0BF12C 000C78C0 */   sll   $t7, $t4, 3
/* 0F3C60 7F0BF130 01EC7823 */  subu  $t7, $t7, $t4
/* 0F3C64 7F0BF134 3C0E8008 */  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
/* 0F3C68 7F0BF138 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0F3C6C 7F0BF13C 000F7900 */  sll   $t7, $t7, 4
/* 0F3C70 7F0BF140 01EE1821 */  addu  $v1, $t7, $t6
/* 0F3C74 7F0BF144 906F0068 */  lbu   $t7, 0x68($v1)
/* 0F3C78 7F0BF148 3C188008 */  lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
/* 0F3C7C 7F0BF14C 27189EE0 */  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
/* 0F3C80 7F0BF150 000CC880 */  sll   $t9, $t4, 2
/* 0F3C84 7F0BF154 15E00003 */  bnez  $t7, .L7F0BF164
/* 0F3C88 7F0BF158 03382021 */   addu  $a0, $t9, $t8
/* 0F3C8C 7F0BF15C 24CE0001 */  addiu $t6, $a2, 1
/* 0F3C90 7F0BF160 A06E0068 */  sb    $t6, 0x68($v1)
.L7F0BF164:
/* 0F3C94 7F0BF164 8C830000 */  lw    $v1, ($a0)
/* 0F3C98 7F0BF168 25AD0001 */  addiu $t5, $t5, 1
/* 0F3C9C 7F0BF16C 8C790424 */  lw    $t9, 0x424($v1)
/* 0F3CA0 7F0BF170 5320000B */  beql  $t9, $zero, .L7F0BF1A0
/* 0F3CA4 7F0BF174 258C0001 */   addiu $t4, $t4, 1
/* 0F3CA8 7F0BF178 8C780428 */  lw    $t8, 0x428($v1)
/* 0F3CAC 7F0BF17C 53000008 */  beql  $t8, $zero, .L7F0BF1A0
/* 0F3CB0 7F0BF180 258C0001 */   addiu $t4, $t4, 1
/* 0F3CB4 7F0BF184 C46A03E4 */  lwc1  $f10, 0x3e4($v1)
/* 0F3CB8 7F0BF188 4600503C */  c.lt.s $f10, $f0
/* 0F3CBC 7F0BF18C 00000000 */  nop   
/* 0F3CC0 7F0BF190 45020003 */  bc1fl .L7F0BF1A0
/* 0F3CC4 7F0BF194 258C0001 */   addiu $t4, $t4, 1
/* 0F3CC8 7F0BF198 27FF0001 */  addiu $ra, $ra, 1
.L7F0BF19C:
/* 0F3CCC 7F0BF19C 258C0001 */  addiu $t4, $t4, 1
.L7F0BF1A0:
/* 0F3CD0 7F0BF1A0 018A082A */  slt   $at, $t4, $t2
/* 0F3CD4 7F0BF1A4 5420FF95 */  bnezl $at, .L7F0BEFFC
/* 0F3CD8 7F0BF1A8 00002825 */   move  $a1, $zero
.L7F0BF1AC:
/* 0F3CDC 7F0BF1AC 2443FFFF */  addiu $v1, $v0, -1
/* 0F3CE0 7F0BF1B0 03E3082A */  slt   $at, $ra, $v1
/* 0F3CE4 7F0BF1B4 54200006 */  bnezl $at, .L7F0BF1D0
/* 0F3CE8 7F0BF1B8 01A3082A */   slt   $at, $t5, $v1
/* 0F3CEC 7F0BF1BC 0FC3094C */  jal   sub_GAME_7F0C2530
/* 0F3CF0 7F0BF1C0 00002025 */   move  $a0, $zero
/* 0F3CF4 7F0BF1C4 10000006 */  b     .L7F0BF1E0
/* 0F3CF8 7F0BF1C8 00000000 */   nop   
/* 0F3CFC 7F0BF1CC 01A3082A */  slt   $at, $t5, $v1
.L7F0BF1D0:
/* 0F3D00 7F0BF1D0 14200003 */  bnez  $at, .L7F0BF1E0
/* 0F3D04 7F0BF1D4 00000000 */   nop   
/* 0F3D08 7F0BF1D8 0FC30948 */  jal   set_stopplay_flag
/* 0F3D0C 7F0BF1DC 00000000 */   nop   
.L7F0BF1E0:
/* 0F3D10 7F0BF1E0 3C028005 */  lui   $v0, %hi(clock_timer) # $v0, 0x8005
/* 0F3D14 7F0BF1E4 3C0F8005 */  lui   $t7, %hi(D_80048394) # $t7, 0x8005
/* 0F3D18 7F0BF1E8 8DEF8394 */  lw    $t7, %lo(D_80048394)($t7)
/* 0F3D1C 7F0BF1EC 8C428374 */  lw    $v0, %lo(clock_timer)($v0)
/* 0F3D20 7F0BF1F0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F3D24 7F0BF1F4 44810000 */  mtc1  $at, $f0
/* 0F3D28 7F0BF1F8 01E27021 */  addu  $t6, $t7, $v0
/* 0F3D2C 7F0BF1FC 448E8000 */  mtc1  $t6, $f16
/* 0F3D30 7F0BF200 3C018005 */  lui   $at, %hi(D_80048394) # $at, 0x8005
/* 0F3D34 7F0BF204 AC2E8394 */  sw    $t6, %lo(D_80048394)($at)
/* 0F3D38 7F0BF208 468084A0 */  cvt.s.w $f18, $f16
/* 0F3D3C 7F0BF20C 3C038005 */  lui   $v1, %hi(D_800483A8) # $v1, 0x8005
/* 0F3D40 7F0BF210 3C018005 */  lui   $at, %hi(cur_mp_sec) # $at, 0x8005
/* 0F3D44 7F0BF214 246383A8 */  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, -0x7c58
/* 0F3D48 7F0BF218 00002025 */  move  $a0, $zero
/* 0F3D4C 7F0BF21C 3405FFFF */  li    $a1, 65535
/* 0F3D50 7F0BF220 46009103 */  div.s $f4, $f18, $f0
/* 0F3D54 7F0BF224 E42483A4 */  swc1  $f4, %lo(cur_mp_sec)($at)
/* 0F3D58 7F0BF228 8C790000 */  lw    $t9, ($v1)
/* 0F3D5C 7F0BF22C 3C018005 */  lui   $at, %hi(cur_mp_min) # $at, 0x8005
/* 0F3D60 7F0BF230 03227821 */  addu  $t7, $t9, $v0
/* 0F3D64 7F0BF234 448F3000 */  mtc1  $t7, $f6
/* 0F3D68 7F0BF238 AC6F0000 */  sw    $t7, ($v1)
/* 0F3D6C 7F0BF23C 46803220 */  cvt.s.w $f8, $f6
/* 0F3D70 7F0BF240 46004283 */  div.s $f10, $f8, $f0
/* 0F3D74 7F0BF244 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F3D78 7F0BF248 E42A83AC */   swc1  $f10, %lo(cur_mp_min)($at)
/* 0F3D7C 7F0BF24C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F3D80 7F0BF250 44810000 */  mtc1  $at, $f0
/* 0F3D84 7F0BF254 10400009 */  beqz  $v0, .L7F0BF27C
/* 0F3D88 7F0BF258 3C038005 */   lui   $v1, %hi(D_80048390)
/* 0F3D8C 7F0BF25C 3C038005 */  lui   $v1, %hi(D_80048390) # $v1, 0x8005
/* 0F3D90 7F0BF260 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F3D94 7F0BF264 24638390 */  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, -0x7c70
/* 0F3D98 7F0BF268 AC208388 */  sw    $zero, %lo(D_80048388)($at)
/* 0F3D9C 7F0BF26C AC600000 */  sw    $zero, ($v1)
/* 0F3DA0 7F0BF270 3C028005 */  lui   $v0, %hi(clock_timer) # $v0, 0x8005
/* 0F3DA4 7F0BF274 1000000C */  b     .L7F0BF2A8
/* 0F3DA8 7F0BF278 8C428374 */   lw    $v0, %lo(clock_timer)($v0)
.L7F0BF27C:
/* 0F3DAC 7F0BF27C 24638390 */  addiu $v1, $v1, %lo(D_80048390)
/* 0F3DB0 7F0BF280 3C028005 */  lui   $v0, %hi(clock_timer) # $v0, 0x8005
/* 0F3DB4 7F0BF284 8C428374 */  lw    $v0, %lo(clock_timer)($v0)
/* 0F3DB8 7F0BF288 8C6E0000 */  lw    $t6, ($v1)
/* 0F3DBC 7F0BF28C 240F0001 */  li    $t7, 1
/* 0F3DC0 7F0BF290 01C2C821 */  addu  $t9, $t6, $v0
/* 0F3DC4 7F0BF294 2B210708 */  slti  $at, $t9, 0x708
/* 0F3DC8 7F0BF298 14200003 */  bnez  $at, .L7F0BF2A8
/* 0F3DCC 7F0BF29C AC790000 */   sw    $t9, ($v1)
/* 0F3DD0 7F0BF2A0 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F3DD4 7F0BF2A4 AC2F8388 */  sw    $t7, %lo(D_80048388)($at)
.L7F0BF2A8:
/* 0F3DD8 7F0BF2A8 3C0E8005 */  lui   $t6, %hi(D_80048388) # $t6, 0x8005
/* 0F3DDC 7F0BF2AC 8DCE8388 */  lw    $t6, %lo(D_80048388)($t6)
/* 0F3DE0 7F0BF2B0 3C038005 */  lui   $v1, %hi(D_8004838C) # $v1, 0x8005
/* 0F3DE4 7F0BF2B4 2463838C */  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, -0x7c74
/* 0F3DE8 7F0BF2B8 11C00005 */  beqz  $t6, .L7F0BF2D0
/* 0F3DEC 7F0BF2BC 00000000 */   nop   
/* 0F3DF0 7F0BF2C0 8C790000 */  lw    $t9, ($v1)
/* 0F3DF4 7F0BF2C4 0322C021 */  addu  $t8, $t9, $v0
/* 0F3DF8 7F0BF2C8 10000015 */  b     .L7F0BF320
/* 0F3DFC 7F0BF2CC AC780000 */   sw    $t8, ($v1)
.L7F0BF2D0:
/* 0F3E00 7F0BF2D0 3C038005 */  lui   $v1, %hi(D_800483B0) # $v1, 0x8005
/* 0F3E04 7F0BF2D4 246383B0 */  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, -0x7c50
/* 0F3E08 7F0BF2D8 8C6F0000 */  lw    $t7, ($v1)
/* 0F3E0C 7F0BF2DC 3C048005 */  lui   $a0, %hi(D_800483B8) # $a0, 0x8005
/* 0F3E10 7F0BF2E0 3C018005 */  lui   $at, %hi(stage_time_sec) # $at, 0x8005
/* 0F3E14 7F0BF2E4 01E2C821 */  addu  $t9, $t7, $v0
/* 0F3E18 7F0BF2E8 44998000 */  mtc1  $t9, $f16
/* 0F3E1C 7F0BF2EC AC790000 */  sw    $t9, ($v1)
/* 0F3E20 7F0BF2F0 248483B8 */  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, -0x7c48
/* 0F3E24 7F0BF2F4 468084A0 */  cvt.s.w $f18, $f16
/* 0F3E28 7F0BF2F8 46009103 */  div.s $f4, $f18, $f0
/* 0F3E2C 7F0BF2FC E42483B4 */  swc1  $f4, %lo(stage_time_sec)($at)
/* 0F3E30 7F0BF300 8C980000 */  lw    $t8, ($a0)
/* 0F3E34 7F0BF304 3C018005 */  lui   $at, %hi(poweron_time_sec) # $at, 0x8005
/* 0F3E38 7F0BF308 03027021 */  addu  $t6, $t8, $v0
/* 0F3E3C 7F0BF30C 448E3000 */  mtc1  $t6, $f6
/* 0F3E40 7F0BF310 AC8E0000 */  sw    $t6, ($a0)
/* 0F3E44 7F0BF314 46803220 */  cvt.s.w $f8, $f6
/* 0F3E48 7F0BF318 46004283 */  div.s $f10, $f8, $f0
/* 0F3E4C 7F0BF31C E42A83BC */  swc1  $f10, %lo(poweron_time_sec)($at)
.L7F0BF320:
/* 0F3E50 7F0BF320 0C00114D */  jal   set_video2_settings_offset_24
/* 0F3E54 7F0BF324 24040001 */   li    $a0, 1
/* 0F3E58 7F0BF328 3C198005 */  lui   $t9, %hi(current_stage_to_load) # $t9, 0x8005
/* 0F3E5C 7F0BF32C 8F398364 */  lw    $t9, %lo(current_stage_to_load)($t9)
/* 0F3E60 7F0BF330 2401005A */  li    $at, 90
/* 0F3E64 7F0BF334 17210009 */  bne   $t9, $at, .L7F0BF35C
/* 0F3E68 7F0BF338 00000000 */   nop   
/* 0F3E6C 7F0BF33C 0FC2464F */  jal   sub_GAME_7F09193C
/* 0F3E70 7F0BF340 00000000 */   nop   
/* 0F3E74 7F0BF344 0FC06987 */  jal   menu_init
/* 0F3E78 7F0BF348 00000000 */   nop   
/* 0F3E7C 7F0BF34C 0FC30650 */  jal   something_with_LnameJ
/* 0F3E80 7F0BF350 00000000 */   nop   
/* 0F3E84 7F0BF354 100000A9 */  b     .L7F0BF5FC
/* 0F3E88 7F0BF358 00000000 */   nop   
.L7F0BF35C:
/* 0F3E8C 7F0BF35C 0FC26EEF */  jal   sub_GAME_7F09BBBC
/* 0F3E90 7F0BF360 00000000 */   nop   
/* 0F3E94 7F0BF364 0FC2FA34 */  jal   sub_GAME_7F0BE8D0
/* 0F3E98 7F0BF368 00000000 */   nop   
/* 0F3E9C 7F0BF36C 0FC2F1F5 */  jal   sub_GAME_7F0BC7D4
/* 0F3EA0 7F0BF370 00000000 */   nop   
/* 0F3EA4 7F0BF374 0FC24B94 */  jal   sub_GAME_7F092E50
/* 0F3EA8 7F0BF378 00000000 */   nop   
/* 0F3EAC 7F0BF37C 0FC2510E */  jal   sub_GAME_7F094438
/* 0F3EB0 7F0BF380 00000000 */   nop   
/* 0F3EB4 7F0BF384 0FC291FF */  jal   sub_GAME_7F0A47FC
/* 0F3EB8 7F0BF388 00000000 */   nop   
/* 0F3EBC 7F0BF38C 0FC1A39B */  jal   sub_GAME_7F068E6C
/* 0F3EC0 7F0BF390 00000000 */   nop   
/* 0F3EC4 7F0BF394 0FC28A35 */  jal   sub_GAME_7F0A28D4
/* 0F3EC8 7F0BF398 00000000 */   nop   
/* 0F3ECC 7F0BF39C 0FC27F4F */  jal   sub_GAME_7F09FD3C
/* 0F3ED0 7F0BF3A0 00000000 */   nop   
/* 0F3ED4 7F0BF3A4 0FC0F192 */  jal   handle_mp_respawn_and_some_things
/* 0F3ED8 7F0BF3A8 00000000 */   nop   
/* 0F3EDC 7F0BF3AC 0FC304F2 */  jal   reset_all_music_slots
/* 0F3EE0 7F0BF3B0 00000000 */   nop   
/* 0F3EE4 7F0BF3B4 0FC30650 */  jal   something_with_LnameJ
/* 0F3EE8 7F0BF3B8 00000000 */   nop   
/* 0F3EEC 7F0BF3BC 0FC243EE */  jal   get_debug_joy2detailedit_flag
/* 0F3EF0 7F0BF3C0 00000000 */   nop   
/* 0F3EF4 7F0BF3C4 1040004D */  beqz  $v0, .L7F0BF4FC
/* 0F3EF8 7F0BF3C8 3C068005 */   lui   $a2, %hi(D_800483C8) # $a2, 0x8005
/* 0F3EFC 7F0BF3CC 24C683C8 */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
/* 0F3F00 7F0BF3D0 8CD80000 */  lw    $t8, ($a2)
/* 0F3F04 7F0BF3D4 24043000 */  li    $a0, 12288
/* 0F3F08 7F0BF3D8 17000048 */  bnez  $t8, .L7F0BF4FC
/* 0F3F0C 7F0BF3DC 00000000 */   nop   
/* 0F3F10 7F0BF3E0 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F3F14 7F0BF3E4 24050004 */   li    $a1, 4
/* 0F3F18 7F0BF3E8 3C068005 */  lui   $a2, %hi(D_800483C8) # $a2, 0x8005
/* 0F3F1C 7F0BF3EC 24C683C8 */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
/* 0F3F20 7F0BF3F0 10400042 */  beqz  $v0, .L7F0BF4FC
/* 0F3F24 7F0BF3F4 ACC20000 */   sw    $v0, ($a2)
/* 0F3F28 7F0BF3F8 00001825 */  move  $v1, $zero
/* 0F3F2C 7F0BF3FC 24052EE0 */  li    $a1, 12000
/* 0F3F30 7F0BF400 240400FF */  li    $a0, 255
.L7F0BF404:
/* 0F3F34 7F0BF404 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F38 7F0BF408 01C3C821 */  addu  $t9, $t6, $v1
/* 0F3F3C 7F0BF40C A3240000 */  sb    $a0, ($t9)
/* 0F3F40 7F0BF410 8CD80000 */  lw    $t8, ($a2)
/* 0F3F44 7F0BF414 03031021 */  addu  $v0, $t8, $v1
/* 0F3F48 7F0BF418 904F0001 */  lbu   $t7, 1($v0)
/* 0F3F4C 7F0BF41C 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F3F50 7F0BF420 35D90020 */  ori   $t9, $t6, 0x20
/* 0F3F54 7F0BF424 A0590001 */  sb    $t9, 1($v0)
/* 0F3F58 7F0BF428 8CD80000 */  lw    $t8, ($a2)
/* 0F3F5C 7F0BF42C 03031021 */  addu  $v0, $t8, $v1
/* 0F3F60 7F0BF430 904F0001 */  lbu   $t7, 1($v0)
/* 0F3F64 7F0BF434 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F3F68 7F0BF438 35D90004 */  ori   $t9, $t6, 4
/* 0F3F6C 7F0BF43C A0590001 */  sb    $t9, 1($v0)
/* 0F3F70 7F0BF440 8CD80000 */  lw    $t8, ($a2)
/* 0F3F74 7F0BF444 03037821 */  addu  $t7, $t8, $v1
/* 0F3F78 7F0BF448 A1E40004 */  sb    $a0, 4($t7)
/* 0F3F7C 7F0BF44C 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F80 7F0BF450 01C31021 */  addu  $v0, $t6, $v1
/* 0F3F84 7F0BF454 90590005 */  lbu   $t9, 5($v0)
/* 0F3F88 7F0BF458 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F3F8C 7F0BF45C 370F0020 */  ori   $t7, $t8, 0x20
/* 0F3F90 7F0BF460 A04F0005 */  sb    $t7, 5($v0)
/* 0F3F94 7F0BF464 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F98 7F0BF468 01C31021 */  addu  $v0, $t6, $v1
/* 0F3F9C 7F0BF46C 90590005 */  lbu   $t9, 5($v0)
/* 0F3FA0 7F0BF470 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F3FA4 7F0BF474 370F0004 */  ori   $t7, $t8, 4
/* 0F3FA8 7F0BF478 A04F0005 */  sb    $t7, 5($v0)
/* 0F3FAC 7F0BF47C 8CCE0000 */  lw    $t6, ($a2)
/* 0F3FB0 7F0BF480 01C3C821 */  addu  $t9, $t6, $v1
/* 0F3FB4 7F0BF484 A3240008 */  sb    $a0, 8($t9)
/* 0F3FB8 7F0BF488 8CD80000 */  lw    $t8, ($a2)
/* 0F3FBC 7F0BF48C 03031021 */  addu  $v0, $t8, $v1
/* 0F3FC0 7F0BF490 904F0009 */  lbu   $t7, 9($v0)
/* 0F3FC4 7F0BF494 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F3FC8 7F0BF498 35D90020 */  ori   $t9, $t6, 0x20
/* 0F3FCC 7F0BF49C A0590009 */  sb    $t9, 9($v0)
/* 0F3FD0 7F0BF4A0 8CD80000 */  lw    $t8, ($a2)
/* 0F3FD4 7F0BF4A4 03031021 */  addu  $v0, $t8, $v1
/* 0F3FD8 7F0BF4A8 904F0009 */  lbu   $t7, 9($v0)
/* 0F3FDC 7F0BF4AC 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F3FE0 7F0BF4B0 35D90004 */  ori   $t9, $t6, 4
/* 0F3FE4 7F0BF4B4 A0590009 */  sb    $t9, 9($v0)
/* 0F3FE8 7F0BF4B8 8CD80000 */  lw    $t8, ($a2)
/* 0F3FEC 7F0BF4BC 03037821 */  addu  $t7, $t8, $v1
/* 0F3FF0 7F0BF4C0 A1E4000C */  sb    $a0, 0xc($t7)
/* 0F3FF4 7F0BF4C4 8CCE0000 */  lw    $t6, ($a2)
/* 0F3FF8 7F0BF4C8 01C31021 */  addu  $v0, $t6, $v1
/* 0F3FFC 7F0BF4CC 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4000 7F0BF4D0 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F4004 7F0BF4D4 370F0020 */  ori   $t7, $t8, 0x20
/* 0F4008 7F0BF4D8 A04F000D */  sb    $t7, 0xd($v0)
/* 0F400C 7F0BF4DC 8CCE0000 */  lw    $t6, ($a2)
/* 0F4010 7F0BF4E0 01C31021 */  addu  $v0, $t6, $v1
/* 0F4014 7F0BF4E4 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4018 7F0BF4E8 24630010 */  addiu $v1, $v1, 0x10
/* 0F401C 7F0BF4EC 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F4020 7F0BF4F0 370F0004 */  ori   $t7, $t8, 4
/* 0F4024 7F0BF4F4 1465FFC3 */  bne   $v1, $a1, .L7F0BF404
/* 0F4028 7F0BF4F8 A04F000D */   sb    $t7, 0xd($v0)
.L7F0BF4FC:
/* 0F402C 7F0BF4FC 0FC2440F */  jal   get_debug_portal_flag
/* 0F4030 7F0BF500 00000000 */   nop   
/* 0F4034 7F0BF504 10400003 */  beqz  $v0, .L7F0BF514
/* 0F4038 7F0BF508 00000000 */   nop   
/* 0F403C 7F0BF50C 0FC2F7C4 */  jal   sub_GAME_7F0BDF10
/* 0F4040 7F0BF510 00002025 */   move  $a0, $zero
.L7F0BF514:
/* 0F4044 7F0BF514 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4048 7F0BF518 00000000 */   nop   
/* 0F404C 7F0BF51C 24010004 */  li    $at, 4
/* 0F4050 7F0BF520 10410006 */  beq   $v0, $at, .L7F0BF53C
/* 0F4054 7F0BF524 00002025 */   move  $a0, $zero
/* 0F4058 7F0BF528 24010008 */  li    $at, 8
/* 0F405C 7F0BF52C 1041001A */  beq   $v0, $at, .L7F0BF598
/* 0F4060 7F0BF530 00002025 */   move  $a0, $zero
/* 0F4064 7F0BF534 10000031 */  b     .L7F0BF5FC
/* 0F4068 7F0BF538 00000000 */   nop   
.L7F0BF53C:
/* 0F406C 7F0BF53C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4070 7F0BF540 24050002 */   li    $a1, 2
/* 0F4074 7F0BF544 50400008 */  beql  $v0, $zero, .L7F0BF568
/* 0F4078 7F0BF548 00002025 */   move  $a0, $zero
/* 0F407C 7F0BF54C 0FC2BD8C */  jal   sub_GAME_7F0AF630
/* 0F4080 7F0BF550 2404FFFF */   li    $a0, -1
/* 0F4084 7F0BF554 00002025 */  move  $a0, $zero
/* 0F4088 7F0BF558 00002825 */  move  $a1, $zero
/* 0F408C 7F0BF55C 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4090 7F0BF560 00003025 */   move  $a2, $zero
/* 0F4094 7F0BF564 00002025 */  move  $a0, $zero
.L7F0BF568:
/* 0F4098 7F0BF568 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F409C 7F0BF56C 24050001 */   li    $a1, 1
/* 0F40A0 7F0BF570 10400022 */  beqz  $v0, .L7F0BF5FC
/* 0F40A4 7F0BF574 00000000 */   nop   
/* 0F40A8 7F0BF578 0FC2BD8C */  jal   sub_GAME_7F0AF630
/* 0F40AC 7F0BF57C 24040001 */   li    $a0, 1
/* 0F40B0 7F0BF580 00002025 */  move  $a0, $zero
/* 0F40B4 7F0BF584 00002825 */  move  $a1, $zero
/* 0F40B8 7F0BF588 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F40BC 7F0BF58C 00003025 */   move  $a2, $zero
/* 0F40C0 7F0BF590 1000001A */  b     .L7F0BF5FC
/* 0F40C4 7F0BF594 00000000 */   nop   
.L7F0BF598:
/* 0F40C8 7F0BF598 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F40CC 7F0BF59C 24050002 */   li    $a1, 2
/* 0F40D0 7F0BF5A0 50400004 */  beql  $v0, $zero, .L7F0BF5B4
/* 0F40D4 7F0BF5A4 00002025 */   move  $a0, $zero
/* 0F40D8 7F0BF5A8 0FC08B8C */  jal   sub_GAME_7F022E30
/* 0F40DC 7F0BF5AC 00000000 */   nop   
/* 0F40E0 7F0BF5B0 00002025 */  move  $a0, $zero
.L7F0BF5B4:
/* 0F40E4 7F0BF5B4 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F40E8 7F0BF5B8 24050001 */   li    $a1, 1
/* 0F40EC 7F0BF5BC 50400004 */  beql  $v0, $zero, .L7F0BF5D0
/* 0F40F0 7F0BF5C0 00002025 */   move  $a0, $zero
/* 0F40F4 7F0BF5C4 0FC08BA4 */  jal   sub_GAME_7F022E90
/* 0F40F8 7F0BF5C8 00000000 */   nop   
/* 0F40FC 7F0BF5CC 00002025 */  move  $a0, $zero
.L7F0BF5D0:
/* 0F4100 7F0BF5D0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4104 7F0BF5D4 24050020 */   li    $a1, 32
/* 0F4108 7F0BF5D8 50400004 */  beql  $v0, $zero, .L7F0BF5EC
/* 0F410C 7F0BF5DC 00002025 */   move  $a0, $zero
/* 0F4110 7F0BF5E0 0FC08BB2 */  jal   sub_GAME_7F022EC8
/* 0F4114 7F0BF5E4 00000000 */   nop   
/* 0F4118 7F0BF5E8 00002025 */  move  $a0, $zero
.L7F0BF5EC:
/* 0F411C 7F0BF5EC 0C0030C3 */  jal   get_controller_buttons_held
/* 0F4120 7F0BF5F0 24050010 */   li    $a1, 16
/* 0F4124 7F0BF5F4 0FC08BB8 */  jal   sub_GAME_7F022EE0
/* 0F4128 7F0BF5F8 0002202B */   sltu  $a0, $zero, $v0
.L7F0BF5FC:
/* 0F412C 7F0BF5FC 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4130 7F0BF600 00000000 */   nop   
/* 0F4134 7F0BF604 2401000C */  li    $at, 12
/* 0F4138 7F0BF608 1041002E */  beq   $v0, $at, .L7F0BF6C4
/* 0F413C 7F0BF60C 00002025 */   move  $a0, $zero
/* 0F4140 7F0BF610 2401000D */  li    $at, 13
/* 0F4144 7F0BF614 10410048 */  beq   $v0, $at, .L7F0BF738
/* 0F4148 7F0BF618 00002025 */   move  $a0, $zero
/* 0F414C 7F0BF61C 24010038 */  li    $at, 56
/* 0F4150 7F0BF620 54410074 */  bnel  $v0, $at, .L7F0BF7F4
/* 0F4154 7F0BF624 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4158 7F0BF628 0C0010EA */  jal   get_D_8002329C
/* 0F415C 7F0BF62C 00000000 */   nop   
/* 0F4160 7F0BF630 0C0010E4 */  jal   get_D_800232A0
/* 0F4164 7F0BF634 AFA20030 */   sw    $v0, 0x30($sp)
/* 0F4168 7F0BF638 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F416C 7F0BF63C 00002025 */  move  $a0, $zero
/* 0F4170 7F0BF640 0C0030C3 */  jal   get_controller_buttons_held
/* 0F4174 7F0BF644 24050004 */   li    $a1, 4
/* 0F4178 7F0BF648 10400004 */  beqz  $v0, .L7F0BF65C
/* 0F417C 7F0BF64C 00002025 */   move  $a0, $zero
/* 0F4180 7F0BF650 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0F4184 7F0BF654 25D90001 */  addiu $t9, $t6, 1
/* 0F4188 7F0BF658 AFB9002C */  sw    $t9, 0x2c($sp)
.L7F0BF65C:
/* 0F418C 7F0BF65C 0C0030C3 */  jal   get_controller_buttons_held
/* 0F4190 7F0BF660 24050008 */   li    $a1, 8
/* 0F4194 7F0BF664 10400004 */  beqz  $v0, .L7F0BF678
/* 0F4198 7F0BF668 00002025 */   move  $a0, $zero
/* 0F419C 7F0BF66C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0F41A0 7F0BF670 270FFFFF */  addiu $t7, $t8, -1
/* 0F41A4 7F0BF674 AFAF002C */  sw    $t7, 0x2c($sp)
.L7F0BF678:
/* 0F41A8 7F0BF678 0C0030C3 */  jal   get_controller_buttons_held
/* 0F41AC 7F0BF67C 24050001 */   li    $a1, 1
/* 0F41B0 7F0BF680 10400004 */  beqz  $v0, .L7F0BF694
/* 0F41B4 7F0BF684 00002025 */   move  $a0, $zero
/* 0F41B8 7F0BF688 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0F41BC 7F0BF68C 25D90001 */  addiu $t9, $t6, 1
/* 0F41C0 7F0BF690 AFB90030 */  sw    $t9, 0x30($sp)
.L7F0BF694:
/* 0F41C4 7F0BF694 0C0030C3 */  jal   get_controller_buttons_held
/* 0F41C8 7F0BF698 24050002 */   li    $a1, 2
/* 0F41CC 7F0BF69C 10400003 */  beqz  $v0, .L7F0BF6AC
/* 0F41D0 7F0BF6A0 8FB80030 */   lw    $t8, 0x30($sp)
/* 0F41D4 7F0BF6A4 270FFFFF */  addiu $t7, $t8, -1
/* 0F41D8 7F0BF6A8 AFAF0030 */  sw    $t7, 0x30($sp)
.L7F0BF6AC:
/* 0F41DC 7F0BF6AC 0C0010E7 */  jal   set_D_8002329C
/* 0F41E0 7F0BF6B0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0F41E4 7F0BF6B4 0C0010E1 */  jal   set_D_800232A0
/* 0F41E8 7F0BF6B8 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0F41EC 7F0BF6BC 1000004D */  b     .L7F0BF7F4
/* 0F41F0 7F0BF6C0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BF6C4:
/* 0F41F4 7F0BF6C4 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F41F8 7F0BF6C8 24050202 */   li    $a1, 514
/* 0F41FC 7F0BF6CC 50400004 */  beql  $v0, $zero, .L7F0BF6E0
/* 0F4200 7F0BF6D0 00002025 */   move  $a0, $zero
/* 0F4204 7F0BF6D4 0FC2F68E */  jal   sub_GAME_7F0BDA38
/* 0F4208 7F0BF6D8 00000000 */   nop   
/* 0F420C 7F0BF6DC 00002025 */  move  $a0, $zero
.L7F0BF6E0:
/* 0F4210 7F0BF6E0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4214 7F0BF6E4 24050101 */   li    $a1, 257
/* 0F4218 7F0BF6E8 50400004 */  beql  $v0, $zero, .L7F0BF6FC
/* 0F421C 7F0BF6EC 00002025 */   move  $a0, $zero
/* 0F4220 7F0BF6F0 0FC2F67B */  jal   sub_GAME_7F0BD9EC
/* 0F4224 7F0BF6F4 00000000 */   nop   
/* 0F4228 7F0BF6F8 00002025 */  move  $a0, $zero
.L7F0BF6FC:
/* 0F422C 7F0BF6FC 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4230 7F0BF700 24050400 */   li    $a1, 1024
/* 0F4234 7F0BF704 50400004 */  beql  $v0, $zero, .L7F0BF718
/* 0F4238 7F0BF708 00002025 */   move  $a0, $zero
/* 0F423C 7F0BF70C 0C001BF4 */  jal   musicTrack1Stop
/* 0F4240 7F0BF710 00000000 */   nop   
/* 0F4244 7F0BF714 00002025 */  move  $a0, $zero
.L7F0BF718:
/* 0F4248 7F0BF718 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F424C 7F0BF71C 24054000 */   li    $a1, 16384
/* 0F4250 7F0BF720 50400034 */  beql  $v0, $zero, .L7F0BF7F4
/* 0F4254 7F0BF724 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4258 7F0BF728 0C001C28 */  jal   musicTrack1Tempo
/* 0F425C 7F0BF72C 00000000 */   nop   
/* 0F4260 7F0BF730 10000030 */  b     .L7F0BF7F4
/* 0F4264 7F0BF734 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BF738:
/* 0F4268 7F0BF738 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F426C 7F0BF73C 24050622 */   li    $a1, 1570
/* 0F4270 7F0BF740 1040000B */  beqz  $v0, .L7F0BF770
/* 0F4274 7F0BF744 3C058005 */   lui   $a1, 0x8005
/* 0F4278 7F0BF748 84A583E4 */  lh    $a1, %lo(D_800483E4)($a1)
/* 0F427C 7F0BF74C 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0F4280 7F0BF750 3C018005 */  lui   $at, %hi(D_800483E4) # $at, 0x8005
/* 0F4284 7F0BF754 24A5FFFF */  addiu $a1, $a1, -1
/* 0F4288 7F0BF758 00057400 */  sll   $t6, $a1, 0x10
/* 0F428C 7F0BF75C 000E2C03 */  sra   $a1, $t6, 0x10
/* 0F4290 7F0BF760 A42583E4 */  sh    $a1, %lo(D_800483E4)($at)
/* 0F4294 7F0BF764 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0F4298 7F0BF768 0C002382 */  jal   play_sfx_a1
/* 0F429C 7F0BF76C 00003025 */   move  $a2, $zero
.L7F0BF770:
/* 0F42A0 7F0BF770 00002025 */  move  $a0, $zero
/* 0F42A4 7F0BF774 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F42A8 7F0BF778 24050911 */   li    $a1, 2321
/* 0F42AC 7F0BF77C 1040000B */  beqz  $v0, .L7F0BF7AC
/* 0F42B0 7F0BF780 3C058005 */   lui   $a1, 0x8005
/* 0F42B4 7F0BF784 84A583E4 */  lh    $a1, %lo(D_800483E4)($a1)
/* 0F42B8 7F0BF788 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0F42BC 7F0BF78C 3C018005 */  lui   $at, %hi(D_800483E4) # $at, 0x8005
/* 0F42C0 7F0BF790 24A50001 */   addiu $a1, $a1, 1
/* 0F42C4 7F0BF794 0005C400 */  sll   $t8, $a1, 0x10
/* 0F42C8 7F0BF798 00182C03 */  sra   $a1, $t8, 0x10
/* 0F42CC 7F0BF79C A42583E4 */  sh    $a1, %lo(D_800483E4)($at)
/* 0F42D0 7F0BF7A0 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0F42D4 7F0BF7A4 0C002382 */  jal   play_sfx_a1
/* 0F42D8 7F0BF7A8 00003025 */   move  $a2, $zero
.L7F0BF7AC:
/* 0F42DC 7F0BF7AC 00002025 */  move  $a0, $zero
/* 0F42E0 7F0BF7B0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F42E4 7F0BF7B4 24050004 */   li    $a1, 4
/* 0F42E8 7F0BF7B8 50400004 */  beql  $v0, $zero, .L7F0BF7CC
/* 0F42EC 7F0BF7BC 00002025 */   move  $a0, $zero
/* 0F42F0 7F0BF7C0 0C002449 */  jal   sfx_c_70009124
/* 0F42F4 7F0BF7C4 00000000 */   nop   
/* 0F42F8 7F0BF7C8 00002025 */  move  $a0, $zero
.L7F0BF7CC:
/* 0F42FC 7F0BF7CC 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4300 7F0BF7D0 24050008 */   li    $a1, 8
/* 0F4304 7F0BF7D4 10400006 */  beqz  $v0, .L7F0BF7F0
/* 0F4308 7F0BF7D8 3C058005 */   lui   $a1, %hi(D_800483E4) # $a1, 0x8005
/* 0F430C 7F0BF7DC 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0F4310 7F0BF7E0 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0F4314 7F0BF7E4 84A583E4 */  lh    $a1, %lo(D_800483E4)($a1)
/* 0F4318 7F0BF7E8 0C002382 */  jal   play_sfx_a1
/* 0F431C 7F0BF7EC 00003025 */   move  $a2, $zero
.L7F0BF7F0:
/* 0F4320 7F0BF7F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BF7F4:
/* 0F4324 7F0BF7F4 27BD0198 */  addiu $sp, $sp, 0x198
/* 0F4328 7F0BF7F8 03E00008 */  jr    $ra
/* 0F432C 7F0BF7FC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BF800(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BF800
/* 0F4330 7F0BF800 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F4334 7F0BF804 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F4338 7F0BF808 0FC26C54 */  jal   get_cur_playernum
/* 0F433C 7F0BF80C 00000000 */   nop   
/* 0F4340 7F0BF810 0FC2464F */  jal   sub_GAME_7F09193C
/* 0F4344 7F0BF814 A3A2002F */   sb    $v0, 0x2f($sp)
/* 0F4348 7F0BF818 0FC243C2 */  jal   get_debug_freeze_processing
/* 0F434C 7F0BF81C 00000000 */   nop   
/* 0F4350 7F0BF820 10400007 */  beqz  $v0, .L7F0BF840
/* 0F4354 7F0BF824 24010001 */   li    $at, 1
/* 0F4358 7F0BF828 1041002D */  beq   $v0, $at, .L7F0BF8E0
/* 0F435C 7F0BF82C 24010002 */   li    $at, 2
/* 0F4360 7F0BF830 1041004C */  beq   $v0, $at, .L7F0BF964
/* 0F4364 7F0BF834 00000000 */   nop   
/* 0F4368 7F0BF838 1000006B */  b     .L7F0BF9E8
/* 0F436C 7F0BF83C 00000000 */   nop   
.L7F0BF840:
/* 0F4370 7F0BF840 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4374 7F0BF844 00000000 */   nop   
/* 0F4378 7F0BF848 10400009 */  beqz  $v0, .L7F0BF870
/* 0F437C 7F0BF84C 00000000 */   nop   
/* 0F4380 7F0BF850 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4384 7F0BF854 00000000 */   nop   
/* 0F4388 7F0BF858 2401003B */  li    $at, 59
/* 0F438C 7F0BF85C 14410013 */  bne   $v0, $at, .L7F0BF8AC
/* 0F4390 7F0BF860 3C0E8003 */   lui   $t6, %hi(D_80036ABC) # $t6, 0x8003
/* 0F4394 7F0BF864 8DCE6ABC */  lw    $t6, %lo(D_80036ABC)($t6)
/* 0F4398 7F0BF868 05C10010 */  bgez  $t6, .L7F0BF8AC
/* 0F439C 7F0BF86C 00000000 */   nop   
.L7F0BF870:
/* 0F43A0 7F0BF870 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F43A4 7F0BF874 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43A8 7F0BF878 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F43AC 7F0BF87C 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F43B0 7F0BF880 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43B4 7F0BF884 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F43B8 7F0BF888 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F43BC 7F0BF88C 0C0030C3 */  jal   get_controller_buttons_held
/* 0F43C0 7F0BF890 3405FFFF */   li    $a1, 65535
/* 0F43C4 7F0BF894 83A40018 */  lb    $a0, 0x18($sp)
/* 0F43C8 7F0BF898 83A50019 */  lb    $a1, 0x19($sp)
/* 0F43CC 7F0BF89C 0FC24420 */  jal   sub_GAME_7F091080
/* 0F43D0 7F0BF8A0 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F43D4 7F0BF8A4 10000050 */  b     .L7F0BF9E8
/* 0F43D8 7F0BF8A8 00000000 */   nop   
.L7F0BF8AC:
/* 0F43DC 7F0BF8AC 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F43E0 7F0BF8B0 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43E4 7F0BF8B4 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F43E8 7F0BF8B8 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F43EC 7F0BF8BC 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43F0 7F0BF8C0 00022E00 */  sll   $a1, $v0, 0x18
/* 0F43F4 7F0BF8C4 00057E03 */  sra   $t7, $a1, 0x18
/* 0F43F8 7F0BF8C8 01E02825 */  move  $a1, $t7
/* 0F43FC 7F0BF8CC 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4400 7F0BF8D0 0FC24420 */  jal   sub_GAME_7F091080
/* 0F4404 7F0BF8D4 00003025 */   move  $a2, $zero
/* 0F4408 7F0BF8D8 10000043 */  b     .L7F0BF9E8
/* 0F440C 7F0BF8DC 00000000 */   nop   
.L7F0BF8E0:
/* 0F4410 7F0BF8E0 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4414 7F0BF8E4 00000000 */   nop   
/* 0F4418 7F0BF8E8 24010001 */  li    $at, 1
/* 0F441C 7F0BF8EC 14410010 */  bne   $v0, $at, .L7F0BF930
/* 0F4420 7F0BF8F0 00000000 */   nop   
/* 0F4424 7F0BF8F4 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F4428 7F0BF8F8 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F442C 7F0BF8FC A3A20018 */  sb    $v0, 0x18($sp)
/* 0F4430 7F0BF900 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F4434 7F0BF904 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4438 7F0BF908 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F443C 7F0BF90C 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F4440 7F0BF910 0C0030C3 */  jal   get_controller_buttons_held
/* 0F4444 7F0BF914 3405FFFF */   li    $a1, 65535
/* 0F4448 7F0BF918 83A40018 */  lb    $a0, 0x18($sp)
/* 0F444C 7F0BF91C 83A50019 */  lb    $a1, 0x19($sp)
/* 0F4450 7F0BF920 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4454 7F0BF924 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F4458 7F0BF928 1000002F */  b     .L7F0BF9E8
/* 0F445C 7F0BF92C 00000000 */   nop   
.L7F0BF930:
/* 0F4460 7F0BF930 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F4464 7F0BF934 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4468 7F0BF938 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F446C 7F0BF93C 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F4470 7F0BF940 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4474 7F0BF944 00022E00 */  sll   $a1, $v0, 0x18
/* 0F4478 7F0BF948 0005C603 */  sra   $t8, $a1, 0x18
/* 0F447C 7F0BF94C 03002825 */  move  $a1, $t8
/* 0F4480 7F0BF950 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4484 7F0BF954 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4488 7F0BF958 00003025 */   move  $a2, $zero
/* 0F448C 7F0BF95C 10000022 */  b     .L7F0BF9E8
/* 0F4490 7F0BF960 00000000 */   nop   
.L7F0BF964:
/* 0F4494 7F0BF964 0FC243C5 */  jal   get_debug_limit_controller_input
/* 0F4498 7F0BF968 00000000 */   nop   
/* 0F449C 7F0BF96C 24010002 */  li    $at, 2
/* 0F44A0 7F0BF970 14410010 */  bne   $v0, $at, .L7F0BF9B4
/* 0F44A4 7F0BF974 00000000 */   nop   
/* 0F44A8 7F0BF978 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F44AC 7F0BF97C 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44B0 7F0BF980 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F44B4 7F0BF984 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F44B8 7F0BF988 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44BC 7F0BF98C A3A20019 */  sb    $v0, 0x19($sp)
/* 0F44C0 7F0BF990 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F44C4 7F0BF994 0C0030C3 */  jal   get_controller_buttons_held
/* 0F44C8 7F0BF998 3405FFFF */   li    $a1, 65535
/* 0F44CC 7F0BF99C 83A40018 */  lb    $a0, 0x18($sp)
/* 0F44D0 7F0BF9A0 83A50019 */  lb    $a1, 0x19($sp)
/* 0F44D4 7F0BF9A4 0FC21BE7 */  jal   possibly_reset_viewport_options_for_player
/* 0F44D8 7F0BF9A8 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F44DC 7F0BF9AC 1000000C */  b     .L7F0BF9E0
/* 0F44E0 7F0BF9B0 00000000 */   nop   
.L7F0BF9B4:
/* 0F44E4 7F0BF9B4 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 0F44E8 7F0BF9B8 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44EC 7F0BF9BC A3A20018 */  sb    $v0, 0x18($sp)
/* 0F44F0 7F0BF9C0 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 0F44F4 7F0BF9C4 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44F8 7F0BF9C8 00022E00 */  sll   $a1, $v0, 0x18
/* 0F44FC 7F0BF9CC 0005CE03 */  sra   $t9, $a1, 0x18
/* 0F4500 7F0BF9D0 03202825 */  move  $a1, $t9
/* 0F4504 7F0BF9D4 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4508 7F0BF9D8 0FC21BE7 */  jal   possibly_reset_viewport_options_for_player
/* 0F450C 7F0BF9DC 00003025 */   move  $a2, $zero
.L7F0BF9E0:
/* 0F4510 7F0BF9E0 0FC30BA0 */  jal   sub_GAME_7F0C2E80
/* 0F4514 7F0BF9E4 00000000 */   nop   
.L7F0BF9E8:
/* 0F4518 7F0BF9E8 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0F451C 7F0BF9EC 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0F4520 7F0BF9F0 8C4300A8 */  lw    $v1, 0xa8($v0)
/* 0F4524 7F0BF9F4 C4460408 */  lwc1  $f6, 0x408($v0)
/* 0F4528 7F0BF9F8 C44A0410 */  lwc1  $f10, 0x410($v0)
/* 0F452C 7F0BF9FC C4640008 */  lwc1  $f4, 8($v1)
/* 0F4530 7F0BFA00 C4680010 */  lwc1  $f8, 0x10($v1)
/* 0F4534 7F0BFA04 46062001 */  sub.s $f0, $f4, $f6
/* 0F4538 7F0BFA08 460A4081 */  sub.s $f2, $f8, $f10
/* 0F453C 7F0BFA0C 46000402 */  mul.s $f16, $f0, $f0
/* 0F4540 7F0BFA10 00000000 */  nop   
/* 0F4544 7F0BFA14 46021482 */  mul.s $f18, $f2, $f2
/* 0F4548 7F0BFA18 0C007DF8 */  jal   sqrtf
/* 0F454C 7F0BFA1C 46128300 */   add.s $f12, $f16, $f18
/* 0F4550 7F0BFA20 3C028008 */  lui   $v0, %hi(cur_player_stat_ptr) # $v0, 0x8008
/* 0F4554 7F0BFA24 8C42A0B4 */  lw    $v0, %lo(cur_player_stat_ptr)($v0)
/* 0F4558 7F0BFA28 C4440038 */  lwc1  $f4, 0x38($v0)
/* 0F455C 7F0BFA2C 46002180 */  add.s $f6, $f4, $f0
/* 0F4560 7F0BFA30 0FC051D6 */  jal   get_scenario
/* 0F4564 7F0BFA34 E4460038 */   swc1  $f6, 0x38($v0)
/* 0F4568 7F0BFA38 24010002 */  li    $at, 2
/* 0F456C 7F0BFA3C 14410024 */  bne   $v0, $at, .L7F0BFAD0
/* 0F4570 7F0BFA40 00000000 */   nop   
/* 0F4574 7F0BFA44 0FC233E0 */  jal   sub_GAME_7F08CF80
/* 0F4578 7F0BFA48 00000000 */   nop   
/* 0F457C 7F0BFA4C 1040001C */  beqz  $v0, .L7F0BFAC0
/* 0F4580 7F0BFA50 00000000 */   nop   
/* 0F4584 7F0BFA54 0FC17674 */  jal   get_item_in_hand
/* 0F4588 7F0BFA58 00002025 */   move  $a0, $zero
/* 0F458C 7F0BFA5C 24010058 */  li    $at, 88
/* 0F4590 7F0BFA60 1041000B */  beq   $v0, $at, .L7F0BFA90
/* 0F4594 7F0BFA64 00002025 */   move  $a0, $zero
/* 0F4598 7F0BFA68 0FC17645 */  jal   draw_item_in_hand_has_more_ammo
/* 0F459C 7F0BFA6C 24050058 */   li    $a1, 88
/* 0F45A0 7F0BFA70 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0F45A4 7F0BFA74 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0F45A8 7F0BFA78 24010002 */  li    $at, 2
/* 0F45AC 7F0BFA7C 24090005 */  li    $t1, 5
/* 0F45B0 7F0BFA80 8C480894 */  lw    $t0, 0x894($v0)
/* 0F45B4 7F0BFA84 15010002 */  bne   $t0, $at, .L7F0BFA90
/* 0F45B8 7F0BFA88 00000000 */   nop   
/* 0F45BC 7F0BFA8C AC490894 */  sw    $t1, 0x894($v0)
.L7F0BFA90:
/* 0F45C0 7F0BFA90 3C038008 */  lui   $v1, %hi(cur_player_stat_ptr) # $v1, 0x8008
/* 0F45C4 7F0BFA94 2463A0B4 */  addiu $v1, %lo(cur_player_stat_ptr) # addiu $v1, $v1, -0x5f4c
/* 0F45C8 7F0BFA98 8C620000 */  lw    $v0, ($v1)
/* 0F45CC 7F0BFA9C 3C0B8005 */  lui   $t3, %hi(clock_timer) # $t3, 0x8005
/* 0F45D0 7F0BFAA0 8D6B8374 */  lw    $t3, %lo(clock_timer)($t3)
/* 0F45D4 7F0BFAA4 8C4A0060 */  lw    $t2, 0x60($v0)
/* 0F45D8 7F0BFAA8 240D0001 */  li    $t5, 1
/* 0F45DC 7F0BFAAC 014B6021 */  addu  $t4, $t2, $t3
/* 0F45E0 7F0BFAB0 AC4C0060 */  sw    $t4, 0x60($v0)
/* 0F45E4 7F0BFAB4 8C6E0000 */  lw    $t6, ($v1)
/* 0F45E8 7F0BFAB8 10000015 */  b     .L7F0BFB10
/* 0F45EC 7F0BFABC A1CD0069 */   sb    $t5, 0x69($t6)
.L7F0BFAC0:
/* 0F45F0 7F0BFAC0 3C0F8008 */  lui   $t7, %hi(cur_player_stat_ptr) # $t7, 0x8008
/* 0F45F4 7F0BFAC4 8DEFA0B4 */  lw    $t7, %lo(cur_player_stat_ptr)($t7)
/* 0F45F8 7F0BFAC8 10000011 */  b     .L7F0BFB10
/* 0F45FC 7F0BFACC A1E00069 */   sb    $zero, 0x69($t7)
.L7F0BFAD0:
/* 0F4600 7F0BFAD0 0FC051D6 */  jal   get_scenario
/* 0F4604 7F0BFAD4 00000000 */   nop   
/* 0F4608 7F0BFAD8 24010003 */  li    $at, 3
/* 0F460C 7F0BFADC 5441000D */  bnel  $v0, $at, .L7F0BFB14
/* 0F4610 7F0BFAE0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4614 7F0BFAE4 0FC233F0 */  jal   sub_GAME_7F08CFC0
/* 0F4618 7F0BFAE8 00000000 */   nop   
/* 0F461C 7F0BFAEC 10400006 */  beqz  $v0, .L7F0BFB08
/* 0F4620 7F0BFAF0 3C088008 */   lui   $t0, %hi(cur_player_stat_ptr) # $t0, 0x8008
/* 0F4624 7F0BFAF4 3C198008 */  lui   $t9, %hi(cur_player_stat_ptr) # $t9, 0x8008
/* 0F4628 7F0BFAF8 8F39A0B4 */  lw    $t9, %lo(cur_player_stat_ptr)($t9)
/* 0F462C 7F0BFAFC 24180001 */  li    $t8, 1
/* 0F4630 7F0BFB00 10000003 */  b     .L7F0BFB10
/* 0F4634 7F0BFB04 A3380069 */   sb    $t8, 0x69($t9)
.L7F0BFB08:
/* 0F4638 7F0BFB08 8D08A0B4 */  lw    $t0, %lo(cur_player_stat_ptr)($t0)
/* 0F463C 7F0BFB0C A1000069 */  sb    $zero, 0x69($t0)
.L7F0BFB10:
/* 0F4640 7F0BFB10 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BFB14:
/* 0F4644 7F0BFB14 27BD0030 */  addiu $sp, $sp, 0x30
/* 0F4648 7F0BFB18 03E00008 */  jr    $ra
/* 0F464C 7F0BFB1C 00000000 */   nop   
)
#endif





void unload_stage_text_data(void) {
    if (D_800483A0 != 0)
    {
        if (sfxGetArg0Unk3F(D_800483A0) != 0)
        {
            sfxDeactivate(D_800483A0);
        }
    }
    if (current_stage_to_load != 0x5a)
    {
        blank_text_bank(get_textbank_number_for_stagenum(current_stage_to_load));
        sub_GAME_7F007770();
    }
    sub_GAME_7F0926C0();
    cleanupGuardData();
    cleanupObjectSounds();
    cleanupExplosions();
    sub_GAME_7F007920();
    cleanup_REMOVED_();
    cleanupAlarms();
    cleanupObjects(current_stage_to_load);
    cleanupObjectives();
    cleanupSFXRelated();
    cleanupplayersoundrelated();
    sub_GAME_7F0C1268();
    sub_GAME_7F0B47E0();
}


void set_controls_locked_flag(s32 arg0) {
    controls_locked_flag = arg0;
}


s32 get_controls_locked_flag(void) {

    return controls_locked_flag;
}


s32 get_current_difficulty(void) {
    return difficulty_0;
}


void set_difficulty(s32 arg0) {
    difficulty_0 = arg0;
}

void set_mp_time(s32 arg0) {
    mp_time = arg0;
}


void set_mp_point(s32 arg0) {
    mp_point = arg0;
}


f32 get_cur_mp_sec(void) {
    return cur_mp_sec;
}


f32 get_cur_mp_min(void) {
    return cur_mp_min;
}


f32 get_stage_time_sec(void) {
    return stage_time_sec;
}


f32 get_poweron_time_sec(void) {
    return poweron_time_sec;
}


