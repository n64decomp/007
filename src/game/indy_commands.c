#include <ultra64.h>
#include "indy_commands.h"
#include <PR/os.h>
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





#ifdef NONMATCHING
s32 indycmdSendCommand(indy_resource_entry_header *cmd,u32 size)
{
    s32 i;
    u32 uVar1;
    u8 *address;
    u8 *pbuffer;
    u8 buffer [1280];
    u32 *id;
    
    pbuffer = buffer;
    if ((cmd->resourceID & 7) != 0) {
        if (0x500 < size) {
            return 0;
        }
        if ((*buffer & 7) != 0) {
            pbuffer = buffer + 4;
        }
        for (address = pbuffer; address < pbuffer + size; address = address + 1) {
            id = &cmd->resourceID;
            cmd = &cmd->resourceID + 1;
            *address = *id;
        }
        if (((indy_status & 0x20) != 0) && (size != 0)) {
            for (i = 1; (size & 3) != i; i += 1) {}
        }

        indy_buffer_write_command(pbuffer,size + 3 & 0xfffffffc);
        return 1;
    }
    if (((indy_status & 0x20) != 0) && (size != 0)) {

        for (i = 1; (size & 3) != i; i += 1) {}

    }

    indy_buffer_write_command(cmd,size + 3 & 0xfffffffc);
    return 1;
}
//#ifdef NONMATCHING
#else
GLOBAL_ASM(
.text
glabel indycmdSendCommand
/* 104D50 7F0D0220 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 104D54 7F0D0224 27A20040 */  addiu $v0, $sp, 0x40
/* 104D58 7F0D0228 308F0007 */  andi  $t7, $a0, 7
/* 104D5C 7F0D022C AFBF0014 */  sw    $ra, 0x14($sp)
/* 104D60 7F0D0230 AFA40540 */  sw    $a0, 0x540($sp)
/* 104D64 7F0D0234 00A03025 */  move  $a2, $a1
/* 104D68 7F0D0238 00401825 */  move  $v1, $v0
/* 104D6C 7F0D023C 11E0002B */  beqz  $t7, .L7F0D02EC
/* 104D70 7F0D0240 00403825 */   move  $a3, $v0
/* 104D74 7F0D0244 2CA10501 */  sltiu $at, $a1, 0x501
/* 104D78 7F0D0248 14200003 */  bnez  $at, .L7F0D0258
/* 104D7C 7F0D024C 30580007 */   andi  $t8, $v0, 7
/* 104D80 7F0D0250 1000003D */  b     .L7F0D0348
/* 104D84 7F0D0254 00001025 */   move  $v0, $zero
.L7F0D0258:
/* 104D88 7F0D0258 13000003 */  beqz  $t8, .L7F0D0268
/* 104D8C 7F0D025C 3C088005 */   lui   $t0, %hi(indy_status) 
/* 104D90 7F0D0260 27A70044 */  addiu $a3, $sp, 0x44
/* 104D94 7F0D0264 00E01825 */  move  $v1, $a3
.L7F0D0268:
/* 104D98 7F0D0268 00662021 */  addu  $a0, $v1, $a2
/* 104D9C 7F0D026C 0064082B */  sltu  $at, $v1, $a0
/* 104DA0 7F0D0270 10200007 */  beqz  $at, .L7F0D0290
/* 104DA4 7F0D0274 8FA20540 */   lw    $v0, 0x540($sp)
.L7F0D0278:
/* 104DA8 7F0D0278 90590000 */  lbu   $t9, ($v0)
/* 104DAC 7F0D027C 24630001 */  addiu $v1, $v1, 1
/* 104DB0 7F0D0280 0064082B */  sltu  $at, $v1, $a0
/* 104DB4 7F0D0284 24420001 */  addiu $v0, $v0, 1
/* 104DB8 7F0D0288 1420FFFB */  bnez  $at, .L7F0D0278
/* 104DBC 7F0D028C A079FFFF */   sb    $t9, -1($v1)
.L7F0D0290:
/* 104DC0 7F0D0290 8D08EAC4 */  lw    $t0, %lo(indy_status)($t0)
/* 104DC4 7F0D0294 24C50003 */  addiu $a1, $a2, 3
/* 104DC8 7F0D0298 2401FFFC */  li    $at, -4
/* 104DCC 7F0D029C 31090020 */  andi  $t1, $t0, 0x20
/* 104DD0 7F0D02A0 1120000D */  beqz  $t1, .L7F0D02D8
/* 104DD4 7F0D02A4 00A15024 */   and   $t2, $a1, $at
/* 104DD8 7F0D02A8 10C0000B */  beqz  $a2, .L7F0D02D8
/* 104DDC 7F0D02AC 00001025 */   move  $v0, $zero
/* 104DE0 7F0D02B0 30C40003 */  andi  $a0, $a2, 3
/* 104DE4 7F0D02B4 10800005 */  beqz  $a0, .L7F0D02CC
/* 104DE8 7F0D02B8 00801825 */   move  $v1, $a0
/* 104DEC 7F0D02BC 24420001 */  addiu $v0, $v0, 1
.L7F0D02C0:
/* 104DF0 7F0D02C0 5462FFFF */  bnel  $v1, $v0, .L7F0D02C0
/* 104DF4 7F0D02C4 24420001 */   addiu $v0, $v0, 1
/* 104DF8 7F0D02C8 10460003 */  beq   $v0, $a2, .L7F0D02D8
.L7F0D02CC:
/* 104DFC 7F0D02CC 24420004 */   addiu $v0, $v0, 4
.L7F0D02D0:
/* 104E00 7F0D02D0 5446FFFF */  bnel  $v0, $a2, .L7F0D02D0
/* 104E04 7F0D02D4 24420004 */   addiu $v0, $v0, 4
.L7F0D02D8:
/* 104E08 7F0D02D8 00E02025 */  move  $a0, $a3
/* 104E0C 7F0D02DC 0FC34074 */  jal   indy_buffer_write_command
/* 104E10 7F0D02E0 01402825 */   move  $a1, $t2
/* 104E14 7F0D02E4 10000018 */  b     .L7F0D0348
/* 104E18 7F0D02E8 24020001 */   li    $v0, 1
.L7F0D02EC:
/* 104E1C 7F0D02EC 3C0B8005 */  lui   $t3, %hi(indy_status) 
/* 104E20 7F0D02F0 8D6BEAC4 */  lw    $t3, %lo(indy_status)($t3)
/* 104E24 7F0D02F4 24C50003 */  addiu $a1, $a2, 3
/* 104E28 7F0D02F8 2401FFFC */  li    $at, -4
/* 104E2C 7F0D02FC 316C0020 */  andi  $t4, $t3, 0x20
/* 104E30 7F0D0300 1180000D */  beqz  $t4, .L7F0D0338
/* 104E34 7F0D0304 00A16824 */   and   $t5, $a1, $at
/* 104E38 7F0D0308 10C0000B */  beqz  $a2, .L7F0D0338
/* 104E3C 7F0D030C 00001025 */   move  $v0, $zero
/* 104E40 7F0D0310 30C40003 */  andi  $a0, $a2, 3
/* 104E44 7F0D0314 10800005 */  beqz  $a0, .L7F0D032C
/* 104E48 7F0D0318 00801825 */   move  $v1, $a0
/* 104E4C 7F0D031C 24420001 */  addiu $v0, $v0, 1
.L7F0D0320:
/* 104E50 7F0D0320 5462FFFF */  bnel  $v1, $v0, .L7F0D0320
/* 104E54 7F0D0324 24420001 */   addiu $v0, $v0, 1
/* 104E58 7F0D0328 10460003 */  beq   $v0, $a2, .L7F0D0338
.L7F0D032C:
/* 104E5C 7F0D032C 24420004 */   addiu $v0, $v0, 4
.L7F0D0330:
/* 104E60 7F0D0330 5446FFFF */  bnel  $v0, $a2, .L7F0D0330
/* 104E64 7F0D0334 24420004 */   addiu $v0, $v0, 4
.L7F0D0338:
/* 104E68 7F0D0338 8FA40540 */  lw    $a0, 0x540($sp)
/* 104E6C 7F0D033C 0FC34074 */  jal   indy_buffer_write_command
/* 104E70 7F0D0340 01A02825 */   move  $a1, $t5
/* 104E74 7F0D0344 24020001 */  li    $v0, 1
.L7F0D0348:
/* 104E78 7F0D0348 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104E7C 7F0D034C 27BD0540 */  addiu $sp, $sp, 0x540
/* 104E80 7F0D0350 03E00008 */  jr    $ra
/* 104E84 7F0D0354 00000000 */   nop   
)
#endif






s32 send2indyresourcecommands(indy_resource_entry_header * entry1, u32 size1, indy_resource_entry_header * entry2, u32 size2)
{
    indycmdSendCommand(entry1,size1);
    indycmdSendCommand(entry2,size2);
    return TRUE;
}


void indyrescmdSizeNextCmd(s32 readsize,s32 writesize)
{
    indy_resource_entry_type1 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_SIZE;
    cmd.entry.size = 0x14;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    indycmdSendCommand(&cmd,0x14);
}


void indyrescmdSendCmdEnd(s32 readsize,s32 writesize)
{
    indy_resource_entry_type2 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_END;
    cmd.entry.size = 0x14;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    indycmdSendCommand(&cmd,0x14);
}


void indyrescmdInit(s32 readsize,s32 writesize)
{
    indy_resource_entry_type0 cmd;
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_INIT;
    cmd.entry.size = 0x14;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    indycmdSendCommand(&cmd,0x14);
}

void post_type3_indyrescmd(s32 rsize,s32 wsize,char *strptr)
{
    struct indy_resource_entry_type3 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_RESCMD;
    cmd.entry.size = 0x114;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,strptr, 256);
    cmd.strbuffer[255] = 0;
    indycmdSendCommand(&cmd.entry,0x114);
}


void post_type4_indyrescmd_data_recieved(s32 readsize,s32 writesize,s32 data)
{
    indy_resource_entry_type4 cmd;
    
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_RESCMDDATARCVD;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    indycmdSendCommand(&cmd.entry,0x18);
}


