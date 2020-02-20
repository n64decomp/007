# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alSynSetVol
/* 013FA0 700133A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 013FA4 700133A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013FA8 700133A8 AFA50024 */  sw    $a1, 0x24($sp)
/* 013FAC 700133AC AFA60028 */  sw    $a2, 0x28($sp)
/* 013FB0 700133B0 AFA7002C */  sw    $a3, 0x2c($sp)
/* 013FB4 700133B4 8CAF0008 */  lw    $t7, 8($a1)
/* 013FB8 700133B8 51E0001D */  beql  $t7, $zero, .L70013430
/* 013FBC 700133BC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 013FC0 700133C0 0C003C34 */  jal   __allocParam
/* 013FC4 700133C4 AFA40020 */   sw    $a0, 0x20($sp)
/* 013FC8 700133C8 10400018 */  beqz  $v0, .L7001342C
/* 013FCC 700133CC 8FA40020 */   lw    $a0, 0x20($sp)
/* 013FD0 700133D0 8FB90024 */  lw    $t9, 0x24($sp)
/* 013FD4 700133D4 8C98001C */  lw    $t8, 0x1c($a0)
/* 013FD8 700133D8 240B000B */  li    $t3, 11
/* 013FDC 700133DC 8F280008 */  lw    $t0, 8($t9)
/* 013FE0 700133E0 8D0900D8 */  lw    $t1, 0xd8($t0)
/* 013FE4 700133E4 A44B0008 */  sh    $t3, 8($v0)
/* 013FE8 700133E8 03095021 */  addu  $t2, $t8, $t1
/* 013FEC 700133EC AC4A0004 */  sw    $t2, 4($v0)
/* 013FF0 700133F0 87AC002A */  lh    $t4, 0x2a($sp)
/* 013FF4 700133F4 AC4C000C */  sw    $t4, 0xc($v0)
/* 013FF8 700133F8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 013FFC 700133FC 0C003BF2 */  jal   _timeToSamples
/* 014000 70013400 8FA5002C */   lw    $a1, 0x2c($sp)
/* 014004 70013404 8FA6001C */  lw    $a2, 0x1c($sp)
/* 014008 70013408 24050003 */  li    $a1, 3
/* 01400C 7001340C ACC20010 */  sw    $v0, 0x10($a2)
/* 014010 70013410 ACC00000 */  sw    $zero, ($a2)
/* 014014 70013414 8FAD0024 */  lw    $t5, 0x24($sp)
/* 014018 70013418 8DAE0008 */  lw    $t6, 8($t5)
/* 01401C 7001341C 8DC4000C */  lw    $a0, 0xc($t6)
/* 014020 70013420 8C990008 */  lw    $t9, 8($a0)
/* 014024 70013424 0320F809 */  jalr  $t9
/* 014028 70013428 00000000 */  nop   
.L7001342C:
/* 01402C 7001342C 8FBF0014 */  lw    $ra, 0x14($sp)
.L70013430:
/* 014030 70013430 27BD0020 */  addiu $sp, $sp, 0x20
/* 014034 70013434 03E00008 */  jr    $ra
/* 014038 70013438 00000000 */   nop   
