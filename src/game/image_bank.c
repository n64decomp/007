#include "ultra64.h"
#include "ramrom.h"

// bss
//8008D0A0
s32 dword_CODE_bss_8008D0A0;
//8008D0A4
s32 dword_CODE_bss_8008D0A4;
//8008D0A8
s32 dword_CODE_bss_8008D0A8;
//8008D0AC
s32 dword_CODE_bss_8008D0AC;
//8008D0B0;
s32 globalbank_rdram_offset;
//8008D0B4;
s32 *ptr_explosionDL;
//8008D0B8;
s32 *image;
//8008D0BC
s32 dword_CODE_bss_8008D0BC;
//8008D0C0
s32 dword_CODE_bss_8008D0C0;
//8008D0C4
s32 dword_CODE_bss_8008D0C4;
//8008D0C8
s32 dword_CODE_bss_8008D0C8;
//8008D0CC
s32 dword_CODE_bss_8008D0CC;
//8008D0D0
s32 dword_CODE_bss_8008D0D0;
//8008D0D4
s32 dword_CODE_bss_8008D0D4;
//8008D0D8
s32 dword_CODE_bss_8008D0D8;
//8008D0DC
s32 dword_CODE_bss_8008D0DC;
//8008D0E0
s32 dword_CODE_bss_8008D0E0;
//8008D0E4
s32 dword_CODE_bss_8008D0E4;
//8008D0E8
s32 dword_CODE_bss_8008D0E8;
//8008D0EC
s32 dword_CODE_bss_8008D0EC;
//8008D0F0
s32 dword_CODE_bss_8008D0F0;
//8008D0F4
s32 dword_CODE_bss_8008D0F4;
//8008D0F8
s32 dword_CODE_bss_8008D0F8;
//8008D0FC
s32 dword_CODE_bss_8008D0FC;
//8008D100
s32 dword_CODE_bss_8008D100;
//8008D104
s32 dword_CODE_bss_8008D104;
//8008D108
s32 dword_CODE_bss_8008D108;
//8008D10C
s32 dword_CODE_bss_8008D10C;
//8008D110
s32 dword_CODE_bss_8008D110;
//8008D114;
s32 *imgcall;
//8008D118
s32 dword_CODE_bss_8008D118;
//8008D11C
s32 dword_CODE_bss_8008D11C;
//8008D120
s32 dword_CODE_bss_8008D120;
//8008D124
s32 dword_CODE_bss_8008D124;
//8008D128
s32 dword_CODE_bss_8008D128;
//8008D12C
s32 dword_CODE_bss_8008D12C;
//8008D130
s32 dword_CODE_bss_8008D130;
//8008D134
s32 dword_CODE_bss_8008D134;





void sub_GAME_7F0CBF10(s32 arg0) {
    dword_CODE_bss_8008D0A0 = arg0;
    dword_CODE_bss_8008D0A4 = 0;
    dword_CODE_bss_8008D0A8 = 0;
}





#ifdef NONMATCHING
s32 sub_GAME_7F0CBF2C(s32 arg0) {
    s32 temp_t1;
    s32 temp_t2;
    s32 phi_v1;
    s32 phi_v1_2;

    // Node 0
    phi_v1_2 = dword_CODE_bss_8008D0A8;
    if (dword_CODE_bss_8008D0A8 < arg0)
    {
        // Node 1
        phi_v1 = dword_CODE_bss_8008D0A8;
loop_2:
        // Node 2
        temp_t1 = (phi_v1 + 8);
        dword_CODE_bss_8008D0A4 = (u32) (*dword_CODE_bss_8008D0A0 | (dword_CODE_bss_8008D0A4 << 8));
        dword_CODE_bss_8008D0A0 = (void *) (dword_CODE_bss_8008D0A0 + 1);
        dword_CODE_bss_8008D0A8 = temp_t1;
        phi_v1 = temp_t1;
        phi_v1_2 = temp_t1;
        if (temp_t1 < arg0)
        {
            goto loop_2;
        }
    }
    // Node 3
    temp_t2 = (phi_v1_2 - arg0);
    dword_CODE_bss_8008D0A8 = temp_t2;
    return (((u32) dword_CODE_bss_8008D0A4 >> temp_t2) & ((1 << arg0) + -1));
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBF2C
/* 100A5C 7F0CBF2C 3C058009 */  lui   $a1, %hi(dword_CODE_bss_8008D0A8) # $a1, 0x8009
/* 100A60 7F0CBF30 24A5D0A8 */  addiu $a1, %lo(dword_CODE_bss_8008D0A8) # addiu $a1, $a1, -0x2f58
/* 100A64 7F0CBF34 8CA30000 */  lw    $v1, ($a1)
/* 100A68 7F0CBF38 3C078009 */  lui   $a3, %hi(dword_CODE_bss_8008D0A0) # $a3, 0x8009
/* 100A6C 7F0CBF3C 24E7D0A0 */  addiu $a3, %lo(dword_CODE_bss_8008D0A0) # addiu $a3, $a3, -0x2f60
/* 100A70 7F0CBF40 0064082A */  slt   $at, $v1, $a0
/* 100A74 7F0CBF44 1020000F */  beqz  $at, .L7F0CBF84
/* 100A78 7F0CBF48 3C068009 */   lui   $a2, %hi(dword_CODE_bss_8008D0A4) # $a2, 0x8009
/* 100A7C 7F0CBF4C 24C6D0A4 */  addiu $a2, %lo(dword_CODE_bss_8008D0A4) # addiu $a2, $a2, -0x2f5c
.L7F0CBF50:
/* 100A80 7F0CBF50 8CE20000 */  lw    $v0, ($a3)
/* 100A84 7F0CBF54 8CCF0000 */  lw    $t7, ($a2)
/* 100A88 7F0CBF58 24690008 */  addiu $t1, $v1, 8
/* 100A8C 7F0CBF5C 904E0000 */  lbu   $t6, ($v0)
/* 100A90 7F0CBF60 000FC200 */  sll   $t8, $t7, 8
/* 100A94 7F0CBF64 0124082A */  slt   $at, $t1, $a0
/* 100A98 7F0CBF68 24480001 */  addiu $t0, $v0, 1
/* 100A9C 7F0CBF6C 01D8C825 */  or    $t9, $t6, $t8
/* 100AA0 7F0CBF70 ACD90000 */  sw    $t9, ($a2)
/* 100AA4 7F0CBF74 ACE80000 */  sw    $t0, ($a3)
/* 100AA8 7F0CBF78 ACA90000 */  sw    $t1, ($a1)
/* 100AAC 7F0CBF7C 1420FFF4 */  bnez  $at, .L7F0CBF50
/* 100AB0 7F0CBF80 01201825 */   move  $v1, $t1
.L7F0CBF84:
/* 100AB4 7F0CBF84 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D0A4) # $a2, 0x8009
/* 100AB8 7F0CBF88 24C6D0A4 */  addiu $a2, %lo(dword_CODE_bss_8008D0A4) # addiu $a2, $a2, -0x2f5c
/* 100ABC 7F0CBF8C 8CCB0000 */  lw    $t3, ($a2)
/* 100AC0 7F0CBF90 240F0001 */  li    $t7, 1
/* 100AC4 7F0CBF94 00645023 */  subu  $t2, $v1, $a0
/* 100AC8 7F0CBF98 008F7004 */  sllv  $t6, $t7, $a0
/* 100ACC 7F0CBF9C 25D8FFFF */  addiu $t8, $t6, -1
/* 100AD0 7F0CBFA0 014B6806 */  srlv  $t5, $t3, $t2
/* 100AD4 7F0CBFA4 ACAA0000 */  sw    $t2, ($a1)
/* 100AD8 7F0CBFA8 03E00008 */  jr    $ra
/* 100ADC 7F0CBFAC 01B81024 */   and   $v0, $t5, $t8
)
#endif





