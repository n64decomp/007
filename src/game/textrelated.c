#include "ultra64.h"


// data
s32 D_80040E80 = 0;
s32 text_spacing = 0;
s32 text_orientation = 0;
s32 text_wordwrap = 0;
s32 overlap_correction = -1;
s32 text_bilevel_filter = 0;
s32 text_x = 0;
s32 text_y = 0;
s32 text_s = 0;
s32 text_t = 0;
s32 D_80040EA8 = 0;
s32 ptrFirstFontTableSmall = 0;
s32 ptrSecondFontTableSmall = 0;
s32 ptrFirstFontTableLarge = 0;
s32 ptrSecondFontTableLarge = 0;

u16 D_80040EBC[] = {
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff
};
u32 D_80040EDC = 0;
u32 D_80040EE0 = 0;

u32 D_80040EE4[] = {
    0x55555555, 0x55555555,
    0xAAAAAAAA, 0xAAAAAAAA,
    0xFFFFFFFF, 0xFFFFFFFF
};
u32 D_80040EFC = 0;
u32 D_80040F00 = 0;


s32 D_80040F04 = 0xC;
s32 D_80040F08 = 0xB;
s32 D_80040F0C = 0;
s32 D_80040F10 = 0;
s32 D_80040F14 = 0;
s32 D_80040F18 = 0;
s32 D_80040F1C = 0xC;
s32 D_80040F20 = 0xB;
s32 D_80040F24 = 0;
s32 D_80040F28 = 0;



void null_init_main(void) {

}

void sub_GAME_7F0ACB78(s32 arg0) {
    text_spacing = (s32) -arg0;
}

void sub_GAME_7F0ACB88(s32 arg0) {
    text_orientation = arg0;
}

void sub_GAME_7F0ACB94(s32 arg0) {
    text_wordwrap = arg0;
}

void sub_GAME_7F0ACBA0(s32 arg0) {
    overlap_correction = arg0;
}






#ifdef NONMATCHING
void *load_font_tables(void) {
    s32 temp_a2;
    ? temp_ret;
    void *temp_v0;
    s32 temp_v1;
    s32 temp_a2_2;
    ? temp_ret_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    s32 temp_v1_2;
    s32 phi_v1;
    s32 phi_v1_2;

    // Node 0
    text_spacing = 0;
    text_orientation = 0;
    text_wordwrap = 0;
    overlap_correction = -1;
    text_bilevel_filter = 0;
    text_x = 0;
    text_y = 0;
    text_s = 0;
    temp_a2 = (&0x000024B0 - 0);
    text_t = 0;
    temp_ret = allocate_bytes_in_bank(temp_a2, 4, temp_a2);
    ptrFirstFontTableSmall = temp_ret;
    ptrSecondFontTableSmall = (s32) (temp_ret + 0x2a4);
    romCopy(temp_ret, &_fonttablectlsmall1SegmentRomStart, sp1C, &ptrFirstFontTableSmall);
    phi_v1 = 0;
loop_1:
    // Node 1
    temp_v0 = (ptrSecondFontTableSmall + phi_v1);
    temp_v1 = (phi_v1 + 0x18);
    temp_v0->unk14 = (s32) (temp_v0->unk14 + ptrFirstFontTableSmall);
    phi_v1 = temp_v1;
    if (temp_v1 < 0x8d0)
    {
        goto loop_1;
    }
    // Node 2
    temp_a2_2 = (&0x00003540 - 0);
    temp_ret_2 = allocate_bytes_in_bank(temp_a2_2, 4, temp_a2_2, &ptrFirstFontTableSmall);
    ptrFirstFontTableLarge = temp_ret_2;
    ptrSecondFontTableLarge = (void *) (temp_ret_2 + 0x2a4);
    romCopy(temp_ret_2, &_fonttablectllarge1SegmentRomStart, sp1C, &ptrFirstFontTableLarge);
    ptrSecondFontTableLarge->unk14 = (s32) (ptrSecondFontTableLarge->unk14 + ptrFirstFontTableLarge);
    ptrSecondFontTableLarge->unk2C = (s32) (ptrSecondFontTableLarge->unk2C + ptrFirstFontTableLarge);
    phi_v1_2 = 0x30;
loop_3:
    // Node 3
    temp_v0_2 = (ptrSecondFontTableLarge + phi_v1_2);
    temp_v0_2->unk14 = (s32) (temp_v0_2->unk14 + ptrFirstFontTableLarge);
    temp_v0_3 = (ptrSecondFontTableLarge + phi_v1_2);
    temp_v0_3->unk2C = (s32) (temp_v0_3->unk2C + ptrFirstFontTableLarge);
    temp_v0_4 = (ptrSecondFontTableLarge + phi_v1_2);
    temp_v0_4->unk44 = (s32) (temp_v0_4->unk44 + ptrFirstFontTableLarge);
    temp_v0_5 = (ptrSecondFontTableLarge + phi_v1_2);
    temp_v1_2 = (phi_v1_2 + 0x60);
    temp_v0_5->unk5C = (s32) (temp_v0_5->unk5C + ptrFirstFontTableLarge);
    phi_v1_2 = temp_v1_2;
    if (temp_v1_2 != 0x8d0)
    {
        goto loop_3;
    }
    // Node 4
    return temp_v0_5;
}
#else
GLOBAL_ASM(
.text
glabel load_font_tables
/* 0E16DC 7F0ACBAC 3C018004 */  lui   $at, %hi(text_spacing)
/* 0E16E0 7F0ACBB0 AC200E84 */  sw    $zero, %lo(text_spacing)($at)
/* 0E16E4 7F0ACBB4 3C018004 */  lui   $at, %hi(text_orientation)
/* 0E16E8 7F0ACBB8 AC200E88 */  sw    $zero, %lo(text_orientation)($at)
/* 0E16EC 7F0ACBBC 3C018004 */  lui   $at, %hi(text_wordwrap)
/* 0E16F0 7F0ACBC0 AC200E8C */  sw    $zero, %lo(text_wordwrap)($at)
/* 0E16F4 7F0ACBC4 3C018004 */  lui   $at, %hi(overlap_correction)
/* 0E16F8 7F0ACBC8 240EFFFF */  li    $t6, -1
/* 0E16FC 7F0ACBCC AC2E0E90 */  sw    $t6, %lo(overlap_correction)($at)
/* 0E1700 7F0ACBD0 3C018004 */  lui   $at, %hi(text_bilevel_filter)
/* 0E1704 7F0ACBD4 AC200E94 */  sw    $zero, %lo(text_bilevel_filter)($at)
/* 0E1708 7F0ACBD8 3C018004 */  lui   $at, %hi(text_x)
/* 0E170C 7F0ACBDC AC200E98 */  sw    $zero, %lo(text_x)($at)
/* 0E1710 7F0ACBE0 3C018004 */  lui   $at, %hi(text_y)
/* 0E1714 7F0ACBE4 AC200E9C */  sw    $zero, %lo(text_y)($at)
/* 0E1718 7F0ACBE8 3C018004 */  lui   $at, %hi(text_s)
/* 0E171C 7F0ACBEC 3C0F0000 */  lui   $t7, %hi(0x000024B0) # $t7, 0
/* 0E1720 7F0ACBF0 3C180000 */  lui   $t8, 0
/* 0E1724 7F0ACBF4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E1728 7F0ACBF8 AC200EA0 */  sw    $zero, %lo(text_s)($at)
/* 0E172C 7F0ACBFC 27180000 */  addiu $t8, $t8, 0
/* 0E1730 7F0ACC00 25EF24B0 */  addiu $t7, %lo(0x000024B0) # addiu $t7, $t7, 0x24b0
/* 0E1734 7F0ACC04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E1738 7F0ACC08 3C018004 */  lui   $at, %hi(text_t)
/* 0E173C 7F0ACC0C 01F83023 */  subu  $a2, $t7, $t8
/* 0E1740 7F0ACC10 AC200EA4 */  sw    $zero, %lo(text_t)($at)
/* 0E1744 7F0ACC14 00C02025 */  move  $a0, $a2
/* 0E1748 7F0ACC18 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0E174C 7F0ACC1C 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0E1750 7F0ACC20 24050004 */   li    $a1, 4
/* 0E1754 7F0ACC24 3C078004 */  lui   $a3, %hi(ptrFirstFontTableSmall)
/* 0E1758 7F0ACC28 3C088004 */  lui   $t0, %hi(ptrSecondFontTableSmall) 
/* 0E175C 7F0ACC2C 25080EB0 */  addiu $t0, %lo(ptrSecondFontTableSmall) # addiu $t0, $t0, 0xeb0
/* 0E1760 7F0ACC30 24E70EAC */  addiu $a3, %lo(ptrFirstFontTableSmall) # addiu $a3, $a3, 0xeac
/* 0E1764 7F0ACC34 245902A4 */  addiu $t9, $v0, 0x2a4
/* 0E1768 7F0ACC38 3C05002E */  lui   $a1, %hi(_fonttablectlsmall1SegmentRomStart) # $a1, 0x2e
/* 0E176C 7F0ACC3C ACE20000 */  sw    $v0, ($a3)
/* 0E1770 7F0ACC40 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0E1774 7F0ACC44 AD190000 */  sw    $t9, ($t0)
/* 0E1778 7F0ACC48 00402025 */  move  $a0, $v0
/* 0E177C 7F0ACC4C 0C001707 */  jal   romCopy
/* 0E1780 7F0ACC50 24A563F0 */   addiu $a1, %lo(_fonttablectlsmall1SegmentRomStart) # addiu $a1, $a1, 0x63f0
/* 0E1784 7F0ACC54 3C078004 */  lui   $a3, %hi(ptrFirstFontTableSmall)
/* 0E1788 7F0ACC58 3C088004 */  lui   $t0, %hi(ptrSecondFontTableSmall) 
/* 0E178C 7F0ACC5C 25080EB0 */  addiu $t0, %lo(ptrSecondFontTableSmall) # addiu $t0, $t0, 0xeb0
/* 0E1790 7F0ACC60 24E70EAC */  addiu $a3, %lo(ptrFirstFontTableSmall) # addiu $a3, $a3, 0xeac
/* 0E1794 7F0ACC64 00001825 */  move  $v1, $zero
.L7F0ACC68:
/* 0E1798 7F0ACC68 8D090000 */  lw    $t1, ($t0)
/* 0E179C 7F0ACC6C 8CEB0000 */  lw    $t3, ($a3)
/* 0E17A0 7F0ACC70 01231021 */  addu  $v0, $t1, $v1
/* 0E17A4 7F0ACC74 8C4A0014 */  lw    $t2, 0x14($v0)
/* 0E17A8 7F0ACC78 24630018 */  addiu $v1, $v1, 0x18
/* 0E17AC 7F0ACC7C 286108D0 */  slti  $at, $v1, 0x8d0
/* 0E17B0 7F0ACC80 014B6021 */  addu  $t4, $t2, $t3
/* 0E17B4 7F0ACC84 1420FFF8 */  bnez  $at, .L7F0ACC68
/* 0E17B8 7F0ACC88 AC4C0014 */   sw    $t4, 0x14($v0)
/* 0E17BC 7F0ACC8C 3C0D0000 */  lui   $t5, %hi(0x00003540) # $t5, 0
/* 0E17C0 7F0ACC90 3C0E0000 */  lui   $t6, 0
/* 0E17C4 7F0ACC94 25CE0000 */  addiu $t6, $t6, 0
/* 0E17C8 7F0ACC98 25AD3540 */  addiu $t5, %lo(0x00003540) # addiu $t5, $t5, 0x3540
/* 0E17CC 7F0ACC9C 01AE3023 */  subu  $a2, $t5, $t6
/* 0E17D0 7F0ACCA0 00C02025 */  move  $a0, $a2
/* 0E17D4 7F0ACCA4 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0E17D8 7F0ACCA8 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0E17DC 7F0ACCAC 24050004 */   li    $a1, 4
/* 0E17E0 7F0ACCB0 3C078004 */  lui   $a3, %hi(ptrFirstFontTableLarge)
/* 0E17E4 7F0ACCB4 3C088004 */  lui   $t0, %hi(ptrSecondFontTableLarge) 
/* 0E17E8 7F0ACCB8 25080EB8 */  addiu $t0, %lo(ptrSecondFontTableLarge) # addiu $t0, $t0, 0xeb8
/* 0E17EC 7F0ACCBC 24E70EB4 */  addiu $a3, %lo(ptrFirstFontTableLarge) # addiu $a3, $a3, 0xeb4
/* 0E17F0 7F0ACCC0 244F02A4 */  addiu $t7, $v0, 0x2a4
/* 0E17F4 7F0ACCC4 3C05002F */  lui   $a1, %hi(_fonttablectllarge1SegmentRomStart) # $a1, 0x2f
/* 0E17F8 7F0ACCC8 ACE20000 */  sw    $v0, ($a3)
/* 0E17FC 7F0ACCCC 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0E1800 7F0ACCD0 AD0F0000 */  sw    $t7, ($t0)
/* 0E1804 7F0ACCD4 00402025 */  move  $a0, $v0
/* 0E1808 7F0ACCD8 0C001707 */  jal   romCopy
/* 0E180C 7F0ACCDC 24A588A0 */   addiu $a1, %lo(_fonttablectllarge1SegmentRomStart) # addiu $a1, $a1, -0x7760
/* 0E1810 7F0ACCE0 3C088004 */  lui   $t0, %hi(ptrSecondFontTableLarge) 
/* 0E1814 7F0ACCE4 25080EB8 */  addiu $t0, %lo(ptrSecondFontTableLarge) # addiu $t0, $t0, 0xeb8
/* 0E1818 7F0ACCE8 8D020000 */  lw    $v0, ($t0)
/* 0E181C 7F0ACCEC 3C078004 */  lui   $a3, %hi(ptrFirstFontTableLarge)
/* 0E1820 7F0ACCF0 24E70EB4 */  addiu $a3, %lo(ptrFirstFontTableLarge) # addiu $a3, $a3, 0xeb4
/* 0E1824 7F0ACCF4 8CF90000 */  lw    $t9, ($a3)
/* 0E1828 7F0ACCF8 8C580014 */  lw    $t8, 0x14($v0)
/* 0E182C 7F0ACCFC 24030030 */  li    $v1, 48
/* 0E1830 7F0ACD00 240408D0 */  li    $a0, 2256
/* 0E1834 7F0ACD04 03194821 */  addu  $t1, $t8, $t9
/* 0E1838 7F0ACD08 AC490014 */  sw    $t1, 0x14($v0)
/* 0E183C 7F0ACD0C 8D020000 */  lw    $v0, ($t0)
/* 0E1840 7F0ACD10 8CEB0000 */  lw    $t3, ($a3)
/* 0E1844 7F0ACD14 8C4A002C */  lw    $t2, 0x2c($v0)
/* 0E1848 7F0ACD18 014B6021 */  addu  $t4, $t2, $t3
/* 0E184C 7F0ACD1C AC4C002C */  sw    $t4, 0x2c($v0)
.L7F0ACD20:
/* 0E1850 7F0ACD20 8D0D0000 */  lw    $t5, ($t0)
/* 0E1854 7F0ACD24 8CEF0000 */  lw    $t7, ($a3)
/* 0E1858 7F0ACD28 01A31021 */  addu  $v0, $t5, $v1
/* 0E185C 7F0ACD2C 8C4E0014 */  lw    $t6, 0x14($v0)
/* 0E1860 7F0ACD30 01CFC021 */  addu  $t8, $t6, $t7
/* 0E1864 7F0ACD34 AC580014 */  sw    $t8, 0x14($v0)
/* 0E1868 7F0ACD38 8D190000 */  lw    $t9, ($t0)
/* 0E186C 7F0ACD3C 8CEA0000 */  lw    $t2, ($a3)
/* 0E1870 7F0ACD40 03231021 */  addu  $v0, $t9, $v1
/* 0E1874 7F0ACD44 8C49002C */  lw    $t1, 0x2c($v0)
/* 0E1878 7F0ACD48 012A5821 */  addu  $t3, $t1, $t2
/* 0E187C 7F0ACD4C AC4B002C */  sw    $t3, 0x2c($v0)
/* 0E1880 7F0ACD50 8D0C0000 */  lw    $t4, ($t0)
/* 0E1884 7F0ACD54 8CEE0000 */  lw    $t6, ($a3)
/* 0E1888 7F0ACD58 01831021 */  addu  $v0, $t4, $v1
/* 0E188C 7F0ACD5C 8C4D0044 */  lw    $t5, 0x44($v0)
/* 0E1890 7F0ACD60 01AE7821 */  addu  $t7, $t5, $t6
/* 0E1894 7F0ACD64 AC4F0044 */  sw    $t7, 0x44($v0)
/* 0E1898 7F0ACD68 8D180000 */  lw    $t8, ($t0)
/* 0E189C 7F0ACD6C 8CE90000 */  lw    $t1, ($a3)
/* 0E18A0 7F0ACD70 03031021 */  addu  $v0, $t8, $v1
/* 0E18A4 7F0ACD74 8C59005C */  lw    $t9, 0x5c($v0)
/* 0E18A8 7F0ACD78 24630060 */  addiu $v1, $v1, 0x60
/* 0E18AC 7F0ACD7C 03295021 */  addu  $t2, $t9, $t1
/* 0E18B0 7F0ACD80 1464FFE7 */  bne   $v1, $a0, .L7F0ACD20
/* 0E18B4 7F0ACD84 AC4A005C */   sw    $t2, 0x5c($v0)
/* 0E18B8 7F0ACD88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E18BC 7F0ACD8C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0E18C0 7F0ACD90 03E00008 */  jr    $ra
/* 0E18C4 7F0ACD94 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void microcode_constructor(void) {

}
#else
GLOBAL_ASM(
.text
glabel microcode_constructor
/* 0E18C8 7F0ACD98 00801025 */  move  $v0, $a0
/* 0E18CC 7F0ACD9C 24840008 */  addiu $a0, $a0, 8
/* 0E18D0 7F0ACDA0 3C0EE700 */  lui   $t6, 0xe700
/* 0E18D4 7F0ACDA4 AC4E0000 */  sw    $t6, ($v0)
/* 0E18D8 7F0ACDA8 AC400004 */  sw    $zero, 4($v0)
/* 0E18DC 7F0ACDAC 00801825 */  move  $v1, $a0
/* 0E18E0 7F0ACDB0 24840008 */  addiu $a0, $a0, 8
/* 0E18E4 7F0ACDB4 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0E18E8 7F0ACDB8 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0E18EC 7F0ACDBC 00802825 */  move  $a1, $a0
/* 0E18F0 7F0ACDC0 AC6F0000 */  sw    $t7, ($v1)
/* 0E18F4 7F0ACDC4 AC600004 */  sw    $zero, 4($v1)
/* 0E18F8 7F0ACDC8 24840008 */  addiu $a0, $a0, 8
/* 0E18FC 7F0ACDCC 3C18BA00 */  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00
/* 0E1900 7F0ACDD0 37180602 */  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
/* 0E1904 7F0ACDD4 241900C0 */  li    $t9, 192
/* 0E1908 7F0ACDD8 00803025 */  move  $a2, $a0
/* 0E190C 7F0ACDDC ACB90004 */  sw    $t9, 4($a1)
/* 0E1910 7F0ACDE0 ACB80000 */  sw    $t8, ($a1)
/* 0E1914 7F0ACDE4 24840008 */  addiu $a0, $a0, 8
/* 0E1918 7F0ACDE8 3C08B900 */  lui   $t0, (0xB900031D >> 16) # lui $t0, 0xb900
/* 0E191C 7F0ACDEC 3C090050 */  lui   $t1, (0x005041C8 >> 16) # lui $t1, 0x50
/* 0E1920 7F0ACDF0 352941C8 */  ori   $t1, (0x005041C8 & 0xFFFF) # ori $t1, $t1, 0x41c8
/* 0E1924 7F0ACDF4 3508031D */  ori   $t0, (0xB900031D & 0xFFFF) # ori $t0, $t0, 0x31d
/* 0E1928 7F0ACDF8 00803825 */  move  $a3, $a0
/* 0E192C 7F0ACDFC ACC80000 */  sw    $t0, ($a2)
/* 0E1930 7F0ACE00 ACC90004 */  sw    $t1, 4($a2)
/* 0E1934 7F0ACE04 3C0AFCFF */  lui   $t2, (0xFCFF97FF >> 16) # lui $t2, 0xfcff
/* 0E1938 7F0ACE08 3C0BFF2D */  lui   $t3, (0xFF2DFEFF >> 16) # lui $t3, 0xff2d
/* 0E193C 7F0ACE0C 356BFEFF */  ori   $t3, (0xFF2DFEFF & 0xFFFF) # ori $t3, $t3, 0xfeff
/* 0E1940 7F0ACE10 354A97FF */  ori   $t2, (0xFCFF97FF & 0xFFFF) # ori $t2, $t2, 0x97ff
/* 0E1944 7F0ACE14 24840008 */  addiu $a0, $a0, 8
/* 0E1948 7F0ACE18 ACEA0000 */  sw    $t2, ($a3)
/* 0E194C 7F0ACE1C ACEB0004 */  sw    $t3, 4($a3)
/* 0E1950 7F0ACE20 00801025 */  move  $v0, $a0
/* 0E1954 7F0ACE24 24840008 */  addiu $a0, $a0, 8
/* 0E1958 7F0ACE28 3C0CBA00 */  lui   $t4, (0xBA001301 >> 16) # lui $t4, 0xba00
/* 0E195C 7F0ACE2C 358C1301 */  ori   $t4, (0xBA001301 & 0xFFFF) # ori $t4, $t4, 0x1301
/* 0E1960 7F0ACE30 00801825 */  move  $v1, $a0
/* 0E1964 7F0ACE34 AC4C0000 */  sw    $t4, ($v0)
/* 0E1968 7F0ACE38 AC400004 */  sw    $zero, 4($v0)
/* 0E196C 7F0ACE3C 24840008 */  addiu $a0, $a0, 8
/* 0E1970 7F0ACE40 3C0DB900 */  lui   $t5, (0xB9000002 >> 16) # lui $t5, 0xb900
/* 0E1974 7F0ACE44 35AD0002 */  ori   $t5, (0xB9000002 & 0xFFFF) # ori $t5, $t5, 2
/* 0E1978 7F0ACE48 00802825 */  move  $a1, $a0
/* 0E197C 7F0ACE4C AC6D0000 */  sw    $t5, ($v1)
/* 0E1980 7F0ACE50 AC600004 */  sw    $zero, 4($v1)
/* 0E1984 7F0ACE54 24840008 */  addiu $a0, $a0, 8
/* 0E1988 7F0ACE58 3C0EBA00 */  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
/* 0E198C 7F0ACE5C 35CE1001 */  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
/* 0E1990 7F0ACE60 00803025 */  move  $a2, $a0
/* 0E1994 7F0ACE64 ACAE0000 */  sw    $t6, ($a1)
/* 0E1998 7F0ACE68 ACA00004 */  sw    $zero, 4($a1)
/* 0E199C 7F0ACE6C 3C0FBA00 */  lui   $t7, (0xBA000903 >> 16) # lui $t7, 0xba00
/* 0E19A0 7F0ACE70 35EF0903 */  ori   $t7, (0xBA000903 & 0xFFFF) # ori $t7, $t7, 0x903
/* 0E19A4 7F0ACE74 24840008 */  addiu $a0, $a0, 8
/* 0E19A8 7F0ACE78 24180C00 */  li    $t8, 3072
/* 0E19AC 7F0ACE7C ACD80004 */  sw    $t8, 4($a2)
/* 0E19B0 7F0ACE80 ACCF0000 */  sw    $t7, ($a2)
/* 0E19B4 7F0ACE84 00803825 */  move  $a3, $a0
/* 0E19B8 7F0ACE88 3C19BA00 */  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00
/* 0E19BC 7F0ACE8C 37390E02 */  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02
/* 0E19C0 7F0ACE90 ACF90000 */  sw    $t9, ($a3)
/* 0E19C4 7F0ACE94 ACE00004 */  sw    $zero, 4($a3)
/* 0E19C8 7F0ACE98 3C088004 */  lui   $t0, %hi(text_bilevel_filter) 
/* 0E19CC 7F0ACE9C 8D080E94 */  lw    $t0, %lo(text_bilevel_filter)($t0)
/* 0E19D0 7F0ACEA0 24840008 */  addiu $a0, $a0, 8
/* 0E19D4 7F0ACEA4 00801025 */  move  $v0, $a0
/* 0E19D8 7F0ACEA8 1100000A */  beqz  $t0, .L7F0ACED4
/* 0E19DC 7F0ACEAC 3C0BBA00 */   lui   $t3, 0xba00
/* 0E19E0 7F0ACEB0 00801025 */  move  $v0, $a0
/* 0E19E4 7F0ACEB4 3C09BA00 */  lui   $t1, (0xBA000C02 >> 16) # lui $t1, 0xba00
/* 0E19E8 7F0ACEB8 35290C02 */  ori   $t1, (0xBA000C02 & 0xFFFF) # ori $t1, $t1, 0xc02
/* 0E19EC 7F0ACEBC 240A3000 */  li    $t2, 12288
/* 0E19F0 7F0ACEC0 AC4A0004 */  sw    $t2, 4($v0)
/* 0E19F4 7F0ACEC4 AC490000 */  sw    $t1, ($v0)
/* 0E19F8 7F0ACEC8 24840008 */  addiu $a0, $a0, 8
/* 0E19FC 7F0ACECC 03E00008 */  jr    $ra
/* 0E1A00 7F0ACED0 00801025 */   move  $v0, $a0

.L7F0ACED4:
/* 0E1A04 7F0ACED4 356B0C02 */  ori   $t3, $t3, 0xc02
/* 0E1A08 7F0ACED8 240C2000 */  li    $t4, 8192
/* 0E1A0C 7F0ACEDC AC4C0004 */  sw    $t4, 4($v0)
/* 0E1A10 7F0ACEE0 AC4B0000 */  sw    $t3, ($v0)
/* 0E1A14 7F0ACEE4 24840008 */  addiu $a0, $a0, 8
/* 0E1A18 7F0ACEE8 03E00008 */  jr    $ra
/* 0E1A1C 7F0ACEEC 00801025 */   move  $v0, $a0
)
#endif





#ifdef NONMATCHING
s32 combiner_bayer_lod_perspective(void *arg0) {
    void *temp_a1;
    void *temp_a2;
    void *temp_a3;

    // Node 0
    temp_a1 = (arg0 + 8);
    *arg0 = 0xe7000000;
    arg0->unk4 = 0;
    temp_a2 = (temp_a1 + 8);
    temp_a1->unk4 = 0x40;
    *temp_a1 = 0xba000602;
    temp_a3 = (temp_a2 + 8);
    temp_a2->unk4 = 0x80000;
    *temp_a2 = 0xba001301;
    temp_a3->unk4 = 0x10000;
    *temp_a3 = 0xba001001;
    return;
    // (possible return value: (temp_a3 + 8))
}

#else
GLOBAL_ASM(
.text
glabel combiner_bayer_lod_perspective
/* 0E1A20 7F0ACEF0 24850008 */  addiu $a1, $a0, 8
/* 0E1A24 7F0ACEF4 3C0EE700 */  lui   $t6, 0xe700
/* 0E1A28 7F0ACEF8 AC8E0000 */  sw    $t6, ($a0)
/* 0E1A2C 7F0ACEFC AC800004 */  sw    $zero, 4($a0)
/* 0E1A30 7F0ACF00 3C0FBA00 */  lui   $t7, (0xBA000602 >> 16) # lui $t7, 0xba00
/* 0E1A34 7F0ACF04 35EF0602 */  ori   $t7, (0xBA000602 & 0xFFFF) # ori $t7, $t7, 0x602
/* 0E1A38 7F0ACF08 24A60008 */  addiu $a2, $a1, 8
/* 0E1A3C 7F0ACF0C 24180040 */  li    $t8, 64
/* 0E1A40 7F0ACF10 ACB80004 */  sw    $t8, 4($a1)
/* 0E1A44 7F0ACF14 ACAF0000 */  sw    $t7, ($a1)
/* 0E1A48 7F0ACF18 3C19BA00 */  lui   $t9, (0xBA001301 >> 16) # lui $t9, 0xba00
/* 0E1A4C 7F0ACF1C 37391301 */  ori   $t9, (0xBA001301 & 0xFFFF) # ori $t9, $t9, 0x1301
/* 0E1A50 7F0ACF20 24C70008 */  addiu $a3, $a2, 8
/* 0E1A54 7F0ACF24 3C080008 */  lui   $t0, 8
/* 0E1A58 7F0ACF28 3C09BA00 */  lui   $t1, (0xBA001001 >> 16) # lui $t1, 0xba00
/* 0E1A5C 7F0ACF2C ACC80004 */  sw    $t0, 4($a2)
/* 0E1A60 7F0ACF30 ACD90000 */  sw    $t9, ($a2)
/* 0E1A64 7F0ACF34 35291001 */  ori   $t1, (0xBA001001 & 0xFFFF) # ori $t1, $t1, 0x1001
/* 0E1A68 7F0ACF38 3C0A0001 */  lui   $t2, 1
/* 0E1A6C 7F0ACF3C ACEA0004 */  sw    $t2, 4($a3)
/* 0E1A70 7F0ACF40 ACE90000 */  sw    $t1, ($a3)
/* 0E1A74 7F0ACF44 03E00008 */  jr    $ra
/* 0E1A78 7F0ACF48 24E20008 */   addiu $v0, $a3, 8
)
#endif





#ifdef NONMATCHING
s32 draw_blackbox_to_screen(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    void *temp_a0;
    void *temp_t0;
    void *temp_t1;
    void *temp_v1;
    void *temp_a1;

    // Node 0
    *arg0 = 0xb900031d;
    arg0->unk4 = 0x504240;
    temp_a0 = (arg0 + 8);
    *temp_a0 = 0xfcffffff;
    temp_a0->unk4 = 0xfffdf6fb;
    temp_t0 = (temp_a0 + 8);
    *temp_t0 = 0xfa000000;
    temp_t0->unk4 = 0;
    temp_t1 = (temp_t0 + 8);
    *temp_t1 = (s32) ((((*arg4 & 0x3ff) * 4) | 0xf6000000) | ((*arg3 & 0x3ff) << 0xe));
    temp_v1 = (temp_t1 + 8);
    temp_t1->unk4 = (s32) (((*arg2 & 0x3ff) * 4) | ((*arg1 & 0x3ff) << 0xe));
    temp_a1 = (temp_v1 + 8);
    temp_v1->unk4 = 0x504240;
    *temp_v1 = 0xb900031d;
    *temp_a1 = 0xfcff97ff;
    temp_a1->unk4 = 0xff2dfeff;
    return;
    // (possible return value: (temp_a1 + 8))
}

