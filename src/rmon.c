#include "ultra64.h"


void rmonproc(void) {
    // (function likely void)
}

s32 rmon_debug_is_final_build(void) {
    return 1;
}

s32 rmon_debug_returns_neg_1(void) {
    return -1;
}


void rmon_debug_stub(void) {
    // (function likely void)
}


void rmon_debug_stub_0(void) {
    // (function likely void)
}

void rmon_debug_stub_1(void) {
    // (function likely void)
}

void rmon_debug_stub_2(void) {
    // (function likely void)
}

void rmon_debug_stub_3(void) {
    // (function likely void)
}

void rmon_debug_stub_4(void) {
    // (function likely void)
}



#ifdef NONMATCHING
? proutSyncPrintf(s32 arg0, void *arg1, s32 arg2)
{
    s32 temp_s0;
    void *phi_s1;
    s32 phi_s0;

    if (arg2 != 0)
    {
        phi_s1 = arg1;
        phi_s0 = 0;
loop_2:
        temp_s0 = phi_s0 + 1;
        __osRdbSend(*phi_s1);
        phi_s1 = phi_s1 + 1;
        phi_s0 = temp_s0;
        if (temp_s0 != arg2)
        {
            goto loop_2;
        }
    }
    return 1;
}
#else
GLOBAL_ASM(
.text
glabel proutSyncPrintf
/* 00DAE8 7000CEE8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00DAEC 7000CEEC AFB20020 */  sw    $s2, 0x20($sp)
/* 00DAF0 7000CEF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 00DAF4 7000CEF4 00C09025 */  move  $s2, $a2
/* 00DAF8 7000CEF8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00DAFC 7000CEFC AFB1001C */  sw    $s1, 0x1c($sp)
/* 00DB00 7000CF00 AFA40028 */  sw    $a0, 0x28($sp)
/* 00DB04 7000CF04 10C00008 */  beqz  $a2, .L7000CF28
/* 00DB08 7000CF08 00008025 */   move  $s0, $zero
/* 00DB0C 7000CF0C 00A08825 */  move  $s1, $a1
/* 00DB10 7000CF10 92240000 */  lbu   $a0, ($s1)
.L7000CF14:
/* 00DB14 7000CF14 26100001 */  addiu $s0, $s0, 1
/* 00DB18 7000CF18 0C0015AF */  jal   __osRdbSend
/* 00DB1C 7000CF1C 26310001 */   addiu $s1, $s1, 1
/* 00DB20 7000CF20 5612FFFC */  bnel  $s0, $s2, .L7000CF14
/* 00DB24 7000CF24 92240000 */   lbu   $a0, ($s1)
.L7000CF28:
/* 00DB28 7000CF28 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00DB2C 7000CF2C 8FB00018 */  lw    $s0, 0x18($sp)
/* 00DB30 7000CF30 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00DB34 7000CF34 8FB20020 */  lw    $s2, 0x20($sp)
/* 00DB38 7000CF38 27BD0028 */  addiu $sp, $sp, 0x28
/* 00DB3C 7000CF3C 03E00008 */  jr    $ra
/* 00DB40 7000CF40 24020001 */   li    $v0, 1
)
#endif



#ifdef NONMATCHING
void osSyncPrintf(s32 arg0, s32 arg1, ? arg2, ? arg3)
{
    _Printf(&proutSyncPrintf, 0, arg0, &arg1);
}
#else
GLOBAL_ASM(
.text
glabel osSyncPrintf
/* 00DB44 7000CF44 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00DB48 7000CF48 AFA40020 */  sw    $a0, 0x20($sp)
/* 00DB4C 7000CF4C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00DB50 7000CF50 AFA50024 */  sw    $a1, 0x24($sp)
/* 00DB54 7000CF54 AFA60028 */  sw    $a2, 0x28($sp)
/* 00DB58 7000CF58 AFA7002C */  sw    $a3, 0x2c($sp)
/* 00DB5C 7000CF5C 3C047001 */  lui   $a0, %hi(proutSyncPrintf) # $a0, 0x7001
/* 00DB60 7000CF60 2484CEE8 */  addiu $a0, %lo(proutSyncPrintf) # addiu $a0, $a0, -0x3118
/* 00DB64 7000CF64 27A70024 */  addiu $a3, $sp, 0x24
/* 00DB68 7000CF68 8FA60020 */  lw    $a2, 0x20($sp)
/* 00DB6C 7000CF6C 0C004FD8 */  jal   _Printf
/* 00DB70 7000CF70 00002825 */   move  $a1, $zero
/* 00DB74 7000CF74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00DB78 7000CF78 27BD0020 */  addiu $sp, $sp, 0x20
/* 00DB7C 7000CF7C 03E00008 */  jr    $ra
/* 00DB80 7000CF80 00000000 */   nop  
)
#endif




