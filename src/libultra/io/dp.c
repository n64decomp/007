#include <os_internal.h>
#include <rcp.h>

int __osDpDeviceBusy(void)
{
    register u32 stat;
    stat = IO_READ(DPC_STATUS_REG);
    if (stat & DPC_STATUS_DMA_BUSY)
        return 1;
    return 0;
}
