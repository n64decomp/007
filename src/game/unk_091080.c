#include "ultra64.h"

// bss
//CODE.bss:80079E20
s32 dword_CODE_bss_80079E20;


// data
//D:80037010
s32 D_80037010 = 0;
//D:80037014
f32 stanbondx = 0.0f;
//D:80037018
s32 stanbondy = 0;
//D:8003701C
s32 stanbondz = 0;
//D:80037020
s32 D_80037020 = 0;
//D:80037024
s32 D_80037024 = 0;
//D:80037028
f32 D_80037028 = -1.0;
//D:8003702C
s32 D_8003702C = 0;
//D:80037030
f32 D_80037030 = 1.0;
//D:80037034
s32 D_80037034 = 0;
//D:80037038
s32 D_80037038 = 0;
//D:8003703C
f32 D_8003703C = 1.0;
//D:80037040
s32 D_80037040 = 0;
//D:80037044
s32 D_80037044 = 0;
//D:80037048
f32 D_80037048 = 1.0;
//D:8003704C
s32 D_8003704C = 0;
//D:80037050
f32 D_80037050 = 1.0;
//D:80037054
s32 D_80037054 = 0;
//D:80037058
f32 D_80037058 = 1.0;
//D:8003705C
f32 D_8003705C = 1.0;
//D:80037060
s32 D_80037060 = 0;
//D:80037064
s32 D_80037064 = 0;
//D:80037068
s32 D_80037068 = 0;


// rodata


