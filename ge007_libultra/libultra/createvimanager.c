#include "ultra64.h"

//.section .data
osDevMgr __osViDevMgr = {0};

//.section .rodata

//.section .bss
osThread viThread;
char viThreadStack[0x1000];
OSMesgQueue viEventQueue;
char viEventBuf[0x18];
osIoMesg viRetraceMsg;
osIoMesg viCounterMsg;
u16 retrace;

#ifdef NONMATCHING
void osCreateViManager(s32 arg0, s32 argC) {
    s32 sp24;
    s32 sp28;
    s32 sp2C;

    // Node 0
    if (__osViDevMgr == 0)
    {
        // Node 1
        __osTimerServicesInit();
        osCreateMesgQueue(&viEventQueue, &viEventBuf, 5);
        viRetraceMsg = (u16)0xd;
        viRetraceMsg.unk2 = (u8)0;
        viRetraceMsg.unk4 = 0;
        viCounterMsg = (u16)0xe;
        viCounterMsg.unk2 = (u8)0;
        viCounterMsg.unk4 = 0;
        osSetEventMesg(7, &viEventQueue, &viRetraceMsg);
        osSetEventMesg(3, &viEventQueue, &viCounterMsg);
        sp28 = -1;
        sp24 = osGetThreadPri(0);
        if (sp24 < argC)
        {
            // Node 2
            sp28 = sp24;
            osSetThreadPri(0, argC);
        }
        // Node 3
        __osViDevMgr = 1;
        __osViDevMgr.unk4 = &viThread;
        __osViDevMgr.unk8 = &viEventQueue;
        __osViDevMgr.unkC = &viEventQueue;
        sp2C = __osDisableInt();
        __osViDevMgr.unk10 = 0;
        __osViDevMgr.unk14 = 0;
        __osViDevMgr.unk18 = 0;
        osCreateThread(&viThread, 0, &viMgrMain, &__osViDevMgr, (s32) (&viThreadStack + 0x1000), argC);
        __osViInit();
        osStartThread(&viThread);
        __osRestoreInt(sp2C);
        if (sp28 != -1)
        {
            // Node 4
            osSetThreadPri(0, sp28);
            return;
            // (possible return value: osSetThreadPri(0, sp28))
        }
    }
    // (function likely void)
}

