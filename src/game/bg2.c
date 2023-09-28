#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <bondconstants.h>
#include <fr.h>
#include <memp.h>
#include "bg.h"
#include "bondview.h"
#include "debugmenu_handler.h"
#include "decompress.h"
#include "fog.h"
#include "lvl.h"
#include "math_ceil.h"
#include "matrixmath.h"
#include "player.h"
#include "explosions.h"
#include "unk_0BC530.h"

// new file, per EU

#ifdef NONMATCHING
u32 sub_GAME_7F0BA5C0(u32 arg0, u32 arg1) {
    s32 temp_a0;
    u32 temp_v0;
    void *phi_v0;
    s32 phi_a0;
    void *phi_v1;

    // Node 0
    if (arg0 < arg1)
    {
        // Node 1
        phi_v0 = arg0;
loop_2:
        // Node 2
        if (DL_LUT_PRIMARY_ADDFOG != 0)
        {
            // Node 3
            phi_a0 = DL_LUT_PRIMARY_ADDFOG;
            phi_v1 = &DL_LUT_PRIMARY_ADDFOG;
loop_4:
            // Node 4
            if (*phi_v0 == phi_a0)
            {
                // Node 5
                if (phi_v0->unk4 == phi_v1->unk4)
                {
                    // Node 6
                    *phi_v0 = (s32) phi_v1->unk8;
                    phi_v0->unk4 = (s32) phi_v1->unkC;
                }
            }
            // Node 7
            temp_a0 = phi_v1->unk10;
            phi_a0 = temp_a0;
            phi_v1 = (phi_v1 + 0x10);
            if (temp_a0 != 0)
            {
                goto loop_4;
            }
        }
        // Node 8
        temp_v0 = (phi_v0 + 8);
        phi_v0 = temp_v0;
        if (temp_v0 < arg1)
        {
            goto loop_2;
        }
    }
    // Node 9
    return arg0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BA5C0
/* 0EF0F0 7F0BA5C0 0085082B */  sltu  $at, $a0, $a1
/* 0EF0F4 7F0BA5C4 1020001C */  beqz  $at, .L7F0BA638
/* 0EF0F8 7F0BA5C8 00801025 */   move  $v0, $a0
/* 0EF0FC 7F0BA5CC 3C068004 */  lui   $a2, %hi(DL_LUT_PRIMARY_ADDFOG)
/* 0EF100 7F0BA5D0 24C64940 */  addiu $a2, %lo(DL_LUT_PRIMARY_ADDFOG) # addiu $a2, $a2, 0x4940
/* 0EF104 7F0BA5D4 8CCE0000 */  lw    $t6, ($a2)
.L7F0BA5D8:
/* 0EF108 7F0BA5D8 3C0F8004 */  lui   $t7, %hi(DL_LUT_PRIMARY_ADDFOG) 
/* 0EF10C 7F0BA5DC 25EF4940 */  addiu $t7, %lo(DL_LUT_PRIMARY_ADDFOG) # addiu $t7, $t7, 0x4940
/* 0EF110 7F0BA5E0 11C00011 */  beqz  $t6, .L7F0BA628
/* 0EF114 7F0BA5E4 00C01825 */   move  $v1, $a2
/* 0EF118 7F0BA5E8 8DE40000 */  lw    $a0, ($t7)
/* 0EF11C 7F0BA5EC 8C580000 */  lw    $t8, ($v0)
.L7F0BA5F0:
/* 0EF120 7F0BA5F0 5704000A */  bnel  $t8, $a0, .L7F0BA61C
/* 0EF124 7F0BA5F4 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF128 7F0BA5F8 8C590004 */  lw    $t9, 4($v0)
/* 0EF12C 7F0BA5FC 8C680004 */  lw    $t0, 4($v1)
/* 0EF130 7F0BA600 57280006 */  bnel  $t9, $t0, .L7F0BA61C
/* 0EF134 7F0BA604 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF138 7F0BA608 8C610008 */  lw    $at, 8($v1)
/* 0EF13C 7F0BA60C AC410000 */  sw    $at, ($v0)
/* 0EF140 7F0BA610 8C6A000C */  lw    $t2, 0xc($v1)
/* 0EF144 7F0BA614 AC4A0004 */  sw    $t2, 4($v0)
/* 0EF148 7F0BA618 8C640010 */  lw    $a0, 0x10($v1)
.L7F0BA61C:
/* 0EF14C 7F0BA61C 24630010 */  addiu $v1, $v1, 0x10
/* 0EF150 7F0BA620 5480FFF3 */  bnezl $a0, .L7F0BA5F0
/* 0EF154 7F0BA624 8C580000 */   lw    $t8, ($v0)
.L7F0BA628:
/* 0EF158 7F0BA628 24420008 */  addiu $v0, $v0, 8
/* 0EF15C 7F0BA62C 0045082B */  sltu  $at, $v0, $a1
/* 0EF160 7F0BA630 5420FFE9 */  bnezl $at, .L7F0BA5D8
/* 0EF164 7F0BA634 8CCE0000 */   lw    $t6, ($a2)
.L7F0BA638:
/* 0EF168 7F0BA638 03E00008 */  jr    $ra
/* 0EF16C 7F0BA63C 00000000 */   nop   
)

