#include "ultra64.h"

struct music_setup
{
  s16 stage_id;
  s16 main_music;
  s16 bg_sound;
  s16 xtrack;
};

// data
//D:8004EB10
struct music_setup music_setup_entries[] = {
{   9,    0xF, 0xFFFF,   0x29},
{0x14,    0xC, 0xFFFF,   0x26},
{0x16,   0x11, 0xFFFF,   0x3D},
{0x17,      8, 0xFFFF,   0x12},
{0x18,    0xB, 0xFFFF,   0x25},
{0x19,      3, 0xFFFF,   0x1D},
{0x1A,    0xA, 0xFFFF,   0x3E},
{0x1B,   0x10, 0xFFFF,   0x2A},
{0x1C,   0x19, 0xFFFF,   0x2E},
{0x1D,    0xE, 0xFFFF,   0x28},
{0x1E,      4, 0xFFFF,   0x20},
{0x20,   0x16, 0xFFFF,   0x2F},
{0x21,      9, 0xFFFF,   0x35},
{0x22,      7, 0xFFFF,   0x1F},
{0x23,   0x32, 0xFFFF,   0x33},
{0x24,   0x39, 0xFFFF,   0x35},
{0x25,   0x37, 0xFFFF,   0x2B},
{0x27,   0x1A, 0xFFFF,   0x15},
{0x28,      6, 0xFFFF, 0xFFFF},
{0x29,   0x13, 0xFFFF,   0x30},
{0x2A,   0x1C, 0xFFFF, 0xFFFF},
{0x2B,   0x1C,   0x35,   0x3C},
{0x36,   0x31, 0xFFFF, 0xFFFF},
{0}
};

//D:8004EBD0
s16 random_tracks[] = {
        3,     4,     5,     6,     7,     8,     9,   0xA,   0xB,   0xC,   0xD,
      0xE,   0xF,  0x10,  0x11,  0x12,  0x13,  0x15,  0x16,  0x19,  0x1A,  0x1C,
     0x1D,  0x1F,  0x20,  0x21,  0x22,  0x23,  0x24,  0x25,  0x26,  0x28,  0x29,
     0x2A,  0x2B,  0x2D,  0x2E,  0x2F,  0x30,  0x32,  0x34,  0x38,  0x39,     0
};



