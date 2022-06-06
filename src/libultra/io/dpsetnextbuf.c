#include <os_internal.h>
#include <rcp.h>
#include "../os/osint.h"

s32 osDpSetNextBuffer(void *bufPtr, u64 size)
{
    register u32 stat;

    if (__osDpDeviceBusy())
        return -1;
    IO_WRITE(DPC_STATUS_REG, DPC_CLR_XBUS_DMEM_DMA);
    do
    {
        stat = IO_READ(DPC_STATUS_REG);
    } while (stat & DPC_STATUS_XBUS_DMEM_DMA);
    IO_WRITE(DPC_START_REG, osVirtualToPhysical(bufPtr));
    IO_WRITE(DPC_END_REG, osVirtualToPhysical(bufPtr) + size);
    return 0;
}
