#include "ultra64.h"




#ifdef NONMATCHING
void cleanupplayersoundrelated(void) {
    ? temp_ret;
    void *temp_s0;
    s32 temp_s1;
    s32 temp_s4;
    ? temp_ret_2;
    void *phi_s2;
    s32 phi_s1;
    s32 phi_s4;
    ? phi_return;

    // Node 0
    temp_ret = getPlayerCount();
    phi_return = temp_ret;
    if (temp_ret > 0)
    {
        // Node 1
        phi_s2 = ((0 * 4) + &players);
        phi_s4 = 0;
loop_2:
        // Node 2
        phi_s1 = 0;
loop_3:
        // Node 3
        temp_s0 = (*phi_s2 + phi_s1);
        if (temp_s0->unkA44 != 0)
        {
            // Node 4
            if (sfxGetArg0Unk3F(temp_s0->unkA44) != 0)
            {
                // Node 5
                sfxDeactivate((temp_s0 + 0x870)->unk1D4);
            }
        }
        // Node 6
        temp_s1 = (phi_s1 + 0x3a8);
        phi_s1 = temp_s1;
        if (temp_s1 != 0x750)
        {
            goto loop_3;
        }
        // Node 7
        temp_s4 = (phi_s4 + 1);
        temp_ret_2 = getPlayerCount();
        phi_s2 = (phi_s2 + 4);
        phi_s4 = temp_s4;
        phi_return = temp_ret_2;
        if (temp_s4 < temp_ret_2)
        {
            goto loop_2;
        }
    }
    // Node 8
    return phi_return;
}

#else
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
/* 03C4DC 7F0079AC 3C0F8008 */  lui   $t7, %hi(players) 
/* 03C4E0 7F0079B0 25EF9EE0 */  addiu $t7, %lo(players) # addiu $t7, $t7, -0x6120
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
/* 03C508 7F0079D8 0C00237C */  jal   sfxGetArg0Unk3F
/* 03C50C 7F0079DC 00000000 */   nop   
/* 03C510 7F0079E0 50400004 */  beql  $v0, $zero, .L7F0079F4
/* 03C514 7F0079E4 263103A8 */   addiu $s1, $s1, 0x3a8
/* 03C518 7F0079E8 0C002408 */  jal   sfxDeactivate
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

