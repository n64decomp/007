#include <ultra64.h>
//#include <bondtypes.h>
#include <deb.h>
#include "stan.h"
#include "bg.h"
#include "chrai.h"
#include "chr.h"
#include "unk_0B3200.h"
#include "assert.h"

// bss
struct StanPrefixRecord {
    //CODE.bss:8007B120
    s32 stanfile;
    //CODE.bss:8007B124
    StandTile *ptr_firstroom;    // read as offset 4, hence the struct
};

struct StanPrefixRecord stan_prefix;



//CODE.bss:8007B128
s32 firststaninroom;
//CODE.bss:8007B12C
s32 dword_CODE_bss_8007B12C;
//CODE.bss:8007B130
s32 dword_CODE_bss_8007B130; //stanladder s1
//CODE.bss:8007B134
char dword_CODE_bss_8007B134;
char dword_CODE_bss_8007B135;
char dword_CODE_bss_8007B136;
char dword_CODE_bss_8007B137;
char dword_CODE_bss_8007B138[0x21C];
//CODE.bss:8007B354
s32 dword_CODE_bss_8007B354;
//CODE.bss:8007B358 //stan list array
s32 dword_CODE_bss_8007B358[0x1a1];
//CODE.bss:8007B9DC
s32 dword_CODE_bss_8007B9DC; //region?
//CODE.bss:8007B9E0
s32 dword_CODE_bss_8007B9E0;



// All relating to a saved collision, but not one struct
//CODE.bss:8007B9E4
StandTile *stanSavedColl_tile;
//CODE.bss:8007B9E8
s32 stanSavedColl_pointI;
//CODE.bss:8007B9EC
s32 stanSavedColl_unknown;
//CODE.bss:8007B9F0
struct coord2d stanSavedColl_pntA;
//CODE.bss:8007B9F8
struct coord2d stanSavedColl_pntB;
//CODE.bss:8007BA00
f32 stanSavedColl_someMin;

//CODE.bss:8007BA04
PropRecord * stanSavedColl_posData;


//CODE.bss:8007BA08
s32 dword_CODE_bss_8007BA08;
//CODE.bss:8007BA0C
StandTile * dword_CODE_bss_8007BA0C;
//CODE.bss:8007BA10
StandTile *bfsTileStack[352];


// data