void indyrescmdCheckFileExists(s32 rsize,s32 wsize,char *name)
{
  indy_resource_entry_type5 cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = INDY_SENDCHECKFILEEXISTS;
  cmd.entry.size = 0x114;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;
  strncpy(cmd.strbuffer,name,0x100);
  cmd.strbuffer[255] = '\0';
  indycmdSendCommand(&cmd,0x114);
}


void post_type6_indyrescmd_printfrecieved(s32 readsize,s32 writesize,u32 data1,u32 data2)
{
    struct indy_resource_entry_type6 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_RECVCHECKFILEEXISTS;
    cmd.entry.size = 0x1c;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    indycmdSendCommand(&cmd.entry,0x1c);
}


void indyrescmdSendFileLoad(u32 rsize,u32 wsize,u8 *filename,u32 size)
{
    struct indy_resource_entry_type7 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_SENDFILELOAD;
    cmd.entry.size = 0x118;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,filename,0x100);
    cmd.strbuffer[255] = '\0';
    cmd.size = size;
    indycmdSendCommand(&cmd,0x118);
}


void post_type8_indyrescmd_log_recieved(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 cmd2size,struct indy_resource_entry_type8 *cmd2)
{
   struct indy_resource_entry_type8 cmd;
  
   cmd.entry.resourceID = 0x9abf1623;
   cmd.entry.type = INDY_LOGRECVD;
  
   cmd.entry.size = (cmd2size +3 & ~3)+ 0x20;
   cmd.entry.readsize = rsize;
   cmd.entry.writesize = wsize;
  
   cmd.data1 = data1;
   cmd.size = cmd2size;
   cmd.data2 = data2;
   send2indyresourcecommands(&cmd,0x20,cmd2,cmd2size);
}


void indyrescmdSendDump(s32 rsize,s32 wsize,char *strptr,u32 size2,struct indy_resource_entry3 *cmd2)
{
  indy_resource_entry_type9 cmd;

  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = INDY_SENDDUMP;

  cmd.entry.size = (size2 + 3 & 0xfffffffc) + 0x114;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;

  strncpy(cmd.strbuffer,strptr,0x100);
  cmd.strbuffer[255] = '\0';
  send2indyresourcecommands(&cmd,0x114,cmd2,size2);
  
}


void post_typeA_indyrescmd_app_command_recieved(s32 readsize,s32 writesize,u32 data)
{
  indy_resource_entry_typeA cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = INDY_APPCMDRECVD;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  indycmdSendCommand(&cmd.entry,0x18);
}