#endif





#ifdef NONMATCHING
void LoadFromDynamicCCRMLUT(Gfx *glistp, int DLSize, int LUTToUse)
{
    char cVar1;
    int *piVar2;
    int  iVar3;
    int  iVar4;

    if ((param_2 != NULL) && (param_1 < param_2))
        goto code_r0x7f0ba66c;
    if (param_2 == NULL)
    {
        cVar1 = *(char *)param_1;
        while (cVar1 != -0x48)
        {
code_r0x7f0ba66c:
            do
            {
                piVar2 = (int *)(&gDynamic_CC_RM_LUTp)[param_3];
                iVar3  = *piVar2;
                if (iVar3 != 0)
                {
                    iVar4 = *param_1;
                    while (true)
                    {
                        if (iVar4 == iVar3)
                        {
                            if (param_1[1] == piVar2[1])
                            {
                                dword_80044DB0 += 1;
                                *param_1   = piVar2[2];
                                param_1[1] = piVar2[3];
                                iVar3      = piVar2[4];
                            }
                            else
                            {
                                iVar3 = piVar2[4];
                            }
                        }
                        else
                        {
                            iVar3 = piVar2[4];
                        }
                        piVar2 = piVar2 + 4;
                        if (iVar3 == 0)
                            break;
                        iVar4 = *param_1;
                    }
                }
                param_1 = param_1 + 2;
            } while ((param_2 != NULL) && (param_1 < param_2));
            if (param_2 != NULL)
            {
                return;
            }
            cVar1 = *(char *)param_1;
        }
    }
    return;
}
#else


