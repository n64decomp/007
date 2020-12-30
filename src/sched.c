#include <ultra64.h>
#include "init.h"
#include "sched.h"
#include "bondgame.h"
#include "deb_print.h"

/**
 * @file sched.c
 * This file contains the scheduler. 
 * 
 * In particular, it:
 *   - is based on but modified by rare from code included in sdk
 *   - 
 *   - 
 */

u32 stderr_unused = 0;
u32 stderr_enabled = 0;
u32 stderr_active = 0;
u32 stderr_permitted = 0;
u32 userCompareValue = 45000000;
u32 currentcount = 0;
u32 setby_DPCfill_0 = 0;
u32 setby_DPCfill_1 = 0;
//800230b0
f32 something_with_osVI_0 = 0.0;
f32 something_with_osVI_4 = 1.0;
f32 something_with_osVI_8 = 1.0;
f32 something_with_osVI_C = 1.0;
f32 something_with_osVI_10 = 1.0;
f32 something_with_osVI_14 = 0.0;
f32 something_with_osVI_18 = 0.0;

u32 D_800230CC = 1;


OSSched sc;
//temporary until i get proper sized structs
OSScClient gfxClient[3];
//char gfxClient[0x18];

char target_for_counters_maybe[0x10];
char dword_CODE_bss_8005DB40[0xB0];


/**
 * 1570	70000970
 * A0-> stderr.activated	[80023098]; fry AT
 */
void activate_stderr(u32 flag)
{
	stderr_active = flag;
}

/**
 * 157C	7000097C
 * A0-> stderr.enable		[80023094]; fry AT
 */
void enable_stderr(u32 flag)
{
	stderr_enabled = flag;
}

/**
 * 1588	70000988
 * A0-> stderr.permitted	[8002309C]; fry AT
 */
void permit_stderr(u32 flag)
{
	stderr_permitted = flag;
}

/**
 * 1594	70000994
 * A0-> user.Compare		[800230A0]; fry AT
 */
void setUserCompareValue(u32 value)
{
	userCompareValue = value;
}

/**
 * 15A0	700009A0
 * test to display stderr and update Count
 */
void CheckDisplayErrorBuffer(u32 *buffer)
{
	if ((stderr_permitted && stderr_active) || stderr_enabled )
    {
		write_stderr_to_buffer(buffer);
		currentcount = osGetCount();
	}
}

/**
 * 15F8	700009F8
 * test to display stderr every 16th frame
 */

void CheckDisplayErrorBufferEvery16Frames(u32 framecount)
{
	if (!(framecount & 0xf))
    {
		if ((stderr_permitted && stderr_active) || stderr_enabled)
        {
			if (userCompareValue < (osGetCount() - currentcount))
            {
				write_stderr_to_buffer((u32*)cfb_16[0]);
				write_stderr_to_buffer((u32*)cfb_16[1]);
			}
		}
	}
}

/**
 * Not 100% on name, came from osInitialize's call to function
 * 1688	70000A88
 * store current Count to 800230A4
 */
void osCreateLog(void){
	currentcount=osGetCount();
}

/**
 * 16AC	70000AAC
 * (thread management)
 */
#ifdef NONMATCHING
void osCreateScheduler (OSSched * sc, void * stack, u8 mode, u8 numFields)
{
    sc->curRSPTask = 0;
    sc->curRDPTask = 0;
    sc->clientList = 0;
    sc->frameCount = 0;
    sc->audioListHead = 0;
    sc->gfxListHead = 0;
    sc->audioListTail = 0;
    sc->gfxListTail = 0;
    sc->retraceMsg.type = 1;
    sc->prenmiMsg.type = 5;
    sc->thread = stack;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, 8);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, 8);
    osCreateViManager(0xfe);

    viMode = osViModeTable[mode];
    viMode.comRegs.ctrl = osViModeTable[mode].comRegs.hStart;
    viMode.comRegs.width = osViModeTable[mode].fldRegs[0].vStart;
    viMode.comRegs.burst = osViModeTable[mode].fldRegs[1].vStart;

    osSetEventMesg(4, &sc->interruptQ, 0x29b);
    osSetEventMesg(9, &sc->interruptQ, 0x29c);
    osSetEventMesg(0xe, &sc->interruptQ, 0x29d);
    osViSetEvent(&sc->interruptQ, 0x29a, numFields);
    osCreateLog();
    osCreateThread(sc->thread, 2, &__scMain, sc, set_stack_entry(&sp_shed, 0x200), 0x1e);
    osStartThread(sc->thread);
}
#else
GLOBAL_ASM(
glabel osCreateScheduler
/* 0016AC 70000AAC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0016B0 70000AB0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0016B4 70000AB4 AFB10020 */  sw    $s1, 0x20($sp)
/* 0016B8 70000AB8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0016BC 70000ABC AFA5002C */  sw    $a1, 0x2c($sp)
/* 0016C0 70000AC0 AFA60030 */  sw    $a2, 0x30($sp)
/* 0016C4 70000AC4 AFA70034 */  sw    $a3, 0x34($sp)
/* 0016C8 70000AC8 240E0001 */  li    $t6, 1
/* 0016CC 70000ACC 240F0005 */  li    $t7, 5
/* 0016D0 70000AD0 AC8000C8 */  sw    $zero, 0xc8($a0)
/* 0016D4 70000AD4 AC8000CC */  sw    $zero, 0xcc($a0)
/* 0016D8 70000AD8 AC8000B4 */  sw    $zero, 0xb4($a0)
/* 0016DC 70000ADC AC8000D0 */  sw    $zero, 0xd0($a0)
/* 0016E0 70000AE0 AC8000B8 */  sw    $zero, 0xb8($a0)
/* 0016E4 70000AE4 AC8000BC */  sw    $zero, 0xbc($a0)
/* 0016E8 70000AE8 AC8000C0 */  sw    $zero, 0xc0($a0)
/* 0016EC 70000AEC AC8000C4 */  sw    $zero, 0xc4($a0)
/* 0016F0 70000AF0 A48E0000 */  sh    $t6, ($a0)
/* 0016F4 70000AF4 A48F0020 */  sh    $t7, 0x20($a0)
/* 0016F8 70000AF8 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0016FC 70000AFC 00808025 */  move  $s0, $a0
/* 001700 70000B00 24910040 */  addiu $s1, $a0, 0x40
/* 001704 70000B04 AC9800B0 */  sw    $t8, 0xb0($a0)
/* 001708 70000B08 02202025 */  move  $a0, $s1
/* 00170C 70000B0C 26050058 */  addiu $a1, $s0, 0x58
/* 001710 70000B10 0C0035B4 */  jal   osCreateMesgQueue
/* 001714 70000B14 24060008 */   li    $a2, 8
/* 001718 70000B18 26040078 */  addiu $a0, $s0, 0x78
/* 00171C 70000B1C 26050090 */  addiu $a1, $s0, 0x90
/* 001720 70000B20 0C0035B4 */  jal   osCreateMesgQueue
/* 001724 70000B24 24060008 */   li    $a2, 8
/* 001728 70000B28 0C00363C */  jal   osCreateViManager
/* 00172C 70000B2C 240400FE */   li    $a0, 254
/* 001730 70000B30 93B90033 */  lbu   $t9, 0x33($sp)
/* 001734 70000B34 3C098002 */  lui   $t1, %hi(osViModeTable) 
/* 001738 70000B38 3C038006 */  lui   $v1, %hi(viMode)
/* 00173C 70000B3C 00194080 */  sll   $t0, $t9, 2
/* 001740 70000B40 01194021 */  addu  $t0, $t0, $t9
/* 001744 70000B44 00084100 */  sll   $t0, $t0, 4
/* 001748 70000B48 252969C0 */  addiu $t1, %lo(osViModeTable) # addiu $t1, $t1, 0x69c0
/* 00174C 70000B4C 2463087C */  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 001750 70000B50 01095021 */  addu  $t2, $t0, $t1
/* 001754 70000B54 AC6A0000 */  sw    $t2, ($v1)
/* 001758 70000B58 8D4B001C */  lw    $t3, 0x1c($t2)
/* 00175C 70000B5C 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 001760 70000B60 24040004 */  li    $a0, 4
/* 001764 70000B64 AC2B0880 */  sw    $t3, %lo(viMode+0x4)($at)
/* 001768 70000B68 8D4C0030 */  lw    $t4, 0x30($t2)
/* 00176C 70000B6C 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 001770 70000B70 02202825 */  move  $a1, $s1
/* 001774 70000B74 AC2C0884 */  sw    $t4, %lo(viMode+0x8)($at)
/* 001778 70000B78 8D4D0044 */  lw    $t5, 0x44($t2)
/* 00177C 70000B7C 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 001780 70000B80 2406029B */  li    $a2, 667
/* 001784 70000B84 0C003714 */  jal   osSetEventMesg
/* 001788 70000B88 AC2D0888 */   sw    $t5, %lo(viMode+0xC)($at)
/* 00178C 70000B8C 24040009 */  li    $a0, 9
/* 001790 70000B90 02202825 */  move  $a1, $s1
/* 001794 70000B94 0C003714 */  jal   osSetEventMesg
/* 001798 70000B98 2406029C */   li    $a2, 668
/* 00179C 70000B9C 2404000E */  li    $a0, 14
/* 0017A0 70000BA0 02202825 */  move  $a1, $s1
/* 0017A4 70000BA4 0C003714 */  jal   osSetEventMesg
/* 0017A8 70000BA8 2406029D */   li    $a2, 669
/* 0017AC 70000BAC 02202025 */  move  $a0, $s1
/* 0017B0 70000BB0 2405029A */  li    $a1, 666
/* 0017B4 70000BB4 0C003730 */  jal   osViSetEvent
/* 0017B8 70000BB8 8FA60034 */   lw    $a2, 0x34($sp)
/* 0017BC 70000BBC 0C0002A2 */  jal   osCreateLog
/* 0017C0 70000BC0 00000000 */   nop   
/* 0017C4 70000BC4 3C04803B */  lui   $a0, %hi(sp_shed) # $a0, 0x803b
/* 0017C8 70000BC8 2484B750 */  addiu $a0, %lo(sp_shed) # addiu $a0, $a0, -0x48b0
/* 0017CC 70000BCC 0C0001BC */  jal   set_stack_entry
/* 0017D0 70000BD0 24050200 */   li    $a1, 512
/* 0017D4 70000BD4 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0017D8 70000BD8 3C067000 */  lui   $a2, %hi(__scMain) # $a2, 0x7000
/* 0017DC 70000BDC 240E001E */  li    $t6, 30
/* 0017E0 70000BE0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0017E4 70000BE4 24C60D00 */  addiu $a2, %lo(__scMain) # addiu $a2, $a2, 0xd00
/* 0017E8 70000BE8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0017EC 70000BEC 24050002 */  li    $a1, 2
/* 0017F0 70000BF0 0C00350C */  jal   osCreateThread
/* 0017F4 70000BF4 02003825 */   move  $a3, $s0
/* 0017F8 70000BF8 0C003560 */  jal   osStartThread
/* 0017FC 70000BFC 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 001800 70000C00 8FBF0024 */  lw    $ra, 0x24($sp)
/* 001804 70000C04 8FB0001C */  lw    $s0, 0x1c($sp)
/* 001808 70000C08 8FB10020 */  lw    $s1, 0x20($sp)
/* 00180C 70000C0C 03E00008 */  jr    $ra
/* 001810 70000C10 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

/**
 * 1814	70000C14
 */
void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next)
{
    OSIntMask mask;

    mask = osSetIntMask(1);

    c->msgQ = msgQ;
    c[1].next = next;
    c->next = sc->clientList;
    sc->clientList = c;

    osSetIntMask(mask);
}