#ifdef NONMATCHING
void sub_GAME_7F091080(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80055850
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055854
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055858
.word 0x3c8efa35 /*0.017453292*/
glabel D_8005585C
.word 0x3c8efa35 /*0.017453292*/
.text
glabel sub_GAME_7F091080
/* 0C5BB0 7F091080 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C5BB4 7F091084 AFA40018 */  sw    $a0, 0x18($sp)
/* 0C5BB8 7F091088 83AF001B */  lb    $t7, 0x1b($sp)
/* 0C5BBC 7F09108C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C5BC0 7F091090 44810000 */  mtc1  $at, $f0
/* 0C5BC4 7F091094 00053E00 */  sll   $a3, $a1, 0x18
/* 0C5BC8 7F091098 00077603 */  sra   $t6, $a3, 0x18
/* 0C5BCC 7F09109C 29E1FFFD */  slti  $at, $t7, -3
/* 0C5BD0 7F0910A0 01C03825 */  move  $a3, $t6
/* 0C5BD4 7F0910A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C5BD8 7F0910A8 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C5BDC 7F0910AC AFA60020 */  sw    $a2, 0x20($sp)
/* 0C5BE0 7F0910B0 10200004 */  beqz  $at, .L7F0910C4
/* 0C5BE4 7F0910B4 46000086 */   mov.s $f2, $f0
/* 0C5BE8 7F0910B8 25F80003 */  addiu $t8, $t7, 3
/* 0C5BEC 7F0910BC 10000008 */  b     .L7F0910E0
/* 0C5BF0 7F0910C0 A3B8001B */   sb    $t8, 0x1b($sp)
.L7F0910C4:
/* 0C5BF4 7F0910C4 83B9001B */  lb    $t9, 0x1b($sp)
/* 0C5BF8 7F0910C8 2B210004 */  slti  $at, $t9, 4
/* 0C5BFC 7F0910CC 14200003 */  bnez  $at, .L7F0910DC
/* 0C5C00 7F0910D0 2728FFFD */   addiu $t0, $t9, -3
/* 0C5C04 7F0910D4 10000002 */  b     .L7F0910E0
/* 0C5C08 7F0910D8 A3A8001B */   sb    $t0, 0x1b($sp)
.L7F0910DC:
/* 0C5C0C 7F0910DC A3A0001B */  sb    $zero, 0x1b($sp)
.L7F0910E0:
/* 0C5C10 7F0910E0 28E1FFFD */  slti  $at, $a3, -3
/* 0C5C14 7F0910E4 10200005 */  beqz  $at, .L7F0910FC
/* 0C5C18 7F0910E8 97A50022 */   lhu   $a1, 0x22($sp)
/* 0C5C1C 7F0910EC 24E70003 */  addiu $a3, $a3, 3
/* 0C5C20 7F0910F0 00074E00 */  sll   $t1, $a3, 0x18
/* 0C5C24 7F0910F4 10000008 */  b     .L7F091118
/* 0C5C28 7F0910F8 00093E03 */   sra   $a3, $t1, 0x18
.L7F0910FC:
/* 0C5C2C 7F0910FC 28E10004 */  slti  $at, $a3, 4
/* 0C5C30 7F091100 14200004 */  bnez  $at, .L7F091114
/* 0C5C34 7F091104 24E7FFFD */   addiu $a3, $a3, -3
/* 0C5C38 7F091108 00075E00 */  sll   $t3, $a3, 0x18
/* 0C5C3C 7F09110C 10000002 */  b     .L7F091118
/* 0C5C40 7F091110 000B3E03 */   sra   $a3, $t3, 0x18
.L7F091114:
/* 0C5C44 7F091114 00003825 */  move  $a3, $zero
.L7F091118:
/* 0C5C48 7F091118 30AD0030 */  andi  $t5, $a1, 0x30
/* 0C5C4C 7F09111C 15A00085 */  bnez  $t5, .L7F091334
/* 0C5C50 7F091120 30AE2000 */   andi  $t6, $a1, 0x2000
/* 0C5C54 7F091124 11C00005 */  beqz  $t6, .L7F09113C
/* 0C5C58 7F091128 3C0F8003 */   lui   $t7, %hi(D_80037054) 
/* 0C5C5C 7F09112C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C5C60 7F091130 44812000 */  mtc1  $at, $f4
/* 0C5C64 7F091134 00000000 */  nop   
/* 0C5C68 7F091138 46040083 */  div.s $f2, $f0, $f4
.L7F09113C:
/* 0C5C6C 7F09113C 95EF7054 */  lhu   $t7, %lo(D_80037054)($t7)
/* 0C5C70 7F091140 44874000 */  mtc1  $a3, $f8
/* 0C5C74 7F091144 30AA0101 */  andi  $t2, $a1, 0x101
/* 0C5C78 7F091148 01E0C027 */  not   $t8, $t7
/* 0C5C7C 7F09114C 00B81024 */  and   $v0, $a1, $t8
/* 0C5C80 7F091150 30598000 */  andi  $t9, $v0, 0x8000
/* 0C5C84 7F091154 30484000 */  andi  $t0, $v0, 0x4000
/* 0C5C88 7F091158 13200005 */  beqz  $t9, .L7F091170
/* 0C5C8C 7F09115C 46804020 */   cvt.s.w $f0, $f8
/* 0C5C90 7F091160 3C018003 */  lui   $at, %hi(D_80037050)
/* 0C5C94 7F091164 C42C7050 */  lwc1  $f12, %lo(D_80037050)($at)
/* 0C5C98 7F091168 460C6300 */  add.s $f12, $f12, $f12
/* 0C5C9C 7F09116C E42C7050 */  swc1  $f12, %lo(D_80037050)($at)
.L7F091170:
/* 0C5CA0 7F091170 3C018003 */  lui   $at, %hi(D_80037050)
/* 0C5CA4 7F091174 11000006 */  beqz  $t0, .L7F091190
/* 0C5CA8 7F091178 C42C7050 */   lwc1  $f12, %lo(D_80037050)($at)
/* 0C5CAC 7F09117C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C5CB0 7F091180 44813000 */  mtc1  $at, $f6
/* 0C5CB4 7F091184 00000000 */  nop   
/* 0C5CB8 7F091188 46066302 */  mul.s $f12, $f12, $f6
/* 0C5CBC 7F09118C 00000000 */  nop   
.L7F091190:
/* 0C5CC0 7F091190 3C018003 */  lui   $at, %hi(D_80037040)
/* 0C5CC4 7F091194 C4307040 */  lwc1  $f16, %lo(D_80037040)($at)
/* 0C5CC8 7F091198 3C048003 */  lui   $a0, %hi(stanbondx)
/* 0C5CCC 7F09119C 24847014 */  addiu $a0, %lo(stanbondx) # addiu $a0, $a0, 0x7014
/* 0C5CD0 7F0911A0 46100102 */  mul.s $f4, $f0, $f16
/* 0C5CD4 7F0911A4 C48A0000 */  lwc1  $f10, ($a0)
/* 0C5CD8 7F0911A8 3C018003 */  lui   $at, %hi(D_8003703C)
/* 0C5CDC 7F0911AC 30A90202 */  andi  $t1, $a1, 0x202
/* 0C5CE0 7F0911B0 3C028003 */  lui   $v0, %hi(D_80037044)
/* 0C5CE4 7F0911B4 24427044 */  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
/* 0C5CE8 7F0911B8 30AD0400 */  andi  $t5, $a1, 0x400
/* 0C5CEC 7F0911BC 46022182 */  mul.s $f6, $f4, $f2
/* 0C5CF0 7F0911C0 30AE0008 */  andi  $t6, $a1, 8
/* 0C5CF4 7F0911C4 30AF0004 */  andi  $t7, $a1, 4
/* 0C5CF8 7F0911C8 460C3202 */  mul.s $f8, $f6, $f12
/* 0C5CFC 7F0911CC C4860008 */  lwc1  $f6, 8($a0)
/* 0C5D00 7F0911D0 46085100 */  add.s $f4, $f10, $f8
/* 0C5D04 7F0911D4 46000287 */  neg.s $f10, $f0
/* 0C5D08 7F0911D8 E4840000 */  swc1  $f4, ($a0)
/* 0C5D0C 7F0911DC C432703C */  lwc1  $f18, %lo(D_8003703C)($at)
/* 0C5D10 7F0911E0 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0C5D14 7F0911E4 46125202 */  mul.s $f8, $f10, $f18
/* 0C5D18 7F0911E8 00000000 */  nop   
/* 0C5D1C 7F0911EC 46024102 */  mul.s $f4, $f8, $f2
/* 0C5D20 7F0911F0 00000000 */  nop   
/* 0C5D24 7F0911F4 460C2282 */  mul.s $f10, $f4, $f12
/* 0C5D28 7F0911F8 460A3200 */  add.s $f8, $f6, $f10
/* 0C5D2C 7F0911FC 11200011 */  beqz  $t1, .L7F091244
/* 0C5D30 7F091200 E4880008 */   swc1  $f8, 8($a0)
/* 0C5D34 7F091204 44810000 */  mtc1  $at, $f0
/* 0C5D38 7F091208 C4840000 */  lwc1  $f4, ($a0)
/* 0C5D3C 7F09120C 46120182 */  mul.s $f6, $f0, $f18
/* 0C5D40 7F091210 00000000 */  nop   
/* 0C5D44 7F091214 46023282 */  mul.s $f10, $f6, $f2
/* 0C5D48 7F091218 00000000 */  nop   
/* 0C5D4C 7F09121C 460C5202 */  mul.s $f8, $f10, $f12
/* 0C5D50 7F091220 C48A0008 */  lwc1  $f10, 8($a0)
/* 0C5D54 7F091224 46082181 */  sub.s $f6, $f4, $f8
/* 0C5D58 7F091228 46100102 */  mul.s $f4, $f0, $f16
/* 0C5D5C 7F09122C E4860000 */  swc1  $f6, ($a0)
/* 0C5D60 7F091230 46022202 */  mul.s $f8, $f4, $f2
/* 0C5D64 7F091234 00000000 */  nop   
/* 0C5D68 7F091238 460C4182 */  mul.s $f6, $f8, $f12
/* 0C5D6C 7F09123C 46065101 */  sub.s $f4, $f10, $f6
/* 0C5D70 7F091240 E4840008 */  swc1  $f4, 8($a0)
.L7F091244:
/* 0C5D74 7F091244 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0C5D78 7F091248 44810000 */  mtc1  $at, $f0
/* 0C5D7C 7F09124C 51400010 */  beql  $t2, $zero, .L7F091290
/* 0C5D80 7F091250 83AB001B */   lb    $t3, 0x1b($sp)
/* 0C5D84 7F091254 46120282 */  mul.s $f10, $f0, $f18
/* 0C5D88 7F091258 C4880000 */  lwc1  $f8, ($a0)
/* 0C5D8C 7F09125C 46025182 */  mul.s $f6, $f10, $f2
/* 0C5D90 7F091260 00000000 */  nop   
/* 0C5D94 7F091264 460C3102 */  mul.s $f4, $f6, $f12
/* 0C5D98 7F091268 C4860008 */  lwc1  $f6, 8($a0)
/* 0C5D9C 7F09126C 46044280 */  add.s $f10, $f8, $f4
/* 0C5DA0 7F091270 46100202 */  mul.s $f8, $f0, $f16
/* 0C5DA4 7F091274 E48A0000 */  swc1  $f10, ($a0)
/* 0C5DA8 7F091278 46024102 */  mul.s $f4, $f8, $f2
/* 0C5DAC 7F09127C 00000000 */  nop   
/* 0C5DB0 7F091280 460C2282 */  mul.s $f10, $f4, $f12
/* 0C5DB4 7F091284 460A3200 */  add.s $f8, $f6, $f10
/* 0C5DB8 7F091288 E4880008 */  swc1  $f8, 8($a0)
/* 0C5DBC 7F09128C 83AB001B */  lb    $t3, 0x1b($sp)
.L7F091290:
/* 0C5DC0 7F091290 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 0C5DC4 7F091294 44814000 */  mtc1  $at, $f8
/* 0C5DC8 7F091298 448B2000 */  mtc1  $t3, $f4
/* 0C5DCC 7F09129C 3C038003 */  lui   $v1, %hi(D_80037038)
/* 0C5DD0 7F0912A0 24637038 */  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
/* 0C5DD4 7F0912A4 468021A0 */  cvt.s.w $f6, $f4
/* 0C5DD8 7F0912A8 30AC0800 */  andi  $t4, $a1, 0x800
/* 0C5DDC 7F0912AC 3C018003 */  lui   $at, %hi(D_80037050)
/* 0C5DE0 7F0912B0 46023282 */  mul.s $f10, $f6, $f2
/* 0C5DE4 7F0912B4 C4660000 */  lwc1  $f6, ($v1)
/* 0C5DE8 7F0912B8 46085102 */  mul.s $f4, $f10, $f8
/* 0C5DEC 7F0912BC 46043280 */  add.s $f10, $f6, $f4
/* 0C5DF0 7F0912C0 11800005 */  beqz  $t4, .L7F0912D8
/* 0C5DF4 7F0912C4 E46A0000 */   swc1  $f10, ($v1)
/* 0C5DF8 7F0912C8 46021180 */  add.s $f6, $f2, $f2
/* 0C5DFC 7F0912CC C4480000 */  lwc1  $f8, ($v0)
/* 0C5E00 7F0912D0 46064101 */  sub.s $f4, $f8, $f6
/* 0C5E04 7F0912D4 E4440000 */  swc1  $f4, ($v0)
.L7F0912D8:
/* 0C5E08 7F0912D8 3C028003 */  lui   $v0, %hi(D_80037044)
/* 0C5E0C 7F0912DC 11A00005 */  beqz  $t5, .L7F0912F4
/* 0C5E10 7F0912E0 24427044 */   addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
/* 0C5E14 7F0912E4 46021200 */  add.s $f8, $f2, $f2
/* 0C5E18 7F0912E8 C44A0000 */  lwc1  $f10, ($v0)
/* 0C5E1C 7F0912EC 46085180 */  add.s $f6, $f10, $f8
/* 0C5E20 7F0912F0 E4460000 */  swc1  $f6, ($v0)
.L7F0912F4:
/* 0C5E24 7F0912F4 11C00006 */  beqz  $t6, .L7F091310
/* 0C5E28 7F0912F8 00000000 */   nop   
/* 0C5E2C 7F0912FC 46020282 */  mul.s $f10, $f0, $f2
/* 0C5E30 7F091300 C4840004 */  lwc1  $f4, 4($a0)
/* 0C5E34 7F091304 460C5202 */  mul.s $f8, $f10, $f12
/* 0C5E38 7F091308 46082180 */  add.s $f6, $f4, $f8
/* 0C5E3C 7F09130C E4860004 */  swc1  $f6, 4($a0)
.L7F091310:
/* 0C5E40 7F091310 11E00008 */  beqz  $t7, .L7F091334
/* 0C5E44 7F091314 E42C7050 */   swc1  $f12, %lo(D_80037050)($at)
/* 0C5E48 7F091318 46020102 */  mul.s $f4, $f0, $f2
/* 0C5E4C 7F09131C C48A0004 */  lwc1  $f10, 4($a0)
/* 0C5E50 7F091320 3C018003 */  lui   $at, %hi(D_80037050)
/* 0C5E54 7F091324 460C2202 */  mul.s $f8, $f4, $f12
/* 0C5E58 7F091328 46085181 */  sub.s $f6, $f10, $f8
/* 0C5E5C 7F09132C E4860004 */  swc1  $f6, 4($a0)
/* 0C5E60 7F091330 E42C7050 */  swc1  $f12, %lo(D_80037050)($at)
.L7F091334:
/* 0C5E64 7F091334 3C038003 */  lui   $v1, %hi(D_80037038)
/* 0C5E68 7F091338 24637038 */  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
/* 0C5E6C 7F09133C 44806000 */  mtc1  $zero, $f12
/* 0C5E70 7F091340 C46E0000 */  lwc1  $f14, ($v1)
/* 0C5E74 7F091344 3C028003 */  lui   $v0, %hi(D_80037044)
/* 0C5E78 7F091348 24427044 */  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
/* 0C5E7C 7F09134C 460C703C */  c.lt.s $f14, $f12
/* 0C5E80 7F091350 3C0143B4 */  lui   $at, 0x43b4
/* 0C5E84 7F091354 4502000B */  bc1fl .L7F091384
/* 0C5E88 7F091358 3C0143B4 */   li    $at, 0x43B40000 # 360.000000
/* 0C5E8C 7F09135C 44811000 */  mtc1  $at, $f2
/* 0C5E90 7F091360 00000000 */  nop   
/* 0C5E94 7F091364 46027100 */  add.s $f4, $f14, $f2
.L7F091368:
/* 0C5E98 7F091368 E4640000 */  swc1  $f4, ($v1)
/* 0C5E9C 7F09136C C46E0000 */  lwc1  $f14, ($v1)
/* 0C5EA0 7F091370 460C703C */  c.lt.s $f14, $f12
/* 0C5EA4 7F091374 00000000 */  nop   
/* 0C5EA8 7F091378 4503FFFB */  bc1tl .L7F091368
/* 0C5EAC 7F09137C 46027100 */   add.s $f4, $f14, $f2
/* 0C5EB0 7F091380 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
.L7F091384:
/* 0C5EB4 7F091384 44811000 */  mtc1  $at, $f2
/* 0C5EB8 7F091388 3C018005 */  lui   $at, %hi(D_80055850)
/* 0C5EBC 7F09138C 460E103E */  c.le.s $f2, $f14
/* 0C5EC0 7F091390 00000000 */  nop   
/* 0C5EC4 7F091394 45020009 */  bc1fl .L7F0913BC
/* 0C5EC8 7F091398 C4400000 */   lwc1  $f0, ($v0)
/* 0C5ECC 7F09139C 46027281 */  sub.s $f10, $f14, $f2
.L7F0913A0:
/* 0C5ED0 7F0913A0 E46A0000 */  swc1  $f10, ($v1)
/* 0C5ED4 7F0913A4 C46E0000 */  lwc1  $f14, ($v1)
/* 0C5ED8 7F0913A8 460E103E */  c.le.s $f2, $f14
/* 0C5EDC 7F0913AC 00000000 */  nop   
/* 0C5EE0 7F0913B0 4503FFFB */  bc1tl .L7F0913A0
/* 0C5EE4 7F0913B4 46027281 */   sub.s $f10, $f14, $f2
/* 0C5EE8 7F0913B8 C4400000 */  lwc1  $f0, ($v0)
.L7F0913BC:
/* 0C5EEC 7F0913BC 460C003C */  c.lt.s $f0, $f12
/* 0C5EF0 7F0913C0 00000000 */  nop   
/* 0C5EF4 7F0913C4 45020009 */  bc1fl .L7F0913EC
/* 0C5EF8 7F0913C8 4600103E */   c.le.s $f2, $f0
/* 0C5EFC 7F0913CC 46020200 */  add.s $f8, $f0, $f2
.L7F0913D0:
/* 0C5F00 7F0913D0 E4480000 */  swc1  $f8, ($v0)
/* 0C5F04 7F0913D4 C4400000 */  lwc1  $f0, ($v0)
/* 0C5F08 7F0913D8 460C003C */  c.lt.s $f0, $f12
/* 0C5F0C 7F0913DC 00000000 */  nop   
/* 0C5F10 7F0913E0 4503FFFB */  bc1tl .L7F0913D0
/* 0C5F14 7F0913E4 46020200 */   add.s $f8, $f0, $f2
/* 0C5F18 7F0913E8 4600103E */  c.le.s $f2, $f0
.L7F0913EC:
/* 0C5F1C 7F0913EC 00000000 */  nop   
/* 0C5F20 7F0913F0 45000008 */  bc1f  .L7F091414
/* 0C5F24 7F0913F4 00000000 */   nop   
/* 0C5F28 7F0913F8 46020181 */  sub.s $f6, $f0, $f2
.L7F0913FC:
/* 0C5F2C 7F0913FC E4460000 */  swc1  $f6, ($v0)
/* 0C5F30 7F091400 C4400000 */  lwc1  $f0, ($v0)
/* 0C5F34 7F091404 4600103E */  c.le.s $f2, $f0
/* 0C5F38 7F091408 00000000 */  nop   
/* 0C5F3C 7F09140C 4503FFFB */  bc1tl .L7F0913FC
/* 0C5F40 7F091410 46020181 */   sub.s $f6, $f0, $f2
.L7F091414:
/* 0C5F44 7F091414 C4245850 */  lwc1  $f4, %lo(D_80055850)($at)
/* 0C5F48 7F091418 46047302 */  mul.s $f12, $f14, $f4
/* 0C5F4C 7F09141C 0FC15FA8 */  jal   cosf
/* 0C5F50 7F091420 00000000 */   nop   
/* 0C5F54 7F091424 3C018003 */  lui   $at, %hi(D_8003703C)
/* 0C5F58 7F091428 E420703C */  swc1  $f0, %lo(D_8003703C)($at)
/* 0C5F5C 7F09142C 3C038003 */  lui   $v1, %hi(D_80037038)
/* 0C5F60 7F091430 24637038 */  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
/* 0C5F64 7F091434 3C018005 */  lui   $at, %hi(D_80055854)
/* 0C5F68 7F091438 C4285854 */  lwc1  $f8, %lo(D_80055854)($at)
/* 0C5F6C 7F09143C C46A0000 */  lwc1  $f10, ($v1)
/* 0C5F70 7F091440 46085302 */  mul.s $f12, $f10, $f8
/* 0C5F74 7F091444 0FC15FAB */  jal   sinf
/* 0C5F78 7F091448 00000000 */   nop   
/* 0C5F7C 7F09144C 3C018003 */  lui   $at, %hi(D_80037040)
/* 0C5F80 7F091450 E4207040 */  swc1  $f0, %lo(D_80037040)($at)
/* 0C5F84 7F091454 3C028003 */  lui   $v0, %hi(D_80037044)
/* 0C5F88 7F091458 24427044 */  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
/* 0C5F8C 7F09145C 3C018005 */  lui   $at, %hi(D_80055858)
/* 0C5F90 7F091460 C4245858 */  lwc1  $f4, %lo(D_80055858)($at)
/* 0C5F94 7F091464 C4460000 */  lwc1  $f6, ($v0)
/* 0C5F98 7F091468 46043302 */  mul.s $f12, $f6, $f4
/* 0C5F9C 7F09146C 0FC15FA8 */  jal   cosf
/* 0C5FA0 7F091470 00000000 */   nop   
/* 0C5FA4 7F091474 3C018003 */  lui   $at, %hi(D_80037048)
/* 0C5FA8 7F091478 E4207048 */  swc1  $f0, %lo(D_80037048)($at)
/* 0C5FAC 7F09147C 3C028003 */  lui   $v0, %hi(D_80037044)
/* 0C5FB0 7F091480 24427044 */  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
/* 0C5FB4 7F091484 3C018005 */  lui   $at, %hi(D_8005585C)
/* 0C5FB8 7F091488 C428585C */  lwc1  $f8, %lo(D_8005585C)($at)
/* 0C5FBC 7F09148C C44A0000 */  lwc1  $f10, ($v0)
/* 0C5FC0 7F091490 46085302 */  mul.s $f12, $f10, $f8
/* 0C5FC4 7F091494 0FC15FAB */  jal   sinf
/* 0C5FC8 7F091498 00000000 */   nop   
/* 0C5FCC 7F09149C 3C048003 */  lui   $a0, %hi(D_8003704C)
/* 0C5FD0 7F0914A0 2484704C */  addiu $a0, %lo(D_8003704C) # addiu $a0, $a0, 0x704c
/* 0C5FD4 7F0914A4 E4800000 */  swc1  $f0, ($a0)
/* 0C5FD8 7F0914A8 C4820000 */  lwc1  $f2, ($a0)
/* 0C5FDC 7F0914AC 3C028003 */  lui   $v0, %hi(D_80037020)
/* 0C5FE0 7F0914B0 24427020 */  addiu $v0, %lo(D_80037020) # addiu $v0, $v0, 0x7020
/* 0C5FE4 7F0914B4 3C018003 */  lui   $at, %hi(D_80037048)
/* 0C5FE8 7F0914B8 E4420004 */  swc1  $f2, 4($v0)
/* 0C5FEC 7F0914BC C42E7048 */  lwc1  $f14, %lo(D_80037048)($at)
/* 0C5FF0 7F0914C0 3C018003 */  lui   $at, %hi(D_80037040)
/* 0C5FF4 7F0914C4 C4307040 */  lwc1  $f16, %lo(D_80037040)($at)
/* 0C5FF8 7F0914C8 3C018003 */  lui   $at, %hi(D_8003703C)
/* 0C5FFC 7F0914CC 46007107 */  neg.s $f4, $f14
/* 0C6000 7F0914D0 46107182 */  mul.s $f6, $f14, $f16
/* 0C6004 7F0914D4 46001207 */  neg.s $f8, $f2
/* 0C6008 7F0914D8 3C038003 */  lui   $v1, %hi(D_8003702C)
/* 0C600C 7F0914DC 2463702C */  addiu $v1, %lo(D_8003702C) # addiu $v1, $v1, 0x702c
/* 0C6010 7F0914E0 97B80022 */  lhu   $t8, 0x22($sp)
/* 0C6014 7F0914E4 E4460000 */  swc1  $f6, ($v0)
/* 0C6018 7F0914E8 C432703C */  lwc1  $f18, %lo(D_8003703C)($at)
/* 0C601C 7F0914EC 3C018003 */  lui   $at, %hi(D_80037054)
/* 0C6020 7F0914F0 E46E0004 */  swc1  $f14, 4($v1)
/* 0C6024 7F0914F4 46122282 */  mul.s $f10, $f4, $f18
/* 0C6028 7F0914F8 00000000 */  nop   
/* 0C602C 7F0914FC 46104182 */  mul.s $f6, $f8, $f16
/* 0C6030 7F091500 00000000 */  nop   
/* 0C6034 7F091504 46121102 */  mul.s $f4, $f2, $f18
/* 0C6038 7F091508 E44A0008 */  swc1  $f10, 8($v0)
/* 0C603C 7F09150C E4660000 */  swc1  $f6, ($v1)
/* 0C6040 7F091510 E4640008 */  swc1  $f4, 8($v1)
/* 0C6044 7F091514 A4387054 */  sh    $t8, %lo(D_80037054)($at)
/* 0C6048 7F091518 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0C604C 7F09151C 44816000 */  mtc1  $at, $f12
/* 0C6050 7F091520 0FC26C85 */  jal   set_cur_player_fovy
/* 0C6054 7F091524 00000000 */   nop   
/* 0C6058 7F091528 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80079E20)
/* 0C605C 7F09152C 24429E20 */  addiu $v0, %lo(dword_CODE_bss_80079E20) # addiu $v0, $v0, -0x61e0
/* 0C6060 7F091530 8C590000 */  lw    $t9, ($v0)
/* 0C6064 7F091534 24010001 */  li    $at, 1
/* 0C6068 7F091538 27230001 */  addiu $v1, $t9, 1
/* 0C606C 7F09153C 14610007 */  bne   $v1, $at, .L7F09155C
/* 0C6070 7F091540 AC430000 */   sw    $v1, ($v0)
/* 0C6074 7F091544 0FC173D7 */  jal   remove_item_in_hand
/* 0C6078 7F091548 00002025 */   move  $a0, $zero
/* 0C607C 7F09154C 0FC173D7 */  jal   remove_item_in_hand
/* 0C6080 7F091550 24040001 */   li    $a0, 1
/* 0C6084 7F091554 10000007 */  b     .L7F091574
/* 0C6088 7F091558 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F09155C:
/* 0C608C 7F09155C 24010004 */  li    $at, 4
/* 0C6090 7F091560 54610004 */  bnel  $v1, $at, .L7F091574
/* 0C6094 7F091564 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6098 7F091568 0FC1E73C */  jal   solo_char_load
/* 0C609C 7F09156C 00000000 */   nop   
/* 0C60A0 7F091570 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F091574:
/* 0C60A4 7F091574 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C60A8 7F091578 03E00008 */  jr    $ra
/* 0C60AC 7F09157C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091580(s32 arg0) {
    // Node 0
    sub_GAME_7F0876C4(&stanbondx, &D_80037020, &D_8003702C);
    return arg0;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091580
/* 0C60B0 7F091580 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C60B4 7F091584 AFA40018 */  sw    $a0, 0x18($sp)
/* 0C60B8 7F091588 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C60BC 7F09158C 3C048003 */  lui   $a0, %hi(stanbondx)
/* 0C60C0 7F091590 3C058003 */  lui   $a1, %hi(D_80037020)
/* 0C60C4 7F091594 3C068003 */  lui   $a2, %hi(D_8003702C)
/* 0C60C8 7F091598 24C6702C */  addiu $a2, %lo(D_8003702C) # addiu $a2, $a2, 0x702c
/* 0C60CC 7F09159C 24A57020 */  addiu $a1, %lo(D_80037020) # addiu $a1, $a1, 0x7020
/* 0C60D0 7F0915A0 0FC21DB1 */  jal   sub_GAME_7F0876C4
/* 0C60D4 7F0915A4 24847014 */   addiu $a0, %lo(stanbondx) # addiu $a0, $a0, 0x7014
/* 0C60D8 7F0915A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C60DC 7F0915AC 8FA20018 */  lw    $v0, 0x18($sp)
/* 0C60E0 7F0915B0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C60E4 7F0915B4 03E00008 */  jr    $ra
/* 0C60E8 7F0915B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F0915BC(f32 arg0) {
    f32 temp_f0;

    // Node 0
    temp_f0 = (D_80037058 / arg0);
    D_80037058 = arg0;
    stanbondx = (f32) (stanbondx * temp_f0);
    stanbondx.unk4 = (f32) (stanbondx.unk4 * temp_f0);
    stanbondx.unk8 = (f32) (stanbondx.unk8 * temp_f0);
    D_8003705C = (f32) (1.0f / arg0);
    return;
    // (possible return value: temp_f0)
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0915BC
/* 0C60EC 7F0915BC 3C028003 */  lui   $v0, %hi(D_80037058)
/* 0C60F0 7F0915C0 24427058 */  addiu $v0, %lo(D_80037058) # addiu $v0, $v0, 0x7058
/* 0C60F4 7F0915C4 C4440000 */  lwc1  $f4, ($v0)
/* 0C60F8 7F0915C8 3C038003 */  lui   $v1, %hi(stanbondx)
/* 0C60FC 7F0915CC 24637014 */  addiu $v1, %lo(stanbondx) # addiu $v1, $v1, 0x7014
/* 0C6100 7F0915D0 460C2003 */  div.s $f0, $f4, $f12
/* 0C6104 7F0915D4 C4660000 */  lwc1  $f6, ($v1)
/* 0C6108 7F0915D8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C610C 7F0915DC C46A0004 */  lwc1  $f10, 4($v1)
/* 0C6110 7F0915E0 C4720008 */  lwc1  $f18, 8($v1)
/* 0C6114 7F0915E4 E44C0000 */  swc1  $f12, ($v0)
/* 0C6118 7F0915E8 46003202 */  mul.s $f8, $f6, $f0
/* 0C611C 7F0915EC 44813000 */  mtc1  $at, $f6
/* 0C6120 7F0915F0 3C018003 */  lui   $at, %hi(D_8003705C)
/* 0C6124 7F0915F4 46005402 */  mul.s $f16, $f10, $f0
/* 0C6128 7F0915F8 00000000 */  nop   
/* 0C612C 7F0915FC 46009102 */  mul.s $f4, $f18, $f0
/* 0C6130 7F091600 E4680000 */  swc1  $f8, ($v1)
/* 0C6134 7F091604 E4700004 */  swc1  $f16, 4($v1)
/* 0C6138 7F091608 460C3203 */  div.s $f8, $f6, $f12
/* 0C613C 7F09160C E4640008 */  swc1  $f4, 8($v1)
/* 0C6140 7F091610 03E00008 */  jr    $ra
/* 0C6144 7F091614 E428705C */   swc1  $f8, %lo(D_8003705C)($at)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091618(void) {
    // Node 0
    get_BONDdata_position();
    cosf((D_80055860 - get_curplay_horizontal_rotation_in_degrees()));
    sinf(sp18);
    cosf(sp18);
    sinf(sp18);
    return;
    // (possible return value: sinf(sp18))
}

#else
GLOBAL_ASM(
.late_rodata
glabel D_80055860
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F091618
/* 0C6148 7F091618 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C614C 7F09161C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6150 7F091620 0FC227F5 */  jal   get_BONDdata_position
/* 0C6154 7F091624 00000000 */   nop   
/* 0C6158 7F091628 0FC227B9 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0C615C 7F09162C 00000000 */   nop   
/* 0C6160 7F091630 3C018005 */  lui   $at, %hi(D_80055860)
/* 0C6164 7F091634 C4245860 */  lwc1  $f4, %lo(D_80055860)($at)
/* 0C6168 7F091638 46002301 */  sub.s $f12, $f4, $f0
/* 0C616C 7F09163C 0FC15FA8 */  jal   cosf
/* 0C6170 7F091640 E7AC0018 */   swc1  $f12, 0x18($sp)
/* 0C6174 7F091644 0FC15FAB */  jal   sinf
/* 0C6178 7F091648 C7AC0018 */   lwc1  $f12, 0x18($sp)
/* 0C617C 7F09164C 0FC15FA8 */  jal   cosf
/* 0C6180 7F091650 C7AC0018 */   lwc1  $f12, 0x18($sp)
/* 0C6184 7F091654 0FC15FAB */  jal   sinf
/* 0C6188 7F091658 C7AC0018 */   lwc1  $f12, 0x18($sp)
/* 0C618C 7F09165C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C6190 7F091660 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C6194 7F091664 03E00008 */  jr    $ra
/* 0C6198 7F091668 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09166C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09166C
/* 0C619C 7F09166C 3C028003 */  lui   $v0, %hi(stanbondx)
/* 0C61A0 7F091670 3C038003 */  lui   $v1, %hi(D_80037060)
/* 0C61A4 7F091674 24637060 */  addiu $v1, %lo(D_80037060) # addiu $v1, $v1, 0x7060
/* 0C61A8 7F091678 24427014 */  addiu $v0, %lo(stanbondx) # addiu $v0, $v0, 0x7014
/* 0C61AC 7F09167C C4440000 */  lwc1  $f4, ($v0)
/* 0C61B0 7F091680 C4660000 */  lwc1  $f6, ($v1)
/* 0C61B4 7F091684 C4480004 */  lwc1  $f8, 4($v0)
/* 0C61B8 7F091688 C46A0004 */  lwc1  $f10, 4($v1)
/* 0C61BC 7F09168C 46062001 */  sub.s $f0, $f4, $f6
/* 0C61C0 7F091690 C4500008 */  lwc1  $f16, 8($v0)
/* 0C61C4 7F091694 C4720008 */  lwc1  $f18, 8($v1)
/* 0C61C8 7F091698 460A4081 */  sub.s $f2, $f8, $f10
/* 0C61CC 7F09169C 46000102 */  mul.s $f4, $f0, $f0
/* 0C61D0 7F0916A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C61D4 7F0916A4 46128381 */  sub.s $f14, $f16, $f18
/* 0C61D8 7F0916A8 46021182 */  mul.s $f6, $f2, $f2
/* 0C61DC 7F0916AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C61E0 7F0916B0 460E7282 */  mul.s $f10, $f14, $f14
/* 0C61E4 7F0916B4 46062200 */  add.s $f8, $f4, $f6
/* 0C61E8 7F0916B8 0C007DF8 */  jal   sqrtf
/* 0C61EC 7F0916BC 460A4300 */   add.s $f12, $f8, $f10
/* 0C61F0 7F0916C0 3C028003 */  lui   $v0, %hi(stanbondx)
/* 0C61F4 7F0916C4 24427014 */  addiu $v0, %lo(stanbondx) # addiu $v0, $v0, 0x7014
/* 0C61F8 7F0916C8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C61FC 7F0916CC 3C038003 */  lui   $v1, %hi(D_80037060)
/* 0C6200 7F0916D0 C4500000 */  lwc1  $f16, ($v0)
/* 0C6204 7F0916D4 C4520004 */  lwc1  $f18, 4($v0)
/* 0C6208 7F0916D8 C4440008 */  lwc1  $f4, 8($v0)
/* 0C620C 7F0916DC 24637060 */  addiu $v1, %lo(D_80037060) # addiu $v1, $v1, 0x7060
/* 0C6210 7F0916E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C6214 7F0916E4 E4700000 */  swc1  $f16, ($v1)
/* 0C6218 7F0916E8 E4720004 */  swc1  $f18, 4($v1)
/* 0C621C 7F0916EC 03E00008 */  jr    $ra
/* 0C6220 7F0916F0 E4640008 */   swc1  $f4, 8($v1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0916F4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0916F4
/* 0C6224 7F0916F4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C6228 7F0916F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C622C 7F0916FC 0FC227F5 */  jal   get_BONDdata_position
/* 0C6230 7F091700 00000000 */   nop   
/* 0C6234 7F091704 C4440000 */  lwc1  $f4, ($v0)
/* 0C6238 7F091708 3C038003 */  lui   $v1, %hi(stanbondx)
/* 0C623C 7F09170C 24637014 */  addiu $v1, %lo(stanbondx) # addiu $v1, $v1, 0x7014
/* 0C6240 7F091710 E4640000 */  swc1  $f4, ($v1)
/* 0C6244 7F091714 C4460004 */  lwc1  $f6, 4($v0)
/* 0C6248 7F091718 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C624C 7F09171C 3C018008 */  lui   $at, %hi(dword_CODE_bss_80079E20)
/* 0C6250 7F091720 E4660004 */  swc1  $f6, 4($v1)
/* 0C6254 7F091724 C4480008 */  lwc1  $f8, 8($v0)
/* 0C6258 7F091728 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C625C 7F09172C E4680008 */  swc1  $f8, 8($v1)
/* 0C6260 7F091730 03E00008 */  jr    $ra
/* 0C6264 7F091734 AC209E20 */   sw    $zero, %lo(dword_CODE_bss_80079E20)($at)
)
#endif



