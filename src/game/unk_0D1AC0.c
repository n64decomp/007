#include "ultra64.h"


// data
f32 D_8004EAF0 = 0.0;
f32 D_8004EAF4 = 0.0;




#ifdef NONMATCHING
s32 sub_GAME_7F0D1AC0(void *arg0) {
    void *temp_v1;
    void *temp_a1;
    void *temp_a0;
    void *temp_a3;
    void *temp_v1_2;
    void *temp_a1_2;
    void *temp_a2;

    // Node 0
    D_8004EAF4 = 0.0f;
    D_8004EAF0 = (f32) D_8004EAF4;
    temp_v1 = (arg0 + 8);
    *arg0 = 0xba000c02;
    arg0->unk4 = 0;
    temp_a1 = (temp_v1 + 8);
    temp_v1->unk4 = 0xc0;
    *temp_v1 = 0xba000602;
    temp_a1->unk4 = 1;
    *temp_a1 = 0xb6000000;
    temp_a0 = (temp_a1 + 8);
    temp_a3 = (temp_a0 + 8);
    *temp_a0 = 0xe7000000;
    temp_a0->unk4 = 0;
    temp_v1_2 = (temp_a3 + 8);
    *temp_a3 = 0xba001301;
    temp_a3->unk4 = 0;
    temp_a1_2 = (temp_v1_2 + 8);
    temp_v1_2->unk4 = 0x300000;
    *temp_v1_2 = 0xba001402;
    temp_a2 = (temp_a1_2 + 8);
    temp_a1_2->unk4 = 0xf0a4000;
    *temp_a1_2 = 0xb900031d;
    temp_a2->unk4 = 0x800000;
    *temp_a2 = 0xba001701;
    return;
    // (possible return value: (temp_a2 + 8))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1AC0
/* 1065F0 7F0D1AC0 44802000 */  mtc1  $zero, $f4
/* 1065F4 7F0D1AC4 3C088005 */  lui   $t0, %hi(D_8004EAF4) 
/* 1065F8 7F0D1AC8 2508EAF4 */  addiu $t0, %lo(D_8004EAF4) # addiu $t0, $t0, -0x150c
/* 1065FC 7F0D1ACC E5040000 */  swc1  $f4, ($t0)
/* 106600 7F0D1AD0 C5060000 */  lwc1  $f6, ($t0)
/* 106604 7F0D1AD4 3C018005 */  lui   $at, %hi(D_8004EAF0)
/* 106608 7F0D1AD8 00801025 */  move  $v0, $a0
/* 10660C 7F0D1ADC 3C0EBA00 */  lui   $t6, (0xBA000C02 >> 16) # lui $t6, 0xba00
/* 106610 7F0D1AE0 E426EAF0 */  swc1  $f6, %lo(D_8004EAF0)($at)
/* 106614 7F0D1AE4 35CE0C02 */  ori   $t6, (0xBA000C02 & 0xFFFF) # ori $t6, $t6, 0xc02
/* 106618 7F0D1AE8 24830008 */  addiu $v1, $a0, 8
/* 10661C 7F0D1AEC AC4E0000 */  sw    $t6, ($v0)
/* 106620 7F0D1AF0 AC400004 */  sw    $zero, 4($v0)
/* 106624 7F0D1AF4 3C0FBA00 */  lui   $t7, (0xBA000602 >> 16) # lui $t7, 0xba00
/* 106628 7F0D1AF8 35EF0602 */  ori   $t7, (0xBA000602 & 0xFFFF) # ori $t7, $t7, 0x602
/* 10662C 7F0D1AFC 24650008 */  addiu $a1, $v1, 8
/* 106630 7F0D1B00 241800C0 */  li    $t8, 192
/* 106634 7F0D1B04 AC780004 */  sw    $t8, 4($v1)
/* 106638 7F0D1B08 AC6F0000 */  sw    $t7, ($v1)
/* 10663C 7F0D1B0C 3C19B600 */  lui   $t9, 0xb600
/* 106640 7F0D1B10 24090001 */  li    $t1, 1
/* 106644 7F0D1B14 ACA90004 */  sw    $t1, 4($a1)
/* 106648 7F0D1B18 ACB90000 */  sw    $t9, ($a1)
/* 10664C 7F0D1B1C 24A40008 */  addiu $a0, $a1, 8
/* 106650 7F0D1B20 24870008 */  addiu $a3, $a0, 8
/* 106654 7F0D1B24 3C0AE700 */  lui   $t2, 0xe700
/* 106658 7F0D1B28 AC8A0000 */  sw    $t2, ($a0)
/* 10665C 7F0D1B2C AC800004 */  sw    $zero, 4($a0)
/* 106660 7F0D1B30 3C0BBA00 */  lui   $t3, (0xBA001301 >> 16) # lui $t3, 0xba00
/* 106664 7F0D1B34 356B1301 */  ori   $t3, (0xBA001301 & 0xFFFF) # ori $t3, $t3, 0x1301
/* 106668 7F0D1B38 24E30008 */  addiu $v1, $a3, 8
/* 10666C 7F0D1B3C ACEB0000 */  sw    $t3, ($a3)
/* 106670 7F0D1B40 ACE00004 */  sw    $zero, 4($a3)
/* 106674 7F0D1B44 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 106678 7F0D1B48 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 10667C 7F0D1B4C 24650008 */  addiu $a1, $v1, 8
/* 106680 7F0D1B50 3C0D0030 */  lui   $t5, 0x30
/* 106684 7F0D1B54 AC6D0004 */  sw    $t5, 4($v1)
/* 106688 7F0D1B58 AC6C0000 */  sw    $t4, ($v1)
/* 10668C 7F0D1B5C 3C0F0F0A */  lui   $t7, (0x0F0A4000 >> 16) # lui $t7, 0xf0a
/* 106690 7F0D1B60 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 106694 7F0D1B64 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 106698 7F0D1B68 35EF4000 */  ori   $t7, (0x0F0A4000 & 0xFFFF) # ori $t7, $t7, 0x4000
/* 10669C 7F0D1B6C 24A60008 */  addiu $a2, $a1, 8
/* 1066A0 7F0D1B70 3C18BA00 */  lui   $t8, (0xBA001701 >> 16) # lui $t8, 0xba00
/* 1066A4 7F0D1B74 ACAF0004 */  sw    $t7, 4($a1)
/* 1066A8 7F0D1B78 ACAE0000 */  sw    $t6, ($a1)
/* 1066AC 7F0D1B7C 37181701 */  ori   $t8, (0xBA001701 & 0xFFFF) # ori $t8, $t8, 0x1701
/* 1066B0 7F0D1B80 3C190080 */  lui   $t9, 0x80
/* 1066B4 7F0D1B84 ACD90004 */  sw    $t9, 4($a2)
/* 1066B8 7F0D1B88 ACD80000 */  sw    $t8, ($a2)
/* 1066BC 7F0D1B8C 03E00008 */  jr    $ra
/* 1066C0 7F0D1B90 24C20008 */   addiu $v0, $a2, 8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1B94(s32 arg1, ?32 argE) {
    // Node 0
    sub_GAME_7F0D1BD0(arg1, arg1, argE, 2, 1);
    return;
    // (possible return value: sub_GAME_7F0D1BD0(arg1, arg1, argE, 2, 1))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1B94
/* 1066C4 7F0D1B94 44856000 */  mtc1  $a1, $f12
/* 1066C8 7F0D1B98 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1066CC 7F0D1B9C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 1066D0 7F0D1BA0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1066D4 7F0D1BA4 240F0002 */  li    $t7, 2
/* 1066D8 7F0D1BA8 24180001 */  li    $t8, 1
/* 1066DC 7F0D1BAC 44056000 */  mfc1  $a1, $f12
/* 1066E0 7F0D1BB0 AFB80018 */  sw    $t8, 0x18($sp)
/* 1066E4 7F0D1BB4 AFAF0014 */  sw    $t7, 0x14($sp)
/* 1066E8 7F0D1BB8 0FC346F4 */  jal   sub_GAME_7F0D1BD0
/* 1066EC 7F0D1BBC AFAE0010 */   sw    $t6, 0x10($sp)
/* 1066F0 7F0D1BC0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1066F4 7F0D1BC4 27BD0028 */  addiu $sp, $sp, 0x28
/* 1066F8 7F0D1BC8 03E00008 */  jr    $ra
/* 1066FC 7F0D1BCC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1BD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1BD0
/* 106700 7F0D1BD0 44856000 */  mtc1  $a1, $f12
/* 106704 7F0D1BD4 44802000 */  mtc1  $zero, $f4
/* 106708 7F0D1BD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 10670C 7F0D1BDC AFB2000C */  sw    $s2, 0xc($sp)
/* 106710 7F0D1BE0 460C203C */  c.lt.s $f4, $f12
/* 106714 7F0D1BE4 AFB10008 */  sw    $s1, 8($sp)
/* 106718 7F0D1BE8 AFB00004 */  sw    $s0, 4($sp)
/* 10671C 7F0D1BEC AFA60018 */  sw    $a2, 0x18($sp)
/* 106720 7F0D1BF0 45000070 */  bc1f  .L7F0D1DB4
/* 106724 7F0D1BF4 AFA7001C */   sw    $a3, 0x1c($sp)
/* 106728 7F0D1BF8 3C058005 */  lui   $a1, %hi(D_8004EAF4)
/* 10672C 7F0D1BFC 24A5EAF4 */  addiu $a1, %lo(D_8004EAF4) # addiu $a1, $a1, -0x150c
/* 106730 7F0D1C00 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 106734 7F0D1C04 44817000 */  mtc1  $at, $f14
/* 106738 7F0D1C08 C4A00000 */  lwc1  $f0, ($a1)
/* 10673C 7F0D1C0C 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106740 7F0D1C10 44815000 */  mtc1  $at, $f10
/* 106744 7F0D1C14 460E0183 */  div.s $f6, $f0, $f14
/* 106748 7F0D1C18 00804025 */  move  $t0, $a0
/* 10674C 7F0D1C1C 3C18F700 */  lui   $t8, 0xf700
/* 106750 7F0D1C20 AD180000 */  sw    $t8, ($t0)
/* 106754 7F0D1C24 460A0402 */  mul.s $f16, $f0, $f10
/* 106758 7F0D1C28 460C0080 */  add.s $f2, $f0, $f12
/* 10675C 7F0D1C2C 8FB90018 */  lw    $t9, 0x18($sp)
/* 106760 7F0D1C30 8FB8001C */  lw    $t8, 0x1c($sp)
/* 106764 7F0D1C34 24840008 */  addiu $a0, $a0, 8
/* 106768 7F0D1C38 00197200 */  sll   $t6, $t9, 8
/* 10676C 7F0D1C3C 31CFF800 */  andi  $t7, $t6, 0xf800
/* 106770 7F0D1C40 0018C8C0 */  sll   $t9, $t8, 3
/* 106774 7F0D1C44 332E07C0 */  andi  $t6, $t9, 0x7c0
/* 106778 7F0D1C48 8FB90020 */  lw    $t9, 0x20($sp)
/* 10677C 7F0D1C4C 01EEC025 */  or    $t8, $t7, $t6
/* 106780 7F0D1C50 00197883 */  sra   $t7, $t9, 2
/* 106784 7F0D1C54 31EE003E */  andi  $t6, $t7, 0x3e
/* 106788 7F0D1C58 030E4825 */  or    $t1, $t8, $t6
/* 10678C 7F0D1C5C 35390001 */  ori   $t9, $t1, 1
/* 106790 7F0D1C60 00197C00 */  sll   $t7, $t9, 0x10
/* 106794 7F0D1C64 01F9C025 */  or    $t8, $t7, $t9
/* 106798 7F0D1C68 460E8483 */  div.s $f18, $f16, $f14
/* 10679C 7F0D1C6C AD180004 */  sw    $t8, 4($t0)
/* 1067A0 7F0D1C70 4600320D */  trunc.w.s $f8, $f6
/* 1067A4 7F0D1C74 44064000 */  mfc1  $a2, $f8
/* 1067A8 7F0D1C78 00000000 */  nop   
/* 1067AC 7F0D1C7C 00C01025 */  move  $v0, $a2
/* 1067B0 7F0D1C80 460E1183 */  div.s $f6, $f2, $f14
/* 1067B4 7F0D1C84 4600910D */  trunc.w.s $f4, $f18
/* 1067B8 7F0D1C88 44072000 */  mfc1  $a3, $f4
/* 1067BC 7F0D1C8C 4600320D */  trunc.w.s $f8, $f6
/* 1067C0 7F0D1C90 44034000 */  mfc1  $v1, $f8
/* 1067C4 7F0D1C94 00000000 */  nop   
/* 1067C8 7F0D1C98 0066082A */  slt   $at, $v1, $a2
/* 1067CC 7F0D1C9C 14200042 */  bnez  $at, .L7F0D1DA8
/* 1067D0 7F0D1CA0 28C10003 */   slti  $at, $a2, 3
/* 1067D4 7F0D1CA4 10200040 */  beqz  $at, .L7F0D1DA8
/* 1067D8 7F0D1CA8 3C01435B */   li    $at, 0x435B0000 # 219.000000
/* 1067DC 7F0D1CAC 44815000 */  mtc1  $at, $f10
/* 1067E0 7F0D1CB0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 1067E4 7F0D1CB4 44819000 */  mtc1  $at, $f18
/* 1067E8 7F0D1CB8 460A1402 */  mul.s $f16, $f2, $f10
/* 1067EC 7F0D1CBC 000240C0 */  sll   $t0, $v0, 3
/* 1067F0 7F0D1CC0 01024023 */  subu  $t0, $t0, $v0
/* 1067F4 7F0D1CC4 000840C0 */  sll   $t0, $t0, 3
/* 1067F8 7F0D1CC8 01024023 */  subu  $t0, $t0, $v0
/* 1067FC 7F0D1CCC 00084080 */  sll   $t0, $t0, 2
/* 106800 7F0D1CD0 01024023 */  subu  $t0, $t0, $v0
/* 106804 7F0D1CD4 46128103 */  div.s $f4, $f16, $f18
/* 106808 7F0D1CD8 00E84823 */  subu  $t1, $a3, $t0
/* 10680C 7F0D1CDC 25290032 */  addiu $t1, $t1, 0x32
/* 106810 7F0D1CE0 24120007 */  li    $s2, 7
/* 106814 7F0D1CE4 3C11F600 */  lui   $s1, 0xf600
/* 106818 7F0D1CE8 8FAD0028 */  lw    $t5, 0x28($sp)
/* 10681C 7F0D1CEC 8FAC0024 */  lw    $t4, 0x24($sp)
/* 106820 7F0D1CF0 4600218D */  trunc.w.s $f6, $f4
/* 106824 7F0D1CF4 44063000 */  mfc1  $a2, $f6
/* 106828 7F0D1CF8 00000000 */  nop   
/* 10682C 7F0D1CFC 00C85823 */  subu  $t3, $a2, $t0
.L7F0D1D00:
/* 106830 7F0D1D00 256B0032 */  addiu $t3, $t3, 0x32
/* 106834 7F0D1D04 29210032 */  slti  $at, $t1, 0x32
/* 106838 7F0D1D08 01203825 */  move  $a3, $t1
/* 10683C 7F0D1D0C 10200002 */  beqz  $at, .L7F0D1D18
/* 106840 7F0D1D10 01605025 */   move  $t2, $t3
/* 106844 7F0D1D14 24070032 */  li    $a3, 50
.L7F0D1D18:
/* 106848 7F0D1D18 2961010E */  slti  $at, $t3, 0x10e
/* 10684C 7F0D1D1C 14200002 */  bnez  $at, .L7F0D1D28
/* 106850 7F0D1D20 250800DB */   addiu $t0, $t0, 0xdb
/* 106854 7F0D1D24 240A010D */  li    $t2, 269
.L7F0D1D28:
/* 106858 7F0D1D28 0147082A */  slt   $at, $t2, $a3
/* 10685C 7F0D1D2C 54200018 */  bnezl $at, .L7F0D1D90
/* 106860 7F0D1D30 24420001 */   addiu $v0, $v0, 1
/* 106864 7F0D1D34 00520019 */  multu $v0, $s2
/* 106868 7F0D1D38 314F03FF */  andi  $t7, $t2, 0x3ff
/* 10686C 7F0D1D3C 000FC380 */  sll   $t8, $t7, 0xe
/* 106870 7F0D1D40 018DC821 */  addu  $t9, $t4, $t5
/* 106874 7F0D1D44 03117025 */  or    $t6, $t8, $s1
/* 106878 7F0D1D48 00805825 */  move  $t3, $a0
/* 10687C 7F0D1D4C 24840008 */  addiu $a0, $a0, 8
/* 106880 7F0D1D50 00008012 */  mflo  $s0
/* 106884 7F0D1D54 03307821 */  addu  $t7, $t9, $s0
/* 106888 7F0D1D58 25F80011 */  addiu $t8, $t7, 0x11
/* 10688C 7F0D1D5C 331903FF */  andi  $t9, $t8, 0x3ff
/* 106890 7F0D1D60 00197880 */  sll   $t7, $t9, 2
/* 106894 7F0D1D64 01CFC025 */  or    $t8, $t6, $t7
/* 106898 7F0D1D68 AD780000 */  sw    $t8, ($t3)
/* 10689C 7F0D1D6C 01B07821 */  addu  $t7, $t5, $s0
/* 1068A0 7F0D1D70 30F903FF */  andi  $t9, $a3, 0x3ff
/* 1068A4 7F0D1D74 00197380 */  sll   $t6, $t9, 0xe
/* 1068A8 7F0D1D78 25F80012 */  addiu $t8, $t7, 0x12
/* 1068AC 7F0D1D7C 331903FF */  andi  $t9, $t8, 0x3ff
/* 1068B0 7F0D1D80 00197880 */  sll   $t7, $t9, 2
/* 1068B4 7F0D1D84 01CFC025 */  or    $t8, $t6, $t7
/* 1068B8 7F0D1D88 AD780004 */  sw    $t8, 4($t3)
/* 1068BC 7F0D1D8C 24420001 */  addiu $v0, $v0, 1
.L7F0D1D90:
/* 1068C0 7F0D1D90 0062082A */  slt   $at, $v1, $v0
/* 1068C4 7F0D1D94 14200004 */  bnez  $at, .L7F0D1DA8
/* 1068C8 7F0D1D98 2529FF25 */   addiu $t1, $t1, -0xdb
/* 1068CC 7F0D1D9C 28410003 */  slti  $at, $v0, 3
/* 1068D0 7F0D1DA0 5420FFD7 */  bnezl $at, .L7F0D1D00
/* 1068D4 7F0D1DA4 00C85823 */   subu  $t3, $a2, $t0
.L7F0D1DA8:
/* 1068D8 7F0D1DA8 C4A80000 */  lwc1  $f8, ($a1)
/* 1068DC 7F0D1DAC 460C4280 */  add.s $f10, $f8, $f12
/* 1068E0 7F0D1DB0 E4AA0000 */  swc1  $f10, ($a1)
.L7F0D1DB4:
/* 1068E4 7F0D1DB4 8FB00004 */  lw    $s0, 4($sp)
/* 1068E8 7F0D1DB8 8FB10008 */  lw    $s1, 8($sp)
/* 1068EC 7F0D1DBC 8FB2000C */  lw    $s2, 0xc($sp)
/* 1068F0 7F0D1DC0 27BD0010 */  addiu $sp, $sp, 0x10
/* 1068F4 7F0D1DC4 03E00008 */  jr    $ra
/* 1068F8 7F0D1DC8 00801025 */   move  $v0, $a0
)
#endif





void sub_GAME_7F0D1DCC(f32 arg0) {
    if (0.0f < arg0) {
        D_8004EAF4 = (f32) (D_8004EAF4 + arg0);
        return;
    }
}





#ifdef NONMATCHING
void sub_GAME_7F0D1DFC(s32 arg1, ?32 argC) {
    // Node 0
    sub_GAME_7F0D1B94(arg1, ((D_8004EAF0 + arg1) - D_8004EAF4), argC);
    return;
    // (possible return value: sub_GAME_7F0D1B94(arg1, ((D_8004EAF0 + arg1) - D_8004EAF4), argC))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1DFC
/* 10692C 7F0D1DFC 3C018005 */  lui   $at, %hi(D_8004EAF0)
/* 106930 7F0D1E00 44856000 */  mtc1  $a1, $f12
/* 106934 7F0D1E04 C424EAF0 */  lwc1  $f4, %lo(D_8004EAF0)($at)
/* 106938 7F0D1E08 3C018005 */  lui   $at, %hi(D_8004EAF4)
/* 10693C 7F0D1E0C C428EAF4 */  lwc1  $f8, %lo(D_8004EAF4)($at)
/* 106940 7F0D1E10 460C2180 */  add.s $f6, $f4, $f12
/* 106944 7F0D1E14 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 106948 7F0D1E18 8FAE0030 */  lw    $t6, 0x30($sp)
/* 10694C 7F0D1E1C AFBF001C */  sw    $ra, 0x1c($sp)
/* 106950 7F0D1E20 46083281 */  sub.s $f10, $f6, $f8
/* 106954 7F0D1E24 AFAE0010 */  sw    $t6, 0x10($sp)
/* 106958 7F0D1E28 44055000 */  mfc1  $a1, $f10
/* 10695C 7F0D1E2C 0FC346E5 */  jal   sub_GAME_7F0D1B94
/* 106960 7F0D1E30 00000000 */   nop   
/* 106964 7F0D1E34 8FBF001C */  lw    $ra, 0x1c($sp)
/* 106968 7F0D1E38 27BD0020 */  addiu $sp, $sp, 0x20
/* 10696C 7F0D1E3C 03E00008 */  jr    $ra
/* 106970 7F0D1E40 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1E44(s32 arg1, ?32 argE, ?32 argF, ?32 arg10) {
    // Node 0
    sub_GAME_7F0D1BD0(arg1, ((D_8004EAF0 + arg1) - D_8004EAF4), argE, argF, arg10);
    return;
    // (possible return value: sub_GAME_7F0D1BD0(arg1, ((D_8004EAF0 + arg1) - D_8004EAF4), argE, argF, arg10))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1E44
/* 106974 7F0D1E44 3C018005 */  lui   $at, %hi(D_8004EAF0)
/* 106978 7F0D1E48 44856000 */  mtc1  $a1, $f12
/* 10697C 7F0D1E4C C424EAF0 */  lwc1  $f4, %lo(D_8004EAF0)($at)
/* 106980 7F0D1E50 3C018005 */  lui   $at, %hi(D_8004EAF4)
/* 106984 7F0D1E54 C428EAF4 */  lwc1  $f8, %lo(D_8004EAF4)($at)
/* 106988 7F0D1E58 460C2180 */  add.s $f6, $f4, $f12
/* 10698C 7F0D1E5C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 106990 7F0D1E60 8FAE0038 */  lw    $t6, 0x38($sp)
/* 106994 7F0D1E64 8FAF003C */  lw    $t7, 0x3c($sp)
/* 106998 7F0D1E68 46083281 */  sub.s $f10, $f6, $f8
/* 10699C 7F0D1E6C 8FB80040 */  lw    $t8, 0x40($sp)
/* 1069A0 7F0D1E70 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1069A4 7F0D1E74 AFAE0010 */  sw    $t6, 0x10($sp)
/* 1069A8 7F0D1E78 44055000 */  mfc1  $a1, $f10
/* 1069AC 7F0D1E7C AFAF0014 */  sw    $t7, 0x14($sp)
/* 1069B0 7F0D1E80 0FC346F4 */  jal   sub_GAME_7F0D1BD0
/* 1069B4 7F0D1E84 AFB80018 */   sw    $t8, 0x18($sp)
/* 1069B8 7F0D1E88 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1069BC 7F0D1E8C 27BD0028 */  addiu $sp, $sp, 0x28
/* 1069C0 7F0D1E90 03E00008 */  jr    $ra
/* 1069C4 7F0D1E94 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1E98(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1E98
/* 1069C8 7F0D1E98 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 1069CC 7F0D1E9C 44810000 */  mtc1  $at, $f0
/* 1069D0 7F0D1EA0 3C018005 */  lui   $at, %hi(D_8004EAF4)
/* 1069D4 7F0D1EA4 C424EAF4 */  lwc1  $f4, %lo(D_8004EAF4)($at)
/* 1069D8 7F0D1EA8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1069DC 7F0D1EAC AFBF002C */  sw    $ra, 0x2c($sp)
/* 1069E0 7F0D1EB0 46002183 */  div.s $f6, $f4, $f0
/* 1069E4 7F0D1EB4 AFBE0028 */  sw    $fp, 0x28($sp)
/* 1069E8 7F0D1EB8 AFB70024 */  sw    $s7, 0x24($sp)
/* 1069EC 7F0D1EBC AFB60020 */  sw    $s6, 0x20($sp)
/* 1069F0 7F0D1EC0 AFB5001C */  sw    $s5, 0x1c($sp)
/* 1069F4 7F0D1EC4 AFB40018 */  sw    $s4, 0x18($sp)
/* 1069F8 7F0D1EC8 AFB30014 */  sw    $s3, 0x14($sp)
/* 1069FC 7F0D1ECC AFB20010 */  sw    $s2, 0x10($sp)
/* 106A00 7F0D1ED0 AFB1000C */  sw    $s1, 0xc($sp)
/* 106A04 7F0D1ED4 AFB00008 */  sw    $s0, 8($sp)
/* 106A08 7F0D1ED8 00801025 */  move  $v0, $a0
/* 106A0C 7F0D1EDC 3C0FF700 */  lui   $t7, 0xf700
/* 106A10 7F0D1EE0 AC4F0000 */  sw    $t7, ($v0)
/* 106A14 7F0D1EE4 000670C0 */  sll   $t6, $a2, 3
/* 106A18 7F0D1EE8 31CF07C0 */  andi  $t7, $t6, 0x7c0
/* 106A1C 7F0D1EEC 0005C200 */  sll   $t8, $a1, 8
/* 106A20 7F0D1EF0 3319F800 */  andi  $t9, $t8, 0xf800
/* 106A24 7F0D1EF4 032FC025 */  or    $t8, $t9, $t7
/* 106A28 7F0D1EF8 00077083 */  sra   $t6, $a3, 2
/* 106A2C 7F0D1EFC 31D9003E */  andi  $t9, $t6, 0x3e
/* 106A30 7F0D1F00 03191825 */  or    $v1, $t8, $t9
/* 106A34 7F0D1F04 346F0001 */  ori   $t7, $v1, 1
/* 106A38 7F0D1F08 000F7400 */  sll   $t6, $t7, 0x10
/* 106A3C 7F0D1F0C 4600320D */  trunc.w.s $f8, $f6
/* 106A40 7F0D1F10 01CFC025 */  or    $t8, $t6, $t7
/* 106A44 7F0D1F14 AC580004 */  sw    $t8, 4($v0)
/* 106A48 7F0D1F18 24840008 */  addiu $a0, $a0, 8
/* 106A4C 7F0D1F1C 44084000 */  mfc1  $t0, $f8
/* 106A50 7F0D1F20 00000000 */  nop   
/* 106A54 7F0D1F24 050200F2 */  bltzl $t0, .L7F0D22F0
/* 106A58 7F0D1F28 8FBF002C */   lw    $ra, 0x2c($sp)
/* 106A5C 7F0D1F2C 44805000 */  mtc1  $zero, $f10
/* 106A60 7F0D1F30 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106A64 7F0D1F34 44819000 */  mtc1  $at, $f18
/* 106A68 7F0D1F38 46805420 */  cvt.s.w $f16, $f10
/* 106A6C 7F0D1F3C 24180001 */  li    $t8, 1
/* 106A70 7F0D1F40 44985000 */  mtc1  $t8, $f10
/* 106A74 7F0D1F44 3C01F600 */  lui   $at, 0xf600
/* 106A78 7F0D1F48 24180002 */  li    $t8, 2
/* 106A7C 7F0D1F4C 000080C0 */  sll   $s0, $zero, 3
/* 106A80 7F0D1F50 46128102 */  mul.s $f4, $f16, $f18
/* 106A84 7F0D1F54 02008023 */  subu  $s0, $s0, $zero
/* 106A88 7F0D1F58 000848C0 */  sll   $t1, $t0, 3
/* 106A8C 7F0D1F5C 01284823 */  subu  $t1, $t1, $t0
/* 106A90 7F0D1F60 25290012 */  addiu $t1, $t1, 0x12
/* 106A94 7F0D1F64 26030015 */  addiu $v1, $s0, 0x15
/* 106A98 7F0D1F68 46805420 */  cvt.s.w $f16, $f10
/* 106A9C 7F0D1F6C 44985000 */  mtc1  $t8, $f10
/* 106AA0 7F0D1F70 26020012 */  addiu $v0, $s0, 0x12
/* 106AA4 7F0D1F74 241F0027 */  li    $ra, 39
/* 106AA8 7F0D1F78 241E000B */  li    $fp, 11
/* 106AAC 7F0D1F7C 46002183 */  div.s $f6, $f4, $f0
/* 106AB0 7F0D1F80 3C17F600 */  lui   $s7, 0xf600
/* 106AB4 7F0D1F84 4600320D */  trunc.w.s $f8, $f6
/* 106AB8 7F0D1F88 44054000 */  mfc1  $a1, $f8
/* 106ABC 7F0D1F8C 00000000 */  nop   
/* 106AC0 7F0D1F90 24A50032 */  addiu $a1, $a1, 0x32
/* 106AC4 7F0D1F94 30AF03FF */  andi  $t7, $a1, 0x3ff
/* 106AC8 7F0D1F98 000F2B80 */  sll   $a1, $t7, 0xe
/* 106ACC 7F0D1F9C 00A15025 */  or    $t2, $a1, $at
/* 106AD0 7F0D1FA0 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106AD4 7F0D1FA4 44819000 */  mtc1  $at, $f18
/* 106AD8 7F0D1FA8 3C01F600 */  lui   $at, 0xf600
/* 106ADC 7F0D1FAC 46128102 */  mul.s $f4, $f16, $f18
/* 106AE0 7F0D1FB0 46805420 */  cvt.s.w $f16, $f10
/* 106AE4 7F0D1FB4 46002183 */  div.s $f6, $f4, $f0
/* 106AE8 7F0D1FB8 4600320D */  trunc.w.s $f8, $f6
/* 106AEC 7F0D1FBC 44064000 */  mfc1  $a2, $f8
/* 106AF0 7F0D1FC0 00000000 */  nop   
/* 106AF4 7F0D1FC4 24C60032 */  addiu $a2, $a2, 0x32
/* 106AF8 7F0D1FC8 30CF03FF */  andi  $t7, $a2, 0x3ff
/* 106AFC 7F0D1FCC 000F3380 */  sll   $a2, $t7, 0xe
/* 106B00 7F0D1FD0 00C15825 */  or    $t3, $a2, $at
/* 106B04 7F0D1FD4 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106B08 7F0D1FD8 44819000 */  mtc1  $at, $f18
/* 106B0C 7F0D1FDC 3C01F600 */  lui   $at, 0xf600
/* 106B10 7F0D1FE0 46128102 */  mul.s $f4, $f16, $f18
/* 106B14 7F0D1FE4 46002183 */  div.s $f6, $f4, $f0
/* 106B18 7F0D1FE8 4600320D */  trunc.w.s $f8, $f6
/* 106B1C 7F0D1FEC 44074000 */  mfc1  $a3, $f8
/* 106B20 7F0D1FF0 00000000 */  nop   
/* 106B24 7F0D1FF4 24E70032 */  addiu $a3, $a3, 0x32
/* 106B28 7F0D1FF8 30EF03FF */  andi  $t7, $a3, 0x3ff
/* 106B2C 7F0D1FFC 000F3B80 */  sll   $a3, $t7, 0xe
/* 106B30 7F0D2000 00E16025 */  or    $t4, $a3, $at
/* 106B34 7F0D2004 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106B38 7F0D2008 44811000 */  mtc1  $at, $f2
/* 106B3C 7F0D200C 00000000 */  nop   
/* 106B40 7F0D2010 00808025 */  move  $s0, $a0
.L7F0D2014:
/* 106B44 7F0D2014 307203FF */  andi  $s2, $v1, 0x3ff
/* 106B48 7F0D2018 305303FF */  andi  $s3, $v0, 0x3ff
/* 106B4C 7F0D201C 00137880 */  sll   $t7, $s3, 2
/* 106B50 7F0D2020 0012C080 */  sll   $t8, $s2, 2
/* 106B54 7F0D2024 0158C825 */  or    $t9, $t2, $t8
/* 106B58 7F0D2028 00AF7025 */  or    $t6, $a1, $t7
/* 106B5C 7F0D202C AE0E0004 */  sw    $t6, 4($s0)
/* 106B60 7F0D2030 AE190000 */  sw    $t9, ($s0)
/* 106B64 7F0D2034 24840008 */  addiu $a0, $a0, 8
/* 106B68 7F0D2038 00808025 */  move  $s0, $a0
/* 106B6C 7F0D203C 03009025 */  move  $s2, $t8
/* 106B70 7F0D2040 0178C025 */  or    $t8, $t3, $t8
/* 106B74 7F0D2044 00CFC825 */  or    $t9, $a2, $t7
/* 106B78 7F0D2048 AE190004 */  sw    $t9, 4($s0)
/* 106B7C 7F0D204C AE180000 */  sw    $t8, ($s0)
/* 106B80 7F0D2050 24840008 */  addiu $a0, $a0, 8
/* 106B84 7F0D2054 00808025 */  move  $s0, $a0
/* 106B88 7F0D2058 01E09825 */  move  $s3, $t7
/* 106B8C 7F0D205C 00F37025 */  or    $t6, $a3, $s3
/* 106B90 7F0D2060 01927825 */  or    $t7, $t4, $s2
/* 106B94 7F0D2064 AE0F0000 */  sw    $t7, ($s0)
/* 106B98 7F0D2068 AE0E0004 */  sw    $t6, 4($s0)
/* 106B9C 7F0D206C 24840008 */  addiu $a0, $a0, 8
/* 106BA0 7F0D2070 240D0003 */  li    $t5, 3
/* 106BA4 7F0D2074 448D7000 */  mtc1  $t5, $f14
/* 106BA8 7F0D2078 27DEFFFC */  addiu $fp, $fp, -4
/* 106BAC 7F0D207C 468073A0 */  cvt.s.w $f14, $f14
/* 106BB0 7F0D2080 46027382 */  mul.s $f14, $f14, $f2
/* 106BB4 7F0D2084 46007383 */  div.s $f14, $f14, $f0
/* 106BB8 7F0D2088 4600738D */  trunc.w.s $f14, $f14
/* 106BBC 7F0D208C 44117000 */  mfc1  $s1, $f14
/* 106BC0 7F0D2090 00000000 */  nop   
/* 106BC4 7F0D2094 26310032 */  addiu $s1, $s1, 0x32
/* 106BC8 7F0D2098 323903FF */  andi  $t9, $s1, 0x3ff
/* 106BCC 7F0D209C 00197B80 */  sll   $t7, $t9, 0xe
/* 106BD0 7F0D20A0 01F77025 */  or    $t6, $t7, $s7
/* 106BD4 7F0D20A4 01F3C825 */  or    $t9, $t7, $s3
/* 106BD8 7F0D20A8 25AF0001 */  addiu $t7, $t5, 1
/* 106BDC 7F0D20AC 448F7000 */  mtc1  $t7, $f14
/* 106BE0 7F0D20B0 00000000 */  nop   
/* 106BE4 7F0D20B4 468073A0 */  cvt.s.w $f14, $f14
/* 106BE8 7F0D20B8 46027482 */  mul.s $f18, $f14, $f2
/* 106BEC 7F0D20BC 51BE004D */  beql  $t5, $fp, .L7F0D21F4
/* 106BF0 7F0D20C0 46009403 */   div.s $f16, $f18, $f0
/* 106BF4 7F0D20C4 46009403 */  div.s $f16, $f18, $f0
.L7F0D20C8:
/* 106BF8 7F0D20C8 00808025 */  move  $s0, $a0
/* 106BFC 7F0D20CC 01D2C025 */  or    $t8, $t6, $s2
/* 106C00 7F0D20D0 AE180000 */  sw    $t8, ($s0)
/* 106C04 7F0D20D4 AE190004 */  sw    $t9, 4($s0)
/* 106C08 7F0D20D8 24840008 */  addiu $a0, $a0, 8
/* 106C0C 7F0D20DC 00808025 */  move  $s0, $a0
/* 106C10 7F0D20E0 24840008 */  addiu $a0, $a0, 8
/* 106C14 7F0D20E4 4600840D */  trunc.w.s $f16, $f16
/* 106C18 7F0D20E8 44148000 */  mfc1  $s4, $f16
/* 106C1C 7F0D20EC 00000000 */  nop   
/* 106C20 7F0D20F0 26940032 */  addiu $s4, $s4, 0x32
/* 106C24 7F0D20F4 329803FF */  andi  $t8, $s4, 0x3ff
/* 106C28 7F0D20F8 0018CB80 */  sll   $t9, $t8, 0xe
/* 106C2C 7F0D20FC 03377825 */  or    $t7, $t9, $s7
/* 106C30 7F0D2100 0333C025 */  or    $t8, $t9, $s3
/* 106C34 7F0D2104 25B90002 */  addiu $t9, $t5, 2
/* 106C38 7F0D2108 44998000 */  mtc1  $t9, $f16
/* 106C3C 7F0D210C 01F27025 */  or    $t6, $t7, $s2
/* 106C40 7F0D2110 AE0E0000 */  sw    $t6, ($s0)
/* 106C44 7F0D2114 46808420 */  cvt.s.w $f16, $f16
/* 106C48 7F0D2118 AE180004 */  sw    $t8, 4($s0)
/* 106C4C 7F0D211C 00808025 */  move  $s0, $a0
/* 106C50 7F0D2120 24840008 */  addiu $a0, $a0, 8
/* 106C54 7F0D2124 46028402 */  mul.s $f16, $f16, $f2
/* 106C58 7F0D2128 46008403 */  div.s $f16, $f16, $f0
/* 106C5C 7F0D212C 4600840D */  trunc.w.s $f16, $f16
/* 106C60 7F0D2130 44158000 */  mfc1  $s5, $f16
/* 106C64 7F0D2134 00000000 */  nop   
/* 106C68 7F0D2138 26B50032 */  addiu $s5, $s5, 0x32
/* 106C6C 7F0D213C 32AE03FF */  andi  $t6, $s5, 0x3ff
/* 106C70 7F0D2140 000EC380 */  sll   $t8, $t6, 0xe
/* 106C74 7F0D2144 0317C825 */  or    $t9, $t8, $s7
/* 106C78 7F0D2148 03137025 */  or    $t6, $t8, $s3
/* 106C7C 7F0D214C 25B80003 */  addiu $t8, $t5, 3
/* 106C80 7F0D2150 44988000 */  mtc1  $t8, $f16
/* 106C84 7F0D2154 25AD0004 */  addiu $t5, $t5, 4
/* 106C88 7F0D2158 448D7000 */  mtc1  $t5, $f14
/* 106C8C 7F0D215C 46808420 */  cvt.s.w $f16, $f16
/* 106C90 7F0D2160 03327825 */  or    $t7, $t9, $s2
/* 106C94 7F0D2164 AE0F0000 */  sw    $t7, ($s0)
/* 106C98 7F0D2168 AE0E0004 */  sw    $t6, 4($s0)
/* 106C9C 7F0D216C 00808025 */  move  $s0, $a0
/* 106CA0 7F0D2170 24840008 */  addiu $a0, $a0, 8
/* 106CA4 7F0D2174 46028402 */  mul.s $f16, $f16, $f2
/* 106CA8 7F0D2178 46008403 */  div.s $f16, $f16, $f0
/* 106CAC 7F0D217C 4600840D */  trunc.w.s $f16, $f16
/* 106CB0 7F0D2180 468073A0 */  cvt.s.w $f14, $f14
/* 106CB4 7F0D2184 44168000 */  mfc1  $s6, $f16
/* 106CB8 7F0D2188 00000000 */  nop   
/* 106CBC 7F0D218C 26D60032 */  addiu $s6, $s6, 0x32
/* 106CC0 7F0D2190 32CF03FF */  andi  $t7, $s6, 0x3ff
/* 106CC4 7F0D2194 46027382 */  mul.s $f14, $f14, $f2
/* 106CC8 7F0D2198 000F7380 */  sll   $t6, $t7, 0xe
/* 106CCC 7F0D219C 01D7C025 */  or    $t8, $t6, $s7
/* 106CD0 7F0D21A0 0312C825 */  or    $t9, $t8, $s2
/* 106CD4 7F0D21A4 AE190000 */  sw    $t9, ($s0)
/* 106CD8 7F0D21A8 01D37825 */  or    $t7, $t6, $s3
/* 106CDC 7F0D21AC AE0F0004 */  sw    $t7, 4($s0)
/* 106CE0 7F0D21B0 46007383 */  div.s $f14, $f14, $f0
/* 106CE4 7F0D21B4 4600738D */  trunc.w.s $f14, $f14
/* 106CE8 7F0D21B8 44117000 */  mfc1  $s1, $f14
/* 106CEC 7F0D21BC 00000000 */  nop   
/* 106CF0 7F0D21C0 26310032 */  addiu $s1, $s1, 0x32
/* 106CF4 7F0D21C4 323903FF */  andi  $t9, $s1, 0x3ff
/* 106CF8 7F0D21C8 00197B80 */  sll   $t7, $t9, 0xe
/* 106CFC 7F0D21CC 01F77025 */  or    $t6, $t7, $s7
/* 106D00 7F0D21D0 01F3C825 */  or    $t9, $t7, $s3
/* 106D04 7F0D21D4 25AF0001 */  addiu $t7, $t5, 1
/* 106D08 7F0D21D8 448F7000 */  mtc1  $t7, $f14
/* 106D0C 7F0D21DC 00000000 */  nop   
/* 106D10 7F0D21E0 468073A0 */  cvt.s.w $f14, $f14
/* 106D14 7F0D21E4 46027482 */  mul.s $f18, $f14, $f2
/* 106D18 7F0D21E8 55BEFFB7 */  bnel  $t5, $fp, .L7F0D20C8
/* 106D1C 7F0D21EC 46009403 */   div.s $f16, $f18, $f0
/* 106D20 7F0D21F0 46009403 */  div.s $f16, $f18, $f0
.L7F0D21F4:
/* 106D24 7F0D21F4 00808025 */  move  $s0, $a0
/* 106D28 7F0D21F8 01D2C025 */  or    $t8, $t6, $s2
/* 106D2C 7F0D21FC AE180000 */  sw    $t8, ($s0)
/* 106D30 7F0D2200 AE190004 */  sw    $t9, 4($s0)
/* 106D34 7F0D2204 24840008 */  addiu $a0, $a0, 8
/* 106D38 7F0D2208 00808025 */  move  $s0, $a0
/* 106D3C 7F0D220C 24840008 */  addiu $a0, $a0, 8
/* 106D40 7F0D2210 27DE0004 */  addiu $fp, $fp, 4
/* 106D44 7F0D2214 4600840D */  trunc.w.s $f16, $f16
/* 106D48 7F0D2218 44148000 */  mfc1  $s4, $f16
/* 106D4C 7F0D221C 00000000 */  nop   
/* 106D50 7F0D2220 26940032 */  addiu $s4, $s4, 0x32
/* 106D54 7F0D2224 329803FF */  andi  $t8, $s4, 0x3ff
/* 106D58 7F0D2228 0018CB80 */  sll   $t9, $t8, 0xe
/* 106D5C 7F0D222C 03377825 */  or    $t7, $t9, $s7
/* 106D60 7F0D2230 0333C025 */  or    $t8, $t9, $s3
/* 106D64 7F0D2234 25B90002 */  addiu $t9, $t5, 2
/* 106D68 7F0D2238 44998000 */  mtc1  $t9, $f16
/* 106D6C 7F0D223C 01F27025 */  or    $t6, $t7, $s2
/* 106D70 7F0D2240 AE0E0000 */  sw    $t6, ($s0)
/* 106D74 7F0D2244 46808420 */  cvt.s.w $f16, $f16
/* 106D78 7F0D2248 AE180004 */  sw    $t8, 4($s0)
/* 106D7C 7F0D224C 00808025 */  move  $s0, $a0
/* 106D80 7F0D2250 24840008 */  addiu $a0, $a0, 8
/* 106D84 7F0D2254 46028402 */  mul.s $f16, $f16, $f2
/* 106D88 7F0D2258 46008403 */  div.s $f16, $f16, $f0
/* 106D8C 7F0D225C 4600840D */  trunc.w.s $f16, $f16
/* 106D90 7F0D2260 44158000 */  mfc1  $s5, $f16
/* 106D94 7F0D2264 00000000 */  nop   
/* 106D98 7F0D2268 26B50032 */  addiu $s5, $s5, 0x32
/* 106D9C 7F0D226C 32AE03FF */  andi  $t6, $s5, 0x3ff
/* 106DA0 7F0D2270 000EC380 */  sll   $t8, $t6, 0xe
/* 106DA4 7F0D2274 0317C825 */  or    $t9, $t8, $s7
/* 106DA8 7F0D2278 03137025 */  or    $t6, $t8, $s3
/* 106DAC 7F0D227C 25B80003 */  addiu $t8, $t5, 3
/* 106DB0 7F0D2280 44988000 */  mtc1  $t8, $f16
/* 106DB4 7F0D2284 03327825 */  or    $t7, $t9, $s2
/* 106DB8 7F0D2288 AE0F0000 */  sw    $t7, ($s0)
/* 106DBC 7F0D228C 46808420 */  cvt.s.w $f16, $f16
/* 106DC0 7F0D2290 AE0E0004 */  sw    $t6, 4($s0)
/* 106DC4 7F0D2294 00808025 */  move  $s0, $a0
/* 106DC8 7F0D2298 24840008 */  addiu $a0, $a0, 8
/* 106DCC 7F0D229C 25AD0004 */  addiu $t5, $t5, 4
/* 106DD0 7F0D22A0 46028402 */  mul.s $f16, $f16, $f2
/* 106DD4 7F0D22A4 46008403 */  div.s $f16, $f16, $f0
/* 106DD8 7F0D22A8 4600840D */  trunc.w.s $f16, $f16
/* 106DDC 7F0D22AC 44168000 */  mfc1  $s6, $f16
/* 106DE0 7F0D22B0 00000000 */  nop   
/* 106DE4 7F0D22B4 26D60032 */  addiu $s6, $s6, 0x32
/* 106DE8 7F0D22B8 32CF03FF */  andi  $t7, $s6, 0x3ff
/* 106DEC 7F0D22BC 000F7380 */  sll   $t6, $t7, 0xe
/* 106DF0 7F0D22C0 01D7C025 */  or    $t8, $t6, $s7
/* 106DF4 7F0D22C4 0312C825 */  or    $t9, $t8, $s2
/* 106DF8 7F0D22C8 01D37825 */  or    $t7, $t6, $s3
/* 106DFC 7F0D22CC AE0F0004 */  sw    $t7, 4($s0)
/* 106E00 7F0D22D0 AE190000 */  sw    $t9, ($s0)
/* 106E04 7F0D22D4 24420007 */  addiu $v0, $v0, 7
/* 106E08 7F0D22D8 0122082A */  slt   $at, $t1, $v0
/* 106E0C 7F0D22DC 14200003 */  bnez  $at, .L7F0D22EC
/* 106E10 7F0D22E0 24630007 */   addiu $v1, $v1, 7
/* 106E14 7F0D22E4 545FFF4B */  bnel  $v0, $ra, .L7F0D2014
/* 106E18 7F0D22E8 00808025 */   move  $s0, $a0
.L7F0D22EC:
/* 106E1C 7F0D22EC 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F0D22F0:
/* 106E20 7F0D22F0 8FB00008 */  lw    $s0, 8($sp)
/* 106E24 7F0D22F4 8FB1000C */  lw    $s1, 0xc($sp)
/* 106E28 7F0D22F8 8FB20010 */  lw    $s2, 0x10($sp)
/* 106E2C 7F0D22FC 8FB30014 */  lw    $s3, 0x14($sp)
/* 106E30 7F0D2300 8FB40018 */  lw    $s4, 0x18($sp)
/* 106E34 7F0D2304 8FB5001C */  lw    $s5, 0x1c($sp)
/* 106E38 7F0D2308 8FB60020 */  lw    $s6, 0x20($sp)
/* 106E3C 7F0D230C 8FB70024 */  lw    $s7, 0x24($sp)
/* 106E40 7F0D2310 8FBE0028 */  lw    $fp, 0x28($sp)
/* 106E44 7F0D2314 27BD0030 */  addiu $sp, $sp, 0x30
/* 106E48 7F0D2318 03E00008 */  jr    $ra
/* 106E4C 7F0D231C 00801025 */   move  $v0, $a0
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0D2320(void) {
    // Node 0
    D_8004EAF4 = (f32) (((s32) (D_8004EAF4 / 10.0f) * 0xa) + 0xa);
    D_8004EAF0 = (f32) D_8004EAF4;
    return;
    // (possible return value: (((s32) (D_8004EAF4 / 10.0f) * 0xa) + 0xa))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2320
/* 106E50 7F0D2320 3C038005 */  lui   $v1, %hi(D_8004EAF4)
/* 106E54 7F0D2324 2463EAF4 */  addiu $v1, %lo(D_8004EAF4) # addiu $v1, $v1, -0x150c
/* 106E58 7F0D2328 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 106E5C 7F0D232C 44813000 */  mtc1  $at, $f6
/* 106E60 7F0D2330 C4640000 */  lwc1  $f4, ($v1)
/* 106E64 7F0D2334 3C018005 */  lui   $at, %hi(D_8004EAF0)
/* 106E68 7F0D2338 46062203 */  div.s $f8, $f4, $f6
/* 106E6C 7F0D233C 4600428D */  trunc.w.s $f10, $f8
/* 106E70 7F0D2340 44025000 */  mfc1  $v0, $f10
/* 106E74 7F0D2344 00000000 */  nop   
/* 106E78 7F0D2348 00027880 */  sll   $t7, $v0, 2
/* 106E7C 7F0D234C 01E27821 */  addu  $t7, $t7, $v0
/* 106E80 7F0D2350 000F7840 */  sll   $t7, $t7, 1
/* 106E84 7F0D2354 25E2000A */  addiu $v0, $t7, 0xa
/* 106E88 7F0D2358 44828000 */  mtc1  $v0, $f16
/* 106E8C 7F0D235C 00000000 */  nop   
/* 106E90 7F0D2360 468084A0 */  cvt.s.w $f18, $f16
/* 106E94 7F0D2364 E4720000 */  swc1  $f18, ($v1)
/* 106E98 7F0D2368 C4640000 */  lwc1  $f4, ($v1)
/* 106E9C 7F0D236C 03E00008 */  jr    $ra
/* 106EA0 7F0D2370 E424EAF0 */   swc1  $f4, %lo(D_8004EAF0)($at)
)
#endif