#else
GLOBAL_ASM(
.text
glabel osCreateViManager
/* 00E4F0 7000D8F0 3C0E8002 */  lui   $t6, %hi(__osViDevMgr) 
/* 00E4F4 7000D8F4 8DCE69A0 */  lw    $t6, %lo(__osViDevMgr)($t6)
/* 00E4F8 7000D8F8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00E4FC 7000D8FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E500 7000D900 15C00059 */  bnez  $t6, .L7000DA68
/* 00E504 7000D904 AFA40030 */   sw    $a0, 0x30($sp)
/* 00E508 7000D908 0C00618C */  jal   __osTimerServicesInit
/* 00E50C 7000D90C 00000000 */   nop   
/* 00E510 7000D910 3C048006 */  lui   $a0, %hi(viEventQueue) # $a0, 0x8006
/* 00E514 7000D914 3C058006 */  lui   $a1, %hi(viEventBuf) # $a1, 0x8006
/* 00E518 7000D918 24A569B8 */  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x69b8
/* 00E51C 7000D91C 248469A0 */  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x69a0
/* 00E520 7000D920 0C0035B4 */  jal   osCreateMesgQueue
/* 00E524 7000D924 24060005 */   li    $a2, 5
/* 00E528 7000D928 3C018006 */  lui   $at, %hi(viRetraceMsg) # $at, 0x8006
/* 00E52C 7000D92C 240F000D */  li    $t7, 13
/* 00E530 7000D930 A42F69D0 */  sh    $t7, 0($at)
/* 00E534 7000D934 A02069D2 */  sb    $zero, 2($at)
/* 00E538 7000D938 AC2069D4 */  sw    $zero, 4($at)
/* 00E53C 7000D93C 3C018006 */  lui   $at, %hi(viCounterMsg) # $at, 0x8006
/* 00E540 7000D940 2418000E */  li    $t8, 14
/* 00E544 7000D944 3C058006 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8006
/* 00E548 7000D948 3C068006 */  lui   $a2, %hi(viRetraceMsg) # $a2, 0x8006
/* 00E54C 7000D94C A43869E8 */  sh    $t8, 0($at)
/* 00E550 7000D950 A02069EA */  sb    $zero, 2($at)
/* 00E554 7000D954 AC2069EC */  sw    $zero, 4($at)
/* 00E558 7000D958 24C669D0 */  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x69d0
/* 00E55C 7000D95C 24A569A0 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x69a0
/* 00E560 7000D960 0C003714 */  jal   osSetEventMesg
/* 00E564 7000D964 24040007 */   li    $a0, 7
/* 00E568 7000D968 3C058006 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8006
/* 00E56C 7000D96C 3C068006 */  lui   $a2, %hi(viCounterMsg) # $a2, 0x8006
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
/* 00E5C0 7000D9C0 3C018002 */  lui   $at, %hi(__osViDevMgr) # $at, 0x8002
/* 00E5C4 7000D9C4 3C0C8006 */  lui   $t4, %hi(viEventQueue) 
/* 00E5C8 7000D9C8 3C0B8006 */  lui   $t3, %hi(viThread) 
/* 00E5CC 7000D9CC 258C69A0 */  addiu $t4, %lo(viEventQueue) # addiu $t4, $t4, 0x69a0
/* 00E5D0 7000D9D0 240A0001 */  li    $t2, 1
/* 00E5D4 7000D9D4 256B57F0 */  addiu $t3, %lo(viThread) # addiu $t3, $t3, 0x57f0
/* 00E5D8 7000D9D8 AC2A69A0 */  sw    $t2, 0($at)
/* 00E5DC 7000D9DC AC2B69A4 */  sw    $t3, 4($at)
/* 00E5E0 7000D9E0 AC2C69A8 */  sw    $t4, 8($at)
/* 00E5E4 7000D9E4 AC2C69AC */  sw    $t4, 0xC($at)
/* 00E5E8 7000D9E8 3C0D8006 */  lui   $t5, %hi(viThreadStack) 
/* 00E5EC 7000D9EC 8FAF0030 */  lw    $t7, 0x30($sp)
/* 00E5F0 7000D9F0 3C018002 */  lui   $at, %hi(__osViDevMgr) # $at, 0x8002
/* 00E5F4 7000D9F4 25AD59A0 */  addiu $t5, %lo(viThreadStack) # addiu $t5, $t5, 0x59a0
/* 00E5F8 7000D9F8 25AE1000 */  addiu $t6, $t5, 0x1000
/* 00E5FC 7000D9FC 3C067001 */  lui   $a2, %hi(viMgrMain) # $a2, 0x7001
/* 00E600 7000DA00 3C078002 */  lui   $a3, %hi(__osViDevMgr) # $a3, 0x8002
/* 00E604 7000DA04 AFA2002C */  sw    $v0, 0x2c($sp)
/* 00E608 7000DA08 AC2069B0 */  sw    $zero, 0x10($at)
/* 00E60C 7000DA0C AC2069B4 */  sw    $zero, 0x14($at)
/* 00E610 7000DA10 AC2069B8 */  sw    $zero, 0x18($at)
/* 00E614 7000DA14 24E769A0 */  addiu $a3, %lo(__osViDevMgr) # addiu $a3, $a3, 0x69a0
/* 00E618 7000DA18 24C6DA78 */  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, -0x2588
/* 00E61C 7000DA1C AFAE0010 */  sw    $t6, 0x10($sp)
/* 00E620 7000DA20 01602025 */  move  $a0, $t3
/* 00E624 7000DA24 00002825 */  move  $a1, $zero
/* 00E628 7000DA28 0C00350C */  jal   osCreateThread
/* 00E62C 7000DA2C AFAF0014 */   sw    $t7, 0x14($sp)
/* 00E630 7000DA30 0C006294 */  jal   __osViInit
/* 00E634 7000DA34 00000000 */   nop   
/* 00E638 7000DA38 3C048006 */  lui   $a0, %hi(viThread) # $a0, 0x8006
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
)
#endif



