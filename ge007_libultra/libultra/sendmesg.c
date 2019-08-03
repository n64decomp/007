#include "ultra64.h"

#ifdef NONMATCHING
void osSendMesg(s32 arg0, s32 arg1, ? arg2, void *argE, ?32 argF, s32 arg10) {
    s32 temp_s0;

    // Node 0
    temp_s0 = __osDisableInt();
    if (argE->unk8 >= argE->unk10)
    {
        loop_1:
        // Node 1
        if (arg10 != 1)
        {
            // Node 3
            __osRestoreInt(temp_s0);
            return;
            // (possible return value: -1)
        }
        // Node 2
        __osRunningThread->unk10 = (u16)8;
        __osEnqueueAndYield((argE + 4));
        // Node 4
        if (argE->unk8 >= argE->unk10)
        {
            goto loop_1;
        }
    }
    // Node 5
    *(argE->unk14 + (((s32) (argE->unkC + argE->unk8) % (s32) argE->unk10) * 4)) = argF;
    argE->unk8 = (s32) (argE->unk8 + 1);
    if (**argE != 0)
    {
        // Node 6
        osStartThread(__osPopThread(argE));
    }
    // Node 7
    __osRestoreInt(temp_s0);
    return;
    // (possible return value: 0)
}
#else
GLOBAL_ASM(
.text
glabel osSendMesg
/* 00EB10 7000DF10 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00EB14 7000DF14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00EB18 7000DF18 AFA40038 */  sw    $a0, 0x38($sp)
/* 00EB1C 7000DF1C AFA5003C */  sw    $a1, 0x3c($sp)
/* 00EB20 7000DF20 AFA60040 */  sw    $a2, 0x40($sp)
/* 00EB24 7000DF24 AFB20020 */  sw    $s2, 0x20($sp)
/* 00EB28 7000DF28 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00EB2C 7000DF2C 0C00617C */  jal   __osDisableInt
/* 00EB30 7000DF30 AFB00018 */   sw    $s0, 0x18($sp)
/* 00EB34 7000DF34 8FAE0038 */  lw    $t6, 0x38($sp)
/* 00EB38 7000DF38 00408025 */  move  $s0, $v0
/* 00EB3C 7000DF3C 8DCF0008 */  lw    $t7, 8($t6)
/* 00EB40 7000DF40 8DD80010 */  lw    $t8, 0x10($t6)
/* 00EB44 7000DF44 01F8082A */  slt   $at, $t7, $t8
/* 00EB48 7000DF48 14200018 */  bnez  $at, .L7000DFAC
/* 00EB4C 7000DF4C 00000000 */   nop   
.L7000DF50:
/* 00EB50 7000DF50 8FB90040 */  lw    $t9, 0x40($sp)
/* 00EB54 7000DF54 24010001 */  li    $at, 1
/* 00EB58 7000DF58 1721000A */  bne   $t9, $at, .L7000DF84
/* 00EB5C 7000DF5C 00000000 */   nop   
/* 00EB60 7000DF60 3C098002 */  lui   $t1, %hi(__osRunningThread) # $t1, 0x8002
/* 00EB64 7000DF64 8D297730 */  lw    $t1, %lo(__osRunningThread)($t1)
/* 00EB68 7000DF68 24080008 */  li    $t0, 8
/* 00EB6C 7000DF6C A5280010 */  sh    $t0, 0x10($t1)
/* 00EB70 7000DF70 8FA40038 */  lw    $a0, 0x38($sp)
/* 00EB74 7000DF74 0C0041EB */  jal   __osEnqueueAndYield
/* 00EB78 7000DF78 24840004 */   addiu $a0, $a0, 4
/* 00EB7C 7000DF7C 10000005 */  b     .L7000DF94
/* 00EB80 7000DF80 00000000 */   nop   
.L7000DF84:
/* 00EB84 7000DF84 0C006184 */  jal   __osRestoreInt
/* 00EB88 7000DF88 02002025 */   move  $a0, $s0
/* 00EB8C 7000DF8C 1000002D */  b     .L7000E044
/* 00EB90 7000DF90 2402FFFF */   li    $v0, -1
.L7000DF94:
/* 00EB94 7000DF94 8FAA0038 */  lw    $t2, 0x38($sp)
/* 00EB98 7000DF98 8D4B0008 */  lw    $t3, 8($t2)
/* 00EB9C 7000DF9C 8D4C0010 */  lw    $t4, 0x10($t2)
/* 00EBA0 7000DFA0 016C082A */  slt   $at, $t3, $t4
/* 00EBA4 7000DFA4 1020FFEA */  beqz  $at, .L7000DF50
/* 00EBA8 7000DFA8 00000000 */   nop   
.L7000DFAC:
/* 00EBAC 7000DFAC 8FAD0038 */  lw    $t5, 0x38($sp)
/* 00EBB0 7000DFB0 8FA8003C */  lw    $t0, 0x3c($sp)
/* 00EBB4 7000DFB4 8DAE000C */  lw    $t6, 0xc($t5)
/* 00EBB8 7000DFB8 8DAF0008 */  lw    $t7, 8($t5)
/* 00EBBC 7000DFBC 8DB90010 */  lw    $t9, 0x10($t5)
/* 00EBC0 7000DFC0 8DA90014 */  lw    $t1, 0x14($t5)
/* 00EBC4 7000DFC4 01CFC021 */  addu  $t8, $t6, $t7
/* 00EBC8 7000DFC8 0319001A */  div   $zero, $t8, $t9
/* 00EBCC 7000DFCC 00008810 */  mfhi  $s1
/* 00EBD0 7000DFD0 00115080 */  sll   $t2, $s1, 2
/* 00EBD4 7000DFD4 012A5821 */  addu  $t3, $t1, $t2
/* 00EBD8 7000DFD8 AD680000 */  sw    $t0, ($t3)
/* 00EBDC 7000DFDC 8FAC0038 */  lw    $t4, 0x38($sp)
/* 00EBE0 7000DFE0 17200002 */  bnez  $t9, .L7000DFEC
/* 00EBE4 7000DFE4 00000000 */   nop   
/* 00EBE8 7000DFE8 0007000D */  break 7
.L7000DFEC:
/* 00EBEC 7000DFEC 2401FFFF */  li    $at, -1
/* 00EBF0 7000DFF0 17210004 */  bne   $t9, $at, .L7000E004
/* 00EBF4 7000DFF4 3C018000 */   lui   $at, 0x8000
/* 00EBF8 7000DFF8 17010002 */  bne   $t8, $at, .L7000E004
/* 00EBFC 7000DFFC 00000000 */   nop   
/* 00EC00 7000E000 0006000D */  break 6
.L7000E004:
/* 00EC04 7000E004 8D8E0008 */  lw    $t6, 8($t4)
/* 00EC08 7000E008 25CF0001 */  addiu $t7, $t6, 1
/* 00EC0C 7000E00C AD8F0008 */  sw    $t7, 8($t4)
/* 00EC10 7000E010 8FB80038 */  lw    $t8, 0x38($sp)
/* 00EC14 7000E014 8F190000 */  lw    $t9, ($t8)
/* 00EC18 7000E018 8F2D0000 */  lw    $t5, ($t9)
/* 00EC1C 7000E01C 11A00006 */  beqz  $t5, .L7000E038
/* 00EC20 7000E020 00000000 */   nop   
/* 00EC24 7000E024 0C00423D */  jal   __osPopThread
/* 00EC28 7000E028 03002025 */   move  $a0, $t8
/* 00EC2C 7000E02C 00409025 */  move  $s2, $v0
/* 00EC30 7000E030 0C003560 */  jal   osStartThread
/* 00EC34 7000E034 02402025 */   move  $a0, $s2
.L7000E038:
/* 00EC38 7000E038 0C006184 */  jal   __osRestoreInt
/* 00EC3C 7000E03C 02002025 */   move  $a0, $s0
/* 00EC40 7000E040 00001025 */  move  $v0, $zero
.L7000E044:
/* 00EC44 7000E044 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00EC48 7000E048 8FB00018 */  lw    $s0, 0x18($sp)
/* 00EC4C 7000E04C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00EC50 7000E050 8FB20020 */  lw    $s2, 0x20($sp)
/* 00EC54 7000E054 03E00008 */  jr    $ra
/* 00EC58 7000E058 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif