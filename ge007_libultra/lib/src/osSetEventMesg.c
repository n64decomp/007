#include "libultra_internal.h"
typedef struct OSEventMessageStruct_0_s
{
    OSMesgQueue *queue;
    OSMesg msg;
    //u8 pad[4];
} OSEventMessageStruct_0;
OSEventMessageStruct_0 D_80363830[0x80 >> 3];
void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg)
{
    register u32 int_disabled;
    OSEventMessageStruct_0 *msgs;
    int_disabled = __osDisableInt();
    msgs = D_80363830 + e;
    msgs->queue = mq;
    msgs->msg = msg;
    __osRestoreInt(int_disabled);
}
