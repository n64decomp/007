#include "ultra64.h"
#include "ramrom.h"
#include "snd.h"

/**
 * @file music.c
 * This file contains code to handle music.
 */

s32 music_unused = 0;
s32 music1_track_num = 0;
u16 music1len = 0x7FFF;
s32 music2_track_num = 0;
u16 music2len = 0x7FFF;
s32 music3_track_num = 0;
u16 music3len = 0x7FFF;
s32 music1_playing = 0;
s32 music2_playing = 0;
s32 music3_playing = 0;
s16 music_tempo_array[] = {
0x6665,0x7332,0x7332,0x7998,0x7332,0x5998,0x6665,0x6665,0x6665,0x6665,0x7332,
0x6665,0x7332,0x6665,0x6665,0x7332,0x7332,0x6665,0x3FFF,0x6665,0x6665,
0x3FFF,0x6665,0x6665,0x6665,0x6665,0x6665,0x7998,0x6665,0x5998,0x6665,
0x6665,0x6665,0x6665,0x6665,0x6665,0x6665,0x5998,0x6665,0x3332,0x6665,
0x7332,0x7332,0x5998,0x7332,0x6665,0x6665,0x6665,0x6665,0x6665,0x6665,
0x6665,0x6CCB,0x6665,0x6665,0x6665,0x6665,0x6665,0x6665,0x6665,0x7332,
0x6665,0x7332,0x7998,0xFFFF };




/*not sure why this is called hp, maybe for heap? */
u32 hp[4];
u32 *ptr_sfx_buf;
s32 D_80063724;
s32 seqp_1;
s32 seqp_2;
s32 seqp_3;
void *ptr_musicdatatable;

char D_80063738[0x80];
char D_800637B8[0x7E];
s16 D_80063836;
s32 D_80063838;
s32 D_8006383C;
s32 D_80063840;
s16 musicTrack1_length;
s16 D_80063846;
s16 D_80063848;
s16 music1_length;
s16 music2_length;
s16 music3_length;
s32 music1_rate;
s32 music2_rate;
s32 music3_rate;
s32 D_8006385C;
char D_80063860[0xF8];
char D_80063958[0xF8];
char D_80063A50[0x100];
char D_80063B50[0x54];
s32 D_80063BA4;
s32 D_80063BA8;




/**
 * 75F0	700069F0
 */
#ifdef NONMATCHING
s32 audio_related(void *arg0, s32 arg1) {
    // Node 0
    if (*arg0 > 0)
    {
        loop_1:
        // Node 1
        (arg0 + 8)->unk-4 = (s32) (arg0->unk4 + arg1);
        if ((0 + 1) < *arg0)
        {
            goto loop_1;
        }
    }
    // (possible return value: 0)
}

#else
GLOBAL_ASM(
.text
glabel audio_related
/* 0075F0 700069F0 948E0000 */  lhu   $t6, ($a0)
/* 0075F4 700069F4 00001025 */  move  $v0, $zero
/* 0075F8 700069F8 00801825 */  move  $v1, $a0
/* 0075FC 700069FC 19C0000A */  blez  $t6, .L70006A28
/* 007600 70006A00 00000000 */   nop   
/* 007604 70006A04 8C6F0004 */  lw    $t7, 4($v1)
.L70006A08:
/* 007608 70006A08 24420001 */  addiu $v0, $v0, 1
/* 00760C 70006A0C 24630008 */  addiu $v1, $v1, 8
/* 007610 70006A10 01E5C021 */  addu  $t8, $t7, $a1
/* 007614 70006A14 AC78FFFC */  sw    $t8, -4($v1)
/* 007618 70006A18 94990000 */  lhu   $t9, ($a0)
/* 00761C 70006A1C 0059082A */  slt   $at, $v0, $t9
/* 007620 70006A20 5420FFF9 */  bnezl $at, .L70006A08
/* 007624 70006A24 8C6F0004 */   lw    $t7, 4($v1)
.L70006A28:
/* 007628 70006A28 03E00008 */  jr    $ra
/* 00762C 70006A2C 00000000 */   nop   
)
#endif


/**
 * 7630	70006A30
 *     loads sound and music banks into memory segment 6
 */
