#ifndef _scheduler_h_
#define _scheduler_h_

#include "ultra64.h"

#define OS_SC_STACKSIZE      0x2000

#define OS_SC_RETRACE_MSG       1
#define OS_SC_DONE_MSG          2
#define OS_SC_RDP_DONE_MSG      3
#define OS_SC_PRE_NMI_MSG       4
#define OS_SC_LAST_MSG          4	/* this should have highest number */
#define OS_SC_MAX_MESGS         8

typedef struct {
    short type;
    char  misc[30];
} OSScMsg;

typedef struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    OSTask list;
    OSMesgQueue *msgQ;
    OSMesg msg;
} OSScTask;

#define OS_SC_NEEDS_RDP	        0x0001
#define OS_SC_NEEDS_RSP	        0x0002
#define OS_SC_DRAM_DLIST        0x0004
#define OS_SC_PARALLEL_TASK     0x0010
#define OS_SC_LAST_TASK	        0x0020
#define OS_SC_SWAPBUFFER        0x0040

#define OS_SC_RCP_MASK		0x0003
#define OS_SC_TYPE_MASK		0x0007

typedef struct SCClient_s {
    struct SCClient_s   *next;
    OSMesgQueue         *msgQ;
} OSScClient;

//fixme im wrong size, shouldn't copy paste from sample code anyway
typedef struct {
    OSScMsg     retraceMsg;
    OSScMsg     prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg      intBuf[OS_SC_MAX_MESGS];
    OSMesgQueue cmdQ;
    OSMesg      cmdMsgBuf[OS_SC_MAX_MESGS];
    OSThread    *thread;
    OSScClient  *clientList;
    OSScTask    *audioListHead;
    OSScTask    *gfxListHead;
    OSScTask    *audioListTail;
    OSScTask    *gfxListTail;
    OSScTask    *curRSPTask;
    OSScTask    *curRDPTask;
    u32         frameCount;
    s32         doAudio;
} OSSched;

extern OSSched sc;
//extern OSScClient gfxClient;
extern char gfxClient[0x18];

void activate_stderr(u32 flag);
void enable_stderr(u32 flag);
void permit_stderr(u32 flag);
void setUserCompareValue(u32 value);
extern void CheckDisplayErrorBuffer(u32 *buffer);
extern void CheckDisplayErrorBufferEvery16Frames(u32 framecount);
void osCreateLog(void);
void __scMain(void *arg);
void __scYield(OSSched *sc) ;

void            osCreateScheduler(OSSched *s, void *stack, u8 mode, u8 numFields);
void            osScAddClient(OSSched *s, OSScClient *c, OSMesgQueue *msgQ);
void            osScRemoveClient(OSSched *s, OSScClient *c);
OSMesgQueue     *osScGetCmdQ(OSSched *s);

#endif

