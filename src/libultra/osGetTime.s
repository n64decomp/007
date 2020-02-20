# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osGetTime
/* 00F7B0 7000EBB0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00F7B4 7000EBB4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00F7B8 7000EBB8 0C00617C */  jal   __osDisableInt
/* 00F7BC 7000EBBC AFB00018 */   sw    $s0, 0x18($sp)
/* 00F7C0 7000EBC0 0C003638 */  jal   osGetCount
/* 00F7C4 7000EBC4 00408025 */   move  $s0, $v0
/* 00F7C8 7000EBC8 AFA20034 */  sw    $v0, 0x34($sp)
/* 00F7CC 7000EBCC 3C0F8007 */  lui   $t7, %hi(__osBaseCounter) 
/* 00F7D0 7000EBD0 8DEF8E18 */  lw    $t7, %lo(__osBaseCounter)($t7)
/* 00F7D4 7000EBD4 8FAE0034 */  lw    $t6, 0x34($sp)
/* 00F7D8 7000EBD8 3C088007 */  lui   $t0, %hi(__osCurrentTime) 
/* 00F7DC 7000EBDC 3C098007 */  lui   $t1, %hi(__osCurrentTime+4) 
/* 00F7E0 7000EBE0 8D298E14 */  lw    $t1, %lo(__osCurrentTime+4)($t1)
/* 00F7E4 7000EBE4 8D088E10 */  lw    $t0, %lo(__osCurrentTime)($t0)
/* 00F7E8 7000EBE8 01CFC023 */  subu  $t8, $t6, $t7
/* 00F7EC 7000EBEC AFB80030 */  sw    $t8, 0x30($sp)
/* 00F7F0 7000EBF0 02002025 */  move  $a0, $s0
/* 00F7F4 7000EBF4 AFA9002C */  sw    $t1, 0x2c($sp)
/* 00F7F8 7000EBF8 0C006184 */  jal   __osRestoreInt
/* 00F7FC 7000EBFC AFA80028 */   sw    $t0, 0x28($sp)
/* 00F800 7000EC00 8FB90030 */  lw    $t9, 0x30($sp)
/* 00F804 7000EC04 8FAD002C */  lw    $t5, 0x2c($sp)
/* 00F808 7000EC08 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00F80C 7000EC0C 03205825 */  move  $t3, $t9
/* 00F810 7000EC10 016D1821 */  addu  $v1, $t3, $t5
/* 00F814 7000EC14 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00F818 7000EC18 240A0000 */  li    $t2, 0
/* 00F81C 7000EC1C 006D082B */  sltu  $at, $v1, $t5
/* 00F820 7000EC20 002A1021 */  addu  $v0, $at, $t2
/* 00F824 7000EC24 8FB00018 */  lw    $s0, 0x18($sp)
/* 00F828 7000EC28 27BD0038 */  addiu $sp, $sp, 0x38
/* 00F82C 7000EC2C 03E00008 */  jr    $ra
/* 00F830 7000EC30 004C1021 */   addu  $v0, $v0, $t4
