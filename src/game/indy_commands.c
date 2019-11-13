#include "ultra64.h"
#include "game/indy_commands.h"

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


#ifdef NONMATCHING
void sub_GAME_7F0D0180(u8 *buffer,u32 size)
{
  int i;
  
  for (i = 4; i != 100000; i + 4){;}
  rmon_debug_stub_0();
  for (i = 4; i != 100000; i + 4){;}
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0180
/* 104CB0 7F0D0180 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104CB4 7F0D0184 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104CB8 7F0D0188 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104CBC 7F0D018C 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104CC0 7F0D0190 00001025 */  move  $v0, $zero
/* 104CC4 7F0D0194 24420004 */  addiu $v0, $v0, 4
.L7F0D0198:
/* 104CC8 7F0D0198 5443FFFF */  bnel  $v0, $v1, .L7F0D0198
/* 104CCC 7F0D019C 24420004 */   addiu $v0, $v0, 4
/* 104CD0 7F0D01A0 0C0033B0 */  jal   rmon_debug_stub_0
/* 104CD4 7F0D01A4 00000000 */   nop   
/* 104CD8 7F0D01A8 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104CDC 7F0D01AC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104CE0 7F0D01B0 00001025 */  move  $v0, $zero
/* 104CE4 7F0D01B4 24420004 */  addiu $v0, $v0, 4
.L7F0D01B8:
/* 104CE8 7F0D01B8 5443FFFF */  bnel  $v0, $v1, .L7F0D01B8
/* 104CEC 7F0D01BC 24420004 */   addiu $v0, $v0, 4
/* 104CF0 7F0D01C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104CF4 7F0D01C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 104CF8 7F0D01C8 03E00008 */  jr    $ra
/* 104CFC 7F0D01CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D01D0(u8 *buffer,u32 size)
{
  int i;
  
  for (i = 4; i != 100000; i + 4){;}
  rmon_debug_stub();
  for (i = 4; i != 100000; i + 4){;}
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D01D0
/* 104D00 7F0D01D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104D04 7F0D01D4 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104D08 7F0D01D8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104D0C 7F0D01DC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104D10 7F0D01E0 00001025 */  move  $v0, $zero
/* 104D14 7F0D01E4 24420004 */  addiu $v0, $v0, 4
.L7F0D01E8:
/* 104D18 7F0D01E8 5443FFFF */  bnel  $v0, $v1, .L7F0D01E8
/* 104D1C 7F0D01EC 24420004 */   addiu $v0, $v0, 4
/* 104D20 7F0D01F0 0C0033AE */  jal   rmon_debug_stub
/* 104D24 7F0D01F4 00000000 */   nop   
/* 104D28 7F0D01F8 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104D2C 7F0D01FC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104D30 7F0D0200 00001025 */  move  $v0, $zero
/* 104D34 7F0D0204 24420004 */  addiu $v0, $v0, 4
.L7F0D0208:
/* 104D38 7F0D0208 5443FFFF */  bnel  $v0, $v1, .L7F0D0208
/* 104D3C 7F0D020C 24420004 */   addiu $v0, $v0, 4
/* 104D40 7F0D0210 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104D44 7F0D0214 27BD0018 */  addiu $sp, $sp, 0x18
/* 104D48 7F0D0218 03E00008 */  jr    $ra
/* 104D4C 7F0D021C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void postindyresourcecommand(indy_resource_entry *param_1,u32 param_2)
{

}
#else
GLOBAL_ASM(
.text
glabel postindyresourcecommand
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
/* 104E0C 7F0D02DC 0FC34074 */  jal   sub_GAME_7F0D01D0
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
/* 104E6C 7F0D033C 0FC34074 */  jal   sub_GAME_7F0D01D0
/* 104E70 7F0D0340 01A02825 */   move  $a1, $t5
/* 104E74 7F0D0344 24020001 */  li    $v0, 1
.L7F0D0348:
/* 104E78 7F0D0348 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104E7C 7F0D034C 27BD0540 */  addiu $sp, $sp, 0x540
/* 104E80 7F0D0350 03E00008 */  jr    $ra
/* 104E84 7F0D0354 00000000 */   nop   
)
#endif






u32 send2indyresourcecommands(struct indy_resource_entry * entry1, u32 size1, struct indy_resource_entry * entry2, u32 size2)
{
    postindyresourcecommand(entry1,size1);
    postindyresourcecommand(entry2,size2);
    return 1;
}


void post_type1_indyrescmd_sizenextcmd(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;

    cmd.resourceID = 0x9abf1623;
    cmd.type = 1;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}


void post_type2_indyrescmd_cmds_rdy_to_proc(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;

    cmd.resourceID = 0x9abf1623;
    cmd.type = 2;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}


void post_type0_indyrescmd_init(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;
    cmd.resourceID = 0x9abf1623;
    cmd.type = 0;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}

#ifdef NONMATCHING
void post_type3_indyrescmd(s32 rsize,s32 wsize,char *strptr)
{
    struct indy_resource_entry_type3 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 3;
    cmd.entry.size = 0x114;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    something_with_strings(cmd.strbuffer,strptr,0x100);
    cmd.data = 0;
    postindyresourcecommand(&cmd.entry,0x114);
}
#else
GLOBAL_ASM(
.text
glabel post_type3_indyrescmd
/* 104F90 7F0D0460 27BDFED0 */  addiu $sp, $sp, -0x130
/* 104F94 7F0D0464 AFA50134 */  sw    $a1, 0x134($sp)
/* 104F98 7F0D0468 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104F9C 7F0D046C AFA5002C */  sw    $a1, 0x2c($sp)
/* 104FA0 7F0D0470 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104FA4 7F0D0474 AFA60138 */  sw    $a2, 0x138($sp)
/* 104FA8 7F0D0478 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 104FAC 7F0D047C 240F0003 */  li    $t7, 3
/* 104FB0 7F0D0480 24180114 */  li    $t8, 276
/* 104FB4 7F0D0484 AFA40028 */  sw    $a0, 0x28($sp)
/* 104FB8 7F0D0488 00C02825 */  move  $a1, $a2
/* 104FBC 7F0D048C AFAE001C */  sw    $t6, 0x1c($sp)
/* 104FC0 7F0D0490 AFAF0020 */  sw    $t7, 0x20($sp)
/* 104FC4 7F0D0494 AFB80024 */  sw    $t8, 0x24($sp)
/* 104FC8 7F0D0498 24060100 */  li    $a2, 256
/* 104FCC 7F0D049C 0C0029E8 */  jal   something_with_strings
/* 104FD0 7F0D04A0 27A40030 */   addiu $a0, $sp, 0x30
/* 104FD4 7F0D04A4 A3A0012F */  sb    $zero, 0x12f($sp)
/* 104FD8 7F0D04A8 27A4001C */  addiu $a0, $sp, 0x1c
/* 104FDC 7F0D04AC 0FC34088 */  jal   postindyresourcecommand
/* 104FE0 7F0D04B0 24050114 */   li    $a1, 276
/* 104FE4 7F0D04B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104FE8 7F0D04B8 27BD0130 */  addiu $sp, $sp, 0x130
/* 104FEC 7F0D04BC 03E00008 */  jr    $ra
/* 104FF0 7F0D04C0 00000000 */   nop   
)
#endif






void post_type4_indyrescmd_data_recieved(s32 readsize,s32 writesize,s32 data)
{
    struct indy_resource_entry_type4 cmd;
    
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 4;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}






#ifdef NONMATCHING
void post_type5_indyrescmd_printfsend(s32 param_1,s32 param_2,char *param_3)
{
    struct indy_resource_entry cmd;
    char acStack256 [255];
    undefined uStack1;
    
    cmd.resourceID = 0x9abf1623;
    cmd.type = 5;
    cmd.size = 0x114;
    cmd.readsize = param_1;
    cmd.writesize = param_2;
    something_with_strings(acStack256,param_3,0x100);
    uStack1 = 0;
    postindyresourcecommand(&cmd,0x114);
}
#else
GLOBAL_ASM(
.text
glabel post_type5_indyrescmd_printfsend
/* 105044 7F0D0514 27BDFED0 */  addiu $sp, $sp, -0x130
/* 105048 7F0D0518 AFA50134 */  sw    $a1, 0x134($sp)
/* 10504C 7F0D051C 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105050 7F0D0520 AFA5002C */  sw    $a1, 0x2c($sp)
/* 105054 7F0D0524 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105058 7F0D0528 AFA60138 */  sw    $a2, 0x138($sp)
/* 10505C 7F0D052C 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105060 7F0D0530 240F0005 */  li    $t7, 5
/* 105064 7F0D0534 24180114 */  li    $t8, 276
/* 105068 7F0D0538 AFA40028 */  sw    $a0, 0x28($sp)
/* 10506C 7F0D053C 00C02825 */  move  $a1, $a2
/* 105070 7F0D0540 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105074 7F0D0544 AFAF0020 */  sw    $t7, 0x20($sp)
/* 105078 7F0D0548 AFB80024 */  sw    $t8, 0x24($sp)
/* 10507C 7F0D054C 24060100 */  li    $a2, 256
/* 105080 7F0D0550 0C0029E8 */  jal   something_with_strings
/* 105084 7F0D0554 27A40030 */   addiu $a0, $sp, 0x30
/* 105088 7F0D0558 A3A0012F */  sb    $zero, 0x12f($sp)
/* 10508C 7F0D055C 27A4001C */  addiu $a0, $sp, 0x1c
/* 105090 7F0D0560 0FC34088 */  jal   postindyresourcecommand
/* 105094 7F0D0564 24050114 */   li    $a1, 276
/* 105098 7F0D0568 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10509C 7F0D056C 27BD0130 */  addiu $sp, $sp, 0x130
/* 1050A0 7F0D0570 03E00008 */  jr    $ra
/* 1050A4 7F0D0574 00000000 */   nop   
)
#endif






