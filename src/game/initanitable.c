#include "ultra64.h"


//bss
char dword_CODE_bss_80069170[0x2D0];
OSMesgQueue animMsgQ;
char dword_CODE_bss_80069458[0xC0];
OSMesg animMesg[8];
s32 *ptr_animation_table;


//data
void * D_80029D60[] = {NULL, &dword_CODE_bss_80069170, &dword_CODE_bss_80069170};

s32 animation_table_ptrs1[] = {
    0x1C, 0x144, 0x214, 0x318, 0x3C4, 0x610, 0x814, 0x990, 0xB84, 0xDB4,
    0x1028, 0x1334, 0x1578, 0x17B4, 0x186C, 0x1984, 0x1A6C, 0x1B54, 0x1C9C,
    0x1E40, 0x1F84, 0x2134, 0x282C, 0x299C, 0x2E64, 0x2F94, 0x30B8, 0x31DC,
    0x32C8, 0x33AC, 0x34D4, 0x35C8, 0x36D8, 0x384C, 0x39C0, 0x3AF0, 0x3C10,
    0x3D04, 0x3D9C, 0x3FA0, 0x4018, 0x4070, 0x40D4, 0x4144, 0x4298, 0x42C8,
    0x4384, 0x4504, 0x4574, 0x45CC, 1, 1, 0x47BC, 0x4A40, 0x4CE0, 0x4F14,
    0x51C4, 0x540C, 0x54A0, 0x5554, 0x5684, 0x5744, 0x5964, 0x5D10, 0x5EF0,
    0x60D4, 0x6254, 0x637C, 0x6484, 0x6554, 0x6644, 0x6738, 0x6808, 0x694C,
    0x6A18, 0x6C18, 0x6D50, 0x6F08, 0x700C, 0x71D0, 0x7304, 0x7430, 0x74A4,
    0x7514, 0x7588, 0x75EC, 0x7650, 0x76B8, 0x7714, 0x777C, 0x77D4, 1, 1,
    1, 1, 1, 1, 0x78C8, 0x7AA8, 0x7C4C, 0x7D04, 0x7DD8, 0x7F0C, 0x7FB4, 0x8080,
    0x8164, 0x8194, 0x8204, 0x8274, 0x82E0, 0x8340, 0x83A4, 0x8404, 0x845C,
    0x84C4, 0x8520, 0x8698, 0x8800, 0x8978, 0x8AAC, 0x8BF0, 0x8D28, 0x8E1C,
    0x8F2C, 0x9084, 0x9194, 0x92EC, 0x9444, 0x95FC, 0x97BC, 0x98C8, 0x9A2C,
    0x9B48, 0x9C4C, 0x9D5C, 0x9E44, 0x9F48, 0xA094, 0xA1B8, 0xA2F8, 0xA424,
    0xA538, 0xA650, 1, 1, 1, 1, 0xA6B0, 0xA704, 0xA8BC, 0xA94C, 0xA9DC, 0xACAC,
    0xB174, 0xB2AC, 0xB528, 0xB6B0, 0xB7C8, 0xB854, 0xB9A8, 0xBC40, 0xBF80,
    0xC224, 0xC410, 0xC544, 0xC838, 0xCB78, 0xCE6C, 0xD0A8, 1, 0xD348, 0xD54C,
    0xD5E4, 0xD668, 0xD6F8, 0xD728, 0xD89C, 0xDBE4, 0xDD20, 0xE05C, 0xE08C,
    0xE0BC, 0xE18C, 0 };

s32 animation_table_ptrs2[] = { 0xE470, 0xE5F4, 0xE7C0, 0 };


