#include "ultra64.h"
#include "game/fog.h"

// bss
//CODE.bss:800825C0
s32 sky_enabled;
//CODE.bss:800825C4
u32 *ptr_nearfog_enviroment_values;
//CODE.bss:800825C8
s32 buffer_far_pervasiveness;
//CODE.bss:800825CC
s32 far_fog;
//CODE.bss:800825D0
s32 D_800825D0;
//CODE.bss:800825D4
s32 D_800825D4;
//CODE.bss:800825D8
s32 flt_CODE_bss_800825D8;
//CODE.bss:800825DC
s32 flt_CODE_bss_800825DC;
//CODE.bss:800825E0
s32 buffer_far_ambiant;
//CODE.bss:800825E4
s32 bg_dif_light;
//CODE.bss:800825E8
s32 env_table_hit;
//CODE.bss:800825EC
s32 env_table_match_start;
//CODE.bss:800825F0
s32 env_table_match_end;
//CODE.bss:800825F4
s32 D_800825F4;
//CODE.bss:800825F8
u32 dword_CODE_bss_800825F8;

f32 flt_CODE_bss_800825FC;
f32 flt_CODE_bss_80082600;
u32 DAT_80082604;
u32 DAT_80082608;
u32 DAT_8008260c;
u32 DAT_80082610;
u32 DAT_80082614;
u32 dword_CODE_bss_80082618;
u32 dword_CODE_bss_8008261C;
u8 off_CODE_bss_80082620;
u8 byte_CODE_bss_80082621;
u8 byte_CODE_bss_80082622;
u8 byte_CODE_bss_80082623;

u8 byte_CODE_bss_80082624;
u8 byte_CODE_bss_80082625;
u8 byte_CODE_bss_80082626;
u8 byte_CODE_bss_80082627;
u8 byte_CODE_bss_80082628;
u8 byte_CODE_bss_80082629;
u8 byte_CODE_bss_8008262a;
u8 byte_CODE_bss_8008262b;
u8 byte_CODE_bss_8008262c;
u8 byte_CODE_bss_8008262d;
u8 byte_CODE_bss_8008262e;
u8 byte_CODE_bss_8008262f;
u8 byte_CODE_bss_80082630;
u8 byte_CODE_bss_80082631;
u8 byte_CODE_bss_80082632;
u8 byte_CODE_bss_80082633;
u8 byte_CODE_bss_80082634;
u8 byte_CODE_bss_80082635;
u8 byte_CODE_bss_80082636;
u8 byte_CODE_bss_80082637;
u8 byte_CODE_bss_80082638;
u8 byte_CODE_bss_80082639;
u8 byte_CODE_bss_8008263a;
u8 byte_CODE_bss_8008263b;
u8 byte_CODE_bss_8008263c;
u8 byte_CODE_bss_8008263d;
u8 byte_CODE_bss_8008263e;
u8 byte_CODE_bss_8008263f;
u8 byte_CODE_bss_80082640;
u8 byte_CODE_bss_80082641;
u8 byte_CODE_bss_80082642;
u8 byte_CODE_bss_80082643;
u8 byte_CODE_bss_80082644;
u8 byte_CODE_bss_80082645;
u8 byte_CODE_bss_80082646;
u8 byte_CODE_bss_80082647;
u8 byte_CODE_bss_80082648;
u8 byte_CODE_bss_80082649;
u8 byte_CODE_bss_8008264a;
u8 byte_CODE_bss_8008264b;
u8 byte_CODE_bss_8008264c;
u8 byte_CODE_bss_8008264d;
u8 byte_CODE_bss_8008264e;
u8 byte_CODE_bss_8008264f;
u8 byte_CODE_bss_80082650;
u8 byte_CODE_bss_80082651;
u8 byte_CODE_bss_80082652;
u8 byte_CODE_bss_80082653;
u8 byte_CODE_bss_80082654;
u8 byte_CODE_bss_80082655;
u8 byte_CODE_bss_80082656;
u8 byte_CODE_bss_80082657;
u8 byte_CODE_bss_80082658;
u8 byte_CODE_bss_80082659;
u8 byte_CODE_bss_8008265a;
u8 byte_CODE_bss_8008265b;
u8 byte_CODE_bss_8008265c;
u8 byte_CODE_bss_8008265d;
u8 byte_CODE_bss_8008265e;
u8 byte_CODE_bss_8008265f;



