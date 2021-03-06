# Goldeneye 007 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
.section .text
glabel lldiv
/* 021750 70020B50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 021754 70020B54 AFA40030 */  sw    $a0, 0x30($sp)
/* 021758 70020B58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 02175C 70020B5C AFA60038 */  sw    $a2, 0x38($sp)
/* 021760 70020B60 AFA7003C */  sw    $a3, 0x3c($sp)
/* 021764 70020B64 00C02025 */  move  $a0, $a2
/* 021768 70020B68 00E02825 */  move  $a1, $a3
/* 02176C 70020B6C 8FA70044 */  lw    $a3, 0x44($sp)
/* 021770 70020B70 0C003B53 */  jal   __ll_div
/* 021774 70020B74 8FA60040 */   lw    $a2, 0x40($sp)
/* 021778 70020B78 AFA20020 */  sw    $v0, 0x20($sp)
/* 02177C 70020B7C AFA30024 */  sw    $v1, 0x24($sp)
/* 021780 70020B80 8FA40040 */  lw    $a0, 0x40($sp)
/* 021784 70020B84 8FA50044 */  lw    $a1, 0x44($sp)
/* 021788 70020B88 00403025 */  move  $a2, $v0
/* 02178C 70020B8C 0C003B6A */  jal   __ll_mul
/* 021790 70020B90 00603825 */   move  $a3, $v1
/* 021794 70020B94 8FAE0038 */  lw    $t6, 0x38($sp)
/* 021798 70020B98 8FAF003C */  lw    $t7, 0x3c($sp)
/* 02179C 70020B9C 8FA80020 */  lw    $t0, 0x20($sp)
/* 0217A0 70020BA0 01C2C023 */  subu  $t8, $t6, $v0
/* 0217A4 70020BA4 01E3082B */  sltu  $at, $t7, $v1
/* 0217A8 70020BA8 0301C023 */  subu  $t8, $t8, $at
/* 0217AC 70020BAC 01E3C823 */  subu  $t9, $t7, $v1
/* 0217B0 70020BB0 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0217B4 70020BB4 AFB80028 */  sw    $t8, 0x28($sp)
/* 0217B8 70020BB8 1D000017 */  bgtz  $t0, .L70020C18
/* 0217BC 70020BBC 8FA90024 */   lw    $t1, 0x24($sp)
/* 0217C0 70020BC0 05000003 */  bltz  $t0, .L70020BD0
/* 0217C4 70020BC4 00000000 */   nop   
/* 0217C8 70020BC8 10000014 */  b     .L70020C1C
/* 0217CC 70020BCC 27A80020 */   addiu $t0, $sp, 0x20
.L70020BD0:
/* 0217D0 70020BD0 07020012 */  bltzl $t8, .L70020C1C
/* 0217D4 70020BD4 27A80020 */   addiu $t0, $sp, 0x20
/* 0217D8 70020BD8 1F000003 */  bgtz  $t8, .L70020BE8
/* 0217DC 70020BDC 252B0001 */   addiu $t3, $t1, 1
/* 0217E0 70020BE0 5320000E */  beql  $t9, $zero, .L70020C1C
/* 0217E4 70020BE4 27A80020 */   addiu $t0, $sp, 0x20
.L70020BE8:
/* 0217E8 70020BE8 8FAC0040 */  lw    $t4, 0x40($sp)
/* 0217EC 70020BEC 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0217F0 70020BF0 2D610001 */  sltiu $at, $t3, 1
/* 0217F4 70020BF4 01015021 */  addu  $t2, $t0, $at
/* 0217F8 70020BF8 030C7023 */  subu  $t6, $t8, $t4
/* 0217FC 70020BFC 032D082B */  sltu  $at, $t9, $t5
/* 021800 70020C00 01C17023 */  subu  $t6, $t6, $at
/* 021804 70020C04 032D7823 */  subu  $t7, $t9, $t5
/* 021808 70020C08 AFAA0020 */  sw    $t2, 0x20($sp)
/* 02180C 70020C0C AFAB0024 */  sw    $t3, 0x24($sp)
/* 021810 70020C10 AFAF002C */  sw    $t7, 0x2c($sp)
/* 021814 70020C14 AFAE0028 */  sw    $t6, 0x28($sp)
.L70020C18:
/* 021818 70020C18 27A80020 */  addiu $t0, $sp, 0x20
.L70020C1C:
/* 02181C 70020C1C 8FA20030 */  lw    $v0, 0x30($sp)
/* 021820 70020C20 8D010000 */  lw    $at, ($t0)
/* 021824 70020C24 AC410000 */  sw    $at, ($v0)
/* 021828 70020C28 8D0B0004 */  lw    $t3, 4($t0)
/* 02182C 70020C2C AC4B0004 */  sw    $t3, 4($v0)
/* 021830 70020C30 8D010008 */  lw    $at, 8($t0)
/* 021834 70020C34 AC410008 */  sw    $at, 8($v0)
/* 021838 70020C38 8D0B000C */  lw    $t3, 0xc($t0)
/* 02183C 70020C3C AC4B000C */  sw    $t3, 0xc($v0)
/* 021840 70020C40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 021844 70020C44 27BD0030 */  addiu $sp, $sp, 0x30
/* 021848 70020C48 03E00008 */  jr    $ra
/* 02184C 70020C4C 00000000 */   nop   

