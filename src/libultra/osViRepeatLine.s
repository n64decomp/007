# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osViRepeatLine
/* 00EE60 7000E260 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00EE64 7000E264 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00EE68 7000E268 AFA40028 */  sw    $a0, 0x28($sp)
/* 00EE6C 7000E26C 0C00617C */  jal   __osDisableInt
/* 00EE70 7000E270 AFB00018 */   sw    $s0, 0x18($sp)
/* 00EE74 7000E274 93AE002B */  lbu   $t6, 0x2b($sp)
/* 00EE78 7000E278 00408025 */  move  $s0, $v0
/* 00EE7C 7000E27C 11C00007 */  beqz  $t6, .L7000E29C
/* 00EE80 7000E280 00000000 */   nop   
/* 00EE84 7000E284 3C0F8003 */  lui   $t7, %hi(__osViNext) 
/* 00EE88 7000E288 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00EE8C 7000E28C 95F80000 */  lhu   $t8, ($t7)
/* 00EE90 7000E290 37190040 */  ori   $t9, $t8, 0x40
/* 00EE94 7000E294 10000007 */  b     .L7000E2B4
/* 00EE98 7000E298 A5F90000 */   sh    $t9, ($t7)
.L7000E29C:
/* 00EE9C 7000E29C 3C088003 */  lui   $t0, %hi(__osViNext) 
/* 00EEA0 7000E2A0 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 00EEA4 7000E2A4 2401FFBF */  li    $at, -65
/* 00EEA8 7000E2A8 95090000 */  lhu   $t1, ($t0)
/* 00EEAC 7000E2AC 01215024 */  and   $t2, $t1, $at
/* 00EEB0 7000E2B0 A50A0000 */  sh    $t2, ($t0)
.L7000E2B4:
/* 00EEB4 7000E2B4 0C006184 */  jal   __osRestoreInt
/* 00EEB8 7000E2B8 02002025 */   move  $a0, $s0
/* 00EEBC 7000E2BC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00EEC0 7000E2C0 8FB00018 */  lw    $s0, 0x18($sp)
/* 00EEC4 7000E2C4 27BD0028 */  addiu $sp, $sp, 0x28
/* 00EEC8 7000E2C8 03E00008 */  jr    $ra
/* 00EECC 7000E2CC 00000000 */   nop   
