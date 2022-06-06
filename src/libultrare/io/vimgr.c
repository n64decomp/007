#include <PR/os_internal.h>
#include <PR/rcp.h>
#include <io/viint.h>
#include <os/osint.h>

#define EU_OS_VIM_STACKSIZE 256

#if defined(VERSION_EU)
#undef OS_VIM_STACKSIZE
#define OS_VIM_STACKSIZE EU_OS_VIM_STACKSIZE
#endif


OSDevMgr __osViDevMgr = {0};

static OSThread viThread;
static unsigned char viThreadStack[OS_VIM_STACKSIZE];
static OSMesgQueue viEventQueue;
static OSMesg viEventBuf[5];
static OSIoMesg viRetraceMsg;
static OSIoMesg viCounterMsg;

static void viMgrMain(void *arg);

void osCreateViManager(OSPri pri)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;

	if (__osViDevMgr.active == 0)
	{
		__osTimerServicesInit();
		osCreateMesgQueue(&viEventQueue, viEventBuf, 5);
		viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
		viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viRetraceMsg.hdr.retQueue = NULL;
		viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
		viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viCounterMsg.hdr.retQueue = NULL;
		osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
		osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);
		oldPri = -1;
		myPri = osGetThreadPri(NULL);

		if (myPri < pri)
		{
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}

		savedMask = __osDisableInt();
		__osViDevMgr.active = 1;
		__osViDevMgr.thread = &viThread;
		__osViDevMgr.cmdQueue = &viEventQueue;
		__osViDevMgr.evtQueue = &viEventQueue;
		__osViDevMgr.acsQueue = NULL;
		__osViDevMgr.dma = NULL;
		__osViDevMgr.edma = NULL;
		osCreateThread(&viThread, 0, viMgrMain, &__osViDevMgr, &viThreadStack[OS_VIM_STACKSIZE], pri);
		__osViInit();
		osStartThread(&viThread);
		__osRestoreInt(savedMask);

		if (oldPri != -1)
		{
			osSetThreadPri(0, oldPri);
		}
	}
}

static void viMgrMain(void *arg)
{
	__OSViContext *vc;
	OSDevMgr *dm;
	OSIoMesg *mb;
	static u16 retrace;
	s32 first;
	u32 count;

	mb = NULL;
	first = 0;
	vc = __osViGetCurrentContext();
	retrace = vc->retraceCount;
	if (retrace == 0)
		retrace = 1;
	dm = (OSDevMgr *)arg;
	while (TRUE)
	{
		osRecvMesg(dm->evtQueue, (OSMesg)&mb, OS_MESG_BLOCK);
		switch (mb->hdr.type)
		{
            case OS_MESG_TYPE_VRETRACE:
                __osViSwapContext();
                retrace--;
                if (retrace == 0)
                {
                    vc = __osViGetCurrentContext();
                    if (vc->msgq != NULL)
                        osSendMesg(vc->msgq, vc->msg, OS_MESG_NOBLOCK);
                    retrace = vc->retraceCount;
                }
                __osViIntrCount++;
                if (first)
                {

                    count = osGetCount();
                    __osCurrentTime = count;
                    first = 0;
                }
                count = __osBaseCounter;
                __osBaseCounter = osGetCount();
                count = __osBaseCounter - count;
                __osCurrentTime = __osCurrentTime + count;
                break;
                
            case OS_MESG_TYPE_COUNTER:
                __osTimerInterrupt();
                break;
		}
	}
}
