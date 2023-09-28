
#include <ultra64.h>
#include "debugmenu_handler.h"
#include "lvl.h"
#include "initcheattext.h"
#include "front.h"
#include "ramromreplay.h"
#include <ramrom.h>
#include <macro.h>
#include "file.h"
#include "file2.h"
#include <random.h>
#include "joy.h"
//D:800483F0

struct ramrom_struct
{
    ramromfilestructure *fdata;
    s32 locked;
};

struct ramrom_blockbuf
{
    s8 stick_x;
    s8 stick_y;
    u8 button_low;
    u8 button_high;
};
struct ramrom_seed
{
    u8 speedframes;
    u8 count;
    u8 randseed;
    u8 check;
};

//move me to better home
extern u32* ramrom_Dam_1;
extern u32* ramrom_Dam_2;
extern u32* ramrom_Facility_1;
extern u32* ramrom_Facility_2;
extern u32* ramrom_Facility_3;
extern u32* ramrom_Runway_1;
extern u32* ramrom_Runway_2;
extern u32* ramrom_BunkerI_1;
extern u32* ramrom_BunkerI_2;
extern u32* ramrom_Silo_1;
extern u32* ramrom_Silo_2;
extern u32* ramrom_Frigate_1;
extern u32* ramrom_Frigate_2;
extern u32* ramrom_Train;

extern u64 g_randomSeed;
extern u64 g_chrObjRandomSeed;

struct ramrom_struct ramrom_table[] = {
    {&ramrom_Dam_1, 0},
    {&ramrom_Dam_2, 0},
    {&ramrom_Facility_1, 0},
    {&ramrom_Facility_2, 0},
    {&ramrom_Facility_3, 0},
    {&ramrom_Runway_1, 0},
    {&ramrom_Runway_2, 0},
    {&ramrom_BunkerI_1, 0},
    {&ramrom_BunkerI_2, 0},
    {&ramrom_Silo_1, 0},
    {&ramrom_Silo_2, 0},
    {&ramrom_Frigate_1, 0},
    {&ramrom_Frigate_2, 0},
    {&ramrom_Train, 0},
    {0,0}
};

//D:80048468
ramromfilestructure* ptr_active_demofile = 0;
//D:8004846C
struct ramrom_seed * ramrom_blkbuf_2 = NULL;
//D:80048470
struct ramrom_blockbuf * ramrom_blkbuf_3 = NULL;
//D:80048474
s32 is_ramrom_flag = 0;
//D:80048478
s32 ramrom_demo_related_3 = 0;
//D:8004847C
s32 g_ramromPlayBackFlag = 0;
//D:80048480
s32 recording_ramrom_flag = 0;
//D:80048484
s32 ramrom_demo_related_6 = 0;
//D:80048488
s32 g_ramromRecordFlag = 0;
//D:8004848C
//                     .align 4





void ensureCameraModeA(void);
s32 ramrom_replay_handler(struct contsample *arg0, s32 arg1);
void record_player_input_as_packet(struct contsample *arg0, s32 arg1, s32 arg2);
void copy_current_ingame_registers_before_ramrom_playback(ramromfilestructure *state);
void copy_recorded_ramrom_registers_to_proper_place_ingame(ramromfilestructure *state);


void clear_ramrom_block_buffer_heading_ptrs(void) {
    ptr_active_demofile = 0;
    ramrom_blkbuf_2 = 0;
    ramrom_blkbuf_3 = 0;
}


s32 get_is_ramrom_flag(void) {
    return is_ramrom_flag;
}


s32 get_recording_ramrom_flag(void) {
    return recording_ramrom_flag;
}


s32 interface_menu0B_runstage(void) {
    return g_ramromPlayBackFlag;
}

// Address 0x7F0BFCB0 NTSC.
void finalize_ramrom_on_hw(void)
{
    u8 buffer[0x28];
    u8 *p;
    void *a1;

    p = ALIGN16_a((s32)buffer);
    p[0] = 0;
    p[1] = 0;

    romWrite((void *) p, (void *) address_demo_loaded, 0x10U);
    
    address_demo_loaded += 4;

    a1 = INDY_RAMROM_DEMO_POINTER;

    ptr_active_demofile = romCopyAligned(ramrom_data_target, a1, 0xf0);
    ptr_active_demofile->totaltime_ms = g_GlobalTimer - g_ClockTimer;
    ptr_active_demofile->filesize = (s32)address_demo_loaded - (s32)a1;
    romWrite(ptr_active_demofile, a1, 0xf0);
}