#else
GLOBAL_ASM(
.text
glabel draw_blackbox_to_screen
/* 0E1A7C 7F0ACF4C 3C0AB900 */  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
/* 0E1A80 7F0ACF50 3C0B0050 */  lui   $t3, (0x00504240 >> 16) # lui $t3, 0x50
/* 0E1A84 7F0ACF54 00801025 */  move  $v0, $a0
/* 0E1A88 7F0ACF58 356B4240 */  ori   $t3, (0x00504240 & 0xFFFF) # ori $t3, $t3, 0x4240
/* 0E1A8C 7F0ACF5C 354A031D */  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
/* 0E1A90 7F0ACF60 AC4A0000 */  sw    $t2, ($v0)
/* 0E1A94 7F0ACF64 AC4B0004 */  sw    $t3, 4($v0)
/* 0E1A98 7F0ACF68 3C0EFCFF */  lui   $t6, (0xFCFFFFFF >> 16) # lui $t6, 0xfcff
/* 0E1A9C 7F0ACF6C 3C0FFFFD */  lui   $t7, (0xFFFDF6FB >> 16) # lui $t7, 0xfffd
/* 0E1AA0 7F0ACF70 24840008 */  addiu $a0, $a0, 8
/* 0E1AA4 7F0ACF74 35EFF6FB */  ori   $t7, (0xFFFDF6FB & 0xFFFF) # ori $t7, $t7, 0xf6fb
/* 0E1AA8 7F0ACF78 35CEFFFF */  ori   $t6, (0xFCFFFFFF & 0xFFFF) # ori $t6, $t6, 0xffff
/* 0E1AAC 7F0ACF7C AC8E0000 */  sw    $t6, ($a0)
/* 0E1AB0 7F0ACF80 AC8F0004 */  sw    $t7, 4($a0)
/* 0E1AB4 7F0ACF84 24880008 */  addiu $t0, $a0, 8
/* 0E1AB8 7F0ACF88 3C18FA00 */  lui   $t8, 0xfa00
/* 0E1ABC 7F0ACF8C AD180000 */  sw    $t8, ($t0)
/* 0E1AC0 7F0ACF90 AD000004 */  sw    $zero, 4($t0)
/* 0E1AC4 7F0ACF94 8FB90010 */  lw    $t9, 0x10($sp)
/* 0E1AC8 7F0ACF98 8CF80000 */  lw    $t8, ($a3)
/* 0E1ACC 7F0ACF9C 3C01F600 */  lui   $at, 0xf600
/* 0E1AD0 7F0ACFA0 8F2C0000 */  lw    $t4, ($t9)
/* 0E1AD4 7F0ACFA4 331903FF */  andi  $t9, $t8, 0x3ff
/* 0E1AD8 7F0ACFA8 25090008 */  addiu $t1, $t0, 8
/* 0E1ADC 7F0ACFAC 318D03FF */  andi  $t5, $t4, 0x3ff
/* 0E1AE0 7F0ACFB0 000D7080 */  sll   $t6, $t5, 2
/* 0E1AE4 7F0ACFB4 01C17825 */  or    $t7, $t6, $at
/* 0E1AE8 7F0ACFB8 00196380 */  sll   $t4, $t9, 0xe
/* 0E1AEC 7F0ACFBC 01EC6825 */  or    $t5, $t7, $t4
/* 0E1AF0 7F0ACFC0 AD2D0000 */  sw    $t5, ($t1)
/* 0E1AF4 7F0ACFC4 8CAF0000 */  lw    $t7, ($a1)
/* 0E1AF8 7F0ACFC8 8CCE0000 */  lw    $t6, ($a2)
/* 0E1AFC 7F0ACFCC 25230008 */  addiu $v1, $t1, 8
/* 0E1B00 7F0ACFD0 31EC03FF */  andi  $t4, $t7, 0x3ff
/* 0E1B04 7F0ACFD4 31D803FF */  andi  $t8, $t6, 0x3ff
/* 0E1B08 7F0ACFD8 0018C880 */  sll   $t9, $t8, 2
/* 0E1B0C 7F0ACFDC 000C6B80 */  sll   $t5, $t4, 0xe
/* 0E1B10 7F0ACFE0 032D7025 */  or    $t6, $t9, $t5
/* 0E1B14 7F0ACFE4 AD2E0004 */  sw    $t6, 4($t1)
/* 0E1B18 7F0ACFE8 24650008 */  addiu $a1, $v1, 8
/* 0E1B1C 7F0ACFEC 3C18FCFF */  lui   $t8, (0xFCFF97FF >> 16) # lui $t8, 0xfcff
/* 0E1B20 7F0ACFF0 3C0FFF2D */  lui   $t7, (0xFF2DFEFF >> 16) # lui $t7, 0xff2d
/* 0E1B24 7F0ACFF4 AC6B0004 */  sw    $t3, 4($v1)
/* 0E1B28 7F0ACFF8 AC6A0000 */  sw    $t2, ($v1)
/* 0E1B2C 7F0ACFFC 35EFFEFF */  ori   $t7, (0xFF2DFEFF & 0xFFFF) # ori $t7, $t7, 0xfeff
/* 0E1B30 7F0AD000 371897FF */  ori   $t8, (0xFCFF97FF & 0xFFFF) # ori $t8, $t8, 0x97ff
/* 0E1B34 7F0AD004 ACB80000 */  sw    $t8, ($a1)
/* 0E1B38 7F0AD008 ACAF0004 */  sw    $t7, 4($a1)
/* 0E1B3C 7F0AD00C 03E00008 */  jr    $ra
/* 0E1B40 7F0AD010 24A20008 */   addiu $v0, $a1, 8
)
#endif





#ifdef NONMATCHING
s32 microcode_constructor_related_to_menus(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    void *temp_a0;
    void *temp_t0;
    void *temp_t1;
    void *temp_v1;

    // Node 0
    *arg0 = 0xb900031d;
    arg0->unk4 = 0x504240;
    temp_a0 = (arg0 + 8);
    *temp_a0 = 0xfcffffff;
    temp_a0->unk4 = 0xfffdf6fb;
    temp_t0 = (temp_a0 + 8);
    *temp_t0 = 0xfa000000;
    temp_t1 = (temp_t0 + 8);
    temp_t0->unk4 = (s32) (((((arg5 >> 0x18) << 0x18) | (((arg5 >> 0x10) & 0xff) << 0x10)) | (((arg5 >> 8) & 0xff) << 8)) | (arg5 & 0xff));
    temp_v1 = (temp_t1 + 8);
    temp_t1->unk4 = (s32) (((arg1 & 0x3ff) << 0xe) | ((arg2 & 0x3ff) * 4));
    *temp_t1 = (s32) ((((arg3 & 0x3ff) << 0xe) | 0xf6000000) | ((arg4 & 0x3ff) * 4));
    temp_v1->unk4 = 0xff2dfeff;
    *temp_v1 = 0xfcff97ff;
    return;
    // (possible return value: (temp_v1 + 8))
}

