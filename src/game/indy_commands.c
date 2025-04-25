#include <ultra64.h>
#include "indy_commands.h"
#include <PR/os.h>
#include <PR/region.h>
#include "rmon.h"
// data
//D:8004EAC0
s32 D_8004EAC0 = 0;
//D:8004EAC4
s32 indy_status = 0x103;
//D:8004EAC8
s32 indy_ready = 0;
//D:8004EACC
s32 D_8004EACC = 0x0;
//D:8004EAD0
s32 D_8004EAD0 = 0x0;


void indy_buffer_read_command(u8 *buffer,u32 size)
{
    int i;

    for (i = 0; i != 100000; i += 4) { }

    osReadHost(buffer, size);

    for (i = 0; i != 100000; i += 1) { }
}


void indy_buffer_write_command(u8 *buffer,u32 size)
{
    int i;

    for (i = 0; i != 100000; i += 4){}

    osWriteHost(buffer, size);

    for (i = 0; i != 100000; i += 1){}
}




// /include/PR/region.h
// #define ALIGN(s, align) (((u32)(s) + (align-1)) & ~(align-1))

s32 indycmdSendCommand(u8 *buffer, u32 size)
{
    u8 sp40[0x500];
    u8 *address;
    u32 i;
    u8 *source;
    u8 *pbuffer;
    u8 *padding1;
    u8 *end;
    u8 *padding5;

    address = sp40; // var_v1
    pbuffer = sp40; // var_a3

    // if argument isn't 8 byte aligned
    if ((s32)(buffer) & 7)
    {
        if (size > 0x500)
        {
            return 0;
        }

        // if local buffer isn't 8 byte aligned
        if ((s32)(pbuffer) & 7)
        {
            address += 4; // var_v1 = var_a3;
            pbuffer += 4; // var_a3 = &sp44;
        }

        if(pbuffer);
        
        end = address + size;
        for (source = buffer; address < end; )
        {
            *address++ = *source++;
        }
        
        if (indy_status & 0x20)
        {
            for (i = 0; i < size; i++)
            {
            }
        }

        indy_buffer_write_command(pbuffer, ALIGN(size, 4));
        
        return 1;
    }
    else // else it is aligned
    {
        if (indy_status & 0x20)
        {
            for (i = 0; i < size; i++)
            {
            }
        }
    
        indy_buffer_write_command(buffer, ALIGN(size, 4));
        
        return 1;
    }
}



s32 send2indyresourcecommands(indy_resource_entry_header * entry1, u32 size1, indy_resource_entry_header * entry2, u32 size2)
{
    indycmdSendCommand((u8 *)entry1, size1);
    indycmdSendCommand((u8 *)entry2, size2);

    return TRUE;
}


