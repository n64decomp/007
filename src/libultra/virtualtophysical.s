# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osVirtualToPhysical
/* 00F4B0 7000E8B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00F4B4 7000E8B4 AFA40018 */  sw    $a0, 0x18($sp)
/* 00F4B8 7000E8B8 8FAE0018 */  lw    $t6, 0x18($sp)
/* 00F4BC 7000E8BC 3C018000 */  lui   $at, 0x8000
/* 00F4C0 7000E8C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F4C4 7000E8C4 01C1082B */  sltu  $at, $t6, $at
/* 00F4C8 7000E8C8 14200007 */  bnez  $at, .L7000E8E8
/* 00F4CC 7000E8CC 3C01A000 */   lui   $at, 0xa000
/* 00F4D0 7000E8D0 01C1082B */  sltu  $at, $t6, $at
/* 00F4D4 7000E8D4 10200004 */  beqz  $at, .L7000E8E8
/* 00F4D8 7000E8D8 3C011FFF */   lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
/* 00F4DC 7000E8DC 3421FFFF */  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 00F4E0 7000E8E0 1000000E */  b     .L7000E91C
/* 00F4E4 7000E8E4 01C11024 */   and   $v0, $t6, $at
.L7000E8E8:
/* 00F4E8 7000E8E8 8FAF0018 */  lw    $t7, 0x18($sp)
/* 00F4EC 7000E8EC 3C01A000 */  lui   $at, 0xa000
/* 00F4F0 7000E8F0 01E1082B */  sltu  $at, $t7, $at
/* 00F4F4 7000E8F4 14200007 */  bnez  $at, .L7000E914
/* 00F4F8 7000E8F8 3C01C000 */   lui   $at, 0xc000
/* 00F4FC 7000E8FC 01E1082B */  sltu  $at, $t7, $at
/* 00F500 7000E900 10200004 */  beqz  $at, .L7000E914
/* 00F504 7000E904 3C011FFF */   lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
/* 00F508 7000E908 3421FFFF */  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 00F50C 7000E90C 10000003 */  b     .L7000E91C
/* 00F510 7000E910 01E11024 */   and   $v0, $t7, $at
.L7000E914:
/* 00F514 7000E914 0C006408 */  jal   __osProbeTLB
/* 00F518 7000E918 8FA40018 */   lw    $a0, 0x18($sp)
.L7000E91C:
/* 00F51C 7000E91C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F520 7000E920 27BD0018 */  addiu $sp, $sp, 0x18
/* 00F524 7000E924 03E00008 */  jr    $ra
/* 00F528 7000E928 00000000 */   nop   
