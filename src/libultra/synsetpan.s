# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alSynSetPan
/* 0140D0 700134D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0140D4 700134D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0140D8 700134D8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0140DC 700134DC AFA60020 */  sw    $a2, 0x20($sp)
/* 0140E0 700134E0 8CAE0008 */  lw    $t6, 8($a1)
/* 0140E4 700134E4 51C00018 */  beql  $t6, $zero, .L70013548
/* 0140E8 700134E8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0140EC 700134EC 0C003C34 */  jal   __allocParam
/* 0140F0 700134F0 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0140F4 700134F4 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0140F8 700134F8 10400012 */  beqz  $v0, .L70013544
/* 0140FC 700134FC 00403025 */   move  $a2, $v0
/* 014100 70013500 8FAF0018 */  lw    $t7, 0x18($sp)
/* 014104 70013504 8CF90008 */  lw    $t9, 8($a3)
/* 014108 70013508 240A000C */  li    $t2, 12
/* 01410C 7001350C 8DF8001C */  lw    $t8, 0x1c($t7)
/* 014110 70013510 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 014114 70013514 A44A0008 */  sh    $t2, 8($v0)
/* 014118 70013518 24050003 */  li    $a1, 3
/* 01411C 7001351C 03084821 */  addu  $t1, $t8, $t0
/* 014120 70013520 AC490004 */  sw    $t1, 4($v0)
/* 014124 70013524 93AB0023 */  lbu   $t3, 0x23($sp)
/* 014128 70013528 AC400000 */  sw    $zero, ($v0)
/* 01412C 7001352C AC4B000C */  sw    $t3, 0xc($v0)
/* 014130 70013530 8CEC0008 */  lw    $t4, 8($a3)
/* 014134 70013534 8D84000C */  lw    $a0, 0xc($t4)
/* 014138 70013538 8C990008 */  lw    $t9, 8($a0)
/* 01413C 7001353C 0320F809 */  jalr  $t9
/* 014140 70013540 00000000 */  nop   
.L70013544:
/* 014144 70013544 8FBF0014 */  lw    $ra, 0x14($sp)
.L70013548:
/* 014148 70013548 27BD0018 */  addiu $sp, $sp, 0x18
/* 01414C 7001354C 03E00008 */  jr    $ra
/* 014150 70013550 00000000 */   nop   
