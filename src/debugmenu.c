#include "ultra64.h"
#include "debugmenu.h"
#include "vi.h"

u32 image_resource[] = {  
         0,  0x227A00,  0x7A348B,  0x223434,  0x115811,  0x696900,         0,    0x9C00,
    0x4600,  0x460000,    0x4600,         0,         0,         0,         0,      0x46,
  0x229C11,  0x346900,  0x229C11,  0x699C11,    0x5834,  0xADAD34,  0x118B34,  0x9CAD7A,
  0x229C11,  0x229C11,         0,         0,         0,         0,         0,  0x113411,
         0,  0x46CE00,  0xAD58DE,  0x466969,  0x9C9C69,  0x8B8B00,  0x469C00,  0x22CE00,
  0x583400,  0x345800,  0x7ACE69,    0x5800,         0,         0,         0,    0x3446,
  0x8B007A,  0x588B00,  0x8B008B,  0x22007A,  0x119C69,  0x8B0000,  0x9C1100,  0x22008B,
  0x8B007A,  0x8B007A,         0,         0,  0x225869,         0,0x69582200,  0x9C698B,
         0,  0x46CE00,  0x222258,  0xDEEF7A,  0xAD1111,  0x69EF9C,  0x8B0000,  0x460000,
  0x8B0000,    0x8B00,  0x58CE34,    0x8B00,         0,         0,         0,    0x8B00,
  0x8B008B,    0x8B00,  0x11007A,  0x118B46,  0x58467A,  0xCEAD22,  0x9C8B00,    0x117A,
  0x698B46,  0x8B00AD,  0x34AD00,  0x34AD00,0x228B4600,0x8B8B8B8B,  0x468B22,  0x11008B,
         0,    0x7A00,         0,  0x9C9C00,  0x118B34,0x22ADBD46,  0x8B8B34,         0,
  0x8B0000,    0x8B00,  0x7A2269,0x22ADEF9C,         0,0x22ADADAD,         0,  0x226900,
  0x8B008B,    0x8B00,    0x7A00,    0x117A,  0x9C347A,      0x8B,  0xCE117A,    0x2269,
  0x8B227A,  0x229C8B,    0x1100,    0x1100,0xAD580000,0x34343434,    0x58AD,    0xBD34,
         0,  0x112200,         0,0x22DEDE22,  0xCE5858,  0x46468B,  0x8BAD00,         0,
  0x8B0000,    0x8B00,         0,    0x8B00,    0x3400,         0,    0x2200,  0x691100,
  0x8B008B,    0x8B00,  0x691158,  0x11008B,  0x7A9CAD,0x1122008B,  0x8B008B,    0x8B00,
  0x8B008B,    0x227A,    0x2200,    0x2200,0x228B4600,0x8B8B8B8B,  0x468B22,    0x6900,
         0,  0x228B00,         0,  0x8B8B00,  0x34BD00,  0x119C46,  0x7A6969,         0,
  0x583400,  0x345800,         0,    0x5800,  0x11FF00,         0,  0x228B00,  0x8B0000,
  0x349C22,  0x8BCE69,0x22BDAD8B,  0x7A9C11,    0x8B8B,0x118B9C11,  0x349C22,    0x5800,
  0x349C11,  0x588B11,  0x228B00,  0x69AD00,  0x225869,         0,0x69582200,    0xBD00,
         0,         0,         0,  0x464600,    0x4600,         0,         0,         0,
    0x4600,  0x460000,         0,         0,  0x583400,         0,         0,0x58340000,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,  0x8B0000,         0,         0,         0,         0,
  0x229C11,  0x221100,0x11223400,    0x3411,0x11342200,  0x343422,  0x343422,    0x2222,
  0x220022,  0x342222,    0x3434,  0x341122,0x22341100,0x11110022,0x22221134,    0x2200,
  0x343411,    0x3400,  0x343411,  0x113411,  0x343434,0x11341134,0x11220034,0x34220034,
0x11340022,0x11220034,  0x223422,    0x8B34,  0x460000,  0x587A00,    0x5800,         0,
0x348B008B,  0x69BD00,0x11DE7A58,  0xAD69DE,0x22CE7A9C,0x11CE7AAD,0x11CE7AAD,  0xAD7ADE,
0x22CE00CE,  0x69CE58,    0x8BCE,0x22CE22CE,0x46CE4600,0x7ABD00FF,0x58FF46CE,  0xAD7A9C,
0x11CE7A7A,  0xAD7A8B,0x22CE7A7A,0x118B7ABD,0x469CCECE,0x8B8B34CE,0x8B8B00BD,0xBD8B22BD,
0x58CE00CE,0x22BD00CE,  0xBD7AAD,    0x8B00,  0x7A1100,    0x8B00,  0x694658,         0,
0x468B7ABD,  0x588B22,  0x8B008B,0x46460011,  0x8B007A,0x118B3458,  0x8B3458,0x46460011,
  0x8B008B,    0x8B00,    0x117A,  0x8B7A11,  0x8B0000,0x589C58BD,0x11AD698B,0x4646007A,
0x118B007A,0x5846007A,0x118B007A,0x46580011,0x34228B46,0x6934008B,  0x7A008B,0x58348B7A,
0x11696946,  0x695846,  0x113458,    0x8B00,  0x116900,    0x8B00,  0x110011,         0,
0x468B8B9C,  0x9C228B,  0xDEAD7A,0x58340000,  0x8B007A,0x11DEAD00,  0xDEAD00,0x583400AD,
0x46DEADBD,    0x8B00,0x3411117A,  0xDEAD00,  0x8B0000,0x5846AD7A,0x118B8B8B,0x5834007A,
0x11DEAD34,0x5834007A,0x11DEDE46,  0x58AD34,    0x8B00,0x5834008B,  0x8B117A,  0xBDDE8B,
  0x22AD00,  0x11BD00,  0x226900,    0x8B00,    0x8B00,    0x8B00,         0,         0,
0x348B348B,0x469C8BAD,  0x8B007A,0x347A0058,  0x8B009C,  0x8B008B,  0x8B0000,0x228B007A,
  0x8B008B,    0x8B00,0x46462269,  0x8B117A,  0x8B007A,0x6934347A,0x118B34DE,0x118B009C,
  0x8B0000,0x228B009C,  0x8B117A,0x3434008B,    0x8B00,0x4646008B,  0x22CE00,  0xADBD8B,
  0x8B007A,    0x8B00,  0x8B0058,    0x8B00,    0x3446,    0x8B00,         0,         0,
  0x697A9C,0x7A9C00BD,0x69CEAD58,  0x58AD58,0x22BDAD34,0x22CEAD8B,0x22BD2200,  0x58AD58,
0x22AD00CE,  0x8BBD7A,  0x7A7A00,0x22BD228B,0x69BDADBD,0x8B9C00BD,0x69CE227A,  0x58AD34,
0x22CE6900,  0x9CEF69,0x22BD2258,0x7A9C9C22,  0x46CE34,  0x7AAD11,    0x5800,  0x580058,
0x22AD00CE,  0x58BD34,  0xAD9C9C,    0x8B00,      0x8B,    0x8B00,         0,0x22222222,
    0x2211,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,  0x58588B,         0,         0,         0,         0,         0,         0,
         0,         0,         0,    0xCE34,      0x7A,0x1158AD00,         0,0x7A7A7A7A,
  0x693400,         0,0x22690000,         0,      0x8B,         0,    0x589C,0x11000000,
0x22690000,    0x1100,    0x1100,0x22690000,  0x8B7A00,         0,         0,         0,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,    0x4646,    0x4600,  0x464600,         0,         0,
  0x46AD00,         0,  0x8B0000,         0,      0x8B,         0,  0x116900,         0,
  0x8B0000,    0x6900,    0x6900,  0x8B0000,    0x8B00,         0,         0,         0,
         0,         0,         0,         0,  0x226900,         0,         0,         0,
         0,         0,         0,    0x8B00,    0x8B00,    0x8B00,         0,         0,
    0x5800,  0x8B9C34,  0xCEAD69,  0x7AAD9C,  0x8BADBD,  0x7AAD34,  0x9CDE7A,  0x8B9CCE,
0x11CEAD69,  0x589C00,  0x8BAD69,  0x8BAD69,    0x8B00,0x7AAD9C9C,0x22CEAD69,  0x7AAD34,
0x22CEAD69,  0x8B9CDE,0x22DE9C69,  0x7AAD9C,  0x9CDE7A,0x118B00AD,0x11CE00DE,0x34CE00DE,
0x22CE34AD,0x22CE00DE,  0xBD9CAD,    0x8B00,    0x8B00,    0x8B00,0x229C347A,         0,
         0,  0x9CAD7A,  0x8B007A,0x69340034,0x4634009C,0x46CE9CBD,  0x226900,0x4646008B,
  0x8B008B,    0x8B00,      0x7A,  0xDE7A00,    0x8B00,0x46468B69,0x119C008B,0x4646008B,
  0x8B0069,0x5846008B,  0x8B0000,  0x8B7A58,  0x226900,  0x8B008B,  0x7A117A,  0x8B8B8B,
  0x58BD00,  0x8B008B,  0x464646,  0x467A00,    0x8B00,    0x8B46,0x7A349C22,         0,
         0,0x4634227A,  0x9C007A,0x58460022,0x4646009C,0x34460034,  0x226900,0x3446009C,
  0x8B008B,    0x8B00,      0x7A,  0x8B6911,    0x8B00,0x46468B69,0x118B008B,0x3458008B,
  0xAD0069,0x584600AD,  0x8B0000,  0x69348B,  0x226911,  0x8B009C,  0x11DE00,  0xADBD8B,
  0x699C11,  0x469C34,  0x225858,    0x8B00,    0x8B00,    0x8B00,         0,         0,
         0,0x119C8BCE,0x22ADAD58,  0x7A9C46,  0x69ADAD,0x1169AD46,  0x8BBD7A,  0x69ADAD,
0x22AD00BD,0x118BCE69,      0x7A,0x227A34CE,  0x8BBD7A,0x7A699C46,0x69BD00CE,  0x7A9C22,
  0xBD9C58,  0x69ADAD,0x22CE9C34,  0x8BAD58,    0x9C8B,  0x699CAD,0x11005800,  0x580069,
0x11BD349C,    0x9C00,  0xADAD9C,    0x8B00,    0x8B00,    0x8B00,         0,         0,
         0,         0,         0,         0,         0,         0,         0,      0x8B,
         0,         0,    0x4646,         0,         0,         0,         0,         0,
  0x8B0000,      0x8B,         0,         0,         0,         0,         0,         0,
         0,  0x226900,         0,    0x8B46,    0x8B00,  0x467A00,         0,         0 
};

