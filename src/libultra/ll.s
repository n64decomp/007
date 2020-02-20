# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel __ull_rshift
/* 00F840 7000EC40 AFA40000 */  sw    $a0, ($sp)
/* 00F844 7000EC44 AFA50004 */  sw    $a1, 4($sp)
/* 00F848 7000EC48 AFA60008 */  sw    $a2, 8($sp)
/* 00F84C 7000EC4C AFA7000C */  sw    $a3, 0xc($sp)
/* 00F850 7000EC50 DFAF0008 */  ld    $t7, 8($sp)
/* 00F854 7000EC54 DFAE0000 */  ld    $t6, ($sp)
/* 00F858 7000EC58 01EE1016 */  dsrlv $v0, $t6, $t7
/* 00F85C 7000EC5C 0002183C */  dsll32 $v1, $v0, 0
/* 00F860 7000EC60 0003183F */  dsra32 $v1, $v1, 0
/* 00F864 7000EC64 03E00008 */  jr    $ra
/* 00F868 7000EC68 0002103F */   dsra32 $v0, $v0, 0

glabel __ull_rem
/* 00F86C 7000EC6C AFA40000 */  sw    $a0, ($sp)
/* 00F870 7000EC70 AFA50004 */  sw    $a1, 4($sp)
/* 00F874 7000EC74 AFA60008 */  sw    $a2, 8($sp)
/* 00F878 7000EC78 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F87C 7000EC7C DFAF0008 */  ld    $t7, 8($sp)
/* 00F880 7000EC80 DFAE0000 */  ld    $t6, ($sp)
/* 00F884 7000EC84 01CF001F */  ddivu $zero, $t6, $t7
/* 00F888 7000EC88 15E00002 */  bnez  $t7, .L7000EC94
/* 00F88C 7000EC8C 00000000 */   nop   
/* 00F890 7000EC90 0007000D */  break 7
.L7000EC94:
/* 00F894 7000EC94 00001010 */  mfhi  $v0
/* 00F898 7000EC98 0002183C */  dsll32 $v1, $v0, 0
/* 00F89C 7000EC9C 0003183F */  dsra32 $v1, $v1, 0
/* 00F8A0 7000ECA0 03E00008 */  jr    $ra
/* 00F8A4 7000ECA4 0002103F */   dsra32 $v0, $v0, 0

glabel __ull_div
/* 00F8A8 7000ECA8 AFA40000 */  sw    $a0, ($sp)
/* 00F8AC 7000ECAC AFA50004 */  sw    $a1, 4($sp)
/* 00F8B0 7000ECB0 AFA60008 */  sw    $a2, 8($sp)
/* 00F8B4 7000ECB4 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F8B8 7000ECB8 DFAF0008 */  ld    $t7, 8($sp)
/* 00F8BC 7000ECBC DFAE0000 */  ld    $t6, ($sp)
/* 00F8C0 7000ECC0 01CF001F */  ddivu $zero, $t6, $t7
/* 00F8C4 7000ECC4 15E00002 */  bnez  $t7, .L7000ECD0
/* 00F8C8 7000ECC8 00000000 */   nop   
/* 00F8CC 7000ECCC 0007000D */  break 7
.L7000ECD0:
/* 00F8D0 7000ECD0 00001012 */  mflo  $v0
/* 00F8D4 7000ECD4 0002183C */  dsll32 $v1, $v0, 0
/* 00F8D8 7000ECD8 0003183F */  dsra32 $v1, $v1, 0
/* 00F8DC 7000ECDC 03E00008 */  jr    $ra
/* 00F8E0 7000ECE0 0002103F */   dsra32 $v0, $v0, 0

