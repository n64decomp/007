#include <ultra64.h>




#ifdef NONMATCHING
void cleanupGuardData(void) {
    void *temp_v0;
    s32 temp_s2;
    s32 phi_s0;
    s32 phi_s2;
    s32 phi_v1;

    // Node 0
    if (num_guards > 0)
    {
        // Node 1
        phi_s0 = 0;
        phi_s2 = 0;
        phi_v1 = num_guards;
loop_2:
        // Node 2
        temp_v0 = (ptr_guard_data + phi_s0);
        if (temp_v0->unk1C != 0)
        {
            // Node 3
            disable_sounds_attached_to_player_then_something(temp_v0->unk18);
            chrpropDelist((ptr_guard_data + phi_s0)->unk18);
            chrpropDisable((ptr_guard_data + phi_s0)->unk18);
            chrpropFree((ptr_guard_data + phi_s0)->unk18);
            phi_v1 = num_guards;
        }
        // Node 4
        temp_s2 = (phi_s2 + 1);
        phi_s0 = (phi_s0 + 0x1dc);
        phi_s2 = temp_s2;
        phi_v1 = phi_v1;
        if (temp_s2 < phi_v1)
        {
            goto loop_2;
        }
    }
    // Node 5
    return;
}
#else
GLOBAL_ASM(
.text
glabel cleanupGuardData
/* 03BEE0 7F0073B0 3C038003 */  lui   $v1, %hi(num_guards)
/* 03BEE4 7F0073B4 8C63CC68 */  lw    $v1, %lo(num_guards)($v1)
/* 03BEE8 7F0073B8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03BEEC 7F0073BC AFB20020 */  sw    $s2, 0x20($sp)
/* 03BEF0 7F0073C0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 03BEF4 7F0073C4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03BEF8 7F0073C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 03BEFC 7F0073CC 1860001D */  blez  $v1, .L7F007444
/* 03BF00 7F0073D0 00009025 */   move  $s2, $zero
/* 03BF04 7F0073D4 3C118003 */  lui   $s1, %hi(ptr_guard_data)
/* 03BF08 7F0073D8 2631CC64 */  addiu $s1, %lo(ptr_guard_data) # addiu $s1, $s1, -0x339c
/* 03BF0C 7F0073DC 00008025 */  move  $s0, $zero
.L7F0073E0:
/* 03BF10 7F0073E0 8E2E0000 */  lw    $t6, ($s1)
/* 03BF14 7F0073E4 01D01021 */  addu  $v0, $t6, $s0
/* 03BF18 7F0073E8 8C4F001C */  lw    $t7, 0x1c($v0)
/* 03BF1C 7F0073EC 51E00012 */  beql  $t7, $zero, .L7F007438
/* 03BF20 7F0073F0 26520001 */   addiu $s2, $s2, 1
/* 03BF24 7F0073F4 0FC08105 */  jal   disable_sounds_attached_to_player_then_something
/* 03BF28 7F0073F8 8C440018 */   lw    $a0, 0x18($v0)
/* 03BF2C 7F0073FC 8E380000 */  lw    $t8, ($s1)
/* 03BF30 7F007400 0310C821 */  addu  $t9, $t8, $s0
/* 03BF34 7F007404 0FC0E94E */  jal   chrpropDelist
/* 03BF38 7F007408 8F240018 */   lw    $a0, 0x18($t9)
/* 03BF3C 7F00740C 8E280000 */  lw    $t0, ($s1)
/* 03BF40 7F007410 01104821 */  addu  $t1, $t0, $s0
/* 03BF44 7F007414 0FC0E905 */  jal   chrpropDisable
/* 03BF48 7F007418 8D240018 */   lw    $a0, 0x18($t1)
/* 03BF4C 7F00741C 8E2A0000 */  lw    $t2, ($s1)
/* 03BF50 7F007420 01505821 */  addu  $t3, $t2, $s0
/* 03BF54 7F007424 0FC0E921 */  jal   chrpropFree
/* 03BF58 7F007428 8D640018 */   lw    $a0, 0x18($t3)
/* 03BF5C 7F00742C 3C038003 */  lui   $v1, %hi(num_guards)
/* 03BF60 7F007430 8C63CC68 */  lw    $v1, %lo(num_guards)($v1)
/* 03BF64 7F007434 26520001 */  addiu $s2, $s2, 1
.L7F007438:
/* 03BF68 7F007438 0243082A */  slt   $at, $s2, $v1
/* 03BF6C 7F00743C 1420FFE8 */  bnez  $at, .L7F0073E0
/* 03BF70 7F007440 261001DC */   addiu $s0, $s0, 0x1dc
.L7F007444:
/* 03BF74 7F007444 8FBF0024 */  lw    $ra, 0x24($sp)
/* 03BF78 7F007448 8FB00018 */  lw    $s0, 0x18($sp)
/* 03BF7C 7F00744C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03BF80 7F007450 8FB20020 */  lw    $s2, 0x20($sp)
/* 03BF84 7F007454 03E00008 */  jr    $ra
/* 03BF88 7F007458 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


