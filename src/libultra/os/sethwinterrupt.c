#include <os_internal.h>
#include "exceptasm.h"

void __osSetHWIntrRoutine(OSHWIntr interrupt, s32 (*handler)(void))
{
    register u32 saveMask;
    saveMask = __osDisableInt();
    __osHwIntTable[interrupt] = handler;
    __osRestoreInt(saveMask);
}
