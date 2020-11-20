# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

.ifndef VERSION_EU
glabel osCreateViManager
/* 00E4F0 7000D8F0 3C0E8002 */  lui   $t6, %hi(__osViDevMgr) 
/* 00E4F4 7000D8F4 8DCE69A0 */  lw    $t6, %lo(__osViDevMgr)($t6)
/* 00E4F8 7000D8F8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00E4FC 7000D8FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E500 7000D900 15C00059 */  bnez  $t6, .L7000DA68
/* 00E504 7000D904 AFA40030 */   sw    $a0, 0x30($sp)
/* 00E508 7000D908 0C00618C */  jal   __osTimerServicesInit
/* 00E50C 7000D90C 00000000 */   nop   
/* 00E510 7000D910 3C048006 */  lui   $a0, %hi(viEventQueue)
/* 00E514 7000D914 3C058006 */  lui   $a1, %hi(viEventBuf)
/* 00E518 7000D918 24A569B8 */  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x69b8
/* 00E51C 7000D91C 248469A0 */  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x69a0
/* 00E520 7000D920 0C0035B4 */  jal   osCreateMesgQueue
/* 00E524 7000D924 24060005 */   li    $a2, 5
/* 00E528 7000D928 3C018006 */  lui   $at, %hi(viRetraceMsg+0x4)
/* 00E52C 7000D92C 240F000D */  li    $t7, 13
/* 00E530 7000D930 A42F69D0 */  sh    $t7, %lo(viRetraceMsg)($at)
/* 00E534 7000D934 A02069D2 */  sb    $zero, %lo(viRetraceMsg+0x2)($at)
/* 00E538 7000D938 AC2069D4 */  sw    $zero, %lo(viRetraceMsg+0x4)($at)
/* 00E53C 7000D93C 3C018006 */  lui   $at, %hi(viCounterMsg+0x4)
/* 00E540 7000D940 2418000E */  li    $t8, 14
/* 00E544 7000D944 3C058006 */  lui   $a1, %hi(viEventQueue)
/* 00E548 7000D948 3C068006 */  lui   $a2, %hi(viRetraceMsg)
/* 00E54C 7000D94C A43869E8 */  sh    $t8, %lo(viCounterMsg)($at)
/* 00E550 7000D950 A02069EA */  sb    $zero, %lo(viCounterMsg+0x2)($at)
/* 00E554 7000D954 AC2069EC */  sw    $zero, %lo(viCounterMsg+0x4)($at)
/* 00E558 7000D958 24C669D0 */  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x69d0
/* 00E55C 7000D95C 24A569A0 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x69a0
/* 00E560 7000D960 0C003714 */  jal   osSetEventMesg
/* 00E564 7000D964 24040007 */   li    $a0, 7
/* 00E568 7000D968 3C058006 */  lui   $a1, %hi(viEventQueue)
/* 00E56C 7000D96C 3C068006 */  lui   $a2, %hi(viCounterMsg)
/* 00E570 7000D970 24C669E8 */  addiu $a2, %lo(viCounterMsg) # addiu $a2, $a2, 0x69e8
/* 00E574 7000D974 24A569A0 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x69a0
/* 00E578 7000D978 0C003714 */  jal   osSetEventMesg
/* 00E57C 7000D97C 24040003 */   li    $a0, 3
/* 00E580 7000D980 2419FFFF */  li    $t9, -1
/* 00E584 7000D984 AFB90028 */  sw    $t9, 0x28($sp)
/* 00E588 7000D988 0C00628C */  jal   osGetThreadPri
/* 00E58C 7000D98C 00002025 */   move  $a0, $zero
/* 00E590 7000D990 AFA20024 */  sw    $v0, 0x24($sp)
/* 00E594 7000D994 8FA80024 */  lw    $t0, 0x24($sp)
/* 00E598 7000D998 8FA90030 */  lw    $t1, 0x30($sp)
/* 00E59C 7000D99C 0109082A */  slt   $at, $t0, $t1
/* 00E5A0 7000D9A0 10200005 */  beqz  $at, .L7000D9B8
/* 00E5A4 7000D9A4 00000000 */   nop   
/* 00E5A8 7000D9A8 AFA80028 */  sw    $t0, 0x28($sp)
/* 00E5AC 7000D9AC 00002025 */  move  $a0, $zero
/* 00E5B0 7000D9B0 0C003600 */  jal   osSetThreadPri
/* 00E5B4 7000D9B4 01202825 */   move  $a1, $t1
.L7000D9B8:
/* 00E5B8 7000D9B8 0C00617C */  jal   __osDisableInt
/* 00E5BC 7000D9BC 00000000 */   nop   
/* 00E5C0 7000D9C0 3C018002 */  lui   $at, %hi(D_800269AC)
/* 00E5C4 7000D9C4 3C0C8006 */  lui   $t4, %hi(viEventQueue) 
/* 00E5C8 7000D9C8 3C0B8006 */  lui   $t3, %hi(viThread) 
/* 00E5CC 7000D9CC 258C69A0 */  addiu $t4, %lo(viEventQueue) # addiu $t4, $t4, 0x69a0
/* 00E5D0 7000D9D0 240A0001 */  li    $t2, 1
/* 00E5D4 7000D9D4 256B57F0 */  addiu $t3, %lo(viThread) # addiu $t3, $t3, 0x57f0
/* 00E5D8 7000D9D8 AC2A69A0 */  sw    $t2, %lo(__osViDevMgr)($at)
/* 00E5DC 7000D9DC AC2B69A4 */  sw    $t3, %lo(D_800269A4)($at)
/* 00E5E0 7000D9E0 AC2C69A8 */  sw    $t4, %lo(D_800269A8)($at)
/* 00E5E4 7000D9E4 AC2C69AC */  sw    $t4, %lo(D_800269AC)($at)
/* 00E5E8 7000D9E8 3C0D8006 */  lui   $t5, %hi(viThreadStack) 
/* 00E5EC 7000D9EC 8FAF0030 */  lw    $t7, 0x30($sp)
/* 00E5F0 7000D9F0 3C018002 */  lui   $at, %hi(D_800269B8)
/* 00E5F4 7000D9F4 25AD59A0 */  addiu $t5, %lo(viThreadStack) # addiu $t5, $t5, 0x59a0
/* 00E5F8 7000D9F8 25AE1000 */  addiu $t6, $t5, 0x1000
/* 00E5FC 7000D9FC 3C067001 */  lui   $a2, %hi(viMgrMain) # $a2, 0x7001
/* 00E600 7000DA00 3C078002 */  lui   $a3, %hi(__osViDevMgr)
/* 00E604 7000DA04 AFA2002C */  sw    $v0, 0x2c($sp)
/* 00E608 7000DA08 AC2069B0 */  sw    $zero, %lo(D_800269B0)($at)
/* 00E60C 7000DA0C AC2069B4 */  sw    $zero, %lo(D_800269B4)($at)
/* 00E610 7000DA10 AC2069B8 */  sw    $zero, %lo(D_800269B8)($at)
/* 00E614 7000DA14 24E769A0 */  addiu $a3, %lo(__osViDevMgr) # addiu $a3, $a3, 0x69a0
/* 00E618 7000DA18 24C6DA78 */  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, -0x2588
/* 00E61C 7000DA1C AFAE0010 */  sw    $t6, 0x10($sp)
/* 00E620 7000DA20 01602025 */  move  $a0, $t3
/* 00E624 7000DA24 00002825 */  move  $a1, $zero
/* 00E628 7000DA28 0C00350C */  jal   osCreateThread
/* 00E62C 7000DA2C AFAF0014 */   sw    $t7, 0x14($sp)
/* 00E630 7000DA30 0C006294 */  jal   __osViInit
/* 00E634 7000DA34 00000000 */   nop   
/* 00E638 7000DA38 3C048006 */  lui   $a0, %hi(viThread)
/* 00E63C 7000DA3C 0C003560 */  jal   osStartThread
/* 00E640 7000DA40 248457F0 */   addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x57f0
/* 00E644 7000DA44 0C006184 */  jal   __osRestoreInt
/* 00E648 7000DA48 8FA4002C */   lw    $a0, 0x2c($sp)
/* 00E64C 7000DA4C 8FB80028 */  lw    $t8, 0x28($sp)
/* 00E650 7000DA50 2401FFFF */  li    $at, -1
/* 00E654 7000DA54 13010004 */  beq   $t8, $at, .L7000DA68
/* 00E658 7000DA58 00000000 */   nop   
/* 00E65C 7000DA5C 00002025 */  move  $a0, $zero
/* 00E660 7000DA60 0C003600 */  jal   osSetThreadPri
/* 00E664 7000DA64 03002825 */   move  $a1, $t8
.L7000DA68:
/* 00E668 7000DA68 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E66C 7000DA6C 27BD0030 */  addiu $sp, $sp, 0x30
/* 00E670 7000DA70 03E00008 */  jr    $ra
/* 00E674 7000DA74 00000000 */   nop   
.endif
.ifdef VERSION_EU
glabel osCreateViManager
/* 0023E0 700017E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0023E4 700017E4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0023E8 700017E8 3C108002 */  lui   $s0, %hi(__osViDevMgr) # $s0, 0x8002
/* 0023EC 700017EC 26100F90 */  addiu $s0, %lo(__osViDevMgr) # addiu $s0, $s0, 0xf90
/* 0023F0 700017F0 8E0E0000 */  lw    $t6, ($s0)
/* 0023F4 700017F4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0023F8 700017F8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0023FC 700017FC 55C00052 */  bnezl $t6, .L70001948
/* 002400 70001800 8FBF0024 */   lw    $ra, 0x24($sp)
/* 002404 70001804 0C0034A0 */  jal   __osTimerServicesInit
/* 002408 70001808 00000000 */   nop   
/* 00240C 7000180C 3C048005 */  lui   $a0, %hi(viEventQueue) # $a0, 0x8005
/* 002410 70001810 3C058005 */  lui   $a1, %hi(viEventBuf) # $a1, 0x8005
/* 002414 70001814 24A52278 */  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x2278
/* 002418 70001818 24842260 */  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x2260
/* 00241C 7000181C 0C00310C */  jal   osCreateMesgQueue
/* 002420 70001820 24060005 */   li    $a2, 5
/* 002424 70001824 3C068005 */  lui   $a2, %hi(viRetraceMsg) # $a2, 0x8005
/* 002428 70001828 3C078005 */  lui   $a3, %hi(viCounterMsg) # $a3, 0x8005
/* 00242C 7000182C 24E722A8 */  addiu $a3, %lo(viCounterMsg) # addiu $a3, $a3, 0x22a8
/* 002430 70001830 24C62290 */  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x2290
/* 002434 70001834 240F000D */  li    $t7, 13
/* 002438 70001838 2418000E */  li    $t8, 14
/* 00243C 7000183C 3C058005 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
/* 002440 70001840 A4CF0000 */  sh    $t7, ($a2)
/* 002444 70001844 A0C00002 */  sb    $zero, 2($a2)
/* 002448 70001848 ACC00004 */  sw    $zero, 4($a2)
/* 00244C 7000184C A4F80000 */  sh    $t8, ($a3)
/* 002450 70001850 A0E00002 */  sb    $zero, 2($a3)
/* 002454 70001854 ACE00004 */  sw    $zero, 4($a3)
/* 002458 70001858 24A52260 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
/* 00245C 7000185C 0C003194 */  jal   osSetEventMesg
/* 002460 70001860 24040007 */   li    $a0, 7
/* 002464 70001864 3C078005 */  lui   $a3, %hi(viCounterMsg)
/* 002468 70001868 3C058005 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
/* 00246C 7000186C 24E622A8 */  addiu $a2, $a3, %lo(viCounterMsg)
/* 002470 70001870 24A52260 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
/* 002474 70001874 0C003194 */  jal   osSetEventMesg
/* 002478 70001878 24040003 */   li    $a0, 3
/* 00247C 7000187C 2419FFFF */  li    $t9, -1
/* 002480 70001880 AFB90028 */  sw    $t9, 0x28($sp)
/* 002484 70001884 0C0035A0 */  jal   osGetThreadPri
/* 002488 70001888 00002025 */   move  $a0, $zero
/* 00248C 7000188C 8FA80030 */  lw    $t0, 0x30($sp)
/* 002490 70001890 00002025 */  move  $a0, $zero
/* 002494 70001894 0048082A */  slt   $at, $v0, $t0
/* 002498 70001898 10200003 */  beqz  $at, .L700018A8
/* 00249C 7000189C 01002825 */   move  $a1, $t0
/* 0024A0 700018A0 0C003158 */  jal   osSetThreadPri
/* 0024A4 700018A4 AFA20028 */   sw    $v0, 0x28($sp)
.L700018A8:
/* 0024A8 700018A8 0C0035A8 */  jal   __osDisableInt
/* 0024AC 700018AC 00000000 */   nop   
/* 0024B0 700018B0 8FAB0030 */  lw    $t3, 0x30($sp)
/* 0024B4 700018B4 3C038005 */  lui   $v1, %hi(viEventQueue) # $v1, 0x8005
/* 0024B8 700018B8 3C048005 */  lui   $a0, %hi(viThread) # $a0, 0x8005
/* 0024BC 700018BC 3C0A8005 */  lui   $t2, %hi(viEventQueue) # $t2, 0x8005
/* 0024C0 700018C0 24841FB0 */  addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
/* 0024C4 700018C4 24632260 */  addiu $v1, %lo(viEventQueue) # addiu $v1, $v1, 0x2260
/* 0024C8 700018C8 24090001 */  li    $t1, 1
/* 0024CC 700018CC 254A2260 */  addiu $t2, %lo(viEventQueue) # addiu $t2, $t2, 0x2260
/* 0024D0 700018D0 3C067000 */  lui   $a2, %hi(viMgrMain) # $a2, 0x7000
/* 0024D4 700018D4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0024D8 700018D8 AE090000 */  sw    $t1, ($s0)
/* 0024DC 700018DC AE040004 */  sw    $a0, 4($s0)
/* 0024E0 700018E0 AE030008 */  sw    $v1, 8($s0)
/* 0024E4 700018E4 AE03000C */  sw    $v1, 0xc($s0)
/* 0024E8 700018E8 AE000010 */  sw    $zero, 0x10($s0)
/* 0024EC 700018EC AE000014 */  sw    $zero, 0x14($s0)
/* 0024F0 700018F0 AE000018 */  sw    $zero, 0x18($s0)
/* 0024F4 700018F4 24C61958 */  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, 0x1958
/* 0024F8 700018F8 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0024FC 700018FC 00002825 */  move  $a1, $zero
/* 002500 70001900 02003825 */  move  $a3, $s0
/* 002504 70001904 0C003064 */  jal   osCreateThread
/* 002508 70001908 AFAB0014 */   sw    $t3, 0x14($sp)
/* 00250C 7000190C 0C0035B8 */  jal   __osViInit
/* 002510 70001910 00000000 */   nop   
/* 002514 70001914 3C048005 */  lui   $a0, %hi(viThread) # $a0, 0x8005
/* 002518 70001918 0C0030B8 */  jal   osStartThread
/* 00251C 7000191C 24841FB0 */   addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
/* 002520 70001920 0C0035B0 */  jal   __osRestoreInt
/* 002524 70001924 8FA4002C */   lw    $a0, 0x2c($sp)
/* 002528 70001928 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00252C 7000192C 2401FFFF */  li    $at, -1
/* 002530 70001930 00002025 */  move  $a0, $zero
/* 002534 70001934 51810004 */  beql  $t4, $at, .L70001948
/* 002538 70001938 8FBF0024 */   lw    $ra, 0x24($sp)
/* 00253C 7000193C 0C003158 */  jal   osSetThreadPri
/* 002540 70001940 01802825 */   move  $a1, $t4
/* 002544 70001944 8FBF0024 */  lw    $ra, 0x24($sp)
.L70001948:
/* 002548 70001948 8FB00020 */  lw    $s0, 0x20($sp)
/* 00254C 7000194C 27BD0030 */  addiu $sp, $sp, 0x30
/* 002550 70001950 03E00008 */  jr    $ra
/* 002554 70001954 00000000 */   nop   
.endif

