#include <os_internal.h>
#include <R4300.h>

void __osResetGlobalIntMask(OSHWIntr interrupt)
{
    register u32 saveMask = __osDisableInt();

    //not sure about these constants, SR_IBIT3 is external level 3 INT0, which I think corresponds to the rcp
    //os.h has several masks defined that end in 401 but non that are just 401
    __OSGlobalIntMask &= ~(interrupt & ~(SR_IBIT3 | SR_IE));

    __osRestoreInt(saveMask);
}