/**
 * 1870	70000C70
 */
void osScRemoveClient(OSSched *sc, OSScClient *c)
{
    OSScClient *client = sc->clientList; 
    OSScClient *prev   = 0;
    OSIntMask  mask;

    mask = osSetIntMask(1);
    
    while (client != 0) 
    {
        if (client == c) 
        {
	        if(prev)
		        prev->next = c->next;
	        else
		        sc->clientList = c->next;
                break;
        }
        prev   = client;
        client = client->next;
    }

    osSetIntMask(mask);
}


/**
 * 18F8	70000CF8
 * V0= A0+78
 */
OSMesgQueue *osScGetCmdQ(OSSched *sc)
{
    return &sc->cmdQ;
}

/**
 * 1900	70000D00
 */
#ifdef NONMATCHING
void __scMain(void *arg)
{
    OSMesg msg;
    OSSched *sc = (OSSched *)arg;
    OSScClient *client;
    static int count = 0;
    
    while (1) {
        
        osRecvMesg(&sc->interruptQ, (OSMesg *)&msg, OS_MESG_BLOCK);

        switch ((int) msg) {
            case (0x29a):
                __scHandleRetrace(sc);
                break;

            case (0x29b):
                __scHandleRSP(sc);
                break;

            case (0x29c):
                __scHandleRDP(sc);
                break;

            case (0x29d):
                reset_cont_rumble_detect();
                for (client = sc->clientList;client != 0;client = client->next) {
                      osSendMesg(client->msgQ, (OSMesg) &sc->prenmiMsg, OS_MESG_NOBLOCK);
                }
                break;
        }
    }
    if (osTvType == 2)
    {
        osViSetMode(0x80027320);
    }
    else
    {
        osViSetMode(0x80026a60);
    }
    osViSetXScale(1.00000000);
    osViSetYScale(1.00000000);
    osViRepeatLine(0);
    osViBlack(1);

    while (1) {
        while ((u32)msg != 0x29a) {
            osRecvMesg(&sc->interruptQ,&msg,1);
        }
        controllerSchedulerRelated();
    }

}
#else
GLOBAL_ASM(
glabel __scMain
/* 001900 70000D00 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 001904 70000D04 AFB50028 */  sw    $s5, 0x28($sp)
/* 001908 70000D08 AFB40024 */  sw    $s4, 0x24($sp)
/* 00190C 70000D0C AFB30020 */  sw    $s3, 0x20($sp)
/* 001910 70000D10 AFB2001C */  sw    $s2, 0x1c($sp)
/* 001914 70000D14 AFB00014 */  sw    $s0, 0x14($sp)
/* 001918 70000D18 00809025 */  move  $s2, $a0
/* 00191C 70000D1C AFBF002C */  sw    $ra, 0x2c($sp)
/* 001920 70000D20 AFB10018 */  sw    $s1, 0x18($sp)
/* 001924 70000D24 AFA0004C */  sw    $zero, 0x4c($sp)
/* 001928 70000D28 00008025 */  move  $s0, $zero
/* 00192C 70000D2C 24930040 */  addiu $s3, $a0, 0x40
/* 001930 70000D30 27B4004C */  addiu $s4, $sp, 0x4c
/* 001934 70000D34 2415029A */  li    $s5, 666
/* 001938 70000D38 02602025 */  move  $a0, $s3
.L70000D3C:
/* 00193C 70000D3C 02802825 */  move  $a1, $s4
/* 001940 70000D40 0C003774 */  jal   osRecvMesg
/* 001944 70000D44 24060001 */   li    $a2, 1
/* 001948 70000D48 8FAE004C */  lw    $t6, 0x4c($sp)
/* 00194C 70000D4C 2401029B */  li    $at, 667
/* 001950 70000D50 11D50009 */  beq   $t6, $s5, .L70000D78
/* 001954 70000D54 00000000 */   nop   
/* 001958 70000D58 11C1000B */  beq   $t6, $at, .L70000D88
/* 00195C 70000D5C 2401029C */   li    $at, 668
/* 001960 70000D60 11C1000D */  beq   $t6, $at, .L70000D98
/* 001964 70000D64 2401029D */   li    $at, 669
/* 001968 70000D68 11C1000F */  beq   $t6, $at, .L70000DA8
/* 00196C 70000D6C 00000000 */   nop   
/* 001970 70000D70 1000001B */  b     .L70000DE0
/* 001974 70000D74 00000000 */   nop   
.L70000D78:
/* 001978 70000D78 0C0003AD */  jal   __scHandleRetrace
/* 00197C 70000D7C 02402025 */   move  $a0, $s2
/* 001980 70000D80 10000017 */  b     .L70000DE0
/* 001984 70000D84 00000000 */   nop   
.L70000D88:
/* 001988 70000D88 0C000405 */  jal   __scHandleRSP
/* 00198C 70000D8C 02402025 */   move  $a0, $s2
/* 001990 70000D90 10000013 */  b     .L70000DE0
/* 001994 70000D94 00000000 */   nop   
.L70000D98:
/* 001998 70000D98 0C00044A */  jal   __scHandleRDP
/* 00199C 70000D9C 02402025 */   move  $a0, $s2
/* 0019A0 70000DA0 1000000F */  b     .L70000DE0
/* 0019A4 70000DA4 00000000 */   nop   
.L70000DA8:
/* 0019A8 70000DA8 0C003237 */  jal   reset_cont_rumble_detect
/* 0019AC 70000DAC 00000000 */   nop   
/* 0019B0 70000DB0 8E5000B4 */  lw    $s0, 0xb4($s2)
/* 0019B4 70000DB4 26510020 */  addiu $s1, $s2, 0x20
/* 0019B8 70000DB8 52000009 */  beql  $s0, $zero, .L70000DE0
/* 0019BC 70000DBC 24100001 */   li    $s0, 1
/* 0019C0 70000DC0 8E040004 */  lw    $a0, 4($s0)
.L70000DC4:
/* 0019C4 70000DC4 02202825 */  move  $a1, $s1
/* 0019C8 70000DC8 0C0037C4 */  jal   osSendMesg
/* 0019CC 70000DCC 00003025 */   move  $a2, $zero
/* 0019D0 70000DD0 8E100000 */  lw    $s0, ($s0)
/* 0019D4 70000DD4 5600FFFB */  bnezl $s0, .L70000DC4
/* 0019D8 70000DD8 8E040004 */   lw    $a0, 4($s0)
/* 0019DC 70000DDC 24100001 */  li    $s0, 1
.L70000DE0:
/* 0019E0 70000DE0 5200FFD6 */  beql  $s0, $zero, .L70000D3C
/* 0019E4 70000DE4 02602025 */   move  $a0, $s3
/* 0019E8 70000DE8 3C0F8000 */  lui   $t7, %hi(osTvType) 
/* 0019EC 70000DEC 8DEF0300 */  lw    $t7, %lo(osTvType)($t7)
/* 0019F0 70000DF0 24010002 */  li    $at, 2
/* 0019F4 70000DF4 3C048002 */  lui   $a0, %hi(osViModeTable_osViModeNtscLan1)
/* 0019F8 70000DF8 15E10006 */  bne   $t7, $at, .L70000E14
/* 0019FC 70000DFC 00000000 */   nop   
/* 001A00 70000E00 3C048002 */  lui   $a0, %hi(osViModeTable_osViModeMpalLan1)
/* 001A04 70000E04 0C003818 */  jal   osViSetMode
/* 001A08 70000E08 24847320 */   addiu $a0, %lo(osViModeTable_osViModeMpalLan1) # addiu $a0, $a0, 0x7320
/* 001A0C 70000E0C 10000004 */  b     .L70000E20
/* 001A10 70000E10 3C013F80 */   lui   $at, 0x3f80
.L70000E14:
/* 001A14 70000E14 0C003818 */  jal   osViSetMode
/* 001A18 70000E18 24846A60 */   addiu $a0, $a0, %lo(osViModeTable_osViModeNtscLan1)
/* 001A1C 70000E1C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
.L70000E20:
/* 001A20 70000E20 44816000 */  mtc1  $at, $f12
/* 001A24 70000E24 0C003834 */  jal   osViSetXScale
/* 001A28 70000E28 00000000 */   nop   
/* 001A2C 70000E2C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 001A30 70000E30 44816000 */  mtc1  $at, $f12
/* 001A34 70000E34 0C003880 */  jal   osViSetYScale
/* 001A38 70000E38 00000000 */   nop   
/* 001A3C 70000E3C 0C003898 */  jal   osViRepeatLine
/* 001A40 70000E40 00002025 */   move  $a0, $zero
/* 001A44 70000E44 0C0038B4 */  jal   osViBlack
/* 001A48 70000E48 24040001 */   li    $a0, 1
/* 001A4C 70000E4C 02602025 */  move  $a0, $s3
.L70000E50:
/* 001A50 70000E50 02802825 */  move  $a1, $s4
/* 001A54 70000E54 0C003774 */  jal   osRecvMesg
/* 001A58 70000E58 24060001 */   li    $a2, 1
/* 001A5C 70000E5C 8FB8004C */  lw    $t8, 0x4c($sp)
/* 001A60 70000E60 5715FFFB */  bnel  $t8, $s5, .L70000E50
/* 001A64 70000E64 02602025 */   move  $a0, $s3
/* 001A68 70000E68 0C002F62 */  jal   controllerSchedulerRelated
/* 001A6C 70000E6C 00000000 */   nop   
/* 001A70 70000E70 1000FFF7 */  b     .L70000E50
/* 001A74 70000E74 02602025 */   move  $a0, $s3
/* 001A78 70000E78 00000000 */  nop   
/* 001A7C 70000E7C 00000000 */  nop   
/* 001A80 70000E80 00000000 */  nop   
/* 001A84 70000E84 00000000 */  nop   
/* 001A88 70000E88 00000000 */  nop   
/* 001A8C 70000E8C 00000000 */  nop   
/* 001A90 70000E90 8FBF002C */  lw    $ra, 0x2c($sp)
/* 001A94 70000E94 8FB00014 */  lw    $s0, 0x14($sp)
/* 001A98 70000E98 8FB10018 */  lw    $s1, 0x18($sp)
/* 001A9C 70000E9C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 001AA0 70000EA0 8FB30020 */  lw    $s3, 0x20($sp)
/* 001AA4 70000EA4 8FB40024 */  lw    $s4, 0x24($sp)
/* 001AA8 70000EA8 8FB50028 */  lw    $s5, 0x28($sp)
/* 001AAC 70000EAC 03E00008 */  jr    $ra
/* 001AB0 70000EB0 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif

/**
 * 1AB4	70000EB4
 */
#ifdef NONMATCHING
void __scHandleRetrace(OSSched *sc)
{
    OSScTask    *rspTask = 0;
    
    OSScClient  *client;
    //s32         i;
    s32         state;
    OSScTask    *sp = 0;
    OSScTask    *dp = 0;
    

    video_related_1();
    sc->frameCount++;
    video_related_7();
    controllerSchedulerRelated();
    music_related_15();
    while (osRecvMesg(&sc->cmdQ, (OSMesg *)&rspTask, OS_MESG_NOBLOCK) != -1) {
        __scAppendList(sc, rspTask);
    }
    if (sc->doAudio && sc->curRSPTask) {
        __scYield(sc);
    } else {
        state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
        if ( __scSchedule (sc, &sp, &dp, state) != state)
            __scExec(sc, sp, dp);
    }

    for (client = sc->clientList; client != 0; client = client->next) {
        osSendMesg(client->msgQ, (OSMesg) &sc->retraceMsg, OS_MESG_NOBLOCK);
    }

    CheckDisplayErrorBufferEvery16Frames(sc->frameCount);
}
#else
GLOBAL_ASM(
glabel __scHandleRetrace
/* 001AB4 70000EB4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 001AB8 70000EB8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 001ABC 70000EBC AFB10018 */  sw    $s1, 0x18($sp)
/* 001AC0 70000EC0 00808825 */  move  $s1, $a0
/* 001AC4 70000EC4 AFB30020 */  sw    $s3, 0x20($sp)
/* 001AC8 70000EC8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 001ACC 70000ECC AFB00014 */  sw    $s0, 0x14($sp)
/* 001AD0 70000ED0 AFA0003C */  sw    $zero, 0x3c($sp)
/* 001AD4 70000ED4 AFA00030 */  sw    $zero, 0x30($sp)
/* 001AD8 70000ED8 0C0009E9 */  jal   video_related_1
/* 001ADC 70000EDC AFA0002C */   sw    $zero, 0x2c($sp)
/* 001AE0 70000EE0 8E2E00D0 */  lw    $t6, 0xd0($s1)
/* 001AE4 70000EE4 25CF0001 */  addiu $t7, $t6, 1
/* 001AE8 70000EE8 0C000C68 */  jal   video_related_7
/* 001AEC 70000EEC AE2F00D0 */   sw    $t7, 0xd0($s1)
/* 001AF0 70000EF0 0C002F62 */  jal   controllerSchedulerRelated
/* 001AF4 70000EF4 00000000 */   nop   
/* 001AF8 70000EF8 0C001E45 */  jal   music_related_15
/* 001AFC 70000EFC 00000000 */   nop   
/* 001B00 70000F00 27B3003C */  addiu $s3, $sp, 0x3c
/* 001B04 70000F04 26320078 */  addiu $s2, $s1, 0x78
/* 001B08 70000F08 02402025 */  move  $a0, $s2
/* 001B0C 70000F0C 02602825 */  move  $a1, $s3
/* 001B10 70000F10 0C003774 */  jal   osRecvMesg
/* 001B14 70000F14 00003025 */   move  $a2, $zero
/* 001B18 70000F18 2410FFFF */  li    $s0, -1
/* 001B1C 70000F1C 10500009 */  beq   $v0, $s0, .L70000F44
/* 001B20 70000F20 02202025 */   move  $a0, $s1
.L70000F24:
/* 001B24 70000F24 0C0004F6 */  jal   __scAppendList
/* 001B28 70000F28 8FA5003C */   lw    $a1, 0x3c($sp)
/* 001B2C 70000F2C 02402025 */  move  $a0, $s2
/* 001B30 70000F30 02602825 */  move  $a1, $s3
/* 001B34 70000F34 0C003774 */  jal   osRecvMesg
/* 001B38 70000F38 00003025 */   move  $a2, $zero
/* 001B3C 70000F3C 5450FFF9 */  bnel  $v0, $s0, .L70000F24
/* 001B40 70000F40 02202025 */   move  $a0, $s1
.L70000F44:
/* 001B44 70000F44 8E3800D4 */  lw    $t8, 0xd4($s1)
/* 001B48 70000F48 02202025 */  move  $a0, $s1
/* 001B4C 70000F4C 27A50030 */  addiu $a1, $sp, 0x30
/* 001B50 70000F50 53000009 */  beql  $t8, $zero, .L70000F78
/* 001B54 70000F54 8E2800C8 */   lw    $t0, 0xc8($s1)
/* 001B58 70000F58 8E3900C8 */  lw    $t9, 0xc8($s1)
/* 001B5C 70000F5C 53200006 */  beql  $t9, $zero, .L70000F78
/* 001B60 70000F60 8E2800C8 */   lw    $t0, 0xc8($s1)
/* 001B64 70000F64 0C000558 */  jal   __scYield
/* 001B68 70000F68 02202025 */   move  $a0, $s1
/* 001B6C 70000F6C 10000010 */  b     .L70000FB0
/* 001B70 70000F70 8E3000B4 */   lw    $s0, 0xb4($s1)
/* 001B74 70000F74 8E2800C8 */  lw    $t0, 0xc8($s1)
.L70000F78:
/* 001B78 70000F78 8E2B00CC */  lw    $t3, 0xcc($s1)
/* 001B7C 70000F7C 27A6002C */  addiu $a2, $sp, 0x2c
/* 001B80 70000F80 2D090001 */  sltiu $t1, $t0, 1
/* 001B84 70000F84 00095040 */  sll   $t2, $t1, 1
/* 001B88 70000F88 2D6C0001 */  sltiu $t4, $t3, 1
/* 001B8C 70000F8C 014C8025 */  or    $s0, $t2, $t4
/* 001B90 70000F90 0C000567 */  jal   __scSchedule
/* 001B94 70000F94 02003825 */   move  $a3, $s0
/* 001B98 70000F98 10500004 */  beq   $v0, $s0, .L70000FAC
/* 001B9C 70000F9C 02202025 */   move  $a0, $s1
/* 001BA0 70000FA0 8FA50030 */  lw    $a1, 0x30($sp)
/* 001BA4 70000FA4 0C000510 */  jal   __scExec
/* 001BA8 70000FA8 8FA6002C */   lw    $a2, 0x2c($sp)
.L70000FAC:
/* 001BAC 70000FAC 8E3000B4 */  lw    $s0, 0xb4($s1)
.L70000FB0:
/* 001BB0 70000FB0 1200000F */  beqz  $s0, .L70000FF0
/* 001BB4 70000FB4 00000000 */   nop   
/* 001BB8 70000FB8 8E0D0008 */  lw    $t5, 8($s0)
.L70000FBC:
/* 001BBC 70000FBC 02202825 */  move  $a1, $s1
/* 001BC0 70000FC0 00003025 */  move  $a2, $zero
/* 001BC4 70000FC4 11A00005 */  beqz  $t5, .L70000FDC
/* 001BC8 70000FC8 00000000 */   nop   
/* 001BCC 70000FCC 8E2E00D0 */  lw    $t6, 0xd0($s1)
/* 001BD0 70000FD0 31CF0001 */  andi  $t7, $t6, 1
/* 001BD4 70000FD4 55E00004 */  bnezl $t7, .L70000FE8
/* 001BD8 70000FD8 8E100000 */   lw    $s0, ($s0)
.L70000FDC:
/* 001BDC 70000FDC 0C0037C4 */  jal   osSendMesg
/* 001BE0 70000FE0 8E040004 */   lw    $a0, 4($s0)
/* 001BE4 70000FE4 8E100000 */  lw    $s0, ($s0)
.L70000FE8:
/* 001BE8 70000FE8 5600FFF4 */  bnezl $s0, .L70000FBC
/* 001BEC 70000FEC 8E0D0008 */   lw    $t5, 8($s0)
.L70000FF0:
/* 001BF0 70000FF0 0C00027E */  jal   CheckDisplayErrorBufferEvery16Frames
/* 001BF4 70000FF4 8E2400D0 */   lw    $a0, 0xd0($s1)
/* 001BF8 70000FF8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 001BFC 70000FFC 8FB00014 */  lw    $s0, 0x14($sp)
/* 001C00 70001000 8FB10018 */  lw    $s1, 0x18($sp)
/* 001C04 70001004 8FB2001C */  lw    $s2, 0x1c($sp)
/* 001C08 70001008 8FB30020 */  lw    $s3, 0x20($sp)
/* 001C0C 7000100C 03E00008 */  jr    $ra
/* 001C10 70001010 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

/**
 * 1C14	70001014
 */
#ifdef NONMATCHING
void __scHandleRSP(OSSched *sc)
{
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;

    t = sc->curRSPTask;
    sc->curRSPTask = 0;
    video_related_3(0x10001);
    if (((t->state & 0x10) != 0) && (osSpTaskYielded(t->list) != 0))
    {
        t->state = (s32) (t->state | 0x20);
        if ((t->flags & 7) == 3)
        {
            *t = (void *) sc->gfxListHead;
            sc->gfxListHead = t;
            if (sc->gfxListTail == 0)
            {
                sc->gfxListTail = t;
            }
        }
    }
    else
    {
        t->state = (s32) (t->state & -3);
        __scTaskComplete(sc, t);
    }
    if (__scSchedule(sc, &sp, &dp, ((((u32) sc->curRSPTask < 1U) * 2) | ((u32) sc->curRDPTask < 1U))))
    {
        __scExec(sc, sp, dp);
    }
}

#else
GLOBAL_ASM(
glabel __scHandleRSP
/* 001C14 70001014 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 001C18 70001018 AFBF001C */  sw    $ra, 0x1c($sp)
/* 001C1C 7000101C AFB00018 */  sw    $s0, 0x18($sp)
/* 001C20 70001020 AFA00028 */  sw    $zero, 0x28($sp)
/* 001C24 70001024 AFA00024 */  sw    $zero, 0x24($sp)
/* 001C28 70001028 8C8500C8 */  lw    $a1, 0xc8($a0)
/* 001C2C 7000102C 00808025 */  move  $s0, $a0
/* 001C30 70001030 AC8000C8 */  sw    $zero, 0xc8($a0)
/* 001C34 70001034 3C040001 */  lui   $a0, (0x00010001 >> 16) # lui $a0, 1
/* 001C38 70001038 34840001 */  ori   $a0, (0x00010001 & 0xFFFF) # ori $a0, $a0, 1
/* 001C3C 7000103C 0C000A15 */  jal   video_related_3
/* 001C40 70001040 AFA5002C */   sw    $a1, 0x2c($sp)
/* 001C44 70001044 8FA5002C */  lw    $a1, 0x2c($sp)
/* 001C48 70001048 8CAE0004 */  lw    $t6, 4($a1)
/* 001C4C 7000104C 24A40010 */  addiu $a0, $a1, 0x10
/* 001C50 70001050 31CF0010 */  andi  $t7, $t6, 0x10
/* 001C54 70001054 51E00015 */  beql  $t7, $zero, .L700010AC
/* 001C58 70001058 8CAC0004 */   lw    $t4, 4($a1)
/* 001C5C 7000105C 0C0038D0 */  jal   osSpTaskYielded
/* 001C60 70001060 AFA5002C */   sw    $a1, 0x2c($sp)
/* 001C64 70001064 10400010 */  beqz  $v0, .L700010A8
/* 001C68 70001068 8FA5002C */   lw    $a1, 0x2c($sp)
/* 001C6C 7000106C 8CB80004 */  lw    $t8, 4($a1)
/* 001C70 70001070 8CA80008 */  lw    $t0, 8($a1)
/* 001C74 70001074 24010003 */  li    $at, 3
/* 001C78 70001078 37190020 */  ori   $t9, $t8, 0x20
/* 001C7C 7000107C 31090007 */  andi  $t1, $t0, 7
/* 001C80 70001080 1521000F */  bne   $t1, $at, .L700010C0
/* 001C84 70001084 ACB90004 */   sw    $t9, 4($a1)
/* 001C88 70001088 8E0A00BC */  lw    $t2, 0xbc($s0)
/* 001C8C 7000108C ACAA0000 */  sw    $t2, ($a1)
/* 001C90 70001090 8E0B00C4 */  lw    $t3, 0xc4($s0)
/* 001C94 70001094 AE0500BC */  sw    $a1, 0xbc($s0)
/* 001C98 70001098 5560000A */  bnezl $t3, .L700010C4
/* 001C9C 7000109C 8E0E00C8 */   lw    $t6, 0xc8($s0)
/* 001CA0 700010A0 10000007 */  b     .L700010C0
/* 001CA4 700010A4 AE0500C4 */   sw    $a1, 0xc4($s0)
.L700010A8:
/* 001CA8 700010A8 8CAC0004 */  lw    $t4, 4($a1)
.L700010AC:
/* 001CAC 700010AC 2401FFFD */  li    $at, -3
/* 001CB0 700010B0 02002025 */  move  $a0, $s0
/* 001CB4 700010B4 01816824 */  and   $t5, $t4, $at
/* 001CB8 700010B8 0C00048C */  jal   __scTaskComplete
/* 001CBC 700010BC ACAD0004 */   sw    $t5, 4($a1)
.L700010C0:
/* 001CC0 700010C0 8E0E00C8 */  lw    $t6, 0xc8($s0)
.L700010C4:
/* 001CC4 700010C4 8E1900CC */  lw    $t9, 0xcc($s0)
/* 001CC8 700010C8 02002025 */  move  $a0, $s0
/* 001CCC 700010CC 2DCF0001 */  sltiu $t7, $t6, 1
/* 001CD0 700010D0 000FC040 */  sll   $t8, $t7, 1
/* 001CD4 700010D4 2F280001 */  sltiu $t0, $t9, 1
/* 001CD8 700010D8 03083825 */  or    $a3, $t8, $t0
/* 001CDC 700010DC AFA70020 */  sw    $a3, 0x20($sp)
/* 001CE0 700010E0 27A50028 */  addiu $a1, $sp, 0x28
/* 001CE4 700010E4 0C000567 */  jal   __scSchedule
/* 001CE8 700010E8 27A60024 */   addiu $a2, $sp, 0x24
/* 001CEC 700010EC 8FA70020 */  lw    $a3, 0x20($sp)
/* 001CF0 700010F0 02002025 */  move  $a0, $s0
/* 001CF4 700010F4 8FA50028 */  lw    $a1, 0x28($sp)
/* 001CF8 700010F8 50470004 */  beql  $v0, $a3, .L7000110C
/* 001CFC 700010FC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001D00 70001100 0C000510 */  jal   __scExec
/* 001D04 70001104 8FA60024 */   lw    $a2, 0x24($sp)
/* 001D08 70001108 8FBF001C */  lw    $ra, 0x1c($sp)
.L7000110C:
/* 001D0C 7000110C 8FB00018 */  lw    $s0, 0x18($sp)
/* 001D10 70001110 27BD0030 */  addiu $sp, $sp, 0x30
/* 001D14 70001114 03E00008 */  jr    $ra
/* 001D18 70001118 00000000 */   nop   
)
#endif

/**
 * 1D1C	7000111C
 * V0= 8005DB30: target for DP Cmd clock, buffer counter, pipe counter, and tmem counter
 */
char *get_counters(void)
{
    return &target_for_counters_maybe;
}

/**
 * 1D28	70001128
 */
#ifdef NONMATCHING
void __scHandleRDP(void *arg0)
{
    ?32 sp28;
    ?32 sp24;

    sp28 = 0;
    sp24 = 0;
    if (arg0->unkCC != 0)
    {
        video_related_3(0x10002);
        osDpGetCounters(&target_for_counters_maybe);
        arg0->unkCC = NULL;
        arg0->unkCC->unk4 = (s32) (arg0->unkCC->unk4 & -2);
        __scTaskComplete(arg0, arg0->unkCC);
        if (__scSchedule(arg0, &sp28, &sp24, ((((u32) arg0->unkC8 < 1U) * 2) | ((u32) arg0->unkCC < 1U))) != sp20)
        {
            __scExec(arg0, sp28, sp24, sp20);
        }
    }
}

#else
GLOBAL_ASM(
glabel __scHandleRDP
/* 001D28 70001128 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 001D2C 7000112C AFBF001C */  sw    $ra, 0x1c($sp)
/* 001D30 70001130 AFB00018 */  sw    $s0, 0x18($sp)
/* 001D34 70001134 AFA00028 */  sw    $zero, 0x28($sp)
/* 001D38 70001138 AFA00024 */  sw    $zero, 0x24($sp)
/* 001D3C 7000113C 8C8E00CC */  lw    $t6, 0xcc($a0)
/* 001D40 70001140 00808025 */  move  $s0, $a0
/* 001D44 70001144 3C040001 */  lui   $a0, (0x00010002 >> 16) # lui $a0, 1
/* 001D48 70001148 51C00021 */  beql  $t6, $zero, .L700011D0
/* 001D4C 7000114C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001D50 70001150 0C000A15 */  jal   video_related_3
/* 001D54 70001154 34840002 */   ori   $a0, (0x00010002 & 0xFFFF) # ori $a0, $a0, 2
/* 001D58 70001158 3C048006 */  lui   $a0, %hi(target_for_counters_maybe)
/* 001D5C 7000115C 0C0038F0 */  jal   osDpGetCounters
/* 001D60 70001160 2484DB30 */   addiu $a0, %lo(target_for_counters_maybe) # addiu $a0, $a0, -0x24d0
/* 001D64 70001164 8E0500CC */  lw    $a1, 0xcc($s0)
/* 001D68 70001168 AE0000CC */  sw    $zero, 0xcc($s0)
/* 001D6C 7000116C 2401FFFE */  li    $at, -2
/* 001D70 70001170 8CAF0004 */  lw    $t7, 4($a1)
/* 001D74 70001174 02002025 */  move  $a0, $s0
/* 001D78 70001178 01E1C024 */  and   $t8, $t7, $at
/* 001D7C 7000117C 0C00048C */  jal   __scTaskComplete
/* 001D80 70001180 ACB80004 */   sw    $t8, 4($a1)
/* 001D84 70001184 8E1900C8 */  lw    $t9, 0xc8($s0)
/* 001D88 70001188 8E0A00CC */  lw    $t2, 0xcc($s0)
/* 001D8C 7000118C 02002025 */  move  $a0, $s0
/* 001D90 70001190 2F280001 */  sltiu $t0, $t9, 1
/* 001D94 70001194 00084840 */  sll   $t1, $t0, 1
/* 001D98 70001198 2D4B0001 */  sltiu $t3, $t2, 1
/* 001D9C 7000119C 012B3825 */  or    $a3, $t1, $t3
/* 001DA0 700011A0 AFA70020 */  sw    $a3, 0x20($sp)
/* 001DA4 700011A4 27A50028 */  addiu $a1, $sp, 0x28
/* 001DA8 700011A8 0C000567 */  jal   __scSchedule
/* 001DAC 700011AC 27A60024 */   addiu $a2, $sp, 0x24
/* 001DB0 700011B0 8FA70020 */  lw    $a3, 0x20($sp)
/* 001DB4 700011B4 02002025 */  move  $a0, $s0
/* 001DB8 700011B8 8FA50028 */  lw    $a1, 0x28($sp)
/* 001DBC 700011BC 50470004 */  beql  $v0, $a3, .L700011D0
/* 001DC0 700011C0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001DC4 700011C4 0C000510 */  jal   __scExec
/* 001DC8 700011C8 8FA60024 */   lw    $a2, 0x24($sp)
/* 001DCC 700011CC 8FBF001C */  lw    $ra, 0x1c($sp)
.L700011D0:
/* 001DD0 700011D0 8FB00018 */  lw    $s0, 0x18($sp)
/* 001DD4 700011D4 27BD0030 */  addiu $sp, $sp, 0x30
/* 001DD8 700011D8 03E00008 */  jr    $ra
/* 001DDC 700011DC 00000000 */   nop   
)
#endif

/**
 * 1DE0	700011E0
 * 
 */
OSScTask *__scTaskReady(OSScTask *t) 
{
    void *a;
    void *b;    

    if (t) {    
        if ((a=osViGetCurrentFramebuffer()) != (b=osViGetNextFramebuffer())) {
            return 0;
        }

        return t;
    }

    return 0;
}

/**
 * 1E30	70001230
 */
#ifdef NONMATCHING
void __scTaskComplete(s32 arg0, void *arg1)
{
    s32 temp_t2;
    void *temp_t8;
    void *temp_t8_2;
    void *temp_t5;
    s32 temp_t7;
    s32 temp_t0;
    void *phi_t8;
    void *phi_t5;
    s32 phi_v1;
    s32 phi_t0;
    ? phi_return;

    phi_return = 0;
    if ((arg1->unk4 & 3) == 0)
    {
        osSendMesg(arg1->unk50, arg1->unk54, 1);
        if (arg1->unk10 == 1)
        {
            if ((arg1->unk8 & 0x40) != 0)
            {
                if ((arg1->unk8 & 0x20) != 0)
                {
                    if (D_800230CC != 0)
                    {
                        osViBlack(0);
                        D_800230CC = 0;
                    }
                    temp_t2 = (something_with_osVI * 4);
                    phi_v1 = temp_t2;
                    if ((0x80020000 + temp_t2)->unk30C4 != 0)
                    {
                        temp_t8 = ((something_with_osVI * 0x50) + &dword_CODE_bss_8005DB40);
                        phi_t8 = temp_t8;
                        phi_t5 = (0x80060000 + (something_with_osVI * 4))->unk-2420;
block_8:
                        temp_t8_2 = (phi_t8 + 0xc);
                        temp_t5 = (phi_t5 + 0xc);
                        temp_t5->unk-C = (?32) *phi_t8;
                        temp_t5->unk-8 = (?32) temp_t8_2->unk-8;
                        temp_t5->unk-4 = (?32) temp_t8_2->unk-4;
                        phi_t8 = temp_t8_2;
                        phi_t5 = temp_t5;
                        if (temp_t8_2 != (temp_t8 + 0x48))
                        {
                            goto block_8;
                        }
                        *temp_t5 = (?32) *temp_t8_2;
                        temp_t5->unk4 = (?32) temp_t8_2->unk4;
                        osSetIntMask(osSetIntMask(0x80401));
                        phi_v1 = (something_with_osVI * 4);
                    }
                    osViSetXScale((0x80020000 + phi_v1)->unk30B4);
                    osViSetYScale((0x80020000 + (something_with_osVI * 4))->unk30BC);
                    temp_t7 = (something_with_osVI + 1);
                    temp_t0 = (temp_t7 & 1);
                    phi_t0 = temp_t0;
                    if (temp_t7 < 0)
                    {
                        phi_t0 = temp_t0;
                        if (temp_t0 != 0)
                        {
                            phi_t0 = (temp_t0 + -2);
                        }
                    }
                    something_with_osVI = (s32) phi_t0;
                    CheckDisplayErrorBuffer(arg1->unkC);
                    osViSwapBuffer(arg1->unkC);
                }
            }
        }
        phi_return = 1;
    }
    return phi_return;
}
#else
GLOBAL_ASM(
glabel __scTaskComplete
/* 001E30 70001230 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 001E34 70001234 AFBF001C */  sw    $ra, 0x1c($sp)
/* 001E38 70001238 AFB00018 */  sw    $s0, 0x18($sp)
/* 001E3C 7000123C AFA40020 */  sw    $a0, 0x20($sp)
/* 001E40 70001240 8CAE0004 */  lw    $t6, 4($a1)
/* 001E44 70001244 00A08025 */  move  $s0, $a1
/* 001E48 70001248 24060001 */  li    $a2, 1
/* 001E4C 7000124C 31CF0003 */  andi  $t7, $t6, 3
/* 001E50 70001250 15E0005C */  bnez  $t7, .L700013C4
/* 001E54 70001254 00001025 */   move  $v0, $zero
/* 001E58 70001258 8CA40050 */  lw    $a0, 0x50($a1)
/* 001E5C 7000125C 0C0037C4 */  jal   osSendMesg
/* 001E60 70001260 8CA50054 */   lw    $a1, 0x54($a1)
/* 001E64 70001264 8E180010 */  lw    $t8, 0x10($s0)
/* 001E68 70001268 24010001 */  li    $at, 1
/* 001E6C 7000126C 17010053 */  bne   $t8, $at, .L700013BC
/* 001E70 70001270 00000000 */   nop   
/* 001E74 70001274 8E020008 */  lw    $v0, 8($s0)
/* 001E78 70001278 30590040 */  andi  $t9, $v0, 0x40
/* 001E7C 7000127C 1320004F */  beqz  $t9, .L700013BC
/* 001E80 70001280 30480020 */   andi  $t0, $v0, 0x20
/* 001E84 70001284 1100004D */  beqz  $t0, .L700013BC
/* 001E88 70001288 3C098002 */   lui   $t1, %hi(D_800230CC) 
/* 001E8C 7000128C 8D2930CC */  lw    $t1, %lo(D_800230CC)($t1)
/* 001E90 70001290 11200005 */  beqz  $t1, .L700012A8
/* 001E94 70001294 00000000 */   nop   
/* 001E98 70001298 0C0038B4 */  jal   osViBlack
/* 001E9C 7000129C 00002025 */   move  $a0, $zero
/* 001EA0 700012A0 3C018002 */  lui   $at, %hi(D_800230CC)
/* 001EA4 700012A4 AC2030CC */  sw    $zero, %lo(D_800230CC)($at)
.L700012A8:
/* 001EA8 700012A8 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001EAC 700012AC 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001EB0 700012B0 3C0B8002 */  lui   $t3, %hi(something_with_osVI_14)
/* 001EB4 700012B4 3C040008 */  lui   $a0, (0x00080401 >> 16) # lui $a0, 8
/* 001EB8 700012B8 00035080 */  sll   $t2, $v1, 2
/* 001EBC 700012BC 016A5821 */  addu  $t3, $t3, $t2
/* 001EC0 700012C0 8D6B30C4 */  lw    $t3, %lo(something_with_osVI_14)($t3)
/* 001EC4 700012C4 01401825 */  move  $v1, $t2
/* 001EC8 700012C8 11600023 */  beqz  $t3, .L70001358
/* 001ECC 700012CC 00000000 */   nop   
/* 001ED0 700012D0 0C00374C */  jal   osSetIntMask
/* 001ED4 700012D4 34840401 */   ori   $a0, (0x00080401 & 0xFFFF) # ori $a0, $a0, 0x401
/* 001ED8 700012D8 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001EDC 700012DC 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001EE0 700012E0 3C0F8006 */  lui   $t7, %hi(dword_CODE_bss_8005DB40) 
/* 001EE4 700012E4 25EFDB40 */  addiu $t7, %lo(dword_CODE_bss_8005DB40) # addiu $t7, $t7, -0x24c0
/* 001EE8 700012E8 00037080 */  sll   $t6, $v1, 2
/* 001EEC 700012EC 01C37021 */  addu  $t6, $t6, $v1
/* 001EF0 700012F0 000E7100 */  sll   $t6, $t6, 4
/* 001EF4 700012F4 3C0D8006 */  lui   $t5, %hi(sc+416)
/* 001EF8 700012F8 00036080 */  sll   $t4, $v1, 2
/* 001EFC 700012FC 01AC6821 */  addu  $t5, $t5, $t4
/* 001F00 70001300 01CFC021 */  addu  $t8, $t6, $t7
/* 001F04 70001304 27090048 */  addiu $t1, $t8, 0x48
/* 001F08 70001308 8DADDBE0 */  lw    $t5, %lo(sc+416)($t5)
.L7000130C:
/* 001F0C 7000130C 8F010000 */  lw    $at, ($t8)
/* 001F10 70001310 2718000C */  addiu $t8, $t8, 0xc
/* 001F14 70001314 25AD000C */  addiu $t5, $t5, 0xc
/* 001F18 70001318 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 001F1C 7000131C 8F01FFF8 */  lw    $at, -8($t8)
/* 001F20 70001320 ADA1FFF8 */  sw    $at, -8($t5)
/* 001F24 70001324 8F01FFFC */  lw    $at, -4($t8)
/* 001F28 70001328 1709FFF8 */  bne   $t8, $t1, .L7000130C
/* 001F2C 7000132C ADA1FFFC */   sw    $at, -4($t5)
/* 001F30 70001330 8F010000 */  lw    $at, ($t8)
/* 001F34 70001334 00402025 */  move  $a0, $v0
/* 001F38 70001338 ADA10000 */  sw    $at, ($t5)
/* 001F3C 7000133C 8F090004 */  lw    $t1, 4($t8)
/* 001F40 70001340 0C00374C */  jal   osSetIntMask
/* 001F44 70001344 ADA90004 */   sw    $t1, 4($t5)
/* 001F48 70001348 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001F4C 7000134C 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001F50 70001350 00035080 */  sll   $t2, $v1, 2
/* 001F54 70001354 01401825 */  move  $v1, $t2
.L70001358:
/* 001F58 70001358 3C018002 */  lui   $at, %hi(something_with_osVI_4)
/* 001F5C 7000135C 00230821 */  addu  $at, $at, $v1
/* 001F60 70001360 0C003834 */  jal   osViSetXScale
/* 001F64 70001364 C42C30B4 */   lwc1  $f12, %lo(something_with_osVI_4)($at)
/* 001F68 70001368 3C0B8002 */  lui   $t3, %hi(something_with_osVI_0) 
/* 001F6C 7000136C 8D6B30B0 */  lw    $t3, %lo(something_with_osVI_0)($t3)
/* 001F70 70001370 3C018002 */  lui   $at, %hi(something_with_osVI_C)
/* 001F74 70001374 000B6080 */  sll   $t4, $t3, 2
/* 001F78 70001378 002C0821 */  addu  $at, $at, $t4
/* 001F7C 7000137C 0C003880 */  jal   osViSetYScale
/* 001F80 70001380 C42C30BC */   lwc1  $f12, %lo(something_with_osVI_C)($at)
/* 001F84 70001384 3C0E8002 */  lui   $t6, %hi(something_with_osVI_0) 
/* 001F88 70001388 8DCE30B0 */  lw    $t6, %lo(something_with_osVI_0)($t6)
/* 001F8C 7000138C 3C018002 */  lui   $at, %hi(something_with_osVI_0)
/* 001F90 70001390 25CF0001 */  addiu $t7, $t6, 1
/* 001F94 70001394 05E10004 */  bgez  $t7, .L700013A8
/* 001F98 70001398 31E80001 */   andi  $t0, $t7, 1
/* 001F9C 7000139C 11000002 */  beqz  $t0, .L700013A8
/* 001FA0 700013A0 00000000 */   nop   
/* 001FA4 700013A4 2508FFFE */  addiu $t0, $t0, -2
.L700013A8:
/* 001FA8 700013A8 AC2830B0 */  sw    $t0, %lo(something_with_osVI_0)($at)
/* 001FAC 700013AC 0C000268 */  jal   CheckDisplayErrorBuffer
/* 001FB0 700013B0 8E04000C */   lw    $a0, 0xc($s0)
/* 001FB4 700013B4 0C003924 */  jal   osViSwapBuffer
/* 001FB8 700013B8 8E04000C */   lw    $a0, 0xc($s0)
.L700013BC:
/* 001FBC 700013BC 10000001 */  b     .L700013C4
/* 001FC0 700013C0 24020001 */   li    $v0, 1
.L700013C4:
/* 001FC4 700013C4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 001FC8 700013C8 8FB00018 */  lw    $s0, 0x18($sp)
/* 001FCC 700013CC 27BD0020 */  addiu $sp, $sp, 0x20
/* 001FD0 700013D0 03E00008 */  jr    $ra
/* 001FD4 700013D4 00000000 */   nop   
)
#endif

/**
 * 1FD8	700013D8
 */

void __scAppendList(OSSched *sc, OSScTask *t) 
{
    long type = t->list.t.type;
    
    if (type == M_AUDTASK) {
        if (sc->audioListTail)
            sc->audioListTail->next = t;
        else
            sc->audioListHead = t;
            
        sc->audioListTail = t;
        sc->doAudio = 1;
    } else {
        if (sc->gfxListTail)
            sc->gfxListTail->next = t;
        else
            sc->gfxListHead = t;
        
	sc->gfxListTail = t;
    }
    
    t->next = NULL;
    t->state = t->flags & OS_SC_RCP_MASK;    
}


/**
 * 2040	70001440
 * (DPC fill)
 */
#ifdef NONMATCHING
void __scExec(void *arg0, void *arg1, void *arg2)
{
    s32 phi_v0;

    if (arg1 != 0)
    {
        if (arg1->unk10 == 2)
        {
            osWritebackDCacheAll();
        }
        phi_v0 = arg1->unk10;
        if (arg1->unk10 != 2)
        {
            phi_v0 = arg1->unk10;
            if ((arg1->unk4 & 0x10) == 0)
            {
                osDpSetStatus(0x3c0);
                phi_v0 = arg1->unk10;
            }
        }
        if (phi_v0 == 2)
        {
            video_related_3(0x30001);
        }
        else
        {
            video_related_3(0x30001);
            video_related_3(0x20002);
        }
        arg1->unk4 = (s32) (arg1->unk4 & -0x31);
        osSpTaskLoad((arg1 + 0x10));
        osSpTaskStartGo(sp20);
        arg0->unkC8 = arg1;
        if (arg1 == arg2)
        {
            arg0->unkCC = arg2;
        }
    }
    if (arg2 != 0)
    {
        if (arg2 != arg1)
        {
            osDpSetNextBuffer(arg2->unk38, *arg2->unk3C, arg2->unk3C->unk4);
            setby_DPCfill_0 = 1;
            setby_DPCfill_1 = 0;
            arg0->unkCC = arg2;
        }
    }
}
#else
GLOBAL_ASM(
glabel __scExec
/* 002040 70001440 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 002044 70001444 AFB10018 */  sw    $s1, 0x18($sp)
/* 002048 70001448 AFB00014 */  sw    $s0, 0x14($sp)
/* 00204C 7000144C 00A08025 */  move  $s0, $a1
/* 002050 70001450 00C08825 */  move  $s1, $a2
/* 002054 70001454 AFBF001C */  sw    $ra, 0x1c($sp)
/* 002058 70001458 10A0002C */  beqz  $a1, .L7000150C
/* 00205C 7000145C AFA40028 */   sw    $a0, 0x28($sp)
/* 002060 70001460 8CA20010 */  lw    $v0, 0x10($a1)
/* 002064 70001464 24010002 */  li    $at, 2
/* 002068 70001468 54410005 */  bnel  $v0, $at, .L70001480
/* 00206C 7000146C 24010002 */   li    $at, 2
/* 002070 70001470 0C0034C8 */  jal   osWritebackDCacheAll
/* 002074 70001474 00000000 */   nop   
/* 002078 70001478 8E020010 */  lw    $v0, 0x10($s0)
/* 00207C 7000147C 24010002 */  li    $at, 2
.L70001480:
/* 002080 70001480 50410009 */  beql  $v0, $at, .L700014A8
/* 002084 70001484 24010002 */   li    $at, 2
/* 002088 70001488 8E0E0004 */  lw    $t6, 4($s0)
/* 00208C 7000148C 31CF0010 */  andi  $t7, $t6, 0x10
/* 002090 70001490 55E00005 */  bnezl $t7, .L700014A8
/* 002094 70001494 24010002 */   li    $at, 2
/* 002098 70001498 0C003938 */  jal   osDpSetStatus
/* 00209C 7000149C 240403C0 */   li    $a0, 960
/* 0020A0 700014A0 8E020010 */  lw    $v0, 0x10($s0)
/* 0020A4 700014A4 24010002 */  li    $at, 2
.L700014A8:
/* 0020A8 700014A8 14410006 */  bne   $v0, $at, .L700014C4
/* 0020AC 700014AC 3C040004 */   lui   $a0, 4
/* 0020B0 700014B0 3C040003 */  lui   $a0, (0x00030001 >> 16) # lui $a0, 3
/* 0020B4 700014B4 0C000A15 */  jal   video_related_3
/* 0020B8 700014B8 34840001 */   ori   $a0, (0x00030001 & 0xFFFF) # ori $a0, $a0, 1
/* 0020BC 700014BC 10000007 */  b     .L700014DC
/* 0020C0 700014C0 8E180004 */   lw    $t8, 4($s0)
.L700014C4:
/* 0020C4 700014C4 0C000A15 */  jal   video_related_3
/* 0020C8 700014C8 34840001 */   ori   $a0, (0x00030001 & 0xFFFF) # ori $a0, $a0, 1
/* 0020CC 700014CC 3C040002 */  lui   $a0, (0x00020002 >> 16) # lui $a0, 2
/* 0020D0 700014D0 0C000A15 */  jal   video_related_3
/* 0020D4 700014D4 34840002 */   ori   $a0, (0x00020002 & 0xFFFF) # ori $a0, $a0, 2
/* 0020D8 700014D8 8E180004 */  lw    $t8, 4($s0)
.L700014DC:
/* 0020DC 700014DC 2401FFCF */  li    $at, -49
/* 0020E0 700014E0 26040010 */  addiu $a0, $s0, 0x10
/* 0020E4 700014E4 0301C824 */  and   $t9, $t8, $at
/* 0020E8 700014E8 AE190004 */  sw    $t9, 4($s0)
/* 0020EC 700014EC 0C003983 */  jal   osSpTaskLoad
/* 0020F0 700014F0 AFA40020 */   sw    $a0, 0x20($sp)
/* 0020F4 700014F4 0C0039DB */  jal   osSpTaskStartGo
/* 0020F8 700014F8 8FA40020 */   lw    $a0, 0x20($sp)
/* 0020FC 700014FC 8FA80028 */  lw    $t0, 0x28($sp)
/* 002100 70001500 16110002 */  bne   $s0, $s1, .L7000150C
/* 002104 70001504 AD1000C8 */   sw    $s0, 0xc8($t0)
/* 002108 70001508 AD1100CC */  sw    $s1, 0xcc($t0)
.L7000150C:
/* 00210C 7000150C 52200010 */  beql  $s1, $zero, .L70001550
/* 002110 70001510 8FBF001C */   lw    $ra, 0x1c($sp)
/* 002114 70001514 5230000E */  beql  $s1, $s0, .L70001550
/* 002118 70001518 8FBF001C */   lw    $ra, 0x1c($sp)
/* 00211C 7000151C 8E29003C */  lw    $t1, 0x3c($s1)
/* 002120 70001520 8E240038 */  lw    $a0, 0x38($s1)
/* 002124 70001524 8D260000 */  lw    $a2, ($t1)
/* 002128 70001528 0C0039EC */  jal   osDpSetNextBuffer
/* 00212C 7000152C 8D270004 */   lw    $a3, 4($t1)
/* 002130 70001530 240A0001 */  li    $t2, 1
/* 002134 70001534 3C018002 */  lui   $at, %hi(setby_DPCfill_0)
/* 002138 70001538 8FAB0028 */  lw    $t3, 0x28($sp)
/* 00213C 7000153C AC2A30A8 */  sw    $t2, %lo(setby_DPCfill_0)($at)
/* 002140 70001540 3C018002 */  lui   $at, %hi(setby_DPCfill_1)
/* 002144 70001544 AC2030AC */  sw    $zero, %lo(setby_DPCfill_1)($at)
/* 002148 70001548 AD7100CC */  sw    $s1, 0xcc($t3)
/* 00214C 7000154C 8FBF001C */  lw    $ra, 0x1c($sp)
.L70001550:
/* 002150 70001550 8FB00014 */  lw    $s0, 0x14($sp)
/* 002154 70001554 8FB10018 */  lw    $s1, 0x18($sp)
/* 002158 70001558 03E00008 */  jr    $ra
/* 00215C 7000155C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

/**
 * 2160	70001560
 */

void __scYield(OSSched *sc) 
{
    if (sc->curRSPTask->list.t.type == M_GFXTASK) {
        sc->curRSPTask->state |= 0x0010;
        osSpTaskYield();
    } else {
      
    }    
}


/**
 * 219C	7000159C
 * ???
 *	uses TLB pointers at 80028400
 *	7000167C	3
 *	70001704	2,6,7
 *	70001758	default; 1,4,5
 */
#ifdef NONMATCHING
void __scSchedule(void) {
    
}
#else
GLOBAL_ASM(
.late_rodata
glabel jpt_80028400
    .word .L70001758
    .word .L70001704
    .word .L7000167C
    .word .L70001758
    .word .L70001758
    .word .L70001704
    .word .L70001704

.text
glabel __scSchedule
/* 00219C 7000159C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0021A0 700015A0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0021A4 700015A4 00808825 */  move  $s1, $a0
/* 0021A8 700015A8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0021AC 700015AC AFB00014 */  sw    $s0, 0x14($sp)
/* 0021B0 700015B0 2408FFFD */  li    $t0, -3
.L700015B4:
/* 0021B4 700015B4 8E2E00D4 */  lw    $t6, 0xd4($s1)
/* 0021B8 700015B8 00E01825 */  move  $v1, $a3
/* 0021BC 700015BC 8E3000BC */  lw    $s0, 0xbc($s1)
/* 0021C0 700015C0 11C00016 */  beqz  $t6, .L7000161C
/* 0021C4 700015C4 8E2200B8 */   lw    $v0, 0xb8($s1)
/* 0021C8 700015C8 30EF0002 */  andi  $t7, $a3, 2
/* 0021CC 700015CC 51E00014 */  beql  $t7, $zero, .L70001620
/* 0021D0 700015D0 02002025 */   move  $a0, $s0
/* 0021D4 700015D4 52000009 */  beql  $s0, $zero, .L700015FC
/* 0021D8 700015D8 ACA20000 */   sw    $v0, ($a1)
/* 0021DC 700015DC 8E180008 */  lw    $t8, 8($s0)
/* 0021E0 700015E0 00E81824 */  and   $v1, $a3, $t0
/* 0021E4 700015E4 33190010 */  andi  $t9, $t8, 0x10
/* 0021E8 700015E8 53200004 */  beql  $t9, $zero, .L700015FC
/* 0021EC 700015EC ACA20000 */   sw    $v0, ($a1)
/* 0021F0 700015F0 10000059 */  b     .L70001758
/* 0021F4 700015F4 ACB00000 */   sw    $s0, ($a1)
/* 0021F8 700015F8 ACA20000 */  sw    $v0, ($a1)
.L700015FC:
/* 0021FC 700015FC 8E2A00B8 */  lw    $t2, 0xb8($s1)
/* 002200 70001600 AE2000D4 */  sw    $zero, 0xd4($s1)
/* 002204 70001604 00E81824 */  and   $v1, $a3, $t0
/* 002208 70001608 8D4B0000 */  lw    $t3, ($t2)
/* 00220C 7000160C 15600052 */  bnez  $t3, .L70001758
/* 002210 70001610 AE2B00B8 */   sw    $t3, 0xb8($s1)
/* 002214 70001614 10000050 */  b     .L70001758
/* 002218 70001618 AE2000C0 */   sw    $zero, 0xc0($s1)
.L7000161C:
/* 00221C 7000161C 02002025 */  move  $a0, $s0
.L70001620:
/* 002220 70001620 AFA30024 */  sw    $v1, 0x24($sp)
/* 002224 70001624 AFA5002C */  sw    $a1, 0x2c($sp)
/* 002228 70001628 AFA60030 */  sw    $a2, 0x30($sp)
/* 00222C 7000162C 0C000478 */  jal   __scTaskReady
/* 002230 70001630 AFA70034 */   sw    $a3, 0x34($sp)
/* 002234 70001634 8FA30024 */  lw    $v1, 0x24($sp)
/* 002238 70001638 8FA5002C */  lw    $a1, 0x2c($sp)
/* 00223C 7000163C 8FA60030 */  lw    $a2, 0x30($sp)
/* 002240 70001640 8FA70034 */  lw    $a3, 0x34($sp)
/* 002244 70001644 2408FFFD */  li    $t0, -3
/* 002248 70001648 10400043 */  beqz  $v0, .L70001758
/* 00224C 7000164C 2409FFFE */   li    $t1, -2
/* 002250 70001650 8E0D0008 */  lw    $t5, 8($s0)
/* 002254 70001654 31AE0007 */  andi  $t6, $t5, 7
/* 002258 70001658 25CFFFFF */  addiu $t7, $t6, -1
/* 00225C 7000165C 2DE10007 */  sltiu $at, $t7, 7
/* 002260 70001660 1020003D */  beqz  $at, .L70001758
/* 002264 70001664 000F7880 */   sll   $t7, $t7, 2
/* 002268 70001668 3C018003 */  lui   $at, %hi(jpt_80028400)
/* 00226C 7000166C 002F0821 */  addu  $at, $at, $t7
/* 002270 70001670 8C2F8400 */  lw    $t7, %lo(jpt_80028400)($at) # lw    $t7, -0x7c00($at)
/* 002274 70001674 01E00008 */  jr    $t7
/* 002278 70001678 00000000 */   nop   
.L7000167C:
/* 00227C 7000167C 8E180004 */  lw    $t8, 4($s0)
/* 002280 70001680 30EA0002 */  andi  $t2, $a3, 2
/* 002284 70001684 24010003 */  li    $at, 3
/* 002288 70001688 33190020 */  andi  $t9, $t8, 0x20
/* 00228C 7000168C 13200011 */  beqz  $t9, .L700016D4
/* 002290 70001690 00000000 */   nop   
/* 002294 70001694 11400030 */  beqz  $t2, .L70001758
/* 002298 70001698 00000000 */   nop   
/* 00229C 7000169C ACB00000 */  sw    $s0, ($a1)
/* 0022A0 700016A0 8E0B0004 */  lw    $t3, 4($s0)
/* 0022A4 700016A4 00E81824 */  and   $v1, $a3, $t0
/* 0022A8 700016A8 316C0001 */  andi  $t4, $t3, 1
/* 0022AC 700016AC 51800004 */  beql  $t4, $zero, .L700016C0
/* 0022B0 700016B0 8E2D00BC */   lw    $t5, 0xbc($s1)
/* 0022B4 700016B4 ACD00000 */  sw    $s0, ($a2)
/* 0022B8 700016B8 00691824 */  and   $v1, $v1, $t1
/* 0022BC 700016BC 8E2D00BC */  lw    $t5, 0xbc($s1)
.L700016C0:
/* 0022C0 700016C0 8DAE0000 */  lw    $t6, ($t5)
/* 0022C4 700016C4 15C00024 */  bnez  $t6, .L70001758
/* 0022C8 700016C8 AE2E00BC */   sw    $t6, 0xbc($s1)
/* 0022CC 700016CC 10000022 */  b     .L70001758
/* 0022D0 700016D0 AE2000C4 */   sw    $zero, 0xc4($s1)
.L700016D4:
/* 0022D4 700016D4 14E10020 */  bne   $a3, $at, .L70001758
/* 0022D8 700016D8 00000000 */   nop   
/* 0022DC 700016DC ACD00000 */  sw    $s0, ($a2)
/* 0022E0 700016E0 ACB00000 */  sw    $s0, ($a1)
/* 0022E4 700016E4 8E3800BC */  lw    $t8, 0xbc($s1)
/* 0022E8 700016E8 2401FFFC */  li    $at, -4
/* 0022EC 700016EC 00E11824 */  and   $v1, $a3, $at
/* 0022F0 700016F0 8F190000 */  lw    $t9, ($t8)
/* 0022F4 700016F4 17200018 */  bnez  $t9, .L70001758
/* 0022F8 700016F8 AE3900BC */   sw    $t9, 0xbc($s1)
/* 0022FC 700016FC 10000016 */  b     .L70001758
/* 002300 70001700 AE2000C4 */   sw    $zero, 0xc4($s1)
.L70001704:
/* 002304 70001704 8E020004 */  lw    $v0, 4($s0)
/* 002308 70001708 30EC0002 */  andi  $t4, $a3, 2
/* 00230C 7000170C 304B0002 */  andi  $t3, $v0, 2
/* 002310 70001710 11600006 */  beqz  $t3, .L7000172C
/* 002314 70001714 304D0001 */   andi  $t5, $v0, 1
/* 002318 70001718 1180000F */  beqz  $t4, .L70001758
/* 00231C 7000171C 00000000 */   nop   
/* 002320 70001720 ACB00000 */  sw    $s0, ($a1)
/* 002324 70001724 1000000C */  b     .L70001758
/* 002328 70001728 00E81824 */   and   $v1, $a3, $t0
.L7000172C:
/* 00232C 7000172C 11A0000A */  beqz  $t5, .L70001758
/* 002330 70001730 30EE0001 */   andi  $t6, $a3, 1
/* 002334 70001734 11C00008 */  beqz  $t6, .L70001758
/* 002338 70001738 00000000 */   nop   
/* 00233C 7000173C ACD00000 */  sw    $s0, ($a2)
/* 002340 70001740 8E2F00BC */  lw    $t7, 0xbc($s1)
/* 002344 70001744 00E91824 */  and   $v1, $a3, $t1
/* 002348 70001748 8DF80000 */  lw    $t8, ($t7)
/* 00234C 7000174C 17000002 */  bnez  $t8, .L70001758
/* 002350 70001750 AE3800BC */   sw    $t8, 0xbc($s1)
/* 002354 70001754 AE2000C4 */  sw    $zero, 0xc4($s1)
.L70001758:
/* 002358 70001758 50670004 */  beql  $v1, $a3, .L7000176C
/* 00235C 7000175C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 002360 70001760 1000FF94 */  b     .L700015B4
/* 002364 70001764 00603825 */   move  $a3, $v1
/* 002368 70001768 8FBF001C */  lw    $ra, 0x1c($sp)
.L7000176C:
/* 00236C 7000176C 8FB00014 */  lw    $s0, 0x14($sp)
/* 002370 70001770 8FB10018 */  lw    $s1, 0x18($sp)
/* 002374 70001774 27BD0028 */  addiu $sp, $sp, 0x28
/* 002378 70001778 03E00008 */  jr    $ra
/* 00237C 7000177C 00601025 */   move  $v0, $v1
)
#endif

