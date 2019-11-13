#include "ultra64.h"



#ifdef NONMATCHING
void sub_GAME_7F007180(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007180
/* 03BCB0 7F007180 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03BCB4 7F007184 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BCB8 7F007188 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 03BCBC 7F00718C 00000000 */   nop   
/* 03BCC0 7F007190 0FC26919 */  jal   get_num_players
/* 03BCC4 7F007194 AFA20018 */   sw    $v0, 0x18($sp)
/* 03BCC8 7F007198 240E00C8 */  li    $t6, 200
/* 03BCCC 7F00719C 01C2001A */  div   $zero, $t6, $v0
/* 03BCD0 7F0071A0 8FA30018 */  lw    $v1, 0x18($sp)
/* 03BCD4 7F0071A4 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A160)
/* 03BCD8 7F0071A8 24C6A160 */  addiu $a2, %lo(dword_CODE_bss_8007A160) # addiu $a2, $a2, -0x5ea0
/* 03BCDC 7F0071AC 14400002 */  bnez  $v0, .L7F0071B8
/* 03BCE0 7F0071B0 00000000 */   nop   
/* 03BCE4 7F0071B4 0007000D */  break 7
.L7F0071B8:
/* 03BCE8 7F0071B8 2401FFFF */  li    $at, -1
/* 03BCEC 7F0071BC 14410004 */  bne   $v0, $at, .L7F0071D0
/* 03BCF0 7F0071C0 3C018000 */   lui   $at, 0x8000
/* 03BCF4 7F0071C4 15C10002 */  bne   $t6, $at, .L7F0071D0
/* 03BCF8 7F0071C8 00000000 */   nop   
/* 03BCFC 7F0071CC 0006000D */  break 6
.L7F0071D0:
/* 03BD00 7F0071D0 00007812 */  mflo  $t7
/* 03BD04 7F0071D4 2401001D */  li    $at, 29
/* 03BD08 7F0071D8 10610004 */  beq   $v1, $at, .L7F0071EC
/* 03BD0C 7F0071DC ACCF0000 */   sw    $t7, ($a2)
/* 03BD10 7F0071E0 2401001E */  li    $at, 30
/* 03BD14 7F0071E4 54610005 */  bnel  $v1, $at, .L7F0071FC
/* 03BD18 7F0071E8 8CC40000 */   lw    $a0, ($a2)
.L7F0071EC:
/* 03BD1C 7F0071EC 8CD80000 */  lw    $t8, ($a2)
/* 03BD20 7F0071F0 0018C843 */  sra   $t9, $t8, 1
/* 03BD24 7F0071F4 ACD90000 */  sw    $t9, ($a2)
/* 03BD28 7F0071F8 8CC40000 */  lw    $a0, ($a2)
.L7F0071FC:
/* 03BD2C 7F0071FC 2401FFF0 */  li    $at, -16
/* 03BD30 7F007200 24050004 */  li    $a1, 4
/* 03BD34 7F007204 00044080 */  sll   $t0, $a0, 2
/* 03BD38 7F007208 01044023 */  subu  $t0, $t0, $a0
/* 03BD3C 7F00720C 00084080 */  sll   $t0, $t0, 2
/* 03BD40 7F007210 01044021 */  addu  $t0, $t0, $a0
/* 03BD44 7F007214 000840C0 */  sll   $t0, $t0, 3
/* 03BD48 7F007218 2504000F */  addiu $a0, $t0, 0xf
/* 03BD4C 7F00721C 00814824 */  and   $t1, $a0, $at
/* 03BD50 7F007220 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03BD54 7F007224 01202025 */   move  $a0, $t1
/* 03BD58 7F007228 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A160)
/* 03BD5C 7F00722C 24C6A160 */  addiu $a2, %lo(dword_CODE_bss_8007A160) # addiu $a2, $a2, -0x5ea0
/* 03BD60 7F007230 8CCA0000 */  lw    $t2, ($a2)
/* 03BD64 7F007234 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A164)
/* 03BD68 7F007238 2484A164 */  addiu $a0, %lo(dword_CODE_bss_8007A164) # addiu $a0, $a0, -0x5e9c
/* 03BD6C 7F00723C AC820000 */  sw    $v0, ($a0)
/* 03BD70 7F007240 1940000B */  blez  $t2, .L7F007270
/* 03BD74 7F007244 00001825 */   move  $v1, $zero
/* 03BD78 7F007248 00001025 */  move  $v0, $zero
/* 03BD7C 7F00724C 8C8B0000 */  lw    $t3, ($a0)
.L7F007250:
/* 03BD80 7F007250 24630001 */  addiu $v1, $v1, 1
/* 03BD84 7F007254 01626021 */  addu  $t4, $t3, $v0
/* 03BD88 7F007258 AD800000 */  sw    $zero, ($t4)
/* 03BD8C 7F00725C 8CCD0000 */  lw    $t5, ($a2)
/* 03BD90 7F007260 24420068 */  addiu $v0, $v0, 0x68
/* 03BD94 7F007264 006D082A */  slt   $at, $v1, $t5
/* 03BD98 7F007268 5420FFF9 */  bnezl $at, .L7F007250
/* 03BD9C 7F00726C 8C8B0000 */   lw    $t3, ($a0)
.L7F007270:
/* 03BDA0 7F007270 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BDA4 7F007274 3C018004 */  lui   $at, %hi(D_80040940)
/* 03BDA8 7F007278 AC200940 */  sw    $zero, %lo(D_80040940)($at)
/* 03BDAC 7F00727C 03E00008 */  jr    $ra
/* 03BDB0 7F007280 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

