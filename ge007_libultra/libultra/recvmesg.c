#include "ultra64.h"

#ifdef NONMATCHING
void osRecvMesg(s32 arg0, s32 arg1, ? arg2, void *argA, void *argB, s32 argC) {
    s32 temp_s0;

    // Node 0
    temp_s0 = __osDisableInt();
    if (argA->unk8 == 0)
    {
        loop_1:
        // Node 1
        if (argC == 0)
        {
            // Node 2
            __osRestoreInt(temp_s0);
            return;
            // (possible return value: -1)
        }
        // Node 3
        __osRunningThread->unk10 = (u16)8;
        __osEnqueueAndYield(argA);
        if (argA->unk8 == 0)
        {
            goto loop_1;
        }
    }
    // Node 4
    if (argB != 0)
    {
        // Node 5
        *argB = (?32) *(argA->unk14 + (argA->unkC * 4));
    }
    // Node 6
    argA->unkC = (s32) ((s32) (argA->unkC + 1) % (s32) argA->unk10);
    argA->unk8 = (s32) (argA->unk8 + -1);
    if (*argA->unk4 != 0)
    {
        // Node 7
        osStartThread(__osPopThread((argA + 4)));
    }
    // Node 8
    __osRestoreInt(temp_s0);
    return;
    // (possible return value: 0)
}
#else
GLOBAL_ASM(
.text
glabel osRecvMesg
/* 00E9D0 7000DDD0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E9D4 7000DDD4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E9D8 7000DDD8 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E9DC 7000DDDC AFA5002C */  sw    $a1, 0x2c($sp)
/* 00E9E0 7000DDE0 AFA60030 */  sw    $a2, 0x30($sp)
/* 00E9E4 7000DDE4 AFB10018 */  sw    $s1, 0x18($sp)
/* 00E9E8 7000DDE8 0C00617C */  jal   __osDisableInt
/* 00E9EC 7000DDEC AFB00014 */   sw    $s0, 0x14($sp)
/* 00E9F0 7000DDF0 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E9F4 7000DDF4 00408025 */  move  $s0, $v0
/* 00E9F8 7000DDF8 8DCF0008 */  lw    $t7, 8($t6)
/* 00E9FC 7000DDFC 15E00012 */  bnez  $t7, .L7000DE48
/* 00EA00 7000DE00 00000000 */   nop   
.L7000DE04:
/* 00EA04 7000DE04 8FB80030 */  lw    $t8, 0x30($sp)
/* 00EA08 7000DE08 17000005 */  bnez  $t8, .L7000DE20
/* 00EA0C 7000DE0C 00000000 */   nop   
/* 00EA10 7000DE10 0C006184 */  jal   __osRestoreInt
/* 00EA14 7000DE14 02002025 */   move  $a0, $s0
/* 00EA18 7000DE18 10000036 */  b     .L7000DEF4
/* 00EA1C 7000DE1C 2402FFFF */   li    $v0, -1
.L7000DE20:
/* 00EA20 7000DE20 3C088002 */  lui   $t0, %hi(__osRunningThread) 
/* 00EA24 7000DE24 8D087730 */  lw    $t0, %lo(__osRunningThread)($t0)
/* 00EA28 7000DE28 24190008 */  li    $t9, 8
/* 00EA2C 7000DE2C A5190010 */  sh    $t9, 0x10($t0)
/* 00EA30 7000DE30 0C0041EB */  jal   __osEnqueueAndYield
/* 00EA34 7000DE34 8FA40028 */   lw    $a0, 0x28($sp)
/* 00EA38 7000DE38 8FA90028 */  lw    $t1, 0x28($sp)
/* 00EA3C 7000DE3C 8D2A0008 */  lw    $t2, 8($t1)
/* 00EA40 7000DE40 1140FFF0 */  beqz  $t2, .L7000DE04
/* 00EA44 7000DE44 00000000 */   nop   
.L7000DE48:
/* 00EA48 7000DE48 8FAB002C */  lw    $t3, 0x2c($sp)
/* 00EA4C 7000DE4C 11600008 */  beqz  $t3, .L7000DE70
/* 00EA50 7000DE50 00000000 */   nop   
/* 00EA54 7000DE54 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00EA58 7000DE58 8D8E000C */  lw    $t6, 0xc($t4)
/* 00EA5C 7000DE5C 8D8D0014 */  lw    $t5, 0x14($t4)
/* 00EA60 7000DE60 000E7880 */  sll   $t7, $t6, 2
/* 00EA64 7000DE64 01AFC021 */  addu  $t8, $t5, $t7
/* 00EA68 7000DE68 8F190000 */  lw    $t9, ($t8)
/* 00EA6C 7000DE6C AD790000 */  sw    $t9, ($t3)
.L7000DE70:
/* 00EA70 7000DE70 8FA80028 */  lw    $t0, 0x28($sp)
/* 00EA74 7000DE74 8D09000C */  lw    $t1, 0xc($t0)
/* 00EA78 7000DE78 8D0C0010 */  lw    $t4, 0x10($t0)
/* 00EA7C 7000DE7C 252A0001 */  addiu $t2, $t1, 1
/* 00EA80 7000DE80 014C001A */  div   $zero, $t2, $t4
/* 00EA84 7000DE84 00007010 */  mfhi  $t6
/* 00EA88 7000DE88 AD0E000C */  sw    $t6, 0xc($t0)
/* 00EA8C 7000DE8C 8FAD0028 */  lw    $t5, 0x28($sp)
/* 00EA90 7000DE90 15800002 */  bnez  $t4, .L7000DE9C
/* 00EA94 7000DE94 00000000 */   nop   
/* 00EA98 7000DE98 0007000D */  break 7
.L7000DE9C:
/* 00EA9C 7000DE9C 2401FFFF */  li    $at, -1
/* 00EAA0 7000DEA0 15810004 */  bne   $t4, $at, .L7000DEB4
/* 00EAA4 7000DEA4 3C018000 */   lui   $at, 0x8000
/* 00EAA8 7000DEA8 15410002 */  bne   $t2, $at, .L7000DEB4
/* 00EAAC 7000DEAC 00000000 */   nop   
/* 00EAB0 7000DEB0 0006000D */  break 6
.L7000DEB4:
/* 00EAB4 7000DEB4 8DAF0008 */  lw    $t7, 8($t5)
/* 00EAB8 7000DEB8 25F8FFFF */  addiu $t8, $t7, -1
/* 00EABC 7000DEBC ADB80008 */  sw    $t8, 8($t5)
/* 00EAC0 7000DEC0 8FB90028 */  lw    $t9, 0x28($sp)
/* 00EAC4 7000DEC4 8F2B0004 */  lw    $t3, 4($t9)
/* 00EAC8 7000DEC8 8D690000 */  lw    $t1, ($t3)
/* 00EACC 7000DECC 11200006 */  beqz  $t1, .L7000DEE8
/* 00EAD0 7000DED0 00000000 */   nop   
/* 00EAD4 7000DED4 0C00423D */  jal   __osPopThread
/* 00EAD8 7000DED8 27240004 */   addiu $a0, $t9, 4
/* 00EADC 7000DEDC 00408825 */  move  $s1, $v0
/* 00EAE0 7000DEE0 0C003560 */  jal   osStartThread
/* 00EAE4 7000DEE4 02202025 */   move  $a0, $s1
.L7000DEE8:
/* 00EAE8 7000DEE8 0C006184 */  jal   __osRestoreInt
/* 00EAEC 7000DEEC 02002025 */   move  $a0, $s0
/* 00EAF0 7000DEF0 00001025 */  move  $v0, $zero
.L7000DEF4:
/* 00EAF4 7000DEF4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00EAF8 7000DEF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 00EAFC 7000DEFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 00EB00 7000DF00 03E00008 */  jr    $ra
/* 00EB04 7000DF04 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif