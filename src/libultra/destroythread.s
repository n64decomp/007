# Goldeneye 007 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
.section .text
glabel osDestroyThread
/* 01C760 7001BB60 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 01C764 7001BB64 AFBF0024 */  sw    $ra, 0x24($sp)
/* 01C768 7001BB68 AFA40038 */  sw    $a0, 0x38($sp)
/* 01C76C 7001BB6C AFB20020 */  sw    $s2, 0x20($sp)
/* 01C770 7001BB70 AFB1001C */  sw    $s1, 0x1c($sp)
/* 01C774 7001BB74 0C00617C */  jal   __osDisableInt
/* 01C778 7001BB78 AFB00018 */   sw    $s0, 0x18($sp)
/* 01C77C 7001BB7C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 01C780 7001BB80 00408025 */  move  $s0, $v0
/* 01C784 7001BB84 15C00005 */  bnez  $t6, .L7001BB9C
/* 01C788 7001BB88 00000000 */   nop   
/* 01C78C 7001BB8C 3C0F8002 */  lui   $t7, %hi(__osRunningThread) 
/* 01C790 7001BB90 8DEF7730 */  lw    $t7, %lo(__osRunningThread)($t7)
/* 01C794 7001BB94 10000009 */  b     .L7001BBBC
/* 01C798 7001BB98 AFAF0038 */   sw    $t7, 0x38($sp)
.L7001BB9C:
/* 01C79C 7001BB9C 8FB80038 */  lw    $t8, 0x38($sp)
/* 01C7A0 7001BBA0 24010001 */  li    $at, 1
/* 01C7A4 7001BBA4 97190010 */  lhu   $t9, 0x10($t8)
/* 01C7A8 7001BBA8 13210004 */  beq   $t9, $at, .L7001BBBC
/* 01C7AC 7001BBAC 00000000 */   nop   
/* 01C7B0 7001BBB0 8F040008 */  lw    $a0, 8($t8)
/* 01C7B4 7001BBB4 0C0042A4 */  jal   __osDequeueThread
/* 01C7B8 7001BBB8 03002825 */   move  $a1, $t8
.L7001BBBC:
/* 01C7BC 7001BBBC 3C088002 */  lui   $t0, %hi(__osActiveQueue) 
/* 01C7C0 7001BBC0 8D08772C */  lw    $t0, %lo(__osActiveQueue)($t0)
/* 01C7C4 7001BBC4 8FA90038 */  lw    $t1, 0x38($sp)
/* 01C7C8 7001BBC8 15090005 */  bne   $t0, $t1, .L7001BBE0
/* 01C7CC 7001BBCC 00000000 */   nop   
/* 01C7D0 7001BBD0 8D0A000C */  lw    $t2, 0xc($t0)
/* 01C7D4 7001BBD4 3C018002 */  lui   $at, %hi(__osActiveQueue)
/* 01C7D8 7001BBD8 10000010 */  b     .L7001BC1C
/* 01C7DC 7001BBDC AC2A772C */   sw    $t2, %lo(__osActiveQueue)($at)
.L7001BBE0:
/* 01C7E0 7001BBE0 3C118002 */  lui   $s1, %hi(__osActiveQueue)
/* 01C7E4 7001BBE4 8E31772C */  lw    $s1, %lo(__osActiveQueue)($s1)
/* 01C7E8 7001BBE8 8E32000C */  lw    $s2, 0xc($s1)
/* 01C7EC 7001BBEC 1240000B */  beqz  $s2, .L7001BC1C
/* 01C7F0 7001BBF0 00000000 */   nop   
.L7001BBF4:
/* 01C7F4 7001BBF4 8FAB0038 */  lw    $t3, 0x38($sp)
/* 01C7F8 7001BBF8 164B0004 */  bne   $s2, $t3, .L7001BC0C
/* 01C7FC 7001BBFC 00000000 */   nop   
/* 01C800 7001BC00 8D6C000C */  lw    $t4, 0xc($t3)
/* 01C804 7001BC04 10000005 */  b     .L7001BC1C
/* 01C808 7001BC08 AE2C000C */   sw    $t4, 0xc($s1)
.L7001BC0C:
/* 01C80C 7001BC0C 02408825 */  move  $s1, $s2
/* 01C810 7001BC10 8E32000C */  lw    $s2, 0xc($s1)
/* 01C814 7001BC14 1640FFF7 */  bnez  $s2, .L7001BBF4
/* 01C818 7001BC18 00000000 */   nop   
.L7001BC1C:
/* 01C81C 7001BC1C 3C0E8002 */  lui   $t6, %hi(__osRunningThread) 
/* 01C820 7001BC20 8DCE7730 */  lw    $t6, %lo(__osRunningThread)($t6)
/* 01C824 7001BC24 8FAD0038 */  lw    $t5, 0x38($sp)
/* 01C828 7001BC28 15AE0003 */  bne   $t5, $t6, .L7001BC38
/* 01C82C 7001BC2C 00000000 */   nop   
/* 01C830 7001BC30 0C004241 */  jal   __osDispatchThread
/* 01C834 7001BC34 00000000 */   nop   
.L7001BC38:
/* 01C838 7001BC38 0C006184 */  jal   __osRestoreInt
/* 01C83C 7001BC3C 02002025 */   move  $a0, $s0
/* 01C840 7001BC40 8FBF0024 */  lw    $ra, 0x24($sp)
/* 01C844 7001BC44 8FB00018 */  lw    $s0, 0x18($sp)
/* 01C848 7001BC48 8FB1001C */  lw    $s1, 0x1c($sp)
/* 01C84C 7001BC4C 8FB20020 */  lw    $s2, 0x20($sp)
/* 01C850 7001BC50 03E00008 */  jr    $ra
/* 01C854 7001BC54 27BD0038 */   addiu $sp, $sp, 0x38

