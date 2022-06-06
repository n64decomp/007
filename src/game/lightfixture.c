#include <ultra64.h>
#include "lightfixture.h"
#include <bondconstants.h>
#include <assets/image_externs.h>



// bss
//CODE.bss:80082660
s_lightfixture light_fixture_table[0x64];
//CODE.bss:80082B10
s16 cur_entry_lightfixture_table;
//CODE.bss:80082B12
s16 index_of_cur_entry_lightfixture_table;
//CODE.bss:80082B14                     .align 3
//CODE.bss:80082B18
s16 word_CODE_bss_80082B18[0x400];
//CODE.bss:80083318
s32 dword_CODE_bss_80083318;

// data
//D:80046030
s32 D_80046030 = 0; 

s32 D_80046034[] = {0, 0, 0, 0, 0, 0, 0};


//this mostly matches 4 bytes different
#ifdef NONMATCHING
void init_lightfixture_tables(void)
{
    s32 i;
    for (i=0;i<0x64;i++) {light_fixture_table[i].index = 0;}
    for (i=0;i<0x400;i++) {word_CODE_bss_80082B18[i] = 0;}
    D_80046030[0] = 0;
}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel init_lightfixture_tables
/* 0F0000 7F0BB4D0 3C038008 */  lui   $v1, %hi(light_fixture_table)
/* 0F0004 7F0BB4D4 3C028008 */  lui   $v0, %hi(cur_entry_lightfixture_table)
/* 0F0008 7F0BB4D8 24422B10 */  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
/* 0F000C 7F0BB4DC 24632660 */  addiu $v1, %lo(light_fixture_table) # addiu $v1, $v1, 0x2660
.L7F0BB4E0:
/* 0F0010 7F0BB4E0 2463000C */  addiu $v1, $v1, 0xc
/* 0F0014 7F0BB4E4 0062082B */  sltu  $at, $v1, $v0
/* 0F0018 7F0BB4E8 1420FFFD */  bnez  $at, .L7F0BB4E0
/* 0F001C 7F0BB4EC A460FFF4 */   sh    $zero, -0xc($v1)
/* 0F0020 7F0BB4F0 3C038008 */  lui   $v1, %hi(word_CODE_bss_80082B18)
/* 0F0024 7F0BB4F4 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80083318)
/* 0F0028 7F0BB4F8 24423318 */  addiu $v0, %lo(dword_CODE_bss_80083318) # addiu $v0, $v0, 0x3318
/* 0F002C 7F0BB4FC 24632B18 */  addiu $v1, %lo(word_CODE_bss_80082B18) # addiu $v1, $v1, 0x2b18
.L7F0BB500:
                                /*v1 offsets don't match*/
/* 0F0030 7F0BB500 24630010 */  addiu $v1, $v1, 0x10
/* 0F0034 7F0BB504 A460FFF4 */  sh    $zero, -0xc($v1)
/* 0F0038 7F0BB508 A460FFF8 */  sh    $zero, -8($v1)
/* 0F003C 7F0BB50C A460FFFC */  sh    $zero, -4($v1)
/* 0F0040 7F0BB510 1462FFFB */  bne   $v1, $v0, .L7F0BB500
/* 0F0044 7F0BB514 A460FFF0 */   sh    $zero, -0x10($v1)
/* 0F0048 7F0BB518 3C018004 */  lui   $at, %hi(D_80046030)
/* 0F004C 7F0BB51C 03E00008 */  jr    $ra
/* 0F0050 7F0BB520 AC206030 */   sw    $zero, %lo(D_80046030)($at)
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel init_lightfixture_tables
/* 0ED2C0 7F0BA8D0 3C038007 */  lui   $v1, %hi(light_fixture_table) # $v1, 0x8007
/* 0ED2C4 7F0BA8D4 3C028007 */  lui   $v0, %hi(cur_entry_lightfixture_table) # $v0, 0x8007
/* 0ED2C8 7F0BA8D8 2442D480 */  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, -0x2b80
/* 0ED2CC 7F0BA8DC 2463CFD0 */  addiu $v1, %lo(light_fixture_table) # addiu $v1, $v1, -0x3030
.L7F0BA8E0:
/* 0ED2D0 7F0BA8E0 2463000C */  addiu $v1, $v1, 0xc
/* 0ED2D4 7F0BA8E4 0062082B */  sltu  $at, $v1, $v0
/* 0ED2D8 7F0BA8E8 1420FFFD */  bnez  $at, .L7F0BA8E0
/* 0ED2DC 7F0BA8EC A460FFF4 */   sh    $zero, -0xc($v1)
/* 0ED2E0 7F0BA8F0 3C038007 */  lui   $v1, %hi(word_CODE_bss_80082B18) # $v1, 0x8007
/* 0ED2E4 7F0BA8F4 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80083318) # $v0, 0x8007
/* 0ED2E8 7F0BA8F8 2442DC88 */  addiu $v0, %lo(dword_CODE_bss_80083318) # addiu $v0, $v0, -0x2378
/* 0ED2EC 7F0BA8FC 2463D488 */  addiu $v1, %lo(word_CODE_bss_80082B18) # addiu $v1, $v1, -0x2b78
.L7F0BA900:
/* 0ED2F0 7F0BA900 24630010 */  addiu $v1, $v1, 0x10
/* 0ED2F4 7F0BA904 A460FFF4 */  sh    $zero, -0xc($v1)
/* 0ED2F8 7F0BA908 A460FFF8 */  sh    $zero, -8($v1)
/* 0ED2FC 7F0BA90C A460FFFC */  sh    $zero, -4($v1)
/* 0ED300 7F0BA910 1462FFFB */  bne   $v1, $v0, .L7F0BA900
/* 0ED304 7F0BA914 A460FFF0 */   sh    $zero, -0x10($v1)
/* 0ED308 7F0BA918 3C018004 */  lui   $at, 0x8004
/* 0ED30C 7F0BA91C 03E00008 */  jr    $ra
/* 0ED310 7F0BA920 AC20EAA0 */   sw    $zero, -0x1560($at)
)
#endif
#endif


s32 get_index_of_current_entry_in_init_lightfixture_table(void)
{
    s32 i;

    for (i = 0; i != 0x64; i++)
    {
        if (light_fixture_table[i].index == 0)
        {
            return i;
        }
    }
    return 0x64;
}


void add_entry_to_init_lightfixture_table(Gfx *DL)
{
  cur_entry_lightfixture_table = get_index_of_current_entry_in_init_lightfixture_table();
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].index = index_of_cur_entry_lightfixture_table;
    light_fixture_table[cur_entry_lightfixture_table].ptr_start_pertinent_DL = DL;
  }
}


void save_ptrDL_enpoint_to_current_init_lightfixture_table(Gfx *param_1)
{
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].ptr_end_pertinent_DL = param_1;
  }
}


s32 check_if_imageID_is_light(s32 imageID)
{
    if ((imageID == IMAGE_WALL_LAMP)     || 
        (imageID == IMAGE_203_LIGHT)  || 
        (imageID == IMAGE_205_LIGHT)  || 
        (imageID == IMAGE_252_LIGHT)  || 
        (imageID == IMAGE_PANEL_LAMP)    || 
        (imageID == IMAGE_255_LIGHT)  || 
        (imageID == IMAGE_256_LIGHT)  || 
        (imageID == IMAGE_HANGING_LAMP)  || 
        (imageID == IMAGE_NEON_LAMP)     || 
        (imageID == IMAGE_LINEAR_LAMP))
    {
        // Will darken when shot
        return 1;
    } 
    else
    {
        return 0;
    }
}