glabel ldiv
/* 021850 70020C50 00A6001A */  div   $zero, $a1, $a2
/* 021854 70020C54 00001012 */  mflo  $v0
/* 021858 70020C58 27BDFFF8 */  addiu $sp, $sp, -8
/* 02185C 70020C5C 14C00002 */  bnez  $a2, .L70020C68
/* 021860 70020C60 00000000 */   nop   
/* 021864 70020C64 0007000D */  break 7
.L70020C68:
/* 021868 70020C68 2401FFFF */  li    $at, -1
/* 02186C 70020C6C 14C10004 */  bne   $a2, $at, .L70020C80
/* 021870 70020C70 3C018000 */   lui   $at, 0x8000
/* 021874 70020C74 14A10002 */  bne   $a1, $at, .L70020C80
/* 021878 70020C78 00000000 */   nop   
/* 02187C 70020C7C 0006000D */  break 6
.L70020C80:
/* 021880 70020C80 00C20019 */  multu $a2, $v0
/* 021884 70020C84 AFA20000 */  sw    $v0, ($sp)
/* 021888 70020C88 27AF0000 */  addiu $t7, $sp, 0
/* 02188C 70020C8C 00007012 */  mflo  $t6
/* 021890 70020C90 00AE1823 */  subu  $v1, $a1, $t6
/* 021894 70020C94 04410008 */  bgez  $v0, .L70020CB8
/* 021898 70020C98 AFA30004 */   sw    $v1, 4($sp)
/* 02189C 70020C9C AFA20000 */  sw    $v0, ($sp)
/* 0218A0 70020CA0 18600005 */  blez  $v1, .L70020CB8
/* 0218A4 70020CA4 AFA30004 */   sw    $v1, 4($sp)
/* 0218A8 70020CA8 24420001 */  addiu $v0, $v0, 1
/* 0218AC 70020CAC 00661823 */  subu  $v1, $v1, $a2
/* 0218B0 70020CB0 AFA30004 */  sw    $v1, 4($sp)
/* 0218B4 70020CB4 AFA20000 */  sw    $v0, ($sp)
.L70020CB8:
/* 0218B8 70020CB8 8DE10000 */  lw    $at, ($t7)
/* 0218BC 70020CBC 00801025 */  move  $v0, $a0
/* 0218C0 70020CC0 AC810000 */  sw    $at, ($a0)
/* 0218C4 70020CC4 8DE80004 */  lw    $t0, 4($t7)
/* 0218C8 70020CC8 27BD0008 */  addiu $sp, $sp, 8
/* 0218CC 70020CCC 03E00008 */  jr    $ra
/* 0218D0 70020CD0 AC880004 */   sw    $t0, 4($a0)

