#include <ultra64.h>
#include <PR/R4300.h>
#include <PR/os.h>
#include <PR/os_internal.h>
#include <PR/rcp.h>
#include <bondgame.h>
#include "boot.h"
#include "sched.h"
#include "rmon.h" /*<PR/rmon.h>*/
#include "tlb_resolve.h"
#include "tlb_hardwire.h"
#include "init.h"
#include "thread_config.h"

#include "usb.h"

/**
 * EU .data, offset from start of data_seg : 0x22B0
*/

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

#define MAXSP 7

#define RZIPLOADADDR 0x70200000
#define RZIPBUFADDR 0x80300000

#define MAXCODESIZE (0x101000 - 0x1050) 


/**
 * These 3 values (likely more as u32 piDeviceType = DEVICE_TYPE_CART could be 4x u8)
 * piDeviceType is completely unused but the most logical value here
 * piStatusReg, and piDomAddr are explicitly stored as 32bit values
*/
u32 piDeviceType = DEVICE_TYPE_CART;
u32 piStatusReg = PI_CLR_INTR;
u32 piDomAddr = PI_DOM1_ADDR2;

union debug_handler_container
{
    /* There is a bulk memory copy of debug_handler_table,
    * it seems to require a container with a known size,
    * which doesn't seem correct ....
    */
    struct debug_handler_entry rows[MAXSP];
    s32 data[MAXSP * 2];
};

union debug_handler_container debug_handler_table = {
    {
        {sp_boot, "boot"},
        {sp_rmon, "rmon"},
        {sp_idle, "idle"},
        {sp_shed, "shed"},
        {sp_main, "main"},
        {sp_audi, "audi"},
        {0, 0}
    }
};

OSThread rmonThread;
OSThread idleThread;
OSThread mainThread;
OSThread shedThread;
OSMesgQueue gfxFrameMsgQ;
OSMesg gfxFrameMsgBuf[32];
OSMesgQueue *sched_cmdQ;

void mainproc(void *args);



/**
 * 1110	70000510
 * init - The real main entry point, called from boot.s
 * Deflates the compressed data segment
 * Installs the TLB miss handler
 * Then starts the main thread
 */
void init(void)
{
    u32 inflateromSize;
    u8 *csegmentSegmentVaddrStart;
    u8 *cdataSegmentRomStart;
    u32 flags;
    u32 cdataSegmentRomSize;
    u8 *inflateSegmentRomStart;
    s32 i;
    s32 j;

    u8 *datazipram;
    s32 inflate_code_size;
    u32 decompress_result;
    s32 *dest;
    s32 *src;
    u32 copylen;
    s32 *stack_pointer;
    u8 *dataziprom;

    csegmentSegmentVaddrStart = get_csegmentSegmentStart();
    cdataSegmentRomStart = get_cdataSegmentRomStart();
    cdataSegmentRomSize = (u8 *) get_cdataSegmentRomEnd() - cdataSegmentRomStart;
    inflateSegmentRomStart = get_inflateSegmentRomStart();
    inflateromSize = (u8 *) get_inflateSegmentRomEnd() - inflateSegmentRomStart;
    copylen = cdataSegmentRomSize + inflateromSize;
    datazipram = (u8 *) (RZIPLOADADDR - cdataSegmentRomSize);
    dataziprom = csegmentSegmentVaddrStart;

    for (j = copylen - 1; j >= 0; j--)
    {
        datazipram[j] = dataziprom[j];
    }

    decompress_result = jump_decompressfile(datazipram, csegmentSegmentVaddrStart, RZIPBUFADDR);
    if (decompress_result);

    inflate_code_size = (s32) ((u32) &_inflateSegmentRomStart - (u32) &_codeSegmentRomStart);
    if (inflate_code_size > MAXCODESIZE)
    {
        osPiRawStartDma(OS_READ, &_alt_startSegmentRomStart, &_alt_startSegmentStart, inflate_code_size - MAXCODESIZE);
        while ((osPiGetStatus() & PI_STATUS_DMA_BUSY))
        {
        }
    }

    osInitialize();

    // This sets up TLB CONTEXT to allow the TLB miss handler to work
    initTLBPrepareContext();

    // Copy the TLB miss handler to proper place
    src = &resolve_TLBaddress_for_InvalidHit;
    dest = (s32 *) K0BASE;
    while (dest < (s32 *) XUT_VEC)
    {
        *dest++ = *src++;
    }

    // Refresh Cache
    osWritebackDCacheAll();
    osInvalICache((void *) K0BASE, ICACHE_SIZE);

    // Cleanup TLB
    for (i = 2; i < NTLBENTRIES + 1; i++)
    {
        osUnmapTLB(i);
    }

    // Setup floating point register
    flags = __osGetFpcCsr();
    flags |= FPCSR_EI; // enable inexact operation
    flags |= FPCSR_EO; // enable overflow
    flags |= FPCSR_EZ; // enable division by zero
    flags |= FPCSR_EV; // enable invalid operation
    __osSetFpcCsr(flags);

    stack_pointer = setSPToEnd(sp_main, sizeof(sp_main));
    osCreateThread(&mainThread, MAIN_THREAD_ID, &mainproc, NULL, stack_pointer, MAIN_THREAD_PRIORITY);
    osStartThread(&mainThread);
}