#ifdef NONMATCHING

#else
GLOBAL_ASM(
.text
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
/* 00E69C 7000DA9C 3C018006 */  lui   $at, %hi(retrace) # $at, 0x8006
/* 00E6A0 7000DAA0 95CF0002 */  lhu   $t7, 2($t6)
/* 00E6A4 7000DAA4 15E00004 */  bnez  $t7, .L7000DAB8
/* 00E6A8 7000DAA8 A42F6A00 */   sh    $t7, %lo(retrace)($at)
/* 00E6AC 7000DAAC 24180001 */  li    $t8, 1
/* 00E6B0 7000DAB0 3C018006 */  lui   $at, %hi(retrace) # $at, 0x8006
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
/* 00E708 7000DB08 3C018006 */  lui   $at, %hi(retrace) # $at, 0x8006
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
/* 00E74C 7000DB4C 3C018006 */  lui   $at, %hi(retrace) # $at, 0x8006
/* 00E750 7000DB50 95F80002 */  lhu   $t8, 2($t7)
/* 00E754 7000DB54 A4386A00 */  sh    $t8, %lo(retrace)($at)
.L7000DB58:
/* 00E758 7000DB58 3C198007 */  lui   $t9, %hi(__osViIntrCount) 
/* 00E75C 7000DB5C 8F398E1C */  lw    $t9, %lo(__osViIntrCount)($t9)
/* 00E760 7000DB60 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E764 7000DB64 3C018007 */  lui   $at, %hi(__osViIntrCount) # $at, 0x8007
/* 00E768 7000DB68 27280001 */  addiu $t0, $t9, 1
/* 00E76C 7000DB6C 1120000C */  beqz  $t1, .L7000DBA0
/* 00E770 7000DB70 AC288E1C */   sw    $t0, %lo(__osViIntrCount)($at)
/* 00E774 7000DB74 0C003638 */  jal   osGetCount
/* 00E778 7000DB78 00000000 */   nop   
/* 00E77C 7000DB7C AFA20024 */  sw    $v0, 0x24($sp)
/* 00E780 7000DB80 8FAA0024 */  lw    $t2, 0x24($sp)
/* 00E784 7000DB84 240C0000 */  li    $t4, 0
/* 00E788 7000DB88 3C018007 */  lui   $at, %hi(__osCurrentTime) # $at, 0x8007
/* 00E78C 7000DB8C AC2C8E10 */  sw    $t4, %lo(__osCurrentTime)($at)
/* 00E790 7000DB90 3C018007 */  lui   $at, %hi(__osCurrentTime+4) # $at, 0x8007
/* 00E794 7000DB94 01406825 */  move  $t5, $t2
/* 00E798 7000DB98 AC2D8E14 */  sw    $t5, %lo(__osCurrentTime+4)($at)
/* 00E79C 7000DB9C AFA00028 */  sw    $zero, 0x28($sp)
.L7000DBA0:
/* 00E7A0 7000DBA0 3C0B8007 */  lui   $t3, %hi(__osBaseCounter) 
/* 00E7A4 7000DBA4 8D6B8E18 */  lw    $t3, %lo(__osBaseCounter)($t3)
/* 00E7A8 7000DBA8 0C003638 */  jal   osGetCount
/* 00E7AC 7000DBAC AFAB0024 */   sw    $t3, 0x24($sp)
/* 00E7B0 7000DBB0 3C018007 */  lui   $at, %hi(__osBaseCounter) # $at, 0x8007
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
/* 00E7EC 7000DBEC 3C018007 */  lui   $at, %hi(__osCurrentTime) # $at, 0x8007
/* 00E7F0 7000DBF0 018A6021 */  addu  $t4, $t4, $t2
/* 00E7F4 7000DBF4 AC2C8E10 */  sw    $t4, %lo(__osCurrentTime)($at)
/* 00E7F8 7000DBF8 3C018007 */  lui   $at, %hi(__osCurrentTime+4) # $at, 0x8007
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
)
#endif



