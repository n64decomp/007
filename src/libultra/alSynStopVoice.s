# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alSynStopVoice
/* 014290 70013690 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 014294 70013694 AFBF0014 */  sw    $ra, 0x14($sp)
/* 014298 70013698 AFA40018 */  sw    $a0, 0x18($sp)
/* 01429C 7001369C 8CAE0008 */  lw    $t6, 8($a1)
/* 0142A0 700136A0 51C00016 */  beql  $t6, $zero, .L700136FC
/* 0142A4 700136A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0142A8 700136A8 0C003C34 */  jal   __allocParam
/* 0142AC 700136AC AFA5001C */   sw    $a1, 0x1c($sp)
/* 0142B0 700136B0 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0142B4 700136B4 10400010 */  beqz  $v0, .L700136F8
/* 0142B8 700136B8 00403025 */   move  $a2, $v0
/* 0142BC 700136BC 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0142C0 700136C0 8CF90008 */  lw    $t9, 8($a3)
/* 0142C4 700136C4 240A000F */  li    $t2, 15
/* 0142C8 700136C8 8DF8001C */  lw    $t8, 0x1c($t7)
/* 0142CC 700136CC 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 0142D0 700136D0 A44A0008 */  sh    $t2, 8($v0)
/* 0142D4 700136D4 AC400000 */  sw    $zero, ($v0)
/* 0142D8 700136D8 03084821 */  addu  $t1, $t8, $t0
/* 0142DC 700136DC AC490004 */  sw    $t1, 4($v0)
/* 0142E0 700136E0 8CEB0008 */  lw    $t3, 8($a3)
/* 0142E4 700136E4 24050003 */  li    $a1, 3
/* 0142E8 700136E8 8D64000C */  lw    $a0, 0xc($t3)
/* 0142EC 700136EC 8C990008 */  lw    $t9, 8($a0)
/* 0142F0 700136F0 0320F809 */  jalr  $t9
/* 0142F4 700136F4 00000000 */  nop   
.L700136F8:
/* 0142F8 700136F8 8FBF0014 */  lw    $ra, 0x14($sp)
.L700136FC:
/* 0142FC 700136FC 27BD0018 */  addiu $sp, $sp, 0x18
/* 014300 70013700 03E00008 */  jr    $ra
/* 014304 70013704 00000000 */   nop   