#ifdef NONMATCHING
void load_prepare_global_image_bank(void) {
    s32 temp_s0;
    ? temp_ret;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 phi_s0;
    s32 phi_s0_2;

    // Node 0
    temp_s0 = (0x2001400 - 0x2000000);
    temp_ret = allocate_bytes_in_bank((temp_s0 + 0x1000), 4);
    ptr_explosionDL = temp_ret;
    temp_a0 = ((temp_ret + 0xfff) & -0x1000);
    ptr_explosionDL = temp_a0;
    romCopy(temp_a0, &_GlobalimagetableSegmentRomStart, temp_s0);
    temp_v0 = (ptr_explosionDL + 0xfe000000);
    globalbank_rdram_offset = temp_v0;
    image = (s32) (temp_v0 + 0x2000ac8);
    dword_CODE_bss_8008D0BC = (s32) (temp_v0 + 0x2000ad4);
    dword_CODE_bss_8008D0C0 = (s32) (temp_v0 + 0x2000bc4);
    dword_CODE_bss_8008D0C4 = (s32) (temp_v0 + 0x2000c0c);
    dword_CODE_bss_8008D0C8 = (s32) (temp_v0 + 0x2000c48);
    dword_CODE_bss_8008D0CC = (s32) (temp_v0 + 0x2000c54);
    dword_CODE_bss_8008D0D0 = (s32) (temp_v0 + 0x2000c60);
    dword_CODE_bss_8008D0D4 = (s32) (temp_v0 + 0x2000c6c);
    dword_CODE_bss_8008D0D8 = (s32) (temp_v0 + 0x2000c78);
    dword_CODE_bss_8008D0DC = (s32) (temp_v0 + 0x2000c84);
    dword_CODE_bss_8008D0E0 = (s32) (temp_v0 + 0x2000c90);
    dword_CODE_bss_8008D0E4 = (s32) (temp_v0 + 0x2000c9c);
    dword_CODE_bss_8008D0E8 = (s32) (temp_v0 + 0x2000ca8);
    dword_CODE_bss_8008D0EC = (s32) (temp_v0 + 0x2000cb4);
    dword_CODE_bss_8008D0F0 = (s32) (temp_v0 + 0x2000cc0);
    dword_CODE_bss_8008D0F4 = (s32) (temp_v0 + 0x2000ccc);
    dword_CODE_bss_8008D0F8 = (s32) (temp_v0 + 0x2000cd8);
    dword_CODE_bss_8008D0FC = (s32) (temp_v0 + 0x2000ce4);
    dword_CODE_bss_8008D100 = (s32) (temp_v0 + 0x2000cf0);
    dword_CODE_bss_8008D104 = (s32) (temp_v0 + 0x2000cfc);
    dword_CODE_bss_8008D108 = (s32) (temp_v0 + 0x2000d08);
    dword_CODE_bss_8008D10C = (s32) (temp_v0 + 0x2000d14);
    dword_CODE_bss_8008D110 = (s32) (temp_v0 + 0x2000d20);
    imgcall = (s32) (temp_v0 + 0x2000d2c);
    dword_CODE_bss_8008D118 = (s32) (temp_v0 + 0x2000d38);
    dword_CODE_bss_8008D11C = (s32) (temp_v0 + 0x2000d44);
    dword_CODE_bss_8008D120 = (s32) (temp_v0 + 0x2000d5c);
    dword_CODE_bss_8008D124 = (s32) (temp_v0 + 0x2000fb4);
    dword_CODE_bss_8008D128 = (s32) (temp_v0 + 0x2000fd8);
    dword_CODE_bss_8008D12C = (s32) (temp_v0 + 0x2001020);
    dword_CODE_bss_8008D130 = (s32) (temp_v0 + 0x200102c);
    dword_CODE_bss_8008D134 = (s32) (temp_v0 + 0x200132c);
    sub_GAME_7F0CBB74((temp_v0 + 0x2000000), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000078), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000120), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x20001c8), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000270), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000318), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x20003c0), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000468), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000510), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x20005b8), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000660), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000708), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x20007b0), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000858), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000900), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x20009a8), 0);
    sub_GAME_7F0CBB74((globalbank_rdram_offset + 0x2000a50), 0);
    load_image_to_buffer(image, 0);
    phi_s0 = 0;
