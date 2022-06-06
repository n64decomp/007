#include <PR/os.h>
#include <PR/os_internal.h>
#include <PR/R4300.h>
#include <PR/rcp.h>
#include <io/piint.h>
#include <libultrare.h>

typedef struct
{
   /* 0x0 */ unsigned int inst1;
   /* 0x4 */ unsigned int inst2;
   /* 0x8 */ unsigned int inst3;
   /* 0xC */ unsigned int inst4;
} __osExceptionVector;

extern s32 osViClock;
extern __osExceptionVector __osExceptionPreamble;

OSTime osClockRate = OS_CLOCK_RATE;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;

u32 __osFinalRom;
s32 osDiskExist = 0;

void osInitialize()
{
    u32 pifdata;
    u32 clock = 0;
    s32 local_asic_status;
    s32 pistatus;

    __osFinalRom = TRUE;
    __osSetSR(__osGetSR() | SR_CU1);    //enable fpu
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV); //flush denorm to zero, enable invalid operation

    while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) //last byte of joychannel ram
    {
        ;
    }

    while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8))
    {
        ; //todo: magic contant
    }

    *(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)E_VEC = __osExceptionPreamble;

    osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osMapTLBRdb();
    osPiRawReadIo(4, &clock); //TODO: remove magic constant;
    clock &= ~0xf;            //clear lower 4 bits

    if (clock != 0)
    {
        osClockRate = clock;
    }

    osClockRate = osClockRate * 3 / 4;

    if (osResetType == 0 /*cold reset */)
    {
        bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }

    pistatus = IO_READ(PI_STATUS_REG);
    while ((pistatus & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) != 0)
    {
        pistatus = IO_READ(PI_STATUS_REG);
    }

    local_asic_status = IO_READ(LEO_STATUS);
    
    if ((local_asic_status & 0xffff) == 0)
    {
        osDiskExist = 1;
        __osSetHWIntrRoutine(1, &__osLeoInterrupt);
    }
    else
    {
        osDiskExist = 0;
    }
}
