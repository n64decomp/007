# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"

.section .text, "ax" 

# ################################################################
.section .rodata
# ################################################################

glabel D_800536C0
.word 0x3fc90fda # /*1.5707963*/
glabel D_800536C4
.word 0x362edef8 # /*0.0000026057805*/
glabel D_800536C8
.word 0xb94fb7ff # /*-0.00019809602*/
glabel D_800536CC
.word 0x3c08876a # /*0.0083330665*/
glabel D_800536D0
.word 0xbe2aaaa6 # /*-0.1666666*/
glabel D_800536D4
.word 0x3ea2f983 # /*0.31830987*/
glabel D_800536D8
.word 0x40490fdb # /*3.1415927*/
glabel D_800536DC
.word 0x330885a3 # /*3.178650856*/
glabel D_800536E0
.word 0x362edef8 # /*0.0000026057805*/
glabel D_800536E4
.word 0xb94fb7ff # /*-0.00019809602*/
glabel D_800536E8
.word 0x3c08876a # /*0.0083330665*/
glabel D_800536EC
.word 0xbe2aaaa6 # /*-0.1666666*/

# ################################################################
.section .text
# ################################################################


# ################################################################
glabel cosf
/* 08C9D0 7F057EA0 3C018005 */  lui   $at, %hi(D_800536C0)
/* 08C9D4 7F057EA4 C42A36C0 */  lwc1  $f10, %lo(D_800536C0)($at)
/* 08C9D8 7F057EA8 460A6300 */  add.s $f12, $f12, $f10


# ################################################################
glabel sinf
/* 08C9DC 7F057EAC 44086000 */  mfc1  $t0, $f12
/* 08C9E0 7F057EB0 00000000 */  nop   
/* 08C9E4 7F057EB4 00084583 */  sra   $t0, $t0, 0x16
/* 08C9E8 7F057EB8 310801FF */  andi  $t0, $t0, 0x1ff
/* 08C9EC 7F057EBC 290100FF */  slti  $at, $t0, 0xff
/* 08C9F0 7F057EC0 10200019 */  beqz  $at, .L7F057F28
/* 08C9F4 7F057EC4 00000000 */   nop   
/* 08C9F8 7F057EC8 290100E6 */  slti  $at, $t0, 0xe6
/* 08C9FC 7F057ECC 1420003D */  bnez  $at, .L7F057FC4
/* 08CA00 7F057ED0 46006006 */   mov.s $f0, $f12
/* 08CA04 7F057ED4 460C6402 */  mul.s $f16, $f12, $f12
/* 08CA08 7F057ED8 3C018005 */  lui   $at, %hi(D_800536C4)
/* 08CA0C 7F057EDC C43236C4 */  lwc1  $f18, %lo(D_800536C4)($at)
/* 08CA10 7F057EE0 46109482 */  mul.s $f18, $f18, $f16
/* 08CA14 7F057EE4 3C018005 */  lui   $at, %hi(D_800536C8)
/* 08CA18 7F057EE8 C42A36C8 */  lwc1  $f10, %lo(D_800536C8)($at)
/* 08CA1C 7F057EEC 46125480 */  add.s $f18, $f10, $f18
/* 08CA20 7F057EF0 46109482 */  mul.s $f18, $f18, $f16
/* 08CA24 7F057EF4 3C018005 */  lui   $at, %hi(D_800536CC)
/* 08CA28 7F057EF8 C42A36CC */  lwc1  $f10, %lo(D_800536CC)($at)
/* 08CA2C 7F057EFC 46125480 */  add.s $f18, $f10, $f18
/* 08CA30 7F057F00 46109482 */  mul.s $f18, $f18, $f16
/* 08CA34 7F057F04 3C018005 */  lui   $at, %hi(D_800536D0)
/* 08CA38 7F057F08 C42A36D0 */  lwc1  $f10, %lo(D_800536D0)($at)
/* 08CA3C 7F057F0C 46125480 */  add.s $f18, $f10, $f18
/* 08CA40 7F057F10 46109482 */  mul.s $f18, $f18, $f16
/* 08CA44 7F057F14 00000000 */  nop   
/* 08CA48 7F057F18 460C9482 */  mul.s $f18, $f18, $f12
/* 08CA4C 7F057F1C 460C9000 */  add.s $f0, $f18, $f12
/* 08CA50 7F057F20 0BC15FF1 */  j     .L7F057FC4
/* 08CA54 7F057F24 00000000 */   nop   

