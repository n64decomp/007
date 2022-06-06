#include <ultra64.h>
#include <PR/libaudio.h>
#include "game/player.h"


#ifdef NONMATCHING
void cleanupplayersoundrelated(void)
{
    int i;
    int j=0;

    for(i=0; i < getPlayerCount(); i++)
    {
        for(;j<2;j++)
        {
            if((&g_playerPointers[i]->hands[j])->field_A44 && sndGetPlayingState((&g_playerPointers[i]->hands[j])->field_A44))
            {
                sndDeactivate((&g_playerPointers[i]->hands[j])->field_A44);
            }
        }
    }
}

#else

#if defined(VERSION_US) || defined(VERSION_JP)
GLOBAL_ASM(
.text
glabel cleanupplayersoundrelated
/* 03C4B0 7F007980 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03C4B4 7F007984 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03C4B8 7F007988 AFB40028 */  sw    $s4, 0x28($sp)
/* 03C4BC 7F00798C AFB30024 */  sw    $s3, 0x24($sp)
/* 03C4C0 7F007990 AFB20020 */  sw    $s2, 0x20($sp)
/* 03C4C4 7F007994 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03C4C8 7F007998 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C4CC 7F00799C 0FC26919 */  jal   getPlayerCount
/* 03C4D0 7F0079A0 0000A025 */   move  $s4, $zero
/* 03C4D4 7F0079A4 1840001B */  blez  $v0, .L7F007A14
/* 03C4D8 7F0079A8 00147080 */   sll   $t6, $s4, 2
/* 03C4DC 7F0079AC 3C0F8008 */  lui   $t7, %hi(g_playerPointers) 
/* 03C4E0 7F0079B0 25EF9EE0 */  addiu $t7, %lo(g_playerPointers) # addiu $t7, $t7, -0x6120
/* 03C4E4 7F0079B4 01CF9021 */  addu  $s2, $t6, $t7
/* 03C4E8 7F0079B8 24130750 */  li    $s3, 1872
/* 03C4EC 7F0079BC 00008825 */  move  $s1, $zero
.L7F0079C0:
/* 03C4F0 7F0079C0 8E580000 */  lw    $t8, ($s2)
.L7F0079C4:
/* 03C4F4 7F0079C4 03118021 */  addu  $s0, $t8, $s1
/* 03C4F8 7F0079C8 8E040A44 */  lw    $a0, 0xa44($s0)
/* 03C4FC 7F0079CC 26100870 */  addiu $s0, $s0, 0x870
/* 03C500 7F0079D0 50800008 */  beql  $a0, $zero, .L7F0079F4
/* 03C504 7F0079D4 263103A8 */   addiu $s1, $s1, 0x3a8
/* 03C508 7F0079D8 0C00237C */  jal   sndGetPlayingState
/* 03C50C 7F0079DC 00000000 */   nop   
/* 03C510 7F0079E0 50400004 */  beql  $v0, $zero, .L7F0079F4
/* 03C514 7F0079E4 263103A8 */   addiu $s1, $s1, 0x3a8
/* 03C518 7F0079E8 0C002408 */  jal   sndDeactivate
/* 03C51C 7F0079EC 8E0401D4 */   lw    $a0, 0x1d4($s0)
/* 03C520 7F0079F0 263103A8 */  addiu $s1, $s1, 0x3a8
.L7F0079F4:
/* 03C524 7F0079F4 5633FFF3 */  bnel  $s1, $s3, .L7F0079C4
/* 03C528 7F0079F8 8E580000 */   lw    $t8, ($s2)
/* 03C52C 7F0079FC 26940001 */  addiu $s4, $s4, 1
/* 03C530 7F007A00 0FC26919 */  jal   getPlayerCount
/* 03C534 7F007A04 26520004 */   addiu $s2, $s2, 4
/* 03C538 7F007A08 0282082A */  slt   $at, $s4, $v0
/* 03C53C 7F007A0C 5420FFEC */  bnezl $at, .L7F0079C0
/* 03C540 7F007A10 00008825 */   move  $s1, $zero
.L7F007A14:
/* 03C544 7F007A14 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03C548 7F007A18 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C54C 7F007A1C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03C550 7F007A20 8FB20020 */  lw    $s2, 0x20($sp)
/* 03C554 7F007A24 8FB30024 */  lw    $s3, 0x24($sp)
/* 03C558 7F007A28 8FB40028 */  lw    $s4, 0x28($sp)
/* 03C55C 7F007A2C 03E00008 */  jr    $ra
/* 03C560 7F007A30 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.text
glabel cleanupplayersoundrelated
/* 03A2F0 7F007900 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03A2F4 7F007904 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03A2F8 7F007908 AFB40028 */  sw    $s4, 0x28($sp)
/* 03A2FC 7F00790C AFB30024 */  sw    $s3, 0x24($sp)
/* 03A300 7F007910 AFB20020 */  sw    $s2, 0x20($sp)
/* 03A304 7F007914 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03A308 7F007918 AFB00018 */  sw    $s0, 0x18($sp)
/* 03A30C 7F00791C 0FC26669 */  jal   getPlayerCount
/* 03A310 7F007920 0000A025 */   move  $s4, $zero
/* 03A314 7F007924 1840001B */  blez  $v0, .L7F007994
/* 03A318 7F007928 00147080 */   sll   $t6, $s4, 2
/* 03A31C 7F00792C 3C0F8007 */  lui   $t7, %hi(g_playerPointers) # $t7, 0x8007
/* 03A320 7F007930 25EF89F0 */  addiu $t7, %lo(g_playerPointers) # addiu $t7, $t7, -0x7610
/* 03A324 7F007934 01CF9021 */  addu  $s2, $t6, $t7
/* 03A328 7F007938 24130750 */  li    $s3, 1872
/* 03A32C 7F00793C 00008825 */  move  $s1, $zero
.L7F007940:
/* 03A330 7F007940 8E580000 */  lw    $t8, ($s2)
.L7F007944:
/* 03A334 7F007944 03118021 */  addu  $s0, $t8, $s1
/* 03A338 7F007948 8E040A3C */  lw    $a0, 0xa3c($s0)
/* 03A33C 7F00794C 26100868 */  addiu $s0, $s0, 0x868
/* 03A340 7F007950 50800008 */  beql  $a0, $zero, .L7F007974
/* 03A344 7F007954 263103A8 */   addiu $s1, $s1, 0x3a8
/* 03A348 7F007958 0C002094 */  jal   sndGetPlayingState
/* 03A34C 7F00795C 00000000 */   nop   
/* 03A350 7F007960 50400004 */  beql  $v0, $zero, .L7F007974
/* 03A354 7F007964 263103A8 */   addiu $s1, $s1, 0x3a8
/* 03A358 7F007968 0C002120 */  jal   sndDeactivate
/* 03A35C 7F00796C 8E0401D4 */   lw    $a0, 0x1d4($s0)
/* 03A360 7F007970 263103A8 */  addiu $s1, $s1, 0x3a8
.L7F007974:
/* 03A364 7F007974 5633FFF3 */  bnel  $s1, $s3, .L7F007944
/* 03A368 7F007978 8E580000 */   lw    $t8, ($s2)
/* 03A36C 7F00797C 26940001 */  addiu $s4, $s4, 1
/* 03A370 7F007980 0FC26669 */  jal   getPlayerCount
/* 03A374 7F007984 26520004 */   addiu $s2, $s2, 4
/* 03A378 7F007988 0282082A */  slt   $at, $s4, $v0
/* 03A37C 7F00798C 5420FFEC */  bnezl $at, .L7F007940
/* 03A380 7F007990 00008825 */   move  $s1, $zero
.L7F007994:
/* 03A384 7F007994 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03A388 7F007998 8FB00018 */  lw    $s0, 0x18($sp)
/* 03A38C 7F00799C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03A390 7F0079A0 8FB20020 */  lw    $s2, 0x20($sp)
/* 03A394 7F0079A4 8FB30024 */  lw    $s3, 0x24($sp)
/* 03A398 7F0079A8 8FB40028 */  lw    $s4, 0x28($sp)
/* 03A39C 7F0079AC 03E00008 */  jr    $ra
/* 03A3A0 7F0079B0 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#endif

