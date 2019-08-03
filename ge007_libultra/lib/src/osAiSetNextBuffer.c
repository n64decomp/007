#include "libultra_internal.h"
#include "osAi.h"
#include "hardware.h"
u8 D_80334820 = 0;
s32 osAiSetNextBuffer(void *buff, u32 len)
{
    u8 *sp1c = buff;
    if (D_80334820 != 0)
    {
        sp1c -= 0x2000;
    }
    if ((((u32)buff + len) & 0x3fff) == 0x2000)

        D_80334820 = 1;

    else

        D_80334820 = 0;

    if (__osAiDeviceBusy())
        return -1;
    HW_REG(AI_DRAM_ADDR_REG, void *) = (void*)osVirtualToPhysical(sp1c);
    HW_REG(AI_LEN_REG, u32) = len;
    return 0;
}