void indyrescmdStartCmdSeq(s32 readsize, s32 writesize)
{
    indy_resource_entry_type1 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_STARTCMDSEQ;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void indyrescmdEndCmdSeq(s32 readsize,s32 writesize)
{
    s_indyResCmd02End cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_ENDCMDSEQ;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void indyrescmdInit(s32 readsize,s32 writesize)
{
    indy_resource_entry_type0 cmd;
    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_INIT;
    cmd.entry.size = sizeof(indy_resource_entry_type0);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;

    indycmdSendCommand((u8 *)&cmd, sizeof(indy_resource_entry_type0));
}

void post_type3_indyrescmd(s32 rsize,s32 wsize,char *strptr)
{
    struct indy_resource_entry_type3 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_RESCMD;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,strptr, sizeof(cmd.strbuffer));
    cmd.strbuffer[255] = 0;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void post_type4_indyrescmd_data_recieved(s32 readsize,s32 writesize,s32 data)
{
    indy_resource_entry_type4 cmd;
    
    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_RESCMDDATARCVD;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void indyrescmdCheckFileExists(s32 rsize,s32 wsize,char *name)
{
    indy_resource_entry_type5 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_SENDCHECKFILEEXISTS;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,name,sizeof(cmd.strbuffer));
    cmd.strbuffer[255] = '\0';

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void post_type6_indyrescmd_printfrecieved(s32 readsize,s32 writesize,u32 data1,u32 data2)
{
    indy_resource_entry_type6 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_RECVCHECKFILEEXISTS;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data1 = data1;
    cmd.data2 = data2;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void indyrescmdSendFileLoad(u32 rsize,u32 wsize,u8 *filename,u32 size)
{
    indy_resource_entry_type7 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_SENDFILELOAD;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,filename,sizeof(cmd.strbuffer));
    cmd.strbuffer[255] = '\0';
    cmd.size = size;

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void post_type8_indyrescmd_log_recieved(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 cmd2size,struct indy_resource_entry_type8 *cmd2)
{
   indy_resource_entry_type8 cmd;
  
   cmd.entry.resourceID = INDYMAGIC;
   cmd.entry.type = INDY_LOGRECVD;
  
   cmd.entry.size = (cmd2size +3 & ~3)+ sizeof(indy_resource_entry_type8);
   cmd.entry.readsize = rsize;
   cmd.entry.writesize = wsize;
  
   cmd.data1 = data1;
   cmd.size = cmd2size;
   cmd.data2 = data2;

   send2indyresourcecommands(&cmd,sizeof(indy_resource_entry_type8),cmd2,cmd2size);
}


void indyrescmdSendDump(s32 rsize,s32 wsize,char *strptr,u32 size2,struct indy_resource_entry3 *cmd2)
{
  indy_resource_entry_type9 cmd;

  cmd.entry.resourceID = INDYMAGIC;
  cmd.entry.type = INDY_SENDDUMP;

  cmd.entry.size = (size2 + 3 & 0xfffffffc) + sizeof(indy_resource_entry_type9);
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;

  strncpy(cmd.strbuffer,strptr,sizeof(cmd.strbuffer));
  cmd.strbuffer[255] = '\0';

  send2indyresourcecommands(&cmd,sizeof(indy_resource_entry_type9),cmd2,size2);
  
}


void post_typeA_indyrescmd_app_command_recieved(s32 readsize,s32 writesize,u32 data)
{
  indy_resource_entry_typeA cmd;
  
  cmd.entry.resourceID = INDYMAGIC;
  cmd.entry.type = INDY_APPCMDRECVD;
  cmd.entry.size = sizeof(cmd);
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;

  indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void indyrescmdRamRomLoad(u32 rsize,u32 wsize,char *name,u32 filesize,u32 ptarget)
{
  indy_resource_entry_typeF cmd;
  
  cmd.entry.resourceID = INDYMAGIC;
  cmd.entry.type = INDY_RAMROMLOAD;
  cmd.entry.size = sizeof(cmd);
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;
  strncpy(cmd.strbuffer,name,sizeof(cmd.strbuffer));
  cmd.strbuffer[255] = '\0';
  cmd.size = filesize;
  cmd.hwaddress = ptarget;
  
  indycmdSendCommand((u8 *)&cmd, sizeof(cmd));

}


void post_type10_indyrescmd_fault_ack_by_host(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 data3)
{
    indy_resource_entry_type10 cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_FAULTACKHOST;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    cmd.data3 = data3;

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void indyrescmdSendExportFile(u32 rsize,u32 wsize,u8 *ptrstr,u32 size,u8 *hwaddress)
{
    indy_resource_entry_typeD cmd;
    
    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_EXPORTFILE;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,ptrstr,sizeof(cmd.strbuffer));
    cmd.strbuffer[255] = '\0';
    cmd.size = size;
    cmd.hwaddress = hwaddress;

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void post_typeE_indyrescmd_prof_recv(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeE cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_PROFILE_RECV;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void indyrescmdSendHostCmd(s32 rsize,s32 wsize,char *strptr)
{
    indy_resource_entry_typeB cmd;
    
    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_SENDHOSTCMD;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,strptr,sizeof(cmd.strbuffer));
    cmd.strbuffer[1023] = '\0';

    indycmdSendCommand((u8 *)&cmd, sizeof(cmd));
}


void post_typeC_indyrescmd_prof_send(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeC cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_PROFILE_SEND;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


void post_typeA_indyrescmd_app_data_recieved(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeA cmd;

    cmd.entry.resourceID = INDYMAGIC;
    cmd.entry.type = INDY_APPCMDRECVD;
    cmd.entry.size = sizeof(cmd);
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;

    indycmdSendCommand((u8 *)&cmd.entry, sizeof(cmd));
}


s32 indycmdSendInitPacket(void)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type0),sizeof(indy_resource_entry_type0));
    indyrescmdInit(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End));
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_game_data_send(char *strptr)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type3),sizeof(indy_resource_entry_type3));
    post_type3_indyrescmd(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),strptr);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_debug_data_recv(u32 data)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type4),sizeof(indy_resource_entry_type4));
    post_type4_indyrescmd_data_recieved(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendHostCheckFileExists(char *strptr)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type5),sizeof(indy_resource_entry_type5));
    indyrescmdCheckFileExists(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),strptr);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_debug_printf_recv(u32 data1,u32 data2)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type6),sizeof(indy_resource_entry_type6));
    post_type6_indyrescmd_printfrecieved(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data1,data2);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendLoadFile(u8 *filename,u32 size)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type7),sizeof(indy_resource_entry_type7));
    indyrescmdSendFileLoad(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),filename,size);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_1_8_2(u32 data1,u32 data2,u32 size2,struct indy_resource_entry_header *cmd2)
{
    indyrescmdStartCmdSeq((size2 + 3 & 0xfffffffc) + sizeof(indy_resource_entry_type8),sizeof(indy_resource_entry_type8));
    post_type8_indyrescmd_log_recieved(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data1,data2,size2,cmd2);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendDump(char *string, u32 size, struct indy_resource_entry_header *data)
{
    indyrescmdStartCmdSeq((size + 3 & 0xfffffffc) + sizeof(indy_resource_entry_type9),sizeof(indy_resource_entry_type9));
    indyrescmdSendDump(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),string,size,data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_recv_capture_data_success(u32 data)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeA),sizeof(indy_resource_entry_typeA));
    post_typeA_indyrescmd_app_command_recieved(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendRamRomLoad(char *strptr,u32 ptarget,u32 filesize)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeF),sizeof(indy_resource_entry_typeF));
    indyrescmdRamRomLoad(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),strptr,filesize,ptarget);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_1_10_2(u32 param_1,u32 param_2,u32 param_3)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_type10),sizeof(indy_resource_entry_type10));
    post_type10_indyrescmd_fault_ack_by_host(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),param_1,param_2,param_3);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendHostExportFile(char *strptr,u8 *phwaddr,u32 size)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeD),sizeof(indy_resource_entry_typeD));
    indyrescmdSendExportFile(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),strptr,size,phwaddr);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_host_prof_recv(u32 data)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeE),sizeof(indy_resource_entry_typeE));
    post_typeE_indyrescmd_prof_recv(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 indycmdSendHostCmdPacket(char *strptr)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeB),sizeof(indy_resource_entry_typeB));
    indyrescmdSendHostCmd(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),strptr);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_1_C_2(u32 data)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeC),sizeof(indy_resource_entry_typeC));
    post_typeC_indyrescmd_prof_send(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}


