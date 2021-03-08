#include <ultra64.h>
#include "bondgame.h"
#include "boot.h"
#include "sched.h"
#include "rmon.h"
#include "tlb_resolve.h"
#include "tlb_hardwire.h"
#include "init.h"

/**
 * @file init.c
 * This file contains the initial non bootstrap code ran. 
 * 
 * In particular, it:
 *   - unpacks main data payload
 *   - starts idle and rmon loops
 *   - starts main loop
 */

#define NUM_FIELDS  1

u32 unknown_val_80023040 = 0;
/*D:80023044*/
u32 unknown_init_val = 2;

u32 cart_hw_address = 0x10000000;

struct debug_handler_entry debug_handler_table[] = 
{
    {sp_boot, "boot"},
    {sp_rmon, "rmon"},
    {sp_idle, "idle"},
    {sp_shed, "shed"},
    {sp_main, "main"},
    {sp_audi, "audi"},
    {0, 0},
    {0, 0},
};

OSThread rmonThread;
OSThread idleThread;
OSThread mainThread;
OSThread shedThread;
OSMesgQueue gfxFrameMsgQ;
OSMesg gfxFrameMsgBuf[32];
OSMesgQueue *sched_cmdQ;

void mainproc(void *args);

extern u8 * _rarezipSegmentStart;


u32         osPiGetStatus(void);
void __osSetFpcCsr(u32);
u32 __osGetFpcCsr(void);
/**
 * 1110	70000510
 * ???	initializes TLB index...
 *	copies compressed 21990 to virtual address 701EE400, using 70200000 to decompress
 */
#ifdef NONMATCHING
void init(void)
{
    u32 src = get_csegmentSegmentStart();
    u32 datastart = get_cdataSegmentRomStart();
    u32 datacomplen = (get_cdataSegmentRomEnd() - datastart);
    u32 inflatestart = get_rarezipSegmentRomStart();
    u32 inflatelen = (get_rarezipSegmentRomEnd() - inflatestart);
    u32 dst = &_rarezipSegmentRomStart - datacomplen;
    u32 j;
    s32 i;

	for (i = datacomplen + inflatelen - 1; (i >= 0); i--)
    {
		((u8 *)dst)[i] = ((u8 *)src)[i];
	}

    jump_decompressfile(dst, src, 0x80300000);
    if (1)
    {
        if ((&_rarezipSegmentRomStart - &_codeSegmentRomStart) >= 0xfffb1)
        {
            osPiRawStartDma(0, 0x101000, 0x70100400, ((&_rarezipSegmentRomStart - &_codeSegmentRomStart) + 0xfff00050));
            while ((osPiGetStatus() & 1) != 0) {}
        }

        osInitialize();
        set_hardwire_TLB_to_2();
    }


	//IM BROKEN FIX ME!!!!!!!
	//src = (u32 *)resolve_TLBaddress_for_InvalidHit;
	//UT_VEC
	//dst = (u32 *)0x80000000;
	//XUT_VEC
    //while ( (u32)dst != (u32)dst + 0x80 ) { *dst = *src; dst++; src++;}
	//TO HERE
    while( i < 0x80)
    {
		((u32 *)0x80000000)[i++] = ((u32 *)&resolve_TLBaddress_for_InvalidHit)[i++];
	}


    osWritebackDCacheAll();
    osInvalICache(0x80000000, 0x4000);

	for (i=2; i<32; i++)
    {
		osUnmapTLB(i);
	}

    __osSetFpcCsr((__osGetFpcCsr() | 0xe80));
    osCreateThread(&mainThread, 3, &mainproc, 0, set_stack_entry(&sp_main, 0x8000), 0xa);
    osStartThread(&mainThread);
}

#else
GLOBAL_ASM(
.section .text
glabel init
/* 001110 70000510 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 001114 70000514 AFBF0024 */  sw    $ra, 0x24($sp)
/* 001118 70000518 AFB10020 */  sw    $s1, 0x20($sp)
/* 00111C 7000051C 0C00012F */  jal   get_csegmentSegmentStart
/* 001120 70000520 AFB0001C */   sw    $s0, 0x1c($sp)
/* 001124 70000524 0C000132 */  jal   get_cdataSegmentRomStart
/* 001128 70000528 00408025 */   move  $s0, $v0
/* 00112C 7000052C 0C000135 */  jal   get_cdataSegmentRomEnd
/* 001130 70000530 AFA20034 */   sw    $v0, 0x34($sp)
/* 001134 70000534 8FAE0034 */  lw    $t6, 0x34($sp)
/* 001138 70000538 0C000138 */  jal   get_rarezipSegmentRomStart
/* 00113C 7000053C 004E8823 */   subu  $s1, $v0, $t6
/* 001140 70000540 0C00013B */  jal   get_rarezipSegmentRomEnd
/* 001144 70000544 AFA20028 */   sw    $v0, 0x28($sp)
/* 001148 70000548 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00114C 7000054C 3C0A7020 */  lui   $t2, 0x7020
/* 001150 70000550 02002825 */  move  $a1, $s0
/* 001154 70000554 004FC023 */  subu  $t8, $v0, $t7
/* 001158 70000558 02382021 */  addu  $a0, $s1, $t8
/* 00115C 7000055C 2483FFFF */  addiu $v1, $a0, -1
/* 001160 70000560 0460000A */  bltz  $v1, .L7000058C
/* 001164 70000564 3C068030 */   lui   $a2, 0x8030
/* 001168 70000568 3C197020 */  lui   $t9, 0x7020
/* 00116C 7000056C 03312023 */  subu  $a0, $t9, $s1
/* 001170 70000570 02031021 */  addu  $v0, $s0, $v1
.L70000574:
/* 001174 70000574 90480000 */  lbu   $t0, ($v0)
/* 001178 70000578 00834821 */  addu  $t1, $a0, $v1
/* 00117C 7000057C 2463FFFF */  addiu $v1, $v1, -1
/* 001180 70000580 2442FFFF */  addiu $v0, $v0, -1
/* 001184 70000584 0461FFFB */  bgez  $v1, .L70000574
/* 001188 70000588 A1280000 */   sb    $t0, ($t1)
.L7000058C:
/* 00118C 7000058C 0C00013E */  jal   jump_decompressfile
/* 001190 70000590 01512023 */   subu  $a0, $t2, $s1
/* 001194 70000594 3C0B0003 */  lui   $t3, %hi(_rarezipSegmentRomStart) # $t3, 3
/* 001198 70000598 3C0C0000 */  lui   $t4, %hi(_codeSegmentRomStart) # $t4, 0
/* 00119C 7000059C 258C1050 */  addiu $t4, %lo(_codeSegmentRomStart) # addiu $t4, $t4, 0x1050
/* 0011A0 700005A0 256B3590 */  addiu $t3, %lo(_rarezipSegmentRomStart) # addiu $t3, $t3, 0x3590
/* 0011A4 700005A4 3C01000F */  lui   $at, (0x000FFFB1 >> 16) # lui $at, 0xf
/* 0011A8 700005A8 3421FFB1 */  ori   $at, (0x000FFFB1 & 0xFFFF) # ori $at, $at, 0xffb1
/* 0011AC 700005AC 016C1023 */  subu  $v0, $t3, $t4
/* 0011B0 700005B0 0041082A */  slt   $at, $v0, $at
/* 0011B4 700005B4 14200013 */  bnez  $at, .L70000604
/* 0011B8 700005B8 3C01FFF0 */   lui   $at, (0xFFF00050 >> 16) # lui $at, 0xfff0
/* 0011BC 700005BC 34210050 */  ori   $at, (0xFFF00050 & 0xFFFF) # ori $at, $at, 0x50
/* 0011C0 700005C0 3C050010 */  lui   $a1, %hi(0x00101000) # $a1, 0x10
/* 0011C4 700005C4 3C067010 */  lui   $a2, %hi(0x70100400) # $a2, 0x7010
/* 0011C8 700005C8 24C60400 */  addiu $a2, %lo(0x70100400) # addiu $a2, $a2, 0x400
/* 0011CC 700005CC 24A51000 */  addiu $a1, %lo(0x00101000) # addiu $a1, $a1, 0x1000
/* 0011D0 700005D0 00413821 */  addu  $a3, $v0, $at
/* 0011D4 700005D4 0C0033E4 */  jal   osPiRawStartDma
/* 0011D8 700005D8 00002025 */   move  $a0, $zero
/* 0011DC 700005DC 0C00341C */  jal   osPiGetStatus
/* 0011E0 700005E0 00000000 */   nop   
/* 0011E4 700005E4 304D0001 */  andi  $t5, $v0, 1
/* 0011E8 700005E8 11A00006 */  beqz  $t5, .L70000604
/* 0011EC 700005EC 00000000 */   nop   
.L700005F0:
/* 0011F0 700005F0 0C00341C */  jal   osPiGetStatus
/* 0011F4 700005F4 00000000 */   nop   
/* 0011F8 700005F8 304E0001 */  andi  $t6, $v0, 1
/* 0011FC 700005FC 15C0FFFC */  bnez  $t6, .L700005F0
/* 001200 70000600 00000000 */   nop   
.L70000604:
/* 001204 70000604 0C003420 */  jal   osInitialize
/* 001208 70000608 00000000 */   nop   
/* 00120C 7000060C 0C0006EC */  jal   set_hardwire_TLB_to_2
/* 001210 70000610 00000000 */   nop   


/* 001214 70000614 3C108000 */  lui   $s0, %hi(0x80000000)
/* 001218 70000618 3C027000 */  lui   $v0, %hi(resolve_TLBaddress_for_InvalidHit) # $v0, 0x7000
/* 00121C 7000061C 3C048000 */  lui   $a0, (0x80000080 >> 16) # lui $a0, 0x8000
/* 001220 70000620 24421B60 */  addiu $v0, %lo(resolve_TLBaddress_for_InvalidHit) # addiu $v0, $v0, 0x1b60
/* 001224 70000624 02001825 */  move  $v1, $s0
/* 001228 70000628 34840080 */  ori   $a0, (0x80000080 & 0xFFFF) # ori $a0, $a0, 0x80
.L7000062C:
/* 00122C 7000062C 8C4F0000 */  lw    $t7, ($v0)
/* 001230 70000630 24630010 */  addiu $v1, $v1, 0x10
/* 001234 70000634 24420010 */  addiu $v0, $v0, 0x10
/* 001238 70000638 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 00123C 7000063C 8C58FFF4 */  lw    $t8, -0xc($v0)
/* 001240 70000640 AC78FFF4 */  sw    $t8, -0xc($v1)
/* 001244 70000644 8C59FFF8 */  lw    $t9, -8($v0)
/* 001248 70000648 AC79FFF8 */  sw    $t9, -8($v1)
/* 00124C 7000064C 8C48FFFC */  lw    $t0, -4($v0)
/* 001250 70000650 1464FFF6 */  bne   $v1, $a0, .L7000062C
/* 001254 70000654 AC68FFFC */   sw    $t0, -4($v1)


/* 001258 70000658 0C0034C8 */  jal   osWritebackDCacheAll
/* 00125C 7000065C 00000000 */   nop   
/* 001260 70000660 02002025 */  move  $a0, $s0
/* 001264 70000664 0C0034D4 */  jal   osInvalICache
/* 001268 70000668 24054000 */   li    $a1, 16384
/* 00126C 7000066C 24100002 */  li    $s0, 2
/* 001270 70000670 24110020 */  li    $s1, 32
.L70000674:
/* 001274 70000674 0C0034F4 */  jal   osUnmapTLB
/* 001278 70000678 02002025 */   move  $a0, $s0
/* 00127C 7000067C 26100001 */  addiu $s0, 1 # addiu $s0, $s0, 1
/* 001280 70000680 1611FFFC */  bne   $s0, $s1, .L70000674
/* 001284 70000684 00000000 */   nop   
/* 001288 70000688 0C003504 */  jal   __osGetFpcCsr
/* 00128C 7000068C 00000000 */   nop   
/* 001290 70000690 0C003508 */  jal   __osSetFpcCsr
/* 001294 70000694 34440E80 */   ori   $a0, $v0, 0xe80
/* 001298 70000698 3C04803B */  lui   $a0, %hi(sp_main) # $a0, 0x803b
/* 00129C 7000069C 2484B950 */  addiu $a0, %lo(sp_main) # addiu $a0, $a0, -0x46b0
/* 0012A0 700006A0 0C0001BC */  jal   set_stack_entry
/* 0012A4 700006A4 34058000 */   li    $a1, 32768
/* 0012A8 700006A8 3C108006 */  lui   $s0, %hi(mainThread)
/* 0012AC 700006AC 2610D640 */  addiu $s0, %lo(mainThread) # addiu $s0, $s0, -0x29c0
/* 0012B0 700006B0 3C067000 */  lui   $a2, %hi(mainproc) # $a2, 0x7000
/* 0012B4 700006B4 240C000A */  li    $t4, 10
/* 0012B8 700006B8 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0012BC 700006BC 24C6089C */  addiu $a2, %lo(mainproc) # addiu $a2, $a2, 0x89c
/* 0012C0 700006C0 02002025 */  move  $a0, $s0
/* 0012C4 700006C4 24050003 */  li    $a1, 3
/* 0012C8 700006C8 00003825 */  move  $a3, $zero
/* 0012CC 700006CC 0C00350C */  jal   osCreateThread
/* 0012D0 700006D0 AFA20010 */   sw    $v0, 0x10($sp)
/* 0012D4 700006D4 0C003560 */  jal   osStartThread
/* 0012D8 700006D8 02002025 */   move  $a0, $s0
/* 0012DC 700006DC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0012E0 700006E0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0012E4 700006E4 8FB10020 */  lw    $s1, 0x20($sp)
/* 0012E8 700006E8 03E00008 */  jr    $ra
/* 0012EC 700006EC 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

/**
 * 12F0	700006F0
 * V0= new stack pointer; A0+A1-8
 *	accepts: A0=base address, A1=size
 */
void *set_stack_entry(u8 *stack, u32 size) 
{
    return stack+size-8;
}

/**
 * 12FC	700006FC
 * 1->80023044, 10000000->80023048
 */
void set_hw_address_and_unknown(void) 
{
    unknown_init_val = 1;
    cart_hw_address = 0x10000000;
}

/**
 * 1318	70000718
 * A0->SP+0, infinite loop
 */
void idleproc(void *arg) 
{
	for (;;);
}

/**
 * 1338	70000738
 * Null thread; executes 70000718
 */
void idleCreateThread(void) 
{
    osCreateThread(&idleThread, (OSId)1, idleproc, 0, set_stack_entry(&sp_idle, 0x40), (OSPri)0);
    osStartThread(&idleThread);
}

/**
 * 1390	70000790
 * Indi board detection thread; now forcably returns INDI_NOT_DETECTED (1)
 */
void rmonCreateThread(void) 
{
    osCreateThread(&rmonThread, (OSId)0, rmonMain, 0, set_stack_entry(&sp_rmon, 0x300), (OSPri)250);
    osStartThread(&rmonThread);
}

/**
 * 13EC	700007EC
 */
void schedulerInitThread(void)
{
    osCreateMesgQueue(&gfxFrameMsgQ, &gfxFrameMsgBuf, 32);
    if (osTvType == 2) //OS_TV_MPAL
    { 
        osCreateScheduler(&sc, &shedThread, OS_VI_MPAL_LAN1, NUM_FIELDS);
    }
    else 
    {
        osCreateScheduler(&sc, &shedThread, OS_VI_NTSC_LAN1, NUM_FIELDS);
	}

    osScAddClient(&sc, &gfxClient, &gfxFrameMsgQ, 0);
    sched_cmdQ = osScGetCmdQ(&sc);
}

/**
 * 149C	7000089C	datastart main game setup and loop
 *	calls command line parser, debug console setup, etc.
 *	called by 70000510, using 7000D430: A0=8005D640, A1=3, A2=7000089C, A3=0, SP+10=[803B3948], SP+14=0xA
 *	never returns; 7000601C is an infinite loop
 */
void mainproc(void *args)
{
	idleCreateThread();
	viDebugRemoved();
	piCreateManager();
	rmonCreateThread();
	if (tokenReadIo() != 0)
	{
		osStopThread(0);
	}
	
    osSetThreadPri(0, 0xa);
    schedulerInitThread();
    bossEntry();
}

/**
 * 1508	70000908	V0= p->last entry in copy of debug handler code/name table; fries AT,V1,T0,T1,T6,T9
 *	copies table from 8002304C-80023084 to stack
 */
#ifdef NONMATCHING
void setuplastentryofdebughandler(void)
{
    ? sp8;
    void *temp_t6;
    void *temp_t0;
    void *temp_v0;
    void *phi_t6;
    void *phi_t0;
    void *phi_v0;

    phi_t6 = &debug_handler_table;
    phi_t0 = &sp8;
loop_1:
    temp_t6 = (phi_t6 + 0xc);
    temp_t0 = (phi_t0 + 0xc);
    temp_t0->unk-C = (?32) *phi_t6;
    temp_t0->unk-8 = (?32) temp_t6->unk-8;
    temp_t0->unk-4 = (?32) temp_t6->unk-4;
    phi_t6 = temp_t6;
    phi_t0 = temp_t0;
    if (temp_t6 != (&debug_handler_table + 0x30))
    {
        goto loop_1;
    }
    *temp_t0 = (?32) *temp_t6;
    temp_t0->unk4 = (?32) temp_t6->unk4;
    phi_v0 = &sp8;
loop_3:
    temp_v0 = (phi_v0 + 8);
    phi_v0 = temp_v0;
    if (phi_v0->unk8 != 0)
    {
        goto loop_3;
    }
    return temp_v0;
}
#else
GLOBAL_ASM(
.section .text
glabel setuplastentryofdebughandler
/* 001508 70000908 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00150C 7000090C 3C0E8002 */  lui   $t6, %hi(debug_handler_table) 
/* 001510 70000910 27A30008 */  addiu $v1, $sp, 8
/* 001514 70000914 25CE304C */  addiu $t6, %lo(debug_handler_table) # addiu $t6, $t6, 0x304c
/* 001518 70000918 25D90030 */  addiu $t9, $t6, 0x30
/* 00151C 7000091C 00604025 */  move  $t0, $v1
.L70000920:
/* 001520 70000920 8DC10000 */  lw    $at, ($t6)
/* 001524 70000924 25CE000C */  addiu $t6, $t6, 0xc
/* 001528 70000928 2508000C */  addiu $t0, $t0, 0xc
/* 00152C 7000092C AD01FFF4 */  sw    $at, -0xc($t0)
/* 001530 70000930 8DC1FFF8 */  lw    $at, -8($t6)
/* 001534 70000934 AD01FFF8 */  sw    $at, -8($t0)
/* 001538 70000938 8DC1FFFC */  lw    $at, -4($t6)
/* 00153C 7000093C 15D9FFF8 */  bne   $t6, $t9, .L70000920
/* 001540 70000940 AD01FFFC */   sw    $at, -4($t0)
/* 001544 70000944 8DC10000 */  lw    $at, ($t6)
/* 001548 70000948 00601025 */  move  $v0, $v1
/* 00154C 7000094C AD010000 */  sw    $at, ($t0)
/* 001550 70000950 8DD90004 */  lw    $t9, 4($t6)
/* 001554 70000954 AD190004 */  sw    $t9, 4($t0)
/* 001558 70000958 8C490008 */  lw    $t1, 8($v0)
.L7000095C:
/* 00155C 7000095C 24420008 */  addiu $v0, $v0, 8
/* 001560 70000960 5520FFFE */  bnezl $t1, .L7000095C
/* 001564 70000964 8C490008 */   lw    $t1, 8($v0)
/* 001568 70000968 03E00008 */  jr    $ra
/* 00156C 7000096C 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