.L7F057F28:
/* 08CA58 7F057F28 29010136 */  slti  $at, $t0, 0x136
/* 08CA5C 7F057F2C 50200025 */  beql  $at, $zero, .L7F057FC4
/* 08CA60 7F057F30 44800000 */   mtc1  $zero, $f0
/* 08CA64 7F057F34 3C018005 */  lui   $at, %hi(D_800536D4)
/* 08CA68 7F057F38 C43036D4 */  lwc1  $f16, %lo(D_800536D4)($at)
/* 08CA6C 7F057F3C 460C8402 */  mul.s $f16, $f16, $f12
/* 08CA70 7F057F40 4600840C */  round.w.s $f16, $f16
/* 08CA74 7F057F44 44098000 */  mfc1  $t1, $f16
/* 08CA78 7F057F48 46808420 */  cvt.s.w $f16, $f16
/* 08CA7C 7F057F4C 3C018005 */  lui   $at, %hi(D_800536D8)
/* 08CA80 7F057F50 C43236D8 */  lwc1  $f18, %lo(D_800536D8)($at)
/* 08CA84 7F057F54 46109482 */  mul.s $f18, $f18, $f16
/* 08CA88 7F057F58 46126301 */  sub.s $f12, $f12, $f18
/* 08CA8C 7F057F5C 3C018005 */  lui   $at, %hi(D_800536DC)
/* 08CA90 7F057F60 C43236DC */  lwc1  $f18, %lo(D_800536DC)($at)
/* 08CA94 7F057F64 46109482 */  mul.s $f18, $f18, $f16
/* 08CA98 7F057F68 46126301 */  sub.s $f12, $f12, $f18
/* 08CA9C 7F057F6C 460C6402 */  mul.s $f16, $f12, $f12
/* 08CAA0 7F057F70 3C018005 */  lui   $at, %hi(D_800536E0)
/* 08CAA4 7F057F74 C43236E0 */  lwc1  $f18, %lo(D_800536E0)($at)
/* 08CAA8 7F057F78 46109482 */  mul.s $f18, $f18, $f16
/* 08CAAC 7F057F7C 3C018005 */  lui   $at, %hi(D_800536E4)
/* 08CAB0 7F057F80 C42A36E4 */  lwc1  $f10, %lo(D_800536E4)($at)
/* 08CAB4 7F057F84 46125480 */  add.s $f18, $f10, $f18
/* 08CAB8 7F057F88 46109482 */  mul.s $f18, $f18, $f16
/* 08CABC 7F057F8C 3C018005 */  lui   $at, %hi(D_800536E8)
/* 08CAC0 7F057F90 C42A36E8 */  lwc1  $f10, %lo(D_800536E8)($at)
/* 08CAC4 7F057F94 46125480 */  add.s $f18, $f10, $f18
/* 08CAC8 7F057F98 46109482 */  mul.s $f18, $f18, $f16
/* 08CACC 7F057F9C 3C018005 */  lui   $at, %hi(D_800536EC)
/* 08CAD0 7F057FA0 C42A36EC */  lwc1  $f10, %lo(D_800536EC)($at)
/* 08CAD4 7F057FA4 46125480 */  add.s $f18, $f10, $f18
/* 08CAD8 7F057FA8 46109482 */  mul.s $f18, $f18, $f16
/* 08CADC 7F057FAC 00000000 */  nop   
/* 08CAE0 7F057FB0 460C9482 */  mul.s $f18, $f18, $f12
/* 08CAE4 7F057FB4 460C9000 */  add.s $f0, $f18, $f12
/* 08CAE8 7F057FB8 31290001 */  andi  $t1, $t1, 1
/* 08CAEC 7F057FBC 55200001 */  bnezl $t1, .L7F057FC4
/* 08CAF0 7F057FC0 46000007 */   neg.s $f0, $f0
.L7F057FC4:
/* 08CAF4 7F057FC4 03E00008 */  jr    $ra
/* 08CAF8 7F057FC8 00000000 */   nop   