s32 debug_menu_x_pos_offset = 5;
s32 debug_menu_y_pos_offset = 1;
s32 debug_menu_x_text_pos = 0x18;
s32 debug_menu_y_text_pos = 0x10;

u32 stdout_display_list[] = {
    0xE7000000,         0, //gsDPPipeSync(),
    0xBA001402,         0, //gsDPSetCycleType(G_CYC_1CYCLE),
    0xBA000602,      0xC0, //gsDPSetTextureLOD
    0xB900031D,0x500A4240, //gsDPSetRenderMode
    0xFC30B261,0x5566DB6D, //gsDPSetCombineMode
    0xBA001301,         0, //gsDPSetTextureLOD
    0xB9000002,         0, //gsDPSetRenderMode
    0xFD700000,&image_resource[0], //gsDPSetTextureImage
    0xF5700000, 0x7000000, //gsDPSetTile
    0xE6000000,         0, //gsDPLoadSync(),
    0xF3000000, 0x753F080, //gsDPLoadBlock
    0xE7000000,         0, //gsDPPipeSync(),
    0xF5682000,         0, //gsDPSetTile
    0xF2000000,  0x1FC050, //gsDPSetTileSize
    0xE6000000,         0, //gsDPLoadSync(),
    0xB8000000,         0 //gsSPEndDisplayList(),
};

u32 stdout_debug_menu_screen_buffer[1400] = {0};
u32 stdout_primary_color_table[64] = {0};
u32 stdout_environment_color_table[64] = {0};

char *string_formatting[] = {0,
"\x1B[31m\x1B[40m", "\x1B[37m\x1B[40m",
"\x1B[32m\x1B[40m", "\x1B[33m\x1B[40m",
"\x1B[34m\x1B[40m", "\x1B[35m\x1B[40m",
"\x1B[36m\x1B[40m", "\x1B[37m\x1B[44m",
"\x1B[31m\x1B[44m", "\x1B[32m\x1B[44m",
"\x1B[33m\x1B[44m", "\x1B[30m\x1B[44m",
"\x1B[35m\x1B[44m", "\x1B[36m\x1B[44m",
"\x1B[37m\x1B[41m", "\x1B[30m\x1B[41m",
"\x1B[32m\x1B[41m", "\x1B[33m\x1B[41m",
"\x1B[34m\x1B[41m", "\x1B[35m\x1B[41m",
"\x1B[36m\x1B[41m", "\x1B[37m\x1B[45m",
"\x1B[31m\x1B[45m", "\x1B[32m\x1B[45m",
"\x1B[33m\x1B[45m", "\x1B[34m\x1B[45m",
"\x1B[30m\x1B[45m", "\x1B[36m\x1B[45m",
"\x1B[37m\x1B[42m", "\x1B[31m\x1B[42m",
"\x1B[30m\x1B[42m", "\x1B[33m\x1B[42m"};



u64 end_displaylist_command = 0xB800000000000000;
u64 blank_C0_command =0xC000000000000000;
u32 stdout_primary_color = 0xFA000000;
u32 debug_text_color = 0xFFFFFF00;
u32 debug_text_bg_color = 0xFB000000;
u32 speedgraph_color = 0;
u32 D_800268B8 = 0xFF;





u32 dummied_function_7000AD80(s32 arg0, s32 arg1)
{
    return 0;
}


u32 dummied_function_7000AD90(s32 arg0, s32 arg1)
{
    return 0;
}


void null_function_7000ADA0(void)
{
//empty
}


void debugmenuInit_REMOVED(void)
{
//empty
}


void debug_text_related_2(void)
{
    blank_debug_buffer_chars();
}






#ifdef NONMATCHING
s32 display_text_to_coord(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    void *temp_t5;
    void *temp_t8;
    s32 temp_t7;
    s32 temp_t5_2;
    void *temp_v1;

    // Node 0
    // Node 1
    if ((debug_text_color != stdout_primary_color_table.unk4) || (debug_text_bg_color.unk4 != (&stdout_environment_color_table + 0)->unk4))
    {
        // Node 3
        if ((0 + 1) < 0x20)
        {
            goto loop_1;
        }
        // Node 4
        temp_a0 = (string_formatting * 8);
        temp_t5 = (temp_a0 + &stdout_primary_color_table);
        *temp_t5 = (?32) stdout_primary_color;
        temp_t8 = (&stdout_environment_color_table + temp_a0);
        temp_t7 = (string_formatting + 1);
        temp_t5->unk4 = (?32) stdout_primary_color.unk4;
        *temp_t8 = (?32) debug_text_bg_color;
        temp_t8->unk4 = (s32) debug_text_bg_color.unk4;
        temp_t5_2 = (temp_t7 & 0x1f);
        if (temp_t7 < 0)
        {
            // Node 5
            if (temp_t5_2 != 0)
            {
                // Node 6
            }
        }
        // Node 7
        string_formatting = temp_t5_2;
    }
    else
    {

    }
    // Node 8
    temp_v1 = (((arg0 * 0x46) + (arg1 * 2)) + &stdout_debug_menu_screen_buffer);
    *temp_v1 = (s8) (arg2 & 0xff);
    temp_v1->unk1 = temp_t5_2;
    return;
    // (possible return value: temp_t5_2)
}

