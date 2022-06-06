#include <ultra64.h>
#include "indy_commands.h"
#include "indy_comms.h"

s32 indycommInit(void) {
    if (indy_ready != 1)
    {
        indy_ready = 1;
        indycommHostinit();
    }
}

void indycomm_removed(void) {
    #ifdef DEBUG
        //removed
    #endif
}

void indycommHostinit(void) {
    if (indy_ready)
    {
        indycmdSendInitPacket();
    }
}

void indycommHostLoadFile(char *filename, u8 *targetloc)
{
    u8 response1 [8];
    u8 response2 [4];
    u32 size;
  
    if (indy_ready)
    {
        indycmdSendLoadFile(filename,0x400000);
        indycmdReceiveFile(response1,response2,(u32)&size,targetloc);
    }
    return;
}

void indycommHostSendDump(char *filename, u8 *data, u32 size)
{
    u8 auStack4 [4];
  
    if (indy_ready) 
    {
        indycmdSendDump(filename, size, data);
        indycmdAckSendDump(auStack4);
    }
    return;
}

void indycommHostRamRomLoad(char *filename, u8 *target, s32 size)
{
    u32 uStack4;
    u32 uStack8;
    u32 uStack12;
  
    if (indy_ready)
    {
        indycmdSendRamRomLoad(filename,target,size);
        indycmdReceiveRamRom(&uStack4,&uStack8,&uStack12);
    }
    return;
}

void indycommHostSaveFile(char *filename, s32 size, u8 * data)
{
    u8 auStack4 [4];
  
    if (indy_ready)
    {
        indycmdSendHostExportFile(filename,data,size);
        indycmdAckHostExportFile(auStack4);
    }
}

u8 * indycommHostCheckFileExists(char *name, s32 *size)
{
    u8 *response;  
    if (!indy_ready) {
        return NULL;
    } else {
        indycmdSendHostCheckFileExists(name);
        indycmdAckHostCheckFileExists(&response,size);
    }
    return response;
}

u8 *indycommHostSendCmd(u8 *cmdstr)
{
    u8 *local_4;  
    if (!indy_ready) {
        return NULL;
    }
    else {
        indycmdSendHostCmdPacket(cmdstr);
        indycmdAckHostCmdPacket(&local_4);
    }
    return local_4;
}

void indycommHost7F0D0124(void) {
    if (indy_ready)
    {
        rmonStatus();
    }
}

void indycommHostCloseConnection(void) {
    indycommHostSendCmd("sleep 5; /etc/killall ghost gload");
}
