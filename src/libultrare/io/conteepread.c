#include <PR/os.h>
#include <io/controller.h>
#include <ultra64.h>

s32 __osPackEepReadData(u8);
OSPifRam __osEepPifRam;

s32 osEepromRead(OSMesgQueue *mq, u8 address, u8 *buffer) {
    s32 ret;
    s32 i;
    u8 *ptr;
    OSContStatus data;
    __OSContEepromFormat format;
    ret = 0;
    i = 0;
    ptr = (u8 *) &__osEepPifRam;
    if (address > 0x40) {
        return -1;
    }
    __osSiGetAccess();
    ret = __osEepStatus(mq, &data);
    if (ret != 0 || data.type != 0x8000) {

        return 8;
    }
    while (data.status & 0x80) {
        __osEepStatus(mq, &data);
    }
    __osPackEepReadData(address);
    ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    for (i = 0; i < 0x10; i++) {
        __osEepPifRam.ramarray[i] = 255;
    }
    __osEepPifRam.pifstatus = 0;
    ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
    __osContLastCmd = 4;
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    for (i = 0; i < 4; i++) {
        ptr++;
    }
    format = *(__OSContEepromFormat *) ptr;
    ret = (format.rxsize & 0xc0) >> 4;
    if (ret == 0) {
        for (i = 0; i < 8; i++) {
            *buffer++ = ((u8 *) &format.data)[i];
        }
    }
    __osSiRelAccess();
    return ret;
}

s32 __osPackEepReadData(u8 address) {
    u8 *ptr;
    __OSContEepromFormat format;
    s32 i;
    ptr = (u8 *) &__osEepPifRam;
    for (i = 0; i < 0x10; i++) {
        __osEepPifRam.ramarray[i] = 255;
    }
    __osEepPifRam.pifstatus = 1;
    format.txsize = 2;
    format.rxsize = 8;
    format.cmd = 4;
    format.address = address;
    for (i = 0; i < 8; i++) {
        ((u8 *) &format.data)[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        *ptr++ = 0;
    }
    *(__OSContEepromFormat *) ptr = format;
    ptr += 0xc;
    *ptr = 254;
#ifdef AVOID_UB
    return 0;
#endif
}
