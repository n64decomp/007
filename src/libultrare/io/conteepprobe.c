#include <ultra64.h>

s32 osEepromProbe(OSMesgQueue *mq) {
    s32 status = 0;
    OSContStatus sdata;

    __osSiGetAccess();
    status = __osEepStatus(mq, &sdata);
    if (status == 0 && (sdata.type & 0x8000) != 0) {
        status = 1;
    } else {
        status = 0;
    }
    __osSiRelAccess();
    return status;
}
