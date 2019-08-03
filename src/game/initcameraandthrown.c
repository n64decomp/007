#include "ultra64.h"



// data
//D:8002A780
u32 D_8002A780 = 0;
//D:8002A784
u32 D_8002A784 = 0;
//D:8002A788
u32 D_8002A788 = 0;






#ifdef NONMATCHING
void set_weapon_model_generated_thrown_object(void) {

}
#else
GLOBAL_ASM(
.late_rodata
.text
glabel set_weapon_model_generated_thrown_object
/* 03A240 7F005710 248EFFFD */  addiu $t6, $a0, -3
/* 03A244 7F005714 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03A248 7F005718 2DC1002E */  sltiu $at, $t6, 0x2e
/* 03A24C 7F00571C AFBF0014 */  sw    $ra, 0x14($sp)
/* 03A250 7F005720 1020001E */  beqz  $at, .L7F00579C
/* 03A254 7F005724 2405FFFF */   li    $a1, -1
/* 03A258 7F005728 000E7080 */  sll   $t6, $t6, 2
/* 03A25C 7F00572C 3C018005 */  lui   $at, %hi(projectile_ptr_table)
/* 03A260 7F005730 002E0821 */  addu  $at, $at, $t6
/* 03A264 7F005734 8C2EF0F0 */  lw    $t6, %lo(projectile_ptr_table)($at)
/* 03A268 7F005738 01C00008 */  jr    $t6
/* 03A26C 7F00573C 00000000 */   nop   
throwingknife:
/* 03A270 7F005740 10000016 */  b     .L7F00579C
/* 03A274 7F005744 240500BA */   li    $a1, 186
grenade_launch_round:
/* 03A278 7F005748 10000014 */  b     .L7F00579C
/* 03A27C 7F00574C 240500CB */   li    $a1, 203
rocket:
/* 03A280 7F005750 10000012 */  b     .L7F00579C
/* 03A284 7F005754 240500CA */   li    $a1, 202
grenade:
/* 03A288 7F005758 10000010 */  b     .L7F00579C
/* 03A28C 7F00575C 240500C4 */   li    $a1, 196
timed_mine:
/* 03A290 7F005760 1000000E */  b     .L7F00579C
/* 03A294 7F005764 240500C9 */   li    $a1, 201
prox_mine:
/* 03A298 7F005768 1000000C */  b     .L7F00579C
/* 03A29C 7F00576C 240500C8 */   li    $a1, 200
remote_mine:
/* 03A2A0 7F005770 1000000A */  b     .L7F00579C
/* 03A2A4 7F005774 240500C7 */   li    $a1, 199
rocket_0:
/* 03A2A8 7F005778 10000008 */  b     .L7F00579C
/* 03A2AC 7F00577C 240500CA */   li    $a1, 202
bombcase:
/* 03A2B0 7F005780 10000006 */  b     .L7F00579C
/* 03A2B4 7F005784 240500E2 */   li    $a1, 226
plastique:
/* 03A2B8 7F005788 10000004 */  b     .L7F00579C
/* 03A2BC 7F00578C 24050111 */   li    $a1, 273
bug:
/* 03A2C0 7F005790 10000002 */  b     .L7F00579C
/* 03A2C4 7F005794 240500F5 */   li    $a1, 245
microcamera:
/* 03A2C8 7F005798 240500F6 */  li    $a1, 246
default:
.L7F00579C:
/* 03A2CC 7F00579C 04A00005 */  bltz  $a1, .L7F0057B4
/* 03A2D0 7F0057A0 00001025 */   move  $v0, $zero
/* 03A2D4 7F0057A4 0FC15B0E */  jal   load_model
/* 03A2D8 7F0057A8 00A02025 */   move  $a0, $a1
/* 03A2DC 7F0057AC 10000002 */  b     .L7F0057B8
/* 03A2E0 7F0057B0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0057B4:
/* 03A2E4 7F0057B4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0057B8:
/* 03A2E8 7F0057B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 03A2EC 7F0057BC 03E00008 */  jr    $ra
/* 03A2F0 7F0057C0 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void load_camera_intro_type_values(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel projectile_ptr_table
.word throwingknife
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word grenade_launch_round
.word rocket
.word grenade
.word timed_mine
.word prox_mine
.word remote_mine
.word default
.word default
.word rocket_0
.word bombcase
.word plastique
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word bug
.word microcamera


/*8004f1a8*/
glabel default_zoom_speed
.word 0x3f68ba2e

glabel jpt_8004F1AC
    .word spawn_point
    .word weapon
    .word ammo
    .word swirling_intro_cam
    .word intro_ani
    .word cuff_char
    .word fixed_cam
    .word watch_time
    .word credits

glabel D_8004F1D0
.word 0xb8d1b717
glabel D_8004F1D4
.word 0x40c90fdb
glabel D_8004F1D8
.word 0x40c90fdb
glabel D_8004F1DC
.word 0x3e2e147c
glabel D_8004F1E0
.word 0x3dccccd0
.text
glabel load_camera_intro_type_values
/* 03A2F4 7F0057C4 27BDFF68 */  addiu $sp, $sp, -0x98
/* 03A2F8 7F0057C8 3C0F8003 */  lui   $t7, %hi(D_8002A780) # $t7, 0x8003
/* 03A2FC 7F0057CC AFBF0034 */  sw    $ra, 0x34($sp)
/* 03A300 7F0057D0 AFB20030 */  sw    $s2, 0x30($sp)
/* 03A304 7F0057D4 AFB1002C */  sw    $s1, 0x2c($sp)
/* 03A308 7F0057D8 AFB00028 */  sw    $s0, 0x28($sp)
/* 03A30C 7F0057DC F7B60020 */  sdc1  $f22, 0x20($sp)
/* 03A310 7F0057E0 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 03A314 7F0057E4 25EFA780 */  addiu $t7, %lo(D_8002A780) # addiu $t7, $t7, -0x5880
/* 03A318 7F0057E8 8DE10000 */  lw    $at, ($t7)
/* 03A31C 7F0057EC 27AE008C */  addiu $t6, $sp, 0x8c
/* 03A320 7F0057F0 8DE80004 */  lw    $t0, 4($t7)
/* 03A324 7F0057F4 ADC10000 */  sw    $at, ($t6)
/* 03A328 7F0057F8 8DE10008 */  lw    $at, 8($t7)
/* 03A32C 7F0057FC ADC80004 */  sw    $t0, 4($t6)
/* 03A330 7F005800 3C118003 */  lui   $s1, %hi(resolution) # $s1, 0x8003
/* 03A334 7F005804 ADC10008 */  sw    $at, 8($t6)
/* 03A338 7F005808 3C018003 */  lui   $at, %hi(mission_kia_flag) # $at, 0x8003
/* 03A33C 7F00580C AC20A928 */  sw    $zero, %lo(mission_kia_flag)($at)
/* 03A340 7F005810 3C018003 */  lui   $at, %hi(camera_80036424) # $at, 0x8003
/* 03A344 7F005814 3C108007 */  lui   $s0, %hi(ptr_setup_intro) # $s0, 0x8007
/* 03A348 7F005818 AC206424 */  sw    $zero, %lo(camera_80036424)($at)
/* 03A34C 7F00581C 26316428 */  addiu $s1, %lo(resolution) # addiu $s1, $s1, 0x6428
/* 03A350 7F005820 8E105D08 */  lw    $s0, %lo(ptr_setup_intro)($s0)
/* 03A354 7F005824 AE200000 */  sw    $zero, ($s1)
/* 03A358 7F005828 3C018003 */  lui   $at, %hi(camera_8003642C) # $at, 0x8003
/* 03A35C 7F00582C 3C128003 */  lui   $s2, %hi(camera_80036430) # $s2, 0x8003
/* 03A360 7F005830 AC20642C */  sw    $zero, %lo(camera_8003642C)($at)
/* 03A364 7F005834 44802000 */  mtc1  $zero, $f4
/* 03A368 7F005838 26526430 */  addiu $s2, %lo(camera_80036430) # addiu $s2, $s2, 0x6430
/* 03A36C 7F00583C AE400000 */  sw    $zero, ($s2)
/* 03A370 7F005840 3C018003 */  lui   $at, %hi(camera_80036434) # $at, 0x8003
/* 03A374 7F005844 AFA0007C */  sw    $zero, 0x7c($sp)
/* 03A378 7F005848 AC206434 */  sw    $zero, %lo(camera_80036434)($at)
/* 03A37C 7F00584C 0C001A57 */  jal   get_stage_num
/* 03A380 7F005850 E7A40088 */   swc1  $f4, 0x88($sp)
/* 03A384 7F005854 24010036 */  li    $at, 54
/* 03A388 7F005858 1441000B */  bne   $v0, $at, .L7F005888
/* 03A38C 7F00585C 3C040004 */   lui   $a0, (0x00046EA0 >> 16) # lui $a0, 4
/* 03A390 7F005860 34846EA0 */  ori   $a0, (0x00046EA0 & 0xFFFF) # ori $a0, $a0, 0x6ea0
/* 03A394 7F005864 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03A398 7F005868 24050004 */   li    $a1, 4
/* 03A39C 7F00586C 244A003F */  addiu $t2, $v0, 0x3f
/* 03A3A0 7F005870 2401FFC0 */  li    $at, -64
/* 03A3A4 7F005874 AE220000 */  sw    $v0, ($s1)
/* 03A3A8 7F005878 01415824 */  and   $t3, $t2, $at
/* 03A3AC 7F00587C 240C0001 */  li    $t4, 1
/* 03A3B0 7F005880 AE2B0000 */  sw    $t3, ($s1)
/* 03A3B4 7F005884 AE4C0000 */  sw    $t4, ($s2)
.L7F005888:
/* 03A3B8 7F005888 3C018003 */  lui   $at, %hi(camera_80036438) # $at, 0x8003
/* 03A3BC 7F00588C AC206438 */  sw    $zero, %lo(camera_80036438)($at)
/* 03A3C0 7F005890 3C018003 */  lui   $at, %hi(D_8003643C) # $at, 0x8003
/* 03A3C4 7F005894 AC20643C */  sw    $zero, %lo(D_8003643C)($at)
/* 03A3C8 7F005898 3C018003 */  lui   $at, %hi(D_80036440) # $at, 0x8003
/* 03A3CC 7F00589C 3C028008 */  lui   $v0, %hi(flt_CODE_bss_80079990) # $v0, 0x8008
/* 03A3D0 7F0058A0 AC206440 */  sw    $zero, %lo(D_80036440)($at)
/* 03A3D4 7F0058A4 44803000 */  mtc1  $zero, $f6
/* 03A3D8 7F0058A8 44804000 */  mtc1  $zero, $f8
/* 03A3DC 7F0058AC 44805000 */  mtc1  $zero, $f10
/* 03A3E0 7F0058B0 24429990 */  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
/* 03A3E4 7F0058B4 3C018003 */  lui   $at, %hi(D_80036444) # $at, 0x8003
/* 03A3E8 7F0058B8 E4460000 */  swc1  $f6, ($v0)
/* 03A3EC 7F0058BC E4480004 */  swc1  $f8, 4($v0)
/* 03A3F0 7F0058C0 E44A0008 */  swc1  $f10, 8($v0)
/* 03A3F4 7F0058C4 AC206444 */  sw    $zero, %lo(D_80036444)($at)
/* 03A3F8 7F0058C8 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079C68) # $at, 0x8008
/* 03A3FC 7F0058CC AC209C68 */  sw    $zero, %lo(dword_CODE_bss_80079C68)($at)
/* 03A400 7F0058D0 3C018003 */  lui   $at, %hi(in_tank_flag) # $at, 0x8003
/* 03A404 7F0058D4 AC206448 */  sw    $zero, %lo(in_tank_flag)($at)
/* 03A408 7F0058D8 3C018003 */  lui   $at, %hi(D_8003644C) # $at, 0x8003
/* 03A40C 7F0058DC AC20644C */  sw    $zero, %lo(D_8003644C)($at)
/* 03A410 7F0058E0 44808000 */  mtc1  $zero, $f16
/* 03A414 7F0058E4 3C018003 */  lui   $at, %hi(D_80036450) # $at, 0x8003
/* 03A418 7F0058E8 AC206450 */  sw    $zero, %lo(D_80036450)($at)
/* 03A41C 7F0058EC 3C018003 */  lui   $at, %hi(D_80036454) # $at, 0x8003
/* 03A420 7F0058F0 3C038003 */  lui   $v1, %hi(SFX_80036458) # $v1, 0x8003
/* 03A424 7F0058F4 E4306454 */  swc1  $f16, %lo(D_80036454)($at)
/* 03A428 7F0058F8 44809000 */  mtc1  $zero, $f18
/* 03A42C 7F0058FC 24636458 */  addiu $v1, %lo(SFX_80036458) # addiu $v1, $v1, 0x6458
/* 03A430 7F005900 44802000 */  mtc1  $zero, $f4
/* 03A434 7F005904 AC600000 */  sw    $zero, ($v1)
/* 03A438 7F005908 AC600004 */  sw    $zero, 4($v1)
/* 03A43C 7F00590C 3C018003 */  lui   $at, %hi(D_80036460) # $at, 0x8003
/* 03A440 7F005910 E4326460 */  swc1  $f18, %lo(D_80036460)($at)
/* 03A444 7F005914 44803000 */  mtc1  $zero, $f6
/* 03A448 7F005918 3C018003 */  lui   $at, %hi(D_80036464) # $at, 0x8003
/* 03A44C 7F00591C E4246464 */  swc1  $f4, %lo(D_80036464)($at)
/* 03A450 7F005920 44804000 */  mtc1  $zero, $f8
/* 03A454 7F005924 3C018003 */  lui   $at, %hi(D_80036468) # $at, 0x8003
/* 03A458 7F005928 E4266468 */  swc1  $f6, %lo(D_80036468)($at)
/* 03A45C 7F00592C 44805000 */  mtc1  $zero, $f10
/* 03A460 7F005930 3C018003 */  lui   $at, %hi(D_8003646C) # $at, 0x8003
/* 03A464 7F005934 E428646C */  swc1  $f8, %lo(D_8003646C)($at)
/* 03A468 7F005938 44808000 */  mtc1  $zero, $f16
/* 03A46C 7F00593C 3C018003 */  lui   $at, %hi(D_80036470) # $at, 0x8003
/* 03A470 7F005940 E42A6470 */  swc1  $f10, %lo(D_80036470)($at)
/* 03A474 7F005944 44809000 */  mtc1  $zero, $f18
/* 03A478 7F005948 3C018003 */  lui   $at, %hi(D_80036474) # $at, 0x8003
/* 03A47C 7F00594C E4306474 */  swc1  $f16, %lo(D_80036474)($at)
/* 03A480 7F005950 44802000 */  mtc1  $zero, $f4
/* 03A484 7F005954 3C018003 */  lui   $at, %hi(D_80036478) # $at, 0x8003
/* 03A488 7F005958 E4326478 */  swc1  $f18, %lo(D_80036478)($at)
/* 03A48C 7F00595C 3C018003 */  lui   $at, %hi(D_8003647C) # $at, 0x8003
/* 03A490 7F005960 E424647C */  swc1  $f4, %lo(D_8003647C)($at)
/* 03A494 7F005964 44803000 */  mtc1  $zero, $f6
/* 03A498 7F005968 3C018003 */  lui   $at, %hi(D_80036480) # $at, 0x8003
/* 03A49C 7F00596C AC206480 */  sw    $zero, %lo(D_80036480)($at)
/* 03A4A0 7F005970 44804000 */  mtc1  $zero, $f8
/* 03A4A4 7F005974 3C018003 */  lui   $at, %hi(D_80036484) # $at, 0x8003
/* 03A4A8 7F005978 E4266484 */  swc1  $f6, %lo(D_80036484)($at)
/* 03A4AC 7F00597C 3C018003 */  lui   $at, %hi(D_80036488) # $at, 0x8003
/* 03A4B0 7F005980 E4286488 */  swc1  $f8, %lo(D_80036488)($at)
/* 03A4B4 7F005984 3C018003 */  lui   $at, %hi(D_8003648C) # $at, 0x8003
/* 03A4B8 7F005988 AC20648C */  sw    $zero, %lo(D_8003648C)($at)
/* 03A4BC 7F00598C 3C018003 */  lui   $at, %hi(D_800364B0) # $at, 0x8003
/* 03A4C0 7F005990 240D0001 */  li    $t5, 1
/* 03A4C4 7F005994 AC2D64B0 */  sw    $t5, %lo(D_800364B0)($at)
/* 03A4C8 7F005998 3C018003 */  lui   $at, %hi(disable_player_pickups_flag) # $at, 0x8003
/* 03A4CC 7F00599C AC2064B4 */  sw    $zero, %lo(disable_player_pickups_flag)($at)
/* 03A4D0 7F0059A0 3C018003 */  lui   $at, %hi(cameramode) # $at, 0x8003
/* 03A4D4 7F0059A4 AC206494 */  sw    $zero, %lo(cameramode)($at)
/* 03A4D8 7F0059A8 3C018003 */  lui   $at, %hi(D_80036498) # $at, 0x8003
/* 03A4DC 7F0059AC AC206498 */  sw    $zero, %lo(D_80036498)($at)
/* 03A4E0 7F0059B0 3C018003 */  lui   $at, %hi(D_8003649C) # $at, 0x8003
/* 03A4E4 7F0059B4 AC20649C */  sw    $zero, %lo(D_8003649C)($at)
/* 03A4E8 7F0059B8 44805000 */  mtc1  $zero, $f10
/* 03A4EC 7F0059BC 3C018003 */  lui   $at, %hi(stop_time_flag) # $at, 0x8003
/* 03A4F0 7F0059C0 AC2064A0 */  sw    $zero, %lo(stop_time_flag)($at)
/* 03A4F4 7F0059C4 3C018003 */  lui   $at, %hi(D_800364A4) # $at, 0x8003
/* 03A4F8 7F0059C8 E42A64A4 */  swc1  $f10, %lo(D_800364A4)($at)
/* 03A4FC 7F0059CC 3C018003 */  lui   $at, %hi(D_800364A8) # $at, 0x8003
/* 03A500 7F0059D0 24190001 */  li    $t9, 1
/* 03A504 7F0059D4 AC3964A8 */  sw    $t9, %lo(D_800364A8)($at)
/* 03A508 7F0059D8 3C018003 */  lui   $at, %hi(D_800364AC) # $at, 0x8003
/* 03A50C 7F0059DC AC2064AC */  sw    $zero, %lo(D_800364AC)($at)
/* 03A510 7F0059E0 3C018003 */  lui   $at, %hi(D_800364C0) # $at, 0x8003
/* 03A514 7F0059E4 AC2064C0 */  sw    $zero, %lo(D_800364C0)($at)
/* 03A518 7F0059E8 3C018003 */  lui   $at, %hi(D_800364B8) # $at, 0x8003
/* 03A51C 7F0059EC AC2064B8 */  sw    $zero, %lo(D_800364B8)($at)
/* 03A520 7F0059F0 3C018003 */  lui   $at, %hi(D_800364BC) # $at, 0x8003
/* 03A524 7F0059F4 AC2064BC */  sw    $zero, %lo(D_800364BC)($at)
/* 03A528 7F0059F8 3C018008 */  lui   $at, %hi(mission_timer) # $at, 0x8008
/* 03A52C 7F0059FC 3C118008 */  lui   $s1, %hi(watch_time_0) # $s1, 0x8008
/* 03A530 7F005A00 AC209A20 */  sw    $zero, %lo(mission_timer)($at)
/* 03A534 7F005A04 26319A24 */  addiu $s1, %lo(watch_time_0) # addiu $s1, $s1, -0x65dc
/* 03A538 7F005A08 AE200000 */  sw    $zero, ($s1)
/* 03A53C 7F005A0C 3C018003 */  lui   $at, %hi(D_80036514) # $at, 0x8003
/* 03A540 7F005A10 AC206514 */  sw    $zero, %lo(D_80036514)($at)
/* 03A544 7F005A14 3C018005 */  lui   $at, %hi(default_zoom_speed) # $at, 0x8005
/* 03A548 7F005A18 C430F1A8 */  lwc1  $f16, %lo(default_zoom_speed)($at)
/* 03A54C 7F005A1C 3C018003 */  lui   $at, %hi(watch_transition_time) # $at, 0x8003
/* 03A550 7F005A20 E43065A8 */  swc1  $f16, %lo(watch_transition_time)($at)
/* 03A554 7F005A24 3C018008 */  lui   $at, %hi(starting_left_weapon) # $at, 0x8008
/* 03A558 7F005A28 AC2099E4 */  sw    $zero, %lo(starting_left_weapon)($at)
/* 03A55C 7F005A2C 3C018008 */  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
/* 03A560 7F005A30 120000F0 */  beqz  $s0, .L7F005DF4
/* 03A564 7F005A34 AC2099E0 */   sw    $zero, %lo(starting_right_weapon)($at)
/* 03A568 7F005A38 8E020000 */  lw    $v0, ($s0)
/* 03A56C 7F005A3C 24010009 */  li    $at, 9
/* 03A570 7F005A40 3C128008 */  lui   $s2, %hi(ptr_BONDdata) # $s2, 0x8008
/* 03A574 7F005A44 104100EB */  beq   $v0, $at, .L7F005DF4
/* 03A578 7F005A48 3C0142C8 */   li    $at, 0x42C80000 # 100.000000
/* 03A57C 7F005A4C 4481B000 */  mtc1  $at, $f22
/* 03A580 7F005A50 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 03A584 7F005A54 4481A000 */  mtc1  $at, $f20
/* 03A588 7F005A58 2652A0B0 */  addiu $s2, %lo(ptr_BONDdata) # addiu $s2, $s2, -0x5f50
/* 03A58C 7F005A5C 2C410009 */  sltiu $at, $v0, 9
.L7F005A60:
/* 03A590 7F005A60 102000DF */  beqz  $at, .L7F005DE0
/* 03A594 7F005A64 0002C080 */   sll   $t8, $v0, 2
/* 03A598 7F005A68 3C018005 */  lui   $at, %hi(jpt_8004F1AC)
/* 03A59C 7F005A6C 00380821 */  addu  $at, $at, $t8
/* 03A5A0 7F005A70 8C38F1AC */  lw    $t8, %lo(jpt_8004F1AC)($at)
/* 03A5A4 7F005A74 03000008 */  jr    $t8
/* 03A5A8 7F005A78 00000000 */   nop   
spawn_point:
/* 03A5AC 7F005A7C 3C0E8007 */  lui   $t6, %hi(ptr_0xxxpresets) # $t6, 0x8007
/* 03A5B0 7F005A80 8DCE5D18 */  lw    $t6, %lo(ptr_0xxxpresets)($t6)
/* 03A5B4 7F005A84 11C00018 */  beqz  $t6, .L7F005AE8
/* 03A5B8 7F005A88 00000000 */   nop   
/* 03A5BC 7F005A8C 0FC30288 */  jal   check_ramrom_flags
/* 03A5C0 7F005A90 00000000 */   nop   
/* 03A5C4 7F005A94 8E0F0008 */  lw    $t7, 8($s0)
/* 03A5C8 7F005A98 3C0A8007 */  lui   $t2, %hi(ptr_0xxxpresets) # $t2, 0x8007
/* 03A5CC 7F005A9C 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079C28)
/* 03A5D0 7F005AA0 144F0011 */  bne   $v0, $t7, .L7F005AE8
/* 03A5D4 7F005AA4 00000000 */   nop   
/* 03A5D8 7F005AA8 8E080004 */  lw    $t0, 4($s0)
/* 03A5DC 7F005AAC 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80079C68) # $v0, 0x8008
/* 03A5E0 7F005AB0 8C429C68 */  lw    $v0, %lo(dword_CODE_bss_80079C68)($v0)
/* 03A5E4 7F005AB4 00084880 */  sll   $t1, $t0, 2
/* 03A5E8 7F005AB8 01284823 */  subu  $t1, $t1, $t0
/* 03A5EC 7F005ABC 8D4A5D18 */  lw    $t2, %lo(ptr_0xxxpresets)($t2)
/* 03A5F0 7F005AC0 00094880 */  sll   $t1, $t1, 2
/* 03A5F4 7F005AC4 01284823 */  subu  $t1, $t1, $t0
/* 03A5F8 7F005AC8 00094880 */  sll   $t1, $t1, 2
/* 03A5FC 7F005ACC 00026080 */  sll   $t4, $v0, 2
/* 03A600 7F005AD0 002C0821 */  addu  $at, $at, $t4
/* 03A604 7F005AD4 012A5821 */  addu  $t3, $t1, $t2
/* 03A608 7F005AD8 AC2B9C28 */  sw    $t3, %lo(dword_CODE_bss_80079C28)($at)
/* 03A60C 7F005ADC 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079C68) # $at, 0x8008
/* 03A610 7F005AE0 244D0001 */  addiu $t5, $v0, 1
/* 03A614 7F005AE4 AC2D9C68 */  sw    $t5, %lo(dword_CODE_bss_80079C68)($at)
.L7F005AE8:
/* 03A618 7F005AE8 100000BE */  b     .L7F005DE4
/* 03A61C 7F005AEC 2610000C */   addiu $s0, $s0, 0xc
weapon:
/* 03A620 7F005AF0 0FC30288 */  jal   check_ramrom_flags
/* 03A624 7F005AF4 00000000 */   nop   
/* 03A628 7F005AF8 8E19000C */  lw    $t9, 0xc($s0)
/* 03A62C 7F005AFC 1459001C */  bne   $v0, $t9, .L7F005B70
/* 03A630 7F005B00 00000000 */   nop   
/* 03A634 7F005B04 0FC015C4 */  jal   set_weapon_model_generated_thrown_object
/* 03A638 7F005B08 8E040004 */   lw    $a0, 4($s0)
/* 03A63C 7F005B0C 8E040008 */  lw    $a0, 8($s0)
/* 03A640 7F005B10 04800008 */  bltz  $a0, .L7F005B34
/* 03A644 7F005B14 00000000 */   nop   
/* 03A648 7F005B18 0FC015C4 */  jal   set_weapon_model_generated_thrown_object
/* 03A64C 7F005B1C 00000000 */   nop   
/* 03A650 7F005B20 8E040004 */  lw    $a0, 4($s0)
/* 03A654 7F005B24 0FC23143 */  jal   add_doubles_item_to_inventory
/* 03A658 7F005B28 8E050008 */   lw    $a1, 8($s0)
/* 03A65C 7F005B2C 10000004 */  b     .L7F005B40
/* 03A660 7F005B30 8FB8007C */   lw    $t8, 0x7c($sp)
.L7F005B34:
/* 03A664 7F005B34 0FC23122 */  jal   add_item_to_inventory
/* 03A668 7F005B38 8E040004 */   lw    $a0, 4($s0)
/* 03A66C 7F005B3C 8FB8007C */  lw    $t8, 0x7c($sp)
.L7F005B40:
/* 03A670 7F005B40 1700000B */  bnez  $t8, .L7F005B70
/* 03A674 7F005B44 00000000 */   nop   
/* 03A678 7F005B48 8E0E0004 */  lw    $t6, 4($s0)
/* 03A67C 7F005B4C 3C018008 */  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
/* 03A680 7F005B50 240F0001 */  li    $t7, 1
/* 03A684 7F005B54 AC2E99E0 */  sw    $t6, %lo(starting_right_weapon)($at)
/* 03A688 7F005B58 8E040008 */  lw    $a0, 8($s0)
/* 03A68C 7F005B5C AFAF007C */  sw    $t7, 0x7c($sp)
/* 03A690 7F005B60 3C018008 */  lui   $at, %hi(starting_left_weapon) # $at, 0x8008
/* 03A694 7F005B64 04800002 */  bltz  $a0, .L7F005B70
/* 03A698 7F005B68 00000000 */   nop   
/* 03A69C 7F005B6C AC2499E4 */  sw    $a0, %lo(starting_left_weapon)($at)
.L7F005B70:
/* 03A6A0 7F005B70 1000009C */  b     .L7F005DE4
/* 03A6A4 7F005B74 26100010 */   addiu $s0, $s0, 0x10
ammo:
/* 03A6A8 7F005B78 0FC30288 */  jal   check_ramrom_flags
/* 03A6AC 7F005B7C 00000000 */   nop   
/* 03A6B0 7F005B80 8E08000C */  lw    $t0, 0xc($s0)
/* 03A6B4 7F005B84 14480004 */  bne   $v0, $t0, .L7F005B98
/* 03A6B8 7F005B88 00000000 */   nop   
/* 03A6BC 7F005B8C 8E040004 */  lw    $a0, 4($s0)
/* 03A6C0 7F005B90 0FC1A44C */  jal   give_cur_player_ammo
/* 03A6C4 7F005B94 8E050008 */   lw    $a1, 8($s0)
.L7F005B98:
/* 03A6C8 7F005B98 10000092 */  b     .L7F005DE4
/* 03A6CC 7F005B9C 26100010 */   addiu $s0, $s0, 0x10
swirling_intro_cam:
/* 03A6D0 7F005BA0 3C098003 */  lui   $t1, %hi(D_800364AC) # $t1, 0x8003
/* 03A6D4 7F005BA4 8D2964AC */  lw    $t1, %lo(D_800364AC)($t1)
/* 03A6D8 7F005BA8 02001025 */  move  $v0, $s0
/* 03A6DC 7F005BAC 3C018003 */  lui   $at, %hi(D_800364AC) # $at, 0x8003
/* 03A6E0 7F005BB0 55200003 */  bnezl $t1, .L7F005BC0
/* 03A6E4 7F005BB4 8C4A0008 */   lw    $t2, 8($v0)
/* 03A6E8 7F005BB8 AC3064AC */  sw    $s0, %lo(D_800364AC)($at)
/* 03A6EC 7F005BBC 8C4A0008 */  lw    $t2, 8($v0)
.L7F005BC0:
/* 03A6F0 7F005BC0 8C4B000C */  lw    $t3, 0xc($v0)
/* 03A6F4 7F005BC4 8C4C0010 */  lw    $t4, 0x10($v0)
/* 03A6F8 7F005BC8 448A9000 */  mtc1  $t2, $f18
/* 03A6FC 7F005BCC 448B4000 */  mtc1  $t3, $f8
/* 03A700 7F005BD0 8C4D0014 */  lw    $t5, 0x14($v0)
/* 03A704 7F005BD4 46809120 */  cvt.s.w $f4, $f18
/* 03A708 7F005BD8 448C9000 */  mtc1  $t4, $f18
/* 03A70C 7F005BDC 8C590018 */  lw    $t9, 0x18($v0)
/* 03A710 7F005BE0 26100020 */  addiu $s0, $s0, 0x20
/* 03A714 7F005BE4 468042A0 */  cvt.s.w $f10, $f8
/* 03A718 7F005BE8 448D4000 */  mtc1  $t5, $f8
/* 03A71C 7F005BEC 46142183 */  div.s $f6, $f4, $f20
/* 03A720 7F005BF0 46809120 */  cvt.s.w $f4, $f18
/* 03A724 7F005BF4 44999000 */  mtc1  $t9, $f18
/* 03A728 7F005BF8 46145403 */  div.s $f16, $f10, $f20
/* 03A72C 7F005BFC E4460008 */  swc1  $f6, 8($v0)
/* 03A730 7F005C00 468042A0 */  cvt.s.w $f10, $f8
/* 03A734 7F005C04 46142183 */  div.s $f6, $f4, $f20
/* 03A738 7F005C08 E450000C */  swc1  $f16, 0xc($v0)
/* 03A73C 7F005C0C 46809120 */  cvt.s.w $f4, $f18
/* 03A740 7F005C10 46145403 */  div.s $f16, $f10, $f20
/* 03A744 7F005C14 E4460010 */  swc1  $f6, 0x10($v0)
/* 03A748 7F005C18 46142183 */  div.s $f6, $f4, $f20
/* 03A74C 7F005C1C E4500014 */  swc1  $f16, 0x14($v0)
/* 03A750 7F005C20 10000070 */  b     .L7F005DE4
/* 03A754 7F005C24 E4460018 */   swc1  $f6, 0x18($v0)
intro_ani:
/* 03A758 7F005C28 8E180004 */  lw    $t8, 4($s0)
/* 03A75C 7F005C2C 3C018003 */  lui   $at, %hi(D_80036514) # $at, 0x8003
/* 03A760 7F005C30 26100008 */  addiu $s0, $s0, 8
/* 03A764 7F005C34 1000006B */  b     .L7F005DE4
/* 03A768 7F005C38 AC386514 */   sw    $t8, %lo(D_80036514)($at)
cuff_char:
/* 03A76C 7F005C3C 8E0E0004 */  lw    $t6, 4($s0)
/* 03A770 7F005C40 8E4F0000 */  lw    $t7, ($s2)
/* 03A774 7F005C44 26100008 */  addiu $s0, $s0, 8
/* 03A778 7F005C48 10000066 */  b     .L7F005DE4
/* 03A77C 7F005C4C ADEE041C */   sw    $t6, 0x41c($t7)
fixed_cam:
/* 03A780 7F005C50 0FC26C54 */  jal   get_cur_playernum
/* 03A784 7F005C54 00000000 */   nop   
/* 03A788 7F005C58 1440002C */  bnez  $v0, .L7F005D0C
/* 03A78C 7F005C5C 3C088003 */   lui   $t0, %hi(D_800364B8) # $t0, 0x8003
/* 03A790 7F005C60 8D0864B8 */  lw    $t0, %lo(D_800364B8)($t0)
/* 03A794 7F005C64 3C098003 */  lui   $t1, %hi(D_800364BC) # $t1, 0x8003
/* 03A798 7F005C68 3C018003 */  lui   $at, %hi(D_800364B8) # $at, 0x8003
/* 03A79C 7F005C6C AE080024 */  sw    $t0, 0x24($s0)
/* 03A7A0 7F005C70 8D2964BC */  lw    $t1, %lo(D_800364BC)($t1)
/* 03A7A4 7F005C74 AC3064B8 */  sw    $s0, %lo(D_800364B8)($at)
/* 03A7A8 7F005C78 3C018003 */  lui   $at, %hi(D_800364BC) # $at, 0x8003
/* 03A7AC 7F005C7C 252A0001 */  addiu $t2, $t1, 1
/* 03A7B0 7F005C80 AC2A64BC */  sw    $t2, %lo(D_800364BC)($at)
/* 03A7B4 7F005C84 8E0B0004 */  lw    $t3, 4($s0)
/* 03A7B8 7F005C88 8E0C0008 */  lw    $t4, 8($s0)
/* 03A7BC 7F005C8C 8E0D000C */  lw    $t5, 0xc($s0)
/* 03A7C0 7F005C90 448B4000 */  mtc1  $t3, $f8
/* 03A7C4 7F005C94 448C9000 */  mtc1  $t4, $f18
/* 03A7C8 7F005C98 8E190010 */  lw    $t9, 0x10($s0)
/* 03A7CC 7F005C9C 468042A0 */  cvt.s.w $f10, $f8
/* 03A7D0 7F005CA0 448D4000 */  mtc1  $t5, $f8
/* 03A7D4 7F005CA4 8E180014 */  lw    $t8, 0x14($s0)
/* 03A7D8 7F005CA8 9604001E */  lhu   $a0, 0x1e($s0)
/* 03A7DC 7F005CAC 46809120 */  cvt.s.w $f4, $f18
/* 03A7E0 7F005CB0 44999000 */  mtc1  $t9, $f18
/* 03A7E4 7F005CB4 46165403 */  div.s $f16, $f10, $f22
/* 03A7E8 7F005CB8 468042A0 */  cvt.s.w $f10, $f8
/* 03A7EC 7F005CBC 44984000 */  mtc1  $t8, $f8
/* 03A7F0 7F005CC0 46162183 */  div.s $f6, $f4, $f22
/* 03A7F4 7F005CC4 E6100004 */  swc1  $f16, 4($s0)
/* 03A7F8 7F005CC8 46809120 */  cvt.s.w $f4, $f18
/* 03A7FC 7F005CCC 46165403 */  div.s $f16, $f10, $f22
/* 03A800 7F005CD0 E6060008 */  swc1  $f6, 8($s0)
/* 03A804 7F005CD4 468042A0 */  cvt.s.w $f10, $f8
/* 03A808 7F005CD8 46142183 */  div.s $f6, $f4, $f20
/* 03A80C 7F005CDC E610000C */  swc1  $f16, 0xc($s0)
/* 03A810 7F005CE0 46145403 */  div.s $f16, $f10, $f20
/* 03A814 7F005CE4 E6060010 */  swc1  $f6, 0x10($s0)
/* 03A818 7F005CE8 0FC30776 */  jal   get_textptr_for_textID
/* 03A81C 7F005CEC E6100014 */   swc1  $f16, 0x14($s0)
/* 03A820 7F005CF0 8E030020 */  lw    $v1, 0x20($s0)
/* 03A824 7F005CF4 AE02001C */  sw    $v0, 0x1c($s0)
/* 03A828 7F005CF8 10600004 */  beqz  $v1, .L7F005D0C
/* 03A82C 7F005CFC 00000000 */   nop   
/* 03A830 7F005D00 0FC30776 */  jal   get_textptr_for_textID
/* 03A834 7F005D04 3064FFFF */   andi  $a0, $v1, 0xffff
/* 03A838 7F005D08 AE020020 */  sw    $v0, 0x20($s0)
.L7F005D0C:
/* 03A83C 7F005D0C 10000035 */  b     .L7F005DE4
/* 03A840 7F005D10 26100028 */   addiu $s0, $s0, 0x28
watch_time:
/* 03A844 7F005D14 AE200000 */  sw    $zero, ($s1)
/* 03A848 7F005D18 8E040008 */  lw    $a0, 8($s0)
/* 03A84C 7F005D1C 2401003C */  li    $at, 60
/* 03A850 7F005D20 5880000B */  blezl $a0, .L7F005D50
/* 03A854 7F005D24 8E020004 */   lw    $v0, 4($s0)
/* 03A858 7F005D28 0081001A */  div   $zero, $a0, $at
/* 03A85C 7F005D2C 00007810 */  mfhi  $t7
/* 03A860 7F005D30 000F40C0 */  sll   $t0, $t7, 3
/* 03A864 7F005D34 010F4023 */  subu  $t0, $t0, $t7
/* 03A868 7F005D38 00084140 */  sll   $t0, $t0, 5
/* 03A86C 7F005D3C 010F4021 */  addu  $t0, $t0, $t7
/* 03A870 7F005D40 00084100 */  sll   $t0, $t0, 4
/* 03A874 7F005D44 3C018008 */  lui   $at, %hi(watch_time_0) # $at, 0x8008
/* 03A878 7F005D48 AC289A24 */  sw    $t0, %lo(watch_time_0)($at)
/* 03A87C 7F005D4C 8E020004 */  lw    $v0, 4($s0)
.L7F005D50:
/* 03A880 7F005D50 2401000C */  li    $at, 12
/* 03A884 7F005D54 1840000B */  blez  $v0, .L7F005D84
/* 03A888 7F005D58 00000000 */   nop   
/* 03A88C 7F005D5C 0041001A */  div   $zero, $v0, $at
/* 03A890 7F005D60 00005810 */  mfhi  $t3
/* 03A894 7F005D64 3C010003 */  lui   $at, (0x00034BC0 >> 16) # lui $at, 3
/* 03A898 7F005D68 34214BC0 */  ori   $at, (0x00034BC0 & 0xFFFF) # ori $at, $at, 0x4bc0
/* 03A89C 7F005D6C 01610019 */  multu $t3, $at
/* 03A8A0 7F005D70 8E2A0000 */  lw    $t2, ($s1)
/* 03A8A4 7F005D74 3C018008 */  lui   $at, %hi(watch_time_0) # $at, 0x8008
/* 03A8A8 7F005D78 00006012 */  mflo  $t4
/* 03A8AC 7F005D7C 014C6821 */  addu  $t5, $t2, $t4
/* 03A8B0 7F005D80 AC2D9A24 */  sw    $t5, %lo(watch_time_0)($at)
.L7F005D84:
/* 03A8B4 7F005D84 10000017 */  b     .L7F005DE4
/* 03A8B8 7F005D88 2610000C */   addiu $s0, $s0, 0xc
credits:
/* 03A8BC 7F005D8C 3C198007 */  lui   $t9, %hi(dword_CODE_bss_80075D28) # $t9, 0x8007
/* 03A8C0 7F005D90 8F395D28 */  lw    $t9, %lo(dword_CODE_bss_80075D28)($t9)
/* 03A8C4 7F005D94 8E180004 */  lw    $t8, 4($s0)
/* 03A8C8 7F005D98 3C018003 */  lui   $at, %hi(D_80036440) # $at, 0x8003
/* 03A8CC 7F005D9C 03381021 */  addu  $v0, $t9, $t8
/* 03A8D0 7F005DA0 AC226440 */  sw    $v0, %lo(D_80036440)($at)
/* 03A8D4 7F005DA4 944F0000 */  lhu   $t7, ($v0)
/* 03A8D8 7F005DA8 55E00005 */  bnezl $t7, .L7F005DC0
/* 03A8DC 7F005DAC 9448000C */   lhu   $t0, 0xc($v0)
/* 03A8E0 7F005DB0 944E0002 */  lhu   $t6, 2($v0)
/* 03A8E4 7F005DB4 11C00008 */  beqz  $t6, .L7F005DD8
/* 03A8E8 7F005DB8 00000000 */   nop   
/* 03A8EC 7F005DBC 9448000C */  lhu   $t0, 0xc($v0)
.L7F005DC0:
/* 03A8F0 7F005DC0 2442000C */  addiu $v0, $v0, 0xc
/* 03A8F4 7F005DC4 5500FFFE */  bnezl $t0, .L7F005DC0
/* 03A8F8 7F005DC8 9448000C */   lhu   $t0, 0xc($v0)
/* 03A8FC 7F005DCC 94490002 */  lhu   $t1, 2($v0)
/* 03A900 7F005DD0 5520FFFB */  bnezl $t1, .L7F005DC0
/* 03A904 7F005DD4 9448000C */   lhu   $t0, 0xc($v0)
.L7F005DD8:
/* 03A908 7F005DD8 10000002 */  b     .L7F005DE4
/* 03A90C 7F005DDC 26100008 */   addiu $s0, $s0, 8
def_7F005A74:
.L7F005DE0:
/* 03A910 7F005DE0 26100004 */  addiu $s0, $s0, 4
.L7F005DE4:
/* 03A914 7F005DE4 8E020000 */  lw    $v0, ($s0)
/* 03A918 7F005DE8 24010009 */  li    $at, 9
/* 03A91C 7F005DEC 5441FF1C */  bnel  $v0, $at, .L7F005A60
/* 03A920 7F005DF0 2C410009 */   sltiu $at, $v0, 9
.L7F005DF4:
/* 03A924 7F005DF4 3C028003 */  lui   $v0, %hi(D_800364B8) # $v0, 0x8003
/* 03A928 7F005DF8 8C4264B8 */  lw    $v0, %lo(D_800364B8)($v0)
/* 03A92C 7F005DFC 3C128008 */  lui   $s2, %hi(ptr_BONDdata) # $s2, 0x8008
/* 03A930 7F005E00 2652A0B0 */  addiu $s2, %lo(ptr_BONDdata) # addiu $s2, $s2, -0x5f50
/* 03A934 7F005E04 10400012 */  beqz  $v0, .L7F005E50
/* 03A938 7F005E08 3C018003 */   lui   $at, %hi(D_800364C0) # $at, 0x8003
/* 03A93C 7F005E0C 0C002914 */  jal   get_random_value
/* 03A940 7F005E10 AC2264C0 */   sw    $v0, %lo(D_800364C0)($at)
/* 03A944 7F005E14 3C0B8003 */  lui   $t3, %hi(D_800364BC) # $t3, 0x8003
/* 03A948 7F005E18 8D6B64BC */  lw    $t3, %lo(D_800364BC)($t3)
/* 03A94C 7F005E1C 004B001B */  divu  $zero, $v0, $t3
/* 03A950 7F005E20 00001810 */  mfhi  $v1
/* 03A954 7F005E24 15600002 */  bnez  $t3, .L7F005E30
/* 03A958 7F005E28 00000000 */   nop   
/* 03A95C 7F005E2C 0007000D */  break 7
.L7F005E30:
/* 03A960 7F005E30 18600007 */  blez  $v1, .L7F005E50
.L7F005E34:
/* 03A964 7F005E34 3C0A8003 */   lui   $t2, %hi(D_800364C0) # $t2, 0x8003
/* 03A968 7F005E38 8D4A64C0 */  lw    $t2, %lo(D_800364C0)($t2)
/* 03A96C 7F005E3C 2463FFFF */  addiu $v1, $v1, -1
/* 03A970 7F005E40 3C018003 */  lui   $at, %hi(D_800364C0) # $at, 0x8003
/* 03A974 7F005E44 8D4C0024 */  lw    $t4, 0x24($t2)
/* 03A978 7F005E48 1C60FFFA */  bgtz  $v1, .L7F005E34
/* 03A97C 7F005E4C AC2C64C0 */   sw    $t4, %lo(D_800364C0)($at)
.L7F005E50:
/* 03A980 7F005E50 0FC23122 */  jal   add_item_to_inventory
/* 03A984 7F005E54 24040001 */   li    $a0, 1
/* 03A988 7F005E58 8FAD007C */  lw    $t5, 0x7c($sp)
/* 03A98C 7F005E5C 44809000 */  mtc1  $zero, $f18
/* 03A990 7F005E60 15A00003 */  bnez  $t5, .L7F005E70
/* 03A994 7F005E64 24190001 */   li    $t9, 1
/* 03A998 7F005E68 3C018008 */  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
/* 03A99C 7F005E6C AC3999E0 */  sw    $t9, %lo(starting_right_weapon)($at)
.L7F005E70:
/* 03A9A0 7F005E70 8E580000 */  lw    $t8, ($s2)
/* 03A9A4 7F005E74 3C018005 */  lui   $at, %hi(D_8004F1D0) # $at, 0x8005
/* 03A9A8 7F005E78 44803000 */  mtc1  $zero, $f6
/* 03A9AC 7F005E7C E7120078 */  swc1  $f18, 0x78($t8)
/* 03A9B0 7F005E80 8E4F0000 */  lw    $t7, ($s2)
/* 03A9B4 7F005E84 C424F1D0 */  lwc1  $f4, %lo(D_8004F1D0)($at)
/* 03A9B8 7F005E88 3C088008 */  lui   $t0, %hi(dword_CODE_bss_80079C68) # $t0, 0x8008
/* 03A9BC 7F005E8C E5E4007C */  swc1  $f4, 0x7c($t7)
/* 03A9C0 7F005E90 8E4E0000 */  lw    $t6, ($s2)
/* 03A9C4 7F005E94 E5C60080 */  swc1  $f6, 0x80($t6)
/* 03A9C8 7F005E98 8D089C68 */  lw    $t0, %lo(dword_CODE_bss_80079C68)($t0)
/* 03A9CC 7F005E9C 5900002C */  blezl $t0, .L7F005F50
/* 03A9D0 7F005EA0 27A4008C */   addiu $a0, $sp, 0x8c
/* 03A9D4 7F005EA4 0FC26919 */  jal   get_num_players
/* 03A9D8 7F005EA8 00000000 */   nop   
/* 03A9DC 7F005EAC 28410002 */  slti  $at, $v0, 2
/* 03A9E0 7F005EB0 14200008 */  bnez  $at, .L7F005ED4
/* 03A9E4 7F005EB4 3C098008 */   lui   $t1, %hi(dword_CODE_bss_80079C68) # $t1, 0x8008
/* 03A9E8 7F005EB8 8D299C68 */  lw    $t1, %lo(dword_CODE_bss_80079C68)($t1)
/* 03A9EC 7F005EBC 59200006 */  blezl $t1, .L7F005ED8
/* 03A9F0 7F005EC0 00001825 */   move  $v1, $zero
/* 03A9F4 7F005EC4 0FC1E43C */  jal   sub_GAME_7F0790F0
/* 03A9F8 7F005EC8 00000000 */   nop   
/* 03A9FC 7F005ECC 10000002 */  b     .L7F005ED8
/* 03AA00 7F005ED0 00401825 */   move  $v1, $v0
.L7F005ED4:
/* 03AA04 7F005ED4 00001825 */  move  $v1, $zero
.L7F005ED8:
/* 03AA08 7F005ED8 3C0A8008 */  lui   $t2, %hi(dword_CODE_bss_80079C28) # $t2, 0x8008
/* 03AA0C 7F005EDC 254A9C28 */  addiu $t2, %lo(dword_CODE_bss_80079C28) # addiu $t2, $t2, -0x63d8
/* 03AA10 7F005EE0 00035880 */  sll   $t3, $v1, 2
/* 03AA14 7F005EE4 016A8821 */  addu  $s1, $t3, $t2
/* 03AA18 7F005EE8 8E300000 */  lw    $s0, ($s1)
/* 03AA1C 7F005EEC C6080000 */  lwc1  $f8, ($s0)
/* 03AA20 7F005EF0 E7A8008C */  swc1  $f8, 0x8c($sp)
/* 03AA24 7F005EF4 C60A0008 */  lwc1  $f10, 8($s0)
/* 03AA28 7F005EF8 8FA5008C */  lw    $a1, 0x8c($sp)
/* 03AA2C 7F005EFC E7AA0094 */  swc1  $f10, 0x94($sp)
/* 03AA30 7F005F00 8E040028 */  lw    $a0, 0x28($s0)
/* 03AA34 7F005F04 8FA60094 */  lw    $a2, 0x94($sp)
/* 03AA38 7F005F08 0FC20358 */  jal   sub_GAME_7F080D60
/* 03AA3C 7F005F0C AFA40084 */   sw    $a0, 0x84($sp)
/* 03AA40 7F005F10 8E420000 */  lw    $v0, ($s2)
/* 03AA44 7F005F14 46000506 */  mov.s $f20, $f0
/* 03AA48 7F005F18 C45029BC */  lwc1  $f16, 0x29bc($v0)
/* 03AA4C 7F005F1C 46008480 */  add.s $f18, $f16, $f0
/* 03AA50 7F005F20 E7B20090 */  swc1  $f18, 0x90($sp)
/* 03AA54 7F005F24 E4400070 */  swc1  $f0, 0x70($v0)
/* 03AA58 7F005F28 8E300000 */  lw    $s0, ($s1)
/* 03AA5C 7F005F2C C60C0018 */  lwc1  $f12, 0x18($s0)
/* 03AA60 7F005F30 0FC16A8C */  jal   convert_angle_using_inverse
/* 03AA64 7F005F34 C60E0020 */   lwc1  $f14, 0x20($s0)
/* 03AA68 7F005F38 3C018005 */  lui   $at, %hi(D_8004F1D4) # $at, 0x8005
/* 03AA6C 7F005F3C C424F1D4 */  lwc1  $f4, %lo(D_8004F1D4)($at)
/* 03AA70 7F005F40 46002181 */  sub.s $f6, $f4, $f0
/* 03AA74 7F005F44 10000011 */  b     .L7F005F8C
/* 03AA78 7F005F48 E7A60088 */   swc1  $f6, 0x88($sp)
/* 03AA7C 7F005F4C 27A4008C */  addiu $a0, $sp, 0x8c
.L7F005F50:
/* 03AA80 7F005F50 27A50090 */  addiu $a1, $sp, 0x90
/* 03AA84 7F005F54 27A60094 */  addiu $a2, $sp, 0x94
/* 03AA88 7F005F58 0FC2BEDE */  jal   sub_GAME_7F0AFB78
/* 03AA8C 7F005F5C 3C0741F0 */   lui   $a3, 0x41f0
/* 03AA90 7F005F60 AFA20084 */  sw    $v0, 0x84($sp)
/* 03AA94 7F005F64 00402025 */  move  $a0, $v0
/* 03AA98 7F005F68 8FA5008C */  lw    $a1, 0x8c($sp)
/* 03AA9C 7F005F6C 0FC20358 */  jal   sub_GAME_7F080D60
/* 03AAA0 7F005F70 8FA60094 */   lw    $a2, 0x94($sp)
/* 03AAA4 7F005F74 8E420000 */  lw    $v0, ($s2)
/* 03AAA8 7F005F78 46000506 */  mov.s $f20, $f0
/* 03AAAC 7F005F7C C44829BC */  lwc1  $f8, 0x29bc($v0)
/* 03AAB0 7F005F80 46004280 */  add.s $f10, $f8, $f0
/* 03AAB4 7F005F84 E7AA0090 */  swc1  $f10, 0x90($sp)
/* 03AAB8 7F005F88 E4400070 */  swc1  $f0, 0x70($v0)
.L7F005F8C:
/* 03AABC 7F005F8C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 03AAC0 7F005F90 44819000 */  mtc1  $at, $f18
/* 03AAC4 7F005F94 C7B00088 */  lwc1  $f16, 0x88($sp)
/* 03AAC8 7F005F98 3C018005 */  lui   $at, %hi(D_8004F1D8) # $at, 0x8005
/* 03AACC 7F005F9C C426F1D8 */  lwc1  $f6, %lo(D_8004F1D8)($at)
/* 03AAD0 7F005FA0 46128102 */  mul.s $f4, $f16, $f18
/* 03AAD4 7F005FA4 8E4C0000 */  lw    $t4, ($s2)
/* 03AAD8 7F005FA8 3C018005 */  lui   $at, %hi(D_8004F1DC) # $at, 0x8005
/* 03AADC 7F005FAC 27A5008C */  addiu $a1, $sp, 0x8c
/* 03AAE0 7F005FB0 46062203 */  div.s $f8, $f4, $f6
/* 03AAE4 7F005FB4 E5880148 */  swc1  $f8, 0x148($t4)
/* 03AAE8 7F005FB8 8E4D0000 */  lw    $t5, ($s2)
/* 03AAEC 7F005FBC E5B40074 */  swc1  $f20, 0x74($t5)
/* 03AAF0 7F005FC0 C42AF1DC */  lwc1  $f10, %lo(D_8004F1DC)($at)
/* 03AAF4 7F005FC4 8E590000 */  lw    $t9, ($s2)
/* 03AAF8 7F005FC8 460AA403 */  div.s $f16, $f20, $f10
/* 03AAFC 7F005FCC E730006C */  swc1  $f16, 0x6c($t9)
/* 03AB00 7F005FD0 8E440000 */  lw    $a0, ($s2)
/* 03AB04 7F005FD4 8FA60084 */  lw    $a2, 0x84($sp)
/* 03AB08 7F005FD8 0FC1F1CC */  jal   change_player_pos_to_target
/* 03AB0C 7F005FDC 24840488 */   addiu $a0, $a0, 0x488
/* 03AB10 7F005FE0 0FC15FAB */  jal   sinf
/* 03AB14 7F005FE4 C7AC0088 */   lwc1  $f12, 0x88($sp)
/* 03AB18 7F005FE8 8E580000 */  lw    $t8, ($s2)
/* 03AB1C 7F005FEC 46000487 */  neg.s $f18, $f0
/* 03AB20 7F005FF0 44802000 */  mtc1  $zero, $f4
/* 03AB24 7F005FF4 E7120498 */  swc1  $f18, 0x498($t8)
/* 03AB28 7F005FF8 8E4F0000 */  lw    $t7, ($s2)
/* 03AB2C 7F005FFC E5E4049C */  swc1  $f4, 0x49c($t7)
/* 03AB30 7F006000 0FC15FA8 */  jal   cosf
/* 03AB34 7F006004 C7AC0088 */   lwc1  $f12, 0x88($sp)
/* 03AB38 7F006008 8E4E0000 */  lw    $t6, ($s2)
/* 03AB3C 7F00600C 3C018003 */  lui   $at, %hi(D_800364D0) # $at, 0x8003
/* 03AB40 7F006010 E5C004A0 */  swc1  $f0, 0x4a0($t6)
/* 03AB44 7F006014 0FC225C6 */  jal   sub_GAME_7F089718
/* 03AB48 7F006018 C42C64D0 */   lwc1  $f12, %lo(D_800364D0)($at)
/* 03AB4C 7F00601C 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079DA0) # $at, 0x8008
/* 03AB50 7F006020 AC209DA0 */  sw    $zero, %lo(dword_CODE_bss_80079DA0)($at)
/* 03AB54 7F006024 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079DA4) # $at, 0x8008
/* 03AB58 7F006028 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80079DA8) # $v0, 0x8008
/* 03AB5C 7F00602C 3C038008 */  lui   $v1, %hi(dword_CODE_bss_80079DC8) # $v1, 0x8008
/* 03AB60 7F006030 24639DC8 */  addiu $v1, %lo(dword_CODE_bss_80079DC8) # addiu $v1, $v1, -0x6238
/* 03AB64 7F006034 24429DA8 */  addiu $v0, %lo(dword_CODE_bss_80079DA8) # addiu $v0, $v0, -0x6258
/* 03AB68 7F006038 AC209DA4 */  sw    $zero, %lo(dword_CODE_bss_80079DA4)($at)
.L7F00603C:
/* 03AB6C 7F00603C 24420010 */  addiu $v0, $v0, 0x10
/* 03AB70 7F006040 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 03AB74 7F006044 AC40FFF8 */  sw    $zero, -8($v0)
/* 03AB78 7F006048 AC40FFFC */  sw    $zero, -4($v0)
/* 03AB7C 7F00604C 1443FFFB */  bne   $v0, $v1, .L7F00603C
/* 03AB80 7F006050 AC40FFF0 */   sw    $zero, -0x10($v0)
/* 03AB84 7F006054 0FC228CC */  jal   reset_intro_camera_message_dialogs_for_BONDdata
/* 03AB88 7F006058 00000000 */   nop   
/* 03AB8C 7F00605C 0FC22A40 */  jal   sub_GAME_7F08A900
/* 03AB90 7F006060 00000000 */   nop   
/* 03AB94 7F006064 0FC0E90C */  jal   remove_last_obj_pos_data_entry
/* 03AB98 7F006068 00000000 */   nop   
/* 03AB9C 7F00606C 8E480000 */  lw    $t0, ($s2)
/* 03ABA0 7F006070 240A0006 */  li    $t2, 6
/* 03ABA4 7F006074 AD0200A8 */  sw    $v0, 0xa8($t0)
/* 03ABA8 7F006078 8E490000 */  lw    $t1, ($s2)
/* 03ABAC 7F00607C 8D2B00A8 */  lw    $t3, 0xa8($t1)
/* 03ABB0 7F006080 AD600004 */  sw    $zero, 4($t3)
/* 03ABB4 7F006084 8E4C0000 */  lw    $t4, ($s2)
/* 03ABB8 7F006088 8D8D00A8 */  lw    $t5, 0xa8($t4)
/* 03ABBC 7F00608C A1AA0000 */  sb    $t2, ($t5)
/* 03ABC0 7F006090 8E590000 */  lw    $t9, ($s2)
/* 03ABC4 7F006094 C7A0008C */  lwc1  $f0, 0x8c($sp)
/* 03ABC8 7F006098 E7200408 */  swc1  $f0, 0x408($t9)
/* 03ABCC 7F00609C 8E580000 */  lw    $t8, ($s2)
/* 03ABD0 7F0060A0 8F0F00A8 */  lw    $t7, 0xa8($t8)
/* 03ABD4 7F0060A4 E5E00008 */  swc1  $f0, 8($t7)
/* 03ABD8 7F0060A8 8E4E0000 */  lw    $t6, ($s2)
/* 03ABDC 7F0060AC C7A00090 */  lwc1  $f0, 0x90($sp)
/* 03ABE0 7F0060B0 E5C0040C */  swc1  $f0, 0x40c($t6)
/* 03ABE4 7F0060B4 8E480000 */  lw    $t0, ($s2)
/* 03ABE8 7F0060B8 8D0900A8 */  lw    $t1, 0xa8($t0)
/* 03ABEC 7F0060BC E520000C */  swc1  $f0, 0xc($t1)
/* 03ABF0 7F0060C0 8E4B0000 */  lw    $t3, ($s2)
/* 03ABF4 7F0060C4 C7A00094 */  lwc1  $f0, 0x94($sp)
/* 03ABF8 7F0060C8 E5600410 */  swc1  $f0, 0x410($t3)
/* 03ABFC 7F0060CC 8E4C0000 */  lw    $t4, ($s2)
/* 03AC00 7F0060D0 8D8A00A8 */  lw    $t2, 0xa8($t4)
/* 03AC04 7F0060D4 E5400010 */  swc1  $f0, 0x10($t2)
/* 03AC08 7F0060D8 8E590000 */  lw    $t9, ($s2)
/* 03AC0C 7F0060DC 8FAD0084 */  lw    $t5, 0x84($sp)
/* 03AC10 7F0060E0 8F3800A8 */  lw    $t8, 0xa8($t9)
/* 03AC14 7F0060E4 AF0D0014 */  sw    $t5, 0x14($t8)
/* 03AC18 7F0060E8 8E4F0000 */  lw    $t7, ($s2)
/* 03AC1C 7F0060EC 0FC0E929 */  jal   set_current_objposdata_plus_0x28
/* 03AC20 7F0060F0 8DE400A8 */   lw    $a0, 0xa8($t7)
/* 03AC24 7F0060F4 8E4E0000 */  lw    $t6, ($s2)
/* 03AC28 7F0060F8 0FC0E901 */  jal   set_stateflag_0x04_for_posdata
/* 03AC2C 7F0060FC 8DC400A8 */   lw    $a0, 0xa8($t6)
/* 03AC30 7F006100 8E420000 */  lw    $v0, ($s2)
/* 03AC34 7F006104 3C018005 */  lui   $at, %hi(D_8004F1E0) # $at, 0x8005
/* 03AC38 7F006108 C420F1E0 */  lwc1  $f0, %lo(D_8004F1E0)($at)
/* 03AC3C 7F00610C C44604B4 */  lwc1  $f6, 0x4b4($v0)
/* 03AC40 7F006110 46003203 */  div.s $f8, $f6, $f0
/* 03AC44 7F006114 E44803B8 */  swc1  $f8, 0x3b8($v0)
/* 03AC48 7F006118 8E420000 */  lw    $v0, ($s2)
/* 03AC4C 7F00611C C44A04B8 */  lwc1  $f10, 0x4b8($v0)
/* 03AC50 7F006120 46005403 */  div.s $f16, $f10, $f0
/* 03AC54 7F006124 E45003BC */  swc1  $f16, 0x3bc($v0)
/* 03AC58 7F006128 8E420000 */  lw    $v0, ($s2)
/* 03AC5C 7F00612C C45204BC */  lwc1  $f18, 0x4bc($v0)
/* 03AC60 7F006130 46009103 */  div.s $f4, $f18, $f0
/* 03AC64 7F006134 0FC26919 */  jal   get_num_players
/* 03AC68 7F006138 E44403C0 */   swc1  $f4, 0x3c0($v0)
/* 03AC6C 7F00613C 24010001 */  li    $at, 1
/* 03AC70 7F006140 14410005 */  bne   $v0, $at, .L7F006158
/* 03AC74 7F006144 00000000 */   nop   
/* 03AC78 7F006148 0FC1EA6E */  jal   set_camera_mode
/* 03AC7C 7F00614C 24040001 */   li    $a0, 1
/* 03AC80 7F006150 10000003 */  b     .L7F006160
/* 03AC84 7F006154 00000000 */   nop   
.L7F006158:
/* 03AC88 7F006158 0FC1EA6E */  jal   set_camera_mode
/* 03AC8C 7F00615C 24040009 */   li    $a0, 9
.L7F006160:
/* 03AC90 7F006160 3C048003 */  lui   $a0, %hi(D_800364D8) # $a0, 0x8003
/* 03AC94 7F006164 248464D8 */  addiu $a0, %lo(D_800364D8) # addiu $a0, $a0, 0x64d8
/* 03AC98 7F006168 00004080 */  sll   $t0, $zero, 2
/* 03AC9C 7F00616C 00884821 */  addu  $t1, $a0, $t0
/* 03ACA0 7F006170 8D2B0000 */  lw    $t3, ($t1)
/* 03ACA4 7F006174 3C038003 */  lui   $v1, %hi(D_8003650C) # $v1, 0x8003
/* 03ACA8 7F006178 2463650C */  addiu $v1, %lo(D_8003650C) # addiu $v1, $v1, 0x650c
/* 03ACAC 7F00617C AC600000 */  sw    $zero, ($v1)
/* 03ACB0 7F006180 11600009 */  beqz  $t3, .L7F0061A8
/* 03ACB4 7F006184 00001025 */   move  $v0, $zero
/* 03ACB8 7F006188 244C0001 */  addiu $t4, $v0, 1
.L7F00618C:
/* 03ACBC 7F00618C 000C5080 */  sll   $t2, $t4, 2
/* 03ACC0 7F006190 008AC821 */  addu  $t9, $a0, $t2
/* 03ACC4 7F006194 8F2D0000 */  lw    $t5, ($t9)
/* 03ACC8 7F006198 AC6C0000 */  sw    $t4, ($v1)
/* 03ACCC 7F00619C 01801025 */  move  $v0, $t4
/* 03ACD0 7F0061A0 55A0FFFA */  bnezl $t5, .L7F00618C
/* 03ACD4 7F0061A4 244C0001 */   addiu $t4, $v0, 1
.L7F0061A8:
/* 03ACD8 7F0061A8 8E4F0000 */  lw    $t7, ($s2)
/* 03ACDC 7F0061AC 24180001 */  li    $t8, 1
/* 03ACE0 7F0061B0 3C018003 */  lui   $at, %hi(D_80036510) # $at, 0x8003
/* 03ACE4 7F0061B4 ADF80420 */  sw    $t8, 0x420($t7)
/* 03ACE8 7F0061B8 8E4E0000 */  lw    $t6, ($s2)
/* 03ACEC 7F0061BC ADC00424 */  sw    $zero, 0x424($t6)
/* 03ACF0 7F0061C0 8E480000 */  lw    $t0, ($s2)
/* 03ACF4 7F0061C4 AD000428 */  sw    $zero, 0x428($t0)
/* 03ACF8 7F0061C8 8FBF0034 */  lw    $ra, 0x34($sp)
/* 03ACFC 7F0061CC 8FB20030 */  lw    $s2, 0x30($sp)
/* 03AD00 7F0061D0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 03AD04 7F0061D4 8FB00028 */  lw    $s0, 0x28($sp)
/* 03AD08 7F0061D8 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 03AD0C 7F0061DC D7B40018 */  ldc1  $f20, 0x18($sp)
/* 03AD10 7F0061E0 AC206510 */  sw    $zero, %lo(D_80036510)($at)
/* 03AD14 7F0061E4 03E00008 */  jr    $ra
/* 03AD18 7F0061E8 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif




