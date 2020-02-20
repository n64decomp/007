# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alSynSetPitch
/* 014160 70013560 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 014164 70013564 AFBF0014 */  sw    $ra, 0x14($sp)
/* 014168 70013568 AFA40018 */  sw    $a0, 0x18($sp)
/* 01416C 7001356C AFA60020 */  sw    $a2, 0x20($sp)
/* 014170 70013570 8CAE0008 */  lw    $t6, 8($a1)
/* 014174 70013574 51C00018 */  beql  $t6, $zero, .L700135D8
/* 014178 70013578 8FBF0014 */   lw    $ra, 0x14($sp)
/* 01417C 7001357C 0C003C34 */  jal   __allocParam
/* 014180 70013580 AFA5001C */   sw    $a1, 0x1c($sp)
/* 014184 70013584 8FA7001C */  lw    $a3, 0x1c($sp)
/* 014188 70013588 10400012 */  beqz  $v0, .L700135D4
/* 01418C 7001358C 00403025 */   move  $a2, $v0
/* 014190 70013590 8FAF0018 */  lw    $t7, 0x18($sp)
/* 014194 70013594 8CF90008 */  lw    $t9, 8($a3)
/* 014198 70013598 240A0007 */  li    $t2, 7
/* 01419C 7001359C 8DF8001C */  lw    $t8, 0x1c($t7)
/* 0141A0 700135A0 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 0141A4 700135A4 A44A0008 */  sh    $t2, 8($v0)
/* 0141A8 700135A8 24050003 */  li    $a1, 3
/* 0141AC 700135AC 03084821 */  addu  $t1, $t8, $t0
/* 0141B0 700135B0 AC490004 */  sw    $t1, 4($v0)
/* 0141B4 700135B4 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0141B8 700135B8 AC400000 */  sw    $zero, ($v0)
/* 0141BC 700135BC E444000C */  swc1  $f4, 0xc($v0)
/* 0141C0 700135C0 8CEB0008 */  lw    $t3, 8($a3)
/* 0141C4 700135C4 8D64000C */  lw    $a0, 0xc($t3)
/* 0141C8 700135C8 8C990008 */  lw    $t9, 8($a0)
/* 0141CC 700135CC 0320F809 */  jalr  $t9
/* 0141D0 700135D0 00000000 */  nop   
.L700135D4:
/* 0141D4 700135D4 8FBF0014 */  lw    $ra, 0x14($sp)
.L700135D8:
/* 0141D8 700135D8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0141DC 700135DC 03E00008 */  jr    $ra
/* 0141E0 700135E0 00000000 */   nop   
