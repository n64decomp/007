#include <ultra64.h>
#include <PR/os.h>
#include "init.h"
#include "sched.h"
#include <bondgame.h>
#include "crash.h"
#include "fr.h"
#include "joy.h"
#include "music.h"
#include "speed_graph.h"
#include "thread_config.h"

/**
 * EU .data, offset from start of data_seg : 0x2300
*/

/**
 * @file sched.c
 * This file contains the scheduler. 
 * 
 * In particular, it:
 *   - is based on but modified by rare from code included in sdk
 *   - 
 *   - 
 */

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669


#define OS_SC_DP                0x0001
#define OS_SC_SP                0x0002
#define OS_SC_YIELD             0x0010
#define OS_SC_YIELDED           0x0020


#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)

// forward declarations
void __scHandleRetrace(OSSched *sc);
void __scHandleRSP(OSSched *sc);
void __scHandleRDP(OSSched *sc);
void __scMain(void *arg);

u32 stderr_unused = 0;
u32 stderr_enabled = 0;
u32 stderr_active = 0;
u32 stderr_permitted = 0;

/**
 * EU .data, offset from start of data_seg : 0x2310
*/
u32 userCompareValue = 45000000;
u32 currentcount = 0;
u32 dp_busy = 0;
u32 dpCount = 0;
//800230b0
s32 g_schedViCurrentFrameBuffer = 0;
f32 g_ViXScales[NUM_VIDEO_FRAME_BUFFERS] = {1.0, 1.0};
f32 g_ViYScales[NUM_VIDEO_FRAME_BUFFERS] = {1.0, 1.0};
s32 g_ViChangeVideoModes[NUM_VIDEO_FRAME_BUFFERS] = {0, 0}; // boolean

OSSched os_scheduler;
OSScClient gfxClient[3];
u32 g_DisplayPerformanceCounters[4]; // clock, cmc, pipe, tmem

/**
 * EU .bss 0x80051f00.
*/
OSViMode g_ViModes[NUM_VIDEO_FRAME_BUFFERS];
OSViMode *g_ViModePtrs[NUM_VIDEO_FRAME_BUFFERS];

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
		crashRenderFrame(buffer);
		currentcount = osGetCount();
	}
}

/**
 * Address 0x700009F8.
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
				crashRenderFrame((u16*)cfb_16[0]);
				crashRenderFrame((u16*)cfb_16[1]);
			}
		}
	}
}

/**
 * Not 100% on name, came from osInitialize's call to function
 * 1688	70000A88
 * store current Count to 800230A4
 */
void osCreateLog(void)
{
	currentcount=osGetCount();
}