// Address 0x7F0BFD60 NTSC.
void save_ramrom_to_devtool(void)
{
    int i;
    char indyFileName [256];
    u32 size;
    
    for (i = 1; ; i++)
    {
        sprintf(indyFileName, "replay/demo.%d", i);
        
        if (!indycommHostCheckFileExists(indyFileName, &size))
        {
            break;
        }
    }
    
    sprintf(indyFileName, "replay/demo.%d", i);
    indycommHostSaveFile(indyFileName, INDY_RAMROM_DEMO_POINTER, ptr_active_demofile->filesize);
}





void load_ramrom_from_devtool(void)
{

    static const char strDemoFileName[] = "replay/demo.load";
    s32 size;

    if (indycommHostCheckFileExists(&strDemoFileName, &size) != 0)
    {
        indycommHostRamRomLoad(&strDemoFileName, (u8 *)INDY_RAMROM_DEMO_ADDRESS, size);
        ptr_active_demofile = romCopyAligned(&ramrom_data_target, (u8 *)INDY_RAMROM_DEMO_ADDRESS, sizeof(struct ramromfilestructure));
    }
}






#ifdef NONMATCHING
// Address 0x7F0BFE5C NTSC
//
// https://decomp.me/scratch/RNdWO 93%
void record_player_input_as_packet(struct contsample *arg0, s32 arg1, s32 arg2)
{
    s32 temp_t5;
    s32 temp_t1;
    s32 var_a0;
    s32 var_a2;
    u8 var_a3;
    s32 var_t2;
    struct ramrom_blockbuf *temp_v0;
    s32 temp_s0;
    u8 t1;
    s32 others0;

    temp_t5 = ALIGN16_a((s32)&ramrom_data_target[0x1f8]);
    temp_t1 = ptr_active_demofile->size_cmds;

    var_t2 = 0;
    var_a3 = 0;
    
    ramrom_blkbuf_2 = (struct ramrom_seed *)temp_t5;
    ramrom_blkbuf_3 = (struct ramrom_blockbuf *)(ramrom_blkbuf_2 + 1);

    // loop structure based on: void joyConsumeSamples(struct contdata *contdata)
    if (arg1 != arg2)
    {
        var_a2 = (s32) (arg1 + 1) % CONTSAMPLE_LEN;
        while (1)
        {
            for (var_a0 = 0; var_a0 < temp_t1; var_a0++)
            {
                temp_v0 = ramrom_blkbuf_3 + (var_t2 * temp_t1) + var_a0;

                temp_v0->stick_x = arg0->pads[var_a2*4 + var_a0].stick_x;
                temp_v0->stick_y = arg0->pads[var_a2*4 + var_a0].stick_y;
                temp_v0->button_low = arg0->pads[var_a2*4 + var_a0].button;
                temp_v0->button_high = arg0->pads[var_a2*4 + var_a0].button >> 8;
    
                var_a3 += (u8) (
                    (u8)temp_v0->stick_x
                    + (u8)temp_v0->stick_y
                    + temp_v0->button_low
                    + temp_v0->button_high);
            }
    
            var_t2++;

            if (var_a2 == arg2)
            {
                break;
            }

            var_a2 = (s32) (var_a2 + 1) % CONTSAMPLE_LEN;
        }
    }
        
    ramrom_blkbuf_2->count = var_t2;
    ramrom_blkbuf_2->speedframes = speedgraphframes;
    ramrom_blkbuf_2->randseed = g_randomSeed;
    
    var_a3 += (u8) ((u8)ramrom_blkbuf_2->speedframes + (u8)ramrom_blkbuf_2->count + ramrom_blkbuf_2->randseed);
    ramrom_blkbuf_2->check = var_a3;

    temp_s0 = (temp_t1 * 4 * var_t2) + sizeof(s32);

    romWrite((void *) ramrom_blkbuf_2, address_demo_loaded, ALIGN16_a(temp_s0));

    address_demo_loaded += align_addr_even(temp_s0 + 1);
}
#else
GLOBAL_ASM(
.text
glabel record_player_input_as_packet
/* 0F498C 7F0BFE5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4990 7F0BFE60 3C0E8005 */  lui   $t6, %hi(ptr_active_demofile)
/* 0F4994 7F0BFE64 3C0F8009 */  lui   $t7, %hi(ramrom_data_target + 0x1F8)
/* 0F4998 7F0BFE68 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F499C 7F0BFE6C 25EFC468 */  addiu $t7, %lo(ramrom_data_target + 0x1F8) # addiu $t7, $t7, -0x3b98
/* 0F49A0 7F0BFE70 25F8000F */  addiu $t8, $t7, 0xf
/* 0F49A4 7F0BFE74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F49A8 7F0BFE78 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F49AC 7F0BFE7C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F49B0 7F0BFE80 3719000F */  ori   $t9, $t8, 0xf
/* 0F49B4 7F0BFE84 3C088005 */  lui   $t0, %hi(ramrom_blkbuf_3)
/* 0F49B8 7F0BFE88 3C0C8005 */  lui   $t4, %hi(ramrom_blkbuf_2)
/* 0F49BC 7F0BFE8C 3B2D000F */  xori  $t5, $t9, 0xf
/* 0F49C0 7F0BFE90 8DC90018 */  lw    $t1, 0x18($t6)
/* 0F49C4 7F0BFE94 258C846C */  addiu $t4, %lo(ramrom_blkbuf_2) # addiu $t4, $t4, -0x7b94
/* 0F49C8 7F0BFE98 25088470 */  addiu $t0, %lo(ramrom_blkbuf_3) # addiu $t0, $t0, -0x7b90
/* 0F49CC 7F0BFE9C 25AE0004 */  addiu $t6, $t5, 4
/* 0F49D0 7F0BFEA0 00C08025 */  move  $s0, $a2
/* 0F49D4 7F0BFEA4 00808825 */  move  $s1, $a0
/* 0F49D8 7F0BFEA8 00005025 */  move  $t2, $zero
/* 0F49DC 7F0BFEAC 00003825 */  move  $a3, $zero
/* 0F49E0 7F0BFEB0 AD8D0000 */  sw    $t5, ($t4)
/* 0F49E4 7F0BFEB4 AD0E0000 */  sw    $t6, ($t0)
/* 0F49E8 7F0BFEB8 10A60048 */  beq   $a1, $a2, .L7F0BFFDC
/* 0F49EC 7F0BFEBC 01A01025 */   move  $v0, $t5
/* 0F49F0 7F0BFEC0 240B0014 */  li    $t3, 20
/* 0F49F4 7F0BFEC4 24AF0001 */  addiu $t7, $a1, 1
/* 0F49F8 7F0BFEC8 01EB001A */  div   $zero, $t7, $t3
/* 0F49FC 7F0BFECC 00003010 */  mfhi  $a2
/* 0F4A00 7F0BFED0 00002025 */  move  $a0, $zero
/* 0F4A04 7F0BFED4 15600002 */  bnez  $t3, .L7F0BFEE0
/* 0F4A08 7F0BFED8 00000000 */   nop
/* 0F4A0C 7F0BFEDC 0007000D */  break 7
.L7F0BFEE0:
/* 0F4A10 7F0BFEE0 2401FFFF */  li    $at, -1
/* 0F4A14 7F0BFEE4 15610004 */  bne   $t3, $at, .L7F0BFEF8
/* 0F4A18 7F0BFEE8 3C018000 */   lui   $at, 0x8000
/* 0F4A1C 7F0BFEEC 15E10002 */  bne   $t7, $at, .L7F0BFEF8
/* 0F4A20 7F0BFEF0 00000000 */   nop
/* 0F4A24 7F0BFEF4 0006000D */  break 6
.L7F0BFEF8:
/* 0F4A28 7F0BFEF8 19200025 */  blez  $t1, .L7F0BFF90
/* 0F4A2C 7F0BFEFC 00000000 */   nop
/* 0F4A30 7F0BFF00 01490019 */  multu $t2, $t1
/* 0F4A34 7F0BFF04 0006C880 */  sll   $t9, $a2, 2
/* 0F4A38 7F0BFF08 00196880 */  sll   $t5, $t9, 2
/* 0F4A3C 7F0BFF0C 01B96823 */  subu  $t5, $t5, $t9
/* 0F4A40 7F0BFF10 000D6840 */  sll   $t5, $t5, 1
/* 0F4A44 7F0BFF14 022D1821 */  addu  $v1, $s1, $t5
/* 0F4A48 7F0BFF18 00002812 */  mflo  $a1
/* 0F4A4C 7F0BFF1C 0005C080 */  sll   $t8, $a1, 2
/* 0F4A50 7F0BFF20 03002825 */  move  $a1, $t8
.L7F0BFF24:
/* 0F4A54 7F0BFF24 8D0E0000 */  lw    $t6, ($t0)
/* 0F4A58 7F0BFF28 80790002 */  lb    $t9, 2($v1)
/* 0F4A5C 7F0BFF2C 0004C080 */  sll   $t8, $a0, 2
/* 0F4A60 7F0BFF30 00AE7821 */  addu  $t7, $a1, $t6
/* 0F4A64 7F0BFF34 01F81021 */  addu  $v0, $t7, $t8
/* 0F4A68 7F0BFF38 A0590000 */  sb    $t9, ($v0)
/* 0F4A6C 7F0BFF3C 806D0003 */  lb    $t5, 3($v1)
/* 0F4A70 7F0BFF40 24840001 */  addiu $a0, $a0, 1
/* 0F4A74 7F0BFF44 24630006 */  addiu $v1, $v1, 6
/* 0F4A78 7F0BFF48 A04D0001 */  sb    $t5, 1($v0)
/* 0F4A7C 7F0BFF4C 946FFFFA */  lhu   $t7, -6($v1)
/* 0F4A80 7F0BFF50 904E0001 */  lbu   $t6, 1($v0)
/* 0F4A84 7F0BFF54 904D0000 */  lbu   $t5, ($v0)
/* 0F4A88 7F0BFF58 A04F0002 */  sb    $t7, 2($v0)
/* 0F4A8C 7F0BFF5C 9478FFFA */  lhu   $t8, -6($v1)
/* 0F4A90 7F0BFF60 01AE7821 */  addu  $t7, $t5, $t6
/* 0F4A94 7F0BFF64 0018CA03 */  sra   $t9, $t8, 8
/* 0F4A98 7F0BFF68 90580002 */  lbu   $t8, 2($v0)
/* 0F4A9C 7F0BFF6C A0590003 */  sb    $t9, 3($v0)
/* 0F4AA0 7F0BFF70 904D0003 */  lbu   $t5, 3($v0)
/* 0F4AA4 7F0BFF74 01F8C821 */  addu  $t9, $t7, $t8
/* 0F4AA8 7F0BFF78 032D7021 */  addu  $t6, $t9, $t5
/* 0F4AAC 7F0BFF7C 31CF00FF */  andi  $t7, $t6, 0xff
/* 0F4AB0 7F0BFF80 00EF3821 */  addu  $a3, $a3, $t7
/* 0F4AB4 7F0BFF84 30F800FF */  andi  $t8, $a3, 0xff
/* 0F4AB8 7F0BFF88 1489FFE6 */  bne   $a0, $t1, .L7F0BFF24
/* 0F4ABC 7F0BFF8C 03003825 */   move  $a3, $t8
.L7F0BFF90:
/* 0F4AC0 7F0BFF90 14D00003 */  bne   $a2, $s0, .L7F0BFFA0
/* 0F4AC4 7F0BFF94 254A0001 */   addiu $t2, $t2, 1
/* 0F4AC8 7F0BFF98 10000010 */  b     .L7F0BFFDC
/* 0F4ACC 7F0BFF9C 8D820000 */   lw    $v0, ($t4)
.L7F0BFFA0:
/* 0F4AD0 7F0BFFA0 24D90001 */  addiu $t9, $a2, 1
/* 0F4AD4 7F0BFFA4 032B001A */  div   $zero, $t9, $t3
/* 0F4AD8 7F0BFFA8 00003010 */  mfhi  $a2
/* 0F4ADC 7F0BFFAC 00002025 */  move  $a0, $zero
/* 0F4AE0 7F0BFFB0 15600002 */  bnez  $t3, .L7F0BFFBC
/* 0F4AE4 7F0BFFB4 00000000 */   nop
/* 0F4AE8 7F0BFFB8 0007000D */  break 7
.L7F0BFFBC:
/* 0F4AEC 7F0BFFBC 2401FFFF */  li    $at, -1
/* 0F4AF0 7F0BFFC0 15610004 */  bne   $t3, $at, .L7F0BFFD4
/* 0F4AF4 7F0BFFC4 3C018000 */   lui   $at, 0x8000
/* 0F4AF8 7F0BFFC8 17210002 */  bne   $t9, $at, .L7F0BFFD4
/* 0F4AFC 7F0BFFCC 00000000 */   nop
/* 0F4B00 7F0BFFD0 0006000D */  break 6
.L7F0BFFD4:
/* 0F4B04 7F0BFFD4 1000FFC8 */  b     .L7F0BFEF8
/* 0F4B08 7F0BFFD8 00000000 */   nop
.L7F0BFFDC:
/* 0F4B0C 7F0BFFDC A04A0001 */  sb    $t2, 1($v0)
/* 0F4B10 7F0BFFE0 3C0D8005 */  lui   $t5, %hi(speedgraphframes)
/* 0F4B14 7F0BFFE4 8DAD8498 */  lw    $t5, %lo(speedgraphframes)($t5)
/* 0F4B18 7F0BFFE8 8D8E0000 */  lw    $t6, ($t4)
/* 0F4B1C 7F0BFFEC 3C198002 */  lui   $t9, %hi(g_randomSeed + 0x4)
/* 0F4B20 7F0BFFF0 3C118009 */  lui   $s1, %hi(address_demo_loaded)
/* 0F4B24 7F0BFFF4 A1CD0000 */  sb    $t5, ($t6)
/* 0F4B28 7F0BFFF8 8D8D0000 */  lw    $t5, ($t4)
/* 0F4B2C 7F0BFFFC 8F394464 */  lw    $t9, %lo(g_randomSeed + 0x4)($t9)
/* 0F4B30 7F0C0000 2631C5F4 */  addiu $s1, %lo(address_demo_loaded) # addiu $s1, $s1, -0x3a0c
/* 0F4B34 7F0C0004 A1B90002 */  sb    $t9, 2($t5)
/* 0F4B38 7F0C0008 8D820000 */  lw    $v0, ($t4)
/* 0F4B3C 7F0C000C 904E0000 */  lbu   $t6, ($v0)
/* 0F4B40 7F0C0010 90580001 */  lbu   $t8, 1($v0)
/* 0F4B44 7F0C0014 904F0002 */  lbu   $t7, 2($v0)
/* 0F4B48 7F0C0018 01D8C821 */  addu  $t9, $t6, $t8
/* 0F4B4C 7F0C001C 032F7021 */  addu  $t6, $t9, $t7
/* 0F4B50 7F0C0020 0009C880 */  sll   $t9, $t1, 2
/* 0F4B54 7F0C0024 032A0019 */  multu $t9, $t2
/* 0F4B58 7F0C0028 00EEC021 */  addu  $t8, $a3, $t6
/* 0F4B5C 7F0C002C A0580003 */  sb    $t8, 3($v0)
/* 0F4B60 7F0C0030 8E250000 */  lw    $a1, ($s1)
/* 0F4B64 7F0C0034 8D840000 */  lw    $a0, ($t4)
/* 0F4B68 7F0C0038 00008012 */  mflo  $s0
/* 0F4B6C 7F0C003C 26100004 */  addiu $s0, $s0, 4
/* 0F4B70 7F0C0040 2606000F */  addiu $a2, $s0, 0xf
/* 0F4B74 7F0C0044 34CF000F */  ori   $t7, $a2, 0xf
/* 0F4B78 7F0C0048 0C001742 */  jal   romWrite
/* 0F4B7C 7F0C004C 39E6000F */   xori  $a2, $t7, 0xf
/* 0F4B80 7F0C0050 8E2E0000 */  lw    $t6, ($s1)
/* 0F4B84 7F0C0054 26180001 */  addiu $t8, $s0, 1
/* 0F4B88 7F0C0058 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F4B8C 7F0C005C 37190001 */  ori   $t9, $t8, 1
/* 0F4B90 7F0C0060 3B2F0001 */  xori  $t7, $t9, 1
/* 0F4B94 7F0C0064 3C018009 */  lui   $at, %hi(address_demo_loaded)
/* 0F4B98 7F0C0068 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F4B9C 7F0C006C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F4BA0 7F0C0070 01CF6821 */  addu  $t5, $t6, $t7
/* 0F4BA4 7F0C0074 AC2DC5F4 */  sw    $t5, %lo(address_demo_loaded)($at)
/* 0F4BA8 7F0C0078 03E00008 */  jr    $ra
/* 0F4BAC 7F0C007C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif




// Address 0x7F0C0080 NTSC.
s32 ramrom_replay_handler(struct contsample *arg0, s32 arg1)
{
    s32 padding[2];
    s32 var_a3;
    s32 var_a0;
    struct ramrom_blockbuf *temp_v0;
    u8 var_t0;
    s32 temp_a2;
    s32 temp_t2;

    var_t0 = 0;
    temp_a2 = (s32) ptr_active_demofile->size_cmds;
    temp_t2 = ramrom_blkbuf_2->count;

    for (var_a3 = 0; var_a3 < temp_t2; var_a3++)
    {
        arg1 = (s32) (arg1 + 1) % CONTSAMPLE_LEN;

        for (var_a0 = 0; var_a0 < MAXCONTROLLERS; var_a0++)
        {
            if (var_a0 < temp_a2)
            {
                temp_v0 = ramrom_blkbuf_3 + (var_a3 * temp_a2) + var_a0;

                arg0->pads[arg1 * 4 + var_a0].stick_x = temp_v0->stick_x;
                arg0->pads[arg1 * 4 + var_a0].stick_y = temp_v0->stick_y;
                arg0->pads[arg1 * 4 + var_a0].button = (temp_v0->button_high << 8) | temp_v0->button_low;

                var_t0 += (u8)((u8)temp_v0->stick_x + (u8)temp_v0->stick_y + temp_v0->button_low + temp_v0->button_high);
            }
            else
            {
                arg0->pads[arg1 * 4 + var_a0].stick_x = 0;
                arg0->pads[arg1 * 4 + var_a0].stick_y = 0;
                arg0->pads[arg1 * 4 + var_a0].button = 0;
            }
        }
    }

    if (ramrom_blkbuf_2->randseed != (u8)g_randomSeed)
    {
        ensureCameraModeA();
    }

    var_t0 += (u8)((u8)ramrom_blkbuf_2->speedframes + (u8)ramrom_blkbuf_2->count + ramrom_blkbuf_2->randseed);
    if (ramrom_blkbuf_2->check != var_t0)
    {
        ensureCameraModeA();
    }
    
    joySetContDataIndex(0);
    
    if (joyGetButtonsPressedThisFrame(0, 0xFFFFU) != 0)
    {
        ensureCameraModeA();
        prev_keypresses = 1;
    }
    
    joySetContDataIndex(1);

    return arg1;
}



// Address 0x7F0C0268 NTSC.
void iterate_ramrom_entries_handle_camera_out(void)
{
    s32 temp_v1;
    s32 var_a3;
    
    ramrom_blkbuf_2 = romCopyAligned(ramrom_data_target + 0x1F8, address_demo_loaded, sizeof(struct ramrom_seed));

    var_a3 = ramrom_blkbuf_2->count;
    if (var_a3 > 0)
    {
        ramrom_blkbuf_3 = romCopyAligned(
            ramrom_data_target + 0x21E,
            address_demo_loaded + 4,
            ptr_active_demofile->size_cmds * sizeof(struct ramrom_blockbuf) * ramrom_blkbuf_2->count);
    }

    var_a3 = ramrom_blkbuf_2->count;
    if (var_a3 == 0 && ramrom_blkbuf_2->speedframes == 0)
    {
        ensureCameraModeA();
    }
    else
    {
        // 5 is ??
        address_demo_loaded += align_addr_even((ptr_active_demofile->size_cmds * sizeof(struct ramrom_blockbuf) * ramrom_blkbuf_2->count) + 5);
    }

    sub_GAME_7F0C0AA0(ramrom_blkbuf_2->speedframes);

    // BUG? Does this need to be adjusted for PAL?
    temp_v1 = ptr_active_demofile->totaltime_ms - 0x3C;
    if(0);
    if ((g_GlobalTimer >= temp_v1) && ((g_GlobalTimer - g_ClockTimer) < temp_v1))
    {
        ensureCameraModeA();
    }
}

void copy_current_ingame_registers_before_ramrom_playback(ramromfilestructure *state)
{
    state->randomseed = g_randomSeed;
    state->randomizer = g_chrObjRandomSeed;
    state->mode = gamemode;
    state->numplayers = selected_num_players;
    state->scenario = scenario;
    state->mpstage_sel = MP_stage_selected;
    state->gamelength = game_length;
    state->mp_weapon_set = getMPWeaponSet();
    state->mp_char[0] = player_char[0];
    state->mp_char[1] = player_char[1];
    state->mp_char[2] = player_char[2];
    state->mp_char[3] = player_char[3];
    state->mp_handi[0] = player_handicap[0];
    state->mp_handi[1] = player_handicap[1];
    state->mp_handi[2] = player_handicap[2];
    state->mp_handi[3] = player_handicap[3];
    state->mp_contstyle[0] = controlstyle_player[0];
    state->mp_contstyle[1] = controlstyle_player[1];
    state->mp_contstyle[2] = controlstyle_player[2];
    state->mp_contstyle[3] = controlstyle_player[3];
    state->aim_option = aim_sight_adjustment;
    state->mp_flags[0] = get_players_team_or_scenario_item_flag(0);
    state->mp_flags[1] = get_players_team_or_scenario_item_flag(1);
    state->mp_flags[2] = get_players_team_or_scenario_item_flag(2);
    state->mp_flags[3] = get_players_team_or_scenario_item_flag(3);
}

void copy_recorded_ramrom_registers_to_proper_place_ingame(ramromfilestructure *state)
{
    g_randomSeed = state->randomseed;
    g_chrObjRandomSeed = state->randomizer;
    gamemode = state->mode;
    selected_num_players = state->numplayers;
    scenario = state->scenario;
    MP_stage_selected = state->mpstage_sel;
    game_length = state->gamelength;
    setMPWeaponSet(state->mp_weapon_set);
    player_char[0] = state->mp_char[0];
    player_char[1] = state->mp_char[1];
    player_char[2] = state->mp_char[2];
    player_char[3] = state->mp_char[3];
    player_handicap[0] = state->mp_handi[0];
    player_handicap[1] = state->mp_handi[1];
    player_handicap[2] = state->mp_handi[2];
    player_handicap[3] = state->mp_handi[3];
    controlstyle_player[0] = state->mp_contstyle[0];
    controlstyle_player[1] = state->mp_contstyle[1];
    controlstyle_player[2] = state->mp_contstyle[2];
    controlstyle_player[3] = state->mp_contstyle[3];
    aim_sight_adjustment = state->aim_option;
    set_players_team_or_scenario_item_flag(0, state->mp_flags[0]);
    set_players_team_or_scenario_item_flag(1, state->mp_flags[1]);
    set_players_team_or_scenario_item_flag(2, state->mp_flags[2]);
    set_players_team_or_scenario_item_flag(3, state->mp_flags[3]);
}

// Address 0x7F0C0640 NTSC
void test_if_recording_demos_this_stage_load(enum LEVELID arg0, enum DIFFICULTY arg1)
{
    if (g_ramromRecordFlag != 0)
    {
        ptr_active_demofile = (ramromfilestructure *) ALIGN16_a((s32)ramrom_data_target);
        dword_CODE_bss_8008C5F8 = 0;
        ptr_active_demofile->stagenum = arg0;
        ptr_active_demofile->difficulty = arg1;
        ptr_active_demofile->size_cmds = joyGetControllerCount();
        ptr_active_demofile->slotnum = record_slot_num;
        sub_GAME_7F01D61C(&ptr_active_demofile->savefile);
        copy_current_ingame_registers_before_ramrom_playback(ptr_active_demofile);
        recording_ramrom_flag = 1;
        ramrom_demo_related_6 = 1;
        joySetRecordFunc(record_player_input_as_packet);
        address_demo_loaded = INDY_RAMROM_DEMO_POINTER;
        romWrite(ptr_active_demofile, address_demo_loaded, 0xF0U);
        address_demo_loaded += sizeof(struct ramromfilestructure);
        g_ramromRecordFlag = 0;
        
        return;
    }
    
    if (g_ramromPlayBackFlag != 0)
    {
        dword_CODE_bss_8008C5F8 = 0;
        set_selected_difficulty(ptr_active_demofile->difficulty);
        set_solo_and_ptr_briefing(ptr_active_demofile->stagenum);
        set_selected_foldernum_and_copy_demo_eeprom(&ptr_active_demofile->savefile);
        copy_current_ingame_registers_before_ramrom_playback((ramromfilestructure *) (ramrom_data_target + 0x110));
        copy_recorded_ramrom_registers_to_proper_place_ingame(ptr_active_demofile);
        is_ramrom_flag = 1;
        ramrom_demo_related_3 = 1;
        joySetPlaybackFunc(ramrom_replay_handler, ptr_active_demofile->size_cmds);
        joySetContDataIndex(1);
        g_ramromPlayBackFlag = 0;
    }
}





void setRamRomRecordSlot(s32 arg0)
{
    g_ramromRecordFlag = 1;
    record_slot_num = arg0;
}

void stop_recording_ramrom(void)
{
    if (ramrom_demo_related_6 != 0)
    {
        finalize_ramrom_on_hw();
        joySetRecordFunc(0);
        ramrom_demo_related_6 = 0;
        recording_ramrom_flag = 0;
    }
}

void replay_recorded_ramrom_at_address(ramromfilestructure *demofile)
{
    address_demo_loaded = demofile;
    ptr_active_demofile = romCopyAligned(&ramrom_data_target, address_demo_loaded, sizeof(struct ramromfilestructure));
    address_demo_loaded += sizeof(ramromfilestructure);
    g_ramromPlayBackFlag = 1;
    set_solo_and_ptr_briefing(ptr_active_demofile->stagenum);
    set_selected_difficulty(ptr_active_demofile->difficulty);
    frontChangeMenu(MENU_RUN_STAGE,1);
}

void replay_recorded_ramrom_from_indy(void)
{
    replay_recorded_ramrom_at_address(INDY_RAMROM_DEMO_ADDRESS);
}

void ensureCameraModeA(void)
{
    if (get_camera_mode() != CAMERAMODE_UNK10)
    {
        set_camera_mode(CAMERAMODE_UNK10);
    }
}

void stop_demo_playback(void)
{
    if (ramrom_demo_related_6 != 0)
    {
        stop_recording_ramrom();
        return;
    }
    if (ramrom_demo_related_3 != 0)
    {
        copy_recorded_ramrom_registers_to_proper_place_ingame(ramrom_data_target + 0x110);
        joySetPlaybackFunc(0, -1);
        joySetContDataIndex(0);
        ramrom_demo_related_3 = 0;
        is_ramrom_flag = 0;
    }
}



// Address 0x7F0C0970 NTSC.
void select_ramrom_to_play(void)
{
    s32 i;
    s32 temp_v0;

    temp_v0 = fileGetHighestStageUnlockedAnyFolder();

    for (i = 0; ramrom_table[i].fdata != NULL && temp_v0 >= ramrom_table[i].locked; i++)
    {}

    replay_recorded_ramrom_at_address(ramrom_table[randomGetNext() % i].fdata);
}





u32 check_ramrom_flags(void)
{
    if ((get_is_ramrom_flag() != 0) || (get_recording_ramrom_flag() != 0))
    {
        return ptr_active_demofile->slotnum;

    }
    return 0;
}



