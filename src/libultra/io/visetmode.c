#include <os_internal.h>
#include "viint.h"

void osViSetMode(OSViMode *modep)
{
    register u32 saveMask;
    saveMask = __osDisableInt();
    __osViNext->modep = modep;
    __osViNext->state = VI_STATE_MODE;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(saveMask);
}
