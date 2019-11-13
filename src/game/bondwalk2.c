#include "ultra64.h"




#ifdef NONMATCHING
f32 sub_GAME_7F06ABB0(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s3                      2 arg5, s32 arg6, s32 arg7) {
    void *sp0;
    void *spC;
    void *temp_v0;
    s32 temp_f18;
    s32 temp_f8;
    s32 temp_f4;
    s32 temp_f10;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v1;
    s32 phi_a1;
    s32 phi_a2;
    s32 phi_a3;
    s32 phi_t0;
    s32 phi_v1;
    s32 phi_a0;
    void *phi_v0;
    s32 phi_a3_2;
    s32 phi_t0_2;
    s32 phi_v1_2;
    s32 phi_a0_2;
    s32 phi_a3_3;
    s32 phi_t0_3;

    // Node 0
    if (0.0f < *arg2)
    {
        // Node 1
        if (0.0f < arg2->unk4)
        {
            // Node 2
            **arg0 = 0xba001301;
            *arg0->unk4 = 0;
            temp_v0 = (*arg0 + 8);
            temp_f18 = (s32) ((*arg1 - *arg2) * 4.0f);
            temp_f8 = (s32) ((arg1->unk4 - arg2->unk4) * 4.0f);
            temp_f4 = (s32) ((*arg2 + *arg1) * 4.0f);
            temp_f10 = (s32) ((arg2->unk4 + arg1->unk4) * 4.0f);
            phi_v0 = temp_v0;
            if (temp_f4 >= 0)
            {
                // Node 3
                phi_v0 = temp_v0;
                if (temp_f10 >= 0)
                {
                    // Node 4
                    phi_a1 = temp_f18;
                    phi_a3_3 = 0;
                    phi_t0_3 = 0;
                    if (temp_f18 < 0)
                    {
                        // Node 5
                        if (arg5 != 0)
                        {
                            // Node 6
                            phi_a1 = 0;
                            phi_a3_3 = 0;
                            phi_t0_3 = ((s32) ((-temp_f18 * arg4) << 5) / (s32)                       (temp_f4 - temp_f18));
                        }
                        else
                        {
                            // Node 7
                            phi_a1 = 0;
                            phi_a3_3 = ((s32) ((-temp_f18 * arg3) << 5) / (s32)                       (temp_f4 - temp_f18));
                            phi_t0_3 = 0;
                        }
                    }
                    // Node 8
                    phi_a2 = temp_f8;
                    phi_a3_2 = phi_a3_3;
                    phi_t0_2 = phi_t0_3;
                    if (temp_f8 < 0)
                    {
                        // Node 9
                        if (arg5 != 0)
                        {
                            // Node 10
                            phi_a2 = 0;
                            phi_a3_2 = (phi_a3_3 + ((s32) ((-temp_f8 * arg3) <<                       5) / (s32) (temp_f10 - temp_f8)));
                            phi_t0_2 = phi_t0_3;
                        }
                        else
                        {
                            // Node 11
                            phi_a2 = 0;
                            phi_a3_2 = phi_a3_3;
                            phi_t0_2 = (phi_t0_3 + ((s32) ((-temp_f8 * arg4) <<                       5) / (s32) (temp_f10 - temp_f8)));
                        }
                    }
                    // Node 12
                    if (arg5 != 0)
                    {
                        // Node 13
                        phi_v1_2 = (s32) (((f32) arg3 / (arg2->unk4 + arg2->unk4                      )) * 1024.0f);
                        phi_a0_2 = (s32) (((f32) arg4 / (*arg2 + *arg2)) * 1024.                      0f);
                    }
                    else
                    {
                        // Node 14
                        phi_v1_2 = (s32) (((f32) arg3 / (*arg2 + *arg2)) * 1024.                      0f);
                        phi_a0_2 = (s32) (((f32) arg4 / (arg2->unk4 + arg2->unk4                      )) * 1024.0f);
                    }
                    // Node 15
                    phi_a3 = phi_a3_2;
                    phi_v1 = phi_v1_2;
                    if (arg6 != 0)
                    {
                        // Node 16
                        phi_a3 = (((arg3 + -1) << 5) - phi_a3_2);
                        phi_v1 = (0x10000 - phi_v1_2);
                    }
                    // Node 17
                    phi_t0 = phi_t0_2;
                    phi_a0 = phi_a0_2;
                    if (arg7 != 0)
                    {
                        // Node 18
                        phi_t0 = (((arg4 + -1) << 5) - phi_t0_2);
                        phi_a0 = (0x10000 - phi_a0_2);
                    }
                    // Node 19
                    if (arg5 != 0)
                    {
                        // Node 20
                        *temp_v0 = (s32) ((((temp_f4 & 0xfff) << 0xc) | 0xe50000                      00) | (temp_f10 & 0xfff));
                        temp_v0->unk4 = (s32) (((phi_a1 & 0xfff) << 0xc) | (phi_                      a2 & 0xfff));
                        temp_v0_2 = (temp_v0 + 8);
                        *temp_v0_2 = 0xb4000000;
                        temp_v0_2->unk4 = (s32) ((phi_a3 << 0x10) | (phi_t0 & 0x                      ffff));
                        temp_v0_4 = (temp_v0_2 + 8);
                        spC = temp_v0_4;
                        *spC = 0xb3000000;
                        spC->unk4 = (s32) ((phi_v1 << 0x10) | (phi_a0 & 0xffff))                      ;
                        phi_v0 = (temp_v0_4 + 8);
                    }
                    else
                    {
                        // Node 21
                        *temp_v0 = (s32) ((((temp_f4 & 0xfff) << 0xc) | 0xe40000                      00) | (temp_f10 & 0xfff));
                        temp_v0->unk4 = (s32) (((phi_a1 & 0xfff) << 0xc) | (phi_                      a2 & 0xfff));
                        temp_v0_3 = (temp_v0 + 8);
                        *temp_v0_3 = 0xb4000000;
                        temp_v0_3->unk4 = (s32) ((phi_a3 << 0x10) | (phi_t0 & 0x                      ffff));
                        temp_v0_5 = (temp_v0_3 + 8);
                        sp0 = temp_v0_5;
                        *sp0 = 0xb3000000;
                        sp0->unk4 = (s32) ((phi_v1 << 0x10) | (phi_a0 & 0xffff))                      ;
                        phi_v0 = (temp_v0_5 + 8);
                    }
                }
            }
            // Node 22
            temp_v1 = phi_v0;
            temp_v1->unk4 = 0x80000;
            *temp_v1 = 0xba001301;
            *arg0 = (void *) (phi_v0 + 8);
        }
    }
    // Node 23
    return 0.0f;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06ABB0
/* 09F6E0 7F06ABB0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 09F6E4 7F06ABB4 AFA40040 */  sw    $a0, 0x40($sp)
/* 09F6E8 7F06ABB8 AFA50044 */  sw    $a1, 0x44($sp)
/* 09F6EC 7F06ABBC AFA60048 */  sw    $a2, 0x48($sp)
/* 09F6F0 7F06ABC0 AFA7004C */  sw    $a3, 0x4c($sp)
/* 09F6F4 7F06ABC4 44800000 */  mtc1  $zero, $f0
/* 09F6F8 7F06ABC8 C4C40000 */  lwc1  $f4, ($a2)
/* 09F6FC 7F06ABCC 4604003C */  c.lt.s $f0, $f4
/* 09F700 7F06ABD0 00000000 */  nop   
/* 09F704 7F06ABD4 45000102 */  bc1f  .L7F06AFE0
/* 09F708 7F06ABD8 00000000 */   nop   
/* 09F70C 7F06ABDC C4C60004 */  lwc1  $f6, 4($a2)
/* 09F710 7F06ABE0 3C0BBA00 */  lui   $t3, (0xBA001301 >> 16) # lui $t3, 0xba00
/* 09F714 7F06ABE4 4606003C */  c.lt.s $f0, $f6
/* 09F718 7F06ABE8 00000000 */  nop   
/* 09F71C 7F06ABEC 450000FC */  bc1f  .L7F06AFE0
/* 09F720 7F06ABF0 00000000 */   nop   
/* 09F724 7F06ABF4 8C820000 */  lw    $v0, ($a0)
/* 09F728 7F06ABF8 356B1301 */  ori   $t3, (0xBA001301 & 0xFFFF) # ori $t3, $t3, 0x1301
/* 09F72C 7F06ABFC 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 09F730 7F06AC00 00401825 */  move  $v1, $v0
/* 09F734 7F06AC04 AC6B0000 */  sw    $t3, ($v1)
/* 09F738 7F06AC08 AC600004 */  sw    $zero, 4($v1)
/* 09F73C 7F06AC0C 8FB90048 */  lw    $t9, 0x48($sp)
/* 09F740 7F06AC10 8FB80044 */  lw    $t8, 0x44($sp)
/* 09F744 7F06AC14 44818000 */  mtc1  $at, $f16
/* 09F748 7F06AC18 C7200000 */  lwc1  $f0, ($t9)
/* 09F74C 7F06AC1C C70C0000 */  lwc1  $f12, ($t8)
/* 09F750 7F06AC20 C7220004 */  lwc1  $f2, 4($t9)
/* 09F754 7F06AC24 C70E0004 */  lwc1  $f14, 4($t8)
/* 09F758 7F06AC28 46006201 */  sub.s $f8, $f12, $f0
/* 09F75C 7F06AC2C 00003825 */  move  $a3, $zero
/* 09F760 7F06AC30 00004025 */  move  $t0, $zero
/* 09F764 7F06AC34 46027101 */  sub.s $f4, $f14, $f2
/* 09F768 7F06AC38 46104282 */  mul.s $f10, $f8, $f16
/* 09F76C 7F06AC3C 24420008 */  addiu $v0, $v0, 8
/* 09F770 7F06AC40 46102182 */  mul.s $f6, $f4, $f16
/* 09F774 7F06AC44 4600548D */  trunc.w.s $f18, $f10
/* 09F778 7F06AC48 460C0280 */  add.s $f10, $f0, $f12
/* 09F77C 7F06AC4C 44059000 */  mfc1  $a1, $f18
/* 09F780 7F06AC50 4600320D */  trunc.w.s $f8, $f6
/* 09F784 7F06AC54 46105482 */  mul.s $f18, $f10, $f16
/* 09F788 7F06AC58 460E1180 */  add.s $f6, $f2, $f14
/* 09F78C 7F06AC5C 44064000 */  mfc1  $a2, $f8
/* 09F790 7F06AC60 46103202 */  mul.s $f8, $f6, $f16
/* 09F794 7F06AC64 4600910D */  trunc.w.s $f4, $f18
/* 09F798 7F06AC68 44092000 */  mfc1  $t1, $f4
/* 09F79C 7F06AC6C 4600428D */  trunc.w.s $f10, $f8
/* 09F7A0 7F06AC70 440A5000 */  mfc1  $t2, $f10
/* 09F7A4 7F06AC74 052200D4 */  bltzl $t1, .L7F06AFC8
/* 09F7A8 7F06AC78 00401825 */   move  $v1, $v0
/* 09F7AC 7F06AC7C 054200D2 */  bltzl $t2, .L7F06AFC8
/* 09F7B0 7F06AC80 00401825 */   move  $v1, $v0
/* 09F7B4 7F06AC84 04A1002A */  bgez  $a1, .L7F06AD30
/* 09F7B8 7F06AC88 8FAC0054 */   lw    $t4, 0x54($sp)
/* 09F7BC 7F06AC8C 11800015 */  beqz  $t4, .L7F06ACE4
/* 09F7C0 7F06AC90 8FAF004C */   lw    $t7, 0x4c($sp)
/* 09F7C4 7F06AC94 8FAD0050 */  lw    $t5, 0x50($sp)
/* 09F7C8 7F06AC98 0005C823 */  negu  $t9, $a1
/* 09F7CC 7F06AC9C 0125C023 */  subu  $t8, $t1, $a1
/* 09F7D0 7F06ACA0 032D0019 */  multu $t9, $t5
/* 09F7D4 7F06ACA4 00007812 */  mflo  $t7
/* 09F7D8 7F06ACA8 000F7140 */  sll   $t6, $t7, 5
/* 09F7DC 7F06ACAC 00000000 */  nop   
/* 09F7E0 7F06ACB0 01D8001A */  div   $zero, $t6, $t8
/* 09F7E4 7F06ACB4 00004012 */  mflo  $t0
/* 09F7E8 7F06ACB8 17000002 */  bnez  $t8, .L7F06ACC4
/* 09F7EC 7F06ACBC 00000000 */   nop   
/* 09F7F0 7F06ACC0 0007000D */  break 7
.L7F06ACC4:
/* 09F7F4 7F06ACC4 2401FFFF */  li    $at, -1
/* 09F7F8 7F06ACC8 17010004 */  bne   $t8, $at, .L7F06ACDC
/* 09F7FC 7F06ACCC 3C018000 */   lui   $at, 0x8000
/* 09F800 7F06ACD0 15C10002 */  bne   $t6, $at, .L7F06ACDC
/* 09F804 7F06ACD4 00000000 */   nop   
/* 09F808 7F06ACD8 0006000D */  break 6
.L7F06ACDC:
/* 09F80C 7F06ACDC 10000014 */  b     .L7F06AD30
/* 09F810 7F06ACE0 00002825 */   move  $a1, $zero
.L7F06ACE4:
/* 09F814 7F06ACE4 0005C823 */  negu  $t9, $a1
/* 09F818 7F06ACE8 032F0019 */  multu $t9, $t7
/* 09F81C 7F06ACEC 0125C823 */  subu  $t9, $t1, $a1
/* 09F820 7F06ACF0 8FAD0050 */  lw    $t5, 0x50($sp)
/* 09F824 7F06ACF4 00007012 */  mflo  $t6
/* 09F828 7F06ACF8 000EC140 */  sll   $t8, $t6, 5
/* 09F82C 7F06ACFC 00000000 */  nop   
/* 09F830 7F06AD00 0319001A */  div   $zero, $t8, $t9
/* 09F834 7F06AD04 00003812 */  mflo  $a3
/* 09F838 7F06AD08 17200002 */  bnez  $t9, .L7F06AD14
/* 09F83C 7F06AD0C 00000000 */   nop   
/* 09F840 7F06AD10 0007000D */  break 7
.L7F06AD14:
/* 09F844 7F06AD14 2401FFFF */  li    $at, -1
/* 09F848 7F06AD18 17210004 */  bne   $t9, $at, .L7F06AD2C
/* 09F84C 7F06AD1C 3C018000 */   lui   $at, 0x8000
/* 09F850 7F06AD20 17010002 */  bne   $t8, $at, .L7F06AD2C
/* 09F854 7F06AD24 00000000 */   nop   
/* 09F858 7F06AD28 0006000D */  break 6
.L7F06AD2C:
/* 09F85C 7F06AD2C 00002825 */  move  $a1, $zero
.L7F06AD30:
/* 09F860 7F06AD30 8FAC0054 */  lw    $t4, 0x54($sp)
/* 09F864 7F06AD34 04C1002A */  bgez  $a2, .L7F06ADE0
/* 09F868 7F06AD38 8FAD0050 */   lw    $t5, 0x50($sp)
/* 09F86C 7F06AD3C 11800016 */  beqz  $t4, .L7F06AD98
/* 09F870 7F06AD40 0006C023 */   negu  $t8, $a2
/* 09F874 7F06AD44 8FAE004C */  lw    $t6, 0x4c($sp)
/* 09F878 7F06AD48 00067823 */  negu  $t7, $a2
/* 09F87C 7F06AD4C 01EE0019 */  multu $t7, $t6
/* 09F880 7F06AD50 01467823 */  subu  $t7, $t2, $a2
/* 09F884 7F06AD54 0000C012 */  mflo  $t8
/* 09F888 7F06AD58 0018C940 */  sll   $t9, $t8, 5
/* 09F88C 7F06AD5C 00000000 */  nop   
/* 09F890 7F06AD60 032F001A */  div   $zero, $t9, $t7
/* 09F894 7F06AD64 00007012 */  mflo  $t6
/* 09F898 7F06AD68 00EE3821 */  addu  $a3, $a3, $t6
/* 09F89C 7F06AD6C 15E00002 */  bnez  $t7, .L7F06AD78
/* 09F8A0 7F06AD70 00000000 */   nop   
/* 09F8A4 7F06AD74 0007000D */  break 7
.L7F06AD78:
/* 09F8A8 7F06AD78 2401FFFF */  li    $at, -1
/* 09F8AC 7F06AD7C 15E10004 */  bne   $t7, $at, .L7F06AD90
/* 09F8B0 7F06AD80 3C018000 */   lui   $at, 0x8000
/* 09F8B4 7F06AD84 17210002 */  bne   $t9, $at, .L7F06AD90
/* 09F8B8 7F06AD88 00000000 */   nop   
/* 09F8BC 7F06AD8C 0006000D */  break 6
.L7F06AD90:
/* 09F8C0 7F06AD90 10000013 */  b     .L7F06ADE0
/* 09F8C4 7F06AD94 00003025 */   move  $a2, $zero
.L7F06AD98:
/* 09F8C8 7F06AD98 030D0019 */  multu $t8, $t5
/* 09F8CC 7F06AD9C 01467023 */  subu  $t6, $t2, $a2
/* 09F8D0 7F06ADA0 0000C812 */  mflo  $t9
/* 09F8D4 7F06ADA4 00197940 */  sll   $t7, $t9, 5
/* 09F8D8 7F06ADA8 00000000 */  nop   
/* 09F8DC 7F06ADAC 01EE001A */  div   $zero, $t7, $t6
/* 09F8E0 7F06ADB0 0000C012 */  mflo  $t8
/* 09F8E4 7F06ADB4 01184021 */  addu  $t0, $t0, $t8
/* 09F8E8 7F06ADB8 15C00002 */  bnez  $t6, .L7F06ADC4
/* 09F8EC 7F06ADBC 00000000 */   nop   
/* 09F8F0 7F06ADC0 0007000D */  break 7
.L7F06ADC4:
/* 09F8F4 7F06ADC4 2401FFFF */  li    $at, -1
/* 09F8F8 7F06ADC8 15C10004 */  bne   $t6, $at, .L7F06ADDC
/* 09F8FC 7F06ADCC 3C018000 */   lui   $at, 0x8000
/* 09F900 7F06ADD0 15E10002 */  bne   $t7, $at, .L7F06ADDC
/* 09F904 7F06ADD4 00000000 */   nop   
/* 09F908 7F06ADD8 0006000D */  break 6
.L7F06ADDC:
/* 09F90C 7F06ADDC 00003025 */  move  $a2, $zero
.L7F06ADE0:
/* 09F910 7F06ADE0 11800015 */  beqz  $t4, .L7F06AE38
/* 09F914 7F06ADE4 8FAE0058 */   lw    $t6, 0x58($sp)
/* 09F918 7F06ADE8 8FB9004C */  lw    $t9, 0x4c($sp)
/* 09F91C 7F06ADEC 46021180 */  add.s $f6, $f2, $f2
/* 09F920 7F06ADF0 3C014480 */  li    $at, 0x44800000 # 1024.000000
/* 09F924 7F06ADF4 44999000 */  mtc1  $t9, $f18
/* 09F928 7F06ADF8 44816000 */  mtc1  $at, $f12
/* 09F92C 7F06ADFC 46809120 */  cvt.s.w $f4, $f18
/* 09F930 7F06AE00 46062203 */  div.s $f8, $f4, $f6
/* 09F934 7F06AE04 448D2000 */  mtc1  $t5, $f4
/* 09F938 7F06AE08 00000000 */  nop   
/* 09F93C 7F06AE0C 468021A0 */  cvt.s.w $f6, $f4
/* 09F940 7F06AE10 460C4282 */  mul.s $f10, $f8, $f12
/* 09F944 7F06AE14 46000200 */  add.s $f8, $f0, $f0
/* 09F948 7F06AE18 4600548D */  trunc.w.s $f18, $f10
/* 09F94C 7F06AE1C 46083283 */  div.s $f10, $f6, $f8
/* 09F950 7F06AE20 44039000 */  mfc1  $v1, $f18
/* 09F954 7F06AE24 460C5482 */  mul.s $f18, $f10, $f12
/* 09F958 7F06AE28 4600910D */  trunc.w.s $f4, $f18
/* 09F95C 7F06AE2C 44042000 */  mfc1  $a0, $f4
/* 09F960 7F06AE30 10000014 */  b     .L7F06AE84
/* 09F964 7F06AE34 00000000 */   nop   
.L7F06AE38:
/* 09F968 7F06AE38 8FB8004C */  lw    $t8, 0x4c($sp)
/* 09F96C 7F06AE3C 46000280 */  add.s $f10, $f0, $f0
/* 09F970 7F06AE40 3C014480 */  li    $at, 0x44800000 # 1024.000000
/* 09F974 7F06AE44 44983000 */  mtc1  $t8, $f6
/* 09F978 7F06AE48 44816000 */  mtc1  $at, $f12
/* 09F97C 7F06AE4C 46803220 */  cvt.s.w $f8, $f6
/* 09F980 7F06AE50 460A4483 */  div.s $f18, $f8, $f10
/* 09F984 7F06AE54 448D4000 */  mtc1  $t5, $f8
/* 09F988 7F06AE58 00000000 */  nop   
/* 09F98C 7F06AE5C 468042A0 */  cvt.s.w $f10, $f8
/* 09F990 7F06AE60 460C9102 */  mul.s $f4, $f18, $f12
/* 09F994 7F06AE64 46021480 */  add.s $f18, $f2, $f2
/* 09F998 7F06AE68 4600218D */  trunc.w.s $f6, $f4
/* 09F99C 7F06AE6C 46125103 */  div.s $f4, $f10, $f18
/* 09F9A0 7F06AE70 44033000 */  mfc1  $v1, $f6
/* 09F9A4 7F06AE74 460C2182 */  mul.s $f6, $f4, $f12
/* 09F9A8 7F06AE78 4600320D */  trunc.w.s $f8, $f6
/* 09F9AC 7F06AE7C 44044000 */  mfc1  $a0, $f8
/* 09F9B0 7F06AE80 00000000 */  nop   
.L7F06AE84:
/* 09F9B4 7F06AE84 11C00006 */  beqz  $t6, .L7F06AEA0
/* 09F9B8 7F06AE88 8FB9004C */   lw    $t9, 0x4c($sp)
/* 09F9BC 7F06AE8C 272FFFFF */  addiu $t7, $t9, -1
/* 09F9C0 7F06AE90 3C180001 */  lui   $t8, 1
/* 09F9C4 7F06AE94 000F7140 */  sll   $t6, $t7, 5
/* 09F9C8 7F06AE98 03031823 */  subu  $v1, $t8, $v1
/* 09F9CC 7F06AE9C 01C73823 */  subu  $a3, $t6, $a3
.L7F06AEA0:
/* 09F9D0 7F06AEA0 8FB8005C */  lw    $t8, 0x5c($sp)
/* 09F9D4 7F06AEA4 25AFFFFF */  addiu $t7, $t5, -1
/* 09F9D8 7F06AEA8 3C190001 */  lui   $t9, 1
/* 09F9DC 7F06AEAC 13000003 */  beqz  $t8, .L7F06AEBC
/* 09F9E0 7F06AEB0 000F7140 */   sll   $t6, $t7, 5
/* 09F9E4 7F06AEB4 03242023 */  subu  $a0, $t9, $a0
/* 09F9E8 7F06AEB8 01C84023 */  subu  $t0, $t6, $t0
.L7F06AEBC:
/* 09F9EC 7F06AEBC 11800022 */  beqz  $t4, .L7F06AF48
/* 09F9F0 7F06AEC0 31390FFF */   andi  $t9, $t1, 0xfff
/* 09F9F4 7F06AEC4 31380FFF */  andi  $t8, $t1, 0xfff
/* 09F9F8 7F06AEC8 0018CB00 */  sll   $t9, $t8, 0xc
/* 09F9FC 7F06AECC 3C01E500 */  lui   $at, 0xe500
/* 09FA00 7F06AED0 03217825 */  or    $t7, $t9, $at
/* 09FA04 7F06AED4 314E0FFF */  andi  $t6, $t2, 0xfff
/* 09FA08 7F06AED8 01EEC025 */  or    $t8, $t7, $t6
/* 09FA0C 7F06AEDC 30B90FFF */  andi  $t9, $a1, 0xfff
/* 09FA10 7F06AEE0 00406025 */  move  $t4, $v0
/* 09FA14 7F06AEE4 AD980000 */  sw    $t8, ($t4)
/* 09FA18 7F06AEE8 00197B00 */  sll   $t7, $t9, 0xc
/* 09FA1C 7F06AEEC 30CE0FFF */  andi  $t6, $a2, 0xfff
/* 09FA20 7F06AEF0 01EEC025 */  or    $t8, $t7, $t6
/* 09FA24 7F06AEF4 AD980004 */  sw    $t8, 4($t4)
/* 09FA28 7F06AEF8 24420008 */  addiu $v0, $v0, 8
/* 09FA2C 7F06AEFC 00406825 */  move  $t5, $v0
/* 09FA30 7F06AF00 3C19B400 */  lui   $t9, 0xb400
/* 09FA34 7F06AF04 ADB90000 */  sw    $t9, ($t5)
/* 09FA38 7F06AF08 3118FFFF */  andi  $t8, $t0, 0xffff
/* 09FA3C 7F06AF0C 00077400 */  sll   $t6, $a3, 0x10
/* 09FA40 7F06AF10 01D8C825 */  or    $t9, $t6, $t8
/* 09FA44 7F06AF14 ADB90004 */  sw    $t9, 4($t5)
/* 09FA48 7F06AF18 24420008 */  addiu $v0, $v0, 8
/* 09FA4C 7F06AF1C AFA2000C */  sw    $v0, 0xc($sp)
/* 09FA50 7F06AF20 8FAE000C */  lw    $t6, 0xc($sp)
/* 09FA54 7F06AF24 3C0FB300 */  lui   $t7, 0xb300
/* 09FA58 7F06AF28 0003CC00 */  sll   $t9, $v1, 0x10
/* 09FA5C 7F06AF2C ADCF0000 */  sw    $t7, ($t6)
/* 09FA60 7F06AF30 8FB8000C */  lw    $t8, 0xc($sp)
/* 09FA64 7F06AF34 308FFFFF */  andi  $t7, $a0, 0xffff
/* 09FA68 7F06AF38 032F7025 */  or    $t6, $t9, $t7
/* 09FA6C 7F06AF3C 24420008 */  addiu $v0, $v0, 8
/* 09FA70 7F06AF40 10000020 */  b     .L7F06AFC4
/* 09FA74 7F06AF44 AF0E0004 */   sw    $t6, 4($t8)
.L7F06AF48:
/* 09FA78 7F06AF48 00197B00 */  sll   $t7, $t9, 0xc
/* 09FA7C 7F06AF4C 3C01E400 */  lui   $at, 0xe400
/* 09FA80 7F06AF50 01E17025 */  or    $t6, $t7, $at
/* 09FA84 7F06AF54 31580FFF */  andi  $t8, $t2, 0xfff
/* 09FA88 7F06AF58 01D8C825 */  or    $t9, $t6, $t8
/* 09FA8C 7F06AF5C 30AF0FFF */  andi  $t7, $a1, 0xfff
/* 09FA90 7F06AF60 00406025 */  move  $t4, $v0
/* 09FA94 7F06AF64 AD990000 */  sw    $t9, ($t4)
/* 09FA98 7F06AF68 000F7300 */  sll   $t6, $t7, 0xc
/* 09FA9C 7F06AF6C 30D80FFF */  andi  $t8, $a2, 0xfff
/* 09FAA0 7F06AF70 01D8C825 */  or    $t9, $t6, $t8
/* 09FAA4 7F06AF74 AD990004 */  sw    $t9, 4($t4)
/* 09FAA8 7F06AF78 24420008 */  addiu $v0, $v0, 8
/* 09FAAC 7F06AF7C 00406825 */  move  $t5, $v0
/* 09FAB0 7F06AF80 3C0FB400 */  lui   $t7, 0xb400
/* 09FAB4 7F06AF84 ADAF0000 */  sw    $t7, ($t5)
/* 09FAB8 7F06AF88 3119FFFF */  andi  $t9, $t0, 0xffff
/* 09FABC 7F06AF8C 0007C400 */  sll   $t8, $a3, 0x10
/* 09FAC0 7F06AF90 03197825 */  or    $t7, $t8, $t9
/* 09FAC4 7F06AF94 ADAF0004 */  sw    $t7, 4($t5)
/* 09FAC8 7F06AF98 24420008 */  addiu $v0, $v0, 8
/* 09FACC 7F06AF9C AFA20000 */  sw    $v0, ($sp)
/* 09FAD0 7F06AFA0 8FB80000 */  lw    $t8, ($sp)
/* 09FAD4 7F06AFA4 3C0EB300 */  lui   $t6, 0xb300
/* 09FAD8 7F06AFA8 00037C00 */  sll   $t7, $v1, 0x10
/* 09FADC 7F06AFAC AF0E0000 */  sw    $t6, ($t8)
/* 09FAE0 7F06AFB0 8FB90000 */  lw    $t9, ($sp)
/* 09FAE4 7F06AFB4 308EFFFF */  andi  $t6, $a0, 0xffff
/* 09FAE8 7F06AFB8 01EEC025 */  or    $t8, $t7, $t6
/* 09FAEC 7F06AFBC 24420008 */  addiu $v0, $v0, 8
/* 09FAF0 7F06AFC0 AF380004 */  sw    $t8, 4($t9)
.L7F06AFC4:
/* 09FAF4 7F06AFC4 00401825 */  move  $v1, $v0
.L7F06AFC8:
/* 09FAF8 7F06AFC8 3C0F0008 */  lui   $t7, 8
/* 09FAFC 7F06AFCC AC6F0004 */  sw    $t7, 4($v1)
/* 09FB00 7F06AFD0 AC6B0000 */  sw    $t3, ($v1)
/* 09FB04 7F06AFD4 8FAE0040 */  lw    $t6, 0x40($sp)
/* 09FB08 7F06AFD8 24420008 */  addiu $v0, $v0, 8
/* 09FB0C 7F06AFDC ADC20000 */  sw    $v0, ($t6)
.L7F06AFE0:
/* 09FB10 7F06AFE0 03E00008 */  jr    $ra
/* 09FB14 7F06AFE4 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





#ifdef NONMATCHING
f32 display_image_at_on_screen_coord(void *arg0, void *arg2, ?32 arg4, ?32 arg5, ?32 arg6, ?32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    void *temp_v0;
    void *phi_v0;
    f32 phi_return_reg;

    // Node 0
    phi_return_reg = 0.0f;
    if (0.0f < *arg2)
    {
        // Node 1
        phi_return_reg = 0.0f;
        if (0.0f < arg2->unk4)
        {
            // Node 2
            **arg0 = 0xfb000000;
            *arg0->unk4 = (s32) ((((arg8 << 0x18) | ((arg9 & 0xff) << 0x10)) | ((argA & 0xff) << 8)) | (argB & 0xff));
            temp_v0 = (*arg0 + 8);
            if (argC != 0)
            {
                // Node 3
                *temp_v0 = 0xfc26a005;
                temp_v0->unk4 = 0x1f1493ff;
                phi_v0 = (temp_v0 + 8);
            }
            else
            {
                // Node 4
                if (argD != 0)
                {
                    // Node 5
                    temp_v0->unk4 = -0x1c8;
                    *temp_v0 = 0xfc129bff;
                    phi_v0 = (temp_v0 + 8);
                }
                else
                {
                    // Node 6
                    *temp_v0 = 0xfc129a25;
                    temp_v0->unk4 = 0xff37ffff;
                    phi_v0 = (temp_v0 + 8);
                }
            }
            // Node 7
            *arg0 = (void *) phi_v0;
            phi_return_reg = sub_GAME_7F06ABB0(arg4, arg5, arg6, arg7);
        }
    }
    // Node 8
    return phi_return_reg;
}
#else
GLOBAL_ASM(
.text
glabel display_image_at_on_screen_coord
/* 09FB18 7F06AFE8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 09FB1C 7F06AFEC AFBF0024 */  sw    $ra, 0x24($sp)
/* 09FB20 7F06AFF0 44800000 */  mtc1  $zero, $f0
/* 09FB24 7F06AFF4 C4C40000 */  lwc1  $f4, ($a2)
/* 09FB28 7F06AFF8 4604003C */  c.lt.s $f0, $f4
/* 09FB2C 7F06AFFC 00000000 */  nop   
/* 09FB30 7F06B000 45020041 */  bc1fl .L7F06B108
/* 09FB34 7F06B004 8FBF0024 */   lw    $ra, 0x24($sp)
/* 09FB38 7F06B008 C4C60004 */  lwc1  $f6, 4($a2)
/* 09FB3C 7F06B00C 4606003C */  c.lt.s $f0, $f6
/* 09FB40 7F06B010 00000000 */  nop   
/* 09FB44 7F06B014 4502003C */  bc1fl .L7F06B108
/* 09FB48 7F06B018 8FBF0024 */   lw    $ra, 0x24($sp)
/* 09FB4C 7F06B01C 8C820000 */  lw    $v0, ($a0)
/* 09FB50 7F06B020 3C0EFB00 */  lui   $t6, 0xfb00
/* 09FB54 7F06B024 00401825 */  move  $v1, $v0
/* 09FB58 7F06B028 AC6E0000 */  sw    $t6, ($v1)
/* 09FB5C 7F06B02C 8FB80048 */  lw    $t8, 0x48($sp)
/* 09FB60 7F06B030 8FA8004C */  lw    $t0, 0x4c($sp)
/* 09FB64 7F06B034 8FAC0050 */  lw    $t4, 0x50($sp)
/* 09FB68 7F06B038 0018CE00 */  sll   $t9, $t8, 0x18
/* 09FB6C 7F06B03C 8FB80054 */  lw    $t8, 0x54($sp)
/* 09FB70 7F06B040 310900FF */  andi  $t1, $t0, 0xff
/* 09FB74 7F06B044 00095400 */  sll   $t2, $t1, 0x10
/* 09FB78 7F06B048 318D00FF */  andi  $t5, $t4, 0xff
/* 09FB7C 7F06B04C 000D7200 */  sll   $t6, $t5, 8
/* 09FB80 7F06B050 032A5825 */  or    $t3, $t9, $t2
/* 09FB84 7F06B054 016E7825 */  or    $t7, $t3, $t6
/* 09FB88 7F06B058 330800FF */  andi  $t0, $t8, 0xff
/* 09FB8C 7F06B05C 01E84825 */  or    $t1, $t7, $t0
/* 09FB90 7F06B060 AC690004 */  sw    $t1, 4($v1)
/* 09FB94 7F06B064 8FB90058 */  lw    $t9, 0x58($sp)
/* 09FB98 7F06B068 24420008 */  addiu $v0, $v0, 8
/* 09FB9C 7F06B06C 00401825 */  move  $v1, $v0
/* 09FBA0 7F06B070 13200009 */  beqz  $t9, .L7F06B098
/* 09FBA4 7F06B074 8FAD005C */   lw    $t5, 0x5c($sp)
/* 09FBA8 7F06B078 3C0AFC26 */  lui   $t2, (0xFC26A005 >> 16) # lui $t2, 0xfc26
/* 09FBAC 7F06B07C 3C0C1F14 */  lui   $t4, (0x1F1493FF >> 16) # lui $t4, 0x1f14
/* 09FBB0 7F06B080 358C93FF */  ori   $t4, (0x1F1493FF & 0xFFFF) # ori $t4, $t4, 0x93ff
/* 09FBB4 7F06B084 354AA005 */  ori   $t2, (0xFC26A005 & 0xFFFF) # ori $t2, $t2, 0xa005
/* 09FBB8 7F06B088 AC6A0000 */  sw    $t2, ($v1)
/* 09FBBC 7F06B08C AC6C0004 */  sw    $t4, 4($v1)
/* 09FBC0 7F06B090 10000012 */  b     .L7F06B0DC
/* 09FBC4 7F06B094 24420008 */   addiu $v0, $v0, 8
.L7F06B098:
/* 09FBC8 7F06B098 11A00009 */  beqz  $t5, .L7F06B0C0
/* 09FBCC 7F06B09C 00401825 */   move  $v1, $v0
/* 09FBD0 7F06B0A0 00401825 */  move  $v1, $v0
/* 09FBD4 7F06B0A4 3C0BFC12 */  lui   $t3, (0xFC129BFF >> 16) # lui $t3, 0xfc12
/* 09FBD8 7F06B0A8 356B9BFF */  ori   $t3, (0xFC129BFF & 0xFFFF) # ori $t3, $t3, 0x9bff
/* 09FBDC 7F06B0AC 240EFE38 */  li    $t6, -456
/* 09FBE0 7F06B0B0 AC6E0004 */  sw    $t6, 4($v1)
/* 09FBE4 7F06B0B4 AC6B0000 */  sw    $t3, ($v1)
/* 09FBE8 7F06B0B8 10000008 */  b     .L7F06B0DC
/* 09FBEC 7F06B0BC 24420008 */   addiu $v0, $v0, 8
.L7F06B0C0:
/* 09FBF0 7F06B0C0 3C18FC12 */  lui   $t8, (0xFC129A25 >> 16) # lui $t8, 0xfc12
/* 09FBF4 7F06B0C4 3C0FFF37 */  lui   $t7, (0xFF37FFFF >> 16) # lui $t7, 0xff37
/* 09FBF8 7F06B0C8 35EFFFFF */  ori   $t7, (0xFF37FFFF & 0xFFFF) # ori $t7, $t7, 0xffff
/* 09FBFC 7F06B0CC 37189A25 */  ori   $t8, (0xFC129A25 & 0xFFFF) # ori $t8, $t8, 0x9a25
/* 09FC00 7F06B0D0 AC780000 */  sw    $t8, ($v1)
/* 09FC04 7F06B0D4 AC6F0004 */  sw    $t7, 4($v1)
/* 09FC08 7F06B0D8 24420008 */  addiu $v0, $v0, 8
.L7F06B0DC:
/* 09FC0C 7F06B0DC AC820000 */  sw    $v0, ($a0)
/* 09FC10 7F06B0E0 8FAA0044 */  lw    $t2, 0x44($sp)
/* 09FC14 7F06B0E4 8FB90040 */  lw    $t9, 0x40($sp)
/* 09FC18 7F06B0E8 8FA9003C */  lw    $t1, 0x3c($sp)
/* 09FC1C 7F06B0EC 8FA80038 */  lw    $t0, 0x38($sp)
/* 09FC20 7F06B0F0 AFAA001C */  sw    $t2, 0x1c($sp)
/* 09FC24 7F06B0F4 AFB90018 */  sw    $t9, 0x18($sp)
/* 09FC28 7F06B0F8 AFA90014 */  sw    $t1, 0x14($sp)
/* 09FC2C 7F06B0FC 0FC1AAEC */  jal   sub_GAME_7F06ABB0
/* 09FC30 7F06B100 AFA80010 */   sw    $t0, 0x10($sp)
/* 09FC34 7F06B104 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06B108:
/* 09FC38 7F06B108 27BD0028 */  addiu $sp, $sp, 0x28
/* 09FC3C 7F06B10C 03E00008 */  jr    $ra
/* 09FC40 7F06B110 00000000 */   nop   
)
#endif