#else
GLOBAL_ASM(
.text
glabel display_text_to_coord
/* 00B9D0 7000ADD0 AFA60008 */  sw    $a2, 8($sp)
/* 00B9D4 7000ADD4 30CE00FF */  andi  $t6, $a2, 0xff
/* 00B9D8 7000ADD8 3C038002 */  lui   $v1, %hi(debug_text_color)
/* 00B9DC 7000ADDC 3C088002 */  lui   $t0, %hi(stdout_primary_color_table) 
/* 00B9E0 7000ADE0 3C0A8002 */  lui   $t2, %hi(stdout_environment_color_table) 
/* 00B9E4 7000ADE4 3C098002 */  lui   $t1, %hi(debug_text_bg_color) 
/* 00B9E8 7000ADE8 01C03025 */  move  $a2, $t6
/* 00B9EC 7000ADEC AFA40000 */  sw    $a0, ($sp)
/* 00B9F0 7000ADF0 252968B0 */  addiu $t1, %lo(debug_text_bg_color) # addiu $t1, $t1, 0x68b0
/* 00B9F4 7000ADF4 254A6710 */  addiu $t2, %lo(stdout_environment_color_table) # addiu $t2, $t2, 0x6710
/* 00B9F8 7000ADF8 25086610 */  addiu $t0, %lo(stdout_primary_color_table) # addiu $t0, $t0, 0x6610
/* 00B9FC 7000ADFC 8C6368AC */  lw    $v1, %lo(debug_text_color)($v1)
/* 00BA00 7000AE00 00001025 */  move  $v0, $zero
/* 00BA04 7000AE04 00003825 */  move  $a3, $zero
.L7000AE08:
/* 00BA08 7000AE08 8D0F0004 */  lw    $t7, 4($t0)
/* 00BA0C 7000AE0C 25080008 */  addiu $t0, $t0, 8
/* 00BA10 7000AE10 0147C821 */  addu  $t9, $t2, $a3
/* 00BA14 7000AE14 546F0006 */  bnel  $v1, $t7, .L7000AE30
/* 00BA18 7000AE18 24420001 */   addiu $v0, $v0, 1
/* 00BA1C 7000AE1C 8D380004 */  lw    $t8, 4($t1)
/* 00BA20 7000AE20 8F2B0004 */  lw    $t3, 4($t9)
/* 00BA24 7000AE24 530B0020 */  beql  $t8, $t3, .L7000AEA8
/* 00BA28 7000AE28 8FAE0000 */   lw    $t6, ($sp)
/* 00BA2C 7000AE2C 24420001 */  addiu $v0, $v0, 1
.L7000AE30:
/* 00BA30 7000AE30 28410020 */  slti  $at, $v0, 0x20
/* 00BA34 7000AE34 1420FFF4 */  bnez  $at, .L7000AE08
/* 00BA38 7000AE38 24E70008 */   addiu $a3, $a3, 8
/* 00BA3C 7000AE3C 3C078002 */  lui   $a3, %hi(string_formatting)
/* 00BA40 7000AE40 24E76810 */  addiu $a3, %lo(string_formatting) # addiu $a3, $a3, 0x6810
/* 00BA44 7000AE44 8CE30000 */  lw    $v1, ($a3)
/* 00BA48 7000AE48 3C0E8002 */  lui   $t6, %hi(stdout_primary_color) 
/* 00BA4C 7000AE4C 25CE68A8 */  addiu $t6, %lo(stdout_primary_color) # addiu $t6, $t6, 0x68a8
/* 00BA50 7000AE50 8DC10000 */  lw    $at, ($t6)
/* 00BA54 7000AE54 3C0C8002 */  lui   $t4, %hi(stdout_primary_color_table) 
/* 00BA58 7000AE58 258C6610 */  addiu $t4, %lo(stdout_primary_color_table) # addiu $t4, $t4, 0x6610
/* 00BA5C 7000AE5C 000320C0 */  sll   $a0, $v1, 3
/* 00BA60 7000AE60 008C6821 */  addu  $t5, $a0, $t4
/* 00BA64 7000AE64 ADA10000 */  sw    $at, ($t5)
/* 00BA68 7000AE68 8DD90004 */  lw    $t9, 4($t6)
/* 00BA6C 7000AE6C 0144C021 */  addu  $t8, $t2, $a0
/* 00BA70 7000AE70 246F0001 */  addiu $t7, $v1, 1
/* 00BA74 7000AE74 ADB90004 */  sw    $t9, 4($t5)
/* 00BA78 7000AE78 8D210000 */  lw    $at, ($t1)
/* 00BA7C 7000AE7C AF010000 */  sw    $at, ($t8)
/* 00BA80 7000AE80 8D2C0004 */  lw    $t4, 4($t1)
/* 00BA84 7000AE84 AF0C0004 */  sw    $t4, 4($t8)
/* 00BA88 7000AE88 05E10004 */  bgez  $t7, .L7000AE9C
/* 00BA8C 7000AE8C 31ED001F */   andi  $t5, $t7, 0x1f
/* 00BA90 7000AE90 11A00002 */  beqz  $t5, .L7000AE9C
/* 00BA94 7000AE94 00000000 */   nop   
/* 00BA98 7000AE98 25ADFFE0 */  addiu $t5, $t5, -0x20
.L7000AE9C:
/* 00BA9C 7000AE9C ACED0000 */  sw    $t5, ($a3)
/* 00BAA0 7000AEA0 01A01025 */  move  $v0, $t5
/* 00BAA4 7000AEA4 8FAE0000 */  lw    $t6, ($sp)
.L7000AEA8:
/* 00BAA8 7000AEA8 00055840 */  sll   $t3, $a1, 1
/* 00BAAC 7000AEAC 3C0C8002 */  lui   $t4, %hi(stdout_debug_menu_screen_buffer) 
/* 00BAB0 7000AEB0 000EC8C0 */  sll   $t9, $t6, 3
/* 00BAB4 7000AEB4 032EC821 */  addu  $t9, $t9, $t6
/* 00BAB8 7000AEB8 0019C880 */  sll   $t9, $t9, 2
/* 00BABC 7000AEBC 032EC823 */  subu  $t9, $t9, $t6
/* 00BAC0 7000AEC0 0019C840 */  sll   $t9, $t9, 1
/* 00BAC4 7000AEC4 032BC021 */  addu  $t8, $t9, $t3
/* 00BAC8 7000AEC8 258C5030 */  addiu $t4, %lo(stdout_debug_menu_screen_buffer) # addiu $t4, $t4, 0x5030
/* 00BACC 7000AECC 030C1821 */  addu  $v1, $t8, $t4
/* 00BAD0 7000AED0 A0660000 */  sb    $a2, ($v1)
/* 00BAD4 7000AED4 03E00008 */  jr    $ra
/* 00BAD8 7000AED8 A0620001 */   sb    $v0, 1($v1)
)
#endif




void debugMenuSetTextPOStoOffset(void)
{
    debug_menu_x_text_pos = debug_menu_x_pos_offset;
    debug_menu_y_text_pos = debug_menu_y_pos_offset;
}




void blank_debug_buffer_chars(void)
{
  int x;
  int y;
  
  for (y = 0; y < 0x23; y++)
  {
    for (x = 0; x < 0x50; x++)
    {
      display_text_to_coord(x,y,'\0');
    }
  }
  debugMenuSetTextPOStoOffset();
  null_function_7000ADA0();
  string_formatting[0] = NULL;
}




void stubbed_function_7000AF84(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    return;
}






