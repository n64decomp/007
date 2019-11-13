#include "ultra64.h"

// bss
//CODE.bss:8007A0D0
s32 dword_CODE_bss_8007A0D0;
//CODE.bss:8007A0D4
s32 dword_CODE_bss_8007A0D4;
//CODE.bss:8007A0D8
s32 dword_CODE_bss_8007A0D8;
//CODE.bss:8007A0DC
s32 dword_CODE_bss_8007A0DC;
//CODE.bss:8007A0E0
s32 dword_CODE_bss_8007A0E0;
//CODE.bss:8007A0E4
s32 dword_CODE_bss_8007A0E4;
//CODE.bss:8007A0E8
s32 dword_CODE_bss_8007A0E8;
//CODE.bss:8007A0EC
s32 dword_CODE_bss_8007A0EC;
//CODE.bss:8007A0F0
s16 word_CODE_bss_8007A0F0;
//CODE.bss:8007A0F2
s16 word_CODE_bss_8007A0F2;



void null_init_main_1(void) {
    return;
}




#ifdef NONMATCHING
void sub_GAME_7F09B7A8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B7A8
/* 0D02D8 7F09B7A8 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0D4)
/* 0D02DC 7F09B7AC 8C63A0D4 */  lw    $v1, %lo(dword_CODE_bss_8007A0D4)($v1)
/* 0D02E0 7F09B7B0 00001025 */  move  $v0, $zero
/* 0D02E4 7F09B7B4 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0E8)
/* 0D02E8 7F09B7B8 18600008 */  blez  $v1, .L7F09B7DC
/* 0D02EC 7F09B7BC 00032880 */   sll   $a1, $v1, 2
/* 0D02F0 7F09B7C0 00A32821 */  addu  $a1, $a1, $v1
/* 0D02F4 7F09B7C4 00052880 */  sll   $a1, $a1, 2
/* 0D02F8 7F09B7C8 8C84A0E8 */  lw    $a0, %lo(dword_CODE_bss_8007A0E8)($a0)
.L7F09B7CC:
/* 0D02FC 7F09B7CC 24420014 */  addiu $v0, $v0, 0x14
/* 0D0300 7F09B7D0 0045082A */  slt   $at, $v0, $a1
/* 0D0304 7F09B7D4 1420FFFD */  bnez  $at, .L7F09B7CC
/* 0D0308 7F09B7D8 24840014 */   addiu $a0, $a0, 0x14
.L7F09B7DC:
/* 0D030C 7F09B7DC 03E00008 */  jr    $ra
/* 0D0310 7F09B7E0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B7E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B7E4
/* 0D0314 7F09B7E4 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0DC)
/* 0D0318 7F09B7E8 8C63A0DC */  lw    $v1, %lo(dword_CODE_bss_8007A0DC)($v1)
/* 0D031C 7F09B7EC 00001025 */  move  $v0, $zero
/* 0D0320 7F09B7F0 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0EC)
/* 0D0324 7F09B7F4 18600008 */  blez  $v1, .L7F09B818
/* 0D0328 7F09B7F8 00032880 */   sll   $a1, $v1, 2
/* 0D032C 7F09B7FC 00A32821 */  addu  $a1, $a1, $v1
/* 0D0330 7F09B800 00052880 */  sll   $a1, $a1, 2
/* 0D0334 7F09B804 8C84A0EC */  lw    $a0, %lo(dword_CODE_bss_8007A0EC)($a0)
.L7F09B808:
/* 0D0338 7F09B808 24420014 */  addiu $v0, $v0, 0x14
/* 0D033C 7F09B80C 0045082A */  slt   $at, $v0, $a1
/* 0D0340 7F09B810 1420FFFD */  bnez  $at, .L7F09B808
/* 0D0344 7F09B814 24840014 */   addiu $a0, $a0, 0x14
.L7F09B818:
/* 0D0348 7F09B818 03E00008 */  jr    $ra
/* 0D034C 7F09B81C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B820(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B820
/* 0D0350 7F09B820 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0D0354 7F09B824 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D0358 7F09B828 0FC26919 */  jal   get_num_players
/* 0D035C 7F09B82C 00000000 */   nop   
/* 0D0360 7F09B830 28410002 */  slti  $at, $v0, 2
/* 0D0364 7F09B834 1420000F */  bnez  $at, .L7F09B874
/* 0D0368 7F09B838 240201F4 */   li    $v0, 500
/* 0D036C 7F09B83C 240E0BB8 */  li    $t6, 3000
/* 0D0370 7F09B840 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D0)
/* 0D0374 7F09B844 3C088008 */  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
/* 0D0378 7F09B848 AC2EA0D0 */  sw    $t6, %lo(dword_CODE_bss_8007A0D0)($at)
/* 0D037C 7F09B84C 2508A0D4 */  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
/* 0D0380 7F09B850 240F0050 */  li    $t7, 80
/* 0D0384 7F09B854 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
/* 0D0388 7F09B858 AD0F0000 */  sw    $t7, ($t0)
/* 0D038C 7F09B85C 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D8)
/* 0D0390 7F09B860 2529A0DC */  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
/* 0D0394 7F09B864 24030014 */  li    $v1, 20
/* 0D0398 7F09B868 AC22A0D8 */  sw    $v0, %lo(dword_CODE_bss_8007A0D8)($at)
/* 0D039C 7F09B86C 10000022 */  b     .L7F09B8F8
/* 0D03A0 7F09B870 AD230000 */   sw    $v1, ($t1)
.L7F09B874:
/* 0D03A4 7F09B874 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 0D03A8 7F09B878 00000000 */   nop   
/* 0D03AC 7F09B87C 2401001E */  li    $at, 30
/* 0D03B0 7F09B880 10410011 */  beq   $v0, $at, .L7F09B8C8
/* 0D03B4 7F09B884 2401001D */   li    $at, 29
/* 0D03B8 7F09B888 1041000F */  beq   $v0, $at, .L7F09B8C8
/* 0D03BC 7F09B88C 24030014 */   li    $v1, 20
/* 0D03C0 7F09B890 240201F4 */  li    $v0, 500
/* 0D03C4 7F09B894 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D0)
/* 0D03C8 7F09B898 3C088008 */  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
/* 0D03CC 7F09B89C AC22A0D0 */  sw    $v0, %lo(dword_CODE_bss_8007A0D0)($at)
/* 0D03D0 7F09B8A0 2508A0D4 */  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
/* 0D03D4 7F09B8A4 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
/* 0D03D8 7F09B8A8 AD030000 */  sw    $v1, ($t0)
/* 0D03DC 7F09B8AC 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D8)
/* 0D03E0 7F09B8B0 241805DC */  li    $t8, 1500
/* 0D03E4 7F09B8B4 2529A0DC */  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
/* 0D03E8 7F09B8B8 AC38A0D8 */  sw    $t8, %lo(dword_CODE_bss_8007A0D8)($at)
/* 0D03EC 7F09B8BC 24190028 */  li    $t9, 40
/* 0D03F0 7F09B8C0 1000000D */  b     .L7F09B8F8
/* 0D03F4 7F09B8C4 AD390000 */   sw    $t9, ($t1)
.L7F09B8C8:
/* 0D03F8 7F09B8C8 240201F4 */  li    $v0, 500
/* 0D03FC 7F09B8CC 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D0)
/* 0D0400 7F09B8D0 3C088008 */  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
/* 0D0404 7F09B8D4 AC22A0D0 */  sw    $v0, %lo(dword_CODE_bss_8007A0D0)($at)
/* 0D0408 7F09B8D8 2508A0D4 */  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
/* 0D040C 7F09B8DC 24030014 */  li    $v1, 20
/* 0D0410 7F09B8E0 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
/* 0D0414 7F09B8E4 AD030000 */  sw    $v1, ($t0)
/* 0D0418 7F09B8E8 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0D8)
/* 0D041C 7F09B8EC 2529A0DC */  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
/* 0D0420 7F09B8F0 AC22A0D8 */  sw    $v0, %lo(dword_CODE_bss_8007A0D8)($at)
/* 0D0424 7F09B8F4 AD230000 */  sw    $v1, ($t1)
.L7F09B8F8:
/* 0D0428 7F09B8F8 8D040000 */  lw    $a0, ($t0)
/* 0D042C 7F09B8FC 24050004 */  li    $a1, 4
/* 0D0430 7F09B900 00045880 */  sll   $t3, $a0, 2
/* 0D0434 7F09B904 01645821 */  addu  $t3, $t3, $a0
/* 0D0438 7F09B908 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0D043C 7F09B90C 000B2080 */   sll   $a0, $t3, 2
/* 0D0440 7F09B910 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A0E8)
/* 0D0444 7F09B914 24C6A0E8 */  addiu $a2, %lo(dword_CODE_bss_8007A0E8) # addiu $a2, $a2, -0x5f18
/* 0D0448 7F09B918 ACC20000 */  sw    $v0, ($a2)
/* 0D044C 7F09B91C 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0D0)
/* 0D0450 7F09B920 8C84A0D0 */  lw    $a0, %lo(dword_CODE_bss_8007A0D0)($a0)
/* 0D0454 7F09B924 24050004 */  li    $a1, 4
/* 0D0458 7F09B928 00046100 */  sll   $t4, $a0, 4
/* 0D045C 7F09B92C 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0D0460 7F09B930 01802025 */   move  $a0, $t4
/* 0D0464 7F09B934 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
/* 0D0468 7F09B938 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007A0E0)
/* 0D046C 7F09B93C AC22A0E0 */  sw    $v0, %lo(dword_CODE_bss_8007A0E0)($at)
/* 0D0470 7F09B940 2529A0DC */  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
/* 0D0474 7F09B944 8D240000 */  lw    $a0, ($t1)
/* 0D0478 7F09B948 24050004 */  li    $a1, 4
/* 0D047C 7F09B94C 00046880 */  sll   $t5, $a0, 2
/* 0D0480 7F09B950 01A46821 */  addu  $t5, $t5, $a0
/* 0D0484 7F09B954 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0D0488 7F09B958 000D2080 */   sll   $a0, $t5, 2
/* 0D048C 7F09B95C 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
/* 0D0490 7F09B960 24E7A0EC */  addiu $a3, %lo(dword_CODE_bss_8007A0EC) # addiu $a3, $a3, -0x5f14
/* 0D0494 7F09B964 ACE20000 */  sw    $v0, ($a3)
/* 0D0498 7F09B968 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0D8)
/* 0D049C 7F09B96C 8C84A0D8 */  lw    $a0, %lo(dword_CODE_bss_8007A0D8)($a0)
/* 0D04A0 7F09B970 24050004 */  li    $a1, 4
/* 0D04A4 7F09B974 00047100 */  sll   $t6, $a0, 4
/* 0D04A8 7F09B978 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0D04AC 7F09B97C 01C02025 */   move  $a0, $t6
/* 0D04B0 7F09B980 3C0A8008 */  lui   $t2, %hi(dword_CODE_bss_8007A0D0) 
/* 0D04B4 7F09B984 254AA0D0 */  addiu $t2, %lo(dword_CODE_bss_8007A0D0) # addiu $t2, $t2, -0x5f30
/* 0D04B8 7F09B988 8D4F0000 */  lw    $t7, ($t2)
/* 0D04BC 7F09B98C 3C058008 */  lui   $a1, %hi(dword_CODE_bss_8007A0E4)
/* 0D04C0 7F09B990 24A5A0E4 */  addiu $a1, %lo(dword_CODE_bss_8007A0E4) # addiu $a1, $a1, -0x5f1c
/* 0D04C4 7F09B994 ACA20000 */  sw    $v0, ($a1)
/* 0D04C8 7F09B998 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A0E8)
/* 0D04CC 7F09B99C 3C018008 */  lui   $at, %hi(word_CODE_bss_8007A0F0)
/* 0D04D0 7F09B9A0 24C6A0E8 */  addiu $a2, %lo(dword_CODE_bss_8007A0E8) # addiu $a2, $a2, -0x5f18
/* 0D04D4 7F09B9A4 3C188008 */  lui   $t8, %hi(dword_CODE_bss_8007A0E0) 
/* 0D04D8 7F09B9A8 A42FA0F0 */  sh    $t7, %lo(word_CODE_bss_8007A0F0)($at)
/* 0D04DC 7F09B9AC 8CD90000 */  lw    $t9, ($a2)
/* 0D04E0 7F09B9B0 8F18A0E0 */  lw    $t8, %lo(dword_CODE_bss_8007A0E0)($t8)
/* 0D04E4 7F09B9B4 2404FFFF */  li    $a0, -1
/* 0D04E8 7F09B9B8 3C088008 */  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
/* 0D04EC 7F09B9BC AF380000 */  sw    $t8, ($t9)
/* 0D04F0 7F09B9C0 8CCC0000 */  lw    $t4, ($a2)
/* 0D04F4 7F09B9C4 8D4B0000 */  lw    $t3, ($t2)
/* 0D04F8 7F09B9C8 2508A0D4 */  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
/* 0D04FC 7F09B9CC 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
/* 0D0500 7F09B9D0 A58B000C */  sh    $t3, 0xc($t4)
/* 0D0504 7F09B9D4 8CCD0000 */  lw    $t5, ($a2)
/* 0D0508 7F09B9D8 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
/* 0D050C 7F09B9DC 2529A0DC */  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
/* 0D0510 7F09B9E0 A5A0000E */  sh    $zero, 0xe($t5)
/* 0D0514 7F09B9E4 8CCE0000 */  lw    $t6, ($a2)
/* 0D0518 7F09B9E8 24E7A0EC */  addiu $a3, %lo(dword_CODE_bss_8007A0EC) # addiu $a3, $a3, -0x5f14
/* 0D051C 7F09B9EC 24020014 */  li    $v0, 20
/* 0D0520 7F09B9F0 A5C40010 */  sh    $a0, 0x10($t6)
/* 0D0524 7F09B9F4 8CCF0000 */  lw    $t7, ($a2)
/* 0D0528 7F09B9F8 24030001 */  li    $v1, 1
/* 0D052C 7F09B9FC 3C0D8008 */  lui   $t5, %hi(dword_CODE_bss_8007A0D8) 
/* 0D0530 7F09BA00 A5E40012 */  sh    $a0, 0x12($t7)
/* 0D0534 7F09BA04 8D180000 */  lw    $t8, ($t0)
/* 0D0538 7F09BA08 2B010002 */  slti  $at, $t8, 2
/* 0D053C 7F09BA0C 1420000B */  bnez  $at, .L7F09BA3C
/* 0D0540 7F09BA10 00000000 */   nop   
/* 0D0544 7F09BA14 8CD90000 */  lw    $t9, ($a2)
.L7F09BA18:
/* 0D0548 7F09BA18 24630001 */  addiu $v1, $v1, 1
/* 0D054C 7F09BA1C 03225821 */  addu  $t3, $t9, $v0
/* 0D0550 7F09BA20 A564000E */  sh    $a0, 0xe($t3)
/* 0D0554 7F09BA24 8D0C0000 */  lw    $t4, ($t0)
/* 0D0558 7F09BA28 24420014 */  addiu $v0, $v0, 0x14
/* 0D055C 7F09BA2C 006C082A */  slt   $at, $v1, $t4
/* 0D0560 7F09BA30 5420FFF9 */  bnezl $at, .L7F09BA18
/* 0D0564 7F09BA34 8CD90000 */   lw    $t9, ($a2)
/* 0D0568 7F09BA38 24030001 */  li    $v1, 1
.L7F09BA3C:
/* 0D056C 7F09BA3C 8DADA0D8 */  lw    $t5, %lo(dword_CODE_bss_8007A0D8)($t5)
/* 0D0570 7F09BA40 3C018008 */  lui   $at, %hi(word_CODE_bss_8007A0F2)
/* 0D0574 7F09BA44 3C188008 */  lui   $t8, %hi(dword_CODE_bss_8007A0D8) 
/* 0D0578 7F09BA48 A42DA0F2 */  sh    $t5, %lo(word_CODE_bss_8007A0F2)($at)
/* 0D057C 7F09BA4C 8CEF0000 */  lw    $t7, ($a3)
/* 0D0580 7F09BA50 8CAE0000 */  lw    $t6, ($a1)
/* 0D0584 7F09BA54 24020014 */  li    $v0, 20
/* 0D0588 7F09BA58 ADEE0000 */  sw    $t6, ($t7)
/* 0D058C 7F09BA5C 8CF90000 */  lw    $t9, ($a3)
/* 0D0590 7F09BA60 8F18A0D8 */  lw    $t8, %lo(dword_CODE_bss_8007A0D8)($t8)
/* 0D0594 7F09BA64 A738000C */  sh    $t8, 0xc($t9)
/* 0D0598 7F09BA68 8CEB0000 */  lw    $t3, ($a3)
/* 0D059C 7F09BA6C A560000E */  sh    $zero, 0xe($t3)
/* 0D05A0 7F09BA70 8CEC0000 */  lw    $t4, ($a3)
/* 0D05A4 7F09BA74 A5840010 */  sh    $a0, 0x10($t4)
/* 0D05A8 7F09BA78 8CED0000 */  lw    $t5, ($a3)
/* 0D05AC 7F09BA7C A5A40012 */  sh    $a0, 0x12($t5)
/* 0D05B0 7F09BA80 8D2E0000 */  lw    $t6, ($t1)
/* 0D05B4 7F09BA84 29C10002 */  slti  $at, $t6, 2
/* 0D05B8 7F09BA88 5420000B */  bnezl $at, .L7F09BAB8
/* 0D05BC 7F09BA8C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0D05C0 7F09BA90 8CEF0000 */  lw    $t7, ($a3)
.L7F09BA94:
/* 0D05C4 7F09BA94 24630001 */  addiu $v1, $v1, 1
/* 0D05C8 7F09BA98 01E2C021 */  addu  $t8, $t7, $v0
/* 0D05CC 7F09BA9C A704000E */  sh    $a0, 0xe($t8)
/* 0D05D0 7F09BAA0 8D390000 */  lw    $t9, ($t1)
/* 0D05D4 7F09BAA4 24420014 */  addiu $v0, $v0, 0x14
/* 0D05D8 7F09BAA8 0079082A */  slt   $at, $v1, $t9
/* 0D05DC 7F09BAAC 5420FFF9 */  bnezl $at, .L7F09BA94
/* 0D05E0 7F09BAB0 8CEF0000 */   lw    $t7, ($a3)
/* 0D05E4 7F09BAB4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09BAB8:
/* 0D05E8 7F09BAB8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0D05EC 7F09BABC 03E00008 */  jr    $ra
/* 0D05F0 7F09BAC0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09BAC4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09BAC4
/* 0D05F4 7F09BAC4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0D05F8 7F09BAC8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D05FC 7F09BACC AFB40028 */  sw    $s4, 0x28($sp)
/* 0D0600 7F09BAD0 AFB30024 */  sw    $s3, 0x24($sp)
/* 0D0604 7F09BAD4 00809825 */  move  $s3, $a0
/* 0D0608 7F09BAD8 00A0A025 */  move  $s4, $a1
/* 0D060C 7F09BADC AFB20020 */  sw    $s2, 0x20($sp)
/* 0D0610 7F09BAE0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0D0614 7F09BAE4 0FC0E909 */  jal   get_ptr_obj_pos_list_current_entry
/* 0D0618 7F09BAE8 AFB00018 */   sw    $s0, 0x18($sp)
/* 0D061C 7F09BAEC 1040002B */  beqz  $v0, .L7F09BB9C
/* 0D0620 7F09BAF0 00408825 */   move  $s1, $v0
/* 0D0624 7F09BAF4 24120001 */  li    $s2, 1
/* 0D0628 7F09BAF8 24100018 */  li    $s0, 24
/* 0D062C 7F09BAFC 922E0000 */  lbu   $t6, ($s1)
.L7F09BB00:
/* 0D0630 7F09BB00 564E0024 */  bnel  $s2, $t6, .L7F09BB94
/* 0D0634 7F09BB04 8E310024 */   lw    $s1, 0x24($s1)
/* 0D0638 7F09BB08 8E220004 */  lw    $v0, 4($s1)
/* 0D063C 7F09BB0C 8C440014 */  lw    $a0, 0x14($v0)
/* 0D0640 7F09BB10 8C830008 */  lw    $v1, 8($a0)
/* 0D0644 7F09BB14 8C650000 */  lw    $a1, ($v1)
/* 0D0648 7F09BB18 50A0001E */  beql  $a1, $zero, .L7F09BB94
/* 0D064C 7F09BB1C 8E310024 */   lw    $s1, 0x24($s1)
/* 0D0650 7F09BB20 94A20000 */  lhu   $v0, ($a1)
.L7F09BB24:
/* 0D0654 7F09BB24 304F00FF */  andi  $t7, $v0, 0xff
/* 0D0658 7F09BB28 55F00009 */  bnel  $t7, $s0, .L7F09BB50
/* 0D065C 7F09BB2C 8CA20014 */   lw    $v0, 0x14($a1)
/* 0D0660 7F09BB30 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0D0664 7F09BB34 00000000 */   nop   
/* 0D0668 7F09BB38 8C580000 */  lw    $t8, ($v0)
/* 0D066C 7F09BB3C 56780015 */  bnel  $s3, $t8, .L7F09BB94
/* 0D0670 7F09BB40 8E310024 */   lw    $s1, 0x24($s1)
/* 0D0674 7F09BB44 10000012 */  b     .L7F09BB90
/* 0D0678 7F09BB48 AC540000 */   sw    $s4, ($v0)
/* 0D067C 7F09BB4C 8CA20014 */  lw    $v0, 0x14($a1)
.L7F09BB50:
/* 0D0680 7F09BB50 10400003 */  beqz  $v0, .L7F09BB60
/* 0D0684 7F09BB54 00000000 */   nop   
/* 0D0688 7F09BB58 1000000B */  b     .L7F09BB88
/* 0D068C 7F09BB5C 00402825 */   move  $a1, $v0
.L7F09BB60:
/* 0D0690 7F09BB60 10A00009 */  beqz  $a1, .L7F09BB88
/* 0D0694 7F09BB64 00000000 */   nop   
/* 0D0698 7F09BB68 8CA2000C */  lw    $v0, 0xc($a1)
.L7F09BB6C:
/* 0D069C 7F09BB6C 50400004 */  beql  $v0, $zero, .L7F09BB80
/* 0D06A0 7F09BB70 8CA50008 */   lw    $a1, 8($a1)
/* 0D06A4 7F09BB74 10000004 */  b     .L7F09BB88
/* 0D06A8 7F09BB78 00402825 */   move  $a1, $v0
/* 0D06AC 7F09BB7C 8CA50008 */  lw    $a1, 8($a1)
.L7F09BB80:
/* 0D06B0 7F09BB80 54A0FFFA */  bnezl $a1, .L7F09BB6C
/* 0D06B4 7F09BB84 8CA2000C */   lw    $v0, 0xc($a1)
.L7F09BB88:
/* 0D06B8 7F09BB88 54A0FFE6 */  bnezl $a1, .L7F09BB24
/* 0D06BC 7F09BB8C 94A20000 */   lhu   $v0, ($a1)
.L7F09BB90:
/* 0D06C0 7F09BB90 8E310024 */  lw    $s1, 0x24($s1)
.L7F09BB94:
/* 0D06C4 7F09BB94 5620FFDA */  bnezl $s1, .L7F09BB00
/* 0D06C8 7F09BB98 922E0000 */   lbu   $t6, ($s1)
.L7F09BB9C:
/* 0D06CC 7F09BB9C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0D06D0 7F09BBA0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D06D4 7F09BBA4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0D06D8 7F09BBA8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0D06DC 7F09BBAC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0D06E0 7F09BBB0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0D06E4 7F09BBB4 03E00008 */  jr    $ra
/* 0D06E8 7F09BBB8 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09BBBC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09BBBC
/* 0D06EC 7F09BBBC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0D06F0 7F09BBC0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0D06F4 7F09BBC4 3C158008 */  lui   $s5, %hi(word_CODE_bss_8007A0F2)
/* 0D06F8 7F09BBC8 3C0F8008 */  lui   $t7, %hi(dword_CODE_bss_8007A0D8) 
/* 0D06FC 7F09BBCC 8DEFA0D8 */  lw    $t7, %lo(dword_CODE_bss_8007A0D8)($t7)
/* 0D0700 7F09BBD0 26B5A0F2 */  addiu $s5, %lo(word_CODE_bss_8007A0F2) # addiu $s5, $s5, -0x5f0e
/* 0D0704 7F09BBD4 86AE0000 */  lh    $t6, ($s5)
/* 0D0708 7F09BBD8 000FC083 */  sra   $t8, $t7, 2
/* 0D070C 7F09BBDC AFB60030 */  sw    $s6, 0x30($sp)
/* 0D0710 7F09BBE0 01D8082A */  slt   $at, $t6, $t8
/* 0D0714 7F09BBE4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D0718 7F09BBE8 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0D071C 7F09BBEC AFB70034 */  sw    $s7, 0x34($sp)
/* 0D0720 7F09BBF0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0D0724 7F09BBF4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0D0728 7F09BBF8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0D072C 7F09BBFC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0D0730 7F09BC00 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D0734 7F09BC04 1020004B */  beqz  $at, .L7F09BD34
/* 0D0738 7F09BC08 0000B025 */   move  $s6, $zero
/* 0D073C 7F09BC0C 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0DC)
/* 0D0740 7F09BC10 8C84A0DC */  lw    $a0, %lo(dword_CODE_bss_8007A0DC)($a0)
/* 0D0744 7F09BC14 0000F025 */  move  $fp, $zero
/* 0D0748 7F09BC18 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0EC)
/* 0D074C 7F09BC1C 2485FFFF */  addiu $a1, $a0, -1
/* 0D0750 7F09BC20 18A00044 */  blez  $a1, .L7F09BD34
/* 0D0754 7F09BC24 24170014 */   li    $s7, 20
/* 0D0758 7F09BC28 3C148008 */  lui   $s4, %hi(dword_CODE_bss_8007A0EC)
/* 0D075C 7F09BC2C 2694A0EC */  addiu $s4, %lo(dword_CODE_bss_8007A0EC) # addiu $s4, $s4, -0x5f14
/* 0D0760 7F09BC30 8C63A0EC */  lw    $v1, %lo(dword_CODE_bss_8007A0EC)($v1)
.L7F09BC34:
/* 0D0764 7F09BC34 03D70019 */  multu $fp, $s7
/* 0D0768 7F09BC38 27C20001 */  addiu $v0, $fp, 1
/* 0D076C 7F09BC3C 00025400 */  sll   $t2, $v0, 0x10
/* 0D0770 7F09BC40 000A5C03 */  sra   $t3, $t2, 0x10
/* 0D0774 7F09BC44 00029400 */  sll   $s2, $v0, 0x10
/* 0D0778 7F09BC48 00124C03 */  sra   $t1, $s2, 0x10
/* 0D077C 7F09BC4C 0164082A */  slt   $at, $t3, $a0
/* 0D0780 7F09BC50 00009812 */  mflo  $s3
/* 0D0784 7F09BC54 0073C821 */  addu  $t9, $v1, $s3
/* 0D0788 7F09BC58 8728000E */  lh    $t0, 0xe($t9)
/* 0D078C 7F09BC5C 59000030 */  blezl $t0, .L7F09BD20
/* 0D0790 7F09BC60 27DE0001 */   addiu $fp, $fp, 1
/* 0D0794 7F09BC64 1020002D */  beqz  $at, .L7F09BD1C
/* 0D0798 7F09BC68 01209025 */   move  $s2, $t1
.L7F09BC6C:
/* 0D079C 7F09BC6C 02570019 */  multu $s2, $s7
/* 0D07A0 7F09BC70 00738021 */  addu  $s0, $v1, $s3
/* 0D07A4 7F09BC74 00008812 */  mflo  $s1
/* 0D07A8 7F09BC78 00711021 */  addu  $v0, $v1, $s1
/* 0D07AC 7F09BC7C 844C000E */  lh    $t4, 0xe($v0)
/* 0D07B0 7F09BC80 59800020 */  blezl $t4, .L7F09BD04
/* 0D07B4 7F09BC84 26520001 */   addiu $s2, $s2, 1
/* 0D07B8 7F09BC88 8E0D0004 */  lw    $t5, 4($s0)
/* 0D07BC 7F09BC8C 8C4F0004 */  lw    $t7, 4($v0)
/* 0D07C0 7F09BC90 55AF001C */  bnel  $t5, $t7, .L7F09BD04
/* 0D07C4 7F09BC94 26520001 */   addiu $s2, $s2, 1
/* 0D07C8 7F09BC98 8E0E0008 */  lw    $t6, 8($s0)
/* 0D07CC 7F09BC9C 8C580008 */  lw    $t8, 8($v0)
/* 0D07D0 7F09BCA0 55D80018 */  bnel  $t6, $t8, .L7F09BD04
/* 0D07D4 7F09BCA4 26520001 */   addiu $s2, $s2, 1
/* 0D07D8 7F09BCA8 8C440000 */  lw    $a0, ($v0)
/* 0D07DC 7F09BCAC 8E050000 */  lw    $a1, ($s0)
/* 0D07E0 7F09BCB0 0FC26EB1 */  jal   sub_GAME_7F09BAC4
/* 0D07E4 7F09BCB4 24160001 */   li    $s6, 1
/* 0D07E8 7F09BCB8 8E830000 */  lw    $v1, ($s4)
/* 0D07EC 7F09BCBC 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A0DC)
/* 0D07F0 7F09BCC0 00738021 */  addu  $s0, $v1, $s3
/* 0D07F4 7F09BCC4 00714021 */  addu  $t0, $v1, $s1
/* 0D07F8 7F09BCC8 8509000E */  lh    $t1, 0xe($t0)
/* 0D07FC 7F09BCCC 8619000E */  lh    $t9, 0xe($s0)
/* 0D0800 7F09BCD0 03295021 */  addu  $t2, $t9, $t1
/* 0D0804 7F09BCD4 A60A000E */  sh    $t2, 0xe($s0)
/* 0D0808 7F09BCD8 8E8B0000 */  lw    $t3, ($s4)
/* 0D080C 7F09BCDC 01716021 */  addu  $t4, $t3, $s1
/* 0D0810 7F09BCE0 A580000E */  sh    $zero, 0xe($t4)
/* 0D0814 7F09BCE4 8E830000 */  lw    $v1, ($s4)
/* 0D0818 7F09BCE8 86AD0000 */  lh    $t5, ($s5)
/* 0D081C 7F09BCEC 00717821 */  addu  $t7, $v1, $s1
/* 0D0820 7F09BCF0 85EE000C */  lh    $t6, 0xc($t7)
/* 0D0824 7F09BCF4 01AEC021 */  addu  $t8, $t5, $t6
/* 0D0828 7F09BCF8 A6B80000 */  sh    $t8, ($s5)
/* 0D082C 7F09BCFC 8C84A0DC */  lw    $a0, %lo(dword_CODE_bss_8007A0DC)($a0)
/* 0D0830 7F09BD00 26520001 */  addiu $s2, $s2, 1
.L7F09BD04:
/* 0D0834 7F09BD04 00124400 */  sll   $t0, $s2, 0x10
/* 0D0838 7F09BD08 00089403 */  sra   $s2, $t0, 0x10
/* 0D083C 7F09BD0C 0244082A */  slt   $at, $s2, $a0
/* 0D0840 7F09BD10 1420FFD6 */  bnez  $at, .L7F09BC6C
/* 0D0844 7F09BD14 00000000 */   nop   
/* 0D0848 7F09BD18 2485FFFF */  addiu $a1, $a0, -1
.L7F09BD1C:
/* 0D084C 7F09BD1C 27DE0001 */  addiu $fp, $fp, 1
.L7F09BD20:
/* 0D0850 7F09BD20 001E4C00 */  sll   $t1, $fp, 0x10
/* 0D0854 7F09BD24 0009F403 */  sra   $fp, $t1, 0x10
/* 0D0858 7F09BD28 03C5082A */  slt   $at, $fp, $a1
/* 0D085C 7F09BD2C 1420FFC1 */  bnez  $at, .L7F09BC34
/* 0D0860 7F09BD30 00000000 */   nop   
.L7F09BD34:
/* 0D0864 7F09BD34 3C148008 */  lui   $s4, %hi(dword_CODE_bss_8007A0EC)
/* 0D0868 7F09BD38 2694A0EC */  addiu $s4, %lo(dword_CODE_bss_8007A0EC) # addiu $s4, $s4, -0x5f14
/* 0D086C 7F09BD3C 12C0002E */  beqz  $s6, .L7F09BDF8
/* 0D0870 7F09BD40 24170014 */   li    $s7, 20
/* 0D0874 7F09BD44 00002025 */  move  $a0, $zero
/* 0D0878 7F09BD48 0000F025 */  move  $fp, $zero
/* 0D087C 7F09BD4C 2405FFFF */  li    $a1, -1
.L7F09BD50:
/* 0D0880 7F09BD50 03D70019 */  multu $fp, $s7
/* 0D0884 7F09BD54 8E830000 */  lw    $v1, ($s4)
/* 0D0888 7F09BD58 00009812 */  mflo  $s3
/* 0D088C 7F09BD5C 00738021 */  addu  $s0, $v1, $s3
/* 0D0890 7F09BD60 86120010 */  lh    $s2, 0x10($s0)
/* 0D0894 7F09BD64 06420022 */  bltzl $s2, .L7F09BDF0
/* 0D0898 7F09BD68 24040001 */   li    $a0, 1
/* 0D089C 7F09BD6C 860B000E */  lh    $t3, 0xe($s0)
/* 0D08A0 7F09BD70 5560001B */  bnezl $t3, .L7F09BDE0
/* 0D08A4 7F09BD74 0012F400 */   sll   $fp, $s2, 0x10
/* 0D08A8 7F09BD78 02570019 */  multu $s2, $s7
/* 0D08AC 7F09BD7C 00008812 */  mflo  $s1
/* 0D08B0 7F09BD80 00711021 */  addu  $v0, $v1, $s1
/* 0D08B4 7F09BD84 844C000E */  lh    $t4, 0xe($v0)
/* 0D08B8 7F09BD88 55800015 */  bnezl $t4, .L7F09BDE0
/* 0D08BC 7F09BD8C 0012F400 */   sll   $fp, $s2, 0x10
/* 0D08C0 7F09BD90 860F000C */  lh    $t7, 0xc($s0)
/* 0D08C4 7F09BD94 844D000C */  lh    $t5, 0xc($v0)
/* 0D08C8 7F09BD98 01ED7021 */  addu  $t6, $t7, $t5
/* 0D08CC 7F09BD9C A60E000C */  sh    $t6, 0xc($s0)
/* 0D08D0 7F09BDA0 8E980000 */  lw    $t8, ($s4)
/* 0D08D4 7F09BDA4 03114021 */  addu  $t0, $t8, $s1
/* 0D08D8 7F09BDA8 A505000E */  sh    $a1, 0xe($t0)
/* 0D08DC 7F09BDAC 8E830000 */  lw    $v1, ($s4)
/* 0D08E0 7F09BDB0 0071C821 */  addu  $t9, $v1, $s1
/* 0D08E4 7F09BDB4 87320010 */  lh    $s2, 0x10($t9)
/* 0D08E8 7F09BDB8 00734821 */  addu  $t1, $v1, $s3
/* 0D08EC 7F09BDBC 0640000C */  bltz  $s2, .L7F09BDF0
/* 0D08F0 7F09BDC0 A5320010 */   sh    $s2, 0x10($t1)
/* 0D08F4 7F09BDC4 02570019 */  multu $s2, $s7
/* 0D08F8 7F09BDC8 8E8A0000 */  lw    $t2, ($s4)
/* 0D08FC 7F09BDCC 00005812 */  mflo  $t3
/* 0D0900 7F09BDD0 014B6021 */  addu  $t4, $t2, $t3
/* 0D0904 7F09BDD4 10000006 */  b     .L7F09BDF0
/* 0D0908 7F09BDD8 A59E0012 */   sh    $fp, 0x12($t4)
/* 0D090C 7F09BDDC 0012F400 */  sll   $fp, $s2, 0x10
.L7F09BDE0:
/* 0D0910 7F09BDE0 001E7C03 */  sra   $t7, $fp, 0x10
/* 0D0914 7F09BDE4 10000002 */  b     .L7F09BDF0
/* 0D0918 7F09BDE8 01E0F025 */   move  $fp, $t7
/* 0D091C 7F09BDEC 24040001 */  li    $a0, 1
.L7F09BDF0:
/* 0D0920 7F09BDF0 1080FFD7 */  beqz  $a0, .L7F09BD50
/* 0D0924 7F09BDF4 00000000 */   nop   
.L7F09BDF8:
/* 0D0928 7F09BDF8 3C0E8008 */  lui   $t6, %hi(dword_CODE_bss_8007A0D8) 
/* 0D092C 7F09BDFC 8DCEA0D8 */  lw    $t6, %lo(dword_CODE_bss_8007A0D8)($t6)
/* 0D0930 7F09BE00 86AD0000 */  lh    $t5, ($s5)
/* 0D0934 7F09BE04 000EC083 */  sra   $t8, $t6, 2
/* 0D0938 7F09BE08 01B8082A */  slt   $at, $t5, $t8
/* 0D093C 7F09BE0C 50200004 */  beql  $at, $zero, .L7F09BE20
/* 0D0940 7F09BE10 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0D0944 7F09BE14 0FC159A4 */  jal   sub_GAME_7F056690
/* 0D0948 7F09BE18 00000000 */   nop   
/* 0D094C 7F09BE1C 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F09BE20:
/* 0D0950 7F09BE20 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D0954 7F09BE24 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0D0958 7F09BE28 8FB20020 */  lw    $s2, 0x20($sp)
/* 0D095C 7F09BE2C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0D0960 7F09BE30 8FB40028 */  lw    $s4, 0x28($sp)
/* 0D0964 7F09BE34 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0D0968 7F09BE38 8FB60030 */  lw    $s6, 0x30($sp)
/* 0D096C 7F09BE3C 8FB70034 */  lw    $s7, 0x34($sp)
/* 0D0970 7F09BE40 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0D0974 7F09BE44 03E00008 */  jr    $ra
/* 0D0978 7F09BE48 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09BE4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09BE4C
/* 0D097C 7F09BE4C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0D0980 7F09BE50 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D0984 7F09BE54 24010B0B */  li    $at, 2827
/* 0D0988 7F09BE58 00808025 */  move  $s0, $a0
/* 0D098C 7F09BE5C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0D0990 7F09BE60 AFA60028 */  sw    $a2, 0x28($sp)
/* 0D0994 7F09BE64 10A1000A */  beq   $a1, $at, .L7F09BE90
/* 0D0998 7F09BE68 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0D099C 7F09BE6C 3401CCCC */  li    $at, 52428
/* 0D09A0 7F09BE70 14A1000E */  bne   $a1, $at, .L7F09BEAC
/* 0D09A4 7F09BE74 3C088008 */   lui   $t0, %hi(dword_CODE_bss_8007A0E8) 
/* 0D09A8 7F09BE78 3C0B8008 */  lui   $t3, %hi(word_CODE_bss_8007A0F0) 
/* 0D09AC 7F09BE7C 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A0D4+2)
/* 0D09B0 7F09BE80 8D08A0E8 */  lw    $t0, %lo(dword_CODE_bss_8007A0E8)($t0)
/* 0D09B4 7F09BE84 256BA0F0 */  addiu $t3, %lo(word_CODE_bss_8007A0F0) # addiu $t3, $t3, -0x5f10
/* 0D09B8 7F09BE88 1000000A */  b     .L7F09BEB4
/* 0D09BC 7F09BE8C 84C6A0D6 */   lh    $a2, %lo(dword_CODE_bss_8007A0D4+2)($a2)
.L7F09BE90:
/* 0D09C0 7F09BE90 3C088008 */  lui   $t0, %hi(dword_CODE_bss_8007A0EC) 
/* 0D09C4 7F09BE94 3C0B8008 */  lui   $t3, %hi(word_CODE_bss_8007A0F2) 
/* 0D09C8 7F09BE98 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007A0DC+0x2)
/* 0D09CC 7F09BE9C 8D08A0EC */  lw    $t0, %lo(dword_CODE_bss_8007A0EC)($t0)
/* 0D09D0 7F09BEA0 256BA0F2 */  addiu $t3, %lo(word_CODE_bss_8007A0F2) # addiu $t3, $t3, -0x5f0e
/* 0D09D4 7F09BEA4 10000003 */  b     .L7F09BEB4
/* 0D09D8 7F09BEA8 84C6A0DE */   lh    $a2, %lo(dword_CODE_bss_8007A0DC+0x2)($a2)
.L7F09BEAC:
/* 0D09DC 7F09BEAC 10000060 */  b     .L7F09C030
/* 0D09E0 7F09BEB0 00001025 */   move  $v0, $zero
.L7F09BEB4:
/* 0D09E4 7F09BEB4 00001825 */  move  $v1, $zero
/* 0D09E8 7F09BEB8 00001025 */  move  $v0, $zero
/* 0D09EC 7F09BEBC 00002825 */  move  $a1, $zero
/* 0D09F0 7F09BEC0 24090014 */  li    $t1, 20
/* 0D09F4 7F09BEC4 2407FFFF */  li    $a3, -1
.L7F09BEC8:
/* 0D09F8 7F09BEC8 00A90019 */  multu $a1, $t1
/* 0D09FC 7F09BECC 00007012 */  mflo  $t6
/* 0D0A00 7F09BED0 010E2021 */  addu  $a0, $t0, $t6
/* 0D0A04 7F09BED4 848F000E */  lh    $t7, 0xe($a0)
/* 0D0A08 7F09BED8 55E00008 */  bnezl $t7, .L7F09BEFC
/* 0D0A0C 7F09BEDC 84850010 */   lh    $a1, 0x10($a0)
/* 0D0A10 7F09BEE0 8498000C */  lh    $t8, 0xc($a0)
/* 0D0A14 7F09BEE4 0310082A */  slt   $at, $t8, $s0
/* 0D0A18 7F09BEE8 54200004 */  bnezl $at, .L7F09BEFC
/* 0D0A1C 7F09BEEC 84850010 */   lh    $a1, 0x10($a0)
/* 0D0A20 7F09BEF0 1000000B */  b     .L7F09BF20
/* 0D0A24 7F09BEF4 24030001 */   li    $v1, 1
/* 0D0A28 7F09BEF8 84850010 */  lh    $a1, 0x10($a0)
.L7F09BEFC:
/* 0D0A2C 7F09BEFC 24420001 */  addiu $v0, $v0, 1
/* 0D0A30 7F09BF00 00C2082A */  slt   $at, $a2, $v0
/* 0D0A34 7F09BF04 50A70004 */  beql  $a1, $a3, .L7F09BF18
/* 0D0A38 7F09BF08 00071C00 */   sll   $v1, $a3, 0x10
/* 0D0A3C 7F09BF0C 10200004 */  beqz  $at, .L7F09BF20
/* 0D0A40 7F09BF10 00000000 */   nop   
/* 0D0A44 7F09BF14 00071C00 */  sll   $v1, $a3, 0x10
.L7F09BF18:
/* 0D0A48 7F09BF18 0003CC03 */  sra   $t9, $v1, 0x10
/* 0D0A4C 7F09BF1C 03201825 */  move  $v1, $t9
.L7F09BF20:
/* 0D0A50 7F09BF20 1060FFE9 */  beqz  $v1, .L7F09BEC8
/* 0D0A54 7F09BF24 00000000 */   nop   
/* 0D0A58 7F09BF28 00C2082A */  slt   $at, $a2, $v0
/* 0D0A5C 7F09BF2C 50200008 */  beql  $at, $zero, .L7F09BF50
/* 0D0A60 7F09BF30 24010001 */   li    $at, 1
/* 0D0A64 7F09BF34 0FC26DEA */  jal   sub_GAME_7F09B7A8
/* 0D0A68 7F09BF38 00000000 */   nop   
/* 0D0A6C 7F09BF3C 0FC26DF9 */  jal   sub_GAME_7F09B7E4
/* 0D0A70 7F09BF40 00000000 */   nop   
/* 0D0A74 7F09BF44 1000003A */  b     .L7F09C030
/* 0D0A78 7F09BF48 00001025 */   move  $v0, $zero
/* 0D0A7C 7F09BF4C 24010001 */  li    $at, 1
.L7F09BF50:
/* 0D0A80 7F09BF50 14610037 */  bne   $v1, $at, .L7F09C030
/* 0D0A84 7F09BF54 00001025 */   move  $v0, $zero
/* 0D0A88 7F09BF58 00A90019 */  multu $a1, $t1
/* 0D0A8C 7F09BF5C 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0D0A90 7F09BF60 00006025 */  move  $t4, $zero
/* 0D0A94 7F09BF64 00006812 */  mflo  $t5
/* 0D0A98 7F09BF68 010D2021 */  addu  $a0, $t0, $t5
/* 0D0A9C 7F09BF6C 8498000E */  lh    $t8, 0xe($a0)
/* 0D0AA0 7F09BF70 848A000C */  lh    $t2, 0xc($a0)
/* 0D0AA4 7F09BF74 AC8E0004 */  sw    $t6, 4($a0)
/* 0D0AA8 7F09BF78 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0D0AAC 7F09BF7C 27190001 */  addiu $t9, $t8, 1
/* 0D0AB0 7F09BF80 A499000E */  sh    $t9, 0xe($a0)
/* 0D0AB4 7F09BF84 1150001F */  beq   $t2, $s0, .L7F09C004
/* 0D0AB8 7F09BF88 AC8F0008 */   sw    $t7, 8($a0)
/* 0D0ABC 7F09BF8C 18C0001D */  blez  $a2, .L7F09C004
/* 0D0AC0 7F09BF90 00001825 */   move  $v1, $zero
/* 0D0AC4 7F09BF94 01001025 */  move  $v0, $t0
.L7F09BF98:
/* 0D0AC8 7F09BF98 844D000E */  lh    $t5, 0xe($v0)
/* 0D0ACC 7F09BF9C 54ED0017 */  bnel  $a3, $t5, .L7F09BFFC
/* 0D0AD0 7F09BFA0 24630001 */   addiu $v1, $v1, 1
/* 0D0AD4 7F09BFA4 8C8E0000 */  lw    $t6, ($a0)
/* 0D0AD8 7F09BFA8 A490000C */  sh    $s0, 0xc($a0)
/* 0D0ADC 7F09BFAC 00107900 */  sll   $t7, $s0, 4
/* 0D0AE0 7F09BFB0 0150C823 */  subu  $t9, $t2, $s0
/* 0D0AE4 7F09BFB4 01CFC021 */  addu  $t8, $t6, $t7
/* 0D0AE8 7F09BFB8 AC580000 */  sw    $t8, ($v0)
/* 0D0AEC 7F09BFBC A459000C */  sh    $t9, 0xc($v0)
/* 0D0AF0 7F09BFC0 A440000E */  sh    $zero, 0xe($v0)
/* 0D0AF4 7F09BFC4 A4450012 */  sh    $a1, 0x12($v0)
/* 0D0AF8 7F09BFC8 848D0010 */  lh    $t5, 0x10($a0)
/* 0D0AFC 7F09BFCC 240C0001 */  li    $t4, 1
/* 0D0B00 7F09BFD0 A44D0010 */  sh    $t5, 0x10($v0)
/* 0D0B04 7F09BFD4 84820010 */  lh    $v0, 0x10($a0)
/* 0D0B08 7F09BFD8 04400005 */  bltz  $v0, .L7F09BFF0
/* 0D0B0C 7F09BFDC 00000000 */   nop   
/* 0D0B10 7F09BFE0 00490019 */  multu $v0, $t1
/* 0D0B14 7F09BFE4 00007012 */  mflo  $t6
/* 0D0B18 7F09BFE8 010E7821 */  addu  $t7, $t0, $t6
/* 0D0B1C 7F09BFEC A5E30012 */  sh    $v1, 0x12($t7)
.L7F09BFF0:
/* 0D0B20 7F09BFF0 10000004 */  b     .L7F09C004
/* 0D0B24 7F09BFF4 A4830010 */   sh    $v1, 0x10($a0)
/* 0D0B28 7F09BFF8 24630001 */  addiu $v1, $v1, 1
.L7F09BFFC:
/* 0D0B2C 7F09BFFC 1466FFE6 */  bne   $v1, $a2, .L7F09BF98
/* 0D0B30 7F09C000 24420014 */   addiu $v0, $v0, 0x14
.L7F09C004:
/* 0D0B34 7F09C004 51800006 */  beql  $t4, $zero, .L7F09C020
/* 0D0B38 7F09C008 856D0000 */   lh    $t5, ($t3)
/* 0D0B3C 7F09C00C 85780000 */  lh    $t8, ($t3)
/* 0D0B40 7F09C010 0310C823 */  subu  $t9, $t8, $s0
/* 0D0B44 7F09C014 10000004 */  b     .L7F09C028
/* 0D0B48 7F09C018 A5790000 */   sh    $t9, ($t3)
/* 0D0B4C 7F09C01C 856D0000 */  lh    $t5, ($t3)
.L7F09C020:
/* 0D0B50 7F09C020 01AA7023 */  subu  $t6, $t5, $t2
/* 0D0B54 7F09C024 A56E0000 */  sh    $t6, ($t3)
.L7F09C028:
/* 0D0B58 7F09C028 10000001 */  b     .L7F09C030
/* 0D0B5C 7F09C02C 8C820000 */   lw    $v0, ($a0)
.L7F09C030:
/* 0D0B60 7F09C030 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0D0B64 7F09C034 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D0B68 7F09C038 27BD0020 */  addiu $sp, $sp, 0x20
/* 0D0B6C 7F09C03C 03E00008 */  jr    $ra
/* 0D0B70 7F09C040 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09C044(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09C044
/* 0D0B74 7F09C044 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007A0E0)
/* 0D0B78 7F09C048 8C42A0E0 */  lw    $v0, %lo(dword_CODE_bss_8007A0E0)($v0)
/* 0D0B7C 7F09C04C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0D0B80 7F09C050 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D0B84 7F09C054 0082082B */  sltu  $at, $a0, $v0
/* 0D0B88 7F09C058 00808025 */  move  $s0, $a0
/* 0D0B8C 7F09C05C 1420000D */  bnez  $at, .L7F09C094
/* 0D0B90 7F09C060 AFBF001C */   sw    $ra, 0x1c($sp)
/* 0D0B94 7F09C064 3C0E8008 */  lui   $t6, %hi(dword_CODE_bss_8007A0D0) 
/* 0D0B98 7F09C068 8DCEA0D0 */  lw    $t6, %lo(dword_CODE_bss_8007A0D0)($t6)
/* 0D0B9C 7F09C06C 3C0A8008 */  lui   $t2, %hi(word_CODE_bss_8007A0F0) 
/* 0D0BA0 7F09C070 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007A0E8)
/* 0D0BA4 7F09C074 25CFFFFF */  addiu $t7, $t6, -1
/* 0D0BA8 7F09C078 000FC100 */  sll   $t8, $t7, 4
/* 0D0BAC 7F09C07C 0302C821 */  addu  $t9, $t8, $v0
/* 0D0BB0 7F09C080 0324082B */  sltu  $at, $t9, $a0
/* 0D0BB4 7F09C084 14200003 */  bnez  $at, .L7F09C094
/* 0D0BB8 7F09C088 254AA0F0 */   addiu $t2, %lo(word_CODE_bss_8007A0F0) # addiu $t2, $t2, -0x5f10
/* 0D0BBC 7F09C08C 10000018 */  b     .L7F09C0F0
/* 0D0BC0 7F09C090 8CE7A0E8 */   lw    $a3, %lo(dword_CODE_bss_8007A0E8)($a3)
.L7F09C094:
/* 0D0BC4 7F09C094 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007A0E4)
/* 0D0BC8 7F09C098 8C42A0E4 */  lw    $v0, %lo(dword_CODE_bss_8007A0E4)($v0)
/* 0D0BCC 7F09C09C 3C0B8008 */  lui   $t3, %hi(dword_CODE_bss_8007A0D8) 
/* 0D0BD0 7F09C0A0 0202082B */  sltu  $at, $s0, $v0
/* 0D0BD4 7F09C0A4 1420000C */  bnez  $at, .L7F09C0D8
/* 0D0BD8 7F09C0A8 00000000 */   nop   
/* 0D0BDC 7F09C0AC 8D6BA0D8 */  lw    $t3, %lo(dword_CODE_bss_8007A0D8)($t3)
/* 0D0BE0 7F09C0B0 3C0A8008 */  lui   $t2, %hi(word_CODE_bss_8007A0F2) 
/* 0D0BE4 7F09C0B4 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
/* 0D0BE8 7F09C0B8 256CFFFF */  addiu $t4, $t3, -1
/* 0D0BEC 7F09C0BC 000C6900 */  sll   $t5, $t4, 4
/* 0D0BF0 7F09C0C0 01A27021 */  addu  $t6, $t5, $v0
/* 0D0BF4 7F09C0C4 01D0082B */  sltu  $at, $t6, $s0
/* 0D0BF8 7F09C0C8 14200003 */  bnez  $at, .L7F09C0D8
/* 0D0BFC 7F09C0CC 254AA0F2 */   addiu $t2, %lo(word_CODE_bss_8007A0F2) # addiu $t2, $t2, -0x5f0e
/* 0D0C00 7F09C0D0 10000007 */  b     .L7F09C0F0
/* 0D0C04 7F09C0D4 8CE7A0EC */   lw    $a3, %lo(dword_CODE_bss_8007A0EC)($a3)
.L7F09C0D8:
/* 0D0C08 7F09C0D8 0FC26DEA */  jal   sub_GAME_7F09B7A8
/* 0D0C0C 7F09C0DC 00000000 */   nop   
/* 0D0C10 7F09C0E0 0FC26DF9 */  jal   sub_GAME_7F09B7E4
/* 0D0C14 7F09C0E4 00000000 */   nop   
/* 0D0C18 7F09C0E8 10000053 */  b     .L7F09C238
/* 0D0C1C 7F09C0EC 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F09C0F0:
/* 0D0C20 7F09C0F0 00002825 */  move  $a1, $zero
/* 0D0C24 7F09C0F4 00004025 */  move  $t0, $zero
/* 0D0C28 7F09C0F8 2409FFFF */  li    $t1, -1
/* 0D0C2C 7F09C0FC 24060014 */  li    $a2, 20
.L7F09C100:
/* 0D0C30 7F09C100 00A60019 */  multu $a1, $a2
/* 0D0C34 7F09C104 00007812 */  mflo  $t7
/* 0D0C38 7F09C108 00EF2021 */  addu  $a0, $a3, $t7
/* 0D0C3C 7F09C10C 8C980000 */  lw    $t8, ($a0)
/* 0D0C40 7F09C110 56180043 */  bnel  $s0, $t8, .L7F09C220
/* 0D0C44 7F09C114 84850010 */   lh    $a1, 0x10($a0)
/* 0D0C48 7F09C118 8482000E */  lh    $v0, 0xe($a0)
/* 0D0C4C 7F09C11C 24080001 */  li    $t0, 1
/* 0D0C50 7F09C120 2459FFFF */  addiu $t9, $v0, -1
/* 0D0C54 7F09C124 A499000E */  sh    $t9, 0xe($a0)
/* 0D0C58 7F09C128 848B000E */  lh    $t3, 0xe($a0)
/* 0D0C5C 7F09C12C 1560003F */  bnez  $t3, .L7F09C22C
/* 0D0C60 7F09C130 00000000 */   nop   
/* 0D0C64 7F09C134 854C0000 */  lh    $t4, ($t2)
/* 0D0C68 7F09C138 848D000C */  lh    $t5, 0xc($a0)
/* 0D0C6C 7F09C13C 018D7021 */  addu  $t6, $t4, $t5
/* 0D0C70 7F09C140 A54E0000 */  sh    $t6, ($t2)
/* 0D0C74 7F09C144 84830010 */  lh    $v1, 0x10($a0)
/* 0D0C78 7F09C148 04620016 */  bltzl $v1, .L7F09C1A4
/* 0D0C7C 7F09C14C 84830012 */   lh    $v1, 0x12($a0)
/* 0D0C80 7F09C150 00660019 */  multu $v1, $a2
/* 0D0C84 7F09C154 00007812 */  mflo  $t7
/* 0D0C88 7F09C158 00EF1021 */  addu  $v0, $a3, $t7
/* 0D0C8C 7F09C15C 8458000E */  lh    $t8, 0xe($v0)
/* 0D0C90 7F09C160 57000010 */  bnezl $t8, .L7F09C1A4
/* 0D0C94 7F09C164 84830012 */   lh    $v1, 0x12($a0)
/* 0D0C98 7F09C168 8499000C */  lh    $t9, 0xc($a0)
/* 0D0C9C 7F09C16C 844B000C */  lh    $t3, 0xc($v0)
/* 0D0CA0 7F09C170 032B6021 */  addu  $t4, $t9, $t3
/* 0D0CA4 7F09C174 A48C000C */  sh    $t4, 0xc($a0)
/* 0D0CA8 7F09C178 844D0010 */  lh    $t5, 0x10($v0)
/* 0D0CAC 7F09C17C A48D0010 */  sh    $t5, 0x10($a0)
/* 0D0CB0 7F09C180 A449000E */  sh    $t1, 0xe($v0)
/* 0D0CB4 7F09C184 84830010 */  lh    $v1, 0x10($a0)
/* 0D0CB8 7F09C188 04620006 */  bltzl $v1, .L7F09C1A4
/* 0D0CBC 7F09C18C 84830012 */   lh    $v1, 0x12($a0)
/* 0D0CC0 7F09C190 00660019 */  multu $v1, $a2
/* 0D0CC4 7F09C194 00007012 */  mflo  $t6
/* 0D0CC8 7F09C198 00EE7821 */  addu  $t7, $a3, $t6
/* 0D0CCC 7F09C19C A5E50012 */  sh    $a1, 0x12($t7)
/* 0D0CD0 7F09C1A0 84830012 */  lh    $v1, 0x12($a0)
.L7F09C1A4:
/* 0D0CD4 7F09C1A4 04600021 */  bltz  $v1, .L7F09C22C
/* 0D0CD8 7F09C1A8 00000000 */   nop   
/* 0D0CDC 7F09C1AC 00660019 */  multu $v1, $a2
/* 0D0CE0 7F09C1B0 0000C012 */  mflo  $t8
/* 0D0CE4 7F09C1B4 00F81021 */  addu  $v0, $a3, $t8
/* 0D0CE8 7F09C1B8 8459000E */  lh    $t9, 0xe($v0)
/* 0D0CEC 7F09C1BC 0003C400 */  sll   $t8, $v1, 0x10
/* 0D0CF0 7F09C1C0 1720001A */  bnez  $t9, .L7F09C22C
/* 0D0CF4 7F09C1C4 0018CC03 */   sra   $t9, $t8, 0x10
/* 0D0CF8 7F09C1C8 03260019 */  multu $t9, $a2
/* 0D0CFC 7F09C1CC 844B000C */  lh    $t3, 0xc($v0)
/* 0D0D00 7F09C1D0 848C000C */  lh    $t4, 0xc($a0)
/* 0D0D04 7F09C1D4 00032C00 */  sll   $a1, $v1, 0x10
/* 0D0D08 7F09C1D8 00057C03 */  sra   $t7, $a1, 0x10
/* 0D0D0C 7F09C1DC 016C6821 */  addu  $t5, $t3, $t4
/* 0D0D10 7F09C1E0 A44D000C */  sh    $t5, 0xc($v0)
/* 0D0D14 7F09C1E4 848E0010 */  lh    $t6, 0x10($a0)
/* 0D0D18 7F09C1E8 01E02825 */  move  $a1, $t7
/* 0D0D1C 7F09C1EC 00005812 */  mflo  $t3
/* 0D0D20 7F09C1F0 A44E0010 */  sh    $t6, 0x10($v0)
/* 0D0D24 7F09C1F4 A489000E */  sh    $t1, 0xe($a0)
/* 0D0D28 7F09C1F8 00EB6021 */  addu  $t4, $a3, $t3
/* 0D0D2C 7F09C1FC 85830010 */  lh    $v1, 0x10($t4)
/* 0D0D30 7F09C200 0460000A */  bltz  $v1, .L7F09C22C
/* 0D0D34 7F09C204 00000000 */   nop   
/* 0D0D38 7F09C208 00660019 */  multu $v1, $a2
/* 0D0D3C 7F09C20C 00006812 */  mflo  $t5
/* 0D0D40 7F09C210 00ED7021 */  addu  $t6, $a3, $t5
/* 0D0D44 7F09C214 10000005 */  b     .L7F09C22C
/* 0D0D48 7F09C218 A5CF0012 */   sh    $t7, 0x12($t6)
/* 0D0D4C 7F09C21C 84850010 */  lh    $a1, 0x10($a0)
.L7F09C220:
/* 0D0D50 7F09C220 14A90002 */  bne   $a1, $t1, .L7F09C22C
/* 0D0D54 7F09C224 00000000 */   nop   
/* 0D0D58 7F09C228 24080001 */  li    $t0, 1
.L7F09C22C:
/* 0D0D5C 7F09C22C 1100FFB4 */  beqz  $t0, .L7F09C100
/* 0D0D60 7F09C230 00000000 */   nop   
/* 0D0D64 7F09C234 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F09C238:
/* 0D0D68 7F09C238 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D0D6C 7F09C23C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0D0D70 7F09C240 03E00008 */  jr    $ra
/* 0D0D74 7F09C244 00000000 */   nop   
)
#endif



