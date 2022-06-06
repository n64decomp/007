
#include <ultra64.h>

extern u64 osClockRate;
extern u8 D_80365D20;
extern u8 _osContNumControllers;
extern OSTimer __osEepromTimer;
extern OSMesgQueue __osEepromTimerQ;
extern OSMesg __osEepromTimerMsg[4];

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    s32 status = 0;
    if (address > 0x40) {
        return -1;
    }

    while (nbytes > 0) {
        status = osEepromRead(mq, address, buffer);
        if (status != 0) {
            return status;
        }

        nbytes -= 8;
        address += 1;
        buffer += 8;
        osSetTimer(&__osEepromTimer, 12000 * osClockRate / 1000000, 0, &__osEepromTimerQ, __osEepromTimerMsg);
        osRecvMesg(&__osEepromTimerQ, NULL, OS_MESG_BLOCK);
    }

    return status;
}