void indyrescmdRamRomLoad(u32 rsize,u32 wsize,char *name,u32 filesize,u32 ptarget)
{
  indy_resource_entry_typeF cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = INDY_RAMROMLOAD;
  cmd.entry.size = 0x11c;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;
  strncpy(cmd.strbuffer,name,0x100);
  cmd.strbuffer[255] = '\0';
  cmd.size = filesize;
  cmd.hwaddress = ptarget;
  
  indycmdSendCommand(&cmd,0x11c);

}


void post_type10_indyrescmd_fault_ack_by_host(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 data3)
{
    struct indy_resource_entry_type10 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_FAULTACKHOST;
    cmd.entry.size = 0x20;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    cmd.data3 = data3;
    indycmdSendCommand(&cmd,0x20);
}


void indyrescmdSendExportFile(u32 rsize,u32 wsize,u8 *ptrstr,u32 size,u8 *hwaddress)
{
    indy_resource_entry_typeD cmd;
    
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_EXPORTFILE;
    cmd.entry.size = 0x11c;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,ptrstr,0x100);
    cmd.strbuffer[255] = '\0';
    cmd.size = size;
    cmd.hwaddress = hwaddress;
    indycmdSendCommand(&cmd,0x11c);
}


void post_typeE_indyrescmd_prof_recv(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeE cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_PROFILE_RECV;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    indycmdSendCommand(&cmd.entry,0x18);
}


void indyrescmdSendHostCmd(s32 rsize,s32 wsize,char *strptr)
{
    indy_resource_entry_typeB res;
    
    res.entry.resourceID = 0x9abf1623;
    res.entry.type = INDY_SENDHOSTCMD;
    res.entry.size = 0x414;
    res.entry.readsize = rsize;
    res.entry.writesize = wsize;
    strncpy(res.strbuffer,strptr,0x400);
    res.strbuffer[1023] = '\0';
    indycmdSendCommand(&res,0x414);
}


void post_typeC_indyrescmd_prof_send(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeC cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_PROFILE_SEND;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    indycmdSendCommand(&cmd.entry,0x18);
}


void post_typeA_indyrescmd_app_data_recieved(s32 readsize,s32 writesize,u32 data)
{
    indy_resource_entry_typeA cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = INDY_APPCMDRECVD;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    indycmdSendCommand(&cmd.entry,0x18);
}