#else
GLOBAL_ASM(
.text
glabel microcode_constructor_related_to_menus
/* 0E1B44 7F0AD014 00801025 */  move  $v0, $a0
/* 0E1B48 7F0AD018 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0E1B4C 7F0AD01C 3C0F0050 */  lui   $t7, (0x00504240 >> 16) # lui $t7, 0x50
/* 0E1B50 7F0AD020 35EF4240 */  ori   $t7, (0x00504240 & 0xFFFF) # ori $t7, $t7, 0x4240
/* 0E1B54 7F0AD024 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0E1B58 7F0AD028 AC4E0000 */  sw    $t6, ($v0)
/* 0E1B5C 7F0AD02C AC4F0004 */  sw    $t7, 4($v0)
/* 0E1B60 7F0AD030 3C18FCFF */  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
/* 0E1B64 7F0AD034 3C19FFFD */  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
/* 0E1B68 7F0AD038 24840008 */  addiu $a0, $a0, 8
/* 0E1B6C 7F0AD03C 3739F6FB */  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
/* 0E1B70 7F0AD040 3718FFFF */  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
/* 0E1B74 7F0AD044 AC980000 */  sw    $t8, ($a0)
/* 0E1B78 7F0AD048 AC990004 */  sw    $t9, 4($a0)
/* 0E1B7C 7F0AD04C 24880008 */  addiu $t0, $a0, 8
/* 0E1B80 7F0AD050 3C0AFA00 */  lui   $t2, 0xfa00
/* 0E1B84 7F0AD054 AD0A0000 */  sw    $t2, ($t0)
/* 0E1B88 7F0AD058 8FAB0014 */  lw    $t3, 0x14($sp)
/* 0E1B8C 7F0AD05C 3C01F600 */  lui   $at, 0xf600
/* 0E1B90 7F0AD060 25090008 */  addiu $t1, $t0, 8
/* 0E1B94 7F0AD064 000BCC02 */  srl   $t9, $t3, 0x10
/* 0E1B98 7F0AD068 332A00FF */  andi  $t2, $t9, 0xff
/* 0E1B9C 7F0AD06C 000A6400 */  sll   $t4, $t2, 0x10
/* 0E1BA0 7F0AD070 000B7602 */  srl   $t6, $t3, 0x18
/* 0E1BA4 7F0AD074 000E7E00 */  sll   $t7, $t6, 0x18
/* 0E1BA8 7F0AD078 000BC202 */  srl   $t8, $t3, 8
/* 0E1BAC 7F0AD07C 331900FF */  andi  $t9, $t8, 0xff
/* 0E1BB0 7F0AD080 01EC6825 */  or    $t5, $t7, $t4
/* 0E1BB4 7F0AD084 00195200 */  sll   $t2, $t9, 8
/* 0E1BB8 7F0AD088 01606025 */  move  $t4, $t3
/* 0E1BBC 7F0AD08C 318E00FF */  andi  $t6, $t4, 0xff
/* 0E1BC0 7F0AD090 01AA7825 */  or    $t7, $t5, $t2
/* 0E1BC4 7F0AD094 01EEC025 */  or    $t8, $t7, $t6
/* 0E1BC8 7F0AD098 AD180004 */  sw    $t8, 4($t0)
/* 0E1BCC 7F0AD09C 8FAB0010 */  lw    $t3, 0x10($sp)
/* 0E1BD0 7F0AD0A0 30F903FF */  andi  $t9, $a3, 0x3ff
/* 0E1BD4 7F0AD0A4 00196B80 */  sll   $t5, $t9, 0xe
/* 0E1BD8 7F0AD0A8 01A15025 */  or    $t2, $t5, $at
/* 0E1BDC 7F0AD0AC 316C03FF */  andi  $t4, $t3, 0x3ff
/* 0E1BE0 7F0AD0B0 000C7880 */  sll   $t7, $t4, 2
/* 0E1BE4 7F0AD0B4 014F7025 */  or    $t6, $t2, $t7
/* 0E1BE8 7F0AD0B8 30CD03FF */  andi  $t5, $a2, 0x3ff
/* 0E1BEC 7F0AD0BC 30B803FF */  andi  $t8, $a1, 0x3ff
/* 0E1BF0 7F0AD0C0 0018CB80 */  sll   $t9, $t8, 0xe
/* 0E1BF4 7F0AD0C4 000D5880 */  sll   $t3, $t5, 2
/* 0E1BF8 7F0AD0C8 032B6025 */  or    $t4, $t9, $t3
/* 0E1BFC 7F0AD0CC 25230008 */  addiu $v1, $t1, 8
/* 0E1C00 7F0AD0D0 3C0FFF2D */  lui   $t7, (0xFF2DFEFF >> 16) # lui $t7, 0xff2d
/* 0E1C04 7F0AD0D4 3C0AFCFF */  lui   $t2, (0xFCFF97FF >> 16) # lui $t2, 0xfcff
/* 0E1C08 7F0AD0D8 AD2C0004 */  sw    $t4, 4($t1)
/* 0E1C0C 7F0AD0DC AD2E0000 */  sw    $t6, ($t1)
/* 0E1C10 7F0AD0E0 354A97FF */  ori   $t2, (0xFCFF97FF & 0xFFFF) # ori $t2, $t2, 0x97ff
/* 0E1C14 7F0AD0E4 35EFFEFF */  ori   $t7, (0xFF2DFEFF & 0xFFFF) # ori $t7, $t7, 0xfeff
/* 0E1C18 7F0AD0E8 AC6F0004 */  sw    $t7, 4($v1)
/* 0E1C1C 7F0AD0EC AC6A0000 */  sw    $t2, ($v1)
/* 0E1C20 7F0AD0F0 03E00008 */  jr    $ra
/* 0E1C24 7F0AD0F4 24620008 */   addiu $v0, $v1, 8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0AD0F8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AD0F8
/* 0E1C28 7F0AD0F8 27BDFF10 */  addiu $sp, $sp, -0xf0
/* 0E1C2C 7F0AD0FC 8FB90100 */  lw    $t9, 0x100($sp)
/* 0E1C30 7F0AD100 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E1C34 7F0AD104 AFB10018 */  sw    $s1, 0x18($sp)
/* 0E1C38 7F0AD108 AFB00014 */  sw    $s0, 0x14($sp)
/* 0E1C3C 7F0AD10C AFA500F4 */  sw    $a1, 0xf4($sp)
/* 0E1C40 7F0AD110 8F2C0010 */  lw    $t4, 0x10($t9)
/* 0E1C44 7F0AD114 8CCE0000 */  lw    $t6, ($a2)
/* 0E1C48 7F0AD118 8FAF0118 */  lw    $t7, 0x118($sp)
/* 0E1C4C 7F0AD11C 000C6880 */  sll   $t5, $t4, 2
/* 0E1C50 7F0AD120 01AC6823 */  subu  $t5, $t5, $t4
/* 0E1C54 7F0AD124 8FB80104 */  lw    $t8, 0x104($sp)
/* 0E1C58 7F0AD128 000D6880 */  sll   $t5, $t5, 2
/* 0E1C5C 7F0AD12C 8CF90010 */  lw    $t9, 0x10($a3)
/* 0E1C60 7F0AD130 01AC6821 */  addu  $t5, $t5, $t4
/* 0E1C64 7F0AD134 01CF4821 */  addu  $t1, $t6, $t7
/* 0E1C68 7F0AD138 000D7080 */  sll   $t6, $t5, 2
/* 0E1C6C 7F0AD13C 030E7821 */  addu  $t7, $t8, $t6
/* 0E1C70 7F0AD140 00196080 */  sll   $t4, $t9, 2
/* 0E1C74 7F0AD144 01EC6821 */  addu  $t5, $t7, $t4
/* 0E1C78 7F0AD148 3C0E8004 */  lui   $t6, %hi(text_spacing) 
/* 0E1C7C 7F0AD14C 8DCE0E84 */  lw    $t6, %lo(text_spacing)($t6)
/* 0E1C80 7F0AD150 8DB80000 */  lw    $t8, ($t5)
/* 0E1C84 7F0AD154 8CAF0000 */  lw    $t7, ($a1)
/* 0E1C88 7F0AD158 00808025 */  move  $s0, $a0
/* 0E1C8C 7F0AD15C 030E1021 */  addu  $v0, $t8, $t6
/* 0E1C90 7F0AD160 01E26023 */  subu  $t4, $t7, $v0
/* 0E1C94 7F0AD164 258D0001 */  addiu $t5, $t4, 1
/* 0E1C98 7F0AD168 ACAD0000 */  sw    $t5, ($a1)
/* 0E1C9C 7F0AD16C 3C188004 */  lui   $t8, %hi(text_orientation) 
/* 0E1CA0 7F0AD170 8F180E88 */  lw    $t8, %lo(text_orientation)($t8)
/* 0E1CA4 7F0AD174 00E08825 */  move  $s1, $a3
/* 0E1CA8 7F0AD178 57000014 */  bnezl $t8, .L7F0AD1CC
/* 0E1CAC 7F0AD17C 8FA40108 */   lw    $a0, 0x108($sp)
/* 0E1CB0 7F0AD180 59A00244 */  blezl $t5, .L7F0ADA94
/* 0E1CB4 7F0AD184 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1CB8 7F0AD188 0C001107 */  jal   get_video2_settings_txtClipW
/* 0E1CBC 7F0AD18C AFA900E0 */   sw    $t1, 0xe0($sp)
/* 0E1CC0 7F0AD190 8FAE00F4 */  lw    $t6, 0xf4($sp)
/* 0E1CC4 7F0AD194 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0E1CC8 7F0AD198 8DCF0000 */  lw    $t7, ($t6)
/* 0E1CCC 7F0AD19C 004F082A */  slt   $at, $v0, $t7
/* 0E1CD0 7F0AD1A0 5420023C */  bnezl $at, .L7F0ADA94
/* 0E1CD4 7F0AD1A4 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1CD8 7F0AD1A8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0E1CDC 7F0AD1AC AFA900E0 */   sw    $t1, 0xe0($sp)
/* 0E1CE0 7F0AD1B0 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0E1CE4 7F0AD1B4 8E2C0004 */  lw    $t4, 4($s1)
/* 0E1CE8 7F0AD1B8 012CC821 */  addu  $t9, $t1, $t4
/* 0E1CEC 7F0AD1BC 0059082A */  slt   $at, $v0, $t9
/* 0E1CF0 7F0AD1C0 54200234 */  bnezl $at, .L7F0ADA94
/* 0E1CF4 7F0AD1C4 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1CF8 7F0AD1C8 8FA40108 */  lw    $a0, 0x108($sp)
.L7F0AD1CC:
/* 0E1CFC 7F0AD1CC 8FB80110 */  lw    $t8, 0x110($sp)
/* 0E1D00 7F0AD1D0 8FAE00F4 */  lw    $t6, 0xf4($sp)
/* 0E1D04 7F0AD1D4 8FAA010C */  lw    $t2, 0x10c($sp)
/* 0E1D08 7F0AD1D8 00986821 */  addu  $t5, $a0, $t8
/* 0E1D0C 7F0AD1DC AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E1D10 7F0AD1E0 8DC20000 */  lw    $v0, ($t6)
/* 0E1D14 7F0AD1E4 8FAC0114 */  lw    $t4, 0x114($sp)
/* 0E1D18 7F0AD1E8 01A2082A */  slt   $at, $t5, $v0
/* 0E1D1C 7F0AD1EC 54200229 */  bnezl $at, .L7F0ADA94
/* 0E1D20 7F0AD1F0 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1D24 7F0AD1F4 8E390004 */  lw    $t9, 4($s1)
/* 0E1D28 7F0AD1F8 014C5821 */  addu  $t3, $t2, $t4
/* 0E1D2C 7F0AD1FC 03291821 */  addu  $v1, $t9, $t1
/* 0E1D30 7F0AD200 0163082A */  slt   $at, $t3, $v1
/* 0E1D34 7F0AD204 14200222 */  bnez  $at, .L7F0ADA90
/* 0E1D38 7F0AD208 0044082A */   slt   $at, $v0, $a0
/* 0E1D3C 7F0AD20C 54200221 */  bnezl $at, .L7F0ADA94
/* 0E1D40 7F0AD210 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1D44 7F0AD214 8E380008 */  lw    $t8, 8($s1)
/* 0E1D48 7F0AD218 00786821 */  addu  $t5, $v1, $t8
/* 0E1D4C 7F0AD21C 01AA082A */  slt   $at, $t5, $t2
/* 0E1D50 7F0AD220 5420021C */  bnezl $at, .L7F0ADA94
/* 0E1D54 7F0AD224 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E1D58 7F0AD228 8E2E0000 */  lw    $t6, ($s1)
/* 0E1D5C 7F0AD22C 3C058004 */  lui   $a1, %hi(D_80040EA8)
/* 0E1D60 7F0AD230 24A50EA8 */  addiu $a1, %lo(D_80040EA8) # addiu $a1, $a1, 0xea8
/* 0E1D64 7F0AD234 29C10080 */  slti  $at, $t6, 0x80
/* 0E1D68 7F0AD238 1020006F */  beqz  $at, .L7F0AD3F8
/* 0E1D6C 7F0AD23C 02001025 */   move  $v0, $s0
/* 0E1D70 7F0AD240 02001025 */  move  $v0, $s0
/* 0E1D74 7F0AD244 3C0FBA00 */  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
/* 0E1D78 7F0AD248 35EF0E02 */  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
/* 0E1D7C 7F0AD24C 26100008 */  addiu $s0, $s0, 8
/* 0E1D80 7F0AD250 AC4F0000 */  sw    $t7, ($v0)
/* 0E1D84 7F0AD254 AC400004 */  sw    $zero, 4($v0)
/* 0E1D88 7F0AD258 02001825 */  move  $v1, $s0
/* 0E1D8C 7F0AD25C 3C0CFD90 */  lui   $t4, 0xfd90
/* 0E1D90 7F0AD260 AC6C0000 */  sw    $t4, ($v1)
/* 0E1D94 7F0AD264 8E390014 */  lw    $t9, 0x14($s1)
/* 0E1D98 7F0AD268 26100008 */  addiu $s0, $s0, 8
/* 0E1D9C 7F0AD26C 02002025 */  move  $a0, $s0
/* 0E1DA0 7F0AD270 26100008 */  addiu $s0, $s0, 8
/* 0E1DA4 7F0AD274 AC790004 */  sw    $t9, 4($v1)
/* 0E1DA8 7F0AD278 02002825 */  move  $a1, $s0
/* 0E1DAC 7F0AD27C 3C18F590 */  lui   $t8, 0xf590
/* 0E1DB0 7F0AD280 3C0D0700 */  lui   $t5, 0x700
/* 0E1DB4 7F0AD284 AC8D0004 */  sw    $t5, 4($a0)
/* 0E1DB8 7F0AD288 AC980000 */  sw    $t8, ($a0)
/* 0E1DBC 7F0AD28C 26100008 */  addiu $s0, $s0, 8
/* 0E1DC0 7F0AD290 3C0EE600 */  lui   $t6, 0xe600
/* 0E1DC4 7F0AD294 ACAE0000 */  sw    $t6, ($a1)
/* 0E1DC8 7F0AD298 02004025 */  move  $t0, $s0
/* 0E1DCC 7F0AD29C ACA00004 */  sw    $zero, 4($a1)
/* 0E1DD0 7F0AD2A0 3C0FF300 */  lui   $t7, 0xf300
/* 0E1DD4 7F0AD2A4 AD0F0000 */  sw    $t7, ($t0)
/* 0E1DD8 7F0AD2A8 8E23000C */  lw    $v1, 0xc($s1)
/* 0E1DDC 7F0AD2AC 8E390008 */  lw    $t9, 8($s1)
/* 0E1DE0 7F0AD2B0 26100008 */  addiu $s0, $s0, 8
/* 0E1DE4 7F0AD2B4 24630007 */  addiu $v1, $v1, 7
/* 0E1DE8 7F0AD2B8 306C00F8 */  andi  $t4, $v1, 0xf8
/* 0E1DEC 7F0AD2BC 01990019 */  multu $t4, $t9
/* 0E1DF0 7F0AD2C0 01801825 */  move  $v1, $t4
/* 0E1DF4 7F0AD2C4 240607FF */  li    $a2, 2047
/* 0E1DF8 7F0AD2C8 00001012 */  mflo  $v0
/* 0E1DFC 7F0AD2CC 24420001 */  addiu $v0, $v0, 1
/* 0E1E00 7F0AD2D0 0002C043 */  sra   $t8, $v0, 1
/* 0E1E04 7F0AD2D4 2702FFFF */  addiu $v0, $t8, -1
/* 0E1E08 7F0AD2D8 284107FF */  slti  $at, $v0, 0x7ff
/* 0E1E0C 7F0AD2DC 10200003 */  beqz  $at, .L7F0AD2EC
/* 0E1E10 7F0AD2E0 00000000 */   nop   
/* 0E1E14 7F0AD2E4 10000001 */  b     .L7F0AD2EC
/* 0E1E18 7F0AD2E8 00403025 */   move  $a2, $v0
.L7F0AD2EC:
/* 0E1E1C 7F0AD2EC 04610003 */  bgez  $v1, .L7F0AD2FC
/* 0E1E20 7F0AD2F0 000310C3 */   sra   $v0, $v1, 3
/* 0E1E24 7F0AD2F4 24610007 */  addiu $at, $v1, 7
/* 0E1E28 7F0AD2F8 000110C3 */  sra   $v0, $at, 3
.L7F0AD2FC:
/* 0E1E2C 7F0AD2FC 1C400003 */  bgtz  $v0, .L7F0AD30C
/* 0E1E30 7F0AD300 30D90FFF */   andi  $t9, $a2, 0xfff
/* 0E1E34 7F0AD304 10000002 */  b     .L7F0AD310
/* 0E1E38 7F0AD308 24070001 */   li    $a3, 1
.L7F0AD30C:
/* 0E1E3C 7F0AD30C 00403825 */  move  $a3, $v0
.L7F0AD310:
/* 0E1E40 7F0AD310 1C400003 */  bgtz  $v0, .L7F0AD320
/* 0E1E44 7F0AD314 24ED07FF */   addiu $t5, $a3, 0x7ff
/* 0E1E48 7F0AD318 10000002 */  b     .L7F0AD324
/* 0E1E4C 7F0AD31C 24050001 */   li    $a1, 1
.L7F0AD320:
/* 0E1E50 7F0AD320 00402825 */  move  $a1, $v0
.L7F0AD324:
/* 0E1E54 7F0AD324 01A5001A */  div   $zero, $t5, $a1
/* 0E1E58 7F0AD328 14A00002 */  bnez  $a1, .L7F0AD334
/* 0E1E5C 7F0AD32C 00000000 */   nop   
/* 0E1E60 7F0AD330 0007000D */  break 7
.L7F0AD334:
/* 0E1E64 7F0AD334 2401FFFF */  li    $at, -1
/* 0E1E68 7F0AD338 14A10004 */  bne   $a1, $at, .L7F0AD34C
/* 0E1E6C 7F0AD33C 3C018000 */   lui   $at, 0x8000
/* 0E1E70 7F0AD340 15A10002 */  bne   $t5, $at, .L7F0AD34C
/* 0E1E74 7F0AD344 00000000 */   nop   
/* 0E1E78 7F0AD348 0006000D */  break 6
.L7F0AD34C:
/* 0E1E7C 7F0AD34C 00007012 */  mflo  $t6
/* 0E1E80 7F0AD350 31CF0FFF */  andi  $t7, $t6, 0xfff
/* 0E1E84 7F0AD354 3C010700 */  lui   $at, 0x700
/* 0E1E88 7F0AD358 01E16025 */  or    $t4, $t7, $at
/* 0E1E8C 7F0AD35C 0019C300 */  sll   $t8, $t9, 0xc
/* 0E1E90 7F0AD360 01986825 */  or    $t5, $t4, $t8
/* 0E1E94 7F0AD364 AD0D0004 */  sw    $t5, 4($t0)
/* 0E1E98 7F0AD368 02001025 */  move  $v0, $s0
/* 0E1E9C 7F0AD36C 3C0EE700 */  lui   $t6, 0xe700
/* 0E1EA0 7F0AD370 AC4E0000 */  sw    $t6, ($v0)
/* 0E1EA4 7F0AD374 AC400004 */  sw    $zero, 4($v0)
/* 0E1EA8 7F0AD378 8E2F000C */  lw    $t7, 0xc($s1)
/* 0E1EAC 7F0AD37C 26100008 */  addiu $s0, $s0, 8
/* 0E1EB0 7F0AD380 02001825 */  move  $v1, $s0
/* 0E1EB4 7F0AD384 25F90007 */  addiu $t9, $t7, 7
/* 0E1EB8 7F0AD388 332C00F8 */  andi  $t4, $t9, 0xf8
/* 0E1EBC 7F0AD38C 25980007 */  addiu $t8, $t4, 7
/* 0E1EC0 7F0AD390 001868C3 */  sra   $t5, $t8, 3
/* 0E1EC4 7F0AD394 31AE01FF */  andi  $t6, $t5, 0x1ff
/* 0E1EC8 7F0AD398 000E7A40 */  sll   $t7, $t6, 9
/* 0E1ECC 7F0AD39C 3C01F588 */  lui   $at, 0xf588
/* 0E1ED0 7F0AD3A0 01E1C825 */  or    $t9, $t7, $at
/* 0E1ED4 7F0AD3A4 26100008 */  addiu $s0, $s0, 8
/* 0E1ED8 7F0AD3A8 02002025 */  move  $a0, $s0
/* 0E1EDC 7F0AD3AC AC790000 */  sw    $t9, ($v1)
/* 0E1EE0 7F0AD3B0 3C0CF200 */  lui   $t4, 0xf200
/* 0E1EE4 7F0AD3B4 AC600004 */  sw    $zero, 4($v1)
/* 0E1EE8 7F0AD3B8 AC8C0000 */  sw    $t4, ($a0)
/* 0E1EEC 7F0AD3BC 8E38000C */  lw    $t8, 0xc($s1)
/* 0E1EF0 7F0AD3C0 26100008 */  addiu $s0, $s0, 8
/* 0E1EF4 7F0AD3C4 270D0007 */  addiu $t5, $t8, 7
/* 0E1EF8 7F0AD3C8 31AE00F8 */  andi  $t6, $t5, 0xf8
/* 0E1EFC 7F0AD3CC 8E2D0008 */  lw    $t5, 8($s1)
/* 0E1F00 7F0AD3D0 25CFFFFF */  addiu $t7, $t6, -1
/* 0E1F04 7F0AD3D4 000FC880 */  sll   $t9, $t7, 2
/* 0E1F08 7F0AD3D8 332C0FFF */  andi  $t4, $t9, 0xfff
/* 0E1F0C 7F0AD3DC 25AEFFFF */  addiu $t6, $t5, -1
/* 0E1F10 7F0AD3E0 000E7880 */  sll   $t7, $t6, 2
/* 0E1F14 7F0AD3E4 31F90FFF */  andi  $t9, $t7, 0xfff
/* 0E1F18 7F0AD3E8 000CC300 */  sll   $t8, $t4, 0xc
/* 0E1F1C 7F0AD3EC 03196025 */  or    $t4, $t8, $t9
/* 0E1F20 7F0AD3F0 100000AC */  b     .L7F0AD6A4
/* 0E1F24 7F0AD3F4 AC8C0004 */   sw    $t4, 4($a0)
.L7F0AD3F8:
/* 0E1F28 7F0AD3F8 26100008 */  addiu $s0, $s0, 8
/* 0E1F2C 7F0AD3FC 3C0DE700 */  lui   $t5, 0xe700
/* 0E1F30 7F0AD400 AC4D0000 */  sw    $t5, ($v0)
/* 0E1F34 7F0AD404 AC400004 */  sw    $zero, 4($v0)
/* 0E1F38 7F0AD408 02001825 */  move  $v1, $s0
/* 0E1F3C 7F0AD40C 3C0EBA00 */  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00
/* 0E1F40 7F0AD410 35CE0E02 */  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
/* 0E1F44 7F0AD414 340FC000 */  li    $t7, 49152
/* 0E1F48 7F0AD418 AC6F0004 */  sw    $t7, 4($v1)
/* 0E1F4C 7F0AD41C AC6E0000 */  sw    $t6, ($v1)
/* 0E1F50 7F0AD420 8CB80000 */  lw    $t8, ($a1)
/* 0E1F54 7F0AD424 26100008 */  addiu $s0, $s0, 8
/* 0E1F58 7F0AD428 02003825 */  move  $a3, $s0
/* 0E1F5C 7F0AD42C 13000056 */  beqz  $t8, .L7F0AD588
/* 0E1F60 7F0AD430 3C19FD10 */   lui   $t9, 0xfd10
/* 0E1F64 7F0AD434 ACA00000 */  sw    $zero, ($a1)
/* 0E1F68 7F0AD438 ACF90000 */  sw    $t9, ($a3)
/* 0E1F6C 7F0AD43C 3C048004 */  lui   $a0, %hi(D_80040EBC)
/* 0E1F70 7F0AD440 24840EBC */  addiu $a0, %lo(D_80040EBC) # addiu $a0, $a0, 0xebc
/* 0E1F74 7F0AD444 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0E1F78 7F0AD448 AFA900E0 */  sw    $t1, 0xe0($sp)
/* 0E1F7C 7F0AD44C AFA700B4 */  sw    $a3, 0xb4($sp)
/* 0E1F80 7F0AD450 0C003A2C */  jal   osVirtualToPhysical
/* 0E1F84 7F0AD454 26100008 */   addiu $s0, $s0, 8
/* 0E1F88 7F0AD458 8FA700B4 */  lw    $a3, 0xb4($sp)
/* 0E1F8C 7F0AD45C 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0E1F90 7F0AD460 8FAB0020 */  lw    $t3, 0x20($sp)
/* 0E1F94 7F0AD464 02001825 */  move  $v1, $s0
/* 0E1F98 7F0AD468 26100008 */  addiu $s0, $s0, 8
/* 0E1F9C 7F0AD46C ACE20004 */  sw    $v0, 4($a3)
/* 0E1FA0 7F0AD470 02002025 */  move  $a0, $s0
/* 0E1FA4 7F0AD474 3C0CE800 */  lui   $t4, 0xe800
/* 0E1FA8 7F0AD478 3C0DF500 */  lui   $t5, (0xF5000100 >> 16) # lui $t5, 0xf500
/* 0E1FAC 7F0AD47C 35AD0100 */  ori   $t5, (0xF5000100 & 0xFFFF) # ori $t5, $t5, 0x100
/* 0E1FB0 7F0AD480 AC6C0000 */  sw    $t4, ($v1)
/* 0E1FB4 7F0AD484 AC600004 */  sw    $zero, 4($v1)
/* 0E1FB8 7F0AD488 AC8D0000 */  sw    $t5, ($a0)
/* 0E1FBC 7F0AD48C 26100008 */  addiu $s0, $s0, 8
/* 0E1FC0 7F0AD490 3C0E0700 */  lui   $t6, 0x700
/* 0E1FC4 7F0AD494 AC8E0004 */  sw    $t6, 4($a0)
/* 0E1FC8 7F0AD498 02002825 */  move  $a1, $s0
/* 0E1FCC 7F0AD49C 26100008 */  addiu $s0, $s0, 8
/* 0E1FD0 7F0AD4A0 02003025 */  move  $a2, $s0
/* 0E1FD4 7F0AD4A4 3C0FE600 */  lui   $t7, 0xe600
/* 0E1FD8 7F0AD4A8 ACAF0000 */  sw    $t7, ($a1)
/* 0E1FDC 7F0AD4AC 26100008 */  addiu $s0, $s0, 8
/* 0E1FE0 7F0AD4B0 ACA00004 */  sw    $zero, 4($a1)
/* 0E1FE4 7F0AD4B4 3C190703 */  lui   $t9, (0x0703C000 >> 16) # lui $t9, 0x703
/* 0E1FE8 7F0AD4B8 3739C000 */  ori   $t9, (0x0703C000 & 0xFFFF) # ori $t9, $t9, 0xc000
/* 0E1FEC 7F0AD4BC 02004025 */  move  $t0, $s0
/* 0E1FF0 7F0AD4C0 3C18F000 */  lui   $t8, 0xf000
/* 0E1FF4 7F0AD4C4 ACD80000 */  sw    $t8, ($a2)
/* 0E1FF8 7F0AD4C8 ACD90004 */  sw    $t9, 4($a2)
/* 0E1FFC 7F0AD4CC 26100008 */  addiu $s0, $s0, 8
/* 0E2000 7F0AD4D0 3C0CE700 */  lui   $t4, 0xe700
/* 0E2004 7F0AD4D4 AD0C0000 */  sw    $t4, ($t0)
/* 0E2008 7F0AD4D8 AD000004 */  sw    $zero, 4($t0)
/* 0E200C 7F0AD4DC 02003825 */  move  $a3, $s0
/* 0E2010 7F0AD4E0 3C0DFD10 */  lui   $t5, 0xfd10
/* 0E2014 7F0AD4E4 ACED0000 */  sw    $t5, ($a3)
/* 0E2018 7F0AD4E8 3C048004 */  lui   $a0, %hi(D_80040EDC)
/* 0E201C 7F0AD4EC 24840EDC */  addiu $a0, %lo(D_80040EDC) # addiu $a0, $a0, 0xedc
/* 0E2020 7F0AD4F0 AFA7009C */  sw    $a3, 0x9c($sp)
/* 0E2024 7F0AD4F4 26100008 */  addiu $s0, $s0, 8
/* 0E2028 7F0AD4F8 AFA900E0 */  sw    $t1, 0xe0($sp)
/* 0E202C 7F0AD4FC 0C003A2C */  jal   osVirtualToPhysical
/* 0E2030 7F0AD500 AFAB0020 */   sw    $t3, 0x20($sp)
/* 0E2034 7F0AD504 8FA7009C */  lw    $a3, 0x9c($sp)
/* 0E2038 7F0AD508 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0E203C 7F0AD50C 8FAB0020 */  lw    $t3, 0x20($sp)
/* 0E2040 7F0AD510 02001825 */  move  $v1, $s0
/* 0E2044 7F0AD514 26100008 */  addiu $s0, $s0, 8
/* 0E2048 7F0AD518 3C0EE800 */  lui   $t6, 0xe800
/* 0E204C 7F0AD51C ACE20004 */  sw    $v0, 4($a3)
/* 0E2050 7F0AD520 AC6E0000 */  sw    $t6, ($v1)
/* 0E2054 7F0AD524 02002025 */  move  $a0, $s0
/* 0E2058 7F0AD528 26100008 */  addiu $s0, $s0, 8
/* 0E205C 7F0AD52C AC600004 */  sw    $zero, 4($v1)
/* 0E2060 7F0AD530 3C0FF500 */  lui   $t7, (0xF5000110 >> 16) # lui $t7, 0xf500
/* 0E2064 7F0AD534 35EF0110 */  ori   $t7, (0xF5000110 & 0xFFFF) # ori $t7, $t7, 0x110
/* 0E2068 7F0AD538 02002825 */  move  $a1, $s0
/* 0E206C 7F0AD53C 3C180700 */  lui   $t8, 0x700
/* 0E2070 7F0AD540 AC980004 */  sw    $t8, 4($a0)
/* 0E2074 7F0AD544 26100008 */  addiu $s0, $s0, 8
/* 0E2078 7F0AD548 AC8F0000 */  sw    $t7, ($a0)
/* 0E207C 7F0AD54C 02003025 */  move  $a2, $s0
/* 0E2080 7F0AD550 3C19E600 */  lui   $t9, 0xe600
/* 0E2084 7F0AD554 ACB90000 */  sw    $t9, ($a1)
/* 0E2088 7F0AD558 26100008 */  addiu $s0, $s0, 8
/* 0E208C 7F0AD55C ACA00004 */  sw    $zero, 4($a1)
/* 0E2090 7F0AD560 3C0D0703 */  lui   $t5, (0x0703C000 >> 16) # lui $t5, 0x703
/* 0E2094 7F0AD564 35ADC000 */  ori   $t5, (0x0703C000 & 0xFFFF) # ori $t5, $t5, 0xc000
/* 0E2098 7F0AD568 02004025 */  move  $t0, $s0
/* 0E209C 7F0AD56C 3C0CF000 */  lui   $t4, 0xf000
/* 0E20A0 7F0AD570 ACCC0000 */  sw    $t4, ($a2)
/* 0E20A4 7F0AD574 ACCD0004 */  sw    $t5, 4($a2)
/* 0E20A8 7F0AD578 3C0EE700 */  lui   $t6, 0xe700
/* 0E20AC 7F0AD57C AD0E0000 */  sw    $t6, ($t0)
/* 0E20B0 7F0AD580 AD000004 */  sw    $zero, 4($t0)
/* 0E20B4 7F0AD584 26100008 */  addiu $s0, $s0, 8
.L7F0AD588:
/* 0E20B8 7F0AD588 02002825 */  move  $a1, $s0
/* 0E20BC 7F0AD58C 3C0FFD50 */  lui   $t7, 0xfd50
/* 0E20C0 7F0AD590 ACAF0000 */  sw    $t7, ($a1)
/* 0E20C4 7F0AD594 8E240014 */  lw    $a0, 0x14($s1)
/* 0E20C8 7F0AD598 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0E20CC 7F0AD59C AFA900E0 */  sw    $t1, 0xe0($sp)
/* 0E20D0 7F0AD5A0 AFA50084 */  sw    $a1, 0x84($sp)
/* 0E20D4 7F0AD5A4 0C003A2C */  jal   osVirtualToPhysical
/* 0E20D8 7F0AD5A8 26100008 */   addiu $s0, $s0, 8
/* 0E20DC 7F0AD5AC 8FA50084 */  lw    $a1, 0x84($sp)
/* 0E20E0 7F0AD5B0 8FA900E0 */  lw    $t1, 0xe0($sp)
/* 0E20E4 7F0AD5B4 8FAA010C */  lw    $t2, 0x10c($sp)
/* 0E20E8 7F0AD5B8 8FAB0020 */  lw    $t3, 0x20($sp)
/* 0E20EC 7F0AD5BC 02001825 */  move  $v1, $s0
/* 0E20F0 7F0AD5C0 26100008 */  addiu $s0, $s0, 8
/* 0E20F4 7F0AD5C4 ACA20004 */  sw    $v0, 4($a1)
/* 0E20F8 7F0AD5C8 3C080700 */  lui   $t0, 0x700
/* 0E20FC 7F0AD5CC 3C18F550 */  lui   $t8, 0xf550
/* 0E2100 7F0AD5D0 02002025 */  move  $a0, $s0
/* 0E2104 7F0AD5D4 AC780000 */  sw    $t8, ($v1)
/* 0E2108 7F0AD5D8 AC680004 */  sw    $t0, 4($v1)
/* 0E210C 7F0AD5DC 26100008 */  addiu $s0, $s0, 8
/* 0E2110 7F0AD5E0 3C19E600 */  lui   $t9, 0xe600
/* 0E2114 7F0AD5E4 AC990000 */  sw    $t9, ($a0)
/* 0E2118 7F0AD5E8 AC800004 */  sw    $zero, 4($a0)
/* 0E211C 7F0AD5EC 02003025 */  move  $a2, $s0
/* 0E2120 7F0AD5F0 3C0CF300 */  lui   $t4, 0xf300
/* 0E2124 7F0AD5F4 ACCC0000 */  sw    $t4, ($a2)
/* 0E2128 7F0AD5F8 8E270008 */  lw    $a3, 8($s1)
/* 0E212C 7F0AD5FC 26100008 */  addiu $s0, $s0, 8
/* 0E2130 7F0AD600 02001025 */  move  $v0, $s0
/* 0E2134 7F0AD604 00076880 */  sll   $t5, $a3, 2
/* 0E2138 7F0AD608 25A7FFFF */  addiu $a3, $t5, -1
/* 0E213C 7F0AD60C 28E107FF */  slti  $at, $a3, 0x7ff
/* 0E2140 7F0AD610 10200003 */  beqz  $at, .L7F0AD620
/* 0E2144 7F0AD614 26100008 */   addiu $s0, $s0, 8
/* 0E2148 7F0AD618 10000002 */  b     .L7F0AD624
/* 0E214C 7F0AD61C 00E02825 */   move  $a1, $a3
.L7F0AD620:
/* 0E2150 7F0AD620 240507FF */  li    $a1, 2047
.L7F0AD624:
/* 0E2154 7F0AD624 30AE0FFF */  andi  $t6, $a1, 0xfff
/* 0E2158 7F0AD628 000E7B00 */  sll   $t7, $t6, 0xc
/* 0E215C 7F0AD62C 01E8C025 */  or    $t8, $t7, $t0
/* 0E2160 7F0AD630 37190800 */  ori   $t9, $t8, 0x800
/* 0E2164 7F0AD634 ACD90004 */  sw    $t9, 4($a2)
/* 0E2168 7F0AD638 3C0CE700 */  lui   $t4, 0xe700
/* 0E216C 7F0AD63C 3C0DF540 */  lui   $t5, (0xF5400200 >> 16) # lui $t5, 0xf540
/* 0E2170 7F0AD640 AC4C0000 */  sw    $t4, ($v0)
/* 0E2174 7F0AD644 AC400004 */  sw    $zero, 4($v0)
/* 0E2178 7F0AD648 35AD0200 */  ori   $t5, (0xF5400200 & 0xFFFF) # ori $t5, $t5, 0x200
/* 0E217C 7F0AD64C 02001825 */  move  $v1, $s0
/* 0E2180 7F0AD650 AC6D0000 */  sw    $t5, ($v1)
/* 0E2184 7F0AD654 8E2F0000 */  lw    $t7, ($s1)
/* 0E2188 7F0AD658 3C010008 */  lui   $at, 8
/* 0E218C 7F0AD65C 26100008 */  addiu $s0, $s0, 8
/* 0E2190 7F0AD660 31F80001 */  andi  $t8, $t7, 1
/* 0E2194 7F0AD664 0018CD00 */  sll   $t9, $t8, 0x14
/* 0E2198 7F0AD668 03216025 */  or    $t4, $t9, $at
/* 0E219C 7F0AD66C 358D0200 */  ori   $t5, $t4, 0x200
/* 0E21A0 7F0AD670 AC6D0004 */  sw    $t5, 4($v1)
/* 0E21A4 7F0AD674 02002025 */  move  $a0, $s0
/* 0E21A8 7F0AD678 3C0EF200 */  lui   $t6, 0xf200
/* 0E21AC 7F0AD67C AC8E0000 */  sw    $t6, ($a0)
/* 0E21B0 7F0AD680 8E2F0008 */  lw    $t7, 8($s1)
/* 0E21B4 7F0AD684 3C010003 */  lui   $at, (0x0003C000 >> 16) # lui $at, 3
/* 0E21B8 7F0AD688 3421C000 */  ori   $at, (0x0003C000 & 0xFFFF) # ori $at, $at, 0xc000
/* 0E21BC 7F0AD68C 25F8FFFF */  addiu $t8, $t7, -1
/* 0E21C0 7F0AD690 0018C880 */  sll   $t9, $t8, 2
/* 0E21C4 7F0AD694 332C0FFF */  andi  $t4, $t9, 0xfff
/* 0E21C8 7F0AD698 01816825 */  or    $t5, $t4, $at
/* 0E21CC 7F0AD69C AC8D0004 */  sw    $t5, 4($a0)
/* 0E21D0 7F0AD6A0 26100008 */  addiu $s0, $s0, 8
.L7F0AD6A4:
/* 0E21D4 7F0AD6A4 8FAE00F4 */  lw    $t6, 0xf4($sp)
/* 0E21D8 7F0AD6A8 8E38000C */  lw    $t8, 0xc($s1)
/* 0E21DC 7F0AD6AC 8FB90024 */  lw    $t9, 0x24($sp)
/* 0E21E0 7F0AD6B0 8DCF0000 */  lw    $t7, ($t6)
/* 0E21E4 7F0AD6B4 01F84021 */  addu  $t0, $t7, $t8
/* 0E21E8 7F0AD6B8 0328082A */  slt   $at, $t9, $t0
/* 0E21EC 7F0AD6BC 542000F5 */  bnezl $at, .L7F0ADA94
/* 0E21F0 7F0AD6C0 8FAC00F4 */   lw    $t4, 0xf4($sp)
/* 0E21F4 7F0AD6C4 8E240004 */  lw    $a0, 4($s1)
/* 0E21F8 7F0AD6C8 00891821 */  addu  $v1, $a0, $t1
/* 0E21FC 7F0AD6CC 006A082A */  slt   $at, $v1, $t2
/* 0E2200 7F0AD6D0 542000B4 */  bnezl $at, .L7F0AD9A4
/* 0E2204 7F0AD6D4 8E2E0008 */   lw    $t6, 8($s1)
/* 0E2208 7F0AD6D8 8E2C0008 */  lw    $t4, 8($s1)
/* 0E220C 7F0AD6DC 3C0D8004 */  lui   $t5, %hi(text_orientation) 
/* 0E2210 7F0AD6E0 006C1021 */  addu  $v0, $v1, $t4
/* 0E2214 7F0AD6E4 0162082A */  slt   $at, $t3, $v0
/* 0E2218 7F0AD6E8 54200077 */  bnezl $at, .L7F0AD8C8
/* 0E221C 7F0AD6EC 0163082A */   slt   $at, $t3, $v1
/* 0E2220 7F0AD6F0 8DAD0E88 */  lw    $t5, %lo(text_orientation)($t5)
/* 0E2224 7F0AD6F4 3C068004 */  lui   $a2, %hi(text_x)
/* 0E2228 7F0AD6F8 24C60E98 */  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
/* 0E222C 7F0AD6FC 11A0003E */  beqz  $t5, .L7F0AD7F8
/* 0E2230 7F0AD700 3C078004 */   lui   $a3, %hi(text_y)
/* 0E2234 7F0AD704 3C068004 */  lui   $a2, %hi(text_x)
/* 0E2238 7F0AD708 24C60E98 */  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
/* 0E223C 7F0AD70C 8CCF0000 */  lw    $t7, ($a2)
/* 0E2240 7F0AD710 3C078004 */  lui   $a3, %hi(text_y)
/* 0E2244 7F0AD714 00087080 */  sll   $t6, $t0, 2
/* 0E2248 7F0AD718 24E70E9C */  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
/* 0E224C 7F0AD71C 01CFC021 */  addu  $t8, $t6, $t7
/* 0E2250 7F0AD720 8CEF0000 */  lw    $t7, ($a3)
/* 0E2254 7F0AD724 33190FFF */  andi  $t9, $t8, 0xfff
/* 0E2258 7F0AD728 01246823 */  subu  $t5, $t1, $a0
/* 0E225C 7F0AD72C 000D7080 */  sll   $t6, $t5, 2
/* 0E2260 7F0AD730 3C01E500 */  lui   $at, 0xe500
/* 0E2264 7F0AD734 03216025 */  or    $t4, $t9, $at
/* 0E2268 7F0AD738 01CFC021 */  addu  $t8, $t6, $t7
/* 0E226C 7F0AD73C 33190FFF */  andi  $t9, $t8, 0xfff
/* 0E2270 7F0AD740 00196B00 */  sll   $t5, $t9, 0xc
/* 0E2274 7F0AD744 018D7025 */  or    $t6, $t4, $t5
/* 0E2278 7F0AD748 02001025 */  move  $v0, $s0
/* 0E227C 7F0AD74C AC4E0000 */  sw    $t6, ($v0)
/* 0E2280 7F0AD750 8FAF00F4 */  lw    $t7, 0xf4($sp)
/* 0E2284 7F0AD754 8CCC0000 */  lw    $t4, ($a2)
/* 0E2288 7F0AD758 26100008 */  addiu $s0, $s0, 8
/* 0E228C 7F0AD75C 8DF80000 */  lw    $t8, ($t7)
/* 0E2290 7F0AD760 8E2F0004 */  lw    $t7, 4($s1)
/* 0E2294 7F0AD764 02001825 */  move  $v1, $s0
/* 0E2298 7F0AD768 0018C880 */  sll   $t9, $t8, 2
/* 0E229C 7F0AD76C 032C6821 */  addu  $t5, $t9, $t4
/* 0E22A0 7F0AD770 8E390008 */  lw    $t9, 8($s1)
/* 0E22A4 7F0AD774 012FC023 */  subu  $t8, $t1, $t7
/* 0E22A8 7F0AD778 8CEF0000 */  lw    $t7, ($a3)
/* 0E22AC 7F0AD77C 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 0E22B0 7F0AD780 03196023 */  subu  $t4, $t8, $t9
/* 0E22B4 7F0AD784 000C6880 */  sll   $t5, $t4, 2
/* 0E22B8 7F0AD788 01AFC021 */  addu  $t8, $t5, $t7
/* 0E22BC 7F0AD78C 33190FFF */  andi  $t9, $t8, 0xfff
/* 0E22C0 7F0AD790 00196300 */  sll   $t4, $t9, 0xc
/* 0E22C4 7F0AD794 01CC6825 */  or    $t5, $t6, $t4
/* 0E22C8 7F0AD798 AC4D0004 */  sw    $t5, 4($v0)
/* 0E22CC 7F0AD79C 3C0FB400 */  lui   $t7, 0xb400
/* 0E22D0 7F0AD7A0 AC6F0000 */  sw    $t7, ($v1)
/* 0E22D4 7F0AD7A4 8E380008 */  lw    $t8, 8($s1)
/* 0E22D8 7F0AD7A8 3C0C8004 */  lui   $t4, %hi(text_s) 
/* 0E22DC 7F0AD7AC 8D8C0EA0 */  lw    $t4, %lo(text_s)($t4)
/* 0E22E0 7F0AD7B0 2719FFFF */  addiu $t9, $t8, -1
/* 0E22E4 7F0AD7B4 00197140 */  sll   $t6, $t9, 5
/* 0E22E8 7F0AD7B8 3C188004 */  lui   $t8, %hi(text_t) 
/* 0E22EC 7F0AD7BC 8F190EA4 */  lw    $t9, %lo(text_t)($t8)
/* 0E22F0 7F0AD7C0 01CC6821 */  addu  $t5, $t6, $t4
/* 0E22F4 7F0AD7C4 31AFFFFF */  andi  $t7, $t5, 0xffff
/* 0E22F8 7F0AD7C8 26100008 */  addiu $s0, $s0, 8
/* 0E22FC 7F0AD7CC 00197400 */  sll   $t6, $t9, 0x10
/* 0E2300 7F0AD7D0 01CF6025 */  or    $t4, $t6, $t7
/* 0E2304 7F0AD7D4 02002825 */  move  $a1, $s0
/* 0E2308 7F0AD7D8 3C180400 */  lui   $t8, (0x0400FC00 >> 16) # lui $t8, 0x400
/* 0E230C 7F0AD7DC 3718FC00 */  ori   $t8, (0x0400FC00 & 0xFFFF) # ori $t8, $t8, 0xfc00
/* 0E2310 7F0AD7E0 AC6C0004 */  sw    $t4, 4($v1)
/* 0E2314 7F0AD7E4 3C0DB300 */  lui   $t5, 0xb300
/* 0E2318 7F0AD7E8 ACAD0000 */  sw    $t5, ($a1)
/* 0E231C 7F0AD7EC ACB80004 */  sw    $t8, 4($a1)
/* 0E2320 7F0AD7F0 100000A7 */  b     .L7F0ADA90
/* 0E2324 7F0AD7F4 26100008 */   addiu $s0, $s0, 8
.L7F0AD7F8:
/* 0E2328 7F0AD7F8 8CCE0000 */  lw    $t6, ($a2)
/* 0E232C 7F0AD7FC 0008C880 */  sll   $t9, $t0, 2
/* 0E2330 7F0AD800 24E70E9C */  addiu $a3, $a3, %lo(text_y)
/* 0E2334 7F0AD804 032E7821 */  addu  $t7, $t9, $t6
/* 0E2338 7F0AD808 8CEE0000 */  lw    $t6, ($a3)
/* 0E233C 7F0AD80C 31EC0FFF */  andi  $t4, $t7, 0xfff
/* 0E2340 7F0AD810 000C6B00 */  sll   $t5, $t4, 0xc
/* 0E2344 7F0AD814 0002C880 */  sll   $t9, $v0, 2
/* 0E2348 7F0AD818 3C01E400 */  lui   $at, 0xe400
/* 0E234C 7F0AD81C 032E7821 */  addu  $t7, $t9, $t6
/* 0E2350 7F0AD820 31EC0FFF */  andi  $t4, $t7, 0xfff
/* 0E2354 7F0AD824 01A1C025 */  or    $t8, $t5, $at
/* 0E2358 7F0AD828 030C6825 */  or    $t5, $t8, $t4
/* 0E235C 7F0AD82C 02001825 */  move  $v1, $s0
/* 0E2360 7F0AD830 AC6D0000 */  sw    $t5, ($v1)
/* 0E2364 7F0AD834 8FB900F4 */  lw    $t9, 0xf4($sp)
/* 0E2368 7F0AD838 8CD80000 */  lw    $t8, ($a2)
/* 0E236C 7F0AD83C 26100008 */  addiu $s0, $s0, 8
/* 0E2370 7F0AD840 8F2E0000 */  lw    $t6, ($t9)
/* 0E2374 7F0AD844 02002025 */  move  $a0, $s0
/* 0E2378 7F0AD848 26100008 */  addiu $s0, $s0, 8
/* 0E237C 7F0AD84C 000E7880 */  sll   $t7, $t6, 2
/* 0E2380 7F0AD850 8E2E0004 */  lw    $t6, 4($s1)
/* 0E2384 7F0AD854 01F86021 */  addu  $t4, $t7, $t8
/* 0E2388 7F0AD858 318D0FFF */  andi  $t5, $t4, 0xfff
/* 0E238C 7F0AD85C 8CEC0000 */  lw    $t4, ($a3)
/* 0E2390 7F0AD860 012E7821 */  addu  $t7, $t1, $t6
/* 0E2394 7F0AD864 000FC080 */  sll   $t8, $t7, 2
/* 0E2398 7F0AD868 000DCB00 */  sll   $t9, $t5, 0xc
/* 0E239C 7F0AD86C 030C6821 */  addu  $t5, $t8, $t4
/* 0E23A0 7F0AD870 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 0E23A4 7F0AD874 032E7825 */  or    $t7, $t9, $t6
/* 0E23A8 7F0AD878 AC6F0004 */  sw    $t7, 4($v1)
/* 0E23AC 7F0AD87C 3C18B400 */  lui   $t8, 0xb400
/* 0E23B0 7F0AD880 AC980000 */  sw    $t8, ($a0)
/* 0E23B4 7F0AD884 3C0C8004 */  lui   $t4, %hi(text_s) 
/* 0E23B8 7F0AD888 8D8D0EA0 */  lw    $t5, %lo(text_s)($t4)
/* 0E23BC 7F0AD88C 3C0E8004 */  lui   $t6, %hi(text_t) 
/* 0E23C0 7F0AD890 8DCE0EA4 */  lw    $t6, %lo(text_t)($t6)
/* 0E23C4 7F0AD894 000DCC00 */  sll   $t9, $t5, 0x10
/* 0E23C8 7F0AD898 3C0D0400 */  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
/* 0E23CC 7F0AD89C 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 0E23D0 7F0AD8A0 032FC025 */  or    $t8, $t9, $t7
/* 0E23D4 7F0AD8A4 02002825 */  move  $a1, $s0
/* 0E23D8 7F0AD8A8 AC980004 */  sw    $t8, 4($a0)
/* 0E23DC 7F0AD8AC 35AD0400 */  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
/* 0E23E0 7F0AD8B0 3C0CB300 */  lui   $t4, 0xb300
/* 0E23E4 7F0AD8B4 ACAC0000 */  sw    $t4, ($a1)
/* 0E23E8 7F0AD8B8 ACAD0004 */  sw    $t5, 4($a1)
/* 0E23EC 7F0AD8BC 10000074 */  b     .L7F0ADA90
/* 0E23F0 7F0AD8C0 26100008 */   addiu $s0, $s0, 8
/* 0E23F4 7F0AD8C4 0163082A */  slt   $at, $t3, $v1
.L7F0AD8C8:
/* 0E23F8 7F0AD8C8 14200071 */  bnez  $at, .L7F0ADA90
/* 0E23FC 7F0AD8CC 3C068004 */   lui   $a2, %hi(text_x)
/* 0E2400 7F0AD8D0 24C60E98 */  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
/* 0E2404 7F0AD8D4 8CD90000 */  lw    $t9, ($a2)
/* 0E2408 7F0AD8D8 3C078004 */  lui   $a3, %hi(text_y)
/* 0E240C 7F0AD8DC 00087080 */  sll   $t6, $t0, 2
/* 0E2410 7F0AD8E0 24E70E9C */  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
/* 0E2414 7F0AD8E4 01D97821 */  addu  $t7, $t6, $t9
/* 0E2418 7F0AD8E8 8CEE0000 */  lw    $t6, ($a3)
/* 0E241C 7F0AD8EC 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0E2420 7F0AD8F0 00186300 */  sll   $t4, $t8, 0xc
/* 0E2424 7F0AD8F4 3C01E400 */  lui   $at, 0xe400
/* 0E2428 7F0AD8F8 016EC821 */  addu  $t9, $t3, $t6
/* 0E242C 7F0AD8FC 332F0FFF */  andi  $t7, $t9, 0xfff
/* 0E2430 7F0AD900 01816825 */  or    $t5, $t4, $at
/* 0E2434 7F0AD904 01AFC025 */  or    $t8, $t5, $t7
/* 0E2438 7F0AD908 02001025 */  move  $v0, $s0
/* 0E243C 7F0AD90C AC580000 */  sw    $t8, ($v0)
/* 0E2440 7F0AD910 8FAC00F4 */  lw    $t4, 0xf4($sp)
/* 0E2444 7F0AD914 8CCD0000 */  lw    $t5, ($a2)
/* 0E2448 7F0AD918 26100008 */  addiu $s0, $s0, 8
/* 0E244C 7F0AD91C 8D8E0000 */  lw    $t6, ($t4)
/* 0E2450 7F0AD920 02001825 */  move  $v1, $s0
/* 0E2454 7F0AD924 26100008 */  addiu $s0, $s0, 8
/* 0E2458 7F0AD928 000EC880 */  sll   $t9, $t6, 2
/* 0E245C 7F0AD92C 8E2E0004 */  lw    $t6, 4($s1)
/* 0E2460 7F0AD930 032D7821 */  addu  $t7, $t9, $t5
/* 0E2464 7F0AD934 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0E2468 7F0AD938 8CEF0000 */  lw    $t7, ($a3)
/* 0E246C 7F0AD93C 012EC821 */  addu  $t9, $t1, $t6
/* 0E2470 7F0AD940 00196880 */  sll   $t5, $t9, 2
/* 0E2474 7F0AD944 00186300 */  sll   $t4, $t8, 0xc
/* 0E2478 7F0AD948 01AFC021 */  addu  $t8, $t5, $t7
/* 0E247C 7F0AD94C 330E0FFF */  andi  $t6, $t8, 0xfff
/* 0E2480 7F0AD950 018EC825 */  or    $t9, $t4, $t6
/* 0E2484 7F0AD954 AC590004 */  sw    $t9, 4($v0)
/* 0E2488 7F0AD958 3C0DB400 */  lui   $t5, 0xb400
/* 0E248C 7F0AD95C AC6D0000 */  sw    $t5, ($v1)
/* 0E2490 7F0AD960 3C0F8004 */  lui   $t7, %hi(text_s) 
/* 0E2494 7F0AD964 8DF80EA0 */  lw    $t8, %lo(text_s)($t7)
/* 0E2498 7F0AD968 3C0E8004 */  lui   $t6, %hi(text_t) 
/* 0E249C 7F0AD96C 8DCE0EA4 */  lw    $t6, %lo(text_t)($t6)
/* 0E24A0 7F0AD970 00186400 */  sll   $t4, $t8, 0x10
/* 0E24A4 7F0AD974 3C180400 */  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
/* 0E24A8 7F0AD978 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 0E24AC 7F0AD97C 01996825 */  or    $t5, $t4, $t9
/* 0E24B0 7F0AD980 02002025 */  move  $a0, $s0
/* 0E24B4 7F0AD984 AC6D0004 */  sw    $t5, 4($v1)
/* 0E24B8 7F0AD988 37180400 */  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
/* 0E24BC 7F0AD98C 3C0FB300 */  lui   $t7, 0xb300
/* 0E24C0 7F0AD990 AC8F0000 */  sw    $t7, ($a0)
/* 0E24C4 7F0AD994 AC980004 */  sw    $t8, 4($a0)
/* 0E24C8 7F0AD998 1000003D */  b     .L7F0ADA90
/* 0E24CC 7F0AD99C 26100008 */   addiu $s0, $s0, 8
/* 0E24D0 7F0AD9A0 8E2E0008 */  lw    $t6, 8($s1)
.L7F0AD9A4:
/* 0E24D4 7F0AD9A4 3C068004 */  lui   $a2, %hi(text_x)
/* 0E24D8 7F0AD9A8 24C60E98 */  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
/* 0E24DC 7F0AD9AC 006E1021 */  addu  $v0, $v1, $t6
/* 0E24E0 7F0AD9B0 004A082A */  slt   $at, $v0, $t2
/* 0E24E4 7F0AD9B4 14200036 */  bnez  $at, .L7F0ADA90
/* 0E24E8 7F0AD9B8 3C078004 */   lui   $a3, %hi(text_y)
/* 0E24EC 7F0AD9BC 8CD90000 */  lw    $t9, ($a2)
/* 0E24F0 7F0AD9C0 00086080 */  sll   $t4, $t0, 2
/* 0E24F4 7F0AD9C4 24E70E9C */  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
/* 0E24F8 7F0AD9C8 01996821 */  addu  $t5, $t4, $t9
/* 0E24FC 7F0AD9CC 8CF90000 */  lw    $t9, ($a3)
/* 0E2500 7F0AD9D0 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E2504 7F0AD9D4 000FC300 */  sll   $t8, $t7, 0xc
/* 0E2508 7F0AD9D8 00026080 */  sll   $t4, $v0, 2
/* 0E250C 7F0AD9DC 3C01E400 */  lui   $at, 0xe400
/* 0E2510 7F0AD9E0 01996821 */  addu  $t5, $t4, $t9
/* 0E2514 7F0AD9E4 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E2518 7F0AD9E8 03017025 */  or    $t6, $t8, $at
/* 0E251C 7F0AD9EC 01CFC025 */  or    $t8, $t6, $t7
/* 0E2520 7F0AD9F0 02001825 */  move  $v1, $s0
/* 0E2524 7F0AD9F4 AC780000 */  sw    $t8, ($v1)
/* 0E2528 7F0AD9F8 8FAC00F4 */  lw    $t4, 0xf4($sp)
/* 0E252C 7F0AD9FC 8CCE0000 */  lw    $t6, ($a2)
/* 0E2530 7F0ADA00 26100008 */  addiu $s0, $s0, 8
/* 0E2534 7F0ADA04 8D990000 */  lw    $t9, ($t4)
/* 0E2538 7F0ADA08 02002025 */  move  $a0, $s0
/* 0E253C 7F0ADA0C 26100008 */  addiu $s0, $s0, 8
/* 0E2540 7F0ADA10 00196880 */  sll   $t5, $t9, 2
/* 0E2544 7F0ADA14 01AE7821 */  addu  $t7, $t5, $t6
/* 0E2548 7F0ADA18 8CED0000 */  lw    $t5, ($a3)
/* 0E254C 7F0ADA1C 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0E2550 7F0ADA20 000AC880 */  sll   $t9, $t2, 2
/* 0E2554 7F0ADA24 032D7021 */  addu  $t6, $t9, $t5
/* 0E2558 7F0ADA28 31CF0FFF */  andi  $t7, $t6, 0xfff
/* 0E255C 7F0ADA2C 00186300 */  sll   $t4, $t8, 0xc
/* 0E2560 7F0ADA30 018FC025 */  or    $t8, $t4, $t7
/* 0E2564 7F0ADA34 AC780004 */  sw    $t8, 4($v1)
/* 0E2568 7F0ADA38 3C19B400 */  lui   $t9, 0xb400
/* 0E256C 7F0ADA3C AC990000 */  sw    $t9, ($a0)
/* 0E2570 7F0ADA40 8E2E0004 */  lw    $t6, 4($s1)
/* 0E2574 7F0ADA44 01496823 */  subu  $t5, $t2, $t1
/* 0E2578 7F0ADA48 3C188004 */  lui   $t8, %hi(text_t) 
/* 0E257C 7F0ADA4C 01AE6023 */  subu  $t4, $t5, $t6
/* 0E2580 7F0ADA50 8F180EA4 */  lw    $t8, %lo(text_t)($t8)
/* 0E2584 7F0ADA54 000C7940 */  sll   $t7, $t4, 5
/* 0E2588 7F0ADA58 3C0E8004 */  lui   $t6, %hi(text_s) 
/* 0E258C 7F0ADA5C 8DCC0EA0 */  lw    $t4, %lo(text_s)($t6)
/* 0E2590 7F0ADA60 01F8C821 */  addu  $t9, $t7, $t8
/* 0E2594 7F0ADA64 332DFFFF */  andi  $t5, $t9, 0xffff
/* 0E2598 7F0ADA68 000C7C00 */  sll   $t7, $t4, 0x10
/* 0E259C 7F0ADA6C 01EDC025 */  or    $t8, $t7, $t5
/* 0E25A0 7F0ADA70 02002825 */  move  $a1, $s0
/* 0E25A4 7F0ADA74 AC980004 */  sw    $t8, 4($a0)
/* 0E25A8 7F0ADA78 3C0E0400 */  lui   $t6, (0x04000400 >> 16) # lui $t6, 0x400
/* 0E25AC 7F0ADA7C 35CE0400 */  ori   $t6, (0x04000400 & 0xFFFF) # ori $t6, $t6, 0x400
/* 0E25B0 7F0ADA80 3C19B300 */  lui   $t9, 0xb300
/* 0E25B4 7F0ADA84 ACB90000 */  sw    $t9, ($a1)
/* 0E25B8 7F0ADA88 ACAE0004 */  sw    $t6, 4($a1)
/* 0E25BC 7F0ADA8C 26100008 */  addiu $s0, $s0, 8
.L7F0ADA90:
/* 0E25C0 7F0ADA90 8FAC00F4 */  lw    $t4, 0xf4($sp)
.L7F0ADA94:
/* 0E25C4 7F0ADA94 8E2D000C */  lw    $t5, 0xc($s1)
/* 0E25C8 7F0ADA98 02001025 */  move  $v0, $s0
/* 0E25CC 7F0ADA9C 8D8F0000 */  lw    $t7, ($t4)
/* 0E25D0 7F0ADAA0 01EDC021 */  addu  $t8, $t7, $t5
/* 0E25D4 7F0ADAA4 AD980000 */  sw    $t8, ($t4)
/* 0E25D8 7F0ADAA8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E25DC 7F0ADAAC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0E25E0 7F0ADAB0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0E25E4 7F0ADAB4 03E00008 */  jr    $ra
/* 0E25E8 7F0ADAB8 27BD00F0 */   addiu $sp, $sp, 0xf0
)
#endif





#ifdef NONMATCHING
void en_text_write_stuff(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel en_text_write_stuff
/* 0E25EC 7F0ADABC 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 0E25F0 7F0ADAC0 240E0001 */  li    $t6, 1
/* 0E25F4 7F0ADAC4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E25F8 7F0ADAC8 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0E25FC 7F0ADACC AFBF005C */  sw    $ra, 0x5c($sp)
/* 0E2600 7F0ADAD0 AFBE0058 */  sw    $fp, 0x58($sp)
/* 0E2604 7F0ADAD4 AFB70054 */  sw    $s7, 0x54($sp)
/* 0E2608 7F0ADAD8 AFB60050 */  sw    $s6, 0x50($sp)
/* 0E260C 7F0ADADC AFB5004C */  sw    $s5, 0x4c($sp)
/* 0E2610 7F0ADAE0 AFB40048 */  sw    $s4, 0x48($sp)
/* 0E2614 7F0ADAE4 AFB30044 */  sw    $s3, 0x44($sp)
/* 0E2618 7F0ADAE8 AFB20040 */  sw    $s2, 0x40($sp)
/* 0E261C 7F0ADAEC AFB1003C */  sw    $s1, 0x3c($sp)
/* 0E2620 7F0ADAF0 AFB00038 */  sw    $s0, 0x38($sp)
/* 0E2624 7F0ADAF4 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E2628 7F0ADAF8 8CCF0000 */  lw    $t7, ($a2)
/* 0E262C 7F0ADAFC 8CB40000 */  lw    $s4, ($a1)
/* 0E2630 7F0ADB00 00E08025 */  move  $s0, $a3
/* 0E2634 7F0ADB04 00A08825 */  move  $s1, $a1
/* 0E2638 7F0ADB08 00C09025 */  move  $s2, $a2
/* 0E263C 7F0ADB0C 00809825 */  move  $s3, $a0
/* 0E2640 7F0ADB10 24150048 */  li    $s5, 72
/* 0E2644 7F0ADB14 17000006 */  bnez  $t8, .L7F0ADB30
/* 0E2648 7F0ADB18 AFAF00A0 */   sw    $t7, 0xa0($sp)
/* 0E264C 7F0ADB1C 8FB900B8 */  lw    $t9, 0xb8($sp)
/* 0E2650 7F0ADB20 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E2654 7F0ADB24 8F290890 */  lw    $t1, 0x890($t9)
/* 0E2658 7F0ADB28 01095021 */  addu  $t2, $t0, $t1
/* 0E265C 7F0ADB2C AFAA00D0 */  sw    $t2, 0xd0($sp)
.L7F0ADB30:
/* 0E2660 7F0ADB30 3C0B8005 */  lui   $t3, %hi(j_text_trigger) 
/* 0E2664 7F0ADB34 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E2668 7F0ADB38 8FAC00D0 */  lw    $t4, 0xd0($sp)
/* 0E266C 7F0ADB3C 02602025 */  move  $a0, $s3
/* 0E2670 7F0ADB40 11600004 */  beqz  $t3, .L7F0ADB54
/* 0E2674 7F0ADB44 2981000E */   slti  $at, $t4, 0xe
/* 0E2678 7F0ADB48 10200002 */  beqz  $at, .L7F0ADB54
/* 0E267C 7F0ADB4C 240D000E */   li    $t5, 14
/* 0E2680 7F0ADB50 AFAD00D0 */  sw    $t5, 0xd0($sp)
.L7F0ADB54:
/* 0E2684 7F0ADB54 8FA300C0 */  lw    $v1, 0xc0($sp)
/* 0E2688 7F0ADB58 3C0EFA00 */  lui   $t6, 0xfa00
/* 0E268C 7F0ADB5C AC8E0000 */  sw    $t6, ($a0)
/* 0E2690 7F0ADB60 0003CE02 */  srl   $t9, $v1, 0x18
/* 0E2694 7F0ADB64 00035402 */  srl   $t2, $v1, 0x10
/* 0E2698 7F0ADB68 314B00FF */  andi  $t3, $t2, 0xff
/* 0E269C 7F0ADB6C 00194600 */  sll   $t0, $t9, 0x18
/* 0E26A0 7F0ADB70 00037A02 */  srl   $t7, $v1, 8
/* 0E26A4 7F0ADB74 31F800FF */  andi  $t8, $t7, 0xff
/* 0E26A8 7F0ADB78 000B6400 */  sll   $t4, $t3, 0x10
/* 0E26AC 7F0ADB7C 010C6825 */  or    $t5, $t0, $t4
/* 0E26B0 7F0ADB80 0018CA00 */  sll   $t9, $t8, 8
/* 0E26B4 7F0ADB84 01B94825 */  or    $t1, $t5, $t9
/* 0E26B8 7F0ADB88 306B00FF */  andi  $t3, $v1, 0xff
/* 0E26BC 7F0ADB8C 012B4025 */  or    $t0, $t1, $t3
/* 0E26C0 7F0ADB90 AC880004 */  sw    $t0, 4($a0)
/* 0E26C4 7F0ADB94 92020000 */  lbu   $v0, ($s0)
/* 0E26C8 7F0ADB98 26730008 */  addiu $s3, $s3, 8
/* 0E26CC 7F0ADB9C 8FB700BC */  lw    $s7, 0xbc($sp)
/* 0E26D0 7F0ADBA0 10400075 */  beqz  $v0, .L7F0ADD78
/* 0E26D4 7F0ADBA4 8FBE00C4 */   lw    $fp, 0xc4($sp)
/* 0E26D8 7F0ADBA8 27B6006C */  addiu $s6, $sp, 0x6c
/* 0E26DC 7F0ADBAC 24010020 */  li    $at, 32
.L7F0ADBB0:
/* 0E26E0 7F0ADBB0 54410008 */  bnel  $v0, $at, .L7F0ADBD4
/* 0E26E4 7F0ADBB4 2401000A */   li    $at, 10
/* 0E26E8 7F0ADBB8 8E2C0000 */  lw    $t4, ($s1)
/* 0E26EC 7F0ADBBC 24150048 */  li    $s5, 72
/* 0E26F0 7F0ADBC0 26100001 */  addiu $s0, $s0, 1
/* 0E26F4 7F0ADBC4 258E0005 */  addiu $t6, $t4, 5
/* 0E26F8 7F0ADBC8 10000068 */  b     .L7F0ADD6C
/* 0E26FC 7F0ADBCC AE2E0000 */   sw    $t6, ($s1)
/* 0E2700 7F0ADBD0 2401000A */  li    $at, 10
.L7F0ADBD4:
/* 0E2704 7F0ADBD4 54410014 */  bnel  $v0, $at, .L7F0ADC28
/* 0E2708 7F0ADBD8 28410080 */   slti  $at, $v0, 0x80
/* 0E270C 7F0ADBDC 3C028004 */  lui   $v0, %hi(overlap_correction)
/* 0E2710 7F0ADBE0 8C420E90 */  lw    $v0, %lo(overlap_correction)($v0)
/* 0E2714 7F0ADBE4 24150048 */  li    $s5, 72
/* 0E2718 7F0ADBE8 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 0E271C 7F0ADBEC 04400008 */  bltz  $v0, .L7F0ADC10
/* 0E2720 7F0ADBF0 26100001 */   addiu $s0, $s0, 1
/* 0E2724 7F0ADBF4 8E2F0000 */  lw    $t7, ($s1)
/* 0E2728 7F0ADBF8 568F0006 */  bnel  $s4, $t7, .L7F0ADC14
/* 0E272C 7F0ADBFC 8E590000 */   lw    $t9, ($s2)
/* 0E2730 7F0ADC00 8E580000 */  lw    $t8, ($s2)
/* 0E2734 7F0ADC04 03026821 */  addu  $t5, $t8, $v0
/* 0E2738 7F0ADC08 10000004 */  b     .L7F0ADC1C
/* 0E273C 7F0ADC0C AE4D0000 */   sw    $t5, ($s2)
.L7F0ADC10:
/* 0E2740 7F0ADC10 8E590000 */  lw    $t9, ($s2)
.L7F0ADC14:
/* 0E2744 7F0ADC14 032A4821 */  addu  $t1, $t9, $t2
/* 0E2748 7F0ADC18 AE490000 */  sw    $t1, ($s2)
.L7F0ADC1C:
/* 0E274C 7F0ADC1C 10000053 */  b     .L7F0ADD6C
/* 0E2750 7F0ADC20 AE340000 */   sw    $s4, ($s1)
/* 0E2754 7F0ADC24 28410080 */  slti  $at, $v0, 0x80
.L7F0ADC28:
/* 0E2758 7F0ADC28 1020001D */  beqz  $at, .L7F0ADCA0
/* 0E275C 7F0ADC2C 3C0E8004 */   lui   $t6, %hi(D_80040EFC)
/* 0E2760 7F0ADC30 24030018 */  li    $v1, 24
/* 0E2764 7F0ADC34 00430019 */  multu $v0, $v1
/* 0E2768 7F0ADC38 8FA800B8 */  lw    $t0, 0xb8($sp)
/* 0E276C 7F0ADC3C 8FB800A0 */  lw    $t8, 0xa0($sp)
/* 0E2770 7F0ADC40 8FAD00C8 */  lw    $t5, 0xc8($sp)
/* 0E2774 7F0ADC44 8FB900CC */  lw    $t9, 0xcc($sp)
/* 0E2778 7F0ADC48 02602025 */  move  $a0, $s3
/* 0E277C 7F0ADC4C 02202825 */  move  $a1, $s1
/* 0E2780 7F0ADC50 02403025 */  move  $a2, $s2
/* 0E2784 7F0ADC54 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E2788 7F0ADC58 AFB40018 */  sw    $s4, 0x18($sp)
/* 0E278C 7F0ADC5C 00005812 */  mflo  $t3
/* 0E2790 7F0ADC60 01683821 */  addu  $a3, $t3, $t0
/* 0E2794 7F0ADC64 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E2798 7F0ADC68 02A30019 */  multu $s5, $v1
/* 0E279C 7F0ADC6C AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E27A0 7F0ADC70 AFB8001C */  sw    $t8, 0x1c($sp)
/* 0E27A4 7F0ADC74 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E27A8 7F0ADC78 AFB90028 */  sw    $t9, 0x28($sp)
/* 0E27AC 7F0ADC7C 00006012 */  mflo  $t4
/* 0E27B0 7F0ADC80 01887021 */  addu  $t6, $t4, $t0
/* 0E27B4 7F0ADC84 25CFFCE8 */  addiu $t7, $t6, -0x318
/* 0E27B8 7F0ADC88 0FC2B43E */  jal   sub_GAME_7F0AD0F8
/* 0E27BC 7F0ADC8C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0E27C0 7F0ADC90 00409825 */  move  $s3, $v0
/* 0E27C4 7F0ADC94 92150000 */  lbu   $s5, ($s0)
/* 0E27C8 7F0ADC98 10000034 */  b     .L7F0ADD6C
/* 0E27CC 7F0ADC9C 26100001 */   addiu $s0, $s0, 1
.L7F0ADCA0:
/* 0E27D0 7F0ADCA0 25CE0EFC */  addiu $t6, $t6, %lo(D_80040EFC)
/* 0E27D4 7F0ADCA4 8DC10000 */  lw    $at, ($t6)
/* 0E27D8 7F0ADCA8 920A0001 */  lbu   $t2, 1($s0)
/* 0E27DC 7F0ADCAC 304B007F */  andi  $t3, $v0, 0x7f
/* 0E27E0 7F0ADCB0 AEC10000 */  sw    $at, ($s6)
/* 0E27E4 7F0ADCB4 8DD80004 */  lw    $t8, 4($t6)
/* 0E27E8 7F0ADCB8 000B61C0 */  sll   $t4, $t3, 7
/* 0E27EC 7F0ADCBC 3149007F */  andi  $t1, $t2, 0x7f
/* 0E27F0 7F0ADCC0 AED80004 */  sw    $t8, 4($s6)
/* 0E27F4 7F0ADCC4 8DC10008 */  lw    $at, 8($t6)
/* 0E27F8 7F0ADCC8 012C1825 */  or    $v1, $t1, $t4
/* 0E27FC 7F0ADCCC 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E2800 7F0ADCD0 AEC10008 */  sw    $at, 8($s6)
/* 0E2804 7F0ADCD4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E2808 7F0ADCD8 308D2000 */  andi  $t5, $a0, 0x2000
/* 0E280C 7F0ADCDC 308B1FFF */  andi  $t3, $a0, 0x1fff
/* 0E2810 7F0ADCE0 AED8000C */  sw    $t8, 0xc($s6)
/* 0E2814 7F0ADCE4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E2818 7F0ADCE8 2419000F */  li    $t9, 15
/* 0E281C 7F0ADCEC 240A0010 */  li    $t2, 16
/* 0E2820 7F0ADCF0 AEC10010 */  sw    $at, 0x10($s6)
/* 0E2824 7F0ADCF4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E2828 7F0ADCF8 296103C7 */  slti  $at, $t3, 0x3c7
/* 0E282C 7F0ADCFC 11A00003 */  beqz  $t5, .L7F0ADD0C
/* 0E2830 7F0ADD00 AED80014 */   sw    $t8, 0x14($s6)
/* 0E2834 7F0ADD04 AFB90078 */  sw    $t9, 0x78($sp)
/* 0E2838 7F0ADD08 AFAA0074 */  sw    $t2, 0x74($sp)
.L7F0ADD0C:
/* 0E283C 7F0ADD0C 54200003 */  bnezl $at, .L7F0ADD1C
/* 0E2840 7F0ADD10 24890080 */   addiu $t1, $a0, 0x80
/* 0E2844 7F0ADD14 24040002 */  li    $a0, 2
/* 0E2848 7F0ADD18 24890080 */  addiu $t1, $a0, 0x80
.L7F0ADD1C:
/* 0E284C 7F0ADD1C 0FC3068C */  jal   something_with_LnameX
/* 0E2850 7F0ADD20 AFA9006C */   sw    $t1, 0x6c($sp)
/* 0E2854 7F0ADD24 8FAC00A0 */  lw    $t4, 0xa0($sp)
/* 0E2858 7F0ADD28 8FA800C8 */  lw    $t0, 0xc8($sp)
/* 0E285C 7F0ADD2C 8FAF00CC */  lw    $t7, 0xcc($sp)
/* 0E2860 7F0ADD30 AFA20080 */  sw    $v0, 0x80($sp)
/* 0E2864 7F0ADD34 02602025 */  move  $a0, $s3
/* 0E2868 7F0ADD38 02202825 */  move  $a1, $s1
/* 0E286C 7F0ADD3C 02403025 */  move  $a2, $s2
/* 0E2870 7F0ADD40 02C03825 */  move  $a3, $s6
/* 0E2874 7F0ADD44 AFB60010 */  sw    $s6, 0x10($sp)
/* 0E2878 7F0ADD48 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E287C 7F0ADD4C AFB40018 */  sw    $s4, 0x18($sp)
/* 0E2880 7F0ADD50 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E2884 7F0ADD54 AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E2888 7F0ADD58 AFA80024 */  sw    $t0, 0x24($sp)
/* 0E288C 7F0ADD5C 0FC2B43E */  jal   sub_GAME_7F0AD0F8
/* 0E2890 7F0ADD60 AFAF0028 */   sw    $t7, 0x28($sp)
/* 0E2894 7F0ADD64 00409825 */  move  $s3, $v0
/* 0E2898 7F0ADD68 26100002 */  addiu $s0, $s0, 2
.L7F0ADD6C:
/* 0E289C 7F0ADD6C 92020000 */  lbu   $v0, ($s0)
/* 0E28A0 7F0ADD70 5440FF8F */  bnezl $v0, .L7F0ADBB0
/* 0E28A4 7F0ADD74 24010020 */   li    $at, 32
.L7F0ADD78:
/* 0E28A8 7F0ADD78 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0E28AC 7F0ADD7C 02601025 */  move  $v0, $s3
/* 0E28B0 7F0ADD80 8FB30044 */  lw    $s3, 0x44($sp)
/* 0E28B4 7F0ADD84 8FB00038 */  lw    $s0, 0x38($sp)
/* 0E28B8 7F0ADD88 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0E28BC 7F0ADD8C 8FB20040 */  lw    $s2, 0x40($sp)
/* 0E28C0 7F0ADD90 8FB40048 */  lw    $s4, 0x48($sp)
/* 0E28C4 7F0ADD94 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0E28C8 7F0ADD98 8FB60050 */  lw    $s6, 0x50($sp)
/* 0E28CC 7F0ADD9C 8FB70054 */  lw    $s7, 0x54($sp)
/* 0E28D0 7F0ADDA0 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0E28D4 7F0ADDA4 03E00008 */  jr    $ra
/* 0E28D8 7F0ADDA8 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel en_text_write_stuff
/* 0E25EC 7F0ADABC 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 0E25F0 7F0ADAC0 240E0001 */  li    $t6, 1
/* 0E25F4 7F0ADAC4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E25F8 7F0ADAC8 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0E25FC 7F0ADACC AFBF005C */  sw    $ra, 0x5c($sp)
/* 0E2600 7F0ADAD0 AFBE0058 */  sw    $fp, 0x58($sp)
/* 0E2604 7F0ADAD4 AFB70054 */  sw    $s7, 0x54($sp)
/* 0E2608 7F0ADAD8 AFB60050 */  sw    $s6, 0x50($sp)
/* 0E260C 7F0ADADC AFB5004C */  sw    $s5, 0x4c($sp)
/* 0E2610 7F0ADAE0 AFB40048 */  sw    $s4, 0x48($sp)
/* 0E2614 7F0ADAE4 AFB30044 */  sw    $s3, 0x44($sp)
/* 0E2618 7F0ADAE8 AFB20040 */  sw    $s2, 0x40($sp)
/* 0E261C 7F0ADAEC AFB1003C */  sw    $s1, 0x3c($sp)
/* 0E2620 7F0ADAF0 AFB00038 */  sw    $s0, 0x38($sp)
/* 0E2624 7F0ADAF4 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E2628 7F0ADAF8 8CCF0000 */  lw    $t7, ($a2)
/* 0E262C 7F0ADAFC 8CB40000 */  lw    $s4, ($a1)
/* 0E2630 7F0ADB00 00E08025 */  move  $s0, $a3
/* 0E2634 7F0ADB04 00A08825 */  move  $s1, $a1
/* 0E2638 7F0ADB08 00C09025 */  move  $s2, $a2
/* 0E263C 7F0ADB0C 00809825 */  move  $s3, $a0
/* 0E2640 7F0ADB10 24150048 */  li    $s5, 72
/* 0E2644 7F0ADB14 17000006 */  bnez  $t8, .L7F0ADB30
/* 0E2648 7F0ADB18 AFAF00A0 */   sw    $t7, 0xa0($sp)
/* 0E264C 7F0ADB1C 8FB900B8 */  lw    $t9, 0xb8($sp)
/* 0E2650 7F0ADB20 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E2654 7F0ADB24 8F290890 */  lw    $t1, 0x890($t9)
/* 0E2658 7F0ADB28 01095021 */  addu  $t2, $t0, $t1
/* 0E265C 7F0ADB2C AFAA00D0 */  sw    $t2, 0xd0($sp)
.L7F0ADB30:
/* 0E2660 7F0ADB30 3C0B8005 */  lui   $t3, %hi(j_text_trigger) 
/* 0E2664 7F0ADB34 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E2668 7F0ADB38 8FAC00D0 */  lw    $t4, 0xd0($sp)
/* 0E266C 7F0ADB3C 02602025 */  move  $a0, $s3
/* 0E2670 7F0ADB40 11600004 */  beqz  $t3, .L7F0ADB54
/* 0E2674 7F0ADB44 2981000E */   slti  $at, $t4, 0xe
/* 0E2678 7F0ADB48 10200002 */  beqz  $at, .L7F0ADB54
/* 0E267C 7F0ADB4C 240D000E */   li    $t5, 14
/* 0E2680 7F0ADB50 AFAD00D0 */  sw    $t5, 0xd0($sp)
.L7F0ADB54:
/* 0E2684 7F0ADB54 8FA300C0 */  lw    $v1, 0xc0($sp)
/* 0E2688 7F0ADB58 3C0EFA00 */  lui   $t6, 0xfa00
/* 0E268C 7F0ADB5C AC8E0000 */  sw    $t6, ($a0)
/* 0E2690 7F0ADB60 0003CE02 */  srl   $t9, $v1, 0x18
/* 0E2694 7F0ADB64 00035402 */  srl   $t2, $v1, 0x10
/* 0E2698 7F0ADB68 314B00FF */  andi  $t3, $t2, 0xff
/* 0E269C 7F0ADB6C 00194600 */  sll   $t0, $t9, 0x18
/* 0E26A0 7F0ADB70 00037A02 */  srl   $t7, $v1, 8
/* 0E26A4 7F0ADB74 31F800FF */  andi  $t8, $t7, 0xff
/* 0E26A8 7F0ADB78 000B6400 */  sll   $t4, $t3, 0x10
/* 0E26AC 7F0ADB7C 010C6825 */  or    $t5, $t0, $t4
/* 0E26B0 7F0ADB80 0018CA00 */  sll   $t9, $t8, 8
/* 0E26B4 7F0ADB84 01B94825 */  or    $t1, $t5, $t9
/* 0E26B8 7F0ADB88 306B00FF */  andi  $t3, $v1, 0xff
/* 0E26BC 7F0ADB8C 012B4025 */  or    $t0, $t1, $t3
/* 0E26C0 7F0ADB90 AC880004 */  sw    $t0, 4($a0)
/* 0E26C4 7F0ADB94 92020000 */  lbu   $v0, ($s0)
/* 0E26C8 7F0ADB98 26730008 */  addiu $s3, $s3, 8
/* 0E26CC 7F0ADB9C 8FB700BC */  lw    $s7, 0xbc($sp)
/* 0E26D0 7F0ADBA0 10400075 */  beqz  $v0, .L7F0ADD78
/* 0E26D4 7F0ADBA4 8FBE00C4 */   lw    $fp, 0xc4($sp)
/* 0E26D8 7F0ADBA8 27B6006C */  addiu $s6, $sp, 0x6c
/* 0E26DC 7F0ADBAC 24010020 */  li    $at, 32
.L7F0ADBB0:
/* 0E26E0 7F0ADBB0 54410008 */  bnel  $v0, $at, .L7F0ADBD4
/* 0E26E4 7F0ADBB4 2401000A */   li    $at, 10
/* 0E26E8 7F0ADBB8 8E2C0000 */  lw    $t4, ($s1)
/* 0E26EC 7F0ADBBC 24150048 */  li    $s5, 72
/* 0E26F0 7F0ADBC0 26100001 */  addiu $s0, $s0, 1
/* 0E26F4 7F0ADBC4 258E0005 */  addiu $t6, $t4, 5
/* 0E26F8 7F0ADBC8 10000068 */  b     .L7F0ADD6C
/* 0E26FC 7F0ADBCC AE2E0000 */   sw    $t6, ($s1)
/* 0E2700 7F0ADBD0 2401000A */  li    $at, 10
.L7F0ADBD4:
/* 0E2704 7F0ADBD4 54410014 */  bnel  $v0, $at, .L7F0ADC28
/* 0E2708 7F0ADBD8 28410080 */   slti  $at, $v0, 0x80
/* 0E270C 7F0ADBDC 3C028004 */  lui   $v0, %hi(overlap_correction)
/* 0E2710 7F0ADBE0 8C420E90 */  lw    $v0, %lo(overlap_correction)($v0)
/* 0E2714 7F0ADBE4 24150048 */  li    $s5, 72
/* 0E2718 7F0ADBE8 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 0E271C 7F0ADBEC 04400008 */  bltz  $v0, .L7F0ADC10
/* 0E2720 7F0ADBF0 26100001 */   addiu $s0, $s0, 1
/* 0E2724 7F0ADBF4 8E2F0000 */  lw    $t7, ($s1)
/* 0E2728 7F0ADBF8 568F0006 */  bnel  $s4, $t7, .L7F0ADC14
/* 0E272C 7F0ADBFC 8E590000 */   lw    $t9, ($s2)
/* 0E2730 7F0ADC00 8E580000 */  lw    $t8, ($s2)
/* 0E2734 7F0ADC04 03026821 */  addu  $t5, $t8, $v0
/* 0E2738 7F0ADC08 10000004 */  b     .L7F0ADC1C
/* 0E273C 7F0ADC0C AE4D0000 */   sw    $t5, ($s2)
.L7F0ADC10:
/* 0E2740 7F0ADC10 8E590000 */  lw    $t9, ($s2)
.L7F0ADC14:
/* 0E2744 7F0ADC14 032A4821 */  addu  $t1, $t9, $t2
/* 0E2748 7F0ADC18 AE490000 */  sw    $t1, ($s2)
.L7F0ADC1C:
/* 0E274C 7F0ADC1C 10000053 */  b     .L7F0ADD6C
/* 0E2750 7F0ADC20 AE340000 */   sw    $s4, ($s1)
/* 0E2754 7F0ADC24 28410080 */  slti  $at, $v0, 0x80
.L7F0ADC28:
/* 0E2758 7F0ADC28 1020001D */  beqz  $at, .L7F0ADCA0
/* 0E275C 7F0ADC2C 3C0E8004 */   lui   $t6, %hi(D_80040EFC)
/* 0E2760 7F0ADC30 24030018 */  li    $v1, 24
/* 0E2764 7F0ADC34 00430019 */  multu $v0, $v1
/* 0E2768 7F0ADC38 8FA800B8 */  lw    $t0, 0xb8($sp)
/* 0E276C 7F0ADC3C 8FB800A0 */  lw    $t8, 0xa0($sp)
/* 0E2770 7F0ADC40 8FAD00C8 */  lw    $t5, 0xc8($sp)
/* 0E2774 7F0ADC44 8FB900CC */  lw    $t9, 0xcc($sp)
/* 0E2778 7F0ADC48 02602025 */  move  $a0, $s3
/* 0E277C 7F0ADC4C 02202825 */  move  $a1, $s1
/* 0E2780 7F0ADC50 02403025 */  move  $a2, $s2
/* 0E2784 7F0ADC54 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E2788 7F0ADC58 AFB40018 */  sw    $s4, 0x18($sp)
/* 0E278C 7F0ADC5C 00005812 */  mflo  $t3
/* 0E2790 7F0ADC60 01683821 */  addu  $a3, $t3, $t0
/* 0E2794 7F0ADC64 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E2798 7F0ADC68 02A30019 */  multu $s5, $v1
/* 0E279C 7F0ADC6C AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E27A0 7F0ADC70 AFB8001C */  sw    $t8, 0x1c($sp)
/* 0E27A4 7F0ADC74 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E27A8 7F0ADC78 AFB90028 */  sw    $t9, 0x28($sp)
/* 0E27AC 7F0ADC7C 00006012 */  mflo  $t4
/* 0E27B0 7F0ADC80 01887021 */  addu  $t6, $t4, $t0
/* 0E27B4 7F0ADC84 25CFFCE8 */  addiu $t7, $t6, -0x318
/* 0E27B8 7F0ADC88 0FC2B43E */  jal   sub_GAME_7F0AD0F8
/* 0E27BC 7F0ADC8C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0E27C0 7F0ADC90 00409825 */  move  $s3, $v0
/* 0E27C4 7F0ADC94 92150000 */  lbu   $s5, ($s0)
/* 0E27C8 7F0ADC98 10000034 */  b     .L7F0ADD6C
/* 0E27CC 7F0ADC9C 26100001 */   addiu $s0, $s0, 1
.L7F0ADCA0:
/* 0E27D0 7F0ADCA0 25CE0EFC */  addiu $t6, $t6, %lo(D_80040EFC)
/* 0E27D4 7F0ADCA4 8DC10000 */  lw    $at, ($t6)
/* 0E27D8 7F0ADCA8 920A0001 */  lbu   $t2, 1($s0)
/* 0E27DC 7F0ADCAC 304B007F */  andi  $t3, $v0, 0x7f
/* 0E27E0 7F0ADCB0 AEC10000 */  sw    $at, ($s6)
/* 0E27E4 7F0ADCB4 8DD80004 */  lw    $t8, 4($t6)
/* 0E27E8 7F0ADCB8 000B61C0 */  sll   $t4, $t3, 7
/* 0E27EC 7F0ADCBC 3149007F */  andi  $t1, $t2, 0x7f
/* 0E27F0 7F0ADCC0 AED80004 */  sw    $t8, 4($s6)
/* 0E27F4 7F0ADCC4 8DC10008 */  lw    $at, 8($t6)
/* 0E27F8 7F0ADCC8 012C1825 */  or    $v1, $t1, $t4
/* 0E27FC 7F0ADCCC 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E2800 7F0ADCD0 AEC10008 */  sw    $at, 8($s6)
/* 0E2804 7F0ADCD4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E2808 7F0ADCD8 308D2000 */  andi  $t5, $a0, 0x2000
/* 0E280C 7F0ADCDC 308B1FFF */  andi  $t3, $a0, 0x1fff
/* 0E2810 7F0ADCE0 AED8000C */  sw    $t8, 0xc($s6)
/* 0E2814 7F0ADCE4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E2818 7F0ADCE8 2419000F */  li    $t9, 15
/* 0E281C 7F0ADCEC 240A0010 */  li    $t2, 16
/* 0E2820 7F0ADCF0 AEC10010 */  sw    $at, 0x10($s6)
/* 0E2824 7F0ADCF4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E2828 7F0ADCF8 296103C7 */  slti  $at, $t3, 0x3c8
/* 0E282C 7F0ADCFC 11A00003 */  beqz  $t5, .L7F0ADD0C
/* 0E2830 7F0ADD00 AED80014 */   sw    $t8, 0x14($s6)
/* 0E2834 7F0ADD04 AFB90078 */  sw    $t9, 0x78($sp)
/* 0E2838 7F0ADD08 AFAA0074 */  sw    $t2, 0x74($sp)
.L7F0ADD0C:
/* 0E283C 7F0ADD0C 54200003 */  bnezl $at, .L7F0ADD1C
/* 0E2840 7F0ADD10 24890080 */   addiu $t1, $a0, 0x80
/* 0E2844 7F0ADD14 24040002 */  li    $a0, 2
/* 0E2848 7F0ADD18 24890080 */  addiu $t1, $a0, 0x80
.L7F0ADD1C:
/* 0E284C 7F0ADD1C 0FC3068C */  jal   something_with_LnameX
/* 0E2850 7F0ADD20 AFA9006C */   sw    $t1, 0x6c($sp)
/* 0E2854 7F0ADD24 8FAC00A0 */  lw    $t4, 0xa0($sp)
/* 0E2858 7F0ADD28 8FA800C8 */  lw    $t0, 0xc8($sp)
/* 0E285C 7F0ADD2C 8FAF00CC */  lw    $t7, 0xcc($sp)
/* 0E2860 7F0ADD30 AFA20080 */  sw    $v0, 0x80($sp)
/* 0E2864 7F0ADD34 02602025 */  move  $a0, $s3
/* 0E2868 7F0ADD38 02202825 */  move  $a1, $s1
/* 0E286C 7F0ADD3C 02403025 */  move  $a2, $s2
/* 0E2870 7F0ADD40 02C03825 */  move  $a3, $s6
/* 0E2874 7F0ADD44 AFB60010 */  sw    $s6, 0x10($sp)
/* 0E2878 7F0ADD48 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E287C 7F0ADD4C AFB40018 */  sw    $s4, 0x18($sp)
/* 0E2880 7F0ADD50 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E2884 7F0ADD54 AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E2888 7F0ADD58 AFA80024 */  sw    $t0, 0x24($sp)
/* 0E288C 7F0ADD5C 0FC2B43E */  jal   sub_GAME_7F0AD0F8
/* 0E2890 7F0ADD60 AFAF0028 */   sw    $t7, 0x28($sp)
/* 0E2894 7F0ADD64 00409825 */  move  $s3, $v0
/* 0E2898 7F0ADD68 26100002 */  addiu $s0, $s0, 2
.L7F0ADD6C:
/* 0E289C 7F0ADD6C 92020000 */  lbu   $v0, ($s0)
/* 0E28A0 7F0ADD70 5440FF8F */  bnezl $v0, .L7F0ADBB0
/* 0E28A4 7F0ADD74 24010020 */   li    $at, 32
.L7F0ADD78:
/* 0E28A8 7F0ADD78 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0E28AC 7F0ADD7C 02601025 */  move  $v0, $s3
/* 0E28B0 7F0ADD80 8FB30044 */  lw    $s3, 0x44($sp)
/* 0E28B4 7F0ADD84 8FB00038 */  lw    $s0, 0x38($sp)
/* 0E28B8 7F0ADD88 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0E28BC 7F0ADD8C 8FB20040 */  lw    $s2, 0x40($sp)
/* 0E28C0 7F0ADD90 8FB40048 */  lw    $s4, 0x48($sp)
/* 0E28C4 7F0ADD94 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0E28C8 7F0ADD98 8FB60050 */  lw    $s6, 0x50($sp)
/* 0E28CC 7F0ADD9C 8FB70054 */  lw    $s7, 0x54($sp)
/* 0E28D0 7F0ADDA0 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0E28D4 7F0ADDA4 03E00008 */  jr    $ra
/* 0E28D8 7F0ADDA8 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif
#endif




#ifdef NONMATCHING
void sub_GAME_7F0ADDAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0ADDAC
/* 0E28DC 7F0ADDAC 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0E28E0 7F0ADDB0 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0E28E4 7F0ADDB4 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0E28E8 7F0ADDB8 AFB70044 */  sw    $s7, 0x44($sp)
/* 0E28EC 7F0ADDBC AFB60040 */  sw    $s6, 0x40($sp)
/* 0E28F0 7F0ADDC0 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0E28F4 7F0ADDC4 AFB40038 */  sw    $s4, 0x38($sp)
/* 0E28F8 7F0ADDC8 AFB30034 */  sw    $s3, 0x34($sp)
/* 0E28FC 7F0ADDCC AFB20030 */  sw    $s2, 0x30($sp)
/* 0E2900 7F0ADDD0 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0E2904 7F0ADDD4 AFB00028 */  sw    $s0, 0x28($sp)
/* 0E2908 7F0ADDD8 8CCE0000 */  lw    $t6, ($a2)
/* 0E290C 7F0ADDDC 8FAF0090 */  lw    $t7, 0x90($sp)
/* 0E2910 7F0ADDE0 8FA90070 */  lw    $t1, 0x70($sp)
/* 0E2914 7F0ADDE4 8FB90074 */  lw    $t9, 0x74($sp)
/* 0E2918 7F0ADDE8 01CFC021 */  addu  $t8, $t6, $t7
/* 0E291C 7F0ADDEC AFB80050 */  sw    $t8, 0x50($sp)
/* 0E2920 7F0ADDF0 8D2A0010 */  lw    $t2, 0x10($t1)
/* 0E2924 7F0ADDF4 8CEE0010 */  lw    $t6, 0x10($a3)
/* 0E2928 7F0ADDF8 00809825 */  move  $s3, $a0
/* 0E292C 7F0ADDFC 000A5880 */  sll   $t3, $t2, 2
/* 0E2930 7F0ADE00 016A5823 */  subu  $t3, $t3, $t2
/* 0E2934 7F0ADE04 000B5880 */  sll   $t3, $t3, 2
/* 0E2938 7F0ADE08 016A5821 */  addu  $t3, $t3, $t2
/* 0E293C 7F0ADE0C 000B6080 */  sll   $t4, $t3, 2
/* 0E2940 7F0ADE10 032C6821 */  addu  $t5, $t9, $t4
/* 0E2944 7F0ADE14 000E7880 */  sll   $t7, $t6, 2
/* 0E2948 7F0ADE18 01AFC021 */  addu  $t8, $t5, $t7
/* 0E294C 7F0ADE1C 3C0A8004 */  lui   $t2, %hi(text_spacing) 
/* 0E2950 7F0ADE20 8D4A0E84 */  lw    $t2, %lo(text_spacing)($t2)
/* 0E2954 7F0ADE24 8F090000 */  lw    $t1, ($t8)
/* 0E2958 7F0ADE28 8CAB0000 */  lw    $t3, ($a1)
/* 0E295C 7F0ADE2C 00E0F025 */  move  $fp, $a3
/* 0E2960 7F0ADE30 012A1021 */  addu  $v0, $t1, $t2
/* 0E2964 7F0ADE34 0162C823 */  subu  $t9, $t3, $v0
/* 0E2968 7F0ADE38 272C0001 */  addiu $t4, $t9, 1
/* 0E296C 7F0ADE3C ACAC0000 */  sw    $t4, ($a1)
/* 0E2970 7F0ADE40 AFA50064 */  sw    $a1, 0x64($sp)
/* 0E2974 7F0ADE44 8CAE0000 */  lw    $t6, ($a1)
/* 0E2978 7F0ADE48 59C00173 */  blezl $t6, .L7F0AE418
/* 0E297C 7F0ADE4C 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E2980 7F0ADE50 0C001107 */  jal   get_video2_settings_txtClipW
/* 0E2984 7F0ADE54 AFA50064 */   sw    $a1, 0x64($sp)
/* 0E2988 7F0ADE58 8FAD0064 */  lw    $t5, 0x64($sp)
/* 0E298C 7F0ADE5C 8DAF0000 */  lw    $t7, ($t5)
/* 0E2990 7F0ADE60 004F082A */  slt   $at, $v0, $t7
/* 0E2994 7F0ADE64 5420016C */  bnezl $at, .L7F0AE418
/* 0E2998 7F0ADE68 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E299C 7F0ADE6C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0E29A0 7F0ADE70 00000000 */   nop   
/* 0E29A4 7F0ADE74 8FB80050 */  lw    $t8, 0x50($sp)
/* 0E29A8 7F0ADE78 8FC90004 */  lw    $t1, 4($fp)
/* 0E29AC 7F0ADE7C 8FAA0064 */  lw    $t2, 0x64($sp)
/* 0E29B0 7F0ADE80 03092021 */  addu  $a0, $t8, $t1
/* 0E29B4 7F0ADE84 0044082A */  slt   $at, $v0, $a0
/* 0E29B8 7F0ADE88 54200163 */  bnezl $at, .L7F0AE418
/* 0E29BC 7F0ADE8C 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E29C0 7F0ADE90 8FB40078 */  lw    $s4, 0x78($sp)
/* 0E29C4 7F0ADE94 8FB60088 */  lw    $s6, 0x88($sp)
/* 0E29C8 7F0ADE98 8D430000 */  lw    $v1, ($t2)
/* 0E29CC 7F0ADE9C 8FB5007C */  lw    $s5, 0x7c($sp)
/* 0E29D0 7F0ADEA0 02965821 */  addu  $t3, $s4, $s6
/* 0E29D4 7F0ADEA4 0163082A */  slt   $at, $t3, $v1
/* 0E29D8 7F0ADEA8 1420015A */  bnez  $at, .L7F0AE414
/* 0E29DC 7F0ADEAC 8FB7008C */   lw    $s7, 0x8c($sp)
/* 0E29E0 7F0ADEB0 02B7C821 */  addu  $t9, $s5, $s7
/* 0E29E4 7F0ADEB4 0324082A */  slt   $at, $t9, $a0
/* 0E29E8 7F0ADEB8 14200156 */  bnez  $at, .L7F0AE414
/* 0E29EC 7F0ADEBC 0074082A */   slt   $at, $v1, $s4
/* 0E29F0 7F0ADEC0 54200155 */  bnezl $at, .L7F0AE418
/* 0E29F4 7F0ADEC4 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E29F8 7F0ADEC8 8FCC0008 */  lw    $t4, 8($fp)
/* 0E29FC 7F0ADECC 008C7021 */  addu  $t6, $a0, $t4
/* 0E2A00 7F0ADED0 01D5082A */  slt   $at, $t6, $s5
/* 0E2A04 7F0ADED4 54200150 */  bnezl $at, .L7F0AE418
/* 0E2A08 7F0ADED8 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E2A0C 7F0ADEDC 8FCD0000 */  lw    $t5, ($fp)
/* 0E2A10 7F0ADEE0 3C058004 */  lui   $a1, %hi(D_80040EA8)
/* 0E2A14 7F0ADEE4 24A50EA8 */  addiu $a1, %lo(D_80040EA8) # addiu $a1, $a1, 0xea8
/* 0E2A18 7F0ADEE8 29A10080 */  slti  $at, $t5, 0x80
/* 0E2A1C 7F0ADEEC 1020006E */  beqz  $at, .L7F0AE0A8
/* 0E2A20 7F0ADEF0 3C11E700 */   lui   $s1, 0xe700
/* 0E2A24 7F0ADEF4 02601025 */  move  $v0, $s3
/* 0E2A28 7F0ADEF8 3C0FBA00 */  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
/* 0E2A2C 7F0ADEFC 35EF0E02 */  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
/* 0E2A30 7F0ADF00 26730008 */  addiu $s3, $s3, 8
/* 0E2A34 7F0ADF04 AC4F0000 */  sw    $t7, ($v0)
/* 0E2A38 7F0ADF08 AC400004 */  sw    $zero, 4($v0)
/* 0E2A3C 7F0ADF0C 02601825 */  move  $v1, $s3
/* 0E2A40 7F0ADF10 3C18FD90 */  lui   $t8, 0xfd90
/* 0E2A44 7F0ADF14 AC780000 */  sw    $t8, ($v1)
/* 0E2A48 7F0ADF18 8FC90014 */  lw    $t1, 0x14($fp)
/* 0E2A4C 7F0ADF1C 26730008 */  addiu $s3, $s3, 8
/* 0E2A50 7F0ADF20 02602025 */  move  $a0, $s3
/* 0E2A54 7F0ADF24 26730008 */  addiu $s3, $s3, 8
/* 0E2A58 7F0ADF28 AC690004 */  sw    $t1, 4($v1)
/* 0E2A5C 7F0ADF2C 3C120700 */  lui   $s2, 0x700
/* 0E2A60 7F0ADF30 02602825 */  move  $a1, $s3
/* 0E2A64 7F0ADF34 3C0AF590 */  lui   $t2, 0xf590
/* 0E2A68 7F0ADF38 AC8A0000 */  sw    $t2, ($a0)
/* 0E2A6C 7F0ADF3C AC920004 */  sw    $s2, 4($a0)
/* 0E2A70 7F0ADF40 26730008 */  addiu $s3, $s3, 8
/* 0E2A74 7F0ADF44 3C0BE600 */  lui   $t3, 0xe600
/* 0E2A78 7F0ADF48 ACAB0000 */  sw    $t3, ($a1)
/* 0E2A7C 7F0ADF4C 02604025 */  move  $t0, $s3
/* 0E2A80 7F0ADF50 ACA00004 */  sw    $zero, 4($a1)
/* 0E2A84 7F0ADF54 3C19F300 */  lui   $t9, 0xf300
/* 0E2A88 7F0ADF58 AD190000 */  sw    $t9, ($t0)
/* 0E2A8C 7F0ADF5C 8FC3000C */  lw    $v1, 0xc($fp)
/* 0E2A90 7F0ADF60 8FCE0008 */  lw    $t6, 8($fp)
/* 0E2A94 7F0ADF64 26730008 */  addiu $s3, $s3, 8
/* 0E2A98 7F0ADF68 24630007 */  addiu $v1, $v1, 7
/* 0E2A9C 7F0ADF6C 306C00F8 */  andi  $t4, $v1, 0xf8
/* 0E2AA0 7F0ADF70 018E0019 */  multu $t4, $t6
/* 0E2AA4 7F0ADF74 01801825 */  move  $v1, $t4
/* 0E2AA8 7F0ADF78 3C11E700 */  lui   $s1, 0xe700
/* 0E2AAC 7F0ADF7C 240607FF */  li    $a2, 2047
/* 0E2AB0 7F0ADF80 00001012 */  mflo  $v0
/* 0E2AB4 7F0ADF84 24420001 */  addiu $v0, $v0, 1
/* 0E2AB8 7F0ADF88 00026843 */  sra   $t5, $v0, 1
/* 0E2ABC 7F0ADF8C 25A2FFFF */  addiu $v0, $t5, -1
/* 0E2AC0 7F0ADF90 284107FF */  slti  $at, $v0, 0x7ff
/* 0E2AC4 7F0ADF94 10200003 */  beqz  $at, .L7F0ADFA4
/* 0E2AC8 7F0ADF98 00000000 */   nop   
/* 0E2ACC 7F0ADF9C 10000001 */  b     .L7F0ADFA4
/* 0E2AD0 7F0ADFA0 00403025 */   move  $a2, $v0
.L7F0ADFA4:
/* 0E2AD4 7F0ADFA4 04610003 */  bgez  $v1, .L7F0ADFB4
/* 0E2AD8 7F0ADFA8 000310C3 */   sra   $v0, $v1, 3
/* 0E2ADC 7F0ADFAC 24610007 */  addiu $at, $v1, 7
/* 0E2AE0 7F0ADFB0 000110C3 */  sra   $v0, $at, 3
.L7F0ADFB4:
/* 0E2AE4 7F0ADFB4 1C400003 */  bgtz  $v0, .L7F0ADFC4
/* 0E2AE8 7F0ADFB8 30CB0FFF */   andi  $t3, $a2, 0xfff
/* 0E2AEC 7F0ADFBC 10000002 */  b     .L7F0ADFC8
/* 0E2AF0 7F0ADFC0 24070001 */   li    $a3, 1
.L7F0ADFC4:
/* 0E2AF4 7F0ADFC4 00403825 */  move  $a3, $v0
.L7F0ADFC8:
/* 0E2AF8 7F0ADFC8 1C400003 */  bgtz  $v0, .L7F0ADFD8
/* 0E2AFC 7F0ADFCC 24EF07FF */   addiu $t7, $a3, 0x7ff
/* 0E2B00 7F0ADFD0 10000002 */  b     .L7F0ADFDC
/* 0E2B04 7F0ADFD4 24050001 */   li    $a1, 1
.L7F0ADFD8:
/* 0E2B08 7F0ADFD8 00402825 */  move  $a1, $v0
.L7F0ADFDC:
/* 0E2B0C 7F0ADFDC 01E5001A */  div   $zero, $t7, $a1
/* 0E2B10 7F0ADFE0 0000C012 */  mflo  $t8
/* 0E2B14 7F0ADFE4 33090FFF */  andi  $t1, $t8, 0xfff
/* 0E2B18 7F0ADFE8 01325025 */  or    $t2, $t1, $s2
/* 0E2B1C 7F0ADFEC 000BCB00 */  sll   $t9, $t3, 0xc
/* 0E2B20 7F0ADFF0 01596025 */  or    $t4, $t2, $t9
/* 0E2B24 7F0ADFF4 AD0C0004 */  sw    $t4, 4($t0)
/* 0E2B28 7F0ADFF8 02601025 */  move  $v0, $s3
/* 0E2B2C 7F0ADFFC AC510000 */  sw    $s1, ($v0)
/* 0E2B30 7F0AE000 AC400004 */  sw    $zero, 4($v0)
/* 0E2B34 7F0AE004 8FCE000C */  lw    $t6, 0xc($fp)
/* 0E2B38 7F0AE008 14A00002 */  bnez  $a1, .L7F0AE014
/* 0E2B3C 7F0AE00C 00000000 */   nop   
/* 0E2B40 7F0AE010 0007000D */  break 7
.L7F0AE014:
/* 0E2B44 7F0AE014 2401FFFF */  li    $at, -1
/* 0E2B48 7F0AE018 14A10004 */  bne   $a1, $at, .L7F0AE02C
/* 0E2B4C 7F0AE01C 3C018000 */   lui   $at, 0x8000
/* 0E2B50 7F0AE020 15E10002 */  bne   $t7, $at, .L7F0AE02C
/* 0E2B54 7F0AE024 00000000 */   nop   
/* 0E2B58 7F0AE028 0006000D */  break 6
.L7F0AE02C:
/* 0E2B5C 7F0AE02C 25CD0007 */  addiu $t5, $t6, 7
/* 0E2B60 7F0AE030 31AF00F8 */  andi  $t7, $t5, 0xf8
/* 0E2B64 7F0AE034 25F80007 */  addiu $t8, $t7, 7
/* 0E2B68 7F0AE038 001848C3 */  sra   $t1, $t8, 3
/* 0E2B6C 7F0AE03C 26730008 */  addiu $s3, $s3, 8
/* 0E2B70 7F0AE040 02601825 */  move  $v1, $s3
/* 0E2B74 7F0AE044 312B01FF */  andi  $t3, $t1, 0x1ff
/* 0E2B78 7F0AE048 000B5240 */  sll   $t2, $t3, 9
/* 0E2B7C 7F0AE04C 3C01F588 */  lui   $at, 0xf588
/* 0E2B80 7F0AE050 0141C825 */  or    $t9, $t2, $at
/* 0E2B84 7F0AE054 26730008 */  addiu $s3, $s3, 8
/* 0E2B88 7F0AE058 02602025 */  move  $a0, $s3
/* 0E2B8C 7F0AE05C AC790000 */  sw    $t9, ($v1)
/* 0E2B90 7F0AE060 AC600004 */  sw    $zero, 4($v1)
/* 0E2B94 7F0AE064 3C0CF200 */  lui   $t4, 0xf200
/* 0E2B98 7F0AE068 AC8C0000 */  sw    $t4, ($a0)
/* 0E2B9C 7F0AE06C 8FCE000C */  lw    $t6, 0xc($fp)
/* 0E2BA0 7F0AE070 8FD90008 */  lw    $t9, 8($fp)
/* 0E2BA4 7F0AE074 26730008 */  addiu $s3, $s3, 8
/* 0E2BA8 7F0AE078 25CD0007 */  addiu $t5, $t6, 7
/* 0E2BAC 7F0AE07C 31AF00F8 */  andi  $t7, $t5, 0xf8
/* 0E2BB0 7F0AE080 25F8FFFF */  addiu $t8, $t7, -1
/* 0E2BB4 7F0AE084 00184880 */  sll   $t1, $t8, 2
/* 0E2BB8 7F0AE088 272CFFFF */  addiu $t4, $t9, -1
/* 0E2BBC 7F0AE08C 000C7080 */  sll   $t6, $t4, 2
/* 0E2BC0 7F0AE090 312B0FFF */  andi  $t3, $t1, 0xfff
/* 0E2BC4 7F0AE094 000B5300 */  sll   $t2, $t3, 0xc
/* 0E2BC8 7F0AE098 31CD0FFF */  andi  $t5, $t6, 0xfff
/* 0E2BCC 7F0AE09C 014D7825 */  or    $t7, $t2, $t5
/* 0E2BD0 7F0AE0A0 10000095 */  b     .L7F0AE2F8
/* 0E2BD4 7F0AE0A4 AC8F0004 */   sw    $t7, 4($a0)
.L7F0AE0A8:
/* 0E2BD8 7F0AE0A8 02601025 */  move  $v0, $s3
/* 0E2BDC 7F0AE0AC 26730008 */  addiu $s3, $s3, 8
/* 0E2BE0 7F0AE0B0 AC510000 */  sw    $s1, ($v0)
/* 0E2BE4 7F0AE0B4 AC400004 */  sw    $zero, 4($v0)
/* 0E2BE8 7F0AE0B8 02601825 */  move  $v1, $s3
/* 0E2BEC 7F0AE0BC 3C18BA00 */  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
/* 0E2BF0 7F0AE0C0 37180E02 */  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
/* 0E2BF4 7F0AE0C4 3409C000 */  li    $t1, 49152
/* 0E2BF8 7F0AE0C8 AC690004 */  sw    $t1, 4($v1)
/* 0E2BFC 7F0AE0CC AC780000 */  sw    $t8, ($v1)
/* 0E2C00 7F0AE0D0 8CAB0000 */  lw    $t3, ($a1)
/* 0E2C04 7F0AE0D4 26730008 */  addiu $s3, $s3, 8
/* 0E2C08 7F0AE0D8 02608025 */  move  $s0, $s3
/* 0E2C0C 7F0AE0DC 11600047 */  beqz  $t3, .L7F0AE1FC
/* 0E2C10 7F0AE0E0 3C19FD10 */   lui   $t9, 0xfd10
/* 0E2C14 7F0AE0E4 ACA00000 */  sw    $zero, ($a1)
/* 0E2C18 7F0AE0E8 3C048004 */  lui   $a0, %hi(D_80040EBC)
/* 0E2C1C 7F0AE0EC 24840EBC */  addiu $a0, %lo(D_80040EBC) # addiu $a0, $a0, 0xebc
/* 0E2C20 7F0AE0F0 AE190000 */  sw    $t9, ($s0)
/* 0E2C24 7F0AE0F4 0C003A2C */  jal   osVirtualToPhysical
/* 0E2C28 7F0AE0F8 26730008 */   addiu $s3, $s3, 8
/* 0E2C2C 7F0AE0FC 02601825 */  move  $v1, $s3
/* 0E2C30 7F0AE100 26730008 */  addiu $s3, $s3, 8
/* 0E2C34 7F0AE104 AE020004 */  sw    $v0, 4($s0)
/* 0E2C38 7F0AE108 02602025 */  move  $a0, $s3
/* 0E2C3C 7F0AE10C 3C0CE800 */  lui   $t4, 0xe800
/* 0E2C40 7F0AE110 AC6C0000 */  sw    $t4, ($v1)
/* 0E2C44 7F0AE114 AC600004 */  sw    $zero, 4($v1)
/* 0E2C48 7F0AE118 3C0EF500 */  lui   $t6, (0xF5000100 >> 16) # lui $t6, 0xf500
/* 0E2C4C 7F0AE11C 35CE0100 */  ori   $t6, (0xF5000100 & 0xFFFF) # ori $t6, $t6, 0x100
/* 0E2C50 7F0AE120 26730008 */  addiu $s3, $s3, 8
/* 0E2C54 7F0AE124 3C120700 */  lui   $s2, 0x700
/* 0E2C58 7F0AE128 AC920004 */  sw    $s2, 4($a0)
/* 0E2C5C 7F0AE12C 02602825 */  move  $a1, $s3
/* 0E2C60 7F0AE130 AC8E0000 */  sw    $t6, ($a0)
/* 0E2C64 7F0AE134 26730008 */  addiu $s3, $s3, 8
/* 0E2C68 7F0AE138 02603025 */  move  $a2, $s3
/* 0E2C6C 7F0AE13C 3C0AE600 */  lui   $t2, 0xe600
/* 0E2C70 7F0AE140 ACAA0000 */  sw    $t2, ($a1)
/* 0E2C74 7F0AE144 26730008 */  addiu $s3, $s3, 8
/* 0E2C78 7F0AE148 ACA00004 */  sw    $zero, 4($a1)
/* 0E2C7C 7F0AE14C 3C0F0703 */  lui   $t7, (0x0703C000 >> 16) # lui $t7, 0x703
/* 0E2C80 7F0AE150 35EFC000 */  ori   $t7, (0x0703C000 & 0xFFFF) # ori $t7, $t7, 0xc000
/* 0E2C84 7F0AE154 02603825 */  move  $a3, $s3
/* 0E2C88 7F0AE158 3C0DF000 */  lui   $t5, 0xf000
/* 0E2C8C 7F0AE15C ACCD0000 */  sw    $t5, ($a2)
/* 0E2C90 7F0AE160 ACCF0004 */  sw    $t7, 4($a2)
/* 0E2C94 7F0AE164 26730008 */  addiu $s3, $s3, 8
/* 0E2C98 7F0AE168 ACE00004 */  sw    $zero, 4($a3)
/* 0E2C9C 7F0AE16C ACF10000 */  sw    $s1, ($a3)
/* 0E2CA0 7F0AE170 02608025 */  move  $s0, $s3
/* 0E2CA4 7F0AE174 3C048004 */  lui   $a0, %hi(D_80040EDC)
/* 0E2CA8 7F0AE178 3C18FD10 */  lui   $t8, 0xfd10
/* 0E2CAC 7F0AE17C AE180000 */  sw    $t8, ($s0)
/* 0E2CB0 7F0AE180 24840EDC */  addiu $a0, %lo(D_80040EDC) # addiu $a0, $a0, 0xedc
/* 0E2CB4 7F0AE184 0C003A2C */  jal   osVirtualToPhysical
/* 0E2CB8 7F0AE188 26730008 */   addiu $s3, $s3, 8
/* 0E2CBC 7F0AE18C 02601825 */  move  $v1, $s3
/* 0E2CC0 7F0AE190 26730008 */  addiu $s3, $s3, 8
/* 0E2CC4 7F0AE194 AE020004 */  sw    $v0, 4($s0)
/* 0E2CC8 7F0AE198 02602025 */  move  $a0, $s3
/* 0E2CCC 7F0AE19C 3C09E800 */  lui   $t1, 0xe800
/* 0E2CD0 7F0AE1A0 AC690000 */  sw    $t1, ($v1)
/* 0E2CD4 7F0AE1A4 26730008 */  addiu $s3, $s3, 8
/* 0E2CD8 7F0AE1A8 AC600004 */  sw    $zero, 4($v1)
/* 0E2CDC 7F0AE1AC 3C0BF500 */  lui   $t3, (0xF5000110 >> 16) # lui $t3, 0xf500
/* 0E2CE0 7F0AE1B0 356B0110 */  ori   $t3, (0xF5000110 & 0xFFFF) # ori $t3, $t3, 0x110
/* 0E2CE4 7F0AE1B4 02602825 */  move  $a1, $s3
/* 0E2CE8 7F0AE1B8 26730008 */  addiu $s3, $s3, 8
/* 0E2CEC 7F0AE1BC AC8B0000 */  sw    $t3, ($a0)
/* 0E2CF0 7F0AE1C0 AC920004 */  sw    $s2, 4($a0)
/* 0E2CF4 7F0AE1C4 02603025 */  move  $a2, $s3
/* 0E2CF8 7F0AE1C8 3C19E600 */  lui   $t9, 0xe600
/* 0E2CFC 7F0AE1CC ACB90000 */  sw    $t9, ($a1)
/* 0E2D00 7F0AE1D0 26730008 */  addiu $s3, $s3, 8
/* 0E2D04 7F0AE1D4 ACA00004 */  sw    $zero, 4($a1)
/* 0E2D08 7F0AE1D8 3C0E0703 */  lui   $t6, (0x0703C000 >> 16) # lui $t6, 0x703
/* 0E2D0C 7F0AE1DC 35CEC000 */  ori   $t6, (0x0703C000 & 0xFFFF) # ori $t6, $t6, 0xc000
/* 0E2D10 7F0AE1E0 02603825 */  move  $a3, $s3
/* 0E2D14 7F0AE1E4 3C0CF000 */  lui   $t4, 0xf000
/* 0E2D18 7F0AE1E8 ACCC0000 */  sw    $t4, ($a2)
/* 0E2D1C 7F0AE1EC ACCE0004 */  sw    $t6, 4($a2)
/* 0E2D20 7F0AE1F0 ACE00004 */  sw    $zero, 4($a3)
/* 0E2D24 7F0AE1F4 ACF10000 */  sw    $s1, ($a3)
/* 0E2D28 7F0AE1F8 26730008 */  addiu $s3, $s3, 8
.L7F0AE1FC:
/* 0E2D2C 7F0AE1FC 02608025 */  move  $s0, $s3
/* 0E2D30 7F0AE200 3C0AFD50 */  lui   $t2, 0xfd50
/* 0E2D34 7F0AE204 AE0A0000 */  sw    $t2, ($s0)
/* 0E2D38 7F0AE208 3C120700 */  lui   $s2, 0x700
/* 0E2D3C 7F0AE20C 8FC40014 */  lw    $a0, 0x14($fp)
/* 0E2D40 7F0AE210 0C003A2C */  jal   osVirtualToPhysical
/* 0E2D44 7F0AE214 26730008 */   addiu $s3, $s3, 8
/* 0E2D48 7F0AE218 02601825 */  move  $v1, $s3
/* 0E2D4C 7F0AE21C AE020004 */  sw    $v0, 4($s0)
/* 0E2D50 7F0AE220 26730008 */  addiu $s3, $s3, 8
/* 0E2D54 7F0AE224 3C0DF550 */  lui   $t5, 0xf550
/* 0E2D58 7F0AE228 02602025 */  move  $a0, $s3
/* 0E2D5C 7F0AE22C AC6D0000 */  sw    $t5, ($v1)
/* 0E2D60 7F0AE230 AC720004 */  sw    $s2, 4($v1)
/* 0E2D64 7F0AE234 26730008 */  addiu $s3, $s3, 8
/* 0E2D68 7F0AE238 3C0FE600 */  lui   $t7, 0xe600
/* 0E2D6C 7F0AE23C AC8F0000 */  sw    $t7, ($a0)
/* 0E2D70 7F0AE240 AC800004 */  sw    $zero, 4($a0)
/* 0E2D74 7F0AE244 02603025 */  move  $a2, $s3
/* 0E2D78 7F0AE248 3C18F300 */  lui   $t8, 0xf300
/* 0E2D7C 7F0AE24C ACD80000 */  sw    $t8, ($a2)
/* 0E2D80 7F0AE250 8FC70008 */  lw    $a3, 8($fp)
/* 0E2D84 7F0AE254 26730008 */  addiu $s3, $s3, 8
/* 0E2D88 7F0AE258 02601025 */  move  $v0, $s3
/* 0E2D8C 7F0AE25C 00074880 */  sll   $t1, $a3, 2
/* 0E2D90 7F0AE260 2527FFFF */  addiu $a3, $t1, -1
/* 0E2D94 7F0AE264 28E107FF */  slti  $at, $a3, 0x7ff
/* 0E2D98 7F0AE268 10200003 */  beqz  $at, .L7F0AE278
/* 0E2D9C 7F0AE26C 26730008 */   addiu $s3, $s3, 8
/* 0E2DA0 7F0AE270 10000002 */  b     .L7F0AE27C
/* 0E2DA4 7F0AE274 00E02825 */   move  $a1, $a3
.L7F0AE278:
/* 0E2DA8 7F0AE278 240507FF */  li    $a1, 2047
.L7F0AE27C:
/* 0E2DAC 7F0AE27C 30AB0FFF */  andi  $t3, $a1, 0xfff
/* 0E2DB0 7F0AE280 000BCB00 */  sll   $t9, $t3, 0xc
/* 0E2DB4 7F0AE284 03326025 */  or    $t4, $t9, $s2
/* 0E2DB8 7F0AE288 358E0800 */  ori   $t6, $t4, 0x800
/* 0E2DBC 7F0AE28C ACCE0004 */  sw    $t6, 4($a2)
/* 0E2DC0 7F0AE290 3C0AF540 */  lui   $t2, (0xF5400200 >> 16) # lui $t2, 0xf540
/* 0E2DC4 7F0AE294 AC400004 */  sw    $zero, 4($v0)
/* 0E2DC8 7F0AE298 AC510000 */  sw    $s1, ($v0)
/* 0E2DCC 7F0AE29C 354A0200 */  ori   $t2, (0xF5400200 & 0xFFFF) # ori $t2, $t2, 0x200
/* 0E2DD0 7F0AE2A0 02601825 */  move  $v1, $s3
/* 0E2DD4 7F0AE2A4 AC6A0000 */  sw    $t2, ($v1)
/* 0E2DD8 7F0AE2A8 8FCF0000 */  lw    $t7, ($fp)
/* 0E2DDC 7F0AE2AC 3C010008 */  lui   $at, 8
/* 0E2DE0 7F0AE2B0 26730008 */  addiu $s3, $s3, 8
/* 0E2DE4 7F0AE2B4 31F80001 */  andi  $t8, $t7, 1
/* 0E2DE8 7F0AE2B8 00184D00 */  sll   $t1, $t8, 0x14
/* 0E2DEC 7F0AE2BC 01215825 */  or    $t3, $t1, $at
/* 0E2DF0 7F0AE2C0 35790200 */  ori   $t9, $t3, 0x200
/* 0E2DF4 7F0AE2C4 AC790004 */  sw    $t9, 4($v1)
/* 0E2DF8 7F0AE2C8 02602025 */  move  $a0, $s3
/* 0E2DFC 7F0AE2CC 3C0CF200 */  lui   $t4, 0xf200
/* 0E2E00 7F0AE2D0 AC8C0000 */  sw    $t4, ($a0)
/* 0E2E04 7F0AE2D4 8FCE0008 */  lw    $t6, 8($fp)
/* 0E2E08 7F0AE2D8 3C010003 */  lui   $at, (0x0003C000 >> 16) # lui $at, 3
/* 0E2E0C 7F0AE2DC 3421C000 */  ori   $at, (0x0003C000 & 0xFFFF) # ori $at, $at, 0xc000
/* 0E2E10 7F0AE2E0 25CAFFFF */  addiu $t2, $t6, -1
/* 0E2E14 7F0AE2E4 000A6880 */  sll   $t5, $t2, 2
/* 0E2E18 7F0AE2E8 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E2E1C 7F0AE2EC 01E1C025 */  or    $t8, $t7, $at
/* 0E2E20 7F0AE2F0 AC980004 */  sw    $t8, 4($a0)
/* 0E2E24 7F0AE2F4 26730008 */  addiu $s3, $s3, 8
.L7F0AE2F8:
/* 0E2E28 7F0AE2F8 8FA20084 */  lw    $v0, 0x84($sp)
/* 0E2E2C 7F0AE2FC 02602025 */  move  $a0, $s3
/* 0E2E30 7F0AE300 3C09FA00 */  lui   $t1, 0xfa00
/* 0E2E34 7F0AE304 00026602 */  srl   $t4, $v0, 0x18
/* 0E2E38 7F0AE308 00026C02 */  srl   $t5, $v0, 0x10
/* 0E2E3C 7F0AE30C 31AF00FF */  andi  $t7, $t5, 0xff
/* 0E2E40 7F0AE310 000C7600 */  sll   $t6, $t4, 0x18
/* 0E2E44 7F0AE314 000FC400 */  sll   $t8, $t7, 0x10
/* 0E2E48 7F0AE318 AC890000 */  sw    $t1, ($a0)
/* 0E2E4C 7F0AE31C 0002CA02 */  srl   $t9, $v0, 8
/* 0E2E50 7F0AE320 332C00FF */  andi  $t4, $t9, 0xff
/* 0E2E54 7F0AE324 01D84825 */  or    $t1, $t6, $t8
/* 0E2E58 7F0AE328 000C5200 */  sll   $t2, $t4, 8
/* 0E2E5C 7F0AE32C 012A6825 */  or    $t5, $t1, $t2
/* 0E2E60 7F0AE330 304E00FF */  andi  $t6, $v0, 0xff
/* 0E2E64 7F0AE334 01AEC025 */  or    $t8, $t5, $t6
/* 0E2E68 7F0AE338 AC980004 */  sw    $t8, 4($a0)
/* 0E2E6C 7F0AE33C 8FAB0064 */  lw    $t3, 0x64($sp)
/* 0E2E70 7F0AE340 26730008 */  addiu $s3, $s3, 8
/* 0E2E74 7F0AE344 2411FFFF */  li    $s1, -1
/* 0E2E78 7F0AE348 24120002 */  li    $s2, 2
/* 0E2E7C 7F0AE34C 8D630000 */  lw    $v1, ($t3)
/* 0E2E80 7F0AE350 2410FFFF */  li    $s0, -1
.L7F0AE354:
/* 0E2E84 7F0AE354 16200003 */  bnez  $s1, .L7F0AE364
/* 0E2E88 7F0AE358 00712821 */   addu  $a1, $v1, $s1
/* 0E2E8C 7F0AE35C 5200000E */  beql  $s0, $zero, .L7F0AE398
/* 0E2E90 7F0AE360 26100001 */   addiu $s0, $s0, 1
.L7F0AE364:
/* 0E2E94 7F0AE364 8FB90050 */  lw    $t9, 0x50($sp)
/* 0E2E98 7F0AE368 02602025 */  move  $a0, $s3
/* 0E2E9C 7F0AE36C 03C03825 */  move  $a3, $fp
/* 0E2EA0 7F0AE370 AFB40010 */  sw    $s4, 0x10($sp)
/* 0E2EA4 7F0AE374 AFB50014 */  sw    $s5, 0x14($sp)
/* 0E2EA8 7F0AE378 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E2EAC 7F0AE37C AFB7001C */  sw    $s7, 0x1c($sp)
/* 0E2EB0 7F0AE380 0FC2B917 */  jal   sub_GAME_7F0AE45C
/* 0E2EB4 7F0AE384 03303021 */   addu  $a2, $t9, $s0
/* 0E2EB8 7F0AE388 8FAC0064 */  lw    $t4, 0x64($sp)
/* 0E2EBC 7F0AE38C 00409825 */  move  $s3, $v0
/* 0E2EC0 7F0AE390 8D830000 */  lw    $v1, ($t4)
/* 0E2EC4 7F0AE394 26100001 */  addiu $s0, $s0, 1
.L7F0AE398:
/* 0E2EC8 7F0AE398 1612FFEE */  bne   $s0, $s2, .L7F0AE354
/* 0E2ECC 7F0AE39C 00000000 */   nop   
/* 0E2ED0 7F0AE3A0 26310001 */  addiu $s1, $s1, 1
/* 0E2ED4 7F0AE3A4 5632FFEB */  bnel  $s1, $s2, .L7F0AE354
/* 0E2ED8 7F0AE3A8 2410FFFF */   li    $s0, -1
/* 0E2EDC 7F0AE3AC 8FA20080 */  lw    $v0, 0x80($sp)
/* 0E2EE0 7F0AE3B0 3C09FA00 */  lui   $t1, 0xfa00
/* 0E2EE4 7F0AE3B4 AE690000 */  sw    $t1, ($s3)
/* 0E2EE8 7F0AE3B8 00026E02 */  srl   $t5, $v0, 0x18
/* 0E2EEC 7F0AE3BC 00025C02 */  srl   $t3, $v0, 0x10
/* 0E2EF0 7F0AE3C0 317900FF */  andi  $t9, $t3, 0xff
/* 0E2EF4 7F0AE3C4 000D7600 */  sll   $t6, $t5, 0x18
/* 0E2EF8 7F0AE3C8 00196400 */  sll   $t4, $t9, 0x10
/* 0E2EFC 7F0AE3CC 00027A02 */  srl   $t7, $v0, 8
/* 0E2F00 7F0AE3D0 31ED00FF */  andi  $t5, $t7, 0xff
/* 0E2F04 7F0AE3D4 01CC4825 */  or    $t1, $t6, $t4
/* 0E2F08 7F0AE3D8 000DC200 */  sll   $t8, $t5, 8
/* 0E2F0C 7F0AE3DC 01385825 */  or    $t3, $t1, $t8
/* 0E2F10 7F0AE3E0 304E00FF */  andi  $t6, $v0, 0xff
/* 0E2F14 7F0AE3E4 016E6025 */  or    $t4, $t3, $t6
/* 0E2F18 7F0AE3E8 AE6C0004 */  sw    $t4, 4($s3)
/* 0E2F1C 7F0AE3EC 00602825 */  move  $a1, $v1
/* 0E2F20 7F0AE3F0 26640008 */  addiu $a0, $s3, 8
/* 0E2F24 7F0AE3F4 AFB7001C */  sw    $s7, 0x1c($sp)
/* 0E2F28 7F0AE3F8 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E2F2C 7F0AE3FC AFB50014 */  sw    $s5, 0x14($sp)
/* 0E2F30 7F0AE400 AFB40010 */  sw    $s4, 0x10($sp)
/* 0E2F34 7F0AE404 8FA60050 */  lw    $a2, 0x50($sp)
/* 0E2F38 7F0AE408 0FC2B917 */  jal   sub_GAME_7F0AE45C
/* 0E2F3C 7F0AE40C 03C03825 */   move  $a3, $fp
/* 0E2F40 7F0AE410 00409825 */  move  $s3, $v0
.L7F0AE414:
/* 0E2F44 7F0AE414 8FA50064 */  lw    $a1, 0x64($sp)
.L7F0AE418:
/* 0E2F48 7F0AE418 8FCF000C */  lw    $t7, 0xc($fp)
/* 0E2F4C 7F0AE41C 02601025 */  move  $v0, $s3
/* 0E2F50 7F0AE420 8CAA0000 */  lw    $t2, ($a1)
/* 0E2F54 7F0AE424 014F6821 */  addu  $t5, $t2, $t7
/* 0E2F58 7F0AE428 ACAD0000 */  sw    $t5, ($a1)
/* 0E2F5C 7F0AE42C 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0E2F60 7F0AE430 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0E2F64 7F0AE434 8FB70044 */  lw    $s7, 0x44($sp)
/* 0E2F68 7F0AE438 8FB60040 */  lw    $s6, 0x40($sp)
/* 0E2F6C 7F0AE43C 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0E2F70 7F0AE440 8FB40038 */  lw    $s4, 0x38($sp)
/* 0E2F74 7F0AE444 8FB30034 */  lw    $s3, 0x34($sp)
/* 0E2F78 7F0AE448 8FB20030 */  lw    $s2, 0x30($sp)
/* 0E2F7C 7F0AE44C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0E2F80 7F0AE450 8FB00028 */  lw    $s0, 0x28($sp)
/* 0E2F84 7F0AE454 03E00008 */  jr    $ra
/* 0E2F88 7F0AE458 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0AE45C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AE45C
/* 0E2F8C 7F0AE45C 8CEE000C */  lw    $t6, 0xc($a3)
/* 0E2F90 7F0AE460 8FAF0010 */  lw    $t7, 0x10($sp)
/* 0E2F94 7F0AE464 8FB80018 */  lw    $t8, 0x18($sp)
/* 0E2F98 7F0AE468 01C51021 */  addu  $v0, $t6, $a1
/* 0E2F9C 7F0AE46C 01F8C821 */  addu  $t9, $t7, $t8
/* 0E2FA0 7F0AE470 0322082A */  slt   $at, $t9, $v0
/* 0E2FA4 7F0AE474 1420009B */  bnez  $at, .L7F0AE6E4
/* 0E2FA8 7F0AE478 00000000 */   nop   
/* 0E2FAC 7F0AE47C 8CE30004 */  lw    $v1, 4($a3)
/* 0E2FB0 7F0AE480 8FA90014 */  lw    $t1, 0x14($sp)
/* 0E2FB4 7F0AE484 8FAC001C */  lw    $t4, 0x1c($sp)
/* 0E2FB8 7F0AE488 00664021 */  addu  $t0, $v1, $a2
/* 0E2FBC 7F0AE48C 0109082A */  slt   $at, $t0, $t1
/* 0E2FC0 7F0AE490 5420006E */  bnezl $at, .L7F0AE64C
/* 0E2FC4 7F0AE494 8CEF0008 */   lw    $t7, 8($a3)
/* 0E2FC8 7F0AE498 8CED0008 */  lw    $t5, 8($a3)
/* 0E2FCC 7F0AE49C 012C5021 */  addu  $t2, $t1, $t4
/* 0E2FD0 7F0AE4A0 3C0E8004 */  lui   $t6, %hi(text_orientation) 
/* 0E2FD4 7F0AE4A4 010D5821 */  addu  $t3, $t0, $t5
/* 0E2FD8 7F0AE4A8 014B082A */  slt   $at, $t2, $t3
/* 0E2FDC 7F0AE4AC 54200047 */  bnezl $at, .L7F0AE5CC
/* 0E2FE0 7F0AE4B0 0148082A */   slt   $at, $t2, $t0
/* 0E2FE4 7F0AE4B4 8DCE0E88 */  lw    $t6, %lo(text_orientation)($t6)
/* 0E2FE8 7F0AE4B8 0002C080 */  sll   $t8, $v0, 2
/* 0E2FEC 7F0AE4BC 330C0FFF */  andi  $t4, $t8, 0xfff
/* 0E2FF0 7F0AE4C0 11C00026 */  beqz  $t6, .L7F0AE55C
/* 0E2FF4 7F0AE4C4 24880008 */   addiu $t0, $a0, 8
/* 0E2FF8 7F0AE4C8 00C37823 */  subu  $t7, $a2, $v1
/* 0E2FFC 7F0AE4CC 000FC080 */  sll   $t8, $t7, 2
/* 0E3000 7F0AE4D0 33190FFF */  andi  $t9, $t8, 0xfff
/* 0E3004 7F0AE4D4 00196300 */  sll   $t4, $t9, 0xc
/* 0E3008 7F0AE4D8 3C01E500 */  lui   $at, 0xe500
/* 0E300C 7F0AE4DC 00027080 */  sll   $t6, $v0, 2
/* 0E3010 7F0AE4E0 31CF0FFF */  andi  $t7, $t6, 0xfff
/* 0E3014 7F0AE4E4 01816825 */  or    $t5, $t4, $at
/* 0E3018 7F0AE4E8 01AFC025 */  or    $t8, $t5, $t7
/* 0E301C 7F0AE4EC AC980000 */  sw    $t8, ($a0)
/* 0E3020 7F0AE4F0 8CF90004 */  lw    $t9, 4($a3)
/* 0E3024 7F0AE4F4 8CEE0008 */  lw    $t6, 8($a3)
/* 0E3028 7F0AE4F8 24890008 */  addiu $t1, $a0, 8
/* 0E302C 7F0AE4FC 00D96023 */  subu  $t4, $a2, $t9
/* 0E3030 7F0AE500 018E6823 */  subu  $t5, $t4, $t6
/* 0E3034 7F0AE504 000D7880 */  sll   $t7, $t5, 2
/* 0E3038 7F0AE508 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0E303C 7F0AE50C 00056080 */  sll   $t4, $a1, 2
/* 0E3040 7F0AE510 318E0FFF */  andi  $t6, $t4, 0xfff
/* 0E3044 7F0AE514 0018CB00 */  sll   $t9, $t8, 0xc
/* 0E3048 7F0AE518 032E6825 */  or    $t5, $t9, $t6
/* 0E304C 7F0AE51C AC8D0004 */  sw    $t5, 4($a0)
/* 0E3050 7F0AE520 3C0FB400 */  lui   $t7, 0xb400
/* 0E3054 7F0AE524 AD2F0000 */  sw    $t7, ($t1)
/* 0E3058 7F0AE528 8CF80008 */  lw    $t8, 8($a3)
/* 0E305C 7F0AE52C 3C0F0400 */  lui   $t7, (0x0400FC00 >> 16) # lui $t7, 0x400
/* 0E3060 7F0AE530 252A0008 */  addiu $t2, $t1, 8
/* 0E3064 7F0AE534 270CFFFF */  addiu $t4, $t8, -1
/* 0E3068 7F0AE538 000CC940 */  sll   $t9, $t4, 5
/* 0E306C 7F0AE53C 332EFFFF */  andi  $t6, $t9, 0xffff
/* 0E3070 7F0AE540 AD2E0004 */  sw    $t6, 4($t1)
/* 0E3074 7F0AE544 35EFFC00 */  ori   $t7, (0x0400FC00 & 0xFFFF) # ori $t7, $t7, 0xfc00
/* 0E3078 7F0AE548 3C0DB300 */  lui   $t5, 0xb300
/* 0E307C 7F0AE54C AD4D0000 */  sw    $t5, ($t2)
/* 0E3080 7F0AE550 AD4F0004 */  sw    $t7, 4($t2)
/* 0E3084 7F0AE554 03E00008 */  jr    $ra
/* 0E3088 7F0AE558 25420008 */   addiu $v0, $t2, 8

.L7F0AE55C:
/* 0E308C 7F0AE55C 000CCB00 */  sll   $t9, $t4, 0xc
/* 0E3090 7F0AE560 3C01E400 */  lui   $at, 0xe400
/* 0E3094 7F0AE564 000B6880 */  sll   $t5, $t3, 2
/* 0E3098 7F0AE568 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E309C 7F0AE56C 03217025 */  or    $t6, $t9, $at
/* 0E30A0 7F0AE570 01CFC025 */  or    $t8, $t6, $t7
/* 0E30A4 7F0AE574 AC980000 */  sw    $t8, ($a0)
/* 0E30A8 7F0AE578 8CEE0004 */  lw    $t6, 4($a3)
/* 0E30AC 7F0AE57C 00056080 */  sll   $t4, $a1, 2
/* 0E30B0 7F0AE580 31990FFF */  andi  $t9, $t4, 0xfff
/* 0E30B4 7F0AE584 00CE7821 */  addu  $t7, $a2, $t6
/* 0E30B8 7F0AE588 000FC080 */  sll   $t8, $t7, 2
/* 0E30BC 7F0AE58C 330C0FFF */  andi  $t4, $t8, 0xfff
/* 0E30C0 7F0AE590 00196B00 */  sll   $t5, $t9, 0xc
/* 0E30C4 7F0AE594 01ACC825 */  or    $t9, $t5, $t4
/* 0E30C8 7F0AE598 AC990004 */  sw    $t9, 4($a0)
/* 0E30CC 7F0AE59C 3C180400 */  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
/* 0E30D0 7F0AE5A0 3C0EB400 */  lui   $t6, 0xb400
/* 0E30D4 7F0AE5A4 25090008 */  addiu $t1, $t0, 8
/* 0E30D8 7F0AE5A8 AD0E0000 */  sw    $t6, ($t0)
/* 0E30DC 7F0AE5AC 37180400 */  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
/* 0E30E0 7F0AE5B0 AD000004 */  sw    $zero, 4($t0)
/* 0E30E4 7F0AE5B4 3C0FB300 */  lui   $t7, 0xb300
/* 0E30E8 7F0AE5B8 AD2F0000 */  sw    $t7, ($t1)
/* 0E30EC 7F0AE5BC AD380004 */  sw    $t8, 4($t1)
/* 0E30F0 7F0AE5C0 03E00008 */  jr    $ra
/* 0E30F4 7F0AE5C4 25220008 */   addiu $v0, $t1, 8

/* 0E30F8 7F0AE5C8 0148082A */  slt   $at, $t2, $t0
.L7F0AE5CC:
/* 0E30FC 7F0AE5CC 14200045 */  bnez  $at, .L7F0AE6E4
/* 0E3100 7F0AE5D0 24880008 */   addiu $t0, $a0, 8
/* 0E3104 7F0AE5D4 00026880 */  sll   $t5, $v0, 2
/* 0E3108 7F0AE5D8 31AC0FFF */  andi  $t4, $t5, 0xfff
/* 0E310C 7F0AE5DC 000CCB00 */  sll   $t9, $t4, 0xc
/* 0E3110 7F0AE5E0 3C01E400 */  lui   $at, 0xe400
/* 0E3114 7F0AE5E4 000A7880 */  sll   $t7, $t2, 2
/* 0E3118 7F0AE5E8 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0E311C 7F0AE5EC 03217025 */  or    $t6, $t9, $at
/* 0E3120 7F0AE5F0 01D86825 */  or    $t5, $t6, $t8
/* 0E3124 7F0AE5F4 AC8D0000 */  sw    $t5, ($a0)
/* 0E3128 7F0AE5F8 8CEE0004 */  lw    $t6, 4($a3)
/* 0E312C 7F0AE5FC 00056080 */  sll   $t4, $a1, 2
/* 0E3130 7F0AE600 31990FFF */  andi  $t9, $t4, 0xfff
/* 0E3134 7F0AE604 00CEC021 */  addu  $t8, $a2, $t6
/* 0E3138 7F0AE608 00186880 */  sll   $t5, $t8, 2
/* 0E313C 7F0AE60C 31AC0FFF */  andi  $t4, $t5, 0xfff
/* 0E3140 7F0AE610 00197B00 */  sll   $t7, $t9, 0xc
/* 0E3144 7F0AE614 01ECC825 */  or    $t9, $t7, $t4
/* 0E3148 7F0AE618 AC990004 */  sw    $t9, 4($a0)
/* 0E314C 7F0AE61C 3C0D0400 */  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
/* 0E3150 7F0AE620 3C0EB400 */  lui   $t6, 0xb400
/* 0E3154 7F0AE624 25090008 */  addiu $t1, $t0, 8
/* 0E3158 7F0AE628 AD0E0000 */  sw    $t6, ($t0)
/* 0E315C 7F0AE62C 35AD0400 */  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
/* 0E3160 7F0AE630 AD000004 */  sw    $zero, 4($t0)
/* 0E3164 7F0AE634 3C18B300 */  lui   $t8, 0xb300
/* 0E3168 7F0AE638 AD380000 */  sw    $t8, ($t1)
/* 0E316C 7F0AE63C AD2D0004 */  sw    $t5, 4($t1)
/* 0E3170 7F0AE640 03E00008 */  jr    $ra
/* 0E3174 7F0AE644 25220008 */   addiu $v0, $t1, 8

/* 0E3178 7F0AE648 8CEF0008 */  lw    $t7, 8($a3)
.L7F0AE64C:
/* 0E317C 7F0AE64C 00026080 */  sll   $t4, $v0, 2
/* 0E3180 7F0AE650 31990FFF */  andi  $t9, $t4, 0xfff
/* 0E3184 7F0AE654 010F5821 */  addu  $t3, $t0, $t7
/* 0E3188 7F0AE658 0169082A */  slt   $at, $t3, $t1
/* 0E318C 7F0AE65C 14200021 */  bnez  $at, .L7F0AE6E4
/* 0E3190 7F0AE660 00801825 */   move  $v1, $a0
/* 0E3194 7F0AE664 00197300 */  sll   $t6, $t9, 0xc
/* 0E3198 7F0AE668 3C01E400 */  lui   $at, 0xe400
/* 0E319C 7F0AE66C 000B6880 */  sll   $t5, $t3, 2
/* 0E31A0 7F0AE670 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E31A4 7F0AE674 01C1C025 */  or    $t8, $t6, $at
/* 0E31A8 7F0AE678 030F6025 */  or    $t4, $t8, $t7
/* 0E31AC 7F0AE67C 0005C880 */  sll   $t9, $a1, 2
/* 0E31B0 7F0AE680 332E0FFF */  andi  $t6, $t9, 0xfff
/* 0E31B4 7F0AE684 0009C080 */  sll   $t8, $t1, 2
/* 0E31B8 7F0AE688 330F0FFF */  andi  $t7, $t8, 0xfff
/* 0E31BC 7F0AE68C 000E6B00 */  sll   $t5, $t6, 0xc
/* 0E31C0 7F0AE690 AC6C0000 */  sw    $t4, ($v1)
/* 0E31C4 7F0AE694 01AF6025 */  or    $t4, $t5, $t7
/* 0E31C8 7F0AE698 24840008 */  addiu $a0, $a0, 8
/* 0E31CC 7F0AE69C 00804025 */  move  $t0, $a0
/* 0E31D0 7F0AE6A0 AC6C0004 */  sw    $t4, 4($v1)
/* 0E31D4 7F0AE6A4 3C19B400 */  lui   $t9, 0xb400
/* 0E31D8 7F0AE6A8 AD190000 */  sw    $t9, ($t0)
/* 0E31DC 7F0AE6AC 8CEE0004 */  lw    $t6, 4($a3)
/* 0E31E0 7F0AE6B0 24840008 */  addiu $a0, $a0, 8
/* 0E31E4 7F0AE6B4 00805025 */  move  $t2, $a0
/* 0E31E8 7F0AE6B8 012EC023 */  subu  $t8, $t1, $t6
/* 0E31EC 7F0AE6BC 03066823 */  subu  $t5, $t8, $a2
/* 0E31F0 7F0AE6C0 000D7940 */  sll   $t7, $t5, 5
/* 0E31F4 7F0AE6C4 31ECFFFF */  andi  $t4, $t7, 0xffff
/* 0E31F8 7F0AE6C8 AD0C0004 */  sw    $t4, 4($t0)
/* 0E31FC 7F0AE6CC 3C0E0400 */  lui   $t6, (0x04000400 >> 16) # lui $t6, 0x400
/* 0E3200 7F0AE6D0 35CE0400 */  ori   $t6, (0x04000400 & 0xFFFF) # ori $t6, $t6, 0x400
/* 0E3204 7F0AE6D4 3C19B300 */  lui   $t9, 0xb300
/* 0E3208 7F0AE6D8 AD590000 */  sw    $t9, ($t2)
/* 0E320C 7F0AE6DC AD4E0004 */  sw    $t6, 4($t2)
/* 0E3210 7F0AE6E0 24840008 */  addiu $a0, $a0, 8
.L7F0AE6E4:
/* 0E3214 7F0AE6E4 03E00008 */  jr    $ra
/* 0E3218 7F0AE6E8 00801025 */   move  $v0, $a0
)
#endif