#ifdef NONMATCHING
void something_debug_info_related(s32 arg0)
{
    s32 temp_s0;
    s32 temp_s0_2;
    s32 phi_s3;
    s32 phi_s0;
    s32 phi_s1;
    s32 phi_s0_2;

    phi_s3 = arg0 + 0x21;
    phi_s1 = 0x21;
loop_1:
    if ((phi_s3 >= 0) && (phi_s3 < 0x23))
    {
loop_3:
        stubbed_function_7000AF84(phi_s0, phi_s3, phi_s0, phi_s1);
        temp_s0 = phi_s0 + 1;
        phi_s0 = temp_s0;
        if (temp_s0 != 0x50)
        {
            goto loop_3;
        }
    }
    else
    {
        phi_s0_2 = 0;
loop_6:
        display_text_to_coord(phi_s0_2, phi_s1, 0);
        temp_s0_2 = phi_s0_2 + 1;
        phi_s0_2 = temp_s0_2;
        if (temp_s0_2 != 0x50)
        {
            goto loop_6;
        }
    }
    phi_s3 = phi_s3 - 1;
    phi_s1 = phi_s1 - 1;
    if (phi_s1 != 0)
    {
        goto loop_1;
    }
}
#else
GLOBAL_ASM(
.text
glabel something_debug_info_related
/* 00BB98 7000AF98 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00BB9C 7000AF9C AFB30020 */  sw    $s3, 0x20($sp)
/* 00BBA0 7000AFA0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00BBA4 7000AFA4 AFB10018 */  sw    $s1, 0x18($sp)
/* 00BBA8 7000AFA8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00BBAC 7000AFAC AFB00014 */  sw    $s0, 0x14($sp)
/* 00BBB0 7000AFB0 24110021 */  li    $s1, 33
/* 00BBB4 7000AFB4 24120050 */  li    $s2, 80
/* 00BBB8 7000AFB8 24930021 */  addiu $s3, $a0, 0x21
.L7000AFBC:
/* 00BBBC 7000AFBC 0660000D */  bltz  $s3, .L7000AFF4
/* 00BBC0 7000AFC0 2A610023 */   slti  $at, $s3, 0x23
/* 00BBC4 7000AFC4 1020000B */  beqz  $at, .L7000AFF4
/* 00BBC8 7000AFC8 00008025 */   move  $s0, $zero
/* 00BBCC 7000AFCC 02002025 */  move  $a0, $s0
.L7000AFD0:
/* 00BBD0 7000AFD0 02602825 */  move  $a1, $s3
/* 00BBD4 7000AFD4 02003025 */  move  $a2, $s0
/* 00BBD8 7000AFD8 0C002BE1 */  jal   stubbed_function_7000AF84
/* 00BBDC 7000AFDC 02203825 */   move  $a3, $s1
/* 00BBE0 7000AFE0 26100001 */  addiu $s0, $s0, 1
/* 00BBE4 7000AFE4 5612FFFA */  bnel  $s0, $s2, .L7000AFD0
/* 00BBE8 7000AFE8 02002025 */   move  $a0, $s0
/* 00BBEC 7000AFEC 1000000A */  b     .L7000B018
/* 00BBF0 7000AFF0 02201025 */   move  $v0, $s1
.L7000AFF4:
/* 00BBF4 7000AFF4 00008025 */  move  $s0, $zero
/* 00BBF8 7000AFF8 02002025 */  move  $a0, $s0
.L7000AFFC:
/* 00BBFC 7000AFFC 02202825 */  move  $a1, $s1
/* 00BC00 7000B000 0C002B74 */  jal   display_text_to_coord
/* 00BC04 7000B004 00003025 */   move  $a2, $zero
/* 00BC08 7000B008 26100001 */  addiu $s0, $s0, 1
/* 00BC0C 7000B00C 5612FFFB */  bnel  $s0, $s2, .L7000AFFC
/* 00BC10 7000B010 02002025 */   move  $a0, $s0
/* 00BC14 7000B014 02201025 */  move  $v0, $s1
.L7000B018:
/* 00BC18 7000B018 2673FFFF */  addiu $s3, $s3, -1
/* 00BC1C 7000B01C 1620FFE7 */  bnez  $s1, .L7000AFBC
/* 00BC20 7000B020 2631FFFF */   addiu $s1, $s1, -1
/* 00BC24 7000B024 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00BC28 7000B028 8FB00014 */  lw    $s0, 0x14($sp)
/* 00BC2C 7000B02C 8FB10018 */  lw    $s1, 0x18($sp)
/* 00BC30 7000B030 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00BC34 7000B034 8FB30020 */  lw    $s3, 0x20($sp)
/* 00BC38 7000B038 03E00008 */  jr    $ra
/* 00BC3C 7000B03C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
void set_final_debug_text_positions(s32 xadjust,s32 yadjust)
{
  debug_menu_x_text_pos = xadjust + debug_menu_x_pos_offset;
  debug_menu_y_text_pos = yadjust + debug_menu_y_pos_offset;
}
#else
GLOBAL_ASM(
.text
glabel set_final_debug_text_positions
/* 00BC40 7000B040 3C0E8002 */  lui   $t6, %hi(debug_menu_x_pos_offset) 
/* 00BC44 7000B044 8DCE4FA0 */  lw    $t6, %lo(debug_menu_x_pos_offset)($t6)
/* 00BC48 7000B048 3C0F8002 */  lui   $t7, %hi(debug_menu_y_pos_offset) 
/* 00BC4C 7000B04C 8DEF4FA4 */  lw    $t7, %lo(debug_menu_y_pos_offset)($t7)
/* 00BC50 7000B050 3C018002 */  lui   $at, %hi(debug_menu_x_text_pos)
/* 00BC54 7000B054 008E2021 */  addu  $a0, $a0, $t6
/* 00BC58 7000B058 AC244FA8 */  sw    $a0, %lo(debug_menu_x_text_pos)($at)
/* 00BC5C 7000B05C 3C018002 */  lui   $at, %hi(debug_menu_y_text_pos)
/* 00BC60 7000B060 00AF2821 */  addu  $a1, $a1, $t7
/* 00BC64 7000B064 03E00008 */  jr    $ra
/* 00BC68 7000B068 AC254FAC */   sw    $a1, %lo(debug_menu_y_text_pos)($at)
)
#endif






void set_debug_text_color(s32 red,s32 blue,s32 green,s32 alpha)
{
  debug_text_color = red << 0x18 | blue << 0x10 | green << 8 | 0xffU - alpha;
}


void set_color_speedgraph(s32 red,s32 green,s32 blue,s32 alpha)
{
  speedgraph_color = red << 0x18 | green << 0x10 | blue << 8 | 0xffU - alpha;
}





#ifdef NONMATCHING
void write_char_to_screen(u8 character)

