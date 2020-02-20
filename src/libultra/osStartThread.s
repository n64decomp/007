# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osStartThread
/* 00E180 7000D580 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E184 7000D584 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E188 7000D588 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E18C 7000D58C AFB10018 */  sw    $s1, 0x18($sp)
/* 00E190 7000D590 0C00617C */  jal   __osDisableInt
/* 00E194 7000D594 AFB00014 */   sw    $s0, 0x14($sp)
/* 00E198 7000D598 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E19C 7000D59C 24010001 */  li    $at, 1
/* 00E1A0 7000D5A0 00408025 */  move  $s0, $v0
/* 00E1A4 7000D5A4 95D10010 */  lhu   $s1, 0x10($t6)
/* 00E1A8 7000D5A8 1221000C */  beq   $s1, $at, .L7000D5DC
/* 00E1AC 7000D5AC 24010008 */   li    $at, 8
/* 00E1B0 7000D5B0 1621002A */  bne   $s1, $at, .L7000D65C
/* 00E1B4 7000D5B4 00000000 */   nop   
/* 00E1B8 7000D5B8 8FB80028 */  lw    $t8, 0x28($sp)
/* 00E1BC 7000D5BC 240F0002 */  li    $t7, 2
/* 00E1C0 7000D5C0 3C048002 */  lui   $a0, %hi(__osRunQueue)
/* 00E1C4 7000D5C4 A70F0010 */  sh    $t7, 0x10($t8)
/* 00E1C8 7000D5C8 8FA50028 */  lw    $a1, 0x28($sp)
/* 00E1CC 7000D5CC 0C00422B */  jal   __osEnqueueThread
/* 00E1D0 7000D5D0 24847728 */   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
/* 00E1D4 7000D5D4 10000021 */  b     .L7000D65C
/* 00E1D8 7000D5D8 00000000 */   nop   
.L7000D5DC:
/* 00E1DC 7000D5DC 8FB90028 */  lw    $t9, 0x28($sp)
/* 00E1E0 7000D5E0 8F280008 */  lw    $t0, 8($t9)
/* 00E1E4 7000D5E4 11000005 */  beqz  $t0, .L7000D5FC
/* 00E1E8 7000D5E8 00000000 */   nop   
/* 00E1EC 7000D5EC 3C098002 */  lui   $t1, %hi(__osRunQueue) 
/* 00E1F0 7000D5F0 25297728 */  addiu $t1, %lo(__osRunQueue) # addiu $t1, $t1, 0x7728
/* 00E1F4 7000D5F4 1509000A */  bne   $t0, $t1, .L7000D620
/* 00E1F8 7000D5F8 00000000 */   nop   
.L7000D5FC:
/* 00E1FC 7000D5FC 8FAB0028 */  lw    $t3, 0x28($sp)
/* 00E200 7000D600 240A0002 */  li    $t2, 2
/* 00E204 7000D604 3C048002 */  lui   $a0, %hi(__osRunQueue)
/* 00E208 7000D608 A56A0010 */  sh    $t2, 0x10($t3)
/* 00E20C 7000D60C 8FA50028 */  lw    $a1, 0x28($sp)
/* 00E210 7000D610 0C00422B */  jal   __osEnqueueThread
/* 00E214 7000D614 24847728 */   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
/* 00E218 7000D618 10000010 */  b     .L7000D65C
/* 00E21C 7000D61C 00000000 */   nop   
.L7000D620:
/* 00E220 7000D620 8FAD0028 */  lw    $t5, 0x28($sp)
/* 00E224 7000D624 240C0008 */  li    $t4, 8
/* 00E228 7000D628 A5AC0010 */  sh    $t4, 0x10($t5)
/* 00E22C 7000D62C 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E230 7000D630 8DC40008 */  lw    $a0, 8($t6)
/* 00E234 7000D634 0C00422B */  jal   __osEnqueueThread
/* 00E238 7000D638 01C02825 */   move  $a1, $t6
/* 00E23C 7000D63C 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00E240 7000D640 0C00423D */  jal   __osPopThread
/* 00E244 7000D644 8DE40008 */   lw    $a0, 8($t7)
/* 00E248 7000D648 00408825 */  move  $s1, $v0
/* 00E24C 7000D64C 3C048002 */  lui   $a0, %hi(__osRunQueue)
/* 00E250 7000D650 24847728 */  addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
/* 00E254 7000D654 0C00422B */  jal   __osEnqueueThread
/* 00E258 7000D658 02202825 */   move  $a1, $s1
.L7000D65C:
/* 00E25C 7000D65C 3C188002 */  lui   $t8, %hi(__osRunningThread) 
/* 00E260 7000D660 8F187730 */  lw    $t8, %lo(__osRunningThread)($t8)
/* 00E264 7000D664 17000005 */  bnez  $t8, .L7000D67C
/* 00E268 7000D668 00000000 */   nop   
/* 00E26C 7000D66C 0C004241 */  jal   __osDispatchThread
/* 00E270 7000D670 00000000 */   nop   
/* 00E274 7000D674 1000000F */  b     .L7000D6B4
/* 00E278 7000D678 00000000 */   nop   
.L7000D67C:
/* 00E27C 7000D67C 3C198002 */  lui   $t9, %hi(__osRunningThread) 
/* 00E280 7000D680 3C098002 */  lui   $t1, %hi(__osRunQueue) 
/* 00E284 7000D684 8D297728 */  lw    $t1, %lo(__osRunQueue)($t1)
/* 00E288 7000D688 8F397730 */  lw    $t9, %lo(__osRunningThread)($t9)
/* 00E28C 7000D68C 8D2A0004 */  lw    $t2, 4($t1)
/* 00E290 7000D690 8F280004 */  lw    $t0, 4($t9)
/* 00E294 7000D694 010A082A */  slt   $at, $t0, $t2
/* 00E298 7000D698 10200006 */  beqz  $at, .L7000D6B4
/* 00E29C 7000D69C 00000000 */   nop   
/* 00E2A0 7000D6A0 240B0002 */  li    $t3, 2
/* 00E2A4 7000D6A4 3C048002 */  lui   $a0, %hi(__osRunQueue)
/* 00E2A8 7000D6A8 A72B0010 */  sh    $t3, 0x10($t9)
/* 00E2AC 7000D6AC 0C0041EB */  jal   __osEnqueueAndYield
/* 00E2B0 7000D6B0 24847728 */   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
.L7000D6B4:
/* 00E2B4 7000D6B4 0C006184 */  jal   __osRestoreInt
/* 00E2B8 7000D6B8 02002025 */   move  $a0, $s0
/* 00E2BC 7000D6BC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E2C0 7000D6C0 8FB00014 */  lw    $s0, 0x14($sp)
/* 00E2C4 7000D6C4 8FB10018 */  lw    $s1, 0x18($sp)
/* 00E2C8 7000D6C8 03E00008 */  jr    $ra
/* 00E2CC 7000D6CC 27BD0028 */   addiu $sp, $sp, 0x28