#ifdef NONMATCHING
void jp_text_write_stuff(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel jp_text_write_stuff
/* 0E321C 7F0AE6EC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0E3220 7F0AE6F0 240E0001 */  li    $t6, 1
/* 0E3224 7F0AE6F4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E3228 7F0AE6F8 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 0E322C 7F0AE6FC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0E3230 7F0AE700 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0E3234 7F0AE704 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0E3238 7F0AE708 AFB60058 */  sw    $s6, 0x58($sp)
/* 0E323C 7F0AE70C AFB50054 */  sw    $s5, 0x54($sp)
/* 0E3240 7F0AE710 AFB40050 */  sw    $s4, 0x50($sp)
/* 0E3244 7F0AE714 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0E3248 7F0AE718 AFB20048 */  sw    $s2, 0x48($sp)
/* 0E324C 7F0AE71C AFB10044 */  sw    $s1, 0x44($sp)
/* 0E3250 7F0AE720 AFB00040 */  sw    $s0, 0x40($sp)
/* 0E3254 7F0AE724 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E3258 7F0AE728 8CCF0000 */  lw    $t7, ($a2)
/* 0E325C 7F0AE72C 8CB60000 */  lw    $s6, ($a1)
/* 0E3260 7F0AE730 00E08025 */  move  $s0, $a3
/* 0E3264 7F0AE734 00A08825 */  move  $s1, $a1
/* 0E3268 7F0AE738 00C09825 */  move  $s3, $a2
/* 0E326C 7F0AE73C 0080A825 */  move  $s5, $a0
/* 0E3270 7F0AE740 24140048 */  li    $s4, 72
/* 0E3274 7F0AE744 17000006 */  bnez  $t8, .L7F0AE760
/* 0E3278 7F0AE748 AFAF0090 */   sw    $t7, 0x90($sp)
/* 0E327C 7F0AE74C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0E3280 7F0AE750 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E3284 7F0AE754 8F290890 */  lw    $t1, 0x890($t9)
/* 0E3288 7F0AE758 01095021 */  addu  $t2, $t0, $t1
/* 0E328C 7F0AE75C AFAA00C4 */  sw    $t2, 0xc4($sp)
.L7F0AE760:
/* 0E3290 7F0AE760 3C0B8005 */  lui   $t3, %hi(j_text_trigger) 
/* 0E3294 7F0AE764 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E3298 7F0AE768 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0E329C 7F0AE76C 27B20074 */  addiu $s2, $sp, 0x74
/* 0E32A0 7F0AE770 11600004 */  beqz  $t3, .L7F0AE784
/* 0E32A4 7F0AE774 2981000E */   slti  $at, $t4, 0xe
/* 0E32A8 7F0AE778 10200002 */  beqz  $at, .L7F0AE784
/* 0E32AC 7F0AE77C 240D000E */   li    $t5, 14
/* 0E32B0 7F0AE780 AFAD00C4 */  sw    $t5, 0xc4($sp)
.L7F0AE784:
/* 0E32B4 7F0AE784 92020000 */  lbu   $v0, ($s0)
/* 0E32B8 7F0AE788 8FBE00B0 */  lw    $fp, 0xb0($sp)
/* 0E32BC 7F0AE78C 8FB700AC */  lw    $s7, 0xac($sp)
/* 0E32C0 7F0AE790 10400071 */  beqz  $v0, .L7F0AE958
/* 0E32C4 7F0AE794 24010020 */   li    $at, 32
.L7F0AE798:
/* 0E32C8 7F0AE798 54410008 */  bnel  $v0, $at, .L7F0AE7BC
/* 0E32CC 7F0AE79C 2401000A */   li    $at, 10
/* 0E32D0 7F0AE7A0 8E2E0000 */  lw    $t6, ($s1)
/* 0E32D4 7F0AE7A4 24140048 */  li    $s4, 72
/* 0E32D8 7F0AE7A8 26100001 */  addiu $s0, $s0, 1
/* 0E32DC 7F0AE7AC 25CF0005 */  addiu $t7, $t6, 5
/* 0E32E0 7F0AE7B0 10000066 */  b     .L7F0AE94C
/* 0E32E4 7F0AE7B4 AE2F0000 */   sw    $t7, ($s1)
/* 0E32E8 7F0AE7B8 2401000A */  li    $at, 10
.L7F0AE7BC:
/* 0E32EC 7F0AE7BC 5441000A */  bnel  $v0, $at, .L7F0AE7E8
/* 0E32F0 7F0AE7C0 28410080 */   slti  $at, $v0, 0x80
/* 0E32F4 7F0AE7C4 AE360000 */  sw    $s6, ($s1)
/* 0E32F8 7F0AE7C8 8E780000 */  lw    $t8, ($s3)
/* 0E32FC 7F0AE7CC 8FB900C4 */  lw    $t9, 0xc4($sp)
/* 0E3300 7F0AE7D0 24140048 */  li    $s4, 72
/* 0E3304 7F0AE7D4 26100001 */  addiu $s0, $s0, 1
/* 0E3308 7F0AE7D8 03194021 */  addu  $t0, $t8, $t9
/* 0E330C 7F0AE7DC 1000005B */  b     .L7F0AE94C
/* 0E3310 7F0AE7E0 AE680000 */   sw    $t0, ($s3)
/* 0E3314 7F0AE7E4 28410080 */  slti  $at, $v0, 0x80
.L7F0AE7E8:
/* 0E3318 7F0AE7E8 10200021 */  beqz  $at, .L7F0AE870
/* 0E331C 7F0AE7EC 3C0E8004 */   lui   $t6, %hi(D_80040F14)
/* 0E3320 7F0AE7F0 24030018 */  li    $v1, 24
/* 0E3324 7F0AE7F4 00430019 */  multu $v0, $v1
/* 0E3328 7F0AE7F8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0E332C 7F0AE7FC 8FAE0090 */  lw    $t6, 0x90($sp)
/* 0E3330 7F0AE800 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0E3334 7F0AE804 8FB800B8 */  lw    $t8, 0xb8($sp)
/* 0E3338 7F0AE808 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0E333C 7F0AE80C 8FA800C0 */  lw    $t0, 0xc0($sp)
/* 0E3340 7F0AE810 02A02025 */  move  $a0, $s5
/* 0E3344 7F0AE814 02202825 */  move  $a1, $s1
/* 0E3348 7F0AE818 02603025 */  move  $a2, $s3
/* 0E334C 7F0AE81C 00004812 */  mflo  $t1
/* 0E3350 7F0AE820 012A3821 */  addu  $a3, $t1, $t2
/* 0E3354 7F0AE824 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E3358 7F0AE828 02830019 */  multu $s4, $v1
/* 0E335C 7F0AE82C AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3360 7F0AE830 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3364 7F0AE834 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E3368 7F0AE838 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0E336C 7F0AE83C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0E3370 7F0AE840 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E3374 7F0AE844 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0E3378 7F0AE848 AFA80030 */  sw    $t0, 0x30($sp)
/* 0E337C 7F0AE84C 00005812 */  mflo  $t3
/* 0E3380 7F0AE850 016A6021 */  addu  $t4, $t3, $t2
/* 0E3384 7F0AE854 258DFCE8 */  addiu $t5, $t4, -0x318
/* 0E3388 7F0AE858 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E338C 7F0AE85C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0E3390 7F0AE860 0040A825 */  move  $s5, $v0
/* 0E3394 7F0AE864 92140000 */  lbu   $s4, ($s0)
/* 0E3398 7F0AE868 10000038 */  b     .L7F0AE94C
/* 0E339C 7F0AE86C 26100001 */   addiu $s0, $s0, 1
.L7F0AE870:
/* 0E33A0 7F0AE870 25CE0F14 */  addiu $t6, $t6, %lo(D_80040F14)
/* 0E33A4 7F0AE874 8DC10000 */  lw    $at, ($t6)
/* 0E33A8 7F0AE878 92090001 */  lbu   $t1, 1($s0)
/* 0E33AC 7F0AE87C 304A007F */  andi  $t2, $v0, 0x7f
/* 0E33B0 7F0AE880 AE410000 */  sw    $at, ($s2)
/* 0E33B4 7F0AE884 8DD80004 */  lw    $t8, 4($t6)
/* 0E33B8 7F0AE888 000A61C0 */  sll   $t4, $t2, 7
/* 0E33BC 7F0AE88C 312B007F */  andi  $t3, $t1, 0x7f
/* 0E33C0 7F0AE890 AE580004 */  sw    $t8, 4($s2)
/* 0E33C4 7F0AE894 8DC10008 */  lw    $at, 8($t6)
/* 0E33C8 7F0AE898 016C1825 */  or    $v1, $t3, $t4
/* 0E33CC 7F0AE89C 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E33D0 7F0AE8A0 AE410008 */  sw    $at, 8($s2)
/* 0E33D4 7F0AE8A4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E33D8 7F0AE8A8 30992000 */  andi  $t9, $a0, 0x2000
/* 0E33DC 7F0AE8AC 308A1FFF */  andi  $t2, $a0, 0x1fff
/* 0E33E0 7F0AE8B0 AE58000C */  sw    $t8, 0xc($s2)
/* 0E33E4 7F0AE8B4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E33E8 7F0AE8B8 2408000F */  li    $t0, 15
/* 0E33EC 7F0AE8BC 24090010 */  li    $t1, 16
/* 0E33F0 7F0AE8C0 AE410010 */  sw    $at, 0x10($s2)
/* 0E33F4 7F0AE8C4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E33F8 7F0AE8C8 294103C7 */  slti  $at, $t2, 0x3c7
/* 0E33FC 7F0AE8CC 13200003 */  beqz  $t9, .L7F0AE8DC
/* 0E3400 7F0AE8D0 AE580014 */   sw    $t8, 0x14($s2)
/* 0E3404 7F0AE8D4 AFA80080 */  sw    $t0, 0x80($sp)
/* 0E3408 7F0AE8D8 AFA9007C */  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
/* 0E340C 7F0AE8DC 54200003 */  bnezl $at, .L7F0AE8EC
/* 0E3410 7F0AE8E0 248B0080 */   addiu $t3, $a0, 0x80
/* 0E3414 7F0AE8E4 24040002 */  li    $a0, 2
/* 0E3418 7F0AE8E8 248B0080 */  addiu $t3, $a0, 0x80
.L7F0AE8EC:
/* 0E341C 7F0AE8EC 0FC3068C */  jal   something_with_LnameX
/* 0E3420 7F0AE8F0 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0E3424 7F0AE8F4 8FAC0090 */  lw    $t4, 0x90($sp)
/* 0E3428 7F0AE8F8 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0E342C 7F0AE8FC 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 0E3430 7F0AE900 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0E3434 7F0AE904 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0E3438 7F0AE908 AFA20088 */  sw    $v0, 0x88($sp)
/* 0E343C 7F0AE90C 02A02025 */  move  $a0, $s5
/* 0E3440 7F0AE910 02202825 */  move  $a1, $s1
/* 0E3444 7F0AE914 02603025 */  move  $a2, $s3
/* 0E3448 7F0AE918 02403825 */  move  $a3, $s2
/* 0E344C 7F0AE91C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E3450 7F0AE920 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3454 7F0AE924 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3458 7F0AE928 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E345C 7F0AE92C AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E3460 7F0AE930 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E3464 7F0AE934 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0E3468 7F0AE938 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0E346C 7F0AE93C 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E3470 7F0AE940 AFB80030 */   sw    $t8, 0x30($sp)
/* 0E3474 7F0AE944 0040A825 */  move  $s5, $v0
/* 0E3478 7F0AE948 26100002 */  addiu $s0, $s0, 2
.L7F0AE94C:
/* 0E347C 7F0AE94C 92020000 */  lbu   $v0, ($s0)
/* 0E3480 7F0AE950 5440FF91 */  bnezl $v0, .L7F0AE798
/* 0E3484 7F0AE954 24010020 */   li    $at, 32
.L7F0AE958:
/* 0E3488 7F0AE958 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0E348C 7F0AE95C 02A01025 */  move  $v0, $s5
/* 0E3490 7F0AE960 8FB50054 */  lw    $s5, 0x54($sp)
/* 0E3494 7F0AE964 8FB00040 */  lw    $s0, 0x40($sp)
/* 0E3498 7F0AE968 8FB10044 */  lw    $s1, 0x44($sp)
/* 0E349C 7F0AE96C 8FB20048 */  lw    $s2, 0x48($sp)
/* 0E34A0 7F0AE970 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0E34A4 7F0AE974 8FB40050 */  lw    $s4, 0x50($sp)
/* 0E34A8 7F0AE978 8FB60058 */  lw    $s6, 0x58($sp)
/* 0E34AC 7F0AE97C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 0E34B0 7F0AE980 8FBE0060 */  lw    $fp, 0x60($sp)
/* 0E34B4 7F0AE984 03E00008 */  jr    $ra
/* 0E34B8 7F0AE988 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel jp_text_write_stuff
/* 0E321C 7F0AE6EC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0E3220 7F0AE6F0 240E0001 */  li    $t6, 1
/* 0E3224 7F0AE6F4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E3228 7F0AE6F8 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 0E322C 7F0AE6FC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0E3230 7F0AE700 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0E3234 7F0AE704 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0E3238 7F0AE708 AFB60058 */  sw    $s6, 0x58($sp)
/* 0E323C 7F0AE70C AFB50054 */  sw    $s5, 0x54($sp)
/* 0E3240 7F0AE710 AFB40050 */  sw    $s4, 0x50($sp)
/* 0E3244 7F0AE714 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0E3248 7F0AE718 AFB20048 */  sw    $s2, 0x48($sp)
/* 0E324C 7F0AE71C AFB10044 */  sw    $s1, 0x44($sp)
/* 0E3250 7F0AE720 AFB00040 */  sw    $s0, 0x40($sp)
/* 0E3254 7F0AE724 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E3258 7F0AE728 8CCF0000 */  lw    $t7, ($a2)
/* 0E325C 7F0AE72C 8CB60000 */  lw    $s6, ($a1)
/* 0E3260 7F0AE730 00E08025 */  move  $s0, $a3
/* 0E3264 7F0AE734 00A08825 */  move  $s1, $a1
/* 0E3268 7F0AE738 00C09825 */  move  $s3, $a2
/* 0E326C 7F0AE73C 0080A825 */  move  $s5, $a0
/* 0E3270 7F0AE740 24140048 */  li    $s4, 72
/* 0E3274 7F0AE744 17000006 */  bnez  $t8, .L7F0AE760
/* 0E3278 7F0AE748 AFAF0090 */   sw    $t7, 0x90($sp)
/* 0E327C 7F0AE74C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0E3280 7F0AE750 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E3284 7F0AE754 8F290890 */  lw    $t1, 0x890($t9)
/* 0E3288 7F0AE758 01095021 */  addu  $t2, $t0, $t1
/* 0E328C 7F0AE75C AFAA00C4 */  sw    $t2, 0xc4($sp)
.L7F0AE760:
/* 0E3290 7F0AE760 3C0B8005 */  lui   $t3, %hi(j_text_trigger) 
/* 0E3294 7F0AE764 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E3298 7F0AE768 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0E329C 7F0AE76C 27B20074 */  addiu $s2, $sp, 0x74
/* 0E32A0 7F0AE770 11600004 */  beqz  $t3, .L7F0AE784
/* 0E32A4 7F0AE774 2981000E */   slti  $at, $t4, 0xe
/* 0E32A8 7F0AE778 10200002 */  beqz  $at, .L7F0AE784
/* 0E32AC 7F0AE77C 240D000E */   li    $t5, 14
/* 0E32B0 7F0AE780 AFAD00C4 */  sw    $t5, 0xc4($sp)
.L7F0AE784:
/* 0E32B4 7F0AE784 92020000 */  lbu   $v0, ($s0)
/* 0E32B8 7F0AE788 8FBE00B0 */  lw    $fp, 0xb0($sp)
/* 0E32BC 7F0AE78C 8FB700AC */  lw    $s7, 0xac($sp)
/* 0E32C0 7F0AE790 10400071 */  beqz  $v0, .L7F0AE958
/* 0E32C4 7F0AE794 24010020 */   li    $at, 32
.L7F0AE798:
/* 0E32C8 7F0AE798 54410008 */  bnel  $v0, $at, .L7F0AE7BC
/* 0E32CC 7F0AE79C 2401000A */   li    $at, 10
/* 0E32D0 7F0AE7A0 8E2E0000 */  lw    $t6, ($s1)
/* 0E32D4 7F0AE7A4 24140048 */  li    $s4, 72
/* 0E32D8 7F0AE7A8 26100001 */  addiu $s0, $s0, 1
/* 0E32DC 7F0AE7AC 25CF0005 */  addiu $t7, $t6, 5
/* 0E32E0 7F0AE7B0 10000066 */  b     .L7F0AE94C
/* 0E32E4 7F0AE7B4 AE2F0000 */   sw    $t7, ($s1)
/* 0E32E8 7F0AE7B8 2401000A */  li    $at, 10
.L7F0AE7BC:
/* 0E32EC 7F0AE7BC 5441000A */  bnel  $v0, $at, .L7F0AE7E8
/* 0E32F0 7F0AE7C0 28410080 */   slti  $at, $v0, 0x80
/* 0E32F4 7F0AE7C4 AE360000 */  sw    $s6, ($s1)
/* 0E32F8 7F0AE7C8 8E780000 */  lw    $t8, ($s3)
/* 0E32FC 7F0AE7CC 8FB900C4 */  lw    $t9, 0xc4($sp)
/* 0E3300 7F0AE7D0 24140048 */  li    $s4, 72
/* 0E3304 7F0AE7D4 26100001 */  addiu $s0, $s0, 1
/* 0E3308 7F0AE7D8 03194021 */  addu  $t0, $t8, $t9
/* 0E330C 7F0AE7DC 1000005B */  b     .L7F0AE94C
/* 0E3310 7F0AE7E0 AE680000 */   sw    $t0, ($s3)
/* 0E3314 7F0AE7E4 28410080 */  slti  $at, $v0, 0x80
.L7F0AE7E8:
/* 0E3318 7F0AE7E8 10200021 */  beqz  $at, .L7F0AE870
/* 0E331C 7F0AE7EC 3C0E8004 */   lui   $t6, %hi(D_80040F14)
/* 0E3320 7F0AE7F0 24030018 */  li    $v1, 24
/* 0E3324 7F0AE7F4 00430019 */  multu $v0, $v1
/* 0E3328 7F0AE7F8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0E332C 7F0AE7FC 8FAE0090 */  lw    $t6, 0x90($sp)
/* 0E3330 7F0AE800 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0E3334 7F0AE804 8FB800B8 */  lw    $t8, 0xb8($sp)
/* 0E3338 7F0AE808 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0E333C 7F0AE80C 8FA800C0 */  lw    $t0, 0xc0($sp)
/* 0E3340 7F0AE810 02A02025 */  move  $a0, $s5
/* 0E3344 7F0AE814 02202825 */  move  $a1, $s1
/* 0E3348 7F0AE818 02603025 */  move  $a2, $s3
/* 0E334C 7F0AE81C 00004812 */  mflo  $t1
/* 0E3350 7F0AE820 012A3821 */  addu  $a3, $t1, $t2
/* 0E3354 7F0AE824 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E3358 7F0AE828 02830019 */  multu $s4, $v1
/* 0E335C 7F0AE82C AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3360 7F0AE830 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3364 7F0AE834 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E3368 7F0AE838 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0E336C 7F0AE83C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0E3370 7F0AE840 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E3374 7F0AE844 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0E3378 7F0AE848 AFA80030 */  sw    $t0, 0x30($sp)
/* 0E337C 7F0AE84C 00005812 */  mflo  $t3
/* 0E3380 7F0AE850 016A6021 */  addu  $t4, $t3, $t2
/* 0E3384 7F0AE854 258DFCE8 */  addiu $t5, $t4, -0x318
/* 0E3388 7F0AE858 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E338C 7F0AE85C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0E3390 7F0AE860 0040A825 */  move  $s5, $v0
/* 0E3394 7F0AE864 92140000 */  lbu   $s4, ($s0)
/* 0E3398 7F0AE868 10000038 */  b     .L7F0AE94C
/* 0E339C 7F0AE86C 26100001 */   addiu $s0, $s0, 1
.L7F0AE870:
/* 0E33A0 7F0AE870 25CE0F14 */  addiu $t6, $t6, %lo(D_80040F14)
/* 0E33A4 7F0AE874 8DC10000 */  lw    $at, ($t6)
/* 0E33A8 7F0AE878 92090001 */  lbu   $t1, 1($s0)
/* 0E33AC 7F0AE87C 304A007F */  andi  $t2, $v0, 0x7f
/* 0E33B0 7F0AE880 AE410000 */  sw    $at, ($s2)
/* 0E33B4 7F0AE884 8DD80004 */  lw    $t8, 4($t6)
/* 0E33B8 7F0AE888 000A61C0 */  sll   $t4, $t2, 7
/* 0E33BC 7F0AE88C 312B007F */  andi  $t3, $t1, 0x7f
/* 0E33C0 7F0AE890 AE580004 */  sw    $t8, 4($s2)
/* 0E33C4 7F0AE894 8DC10008 */  lw    $at, 8($t6)
/* 0E33C8 7F0AE898 016C1825 */  or    $v1, $t3, $t4
/* 0E33CC 7F0AE89C 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E33D0 7F0AE8A0 AE410008 */  sw    $at, 8($s2)
/* 0E33D4 7F0AE8A4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E33D8 7F0AE8A8 30992000 */  andi  $t9, $a0, 0x2000
/* 0E33DC 7F0AE8AC 308A1FFF */  andi  $t2, $a0, 0x1fff
/* 0E33E0 7F0AE8B0 AE58000C */  sw    $t8, 0xc($s2)
/* 0E33E4 7F0AE8B4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E33E8 7F0AE8B8 2408000F */  li    $t0, 15
/* 0E33EC 7F0AE8BC 24090010 */  li    $t1, 16
/* 0E33F0 7F0AE8C0 AE410010 */  sw    $at, 0x10($s2)
/* 0E33F4 7F0AE8C4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E33F8 7F0AE8C8 294103C7 */  slti  $at, $t2, 0x3c8
/* 0E33FC 7F0AE8CC 13200003 */  beqz  $t9, .L7F0AE8DC
/* 0E3400 7F0AE8D0 AE580014 */   sw    $t8, 0x14($s2)
/* 0E3404 7F0AE8D4 AFA80080 */  sw    $t0, 0x80($sp)
/* 0E3408 7F0AE8D8 AFA9007C */  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
/* 0E340C 7F0AE8DC 54200003 */  bnezl $at, .L7F0AE8EC
/* 0E3410 7F0AE8E0 248B0080 */   addiu $t3, $a0, 0x80
/* 0E3414 7F0AE8E4 24040002 */  li    $a0, 2
/* 0E3418 7F0AE8E8 248B0080 */  addiu $t3, $a0, 0x80
.L7F0AE8EC:
/* 0E341C 7F0AE8EC 0FC3068C */  jal   something_with_LnameX
/* 0E3420 7F0AE8F0 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0E3424 7F0AE8F4 8FAC0090 */  lw    $t4, 0x90($sp)
/* 0E3428 7F0AE8F8 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0E342C 7F0AE8FC 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 0E3430 7F0AE900 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0E3434 7F0AE904 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0E3438 7F0AE908 AFA20088 */  sw    $v0, 0x88($sp)
/* 0E343C 7F0AE90C 02A02025 */  move  $a0, $s5
/* 0E3440 7F0AE910 02202825 */  move  $a1, $s1
/* 0E3444 7F0AE914 02603025 */  move  $a2, $s3
/* 0E3448 7F0AE918 02403825 */  move  $a3, $s2
/* 0E344C 7F0AE91C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E3450 7F0AE920 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3454 7F0AE924 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3458 7F0AE928 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E345C 7F0AE92C AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E3460 7F0AE930 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E3464 7F0AE934 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0E3468 7F0AE938 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0E346C 7F0AE93C 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E3470 7F0AE940 AFB80030 */   sw    $t8, 0x30($sp)
/* 0E3474 7F0AE944 0040A825 */  move  $s5, $v0
/* 0E3478 7F0AE948 26100002 */  addiu $s0, $s0, 2
.L7F0AE94C:
/* 0E347C 7F0AE94C 92020000 */  lbu   $v0, ($s0)
/* 0E3480 7F0AE950 5440FF91 */  bnezl $v0, .L7F0AE798
/* 0E3484 7F0AE954 24010020 */   li    $at, 32
.L7F0AE958:
/* 0E3488 7F0AE958 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0E348C 7F0AE95C 02A01025 */  move  $v0, $s5
/* 0E3490 7F0AE960 8FB50054 */  lw    $s5, 0x54($sp)
/* 0E3494 7F0AE964 8FB00040 */  lw    $s0, 0x40($sp)
/* 0E3498 7F0AE968 8FB10044 */  lw    $s1, 0x44($sp)
/* 0E349C 7F0AE96C 8FB20048 */  lw    $s2, 0x48($sp)
/* 0E34A0 7F0AE970 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0E34A4 7F0AE974 8FB40050 */  lw    $s4, 0x50($sp)
/* 0E34A8 7F0AE978 8FB60058 */  lw    $s6, 0x58($sp)
/* 0E34AC 7F0AE97C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 0E34B0 7F0AE980 8FBE0060 */  lw    $fp, 0x60($sp)
/* 0E34B4 7F0AE984 03E00008 */  jr    $ra
/* 0E34B8 7F0AE988 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif
#endif




#ifdef NONMATCHING
void sub_GAME_7F0AE98C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AE98C
/* 0E34BC 7F0AE98C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E34C0 7F0AE990 AFB00008 */  sw    $s0, 8($sp)
/* 0E34C4 7F0AE994 8FB0002C */  lw    $s0, 0x2c($sp)
/* 0E34C8 7F0AE998 AFB30014 */  sw    $s3, 0x14($sp)
/* 0E34CC 7F0AE99C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E34D0 7F0AE9A0 AFB1000C */  sw    $s1, 0xc($sp)
/* 0E34D4 7F0AE9A4 AC800000 */  sw    $zero, ($a0)
/* 0E34D8 7F0AE9A8 24020048 */  li    $v0, 72
/* 0E34DC 7F0AE9AC 00004025 */  move  $t0, $zero
/* 0E34E0 7F0AE9B0 16000004 */  bnez  $s0, .L7F0AE9C4
/* 0E34E4 7F0AE9B4 ACA00000 */   sw    $zero, ($a1)
/* 0E34E8 7F0AE9B8 8CEE0890 */  lw    $t6, 0x890($a3)
/* 0E34EC 7F0AE9BC 8CEF088C */  lw    $t7, 0x88c($a3)
/* 0E34F0 7F0AE9C0 01CF8021 */  addu  $s0, $t6, $t7
.L7F0AE9C4:
/* 0E34F4 7F0AE9C4 3C188005 */  lui   $t8, %hi(j_text_trigger) 
/* 0E34F8 7F0AE9C8 8F1884D0 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0E34FC 7F0AE9CC 3C138004 */  lui   $s3, %hi(text_spacing)
/* 0E3500 7F0AE9D0 2A01000E */  slti  $at, $s0, 0xe
/* 0E3504 7F0AE9D4 13000004 */  beqz  $t8, .L7F0AE9E8
/* 0E3508 7F0AE9D8 26730E84 */   addiu $s3, %lo(text_spacing) # addiu $s3, $s3, 0xe84
/* 0E350C 7F0AE9DC 50200003 */  beql  $at, $zero, .L7F0AE9EC
/* 0E3510 7F0AE9E0 90C90000 */   lbu   $t1, ($a2)
/* 0E3514 7F0AE9E4 2410000E */  li    $s0, 14
.L7F0AE9E8:
/* 0E3518 7F0AE9E8 90C90000 */  lbu   $t1, ($a2)
.L7F0AE9EC:
/* 0E351C 7F0AE9EC 2412000D */  li    $s2, 13
/* 0E3520 7F0AE9F0 24110018 */  li    $s1, 24
/* 0E3524 7F0AE9F4 11200050 */  beqz  $t1, .L7F0AEB38
/* 0E3528 7F0AE9F8 240D000A */   li    $t5, 10
/* 0E352C 7F0AE9FC 240C0020 */  li    $t4, 32
/* 0E3530 7F0AEA00 8FAA0028 */  lw    $t2, 0x28($sp)
.L7F0AEA04:
/* 0E3534 7F0AEA04 1589000A */  bne   $t4, $t1, .L7F0AEA30
/* 0E3538 7F0AEA08 00000000 */   nop   
/* 0E353C 7F0AEA0C 90D90001 */  lbu   $t9, 1($a2)
/* 0E3540 7F0AEA10 24020048 */  li    $v0, 72
/* 0E3544 7F0AEA14 11B90004 */  beq   $t5, $t9, .L7F0AEA28
/* 0E3548 7F0AEA18 00000000 */   nop   
/* 0E354C 7F0AEA1C 8CAE0000 */  lw    $t6, ($a1)
/* 0E3550 7F0AEA20 25CF0005 */  addiu $t7, $t6, 5
/* 0E3554 7F0AEA24 ACAF0000 */  sw    $t7, ($a1)
.L7F0AEA28:
/* 0E3558 7F0AEA28 10000040 */  b     .L7F0AEB2C
/* 0E355C 7F0AEA2C 24C60001 */   addiu $a2, $a2, 1
.L7F0AEA30:
/* 0E3560 7F0AEA30 15A9000C */  bne   $t5, $t1, .L7F0AEA64
/* 0E3564 7F0AEA34 29210080 */   slti  $at, $t1, 0x80
/* 0E3568 7F0AEA38 8CA30000 */  lw    $v1, ($a1)
/* 0E356C 7F0AEA3C 0103082A */  slt   $at, $t0, $v1
/* 0E3570 7F0AEA40 50200003 */  beql  $at, $zero, .L7F0AEA50
/* 0E3574 7F0AEA44 ACA00000 */   sw    $zero, ($a1)
/* 0E3578 7F0AEA48 00604025 */  move  $t0, $v1
/* 0E357C 7F0AEA4C ACA00000 */  sw    $zero, ($a1)
.L7F0AEA50:
/* 0E3580 7F0AEA50 8C980000 */  lw    $t8, ($a0)
/* 0E3584 7F0AEA54 24C60001 */  addiu $a2, $a2, 1
/* 0E3588 7F0AEA58 0310C821 */  addu  $t9, $t8, $s0
/* 0E358C 7F0AEA5C 10000033 */  b     .L7F0AEB2C
/* 0E3590 7F0AEA60 AC990000 */   sw    $t9, ($a0)
.L7F0AEA64:
/* 0E3594 7F0AEA64 5020001C */  beql  $at, $zero, .L7F0AEAD8
/* 0E3598 7F0AEA68 292100C0 */   slti  $at, $t1, 0xc0
/* 0E359C 7F0AEA6C 01310019 */  multu $t1, $s1
/* 0E35A0 7F0AEA70 24C60001 */  addiu $a2, $a2, 1
/* 0E35A4 7F0AEA74 00007012 */  mflo  $t6
/* 0E35A8 7F0AEA78 00EE5821 */  addu  $t3, $a3, $t6
/* 0E35AC 7F0AEA7C 8D6FFCF8 */  lw    $t7, -0x308($t3)
/* 0E35B0 7F0AEA80 00510019 */  multu $v0, $s1
/* 0E35B4 7F0AEA84 000FC080 */  sll   $t8, $t7, 2
/* 0E35B8 7F0AEA88 0158C821 */  addu  $t9, $t2, $t8
/* 0E35BC 7F0AEA8C 00007012 */  mflo  $t6
/* 0E35C0 7F0AEA90 00EE7821 */  addu  $t7, $a3, $t6
/* 0E35C4 7F0AEA94 8DF8FCF8 */  lw    $t8, -0x308($t7)
/* 0E35C8 7F0AEA98 03120019 */  multu $t8, $s2
/* 0E35CC 7F0AEA9C 00007012 */  mflo  $t6
/* 0E35D0 7F0AEAA0 000E7880 */  sll   $t7, $t6, 2
/* 0E35D4 7F0AEAA4 032FC021 */  addu  $t8, $t9, $t7
/* 0E35D8 7F0AEAA8 8F0E0000 */  lw    $t6, ($t8)
/* 0E35DC 7F0AEAAC 8E790000 */  lw    $t9, ($s3)
/* 0E35E0 7F0AEAB0 8D78FCF4 */  lw    $t8, -0x30c($t3)
/* 0E35E4 7F0AEAB4 8CAF0000 */  lw    $t7, ($a1)
/* 0E35E8 7F0AEAB8 01D91821 */  addu  $v1, $t6, $t9
/* 0E35EC 7F0AEABC 2463FFFF */  addiu $v1, $v1, -1
/* 0E35F0 7F0AEAC0 01F87021 */  addu  $t6, $t7, $t8
/* 0E35F4 7F0AEAC4 01C3C823 */  subu  $t9, $t6, $v1
/* 0E35F8 7F0AEAC8 ACB90000 */  sw    $t9, ($a1)
/* 0E35FC 7F0AEACC 10000017 */  b     .L7F0AEB2C
/* 0E3600 7F0AEAD0 90C2FFFF */   lbu   $v0, -1($a2)
/* 0E3604 7F0AEAD4 292100C0 */  slti  $at, $t1, 0xc0
.L7F0AEAD8:
/* 0E3608 7F0AEAD8 5020000C */  beql  $at, $zero, .L7F0AEB0C
/* 0E360C 7F0AEADC 8D580000 */   lw    $t8, ($t2)
/* 0E3610 7F0AEAE0 8D4F0000 */  lw    $t7, ($t2)
/* 0E3614 7F0AEAE4 8E780000 */  lw    $t8, ($s3)
/* 0E3618 7F0AEAE8 8CAE0000 */  lw    $t6, ($a1)
/* 0E361C 7F0AEAEC 24C60002 */  addiu $a2, $a2, 2
/* 0E3620 7F0AEAF0 01F81821 */  addu  $v1, $t7, $t8
/* 0E3624 7F0AEAF4 2463FFFF */  addiu $v1, $v1, -1
/* 0E3628 7F0AEAF8 01C3C823 */  subu  $t9, $t6, $v1
/* 0E362C 7F0AEAFC 272F000B */  addiu $t7, $t9, 0xb
/* 0E3630 7F0AEB00 1000000A */  b     .L7F0AEB2C
/* 0E3634 7F0AEB04 ACAF0000 */   sw    $t7, ($a1)
/* 0E3638 7F0AEB08 8D580000 */  lw    $t8, ($t2)
.L7F0AEB0C:
/* 0E363C 7F0AEB0C 8E6E0000 */  lw    $t6, ($s3)
/* 0E3640 7F0AEB10 8CB90000 */  lw    $t9, ($a1)
/* 0E3644 7F0AEB14 24C60002 */  addiu $a2, $a2, 2
/* 0E3648 7F0AEB18 030E1821 */  addu  $v1, $t8, $t6
/* 0E364C 7F0AEB1C 2463FFFF */  addiu $v1, $v1, -1
/* 0E3650 7F0AEB20 03237823 */  subu  $t7, $t9, $v1
/* 0E3654 7F0AEB24 25F8000F */  addiu $t8, $t7, 0xf
/* 0E3658 7F0AEB28 ACB80000 */  sw    $t8, ($a1)
.L7F0AEB2C:
/* 0E365C 7F0AEB2C 90C90000 */  lbu   $t1, ($a2)
/* 0E3660 7F0AEB30 1520FFB4 */  bnez  $t1, .L7F0AEA04
/* 0E3664 7F0AEB34 00000000 */   nop   
.L7F0AEB38:
/* 0E3668 7F0AEB38 8CAE0000 */  lw    $t6, ($a1)
/* 0E366C 7F0AEB3C 01C8082A */  slt   $at, $t6, $t0
/* 0E3670 7F0AEB40 50200003 */  beql  $at, $zero, .L7F0AEB50
/* 0E3674 7F0AEB44 8FB00008 */   lw    $s0, 8($sp)
/* 0E3678 7F0AEB48 ACA80000 */  sw    $t0, ($a1)
/* 0E367C 7F0AEB4C 8FB00008 */  lw    $s0, 8($sp)
.L7F0AEB50:
/* 0E3680 7F0AEB50 8FB1000C */  lw    $s1, 0xc($sp)
/* 0E3684 7F0AEB54 8FB20010 */  lw    $s2, 0x10($sp)
/* 0E3688 7F0AEB58 8FB30014 */  lw    $s3, 0x14($sp)
/* 0E368C 7F0AEB5C 03E00008 */  jr    $ra
/* 0E3690 7F0AEB60 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0AEB64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AEB64
/* 0E3694 7F0AEB64 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0E3698 7F0AEB68 AFB40030 */  sw    $s4, 0x30($sp)
/* 0E369C 7F0AEB6C AFB3002C */  sw    $s3, 0x2c($sp)
/* 0E36A0 7F0AEB70 AFB20028 */  sw    $s2, 0x28($sp)
/* 0E36A4 7F0AEB74 AFB00020 */  sw    $s0, 0x20($sp)
/* 0E36A8 7F0AEB78 00C08025 */  move  $s0, $a2
/* 0E36AC 7F0AEB7C 00A09025 */  move  $s2, $a1
/* 0E36B0 7F0AEB80 00E09825 */  move  $s3, $a3
/* 0E36B4 7F0AEB84 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0E36B8 7F0AEB88 AFB10024 */  sw    $s1, 0x24($sp)
/* 0E36BC 7F0AEB8C AFA40090 */  sw    $a0, 0x90($sp)
/* 0E36C0 7F0AEB90 00005825 */  move  $t3, $zero
/* 0E36C4 7F0AEB94 AFA0007C */  sw    $zero, 0x7c($sp)
/* 0E36C8 7F0AEB98 240D0001 */  li    $t5, 1
/* 0E36CC 7F0AEB9C 27B4004C */  addiu $s4, $sp, 0x4c
/* 0E36D0 7F0AEBA0 240A0018 */  li    $t2, 24
.L7F0AEBA4:
/* 0E36D4 7F0AEBA4 AFA00080 */  sw    $zero, 0x80($sp)
/* 0E36D8 7F0AEBA8 92440000 */  lbu   $a0, ($s2)
/* 0E36DC 7F0AEBAC 00008825 */  move  $s1, $zero
/* 0E36E0 7F0AEBB0 00001825 */  move  $v1, $zero
/* 0E36E4 7F0AEBB4 28810021 */  slti  $at, $a0, 0x21
/* 0E36E8 7F0AEBB8 1420001E */  bnez  $at, .L7F0AEC34
/* 0E36EC 7F0AEBBC 27A50080 */   addiu $a1, $sp, 0x80
/* 0E36F0 7F0AEBC0 27A2004C */  addiu $v0, $sp, 0x4c
/* 0E36F4 7F0AEBC4 A0440000 */  sb    $a0, ($v0)
.L7F0AEBC8:
/* 0E36F8 7F0AEBC8 924E0000 */  lbu   $t6, ($s2)
/* 0E36FC 7F0AEBCC 26520001 */  addiu $s2, $s2, 1
/* 0E3700 7F0AEBD0 26310001 */  addiu $s1, $s1, 1
/* 0E3704 7F0AEBD4 01CA0019 */  multu $t6, $t2
/* 0E3708 7F0AEBD8 904E0000 */  lbu   $t6, ($v0)
/* 0E370C 7F0AEBDC 24420001 */  addiu $v0, $v0, 1
/* 0E3710 7F0AEBE0 29C10080 */  slti  $at, $t6, 0x80
/* 0E3714 7F0AEBE4 00007812 */  mflo  $t7
/* 0E3718 7F0AEBE8 026FC021 */  addu  $t8, $s3, $t7
/* 0E371C 7F0AEBEC 8F19FCF4 */  lw    $t9, -0x30c($t8)
/* 0E3720 7F0AEBF0 1420000C */  bnez  $at, .L7F0AEC24
/* 0E3724 7F0AEBF4 00791821 */   addu  $v1, $v1, $t9
/* 0E3728 7F0AEBF8 924F0000 */  lbu   $t7, ($s2)
/* 0E372C 7F0AEBFC 26520001 */  addiu $s2, $s2, 1
/* 0E3730 7F0AEC00 26310001 */  addiu $s1, $s1, 1
/* 0E3734 7F0AEC04 A04F0000 */  sb    $t7, ($v0)
/* 0E3738 7F0AEC08 9258FFFF */  lbu   $t8, -1($s2)
/* 0E373C 7F0AEC0C 24420001 */  addiu $v0, $v0, 1
/* 0E3740 7F0AEC10 030A0019 */  multu $t8, $t2
/* 0E3744 7F0AEC14 0000C812 */  mflo  $t9
/* 0E3748 7F0AEC18 02797021 */  addu  $t6, $s3, $t9
/* 0E374C 7F0AEC1C 8DCFFCF4 */  lw    $t7, -0x30c($t6)
/* 0E3750 7F0AEC20 006F1821 */  addu  $v1, $v1, $t7
.L7F0AEC24:
/* 0E3754 7F0AEC24 92440000 */  lbu   $a0, ($s2)
/* 0E3758 7F0AEC28 28810021 */  slti  $at, $a0, 0x21
/* 0E375C 7F0AEC2C 5020FFE6 */  beql  $at, $zero, .L7F0AEBC8
/* 0E3760 7F0AEC30 A0440000 */   sb    $a0, ($v0)
.L7F0AEC34:
/* 0E3764 7F0AEC34 0291C021 */  addu  $t8, $s4, $s1
/* 0E3768 7F0AEC38 A3000000 */  sb    $zero, ($t8)
/* 0E376C 7F0AEC3C 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0E3770 7F0AEC40 AFAD0078 */  sw    $t5, 0x78($sp)
/* 0E3774 7F0AEC44 AFAB008C */  sw    $t3, 0x8c($sp)
/* 0E3778 7F0AEC48 AFA00014 */  sw    $zero, 0x14($sp)
/* 0E377C 7F0AEC4C 27A4007C */  addiu $a0, $sp, 0x7c
/* 0E3780 7F0AEC50 02803025 */  move  $a2, $s4
/* 0E3784 7F0AEC54 02603825 */  move  $a3, $s3
/* 0E3788 7F0AEC58 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0E378C 7F0AEC5C AFB90010 */   sw    $t9, 0x10($sp)
/* 0E3790 7F0AEC60 8FAB008C */  lw    $t3, 0x8c($sp)
/* 0E3794 7F0AEC64 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0E3798 7F0AEC68 8FAF0090 */  lw    $t7, 0x90($sp)
/* 0E379C 7F0AEC6C 3C088004 */  lui   $t0, %hi(text_wordwrap) 
/* 0E37A0 7F0AEC70 016E5821 */  addu  $t3, $t3, $t6
/* 0E37A4 7F0AEC74 01EB082A */  slt   $at, $t7, $t3
/* 0E37A8 7F0AEC78 25080E8C */  addiu $t0, %lo(text_wordwrap) # addiu $t0, $t0, 0xe8c
/* 0E37AC 7F0AEC7C 24090020 */  li    $t1, 32
/* 0E37B0 7F0AEC80 240A0018 */  li    $t2, 24
/* 0E37B4 7F0AEC84 240C000A */  li    $t4, 10
/* 0E37B8 7F0AEC88 14200003 */  bnez  $at, .L7F0AEC98
/* 0E37BC 7F0AEC8C 8FAD0078 */   lw    $t5, 0x78($sp)
/* 0E37C0 7F0AEC90 10000002 */  b     .L7F0AEC9C
/* 0E37C4 7F0AEC94 24040001 */   li    $a0, 1
.L7F0AEC98:
/* 0E37C8 7F0AEC98 00002025 */  move  $a0, $zero
.L7F0AEC9C:
/* 0E37CC 7F0AEC9C 92420000 */  lbu   $v0, ($s2)
/* 0E37D0 7F0AECA0 2401000A */  li    $at, 10
/* 0E37D4 7F0AECA4 5441002F */  bnel  $v0, $at, .L7F0AED64
/* 0E37D8 7F0AECA8 24010020 */   li    $at, 32
/* 0E37DC 7F0AECAC 1480000E */  bnez  $a0, .L7F0AECE8
/* 0E37E0 7F0AECB0 00001825 */   move  $v1, $zero
/* 0E37E4 7F0AECB4 A20C0000 */  sb    $t4, ($s0)
/* 0E37E8 7F0AECB8 8D180000 */  lw    $t8, ($t0)
/* 0E37EC 7F0AECBC 26100001 */  addiu $s0, $s0, 1
/* 0E37F0 7F0AECC0 1B000009 */  blez  $t8, .L7F0AECE8
/* 0E37F4 7F0AECC4 00000000 */   nop   
/* 0E37F8 7F0AECC8 A2090000 */  sb    $t1, ($s0)
.L7F0AECCC:
/* 0E37FC 7F0AECCC 8D190000 */  lw    $t9, ($t0)
/* 0E3800 7F0AECD0 24630001 */  addiu $v1, $v1, 1
/* 0E3804 7F0AECD4 26100001 */  addiu $s0, $s0, 1
/* 0E3808 7F0AECD8 0079082A */  slt   $at, $v1, $t9
/* 0E380C 7F0AECDC 5420FFFB */  bnezl $at, .L7F0AECCC
/* 0E3810 7F0AECE0 A2090000 */   sb    $t1, ($s0)
/* 0E3814 7F0AECE4 00001825 */  move  $v1, $zero
.L7F0AECE8:
/* 0E3818 7F0AECE8 1A20001A */  blez  $s1, .L7F0AED54
/* 0E381C 7F0AECEC 00005825 */   move  $t3, $zero
/* 0E3820 7F0AECF0 32250003 */  andi  $a1, $s1, 3
/* 0E3824 7F0AECF4 10A00009 */  beqz  $a1, .L7F0AED1C
/* 0E3828 7F0AECF8 00A02025 */   move  $a0, $a1
/* 0E382C 7F0AECFC 02831021 */  addu  $v0, $s4, $v1
.L7F0AED00:
/* 0E3830 7F0AED00 904E0000 */  lbu   $t6, ($v0)
/* 0E3834 7F0AED04 24630001 */  addiu $v1, $v1, 1
/* 0E3838 7F0AED08 26100001 */  addiu $s0, $s0, 1
/* 0E383C 7F0AED0C 24420001 */  addiu $v0, $v0, 1
/* 0E3840 7F0AED10 1483FFFB */  bne   $a0, $v1, .L7F0AED00
/* 0E3844 7F0AED14 A20EFFFF */   sb    $t6, -1($s0)
/* 0E3848 7F0AED18 1071000E */  beq   $v1, $s1, .L7F0AED54
.L7F0AED1C:
/* 0E384C 7F0AED1C 27AF004C */   addiu $t7, $sp, 0x4c
/* 0E3850 7F0AED20 022F2021 */  addu  $a0, $s1, $t7
/* 0E3854 7F0AED24 02831021 */  addu  $v0, $s4, $v1
.L7F0AED28:
/* 0E3858 7F0AED28 90580000 */  lbu   $t8, ($v0)
/* 0E385C 7F0AED2C 24420004 */  addiu $v0, $v0, 4
/* 0E3860 7F0AED30 26100004 */  addiu $s0, $s0, 4
/* 0E3864 7F0AED34 A218FFFC */  sb    $t8, -4($s0)
/* 0E3868 7F0AED38 9059FFFD */  lbu   $t9, -3($v0)
/* 0E386C 7F0AED3C A219FFFD */  sb    $t9, -3($s0)
/* 0E3870 7F0AED40 904EFFFE */  lbu   $t6, -2($v0)
/* 0E3874 7F0AED44 A20EFFFE */  sb    $t6, -2($s0)
/* 0E3878 7F0AED48 904FFFFF */  lbu   $t7, -1($v0)
/* 0E387C 7F0AED4C 1444FFF6 */  bne   $v0, $a0, .L7F0AED28
/* 0E3880 7F0AED50 A20FFFFF */   sb    $t7, -1($s0)
.L7F0AED54:
/* 0E3884 7F0AED54 A20C0000 */  sb    $t4, ($s0)
/* 0E3888 7F0AED58 10000061 */  b     .L7F0AEEE0
/* 0E388C 7F0AED5C 26100001 */   addiu $s0, $s0, 1
/* 0E3890 7F0AED60 24010020 */  li    $at, 32
.L7F0AED64:
/* 0E3894 7F0AED64 14410032 */  bne   $v0, $at, .L7F0AEE30
/* 0E3898 7F0AED68 00000000 */   nop   
/* 0E389C 7F0AED6C 14800012 */  bnez  $a0, .L7F0AEDB8
/* 0E38A0 7F0AED70 00001825 */   move  $v1, $zero
/* 0E38A4 7F0AED74 A20C0000 */  sb    $t4, ($s0)
/* 0E38A8 7F0AED78 8D020000 */  lw    $v0, ($t0)
/* 0E38AC 7F0AED7C 26100001 */  addiu $s0, $s0, 1
/* 0E38B0 7F0AED80 5840000A */  blezl $v0, .L7F0AEDAC
/* 0E38B4 7F0AED84 8FB90080 */   lw    $t9, 0x80($sp)
/* 0E38B8 7F0AED88 A2090000 */  sb    $t1, ($s0)
.L7F0AED8C:
/* 0E38BC 7F0AED8C 8D020000 */  lw    $v0, ($t0)
/* 0E38C0 7F0AED90 24630001 */  addiu $v1, $v1, 1
/* 0E38C4 7F0AED94 26100001 */  addiu $s0, $s0, 1
/* 0E38C8 7F0AED98 0062082A */  slt   $at, $v1, $v0
/* 0E38CC 7F0AED9C 5420FFFB */  bnezl $at, .L7F0AED8C
/* 0E38D0 7F0AEDA0 A2090000 */   sb    $t1, ($s0)
/* 0E38D4 7F0AEDA4 00001825 */  move  $v1, $zero
/* 0E38D8 7F0AEDA8 8FB90080 */  lw    $t9, 0x80($sp)
.L7F0AEDAC:
/* 0E38DC 7F0AEDAC 0002C080 */  sll   $t8, $v0, 2
/* 0E38E0 7F0AEDB0 0302C021 */  addu  $t8, $t8, $v0
/* 0E38E4 7F0AEDB4 03195821 */  addu  $t3, $t8, $t9
.L7F0AEDB8:
/* 0E38E8 7F0AEDB8 1A20001A */  blez  $s1, .L7F0AEE24
/* 0E38EC 7F0AEDBC 256B0005 */   addiu $t3, $t3, 5
/* 0E38F0 7F0AEDC0 32250003 */  andi  $a1, $s1, 3
/* 0E38F4 7F0AEDC4 10A00009 */  beqz  $a1, .L7F0AEDEC
/* 0E38F8 7F0AEDC8 00A02025 */   move  $a0, $a1
/* 0E38FC 7F0AEDCC 02831021 */  addu  $v0, $s4, $v1
.L7F0AEDD0:
/* 0E3900 7F0AEDD0 904E0000 */  lbu   $t6, ($v0)
/* 0E3904 7F0AEDD4 24630001 */  addiu $v1, $v1, 1
/* 0E3908 7F0AEDD8 26100001 */  addiu $s0, $s0, 1
/* 0E390C 7F0AEDDC 24420001 */  addiu $v0, $v0, 1
/* 0E3910 7F0AEDE0 1483FFFB */  bne   $a0, $v1, .L7F0AEDD0
/* 0E3914 7F0AEDE4 A20EFFFF */   sb    $t6, -1($s0)
/* 0E3918 7F0AEDE8 1071000E */  beq   $v1, $s1, .L7F0AEE24
.L7F0AEDEC:
/* 0E391C 7F0AEDEC 27AF004C */   addiu $t7, $sp, 0x4c
/* 0E3920 7F0AEDF0 022F2021 */  addu  $a0, $s1, $t7
/* 0E3924 7F0AEDF4 02831021 */  addu  $v0, $s4, $v1
.L7F0AEDF8:
/* 0E3928 7F0AEDF8 90580000 */  lbu   $t8, ($v0)
/* 0E392C 7F0AEDFC 24420004 */  addiu $v0, $v0, 4
/* 0E3930 7F0AEE00 26100004 */  addiu $s0, $s0, 4
/* 0E3934 7F0AEE04 A218FFFC */  sb    $t8, -4($s0)
/* 0E3938 7F0AEE08 9059FFFD */  lbu   $t9, -3($v0)
/* 0E393C 7F0AEE0C A219FFFD */  sb    $t9, -3($s0)
/* 0E3940 7F0AEE10 904EFFFE */  lbu   $t6, -2($v0)
/* 0E3944 7F0AEE14 A20EFFFE */  sb    $t6, -2($s0)
/* 0E3948 7F0AEE18 904FFFFF */  lbu   $t7, -1($v0)
/* 0E394C 7F0AEE1C 1444FFF6 */  bne   $v0, $a0, .L7F0AEDF8
/* 0E3950 7F0AEE20 A20FFFFF */   sb    $t7, -1($s0)
.L7F0AEE24:
/* 0E3954 7F0AEE24 A2090000 */  sb    $t1, ($s0)
/* 0E3958 7F0AEE28 1000002D */  b     .L7F0AEEE0
/* 0E395C 7F0AEE2C 26100001 */   addiu $s0, $s0, 1
.L7F0AEE30:
/* 0E3960 7F0AEE30 1440002B */  bnez  $v0, .L7F0AEEE0
/* 0E3964 7F0AEE34 00001825 */   move  $v1, $zero
/* 0E3968 7F0AEE38 1480000E */  bnez  $a0, .L7F0AEE74
/* 0E396C 7F0AEE3C 00006825 */   move  $t5, $zero
/* 0E3970 7F0AEE40 A20C0000 */  sb    $t4, ($s0)
/* 0E3974 7F0AEE44 8D180000 */  lw    $t8, ($t0)
/* 0E3978 7F0AEE48 26100001 */  addiu $s0, $s0, 1
/* 0E397C 7F0AEE4C 1B000009 */  blez  $t8, .L7F0AEE74
/* 0E3980 7F0AEE50 00000000 */   nop   
/* 0E3984 7F0AEE54 A2090000 */  sb    $t1, ($s0)
.L7F0AEE58:
/* 0E3988 7F0AEE58 8D190000 */  lw    $t9, ($t0)
/* 0E398C 7F0AEE5C 24630001 */  addiu $v1, $v1, 1
/* 0E3990 7F0AEE60 26100001 */  addiu $s0, $s0, 1
/* 0E3994 7F0AEE64 0079082A */  slt   $at, $v1, $t9
/* 0E3998 7F0AEE68 5420FFFB */  bnezl $at, .L7F0AEE58
/* 0E399C 7F0AEE6C A2090000 */   sb    $t1, ($s0)
/* 0E39A0 7F0AEE70 00001825 */  move  $v1, $zero
.L7F0AEE74:
/* 0E39A4 7F0AEE74 1A200019 */  blez  $s1, .L7F0AEEDC
/* 0E39A8 7F0AEE78 32250003 */   andi  $a1, $s1, 3
/* 0E39AC 7F0AEE7C 10A00009 */  beqz  $a1, .L7F0AEEA4
/* 0E39B0 7F0AEE80 00A02025 */   move  $a0, $a1
/* 0E39B4 7F0AEE84 02831021 */  addu  $v0, $s4, $v1
.L7F0AEE88:
/* 0E39B8 7F0AEE88 904E0000 */  lbu   $t6, ($v0)
/* 0E39BC 7F0AEE8C 24630001 */  addiu $v1, $v1, 1
/* 0E39C0 7F0AEE90 26100001 */  addiu $s0, $s0, 1
/* 0E39C4 7F0AEE94 24420001 */  addiu $v0, $v0, 1
/* 0E39C8 7F0AEE98 1483FFFB */  bne   $a0, $v1, .L7F0AEE88
/* 0E39CC 7F0AEE9C A20EFFFF */   sb    $t6, -1($s0)
/* 0E39D0 7F0AEEA0 1071000E */  beq   $v1, $s1, .L7F0AEEDC
.L7F0AEEA4:
/* 0E39D4 7F0AEEA4 27AF004C */   addiu $t7, $sp, 0x4c
/* 0E39D8 7F0AEEA8 022F2021 */  addu  $a0, $s1, $t7
/* 0E39DC 7F0AEEAC 02831021 */  addu  $v0, $s4, $v1
.L7F0AEEB0:
/* 0E39E0 7F0AEEB0 90580000 */  lbu   $t8, ($v0)
/* 0E39E4 7F0AEEB4 24420004 */  addiu $v0, $v0, 4
/* 0E39E8 7F0AEEB8 26100004 */  addiu $s0, $s0, 4
/* 0E39EC 7F0AEEBC A218FFFC */  sb    $t8, -4($s0)
/* 0E39F0 7F0AEEC0 9059FFFD */  lbu   $t9, -3($v0)
/* 0E39F4 7F0AEEC4 A219FFFD */  sb    $t9, -3($s0)
/* 0E39F8 7F0AEEC8 904EFFFE */  lbu   $t6, -2($v0)
/* 0E39FC 7F0AEECC A20EFFFE */  sb    $t6, -2($s0)
/* 0E3A00 7F0AEED0 904FFFFF */  lbu   $t7, -1($v0)
/* 0E3A04 7F0AEED4 1444FFF6 */  bne   $v0, $a0, .L7F0AEEB0
/* 0E3A08 7F0AEED8 A20FFFFF */   sb    $t7, -1($s0)
.L7F0AEEDC:
/* 0E3A0C 7F0AEEDC A2000000 */  sb    $zero, ($s0)
.L7F0AEEE0:
/* 0E3A10 7F0AEEE0 24010001 */  li    $at, 1
/* 0E3A14 7F0AEEE4 11A1FF2F */  beq   $t5, $at, .L7F0AEBA4
/* 0E3A18 7F0AEEE8 26520001 */   addiu $s2, $s2, 1
/* 0E3A1C 7F0AEEEC 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0E3A20 7F0AEEF0 8FB00020 */  lw    $s0, 0x20($sp)
/* 0E3A24 7F0AEEF4 8FB10024 */  lw    $s1, 0x24($sp)
/* 0E3A28 7F0AEEF8 8FB20028 */  lw    $s2, 0x28($sp)
/* 0E3A2C 7F0AEEFC 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0E3A30 7F0AEF00 8FB40030 */  lw    $s4, 0x30($sp)
/* 0E3A34 7F0AEF04 03E00008 */  jr    $ra
/* 0E3A38 7F0AEF08 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif



void sub_GAME_7F0AEF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // (function likely stubbed)
}

u32 sub_GAME_7F0AEF20(u32 param_1,u32 param_2){
  return param_1;
}