#ifdef NONMATCHING
void setupaudio(void) {
    s32 sp38;
    s32 sp40;
    ?32 sp50;
    ?32 sp54;
    s8 sp58;
    ?32 sp60;
    ?32 sp64;
    ?32 sp68;
    ?32 sp6C;
    ?32 sp70;
    s8 sp74;
    ?32 sp7C;
    ?32 sp80;
    ?32 sp84;
    ?32 sp88;
    ?32 sp8C;
    s8 sp90;
    ?32 sp98;
    ?32 sp9C;
    ?32 spA0;
    ?32 spA4;
    ?32 spA8;
    ?32 spAC;
    ?32 spB4;
    ?32 spBC;
    s8 spC0;
    s32 spCC;
    s32 spD4;
    ?32 spD8;
    ?32 spDC;
    ?32 spE0;
    ? temp_ret;
    u32 temp_v1;
    s32 temp_v0;
    ? temp_ret_2;
    s32 temp_v0_2;
    ? temp_ret_3;
    ? temp_ret_4;
    s32 temp_v1_2;
    ? temp_ret_5;
    ? temp_ret_6;
    s16 temp_t4;
    void *temp_a0;
    void *temp_a1;
    s32 temp_v0_3;
    u32 phi_v1;
    void *phi_a0;
    void *phi_v1_2;
    void *phi_a1;

    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        temp_ret = mempAllocBytesInBank(0x2e000, 6);
        phi_v1 = temp_ret;
loop_2:
        // Node 2
        temp_v1 = (phi_v1 + 1);
        temp_v1->unk-1 = (u8)0;
        phi_v1 = temp_v1;
        if (temp_v1 < (u32) (temp_ret + 0x2e000))
        {
            goto loop_2;
        }
        // Node 3
        alHeapInit(&hp, temp_ret, 0x2e000);
        temp_v0 = (&_sfxtblSegmentRomStart - &_sfxctlSegmentRomStart);
        sp38 = temp_v0;
        temp_ret_2 = alHeapDBAlloc(0, 0, &hp, 1, temp_v0);
        spD4 = temp_ret_2;
        romCopy(temp_ret_2, &_sfxctlSegmentRomStart, sp38);
        alBnkfNew(spD4, &_sfxtblSegmentRomStart);
        temp_v0_2 = (&_instrumentstblSegmentRomStart - &_instrumentsctlSegmentRomStart);
        sp38 = temp_v0_2;
        ptr_sfx_buf = (?32) spD4->unk4;
        temp_ret_3 = alHeapDBAlloc(0, 0, &hp, 1, temp_v0_2);
        spCC = temp_ret_3;
        romCopy(temp_ret_3, &_instrumentsctlSegmentRomStart, sp38);
        alBnkfNew(spCC, &_instrumentstblSegmentRomStart);
        D_80063724 = (?32) spCC->unk4;
        temp_ret_4 = alHeapDBAlloc(0, 0, &hp, 1, 0x10);
        ptr_musicdatatable = temp_ret_4;
        romCopy(temp_ret_4, &_musicsampletblSegmentRomStart, 0x10);
        temp_v1_2 = ((*ptr_musicdatatable * 8) + 4);
        sp40 = temp_v1_2;
        temp_ret_5 = alHeapDBAlloc(0, 0, &hp, 1, temp_v1_2);
        ptr_musicdatatable = temp_ret_5;
        romCopy(temp_ret_5, sp38, (((temp_v1_2 + 0xf) | 0xf) ^ 0xf), &ptr_musicdatatable);
        audio_related(ptr_musicdatatable, &_musicsampletblSegmentRomStart);
        D_80063838 = alHeapDBAlloc(0, 0, &hp, 1, 0x18c8);
        temp_ret_6 = alHeapDBAlloc(0, 0, &hp, 1, 0x1770);
        D_8006383C = temp_ret_6;
        D_80063840 = (s32) (temp_ret_6 + 0x7d0);
        phi_a0 = (void *) ptr_musicdatatable;
        phi_v1_2 = &D_80063738;
        phi_a1 = &D_800637B8;
loop_4:
        // Node 4
        temp_t4 = phi_a0->unk8;
        temp_a0 = (phi_a0 + 8);
        temp_a1 = (phi_a1 + 2);
        *phi_v1_2 = temp_t4;
        temp_v0_3 = (temp_t4 & 0xffff);
        temp_a1->unk-2 = (s16) temp_a0->unk2;
        if ((temp_v0_3 & 1) != 0)
        {
            // Node 5
            *phi_v1_2 = (s16) (temp_v0_3 + 1);
        }
        // Node 6
        phi_a0 = temp_a0;
        phi_v1_2 = (phi_v1_2 + 2);
        phi_a1 = temp_a1;
        if (temp_a1 != &D_80063836)
        {
            goto loop_4;
        }
        // Node 7
        spA4 = 0;
        spA8 = 0x18;
        spAC = 0x80;
        spB4 = 0;
        spC0 = (u8)6;
        spBC = 0;
        amCreateAudioMgr(&spA4, temp_a1, &D_80063836, &D_8006383C);
        
        sp88 = 0x10;
        sp8C = 0x40;
        sp90 = (u8)0x10;
        sp98 = 0;
        sp9C = 0;
        spA0 = 0;

        sp6C = 0x10;
        sp70 = 0x40;
        sp74 = (u8)0x10;
        sp7C = 0;
        sp80 = 0;
        sp84 = 0;

        sp50 = 0x10;
        sp54 = 0x40;
        sp58 = (u8)0x10;
        sp60 = 0;
        sp64 = 0;
        sp68 = 0;
        seqp_1 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        seqp_2 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        seqp_3 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        alCSPNew(seqp_1, &sp88);
        alSeqpSetBank(seqp_1, D_80063724);
        alCSPNew(seqp_2, &sp6C);
        alSeqpSetBank(seqp_2, D_80063724);
        alCSPNew(seqp_3, &sp50);
        alSeqpSetBank(seqp_3, D_80063724);
        spDC = 0x40;
        spD8 = 0x40;
        spE0 = 8;
        sfx_c_70007B20(&spD8);
        startaudiThread();
    }
    // Node 8
    return;
}
#else
GLOBAL_ASM(
.text
glabel setupaudio
/* 007630 70006A30 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 007634 70006A34 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 007638 70006A38 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 00763C 70006A3C AFBF0024 */  sw    $ra, 0x24($sp)
/* 007640 70006A40 15C00109 */  bnez  $t6, .L70006E68
/* 007644 70006A44 AFB00020 */   sw    $s0, 0x20($sp)
/* 007648 70006A48 3C040002 */  lui   $a0, (0x0002E000 >> 16) # lui $a0, 2
/* 00764C 70006A4C 3484E000 */  ori   $a0, (0x0002E000 & 0xFFFF) # ori $a0, $a0, 0xe000
/* 007650 70006A50 0C0025C8 */  jal   mempAllocBytesInBank
/* 007654 70006A54 24050006 */   li    $a1, 6
/* 007658 70006A58 3C010002 */  lui   $at, (0x0002E000 >> 16) # lui $at, 2
/* 00765C 70006A5C 3421E000 */  ori   $at, (0x0002E000 & 0xFFFF) # ori $at, $at, 0xe000
/* 007660 70006A60 00401825 */  move  $v1, $v0
/* 007664 70006A64 00402825 */  move  $a1, $v0
/* 007668 70006A68 00412021 */  addu  $a0, $v0, $at
.L70006A6C:
/* 00766C 70006A6C 24630001 */  addiu $v1, $v1, 1
/* 007670 70006A70 0064082B */  sltu  $at, $v1, $a0
/* 007674 70006A74 1420FFFD */  bnez  $at, .L70006A6C
/* 007678 70006A78 A060FFFF */   sb    $zero, -1($v1)
/* 00767C 70006A7C 3C108006 */  lui   $s0, %hi(hp)
/* 007680 70006A80 26103710 */  addiu $s0, %lo(hp) # addiu $s0, $s0, 0x3710
/* 007684 70006A84 3C060002 */  lui   $a2, (0x0002E000 >> 16) # lui $a2, 2
/* 007688 70006A88 34C6E000 */  ori   $a2, (0x0002E000 & 0xFFFF) # ori $a2, $a2, 0xe000
/* 00768C 70006A8C 0C00434C */  jal   alHeapInit
/* 007690 70006A90 02002025 */   move  $a0, $s0
/* 007694 70006A94 3C0F002F */  lui   $t7, %hi(_sfxtblSegmentRomStart) # $t7, 0x2f
/* 007698 70006A98 3C18002F */  lui   $t8, %hi(_sfxctlSegmentRomStart) # $t8, 0x2f
/* 00769C 70006A9C 2718BDE0 */  addiu $t8, %lo(_sfxctlSegmentRomStart) # addiu $t8, $t8, -0x4220
/* 0076A0 70006AA0 25EF19A0 */  addiu $t7, %lo(_sfxtblSegmentRomStart) # addiu $t7, $t7, 0x19a0
/* 0076A4 70006AA4 01F81023 */  subu  $v0, $t7, $t8
/* 0076A8 70006AA8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0076AC 70006AAC AFA20038 */  sw    $v0, 0x38($sp)
/* 0076B0 70006AB0 00002025 */  move  $a0, $zero
/* 0076B4 70006AB4 00002825 */  move  $a1, $zero
/* 0076B8 70006AB8 02003025 */  move  $a2, $s0
/* 0076BC 70006ABC 0C003AD4 */  jal   alHeapDBAlloc
/* 0076C0 70006AC0 24070001 */   li    $a3, 1
/* 0076C4 70006AC4 3C05002F */  lui   $a1, %hi(_sfxctlSegmentRomStart) # $a1, 0x2f
/* 0076C8 70006AC8 AFA200D4 */  sw    $v0, 0xd4($sp)
/* 0076CC 70006ACC 24A5BDE0 */  addiu $a1, %lo(_sfxctlSegmentRomStart) # addiu $a1, $a1, -0x4220
/* 0076D0 70006AD0 00402025 */  move  $a0, $v0
/* 0076D4 70006AD4 0C001707 */  jal   romCopy
/* 0076D8 70006AD8 8FA60038 */   lw    $a2, 0x38($sp)
/* 0076DC 70006ADC 3C05002F */  lui   $a1, %hi(_sfxtblSegmentRomStart) # $a1, 0x2f
/* 0076E0 70006AE0 24A519A0 */  addiu $a1, %lo(_sfxtblSegmentRomStart) # addiu $a1, $a1, 0x19a0
/* 0076E4 70006AE4 0C00439D */  jal   alBnkfNew
/* 0076E8 70006AE8 8FA400D4 */   lw    $a0, 0xd4($sp)
/* 0076EC 70006AEC 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0076F0 70006AF0 3C09003C */  lui   $t1, %hi(_instrumentstblSegmentRomStart) # $t1, 0x3c
/* 0076F4 70006AF4 3C0A003B */  lui   $t2, %hi(_instrumentsctlSegmentRomStart) # $t2, 0x3b
/* 0076F8 70006AF8 8F280004 */  lw    $t0, 4($t9)
/* 0076FC 70006AFC 254A4450 */  addiu $t2, %lo(_instrumentsctlSegmentRomStart) # addiu $t2, $t2, 0x4450
/* 007700 70006B00 252987F0 */  addiu $t1, %lo(_instrumentstblSegmentRomStart) # addiu $t1, $t1, -0x7810
/* 007704 70006B04 3C018006 */  lui   $at, %hi(ptr_sfx_buf)
/* 007708 70006B08 012A1023 */  subu  $v0, $t1, $t2
/* 00770C 70006B0C AFA20010 */  sw    $v0, 0x10($sp)
/* 007710 70006B10 AFA20038 */  sw    $v0, 0x38($sp)
/* 007714 70006B14 00002025 */  move  $a0, $zero
/* 007718 70006B18 00002825 */  move  $a1, $zero
/* 00771C 70006B1C 02003025 */  move  $a2, $s0
/* 007720 70006B20 24070001 */  li    $a3, 1
/* 007724 70006B24 0C003AD4 */  jal   alHeapDBAlloc
/* 007728 70006B28 AC283720 */   sw    $t0, %lo(ptr_sfx_buf)($at)
/* 00772C 70006B2C 3C05003B */  lui   $a1, %hi(_instrumentsctlSegmentRomStart) # $a1, 0x3b
/* 007730 70006B30 AFA200CC */  sw    $v0, 0xcc($sp)
/* 007734 70006B34 24A54450 */  addiu $a1, %lo(_instrumentsctlSegmentRomStart) # addiu $a1, $a1, 0x4450
/* 007738 70006B38 00402025 */  move  $a0, $v0
/* 00773C 70006B3C 0C001707 */  jal   romCopy
/* 007740 70006B40 8FA60038 */   lw    $a2, 0x38($sp)
/* 007744 70006B44 3C05003C */  lui   $a1, %hi(_instrumentstblSegmentRomStart) # $a1, 0x3c
/* 007748 70006B48 24A587F0 */  addiu $a1, %lo(_instrumentstblSegmentRomStart) # addiu $a1, $a1, -0x7810
/* 00774C 70006B4C 0C00439D */  jal   alBnkfNew
/* 007750 70006B50 8FA400CC */   lw    $a0, 0xcc($sp)
/* 007754 70006B54 8FAB00CC */  lw    $t3, 0xcc($sp)
/* 007758 70006B58 3C018006 */  lui   $at, %hi(D_80063724)
/* 00775C 70006B5C 240D0010 */  li    $t5, 16
/* 007760 70006B60 8D6C0004 */  lw    $t4, 4($t3)
/* 007764 70006B64 AFAD0010 */  sw    $t5, 0x10($sp)
/* 007768 70006B68 00002025 */  move  $a0, $zero
/* 00776C 70006B6C 00002825 */  move  $a1, $zero
/* 007770 70006B70 02003025 */  move  $a2, $s0
/* 007774 70006B74 24070001 */  li    $a3, 1
/* 007778 70006B78 0C003AD4 */  jal   alHeapDBAlloc
/* 00777C 70006B7C AC2C3724 */   sw    $t4, %lo(D_80063724)($at)
/* 007780 70006B80 3C038006 */  lui   $v1, %hi(ptr_musicdatatable)
/* 007784 70006B84 3C050042 */  lui   $a1, %hi(_musicsampletblSegmentRomStart) # $a1, 0x42
/* 007788 70006B88 24633734 */  addiu $v1, %lo(ptr_musicdatatable) # addiu $v1, $v1, 0x3734
/* 00778C 70006B8C 24A59790 */  addiu $a1, %lo(_musicsampletblSegmentRomStart) # addiu $a1, $a1, -0x6870
/* 007790 70006B90 AC620000 */  sw    $v0, ($v1)
/* 007794 70006B94 AFA50038 */  sw    $a1, 0x38($sp)
/* 007798 70006B98 00402025 */  move  $a0, $v0
/* 00779C 70006B9C 0C001707 */  jal   romCopy
/* 0077A0 70006BA0 24060010 */   li    $a2, 16
/* 0077A4 70006BA4 3C0E8006 */  lui   $t6, %hi(ptr_musicdatatable) 
/* 0077A8 70006BA8 8DCE3734 */  lw    $t6, %lo(ptr_musicdatatable)($t6)
/* 0077AC 70006BAC 00002025 */  move  $a0, $zero
/* 0077B0 70006BB0 00002825 */  move  $a1, $zero
/* 0077B4 70006BB4 95C30000 */  lhu   $v1, ($t6)
/* 0077B8 70006BB8 02003025 */  move  $a2, $s0
/* 0077BC 70006BBC 24070001 */  li    $a3, 1
/* 0077C0 70006BC0 000378C0 */  sll   $t7, $v1, 3
/* 0077C4 70006BC4 25E30004 */  addiu $v1, $t7, 4
/* 0077C8 70006BC8 AFA30010 */  sw    $v1, 0x10($sp)
/* 0077CC 70006BCC 0C003AD4 */  jal   alHeapDBAlloc
/* 0077D0 70006BD0 AFA30040 */   sw    $v1, 0x40($sp)
/* 0077D4 70006BD4 8FA30040 */  lw    $v1, 0x40($sp)
/* 0077D8 70006BD8 3C078006 */  lui   $a3, %hi(ptr_musicdatatable)
/* 0077DC 70006BDC 24E73734 */  addiu $a3, %lo(ptr_musicdatatable) # addiu $a3, $a3, 0x3734
/* 0077E0 70006BE0 2466000F */  addiu $a2, $v1, 0xf
/* 0077E4 70006BE4 34D8000F */  ori   $t8, $a2, 0xf
/* 0077E8 70006BE8 ACE20000 */  sw    $v0, ($a3)
/* 0077EC 70006BEC 3B06000F */  xori  $a2, $t8, 0xf
/* 0077F0 70006BF0 00402025 */  move  $a0, $v0
/* 0077F4 70006BF4 0C001707 */  jal   romCopy
/* 0077F8 70006BF8 8FA50038 */   lw    $a1, 0x38($sp)
/* 0077FC 70006BFC 3C048006 */  lui   $a0, %hi(ptr_musicdatatable)
/* 007800 70006C00 3C050042 */  lui   $a1, %hi(_musicsampletblSegmentRomStart) # $a1, 0x42
/* 007804 70006C04 24A59790 */  addiu $a1, %lo(_musicsampletblSegmentRomStart) # addiu $a1, $a1, -0x6870
/* 007808 70006C08 0C001A7C */  jal   audio_related
/* 00780C 70006C0C 8C843734 */   lw    $a0, %lo(ptr_musicdatatable)($a0)
/* 007810 70006C10 240818C8 */  li    $t0, 6344
/* 007814 70006C14 AFA80010 */  sw    $t0, 0x10($sp)
/* 007818 70006C18 00002025 */  move  $a0, $zero
/* 00781C 70006C1C 00002825 */  move  $a1, $zero
/* 007820 70006C20 02003025 */  move  $a2, $s0
/* 007824 70006C24 0C003AD4 */  jal   alHeapDBAlloc
/* 007828 70006C28 24070001 */   li    $a3, 1
/* 00782C 70006C2C 3C018006 */  lui   $at, %hi(D_80063838)
/* 007830 70006C30 24091770 */  li    $t1, 6000
/* 007834 70006C34 AC223838 */  sw    $v0, %lo(D_80063838)($at)
/* 007838 70006C38 AFA90010 */  sw    $t1, 0x10($sp)
/* 00783C 70006C3C 00002025 */  move  $a0, $zero
/* 007840 70006C40 00002825 */  move  $a1, $zero
/* 007844 70006C44 02003025 */  move  $a2, $s0
/* 007848 70006C48 0C003AD4 */  jal   alHeapDBAlloc
/* 00784C 70006C4C 24070001 */   li    $a3, 1
/* 007850 70006C50 3C078006 */  lui   $a3, %hi(D_8006383C)
/* 007854 70006C54 24E7383C */  addiu $a3, %lo(D_8006383C) # addiu $a3, $a3, 0x383c
/* 007858 70006C58 ACE20000 */  sw    $v0, ($a3)
/* 00785C 70006C5C 244B07D0 */  addiu $t3, $v0, 0x7d0
/* 007860 70006C60 3C018006 */  lui   $at, %hi(D_80063840)
/* 007864 70006C64 3C038006 */  lui   $v1, %hi(D_80063738)
/* 007868 70006C68 3C048006 */  lui   $a0, %hi(ptr_musicdatatable)
/* 00786C 70006C6C 3C058006 */  lui   $a1, %hi(D_800637B8)
/* 007870 70006C70 3C068006 */  lui   $a2, %hi(D_80063836)
/* 007874 70006C74 AC2B3840 */  sw    $t3, %lo(D_80063840)($at)
/* 007878 70006C78 24C63836 */  addiu $a2, %lo(D_80063836) # addiu $a2, $a2, 0x3836
/* 00787C 70006C7C 24A537B8 */  addiu $a1, %lo(D_800637B8) # addiu $a1, $a1, 0x37b8
/* 007880 70006C80 8C843734 */  lw    $a0, %lo(ptr_musicdatatable)($a0)
/* 007884 70006C84 24633738 */  addiu $v1, %lo(D_80063738) # addiu $v1, $v1, 0x3738
.L70006C88:
/* 007888 70006C88 948C0008 */  lhu   $t4, 8($a0)
/* 00788C 70006C8C 24840008 */  addiu $a0, $a0, 8
/* 007890 70006C90 24A50002 */  addiu $a1, $a1, 2
/* 007894 70006C94 A46C0000 */  sh    $t4, ($v1)
/* 007898 70006C98 948D0002 */  lhu   $t5, 2($a0)
/* 00789C 70006C9C 3182FFFF */  andi  $v0, $t4, 0xffff
/* 0078A0 70006CA0 304E0001 */  andi  $t6, $v0, 1
/* 0078A4 70006CA4 11C00003 */  beqz  $t6, .L70006CB4
/* 0078A8 70006CA8 A4ADFFFE */   sh    $t5, -2($a1)
/* 0078AC 70006CAC 244F0001 */  addiu $t7, $v0, 1
/* 0078B0 70006CB0 A46F0000 */  sh    $t7, ($v1)
.L70006CB4:
/* 0078B4 70006CB4 14A6FFF4 */  bne   $a1, $a2, .L70006C88
/* 0078B8 70006CB8 24630002 */   addiu $v1, $v1, 2
/* 0078BC 70006CBC 24180018 */  li    $t8, 24
/* 0078C0 70006CC0 24190080 */  li    $t9, 128
/* 0078C4 70006CC4 24080006 */  li    $t0, 6
/* 0078C8 70006CC8 AFA000A4 */  sw    $zero, 0xa4($sp)
/* 0078CC 70006CCC AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0078D0 70006CD0 AFB900AC */  sw    $t9, 0xac($sp)
/* 0078D4 70006CD4 AFA000B4 */  sw    $zero, 0xb4($sp)
/* 0078D8 70006CD8 A3A800C0 */  sb    $t0, 0xc0($sp)
/* 0078DC 70006CDC AFA000BC */  sw    $zero, 0xbc($sp)
/* 0078E0 70006CE0 AFB000B8 */  sw    $s0, 0xb8($sp)
/* 0078E4 70006CE4 0C0006F4 */  jal   amCreateAudioMgr
/* 0078E8 70006CE8 27A400A4 */   addiu $a0, $sp, 0xa4
/* 0078EC 70006CEC 24090010 */  li    $t1, 16
/* 0078F0 70006CF0 240A0040 */  li    $t2, 64
/* 0078F4 70006CF4 240B0010 */  li    $t3, 16
/* 0078F8 70006CF8 240C0010 */  li    $t4, 16
/* 0078FC 70006CFC 240D0040 */  li    $t5, 64
/* 007900 70006D00 240E0010 */  li    $t6, 16
/* 007904 70006D04 240F0010 */  li    $t7, 16
/* 007908 70006D08 24180040 */  li    $t8, 64
/* 00790C 70006D0C 24190010 */  li    $t9, 16
/* 007910 70006D10 2408007C */  li    $t0, 124
/* 007914 70006D14 AFA90088 */  sw    $t1, 0x88($sp)
/* 007918 70006D18 AFAA008C */  sw    $t2, 0x8c($sp)
/* 00791C 70006D1C A3AB0090 */  sb    $t3, 0x90($sp)
/* 007920 70006D20 AFB00094 */  sw    $s0, 0x94($sp)
/* 007924 70006D24 AFA00098 */  sw    $zero, 0x98($sp)
/* 007928 70006D28 AFA0009C */  sw    $zero, 0x9c($sp)
/* 00792C 70006D2C AFA000A0 */  sw    $zero, 0xa0($sp)
/* 007930 70006D30 AFAC006C */  sw    $t4, 0x6c($sp)
/* 007934 70006D34 AFAD0070 */  sw    $t5, 0x70($sp)
/* 007938 70006D38 A3AE0074 */  sb    $t6, 0x74($sp)
/* 00793C 70006D3C AFB00078 */  sw    $s0, 0x78($sp)
/* 007940 70006D40 AFA0007C */  sw    $zero, 0x7c($sp)
/* 007944 70006D44 AFA00080 */  sw    $zero, 0x80($sp)
/* 007948 70006D48 AFA00084 */  sw    $zero, 0x84($sp)
/* 00794C 70006D4C AFAF0050 */  sw    $t7, 0x50($sp)
/* 007950 70006D50 AFB80054 */  sw    $t8, 0x54($sp)
/* 007954 70006D54 A3B90058 */  sb    $t9, 0x58($sp)
/* 007958 70006D58 AFB0005C */  sw    $s0, 0x5c($sp)
/* 00795C 70006D5C AFA00060 */  sw    $zero, 0x60($sp)
/* 007960 70006D60 AFA00064 */  sw    $zero, 0x64($sp)
/* 007964 70006D64 AFA00068 */  sw    $zero, 0x68($sp)
/* 007968 70006D68 AFA80010 */  sw    $t0, 0x10($sp)
/* 00796C 70006D6C 00002025 */  move  $a0, $zero
/* 007970 70006D70 00002825 */  move  $a1, $zero
/* 007974 70006D74 02003025 */  move  $a2, $s0
/* 007978 70006D78 0C003AD4 */  jal   alHeapDBAlloc
/* 00797C 70006D7C 24070001 */   li    $a3, 1
/* 007980 70006D80 3C018006 */  lui   $at, %hi(seqp_1)
/* 007984 70006D84 2409007C */  li    $t1, 124
/* 007988 70006D88 AC223728 */  sw    $v0, %lo(seqp_1)($at)
/* 00798C 70006D8C AFA90010 */  sw    $t1, 0x10($sp)
/* 007990 70006D90 00002025 */  move  $a0, $zero
/* 007994 70006D94 00002825 */  move  $a1, $zero
/* 007998 70006D98 02003025 */  move  $a2, $s0
/* 00799C 70006D9C 0C003AD4 */  jal   alHeapDBAlloc
/* 0079A0 70006DA0 24070001 */   li    $a3, 1
/* 0079A4 70006DA4 3C018006 */  lui   $at, %hi(seqp_2)
/* 0079A8 70006DA8 240A007C */  li    $t2, 124
/* 0079AC 70006DAC AC22372C */  sw    $v0, %lo(seqp_2)($at)
/* 0079B0 70006DB0 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0079B4 70006DB4 00002025 */  move  $a0, $zero
/* 0079B8 70006DB8 00002825 */  move  $a1, $zero
/* 0079BC 70006DBC 02003025 */  move  $a2, $s0
/* 0079C0 70006DC0 0C003AD4 */  jal   alHeapDBAlloc
/* 0079C4 70006DC4 24070001 */   li    $a3, 1
/* 0079C8 70006DC8 3C018006 */  lui   $at, %hi(seqp_3)
/* 0079CC 70006DCC 3C048006 */  lui   $a0, %hi(seqp_1)
/* 0079D0 70006DD0 AC223730 */  sw    $v0, %lo(seqp_3)($at)
/* 0079D4 70006DD4 8C843728 */  lw    $a0, %lo(seqp_1)($a0)
/* 0079D8 70006DD8 0C004820 */  jal   alCSPNew
/* 0079DC 70006DDC 27A50088 */   addiu $a1, $sp, 0x88
/* 0079E0 70006DE0 3C048006 */  lui   $a0, %hi(seqp_1)
/* 0079E4 70006DE4 3C058006 */  lui   $a1, %hi(D_80063724)
/* 0079E8 70006DE8 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 0079EC 70006DEC 0C00487C */  jal   alSeqpSetBank
/* 0079F0 70006DF0 8C843728 */   lw    $a0, %lo(seqp_1)($a0)
/* 0079F4 70006DF4 3C048006 */  lui   $a0, %hi(seqp_2)
/* 0079F8 70006DF8 8C84372C */  lw    $a0, %lo(seqp_2)($a0)
/* 0079FC 70006DFC 0C004820 */  jal   alCSPNew
/* 007A00 70006E00 27A5006C */   addiu $a1, $sp, 0x6c
/* 007A04 70006E04 3C048006 */  lui   $a0, %hi(seqp_2)
/* 007A08 70006E08 3C058006 */  lui   $a1, %hi(D_80063724)
/* 007A0C 70006E0C 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 007A10 70006E10 0C00487C */  jal   alSeqpSetBank
/* 007A14 70006E14 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
/* 007A18 70006E18 3C048006 */  lui   $a0, %hi(seqp_3)
/* 007A1C 70006E1C 8C843730 */  lw    $a0, %lo(seqp_3)($a0)
/* 007A20 70006E20 0C004820 */  jal   alCSPNew
/* 007A24 70006E24 27A50050 */   addiu $a1, $sp, 0x50
/* 007A28 70006E28 3C048006 */  lui   $a0, %hi(seqp_3)
/* 007A2C 70006E2C 3C058006 */  lui   $a1, %hi(D_80063724)
/* 007A30 70006E30 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 007A34 70006E34 0C00487C */  jal   alSeqpSetBank
/* 007A38 70006E38 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
/* 007A3C 70006E3C 240B0040 */  li    $t3, 64
/* 007A40 70006E40 240C0040 */  li    $t4, 64
/* 007A44 70006E44 240D0008 */  li    $t5, 8
/* 007A48 70006E48 AFAB00DC */  sw    $t3, 0xdc($sp)
/* 007A4C 70006E4C AFAC00D8 */  sw    $t4, 0xd8($sp)
/* 007A50 70006E50 AFAD00E0 */  sw    $t5, 0xe0($sp)
/* 007A54 70006E54 AFB000E4 */  sw    $s0, 0xe4($sp)
/* 007A58 70006E58 0C001EC8 */  jal   sfx_c_70007B20
/* 007A5C 70006E5C 27A400D8 */   addiu $a0, $sp, 0xd8
/* 007A60 70006E60 0C0007D6 */  jal   startaudiThread
/* 007A64 70006E64 00000000 */   nop   
.L70006E68:
/* 007A68 70006E68 8FBF0024 */  lw    $ra, 0x24($sp)
/* 007A6C 70006E6C 8FB00020 */  lw    $s0, 0x20($sp)
/* 007A70 70006E70 27BD00E8 */  addiu $sp, $sp, 0xe8
/* 007A74 70006E74 03E00008 */  jr    $ra
/* 007A78 70006E78 00000000 */   nop   
)
#endif


