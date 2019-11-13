#include "ultra64.h"

#ifdef NONMATCHING
void osStopThread(OSThread *t){

}
#else
GLOBAL_ASM(
.text
glabel osStopThread
/* 00E340 7000D740 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00E344 7000D744 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00E348 7000D748 AFA40038 */  sw    $a0, 0x38($sp)
/* 00E34C 7000D74C AFB20020 */  sw    $s2, 0x20($sp)
/* 00E350 7000D750 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00E354 7000D754 0C00617C */  jal   __osDisableInt
/* 00E358 7000D758 AFB00018 */   sw    $s0, 0x18($sp)
/* 00E35C 7000D75C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 00E360 7000D760 00408025 */  move  $s0, $v0
/* 00E364 7000D764 15C00003 */  bnez  $t6, .L7000D774
/* 00E368 7000D768 00000000 */   nop   
/* 00E36C 7000D76C 10000003 */  b     .L7000D77C
/* 00E370 7000D770 24110004 */   li    $s1, 4
.L7000D774:
/* 00E374 7000D774 8FAF0038 */  lw    $t7, 0x38($sp)
/* 00E378 7000D778 95F10010 */  lhu   $s1, 0x10($t7)
.L7000D77C:
/* 00E37C 7000D77C 02209025 */  move  $s2, $s1
/* 00E380 7000D780 24010002 */  li    $at, 2
/* 00E384 7000D784 1241000F */  beq   $s2, $at, .L7000D7C4
/* 00E388 7000D788 24010004 */   li    $at, 4
/* 00E38C 7000D78C 12410005 */  beq   $s2, $at, .L7000D7A4
/* 00E390 7000D790 24010008 */   li    $at, 8
/* 00E394 7000D794 1241000B */  beq   $s2, $at, .L7000D7C4
/* 00E398 7000D798 00000000 */   nop   
/* 00E39C 7000D79C 10000010 */  b     .L7000D7E0
/* 00E3A0 7000D7A0 00000000 */   nop   
.L7000D7A4:
/* 00E3A4 7000D7A4 3C198002 */  lui   $t9, %hi(__osRunningThread) 
/* 00E3A8 7000D7A8 8F397730 */  lw    $t9, %lo(__osRunningThread)($t9)
/* 00E3AC 7000D7AC 24180001 */  li    $t8, 1
/* 00E3B0 7000D7B0 00002025 */  move  $a0, $zero
/* 00E3B4 7000D7B4 0C0041EB */  jal   __osEnqueueAndYield
/* 00E3B8 7000D7B8 A7380010 */   sh    $t8, 0x10($t9)
/* 00E3BC 7000D7BC 10000008 */  b     .L7000D7E0
/* 00E3C0 7000D7C0 00000000 */   nop   
.L7000D7C4:
/* 00E3C4 7000D7C4 8FA90038 */  lw    $t1, 0x38($sp)
/* 00E3C8 7000D7C8 24080001 */  li    $t0, 1
/* 00E3CC 7000D7CC A5280010 */  sh    $t0, 0x10($t1)
/* 00E3D0 7000D7D0 8FAA0038 */  lw    $t2, 0x38($sp)
/* 00E3D4 7000D7D4 8D440008 */  lw    $a0, 8($t2)
/* 00E3D8 7000D7D8 0C0042A4 */  jal   __osDequeueThread
/* 00E3DC 7000D7DC 01402825 */   move  $a1, $t2
.L7000D7E0:
/* 00E3E0 7000D7E0 0C006184 */  jal   __osRestoreInt
/* 00E3E4 7000D7E4 02002025 */   move  $a0, $s0
/* 00E3E8 7000D7E8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00E3EC 7000D7EC 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E3F0 7000D7F0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00E3F4 7000D7F4 8FB20020 */  lw    $s2, 0x20($sp)
/* 00E3F8 7000D7F8 03E00008 */  jr    $ra
/* 00E3FC 7000D7FC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif
