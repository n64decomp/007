#include <ultra64.h>
#include "rsp.h"
#include <init.h>
#include <memp.h>
#include <deb.h>
#include <sched.h>
#include <PR/sptask.h>
#include <PR/ucode.h>

#define RSP_MEMP_BANK                   6
#define RSP_MEMP_ALLOC_SIZE_BYTES  0xA000

/**
 * Address 8008D370.
 */
u8 g_gfxDramStack[SP_DRAM_STACK_SIZE8];

/**
 * Address 8008D770.
 */
u8 g_gfxYieldBuf[OS_YIELD_GFX_DATA_SIZE];

/**
 * Address 8004E9E0.
 */
s32 g_gfxDebugEntryData = 0;

/**
 * Address 8004E9E4.
 */
s32 g_gfxRdpOutputBufferEnd = 0;

/**
 * Address 8004E9E8.
 */
s32 g_gfxRdpOutputBufferStart = 0;

/**
 * Address 8004E9EC.
 */
s32 g_unused8004E9EC = 0;

/**
 * Address 8004E9F0.
 */
struct GfxInfo_s g_gfxTaskSettings[2] = 
{
    // 8004EA50
    {
        // next
        NULL,
        
        // state
        0,
        
        // flags
        0, 
        
        // framebuffer
        NULL,

        // list.t.type
        M_GFXTASK,
        
        // list.t.flags
        OS_TASK_DP_WAIT,
        
        // list.t.ucode_boot
        NULL,
        
        // list.t.ucode_boot_size
        0,
        
        // list.t.ucode
        NULL,
        
        // list.t.ucode_size
        SP_UCODE_SIZE,
        
        // list.t.ucode_data
        NULL,
        
        // list.t.ucode_data_size
        SP_UCODE_DATA_SIZE,
        
        // list.t.dram_stack
        (u64 *)&g_gfxDramStack,
        
        // list.t.dram_stack_size
        SP_DRAM_STACK_SIZE8,
        
        // list.t.output_buff
        NULL,
        
        // list.t.output_buff_size
        0,
        
        // list.t.data_ptr
        NULL,
        
        // list.t.data_size
        0,
        
        // list.t.yield_data_ptr
        NULL,
        
        // list.t.yield_data_size
        0,
        
        // msgQ
        NULL, 
        
        // msg
        NULL,
        
        // cfb (pointer)
        0,
        
        // unk5C
        0
    },

    // 8004EAB0
    {
        // next
        NULL,
        
        // state
        0,
        
        // flags
        0, 
        
        // framebuffer
        NULL,

        // list.t.type
        M_GFXTASK,
        
        // list.t.flags
        OS_TASK_DP_WAIT,
        
        // list.t.ucode_boot
        NULL,
        
        // list.t.ucode_boot_size
        0,
        
        // list.t.ucode
        NULL,
        
        // list.t.ucode_size
        SP_UCODE_SIZE,
        
        // list.t.ucode_data
        NULL,
        
        // list.t.ucode_data_size
        SP_UCODE_DATA_SIZE,
        
        // list.t.dram_stack
        (u64 *)&g_gfxDramStack,
        
        // list.t.dram_stack_size
        SP_DRAM_STACK_SIZE8,
        
        // list.t.output_buff
        NULL,
        
        // list.t.output_buff_size
        0,
        
        // list.t.data_ptr
        NULL,
        
        // list.t.data_size
        0,
        
        // list.t.yield_data_ptr
        NULL,
        
        // list.t.yield_data_size
        0,
        
        // msgQ
        NULL, 
        
        // msg
        NULL,
        
        // cfb (pointer)
        0,
        
        // unk5C
        0
    },
};

/**
 * Address 8004EAB0.
 * Initialization needs to point this to an item in the g_gfxTaskSettings array
 * otherwise rspGfxTaskStart will fail.
 */
struct GfxInfo_s *g_gfxTaskSettingsList = &g_gfxTaskSettings[0];

extern long long int rspbootTextStart[];
extern long long int rspbootTextEnd[];
extern long long int gsp3DTextStart[];
extern long long int gsp3DDataStart[];

void rspInit(void)
{
    debTryAdd(&g_gfxDebugEntryData, "rsp_c_debug");
}

void rspAllocateBuffers(void)
{
    g_gfxRdpOutputBufferStart = mempAllocBytesInBank(RSP_MEMP_ALLOC_SIZE_BYTES, RSP_MEMP_BANK);
    g_gfxRdpOutputBufferEnd = g_gfxRdpOutputBufferStart + RSP_MEMP_ALLOC_SIZE_BYTES;
}

/**
 * Has similarities to:
 * createGfxTask from n64devkit\ultra\usr\src\pr\demos_old\simple\gfx.c
 * gfxTaskStart from n64devkit\ultra\usr\src\pr\demos_old\nnsample2\graphic.c
 */
void rspGfxTaskStart(Gfx *firstGdl, Gfx *gdl, s32 arg2, OSMesg rspReplyMsg)
{
    OSScTask *sctask;
    OSTask *task;

    sctask = &((struct GfxInfo_s *)g_gfxTaskSettingsList)->task;
    task = &sctask->list;

    task->t.ucode_boot = (u64*)rspbootTextStart;
    
    // u64 pointers, cast to x32 to avoid (sra _,_,0x3)
    task->t.ucode_boot_size = ((s32)rspbootTextEnd - (s32)rspbootTextStart);

    if (rspbootTextStart);
    
    // task>type = M_GFXTASK, set in bss constructor
    // task->flags = OS_TASK_DP_WAIT, set in bss constructor
    
    task->t.ucode = (u64*)gsp3DTextStart;
    task->t.ucode_data = (u64*)gsp3DDataStart;
    // task->ucode_data_size = SP_UCODE_DATA_SIZE, set in bss constructor
    // task->dram_stack = &g_gfxDramStack, set in bss constructor
    // task->dram_stack_size = SP_DRAM_STACK_SIZE8, set in bss constructor
    task->t.output_buff = (u64 *)g_gfxRdpOutputBufferStart;
    task->t.output_buff_size = (u64 *)g_gfxRdpOutputBufferEnd;
    task->t.data_ptr = (u64 *) firstGdl;
    task->t.data_size = (s32) ((gdl - firstGdl) * sizeof (Gfx)); // u64 pointers, generates sra	t3,t2,0x3
    task->t.yield_data_ptr = (u64 *)&g_gfxYieldBuf;
    task->t.yield_data_size = sizeof(g_gfxYieldBuf);

    sctask->next = NULL;
    sctask->flags = (OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER);

    /* reply to when finished */
    sctask->msgQ = &gfxFrameMsgQ;

    /* reply with this message */
    sctask->msg = rspReplyMsg;

    sctask->framebuffer = (void *) ((struct GfxInfo_s *)g_gfxTaskSettingsList)->cfb;

    osWritebackDCacheAll();

    /* start graphic task */
    osSendMesg(sched_cmdQ, (OSMesg)sctask, OS_MESG_BLOCK);
    
    // Toggles the g_gfxTaskSettingsList to point to altnerate tasks.
    // Depends on first assignment taking place (g_gfxTaskSettingsList = g_gfxTaskSettings[0]).
    // Not a typo, but probably not best practice.
    g_gfxTaskSettingsList = (struct GfxInfo_s *)((u32)g_gfxTaskSettingsList ^ (u32) &g_gfxTaskSettings[0] ^ (u32) &g_gfxTaskSettings[1]);
}