/**
 * 7A7C	70006E7C
 *     play first music track A0
 */
#ifdef NONMATCHING
void musicTrack1Play(s32 arg0, s32 arg852) {
    ? sp34;
    s32 sp2140;
    void *temp_t2;
    s32 temp_v0;
    s32 temp_a2;

    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        if (music1_track_num != 0)
        {
            // Node 2
            musicTrack1Stop();
        }
        // Node 3
        music1_track_num = arg852;
        if (alCSPGetState(seqp_1) != 0)
        {
            loop_4:
            // Node 4
            if (alCSPGetState(seqp_1) != 0)
            {
                goto loop_4;
            }
        }
        // Node 5
        temp_t2 = (ptr_musicdatatable + (music1_track_num * 8));
        temp_v0 = (music1_track_num * 2);
        if ((u32) temp_t2->unk4 < 0x10000U)
        {
            // Node 6
            musicTrack1Play(1, temp_t2->unk4, music1_track_num);
            return;
            // (possible return value: musicTrack1Play(1, temp_t2->unk4, music1_track_num))
        }
        // Node 7
        temp_a2 = (((*(&D_800637B8 + temp_v0) + 0xf) | 0xf) ^ 0xf);
        sp2140 = (s32) D_80063838;
        romCopy(((D_80063838 + (((((0x80060000 + temp_v0)->unk3738 + 0xf) | 0xf) ^ 0xf) + 0x40)) - temp_a2), temp_t2->unk4, temp_a2, music1_track_num);
        decompressdata(sp28, sp2140, &sp34);
        alCSeqNew(&D_80063860, D_80063838);
        alCSPSetSeq(seqp_1, &D_80063860);
        musicTrack1Vol((musicTrack1Length() & 0xffff));
        alCSPPlay(seqp_1);
    }
    // Node 8
    return;
    // (function likely void)
}

#else
GLOBAL_ASM(
.text
glabel musicTrack1Play
/* 007A7C 70006E7C 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 007A80 70006E80 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 007A84 70006E84 27BDDEB8 */  addiu $sp, $sp, -0x2148
/* 007A88 70006E88 AFBF001C */  sw    $ra, 0x1c($sp)
/* 007A8C 70006E8C AFB00018 */  sw    $s0, 0x18($sp)
/* 007A90 70006E90 15C0004A */  bnez  $t6, .L70006FBC
/* 007A94 70006E94 AFA42148 */   sw    $a0, 0x2148($sp)
/* 007A98 70006E98 3C0F8002 */  lui   $t7, %hi(music1_track_num) 
/* 007A9C 70006E9C 8DEF4334 */  lw    $t7, %lo(music1_track_num)($t7)
/* 007AA0 70006EA0 51E00004 */  beql  $t7, $zero, .L70006EB4
/* 007AA4 70006EA4 8FB82148 */   lw    $t8, 0x2148($sp)
/* 007AA8 70006EA8 0C001BF4 */  jal   musicTrack1Stop
/* 007AAC 70006EAC 00000000 */   nop   
/* 007AB0 70006EB0 8FB82148 */  lw    $t8, 0x2148($sp)
.L70006EB4:
/* 007AB4 70006EB4 3C108006 */  lui   $s0, %hi(seqp_1)
/* 007AB8 70006EB8 3C018002 */  lui   $at, %hi(music1_track_num)
/* 007ABC 70006EBC 26103728 */  addiu $s0, %lo(seqp_1) # addiu $s0, $s0, 0x3728
/* 007AC0 70006EC0 AC384334 */  sw    $t8, %lo(music1_track_num)($at)
/* 007AC4 70006EC4 0C00488C */  jal   alCSPGetState
/* 007AC8 70006EC8 8E040000 */   lw    $a0, ($s0)
/* 007ACC 70006ECC 10400005 */  beqz  $v0, .L70006EE4
/* 007AD0 70006ED0 00000000 */   nop   
.L70006ED4:
/* 007AD4 70006ED4 0C00488C */  jal   alCSPGetState
/* 007AD8 70006ED8 8E040000 */   lw    $a0, ($s0)
/* 007ADC 70006EDC 1440FFFD */  bnez  $v0, .L70006ED4
/* 007AE0 70006EE0 00000000 */   nop   
.L70006EE4:
/* 007AE4 70006EE4 3C078002 */  lui   $a3, %hi(music1_track_num)
/* 007AE8 70006EE8 8CE74334 */  lw    $a3, %lo(music1_track_num)($a3)
/* 007AEC 70006EEC 3C198006 */  lui   $t9, %hi(ptr_musicdatatable) 
/* 007AF0 70006EF0 8F393734 */  lw    $t9, %lo(ptr_musicdatatable)($t9)
/* 007AF4 70006EF4 000748C0 */  sll   $t1, $a3, 3
/* 007AF8 70006EF8 3C010001 */  lui   $at, 1
/* 007AFC 70006EFC 03295021 */  addu  $t2, $t9, $t1
/* 007B00 70006F00 8D450004 */  lw    $a1, 4($t2)
/* 007B04 70006F04 3C038006 */  lui   $v1, %hi(D_80063738)
/* 007B08 70006F08 00071040 */  sll   $v0, $a3, 1
/* 007B0C 70006F0C 00A1082B */  sltu  $at, $a1, $at
/* 007B10 70006F10 10200005 */  beqz  $at, .L70006F28
/* 007B14 70006F14 00621821 */   addu  $v1, $v1, $v0
/* 007B18 70006F18 0C001B9F */  jal   musicTrack1Play
/* 007B1C 70006F1C 24040001 */   li    $a0, 1
/* 007B20 70006F20 10000027 */  b     .L70006FC0
/* 007B24 70006F24 8FBF001C */   lw    $ra, 0x1c($sp)
.L70006F28:
/* 007B28 70006F28 94633738 */  lhu   $v1, %lo(D_80063738)($v1)
/* 007B2C 70006F2C 3C068006 */  lui   $a2, %hi(D_800637B8)
/* 007B30 70006F30 00C23021 */  addu  $a2, $a2, $v0
/* 007B34 70006F34 94C637B8 */  lhu   $a2, %lo(D_800637B8)($a2)
/* 007B38 70006F38 3C088006 */  lui   $t0, %hi(D_80063838) 
/* 007B3C 70006F3C 2463000F */  addiu $v1, $v1, 0xf
/* 007B40 70006F40 8D083838 */  lw    $t0, %lo(D_80063838)($t0)
/* 007B44 70006F44 346B000F */  ori   $t3, $v1, 0xf
/* 007B48 70006F48 396C000F */  xori  $t4, $t3, 0xf
/* 007B4C 70006F4C 24C6000F */  addiu $a2, $a2, 0xf
/* 007B50 70006F50 25830040 */  addiu $v1, $t4, 0x40
/* 007B54 70006F54 34CD000F */  ori   $t5, $a2, 0xf
/* 007B58 70006F58 39A6000F */  xori  $a2, $t5, 0xf
/* 007B5C 70006F5C 01037821 */  addu  $t7, $t0, $v1
/* 007B60 70006F60 01E62023 */  subu  $a0, $t7, $a2
/* 007B64 70006F64 AFA40028 */  sw    $a0, 0x28($sp)
/* 007B68 70006F68 0C001707 */  jal   romCopy
/* 007B6C 70006F6C AFA82140 */   sw    $t0, 0x2140($sp)
/* 007B70 70006F70 8FA40028 */  lw    $a0, 0x28($sp)
/* 007B74 70006F74 8FA52140 */  lw    $a1, 0x2140($sp)
/* 007B78 70006F78 0FC339FC */  jal   decompressdata
/* 007B7C 70006F7C 27A60034 */   addiu $a2, $sp, 0x34
/* 007B80 70006F80 3C048006 */  lui   $a0, %hi(D_80063860)
/* 007B84 70006F84 3C058006 */  lui   $a1, %hi(D_80063838)
/* 007B88 70006F88 8CA53838 */  lw    $a1, %lo(D_80063838)($a1)
/* 007B8C 70006F8C 0C0049E7 */  jal   alCSeqNew
/* 007B90 70006F90 24843860 */   addiu $a0, %lo(D_80063860) # addiu $a0, $a0, 0x3860
/* 007B94 70006F94 3C058006 */  lui   $a1, %hi(D_80063860)
/* 007B98 70006F98 24A53860 */  addiu $a1, %lo(D_80063860) # addiu $a1, $a1, 0x3860
/* 007B9C 70006F9C 0C004B40 */  jal   alCSPSetSeq
/* 007BA0 70006FA0 8E040000 */   lw    $a0, ($s0)
/* 007BA4 70006FA4 0C001C0C */  jal   musicTrack1Length
/* 007BA8 70006FA8 00000000 */   nop   
/* 007BAC 70006FAC 0C001C0F */  jal   musicTrack1Vol
/* 007BB0 70006FB0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 007BB4 70006FB4 0C004B50 */  jal   alCSPPlay
/* 007BB8 70006FB8 8E040000 */   lw    $a0, ($s0)
.L70006FBC:
/* 007BBC 70006FBC 8FBF001C */  lw    $ra, 0x1c($sp)
.L70006FC0:
/* 007BC0 70006FC0 8FB00018 */  lw    $s0, 0x18($sp)
/* 007BC4 70006FC4 27BD2148 */  addiu $sp, $sp, 0x2148
/* 007BC8 70006FC8 03E00008 */  jr    $ra
/* 007BCC 70006FCC 00000000 */   nop   
)
#endif