GLOBAL_ASM(
.text
glabel bgLoadFromDynamicCCRMLUT /*DynamicCCRMLUT(Int DLSize (a0), Gfx GBICommand(a1), Gfx ReplacementGBICommand (a2))*/
/* 0EF170 7F0BA640 10A00004 */  beqz  $a1, .L7F0BA654   /*if a1 = 0 goto L7F0BA654*/
/* 0EF174 7F0BA644 00801025 */   move  $v0, $a0         /*v0 = a0*/
/* 0EF178 7F0BA648 0045082B */  sltu  $at, $v0, $a1     /*if a1 < v0   then goto L7F0BA668*/
/* 0EF17C 7F0BA64C 14200006 */  bnez  $at, .L7F0BA668   
/* 0EF180 7F0BA650 00000000 */   nop   
.L7F0BA654:
/* 0EF184 7F0BA654 14A0002E */  bnez  $a1, .L7F0BA710   /*if a1 != 0 goto return*/
/* 0EF188 7F0BA658 00000000 */   nop   
/* 0EF18C 7F0BA65C 808E0000 */  lb    $t6, ($a0)        /*t6 = byte(a0)*/
/* 0EF190 7F0BA660 2408FFB8 */  li    $t0, -72          /*t0 = 0xB8*/
/* 0EF194 7F0BA664 110E002A */  beq   $t0, $t6, .L7F0BA710  /*if t6 = 0xB8 return (B8 = EndDl())*/
.L7F0BA668:
/* 0EF198 7F0BA668 3C098004 */   lui   $t1, %hi(ptrDynamic_CC_RM_LUT) 
/* 0EF19C 7F0BA66C 25294D88 */  addiu $t1, %lo(ptrDynamic_CC_RM_LUT) # addiu $t1, $t1, 0x4d88
/* 0EF1A0 7F0BA670 00067880 */  sll   $t7, $a2, 2   /*t7 = a2 << 2*/
/* 0EF1A4 7F0BA674 012FC021 */  addu  $t8, $t1, $t7 /*t8 = t7 + t1*/
/* 0EF1A8 7F0BA678 8F030000 */  lw    $v1, ($t8)
/* 0EF1AC 7F0BA67C 3C078004 */  lui   $a3, %hi(D_80044DB0)
/* 0EF1B0 7F0BA680 8CE74DB0 */  lw    $a3, %lo(D_80044DB0)($a3) # 0x4DB0($a3), 
/* 0EF1B4 7F0BA684 8C640000 */  lw    $a0, ($v1)
/* 0EF1B8 7F0BA688 2408FFB8 */  li    $t0, -72
/* 0EF1BC 7F0BA68C 10800011 */  beqz  $a0, .L7F0BA6D4
/* 0EF1C0 7F0BA690 00000000 */   nop   
/* 0EF1C4 7F0BA694 8C590000 */  lw    $t9, ($v0)
.L7F0BA698:
/* 0EF1C8 7F0BA698 5724000B */  bnel  $t9, $a0, .L7F0BA6C8
/* 0EF1CC 7F0BA69C 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF1D0 7F0BA6A0 8C4A0004 */  lw    $t2, 4($v0)
/* 0EF1D4 7F0BA6A4 8C6B0004 */  lw    $t3, 4($v1)
/* 0EF1D8 7F0BA6A8 554B0007 */  bnel  $t2, $t3, .L7F0BA6C8
/* 0EF1DC 7F0BA6AC 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF1E0 7F0BA6B0 8C610008 */  lw    $at, 8($v1)
/* 0EF1E4 7F0BA6B4 24E70001 */  addiu $a3, $a3, 1
/* 0EF1E8 7F0BA6B8 AC410000 */  sw    $at, ($v0)
/* 0EF1EC 7F0BA6BC 8C6D000C */  lw    $t5, 0xc($v1)
/* 0EF1F0 7F0BA6C0 AC4D0004 */  sw    $t5, 4($v0)
/* 0EF1F4 7F0BA6C4 8C640010 */  lw    $a0, 0x10($v1)
.L7F0BA6C8:
/* 0EF1F8 7F0BA6C8 24630010 */  addiu $v1, $v1, 0x10
/* 0EF1FC 7F0BA6CC 5480FFF2 */  bnezl $a0, .L7F0BA698
/* 0EF200 7F0BA6D0 8C590000 */   lw    $t9, ($v0)
.L7F0BA6D4:
/* 0EF204 7F0BA6D4 10A00006 */  beqz  $a1, .L7F0BA6F0
/* 0EF208 7F0BA6D8 24420008 */   addiu $v0, $v0, 8
/* 0EF20C 7F0BA6DC 3C018004 */  lui   $at, %hi(D_80044DB0)
/* 0EF210 7F0BA6E0 AC274DB0 */  sw    $a3, %lo(D_80044DB0)($at)
/* 0EF214 7F0BA6E4 0045082B */  sltu  $at, $v0, $a1
/* 0EF218 7F0BA6E8 1420FFDF */  bnez  $at, .L7F0BA668
/* 0EF21C 7F0BA6EC 00000000 */   nop   
.L7F0BA6F0:
/* 0EF220 7F0BA6F0 3C018004 */  lui   $at, %hi(D_80044DB0)
/* 0EF224 7F0BA6F4 14A00006 */  bnez  $a1, .L7F0BA710
/* 0EF228 7F0BA6F8 AC274DB0 */   sw    $a3, %lo(D_80044DB0)($at)
/* 0EF22C 7F0BA6FC 3C018004 */  lui   $at, %hi(D_80044DB0)
/* 0EF230 7F0BA700 AC274DB0 */  sw    $a3, %lo(D_80044DB0)($at)
/* 0EF234 7F0BA704 804E0000 */  lb    $t6, ($v0)
/* 0EF238 7F0BA708 150EFFD7 */  bne   $t0, $t6, .L7F0BA668
/* 0EF23C 7F0BA70C 00000000 */   nop   
.L7F0BA710:
/* 0EF240 7F0BA710 03E00008 */  jr    $ra
/* 0EF244 7F0BA714 00000000 */   nop   
)



#endif