s32 indycmdSendInitPacket(void)
{
    indyrescmdSizeNextCmd(0x14,0x14);
    indyrescmdInit(0x14,0x14);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_game_data_send(char *strptr)
{
    indyrescmdSizeNextCmd(0x114,0x114);
    post_type3_indyrescmd(0x14,0x14,strptr);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_debug_data_recv(u32 data)
{
    indyrescmdSizeNextCmd(0x18,0x18);
    post_type4_indyrescmd_data_recieved(0x14,0x14,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendHostCheckFileExists(char *strptr)
{
    indyrescmdSizeNextCmd(0x114,0x114);
    indyrescmdCheckFileExists(0x14,0x14,strptr);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_debug_printf_recv(u32 data1,u32 data2)
{
    indyrescmdSizeNextCmd(0x1c,0x1c);
    post_type6_indyrescmd_printfrecieved(0x14,0x14,data1,data2);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendLoadFile(u8 *filename,u32 size)
{
    indyrescmdSizeNextCmd(0x118,0x118);
    indyrescmdSendFileLoad(0x14,0x14,filename,size);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_1_8_2(u32 data1,u32 data2,u32 size2,struct indy_resource_entry_header *cmd2)
{
    indyrescmdSizeNextCmd((size2 + 3 & 0xfffffffc) + 0x20,0x20);
    post_type8_indyrescmd_log_recieved(0x14,0x14,data1,data2,size2,cmd2);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendDump(char *string, u32 size, struct indy_resource_entry_header *data)
{
    indyrescmdSizeNextCmd((size + 3 & 0xfffffffc) + 0x114,0x114);
    indyrescmdSendDump(0x14,0x14,string,size,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_recv_capture_data_success(u32 data)
{
    indyrescmdSizeNextCmd(0x18,0x18);
    post_typeA_indyrescmd_app_command_recieved(0x14,0x14,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendRamRomLoad(char *strptr,u32 ptarget,u32 filesize)
{
    indyrescmdSizeNextCmd(0x11c,0x11c);
    indyrescmdRamRomLoad(0x14,0x14,strptr,filesize,ptarget);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_1_10_2(u32 param_1,u32 param_2,u32 param_3)
{
    indyrescmdSizeNextCmd(0x20,0x20);
    post_type10_indyrescmd_fault_ack_by_host(0x14,0x14,param_1,param_2,param_3);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendHostExportFile(char *strptr,u8 *phwaddr,u32 size)
{
    indyrescmdSizeNextCmd(0x11c,0x11c);
    indyrescmdSendExportFile(0x14,0x14,strptr,size,phwaddr);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_host_prof_recv(u32 data)
{
    indyrescmdSizeNextCmd(0x18,0x18);
    post_typeE_indyrescmd_prof_recv(0x14,0x14,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 indycmdSendHostCmdPacket(char *strptr)
{
    indyrescmdSizeNextCmd(0x414,0x414);
    indyrescmdSendHostCmd(0x14,0x14,strptr);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_1_C_2(u32 data)
{
    indyrescmdSizeNextCmd(0x18,0x18);
    post_typeC_indyrescmd_prof_send(0x14,0x14,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}


s32 post_indyrescmd_1_A_2(u32 data)
{
    indyrescmdSizeNextCmd(0x18,0x18);
    post_typeA_indyrescmd_app_data_recieved(0x14,0x14,data);
    indyrescmdSendCmdEnd(0,0);
    return TRUE;
}






#ifdef NONMATCHING
s32 indycmdRecieveCommand(struct indy_resource_entry_header *resource,u32 size)

{
    uint uVar1;
    u32 uVar2;
    u8 *buffer;
    u8 *puVar3;
    u8 auStack1024 [1024];
    
    
    buffer = auStack1024;
    if ((resource & 7) == 0) {
        indy_buffer_read_command(resource,size + 3 & 0xfffffffc);
        if ((indy_status & 0x10) == 0) {
            return 1;
        }
        if (size != 0) {
            if ((size & 3) == 0) {
                uVar2 = 4;
            }
            else {
                for (uVar1 = 1; (size & 3) != uVar1; uVar1 += 1) {
                }
                uVar2 = uVar1 + 4;
                if (uVar1 == size) {
                    return 1;
                }
            }
            for (; uVar2 != size; uVar2 += 4) {
            }
        }
        return 1;
    }
    if (0x400 < size) {
        return 0;
    }
    if (false) {
        buffer = auStack1020;
    }
    indy_buffer_read_command(buffer,size + 3 & 0xfffffffc);
    puVar3 = buffer + size;
    for (; buffer < puVar3; buffer = buffer + 1) {
        *&resource->resourceID = *buffer;
        resource = &resource->resourceID + 1;
    }
    if (((indy_status & 0x10) != 0) && (size != 0)) {
        if ((size & 3) == 0) {
            uVar2 = 4;
        }
        else {
            for (uVar1 = 1; (size & 3) != uVar1; uVar1 += 1) {
            }
            uVar2 = uVar1 + 4;
            if (uVar1 == size) {
                return 1;
            }
        }
        for (; uVar2 != size; uVar2 += 4) {
        }
    }
    return 1;
}
#else
GLOBAL_ASM(
.text
glabel indycmdRecieveCommand
/* 105A7C 7F0D0F4C 27BDFBC0 */  addiu $sp, $sp, -0x440
/* 105A80 7F0D0F50 27A20040 */  addiu $v0, $sp, 0x40
/* 105A84 7F0D0F54 308F0007 */  andi  $t7, $a0, 7
/* 105A88 7F0D0F58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105A8C 7F0D0F5C AFA40440 */  sw    $a0, 0x440($sp)
/* 105A90 7F0D0F60 00A03025 */  move  $a2, $a1
/* 105A94 7F0D0F64 00401825 */  move  $v1, $v0
/* 105A98 7F0D0F68 11E00031 */  beqz  $t7, .L7F0D1030
/* 105A9C 7F0D0F6C 00403825 */   move  $a3, $v0
/* 105AA0 7F0D0F70 2CA10401 */  sltiu $at, $a1, 0x401
/* 105AA4 7F0D0F74 14200003 */  bnez  $at, .L7F0D0F84
/* 105AA8 7F0D0F78 30580007 */   andi  $t8, $v0, 7
/* 105AAC 7F0D0F7C 10000046 */  b     .L7F0D1098
/* 105AB0 7F0D0F80 00001025 */   move  $v0, $zero
.L7F0D0F84:
/* 105AB4 7F0D0F84 13000003 */  beqz  $t8, .L7F0D0F94
/* 105AB8 7F0D0F88 24C50003 */   addiu $a1, $a2, 3
/* 105ABC 7F0D0F8C 27A30044 */  addiu $v1, $sp, 0x44
/* 105AC0 7F0D0F90 00603825 */  move  $a3, $v1
.L7F0D0F94:
/* 105AC4 7F0D0F94 2401FFFC */  li    $at, -4
/* 105AC8 7F0D0F98 00A1C824 */  and   $t9, $a1, $at
/* 105ACC 7F0D0F9C 03202825 */  move  $a1, $t9
/* 105AD0 7F0D0FA0 00E02025 */  move  $a0, $a3
/* 105AD4 7F0D0FA4 AFA3003C */  sw    $v1, 0x3c($sp)
/* 105AD8 7F0D0FA8 0FC34060 */  jal   indy_buffer_read_command
/* 105ADC 7F0D0FAC AFA60444 */   sw    $a2, 0x444($sp)
/* 105AE0 7F0D0FB0 8FA3003C */  lw    $v1, 0x3c($sp)
/* 105AE4 7F0D0FB4 8FA60444 */  lw    $a2, 0x444($sp)
/* 105AE8 7F0D0FB8 8FA20440 */  lw    $v0, 0x440($sp)
/* 105AEC 7F0D0FBC 3C098005 */  lui   $t1, %hi(indy_status) 
/* 105AF0 7F0D0FC0 00662021 */  addu  $a0, $v1, $a2
/* 105AF4 7F0D0FC4 0064082B */  sltu  $at, $v1, $a0
/* 105AF8 7F0D0FC8 10200007 */  beqz  $at, .L7F0D0FE8
/* 105AFC 7F0D0FCC 00000000 */   nop   
.L7F0D0FD0:
/* 105B00 7F0D0FD0 90680000 */  lbu   $t0, ($v1)
/* 105B04 7F0D0FD4 24630001 */  addiu $v1, $v1, 1
/* 105B08 7F0D0FD8 0064082B */  sltu  $at, $v1, $a0
/* 105B0C 7F0D0FDC 24420001 */  addiu $v0, $v0, 1
/* 105B10 7F0D0FE0 1420FFFB */  bnez  $at, .L7F0D0FD0
/* 105B14 7F0D0FE4 A048FFFF */   sb    $t0, -1($v0)
.L7F0D0FE8:
/* 105B18 7F0D0FE8 8D29EAC4 */  lw    $t1, %lo(indy_status)($t1)
/* 105B1C 7F0D0FEC 312A0010 */  andi  $t2, $t1, 0x10
/* 105B20 7F0D0FF0 1140000D */  beqz  $t2, .L7F0D1028
/* 105B24 7F0D0FF4 00000000 */   nop   
/* 105B28 7F0D0FF8 10C0000B */  beqz  $a2, .L7F0D1028
/* 105B2C 7F0D0FFC 00001025 */   move  $v0, $zero
/* 105B30 7F0D1000 30C40003 */  andi  $a0, $a2, 3
/* 105B34 7F0D1004 10800005 */  beqz  $a0, .L7F0D101C
/* 105B38 7F0D1008 00801825 */   move  $v1, $a0
/* 105B3C 7F0D100C 24420001 */  addiu $v0, $v0, 1
.L7F0D1010:
/* 105B40 7F0D1010 5462FFFF */  bnel  $v1, $v0, .L7F0D1010
/* 105B44 7F0D1014 24420001 */   addiu $v0, $v0, 1
/* 105B48 7F0D1018 10460003 */  beq   $v0, $a2, .L7F0D1028
.L7F0D101C:
/* 105B4C 7F0D101C 24420004 */   addiu $v0, $v0, 4
.L7F0D1020:
/* 105B50 7F0D1020 5446FFFF */  bnel  $v0, $a2, .L7F0D1020
/* 105B54 7F0D1024 24420004 */   addiu $v0, $v0, 4
.L7F0D1028:
/* 105B58 7F0D1028 1000001B */  b     .L7F0D1098
/* 105B5C 7F0D102C 24020001 */   li    $v0, 1
.L7F0D1030:
/* 105B60 7F0D1030 24C50003 */  addiu $a1, $a2, 3
/* 105B64 7F0D1034 2401FFFC */  li    $at, -4
/* 105B68 7F0D1038 00A15824 */  and   $t3, $a1, $at
/* 105B6C 7F0D103C 01602825 */  move  $a1, $t3
/* 105B70 7F0D1040 8FA40440 */  lw    $a0, 0x440($sp)
/* 105B74 7F0D1044 0FC34060 */  jal   indy_buffer_read_command
/* 105B78 7F0D1048 AFA60444 */   sw    $a2, 0x444($sp)
/* 105B7C 7F0D104C 3C0C8005 */  lui   $t4, %hi(indy_status) 
/* 105B80 7F0D1050 8D8CEAC4 */  lw    $t4, %lo(indy_status)($t4)
/* 105B84 7F0D1054 8FA60444 */  lw    $a2, 0x444($sp)
/* 105B88 7F0D1058 318D0010 */  andi  $t5, $t4, 0x10
/* 105B8C 7F0D105C 51A0000E */  beql  $t5, $zero, .L7F0D1098
/* 105B90 7F0D1060 24020001 */   li    $v0, 1
/* 105B94 7F0D1064 10C0000B */  beqz  $a2, .L7F0D1094
/* 105B98 7F0D1068 00001025 */   move  $v0, $zero
/* 105B9C 7F0D106C 30C40003 */  andi  $a0, $a2, 3
/* 105BA0 7F0D1070 10800005 */  beqz  $a0, .L7F0D1088
/* 105BA4 7F0D1074 00801825 */   move  $v1, $a0
/* 105BA8 7F0D1078 24420001 */  addiu $v0, $v0, 1
.L7F0D107C:
/* 105BAC 7F0D107C 5462FFFF */  bnel  $v1, $v0, .L7F0D107C
/* 105BB0 7F0D1080 24420001 */   addiu $v0, $v0, 1
/* 105BB4 7F0D1084 10460003 */  beq   $v0, $a2, .L7F0D1094
.L7F0D1088:
/* 105BB8 7F0D1088 24420004 */   addiu $v0, $v0, 4
.L7F0D108C:
/* 105BBC 7F0D108C 5446FFFF */  bnel  $v0, $a2, .L7F0D108C
/* 105BC0 7F0D1090 24420004 */   addiu $v0, $v0, 4
.L7F0D1094:
/* 105BC4 7F0D1094 24020001 */  li    $v0, 1
.L7F0D1098:
/* 105BC8 7F0D1098 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105BCC 7F0D109C 27BD0440 */  addiu $sp, $sp, 0x440
/* 105BD0 7F0D10A0 03E00008 */  jr    $ra
/* 105BD4 7F0D10A4 00000000 */   nop   
)
#endif






s32 post_indyrescmd_read_2commands(u8 *buffer1,u32 size1,u8 *buffer2,u32 size2)
{
    indy_buffer_read_command(buffer1,size1 + 3 & 0xfffffffc);
    indy_buffer_read_command(buffer2,size2 + 3 & 0xfffffffc);
    return TRUE;
}


s32 indyrescmdResponseSize(s32 readsize, s32 writesize)
{
    struct indy_resource_entry_header cmd;
    u32 ret;

    indycmdRecieveCommand(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x1C);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x20);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return FALSE;
    }
    if (cmd.entry.type != 8)
    {
        return FALSE;
    }
    if (cmd.entry.size != (((cmd.size + 3) & ~3) + 0x20))
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
    indycmdRecieveCommand(child, (cmd.size + 3) & ~3);
    return TRUE;
}


s32 indyrescmdResponseSendDump(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_typeA cmd;

    indycmdRecieveCommand(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x20);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
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

    indycmdRecieveCommand(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
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

