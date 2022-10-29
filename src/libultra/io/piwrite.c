#include <os_internal.h>
#include <os.h>
#include "piint.h"

s32 osPiWriteIo(u32 devAddr, u32 data)
{
    register s32 ret;
    __osPiGetAccess();
    ret = osPiRawWriteIo(devAddr, data);
    __osPiRelAccess();
    return ret;
}
