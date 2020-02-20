# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osAiSetFrequency
/* 00F530 7000E930 3C0E8003 */  lui   $t6, %hi(osViClock)#%hi(osViClock) 
/* 00F534 7000E934 8DCE804C */  lw    $t6, %lo(osViClock)($t6)#%lo(osViClock)($t6)
/* 00F538 7000E938 44844000 */  mtc1  $a0, $f8
/* 00F53C 7000E93C 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 00F540 7000E940 448E2000 */  mtc1  $t6, $f4
/* 00F544 7000E944 468042A0 */  cvt.s.w $f10, $f8
/* 00F548 7000E948 04810005 */  bgez  $a0, .L7000E960
/* 00F54C 7000E94C 468021A0 */   cvt.s.w $f6, $f4
/* 00F550 7000E950 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 00F554 7000E954 44818000 */  mtc1  $at, $f16
/* 00F558 7000E958 00000000 */  nop   
/* 00F55C 7000E95C 46105280 */  add.s $f10, $f10, $f16
.L7000E960:
/* 00F560 7000E960 460A3483 */  div.s $f18, $f6, $f10
/* 00F564 7000E964 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 00F568 7000E968 44812000 */  mtc1  $at, $f4
/* 00F56C 7000E96C 24050001 */  li    $a1, 1
/* 00F570 7000E970 46049300 */  add.s $f12, $f18, $f4
/* 00F574 7000E974 444FF800 */  cfc1  $t7, $31
/* 00F578 7000E978 44C5F800 */  ctc1  $a1, $31
/* 00F57C 7000E97C 00000000 */  nop   
/* 00F580 7000E980 46006224 */  cvt.w.s $f8, $f12
/* 00F584 7000E984 4445F800 */  cfc1  $a1, $31
/* 00F588 7000E988 00000000 */  nop   
/* 00F58C 7000E98C 30A10004 */  andi  $at, $a1, 4
/* 00F590 7000E990 30A50078 */  andi  $a1, $a1, 0x78
/* 00F594 7000E994 10A00013 */  beqz  $a1, .L7000E9E4
/* 00F598 7000E998 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 00F59C 7000E99C 44814000 */  mtc1  $at, $f8
/* 00F5A0 7000E9A0 24050001 */  li    $a1, 1
/* 00F5A4 7000E9A4 46086201 */  sub.s $f8, $f12, $f8
/* 00F5A8 7000E9A8 44C5F800 */  ctc1  $a1, $31
/* 00F5AC 7000E9AC 00000000 */  nop   
/* 00F5B0 7000E9B0 46004224 */  cvt.w.s $f8, $f8
/* 00F5B4 7000E9B4 4445F800 */  cfc1  $a1, $31
/* 00F5B8 7000E9B8 00000000 */  nop   
/* 00F5BC 7000E9BC 30A10004 */  andi  $at, $a1, 4
/* 00F5C0 7000E9C0 30A50078 */  andi  $a1, $a1, 0x78
/* 00F5C4 7000E9C4 14A00005 */  bnez  $a1, .L7000E9DC
/* 00F5C8 7000E9C8 00000000 */   nop   
/* 00F5CC 7000E9CC 44054000 */  mfc1  $a1, $f8
/* 00F5D0 7000E9D0 3C018000 */  lui   $at, 0x8000
/* 00F5D4 7000E9D4 10000007 */  b     .L7000E9F4
/* 00F5D8 7000E9D8 00A12825 */   or    $a1, $a1, $at
.L7000E9DC:
/* 00F5DC 7000E9DC 10000005 */  b     .L7000E9F4
/* 00F5E0 7000E9E0 2405FFFF */   li    $a1, -1
.L7000E9E4:
/* 00F5E4 7000E9E4 44054000 */  mfc1  $a1, $f8
/* 00F5E8 7000E9E8 00000000 */  nop   
/* 00F5EC 7000E9EC 04A0FFFB */  bltz  $a1, .L7000E9DC
/* 00F5F0 7000E9F0 00000000 */   nop   
.L7000E9F4:
/* 00F5F4 7000E9F4 44CFF800 */  ctc1  $t7, $31
/* 00F5F8 7000E9F8 2CA10084 */  sltiu $at, $a1, 0x84
/* 00F5FC 7000E9FC 10200003 */  beqz  $at, .L7000EA0C
/* 00F600 7000EA00 00000000 */   nop   
/* 00F604 7000EA04 10000020 */  b     .L7000EA88
/* 00F608 7000EA08 2402FFFF */   li    $v0, -1
.L7000EA0C:
/* 00F60C 7000EA0C 24010042 */  li    $at, 66
/* 00F610 7000EA10 00A1001B */  divu  $zero, $a1, $at
/* 00F614 7000EA14 00003012 */  mflo  $a2
/* 00F618 7000EA18 30D800FF */  andi  $t8, $a2, 0xff
/* 00F61C 7000EA1C 03003025 */  move  $a2, $t8
/* 00F620 7000EA20 28C10011 */  slti  $at, $a2, 0x11
/* 00F624 7000EA24 14200002 */  bnez  $at, .L7000EA30
/* 00F628 7000EA28 00000000 */   nop   
/* 00F62C 7000EA2C 24060010 */  li    $a2, 16
.L7000EA30:
/* 00F630 7000EA30 24B9FFFF */  addiu $t9, $a1, -1
/* 00F634 7000EA34 3C08A450 */  lui   $t0, %hi(AI_DACRATE_REG) # $t0, 0xa450
/* 00F638 7000EA38 AD190010 */  sw    $t9, %lo(AI_DACRATE_REG)($t0)
/* 00F63C 7000EA3C 24C9FFFF */  addiu $t1, $a2, -1
/* 00F640 7000EA40 3C0AA450 */  lui   $t2, %hi(AI_BITRATE_REG) # $t2, 0xa450
/* 00F644 7000EA44 AD490014 */  sw    $t1, %lo(AI_BITRATE_REG)($t2)
/* 00F648 7000EA48 240B0001 */  li    $t3, 1
/* 00F64C 7000EA4C 3C0CA450 */  lui   $t4, %hi(AI_CONTROL_REG) # $t4, 0xa450
/* 00F650 7000EA50 AD8B0008 */  sw    $t3, %lo(AI_CONTROL_REG)($t4)
/* 00F654 7000EA54 3C0D8003 */  lui   $t5, %hi(osViClock)  #osViClock
/* 00F658 7000EA58 8DAD804C */  lw    $t5, %lo(osViClock)($t5) #osViClock
/* 00F65C 7000EA5C 01A5001A */  div   $zero, $t5, $a1
/* 00F660 7000EA60 00001012 */  mflo  $v0
/* 00F664 7000EA64 14A00002 */  bnez  $a1, .L7000EA70
/* 00F668 7000EA68 00000000 */   nop   
/* 00F66C 7000EA6C 0007000D */  break 7
.L7000EA70:
/* 00F670 7000EA70 2401FFFF */  li    $at, -1
/* 00F674 7000EA74 14A10004 */  bne   $a1, $at, .L7000EA88
/* 00F678 7000EA78 3C018000 */   lui   $at, 0x8000
/* 00F67C 7000EA7C 15A10002 */  bne   $t5, $at, .L7000EA88
/* 00F680 7000EA80 00000000 */   nop   
/* 00F684 7000EA84 0006000D */  break 6
.L7000EA88:
/* 00F688 7000EA88 03E00008 */  jr    $ra
/* 00F68C 7000EA8C 27BD0010 */   addiu $sp, $sp, 0x10