s32 post_indyrescmd_1_A_2(u32 data)
{
    indyrescmdStartCmdSeq(sizeof(indy_resource_entry_typeA),sizeof(indy_resource_entry_typeA));
    post_typeA_indyrescmd_app_data_recieved(sizeof(s_indyResCmd02End),sizeof(s_indyResCmd02End),data);
    indyrescmdEndCmdSeq(0,0);

    return TRUE;
}




s32 indycmdRecieveCommand(u8 *buffer, u32 size)
{
    u8 sp40[0x400];
    u8 *address;
    u32 i;
    u8 *dest;
    u8 *pbuffer;
    u8 *padding1;
    u8 *end;
    u8 *padding5;

    address = sp40; // var_v1
    pbuffer = sp40; // var_a3

    // if argument isn't 8 byte aligned
    if ((s32)(buffer) & 7)
    {
        if (size > 0x400)
        {
            return 0;
        }

        // if local buffer isn't 8 byte aligned
        if ((s32)(pbuffer) & 7)
        {
            pbuffer += 4; // var_a3 = &sp44;
            address += 4; // var_v1 = var_a3;
        }

        indy_buffer_read_command(pbuffer, ALIGN(size, 4));

        end = address + size;
        for (dest = buffer; address < end; )
        {
            *dest++ = *address++;
        }
        
        if (indy_status & 0x10)
        {
            for (i = 0; i < size; i++)
            {
            }
        }
        
        return 1;
    }
    else // else it is aligned
    {
        indy_buffer_read_command(buffer, ALIGN(size, 4));
        
        if (indy_status & 0x10)
        {
            for (i = 0; i < size; i++)
            {
            }
        }
    
        return 1;
    }
}



s32 post_indyrescmd_read_2commands(u8 *buffer1,u32 size1,u8 *buffer2,u32 size2)
{
    indy_buffer_read_command(buffer1,size1 + 3 & 0xfffffffc);
    indy_buffer_read_command(buffer2,size2 + 3 & 0xfffffffc);
    return TRUE;
}


s32 indyrescmdResponseSize(s32 readsize, s32 writesize)
{
    struct indy_resource_entry_header cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x14);

    if (cmd.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.type != 1)
    {
        return FALSE;
    }

    if (cmd.size != 0x14)
    {
        return FALSE;
    }

    if ((readsize != 0) && (cmd.readsize != readsize))
    {
        return FALSE;
    }

    if (cmd.writesize != writesize)
    {
        return FALSE;
    }

    return TRUE;
}