{
  short txtClipW;
  short txtClipH;
  int start_pos;
  
  txtClipW = get_video2_settings_txtClipW();
  start_pos = (int)txtClipW + -0xd;
  if (start_pos < 0) {
    start_pos = (int)txtClipW + -10;
  }
  txtClipH = get_video2_settings_txtClipH();
  if ((character == 0) || ((0x1f < character && (character < 0x7f)))) {
    display_text_to_coord(debug_menu_x_text_pos,debug_menu_y_text_pos,character);
  }
  debug_menu_x_text_pos += 1;
  if (((character == 0xd) || (character == 10)) || (start_pos >> 2 <= debug_menu_x_text_pos)) {
    debug_menu_y_text_pos += 1;
    debug_menu_x_text_pos = debug_menu_x_pos_offset;
    if (((int)txtClipH + -10) / 7 <= debug_menu_y_text_pos) {
      debug_menu_y_text_pos = debug_menu_y_pos_offset;
    }
  }
}
#else
GLOBAL_ASM(
.text
glabel write_char_to_screen
/* 00BCC4 7000B0C4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00BCC8 7000B0C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00BCCC 7000B0CC 0C001107 */  jal   get_video2_settings_txtClipW
/* 00BCD0 7000B0D0 AFA40028 */   sw    $a0, 0x28($sp)
/* 00BCD4 7000B0D4 244EFFF3 */  addiu $t6, $v0, -0xd
/* 00BCD8 7000B0D8 05C10003 */  bgez  $t6, .L7000B0E8
/* 00BCDC 7000B0DC 000E7883 */   sra   $t7, $t6, 2
/* 00BCE0 7000B0E0 25C10003 */  addiu $at, $t6, 3
/* 00BCE4 7000B0E4 00017883 */  sra   $t7, $at, 2
.L7000B0E8:
/* 00BCE8 7000B0E8 0C00110B */  jal   get_video2_settings_txtClipH
/* 00BCEC 7000B0EC AFAF0024 */   sw    $t7, 0x24($sp)
/* 00BCF0 7000B0F0 2448FFF6 */  addiu $t0, $v0, -0xa
/* 00BCF4 7000B0F4 24010007 */  li    $at, 7
/* 00BCF8 7000B0F8 0101001A */  div   $zero, $t0, $at
/* 00BCFC 7000B0FC 93A6002B */  lbu   $a2, 0x2b($sp)
/* 00BD00 7000B100 00004012 */  mflo  $t0
/* 00BD04 7000B104 3C028002 */  lui   $v0, %hi(debug_menu_x_text_pos)
/* 00BD08 7000B108 10C00005 */  beqz  $a2, .L7000B120
/* 00BD0C 7000B10C 00C01825 */   move  $v1, $a2
/* 00BD10 7000B110 28610020 */  slti  $at, $v1, 0x20
/* 00BD14 7000B114 1420000C */  bnez  $at, .L7000B148
/* 00BD18 7000B118 2861007F */   slti  $at, $v1, 0x7f
/* 00BD1C 7000B11C 1020000A */  beqz  $at, .L7000B148
.L7000B120:
/* 00BD20 7000B120 3C078002 */   lui   $a3, %hi(debug_menu_y_text_pos)
/* 00BD24 7000B124 24E74FAC */  addiu $a3, %lo(debug_menu_y_text_pos) # addiu $a3, $a3, 0x4fac
/* 00BD28 7000B128 24424FA8 */  addiu $v0, %lo(debug_menu_x_text_pos) # addiu $v0, $v0, 0x4fa8
/* 00BD2C 7000B12C 8C440000 */  lw    $a0, ($v0)
/* 00BD30 7000B130 8CE50000 */  lw    $a1, ($a3)
/* 00BD34 7000B134 AFA3001C */  sw    $v1, 0x1c($sp)
/* 00BD38 7000B138 0C002B74 */  jal   display_text_to_coord
/* 00BD3C 7000B13C AFA80020 */   sw    $t0, 0x20($sp)
/* 00BD40 7000B140 8FA3001C */  lw    $v1, 0x1c($sp)
/* 00BD44 7000B144 8FA80020 */  lw    $t0, 0x20($sp)
.L7000B148:
/* 00BD48 7000B148 3C028002 */  lui   $v0, %hi(debug_menu_x_text_pos)
/* 00BD4C 7000B14C 24424FA8 */  addiu $v0, %lo(debug_menu_x_text_pos) # addiu $v0, $v0, 0x4fa8
/* 00BD50 7000B150 8C590000 */  lw    $t9, ($v0)
/* 00BD54 7000B154 3C078002 */  lui   $a3, %hi(debug_menu_y_text_pos)
/* 00BD58 7000B158 2401000D */  li    $at, 13
/* 00BD5C 7000B15C 27290001 */  addiu $t1, $t9, 1
/* 00BD60 7000B160 24E74FAC */  addiu $a3, %lo(debug_menu_y_text_pos) # addiu $a3, $a3, 0x4fac
/* 00BD64 7000B164 10610007 */  beq   $v1, $at, .L7000B184
/* 00BD68 7000B168 AC490000 */   sw    $t1, ($v0)
/* 00BD6C 7000B16C 2401000A */  li    $at, 10
/* 00BD70 7000B170 10610004 */  beq   $v1, $at, .L7000B184
/* 00BD74 7000B174 8FAB0024 */   lw    $t3, 0x24($sp)
/* 00BD78 7000B178 012B082A */  slt   $at, $t1, $t3
/* 00BD7C 7000B17C 5420000D */  bnezl $at, .L7000B1B4
/* 00BD80 7000B180 8FBF0014 */   lw    $ra, 0x14($sp)
.L7000B184:
/* 00BD84 7000B184 8CED0000 */  lw    $t5, ($a3)
/* 00BD88 7000B188 3C0C8002 */  lui   $t4, %hi(debug_menu_x_pos_offset) 
/* 00BD8C 7000B18C 8D8C4FA0 */  lw    $t4, %lo(debug_menu_x_pos_offset)($t4)
/* 00BD90 7000B190 25AE0001 */  addiu $t6, $t5, 1
/* 00BD94 7000B194 01C8082A */  slt   $at, $t6, $t0
/* 00BD98 7000B198 ACEE0000 */  sw    $t6, ($a3)
/* 00BD9C 7000B19C 14200004 */  bnez  $at, .L7000B1B0
/* 00BDA0 7000B1A0 AC4C0000 */   sw    $t4, ($v0)
/* 00BDA4 7000B1A4 3C188002 */  lui   $t8, %hi(debug_menu_y_pos_offset) 
/* 00BDA8 7000B1A8 8F184FA4 */  lw    $t8, %lo(debug_menu_y_pos_offset)($t8)
/* 00BDAC 7000B1AC ACF80000 */  sw    $t8, ($a3)
.L7000B1B0:
/* 00BDB0 7000B1B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000B1B4:
/* 00BDB4 7000B1B4 27BD0028 */  addiu $sp, $sp, 0x28
/* 00BDB8 7000B1B8 03E00008 */  jr    $ra
/* 00BDBC 7000B1BC 00000000 */   nop   
)
#endif




void debug_printcharatpos(int x,int y, u8 character)
{
  set_final_debug_text_positions(x,y);
  write_char_to_screen(character);
}