// data
//D:80044DC0
s32 D_80044DC0 = 0;
//D:80044DC4
f32 near_fog_value = 3.4028235e38;
//D:80044DC8
f32 near_fog_times_intensity = 0.0;
//D:80044DCC
s32 ptr_current_data[] = {0x384, 0x3E8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//D:80044E10
struct fog_element fog_tables[] = {
    {0x16, 15.0, 3500.0, 2000.0, 2500.0, 2000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 170.0, 100.0, 40.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 30.0},
    {0x17, 10.0, 10000.0, 2500.0, 5000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x18, 10.0, 3000.0, 2000.0, 3000.0, 500.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x19, 10.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x7D, 20.0, 15000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x1D, 10.0, 7500.0, 5000.0, 6000.0, 1000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x18, 0x20, 1, 5000.0, 0, 0, 225.0, 175.0, 100.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 25.0},
    {0x1E, 10.0, 3000.0, 1600.0, 2000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 7500.0, 0, 0, 70.0, 199.0, 186.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x1F, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x21, 5.0, 15000.0, 3333.0, 4444.0, 600.0, 0.0, 0x3E7, 0x3E3, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x3A5, 30.0, 15000.0, 3333.0, 4444.0, 600.0, 0.0, 0x3E7, 0x3E3, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x22, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3DE, 0x3E8, 0x10, 0x20, 0x10, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x86, 10.0, 1000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3DE, 0x3E8, 0x40, 0x80, 0x40, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x23, 10.0, 15000.0, 6000.0, 8000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x30, 0x40, 1, 5000.0, 0, 0, 25.0, 25.0, 25.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x24, 2.0, 2500.0, 4444.0, 5555.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x60, 0x80, 1, 10000.0, 0, 0, 240.0, 120.0, 30.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 7.0},
    {0x25, 10.0, 2500.0, 1500.0, 2500.0, 1000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x20, 0, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x26, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x28, 1, 10000.0, 0, 0, 160.0, 160.0, 190.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x27, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x29, 10.0, 9500.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x2B, 2.0, 2000.0, 2500.0, 3055.0, 750.0, 0.0, 0x3E7, 0x3BD, 0x3E8, 0x20, 0x10, 0x10, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 20.0},
    {0x3AF, 2.0, 8000.0, 6000.0, 8000.0, 800.0, 0.0, 0x3E7, 0x3DF, 0x3E8, 0x20, 0x10, 0x10, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B, 10.0, 10000.0, 1000.0, 15000.0, 750.0, 0.0, 0x3E7, 0x3E4, 0x41A, 0x10, 0, 0, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xD1, 10.0, 2500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x135, 10.0, 2000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x199, 10.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0xF1, 10.0, 7000.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x155, 10.0, 5500.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B9, 10.0, 4000.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xEE, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x152, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1B6, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0xEF, 10.0, 7500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x153, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B7, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xC8, 10.0, 7500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x12C, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x190, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x28, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xF0, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x154, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B8, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xE7, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x14B, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1AF, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1C, 10.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 72.0, 65.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x80, 30.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 72.0, 65.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x20, 10.0, 20000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x84, 10.0, 10000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3CC, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 10.0, 10.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0}
};

struct fog_element2 fog_tables2[] = {
    {0xFFFFFFFF, 0, 0x10, 0x40, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1A, 0x10, 0x30, 0x60, 1, 3000.0, 0, 0, 230.0, 230.0, 230.0, 1, 0, 0, 0, -150.0, 2, 0, 255.0, 255.0, 150.0, 0.0},
    {0x36, 0x30, 0x40, 0x10, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0}
};

// rodata



#ifdef NONMATCHING
void sub_GAME_7F0BA720(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BA720
/* 0EF250 7F0BA720 AFA40000 */  sw    $a0, ($sp)
/* 0EF254 7F0BA724 03E00008 */  jr    $ra
/* 0EF258 7F0BA728 AFA50004 */   sw    $a1, 4($sp)
)
#endif





s32 get_ptr_currentdata(void){
  return ptr_current_data;
}

f32 get_near_fog_value(void) {
  return near_fog_value;
}

f32 square_near_fog_value(void) {
  return near_fog_value * near_fog_value;
}





#ifdef NONMATCHING
void copy_table1_env_to_current(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_table1_env_to_current
/* 0EF288 7F0BA758 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EF28C 7F0BA75C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EF290 7F0BA760 C48E0008 */  lwc1  $f14, 8($a0)
/* 0EF294 7F0BA764 C48C0004 */  lwc1  $f12, 4($a0)
/* 0EF298 7F0BA768 0C001194 */  jal   set_page_height
/* 0EF29C 7F0BA76C AFA40038 */   sw    $a0, 0x38($sp)
/* 0EF2A0 7F0BA770 0C0011AB */  jal   video_related_27
/* 0EF2A4 7F0BA774 27A40030 */   addiu $a0, $sp, 0x30
/* 0EF2A8 7F0BA778 0FC2D21E */  jal   sub_GAME_7F0B4878
/* 0EF2AC 7F0BA77C 00000000 */   nop   
/* 0EF2B0 7F0BA780 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0EF2B4 7F0BA784 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 0EF2B8 7F0BA788 8FA50038 */  lw    $a1, 0x38($sp)
/* 0EF2BC 7F0BA78C 46002183 */  div.s $f6, $f4, $f0
/* 0EF2C0 7F0BA790 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0EF2C4 7F0BA794 3C048008 */  lui   $a0, %hi(bg_dif_light) # $a0, 0x8008
/* 0EF2C8 7F0BA798 248425E4 */  addiu $a0, %lo(bg_dif_light) # addiu $a0, $a0, 0x25e4
/* 0EF2CC 7F0BA79C 3C068008 */  lui   $a2, %hi(buffer_far_ambiant) # $a2, 0x8008
/* 0EF2D0 7F0BA7A0 24C625E0 */  addiu $a2, %lo(buffer_far_ambiant) # addiu $a2, $a2, 0x25e0
/* 0EF2D4 7F0BA7A4 3C038008 */  lui   $v1, %hi(buffer_far_pervasiveness) # $v1, 0x8008
/* 0EF2D8 7F0BA7A8 246325C8 */  addiu $v1, %lo(buffer_far_pervasiveness) # addiu $v1, $v1, 0x25c8
/* 0EF2DC 7F0BA7AC 3C028004 */  lui   $v0, %hi(ptr_current_data) # $v0, 0x8004
/* 0EF2E0 7F0BA7B0 24424DCC */  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
/* 0EF2E4 7F0BA7B4 46004283 */  div.s $f10, $f8, $f0
/* 0EF2E8 7F0BA7B8 E7A60030 */  swc1  $f6, 0x30($sp)
/* 0EF2EC 7F0BA7BC 44814000 */  mtc1  $at, $f8
/* 0EF2F0 7F0BA7C0 E7AA0034 */  swc1  $f10, 0x34($sp)
/* 0EF2F4 7F0BA7C4 8CAE0020 */  lw    $t6, 0x20($a1)
/* 0EF2F8 7F0BA7C8 448E2000 */  mtc1  $t6, $f4
/* 0EF2FC 7F0BA7CC 00000000 */  nop   
/* 0EF300 7F0BA7D0 468021A0 */  cvt.s.w $f6, $f4
/* 0EF304 7F0BA7D4 46083283 */  div.s $f10, $f6, $f8
/* 0EF308 7F0BA7D8 44814000 */  mtc1  $at, $f8
/* 0EF30C 7F0BA7DC 3C018004 */  lui   $at, %hi(near_fog_value) # $at, 0x8004
/* 0EF310 7F0BA7E0 E48A0000 */  swc1  $f10, ($a0)
/* 0EF314 7F0BA7E4 8CAF0024 */  lw    $t7, 0x24($a1)
/* 0EF318 7F0BA7E8 448F2000 */  mtc1  $t7, $f4
/* 0EF31C 7F0BA7EC 24AF000C */  addiu $t7, $a1, 0xc
/* 0EF320 7F0BA7F0 468021A0 */  cvt.s.w $f6, $f4
/* 0EF324 7F0BA7F4 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 0EF328 7F0BA7F8 46083283 */  div.s $f10, $f6, $f8
/* 0EF32C 7F0BA7FC C7A60030 */  lwc1  $f6, 0x30($sp)
/* 0EF330 7F0BA800 46062381 */  sub.s $f14, $f4, $f6
/* 0EF334 7F0BA804 E4CA0000 */  swc1  $f10, ($a2)
/* 0EF338 7F0BA808 C4D00000 */  lwc1  $f16, ($a2)
/* 0EF33C 7F0BA80C 46107202 */  mul.s $f8, $f14, $f16
/* 0EF340 7F0BA810 46083280 */  add.s $f10, $f6, $f8
/* 0EF344 7F0BA814 E42A4DC4 */  swc1  $f10, %lo(near_fog_value)($at)
/* 0EF348 7F0BA818 C4820000 */  lwc1  $f2, ($a0)
/* 0EF34C 7F0BA81C 3C018004 */  lui   $at, %hi(near_fog_times_intensity) # $at, 0x8004
/* 0EF350 7F0BA820 46027102 */  mul.s $f4, $f14, $f2
/* 0EF354 7F0BA824 46043200 */  add.s $f8, $f6, $f4
/* 0EF358 7F0BA828 E4284DC8 */  swc1  $f8, %lo(near_fog_times_intensity)($at)
/* 0EF35C 7F0BA82C C4AA0004 */  lwc1  $f10, 4($a1)
/* 0EF360 7F0BA830 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0EF364 7F0BA834 46005183 */  div.s $f6, $f10, $f0
/* 0EF368 7F0BA838 46028281 */  sub.s $f10, $f16, $f2
/* 0EF36C 7F0BA83C E4660000 */  swc1  $f6, ($v1)
/* 0EF370 7F0BA840 C4A40008 */  lwc1  $f4, 8($a1)
/* 0EF374 7F0BA844 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 0EF378 7F0BA848 44813000 */  mtc1  $at, $f6
/* 0EF37C 7F0BA84C 46002203 */  div.s $f8, $f4, $f0
/* 0EF380 7F0BA850 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0EF384 7F0BA854 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0EF388 7F0BA858 44815000 */  mtc1  $at, $f10
/* 0EF38C 7F0BA85C 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 0EF390 7F0BA860 C4720000 */  lwc1  $f18, ($v1)
/* 0EF394 7F0BA864 E4680004 */  swc1  $f8, 4($v1)
/* 0EF398 7F0BA868 46043203 */  div.s $f8, $f6, $f4
/* 0EF39C 7F0BA86C C46C0004 */  lwc1  $f12, 4($v1)
/* 0EF3A0 7F0BA870 46025181 */  sub.s $f6, $f10, $f2
/* 0EF3A4 7F0BA874 E7A80020 */  swc1  $f8, 0x20($sp)
/* 0EF3A8 7F0BA878 44814000 */  mtc1  $at, $f8
/* 0EF3AC 7F0BA87C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EF3B0 7F0BA880 46083282 */  mul.s $f10, $f6, $f8
/* 0EF3B4 7F0BA884 46126201 */  sub.s $f8, $f12, $f18
/* 0EF3B8 7F0BA888 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0EF3BC 7F0BA88C 44814000 */  mtc1  $at, $f8
/* 0EF3C0 7F0BA890 46045183 */  div.s $f6, $f10, $f4
/* 0EF3C4 7F0BA894 C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 0EF3C8 7F0BA898 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EF3CC 7F0BA89C 46005107 */  neg.s $f4, $f10
/* 0EF3D0 7F0BA8A0 46089280 */  add.s $f10, $f18, $f8
/* 0EF3D4 7F0BA8A4 C7A80018 */  lwc1  $f8, 0x18($sp)
/* 0EF3D8 7F0BA8A8 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 0EF3DC 7F0BA8AC 460C2182 */  mul.s $f6, $f4, $f12
/* 0EF3E0 7F0BA8B0 00000000 */  nop   
/* 0EF3E4 7F0BA8B4 460A3102 */  mul.s $f4, $f6, $f10
/* 0EF3E8 7F0BA8B8 44815000 */  mtc1  $at, $f10
/* 0EF3EC 7F0BA8BC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EF3F0 7F0BA8C0 46082183 */  div.s $f6, $f4, $f8
/* 0EF3F4 7F0BA8C4 44814000 */  mtc1  $at, $f8
/* 0EF3F8 7F0BA8C8 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EF3FC 7F0BA8CC 460A3103 */  div.s $f4, $f6, $f10
/* 0EF400 7F0BA8D0 C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 0EF404 7F0BA8D4 46086180 */  add.s $f6, $f12, $f8
/* 0EF408 7F0BA8D8 C7A80018 */  lwc1  $f8, 0x18($sp)
/* 0EF40C 7F0BA8DC E4640010 */  swc1  $f4, 0x10($v1)
/* 0EF410 7F0BA8E0 460A3102 */  mul.s $f4, $f6, $f10
/* 0EF414 7F0BA8E4 C7AA001C */  lwc1  $f10, 0x1c($sp)
/* 0EF418 7F0BA8E8 46082183 */  div.s $f6, $f4, $f8
/* 0EF41C 7F0BA8EC 44814000 */  mtc1  $at, $f8
/* 0EF420 7F0BA8F0 3C018008 */  lui   $at, %hi(ptr_nearfog_enviroment_values)
/* 0EF424 7F0BA8F4 460A3100 */  add.s $f4, $f6, $f10
/* 0EF428 7F0BA8F8 46082183 */  div.s $f6, $f4, $f8
/* 0EF42C 7F0BA8FC E4660014 */  swc1  $f6, 0x14($v1)
/* 0EF430 7F0BA900 8CB80020 */  lw    $t8, 0x20($a1)
/* 0EF434 7F0BA904 AC580000 */  sw    $t8, ($v0)
/* 0EF438 7F0BA908 8CB90024 */  lw    $t9, 0x24($a1)
/* 0EF43C 7F0BA90C 24180001 */  li    $t8, 1
/* 0EF440 7F0BA910 AC590004 */  sw    $t9, 4($v0)
/* 0EF444 7F0BA914 90A80028 */  lbu   $t0, 0x28($a1)
/* 0EF448 7F0BA918 A0480008 */  sb    $t0, 8($v0)
/* 0EF44C 7F0BA91C 90A90029 */  lbu   $t1, 0x29($a1)
/* 0EF450 7F0BA920 A0490009 */  sb    $t1, 9($v0)
/* 0EF454 7F0BA924 90AA002A */  lbu   $t2, 0x2a($a1)
/* 0EF458 7F0BA928 A04A000A */  sb    $t2, 0xa($v0)
/* 0EF45C 7F0BA92C 90AB002B */  lbu   $t3, 0x2b($a1)
/* 0EF460 7F0BA930 A04B000B */  sb    $t3, 0xb($v0)
/* 0EF464 7F0BA934 C4AA002C */  lwc1  $f10, 0x2c($a1)
/* 0EF468 7F0BA938 E44A000C */  swc1  $f10, 0xc($v0)
/* 0EF46C 7F0BA93C 84AC0030 */  lh    $t4, 0x30($a1)
/* 0EF470 7F0BA940 A44C0010 */  sh    $t4, 0x10($v0)
/* 0EF474 7F0BA944 C4A40034 */  lwc1  $f4, 0x34($a1)
/* 0EF478 7F0BA948 E4440014 */  swc1  $f4, 0x14($v0)
/* 0EF47C 7F0BA94C C4A80038 */  lwc1  $f8, 0x38($a1)
/* 0EF480 7F0BA950 E4480018 */  swc1  $f8, 0x18($v0)
/* 0EF484 7F0BA954 C4A6003C */  lwc1  $f6, 0x3c($a1)
/* 0EF488 7F0BA958 E446001C */  swc1  $f6, 0x1c($v0)
/* 0EF48C 7F0BA95C 90AD0040 */  lbu   $t5, 0x40($a1)
/* 0EF490 7F0BA960 A04D0020 */  sb    $t5, 0x20($v0)
/* 0EF494 7F0BA964 C4AA0044 */  lwc1  $f10, 0x44($a1)
/* 0EF498 7F0BA968 E44A0024 */  swc1  $f10, 0x24($v0)
/* 0EF49C 7F0BA96C 84AE0048 */  lh    $t6, 0x48($a1)
/* 0EF4A0 7F0BA970 A44E0028 */  sh    $t6, 0x28($v0)
/* 0EF4A4 7F0BA974 C4A4004C */  lwc1  $f4, 0x4c($a1)
/* 0EF4A8 7F0BA978 E444002C */  swc1  $f4, 0x2c($v0)
/* 0EF4AC 7F0BA97C C4A80050 */  lwc1  $f8, 0x50($a1)
/* 0EF4B0 7F0BA980 44802000 */  mtc1  $zero, $f4
/* 0EF4B4 7F0BA984 E4480030 */  swc1  $f8, 0x30($v0)
/* 0EF4B8 7F0BA988 C4A60054 */  lwc1  $f6, 0x54($a1)
/* 0EF4BC 7F0BA98C E4460034 */  swc1  $f6, 0x34($v0)
/* 0EF4C0 7F0BA990 C4AA0058 */  lwc1  $f10, 0x58($a1)
/* 0EF4C4 7F0BA994 E44A0038 */  swc1  $f10, 0x38($v0)
/* 0EF4C8 7F0BA998 C4A8000C */  lwc1  $f8, 0xc($a1)
/* 0EF4CC 7F0BA99C 46082032 */  c.eq.s $f4, $f8
/* 0EF4D0 7F0BA9A0 00000000 */  nop   
/* 0EF4D4 7F0BA9A4 45000004 */  bc1f  .L7F0BA9B8
/* 0EF4D8 7F0BA9A8 00000000 */   nop   
/* 0EF4DC 7F0BA9AC 3C018008 */  lui   $at, %hi(ptr_nearfog_enviroment_values) # $at, 0x8008
/* 0EF4E0 7F0BA9B0 10000002 */  b     .L7F0BA9BC
/* 0EF4E4 7F0BA9B4 AC2025C4 */   sw    $zero, %lo(ptr_nearfog_enviroment_values)($at)
.L7F0BA9B8:
/* 0EF4E8 7F0BA9B8 AC2F25C4 */  sw    $t7, %lo(ptr_nearfog_enviroment_values)($at)
.L7F0BA9BC:
/* 0EF4EC 7F0BA9BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EF4F0 7F0BA9C0 3C018008 */  lui   $at, %hi(sky_enabled) # $at, 0x8008
/* 0EF4F4 7F0BA9C4 AC3825C0 */  sw    $t8, %lo(sky_enabled)($at)
/* 0EF4F8 7F0BA9C8 03E00008 */  jr    $ra
/* 0EF4FC 7F0BA9CC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void copy_table2_env_to_current(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_table2_env_to_current
/* 0EF500 7F0BA9D0 908E0004 */  lbu   $t6, 4($a0)
/* 0EF504 7F0BA9D4 3C028004 */  lui   $v0, %hi(ptr_current_data) # $v0, 0x8004
/* 0EF508 7F0BA9D8 24424DCC */  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
/* 0EF50C 7F0BA9DC A04E0008 */  sb    $t6, 8($v0)
/* 0EF510 7F0BA9E0 908F0005 */  lbu   $t7, 5($a0)
/* 0EF514 7F0BA9E4 A04F0009 */  sb    $t7, 9($v0)
/* 0EF518 7F0BA9E8 90980006 */  lbu   $t8, 6($a0)
/* 0EF51C 7F0BA9EC A058000A */  sb    $t8, 0xa($v0)
/* 0EF520 7F0BA9F0 90990007 */  lbu   $t9, 7($a0)
/* 0EF524 7F0BA9F4 A059000B */  sb    $t9, 0xb($v0)
/* 0EF528 7F0BA9F8 C4840008 */  lwc1  $f4, 8($a0)
/* 0EF52C 7F0BA9FC E444000C */  swc1  $f4, 0xc($v0)
/* 0EF530 7F0BAA00 8488000C */  lh    $t0, 0xc($a0)
/* 0EF534 7F0BAA04 A4480010 */  sh    $t0, 0x10($v0)
/* 0EF538 7F0BAA08 C4860010 */  lwc1  $f6, 0x10($a0)
/* 0EF53C 7F0BAA0C E4460014 */  swc1  $f6, 0x14($v0)
/* 0EF540 7F0BAA10 C4880014 */  lwc1  $f8, 0x14($a0)
/* 0EF544 7F0BAA14 E4480018 */  swc1  $f8, 0x18($v0)
/* 0EF548 7F0BAA18 C48A0018 */  lwc1  $f10, 0x18($a0)
/* 0EF54C 7F0BAA1C E44A001C */  swc1  $f10, 0x1c($v0)
/* 0EF550 7F0BAA20 9089001C */  lbu   $t1, 0x1c($a0)
/* 0EF554 7F0BAA24 A0490020 */  sb    $t1, 0x20($v0)
/* 0EF558 7F0BAA28 C4900020 */  lwc1  $f16, 0x20($a0)
/* 0EF55C 7F0BAA2C E4500024 */  swc1  $f16, 0x24($v0)
/* 0EF560 7F0BAA30 848A0024 */  lh    $t2, 0x24($a0)
/* 0EF564 7F0BAA34 A44A0028 */  sh    $t2, 0x28($v0)
/* 0EF568 7F0BAA38 C4920028 */  lwc1  $f18, 0x28($a0)
/* 0EF56C 7F0BAA3C E452002C */  swc1  $f18, 0x2c($v0)
/* 0EF570 7F0BAA40 C484002C */  lwc1  $f4, 0x2c($a0)
/* 0EF574 7F0BAA44 E4440030 */  swc1  $f4, 0x30($v0)
/* 0EF578 7F0BAA48 C4860030 */  lwc1  $f6, 0x30($a0)
/* 0EF57C 7F0BAA4C E4460034 */  swc1  $f6, 0x34($v0)
/* 0EF580 7F0BAA50 C4880034 */  lwc1  $f8, 0x34($a0)
/* 0EF584 7F0BAA54 03E00008 */  jr    $ra
/* 0EF588 7F0BAA58 E4480038 */   swc1  $f8, 0x38($v0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BAA5C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BAA5C
/* 0EF58C 7F0BAA5C 03E00008 */  jr    $ra
/* 0EF590 7F0BAA60 AFA40000 */   sw    $a0, ($sp)
)
#endif





#ifdef NONMATCHING
void load_enviroment(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel default_near_fog
.word 0x7f7fffff  /*3.4028235e38*/
glabel D_80058D74
.word 0x461c4000  /*10000.0*/
.text
glabel load_enviroment
/* 0EF594 7F0BAA64 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF598 7F0BAA68 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EF59C 7F0BAA6C AFA5002C */  sw    $a1, 0x2c($sp)
/* 0EF5A0 7F0BAA70 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0EF5A4 7F0BAA74 0FC26919 */  jal   get_num_players
/* 0EF5A8 7F0BAA78 AFA40028 */   sw    $a0, 0x28($sp)
/* 0EF5AC 7F0BAA7C 24010001 */  li    $at, 1
/* 0EF5B0 7F0BAA80 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0EF5B4 7F0BAA84 8FA70028 */  lw    $a3, 0x28($sp)
/* 0EF5B8 7F0BAA88 14410002 */  bne   $v0, $at, .L7F0BAA94
/* 0EF5BC 7F0BAA8C 00404025 */   move  $t0, $v0
/* 0EF5C0 7F0BAA90 00004025 */  move  $t0, $zero
.L7F0BAA94:
/* 0EF5C4 7F0BAA94 3C018006 */  lui   $at, %hi(default_near_fog) # $at, 0x8006
/* 0EF5C8 7F0BAA98 C4248D70 */  lwc1  $f4, %lo(default_near_fog)($at)
/* 0EF5CC 7F0BAA9C 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0EF5D0 7F0BAAA0 3C018004 */  lui   $at, %hi(near_fog_value) # $at, 0x8004
/* 0EF5D4 7F0BAAA4 44803000 */  mtc1  $zero, $f6
/* 0EF5D8 7F0BAAA8 E4244DC4 */  swc1  $f4, %lo(near_fog_value)($at)
/* 0EF5DC 7F0BAAAC 3C018004 */  lui   $at, %hi(near_fog_times_intensity) # $at, 0x8004
/* 0EF5E0 7F0BAAB0 11C0001A */  beqz  $t6, .L7F0BAB1C
/* 0EF5E4 7F0BAAB4 E4264DC8 */   swc1  $f6, %lo(near_fog_times_intensity)($at)
/* 0EF5E8 7F0BAAB8 3C098004 */  lui   $t1, %hi(fog_tables)
/* 0EF5EC 7F0BAABC 25234E10 */  addiu $v1, $t1, %lo(fog_tables)
/* 0EF5F0 7F0BAAC0 8C6F0000 */  lw    $t7, ($v1)
/* 0EF5F4 7F0BAAC4 3C188004 */  lui   $t8, %hi(fog_tables) # $t8, 0x8004
/* 0EF5F8 7F0BAAC8 27184E10 */  addiu $t8, %lo(fog_tables) # addiu $t8, $t8, 0x4e10
/* 0EF5FC 7F0BAACC 11E00013 */  beqz  $t7, .L7F0BAB1C
/* 0EF600 7F0BAAD0 24E40384 */   addiu $a0, $a3, 0x384
/* 0EF604 7F0BAAD4 8F020000 */  lw    $v0, ($t8)
.L7F0BAAD8:
/* 0EF608 7F0BAAD8 1482000C */  bne   $a0, $v0, .L7F0BAB0C
/* 0EF60C 7F0BAADC 3C028008 */   lui   $v0, %hi(env_table_hit) # $v0, 0x8008
/* 0EF610 7F0BAAE0 244225E8 */  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
/* 0EF614 7F0BAAE4 AC430000 */  sw    $v1, ($v0)
/* 0EF618 7F0BAAE8 3C018008 */  lui   $at, %hi(env_table_match_start) # $at, 0x8008
/* 0EF61C 7F0BAAEC AC2325EC */  sw    $v1, %lo(env_table_match_start)($at)
/* 0EF620 7F0BAAF0 3C018008 */  lui   $at, %hi(env_table_match_end) # $at, 0x8008
/* 0EF624 7F0BAAF4 2479005C */  addiu $t9, $v1, 0x5c
/* 0EF628 7F0BAAF8 AC3925F0 */  sw    $t9, %lo(env_table_match_end)($at)
/* 0EF62C 7F0BAAFC 0FC2E9D6 */  jal   copy_table1_env_to_current
/* 0EF630 7F0BAB00 8C440000 */   lw    $a0, ($v0)
/* 0EF634 7F0BAB04 10000065 */  b     .L7F0BAC9C
/* 0EF638 7F0BAB08 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BAB0C:
/* 0EF63C 7F0BAB0C 8C62005C */  lw    $v0, 0x5c($v1)
/* 0EF640 7F0BAB10 2463005C */  addiu $v1, $v1, 0x5c
/* 0EF644 7F0BAB14 1440FFF0 */  bnez  $v0, .L7F0BAAD8
/* 0EF648 7F0BAB18 00000000 */   nop   
.L7F0BAB1C:
/* 0EF64C 7F0BAB1C 3C098004 */  lui   $t1, %hi(fog_tables) # $t1, 0x8004
/* 0EF650 7F0BAB20 25294E10 */  addiu $t1, %lo(fog_tables) # addiu $t1, $t1, 0x4e10
/* 0EF654 7F0BAB24 8D250000 */  lw    $a1, ($t1)
/* 0EF658 7F0BAB28 3C0A8004 */  lui   $t2, %hi(fog_tables) # $t2, 0x8004
/* 0EF65C 7F0BAB2C 254A4E10 */  addiu $t2, %lo(fog_tables) # addiu $t2, $t2, 0x4e10
/* 0EF660 7F0BAB30 10A00019 */  beqz  $a1, .L7F0BAB98
/* 0EF664 7F0BAB34 01201825 */   move  $v1, $t1
/* 0EF668 7F0BAB38 00085880 */  sll   $t3, $t0, 2
/* 0EF66C 7F0BAB3C 01685823 */  subu  $t3, $t3, $t0
/* 0EF670 7F0BAB40 000B58C0 */  sll   $t3, $t3, 3
/* 0EF674 7F0BAB44 01685821 */  addu  $t3, $t3, $t0
/* 0EF678 7F0BAB48 000B5880 */  sll   $t3, $t3, 2
/* 0EF67C 7F0BAB4C 00EB2021 */  addu  $a0, $a3, $t3
/* 0EF680 7F0BAB50 8D420000 */  lw    $v0, ($t2)
.L7F0BAB54:
/* 0EF684 7F0BAB54 1482000C */  bne   $a0, $v0, .L7F0BAB88
/* 0EF688 7F0BAB58 3C028008 */   lui   $v0, %hi(env_table_hit) # $v0, 0x8008
/* 0EF68C 7F0BAB5C 244225E8 */  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
/* 0EF690 7F0BAB60 AC430000 */  sw    $v1, ($v0)
/* 0EF694 7F0BAB64 3C018008 */  lui   $at, %hi(env_table_match_start) # $at, 0x8008
/* 0EF698 7F0BAB68 AC2325EC */  sw    $v1, %lo(env_table_match_start)($at)
/* 0EF69C 7F0BAB6C 3C018008 */  lui   $at, %hi(env_table_match_end) # $at, 0x8008
/* 0EF6A0 7F0BAB70 246C005C */  addiu $t4, $v1, 0x5c
/* 0EF6A4 7F0BAB74 AC2C25F0 */  sw    $t4, %lo(env_table_match_end)($at)
/* 0EF6A8 7F0BAB78 0FC2E9D6 */  jal   copy_table1_env_to_current
/* 0EF6AC 7F0BAB7C 8C440000 */   lw    $a0, ($v0)
/* 0EF6B0 7F0BAB80 10000046 */  b     .L7F0BAC9C
/* 0EF6B4 7F0BAB84 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BAB88:
/* 0EF6B8 7F0BAB88 8C62005C */  lw    $v0, 0x5c($v1)
/* 0EF6BC 7F0BAB8C 2463005C */  addiu $v1, $v1, 0x5c
/* 0EF6C0 7F0BAB90 1440FFF0 */  bnez  $v0, .L7F0BAB54
/* 0EF6C4 7F0BAB94 00000000 */   nop   
.L7F0BAB98:
/* 0EF6C8 7F0BAB98 29010002 */  slti  $at, $t0, 2
/* 0EF6CC 7F0BAB9C 5420001D */  bnezl $at, .L7F0BAC14
/* 0EF6D0 7F0BABA0 3C014170 */   lui   $at, 0x4170
/* 0EF6D4 7F0BABA4 10A0001A */  beqz  $a1, .L7F0BAC10
/* 0EF6D8 7F0BABA8 01201825 */   move  $v1, $t1
/* 0EF6DC 7F0BABAC 00082080 */  sll   $a0, $t0, 2
/* 0EF6E0 7F0BABB0 00882023 */  subu  $a0, $a0, $t0
/* 0EF6E4 7F0BABB4 000420C0 */  sll   $a0, $a0, 3
/* 0EF6E8 7F0BABB8 3C0D8004 */  lui   $t5, %hi(fog_tables) # $t5, 0x8004
/* 0EF6EC 7F0BABBC 25AD4E10 */  addiu $t5, %lo(fog_tables) # addiu $t5, $t5, 0x4e10
/* 0EF6F0 7F0BABC0 00882021 */  addu  $a0, $a0, $t0
/* 0EF6F4 7F0BABC4 00042080 */  sll   $a0, $a0, 2
/* 0EF6F8 7F0BABC8 8DA20000 */  lw    $v0, ($t5)
.L7F0BABCC:
/* 0EF6FC 7F0BABCC 1482000C */  bne   $a0, $v0, .L7F0BAC00
/* 0EF700 7F0BABD0 3C028008 */   lui   $v0, %hi(env_table_hit) # $v0, 0x8008
/* 0EF704 7F0BABD4 244225E8 */  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
/* 0EF708 7F0BABD8 AC430000 */  sw    $v1, ($v0)
/* 0EF70C 7F0BABDC 3C018008 */  lui   $at, %hi(env_table_match_start) # $at, 0x8008
/* 0EF710 7F0BABE0 AC2325EC */  sw    $v1, %lo(env_table_match_start)($at)
/* 0EF714 7F0BABE4 3C018008 */  lui   $at, %hi(env_table_match_end) # $at, 0x8008
/* 0EF718 7F0BABE8 246E005C */  addiu $t6, $v1, 0x5c
/* 0EF71C 7F0BABEC AC2E25F0 */  sw    $t6, %lo(env_table_match_end)($at)
/* 0EF720 7F0BABF0 0FC2E9D6 */  jal   copy_table1_env_to_current
/* 0EF724 7F0BABF4 8C440000 */   lw    $a0, ($v0)
/* 0EF728 7F0BABF8 10000028 */  b     .L7F0BAC9C
/* 0EF72C 7F0BABFC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BAC00:
/* 0EF730 7F0BAC00 8C62005C */  lw    $v0, 0x5c($v1)
/* 0EF734 7F0BAC04 2463005C */  addiu $v1, $v1, 0x5c
/* 0EF738 7F0BAC08 1440FFF0 */  bnez  $v0, .L7F0BABCC
/* 0EF73C 7F0BAC0C 00000000 */   nop   
.L7F0BAC10:
/* 0EF740 7F0BAC10 3C014170 */  li    $at, 0x41700000 # 15.000000
.L7F0BAC14:
/* 0EF744 7F0BAC14 44816000 */  mtc1  $at, $f12
/* 0EF748 7F0BAC18 3C018006 */  lui   $at, %hi(D_80058D74) # $at, 0x8006
/* 0EF74C 7F0BAC1C C42E8D74 */  lwc1  $f14, %lo(D_80058D74)($at)
/* 0EF750 7F0BAC20 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0EF754 7F0BAC24 0C001194 */  jal   set_page_height
/* 0EF758 7F0BAC28 AFA70028 */   sw    $a3, 0x28($sp)
/* 0EF75C 7F0BAC2C 3C048004 */  lui   $a0, %hi(fog_tables2) # $a0, 0x8004
/* 0EF760 7F0BAC30 3C018008 */  lui   $at, %hi(sky_enabled) # $at, 0x8008
/* 0EF764 7F0BAC34 24845F50 */  addiu $a0, %lo(fog_tables2) # addiu $a0, $a0, 0x5f50
/* 0EF768 7F0BAC38 AC2025C0 */  sw    $zero, %lo(sky_enabled)($at)
/* 0EF76C 7F0BAC3C 8C8F0000 */  lw    $t7, ($a0)
/* 0EF770 7F0BAC40 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0EF774 7F0BAC44 8FA70028 */  lw    $a3, 0x28($sp)
/* 0EF778 7F0BAC48 11E0000B */  beqz  $t7, .L7F0BAC78
/* 0EF77C 7F0BAC4C 00801825 */   move  $v1, $a0
/* 0EF780 7F0BAC50 3C188004 */  lui   $t8, %hi(fog_tables2) # $t8, 0x8004
/* 0EF784 7F0BAC54 27185F50 */  addiu $t8, %lo(fog_tables2) # addiu $t8, $t8, 0x5f50
/* 0EF788 7F0BAC58 8F020000 */  lw    $v0, ($t8)
.L7F0BAC5C:
/* 0EF78C 7F0BAC5C 54E20003 */  bnel  $a3, $v0, .L7F0BAC6C
/* 0EF790 7F0BAC60 8C620038 */   lw    $v0, 0x38($v1)
/* 0EF794 7F0BAC64 00603025 */  move  $a2, $v1
/* 0EF798 7F0BAC68 8C620038 */  lw    $v0, 0x38($v1)
.L7F0BAC6C:
/* 0EF79C 7F0BAC6C 24630038 */  addiu $v1, $v1, 0x38
/* 0EF7A0 7F0BAC70 1440FFFA */  bnez  $v0, .L7F0BAC5C
/* 0EF7A4 7F0BAC74 00000000 */   nop   
.L7F0BAC78:
/* 0EF7A8 7F0BAC78 14C00002 */  bnez  $a2, .L7F0BAC84
/* 0EF7AC 7F0BAC7C 00000000 */   nop   
/* 0EF7B0 7F0BAC80 00803025 */  move  $a2, $a0
.L7F0BAC84:
/* 0EF7B4 7F0BAC84 0FC2EA74 */  jal   copy_table2_env_to_current
/* 0EF7B8 7F0BAC88 00C02025 */   move  $a0, $a2
/* 0EF7BC 7F0BAC8C 3C028008 */  lui   $v0, %hi(env_table_hit) # $v0, 0x8008
/* 0EF7C0 7F0BAC90 244225E8 */  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
/* 0EF7C4 7F0BAC94 AC400000 */  sw    $zero, ($v0)
/* 0EF7C8 7F0BAC98 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BAC9C:
/* 0EF7CC 7F0BAC9C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0EF7D0 7F0BACA0 03E00008 */  jr    $ra
/* 0EF7D4 7F0BACA4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void switch_to_solosky2(void) {

}
#else
GLOBAL_ASM(
.text
glabel switch_to_solosky2
/* 0EF7D8 7F0BACA8 3C028008 */  lui   $v0, %hi(env_table_match_start) # $v0, 0x8008
/* 0EF7DC 7F0BACAC 8C4225EC */  lw    $v0, %lo(env_table_match_start)($v0)
/* 0EF7E0 7F0BACB0 3C048008 */  lui   $a0, %hi(dword_CODE_bss_800825F8) # $a0, 0x8008
/* 0EF7E4 7F0BACB4 248425F8 */  addiu $a0, %lo(dword_CODE_bss_800825F8) # addiu $a0, $a0, 0x25f8
/* 0EF7E8 7F0BACB8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EF7EC 7F0BACBC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EF7F0 7F0BACC0 00804025 */  move  $t0, $a0
/* 0EF7F4 7F0BACC4 0040C825 */  move  $t9, $v0
/* 0EF7F8 7F0BACC8 24580054 */  addiu $t8, $v0, 0x54
.L7F0BACCC:
/* 0EF7FC 7F0BACCC 8F210000 */  lw    $at, ($t9)
/* 0EF800 7F0BACD0 2739000C */  addiu $t9, $t9, 0xc
/* 0EF804 7F0BACD4 2508000C */  addiu $t0, $t0, 0xc
/* 0EF808 7F0BACD8 AD01FFF4 */  sw    $at, -0xc($t0)
/* 0EF80C 7F0BACDC 8F21FFF8 */  lw    $at, -8($t9)
/* 0EF810 7F0BACE0 AD01FFF8 */  sw    $at, -8($t0)
/* 0EF814 7F0BACE4 8F21FFFC */  lw    $at, -4($t9)
/* 0EF818 7F0BACE8 1738FFF8 */  bne   $t9, $t8, .L7F0BACCC
/* 0EF81C 7F0BACEC AD01FFFC */   sw    $at, -4($t0)
/* 0EF820 7F0BACF0 8F210000 */  lw    $at, ($t9)
/* 0EF824 7F0BACF4 3C038008 */  lui   $v1, %hi(env_table_match_end) # $v1, 0x8008
/* 0EF828 7F0BACF8 AD010000 */  sw    $at, ($t0)
/* 0EF82C 7F0BACFC 8F380004 */  lw    $t8, 4($t9)
/* 0EF830 7F0BAD00 3C018008 */  lui   $at, %hi(flt_CODE_bss_800825FC) # $at, 0x8008
/* 0EF834 7F0BAD04 AD180004 */  sw    $t8, 4($t0)
/* 0EF838 7F0BAD08 8C6325F0 */  lw    $v1, %lo(env_table_match_end)($v1)
/* 0EF83C 7F0BAD0C C4400004 */  lwc1  $f0, 4($v0)
/* 0EF840 7F0BAD10 C4640004 */  lwc1  $f4, 4($v1)
/* 0EF844 7F0BAD14 46002181 */  sub.s $f6, $f4, $f0
/* 0EF848 7F0BAD18 46066202 */  mul.s $f8, $f12, $f6
/* 0EF84C 7F0BAD1C 46080280 */  add.s $f10, $f0, $f8
/* 0EF850 7F0BAD20 E42A25FC */  swc1  $f10, %lo(flt_CODE_bss_800825FC)($at)
/* 0EF854 7F0BAD24 C4420008 */  lwc1  $f2, 8($v0)
/* 0EF858 7F0BAD28 C4640008 */  lwc1  $f4, 8($v1)
/* 0EF85C 7F0BAD2C 3C018008 */  lui   $at, %hi(flt_CODE_bss_80082600) # $at, 0x8008
/* 0EF860 7F0BAD30 46022181 */  sub.s $f6, $f4, $f2
/* 0EF864 7F0BAD34 46066202 */  mul.s $f8, $f12, $f6
/* 0EF868 7F0BAD38 46081280 */  add.s $f10, $f2, $f8
/* 0EF86C 7F0BAD3C E42A2600 */  swc1  $f10, %lo(flt_CODE_bss_80082600)($at)
/* 0EF870 7F0BAD40 8C490020 */  lw    $t1, 0x20($v0)
/* 0EF874 7F0BAD44 8C6A0020 */  lw    $t2, 0x20($v1)
/* 0EF878 7F0BAD48 3C018008 */  lui   $at, %hi(dword_CODE_bss_8008261C) # $at, 0x8008
/* 0EF87C 7F0BAD4C 44892000 */  mtc1  $t1, $f4
/* 0EF880 7F0BAD50 448A3000 */  mtc1  $t2, $f6
/* 0EF884 7F0BAD54 468023A0 */  cvt.s.w $f14, $f4
/* 0EF888 7F0BAD58 46803220 */  cvt.s.w $f8, $f6
/* 0EF88C 7F0BAD5C 460E4281 */  sub.s $f10, $f8, $f14
/* 0EF890 7F0BAD60 460A6102 */  mul.s $f4, $f12, $f10
/* 0EF894 7F0BAD64 46047180 */  add.s $f6, $f14, $f4
/* 0EF898 7F0BAD68 4600320D */  trunc.w.s $f8, $f6
/* 0EF89C 7F0BAD6C 440C4000 */  mfc1  $t4, $f8
/* 0EF8A0 7F0BAD70 00000000 */  nop   
/* 0EF8A4 7F0BAD74 AC2C2618 */  sw    $t4, %lo(dword_CODE_bss_80082618)($at)
/* 0EF8A8 7F0BAD78 8C4D0024 */  lw    $t5, 0x24($v0)
/* 0EF8AC 7F0BAD7C 8C6F0024 */  lw    $t7, 0x24($v1)
/* 0EF8B0 7F0BAD80 448D5000 */  mtc1  $t5, $f10
/* 0EF8B4 7F0BAD84 448F2000 */  mtc1  $t7, $f4
/* 0EF8B8 7F0BAD88 46805420 */  cvt.s.w $f16, $f10
/* 0EF8BC 7F0BAD8C 468021A0 */  cvt.s.w $f6, $f4
/* 0EF8C0 7F0BAD90 46103201 */  sub.s $f8, $f6, $f16
/* 0EF8C4 7F0BAD94 46086282 */  mul.s $f10, $f12, $f8
/* 0EF8C8 7F0BAD98 460A8100 */  add.s $f4, $f16, $f10
/* 0EF8CC 7F0BAD9C 4600218D */  trunc.w.s $f6, $f4
/* 0EF8D0 7F0BADA0 44183000 */  mfc1  $t8, $f6
/* 0EF8D4 7F0BADA4 00000000 */  nop   
/* 0EF8D8 7F0BADA8 AC38261C */  sw    $t8, %lo(dword_CODE_bss_8008261C)($at)
/* 0EF8DC 7F0BADAC 90590028 */  lbu   $t9, 0x28($v0)
/* 0EF8E0 7F0BADB0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EF8E4 7F0BADB4 44994000 */  mtc1  $t9, $f8
/* 0EF8E8 7F0BADB8 07210004 */  bgez  $t9, .L7F0BADCC
/* 0EF8EC 7F0BADBC 468044A0 */   cvt.s.w $f18, $f8
/* 0EF8F0 7F0BADC0 44815000 */  mtc1  $at, $f10
/* 0EF8F4 7F0BADC4 00000000 */  nop   
/* 0EF8F8 7F0BADC8 460A9480 */  add.s $f18, $f18, $f10
.L7F0BADCC:
/* 0EF8FC 7F0BADCC 90680028 */  lbu   $t0, 0x28($v1)
/* 0EF900 7F0BADD0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EF904 7F0BADD4 44882000 */  mtc1  $t0, $f4
/* 0EF908 7F0BADD8 05010004 */  bgez  $t0, .L7F0BADEC
/* 0EF90C 7F0BADDC 468021A0 */   cvt.s.w $f6, $f4
/* 0EF910 7F0BADE0 44814000 */  mtc1  $at, $f8
/* 0EF914 7F0BADE4 00000000 */  nop   
/* 0EF918 7F0BADE8 46083180 */  add.s $f6, $f6, $f8
.L7F0BADEC:
/* 0EF91C 7F0BADEC 46123281 */  sub.s $f10, $f6, $f18
/* 0EF920 7F0BADF0 240A0001 */  li    $t2, 1
/* 0EF924 7F0BADF4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0EF928 7F0BADF8 460A6102 */  mul.s $f4, $f12, $f10
/* 0EF92C 7F0BADFC 46049200 */  add.s $f8, $f18, $f4
/* 0EF930 7F0BAE00 4449F800 */  cfc1  $t1, $31
/* 0EF934 7F0BAE04 44CAF800 */  ctc1  $t2, $31
/* 0EF938 7F0BAE08 00000000 */  nop   
/* 0EF93C 7F0BAE0C 460041A4 */  cvt.w.s $f6, $f8
/* 0EF940 7F0BAE10 444AF800 */  cfc1  $t2, $31
/* 0EF944 7F0BAE14 00000000 */  nop   
/* 0EF948 7F0BAE18 314A0078 */  andi  $t2, $t2, 0x78
/* 0EF94C 7F0BAE1C 51400013 */  beql  $t2, $zero, .L7F0BAE6C
/* 0EF950 7F0BAE20 440A3000 */   mfc1  $t2, $f6
/* 0EF954 7F0BAE24 44813000 */  mtc1  $at, $f6
/* 0EF958 7F0BAE28 240A0001 */  li    $t2, 1
/* 0EF95C 7F0BAE2C 46064181 */  sub.s $f6, $f8, $f6
/* 0EF960 7F0BAE30 44CAF800 */  ctc1  $t2, $31
/* 0EF964 7F0BAE34 00000000 */  nop   
/* 0EF968 7F0BAE38 460031A4 */  cvt.w.s $f6, $f6
/* 0EF96C 7F0BAE3C 444AF800 */  cfc1  $t2, $31
/* 0EF970 7F0BAE40 00000000 */  nop   
/* 0EF974 7F0BAE44 314A0078 */  andi  $t2, $t2, 0x78
/* 0EF978 7F0BAE48 15400005 */  bnez  $t2, .L7F0BAE60
/* 0EF97C 7F0BAE4C 00000000 */   nop   
/* 0EF980 7F0BAE50 440A3000 */  mfc1  $t2, $f6
/* 0EF984 7F0BAE54 3C018000 */  lui   $at, 0x8000
/* 0EF988 7F0BAE58 10000007 */  b     .L7F0BAE78
/* 0EF98C 7F0BAE5C 01415025 */   or    $t2, $t2, $at
.L7F0BAE60:
/* 0EF990 7F0BAE60 10000005 */  b     .L7F0BAE78
/* 0EF994 7F0BAE64 240AFFFF */   li    $t2, -1
/* 0EF998 7F0BAE68 440A3000 */  mfc1  $t2, $f6
.L7F0BAE6C:
/* 0EF99C 7F0BAE6C 00000000 */  nop   
/* 0EF9A0 7F0BAE70 0540FFFB */  bltz  $t2, .L7F0BAE60
/* 0EF9A4 7F0BAE74 00000000 */   nop   
.L7F0BAE78:
/* 0EF9A8 7F0BAE78 3C018008 */  lui   $at, %hi(off_CODE_bss_80082620) # $at, 0x8008
/* 0EF9AC 7F0BAE7C A02A2620 */  sb    $t2, %lo(off_CODE_bss_80082620)($at)
/* 0EF9B0 7F0BAE80 904B0029 */  lbu   $t3, 0x29($v0)
/* 0EF9B4 7F0BAE84 44C9F800 */  ctc1  $t1, $31
/* 0EF9B8 7F0BAE88 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EF9BC 7F0BAE8C 448B5000 */  mtc1  $t3, $f10
/* 0EF9C0 7F0BAE90 05610004 */  bgez  $t3, .L7F0BAEA4
/* 0EF9C4 7F0BAE94 46805120 */   cvt.s.w $f4, $f10
/* 0EF9C8 7F0BAE98 44814000 */  mtc1  $at, $f8
/* 0EF9CC 7F0BAE9C 00000000 */  nop   
/* 0EF9D0 7F0BAEA0 46082100 */  add.s $f4, $f4, $f8
.L7F0BAEA4:
/* 0EF9D4 7F0BAEA4 E7A40018 */  swc1  $f4, 0x18($sp)
/* 0EF9D8 7F0BAEA8 906C0029 */  lbu   $t4, 0x29($v1)
/* 0EF9DC 7F0BAEAC C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0EF9E0 7F0BAEB0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EF9E4 7F0BAEB4 448C3000 */  mtc1  $t4, $f6
/* 0EF9E8 7F0BAEB8 314B00F8 */  andi  $t3, $t2, 0xf8
/* 0EF9EC 7F0BAEBC 05810004 */  bgez  $t4, .L7F0BAED0
/* 0EF9F0 7F0BAEC0 468032A0 */   cvt.s.w $f10, $f6
/* 0EF9F4 7F0BAEC4 44814000 */  mtc1  $at, $f8
/* 0EF9F8 7F0BAEC8 00000000 */  nop   
/* 0EF9FC 7F0BAECC 46085280 */  add.s $f10, $f10, $f8
.L7F0BAED0:
/* 0EFA00 7F0BAED0 46045181 */  sub.s $f6, $f10, $f4
/* 0EFA04 7F0BAED4 240F0001 */  li    $t7, 1
/* 0EFA08 7F0BAED8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0EFA0C 7F0BAEDC 46066202 */  mul.s $f8, $f12, $f6
/* 0EFA10 7F0BAEE0 46082280 */  add.s $f10, $f4, $f8
/* 0EFA14 7F0BAEE4 444DF800 */  cfc1  $t5, $31
/* 0EFA18 7F0BAEE8 44CFF800 */  ctc1  $t7, $31
/* 0EFA1C 7F0BAEEC 00000000 */  nop   
/* 0EFA20 7F0BAEF0 460051A4 */  cvt.w.s $f6, $f10
/* 0EFA24 7F0BAEF4 444FF800 */  cfc1  $t7, $31
/* 0EFA28 7F0BAEF8 00000000 */  nop   
/* 0EFA2C 7F0BAEFC 31EF0078 */  andi  $t7, $t7, 0x78
/* 0EFA30 7F0BAF00 51E00013 */  beql  $t7, $zero, .L7F0BAF50
/* 0EFA34 7F0BAF04 440F3000 */   mfc1  $t7, $f6
/* 0EFA38 7F0BAF08 44813000 */  mtc1  $at, $f6
/* 0EFA3C 7F0BAF0C 240F0001 */  li    $t7, 1
/* 0EFA40 7F0BAF10 46065181 */  sub.s $f6, $f10, $f6
/* 0EFA44 7F0BAF14 44CFF800 */  ctc1  $t7, $31
/* 0EFA48 7F0BAF18 00000000 */  nop   
/* 0EFA4C 7F0BAF1C 460031A4 */  cvt.w.s $f6, $f6
/* 0EFA50 7F0BAF20 444FF800 */  cfc1  $t7, $31
/* 0EFA54 7F0BAF24 00000000 */  nop   
/* 0EFA58 7F0BAF28 31EF0078 */  andi  $t7, $t7, 0x78
/* 0EFA5C 7F0BAF2C 15E00005 */  bnez  $t7, .L7F0BAF44
/* 0EFA60 7F0BAF30 00000000 */   nop   
/* 0EFA64 7F0BAF34 440F3000 */  mfc1  $t7, $f6
/* 0EFA68 7F0BAF38 3C018000 */  lui   $at, 0x8000
/* 0EFA6C 7F0BAF3C 10000007 */  b     .L7F0BAF5C
/* 0EFA70 7F0BAF40 01E17825 */   or    $t7, $t7, $at
.L7F0BAF44:
/* 0EFA74 7F0BAF44 10000005 */  b     .L7F0BAF5C
/* 0EFA78 7F0BAF48 240FFFFF */   li    $t7, -1
/* 0EFA7C 7F0BAF4C 440F3000 */  mfc1  $t7, $f6
.L7F0BAF50:
/* 0EFA80 7F0BAF50 00000000 */  nop   
/* 0EFA84 7F0BAF54 05E0FFFB */  bltz  $t7, .L7F0BAF44
/* 0EFA88 7F0BAF58 00000000 */   nop   
.L7F0BAF5C:
/* 0EFA8C 7F0BAF5C 3C018008 */  lui   $at, %hi(byte_CODE_bss_80082621) # $at, 0x8008
/* 0EFA90 7F0BAF60 A02F2621 */  sb    $t7, %lo(byte_CODE_bss_80082621)($at)
/* 0EFA94 7F0BAF64 904E002A */  lbu   $t6, 0x2a($v0)
/* 0EFA98 7F0BAF68 44CDF800 */  ctc1  $t5, $31
/* 0EFA9C 7F0BAF6C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFAA0 7F0BAF70 448E2000 */  mtc1  $t6, $f4
/* 0EFAA4 7F0BAF74 31ED00F8 */  andi  $t5, $t7, 0xf8
/* 0EFAA8 7F0BAF78 05C10004 */  bgez  $t6, .L7F0BAF8C
/* 0EFAAC 7F0BAF7C 46802220 */   cvt.s.w $f8, $f4
/* 0EFAB0 7F0BAF80 44815000 */  mtc1  $at, $f10
/* 0EFAB4 7F0BAF84 00000000 */  nop   
/* 0EFAB8 7F0BAF88 460A4200 */  add.s $f8, $f8, $f10
.L7F0BAF8C:
/* 0EFABC 7F0BAF8C E7A8001C */  swc1  $f8, 0x1c($sp)
/* 0EFAC0 7F0BAF90 9078002A */  lbu   $t8, 0x2a($v1)
/* 0EFAC4 7F0BAF94 C7A8001C */  lwc1  $f8, 0x1c($sp)
/* 0EFAC8 7F0BAF98 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFACC 7F0BAF9C 44983000 */  mtc1  $t8, $f6
/* 0EFAD0 7F0BAFA0 07010004 */  bgez  $t8, .L7F0BAFB4
/* 0EFAD4 7F0BAFA4 46803120 */   cvt.s.w $f4, $f6
/* 0EFAD8 7F0BAFA8 44815000 */  mtc1  $at, $f10
/* 0EFADC 7F0BAFAC 00000000 */  nop   
/* 0EFAE0 7F0BAFB0 460A2100 */  add.s $f4, $f4, $f10
.L7F0BAFB4:
/* 0EFAE4 7F0BAFB4 46082181 */  sub.s $f6, $f4, $f8
/* 0EFAE8 7F0BAFB8 24080001 */  li    $t0, 1
/* 0EFAEC 7F0BAFBC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0EFAF0 7F0BAFC0 46066282 */  mul.s $f10, $f12, $f6
/* 0EFAF4 7F0BAFC4 460A4100 */  add.s $f4, $f8, $f10
/* 0EFAF8 7F0BAFC8 4459F800 */  cfc1  $t9, $31
/* 0EFAFC 7F0BAFCC 44C8F800 */  ctc1  $t0, $31
/* 0EFB00 7F0BAFD0 00000000 */  nop   
/* 0EFB04 7F0BAFD4 460021A4 */  cvt.w.s $f6, $f4
/* 0EFB08 7F0BAFD8 4448F800 */  cfc1  $t0, $31
/* 0EFB0C 7F0BAFDC 00000000 */  nop   
/* 0EFB10 7F0BAFE0 31080078 */  andi  $t0, $t0, 0x78
/* 0EFB14 7F0BAFE4 51000013 */  beql  $t0, $zero, .L7F0BB034
/* 0EFB18 7F0BAFE8 44083000 */   mfc1  $t0, $f6
/* 0EFB1C 7F0BAFEC 44813000 */  mtc1  $at, $f6
/* 0EFB20 7F0BAFF0 24080001 */  li    $t0, 1
/* 0EFB24 7F0BAFF4 46062181 */  sub.s $f6, $f4, $f6
/* 0EFB28 7F0BAFF8 44C8F800 */  ctc1  $t0, $31
/* 0EFB2C 7F0BAFFC 00000000 */  nop   
/* 0EFB30 7F0BB000 460031A4 */  cvt.w.s $f6, $f6
/* 0EFB34 7F0BB004 4448F800 */  cfc1  $t0, $31
/* 0EFB38 7F0BB008 00000000 */  nop   
/* 0EFB3C 7F0BB00C 31080078 */  andi  $t0, $t0, 0x78
/* 0EFB40 7F0BB010 15000005 */  bnez  $t0, .L7F0BB028
/* 0EFB44 7F0BB014 00000000 */   nop   
/* 0EFB48 7F0BB018 44083000 */  mfc1  $t0, $f6
/* 0EFB4C 7F0BB01C 3C018000 */  lui   $at, 0x8000
/* 0EFB50 7F0BB020 10000007 */  b     .L7F0BB040
/* 0EFB54 7F0BB024 01014025 */   or    $t0, $t0, $at
.L7F0BB028:
/* 0EFB58 7F0BB028 10000005 */  b     .L7F0BB040
/* 0EFB5C 7F0BB02C 2408FFFF */   li    $t0, -1
/* 0EFB60 7F0BB030 44083000 */  mfc1  $t0, $f6
.L7F0BB034:
/* 0EFB64 7F0BB034 00000000 */  nop   
/* 0EFB68 7F0BB038 0500FFFB */  bltz  $t0, .L7F0BB028
/* 0EFB6C 7F0BB03C 00000000 */   nop   
.L7F0BB040:
/* 0EFB70 7F0BB040 3C018008 */  lui   $at, %hi(byte_CODE_bss_80082622) # $at, 0x8008
/* 0EFB74 7F0BB044 A0282622 */  sb    $t0, %lo(byte_CODE_bss_80082622)($at)
/* 0EFB78 7F0BB048 44D9F800 */  ctc1  $t9, $31
/* 0EFB7C 7F0BB04C 311800F8 */  andi  $t8, $t0, 0xf8
/* 0EFB80 7F0BB050 A02B2620 */  sb    $t3, %lo(off_CODE_bss_80082620)($at)
/* 0EFB84 7F0BB054 A02D2621 */  sb    $t5, %lo(byte_CODE_bss_80082621)($at)
/* 0EFB88 7F0BB058 0FC2E9D6 */  jal   copy_table1_env_to_current
/* 0EFB8C 7F0BB05C A0382622 */   sb    $t8, %lo(byte_CODE_bss_80082622)($at)
/* 0EFB90 7F0BB060 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EFB94 7F0BB064 27BD0020 */  addiu $sp, $sp, 0x20
/* 0EFB98 7F0BB068 03E00008 */  jr    $ra
/* 0EFB9C 7F0BB06C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB070(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB070
/* 0EFBA0 7F0BB070 3C0E8008 */  lui   $t6, %hi(sky_enabled) # $t6, 0x8008
/* 0EFBA4 7F0BB074 8DCE25C0 */  lw    $t6, %lo(sky_enabled)($t6)
/* 0EFBA8 7F0BB078 15C00003 */  bnez  $t6, .L7F0BB088
/* 0EFBAC 7F0BB07C 00000000 */   nop   
/* 0EFBB0 7F0BB080 03E00008 */  jr    $ra
/* 0EFBB4 7F0BB084 00801025 */   move  $v0, $a0

.L7F0BB088:
/* 0EFBB8 7F0BB088 10A0003D */  beqz  $a1, .L7F0BB180
/* 0EFBBC 7F0BB08C 3C078004 */   lui   $a3, %hi(ptr_current_data)
/* 0EFBC0 7F0BB090 3C078004 */  lui   $a3, %hi(ptr_current_data) # $a3, 0x8004
/* 0EFBC4 7F0BB094 00801025 */  move  $v0, $a0
/* 0EFBC8 7F0BB098 3C0FF800 */  lui   $t7, 0xf800
/* 0EFBCC 7F0BB09C 24E74DCC */  addiu $a3, %lo(ptr_current_data) # addiu $a3, $a3, 0x4dcc
/* 0EFBD0 7F0BB0A0 AC4F0000 */  sw    $t7, ($v0)
/* 0EFBD4 7F0BB0A4 90ED000A */  lbu   $t5, 0xa($a3)
/* 0EFBD8 7F0BB0A8 90EA0009 */  lbu   $t2, 9($a3)
/* 0EFBDC 7F0BB0AC 90F90008 */  lbu   $t9, 8($a3)
/* 0EFBE0 7F0BB0B0 01A07025 */  move  $t6, $t5
/* 0EFBE4 7F0BB0B4 000A5C00 */  sll   $t3, $t2, 0x10
/* 0EFBE8 7F0BB0B8 00194600 */  sll   $t0, $t9, 0x18
/* 0EFBEC 7F0BB0BC 010B6025 */  or    $t4, $t0, $t3
/* 0EFBF0 7F0BB0C0 000E7A00 */  sll   $t7, $t6, 8
/* 0EFBF4 7F0BB0C4 018FC025 */  or    $t8, $t4, $t7
/* 0EFBF8 7F0BB0C8 371900FF */  ori   $t9, $t8, 0xff
/* 0EFBFC 7F0BB0CC 24840008 */  addiu $a0, $a0, 8
/* 0EFC00 7F0BB0D0 3C09BC00 */  lui   $t1, (0xBC000008 >> 16) # lui $t1, 0xbc00
/* 0EFC04 7F0BB0D4 AC590004 */  sw    $t9, 4($v0)
/* 0EFC08 7F0BB0D8 35290008 */  ori   $t1, (0xBC000008 & 0xFFFF) # ori $t1, $t1, 8
/* 0EFC0C 7F0BB0DC 00801825 */  move  $v1, $a0
/* 0EFC10 7F0BB0E0 AC690000 */  sw    $t1, ($v1)
/* 0EFC14 7F0BB0E4 8CEA0004 */  lw    $t2, 4($a3)
/* 0EFC18 7F0BB0E8 8CE50000 */  lw    $a1, ($a3)
/* 0EFC1C 7F0BB0EC 3C080001 */  lui   $t0, (0x0001F400 >> 16) # lui $t0, 1
/* 0EFC20 7F0BB0F0 3508F400 */  ori   $t0, (0x0001F400 & 0xFFFF) # ori $t0, $t0, 0xf400
/* 0EFC24 7F0BB0F4 01453023 */  subu  $a2, $t2, $a1
/* 0EFC28 7F0BB0F8 0106001A */  div   $zero, $t0, $a2
/* 0EFC2C 7F0BB0FC 00056023 */  negu  $t4, $a1
/* 0EFC30 7F0BB100 000C7A00 */  sll   $t7, $t4, 8
/* 0EFC34 7F0BB104 01E8C021 */  addu  $t8, $t7, $t0
/* 0EFC38 7F0BB108 00005812 */  mflo  $t3
/* 0EFC3C 7F0BB10C 316DFFFF */  andi  $t5, $t3, 0xffff
/* 0EFC40 7F0BB110 000D7400 */  sll   $t6, $t5, 0x10
/* 0EFC44 7F0BB114 0306001A */  div   $zero, $t8, $a2
/* 0EFC48 7F0BB118 0000C812 */  mflo  $t9
/* 0EFC4C 7F0BB11C 3329FFFF */  andi  $t1, $t9, 0xffff
/* 0EFC50 7F0BB120 01C95025 */  or    $t2, $t6, $t1
/* 0EFC54 7F0BB124 AC6A0004 */  sw    $t2, 4($v1)
/* 0EFC58 7F0BB128 24840008 */  addiu $a0, $a0, 8
/* 0EFC5C 7F0BB12C 14C00002 */  bnez  $a2, .L7F0BB138
/* 0EFC60 7F0BB130 00000000 */   nop   
/* 0EFC64 7F0BB134 0007000D */  break 7
.L7F0BB138:
/* 0EFC68 7F0BB138 2401FFFF */  li    $at, -1
/* 0EFC6C 7F0BB13C 14C10004 */  bne   $a2, $at, .L7F0BB150
/* 0EFC70 7F0BB140 3C018000 */   lui   $at, 0x8000
/* 0EFC74 7F0BB144 15010002 */  bne   $t0, $at, .L7F0BB150
/* 0EFC78 7F0BB148 00000000 */   nop   
/* 0EFC7C 7F0BB14C 0006000D */  break 6
.L7F0BB150:
/* 0EFC80 7F0BB150 01000821 */  addu  $at, $t0, $zero
/* 0EFC84 7F0BB154 14C00002 */  bnez  $a2, .L7F0BB160
/* 0EFC88 7F0BB158 00000000 */   nop   
/* 0EFC8C 7F0BB15C 0007000D */  break 7
.L7F0BB160:
/* 0EFC90 7F0BB160 2401FFFF */  li    $at, -1
/* 0EFC94 7F0BB164 14C10004 */  bne   $a2, $at, .L7F0BB178
/* 0EFC98 7F0BB168 3C018000 */   lui   $at, 0x8000
/* 0EFC9C 7F0BB16C 17010002 */  bne   $t8, $at, .L7F0BB178
/* 0EFCA0 7F0BB170 00000000 */   nop   
/* 0EFCA4 7F0BB174 0006000D */  break 6
.L7F0BB178:
/* 0EFCA8 7F0BB178 1000003B */  b     .L7F0BB268
/* 0EFCAC 7F0BB17C 24850008 */   addiu $a1, $a0, 8
.L7F0BB180:
/* 0EFCB0 7F0BB180 00801025 */  move  $v0, $a0
/* 0EFCB4 7F0BB184 3C08F800 */  lui   $t0, 0xf800
/* 0EFCB8 7F0BB188 24E74DCC */  addiu $a3, $a3, %lo(ptr_current_data)
/* 0EFCBC 7F0BB18C AC480000 */  sw    $t0, ($v0)
/* 0EFCC0 7F0BB190 90E9000A */  lbu   $t1, 0xa($a3)
/* 0EFCC4 7F0BB194 90F80009 */  lbu   $t8, 9($a3)
/* 0EFCC8 7F0BB198 90ED0008 */  lbu   $t5, 8($a3)
/* 0EFCCC 7F0BB19C 01205025 */  move  $t2, $t1
/* 0EFCD0 7F0BB1A0 0018CC00 */  sll   $t9, $t8, 0x10
/* 0EFCD4 7F0BB1A4 000D6600 */  sll   $t4, $t5, 0x18
/* 0EFCD8 7F0BB1A8 01997025 */  or    $t6, $t4, $t9
/* 0EFCDC 7F0BB1AC 000A4200 */  sll   $t0, $t2, 8
/* 0EFCE0 7F0BB1B0 01C85825 */  or    $t3, $t6, $t0
/* 0EFCE4 7F0BB1B4 356D00FF */  ori   $t5, $t3, 0xff
/* 0EFCE8 7F0BB1B8 24840008 */  addiu $a0, $a0, 8
/* 0EFCEC 7F0BB1BC 3C0FBC00 */  lui   $t7, (0xBC000008 >> 16) # lui $t7, 0xbc00
/* 0EFCF0 7F0BB1C0 AC4D0004 */  sw    $t5, 4($v0)
/* 0EFCF4 7F0BB1C4 35EF0008 */  ori   $t7, (0xBC000008 & 0xFFFF) # ori $t7, $t7, 8
/* 0EFCF8 7F0BB1C8 00801825 */  move  $v1, $a0
/* 0EFCFC 7F0BB1CC AC6F0000 */  sw    $t7, ($v1)
/* 0EFD00 7F0BB1D0 8CF80004 */  lw    $t8, 4($a3)
/* 0EFD04 7F0BB1D4 8CE50000 */  lw    $a1, ($a3)
/* 0EFD08 7F0BB1D8 3C0C0001 */  lui   $t4, (0x0001F400 >> 16) # lui $t4, 1
/* 0EFD0C 7F0BB1DC 358CF400 */  ori   $t4, (0x0001F400 & 0xFFFF) # ori $t4, $t4, 0xf400
/* 0EFD10 7F0BB1E0 03053023 */  subu  $a2, $t8, $a1
/* 0EFD14 7F0BB1E4 0186001A */  div   $zero, $t4, $a2
/* 0EFD18 7F0BB1E8 00057023 */  negu  $t6, $a1
/* 0EFD1C 7F0BB1EC 000E4200 */  sll   $t0, $t6, 8
/* 0EFD20 7F0BB1F0 010C5821 */  addu  $t3, $t0, $t4
/* 0EFD24 7F0BB1F4 0000C812 */  mflo  $t9
/* 0EFD28 7F0BB1F8 3329FFFF */  andi  $t1, $t9, 0xffff
/* 0EFD2C 7F0BB1FC 00095400 */  sll   $t2, $t1, 0x10
/* 0EFD30 7F0BB200 0166001A */  div   $zero, $t3, $a2
/* 0EFD34 7F0BB204 00006812 */  mflo  $t5
/* 0EFD38 7F0BB208 31AFFFFF */  andi  $t7, $t5, 0xffff
/* 0EFD3C 7F0BB20C 014FC025 */  or    $t8, $t2, $t7
/* 0EFD40 7F0BB210 AC780004 */  sw    $t8, 4($v1)
/* 0EFD44 7F0BB214 24840008 */  addiu $a0, $a0, 8
/* 0EFD48 7F0BB218 14C00002 */  bnez  $a2, .L7F0BB224
/* 0EFD4C 7F0BB21C 00000000 */   nop   
/* 0EFD50 7F0BB220 0007000D */  break 7
.L7F0BB224:
/* 0EFD54 7F0BB224 2401FFFF */  li    $at, -1
/* 0EFD58 7F0BB228 14C10004 */  bne   $a2, $at, .L7F0BB23C
/* 0EFD5C 7F0BB22C 3C018000 */   lui   $at, 0x8000
/* 0EFD60 7F0BB230 15810002 */  bne   $t4, $at, .L7F0BB23C
/* 0EFD64 7F0BB234 00000000 */   nop   
/* 0EFD68 7F0BB238 0006000D */  break 6
.L7F0BB23C:
/* 0EFD6C 7F0BB23C 01800821 */  addu  $at, $t4, $zero
/* 0EFD70 7F0BB240 14C00002 */  bnez  $a2, .L7F0BB24C
/* 0EFD74 7F0BB244 00000000 */   nop   
/* 0EFD78 7F0BB248 0007000D */  break 7
.L7F0BB24C:
/* 0EFD7C 7F0BB24C 2401FFFF */  li    $at, -1
/* 0EFD80 7F0BB250 14C10004 */  bne   $a2, $at, .L7F0BB264
/* 0EFD84 7F0BB254 3C018000 */   lui   $at, 0x8000
/* 0EFD88 7F0BB258 15610002 */  bne   $t3, $at, .L7F0BB264
/* 0EFD8C 7F0BB25C 00000000 */   nop   
/* 0EFD90 7F0BB260 0006000D */  break 6
.L7F0BB264:
/* 0EFD94 7F0BB264 24850008 */  addiu $a1, $a0, 8
.L7F0BB268:
/* 0EFD98 7F0BB268 3C0CB700 */  lui   $t4, 0xb700
/* 0EFD9C 7F0BB26C 3C190001 */  lui   $t9, 1
/* 0EFDA0 7F0BB270 AC990004 */  sw    $t9, 4($a0)
/* 0EFDA4 7F0BB274 AC8C0000 */  sw    $t4, ($a0)
/* 0EFDA8 7F0BB278 3C09BA00 */  lui   $t1, (0xBA000402 >> 16) # lui $t1, 0xba00
/* 0EFDAC 7F0BB27C 35290402 */  ori   $t1, (0xBA000402 & 0xFFFF) # ori $t1, $t1, 0x402
/* 0EFDB0 7F0BB280 240E0020 */  li    $t6, 32
/* 0EFDB4 7F0BB284 ACAE0004 */  sw    $t6, 4($a1)
/* 0EFDB8 7F0BB288 ACA90000 */  sw    $t1, ($a1)
/* 0EFDBC 7F0BB28C 24A20008 */  addiu $v0, $a1, 8
/* 0EFDC0 7F0BB290 03E00008 */  jr    $ra
/* 0EFDC4 7F0BB294 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB298(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB298
/* 0EFDC8 7F0BB298 3C0E8008 */  lui   $t6, %hi(sky_enabled) # $t6, 0x8008
/* 0EFDCC 7F0BB29C 8DCE25C0 */  lw    $t6, %lo(sky_enabled)($t6)
/* 0EFDD0 7F0BB2A0 24820008 */  addiu $v0, $a0, 8
/* 0EFDD4 7F0BB2A4 3C0FB600 */  lui   $t7, 0xb600
/* 0EFDD8 7F0BB2A8 15C00003 */  bnez  $t6, .L7F0BB2B8
/* 0EFDDC 7F0BB2AC 3C180001 */   lui   $t8, 1
/* 0EFDE0 7F0BB2B0 03E00008 */  jr    $ra
/* 0EFDE4 7F0BB2B4 00801025 */   move  $v0, $a0

.L7F0BB2B8:
/* 0EFDE8 7F0BB2B8 AC8F0000 */  sw    $t7, ($a0)
/* 0EFDEC 7F0BB2BC AC980004 */  sw    $t8, 4($a0)
/* 0EFDF0 7F0BB2C0 03E00008 */  jr    $ra
/* 0EFDF4 7F0BB2C4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB2C8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB2C8
/* 0EFDF8 7F0BB2C8 3C0E8008 */  lui   $t6, %hi(sky_enabled) # $t6, 0x8008
/* 0EFDFC 7F0BB2CC 8DCE25C0 */  lw    $t6, %lo(sky_enabled)($t6)
/* 0EFE00 7F0BB2D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EFE04 7F0BB2D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EFE08 7F0BB2D8 15C00003 */  bnez  $t6, .L7F0BB2E8
/* 0EFE0C 7F0BB2DC AFA50034 */   sw    $a1, 0x34($sp)
/* 0EFE10 7F0BB2E0 10000029 */  b     .L7F0BB388
/* 0EFE14 7F0BB2E4 24020001 */   li    $v0, 1
.L7F0BB2E8:
/* 0EFE18 7F0BB2E8 0FC227F5 */  jal   get_BONDdata_position
/* 0EFE1C 7F0BB2EC AFA40030 */   sw    $a0, 0x30($sp)
/* 0EFE20 7F0BB2F0 0FC1E0F1 */  jal   get_BONDdata_field_10CC
/* 0EFE24 7F0BB2F4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0EFE28 7F0BB2F8 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0EFE2C 7F0BB2FC 8FA40030 */  lw    $a0, 0x30($sp)
/* 0EFE30 7F0BB300 3C018004 */  lui   $at, %hi(near_fog_value) # $at, 0x8004
/* 0EFE34 7F0BB304 C4660000 */  lwc1  $f6, ($v1)
/* 0EFE38 7F0BB308 C4840000 */  lwc1  $f4, ($a0)
/* 0EFE3C 7F0BB30C 46062201 */  sub.s $f8, $f4, $f6
/* 0EFE40 7F0BB310 E7A80024 */  swc1  $f8, 0x24($sp)
/* 0EFE44 7F0BB314 C4700004 */  lwc1  $f16, 4($v1)
/* 0EFE48 7F0BB318 C48A0004 */  lwc1  $f10, 4($a0)
/* 0EFE4C 7F0BB31C 46105481 */  sub.s $f18, $f10, $f16
/* 0EFE50 7F0BB320 C7AA0024 */  lwc1  $f10, 0x24($sp)
/* 0EFE54 7F0BB324 E7B20028 */  swc1  $f18, 0x28($sp)
/* 0EFE58 7F0BB328 C4660008 */  lwc1  $f6, 8($v1)
/* 0EFE5C 7F0BB32C C4840008 */  lwc1  $f4, 8($a0)
/* 0EFE60 7F0BB330 46062201 */  sub.s $f8, $f4, $f6
/* 0EFE64 7F0BB334 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 0EFE68 7F0BB338 E7A8002C */  swc1  $f8, 0x2c($sp)
/* 0EFE6C 7F0BB33C C4500000 */  lwc1  $f16, ($v0)
/* 0EFE70 7F0BB340 C4460004 */  lwc1  $f6, 4($v0)
/* 0EFE74 7F0BB344 46105482 */  mul.s $f18, $f10, $f16
/* 0EFE78 7F0BB348 C4500008 */  lwc1  $f16, 8($v0)
/* 0EFE7C 7F0BB34C 24020001 */  li    $v0, 1
/* 0EFE80 7F0BB350 46062202 */  mul.s $f8, $f4, $f6
/* 0EFE84 7F0BB354 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 0EFE88 7F0BB358 46048182 */  mul.s $f6, $f16, $f4
/* 0EFE8C 7F0BB35C 46089280 */  add.s $f10, $f18, $f8
/* 0EFE90 7F0BB360 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 0EFE94 7F0BB364 C4324DC4 */  lwc1  $f18, %lo(near_fog_value)($at)
/* 0EFE98 7F0BB368 460A3000 */  add.s $f0, $f6, $f10
/* 0EFE9C 7F0BB36C 46089400 */  add.s $f16, $f18, $f8
/* 0EFEA0 7F0BB370 4600803C */  c.lt.s $f16, $f0
/* 0EFEA4 7F0BB374 00000000 */  nop   
/* 0EFEA8 7F0BB378 45000003 */  bc1f  .L7F0BB388
/* 0EFEAC 7F0BB37C 00000000 */   nop   
/* 0EFEB0 7F0BB380 10000001 */  b     .L7F0BB388
/* 0EFEB4 7F0BB384 00001025 */   move  $v0, $zero
.L7F0BB388:
/* 0EFEB8 7F0BB388 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EFEBC 7F0BB38C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0EFEC0 7F0BB390 03E00008 */  jr    $ra
/* 0EFEC4 7F0BB394 00000000 */   nop   
)
#endif





u32 return_nearfog_values(void){
  return ptr_nearfog_enviroment_values;
}






#ifdef NONMATCHING
void if_sky_present_convert_values(void) {

}
#else
GLOBAL_ASM(
.text
glabel if_sky_present_convert_values
/* 0EFED4 7F0BB3A4 3C0E8008 */  lui   $t6, %hi(sky_enabled) # $t6, 0x8008
/* 0EFED8 7F0BB3A8 8DCE25C0 */  lw    $t6, %lo(sky_enabled)($t6)
/* 0EFEDC 7F0BB3AC 55C00004 */  bnezl $t6, .L7F0BB3C0
/* 0EFEE0 7F0BB3B0 44801000 */   mtc1  $zero, $f2
/* 0EFEE4 7F0BB3B4 03E00008 */  jr    $ra
/* 0EFEE8 7F0BB3B8 24020002 */   li    $v0, 2

/* 0EFEEC 7F0BB3BC 44801000 */  mtc1  $zero, $f2
.L7F0BB3C0:
/* 0EFEF0 7F0BB3C0 C4840018 */  lwc1  $f4, 0x18($a0)
/* 0EFEF4 7F0BB3C4 3C028004 */  lui   $v0, %hi(ptr_current_data) # $v0, 0x8004
/* 0EFEF8 7F0BB3C8 24424DCC */  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
/* 0EFEFC 7F0BB3CC 4602203C */  c.lt.s $f4, $f2
/* 0EFF00 7F0BB3D0 3C038008 */  lui   $v1, %hi(buffer_far_pervasiveness)
/* 0EFF04 7F0BB3D4 45020004 */  bc1fl .L7F0BB3E8
/* 0EFF08 7F0BB3D8 904F0008 */   lbu   $t7, 8($v0)
/* 0EFF0C 7F0BB3DC 03E00008 */  jr    $ra
/* 0EFF10 7F0BB3E0 24020002 */   li    $v0, 2

/* 0EFF14 7F0BB3E4 904F0008 */  lbu   $t7, 8($v0)
.L7F0BB3E8:
/* 0EFF18 7F0BB3E8 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EFF1C 7F0BB3EC 44816000 */  mtc1  $at, $f12
/* 0EFF20 7F0BB3F0 448F3000 */  mtc1  $t7, $f6
/* 0EFF24 7F0BB3F4 246325C8 */  addiu $v1, $v1, %lo(buffer_far_pervasiveness)
/* 0EFF28 7F0BB3F8 05E10005 */  bgez  $t7, .L7F0BB410
/* 0EFF2C 7F0BB3FC 46803220 */   cvt.s.w $f8, $f6
/* 0EFF30 7F0BB400 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF34 7F0BB404 44815000 */  mtc1  $at, $f10
/* 0EFF38 7F0BB408 00000000 */  nop   
/* 0EFF3C 7F0BB40C 460A4200 */  add.s $f8, $f8, $f10
.L7F0BB410:
/* 0EFF40 7F0BB410 460C4403 */  div.s $f16, $f8, $f12
/* 0EFF44 7F0BB414 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF48 7F0BB418 E4B00000 */  swc1  $f16, ($a1)
/* 0EFF4C 7F0BB41C 90580009 */  lbu   $t8, 9($v0)
/* 0EFF50 7F0BB420 44989000 */  mtc1  $t8, $f18
/* 0EFF54 7F0BB424 07010004 */  bgez  $t8, .L7F0BB438
/* 0EFF58 7F0BB428 46809120 */   cvt.s.w $f4, $f18
/* 0EFF5C 7F0BB42C 44813000 */  mtc1  $at, $f6
/* 0EFF60 7F0BB430 00000000 */  nop   
/* 0EFF64 7F0BB434 46062100 */  add.s $f4, $f4, $f6
.L7F0BB438:
/* 0EFF68 7F0BB438 460C2283 */  div.s $f10, $f4, $f12
/* 0EFF6C 7F0BB43C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF70 7F0BB440 E4AA0004 */  swc1  $f10, 4($a1)
/* 0EFF74 7F0BB444 9059000A */  lbu   $t9, 0xa($v0)
/* 0EFF78 7F0BB448 44994000 */  mtc1  $t9, $f8
/* 0EFF7C 7F0BB44C 07210004 */  bgez  $t9, .L7F0BB460
/* 0EFF80 7F0BB450 46804420 */   cvt.s.w $f16, $f8
/* 0EFF84 7F0BB454 44819000 */  mtc1  $at, $f18
/* 0EFF88 7F0BB458 00000000 */  nop   
/* 0EFF8C 7F0BB45C 46128400 */  add.s $f16, $f16, $f18
.L7F0BB460:
/* 0EFF90 7F0BB460 460C8183 */  div.s $f6, $f16, $f12
/* 0EFF94 7F0BB464 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EFF98 7F0BB468 E4A60008 */  swc1  $f6, 8($a1)
/* 0EFF9C 7F0BB46C C48A0018 */  lwc1  $f10, 0x18($a0)
/* 0EFFA0 7F0BB470 C4640010 */  lwc1  $f4, 0x10($v1)
/* 0EFFA4 7F0BB474 C4720014 */  lwc1  $f18, 0x14($v1)
/* 0EFFA8 7F0BB478 460A2203 */  div.s $f8, $f4, $f10
/* 0EFFAC 7F0BB47C 46124400 */  add.s $f16, $f8, $f18
/* 0EFFB0 7F0BB480 E4B0000C */  swc1  $f16, 0xc($a1)
/* 0EFFB4 7F0BB484 C4A0000C */  lwc1  $f0, 0xc($a1)
/* 0EFFB8 7F0BB488 4602003C */  c.lt.s $f0, $f2
/* 0EFFBC 7F0BB48C 00000000 */  nop   
/* 0EFFC0 7F0BB490 45020004 */  bc1fl .L7F0BB4A4
/* 0EFFC4 7F0BB494 44813000 */   mtc1  $at, $f6
/* 0EFFC8 7F0BB498 03E00008 */  jr    $ra
/* 0EFFCC 7F0BB49C 24020002 */   li    $v0, 2

/* 0EFFD0 7F0BB4A0 44813000 */  mtc1  $at, $f6
.L7F0BB4A4:
/* 0EFFD4 7F0BB4A4 24020001 */  li    $v0, 1
/* 0EFFD8 7F0BB4A8 4600303C */  c.lt.s $f6, $f0
/* 0EFFDC 7F0BB4AC 00000000 */  nop   
/* 0EFFE0 7F0BB4B0 45000003 */  bc1f  .L7F0BB4C0
/* 0EFFE4 7F0BB4B4 00000000 */   nop   
/* 0EFFE8 7F0BB4B8 03E00008 */  jr    $ra
/* 0EFFEC 7F0BB4BC 00001025 */   move  $v0, $zero

.L7F0BB4C0:
/* 0EFFF0 7F0BB4C0 03E00008 */  jr    $ra
/* 0EFFF4 7F0BB4C4 00000000 */   nop   
)
#endif