void post_type6_indyrescmd_printfrecieved(s32 readsize,s32 writesize,u32 data1,u32 data2)
{
    struct indy_resource_entry_type6 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 6;
    cmd.entry.size = 0x1c;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    postindyresourcecommand(&cmd.entry,0x1c);
}



#ifdef NONMATCHING
void post_type7_indyrescmd_log_send(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_type7_indyrescmd_log_send
/* 105100 7F0D05D0 27BDFED0 */  addiu $sp, $sp, -0x130
/* 105104 7F0D05D4 AFA50134 */  sw    $a1, 0x134($sp)
/* 105108 7F0D05D8 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 10510C 7F0D05DC AFA50028 */  sw    $a1, 0x28($sp)
/* 105110 7F0D05E0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105114 7F0D05E4 AFA40130 */  sw    $a0, 0x130($sp)
/* 105118 7F0D05E8 AFA60138 */  sw    $a2, 0x138($sp)
/* 10511C 7F0D05EC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105120 7F0D05F0 240F0007 */  li    $t7, 7
/* 105124 7F0D05F4 24180118 */  li    $t8, 280
/* 105128 7F0D05F8 AFA40024 */  sw    $a0, 0x24($sp)
/* 10512C 7F0D05FC 00C02825 */  move  $a1, $a2
/* 105130 7F0D0600 AFA7013C */  sw    $a3, 0x13c($sp)
/* 105134 7F0D0604 AFAE0018 */  sw    $t6, 0x18($sp)
/* 105138 7F0D0608 AFAF001C */  sw    $t7, 0x1c($sp)
/* 10513C 7F0D060C AFB80020 */  sw    $t8, 0x20($sp)
/* 105140 7F0D0610 24060100 */  li    $a2, 256
/* 105144 7F0D0614 0C0029E8 */  jal   something_with_strings
/* 105148 7F0D0618 27A4002C */   addiu $a0, $sp, 0x2c
/* 10514C 7F0D061C 8FA9013C */  lw    $t1, 0x13c($sp)
/* 105150 7F0D0620 A3A0012B */  sb    $zero, 0x12b($sp)
/* 105154 7F0D0624 27A40018 */  addiu $a0, $sp, 0x18
/* 105158 7F0D0628 24050118 */  li    $a1, 280
/* 10515C 7F0D062C 0FC34088 */  jal   postindyresourcecommand
/* 105160 7F0D0630 AFA9012C */   sw    $t1, 0x12c($sp)
/* 105164 7F0D0634 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105168 7F0D0638 27BD0130 */  addiu $sp, $sp, 0x130
/* 10516C 7F0D063C 03E00008 */  jr    $ra
/* 105170 7F0D0640 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_type8_indyrescmd_log_recieved(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_type8_indyrescmd_log_recieved
/* 105174 7F0D0644 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105178 7F0D0648 AFA70044 */  sw    $a3, 0x44($sp)
/* 10517C 7F0D064C 8FA70048 */  lw    $a3, 0x48($sp)
/* 105180 7F0D0650 2401FFFC */  li    $at, -4
/* 105184 7F0D0654 8FAC0044 */  lw    $t4, 0x44($sp)
/* 105188 7F0D0658 24F80003 */  addiu $t8, $a3, 3
/* 10518C 7F0D065C 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105190 7F0D0660 0301C824 */  and   $t9, $t8, $at
/* 105194 7F0D0664 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105198 7F0D0668 AFA40038 */  sw    $a0, 0x38($sp)
/* 10519C 7F0D066C AFA5003C */  sw    $a1, 0x3c($sp)
/* 1051A0 7F0D0670 AFA60040 */  sw    $a2, 0x40($sp)
/* 1051A4 7F0D0674 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1051A8 7F0D0678 240F0008 */  li    $t7, 8
/* 1051AC 7F0D067C 27280020 */  addiu $t0, $t9, 0x20
/* 1051B0 7F0D0680 AFA40024 */  sw    $a0, 0x24($sp)
/* 1051B4 7F0D0684 AFA50028 */  sw    $a1, 0x28($sp)
/* 1051B8 7F0D0688 AFA6002C */  sw    $a2, 0x2c($sp)
/* 1051BC 7F0D068C AFAE0018 */  sw    $t6, 0x18($sp)
/* 1051C0 7F0D0690 AFAF001C */  sw    $t7, 0x1c($sp)
/* 1051C4 7F0D0694 AFA80020 */  sw    $t0, 0x20($sp)
/* 1051C8 7F0D0698 8FA6004C */  lw    $a2, 0x4c($sp)
/* 1051CC 7F0D069C 24050020 */  li    $a1, 32
/* 1051D0 7F0D06A0 27A40018 */  addiu $a0, $sp, 0x18
/* 1051D4 7F0D06A4 AFA70034 */  sw    $a3, 0x34($sp)
/* 1051D8 7F0D06A8 0FC340D6 */  jal   send2indyresourcecommands
/* 1051DC 7F0D06AC AFAC0030 */   sw    $t4, 0x30($sp)
/* 1051E0 7F0D06B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1051E4 7F0D06B4 27BD0038 */  addiu $sp, $sp, 0x38
/* 1051E8 7F0D06B8 03E00008 */  jr    $ra
/* 1051EC 7F0D06BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_type9_indyrescmd_app_command_ready(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_type9_indyrescmd_app_command_ready
/* 1051F0 7F0D06C0 27BDFED0 */  addiu $sp, $sp, -0x130
/* 1051F4 7F0D06C4 24F90003 */  addiu $t9, $a3, 3
/* 1051F8 7F0D06C8 2401FFFC */  li    $at, -4
/* 1051FC 7F0D06CC AFA50134 */  sw    $a1, 0x134($sp)
/* 105200 7F0D06D0 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105204 7F0D06D4 03214024 */  and   $t0, $t9, $at
/* 105208 7F0D06D8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 10520C 7F0D06DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 105210 7F0D06E0 AFA40130 */  sw    $a0, 0x130($sp)
/* 105214 7F0D06E4 AFA60138 */  sw    $a2, 0x138($sp)
/* 105218 7F0D06E8 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 10521C 7F0D06EC 240F0009 */  li    $t7, 9
/* 105220 7F0D06F0 25090114 */  addiu $t1, $t0, 0x114
/* 105224 7F0D06F4 AFA40028 */  sw    $a0, 0x28($sp)
/* 105228 7F0D06F8 00C02825 */  move  $a1, $a2
/* 10522C 7F0D06FC AFA7013C */  sw    $a3, 0x13c($sp)
/* 105230 7F0D0700 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105234 7F0D0704 AFAF0020 */  sw    $t7, 0x20($sp)
/* 105238 7F0D0708 AFA90024 */  sw    $t1, 0x24($sp)
/* 10523C 7F0D070C 24060100 */  li    $a2, 256
/* 105240 7F0D0710 0C0029E8 */  jal   something_with_strings
/* 105244 7F0D0714 27A40030 */   addiu $a0, $sp, 0x30
/* 105248 7F0D0718 A3A0012F */  sb    $zero, 0x12f($sp)
/* 10524C 7F0D071C 27A4001C */  addiu $a0, $sp, 0x1c
/* 105250 7F0D0720 24050114 */  li    $a1, 276
/* 105254 7F0D0724 8FA60140 */  lw    $a2, 0x140($sp)
/* 105258 7F0D0728 0FC340D6 */  jal   send2indyresourcecommands
/* 10525C 7F0D072C 8FA7013C */   lw    $a3, 0x13c($sp)
/* 105260 7F0D0730 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105264 7F0D0734 27BD0130 */  addiu $sp, $sp, 0x130
/* 105268 7F0D0738 03E00008 */  jr    $ra
/* 10526C 7F0D073C 00000000 */   nop   
)
#endif




