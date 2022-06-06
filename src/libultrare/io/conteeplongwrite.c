#include <ultra64.h>

extern u64 osClockRate;
extern u8 D_80365D20;
extern u8 _osContNumControllers;
extern OSTimer __osEepromTimer;
extern OSMesgQueue __osEepromTimerQ;
extern OSMesg __osEepromTimerMsg[4];
// exactly the same as osEepromLongRead except for osEepromWrite call

s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    s32 result = 0;
    if (address > 0x40) {
        return -1;
    }

    while (nbytes > 0) {
        result = osEepromWrite(mq, address, buffer);
        if (result != 0) {
            return result;
        }

        nbytes -= 8;
        address += 1;
        buffer += 8;
        osSetTimer(&__osEepromTimer, 12000 * osClockRate / 1000000, 0, &__osEepromTimerQ, __osEepromTimerMsg);
        osRecvMesg(&__osEepromTimerQ, NULL, OS_MESG_BLOCK);
    }

    return result;
}