.ifndef VERSION_EU
glabel viMgrMain
/* 00E678 7000DA78 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00E67C 7000DA7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E680 7000DA80 AFA40038 */  sw    $a0, 0x38($sp)
/* 00E684 7000DA84 AFB00018 */  sw    $s0, 0x18($sp)
/* 00E688 7000DA88 AFA0002C */  sw    $zero, 0x2c($sp)
/* 00E68C 7000DA8C 0C0062D8 */  jal   __osViGetCurrentContext
/* 00E690 7000DA90 AFA00028 */   sw    $zero, 0x28($sp)
/* 00E694 7000DA94 AFA20034 */  sw    $v0, 0x34($sp)
/* 00E698 7000DA98 8FAE0034 */  lw    $t6, 0x34($sp)
/* 00E69C 7000DA9C 3C018006 */  lui   $at, %hi(retrace)
/* 00E6A0 7000DAA0 95CF0002 */  lhu   $t7, 2($t6)
/* 00E6A4 7000DAA4 15E00004 */  bnez  $t7, .L7000DAB8
/* 00E6A8 7000DAA8 A42F6A00 */   sh    $t7, %lo(retrace)($at)
/* 00E6AC 7000DAAC 24180001 */  li    $t8, 1
/* 00E6B0 7000DAB0 3C018006 */  lui   $at, %hi(retrace)
/* 00E6B4 7000DAB4 A4386A00 */  sh    $t8, %lo(retrace)($at)
.L7000DAB8:
/* 00E6B8 7000DAB8 8FB90038 */  lw    $t9, 0x38($sp)
/* 00E6BC 7000DABC AFB90030 */  sw    $t9, 0x30($sp)
.L7000DAC0:
/* 00E6C0 7000DAC0 8FA80030 */  lw    $t0, 0x30($sp)
/* 00E6C4 7000DAC4 27A5002C */  addiu $a1, $sp, 0x2c
/* 00E6C8 7000DAC8 24060001 */  li    $a2, 1
/* 00E6CC 7000DACC 0C003774 */  jal   osRecvMesg
/* 00E6D0 7000DAD0 8D04000C */   lw    $a0, 0xc($t0)
/* 00E6D4 7000DAD4 8FA9002C */  lw    $t1, 0x2c($sp)
/* 00E6D8 7000DAD8 2401000D */  li    $at, 13
/* 00E6DC 7000DADC 95300000 */  lhu   $s0, ($t1)
/* 00E6E0 7000DAE0 12010005 */  beq   $s0, $at, .L7000DAF8
/* 00E6E4 7000DAE4 2401000E */   li    $at, 14
/* 00E6E8 7000DAE8 12010047 */  beq   $s0, $at, .L7000DC08
/* 00E6EC 7000DAEC 00000000 */   nop   
/* 00E6F0 7000DAF0 1000FFF3 */  b     .L7000DAC0
/* 00E6F4 7000DAF4 00000000 */   nop   
.L7000DAF8:
/* 00E6F8 7000DAF8 0C0062DC */  jal   __osViSwapContext
/* 00E6FC 7000DAFC 00000000 */   nop   
/* 00E700 7000DB00 3C0A8006 */  lui   $t2, %hi(retrace) 
/* 00E704 7000DB04 954A6A00 */  lhu   $t2, %lo(retrace)($t2)
/* 00E708 7000DB08 3C018006 */  lui   $at, %hi(retrace)
/* 00E70C 7000DB0C 254BFFFF */  addiu $t3, $t2, -1
/* 00E710 7000DB10 316CFFFF */  andi  $t4, $t3, 0xffff
/* 00E714 7000DB14 15800010 */  bnez  $t4, .L7000DB58
/* 00E718 7000DB18 A42B6A00 */   sh    $t3, %lo(retrace)($at)
/* 00E71C 7000DB1C 0C0062D8 */  jal   __osViGetCurrentContext
/* 00E720 7000DB20 00000000 */   nop   
/* 00E724 7000DB24 AFA20034 */  sw    $v0, 0x34($sp)
/* 00E728 7000DB28 8FAD0034 */  lw    $t5, 0x34($sp)
/* 00E72C 7000DB2C 8DAE0010 */  lw    $t6, 0x10($t5)
/* 00E730 7000DB30 11C00005 */  beqz  $t6, .L7000DB48
/* 00E734 7000DB34 00000000 */   nop   
/* 00E738 7000DB38 01C02025 */  move  $a0, $t6
/* 00E73C 7000DB3C 8DA50014 */  lw    $a1, 0x14($t5)
/* 00E740 7000DB40 0C0037C4 */  jal   osSendMesg
/* 00E744 7000DB44 00003025 */   move  $a2, $zero
.L7000DB48:
/* 00E748 7000DB48 8FAF0034 */  lw    $t7, 0x34($sp)
/* 00E74C 7000DB4C 3C018006 */  lui   $at, %hi(retrace)
/* 00E750 7000DB50 95F80002 */  lhu   $t8, 2($t7)
/* 00E754 7000DB54 A4386A00 */  sh    $t8, %lo(retrace)($at)
.L7000DB58:
/* 00E758 7000DB58 3C198007 */  lui   $t9, %hi(__osViIntrCount) 
/* 00E75C 7000DB5C 8F398E1C */  lw    $t9, %lo(__osViIntrCount)($t9)
/* 00E760 7000DB60 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E764 7000DB64 3C018007 */  lui   $at, %hi(__osViIntrCount)
/* 00E768 7000DB68 27280001 */  addiu $t0, $t9, 1
/* 00E76C 7000DB6C 1120000C */  beqz  $t1, .L7000DBA0
/* 00E770 7000DB70 AC288E1C */   sw    $t0, %lo(__osViIntrCount)($at)
/* 00E774 7000DB74 0C003638 */  jal   osGetCount
/* 00E778 7000DB78 00000000 */   nop   
/* 00E77C 7000DB7C AFA20024 */  sw    $v0, 0x24($sp)
/* 00E780 7000DB80 8FAA0024 */  lw    $t2, 0x24($sp)
/* 00E784 7000DB84 240C0000 */  li    $t4, 0
/* 00E788 7000DB88 3C018007 */  lui   $at, %hi(__osCurrentTime)
/* 00E78C 7000DB8C AC2C8E10 */  sw    $t4, %lo(__osCurrentTime)($at)
/* 00E790 7000DB90 3C018007 */  lui   $at, %hi(__osCurrentTime+4)
/* 00E794 7000DB94 01406825 */  move  $t5, $t2
/* 00E798 7000DB98 AC2D8E14 */  sw    $t5, %lo(__osCurrentTime+4)($at)
/* 00E79C 7000DB9C AFA00028 */  sw    $zero, 0x28($sp)
.L7000DBA0:
/* 00E7A0 7000DBA0 3C0B8007 */  lui   $t3, %hi(__osBaseCounter) 
/* 00E7A4 7000DBA4 8D6B8E18 */  lw    $t3, %lo(__osBaseCounter)($t3)
/* 00E7A8 7000DBA8 0C003638 */  jal   osGetCount
/* 00E7AC 7000DBAC AFAB0024 */   sw    $t3, 0x24($sp)
/* 00E7B0 7000DBB0 3C018007 */  lui   $at, %hi(__osBaseCounter)
/* 00E7B4 7000DBB4 AC228E18 */  sw    $v0, %lo(__osBaseCounter)($at)
/* 00E7B8 7000DBB8 3C0E8007 */  lui   $t6, %hi(__osBaseCounter) 
/* 00E7BC 7000DBBC 8DCE8E18 */  lw    $t6, %lo(__osBaseCounter)($t6)
/* 00E7C0 7000DBC0 8FAF0024 */  lw    $t7, 0x24($sp)
/* 00E7C4 7000DBC4 3C0B8007 */  lui   $t3, %hi(__osCurrentTime+4) 
/* 00E7C8 7000DBC8 8D6B8E14 */  lw    $t3, %lo(__osCurrentTime+4)($t3)
/* 00E7CC 7000DBCC 01CFC023 */  subu  $t8, $t6, $t7
/* 00E7D0 7000DBD0 03004825 */  move  $t1, $t8
/* 00E7D4 7000DBD4 3C0A8007 */  lui   $t2, %hi(__osCurrentTime) 
/* 00E7D8 7000DBD8 012B6821 */  addu  $t5, $t1, $t3
/* 00E7DC 7000DBDC 8D4A8E10 */  lw    $t2, %lo(__osCurrentTime)($t2)
/* 00E7E0 7000DBE0 24080000 */  li    $t0, 0
/* 00E7E4 7000DBE4 01AB082B */  sltu  $at, $t5, $t3
/* 00E7E8 7000DBE8 00286021 */  addu  $t4, $at, $t0
/* 00E7EC 7000DBEC 3C018007 */  lui   $at, %hi(__osCurrentTime)
/* 00E7F0 7000DBF0 018A6021 */  addu  $t4, $t4, $t2
/* 00E7F4 7000DBF4 AC2C8E10 */  sw    $t4, %lo(__osCurrentTime)($at)
/* 00E7F8 7000DBF8 3C018007 */  lui   $at, %hi(__osCurrentTime+4)
/* 00E7FC 7000DBFC AFB80024 */  sw    $t8, 0x24($sp)
/* 00E800 7000DC00 1000FFAF */  b     .L7000DAC0
/* 00E804 7000DC04 AC2D8E14 */   sw    $t5, %lo(__osCurrentTime+4)($at)
.L7000DC08:
/* 00E808 7000DC08 0C0061AF */  jal   __osTimerInterrupt
/* 00E80C 7000DC0C 00000000 */   nop   
/* 00E810 7000DC10 1000FFAB */  b     .L7000DAC0
/* 00E814 7000DC14 00000000 */   nop   
/* 00E818 7000DC18 00000000 */  nop   
/* 00E81C 7000DC1C 00000000 */  nop   
/* 00E820 7000DC20 00000000 */  nop   
/* 00E824 7000DC24 00000000 */  nop   
/* 00E828 7000DC28 00000000 */  nop   
/* 00E82C 7000DC2C 00000000 */  nop   
/* 00E830 7000DC30 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E834 7000DC34 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E838 7000DC38 27BD0038 */  addiu $sp, $sp, 0x38
/* 00E83C 7000DC3C 03E00008 */  jr    $ra
/* 00E840 7000DC40 00000000 */   nop   
.endif
.ifdef VERSION_EU
glabel viMgrMain
/* 002558 70001958 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00255C 7000195C AFBF0034 */  sw    $ra, 0x34($sp)
/* 002560 70001960 AFB70030 */  sw    $s7, 0x30($sp)
/* 002564 70001964 0080B825 */  move  $s7, $a0
/* 002568 70001968 AFB6002C */  sw    $s6, 0x2c($sp)
/* 00256C 7000196C AFB50028 */  sw    $s5, 0x28($sp)
/* 002570 70001970 AFB40024 */  sw    $s4, 0x24($sp)
/* 002574 70001974 AFB30020 */  sw    $s3, 0x20($sp)
/* 002578 70001978 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00257C 7000197C AFB10018 */  sw    $s1, 0x18($sp)
/* 002580 70001980 AFB00014 */  sw    $s0, 0x14($sp)
/* 002584 70001984 0C0035FC */  jal   __osViGetCurrentContext
/* 002588 70001988 AFA00044 */   sw    $zero, 0x44($sp)
/* 00258C 7000198C 94430002 */  lhu   $v1, 2($v0)
/* 002590 70001990 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002594 70001994 2416000E */  li    $s6, 14
/* 002598 70001998 14600004 */  bnez  $v1, .L700019AC
/* 00259C 7000199C A42322C0 */   sh    $v1, %lo(retrace)($at)
/* 0025A0 700019A0 24030001 */  li    $v1, 1
/* 0025A4 700019A4 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 0025A8 700019A8 A42322C0 */  sh    $v1, %lo(retrace)($at)
.L700019AC:
/* 0025AC 700019AC 3C138005 */  lui   $s3, %hi(__osViIntrCount) # $s3, 0x8005
/* 0025B0 700019B0 3C128005 */  lui   $s2, %hi(__osBaseCounter) # $s2, 0x8005
/* 0025B4 700019B4 3C118005 */  lui   $s1, %hi(__osCurrentTime) # $s1, 0x8005
/* 0025B8 700019B8 26317C80 */  addiu $s1, %lo(__osCurrentTime) # addiu $s1, $s1, 0x7c80
/* 0025BC 700019BC 26527C88 */  addiu $s2, %lo(__osBaseCounter) # addiu $s2, $s2, 0x7c88
/* 0025C0 700019C0 26737C8C */  addiu $s3, %lo(__osViIntrCount) # addiu $s3, $s3, 0x7c8c
/* 0025C4 700019C4 2415000D */  li    $s5, 13
/* 0025C8 700019C8 27B40044 */  addiu $s4, $sp, 0x44
.L700019CC:
/* 0025CC 700019CC 8EE4000C */  lw    $a0, 0xc($s7)
.L700019D0:
/* 0025D0 700019D0 02802825 */  move  $a1, $s4
/* 0025D4 700019D4 0C0031F4 */  jal   osRecvMesg
/* 0025D8 700019D8 24060001 */   li    $a2, 1
/* 0025DC 700019DC 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0025E0 700019E0 95C30000 */  lhu   $v1, ($t6)
/* 0025E4 700019E4 10750005 */  beq   $v1, $s5, .L700019FC
/* 0025E8 700019E8 00000000 */   nop   
/* 0025EC 700019EC 1076002A */  beq   $v1, $s6, .L70001A98
/* 0025F0 700019F0 00000000 */   nop   
/* 0025F4 700019F4 1000FFF6 */  b     .L700019D0
/* 0025F8 700019F8 8EE4000C */   lw    $a0, 0xc($s7)
.L700019FC:
/* 0025FC 700019FC 0C003600 */  jal   __osViSwapContext
/* 002600 70001A00 00000000 */   nop   
/* 002604 70001A04 3C038005 */  lui   $v1, %hi(retrace) # $v1, 0x8005
/* 002608 70001A08 946322C0 */  lhu   $v1, %lo(retrace)($v1)
/* 00260C 70001A0C 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002610 70001A10 2463FFFF */  addiu $v1, $v1, -1
/* 002614 70001A14 306FFFFF */  andi  $t7, $v1, 0xffff
/* 002618 70001A18 15E0000E */  bnez  $t7, .L70001A54
/* 00261C 70001A1C A42F22C0 */   sh    $t7, %lo(retrace)($at)
/* 002620 70001A20 0C0035FC */  jal   __osViGetCurrentContext
/* 002624 70001A24 00000000 */   nop   
/* 002628 70001A28 8C580010 */  lw    $t8, 0x10($v0)
/* 00262C 70001A2C 00408025 */  move  $s0, $v0
/* 002630 70001A30 00003025 */  move  $a2, $zero
/* 002634 70001A34 53000005 */  beql  $t8, $zero, .L70001A4C
/* 002638 70001A38 96030002 */   lhu   $v1, 2($s0)
/* 00263C 70001A3C 8C440010 */  lw    $a0, 0x10($v0)
/* 002640 70001A40 0C003244 */  jal   osSendMesg
/* 002644 70001A44 8C450014 */   lw    $a1, 0x14($v0)
/* 002648 70001A48 96030002 */  lhu   $v1, 2($s0)
.L70001A4C:
/* 00264C 70001A4C 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002650 70001A50 A42322C0 */  sh    $v1, %lo(retrace)($at)
.L70001A54:
/* 002654 70001A54 8E790000 */  lw    $t9, ($s3)
/* 002658 70001A58 8E500000 */  lw    $s0, ($s2)
/* 00265C 70001A5C 27280001 */  addiu $t0, $t9, 1
/* 002660 70001A60 0C003190 */  jal   osGetCount
/* 002664 70001A64 AE680000 */   sw    $t0, ($s3)
/* 002668 70001A68 8E2D0004 */  lw    $t5, 4($s1)
/* 00266C 70001A6C 00508023 */  subu  $s0, $v0, $s0
/* 002670 70001A70 8E2C0000 */  lw    $t4, ($s1)
/* 002674 70001A74 020D7821 */  addu  $t7, $s0, $t5
/* 002678 70001A78 240A0000 */  li    $t2, 0
/* 00267C 70001A7C 01ED082B */  sltu  $at, $t7, $t5
/* 002680 70001A80 002A7021 */  addu  $t6, $at, $t2
/* 002684 70001A84 01CC7021 */  addu  $t6, $t6, $t4
/* 002688 70001A88 AE420000 */  sw    $v0, ($s2)
/* 00268C 70001A8C AE2E0000 */  sw    $t6, ($s1)
/* 002690 70001A90 1000FFCE */  b     .L700019CC
/* 002694 70001A94 AE2F0004 */   sw    $t7, 4($s1)
.L70001A98:
/* 002698 70001A98 0C0034C3 */  jal   __osTimerInterrupt
/* 00269C 70001A9C 00000000 */   nop   
/* 0026A0 70001AA0 1000FFCB */  b     .L700019D0
/* 0026A4 70001AA4 8EE4000C */   lw    $a0, 0xc($s7)
/* 0026A8 70001AA8 00000000 */  nop   
/* 0026AC 70001AAC 00000000 */  nop   
/* 0026B0 70001AB0 00000000 */  nop   
/* 0026B4 70001AB4 00000000 */  nop   
/* 0026B8 70001AB8 00000000 */  nop   
/* 0026BC 70001ABC 00000000 */  nop   
/* 0026C0 70001AC0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0026C4 70001AC4 8FB00014 */  lw    $s0, 0x14($sp)
/* 0026C8 70001AC8 8FB10018 */  lw    $s1, 0x18($sp)
/* 0026CC 70001ACC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0026D0 70001AD0 8FB30020 */  lw    $s3, 0x20($sp)
/* 0026D4 70001AD4 8FB40024 */  lw    $s4, 0x24($sp)
/* 0026D8 70001AD8 8FB50028 */  lw    $s5, 0x28($sp)
/* 0026DC 70001ADC 8FB6002C */  lw    $s6, 0x2c($sp)
/* 0026E0 70001AE0 8FB70030 */  lw    $s7, 0x30($sp)
/* 0026E4 70001AE4 03E00008 */  jr    $ra
/* 0026E8 70001AE8 27BD0050 */   addiu $sp, $sp, 0x50
.endif

.section .data
glabel __osViDevMgr
.word 0
glabel D_800269A4
.word 0
glabel D_800269A8
.word 0
glabel D_800269AC
.word 0
glabel D_800269B0
.word 0
glabel D_800269B4
.word 0
glabel D_800269B8
.word 0




.section .rodata


.section .bss
glabel viThread
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0

glabel viThreadStack
        #[4096]
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.section .bss
glabel viEventQueue
.word 0, 0, 0, 0, 0, 0

glabel viEventBuf
.word 0, 0, 0, 0, 0, 0

glabel viRetraceMsg
.word 0, 0, 0, 0, 0, 0

glabel viCounterMsg
.word 0, 0, 0, 0, 0, 0

glabel retrace
.half 0

