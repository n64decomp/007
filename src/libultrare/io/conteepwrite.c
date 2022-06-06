#include <PR/os_internal.h>
#include <io/controller.h>
#include <io/siint.h>
#include <PR/rcp.h>

static void __osPackEepWriteData(u8 address, u8 *buffer);

s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer)
{

    s32 ret;
    int i;
    u8 *ptr;
    __OSContEepromFormat eepromformat;
    OSContStatus sdata;

    ret = 0;
    ptr = (u8 *)&__osEepPifRam.ramarray;

    if (address > EEPROM_MAXBLOCKS)
    {
        return -1;
    }

    __osSiGetAccess();
    ret = __osEepStatus(mq, &sdata);

    if (ret != 0 || sdata.type != CONT_EEPROM)
    {
        return CONT_NO_RESPONSE_ERROR;
    }

    while (sdata.status & CONT_EEPROM_BUSY)
    {
        __osEepStatus(mq, &sdata);
    }

    __osPackEepWriteData(address, buffer);
    ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam); //send command to pif
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) // buffer overflow?
    {
        __osEepPifRam.ramarray[i] = CONT_CMD_NOP;
    }

    __osEepPifRam.pifstatus = CONT_CMD_REQUEST_STATUS;


    ret = __osSiRawStartDma(OS_READ, &__osEepPifRam); //recv response
    __osContLastCmd = CONT_CMD_WRITE_EEPROM;
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    for (i = 0; i < 4; i++) //skip the first 4 bytes
    {
        ptr++;
    }

    eepromformat = *(__OSContEepromFormat *)ptr;

    //probably indicates an error, from PIF
    ret = CHNL_ERR(eepromformat); //TODO: remove magic constants

    __osSiRelAccess();

    return ret;
}

static void __osPackEepWriteData(u8 address, u8 *buffer)
{
    u8 *ptr;
    __OSContEepromFormat eepromformat;
    int i;
    ptr = (u8 *)&__osEepPifRam.ramarray;

    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) // buffer overflow?
    {
        __osEepPifRam.ramarray[i] = CONT_CMD_NOP;
    }

    __osEepPifRam.pifstatus = CONT_CMD_EXE;

    eepromformat.txsize = CONT_CMD_WRITE_EEPROM_TX;
    eepromformat.rxsize = CONT_CMD_WRITE_EEPROM_RX;
    eepromformat.cmd = CONT_CMD_WRITE_EEPROM;
    eepromformat.address = address;

    for (i = 0; i < ARRLEN(eepromformat.data); i++)
    {
        eepromformat.data[i] = *buffer++;
    }

    for (i = 0; i < 4; i++) //skip the first 4 bytes
    {
        *ptr++ = 0;
    }

    *(__OSContEepromFormat *)(ptr) = eepromformat;
    ptr += sizeof(__OSContEepromFormat);
    ptr[0] = CONT_CMD_END;
}

s32 __osEepStatus(OSMesgQueue *mq, OSContStatus *data)
{
    s32 ret;
    int i;
    u8 *ptr;
    __OSContRequesFormat requestformat;

    ret = 0;
    ptr = (u8 *)__osEepPifRam.ramarray;
    //could be bset or bzero intrinsic

    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) //still has the buffer overflow =/, just sets status to 0
    {
        __osEepPifRam.ramarray[i] = 0;
    }

    __osEepPifRam.pifstatus = CONT_CMD_EXE;
    ptr = (u8 *)__osEepPifRam.ramarray;
    
    for (i = 0; i < 4; i++) //zero 4 bytes?
    {
        *ptr++ = 0;
    }

    requestformat.dummy = CONT_CMD_NOP;
    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
    requestformat.cmd = CONT_CMD_REQUEST_STATUS;
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;
    requestformat.dummy1 = CONT_CMD_NOP;
    *(__OSContRequesFormat *)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormat);
    *ptr = CONT_CMD_END;

    ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    __osContLastCmd = CONT_CMD_WRITE_EEPROM;
    ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    if (ret != 0)
    {
        return ret;
    }

    ptr = (u8 *)&__osEepPifRam;

    for (i = 0; i < 4; i++)
    {
        *ptr++ = 0;
    }

    requestformat = *(__OSContRequesFormat *)ptr;
    data->errno = CHNL_ERR(requestformat);
    data->type = (requestformat.typel << 8) | requestformat.typeh;
    data->status = requestformat.status;
    
    if (data->errno != 0)
    {
        return data->errno;
    }

    return 0;
}