/**
 * 12F0	700006F0
 * setSPToEnd - set stack pointer to end of stack
 * @param stack
 * @param size
 * @return stack+size-8
 */
void *setSPToEnd(u8 *stack, u32 size)
{
    return stack + size - 8;
}

/**
 * 12FC	700006FC
 * piStatusRegReset - set PI status register to trigger a reset
 * This is unused and is leftover from Indy debug,
 */
void piStatusRegReset(void)
{
    piStatusReg = PI_SET_RESET;
    piDomAddr = PI_DOM1_ADDR2;
}

/**
 * 1318	70000718
 * idleproc - infinite loop
 * @param arg doesn't matter as this is infinite loop
 */
void idleproc(void *arg)
{
    for (;;);
}

/**
 * 1338	70000738
 * idleCreateThread - creates an empty thread;
 */
void idleCreateThread(void)
{
    osCreateThread(&idleThread, IDLE_THREAD_ID, idleproc, NULL, setSPToEnd(&sp_idle, sizeof(sp_idle)), IDLE_THREAD_PRIORITY);
    osStartThread(&idleThread);
}

/**
 * 1390	70000790
 * rmonCreateThread - remote communication thread
 * rmonMain now forcably returns INDI_NOT_DETECTED (1)
 */
void rmonCreateThread(void)
{
    osCreateThread(&rmonThread, RMON_THREAD_ID, rmonMain, NULL, setSPToEnd(&sp_rmon, sizeof(sp_rmon)), RMON_THREAD_PRIORITY);
    osStartThread(&rmonThread);
}

/**
 * 13EC	700007EC
 * schedulerInitThread - create scheduler thread based on TV type
 */
void schedulerInitThread(void)
{
    osCreateMesgQueue(&gfxFrameMsgQ, &gfxFrameMsgBuf, 32);
    if (osTvType == OS_TV_MPAL)
    {
        osCreateScheduler(&os_scheduler, &shedThread, OS_VI_MPAL_LAN1, NUM_FIELDS);
    }
    else
    {
        osCreateScheduler(&os_scheduler, &shedThread, OS_VI_NTSC_LAN1, NUM_FIELDS);
    }

    osScAddClient(&os_scheduler, &gfxClient, &gfxFrameMsgQ, NULL);
    sched_cmdQ = osScGetCmdQ(&os_scheduler);
}

/**
 * 149C	7000089C
 * mainproc - main game setup and loop
 * calls command line parser, debug console setup, etc.
 * @param args
 */
void mainproc(void *args)
{
    idleCreateThread();
    viDebugRemoved();
    piCreateManager();
#ifdef ENABLE_USB
    // make debug print output available as soon as possible.
    // This uses blocking calls, and the PI manager, so can't be called
    // before here.
    usb_initialize();
#else
    rmonCreateThread();
#endif
    if (tokenReadIo())
    {
        osStopThread(RMON_THREAD_ID);
    }

    osSetThreadPri(RMON_THREAD_ID, MAIN_THREAD_PRIORITY);
    // Timers are initialized via:
    // schedulerInitThread -> osCreateScheduler -> osCreateViManager -> __osTimerServicesInit
    schedulerInitThread();
#ifdef ENABLE_USB
    // Unlike the pure source, this version injects a dependency on timer, so can't init
    // before here.
    rmonCreateThread();
#endif
    bossEntry();
}

/**
 * 1508	70000908
 * initDebugHandlerTable - setup debug handler table
 * This is unused and is leftover from Indy debug.
 */
void initDebugHandlerTable(void)
{
    union debug_handler_container dhe;
    struct debug_handler_entry *p;

    dhe = debug_handler_table;

    p = &dhe.rows[0];

    do
    {
        p++;
    } while (p->address != NULL);
}
