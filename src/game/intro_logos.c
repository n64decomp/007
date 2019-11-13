#include "ultra64.h"
#include "bondgame.h"
#include "game/intro_logos.h"

// bss
//CODE.bss:80069550
s32 dword_CODE_bss_80069550;
//CODE.bss:80069554
s32 dword_CODE_bss_80069554;
//CODE.bss:80069558
s32 matrix_buffer_rarelogo_0;
//CODE.bss:8006955C
s32 matrix_buffer_gunbarrel_0;
//CODE.bss:80069560
s32 matrix_buffer_rarelogo_1;
//CODE.bss:80069564
s32 matrix_buffer_rarelogo_2;
//CODE.bss:80069568
s32 matrix_buffer_gunbarrel_1;
//CODE.bss:8006956C
s32 matrix_buffer_intro_backdrop;
//CODE.bss:80069570
s32 matrix_buffer_intro_bond;
//CODE.bss:80069574
s32 x;
//CODE.bss:80069578
s32 y;
//CODE.bss:8006957C
s32 dword_CODE_bss_8006957C;
//CODE.bss:80069580
s32 dword_CODE_bss_80069580;
//CODE.bss:80069584
s32 word_CODE_bss_80069584;
//CODE.bss:80069588
s32 dword_CODE_bss_80069588;
//CODE.bss:8006958C
s32 dword_CODE_bss_8006958C;
//CODE.bss:80069590
s32 virtualaddress;
//CODE.bss:80069594
s32 dword_CODE_bss_80069594;


// data
u32 D_8002A7D0 = 0;
u32 D_8002A7D4 = 0x3000000;
u32 D_8002A7D8 = 0;
u32 D_8002A7DC = 0;
u32 D_8002A7E0 = 0;
u32 D_8002A7E4 = 0;

u32 D_8002A7E8 = 0xFF;
u32 D_8002A7EC = 0xFF;
u32 D_8002A7F0 = 0xFF;
u32 D_8002A7F4 = 0;
u32 D_8002A7F8 = 0;
u32 D_8002A7FC = 0;

u32 D_8002A800 = 1;
u32 D_8002A804 = 3;
u32 D_8002A808 = 0;
u32 D_8002A80C = 0;
u32 D_8002A810 = 0;
u32 D_8002A814 = 0;
u32 D_8002A818 = 0;
u32 D_8002A81C = 0;
u32 D_8002A820 = 0;
u32 D_8002A824 = 0;
u32 D_8002A828 = 0;
u32 D_8002A82C = 0;
u32 D_8002A830 = 0;
u32 D_8002A834 = 0;
u32 D_8002A838 = 0;
f32 D_8002A83C = 1758.2957f;
f32 D_8002A840 = 220.0f;
f32 D_8002A844 = 684.28143f;
f32 D_8002A848 = -0.97f;
u32 D_8002A84C = 0;
f32 D_8002A850 = 0.24f;
u32 D_8002A854 = 0;
f32 D_8002A858 = 1.0f;
u32 D_8002A85C = 0x80000000;
struct rgba_val D_8002A860 = {0xDC, 0xDC, 0xDC, 0};
struct rgba_val D_8002A864 = {0xDC, 0xDC, 0xDC, 0};
struct rgba_val D_8002A868 = {0xFF, 0xFF, 0xFF, 0};
struct rgba_val D_8002A86C = {0xFF, 0xFF, 0xFF, 0};
struct rgba_val D_8002A870 = {0x00, 0x7F, 0x00, 0};
u32 D_8002A874 = 0;

u32 D_8002A878 =  0;
u32 D_8002A87C =  0;
f32 D_8002A880 =  4883.0f;
u32 D_8002A884 = 0;
u32 D_8002A888 = 0;
f32 D_8002A88C =  -1.0f;
u32 D_8002A890 =  0;
f32 D_8002A894 =  1.0f;
u32 D_8002A898 =  0;


f32 D_8002A89C = 0.0f;
u32 intro_eye_counter = 0;
u32 intro_state_blood_animation = 0;
u32 D_8002A8A8 = 0;
u32 D_8002A8AC = 0;
u32 D_8002A8B0 = 0;
/*
                .word 0
                .word 0
                .word 0
*/