/**
 * 7BD0	70006FD0
 *     stop playing first music track
 */
void musicTrack1Stop(void) {
    if (bootswitch_sound == 0)
    {
        music1_playing = 0;
        if (music1_track_num != 0)
        {
            if (alCSPGetState(seqp_1) == 1)
            {
                alCSPStop(seqp_1);
            }
        }
        music1_track_num = 0;
    }
}

/**
 * 7C30	70007030
 *     V0= [80024338]
 */
u16 musicTrack1Length(void) {
    return music1len;
}






/**
 * 7C3C	7000703C
 *     ??? - sets something for currently running music track...
 *     accepts: A0=value
 */
#ifdef NONMATCHING
void musicTrack1Vol(s32 arg0) {
    s16 temp_a2;

    // Node 0
    temp_a2 = (arg0 & 0xffff);
    music1len = temp_a2;
    alCSPSetVol(seqp_1, ((s32) (((u32) (temp_a2 * *(&music_tempo_array + (music1_track_num * 2))) >> 0xf) << 0x10) >> 0x10), temp_a2);
    return;
    // (possible return value: alCSPSetVol(seqp_1, ((s32) (((u32) (temp_a2 * *(&music_tempo_array + (music1_track_num * 2))) >> 0xf) << 0x10) >> 0x10), temp_a2))
}

#else
GLOBAL_ASM(
.text
glabel musicTrack1Vol
/* 007C3C 7000703C 3C0E8002 */  lui   $t6, %hi(music1_track_num) 
/* 007C40 70007040 8DCE4334 */  lw    $t6, %lo(music1_track_num)($t6)
/* 007C44 70007044 3C188002 */  lui   $t8, %hi(music_tempo_array)
/* 007C48 70007048 3086FFFF */  andi  $a2, $a0, 0xffff
/* 007C4C 7000704C 000E7840 */  sll   $t7, $t6, 1
/* 007C50 70007050 030FC021 */  addu  $t8, $t8, $t7
/* 007C54 70007054 87184358 */  lh    $t8, %lo(music_tempo_array)($t8)
/* 007C58 70007058 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 007C5C 7000705C AFA40018 */  sw    $a0, 0x18($sp)
/* 007C60 70007060 00D80019 */  multu $a2, $t8
/* 007C64 70007064 AFBF0014 */  sw    $ra, 0x14($sp)
/* 007C68 70007068 3C018002 */  lui   $at, %hi(music1len)
/* 007C6C 7000706C 3C048006 */  lui   $a0, %hi(seqp_1)
/* 007C70 70007070 A4264338 */  sh    $a2, %lo(music1len)($at)
/* 007C74 70007074 8C843728 */  lw    $a0, %lo(seqp_1)($a0)
/* 007C78 70007078 00001012 */  mflo  $v0
/* 007C7C 7000707C 0002CBC2 */  srl   $t9, $v0, 0xf
/* 007C80 70007080 00192C00 */  sll   $a1, $t9, 0x10
/* 007C84 70007084 00054403 */  sra   $t0, $a1, 0x10
/* 007C88 70007088 0C004B68 */  jal   alCSPSetVol
/* 007C8C 7000708C 01002825 */   move  $a1, $t0
/* 007C90 70007090 8FBF0014 */  lw    $ra, 0x14($sp)
/* 007C94 70007094 27BD0018 */  addiu $sp, $sp, 0x18
/* 007C98 70007098 03E00008 */  jr    $ra
/* 007C9C 7000709C 00000000 */   nop   
)
#endif







/**
 * 7CA0	700070A0
 */
#ifdef NONMATCHING
void *musicTrack1Tempo(void) {
    // Node 0
    *(&music_tempo_array + (music1_track_num * 2)) = musicTrack1Length();
    if (music_tempo_array >= 0)
    {
        loop_1:
        // Node 1
        if (music_tempo_array.unk2 >= 0)
        {
            goto loop_1;
        }
    }
    // (possible return value: &music_tempo_array)
}

#else
GLOBAL_ASM(
.text
glabel musicTrack1Tempo
/* 007CA0 700070A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 007CA4 700070A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 007CA8 700070A8 0C001C0C */  jal   musicTrack1Length
/* 007CAC 700070AC 00000000 */   nop   
/* 007CB0 700070B0 3C0E8002 */  lui   $t6, %hi(music1_track_num) 
/* 007CB4 700070B4 8DCE4334 */  lw    $t6, %lo(music1_track_num)($t6)
/* 007CB8 700070B8 3C048002 */  lui   $a0, %hi(music_tempo_array)
/* 007CBC 700070BC 24844358 */  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
/* 007CC0 700070C0 000E7840 */  sll   $t7, $t6, 1
/* 007CC4 700070C4 008FC021 */  addu  $t8, $a0, $t7
/* 007CC8 700070C8 A7020000 */  sh    $v0, ($t8)
/* 007CCC 700070CC 84990000 */  lh    $t9, ($a0)
/* 007CD0 700070D0 3C028002 */  lui   $v0, %hi(music_tempo_array)
/* 007CD4 700070D4 24424358 */  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
/* 007CD8 700070D8 07200005 */  bltz  $t9, .L700070F0
/* 007CDC 700070DC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 007CE0 700070E0 84480002 */  lh    $t0, 2($v0)
.L700070E4:
/* 007CE4 700070E4 24420002 */  addiu $v0, $v0, 2
/* 007CE8 700070E8 0503FFFE */  bgezl $t0, .L700070E4
/* 007CEC 700070EC 84480002 */   lh    $t0, 2($v0)
.L700070F0:
/* 007CF0 700070F0 03E00008 */  jr    $ra
/* 007CF4 700070F4 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif



/**
 * 7CF8	700070F8
 */
void music_related_1(f32 rate) {
    if (music1_playing >= 0)
    {
        musicTrack1_length = musicTrack1Length();
        music1_length = 0;
        music1_rate = (s32) (rate * 60.0f);
        music1_playing = -1;
    }
}






/**
 * 7D68	70007168
 */
#ifdef NONMATCHING
s16 music_related_3(f32 arg0, s32 arg1, f32 rate, s16 length) {
    if (music1_playing <= 0)
    {
        alCSPPlay(seqp_1);
        if (length == 0xffff)
        {
            music1_length = musicTrack1_length;
        }
        else
        {
            music1_length = length;
        }
        musicTrack1_length = (u16)0;
        music1_rate = (s32) (rate * 60.0f);
        music1_playing = 1;
    }
}
#else
GLOBAL_ASM(
.text
glabel music_related_3
/* 007D68 70007168 3C0E8002 */  lui   $t6, %hi(music1_playing) 
/* 007D6C 7000716C 8DCE434C */  lw    $t6, %lo(music1_playing)($t6)
/* 007D70 70007170 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 007D74 70007174 AFBF0014 */  sw    $ra, 0x14($sp)
/* 007D78 70007178 E7AC0018 */  swc1  $f12, 0x18($sp)
/* 007D7C 7000717C 1DC0001D */  bgtz  $t6, .L700071F4
/* 007D80 70007180 AFA5001C */   sw    $a1, 0x1c($sp)
/* 007D84 70007184 3C048006 */  lui   $a0, %hi(seqp_1)
/* 007D88 70007188 0C004B50 */  jal   alCSPPlay
/* 007D8C 7000718C 8C843728 */   lw    $a0, %lo(seqp_1)($a0)
/* 007D90 70007190 97A2001E */  lhu   $v0, 0x1e($sp)
/* 007D94 70007194 3401FFFF */  li    $at, 65535
/* 007D98 70007198 3C0F8006 */  lui   $t7, %hi(musicTrack1_length) 
/* 007D9C 7000719C 14410005 */  bne   $v0, $at, .L700071B4
/* 007DA0 700071A0 00000000 */   nop   
/* 007DA4 700071A4 95EF3844 */  lhu   $t7, %lo(musicTrack1_length)($t7)
/* 007DA8 700071A8 3C018006 */  lui   $at, %hi(music1_length)
/* 007DAC 700071AC 10000003 */  b     .L700071BC
/* 007DB0 700071B0 A42F384A */   sh    $t7, %lo(music1_length)($at)
.L700071B4:
/* 007DB4 700071B4 3C018006 */  lui   $at, %hi(music1_length)
/* 007DB8 700071B8 A422384A */  sh    $v0, %lo(music1_length)($at)
.L700071BC:
/* 007DBC 700071BC 3C018006 */  lui   $at, %hi(musicTrack1_length)
/* 007DC0 700071C0 A4203844 */  sh    $zero, %lo(musicTrack1_length)($at)
/* 007DC4 700071C4 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 007DC8 700071C8 44813000 */  mtc1  $at, $f6
/* 007DCC 700071CC C7A40018 */  lwc1  $f4, 0x18($sp)
/* 007DD0 700071D0 3C018006 */  lui   $at, %hi(music1_rate)
/* 007DD4 700071D4 24080001 */  li    $t0, 1
/* 007DD8 700071D8 46062202 */  mul.s $f8, $f4, $f6
/* 007DDC 700071DC 4600428D */  trunc.w.s $f10, $f8
/* 007DE0 700071E0 44195000 */  mfc1  $t9, $f10
/* 007DE4 700071E4 00000000 */  nop   
/* 007DE8 700071E8 AC393850 */  sw    $t9, %lo(music1_rate)($at)
/* 007DEC 700071EC 3C018002 */  lui   $at, %hi(music1_playing)
/* 007DF0 700071F0 AC28434C */  sw    $t0, %lo(music1_playing)($at)
.L700071F4:
/* 007DF4 700071F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 007DF8 700071F8 27BD0018 */  addiu $sp, $sp, 0x18
/* 007DFC 700071FC 03E00008 */  jr    $ra
/* 007E00 70007200 00000000 */   nop   
)
#endif






/**
 * 7E04	70007204
 */
#ifdef NONMATCHING
void musicTrack2Play(s32 arg0, s32 arg852) {
    ? sp34;
    s32 sp2140;
    void *temp_t2;
    s32 temp_v0;
    s32 temp_a2;

    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        if (music2_track_num != 0)
        {
            // Node 2
            musicTrack2Stop();
        }
        // Node 3
        music2_track_num = arg852;
        if (alCSPGetState(seqp_2) != 0)
        {
            loop_4:
            // Node 4
            if (alCSPGetState(seqp_2) != 0)
            {
                goto loop_4;
            }
        }
        // Node 5
        temp_t2 = (ptr_musicdatatable + (music2_track_num * 8));
        temp_v0 = (music2_track_num * 2);
        if ((u32) temp_t2->unk4 < 0x10000U)
        {
            // Node 6
            musicTrack2Play(1, temp_t2->unk4, music2_track_num);
            return;
            // (possible return value: musicTrack2Play(1, temp_t2->unk4, music2_track_num))
        }
        // Node 7
        temp_a2 = (((*(&D_800637B8 + temp_v0) + 0xf) | 0xf) ^ 0xf);
        sp2140 = (s32) D_8006383C;
        romCopy(((D_8006383C + (((((0x80060000 + temp_v0)->unk3738 + 0xf) | 0xf) ^ 0xf) + 0x40)) - temp_a2), temp_t2->unk4, temp_a2, music2_track_num);
        decompressdata(sp28, sp2140, &sp34);
        alCSeqNew(&D_80063958, D_8006383C);
        alCSPSetSeq(seqp_2, &D_80063958);
        musicTrack2Vol((musicTrack2Length() & 0xffff));
        alCSPPlay(seqp_2);
    }
    // Node 8
    return;
    // (function likely void)
}

