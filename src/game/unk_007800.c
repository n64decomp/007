#include "ultra64.h"



#ifdef NONMATCHING
void cleanupExplosions(void) {
    ? temp_ret;
    void *temp_t8;
    s32 temp_s0;
    void *temp_t7;
    s32 temp_s0_2;
    s32 phi_s0;
    s32 phi_s0_2;
    ? phi_return;
    ? phi_return_2;
    ? phi_return_3;
    ? phi_return_4;

    // Node 0
    D_80040170 = 0;
    temp_ret = video_related_9(0);
    phi_s0 = 0;
    phi_return_3 = temp_ret;
    phi_return_4 = temp_ret;
    if (ptr_explosion_buf != 0)
    {
loop_1:
        // Node 1
        temp_t8 = (ptr_explosion_buf + phi_s0);
        if (*temp_t8 != 0)
        {
            // Node 2
            sub_GAME_7F03A538(*temp_t8);
            unset_stateflag_0x04_for_posdata(*(ptr_explosion_buf + phi_s0));
            *(ptr_explosion_buf + phi_s0) = 0;
            phi_return_4 = set_last_obj_pos_data(*(ptr_explosion_buf + phi_s0));
        }
        // Node 3
        temp_s0 = (phi_s0 + 0x3e0);
        phi_s0 = temp_s0;
        phi_return_3 = phi_return_4;
        phi_return_4 = phi_return_4;
        if (temp_s0 != 0x1740)
        {
            goto loop_1;
        }
    }
    // Node 4
    phi_s0_2 = 0;
    phi_return = phi_return_3;
    phi_return_2 = phi_return_3;
    if (ptr_smoke_buf != 0)
    {
loop_5:
        // Node 5
        temp_t7 = (ptr_smoke_buf + phi_s0_2);
        if (*temp_t7 != 0)
        {
            // Node 6
            sub_GAME_7F03A538(*temp_t7);
            unset_stateflag_0x04_for_posdata(*(ptr_smoke_buf + phi_s0_2));
            *(ptr_smoke_buf + phi_s0_2) = 0;
            phi_return_2 = set_last_obj_pos_data(*(ptr_smoke_buf + phi_s0_2));
        }
        // Node 7
        temp_s0_2 = (phi_s0_2 + 0x198);
        phi_s0_2 = temp_s0_2;
        phi_return = phi_return_2;
        phi_return_2 = phi_return_2;
        if (temp_s0_2 != 0x1fe0)
        {
            goto loop_5;
        }
    }
    // Node 8
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel cleanupExplosions
/* 03C330 7F007800 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03C334 7F007804 AFBF0024 */  sw    $ra, 0x24($sp)
/* 03C338 7F007808 3C018004 */  lui   $at, %hi(D_80040170) # $at, 0x8004
/* 03C33C 7F00780C 44806000 */  mtc1  $zero, $f12
/* 03C340 7F007810 AFB20020 */  sw    $s2, 0x20($sp)
/* 03C344 7F007814 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03C348 7F007818 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C34C 7F00781C 0C000EC1 */  jal   video_related_9
/* 03C350 7F007820 AC200170 */   sw    $zero, %lo(D_80040170)($at)
/* 03C354 7F007824 3C118008 */  lui   $s1, %hi(ptr_explosion_buf) # $s1, 0x8008
/* 03C358 7F007828 2631A144 */  addiu $s1, %lo(ptr_explosion_buf) # addiu $s1, $s1, -0x5ebc
/* 03C35C 7F00782C 8E2E0000 */  lw    $t6, ($s1)
/* 03C360 7F007830 00008025 */  move  $s0, $zero
/* 03C364 7F007834 24121740 */  li    $s2, 5952
/* 03C368 7F007838 11C00016 */  beqz  $t6, .L7F007894
/* 03C36C 7F00783C 00000000 */   nop   
/* 03C370 7F007840 8E2F0000 */  lw    $t7, ($s1)
.L7F007844:
/* 03C374 7F007844 01F0C021 */  addu  $t8, $t7, $s0
/* 03C378 7F007848 8F040000 */  lw    $a0, ($t8)
/* 03C37C 7F00784C 5080000F */  beql  $a0, $zero, .L7F00788C
/* 03C380 7F007850 261003E0 */   addiu $s0, $s0, 0x3e0
/* 03C384 7F007854 0FC0E94E */  jal   sub_GAME_7F03A538
/* 03C388 7F007858 00000000 */   nop   
/* 03C38C 7F00785C 8E390000 */  lw    $t9, ($s1)
/* 03C390 7F007860 03304021 */  addu  $t0, $t9, $s0
/* 03C394 7F007864 0FC0E905 */  jal   unset_stateflag_0x04_for_posdata
/* 03C398 7F007868 8D040000 */   lw    $a0, ($t0)
/* 03C39C 7F00786C 8E290000 */  lw    $t1, ($s1)
/* 03C3A0 7F007870 01305021 */  addu  $t2, $t1, $s0
/* 03C3A4 7F007874 0FC0E921 */  jal   set_last_obj_pos_data
/* 03C3A8 7F007878 8D440000 */   lw    $a0, ($t2)
/* 03C3AC 7F00787C 8E2B0000 */  lw    $t3, ($s1)
/* 03C3B0 7F007880 01706021 */  addu  $t4, $t3, $s0
/* 03C3B4 7F007884 AD800000 */  sw    $zero, ($t4)
/* 03C3B8 7F007888 261003E0 */  addiu $s0, $s0, 0x3e0
.L7F00788C:
/* 03C3BC 7F00788C 5612FFED */  bnel  $s0, $s2, .L7F007844
/* 03C3C0 7F007890 8E2F0000 */   lw    $t7, ($s1)
.L7F007894:
/* 03C3C4 7F007894 3C118008 */  lui   $s1, %hi(ptr_smoke_buf) # $s1, 0x8008
/* 03C3C8 7F007898 2631A140 */  addiu $s1, %lo(ptr_smoke_buf) # addiu $s1, $s1, -0x5ec0
/* 03C3CC 7F00789C 8E2D0000 */  lw    $t5, ($s1)
/* 03C3D0 7F0078A0 00008025 */  move  $s0, $zero
/* 03C3D4 7F0078A4 24121FE0 */  li    $s2, 8160
/* 03C3D8 7F0078A8 51A00017 */  beql  $t5, $zero, .L7F007908
/* 03C3DC 7F0078AC 8FBF0024 */   lw    $ra, 0x24($sp)
/* 03C3E0 7F0078B0 8E2E0000 */  lw    $t6, ($s1)
.L7F0078B4:
/* 03C3E4 7F0078B4 01D07821 */  addu  $t7, $t6, $s0
/* 03C3E8 7F0078B8 8DE40000 */  lw    $a0, ($t7)
/* 03C3EC 7F0078BC 5080000F */  beql  $a0, $zero, .L7F0078FC
/* 03C3F0 7F0078C0 26100198 */   addiu $s0, $s0, 0x198
/* 03C3F4 7F0078C4 0FC0E94E */  jal   sub_GAME_7F03A538
/* 03C3F8 7F0078C8 00000000 */   nop   
/* 03C3FC 7F0078CC 8E380000 */  lw    $t8, ($s1)
/* 03C400 7F0078D0 0310C821 */  addu  $t9, $t8, $s0
/* 03C404 7F0078D4 0FC0E905 */  jal   unset_stateflag_0x04_for_posdata
/* 03C408 7F0078D8 8F240000 */   lw    $a0, ($t9)
/* 03C40C 7F0078DC 8E280000 */  lw    $t0, ($s1)
/* 03C410 7F0078E0 01104821 */  addu  $t1, $t0, $s0
/* 03C414 7F0078E4 0FC0E921 */  jal   set_last_obj_pos_data
/* 03C418 7F0078E8 8D240000 */   lw    $a0, ($t1)
/* 03C41C 7F0078EC 8E2A0000 */  lw    $t2, ($s1)
/* 03C420 7F0078F0 01505821 */  addu  $t3, $t2, $s0
/* 03C424 7F0078F4 AD600000 */  sw    $zero, ($t3)
/* 03C428 7F0078F8 26100198 */  addiu $s0, $s0, 0x198
.L7F0078FC:
/* 03C42C 7F0078FC 5612FFED */  bnel  $s0, $s2, .L7F0078B4
/* 03C430 7F007900 8E2E0000 */   lw    $t6, ($s1)
/* 03C434 7F007904 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F007908:
/* 03C438 7F007908 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C43C 7F00790C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03C440 7F007910 8FB20020 */  lw    $s2, 0x20($sp)
/* 03C444 7F007914 03E00008 */  jr    $ra
/* 03C448 7F007918 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