#ifdef NONMATCHING
void expand_ani_table_entries(void) {

}
#else
GLOBAL_ASM(
.text
glabel expand_ani_table_entries
/* 035530 7F000A00 8C830000 */  lw    $v1, ($a0)
/* 035534 7F000A04 3C068007 */  lui   $a2, %hi(ptr_animation_table)
/* 035538 7F000A08 00801025 */  move  $v0, $a0
/* 03553C 7F000A0C 10600017 */  beqz  $v1, .L7F000A6C
/* 035540 7F000A10 24C69538 */   addiu $a2, %lo(ptr_animation_table) # addiu $a2, $a2, -0x6ac8
/* 035544 7F000A14 8C830000 */  lw    $v1, ($a0)
/* 035548 7F000A18 24050001 */  li    $a1, 1
.L7F000A1C:
/* 03554C 7F000A1C 50A3000E */  beql  $a1, $v1, .L7F000A58
/* 035550 7F000A20 8C430004 */   lw    $v1, 4($v0)
/* 035554 7F000A24 8CCE0000 */  lw    $t6, ($a2)
/* 035558 7F000A28 006E7821 */  addu  $t7, $v1, $t6
/* 03555C 7F000A2C AC4F0000 */  sw    $t7, ($v0)
/* 035560 7F000A30 8CD90000 */  lw    $t9, ($a2)
/* 035564 7F000A34 8DF80008 */  lw    $t8, 8($t7)
/* 035568 7F000A38 03194021 */  addu  $t0, $t8, $t9
/* 03556C 7F000A3C ADE80008 */  sw    $t0, 8($t7)
/* 035570 7F000A40 8C430000 */  lw    $v1, ($v0)
/* 035574 7F000A44 8CCA0000 */  lw    $t2, ($a2)
/* 035578 7F000A48 8C690010 */  lw    $t1, 0x10($v1)
/* 03557C 7F000A4C 012A5821 */  addu  $t3, $t1, $t2
/* 035580 7F000A50 AC6B0010 */  sw    $t3, 0x10($v1)
/* 035584 7F000A54 8C430004 */  lw    $v1, 4($v0)
.L7F000A58:
/* 035588 7F000A58 24420004 */  addiu $v0, $v0, 4
/* 03558C 7F000A5C 1460FFEF */  bnez  $v1, .L7F000A1C
/* 035590 7F000A60 00000000 */   nop   
/* 035594 7F000A64 00801025 */  move  $v0, $a0
/* 035598 7F000A68 8C830000 */  lw    $v1, ($a0)
.L7F000A6C:
/* 03559C 7F000A6C 1060000D */  beqz  $v1, .L7F000AA4
/* 0355A0 7F000A70 24050001 */   li    $a1, 1
/* 0355A4 7F000A74 3C040012 */  lui   $a0, %hi(_animation_tableSegmentRomStart) # $a0, 0x12
/* 0355A8 7F000A78 24844AC0 */  addiu $a0, %lo(_animation_tableSegmentRomStart) # addiu $a0, $a0, 0x4ac0
/* 0355AC 7F000A7C 8C430000 */  lw    $v1, ($v0)
.L7F000A80:
/* 0355B0 7F000A80 50A30005 */  beql  $a1, $v1, .L7F000A98
/* 0355B4 7F000A84 8C430004 */   lw    $v1, 4($v0)
/* 0355B8 7F000A88 8C6C0000 */  lw    $t4, ($v1)
/* 0355BC 7F000A8C 01846821 */  addu  $t5, $t4, $a0
/* 0355C0 7F000A90 AC6D0000 */  sw    $t5, ($v1)
/* 0355C4 7F000A94 8C430004 */  lw    $v1, 4($v0)
.L7F000A98:
/* 0355C8 7F000A98 24420004 */  addiu $v0, $v0, 4
/* 0355CC 7F000A9C 1460FFF8 */  bnez  $v1, .L7F000A80
/* 0355D0 7F000AA0 00000000 */   nop   
.L7F000AA4:
/* 0355D4 7F000AA4 03E00008 */  jr    $ra
/* 0355D8 7F000AA8 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void alloc_load_expand_ani_table(void) {
    s32 temp_a2;
    ? temp_ret;

    // Node 0
    osCreateMesgQueue(&animMsgQ, &animMesg, 8);
    sub_GAME_7F0009E0(&D_80029D60, &animMsgQ, &dword_CODE_bss_80069458);
    temp_a2 = (&0x0000E7E0 - 0);
    temp_ret = mempAllocBytesInBank(temp_a2, 6, temp_a2);
    ptr_animation_table = temp_ret;
    romCopy(temp_ret, &_animation_dataSegmentRomStart, sp18);
    expand_ani_table_entries(&animation_table_ptrs1);
    expand_ani_table_entries(&animation_table_ptrs2);
}
#else
GLOBAL_ASM(
.text
glabel alloc_load_expand_ani_table
/* 0355DC 7F000AAC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0355E0 7F000AB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0355E4 7F000AB4 3C048007 */  lui   $a0, %hi(animMsgQ)
/* 0355E8 7F000AB8 3C058007 */  lui   $a1, %hi(animMesg)
/* 0355EC 7F000ABC 24A59518 */  addiu $a1, %lo(animMesg) # addiu $a1, $a1, -0x6ae8
/* 0355F0 7F000AC0 24849440 */  addiu $a0, %lo(animMsgQ) # addiu $a0, $a0, -0x6bc0
/* 0355F4 7F000AC4 0C0035B4 */  jal   osCreateMesgQueue
/* 0355F8 7F000AC8 24060008 */   li    $a2, 8
/* 0355FC 7F000ACC 3C048003 */  lui   $a0, %hi(D_80029D60)
/* 035600 7F000AD0 3C058007 */  lui   $a1, %hi(animMsgQ)
/* 035604 7F000AD4 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069458)
/* 035608 7F000AD8 24C69458 */  addiu $a2, %lo(dword_CODE_bss_80069458) # addiu $a2, $a2, -0x6ba8
/* 03560C 7F000ADC 24A59440 */  addiu $a1, %lo(animMsgQ) # addiu $a1, $a1, -0x6bc0
/* 035610 7F000AE0 0FC00278 */  jal   sub_GAME_7F0009E0
/* 035614 7F000AE4 24849D60 */   addiu $a0, %lo(D_80029D60) # addiu $a0, $a0, -0x62a0
/* 035618 7F000AE8 3C0E0001 */  lui   $t6, %hi(0x0000E7E0) # $t6, 1
/* 03561C 7F000AEC 3C0F0000 */  lui   $t7, 0
/* 035620 7F000AF0 25EF0000 */  addiu $t7, $t7, 0
/* 035624 7F000AF4 25CEE7E0 */  addiu $t6, %lo(0x0000E7E0) # addiu $t6, $t6, -0x1820
/* 035628 7F000AF8 01CF3023 */  subu  $a2, $t6, $t7
/* 03562C 7F000AFC 00C02025 */  move  $a0, $a2
/* 035630 7F000B00 AFA60018 */  sw    $a2, 0x18($sp)
/* 035634 7F000B04 0C0025C8 */  jal   mempAllocBytesInBank
/* 035638 7F000B08 24050006 */   li    $a1, 6
/* 03563C 7F000B0C 3C038007 */  lui   $v1, %hi(ptr_animation_table)
/* 035640 7F000B10 24639538 */  addiu $v1, %lo(ptr_animation_table) # addiu $v1, $v1, -0x6ac8
/* 035644 7F000B14 3C050029 */  lui   $a1, %hi(_animation_dataSegmentRomStart) # $a1, 0x29
/* 035648 7F000B18 AC620000 */  sw    $v0, ($v1)
/* 03564C 7F000B1C 8FA60018 */  lw    $a2, 0x18($sp)
/* 035650 7F000B20 24A5E980 */  addiu $a1, %lo(_animation_dataSegmentRomStart) # addiu $a1, $a1, -0x1680
/* 035654 7F000B24 0C001707 */  jal   romCopy
/* 035658 7F000B28 00402025 */   move  $a0, $v0
/* 03565C 7F000B2C 3C048003 */  lui   $a0, %hi(animation_table_ptrs1)
/* 035660 7F000B30 0FC00280 */  jal   expand_ani_table_entries
/* 035664 7F000B34 24849D6C */   addiu $a0, %lo(animation_table_ptrs1) # addiu $a0, $a0, -0x6294
/* 035668 7F000B38 3C048003 */  lui   $a0, %hi(animation_table_ptrs2)
/* 03566C 7F000B3C 0FC00280 */  jal   expand_ani_table_entries
/* 035670 7F000B40 2484A04C */   addiu $a0, %lo(animation_table_ptrs2) # addiu $a0, $a0, -0x5fb4
/* 035674 7F000B44 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035678 7F000B48 27BD0020 */  addiu $sp, $sp, 0x20
/* 03567C 7F000B4C 03E00008 */  jr    $ra
/* 035680 7F000B50 00000000 */   nop   
)
#endif