void osCreateScheduler (OSSched * sc, void * stack, u8 mode, u32 numFields)
{
    sc->curRSPTask = 0;
    sc->curRDPTask = 0;
    sc->clientList = 0;
    sc->frameCount = 0;
    sc->audioListHead = 0;
    sc->gfxListHead = 0;
    sc->audioListTail = 0;
    sc->gfxListTail = 0;
    sc->retraceMsg.type = OS_SC_RETRACE_MSG;
    sc->prenmiMsg.type = OS_SC_PRE_NMI_MSG;
    sc->thread = stack;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, OS_SC_MAX_MESGS);
    osCreateViManager(OS_PRIORITY_VIMGR);
    viMode = &osViModeTable[mode];
    g_viOriginalHstart = viMode->comRegs.hStart;
    g_viOriginalVstart0 = viMode->fldRegs[0].vStart;
    g_viOriginalVstart1 = viMode->fldRegs[1].vStart;
    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg)RSP_DONE_MSG); 
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg)RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg)PRE_NMI_MSG);
    osViSetEvent(&sc->interruptQ, (OSMesg)VIDEO_MSG, numFields);
    osCreateLog();
    osCreateThread(sc->thread, SCHED_THREAD_ID, &__scMain, sc, setSPToEnd(&sp_shed, sizeof(sp_shed)), SCHED_THREAD_PRIORITY);
    osStartThread(sc->thread);
}

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next)
{
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

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

    mask = osSetIntMask(OS_IM_NONE);
    
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
 * Based on libultra\sched\sched.c. In particular, unlike the other scheduler methods,
 * the arg is actually void* instead of OSSched *sc.
 */
void __scMain(void *arg)
{
    OSMesg msg = NULL;
    OSSched *sc = (OSSched *)arg;
    OSScClient *client;
    s32 done = FALSE;

    while (!done)
    {        
        osRecvMesg(&sc->interruptQ, &msg, OS_MESG_BLOCK);

        switch ((s32)msg)
        {
            case VIDEO_MSG:
                __scHandleRetrace(sc);
                break;

            case RSP_DONE_MSG:
                __scHandleRSP(sc);
                break;

            case RDP_DONE_MSG:
                __scHandleRDP(sc);
                break;

            case PRE_NMI_MSG:
            do {
                joyRumblePakStop();

                for (client = sc->clientList; (client != NULL); client = client->next)
                {
                      osSendMesg(client->msgQ, (OSMesg)&sc->prenmiMsg, OS_MESG_NOBLOCK);
                }
                done = TRUE;
                break;
            } while(0);

            default:
                break;
        }
    }

    if (osTvType == TV_TYPE_MPAL)
    {
        osViSetMode(&osViModeTable[OS_VI_MPAL_LAN1]);
    }
    else
    {
        osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
    }

    osViSetXScale(1.0f);
    osViSetYScale(1.0f);
    osViRepeatLine(0);
    osViBlack(TRUE);

    while (TRUE)
    {
        do
        {
            osRecvMesg(&sc->interruptQ, &msg, OS_MESG_BLOCK);
        } while((s32)msg != VIDEO_MSG);

        joyPoll();
    }
}

void __scHandleRetrace(OSSched *sc) {
    OSScTask    *rspTask = 0;    
    OSScClient  *client;
    s32         state;
    OSScTask    *sp = 0;
    OSScTask    *dp = 0;
    speedGraphVideoRelated_1();
    sc->frameCount++;
    viVsyncRelated();
    joyPoll();
    musicFadeTick();
    while (osRecvMesg(&sc->cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) != -1) {
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
        if ((*((s32*)client + 2) == 0) || ((sc->frameCount & 1) == 0)) {
            osSendMesg(client->msgQ, (OSMesg) &sc->retraceMsg, OS_MESG_NOBLOCK);
        }
    }
    CheckDisplayErrorBufferEvery16Frames(sc->frameCount);
}

void __scHandleRSP(OSSched *sc) {
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;
    t = sc->curRSPTask;
    sc->curRSPTask = 0;
#if defined(VERSION_EU)
    speedGraphDisplay(0x10001);
#else
    profileSetMarker(0x10001);
#endif
    if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
        t->state |= OS_SC_YIELDED;
        if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
            t->next = sc->gfxListHead;
            sc->gfxListHead = t;
            if (sc->gfxListTail == 0) {
                sc->gfxListTail = t;
            }
        }
    } else {
        t->state &= ~OS_SC_NEEDS_RSP;
        __scTaskComplete(sc, t);
    }
    state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
    if (__scSchedule(sc, &sp, &dp, state) != state) {
        __scExec(sc, sp, dp);
    }
}

u32 *get_counters(void)
{
    return g_DisplayPerformanceCounters;
}

void __scHandleRDP(OSSched *sc)
{
    OSScTask *t, *sp = NULL, *dp = NULL; 
    s32 state;
    if (sc->curRDPTask != NULL) {
#if defined(VERSION_EU)
    speedGraphDisplay(0x10002);
#else
    profileSetMarker(0x10002);
#endif
        osDpGetCounters(g_DisplayPerformanceCounters);
        t = sc->curRDPTask;
        sc->curRDPTask = NULL;
        t->state &= ~OS_SC_NEEDS_RDP;
        __scTaskComplete(sc, t);
        state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
        if (__scSchedule(sc, &sp, &dp, state) != state) {
            __scExec(sc, sp, dp);
        }
    }
}

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