#ifdef NONMATCHING
void return_ptr_vertex_of_entry_room(void) {

}
#else
GLOBAL_ASM(
.text
glabel return_ptr_vertex_of_entry_room
/* 0F01C4 7F0BB694 808E0000 */  lb    $t6, ($a0)
/* 0F01C8 7F0BB698 24020004 */  li    $v0, 4
/* 0F01CC 7F0BB69C 0005C880 */  sll   $t9, $a1, 2
/* 0F01D0 7F0BB6A0 104E0005 */  beq   $v0, $t6, .L7F0BB6B8
/* 0F01D4 7F0BB6A4 0325C821 */   addu  $t9, $t9, $a1
/* 0F01D8 7F0BB6A8 808FFFF8 */  lb    $t7, -8($a0)
.L7F0BB6AC:
/* 0F01DC 7F0BB6AC 2484FFF8 */  addiu $a0, $a0, -8
/* 0F01E0 7F0BB6B0 544FFFFE */  bnel  $v0, $t7, .L7F0BB6AC
/* 0F01E4 7F0BB6B4 808FFFF8 */   lb    $t7, -8($a0)
.L7F0BB6B8:
/* 0F01E8 7F0BB6B8 8C830004 */  lw    $v1, 4($a0)
/* 0F01EC 7F0BB6BC 3C01FF00 */  lui   $at, 0xff00
/* 0F01F0 7F0BB6C0 0019C900 */  sll   $t9, $t9, 4
/* 0F01F4 7F0BB6C4 0061C024 */  and   $t8, $v1, $at
/* 0F01F8 7F0BB6C8 3C010E00 */  lui   $at, 0xe00
/* 0F01FC 7F0BB6CC 17010007 */  bne   $t8, $at, .L7F0BB6EC
/* 0F0200 7F0BB6D0 3C088004 */   lui   $t0, %hi(array_room_info + 0x4)
/* 0F0204 7F0BB6D4 01194021 */  addu  $t0, $t0, $t9
/* 0F0208 7F0BB6D8 8D081418 */  lw    $t0, %lo(array_room_info + 0x4)($t0)
/* 0F020C 7F0BB6DC 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0F0210 7F0BB6E0 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0F0214 7F0BB6E4 00614824 */  and   $t1, $v1, $at
/* 0F0218 7F0BB6E8 01091821 */  addu  $v1, $t0, $t1
.L7F0BB6EC:
/* 0F021C 7F0BB6EC 03E00008 */  jr    $ra
/* 0F0220 7F0BB6F0 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB6F4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80058D80*/
glabel jpt_80058D80
.word .L7F0BB714
.word .L7F0BB7C0
.word .L7F0BB7EC
.word .L7F0BB818
.word .L7F0BB844
.text
glabel sub_GAME_7F0BB6F4
/* 0F0224 7F0BB6F4 2CA10005 */  sltiu $at, $a1, 5
/* 0F0228 7F0BB6F8 1020005C */  beqz  $at, .L7F0BB86C
/* 0F022C 7F0BB6FC 00057080 */   sll   $t6, $a1, 2
/* 0F0230 7F0BB700 3C018006 */  lui   $at, %hi(jpt_80058D80)
/* 0F0234 7F0BB704 002E0821 */  addu  $at, $at, $t6
/* 0F0238 7F0BB708 8C2E8D80 */  lw    $t6, %lo(jpt_80058D80)($at)
/* 0F023C 7F0BB70C 01C00008 */  jr    $t6
/* 0F0240 7F0BB710 00000000 */   nop   
.L7F0BB714:
/* 0F0244 7F0BB714 2402000A */  li    $v0, 10
/* 0F0248 7F0BB718 908F0005 */  lbu   $t7, 5($a0)
/* 0F024C 7F0BB71C 01E2001A */  div   $zero, $t7, $v0
/* 0F0250 7F0BB720 0000C012 */  mflo  $t8
/* 0F0254 7F0BB724 ACD80000 */  sw    $t8, ($a2)
/* 0F0258 7F0BB728 90990006 */  lbu   $t9, 6($a0)
/* 0F025C 7F0BB72C 14400002 */  bnez  $v0, .L7F0BB738
/* 0F0260 7F0BB730 00000000 */   nop   
/* 0F0264 7F0BB734 0007000D */  break 7
.L7F0BB738:
/* 0F0268 7F0BB738 2401FFFF */  li    $at, -1
/* 0F026C 7F0BB73C 14410004 */  bne   $v0, $at, .L7F0BB750
/* 0F0270 7F0BB740 3C018000 */   lui   $at, 0x8000
/* 0F0274 7F0BB744 15E10002 */  bne   $t7, $at, .L7F0BB750
/* 0F0278 7F0BB748 00000000 */   nop   
/* 0F027C 7F0BB74C 0006000D */  break 6
.L7F0BB750:
/* 0F0280 7F0BB750 0322001A */  div   $zero, $t9, $v0
/* 0F0284 7F0BB754 00004012 */  mflo  $t0
/* 0F0288 7F0BB758 ACE80000 */  sw    $t0, ($a3)
/* 0F028C 7F0BB75C 90890007 */  lbu   $t1, 7($a0)
/* 0F0290 7F0BB760 14400002 */  bnez  $v0, .L7F0BB76C
/* 0F0294 7F0BB764 00000000 */   nop   
/* 0F0298 7F0BB768 0007000D */  break 7
.L7F0BB76C:
/* 0F029C 7F0BB76C 2401FFFF */  li    $at, -1
/* 0F02A0 7F0BB770 14410004 */  bne   $v0, $at, .L7F0BB784
/* 0F02A4 7F0BB774 3C018000 */   lui   $at, 0x8000
/* 0F02A8 7F0BB778 17210002 */  bne   $t9, $at, .L7F0BB784
/* 0F02AC 7F0BB77C 00000000 */   nop   
/* 0F02B0 7F0BB780 0006000D */  break 6
.L7F0BB784:
/* 0F02B4 7F0BB784 0122001A */  div   $zero, $t1, $v0
/* 0F02B8 7F0BB788 8FAB0010 */  lw    $t3, 0x10($sp)
/* 0F02BC 7F0BB78C 00005012 */  mflo  $t2
/* 0F02C0 7F0BB790 14400002 */  bnez  $v0, .L7F0BB79C
/* 0F02C4 7F0BB794 00000000 */   nop   
/* 0F02C8 7F0BB798 0007000D */  break 7
.L7F0BB79C:
/* 0F02CC 7F0BB79C 2401FFFF */  li    $at, -1
/* 0F02D0 7F0BB7A0 14410004 */  bne   $v0, $at, .L7F0BB7B4
/* 0F02D4 7F0BB7A4 3C018000 */   lui   $at, 0x8000
/* 0F02D8 7F0BB7A8 15210002 */  bne   $t1, $at, .L7F0BB7B4
/* 0F02DC 7F0BB7AC 00000000 */   nop   
/* 0F02E0 7F0BB7B0 0006000D */  break 6
.L7F0BB7B4:
/* 0F02E4 7F0BB7B4 AD6A0000 */  sw    $t2, ($t3)
/* 0F02E8 7F0BB7B8 03E00008 */  jr    $ra
/* 0F02EC 7F0BB7BC 00000000 */   nop   
.L7F0BB7C0:
/* 0F02F0 7F0BB7C0 8C8C0004 */  lw    $t4, 4($a0)
/* 0F02F4 7F0BB7C4 318D000F */  andi  $t5, $t4, 0xf
/* 0F02F8 7F0BB7C8 ACCD0000 */  sw    $t5, ($a2)
/* 0F02FC 7F0BB7CC 908E0007 */  lbu   $t6, 7($a0)
/* 0F0300 7F0BB7D0 000E7902 */  srl   $t7, $t6, 4
/* 0F0304 7F0BB7D4 ACEF0000 */  sw    $t7, ($a3)
/* 0F0308 7F0BB7D8 8C980000 */  lw    $t8, ($a0)
/* 0F030C 7F0BB7DC 8FA80010 */  lw    $t0, 0x10($sp)
/* 0F0310 7F0BB7E0 3319000F */  andi  $t9, $t8, 0xf
/* 0F0314 7F0BB7E4 03E00008 */  jr    $ra
/* 0F0318 7F0BB7E8 AD190000 */   sw    $t9, ($t0)
.L7F0BB7EC:
/* 0F031C 7F0BB7EC 90890006 */  lbu   $t1, 6($a0)
/* 0F0320 7F0BB7F0 312A000F */  andi  $t2, $t1, 0xf
/* 0F0324 7F0BB7F4 ACCA0000 */  sw    $t2, ($a2)
/* 0F0328 7F0BB7F8 948B0006 */  lhu   $t3, 6($a0)
/* 0F032C 7F0BB7FC 000B6302 */  srl   $t4, $t3, 0xc
/* 0F0330 7F0BB800 ACEC0000 */  sw    $t4, ($a3)
/* 0F0334 7F0BB804 908D0003 */  lbu   $t5, 3($a0)
/* 0F0338 7F0BB808 8FAF0010 */  lw    $t7, 0x10($sp)
/* 0F033C 7F0BB80C 000D7102 */  srl   $t6, $t5, 4
/* 0F0340 7F0BB810 03E00008 */  jr    $ra
/* 0F0344 7F0BB814 ADEE0000 */   sw    $t6, ($t7)
.L7F0BB818:
/* 0F0348 7F0BB818 94980004 */  lhu   $t8, 4($a0)
/* 0F034C 7F0BB81C 3319000F */  andi  $t9, $t8, 0xf
/* 0F0350 7F0BB820 ACD90000 */  sw    $t9, ($a2)
/* 0F0354 7F0BB824 90880005 */  lbu   $t0, 5($a0)
/* 0F0358 7F0BB828 00084902 */  srl   $t1, $t0, 4
/* 0F035C 7F0BB82C ACE90000 */  sw    $t1, ($a3)
/* 0F0360 7F0BB830 908A0002 */  lbu   $t2, 2($a0)
/* 0F0364 7F0BB834 8FAC0010 */  lw    $t4, 0x10($sp)
/* 0F0368 7F0BB838 314B000F */  andi  $t3, $t2, 0xf
/* 0F036C 7F0BB83C 03E00008 */  jr    $ra
/* 0F0370 7F0BB840 AD8B0000 */   sw    $t3, ($t4)
.L7F0BB844:
/* 0F0374 7F0BB844 908D0004 */  lbu   $t5, 4($a0)
/* 0F0378 7F0BB848 31AE000F */  andi  $t6, $t5, 0xf
/* 0F037C 7F0BB84C ACCE0000 */  sw    $t6, ($a2)
/* 0F0380 7F0BB850 8C8F0004 */  lw    $t7, 4($a0)
/* 0F0384 7F0BB854 000FC702 */  srl   $t8, $t7, 0x1c
/* 0F0388 7F0BB858 ACF80000 */  sw    $t8, ($a3)
/* 0F038C 7F0BB85C 94990002 */  lhu   $t9, 2($a0)
/* 0F0390 7F0BB860 8FA90010 */  lw    $t1, 0x10($sp)
/* 0F0394 7F0BB864 00194302 */  srl   $t0, $t9, 0xc
/* 0F0398 7F0BB868 AD280000 */  sw    $t0, ($t1)
def_7F0BB70C:
.L7F0BB86C:
/* 0F039C 7F0BB86C 03E00008 */  jr    $ra
/* 0F03A0 7F0BB870 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB874(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB874
/* 0F03A4 7F0BB874 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F03A8 7F0BB878 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F03AC 7F0BB87C AFA60038 */  sw    $a2, 0x38($sp)
/* 0F03B0 7F0BB880 AFA7003C */  sw    $a3, 0x3c($sp)
/* 0F03B4 7F0BB884 27AE0024 */  addiu $t6, $sp, 0x24
/* 0F03B8 7F0BB888 AFA40030 */  sw    $a0, 0x30($sp)
/* 0F03BC 7F0BB88C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0F03C0 7F0BB890 27A70028 */  addiu $a3, $sp, 0x28
/* 0F03C4 7F0BB894 0FC2EDBD */  jal   sub_GAME_7F0BB6F4
/* 0F03C8 7F0BB898 27A6002C */   addiu $a2, $sp, 0x2c
/* 0F03CC 7F0BB89C 8FA40030 */  lw    $a0, 0x30($sp)
/* 0F03D0 7F0BB8A0 0FC2EDA5 */  jal   return_ptr_vertex_of_entry_room
/* 0F03D4 7F0BB8A4 8FA50038 */   lw    $a1, 0x38($sp)
/* 0F03D8 7F0BB8A8 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0F03DC 7F0BB8AC 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0F03E0 7F0BB8B0 8FA30040 */  lw    $v1, 0x40($sp)
/* 0F03E4 7F0BB8B4 000FC100 */  sll   $t8, $t7, 4
/* 0F03E8 7F0BB8B8 0058C821 */  addu  $t9, $v0, $t8
/* 0F03EC 7F0BB8BC 87280000 */  lh    $t0, ($t9)
/* 0F03F0 7F0BB8C0 8FA40044 */  lw    $a0, 0x44($sp)
/* 0F03F4 7F0BB8C4 A4A80000 */  sh    $t0, ($a1)
/* 0F03F8 7F0BB8C8 8FA9002C */  lw    $t1, 0x2c($sp)
/* 0F03FC 7F0BB8CC 00095100 */  sll   $t2, $t1, 4
/* 0F0400 7F0BB8D0 004A5821 */  addu  $t3, $v0, $t2
/* 0F0404 7F0BB8D4 856C0002 */  lh    $t4, 2($t3)
/* 0F0408 7F0BB8D8 A4AC0002 */  sh    $t4, 2($a1)
/* 0F040C 7F0BB8DC 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0F0410 7F0BB8E0 000D7100 */  sll   $t6, $t5, 4
/* 0F0414 7F0BB8E4 004E7821 */  addu  $t7, $v0, $t6
/* 0F0418 7F0BB8E8 85F80004 */  lh    $t8, 4($t7)
/* 0F041C 7F0BB8EC A4B80004 */  sh    $t8, 4($a1)
/* 0F0420 7F0BB8F0 8FB90028 */  lw    $t9, 0x28($sp)
/* 0F0424 7F0BB8F4 00194100 */  sll   $t0, $t9, 4
/* 0F0428 7F0BB8F8 00484821 */  addu  $t1, $v0, $t0
/* 0F042C 7F0BB8FC 852A0000 */  lh    $t2, ($t1)
/* 0F0430 7F0BB900 A46A0000 */  sh    $t2, ($v1)
/* 0F0434 7F0BB904 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0F0438 7F0BB908 000B6100 */  sll   $t4, $t3, 4
/* 0F043C 7F0BB90C 004C6821 */  addu  $t5, $v0, $t4
/* 0F0440 7F0BB910 85AE0002 */  lh    $t6, 2($t5)
/* 0F0444 7F0BB914 A46E0002 */  sh    $t6, 2($v1)
/* 0F0448 7F0BB918 8FAF0028 */  lw    $t7, 0x28($sp)
/* 0F044C 7F0BB91C 000FC100 */  sll   $t8, $t7, 4
/* 0F0450 7F0BB920 0058C821 */  addu  $t9, $v0, $t8
/* 0F0454 7F0BB924 87280004 */  lh    $t0, 4($t9)
/* 0F0458 7F0BB928 A4680004 */  sh    $t0, 4($v1)
/* 0F045C 7F0BB92C 8FA90024 */  lw    $t1, 0x24($sp)
/* 0F0460 7F0BB930 00095100 */  sll   $t2, $t1, 4
/* 0F0464 7F0BB934 004A5821 */  addu  $t3, $v0, $t2
/* 0F0468 7F0BB938 856C0000 */  lh    $t4, ($t3)
/* 0F046C 7F0BB93C A48C0000 */  sh    $t4, ($a0)
/* 0F0470 7F0BB940 8FAD0024 */  lw    $t5, 0x24($sp)
/* 0F0474 7F0BB944 000D7100 */  sll   $t6, $t5, 4
/* 0F0478 7F0BB948 004E7821 */  addu  $t7, $v0, $t6
/* 0F047C 7F0BB94C 85F80002 */  lh    $t8, 2($t7)
/* 0F0480 7F0BB950 A4980002 */  sh    $t8, 2($a0)
/* 0F0484 7F0BB954 8FB90024 */  lw    $t9, 0x24($sp)
/* 0F0488 7F0BB958 00194100 */  sll   $t0, $t9, 4
/* 0F048C 7F0BB95C 00484821 */  addu  $t1, $v0, $t0
/* 0F0490 7F0BB960 852A0004 */  lh    $t2, 4($t1)
/* 0F0494 7F0BB964 A48A0004 */  sh    $t2, 4($a0)
/* 0F0498 7F0BB968 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F049C 7F0BB96C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0F04A0 7F0BB970 03E00008 */  jr    $ra
/* 0F04A4 7F0BB974 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BB978(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB978
/* 0F04A8 7F0BB978 00047080 */  sll   $t6, $a0, 2
/* 0F04AC 7F0BB97C 01C47021 */  addu  $t6, $t6, $a0
/* 0F04B0 7F0BB980 000E7100 */  sll   $t6, $t6, 4
/* 0F04B4 7F0BB984 3C028004 */  lui   $v0, %hi(array_room_info + 0x4)
/* 0F04B8 7F0BB988 004E1021 */  addu  $v0, $v0, $t6
/* 0F04BC 7F0BB98C 3C058008 */  lui   $a1, %hi(word_CODE_bss_80082B18)
/* 0F04C0 7F0BB990 3C068008 */  lui   $a2, %hi(dword_CODE_bss_80083318)
/* 0F04C4 7F0BB994 8C421418 */  lw    $v0, %lo(array_room_info + 0x4)($v0)
/* 0F04C8 7F0BB998 24C63318 */  addiu $a2, %lo(dword_CODE_bss_80083318) # addiu $a2, $a2, 0x3318
/* 0F04CC 7F0BB99C 24A52B18 */  addiu $a1, %lo(word_CODE_bss_80082B18) # addiu $a1, $a1, 0x2b18
/* 0F04D0 7F0BB9A0 94AF0000 */  lhu   $t7, ($a1)
.L7F0BB9A4:
/* 0F04D4 7F0BB9A4 548F001A */  bnel  $a0, $t7, .L7F0BBA10
/* 0F04D8 7F0BB9A8 24A50004 */   addiu $a1, $a1, 4
/* 0F04DC 7F0BB9AC 94B80002 */  lhu   $t8, 2($a1)
/* 0F04E0 7F0BB9B0 0018C900 */  sll   $t9, $t8, 4
/* 0F04E4 7F0BB9B4 00591821 */  addu  $v1, $v0, $t9
/* 0F04E8 7F0BB9B8 9068000C */  lbu   $t0, 0xc($v1)
/* 0F04EC 7F0BB9BC 00084882 */  srl   $t1, $t0, 2
/* 0F04F0 7F0BB9C0 A069000C */  sb    $t1, 0xc($v1)
/* 0F04F4 7F0BB9C4 94AA0002 */  lhu   $t2, 2($a1)
/* 0F04F8 7F0BB9C8 000A5900 */  sll   $t3, $t2, 4
/* 0F04FC 7F0BB9CC 004B1821 */  addu  $v1, $v0, $t3
/* 0F0500 7F0BB9D0 906C000D */  lbu   $t4, 0xd($v1)
/* 0F0504 7F0BB9D4 000C6882 */  srl   $t5, $t4, 2
/* 0F0508 7F0BB9D8 A06D000D */  sb    $t5, 0xd($v1)
/* 0F050C 7F0BB9DC 94AE0002 */  lhu   $t6, 2($a1)
/* 0F0510 7F0BB9E0 000E7900 */  sll   $t7, $t6, 4
/* 0F0514 7F0BB9E4 004F1821 */  addu  $v1, $v0, $t7
/* 0F0518 7F0BB9E8 9078000E */  lbu   $t8, 0xe($v1)
/* 0F051C 7F0BB9EC 0018C882 */  srl   $t9, $t8, 2
/* 0F0520 7F0BB9F0 A079000E */  sb    $t9, 0xe($v1)
/* 0F0524 7F0BB9F4 94A80002 */  lhu   $t0, 2($a1)
/* 0F0528 7F0BB9F8 00084900 */  sll   $t1, $t0, 4
/* 0F052C 7F0BB9FC 00491821 */  addu  $v1, $v0, $t1
/* 0F0530 7F0BBA00 906A000F */  lbu   $t2, 0xf($v1)
/* 0F0534 7F0BBA04 000A5882 */  srl   $t3, $t2, 2
/* 0F0538 7F0BBA08 A06B000F */  sb    $t3, 0xf($v1)
/* 0F053C 7F0BBA0C 24A50004 */  addiu $a1, $a1, 4
.L7F0BBA10:
/* 0F0540 7F0BBA10 54A6FFE4 */  bnel  $a1, $a2, .L7F0BB9A4
/* 0F0544 7F0BBA14 94AF0000 */   lhu   $t7, ($a1)
/* 0F0548 7F0BBA18 03E00008 */  jr    $ra
/* 0F054C 7F0BBA1C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBA20(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBA20
/* 0F0550 7F0BBA20 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F0554 7F0BBA24 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F0558 7F0BBA28 AFA40018 */  sw    $a0, 0x18($sp)
/* 0F055C 7F0BBA2C 0FC2EEB7 */  jal   sub_GAME_7F0BBADC
/* 0F0560 7F0BBA30 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0F0564 7F0BBA34 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F0568 7F0BBA38 14400024 */  bnez  $v0, .L7F0BBACC
/* 0F056C 7F0BBA3C 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0F0570 7F0BBA40 00067080 */  sll   $t6, $a2, 2
/* 0F0574 7F0BBA44 3C058004 */  lui   $a1, %hi(D_80046030)
/* 0F0578 7F0BBA48 01C67021 */  addu  $t6, $t6, $a2
/* 0F057C 7F0BBA4C 24A56030 */  addiu $a1, %lo(D_80046030) # addiu $a1, $a1, 0x6030
/* 0F0580 7F0BBA50 000E7100 */  sll   $t6, $t6, 4
/* 0F0584 7F0BBA54 3C0F8004 */  lui   $t7, %hi(array_room_info + 0x4)
/* 0F0588 7F0BBA58 8CB90000 */  lw    $t9, ($a1)
/* 0F058C 7F0BBA5C 01EE7821 */  addu  $t7, $t7, $t6
/* 0F0590 7F0BBA60 8DEF1418 */  lw    $t7, %lo(array_room_info + 0x4)($t7)
/* 0F0594 7F0BBA64 3C098008 */  lui   $t1, %hi(word_CODE_bss_80082B18) 
/* 0F0598 7F0BBA68 25292B18 */  addiu $t1, %lo(word_CODE_bss_80082B18) # addiu $t1, $t1, 0x2b18
/* 0F059C 7F0BBA6C 00194080 */  sll   $t0, $t9, 2
/* 0F05A0 7F0BBA70 01091021 */  addu  $v0, $t0, $t1
/* 0F05A4 7F0BBA74 008F1823 */  subu  $v1, $a0, $t7
/* 0F05A8 7F0BBA78 0003C102 */  srl   $t8, $v1, 4
/* 0F05AC 7F0BBA7C A4460000 */  sh    $a2, ($v0)
/* 0F05B0 7F0BBA80 A4580002 */  sh    $t8, 2($v0)
/* 0F05B4 7F0BBA84 908A000C */  lbu   $t2, 0xc($a0)
/* 0F05B8 7F0BBA88 908C000D */  lbu   $t4, 0xd($a0)
/* 0F05BC 7F0BBA8C 908E000E */  lbu   $t6, 0xe($a0)
/* 0F05C0 7F0BBA90 9098000F */  lbu   $t8, 0xf($a0)
/* 0F05C4 7F0BBA94 000A5882 */  srl   $t3, $t2, 2
/* 0F05C8 7F0BBA98 000C6882 */  srl   $t5, $t4, 2
/* 0F05CC 7F0BBA9C 000E7882 */  srl   $t7, $t6, 2
/* 0F05D0 7F0BBAA0 0018C882 */  srl   $t9, $t8, 2
/* 0F05D4 7F0BBAA4 A08B000C */  sb    $t3, 0xc($a0)
/* 0F05D8 7F0BBAA8 A08D000D */  sb    $t5, 0xd($a0)
/* 0F05DC 7F0BBAAC A08F000E */  sb    $t7, 0xe($a0)
/* 0F05E0 7F0BBAB0 A099000F */  sb    $t9, 0xf($a0)
/* 0F05E4 7F0BBAB4 8CA80000 */  lw    $t0, ($a1)
/* 0F05E8 7F0BBAB8 25090001 */  addiu $t1, $t0, 1
/* 0F05EC 7F0BBABC 29210200 */  slti  $at, $t1, 0x200
/* 0F05F0 7F0BBAC0 14200002 */  bnez  $at, .L7F0BBACC
/* 0F05F4 7F0BBAC4 ACA90000 */   sw    $t1, ($a1)
/* 0F05F8 7F0BBAC8 ACA00000 */  sw    $zero, ($a1)
.L7F0BBACC:
/* 0F05FC 7F0BBACC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F0600 7F0BBAD0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F0604 7F0BBAD4 03E00008 */  jr    $ra
/* 0F0608 7F0BBAD8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBADC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBADC
/* 0F060C 7F0BBADC 00057080 */  sll   $t6, $a1, 2
/* 0F0610 7F0BBAE0 01C57021 */  addu  $t6, $t6, $a1
/* 0F0614 7F0BBAE4 000E7100 */  sll   $t6, $t6, 4
/* 0F0618 7F0BBAE8 3C0F8004 */  lui   $t7, %hi(array_room_info + 0x4)
/* 0F061C 7F0BBAEC 01EE7821 */  addu  $t7, $t7, $t6
/* 0F0620 7F0BBAF0 8DEF1418 */  lw    $t7, %lo(array_room_info + 0x4)($t7)
/* 0F0624 7F0BBAF4 3C068008 */  lui   $a2, %hi(word_CODE_bss_80082B18)
/* 0F0628 7F0BBAF8 3C038008 */  lui   $v1, %hi(dword_CODE_bss_80083318)
/* 0F062C 7F0BBAFC 008F1023 */  subu  $v0, $a0, $t7
/* 0F0630 7F0BBB00 0002C102 */  srl   $t8, $v0, 4
/* 0F0634 7F0BBB04 03001025 */  move  $v0, $t8
/* 0F0638 7F0BBB08 24633318 */  addiu $v1, %lo(dword_CODE_bss_80083318) # addiu $v1, $v1, 0x3318
/* 0F063C 7F0BBB0C 24C62B18 */  addiu $a2, %lo(word_CODE_bss_80082B18) # addiu $a2, $a2, 0x2b18
/* 0F0640 7F0BBB10 94D90000 */  lhu   $t9, ($a2)
.L7F0BBB14:
/* 0F0644 7F0BBB14 54B90007 */  bnel  $a1, $t9, .L7F0BBB34
/* 0F0648 7F0BBB18 94C90004 */   lhu   $t1, 4($a2)
/* 0F064C 7F0BBB1C 94C80002 */  lhu   $t0, 2($a2)
/* 0F0650 7F0BBB20 54480004 */  bnel  $v0, $t0, .L7F0BBB34
/* 0F0654 7F0BBB24 94C90004 */   lhu   $t1, 4($a2)
/* 0F0658 7F0BBB28 03E00008 */  jr    $ra
/* 0F065C 7F0BBB2C 24020001 */   li    $v0, 1

/* 0F0660 7F0BBB30 94C90004 */  lhu   $t1, 4($a2)
.L7F0BBB34:
/* 0F0664 7F0BBB34 54A90007 */  bnel  $a1, $t1, .L7F0BBB54
/* 0F0668 7F0BBB38 94CB0008 */   lhu   $t3, 8($a2)
/* 0F066C 7F0BBB3C 94CA0006 */  lhu   $t2, 6($a2)
/* 0F0670 7F0BBB40 544A0004 */  bnel  $v0, $t2, .L7F0BBB54
/* 0F0674 7F0BBB44 94CB0008 */   lhu   $t3, 8($a2)
/* 0F0678 7F0BBB48 03E00008 */  jr    $ra
/* 0F067C 7F0BBB4C 24020001 */   li    $v0, 1

/* 0F0680 7F0BBB50 94CB0008 */  lhu   $t3, 8($a2)
.L7F0BBB54:
/* 0F0684 7F0BBB54 54AB0007 */  bnel  $a1, $t3, .L7F0BBB74
/* 0F0688 7F0BBB58 94CD000C */   lhu   $t5, 0xc($a2)
/* 0F068C 7F0BBB5C 94CC000A */  lhu   $t4, 0xa($a2)
/* 0F0690 7F0BBB60 544C0004 */  bnel  $v0, $t4, .L7F0BBB74
/* 0F0694 7F0BBB64 94CD000C */   lhu   $t5, 0xc($a2)
/* 0F0698 7F0BBB68 03E00008 */  jr    $ra
/* 0F069C 7F0BBB6C 24020001 */   li    $v0, 1

/* 0F06A0 7F0BBB70 94CD000C */  lhu   $t5, 0xc($a2)
.L7F0BBB74:
/* 0F06A4 7F0BBB74 54AD0007 */  bnel  $a1, $t5, .L7F0BBB94
/* 0F06A8 7F0BBB78 24C60010 */   addiu $a2, $a2, 0x10
/* 0F06AC 7F0BBB7C 94CE000E */  lhu   $t6, 0xe($a2)
/* 0F06B0 7F0BBB80 544E0004 */  bnel  $v0, $t6, .L7F0BBB94
/* 0F06B4 7F0BBB84 24C60010 */   addiu $a2, $a2, 0x10
/* 0F06B8 7F0BBB88 03E00008 */  jr    $ra
/* 0F06BC 7F0BBB8C 24020001 */   li    $v0, 1

/* 0F06C0 7F0BBB90 24C60010 */  addiu $a2, $a2, 0x10
.L7F0BBB94:
/* 0F06C4 7F0BBB94 54C3FFDF */  bnel  $a2, $v1, .L7F0BBB14
/* 0F06C8 7F0BBB98 94D90000 */   lhu   $t9, ($a2)
/* 0F06CC 7F0BBB9C 00001025 */  move  $v0, $zero
/* 0F06D0 7F0BBBA0 03E00008 */  jr    $ra
/* 0F06D4 7F0BBBA4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBBA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBBA8
/* 0F06D8 7F0BBBA8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F06DC 7F0BBBAC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F06E0 7F0BBBB0 AFA60040 */  sw    $a2, 0x40($sp)
/* 0F06E4 7F0BBBB4 27AE0028 */  addiu $t6, $sp, 0x28
/* 0F06E8 7F0BBBB8 AFA40038 */  sw    $a0, 0x38($sp)
/* 0F06EC 7F0BBBBC AFAE0010 */  sw    $t6, 0x10($sp)
/* 0F06F0 7F0BBBC0 27A60030 */  addiu $a2, $sp, 0x30
/* 0F06F4 7F0BBBC4 0FC2EDBD */  jal   sub_GAME_7F0BB6F4
/* 0F06F8 7F0BBBC8 27A7002C */   addiu $a3, $sp, 0x2c
/* 0F06FC 7F0BBBCC 8FA40038 */  lw    $a0, 0x38($sp)
/* 0F0700 7F0BBBD0 0FC2EDA5 */  jal   return_ptr_vertex_of_entry_room
/* 0F0704 7F0BBBD4 8FA50040 */   lw    $a1, 0x40($sp)
/* 0F0708 7F0BBBD8 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0F070C 7F0BBBDC AFA20024 */  sw    $v0, 0x24($sp)
/* 0F0710 7F0BBBE0 8FA50040 */  lw    $a1, 0x40($sp)
/* 0F0714 7F0BBBE4 000FC100 */  sll   $t8, $t7, 4
/* 0F0718 7F0BBBE8 0FC2EE88 */  jal   sub_GAME_7F0BBA20
/* 0F071C 7F0BBBEC 03022021 */   addu  $a0, $t8, $v0
/* 0F0720 7F0BBBF0 8FB9002C */  lw    $t9, 0x2c($sp)
/* 0F0724 7F0BBBF4 8FA90024 */  lw    $t1, 0x24($sp)
/* 0F0728 7F0BBBF8 8FA50040 */  lw    $a1, 0x40($sp)
/* 0F072C 7F0BBBFC 00194100 */  sll   $t0, $t9, 4
/* 0F0730 7F0BBC00 0FC2EE88 */  jal   sub_GAME_7F0BBA20
/* 0F0734 7F0BBC04 01092021 */   addu  $a0, $t0, $t1
/* 0F0738 7F0BBC08 8FAA0028 */  lw    $t2, 0x28($sp)
/* 0F073C 7F0BBC0C 8FAC0024 */  lw    $t4, 0x24($sp)
/* 0F0740 7F0BBC10 8FA50040 */  lw    $a1, 0x40($sp)
/* 0F0744 7F0BBC14 000A5900 */  sll   $t3, $t2, 4
/* 0F0748 7F0BBC18 0FC2EE88 */  jal   sub_GAME_7F0BBA20
/* 0F074C 7F0BBC1C 016C2021 */   addu  $a0, $t3, $t4
/* 0F0750 7F0BBC20 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0754 7F0BBC24 27BD0038 */  addiu $sp, $sp, 0x38
/* 0F0758 7F0BBC28 03E00008 */  jr    $ra
/* 0F075C 7F0BBC2C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBC30(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBC30
/* 0F0760 7F0BBC30 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F0764 7F0BBC34 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0768 7F0BBC38 AFA60048 */  sw    $a2, 0x48($sp)
/* 0F076C 7F0BBC3C 27AE0030 */  addiu $t6, $sp, 0x30
/* 0F0770 7F0BBC40 AFA40040 */  sw    $a0, 0x40($sp)
/* 0F0774 7F0BBC44 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0F0778 7F0BBC48 27A60038 */  addiu $a2, $sp, 0x38
/* 0F077C 7F0BBC4C 0FC2EDBD */  jal   sub_GAME_7F0BB6F4
/* 0F0780 7F0BBC50 27A70034 */   addiu $a3, $sp, 0x34
/* 0F0784 7F0BBC54 8FA40040 */  lw    $a0, 0x40($sp)
/* 0F0788 7F0BBC58 0FC2EDA5 */  jal   return_ptr_vertex_of_entry_room
/* 0F078C 7F0BBC5C 8FA50048 */   lw    $a1, 0x48($sp)
/* 0F0790 7F0BBC60 8FAF0034 */  lw    $t7, 0x34($sp)
/* 0F0794 7F0BBC64 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F0798 7F0BBC68 8FA50048 */  lw    $a1, 0x48($sp)
/* 0F079C 7F0BBC6C 000FC100 */  sll   $t8, $t7, 4
/* 0F07A0 7F0BBC70 0FC2EEB7 */  jal   sub_GAME_7F0BBADC
/* 0F07A4 7F0BBC74 03022021 */   addu  $a0, $t8, $v0
/* 0F07A8 7F0BBC78 8FB90038 */  lw    $t9, 0x38($sp)
/* 0F07AC 7F0BBC7C 8FA9002C */  lw    $t1, 0x2c($sp)
/* 0F07B0 7F0BBC80 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F07B4 7F0BBC84 00194100 */  sll   $t0, $t9, 4
/* 0F07B8 7F0BBC88 8FA50048 */  lw    $a1, 0x48($sp)
/* 0F07BC 7F0BBC8C 0FC2EEB7 */  jal   sub_GAME_7F0BBADC
/* 0F07C0 7F0BBC90 01092021 */   addu  $a0, $t0, $t1
/* 0F07C4 7F0BBC94 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0F07C8 7F0BBC98 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0F07CC 7F0BBC9C AFA20028 */  sw    $v0, 0x28($sp)
/* 0F07D0 7F0BBCA0 000A5900 */  sll   $t3, $t2, 4
/* 0F07D4 7F0BBCA4 8FA50048 */  lw    $a1, 0x48($sp)
/* 0F07D8 7F0BBCA8 0FC2EEB7 */  jal   sub_GAME_7F0BBADC
/* 0F07DC 7F0BBCAC 016C2021 */   addu  $a0, $t3, $t4
/* 0F07E0 7F0BBCB0 8FAD0028 */  lw    $t5, 0x28($sp)
/* 0F07E4 7F0BBCB4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F07E8 7F0BBCB8 8FAF0024 */  lw    $t7, 0x24($sp)
/* 0F07EC 7F0BBCBC 004D7021 */  addu  $t6, $v0, $t5
/* 0F07F0 7F0BBCC0 27BD0040 */  addiu $sp, $sp, 0x40
/* 0F07F4 7F0BBCC4 03E00008 */  jr    $ra
/* 0F07F8 7F0BBCC8 01CF1021 */   addu  $v0, $t6, $t7
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBCCC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBCCC
/* 0F07FC 7F0BBCCC 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0F0800 7F0BBCD0 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0F0804 7F0BBCD4 AFB60038 */  sw    $s6, 0x38($sp)
/* 0F0808 7F0BBCD8 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F080C 7F0BBCDC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F0810 7F0BBCE0 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0F0814 7F0BBCE4 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0F0818 7F0BBCE8 AFB50034 */  sw    $s5, 0x34($sp)
/* 0F081C 7F0BBCEC AFB40030 */  sw    $s4, 0x30($sp)
/* 0F0820 7F0BBCF0 3C138008 */  lui   $s3, %hi(word_CODE_bss_80082B18)
/* 0F0824 7F0BBCF4 3C168004 */  lui   $s6, %hi(array_room_info)
/* 0F0828 7F0BBCF8 3C1E8008 */  lui   $fp, %hi(dword_CODE_bss_80083318) 
/* 0F082C 7F0BBCFC 4481A000 */  mtc1  $at, $f20
/* 0F0830 7F0BBD00 0080A025 */  move  $s4, $a0
/* 0F0834 7F0BBD04 00A0A825 */  move  $s5, $a1
/* 0F0838 7F0BBD08 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0F083C 7F0BBD0C AFB20028 */  sw    $s2, 0x28($sp)
/* 0F0840 7F0BBD10 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F0844 7F0BBD14 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F0848 7F0BBD18 27DE3318 */  addiu $fp, %lo(dword_CODE_bss_80083318) # addiu $fp, $fp, 0x3318
/* 0F084C 7F0BBD1C 26D61414 */  addiu $s6, %lo(array_room_info) # addiu $s6, $s6, 0x1414
/* 0F0850 7F0BBD20 26732B18 */  addiu $s3, %lo(word_CODE_bss_80082B18) # addiu $s3, $s3, 0x2b18
/* 0F0854 7F0BBD24 24170050 */  li    $s7, 80
/* 0F0858 7F0BBD28 966E0000 */  lhu   $t6, ($s3)
.L7F0BBD2C:
/* 0F085C 7F0BBD2C 56AE0027 */  bnel  $s5, $t6, .L7F0BBDCC
/* 0F0860 7F0BBD30 26730004 */   addiu $s3, $s3, 4
/* 0F0864 7F0BBD34 02B70019 */  multu $s5, $s7
/* 0F0868 7F0BBD38 966F0002 */  lhu   $t7, 2($s3)
/* 0F086C 7F0BBD3C 868B0000 */  lh    $t3, ($s4)
/* 0F0870 7F0BBD40 868D0002 */  lh    $t5, 2($s4)
/* 0F0874 7F0BBD44 000FC100 */  sll   $t8, $t7, 4
/* 0F0878 7F0BBD48 868F0004 */  lh    $t7, 4($s4)
/* 0F087C 7F0BBD4C 0000C812 */  mflo  $t9
/* 0F0880 7F0BBD50 02D94021 */  addu  $t0, $s6, $t9
/* 0F0884 7F0BBD54 8D090004 */  lw    $t1, 4($t0)
/* 0F0888 7F0BBD58 03091021 */  addu  $v0, $t8, $t1
/* 0F088C 7F0BBD5C 844A0000 */  lh    $t2, ($v0)
/* 0F0890 7F0BBD60 844C0002 */  lh    $t4, 2($v0)
/* 0F0894 7F0BBD64 844E0004 */  lh    $t6, 4($v0)
/* 0F0898 7F0BBD68 014B8023 */  subu  $s0, $t2, $t3
/* 0F089C 7F0BBD6C 018D8823 */  subu  $s1, $t4, $t5
/* 0F08A0 7F0BBD70 06010002 */  bgez  $s0, .L7F0BBD7C
/* 0F08A4 7F0BBD74 01CF9023 */   subu  $s2, $t6, $t7
/* 0F08A8 7F0BBD78 00108023 */  negu  $s0, $s0
.L7F0BBD7C:
/* 0F08AC 7F0BBD7C 06210002 */  bgez  $s1, .L7F0BBD88
/* 0F08B0 7F0BBD80 00000000 */   nop   
/* 0F08B4 7F0BBD84 00118823 */  negu  $s1, $s1
.L7F0BBD88:
/* 0F08B8 7F0BBD88 06410002 */  bgez  $s2, .L7F0BBD94
/* 0F08BC 7F0BBD8C 00000000 */   nop   
/* 0F08C0 7F0BBD90 00129023 */  negu  $s2, $s2
.L7F0BBD94:
/* 0F08C4 7F0BBD94 0FC2D20F */  jal   get_room_data_float1
/* 0F08C8 7F0BBD98 00000000 */   nop   
/* 0F08CC 7F0BBD9C 46140102 */  mul.s $f4, $f0, $f20
/* 0F08D0 7F0BBDA0 0211C821 */  addu  $t9, $s0, $s1
/* 0F08D4 7F0BBDA4 03324021 */  addu  $t0, $t9, $s2
/* 0F08D8 7F0BBDA8 4600218D */  trunc.w.s $f6, $f4
/* 0F08DC 7F0BBDAC 44093000 */  mfc1  $t1, $f6
/* 0F08E0 7F0BBDB0 00000000 */  nop   
/* 0F08E4 7F0BBDB4 0109082A */  slt   $at, $t0, $t1
/* 0F08E8 7F0BBDB8 50200004 */  beql  $at, $zero, .L7F0BBDCC
/* 0F08EC 7F0BBDBC 26730004 */   addiu $s3, $s3, 4
/* 0F08F0 7F0BBDC0 10000005 */  b     .L7F0BBDD8
/* 0F08F4 7F0BBDC4 24020001 */   li    $v0, 1
/* 0F08F8 7F0BBDC8 26730004 */  addiu $s3, $s3, 4
.L7F0BBDCC:
/* 0F08FC 7F0BBDCC 567EFFD7 */  bnel  $s3, $fp, .L7F0BBD2C
/* 0F0900 7F0BBDD0 966E0000 */   lhu   $t6, ($s3)
/* 0F0904 7F0BBDD4 00001025 */  move  $v0, $zero
.L7F0BBDD8:
/* 0F0908 7F0BBDD8 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0F090C 7F0BBDDC D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F0910 7F0BBDE0 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F0914 7F0BBDE4 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F0918 7F0BBDE8 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F091C 7F0BBDEC 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F0920 7F0BBDF0 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F0924 7F0BBDF4 8FB50034 */  lw    $s5, 0x34($sp)
/* 0F0928 7F0BBDF8 8FB60038 */  lw    $s6, 0x38($sp)
/* 0F092C 7F0BBDFC 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0F0930 7F0BBE00 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0F0934 7F0BBE04 03E00008 */  jr    $ra
/* 0F0938 7F0BBE08 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BBE0C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBE0C
/* 0F093C 7F0BBE0C 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0F0940 7F0BBE10 AFB20044 */  sw    $s2, 0x44($sp)
/* 0F0944 7F0BBE14 AFB10040 */  sw    $s1, 0x40($sp)
/* 0F0948 7F0BBE18 AFB0003C */  sw    $s0, 0x3c($sp)
/* 0F094C 7F0BBE1C 3C128008 */  lui   $s2, %hi(light_fixture_table)
/* 0F0950 7F0BBE20 3C028008 */  lui   $v0, %hi(cur_entry_lightfixture_table)
/* 0F0954 7F0BBE24 00808025 */  move  $s0, $a0
/* 0F0958 7F0BBE28 00A08825 */  move  $s1, $a1
/* 0F095C 7F0BBE2C AFBF005C */  sw    $ra, 0x5c($sp)
/* 0F0960 7F0BBE30 AFB70058 */  sw    $s7, 0x58($sp)
/* 0F0964 7F0BBE34 AFB60054 */  sw    $s6, 0x54($sp)
/* 0F0968 7F0BBE38 AFB50050 */  sw    $s5, 0x50($sp)
/* 0F096C 7F0BBE3C AFB4004C */  sw    $s4, 0x4c($sp)
/* 0F0970 7F0BBE40 AFB30048 */  sw    $s3, 0x48($sp)
/* 0F0974 7F0BBE44 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0F0978 7F0BBE48 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0F097C 7F0BBE4C F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0F0980 7F0BBE50 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F0984 7F0BBE54 00C03825 */  move  $a3, $a2
/* 0F0988 7F0BBE58 24422B10 */  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
/* 0F098C 7F0BBE5C 26522660 */  addiu $s2, %lo(light_fixture_table) # addiu $s2, $s2, 0x2660
/* 0F0990 7F0BBE60 86460000 */  lh    $a2, ($s2)
.L7F0BBE64:
/* 0F0994 7F0BBE64 54E60186 */  bnel  $a3, $a2, .L7F0BC480
/* 0F0998 7F0BBE68 2652000C */   addiu $s2, $s2, 0xc
/* 0F099C 7F0BBE6C 8E4E0004 */  lw    $t6, 4($s2)
/* 0F09A0 7F0BBE70 020E082B */  sltu  $at, $s0, $t6
/* 0F09A4 7F0BBE74 54200182 */  bnezl $at, .L7F0BC480
/* 0F09A8 7F0BBE78 2652000C */   addiu $s2, $s2, 0xc
/* 0F09AC 7F0BBE7C 8E4F0008 */  lw    $t7, 8($s2)
/* 0F09B0 7F0BBE80 020F082B */  sltu  $at, $s0, $t7
/* 0F09B4 7F0BBE84 1020017D */  beqz  $at, .L7F0BC47C
/* 0F09B8 7F0BBE88 02002025 */   move  $a0, $s0
/* 0F09BC 7F0BBE8C 0FC2EF0C */  jal   sub_GAME_7F0BBC30
/* 0F09C0 7F0BBE90 02202825 */   move  $a1, $s1
/* 0F09C4 7F0BBE94 1440017C */  bnez  $v0, .L7F0BC488
/* 0F09C8 7F0BBE98 02002025 */   move  $a0, $s0
/* 0F09CC 7F0BBE9C 02202825 */  move  $a1, $s1
/* 0F09D0 7F0BBEA0 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F09D4 7F0BBEA4 86460000 */   lh    $a2, ($s2)
/* 0F09D8 7F0BBEA8 27B800E8 */  addiu $t8, $sp, 0xe8
/* 0F09DC 7F0BBEAC 27B900E0 */  addiu $t9, $sp, 0xe0
/* 0F09E0 7F0BBEB0 AFB90014 */  sw    $t9, 0x14($sp)
/* 0F09E4 7F0BBEB4 AFB80010 */  sw    $t8, 0x10($sp)
/* 0F09E8 7F0BBEB8 02002025 */  move  $a0, $s0
/* 0F09EC 7F0BBEBC 02202825 */  move  $a1, $s1
/* 0F09F0 7F0BBEC0 86460000 */  lh    $a2, ($s2)
/* 0F09F4 7F0BBEC4 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F09F8 7F0BBEC8 27A700F0 */   addiu $a3, $sp, 0xf0
/* 0F09FC 7F0BBECC 87A200F0 */  lh    $v0, 0xf0($sp)
/* 0F0A00 7F0BBED0 87A500E8 */  lh    $a1, 0xe8($sp)
/* 0F0A04 7F0BBED4 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0A08 7F0BBED8 87A300F2 */  lh    $v1, 0xf2($sp)
/* 0F0A0C 7F0BBEDC 00458023 */  subu  $s0, $v0, $a1
/* 0F0A10 7F0BBEE0 00105C00 */  sll   $t3, $s0, 0x10
/* 0F0A14 7F0BBEE4 000B8403 */  sra   $s0, $t3, 0x10
/* 0F0A18 7F0BBEE8 02100019 */  multu $s0, $s0
/* 0F0A1C 7F0BBEEC 87A700EA */  lh    $a3, 0xea($sp)
/* 0F0A20 7F0BBEF0 0046A023 */  subu  $s4, $v0, $a2
/* 0F0A24 7F0BBEF4 00146C00 */  sll   $t5, $s4, 0x10
/* 0F0A28 7F0BBEF8 000DA403 */  sra   $s4, $t5, 0x10
/* 0F0A2C 7F0BBEFC 00678823 */  subu  $s1, $v1, $a3
/* 0F0A30 7F0BBF00 0011CC00 */  sll   $t9, $s1, 0x10
/* 0F0A34 7F0BBF04 00198C03 */  sra   $s1, $t9, 0x10
/* 0F0A38 7F0BBF08 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0A3C 7F0BBF0C 87A400F4 */  lh    $a0, 0xf4($sp)
/* 0F0A40 7F0BBF10 00006812 */  mflo  $t5
/* 0F0A44 7F0BBF14 87A900EC */  lh    $t1, 0xec($sp)
/* 0F0A48 7F0BBF18 00A6B823 */  subu  $s7, $a1, $a2
/* 0F0A4C 7F0BBF1C 02310019 */  multu $s1, $s1
/* 0F0A50 7F0BBF20 00E87023 */  subu  $t6, $a3, $t0
/* 0F0A54 7F0BBF24 00177C00 */  sll   $t7, $s7, 0x10
/* 0F0A58 7F0BBF28 A7AE00B4 */  sh    $t6, 0xb4($sp)
/* 0F0A5C 7F0BBF2C 000FBC03 */  sra   $s7, $t7, 0x10
/* 0F0A60 7F0BBF30 00899823 */  subu  $s3, $a0, $t1
/* 0F0A64 7F0BBF34 00137C00 */  sll   $t7, $s3, 0x10
/* 0F0A68 7F0BBF38 000F9C03 */  sra   $s3, $t7, 0x10
/* 0F0A6C 7F0BBF3C 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0A70 7F0BBF40 0068A823 */  subu  $s5, $v1, $t0
/* 0F0A74 7F0BBF44 00007012 */  mflo  $t6
/* 0F0A78 7F0BBF48 008AB023 */  subu  $s6, $a0, $t2
/* 0F0A7C 7F0BBF4C 0016CC00 */  sll   $t9, $s6, 0x10
/* 0F0A80 7F0BBF50 02730019 */  multu $s3, $s3
/* 0F0A84 7F0BBF54 0019B403 */  sra   $s6, $t9, 0x10
/* 0F0A88 7F0BBF58 01AE7821 */  addu  $t7, $t5, $t6
/* 0F0A8C 7F0BBF5C 00156400 */  sll   $t4, $s5, 0x10
/* 0F0A90 7F0BBF60 000CAC03 */  sra   $s5, $t4, 0x10
/* 0F0A94 7F0BBF64 012A6023 */  subu  $t4, $t1, $t2
/* 0F0A98 7F0BBF68 A7AC00AE */  sh    $t4, 0xae($sp)
/* 0F0A9C 7F0BBF6C 0000C012 */  mflo  $t8
/* 0F0AA0 7F0BBF70 01F8C821 */  addu  $t9, $t7, $t8
/* 0F0AA4 7F0BBF74 44992000 */  mtc1  $t9, $f4
/* 0F0AA8 7F0BBF78 0C007DF8 */  jal   sqrtf
/* 0F0AAC 7F0BBF7C 46802320 */   cvt.s.w $f12, $f4
/* 0F0AB0 7F0BBF80 0FC2D20C */  jal   get_room_data_float2
/* 0F0AB4 7F0BBF84 46000506 */   mov.s $f20, $f0
/* 0F0AB8 7F0BBF88 02940019 */  multu $s4, $s4
/* 0F0ABC 7F0BBF8C 46140182 */  mul.s $f6, $f0, $f20
/* 0F0AC0 7F0BBF90 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0F0AC4 7F0BBF94 4481D000 */  mtc1  $at, $f26
/* 0F0AC8 7F0BBF98 00000000 */  nop   
/* 0F0ACC 7F0BBF9C 4606D203 */  div.s $f8, $f26, $f6
/* 0F0AD0 7F0BBFA0 00005812 */  mflo  $t3
/* 0F0AD4 7F0BBFA4 00000000 */  nop   
/* 0F0AD8 7F0BBFA8 00000000 */  nop   
/* 0F0ADC 7F0BBFAC 02B50019 */  multu $s5, $s5
/* 0F0AE0 7F0BBFB0 00006012 */  mflo  $t4
/* 0F0AE4 7F0BBFB4 016C6821 */  addu  $t5, $t3, $t4
/* 0F0AE8 7F0BBFB8 00000000 */  nop   
/* 0F0AEC 7F0BBFBC 02D60019 */  multu $s6, $s6
/* 0F0AF0 7F0BBFC0 E7A800A8 */  swc1  $f8, 0xa8($sp)
/* 0F0AF4 7F0BBFC4 00007012 */  mflo  $t6
/* 0F0AF8 7F0BBFC8 01AE7821 */  addu  $t7, $t5, $t6
/* 0F0AFC 7F0BBFCC 448F5000 */  mtc1  $t7, $f10
/* 0F0B00 7F0BBFD0 0C007DF8 */  jal   sqrtf
/* 0F0B04 7F0BBFD4 46805320 */   cvt.s.w $f12, $f10
/* 0F0B08 7F0BBFD8 0FC2D20C */  jal   get_room_data_float2
/* 0F0B0C 7F0BBFDC 46000506 */   mov.s $f20, $f0
/* 0F0B10 7F0BBFE0 02F70019 */  multu $s7, $s7
/* 0F0B14 7F0BBFE4 87A200B4 */  lh    $v0, 0xb4($sp)
/* 0F0B18 7F0BBFE8 46140402 */  mul.s $f16, $f0, $f20
/* 0F0B1C 7F0BBFEC 87A300AE */  lh    $v1, 0xae($sp)
/* 0F0B20 7F0BBFF0 4610D483 */  div.s $f18, $f26, $f16
/* 0F0B24 7F0BBFF4 0000C012 */  mflo  $t8
/* 0F0B28 7F0BBFF8 00000000 */  nop   
/* 0F0B2C 7F0BBFFC 00000000 */  nop   
/* 0F0B30 7F0BC000 00420019 */  multu $v0, $v0
/* 0F0B34 7F0BC004 0000C812 */  mflo  $t9
/* 0F0B38 7F0BC008 03195821 */  addu  $t3, $t8, $t9
/* 0F0B3C 7F0BC00C 00000000 */  nop   
/* 0F0B40 7F0BC010 00630019 */  multu $v1, $v1
/* 0F0B44 7F0BC014 E7B200A4 */  swc1  $f18, 0xa4($sp)
/* 0F0B48 7F0BC018 00006012 */  mflo  $t4
/* 0F0B4C 7F0BC01C 016C6821 */  addu  $t5, $t3, $t4
/* 0F0B50 7F0BC020 448D2000 */  mtc1  $t5, $f4
/* 0F0B54 7F0BC024 0C007DF8 */  jal   sqrtf
/* 0F0B58 7F0BC028 46802320 */   cvt.s.w $f12, $f4
/* 0F0B5C 7F0BC02C 0FC2D20C */  jal   get_room_data_float2
/* 0F0B60 7F0BC030 46000506 */   mov.s $f20, $f0
/* 0F0B64 7F0BC034 46140182 */  mul.s $f6, $f0, $f20
/* 0F0B68 7F0BC038 86440000 */  lh    $a0, ($s2)
/* 0F0B6C 7F0BC03C 27A50094 */  addiu $a1, $sp, 0x94
/* 0F0B70 7F0BC040 4606D203 */  div.s $f8, $f26, $f6
/* 0F0B74 7F0BC044 0FC2F28D */  jal   sub_GAME_7F0BCA34
/* 0F0B78 7F0BC048 E7A800A0 */   swc1  $f8, 0xa0($sp)
/* 0F0B7C 7F0BC04C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F0B80 7F0BC050 4481C000 */  mtc1  $at, $f24
/* 0F0B84 7F0BC054 4480B000 */  mtc1  $zero, $f22
/* 0F0B88 7F0BC058 00000000 */  nop   
/* 0F0B8C 7F0BC05C 4618B03C */  c.lt.s $f22, $f24
/* 0F0B90 7F0BC060 4600B506 */  mov.s $f20, $f22
/* 0F0B94 7F0BC064 45020039 */  bc1fl .L7F0BC14C
/* 0F0B98 7F0BC068 4618B03C */   c.lt.s $f22, $f24
/* 0F0B9C 7F0BC06C 44905000 */  mtc1  $s0, $f10
/* 0F0BA0 7F0BC070 44919000 */  mtc1  $s1, $f18
/* 0F0BA4 7F0BC074 44933000 */  mtc1  $s3, $f6
/* 0F0BA8 7F0BC078 46805420 */  cvt.s.w $f16, $f10
/* 0F0BAC 7F0BC07C 27B00088 */  addiu $s0, $sp, 0x88
/* 0F0BB0 7F0BC080 46809120 */  cvt.s.w $f4, $f18
/* 0F0BB4 7F0BC084 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0F0BB8 7F0BC088 46803220 */  cvt.s.w $f8, $f6
/* 0F0BBC 7F0BC08C E7A40068 */  swc1  $f4, 0x68($sp)
/* 0F0BC0 7F0BC090 E7A80064 */  swc1  $f8, 0x64($sp)
.L7F0BC094:
/* 0F0BC4 7F0BC094 0FC2D20C */  jal   get_room_data_float2
/* 0F0BC8 7F0BC098 00000000 */   nop   
/* 0F0BCC 7F0BC09C 87A500E8 */  lh    $a1, 0xe8($sp)
/* 0F0BD0 7F0BC0A0 C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0F0BD4 7F0BC0A4 44855000 */  mtc1  $a1, $f10
/* 0F0BD8 7F0BC0A8 46149102 */  mul.s $f4, $f18, $f20
/* 0F0BDC 7F0BC0AC 46805420 */  cvt.s.w $f16, $f10
/* 0F0BE0 7F0BC0B0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 0F0BE4 7F0BC0B4 46048180 */  add.s $f6, $f16, $f4
/* 0F0BE8 7F0BC0B8 46003202 */  mul.s $f8, $f6, $f0
/* 0F0BEC 7F0BC0BC 46085480 */  add.s $f18, $f10, $f8
/* 0F0BF0 7F0BC0C0 0FC2D20C */  jal   get_room_data_float2
/* 0F0BF4 7F0BC0C4 E7B20088 */   swc1  $f18, 0x88($sp)
/* 0F0BF8 7F0BC0C8 87A700EA */  lh    $a3, 0xea($sp)
/* 0F0BFC 7F0BC0CC C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0F0C00 7F0BC0D0 44878000 */  mtc1  $a3, $f16
/* 0F0C04 7F0BC0D4 46143282 */  mul.s $f10, $f6, $f20
/* 0F0C08 7F0BC0D8 46808120 */  cvt.s.w $f4, $f16
/* 0F0C0C 7F0BC0DC C7B00098 */  lwc1  $f16, 0x98($sp)
/* 0F0C10 7F0BC0E0 460A2200 */  add.s $f8, $f4, $f10
/* 0F0C14 7F0BC0E4 46004482 */  mul.s $f18, $f8, $f0
/* 0F0C18 7F0BC0E8 46128180 */  add.s $f6, $f16, $f18
/* 0F0C1C 7F0BC0EC 0FC2D20C */  jal   get_room_data_float2
/* 0F0C20 7F0BC0F0 E7A6008C */   swc1  $f6, 0x8c($sp)
/* 0F0C24 7F0BC0F4 87A900EC */  lh    $t1, 0xec($sp)
/* 0F0C28 7F0BC0F8 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0F0C2C 7F0BC0FC 4405B000 */  mfc1  $a1, $f22
/* 0F0C30 7F0BC100 44892000 */  mtc1  $t1, $f4
/* 0F0C34 7F0BC104 46144402 */  mul.s $f16, $f8, $f20
/* 0F0C38 7F0BC108 4406D000 */  mfc1  $a2, $f26
/* 0F0C3C 7F0BC10C 02002025 */  move  $a0, $s0
/* 0F0C40 7F0BC110 468022A0 */  cvt.s.w $f10, $f4
/* 0F0C44 7F0BC114 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0F0C48 7F0BC118 46105480 */  add.s $f18, $f10, $f16
/* 0F0C4C 7F0BC11C 46009182 */  mul.s $f6, $f18, $f0
/* 0F0C50 7F0BC120 46062200 */  add.s $f8, $f4, $f6
/* 0F0C54 7F0BC124 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0C58 7F0BC128 E7A80090 */   swc1  $f8, 0x90($sp)
/* 0F0C5C 7F0BC12C C7AA00A8 */  lwc1  $f10, 0xa8($sp)
/* 0F0C60 7F0BC130 460AA500 */  add.s $f20, $f20, $f10
/* 0F0C64 7F0BC134 4618A03C */  c.lt.s $f20, $f24
/* 0F0C68 7F0BC138 00000000 */  nop   
/* 0F0C6C 7F0BC13C 4501FFD5 */  bc1t  .L7F0BC094
/* 0F0C70 7F0BC140 00000000 */   nop   
/* 0F0C74 7F0BC144 4600B506 */  mov.s $f20, $f22
/* 0F0C78 7F0BC148 4618B03C */  c.lt.s $f22, $f24
.L7F0BC14C:
/* 0F0C7C 7F0BC14C 27B00088 */  addiu $s0, $sp, 0x88
/* 0F0C80 7F0BC150 45020038 */  bc1fl .L7F0BC234
/* 0F0C84 7F0BC154 4618B03C */   c.lt.s $f22, $f24
/* 0F0C88 7F0BC158 44948000 */  mtc1  $s4, $f16
/* 0F0C8C 7F0BC15C 44952000 */  mtc1  $s5, $f4
/* 0F0C90 7F0BC160 44964000 */  mtc1  $s6, $f8
/* 0F0C94 7F0BC164 468084A0 */  cvt.s.w $f18, $f16
/* 0F0C98 7F0BC168 468021A0 */  cvt.s.w $f6, $f4
/* 0F0C9C 7F0BC16C E7B2006C */  swc1  $f18, 0x6c($sp)
/* 0F0CA0 7F0BC170 468042A0 */  cvt.s.w $f10, $f8
/* 0F0CA4 7F0BC174 E7A60068 */  swc1  $f6, 0x68($sp)
/* 0F0CA8 7F0BC178 E7AA0064 */  swc1  $f10, 0x64($sp)
.L7F0BC17C:
/* 0F0CAC 7F0BC17C 0FC2D20C */  jal   get_room_data_float2
/* 0F0CB0 7F0BC180 00000000 */   nop   
/* 0F0CB4 7F0BC184 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0CB8 7F0BC188 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 0F0CBC 7F0BC18C 44868000 */  mtc1  $a2, $f16
/* 0F0CC0 7F0BC190 46142182 */  mul.s $f6, $f4, $f20
/* 0F0CC4 7F0BC194 468084A0 */  cvt.s.w $f18, $f16
/* 0F0CC8 7F0BC198 C7B00094 */  lwc1  $f16, 0x94($sp)
/* 0F0CCC 7F0BC19C 46069200 */  add.s $f8, $f18, $f6
/* 0F0CD0 7F0BC1A0 46004282 */  mul.s $f10, $f8, $f0
/* 0F0CD4 7F0BC1A4 460A8100 */  add.s $f4, $f16, $f10
/* 0F0CD8 7F0BC1A8 0FC2D20C */  jal   get_room_data_float2
/* 0F0CDC 7F0BC1AC E7A40088 */   swc1  $f4, 0x88($sp)
/* 0F0CE0 7F0BC1B0 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0CE4 7F0BC1B4 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0F0CE8 7F0BC1B8 44889000 */  mtc1  $t0, $f18
/* 0F0CEC 7F0BC1BC 46144402 */  mul.s $f16, $f8, $f20
/* 0F0CF0 7F0BC1C0 468091A0 */  cvt.s.w $f6, $f18
/* 0F0CF4 7F0BC1C4 C7B20098 */  lwc1  $f18, 0x98($sp)
/* 0F0CF8 7F0BC1C8 46103280 */  add.s $f10, $f6, $f16
/* 0F0CFC 7F0BC1CC 46005102 */  mul.s $f4, $f10, $f0
/* 0F0D00 7F0BC1D0 46049200 */  add.s $f8, $f18, $f4
/* 0F0D04 7F0BC1D4 0FC2D20C */  jal   get_room_data_float2
/* 0F0D08 7F0BC1D8 E7A8008C */   swc1  $f8, 0x8c($sp)
/* 0F0D0C 7F0BC1DC 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0D10 7F0BC1E0 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0F0D14 7F0BC1E4 4405B000 */  mfc1  $a1, $f22
/* 0F0D18 7F0BC1E8 448A3000 */  mtc1  $t2, $f6
/* 0F0D1C 7F0BC1EC 46145482 */  mul.s $f18, $f10, $f20
/* 0F0D20 7F0BC1F0 4406D000 */  mfc1  $a2, $f26
/* 0F0D24 7F0BC1F4 02002025 */  move  $a0, $s0
/* 0F0D28 7F0BC1F8 46803420 */  cvt.s.w $f16, $f6
/* 0F0D2C 7F0BC1FC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0F0D30 7F0BC200 46128100 */  add.s $f4, $f16, $f18
/* 0F0D34 7F0BC204 46002202 */  mul.s $f8, $f4, $f0
/* 0F0D38 7F0BC208 46083280 */  add.s $f10, $f6, $f8
/* 0F0D3C 7F0BC20C 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0D40 7F0BC210 E7AA0090 */   swc1  $f10, 0x90($sp)
/* 0F0D44 7F0BC214 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0F0D48 7F0BC218 4610A500 */  add.s $f20, $f20, $f16
/* 0F0D4C 7F0BC21C 4618A03C */  c.lt.s $f20, $f24
/* 0F0D50 7F0BC220 00000000 */  nop   
/* 0F0D54 7F0BC224 4501FFD5 */  bc1t  .L7F0BC17C
/* 0F0D58 7F0BC228 00000000 */   nop   
/* 0F0D5C 7F0BC22C 4600B506 */  mov.s $f20, $f22
/* 0F0D60 7F0BC230 4618B03C */  c.lt.s $f22, $f24
.L7F0BC234:
/* 0F0D64 7F0BC234 00000000 */  nop   
/* 0F0D68 7F0BC238 45020039 */  bc1fl .L7F0BC320
/* 0F0D6C 7F0BC23C 8E530004 */   lw    $s3, 4($s2)
/* 0F0D70 7F0BC240 87AE00B4 */  lh    $t6, 0xb4($sp)
/* 0F0D74 7F0BC244 87AF00AE */  lh    $t7, 0xae($sp)
/* 0F0D78 7F0BC248 44979000 */  mtc1  $s7, $f18
/* 0F0D7C 7F0BC24C 448E3000 */  mtc1  $t6, $f6
/* 0F0D80 7F0BC250 448F5000 */  mtc1  $t7, $f10
/* 0F0D84 7F0BC254 46809120 */  cvt.s.w $f4, $f18
/* 0F0D88 7F0BC258 46803220 */  cvt.s.w $f8, $f6
/* 0F0D8C 7F0BC25C E7A4006C */  swc1  $f4, 0x6c($sp)
/* 0F0D90 7F0BC260 46805420 */  cvt.s.w $f16, $f10
/* 0F0D94 7F0BC264 E7A80068 */  swc1  $f8, 0x68($sp)
/* 0F0D98 7F0BC268 E7B00064 */  swc1  $f16, 0x64($sp)
.L7F0BC26C:
/* 0F0D9C 7F0BC26C 0FC2D20C */  jal   get_room_data_float2
/* 0F0DA0 7F0BC270 00000000 */   nop   
/* 0F0DA4 7F0BC274 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0DA8 7F0BC278 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0F0DAC 7F0BC27C 44869000 */  mtc1  $a2, $f18
/* 0F0DB0 7F0BC280 46143202 */  mul.s $f8, $f6, $f20
/* 0F0DB4 7F0BC284 46809120 */  cvt.s.w $f4, $f18
/* 0F0DB8 7F0BC288 C7B20094 */  lwc1  $f18, 0x94($sp)
/* 0F0DBC 7F0BC28C 46082280 */  add.s $f10, $f4, $f8
/* 0F0DC0 7F0BC290 46005402 */  mul.s $f16, $f10, $f0
/* 0F0DC4 7F0BC294 46109180 */  add.s $f6, $f18, $f16
/* 0F0DC8 7F0BC298 0FC2D20C */  jal   get_room_data_float2
/* 0F0DCC 7F0BC29C E7A60088 */   swc1  $f6, 0x88($sp)
/* 0F0DD0 7F0BC2A0 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0DD4 7F0BC2A4 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0F0DD8 7F0BC2A8 44882000 */  mtc1  $t0, $f4
/* 0F0DDC 7F0BC2AC 46145482 */  mul.s $f18, $f10, $f20
/* 0F0DE0 7F0BC2B0 46802220 */  cvt.s.w $f8, $f4
/* 0F0DE4 7F0BC2B4 C7A40098 */  lwc1  $f4, 0x98($sp)
/* 0F0DE8 7F0BC2B8 46124400 */  add.s $f16, $f8, $f18
/* 0F0DEC 7F0BC2BC 46008182 */  mul.s $f6, $f16, $f0
/* 0F0DF0 7F0BC2C0 46062280 */  add.s $f10, $f4, $f6
/* 0F0DF4 7F0BC2C4 0FC2D20C */  jal   get_room_data_float2
/* 0F0DF8 7F0BC2C8 E7AA008C */   swc1  $f10, 0x8c($sp)
/* 0F0DFC 7F0BC2CC 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0E00 7F0BC2D0 C7B00064 */  lwc1  $f16, 0x64($sp)
/* 0F0E04 7F0BC2D4 4405B000 */  mfc1  $a1, $f22
/* 0F0E08 7F0BC2D8 448A4000 */  mtc1  $t2, $f8
/* 0F0E0C 7F0BC2DC 46148102 */  mul.s $f4, $f16, $f20
/* 0F0E10 7F0BC2E0 4406D000 */  mfc1  $a2, $f26
/* 0F0E14 7F0BC2E4 02002025 */  move  $a0, $s0
/* 0F0E18 7F0BC2E8 468044A0 */  cvt.s.w $f18, $f8
/* 0F0E1C 7F0BC2EC C7A8009C */  lwc1  $f8, 0x9c($sp)
/* 0F0E20 7F0BC2F0 46049180 */  add.s $f6, $f18, $f4
/* 0F0E24 7F0BC2F4 46003282 */  mul.s $f10, $f6, $f0
/* 0F0E28 7F0BC2F8 460A4400 */  add.s $f16, $f8, $f10
/* 0F0E2C 7F0BC2FC 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0E30 7F0BC300 E7B00090 */   swc1  $f16, 0x90($sp)
/* 0F0E34 7F0BC304 C7B200A0 */  lwc1  $f18, 0xa0($sp)
/* 0F0E38 7F0BC308 4612A500 */  add.s $f20, $f20, $f18
/* 0F0E3C 7F0BC30C 4618A03C */  c.lt.s $f20, $f24
/* 0F0E40 7F0BC310 00000000 */  nop   
/* 0F0E44 7F0BC314 4501FFD5 */  bc1t  .L7F0BC26C
/* 0F0E48 7F0BC318 00000000 */   nop   
/* 0F0E4C 7F0BC31C 8E530004 */  lw    $s3, 4($s2)
.L7F0BC320:
/* 0F0E50 7F0BC320 8E430008 */  lw    $v1, 8($s2)
/* 0F0E54 7F0BC324 24170004 */  li    $s7, 4
/* 0F0E58 7F0BC328 27B600C8 */  addiu $s6, $sp, 0xc8
/* 0F0E5C 7F0BC32C 0263082B */  sltu  $at, $s3, $v1
/* 0F0E60 7F0BC330 10200055 */  beqz  $at, .L7F0BC488
/* 0F0E64 7F0BC334 27B500D0 */   addiu $s5, $sp, 0xd0
/* 0F0E68 7F0BC338 27B400D8 */  addiu $s4, $sp, 0xd8
/* 0F0E6C 7F0BC33C 82620000 */  lb    $v0, ($s3)
.L7F0BC340:
/* 0F0E70 7F0BC340 2401FFBF */  li    $at, -65
/* 0F0E74 7F0BC344 00008025 */  move  $s0, $zero
/* 0F0E78 7F0BC348 14410020 */  bne   $v0, $at, .L7F0BC3CC
/* 0F0E7C 7F0BC34C 02602025 */   move  $a0, $s3
/* 0F0E80 7F0BC350 00002825 */  move  $a1, $zero
/* 0F0E84 7F0BC354 86460000 */  lh    $a2, ($s2)
/* 0F0E88 7F0BC358 02803825 */  move  $a3, $s4
/* 0F0E8C 7F0BC35C AFB50010 */  sw    $s5, 0x10($sp)
/* 0F0E90 7F0BC360 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F0E94 7F0BC364 AFB60014 */   sw    $s6, 0x14($sp)
/* 0F0E98 7F0BC368 02802025 */  move  $a0, $s4
/* 0F0E9C 7F0BC36C 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0EA0 7F0BC370 86450000 */   lh    $a1, ($s2)
/* 0F0EA4 7F0BC374 10400003 */  beqz  $v0, .L7F0BC384
/* 0F0EA8 7F0BC378 02A02025 */   move  $a0, $s5
/* 0F0EAC 7F0BC37C 1000000C */  b     .L7F0BC3B0
/* 0F0EB0 7F0BC380 24100001 */   li    $s0, 1
.L7F0BC384:
/* 0F0EB4 7F0BC384 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0EB8 7F0BC388 86450000 */   lh    $a1, ($s2)
/* 0F0EBC 7F0BC38C 10400003 */  beqz  $v0, .L7F0BC39C
/* 0F0EC0 7F0BC390 02C02025 */   move  $a0, $s6
/* 0F0EC4 7F0BC394 10000006 */  b     .L7F0BC3B0
/* 0F0EC8 7F0BC398 24100001 */   li    $s0, 1
.L7F0BC39C:
/* 0F0ECC 7F0BC39C 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0ED0 7F0BC3A0 86450000 */   lh    $a1, ($s2)
/* 0F0ED4 7F0BC3A4 10400002 */  beqz  $v0, .L7F0BC3B0
/* 0F0ED8 7F0BC3A8 00000000 */   nop   
/* 0F0EDC 7F0BC3AC 24100001 */  li    $s0, 1
.L7F0BC3B0:
/* 0F0EE0 7F0BC3B0 12000004 */  beqz  $s0, .L7F0BC3C4
/* 0F0EE4 7F0BC3B4 02602025 */   move  $a0, $s3
/* 0F0EE8 7F0BC3B8 00002825 */  move  $a1, $zero
/* 0F0EEC 7F0BC3BC 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F0EF0 7F0BC3C0 86460000 */   lh    $a2, ($s2)
.L7F0BC3C4:
/* 0F0EF4 7F0BC3C4 10000027 */  b     .L7F0BC464
/* 0F0EF8 7F0BC3C8 8E430008 */   lw    $v1, 8($s2)
.L7F0BC3CC:
/* 0F0EFC 7F0BC3CC 2401FFB1 */  li    $at, -79
/* 0F0F00 7F0BC3D0 14410024 */  bne   $v0, $at, .L7F0BC464
/* 0F0F04 7F0BC3D4 00001025 */   move  $v0, $zero
.L7F0BC3D8:
/* 0F0F08 7F0BC3D8 24510001 */  addiu $s1, $v0, 1
/* 0F0F0C 7F0BC3DC 00008025 */  move  $s0, $zero
/* 0F0F10 7F0BC3E0 02202825 */  move  $a1, $s1
/* 0F0F14 7F0BC3E4 02602025 */  move  $a0, $s3
/* 0F0F18 7F0BC3E8 86460000 */  lh    $a2, ($s2)
/* 0F0F1C 7F0BC3EC 02803825 */  move  $a3, $s4
/* 0F0F20 7F0BC3F0 AFB50010 */  sw    $s5, 0x10($sp)
/* 0F0F24 7F0BC3F4 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F0F28 7F0BC3F8 AFB60014 */   sw    $s6, 0x14($sp)
/* 0F0F2C 7F0BC3FC 02802025 */  move  $a0, $s4
/* 0F0F30 7F0BC400 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F34 7F0BC404 86450000 */   lh    $a1, ($s2)
/* 0F0F38 7F0BC408 10400003 */  beqz  $v0, .L7F0BC418
/* 0F0F3C 7F0BC40C 02A02025 */   move  $a0, $s5
/* 0F0F40 7F0BC410 1000000C */  b     .L7F0BC444
/* 0F0F44 7F0BC414 24100001 */   li    $s0, 1
.L7F0BC418:
/* 0F0F48 7F0BC418 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F4C 7F0BC41C 86450000 */   lh    $a1, ($s2)
/* 0F0F50 7F0BC420 10400003 */  beqz  $v0, .L7F0BC430
/* 0F0F54 7F0BC424 02C02025 */   move  $a0, $s6
/* 0F0F58 7F0BC428 10000006 */  b     .L7F0BC444
/* 0F0F5C 7F0BC42C 24100001 */   li    $s0, 1
.L7F0BC430:
/* 0F0F60 7F0BC430 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F64 7F0BC434 86450000 */   lh    $a1, ($s2)
/* 0F0F68 7F0BC438 10400002 */  beqz  $v0, .L7F0BC444
/* 0F0F6C 7F0BC43C 00000000 */   nop   
/* 0F0F70 7F0BC440 24100001 */  li    $s0, 1
.L7F0BC444:
/* 0F0F74 7F0BC444 12000004 */  beqz  $s0, .L7F0BC458
/* 0F0F78 7F0BC448 02602025 */   move  $a0, $s3
/* 0F0F7C 7F0BC44C 02202825 */  move  $a1, $s1
/* 0F0F80 7F0BC450 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F0F84 7F0BC454 86460000 */   lh    $a2, ($s2)
.L7F0BC458:
/* 0F0F88 7F0BC458 1637FFDF */  bne   $s1, $s7, .L7F0BC3D8
/* 0F0F8C 7F0BC45C 02201025 */   move  $v0, $s1
/* 0F0F90 7F0BC460 8E430008 */  lw    $v1, 8($s2)
.L7F0BC464:
/* 0F0F94 7F0BC464 26730008 */  addiu $s3, $s3, 8
/* 0F0F98 7F0BC468 0263082B */  sltu  $at, $s3, $v1
/* 0F0F9C 7F0BC46C 5420FFB4 */  bnezl $at, .L7F0BC340
/* 0F0FA0 7F0BC470 82620000 */   lb    $v0, ($s3)
/* 0F0FA4 7F0BC474 10000005 */  b     .L7F0BC48C
/* 0F0FA8 7F0BC478 8FBF005C */   lw    $ra, 0x5c($sp)
.L7F0BC47C:
/* 0F0FAC 7F0BC47C 2652000C */  addiu $s2, $s2, 0xc
.L7F0BC480:
/* 0F0FB0 7F0BC480 5642FE78 */  bnel  $s2, $v0, .L7F0BBE64
/* 0F0FB4 7F0BC484 86460000 */   lh    $a2, ($s2)
.L7F0BC488:
/* 0F0FB8 7F0BC488 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F0BC48C:
/* 0F0FBC 7F0BC48C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F0FC0 7F0BC490 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0F0FC4 7F0BC494 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0F0FC8 7F0BC498 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0F0FCC 7F0BC49C 8FB0003C */  lw    $s0, 0x3c($sp)
/* 0F0FD0 7F0BC4A0 8FB10040 */  lw    $s1, 0x40($sp)
/* 0F0FD4 7F0BC4A4 8FB20044 */  lw    $s2, 0x44($sp)
/* 0F0FD8 7F0BC4A8 8FB30048 */  lw    $s3, 0x48($sp)
/* 0F0FDC 7F0BC4AC 8FB4004C */  lw    $s4, 0x4c($sp)
/* 0F0FE0 7F0BC4B0 8FB50050 */  lw    $s5, 0x50($sp)
/* 0F0FE4 7F0BC4B4 8FB60054 */  lw    $s6, 0x54($sp)
/* 0F0FE8 7F0BC4B8 8FB70058 */  lw    $s7, 0x58($sp)
/* 0F0FEC 7F0BC4BC 03E00008 */  jr    $ra
/* 0F0FF0 7F0BC4C0 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif




#ifdef NONMATCHING//
void sub_GAME_7F0BC4C4(u16 arg0)
{
    s32 i;

    for (i=0;i<cur_entry_lightfixture_table;i= i+4)
    {
        if (arg0 == light_fixture_table[i].index)
        {
            light_fixture_table[i].index = 0;
        }
        if (arg0 == light_fixture_table[i+1].index)
        {
            light_fixture_table[i+1].index = 0;
        }
        if (arg0 == light_fixture_table[i+2].index)
        {
            light_fixture_table[i+2].index = 0;
        }
        if (arg0 == light_fixture_table[i+3].index)
        {
            light_fixture_table[i+3].index = 0;
        }
    }
    index_of_cur_entry_lightfixture_table = arg0;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC4C4
/* 0F0FF4 7F0BC4C4 3C038008 */  lui   $v1, %hi(light_fixture_table)
/* 0F0FF8 7F0BC4C8 3C028008 */  lui   $v0, %hi(cur_entry_lightfixture_table)
/* 0F0FFC 7F0BC4CC 24422B10 */  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
/* 0F1000 7F0BC4D0 24632660 */  addiu $v1, %lo(light_fixture_table) # addiu $v1, $v1, 0x2660
/* 0F1004 7F0BC4D4 846E0000 */  lh    $t6, ($v1)
.L7F0BC4D8:
/* 0F1008 7F0BC4D8 548E0003 */  bnel  $a0, $t6, .L7F0BC4E8
/* 0F100C 7F0BC4DC 846F000C */   lh    $t7, 0xc($v1)
/* 0F1010 7F0BC4E0 A4600000 */  sh    $zero, ($v1)
/* 0F1014 7F0BC4E4 846F000C */  lh    $t7, 0xc($v1)
.L7F0BC4E8:
/* 0F1018 7F0BC4E8 548F0003 */  bnel  $a0, $t7, .L7F0BC4F8
/* 0F101C 7F0BC4EC 84780018 */   lh    $t8, 0x18($v1)
/* 0F1020 7F0BC4F0 A460000C */  sh    $zero, 0xc($v1)
/* 0F1024 7F0BC4F4 84780018 */  lh    $t8, 0x18($v1)
.L7F0BC4F8:
/* 0F1028 7F0BC4F8 54980003 */  bnel  $a0, $t8, .L7F0BC508
/* 0F102C 7F0BC4FC 84790024 */   lh    $t9, 0x24($v1)
/* 0F1030 7F0BC500 A4600018 */  sh    $zero, 0x18($v1)
/* 0F1034 7F0BC504 84790024 */  lh    $t9, 0x24($v1)
.L7F0BC508:
/* 0F1038 7F0BC508 54990003 */  bnel  $a0, $t9, .L7F0BC518
/* 0F103C 7F0BC50C 24630030 */   addiu $v1, $v1, 0x30
/* 0F1040 7F0BC510 A4600024 */  sh    $zero, 0x24($v1)
/* 0F1044 7F0BC514 24630030 */  addiu $v1, $v1, 0x30
.L7F0BC518:
/* 0F1048 7F0BC518 5462FFEF */  bnel  $v1, $v0, .L7F0BC4D8
/* 0F104C 7F0BC51C 846E0000 */   lh    $t6, ($v1)
/* 0F1050 7F0BC520 3C018008 */  lui   $at, %hi(index_of_cur_entry_lightfixture_table)
/* 0F1054 7F0BC524 03E00008 */  jr    $ra
/* 0F1058 7F0BC528 A4242B12 */   sh    $a0, %lo(index_of_cur_entry_lightfixture_table)($at)
)
#endif