glabel __ll_lshift
/* 00F8E4 7000ECE4 AFA40000 */  sw    $a0, ($sp)
/* 00F8E8 7000ECE8 AFA50004 */  sw    $a1, 4($sp)
/* 00F8EC 7000ECEC AFA60008 */  sw    $a2, 8($sp)
/* 00F8F0 7000ECF0 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F8F4 7000ECF4 DFAF0008 */  ld    $t7, 8($sp)
/* 00F8F8 7000ECF8 DFAE0000 */  ld    $t6, ($sp)
/* 00F8FC 7000ECFC 01EE1014 */  dsllv $v0, $t6, $t7
/* 00F900 7000ED00 0002183C */  dsll32 $v1, $v0, 0
/* 00F904 7000ED04 0003183F */  dsra32 $v1, $v1, 0
/* 00F908 7000ED08 03E00008 */  jr    $ra
/* 00F90C 7000ED0C 0002103F */   dsra32 $v0, $v0, 0

glabel __ll_rem
/* 00F910 7000ED10 AFA40000 */  sw    $a0, ($sp)
/* 00F914 7000ED14 AFA50004 */  sw    $a1, 4($sp)
/* 00F918 7000ED18 AFA60008 */  sw    $a2, 8($sp)
/* 00F91C 7000ED1C AFA7000C */  sw    $a3, 0xc($sp)
/* 00F920 7000ED20 DFAF0008 */  ld    $t7, 8($sp)
/* 00F924 7000ED24 DFAE0000 */  ld    $t6, ($sp)
/* 00F928 7000ED28 01CF001F */  ddivu $zero, $t6, $t7
/* 00F92C 7000ED2C 15E00002 */  bnez  $t7, .L7000ED38
/* 00F930 7000ED30 00000000 */   nop   
/* 00F934 7000ED34 0007000D */  break 7
.L7000ED38:
/* 00F938 7000ED38 00001010 */  mfhi  $v0
/* 00F93C 7000ED3C 0002183C */  dsll32 $v1, $v0, 0
/* 00F940 7000ED40 0003183F */  dsra32 $v1, $v1, 0
/* 00F944 7000ED44 03E00008 */  jr    $ra
/* 00F948 7000ED48 0002103F */   dsra32 $v0, $v0, 0

glabel __ll_div
/* 00F94C 7000ED4C AFA40000 */  sw    $a0, ($sp)
/* 00F950 7000ED50 AFA50004 */  sw    $a1, 4($sp)
/* 00F954 7000ED54 AFA60008 */  sw    $a2, 8($sp)
/* 00F958 7000ED58 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F95C 7000ED5C DFAF0008 */  ld    $t7, 8($sp)
/* 00F960 7000ED60 DFAE0000 */  ld    $t6, ($sp)
/* 00F964 7000ED64 01CF001E */  ddiv  $zero, $t6, $t7
/* 00F968 7000ED68 00000000 */  nop   
/* 00F96C 7000ED6C 15E00002 */  bnez  $t7, .L7000ED78
/* 00F970 7000ED70 00000000 */   nop   
/* 00F974 7000ED74 0007000D */  break 7
.L7000ED78:
/* 00F978 7000ED78 6401FFFF */  daddiu $at, $zero, -1
/* 00F97C 7000ED7C 15E10005 */  bne   $t7, $at, .L7000ED94
/* 00F980 7000ED80 64010001 */   daddiu $at, $zero, 1
/* 00F984 7000ED84 00010FFC */  dsll32 $at, $at, 0x1f
/* 00F988 7000ED88 15C10002 */  bne   $t6, $at, .L7000ED94
/* 00F98C 7000ED8C 00000000 */   nop   
/* 00F990 7000ED90 0006000D */  break 6
.L7000ED94:
/* 00F994 7000ED94 00001012 */  mflo  $v0
/* 00F998 7000ED98 0002183C */  dsll32 $v1, $v0, 0
/* 00F99C 7000ED9C 0003183F */  dsra32 $v1, $v1, 0
/* 00F9A0 7000EDA0 03E00008 */  jr    $ra
/* 00F9A4 7000EDA4 0002103F */   dsra32 $v0, $v0, 0

