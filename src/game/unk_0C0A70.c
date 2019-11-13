#include "ultra64.h"
#include "game/unk_0C0A70.h"

// data
s32 D_80048490 = -1;
s32 D_80048494 = 0;
s32 D_80048498 = 1;
#ifdef VERSION_JP
f32 jpD_800484CC = 1.0f;
f32 jpD_800484D0 = 1.0f;
#endif
s32 D_8004849C = -1;
s32 D_800484A0 = 0;
s32 D_800484A4 = 0;
s32 D_800484A8 = 0;
u32 copy_of_osgetcount_value_0 = 0;
u32 copy_of_osgetcount_value_1 = 0;
s32 D_800484B4 = 1;



#ifdef NONMATCHING
void store_osgetcount(void) {
    u32 temp_ret;

    temp_ret = osGetCount();
    copy_of_osgetcount_value_1 = temp_ret;
    copy_of_osgetcount_value_0 = temp_ret;
}

#else
GLOBAL_ASM(
.text
glabel store_osgetcount
/* 0F55A0 7F0C0A70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F55A4 7F0C0A74 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F55A8 7F0C0A78 0C003638 */  jal   osGetCount
/* 0F55AC 7F0C0A7C 00000000 */   nop   
/* 0F55B0 7F0C0A80 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F55B4 7F0C0A84 3C038005 */  lui   $v1, %hi(copy_of_osgetcount_value_1)
/* 0F55B8 7F0C0A88 246384B0 */  addiu $v1, %lo(copy_of_osgetcount_value_1) # addiu $v1, $v1, -0x7b50
/* 0F55BC 7F0C0A8C AC620000 */  sw    $v0, ($v1)
/* 0F55C0 7F0C0A90 3C018005 */  lui   $at, %hi(copy_of_osgetcount_value_0)
/* 0F55C4 7F0C0A94 AC2284AC */  sw    $v0, %lo(copy_of_osgetcount_value_0)($at)
/* 0F55C8 7F0C0A98 03E00008 */  jr    $ra
/* 0F55CC 7F0C0A9C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C0AA0(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C0AA0
/* 0F55D0 7F0C0AA0 3C0E8005 */  lui   $t6, %hi(copy_of_osgetcount_value_1) 
/* 0F55D4 7F0C0AA4 8DCE84B0 */  lw    $t6, %lo(copy_of_osgetcount_value_1)($t6)
/* 0F55D8 7F0C0AA8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F55DC 7F0C0AAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F55E0 7F0C0AB0 3C018005 */  lui   $at, %hi(copy_of_osgetcount_value_0)
/* 0F55E4 7F0C0AB4 AFA40018 */  sw    $a0, 0x18($sp)
/* 0F55E8 7F0C0AB8 0C003638 */  jal   osGetCount
/* 0F55EC 7F0C0ABC AC2E84AC */   sw    $t6, %lo(copy_of_osgetcount_value_0)($at)
/* 0F55F0 7F0C0AC0 3C048005 */  lui   $a0, %hi(D_80048494)
/* 0F55F4 7F0C0AC4 3C018005 */  lui   $at, %hi(copy_of_osgetcount_value_1)
/* 0F55F8 7F0C0AC8 AC2284B0 */  sw    $v0, %lo(copy_of_osgetcount_value_1)($at)
/* 0F55FC 7F0C0ACC 24848494 */  addiu $a0, %lo(D_80048494) # addiu $a0, $a0, -0x7b6c
/* 0F5600 7F0C0AD0 8C830000 */  lw    $v1, ($a0)
/* 0F5604 7F0C0AD4 8FA70018 */  lw    $a3, 0x18($sp)
/* 0F5608 7F0C0AD8 3C018005 */  lui   $at, %hi(D_80048490)
/* 0F560C 7F0C0ADC AC238490 */  sw    $v1, %lo(D_80048490)($at)
/* 0F5610 7F0C0AE0 00677821 */  addu  $t7, $v1, $a3
/* 0F5614 7F0C0AE4 AC8F0000 */  sw    $t7, ($a0)
/* 0F5618 7F0C0AE8 3C018005 */  lui   $at, %hi(D_80048498)
/* 0F561C 7F0C0AEC AC278498 */  sw    $a3, %lo(D_80048498)($at)
/* 0F5620 7F0C0AF0 8C830000 */  lw    $v1, ($a0)
/* 0F5624 7F0C0AF4 3C058005 */  lui   $a1, %hi(D_800484A0)
/* 0F5628 7F0C0AF8 24A584A0 */  addiu $a1, %lo(D_800484A0) # addiu $a1, $a1, -0x7b60
/* 0F562C 7F0C0AFC 8CB80000 */  lw    $t8, ($a1)
/* 0F5630 7F0C0B00 3C068005 */  lui   $a2, %hi(D_8004849C)
/* 0F5634 7F0C0B04 24C6849C */  addiu $a2, %lo(D_8004849C) # addiu $a2, $a2, -0x7b64
/* 0F5638 7F0C0B08 30680001 */  andi  $t0, $v1, 1
/* 0F563C 7F0C0B0C ACD80000 */  sw    $t8, ($a2)
/* 0F5640 7F0C0B10 04610003 */  bgez  $v1, .L7F0C0B20
/* 0F5644 7F0C0B14 0003C843 */   sra   $t9, $v1, 1
/* 0F5648 7F0C0B18 24610001 */  addiu $at, $v1, 1
/* 0F564C 7F0C0B1C 0001C843 */  sra   $t9, $at, 1
.L7F0C0B20:
/* 0F5650 7F0C0B20 ACB90000 */  sw    $t9, ($a1)
/* 0F5654 7F0C0B24 3C018005 */  lui   $at, %hi(D_800484A4)
/* 0F5658 7F0C0B28 AC2884A4 */  sw    $t0, %lo(D_800484A4)($at)
/* 0F565C 7F0C0B2C 8CCA0000 */  lw    $t2, ($a2)
/* 0F5660 7F0C0B30 8CA90000 */  lw    $t1, ($a1)
/* 0F5664 7F0C0B34 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F5668 7F0C0B38 3C018005 */  lui   $at, %hi(D_800484A8)
/* 0F566C 7F0C0B3C 012A5823 */  subu  $t3, $t1, $t2
/* 0F5670 7F0C0B40 AC2B84A8 */  sw    $t3, %lo(D_800484A8)($at)
/* 0F5674 7F0C0B44 03E00008 */  jr    $ra
/* 0F5678 7F0C0B48 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C0AA0
/* 0F6280 7F0C1710 3C0E8005 */  lui   $t6, %hi(copy_of_osgetcount_value_1) # $t6, 0x8005
/* 0F6284 7F0C1714 8DCE84E8 */  lw    $t6, %lo(copy_of_osgetcount_value_1)($t6)
/* 0F6288 7F0C1718 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F628C 7F0C171C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6290 7F0C1720 3C018005 */  lui   $at, %hi(copy_of_osgetcount_value_0) # $at, 0x8005
/* 0F6294 7F0C1724 AFA40018 */  sw    $a0, 0x18($sp)
/* 0F6298 7F0C1728 0C003648 */  jal   osGetCount
/* 0F629C 7F0C172C AC2E84E4 */   sw    $t6, %lo(copy_of_osgetcount_value_0)($at)
/* 0F62A0 7F0C1730 8FA60018 */  lw    $a2, 0x18($sp)
/* 0F62A4 7F0C1734 3C048005 */  lui   $a0, %hi(D_80048494) # $a0, 0x8005
/* 0F62A8 7F0C1738 3C018005 */  lui   $at, %hi(copy_of_osgetcount_value_1) # $at, 0x8005
/* 0F62AC 7F0C173C 44862000 */  mtc1  $a2, $f4
/* 0F62B0 7F0C1740 AC2284E8 */  sw    $v0, %lo(copy_of_osgetcount_value_1)($at)
/* 0F62B4 7F0C1744 248484C4 */  addiu $a0, %lo(D_80048494) # addiu $a0, $a0, -0x7b3c
/* 0F62B8 7F0C1748 8C830000 */  lw    $v1, ($a0)
/* 0F62BC 7F0C174C 468021A0 */  cvt.s.w $f6, $f4
/* 0F62C0 7F0C1750 3C018005 */  lui   $at, %hi(D_80048490) # $at, 0x8005
/* 0F62C4 7F0C1754 AC2384C0 */  sw    $v1, %lo(D_80048490)($at)
/* 0F62C8 7F0C1758 00667821 */  addu  $t7, $v1, $a2
/* 0F62CC 7F0C175C 3C078005 */  lui   $a3, %hi(jpD_800484CC) # $a3, 0x8005
/* 0F62D0 7F0C1760 AC8F0000 */  sw    $t7, ($a0)
/* 0F62D4 7F0C1764 3C018005 */  lui   $at, %hi(D_80048498) # $at, 0x8005
/* 0F62D8 7F0C1768 24E784CC */  addiu $a3, %lo(jpD_800484CC) # addiu $a3, $a3, -0x7b34
/* 0F62DC 7F0C176C AC2684C8 */  sw    $a2, %lo(D_80048498)($at)
/* 0F62E0 7F0C1770 E4E60000 */  swc1  $f6, ($a3)
/* 0F62E4 7F0C1774 C4E80000 */  lwc1  $f8, ($a3)
/* 0F62E8 7F0C1778 3C018005 */  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
/* 0F62EC 7F0C177C 3C058005 */  lui   $a1, %hi(D_800484A0) # $a1, 0x8005
/* 0F62F0 7F0C1780 E42884D0 */  swc1  $f8, %lo(jpD_800484D0)($at)
/* 0F62F4 7F0C1784 8C830000 */  lw    $v1, ($a0)
/* 0F62F8 7F0C1788 24A584D8 */  addiu $a1, %lo(D_800484A0) # addiu $a1, $a1, -0x7b28
/* 0F62FC 7F0C178C 8CB80000 */  lw    $t8, ($a1)
/* 0F6300 7F0C1790 3C088005 */  lui   $t0, %hi(D_8004849C) # $t0, 0x8005
/* 0F6304 7F0C1794 250884D4 */  addiu $t0, %lo(D_8004849C) # addiu $t0, $t0, -0x7b2c
/* 0F6308 7F0C1798 30690001 */  andi  $t1, $v1, 1
/* 0F630C 7F0C179C AD180000 */  sw    $t8, ($t0)
/* 0F6310 7F0C17A0 04610003 */  bgez  $v1, .L7F0C17B0
/* 0F6314 7F0C17A4 0003C843 */   sra   $t9, $v1, 1
/* 0F6318 7F0C17A8 24610001 */  addiu $at, $v1, 1
/* 0F631C 7F0C17AC 0001C843 */  sra   $t9, $at, 1
.L7F0C17B0:
/* 0F6320 7F0C17B0 ACB90000 */  sw    $t9, ($a1)
/* 0F6324 7F0C17B4 3C018005 */  lui   $at, %hi(D_800484A4) # $at, 0x8005
/* 0F6328 7F0C17B8 AC2984DC */  sw    $t1, %lo(D_800484A4)($at)
/* 0F632C 7F0C17BC 8D0B0000 */  lw    $t3, ($t0)
/* 0F6330 7F0C17C0 8CAA0000 */  lw    $t2, ($a1)
/* 0F6334 7F0C17C4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F6338 7F0C17C8 3C018005 */  lui   $at, %hi(D_800484A8) # $at, 0x8005
/* 0F633C 7F0C17CC 014B6023 */  subu  $t4, $t2, $t3
/* 0F6340 7F0C17D0 AC2C84E0 */  sw    $t4, %lo(D_800484A8)($at)
/* 0F6344 7F0C17D4 03E00008 */  jr    $ra
/* 0F6348 7F0C17D8 27BD0018 */   addiu $sp, $sp, 0x18  
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F0C0B4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C0B4C
/* 0F567C 7F0C0B4C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F5680 7F0C0B50 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F5684 7F0C0B54 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F5688 7F0C0B58 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F568C 7F0C0B5C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F5690 7F0C0B60 3C108005 */  lui   $s0, %hi(D_800484B4)
/* 0F5694 7F0C0B64 3C118005 */  lui   $s1, %hi(copy_of_osgetcount_value_1)
/* 0F5698 7F0C0B68 3C120005 */  lui   $s2, (0x0005EB61 >> 16) # lui $s2, 5
/* 0F569C 7F0C0B6C 3C13000B */  lui   $s3, (0x000BD6C3 >> 16) # lui $s3, 0xb
/* 0F56A0 7F0C0B70 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F56A4 7F0C0B74 3673D6C3 */  ori   $s3, (0x000BD6C3 & 0xFFFF) # ori $s3, $s3, 0xd6c3
/* 0F56A8 7F0C0B78 3652EB61 */  ori   $s2, (0x0005EB61 & 0xFFFF) # ori $s2, $s2, 0xeb61
/* 0F56AC 7F0C0B7C 263184B0 */  addiu $s1, %lo(copy_of_osgetcount_value_1) # addiu $s1, $s1, -0x7b50
/* 0F56B0 7F0C0B80 261084B4 */  addiu $s0, %lo(D_800484B4) # addiu $s0, $s0, -0x7b4c
.L7F0C0B84:
/* 0F56B4 7F0C0B84 0C003638 */  jal   osGetCount
/* 0F56B8 7F0C0B88 00000000 */   nop   
/* 0F56BC 7F0C0B8C 8E2E0000 */  lw    $t6, ($s1)
/* 0F56C0 7F0C0B90 8E190000 */  lw    $t9, ($s0)
/* 0F56C4 7F0C0B94 004E7823 */  subu  $t7, $v0, $t6
/* 0F56C8 7F0C0B98 01F2C021 */  addu  $t8, $t7, $s2
/* 0F56CC 7F0C0B9C 0313001B */  divu  $zero, $t8, $s3
/* 0F56D0 7F0C0BA0 00002012 */  mflo  $a0
/* 0F56D4 7F0C0BA4 0099082B */  sltu  $at, $a0, $t9
/* 0F56D8 7F0C0BA8 16600002 */  bnez  $s3, .L7F0C0BB4
/* 0F56DC 7F0C0BAC 00000000 */   nop   
/* 0F56E0 7F0C0BB0 0007000D */  break 7
.L7F0C0BB4:
/* 0F56E4 7F0C0BB4 1420FFF3 */  bnez  $at, .L7F0C0B84
/* 0F56E8 7F0C0BB8 00000000 */   nop   
/* 0F56EC 7F0C0BBC 24080001 */  li    $t0, 1
/* 0F56F0 7F0C0BC0 0FC302A8 */  jal   sub_GAME_7F0C0AA0
/* 0F56F4 7F0C0BC4 AE080000 */   sw    $t0, ($s0)
/* 0F56F8 7F0C0BC8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F56FC 7F0C0BCC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F5700 7F0C0BD0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F5704 7F0C0BD4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F5708 7F0C0BD8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F570C 7F0C0BDC 03E00008 */  jr    $ra
/* 0F5710 7F0C0BE0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





void sub_GAME_7F0C0BE4(s32 arg0) {
    D_800484B4 = arg0;
}

void sub_GAME_7F0C0BF0(void) {
    sub_GAME_7F0A9358();
}