s32 indyrescmdResponseEnd(s32 readsize, s32 writesize)
{
    struct indy_resource_entry_header cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x14);

    if (cmd.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.type != 2)
    {
        return FALSE;
    }

    if (cmd.size != 0x14)
    {
        return FALSE;
    }

    if (cmd.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.writesize != writesize)
    {
        return FALSE;
    }

    return TRUE;
}



s32 post_indyrescmd_istype4_correctvalue(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_type4 cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x18);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 4)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response = cmd.data;

    return TRUE;
}


s32 indyrescmdResponseFileExists(s32 readsize, s32 writesize, u32 *response1, u32 *response2)
{
    struct indy_resource_entry_type6 cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x1C);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 6)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x1C)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response1 = cmd.data1;
    *response2 = cmd.data2;

    return TRUE;
}


s32 indyrescmdResponseRecieveFile(s32 readsize, s32 writesize, u32 *response1, u32 *response2, u32 *childsize, u32 *child)
{
    struct indy_resource_entry_type8 cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x20);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 8)
    {
        return FALSE;
    }
    
    if (cmd.entry.size != (ALIGN(cmd.size, 4) + 0x20))
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response1 = cmd.data1;
    *response2 = cmd.data2;
    *childsize = cmd.size;

    indycmdRecieveCommand((u8 *)child, ALIGN(cmd.size, 4));

    return TRUE;
}


s32 indyrescmdResponseSendDump(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_typeA cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x18);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 0xA)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response = cmd.data;

    return TRUE;
}


s32 indyrescmdResponseRecieveRamRom(s32 readsize, s32 writesize, u32 *data1, u32 *data2, u32 *data3)
{
    struct indy_resource_entry_type10 cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x20);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 0x10)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x20)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *data1 = cmd.data1;
    *data2 = cmd.data2;
    *data3 = cmd.data3;

    return TRUE;
}


s32 indyrescmdResponseHostExportFile(s32 readsize, s32 writesize, u32 *response)
{
    indy_resource_entry_typeE cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x18);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }

    if (cmd.entry.type != 0xE)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response = cmd.data;

    return TRUE;
}


s32 indyrescmdResponseHostCmdPacket(s32 readsize, s32 writesize, u32 *response)
{
    indy_resource_entry_typeC cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x18);

    if (cmd.entry.resourceID != INDYMAGIC)
    {
        return FALSE;
    }
    
    if (cmd.entry.type != 0xC)
    {
        return FALSE;
    }

    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }

    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }

    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }

    *response = cmd.data;

    return TRUE;
}


s32 response_indyrescmd_1_4_2(u8 *response)
{
    indyrescmdResponseSize(0x18,0x18);
    post_indyrescmd_istype4_correctvalue(0x14,0x14,response);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdAckHostCheckFileExists(u8 *response1,u8 *response2)
{
    indyrescmdResponseSize(0x1c,0x1c);
    indyrescmdResponseFileExists(0x14,0x14,response1,response2);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdReceiveFile(u8 *response1,u8 *response2,u32 childsize,u8 *child)
{
    indyrescmdResponseSize(0,0x20);
    indyrescmdResponseRecieveFile(0x14,0x14,response1,response2,childsize,child);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdAckSendDump(u8 *param_1)
{
    indyrescmdResponseSize(0x18,0x18);
    indyrescmdResponseSendDump(0x14,0x14,param_1);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdReceiveRamRom(u32 *param_1,u32 *param_2,u32 *param_3)
{
    indyrescmdResponseSize(0x20,0x20);
    indyrescmdResponseRecieveRamRom(0x14,0x14,param_1,param_2,param_3);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdAckHostExportFile(u8 *response)
{
    indyrescmdResponseSize(0x18,0x18);
    indyrescmdResponseHostExportFile(0x14,0x14,response);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 indycmdAckHostCmdPacket(u8 *response)
{
    indyrescmdResponseSize(0x18,0x18);
    indyrescmdResponseHostCmdPacket(0x14,0x14,response);
    indyrescmdResponseEnd(0,0);

    return TRUE;
}


s32 response_indyrescmd_curr_matches_expected(s32 readsize, s32 writesize)
{
    struct indy_resource_entry_header cmd;

    indycmdRecieveCommand((u8 *)&cmd, 0x14);
    if (cmd.resourceID != INDYMAGIC)
    {
        return FALSE;
    }
    
    if ((readsize != 0) && (cmd.readsize != readsize))
    {
        return FALSE;
    }

    if ((writesize != 0) && (cmd.writesize != writesize))
    {
        return FALSE;
    }

    return TRUE;
}

