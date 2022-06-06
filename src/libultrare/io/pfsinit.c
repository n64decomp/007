#include <PR/os_internal.h>
#include <io/controller.h>
#include <io/siint.h>

s32 osPfsInit(OSMesgQueue *queue, OSPfs *pfs, int channel)
{
    s32 ret;
    ret = 0;
    __osSiGetAccess();
    ret = __osPfsGetStatus(queue, channel);
    __osSiRelAccess();
    
    if (ret != 0)
    {
        return ret;
    }

    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    
    ERRCK(__osGetId(pfs));

    ret = osPfsChecker(pfs);
    pfs->status |= PFS_INITIALIZED;

    return ret;
}

s32 __osPfsGetStatus(OSMesgQueue *queue, int channel)
{
    s32 ret;
    OSMesg dummy;
    u8 bitpattern;
    OSContStatus data[MAXCONTROLLERS];

    ret = 0;
    __osPfsRequestData(CONT_CMD_REQUEST_STATUS);
    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    __osPfsGetInitData(&bitpattern, data);

    if ((data[channel].status & CONT_CARD_ON) && (data[channel].status & CONT_CARD_PULL))
    {
        return CONT_CARD_PULL;
    }

    if (data[channel].errno != 0 || (data[channel].status & CONT_CARD_ON) == 0)
    {
        return CONT_CARD_ON;
    }

    if ((data[channel].status & CONT_ADDR_CRC_ER) != 0)
    {
        return CONT_ADDR_CRC_ER;
    }

    return ret;
}