s32 __scTaskComplete(OSSched *sc, OSScTask *t)
{
    int rv;
    static int firsttime = 1;
    if ((t->state & OS_SC_RCP_MASK) == 0) {
        rv = osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);
        if (t->list.t.type == M_GFXTASK) {
            if ((t->flags & OS_SC_SWAPBUFFER) && (t->flags & OS_SC_LAST_TASK)){
                if (firsttime) {
                    osViBlack(FALSE);
                    firsttime = 0;
                }
                if (g_ViChangeVideoModes[g_schedViCurrentFrameBuffer]) {
                    OSIntMask mask = osSetIntMask(OS_IM_VI);
                    *g_ViModePtrs[g_schedViCurrentFrameBuffer] = g_ViModes[g_schedViCurrentFrameBuffer];
                    osSetIntMask(mask);
                }
                osViSetXScale(g_ViXScales[g_schedViCurrentFrameBuffer]);
                osViSetYScale(g_ViYScales[g_schedViCurrentFrameBuffer]);
                g_schedViCurrentFrameBuffer = ((g_schedViCurrentFrameBuffer + 1) % 2);
                CheckDisplayErrorBuffer(t->framebuffer);
                osViSwapBuffer(t->framebuffer);
            }
        }
        return 1;
    }    
    return 0;
}

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

void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp)
{
    int rv;
    if (sp)
    {
        if (sp->list.t.type == M_AUDTASK)
        {
            osWritebackDCacheAll();
        } 
        
        if ((sp->list.t.type != M_AUDTASK) && (sp->state & 0x10) == 0)
        {
            osDpSetStatus(0x3c0);
        }
        
        if (sp->list.t.type == 2)
        {
#if defined(VERSION_EU)
            speedGraphDisplay(0x30001);
#else
            profileSetMarker(0x30001);
#endif
        }
        else
        {
#if defined(VERSION_EU)
            speedGraphDisplay(0x40001);
            speedGraphDisplay(0x20002);
#else
            profileSetMarker(0x40001);
            profileSetMarker(0x20002);
#endif
        }
        sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED); 
        osSpTaskLoad(&sp->list);
        osSpTaskStartGo(&sp->list);
        sc->curRSPTask = sp;
        if (sp == dp)
        {
            sc->curRDPTask = dp;
        }
    }
    if (dp && (dp != sp))
    {
        rv = osDpSetNextBuffer(dp->list.t.output_buff, *dp->list.t.output_buff_size);

        dp_busy = 1;
        dpCount = 0;

        sc->curRDPTask = dp;        
    }
}

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
s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP) 
{
    s32 avail = availRCP;
    OSScTask *gfx = sc->gfxListHead;
    OSScTask *audio = sc->audioListHead;

    if (sc->doAudio && (avail & OS_SC_SP))
    {
        if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK))
        {
            *sp = gfx;
            avail &= ~OS_SC_SP;
        } else {
            *sp = audio;
            avail &= ~OS_SC_SP;
            sc->doAudio = 0;
            sc->audioListHead = sc->audioListHead->next;
            if (sc->audioListHead == NULL)
                sc->audioListTail = NULL; 
        }        
    } else {            
        if (__scTaskReady(gfx))
        {
            switch (gfx->flags & OS_SC_TYPE_MASK)
            {
              case (OS_SC_XBUS):
                  if (gfx->state & OS_SC_YIELDED)
                  {
                      if (avail & OS_SC_SP)
                      {
                          *sp = gfx;
                          avail &= ~OS_SC_SP;
                      
                          if (gfx->state & OS_SC_DP)
                          { 
                              *dp = gfx;
                              avail &= ~OS_SC_DP;

                              if (avail & OS_SC_DP == 0)
                                  assert(sc->curRDPTask == gfx);
                              
                          }
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }                  
                  } else {
                      if (avail == (OS_SC_SP | OS_SC_DP))
                      {
                          *sp = *dp = gfx;
                          avail &= ~(OS_SC_SP | OS_SC_DP);
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }
                  }
                  break;
          
              case (OS_SC_DRAM):
              case (OS_SC_DP_DRAM):
              case (OS_SC_DP_XBUS):
                  if (gfx->state & OS_SC_SP) 
                  {
                      if (avail & OS_SC_SP)
                      {
                          *sp = gfx;
                          avail &= ~OS_SC_SP;
                      }
                  } else if (gfx->state & OS_SC_DP) {
                      if (avail & OS_SC_DP)
                      {
                          *dp = gfx;
                          avail &= ~OS_SC_DP;
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }
                  }
                  break;

              case (OS_SC_SP_DRAM):
              case (OS_SC_SP_XBUS):
              default:
                  break;
            }
        }
    }

    if (avail != availRCP)
        avail = __scSchedule(sc, sp, dp, avail);

    return avail;
    
}