void post_typeA_indyrescmd_app_command_recieved(s32 readsize,s32 writesize,u32 data)
{
  struct indy_resource_entry_type4 cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 10;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry,0x18);
}





#ifdef NONMATCHING
void post_typeF_indyrescmd_fault_send(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_typeF_indyrescmd_fault_send
/* 1052C0 7F0D0790 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 1052C4 7F0D0794 AFA5013C */  sw    $a1, 0x13c($sp)
/* 1052C8 7F0D0798 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1052CC 7F0D079C AFA5002C */  sw    $a1, 0x2c($sp)
/* 1052D0 7F0D07A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1052D4 7F0D07A4 AFA40138 */  sw    $a0, 0x138($sp)
/* 1052D8 7F0D07A8 AFA60140 */  sw    $a2, 0x140($sp)
/* 1052DC 7F0D07AC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1052E0 7F0D07B0 240F000F */  li    $t7, 15
/* 1052E4 7F0D07B4 2418011C */  li    $t8, 284
/* 1052E8 7F0D07B8 AFA40028 */  sw    $a0, 0x28($sp)
/* 1052EC 7F0D07BC 00C02825 */  move  $a1, $a2
/* 1052F0 7F0D07C0 AFA70144 */  sw    $a3, 0x144($sp)
/* 1052F4 7F0D07C4 AFAE001C */  sw    $t6, 0x1c($sp)
/* 1052F8 7F0D07C8 AFAF0020 */  sw    $t7, 0x20($sp)
/* 1052FC 7F0D07CC AFB80024 */  sw    $t8, 0x24($sp)
/* 105300 7F0D07D0 24060100 */  li    $a2, 256
/* 105304 7F0D07D4 0C0029E8 */  jal   something_with_strings
/* 105308 7F0D07D8 27A40030 */   addiu $a0, $sp, 0x30
/* 10530C 7F0D07DC 8FA90144 */  lw    $t1, 0x144($sp)
/* 105310 7F0D07E0 8FAA0148 */  lw    $t2, 0x148($sp)
/* 105314 7F0D07E4 A3A0012F */  sb    $zero, 0x12f($sp)
/* 105318 7F0D07E8 27A4001C */  addiu $a0, $sp, 0x1c
/* 10531C 7F0D07EC 2405011C */  li    $a1, 284
/* 105320 7F0D07F0 AFA90130 */  sw    $t1, 0x130($sp)
/* 105324 7F0D07F4 0FC34088 */  jal   postindyresourcecommand
/* 105328 7F0D07F8 AFAA0134 */   sw    $t2, 0x134($sp)
/* 10532C 7F0D07FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105330 7F0D0800 27BD0138 */  addiu $sp, $sp, 0x138
/* 105334 7F0D0804 03E00008 */  jr    $ra
/* 105338 7F0D0808 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_type10_indyrescmd_fault_ack_by_host(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_type10_indyrescmd_fault_ack_by_host
/* 10533C 7F0D080C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105340 7F0D0810 8FA90048 */  lw    $t1, 0x48($sp)
/* 105344 7F0D0814 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105348 7F0D0818 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10534C 7F0D081C AFA40038 */  sw    $a0, 0x38($sp)
/* 105350 7F0D0820 AFA5003C */  sw    $a1, 0x3c($sp)
/* 105354 7F0D0824 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105358 7F0D0828 240F0010 */  li    $t7, 16
/* 10535C 7F0D082C 24180020 */  li    $t8, 32
/* 105360 7F0D0830 AFA40024 */  sw    $a0, 0x24($sp)
/* 105364 7F0D0834 AFA50028 */  sw    $a1, 0x28($sp)
/* 105368 7F0D0838 AFAE0018 */  sw    $t6, 0x18($sp)
/* 10536C 7F0D083C AFAF001C */  sw    $t7, 0x1c($sp)
/* 105370 7F0D0840 AFB80020 */  sw    $t8, 0x20($sp)
/* 105374 7F0D0844 AFA6002C */  sw    $a2, 0x2c($sp)
/* 105378 7F0D0848 AFA70030 */  sw    $a3, 0x30($sp)
/* 10537C 7F0D084C 24050020 */  li    $a1, 32
/* 105380 7F0D0850 27A40018 */  addiu $a0, $sp, 0x18
/* 105384 7F0D0854 0FC34088 */  jal   postindyresourcecommand
/* 105388 7F0D0858 AFA90034 */   sw    $t1, 0x34($sp)
/* 10538C 7F0D085C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105390 7F0D0860 27BD0038 */  addiu $sp, $sp, 0x38
/* 105394 7F0D0864 03E00008 */  jr    $ra
/* 105398 7F0D0868 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_typeD_indyrescmd_prof_send_filename(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_typeD_indyrescmd_prof_send_filename
/* 10539C 7F0D086C 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 1053A0 7F0D0870 AFA5013C */  sw    $a1, 0x13c($sp)
/* 1053A4 7F0D0874 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1053A8 7F0D0878 AFA5002C */  sw    $a1, 0x2c($sp)
/* 1053AC 7F0D087C AFBF0014 */  sw    $ra, 0x14($sp)
/* 1053B0 7F0D0880 AFA40138 */  sw    $a0, 0x138($sp)
/* 1053B4 7F0D0884 AFA60140 */  sw    $a2, 0x140($sp)
/* 1053B8 7F0D0888 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1053BC 7F0D088C 240F000D */  li    $t7, 13
/* 1053C0 7F0D0890 2418011C */  li    $t8, 284
/* 1053C4 7F0D0894 AFA40028 */  sw    $a0, 0x28($sp)
/* 1053C8 7F0D0898 00C02825 */  move  $a1, $a2
/* 1053CC 7F0D089C AFA70144 */  sw    $a3, 0x144($sp)
/* 1053D0 7F0D08A0 AFAE001C */  sw    $t6, 0x1c($sp)
/* 1053D4 7F0D08A4 AFAF0020 */  sw    $t7, 0x20($sp)
/* 1053D8 7F0D08A8 AFB80024 */  sw    $t8, 0x24($sp)
/* 1053DC 7F0D08AC 24060100 */  li    $a2, 256
/* 1053E0 7F0D08B0 0C0029E8 */  jal   something_with_strings
/* 1053E4 7F0D08B4 27A40030 */   addiu $a0, $sp, 0x30
/* 1053E8 7F0D08B8 8FA90144 */  lw    $t1, 0x144($sp)
/* 1053EC 7F0D08BC 8FAA0148 */  lw    $t2, 0x148($sp)
/* 1053F0 7F0D08C0 A3A0012F */  sb    $zero, 0x12f($sp)
/* 1053F4 7F0D08C4 27A4001C */  addiu $a0, $sp, 0x1c
/* 1053F8 7F0D08C8 2405011C */  li    $a1, 284
/* 1053FC 7F0D08CC AFA90130 */  sw    $t1, 0x130($sp)
/* 105400 7F0D08D0 0FC34088 */  jal   postindyresourcecommand
/* 105404 7F0D08D4 AFAA0134 */   sw    $t2, 0x134($sp)
/* 105408 7F0D08D8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10540C 7F0D08DC 27BD0138 */  addiu $sp, $sp, 0x138
/* 105410 7F0D08E0 03E00008 */  jr    $ra
/* 105414 7F0D08E4 00000000 */   nop   
)
#endif






void post_typeE_indyrescmd_prof_recv(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0xe;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}





#ifdef NONMATCHING
void post_typeB_indyrescmd_host_prof_req(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_typeB_indyrescmd_host_prof_req
/* 105468 7F0D0938 27BDFBD0 */  addiu $sp, $sp, -0x430
/* 10546C 7F0D093C AFA50434 */  sw    $a1, 0x434($sp)
/* 105470 7F0D0940 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105474 7F0D0944 AFA5002C */  sw    $a1, 0x2c($sp)
/* 105478 7F0D0948 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10547C 7F0D094C AFA60438 */  sw    $a2, 0x438($sp)
/* 105480 7F0D0950 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105484 7F0D0954 240F000B */  li    $t7, 11
/* 105488 7F0D0958 24180414 */  li    $t8, 1044
/* 10548C 7F0D095C AFA40028 */  sw    $a0, 0x28($sp)
/* 105490 7F0D0960 00C02825 */  move  $a1, $a2
/* 105494 7F0D0964 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105498 7F0D0968 AFAF0020 */  sw    $t7, 0x20($sp)
/* 10549C 7F0D096C AFB80024 */  sw    $t8, 0x24($sp)
/* 1054A0 7F0D0970 24060400 */  li    $a2, 1024
/* 1054A4 7F0D0974 0C0029E8 */  jal   something_with_strings
/* 1054A8 7F0D0978 27A40030 */   addiu $a0, $sp, 0x30
/* 1054AC 7F0D097C A3A0042F */  sb    $zero, 0x42f($sp)
/* 1054B0 7F0D0980 27A4001C */  addiu $a0, $sp, 0x1c
/* 1054B4 7F0D0984 0FC34088 */  jal   postindyresourcecommand
/* 1054B8 7F0D0988 24050414 */   li    $a1, 1044
/* 1054BC 7F0D098C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1054C0 7F0D0990 27BD0430 */  addiu $sp, $sp, 0x430
/* 1054C4 7F0D0994 03E00008 */  jr    $ra
/* 1054C8 7F0D0998 00000000 */   nop   
)
#endif






