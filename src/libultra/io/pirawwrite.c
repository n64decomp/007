#include <os_internal.h>
#include "piint.h"

s32	osPiRawWriteIo(u32 devAddr, u32 data)
{
    register u32 stat;
    WAIT_ON_IOBUSY(stat);
    IO_WRITE((u32)osRomBase | devAddr, data);
    return 0;
}