#else
GLOBAL_ASM(
.text
glabel musicTrack2Play
/* 007E04 70007204 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 007E08 70007208 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 007E0C 7000720C 27BDDEB8 */  addiu $sp, $sp, -0x2148
/* 007E10 70007210 AFBF001C */  sw    $ra, 0x1c($sp)
/* 007E14 70007214 AFB00018 */  sw    $s0, 0x18($sp)
/* 007E18 70007218 15C0004A */  bnez  $t6, .L70007344
/* 007E1C 7000721C AFA42148 */   sw    $a0, 0x2148($sp)
/* 007E20 70007220 3C0F8002 */  lui   $t7, %hi(music2_track_num) 
/* 007E24 70007224 8DEF433C */  lw    $t7, %lo(music2_track_num)($t7)
/* 007E28 70007228 51E00004 */  beql  $t7, $zero, .L7000723C
/* 007E2C 7000722C 8FB82148 */   lw    $t8, 0x2148($sp)
/* 007E30 70007230 0C001CD6 */  jal   musicTrack2Stop
/* 007E34 70007234 00000000 */   nop   
/* 007E38 70007238 8FB82148 */  lw    $t8, 0x2148($sp)
.L7000723C:
/* 007E3C 7000723C 3C108006 */  lui   $s0, %hi(seqp_2)
/* 007E40 70007240 3C018002 */  lui   $at, %hi(music2_track_num)
/* 007E44 70007244 2610372C */  addiu $s0, %lo(seqp_2) # addiu $s0, $s0, 0x372c
/* 007E48 70007248 AC38433C */  sw    $t8, %lo(music2_track_num)($at)
/* 007E4C 7000724C 0C00488C */  jal   alCSPGetState
/* 007E50 70007250 8E040000 */   lw    $a0, ($s0)
/* 007E54 70007254 10400005 */  beqz  $v0, .L7000726C
/* 007E58 70007258 00000000 */   nop   
.L7000725C:
/* 007E5C 7000725C 0C00488C */  jal   alCSPGetState
/* 007E60 70007260 8E040000 */   lw    $a0, ($s0)
/* 007E64 70007264 1440FFFD */  bnez  $v0, .L7000725C
/* 007E68 70007268 00000000 */   nop   
.L7000726C:
/* 007E6C 7000726C 3C078002 */  lui   $a3, %hi(music2_track_num)
/* 007E70 70007270 8CE7433C */  lw    $a3, %lo(music2_track_num)($a3)
/* 007E74 70007274 3C198006 */  lui   $t9, %hi(ptr_musicdatatable) 
/* 007E78 70007278 8F393734 */  lw    $t9, %lo(ptr_musicdatatable)($t9)
/* 007E7C 7000727C 000748C0 */  sll   $t1, $a3, 3
/* 007E80 70007280 3C010001 */  lui   $at, 1
/* 007E84 70007284 03295021 */  addu  $t2, $t9, $t1
/* 007E88 70007288 8D450004 */  lw    $a1, 4($t2)
/* 007E8C 7000728C 3C038006 */  lui   $v1, %hi(D_80063738)
/* 007E90 70007290 00071040 */  sll   $v0, $a3, 1
/* 007E94 70007294 00A1082B */  sltu  $at, $a1, $at
/* 007E98 70007298 10200005 */  beqz  $at, .L700072B0
/* 007E9C 7000729C 00621821 */   addu  $v1, $v1, $v0
/* 007EA0 700072A0 0C001C81 */  jal   musicTrack2Play
/* 007EA4 700072A4 24040001 */   li    $a0, 1
/* 007EA8 700072A8 10000027 */  b     .L70007348
/* 007EAC 700072AC 8FBF001C */   lw    $ra, 0x1c($sp)
.L700072B0:
/* 007EB0 700072B0 94633738 */  lhu   $v1, %lo(D_80063738)($v1)
/* 007EB4 700072B4 3C068006 */  lui   $a2, %hi(D_800637B8)
/* 007EB8 700072B8 00C23021 */  addu  $a2, $a2, $v0
/* 007EBC 700072BC 94C637B8 */  lhu   $a2, %lo(D_800637B8)($a2)
/* 007EC0 700072C0 3C088006 */  lui   $t0, %hi(D_8006383C) 
/* 007EC4 700072C4 2463000F */  addiu $v1, $v1, 0xf
/* 007EC8 700072C8 8D08383C */  lw    $t0, %lo(D_8006383C)($t0)
/* 007ECC 700072CC 346B000F */  ori   $t3, $v1, 0xf
/* 007ED0 700072D0 396C000F */  xori  $t4, $t3, 0xf
/* 007ED4 700072D4 24C6000F */  addiu $a2, $a2, 0xf
/* 007ED8 700072D8 25830040 */  addiu $v1, $t4, 0x40
/* 007EDC 700072DC 34CD000F */  ori   $t5, $a2, 0xf
/* 007EE0 700072E0 39A6000F */  xori  $a2, $t5, 0xf
/* 007EE4 700072E4 01037821 */  addu  $t7, $t0, $v1
/* 007EE8 700072E8 01E62023 */  subu  $a0, $t7, $a2
/* 007EEC 700072EC AFA40028 */  sw    $a0, 0x28($sp)
/* 007EF0 700072F0 0C001707 */  jal   romCopy
/* 007EF4 700072F4 AFA82140 */   sw    $t0, 0x2140($sp)
/* 007EF8 700072F8 8FA40028 */  lw    $a0, 0x28($sp)
/* 007EFC 700072FC 8FA52140 */  lw    $a1, 0x2140($sp)
/* 007F00 70007300 0FC339FC */  jal   decompressdata
/* 007F04 70007304 27A60034 */   addiu $a2, $sp, 0x34
/* 007F08 70007308 3C048006 */  lui   $a0, %hi(D_80063958)
/* 007F0C 7000730C 3C058006 */  lui   $a1, %hi(D_8006383C)
/* 007F10 70007310 8CA5383C */  lw    $a1, %lo(D_8006383C)($a1)
/* 007F14 70007314 0C0049E7 */  jal   alCSeqNew
/* 007F18 70007318 24843958 */   addiu $a0, %lo(D_80063958) # addiu $a0, $a0, 0x3958
/* 007F1C 7000731C 3C058006 */  lui   $a1, %hi(D_80063958)
/* 007F20 70007320 24A53958 */  addiu $a1, %lo(D_80063958) # addiu $a1, $a1, 0x3958
/* 007F24 70007324 0C004B40 */  jal   alCSPSetSeq
/* 007F28 70007328 8E040000 */   lw    $a0, ($s0)
/* 007F2C 7000732C 0C001CEE */  jal   musicTrack2Length
/* 007F30 70007330 00000000 */   nop   
/* 007F34 70007334 0C001CF1 */  jal   musicTrack2Vol
/* 007F38 70007338 3044FFFF */   andi  $a0, $v0, 0xffff
/* 007F3C 7000733C 0C004B50 */  jal   alCSPPlay
/* 007F40 70007340 8E040000 */   lw    $a0, ($s0)
.L70007344:
/* 007F44 70007344 8FBF001C */  lw    $ra, 0x1c($sp)
.L70007348:
/* 007F48 70007348 8FB00018 */  lw    $s0, 0x18($sp)
/* 007F4C 7000734C 27BD2148 */  addiu $sp, $sp, 0x2148
/* 007F50 70007350 03E00008 */  jr    $ra
/* 007F54 70007354 00000000 */   nop   
)
#endif


/**
 * 7F58	70007358
 */
#ifdef NONMATCHING
void musicTrack2Stop(void) {
    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        music2_playing = 0;
        if (music2_track_num != 0)
        {
            // Node 2
            if (alCSPGetState(seqp_2) == 1)
            {
                // Node 3
                alCSPStop(seqp_2);
            }
        }
        // Node 4
        music2_track_num = 0;
        return;
        // (function likely void)
    }
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel musicTrack2Stop
/* 007F58 70007358 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 007F5C 7000735C 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 007F60 70007360 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 007F64 70007364 AFBF0014 */  sw    $ra, 0x14($sp)
/* 007F68 70007368 15C0000F */  bnez  $t6, .L700073A8
/* 007F6C 7000736C 3C0F8002 */   lui   $t7, %hi(music2_track_num) 
/* 007F70 70007370 8DEF433C */  lw    $t7, %lo(music2_track_num)($t7)
/* 007F74 70007374 3C018002 */  lui   $at, %hi(music2_playing)
/* 007F78 70007378 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 007F7C 7000737C 11E00008 */  beqz  $t7, .L700073A0
/* 007F80 70007380 3C048006 */   lui   $a0, %hi(seqp_2)
/* 007F84 70007384 0C00488C */  jal   alCSPGetState
/* 007F88 70007388 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
/* 007F8C 7000738C 24010001 */  li    $at, 1
/* 007F90 70007390 14410003 */  bne   $v0, $at, .L700073A0
/* 007F94 70007394 3C048006 */   lui   $a0, %hi(seqp_2)
/* 007F98 70007398 0C004B5C */  jal   alCSPStop
/* 007F9C 7000739C 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
.L700073A0:
/* 007FA0 700073A0 3C018002 */  lui   $at, %hi(music2_track_num)
/* 007FA4 700073A4 AC20433C */  sw    $zero, %lo(music2_track_num)($at)
.L700073A8:
/* 007FA8 700073A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 007FAC 700073AC 27BD0018 */  addiu $sp, $sp, 0x18
/* 007FB0 700073B0 03E00008 */  jr    $ra
/* 007FB4 700073B4 00000000 */   nop   
)
#endif








/**
 * 7FB8	700073B8
 *     V0= [80024340]
 */
u16 musicTrack2Length(void) {
    return music2len;
}







/**
 * 7FC4	700073C4
 */
#ifdef NONMATCHING
void musicTrack2Vol(s32 arg0) {
    s16 temp_a2;

    // Node 0
    temp_a2 = (arg0 & 0xffff);
    music2len = temp_a2;
    return alCSPSetVol(seqp_2, ((s32) (((u32) (temp_a2 * *(&music_tempo_array + (music2_track_num * 2))) >> 0xf) << 0x10) >> 0x10), temp_a2);
}

#else
GLOBAL_ASM(
.text
glabel musicTrack2Vol
/* 007FC4 700073C4 3C0E8002 */  lui   $t6, %hi(music2_track_num) 
/* 007FC8 700073C8 8DCE433C */  lw    $t6, %lo(music2_track_num)($t6)
/* 007FCC 700073CC 3C188002 */  lui   $t8, %hi(music_tempo_array)
/* 007FD0 700073D0 3086FFFF */  andi  $a2, $a0, 0xffff
/* 007FD4 700073D4 000E7840 */  sll   $t7, $t6, 1
/* 007FD8 700073D8 030FC021 */  addu  $t8, $t8, $t7
/* 007FDC 700073DC 87184358 */  lh    $t8, %lo(music_tempo_array)($t8)
/* 007FE0 700073E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 007FE4 700073E4 AFA40018 */  sw    $a0, 0x18($sp)
/* 007FE8 700073E8 00D80019 */  multu $a2, $t8
/* 007FEC 700073EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 007FF0 700073F0 3C018002 */  lui   $at, %hi(music2len)
/* 007FF4 700073F4 3C048006 */  lui   $a0, %hi(seqp_2)
/* 007FF8 700073F8 A4264340 */  sh    $a2, %lo(music2len)($at)
/* 007FFC 700073FC 8C84372C */  lw    $a0, %lo(seqp_2)($a0)
/* 008000 70007400 00001012 */  mflo  $v0
/* 008004 70007404 0002CBC2 */  srl   $t9, $v0, 0xf
/* 008008 70007408 00192C00 */  sll   $a1, $t9, 0x10
/* 00800C 7000740C 00054403 */  sra   $t0, $a1, 0x10
/* 008010 70007410 0C004B68 */  jal   alCSPSetVol
/* 008014 70007414 01002825 */   move  $a1, $t0
/* 008018 70007418 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00801C 7000741C 27BD0018 */  addiu $sp, $sp, 0x18
/* 008020 70007420 03E00008 */  jr    $ra
/* 008024 70007424 00000000 */   nop   
)
#endif







/**
 * 8028	70007428
 */
