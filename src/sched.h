#ifndef _scheduler_h_
#define _scheduler_h_

#include <ultra64.h>

#define OS_SC_STACKSIZE      0x2000

#define OS_SC_RETRACE_MSG       1
#define OS_SC_DONE_MSG          2
#define OS_SC_RDP_DONE_MSG      3
#define OS_SC_RSP_MSG           4  // custom - tells audiomgr it's time to do an audio frame
#define OS_SC_PRE_NMI_MSG       5
#define OS_SC_LAST_MSG          5	/* this should have highest number */
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

extern f32 g_ViXScales[2];
extern f32 g_ViYScales[2];
extern s32 g_ViChangeVideoModes[2];
extern OSSched os_scheduler;
extern OSScClient gfxClient[3];
extern OSViMode g_ViModes[2];
extern OSViMode *g_ViModePtrs[2];
extern s32 dword_CODE_bss_8005DBE8[2];

void activate_stderr(u32 flag);
void enable_stderr(u32 flag);
void permit_stderr(u32 flag);
void setUserCompareValue(u32 value);
void CheckDisplayErrorBuffer(u32 *buffer);
void CheckDisplayErrorBufferEvery16Frames(u32 framecount);
void osCreateLog(void);
void __scMain(void *arg);
u32 *get_counters(void);
void __scYield(OSSched *sc) ;
void __scAppendList(OSSched *sc, OSScTask *t);
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp);
void osCreateScheduler(OSSched *s, void *stack, u8 mode, u32 numFields);
void osScAddClient(OSSched *s, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next);
void osScRemoveClient(OSSched *s, OSScClient *c);
OSMesgQueue *osScGetCmdQ(OSSched *s);


#endif