#ifdef NONMATCHING
void sub_GAME_7F0D2720(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2720
/* 107250 7F0D2720 3C0E8005 */  lui   $t6, %hi(music_setup_entries) # $t6, 0x8005
/* 107254 7F0D2724 85CEEB10 */  lh    $t6, %lo(music_setup_entries)($t6)
/* 107258 7F0D2728 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10725C 7F0D272C AFBF0014 */  sw    $ra, 0x14($sp)
/* 107260 7F0D2730 11C0002A */  beqz  $t6, .L7F0D27DC
/* 107264 7F0D2734 3C0A8005 */   lui   $t2, %hi(random_tracks) # $t2, 0x8005
/* 107268 7F0D2738 3C0F8005 */  lui   $t7, %hi(music_setup_entries)
/* 10726C 7F0D273C 25E2EB10 */  addiu $v0, $t7, %lo(music_setup_entries)
/* 107270 7F0D2740 84430000 */  lh    $v1, ($v0)
.L7F0D2744:
/* 107274 7F0D2744 54830022 */  bnel  $a0, $v1, .L7F0D27D0
/* 107278 7F0D2748 84430008 */   lh    $v1, 8($v0)
/* 10727C 7F0D274C 84430002 */  lh    $v1, 2($v0)
/* 107280 7F0D2750 2401FFFF */  li    $at, -1
/* 107284 7F0D2754 3C188005 */  lui   $t8, %hi(random_tracks) # $t8, 0x8005
/* 107288 7F0D2758 1461001A */  bne   $v1, $at, .L7F0D27C4
/* 10728C 7F0D275C 00000000 */   nop   
/* 107290 7F0D2760 8718EBD0 */  lh    $t8, %lo(random_tracks)($t8)
/* 107294 7F0D2764 3C028005 */  lui   $v0, %hi(random_tracks) # $v0, 0x8005
/* 107298 7F0D2768 00001825 */  move  $v1, $zero
/* 10729C 7F0D276C 13000006 */  beqz  $t8, .L7F0D2788
/* 1072A0 7F0D2770 2442EBD0 */   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
/* 1072A4 7F0D2774 84590002 */  lh    $t9, 2($v0)
.L7F0D2778:
/* 1072A8 7F0D2778 24630001 */  addiu $v1, $v1, 1
/* 1072AC 7F0D277C 24420002 */  addiu $v0, $v0, 2
/* 1072B0 7F0D2780 5720FFFD */  bnezl $t9, .L7F0D2778
/* 1072B4 7F0D2784 84590002 */   lh    $t9, 2($v0)
.L7F0D2788:
/* 1072B8 7F0D2788 0C002914 */  jal   get_random_value
/* 1072BC 7F0D278C AFA30020 */   sw    $v1, 0x20($sp)
/* 1072C0 7F0D2790 8FA30020 */  lw    $v1, 0x20($sp)
/* 1072C4 7F0D2794 3C048005 */  lui   $a0, %hi(random_tracks)
/* 1072C8 7F0D2798 0043001B */  divu  $zero, $v0, $v1
/* 1072CC 7F0D279C 00004010 */  mfhi  $t0
/* 1072D0 7F0D27A0 00084840 */  sll   $t1, $t0, 1
/* 1072D4 7F0D27A4 00892021 */  addu  $a0, $a0, $t1
/* 1072D8 7F0D27A8 8484EBD0 */  lh    $a0, %lo(random_tracks)($a0)
/* 1072DC 7F0D27AC 14600002 */  bnez  $v1, .L7F0D27B8
/* 1072E0 7F0D27B0 00000000 */   nop   
/* 1072E4 7F0D27B4 0007000D */  break 7
.L7F0D27B8:
/* 1072E8 7F0D27B8 00801025 */  move  $v0, $a0
/* 1072EC 7F0D27BC 1000001F */  b     .L7F0D283C
/* 1072F0 7F0D27C0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0D27C4:
/* 1072F4 7F0D27C4 1000001C */  b     .L7F0D2838
/* 1072F8 7F0D27C8 00601025 */   move  $v0, $v1
/* 1072FC 7F0D27CC 84430008 */  lh    $v1, 8($v0)
.L7F0D27D0:
/* 107300 7F0D27D0 24420008 */  addiu $v0, $v0, 8
/* 107304 7F0D27D4 1460FFDB */  bnez  $v1, .L7F0D2744
/* 107308 7F0D27D8 00000000 */   nop   
.L7F0D27DC:
/* 10730C 7F0D27DC 854AEBD0 */  lh    $t2, %lo(random_tracks)($t2)
/* 107310 7F0D27E0 3C028005 */  lui   $v0, %hi(random_tracks) # $v0, 0x8005
/* 107314 7F0D27E4 00001825 */  move  $v1, $zero
/* 107318 7F0D27E8 11400006 */  beqz  $t2, .L7F0D2804
/* 10731C 7F0D27EC 2442EBD0 */   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
/* 107320 7F0D27F0 844B0002 */  lh    $t3, 2($v0)
.L7F0D27F4:
/* 107324 7F0D27F4 24630001 */  addiu $v1, $v1, 1
/* 107328 7F0D27F8 24420002 */  addiu $v0, $v0, 2
/* 10732C 7F0D27FC 5560FFFD */  bnezl $t3, .L7F0D27F4
/* 107330 7F0D2800 844B0002 */   lh    $t3, 2($v0)
.L7F0D2804:
/* 107334 7F0D2804 0C002914 */  jal   get_random_value
/* 107338 7F0D2808 AFA30018 */   sw    $v1, 0x18($sp)
/* 10733C 7F0D280C 8FA30018 */  lw    $v1, 0x18($sp)
/* 107340 7F0D2810 3C048005 */  lui   $a0, %hi(random_tracks)
/* 107344 7F0D2814 0043001B */  divu  $zero, $v0, $v1
/* 107348 7F0D2818 00006010 */  mfhi  $t4
/* 10734C 7F0D281C 000C6840 */  sll   $t5, $t4, 1
/* 107350 7F0D2820 008D2021 */  addu  $a0, $a0, $t5
/* 107354 7F0D2824 8484EBD0 */  lh    $a0, %lo(random_tracks)($a0)
/* 107358 7F0D2828 14600002 */  bnez  $v1, .L7F0D2834
/* 10735C 7F0D282C 00000000 */   nop   
/* 107360 7F0D2830 0007000D */  break 7
.L7F0D2834:
/* 107364 7F0D2834 00801025 */  move  $v0, $a0
.L7F0D2838:
/* 107368 7F0D2838 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0D283C:
/* 10736C 7F0D283C 27BD0028 */  addiu $sp, $sp, 0x28
/* 107370 7F0D2840 03E00008 */  jr    $ra
/* 107374 7F0D2844 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D2848(s32 arg0) {
    void *temp_v1;
    s32 temp_v0;
    s32 phi_v0;
    void *phi_v1;

    // Node 0
    temp_v1 = (0x80050000 + -0x14f0);
    if (music_setup_entries != 0)
    {
        // Node 1
        phi_v0 = *temp_v1;
        phi_v1 = temp_v1;
        // Node 2
        if (arg0 == phi_v0)
        {
            // Node 3
            return phi_v1->unk4;
        }
        // Node 4
        temp_v0 = phi_v1->unk8;
        phi_v0 = temp_v0;
        phi_v1 = (phi_v1 + 8);
        if (temp_v0 != 0)
        {
            goto loop_2;
        }
    }
    // Node 5
    return -1;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2848
/* 107378 7F0D2848 3C0E8005 */  lui   $t6, %hi(music_setup_entries) # $t6, 0x8005
/* 10737C 7F0D284C 85CEEB10 */  lh    $t6, %lo(music_setup_entries)($t6)
/* 107380 7F0D2850 3C0F8005 */  lui   $t7, %hi(music_setup_entries)
/* 107384 7F0D2854 25E3EB10 */  addiu $v1, $t7, %lo(music_setup_entries)
/* 107388 7F0D2858 51C0000B */  beql  $t6, $zero, .L7F0D2888
/* 10738C 7F0D285C 2402FFFF */   li    $v0, -1
/* 107390 7F0D2860 84620000 */  lh    $v0, ($v1)
.L7F0D2864:
/* 107394 7F0D2864 54820004 */  bnel  $a0, $v0, .L7F0D2878
/* 107398 7F0D2868 84620008 */   lh    $v0, 8($v1)
/* 10739C 7F0D286C 03E00008 */  jr    $ra
/* 1073A0 7F0D2870 84620004 */   lh    $v0, 4($v1)

/* 1073A4 7F0D2874 84620008 */  lh    $v0, 8($v1)
.L7F0D2878:
/* 1073A8 7F0D2878 24630008 */  addiu $v1, $v1, 8
/* 1073AC 7F0D287C 1440FFF9 */  bnez  $v0, .L7F0D2864
/* 1073B0 7F0D2880 00000000 */   nop   
/* 1073B4 7F0D2884 2402FFFF */  li    $v0, -1
.L7F0D2888:
/* 1073B8 7F0D2888 03E00008 */  jr    $ra
/* 1073BC 7F0D288C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D2890(s32 arg0) {
    void *temp_v1;
    s32 temp_v0;
    s32 phi_v0;
    void *phi_v1;

    // Node 0
    temp_v1 = (0x80050000 + -0x14f0);
    if (music_setup_entries != 0)
    {
        // Node 1
        phi_v0 = *temp_v1;
        phi_v1 = temp_v1;
        // Node 2
        if (arg0 == phi_v0)
        {
            // Node 3
            return phi_v1->unk6;
        }
        // Node 4
        temp_v0 = phi_v1->unk8;
        phi_v0 = temp_v0;
        phi_v1 = (phi_v1 + 8);
        if (temp_v0 != 0)
        {
            goto loop_2;
        }
    }
    // Node 5
    return -1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2890
/* 1073C0 7F0D2890 3C0E8005 */  lui   $t6, %hi(music_setup_entries) # $t6, 0x8005
/* 1073C4 7F0D2894 85CEEB10 */  lh    $t6, %lo(music_setup_entries)($t6)
/* 1073C8 7F0D2898 3C0F8005 */  lui   $t7, %hi(music_setup_entries)
/* 1073CC 7F0D289C 25E3EB10 */  addiu $v1, $t7, %lo(music_setup_entries)
/* 1073D0 7F0D28A0 51C0000B */  beql  $t6, $zero, .L7F0D28D0
/* 1073D4 7F0D28A4 2402FFFF */   li    $v0, -1
/* 1073D8 7F0D28A8 84620000 */  lh    $v0, ($v1)
.L7F0D28AC:
/* 1073DC 7F0D28AC 54820004 */  bnel  $a0, $v0, .L7F0D28C0
/* 1073E0 7F0D28B0 84620008 */   lh    $v0, 8($v1)
/* 1073E4 7F0D28B4 03E00008 */  jr    $ra
/* 1073E8 7F0D28B8 84620006 */   lh    $v0, 6($v1)

/* 1073EC 7F0D28BC 84620008 */  lh    $v0, 8($v1)
.L7F0D28C0:
/* 1073F0 7F0D28C0 24630008 */  addiu $v1, $v1, 8
/* 1073F4 7F0D28C4 1440FFF9 */  bnez  $v0, .L7F0D28AC
/* 1073F8 7F0D28C8 00000000 */   nop   
/* 1073FC 7F0D28CC 2402FFFF */  li    $v0, -1
.L7F0D28D0:
/* 107400 7F0D28D0 03E00008 */  jr    $ra
/* 107404 7F0D28D4 00000000 */   nop   
)
#endif