#ifdef NONMATCHING
void *musicTrack2Tempo(void) {
    void *phi_v0;

    // Node 0
    *(&music_tempo_array + (music2_track_num * 2)) = musicTrack2Length();
    phi_v0 = &music_tempo_array;
    if (music_tempo_array >= 0)
    {
        loop_1:
        // Node 1
        phi_v0 = (phi_v0 + 2);
        if (phi_v0->unk2 >= 0)
        {
            goto loop_1;
        }
    }
    // Node 2
    return &music_tempo_array;
}
#else
GLOBAL_ASM(
.text
glabel musicTrack2Tempo
/* 008028 70007428 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00802C 7000742C AFBF0014 */  sw    $ra, 0x14($sp)
/* 008030 70007430 0C001CEE */  jal   musicTrack2Length
/* 008034 70007434 00000000 */   nop   
/* 008038 70007438 3C0E8002 */  lui   $t6, %hi(music2_track_num) 
/* 00803C 7000743C 8DCE433C */  lw    $t6, %lo(music2_track_num)($t6)
/* 008040 70007440 3C048002 */  lui   $a0, %hi(music_tempo_array)
/* 008044 70007444 24844358 */  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
/* 008048 70007448 000E7840 */  sll   $t7, $t6, 1
/* 00804C 7000744C 008FC021 */  addu  $t8, $a0, $t7
/* 008050 70007450 A7020000 */  sh    $v0, ($t8)
/* 008054 70007454 84990000 */  lh    $t9, ($a0)
/* 008058 70007458 3C028002 */  lui   $v0, %hi(music_tempo_array)
/* 00805C 7000745C 24424358 */  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
/* 008060 70007460 07200005 */  bltz  $t9, .L70007478
/* 008064 70007464 8FBF0014 */   lw    $ra, 0x14($sp)
/* 008068 70007468 84480002 */  lh    $t0, 2($v0)
.L7000746C:
/* 00806C 7000746C 24420002 */  addiu $v0, $v0, 2
/* 008070 70007470 0503FFFE */  bgezl $t0, .L7000746C
/* 008074 70007474 84480002 */   lh    $t0, 2($v0)
.L70007478:
/* 008078 70007478 03E00008 */  jr    $ra
/* 00807C 7000747C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif


/**
 * 8080	70007480
 */
#ifdef NONMATCHING
void music_related_6(f32 arg0) {
    // Node 0
    if (music2_playing >= 0)
    {
        // Node 1
        D_80063846 = musicTrack2Length();
        music2_length = (u16)0;
        music2_rate = (s32) (arg0 * 60.0f);
        music2_playing = -1;
    }
    // Node 2
    return;
}
#else
GLOBAL_ASM(
.text
glabel music_related_6
/* 008080 70007480 3C0E8002 */  lui   $t6, %hi(music2_playing) 
/* 008084 70007484 8DCE4350 */  lw    $t6, %lo(music2_playing)($t6)
/* 008088 70007488 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00808C 7000748C AFBF0014 */  sw    $ra, 0x14($sp)
/* 008090 70007490 05C00013 */  bltz  $t6, .L700074E0
/* 008094 70007494 E7AC0018 */   swc1  $f12, 0x18($sp)
/* 008098 70007498 0C001CEE */  jal   musicTrack2Length
/* 00809C 7000749C 00000000 */   nop   
/* 0080A0 700074A0 3C018006 */  lui   $at, %hi(D_80063846)
/* 0080A4 700074A4 A4223846 */  sh    $v0, %lo(D_80063846)($at)
/* 0080A8 700074A8 3C018006 */  lui   $at, %hi(music2_length)
/* 0080AC 700074AC A420384C */  sh    $zero, %lo(music2_length)($at)
/* 0080B0 700074B0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0080B4 700074B4 44813000 */  mtc1  $at, $f6
/* 0080B8 700074B8 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0080BC 700074BC 3C018006 */  lui   $at, %hi(music2_rate)
/* 0080C0 700074C0 2419FFFF */  li    $t9, -1
/* 0080C4 700074C4 46062202 */  mul.s $f8, $f4, $f6
/* 0080C8 700074C8 4600428D */  trunc.w.s $f10, $f8
/* 0080CC 700074CC 44185000 */  mfc1  $t8, $f10
/* 0080D0 700074D0 00000000 */  nop   
/* 0080D4 700074D4 AC383854 */  sw    $t8, %lo(music2_rate)($at)
/* 0080D8 700074D8 3C018002 */  lui   $at, %hi(music2_playing)
/* 0080DC 700074DC AC394350 */  sw    $t9, %lo(music2_playing)($at)
.L700074E0:
/* 0080E0 700074E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0080E4 700074E4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0080E8 700074E8 03E00008 */  jr    $ra
/* 0080EC 700074EC 00000000 */   nop   
)
#endif






/**
 * 80F0	700074F0
 */
#ifdef NONMATCHING
void music_related_8(f32 arg0, s32 arg1, s16 arg_unaligned6) {
    // Node 0
    if (music2_playing <= 0)
    {
        // Node 1
        alCSPPlay(seqp_2);
        if (arg_unaligned6 == 0xffff)
        {
            // Node 2
            music2_length = (s16) D_80063846;
        }
        else
        {
            // Node 3
            music2_length = arg_unaligned6;
        }
        // Node 4
        D_80063846 = (u16)0;
        music2_rate = (s32) (arg0 * 60.0f);
        music2_playing = 1;
    }
    // Node 5
    return;
}
#else
GLOBAL_ASM(
.text
glabel music_related_8
/* 0080F0 700074F0 3C0E8002 */  lui   $t6, %hi(music2_playing) 
/* 0080F4 700074F4 8DCE4350 */  lw    $t6, %lo(music2_playing)($t6)
/* 0080F8 700074F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0080FC 700074FC AFBF0014 */  sw    $ra, 0x14($sp)
/* 008100 70007500 E7AC0018 */  swc1  $f12, 0x18($sp)
/* 008104 70007504 1DC0001D */  bgtz  $t6, .L7000757C
/* 008108 70007508 AFA5001C */   sw    $a1, 0x1c($sp)
/* 00810C 7000750C 3C048006 */  lui   $a0, %hi(seqp_2)
/* 008110 70007510 0C004B50 */  jal   alCSPPlay
/* 008114 70007514 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
/* 008118 70007518 97A2001E */  lhu   $v0, 0x1e($sp)
/* 00811C 7000751C 3401FFFF */  li    $at, 65535
/* 008120 70007520 3C0F8006 */  lui   $t7, %hi(D_80063846) 
/* 008124 70007524 14410005 */  bne   $v0, $at, .L7000753C
/* 008128 70007528 00000000 */   nop   
/* 00812C 7000752C 95EF3846 */  lhu   $t7, %lo(D_80063846)($t7)
/* 008130 70007530 3C018006 */  lui   $at, %hi(music2_length)
/* 008134 70007534 10000003 */  b     .L70007544
/* 008138 70007538 A42F384C */   sh    $t7, %lo(music2_length)($at)
.L7000753C:
/* 00813C 7000753C 3C018006 */  lui   $at, %hi(music2_length)
/* 008140 70007540 A422384C */  sh    $v0, %lo(music2_length)($at)
.L70007544:
/* 008144 70007544 3C018006 */  lui   $at, %hi(D_80063846)
/* 008148 70007548 A4203846 */  sh    $zero, %lo(D_80063846)($at)
/* 00814C 7000754C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 008150 70007550 44813000 */  mtc1  $at, $f6
/* 008154 70007554 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 008158 70007558 3C018006 */  lui   $at, %hi(music2_rate)
/* 00815C 7000755C 24080001 */  li    $t0, 1
/* 008160 70007560 46062202 */  mul.s $f8, $f4, $f6
/* 008164 70007564 4600428D */  trunc.w.s $f10, $f8
/* 008168 70007568 44195000 */  mfc1  $t9, $f10
/* 00816C 7000756C 00000000 */  nop   
/* 008170 70007570 AC393854 */  sw    $t9, %lo(music2_rate)($at)
/* 008174 70007574 3C018002 */  lui   $at, %hi(music2_playing)
/* 008178 70007578 AC284350 */  sw    $t0, %lo(music2_playing)($at)
.L7000757C:
/* 00817C 7000757C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 008180 70007580 27BD0018 */  addiu $sp, $sp, 0x18
/* 008184 70007584 03E00008 */  jr    $ra
/* 008188 70007588 00000000 */   nop   
)
#endif






/**
 * 818C	7000758C
 */
#ifdef NONMATCHING
void music_related_3rd_block(s32 arg0, s32 arg852) {
    ? sp34;
    s32 sp2140;
    void *temp_t2;
    s32 temp_v0;
    s32 temp_a2;

    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        if (music3_track_num != 0)
        {
            // Node 2
            musicTrack3Stop();
        }
        // Node 3
        music3_track_num = arg852;
        if (alCSPGetState(seqp_3) != 0)
        {
            loop_4:
            // Node 4
            if (alCSPGetState(seqp_3) != 0)
            {
                goto loop_4;
            }
        }
        // Node 5
        temp_t2 = (ptr_musicdatatable + (music3_track_num * 8));
        temp_v0 = (music3_track_num * 2);
        if ((u32) temp_t2->unk4 < 0x10000U)
        {
            // Node 6
            music_related_3rd_block(1, temp_t2->unk4, music3_track_num);
            return;
            // (possible return value: music_related_3rd_block(1, temp_t2->unk4, music3_track_num))
        }
        // Node 7
        temp_a2 = ((((0x80060000 + temp_v0)->unk37B8 + 0xf) | 0xf) ^ 0xf);
        sp2140 = (s32) D_80063840;
        romCopy(((D_80063840 + (((((0x80060000 + temp_v0)->unk3738 + 0xf) | 0xf) ^ 0xf) + 0x40)) - temp_a2), temp_t2->unk4, temp_a2, music3_track_num);
        decompressdata(sp28, sp2140, &sp34);
        alCSeqNew(&D_80063A50, D_80063840);
        alCSPSetSeq(seqp_3, &D_80063A50);
        musicTrack3Vol((get_music3len() & 0xffff));
        alCSPPlay(seqp_3);
    }
    // Node 8
    return;
    // (function likely void)
}

#else
GLOBAL_ASM(
.text
glabel music_related_3rd_block
/* 00818C 7000758C 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 008190 70007590 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 008194 70007594 27BDDEB8 */  addiu $sp, $sp, -0x2148
/* 008198 70007598 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00819C 7000759C AFB00018 */  sw    $s0, 0x18($sp)
/* 0081A0 700075A0 15C0004A */  bnez  $t6, .L700076CC
/* 0081A4 700075A4 AFA42148 */   sw    $a0, 0x2148($sp)
/* 0081A8 700075A8 3C0F8002 */  lui   $t7, %hi(music3_track_num) 
/* 0081AC 700075AC 8DEF4344 */  lw    $t7, %lo(music3_track_num)($t7)
/* 0081B0 700075B0 51E00004 */  beql  $t7, $zero, .L700075C4
/* 0081B4 700075B4 8FB82148 */   lw    $t8, 0x2148($sp)
/* 0081B8 700075B8 0C001DB8 */  jal   musicTrack3Stop
/* 0081BC 700075BC 00000000 */   nop   
/* 0081C0 700075C0 8FB82148 */  lw    $t8, 0x2148($sp)
.L700075C4:
/* 0081C4 700075C4 3C108006 */  lui   $s0, %hi(seqp_3)
/* 0081C8 700075C8 3C018002 */  lui   $at, %hi(music3_track_num)
/* 0081CC 700075CC 26103730 */  addiu $s0, %lo(seqp_3) # addiu $s0, $s0, 0x3730
/* 0081D0 700075D0 AC384344 */  sw    $t8, %lo(music3_track_num)($at)
/* 0081D4 700075D4 0C00488C */  jal   alCSPGetState
/* 0081D8 700075D8 8E040000 */   lw    $a0, ($s0)
/* 0081DC 700075DC 10400005 */  beqz  $v0, .L700075F4
/* 0081E0 700075E0 00000000 */   nop   
.L700075E4:
/* 0081E4 700075E4 0C00488C */  jal   alCSPGetState
/* 0081E8 700075E8 8E040000 */   lw    $a0, ($s0)
/* 0081EC 700075EC 1440FFFD */  bnez  $v0, .L700075E4
/* 0081F0 700075F0 00000000 */   nop   
.L700075F4:
/* 0081F4 700075F4 3C078002 */  lui   $a3, %hi(music3_track_num)
/* 0081F8 700075F8 8CE74344 */  lw    $a3, %lo(music3_track_num)($a3)
/* 0081FC 700075FC 3C198006 */  lui   $t9, %hi(ptr_musicdatatable) 
/* 008200 70007600 8F393734 */  lw    $t9, %lo(ptr_musicdatatable)($t9)
/* 008204 70007604 000748C0 */  sll   $t1, $a3, 3
/* 008208 70007608 3C010001 */  lui   $at, 1
/* 00820C 7000760C 03295021 */  addu  $t2, $t9, $t1
/* 008210 70007610 8D450004 */  lw    $a1, 4($t2)
/* 008214 70007614 3C038006 */  lui   $v1, %hi(D_80063738)
/* 008218 70007618 00071040 */  sll   $v0, $a3, 1
/* 00821C 7000761C 00A1082B */  sltu  $at, $a1, $at
/* 008220 70007620 10200005 */  beqz  $at, .L70007638
/* 008224 70007624 00621821 */   addu  $v1, $v1, $v0
/* 008228 70007628 0C001D63 */  jal   music_related_3rd_block
/* 00822C 7000762C 24040001 */   li    $a0, 1
/* 008230 70007630 10000027 */  b     .L700076D0
/* 008234 70007634 8FBF001C */   lw    $ra, 0x1c($sp)
.L70007638:
/* 008238 70007638 94633738 */  lhu   $v1, %lo(D_80063738)($v1)
/* 00823C 7000763C 3C068006 */  lui   $a2, %hi(D_800637B8)
/* 008240 70007640 00C23021 */  addu  $a2, $a2, $v0
/* 008244 70007644 94C637B8 */  lhu   $a2, %lo(D_800637B8)($a2)
/* 008248 70007648 3C088006 */  lui   $t0, %hi(D_80063840)
/* 00824C 7000764C 2463000F */  addiu $v1, $v1, 0xf
/* 008250 70007650 8D083840 */  lw    $t0, %lo(D_80063840)($t0)
/* 008254 70007654 346B000F */  ori   $t3, $v1, 0xf
/* 008258 70007658 396C000F */  xori  $t4, $t3, 0xf
/* 00825C 7000765C 24C6000F */  addiu $a2, $a2, 0xf
/* 008260 70007660 25830040 */  addiu $v1, $t4, 0x40
/* 008264 70007664 34CD000F */  ori   $t5, $a2, 0xf
/* 008268 70007668 39A6000F */  xori  $a2, $t5, 0xf
/* 00826C 7000766C 01037821 */  addu  $t7, $t0, $v1
/* 008270 70007670 01E62023 */  subu  $a0, $t7, $a2
/* 008274 70007674 AFA40028 */  sw    $a0, 0x28($sp)
/* 008278 70007678 0C001707 */  jal   romCopy
/* 00827C 7000767C AFA82140 */   sw    $t0, 0x2140($sp)
/* 008280 70007680 8FA40028 */  lw    $a0, 0x28($sp)
/* 008284 70007684 8FA52140 */  lw    $a1, 0x2140($sp)
/* 008288 70007688 0FC339FC */  jal   decompressdata
/* 00828C 7000768C 27A60034 */   addiu $a2, $sp, 0x34
/* 008290 70007690 3C048006 */  lui   $a0, %hi(D_80063A50)
/* 008294 70007694 3C058006 */  lui   $a1, %hi(D_80063840)
/* 008298 70007698 8CA53840 */  lw    $a1, %lo(D_80063840)($a1)
/* 00829C 7000769C 0C0049E7 */  jal   alCSeqNew
/* 0082A0 700076A0 24843A50 */   addiu $a0, %lo(D_80063A50) # addiu $a0, $a0, 0x3a50
/* 0082A4 700076A4 3C058006 */  lui   $a1, %hi(D_80063A50)
/* 0082A8 700076A8 24A53A50 */  addiu $a1, %lo(D_80063A50) # addiu $a1, $a1, 0x3a50
/* 0082AC 700076AC 0C004B40 */  jal   alCSPSetSeq
/* 0082B0 700076B0 8E040000 */   lw    $a0, ($s0)
/* 0082B4 700076B4 0C001DD0 */  jal   get_music3len
/* 0082B8 700076B8 00000000 */   nop   
/* 0082BC 700076BC 0C001DD3 */  jal   musicTrack3Vol
/* 0082C0 700076C0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0082C4 700076C4 0C004B50 */  jal   alCSPPlay
/* 0082C8 700076C8 8E040000 */   lw    $a0, ($s0)
.L700076CC:
/* 0082CC 700076CC 8FBF001C */  lw    $ra, 0x1c($sp)
.L700076D0:
/* 0082D0 700076D0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0082D4 700076D4 27BD2148 */  addiu $sp, $sp, 0x2148
/* 0082D8 700076D8 03E00008 */  jr    $ra
/* 0082DC 700076DC 00000000 */   nop   
)
#endif


/**
 * 82E0	700076E0
 */
#ifdef NONMATCHING
void musicTrack3Stop(void) {
    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        music3_playing = 0;
        if (music3_track_num != 0)
        {
            // Node 2
            if (alCSPGetState(seqp_3) == 1)
            {
                // Node 3
                alCSPStop(seqp_3);
            }
        }
        // Node 4
        music3_track_num = 0;
        return;
        // (function likely void)
    }
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel musicTrack3Stop
/* 0082E0 700076E0 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 0082E4 700076E4 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 0082E8 700076E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0082EC 700076EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0082F0 700076F0 15C0000F */  bnez  $t6, .L70007730
/* 0082F4 700076F4 3C0F8002 */   lui   $t7, %hi(music3_track_num) 
/* 0082F8 700076F8 8DEF4344 */  lw    $t7, %lo(music3_track_num)($t7)
/* 0082FC 700076FC 3C018002 */  lui   $at, %hi(music3_playing)
/* 008300 70007700 AC204354 */  sw    $zero, %lo(music3_playing)($at)
/* 008304 70007704 11E00008 */  beqz  $t7, .L70007728
/* 008308 70007708 3C048006 */   lui   $a0, %hi(seqp_3)
/* 00830C 7000770C 0C00488C */  jal   alCSPGetState
/* 008310 70007710 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
/* 008314 70007714 24010001 */  li    $at, 1
/* 008318 70007718 14410003 */  bne   $v0, $at, .L70007728
/* 00831C 7000771C 3C048006 */   lui   $a0, %hi(seqp_3)
/* 008320 70007720 0C004B5C */  jal   alCSPStop
/* 008324 70007724 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
.L70007728:
/* 008328 70007728 3C018002 */  lui   $at, %hi(music3_track_num)
/* 00832C 7000772C AC204344 */  sw    $zero, %lo(music3_track_num)($at)
.L70007730:
/* 008330 70007730 8FBF0014 */  lw    $ra, 0x14($sp)
/* 008334 70007734 27BD0018 */  addiu $sp, $sp, 0x18
/* 008338 70007738 03E00008 */  jr    $ra
/* 00833C 7000773C 00000000 */   nop   
)
#endif






/**
 * 8340	70007740
 *     V0= 7FFF [80024348]
 */
u16 get_music3len(void) {
    return music3len;
}







/**
 * 834C	7000774C
 */
#ifdef NONMATCHING
void musicTrack3Vol(s32 arg0) {
    s16 temp_a2;

    // Node 0
    temp_a2 = (arg0 & 0xffff);
    music3len = temp_a2;
    alCSPSetVol(seqp_3, ((s32) (((u32) (temp_a2 * (0x80020000 + (music3_track_num * 2))->unk4358) >> 0xf) << 0x10) >> 0x10), temp_a2);
    return;
    // (possible return value: alCSPSetVol(seqp_3, ((s32) (((u32) (temp_a2 * (0x80020000 + (music3_track_num * 2))->unk4358) >> 0xf) << 0x10) >> 0x10), temp_a2))
}
#else
GLOBAL_ASM(
.text
glabel musicTrack3Vol
/* 00834C 7000774C 3C0E8002 */  lui   $t6, %hi(music3_track_num) 
/* 008350 70007750 8DCE4344 */  lw    $t6, %lo(music3_track_num)($t6)
/* 008354 70007754 3C188002 */  lui   $t8, %hi(music_tempo_array)
/* 008358 70007758 3086FFFF */  andi  $a2, $a0, 0xffff
/* 00835C 7000775C 000E7840 */  sll   $t7, $t6, 1
/* 008360 70007760 030FC021 */  addu  $t8, $t8, $t7
/* 008364 70007764 87184358 */  lh    $t8, %lo(music_tempo_array)($t8)
/* 008368 70007768 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00836C 7000776C AFA40018 */  sw    $a0, 0x18($sp)
/* 008370 70007770 00D80019 */  multu $a2, $t8
/* 008374 70007774 AFBF0014 */  sw    $ra, 0x14($sp)
/* 008378 70007778 3C018002 */  lui   $at, %hi(music3len)
/* 00837C 7000777C 3C048006 */  lui   $a0, %hi(seqp_3)
/* 008380 70007780 A4264348 */  sh    $a2, %lo(music3len)($at)
/* 008384 70007784 8C843730 */  lw    $a0, %lo(seqp_3)($a0)
/* 008388 70007788 00001012 */  mflo  $v0
/* 00838C 7000778C 0002CBC2 */  srl   $t9, $v0, 0xf
/* 008390 70007790 00192C00 */  sll   $a1, $t9, 0x10
/* 008394 70007794 00054403 */  sra   $t0, $a1, 0x10
/* 008398 70007798 0C004B68 */  jal   alCSPSetVol
/* 00839C 7000779C 01002825 */   move  $a1, $t0
/* 0083A0 700077A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0083A4 700077A4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0083A8 700077A8 03E00008 */  jr    $ra
/* 0083AC 700077AC 00000000 */   nop   
)
#endif







/**
 * 83B0	700077B0
 */
#ifdef NONMATCHING
void *music_related_10(void) {
    // Node 0
    *(&music_tempo_array + (music3_track_num * 2)) = get_music3len();
    if (music_tempo_array >= 0)
    {
        loop_1:
        // Node 1
        if (music_tempo_array.unk2 >= 0)
        {
            goto loop_1;
        }
    }
    // (possible return value: &music_tempo_array)
}

#else
GLOBAL_ASM(
.text
glabel music_related_10
/* 0083B0 700077B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0083B4 700077B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0083B8 700077B8 0C001DD0 */  jal   get_music3len
/* 0083BC 700077BC 00000000 */   nop   
/* 0083C0 700077C0 3C0E8002 */  lui   $t6, %hi(music3_track_num) 
/* 0083C4 700077C4 8DCE4344 */  lw    $t6, %lo(music3_track_num)($t6)
/* 0083C8 700077C8 3C048002 */  lui   $a0, %hi(music_tempo_array)
/* 0083CC 700077CC 24844358 */  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
/* 0083D0 700077D0 000E7840 */  sll   $t7, $t6, 1
/* 0083D4 700077D4 008FC021 */  addu  $t8, $a0, $t7
/* 0083D8 700077D8 A7020000 */  sh    $v0, ($t8)
/* 0083DC 700077DC 84990000 */  lh    $t9, ($a0)
/* 0083E0 700077E0 3C028002 */  lui   $v0, %hi(music_tempo_array)
/* 0083E4 700077E4 24424358 */  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
/* 0083E8 700077E8 07200005 */  bltz  $t9, .L70007800
/* 0083EC 700077EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0083F0 700077F0 84480002 */  lh    $t0, 2($v0)
.L700077F4:
/* 0083F4 700077F4 24420002 */  addiu $v0, $v0, 2
/* 0083F8 700077F8 0503FFFE */  bgezl $t0, .L700077F4
/* 0083FC 700077FC 84480002 */   lh    $t0, 2($v0)
.L70007800:
/* 008400 70007800 03E00008 */  jr    $ra
/* 008404 70007804 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif


/**
 * 8408	70007808
 */
#ifdef NONMATCHING
void music_related_11(f32 arg0, f32 arg6) {
    // Node 0
    if (music3_playing >= 0)
    {
        // Node 1
        D_80063848 = get_music3len();
        music3_length = (u16)0;
        music3_rate = (s32) (arg6 * 60.0f);
        music3_playing = -1;
        return;
        // (possible return value: get_music3len())
    }
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel music_related_11
/* 008408 70007808 3C0E8002 */  lui   $t6, %hi(music3_playing) 
/* 00840C 7000780C 8DCE4354 */  lw    $t6, %lo(music3_playing)($t6)
/* 008410 70007810 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 008414 70007814 AFBF0014 */  sw    $ra, 0x14($sp)
/* 008418 70007818 05C00013 */  bltz  $t6, .L70007868
/* 00841C 7000781C E7AC0018 */   swc1  $f12, 0x18($sp)
/* 008420 70007820 0C001DD0 */  jal   get_music3len
/* 008424 70007824 00000000 */   nop   
/* 008428 70007828 3C018006 */  lui   $at, %hi(D_80063848)
/* 00842C 7000782C A4223848 */  sh    $v0, %lo(D_80063848)($at)
/* 008430 70007830 3C018006 */  lui   $at, %hi(music3_length)
/* 008434 70007834 A420384E */  sh    $zero, %lo(music3_length)($at)
/* 008438 70007838 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 00843C 7000783C 44813000 */  mtc1  $at, $f6
/* 008440 70007840 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 008444 70007844 3C018006 */  lui   $at, %hi(music3_rate)
/* 008448 70007848 2419FFFF */  li    $t9, -1
/* 00844C 7000784C 46062202 */  mul.s $f8, $f4, $f6
/* 008450 70007850 4600428D */  trunc.w.s $f10, $f8
/* 008454 70007854 44185000 */  mfc1  $t8, $f10
/* 008458 70007858 00000000 */  nop   
/* 00845C 7000785C AC383858 */  sw    $t8, %lo(music3_rate)($at)
/* 008460 70007860 3C018002 */  lui   $at, %hi(music3_playing)
/* 008464 70007864 AC394354 */  sw    $t9, %lo(music3_playing)($at)
.L70007868:
/* 008468 70007868 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00846C 7000786C 27BD0018 */  addiu $sp, $sp, 0x18
/* 008470 70007870 03E00008 */  jr    $ra
/* 008474 70007874 00000000 */   nop   
)
#endif





/**
 * 8478	70007878
 */
#ifdef NONMATCHING
s16 music_related_13(f32 arg0, s32 arg1, f32 arg6, s16 arg7) {
    // Node 0
    if (music3_playing <= 0)
    {
        // Node 1
        alCSPPlay(seqp_3);
        if (arg7 == 0xffff)
        {
            // Node 2
            music3_length = (s16) D_80063848;
        }
        else
        {
            // Node 3
            music3_length = arg7;
        }
        // Node 4
        D_80063848 = (u16)0;
        music3_rate = (s32) (arg6 * 60.0f);
        music3_playing = 1;
        return;
        // (possible return value: arg7)
    }
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel music_related_13
/* 008478 70007878 3C0E8002 */  lui   $t6, %hi(music3_playing) 
/* 00847C 7000787C 8DCE4354 */  lw    $t6, %lo(music3_playing)($t6)
/* 008480 70007880 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 008484 70007884 AFBF0014 */  sw    $ra, 0x14($sp)
/* 008488 70007888 E7AC0018 */  swc1  $f12, 0x18($sp)
/* 00848C 7000788C 1DC0001D */  bgtz  $t6, .L70007904
/* 008490 70007890 AFA5001C */   sw    $a1, 0x1c($sp)
/* 008494 70007894 3C048006 */  lui   $a0, %hi(seqp_3)
/* 008498 70007898 0C004B50 */  jal   alCSPPlay
/* 00849C 7000789C 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
/* 0084A0 700078A0 97A2001E */  lhu   $v0, 0x1e($sp)
/* 0084A4 700078A4 3401FFFF */  li    $at, 65535
/* 0084A8 700078A8 3C0F8006 */  lui   $t7, %hi(D_80063848) 
/* 0084AC 700078AC 14410005 */  bne   $v0, $at, .L700078C4
/* 0084B0 700078B0 00000000 */   nop   
/* 0084B4 700078B4 95EF3848 */  lhu   $t7, %lo(D_80063848)($t7)
/* 0084B8 700078B8 3C018006 */  lui   $at, %hi(music3_length)
/* 0084BC 700078BC 10000003 */  b     .L700078CC
/* 0084C0 700078C0 A42F384E */   sh    $t7, %lo(music3_length)($at)
.L700078C4:
/* 0084C4 700078C4 3C018006 */  lui   $at, %hi(music3_length)
/* 0084C8 700078C8 A422384E */  sh    $v0, %lo(music3_length)($at)
.L700078CC:
/* 0084CC 700078CC 3C018006 */  lui   $at, %hi(D_80063848)
/* 0084D0 700078D0 A4203848 */  sh    $zero, %lo(D_80063848)($at)
/* 0084D4 700078D4 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0084D8 700078D8 44813000 */  mtc1  $at, $f6
/* 0084DC 700078DC C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0084E0 700078E0 3C018006 */  lui   $at, %hi(music3_rate)
/* 0084E4 700078E4 24080001 */  li    $t0, 1
/* 0084E8 700078E8 46062202 */  mul.s $f8, $f4, $f6
/* 0084EC 700078EC 4600428D */  trunc.w.s $f10, $f8
/* 0084F0 700078F0 44195000 */  mfc1  $t9, $f10
/* 0084F4 700078F4 00000000 */  nop   
/* 0084F8 700078F8 AC393858 */  sw    $t9, %lo(music3_rate)($at)
/* 0084FC 700078FC 3C018002 */  lui   $at, %hi(music3_playing)
/* 008500 70007900 AC284354 */  sw    $t0, %lo(music3_playing)($at)
.L70007904:
/* 008504 70007904 8FBF0014 */  lw    $ra, 0x14($sp)
/* 008508 70007908 27BD0018 */  addiu $sp, $sp, 0x18
/* 00850C 7000790C 03E00008 */  jr    $ra
/* 008510 70007910 00000000 */   nop   
)
#endif






/**
 * 8514	70007914
 */
#ifdef NONMATCHING
void music_related_15(void) {
    s16 sp1E;
    s16 sp26;
    s16 sp2E;
    ? temp_ret;
    s32 temp_a1;
    s16 temp_t9;
    s32 temp_t1;
    ? temp_ret_2;
    s32 temp_a1_2;
    s16 temp_t0;
    s32 temp_t2;
    ? temp_ret_3;
    s32 temp_a1_3;
    s16 temp_t1_2;
    s32 temp_t3;

    if (music1_playing != 0)
    {
        temp_ret_3 = musicTrack1Length();
        temp_a1_3 = (music1_length - temp_ret_3);
        temp_t1_2 = ((temp_ret_3 + (s32) ((f32) temp_a1_3 / (f32) music1_rate)) & 0xffff);
        sp2E = temp_t1_2;
        musicTrack1Vol(temp_t1_2, temp_a1_3, &music1_rate);
        temp_t3 = (music1_rate + -1);
        music1_rate = temp_t3;
        if (temp_t3 <= 0)
        {
            if (&seqp_1 == 0)
            {
                alCSPStop(seqp_1, &music1_rate);
            }
            music1_rate = 0;
            music1_playing = 0;
        }
    }
    if (music2_playing != 0)
    {
        temp_ret_2 = musicTrack2Length();
        temp_a1_2 = (music2_length - temp_ret_2);
        temp_t0 = ((temp_ret_2 + (s32) ((f32) temp_a1_2 / (f32) music2_rate)) & 0xffff);
        sp26 = temp_t0;
        musicTrack2Vol(temp_t0, temp_a1_2, &music2_rate);
        temp_t2 = (music2_rate + -1);
        music2_rate = temp_t2;
        if (temp_t2 <= 0)
        {
            if (&seqp_2 == 0)
            {
                alCSPStop(seqp_2, &music2_rate);
            }
            music2_rate = 0;
            music2_playing = 0;
        }
    }
    if (music3_playing != 0)
    {
        temp_ret = get_music3len();
        temp_a1 = (music3_length - temp_ret);
        temp_t9 = ((temp_ret + (s32) ((f32) temp_a1 / (f32) music3_rate)) & 0xffff);
        sp1E = temp_t9;
        musicTrack3Vol(temp_t9, temp_a1, &music3_rate);
        temp_t1 = (music3_rate + -1);
        music3_rate = temp_t1;
        if (temp_t1 <= 0)
        {
            if (&seqp_3 == 0)
            {
                alCSPStop(seqp_3, &music3_rate);
            }
            music3_rate = 0;
            music3_playing = 0;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel music_related_15
/* 008514 70007914 3C0E8002 */  lui   $t6, %hi(music1_playing) 
/* 008518 70007918 8DCE434C */  lw    $t6, %lo(music1_playing)($t6)
/* 00851C 7000791C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 008520 70007920 AFBF0014 */  sw    $ra, 0x14($sp)
/* 008524 70007924 11C00026 */  beqz  $t6, .L700079C0
/* 008528 70007928 00000000 */   nop   
/* 00852C 7000792C 0C001C0C */  jal   musicTrack1Length
/* 008530 70007930 00000000 */   nop   
/* 008534 70007934 3C068006 */  lui   $a2, %hi(music1_rate)
/* 008538 70007938 3C0F8006 */  lui   $t7, %hi(music1_length) 
/* 00853C 7000793C 95EF384A */  lhu   $t7, %lo(music1_length)($t7)
/* 008540 70007940 24C63850 */  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
/* 008544 70007944 8CD80000 */  lw    $t8, ($a2)
/* 008548 70007948 01E22823 */  subu  $a1, $t7, $v0
/* 00854C 7000794C 44852000 */  mtc1  $a1, $f4
/* 008550 70007950 44984000 */  mtc1  $t8, $f8
/* 008554 70007954 468021A0 */  cvt.s.w $f6, $f4
/* 008558 70007958 468042A0 */  cvt.s.w $f10, $f8
/* 00855C 7000795C 460A3403 */  div.s $f16, $f6, $f10
/* 008560 70007960 4600848D */  trunc.w.s $f18, $f16
/* 008564 70007964 44089000 */  mfc1  $t0, $f18
/* 008568 70007968 00000000 */  nop   
/* 00856C 7000796C 00482021 */  addu  $a0, $v0, $t0
/* 008570 70007970 3089FFFF */  andi  $t1, $a0, 0xffff
/* 008574 70007974 01202025 */  move  $a0, $t1
/* 008578 70007978 0C001C0F */  jal   musicTrack1Vol
/* 00857C 7000797C A7A9002E */   sh    $t1, 0x2e($sp)
/* 008580 70007980 3C068006 */  lui   $a2, %hi(music1_rate)
/* 008584 70007984 24C63850 */  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
/* 008588 70007988 8CCA0000 */  lw    $t2, ($a2)
/* 00858C 7000798C 97A4002E */  lhu   $a0, 0x2e($sp)
/* 008590 70007990 254BFFFF */  addiu $t3, $t2, -1
/* 008594 70007994 1D60000A */  bgtz  $t3, .L700079C0
/* 008598 70007998 ACCB0000 */   sw    $t3, ($a2)
/* 00859C 7000799C 14800005 */  bnez  $a0, .L700079B4
/* 0085A0 700079A0 3C048006 */   lui   $a0, %hi(seqp_1)
/* 0085A4 700079A4 0C004B5C */  jal   alCSPStop
/* 0085A8 700079A8 8C843728 */   lw    $a0, %lo(seqp_1)($a0)
/* 0085AC 700079AC 3C068006 */  lui   $a2, %hi(music1_rate)
/* 0085B0 700079B0 24C63850 */  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
.L700079B4:
/* 0085B4 700079B4 ACC00000 */  sw    $zero, ($a2)
/* 0085B8 700079B8 3C018002 */  lui   $at, %hi(music1_playing)
/* 0085BC 700079BC AC20434C */  sw    $zero, %lo(music1_playing)($at)
.L700079C0:
/* 0085C0 700079C0 3C0D8002 */  lui   $t5, %hi(music2_playing) 
/* 0085C4 700079C4 8DAD4350 */  lw    $t5, %lo(music2_playing)($t5)
/* 0085C8 700079C8 11A00026 */  beqz  $t5, .L70007A64
/* 0085CC 700079CC 00000000 */   nop   
/* 0085D0 700079D0 0C001CEE */  jal   musicTrack2Length
/* 0085D4 700079D4 00000000 */   nop   
/* 0085D8 700079D8 3C068006 */  lui   $a2, %hi(music2_rate)
/* 0085DC 700079DC 3C0E8006 */  lui   $t6, %hi(music2_length) 
/* 0085E0 700079E0 95CE384C */  lhu   $t6, %lo(music2_length)($t6)
/* 0085E4 700079E4 24C63854 */  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
/* 0085E8 700079E8 8CCF0000 */  lw    $t7, ($a2)
/* 0085EC 700079EC 01C22823 */  subu  $a1, $t6, $v0
/* 0085F0 700079F0 44852000 */  mtc1  $a1, $f4
/* 0085F4 700079F4 448F3000 */  mtc1  $t7, $f6
/* 0085F8 700079F8 46802220 */  cvt.s.w $f8, $f4
/* 0085FC 700079FC 468032A0 */  cvt.s.w $f10, $f6
/* 008600 70007A00 460A4403 */  div.s $f16, $f8, $f10
/* 008604 70007A04 4600848D */  trunc.w.s $f18, $f16
/* 008608 70007A08 44199000 */  mfc1  $t9, $f18
/* 00860C 70007A0C 00000000 */  nop   
/* 008610 70007A10 00592021 */  addu  $a0, $v0, $t9
/* 008614 70007A14 3088FFFF */  andi  $t0, $a0, 0xffff
/* 008618 70007A18 01002025 */  move  $a0, $t0
/* 00861C 70007A1C 0C001CF1 */  jal   musicTrack2Vol
/* 008620 70007A20 A7A80026 */   sh    $t0, 0x26($sp)
/* 008624 70007A24 3C068006 */  lui   $a2, %hi(music2_rate)
/* 008628 70007A28 24C63854 */  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
/* 00862C 70007A2C 8CC90000 */  lw    $t1, ($a2)
/* 008630 70007A30 97A40026 */  lhu   $a0, 0x26($sp)
/* 008634 70007A34 252AFFFF */  addiu $t2, $t1, -1
/* 008638 70007A38 1D40000A */  bgtz  $t2, .L70007A64
/* 00863C 70007A3C ACCA0000 */   sw    $t2, ($a2)
/* 008640 70007A40 14800005 */  bnez  $a0, .L70007A58
/* 008644 70007A44 3C048006 */   lui   $a0, %hi(seqp_2)
/* 008648 70007A48 0C004B5C */  jal   alCSPStop
/* 00864C 70007A4C 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
/* 008650 70007A50 3C068006 */  lui   $a2, %hi(music2_rate)
/* 008654 70007A54 24C63854 */  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
.L70007A58:
/* 008658 70007A58 ACC00000 */  sw    $zero, ($a2)
/* 00865C 70007A5C 3C018002 */  lui   $at, %hi(music2_playing)
/* 008660 70007A60 AC204350 */  sw    $zero, %lo(music2_playing)($at)
.L70007A64:
/* 008664 70007A64 3C0C8002 */  lui   $t4, %hi(music3_playing) 
/* 008668 70007A68 8D8C4354 */  lw    $t4, %lo(music3_playing)($t4)
/* 00866C 70007A6C 51800027 */  beql  $t4, $zero, .L70007B0C
/* 008670 70007A70 8FBF0014 */   lw    $ra, 0x14($sp)
/* 008674 70007A74 0C001DD0 */  jal   get_music3len
/* 008678 70007A78 00000000 */   nop   
/* 00867C 70007A7C 3C068006 */  lui   $a2, %hi(music3_rate)
/* 008680 70007A80 3C0D8006 */  lui   $t5, %hi(music3_length) 
/* 008684 70007A84 95AD384E */  lhu   $t5, %lo(music3_length)($t5)
/* 008688 70007A88 24C63858 */  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
/* 00868C 70007A8C 8CCE0000 */  lw    $t6, ($a2)
/* 008690 70007A90 01A22823 */  subu  $a1, $t5, $v0
/* 008694 70007A94 44852000 */  mtc1  $a1, $f4
/* 008698 70007A98 448E4000 */  mtc1  $t6, $f8
/* 00869C 70007A9C 468021A0 */  cvt.s.w $f6, $f4
/* 0086A0 70007AA0 468042A0 */  cvt.s.w $f10, $f8
/* 0086A4 70007AA4 460A3403 */  div.s $f16, $f6, $f10
/* 0086A8 70007AA8 4600848D */  trunc.w.s $f18, $f16
/* 0086AC 70007AAC 44189000 */  mfc1  $t8, $f18
/* 0086B0 70007AB0 00000000 */  nop   
/* 0086B4 70007AB4 00582021 */  addu  $a0, $v0, $t8
/* 0086B8 70007AB8 3099FFFF */  andi  $t9, $a0, 0xffff
/* 0086BC 70007ABC 03202025 */  move  $a0, $t9
/* 0086C0 70007AC0 0C001DD3 */  jal   musicTrack3Vol
/* 0086C4 70007AC4 A7B9001E */   sh    $t9, 0x1e($sp)
/* 0086C8 70007AC8 3C068006 */  lui   $a2, %hi(music3_rate)
/* 0086CC 70007ACC 24C63858 */  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
/* 0086D0 70007AD0 8CC80000 */  lw    $t0, ($a2)
/* 0086D4 70007AD4 97A4001E */  lhu   $a0, 0x1e($sp)
/* 0086D8 70007AD8 2509FFFF */  addiu $t1, $t0, -1
/* 0086DC 70007ADC 1D20000A */  bgtz  $t1, .L70007B08
/* 0086E0 70007AE0 ACC90000 */   sw    $t1, ($a2)
/* 0086E4 70007AE4 14800005 */  bnez  $a0, .L70007AFC
/* 0086E8 70007AE8 3C048006 */   lui   $a0, %hi(seqp_3)
/* 0086EC 70007AEC 0C004B5C */  jal   alCSPStop
/* 0086F0 70007AF0 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
/* 0086F4 70007AF4 3C068006 */  lui   $a2, %hi(music3_rate)
/* 0086F8 70007AF8 24C63858 */  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
.L70007AFC:
/* 0086FC 70007AFC ACC00000 */  sw    $zero, ($a2)
/* 008700 70007B00 3C018002 */  lui   $at, %hi(music3_playing)
/* 008704 70007B04 AC204354 */  sw    $zero, %lo(music3_playing)($at)
.L70007B08:
/* 008708 70007B08 8FBF0014 */  lw    $ra, 0x14($sp)
.L70007B0C:
/* 00870C 70007B0C 27BD0030 */  addiu $sp, $sp, 0x30
/* 008710 70007B10 03E00008 */  jr    $ra
/* 008714 70007B14 00000000 */   nop
)
#endif