loop_1:
    // Node 1
    load_image_to_buffer((phi_s0 + dword_CODE_bss_8008D0C0), 0);
    temp_s0_2 = (phi_s0 + 0xc);
    phi_s0 = temp_s0_2;
    if (temp_s0_2 < 0x48)
    {
        goto loop_1;
    }
    // Node 2
    phi_s0_2 = 0;
loop_3:
    // Node 3
    temp_s0_3 = (phi_s0_2 + 0xc);
    phi_s0_2 = temp_s0_3;
    if (temp_s0_3 != 0x3c)
    {
        goto loop_3;
    }
    // Node 4
    return load_image_to_buffer((phi_s0_2 + dword_CODE_bss_8008D0C4), 0);
}
#else
GLOBAL_ASM(
.text
glabel load_prepare_global_image_bank
/* 100AE0 7F0CBFB0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 100AE4 7F0CBFB4 3C0E0200 */  lui   $t6, %hi(0x02001400) # $t6, 0x200
/* 100AE8 7F0CBFB8 3C0F0200 */  lui   $t7, 0x200
/* 100AEC 7F0CBFBC AFB00014 */  sw    $s0, 0x14($sp)
/* 100AF0 7F0CBFC0 25EF0000 */  addiu $t7, $t7, 0
/* 100AF4 7F0CBFC4 25CE1400 */  addiu $t6, %lo(0x02001400) # addiu $t6, $t6, 0x1400
/* 100AF8 7F0CBFC8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 100AFC 7F0CBFCC 01CF8023 */  subu  $s0, $t6, $t7
/* 100B00 7F0CBFD0 AFB30020 */  sw    $s3, 0x20($sp)
/* 100B04 7F0CBFD4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 100B08 7F0CBFD8 AFB10018 */  sw    $s1, 0x18($sp)
/* 100B0C 7F0CBFDC 26041000 */  addiu $a0, $s0, 0x1000
/* 100B10 7F0CBFE0 0C0025C8 */  jal   allocate_bytes_in_bank
/* 100B14 7F0CBFE4 24050004 */   li    $a1, 4
/* 100B18 7F0CBFE8 3C118009 */  lui   $s1, %hi(ptr_explosionDL) # $s1, 0x8009
/* 100B1C 7F0CBFEC 2631D0B4 */  addiu $s1, %lo(ptr_explosionDL) # addiu $s1, $s1, -0x2f4c
/* 100B20 7F0CBFF0 24590FFF */  addiu $t9, $v0, 0xfff
/* 100B24 7F0CBFF4 2401F000 */  li    $at, -4096
/* 100B28 7F0CBFF8 AE220000 */  sw    $v0, ($s1)
/* 100B2C 7F0CBFFC 03212024 */  and   $a0, $t9, $at
/* 100B30 7F0CC000 3C05002A */  lui   $a1, %hi(_GlobalimagetableSegmentRomStart) # $a1, 0x2a
/* 100B34 7F0CC004 AE240000 */  sw    $a0, ($s1)
/* 100B38 7F0CC008 24A5D160 */  addiu $a1, %lo(_GlobalimagetableSegmentRomStart) # addiu $a1, $a1, -0x2ea0
/* 100B3C 7F0CC00C 0C001707 */  jal   romCopy
/* 100B40 7F0CC010 02003025 */   move  $a2, $s0
/* 100B44 7F0CC014 8E290000 */  lw    $t1, ($s1)
/* 100B48 7F0CC018 3C01FE00 */  lui   $at, 0xfe00
/* 100B4C 7F0CC01C 3C108009 */  lui   $s0, %hi(globalbank_rdram_offset) # $s0, 0x8009
/* 100B50 7F0CC020 01211021 */  addu  $v0, $t1, $at
/* 100B54 7F0CC024 3C0B0200 */  lui   $t3, %hi(0x02000AC8) # $t3, 0x200
/* 100B58 7F0CC028 2610D0B0 */  addiu $s0, %lo(globalbank_rdram_offset) # addiu $s0, $s0, -0x2f50
/* 100B5C 7F0CC02C 256B0AC8 */  addiu $t3, %lo(0x02000AC8) # addiu $t3, $t3, 0xac8
/* 100B60 7F0CC030 AE020000 */  sw    $v0, ($s0)
/* 100B64 7F0CC034 004B6021 */  addu  $t4, $v0, $t3
/* 100B68 7F0CC038 3C018009 */  lui   $at, %hi(image) # $at, 0x8009
/* 100B6C 7F0CC03C 3C0D0200 */  lui   $t5, %hi(0x02000AD4) # $t5, 0x200
/* 100B70 7F0CC040 AC2CD0B8 */  sw    $t4, %lo(image)($at)
/* 100B74 7F0CC044 25AD0AD4 */  addiu $t5, %lo(0x02000AD4) # addiu $t5, $t5, 0xad4
/* 100B78 7F0CC048 004D7021 */  addu  $t6, $v0, $t5
/* 100B7C 7F0CC04C 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0BC) # $at, 0x8009
/* 100B80 7F0CC050 AC2ED0BC */  sw    $t6, %lo(dword_CODE_bss_8008D0BC)($at)
/* 100B84 7F0CC054 3C0F0200 */  lui   $t7, %hi(0x02000BC4) # $t7, 0x200
/* 100B88 7F0CC058 3C190200 */  lui   $t9, %hi(0x02000C0C) # $t9, 0x200
/* 100B8C 7F0CC05C 3C128009 */  lui   $s2, %hi(dword_CODE_bss_8008D0C0) # $s2, 0x8009
/* 100B90 7F0CC060 3C138009 */  lui   $s3, %hi(dword_CODE_bss_8008D0C4) # $s3, 0x8009
/* 100B94 7F0CC064 25EF0BC4 */  addiu $t7, %lo(0x02000BC4) # addiu $t7, $t7, 0xbc4
/* 100B98 7F0CC068 27390C0C */  addiu $t9, %lo(0x02000C0C) # addiu $t9, $t9, 0xc0c
/* 100B9C 7F0CC06C 3C090200 */  lui   $t1, %hi(0x02000C48) # $t1, 0x200
/* 100BA0 7F0CC070 2673D0C4 */  addiu $s3, %lo(dword_CODE_bss_8008D0C4) # addiu $s3, $s3, -0x2f3c
/* 100BA4 7F0CC074 2652D0C0 */  addiu $s2, %lo(dword_CODE_bss_8008D0C0) # addiu $s2, $s2, -0x2f40
/* 100BA8 7F0CC078 004FC021 */  addu  $t8, $v0, $t7
/* 100BAC 7F0CC07C 00594021 */  addu  $t0, $v0, $t9
/* 100BB0 7F0CC080 25290C48 */  addiu $t1, %lo(0x02000C48) # addiu $t1, $t1, 0xc48
/* 100BB4 7F0CC084 AE580000 */  sw    $t8, ($s2)
/* 100BB8 7F0CC088 AE680000 */  sw    $t0, ($s3)
/* 100BBC 7F0CC08C 00495021 */  addu  $t2, $v0, $t1
/* 100BC0 7F0CC090 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0C8) # $at, 0x8009
/* 100BC4 7F0CC094 3C0B0200 */  lui   $t3, %hi(0x02000C54) # $t3, 0x200
/* 100BC8 7F0CC098 AC2AD0C8 */  sw    $t2, %lo(dword_CODE_bss_8008D0C8)($at)
/* 100BCC 7F0CC09C 256B0C54 */  addiu $t3, %lo(0x02000C54) # addiu $t3, $t3, 0xc54
/* 100BD0 7F0CC0A0 004B6021 */  addu  $t4, $v0, $t3
/* 100BD4 7F0CC0A4 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0CC) # $at, 0x8009
/* 100BD8 7F0CC0A8 3C0D0200 */  lui   $t5, %hi(0x02000C60) # $t5, 0x200
/* 100BDC 7F0CC0AC AC2CD0CC */  sw    $t4, %lo(dword_CODE_bss_8008D0CC)($at)
/* 100BE0 7F0CC0B0 25AD0C60 */  addiu $t5, %lo(0x02000C60) # addiu $t5, $t5, 0xc60
/* 100BE4 7F0CC0B4 004D7021 */  addu  $t6, $v0, $t5
/* 100BE8 7F0CC0B8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0D0) # $at, 0x8009
/* 100BEC 7F0CC0BC 3C0F0200 */  lui   $t7, %hi(0x02000C6C) # $t7, 0x200
/* 100BF0 7F0CC0C0 AC2ED0D0 */  sw    $t6, %lo(dword_CODE_bss_8008D0D0)($at)
/* 100BF4 7F0CC0C4 25EF0C6C */  addiu $t7, %lo(0x02000C6C) # addiu $t7, $t7, 0xc6c
/* 100BF8 7F0CC0C8 004FC021 */  addu  $t8, $v0, $t7
/* 100BFC 7F0CC0CC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0D4) # $at, 0x8009
/* 100C00 7F0CC0D0 3C190200 */  lui   $t9, %hi(0x02000C78) # $t9, 0x200
/* 100C04 7F0CC0D4 AC38D0D4 */  sw    $t8, %lo(dword_CODE_bss_8008D0D4)($at)
/* 100C08 7F0CC0D8 27390C78 */  addiu $t9, %lo(0x02000C78) # addiu $t9, $t9, 0xc78
/* 100C0C 7F0CC0DC 00594021 */  addu  $t0, $v0, $t9
/* 100C10 7F0CC0E0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0D8) # $at, 0x8009
/* 100C14 7F0CC0E4 3C090200 */  lui   $t1, %hi(0x02000C84) # $t1, 0x200
/* 100C18 7F0CC0E8 AC28D0D8 */  sw    $t0, %lo(dword_CODE_bss_8008D0D8)($at)
/* 100C1C 7F0CC0EC 25290C84 */  addiu $t1, %lo(0x02000C84) # addiu $t1, $t1, 0xc84
/* 100C20 7F0CC0F0 00495021 */  addu  $t2, $v0, $t1
/* 100C24 7F0CC0F4 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0DC) # $at, 0x8009
/* 100C28 7F0CC0F8 3C0B0200 */  lui   $t3, %hi(0x02000C90) # $t3, 0x200
/* 100C2C 7F0CC0FC AC2AD0DC */  sw    $t2, %lo(dword_CODE_bss_8008D0DC)($at)
/* 100C30 7F0CC100 256B0C90 */  addiu $t3, %lo(0x02000C90) # addiu $t3, $t3, 0xc90
/* 100C34 7F0CC104 004B6021 */  addu  $t4, $v0, $t3
/* 100C38 7F0CC108 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0E0) # $at, 0x8009
/* 100C3C 7F0CC10C 3C0D0200 */  lui   $t5, %hi(0x02000C9C) # $t5, 0x200
/* 100C40 7F0CC110 AC2CD0E0 */  sw    $t4, %lo(dword_CODE_bss_8008D0E0)($at)
/* 100C44 7F0CC114 25AD0C9C */  addiu $t5, %lo(0x02000C9C) # addiu $t5, $t5, 0xc9c
/* 100C48 7F0CC118 004D7021 */  addu  $t6, $v0, $t5
/* 100C4C 7F0CC11C 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0E4) # $at, 0x8009
/* 100C50 7F0CC120 3C0F0200 */  lui   $t7, %hi(0x02000CA8) # $t7, 0x200
/* 100C54 7F0CC124 AC2ED0E4 */  sw    $t6, %lo(dword_CODE_bss_8008D0E4)($at)
/* 100C58 7F0CC128 25EF0CA8 */  addiu $t7, %lo(0x02000CA8) # addiu $t7, $t7, 0xca8
/* 100C5C 7F0CC12C 004FC021 */  addu  $t8, $v0, $t7
/* 100C60 7F0CC130 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0E8) # $at, 0x8009
/* 100C64 7F0CC134 3C190200 */  lui   $t9, %hi(0x02000CB4) # $t9, 0x200
/* 100C68 7F0CC138 AC38D0E8 */  sw    $t8, %lo(dword_CODE_bss_8008D0E8)($at)
/* 100C6C 7F0CC13C 27390CB4 */  addiu $t9, %lo(0x02000CB4) # addiu $t9, $t9, 0xcb4
/* 100C70 7F0CC140 00594021 */  addu  $t0, $v0, $t9
/* 100C74 7F0CC144 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0EC) # $at, 0x8009
/* 100C78 7F0CC148 3C090200 */  lui   $t1, %hi(0x02000CC0) # $t1, 0x200
/* 100C7C 7F0CC14C AC28D0EC */  sw    $t0, %lo(dword_CODE_bss_8008D0EC)($at)
/* 100C80 7F0CC150 25290CC0 */  addiu $t1, %lo(0x02000CC0) # addiu $t1, $t1, 0xcc0
/* 100C84 7F0CC154 00495021 */  addu  $t2, $v0, $t1
/* 100C88 7F0CC158 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0F0) # $at, 0x8009
/* 100C8C 7F0CC15C 3C0B0200 */  lui   $t3, %hi(0x02000CCC) # $t3, 0x200
/* 100C90 7F0CC160 AC2AD0F0 */  sw    $t2, %lo(dword_CODE_bss_8008D0F0)($at)
/* 100C94 7F0CC164 256B0CCC */  addiu $t3, %lo(0x02000CCC) # addiu $t3, $t3, 0xccc
/* 100C98 7F0CC168 004B6021 */  addu  $t4, $v0, $t3
/* 100C9C 7F0CC16C 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0F4) # $at, 0x8009
/* 100CA0 7F0CC170 3C0D0200 */  lui   $t5, %hi(0x02000CD8) # $t5, 0x200
/* 100CA4 7F0CC174 AC2CD0F4 */  sw    $t4, %lo(dword_CODE_bss_8008D0F4)($at)
/* 100CA8 7F0CC178 25AD0CD8 */  addiu $t5, %lo(0x02000CD8) # addiu $t5, $t5, 0xcd8
/* 100CAC 7F0CC17C 004D7021 */  addu  $t6, $v0, $t5
/* 100CB0 7F0CC180 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0F8) # $at, 0x8009
/* 100CB4 7F0CC184 3C0F0200 */  lui   $t7, %hi(0x02000CE4) # $t7, 0x200
/* 100CB8 7F0CC188 AC2ED0F8 */  sw    $t6, %lo(dword_CODE_bss_8008D0F8)($at)
/* 100CBC 7F0CC18C 25EF0CE4 */  addiu $t7, %lo(0x02000CE4) # addiu $t7, $t7, 0xce4
/* 100CC0 7F0CC190 004FC021 */  addu  $t8, $v0, $t7
/* 100CC4 7F0CC194 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D0FC) # $at, 0x8009
/* 100CC8 7F0CC198 3C190200 */  lui   $t9, %hi(0x02000CF0) # $t9, 0x200
/* 100CCC 7F0CC19C AC38D0FC */  sw    $t8, %lo(dword_CODE_bss_8008D0FC)($at)
/* 100CD0 7F0CC1A0 27390CF0 */  addiu $t9, %lo(0x02000CF0) # addiu $t9, $t9, 0xcf0
/* 100CD4 7F0CC1A4 00594021 */  addu  $t0, $v0, $t9
/* 100CD8 7F0CC1A8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D100) # $at, 0x8009
/* 100CDC 7F0CC1AC 3C090200 */  lui   $t1, %hi(0x02000CFC) # $t1, 0x200
/* 100CE0 7F0CC1B0 AC28D100 */  sw    $t0, %lo(dword_CODE_bss_8008D100)($at)
/* 100CE4 7F0CC1B4 25290CFC */  addiu $t1, %lo(0x02000CFC) # addiu $t1, $t1, 0xcfc
/* 100CE8 7F0CC1B8 00495021 */  addu  $t2, $v0, $t1
/* 100CEC 7F0CC1BC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D104) # $at, 0x8009
/* 100CF0 7F0CC1C0 3C0B0200 */  lui   $t3, %hi(0x02000D08) # $t3, 0x200
/* 100CF4 7F0CC1C4 AC2AD104 */  sw    $t2, %lo(dword_CODE_bss_8008D104)($at)
/* 100CF8 7F0CC1C8 256B0D08 */  addiu $t3, %lo(0x02000D08) # addiu $t3, $t3, 0xd08
/* 100CFC 7F0CC1CC 004B6021 */  addu  $t4, $v0, $t3
/* 100D00 7F0CC1D0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D108) # $at, 0x8009
/* 100D04 7F0CC1D4 3C0D0200 */  lui   $t5, %hi(0x02000D14) # $t5, 0x200
/* 100D08 7F0CC1D8 AC2CD108 */  sw    $t4, %lo(dword_CODE_bss_8008D108)($at)
/* 100D0C 7F0CC1DC 25AD0D14 */  addiu $t5, %lo(0x02000D14) # addiu $t5, $t5, 0xd14
/* 100D10 7F0CC1E0 004D7021 */  addu  $t6, $v0, $t5
/* 100D14 7F0CC1E4 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D10C) # $at, 0x8009
/* 100D18 7F0CC1E8 3C0F0200 */  lui   $t7, %hi(0x02000D20) # $t7, 0x200
/* 100D1C 7F0CC1EC AC2ED10C */  sw    $t6, %lo(dword_CODE_bss_8008D10C)($at)
/* 100D20 7F0CC1F0 25EF0D20 */  addiu $t7, %lo(0x02000D20) # addiu $t7, $t7, 0xd20
/* 100D24 7F0CC1F4 004FC021 */  addu  $t8, $v0, $t7
/* 100D28 7F0CC1F8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D110) # $at, 0x8009
/* 100D2C 7F0CC1FC 3C190200 */  lui   $t9, %hi(0x02000D2C) # $t9, 0x200
/* 100D30 7F0CC200 AC38D110 */  sw    $t8, %lo(dword_CODE_bss_8008D110)($at)
/* 100D34 7F0CC204 27390D2C */  addiu $t9, %lo(0x02000D2C) # addiu $t9, $t9, 0xd2c
/* 100D38 7F0CC208 00594021 */  addu  $t0, $v0, $t9
/* 100D3C 7F0CC20C 3C018009 */  lui   $at, %hi(imgcall) # $at, 0x8009
/* 100D40 7F0CC210 3C090200 */  lui   $t1, %hi(0x02000D38) # $t1, 0x200
/* 100D44 7F0CC214 AC28D114 */  sw    $t0, %lo(imgcall)($at)
/* 100D48 7F0CC218 25290D38 */  addiu $t1, %lo(0x02000D38) # addiu $t1, $t1, 0xd38
/* 100D4C 7F0CC21C 00495021 */  addu  $t2, $v0, $t1
/* 100D50 7F0CC220 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D118) # $at, 0x8009
/* 100D54 7F0CC224 3C0B0200 */  lui   $t3, %hi(0x02000D44) # $t3, 0x200
/* 100D58 7F0CC228 AC2AD118 */  sw    $t2, %lo(dword_CODE_bss_8008D118)($at)
/* 100D5C 7F0CC22C 256B0D44 */  addiu $t3, %lo(0x02000D44) # addiu $t3, $t3, 0xd44
/* 100D60 7F0CC230 004B6021 */  addu  $t4, $v0, $t3
/* 100D64 7F0CC234 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D11C) # $at, 0x8009
/* 100D68 7F0CC238 3C0D0200 */  lui   $t5, %hi(0x02000D5C) # $t5, 0x200
/* 100D6C 7F0CC23C AC2CD11C */  sw    $t4, %lo(dword_CODE_bss_8008D11C)($at)
/* 100D70 7F0CC240 25AD0D5C */  addiu $t5, %lo(0x02000D5C) # addiu $t5, $t5, 0xd5c
/* 100D74 7F0CC244 004D7021 */  addu  $t6, $v0, $t5
/* 100D78 7F0CC248 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D120) # $at, 0x8009
/* 100D7C 7F0CC24C 3C0F0200 */  lui   $t7, %hi(0x02000FB4) # $t7, 0x200
/* 100D80 7F0CC250 AC2ED120 */  sw    $t6, %lo(dword_CODE_bss_8008D120)($at)
/* 100D84 7F0CC254 25EF0FB4 */  addiu $t7, %lo(0x02000FB4) # addiu $t7, $t7, 0xfb4
/* 100D88 7F0CC258 004FC021 */  addu  $t8, $v0, $t7
/* 100D8C 7F0CC25C 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D124) # $at, 0x8009
/* 100D90 7F0CC260 3C190200 */  lui   $t9, %hi(0x02000FD8) # $t9, 0x200
/* 100D94 7F0CC264 AC38D124 */  sw    $t8, %lo(dword_CODE_bss_8008D124)($at)
/* 100D98 7F0CC268 27390FD8 */  addiu $t9, %lo(0x02000FD8) # addiu $t9, $t9, 0xfd8
/* 100D9C 7F0CC26C 00594021 */  addu  $t0, $v0, $t9
/* 100DA0 7F0CC270 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D128) # $at, 0x8009
/* 100DA4 7F0CC274 3C090200 */  lui   $t1, %hi(0x02001020) # $t1, 0x200
/* 100DA8 7F0CC278 AC28D128 */  sw    $t0, %lo(dword_CODE_bss_8008D128)($at)
/* 100DAC 7F0CC27C 25291020 */  addiu $t1, %lo(0x02001020) # addiu $t1, $t1, 0x1020
/* 100DB0 7F0CC280 00495021 */  addu  $t2, $v0, $t1
/* 100DB4 7F0CC284 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D12C) # $at, 0x8009
/* 100DB8 7F0CC288 3C0B0200 */  lui   $t3, %hi(0x0200102C) # $t3, 0x200
/* 100DBC 7F0CC28C AC2AD12C */  sw    $t2, %lo(dword_CODE_bss_8008D12C)($at)
/* 100DC0 7F0CC290 256B102C */  addiu $t3, %lo(0x0200102C) # addiu $t3, $t3, 0x102c
/* 100DC4 7F0CC294 004B6021 */  addu  $t4, $v0, $t3
/* 100DC8 7F0CC298 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D130) # $at, 0x8009
/* 100DCC 7F0CC29C 3C0D0200 */  lui   $t5, %hi(0x0200132C) # $t5, 0x200
/* 100DD0 7F0CC2A0 AC2CD130 */  sw    $t4, %lo(dword_CODE_bss_8008D130)($at)
/* 100DD4 7F0CC2A4 25AD132C */  addiu $t5, %lo(0x0200132C) # addiu $t5, $t5, 0x132c
/* 100DD8 7F0CC2A8 3C0F0200 */  lui   $t7, 0x200
/* 100DDC 7F0CC2AC 004D7021 */  addu  $t6, $v0, $t5
/* 100DE0 7F0CC2B0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D134) # $at, 0x8009
/* 100DE4 7F0CC2B4 25EF0000 */  addiu $t7, $t7, 0
/* 100DE8 7F0CC2B8 AC2ED134 */  sw    $t6, %lo(dword_CODE_bss_8008D134)($at)
/* 100DEC 7F0CC2BC 004F2021 */  addu  $a0, $v0, $t7
/* 100DF0 7F0CC2C0 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100DF4 7F0CC2C4 00002825 */   move  $a1, $zero
/* 100DF8 7F0CC2C8 8E180000 */  lw    $t8, ($s0)
/* 100DFC 7F0CC2CC 3C190200 */  lui   $t9, %hi(0x02000078) # $t9, 0x200
/* 100E00 7F0CC2D0 27390078 */  addiu $t9, %lo(0x02000078) # addiu $t9, $t9, 0x78
/* 100E04 7F0CC2D4 00002825 */  move  $a1, $zero
/* 100E08 7F0CC2D8 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E0C 7F0CC2DC 03192021 */   addu  $a0, $t8, $t9
/* 100E10 7F0CC2E0 8E080000 */  lw    $t0, ($s0)
/* 100E14 7F0CC2E4 3C090200 */  lui   $t1, %hi(0x02000120) # $t1, 0x200
/* 100E18 7F0CC2E8 25290120 */  addiu $t1, %lo(0x02000120) # addiu $t1, $t1, 0x120
/* 100E1C 7F0CC2EC 00002825 */  move  $a1, $zero
/* 100E20 7F0CC2F0 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E24 7F0CC2F4 01092021 */   addu  $a0, $t0, $t1
/* 100E28 7F0CC2F8 8E0A0000 */  lw    $t2, ($s0)
/* 100E2C 7F0CC2FC 3C0B0200 */  lui   $t3, %hi(0x020001C8) # $t3, 0x200
/* 100E30 7F0CC300 256B01C8 */  addiu $t3, %lo(0x020001C8) # addiu $t3, $t3, 0x1c8
/* 100E34 7F0CC304 00002825 */  move  $a1, $zero
/* 100E38 7F0CC308 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E3C 7F0CC30C 014B2021 */   addu  $a0, $t2, $t3
/* 100E40 7F0CC310 8E0C0000 */  lw    $t4, ($s0)
/* 100E44 7F0CC314 3C0D0200 */  lui   $t5, %hi(0x02000270) # $t5, 0x200
/* 100E48 7F0CC318 25AD0270 */  addiu $t5, %lo(0x02000270) # addiu $t5, $t5, 0x270
/* 100E4C 7F0CC31C 00002825 */  move  $a1, $zero
/* 100E50 7F0CC320 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E54 7F0CC324 018D2021 */   addu  $a0, $t4, $t5
/* 100E58 7F0CC328 8E0E0000 */  lw    $t6, ($s0)
/* 100E5C 7F0CC32C 3C0F0200 */  lui   $t7, %hi(0x02000318) # $t7, 0x200
/* 100E60 7F0CC330 25EF0318 */  addiu $t7, %lo(0x02000318) # addiu $t7, $t7, 0x318
/* 100E64 7F0CC334 00002825 */  move  $a1, $zero
/* 100E68 7F0CC338 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E6C 7F0CC33C 01CF2021 */   addu  $a0, $t6, $t7
/* 100E70 7F0CC340 8E180000 */  lw    $t8, ($s0)
/* 100E74 7F0CC344 3C190200 */  lui   $t9, %hi(0x020003C0) # $t9, 0x200
/* 100E78 7F0CC348 273903C0 */  addiu $t9, %lo(0x020003C0) # addiu $t9, $t9, 0x3c0
/* 100E7C 7F0CC34C 00002825 */  move  $a1, $zero
/* 100E80 7F0CC350 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E84 7F0CC354 03192021 */   addu  $a0, $t8, $t9
/* 100E88 7F0CC358 8E080000 */  lw    $t0, ($s0)
/* 100E8C 7F0CC35C 3C090200 */  lui   $t1, %hi(0x02000468) # $t1, 0x200
/* 100E90 7F0CC360 25290468 */  addiu $t1, %lo(0x02000468) # addiu $t1, $t1, 0x468
/* 100E94 7F0CC364 00002825 */  move  $a1, $zero
/* 100E98 7F0CC368 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100E9C 7F0CC36C 01092021 */   addu  $a0, $t0, $t1
/* 100EA0 7F0CC370 8E0A0000 */  lw    $t2, ($s0)
/* 100EA4 7F0CC374 3C0B0200 */  lui   $t3, %hi(0x02000510) # $t3, 0x200
/* 100EA8 7F0CC378 256B0510 */  addiu $t3, %lo(0x02000510) # addiu $t3, $t3, 0x510
/* 100EAC 7F0CC37C 00002825 */  move  $a1, $zero
/* 100EB0 7F0CC380 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100EB4 7F0CC384 014B2021 */   addu  $a0, $t2, $t3
/* 100EB8 7F0CC388 8E0C0000 */  lw    $t4, ($s0)
/* 100EBC 7F0CC38C 3C0D0200 */  lui   $t5, %hi(0x020005B8) # $t5, 0x200
/* 100EC0 7F0CC390 25AD05B8 */  addiu $t5, %lo(0x020005B8) # addiu $t5, $t5, 0x5b8
/* 100EC4 7F0CC394 00002825 */  move  $a1, $zero
/* 100EC8 7F0CC398 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100ECC 7F0CC39C 018D2021 */   addu  $a0, $t4, $t5
/* 100ED0 7F0CC3A0 8E0E0000 */  lw    $t6, ($s0)
/* 100ED4 7F0CC3A4 3C0F0200 */  lui   $t7, %hi(0x02000660) # $t7, 0x200
/* 100ED8 7F0CC3A8 25EF0660 */  addiu $t7, %lo(0x02000660) # addiu $t7, $t7, 0x660
/* 100EDC 7F0CC3AC 00002825 */  move  $a1, $zero
/* 100EE0 7F0CC3B0 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100EE4 7F0CC3B4 01CF2021 */   addu  $a0, $t6, $t7
/* 100EE8 7F0CC3B8 8E180000 */  lw    $t8, ($s0)
/* 100EEC 7F0CC3BC 3C190200 */  lui   $t9, %hi(0x02000708) # $t9, 0x200
/* 100EF0 7F0CC3C0 27390708 */  addiu $t9, %lo(0x02000708) # addiu $t9, $t9, 0x708
/* 100EF4 7F0CC3C4 00002825 */  move  $a1, $zero
/* 100EF8 7F0CC3C8 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100EFC 7F0CC3CC 03192021 */   addu  $a0, $t8, $t9
/* 100F00 7F0CC3D0 8E080000 */  lw    $t0, ($s0)
/* 100F04 7F0CC3D4 3C090200 */  lui   $t1, %hi(0x020007B0) # $t1, 0x200
/* 100F08 7F0CC3D8 252907B0 */  addiu $t1, %lo(0x020007B0) # addiu $t1, $t1, 0x7b0
/* 100F0C 7F0CC3DC 00002825 */  move  $a1, $zero
/* 100F10 7F0CC3E0 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100F14 7F0CC3E4 01092021 */   addu  $a0, $t0, $t1
/* 100F18 7F0CC3E8 8E0A0000 */  lw    $t2, ($s0)
/* 100F1C 7F0CC3EC 3C0B0200 */  lui   $t3, %hi(0x02000858) # $t3, 0x200
/* 100F20 7F0CC3F0 256B0858 */  addiu $t3, %lo(0x02000858) # addiu $t3, $t3, 0x858
/* 100F24 7F0CC3F4 00002825 */  move  $a1, $zero
/* 100F28 7F0CC3F8 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100F2C 7F0CC3FC 014B2021 */   addu  $a0, $t2, $t3
/* 100F30 7F0CC400 8E0C0000 */  lw    $t4, ($s0)
/* 100F34 7F0CC404 3C0D0200 */  lui   $t5, %hi(0x02000900) # $t5, 0x200
/* 100F38 7F0CC408 25AD0900 */  addiu $t5, %lo(0x02000900) # addiu $t5, $t5, 0x900
/* 100F3C 7F0CC40C 00002825 */  move  $a1, $zero
/* 100F40 7F0CC410 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100F44 7F0CC414 018D2021 */   addu  $a0, $t4, $t5
/* 100F48 7F0CC418 8E0E0000 */  lw    $t6, ($s0)
/* 100F4C 7F0CC41C 3C0F0200 */  lui   $t7, %hi(0x020009A8) # $t7, 0x200
/* 100F50 7F0CC420 25EF09A8 */  addiu $t7, %lo(0x020009A8) # addiu $t7, $t7, 0x9a8
/* 100F54 7F0CC424 00002825 */  move  $a1, $zero
/* 100F58 7F0CC428 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100F5C 7F0CC42C 01CF2021 */   addu  $a0, $t6, $t7
/* 100F60 7F0CC430 8E180000 */  lw    $t8, ($s0)
/* 100F64 7F0CC434 3C190200 */  lui   $t9, %hi(0x02000A50) # $t9, 0x200
/* 100F68 7F0CC438 27390A50 */  addiu $t9, %lo(0x02000A50) # addiu $t9, $t9, 0xa50
/* 100F6C 7F0CC43C 00002825 */  move  $a1, $zero
/* 100F70 7F0CC440 0FC32EDD */  jal   sub_GAME_7F0CBB74
/* 100F74 7F0CC444 03192021 */   addu  $a0, $t8, $t9
/* 100F78 7F0CC448 3C048009 */  lui   $a0, %hi(image) # $a0, 0x8009
/* 100F7C 7F0CC44C 8C84D0B8 */  lw    $a0, %lo(image)($a0)
/* 100F80 7F0CC450 0FC32F06 */  jal   load_image_to_buffer
/* 100F84 7F0CC454 00002825 */   move  $a1, $zero
/* 100F88 7F0CC458 00008025 */  move  $s0, $zero
/* 100F8C 7F0CC45C 8E480000 */  lw    $t0, ($s2)
.L7F0CC460:
/* 100F90 7F0CC460 00002825 */  move  $a1, $zero
/* 100F94 7F0CC464 0FC32F06 */  jal   load_image_to_buffer
/* 100F98 7F0CC468 02082021 */   addu  $a0, $s0, $t0
/* 100F9C 7F0CC46C 2610000C */  addiu $s0, $s0, 0xc
/* 100FA0 7F0CC470 2A010048 */  slti  $at, $s0, 0x48
/* 100FA4 7F0CC474 5420FFFA */  bnezl $at, .L7F0CC460
/* 100FA8 7F0CC478 8E480000 */   lw    $t0, ($s2)
/* 100FAC 7F0CC47C 00008025 */  move  $s0, $zero
/* 100FB0 7F0CC480 2411003C */  li    $s1, 60
/* 100FB4 7F0CC484 8E690000 */  lw    $t1, ($s3)
.L7F0CC488:
/* 100FB8 7F0CC488 00002825 */  move  $a1, $zero
/* 100FBC 7F0CC48C 0FC32F06 */  jal   load_image_to_buffer
/* 100FC0 7F0CC490 02092021 */   addu  $a0, $s0, $t1
/* 100FC4 7F0CC494 2610000C */  addiu $s0, $s0, 0xc
/* 100FC8 7F0CC498 5611FFFB */  bnel  $s0, $s1, .L7F0CC488
/* 100FCC 7F0CC49C 8E690000 */   lw    $t1, ($s3)
/* 100FD0 7F0CC4A0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 100FD4 7F0CC4A4 8FB00014 */  lw    $s0, 0x14($sp)
/* 100FD8 7F0CC4A8 8FB10018 */  lw    $s1, 0x18($sp)
/* 100FDC 7F0CC4AC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100FE0 7F0CC4B0 8FB30020 */  lw    $s3, 0x20($sp)
/* 100FE4 7F0CC4B4 03E00008 */  jr    $ra
/* 100FE8 7F0CC4B8 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