//D:80040F30 //stanladder related
u8 D_80040F30[] = {
    0x8D, 0x86, 0x04, 0xC5,
    0x9D, 0xA4, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

s32 stan_c_debug_notice_list_entry = 0;

//D:80040F44
f32 level_scale = 1.0;
//D:80040F48
f32 inv_level_scale = 1.0;
//D:80040F4C
u8 list_of_tilesizes[] = {
    0x20,0x20,0x20,0x20,
    0x28,0x30,0x38,0x40,
    0x48,0x50,0x58,0x00
};
//D:80040F58
struct StandTile * standTileStart = NULL;
//D:80040F5C
s32 ptr_firstroom_0 = 0;
//D:80040F60
struct StanPrefixRecord* D_80040F60 = 0;
//D:80040F64
s32 D_80040F64[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:80040FAC
s32 D_80040FAC = 0;
//D:80040FB0
s32 m_stanRegion = 0;
//D:80040FB4
s32 stanlinelog_flag = 0;

#if defined(LEFTOVERDEBUG)

s32 D_80040FB8[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0
};
#endif
//D:800413BC
s32 D_800413BC =  0;
//D:800413C0
f32 D_800413C0 =  0.0;
//D:800413C4
f32 D_800413C4 =  0.0;
//D:800413C8
s32 D_800413C8 =  1;
//D:800413CC
s32 D_800413CC =  1;
//D:800413D0
s32 D_800413D0[] =  {0, 0, 0, 0, 0, 0, 0, 0};


// rodata
//D:800585A0
const char aCDCC[] = "%c%d%c%c";
//D:800585AC
const char aStan_c_debug[] = "stan_c_debug";
//D:800585BC
const char aStanlinelog[] = "-stanlinelog";

// forward declarations

s32 stanIsSpecialBit1Set(StandTile *arg0, struct StandTileLocusCallbackRecord* arg1);
s32 sub_GAME_7F0B2274(StandTile *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, struct StandTileLocusCallbackRecord *arg5);
s32 sub_GAME_7F0B21B0(StandTile **tileStack, f32 target_x, f32 target_z, f32 unknown, s32 unk00, s32 *count_rtn, s32 bufMax);

s32 sub_GAME_7F0B1DDC(
    struct StandTile**,
    f32,
    f32,
    f32,
    standTileLocusCallback_A_t,
    standTileLocusCallback_B_t,
    standTileLocusCallback_C_t,
    struct StandTileLocusCallbackRecord*
);
s32 sub_GAME_7F0B2110(StandTile *tile, struct StandTileLocusCallbackRecord*);
s32 stanGetLocusField0(struct StandTileLocusCallbackRecord *arg0);
s32 stanGetLocusCount(struct StandTileLocusCallbackRecord *arg0);
s32 sub_GAME_7F0B260C(StandTile *tile, s32 index, f32 p_x, f32 p_z, s32 arg4, struct StandTileLocusCallbackRecord *arg5);

// end forward declarations

s32 stanBitwiseCastF32(f32 arg0)
{
    // disgusting
    return *(s32*)&arg0;
}

#ifdef NONMATCHING
// maybe getstanroomID and returns a string
s32 sub_GAME_7F0AEF3C(void *arg0) {
    s32 sp24;
    s32 temp_a1;
    s32 phi_v0;

    // Node 0
    sp24 = (s32) ((D_80040FAC * 9) + &D_80040F64);
    temp_a1 = (arg0->unk2 & 7);
    D_80040FAC = (s32) ((D_80040FAC + 1) & 7);
    if (temp_a1 == 0)
    {
        // Node 1
        phi_v0 = 0;
    }
    else
    {
        // Node 2
        phi_v0 = (temp_a1 + 0x30);
    }
    // Node 3
    sprintf(sp24, &aCDCC, ((((s32) *arg0 >> 0xf) & 1) + 0x70), (*arg0 & 0x7fff), (s32) ((((s32) arg0->unk2 >> 3) & 0x1f) + 0x61), (s32) phi_v0);
    return sp24;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AEF3C
/* 0E3A6C 7F0AEF3C 3C068004 */  lui   $a2, %hi(D_80040FAC)
/* 0E3A70 7F0AEF40 8CC60FAC */  lw    $a2, %lo(D_80040FAC)($a2)
/* 0E3A74 7F0AEF44 3C0F8004 */  lui   $t7, %hi(D_80040F64)
/* 0E3A78 7F0AEF48 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E3A7C 7F0AEF4C 000670C0 */  sll   $t6, $a2, 3
/* 0E3A80 7F0AEF50 25EF0F64 */  addiu $t7, %lo(D_80040F64) # addiu $t7, $t7, 0xf64
/* 0E3A84 7F0AEF54 01C67021 */  addu  $t6, $t6, $a2
/* 0E3A88 7F0AEF58 01CFC021 */  addu  $t8, $t6, $t7
/* 0E3A8C 7F0AEF5C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E3A90 7F0AEF60 AFB80024 */  sw    $t8, 0x24($sp)
/* 0E3A94 7F0AEF64 94820000 */  lhu   $v0, ($a0)
/* 0E3A98 7F0AEF68 90830002 */  lbu   $v1, 2($a0)
/* 0E3A9C 7F0AEF6C 24C60001 */  addiu $a2, $a2, 1
/* 0E3AA0 7F0AEF70 000243C3 */  sra   $t0, $v0, 0xf
/* 0E3AA4 7F0AEF74 000348C3 */  sra   $t1, $v1, 3
/* 0E3AA8 7F0AEF78 30D90007 */  andi  $t9, $a2, 7
/* 0E3AAC 7F0AEF7C 310A0001 */  andi  $t2, $t0, 1
/* 0E3AB0 7F0AEF80 312B001F */  andi  $t3, $t1, 0x1f
/* 0E3AB4 7F0AEF84 3C018004 */  lui   $at, %hi(D_80040FAC)
/* 0E3AB8 7F0AEF88 30650007 */  andi  $a1, $v1, 7
/* 0E3ABC 7F0AEF8C 01404025 */  move  $t0, $t2
/* 0E3AC0 7F0AEF90 01604825 */  move  $t1, $t3
/* 0E3AC4 7F0AEF94 AC390FAC */  sw    $t9, %lo(D_80040FAC)($at)
/* 0E3AC8 7F0AEF98 14A00003 */  bnez  $a1, .L7F0AEFA8
/* 0E3ACC 7F0AEF9C 30477FFF */   andi  $a3, $v0, 0x7fff
/* 0E3AD0 7F0AEFA0 10000002 */  b     .L7F0AEFAC
/* 0E3AD4 7F0AEFA4 00001025 */   move  $v0, $zero
.L7F0AEFA8:
/* 0E3AD8 7F0AEFA8 24A20030 */  addiu $v0, $a1, 0x30
.L7F0AEFAC:
/* 0E3ADC 7F0AEFAC 3C058006 */  lui   $a1, %hi(aCDCC)
/* 0E3AE0 7F0AEFB0 252C0061 */  addiu $t4, $t1, 0x61
/* 0E3AE4 7F0AEFB4 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0E3AE8 7F0AEFB8 24A585A0 */  addiu $a1, %lo(aCDCC) # addiu $a1, $a1, -0x7a60
/* 0E3AEC 7F0AEFBC 8FA40024 */  lw    $a0, 0x24($sp)
/* 0E3AF0 7F0AEFC0 25060070 */  addiu $a2, $t0, 0x70
/* 0E3AF4 7F0AEFC4 0C002B25 */  jal   sprintf
/* 0E3AF8 7F0AEFC8 AFA20014 */   sw    $v0, 0x14($sp)
/* 0E3AFC 7F0AEFCC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E3B00 7F0AEFD0 8FA20024 */  lw    $v0, 0x24($sp)
/* 0E3B04 7F0AEFD4 27BD0028 */  addiu $sp, $sp, 0x28
/* 0E3B08 7F0AEFD8 03E00008 */  jr    $ra
/* 0E3B0C 7F0AEFDC 00000000 */   nop
)
#endif




void sub_GAME_7F0AEFE0(void) {
    sub_GAME_7F0AEF3C(); //maybe getstanroomID
}

//stanChecksf
u32 stanRemovedAnimationRoutine(s32 arg0) {
    /*
      if (arg0 < g_someinteger)
      {
        printf("checksf: ERROR line %d %08x<%08x",__LINE__,arg0,g_someInteger);
      }
      if (arg0 > g_someinteger2)
      {
        printf("checksf: ERROR line %d %08x>%08x",__LINE__,arg0,g_someinteger2);
      }
  */
    return 0;
}

void stanInit(void) {
    debTryAdd(&stan_c_debug_notice_list_entry, &aStan_c_debug);//"stan_c_debug");
}






#ifdef NONMATCHING
void sub_GAME_7F0AF038(void) {
    void *temp_v1;
    s32 temp_s0;
    s32 temp_a2;
    void *temp_s0_2;
    s32 temp_s0_4;
    s16 temp_s0_3;
    s32 temp_s2;
    s32 temp_v1_2;
    s32 temp_s0_5;
    void *temp_a0;
    void *phi_v1;
    s32 curroom;
    void *firststan;
    void *phi_s3;
    void *phi_s5;
    s16 phi_s0;
    s32 phi_s2;
    s32 phi_v1_2;
    s32 phi_s0_2;
    void *phi_s1;
    s32 phi_a2;

    // Node 0
    dword_CODE_bss_8007B9DC = 0;
    dword_CODE_bss_8007B12C = 0;
    dword_CODE_bss_8007B12C = 0;
    dword_CODE_bss_8007B130 = 0;
    phi_v1 = &dword_CODE_bss_8007B134;
loop_1:
    // Node 1
    temp_v1 = (phi_v1 + 0x10);
    temp_v1->unk-10 = 0;
    temp_v1->unk-C = 0;
    temp_v1->unk-8 = 0;
    temp_v1->unk-4 = 0;
    phi_v1 = temp_v1;
    if (temp_v1 != &dword_CODE_bss_8007B354)
    {
        goto loop_1;
    }
    // Node 2
    if (*stan_prefix.ptr_firstroom != 0)
    {
        // Node 3
        curroom = 0xff;
        firststan = stan_prefix.ptr_firstroom;
        curroom = 0xff;
loop_4:
        // Node 4
        temp_s0 = firststan->unk3;
        curroom = curroom;
        if (curroom != temp_s0)
        {
            // Node 5
            curroom = (temp_s0 & 0xff);
            //assert(curroom<MAXSTANROOMS);
            if (curroom >= dword_CODE_bss_8007B9DC)
            {
                // Node 6
                dword_CODE_bss_8007B9DC = (s32) (curroom + 1);
            }
            //        assert(firststaninroom[curroom]==NULL);
            // Node 7
            *(&firststaninroom + (curroom * 4)) = (void *) firststan;
            temp_s0_2 = (&dword_CODE_bss_8007B358 + (curroom * 0xc));
            temp_s0_2->unk4 = (u16)0x7fff;
            temp_s0_2->unkA = (u16)-0x8000;
            temp_s0_2->unk2 = (s16) temp_s0_2->unk4;
            *temp_s0_2 = (s16) temp_s0_2->unk4;
            temp_s0_2->unk8 = (s16) temp_s0_2->unkA;
            temp_s0_2->unk6 = (s16) temp_s0_2->unkA;
            curroom = curroom;
            curroom = curroom;
        }
        // Node 8
        temp_s0_4 = (((s32) firststan->unk6 >> 0xc) & 0xf);
        phi_s0_2 = temp_s0_4;
        if (temp_s0_4 > 0)
        {
            // Node 9
            phi_v1_2 = 0;
            phi_s1 = firststan;
loop_10:
            // Node 10
            phi_s3 = phi_s1;
            phi_s5 = (&dword_CODE_bss_8007B358 + (((curroom * 4) - curroom) * 4));
            phi_s2 = 0;
loop_11:
            // Node 11
            temp_s0_3 = phi_s3->unk8;
            temp_s2 = (phi_s2 + 2);
            phi_s0 = temp_s0_3;
            if (temp_s0_3 < *phi_s5)
            {
                // Node 12
                *phi_s5 = temp_s0_3;
                phi_s0 = phi_s3->unk8;
            }
            // Node 13
            if (phi_s5->unk6 < phi_s0)
            {
                // Node 14
                phi_s5->unk6 = (s16) phi_s0;
            }
            // Node 15
            phi_s3 = (phi_s3 + 2);
            phi_s5 = (phi_s5 + 2);
            phi_s2 = temp_s2;
            if (temp_s2 != 6)
            {
                goto loop_11;
            }
            // Node 16
            temp_v1_2 = (phi_v1_2 + 1);
            temp_s0_5 = (((s32) firststan->unk6 >> 0xc) & 0xf);
            phi_v1_2 = temp_v1_2;
            phi_s0_2 = temp_s0_5;
            phi_s1 = (phi_s1 + 8);
            if (temp_v1_2 < temp_s0_5)
            {
                goto loop_10;
            }
        }
        // Node 17
        temp_a0 = (*(&list_of_tilesizes + phi_s0_2) + firststan);
        firststan = temp_a0;
        curroom = curroom;
        if (*temp_a0 != 0)
        {
            goto loop_4;
        }
    }
    // Node 18
    // Error: assert not self.is_leaf
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AF038
/* 0E3B68 7F0AF038 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E3B6C 7F0AF03C 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007B9DC)
/* 0E3B70 7F0AF040 24E7B9DC */  addiu $a3, %lo(dword_CODE_bss_8007B9DC) # addiu $a3, $a3, -0x4624
/* 0E3B74 7F0AF044 ACE00000 */  sw    $zero, ($a3)
/* 0E3B78 7F0AF048 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007B12C)
/* 0E3B7C 7F0AF04C AC20B128 */  sw    $zero, %lo(firststaninroom)($at)
/* 0E3B80 7F0AF050 AC20B12C */  sw    $zero, %lo(dword_CODE_bss_8007B12C)($at)
/* 0E3B84 7F0AF054 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007B130)
/* 0E3B88 7F0AF058 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007B134)
/* 0E3B8C 7F0AF05C 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007B354)
/* 0E3B90 7F0AF060 AFB5001C */  sw    $s5, 0x1c($sp)
/* 0E3B94 7F0AF064 AFB40018 */  sw    $s4, 0x18($sp)
/* 0E3B98 7F0AF068 AFB30014 */  sw    $s3, 0x14($sp)
/* 0E3B9C 7F0AF06C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E3BA0 7F0AF070 AFB1000C */  sw    $s1, 0xc($sp)
/* 0E3BA4 7F0AF074 AFB00008 */  sw    $s0, 8($sp)
/* 0E3BA8 7F0AF078 240600FF */  li    $a2, 255
/* 0E3BAC 7F0AF07C 2442B354 */  addiu $v0, %lo(dword_CODE_bss_8007B354) # addiu $v0, $v0, -0x4cac
/* 0E3BB0 7F0AF080 2463B134 */  addiu $v1, %lo(dword_CODE_bss_8007B134) # addiu $v1, $v1, -0x4ecc
/* 0E3BB4 7F0AF084 AC20B130 */  sw    $zero, %lo(dword_CODE_bss_8007B130)($at)
.L7F0AF088:
/* 0E3BB8 7F0AF088 24630010 */  addiu $v1, $v1, 0x10
/* 0E3BBC 7F0AF08C AC60FFF0 */  sw    $zero, -0x10($v1)
/* 0E3BC0 7F0AF090 AC60FFF4 */  sw    $zero, -0xc($v1)
/* 0E3BC4 7F0AF094 AC60FFF8 */  sw    $zero, -8($v1)
/* 0E3BC8 7F0AF098 1462FFFB */  bne   $v1, $v0, .L7F0AF088
/* 0E3BCC 7F0AF09C AC60FFFC */   sw    $zero, -4($v1)
/* 0E3BD0 7F0AF0A0 3C0E8008 */  lui   $t6, %hi(stan_prefix)
/* 0E3BD4 7F0AF0A4 8DCEB120 */  lw    $t6, %lo(stan_prefix)($t6)
/* 0E3BD8 7F0AF0A8 3C0D8004 */  lui   $t5, %hi(list_of_tilesizes)
/* 0E3BDC 7F0AF0AC 25AD0F4C */  addiu $t5, %lo(list_of_tilesizes) # addiu $t5, $t5, 0xf4c
/* 0E3BE0 7F0AF0B0 8DC40004 */  lw    $a0, 4($t6)
/* 0E3BE4 7F0AF0B4 00C02825 */  move  $a1, $a2
/* 0E3BE8 7F0AF0B8 240C8000 */  li    $t4, -32768
/* 0E3BEC 7F0AF0BC 8C8F0000 */  lw    $t7, ($a0)
/* 0E3BF0 7F0AF0C0 240B7FFF */  li    $t3, 32767
/* 0E3BF4 7F0AF0C4 240A000C */  li    $t2, 12
/* 0E3BF8 7F0AF0C8 11E00048 */  beqz  $t7, .L7F0AF1EC
/* 0E3BFC 7F0AF0CC 3C098008 */   lui   $t1, %hi(dword_CODE_bss_8007B358)
/* 0E3C00 7F0AF0D0 3C088008 */  lui   $t0, %hi(firststaninroom)
/* 0E3C04 7F0AF0D4 2508B128 */  addiu $t0, %lo(firststaninroom) # addiu $t0, $t0, -0x4ed8
/* 0E3C08 7F0AF0D8 2529B358 */  addiu $t1, %lo(dword_CODE_bss_8007B358) # addiu $t1, $t1, -0x4ca8
/* 0E3C0C 7F0AF0DC 24020006 */  li    $v0, 6
/* 0E3C10 7F0AF0E0 90900003 */  lbu   $s0, 3($a0)
.L7F0AF0E4:
/* 0E3C14 7F0AF0E4 00001825 */  move  $v1, $zero
/* 0E3C18 7F0AF0E8 50B00017 */  beql  $a1, $s0, .L7F0AF148
/* 0E3C1C 7F0AF0EC 84900006 */   lh    $s0, 6($a0)
/* 0E3C20 7F0AF0F0 8CF80000 */  lw    $t8, ($a3)
/* 0E3C24 7F0AF0F4 320600FF */  andi  $a2, $s0, 0xff
/* 0E3C28 7F0AF0F8 00C02825 */  move  $a1, $a2
/* 0E3C2C 7F0AF0FC 00D8082A */  slt   $at, $a2, $t8
/* 0E3C30 7F0AF100 14200002 */  bnez  $at, .L7F0AF10C
/* 0E3C34 7F0AF104 24B90001 */   addiu $t9, $a1, 1
/* 0E3C38 7F0AF108 ACF90000 */  sw    $t9, ($a3)
.L7F0AF10C:
/* 0E3C3C 7F0AF10C 00CA0019 */  multu $a2, $t2
/* 0E3C40 7F0AF110 00067080 */  sll   $t6, $a2, 2
/* 0E3C44 7F0AF114 010E7821 */  addu  $t7, $t0, $t6
/* 0E3C48 7F0AF118 ADE40000 */  sw    $a0, ($t7)
/* 0E3C4C 7F0AF11C 0000C012 */  mflo  $t8
/* 0E3C50 7F0AF120 01388021 */  addu  $s0, $t1, $t8
/* 0E3C54 7F0AF124 A60B0004 */  sh    $t3, 4($s0)
/* 0E3C58 7F0AF128 86110004 */  lh    $s1, 4($s0)
/* 0E3C5C 7F0AF12C A60C000A */  sh    $t4, 0xa($s0)
/* 0E3C60 7F0AF130 A6110002 */  sh    $s1, 2($s0)
/* 0E3C64 7F0AF134 A6110000 */  sh    $s1, ($s0)
/* 0E3C68 7F0AF138 8611000A */  lh    $s1, 0xa($s0)
/* 0E3C6C 7F0AF13C A6110008 */  sh    $s1, 8($s0)
/* 0E3C70 7F0AF140 A6110006 */  sh    $s1, 6($s0)
/* 0E3C74 7F0AF144 84900006 */  lh    $s0, 6($a0)
.L7F0AF148:
/* 0E3C78 7F0AF148 00067880 */  sll   $t7, $a2, 2
/* 0E3C7C 7F0AF14C 01E67823 */  subu  $t7, $t7, $a2
/* 0E3C80 7F0AF150 0010CB03 */  sra   $t9, $s0, 0xc
/* 0E3C84 7F0AF154 3330000F */  andi  $s0, $t9, 0xf
/* 0E3C88 7F0AF158 1A00001E */  blez  $s0, .L7F0AF1D4
/* 0E3C8C 7F0AF15C 00808825 */   move  $s1, $a0
/* 0E3C90 7F0AF160 000F7880 */  sll   $t7, $t7, 2
/* 0E3C94 7F0AF164 012FA021 */  addu  $s4, $t1, $t7
/* 0E3C98 7F0AF168 00009025 */  move  $s2, $zero
.L7F0AF16C:
/* 0E3C9C 7F0AF16C 02209825 */  move  $s3, $s1
/* 0E3CA0 7F0AF170 0280A825 */  move  $s5, $s4
.L7F0AF174:
/* 0E3CA4 7F0AF174 86700008 */  lh    $s0, 8($s3)
/* 0E3CA8 7F0AF178 86B80000 */  lh    $t8, ($s5)
/* 0E3CAC 7F0AF17C 26520002 */  addiu $s2, $s2, 2
/* 0E3CB0 7F0AF180 0218082A */  slt   $at, $s0, $t8
/* 0E3CB4 7F0AF184 50200004 */  beql  $at, $zero, .L7F0AF198
/* 0E3CB8 7F0AF188 86B90006 */   lh    $t9, 6($s5)
/* 0E3CBC 7F0AF18C A6B00000 */  sh    $s0, ($s5)
/* 0E3CC0 7F0AF190 86700008 */  lh    $s0, 8($s3)
/* 0E3CC4 7F0AF194 86B90006 */  lh    $t9, 6($s5)
.L7F0AF198:
/* 0E3CC8 7F0AF198 26730002 */  addiu $s3, $s3, 2
/* 0E3CCC 7F0AF19C 0330082A */  slt   $at, $t9, $s0
/* 0E3CD0 7F0AF1A0 10200002 */  beqz  $at, .L7F0AF1AC
/* 0E3CD4 7F0AF1A4 00000000 */   nop
/* 0E3CD8 7F0AF1A8 A6B00006 */  sh    $s0, 6($s5)
.L7F0AF1AC:
/* 0E3CDC 7F0AF1AC 1642FFF1 */  bne   $s2, $v0, .L7F0AF174
/* 0E3CE0 7F0AF1B0 26B50002 */   addiu $s5, $s5, 2
/* 0E3CE4 7F0AF1B4 84900006 */  lh    $s0, 6($a0)
/* 0E3CE8 7F0AF1B8 24630001 */  addiu $v1, $v1, 1
/* 0E3CEC 7F0AF1BC 26310008 */  addiu $s1, $s1, 8
/* 0E3CF0 7F0AF1C0 00107303 */  sra   $t6, $s0, 0xc
/* 0E3CF4 7F0AF1C4 31D0000F */  andi  $s0, $t6, 0xf
/* 0E3CF8 7F0AF1C8 0070082A */  slt   $at, $v1, $s0
/* 0E3CFC 7F0AF1CC 5420FFE7 */  bnezl $at, .L7F0AF16C
/* 0E3D00 7F0AF1D0 00009025 */   move  $s2, $zero
.L7F0AF1D4:
/* 0E3D04 7F0AF1D4 01B0C021 */  addu  $t8, $t5, $s0
/* 0E3D08 7F0AF1D8 93190000 */  lbu   $t9, ($t8)
/* 0E3D0C 7F0AF1DC 03242021 */  addu  $a0, $t9, $a0
/* 0E3D10 7F0AF1E0 8C8E0000 */  lw    $t6, ($a0)
/* 0E3D14 7F0AF1E4 55C0FFBF */  bnezl $t6, .L7F0AF0E4
/* 0E3D18 7F0AF1E8 90900003 */   lbu   $s0, 3($a0)
.L7F0AF1EC:
/* 0E3D1C 7F0AF1EC 8FB00008 */  lw    $s0, 8($sp)
/* 0E3D20 7F0AF1F0 8FB1000C */  lw    $s1, 0xc($sp)
/* 0E3D24 7F0AF1F4 8FB20010 */  lw    $s2, 0x10($sp)
/* 0E3D28 7F0AF1F8 8FB30014 */  lw    $s3, 0x14($sp)
/* 0E3D2C 7F0AF1FC 8FB40018 */  lw    $s4, 0x18($sp)
/* 0E3D30 7F0AF200 8FB5001C */  lw    $s5, 0x1c($sp)
/* 0E3D34 7F0AF204 03E00008 */  jr    $ra
/* 0E3D38 7F0AF208 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0AF20C(void)
{
  float fVar1;
  bool bVar2;
  int iVar3;
  double dVar4;
  float *pfStack00000014;
  int iStack0000001c;
  float *pfStack00000024;
  dword local_c0;
  dword local_70;
  dword local_6c;
  int *local_68;
  int *local_64;
  short local_60;
  short local_5e;
  short local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_48 [2];
  float local_40;
  float local_3c;
  uint local_38;
  int local_34;
  float local_30;
  int *local_2c;
  int local_28;
  float local_24;
  qword local_20;
  qword local_18;
  qword local_10;
  dword local_8;

  local_68 = NULL;
  local_3c = -3.402823e+38;
  bVar2 = false;
  local_58 = *param_1 * level_scale;
  local_54 = param_1[1] * level_scale;
  local_50 = param_1[2] * level_scale;
  if (32767.0 < local_54) {
    local_54 = 32767.0;
  }
  if (local_54 < -32767.0) {
    local_54 = -32767.0;
  }
  local_20._6_2_ = local_58;
  local_60 = local_20._6_2_;
  local_18._6_2_ = local_54;
  local_5e = local_18._6_2_;
  local_10._6_2_ = local_50;
  local_5c = local_10._6_2_;
  local_38 = 0;
  pfStack00000014 = param_1;
  iStack0000001c = param_2;
  pfStack00000024 = param_3;
  do {
    if (DAT_83aa0290 <= local_38) {
      if ((local_68 != NULL) && (pfStack00000024 != NULL)) {
        *pfStack00000024 = local_3c;
      }
      return local_68;
    }
    if (((((firststaninroom[local_38] != NULL) &&
          (stanfileRecord_ARRAY_83aa0a58[local_38].id <= local_60)) &&
         (local_60 <= stanfileRecord_ARRAY_83aa0a58[local_38].tail)) &&
        ((stanfileRecord_ARRAY_83aa0a58[local_38].mid <= local_5c &&
         (local_5c <= *(&stanfileRecord_ARRAY_83aa0a58[local_38].points + 2))))) &&
       (stanfileRecord_ARRAY_83aa0a58[local_38].id2 <= local_5e)) {
      if (iStack0000001c == 0) {
LAB_8238358c:
        for (local_2c = firststaninroom[local_38]; (*local_2c != 0 && (*(local_2c + 3) == local_38))
            ; local_2c = getNextStan(local_2c)) {
          for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
            dVar4 = getShortest2dDispToInfTripleEdge(local_58,local_50,local_2c,local_28);
            if (dVar4 < -2.0) goto LAB_823835a8;
            if (dVar4 < 2.0) {
              bVar2 = true;
            }
          }
          iVar3 = sub_GAME_7F0AF760(local_2c);
          if (iVar3 == 0) {
            if (bVar2) {
              getTileMidPoint(local_2c,local_48);
              local_64 = local_2c;
              iVar3 = walkTilesBetweenPoints_NoCallback
                                (local_48[0],local_40,*pfStack00000014,pfStack00000014[2],&local_64)
              ;
              if ((iVar3 == 0) || (local_64 != local_2c)) goto LAB_823835a8;
            }
            dVar4 = stanGetPositionYValue(*pfStack00000014,pfStack00000014[2],local_2c);
            fVar1 = dVar4;
            if ((fVar1 <= pfStack00000014[1]) && (local_3c < fVar1)) {
              local_68 = local_2c;
              local_3c = fVar1;
            }
          }
LAB_823835a8:
        }
      }
      else {
        for (local_28 = 0; (*(iStack0000001c + local_28) != -1 && (local_28 < 4));
            local_28 = local_28 + 1) {
          if (*(iStack0000001c + local_28) == local_38) goto LAB_8238358c;
        }
      }
    }
    local_38 = local_38 + 1;
  } while( true );
}


#else
GLOBAL_ASM(
.late_rodata
glabel D_800585CC
.word 0x46fffe00 /*32767.0*/
glabel D_800585D0
.word 0xff7fffff /*-3.4028235e38*/
glabel D_800585D4
.word 0xc6fffe00 /*-32767.0*/
.text
glabel sub_GAME_7F0AF20C
/* 0E3D3C 7F0AF20C 27BDFF38 */  addiu $sp, $sp, -0xc8
/* 0E3D40 7F0AF210 3C018006 */  lui   $at, %hi(D_800585CC)
/* 0E3D44 7F0AF214 C42285CC */  lwc1  $f2, %lo(D_800585CC)($at)
/* 0E3D48 7F0AF218 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0E3D4C 7F0AF21C 3C018006 */  lui   $at, %hi(D_800585D0)
/* 0E3D50 7F0AF220 C43885D0 */  lwc1  $f24, %lo(D_800585D0)($at)
/* 0E3D54 7F0AF224 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0E3D58 7F0AF228 AFBE0058 */  sw    $fp, 0x58($sp)
/* 0E3D5C 7F0AF22C AFB70054 */  sw    $s7, 0x54($sp)
/* 0E3D60 7F0AF230 AFB60050 */  sw    $s6, 0x50($sp)
/* 0E3D64 7F0AF234 AFB5004C */  sw    $s5, 0x4c($sp)
/* 0E3D68 7F0AF238 AFB40048 */  sw    $s4, 0x48($sp)
/* 0E3D6C 7F0AF23C AFB30044 */  sw    $s3, 0x44($sp)
/* 0E3D70 7F0AF240 AFB20040 */  sw    $s2, 0x40($sp)
/* 0E3D74 7F0AF244 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0E3D78 7F0AF248 AFB00038 */  sw    $s0, 0x38($sp)
/* 0E3D7C 7F0AF24C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0E3D80 7F0AF250 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0E3D84 7F0AF254 AFA500CC */  sw    $a1, 0xcc($sp)
/* 0E3D88 7F0AF258 AFA600D0 */  sw    $a2, 0xd0($sp)
/* 0E3D8C 7F0AF25C AFA0009C */  sw    $zero, 0x9c($sp)
/* 0E3D90 7F0AF260 3C018004 */  lui   $at, %hi(level_scale)
/* 0E3D94 7F0AF264 C4200F44 */  lwc1  $f0, %lo(level_scale)($at)
/* 0E3D98 7F0AF268 C4840000 */  lwc1  $f4, ($a0)
/* 0E3D9C 7F0AF26C 0080A025 */  move  $s4, $a0
/* 0E3DA0 7F0AF270 3C178004 */  lui   $s7, %hi(list_of_tilesizes)
/* 0E3DA4 7F0AF274 46002182 */  mul.s $f6, $f4, $f0
/* 0E3DA8 7F0AF278 3C0A8008 */  lui   $t2, %hi(firststaninroom)
/* 0E3DAC 7F0AF27C 3C018006 */  lui   $at, %hi(D_800585D4)
/* 0E3DB0 7F0AF280 254AB128 */  addiu $t2, %lo(firststaninroom) # addiu $t2, $t2, -0x4ed8
/* 0E3DB4 7F0AF284 26F70F4C */  addiu $s7, %lo(list_of_tilesizes) # addiu $s7, $s7, 0xf4c
/* 0E3DB8 7F0AF288 24130003 */  li    $s3, 3
/* 0E3DBC 7F0AF28C 241600FF */  li    $s6, 255
/* 0E3DC0 7F0AF290 E7A600B8 */  swc1  $f6, 0xb8($sp)
/* 0E3DC4 7F0AF294 C4880004 */  lwc1  $f8, 4($a0)
/* 0E3DC8 7F0AF298 27BE007C */  addiu $fp, $sp, 0x7c
/* 0E3DCC 7F0AF29C 46004282 */  mul.s $f10, $f8, $f0
/* 0E3DD0 7F0AF2A0 E7AA00BC */  swc1  $f10, 0xbc($sp)
/* 0E3DD4 7F0AF2A4 C4900008 */  lwc1  $f16, 8($a0)
/* 0E3DD8 7F0AF2A8 C7A400BC */  lwc1  $f4, 0xbc($sp)
/* 0E3DDC 7F0AF2AC 24040004 */  li    $a0, 4
/* 0E3DE0 7F0AF2B0 46008482 */  mul.s $f18, $f16, $f0
/* 0E3DE4 7F0AF2B4 4604103C */  c.lt.s $f2, $f4
/* 0E3DE8 7F0AF2B8 00000000 */  nop
/* 0E3DEC 7F0AF2BC 45000002 */  bc1f  .L7F0AF2C8
/* 0E3DF0 7F0AF2C0 E7B200C0 */   swc1  $f18, 0xc0($sp)
/* 0E3DF4 7F0AF2C4 E7A200BC */  swc1  $f2, 0xbc($sp)
.L7F0AF2C8:
/* 0E3DF8 7F0AF2C8 C42085D4 */  lwc1  $f0, %lo(D_800585D4)($at)
/* 0E3DFC 7F0AF2CC C7AC00BC */  lwc1  $f12, 0xbc($sp)
/* 0E3E00 7F0AF2D0 C7A200C0 */  lwc1  $f2, 0xc0($sp)
/* 0E3E04 7F0AF2D4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0E3E08 7F0AF2D8 4600603C */  c.lt.s $f12, $f0
/* 0E3E0C 7F0AF2DC 0000A825 */  move  $s5, $zero
/* 0E3E10 7F0AF2E0 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007B9DC)
/* 0E3E14 7F0AF2E4 4600128D */  trunc.w.s $f10, $f2
/* 0E3E18 7F0AF2E8 45020003 */  bc1fl .L7F0AF2F8
/* 0E3E1C 7F0AF2EC C7A000B8 */   lwc1  $f0, 0xb8($sp)
/* 0E3E20 7F0AF2F0 46000306 */  mov.s $f12, $f0
/* 0E3E24 7F0AF2F4 C7A000B8 */  lwc1  $f0, 0xb8($sp)
.L7F0AF2F8:
/* 0E3E28 7F0AF2F8 4600620D */  trunc.w.s $f8, $f12
/* 0E3E2C 7F0AF2FC 8CC6B9DC */  lw    $a2, %lo(dword_CODE_bss_8007B9DC)($a2)
/* 0E3E30 7F0AF300 44095000 */  mfc1  $t1, $f10
/* 0E3E34 7F0AF304 4600018D */  trunc.w.s $f6, $f0
/* 0E3E38 7F0AF308 44194000 */  mfc1  $t9, $f8
/* 0E3E3C 7F0AF30C E7AC00BC */  swc1  $f12, 0xbc($sp)
/* 0E3E40 7F0AF310 A7A900B0 */  sh    $t1, 0xb0($sp)
/* 0E3E44 7F0AF314 440F3000 */  mfc1  $t7, $f6
/* 0E3E48 7F0AF318 A7B900AE */  sh    $t9, 0xae($sp)
/* 0E3E4C 7F0AF31C 18C0008F */  blez  $a2, .L7F0AF55C
/* 0E3E50 7F0AF320 A7AF00AC */   sh    $t7, 0xac($sp)
/* 0E3E54 7F0AF324 4481B000 */  mtc1  $at, $f22
/* 0E3E58 7F0AF328 3C01C000 */  li    $at, 0xC0000000 # -2.000000
/* 0E3E5C 7F0AF32C 4481A000 */  mtc1  $at, $f20
/* 0E3E60 7F0AF330 AFAA0070 */  sw    $t2, 0x70($sp)
/* 0E3E64 7F0AF334 8FB20088 */  lw    $s2, 0x88($sp)
.L7F0AF338:
/* 0E3E68 7F0AF338 8FAB0070 */  lw    $t3, 0x70($sp)
/* 0E3E6C 7F0AF33C 00156080 */  sll   $t4, $s5, 2
/* 0E3E70 7F0AF340 01956023 */  subu  $t4, $t4, $s5
/* 0E3E74 7F0AF344 8D650000 */  lw    $a1, ($t3)
/* 0E3E78 7F0AF348 3C0D8008 */  lui   $t5, %hi(dword_CODE_bss_8007B358)
/* 0E3E7C 7F0AF34C 25ADB358 */  addiu $t5, %lo(dword_CODE_bss_8007B358) # addiu $t5, $t5, -0x4ca8
/* 0E3E80 7F0AF350 10A0007B */  beqz  $a1, .L7F0AF540
/* 0E3E84 7F0AF354 000C6080 */   sll   $t4, $t4, 2
/* 0E3E88 7F0AF358 018D1021 */  addu  $v0, $t4, $t5
/* 0E3E8C 7F0AF35C 844F0000 */  lh    $t7, ($v0)
/* 0E3E90 7F0AF360 87AE00AC */  lh    $t6, 0xac($sp)
/* 0E3E94 7F0AF364 87B900AC */  lh    $t9, 0xac($sp)
/* 0E3E98 7F0AF368 01CF082A */  slt   $at, $t6, $t7
/* 0E3E9C 7F0AF36C 54200075 */  bnezl $at, .L7F0AF544
/* 0E3EA0 7F0AF370 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3EA4 7F0AF374 84580006 */  lh    $t8, 6($v0)
/* 0E3EA8 7F0AF378 87A800B0 */  lh    $t0, 0xb0($sp)
/* 0E3EAC 7F0AF37C 0319082A */  slt   $at, $t8, $t9
/* 0E3EB0 7F0AF380 54200070 */  bnezl $at, .L7F0AF544
/* 0E3EB4 7F0AF384 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3EB8 7F0AF388 84490004 */  lh    $t1, 4($v0)
/* 0E3EBC 7F0AF38C 87AB00B0 */  lh    $t3, 0xb0($sp)
/* 0E3EC0 7F0AF390 0109082A */  slt   $at, $t0, $t1
/* 0E3EC4 7F0AF394 5420006B */  bnezl $at, .L7F0AF544
/* 0E3EC8 7F0AF398 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3ECC 7F0AF39C 844A000A */  lh    $t2, 0xa($v0)
/* 0E3ED0 7F0AF3A0 87AC00AE */  lh    $t4, 0xae($sp)
/* 0E3ED4 7F0AF3A4 014B082A */  slt   $at, $t2, $t3
/* 0E3ED8 7F0AF3A8 54200066 */  bnezl $at, .L7F0AF544
/* 0E3EDC 7F0AF3AC 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3EE0 7F0AF3B0 844D0002 */  lh    $t5, 2($v0)
/* 0E3EE4 7F0AF3B4 8FAE00CC */  lw    $t6, 0xcc($sp)
/* 0E3EE8 7F0AF3B8 018D082A */  slt   $at, $t4, $t5
/* 0E3EEC 7F0AF3BC 54200061 */  bnezl $at, .L7F0AF544
/* 0E3EF0 7F0AF3C0 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3EF4 7F0AF3C4 51C00015 */  beql  $t6, $zero, .L7F0AF41C
/* 0E3EF8 7F0AF3C8 8CB80000 */   lw    $t8, ($a1)
/* 0E3EFC 7F0AF3CC 91CF0000 */  lbu   $t7, ($t6)
/* 0E3F00 7F0AF3D0 00008025 */  move  $s0, $zero
/* 0E3F04 7F0AF3D4 01C01021 */  addu  $v0, $t6, $zero
/* 0E3F08 7F0AF3D8 12CF000D */  beq   $s6, $t7, .L7F0AF410
/* 0E3F0C 7F0AF3DC 00000000 */   nop
/* 0E3F10 7F0AF3E0 91C30000 */  lbu   $v1, ($t6)
.L7F0AF3E4:
/* 0E3F14 7F0AF3E4 56A30004 */  bnel  $s5, $v1, .L7F0AF3F8
/* 0E3F18 7F0AF3E8 90430001 */   lbu   $v1, 1($v0)
/* 0E3F1C 7F0AF3EC 1000000B */  b     .L7F0AF41C
/* 0E3F20 7F0AF3F0 8CB80000 */   lw    $t8, ($a1)
/* 0E3F24 7F0AF3F4 90430001 */  lbu   $v1, 1($v0)
.L7F0AF3F8:
/* 0E3F28 7F0AF3F8 26100001 */  addiu $s0, $s0, 1
/* 0E3F2C 7F0AF3FC 24420001 */  addiu $v0, $v0, 1
/* 0E3F30 7F0AF400 12C30003 */  beq   $s6, $v1, .L7F0AF410
/* 0E3F34 7F0AF404 00000000 */   nop
/* 0E3F38 7F0AF408 1604FFF6 */  bne   $s0, $a0, .L7F0AF3E4
/* 0E3F3C 7F0AF40C 00000000 */   nop
.L7F0AF410:
/* 0E3F40 7F0AF410 1000004C */  b     .L7F0AF544
/* 0E3F44 7F0AF414 8FAE0070 */   lw    $t6, 0x70($sp)
/* 0E3F48 7F0AF418 8CB80000 */  lw    $t8, ($a1)
.L7F0AF41C:
/* 0E3F4C 7F0AF41C 00A08825 */  move  $s1, $a1
/* 0E3F50 7F0AF420 13000044 */  beqz  $t8, .L7F0AF534
/* 0E3F54 7F0AF424 00000000 */   nop
/* 0E3F58 7F0AF428 90B90003 */  lbu   $t9, 3($a1)
/* 0E3F5C 7F0AF42C 16B90041 */  bne   $s5, $t9, .L7F0AF534
/* 0E3F60 7F0AF430 00008025 */   move  $s0, $zero
.L7F0AF434:
/* 0E3F64 7F0AF434 C7A000B8 */  lwc1  $f0, 0xb8($sp)
.L7F0AF438:
/* 0E3F68 7F0AF438 C7A200C0 */  lwc1  $f2, 0xc0($sp)
/* 0E3F6C 7F0AF43C 02202025 */  move  $a0, $s1
/* 0E3F70 7F0AF440 44060000 */  mfc1  $a2, $f0
/* 0E3F74 7F0AF444 44071000 */  mfc1  $a3, $f2
/* 0E3F78 7F0AF448 0FC2BF9C */  jal   getShortest2dDispToInfTripleEdge
/* 0E3F7C 7F0AF44C 02002825 */   move  $a1, $s0
/* 0E3F80 7F0AF450 4614003C */  c.lt.s $f0, $f20
/* 0E3F84 7F0AF454 26100001 */  addiu $s0, $s0, 1
/* 0E3F88 7F0AF458 4503002B */  bc1tl .L7F0AF508
/* 0E3F8C 7F0AF45C 86220006 */   lh    $v0, 6($s1)
/* 0E3F90 7F0AF460 4616003C */  c.lt.s $f0, $f22
/* 0E3F94 7F0AF464 00000000 */  nop
/* 0E3F98 7F0AF468 45000002 */  bc1f  .L7F0AF474
/* 0E3F9C 7F0AF46C 00000000 */   nop
/* 0E3FA0 7F0AF470 24120001 */  li    $s2, 1
.L7F0AF474:
/* 0E3FA4 7F0AF474 5613FFF0 */  bnel  $s0, $s3, .L7F0AF438
/* 0E3FA8 7F0AF478 C7A000B8 */   lwc1  $f0, 0xb8($sp)
/* 0E3FAC 7F0AF47C 0FC2BDD8 */  jal   sub_GAME_7F0AF760
/* 0E3FB0 7F0AF480 02202025 */   move  $a0, $s1
/* 0E3FB4 7F0AF484 54400020 */  bnezl $v0, .L7F0AF508
/* 0E3FB8 7F0AF488 86220006 */   lh    $v0, 6($s1)
/* 0E3FBC 7F0AF48C 1240000E */  beqz  $s2, .L7F0AF4C8
/* 0E3FC0 7F0AF490 02202025 */   move  $a0, $s1
/* 0E3FC4 7F0AF494 0FC2BE49 */  jal   getTileMidPoint
/* 0E3FC8 7F0AF498 03C02825 */   move  $a1, $fp
/* 0E3FCC 7F0AF49C AFB100A0 */  sw    $s1, 0xa0($sp)
/* 0E3FD0 7F0AF4A0 C6900008 */  lwc1  $f16, 8($s4)
/* 0E3FD4 7F0AF4A4 8E870000 */  lw    $a3, ($s4)
/* 0E3FD8 7F0AF4A8 27A400A0 */  addiu $a0, $sp, 0xa0
/* 0E3FDC 7F0AF4AC 8FA5007C */  lw    $a1, 0x7c($sp)
/* 0E3FE0 7F0AF4B0 8FA60084 */  lw    $a2, 0x84($sp)
/* 0E3FE4 7F0AF4B4 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 0E3FE8 7F0AF4B8 E7B00010 */   swc1  $f16, 0x10($sp)
/* 0E3FEC 7F0AF4BC 10400011 */  beqz  $v0, .L7F0AF504
/* 0E3FF0 7F0AF4C0 8FA800A0 */   lw    $t0, 0xa0($sp)
/* 0E3FF4 7F0AF4C4 1511000F */  bne   $t0, $s1, .L7F0AF504
.L7F0AF4C8:
/* 0E3FF8 7F0AF4C8 02202025 */   move  $a0, $s1
/* 0E3FFC 7F0AF4CC 8E850000 */  lw    $a1, ($s4)
/* 0E4000 7F0AF4D0 0FC2CA5C */  jal   stanGetPositionYValue
/* 0E4004 7F0AF4D4 8E860008 */   lw    $a2, 8($s4)
/* 0E4008 7F0AF4D8 C6920004 */  lwc1  $f18, 4($s4)
/* 0E400C 7F0AF4DC 4600903C */  c.lt.s $f18, $f0
/* 0E4010 7F0AF4E0 00000000 */  nop
/* 0E4014 7F0AF4E4 45030008 */  bc1tl .L7F0AF508
/* 0E4018 7F0AF4E8 86220006 */   lh    $v0, 6($s1)
/* 0E401C 7F0AF4EC 4600C03C */  c.lt.s $f24, $f0
/* 0E4020 7F0AF4F0 00000000 */  nop
/* 0E4024 7F0AF4F4 45020004 */  bc1fl .L7F0AF508
/* 0E4028 7F0AF4F8 86220006 */   lh    $v0, 6($s1)
/* 0E402C 7F0AF4FC AFB1009C */  sw    $s1, 0x9c($sp)
/* 0E4030 7F0AF500 46000606 */  mov.s $f24, $f0
.L7F0AF504:
/* 0E4034 7F0AF504 86220006 */  lh    $v0, 6($s1)
.L7F0AF508:
/* 0E4038 7F0AF508 00024B03 */  sra   $t1, $v0, 0xc
/* 0E403C 7F0AF50C 312A000F */  andi  $t2, $t1, 0xf
/* 0E4040 7F0AF510 02EA5821 */  addu  $t3, $s7, $t2
/* 0E4044 7F0AF514 916C0000 */  lbu   $t4, ($t3)
/* 0E4048 7F0AF518 01918821 */  addu  $s1, $t4, $s1
/* 0E404C 7F0AF51C 8E2D0000 */  lw    $t5, ($s1)
/* 0E4050 7F0AF520 11A00004 */  beqz  $t5, .L7F0AF534
/* 0E4054 7F0AF524 00000000 */   nop
/* 0E4058 7F0AF528 922F0003 */  lbu   $t7, 3($s1)
/* 0E405C 7F0AF52C 52AFFFC1 */  beql  $s5, $t7, .L7F0AF434
/* 0E4060 7F0AF530 00008025 */   move  $s0, $zero
.L7F0AF534:
/* 0E4064 7F0AF534 3C068008 */  lui   $a2, %hi(dword_CODE_bss_8007B9DC)
/* 0E4068 7F0AF538 8CC6B9DC */  lw    $a2, %lo(dword_CODE_bss_8007B9DC)($a2)
/* 0E406C 7F0AF53C 24040004 */  li    $a0, 4
.L7F0AF540:
/* 0E4070 7F0AF540 8FAE0070 */  lw    $t6, 0x70($sp)
.L7F0AF544:
/* 0E4074 7F0AF544 26B50001 */  addiu $s5, $s5, 1
/* 0E4078 7F0AF548 02A6082A */  slt   $at, $s5, $a2
/* 0E407C 7F0AF54C 25D80004 */  addiu $t8, $t6, 4
/* 0E4080 7F0AF550 1420FF79 */  bnez  $at, .L7F0AF338
/* 0E4084 7F0AF554 AFB80070 */   sw    $t8, 0x70($sp)
/* 0E4088 7F0AF558 AFB20088 */  sw    $s2, 0x88($sp)
.L7F0AF55C:
/* 0E408C 7F0AF55C 8FB9009C */  lw    $t9, 0x9c($sp)
/* 0E4090 7F0AF560 8FA800D0 */  lw    $t0, 0xd0($sp)
/* 0E4094 7F0AF564 53200005 */  beql  $t9, $zero, .L7F0AF57C
/* 0E4098 7F0AF568 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0E409C 7F0AF56C 51000003 */  beql  $t0, $zero, .L7F0AF57C
/* 0E40A0 7F0AF570 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0E40A4 7F0AF574 E5180000 */  swc1  $f24, ($t0)
/* 0E40A8 7F0AF578 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F0AF57C:
/* 0E40AC 7F0AF57C 8FA2009C */  lw    $v0, 0x9c($sp)
/* 0E40B0 7F0AF580 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0E40B4 7F0AF584 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0E40B8 7F0AF588 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0E40BC 7F0AF58C 8FB00038 */  lw    $s0, 0x38($sp)
/* 0E40C0 7F0AF590 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0E40C4 7F0AF594 8FB20040 */  lw    $s2, 0x40($sp)
/* 0E40C8 7F0AF598 8FB30044 */  lw    $s3, 0x44($sp)
/* 0E40CC 7F0AF59C 8FB40048 */  lw    $s4, 0x48($sp)
/* 0E40D0 7F0AF5A0 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0E40D4 7F0AF5A4 8FB60050 */  lw    $s6, 0x50($sp)
/* 0E40D8 7F0AF5A8 8FB70054 */  lw    $s7, 0x54($sp)
/* 0E40DC 7F0AF5AC 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0E40E0 7F0AF5B0 03E00008 */  jr    $ra
/* 0E40E4 7F0AF5B4 27BD00C8 */   addiu $sp, $sp, 0xc8
)
#endif





#ifdef NONMATCHING
void stanLoadFile(StanPrefixRecord *arg0) {
    m_stanRegion = 1;
    stan_prefix.stanfile = arg0;
    standTileStart = (s32) (arg0->ptr_firstroom + -0x10);
    if (tokenFind(1, "-stanlinelog") != 0)
    {
        stanlinelog_flag = 1;
    }
    sub_GAME_7F0AF038();
    setLevelScale(1.0);
}

#else
GLOBAL_ASM(
.text
glabel stanLoadFile
/* 0E40E8 7F0AF5B8 3C028008 */  lui   $v0, %hi(stan_prefix)
/* 0E40EC 7F0AF5BC 240E0001 */  li    $t6, 1
/* 0E40F0 7F0AF5C0 3C018004 */  lui   $at, %hi(m_stanRegion)
/* 0E40F4 7F0AF5C4 2442B120 */  addiu $v0, %lo(stan_prefix) # addiu $v0, $v0, -0x4ee0
/* 0E40F8 7F0AF5C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E40FC 7F0AF5CC AC2E0FB0 */  sw    $t6, %lo(m_stanRegion)($at)
/* 0E4100 7F0AF5D0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E4104 7F0AF5D4 AC440000 */  sw    $a0, ($v0)
/* 0E4108 7F0AF5D8 8C980004 */  lw    $t8, 4($a0)
/* 0E410C 7F0AF5DC 3C018004 */  lui   $at, %hi(standTileStart)
/* 0E4110 7F0AF5E0 3C058006 */  lui   $a1, %hi(aStanlinelog)
/* 0E4114 7F0AF5E4 2719FF80 */  addiu $t9, $t8, -0x80
/* 0E4118 7F0AF5E8 AC390F58 */  sw    $t9, %lo(standTileStart)($at)
/* 0E411C 7F0AF5EC 24A585BC */  addiu $a1, %lo(aStanlinelog) # addiu $a1, $a1, -0x7a44
/* 0E4120 7F0AF5F0 0C0029A8 */  jal   tokenFind
/* 0E4124 7F0AF5F4 24040001 */   li    $a0, 1
/* 0E4128 7F0AF5F8 10400003 */  beqz  $v0, .L7F0AF608
/* 0E412C 7F0AF5FC 24080001 */   li    $t0, 1
/* 0E4130 7F0AF600 3C018004 */  lui   $at, %hi(stanlinelog_flag)
/* 0E4134 7F0AF604 AC280FB4 */  sw    $t0, %lo(stanlinelog_flag)($at)
.L7F0AF608:
/* 0E4138 7F0AF608 0FC2BC0E */  jal   sub_GAME_7F0AF038
/* 0E413C 7F0AF60C 00000000 */   nop
/* 0E4140 7F0AF610 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E4144 7F0AF614 44816000 */  mtc1  $at, $f12
/* 0E4148 7F0AF618 0FC2CA54 */  jal   setLevelScale
/* 0E414C 7F0AF61C 00000000 */   nop
/* 0E4150 7F0AF620 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E4154 7F0AF624 27BD0018 */  addiu $sp, $sp, 0x18
/* 0E4158 7F0AF628 03E00008 */  jr    $ra
/* 0E415C 7F0AF62C 00000000 */   nop
)
#endif





//stanRegion()
void sub_GAME_7F0AF630(s32 arg0)
{
#ifdef DEBUG

    if (arg0 < 0)
    {
        if (*(stanPrefix->ptr_firstroom)[m_stanRegion - 1])
        {
            m_stanRegion --;
        }
    }
    else if (arg0 < 1)
    {
        if (arg0 == 0)
        {
            m_stanRegion = 1;
        }
    }
    else if (*(stanPrefix->ptr_firstroom)[m_stanRegion + 1])
    {
        m_stanRegion ++;
    }
    osSyncPrintf("stanRegion():  region=%d",m_stanRegion);
#endif
    return;
}






#ifdef NONMATCHING
//stanFillin()
s32 sub_GAME_7F0AF638(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_s4;
    void *temp_s3;
    s32 temp_s1;
    void *temp_s2;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_s0;
    void *temp_v1;
    void *phi_s2;
    s32 phi_a1;
    void *phi_a0;
    void *phi_s2_2;
    s32 phi_s0;
    s32 phi_a1_2;
    s32 phi_s1;
    s32 phi_s7;
    void *phi_s2_3;
    s32 phi_a1_3;
    s32 phi_s1_2;
    s32 phi_s1_3;
    s32 phi_s7_2;
    s32 phi_s7_3;
    s32 phi_s1_4;

    // Node 0
    temp_s4 = (arg1 & 0xff);
    *arg2 = arg0;
    phi_s2 = (arg2 + 4);
    phi_a1 = arg1;
    phi_s1_3 = 1;
    phi_s7_3 = 0;
loop_1:
    // Node 1
    temp_s3 = phi_s2->unk-4;
    temp_s1 = (phi_s1_3 + -1);
    temp_s2 = (phi_s2 + -4);
    phi_s1 = temp_s1;
    phi_s7 = phi_s7_3;
    phi_s2 = temp_s2;
    phi_a1 = phi_a1;
    if (temp_s4 != (((s32) *temp_s3 >> 0xf) & 1))
    {
        // Node 2
        *temp_s3 = (s16) (*temp_s3 ^ 0x8000);
        phi_s7_2 = phi_s7_3;
        if (sub_GAME_7F0AF760(temp_s3, phi_a1) == 0)
        {
            // Node 3
            phi_s7_2 = (phi_s7_3 + 1);
        }
        // Node 4
        temp_a1 = (((s32) temp_s3->unk6 >> 0xc) & 0xf);
        phi_a0 = temp_s3;
        phi_s2_2 = temp_s2;
        phi_s0 = 0;
        phi_s1 = temp_s1;
        phi_s7 = phi_s7_2;
        phi_s2 = temp_s2;
        phi_a1 = temp_a1;
        phi_a1_3 = temp_a1;
        phi_s1_4 = temp_s1;
        if (temp_a1 > 0)
        {
loop_5:
            // Node 5
            temp_v0 = phi_a0->unkE;
            temp_s0 = (phi_s0 + 1);
            phi_a1_2 = phi_a1_3;
            phi_s2_3 = phi_s2_2;
            phi_s1_2 = phi_s1_4;
            if ((temp_v0 >> 4) != 0)
            {
                // Node 6
                temp_v1 = ((temp_v0 * 8) + standTileStart);
                phi_a1_2 = phi_a1_3;
                phi_s2_3 = phi_s2_2;
                phi_s1_2 = phi_s1_4;
                if (temp_s4 != (((s32) *temp_v1 >> 0xf) & 1))
                {
                    // Node 7
                    *phi_s2_2 = temp_v1;
                    phi_a1_2 = (((s32) temp_s3->unk6 >> 0xc) & 0xf);
                    phi_s2_3 = (phi_s2_2 + 4);
                    phi_s1_2 = (phi_s1_4 + 1);
                }
            }
            // Node 8
            phi_a0 = (phi_a0 + 8);
            phi_s2_2 = phi_s2_3;
            phi_s0 = temp_s0;
            phi_s1 = phi_s1_2;
            phi_s7 = phi_s7_2;
            phi_s2 = phi_s2_3;
            phi_a1 = phi_a1_2;
            phi_a1_3 = phi_a1_2;
            phi_s1_4 = phi_s1_2;
            if (temp_s0 < phi_a1_2)
            {
                goto loop_5;
            }
        }
    }
    // Node 9
    phi_s1_3 = phi_s1;
    phi_s7_3 = phi_s7;
    if (phi_s1 != 0)
    {
        goto loop_1;
    }
    // Node 10
    return phi_s7;

    /*somewhere in this function a loop is checked for overflow
    if (uStack < local_20)
    {
        printf("stanFillin: Stack overflow %d>%d",local_20,uStack);
    }
    */
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AF638
/* 0E4168 7F0AF638 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0E416C 7F0AF63C AFB70030 */  sw    $s7, 0x30($sp)
/* 0E4170 7F0AF640 AFB6002C */  sw    $s6, 0x2c($sp)
/* 0E4174 7F0AF644 AFB40024 */  sw    $s4, 0x24($sp)
/* 0E4178 7F0AF648 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0E417C 7F0AF64C AFB10018 */  sw    $s1, 0x18($sp)
/* 0E4180 7F0AF650 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0E4184 7F0AF654 AFB50028 */  sw    $s5, 0x28($sp)
/* 0E4188 7F0AF658 AFB30020 */  sw    $s3, 0x20($sp)
/* 0E418C 7F0AF65C AFB00014 */  sw    $s0, 0x14($sp)
/* 0E4190 7F0AF660 AFA5003C */  sw    $a1, 0x3c($sp)
/* 0E4194 7F0AF664 3C168004 */  lui   $s6, %hi(standTileStart)
/* 0E4198 7F0AF668 30B400FF */  andi  $s4, $a1, 0xff
/* 0E419C 7F0AF66C 0000B825 */  move  $s7, $zero
/* 0E41A0 7F0AF670 ACC40000 */  sw    $a0, ($a2)
/* 0E41A4 7F0AF674 24110001 */  li    $s1, 1
/* 0E41A8 7F0AF678 26D60F58 */  addiu $s6, %lo(standTileStart) # addiu $s6, $s6, 0xf58
/* 0E41AC 7F0AF67C 24D20004 */  addiu $s2, $a2, 4
/* 0E41B0 7F0AF680 8E53FFFC */  lw    $s3, -4($s2)
.L7F0AF684:
/* 0E41B4 7F0AF684 2631FFFF */  addiu $s1, $s1, -1
/* 0E41B8 7F0AF688 2652FFFC */  addiu $s2, $s2, -4
/* 0E41BC 7F0AF68C 96620000 */  lhu   $v0, ($s3)
/* 0E41C0 7F0AF690 00008025 */  move  $s0, $zero
/* 0E41C4 7F0AF694 02602025 */  move  $a0, $s3
/* 0E41C8 7F0AF698 00027BC3 */  sra   $t7, $v0, 0xf
/* 0E41CC 7F0AF69C 31F80001 */  andi  $t8, $t7, 1
/* 0E41D0 7F0AF6A0 12980021 */  beq   $s4, $t8, .L7F0AF728
/* 0E41D4 7F0AF6A4 38598000 */   xori  $t9, $v0, 0x8000
/* 0E41D8 7F0AF6A8 0FC2BDD8 */  jal   sub_GAME_7F0AF760
/* 0E41DC 7F0AF6AC A6790000 */   sh    $t9, ($s3)
/* 0E41E0 7F0AF6B0 14400002 */  bnez  $v0, .L7F0AF6BC
/* 0E41E4 7F0AF6B4 02602025 */   move  $a0, $s3
/* 0E41E8 7F0AF6B8 26F70001 */  addiu $s7, $s7, 1
.L7F0AF6BC:
/* 0E41EC 7F0AF6BC 86650006 */  lh    $a1, 6($s3)
/* 0E41F0 7F0AF6C0 00054303 */  sra   $t0, $a1, 0xc
/* 0E41F4 7F0AF6C4 3105000F */  andi  $a1, $t0, 0xf
/* 0E41F8 7F0AF6C8 18A00017 */  blez  $a1, .L7F0AF728
/* 0E41FC 7F0AF6CC 00000000 */   nop
.L7F0AF6D0:
/* 0E4200 7F0AF6D0 9482000E */  lhu   $v0, 0xe($a0)
/* 0E4204 7F0AF6D4 26100001 */  addiu $s0, $s0, 1
/* 0E4208 7F0AF6D8 00025103 */  sra   $t2, $v0, 4
/* 0E420C 7F0AF6DC 51400010 */  beql  $t2, $zero, .L7F0AF720
/* 0E4210 7F0AF6E0 0205082A */   slt   $at, $s0, $a1
/* 0E4214 7F0AF6E4 8ECC0000 */  lw    $t4, ($s6)
/* 0E4218 7F0AF6E8 000258C0 */  sll   $t3, $v0, 3
/* 0E421C 7F0AF6EC 016C1821 */  addu  $v1, $t3, $t4
/* 0E4220 7F0AF6F0 946D0000 */  lhu   $t5, ($v1)
/* 0E4224 7F0AF6F4 000D73C3 */  sra   $t6, $t5, 0xf
/* 0E4228 7F0AF6F8 31CF0001 */  andi  $t7, $t6, 1
/* 0E422C 7F0AF6FC 528F0008 */  beql  $s4, $t7, .L7F0AF720
/* 0E4230 7F0AF700 0205082A */   slt   $at, $s0, $a1
/* 0E4234 7F0AF704 AE430000 */  sw    $v1, ($s2)
/* 0E4238 7F0AF708 86650006 */  lh    $a1, 6($s3)
/* 0E423C 7F0AF70C 26310001 */  addiu $s1, $s1, 1
/* 0E4240 7F0AF710 26520004 */  addiu $s2, $s2, 4
/* 0E4244 7F0AF714 0005C303 */  sra   $t8, $a1, 0xc
/* 0E4248 7F0AF718 3305000F */  andi  $a1, $t8, 0xf
/* 0E424C 7F0AF71C 0205082A */  slt   $at, $s0, $a1
.L7F0AF720:
/* 0E4250 7F0AF720 1420FFEB */  bnez  $at, .L7F0AF6D0
/* 0E4254 7F0AF724 24840008 */   addiu $a0, $a0, 8
.L7F0AF728:
/* 0E4258 7F0AF728 5620FFD6 */  bnezl $s1, .L7F0AF684
/* 0E425C 7F0AF72C 8E53FFFC */   lw    $s3, -4($s2)
/* 0E4260 7F0AF730 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0E4264 7F0AF734 02E01025 */  move  $v0, $s7
/* 0E4268 7F0AF738 8FB70030 */  lw    $s7, 0x30($sp)
/* 0E426C 7F0AF73C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0E4270 7F0AF740 8FB10018 */  lw    $s1, 0x18($sp)
/* 0E4274 7F0AF744 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0E4278 7F0AF748 8FB30020 */  lw    $s3, 0x20($sp)
/* 0E427C 7F0AF74C 8FB40024 */  lw    $s4, 0x24($sp)
/* 0E4280 7F0AF750 8FB50028 */  lw    $s5, 0x28($sp)
/* 0E4284 7F0AF754 8FB6002C */  lw    $s6, 0x2c($sp)
/* 0E4288 7F0AF758 03E00008 */  jr    $ra
/* 0E428C 7F0AF75C 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING

// A decent start, mostly my code isn't saving the AB.x and AB.z to the stack

struct int3 {
    s32 x;
    s32 y;
    s32 z;
};

s32 sub_GAME_7F0AF760(StandTile *tile) {
    // Perhaps it's a coincidence but there is a gap between their uses of x and z
    // Suggests there could be an unused y, which makes sense when their points are 3D

    u32 iA;
    u32 iB;
    u32 iC;

    s32 crossProduct;

    struct int3 AB;
    struct int3 AC;


    iA = (tile->hdrTail >> 0x8 & 0xf);     // t1
    iB = (tile->hdrTail >> 0x4 & 0xf);    // t0
    // Actually saving iC somewhere has prevented it being computed early
    iC = (tile->hdrTail & 0xf);     // t2

    AB.x = (tile->points[iB].x - tile->points[iA].x);
    AB.y = 0;
    AB.z = (tile->points[iB].z - tile->points[iA].z);


    AC.x = (tile->points[iC].x - tile->points[iA].x);
    AC.y = 0;
    AC.z = (tile->points[iC].z - tile->points[iA].z);

    crossProduct =  ((AB.z * AC.x) - (AB.x * AC.z));    // potential overflow.

    return (crossProduct == 0);
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AF760
/* 0E4290 7F0AF760 84850006 */  lh    $a1, 6($a0)
/* 0E4294 7F0AF764 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E4298 7F0AF768 00051A03 */  sra   $v1, $a1, 8
/* 0E429C 7F0AF76C 00053103 */  sra   $a2, $a1, 4
/* 0E42A0 7F0AF770 306E000F */  andi  $t6, $v1, 0xf
/* 0E42A4 7F0AF774 30CF000F */  andi  $t7, $a2, 0xf
/* 0E42A8 7F0AF778 000FC0C0 */  sll   $t8, $t7, 3
/* 0E42AC 7F0AF77C 000EC8C0 */  sll   $t9, $t6, 3
/* 0E42B0 7F0AF780 00994821 */  addu  $t1, $a0, $t9
/* 0E42B4 7F0AF784 00984021 */  addu  $t0, $a0, $t8
/* 0E42B8 7F0AF788 850B0008 */  lh    $t3, 8($t0)
/* 0E42BC 7F0AF78C 852C0008 */  lh    $t4, 8($t1)
/* 0E42C0 7F0AF790 30A7000F */  andi  $a3, $a1, 0xf
/* 0E42C4 7F0AF794 0007C8C0 */  sll   $t9, $a3, 3
/* 0E42C8 7F0AF798 016C6823 */  subu  $t5, $t3, $t4
/* 0E42CC 7F0AF79C AFAD0014 */  sw    $t5, 0x14($sp)
/* 0E42D0 7F0AF7A0 852F000C */  lh    $t7, 0xc($t1)
/* 0E42D4 7F0AF7A4 850E000C */  lh    $t6, 0xc($t0)
/* 0E42D8 7F0AF7A8 00995021 */  addu  $t2, $a0, $t9
/* 0E42DC 7F0AF7AC 01CFC023 */  subu  $t8, $t6, $t7
/* 0E42E0 7F0AF7B0 AFB8001C */  sw    $t8, 0x1c($sp)
/* 0E42E4 7F0AF7B4 852C0008 */  lh    $t4, 8($t1)
/* 0E42E8 7F0AF7B8 854B0008 */  lh    $t3, 8($t2)
/* 0E42EC 7F0AF7BC 8FB9001C */  lw    $t9, 0x1c($sp)
/* 0E42F0 7F0AF7C0 016C6823 */  subu  $t5, $t3, $t4
/* 0E42F4 7F0AF7C4 032D0019 */  multu $t9, $t5
/* 0E42F8 7F0AF7C8 AFAD0008 */  sw    $t5, 8($sp)
/* 0E42FC 7F0AF7CC 852F000C */  lh    $t7, 0xc($t1)
/* 0E4300 7F0AF7D0 854E000C */  lh    $t6, 0xc($t2)
/* 0E4304 7F0AF7D4 01CFC023 */  subu  $t8, $t6, $t7
/* 0E4308 7F0AF7D8 8FAE0014 */  lw    $t6, 0x14($sp)
/* 0E430C 7F0AF7DC AFB80010 */  sw    $t8, 0x10($sp)
/* 0E4310 7F0AF7E0 00006012 */  mflo  $t4
/* 0E4314 7F0AF7E4 00000000 */  nop
/* 0E4318 7F0AF7E8 00000000 */  nop
/* 0E431C 7F0AF7EC 030E0019 */  multu $t8, $t6
/* 0E4320 7F0AF7F0 00007812 */  mflo  $t7
/* 0E4324 7F0AF7F4 018FC023 */  subu  $t8, $t4, $t7
/* 0E4328 7F0AF7F8 AFB80000 */  sw    $t8, ($sp)
/* 0E432C 7F0AF7FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0E4330 7F0AF800 03E00008 */  jr    $ra
/* 0E4334 7F0AF804 2F020001 */   sltiu $v0, $t8, 1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0AF808(void) {

// Still quite a long way off.
StandTile *sub_GAME_7F0AF808(f32 f1,f32 f2,f32 f3,f32 f4)
{
    // 'findSomeTile' atm
    // It seems a silly thing to be doing during runtime.

    StandTile *tile;
    StandTile *tileStack[2];

    tile = stan_prefix.ptr_firstroom;

    // this test may be reading a field but it could well look like this,
    //   since 0 signals that there is no more data, so 'tile' isn't really a StandTile
*
    while (*(u32*)tile != 0)
    {
        tileStack[0] = tile;

        if (
            (!sub_GAME_7F0AF760(tile)) &&
            (isPointInsideTriStandTileUnscaled_Maybe(tile,f1,f3) != 0) &&
            (FUN_7f0b20d0(tileStack,f1,f3,f4) != 0) &&
            (tile == tileStack[0]) &&
            (getCrossProductY_and_distToPlaneMaybe(tile,f1,f3) < f2)
        )
        {
            return tile;
        }

        tile = (struct StandTile*) (
            ((s32)tile) + list_of_tilesizes[STAN_POINT_COUNT(tile)]
        );

    }

    return (struct StandTile*)0x0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AF808
/* 0E4338 7F0AF808 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0E433C 7F0AF80C 3C0E8008 */  lui   $t6, %hi(stan_prefix)
/* 0E4340 7F0AF810 8DCEB120 */  lw    $t6, %lo(stan_prefix)($t6)
/* 0E4344 7F0AF814 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0E4348 7F0AF818 AFB20040 */  sw    $s2, 0x40($sp)
/* 0E434C 7F0AF81C AFB1003C */  sw    $s1, 0x3c($sp)
/* 0E4350 7F0AF820 AFB00038 */  sw    $s0, 0x38($sp)
/* 0E4354 7F0AF824 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0E4358 7F0AF828 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0E435C 7F0AF82C F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0E4360 7F0AF830 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0E4364 7F0AF834 8DD00004 */  lw    $s0, 4($t6)
/* 0E4368 7F0AF838 4486B000 */  mtc1  $a2, $f22
/* 0E436C 7F0AF83C 4487C000 */  mtc1  $a3, $f24
/* 0E4370 7F0AF840 8E0F0000 */  lw    $t7, ($s0)
/* 0E4374 7F0AF844 46006506 */  mov.s $f20, $f12
/* 0E4378 7F0AF848 46007686 */  mov.s $f26, $f14
/* 0E437C 7F0AF84C 11E0002A */  beqz  $t7, .L7F0AF8F8
/* 0E4380 7F0AF850 3C128004 */   lui   $s2, %hi(list_of_tilesizes)
/* 0E4384 7F0AF854 26520F4C */  addiu $s2, %lo(list_of_tilesizes) # addiu $s2, $s2, 0xf4c
/* 0E4388 7F0AF858 27B10050 */  addiu $s1, $sp, 0x50
/* 0E438C 7F0AF85C AFB00050 */  sw    $s0, 0x50($sp)
.L7F0AF860:
/* 0E4390 7F0AF860 0FC2BDD8 */  jal   sub_GAME_7F0AF760
/* 0E4394 7F0AF864 02002025 */   move  $a0, $s0
/* 0E4398 7F0AF868 5440001B */  bnezl $v0, .L7F0AF8D8
/* 0E439C 7F0AF86C 86020006 */   lh    $v0, 6($s0)
/* 0E43A0 7F0AF870 4405A000 */  mfc1  $a1, $f20
/* 0E43A4 7F0AF874 4406B000 */  mfc1  $a2, $f22
/* 0E43A8 7F0AF878 0FC2C0DB */  jal   isPointInsideTriStandTileUnscaled_Maybe
/* 0E43AC 7F0AF87C 02002025 */   move  $a0, $s0
/* 0E43B0 7F0AF880 50400015 */  beql  $v0, $zero, .L7F0AF8D8
/* 0E43B4 7F0AF884 86020006 */   lh    $v0, 6($s0)
/* 0E43B8 7F0AF888 4405A000 */  mfc1  $a1, $f20
/* 0E43BC 7F0AF88C 4406B000 */  mfc1  $a2, $f22
/* 0E43C0 7F0AF890 4407C000 */  mfc1  $a3, $f24
/* 0E43C4 7F0AF894 0FC2C834 */  jal   sub_GAME_7F0B20D0
/* 0E43C8 7F0AF898 02202025 */   move  $a0, $s1
/* 0E43CC 7F0AF89C 1040000D */  beqz  $v0, .L7F0AF8D4
/* 0E43D0 7F0AF8A0 8FB80050 */   lw    $t8, 0x50($sp)
/* 0E43D4 7F0AF8A4 5618000C */  bnel  $s0, $t8, .L7F0AF8D8
/* 0E43D8 7F0AF8A8 86020006 */   lh    $v0, 6($s0)
/* 0E43DC 7F0AF8AC 4405A000 */  mfc1  $a1, $f20
/* 0E43E0 7F0AF8B0 4406B000 */  mfc1  $a2, $f22
/* 0E43E4 7F0AF8B4 0FC2CA5C */  jal   stanGetPositionYValue
/* 0E43E8 7F0AF8B8 02002025 */   move  $a0, $s0
/* 0E43EC 7F0AF8BC 461A003C */  c.lt.s $f0, $f26
/* 0E43F0 7F0AF8C0 00000000 */  nop
/* 0E43F4 7F0AF8C4 45020004 */  bc1fl .L7F0AF8D8
/* 0E43F8 7F0AF8C8 86020006 */   lh    $v0, 6($s0)
/* 0E43FC 7F0AF8CC 1000000B */  b     .L7F0AF8FC
/* 0E4400 7F0AF8D0 02001025 */   move  $v0, $s0
.L7F0AF8D4:
/* 0E4404 7F0AF8D4 86020006 */  lh    $v0, 6($s0)
.L7F0AF8D8:
/* 0E4408 7F0AF8D8 0002CB03 */  sra   $t9, $v0, 0xc
/* 0E440C 7F0AF8DC 3328000F */  andi  $t0, $t9, 0xf
/* 0E4410 7F0AF8E0 02484821 */  addu  $t1, $s2, $t0
/* 0E4414 7F0AF8E4 912A0000 */  lbu   $t2, ($t1)
/* 0E4418 7F0AF8E8 01508021 */  addu  $s0, $t2, $s0
/* 0E441C 7F0AF8EC 8E0B0000 */  lw    $t3, ($s0)
/* 0E4420 7F0AF8F0 5560FFDB */  bnezl $t3, .L7F0AF860
/* 0E4424 7F0AF8F4 AFB00050 */   sw    $s0, 0x50($sp)
.L7F0AF8F8:
/* 0E4428 7F0AF8F8 00001025 */  move  $v0, $zero
.L7F0AF8FC:
/* 0E442C 7F0AF8FC 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0E4430 7F0AF900 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0E4434 7F0AF904 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0E4438 7F0AF908 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0E443C 7F0AF90C D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0E4440 7F0AF910 8FB00038 */  lw    $s0, 0x38($sp)
/* 0E4444 7F0AF914 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0E4448 7F0AF918 8FB20040 */  lw    $s2, 0x40($sp)
/* 0E444C 7F0AF91C 03E00008 */  jr    $ra
/* 0E4450 7F0AF920 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif





#ifdef NONMATCHING
// 2 instructions swapped, regalloc.
// I've tried all orderings of the A,B,C assignments, both as indices and as pointers to StandTilePoints
// Summing the x,y,z components first just makes more regalloc issues
// Placing the macros directly in the indexing doesn't help either.
// Making midPnt a f32* did nothing.

// I'm out of ideas.
void getTileMidPoint(StandTile *tile, coord3d *midPnt)
{
    short headerTail;
    // may be RGB
    s32 indexA;
    s32 indexB;
    s32 indexC;

    indexA = STAN_TRIPLE_TO_PNT_INDEX(tile, 0);
    indexB = STAN_TRIPLE_TO_PNT_INDEX(tile, 1);
    indexC = STAN_TRIPLE_TO_PNT_INDEX(tile, 2);

    midPnt->x = ((f32)tile->points[indexA].x + tile->points[indexB].x + tile->points[indexC].x) / 3 * inv_level_scale;
    midPnt->y = ((f32)tile->points[indexA].y + tile->points[indexB].y + tile->points[indexC].y) / 3 * inv_level_scale;
    midPnt->z = ((f32)tile->points[indexA].z + tile->points[indexB].z + tile->points[indexC].z) / 3 * inv_level_scale;

    return;
}

#else
GLOBAL_ASM(
.text
glabel getTileMidPoint
/* 0E4454 7F0AF924 84870006 */  lh    $a3, 6($a0)
/* 0E4458 7F0AF928 3C014040 */  li    $at, 0x40400000 # 3.000000
/* 0E445C 7F0AF92C 44810000 */  mtc1  $at, $f0
/* 0E4460 7F0AF930 00077203 */  sra   $t6, $a3, 8
/* 0E4464 7F0AF934 31CF000F */  andi  $t7, $t6, 0xf
/* 0E4468 7F0AF938 0007C103 */  sra   $t8, $a3, 4
/* 0E446C 7F0AF93C 3319000F */  andi  $t9, $t8, 0xf
/* 0E4470 7F0AF940 000F70C0 */  sll   $t6, $t7, 3
/* 0E4474 7F0AF944 001978C0 */  sll   $t7, $t9, 3
/* 0E4478 7F0AF948 008F5021 */  addu  $t2, $a0, $t7
/* 0E447C 7F0AF94C 008E4821 */  addu  $t1, $a0, $t6
/* 0E4480 7F0AF950 85380008 */  lh    $t8, 8($t1)
/* 0E4484 7F0AF954 85590008 */  lh    $t9, 8($t2)
/* 0E4488 7F0AF958 30EC000F */  andi  $t4, $a3, 0xf
/* 0E448C 7F0AF95C 000C68C0 */  sll   $t5, $t4, 3
/* 0E4490 7F0AF960 44982000 */  mtc1  $t8, $f4
/* 0E4494 7F0AF964 44994000 */  mtc1  $t9, $f8
/* 0E4498 7F0AF968 008D4021 */  addu  $t0, $a0, $t5
/* 0E449C 7F0AF96C 850C0008 */  lh    $t4, 8($t0)
/* 0E44A0 7F0AF970 468021A0 */  cvt.s.w $f6, $f4
/* 0E44A4 7F0AF974 3C0B8004 */  lui   $t3, %hi(inv_level_scale)
/* 0E44A8 7F0AF978 448C9000 */  mtc1  $t4, $f18
/* 0E44AC 7F0AF97C 256B0F48 */  addiu $t3, %lo(inv_level_scale) # addiu $t3, $t3, 0xf48
/* 0E44B0 7F0AF980 468042A0 */  cvt.s.w $f10, $f8
/* 0E44B4 7F0AF984 46809120 */  cvt.s.w $f4, $f18
/* 0E44B8 7F0AF988 460A3400 */  add.s $f16, $f6, $f10
/* 0E44BC 7F0AF98C C56A0000 */  lwc1  $f10, ($t3)
/* 0E44C0 7F0AF990 46102200 */  add.s $f8, $f4, $f16
/* 0E44C4 7F0AF994 46004183 */  div.s $f6, $f8, $f0
/* 0E44C8 7F0AF998 460A3482 */  mul.s $f18, $f6, $f10
/* 0E44CC 7F0AF99C E4B20000 */  swc1  $f18, ($a1)
/* 0E44D0 7F0AF9A0 854E000A */  lh    $t6, 0xa($t2)
/* 0E44D4 7F0AF9A4 852D000A */  lh    $t5, 0xa($t1)
/* 0E44D8 7F0AF9A8 850F000A */  lh    $t7, 0xa($t0)
/* 0E44DC 7F0AF9AC 448E4000 */  mtc1  $t6, $f8
/* 0E44E0 7F0AF9B0 448D2000 */  mtc1  $t5, $f4
/* 0E44E4 7F0AF9B4 448F9000 */  mtc1  $t7, $f18
/* 0E44E8 7F0AF9B8 468041A0 */  cvt.s.w $f6, $f8
/* 0E44EC 7F0AF9BC 46802420 */  cvt.s.w $f16, $f4
/* 0E44F0 7F0AF9C0 46809120 */  cvt.s.w $f4, $f18
/* 0E44F4 7F0AF9C4 46068280 */  add.s $f10, $f16, $f6
/* 0E44F8 7F0AF9C8 C5660000 */  lwc1  $f6, ($t3)
/* 0E44FC 7F0AF9CC 460A2200 */  add.s $f8, $f4, $f10
/* 0E4500 7F0AF9D0 46004403 */  div.s $f16, $f8, $f0
/* 0E4504 7F0AF9D4 46068482 */  mul.s $f18, $f16, $f6
/* 0E4508 7F0AF9D8 E4B20004 */  swc1  $f18, 4($a1)
/* 0E450C 7F0AF9DC 8559000C */  lh    $t9, 0xc($t2)
/* 0E4510 7F0AF9E0 8538000C */  lh    $t8, 0xc($t1)
/* 0E4514 7F0AF9E4 850C000C */  lh    $t4, 0xc($t0)
/* 0E4518 7F0AF9E8 44994000 */  mtc1  $t9, $f8
/* 0E451C 7F0AF9EC 44982000 */  mtc1  $t8, $f4
/* 0E4520 7F0AF9F0 448C9000 */  mtc1  $t4, $f18
/* 0E4524 7F0AF9F4 46804420 */  cvt.s.w $f16, $f8
/* 0E4528 7F0AF9F8 468022A0 */  cvt.s.w $f10, $f4
/* 0E452C 7F0AF9FC 46809120 */  cvt.s.w $f4, $f18
/* 0E4530 7F0AFA00 46105180 */  add.s $f6, $f10, $f16
/* 0E4534 7F0AFA04 C5700000 */  lwc1  $f16, ($t3)
/* 0E4538 7F0AFA08 46062200 */  add.s $f8, $f4, $f6
/* 0E453C 7F0AFA0C 46004283 */  div.s $f10, $f8, $f0
/* 0E4540 7F0AFA10 46105482 */  mul.s $f18, $f10, $f16
/* 0E4544 7F0AFA14 03E00008 */  jr    $ra
/* 0E4548 7F0AFA18 E4B20008 */   swc1  $f18, 8($a1)
)
#endif





#ifdef NONMATCHING
// Saves a1 (tripleIndex) to the stack completely unnecessarily
// Otherwise just regalloc, but maybe that alone fixes it.
void getPointJustInsideOfTileTriple(StandTile *tile, s32 tripleIndex /*canonically c */, coord3d* pnt)
{
    coord3d midPoint;
    s32 pntIndex;

    #ifdef DEBUG
    assert(c<3);
    #endif

    pntIndex = STAN_TRIPLE_TO_PNT_INDEX(tile, tripleIndex);

    pnt->x = tile->points[pntIndex].x * inv_level_scale;
    pnt->y = tile->points[pntIndex].y * inv_level_scale;
    pnt->z = tile->points[pntIndex].z * inv_level_scale;

    getTileMidPoint(tile,&midPoint);

    // 10% of the way from the actual tile point towards the tile's centre.
    pnt->x = midPoint.x * 0.1f + pnt->x * 0.9f;
    pnt->y = midPoint.y * 0.1f + pnt->y * 0.9f;
    pnt->z = midPoint.z * 0.1f + pnt->z * 0.9f;

    return;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800585D8
.word 0x3dcccccd /*0.1*/
glabel D_800585DC
.word 0x3f666666 /*0.89999998*/
.text
glabel getPointJustInsideOfTileTriple
/* 0E454C 7F0AFA1C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E4550 7F0AFA20 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E4554 7F0AFA24 848E0006 */  lh    $t6, 6($a0)
/* 0E4558 7F0AFA28 00057880 */  sll   $t7, $a1, 2
/* 0E455C 7F0AFA2C 24180008 */  li    $t8, 8
/* 0E4560 7F0AFA30 030FC823 */  subu  $t9, $t8, $t7
/* 0E4564 7F0AFA34 032E3807 */  srav  $a3, $t6, $t9
/* 0E4568 7F0AFA38 30E8000F */  andi  $t0, $a3, 0xf
/* 0E456C 7F0AFA3C 000848C0 */  sll   $t1, $t0, 3
/* 0E4570 7F0AFA40 00891021 */  addu  $v0, $a0, $t1
/* 0E4574 7F0AFA44 844A0008 */  lh    $t2, 8($v0)
/* 0E4578 7F0AFA48 3C038004 */  lui   $v1, %hi(inv_level_scale)
/* 0E457C 7F0AFA4C 24630F48 */  addiu $v1, %lo(inv_level_scale) # addiu $v1, $v1, 0xf48
/* 0E4580 7F0AFA50 448A2000 */  mtc1  $t2, $f4
/* 0E4584 7F0AFA54 C4680000 */  lwc1  $f8, ($v1)
/* 0E4588 7F0AFA58 27A5001C */  addiu $a1, $sp, 0x1c
/* 0E458C 7F0AFA5C 468021A0 */  cvt.s.w $f6, $f4
/* 0E4590 7F0AFA60 46083282 */  mul.s $f10, $f6, $f8
/* 0E4594 7F0AFA64 E4CA0000 */  swc1  $f10, ($a2)
/* 0E4598 7F0AFA68 844B000A */  lh    $t3, 0xa($v0)
/* 0E459C 7F0AFA6C C4640000 */  lwc1  $f4, ($v1)
/* 0E45A0 7F0AFA70 448B8000 */  mtc1  $t3, $f16
/* 0E45A4 7F0AFA74 00000000 */  nop
/* 0E45A8 7F0AFA78 468084A0 */  cvt.s.w $f18, $f16
/* 0E45AC 7F0AFA7C 46049182 */  mul.s $f6, $f18, $f4
/* 0E45B0 7F0AFA80 E4C60004 */  swc1  $f6, 4($a2)
/* 0E45B4 7F0AFA84 844C000C */  lh    $t4, 0xc($v0)
/* 0E45B8 7F0AFA88 C4700000 */  lwc1  $f16, ($v1)
/* 0E45BC 7F0AFA8C 448C4000 */  mtc1  $t4, $f8
/* 0E45C0 7F0AFA90 00000000 */  nop
/* 0E45C4 7F0AFA94 468042A0 */  cvt.s.w $f10, $f8
/* 0E45C8 7F0AFA98 46105482 */  mul.s $f18, $f10, $f16
/* 0E45CC 7F0AFA9C E4D20008 */  swc1  $f18, 8($a2)
/* 0E45D0 7F0AFAA0 0FC2BE49 */  jal   getTileMidPoint
/* 0E45D4 7F0AFAA4 AFA60030 */   sw    $a2, 0x30($sp)
/* 0E45D8 7F0AFAA8 3C018006 */  lui   $at, %hi(D_800585D8)
/* 0E45DC 7F0AFAAC C42085D8 */  lwc1  $f0, %lo(D_800585D8)($at)
/* 0E45E0 7F0AFAB0 8FA60030 */  lw    $a2, 0x30($sp)
/* 0E45E4 7F0AFAB4 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0E45E8 7F0AFAB8 3C018006 */  lui   $at, %hi(D_800585DC)
/* 0E45EC 7F0AFABC C42285DC */  lwc1  $f2, %lo(D_800585DC)($at)
/* 0E45F0 7F0AFAC0 46002182 */  mul.s $f6, $f4, $f0
/* 0E45F4 7F0AFAC4 C4C80000 */  lwc1  $f8, ($a2)
/* 0E45F8 7F0AFAC8 46081282 */  mul.s $f10, $f2, $f8
/* 0E45FC 7F0AFACC C4C80004 */  lwc1  $f8, 4($a2)
/* 0E4600 7F0AFAD0 460A3400 */  add.s $f16, $f6, $f10
/* 0E4604 7F0AFAD4 E4D00000 */  swc1  $f16, ($a2)
/* 0E4608 7F0AFAD8 C7B20020 */  lwc1  $f18, 0x20($sp)
/* 0E460C 7F0AFADC 46009102 */  mul.s $f4, $f18, $f0
/* 0E4610 7F0AFAE0 00000000 */  nop
/* 0E4614 7F0AFAE4 46081182 */  mul.s $f6, $f2, $f8
/* 0E4618 7F0AFAE8 C4C80008 */  lwc1  $f8, 8($a2)
/* 0E461C 7F0AFAEC 46062280 */  add.s $f10, $f4, $f6
/* 0E4620 7F0AFAF0 E4CA0004 */  swc1  $f10, 4($a2)
/* 0E4624 7F0AFAF4 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0E4628 7F0AFAF8 46008482 */  mul.s $f18, $f16, $f0
/* 0E462C 7F0AFAFC 00000000 */  nop
/* 0E4630 7F0AFB00 46081102 */  mul.s $f4, $f2, $f8
/* 0E4634 7F0AFB04 46049180 */  add.s $f6, $f18, $f4
/* 0E4638 7F0AFB08 E4C60008 */  swc1  $f6, 8($a2)
/* 0E463C 7F0AFB0C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E4640 7F0AFB10 27BD0028 */  addiu $sp, $sp, 0x28
/* 0E4644 7F0AFB14 03E00008 */  jr    $ra
/* 0E4648 7F0AFB18 00000000 */   nop
)
#endif





/*
* Address: 0x7F0AFB1C
 */
f32 sub_GAME_7F0AFB1C(coord3d *p,coord3d *q)
{
    // Should be a coord3d or vec3d, but they used an array which
    // causes lots of data reads and writes to the stack.
    f32 components[3];

    components[0] = q->x - p->x;
    components[1] = q->y - p->y;
    components[2] = q->z - p->z;

    return components[0]*components[0] + components[1]*components[1] + components[2]*components[2];
}






#ifdef NONMATCHING
void sub_GAME_7F0AFB78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0AFB78
/* 0E46A8 7F0AFB78 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0E46AC 7F0AFB7C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0E46B0 7F0AFB80 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0E46B4 7F0AFB84 AFB70044 */  sw    $s7, 0x44($sp)
/* 0E46B8 7F0AFB88 AFB60040 */  sw    $s6, 0x40($sp)
/* 0E46BC 7F0AFB8C AFB5003C */  sw    $s5, 0x3c($sp)
/* 0E46C0 7F0AFB90 AFB40038 */  sw    $s4, 0x38($sp)
/* 0E46C4 7F0AFB94 AFB30034 */  sw    $s3, 0x34($sp)
/* 0E46C8 7F0AFB98 AFB20030 */  sw    $s2, 0x30($sp)
/* 0E46CC 7F0AFB9C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0E46D0 7F0AFBA0 AFB00028 */  sw    $s0, 0x28($sp)
/* 0E46D4 7F0AFBA4 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0E46D8 7F0AFBA8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0E46DC 7F0AFBAC AFA00078 */  sw    $zero, 0x78($sp)
/* 0E46E0 7F0AFBB0 C4840000 */  lwc1  $f4, ($a0)
/* 0E46E4 7F0AFBB4 3C0E8008 */  lui   $t6, %hi(stan_prefix)
/* 0E46E8 7F0AFBB8 8DCEB120 */  lw    $t6, %lo(stan_prefix)($t6)
/* 0E46EC 7F0AFBBC E7A40064 */  swc1  $f4, 0x64($sp)
/* 0E46F0 7F0AFBC0 C4A60000 */  lwc1  $f6, ($a1)
/* 0E46F4 7F0AFBC4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0E46F8 7F0AFBC8 4487B000 */  mtc1  $a3, $f22
/* 0E46FC 7F0AFBCC E7A60068 */  swc1  $f6, 0x68($sp)
/* 0E4700 7F0AFBD0 C4C80000 */  lwc1  $f8, ($a2)
/* 0E4704 7F0AFBD4 4481A000 */  mtc1  $at, $f20
/* 0E4708 7F0AFBD8 00809825 */  move  $s3, $a0
/* 0E470C 7F0AFBDC E7A8006C */  swc1  $f8, 0x6c($sp)
/* 0E4710 7F0AFBE0 8DD10004 */  lw    $s1, 4($t6)
/* 0E4714 7F0AFBE4 00A0A025 */  move  $s4, $a1
/* 0E4718 7F0AFBE8 00C0A825 */  move  $s5, $a2
/* 0E471C 7F0AFBEC 8E2F0000 */  lw    $t7, ($s1)
/* 0E4720 7F0AFBF0 24160003 */  li    $s6, 3
/* 0E4724 7F0AFBF4 27B7007C */  addiu $s7, $sp, 0x7c
/* 0E4728 7F0AFBF8 11E00039 */  beqz  $t7, .L7F0AFCE0
/* 0E472C 7F0AFBFC 241E0004 */   li    $fp, 4
/* 0E4730 7F0AFC00 27B20058 */  addiu $s2, $sp, 0x58
/* 0E4734 7F0AFC04 96380000 */  lhu   $t8, ($s1)
.L7F0AFC08:
/* 0E4738 7F0AFC08 24010001 */  li    $at, 1
/* 0E473C 7F0AFC0C 0018CBC3 */  sra   $t9, $t8, 0xf
/* 0E4740 7F0AFC10 33280001 */  andi  $t0, $t9, 1
/* 0E4744 7F0AFC14 51010029 */  beql  $t0, $at, .L7F0AFCBC
/* 0E4748 7F0AFC18 86220006 */   lh    $v0, 6($s1)
/* 0E474C 7F0AFC1C 0FC2BDD8 */  jal   sub_GAME_7F0AF760
/* 0E4750 7F0AFC20 02202025 */   move  $a0, $s1
/* 0E4754 7F0AFC24 14400024 */  bnez  $v0, .L7F0AFCB8
/* 0E4758 7F0AFC28 00008025 */   move  $s0, $zero
.L7F0AFC2C:
/* 0E475C 7F0AFC2C 16160006 */  bne   $s0, $s6, .L7F0AFC48
/* 0E4760 7F0AFC30 02202025 */   move  $a0, $s1
/* 0E4764 7F0AFC34 02202025 */  move  $a0, $s1
/* 0E4768 7F0AFC38 0FC2BE49 */  jal   getTileMidPoint
/* 0E476C 7F0AFC3C 02402825 */   move  $a1, $s2
/* 0E4770 7F0AFC40 10000005 */  b     .L7F0AFC58
/* 0E4774 7F0AFC44 4407B000 */   mfc1  $a3, $f22
.L7F0AFC48:
/* 0E4778 7F0AFC48 02002825 */  move  $a1, $s0
/* 0E477C 7F0AFC4C 0FC2BE87 */  jal   getPointJustInsideOfTileTriple
/* 0E4780 7F0AFC50 02403025 */   move  $a2, $s2
/* 0E4784 7F0AFC54 4407B000 */  mfc1  $a3, $f22
.L7F0AFC58:
/* 0E4788 7F0AFC58 AFB1007C */  sw    $s1, 0x7c($sp)
/* 0E478C 7F0AFC5C 02E02025 */  move  $a0, $s7
/* 0E4790 7F0AFC60 8FA50058 */  lw    $a1, 0x58($sp)
/* 0E4794 7F0AFC64 0FC2C834 */  jal   sub_GAME_7F0B20D0
/* 0E4798 7F0AFC68 8FA60060 */   lw    $a2, 0x60($sp)
/* 0E479C 7F0AFC6C 0441000F */  bgez  $v0, .L7F0AFCAC
/* 0E47A0 7F0AFC70 02402025 */   move  $a0, $s2
/* 0E47A4 7F0AFC74 0FC2BEC7 */  jal   sub_GAME_7F0AFB1C
/* 0E47A8 7F0AFC78 27A50064 */   addiu $a1, $sp, 0x64
/* 0E47AC 7F0AFC7C 4614003C */  c.lt.s $f0, $f20
/* 0E47B0 7F0AFC80 00000000 */  nop
/* 0E47B4 7F0AFC84 4502000A */  bc1fl .L7F0AFCB0
/* 0E47B8 7F0AFC88 26100001 */   addiu $s0, $s0, 1
/* 0E47BC 7F0AFC8C C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 0E47C0 7F0AFC90 AFB10078 */  sw    $s1, 0x78($sp)
/* 0E47C4 7F0AFC94 46000506 */  mov.s $f20, $f0
/* 0E47C8 7F0AFC98 E66A0000 */  swc1  $f10, ($s3)
/* 0E47CC 7F0AFC9C C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 0E47D0 7F0AFCA0 E6900000 */  swc1  $f16, ($s4)
/* 0E47D4 7F0AFCA4 C7B20060 */  lwc1  $f18, 0x60($sp)
/* 0E47D8 7F0AFCA8 E6B20000 */  swc1  $f18, ($s5)
.L7F0AFCAC:
/* 0E47DC 7F0AFCAC 26100001 */  addiu $s0, $s0, 1
.L7F0AFCB0:
/* 0E47E0 7F0AFCB0 161EFFDE */  bne   $s0, $fp, .L7F0AFC2C
/* 0E47E4 7F0AFCB4 00000000 */   nop
.L7F0AFCB8:
/* 0E47E8 7F0AFCB8 86220006 */  lh    $v0, 6($s1)
.L7F0AFCBC:
/* 0E47EC 7F0AFCBC 3C0B8004 */  lui   $t3, %hi(list_of_tilesizes)
/* 0E47F0 7F0AFCC0 00024B03 */  sra   $t1, $v0, 0xc
/* 0E47F4 7F0AFCC4 312A000F */  andi  $t2, $t1, 0xf
/* 0E47F8 7F0AFCC8 016A5821 */  addu  $t3, $t3, $t2
/* 0E47FC 7F0AFCCC 916B0F4C */  lbu   $t3, %lo(list_of_tilesizes)($t3)
/* 0E4800 7F0AFCD0 01718821 */  addu  $s1, $t3, $s1
/* 0E4804 7F0AFCD4 8E2C0000 */  lw    $t4, ($s1)
/* 0E4808 7F0AFCD8 5580FFCB */  bnezl $t4, .L7F0AFC08
/* 0E480C 7F0AFCDC 96380000 */   lhu   $t8, ($s1)
.L7F0AFCE0:
/* 0E4810 7F0AFCE0 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0E4814 7F0AFCE4 8FA20078 */  lw    $v0, 0x78($sp)
/* 0E4818 7F0AFCE8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0E481C 7F0AFCEC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0E4820 7F0AFCF0 8FB00028 */  lw    $s0, 0x28($sp)
/* 0E4824 7F0AFCF4 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0E4828 7F0AFCF8 8FB20030 */  lw    $s2, 0x30($sp)
/* 0E482C 7F0AFCFC 8FB30034 */  lw    $s3, 0x34($sp)
/* 0E4830 7F0AFD00 8FB40038 */  lw    $s4, 0x38($sp)
/* 0E4834 7F0AFD04 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0E4838 7F0AFD08 8FB60040 */  lw    $s6, 0x40($sp)
/* 0E483C 7F0AFD0C 8FB70044 */  lw    $s7, 0x44($sp)
/* 0E4840 7F0AFD10 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0E4844 7F0AFD14 03E00008 */  jr    $ra
/* 0E4848 7F0AFD18 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif




// Returns the shortest distance from (p_x,p_z) to the infinite extention of tile's index-th edge, projected into XZ.
// Where the edge is vertical (or degenerate) they just return the distance between the points.
// cannonically tile is sf and index is ei
f32 getShortest2dDispToInfTileEdge(StandTile *tile,s32 index,f32 p_x,f32 p_z)
{
    s32 nextIndex;
    f32 edge_x;
    f32 edge_z;
    f32 edge_len; //canonically d

    f32 v_x;
    f32 v_z;
    f32 crossProduct;

    // 3 unused. We use 2 for the points to make our code cleaner,
    //   though it seems much more likely that the variables were used in the else clause.
    struct StandTilePoint* currPnt;
    struct StandTilePoint* nextPnt;
    f32 UNUSED;

    #ifdef DEBUG
    assert(ei<getsides(sf));
    #endif

    // Omiting the '& 0xF' is equivalent, but keeping it is necessary to match.
    // Perhaps the structure isn't correct but this seems much cleaner than doing an explicit >> 0xC.
    nextIndex = (index + 1) % STAN_TAIL_E(tile);

    nextPnt = &tile->points[nextIndex];
    currPnt = &tile->points[index];
    edge_x = (f32)(nextPnt->x - currPnt->x);
    edge_z = (f32)(nextPnt->z - currPnt->z);

    edge_len = sqrtf(edge_x * edge_x + edge_z * edge_z);

    if (edge_len == 0) {
        // Degenerate case, edge is vertical
        // They just return the distance between the points, which is sensible and the correct value in 3 dimensions.
        v_x = p_x - (f32)tile->points[nextIndex].x;
        v_z = p_z - (f32)tile->points[nextIndex].z;
        return sqrtf(v_x * v_x + v_z * v_z);
    }
    else
    {
        #ifdef DEBUG
        assert(d>0.0f);
        #endif

        // | (AP x AB) / ||AB|| | = ||PA|| sin(a),
        // so we're returning the SIGNED displacement
        crossProduct = (
            edge_z * (p_x - (f32)tile->points[index].x)
            +
            -edge_x * (p_z - (f32)tile->points[index].z)
        );
        return crossProduct / edge_len;
    }

}


// Sig needed for caller matches.
f32 getShortest2dDispToInfTripleEdge(StandTile *tile,s32 start3index,f32 p_x,f32 p_z);

#ifdef NONMATCHING
// Only regalloc incorrect essentially. Any change I make seems to make things much worse though,
//   and my ability to reorder statements is very limited.

// Similar to getShortest2dDispToInfTileEdge
// 2nd arg must be in {0,1,2}
// New name needed though: getShortest2dDispToInfTripleEdge
//same as above, tile is sf, index is ei
f32 getShortest2dDispToInfTripleEdge(StandTile *tile,s32 start3index,f32 p_x,f32 p_z)
{
    s32 end3index;      // types seem correct, changing introduces more instructions

    f32 edge_x;       // 0x40 (8)
    f32 edge_z;       // 0x3C
    f32 edge_len;

    s32 currPntI;
    s32 nextPntI;

    f32 v_x;
    f32 v_z;
    f32 crossProduct;

    #ifdef DEBUG
    assert(ei<getsides(sf));
    #endif


    // end3index = (start3index + 1) % 3, start3index in [0,3)
    if (start3index != 2) {
        end3index = start3index + 1;
    }
    else {
        end3index = 0;
    }

    // making and reusing macros of these introduces extra instructions later
    currPntI = STAN_TRIPLE_TO_PNT_INDEX(tile, start3index);
    nextPntI = STAN_TRIPLE_TO_PNT_INDEX(tile, end3index);

    edge_x = (f32)(tile->points[nextPntI].x - tile->points[currPntI].x);
    edge_z = (f32)(tile->points[nextPntI].z - tile->points[currPntI].z);


    // Identical to getShortest2dDispToInfTileEdge from here

    edge_len = sqrtf(edge_x * edge_x + edge_z * edge_z);

    if (edge_len == 0) {
        // Degenerate case, edge is vertical
        // They just return the distance between the points, which is sensible and the correct value in 3 dimensions.
        v_x = p_x - (f32)tile->points[nextPntI].x;
        v_z = p_z - (f32)tile->points[nextPntI].z;
        return sqrtf(v_x * v_x + v_z * v_z);
    }
    else
    {
        #ifdef DEBUG
        assert(d>0.0f);
        #endif

        // - (AP x AB) / ||AB|| = ||PA|| sin(a)
        crossProduct = (
            edge_z * (p_x - (f32)tile->points[currPntI].x)
            +
            -edge_x * (p_z - (f32)tile->points[currPntI].z)
        );
        return crossProduct / edge_len;
    }
}

#else
GLOBAL_ASM(
.text
glabel getShortest2dDispToInfTripleEdge
/* 0E49A0 7F0AFE70 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0E49A4 7F0AFE74 AFA70054 */  sw    $a3, 0x54($sp)
/* 0E49A8 7F0AFE78 24010002 */  li    $at, 2
/* 0E49AC 7F0AFE7C 00803825 */  move  $a3, $a0
/* 0E49B0 7F0AFE80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E49B4 7F0AFE84 AFA40048 */  sw    $a0, 0x48($sp)
/* 0E49B8 7F0AFE88 10A10003 */  beq   $a1, $at, .L7F0AFE98
/* 0E49BC 7F0AFE8C AFA60050 */   sw    $a2, 0x50($sp)
/* 0E49C0 7F0AFE90 10000002 */  b     .L7F0AFE9C
/* 0E49C4 7F0AFE94 24A30001 */   addiu $v1, $a1, 1
.L7F0AFE98:
/* 0E49C8 7F0AFE98 00001825 */  move  $v1, $zero
.L7F0AFE9C:
/* 0E49CC 7F0AFE9C 84E20006 */  lh    $v0, 6($a3)
/* 0E49D0 7F0AFEA0 24080008 */  li    $t0, 8
/* 0E49D4 7F0AFEA4 00057080 */  sll   $t6, $a1, 2
/* 0E49D8 7F0AFEA8 0003C880 */  sll   $t9, $v1, 2
/* 0E49DC 7F0AFEAC 010E7823 */  subu  $t7, $t0, $t6
/* 0E49E0 7F0AFEB0 01194823 */  subu  $t1, $t0, $t9
/* 0E49E4 7F0AFEB4 01E22807 */  srav  $a1, $v0, $t7
/* 0E49E8 7F0AFEB8 01221807 */  srav  $v1, $v0, $t1
/* 0E49EC 7F0AFEBC 30B8000F */  andi  $t8, $a1, 0xf
/* 0E49F0 7F0AFEC0 306A000F */  andi  $t2, $v1, 0xf
/* 0E49F4 7F0AFEC4 000A58C0 */  sll   $t3, $t2, 3
/* 0E49F8 7F0AFEC8 001860C0 */  sll   $t4, $t8, 3
/* 0E49FC 7F0AFECC 00EC3021 */  addu  $a2, $a3, $t4
/* 0E4A00 7F0AFED0 00EB2021 */  addu  $a0, $a3, $t3
/* 0E4A04 7F0AFED4 848D0008 */  lh    $t5, 8($a0)
/* 0E4A08 7F0AFED8 84CE0008 */  lh    $t6, 8($a2)
/* 0E4A0C 7F0AFEDC 8498000C */  lh    $t8, 0xc($a0)
/* 0E4A10 7F0AFEE0 84D9000C */  lh    $t9, 0xc($a2)
/* 0E4A14 7F0AFEE4 01AE7823 */  subu  $t7, $t5, $t6
/* 0E4A18 7F0AFEE8 448F2000 */  mtc1  $t7, $f4
/* 0E4A1C 7F0AFEEC 03194823 */  subu  $t1, $t8, $t9
/* 0E4A20 7F0AFEF0 44893000 */  mtc1  $t1, $f6
/* 0E4A24 7F0AFEF4 468020A0 */  cvt.s.w $f2, $f4
/* 0E4A28 7F0AFEF8 AFA60018 */  sw    $a2, 0x18($sp)
/* 0E4A2C 7F0AFEFC AFA4001C */  sw    $a0, 0x1c($sp)
/* 0E4A30 7F0AFF00 468033A0 */  cvt.s.w $f14, $f6
/* 0E4A34 7F0AFF04 46021202 */  mul.s $f8, $f2, $f2
/* 0E4A38 7F0AFF08 E7A20040 */  swc1  $f2, 0x40($sp)
/* 0E4A3C 7F0AFF0C 460E7282 */  mul.s $f10, $f14, $f14
/* 0E4A40 7F0AFF10 E7AE003C */  swc1  $f14, 0x3c($sp)
/* 0E4A44 7F0AFF14 0C007DF8 */  jal   sqrtf
/* 0E4A48 7F0AFF18 460A4300 */   add.s $f12, $f8, $f10
/* 0E4A4C 7F0AFF1C 44802000 */  mtc1  $zero, $f4
/* 0E4A50 7F0AFF20 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0E4A54 7F0AFF24 8FA60018 */  lw    $a2, 0x18($sp)
/* 0E4A58 7F0AFF28 46040032 */  c.eq.s $f0, $f4
/* 0E4A5C 7F0AFF2C C7A20040 */  lwc1  $f2, 0x40($sp)
/* 0E4A60 7F0AFF30 C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 0E4A64 7F0AFF34 C7B20050 */  lwc1  $f18, 0x50($sp)
/* 0E4A68 7F0AFF38 45000011 */  bc1f  .L7F0AFF80
/* 0E4A6C 7F0AFF3C 46000406 */   mov.s $f16, $f0
/* 0E4A70 7F0AFF40 848A0008 */  lh    $t2, 8($a0)
/* 0E4A74 7F0AFF44 848B000C */  lh    $t3, 0xc($a0)
/* 0E4A78 7F0AFF48 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 0E4A7C 7F0AFF4C 448A3000 */  mtc1  $t2, $f6
/* 0E4A80 7F0AFF50 448B2000 */  mtc1  $t3, $f4
/* 0E4A84 7F0AFF54 46803220 */  cvt.s.w $f8, $f6
/* 0E4A88 7F0AFF58 468021A0 */  cvt.s.w $f6, $f4
/* 0E4A8C 7F0AFF5C 46089001 */  sub.s $f0, $f18, $f8
/* 0E4A90 7F0AFF60 46065081 */  sub.s $f2, $f10, $f6
/* 0E4A94 7F0AFF64 46000202 */  mul.s $f8, $f0, $f0
/* 0E4A98 7F0AFF68 00000000 */  nop
/* 0E4A9C 7F0AFF6C 46021102 */  mul.s $f4, $f2, $f2
/* 0E4AA0 7F0AFF70 0C007DF8 */  jal   sqrtf
/* 0E4AA4 7F0AFF74 46044300 */   add.s $f12, $f8, $f4
/* 0E4AA8 7F0AFF78 10000011 */  b     .L7F0AFFC0
/* 0E4AAC 7F0AFF7C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0AFF80:
/* 0E4AB0 7F0AFF80 84CC000C */  lh    $t4, 0xc($a2)
/* 0E4AB4 7F0AFF84 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 0E4AB8 7F0AFF88 84CD0008 */  lh    $t5, 8($a2)
/* 0E4ABC 7F0AFF8C 448C3000 */  mtc1  $t4, $f6
/* 0E4AC0 7F0AFF90 00000000 */  nop
/* 0E4AC4 7F0AFF94 46803220 */  cvt.s.w $f8, $f6
/* 0E4AC8 7F0AFF98 46001187 */  neg.s $f6, $f2
/* 0E4ACC 7F0AFF9C 46085101 */  sub.s $f4, $f10, $f8
/* 0E4AD0 7F0AFFA0 448D4000 */  mtc1  $t5, $f8
/* 0E4AD4 7F0AFFA4 46062282 */  mul.s $f10, $f4, $f6
/* 0E4AD8 7F0AFFA8 46804120 */  cvt.s.w $f4, $f8
/* 0E4ADC 7F0AFFAC 46049181 */  sub.s $f6, $f18, $f4
/* 0E4AE0 7F0AFFB0 46067202 */  mul.s $f8, $f14, $f6
/* 0E4AE4 7F0AFFB4 46085300 */  add.s $f12, $f10, $f8
/* 0E4AE8 7F0AFFB8 46106003 */  div.s $f0, $f12, $f16
/* 0E4AEC 7F0AFFBC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0AFFC0:
/* 0E4AF0 7F0AFFC0 27BD0048 */  addiu $sp, $sp, 0x48
/* 0E4AF4 7F0AFFC4 03E00008 */  jr    $ra
/* 0E4AF8 7F0AFFC8 00000000 */   nop
)
#endif





f32 getShortest2dDispToInfTileEdgeUnscaled(StandTile *tile, int index,f32 x,f32 z)
{
  f32 disp;

  disp = getShortest2dDispToInfTileEdge(tile, index, x * level_scale, z * level_scale);
  return disp * inv_level_scale;
}






f32 getShortest2dDispToInfTripleEdgeUnscaled(StandTile *tile,s32 start3index,f32 p_x,f32 p_z)
{
  f32 disp;

  disp = getShortest2dDispToInfTripleEdge(tile, start3index, p_x * level_scale, p_z * level_scale);
  return disp * inv_level_scale;
}




f32 distToTilePnt2D(StandTile *tile,int pntI,f32 p_x,f32 p_z)
{
  f32 len;

  p_x -= (f32)tile->points[pntI].x;
  p_z -= (f32)tile->points[pntI].z;
  return sqrtf(p_x * p_x + p_z * p_z);
}




#ifdef NONMATCHING
f32 sub_GAME_7F0B00C4(StandTile *tile,s32 index,f32 p_x,f32 p_z)
{
  f32 v_x;
  f32 v_z;
  f32 dist;

  v_x = p_x * level_scale - (f32)tile->points[index].x;
  v_z = p_z * level_scale - (f32)tile->points[index].z;
  dist = sqrtf(v_x * v_x + v_z * v_z);

  return dist * inv_level_scale;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B00C4
/* 0E4BF4 7F0B00C4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E4BF8 7F0B00C8 000570C0 */  sll   $t6, $a1, 3
/* 0E4BFC 7F0B00CC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E4C00 7F0B00D0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0E4C04 7F0B00D4 008E1021 */  addu  $v0, $a0, $t6
/* 0E4C08 7F0B00D8 844F0008 */  lh    $t7, 8($v0)
/* 0E4C0C 7F0B00DC 3C018004 */  lui   $at, %hi(level_scale)
/* 0E4C10 7F0B00E0 44867000 */  mtc1  $a2, $f14
/* 0E4C14 7F0B00E4 C4200F44 */  lwc1  $f0, %lo(level_scale)($at)
/* 0E4C18 7F0B00E8 8458000C */  lh    $t8, 0xc($v0)
/* 0E4C1C 7F0B00EC 448F2000 */  mtc1  $t7, $f4
/* 0E4C20 7F0B00F0 46007382 */  mul.s $f14, $f14, $f0
/* 0E4C24 7F0B00F4 4487A000 */  mtc1  $a3, $f20
/* 0E4C28 7F0B00F8 44984000 */  mtc1  $t8, $f8
/* 0E4C2C 7F0B00FC 4600A502 */  mul.s $f20, $f20, $f0
/* 0E4C30 7F0B0100 468021A0 */  cvt.s.w $f6, $f4
/* 0E4C34 7F0B0104 468042A0 */  cvt.s.w $f10, $f8
/* 0E4C38 7F0B0108 46067381 */  sub.s $f14, $f14, $f6
/* 0E4C3C 7F0B010C 460AA501 */  sub.s $f20, $f20, $f10
/* 0E4C40 7F0B0110 460E7402 */  mul.s $f16, $f14, $f14
/* 0E4C44 7F0B0114 00000000 */  nop
/* 0E4C48 7F0B0118 4614A482 */  mul.s $f18, $f20, $f20
/* 0E4C4C 7F0B011C 0C007DF8 */  jal   sqrtf
/* 0E4C50 7F0B0120 46128300 */   add.s $f12, $f16, $f18
/* 0E4C54 7F0B0124 3C018004 */  lui   $at, %hi(inv_level_scale)
/* 0E4C58 7F0B0128 C4240F48 */  lwc1  $f4, %lo(inv_level_scale)($at)
/* 0E4C5C 7F0B012C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E4C60 7F0B0130 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0E4C64 7F0B0134 46040002 */  mul.s $f0, $f0, $f4
/* 0E4C68 7F0B0138 03E00008 */  jr    $ra
/* 0E4C6C 7F0B013C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING

// dot product
f32 sub_GAME_7F0B0140(StandTile *tile, s32 index, f32 p_x, f32 p_z)
{
    f32 d_x;
    f32 d_z;

    d_x = (p_x * level_scale) * tile->points[index].x;
    d_z = (p_z * level_scale) * tile->points[index].z;  // was originally commuted

    return (d_x + d_z) * inv_level_scale);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B0140
/* 0E4C70 7F0B0140 3C018004 */  lui   $at, %hi(level_scale)
/* 0E4C74 7F0B0144 000570C0 */  sll   $t6, $a1, 3
/* 0E4C78 7F0B0148 44866000 */  mtc1  $a2, $f12
/* 0E4C7C 7F0B014C C4220F44 */  lwc1  $f2, %lo(level_scale)($at)
/* 0E4C80 7F0B0150 008E1021 */  addu  $v0, $a0, $t6
/* 0E4C84 7F0B0154 844F000C */  lh    $t7, 0xc($v0)
/* 0E4C88 7F0B0158 46026302 */  mul.s $f12, $f12, $f2
/* 0E4C8C 7F0B015C 44877000 */  mtc1  $a3, $f14
/* 0E4C90 7F0B0160 84580008 */  lh    $t8, 8($v0)
/* 0E4C94 7F0B0164 448F2000 */  mtc1  $t7, $f4
/* 0E4C98 7F0B0168 46027382 */  mul.s $f14, $f14, $f2
/* 0E4C9C 7F0B016C 44985000 */  mtc1  $t8, $f10
/* 0E4CA0 7F0B0170 3C018004 */  lui   $at, %hi(inv_level_scale)
/* 0E4CA4 7F0B0174 468021A0 */  cvt.s.w $f6, $f4
/* 0E4CA8 7F0B0178 46805420 */  cvt.s.w $f16, $f10
/* 0E4CAC 7F0B017C 460E3202 */  mul.s $f8, $f6, $f14
/* 0E4CB0 7F0B0180 C4260F48 */  lwc1  $f6, %lo(inv_level_scale)($at)
/* 0E4CB4 7F0B0184 46106482 */  mul.s $f18, $f12, $f16
/* 0E4CB8 7F0B0188 46124100 */  add.s $f4, $f8, $f18
/* 0E4CBC 7F0B018C 46062002 */  mul.s $f0, $f4, $f6
/* 0E4CC0 7F0B0190 03E00008 */  jr    $ra
/* 0E4CC4 7F0B0194 00000000 */   nop
)
#endif





#ifdef NONMATCHING
// Similar to others
f32 sub_GAME_7F0B0198(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    void *temp_v0;
    void *temp_v0_2;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f18;
    f32 temp_f6;
    f32 temp_f2_2;
    f32 temp_f0_2;
    s32 phi_v0;
    s32 phi_v0_2;
    s32 phi_v0_3;

    // Node 0
    temp_v0 = (arg0 + (arg1 * 8));
    temp_v0_2 = (arg0 + (((s32) (arg1 + 1) % (s32) (((s32) arg0->unk6 >> 0xc) & 0xf)) * 8));
    temp_f0 = (f32) temp_v0->unk8;
    temp_f2 = (f32) temp_v0->unkC;
    temp_f12 = ((f32) temp_v0_2->unk8 - temp_f0);
    temp_f14 = ((f32) temp_v0_2->unkC - temp_f2);
    temp_f18 = (arg2 - temp_f0);
    temp_f6 = (arg3 - temp_f2);
    arg2 = temp_f18;
    arg3 = temp_f6;
    temp_f2_2 = ((temp_f12 * temp_f12) + (temp_f14 * temp_f14));
    temp_f0_2 = ((temp_f18 * temp_f12) + (temp_f6 * temp_f14));
    phi_v0 = 0;
    if (temp_f2_2 < temp_f0_2)
    {
        // Node 1
        phi_v0 = 1;
    }
    // Node 2
    if ((phi_v0 != 0) && (temp_f0_2 < 0.0f))
    {
        // Node 4
        phi_v0_2 = 1;
        // Node 5
        if (phi_v0_2 == 0)
        {
            // Node 6
            phi_v0_3 = 0;
            if (0.0f < temp_f0_2)
            {
                // Node 7
                phi_v0_3 = 1;
            }
            // Node 8
            if (phi_v0_3 != 0)
            {
                // Node 9
                if (temp_f0_2 < temp_f2_2)
                {
                    // Node 10
                }
            }
        }
    }
    else
    {
        // Node 6
        phi_v0_3 = 0;
        if (0.0f < temp_f0_2)
        {
            // Node 7
            phi_v0_3 = 1;
        }
        // Node 8
        if (phi_v0_3 != 0)
        {
            // Node 9
            if (temp_f0_2 < temp_f2_2)
            {
                // Node 10
            }
        }
    }
    // Node 11
    return temp_f0_2;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B0198
/* 0E4CC8 7F0B0198 AFA60008 */  sw    $a2, 8($sp)
/* 0E4CCC 7F0B019C AFA7000C */  sw    $a3, 0xc($sp)
/* 0E4CD0 7F0B01A0 84880006 */  lh    $t0, 6($a0)
/* 0E4CD4 7F0B01A4 24B90001 */  addiu $t9, $a1, 1
/* 0E4CD8 7F0B01A8 000570C0 */  sll   $t6, $a1, 3
/* 0E4CDC 7F0B01AC 00084B03 */  sra   $t1, $t0, 0xc
/* 0E4CE0 7F0B01B0 312A000F */  andi  $t2, $t1, 0xf
/* 0E4CE4 7F0B01B4 032A001A */  div   $zero, $t9, $t2
/* 0E4CE8 7F0B01B8 008E1021 */  addu  $v0, $a0, $t6
/* 0E4CEC 7F0B01BC 00002810 */  mfhi  $a1
/* 0E4CF0 7F0B01C0 844F0008 */  lh    $t7, 8($v0)
/* 0E4CF4 7F0B01C4 8458000C */  lh    $t8, 0xc($v0)
/* 0E4CF8 7F0B01C8 000558C0 */  sll   $t3, $a1, 3
/* 0E4CFC 7F0B01CC 008B1021 */  addu  $v0, $a0, $t3
/* 0E4D00 7F0B01D0 844C0008 */  lh    $t4, 8($v0)
/* 0E4D04 7F0B01D4 844D000C */  lh    $t5, 0xc($v0)
/* 0E4D08 7F0B01D8 448F2000 */  mtc1  $t7, $f4
/* 0E4D0C 7F0B01DC 448C4000 */  mtc1  $t4, $f8
/* 0E4D10 7F0B01E0 44983000 */  mtc1  $t8, $f6
/* 0E4D14 7F0B01E4 46802020 */  cvt.s.w $f0, $f4
/* 0E4D18 7F0B01E8 448D5000 */  mtc1  $t5, $f10
/* 0E4D1C 7F0B01EC C7B00008 */  lwc1  $f16, 8($sp)
/* 0E4D20 7F0B01F0 C7A4000C */  lwc1  $f4, 0xc($sp)
/* 0E4D24 7F0B01F4 00001025 */  move  $v0, $zero
/* 0E4D28 7F0B01F8 46804320 */  cvt.s.w $f12, $f8
/* 0E4D2C 7F0B01FC 468030A0 */  cvt.s.w $f2, $f6
/* 0E4D30 7F0B0200 15400002 */  bnez  $t2, .L7F0B020C
/* 0E4D34 7F0B0204 00000000 */   nop
/* 0E4D38 7F0B0208 0007000D */  break 7
.L7F0B020C:
/* 0E4D3C 7F0B020C 2401FFFF */  li    $at, -1
/* 0E4D40 7F0B0210 15410004 */  bne   $t2, $at, .L7F0B0224
/* 0E4D44 7F0B0214 3C018000 */   lui   $at, 0x8000
/* 0E4D48 7F0B0218 17210002 */  bne   $t9, $at, .L7F0B0224
/* 0E4D4C 7F0B021C 00000000 */   nop
/* 0E4D50 7F0B0220 0006000D */  break 6
.L7F0B0224:
/* 0E4D54 7F0B0224 468053A0 */  cvt.s.w $f14, $f10
/* 0E4D58 7F0B0228 46006301 */  sub.s $f12, $f12, $f0
/* 0E4D5C 7F0B022C 46027381 */  sub.s $f14, $f14, $f2
/* 0E4D60 7F0B0230 460C6202 */  mul.s $f8, $f12, $f12
/* 0E4D64 7F0B0234 46008481 */  sub.s $f18, $f16, $f0
/* 0E4D68 7F0B0238 460E7282 */  mul.s $f10, $f14, $f14
/* 0E4D6C 7F0B023C 46022181 */  sub.s $f6, $f4, $f2
/* 0E4D70 7F0B0240 460C9402 */  mul.s $f16, $f18, $f12
/* 0E4D74 7F0B0244 E7B20008 */  swc1  $f18, 8($sp)
/* 0E4D78 7F0B0248 460E3102 */  mul.s $f4, $f6, $f14
/* 0E4D7C 7F0B024C E7A6000C */  swc1  $f6, 0xc($sp)
/* 0E4D80 7F0B0250 460A4080 */  add.s $f2, $f8, $f10
/* 0E4D84 7F0B0254 46048000 */  add.s $f0, $f16, $f4
/* 0E4D88 7F0B0258 4600103C */  c.lt.s $f2, $f0
/* 0E4D8C 7F0B025C 00000000 */  nop
/* 0E4D90 7F0B0260 45000002 */  bc1f  .L7F0B026C
/* 0E4D94 7F0B0264 00000000 */   nop
/* 0E4D98 7F0B0268 24020001 */  li    $v0, 1
.L7F0B026C:
/* 0E4D9C 7F0B026C 5040000B */  beql  $v0, $zero, .L7F0B029C
/* 0E4DA0 7F0B0270 44805000 */   mtc1  $zero, $f10
/* 0E4DA4 7F0B0274 44804000 */  mtc1  $zero, $f8
/* 0E4DA8 7F0B0278 00001025 */  move  $v0, $zero
/* 0E4DAC 7F0B027C 4608003C */  c.lt.s $f0, $f8
/* 0E4DB0 7F0B0280 00000000 */  nop
/* 0E4DB4 7F0B0284 45000002 */  bc1f  .L7F0B0290
/* 0E4DB8 7F0B0288 00000000 */   nop
/* 0E4DBC 7F0B028C 24020001 */  li    $v0, 1
.L7F0B0290:
/* 0E4DC0 7F0B0290 1440000F */  bnez  $v0, .L7F0B02D0
/* 0E4DC4 7F0B0294 00000000 */   nop
/* 0E4DC8 7F0B0298 44805000 */  mtc1  $zero, $f10
.L7F0B029C:
/* 0E4DCC 7F0B029C 00001025 */  move  $v0, $zero
/* 0E4DD0 7F0B02A0 4600503C */  c.lt.s $f10, $f0
/* 0E4DD4 7F0B02A4 00000000 */  nop
/* 0E4DD8 7F0B02A8 45000002 */  bc1f  .L7F0B02B4
/* 0E4DDC 7F0B02AC 00000000 */   nop
/* 0E4DE0 7F0B02B0 24020001 */  li    $v0, 1
.L7F0B02B4:
/* 0E4DE4 7F0B02B4 10400006 */  beqz  $v0, .L7F0B02D0
/* 0E4DE8 7F0B02B8 00000000 */   nop
/* 0E4DEC 7F0B02BC 4602003C */  c.lt.s $f0, $f2
/* 0E4DF0 7F0B02C0 00001025 */  move  $v0, $zero
/* 0E4DF4 7F0B02C4 45000002 */  bc1f  .L7F0B02D0
/* 0E4DF8 7F0B02C8 00000000 */   nop
/* 0E4DFC 7F0B02CC 24020001 */  li    $v0, 1
.L7F0B02D0:
/* 0E4E00 7F0B02D0 03E00008 */  jr    $ra
/* 0E4E04 7F0B02D4 00000000 */   nop
)
#endif





// Determines if inside (presumably - it effectively does an && of the checks on signs of cross products)
//   based on the 3 edges. So probably only for triangular tiles.
s32 isPointInsideTriStandTile_Maybe(StandTile *tile, f32 p_x, f32 p_z)
{
    f32 disp;
    s32 i;

    for (i = 0; i != 3; i++)
    {
        disp = getShortest2dDispToInfTripleEdge(tile,i,p_x,p_z);
        if (disp < 0) {
            return 0;
        }
    }

    return 1;
}



s32 isPointInsideTriStandTileUnscaled_Maybe(StandTile *tile, f32 p_x, f32 p_z)
{
    f32 disp;
    s32 i;

    for (i = 0; i != 3; i++)
    {
        disp = getShortest2dDispToInfTripleEdgeUnscaled(tile,i,p_x,p_z);
        if (disp < 0) {
            return 0;
        }
    }

    return 1;
}


/*
* Address: 0x7F0B0400
*/
f32 sub_GAME_7F0B0400(StandTile *tile, s32 start3index, f32 p_x, f32 p_z)
{
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f14;
    s32 var_a0;
    s32 padding;

    f32 tempf;
    s32 extra_padding[2];

    #ifdef DEBUG
    assert(ei<getsides(sf));
    #endif

    var_a0 = (start3index != 2) ? start3index + 1 : 0;

    start3index = (tile->tail.half >> (8 - (start3index << 2))) & 0xF;
    var_a0 = (tile->tail.half >> (8 - (var_a0 << 2))) & 0xF;

    temp_f2 = (f32)(tile->points[var_a0].x - tile->points[start3index].x);
    temp_f14 = (f32)(tile->points[var_a0].z - tile->points[start3index].z);

    temp_f0 = sqrtf((temp_f2 * temp_f2) + (temp_f14 * temp_f14));

    if (temp_f0 == 0.0f) {
        return 0.0f;
    }

    #ifdef DEBUG
    assert(d>0.0f);
    #endif

    tempf = (temp_f14 * (p_x - tile->points[start3index].x)) + ((p_z - tile->points[start3index].z) * -temp_f2);
    return tempf / temp_f0;
}




bool stanTestPointWithinTileBoundsMaybe(StandTile *tile, f32 p_x, f32 p_z)
{
    f32 unk;
    s32 i;

    p_x *= level_scale;
    p_z *= level_scale;

    for (i = 0; i != 3; i++)
    {
        unk = sub_GAME_7F0B0400(tile, i, p_x, p_z);

        if (unk < -2)
        {
            return FALSE;
        }
    }

    return TRUE;
}



// A->B ACWS returns 1, CWS (including opposite) returns -1.
// Identical direction and |A| >= |B| returns 0
int getRotationalDirectionBetween(f32 a_x,f32 a_z,f32 b_x,f32 b_z)
{
    // The main 2 cases : return the sign of AxB where it's non-zero
    if (a_z * b_x < a_x * b_z) {
        return 1;
    }
    if (a_x * b_z < a_z * b_x) {
        return -1;
    }

    // [AxB == 0 now]

    // If the vectors are opposite, default to clockwise
    if ((a_x * b_x < 0) || (a_z * b_z < 0)) {
      return -1;
    }

    // If A is shorter, return anti-clockwise
    if (a_x * a_x + a_z * a_z < b_x * b_x + b_z * b_z) {
        return 1;   // ACWS
    }

    // Identical direction, |A| >= |B|
    return 0;
}





s32 sub_GAME_7F0B0688(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
{
    s32 unused1;
    s32 unused2;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = arg0 - arg4;
    sp20 = arg1 - arg5;
    sp1C = arg2 - arg0;
    sp18 = arg3 - arg1;

    return
        (
            (getRotationalDirectionBetween(sp1C, sp18, -sp24, -sp20)
            * getRotationalDirectionBetween(sp1C, sp18, arg6 - arg0, arg7 - arg1)) < 1)
        &&
        (
            (getRotationalDirectionBetween(arg6 - arg4, arg7 - arg5, sp24, sp20)
            * getRotationalDirectionBetween(arg6 - arg4, arg7 - arg5, arg2 - arg4, arg3 - arg5)) < 1)
        ;
}




#if defined(LEFTOVERDEBUG)
#ifdef NONMATCHING
/* 99.44% match, only the stack is slightly wrong */
s32 sub_GAME_7F0B07BC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    f32 c_z2;
    f32 a_x2;
    f32 b_x2;
    f32 a_z2;
    s32 val2;
    f32 c_x;
    s32 val1;
    f32 b_x;
    s32 rc;
    f32 c_x2;
    f32 a_z;
    f32 b_z;
    f32 b_z2;
    f32 a_x;
    f32 c_z;


    rc = 1;
    b_x = -(arg0 - arg4);
    c_z = arg7 - arg1;
    c_x = arg6 - arg0;
    a_x = arg2 - arg0;
    a_z = arg3 - arg1;
    b_z = -(arg1 - arg5);


    val1 = getRotationalDirectionBetween(a_x, a_z, b_x, b_z) * getRotationalDirectionBetween(a_x, a_z, c_x, c_z);

    b_z2 = arg1 - arg5;
    c_x2 = arg2 - arg4;
    b_x2 = arg0 - arg4;
    c_z2 = arg3 - arg5;
    a_x2 = arg6 - arg4;
    a_z2 = arg7 - arg5;


    val2 = getRotationalDirectionBetween(a_x2, a_z2, b_x2, b_z2) * getRotationalDirectionBetween(a_x2, a_z2, c_x2, c_z2);

    if (val1 >= arg8) {
        rc = 0;
    }

    if (val2 >= arg8) {
        rc = 0;
    }

    return rc;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B07BC
/* 0E52EC 7F0B07BC 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0E52F0 7F0B07C0 E7AC0068 */  swc1  $f12, 0x68($sp)
/* 0E52F4 7F0B07C4 AFA60070 */  sw    $a2, 0x70($sp)
/* 0E52F8 7F0B07C8 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0E52FC 7F0B07CC C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0E5300 7F0B07D0 E7AE006C */  swc1  $f14, 0x6c($sp)
/* 0E5304 7F0B07D4 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0E5308 7F0B07D8 46062301 */  sub.s $f12, $f4, $f6
/* 0E530C 7F0B07DC C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 0E5310 7F0B07E0 C7B00078 */  lwc1  $f16, 0x78($sp)
/* 0E5314 7F0B07E4 AFA70074 */  sw    $a3, 0x74($sp)
/* 0E5318 7F0B07E8 46045081 */  sub.s $f2, $f10, $f4
/* 0E531C 7F0B07EC C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0E5320 7F0B07F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E5324 7F0B07F4 46103001 */  sub.s $f0, $f6, $f16
/* 0E5328 7F0B07F8 240E0001 */  li    $t6, 1
/* 0E532C 7F0B07FC AFAE0044 */  sw    $t6, 0x44($sp)
/* 0E5330 7F0B0800 460A4381 */  sub.s $f14, $f8, $f10
/* 0E5334 7F0B0804 E7A00028 */  swc1  $f0, 0x28($sp)
/* 0E5338 7F0B0808 E7A20024 */  swc1  $f2, 0x24($sp)
/* 0E533C 7F0B080C 46001207 */  neg.s $f8, $f2
/* 0E5340 7F0B0810 46000487 */  neg.s $f18, $f0
/* 0E5344 7F0B0814 44074000 */  mfc1  $a3, $f8
/* 0E5348 7F0B0818 44069000 */  mfc1  $a2, $f18
/* 0E534C 7F0B081C E7AE001C */  swc1  $f14, 0x1c($sp)
/* 0E5350 7F0B0820 0FC2C170 */  jal   getRotationalDirectionBetween
/* 0E5354 7F0B0824 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 0E5358 7F0B0828 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0E535C 7F0B082C C7B00068 */  lwc1  $f16, 0x68($sp)
/* 0E5360 7F0B0830 C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 0E5364 7F0B0834 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 0E5368 7F0B0838 46103481 */  sub.s $f18, $f6, $f16
/* 0E536C 7F0B083C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 0E5370 7F0B0840 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 0E5374 7F0B0844 46045201 */  sub.s $f8, $f10, $f4
/* 0E5378 7F0B0848 44069000 */  mfc1  $a2, $f18
/* 0E537C 7F0B084C AFA2002C */  sw    $v0, 0x2c($sp)
/* 0E5380 7F0B0850 44074000 */  mfc1  $a3, $f8
/* 0E5384 7F0B0854 0FC2C170 */  jal   getRotationalDirectionBetween
/* 0E5388 7F0B0858 00000000 */   nop
/* 0E538C 7F0B085C 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0E5390 7F0B0860 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0E5394 7F0B0864 C7B00078 */  lwc1  $f16, 0x78($sp)
/* 0E5398 7F0B0868 004F0019 */  multu $v0, $t7
/* 0E539C 7F0B086C C7B20084 */  lwc1  $f18, 0x84($sp)
/* 0E53A0 7F0B0870 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0E53A4 7F0B0874 46103301 */  sub.s $f12, $f6, $f16
/* 0E53A8 7F0B0878 8FA60028 */  lw    $a2, 0x28($sp)
/* 0E53AC 7F0B087C 8FA70024 */  lw    $a3, 0x24($sp)
/* 0E53B0 7F0B0880 460A9381 */  sub.s $f14, $f18, $f10
/* 0E53B4 7F0B0884 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 0E53B8 7F0B0888 0000C012 */  mflo  $t8
/* 0E53BC 7F0B088C AFB8004C */  sw    $t8, 0x4c($sp)
/* 0E53C0 7F0B0890 0FC2C170 */  jal   getRotationalDirectionBetween
/* 0E53C4 7F0B0894 E7AE001C */   swc1  $f14, 0x1c($sp)
/* 0E53C8 7F0B0898 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0E53CC 7F0B089C C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0E53D0 7F0B08A0 C7B00074 */  lwc1  $f16, 0x74($sp)
/* 0E53D4 7F0B08A4 C7B2007C */  lwc1  $f18, 0x7c($sp)
/* 0E53D8 7F0B08A8 46082181 */  sub.s $f6, $f4, $f8
/* 0E53DC 7F0B08AC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 0E53E0 7F0B08B0 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 0E53E4 7F0B08B4 46128281 */  sub.s $f10, $f16, $f18
/* 0E53E8 7F0B08B8 44063000 */  mfc1  $a2, $f6
/* 0E53EC 7F0B08BC AFA2002C */  sw    $v0, 0x2c($sp)
/* 0E53F0 7F0B08C0 44075000 */  mfc1  $a3, $f10
/* 0E53F4 7F0B08C4 0FC2C170 */  jal   getRotationalDirectionBetween
/* 0E53F8 7F0B08C8 00000000 */   nop
/* 0E53FC 7F0B08CC 8FA30088 */  lw    $v1, 0x88($sp)
/* 0E5400 7F0B08D0 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0E5404 7F0B08D4 0323082A */  slt   $at, $t9, $v1
/* 0E5408 7F0B08D8 54200003 */  bnezl $at, .L7F0B08E8
/* 0E540C 7F0B08DC 8FA8002C */   lw    $t0, 0x2c($sp)
/* 0E5410 7F0B08E0 AFA00044 */  sw    $zero, 0x44($sp)
/* 0E5414 7F0B08E4 8FA8002C */  lw    $t0, 0x2c($sp)
.L7F0B08E8:
/* 0E5418 7F0B08E8 8FA40044 */  lw    $a0, 0x44($sp)
/* 0E541C 7F0B08EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E5420 7F0B08F0 00480019 */  multu $v0, $t0
/* 0E5424 7F0B08F4 27BD0068 */  addiu $sp, $sp, 0x68
/* 0E5428 7F0B08F8 00004812 */  mflo  $t1
/* 0E542C 7F0B08FC 0123082A */  slt   $at, $t1, $v1
/* 0E5430 7F0B0900 14200002 */  bnez  $at, .L7F0B090C
/* 0E5434 7F0B0904 00000000 */   nop
/* 0E5438 7F0B0908 00002025 */  move  $a0, $zero
.L7F0B090C:
/* 0E543C 7F0B090C 03E00008 */  jr    $ra
/* 0E5440 7F0B0910 00801025 */   move  $v0, $a0
)
#endif
#endif

#if !defined(LEFTOVERDEBUG)

s32 sub_GAME_7F0B07BC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    f32 a_z;
    f32 a_x;
    f32 b_z;
    f32 b_x;
    f32 c_x;

    s32 val2;
    s32 val1;
	f32 c_z;
    s32 rc;

    rc = 1;

    b_x = -(arg0 - arg4);
    b_z = -(arg1 - arg5);
	a_x = (arg2 - arg0);
    a_z = (arg3 - arg1);
    c_x = arg6 - arg0;
    c_z = arg7 - arg1;
    val1 = getRotationalDirectionBetween(a_x, a_z, b_x, b_z) * getRotationalDirectionBetween(a_x, a_z, c_x, c_z);

	a_x = (arg6 - arg4);
    a_z = (arg7 - arg5);
    b_x = (arg0 - arg4);
    b_z = (arg1 - arg5);
    c_x = arg2 - arg4;
    c_z = arg3 - arg5;

    val2 = getRotationalDirectionBetween(a_x, a_z, b_x, b_z) * getRotationalDirectionBetween(a_x, a_z, c_x, c_z);

    if (val1 >= arg8) {
        rc = 0;
    }

    if (val2 >= arg8) {
        rc = 0;
    }
    return rc;
}
#endif




// 'walkTilesBetweenPoints_withCallback'
// sig declared for caller matches
bool sub_GAME_7F0B0914(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z,
    standTileWalkCallback_t func, struct StandTileWalkCallbackRecord *funcData);


#ifdef NONMATCHING
bool sub_GAME_7F0B0914(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z,
    standTileWalkCallback_t func, struct StandTileWalkCallbackRecord *funcData)
{
     s32 sp8C;
    StandTile *tileStackTop;
    StandTile *temp_v0_2;
    StandTile *var_s0;
    StandTile *var_s3;
    StandTile *var_s6;
    StandTile *var_s7;
    f32 scaled_startX;
    f32 scaled_startZ;
    f32 scaled_destX;
    f32 scaled_destZ;
    f32 zDist;
    f32 xDist;
    s16 point2_z;
    s16 startpoint2_z;
    s16 point2_x;
    s16 startpoint2_x;
    s32 temp_s2;
    s32 temp_t5;
    s32 pointcount;
    s32 nextTile;
    s32 pointcount2;
    s32 var_fp;
    s32 var_s1;
    s32 var_s4;
    s32 trynexttile;
    u16 temp_v1;

    /*
    somewhere in here debug has
    */
    #ifdef DEBUG
    ossyncPrintf("{\"%s\",0x%08x,0x%08x,0x%08x,0x%08x},\t/* %8.3f %8.3f  %8.3f %8.3f */\n", GetStanRoomID(*tilestack),start_x,start_z,dest_x,dest_z,start_x,start_z);
    #endif


    scaled_startX = start_x * level_scale;
    scaled_startZ = start_z * level_scale;
    scaled_destX = dest_x * level_scale;
    scaled_destZ = dest_z * level_scale;
    tileStackTop = *tileStack;
    trynexttile = 0;
    sp8C = 0;
    zDist = -(scaled_destZ - scaled_startZ);
    xDist = scaled_destX - scaled_startX;
    var_s1 = 0;
    var_s4 = 0;
    var_fp = sp98;
    var_s3 = tileStackTop;
    var_s6 = tileStackTop;
    var_s7 = tileStackTop;

    while (true)
    {
        if (func != NULL)
        {
            func(var_s3, var_s6, funcData);
        }
        var_s0 = var_s3;
        pointcount = (var_s3->tail.half >> 0xC) & 0xF; //pointcount
        pointcount2 = pointcount;
        if (pointcount > 0)
        {
            do
            {
                temp_s2 = var_s1 + 1;
                temp_v0_2 = &var_s3[temp_s2 % pointcount2];
                point2_z = temp_v0_2->unkC;
                startpoint2_z = var_s0->unkC;
                point2_x = temp_v0_2->unk8;
                startpoint2_x = var_s0->unk8;
                if (((((point2_z - startpoint2_z) * xDist) + (zDist * (point2_x - startpoint2_x))) <= 0.0f) && (sub_GAME_7F0B07BC(scaled_startX, scaled_startZ, pointcount2, point2_z, scaled_destX, scaled_destZ, startpoint2_x, startpoint2_z, point2_x, point2_z, (var_s0->unkE >> 4) != 0) != 0))
                {
                    temp_v1 = var_s0->unkE;
                    var_s4 += 1;
                    nextTile = (temp_v1 * 8) + standTileStart;
                    if ((var_s6 != nextTile) && (var_s7 != nextTile))
                    {
                        var_fp = var_s1;
                        if ((temp_v1 >> 4) != 0)
                        {
                            trynexttile = nextTile;
                        }
                        else
                        {
                            trynexttile = NULL;
                        }
                    }
                }
                var_s1 = temp_s2;
                var_s0 += 8;
                temp_t5 = (var_s3->tail.half >> 0xC) & 0xF;
                pointcount2 = temp_t5;
            } while (temp_s2 < temp_t5);
        }
        var_s7 = var_s6;
        var_s6 = var_s3;
        var_s3 = trynexttile;
        //assert(intersections!=0);
        //assert(intersections!=3);
        //printf("sf: stanLineDo %d   %5.1f %5.1f %5.1f %5.1f  %s %s %s\n",3,start_x, start_z,dest_x,dest_z,GetStanRoomID(*tilestack),GetStanRoomID(puVar3));
        if ((var_s3 ^ trynexttile) == 0)
        {
            var_s4 = 0;
        }
        if (var_s4 == 0)
        {
            return TRUE;
        }
        sp8C += 1;
        if ((((sp8C < 0x1F5) ^ 1) != 0) || (trynexttile == 0) || (var_s1 = 0, (var_s4 == 0)))
        {
            stanSavedColl_tile = var_s6;
            stanSavedColl_pointI = var_fp;
            #ifdef DEBUG
            osSyncPrintf("stanLine: Looping; ret=0\n");
            #endif
            return FALSE;
        }
        *tileStack = trynexttile;
        var_s4 = 0;
    }
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B0914
/* 0E5444 7F0B0914 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0E5448 7F0B0918 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0E544C 7F0B091C 3C018004 */  lui   $at, %hi(level_scale)
/* 0E5450 7F0B0920 4485A000 */  mtc1  $a1, $f20
/* 0E5454 7F0B0924 C4200F44 */  lwc1  $f0, %lo(level_scale)($at)
/* 0E5458 7F0B0928 F7B60038 */  sdc1  $f22, 0x38($sp)
/* 0E545C 7F0B092C 4486B000 */  mtc1  $a2, $f22
/* 0E5460 7F0B0930 4600A502 */  mul.s $f20, $f20, $f0
/* 0E5464 7F0B0934 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 0E5468 7F0B0938 4487C000 */  mtc1  $a3, $f24
/* 0E546C 7F0B093C 4600B582 */  mul.s $f22, $f22, $f0
/* 0E5470 7F0B0940 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 0E5474 7F0B0944 C7BA00C8 */  lwc1  $f26, 0xc8($sp)
/* 0E5478 7F0B0948 4600C602 */  mul.s $f24, $f24, $f0
/* 0E547C 7F0B094C AFBF0084 */  sw    $ra, 0x84($sp)
/* 0E5480 7F0B0950 AFBE0080 */  sw    $fp, 0x80($sp)
/* 0E5484 7F0B0954 4600D682 */  mul.s $f26, $f26, $f0
/* 0E5488 7F0B0958 AFB7007C */  sw    $s7, 0x7c($sp)
/* 0E548C 7F0B095C AFB60078 */  sw    $s6, 0x78($sp)
/* 0E5490 7F0B0960 AFB50074 */  sw    $s5, 0x74($sp)
/* 0E5494 7F0B0964 AFB40070 */  sw    $s4, 0x70($sp)
/* 0E5498 7F0B0968 AFB3006C */  sw    $s3, 0x6c($sp)
/* 0E549C 7F0B096C AFB20068 */  sw    $s2, 0x68($sp)
/* 0E54A0 7F0B0970 AFB10064 */  sw    $s1, 0x64($sp)
/* 0E54A4 7F0B0974 AFB00060 */  sw    $s0, 0x60($sp)
/* 0E54A8 7F0B0978 F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 0E54AC 7F0B097C F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 0E54B0 7F0B0980 AFA400B8 */  sw    $a0, 0xb8($sp)
/* 0E54B4 7F0B0984 8C820000 */  lw    $v0, ($a0)
/* 0E54B8 7F0B0988 4616D701 */  sub.s $f28, $f26, $f22
/* 0E54BC 7F0B098C 00807025 */  move  $t6, $a0
/* 0E54C0 7F0B0990 0000A825 */  move  $s5, $zero
/* 0E54C4 7F0B0994 AFA0008C */  sw    $zero, 0x8c($sp)
/* 0E54C8 7F0B0998 4600E707 */  neg.s $f28, $f28
/* 0E54CC 7F0B099C 4614C781 */  sub.s $f30, $f24, $f20
/* 0E54D0 7F0B09A0 00008825 */  move  $s1, $zero
/* 0E54D4 7F0B09A4 0000A025 */  move  $s4, $zero
/* 0E54D8 7F0B09A8 8FBE0098 */  lw    $fp, 0x98($sp)
/* 0E54DC 7F0B09AC 00409825 */  move  $s3, $v0
/* 0E54E0 7F0B09B0 0040B025 */  move  $s6, $v0
/* 0E54E4 7F0B09B4 0040B825 */  move  $s7, $v0
.L7F0B09B8:
/* 0E54E8 7F0B09B8 8FAF00CC */  lw    $t7, 0xcc($sp)
/* 0E54EC 7F0B09BC 02602025 */  move  $a0, $s3
/* 0E54F0 7F0B09C0 51E00005 */  beql  $t7, $zero, .L7F0B09D8
/* 0E54F4 7F0B09C4 86640006 */   lh    $a0, 6($s3)
/* 0E54F8 7F0B09C8 02C02825 */  move  $a1, $s6
/* 0E54FC 7F0B09CC 01E0F809 */  jalr  $t7
/* 0E5500 7F0B09D0 8FA600D0 */  lw    $a2, 0xd0($sp)
/* 0E5504 7F0B09D4 86640006 */  lh    $a0, 6($s3)
.L7F0B09D8:
/* 0E5508 7F0B09D8 02608025 */  move  $s0, $s3
/* 0E550C 7F0B09DC 0004C303 */  sra   $t8, $a0, 0xc
/* 0E5510 7F0B09E0 3319000F */  andi  $t9, $t8, 0xf
/* 0E5514 7F0B09E4 1B200051 */  blez  $t9, .L7F0B0B2C
/* 0E5518 7F0B09E8 03202025 */   move  $a0, $t9
.L7F0B09EC:
/* 0E551C 7F0B09EC 26320001 */  addiu $s2, $s1, 1
/* 0E5520 7F0B09F0 0244001A */  div   $zero, $s2, $a0
/* 0E5524 7F0B09F4 00001810 */  mfhi  $v1
/* 0E5528 7F0B09F8 000358C0 */  sll   $t3, $v1, 3
/* 0E552C 7F0B09FC 026B1021 */  addu  $v0, $s3, $t3
/* 0E5530 7F0B0A00 8445000C */  lh    $a1, 0xc($v0)
/* 0E5534 7F0B0A04 8608000C */  lh    $t0, 0xc($s0)
/* 0E5538 7F0B0A08 84490008 */  lh    $t1, 8($v0)
/* 0E553C 7F0B0A0C 860A0008 */  lh    $t2, 8($s0)
/* 0E5540 7F0B0A10 00A86023 */  subu  $t4, $a1, $t0
/* 0E5544 7F0B0A14 448C3000 */  mtc1  $t4, $f6
/* 0E5548 7F0B0A18 012A6823 */  subu  $t5, $t1, $t2
/* 0E554C 7F0B0A1C 448D8000 */  mtc1  $t5, $f16
/* 0E5550 7F0B0A20 46803220 */  cvt.s.w $f8, $f6
/* 0E5554 7F0B0A24 44802000 */  mtc1  $zero, $f4
/* 0E5558 7F0B0A28 14800002 */  bnez  $a0, .L7F0B0A34
/* 0E555C 7F0B0A2C 00000000 */   nop
/* 0E5560 7F0B0A30 0007000D */  break 7
.L7F0B0A34:
/* 0E5564 7F0B0A34 2401FFFF */  li    $at, -1
/* 0E5568 7F0B0A38 14810004 */  bne   $a0, $at, .L7F0B0A4C
/* 0E556C 7F0B0A3C 3C018000 */   lui   $at, 0x8000
/* 0E5570 7F0B0A40 16410002 */  bne   $s2, $at, .L7F0B0A4C
/* 0E5574 7F0B0A44 00000000 */   nop
/* 0E5578 7F0B0A48 0006000D */  break 6
.L7F0B0A4C:
/* 0E557C 7F0B0A4C 468084A0 */  cvt.s.w $f18, $f16
/* 0E5580 7F0B0A50 461E4282 */  mul.s $f10, $f8, $f30
/* 0E5584 7F0B0A54 00000000 */  nop
/* 0E5588 7F0B0A58 4612E182 */  mul.s $f6, $f28, $f18
/* 0E558C 7F0B0A5C 46065200 */  add.s $f8, $f10, $f6
/* 0E5590 7F0B0A60 4604403E */  c.le.s $f8, $f4
/* 0E5594 7F0B0A64 00000000 */  nop
/* 0E5598 7F0B0A68 45000028 */  bc1f  .L7F0B0B0C
/* 0E559C 7F0B0A6C 00000000 */   nop
/* 0E55A0 7F0B0A70 448A8000 */  mtc1  $t2, $f16
/* 0E55A4 7F0B0A74 44885000 */  mtc1  $t0, $f10
/* 0E55A8 7F0B0A78 44892000 */  mtc1  $t1, $f4
/* 0E55AC 7F0B0A7C 468084A0 */  cvt.s.w $f18, $f16
/* 0E55B0 7F0B0A80 44858000 */  mtc1  $a1, $f16
/* 0E55B4 7F0B0A84 9602000E */  lhu   $v0, 0xe($s0)
/* 0E55B8 7F0B0A88 4406C000 */  mfc1  $a2, $f24
/* 0E55BC 7F0B0A8C 4407D000 */  mfc1  $a3, $f26
/* 0E55C0 7F0B0A90 468051A0 */  cvt.s.w $f6, $f10
/* 0E55C4 7F0B0A94 E7B20010 */  swc1  $f18, 0x10($sp)
/* 0E55C8 7F0B0A98 00027103 */  sra   $t6, $v0, 4
/* 0E55CC 7F0B0A9C 000E782B */  sltu  $t7, $zero, $t6
/* 0E55D0 7F0B0AA0 AFAF0020 */  sw    $t7, 0x20($sp)
/* 0E55D4 7F0B0AA4 46802220 */  cvt.s.w $f8, $f4
/* 0E55D8 7F0B0AA8 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0E55DC 7F0B0AAC 4600A306 */  mov.s $f12, $f20
/* 0E55E0 7F0B0AB0 4600B386 */  mov.s $f14, $f22
/* 0E55E4 7F0B0AB4 468084A0 */  cvt.s.w $f18, $f16
/* 0E55E8 7F0B0AB8 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0E55EC 7F0B0ABC 0FC2C1EF */  jal   sub_GAME_7F0B07BC
/* 0E55F0 7F0B0AC0 E7B2001C */   swc1  $f18, 0x1c($sp)
/* 0E55F4 7F0B0AC4 50400012 */  beql  $v0, $zero, .L7F0B0B10
/* 0E55F8 7F0B0AC8 86640006 */   lh    $a0, 6($s3)
/* 0E55FC 7F0B0ACC 9603000E */  lhu   $v1, 0xe($s0)
/* 0E5600 7F0B0AD0 3C198004 */  lui   $t9, %hi(standTileStart)
/* 0E5604 7F0B0AD4 8F390F58 */  lw    $t9, %lo(standTileStart)($t9)
/* 0E5608 7F0B0AD8 0003C0C0 */  sll   $t8, $v1, 3
/* 0E560C 7F0B0ADC 26940001 */  addiu $s4, $s4, 1
/* 0E5610 7F0B0AE0 03191021 */  addu  $v0, $t8, $t9
/* 0E5614 7F0B0AE4 12C20009 */  beq   $s6, $v0, .L7F0B0B0C
/* 0E5618 7F0B0AE8 00000000 */   nop
/* 0E561C 7F0B0AEC 12E20007 */  beq   $s7, $v0, .L7F0B0B0C
/* 0E5620 7F0B0AF0 00000000 */   nop
/* 0E5624 7F0B0AF4 00035903 */  sra   $t3, $v1, 4
/* 0E5628 7F0B0AF8 11600003 */  beqz  $t3, .L7F0B0B08
/* 0E562C 7F0B0AFC 0220F025 */   move  $fp, $s1
/* 0E5630 7F0B0B00 10000002 */  b     .L7F0B0B0C
/* 0E5634 7F0B0B04 0040A825 */   move  $s5, $v0
.L7F0B0B08:
/* 0E5638 7F0B0B08 0000A825 */  move  $s5, $zero
.L7F0B0B0C:
/* 0E563C 7F0B0B0C 86640006 */  lh    $a0, 6($s3)
.L7F0B0B10:
/* 0E5640 7F0B0B10 02408825 */  move  $s1, $s2
/* 0E5644 7F0B0B14 26100008 */  addiu $s0, $s0, 8
/* 0E5648 7F0B0B18 00046303 */  sra   $t4, $a0, 0xc
/* 0E564C 7F0B0B1C 318D000F */  andi  $t5, $t4, 0xf
/* 0E5650 7F0B0B20 024D082A */  slt   $at, $s2, $t5
/* 0E5654 7F0B0B24 1420FFB1 */  bnez  $at, .L7F0B09EC
/* 0E5658 7F0B0B28 01A02025 */   move  $a0, $t5
.L7F0B0B2C:
/* 0E565C 7F0B0B2C 02C0B825 */  move  $s7, $s6
/* 0E5660 7F0B0B30 0260B025 */  move  $s6, $s3
/* 0E5664 7F0B0B34 02751026 */  xor   $v0, $s3, $s5
/* 0E5668 7F0B0B38 14400002 */  bnez  $v0, .L7F0B0B44
/* 0E566C 7F0B0B3C 02A09825 */   move  $s3, $s5
/* 0E5670 7F0B0B40 0000A025 */  move  $s4, $zero
.L7F0B0B44:
/* 0E5674 7F0B0B44 16800003 */  bnez  $s4, .L7F0B0B54
/* 0E5678 7F0B0B48 8FAE008C */   lw    $t6, 0x8c($sp)
/* 0E567C 7F0B0B4C 10000013 */  b     .L7F0B0B9C
/* 0E5680 7F0B0B50 24020001 */   li    $v0, 1
.L7F0B0B54:
/* 0E5684 7F0B0B54 29C201F5 */  slti  $v0, $t6, 0x1f5
/* 0E5688 7F0B0B58 38420001 */  xori  $v0, $v0, 1
/* 0E568C 7F0B0B5C 25CF0001 */  addiu $t7, $t6, 1
/* 0E5690 7F0B0B60 14400005 */  bnez  $v0, .L7F0B0B78
/* 0E5694 7F0B0B64 AFAF008C */   sw    $t7, 0x8c($sp)
/* 0E5698 7F0B0B68 12A00003 */  beqz  $s5, .L7F0B0B78
/* 0E569C 7F0B0B6C 8FB800B8 */   lw    $t8, 0xb8($sp)
/* 0E56A0 7F0B0B70 16800007 */  bnez  $s4, .L7F0B0B90
/* 0E56A4 7F0B0B74 00008825 */   move  $s1, $zero
.L7F0B0B78:
/* 0E56A8 7F0B0B78 3C018008 */  lui   $at, %hi(stanSavedColl_tile)
/* 0E56AC 7F0B0B7C AC36B9E4 */  sw    $s6, %lo(stanSavedColl_tile)($at)
/* 0E56B0 7F0B0B80 3C018008 */  lui   $at, %hi(stanSavedColl_pointI)
/* 0E56B4 7F0B0B84 AC3EB9E8 */  sw    $fp, %lo(stanSavedColl_pointI)($at)
/* 0E56B8 7F0B0B88 10000004 */  b     .L7F0B0B9C
/* 0E56BC 7F0B0B8C 00001025 */   move  $v0, $zero
.L7F0B0B90:
/* 0E56C0 7F0B0B90 AF150000 */  sw    $s5, ($t8)
/* 0E56C4 7F0B0B94 1000FF88 */  b     .L7F0B09B8
/* 0E56C8 7F0B0B98 0000A025 */   move  $s4, $zero
.L7F0B0B9C:
/* 0E56CC 7F0B0B9C 8FBF0084 */  lw    $ra, 0x84($sp)
/* 0E56D0 7F0B0BA0 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0E56D4 7F0B0BA4 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 0E56D8 7F0B0BA8 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 0E56DC 7F0B0BAC D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 0E56E0 7F0B0BB0 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 0E56E4 7F0B0BB4 D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 0E56E8 7F0B0BB8 8FB00060 */  lw    $s0, 0x60($sp)
/* 0E56EC 7F0B0BBC 8FB10064 */  lw    $s1, 0x64($sp)
/* 0E56F0 7F0B0BC0 8FB20068 */  lw    $s2, 0x68($sp)
/* 0E56F4 7F0B0BC4 8FB3006C */  lw    $s3, 0x6c($sp)
/* 0E56F8 7F0B0BC8 8FB40070 */  lw    $s4, 0x70($sp)
/* 0E56FC 7F0B0BCC 8FB50074 */  lw    $s5, 0x74($sp)
/* 0E5700 7F0B0BD0 8FB60078 */  lw    $s6, 0x78($sp)
/* 0E5704 7F0B0BD4 8FB7007C */  lw    $s7, 0x7c($sp)
/* 0E5708 7F0B0BD8 8FBE0080 */  lw    $fp, 0x80($sp)
/* 0E570C 7F0B0BDC 03E00008 */  jr    $ra
/* 0E5710 7F0B0BE0 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif



// 'walkTilesBetweenPoints_NoCallback'
/**
 * Address 0x7F0B0BE4.
*/
s32 walkTilesBetweenPoints_NoCallback(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z)
{
    return sub_GAME_7F0B0914(tileStack, start_x, start_z, dest_x, dest_z, 0, 0);
}




// 'walkTilesBetweenPoints_NotingRooms'
s32 sub_GAME_7F0B0C24(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z, s32 *roomBuffer, s32 *rtnCountSize, s32 maxBufSize)
{
    struct StandTileWalkCallbackRecord callbackData;
    s32 rtn;


    callbackData.roomBuf = roomBuffer;
    callbackData.count = 0;
    callbackData.bufMax = maxBufSize;
    callbackData.lastRoom = -1;

    rtn = sub_GAME_7F0B0914(tileStack, start_x, start_z, dest_x, dest_z, noteTileRoomIfDifferentToPrev, &callbackData);

    *rtnCountSize = callbackData.count;
    return rtn;
}



void noteTileRoomIfDifferentToPrev(StandTile *tile, StandTile *unused, struct StandTileWalkCallbackRecord *data)
{
    s32 newRoom;

    if (tile->room != data->lastRoom && data->count < data->bufMax)
    {
        newRoom = (s32)tile->room;
        *data->roomBuf = newRoom;
        data->lastRoom = newRoom;
        data->roomBuf += 1;
        data->count += 1;
    }

    return;
}




void noteTileRoomIfDifferentToPrev_2(StandTile *tile, StandTile *unused, struct StandTileWalkCallbackRecord *data) {
    noteTileRoomIfDifferentToPrev(tile, unused, data);
}






#ifdef NONMATCHING
// Not too close

s32 sub_GAME_7F0B0D0C(StandTile *tile, f32 start_x, f32 start_z, StandTile **tilePtr,
    f32 end_x, f32 end_z, s32 *roomBuf, s32 maxBufSize)
{
    s32 roomA;
    s32 roomB;
    s32 bufCount;
     StandTile* tileStack[2];   // unknown size
     StandTile* unkTile;


    bufCount = 0;
    tileStack[0] = tile;

    if (*tilePtr != 0x0) {

        roomA = tile->room;
        roomB = (*tilePtr)->room;

        if (roomA == roomB) {
            *roomBuf = roomA;
            return 1;
         }

        // function related to portals
        // funny & 0xFFs here which we can't reproduce
        if (FUN_7f0b8fd0(roomA & 0xFF, roomB & 0xFF) != 0) {
            *roomBuf = (s32)tile->room;
            roomBuf[1] = (s32)(*tilePtr)->room;
            return 2;
         }

     }

    if (sub_GAME_7F0B0C24(tileStack,start_x,start_z,end_x,end_z,
        roomBuf,&bufCount,maxBufSize) == 0 )
     {
        bufCount = 0;
     }
    else {
        if (maxBufSize < bufCount) {
            bufCount = maxBufSize;
        }

        // Not sure what's going on here.
        unkTile = *tilePtr;

        if (unkTile == 0) {
            *tilePtr = tileStack[0];
            unkTile = tileStack[0];
        }

        if (tileStack[0] != unkTile) {
            bufCount = 0;
            #ifdef DEBUG
            osSyncPrintf("stan %s(%d) != %s(%d) from=%s\n", GetStanRoomID(tileStack[0]), /*funcForTileNumber(tileStack[0])*/,GetStanRoomID(tile), /*funcForTileNumber(tile)*/,GetStanRoomID(roomBuf));
            #endif
        }
     }

    return bufCount;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B0D0C
/* 0E583C 7F0B0D0C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0E5840 7F0B0D10 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0E5844 7F0B0D14 AFB00028 */  sw    $s0, 0x28($sp)
/* 0E5848 7F0B0D18 AFA40048 */  sw    $a0, 0x48($sp)
/* 0E584C 7F0B0D1C AFA5004C */  sw    $a1, 0x4c($sp)
/* 0E5850 7F0B0D20 AFA60050 */  sw    $a2, 0x50($sp)
/* 0E5854 7F0B0D24 AFA40044 */  sw    $a0, 0x44($sp)
/* 0E5858 7F0B0D28 AFA00040 */  sw    $zero, 0x40($sp)
/* 0E585C 7F0B0D2C 8CE20000 */  lw    $v0, ($a3)
/* 0E5860 7F0B0D30 00E08025 */  move  $s0, $a3
/* 0E5864 7F0B0D34 50400016 */  beql  $v0, $zero, .L7F0B0D90
/* 0E5868 7F0B0D38 8FA30060 */   lw    $v1, 0x60($sp)
/* 0E586C 7F0B0D3C 90860003 */  lbu   $a2, 3($a0)
/* 0E5870 7F0B0D40 90470003 */  lbu   $a3, 3($v0)
/* 0E5874 7F0B0D44 8FA30060 */  lw    $v1, 0x60($sp)
/* 0E5878 7F0B0D48 24020001 */  li    $v0, 1
/* 0E587C 7F0B0D4C 14C70003 */  bne   $a2, $a3, .L7F0B0D5C
/* 0E5880 7F0B0D50 30C400FF */   andi  $a0, $a2, 0xff
/* 0E5884 7F0B0D54 1000002E */  b     .L7F0B0E10
/* 0E5888 7F0B0D58 AC660000 */   sw    $a2, ($v1)
.L7F0B0D5C:
/* 0E588C 7F0B0D5C 0FC2E3F4 */  jal   sub_GAME_7F0B8FD0
/* 0E5890 7F0B0D60 30E500FF */   andi  $a1, $a3, 0xff
/* 0E5894 7F0B0D64 10400009 */  beqz  $v0, .L7F0B0D8C
/* 0E5898 7F0B0D68 8FAF0048 */   lw    $t7, 0x48($sp)
/* 0E589C 7F0B0D6C 8FA30060 */  lw    $v1, 0x60($sp)
/* 0E58A0 7F0B0D70 91F80003 */  lbu   $t8, 3($t7)
/* 0E58A4 7F0B0D74 24020002 */  li    $v0, 2
/* 0E58A8 7F0B0D78 AC780000 */  sw    $t8, ($v1)
/* 0E58AC 7F0B0D7C 8E190000 */  lw    $t9, ($s0)
/* 0E58B0 7F0B0D80 93280003 */  lbu   $t0, 3($t9)
/* 0E58B4 7F0B0D84 10000022 */  b     .L7F0B0E10
/* 0E58B8 7F0B0D88 AC680004 */   sw    $t0, 4($v1)
.L7F0B0D8C:
/* 0E58BC 7F0B0D8C 8FA30060 */  lw    $v1, 0x60($sp)
.L7F0B0D90:
/* 0E58C0 7F0B0D90 C7A4005C */  lwc1  $f4, 0x5c($sp)
/* 0E58C4 7F0B0D94 8FAA0064 */  lw    $t2, 0x64($sp)
/* 0E58C8 7F0B0D98 27A90040 */  addiu $t1, $sp, 0x40
/* 0E58CC 7F0B0D9C AFA90018 */  sw    $t1, 0x18($sp)
/* 0E58D0 7F0B0DA0 27A40044 */  addiu $a0, $sp, 0x44
/* 0E58D4 7F0B0DA4 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0E58D8 7F0B0DA8 8FA60050 */  lw    $a2, 0x50($sp)
/* 0E58DC 7F0B0DAC 8FA70058 */  lw    $a3, 0x58($sp)
/* 0E58E0 7F0B0DB0 AFA30014 */  sw    $v1, 0x14($sp)
/* 0E58E4 7F0B0DB4 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0E58E8 7F0B0DB8 0FC2C309 */  jal   sub_GAME_7F0B0C24
/* 0E58EC 7F0B0DBC AFAA001C */   sw    $t2, 0x1c($sp)
/* 0E58F0 7F0B0DC0 14400003 */  bnez  $v0, .L7F0B0DD0
/* 0E58F4 7F0B0DC4 8FA30064 */   lw    $v1, 0x64($sp)
/* 0E58F8 7F0B0DC8 10000011 */  b     .L7F0B0E10
/* 0E58FC 7F0B0DCC 00001025 */   move  $v0, $zero
.L7F0B0DD0:
/* 0E5900 7F0B0DD0 8FAB0040 */  lw    $t3, 0x40($sp)
/* 0E5904 7F0B0DD4 006B082A */  slt   $at, $v1, $t3
/* 0E5908 7F0B0DD8 50200003 */  beql  $at, $zero, .L7F0B0DE8
/* 0E590C 7F0B0DDC 8E020000 */   lw    $v0, ($s0)
/* 0E5910 7F0B0DE0 AFA30040 */  sw    $v1, 0x40($sp)
/* 0E5914 7F0B0DE4 8E020000 */  lw    $v0, ($s0)
.L7F0B0DE8:
/* 0E5918 7F0B0DE8 54400004 */  bnezl $v0, .L7F0B0DFC
/* 0E591C 7F0B0DEC 8FAD0044 */   lw    $t5, 0x44($sp)
/* 0E5920 7F0B0DF0 8FA20044 */  lw    $v0, 0x44($sp)
/* 0E5924 7F0B0DF4 AE020000 */  sw    $v0, ($s0)
/* 0E5928 7F0B0DF8 8FAD0044 */  lw    $t5, 0x44($sp)
.L7F0B0DFC:
/* 0E592C 7F0B0DFC 51A20004 */  beql  $t5, $v0, .L7F0B0E10
/* 0E5930 7F0B0E00 8FA20040 */   lw    $v0, 0x40($sp)
/* 0E5934 7F0B0E04 10000002 */  b     .L7F0B0E10
/* 0E5938 7F0B0E08 00001025 */   move  $v0, $zero
/* 0E593C 7F0B0E0C 8FA20040 */  lw    $v0, 0x40($sp)
.L7F0B0E10:
/* 0E5940 7F0B0E10 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0E5944 7F0B0E14 8FB00028 */  lw    $s0, 0x28($sp)
/* 0E5948 7F0B0E18 27BD0048 */  addiu $sp, $sp, 0x48
/* 0E594C 7F0B0E1C 03E00008 */  jr    $ra
/* 0E5950 7F0B0E20 00000000 */   nop
)
#endif


/**
 * Can change global variables:
 *
 * - D_800413BC
 * - stanSavedColl_pntA
 * - stanSavedColl_pntB
 * - stanSavedColl_tile
 * - stanSavedColl_pointI
 * - stanSavedColl_posData
 *
 * US address 7F0B0E24.
 *
 * 'testLineUnobstructed'
*/
s32 stanTestLineUnobstructed(StandTile **pTile, f32 p_x, f32 p_z, f32 dest_x, f32 dest_z, s32 cdtypes, f32 unkHeight, f32 unkA, f32 unkB, f32 unkC)
{
    struct PropRecord *prop;
    s32 retval; // sp158
    StandTile *sp154; // sp154
    struct coord2d sp14C;
    struct coord2d sp144;
    f32 sp140;
    s32 point_index;
    struct coord2d sp134;
    struct coord2d sp12C;
    s32 loop_flag;
    s32 sp124; // sp124
    s32 padding;
    s32 spD0[0x14]; //spD0
    s32 spCC; // spCC
    s32 next;
    f32 spC4;
    f32 spC0;
    f32 temp_f0_2;
    s16 *spB8;
    struct rect4f *spB4; // spB4
    s32 numvertices0; // spB0
    //f32 unused2;
    s32 i;
    f32 temp_f0;
    f32 spA4;
    f32 spA0; // spA0
    f32 temp_f2;
    s32 already_set;

    sp140 = 1.0f;
    sp124 = 0;
    spCC = (unkA <= unkHeight);
    already_set = 0;

    sp154 = *pTile;
    sp14C.f[0] = p_x;
    sp14C.f[1] = p_z;
    sp144.f[0] = dest_x;
    sp144.f[1] = dest_z;

    retval = sub_GAME_7F0B0C24(&sp154, p_x, p_z, dest_x, dest_z, &spD0[0], &sp124, 0x14);


    if (sp124 > 0x14)
    {
        sp124 = 0x14;
    }

    if (retval == 0)
    {
        s32 padding[2];

        point_index = (stanSavedColl_pointI + 1) % (s32)((stanSavedColl_tile->tail.half >> 0xC) & 0xF);
        D_800413BC = 1;

        stanSavedColl_pntA.f[0] = (f32) stanSavedColl_tile->points[stanSavedColl_pointI].x * inv_level_scale;
        stanSavedColl_pntA.f[1] = (f32) stanSavedColl_tile->points[stanSavedColl_pointI].z * inv_level_scale;

        stanSavedColl_pntB.f[0] = (f32) stanSavedColl_tile->points[point_index].x * inv_level_scale;
        stanSavedColl_pntB.f[1] = (f32) stanSavedColl_tile->points[point_index].z * inv_level_scale;

        sp140 = calculateLineIntersectionFactor(&sp14C, &sp144, &stanSavedColl_pntA, &stanSavedColl_pntB);
    }
    else
    {
        //
    }

    stanSavedColl_posData = NULL;

    if (cdtypes != 0)
    {
        spD0[sp124] = -1;
        roomGetProps((s32 *)&spD0);

        for (spB8 = ptr_list_object_lookup_indices; *spB8 >= 0; spB8++)
        {
            prop = &pos_data_entry[*spB8];

            if (propIsOfCdType(prop, cdtypes) != 0)
            {
                chraiGetCollisionBounds(prop, &spB4, &numvertices0, &spA4, &spA0);

                if (numvertices0 > 0)
                {
                    for (i = 0; i < numvertices0; i++)
                    {
                        next = (i + 1) % numvertices0;

                        if (sub_GAME_7F0B0688(p_x, p_z, dest_x, dest_z, spB4->points[i].f[0], spB4->points[i].f[1], spB4->points[next].f[0], spB4->points[next].f[1]) != 0)
                        {
                            sp134.f[0] = spB4->points[i].f[0];
                            sp134.f[1] = spB4->points[i].f[1];
                            sp12C.f[0] = spB4->points[next].f[0];
                            sp12C.f[1] = spB4->points[next].f[1];

                            temp_f0 = calculateLineIntersectionFactor(&sp14C, &sp144, &sp134, &sp12C);

                            if (temp_f0 < sp140)
                            {
                                loop_flag = 1;

                                if (spCC != 0)
                                {
                                    if (already_set == 0)
                                    {
                                        already_set = 1;

                                        if (unkC <= unkB)
                                        {
                                            spC4 = unkB - unkHeight;
                                            spC0 = unkC - unkA;
                                        }
                                        else
                                        {
                                            if (sp140 < 1.0f)
                                            {
                                                dest_x -= p_x;
                                                dest_x *= sp140;
                                                dest_x = p_x + dest_x;

                                                dest_z -= p_z;
                                                dest_z *= sp140;
                                                dest_z = p_z + dest_z;
                                            }

                                            temp_f0_2 = stanGetPositionYValue(*pTile, p_x, p_z);
                                            unkHeight += temp_f0_2;
                                            unkA += temp_f0_2;
                                            temp_f2 = (stanGetPositionYValue(sp154, dest_x, dest_z) - temp_f0_2) / sp140;
                                            spC0 = temp_f2;
                                            spC4 = temp_f2;
                                        }
                                    }

                                    if ((spA4 <= ((spC0 * temp_f0) + unkA)) || (((spC4 * temp_f0) + unkHeight) <= spA0))
                                    {
                                        loop_flag = 0;
                                    }
                                }

                                if (loop_flag != 0)
                                {
                                    retval = 0;
                                    sp140 = temp_f0;
                                    D_800413BC = 1;
                                    stanSavedColl_pntA = sp134;
                                    stanSavedColl_pntB = sp12C;
                                    stanSavedColl_tile = NULL;
                                    stanSavedColl_pointI = 0;
                                    stanSavedColl_posData = prop;
                                    sp154 = NULL;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (sp154 == NULL)
    {
        sp154 = *pTile;

        dest_x -= p_x;
        dest_x *= sp140;
        dest_x = p_x + dest_x;

        dest_z -= p_z;
        dest_z *= sp140;
        dest_z = p_z + dest_z;
        /*stanlineret = */ walkTilesBetweenPoints_NoCallback(&sp154, p_x, p_z, dest_x, dest_z);
        #ifdef DEBUG
        assert(stanlineret==1)
        #endif
    }

    *pTile = sp154;
    stanSavedColl_someMin = sp140;

    return retval;
}





#ifdef NONMATCHING
void sub_GAME_7F0B1410(void) {
    //osSyncPrintf("stanLineDoor: %d rooms is more than %d\n");
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B1410
/* 0E5F40 7F0B1410 27BDFED8 */  addiu $sp, $sp, -0x128
/* 0E5F44 7F0B1414 F7BA0040 */  sdc1  $f26, 0x40($sp)
/* 0E5F48 7F0B1418 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 0E5F4C 7F0B141C F7B60030 */  sdc1  $f22, 0x30($sp)
/* 0E5F50 7F0B1420 4485B000 */  mtc1  $a1, $f22
/* 0E5F54 7F0B1424 4486C000 */  mtc1  $a2, $f24
/* 0E5F58 7F0B1428 4487D000 */  mtc1  $a3, $f26
/* 0E5F5C 7F0B142C F7BC0048 */  sdc1  $f28, 0x48($sp)
/* 0E5F60 7F0B1430 C7BC0138 */  lwc1  $f28, 0x138($sp)
/* 0E5F64 7F0B1434 AFB10054 */  sw    $s1, 0x54($sp)
/* 0E5F68 7F0B1438 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0E5F6C 7F0B143C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E5F70 7F0B1440 27B10098 */  addiu $s1, $sp, 0x98
/* 0E5F74 7F0B1444 AFBF0074 */  sw    $ra, 0x74($sp)
/* 0E5F78 7F0B1448 AFBE0070 */  sw    $fp, 0x70($sp)
/* 0E5F7C 7F0B144C 4481A000 */  mtc1  $at, $f20
/* 0E5F80 7F0B1450 AFA400F0 */  sw    $a0, 0xf0($sp)
/* 0E5F84 7F0B1454 27AE00EC */  addiu $t6, $sp, 0xec
/* 0E5F88 7F0B1458 240F0014 */  li    $t7, 20
/* 0E5F8C 7F0B145C 4405B000 */  mfc1  $a1, $f22
/* 0E5F90 7F0B1460 4406C000 */  mfc1  $a2, $f24
/* 0E5F94 7F0B1464 4407D000 */  mfc1  $a3, $f26
/* 0E5F98 7F0B1468 AFB7006C */  sw    $s7, 0x6c($sp)
/* 0E5F9C 7F0B146C AFB60068 */  sw    $s6, 0x68($sp)
/* 0E5FA0 7F0B1470 AFB50064 */  sw    $s5, 0x64($sp)
/* 0E5FA4 7F0B1474 AFB40060 */  sw    $s4, 0x60($sp)
/* 0E5FA8 7F0B1478 AFB3005C */  sw    $s3, 0x5c($sp)
/* 0E5FAC 7F0B147C AFB20058 */  sw    $s2, 0x58($sp)
/* 0E5FB0 7F0B1480 AFB00050 */  sw    $s0, 0x50($sp)
/* 0E5FB4 7F0B1484 0000F025 */  move  $fp, $zero
/* 0E5FB8 7F0B1488 AFAF001C */  sw    $t7, 0x1c($sp)
/* 0E5FBC 7F0B148C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0E5FC0 7F0B1490 27A400F0 */  addiu $a0, $sp, 0xf0
/* 0E5FC4 7F0B1494 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E5FC8 7F0B1498 AFA000EC */  sw    $zero, 0xec($sp)
/* 0E5FCC 7F0B149C 0FC2C309 */  jal   sub_GAME_7F0B0C24
/* 0E5FD0 7F0B14A0 E7BC0010 */   swc1  $f28, 0x10($sp)
/* 0E5FD4 7F0B14A4 8FA300EC */  lw    $v1, 0xec($sp)
/* 0E5FD8 7F0B14A8 2419FFFF */  li    $t9, -1
/* 0E5FDC 7F0B14AC 02202025 */  move  $a0, $s1
/* 0E5FE0 7F0B14B0 28610015 */  slti  $at, $v1, 0x15
/* 0E5FE4 7F0B14B4 54200003 */  bnezl $at, .L7F0B14C4
/* 0E5FE8 7F0B14B8 8FB8013C */   lw    $t8, 0x13c($sp)
/* 0E5FEC 7F0B14BC 24030014 */  li    $v1, 20
/* 0E5FF0 7F0B14C0 8FB8013C */  lw    $t8, 0x13c($sp)
.L7F0B14C4:
/* 0E5FF4 7F0B14C4 E7B60118 */  swc1  $f22, 0x118($sp)
/* 0E5FF8 7F0B14C8 E7B8011C */  swc1  $f24, 0x11c($sp)
/* 0E5FFC 7F0B14CC E7BA0110 */  swc1  $f26, 0x110($sp)
/* 0E6000 7F0B14D0 1300006A */  beqz  $t8, .L7F0B167C
/* 0E6004 7F0B14D4 E7BC0114 */   swc1  $f28, 0x114($sp)
/* 0E6008 7F0B14D8 00034080 */  sll   $t0, $v1, 2
/* 0E600C 7F0B14DC 02284821 */  addu  $t1, $s1, $t0
/* 0E6010 7F0B14E0 AD390000 */  sw    $t9, ($t1)
/* 0E6014 7F0B14E4 0FC0F8FF */  jal   roomGetProps
/* 0E6018 7F0B14E8 AFA300EC */   sw    $v1, 0xec($sp)
/* 0E601C 7F0B14EC 3C038007 */  lui   $v1, %hi(ptr_list_object_lookup_indices)
/* 0E6020 7F0B14F0 8C639C30 */  lw    $v1, %lo(ptr_list_object_lookup_indices)($v1)
/* 0E6024 7F0B14F4 27B700F8 */  addiu $s7, $sp, 0xf8
/* 0E6028 7F0B14F8 27B60100 */  addiu $s6, $sp, 0x100
/* 0E602C 7F0B14FC 84620000 */  lh    $v0, ($v1)
/* 0E6030 7F0B1500 27B50110 */  addiu $s5, $sp, 0x110
/* 0E6034 7F0B1504 27B40118 */  addiu $s4, $sp, 0x118
/* 0E6038 7F0B1508 0442005D */  bltzl $v0, .L7F0B1680
/* 0E603C 7F0B150C 8FBF0074 */   lw    $ra, 0x74($sp)
/* 0E6040 7F0B1510 AFA30094 */  sw    $v1, 0x94($sp)
/* 0E6044 7F0B1514 00025080 */  sll   $t2, $v0, 2
.L7F0B1518:
/* 0E6048 7F0B1518 01425023 */  subu  $t2, $t2, $v0
/* 0E604C 7F0B151C 000A5080 */  sll   $t2, $t2, 2
/* 0E6050 7F0B1520 01425021 */  addu  $t2, $t2, $v0
/* 0E6054 7F0B1524 3C0B8007 */  lui   $t3, %hi(pos_data_entry)
/* 0E6058 7F0B1528 256B9C38 */  addiu $t3, %lo(pos_data_entry) # addiu $t3, $t3, -0x63c8
/* 0E605C 7F0B152C 000A5080 */  sll   $t2, $t2, 2
/* 0E6060 7F0B1530 014B9821 */  addu  $s3, $t2, $t3
/* 0E6064 7F0B1534 02602025 */  move  $a0, $s3
/* 0E6068 7F0B1538 0FC0F694 */  jal   propIsOfCdType
/* 0E606C 7F0B153C 8FA5013C */   lw    $a1, 0x13c($sp)
/* 0E6070 7F0B1540 10400048 */  beqz  $v0, .L7F0B1664
/* 0E6074 7F0B1544 02602025 */   move  $a0, $s3
/* 0E6078 7F0B1548 27A50090 */  addiu $a1, $sp, 0x90
/* 0E607C 7F0B154C 0FC0F32C */  jal   chraiGetCollisionBoundsWithoutY
/* 0E6080 7F0B1550 27A6008C */   addiu $a2, $sp, 0x8c
/* 0E6084 7F0B1554 8FA2008C */  lw    $v0, 0x8c($sp)
/* 0E6088 7F0B1558 58400043 */  blezl $v0, .L7F0B1668
/* 0E608C 7F0B155C 8FA30094 */   lw    $v1, 0x94($sp)
/* 0E6090 7F0B1560 18400040 */  blez  $v0, .L7F0B1664
/* 0E6094 7F0B1564 00002825 */   move  $a1, $zero
/* 0E6098 7F0B1568 00008025 */  move  $s0, $zero
/* 0E609C 7F0B156C 8FAC008C */  lw    $t4, 0x8c($sp)
.L7F0B1570:
/* 0E60A0 7F0B1570 24B20001 */  addiu $s2, $a1, 1
/* 0E60A4 7F0B1574 8FAD0090 */  lw    $t5, 0x90($sp)
/* 0E60A8 7F0B1578 024C001A */  div   $zero, $s2, $t4
/* 0E60AC 7F0B157C 01B01821 */  addu  $v1, $t5, $s0
/* 0E60B0 7F0B1580 C4640000 */  lwc1  $f4, ($v1)
/* 0E60B4 7F0B1584 00001010 */  mfhi  $v0
/* 0E60B8 7F0B1588 000270C0 */  sll   $t6, $v0, 3
/* 0E60BC 7F0B158C E7A40010 */  swc1  $f4, 0x10($sp)
/* 0E60C0 7F0B1590 C4660004 */  lwc1  $f6, 4($v1)
/* 0E60C4 7F0B1594 01AE2021 */  addu  $a0, $t5, $t6
/* 0E60C8 7F0B1598 4406D000 */  mfc1  $a2, $f26
/* 0E60CC 7F0B159C E7A60014 */  swc1  $f6, 0x14($sp)
/* 0E60D0 7F0B15A0 C4880000 */  lwc1  $f8, ($a0)
/* 0E60D4 7F0B15A4 4407E000 */  mfc1  $a3, $f28
/* 0E60D8 7F0B15A8 15800002 */  bnez  $t4, .L7F0B15B4
/* 0E60DC 7F0B15AC 00000000 */   nop
/* 0E60E0 7F0B15B0 0007000D */  break 7
.L7F0B15B4:
/* 0E60E4 7F0B15B4 2401FFFF */  li    $at, -1
/* 0E60E8 7F0B15B8 15810004 */  bne   $t4, $at, .L7F0B15CC
/* 0E60EC 7F0B15BC 3C018000 */   lui   $at, 0x8000
/* 0E60F0 7F0B15C0 16410002 */  bne   $s2, $at, .L7F0B15CC
/* 0E60F4 7F0B15C4 00000000 */   nop
/* 0E60F8 7F0B15C8 0006000D */  break 6
.L7F0B15CC:
/* 0E60FC 7F0B15CC E7A80018 */  swc1  $f8, 0x18($sp)
/* 0E6100 7F0B15D0 C48A0004 */  lwc1  $f10, 4($a0)
/* 0E6104 7F0B15D4 00408825 */  move  $s1, $v0
/* 0E6108 7F0B15D8 4600B306 */  mov.s $f12, $f22
/* 0E610C 7F0B15DC 4600C386 */  mov.s $f14, $f24
/* 0E6110 7F0B15E0 0FC2C1A2 */  jal   sub_GAME_7F0B0688
/* 0E6114 7F0B15E4 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 0E6118 7F0B15E8 50400019 */  beql  $v0, $zero, .L7F0B1650
/* 0E611C 7F0B15EC 8FA2008C */   lw    $v0, 0x8c($sp)
/* 0E6120 7F0B15F0 8FAF0090 */  lw    $t7, 0x90($sp)
/* 0E6124 7F0B15F4 0011C0C0 */  sll   $t8, $s1, 3
/* 0E6128 7F0B15F8 02802025 */  move  $a0, $s4
/* 0E612C 7F0B15FC 01F01821 */  addu  $v1, $t7, $s0
/* 0E6130 7F0B1600 C4700000 */  lwc1  $f16, ($v1)
/* 0E6134 7F0B1604 01F81021 */  addu  $v0, $t7, $t8
/* 0E6138 7F0B1608 02A02825 */  move  $a1, $s5
/* 0E613C 7F0B160C E7B00100 */  swc1  $f16, 0x100($sp)
/* 0E6140 7F0B1610 C4720004 */  lwc1  $f18, 4($v1)
/* 0E6144 7F0B1614 02C03025 */  move  $a2, $s6
/* 0E6148 7F0B1618 02E03825 */  move  $a3, $s7
/* 0E614C 7F0B161C E7B20104 */  swc1  $f18, 0x104($sp)
/* 0E6150 7F0B1620 C4440000 */  lwc1  $f4, ($v0)
/* 0E6154 7F0B1624 E7A400F8 */  swc1  $f4, 0xf8($sp)
/* 0E6158 7F0B1628 C4460004 */  lwc1  $f6, 4($v0)
/* 0E615C 7F0B162C 0FC2CC80 */  jal   calculateLineIntersectionFactor
/* 0E6160 7F0B1630 E7A600FC */   swc1  $f6, 0xfc($sp)
/* 0E6164 7F0B1634 4614003C */  c.lt.s $f0, $f20
/* 0E6168 7F0B1638 00000000 */  nop
/* 0E616C 7F0B163C 45020004 */  bc1fl .L7F0B1650
/* 0E6170 7F0B1640 8FA2008C */   lw    $v0, 0x8c($sp)
/* 0E6174 7F0B1644 46000506 */  mov.s $f20, $f0
/* 0E6178 7F0B1648 0260F025 */  move  $fp, $s3
/* 0E617C 7F0B164C 8FA2008C */  lw    $v0, 0x8c($sp)
.L7F0B1650:
/* 0E6180 7F0B1650 02402825 */  move  $a1, $s2
/* 0E6184 7F0B1654 26100008 */  addiu $s0, $s0, 8
/* 0E6188 7F0B1658 0242082A */  slt   $at, $s2, $v0
/* 0E618C 7F0B165C 5420FFC4 */  bnezl $at, .L7F0B1570
/* 0E6190 7F0B1660 8FAC008C */   lw    $t4, 0x8c($sp)
.L7F0B1664:
/* 0E6194 7F0B1664 8FA30094 */  lw    $v1, 0x94($sp)
.L7F0B1668:
/* 0E6198 7F0B1668 84620002 */  lh    $v0, 2($v1)
/* 0E619C 7F0B166C 24630002 */  addiu $v1, $v1, 2
/* 0E61A0 7F0B1670 AFA30094 */  sw    $v1, 0x94($sp)
/* 0E61A4 7F0B1674 0443FFA8 */  bgezl $v0, .L7F0B1518
/* 0E61A8 7F0B1678 00025080 */   sll   $t2, $v0, 2
.L7F0B167C:
/* 0E61AC 7F0B167C 8FBF0074 */  lw    $ra, 0x74($sp)
.L7F0B1680:
/* 0E61B0 7F0B1680 03C01025 */  move  $v0, $fp
/* 0E61B4 7F0B1684 8FBE0070 */  lw    $fp, 0x70($sp)
/* 0E61B8 7F0B1688 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0E61BC 7F0B168C D7B60030 */  ldc1  $f22, 0x30($sp)
/* 0E61C0 7F0B1690 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 0E61C4 7F0B1694 D7BA0040 */  ldc1  $f26, 0x40($sp)
/* 0E61C8 7F0B1698 D7BC0048 */  ldc1  $f28, 0x48($sp)
/* 0E61CC 7F0B169C 8FB00050 */  lw    $s0, 0x50($sp)
/* 0E61D0 7F0B16A0 8FB10054 */  lw    $s1, 0x54($sp)
/* 0E61D4 7F0B16A4 8FB20058 */  lw    $s2, 0x58($sp)
/* 0E61D8 7F0B16A8 8FB3005C */  lw    $s3, 0x5c($sp)
/* 0E61DC 7F0B16AC 8FB40060 */  lw    $s4, 0x60($sp)
/* 0E61E0 7F0B16B0 8FB50064 */  lw    $s5, 0x64($sp)
/* 0E61E4 7F0B16B4 8FB60068 */  lw    $s6, 0x68($sp)
/* 0E61E8 7F0B16B8 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0E61EC 7F0B16BC 03E00008 */  jr    $ra
/* 0E61F0 7F0B16C0 27BD0128 */   addiu $sp, $sp, 0x128
)
#endif


f32 sub_GAME_7F0B16C4(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3)
{
    u32 stack[8];
    f32 result; //d

    result = sqrtf((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

    if (result == 0.0f)
    {
        return sqrtf((x3 - x2) * (x3 - x2) + (z3 - z2) * (z3 - z2));
    }
    #ifdef DEBUG
    assert(d>0.0F);
    #endif
    return ((z2 - z1) * (x3 - x1) + -(x2 - x1) * (z3 - z1)) / result;
}


f32 distBetweenPoints2d(f32 o_x,f32 o_z,f32 p_x,f32 p_z)
{
    p_x -= o_x;
    p_z -= o_z;
    return sqrtf(p_x * p_x + p_z * p_z);
}





bool sub_GAME_7F0B17E4(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3)
{
    f32 f0;
    f32 f2;
    f32 f16;
    f32 f18;

    x3 -= x1;
    z3 -= z1;

    f0 = x2 - x1;
    f2 = z2 - z1;

    f16 = x3 * f0 + z3 * f2;
    f18 = f0 * f0 + f2 * f2;

    return (f18 < f16 && f16 < 0) || (f16 > 0 && f16 < f18);
}





/**
 * Can change global variables
 * - D_800413BC
 * - stanSavedColl_pntA
 * - stanSavedColl_pntB
 * - stanSavedColl_tile
 * - stanSavedColl_pointI
 * - stanSavedColl_posData
 *
 * US address 7F0B18B8.
 * Perfect Dark cdTestVolume (from context)
*/
s32 stanTestVolume(StandTile **arg0, f32 arg1, f32 arg2, f32 arg3, s32 cdtypes, f32 arg5, f32 arg6)
{
    s32 i; // stack ??
    f32 var_f20; // stack ??
    f32 var_f24; // stack ??
    s32 temp_v0; // stack ??
    s32 next; // stack ??

    s32 sp108;
    f32 temp_f0;  // stack ??
    s16 *sp100;
    s32 spFC;
    struct PropRecord *prop; // no stack
    s32 spA8[0x14];
    struct rect4f *spA4;
    s32 numvertices0;  // spa0
    f32 temp_f0_3; // stack ??
    f32 temp_f0_2; // stack ??
    f32 sp94;
    f32 sp90;

    s32 padding1;
    s32 padding2;

    sp108 = (arg6 <= arg5);

    spFC = 0;

    temp_v0 = sub_GAME_7F0B21B0(arg0, arg1, arg2, arg3, &spA8[0], &spFC, 20);
    if (temp_v0 >= 0)
    {
        return temp_v0;
    }


    if (spFC > 20)
    {
        #ifdef DEBUG
            osSyncPrintf("stanCircleLegalXFObjTypeY: %d rooms is more than %d\n",spFC,20);
        #endif
        spFC = 20;
    }

    stanSavedColl_posData = NULL;

    if (cdtypes)
    {
        if (sp108)
        {
            temp_f0 = stanGetPositionYValue(*arg0, arg1, arg2);
            arg5 += temp_f0;
            arg6 += temp_f0;
        }

        spA8[spFC] = -1;
        roomGetProps(&spA8[0]);

        for (sp100 = ptr_list_object_lookup_indices; *sp100 >= 0; sp100++)
        {
            prop = &pos_data_entry[*sp100];

            if (propIsOfCdType(prop, cdtypes) != 0)
            {
                chraiGetCollisionBounds(prop, &spA4, &numvertices0, &sp94, &sp90);
                if ((numvertices0 > 0) && ((sp108 == 0) || ((sp90 <= arg5) && (arg6 <= sp94))))
                {
                    var_f24 = -1.0f;

                    i=0;
                    while(1)
                    {
                        next = (i + 1) % numvertices0;

                        var_f20 = sub_GAME_7F0B16C4(spA4->points[i].f[0], spA4->points[i].f[1], spA4->points[next].f[0], spA4->points[next].f[1], arg1, arg2);

                        if (var_f20 < 0.0f)
                        {
                            var_f20 = -var_f20;
                        }

                        if (var_f24 < var_f20)
                        {
                            temp_f0_2 = distBetweenPoints2d(spA4->points[i].f[0], spA4->points[i].f[1], arg1, arg2);
                            temp_f0_3 = distBetweenPoints2d(spA4->points[next].f[0], spA4->points[next].f[1], arg1, arg2);

                            if ((var_f20 < arg3)
                                && (
                                    (temp_f0_2 < arg3)
                                    || (temp_f0_3 < arg3)
                                    || (sub_GAME_7F0B17E4(spA4->points[i].f[0], spA4->points[i].f[1], spA4->points[next].f[0], spA4->points[next].f[1], arg1, arg2) != 0)))
                            {
                                D_800413BC = 1;
                                var_f24 = var_f20;

                                stanSavedColl_pntA.f[0] = spA4->points[i].f[0];
                                stanSavedColl_pntA.f[1] = spA4->points[i].f[1];
                                stanSavedColl_pntB.f[0] = spA4->points[next].f[0];
                                stanSavedColl_pntB.f[1] = spA4->points[next].f[1];
                                stanSavedColl_tile = NULL;
                                stanSavedColl_pointI = 0;
                                stanSavedColl_posData = prop;
                            }
                        }

                        if (next == 0)
                        {
                            break;
                        }

                        i = next;
                    }

                    if (var_f24 > -1.0f)
                    {
                        return 2;
                    }
                }
            }
        }
    }

    return -2;
}



//stanResetHits
void sub_GAME_7F0B1CC4(void) {
    stanSavedColl_tile = 0;
    stanSavedColl_pointI = 0;
    D_800413BC = 0;
}

StandTile *sub_GAME_7F0B1CE0(void)
{
    #ifdef DEBUG
        osSyncPrintf("Don\'t call stanCircleLegalHit()!\n");
    #endif
    return stanSavedColl_tile;
}

s32 sub_GAME_7F0B1CEC(void)
{
    #ifdef DEBUG
        osSyncPrintf("Don\'t call stanCircleLegalHitEdge()!\n");
    #endif

    return stanSavedColl_pointI;
}


// sig for caller matches
void getTileEdgePoints(StandTile *tile, s32 pointI, coord3d *currPntRtn, coord3d *nextPointRtn);

#ifdef NONMATCHING
// Not debugged at all - can't be far wrong though.
void getTileEdgePoints(StandTile *tile, s32 pointI, coord3d *currPntRtn, coord3d *nextPointRtn)
{
  StandTilePoint *tilePntA;
  StandTilePoint *tilePntB;
  s32 pointCount;

  tilePntA = &tile->points[pointI];

  currPntRtn->x = (f32)tilePntA->x * inv_level_scale;
  currPntRtn->y = (f32)tilePntA->y * inv_level_scale;
  currPntRtn->z = (f32)tilePntA->z * inv_level_scale;

  pointCount = STAN_POINT_COUNT(tile);
  tilePntB = &tile->points[(pointI + 1) % pointCount];


  nextPointRtn->x = (f32)tilePntB->x * inv_level_scale;
  nextPointRtn->y = (f32)tilePntB->y * inv_level_scale;
  nextPointRtn->z = (f32)tilePntB->z * inv_level_scale;

}
#else
GLOBAL_ASM(
.text
glabel getTileEdgePoints
/* 0E6828 7F0B1CF8 000570C0 */  sll   $t6, $a1, 3
/* 0E682C 7F0B1CFC 008E1021 */  addu  $v0, $a0, $t6
/* 0E6830 7F0B1D00 844F0008 */  lh    $t7, 8($v0)
/* 0E6834 7F0B1D04 3C018004 */  lui   $at, %hi(inv_level_scale)
/* 0E6838 7F0B1D08 C4200F48 */  lwc1  $f0, %lo(inv_level_scale)($at)
/* 0E683C 7F0B1D0C 448F2000 */  mtc1  $t7, $f4
/* 0E6840 7F0B1D10 24A80001 */  addiu $t0, $a1, 1
/* 0E6844 7F0B1D14 468021A0 */  cvt.s.w $f6, $f4
/* 0E6848 7F0B1D18 46003202 */  mul.s $f8, $f6, $f0
/* 0E684C 7F0B1D1C E4C80000 */  swc1  $f8, ($a2)
/* 0E6850 7F0B1D20 8458000A */  lh    $t8, 0xa($v0)
/* 0E6854 7F0B1D24 44985000 */  mtc1  $t8, $f10
/* 0E6858 7F0B1D28 00000000 */  nop
/* 0E685C 7F0B1D2C 46805420 */  cvt.s.w $f16, $f10
/* 0E6860 7F0B1D30 46008482 */  mul.s $f18, $f16, $f0
/* 0E6864 7F0B1D34 E4D20004 */  swc1  $f18, 4($a2)
/* 0E6868 7F0B1D38 8459000C */  lh    $t9, 0xc($v0)
/* 0E686C 7F0B1D3C 44992000 */  mtc1  $t9, $f4
/* 0E6870 7F0B1D40 00000000 */  nop
/* 0E6874 7F0B1D44 468021A0 */  cvt.s.w $f6, $f4
/* 0E6878 7F0B1D48 46003202 */  mul.s $f8, $f6, $f0
/* 0E687C 7F0B1D4C E4C80008 */  swc1  $f8, 8($a2)
/* 0E6880 7F0B1D50 84890006 */  lh    $t1, 6($a0)
/* 0E6884 7F0B1D54 00095303 */  sra   $t2, $t1, 0xc
/* 0E6888 7F0B1D58 314B000F */  andi  $t3, $t2, 0xf
/* 0E688C 7F0B1D5C 010B001A */  div   $zero, $t0, $t3
/* 0E6890 7F0B1D60 00002810 */  mfhi  $a1
/* 0E6894 7F0B1D64 000560C0 */  sll   $t4, $a1, 3
/* 0E6898 7F0B1D68 008C1021 */  addu  $v0, $a0, $t4
/* 0E689C 7F0B1D6C 844D0008 */  lh    $t5, 8($v0)
/* 0E68A0 7F0B1D70 15600002 */  bnez  $t3, .L7F0B1D7C
/* 0E68A4 7F0B1D74 00000000 */   nop
/* 0E68A8 7F0B1D78 0007000D */  break 7
.L7F0B1D7C:
/* 0E68AC 7F0B1D7C 2401FFFF */  li    $at, -1
/* 0E68B0 7F0B1D80 15610004 */  bne   $t3, $at, .L7F0B1D94
/* 0E68B4 7F0B1D84 3C018000 */   lui   $at, 0x8000
/* 0E68B8 7F0B1D88 15010002 */  bne   $t0, $at, .L7F0B1D94
/* 0E68BC 7F0B1D8C 00000000 */   nop
/* 0E68C0 7F0B1D90 0006000D */  break 6
.L7F0B1D94:
/* 0E68C4 7F0B1D94 448D5000 */  mtc1  $t5, $f10
/* 0E68C8 7F0B1D98 00000000 */  nop
/* 0E68CC 7F0B1D9C 46805420 */  cvt.s.w $f16, $f10
/* 0E68D0 7F0B1DA0 46008482 */  mul.s $f18, $f16, $f0
/* 0E68D4 7F0B1DA4 E4F20000 */  swc1  $f18, ($a3)
/* 0E68D8 7F0B1DA8 844E000A */  lh    $t6, 0xa($v0)
/* 0E68DC 7F0B1DAC 448E2000 */  mtc1  $t6, $f4
/* 0E68E0 7F0B1DB0 00000000 */  nop
/* 0E68E4 7F0B1DB4 468021A0 */  cvt.s.w $f6, $f4
/* 0E68E8 7F0B1DB8 46003202 */  mul.s $f8, $f6, $f0
/* 0E68EC 7F0B1DBC E4E80004 */  swc1  $f8, 4($a3)
/* 0E68F0 7F0B1DC0 844F000C */  lh    $t7, 0xc($v0)
/* 0E68F4 7F0B1DC4 448F5000 */  mtc1  $t7, $f10
/* 0E68F8 7F0B1DC8 00000000 */  nop
/* 0E68FC 7F0B1DCC 46805420 */  cvt.s.w $f16, $f10
/* 0E6900 7F0B1DD0 46008482 */  mul.s $f18, $f16, $f0
/* 0E6904 7F0B1DD4 03E00008 */  jr    $ra
/* 0E6908 7F0B1DD8 E4F20008 */   swc1  $f18, 8($a3)
)
#endif



#ifdef NONMATCHING
s32 sub_GAME_7F0B1DDC(void)
{
    #ifdef DEBUG
    if (cat>= 0x190)
    {
      osSyncPrintf("cat=%d !!!!!!!!!!!!!!!!!!!! NEED TO INCREASE ARRAY SIZE\n",cat);
    }
    #endif
    if (cat >= 0x320)
    {
      return 5; //error value?
    }
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B1DDC
/* 0E690C 7F0B1DDC 27BDFEB0 */  addiu $sp, $sp, -0x150
/* 0E6910 7F0B1DE0 F7BA0038 */  sdc1  $f26, 0x38($sp)
/* 0E6914 7F0B1DE4 3C018004 */  lui   $at, %hi(level_scale)
/* 0E6918 7F0B1DE8 4485D000 */  mtc1  $a1, $f26
/* 0E691C 7F0B1DEC C4200F44 */  lwc1  $f0, %lo(level_scale)($at)
/* 0E6920 7F0B1DF0 F7BC0040 */  sdc1  $f28, 0x40($sp)
/* 0E6924 7F0B1DF4 4486E000 */  mtc1  $a2, $f28
/* 0E6928 7F0B1DF8 4600D682 */  mul.s $f26, $f26, $f0
/* 0E692C 7F0B1DFC F7BE0048 */  sdc1  $f30, 0x48($sp)
/* 0E6930 7F0B1E00 4487F000 */  mtc1  $a3, $f30
/* 0E6934 7F0B1E04 4600E702 */  mul.s $f28, $f28, $f0
/* 0E6938 7F0B1E08 AFBF0074 */  sw    $ra, 0x74($sp)
/* 0E693C 7F0B1E0C AFBE0070 */  sw    $fp, 0x70($sp)
/* 0E6940 7F0B1E10 AFB7006C */  sw    $s7, 0x6c($sp)
/* 0E6944 7F0B1E14 AFB60068 */  sw    $s6, 0x68($sp)
/* 0E6948 7F0B1E18 AFB50064 */  sw    $s5, 0x64($sp)
/* 0E694C 7F0B1E1C AFB40060 */  sw    $s4, 0x60($sp)
/* 0E6950 7F0B1E20 AFB3005C */  sw    $s3, 0x5c($sp)
/* 0E6954 7F0B1E24 AFB20058 */  sw    $s2, 0x58($sp)
/* 0E6958 7F0B1E28 AFB10054 */  sw    $s1, 0x54($sp)
/* 0E695C 7F0B1E2C AFB00050 */  sw    $s0, 0x50($sp)
/* 0E6960 7F0B1E30 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0E6964 7F0B1E34 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0E6968 7F0B1E38 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0E696C 7F0B1E3C AFA000A4 */  sw    $zero, 0xa4($sp)
/* 0E6970 7F0B1E40 8C8E0000 */  lw    $t6, ($a0)
/* 0E6974 7F0B1E44 27AF00B0 */  addiu $t7, $sp, 0xb0
/* 0E6978 7F0B1E48 4600F782 */  mul.s $f30, $f30, $f0
/* 0E697C 7F0B1E4C 24140001 */  li    $s4, 1
/* 0E6980 7F0B1E50 AFAF0084 */  sw    $t7, 0x84($sp)
/* 0E6984 7F0B1E54 27B200B0 */  addiu $s2, $sp, 0xb0
/* 0E6988 7F0B1E58 8FB60164 */  lw    $s6, 0x164($sp)
/* 0E698C 7F0B1E5C 8FB7016C */  lw    $s7, 0x16c($sp)
/* 0E6990 7F0B1E60 8FBE0168 */  lw    $fp, 0x168($sp)
/* 0E6994 7F0B1E64 AFAE00B0 */  sw    $t6, 0xb0($sp)
/* 0E6998 7F0B1E68 8FB80084 */  lw    $t8, 0x84($sp)
.L7F0B1E6C:
/* 0E699C 7F0B1E6C 8FB900A4 */  lw    $t9, 0xa4($sp)
/* 0E69A0 7F0B1E70 8FAA0160 */  lw    $t2, 0x160($sp)
/* 0E69A4 7F0B1E74 8F130000 */  lw    $s3, ($t8)
/* 0E69A8 7F0B1E78 27090004 */  addiu $t1, $t8, 4
/* 0E69AC 7F0B1E7C 27280001 */  addiu $t0, $t9, 1
/* 0E69B0 7F0B1E80 AFA800A4 */  sw    $t0, 0xa4($sp)
/* 0E69B4 7F0B1E84 AFA90084 */  sw    $t1, 0x84($sp)
/* 0E69B8 7F0B1E88 11400004 */  beqz  $t2, .L7F0B1E9C
/* 0E69BC 7F0B1E8C 00008025 */   move  $s0, $zero
/* 0E69C0 7F0B1E90 02602025 */  move  $a0, $s3
/* 0E69C4 7F0B1E94 0140F809 */  jalr  $t2
/* 0E69C8 7F0B1E98 02E02825 */  move  $a1, $s7
.L7F0B1E9C:
/* 0E69CC 7F0B1E9C 86620006 */  lh    $v0, 6($s3)
/* 0E69D0 7F0B1EA0 00025B03 */  sra   $t3, $v0, 0xc
/* 0E69D4 7F0B1EA4 316C000F */  andi  $t4, $t3, 0xf
/* 0E69D8 7F0B1EA8 19800069 */  blez  $t4, .L7F0B2050
/* 0E69DC 7F0B1EAC 01801025 */   move  $v0, $t4
.L7F0B1EB0:
/* 0E69E0 7F0B1EB0 26150001 */  addiu $s5, $s0, 1
/* 0E69E4 7F0B1EB4 02A2001A */  div   $zero, $s5, $v0
/* 0E69E8 7F0B1EB8 00008810 */  mfhi  $s1
/* 0E69EC 7F0B1EBC 4406D000 */  mfc1  $a2, $f26
/* 0E69F0 7F0B1EC0 14400002 */  bnez  $v0, .L7F0B1ECC
/* 0E69F4 7F0B1EC4 00000000 */   nop
/* 0E69F8 7F0B1EC8 0007000D */  break 7
.L7F0B1ECC:
/* 0E69FC 7F0B1ECC 2401FFFF */  li    $at, -1
/* 0E6A00 7F0B1ED0 14410004 */  bne   $v0, $at, .L7F0B1EE4
/* 0E6A04 7F0B1ED4 3C018000 */   lui   $at, 0x8000
/* 0E6A08 7F0B1ED8 16A10002 */  bne   $s5, $at, .L7F0B1EE4
/* 0E6A0C 7F0B1EDC 00000000 */   nop
/* 0E6A10 7F0B1EE0 0006000D */  break 6
.L7F0B1EE4:
/* 0E6A14 7F0B1EE4 4407E000 */  mfc1  $a3, $f28
/* 0E6A18 7F0B1EE8 02602025 */  move  $a0, $s3
/* 0E6A1C 7F0B1EEC 0FC2BF47 */  jal   getShortest2dDispToInfTileEdge
/* 0E6A20 7F0B1EF0 02002825 */   move  $a1, $s0
/* 0E6A24 7F0B1EF4 4406D000 */  mfc1  $a2, $f26
/* 0E6A28 7F0B1EF8 4407E000 */  mfc1  $a3, $f28
/* 0E6A2C 7F0B1EFC 46000586 */  mov.s $f22, $f0
/* 0E6A30 7F0B1F00 02602025 */  move  $a0, $s3
/* 0E6A34 7F0B1F04 0FC2C019 */  jal   distToTilePnt2D
/* 0E6A38 7F0B1F08 02002825 */   move  $a1, $s0
/* 0E6A3C 7F0B1F0C 4406D000 */  mfc1  $a2, $f26
/* 0E6A40 7F0B1F10 4407E000 */  mfc1  $a3, $f28
/* 0E6A44 7F0B1F14 46000506 */  mov.s $f20, $f0
/* 0E6A48 7F0B1F18 02602025 */  move  $a0, $s3
/* 0E6A4C 7F0B1F1C 0FC2C019 */  jal   distToTilePnt2D
/* 0E6A50 7F0B1F20 02202825 */   move  $a1, $s1
/* 0E6A54 7F0B1F24 461EB03C */  c.lt.s $f22, $f30
/* 0E6A58 7F0B1F28 46000606 */  mov.s $f24, $f0
/* 0E6A5C 7F0B1F2C 45020042 */  bc1fl .L7F0B2038
/* 0E6A60 7F0B1F30 86620006 */   lh    $v0, 6($s3)
/* 0E6A64 7F0B1F34 461EA03C */  c.lt.s $f20, $f30
/* 0E6A68 7F0B1F38 00000000 */  nop
/* 0E6A6C 7F0B1F3C 4501000B */  bc1t  .L7F0B1F6C
/* 0E6A70 7F0B1F40 00000000 */   nop
/* 0E6A74 7F0B1F44 461E003C */  c.lt.s $f0, $f30
/* 0E6A78 7F0B1F48 02602025 */  move  $a0, $s3
/* 0E6A7C 7F0B1F4C 45010007 */  bc1t  .L7F0B1F6C
/* 0E6A80 7F0B1F50 00000000 */   nop
/* 0E6A84 7F0B1F54 4406D000 */  mfc1  $a2, $f26
/* 0E6A88 7F0B1F58 4407E000 */  mfc1  $a3, $f28
/* 0E6A8C 7F0B1F5C 0FC2C066 */  jal   sub_GAME_7F0B0198
/* 0E6A90 7F0B1F60 02002825 */   move  $a1, $s0
/* 0E6A94 7F0B1F64 50400034 */  beql  $v0, $zero, .L7F0B2038
/* 0E6A98 7F0B1F68 86620006 */   lh    $v0, 6($s3)
.L7F0B1F6C:
/* 0E6A9C 7F0B1F6C 12C00008 */  beqz  $s6, .L7F0B1F90
/* 0E6AA0 7F0B1F70 02602025 */   move  $a0, $s3
/* 0E6AA4 7F0B1F74 4406B000 */  mfc1  $a2, $f22
/* 0E6AA8 7F0B1F78 4407A000 */  mfc1  $a3, $f20
/* 0E6AAC 7F0B1F7C 02002825 */  move  $a1, $s0
/* 0E6AB0 7F0B1F80 E7B80010 */  swc1  $f24, 0x10($sp)
/* 0E6AB4 7F0B1F84 02C0F809 */  jalr  $s6
/* 0E6AB8 7F0B1F88 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E6ABC 7F0B1F8C 1440001B */  bnez  $v0, .L7F0B1FFC
.L7F0B1F90:
/* 0E6AC0 7F0B1F90 001068C0 */   sll   $t5, $s0, 3
/* 0E6AC4 7F0B1F94 026D7021 */  addu  $t6, $s3, $t5
/* 0E6AC8 7F0B1F98 95C4000E */  lhu   $a0, 0xe($t6)
/* 0E6ACC 7F0B1F9C 3C088004 */  lui   $t0, %hi(standTileStart)
/* 0E6AD0 7F0B1FA0 2682FFFF */  addiu $v0, $s4, -1
/* 0E6AD4 7F0B1FA4 00047903 */  sra   $t7, $a0, 4
/* 0E6AD8 7F0B1FA8 11E00014 */  beqz  $t7, .L7F0B1FFC
/* 0E6ADC 7F0B1FAC 0004C8C0 */   sll   $t9, $a0, 3
/* 0E6AE0 7F0B1FB0 8D080F58 */  lw    $t0, %lo(standTileStart)($t0)
/* 0E6AE4 7F0B1FB4 00402825 */  move  $a1, $v0
/* 0E6AE8 7F0B1FB8 0440000B */  bltz  $v0, .L7F0B1FE8
/* 0E6AEC 7F0B1FBC 03281821 */   addu  $v1, $t9, $t0
/* 0E6AF0 7F0B1FC0 0002C080 */  sll   $t8, $v0, 2
/* 0E6AF4 7F0B1FC4 27A900B0 */  addiu $t1, $sp, 0xb0
/* 0E6AF8 7F0B1FC8 03091021 */  addu  $v0, $t8, $t1
/* 0E6AFC 7F0B1FCC 8C4A0000 */  lw    $t2, ($v0)
.L7F0B1FD0:
/* 0E6B00 7F0B1FD0 2442FFFC */  addiu $v0, $v0, -4
/* 0E6B04 7F0B1FD4 0052082B */  sltu  $at, $v0, $s2
/* 0E6B08 7F0B1FD8 506A0017 */  beql  $v1, $t2, .L7F0B2038
/* 0E6B0C 7F0B1FDC 86620006 */   lh    $v0, 6($s3)
/* 0E6B10 7F0B1FE0 5020FFFB */  beql  $at, $zero, .L7F0B1FD0
/* 0E6B14 7F0B1FE4 8C4A0000 */   lw    $t2, ($v0)
.L7F0B1FE8:
/* 0E6B18 7F0B1FE8 00145880 */  sll   $t3, $s4, 2
/* 0E6B1C 7F0B1FEC 03AB6021 */  addu  $t4, $sp, $t3
/* 0E6B20 7F0B1FF0 AD8300B0 */  sw    $v1, 0xb0($t4)
/* 0E6B24 7F0B1FF4 1000000F */  b     .L7F0B2034
/* 0E6B28 7F0B1FF8 26940001 */   addiu $s4, $s4, 1
.L7F0B1FFC:
/* 0E6B2C 7F0B1FFC 3C018008 */  lui   $at, %hi(stanSavedColl_tile)
/* 0E6B30 7F0B2000 AC33B9E4 */  sw    $s3, %lo(stanSavedColl_tile)($at)
/* 0E6B34 7F0B2004 3C018008 */  lui   $at, %hi(stanSavedColl_pointI)
/* 0E6B38 7F0B2008 13C00008 */  beqz  $fp, .L7F0B202C
/* 0E6B3C 7F0B200C AC30B9E8 */   sw    $s0, %lo(stanSavedColl_pointI)($at)
/* 0E6B40 7F0B2010 27A400B0 */  addiu $a0, $sp, 0xb0
/* 0E6B44 7F0B2014 02802825 */  move  $a1, $s4
/* 0E6B48 7F0B2018 03C0F809 */  jalr  $fp
/* 0E6B4C 7F0B201C 02E03025 */  move  $a2, $s7
/* 0E6B50 7F0B2020 24010001 */  li    $at, 1
/* 0E6B54 7F0B2024 50410004 */  beql  $v0, $at, .L7F0B2038
/* 0E6B58 7F0B2028 86620006 */   lh    $v0, 6($s3)
.L7F0B202C:
/* 0E6B5C 7F0B202C 10000016 */  b     .L7F0B2088
/* 0E6B60 7F0B2030 24020002 */   li    $v0, 2
.L7F0B2034:
/* 0E6B64 7F0B2034 86620006 */  lh    $v0, 6($s3)
.L7F0B2038:
/* 0E6B68 7F0B2038 02A08025 */  move  $s0, $s5
/* 0E6B6C 7F0B203C 00026B03 */  sra   $t5, $v0, 0xc
/* 0E6B70 7F0B2040 31AE000F */  andi  $t6, $t5, 0xf
/* 0E6B74 7F0B2044 02AE082A */  slt   $at, $s5, $t6
/* 0E6B78 7F0B2048 1420FF99 */  bnez  $at, .L7F0B1EB0
/* 0E6B7C 7F0B204C 01C01025 */   move  $v0, $t6
.L7F0B2050:
/* 0E6B80 7F0B2050 2E810029 */  sltiu $at, $s4, 0x29
/* 0E6B84 7F0B2054 14200003 */  bnez  $at, .L7F0B2064
/* 0E6B88 7F0B2058 8FAF00A4 */   lw    $t7, 0xa4($sp)
/* 0E6B8C 7F0B205C 1000000A */  b     .L7F0B2088
/* 0E6B90 7F0B2060 24020005 */   li    $v0, 5
.L7F0B2064:
/* 0E6B94 7F0B2064 01F4082A */  slt   $at, $t7, $s4
/* 0E6B98 7F0B2068 5420FF80 */  bnezl $at, .L7F0B1E6C
/* 0E6B9C 7F0B206C 8FB80084 */   lw    $t8, 0x84($sp)
/* 0E6BA0 7F0B2070 13C00004 */  beqz  $fp, .L7F0B2084
/* 0E6BA4 7F0B2074 27A400B0 */   addiu $a0, $sp, 0xb0
/* 0E6BA8 7F0B2078 02802825 */  move  $a1, $s4
/* 0E6BAC 7F0B207C 03C0F809 */  jalr  $fp
/* 0E6BB0 7F0B2080 02E03025 */  move  $a2, $s7
.L7F0B2084:
/* 0E6BB4 7F0B2084 2402FFFE */  li    $v0, -2
.L7F0B2088:
/* 0E6BB8 7F0B2088 8FBF0074 */  lw    $ra, 0x74($sp)
/* 0E6BBC 7F0B208C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0E6BC0 7F0B2090 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0E6BC4 7F0B2094 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0E6BC8 7F0B2098 D7BA0038 */  ldc1  $f26, 0x38($sp)
/* 0E6BCC 7F0B209C D7BC0040 */  ldc1  $f28, 0x40($sp)
/* 0E6BD0 7F0B20A0 D7BE0048 */  ldc1  $f30, 0x48($sp)
/* 0E6BD4 7F0B20A4 8FB00050 */  lw    $s0, 0x50($sp)
/* 0E6BD8 7F0B20A8 8FB10054 */  lw    $s1, 0x54($sp)
/* 0E6BDC 7F0B20AC 8FB20058 */  lw    $s2, 0x58($sp)
/* 0E6BE0 7F0B20B0 8FB3005C */  lw    $s3, 0x5c($sp)
/* 0E6BE4 7F0B20B4 8FB40060 */  lw    $s4, 0x60($sp)
/* 0E6BE8 7F0B20B8 8FB50064 */  lw    $s5, 0x64($sp)
/* 0E6BEC 7F0B20BC 8FB60068 */  lw    $s6, 0x68($sp)
/* 0E6BF0 7F0B20C0 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0E6BF4 7F0B20C4 8FBE0070 */  lw    $fp, 0x70($sp)
/* 0E6BF8 7F0B20C8 03E00008 */  jr    $ra
/* 0E6BFC 7F0B20CC 27BD0150 */   addiu $sp, $sp, 0x150
)
#endif




s32 sub_GAME_7F0B20D0(StandTile **tileStack, f32 target_x, f32 target_z, f32 unknown) {
    return sub_GAME_7F0B1DDC(tileStack, target_x, target_z, unknown, NULL, NULL, NULL, NULL);
}




#ifdef NONMATCHING

// Regalloc and a little reordering to solve, but there just seems to be nothing to work with in the loop.
// Indexing roomBuf makes sense and generates closer code.
// 'addTileRoomIfNew'
s32 sub_GAME_7F0B2110(StandTile *tile, struct StandTileLocusCallbackRecord* data)
{
    s32 i;
    s32 room;

    for (i = 0; i < data->count; i++)
    {
        if (data->roomBuf[i] == tile->room) {
            return 0;
        }
    }

    if (data->count < data->bufMax) {
        data->roomBuf[data->count] = tile->room;
        data->count++;
    }

    return 0;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B2110
/* 0E6C40 7F0B2110 8CA60004 */  lw    $a2, 4($a1)
/* 0E6C44 7F0B2114 00A01025 */  move  $v0, $a1
/* 0E6C48 7F0B2118 00001825 */  move  $v1, $zero
/* 0E6C4C 7F0B211C 58C0000F */  blezl $a2, .L7F0B215C
/* 0E6C50 7F0B2120 8CB80008 */   lw    $t8, 8($a1)
/* 0E6C54 7F0B2124 90870003 */  lbu   $a3, 3($a0)
/* 0E6C58 7F0B2128 8CA80000 */  lw    $t0, ($a1)
/* 0E6C5C 7F0B212C 8D0E0000 */  lw    $t6, ($t0)
.L7F0B2130:
/* 0E6C60 7F0B2130 54EE0004 */  bnel  $a3, $t6, .L7F0B2144
/* 0E6C64 7F0B2134 8C4F0004 */   lw    $t7, 4($v0)
/* 0E6C68 7F0B2138 03E00008 */  jr    $ra
/* 0E6C6C 7F0B213C 00001025 */   move  $v0, $zero

/* 0E6C70 7F0B2140 8C4F0004 */  lw    $t7, 4($v0)
.L7F0B2144:
/* 0E6C74 7F0B2144 24630001 */  addiu $v1, $v1, 1
/* 0E6C78 7F0B2148 25080004 */  addiu $t0, $t0, 4
/* 0E6C7C 7F0B214C 006F082A */  slt   $at, $v1, $t7
/* 0E6C80 7F0B2150 5420FFF7 */  bnezl $at, .L7F0B2130
/* 0E6C84 7F0B2154 8D0E0000 */   lw    $t6, ($t0)
/* 0E6C88 7F0B2158 8CB80008 */  lw    $t8, 8($a1)
.L7F0B215C:
/* 0E6C8C 7F0B215C 00001025 */  move  $v0, $zero
/* 0E6C90 7F0B2160 00D8082A */  slt   $at, $a2, $t8
/* 0E6C94 7F0B2164 10200009 */  beqz  $at, .L7F0B218C
/* 0E6C98 7F0B2168 00000000 */   nop
/* 0E6C9C 7F0B216C 8CA90000 */  lw    $t1, ($a1)
/* 0E6CA0 7F0B2170 90990003 */  lbu   $t9, 3($a0)
/* 0E6CA4 7F0B2174 00065080 */  sll   $t2, $a2, 2
/* 0E6CA8 7F0B2178 012A5821 */  addu  $t3, $t1, $t2
/* 0E6CAC 7F0B217C AD790000 */  sw    $t9, ($t3)
/* 0E6CB0 7F0B2180 8CAC0004 */  lw    $t4, 4($a1)
/* 0E6CB4 7F0B2184 258D0001 */  addiu $t5, $t4, 1
/* 0E6CB8 7F0B2188 ACAD0004 */  sw    $t5, 4($a1)
.L7F0B218C:
/* 0E6CBC 7F0B218C 03E00008 */  jr    $ra
/* 0E6CC0 7F0B2190 00000000 */   nop
)
#endif




s32 incrNearEdgeCount(StandTile **tileStack, s32 stackHeight, struct StandTileLocusCallbackRecord* data) {
    data->nearEdgeCount += 1;
    return 1;
}



// maybe stanCircleLegalXFObjTypeY
s32 sub_GAME_7F0B21B0(StandTile **tileStack, f32 target_x, f32 target_z, f32 unknown, s32 unk00, s32 *count_rtn, s32 bufMax)
{
    struct StandTileLocusCallbackRecord data;
    s32 rtn;

    data.unk00 = unk00;
    data.count = 0;
    data.bufMax = bufMax;
    data.nearEdgeCount = 0;

    rtn = sub_GAME_7F0B1DDC(tileStack, target_x, target_z, unknown,
        sub_GAME_7F0B2110, NULL, incrNearEdgeCount, &data
    );

    *count_rtn = data.count;

    if (1 < data.nearEdgeCount) {
        return 2;
    }

    return rtn;
}






/**
 * Address 0x7F0B2244.
*/
s32 stanIsSpecialBit1Set(StandTile *arg0, struct StandTileLocusCallbackRecord *arg1)
{
    s32 val = arg0->mid.half >> 0xC;
    if (D_80040F30[val] & 2)
    {
        arg1->unk00 = 1;
    }

    return 0;
}




#ifdef NONMATCHING
/**
 * Address 0x7F0B2274.
 *
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: no
 * - identical registers: fail
 *
 * Notes: the SRA 0xc needs to be calculated twice, but below is a move instruction from previous SRA 0xc.
 * Seems to match other than that.
*/
s32 sub_GAME_7F0B2274(StandTile *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, struct StandTileLocusCallbackRecord *arg5)
{
    s32 temp_v0;
    StandTile *temp_v1;
    s32 val;

    temp_v0 = arg0->points[arg1].link;

    if ((temp_v0 >> 4) != 0)
    {
        temp_v1 = &standTileStart[temp_v0];

        val = temp_v1->mid.half >> 0xc;
        if (D_80040F30[val] & 2)
        {
            arg5->unk00 = 1;
            return 1;
        }

        val = temp_v1->mid.half >> 0xc;
        if (D_80040F30[val] & 0x40)
        {
            dword_CODE_bss_8007BA0C = temp_v1;
            arg5->count = 1;
            return 0;
        }
    }

    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B2274
/* 0E6DA4 7F0B2274 000570C0 */  sll   $t6, $a1, 3
/* 0E6DA8 7F0B2278 AFA60008 */  sw    $a2, 8($sp)
/* 0E6DAC 7F0B227C AFA7000C */  sw    $a3, 0xc($sp)
/* 0E6DB0 7F0B2280 008E7821 */  addu  $t7, $a0, $t6
/* 0E6DB4 7F0B2284 95E2000E */  lhu   $v0, 0xe($t7)
/* 0E6DB8 7F0B2288 3C088004 */  lui   $t0, %hi(standTileStart)
/* 0E6DBC 7F0B228C 0002C103 */  sra   $t8, $v0, 4
/* 0E6DC0 7F0B2290 5300001E */  beql  $t8, $zero, .L7F0B230C
/* 0E6DC4 7F0B2294 00001025 */   move  $v0, $zero
/* 0E6DC8 7F0B2298 8D080F58 */  lw    $t0, %lo(standTileStart)($t0)
/* 0E6DCC 7F0B229C 0002C8C0 */  sll   $t9, $v0, 3
/* 0E6DD0 7F0B22A0 3C058004 */  lui   $a1, %hi(D_80040F30)
/* 0E6DD4 7F0B22A4 03281821 */  addu  $v1, $t9, $t0
/* 0E6DD8 7F0B22A8 84640004 */  lh    $a0, 4($v1)
/* 0E6DDC 7F0B22AC 24A50F30 */  addiu $a1, %lo(D_80040F30) # addiu $a1, $a1, 0xf30
/* 0E6DE0 7F0B22B0 240D0001 */  li    $t5, 1
/* 0E6DE4 7F0B22B4 00044B03 */  sra   $t1, $a0, 0xc
/* 0E6DE8 7F0B22B8 00A95021 */  addu  $t2, $a1, $t1
/* 0E6DEC 7F0B22BC 914B0000 */  lbu   $t3, ($t2)
/* 0E6DF0 7F0B22C0 00047B03 */  sra   $t7, $a0, 0xc
/* 0E6DF4 7F0B22C4 8FAE0014 */  lw    $t6, 0x14($sp)
/* 0E6DF8 7F0B22C8 316C0002 */  andi  $t4, $t3, 2
/* 0E6DFC 7F0B22CC 11800004 */  beqz  $t4, .L7F0B22E0
/* 0E6E00 7F0B22D0 00AFC021 */   addu  $t8, $a1, $t7
/* 0E6E04 7F0B22D4 ADCD0000 */  sw    $t5, ($t6)
/* 0E6E08 7F0B22D8 03E00008 */  jr    $ra
/* 0E6E0C 7F0B22DC 24020001 */   li    $v0, 1

.L7F0B22E0:
/* 0E6E10 7F0B22E0 93190000 */  lbu   $t9, ($t8)
/* 0E6E14 7F0B22E4 3C018008 */  lui   $at, %hi(dword_CODE_bss_8007BA0C)
/* 0E6E18 7F0B22E8 24090001 */  li    $t1, 1
/* 0E6E1C 7F0B22EC 33280040 */  andi  $t0, $t9, 0x40
/* 0E6E20 7F0B22F0 11000005 */  beqz  $t0, .L7F0B2308
/* 0E6E24 7F0B22F4 00001025 */   move  $v0, $zero
/* 0E6E28 7F0B22F8 8FAA0014 */  lw    $t2, 0x14($sp)
/* 0E6E2C 7F0B22FC AC23BA0C */  sw    $v1, %lo(dword_CODE_bss_8007BA0C)($at)
/* 0E6E30 7F0B2300 03E00008 */  jr    $ra
/* 0E6E34 7F0B2304 AD490004 */   sw    $t1, 4($t2)

.L7F0B2308:
/* 0E6E38 7F0B2308 00001025 */  move  $v0, $zero
.L7F0B230C:
/* 0E6E3C 7F0B230C 03E00008 */  jr    $ra
/* 0E6E40 7F0B2310 00000000 */   nop
)
#endif





/**
 * Address 0x7F0B2314.
*/
s32 stanTileDistanceRelated(StandTile **arg0, f32 arg1, f32 arg2, f32 arg3, struct StandTileLocusCallbackRecord *arg4)
{
    s32 i;

    // HACK:
    for(i=0;;)
    {
        ((s32*)arg4)[i+0] = 0;
        ((s32*)arg4)[i+1] = 0;
        ((s32*)arg4)[i+2] = 0;
        ((s32*)arg4)[i+3] = 0;
        i+=4;
        if (i>15) break;
    }

    // maybe something like:
    /*
    for(i=0;i<3;i++)
    {
        arg4[i].unk00 = 0;
        arg4[i].count = 0;
        arg4[i].bufMax = 0;
        arg4[i].nearEdgeCount = 0;
    }
    */

    return sub_GAME_7F0B1DDC(arg0, arg1, arg2, arg3, stanIsSpecialBit1Set, sub_GAME_7F0B2274, NULL, arg4);
}



s32 stanGetLocusField0(struct StandTileLocusCallbackRecord *arg0)
{
    return arg0->unk00;
}

s32 stanGetLocusCount(struct StandTileLocusCallbackRecord *arg0)
{
    return arg0->count;
}





#ifdef NONMATCHING
// regalloc only really
// Duplicating the macro does nothing
void sub_GAME_7F0B23AC(StandTile *tile, s32 tripleIndex, coord3d *pnt)
{
    s32 pntIndex = STAN_TRIPLE_TO_PNT_INDEX(tile, tripleIndex);

    pnt->x = (f32)tile->points[pntIndex].x * inv_level_scale;
    pnt->y = (f32)tile->points[pntIndex].y * inv_level_scale;
    pnt->z = (f32)tile->points[pntIndex].z * inv_level_scale;
    return;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B23AC
/* 0E6EDC 7F0B23AC 848E0006 */  lh    $t6, 6($a0)
/* 0E6EE0 7F0B23B0 00057880 */  sll   $t7, $a1, 2
/* 0E6EE4 7F0B23B4 24180008 */  li    $t8, 8
/* 0E6EE8 7F0B23B8 030FC823 */  subu  $t9, $t8, $t7
/* 0E6EEC 7F0B23BC 032E2807 */  srav  $a1, $t6, $t9
/* 0E6EF0 7F0B23C0 30A8000F */  andi  $t0, $a1, 0xf
/* 0E6EF4 7F0B23C4 000848C0 */  sll   $t1, $t0, 3
/* 0E6EF8 7F0B23C8 00891021 */  addu  $v0, $a0, $t1
/* 0E6EFC 7F0B23CC 844A0008 */  lh    $t2, 8($v0)
/* 0E6F00 7F0B23D0 3C018004 */  lui   $at, %hi(inv_level_scale)
/* 0E6F04 7F0B23D4 C4200F48 */  lwc1  $f0, %lo(inv_level_scale)($at)
/* 0E6F08 7F0B23D8 448A2000 */  mtc1  $t2, $f4
/* 0E6F0C 7F0B23DC 00000000 */  nop
/* 0E6F10 7F0B23E0 468021A0 */  cvt.s.w $f6, $f4
/* 0E6F14 7F0B23E4 46003202 */  mul.s $f8, $f6, $f0
/* 0E6F18 7F0B23E8 E4C80000 */  swc1  $f8, ($a2)
/* 0E6F1C 7F0B23EC 844B000A */  lh    $t3, 0xa($v0)
/* 0E6F20 7F0B23F0 448B5000 */  mtc1  $t3, $f10
/* 0E6F24 7F0B23F4 00000000 */  nop
/* 0E6F28 7F0B23F8 46805420 */  cvt.s.w $f16, $f10
/* 0E6F2C 7F0B23FC 46008482 */  mul.s $f18, $f16, $f0
/* 0E6F30 7F0B2400 E4D20004 */  swc1  $f18, 4($a2)
/* 0E6F34 7F0B2404 844C000C */  lh    $t4, 0xc($v0)
/* 0E6F38 7F0B2408 448C2000 */  mtc1  $t4, $f4
/* 0E6F3C 7F0B240C 00000000 */  nop
/* 0E6F40 7F0B2410 468021A0 */  cvt.s.w $f6, $f4
/* 0E6F44 7F0B2414 46003202 */  mul.s $f8, $f6, $f0
/* 0E6F48 7F0B2418 03E00008 */  jr    $ra
/* 0E6F4C 7F0B241C E4C80008 */   swc1  $f8, 8($a2)
)
#endif





#ifdef NONMATCHING
// TODO
void stanGetMoveBondCollisionTiles(void) {
    #ifdef DEBUG
    assert(getsides(s1)==3);
    #endif

    //if side++ > getsides
    #ifdef DEBUG
    osSyncPrintf("Ladder %s has no neighbouring ladder stan\n", GetStanRoomID(arg0));
    #endif
    return;


    // for rotate = 0 to 12
    // next

    //ran out of rotating tiles - just end
    #ifdef DEBUG
    osSyncPrintf("rotate==12\n");
    #endif
}
#else
GLOBAL_ASM(
.text
glabel stanGetMoveBondCollisionTiles
/* 0E6F50 7F0B2420 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0E6F54 7F0B2424 3C098008 */  lui   $t1, %hi(dword_CODE_bss_8007BA0C)
/* 0E6F58 7F0B2428 8D29BA0C */  lw    $t1, %lo(dword_CODE_bss_8007BA0C)($t1)
/* 0E6F5C 7F0B242C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E6F60 7F0B2430 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E6F64 7F0B2434 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E6F68 7F0B2438 AFB60030 */  sw    $s6, 0x30($sp)
/* 0E6F6C 7F0B243C AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E6F70 7F0B2440 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E6F74 7F0B2444 AFB30024 */  sw    $s3, 0x24($sp)
/* 0E6F78 7F0B2448 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E6F7C 7F0B244C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E6F80 7F0B2450 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E6F84 7F0B2454 85280006 */  lh    $t0, 6($t1)
/* 0E6F88 7F0B2458 00808025 */  move  $s0, $a0
/* 0E6F8C 7F0B245C 00A08825 */  move  $s1, $a1
/* 0E6F90 7F0B2460 00087303 */  sra   $t6, $t0, 0xc
/* 0E6F94 7F0B2464 31C8000F */  andi  $t0, $t6, 0xf
/* 0E6F98 7F0B2468 00C0A825 */  move  $s5, $a2
/* 0E6F9C 7F0B246C 1900005B */  blez  $t0, .L7F0B25DC
/* 0E6FA0 7F0B2470 00003825 */   move  $a3, $zero
/* 0E6FA4 7F0B2474 3C048004 */  lui   $a0, %hi(standTileStart)
/* 0E6FA8 7F0B2478 3C058004 */  lui   $a1, %hi(D_80040F30)
/* 0E6FAC 7F0B247C 24A50F30 */  addiu $a1, %lo(D_80040F30) # addiu $a1, $a1, 0xf30
/* 0E6FB0 7F0B2480 8C840F58 */  lw    $a0, %lo(standTileStart)($a0)
/* 0E6FB4 7F0B2484 01201825 */  move  $v1, $t1
.L7F0B2488:
/* 0E6FB8 7F0B2488 9462000E */  lhu   $v0, 0xe($v1)
/* 0E6FBC 7F0B248C 0002C0C0 */  sll   $t8, $v0, 3
/* 0E6FC0 7F0B2490 0002C903 */  sra   $t9, $v0, 4
/* 0E6FC4 7F0B2494 1320004D */  beqz  $t9, .L7F0B25CC
/* 0E6FC8 7F0B2498 0304B021 */   addu  $s6, $t8, $a0
/* 0E6FCC 7F0B249C 86C20004 */  lh    $v0, 4($s6)
/* 0E6FD0 7F0B24A0 00025303 */  sra   $t2, $v0, 0xc
/* 0E6FD4 7F0B24A4 00AA5821 */  addu  $t3, $a1, $t2
/* 0E6FD8 7F0B24A8 916C0000 */  lbu   $t4, ($t3)
/* 0E6FDC 7F0B24AC 318D0040 */  andi  $t5, $t4, 0x40
/* 0E6FE0 7F0B24B0 11A00046 */  beqz  $t5, .L7F0B25CC
/* 0E6FE4 7F0B24B4 24FE0002 */   addiu $fp, $a3, 2
/* 0E6FE8 7F0B24B8 24010003 */  li    $at, 3
/* 0E6FEC 7F0B24BC 03C1001A */  div   $zero, $fp, $at
/* 0E6FF0 7F0B24C0 AE090000 */  sw    $t1, ($s0)
/* 0E6FF4 7F0B24C4 00007010 */  mfhi  $t6
/* 0E6FF8 7F0B24C8 AE360000 */  sw    $s6, ($s1)
/* 0E6FFC 7F0B24CC 0000B825 */  move  $s7, $zero
/* 0E7000 7F0B24D0 AFA90040 */  sw    $t1, 0x40($sp)
/* 0E7004 7F0B24D4 01C0F025 */  move  $fp, $t6
/* 0E7008 7F0B24D8 2414000C */  li    $s4, 12
/* 0E700C 7F0B24DC 24130003 */  li    $s3, 3
/* 0E7010 7F0B24E0 00008025 */  move  $s0, $zero
.L7F0B24E4:
/* 0E7014 7F0B24E4 00179083 */  sra   $s2, $s7, 2
/* 0E7018 7F0B24E8 02E08825 */  move  $s1, $s7
.L7F0B24EC:
/* 0E701C 7F0B24EC 02507821 */  addu  $t7, $s2, $s0
/* 0E7020 7F0B24F0 01F3001A */  div   $zero, $t7, $s3
/* 0E7024 7F0B24F4 00002810 */  mfhi  $a1
/* 0E7028 7F0B24F8 32380003 */  andi  $t8, $s1, 3
/* 0E702C 7F0B24FC 02C02025 */  move  $a0, $s6
/* 0E7030 7F0B2500 03140019 */  multu $t8, $s4
/* 0E7034 7F0B2504 16600002 */  bnez  $s3, .L7F0B2510
/* 0E7038 7F0B2508 00000000 */   nop
/* 0E703C 7F0B250C 0007000D */  break 7
.L7F0B2510:
/* 0E7040 7F0B2510 2401FFFF */  li    $at, -1
/* 0E7044 7F0B2514 16610004 */  bne   $s3, $at, .L7F0B2528
/* 0E7048 7F0B2518 3C018000 */   lui   $at, 0x8000
/* 0E704C 7F0B251C 15E10002 */  bne   $t7, $at, .L7F0B2528
/* 0E7050 7F0B2520 00000000 */   nop
/* 0E7054 7F0B2524 0006000D */  break 6
.L7F0B2528:
/* 0E7058 7F0B2528 0000C812 */  mflo  $t9
/* 0E705C 7F0B252C 02B93021 */  addu  $a2, $s5, $t9
/* 0E7060 7F0B2530 0FC2C8EB */  jal   sub_GAME_7F0B23AC
/* 0E7064 7F0B2534 00000000 */   nop
/* 0E7068 7F0B2538 26100001 */  addiu $s0, $s0, 1
/* 0E706C 7F0B253C 1613FFEB */  bne   $s0, $s3, .L7F0B24EC
/* 0E7070 7F0B2540 26310001 */   addiu $s1, $s1, 1
/* 0E7074 7F0B2544 26EA0003 */  addiu $t2, $s7, 3
/* 0E7078 7F0B2548 314B0003 */  andi  $t3, $t2, 3
/* 0E707C 7F0B254C 01740019 */  multu $t3, $s4
/* 0E7080 7F0B2550 8FA40040 */  lw    $a0, 0x40($sp)
/* 0E7084 7F0B2554 03C02825 */  move  $a1, $fp
/* 0E7088 7F0B2558 00006012 */  mflo  $t4
/* 0E708C 7F0B255C 02AC3021 */  addu  $a2, $s5, $t4
/* 0E7090 7F0B2560 0FC2C8EB */  jal   sub_GAME_7F0B23AC
/* 0E7094 7F0B2564 00000000 */   nop
/* 0E7098 7F0B2568 26F70001 */  addiu $s7, $s7, 1
/* 0E709C 7F0B256C 52F4001C */  beql  $s7, $s4, .L7F0B25E0
/* 0E70A0 7F0B2570 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0E70A4 7F0B2574 C6A0001C */  lwc1  $f0, 0x1c($s5)
/* 0E70A8 7F0B2578 C6A20004 */  lwc1  $f2, 4($s5)
/* 0E70AC 7F0B257C 4602003C */  c.lt.s $f0, $f2
/* 0E70B0 7F0B2580 00000000 */  nop
/* 0E70B4 7F0B2584 4503FFD7 */  bc1tl .L7F0B24E4
/* 0E70B8 7F0B2588 00008025 */   move  $s0, $zero
/* 0E70BC 7F0B258C C6AC0010 */  lwc1  $f12, 0x10($s5)
/* 0E70C0 7F0B2590 460C003C */  c.lt.s $f0, $f12
/* 0E70C4 7F0B2594 00000000 */  nop
/* 0E70C8 7F0B2598 4503FFD2 */  bc1tl .L7F0B24E4
/* 0E70CC 7F0B259C 00008025 */   move  $s0, $zero
/* 0E70D0 7F0B25A0 C6A00028 */  lwc1  $f0, 0x28($s5)
/* 0E70D4 7F0B25A4 4602003C */  c.lt.s $f0, $f2
/* 0E70D8 7F0B25A8 00000000 */  nop
/* 0E70DC 7F0B25AC 4503FFCD */  bc1tl .L7F0B24E4
/* 0E70E0 7F0B25B0 00008025 */   move  $s0, $zero
/* 0E70E4 7F0B25B4 460C003C */  c.lt.s $f0, $f12
/* 0E70E8 7F0B25B8 00000000 */  nop
/* 0E70EC 7F0B25BC 4503FFC9 */  bc1tl .L7F0B24E4
/* 0E70F0 7F0B25C0 00008025 */   move  $s0, $zero
/* 0E70F4 7F0B25C4 10000006 */  b     .L7F0B25E0
/* 0E70F8 7F0B25C8 8FBF003C */   lw    $ra, 0x3c($sp)
.L7F0B25CC:
/* 0E70FC 7F0B25CC 24E70001 */  addiu $a3, $a3, 1
/* 0E7100 7F0B25D0 00E8082A */  slt   $at, $a3, $t0
/* 0E7104 7F0B25D4 1420FFAC */  bnez  $at, .L7F0B2488
/* 0E7108 7F0B25D8 24630008 */   addiu $v1, $v1, 8
.L7F0B25DC:
/* 0E710C 7F0B25DC 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0B25E0:
/* 0E7110 7F0B25E0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E7114 7F0B25E4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E7118 7F0B25E8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E711C 7F0B25EC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E7120 7F0B25F0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E7124 7F0B25F4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E7128 7F0B25F8 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E712C 7F0B25FC 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E7130 7F0B2600 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E7134 7F0B2604 03E00008 */  jr    $ra
/* 0E7138 7F0B2608 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
/**
 * arg5 type is wrong, first offset needs to be a float
*/
s32 sub_GAME_7F0B260C(StandTile *tile, s32 index, f32 p_x, f32 p_z, s32 arg4, struct StandTileLocusCallbackRecord *arg5)
{
    if (arg5->unk00 < (f32)tile->points[index].y
        && arg5->unk00 < (f32)tile->points[(index + 1) % STAN_TAIL_E(tile)].y)
    {
        return 1;
    }

    return 0;

}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B260C
/* 0E713C 7F0B260C 000570C0 */  sll   $t6, $a1, 3
/* 0E7140 7F0B2610 AFA60008 */  sw    $a2, 8($sp)
/* 0E7144 7F0B2614 AFA7000C */  sw    $a3, 0xc($sp)
/* 0E7148 7F0B2618 008E7821 */  addu  $t7, $a0, $t6
/* 0E714C 7F0B261C 85F8000A */  lh    $t8, 0xa($t7)
/* 0E7150 7F0B2620 8FA60014 */  lw    $a2, 0x14($sp)
/* 0E7154 7F0B2624 44982000 */  mtc1  $t8, $f4
/* 0E7158 7F0B2628 C4C00000 */  lwc1  $f0, ($a2)
/* 0E715C 7F0B262C 468021A0 */  cvt.s.w $f6, $f4
/* 0E7160 7F0B2630 4606003C */  c.lt.s $f0, $f6
/* 0E7164 7F0B2634 00000000 */  nop
/* 0E7168 7F0B2638 4502001D */  bc1fl .L7F0B26B0
/* 0E716C 7F0B263C 00001025 */   move  $v0, $zero
/* 0E7170 7F0B2640 84880006 */  lh    $t0, 6($a0)
/* 0E7174 7F0B2644 24B90001 */  addiu $t9, $a1, 1
/* 0E7178 7F0B2648 00084B03 */  sra   $t1, $t0, 0xc
/* 0E717C 7F0B264C 312A000F */  andi  $t2, $t1, 0xf
/* 0E7180 7F0B2650 032A001A */  div   $zero, $t9, $t2
/* 0E7184 7F0B2654 00001010 */  mfhi  $v0
/* 0E7188 7F0B2658 000258C0 */  sll   $t3, $v0, 3
/* 0E718C 7F0B265C 008B6021 */  addu  $t4, $a0, $t3
/* 0E7190 7F0B2660 858D000A */  lh    $t5, 0xa($t4)
/* 0E7194 7F0B2664 15400002 */  bnez  $t2, .L7F0B2670
/* 0E7198 7F0B2668 00000000 */   nop
/* 0E719C 7F0B266C 0007000D */  break 7
.L7F0B2670:
/* 0E71A0 7F0B2670 2401FFFF */  li    $at, -1
/* 0E71A4 7F0B2674 15410004 */  bne   $t2, $at, .L7F0B2688
/* 0E71A8 7F0B2678 3C018000 */   lui   $at, 0x8000
/* 0E71AC 7F0B267C 17210002 */  bne   $t9, $at, .L7F0B2688
/* 0E71B0 7F0B2680 00000000 */   nop
/* 0E71B4 7F0B2684 0006000D */  break 6
.L7F0B2688:
/* 0E71B8 7F0B2688 448D4000 */  mtc1  $t5, $f8
/* 0E71BC 7F0B268C 00000000 */  nop
/* 0E71C0 7F0B2690 468042A0 */  cvt.s.w $f10, $f8
/* 0E71C4 7F0B2694 460A003C */  c.lt.s $f0, $f10
/* 0E71C8 7F0B2698 00000000 */  nop
/* 0E71CC 7F0B269C 45020004 */  bc1fl .L7F0B26B0
/* 0E71D0 7F0B26A0 00001025 */   move  $v0, $zero
/* 0E71D4 7F0B26A4 03E00008 */  jr    $ra
/* 0E71D8 7F0B26A8 24020001 */   li    $v0, 1

/* 0E71DC 7F0B26AC 00001025 */  move  $v0, $zero
.L7F0B26B0:
/* 0E71E0 7F0B26B0 03E00008 */  jr    $ra
/* 0E71E4 7F0B26B4 00000000 */   nop
)
#endif




/**
 * US address 7F0B26B8.
*/
s32 sub_GAME_7F0B26B8(StandTile **tile, f32 target_x, f32 target_z, f32 b_z, f32 param_5)
{
    f32 data;

    data = param_5 * level_scale;

    /// TODO: Why is this cast wrong?

    return sub_GAME_7F0B1DDC(tile, target_x, target_z, b_z, NULL, sub_GAME_7F0B260C, NULL, (struct StandTileLocusCallbackRecord*)&data);
}


#ifdef NONMATCHING
// Horrifc BFS on tiles
// stanFillSearch()
StandTile *sub_GAME_7F0B2718(StandTile *srcTile, tilePredicate_t tilePred)
{
    StandTile *tile;
    u32 i;
    u32 pointCount;
    s32 link;
    StandTile *linkTile;

    s32 countForIter;

    s32 pntI;
    s32 seenCount;
    s32 linkI;
    s32 linkOffset;
    s32 madeProgress;   // bool

    // 0x44(sp) looks to be the ptr onto the stack

    // madeProgress =
    if (tilePred(srcTile)) {
        return srcTile;
    }

    bfsTileStack[0] = srcTile;
    seenCount = 1;
    countForIter = seenCount;

    do {
        // Loop over everyone for this iteration
        for(pntI=0; pntI < countForIter; pntI++)
        {

            tile = bfsTileStack[pntI];
            pointCount = STAN_POINT_COUNT(tile);

            // Loop over linked tiles
            for (linkI = 0; linkI < pointCount; linkI++)
            {
                link = tile->points[linkI].link;
                linkOffset = link * 8;  // somehow it's doing this << 3 before testing the >> 4, but this isn't working.

                if (link >> 4 != 0) {
                    linkTile = (struct StandTile*)((s32)standTileStart + linkOffset);

                    // Loop to see if this is a new tile (disgusting)
                    // If was a < and the while was a != though
                    for (i = 0; i < seenCount; i++)
                    {
                        if (bfsTileStack[i] == linkTile) {
                            goto LAB_7f0b283c;  // continue named loop?
                        }
                    }

                    if (tilePred(linkTile)) {
                        return linkTile;
                    }

                    bfsTileStack[seenCount] = linkTile;
                    if (350 < seenCount + 1)
                    {    // as written
                        #ifdef DEBUG
                        osSyncPrintf("Out of confs[] in stanFillSearch()\n");
                        #endif
                        return 0;
                    }

                    pointCount = STAN_POINT_COUNT(tile);
                    seenCount = seenCount + 1;

                }

                // they may also have needed something to put by the label
                LAB_7f0b283c: linkI = linkI;
            }

        }

        // We only continue if we made progress with this iteration
        if (seenCount == countForIter){
            break;
        }

        // does appear to be down here - two li,X,1s initially and a mov zero in the delay slot
        countForIter = seenCount;

    } while (1);


    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B2718
/* 0E7248 7F0B2718 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0E724C 7F0B271C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0E7250 7F0B2720 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0E7254 7F0B2724 AFB40028 */  sw    $s4, 0x28($sp)
/* 0E7258 7F0B2728 0080A025 */  move  $s4, $a0
/* 0E725C 7F0B272C 00A0A825 */  move  $s5, $a1
/* 0E7260 7F0B2730 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0E7264 7F0B2734 AFB70034 */  sw    $s7, 0x34($sp)
/* 0E7268 7F0B2738 AFB60030 */  sw    $s6, 0x30($sp)
/* 0E726C 7F0B273C AFB30024 */  sw    $s3, 0x24($sp)
/* 0E7270 7F0B2740 AFB20020 */  sw    $s2, 0x20($sp)
/* 0E7274 7F0B2744 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E7278 7F0B2748 00A0F809 */  jalr  $a1
/* 0E727C 7F0B274C AFB00018 */  sw    $s0, 0x18($sp)
/* 0E7280 7F0B2750 10400003 */  beqz  $v0, .L7F0B2760
/* 0E7284 7F0B2754 3C018008 */   lui   $at, %hi(bfsTileStack)
/* 0E7288 7F0B2758 10000049 */  b     .L7F0B2880
/* 0E728C 7F0B275C 02801025 */   move  $v0, $s4
.L7F0B2760:
/* 0E7290 7F0B2760 240E0001 */  li    $t6, 1
/* 0E7294 7F0B2764 3C178008 */  lui   $s7, %hi(bfsTileStack)
/* 0E7298 7F0B2768 3C168004 */  lui   $s6, %hi(standTileStart)
/* 0E729C 7F0B276C AC34BA10 */  sw    $s4, %lo(bfsTileStack)($at)
/* 0E72A0 7F0B2770 24110001 */  li    $s1, 1
/* 0E72A4 7F0B2774 26D60F58 */  addiu $s6, %lo(standTileStart) # addiu $s6, $s6, 0xf58
/* 0E72A8 7F0B2778 26F7BA10 */  addiu $s7, %lo(bfsTileStack) # addiu $s7, $s7, -0x45f0
/* 0E72AC 7F0B277C AFAE0058 */  sw    $t6, 0x58($sp)
/* 0E72B0 7F0B2780 0000F025 */  move  $fp, $zero
.L7F0B2784:
/* 0E72B4 7F0B2784 1A200037 */  blez  $s1, .L7F0B2864
/* 0E72B8 7F0B2788 3C0F8008 */   lui   $t7, %hi(bfsTileStack)
/* 0E72BC 7F0B278C 25EFBA10 */  addiu $t7, %lo(bfsTileStack) # addiu $t7, $t7, -0x45f0
/* 0E72C0 7F0B2790 AFAF0044 */  sw    $t7, 0x44($sp)
.L7F0B2794:
/* 0E72C4 7F0B2794 8FB80044 */  lw    $t8, 0x44($sp)
/* 0E72C8 7F0B2798 00009025 */  move  $s2, $zero
/* 0E72CC 7F0B279C 8F140000 */  lw    $s4, ($t8)
/* 0E72D0 7F0B27A0 86840006 */  lh    $a0, 6($s4)
/* 0E72D4 7F0B27A4 02809825 */  move  $s3, $s4
/* 0E72D8 7F0B27A8 0004CB03 */  sra   $t9, $a0, 0xc
/* 0E72DC 7F0B27AC 3324000F */  andi  $a0, $t9, 0xf
/* 0E72E0 7F0B27B0 58800026 */  blezl $a0, .L7F0B284C
/* 0E72E4 7F0B27B4 8FB90044 */   lw    $t9, 0x44($sp)
.L7F0B27B8:
/* 0E72E8 7F0B27B8 9662000E */  lhu   $v0, 0xe($s3)
/* 0E72EC 7F0B27BC 8ECA0000 */  lw    $t2, ($s6)
/* 0E72F0 7F0B27C0 000248C0 */  sll   $t1, $v0, 3
/* 0E72F4 7F0B27C4 00025903 */  sra   $t3, $v0, 4
/* 0E72F8 7F0B27C8 1160001B */  beqz  $t3, .L7F0B2838
/* 0E72FC 7F0B27CC 012A8021 */   addu  $s0, $t1, $t2
/* 0E7300 7F0B27D0 1A200009 */  blez  $s1, .L7F0B27F8
/* 0E7304 7F0B27D4 00001025 */   move  $v0, $zero
/* 0E7308 7F0B27D8 3C038008 */  lui   $v1, %hi(bfsTileStack)
/* 0E730C 7F0B27DC 2463BA10 */  addiu $v1, %lo(bfsTileStack) # addiu $v1, $v1, -0x45f0
.L7F0B27E0:
/* 0E7310 7F0B27E0 8C6C0000 */  lw    $t4, ($v1)
/* 0E7314 7F0B27E4 24420001 */  addiu $v0, $v0, 1
/* 0E7318 7F0B27E8 520C0014 */  beql  $s0, $t4, .L7F0B283C
/* 0E731C 7F0B27EC 26520001 */   addiu $s2, $s2, 1
/* 0E7320 7F0B27F0 1451FFFB */  bne   $v0, $s1, .L7F0B27E0
/* 0E7324 7F0B27F4 24630004 */   addiu $v1, $v1, 4
.L7F0B27F8:
/* 0E7328 7F0B27F8 02A0F809 */  jalr  $s5
/* 0E732C 7F0B27FC 02002025 */  move  $a0, $s0
/* 0E7330 7F0B2800 10400003 */  beqz  $v0, .L7F0B2810
/* 0E7334 7F0B2804 00116880 */   sll   $t5, $s1, 2
/* 0E7338 7F0B2808 1000001D */  b     .L7F0B2880
/* 0E733C 7F0B280C 02001025 */   move  $v0, $s0
.L7F0B2810:
/* 0E7340 7F0B2810 26310001 */  addiu $s1, $s1, 1
/* 0E7344 7F0B2814 02ED7021 */  addu  $t6, $s7, $t5
/* 0E7348 7F0B2818 2E21015F */  sltiu $at, $s1, 0x15f
/* 0E734C 7F0B281C 14200003 */  bnez  $at, .L7F0B282C
/* 0E7350 7F0B2820 ADD00000 */   sw    $s0, ($t6)
/* 0E7354 7F0B2824 10000016 */  b     .L7F0B2880
/* 0E7358 7F0B2828 00001025 */   move  $v0, $zero
.L7F0B282C:
/* 0E735C 7F0B282C 86840006 */  lh    $a0, 6($s4)
/* 0E7360 7F0B2830 00047B03 */  sra   $t7, $a0, 0xc
/* 0E7364 7F0B2834 31E4000F */  andi  $a0, $t7, 0xf
.L7F0B2838:
/* 0E7368 7F0B2838 26520001 */  addiu $s2, $s2, 1
.L7F0B283C:
/* 0E736C 7F0B283C 0244082A */  slt   $at, $s2, $a0
/* 0E7370 7F0B2840 1420FFDD */  bnez  $at, .L7F0B27B8
/* 0E7374 7F0B2844 26730008 */   addiu $s3, $s3, 8
/* 0E7378 7F0B2848 8FB90044 */  lw    $t9, 0x44($sp)
.L7F0B284C:
/* 0E737C 7F0B284C 8FA90058 */  lw    $t1, 0x58($sp)
/* 0E7380 7F0B2850 27DE0001 */  addiu $fp, $fp, 1
/* 0E7384 7F0B2854 27280004 */  addiu $t0, $t9, 4
/* 0E7388 7F0B2858 03C9082A */  slt   $at, $fp, $t1
/* 0E738C 7F0B285C 1420FFCD */  bnez  $at, .L7F0B2794
/* 0E7390 7F0B2860 AFA80044 */   sw    $t0, 0x44($sp)
.L7F0B2864:
/* 0E7394 7F0B2864 8FAA0058 */  lw    $t2, 0x58($sp)
/* 0E7398 7F0B2868 0000F025 */  move  $fp, $zero
/* 0E739C 7F0B286C 522A0004 */  beql  $s1, $t2, .L7F0B2880
/* 0E73A0 7F0B2870 00001025 */   move  $v0, $zero
/* 0E73A4 7F0B2874 1000FFC3 */  b     .L7F0B2784
/* 0E73A8 7F0B2878 AFB10058 */   sw    $s1, 0x58($sp)
/* 0E73AC 7F0B287C 00001025 */  move  $v0, $zero
.L7F0B2880:
/* 0E73B0 7F0B2880 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0E73B4 7F0B2884 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E73B8 7F0B2888 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E73BC 7F0B288C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0E73C0 7F0B2890 8FB30024 */  lw    $s3, 0x24($sp)
/* 0E73C4 7F0B2894 8FB40028 */  lw    $s4, 0x28($sp)
/* 0E73C8 7F0B2898 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0E73CC 7F0B289C 8FB60030 */  lw    $s6, 0x30($sp)
/* 0E73D0 7F0B28A0 8FB70034 */  lw    $s7, 0x34($sp)
/* 0E73D4 7F0B28A4 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0E73D8 7F0B28A8 03E00008 */  jr    $ra
/* 0E73DC 7F0B28AC 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif




/**
 * @param pntA: out parameter, will contain stanSavedColl_pntA (x,z)
 * @param pntB: out parameter, will contain stanSavedColl_pntB (x,z)
 */
bool getCollisionEdge_maybe(coord3d *pntA, coord3d *pntB)
{
    if (stanSavedColl_tile)
    {
        getTileEdgePoints(stanSavedColl_tile, stanSavedColl_pointI, pntA, pntB);

        return TRUE;
    }
    else
    {
        if (D_800413BC)
        {
            pntA->x = stanSavedColl_pntA.f[0];
            pntA->y = 0;
            pntA->z = stanSavedColl_pntA.f[1];

            pntB->x = stanSavedColl_pntB.f[0];
            pntB->y = 0;
            pntB->z = stanSavedColl_pntB.f[1];

            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}



void setLevelScale(f32 ls)
{
    level_scale = ls;
    inv_level_scale = (1.0f / ls);
    #ifdef DEBUG
    if (level_scale != 1.0)
    {
        osSyncPrintf("%5.2fm squared total area\n", /*lots of math*/ 1* inv_level_scale * inv_level_scale * 0.01 * 0.01);
        //...
        osSyncPrintf("%5.2fm squared BB extent\n\n",/*more maths*/ 1 * inv_level_scale * inv_level_scale * 0.01 * 0.01);
    }
    #endif
    return;
}




/**
 * Calculates y value on a tile, according to (x,z) position.
 *
 * Address 0x7F0B2970.
 */
f32 stanGetPositionYValue(StandTile *tile, f32 p_x, f32 p_z)
{
    f32 a[3]; // sp 132, vector a
    f32 b[3]; // sp 120, vector b
    s64 cp[3]; // sp 96, cross product vector (a x b)
    s64 rsum;
    s32 temp_a3;
    s32 temp_t6;
    s32 temp_t7;

    p_x *= level_scale;
    temp_t6 = STAN_TAIL_D(tile);
    temp_t7 = STAN_TAIL_C(tile);
    temp_a3 = STAN_TAIL_POINT_COUNT(tile);
    p_z *= level_scale;

    a[0] = (f32) (tile->points[temp_t7].x - tile->points[temp_t6].x);
    a[1] = (f32) (tile->points[temp_t7].y - tile->points[temp_t6].y);
    a[2] = (f32) (tile->points[temp_t7].z - tile->points[temp_t6].z);

    b[0] = (f32) (tile->points[temp_a3].x - tile->points[temp_t6].x);
    b[1] = (f32) (tile->points[temp_a3].y - tile->points[temp_t6].y);
    b[2] = (f32) (tile->points[temp_a3].z - tile->points[temp_t6].z);

    // implicit call to __f_to_ll
    // This is the cross product, a x b
    cp[0] = (s64)((a[1] * b[2]) - (a[2] * b[1]));
    cp[1] = (s64)((a[2] * b[0]) - (a[0] * b[2]));
    cp[2] = (s64)((a[0] * b[1]) - (a[1] * b[0]));

    // implicit call to __ll_mul
    rsum = ((s64)cp[0] * (s64)tile->points[temp_t6].x)
        + ((s64)cp[1] * (s64)tile->points[temp_t6].y)
        + ((s64)cp[2] * (s64)tile->points[temp_t6].z);

    // don't divide by zero
    if (cp[1] == 0)
    {
        return (f32) tile->points[temp_t6].y * inv_level_scale;
    }

    return (f32) ((((f64)(rsum) - ((f64) p_x * (f64)cp[0])) - ((f64) p_z * (f64)cp[2])) / (f64)(cp[1])) * inv_level_scale;
}


void copy_tile_RGB_as_24bit(StandTile *tile, f32 p_x, f32 p_z, u8 *rtn)
{
    u8 B = (tile->mid.half >> 0x8) & 0xF;
    u8 C = (tile->mid.half >> 0x4) & 0xF;
    u8 D = (tile->mid.half >> 0x0) & 0xF;
    rtn[0] = (B << 0x4) | B;
    rtn[1] = (C << 0x4) | C;
    rtn[2] = (D << 0x4) | D;
}


f32 sub_GAME_7F0B2C74(StandTile *tile, f32 *heights);

#ifdef NONMATCHING

// Very interesting. The target has a load of filler crap including instructions like "c.lt.S f2,f2"
// Presumably something has been generated from a macro but using the fixed value 0

f32 sub_GAME_7F0B2C74(StandTile *tile, f32 *heights)
{
    f32 y;

    y = tile->points[STAN_TRIPLE_TO_PNT_INDEX(tile, 0)].y;

    heights[0] = y * inv_level_scale;
    heights[1] = y * inv_level_scale;

    return;

}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B2C74
/* 0E77A4 7F0B2C74 848E0006 */  lh    $t6, 6($a0)
/* 0E77A8 7F0B2C78 3C028004 */  lui   $v0, %hi(inv_level_scale)
/* 0E77AC 7F0B2C7C 24420F48 */  addiu $v0, %lo(inv_level_scale) # addiu $v0, $v0, 0xf48
/* 0E77B0 7F0B2C80 000E7A03 */  sra   $t7, $t6, 8
/* 0E77B4 7F0B2C84 31F8000F */  andi  $t8, $t7, 0xf
/* 0E77B8 7F0B2C88 0018C8C0 */  sll   $t9, $t8, 3
/* 0E77BC 7F0B2C8C 00994021 */  addu  $t0, $a0, $t9
/* 0E77C0 7F0B2C90 8509000A */  lh    $t1, 0xa($t0)
/* 0E77C4 7F0B2C94 44892000 */  mtc1  $t1, $f4
/* 0E77C8 7F0B2C98 00000000 */  nop
/* 0E77CC 7F0B2C9C 468020A0 */  cvt.s.w $f2, $f4
/* 0E77D0 7F0B2CA0 4602103C */  c.lt.s $f2, $f2
/* 0E77D4 7F0B2CA4 46001006 */  mov.s $f0, $f2
/* 0E77D8 7F0B2CA8 46001306 */  mov.s $f12, $f2
/* 0E77DC 7F0B2CAC 46001386 */  mov.s $f14, $f2
/* 0E77E0 7F0B2CB0 45000002 */  bc1f  .L7F0B2CBC
/* 0E77E4 7F0B2CB4 46001406 */   mov.s $f16, $f2
/* 0E77E8 7F0B2CB8 46001406 */  mov.s $f16, $f2
.L7F0B2CBC:
/* 0E77EC 7F0B2CBC 4610703C */  c.lt.s $f14, $f16
/* 0E77F0 7F0B2CC0 00000000 */  nop
/* 0E77F4 7F0B2CC4 45020003 */  bc1fl .L7F0B2CD4
/* 0E77F8 7F0B2CC8 460C003C */   c.lt.s $f0, $f12
/* 0E77FC 7F0B2CCC 46007406 */  mov.s $f16, $f14
/* 0E7800 7F0B2CD0 460C003C */  c.lt.s $f0, $f12
.L7F0B2CD4:
/* 0E7804 7F0B2CD4 46000086 */  mov.s $f2, $f0
/* 0E7808 7F0B2CD8 45020003 */  bc1fl .L7F0B2CE8
/* 0E780C 7F0B2CDC 460E103C */   c.lt.s $f2, $f14
/* 0E7810 7F0B2CE0 46006086 */  mov.s $f2, $f12
/* 0E7814 7F0B2CE4 460E103C */  c.lt.s $f2, $f14
.L7F0B2CE8:
/* 0E7818 7F0B2CE8 00000000 */  nop
/* 0E781C 7F0B2CEC 45020003 */  bc1fl .L7F0B2CFC
/* 0E7820 7F0B2CF0 C4460000 */   lwc1  $f6, ($v0)
/* 0E7824 7F0B2CF4 46007086 */  mov.s $f2, $f14
/* 0E7828 7F0B2CF8 C4460000 */  lwc1  $f6, ($v0)
.L7F0B2CFC:
/* 0E782C 7F0B2CFC 46068202 */  mul.s $f8, $f16, $f6
/* 0E7830 7F0B2D00 E4A80000 */  swc1  $f8, ($a1)
/* 0E7834 7F0B2D04 C44A0000 */  lwc1  $f10, ($v0)
/* 0E7838 7F0B2D08 460A1482 */  mul.s $f18, $f2, $f10
/* 0E783C 7F0B2D0C 03E00008 */  jr    $ra
/* 0E7840 7F0B2D10 E4B20004 */   swc1  $f18, 4($a1)
)
#endif




f32 sub_GAME_7F0B2D14(StandTile *tile) {
    f32 vs[2];

    sub_GAME_7F0B2C74(tile, vs);
    return vs[0];
}




void debugStanView(s8 joyX, s8 joyY, u16 joyBtns) {
    return;
}

Gfx * sub_GAME_7F0B2D48(Gfx *arg0) {
    return arg0;
}






 /**
 * Get 24bit id stanIdHi from id string
 * @param stanIdHi: 1bit Type, 15bit Integer ID.
 * @param stanIdLo: 5bit stanIdLo File (a-z) and 3bit subtri 0-7
 * canonically Named
 */
void stanPackId(char *id, u16 *stanIdHi, u8 *stanIdLo)
{
    u32   bitsnumber; // sp3c
    char *str_end;    // sp38
    s32   y;          // sp34
    s32   bitsletter; // sp30
    s32   bitsfile;   // sp2c
    s32   bitssubtri; // sp28
    s32   var1;       // sp24

    var1 = id[0] - 'p';

    if (var1 < 0 || var1 > 1) // is p or q the first char (q never used?)
    {
        #ifdef ENABLE_LOG
            osSyncPrintf("stanPackId(): Bad letter chr \'%c\' in \"%s\"\n", id[0], id);
        #endif
    }
    else
    {
        bitsletter = id[0] - 'p'; // yes this is right, Im duplicated.
        bitsnumber = strtol(id + 1, &str_end, 10);

        if (id == str_end - 1)
        {
            #ifdef ENABLE_LOG
                osSyncPrintf("stanPackId(): Bad integer in \"%s\"\n", id);
            #endif
        }
        else if (bitsnumber <= 32767)
        {
            if (str_end[0] - 'a' < 0 || str_end[0] - 'a' >= 26)
            {
                #ifdef ENABLE_LOG
                    osSyncPrintf("stanPackId(): Bad file chr \'%c\' in \"%s\"\n", str_end[0], id);
                #endif
            }
            else
            {
                bitsfile = str_end[0] - 'a';
                if (1)
                    ;
                bitssubtri = str_end[1];

                if (bitssubtri != 0 && bitssubtri != '0')
                {
                    bitssubtri -= '0';
                }

                if (bitssubtri < 0 || bitssubtri >= 8)
                {
                    #ifdef ENABLE_LOG
                        osSyncPrintf("stanPackId(): Bad subtri chr \'%c\' in \"%s\"\n", str_end[1], id);
                    #endif
                }
                else
                {
                    if (str_end[1] == 0 || str_end[2] == 0)
                    {
                        #ifdef DEBUG
                        assert(bitsletter>=0&&bitsletter<=1);     // # 1094 "stan.c"
                        assert(bitsnumber>=0&&bitsnumber<=32767); // # 1095 "stan.c"
                        assert(bitsfile >=0&&bitsfile <=31);      // # 1096 "stan.c"
                        assert(bitssubtri>=0&&bitssubtri<=7);     // # 1097 "stan.c"
                        #endif
                        *stanIdHi = bitsletter << 0xf | bitsnumber;
                        *stanIdLo = bitsfile << 3 | bitssubtri;
                        return;
                    }
                    else
                    {
                        #ifdef ENABLE_LOG
                            osSyncPrintf("stanPackId(): Stan id too long \"%s\"\n", id);
                        #endif
                    }
                }
            }
        }
        else
        {
            #ifdef ENABLE_LOG
                osSyncPrintf("stanPackId(): Integer %d out of range in \"%s\"\n", bitsnumber, id);
            #endif
        }
    }
    *stanIdHi = -1;
    *stanIdLo = -1;
    return;
}





#ifdef NONMATCHING
// TODO
void stanMatchTileName(void) {

}
#else
GLOBAL_ASM(
.text
glabel stanMatchTileName
/* 0E7988 7F0B2E58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E798C 7F0B2E5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E7990 7F0B2E60 908E0000 */  lbu   $t6, ($a0)
/* 0E7994 7F0B2E64 27A50022 */  addiu $a1, $sp, 0x22
/* 0E7998 7F0B2E68 15C00003 */  bnez  $t6, .L7F0B2E78
/* 0E799C 7F0B2E6C 00000000 */   nop
/* 0E79A0 7F0B2E70 1000001F */  b     .L7F0B2EF0
/* 0E79A4 7F0B2E74 00001025 */   move  $v0, $zero
.L7F0B2E78:
/* 0E79A8 7F0B2E78 0FC2CB54 */  jal stanPackId
/* 0E79AC 7F0B2E7C 27A60021 */   addiu $a2, $sp, 0x21
/* 0E79B0 7F0B2E80 3C0F8008 */  lui   $t7, %hi(stan_prefix)
/* 0E79B4 7F0B2E84 8DEFB120 */  lw    $t7, %lo(stan_prefix)($t7)
/* 0E79B8 7F0B2E88 3C058004 */  lui   $a1, %hi(list_of_tilesizes)
/* 0E79BC 7F0B2E8C 24A50F4C */  addiu $a1, %lo(list_of_tilesizes) # addiu $a1, $a1, 0xf4c
/* 0E79C0 7F0B2E90 8DE30004 */  lw    $v1, 4($t7)
/* 0E79C4 7F0B2E94 97A40022 */  lhu   $a0, 0x22($sp)
/* 0E79C8 7F0B2E98 8C780000 */  lw    $t8, ($v1)
/* 0E79CC 7F0B2E9C 53000014 */  beql  $t8, $zero, .L7F0B2EF0
/* 0E79D0 7F0B2EA0 00001025 */   move  $v0, $zero
/* 0E79D4 7F0B2EA4 94790000 */  lhu   $t9, ($v1)
.L7F0B2EA8:
/* 0E79D8 7F0B2EA8 93A80021 */  lbu   $t0, 0x21($sp)
/* 0E79DC 7F0B2EAC 54990007 */  bnel  $a0, $t9, .L7F0B2ECC
/* 0E79E0 7F0B2EB0 84620006 */   lh    $v0, 6($v1)
/* 0E79E4 7F0B2EB4 90690002 */  lbu   $t1, 2($v1)
/* 0E79E8 7F0B2EB8 55090004 */  bnel  $t0, $t1, .L7F0B2ECC
/* 0E79EC 7F0B2EBC 84620006 */   lh    $v0, 6($v1)
/* 0E79F0 7F0B2EC0 1000000B */  b     .L7F0B2EF0
/* 0E79F4 7F0B2EC4 00601025 */   move  $v0, $v1
/* 0E79F8 7F0B2EC8 84620006 */  lh    $v0, 6($v1)
.L7F0B2ECC:
/* 0E79FC 7F0B2ECC 00025303 */  sra   $t2, $v0, 0xc
/* 0E7A00 7F0B2ED0 314B000F */  andi  $t3, $t2, 0xf
/* 0E7A04 7F0B2ED4 00AB6021 */  addu  $t4, $a1, $t3
/* 0E7A08 7F0B2ED8 918D0000 */  lbu   $t5, ($t4)
/* 0E7A0C 7F0B2EDC 01A31821 */  addu  $v1, $t5, $v1
/* 0E7A10 7F0B2EE0 8C6E0000 */  lw    $t6, ($v1)
/* 0E7A14 7F0B2EE4 55C0FFF0 */  bnezl $t6, .L7F0B2EA8
/* 0E7A18 7F0B2EE8 94790000 */   lhu   $t9, ($v1)
/* 0E7A1C 7F0B2EEC 00001025 */  move  $v0, $zero
.L7F0B2EF0:
/* 0E7A20 7F0B2EF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E7A24 7F0B2EF4 27BD0028 */  addiu $sp, $sp, 0x28
/* 0E7A28 7F0B2EF8 03E00008 */  jr    $ra
/* 0E7A2C 7F0B2EFC 00000000 */   nop
)
#endif


#ifdef XBLADEBUG
StandTile RemovedDebugFunctionOrXBLAUnique_7F0B2EFC()
{
    lVar1 = param_2;
    local_10 = *(stanPrefix + 4);
    cStack00000017 = param_1;
    sStack0000001e = param_2;
    while( true ) {
    if (*local_10 == 0) {
        return NULL;
    }
    cVar2 = sStack0000001e;
    if ((*local_10 == sStack0000001e) && (cVar2 = cStack00000017, *(local_10 + 2) == cStack00000017)
        ) break;
    local_10 = Function_8238ED08(local_10,lVar1,in_r5,in_r6,in_r7,in_r8,in_r9,cVar2,
                                    in_stack_ffffffab,in_stack_ffffffaf,in_stack_ffffffb4); 
    }
    return local_10;
}
#endif



void sub_GAME_7F0B2F00(StandTilePoint** arg0) {
    *arg0 = stanMatchTileName(*arg0);
}





#ifdef NONMATCHING
// To try
void *stanDetermineEOF(struct StanPrefixRecord *r, s32 arg1, s32 arg2)
{
     int iVar1;
  StandTile *local_20;
  StandTile **local_18;
  
  iVar1 = param_3._4_4_ - param_2._4_4_;
  stanTileStart = r->ptr_firstroom + iVar1 + -0x80;
  ptr_firstroom_0 = r->ptr_firstroom + iVar1;
  stanPrefix = r;
  #ifdef DEBUG
  assert(*r==0);
  #endif

  for (local_18 = &r->ptr_firstroom; *local_18 != NULL; local_18 = local_18 + 1)
  {
    *local_18 = *local_18 + iVar1;
  }
  for (local_20 = local_18 + 1; *local_20 != 0; local_20 = getNextStan(local_20))
  {
    D_80040F60 = local_20;
  }
  stanPrefix = r;
  return;
}
#else
GLOBAL_ASM(
.text
glabel stanDetermineEOF
/* 0E7A5C 7F0B2F2C 3C088008 */  lui   $t0, %hi(stan_prefix)
/* 0E7A60 7F0B2F30 2508B120 */  addiu $t0, %lo(stan_prefix) # addiu $t0, $t0, -0x4ee0
/* 0E7A64 7F0B2F34 AD040000 */  sw    $a0, ($t0)
/* 0E7A68 7F0B2F38 8C8E0004 */  lw    $t6, 4($a0)
/* 0E7A6C 7F0B2F3C 00C51023 */  subu  $v0, $a2, $a1
/* 0E7A70 7F0B2F40 3C018004 */  lui   $at, %hi(standTileStart)
/* 0E7A74 7F0B2F44 01C27821 */  addu  $t7, $t6, $v0
/* 0E7A78 7F0B2F48 25F8FF80 */  addiu $t8, $t7, -0x80
/* 0E7A7C 7F0B2F4C AC380F58 */  sw    $t8, %lo(standTileStart)($at)
/* 0E7A80 7F0B2F50 8C990004 */  lw    $t9, 4($a0)
/* 0E7A84 7F0B2F54 3C018004 */  lui   $at, %hi(ptr_firstroom_0)
/* 0E7A88 7F0B2F58 3C068004 */  lui   $a2, %hi(list_of_tilesizes)
/* 0E7A8C 7F0B2F5C 03224821 */  addu  $t1, $t9, $v0
/* 0E7A90 7F0B2F60 AC290F5C */  sw    $t1, %lo(ptr_firstroom_0)($at)
/* 0E7A94 7F0B2F64 8C8A0004 */  lw    $t2, 4($a0)
/* 0E7A98 7F0B2F68 24870004 */  addiu $a3, $a0, 4
/* 0E7A9C 7F0B2F6C 24C60F4C */  addiu $a2, %lo(list_of_tilesizes) # addiu $a2, $a2, 0xf4c
/* 0E7AA0 7F0B2F70 11400008 */  beqz  $t2, .L7F0B2F94
/* 0E7AA4 7F0B2F74 3C058004 */   lui   $a1, %hi(D_80040F60)
/* 0E7AA8 7F0B2F78 8CE30000 */  lw    $v1, ($a3)
/* 0E7AAC 7F0B2F7C 00625821 */  addu  $t3, $v1, $v0
.L7F0B2F80:
/* 0E7AB0 7F0B2F80 8CE30004 */  lw    $v1, 4($a3)
/* 0E7AB4 7F0B2F84 ACEB0000 */  sw    $t3, ($a3)
/* 0E7AB8 7F0B2F88 24E70004 */  addiu $a3, $a3, 4
/* 0E7ABC 7F0B2F8C 5460FFFC */  bnezl $v1, .L7F0B2F80
/* 0E7AC0 7F0B2F90 00625821 */   addu  $t3, $v1, $v0
.L7F0B2F94:
/* 0E7AC4 7F0B2F94 24E20004 */  addiu $v0, $a3, 4
/* 0E7AC8 7F0B2F98 8C4C0000 */  lw    $t4, ($v0)
/* 0E7ACC 7F0B2F9C 24A50F60 */  addiu $a1, %lo(D_80040F60) # addiu $a1, $a1, 0xf60
/* 0E7AD0 7F0B2FA0 1180000B */  beqz  $t4, .L7F0B2FD0
/* 0E7AD4 7F0B2FA4 00000000 */   nop
/* 0E7AD8 7F0B2FA8 ACA20000 */  sw    $v0, ($a1)
.L7F0B2FAC:
/* 0E7ADC 7F0B2FAC 84430006 */  lh    $v1, 6($v0)
/* 0E7AE0 7F0B2FB0 00036B03 */  sra   $t5, $v1, 0xc
/* 0E7AE4 7F0B2FB4 31AE000F */  andi  $t6, $t5, 0xf
/* 0E7AE8 7F0B2FB8 00CE7821 */  addu  $t7, $a2, $t6
/* 0E7AEC 7F0B2FBC 91F80000 */  lbu   $t8, ($t7)
/* 0E7AF0 7F0B2FC0 03021021 */  addu  $v0, $t8, $v0
/* 0E7AF4 7F0B2FC4 8C590000 */  lw    $t9, ($v0)
/* 0E7AF8 7F0B2FC8 5720FFF8 */  bnezl $t9, .L7F0B2FAC
/* 0E7AFC 7F0B2FCC ACA20000 */   sw    $v0, ($a1)
.L7F0B2FD0:
/* 0E7B00 7F0B2FD0 03E00008 */  jr    $ra
/* 0E7B04 7F0B2FD4 AD040000 */   sw    $a0, ($t0)
)
#endif


/**
 Get the room the tile belongs to
 @param tile: Tile to quiry
 @return the room number the tile is located in
 @exception Although room is u8, this needs to be s32 for matching ai.
 */
s32 getTileRoom(StandTile *tile)
{
    return tile->room;
}


//incorrect here so that both this and sub_GAME_7F0B4F9C match
extern s32 sub_GAME_7F0B4F9C(u8 arg0) ;

s32 sub_GAME_7F0B2FE0(StandTile *tile)
{
    // u8 -> s32 -> u8 causes the odd asm

    s32 room = tile->room;

    return sub_GAME_7F0B4F9C(room);
}

f32 sub_GAME_7F0B3004(StandTile *tile) {
    return sub_GAME_7F0B2D14(tile);
}

Gfx * sub_GAME_7F0B3024(Gfx *ptrdl, StandTilePoint *tile_point, u32 RGBAColor) {
    return ptrdl;
}

Gfx * sub_GAME_7F0B3034(Gfx *arg0) {
    return arg0;
}

Gfx * sub_GAME_7F0B303C(Gfx * arg0) {
    return arg0;
}

s32 sub_GAME_7F0B3044(void) {
    s32 sp1C;
    f32 temp_f0;

    sp1C = 0;
    if (((dynGetFreeGfx() < 0x1000) || (dynGetFreeVtx() < 0x1000)) && (*D_800413D0 == 0)) {
        D_800413C0 = 0.0f;
        D_800413C4 = 0.0f;
        D_800413C8 = D_800413CC;
        *D_800413D0 = 1;
    }
    if (*D_800413D0 == 0) {
        D_800413C0 += D_800413C4;
        temp_f0 = D_800413C0;
        if (temp_f0 > 1.0f) {
            sp1C = 1;
            D_800413C0 = temp_f0 - 1.0f;
        }
    }
    D_800413CC += 1;
    return sp1C;
}

Gfx * sub_GAME_7F0B312C(Gfx *arg0, s32 arg1)
{
    #ifdef DEBUG
      qword *pqVar1;
      qword *pqVar2;
      int iVar3;
      char cVar4;
      ulonglong uVar5;
      ulonglong uVar6;
      uint uStack00000014;
      stanRecord *psStack0000001c;
      char cStack00000027;
      ushort **ppuStack0000002c;
      uint uStack00000034;
      dword local_80;
      char *local_30;
      dword local_2c;
      uint local_28;
      dword local_24;
      dword local_20;
      qword local_10;
      dword local_8;
  
      uStack00000034 = param_5;
      ppuStack0000002c = param_4;
      uVar6 = ZEXT48(param_2);
      *ppuStack0000002c = param_2;
      local_30 = &DAT_00000001;
      uStack00000014 = param_1;
      psStack0000001c = param_2;
      cStack00000027 = param_3;
      pqVar1 = Function_8237F158();
      pqVar2 = Function_8237F058();
      uVar5 = 0;
      Function_82278968(pqVar2,pqVar1,0,param_4,param_5,param_6,uVar6);
      do {
        do {
          if (local_30 == NULL) {
            Function_82279088();
            return;
          }
          local_30 = local_30 + -1;
          psStack0000001c = ppuStack0000002c[local_30];
        } while (*psStack0000001c >> 0xf == cStack00000027);
        *psStack0000001c = *psStack0000001c ^ 0x8000;
        sub_GAME_7F0AF760(psStack0000001c);
        iVar3 = sub_GAME_7F0B3044();
        if (iVar3 != 0) {
          Function_8238AC90(psStack0000001c,uStack00000014,uVar5,param_4,param_5,param_6,uVar6);
        }
        for (local_28 = 0; cVar4 = getsides(psStack0000001c), local_28 < cVar4; local_28 = local_28 + 1)
        {
          if (psStack0000001c[local_28 + 1].tail >> 4 == 0) {
            iVar3 = sub_GAME_7F0B3044();
            if (iVar3 != 0) {
              uVar5 = local_28 + 1;
              cVar4 = getsides(psStack0000001c);
              trapWord(6,cVar4,0);
              trapWord(5,cVar4 & ~(((uVar5 & 0x7fffffff) << 1 | (uVar5 << 0x20) >> 0x3f) - 1),0xffff);
              uVar5 = uVar5 - (uVar5 / cVar4) * cVar4;
              param_4 = 0xffffffffffffffc0;
              Function_8238B8F0(psStack0000001c,local_28,uVar5,0xffffffffffffffc0,param_5,param_6,uVar6)
              ;
            }
          }
          else if (*(stanTileStart + psStack0000001c[local_28 + 1].tail) >> 0xf != cStack00000027) {
            uVar6 = ZEXT48(ppuStack0000002c);
            ppuStack0000002c[local_30] = stanTileStart + psStack0000001c[local_28 + 1].tail;
            local_30 = local_30 + 1;
            if (uStack00000034 < local_30) {
              osSyncPrintf("stanFillinVis: Stack overflow %d>%d",local_30,uStack00000034);
              return;
            }
          }
        }
      } while( TRUE );
    #endif
    return arg0;
}

#ifdef NONMATCHING
// Only difference is an extra sw a1,0x34(sp) appearing.
// There is the unused first argument which may have the wrong type
int sub_GAME_7F0B3138(void* unused, StandTile **pTile, f32 p_x, f32 p_z, f32 dest_x, f32 dest_z,
        int cdtypes, f32 unkHeight, f32 unkA) {

    return stanTestLineUnobstructed(pTile, p_x, p_z, dest_x, dest_z, cdtypes, unkHeight, unkA, 0, 1);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3138
/* 0E7C68 7F0B3138 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E7C6C 7F0B313C 44866000 */  mtc1  $a2, $f12
/* 0E7C70 7F0B3140 44877000 */  mtc1  $a3, $f14
/* 0E7C74 7F0B3144 AFA40030 */  sw    $a0, 0x30($sp)
/* 0E7C78 7F0B3148 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E7C7C 7F0B314C 44818000 */  mtc1  $at, $f16
/* 0E7C80 7F0B3150 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0E7C84 7F0B3154 8FAE0048 */  lw    $t6, 0x48($sp)
/* 0E7C88 7F0B3158 C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 0E7C8C 7F0B315C C7A80050 */  lwc1  $f8, 0x50($sp)
/* 0E7C90 7F0B3160 44805000 */  mtc1  $zero, $f10
/* 0E7C94 7F0B3164 00A02025 */  move  $a0, $a1
/* 0E7C98 7F0B3168 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0E7C9C 7F0B316C 44056000 */  mfc1  $a1, $f12
/* 0E7CA0 7F0B3170 44067000 */  mfc1  $a2, $f14
/* 0E7CA4 7F0B3174 8FA70040 */  lw    $a3, 0x40($sp)
/* 0E7CA8 7F0B3178 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0E7CAC 7F0B317C E7B00024 */  swc1  $f16, 0x24($sp)
/* 0E7CB0 7F0B3180 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0E7CB4 7F0B3184 E7A60018 */  swc1  $f6, 0x18($sp)
/* 0E7CB8 7F0B3188 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 0E7CBC 7F0B318C 0FC2C389 */  jal   stanTestLineUnobstructed
/* 0E7CC0 7F0B3190 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 0E7CC4 7F0B3194 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0E7CC8 7F0B3198 27BD0030 */  addiu $sp, $sp, 0x30
/* 0E7CCC 7F0B319C 03E00008 */  jr    $ra
/* 0E7CD0 7F0B31A0 00000000 */   nop
)
#endif





void sub_GAME_7F0B31A4(s32 arg0, StandTile *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, f32 arg6, f32 arg7) {
    stanTestVolume(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}