#ifdef NONMATCHING
void write_string_stdout(void *arg0)
{
    void *temp_s1;
    s32 phi_s0;
    void *phi_s1;

    phi_s0 = *arg0;
    phi_s1 = arg0;
    if (*arg0 != 0)
    {
loop_1:
        temp_s1 = phi_s1 + 1;
        write_char_to_screen(phi_s0 & 0xff);
        phi_s0 = *temp_s1;
        phi_s1 = temp_s1;
        if (*temp_s1 != 0)
        {
            goto loop_1;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel write_string_stdout
/* 00BDE8 7000B1E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00BDEC 7000B1EC AFBF001C */  sw    $ra, 0x1c($sp)
/* 00BDF0 7000B1F0 AFB10018 */  sw    $s1, 0x18($sp)
/* 00BDF4 7000B1F4 AFB00014 */  sw    $s0, 0x14($sp)
/* 00BDF8 7000B1F8 90900000 */  lbu   $s0, ($a0)
/* 00BDFC 7000B1FC 00808825 */  move  $s1, $a0
/* 00BE00 7000B200 12000006 */  beqz  $s0, .L7000B21C
/* 00BE04 7000B204 320400FF */   andi  $a0, $s0, 0xff
.L7000B208:
/* 00BE08 7000B208 0C002C31 */  jal   write_char_to_screen
/* 00BE0C 7000B20C 26310001 */   addiu $s1, $s1, 1
/* 00BE10 7000B210 92300000 */  lbu   $s0, ($s1)
/* 00BE14 7000B214 5600FFFC */  bnezl $s0, .L7000B208
/* 00BE18 7000B218 320400FF */   andi  $a0, $s0, 0xff
.L7000B21C:
/* 00BE1C 7000B21C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00BE20 7000B220 8FB00014 */  lw    $s0, 0x14($sp)
/* 00BE24 7000B224 8FB10018 */  lw    $s1, 0x18($sp)
/* 00BE28 7000B228 03E00008 */  jr    $ra
/* 00BE2C 7000B22C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



#ifdef NONMATCHING
void debug_text_related(void *arg2)
{
    void *temp_s1;
    s32 phi_s0;
    void *phi_s1;

    set_final_debug_text_positions();
    phi_s0 = *arg2;
    phi_s1 = arg2;
    if (*arg2 != 0)
    {
loop_1:
        temp_s1 = phi_s1 + 1;
        write_char_to_screen(phi_s0 & 0xff);
        phi_s0 = *temp_s1;
        phi_s1 = temp_s1;
        if (*temp_s1 != 0)
        {
            goto loop_1;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel debug_text_related
/* 00BE30 7000B230 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00BE34 7000B234 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00BE38 7000B238 AFB10018 */  sw    $s1, 0x18($sp)
/* 00BE3C 7000B23C 00C08825 */  move  $s1, $a2
/* 00BE40 7000B240 0C002C10 */  jal   set_final_debug_text_positions
/* 00BE44 7000B244 AFB00014 */   sw    $s0, 0x14($sp)
/* 00BE48 7000B248 92300000 */  lbu   $s0, ($s1)
/* 00BE4C 7000B24C 12000006 */  beqz  $s0, .L7000B268
/* 00BE50 7000B250 320400FF */   andi  $a0, $s0, 0xff
.L7000B254:
/* 00BE54 7000B254 0C002C31 */  jal   write_char_to_screen
/* 00BE58 7000B258 26310001 */   addiu $s1, $s1, 1
/* 00BE5C 7000B25C 92300000 */  lbu   $s0, ($s1)
/* 00BE60 7000B260 5600FFFC */  bnezl $s0, .L7000B254
/* 00BE64 7000B264 320400FF */   andi  $a0, $s0, 0xff
.L7000B268:
/* 00BE68 7000B268 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00BE6C 7000B26C 8FB00014 */  lw    $s0, 0x14($sp)
/* 00BE70 7000B270 8FB10018 */  lw    $s1, 0x18($sp)
/* 00BE74 7000B274 03E00008 */  jr    $ra
/* 00BE78 7000B278 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



#ifdef NONMATCHING
void *read_screen_display_block_and_write_chars(void *arg0)
{
    s32 sp40;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_t5;
    void *temp_t8;
    void *temp_v0_2;
    void *phi_a0;
    s32 phi_a2;
    s32 phi_a1;
    s32 phi_t0;
    s32 phi_a2_2;
    void *phi_s1;
    void *phi_s2;
    s32 phi_s4;
    void *phi_s0;
    void *phi_s0_2;
    s32 phi_s1_2;
    s32 phi_s5;
    void *phi_s0_3;
    void *phi_s1_3;
    void *phi_s1_4;
    s32 phi_s4_2;
    s32 phi_s4_3;

    phi_t0 = 0;
    phi_a2 = -1;
    phi_s1_4 = arg0;
loop_1:
    temp_a1 = 0x80020000 + 0x5030;
    phi_a0 = phi_t0 + temp_a1;
    phi_a1 = temp_a1;
loop_2:
    temp_a1_2 = phi_a1 + 0x46;
    temp_v1 = phi_a0->unk1;
    phi_a2_2 = phi_a2;
    phi_s1 = phi_s1_4;
    if (phi_a0->unk0 != 0)
    {
        phi_a2_2 = phi_a2;
        phi_s1_3 = phi_s1_4;
        if (temp_v1 != phi_a2)
        {
            phi_a2_2 = temp_v1;
            phi_s1_3 = phi_s1_4 + 0x10;
        }
        phi_s1 = phi_s1_3 + 0x18;
    }
    phi_a0 = phi_a0 + 0x46;
    phi_a2 = phi_a2_2;
    phi_a1 = temp_a1_2;
    phi_s1_4 = phi_s1;
    if (temp_a1_2 != &stdout_primary_color_table)
    {
        goto loop_2;
    }
    temp_t0 = phi_t0 + 2;
    phi_t0 = temp_t0;
    phi_a2 = phi_a2_2;
    phi_s1_4 = phi_s1;
    if (temp_t0 < 0x46)
    {
        goto loop_1;
    }
    temp_a0 = phi_s1 - arg0;
    temp_v1_2 = num_microcode_cmds_that_fit(arg0, temp_a1_2, phi_a2_2, &stdout_primary_color_table) + -0x800;
    if (temp_a0 <= 0)
    {
        return arg0;
    }
    if (temp_v1_2 <= 0)
    {
        D_800268B8 = 0;
block_15:
    }
    else
    {
        if (temp_v1_2 < temp_a0)
        {
            D_800268B8 = (s32) ((s32) (temp_v1_2 * 0xff) / temp_a0);
        }
        else
        {
            D_800268B8 = 0x100;
            goto block_15;
        }
    }
    arg0->unk0 = 0x6000000;
    arg0->unk4 = &stdout_display_list;
    sp40 = 0;
    phi_s5 = 0;
    phi_s4 = -1;
    phi_s0 = arg0 + 8;
loop_17:
    phi_s2 = sp40 + &stdout_debug_menu_screen_buffer;
    phi_s1_2 = 0;
loop_18:
    temp_s3 = phi_s2->unk0;
    temp_v1_3 = phi_s2->unk1;
    phi_s0_3 = phi_s0;
    phi_s4_2 = phi_s4;
    if (temp_s3 != 0)
    {
        temp_v0 = temp_v1_3 * 8;
        phi_s0_2 = phi_s0;
        phi_s4_3 = phi_s4;
        if (temp_v1_3 != phi_s4)
        {
            temp_t5 = &stdout_primary_color_table + temp_v0;
            temp_t8 = &stdout_environment_color_table + temp_v0;
            temp_s0 = phi_s0 + 0x10;
            temp_s0->unk-10 = (?32) temp_t5->unk0;
            temp_s0->unk-C = (?32) temp_t5->unk4;
            temp_s0->unk-8 = (?32) temp_t8->unk0;
            temp_s0->unk-4 = (?32) temp_t8->unk4;
            phi_s0_2 = temp_s0;
            phi_s4_3 = temp_v1_3;
        }
        phi_s0_3 = phi_s0_2;
        phi_s4_2 = phi_s4_3;
        if ((u32) (get_random_value() & 0xff) < (u32) D_800268B8)
        {
            temp_v0_2 = phi_s0_2;
            phi_s0_3 = phi_s0_2;
            phi_s4_2 = phi_s4_3;
            if (num_microcode_cmds_that_fit(phi_s0_2) >= 0x400)
            {
                temp_v1_4 = phi_s1_2 * 0x10;
                temp_a0_2 = ((phi_s5 * 8) - phi_s5) * 4;
                temp_a2 = temp_s3 + -0x20;
                temp_s0_2 = phi_s0_2 + 8;
                temp_a1_3 = temp_s0_2;
                temp_v0_2->unk0 = (s32) (((((temp_v1_4 + 0x10) & 0xfff) << 0xc) | 0xe4000000) | ((temp_a0_2 + 0x1c) & 0xfff));
                temp_v0_2->unk4 = (s32) (((temp_v1_4 & 0xfff) << 0xc) | (temp_a0_2 & 0xfff));
                temp_s0_2 = temp_s0_2 + 8;
                temp_a1_3->unk0 = 0xb4000000;
                temp_a1_3->unk4 = (s32) (((temp_a2 & 0x1f) << 0x17) | (((temp_a2 >> 5) * 0xe0) & 0xffff));
                temp_s0_2->unk0 = 0xb3000000;
                temp_s0_2->unk4 = 0x4000400;
                phi_s0_3 = temp_s0_2 + 8;
                phi_s4_2 = phi_s4_3;
            }
        }
    }
    temp_s1 = phi_s1_2 + 1;
    phi_s2 = phi_s2 + 0x46;
    phi_s4 = phi_s4_2;
    phi_s0 = phi_s0_3;
    phi_s1_2 = temp_s1;
    if (temp_s1 != 0x50)
    {
        goto loop_18;
    }
    temp_s5 = phi_s5 + 1;
    sp40 = (s32) (sp40 + 2);
    phi_s5 = temp_s5;
    phi_s4 = phi_s4_2;
    phi_s0 = phi_s0_3;
    if (temp_s5 != 0x23)
    {
        goto loop_17;
    }
    return phi_s0_3;
}
#else
GLOBAL_ASM(
.text
glabel read_screen_display_block_and_write_chars
/* 00BE7C 7000B27C 27BDFF78 */  addiu $sp, $sp, -0x88
/* 00BE80 7000B280 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00BE84 7000B284 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00BE88 7000B288 AFB00018 */  sw    $s0, 0x18($sp)
/* 00BE8C 7000B28C 3C078002 */  lui   $a3, %hi(stdout_primary_color_table)
/* 00BE90 7000B290 00808025 */  move  $s0, $a0
/* 00BE94 7000B294 AFBF003C */  sw    $ra, 0x3c($sp)
/* 00BE98 7000B298 AFBE0038 */  sw    $fp, 0x38($sp)
/* 00BE9C 7000B29C AFB70034 */  sw    $s7, 0x34($sp)
/* 00BEA0 7000B2A0 AFB60030 */  sw    $s6, 0x30($sp)
/* 00BEA4 7000B2A4 AFB40028 */  sw    $s4, 0x28($sp)
/* 00BEA8 7000B2A8 AFB30024 */  sw    $s3, 0x24($sp)
/* 00BEAC 7000B2AC AFB20020 */  sw    $s2, 0x20($sp)
/* 00BEB0 7000B2B0 00808825 */  move  $s1, $a0
/* 00BEB4 7000B2B4 2406FFFF */  li    $a2, -1
/* 00BEB8 7000B2B8 24E76610 */  addiu $a3, %lo(stdout_primary_color_table) # addiu $a3, $a3, 0x6610
/* 00BEBC 7000B2BC 0000A825 */  move  $s5, $zero
/* 00BEC0 7000B2C0 00004025 */  move  $t0, $zero
.L7000B2C4:
/* 00BEC4 7000B2C4 3C0E8002 */  lui   $t6, %hi(stdout_debug_menu_screen_buffer)
/* 00BEC8 7000B2C8 25C55030 */  addiu $a1, $t6, %lo(stdout_debug_menu_screen_buffer)
/* 00BECC 7000B2CC 01052021 */  addu  $a0, $t0, $a1
.L7000B2D0:
/* 00BED0 7000B2D0 90820000 */  lbu   $v0, ($a0)
/* 00BED4 7000B2D4 24A50046 */  addiu $a1, $a1, 0x46
/* 00BED8 7000B2D8 90830001 */  lbu   $v1, 1($a0)
/* 00BEDC 7000B2DC 10400006 */  beqz  $v0, .L7000B2F8
/* 00BEE0 7000B2E0 00000000 */   nop   
/* 00BEE4 7000B2E4 50660004 */  beql  $v1, $a2, .L7000B2F8
/* 00BEE8 7000B2E8 26310018 */   addiu $s1, $s1, 0x18
/* 00BEEC 7000B2EC 26310010 */  addiu $s1, $s1, 0x10
/* 00BEF0 7000B2F0 00603025 */  move  $a2, $v1
/* 00BEF4 7000B2F4 26310018 */  addiu $s1, $s1, 0x18
.L7000B2F8:
/* 00BEF8 7000B2F8 14A7FFF5 */  bne   $a1, $a3, .L7000B2D0
/* 00BEFC 7000B2FC 24840046 */   addiu $a0, $a0, 0x46
/* 00BF00 7000B300 25080002 */  addiu $t0, $t0, 2
/* 00BF04 7000B304 29010046 */  slti  $at, $t0, 0x46
/* 00BF08 7000B308 1420FFEE */  bnez  $at, .L7000B2C4
/* 00BF0C 7000B30C 00000000 */   nop   
/* 00BF10 7000B310 0FC2F5DF */  jal   num_microcode_cmds_that_fit
/* 00BF14 7000B314 02002025 */   move  $a0, $s0
/* 00BF18 7000B318 02302023 */  subu  $a0, $s1, $s0
/* 00BF1C 7000B31C 1C800003 */  bgtz  $a0, .L7000B32C
/* 00BF20 7000B320 2443F800 */   addiu $v1, $v0, -0x800
/* 00BF24 7000B324 10000080 */  b     .L7000B528
/* 00BF28 7000B328 02001025 */   move  $v0, $s0
.L7000B32C:
/* 00BF2C 7000B32C 1C600004 */  bgtz  $v1, .L7000B340
/* 00BF30 7000B330 2414FFFF */   li    $s4, -1
/* 00BF34 7000B334 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF38 7000B338 10000017 */  b     .L7000B398
/* 00BF3C 7000B33C AC2068B8 */   sw    $zero, %lo(D_800268B8)($at)
.L7000B340:
/* 00BF40 7000B340 0064082A */  slt   $at, $v1, $a0
/* 00BF44 7000B344 10200011 */  beqz  $at, .L7000B38C
/* 00BF48 7000B348 00037A00 */   sll   $t7, $v1, 8
/* 00BF4C 7000B34C 01E37823 */  subu  $t7, $t7, $v1
/* 00BF50 7000B350 01E4001A */  div   $zero, $t7, $a0
/* 00BF54 7000B354 14800002 */  bnez  $a0, .L7000B360
/* 00BF58 7000B358 00000000 */   nop   
/* 00BF5C 7000B35C 0007000D */  break 7
.L7000B360:
/* 00BF60 7000B360 2401FFFF */  li    $at, -1
/* 00BF64 7000B364 14810004 */  bne   $a0, $at, .L7000B378
/* 00BF68 7000B368 3C018000 */   lui   $at, 0x8000
/* 00BF6C 7000B36C 15E10002 */  bne   $t7, $at, .L7000B378
/* 00BF70 7000B370 00000000 */   nop   
/* 00BF74 7000B374 0006000D */  break 6
.L7000B378:
/* 00BF78 7000B378 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF7C 7000B37C 0000C012 */  mflo  $t8
/* 00BF80 7000B380 AC3868B8 */  sw    $t8, %lo(D_800268B8)($at)
/* 00BF84 7000B384 10000005 */  b     .L7000B39C
/* 00BF88 7000B388 02001025 */   move  $v0, $s0
.L7000B38C:
/* 00BF8C 7000B38C 24190100 */  li    $t9, 256
/* 00BF90 7000B390 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF94 7000B394 AC3968B8 */  sw    $t9, %lo(D_800268B8)($at)
.L7000B398:
/* 00BF98 7000B398 02001025 */  move  $v0, $s0
.L7000B39C:
/* 00BF9C 7000B39C 3C0A8002 */  lui   $t2, %hi(stdout_display_list) 
/* 00BFA0 7000B3A0 254A4FB0 */  addiu $t2, %lo(stdout_display_list) # addiu $t2, $t2, 0x4fb0
/* 00BFA4 7000B3A4 3C090600 */  lui   $t1, 0x600
/* 00BFA8 7000B3A8 AC490000 */  sw    $t1, ($v0)
/* 00BFAC 7000B3AC AC4A0004 */  sw    $t2, 4($v0)
/* 00BFB0 7000B3B0 3C1E8002 */  lui   $fp, %hi(stdout_environment_color_table) 
/* 00BFB4 7000B3B4 3C178002 */  lui   $s7, %hi(stdout_primary_color_table) 
/* 00BFB8 7000B3B8 26100008 */  addiu $s0, $s0, 8
/* 00BFBC 7000B3BC 26F76610 */  addiu $s7, %lo(stdout_primary_color_table) # addiu $s7, $s7, 0x6610
/* 00BFC0 7000B3C0 27DE6710 */  addiu $fp, %lo(stdout_environment_color_table) # addiu $fp, $fp, 0x6710
/* 00BFC4 7000B3C4 AFA00040 */  sw    $zero, 0x40($sp)
/* 00BFC8 7000B3C8 0000A825 */  move  $s5, $zero
/* 00BFCC 7000B3CC 24160050 */  li    $s6, 80
.L7000B3D0:
/* 00BFD0 7000B3D0 8FAB0040 */  lw    $t3, 0x40($sp)
/* 00BFD4 7000B3D4 3C0C8002 */  lui   $t4, %hi(stdout_debug_menu_screen_buffer) 
/* 00BFD8 7000B3D8 258C5030 */  addiu $t4, %lo(stdout_debug_menu_screen_buffer) # addiu $t4, $t4, 0x5030
/* 00BFDC 7000B3DC 00008825 */  move  $s1, $zero
/* 00BFE0 7000B3E0 016C9021 */  addu  $s2, $t3, $t4
.L7000B3E4:
/* 00BFE4 7000B3E4 92530000 */  lbu   $s3, ($s2)
/* 00BFE8 7000B3E8 92430001 */  lbu   $v1, 1($s2)
/* 00BFEC 7000B3EC 52600045 */  beql  $s3, $zero, .L7000B504
/* 00BFF0 7000B3F0 26310001 */   addiu $s1, $s1, 1
/* 00BFF4 7000B3F4 1074000D */  beq   $v1, $s4, .L7000B42C
/* 00BFF8 7000B3F8 000310C0 */   sll   $v0, $v1, 3
/* 00BFFC 7000B3FC 02E26821 */  addu  $t5, $s7, $v0
/* 00C000 7000B400 8DA10000 */  lw    $at, ($t5)
/* 00C004 7000B404 03C2C021 */  addu  $t8, $fp, $v0
/* 00C008 7000B408 26100010 */  addiu $s0, $s0, 0x10
/* 00C00C 7000B40C AE01FFF0 */  sw    $at, -0x10($s0)
/* 00C010 7000B410 8DAF0004 */  lw    $t7, 4($t5)
/* 00C014 7000B414 0060A025 */  move  $s4, $v1
/* 00C018 7000B418 AE0FFFF4 */  sw    $t7, -0xc($s0)
/* 00C01C 7000B41C 8F010000 */  lw    $at, ($t8)
/* 00C020 7000B420 AE01FFF8 */  sw    $at, -8($s0)
/* 00C024 7000B424 8F090004 */  lw    $t1, 4($t8)
/* 00C028 7000B428 AE09FFFC */  sw    $t1, -4($s0)
.L7000B42C:
/* 00C02C 7000B42C 0C002914 */  jal   get_random_value
/* 00C030 7000B430 00000000 */   nop   
/* 00C034 7000B434 3C0B8002 */  lui   $t3, %hi(D_800268B8) 
/* 00C038 7000B438 8D6B68B8 */  lw    $t3, %lo(D_800268B8)($t3)
/* 00C03C 7000B43C 304A00FF */  andi  $t2, $v0, 0xff
/* 00C040 7000B440 014B082B */  sltu  $at, $t2, $t3
/* 00C044 7000B444 5020002F */  beql  $at, $zero, .L7000B504
/* 00C048 7000B448 26310001 */   addiu $s1, $s1, 1
/* 00C04C 7000B44C 0FC2F5DF */  jal   num_microcode_cmds_that_fit
/* 00C050 7000B450 02002025 */   move  $a0, $s0
/* 00C054 7000B454 28410400 */  slti  $at, $v0, 0x400
/* 00C058 7000B458 14200029 */  bnez  $at, .L7000B500
/* 00C05C 7000B45C 02001025 */   move  $v0, $s0
/* 00C060 7000B460 00111900 */  sll   $v1, $s1, 4
/* 00C064 7000B464 001520C0 */  sll   $a0, $s5, 3
/* 00C068 7000B468 00952023 */  subu  $a0, $a0, $s5
/* 00C06C 7000B46C 246C0010 */  addiu $t4, $v1, 0x10
/* 00C070 7000B470 318E0FFF */  andi  $t6, $t4, 0xfff
/* 00C074 7000B474 00042080 */  sll   $a0, $a0, 2
/* 00C078 7000B478 306A0FFF */  andi  $t2, $v1, 0xfff
/* 00C07C 7000B47C 000A5B00 */  sll   $t3, $t2, 0xc
/* 00C080 7000B480 000E6B00 */  sll   $t5, $t6, 0xc
/* 00C084 7000B484 2499001C */  addiu $t9, $a0, 0x1c
/* 00C088 7000B488 308C0FFF */  andi  $t4, $a0, 0xfff
/* 00C08C 7000B48C 3C01E400 */  lui   $at, 0xe400
/* 00C090 7000B490 2666FFE0 */  addiu $a2, $s3, -0x20
/* 00C094 7000B494 00065143 */  sra   $t2, $a2, 5
/* 00C098 7000B498 01A17825 */  or    $t7, $t5, $at
/* 00C09C 7000B49C 016C7025 */  or    $t6, $t3, $t4
/* 00C0A0 7000B4A0 33380FFF */  andi  $t8, $t9, 0xfff
/* 00C0A4 7000B4A4 01F84825 */  or    $t1, $t7, $t8
/* 00C0A8 7000B4A8 000A58C0 */  sll   $t3, $t2, 3
/* 00C0AC 7000B4AC 016A5823 */  subu  $t3, $t3, $t2
/* 00C0B0 7000B4B0 26100008 */  addiu $s0, $s0, 8
/* 00C0B4 7000B4B4 02002825 */  move  $a1, $s0
/* 00C0B8 7000B4B8 000B5940 */  sll   $t3, $t3, 5
/* 00C0BC 7000B4BC AC490000 */  sw    $t1, ($v0)
/* 00C0C0 7000B4C0 30D8001F */  andi  $t8, $a2, 0x1f
/* 00C0C4 7000B4C4 AC4E0004 */  sw    $t6, 4($v0)
/* 00C0C8 7000B4C8 00184DC0 */  sll   $t1, $t8, 0x17
/* 00C0CC 7000B4CC 316CFFFF */  andi  $t4, $t3, 0xffff
/* 00C0D0 7000B4D0 26100008 */  addiu $s0, $s0, 8
/* 00C0D4 7000B4D4 3C0DB400 */  lui   $t5, 0xb400
/* 00C0D8 7000B4D8 ACAD0000 */  sw    $t5, ($a1)
/* 00C0DC 7000B4DC 02003825 */  move  $a3, $s0
/* 00C0E0 7000B4E0 012C7025 */  or    $t6, $t1, $t4
/* 00C0E4 7000B4E4 ACAE0004 */  sw    $t6, 4($a1)
/* 00C0E8 7000B4E8 3C190400 */  lui   $t9, (0x04000400 >> 16) # lui $t9, 0x400
/* 00C0EC 7000B4EC 37390400 */  ori   $t9, (0x04000400 & 0xFFFF) # ori $t9, $t9, 0x400
/* 00C0F0 7000B4F0 3C0DB300 */  lui   $t5, 0xb300
/* 00C0F4 7000B4F4 ACED0000 */  sw    $t5, ($a3)
/* 00C0F8 7000B4F8 ACF90004 */  sw    $t9, 4($a3)
/* 00C0FC 7000B4FC 26100008 */  addiu $s0, $s0, 8
.L7000B500:
/* 00C100 7000B500 26310001 */  addiu $s1, $s1, 1
.L7000B504:
/* 00C104 7000B504 1636FFB7 */  bne   $s1, $s6, .L7000B3E4
/* 00C108 7000B508 26520046 */   addiu $s2, $s2, 0x46
/* 00C10C 7000B50C 8FAF0040 */  lw    $t7, 0x40($sp)
/* 00C110 7000B510 26B50001 */  addiu $s5, $s5, 1
/* 00C114 7000B514 24010023 */  li    $at, 35
/* 00C118 7000B518 25F80002 */  addiu $t8, $t7, 2
/* 00C11C 7000B51C 16A1FFAC */  bne   $s5, $at, .L7000B3D0
/* 00C120 7000B520 AFB80040 */   sw    $t8, 0x40($sp)
/* 00C124 7000B524 02001025 */  move  $v0, $s0
.L7000B528:
/* 00C128 7000B528 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00C12C 7000B52C 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C130 7000B530 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C134 7000B534 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C138 7000B538 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C13C 7000B53C 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C140 7000B540 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C144 7000B544 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C148 7000B548 8FB70034 */  lw    $s7, 0x34($sp)
/* 00C14C 7000B54C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00C150 7000B550 03E00008 */  jr    $ra
/* 00C154 7000B554 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif
