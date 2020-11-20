# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osViSetXScale
/* 00ECD0 7000E0D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00ECD4 7000E0D4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00ECD8 7000E0D8 E7AC0028 */  swc1  $f12, 0x28($sp)
/* 00ECDC 7000E0DC AFB10018 */  sw    $s1, 0x18($sp)
/* 00ECE0 7000E0E0 0C00617C */  jal   __osDisableInt
/* 00ECE4 7000E0E4 AFB00014 */   sw    $s0, 0x14($sp)
/* 00ECE8 7000E0E8 3C0E8003 */  lui   $t6, %hi(__osViNext) 
/* 00ECEC 7000E0EC 8DCE8044 */  lw    $t6, %lo(__osViNext)($t6)
/* 00ECF0 7000E0F0 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 00ECF4 7000E0F4 3C0F8003 */  lui   $t7, %hi(__osViNext) 
/* 00ECF8 7000E0F8 3C088003 */  lui   $t0, %hi(__osViNext) 
/* 00ECFC 7000E0FC E5C40018 */  swc1  $f4, 0x18($t6)
/* 00ED00 7000E100 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00ED04 7000E104 00408825 */  move  $s1, $v0
/* 00ED08 7000E108 95F80000 */  lhu   $t8, ($t7)
/* 00ED0C 7000E10C 37190002 */  ori   $t9, $t8, 2
/* 00ED10 7000E110 A5F90000 */  sh    $t9, ($t7)
/* 00ED14 7000E114 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 00ED18 7000E118 8D090008 */  lw    $t1, 8($t0)
/* 00ED1C 7000E11C C5060018 */  lwc1  $f6, 0x18($t0)
/* 00ED20 7000E120 8D300020 */  lw    $s0, 0x20($t1)
/* 00ED24 7000E124 320A0FFF */  andi  $t2, $s0, 0xfff
/* 00ED28 7000E128 01408025 */  move  $s0, $t2
/* 00ED2C 7000E12C 44904000 */  mtc1  $s0, $f8
/* 00ED30 7000E130 06010005 */  bgez  $s0, .L7000E148
/* 00ED34 7000E134 468042A0 */   cvt.s.w $f10, $f8
/* 00ED38 7000E138 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 00ED3C 7000E13C 44818000 */  mtc1  $at, $f16
/* 00ED40 7000E140 00000000 */  nop   
/* 00ED44 7000E144 46105280 */  add.s $f10, $f10, $f16
.L7000E148:
/* 00ED48 7000E148 460A3482 */  mul.s $f18, $f6, $f10
/* 00ED4C 7000E14C 240C0001 */  li    $t4, 1
/* 00ED50 7000E150 444BF800 */  cfc1  $t3, $31
/* 00ED54 7000E154 44CCF800 */  ctc1  $t4, $31
/* 00ED58 7000E158 00000000 */  nop   
/* 00ED5C 7000E15C 46009124 */  cvt.w.s $f4, $f18
/* 00ED60 7000E160 444CF800 */  cfc1  $t4, $31
/* 00ED64 7000E164 00000000 */  nop   
/* 00ED68 7000E168 31810004 */  andi  $at, $t4, 4
/* 00ED6C 7000E16C 318C0078 */  andi  $t4, $t4, 0x78
/* 00ED70 7000E170 11800013 */  beqz  $t4, .L7000E1C0
/* 00ED74 7000E174 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 00ED78 7000E178 44812000 */  mtc1  $at, $f4
/* 00ED7C 7000E17C 240C0001 */  li    $t4, 1
/* 00ED80 7000E180 46049101 */  sub.s $f4, $f18, $f4
/* 00ED84 7000E184 44CCF800 */  ctc1  $t4, $31
/* 00ED88 7000E188 00000000 */  nop   
/* 00ED8C 7000E18C 46002124 */  cvt.w.s $f4, $f4
/* 00ED90 7000E190 444CF800 */  cfc1  $t4, $31
/* 00ED94 7000E194 00000000 */  nop   
/* 00ED98 7000E198 31810004 */  andi  $at, $t4, 4
/* 00ED9C 7000E19C 318C0078 */  andi  $t4, $t4, 0x78
/* 00EDA0 7000E1A0 15800005 */  bnez  $t4, .L7000E1B8
/* 00EDA4 7000E1A4 00000000 */   nop   
/* 00EDA8 7000E1A8 440C2000 */  mfc1  $t4, $f4
/* 00EDAC 7000E1AC 3C018000 */  lui   $at, 0x8000
/* 00EDB0 7000E1B0 10000007 */  b     .L7000E1D0
/* 00EDB4 7000E1B4 01816025 */   or    $t4, $t4, $at
.L7000E1B8:
/* 00EDB8 7000E1B8 10000005 */  b     .L7000E1D0
/* 00EDBC 7000E1BC 240CFFFF */   li    $t4, -1
.L7000E1C0:
/* 00EDC0 7000E1C0 440C2000 */  mfc1  $t4, $f4
/* 00EDC4 7000E1C4 00000000 */  nop   
/* 00EDC8 7000E1C8 0580FFFB */  bltz  $t4, .L7000E1B8
/* 00EDCC 7000E1CC 00000000 */   nop   
.L7000E1D0:
/* 00EDD0 7000E1D0 44CBF800 */  ctc1  $t3, $31
/* 00EDD4 7000E1D4 318D0FFF */  andi  $t5, $t4, 0xfff
/* 00EDD8 7000E1D8 AD0D0020 */  sw    $t5, 0x20($t0)
/* 00EDDC 7000E1DC 0C006184 */  jal   __osRestoreInt
/* 00EDE0 7000E1E0 02202025 */   move  $a0, $s1
/* 00EDE4 7000E1E4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00EDE8 7000E1E8 8FB00014 */  lw    $s0, 0x14($sp)
/* 00EDEC 7000E1EC 8FB10018 */  lw    $s1, 0x18($sp)
/* 00EDF0 7000E1F0 03E00008 */  jr    $ra
/* 00EDF4 7000E1F4 27BD0028 */   addiu $sp, $sp, 0x28