glabel __ll_mul
/* 00F9A8 7000EDA8 AFA40000 */  sw    $a0, ($sp)
/* 00F9AC 7000EDAC AFA50004 */  sw    $a1, 4($sp)
/* 00F9B0 7000EDB0 AFA60008 */  sw    $a2, 8($sp)
/* 00F9B4 7000EDB4 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F9B8 7000EDB8 DFAF0008 */  ld    $t7, 8($sp)
/* 00F9BC 7000EDBC DFAE0000 */  ld    $t6, ($sp)
/* 00F9C0 7000EDC0 01CF001D */  dmultu $t6, $t7
/* 00F9C4 7000EDC4 00001012 */  mflo  $v0
/* 00F9C8 7000EDC8 0002183C */  dsll32 $v1, $v0, 0
/* 00F9CC 7000EDCC 0003183F */  dsra32 $v1, $v1, 0
/* 00F9D0 7000EDD0 03E00008 */  jr    $ra
/* 00F9D4 7000EDD4 0002103F */   dsra32 $v0, $v0, 0

glabel __ull_divremi
/* 00F9D8 7000EDD8 87AF0012 */  lh    $t7, 0x12($sp)
/* 00F9DC 7000EDDC AFA60008 */  sw    $a2, 8($sp)
/* 00F9E0 7000EDE0 AFA7000C */  sw    $a3, 0xc($sp)
/* 00F9E4 7000EDE4 DFAE0008 */  ld    $t6, 8($sp)
/* 00F9E8 7000EDE8 01E0C025 */  move  $t8, $t7
/* 00F9EC 7000EDEC 0300C825 */  move  $t9, $t8
/* 00F9F0 7000EDF0 01D9001F */  ddivu $zero, $t6, $t9
/* 00F9F4 7000EDF4 17200002 */  bnez  $t9, .L7000EE00
/* 00F9F8 7000EDF8 00000000 */   nop   
/* 00F9FC 7000EDFC 0007000D */  break 7
.L7000EE00:
/* 00FA00 7000EE00 00004012 */  mflo  $t0
/* 00FA04 7000EE04 FC880000 */  sd    $t0, ($a0)
/* 00FA08 7000EE08 87AA0012 */  lh    $t2, 0x12($sp)
/* 00FA0C 7000EE0C DFA90008 */  ld    $t1, 8($sp)
/* 00FA10 7000EE10 01405825 */  move  $t3, $t2
/* 00FA14 7000EE14 01606025 */  move  $t4, $t3
/* 00FA18 7000EE18 012C001F */  ddivu $zero, $t1, $t4
/* 00FA1C 7000EE1C 15800002 */  bnez  $t4, .L7000EE28
/* 00FA20 7000EE20 00000000 */   nop   
/* 00FA24 7000EE24 0007000D */  break 7
.L7000EE28:
/* 00FA28 7000EE28 00006810 */  mfhi  $t5
/* 00FA2C 7000EE2C FCAD0000 */  sd    $t5, ($a1)
/* 00FA30 7000EE30 03E00008 */  jr    $ra
/* 00FA34 7000EE34 00000000 */   nop   

glabel __ll_mod
/* 00FA38 7000EE38 27BDFFF8 */  addiu $sp, $sp, -8
/* 00FA3C 7000EE3C AFA40008 */  sw    $a0, 8($sp)
/* 00FA40 7000EE40 AFA5000C */  sw    $a1, 0xc($sp)
/* 00FA44 7000EE44 AFA60010 */  sw    $a2, 0x10($sp)
/* 00FA48 7000EE48 AFA70014 */  sw    $a3, 0x14($sp)
/* 00FA4C 7000EE4C DFAF0010 */  ld    $t7, 0x10($sp)
/* 00FA50 7000EE50 DFAE0008 */  ld    $t6, 8($sp)
/* 00FA54 7000EE54 01CF001E */  ddiv  $zero, $t6, $t7
/* 00FA58 7000EE58 00000000 */  nop   
/* 00FA5C 7000EE5C 15E00002 */  bnez  $t7, .L7000EE68
/* 00FA60 7000EE60 00000000 */   nop   
/* 00FA64 7000EE64 0007000D */  break 7
.L7000EE68:
/* 00FA68 7000EE68 6401FFFF */  daddiu $at, $zero, -1
/* 00FA6C 7000EE6C 15E10005 */  bne   $t7, $at, .L7000EE84
/* 00FA70 7000EE70 64010001 */   daddiu $at, $zero, 1
/* 00FA74 7000EE74 00010FFC */  dsll32 $at, $at, 0x1f
/* 00FA78 7000EE78 15C10002 */  bne   $t6, $at, .L7000EE84
/* 00FA7C 7000EE7C 00000000 */   nop   
/* 00FA80 7000EE80 0006000D */  break 6
.L7000EE84:
/* 00FA84 7000EE84 0000C010 */  mfhi  $t8
/* 00FA88 7000EE88 FFB80000 */  sd    $t8, ($sp)
/* 00FA8C 7000EE8C 07010003 */  bgez  $t8, .L7000EE9C
/* 00FA90 7000EE90 00000000 */   nop   
/* 00FA94 7000EE94 1DE00007 */  bgtz  $t7, .L7000EEB4
/* 00FA98 7000EE98 00000000 */   nop   
.L7000EE9C:
/* 00FA9C 7000EE9C DFB90000 */  ld    $t9, ($sp)
/* 00FAA0 7000EEA0 1B200008 */  blez  $t9, .L7000EEC4
/* 00FAA4 7000EEA4 00000000 */   nop   
/* 00FAA8 7000EEA8 DFA80010 */  ld    $t0, 0x10($sp)
/* 00FAAC 7000EEAC 05010005 */  bgez  $t0, .L7000EEC4
/* 00FAB0 7000EEB0 00000000 */   nop   
.L7000EEB4:
/* 00FAB4 7000EEB4 DFA90000 */  ld    $t1, ($sp)
/* 00FAB8 7000EEB8 DFAA0010 */  ld    $t2, 0x10($sp)
/* 00FABC 7000EEBC 012A582D */  daddu $t3, $t1, $t2
/* 00FAC0 7000EEC0 FFAB0000 */  sd    $t3, ($sp)
.L7000EEC4:
/* 00FAC4 7000EEC4 8FA20000 */  lw    $v0, ($sp)
/* 00FAC8 7000EEC8 8FA30004 */  lw    $v1, 4($sp)
/* 00FACC 7000EECC 03E00008 */  jr    $ra
/* 00FAD0 7000EED0 27BD0008 */   addiu $sp, $sp, 8

glabel __ll_rshift
/* 00FAD4 7000EED4 AFA40000 */  sw    $a0, ($sp)
/* 00FAD8 7000EED8 AFA50004 */  sw    $a1, 4($sp)
/* 00FADC 7000EEDC AFA60008 */  sw    $a2, 8($sp)
/* 00FAE0 7000EEE0 AFA7000C */  sw    $a3, 0xc($sp)
/* 00FAE4 7000EEE4 DFAF0008 */  ld    $t7, 8($sp)
/* 00FAE8 7000EEE8 DFAE0000 */  ld    $t6, ($sp)
/* 00FAEC 7000EEEC 01EE1017 */  dsrav $v0, $t6, $t7
/* 00FAF0 7000EEF0 0002183C */  dsll32 $v1, $v0, 0
/* 00FAF4 7000EEF4 0003183F */  dsra32 $v1, $v1, 0
/* 00FAF8 7000EEF8 03E00008 */  jr    $ra
/* 00FAFC 7000EEFC 0002103F */   dsra32 $v0, $v0, 0