#ifdef NONMATCHING
void something_with_gunbarrel_and_rareware_logo_matrix_manip(void) {

}
#else
GLOBAL_ASM(
.text
glabel something_with_gunbarrel_and_rareware_logo_matrix_manip
/* 03C570 7F007A40 3C0E8003 */  lui   $t6, %hi(D_8002A7D0) 
/* 03C574 7F007A44 8DCEA7D0 */  lw    $t6, %lo(D_8002A7D0)($t6)
/* 03C578 7F007A48 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 03C57C 7F007A4C 3C188007 */  lui   $t8, %hi(matrix_buffer_rarelogo_2) 
/* 03C580 7F007A50 8F189564 */  lw    $t8, %lo(matrix_buffer_rarelogo_2)($t8)
/* 03C584 7F007A54 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C588 7F007A58 00808025 */  move  $s0, $a0
/* 03C58C 7F007A5C AFBF001C */  sw    $ra, 0x1c($sp)
/* 03C590 7F007A60 3C058007 */  lui   $a1, %hi(x)
/* 03C594 7F007A64 3C068007 */  lui   $a2, %hi(y)
/* 03C598 7F007A68 000E7980 */  sll   $t7, $t6, 6
/* 03C59C 7F007A6C 8CC69578 */  lw    $a2, %lo(y)($a2)
/* 03C5A0 7F007A70 8CA59574 */  lw    $a1, %lo(x)($a1)
/* 03C5A4 7F007A74 3C07C0A0 */  lui   $a3, 0xc0a0
/* 03C5A8 7F007A78 0C005B46 */  jal   guTranslate
/* 03C5AC 7F007A7C 01F82021 */   addu  $a0, $t7, $t8
/* 03C5B0 7F007A80 3C198003 */  lui   $t9, %hi(D_8002A7D0) 
/* 03C5B4 7F007A84 8F39A7D0 */  lw    $t9, %lo(D_8002A7D0)($t9)
/* 03C5B8 7F007A88 3C098007 */  lui   $t1, %hi(matrix_buffer_gunbarrel_1) 
/* 03C5BC 7F007A8C 8D299568 */  lw    $t1, %lo(matrix_buffer_gunbarrel_1)($t1)
/* 03C5C0 7F007A90 3C058007 */  lui   $a1, %hi(dword_CODE_bss_8006957C)
/* 03C5C4 7F007A94 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069580)
/* 03C5C8 7F007A98 00194180 */  sll   $t0, $t9, 6
/* 03C5CC 7F007A9C 8CC69580 */  lw    $a2, %lo(dword_CODE_bss_80069580)($a2)
/* 03C5D0 7F007AA0 8CA5957C */  lw    $a1, %lo(dword_CODE_bss_8006957C)($a1)
/* 03C5D4 7F007AA4 3C07C0A0 */  lui   $a3, 0xc0a0
/* 03C5D8 7F007AA8 0C005B46 */  jal   guTranslate
/* 03C5DC 7F007AAC 01092021 */   addu  $a0, $t0, $t1
/* 03C5E0 7F007AB0 3C0B0100 */  lui   $t3, 0x100
/* 03C5E4 7F007AB4 256B0000 */  addiu $t3, $t3, 0
/* 03C5E8 7F007AB8 02001025 */  move  $v0, $s0
/* 03C5EC 7F007ABC 3C0A0600 */  lui   $t2, 0x600
/* 03C5F0 7F007AC0 AC4A0000 */  sw    $t2, ($v0)
/* 03C5F4 7F007AC4 AC4B0004 */  sw    $t3, 4($v0)
/* 03C5F8 7F007AC8 0FC07034 */  jal   insert_imageDL
/* 03C5FC 7F007ACC 26040008 */   addiu $a0, $s0, 8
/* 03C600 7F007AD0 0FC07069 */  jal   sub_GAME_7F01C1A4
/* 03C604 7F007AD4 00402025 */   move  $a0, $v0
/* 03C608 7F007AD8 3C0CFCFF */  lui   $t4, (0xFCFFFFFF >> 16) # lui $t4, 0xfcff
/* 03C60C 7F007ADC 3C0DFFFD */  lui   $t5, (0xFFFDF6FB >> 16) # lui $t5, 0xfffd
/* 03C610 7F007AE0 3C0FE6E6 */  lui   $t7, (0xE6E6E600 >> 16) # lui $t7, 0xe6e6
/* 03C614 7F007AE4 35ADF6FB */  ori   $t5, (0xFFFDF6FB & 0xFFFF) # ori $t5, $t5, 0xf6fb
/* 03C618 7F007AE8 358CFFFF */  ori   $t4, (0xFCFFFFFF & 0xFFFF) # ori $t4, $t4, 0xffff
/* 03C61C 7F007AEC 35EFE600 */  ori   $t7, (0xE6E6E600 & 0xFFFF) # ori $t7, $t7, 0xe600
/* 03C620 7F007AF0 3C0EFA00 */  lui   $t6, 0xfa00
/* 03C624 7F007AF4 3C180600 */  lui   $t8, 0x600
/* 03C628 7F007AF8 AC4C0000 */  sw    $t4, ($v0)
/* 03C62C 7F007AFC AC4D0004 */  sw    $t5, 4($v0)
/* 03C630 7F007B00 AC4E0008 */  sw    $t6, 8($v0)
/* 03C634 7F007B04 AC4F000C */  sw    $t7, 0xc($v0)
/* 03C638 7F007B08 AC580010 */  sw    $t8, 0x10($v0)
/* 03C63C 7F007B0C 3C198007 */  lui   $t9, %hi(dword_CODE_bss_80069554) 
/* 03C640 7F007B10 8F399554 */  lw    $t9, %lo(dword_CODE_bss_80069554)($t9)
/* 03C644 7F007B14 3C018000 */  lui   $at, 0x8000
/* 03C648 7F007B18 24490018 */  addiu $t1, $v0, 0x18
/* 03C64C 7F007B1C 03214021 */  addu  $t0, $t9, $at
/* 03C650 7F007B20 AC480014 */  sw    $t0, 0x14($v0)
/* 03C654 7F007B24 3C0A0102 */  lui   $t2, (0x01020040 >> 16) # lui $t2, 0x102
/* 03C658 7F007B28 354A0040 */  ori   $t2, (0x01020040 & 0xFFFF) # ori $t2, $t2, 0x40
/* 03C65C 7F007B2C AFA90024 */  sw    $t1, 0x24($sp)
/* 03C660 7F007B30 AC4A0018 */  sw    $t2, 0x18($v0)
/* 03C664 7F007B34 3C0B8003 */  lui   $t3, %hi(D_8002A7D0) 
/* 03C668 7F007B38 8D6BA7D0 */  lw    $t3, %lo(D_8002A7D0)($t3)
/* 03C66C 7F007B3C 3C0D8007 */  lui   $t5, %hi(matrix_buffer_gunbarrel_1) 
/* 03C670 7F007B40 8DAD9568 */  lw    $t5, %lo(matrix_buffer_gunbarrel_1)($t5)
/* 03C674 7F007B44 000B6180 */  sll   $t4, $t3, 6
/* 03C678 7F007B48 24500020 */  addiu $s0, $v0, 0x20
/* 03C67C 7F007B4C 0C003A2C */  jal   osVirtualToPhysical
/* 03C680 7F007B50 018D2021 */   addu  $a0, $t4, $t5
/* 03C684 7F007B54 8FAE0024 */  lw    $t6, 0x24($sp)
/* 03C688 7F007B58 02001825 */  move  $v1, $s0
/* 03C68C 7F007B5C 3C0F0600 */  lui   $t7, 0x600
/* 03C690 7F007B60 ADC20004 */  sw    $v0, 4($t6)
/* 03C694 7F007B64 AC6F0000 */  sw    $t7, ($v1)
/* 03C698 7F007B68 3C188007 */  lui   $t8, %hi(dword_CODE_bss_80069554) 
/* 03C69C 7F007B6C 8F189554 */  lw    $t8, %lo(dword_CODE_bss_80069554)($t8)
/* 03C6A0 7F007B70 3C018000 */  lui   $at, 0x8000
/* 03C6A4 7F007B74 26020008 */  addiu $v0, $s0, 8
/* 03C6A8 7F007B78 0301C821 */  addu  $t9, $t8, $at
/* 03C6AC 7F007B7C AC790004 */  sw    $t9, 4($v1)
/* 03C6B0 7F007B80 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03C6B4 7F007B84 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C6B8 7F007B88 27BD0038 */  addiu $sp, $sp, 0x38
/* 03C6BC 7F007B8C 03E00008 */  jr    $ra
/* 03C6C0 7F007B90 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void insert_sight_backdrop_eye_intro(void) {

}
#else
GLOBAL_ASM(
.text
glabel insert_sight_backdrop_eye_intro
/* 03C6C4 7F007B94 3C018007 */  lui   $at, %hi(x)
/* 03C6C8 7F007B98 C4249574 */  lwc1  $f4, %lo(x)($at)
/* 03C6CC 7F007B9C 3C014440 */  li    $at, 0x44400000 # 768.000000
/* 03C6D0 7F007BA0 44813000 */  mtc1  $at, $f6
/* 03C6D4 7F007BA4 3C018007 */  lui   $at, %hi(y)
/* 03C6D8 7F007BA8 C42A9578 */  lwc1  $f10, %lo(y)($at)
/* 03C6DC 7F007BAC 3C014220 */  li    $at, 0x42200000 # 40.000000
/* 03C6E0 7F007BB0 44818000 */  mtc1  $at, $f16
/* 03C6E4 7F007BB4 46062200 */  add.s $f8, $f4, $f6
/* 03C6E8 7F007BB8 3C0E8003 */  lui   $t6, %hi(D_8002A7D0) 
/* 03C6EC 7F007BBC 8DCEA7D0 */  lw    $t6, %lo(D_8002A7D0)($t6)
/* 03C6F0 7F007BC0 46105481 */  sub.s $f18, $f10, $f16
/* 03C6F4 7F007BC4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03C6F8 7F007BC8 3C188007 */  lui   $t8, %hi(matrix_buffer_rarelogo_2) 
/* 03C6FC 7F007BCC 8F189564 */  lw    $t8, %lo(matrix_buffer_rarelogo_2)($t8)
/* 03C700 7F007BD0 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C704 7F007BD4 00808025 */  move  $s0, $a0
/* 03C708 7F007BD8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03C70C 7F007BDC 44069000 */  mfc1  $a2, $f18
/* 03C710 7F007BE0 44054000 */  mfc1  $a1, $f8
/* 03C714 7F007BE4 000E7980 */  sll   $t7, $t6, 6
/* 03C718 7F007BE8 3C07C0A0 */  lui   $a3, 0xc0a0
/* 03C71C 7F007BEC 0C005B46 */  jal   guTranslate
/* 03C720 7F007BF0 01F82021 */   addu  $a0, $t7, $t8
/* 03C724 7F007BF4 3C198003 */  lui   $t9, %hi(D_8002A7D0) 
/* 03C728 7F007BF8 8F39A7D0 */  lw    $t9, %lo(D_8002A7D0)($t9)
/* 03C72C 7F007BFC 3C098007 */  lui   $t1, %hi(matrix_buffer_gunbarrel_1) 
/* 03C730 7F007C00 8D299568 */  lw    $t1, %lo(matrix_buffer_gunbarrel_1)($t1)
/* 03C734 7F007C04 3C05402C */  lui   $a1, (0x402CCCCD >> 16) # lui $a1, 0x402c
/* 03C738 7F007C08 3C064024 */  lui   $a2, (0x40247AE1 >> 16) # lui $a2, 0x4024
/* 03C73C 7F007C0C 00194180 */  sll   $t0, $t9, 6
/* 03C740 7F007C10 34C67AE1 */  ori   $a2, (0x40247AE1 & 0xFFFF) # ori $a2, $a2, 0x7ae1
/* 03C744 7F007C14 34A5CCCD */  ori   $a1, (0x402CCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 03C748 7F007C18 3C073F80 */  lui   $a3, 0x3f80
/* 03C74C 7F007C1C 0C005BB9 */  jal   guScale
/* 03C750 7F007C20 01092021 */   addu  $a0, $t0, $t1
/* 03C754 7F007C24 02001025 */  move  $v0, $s0
/* 03C758 7F007C28 3C0A0100 */  lui   $t2, 0x100
/* 03C75C 7F007C2C 3C050600 */  lui   $a1, 0x600
/* 03C760 7F007C30 254A0000 */  addiu $t2, $t2, 0
/* 03C764 7F007C34 26030008 */  addiu $v1, $s0, 8
/* 03C768 7F007C38 3C0B0100 */  lui   $t3, 0x100
/* 03C76C 7F007C3C AC4A0004 */  sw    $t2, 4($v0)
/* 03C770 7F007C40 AC450000 */  sw    $a1, ($v0)
/* 03C774 7F007C44 256B0040 */  addiu $t3, $t3, 0x40
/* 03C778 7F007C48 AC6B0004 */  sw    $t3, 4($v1)
/* 03C77C 7F007C4C AC650000 */  sw    $a1, ($v1)
/* 03C780 7F007C50 0FC07069 */  jal   sub_GAME_7F01C1A4
/* 03C784 7F007C54 24640008 */   addiu $a0, $v1, 8
/* 03C788 7F007C58 3C0C0100 */  lui   $t4, (0x01000040 >> 16) # lui $t4, 0x100
/* 03C78C 7F007C5C 358C0040 */  ori   $t4, (0x01000040 & 0xFFFF) # ori $t4, $t4, 0x40
/* 03C790 7F007C60 AFA20024 */  sw    $v0, 0x24($sp)
/* 03C794 7F007C64 AC4C0000 */  sw    $t4, ($v0)
/* 03C798 7F007C68 3C0D8003 */  lui   $t5, %hi(D_8002A7D0) 
/* 03C79C 7F007C6C 8DADA7D0 */  lw    $t5, %lo(D_8002A7D0)($t5)
/* 03C7A0 7F007C70 3C0F8007 */  lui   $t7, %hi(matrix_buffer_gunbarrel_1) 
/* 03C7A4 7F007C74 8DEF9568 */  lw    $t7, %lo(matrix_buffer_gunbarrel_1)($t7)
/* 03C7A8 7F007C78 000D7180 */  sll   $t6, $t5, 6
/* 03C7AC 7F007C7C 24500008 */  addiu $s0, $v0, 8
/* 03C7B0 7F007C80 0C003A2C */  jal   osVirtualToPhysical
/* 03C7B4 7F007C84 01CF2021 */   addu  $a0, $t6, $t7
/* 03C7B8 7F007C88 8FB80024 */  lw    $t8, 0x24($sp)
/* 03C7BC 7F007C8C 02001825 */  move  $v1, $s0
/* 03C7C0 7F007C90 3C190600 */  lui   $t9, 0x600
/* 03C7C4 7F007C94 AF020004 */  sw    $v0, 4($t8)
/* 03C7C8 7F007C98 AC790000 */  sw    $t9, ($v1)
/* 03C7CC 7F007C9C 3C088007 */  lui   $t0, %hi(dword_CODE_bss_80069554) 
/* 03C7D0 7F007CA0 8D089554 */  lw    $t0, %lo(dword_CODE_bss_80069554)($t0)
/* 03C7D4 7F007CA4 3C018000 */  lui   $at, 0x8000
/* 03C7D8 7F007CA8 26020008 */  addiu $v0, $s0, 8
/* 03C7DC 7F007CAC 01014821 */  addu  $t1, $t0, $at
/* 03C7E0 7F007CB0 AC690004 */  sw    $t1, 4($v1)
/* 03C7E4 7F007CB4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03C7E8 7F007CB8 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C7EC 7F007CBC 27BD0030 */  addiu $sp, $sp, 0x30
/* 03C7F0 7F007CC0 03E00008 */  jr    $ra
/* 03C7F4 7F007CC4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F007CC8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007CC8
/* 03C7F8 7F007CC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03C7FC 7F007CCC 00801025 */  move  $v0, $a0
/* 03C800 7F007CD0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03C804 7F007CD4 AFA50024 */  sw    $a1, 0x24($sp)
/* 03C808 7F007CD8 AFA60028 */  sw    $a2, 0x28($sp)
/* 03C80C 7F007CDC AFA7002C */  sw    $a3, 0x2c($sp)
/* 03C810 7F007CE0 24840008 */  addiu $a0, $a0, 8
/* 03C814 7F007CE4 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 03C818 7F007CE8 3C0F0F0A */  lui   $t7, (0x0F0A4000 >> 16) # lui $t7, 0xf0a
/* 03C81C 7F007CEC 35EF4000 */  ori   $t7, (0x0F0A4000 & 0xFFFF) # ori $t7, $t7, 0x4000
/* 03C820 7F007CF0 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 03C824 7F007CF4 00801825 */  move  $v1, $a0
/* 03C828 7F007CF8 AC4E0000 */  sw    $t6, ($v0)
/* 03C82C 7F007CFC AC4F0004 */  sw    $t7, 4($v0)
/* 03C830 7F007D00 24840008 */  addiu $a0, $a0, 8
/* 03C834 7F007D04 3C18BA00 */  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
/* 03C838 7F007D08 37181402 */  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
/* 03C83C 7F007D0C 00804025 */  move  $t0, $a0
/* 03C840 7F007D10 AC780000 */  sw    $t8, ($v1)
/* 03C844 7F007D14 AC600004 */  sw    $zero, 4($v1)
/* 03C848 7F007D18 24840008 */  addiu $a0, $a0, 8
/* 03C84C 7F007D1C 3C19BA00 */  lui   $t9, (0xBA001301 >> 16) # lui $t9, 0xba00
/* 03C850 7F007D20 37391301 */  ori   $t9, (0xBA001301 & 0xFFFF) # ori $t9, $t9, 0x1301
/* 03C854 7F007D24 00804825 */  move  $t1, $a0
/* 03C858 7F007D28 AD190000 */  sw    $t9, ($t0)
/* 03C85C 7F007D2C AD000004 */  sw    $zero, 4($t0)
/* 03C860 7F007D30 3C0BBA00 */  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
/* 03C864 7F007D34 356B0C02 */  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
/* 03C868 7F007D38 24840008 */  addiu $a0, $a0, 8
/* 03C86C 7F007D3C AD2B0000 */  sw    $t3, ($t1)
/* 03C870 7F007D40 AD200004 */  sw    $zero, 4($t1)
/* 03C874 7F007D44 00805025 */  move  $t2, $a0
/* 03C878 7F007D48 3C0CE700 */  lui   $t4, 0xe700
/* 03C87C 7F007D4C AD4C0000 */  sw    $t4, ($t2)
/* 03C880 7F007D50 AD400004 */  sw    $zero, 4($t2)
/* 03C884 7F007D54 3C058007 */  lui   $a1, %hi(dword_CODE_bss_8006958C)
/* 03C888 7F007D58 8CA5958C */  lw    $a1, %lo(dword_CODE_bss_8006958C)($a1)
/* 03C88C 7F007D5C 8FAD002C */  lw    $t5, 0x2c($sp)
/* 03C890 7F007D60 3C018000 */  lui   $at, 0x8000
/* 03C894 7F007D64 24840008 */  addiu $a0, $a0, 8
/* 03C898 7F007D68 8FA70028 */  lw    $a3, 0x28($sp)
/* 03C89C 7F007D6C 8FA60024 */  lw    $a2, 0x24($sp)
/* 03C8A0 7F007D70 00A12821 */  addu  $a1, $a1, $at
/* 03C8A4 7F007D74 0FC06C90 */  jal   sub_GAME_7F01B240
/* 03C8A8 7F007D78 AFAD0010 */   sw    $t5, 0x10($sp)
/* 03C8AC 7F007D7C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03C8B0 7F007D80 27BD0020 */  addiu $sp, $sp, 0x20
/* 03C8B4 7F007D84 03E00008 */  jr    $ra
/* 03C8B8 7F007D88 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void insert_sniper_sight_eye_intro(void) {

}
#else
GLOBAL_ASM(
.text
glabel insert_sniper_sight_eye_intro
/* 03C8BC 7F007D8C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 03C8C0 7F007D90 3C0F8003 */  lui   $t7, %hi(D_8002A7DC) 
/* 03C8C4 7F007D94 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03C8C8 7F007D98 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C8CC 7F007D9C 25EFA7DC */  addiu $t7, %lo(D_8002A7DC) # addiu $t7, $t7, -0x5824
/* 03C8D0 7F007DA0 8DE10000 */  lw    $at, ($t7)
/* 03C8D4 7F007DA4 27AE003C */  addiu $t6, $sp, 0x3c
/* 03C8D8 7F007DA8 8DE80004 */  lw    $t0, 4($t7)
/* 03C8DC 7F007DAC ADC10000 */  sw    $at, ($t6)
/* 03C8E0 7F007DB0 8DE10008 */  lw    $at, 8($t7)
/* 03C8E4 7F007DB4 3C0A8003 */  lui   $t2, %hi(D_8002A7E8) 
/* 03C8E8 7F007DB8 254AA7E8 */  addiu $t2, %lo(D_8002A7E8) # addiu $t2, $t2, -0x5818
/* 03C8EC 7F007DBC ADC80004 */  sw    $t0, 4($t6)
/* 03C8F0 7F007DC0 ADC10008 */  sw    $at, 8($t6)
/* 03C8F4 7F007DC4 8D410000 */  lw    $at, ($t2)
/* 03C8F8 7F007DC8 27A90030 */  addiu $t1, $sp, 0x30
/* 03C8FC 7F007DCC 8D4D0004 */  lw    $t5, 4($t2)
/* 03C900 7F007DD0 AD210000 */  sw    $at, ($t1)
/* 03C904 7F007DD4 8D410008 */  lw    $at, 8($t2)
/* 03C908 7F007DD8 3C180100 */  lui   $t8, 0x100
/* 03C90C 7F007DDC AD2D0004 */  sw    $t5, 4($t1)
/* 03C910 7F007DE0 AD210008 */  sw    $at, 8($t1)
/* 03C914 7F007DE4 27180000 */  addiu $t8, $t8, 0
/* 03C918 7F007DE8 3C190600 */  lui   $t9, 0x600
/* 03C91C 7F007DEC AC990000 */  sw    $t9, ($a0)
/* 03C920 7F007DF0 AC980004 */  sw    $t8, 4($a0)
/* 03C924 7F007DF4 24900008 */  addiu $s0, $a0, 8
/* 03C928 7F007DF8 0FC07034 */  jal   insert_imageDL
/* 03C92C 7F007DFC 02002025 */   move  $a0, $s0
/* 03C930 7F007E00 3C0EFC11 */  lui   $t6, (0xFC11FE23 >> 16) # lui $t6, 0xfc11
/* 03C934 7F007E04 35CEFE23 */  ori   $t6, (0xFC11FE23 & 0xFFFF) # ori $t6, $t6, 0xfe23
/* 03C938 7F007E08 240FF7FB */  li    $t7, -2053
/* 03C93C 7F007E0C AC4F0004 */  sw    $t7, 4($v0)
/* 03C940 7F007E10 AC4E0000 */  sw    $t6, ($v0)
/* 03C944 7F007E14 0C001107 */  jal   get_video2_settings_txtClipW
/* 03C948 7F007E18 24500008 */   addiu $s0, $v0, 8
/* 03C94C 7F007E1C 44822000 */  mtc1  $v0, $f4
/* 03C950 7F007E20 3C018007 */  lui   $at, %hi(x)
/* 03C954 7F007E24 C4289574 */  lwc1  $f8, %lo(x)($at)
/* 03C958 7F007E28 468021A0 */  cvt.s.w $f6, $f4
/* 03C95C 7F007E2C 3C0144A0 */  li    $at, 0x44A00000 # 1280.000000
/* 03C960 7F007E30 44818000 */  mtc1  $at, $f16
/* 03C964 7F007E34 46083282 */  mul.s $f10, $f6, $f8
/* 03C968 7F007E38 0FC170D8 */  jal   truncf
/* 03C96C 7F007E3C 46105303 */   div.s $f12, $f10, $f16
/* 03C970 7F007E40 4600048D */  trunc.w.s $f18, $f0
/* 03C974 7F007E44 02002025 */  move  $a0, $s0
/* 03C978 7F007E48 27A6003C */  addiu $a2, $sp, 0x3c
/* 03C97C 7F007E4C 27A70030 */  addiu $a3, $sp, 0x30
/* 03C980 7F007E50 44059000 */  mfc1  $a1, $f18
/* 03C984 7F007E54 0FC01F32 */  jal   sub_GAME_7F007CC8
/* 03C988 7F007E58 00000000 */   nop   
/* 03C98C 7F007E5C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03C990 7F007E60 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C994 7F007E64 27BD0048 */  addiu $sp, $sp, 0x48
/* 03C998 7F007E68 03E00008 */  jr    $ra
/* 03C99C 7F007E6C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F007E70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007E70
/* 03C9A0 7F007E70 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03C9A4 7F007E74 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03C9A8 7F007E78 0FC07069 */  jal   sub_GAME_7F01C1A4
/* 03C9AC 7F007E7C AFA50034 */   sw    $a1, 0x34($sp)
/* 03C9B0 7F007E80 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 03C9B4 7F007E84 3C0F0050 */  lui   $t7, (0x00504340 >> 16) # lui $t7, 0x50
/* 03C9B8 7F007E88 3C18FCFF */  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
/* 03C9BC 7F007E8C 3C19FFFD */  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
/* 03C9C0 7F007E90 35EF4340 */  ori   $t7, (0x00504340 & 0xFFFF) # ori $t7, $t7, 0x4340
/* 03C9C4 7F007E94 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 03C9C8 7F007E98 3739F6FB */  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
/* 03C9CC 7F007E9C 3718FFFF */  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
/* 03C9D0 7F007EA0 3C08FA00 */  lui   $t0, 0xfa00
/* 03C9D4 7F007EA4 AC4E0000 */  sw    $t6, ($v0)
/* 03C9D8 7F007EA8 AC4F0004 */  sw    $t7, 4($v0)
/* 03C9DC 7F007EAC AC580008 */  sw    $t8, 8($v0)
/* 03C9E0 7F007EB0 AC59000C */  sw    $t9, 0xc($v0)
/* 03C9E4 7F007EB4 AC480010 */  sw    $t0, 0x10($v0)
/* 03C9E8 7F007EB8 8FA90034 */  lw    $t1, 0x34($sp)
/* 03C9EC 7F007EBC 3C0BBA00 */  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
/* 03C9F0 7F007EC0 356B0602 */  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
/* 03C9F4 7F007EC4 312A00FF */  andi  $t2, $t1, 0xff
/* 03C9F8 7F007EC8 AC4A0014 */  sw    $t2, 0x14($v0)
/* 03C9FC 7F007ECC AC4B0018 */  sw    $t3, 0x18($v0)
/* 03CA00 7F007ED0 AC40001C */  sw    $zero, 0x1c($v0)
/* 03CA04 7F007ED4 244C0020 */  addiu $t4, $v0, 0x20
/* 03CA08 7F007ED8 244D0028 */  addiu $t5, $v0, 0x28
/* 03CA0C 7F007EDC AFAD0030 */  sw    $t5, 0x30($sp)
/* 03CA10 7F007EE0 0C001107 */  jal   get_video2_settings_txtClipW
/* 03CA14 7F007EE4 AFAC001C */   sw    $t4, 0x1c($sp)
/* 03CA18 7F007EE8 0C00110B */  jal   get_video2_settings_txtClipH
/* 03CA1C 7F007EEC A7A2001A */   sh    $v0, 0x1a($sp)
/* 03CA20 7F007EF0 87B9001A */  lh    $t9, 0x1a($sp)
/* 03CA24 7F007EF4 8FA3001C */  lw    $v1, 0x1c($sp)
/* 03CA28 7F007EF8 304E03FF */  andi  $t6, $v0, 0x3ff
/* 03CA2C 7F007EFC 000E7880 */  sll   $t7, $t6, 2
/* 03CA30 7F007F00 3C01F600 */  lui   $at, 0xf600
/* 03CA34 7F007F04 332803FF */  andi  $t0, $t9, 0x3ff
/* 03CA38 7F007F08 00084B80 */  sll   $t1, $t0, 0xe
/* 03CA3C 7F007F0C 01E1C025 */  or    $t8, $t7, $at
/* 03CA40 7F007F10 03095025 */  or    $t2, $t8, $t1
/* 03CA44 7F007F14 AC6A0000 */  sw    $t2, ($v1)
/* 03CA48 7F007F18 AC600004 */  sw    $zero, 4($v1)
/* 03CA4C 7F007F1C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03CA50 7F007F20 8FA20030 */  lw    $v0, 0x30($sp)
/* 03CA54 7F007F24 27BD0030 */  addiu $sp, $sp, 0x30
/* 03CA58 7F007F28 03E00008 */  jr    $ra
/* 03CA5C 7F007F2C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F007F30(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8004F2D0
.word 0x3f68f5c3
glabel D_8004F2D4
.word 0x461c4000
glabel D_8004F2D8
.word 0x459c4000
glabel D_8004F2DC
.word 0x3f68f5c3
.text
glabel sub_GAME_7F007F30
/* 03CA60 7F007F30 27BDFEE0 */  addiu $sp, $sp, -0x120
/* 03CA64 7F007F34 3C0F8003 */  lui   $t7, %hi(D_8002A7FC) 
/* 03CA68 7F007F38 25EFA7FC */  addiu $t7, %lo(D_8002A7FC) # addiu $t7, $t7, -0x5804
/* 03CA6C 7F007F3C AFBF0034 */  sw    $ra, 0x34($sp)
/* 03CA70 7F007F40 AFB50030 */  sw    $s5, 0x30($sp)
/* 03CA74 7F007F44 AFB4002C */  sw    $s4, 0x2c($sp)
/* 03CA78 7F007F48 AFB30028 */  sw    $s3, 0x28($sp)
/* 03CA7C 7F007F4C AFB20024 */  sw    $s2, 0x24($sp)
/* 03CA80 7F007F50 AFB10020 */  sw    $s1, 0x20($sp)
/* 03CA84 7F007F54 AFB0001C */  sw    $s0, 0x1c($sp)
/* 03CA88 7F007F58 AFA40120 */  sw    $a0, 0x120($sp)
/* 03CA8C 7F007F5C AFA50124 */  sw    $a1, 0x124($sp)
/* 03CA90 7F007F60 AFA60128 */  sw    $a2, 0x128($sp)
/* 03CA94 7F007F64 25E8003C */  addiu $t0, $t7, 0x3c
/* 03CA98 7F007F68 27AE00DC */  addiu $t6, $sp, 0xdc
.L7F007F6C:
/* 03CA9C 7F007F6C 8DE10000 */  lw    $at, ($t7)
/* 03CAA0 7F007F70 25EF000C */  addiu $t7, $t7, 0xc
/* 03CAA4 7F007F74 25CE000C */  addiu $t6, $t6, 0xc
/* 03CAA8 7F007F78 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 03CAAC 7F007F7C 8DE1FFF8 */  lw    $at, -8($t7)
/* 03CAB0 7F007F80 ADC1FFF8 */  sw    $at, -8($t6)
/* 03CAB4 7F007F84 8DE1FFFC */  lw    $at, -4($t7)
/* 03CAB8 7F007F88 15E8FFF8 */  bne   $t7, $t0, .L7F007F6C
/* 03CABC 7F007F8C ADC1FFFC */   sw    $at, -4($t6)
/* 03CAC0 7F007F90 8DE10000 */  lw    $at, ($t7)
/* 03CAC4 7F007F94 0000A825 */  move  $s5, $zero
/* 03CAC8 7F007F98 00009025 */  move  $s2, $zero
/* 03CACC 7F007F9C ADC10000 */  sw    $at, ($t6)
/* 03CAD0 7F007FA0 8FA90124 */  lw    $t1, 0x124($sp)
/* 03CAD4 7F007FA4 19200034 */  blez  $t1, .L7F008078
/* 03CAD8 7F007FA8 3C140000 */   lui   $s4, 0
/* 03CADC 7F007FAC 3C138003 */  lui   $s3, %hi(D_8002A7F4)
/* 03CAE0 7F007FB0 3C108007 */  lui   $s0, %hi(dword_CODE_bss_80069594)
/* 03CAE4 7F007FB4 26109594 */  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x6a6c
/* 03CAE8 7F007FB8 2673A7F4 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
/* 03CAEC 7F007FBC 26944298 */  addiu $s4, $s4, 0x4298
/* 03CAF0 7F007FC0 24110089 */  li    $s1, 137
/* 03CAF4 7F007FC4 8E020000 */  lw    $v0, ($s0)
.L7F007FC8:
/* 03CAF8 7F007FC8 04400019 */  bltz  $v0, .L7F008030
/* 03CAFC 7F007FCC 244A0001 */   addiu $t2, $v0, 1
/* 03CB00 7F007FD0 AE0A0000 */  sw    $t2, ($s0)
/* 03CB04 7F007FD4 162A000F */  bne   $s1, $t2, .L7F008014
/* 03CB08 7F007FD8 01401025 */   move  $v0, $t2
/* 03CB0C 7F007FDC 3C018005 */  lui   $at, %hi(D_8004F2D0)
/* 03CB10 7F007FE0 C424F2D0 */  lwc1  $f4, %lo(D_8004F2D0)($at)
/* 03CB14 7F007FE4 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 03CB18 7F007FE8 3C0B8007 */  lui   $t3, %hi(ptr_animation_table) 
/* 03CB1C 7F007FEC 8D6B9538 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 03CB20 7F007FF0 44813000 */  mtc1  $at, $f6
/* 03CB24 7F007FF4 8E640000 */  lw    $a0, ($s3)
/* 03CB28 7F007FF8 00003025 */  move  $a2, $zero
/* 03CB2C 7F007FFC 3C074000 */  lui   $a3, 0x4000
/* 03CB30 7F008000 E7A40010 */  swc1  $f4, 0x10($sp)
/* 03CB34 7F008004 028B2821 */  addu  $a1, $s4, $t3
/* 03CB38 7F008008 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 03CB3C 7F00800C E7A60014 */   swc1  $f6, 0x14($sp)
/* 03CB40 7F008010 8E020000 */  lw    $v0, ($s0)
.L7F008014:
/* 03CB44 7F008014 240100D4 */  li    $at, 212
/* 03CB48 7F008018 14410005 */  bne   $v0, $at, .L7F008030
/* 03CB4C 7F00801C 3C053FCC */   lui   $a1, (0x3FCCCCCD >> 16) # lui $a1, 0x3fcc
/* 03CB50 7F008020 8E640000 */  lw    $a0, ($s3)
/* 03CB54 7F008024 34A5CCCD */  ori   $a1, (0x3FCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 03CB58 7F008028 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 03CB5C 7F00802C 3C064100 */   lui   $a2, 0x4100
.L7F008030:
/* 03CB60 7F008030 8E640000 */  lw    $a0, ($s3)
/* 03CB64 7F008034 24050001 */  li    $a1, 1
/* 03CB68 7F008038 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 03CB6C 7F00803C 24060001 */   li    $a2, 1
/* 03CB70 7F008040 8E0C0000 */  lw    $t4, ($s0)
/* 03CB74 7F008044 240100E6 */  li    $at, 230
/* 03CB78 7F008048 3C048006 */  lui   $a0, %hi(ptr_sfx_buf)
/* 03CB7C 7F00804C 15810005 */  bne   $t4, $at, .L7F008064
/* 03CB80 7F008050 2405006F */   li    $a1, 111
/* 03CB84 7F008054 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 03CB88 7F008058 00003025 */  move  $a2, $zero
/* 03CB8C 7F00805C 0C002382 */  jal   play_sfx_a1
/* 03CB90 7F008060 24150001 */   li    $s5, 1
.L7F008064:
/* 03CB94 7F008064 8FAD0124 */  lw    $t5, 0x124($sp)
/* 03CB98 7F008068 26520001 */  addiu $s2, $s2, 1
/* 03CB9C 7F00806C 564DFFD6 */  bnel  $s2, $t5, .L7F007FC8
/* 03CBA0 7F008070 8E020000 */   lw    $v0, ($s0)
/* 03CBA4 7F008074 00009025 */  move  $s2, $zero
.L7F008078:
/* 03CBA8 7F008078 3C138003 */  lui   $s3, %hi(D_8002A7F4)
/* 03CBAC 7F00807C 2673A7F4 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
/* 03CBB0 7F008080 0FC1B100 */  jal   set_80036084
/* 03CBB4 7F008084 24040001 */   li    $a0, 1
/* 03CBB8 7F008088 0FC1CFF2 */  jal   sub_GAME_7F073FC8
/* 03CBBC 7F00808C 24040050 */   li    $a0, 80
/* 03CBC0 7F008090 0FC1B5AC */  jal   subcalcpos
/* 03CBC4 7F008094 8E640000 */   lw    $a0, ($s3)
/* 03CBC8 7F008098 3C148003 */  lui   $s4, %hi(D_8002A7F8)
/* 03CBCC 7F00809C 2694A7F8 */  addiu $s4, %lo(D_8002A7F8) # addiu $s4, $s4, -0x5808
/* 03CBD0 7F0080A0 8E860000 */  lw    $a2, ($s4)
/* 03CBD4 7F0080A4 8CD90008 */  lw    $t9, 8($a2)
/* 03CBD8 7F0080A8 8F230008 */  lw    $v1, 8($t9)
/* 03CBDC 7F0080AC 8C650000 */  lw    $a1, ($v1)
/* 03CBE0 7F0080B0 50A00008 */  beql  $a1, $zero, .L7F0080D4
/* 03CBE4 7F0080B4 8C650008 */   lw    $a1, 8($v1)
/* 03CBE8 7F0080B8 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 03CBEC 7F0080BC 00C02025 */   move  $a0, $a2
/* 03CBF0 7F0080C0 A4550000 */  sh    $s5, ($v0)
/* 03CBF4 7F0080C4 8E860000 */  lw    $a2, ($s4)
/* 03CBF8 7F0080C8 8CD80008 */  lw    $t8, 8($a2)
/* 03CBFC 7F0080CC 8F030008 */  lw    $v1, 8($t8)
/* 03CC00 7F0080D0 8C650008 */  lw    $a1, 8($v1)
.L7F0080D4:
/* 03CC04 7F0080D4 50A00005 */  beql  $a1, $zero, .L7F0080EC
/* 03CC08 7F0080D8 8FA80128 */   lw    $t0, 0x128($sp)
/* 03CC0C 7F0080DC 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 03CC10 7F0080E0 00C02025 */   move  $a0, $a2
/* 03CC14 7F0080E4 AC550000 */  sw    $s5, ($v0)
/* 03CC18 7F0080E8 8FA80128 */  lw    $t0, 0x128($sp)
.L7F0080EC:
/* 03CC1C 7F0080EC 8E6F0000 */  lw    $t7, ($s3)
/* 03CC20 7F0080F0 AFA800DC */  sw    $t0, 0xdc($sp)
/* 03CC24 7F0080F4 8DEE0008 */  lw    $t6, 8($t7)
/* 03CC28 7F0080F8 85C4000E */  lh    $a0, 0xe($t6)
/* 03CC2C 7F0080FC 00044980 */  sll   $t1, $a0, 6
/* 03CC30 7F008100 0FC2F5C5 */  jal   sub_GAME_7F0BD714
/* 03CC34 7F008104 01202025 */   move  $a0, $t1
/* 03CC38 7F008108 AFA200EC */  sw    $v0, 0xec($sp)
/* 03CC3C 7F00810C 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CC40 7F008110 0FC1BCBE */  jal   subcalcmatrices
/* 03CC44 7F008114 8E650000 */   lw    $a1, ($s3)
/* 03CC48 7F008118 8E8A0000 */  lw    $t2, ($s4)
/* 03CC4C 7F00811C 8E640000 */  lw    $a0, ($s3)
/* 03CC50 7F008120 00003025 */  move  $a2, $zero
/* 03CC54 7F008124 0FC1B198 */  jal   sub_GAME_7F06C660
/* 03CC58 7F008128 8D45001C */   lw    $a1, 0x1c($t2)
/* 03CC5C 7F00812C 8E8B0000 */  lw    $t3, ($s4)
/* 03CC60 7F008130 AFA200DC */  sw    $v0, 0xdc($sp)
/* 03CC64 7F008134 8D6C0008 */  lw    $t4, 8($t3)
/* 03CC68 7F008138 8584000E */  lh    $a0, 0xe($t4)
/* 03CC6C 7F00813C 00046980 */  sll   $t5, $a0, 6
/* 03CC70 7F008140 0FC2F5C5 */  jal   sub_GAME_7F0BD714
/* 03CC74 7F008144 01A02025 */   move  $a0, $t5
/* 03CC78 7F008148 AFA200EC */  sw    $v0, 0xec($sp)
/* 03CC7C 7F00814C 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CC80 7F008150 0FC1BC92 */  jal   instcalcmatrices
/* 03CC84 7F008154 8E850000 */   lw    $a1, ($s4)
/* 03CC88 7F008158 00002025 */  move  $a0, $zero
/* 03CC8C 7F00815C 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 03CC90 7F008160 8E650000 */   lw    $a1, ($s3)
/* 03CC94 7F008164 00402025 */  move  $a0, $v0
/* 03CC98 7F008168 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 03CC9C 7F00816C 8E850000 */   lw    $a1, ($s4)
/* 03CCA0 7F008170 00408025 */  move  $s0, $v0
/* 03CCA4 7F008174 0FC1ACA7 */  jal   sub_GAME_7F06B29C
/* 03CCA8 7F008178 00402025 */   move  $a0, $v0
/* 03CCAC 7F00817C 0FC1AECA */  jal   sub_GAME_7F06BB28
/* 03CCB0 7F008180 02002025 */   move  $a0, $s0
/* 03CCB4 7F008184 8FB80120 */  lw    $t8, 0x120($sp)
/* 03CCB8 7F008188 24190007 */  li    $t9, 7
/* 03CCBC 7F00818C 24080001 */  li    $t0, 1
/* 03CCC0 7F008190 00408025 */  move  $s0, $v0
/* 03CCC4 7F008194 AFB9010C */  sw    $t9, 0x10c($sp)
/* 03CCC8 7F008198 AFA000E0 */  sw    $zero, 0xe0($sp)
/* 03CCCC 7F00819C AFA800E4 */  sw    $t0, 0xe4($sp)
/* 03CCD0 7F0081A0 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CCD4 7F0081A4 00402825 */  move  $a1, $v0
/* 03CCD8 7F0081A8 0FC1AF03 */  jal   drawjointlist
/* 03CCDC 7F0081AC AFB800E8 */   sw    $t8, 0xe8($sp)
/* 03CCE0 7F0081B0 240F0002 */  li    $t7, 2
/* 03CCE4 7F0081B4 AFAF00E4 */  sw    $t7, 0xe4($sp)
/* 03CCE8 7F0081B8 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CCEC 7F0081BC 0FC1AF03 */  jal   drawjointlist
/* 03CCF0 7F0081C0 02002825 */   move  $a1, $s0
/* 03CCF4 7F0081C4 0FC1B100 */  jal   set_80036084
/* 03CCF8 7F0081C8 00002025 */   move  $a0, $zero
/* 03CCFC 7F0081CC 0FC1AC92 */  jal   sub_GAME_7F06B248
/* 03CD00 7F0081D0 02002025 */   move  $a0, $s0
/* 03CD04 7F0081D4 8E620000 */  lw    $v0, ($s3)
/* 03CD08 7F0081D8 00008025 */  move  $s0, $zero
/* 03CD0C 7F0081DC 27B10088 */  addiu $s1, $sp, 0x88
/* 03CD10 7F0081E0 8C4E0008 */  lw    $t6, 8($v0)
/* 03CD14 7F0081E4 85C9000E */  lh    $t1, 0xe($t6)
/* 03CD18 7F0081E8 59200015 */  blezl $t1, .L7F008240
/* 03CD1C 7F0081EC 8E860000 */   lw    $a2, ($s4)
/* 03CD20 7F0081F0 8C4A000C */  lw    $t2, 0xc($v0)
.L7F0081F4:
/* 03CD24 7F0081F4 02202825 */  move  $a1, $s1
/* 03CD28 7F0081F8 0FC16008 */  jal   sub_GAME_7F058020
/* 03CD2C 7F0081FC 01502021 */   addu  $a0, $t2, $s0
/* 03CD30 7F008200 8E6B0000 */  lw    $t3, ($s3)
/* 03CD34 7F008204 00126980 */  sll   $t5, $s2, 6
/* 03CD38 7F008208 02202025 */  move  $a0, $s1
/* 03CD3C 7F00820C 8D6C000C */  lw    $t4, 0xc($t3)
/* 03CD40 7F008210 0FC16327 */  jal   sub_GAME_7F058C9C
/* 03CD44 7F008214 018D2821 */   addu  $a1, $t4, $t5
/* 03CD48 7F008218 8E620000 */  lw    $v0, ($s3)
/* 03CD4C 7F00821C 26520001 */  addiu $s2, $s2, 1
/* 03CD50 7F008220 26100040 */  addiu $s0, $s0, 0x40
/* 03CD54 7F008224 8C590008 */  lw    $t9, 8($v0)
/* 03CD58 7F008228 8738000E */  lh    $t8, 0xe($t9)
/* 03CD5C 7F00822C 0258082A */  slt   $at, $s2, $t8
/* 03CD60 7F008230 5420FFF0 */  bnezl $at, .L7F0081F4
/* 03CD64 7F008234 8C4A000C */   lw    $t2, 0xc($v0)
/* 03CD68 7F008238 00009025 */  move  $s2, $zero
/* 03CD6C 7F00823C 8E860000 */  lw    $a2, ($s4)
.L7F008240:
/* 03CD70 7F008240 00008025 */  move  $s0, $zero
/* 03CD74 7F008244 27B10048 */  addiu $s1, $sp, 0x48
/* 03CD78 7F008248 8CC80008 */  lw    $t0, 8($a2)
/* 03CD7C 7F00824C 850F000E */  lh    $t7, 0xe($t0)
/* 03CD80 7F008250 59E00014 */  blezl $t7, .L7F0082A4
/* 03CD84 7F008254 8FBF0034 */   lw    $ra, 0x34($sp)
/* 03CD88 7F008258 8CCE000C */  lw    $t6, 0xc($a2)
.L7F00825C:
/* 03CD8C 7F00825C 02202825 */  move  $a1, $s1
/* 03CD90 7F008260 0FC16008 */  jal   sub_GAME_7F058020
/* 03CD94 7F008264 01D02021 */   addu  $a0, $t6, $s0
/* 03CD98 7F008268 8E890000 */  lw    $t1, ($s4)
/* 03CD9C 7F00826C 00125980 */  sll   $t3, $s2, 6
/* 03CDA0 7F008270 02202025 */  move  $a0, $s1
/* 03CDA4 7F008274 8D2A000C */  lw    $t2, 0xc($t1)
/* 03CDA8 7F008278 0FC16327 */  jal   sub_GAME_7F058C9C
/* 03CDAC 7F00827C 014B2821 */   addu  $a1, $t2, $t3
/* 03CDB0 7F008280 8E860000 */  lw    $a2, ($s4)
/* 03CDB4 7F008284 26520001 */  addiu $s2, $s2, 1
/* 03CDB8 7F008288 26100040 */  addiu $s0, $s0, 0x40
/* 03CDBC 7F00828C 8CCC0008 */  lw    $t4, 8($a2)
/* 03CDC0 7F008290 858D000E */  lh    $t5, 0xe($t4)
/* 03CDC4 7F008294 024D082A */  slt   $at, $s2, $t5
/* 03CDC8 7F008298 5420FFF0 */  bnezl $at, .L7F00825C
/* 03CDCC 7F00829C 8CCE000C */   lw    $t6, 0xc($a2)
/* 03CDD0 7F0082A0 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F0082A4:
/* 03CDD4 7F0082A4 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 03CDD8 7F0082A8 8FB0001C */  lw    $s0, 0x1c($sp)
/* 03CDDC 7F0082AC 8FB10020 */  lw    $s1, 0x20($sp)
/* 03CDE0 7F0082B0 8FB20024 */  lw    $s2, 0x24($sp)
/* 03CDE4 7F0082B4 8FB30028 */  lw    $s3, 0x28($sp)
/* 03CDE8 7F0082B8 8FB4002C */  lw    $s4, 0x2c($sp)
/* 03CDEC 7F0082BC 8FB50030 */  lw    $s5, 0x30($sp)
/* 03CDF0 7F0082C0 03E00008 */  jr    $ra
/* 03CDF4 7F0082C4 27BD0120 */   addiu $sp, $sp, 0x120
)
#endif



#ifdef NONMATCHING
void insert_bond_eye_intro(void) {

}
#else
GLOBAL_ASM(
.text
glabel insert_bond_eye_intro
/* 03CDF8 7F0082C8 44800000 */  mtc1  $zero, $f0
/* 03CDFC 7F0082CC 3C0E8003 */  lui   $t6, %hi(D_8002A7D0) 
/* 03CE00 7F0082D0 8DCEA7D0 */  lw    $t6, %lo(D_8002A7D0)($t6)
/* 03CE04 7F0082D4 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 03CE08 7F0082D8 3C188007 */  lui   $t8, %hi(matrix_buffer_intro_backdrop) 
/* 03CE0C 7F0082DC 8F18956C */  lw    $t8, %lo(matrix_buffer_intro_backdrop)($t8)
/* 03CE10 7F0082E0 AFB00030 */  sw    $s0, 0x30($sp)
/* 03CE14 7F0082E4 00808025 */  move  $s0, $a0
/* 03CE18 7F0082E8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 03CE1C 7F0082EC 44050000 */  mfc1  $a1, $f0
/* 03CE20 7F0082F0 44060000 */  mfc1  $a2, $f0
/* 03CE24 7F0082F4 44070000 */  mfc1  $a3, $f0
/* 03CE28 7F0082F8 000E7980 */  sll   $t7, $t6, 6
/* 03CE2C 7F0082FC 0C005B46 */  jal   guTranslate
/* 03CE30 7F008300 01F82021 */   addu  $a0, $t7, $t8
/* 03CE34 7F008304 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 03CE38 7F008308 44812000 */  mtc1  $at, $f4
/* 03CE3C 7F00830C 3C018005 */  lui   $at, %hi(D_8004F2D4)
/* 03CE40 7F008310 3C198003 */  lui   $t9, %hi(D_8002A7D0) 
/* 03CE44 7F008314 8F39A7D0 */  lw    $t9, %lo(D_8002A7D0)($t9)
/* 03CE48 7F008318 C426F2D4 */  lwc1  $f6, %lo(D_8004F2D4)($at)
/* 03CE4C 7F00831C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03CE50 7F008320 3C0C8007 */  lui   $t4, %hi(matrix_buffer_intro_bond) 
/* 03CE54 7F008324 8D8C9570 */  lw    $t4, %lo(matrix_buffer_intro_bond)($t4)
/* 03CE58 7F008328 44814000 */  mtc1  $at, $f8
/* 03CE5C 7F00832C 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 03CE60 7F008330 00195980 */  sll   $t3, $t9, 6
/* 03CE64 7F008334 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 03CE68 7F008338 27A5005E */  addiu $a1, $sp, 0x5e
/* 03CE6C 7F00833C 3C064238 */  lui   $a2, 0x4238
/* 03CE70 7F008340 E7A40010 */  swc1  $f4, 0x10($sp)
/* 03CE74 7F008344 E7A60014 */  swc1  $f6, 0x14($sp)
/* 03CE78 7F008348 016C2021 */  addu  $a0, $t3, $t4
/* 03CE7C 7F00834C 0C003FAC */  jal   guPerspective
/* 03CE80 7F008350 E7A80018 */   swc1  $f8, 0x18($sp)
/* 03CE84 7F008354 3C0DBC00 */  lui   $t5, (0xBC00000E >> 16) # lui $t5, 0xbc00
/* 03CE88 7F008358 35AD000E */  ori   $t5, (0xBC00000E & 0xFFFF) # ori $t5, $t5, 0xe
/* 03CE8C 7F00835C 02001025 */  move  $v0, $s0
/* 03CE90 7F008360 AC4D0000 */  sw    $t5, ($v0)
/* 03CE94 7F008364 97AE005E */  lhu   $t6, 0x5e($sp)
/* 03CE98 7F008368 26100008 */  addiu $s0, $s0, 8
/* 03CE9C 7F00836C 02001825 */  move  $v1, $s0
/* 03CEA0 7F008370 26100008 */  addiu $s0, $s0, 8
/* 03CEA4 7F008374 3C0FFCFF */  lui   $t7, (0xFCFFFFFF >> 16) # lui $t7, 0xfcff
/* 03CEA8 7F008378 3C18FFFE */  lui   $t8, (0xFFFE793C >> 16) # lui $t8, 0xfffe
/* 03CEAC 7F00837C AC4E0004 */  sw    $t6, 4($v0)
/* 03CEB0 7F008380 3718793C */  ori   $t8, (0xFFFE793C & 0xFFFF) # ori $t8, $t8, 0x793c
/* 03CEB4 7F008384 35EFFFFF */  ori   $t7, (0xFCFFFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
/* 03CEB8 7F008388 02002825 */  move  $a1, $s0
/* 03CEBC 7F00838C AC6F0000 */  sw    $t7, ($v1)
/* 03CEC0 7F008390 AC780004 */  sw    $t8, 4($v1)
/* 03CEC4 7F008394 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 03CEC8 7F008398 3C0B0055 */  lui   $t3, (0x00552048 >> 16) # lui $t3, 0x55
/* 03CECC 7F00839C 356B2048 */  ori   $t3, (0x00552048 & 0xFFFF) # ori $t3, $t3, 0x2048
/* 03CED0 7F0083A0 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 03CED4 7F0083A4 26100008 */  addiu $s0, $s0, 8
/* 03CED8 7F0083A8 3C0C0103 */  lui   $t4, (0x01030040 >> 16) # lui $t4, 0x103
/* 03CEDC 7F0083AC ACB90000 */  sw    $t9, ($a1)
/* 03CEE0 7F0083B0 ACAB0004 */  sw    $t3, 4($a1)
/* 03CEE4 7F0083B4 358C0040 */  ori   $t4, (0x01030040 & 0xFFFF) # ori $t4, $t4, 0x40
/* 03CEE8 7F0083B8 02003025 */  move  $a2, $s0
/* 03CEEC 7F0083BC ACCC0000 */  sw    $t4, ($a2)
/* 03CEF0 7F0083C0 3C0D8003 */  lui   $t5, %hi(D_8002A7D0) 
/* 03CEF4 7F0083C4 8DADA7D0 */  lw    $t5, %lo(D_8002A7D0)($t5)
/* 03CEF8 7F0083C8 3C0F8007 */  lui   $t7, %hi(matrix_buffer_intro_bond) 
/* 03CEFC 7F0083CC 8DEF9570 */  lw    $t7, %lo(matrix_buffer_intro_bond)($t7)
/* 03CF00 7F0083D0 000D7180 */  sll   $t6, $t5, 6
/* 03CF04 7F0083D4 AFA6004C */  sw    $a2, 0x4c($sp)
/* 03CF08 7F0083D8 26100008 */  addiu $s0, $s0, 8
/* 03CF0C 7F0083DC 0C003A2C */  jal   osVirtualToPhysical
/* 03CF10 7F0083E0 01CF2021 */   addu  $a0, $t6, $t7
/* 03CF14 7F0083E4 8FA6004C */  lw    $a2, 0x4c($sp)
/* 03CF18 7F0083E8 3C180102 */  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
/* 03CF1C 7F0083EC 37180040 */  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 03CF20 7F0083F0 02005025 */  move  $t2, $s0
/* 03CF24 7F0083F4 ACC20004 */  sw    $v0, 4($a2)
/* 03CF28 7F0083F8 AD580000 */  sw    $t8, ($t2)
/* 03CF2C 7F0083FC 3C198003 */  lui   $t9, %hi(D_8002A7D0) 
/* 03CF30 7F008400 8F39A7D0 */  lw    $t9, %lo(D_8002A7D0)($t9)
/* 03CF34 7F008404 3C0C8007 */  lui   $t4, %hi(matrix_buffer_intro_backdrop) 
/* 03CF38 7F008408 8D8C956C */  lw    $t4, %lo(matrix_buffer_intro_backdrop)($t4)
/* 03CF3C 7F00840C 00195980 */  sll   $t3, $t9, 6
/* 03CF40 7F008410 AFAA0048 */  sw    $t2, 0x48($sp)
/* 03CF44 7F008414 26100008 */  addiu $s0, $s0, 8
/* 03CF48 7F008418 0C003A2C */  jal   osVirtualToPhysical
/* 03CF4C 7F00841C 016C2021 */   addu  $a0, $t3, $t4
/* 03CF50 7F008420 8FAA0048 */  lw    $t2, 0x48($sp)
/* 03CF54 7F008424 3C038003 */  lui   $v1, %hi(D_8002A83C)
/* 03CF58 7F008428 3C088003 */  lui   $t0, %hi(D_8002A848) 
/* 03CF5C 7F00842C AD420004 */  sw    $v0, 4($t2)
/* 03CF60 7F008430 2508A848 */  addiu $t0, %lo(D_8002A848) # addiu $t0, $t0, -0x57b8
/* 03CF64 7F008434 2463A83C */  addiu $v1, %lo(D_8002A83C) # addiu $v1, $v1, -0x57c4
/* 03CF68 7F008438 C4600000 */  lwc1  $f0, ($v1)
/* 03CF6C 7F00843C C50A0000 */  lwc1  $f10, ($t0)
/* 03CF70 7F008440 C4620004 */  lwc1  $f2, 4($v1)
/* 03CF74 7F008444 C5120004 */  lwc1  $f18, 4($t0)
/* 03CF78 7F008448 46005400 */  add.s $f16, $f10, $f0
/* 03CF7C 7F00844C C46C0008 */  lwc1  $f12, 8($v1)
/* 03CF80 7F008450 C5060008 */  lwc1  $f6, 8($t0)
/* 03CF84 7F008454 3C098003 */  lui   $t1, %hi(D_8002A854) 
/* 03CF88 7F008458 2529A854 */  addiu $t1, %lo(D_8002A854) # addiu $t1, $t1, -0x57ac
/* 03CF8C 7F00845C 46029100 */  add.s $f4, $f18, $f2
/* 03CF90 7F008460 E7B00010 */  swc1  $f16, 0x10($sp)
/* 03CF94 7F008464 C5300004 */  lwc1  $f16, 4($t1)
/* 03CF98 7F008468 460C3200 */  add.s $f8, $f6, $f12
/* 03CF9C 7F00846C C5320008 */  lwc1  $f18, 8($t1)
/* 03CFA0 7F008470 C52A0000 */  lwc1  $f10, ($t1)
/* 03CFA4 7F008474 44050000 */  mfc1  $a1, $f0
/* 03CFA8 7F008478 44061000 */  mfc1  $a2, $f2
/* 03CFAC 7F00847C 44076000 */  mfc1  $a3, $f12
/* 03CFB0 7F008480 E7A80018 */  swc1  $f8, 0x18($sp)
/* 03CFB4 7F008484 E7A40014 */  swc1  $f4, 0x14($sp)
/* 03CFB8 7F008488 27A40060 */  addiu $a0, $sp, 0x60
/* 03CFBC 7F00848C E7B00020 */  swc1  $f16, 0x20($sp)
/* 03CFC0 7F008490 E7B20024 */  swc1  $f18, 0x24($sp)
/* 03CFC4 7F008494 0FC165A5 */  jal   sub_GAME_7F059694
/* 03CFC8 7F008498 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 03CFCC 7F00849C 02002025 */  move  $a0, $s0
/* 03CFD0 7F0084A0 24050002 */  li    $a1, 2
/* 03CFD4 7F0084A4 0FC01FCC */  jal   sub_GAME_7F007F30
/* 03CFD8 7F0084A8 27A60060 */   addiu $a2, $sp, 0x60
/* 03CFDC 7F0084AC 8FBF0034 */  lw    $ra, 0x34($sp)
/* 03CFE0 7F0084B0 8FB00030 */  lw    $s0, 0x30($sp)
/* 03CFE4 7F0084B4 27BD00A0 */  addiu $sp, $sp, 0xa0
/* 03CFE8 7F0084B8 03E00008 */  jr    $ra
/* 03CFEC 7F0084BC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void load_display_rare_logo(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_display_rare_logo
/* 03CFF0 7F0084C0 44872000 */  mtc1  $a3, $f4
/* 03CFF4 7F0084C4 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 03CFF8 7F0084C8 AFB0002C */  sw    $s0, 0x2c($sp)
/* 03CFFC 7F0084CC 468021A0 */  cvt.s.w $f6, $f4
/* 03D000 7F0084D0 3C018003 */  lui   $at, %hi(D_8002A880)
/* 03D004 7F0084D4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 03D008 7F0084D8 AFB10030 */  sw    $s1, 0x30($sp)
/* 03D00C 7F0084DC AFA500EC */  sw    $a1, 0xec($sp)
/* 03D010 7F0084E0 AFA600F0 */  sw    $a2, 0xf0($sp)
/* 03D014 7F0084E4 E426A880 */  swc1  $f6, %lo(D_8002A880)($at)
/* 03D018 7F0084E8 3C0F0100 */  lui   $t7, 0x100
/* 03D01C 7F0084EC 25EF0000 */  addiu $t7, $t7, 0
/* 03D020 7F0084F0 3C0E0600 */  lui   $t6, 0x600
/* 03D024 7F0084F4 AC8E0000 */  sw    $t6, ($a0)
/* 03D028 7F0084F8 AC8F0004 */  sw    $t7, 4($a0)
/* 03D02C 7F0084FC 24900008 */  addiu $s0, $a0, 8
/* 03D030 7F008500 0FC07034 */  jal   insert_imageDL
/* 03D034 7F008504 02002025 */   move  $a0, $s0
/* 03D038 7F008508 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 03D03C 7F00850C 44814000 */  mtc1  $at, $f8
/* 03D040 7F008510 3C118003 */  lui   $s1, %hi(D_8002A7D0)
/* 03D044 7F008514 2631A7D0 */  addiu $s1, %lo(D_8002A7D0) # addiu $s1, $s1, -0x5830
/* 03D048 7F008518 3C018005 */  lui   $at, %hi(D_8004F2D8)
/* 03D04C 7F00851C C42AF2D8 */  lwc1  $f10, %lo(D_8004F2D8)($at)
/* 03D050 7F008520 8E380000 */  lw    $t8, ($s1)
/* 03D054 7F008524 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03D058 7F008528 3C0E8007 */  lui   $t6, %hi(matrix_buffer_rarelogo_0) 
/* 03D05C 7F00852C 8DCE9558 */  lw    $t6, %lo(matrix_buffer_rarelogo_0)($t6)
/* 03D060 7F008530 44818000 */  mtc1  $at, $f16
/* 03D064 7F008534 3C073FAA */  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
/* 03D068 7F008538 0018C980 */  sll   $t9, $t8, 6
/* 03D06C 7F00853C 00408025 */  move  $s0, $v0
/* 03D070 7F008540 34E7AAAB */  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
/* 03D074 7F008544 27A500E2 */  addiu $a1, $sp, 0xe2
/* 03D078 7F008548 3C064270 */  lui   $a2, 0x4270
/* 03D07C 7F00854C E7A80010 */  swc1  $f8, 0x10($sp)
/* 03D080 7F008550 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 03D084 7F008554 032E2021 */  addu  $a0, $t9, $t6
/* 03D088 7F008558 0C003FAC */  jal   guPerspective
/* 03D08C 7F00855C E7B00018 */   swc1  $f16, 0x18($sp)
/* 03D090 7F008560 3C0FBC00 */  lui   $t7, (0xBC00000E >> 16) # lui $t7, 0xbc00
/* 03D094 7F008564 35EF000E */  ori   $t7, (0xBC00000E & 0xFFFF) # ori $t7, $t7, 0xe
/* 03D098 7F008568 02001025 */  move  $v0, $s0
/* 03D09C 7F00856C AC4F0000 */  sw    $t7, ($v0)
/* 03D0A0 7F008570 97B800E2 */  lhu   $t8, 0xe2($sp)
/* 03D0A4 7F008574 26100008 */  addiu $s0, $s0, 8
/* 03D0A8 7F008578 3C190103 */  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
/* 03D0AC 7F00857C 37390040 */  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 03D0B0 7F008580 02005825 */  move  $t3, $s0
/* 03D0B4 7F008584 AC580004 */  sw    $t8, 4($v0)
/* 03D0B8 7F008588 AD790000 */  sw    $t9, ($t3)
/* 03D0BC 7F00858C 8E2E0000 */  lw    $t6, ($s1)
/* 03D0C0 7F008590 3C188007 */  lui   $t8, %hi(matrix_buffer_rarelogo_0) 
/* 03D0C4 7F008594 8F189558 */  lw    $t8, %lo(matrix_buffer_rarelogo_0)($t8)
/* 03D0C8 7F008598 000E7980 */  sll   $t7, $t6, 6
/* 03D0CC 7F00859C AFAB00D8 */  sw    $t3, 0xd8($sp)
/* 03D0D0 7F0085A0 26100008 */  addiu $s0, $s0, 8
/* 03D0D4 7F0085A4 0C003A2C */  jal   osVirtualToPhysical
/* 03D0D8 7F0085A8 01F82021 */   addu  $a0, $t7, $t8
/* 03D0DC 7F0085AC 8FAB00D8 */  lw    $t3, 0xd8($sp)
/* 03D0E0 7F0085B0 02001825 */  move  $v1, $s0
/* 03D0E4 7F0085B4 240EFFFF */  li    $t6, -1
/* 03D0E8 7F0085B8 AD620004 */  sw    $v0, 4($t3)
/* 03D0EC 7F0085BC AC6E0004 */  sw    $t6, 4($v1)
/* 03D0F0 7F0085C0 26100008 */  addiu $s0, $s0, 8
/* 03D0F4 7F0085C4 3C19B600 */  lui   $t9, 0xb600
/* 03D0F8 7F0085C8 AC790000 */  sw    $t9, ($v1)
/* 03D0FC 7F0085CC 02004025 */  move  $t0, $s0
/* 03D100 7F0085D0 3C0FB700 */  lui   $t7, 0xb700
/* 03D104 7F0085D4 3C180006 */  lui   $t8, (0x00062204 >> 16) # lui $t8, 6
/* 03D108 7F0085D8 37182204 */  ori   $t8, (0x00062204 & 0xFFFF) # ori $t8, $t8, 0x2204
/* 03D10C 7F0085DC AD0F0000 */  sw    $t7, ($t0)
/* 03D110 7F0085E0 AD180004 */  sw    $t8, 4($t0)
/* 03D114 7F0085E4 3C098003 */  lui   $t1, %hi(D_8002A884) 
/* 03D118 7F0085E8 3C0C8003 */  lui   $t4, %hi(D_8002A878) 
/* 03D11C 7F0085EC 258CA878 */  addiu $t4, %lo(D_8002A878) # addiu $t4, $t4, -0x5788
/* 03D120 7F0085F0 2529A884 */  addiu $t1, %lo(D_8002A884) # addiu $t1, $t1, -0x577c
/* 03D124 7F0085F4 C5320000 */  lwc1  $f18, ($t1)
/* 03D128 7F0085F8 C5800000 */  lwc1  $f0, ($t4)
/* 03D12C 7F0085FC C5260004 */  lwc1  $f6, 4($t1)
/* 03D130 7F008600 C5820004 */  lwc1  $f2, 4($t4)
/* 03D134 7F008604 46009100 */  add.s $f4, $f18, $f0
/* 03D138 7F008608 C52A0008 */  lwc1  $f10, 8($t1)
/* 03D13C 7F00860C C58C0008 */  lwc1  $f12, 8($t4)
/* 03D140 7F008610 3C0A8003 */  lui   $t2, %hi(D_8002A890) 
/* 03D144 7F008614 254AA890 */  addiu $t2, %lo(D_8002A890) # addiu $t2, $t2, -0x5770
/* 03D148 7F008618 46023200 */  add.s $f8, $f6, $f2
/* 03D14C 7F00861C 8E390000 */  lw    $t9, ($s1)
/* 03D150 7F008620 E7A40010 */  swc1  $f4, 0x10($sp)
/* 03D154 7F008624 460C5400 */  add.s $f16, $f10, $f12
/* 03D158 7F008628 3C0F8007 */  lui   $t7, %hi(matrix_buffer_rarelogo_1) 
/* 03D15C 7F00862C 8DEF9560 */  lw    $t7, %lo(matrix_buffer_rarelogo_1)($t7)
/* 03D160 7F008630 C5440004 */  lwc1  $f4, 4($t2)
/* 03D164 7F008634 C5460008 */  lwc1  $f6, 8($t2)
/* 03D168 7F008638 C5520000 */  lwc1  $f18, ($t2)
/* 03D16C 7F00863C 44050000 */  mfc1  $a1, $f0
/* 03D170 7F008640 44061000 */  mfc1  $a2, $f2
/* 03D174 7F008644 44076000 */  mfc1  $a3, $f12
/* 03D178 7F008648 00197180 */  sll   $t6, $t9, 6
/* 03D17C 7F00864C 26100008 */  addiu $s0, $s0, 8
/* 03D180 7F008650 E7B00018 */  swc1  $f16, 0x18($sp)
/* 03D184 7F008654 E7A80014 */  swc1  $f8, 0x14($sp)
/* 03D188 7F008658 01CF2021 */  addu  $a0, $t6, $t7
/* 03D18C 7F00865C E7A40020 */  swc1  $f4, 0x20($sp)
/* 03D190 7F008660 E7A60024 */  swc1  $f6, 0x24($sp)
/* 03D194 7F008664 0C005DAA */  jal   guLookAt
/* 03D198 7F008668 E7B2001C */   swc1  $f18, 0x1c($sp)
/* 03D19C 7F00866C 3C180102 */  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
/* 03D1A0 7F008670 37180040 */  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 03D1A4 7F008674 02001825 */  move  $v1, $s0
/* 03D1A8 7F008678 AC780000 */  sw    $t8, ($v1)
/* 03D1AC 7F00867C 8E390000 */  lw    $t9, ($s1)
/* 03D1B0 7F008680 3C0F8007 */  lui   $t7, %hi(matrix_buffer_rarelogo_1) 
/* 03D1B4 7F008684 8DEF9560 */  lw    $t7, %lo(matrix_buffer_rarelogo_1)($t7)
/* 03D1B8 7F008688 00197180 */  sll   $t6, $t9, 6
/* 03D1BC 7F00868C AFA300CC */  sw    $v1, 0xcc($sp)
/* 03D1C0 7F008690 26100008 */  addiu $s0, $s0, 8
/* 03D1C4 7F008694 0C003A2C */  jal   osVirtualToPhysical
/* 03D1C8 7F008698 01CF2021 */   addu  $a0, $t6, $t7
/* 03D1CC 7F00869C 8FA300CC */  lw    $v1, 0xcc($sp)
/* 03D1D0 7F0086A0 44800000 */  mtc1  $zero, $f0
/* 03D1D4 7F0086A4 3C0E8007 */  lui   $t6, %hi(matrix_buffer_rarelogo_2) 
/* 03D1D8 7F0086A8 AC620004 */  sw    $v0, 4($v1)
/* 03D1DC 7F0086AC 8E380000 */  lw    $t8, ($s1)
/* 03D1E0 7F0086B0 8DCE9564 */  lw    $t6, %lo(matrix_buffer_rarelogo_2)($t6)
/* 03D1E4 7F0086B4 3C058003 */  lui   $a1, %hi(D_8002A89C)
/* 03D1E8 7F0086B8 44060000 */  mfc1  $a2, $f0
/* 03D1EC 7F0086BC 0018C980 */  sll   $t9, $t8, 6
/* 03D1F0 7F0086C0 8CA5A89C */  lw    $a1, %lo(D_8002A89C)($a1)
/* 03D1F4 7F0086C4 3C073F80 */  lui   $a3, %hi(0x3F800004) # $a3, 0x3f80
/* 03D1F8 7F0086C8 E7A00010 */  swc1  $f0, 0x10($sp)
/* 03D1FC 7F0086CC 0C005E2D */  jal   guRotate
/* 03D200 7F0086D0 032E2021 */   addu  $a0, $t9, $t6
/* 03D204 7F0086D4 3C028003 */  lui   $v0, %hi(D_8002A89C)
/* 03D208 7F0086D8 2442A89C */  addiu $v0, %lo(D_8002A89C) # addiu $v0, $v0, -0x5764
/* 03D20C 7F0086DC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 03D210 7F0086E0 44815000 */  mtc1  $at, $f10
/* 03D214 7F0086E4 C4480000 */  lwc1  $f8, ($v0)
/* 03D218 7F0086E8 3C0F0100 */  lui   $t7, (0x01000040 >> 16) # lui $t7, 0x100
/* 03D21C 7F0086EC 35EF0040 */  ori   $t7, (0x01000040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 03D220 7F0086F0 460A4400 */  add.s $f16, $f8, $f10
/* 03D224 7F0086F4 02005025 */  move  $t2, $s0
/* 03D228 7F0086F8 3C0E8007 */  lui   $t6, %hi(matrix_buffer_rarelogo_2) 
/* 03D22C 7F0086FC 26100008 */  addiu $s0, $s0, 8
/* 03D230 7F008700 E4500000 */  swc1  $f16, ($v0)
/* 03D234 7F008704 AD4F0000 */  sw    $t7, ($t2)
/* 03D238 7F008708 8E380000 */  lw    $t8, ($s1)
/* 03D23C 7F00870C 8DCE9564 */  lw    $t6, %lo(matrix_buffer_rarelogo_2)($t6)
/* 03D240 7F008710 AFAA00C8 */  sw    $t2, 0xc8($sp)
/* 03D244 7F008714 0018C980 */  sll   $t9, $t8, 6
/* 03D248 7F008718 0C003A2C */  jal   osVirtualToPhysical
/* 03D24C 7F00871C 032E2021 */   addu  $a0, $t9, $t6
/* 03D250 7F008720 8FA800F8 */  lw    $t0, 0xf8($sp)
/* 03D254 7F008724 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 03D258 7F008728 02002025 */  move  $a0, $s0
/* 03D25C 7F00872C 3C0FBC00 */  lui   $t7, (0xBC000002 >> 16) # lui $t7, 0xbc00
/* 03D260 7F008730 35EF0002 */  ori   $t7, (0xBC000002 & 0xFFFF) # ori $t7, $t7, 2
/* 03D264 7F008734 26100008 */  addiu $s0, $s0, 8
/* 03D268 7F008738 3C188000 */  lui   $t8, (0x80000040 >> 16) # lui $t8, 0x8000
/* 03D26C 7F00873C AD420004 */  sw    $v0, 4($t2)
/* 03D270 7F008740 AC8F0000 */  sw    $t7, ($a0)
/* 03D274 7F008744 37180040 */  ori   $t8, (0x80000040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 03D278 7F008748 02002825 */  move  $a1, $s0
/* 03D27C 7F00874C AC980004 */  sw    $t8, 4($a0)
/* 03D280 7F008750 3C190386 */  lui   $t9, (0x03860010 >> 16) # lui $t9, 0x386
/* 03D284 7F008754 3C0E8003 */  lui   $t6, %hi(D_8002A868) 
/* 03D288 7F008758 25CEA868 */  addiu $t6, %lo(D_8002A868) # addiu $t6, $t6, -0x5798
/* 03D28C 7F00875C 37390010 */  ori   $t9, (0x03860010 & 0xFFFF) # ori $t9, $t9, 0x10
/* 03D290 7F008760 26100008 */  addiu $s0, $s0, 8
/* 03D294 7F008764 3C038003 */  lui   $v1, %hi(D_8002A860)
/* 03D298 7F008768 02003025 */  move  $a2, $s0
/* 03D29C 7F00876C ACB90000 */  sw    $t9, ($a1)
/* 03D2A0 7F008770 ACAE0004 */  sw    $t6, 4($a1)
/* 03D2A4 7F008774 3C0F0388 */  lui   $t7, (0x03880010 >> 16) # lui $t7, 0x388
/* 03D2A8 7F008778 2463A860 */  addiu $v1, %lo(D_8002A860) # addiu $v1, $v1, -0x57a0
/* 03D2AC 7F00877C 35EF0010 */  ori   $t7, (0x03880010 & 0xFFFF) # ori $t7, $t7, 0x10
/* 03D2B0 7F008780 ACCF0000 */  sw    $t7, ($a2)
/* 03D2B4 7F008784 ACC30004 */  sw    $v1, 4($a2)
/* 03D2B8 7F008788 26100008 */  addiu $s0, $s0, 8
/* 03D2BC 7F00878C 02003825 */  move  $a3, $s0
/* 03D2C0 7F008790 A0680000 */  sb    $t0, ($v1)
/* 03D2C4 7F008794 A0680001 */  sb    $t0, 1($v1)
/* 03D2C8 7F008798 A0680002 */  sb    $t0, 2($v1)
/* 03D2CC 7F00879C A0680004 */  sb    $t0, 4($v1)
/* 03D2D0 7F0087A0 A0680005 */  sb    $t0, 5($v1)
/* 03D2D4 7F0087A4 A0680006 */  sb    $t0, 6($v1)
/* 03D2D8 7F0087A8 26100008 */  addiu $s0, $s0, 8
/* 03D2DC 7F0087AC 3C09E700 */  lui   $t1, 0xe700
/* 03D2E0 7F0087B0 02005825 */  move  $t3, $s0
/* 03D2E4 7F0087B4 ACE90000 */  sw    $t1, ($a3)
/* 03D2E8 7F0087B8 ACE00004 */  sw    $zero, %lo(0x3F800004)($a3)
/* 03D2EC 7F0087BC 26100008 */  addiu $s0, $s0, 8
/* 03D2F0 7F0087C0 02001025 */  move  $v0, $s0
/* 03D2F4 7F0087C4 AD600004 */  sw    $zero, 4($t3)
/* 03D2F8 7F0087C8 AD690000 */  sw    $t1, ($t3)
/* 03D2FC 7F0087CC 26100008 */  addiu $s0, $s0, 8
/* 03D300 7F0087D0 3C18FC12 */  lui   $t8, (0xFC127E24 >> 16) # lui $t8, 0xfc12
/* 03D304 7F0087D4 37187E24 */  ori   $t8, (0xFC127E24 & 0xFFFF) # ori $t8, $t8, 0x7e24
/* 03D308 7F0087D8 2419F9FC */  li    $t9, -1540
/* 03D30C 7F0087DC 02001825 */  move  $v1, $s0
/* 03D310 7F0087E0 AC590004 */  sw    $t9, 4($v0)
/* 03D314 7F0087E4 AC580000 */  sw    $t8, ($v0)
/* 03D318 7F0087E8 3C0EBA00 */  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00
/* 03D31C 7F0087EC 35CE1301 */  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
/* 03D320 7F0087F0 3C0F0008 */  lui   $t7, 8
/* 03D324 7F0087F4 AC6F0004 */  sw    $t7, 4($v1)
/* 03D328 7F0087F8 AC6E0000 */  sw    $t6, ($v1)
/* 03D32C 7F0087FC 26100008 */  addiu $s0, $s0, 8
/* 03D330 7F008800 02002025 */  move  $a0, $s0
/* 03D334 7F008804 3C18BA00 */  lui   $t8, (0xBA001102 >> 16) # lui $t8, 0xba00
/* 03D338 7F008808 37181102 */  ori   $t8, (0xBA001102 & 0xFFFF) # ori $t8, $t8, 0x1102
/* 03D33C 7F00880C 26100008 */  addiu $s0, $s0, 8
/* 03D340 7F008810 AC980000 */  sw    $t8, ($a0)
/* 03D344 7F008814 02002825 */  move  $a1, $s0
/* 03D348 7F008818 3C19BA00 */  lui   $t9, (0xBA001001 >> 16) # lui $t9, 0xba00
/* 03D34C 7F00881C AC800004 */  sw    $zero, 4($a0)
/* 03D350 7F008820 37391001 */  ori   $t9, (0xBA001001 & 0xFFFF) # ori $t9, $t9, 0x1001
/* 03D354 7F008824 26100008 */  addiu $s0, $s0, 8
/* 03D358 7F008828 ACB90000 */  sw    $t9, ($a1)
/* 03D35C 7F00882C 02003025 */  move  $a2, $s0
/* 03D360 7F008830 ACA00004 */  sw    $zero, 4($a1)
/* 03D364 7F008834 26100008 */  addiu $s0, $s0, 8
/* 03D368 7F008838 3C0EBA00 */  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00
/* 03D36C 7F00883C 35CE0E02 */  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
/* 03D370 7F008840 02001025 */  move  $v0, $s0
/* 03D374 7F008844 ACCE0000 */  sw    $t6, ($a2)
/* 03D378 7F008848 ACC00004 */  sw    $zero, 4($a2)
/* 03D37C 7F00884C 3C0FBA00 */  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
/* 03D380 7F008850 35EF0C02 */  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
/* 03D384 7F008854 26100008 */  addiu $s0, $s0, 8
/* 03D388 7F008858 24182000 */  li    $t8, 8192
/* 03D38C 7F00885C AC580004 */  sw    $t8, 4($v0)
/* 03D390 7F008860 AC4F0000 */  sw    $t7, ($v0)
/* 03D394 7F008864 02001825 */  move  $v1, $s0
/* 03D398 7F008868 3C19BA00 */  lui   $t9, (0xBA000903 >> 16) # lui $t9, 0xba00
/* 03D39C 7F00886C 37390903 */  ori   $t9, (0xBA000903 & 0xFFFF) # ori $t9, $t9, 0x903
/* 03D3A0 7F008870 26100008 */  addiu $s0, $s0, 8
/* 03D3A4 7F008874 AC790000 */  sw    $t9, ($v1)
/* 03D3A8 7F008878 240E0C00 */  li    $t6, 3072
/* 03D3AC 7F00887C 02002025 */  move  $a0, $s0
/* 03D3B0 7F008880 AC6E0004 */  sw    $t6, 4($v1)
/* 03D3B4 7F008884 26100008 */  addiu $s0, $s0, 8
/* 03D3B8 7F008888 02002825 */  move  $a1, $s0
/* 03D3BC 7F00888C AC800004 */  sw    $zero, 4($a0)
/* 03D3C0 7F008890 AC890000 */  sw    $t1, ($a0)
/* 03D3C4 7F008894 26100008 */  addiu $s0, $s0, 8
/* 03D3C8 7F008898 ACA00004 */  sw    $zero, 4($a1)
/* 03D3CC 7F00889C ACA90000 */  sw    $t1, ($a1)
/* 03D3D0 7F0088A0 02003825 */  move  $a3, $s0
/* 03D3D4 7F0088A4 26100008 */  addiu $s0, $s0, 8
/* 03D3D8 7F0088A8 3C0FBB00 */  lui   $t7, (0xBB000001 >> 16) # lui $t7, 0xbb00
/* 03D3DC 7F0088AC 3C180800 */  lui   $t8, (0x08000800 >> 16) # lui $t8, 0x800
/* 03D3E0 7F0088B0 37180800 */  ori   $t8, (0x08000800 & 0xFFFF) # ori $t8, $t8, 0x800
/* 03D3E4 7F0088B4 35EF0001 */  ori   $t7, (0xBB000001 & 0xFFFF) # ori $t7, $t7, 1
/* 03D3E8 7F0088B8 02001025 */  move  $v0, $s0
/* 03D3EC 7F0088BC ACEF0000 */  sw    $t7, ($a3)
/* 03D3F0 7F0088C0 ACF80004 */  sw    $t8, %lo(0x3F800004)($a3)
/* 03D3F4 7F0088C4 26100008 */  addiu $s0, $s0, 8
/* 03D3F8 7F0088C8 3C190200 */  lui   $t9, %hi(0x02004FE8) # $t9, 0x200
/* 03D3FC 7F0088CC 3C0BFD10 */  lui   $t3, 0xfd10
/* 03D400 7F0088D0 27394FE8 */  addiu $t9, %lo(0x02004FE8) # addiu $t9, $t9, 0x4fe8
/* 03D404 7F0088D4 02001825 */  move  $v1, $s0
/* 03D408 7F0088D8 3C0D0701 */  lui   $t5, (0x07014050 >> 16) # lui $t5, 0x701
/* 03D40C 7F0088DC 26100008 */  addiu $s0, $s0, 8
/* 03D410 7F0088E0 AC590004 */  sw    $t9, 4($v0)
/* 03D414 7F0088E4 AC4B0000 */  sw    $t3, ($v0)
/* 03D418 7F0088E8 35AD4050 */  ori   $t5, (0x07014050 & 0xFFFF) # ori $t5, $t5, 0x4050
/* 03D41C 7F0088EC 3C0CF510 */  lui   $t4, 0xf510
/* 03D420 7F0088F0 02002025 */  move  $a0, $s0
/* 03D424 7F0088F4 AC6C0000 */  sw    $t4, ($v1)
/* 03D428 7F0088F8 AC6D0004 */  sw    $t5, 4($v1)
/* 03D42C 7F0088FC 3C1FE600 */  lui   $ra, 0xe600
/* 03D430 7F008900 26100008 */  addiu $s0, $s0, 8
/* 03D434 7F008904 02002825 */  move  $a1, $s0
/* 03D438 7F008908 AC9F0000 */  sw    $ra, ($a0)
/* 03D43C 7F00890C AC800004 */  sw    $zero, 4($a0)
/* 03D440 7F008910 3C0E073F */  lui   $t6, (0x073FF100 >> 16) # lui $t6, 0x73f
/* 03D444 7F008914 35CEF100 */  ori   $t6, (0x073FF100 & 0xFFFF) # ori $t6, $t6, 0xf100
/* 03D448 7F008918 26100008 */  addiu $s0, $s0, 8
/* 03D44C 7F00891C 3C11F300 */  lui   $s1, 0xf300
/* 03D450 7F008920 02003025 */  move  $a2, $s0
/* 03D454 7F008924 ACAE0004 */  sw    $t6, 4($a1)
/* 03D458 7F008928 26100008 */  addiu $s0, $s0, 8
/* 03D45C 7F00892C ACB10000 */  sw    $s1, ($a1)
/* 03D460 7F008930 02001825 */  move  $v1, $s0
/* 03D464 7F008934 ACC00004 */  sw    $zero, 4($a2)
/* 03D468 7F008938 ACC90000 */  sw    $t1, ($a2)
/* 03D46C 7F00893C 3C180001 */  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
/* 03D470 7F008940 3C0FF510 */  lui   $t7, (0xF5101000 >> 16) # lui $t7, 0xf510
/* 03D474 7F008944 35EF1000 */  ori   $t7, (0xF5101000 & 0xFFFF) # ori $t7, $t7, 0x1000
/* 03D478 7F008948 37184050 */  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
/* 03D47C 7F00894C 26100008 */  addiu $s0, $s0, 8
/* 03D480 7F008950 02002025 */  move  $a0, $s0
/* 03D484 7F008954 AC780004 */  sw    $t8, 4($v1)
/* 03D488 7F008958 AC6F0000 */  sw    $t7, ($v1)
/* 03D48C 7F00895C 3C0E0007 */  lui   $t6, (0x0007C07C >> 16) # lui $t6, 7
/* 03D490 7F008960 3C19F200 */  lui   $t9, 0xf200
/* 03D494 7F008964 AC990000 */  sw    $t9, ($a0)
/* 03D498 7F008968 35CEC07C */  ori   $t6, (0x0007C07C & 0xFFFF) # ori $t6, $t6, 0xc07c
/* 03D49C 7F00896C 26100008 */  addiu $s0, $s0, 8
/* 03D4A0 7F008970 310200FF */  andi  $v0, $t0, 0xff
/* 03D4A4 7F008974 AC8E0004 */  sw    $t6, 4($a0)
/* 03D4A8 7F008978 02002825 */  move  $a1, $s0
/* 03D4AC 7F00897C 3C0FFA00 */  lui   $t7, 0xfa00
/* 03D4B0 7F008980 ACAF0000 */  sw    $t7, ($a1)
/* 03D4B4 7F008984 0002C600 */  sll   $t8, $v0, 0x18
/* 03D4B8 7F008988 0002CC00 */  sll   $t9, $v0, 0x10
/* 03D4BC 7F00898C 03197025 */  or    $t6, $t8, $t9
/* 03D4C0 7F008990 00027A00 */  sll   $t7, $v0, 8
/* 03D4C4 7F008994 01CFC025 */  or    $t8, $t6, $t7
/* 03D4C8 7F008998 26100008 */  addiu $s0, $s0, 8
/* 03D4CC 7F00899C 371900FF */  ori   $t9, $t8, 0xff
/* 03D4D0 7F0089A0 02003825 */  move  $a3, $s0
/* 03D4D4 7F0089A4 ACB90004 */  sw    $t9, 4($a1)
/* 03D4D8 7F0089A8 26100008 */  addiu $s0, $s0, 8
/* 03D4DC 7F0089AC 3C0E0200 */  lui   $t6, %hi(0x020043E8) # $t6, 0x200
/* 03D4E0 7F0089B0 25CE43E8 */  addiu $t6, %lo(0x020043E8) # addiu $t6, $t6, 0x43e8
/* 03D4E4 7F0089B4 3C060600 */  lui   $a2, 0x600
/* 03D4E8 7F0089B8 02001025 */  move  $v0, $s0
/* 03D4EC 7F0089BC ACE60000 */  sw    $a2, ($a3)
/* 03D4F0 7F0089C0 ACEE0004 */  sw    $t6, 4($a3)
/* 03D4F4 7F0089C4 26100008 */  addiu $s0, $s0, 8
/* 03D4F8 7F0089C8 3C0F0200 */  lui   $t7, %hi(0x020044B0) # $t7, 0x200
/* 03D4FC 7F0089CC 25EF44B0 */  addiu $t7, %lo(0x020044B0) # addiu $t7, $t7, 0x44b0
/* 03D500 7F0089D0 02001825 */  move  $v1, $s0
/* 03D504 7F0089D4 AC4F0004 */  sw    $t7, 4($v0)
/* 03D508 7F0089D8 AC460000 */  sw    $a2, ($v0)
/* 03D50C 7F0089DC 3C180200 */  lui   $t8, %hi(0x02005FF0) # $t8, 0x200
/* 03D510 7F0089E0 27185FF0 */  addiu $t8, %lo(0x02005FF0) # addiu $t8, $t8, 0x5ff0
/* 03D514 7F0089E4 26100008 */  addiu $s0, $s0, 8
/* 03D518 7F0089E8 02002025 */  move  $a0, $s0
/* 03D51C 7F0089EC AC780004 */  sw    $t8, 4($v1)
/* 03D520 7F0089F0 AC6B0000 */  sw    $t3, ($v1)
/* 03D524 7F0089F4 26100008 */  addiu $s0, $s0, 8
/* 03D528 7F0089F8 02002825 */  move  $a1, $s0
/* 03D52C 7F0089FC 26100008 */  addiu $s0, $s0, 8
/* 03D530 7F008A00 AC8D0004 */  sw    $t5, 4($a0)
/* 03D534 7F008A04 AC8C0000 */  sw    $t4, ($a0)
/* 03D538 7F008A08 02005025 */  move  $t2, $s0
/* 03D53C 7F008A0C 26100008 */  addiu $s0, $s0, 8
/* 03D540 7F008A10 ACA00004 */  sw    $zero, 4($a1)
/* 03D544 7F008A14 ACBF0000 */  sw    $ra, ($a1)
/* 03D548 7F008A18 3C19073F */  lui   $t9, (0x073FF100 >> 16) # lui $t9, 0x73f
/* 03D54C 7F008A1C 3739F100 */  ori   $t9, (0x073FF100 & 0xFFFF) # ori $t9, $t9, 0xf100
/* 03D550 7F008A20 02001025 */  move  $v0, $s0
/* 03D554 7F008A24 240700FF */  li    $a3, 255
/* 03D558 7F008A28 AD590004 */  sw    $t9, 4($t2)
/* 03D55C 7F008A2C AD510000 */  sw    $s1, ($t2)
/* 03D560 7F008A30 26100008 */  addiu $s0, $s0, 8
/* 03D564 7F008A34 3C0F0001 */  lui   $t7, (0x00014050 >> 16) # lui $t7, 1
/* 03D568 7F008A38 35EF4050 */  ori   $t7, (0x00014050 & 0xFFFF) # ori $t7, $t7, 0x4050
/* 03D56C 7F008A3C 02001825 */  move  $v1, $s0
/* 03D570 7F008A40 AC400004 */  sw    $zero, 4($v0)
/* 03D574 7F008A44 AC490000 */  sw    $t1, ($v0)
/* 03D578 7F008A48 AC6F0004 */  sw    $t7, 4($v1)
/* 03D57C 7F008A4C 00087900 */  sll   $t7, $t0, 4
/* 03D580 7F008A50 01E87823 */  subu  $t7, $t7, $t0
/* 03D584 7F008A54 000F7900 */  sll   $t7, $t7, 4
/* 03D588 7F008A58 01E7001A */  div   $zero, $t7, $a3
/* 03D58C 7F008A5C 3C0EF510 */  lui   $t6, (0xF5101000 >> 16) # lui $t6, 0xf510
/* 03D590 7F008A60 35CE1000 */  ori   $t6, (0xF5101000 & 0xFFFF) # ori $t6, $t6, 0x1000
/* 03D594 7F008A64 26100008 */  addiu $s0, $s0, 8
/* 03D598 7F008A68 02002025 */  move  $a0, $s0
/* 03D59C 7F008A6C AC6E0000 */  sw    $t6, ($v1)
/* 03D5A0 7F008A70 3C190007 */  lui   $t9, (0x0007C07C >> 16) # lui $t9, 7
/* 03D5A4 7F008A74 3739C07C */  ori   $t9, (0x0007C07C & 0xFFFF) # ori $t9, $t9, 0xc07c
/* 03D5A8 7F008A78 26100008 */  addiu $s0, $s0, 8
/* 03D5AC 7F008A7C 3C18F200 */  lui   $t8, 0xf200
/* 03D5B0 7F008A80 AC980000 */  sw    $t8, ($a0)
/* 03D5B4 7F008A84 AC990004 */  sw    $t9, 4($a0)
/* 03D5B8 7F008A88 02002825 */  move  $a1, $s0
/* 03D5BC 7F008A8C 3C0EFA00 */  lui   $t6, 0xfa00
/* 03D5C0 7F008A90 ACAE0000 */  sw    $t6, ($a1)
/* 03D5C4 7F008A94 00087080 */  sll   $t6, $t0, 2
/* 03D5C8 7F008A98 01C87023 */  subu  $t6, $t6, $t0
/* 03D5CC 7F008A9C 000E7080 */  sll   $t6, $t6, 2
/* 03D5D0 7F008AA0 01C87021 */  addu  $t6, $t6, $t0
/* 03D5D4 7F008AA4 000E7100 */  sll   $t6, $t6, 4
/* 03D5D8 7F008AA8 00003012 */  mflo  $a2
/* 03D5DC 7F008AAC 30D800FF */  andi  $t8, $a2, 0xff
/* 03D5E0 7F008AB0 03003025 */  move  $a2, $t8
/* 03D5E4 7F008AB4 01C7001A */  div   $zero, $t6, $a3
/* 03D5E8 7F008AB8 0018CE00 */  sll   $t9, $t8, 0x18
/* 03D5EC 7F008ABC 26100008 */  addiu $s0, $s0, 8
/* 03D5F0 7F008AC0 14E00002 */  bnez  $a3, .L7F008ACC
/* 03D5F4 7F008AC4 00000000 */   nop   
/* 03D5F8 7F008AC8 0007000D */  break 7
.L7F008ACC:
/* 03D5FC 7F008ACC 2401FFFF */  li    $at, -1
/* 03D600 7F008AD0 14E10004 */  bne   $a3, $at, .L7F008AE4
/* 03D604 7F008AD4 3C018000 */   lui   $at, 0x8000
/* 03D608 7F008AD8 15E10002 */  bne   $t7, $at, .L7F008AE4
/* 03D60C 7F008ADC 00000000 */   nop   
/* 03D610 7F008AE0 0006000D */  break 6
.L7F008AE4:
/* 03D614 7F008AE4 00007812 */  mflo  $t7
/* 03D618 7F008AE8 31F800FF */  andi  $t8, $t7, 0xff
/* 03D61C 7F008AEC 14E00002 */  bnez  $a3, .L7F008AF8
/* 03D620 7F008AF0 00000000 */   nop   
/* 03D624 7F008AF4 0007000D */  break 7
.L7F008AF8:
/* 03D628 7F008AF8 2401FFFF */  li    $at, -1
/* 03D62C 7F008AFC 14E10004 */  bne   $a3, $at, .L7F008B10
/* 03D630 7F008B00 3C018000 */   lui   $at, 0x8000
/* 03D634 7F008B04 15C10002 */  bne   $t6, $at, .L7F008B10
/* 03D638 7F008B08 00000000 */   nop   
/* 03D63C 7F008B0C 0006000D */  break 6
.L7F008B10:
/* 03D640 7F008B10 00187400 */  sll   $t6, $t8, 0x10
/* 03D644 7F008B14 032E7825 */  or    $t7, $t9, $t6
/* 03D648 7F008B18 0006C200 */  sll   $t8, $a2, 8
/* 03D64C 7F008B1C 01F8C825 */  or    $t9, $t7, $t8
/* 03D650 7F008B20 372E00FF */  ori   $t6, $t9, 0xff
/* 03D654 7F008B24 ACAE0004 */  sw    $t6, 4($a1)
/* 03D658 7F008B28 3C180200 */  lui   $t8, %hi(0x02004758) # $t8, 0x200
/* 03D65C 7F008B2C 02001825 */  move  $v1, $s0
/* 03D660 7F008B30 27184758 */  addiu $t8, %lo(0x02004758) # addiu $t8, $t8, 0x4758
/* 03D664 7F008B34 3C0F0600 */  lui   $t7, 0x600
/* 03D668 7F008B38 AC6F0000 */  sw    $t7, ($v1)
/* 03D66C 7F008B3C AC780004 */  sw    $t8, 4($v1)
/* 03D670 7F008B40 8FBF0034 */  lw    $ra, 0x34($sp)
/* 03D674 7F008B44 26020008 */  addiu $v0, $s0, 8
/* 03D678 7F008B48 8FB0002C */  lw    $s0, 0x2c($sp)
/* 03D67C 7F008B4C 8FB10030 */  lw    $s1, 0x30($sp)
/* 03D680 7F008B50 03E00008 */  jr    $ra
/* 03D684 7F008B54 27BD00E8 */   addiu $sp, $sp, 0xe8
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F008B58(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F008B58
/* 03D688 7F008B58 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03D68C 7F008B5C A020A7D4 */  sb    $zero, %lo(D_8002A7D4)($at)
/* 03D690 7F008B60 3C01445C */  li    $at, 0x445C0000 # 880.000000
/* 03D694 7F008B64 44812000 */  mtc1  $at, $f4
/* 03D698 7F008B68 3C018007 */  lui   $at, %hi(x)
/* 03D69C 7F008B6C 3C0E0200 */  lui   $t6, %hi(0x020067F0) # $t6, 0x200
/* 03D6A0 7F008B70 E4249574 */  swc1  $f4, %lo(x)($at)
/* 03D6A4 7F008B74 3C01C220 */  li    $at, 0xC2200000 # -40.000000
/* 03D6A8 7F008B78 44813000 */  mtc1  $at, $f6
/* 03D6AC 7F008B7C 3C0F0200 */  lui   $t7, 0x200
/* 03D6B0 7F008B80 3C018003 */  lui   $at, %hi(D_8002A89C)
/* 03D6B4 7F008B84 25EF0000 */  addiu $t7, $t7, 0
/* 03D6B8 7F008B88 25CE67F0 */  addiu $t6, %lo(0x020067F0) # addiu $t6, $t6, 0x67f0
/* 03D6BC 7F008B8C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03D6C0 7F008B90 01CF3023 */  subu  $a2, $t6, $t7
/* 03D6C4 7F008B94 E426A89C */  swc1  $f6, %lo(D_8002A89C)($at)
/* 03D6C8 7F008B98 AFA5001C */  sw    $a1, 0x1c($sp)
/* 03D6CC 7F008B9C 3C028007 */  lui   $v0, %hi(virtualaddress)
/* 03D6D0 7F008BA0 3C018003 */  lui   $at, %hi(intro_eye_counter)
/* 03D6D4 7F008BA4 24C6003F */  addiu $a2, $a2, 0x3f
/* 03D6D8 7F008BA8 24429590 */  addiu $v0, %lo(virtualaddress) # addiu $v0, $v0, -0x6a70
/* 03D6DC 7F008BAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 03D6E0 7F008BB0 AC20A8A0 */  sw    $zero, %lo(intro_eye_counter)($at)
/* 03D6E4 7F008BB4 34D8003F */  ori   $t8, $a2, 0x3f
/* 03D6E8 7F008BB8 3C05002A */  lui   $a1, %hi(_GlobalimagetablecmdblkSegmentRomStart) # $a1, 0x2a
/* 03D6EC 7F008BBC AC440000 */  sw    $a0, ($v0)
/* 03D6F0 7F008BC0 24A5E560 */  addiu $a1, %lo(_GlobalimagetablecmdblkSegmentRomStart) # addiu $a1, $a1, -0x1aa0
/* 03D6F4 7F008BC4 0C001707 */  jal   romCopy
/* 03D6F8 7F008BC8 3B06003F */   xori  $a2, $t8, 0x3f
/* 03D6FC 7F008BCC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03D700 7F008BD0 27BD0018 */  addiu $sp, $sp, 0x18
/* 03D704 7F008BD4 03E00008 */  jr    $ra
/* 03D708 7F008BD8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void retrieve_display_rareware_logo(void) {

}
#else
GLOBAL_ASM(
.text
glabel retrieve_display_rareware_logo
/* 03D70C 7F008BDC 3C028003 */  lui   $v0, %hi(D_8002A7D0)
/* 03D710 7F008BE0 2442A7D0 */  addiu $v0, %lo(D_8002A7D0) # addiu $v0, $v0, -0x5830
/* 03D714 7F008BE4 8C4E0000 */  lw    $t6, ($v0)
/* 03D718 7F008BE8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03D71C 7F008BEC 240F0001 */  li    $t7, 1
/* 03D720 7F008BF0 AFB00020 */  sw    $s0, 0x20($sp)
/* 03D724 7F008BF4 3C19BC00 */  lui   $t9, (0xBC000806 >> 16) # lui $t9, 0xbc00
/* 03D728 7F008BF8 01EEC023 */  subu  $t8, $t7, $t6
/* 03D72C 7F008BFC AFBF0024 */  sw    $ra, 0x24($sp)
/* 03D730 7F008C00 AC580000 */  sw    $t8, ($v0)
/* 03D734 7F008C04 37390806 */  ori   $t9, (0xBC000806 & 0xFFFF) # ori $t9, $t9, 0x806
/* 03D738 7F008C08 AC990000 */  sw    $t9, ($a0)
/* 03D73C 7F008C0C 24900008 */  addiu $s0, $a0, 8
/* 03D740 7F008C10 00801825 */  move  $v1, $a0
/* 03D744 7F008C14 3C048007 */  lui   $a0, %hi(virtualaddress)
/* 03D748 7F008C18 8C849590 */  lw    $a0, %lo(virtualaddress)($a0)
/* 03D74C 7F008C1C 0C003A2C */  jal   osVirtualToPhysical
/* 03D750 7F008C20 AFA3002C */   sw    $v1, 0x2c($sp)
/* 03D754 7F008C24 8FA3002C */  lw    $v1, 0x2c($sp)
/* 03D758 7F008C28 3C098003 */  lui   $t1, %hi(D_8002A7D4) 
/* 03D75C 7F008C2C 2529A7D4 */  addiu $t1, %lo(D_8002A7D4) # addiu $t1, $t1, -0x582c
/* 03D760 7F008C30 AC620004 */  sw    $v0, 4($v1)
/* 03D764 7F008C34 91240000 */  lbu   $a0, ($t1)
/* 03D768 7F008C38 3C088003 */  lui   $t0, %hi(intro_eye_counter) 
/* 03D76C 7F008C3C 2508A8A0 */  addiu $t0, %lo(intro_eye_counter) # addiu $t0, $t0, -0x5760
/* 03D770 7F008C40 50800005 */  beql  $a0, $zero, .L7F008C58
/* 03D774 7F008C44 8D0B0000 */   lw    $t3, ($t0)
/* 03D778 7F008C48 24010001 */  li    $at, 1
/* 03D77C 7F008C4C 5481005C */  bnel  $a0, $at, .L7F008DC0
/* 03D780 7F008C50 8FBF0024 */   lw    $ra, 0x24($sp)
/* 03D784 7F008C54 8D0B0000 */  lw    $t3, ($t0)
.L7F008C58:
/* 03D788 7F008C58 240A00FF */  li    $t2, 255
/* 03D78C 7F008C5C 24050046 */  li    $a1, 70
/* 03D790 7F008C60 016A0019 */  multu $t3, $t2
/* 03D794 7F008C64 00002012 */  mflo  $a0
/* 03D798 7F008C68 00000000 */  nop   
/* 03D79C 7F008C6C 00000000 */  nop   
/* 03D7A0 7F008C70 0085001A */  div   $zero, $a0, $a1
/* 03D7A4 7F008C74 14A00002 */  bnez  $a1, .L7F008C80
/* 03D7A8 7F008C78 00000000 */   nop   
/* 03D7AC 7F008C7C 0007000D */  break 7
.L7F008C80:
/* 03D7B0 7F008C80 2401FFFF */  li    $at, -1
/* 03D7B4 7F008C84 14A10004 */  bne   $a1, $at, .L7F008C98
/* 03D7B8 7F008C88 3C018000 */   lui   $at, 0x8000
/* 03D7BC 7F008C8C 14810002 */  bne   $a0, $at, .L7F008C98
/* 03D7C0 7F008C90 00000000 */   nop   
/* 03D7C4 7F008C94 0006000D */  break 6
.L7F008C98:
/* 03D7C8 7F008C98 00001812 */  mflo  $v1
/* 03D7CC 7F008C9C 28610100 */  slti  $at, $v1, 0x100
/* 03D7D0 7F008CA0 14200002 */  bnez  $at, .L7F008CAC
/* 03D7D4 7F008CA4 00000000 */   nop   
/* 03D7D8 7F008CA8 01401825 */  move  $v1, $t2
.L7F008CAC:
/* 03D7DC 7F008CAC 04610002 */  bgez  $v1, .L7F008CB8
/* 03D7E0 7F008CB0 3C01FFFF */   lui   $at, (0xFFFF60A0 >> 16) # lui $at, 0xffff
/* 03D7E4 7F008CB4 00001825 */  move  $v1, $zero
.L7F008CB8:
/* 03D7E8 7F008CB8 342160A0 */  ori   $at, (0xFFFF60A0 & 0xFFFF) # ori $at, $at, 0x60a0
/* 03D7EC 7F008CBC 00816021 */  addu  $t4, $a0, $at
/* 03D7F0 7F008CC0 0185001A */  div   $zero, $t4, $a1
/* 03D7F4 7F008CC4 14A00002 */  bnez  $a1, .L7F008CD0
/* 03D7F8 7F008CC8 00000000 */   nop   
/* 03D7FC 7F008CCC 0007000D */  break 7
.L7F008CD0:
/* 03D800 7F008CD0 2401FFFF */  li    $at, -1
/* 03D804 7F008CD4 14A10004 */  bne   $a1, $at, .L7F008CE8
/* 03D808 7F008CD8 3C018000 */   lui   $at, 0x8000
/* 03D80C 7F008CDC 15810002 */  bne   $t4, $at, .L7F008CE8
/* 03D810 7F008CE0 00000000 */   nop   
/* 03D814 7F008CE4 0006000D */  break 6
.L7F008CE8:
/* 03D818 7F008CE8 00006812 */  mflo  $t5
/* 03D81C 7F008CEC 014D1023 */  subu  $v0, $t2, $t5
/* 03D820 7F008CF0 28410100 */  slti  $at, $v0, 0x100
/* 03D824 7F008CF4 14200002 */  bnez  $at, .L7F008D00
/* 03D828 7F008CF8 00000000 */   nop   
/* 03D82C 7F008CFC 01401025 */  move  $v0, $t2
.L7F008D00:
/* 03D830 7F008D00 04410002 */  bgez  $v0, .L7F008D0C
/* 03D834 7F008D04 00000000 */   nop   
/* 03D838 7F008D08 00001025 */  move  $v0, $zero
.L7F008D0C:
/* 03D83C 7F008D0C 00620019 */  multu $v1, $v0
/* 03D840 7F008D10 3C018007 */  lui   $at, %hi(x)
/* 03D844 7F008D14 C4249574 */  lwc1  $f4, %lo(x)($at)
/* 03D848 7F008D18 02002025 */  move  $a0, $s0
/* 03D84C 7F008D1C 24050193 */  li    $a1, 403
/* 03D850 7F008D20 4600218D */  trunc.w.s $f6, $f4
/* 03D854 7F008D24 240601E8 */  li    $a2, 488
/* 03D858 7F008D28 44073000 */  mfc1  $a3, $f6
/* 03D85C 7F008D2C 00007012 */  mflo  $t6
/* 03D860 7F008D30 00000000 */  nop   
/* 03D864 7F008D34 00000000 */  nop   
/* 03D868 7F008D38 01CA001A */  div   $zero, $t6, $t2
/* 03D86C 7F008D3C 0000C012 */  mflo  $t8
/* 03D870 7F008D40 AFB80010 */  sw    $t8, 0x10($sp)
/* 03D874 7F008D44 15400002 */  bnez  $t2, .L7F008D50
/* 03D878 7F008D48 00000000 */   nop   
/* 03D87C 7F008D4C 0007000D */  break 7
.L7F008D50:
/* 03D880 7F008D50 2401FFFF */  li    $at, -1
/* 03D884 7F008D54 15410004 */  bne   $t2, $at, .L7F008D68
/* 03D888 7F008D58 3C018000 */   lui   $at, 0x8000
/* 03D88C 7F008D5C 15C10002 */  bne   $t6, $at, .L7F008D68
/* 03D890 7F008D60 00000000 */   nop   
/* 03D894 7F008D64 0006000D */  break 6
.L7F008D68:
/* 03D898 7F008D68 0FC02130 */  jal   load_display_rare_logo
/* 03D89C 7F008D6C 00000000 */   nop   
/* 03D8A0 7F008D70 3C088003 */  lui   $t0, %hi(intro_eye_counter) 
/* 03D8A4 7F008D74 2508A8A0 */  addiu $t0, %lo(intro_eye_counter) # addiu $t0, $t0, -0x5760
/* 03D8A8 7F008D78 8D030000 */  lw    $v1, ($t0)
/* 03D8AC 7F008D7C 3C098003 */  lui   $t1, %hi(D_8002A7D4) 
/* 03D8B0 7F008D80 2529A7D4 */  addiu $t1, %lo(D_8002A7D4) # addiu $t1, $t1, -0x582c
/* 03D8B4 7F008D84 28640104 */  slti  $a0, $v1, 0x104
/* 03D8B8 7F008D88 24790001 */  addiu $t9, $v1, 1
/* 03D8BC 7F008D8C 00408025 */  move  $s0, $v0
/* 03D8C0 7F008D90 1480000A */  bnez  $a0, .L7F008DBC
/* 03D8C4 7F008D94 AD190000 */   sw    $t9, ($t0)
/* 03D8C8 7F008D98 2B210122 */  slti  $at, $t9, 0x122
/* 03D8CC 7F008D9C 54200008 */  bnezl $at, .L7F008DC0
/* 03D8D0 7F008DA0 8FBF0024 */   lw    $ra, 0x24($sp)
/* 03D8D4 7F008DA4 912C0000 */  lbu   $t4, ($t1)
/* 03D8D8 7F008DA8 AD000000 */  sw    $zero, ($t0)
/* 03D8DC 7F008DAC 258F0001 */  addiu $t7, $t4, 1
/* 03D8E0 7F008DB0 A12F0000 */  sb    $t7, ($t1)
/* 03D8E4 7F008DB4 25EE0001 */  addiu $t6, $t7, 1
/* 03D8E8 7F008DB8 A12E0000 */  sb    $t6, ($t1)
.L7F008DBC:
/* 03D8EC 7F008DBC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F008DC0:
/* 03D8F0 7F008DC0 02001025 */  move  $v0, $s0
/* 03D8F4 7F008DC4 8FB00020 */  lw    $s0, 0x20($sp)
/* 03D8F8 7F008DC8 03E00008 */  jr    $ra
/* 03D8FC 7F008DCC 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F008DD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F008DD0
/* 03D900 7F008DD0 3C028003 */  lui   $v0, %hi(D_8002A7D4)
/* 03D904 7F008DD4 9042A7D4 */  lbu   $v0, %lo(D_8002A7D4)($v0)
/* 03D908 7F008DD8 384E0002 */  xori  $t6, $v0, 2
/* 03D90C 7F008DDC 03E00008 */  jr    $ra
/* 03D910 7F008DE0 2DC20001 */   sltiu $v0, $t6, 1
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F008DE4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F008DE4
/* 03D914 7F008DE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03D918 7F008DE8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03D91C 7F008DEC AFA5001C */  sw    $a1, 0x1c($sp)
/* 03D920 7F008DF0 8C8E0000 */  lw    $t6, ($a0)
/* 03D924 7F008DF4 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006958C)
/* 03D928 7F008DF8 3C03002A */  lui   $v1, %hi(unknown2) # $v1, 0x2a
/* 03D92C 7F008DFC AC2E958C */  sw    $t6, %lo(dword_CODE_bss_8006958C)($at)
/* 03D930 7F008E00 8CB80000 */  lw    $t8, ($a1)
/* 03D934 7F008E04 3C01FFFB */  lui   $at, (0xFFFBFC00 >> 16) # lui $at, 0xfffb
/* 03D938 7F008E08 3421FC00 */  ori   $at, (0xFFFBFC00 & 0xFFFF) # ori $at, $at, 0xfc00
/* 03D93C 7F008E0C 0301C821 */  addu  $t9, $t8, $at
/* 03D940 7F008E10 ACB90000 */  sw    $t9, ($a1)
/* 03D944 7F008E14 8C880000 */  lw    $t0, ($a0)
/* 03D948 7F008E18 3C0B002C */  lui   $t3, %hi(_ramromDam1SegmentRomStart) # $t3, 0x2c
/* 03D94C 7F008E1C 24634D50 */  addiu $v1, %lo(unknown2) # addiu $v1, $v1, 0x4d50
/* 03D950 7F008E20 3C010004 */  lui   $at, (0x00040400 >> 16) # lui $at, 4
/* 03D954 7F008E24 256BF2D0 */  addiu $t3, %lo(_ramromDam1SegmentRomStart) # addiu $t3, $t3, -0xd30
/* 03D958 7F008E28 34210400 */  ori   $at, (0x00040400 & 0xFFFF) # ori $at, $at, 0x400
/* 03D95C 7F008E2C 01633023 */  subu  $a2, $t3, $v1
/* 03D960 7F008E30 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80069588)
/* 03D964 7F008E34 24C6003F */  addiu $a2, $a2, 0x3f
/* 03D968 7F008E38 01014821 */  addu  $t1, $t0, $at
/* 03D96C 7F008E3C 24429588 */  addiu $v0, %lo(dword_CODE_bss_80069588) # addiu $v0, $v0, -0x6a78
/* 03D970 7F008E40 AC890000 */  sw    $t1, ($a0)
/* 03D974 7F008E44 34CC003F */  ori   $t4, $a2, 0x3f
/* 03D978 7F008E48 AC490000 */  sw    $t1, ($v0)
/* 03D97C 7F008E4C 3986003F */  xori  $a2, $t4, 0x3f
/* 03D980 7F008E50 01202025 */  move  $a0, $t1
/* 03D984 7F008E54 0C001707 */  jal   romCopy
/* 03D988 7F008E58 00602825 */   move  $a1, $v1
/* 03D98C 7F008E5C 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069588)
/* 03D990 7F008E60 3C058007 */  lui   $a1, %hi(dword_CODE_bss_8006958C)
/* 03D994 7F008E64 8CA5958C */  lw    $a1, %lo(dword_CODE_bss_8006958C)($a1)
/* 03D998 7F008E68 0FC06C38 */  jal   sub_GAME_7F01B0E0
/* 03D99C 7F008E6C 8C849588 */   lw    $a0, %lo(dword_CODE_bss_80069588)($a0)
/* 03D9A0 7F008E70 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03D9A4 7F008E74 27BD0018 */  addiu $sp, $sp, 0x18
/* 03D9A8 7F008E78 03E00008 */  jr    $ra
/* 03D9AC 7F008E7C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F008E80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F008E80
/* 03D9B0 7F008E80 240E0002 */  li    $t6, 2
/* 03D9B4 7F008E84 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03D9B8 7F008E88 A02EA7D4 */  sb    $t6, %lo(D_8002A7D4)($at)
/* 03D9BC 7F008E8C 3C014470 */  li    $at, 0x44700000 # 960.000000
/* 03D9C0 7F008E90 44812000 */  mtc1  $at, $f4
/* 03D9C4 7F008E94 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 03D9C8 7F008E98 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03D9CC 7F008E9C 44813000 */  mtc1  $at, $f6
/* 03D9D0 7F008EA0 44800000 */  mtc1  $zero, $f0
/* 03D9D4 7F008EA4 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 03D9D8 7F008EA8 44814000 */  mtc1  $at, $f8
/* 03D9DC 7F008EAC 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 03D9E0 7F008EB0 44815000 */  mtc1  $at, $f10
/* 03D9E4 7F008EB4 AFA40060 */  sw    $a0, 0x60($sp)
/* 03D9E8 7F008EB8 AFA50064 */  sw    $a1, 0x64($sp)
/* 03D9EC 7F008EBC AFBF002C */  sw    $ra, 0x2c($sp)
/* 03D9F0 7F008EC0 3C048007 */  lui   $a0, %hi(matrix_buffer_gunbarrel_0)
/* 03D9F4 7F008EC4 44050000 */  mfc1  $a1, $f0
/* 03D9F8 7F008EC8 44070000 */  mfc1  $a3, $f0
/* 03D9FC 7F008ECC AFB10028 */  sw    $s1, 0x28($sp)
/* 03DA00 7F008ED0 AFB00024 */  sw    $s0, 0x24($sp)
/* 03DA04 7F008ED4 8C84955C */  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
/* 03DA08 7F008ED8 3C0644A0 */  lui   $a2, 0x44a0
/* 03DA0C 7F008EDC E7A40010 */  swc1  $f4, 0x10($sp)
/* 03DA10 7F008EE0 E7A60014 */  swc1  $f6, 0x14($sp)
/* 03DA14 7F008EE4 E7A80018 */  swc1  $f8, 0x18($sp)
/* 03DA18 7F008EE8 0C005AF1 */  jal   guOrtho
/* 03DA1C 7F008EEC E7AA001C */   swc1  $f10, 0x1c($sp)
/* 03DA20 7F008EF0 3C0143F1 */  li    $at, 0x43F10000 # 482.000000
/* 03DA24 7F008EF4 44810000 */  mtc1  $at, $f0
/* 03DA28 7F008EF8 3C01C1F0 */  li    $at, 0xC1F00000 # -30.000000
/* 03DA2C 7F008EFC 44818000 */  mtc1  $at, $f16
/* 03DA30 7F008F00 3C018007 */  lui   $at, %hi(x)
/* 03DA34 7F008F04 8FA20060 */  lw    $v0, 0x60($sp)
/* 03DA38 7F008F08 E4309574 */  swc1  $f16, %lo(x)($at)
/* 03DA3C 7F008F0C 3C018007 */  lui   $at, %hi(y)
/* 03DA40 7F008F10 E4209578 */  swc1  $f0, %lo(y)($at)
/* 03DA44 7F008F14 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 03DA48 7F008F18 44819000 */  mtc1  $at, $f18
/* 03DA4C 7F008F1C 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03DA50 7F008F20 8FB80064 */  lw    $t8, 0x64($sp)
/* 03DA54 7F008F24 E432957C */  swc1  $f18, %lo(dword_CODE_bss_8006957C)($at)
/* 03DA58 7F008F28 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069580)
/* 03DA5C 7F008F2C E4209580 */  swc1  $f0, %lo(dword_CODE_bss_80069580)($at)
/* 03DA60 7F008F30 3C108007 */  lui   $s0, %hi(dword_CODE_bss_80069550)
/* 03DA64 7F008F34 3C018007 */  lui   $at, %hi(word_CODE_bss_80069584)
/* 03DA68 7F008F38 240F0042 */  li    $t7, 66
/* 03DA6C 7F008F3C 26109550 */  addiu $s0, %lo(dword_CODE_bss_80069550) # addiu $s0, $s0, -0x6ab0
/* 03DA70 7F008F40 A42F9584 */  sh    $t7, %lo(word_CODE_bss_80069584)($at)
/* 03DA74 7F008F44 AE020000 */  sw    $v0, ($s0)
/* 03DA78 7F008F48 24420200 */  addiu $v0, $v0, 0x200
/* 03DA7C 7F008F4C 2719FE00 */  addiu $t9, $t8, -0x200
/* 03DA80 7F008F50 AFB90064 */  sw    $t9, 0x64($sp)
/* 03DA84 7F008F54 AFA20060 */  sw    $v0, 0x60($sp)
/* 03DA88 7F008F58 8E040000 */  lw    $a0, ($s0)
/* 03DA8C 7F008F5C 0FC06EB8 */  jal   sub_GAME_7F01BAE0
/* 03DA90 7F008F60 2405001E */   li    $a1, 30
/* 03DA94 7F008F64 8FA30060 */  lw    $v1, 0x60($sp)
/* 03DA98 7F008F68 8FA80064 */  lw    $t0, 0x64($sp)
/* 03DA9C 7F008F6C 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80069554)
/* 03DAA0 7F008F70 24429554 */  addiu $v0, %lo(dword_CODE_bss_80069554) # addiu $v0, $v0, -0x6aac
/* 03DAA4 7F008F74 8E050000 */  lw    $a1, ($s0)
/* 03DAA8 7F008F78 AC430000 */  sw    $v1, ($v0)
/* 03DAAC 7F008F7C 3C018000 */  lui   $at, 0x8000
/* 03DAB0 7F008F80 24630100 */  addiu $v1, $v1, 0x100
/* 03DAB4 7F008F84 2509FF00 */  addiu $t1, $t0, -0x100
/* 03DAB8 7F008F88 AFA90064 */  sw    $t1, 0x64($sp)
/* 03DABC 7F008F8C AFA30060 */  sw    $v1, 0x60($sp)
/* 03DAC0 7F008F90 8C440000 */  lw    $a0, ($v0)
/* 03DAC4 7F008F94 2406001E */  li    $a2, 30
/* 03DAC8 7F008F98 0FC06FFE */  jal   sub_GAME_7F01BFF8
/* 03DACC 7F008F9C 00A12821 */   addu  $a1, $a1, $at
/* 03DAD0 7F008FA0 27A40060 */  addiu $a0, $sp, 0x60
/* 03DAD4 7F008FA4 0FC02379 */  jal   sub_GAME_7F008DE4
/* 03DAD8 7F008FA8 27A50064 */   addiu $a1, $sp, 0x64
/* 03DADC 7F008FAC 3C0B8003 */  lui   $t3, %hi(D_8002A8A8) 
/* 03DAE0 7F008FB0 256BA8A8 */  addiu $t3, %lo(D_8002A8A8) # addiu $t3, $t3, -0x5758
/* 03DAE4 7F008FB4 8D610000 */  lw    $at, ($t3)
/* 03DAE8 7F008FB8 27AA0050 */  addiu $t2, $sp, 0x50
/* 03DAEC 7F008FBC 8D6E0004 */  lw    $t6, 4($t3)
/* 03DAF0 7F008FC0 AD410000 */  sw    $at, ($t2)
/* 03DAF4 7F008FC4 8D610008 */  lw    $at, 8($t3)
/* 03DAF8 7F008FC8 3C110001 */  lui   $s1, (0x00012C00 >> 16) # lui $s1, 1
/* 03DAFC 7F008FCC 36312C00 */  ori   $s1, (0x00012C00 & 0xFFFF) # ori $s1, $s1, 0x2c00
/* 03DB00 7F008FD0 AD4E0004 */  sw    $t6, 4($t2)
/* 03DB04 7F008FD4 AD410008 */  sw    $at, 8($t2)
/* 03DB08 7F008FD8 8FA50060 */  lw    $a1, 0x60($sp)
/* 03DB0C 7F008FDC 02203025 */  move  $a2, $s1
/* 03DB10 7F008FE0 0FC32EBD */  jal   sub_GAME_7F0CBAF4
/* 03DB14 7F008FE4 27A40040 */   addiu $a0, $sp, 0x40
/* 03DB18 7F008FE8 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DB1C 7F008FEC 8FA70064 */  lw    $a3, 0x64($sp)
/* 03DB20 7F008FF0 3C108004 */  lui   $s0, %hi(c_item_entries)
/* 03DB24 7F008FF4 2610DE10 */  addiu $s0, %lo(c_item_entries) # addiu $s0, $s0, -0x21f0
/* 03DB28 7F008FF8 27AF0040 */  addiu $t7, $sp, 0x40
/* 03DB2C 7F008FFC 00D13021 */  addu  $a2, $a2, $s1
/* 03DB30 7F009000 00F13823 */  subu  $a3, $a3, $s1
/* 03DB34 7F009004 AFA70064 */  sw    $a3, 0x64($sp)
/* 03DB38 7F009008 AFA60060 */  sw    $a2, 0x60($sp)
/* 03DB3C 7F00900C AFAF0010 */  sw    $t7, 0x10($sp)
/* 03DB40 7F009010 8E040064 */  lw    $a0, 0x64($s0)
/* 03DB44 7F009014 0FC1D929 */  jal   load_object_fill_header
/* 03DB48 7F009018 8E050068 */   lw    $a1, 0x68($s0)
/* 03DB4C 7F00901C 0FC2F462 */  jal   sub_GAME_7F0BD188
/* 03DB50 7F009020 8E040068 */   lw    $a0, 0x68($s0)
/* 03DB54 7F009024 2443003F */  addiu $v1, $v0, 0x3f
/* 03DB58 7F009028 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DB5C 7F00902C 8FA70064 */  lw    $a3, 0x64($sp)
/* 03DB60 7F009030 3478003F */  ori   $t8, $v1, 0x3f
/* 03DB64 7F009034 3B19003F */  xori  $t9, $t8, 0x3f
/* 03DB68 7F009038 27A80040 */  addiu $t0, $sp, 0x40
/* 03DB6C 7F00903C 00D93021 */  addu  $a2, $a2, $t9
/* 03DB70 7F009040 00F93823 */  subu  $a3, $a3, $t9
/* 03DB74 7F009044 AFA70064 */  sw    $a3, 0x64($sp)
/* 03DB78 7F009048 AFA60060 */  sw    $a2, 0x60($sp)
/* 03DB7C 7F00904C AFA80010 */  sw    $t0, 0x10($sp)
/* 03DB80 7F009050 8E040618 */  lw    $a0, 0x618($s0)
/* 03DB84 7F009054 0FC1D929 */  jal   load_object_fill_header
/* 03DB88 7F009058 8E05061C */   lw    $a1, 0x61c($s0)
/* 03DB8C 7F00905C 0FC2F462 */  jal   sub_GAME_7F0BD188
/* 03DB90 7F009060 8E04061C */   lw    $a0, 0x61c($s0)
/* 03DB94 7F009064 2443003F */  addiu $v1, $v0, 0x3f
/* 03DB98 7F009068 8FAC0064 */  lw    $t4, 0x64($sp)
/* 03DB9C 7F00906C 8FAB0060 */  lw    $t3, 0x60($sp)
/* 03DBA0 7F009070 3469003F */  ori   $t1, $v1, 0x3f
/* 03DBA4 7F009074 392D003F */  xori  $t5, $t1, 0x3f
/* 03DBA8 7F009078 018D5023 */  subu  $t2, $t4, $t5
/* 03DBAC 7F00907C 016D7021 */  addu  $t6, $t3, $t5
/* 03DBB0 7F009080 AFAA0064 */  sw    $t2, 0x64($sp)
/* 03DBB4 7F009084 AFAE0060 */  sw    $t6, 0x60($sp)
/* 03DBB8 7F009088 24040005 */  li    $a0, 5
/* 03DBBC 7F00908C 2405004E */  li    $a1, 78
/* 03DBC0 7F009090 8E060064 */  lw    $a2, 0x64($s0)
/* 03DBC4 7F009094 8E070618 */  lw    $a3, 0x618($s0)
/* 03DBC8 7F009098 0FC08D2A */  jal   sub_GAME_7F0234A8
/* 03DBCC 7F00909C AFA00010 */   sw    $zero, 0x10($sp)
/* 03DBD0 7F0090A0 3C118003 */  lui   $s1, %hi(D_8002A7F4)
/* 03DBD4 7F0090A4 2631A7F4 */  addiu $s1, %lo(D_8002A7F4) # addiu $s1, $s1, -0x580c
/* 03DBD8 7F0090A8 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03DBDC 7F0090AC AE220000 */  sw    $v0, ($s1)
/* 03DBE0 7F0090B0 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03DBE4 7F0090B4 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 03DBE8 7F0090B8 00402025 */   move  $a0, $v0
/* 03DBEC 7F0090BC 8E240000 */  lw    $a0, ($s1)
/* 03DBF0 7F0090C0 0FC1B3A1 */  jal   sub_GAME_7F06CE84
/* 03DBF4 7F0090C4 3C053F80 */   lui   $a1, 0x3f80
/* 03DBF8 7F0090C8 8E240000 */  lw    $a0, ($s1)
/* 03DBFC 7F0090CC 0FC1B303 */  jal   setsuboffset
/* 03DC00 7F0090D0 27A50050 */   addiu $a1, $sp, 0x50
/* 03DC04 7F0090D4 8E240000 */  lw    $a0, ($s1)
/* 03DC08 7F0090D8 0FC1B34F */  jal   setsubroty
/* 03DC0C 7F0090DC 24050000 */   li    $a1, 0
/* 03DC10 7F0090E0 8E240000 */  lw    $a0, ($s1)
/* 03DC14 7F0090E4 3C053F00 */  lui   $a1, 0x3f00
/* 03DC18 7F0090E8 0FC1BFC6 */  jal   sub_GAME_7F06FF18
/* 03DC1C 7F0090EC 24060000 */   li    $a2, 0
/* 03DC20 7F0090F0 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 03DC24 7F0090F4 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 03DC28 7F0090F8 3C180000 */  lui   $t8, 0
/* 03DC2C 7F0090FC 27184144 */  addiu $t8, $t8, 0x4144
/* 03DC30 7F009100 01F82821 */  addu  $a1, $t7, $t8
/* 03DC34 7F009104 94A30004 */  lhu   $v1, 4($a1)
/* 03DC38 7F009108 2462FFBC */  addiu $v0, $v1, -0x44
/* 03DC3C 7F00910C 04430005 */  bgezl $v0, .L7F009124
/* 03DC40 7F009110 44822000 */   mtc1  $v0, $f4
/* 03DC44 7F009114 00431021 */  addu  $v0, $v0, $v1
.L7F009118:
/* 03DC48 7F009118 0442FFFF */  bltzl $v0, .L7F009118
/* 03DC4C 7F00911C 00431021 */   addu  $v0, $v0, $v1
/* 03DC50 7F009120 44822000 */  mtc1  $v0, $f4
.L7F009124:
/* 03DC54 7F009124 3C018005 */  lui   $at, %hi(D_8004F2DC)
/* 03DC58 7F009128 C426F2DC */  lwc1  $f6, %lo(D_8004F2DC)($at)
/* 03DC5C 7F00912C 46802120 */  cvt.s.w $f4, $f4
/* 03DC60 7F009130 44804000 */  mtc1  $zero, $f8
/* 03DC64 7F009134 8E240000 */  lw    $a0, ($s1)
/* 03DC68 7F009138 00003025 */  move  $a2, $zero
/* 03DC6C 7F00913C E7A60010 */  swc1  $f6, 0x10($sp)
/* 03DC70 7F009140 E7A80014 */  swc1  $f8, 0x14($sp)
/* 03DC74 7F009144 44072000 */  mfc1  $a3, $f4
/* 03DC78 7F009148 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 03DC7C 7F00914C 00000000 */   nop   
/* 03DC80 7F009150 3C108004 */  lui   $s0, %hi(PitemZ_entries)
/* 03DC84 7F009154 2610A228 */  addiu $s0, %lo(PitemZ_entries) # addiu $s0, $s0, -0x5dd8
/* 03DC88 7F009158 27B90040 */  addiu $t9, $sp, 0x40
/* 03DC8C 7F00915C AFB90010 */  sw    $t9, 0x10($sp)
/* 03DC90 7F009160 8E0408F4 */  lw    $a0, 0x8f4($s0)
/* 03DC94 7F009164 8E0508F8 */  lw    $a1, 0x8f8($s0)
/* 03DC98 7F009168 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DC9C 7F00916C 0FC1D929 */  jal   load_object_fill_header
/* 03DCA0 7F009170 8FA70064 */   lw    $a3, 0x64($sp)
/* 03DCA4 7F009174 0FC2F462 */  jal   sub_GAME_7F0BD188
/* 03DCA8 7F009178 8E0408F8 */   lw    $a0, 0x8f8($s0)
/* 03DCAC 7F00917C 2443003F */  addiu $v1, $v0, 0x3f
/* 03DCB0 7F009180 8FAD0064 */  lw    $t5, 0x64($sp)
/* 03DCB4 7F009184 8FAA0060 */  lw    $t2, 0x60($sp)
/* 03DCB8 7F009188 3468003F */  ori   $t0, $v1, 0x3f
/* 03DCBC 7F00918C 3909003F */  xori  $t1, $t0, 0x3f
/* 03DCC0 7F009190 01A96023 */  subu  $t4, $t5, $t1
/* 03DCC4 7F009194 01495821 */  addu  $t3, $t2, $t1
/* 03DCC8 7F009198 AFAC0064 */  sw    $t4, 0x64($sp)
/* 03DCCC 7F00919C AFAB0060 */  sw    $t3, 0x60($sp)
/* 03DCD0 7F0091A0 0FC1D73D */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 03DCD4 7F0091A4 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03DCD8 7F0091A8 0FC1B025 */  jal   get_obj_instance_controller_for_header
/* 03DCDC 7F0091AC 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03DCE0 7F0091B0 3C108003 */  lui   $s0, %hi(D_8002A7F8)
/* 03DCE4 7F0091B4 2610A7F8 */  addiu $s0, %lo(D_8002A7F8) # addiu $s0, $s0, -0x5808
/* 03DCE8 7F0091B8 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03DCEC 7F0091BC AE020000 */  sw    $v0, ($s0)
/* 03DCF0 7F0091C0 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03DCF4 7F0091C4 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 03DCF8 7F0091C8 00402025 */   move  $a0, $v0
/* 03DCFC 7F0091CC 8E2E0000 */  lw    $t6, ($s1)
/* 03DD00 7F0091D0 8E0F0000 */  lw    $t7, ($s0)
/* 03DD04 7F0091D4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069594)
/* 03DD08 7F0091D8 ADEE0018 */  sw    $t6, 0x18($t7)
/* 03DD0C 7F0091DC 8E380000 */  lw    $t8, ($s1)
/* 03DD10 7F0091E0 8E0D0000 */  lw    $t5, ($s0)
/* 03DD14 7F0091E4 8F190008 */  lw    $t9, 8($t8)
/* 03DD18 7F0091E8 8F280008 */  lw    $t0, 8($t9)
/* 03DD1C 7F0091EC 8D09000C */  lw    $t1, 0xc($t0)
/* 03DD20 7F0091F0 ADA9001C */  sw    $t1, 0x1c($t5)
/* 03DD24 7F0091F4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03DD28 7F0091F8 8FB10028 */  lw    $s1, 0x28($sp)
/* 03DD2C 7F0091FC 8FB00024 */  lw    $s0, 0x24($sp)
/* 03DD30 7F009200 AC209594 */  sw    $zero, %lo(dword_CODE_bss_80069594)($at)
/* 03DD34 7F009204 03E00008 */  jr    $ra
/* 03DD38 7F009208 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F00920C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F00920C
/* 03DD3C 7F00920C 3C048003 */  lui   $a0, %hi(D_8002A7F4)
/* 03DD40 7F009210 8C84A7F4 */  lw    $a0, %lo(D_8002A7F4)($a0)
/* 03DD44 7F009214 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03DD48 7F009218 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03DD4C 7F00921C 10800003 */  beqz  $a0, .L7F00922C
/* 03DD50 7F009220 00000000 */   nop   
/* 03DD54 7F009224 0FC1B0FE */  jal   set_aircraft_obj_inst_scale_to_zero
/* 03DD58 7F009228 00000000 */   nop   
.L7F00922C:
/* 03DD5C 7F00922C 3C048003 */  lui   $a0, %hi(D_8002A7F8)
/* 03DD60 7F009230 8C84A7F8 */  lw    $a0, %lo(D_8002A7F8)($a0)
/* 03DD64 7F009234 50800004 */  beql  $a0, $zero, .L7F009248
/* 03DD68 7F009238 8FBF0014 */   lw    $ra, 0x14($sp)
/* 03DD6C 7F00923C 0FC1B08D */  jal   set_obj_instance_scale_to_zero
/* 03DD70 7F009240 00000000 */   nop   
/* 03DD74 7F009244 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F009248:
/* 03DD78 7F009248 27BD0018 */  addiu $sp, $sp, 0x18
/* 03DD7C 7F00924C 03E00008 */  jr    $ra
/* 03DD80 7F009250 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F009254(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel jpt_8004F2E0
    .word .L7F0092A4
    .word .L7F009344
    .word .L7F009428
    .word .L7F00949C
    .word .L7F009550
    .word .L7F009610
    .word .L7F0096D8
glabel D_8004F2FC
.word 0x44adc000
glabel D_8004F300
.word 0x449f8000
glabel D_8004F304
.word 0x40ba2fbd
.text
glabel sub_GAME_7F009254
/* 03DD84 7F009254 3C028003 */  lui   $v0, %hi(D_8002A7D0)
/* 03DD88 7F009258 2442A7D0 */  addiu $v0, %lo(D_8002A7D0) # addiu $v0, $v0, -0x5830
/* 03DD8C 7F00925C 8C4E0000 */  lw    $t6, ($v0)
/* 03DD90 7F009260 240F0001 */  li    $t7, 1
/* 03DD94 7F009264 3C198003 */  lui   $t9, %hi(D_8002A7D4) 
/* 03DD98 7F009268 01EEC023 */  subu  $t8, $t7, $t6
/* 03DD9C 7F00926C AC580000 */  sw    $t8, ($v0)
/* 03DDA0 7F009270 9339A7D4 */  lbu   $t9, %lo(D_8002A7D4)($t9)
/* 03DDA4 7F009274 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03DDA8 7F009278 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03DDAC 7F00927C 2728FFFE */  addiu $t0, $t9, -2
/* 03DDB0 7F009280 2D010007 */  sltiu $at, $t0, 7
/* 03DDB4 7F009284 1020012A */  beqz  $at, .L7F009730
/* 03DDB8 7F009288 00802825 */   move  $a1, $a0
/* 03DDBC 7F00928C 00084080 */  sll   $t0, $t0, 2
/* 03DDC0 7F009290 3C018005 */  lui   $at, %hi(jpt_8004F2E0)
/* 03DDC4 7F009294 00280821 */  addu  $at, $at, $t0
/* 03DDC8 7F009298 8C28F2E0 */  lw    $t0, %lo(jpt_8004F2E0)($at)
/* 03DDCC 7F00929C 01000008 */  jr    $t0
/* 03DDD0 7F0092A0 00000000 */   nop   
.L7F0092A4:
/* 03DDD4 7F0092A4 0FC01E90 */  jal   something_with_gunbarrel_and_rareware_logo_matrix_manip
/* 03DDD8 7F0092A8 00A02025 */   move  $a0, $a1
/* 03DDDC 7F0092AC 3C078007 */  lui   $a3, %hi(x)
/* 03DDE0 7F0092B0 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03DDE4 7F0092B4 3C0140C0 */  li    $at, 0x40C00000 # 6.000000
/* 03DDE8 7F0092B8 44813000 */  mtc1  $at, $f6
/* 03DDEC 7F0092BC C4E40000 */  lwc1  $f4, ($a3)
/* 03DDF0 7F0092C0 3C038007 */  lui   $v1, %hi(word_CODE_bss_80069584)
/* 03DDF4 7F0092C4 24639584 */  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
/* 03DDF8 7F0092C8 46062200 */  add.s $f8, $f4, $f6
/* 03DDFC 7F0092CC 84640000 */  lh    $a0, ($v1)
/* 03DE00 7F0092D0 00402825 */  move  $a1, $v0
/* 03DE04 7F0092D4 0481000A */  bgez  $a0, .L7F009300
/* 03DE08 7F0092D8 E4E80000 */   swc1  $f8, ($a3)
/* 03DE0C 7F0092DC 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 03DE10 7F0092E0 44815000 */  mtc1  $at, $f10
/* 03DE14 7F0092E4 C4E00000 */  lwc1  $f0, ($a3)
/* 03DE18 7F0092E8 240900C8 */  li    $t1, 200
/* 03DE1C 7F0092EC A4690000 */  sh    $t1, ($v1)
/* 03DE20 7F0092F0 460A0401 */  sub.s $f16, $f0, $f10
/* 03DE24 7F0092F4 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03DE28 7F0092F8 10000004 */  b     .L7F00930C
/* 03DE2C 7F0092FC E430957C */   swc1  $f16, %lo(dword_CODE_bss_8006957C)($at)
.L7F009300:
/* 03DE30 7F009300 248AFFFA */  addiu $t2, $a0, -6
/* 03DE34 7F009304 A46A0000 */  sh    $t2, ($v1)
/* 03DE38 7F009308 C4E00000 */  lwc1  $f0, ($a3)
.L7F00930C:
/* 03DE3C 7F00930C 3C018005 */  lui   $at, %hi(D_8004F2FC)
/* 03DE40 7F009310 C432F2FC */  lwc1  $f18, %lo(D_8004F2FC)($at)
/* 03DE44 7F009314 4600903C */  c.lt.s $f18, $f0
/* 03DE48 7F009318 00000000 */  nop   
/* 03DE4C 7F00931C 45000104 */  bc1f  .L7F009730
/* 03DE50 7F009320 3C0B8003 */   lui   $t3, %hi(D_8002A7D4) 
/* 03DE54 7F009324 916BA7D4 */  lbu   $t3, %lo(D_8002A7D4)($t3)
/* 03DE58 7F009328 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03DE5C 7F00932C 256C0001 */  addiu $t4, $t3, 1
/* 03DE60 7F009330 A02CA7D4 */  sb    $t4, %lo(D_8002A7D4)($at)
/* 03DE64 7F009334 3C018005 */  lui   $at, %hi(D_8004F300)
/* 03DE68 7F009338 C424F300 */  lwc1  $f4, %lo(D_8004F300)($at)
/* 03DE6C 7F00933C 100000FC */  b     .L7F009730
/* 03DE70 7F009340 E4E40000 */   swc1  $f4, ($a3)
.L7F009344:
/* 03DE74 7F009344 3C0F0100 */  lui   $t7, 0x100
/* 03DE78 7F009348 25EF0000 */  addiu $t7, $t7, 0
/* 03DE7C 7F00934C 00A01025 */  move  $v0, $a1
/* 03DE80 7F009350 3C0D0600 */  lui   $t5, 0x600
/* 03DE84 7F009354 AC4D0000 */  sw    $t5, ($v0)
/* 03DE88 7F009358 AC4F0004 */  sw    $t7, 4($v0)
/* 03DE8C 7F00935C 0FC07034 */  jal   insert_imageDL
/* 03DE90 7F009360 24A40008 */   addiu $a0, $a1, 8
/* 03DE94 7F009364 0FC07034 */  jal   insert_imageDL
/* 03DE98 7F009368 00402025 */   move  $a0, $v0
/* 03DE9C 7F00936C 0FC07034 */  jal   insert_imageDL
/* 03DEA0 7F009370 00402025 */   move  $a0, $v0
/* 03DEA4 7F009374 0FC07034 */  jal   insert_imageDL
/* 03DEA8 7F009378 00402025 */   move  $a0, $v0
/* 03DEAC 7F00937C 0FC07034 */  jal   insert_imageDL
/* 03DEB0 7F009380 00402025 */   move  $a0, $v0
/* 03DEB4 7F009384 0FC01F63 */  jal   insert_sniper_sight_eye_intro
/* 03DEB8 7F009388 00402025 */   move  $a0, $v0
/* 03DEBC 7F00938C 0FC01EE5 */  jal   insert_sight_backdrop_eye_intro
/* 03DEC0 7F009390 00402025 */   move  $a0, $v0
/* 03DEC4 7F009394 3C078007 */  lui   $a3, %hi(x)
/* 03DEC8 7F009398 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03DECC 7F00939C 3C014416 */  li    $at, 0x44160000 # 600.000000
/* 03DED0 7F0093A0 44813000 */  mtc1  $at, $f6
/* 03DED4 7F0093A4 C4E00000 */  lwc1  $f0, ($a3)
/* 03DED8 7F0093A8 00402825 */  move  $a1, $v0
/* 03DEDC 7F0093AC 4606003C */  c.lt.s $f0, $f6
/* 03DEE0 7F0093B0 00000000 */  nop   
/* 03DEE4 7F0093B4 45000007 */  bc1f  .L7F0093D4
/* 03DEE8 7F0093B8 00000000 */   nop   
/* 03DEEC 7F0093BC 0FC020B2 */  jal   insert_bond_eye_intro
/* 03DEF0 7F0093C0 00402025 */   move  $a0, $v0
/* 03DEF4 7F0093C4 3C078007 */  lui   $a3, %hi(x)
/* 03DEF8 7F0093C8 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03DEFC 7F0093CC C4E00000 */  lwc1  $f0, ($a3)
/* 03DF00 7F0093D0 00402825 */  move  $a1, $v0
.L7F0093D4:
/* 03DF04 7F0093D4 3C018005 */  lui   $at, %hi(D_8004F304)
/* 03DF08 7F0093D8 C428F304 */  lwc1  $f8, %lo(D_8004F304)($at)
/* 03DF0C 7F0093DC 3C01C2A0 */  li    $at, 0xC2A00000 # -80.000000
/* 03DF10 7F0093E0 44818000 */  mtc1  $at, $f16
/* 03DF14 7F0093E4 46080281 */  sub.s $f10, $f0, $f8
/* 03DF18 7F0093E8 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03DF1C 7F0093EC 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03DF20 7F0093F0 3C0E8003 */  lui   $t6, %hi(D_8002A7D4) 
/* 03DF24 7F0093F4 E4EA0000 */  swc1  $f10, ($a3)
/* 03DF28 7F0093F8 C4F20000 */  lwc1  $f18, ($a3)
/* 03DF2C 7F0093FC 4610903E */  c.le.s $f18, $f16
/* 03DF30 7F009400 00000000 */  nop   
/* 03DF34 7F009404 450200CB */  bc1fl .L7F009734
/* 03DF38 7F009408 8FBF0014 */   lw    $ra, 0x14($sp)
/* 03DF3C 7F00940C 91CEA7D4 */  lbu   $t6, %lo(D_8002A7D4)($t6)
/* 03DF40 7F009410 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03DF44 7F009414 24190014 */  li    $t9, 20
/* 03DF48 7F009418 25D80001 */  addiu $t8, $t6, 1
/* 03DF4C 7F00941C A038A7D4 */  sb    $t8, %lo(D_8002A7D4)($at)
/* 03DF50 7F009420 100000C3 */  b     .L7F009730
/* 03DF54 7F009424 ACD90000 */   sw    $t9, ($a2)
.L7F009428:
/* 03DF58 7F009428 0FC01F63 */  jal   insert_sniper_sight_eye_intro
/* 03DF5C 7F00942C 00A02025 */   move  $a0, $a1
/* 03DF60 7F009430 0FC01EE5 */  jal   insert_sight_backdrop_eye_intro
/* 03DF64 7F009434 00402025 */   move  $a0, $v0
/* 03DF68 7F009438 0FC020B2 */  jal   insert_bond_eye_intro
/* 03DF6C 7F00943C 00402025 */   move  $a0, $v0
/* 03DF70 7F009440 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03DF74 7F009444 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03DF78 7F009448 8CC80000 */  lw    $t0, ($a2)
/* 03DF7C 7F00944C 00402825 */  move  $a1, $v0
/* 03DF80 7F009450 3C0B8003 */  lui   $t3, %hi(D_8002A7D4) 
/* 03DF84 7F009454 2509FFFF */  addiu $t1, $t0, -1
/* 03DF88 7F009458 052100B5 */  bgez  $t1, .L7F009730
/* 03DF8C 7F00945C ACC90000 */   sw    $t1, ($a2)
/* 03DF90 7F009460 916BA7D4 */  lbu   $t3, %lo(D_8002A7D4)($t3)
/* 03DF94 7F009464 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03DF98 7F009468 00002025 */  move  $a0, $zero
/* 03DF9C 7F00946C 256C0001 */  addiu $t4, $t3, 1
/* 03DFA0 7F009470 A02CA7D4 */  sb    $t4, %lo(D_8002A7D4)($at)
/* 03DFA4 7F009474 0FC070A1 */  jal   die_blood_image_routine
/* 03DFA8 7F009478 AFA20018 */   sw    $v0, 0x18($sp)
/* 03DFAC 7F00947C 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03DFB0 7F009480 3C018003 */  lui   $at, %hi(intro_state_blood_animation)
/* 03DFB4 7F009484 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03DFB8 7F009488 AC20A8A4 */  sw    $zero, %lo(intro_state_blood_animation)($at)
/* 03DFBC 7F00948C 240D0001 */  li    $t5, 1
/* 03DFC0 7F009490 8FA50018 */  lw    $a1, 0x18($sp)
/* 03DFC4 7F009494 100000A6 */  b     .L7F009730
/* 03DFC8 7F009498 ACCD0000 */   sw    $t5, ($a2)
.L7F00949C:
/* 03DFCC 7F00949C 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03DFD0 7F0094A0 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03DFD4 7F0094A4 8CCF0000 */  lw    $t7, ($a2)
/* 03DFD8 7F0094A8 24040001 */  li    $a0, 1
/* 03DFDC 7F0094AC 25EEFFFF */  addiu $t6, $t7, -1
/* 03DFE0 7F0094B0 15C0000A */  bnez  $t6, .L7F0094DC
/* 03DFE4 7F0094B4 ACCE0000 */   sw    $t6, ($a2)
/* 03DFE8 7F0094B8 0FC070A1 */  jal   die_blood_image_routine
/* 03DFEC 7F0094BC AFA50018 */   sw    $a1, 0x18($sp)
/* 03DFF0 7F0094C0 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03DFF4 7F0094C4 3C018003 */  lui   $at, %hi(intro_state_blood_animation)
/* 03DFF8 7F0094C8 AC22A8A4 */  sw    $v0, %lo(intro_state_blood_animation)($at)
/* 03DFFC 7F0094CC 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E000 7F0094D0 24190002 */  li    $t9, 2
/* 03E004 7F0094D4 8FA50018 */  lw    $a1, 0x18($sp)
/* 03E008 7F0094D8 ACD90000 */  sw    $t9, ($a2)
.L7F0094DC:
/* 03E00C 7F0094DC 0FC01F63 */  jal   insert_sniper_sight_eye_intro
/* 03E010 7F0094E0 00A02025 */   move  $a0, $a1
/* 03E014 7F0094E4 0FC01EE5 */  jal   insert_sight_backdrop_eye_intro
/* 03E018 7F0094E8 00402025 */   move  $a0, $v0
/* 03E01C 7F0094EC 0FC020B2 */  jal   insert_bond_eye_intro
/* 03E020 7F0094F0 00402025 */   move  $a0, $v0
/* 03E024 7F0094F4 0FC07100 */  jal   sub_GAME_7F01C400
/* 03E028 7F0094F8 00402025 */   move  $a0, $v0
/* 03E02C 7F0094FC 3C088003 */  lui   $t0, %hi(intro_state_blood_animation) 
/* 03E030 7F009500 8D08A8A4 */  lw    $t0, %lo(intro_state_blood_animation)($t0)
/* 03E034 7F009504 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E038 7F009508 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E03C 7F00950C 11000088 */  beqz  $t0, .L7F009730
/* 03E040 7F009510 00402825 */   move  $a1, $v0
/* 03E044 7F009514 3C098003 */  lui   $t1, %hi(D_8002A7D4) 
/* 03E048 7F009518 9129A7D4 */  lbu   $t1, %lo(D_8002A7D4)($t1)
/* 03E04C 7F00951C 3C078007 */  lui   $a3, %hi(x)
/* 03E050 7F009520 3C018003 */  lui   $at, %hi(D_8002A7D4)
/* 03E054 7F009524 252A0001 */  addiu $t2, $t1, 1
/* 03E058 7F009528 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03E05C 7F00952C A02AA7D4 */  sb    $t2, %lo(D_8002A7D4)($at)
/* 03E060 7F009530 C4E40000 */  lwc1  $f4, ($a3)
/* 03E064 7F009534 3C038007 */  lui   $v1, %hi(word_CODE_bss_80069584)
/* 03E068 7F009538 24639584 */  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
/* 03E06C 7F00953C A4600000 */  sh    $zero, ($v1)
/* 03E070 7F009540 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03E074 7F009544 E424957C */  swc1  $f4, %lo(dword_CODE_bss_8006957C)($at)
/* 03E078 7F009548 10000079 */  b     .L7F009730
/* 03E07C 7F00954C ACC00000 */   sw    $zero, ($a2)
.L7F009550:
/* 03E080 7F009550 3C038007 */  lui   $v1, %hi(word_CODE_bss_80069584)
/* 03E084 7F009554 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E088 7F009558 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E08C 7F00955C 24639584 */  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
/* 03E090 7F009560 846B0000 */  lh    $t3, ($v1)
/* 03E094 7F009564 8CCD0000 */  lw    $t5, ($a2)
/* 03E098 7F009568 AFA50018 */  sw    $a1, 0x18($sp)
/* 03E09C 7F00956C 256C038E */  addiu $t4, $t3, 0x38e
/* 03E0A0 7F009570 25AF0001 */  addiu $t7, $t5, 1
/* 03E0A4 7F009574 A46C0000 */  sh    $t4, ($v1)
/* 03E0A8 7F009578 ACCF0000 */  sw    $t7, ($a2)
/* 03E0AC 7F00957C 0C005B18 */  jal   sins
/* 03E0B0 7F009580 3184FFFF */   andi  $a0, $t4, 0xffff
/* 03E0B4 7F009584 44823000 */  mtc1  $v0, $f6
/* 03E0B8 7F009588 3C014280 */  li    $at, 0x42800000 # 64.000000
/* 03E0BC 7F00958C 44815000 */  mtc1  $at, $f10
/* 03E0C0 7F009590 46803220 */  cvt.s.w $f8, $f6
/* 03E0C4 7F009594 3C014700 */  li    $at, 0x47000000 # 32768.000000
/* 03E0C8 7F009598 44819000 */  mtc1  $at, $f18
/* 03E0CC 7F00959C 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03E0D0 7F0095A0 C426957C */  lwc1  $f6, %lo(dword_CODE_bss_8006957C)($at)
/* 03E0D4 7F0095A4 3C078007 */  lui   $a3, %hi(x)
/* 03E0D8 7F0095A8 460A4402 */  mul.s $f16, $f8, $f10
/* 03E0DC 7F0095AC 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03E0E0 7F0095B0 8FA40018 */  lw    $a0, 0x18($sp)
/* 03E0E4 7F0095B4 46128103 */  div.s $f4, $f16, $f18
/* 03E0E8 7F0095B8 46062200 */  add.s $f8, $f4, $f6
/* 03E0EC 7F0095BC 0FC01F63 */  jal   insert_sniper_sight_eye_intro
/* 03E0F0 7F0095C0 E4E80000 */   swc1  $f8, ($a3)
/* 03E0F4 7F0095C4 0FC01EE5 */  jal   insert_sight_backdrop_eye_intro
/* 03E0F8 7F0095C8 00402025 */   move  $a0, $v0
/* 03E0FC 7F0095CC 0FC020B2 */  jal   insert_bond_eye_intro
/* 03E100 7F0095D0 00402025 */   move  $a0, $v0
/* 03E104 7F0095D4 0FC07286 */  jal   sub_GAME_7F01CA18
/* 03E108 7F0095D8 00402025 */   move  $a0, $v0
/* 03E10C 7F0095DC 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E110 7F0095E0 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E114 7F0095E4 8CCE0000 */  lw    $t6, ($a2)
/* 03E118 7F0095E8 00402825 */  move  $a1, $v0
/* 03E11C 7F0095EC 3C028003 */  lui   $v0, %hi(D_8002A7D4)
/* 03E120 7F0095F0 29C1006C */  slti  $at, $t6, 0x6c
/* 03E124 7F0095F4 1420004E */  bnez  $at, .L7F009730
/* 03E128 7F0095F8 2442A7D4 */   addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
/* 03E12C 7F0095FC 90580000 */  lbu   $t8, ($v0)
/* 03E130 7F009600 ACC00000 */  sw    $zero, ($a2)
/* 03E134 7F009604 27190001 */  addiu $t9, $t8, 1
/* 03E138 7F009608 10000049 */  b     .L7F009730
/* 03E13C 7F00960C A0590000 */   sb    $t9, ($v0)
.L7F009610:
/* 03E140 7F009610 3C038007 */  lui   $v1, %hi(word_CODE_bss_80069584)
/* 03E144 7F009614 24639584 */  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
/* 03E148 7F009618 84680000 */  lh    $t0, ($v1)
/* 03E14C 7F00961C AFA50018 */  sw    $a1, 0x18($sp)
/* 03E150 7F009620 2509038E */  addiu $t1, $t0, 0x38e
/* 03E154 7F009624 A4690000 */  sh    $t1, ($v1)
/* 03E158 7F009628 0C005B18 */  jal   sins
/* 03E15C 7F00962C 3124FFFF */   andi  $a0, $t1, 0xffff
/* 03E160 7F009630 44825000 */  mtc1  $v0, $f10
/* 03E164 7F009634 3C014280 */  li    $at, 0x42800000 # 64.000000
/* 03E168 7F009638 44819000 */  mtc1  $at, $f18
/* 03E16C 7F00963C 46805420 */  cvt.s.w $f16, $f10
/* 03E170 7F009640 3C014700 */  li    $at, 0x47000000 # 32768.000000
/* 03E174 7F009644 44813000 */  mtc1  $at, $f6
/* 03E178 7F009648 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03E17C 7F00964C C42A957C */  lwc1  $f10, %lo(dword_CODE_bss_8006957C)($at)
/* 03E180 7F009650 3C078007 */  lui   $a3, %hi(x)
/* 03E184 7F009654 46128102 */  mul.s $f4, $f16, $f18
/* 03E188 7F009658 24E79574 */  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
/* 03E18C 7F00965C 8FA40018 */  lw    $a0, 0x18($sp)
/* 03E190 7F009660 46062203 */  div.s $f8, $f4, $f6
/* 03E194 7F009664 460A4400 */  add.s $f16, $f8, $f10
/* 03E198 7F009668 0FC01F63 */  jal   insert_sniper_sight_eye_intro
/* 03E19C 7F00966C E4F00000 */   swc1  $f16, ($a3)
/* 03E1A0 7F009670 0FC01EE5 */  jal   insert_sight_backdrop_eye_intro
/* 03E1A4 7F009674 00402025 */   move  $a0, $v0
/* 03E1A8 7F009678 0FC020B2 */  jal   insert_bond_eye_intro
/* 03E1AC 7F00967C 00402025 */   move  $a0, $v0
/* 03E1B0 7F009680 0FC07286 */  jal   sub_GAME_7F01CA18
/* 03E1B4 7F009684 00402025 */   move  $a0, $v0
/* 03E1B8 7F009688 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E1BC 7F00968C 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E1C0 7F009690 8CCA0000 */  lw    $t2, ($a2)
/* 03E1C4 7F009694 00402025 */  move  $a0, $v0
/* 03E1C8 7F009698 25450008 */  addiu $a1, $t2, 8
/* 03E1CC 7F00969C 0FC01F9C */  jal   sub_GAME_7F007E70
/* 03E1D0 7F0096A0 ACC50000 */   sw    $a1, ($a2)
/* 03E1D4 7F0096A4 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E1D8 7F0096A8 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E1DC 7F0096AC 8CCC0000 */  lw    $t4, ($a2)
/* 03E1E0 7F0096B0 00402825 */  move  $a1, $v0
/* 03E1E4 7F0096B4 3C028003 */  lui   $v0, %hi(D_8002A7D4)
/* 03E1E8 7F0096B8 298100F7 */  slti  $at, $t4, 0xf7
/* 03E1EC 7F0096BC 1420001C */  bnez  $at, .L7F009730
/* 03E1F0 7F0096C0 2442A7D4 */   addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
/* 03E1F4 7F0096C4 904D0000 */  lbu   $t5, ($v0)
/* 03E1F8 7F0096C8 ACC00000 */  sw    $zero, ($a2)
/* 03E1FC 7F0096CC 25AF0001 */  addiu $t7, $t5, 1
/* 03E200 7F0096D0 10000017 */  b     .L7F009730
/* 03E204 7F0096D4 A04F0000 */   sb    $t7, ($v0)
.L7F0096D8:
/* 03E208 7F0096D8 3C180100 */  lui   $t8, 0x100
/* 03E20C 7F0096DC 27180000 */  addiu $t8, $t8, 0
/* 03E210 7F0096E0 00A01025 */  move  $v0, $a1
/* 03E214 7F0096E4 3C0E0600 */  lui   $t6, 0x600
/* 03E218 7F0096E8 AC4E0000 */  sw    $t6, ($v0)
/* 03E21C 7F0096EC AC580004 */  sw    $t8, 4($v0)
/* 03E220 7F0096F0 0FC07034 */  jal   insert_imageDL
/* 03E224 7F0096F4 24A40008 */   addiu $a0, $a1, 8
/* 03E228 7F0096F8 3C068003 */  lui   $a2, %hi(intro_eye_counter)
/* 03E22C 7F0096FC 24C6A8A0 */  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
/* 03E230 7F009700 8CC30000 */  lw    $v1, ($a2)
/* 03E234 7F009704 00402825 */  move  $a1, $v0
/* 03E238 7F009708 3C028003 */  lui   $v0, %hi(D_8002A7D4)
/* 03E23C 7F00970C 2864001E */  slti  $a0, $v1, 0x1e
/* 03E240 7F009710 24790001 */  addiu $t9, $v1, 1
/* 03E244 7F009714 14800006 */  bnez  $a0, .L7F009730
/* 03E248 7F009718 ACD90000 */   sw    $t9, ($a2)
/* 03E24C 7F00971C 2442A7D4 */  addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
/* 03E250 7F009720 90480000 */  lbu   $t0, ($v0)
/* 03E254 7F009724 ACC00000 */  sw    $zero, ($a2)
/* 03E258 7F009728 25090001 */  addiu $t1, $t0, 1
/* 03E25C 7F00972C A0490000 */  sb    $t1, ($v0)
def_7F00929C:
.L7F009730:
/* 03E260 7F009730 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F009734:
/* 03E264 7F009734 27BD0018 */  addiu $sp, $sp, 0x18
/* 03E268 7F009738 00A01025 */  move  $v0, $a1
/* 03E26C 7F00973C 03E00008 */  jr    $ra
/* 03E270 7F009740 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F009744(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F009744
/* 03E274 7F009744 3C028003 */  lui   $v0, %hi(D_8002A7D4)
/* 03E278 7F009748 9042A7D4 */  lbu   $v0, %lo(D_8002A7D4)($v0)
/* 03E27C 7F00974C 384E0009 */  xori  $t6, $v0, 9
/* 03E280 7F009750 03E00008 */  jr    $ra
/* 03E284 7F009754 2DC20001 */   sltiu $v0, $t6, 1
)
#endif


