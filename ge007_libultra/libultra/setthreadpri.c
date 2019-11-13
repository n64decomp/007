#include "ultra64.h"

#ifdef NONMATCHING
void osSetThreadPri(s32 arg0, s32 arg1, void *argA, s32 argB) {
    // Node 0
    if (argA == 0)
    {
        // Node 1
        argA = (void *) __osRunningThread;
    }
    // Node 2
    if (argA->unk4 != argB)
    {
        // Node 3
        argA->unk4 = argB;
        if (argA != __osRunningThread)
        {
            // Node 4
            if (argA->unk10 != 1)
            {
                // Node 5
                __osDequeueThread(argA->unk8, argA);
                __osEnqueueThread(argA->unk8, argA);
            }
        }
        // Node 6
        if (__osRunningThread->unk4 < __osRunQueue->unk4)
        {
            // Node 7
            __osRunningThread->unk10 = (u16)2;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }
    // Node 8
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: __osRestoreInt(__osDisableInt()))
}
#else
GLOBAL_ASM(
.text
glabel osSetThreadPri
/* 00E400 7000D800 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E404 7000D804 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E408 7000D808 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E40C 7000D80C AFA5002C */  sw    $a1, 0x2c($sp)
/* 00E410 7000D810 0C00617C */  jal   __osDisableInt
/* 00E414 7000D814 AFB00018 */   sw    $s0, 0x18($sp)
/* 00E418 7000D818 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E41C 7000D81C 00408025 */  move  $s0, $v0
/* 00E420 7000D820 15C00004 */  bnez  $t6, .L7000D834
/* 00E424 7000D824 00000000 */   nop   
/* 00E428 7000D828 3C0F8002 */  lui   $t7, %hi(__osRunningThread) 
/* 00E42C 7000D82C 8DEF7730 */  lw    $t7, %lo(__osRunningThread)($t7)
/* 00E430 7000D830 AFAF0028 */  sw    $t7, 0x28($sp)
.L7000D834:
/* 00E434 7000D834 8FB80028 */  lw    $t8, 0x28($sp)
/* 00E438 7000D838 8FA8002C */  lw    $t0, 0x2c($sp)
/* 00E43C 7000D83C 8F190004 */  lw    $t9, 4($t8)
/* 00E440 7000D840 13280020 */  beq   $t9, $t0, .L7000D8C4
/* 00E444 7000D844 00000000 */   nop   
/* 00E448 7000D848 AF080004 */  sw    $t0, 4($t8)
/* 00E44C 7000D84C 3C0A8002 */  lui   $t2, %hi(__osRunningThread) 
/* 00E450 7000D850 8D4A7730 */  lw    $t2, %lo(__osRunningThread)($t2)
/* 00E454 7000D854 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E458 7000D858 112A000C */  beq   $t1, $t2, .L7000D88C
/* 00E45C 7000D85C 00000000 */   nop   
/* 00E460 7000D860 952B0010 */  lhu   $t3, 0x10($t1)
/* 00E464 7000D864 24010001 */  li    $at, 1
/* 00E468 7000D868 11610008 */  beq   $t3, $at, .L7000D88C
/* 00E46C 7000D86C 00000000 */   nop   
/* 00E470 7000D870 8D240008 */  lw    $a0, 8($t1)
/* 00E474 7000D874 0C0042A4 */  jal   __osDequeueThread
/* 00E478 7000D878 01202825 */   move  $a1, $t1
/* 00E47C 7000D87C 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00E480 7000D880 8D840008 */  lw    $a0, 8($t4)
/* 00E484 7000D884 0C00422B */  jal   __osEnqueueThread
/* 00E488 7000D888 01802825 */   move  $a1, $t4
.L7000D88C:
/* 00E48C 7000D88C 3C0D8002 */  lui   $t5, %hi(__osRunningThread) 
/* 00E490 7000D890 3C0F8002 */  lui   $t7, %hi(__osRunQueue) 
/* 00E494 7000D894 8DEF7728 */  lw    $t7, %lo(__osRunQueue)($t7)
/* 00E498 7000D898 8DAD7730 */  lw    $t5, %lo(__osRunningThread)($t5)
/* 00E49C 7000D89C 8DF90004 */  lw    $t9, 4($t7)
/* 00E4A0 7000D8A0 8DAE0004 */  lw    $t6, 4($t5)
/* 00E4A4 7000D8A4 01D9082A */  slt   $at, $t6, $t9
/* 00E4A8 7000D8A8 10200006 */  beqz  $at, .L7000D8C4
/* 00E4AC 7000D8AC 00000000 */   nop   
/* 00E4B0 7000D8B0 24080002 */  li    $t0, 2
/* 00E4B4 7000D8B4 3C048002 */  lui   $a0, %hi(__osRunQueue) # $a0, 0x8002
/* 00E4B8 7000D8B8 A5A80010 */  sh    $t0, 0x10($t5)
/* 00E4BC 7000D8BC 0C0041EB */  jal   __osEnqueueAndYield
/* 00E4C0 7000D8C0 24847728 */   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
.L7000D8C4:
/* 00E4C4 7000D8C4 0C006184 */  jal   __osRestoreInt
/* 00E4C8 7000D8C8 02002025 */   move  $a0, $s0
/* 00E4CC 7000D8CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E4D0 7000D8D0 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E4D4 7000D8D4 27BD0028 */  addiu $sp, $sp, 0x28
/* 00E4D8 7000D8D8 03E00008 */  jr    $ra
/* 00E4DC 7000D8DC 00000000 */   nop   
)
#endif
