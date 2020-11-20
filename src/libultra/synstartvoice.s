# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alSynStartVoice
/* 014040 70013440 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 014044 70013444 AFBF0014 */  sw    $ra, 0x14($sp)
/* 014048 70013448 AFA40018 */  sw    $a0, 0x18($sp)
/* 01404C 7001344C AFA60020 */  sw    $a2, 0x20($sp)
/* 014050 70013450 8CAE0008 */  lw    $t6, 8($a1)
/* 014054 70013454 51C0001A */  beql  $t6, $zero, .L700134C0
/* 014058 70013458 8FBF0014 */   lw    $ra, 0x14($sp)
/* 01405C 7001345C 0C003C34 */  jal   __allocParam
/* 014060 70013460 AFA5001C */   sw    $a1, 0x1c($sp)
/* 014064 70013464 8FA7001C */  lw    $a3, 0x1c($sp)
/* 014068 70013468 10400014 */  beqz  $v0, .L700134BC
/* 01406C 7001346C 00403025 */   move  $a2, $v0
/* 014070 70013470 8FAF0018 */  lw    $t7, 0x18($sp)
/* 014074 70013474 8CF90008 */  lw    $t9, 8($a3)
/* 014078 70013478 240A000E */  li    $t2, 14
/* 01407C 7001347C 8DF8001C */  lw    $t8, 0x1c($t7)
/* 014080 70013480 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 014084 70013484 A44A0008 */  sh    $t2, 8($v0)
/* 014088 70013488 24050003 */  li    $a1, 3
/* 01408C 7001348C 03084821 */  addu  $t1, $t8, $t0
/* 014090 70013490 AC490004 */  sw    $t1, 4($v0)
/* 014094 70013494 8FAB0020 */  lw    $t3, 0x20($sp)
/* 014098 70013498 AC400000 */  sw    $zero, ($v0)
/* 01409C 7001349C AC4B000C */  sw    $t3, 0xc($v0)
/* 0140A0 700134A0 84EC001A */  lh    $t4, 0x1a($a3)
/* 0140A4 700134A4 A44C000A */  sh    $t4, 0xa($v0)
/* 0140A8 700134A8 8CED0008 */  lw    $t5, 8($a3)
/* 0140AC 700134AC 8DA4000C */  lw    $a0, 0xc($t5)
/* 0140B0 700134B0 8C990008 */  lw    $t9, 8($a0)
/* 0140B4 700134B4 0320F809 */  jalr  $t9
/* 0140B8 700134B8 00000000 */  nop   
.L700134BC:
/* 0140BC 700134BC 8FBF0014 */  lw    $ra, 0x14($sp)
.L700134C0:
/* 0140C0 700134C0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0140C4 700134C4 03E00008 */  jr    $ra
/* 0140C8 700134C8 00000000 */   nop   