glabel osAiSetNextBuffer
/* 00FB00 7000EF00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00FB04 7000EF04 3C0F8002 */  lui   $t7, %hi(B_800276F0) 
/* 00FB08 7000EF08 91EF76F0 */  lbu   $t7, %lo(B_800276F0)($t7)
/* 00FB0C 7000EF0C AFA40020 */  sw    $a0, 0x20($sp)
/* 00FB10 7000EF10 8FAE0020 */  lw    $t6, 0x20($sp)
/* 00FB14 7000EF14 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00FB18 7000EF18 AFA50024 */  sw    $a1, 0x24($sp)
/* 00FB1C 7000EF1C 11E00003 */  beqz  $t7, .L7000EF2C
/* 00FB20 7000EF20 AFAE001C */   sw    $t6, 0x1c($sp)
/* 00FB24 7000EF24 25D8E000 */  addiu $t8, $t6, -0x2000
/* 00FB28 7000EF28 AFB8001C */  sw    $t8, 0x1c($sp)
.L7000EF2C:
/* 00FB2C 7000EF2C 8FB90020 */  lw    $t9, 0x20($sp)
/* 00FB30 7000EF30 8FA80024 */  lw    $t0, 0x24($sp)
/* 00FB34 7000EF34 24012000 */  li    $at, 8192
/* 00FB38 7000EF38 03284821 */  addu  $t1, $t9, $t0
/* 00FB3C 7000EF3C 312A3FFF */  andi  $t2, $t1, 0x3fff
/* 00FB40 7000EF40 15410005 */  bne   $t2, $at, .L7000EF58
/* 00FB44 7000EF44 00000000 */   nop   
/* 00FB48 7000EF48 240B0001 */  li    $t3, 1
/* 00FB4C 7000EF4C 3C018002 */  lui   $at, %hi(B_800276F0)
/* 00FB50 7000EF50 10000003 */  b     .L7000EF60
/* 00FB54 7000EF54 A02B76F0 */   sb    $t3, %lo(B_800276F0)($at)
.L7000EF58:
/* 00FB58 7000EF58 3C018002 */  lui   $at, %hi(B_800276F0)
/* 00FB5C 7000EF5C A02076F0 */  sb    $zero, %lo(B_800276F0)($at)
.L7000EF60:
/* 00FB60 7000EF60 0C00643C */  jal   __osAiDeviceBusy
/* 00FB64 7000EF64 00000000 */   nop   
/* 00FB68 7000EF68 10400003 */  beqz  $v0, .L7000EF78
/* 00FB6C 7000EF6C 00000000 */   nop   
/* 00FB70 7000EF70 10000009 */  b     .L7000EF98
/* 00FB74 7000EF74 2402FFFF */   li    $v0, -1
.L7000EF78:
/* 00FB78 7000EF78 0C003A2C */  jal   osVirtualToPhysical
/* 00FB7C 7000EF7C 8FA4001C */   lw    $a0, 0x1c($sp)
/* 00FB80 7000EF80 3C0CA450 */  lui   $t4, 0xa450
/* 00FB84 7000EF84 AD820000 */  sw    $v0, ($t4)
/* 00FB88 7000EF88 8FAD0024 */  lw    $t5, 0x24($sp)
/* 00FB8C 7000EF8C 3C0FA450 */  lui   $t7, %hi(AI_LEN_REG) # $t7, 0xa450
/* 00FB90 7000EF90 00001025 */  move  $v0, $zero
/* 00FB94 7000EF94 ADED0004 */  sw    $t5, %lo(AI_LEN_REG)($t7)
.L7000EF98:
/* 00FB98 7000EF98 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00FB9C 7000EF9C 27BD0020 */  addiu $sp, $sp, 0x20
/* 00FBA0 7000EFA0 03E00008 */  jr    $ra
/* 00FBA4 7000EFA4 00000000 */   nop   

/* 00FBA8 7000EFA8 00000000 */  nop   
/* 00FBAC 7000EFAC 00000000 */  nop   
.section .data
glabel B_800276F0
.byte 0