void post_typeC_indyrescmd_prof_send(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0xc;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


void post_typeA_indyrescmd_app_data_recieved(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 10;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


u32 post_indy__res_cmd_initialize_seq(void)
{
    post_type1_indyrescmd_sizenextcmd(0x14,0x14);
    post_type0_indyrescmd_init(0x14,0x14);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_data_send(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x114,0x114);
    post_type3_indyrescmd(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_debug_data_recv(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_type4_indyrescmd_data_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_printf_send(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x114,0x114);
    post_type5_indyrescmd_printfsend(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_debug_printf_recv(u32 data1,u32 data2)
{
    post_type1_indyrescmd_sizenextcmd(0x1c,0x1c);
    post_type6_indyrescmd_printfrecieved(0x14,0x14,data1,data2);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_req_filename_size(u8 *filename,u32 size)
{
    post_type1_indyrescmd_sizenextcmd(0x118,0x118);
    post_type7_indyrescmd_log_send(0x14,0x14,filename,size);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_8_2(u32 data1,u32 data2,u32 size2,struct indy_resource_entry *cmd2)
{
    post_type1_indyrescmd_sizenextcmd((size2 + 3 & 0xfffffffc) + 0x20,0x20);
    post_type8_indyrescmd_log_recieved(0x14,0x14,data1,data2,size2,cmd2);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_send_capture_data(char *string, u32 size, struct indy_resource_entry *data)
{
    post_type1_indyrescmd_sizenextcmd((size + 3 & 0xfffffffc) + 0x114,0x114);
    post_type9_indyrescmd_app_command_ready(0x14,0x14,string,size,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_recv_capture_data_success(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeA_indyrescmd_app_command_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_request_ramrom_file(char *strptr,u32 ptarget,u32 filesize)
{
    post_type1_indyrescmd_sizenextcmd(0x11c,0x11c);
    post_typeF_indyrescmd_fault_send(0x14,0x14,strptr,filesize,ptarget);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_10_2(u32 param_1,u32 param_2,u32 param_3)
{
    post_type1_indyrescmd_sizenextcmd(0x20,0x20);
    post_type10_indyrescmd_fault_ack_by_host(0x14,0x14,param_1,param_2,param_3);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_prof_sendfile(char *strptr,u8 *phwaddr,u32 size)
{
    post_type1_indyrescmd_sizenextcmd(0x11c,0x11c);
    post_typeD_indyrescmd_prof_send_filename(0x14,0x14,strptr,size,phwaddr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_host_prof_recv(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeE_indyrescmd_prof_recv(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_B_2(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x414,0x414);
    post_typeB_indyrescmd_host_prof_req(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_C_2(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeC_indyrescmd_prof_send(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_A_2(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeA_indyrescmd_app_data_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}






#ifdef NONMATCHING
void post_indyrescmd_read_command(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_read_command
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
/* 105AD8 7F0D0FA8 0FC34060 */  jal   sub_GAME_7F0D0180
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
/* 105B74 7F0D1044 0FC34060 */  jal   sub_GAME_7F0D0180
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






u32 post_indyrescmd_read_2commands(u8 *buffer1,u32 size1,u8 *buffer2,u32 size2)
{
    sub_GAME_7F0D0180(buffer1,size1 + 3 & 0xfffffffc);
    sub_GAME_7F0D0180(buffer2,size2 + 3 & 0xfffffffc);
    return 1;
}





#ifdef NONMATCHING
u32 post_indyrescmd_istype1_correctsize(int readsize,int writesize)
{
    u32 ret;
    struct indy_resource_entry cmd;
    
    post_indyrescmd_read_command(&cmd,0x14);
    if ((cmd.resourceID == 0x9abf1623) && (cmd.type == 1) && (cmd.size == 0x14) && ((readsize == 0) || (cmd.readsize == readsize))) {
        ret = 1;
        if (cmd.writesize != writesize) {
            ret = 0;
        }
    }
    else {
        ret = 0;
    }
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype1_correctsize
/* 105C30 7F0D1100 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105C34 7F0D1104 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105C38 7F0D1108 AFA40030 */  sw    $a0, 0x30($sp)
/* 105C3C 7F0D110C AFA50034 */  sw    $a1, 0x34($sp)
/* 105C40 7F0D1110 24050014 */  li    $a1, 20
/* 105C44 7F0D1114 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105C48 7F0D1118 27A4001C */   addiu $a0, $sp, 0x1c
/* 105C4C 7F0D111C 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105C50 7F0D1120 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105C54 7F0D1124 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105C58 7F0D1128 11C10003 */  beq   $t6, $at, .L7F0D1138
/* 105C5C 7F0D112C 8FA20030 */   lw    $v0, 0x30($sp)
/* 105C60 7F0D1130 1000001A */  b     .L7F0D119C
/* 105C64 7F0D1134 00001025 */   move  $v0, $zero
.L7F0D1138:
/* 105C68 7F0D1138 8FAF0020 */  lw    $t7, 0x20($sp)
/* 105C6C 7F0D113C 24010001 */  li    $at, 1
/* 105C70 7F0D1140 8FB80024 */  lw    $t8, 0x24($sp)
/* 105C74 7F0D1144 51E10004 */  beql  $t7, $at, .L7F0D1158
/* 105C78 7F0D1148 24010014 */   li    $at, 20
/* 105C7C 7F0D114C 10000013 */  b     .L7F0D119C
/* 105C80 7F0D1150 00001025 */   move  $v0, $zero
/* 105C84 7F0D1154 24010014 */  li    $at, 20
.L7F0D1158:
/* 105C88 7F0D1158 13010003 */  beq   $t8, $at, .L7F0D1168
/* 105C8C 7F0D115C 00000000 */   nop   
/* 105C90 7F0D1160 1000000E */  b     .L7F0D119C
/* 105C94 7F0D1164 00001025 */   move  $v0, $zero
.L7F0D1168:
/* 105C98 7F0D1168 10400005 */  beqz  $v0, .L7F0D1180
/* 105C9C 7F0D116C 8FB90028 */   lw    $t9, 0x28($sp)
/* 105CA0 7F0D1170 53220004 */  beql  $t9, $v0, .L7F0D1184
/* 105CA4 7F0D1174 8FA8002C */   lw    $t0, 0x2c($sp)
/* 105CA8 7F0D1178 10000008 */  b     .L7F0D119C
/* 105CAC 7F0D117C 00001025 */   move  $v0, $zero
.L7F0D1180:
/* 105CB0 7F0D1180 8FA8002C */  lw    $t0, 0x2c($sp)
.L7F0D1184:
/* 105CB4 7F0D1184 8FA90034 */  lw    $t1, 0x34($sp)
/* 105CB8 7F0D1188 24020001 */  li    $v0, 1
/* 105CBC 7F0D118C 11090003 */  beq   $t0, $t1, .L7F0D119C
/* 105CC0 7F0D1190 00000000 */   nop   
/* 105CC4 7F0D1194 10000001 */  b     .L7F0D119C
/* 105CC8 7F0D1198 00001025 */   move  $v0, $zero
.L7F0D119C:
/* 105CCC 7F0D119C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105CD0 7F0D11A0 27BD0030 */  addiu $sp, $sp, 0x30
/* 105CD4 7F0D11A4 03E00008 */  jr    $ra
/* 105CD8 7F0D11A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
u32 post_indyrescmd_istype2_correctvalue(int readsize,int writesize)
{
    u32 ret;
    struct indy_resource_entry cmd;
    
    post_indyrescmd_read_command(&cmd,0x14);
    if ((cmd.resourceID == 0x9abf1623) && (cmd.type == 2) && (cmd.size == 0x14) && (cmd.readsize == readsize))
    {
        ret = 1;
        if (cmd.writesize != writesize) {
            ret = 0;
        }
    }
    else {
        ret = 0;
    }
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype2_correctvalue
/* 105CDC 7F0D11AC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105CE0 7F0D11B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105CE4 7F0D11B4 AFA40030 */  sw    $a0, 0x30($sp)
/* 105CE8 7F0D11B8 AFA50034 */  sw    $a1, 0x34($sp)
/* 105CEC 7F0D11BC 24050014 */  li    $a1, 20
/* 105CF0 7F0D11C0 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105CF4 7F0D11C4 27A4001C */   addiu $a0, $sp, 0x1c
/* 105CF8 7F0D11C8 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105CFC 7F0D11CC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105D00 7F0D11D0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105D04 7F0D11D4 11C10003 */  beq   $t6, $at, .L7F0D11E4
/* 105D08 7F0D11D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 105D0C 7F0D11DC 10000018 */  b     .L7F0D1240
/* 105D10 7F0D11E0 00001025 */   move  $v0, $zero
.L7F0D11E4:
/* 105D14 7F0D11E4 8FAF0020 */  lw    $t7, 0x20($sp)
/* 105D18 7F0D11E8 24010002 */  li    $at, 2
/* 105D1C 7F0D11EC 8FB80024 */  lw    $t8, 0x24($sp)
/* 105D20 7F0D11F0 51E10004 */  beql  $t7, $at, .L7F0D1204
/* 105D24 7F0D11F4 24010014 */   li    $at, 20
/* 105D28 7F0D11F8 10000011 */  b     .L7F0D1240
/* 105D2C 7F0D11FC 00001025 */   move  $v0, $zero
/* 105D30 7F0D1200 24010014 */  li    $at, 20
.L7F0D1204:
/* 105D34 7F0D1204 13010003 */  beq   $t8, $at, .L7F0D1214
/* 105D38 7F0D1208 8FB90028 */   lw    $t9, 0x28($sp)
/* 105D3C 7F0D120C 1000000C */  b     .L7F0D1240
/* 105D40 7F0D1210 00001025 */   move  $v0, $zero
.L7F0D1214:
/* 105D44 7F0D1214 8FA80030 */  lw    $t0, 0x30($sp)
/* 105D48 7F0D1218 8FA9002C */  lw    $t1, 0x2c($sp)
/* 105D4C 7F0D121C 8FAA0034 */  lw    $t2, 0x34($sp)
/* 105D50 7F0D1220 13280003 */  beq   $t9, $t0, .L7F0D1230
/* 105D54 7F0D1224 00000000 */   nop   
/* 105D58 7F0D1228 10000005 */  b     .L7F0D1240
/* 105D5C 7F0D122C 00001025 */   move  $v0, $zero
.L7F0D1230:
/* 105D60 7F0D1230 112A0003 */  beq   $t1, $t2, .L7F0D1240
/* 105D64 7F0D1234 24020001 */   li    $v0, 1
/* 105D68 7F0D1238 10000001 */  b     .L7F0D1240
/* 105D6C 7F0D123C 00001025 */   move  $v0, $zero
.L7F0D1240:
/* 105D70 7F0D1240 03E00008 */  jr    $ra
/* 105D74 7F0D1244 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istype4_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype4_correctvalue
/* 105D78 7F0D1248 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105D7C 7F0D124C AFBF0014 */  sw    $ra, 0x14($sp)
/* 105D80 7F0D1250 AFA40030 */  sw    $a0, 0x30($sp)
/* 105D84 7F0D1254 AFA50034 */  sw    $a1, 0x34($sp)
/* 105D88 7F0D1258 AFA60038 */  sw    $a2, 0x38($sp)
/* 105D8C 7F0D125C 24050018 */  li    $a1, 24
/* 105D90 7F0D1260 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105D94 7F0D1264 27A40018 */   addiu $a0, $sp, 0x18
/* 105D98 7F0D1268 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105D9C 7F0D126C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105DA0 7F0D1270 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105DA4 7F0D1274 11C10003 */  beq   $t6, $at, .L7F0D1284
/* 105DA8 7F0D1278 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105DAC 7F0D127C 10000019 */  b     .L7F0D12E4
/* 105DB0 7F0D1280 00001025 */   move  $v0, $zero
.L7F0D1284:
/* 105DB4 7F0D1284 24010004 */  li    $at, 4
/* 105DB8 7F0D1288 11E10003 */  beq   $t7, $at, .L7F0D1298
/* 105DBC 7F0D128C 8FB80020 */   lw    $t8, 0x20($sp)
/* 105DC0 7F0D1290 10000014 */  b     .L7F0D12E4
/* 105DC4 7F0D1294 00001025 */   move  $v0, $zero
.L7F0D1298:
/* 105DC8 7F0D1298 24010018 */  li    $at, 24
/* 105DCC 7F0D129C 13010003 */  beq   $t8, $at, .L7F0D12AC
/* 105DD0 7F0D12A0 8FB90024 */   lw    $t9, 0x24($sp)
/* 105DD4 7F0D12A4 1000000F */  b     .L7F0D12E4
/* 105DD8 7F0D12A8 00001025 */   move  $v0, $zero
.L7F0D12AC:
/* 105DDC 7F0D12AC 8FA80030 */  lw    $t0, 0x30($sp)
/* 105DE0 7F0D12B0 8FA90028 */  lw    $t1, 0x28($sp)
/* 105DE4 7F0D12B4 8FAA0034 */  lw    $t2, 0x34($sp)
/* 105DE8 7F0D12B8 13280003 */  beq   $t9, $t0, .L7F0D12C8
/* 105DEC 7F0D12BC 00000000 */   nop   
/* 105DF0 7F0D12C0 10000008 */  b     .L7F0D12E4
/* 105DF4 7F0D12C4 00001025 */   move  $v0, $zero
.L7F0D12C8:
/* 105DF8 7F0D12C8 112A0003 */  beq   $t1, $t2, .L7F0D12D8
/* 105DFC 7F0D12CC 8FAB002C */   lw    $t3, 0x2c($sp)
/* 105E00 7F0D12D0 10000004 */  b     .L7F0D12E4
/* 105E04 7F0D12D4 00001025 */   move  $v0, $zero
.L7F0D12D8:
/* 105E08 7F0D12D8 8FAC0038 */  lw    $t4, 0x38($sp)
/* 105E0C 7F0D12DC 24020001 */  li    $v0, 1
/* 105E10 7F0D12E0 AD8B0000 */  sw    $t3, ($t4)
.L7F0D12E4:
/* 105E14 7F0D12E4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105E18 7F0D12E8 27BD0030 */  addiu $sp, $sp, 0x30
/* 105E1C 7F0D12EC 03E00008 */  jr    $ra
/* 105E20 7F0D12F0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istype6_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype6_correctvalue
/* 105E24 7F0D12F4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105E28 7F0D12F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105E2C 7F0D12FC AFA40038 */  sw    $a0, 0x38($sp)
/* 105E30 7F0D1300 AFA5003C */  sw    $a1, 0x3c($sp)
/* 105E34 7F0D1304 AFA60040 */  sw    $a2, 0x40($sp)
/* 105E38 7F0D1308 AFA70044 */  sw    $a3, 0x44($sp)
/* 105E3C 7F0D130C 2405001C */  li    $a1, 28
/* 105E40 7F0D1310 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105E44 7F0D1314 27A4001C */   addiu $a0, $sp, 0x1c
/* 105E48 7F0D1318 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105E4C 7F0D131C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105E50 7F0D1320 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105E54 7F0D1324 11C10003 */  beq   $t6, $at, .L7F0D1334
/* 105E58 7F0D1328 8FAF0020 */   lw    $t7, 0x20($sp)
/* 105E5C 7F0D132C 1000001C */  b     .L7F0D13A0
/* 105E60 7F0D1330 00001025 */   move  $v0, $zero
.L7F0D1334:
/* 105E64 7F0D1334 24010006 */  li    $at, 6
/* 105E68 7F0D1338 11E10003 */  beq   $t7, $at, .L7F0D1348
/* 105E6C 7F0D133C 8FB80024 */   lw    $t8, 0x24($sp)
/* 105E70 7F0D1340 10000017 */  b     .L7F0D13A0
/* 105E74 7F0D1344 00001025 */   move  $v0, $zero
.L7F0D1348:
/* 105E78 7F0D1348 2401001C */  li    $at, 28
/* 105E7C 7F0D134C 13010003 */  beq   $t8, $at, .L7F0D135C
/* 105E80 7F0D1350 8FB90028 */   lw    $t9, 0x28($sp)
/* 105E84 7F0D1354 10000012 */  b     .L7F0D13A0
/* 105E88 7F0D1358 00001025 */   move  $v0, $zero
.L7F0D135C:
/* 105E8C 7F0D135C 8FA80038 */  lw    $t0, 0x38($sp)
/* 105E90 7F0D1360 8FA9002C */  lw    $t1, 0x2c($sp)
/* 105E94 7F0D1364 8FAA003C */  lw    $t2, 0x3c($sp)
/* 105E98 7F0D1368 13280003 */  beq   $t9, $t0, .L7F0D1378
/* 105E9C 7F0D136C 00000000 */   nop   
/* 105EA0 7F0D1370 1000000B */  b     .L7F0D13A0
/* 105EA4 7F0D1374 00001025 */   move  $v0, $zero
.L7F0D1378:
/* 105EA8 7F0D1378 112A0003 */  beq   $t1, $t2, .L7F0D1388
/* 105EAC 7F0D137C 8FAB0030 */   lw    $t3, 0x30($sp)
/* 105EB0 7F0D1380 10000007 */  b     .L7F0D13A0
/* 105EB4 7F0D1384 00001025 */   move  $v0, $zero
.L7F0D1388:
/* 105EB8 7F0D1388 8FAC0040 */  lw    $t4, 0x40($sp)
/* 105EBC 7F0D138C 24020001 */  li    $v0, 1
/* 105EC0 7F0D1390 AD8B0000 */  sw    $t3, ($t4)
/* 105EC4 7F0D1394 8FAE0044 */  lw    $t6, 0x44($sp)
/* 105EC8 7F0D1398 8FAD0034 */  lw    $t5, 0x34($sp)
/* 105ECC 7F0D139C ADCD0000 */  sw    $t5, ($t6)
.L7F0D13A0:
/* 105ED0 7F0D13A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105ED4 7F0D13A4 27BD0038 */  addiu $sp, $sp, 0x38
/* 105ED8 7F0D13A8 03E00008 */  jr    $ra
/* 105EDC 7F0D13AC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istype8_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype8_correctvalue
/* 105EE0 7F0D13B0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105EE4 7F0D13B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105EE8 7F0D13B8 AFA40038 */  sw    $a0, 0x38($sp)
/* 105EEC 7F0D13BC AFA5003C */  sw    $a1, 0x3c($sp)
/* 105EF0 7F0D13C0 AFA60040 */  sw    $a2, 0x40($sp)
/* 105EF4 7F0D13C4 AFA70044 */  sw    $a3, 0x44($sp)
/* 105EF8 7F0D13C8 24050020 */  li    $a1, 32
/* 105EFC 7F0D13CC 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105F00 7F0D13D0 27A40018 */   addiu $a0, $sp, 0x18
/* 105F04 7F0D13D4 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105F08 7F0D13D8 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105F0C 7F0D13DC 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105F10 7F0D13E0 11C10003 */  beq   $t6, $at, .L7F0D13F0
/* 105F14 7F0D13E4 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105F18 7F0D13E8 10000027 */  b     .L7F0D1488
/* 105F1C 7F0D13EC 00001025 */   move  $v0, $zero
.L7F0D13F0:
/* 105F20 7F0D13F0 24010008 */  li    $at, 8
/* 105F24 7F0D13F4 11E10003 */  beq   $t7, $at, .L7F0D1404
/* 105F28 7F0D13F8 8FB90034 */   lw    $t9, 0x34($sp)
/* 105F2C 7F0D13FC 10000022 */  b     .L7F0D1488
/* 105F30 7F0D1400 00001025 */   move  $v0, $zero
.L7F0D1404:
/* 105F34 7F0D1404 8FB80020 */  lw    $t8, 0x20($sp)
/* 105F38 7F0D1408 2402FFFC */  li    $v0, -4
/* 105F3C 7F0D140C 27280003 */  addiu $t0, $t9, 3
/* 105F40 7F0D1410 01024824 */  and   $t1, $t0, $v0
/* 105F44 7F0D1414 252A0020 */  addiu $t2, $t1, 0x20
/* 105F48 7F0D1418 130A0003 */  beq   $t8, $t2, .L7F0D1428
/* 105F4C 7F0D141C 8FAB0024 */   lw    $t3, 0x24($sp)
/* 105F50 7F0D1420 10000019 */  b     .L7F0D1488
/* 105F54 7F0D1424 00001025 */   move  $v0, $zero
.L7F0D1428:
/* 105F58 7F0D1428 8FAC0038 */  lw    $t4, 0x38($sp)
/* 105F5C 7F0D142C 8FAD0028 */  lw    $t5, 0x28($sp)
/* 105F60 7F0D1430 8FAE003C */  lw    $t6, 0x3c($sp)
/* 105F64 7F0D1434 116C0003 */  beq   $t3, $t4, .L7F0D1444
/* 105F68 7F0D1438 00000000 */   nop   
/* 105F6C 7F0D143C 10000012 */  b     .L7F0D1488
/* 105F70 7F0D1440 00001025 */   move  $v0, $zero
.L7F0D1444:
/* 105F74 7F0D1444 11AE0003 */  beq   $t5, $t6, .L7F0D1454
/* 105F78 7F0D1448 8FAF002C */   lw    $t7, 0x2c($sp)
/* 105F7C 7F0D144C 1000000E */  b     .L7F0D1488
/* 105F80 7F0D1450 00001025 */   move  $v0, $zero
.L7F0D1454:
/* 105F84 7F0D1454 8FB90040 */  lw    $t9, 0x40($sp)
/* 105F88 7F0D1458 AF2F0000 */  sw    $t7, ($t9)
/* 105F8C 7F0D145C 8FA90044 */  lw    $t1, 0x44($sp)
/* 105F90 7F0D1460 8FA80030 */  lw    $t0, 0x30($sp)
/* 105F94 7F0D1464 AD280000 */  sw    $t0, ($t1)
/* 105F98 7F0D1468 8FB80034 */  lw    $t8, 0x34($sp)
/* 105F9C 7F0D146C 8FAA0048 */  lw    $t2, 0x48($sp)
/* 105FA0 7F0D1470 270B0003 */  addiu $t3, $t8, 3
/* 105FA4 7F0D1474 AD580000 */  sw    $t8, ($t2)
/* 105FA8 7F0D1478 8FA4004C */  lw    $a0, 0x4c($sp)
/* 105FAC 7F0D147C 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105FB0 7F0D1480 01622824 */   and   $a1, $t3, $v0
/* 105FB4 7F0D1484 24020001 */  li    $v0, 1
.L7F0D1488:
/* 105FB8 7F0D1488 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105FBC 7F0D148C 27BD0038 */  addiu $sp, $sp, 0x38
/* 105FC0 7F0D1490 03E00008 */  jr    $ra
/* 105FC4 7F0D1494 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istypeA_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istypeA_correctvalue
/* 105FC8 7F0D1498 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105FCC 7F0D149C AFBF0014 */  sw    $ra, 0x14($sp)
/* 105FD0 7F0D14A0 AFA40030 */  sw    $a0, 0x30($sp)
/* 105FD4 7F0D14A4 AFA50034 */  sw    $a1, 0x34($sp)
/* 105FD8 7F0D14A8 AFA60038 */  sw    $a2, 0x38($sp)
/* 105FDC 7F0D14AC 24050018 */  li    $a1, 24
/* 105FE0 7F0D14B0 0FC343D3 */  jal   post_indyrescmd_read_command
/* 105FE4 7F0D14B4 27A40018 */   addiu $a0, $sp, 0x18
/* 105FE8 7F0D14B8 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105FEC 7F0D14BC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105FF0 7F0D14C0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105FF4 7F0D14C4 11C10003 */  beq   $t6, $at, .L7F0D14D4
/* 105FF8 7F0D14C8 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105FFC 7F0D14CC 10000019 */  b     .L7F0D1534
/* 106000 7F0D14D0 00001025 */   move  $v0, $zero
.L7F0D14D4:
/* 106004 7F0D14D4 2401000A */  li    $at, 10
/* 106008 7F0D14D8 11E10003 */  beq   $t7, $at, .L7F0D14E8
/* 10600C 7F0D14DC 8FB80020 */   lw    $t8, 0x20($sp)
/* 106010 7F0D14E0 10000014 */  b     .L7F0D1534
/* 106014 7F0D14E4 00001025 */   move  $v0, $zero
.L7F0D14E8:
/* 106018 7F0D14E8 24010018 */  li    $at, 24
/* 10601C 7F0D14EC 13010003 */  beq   $t8, $at, .L7F0D14FC
/* 106020 7F0D14F0 8FB90024 */   lw    $t9, 0x24($sp)
/* 106024 7F0D14F4 1000000F */  b     .L7F0D1534
/* 106028 7F0D14F8 00001025 */   move  $v0, $zero
.L7F0D14FC:
/* 10602C 7F0D14FC 8FA80030 */  lw    $t0, 0x30($sp)
/* 106030 7F0D1500 8FA90028 */  lw    $t1, 0x28($sp)
/* 106034 7F0D1504 8FAA0034 */  lw    $t2, 0x34($sp)
/* 106038 7F0D1508 13280003 */  beq   $t9, $t0, .L7F0D1518
/* 10603C 7F0D150C 00000000 */   nop   
/* 106040 7F0D1510 10000008 */  b     .L7F0D1534
/* 106044 7F0D1514 00001025 */   move  $v0, $zero
.L7F0D1518:
/* 106048 7F0D1518 112A0003 */  beq   $t1, $t2, .L7F0D1528
/* 10604C 7F0D151C 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106050 7F0D1520 10000004 */  b     .L7F0D1534
/* 106054 7F0D1524 00001025 */   move  $v0, $zero
.L7F0D1528:
/* 106058 7F0D1528 8FAC0038 */  lw    $t4, 0x38($sp)
/* 10605C 7F0D152C 24020001 */  li    $v0, 1
/* 106060 7F0D1530 AD8B0000 */  sw    $t3, ($t4)
.L7F0D1534:
/* 106064 7F0D1534 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106068 7F0D1538 27BD0030 */  addiu $sp, $sp, 0x30
/* 10606C 7F0D153C 03E00008 */  jr    $ra
/* 106070 7F0D1540 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istype10_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istype10_correctvalue
/* 106074 7F0D1544 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 106078 7F0D1548 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10607C 7F0D154C AFA40038 */  sw    $a0, 0x38($sp)
/* 106080 7F0D1550 AFA5003C */  sw    $a1, 0x3c($sp)
/* 106084 7F0D1554 AFA60040 */  sw    $a2, 0x40($sp)
/* 106088 7F0D1558 AFA70044 */  sw    $a3, 0x44($sp)
/* 10608C 7F0D155C 24050020 */  li    $a1, 32
/* 106090 7F0D1560 0FC343D3 */  jal   post_indyrescmd_read_command
/* 106094 7F0D1564 27A40018 */   addiu $a0, $sp, 0x18
/* 106098 7F0D1568 8FAE0018 */  lw    $t6, 0x18($sp)
/* 10609C 7F0D156C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 1060A0 7F0D1570 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 1060A4 7F0D1574 11C10003 */  beq   $t6, $at, .L7F0D1584
/* 1060A8 7F0D1578 8FAF001C */   lw    $t7, 0x1c($sp)
/* 1060AC 7F0D157C 1000001F */  b     .L7F0D15FC
/* 1060B0 7F0D1580 00001025 */   move  $v0, $zero
.L7F0D1584:
/* 1060B4 7F0D1584 24010010 */  li    $at, 16
/* 1060B8 7F0D1588 11E10003 */  beq   $t7, $at, .L7F0D1598
/* 1060BC 7F0D158C 8FB80020 */   lw    $t8, 0x20($sp)
/* 1060C0 7F0D1590 1000001A */  b     .L7F0D15FC
/* 1060C4 7F0D1594 00001025 */   move  $v0, $zero
.L7F0D1598:
/* 1060C8 7F0D1598 24010020 */  li    $at, 32
/* 1060CC 7F0D159C 13010003 */  beq   $t8, $at, .L7F0D15AC
/* 1060D0 7F0D15A0 8FB90024 */   lw    $t9, 0x24($sp)
/* 1060D4 7F0D15A4 10000015 */  b     .L7F0D15FC
/* 1060D8 7F0D15A8 00001025 */   move  $v0, $zero
.L7F0D15AC:
/* 1060DC 7F0D15AC 8FA80038 */  lw    $t0, 0x38($sp)
/* 1060E0 7F0D15B0 8FA90028 */  lw    $t1, 0x28($sp)
/* 1060E4 7F0D15B4 8FAA003C */  lw    $t2, 0x3c($sp)
/* 1060E8 7F0D15B8 13280003 */  beq   $t9, $t0, .L7F0D15C8
/* 1060EC 7F0D15BC 00000000 */   nop   
/* 1060F0 7F0D15C0 1000000E */  b     .L7F0D15FC
/* 1060F4 7F0D15C4 00001025 */   move  $v0, $zero
.L7F0D15C8:
/* 1060F8 7F0D15C8 112A0003 */  beq   $t1, $t2, .L7F0D15D8
/* 1060FC 7F0D15CC 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106100 7F0D15D0 1000000A */  b     .L7F0D15FC
/* 106104 7F0D15D4 00001025 */   move  $v0, $zero
.L7F0D15D8:
/* 106108 7F0D15D8 8FAC0040 */  lw    $t4, 0x40($sp)
/* 10610C 7F0D15DC 24020001 */  li    $v0, 1
/* 106110 7F0D15E0 AD8B0000 */  sw    $t3, ($t4)
/* 106114 7F0D15E4 8FAE0044 */  lw    $t6, 0x44($sp)
/* 106118 7F0D15E8 8FAD0030 */  lw    $t5, 0x30($sp)
/* 10611C 7F0D15EC ADCD0000 */  sw    $t5, ($t6)
/* 106120 7F0D15F0 8FB80048 */  lw    $t8, 0x48($sp)
/* 106124 7F0D15F4 8FAF0034 */  lw    $t7, 0x34($sp)
/* 106128 7F0D15F8 AF0F0000 */  sw    $t7, ($t8)
.L7F0D15FC:
/* 10612C 7F0D15FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106130 7F0D1600 27BD0038 */  addiu $sp, $sp, 0x38
/* 106134 7F0D1604 03E00008 */  jr    $ra
/* 106138 7F0D1608 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istypeE_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istypeE_correctvalue
/* 10613C 7F0D160C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 106140 7F0D1610 AFBF0014 */  sw    $ra, 0x14($sp)
/* 106144 7F0D1614 AFA40030 */  sw    $a0, 0x30($sp)
/* 106148 7F0D1618 AFA50034 */  sw    $a1, 0x34($sp)
/* 10614C 7F0D161C AFA60038 */  sw    $a2, 0x38($sp)
/* 106150 7F0D1620 24050018 */  li    $a1, 24
/* 106154 7F0D1624 0FC343D3 */  jal   post_indyrescmd_read_command
/* 106158 7F0D1628 27A40018 */   addiu $a0, $sp, 0x18
/* 10615C 7F0D162C 8FAE0018 */  lw    $t6, 0x18($sp)
/* 106160 7F0D1630 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 106164 7F0D1634 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 106168 7F0D1638 11C10003 */  beq   $t6, $at, .L7F0D1648
/* 10616C 7F0D163C 8FAF001C */   lw    $t7, 0x1c($sp)
/* 106170 7F0D1640 10000019 */  b     .L7F0D16A8
/* 106174 7F0D1644 00001025 */   move  $v0, $zero
.L7F0D1648:
/* 106178 7F0D1648 2401000E */  li    $at, 14
/* 10617C 7F0D164C 11E10003 */  beq   $t7, $at, .L7F0D165C
/* 106180 7F0D1650 8FB80020 */   lw    $t8, 0x20($sp)
/* 106184 7F0D1654 10000014 */  b     .L7F0D16A8
/* 106188 7F0D1658 00001025 */   move  $v0, $zero
.L7F0D165C:
/* 10618C 7F0D165C 24010018 */  li    $at, 24
/* 106190 7F0D1660 13010003 */  beq   $t8, $at, .L7F0D1670
/* 106194 7F0D1664 8FB90024 */   lw    $t9, 0x24($sp)
/* 106198 7F0D1668 1000000F */  b     .L7F0D16A8
/* 10619C 7F0D166C 00001025 */   move  $v0, $zero
.L7F0D1670:
/* 1061A0 7F0D1670 8FA80030 */  lw    $t0, 0x30($sp)
/* 1061A4 7F0D1674 8FA90028 */  lw    $t1, 0x28($sp)
/* 1061A8 7F0D1678 8FAA0034 */  lw    $t2, 0x34($sp)
/* 1061AC 7F0D167C 13280003 */  beq   $t9, $t0, .L7F0D168C
/* 1061B0 7F0D1680 00000000 */   nop   
/* 1061B4 7F0D1684 10000008 */  b     .L7F0D16A8
/* 1061B8 7F0D1688 00001025 */   move  $v0, $zero
.L7F0D168C:
/* 1061BC 7F0D168C 112A0003 */  beq   $t1, $t2, .L7F0D169C
/* 1061C0 7F0D1690 8FAB002C */   lw    $t3, 0x2c($sp)
/* 1061C4 7F0D1694 10000004 */  b     .L7F0D16A8
/* 1061C8 7F0D1698 00001025 */   move  $v0, $zero
.L7F0D169C:
/* 1061CC 7F0D169C 8FAC0038 */  lw    $t4, 0x38($sp)
/* 1061D0 7F0D16A0 24020001 */  li    $v0, 1
/* 1061D4 7F0D16A4 AD8B0000 */  sw    $t3, ($t4)
.L7F0D16A8:
/* 1061D8 7F0D16A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1061DC 7F0D16AC 27BD0030 */  addiu $sp, $sp, 0x30
/* 1061E0 7F0D16B0 03E00008 */  jr    $ra
/* 1061E4 7F0D16B4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indyrescmd_istypeC_correctvalue(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_istypeC_correctvalue
/* 1061E8 7F0D16B8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1061EC 7F0D16BC AFBF0014 */  sw    $ra, 0x14($sp)
/* 1061F0 7F0D16C0 AFA40030 */  sw    $a0, 0x30($sp)
/* 1061F4 7F0D16C4 AFA50034 */  sw    $a1, 0x34($sp)
/* 1061F8 7F0D16C8 AFA60038 */  sw    $a2, 0x38($sp)
/* 1061FC 7F0D16CC 24050018 */  li    $a1, 24
/* 106200 7F0D16D0 0FC343D3 */  jal   post_indyrescmd_read_command
/* 106204 7F0D16D4 27A40018 */   addiu $a0, $sp, 0x18
/* 106208 7F0D16D8 8FAE0018 */  lw    $t6, 0x18($sp)
/* 10620C 7F0D16DC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 106210 7F0D16E0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 106214 7F0D16E4 11C10003 */  beq   $t6, $at, .L7F0D16F4
/* 106218 7F0D16E8 8FAF001C */   lw    $t7, 0x1c($sp)
/* 10621C 7F0D16EC 10000019 */  b     .L7F0D1754
/* 106220 7F0D16F0 00001025 */   move  $v0, $zero
.L7F0D16F4:
/* 106224 7F0D16F4 2401000C */  li    $at, 12
/* 106228 7F0D16F8 11E10003 */  beq   $t7, $at, .L7F0D1708
/* 10622C 7F0D16FC 8FB80020 */   lw    $t8, 0x20($sp)
/* 106230 7F0D1700 10000014 */  b     .L7F0D1754
/* 106234 7F0D1704 00001025 */   move  $v0, $zero
.L7F0D1708:
/* 106238 7F0D1708 24010018 */  li    $at, 24
/* 10623C 7F0D170C 13010003 */  beq   $t8, $at, .L7F0D171C
/* 106240 7F0D1710 8FB90024 */   lw    $t9, 0x24($sp)
/* 106244 7F0D1714 1000000F */  b     .L7F0D1754
/* 106248 7F0D1718 00001025 */   move  $v0, $zero
.L7F0D171C:
/* 10624C 7F0D171C 8FA80030 */  lw    $t0, 0x30($sp)
/* 106250 7F0D1720 8FA90028 */  lw    $t1, 0x28($sp)
/* 106254 7F0D1724 8FAA0034 */  lw    $t2, 0x34($sp)
/* 106258 7F0D1728 13280003 */  beq   $t9, $t0, .L7F0D1738
/* 10625C 7F0D172C 00000000 */   nop   
/* 106260 7F0D1730 10000008 */  b     .L7F0D1754
/* 106264 7F0D1734 00001025 */   move  $v0, $zero
.L7F0D1738:
/* 106268 7F0D1738 112A0003 */  beq   $t1, $t2, .L7F0D1748
/* 10626C 7F0D173C 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106270 7F0D1740 10000004 */  b     .L7F0D1754
/* 106274 7F0D1744 00001025 */   move  $v0, $zero
.L7F0D1748:
/* 106278 7F0D1748 8FAC0038 */  lw    $t4, 0x38($sp)
/* 10627C 7F0D174C 24020001 */  li    $v0, 1
/* 106280 7F0D1750 AD8B0000 */  sw    $t3, ($t4)
.L7F0D1754:
/* 106284 7F0D1754 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106288 7F0D1758 27BD0030 */  addiu $sp, $sp, 0x30
/* 10628C 7F0D175C 03E00008 */  jr    $ra
/* 106290 7F0D1760 00000000 */   nop   
)
#endif






u32 response_indyrescmd_1_4_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istype4_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_6_2(u8 *response1,u8 *response2)
{
    post_indyrescmd_istype1_correctsize(0x1c,0x1c);
    post_indyrescmd_istype6_correctvalue(0x14,0x14,response1,response2);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_8_2(u8 *response1,u8 *response2,u32 childsize,u8 *child)
{
    post_indyrescmd_istype1_correctsize(0,0x20);
    post_indyrescmd_istype8_correctvalue(0x14,0x14,response1,response2,childsize,child);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_A_2(u8 *param_1)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeA_correctvalue(0x14,0x14,param_1);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_10_2(u32 *param_1,u32 *param_2,u32 *param_3)
{
    post_indyrescmd_istype1_correctsize(0x20,0x20);
    post_indyrescmd_istype10_correctvalue(0x14,0x14,param_1,param_2,param_3);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_E_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeE_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


u32 response_indyrescmd_1_C_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeC_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}




#ifdef NONMATCHING
u32 response_indyrescmd_curr_matches_expected(int readsize,int writesize)
{
    u32 ret;
    struct indy_resource_entry cmd;
    
    post_indyrescmd_read_command(&cmd,0x14);
    if (cmd.resourceID == 0x9abf1623) {
        if ((readsize == 0) || (cmd.readsize == readsize)) {
            if (writesize == 0) {
                ret = 1;
            }
            else {
                if (cmd.writesize == writesize) {
                    ret = 1;
                }
                else {
                    ret = 0;
                }
            }
        }
        else {
            ret = 0;
        }
    }
    else {
        ret = 0;
    }
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel response_indyrescmd_curr_matches_expected
/* 1064C8 7F0D1998 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1064CC 7F0D199C AFBF0014 */  sw    $ra, 0x14($sp)
/* 1064D0 7F0D19A0 AFA40030 */  sw    $a0, 0x30($sp)
/* 1064D4 7F0D19A4 AFA50034 */  sw    $a1, 0x34($sp)
/* 1064D8 7F0D19A8 24050014 */  li    $a1, 20
/* 1064DC 7F0D19AC 0FC343D3 */  jal   post_indyrescmd_read_command
/* 1064E0 7F0D19B0 27A4001C */   addiu $a0, $sp, 0x1c
/* 1064E4 7F0D19B4 8FAE001C */  lw    $t6, 0x1c($sp)
/* 1064E8 7F0D19B8 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 1064EC 7F0D19BC 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 1064F0 7F0D19C0 8FA20030 */  lw    $v0, 0x30($sp)
/* 1064F4 7F0D19C4 11C10003 */  beq   $t6, $at, .L7F0D19D4
/* 1064F8 7F0D19C8 8FA30034 */   lw    $v1, 0x34($sp)
/* 1064FC 7F0D19CC 1000000E */  b     .L7F0D1A08
/* 106500 7F0D19D0 00001025 */   move  $v0, $zero
.L7F0D19D4:
/* 106504 7F0D19D4 10400005 */  beqz  $v0, .L7F0D19EC
/* 106508 7F0D19D8 8FAF0028 */   lw    $t7, 0x28($sp)
/* 10650C 7F0D19DC 11E20003 */  beq   $t7, $v0, .L7F0D19EC
/* 106510 7F0D19E0 00000000 */   nop   
/* 106514 7F0D19E4 10000008 */  b     .L7F0D1A08
/* 106518 7F0D19E8 00001025 */   move  $v0, $zero
.L7F0D19EC:
/* 10651C 7F0D19EC 10600005 */  beqz  $v1, .L7F0D1A04
/* 106520 7F0D19F0 8FB8002C */   lw    $t8, 0x2c($sp)
/* 106524 7F0D19F4 53030004 */  beql  $t8, $v1, .L7F0D1A08
/* 106528 7F0D19F8 24020001 */   li    $v0, 1
/* 10652C 7F0D19FC 10000002 */  b     .L7F0D1A08
/* 106530 7F0D1A00 00001025 */   move  $v0, $zero
.L7F0D1A04:
/* 106534 7F0D1A04 24020001 */  li    $v0, 1
.L7F0D1A08:
/* 106538 7F0D1A08 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10653C 7F0D1A0C 27BD0030 */  addiu $sp, $sp, 0x30
/* 106540 7F0D1A10 03E00008 */  jr    $ra
/* 106544 7F0D1A14 00000000 */   nop   
)
#endif



