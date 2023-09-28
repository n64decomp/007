#include <ultra64.h>
#include <memp.h>
#include "../rmon.h" /*<PR/rmon.h>*/
#include "chr.h"
#include "objecthandler.h"
#include "math_floor.h"
#include "math_ceil.h"
#include "quaternion.h"
#include "math_asinfacosf.h"
#include "math_unk_05A9E0.h"
#include "chrobjdata.h"
#include "bondview.h"
#include "random.h"
#include "gbi_extension.h"

// forward declarations

void sub_GAME_7F06D490(struct Model *arg0, struct ModelNode *arg1);
void sub_GAME_7F0755B0(void);
s32 sub_GAME_7F0754BC(struct ModelAnimation *, s32, struct ModelSkeleton*);

// end forward declarations





//newfile per EU
bool modelmgrCanSlotFitRwdata(Model *modelslot, ModelFileHeader *modeldef)
{
	return modeldef->numRecords <= 0
		|| (modelslot->datas != NULL && modelslot->Type >= modeldef->numRecords);
}


#ifdef NONMATCHING
struct PropRecord * get_obj_instance_controller_for_header(struct ModelFileHeader* arg0)
{

}
#else
GLOBAL_ASM(
.text
glabel get_obj_instance_controller_for_header
/* 0A0BC4 7F06C094 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0A0BC8 7F06C098 3C0F8003 */  lui   $t7, %hi(D_80036078) 
/* 0A0BCC 7F06C09C 8DEF6078 */  lw    $t7, %lo(D_80036078)($t7)
/* 0A0BD0 7F06C0A0 AFB60030 */  sw    $s6, 0x30($sp)
/* 0A0BD4 7F06C0A4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0A0BD8 7F06C0A8 240EFFFF */  li    $t6, -1
/* 0A0BDC 7F06C0AC 0080A825 */  move  $s5, $a0
/* 0A0BE0 7F06C0B0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0A0BE4 7F06C0B4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0A0BE8 7F06C0B8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0A0BEC 7F06C0BC AFB20020 */  sw    $s2, 0x20($sp)
/* 0A0BF0 7F06C0C0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A0BF4 7F06C0C4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A0BF8 7F06C0C8 0000B025 */  move  $s6, $zero
/* 0A0BFC 7F06C0CC AFA00040 */  sw    $zero, 0x40($sp)
/* 0A0C00 7F06C0D0 11E00025 */  beqz  $t7, .L7F06C168
/* 0A0C04 7F06C0D4 A7AE003E */   sh    $t6, 0x3e($sp)
/* 0A0C08 7F06C0D8 3C148003 */  lui   $s4, %hi(D_80036074)
/* 0A0C0C 7F06C0DC 26946074 */  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
/* 0A0C10 7F06C0E0 8E840000 */  lw    $a0, ($s4)
/* 0A0C14 7F06C0E4 00001025 */  move  $v0, $zero
/* 0A0C18 7F06C0E8 3C068008 */  lui   $a2, %hi(ptr_allocation_1)
/* 0A0C1C 7F06C0EC 2484FFE2 */  addiu $a0, $a0, -0x1e
/* 0A0C20 7F06C0F0 1880000C */  blez  $a0, .L7F06C124
/* 0A0C24 7F06C0F4 24050004 */   li    $a1, 4
/* 0A0C28 7F06C0F8 8CC69934 */  lw    $a2, %lo(ptr_allocation_1)($a2)
/* 0A0C2C 7F06C0FC 00C01825 */  move  $v1, $a2
.L7F06C100:
/* 0A0C30 7F06C100 8C780008 */  lw    $t8, 8($v1)
/* 0A0C34 7F06C104 17000003 */  bnez  $t8, .L7F06C114
/* 0A0C38 7F06C108 0002C940 */   sll   $t9, $v0, 5
/* 0A0C3C 7F06C10C 10000005 */  b     .L7F06C124
/* 0A0C40 7F06C110 0326B021 */   addu  $s6, $t9, $a2
.L7F06C114:
/* 0A0C44 7F06C114 24420001 */  addiu $v0, $v0, 1
/* 0A0C48 7F06C118 0044082A */  slt   $at, $v0, $a0
/* 0A0C4C 7F06C11C 1420FFF8 */  bnez  $at, .L7F06C100
/* 0A0C50 7F06C120 24630020 */   addiu $v1, $v1, 0x20
.L7F06C124:
/* 0A0C54 7F06C124 56C00005 */  bnezl $s6, .L7F06C13C
/* 0A0C58 7F06C128 86A20014 */   lh    $v0, 0x14($s5)
/* 0A0C5C 7F06C12C 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0C60 7F06C130 24040020 */   li    $a0, 32
/* 0A0C64 7F06C134 0040B025 */  move  $s6, $v0
/* 0A0C68 7F06C138 86A20014 */  lh    $v0, 0x14($s5)
.L7F06C13C:
/* 0A0C6C 7F06C13C 24050004 */  li    $a1, 4
/* 0A0C70 7F06C140 1840002A */  blez  $v0, .L7F06C1EC
/* 0A0C74 7F06C144 00022080 */   sll   $a0, $v0, 2
/* 0A0C78 7F06C148 2484000F */  addiu $a0, $a0, 0xf
/* 0A0C7C 7F06C14C 3488000F */  ori   $t0, $a0, 0xf
/* 0A0C80 7F06C150 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0C84 7F06C154 3904000F */   xori  $a0, $t0, 0xf
/* 0A0C88 7F06C158 AFA20040 */  sw    $v0, 0x40($sp)
/* 0A0C8C 7F06C15C 86AA0014 */  lh    $t2, 0x14($s5)
/* 0A0C90 7F06C160 10000022 */  b     .L7F06C1EC
/* 0A0C94 7F06C164 A7AA003E */   sh    $t2, 0x3e($sp)
.L7F06C168:
/* 0A0C98 7F06C168 3C148003 */  lui   $s4, %hi(D_80036074)
/* 0A0C9C 7F06C16C 26946074 */  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
/* 0A0CA0 7F06C170 8E8B0000 */  lw    $t3, ($s4)
/* 0A0CA4 7F06C174 00008025 */  move  $s0, $zero
/* 0A0CA8 7F06C178 00008825 */  move  $s1, $zero
/* 0A0CAC 7F06C17C 1960001B */  blez  $t3, .L7F06C1EC
/* 0A0CB0 7F06C180 3C138008 */   lui   $s3, %hi(ptr_allocation_1)
/* 0A0CB4 7F06C184 26739934 */  addiu $s3, %lo(ptr_allocation_1) # addiu $s3, $s3, -0x66cc
/* 0A0CB8 7F06C188 8E660000 */  lw    $a2, ($s3)
.L7F06C18C:
/* 0A0CBC 7F06C18C 00109140 */  sll   $s2, $s0, 5
/* 0A0CC0 7F06C190 00D16021 */  addu  $t4, $a2, $s1
/* 0A0CC4 7F06C194 8D8D0008 */  lw    $t5, 8($t4)
/* 0A0CC8 7F06C198 02462021 */  addu  $a0, $s2, $a2
/* 0A0CCC 7F06C19C 55A0000E */  bnezl $t5, .L7F06C1D8
/* 0A0CD0 7F06C1A0 8E980000 */   lw    $t8, ($s4)
/* 0A0CD4 7F06C1A4 0FC1B018 */  jal   modelmgrCanSlotFitRwdata
/* 0A0CD8 7F06C1A8 02A02825 */   move  $a1, $s5
/* 0A0CDC 7F06C1AC 5040000A */  beql  $v0, $zero, .L7F06C1D8
/* 0A0CE0 7F06C1B0 8E980000 */   lw    $t8, ($s4)
/* 0A0CE4 7F06C1B4 8E660000 */  lw    $a2, ($s3)
/* 0A0CE8 7F06C1B8 00D11021 */  addu  $v0, $a2, $s1
/* 0A0CEC 7F06C1BC 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0A0CF0 7F06C1C0 0246B021 */  addu  $s6, $s2, $a2
/* 0A0CF4 7F06C1C4 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0A0CF8 7F06C1C8 844F0002 */  lh    $t7, 2($v0)
/* 0A0CFC 7F06C1CC 10000007 */  b     .L7F06C1EC
/* 0A0D00 7F06C1D0 A7AF003E */   sh    $t7, 0x3e($sp)
/* 0A0D04 7F06C1D4 8E980000 */  lw    $t8, ($s4)
.L7F06C1D8:
/* 0A0D08 7F06C1D8 26100001 */  addiu $s0, $s0, 1
/* 0A0D0C 7F06C1DC 26310020 */  addiu $s1, $s1, 0x20
/* 0A0D10 7F06C1E0 0218082A */  slt   $at, $s0, $t8
/* 0A0D14 7F06C1E4 5420FFE9 */  bnezl $at, .L7F06C18C
/* 0A0D18 7F06C1E8 8E660000 */   lw    $a2, ($s3)
.L7F06C1EC:
/* 0A0D1C 7F06C1EC 12C00006 */  beqz  $s6, .L7F06C208
/* 0A0D20 7F06C1F0 02C02025 */   move  $a0, $s6
/* 0A0D24 7F06C1F4 02A02825 */  move  $a1, $s5
/* 0A0D28 7F06C1F8 0FC1D7DA */  jal   modelInit
/* 0A0D2C 7F06C1FC 8FA60040 */   lw    $a2, 0x40($sp)
/* 0A0D30 7F06C200 87B9003E */  lh    $t9, 0x3e($sp)
/* 0A0D34 7F06C204 A6D90002 */  sh    $t9, 2($s6)
.L7F06C208:
/* 0A0D38 7F06C208 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0A0D3C 7F06C20C 02C01025 */  move  $v0, $s6
/* 0A0D40 7F06C210 8FB60030 */  lw    $s6, 0x30($sp)
/* 0A0D44 7F06C214 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A0D48 7F06C218 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A0D4C 7F06C21C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A0D50 7F06C220 8FB30024 */  lw    $s3, 0x24($sp)
/* 0A0D54 7F06C224 8FB40028 */  lw    $s4, 0x28($sp)
/* 0A0D58 7F06C228 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0A0D5C 7F06C22C 03E00008 */  jr    $ra
/* 0A0D60 7F06C230 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif


void clear_model_obj(Model* model)
{
    model->obj = NULL;
}


#ifdef NONMATCHING
void get_aircraft_obj_instance_controller(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_aircraft_obj_instance_controller
/* 0A0D6C 7F06C23C 3C0E8003 */  lui   $t6, %hi(D_80036078) 
/* 0A0D70 7F06C240 8DCE6078 */  lw    $t6, %lo(D_80036078)($t6)
/* 0A0D74 7F06C244 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A0D78 7F06C248 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A0D7C 7F06C24C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A0D80 7F06C250 AFA40030 */  sw    $a0, 0x30($sp)
/* 0A0D84 7F06C254 00008025 */  move  $s0, $zero
/* 0A0D88 7F06C258 AFA00028 */  sw    $zero, 0x28($sp)
/* 0A0D8C 7F06C25C 11C00028 */  beqz  $t6, .L7F06C300
/* 0A0D90 7F06C260 2408FFFF */   li    $t0, -1
/* 0A0D94 7F06C264 3C058003 */  lui   $a1, %hi(D_80036070)
/* 0A0D98 7F06C268 8CA56070 */  lw    $a1, %lo(D_80036070)($a1)
/* 0A0D9C 7F06C26C 00001025 */  move  $v0, $zero
/* 0A0DA0 7F06C270 3C078008 */  lui   $a3, %hi(ptr_allocation_0)
/* 0A0DA4 7F06C274 24A5FFF6 */  addiu $a1, $a1, -0xa
/* 0A0DA8 7F06C278 18A0000D */  blez  $a1, .L7F06C2B0
/* 0A0DAC 7F06C27C 00000000 */   nop   
/* 0A0DB0 7F06C280 8CE79930 */  lw    $a3, %lo(ptr_allocation_0)($a3)
/* 0A0DB4 7F06C284 00002025 */  move  $a0, $zero
/* 0A0DB8 7F06C288 00E01825 */  move  $v1, $a3
.L7F06C28C:
/* 0A0DBC 7F06C28C 8C6F0008 */  lw    $t7, 8($v1)
/* 0A0DC0 7F06C290 24420001 */  addiu $v0, $v0, 1
/* 0A0DC4 7F06C294 0045082A */  slt   $at, $v0, $a1
/* 0A0DC8 7F06C298 15E00003 */  bnez  $t7, .L7F06C2A8
/* 0A0DCC 7F06C29C 246300BC */   addiu $v1, $v1, 0xbc
/* 0A0DD0 7F06C2A0 10000003 */  b     .L7F06C2B0
/* 0A0DD4 7F06C2A4 00878021 */   addu  $s0, $a0, $a3
.L7F06C2A8:
/* 0A0DD8 7F06C2A8 1420FFF8 */  bnez  $at, .L7F06C28C
/* 0A0DDC 7F06C2AC 248400BC */   addiu $a0, $a0, 0xbc
.L7F06C2B0:
/* 0A0DE0 7F06C2B0 16000006 */  bnez  $s0, .L7F06C2CC
/* 0A0DE4 7F06C2B4 240400C0 */   li    $a0, 192
/* 0A0DE8 7F06C2B8 24050004 */  li    $a1, 4
/* 0A0DEC 7F06C2BC 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0DF0 7F06C2C0 A7A80026 */   sh    $t0, 0x26($sp)
/* 0A0DF4 7F06C2C4 87A80026 */  lh    $t0, 0x26($sp)
/* 0A0DF8 7F06C2C8 00408025 */  move  $s0, $v0
.L7F06C2CC:
/* 0A0DFC 7F06C2CC 8FB80030 */  lw    $t8, 0x30($sp)
/* 0A0E00 7F06C2D0 24050004 */  li    $a1, 4
/* 0A0E04 7F06C2D4 87060014 */  lh    $a2, 0x14($t8)
/* 0A0E08 7F06C2D8 18C00029 */  blez  $a2, .L7F06C380
/* 0A0E0C 7F06C2DC 00062080 */   sll   $a0, $a2, 2
/* 0A0E10 7F06C2E0 2484000F */  addiu $a0, $a0, 0xf
/* 0A0E14 7F06C2E4 3499000F */  ori   $t9, $a0, 0xf
/* 0A0E18 7F06C2E8 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0E1C 7F06C2EC 3B24000F */   xori  $a0, $t9, 0xf
/* 0A0E20 7F06C2F0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0A0E24 7F06C2F4 AFA20028 */  sw    $v0, 0x28($sp)
/* 0A0E28 7F06C2F8 10000021 */  b     .L7F06C380
/* 0A0E2C 7F06C2FC 85480014 */   lh    $t0, 0x14($t2)
.L7F06C300:
/* 0A0E30 7F06C300 3C058003 */  lui   $a1, %hi(D_80036070)
/* 0A0E34 7F06C304 8CA56070 */  lw    $a1, %lo(D_80036070)($a1)
/* 0A0E38 7F06C308 8FAB0030 */  lw    $t3, 0x30($sp)
/* 0A0E3C 7F06C30C 00001825 */  move  $v1, $zero
/* 0A0E40 7F06C310 18A0001B */  blez  $a1, .L7F06C380
/* 0A0E44 7F06C314 85660014 */   lh    $a2, 0x14($t3)
/* 0A0E48 7F06C318 3C078008 */  lui   $a3, %hi(ptr_allocation_0)
/* 0A0E4C 7F06C31C 8CE79930 */  lw    $a3, %lo(ptr_allocation_0)($a3)
/* 0A0E50 7F06C320 00002025 */  move  $a0, $zero
/* 0A0E54 7F06C324 00E01025 */  move  $v0, $a3
.L7F06C328:
/* 0A0E58 7F06C328 8C4C0008 */  lw    $t4, 8($v0)
/* 0A0E5C 7F06C32C 24630001 */  addiu $v1, $v1, 1
/* 0A0E60 7F06C330 55800010 */  bnezl $t4, .L7F06C374
/* 0A0E64 7F06C334 0065082A */   slt   $at, $v1, $a1
/* 0A0E68 7F06C338 58C00009 */  blezl $a2, .L7F06C360
/* 0A0E6C 7F06C33C 8C4F0010 */   lw    $t7, 0x10($v0)
/* 0A0E70 7F06C340 8C4D0010 */  lw    $t5, 0x10($v0)
/* 0A0E74 7F06C344 51A0000B */  beql  $t5, $zero, .L7F06C374
/* 0A0E78 7F06C348 0065082A */   slt   $at, $v1, $a1
/* 0A0E7C 7F06C34C 844E0002 */  lh    $t6, 2($v0)
/* 0A0E80 7F06C350 01C6082A */  slt   $at, $t6, $a2
/* 0A0E84 7F06C354 54200007 */  bnezl $at, .L7F06C374
/* 0A0E88 7F06C358 0065082A */   slt   $at, $v1, $a1
/* 0A0E8C 7F06C35C 8C4F0010 */  lw    $t7, 0x10($v0)
.L7F06C360:
/* 0A0E90 7F06C360 00878021 */  addu  $s0, $a0, $a3
/* 0A0E94 7F06C364 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0A0E98 7F06C368 10000005 */  b     .L7F06C380
/* 0A0E9C 7F06C36C 84480002 */   lh    $t0, 2($v0)
/* 0A0EA0 7F06C370 0065082A */  slt   $at, $v1, $a1
.L7F06C374:
/* 0A0EA4 7F06C374 248400BC */  addiu $a0, $a0, 0xbc
/* 0A0EA8 7F06C378 1420FFEB */  bnez  $at, .L7F06C328
/* 0A0EAC 7F06C37C 244200BC */   addiu $v0, $v0, 0xbc
.L7F06C380:
/* 0A0EB0 7F06C380 12000007 */  beqz  $s0, .L7F06C3A0
/* 0A0EB4 7F06C384 02002025 */   move  $a0, $s0
/* 0A0EB8 7F06C388 8FA50030 */  lw    $a1, 0x30($sp)
/* 0A0EBC 7F06C38C 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A0EC0 7F06C390 0FC1D7EB */  jal   animInit
/* 0A0EC4 7F06C394 A7A80026 */   sh    $t0, 0x26($sp)
/* 0A0EC8 7F06C398 87A80026 */  lh    $t0, 0x26($sp)
/* 0A0ECC 7F06C39C A6080002 */  sh    $t0, 2($s0)
.L7F06C3A0:
/* 0A0ED0 7F06C3A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A0ED4 7F06C3A4 02001025 */  move  $v0, $s0
/* 0A0ED8 7F06C3A8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A0EDC 7F06C3AC 03E00008 */  jr    $ra
/* 0A0EE0 7F06C3B0 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif






void modelAttachHead(Model *model, ModelNode *node,  ModelFileHeader *head)
{
    modelAttachPart(model,model->obj,node,head);
    modelInitRwData(model,head->RootNode);
}

void clear_aircraft_model_obj(Model *objinstance)

{
    objinstance->obj = NULL;
    return;
}

void modelSetDistanceDisabled(s32 param_1) {
  g_ModelDistanceDisabled = param_1;
}

// PD: modelSetDistanceScale
void modelSetDistanceScale(f32 param_1) {
  g_ModelDistanceScale = param_1;
}





#ifdef NONMATCHING
void sub_GAME_7F06C418(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C418
/* 0A0F48 7F06C418 00803025 */  move  $a2, $a0
/* 0A0F4C 7F06C41C 24040004 */  li    $a0, 4
/* 0A0F50 7F06C420 00001025 */  move  $v0, $zero
/* 0A0F54 7F06C424 00A01825 */  move  $v1, $a1
.L7F06C428:
/* 0A0F58 7F06C428 8CCE0000 */  lw    $t6, ($a2)
/* 0A0F5C 7F06C42C 24420001 */  addiu $v0, $v0, 1
/* 0A0F60 7F06C430 24630010 */  addiu $v1, $v1, 0x10
/* 0A0F64 7F06C434 AC6EFFF0 */  sw    $t6, -0x10($v1)
/* 0A0F68 7F06C438 8CCF0004 */  lw    $t7, 4($a2)
/* 0A0F6C 7F06C43C 24C60010 */  addiu $a2, $a2, 0x10
/* 0A0F70 7F06C440 AC6FFFF4 */  sw    $t7, -0xc($v1)
/* 0A0F74 7F06C444 8CD8FFF8 */  lw    $t8, -8($a2)
/* 0A0F78 7F06C448 AC78FFF8 */  sw    $t8, -8($v1)
/* 0A0F7C 7F06C44C 8CD9FFFC */  lw    $t9, -4($a2)
/* 0A0F80 7F06C450 1444FFF5 */  bne   $v0, $a0, .L7F06C428
/* 0A0F84 7F06C454 AC79FFFC */   sw    $t9, -4($v1)
/* 0A0F88 7F06C458 03E00008 */  jr    $ra
/* 0A0F8C 7F06C45C 00000000 */   nop   
)
#endif





void set_vtxallocator(s32 param_1) {
  vtxallocator = param_1;
}


#if defined(LEFTOVERDEBUG)
//called after a debug print during failed model operation
void return_null(void) {
  return;
}
#endif


void sub_GAME_7F06C474(Model* model, coord3d* coord)
{
    Mtxf* mtx;
    f32 dist;
    f32 neg_x;
    f32 neg_y;
    f32 neg_z;
    f32 inv_dist;

    mtx = getsubmatrix(model);
    neg_x = -mtx->m[3][0];
    neg_y = -mtx->m[3][1];
    neg_z = -mtx->m[3][2];

    dist = sqrtf((neg_x * neg_x) + (neg_y * neg_y) + (neg_z * neg_z));
    if (dist > 0.0f)
    {
        inv_dist = 1.0f / (model->scale * dist);
        coord->f[0] = neg_x * inv_dist;
        coord->f[1] = neg_y * inv_dist;
        coord->f[2] = neg_z * inv_dist;
        return;
    }

    coord->f[0] = 0.0f;
    coord->f[1] = 0.0f;
    coord->f[2] = 1.0f / model->scale;
}


void sub_GAME_7F06C550(Model* model, coord3d* coord)
{
  sub_GAME_7F06C474(model, coord);
}


// PD: model0001a524
s32 modelFindNodeMtxIndex(ModelNode *node, s32 arg1)
{
    s32 index;
    union ModelRoData *rodata1;
    union ModelRoData *rodata2;
    union ModelRoData *rodata3;
    union ModelRoData *rodata4;

    while (node)
    {
        switch (node->Opcode & 0xff)
        {
            case MODELNODE_OPCODE_HEADER:
                rodata1 = node->Data;
                return (s16)rodata1->Header.ModelType;

            case MODELNODE_OPCODE_GROUP:
                rodata2 = node->Data;
                return rodata2->Group.MatrixIDs[arg1 == 0x200 ? 2 : (arg1 == 0x100 ? 1 : 0)];

            case MODELNODE_OPCODE_OP03:
                rodata3 = node->Data;
                return rodata3->Group.MatrixIDs[arg1 == 0x200 ? 2 : (arg1 == 0x100 ? 1 : 0)];

            case MODELNODE_OPCODE_GROUPSIMPLE:
                rodata4 = node->Data;
                return rodata4->GroupSimple.Group1;
                break;
        }

        node = node->Parent;
    }

    return -1;
}


// PD: model0001a5cc
Mtxf *modelFindNodeMtx(struct Model *model, struct ModelNode *node, s32 arg2) {
    s32 index = modelFindNodeMtxIndex(node, arg2);

    if (index >= 0) {
        return &model->render_pos[index].pos;
    }

    return NULL;
}


//rejoined per EU
// PD: model0001a60c
Mtxf *getsubmatrix(Model *objinst)
{
    #if defined(LEFTOVERDEBUG)
    if (!objinst)
    {
        osSyncPrintf("getsubmatrix: no objinst!\n");
        return_null();
    }
    if (!objinst->obj)
    {
        osSyncPrintf("getsubmatrix: objinst has no object!\n");
        return_null();
    }
    #endif
    return modelFindNodeMtx(objinst, objinst->obj->RootNode, 0);
}


void sub_GAME_7F06C710(Model* model, coord3d* pos)
{
    Mtxf* mtx;

    mtx = getsubmatrix(model);
    if (mtx != NULL)
    {
        pos->f[0] = (f32) mtx->m[3][0];
        pos->f[1] = (f32) mtx->m[3][1];
        pos->f[2] = (f32) mtx->m[3][2];
        return;
    }

    pos->f[0] = 0.0f;
    pos->f[1] = 0.0f;
    pos->f[2] = 0.0f;
}


f32 sub_GAME_7F06C768(Model *objinst)
{
    Mtxf *mtx = getsubmatrix(objinst);
    if (mtx != 0)
    {
        return -mtx->m[3][2];
    }
    return 0.0f;
}


/**
 * Address 0x7F06C79C.
*/
union ModelRwData* modelGetNodeRwData(Model *Objinst, ModelNode *root)
{
    s32 index  = 0;
    union ModelRwData **data = Objinst->datas;

    switch (root->Opcode & 0xff)
    {
        case MODELNODE_OPCODE_HEADER:
        {
            index = root->Data->Header.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_DLCOLLISION:
        {
            index = root->Data->DisplayListCollisions.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_OP07:
        {
            index = root->Data->Op07.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_LOD:
        {
            index = root->Data->LOD.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_SWITCH:
        {
            index = root->Data->Switch.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_BSP:
        {
            index = root->Data->BSP.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_OP11:
        {
            index = root->Data->Op11.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_GUNFIRE:
        {
            index = root->Data->Gunfire.RwDataIndex;
            break;
        }
        case MODELNODE_OPCODE_HEAD:
        {
            index = root->Data->HeadPlaceholder.RwDataIndex;
            break;
        }
    }

    while (root->Parent)
    {
        root = root->Parent;
        if ((root->Opcode & 0xFF) == MODELNODE_OPCODE_HEAD)
        {
			ModelRwData_HeadPlaceholderRecord *tmp = modelGetNodeRwData(Objinst, root);
            data = tmp->RwDatas;
            break;
        }
    }

    return &data[index];
}



void getpartoffset(Model *objinst, ModelNode *part, coord3d *offset) //#MATCH - however OPCODE 3 needs defining
{
    #if defined(LEFTOVERDEBUG)
    if (!objinst)
    {
        osSyncPrintf("getpartoffset: no objinst!");
        return_null();
    }
    if (!part)
    {
        osSyncPrintf("getpartoffset: no partdesc!");
        return_null();
    }
    #endif
    switch (part->Opcode & 0xFF)
    {
        case MODELNODE_OPCODE_HEADER:
        {
            struct modeldata_root *root = modelGetNodeRwData(objinst, part);
            offset->x                   = root->pos.x;
            offset->y                   = root->pos.y;
            offset->z                   = root->pos.z;
            break;
        }
        case MODELNODE_OPCODE_GROUP:
        {
            ModelRoData_GroupRecord *prt = &part->Data->Group;
            offset->x                  = prt->Origin.x;
            offset->y                  = prt->Origin.y;
            offset->z                  = prt->Origin.z;
            break;
        }
        case MODELNODE_OPCODE_OP03:
        {
            ModelRoData_GroupSimpleRecord *prt = &part->Data->GroupSimple; //UNUSED at this time
            offset->x                        = prt->Origin.x;
            offset->y                        = prt->Origin.y;
            offset->z                        = prt->Origin.z;
            break;
        }
        case MODELNODE_OPCODE_GROUPSIMPLE:
        {
            ModelRoData_GroupSimpleRecord *prt = &part->Data->GroupSimple;
            offset->x                        = prt->Origin.x;
            offset->y                        = prt->Origin.y;
            offset->z                        = prt->Origin.z;
            break;
        }
        default:
        {
            offset->x = 0.0f;
            offset->y = 0.0f;
            offset->z = 0.0f;
            break;
        }
    }
}


void setpartoffset(Model *model, ModelNode *node, coord3d *pos)
{
#if defined(LEFTOVERDEBUG)
    if (!model) {
        osSyncPrintf("setpartoffset: no objinst!");
        return_null();
    }

    if (!node) {
        osSyncPrintf("setpartoffset: no partdesc!");
        return_null();
    }
    else
    {
        // huh?
    }
#endif
    switch (node->Opcode & 0xff)
    {
        case MODELNODE_OPCODE_HEADER:
            {
                ModelRwData_HeaderRecord *rwdata = modelGetNodeRwData(model, node);
                coord3d diff[1];

                diff[0].x = pos->x - rwdata->pos.x;
                diff[0].z = pos->z - rwdata->pos.z;

                rwdata->pos.x = pos->x;
                rwdata->pos.y = pos->y;
                rwdata->pos.z = pos->z;

                rwdata->unk24.x += diff[0].x; rwdata->unk24.z += diff[0].z;
                rwdata->unk34.x += diff[0].x; rwdata->unk34.z += diff[0].z;
                rwdata->unk40.x += diff[0].x; rwdata->unk40.z += diff[0].z;
                rwdata->unk4c.x += diff[0].x; rwdata->unk4c.z += diff[0].z;
            }
            break;
        case MODELNODE_OPCODE_GROUP:
            {
                ModelRoData_GroupRecord *rodata = &node->Data->Group;
                rodata->Origin.x = pos->x;
                rodata->Origin.y = pos->y;
                rodata->Origin.z = pos->z;
            }
            break;
        case MODELNODE_OPCODE_OP03:
            {
                ModelRoData_GroupRecord *rodata = &node->Data->Group;
                rodata->Origin.x = pos->x;
                rodata->Origin.y = pos->y;
                rodata->Origin.z = pos->z;
            }
            break;
        case MODELNODE_OPCODE_GROUPSIMPLE:
            {
                ModelRoData_GroupSimpleRecord *rodata = &node->Data->GroupSimple;
                rodata->Origin.x = pos->x;
                rodata->Origin.y = pos->y;
                rodata->Origin.z = pos->z;
            }
            break;
    }
}


void getsuboffset(Model *objinst, coord3d *offset) //#MATCH
{
    #if defined(LEFTOVERDEBUG )
    if (!objinst)
    {
        osSyncPrintf("getsuboffset: no objinst!");
        return_null();
    }

    if (!objinst->obj)
    {
        osSyncPrintf("getsuboffset: objinst has no object!");
        return_null();
    }
    #endif
    getpartoffset(objinst, objinst->obj->RootNode, offset);
}




void setsuboffset(Model *objinst, coord3d *offset) //#MATCH
{
    #if defined(LEFTOVERDEBUG )
    if (!objinst)
    {
        osSyncPrintf("setsuboffset: no objinst!");
        return_null();
    }
    if (!objinst->obj)
    {
        osSyncPrintf("setsuboffset: objinst has no object!");
        return_null();
    }
    #endif
    setpartoffset(objinst, objinst->obj->RootNode, offset);
}





/**
 * Address 0x7F06CC80.
 */
f32 getsubroty(Model *objinst)
{
    ModelNode *root;
    
    #if defined(LEFTOVERDEBUG)
    if(0)
    {
        // removed
    }

    if (objinst == NULL)
    {
        osSyncPrintf("getsubroty: no objinst!");
        return_null();
    }

    if(0)
    {
        // removed
    }

    if (objinst->obj == NULL)
    {
        osSyncPrintf("getsubroty: objinst has no object!");
        return_null();
    }

    if(0)
    {
        // removed
    }

    if (objinst->obj->RootNode == NULL)
    {
        osSyncPrintf("getsubroty: objinst has no root part!");
        return_null();
    }

    if(0)
    {
        // removed
    }
    #endif

    root = objinst->obj->RootNode;
    if ((root->Opcode & 0xFF) == 1)
    {
        return ((struct modeldata_root *)modelGetNodeRwData(objinst, root))->subroty;
    }

    return 0.0f;
}


void setsubroty(Model *model, f32 angle)
{
    ModelNode* node;
#if defined(LEFTOVERDEBUG)
    if (!model)
    {
        osSyncPrintf("setsubroty: no objinst!");
        return_null();
    }

    if (!model->obj) //< needs to be v1 not a1
    {
        osSyncPrintf("setsubroty: objinst has no object!");
        return_null();
    }

    if (!model->obj->RootNode)
    {
        osSyncPrintf("setsubroty: objinst has no root part!");
        return_null();
    }
#endif
    node = model->obj->RootNode;
    if ((node->Opcode & 0xff) == MODELNODE_OPCODE_HEADER)
    {
        ModelRwData_HeaderRecord *rwdata = modelGetNodeRwData(model, node);
        f32 diff = angle - rwdata->unk14;

        if (diff < 0) { diff += M_TAU_F; }

        rwdata->unk30 += diff;

        if (rwdata->unk30 >= M_TAU_F) { rwdata->unk30 -= M_TAU_F; }

        rwdata->unk20 += diff;

        if (rwdata->unk20 >= M_TAU_F) { rwdata->unk20 -= M_TAU_F; }

        rwdata->unk14 = angle;
    }
}


void modelSetScale(Model *objinst, f32 scale)
{
    objinst->scale = scale;
}


void sub_GAME_7F06CE84(Model* arg0, f32 arg1)
{
    arg0->unkb8 = arg1;
}


f32 getjointsize(Model *model, ModelNode *node)
{
    Model     *temp_a2;
    ModelNode *temp_a1;
    s32        temp_t7;

#if defined(LEFTOVERDEBUG)
    if (!model)
    {
        osSyncPrintf("getjointsize: no objinst!\n");
        return_null();
    }
#endif

    if (node)
    {
        do
        {
            switch (node->Opcode & 0xFF)
            {
                case MODELNODE_OPCODE_HEADER:
                {
                    ModelRoData_HeaderRecord *rodata = &node->Data->Header;
                    return rodata->GroupsAsF32 * model->scale;
                }
                case MODELNODE_OPCODE_GROUP:
                {
                    ModelRoData_GroupRecord *rodata = &node->Data->Group;
                    return rodata->BoundingVolumeRadius * model->scale;
                }
                case MODELNODE_OPCODE_OP03:
                {
                    ModelRoData_GroupRecord *rodata = &node->Data->Group;
                    return rodata->BoundingVolumeRadius * model->scale;
                }
                case MODELNODE_OPCODE_GROUPSIMPLE:
                {
                    ModelRoData_GroupSimpleRecord *rodata = &node->Data->GroupSimple;
                    return rodata->BoundingVolumeRadius * model->scale;
                }
                case MODELNODE_OPCODE_OP11:
                {
                    ModelRoData_Op11Record *rodata = &node->Data->Op11;
                    return rodata->BoundingVolumeRadius * model->scale;
                }
                case MODELNODE_OPCODE_GUNFIRE:
                {
                    ModelRoData_GunfireRecord *rodata = &node->Data->Gunfire;
                    return rodata->Scale * model->scale;
                }
                case MODELNODE_OPCODE_SHADOW:
                {
                    ModelRoData_ShadowRecord *rodata = &node->Data->Shadow;
                    return rodata->Scale * model->scale;
                }
                case MODELNODE_OPCODE_OP14:
                {
                    ModelRoData_Op14Record *rodata = &node->Data->Op14;
                    return rodata->Scale * model->scale;
                }
                case MODELNODE_OPCODE_INTERLINK:
                {
                    ModelRoData_InterlinkageRecord *rodata = &node->Data->Interlinkage;
                    return rodata->Scale * model->scale;
                }
                case MODELNODE_OPCODE_OP16:
                {
                    ModelNode_Op16Record *rodata = &node->Data->Op16;
                    return rodata->Scale * model->scale;
                }
                default:
                    node = node->Parent;
            }
        } while (node);
    }

    return 0.0f;
}


/**
 * Address 0x7F06D00C.
 * PD: model0001af80
*/
f32 getinstsize(Model *arg0)
{
    #if defined(LEFTOVERDEBUG)
    if (arg0 == NULL)
    {
        osSyncPrintf("getinstsize: no objinst!\n");
        return_null();
    }
    
    if (arg0->obj == NULL)
    {
        osSyncPrintf("getinstsize: no objdesc!\n");
        return_null();
    }
    #endif
    
    return arg0->obj->BoundingVolumeRadius * arg0->scale;
}



// PD: model0001af98
void interpolate3dVectors(vec3d *v, vec3d *w, float frac)
{
    v->x += (w->x - v->x) * frac;
    v->y += (w->y - v->y) * frac;
    v->z += (w->z - v->z) * frac;
  return;
}


// PD: model0001afe8
f32 sub_GAME_7F06D0CC(f32 arg0, f32 angle, f32 mult)
{
    f32 value = angle - arg0;

    if (angle < arg0)
    {
        value += M_TAU_F;
    }

    if (value < M_PI_F)
    {
        arg0 += value * mult;

        if (arg0 >= M_TAU_F)
        {
            arg0 -= M_TAU_F;
        }
    }
    else
    {
        arg0 -= (M_TAU_F - value) * mult;

        if (arg0 < 0)
        {
            arg0 += M_TAU_F;
        }
    }

    return arg0;
}


// PD: model0001b07c
void sub_GAME_7F06D160(coord3d *arg0, coord3d *arg1, f32 mult)
{
    arg0->x = sub_GAME_7F06D0CC(arg0->x, arg1->x, mult);
    arg0->y = sub_GAME_7F06D0CC(arg0->y, arg1->y, mult);
    arg0->z = sub_GAME_7F06D0CC(arg0->z, arg1->z, mult);
}


#ifdef NONMATCHING
void sub_GAME_7F06D1CC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06D1CC
/* 0A1CFC 7F06D1CC 8C8E0008 */  lw    $t6, 8($a0)
/* 0A1D00 7F06D1D0 00057880 */  sll   $t7, $a1, 2
/* 0A1D04 7F06D1D4 01E57823 */  subu  $t7, $t7, $a1
/* 0A1D08 7F06D1D8 000F7840 */  sll   $t7, $t7, 1
/* 0A1D0C 7F06D1DC 01CF3821 */  addu  $a3, $t6, $t7
/* 0A1D10 7F06D1E0 90E80002 */  lbu   $t0, 2($a3)
/* 0A1D14 7F06D1E4 00001825 */  move  $v1, $zero
/* 0A1D18 7F06D1E8 01004825 */  move  $t1, $t0
/* 0A1D1C 7F06D1EC 5920003A */  blezl $t1, .L7F06D2D8
/* 0A1D20 7F06D1F0 94F80004 */   lhu   $t8, 4($a3)
/* 0A1D24 7F06D1F4 94F80000 */  lhu   $t8, ($a3)
/* 0A1D28 7F06D1F8 240E0008 */  li    $t6, 8
/* 0A1D2C 7F06D1FC 8C8D0010 */  lw    $t5, 0x10($a0)
/* 0A1D30 7F06D200 03061021 */  addu  $v0, $t8, $a2
/* 0A1D34 7F06D204 30590007 */  andi  $t9, $v0, 7
/* 0A1D38 7F06D208 01D96023 */  subu  $t4, $t6, $t9
/* 0A1D3C 7F06D20C 318F00FF */  andi  $t7, $t4, 0xff
/* 0A1D40 7F06D210 000228C2 */  srl   $a1, $v0, 3
/* 0A1D44 7F06D214 012F082A */  slt   $at, $t1, $t7
/* 0A1D48 7F06D218 318B00FF */  andi  $t3, $t4, 0xff
/* 0A1D4C 7F06D21C 14200010 */  bnez  $at, .L7F06D260
/* 0A1D50 7F06D220 01A55021 */   addu  $t2, $t5, $a1
.L7F06D224:
/* 0A1D54 7F06D224 91590000 */  lbu   $t9, ($t2)
/* 0A1D58 7F06D228 240D0001 */  li    $t5, 1
/* 0A1D5C 7F06D22C 016D7004 */  sllv  $t6, $t5, $t3
/* 0A1D60 7F06D230 012B1023 */  subu  $v0, $t1, $t3
/* 0A1D64 7F06D234 25CFFFFF */  addiu $t7, $t6, -1
/* 0A1D68 7F06D238 304900FF */  andi  $t1, $v0, 0xff
/* 0A1D6C 7F06D23C 032FC024 */  and   $t8, $t9, $t7
/* 0A1D70 7F06D240 01386804 */  sllv  $t5, $t8, $t1
/* 0A1D74 7F06D244 006D1825 */  or    $v1, $v1, $t5
/* 0A1D78 7F06D248 306EFFFF */  andi  $t6, $v1, 0xffff
/* 0A1D7C 7F06D24C 29210008 */  slti  $at, $t1, 8
/* 0A1D80 7F06D250 01C01825 */  move  $v1, $t6
/* 0A1D84 7F06D254 254A0001 */  addiu $t2, $t2, 1
/* 0A1D88 7F06D258 1020FFF2 */  beqz  $at, .L7F06D224
/* 0A1D8C 7F06D25C 240B0008 */   li    $t3, 8
.L7F06D260:
/* 0A1D90 7F06D260 1920000A */  blez  $t1, .L7F06D28C
/* 0A1D94 7F06D264 01697823 */   subu  $t7, $t3, $t1
/* 0A1D98 7F06D268 91590000 */  lbu   $t9, ($t2)
/* 0A1D9C 7F06D26C 240D0001 */  li    $t5, 1
/* 0A1DA0 7F06D270 012D7004 */  sllv  $t6, $t5, $t1
/* 0A1DA4 7F06D274 01F9C007 */  srav  $t8, $t9, $t7
/* 0A1DA8 7F06D278 25D9FFFF */  addiu $t9, $t6, -1
/* 0A1DAC 7F06D27C 03197824 */  and   $t7, $t8, $t9
/* 0A1DB0 7F06D280 006F1825 */  or    $v1, $v1, $t7
/* 0A1DB4 7F06D284 306DFFFF */  andi  $t5, $v1, 0xffff
/* 0A1DB8 7F06D288 01A01825 */  move  $v1, $t5
.L7F06D28C:
/* 0A1DBC 7F06D28C 310900FF */  andi  $t1, $t0, 0xff
/* 0A1DC0 7F06D290 29210010 */  slti  $at, $t1, 0x10
/* 0A1DC4 7F06D294 1020000F */  beqz  $at, .L7F06D2D4
/* 0A1DC8 7F06D298 252E001F */   addiu $t6, $t1, 0x1f
/* 0A1DCC 7F06D29C 24180001 */  li    $t8, 1
/* 0A1DD0 7F06D2A0 01D8C804 */  sllv  $t9, $t8, $t6
/* 0A1DD4 7F06D2A4 00797824 */  and   $t7, $v1, $t9
/* 0A1DD8 7F06D2A8 11E0000A */  beqz  $t7, .L7F06D2D4
/* 0A1DDC 7F06D2AC 00601025 */   move  $v0, $v1
/* 0A1DE0 7F06D2B0 240D0010 */  li    $t5, 16
/* 0A1DE4 7F06D2B4 01A9C023 */  subu  $t8, $t5, $t1
/* 0A1DE8 7F06D2B8 240E0001 */  li    $t6, 1
/* 0A1DEC 7F06D2BC 030EC804 */  sllv  $t9, $t6, $t8
/* 0A1DF0 7F06D2C0 272FFFFF */  addiu $t7, $t9, -1
/* 0A1DF4 7F06D2C4 012F6804 */  sllv  $t5, $t7, $t1
/* 0A1DF8 7F06D2C8 004D1825 */  or    $v1, $v0, $t5
/* 0A1DFC 7F06D2CC 306EFFFF */  andi  $t6, $v1, 0xffff
/* 0A1E00 7F06D2D0 01C01825 */  move  $v1, $t6
.L7F06D2D4:
/* 0A1E04 7F06D2D4 94F80004 */  lhu   $t8, 4($a3)
.L7F06D2D8:
/* 0A1E08 7F06D2D8 00781821 */  addu  $v1, $v1, $t8
/* 0A1E0C 7F06D2DC 03E00008 */  jr    $ra
/* 0A1E10 7F06D2E0 3062FFFF */   andi  $v0, $v1, 0xffff
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D2E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06D2E4
/* 0A1E14 7F06D2E4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0A1E18 7F06D2E8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A1E1C 7F06D2EC AFB20020 */  sw    $s2, 0x20($sp)
/* 0A1E20 7F06D2F0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A1E24 7F06D2F4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A1E28 7F06D2F8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0A1E2C 7F06D2FC 94EE000C */  lhu   $t6, 0xc($a3)
/* 0A1E30 7F06D300 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0A1E34 7F06D304 00E09025 */  move  $s2, $a3
/* 0A1E38 7F06D308 00044080 */  sll   $t0, $a0, 2
/* 0A1E3C 7F06D30C 01CF0019 */  multu $t6, $t7
/* 0A1E40 7F06D310 00045880 */  sll   $t3, $a0, 2
/* 0A1E44 7F06D314 00008812 */  mflo  $s1
/* 0A1E48 7F06D318 50A00008 */  beql  $a1, $zero, .L7F06D33C
/* 0A1E4C 7F06D31C 8CCA0004 */   lw    $t2, 4($a2)
/* 0A1E50 7F06D320 8CD90004 */  lw    $t9, 4($a2)
/* 0A1E54 7F06D324 01044023 */  subu  $t0, $t0, $a0
/* 0A1E58 7F06D328 00084040 */  sll   $t0, $t0, 1
/* 0A1E5C 7F06D32C 03284821 */  addu  $t1, $t9, $t0
/* 0A1E60 7F06D330 10000006 */  b     .L7F06D34C
/* 0A1E64 7F06D334 95300004 */   lhu   $s0, 4($t1)
/* 0A1E68 7F06D338 8CCA0004 */  lw    $t2, 4($a2)
.L7F06D33C:
/* 0A1E6C 7F06D33C 01645823 */  subu  $t3, $t3, $a0
/* 0A1E70 7F06D340 000B5840 */  sll   $t3, $t3, 1
/* 0A1E74 7F06D344 014B6021 */  addu  $t4, $t2, $t3
/* 0A1E78 7F06D348 95900002 */  lhu   $s0, 2($t4)
.L7F06D34C:
/* 0A1E7C 7F06D34C 02402025 */  move  $a0, $s2
/* 0A1E80 7F06D350 02002825 */  move  $a1, $s0
/* 0A1E84 7F06D354 0FC1B473 */  jal   sub_GAME_7F06D1CC
/* 0A1E88 7F06D358 02203025 */   move  $a2, $s1
/* 0A1E8C 7F06D35C 8FAD003C */  lw    $t5, 0x3c($sp)
/* 0A1E90 7F06D360 02402025 */  move  $a0, $s2
/* 0A1E94 7F06D364 26050001 */  addiu $a1, $s0, 1
/* 0A1E98 7F06D368 02203025 */  move  $a2, $s1
/* 0A1E9C 7F06D36C 0FC1B473 */  jal   sub_GAME_7F06D1CC
/* 0A1EA0 7F06D370 A5A20000 */   sh    $v0, ($t5)
/* 0A1EA4 7F06D374 8FAE003C */  lw    $t6, 0x3c($sp)
/* 0A1EA8 7F06D378 02402025 */  move  $a0, $s2
/* 0A1EAC 7F06D37C 26050002 */  addiu $a1, $s0, 2
/* 0A1EB0 7F06D380 02203025 */  move  $a2, $s1
/* 0A1EB4 7F06D384 0FC1B473 */  jal   sub_GAME_7F06D1CC
/* 0A1EB8 7F06D388 A5C20002 */   sh    $v0, 2($t6)
/* 0A1EBC 7F06D38C 8FAF003C */  lw    $t7, 0x3c($sp)
/* 0A1EC0 7F06D390 02402025 */  move  $a0, $s2
/* 0A1EC4 7F06D394 26050003 */  addiu $a1, $s0, 3
/* 0A1EC8 7F06D398 02203025 */  move  $a2, $s1
/* 0A1ECC 7F06D39C 0FC1B473 */  jal   sub_GAME_7F06D1CC
/* 0A1ED0 7F06D3A0 A5E20004 */   sh    $v0, 4($t7)
/* 0A1ED4 7F06D3A4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0A1ED8 7F06D3A8 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0A1EDC 7F06D3AC 3043FFFF */  andi  $v1, $v0, 0xffff
/* 0A1EE0 7F06D3B0 5300000A */  beql  $t8, $zero, .L7F06D3DC
/* 0A1EE4 7F06D3B4 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A1EE8 7F06D3B8 84B90000 */  lh    $t9, ($a1)
/* 0A1EEC 7F06D3BC 3C090001 */  lui   $t1, 1
/* 0A1EF0 7F06D3C0 00194023 */  negu  $t0, $t9
/* 0A1EF4 7F06D3C4 10400004 */  beqz  $v0, .L7F06D3D8
/* 0A1EF8 7F06D3C8 A4A80000 */   sh    $t0, ($a1)
/* 0A1EFC 7F06D3CC 01221823 */  subu  $v1, $t1, $v0
/* 0A1F00 7F06D3D0 306AFFFF */  andi  $t2, $v1, 0xffff
/* 0A1F04 7F06D3D4 01401825 */  move  $v1, $t2
.L7F06D3D8:
/* 0A1F08 7F06D3D8 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06D3DC:
/* 0A1F0C 7F06D3DC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A1F10 7F06D3E0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A1F14 7F06D3E4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A1F18 7F06D3E8 27BD0028 */  addiu $sp, $sp, 0x28
/* 0A1F1C 7F06D3EC 03E00008 */  jr    $ra
/* 0A1F20 7F06D3F0 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D3F4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BC0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06D3F4
/* 0A1F24 7F06D3F4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A1F28 7F06D3F8 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0A1F2C 7F06D3FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A1F30 7F06D400 27AF0028 */  addiu $t7, $sp, 0x28
/* 0A1F34 7F06D404 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0A1F38 7F06D408 0FC1B4B9 */  jal   sub_GAME_7F06D2E4
/* 0A1F3C 7F06D40C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0A1F40 7F06D410 87B80028 */  lh    $t8, 0x28($sp)
/* 0A1F44 7F06D414 8FA30044 */  lw    $v1, 0x44($sp)
/* 0A1F48 7F06D418 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A1F4C 7F06D41C 44982000 */  mtc1  $t8, $f4
/* 0A1F50 7F06D420 00000000 */  nop   
/* 0A1F54 7F06D424 468021A0 */  cvt.s.w $f6, $f4
/* 0A1F58 7F06D428 44822000 */  mtc1  $v0, $f4
/* 0A1F5C 7F06D42C E4660000 */  swc1  $f6, ($v1)
/* 0A1F60 7F06D430 87B9002A */  lh    $t9, 0x2a($sp)
/* 0A1F64 7F06D434 468021A0 */  cvt.s.w $f6, $f4
/* 0A1F68 7F06D438 44994000 */  mtc1  $t9, $f8
/* 0A1F6C 7F06D43C 00000000 */  nop   
/* 0A1F70 7F06D440 468042A0 */  cvt.s.w $f10, $f8
/* 0A1F74 7F06D444 E46A0004 */  swc1  $f10, 4($v1)
/* 0A1F78 7F06D448 87A8002C */  lh    $t0, 0x2c($sp)
/* 0A1F7C 7F06D44C 44888000 */  mtc1  $t0, $f16
/* 0A1F80 7F06D450 00000000 */  nop   
/* 0A1F84 7F06D454 468084A0 */  cvt.s.w $f18, $f16
/* 0A1F88 7F06D458 04410004 */  bgez  $v0, .L7F06D46C
/* 0A1F8C 7F06D45C E4720008 */   swc1  $f18, 8($v1)
/* 0A1F90 7F06D460 44814000 */  mtc1  $at, $f8
/* 0A1F94 7F06D464 00000000 */  nop   
/* 0A1F98 7F06D468 46083180 */  add.s $f6, $f6, $f8
.L7F06D46C:
/* 0A1F9C 7F06D46C 3C018005 */  lui   $at, %hi(D_80054BC0)
/* 0A1FA0 7F06D470 C42A4BC0 */  lwc1  $f10, %lo(D_80054BC0)($at)
/* 0A1FA4 7F06D474 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A1FA8 7F06D478 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0A1FAC 7F06D47C 460A3402 */  mul.s $f16, $f6, $f10
/* 0A1FB0 7F06D480 44819000 */  mtc1  $at, $f18
/* 0A1FB4 7F06D484 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A1FB8 7F06D488 03E00008 */  jr    $ra
/* 0A1FBC 7F06D48C 46128003 */   div.s $f0, $f16, $f18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D490(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06D490
/* 0A1FC0 7F06D490 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0A1FC4 7F06D494 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A1FC8 7F06D498 AFB10018 */  sw    $s1, 0x18($sp)
/* 0A1FCC 7F06D49C 00808825 */  move  $s1, $a0
/* 0A1FD0 7F06D4A0 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0A1FD4 7F06D4A4 AFB00014 */   sw    $s0, 0x14($sp)
/* 0A1FD8 7F06D4A8 804E0000 */  lb    $t6, ($v0)
/* 0A1FDC 7F06D4AC 00408025 */  move  $s0, $v0
/* 0A1FE0 7F06D4B0 55C0007B */  bnezl $t6, .L7F06D6A0
/* 0A1FE4 7F06D4B4 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A1FE8 7F06D4B8 C4440034 */  lwc1  $f4, 0x34($v0)
/* 0A1FEC 7F06D4BC 44807000 */  mtc1  $zero, $f14
/* 0A1FF0 7F06D4C0 E7A40038 */  swc1  $f4, 0x38($sp)
/* 0A1FF4 7F06D4C4 C4460038 */  lwc1  $f6, 0x38($v0)
/* 0A1FF8 7F06D4C8 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0A1FFC 7F06D4CC C448003C */  lwc1  $f8, 0x3c($v0)
/* 0A2000 7F06D4D0 E7A80040 */  swc1  $f8, 0x40($sp)
/* 0A2004 7F06D4D4 C44A0030 */  lwc1  $f10, 0x30($v0)
/* 0A2008 7F06D4D8 E44A0014 */  swc1  $f10, 0x14($v0)
/* 0A200C 7F06D4DC C620002C */  lwc1  $f0, 0x2c($s1)
/* 0A2010 7F06D4E0 46007032 */  c.eq.s $f14, $f0
/* 0A2014 7F06D4E4 00000000 */  nop   
/* 0A2018 7F06D4E8 4503000F */  bc1tl .L7F06D528
/* 0A201C 7F06D4EC 8E380054 */   lw    $t8, 0x54($s1)
/* 0A2020 7F06D4F0 804F0001 */  lb    $t7, 1($v0)
/* 0A2024 7F06D4F4 27A40038 */  addiu $a0, $sp, 0x38
/* 0A2028 7F06D4F8 51E0000B */  beql  $t7, $zero, .L7F06D528
/* 0A202C 7F06D4FC 8E380054 */   lw    $t8, 0x54($s1)
/* 0A2030 7F06D500 44060000 */  mfc1  $a2, $f0
/* 0A2034 7F06D504 0FC1B41F */  jal   interpolate3dVectors
/* 0A2038 7F06D508 24450024 */   addiu $a1, $v0, 0x24
/* 0A203C 7F06D50C C60C0030 */  lwc1  $f12, 0x30($s0)
/* 0A2040 7F06D510 C60E0020 */  lwc1  $f14, 0x20($s0)
/* 0A2044 7F06D514 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A2048 7F06D518 8E26002C */   lw    $a2, 0x2c($s1)
/* 0A204C 7F06D51C 44807000 */  mtc1  $zero, $f14
/* 0A2050 7F06D520 E6000014 */  swc1  $f0, 0x14($s0)
/* 0A2054 7F06D524 8E380054 */  lw    $t8, 0x54($s1)
.L7F06D528:
/* 0A2058 7F06D528 02202025 */  move  $a0, $s1
/* 0A205C 7F06D52C 26050008 */  addiu $a1, $s0, 8
/* 0A2060 7F06D530 17000006 */  bnez  $t8, .L7F06D54C
/* 0A2064 7F06D534 27A6002C */   addiu $a2, $sp, 0x2c
/* 0A2068 7F06D538 C6300084 */  lwc1  $f16, 0x84($s1)
/* 0A206C 7F06D53C 46107032 */  c.eq.s $f14, $f16
/* 0A2070 7F06D540 00000000 */  nop   
/* 0A2074 7F06D544 45030015 */  bc1tl .L7F06D59C
/* 0A2078 7F06D548 C7A40038 */   lwc1  $f4, 0x38($sp)
.L7F06D54C:
/* 0A207C 7F06D54C 82190002 */  lb    $t9, 2($s0)
/* 0A2080 7F06D550 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0A2084 7F06D554 53200011 */  beql  $t9, $zero, .L7F06D59C
/* 0A2088 7F06D558 C7A40038 */   lwc1  $f4, 0x38($sp)
/* 0A208C 7F06D55C C622005C */  lwc1  $f2, 0x5c($s1)
/* 0A2090 7F06D560 C6000050 */  lwc1  $f0, 0x50($s0)
/* 0A2094 7F06D564 C62C0084 */  lwc1  $f12, 0x84($s1)
/* 0A2098 7F06D568 46027032 */  c.eq.s $f14, $f2
/* 0A209C 7F06D56C 00000000 */  nop   
/* 0A20A0 7F06D570 45030006 */  bc1tl .L7F06D58C
/* 0A20A4 7F06D574 46080281 */   sub.s $f10, $f0, $f8
/* 0A20A8 7F06D578 C6120044 */  lwc1  $f18, 0x44($s0)
/* 0A20AC 7F06D57C 46009101 */  sub.s $f4, $f18, $f0
/* 0A20B0 7F06D580 46022182 */  mul.s $f6, $f4, $f2
/* 0A20B4 7F06D584 46060000 */  add.s $f0, $f0, $f6
/* 0A20B8 7F06D588 46080281 */  sub.s $f10, $f0, $f8
.L7F06D58C:
/* 0A20BC 7F06D58C 460C5402 */  mul.s $f16, $f10, $f12
/* 0A20C0 7F06D590 46104480 */  add.s $f18, $f8, $f16
/* 0A20C4 7F06D594 E7B2003C */  swc1  $f18, 0x3c($sp)
/* 0A20C8 7F06D598 C7A40038 */  lwc1  $f4, 0x38($sp)
.L7F06D59C:
/* 0A20CC 7F06D59C C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0A20D0 7F06D5A0 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0A20D4 7F06D5A4 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0A20D8 7F06D5A8 E7A60030 */  swc1  $f6, 0x30($sp)
/* 0A20DC 7F06D5AC E7AA0034 */  swc1  $f10, 0x34($sp)
/* 0A20E0 7F06D5B0 8E2200A0 */  lw    $v0, 0xa0($s1)
/* 0A20E4 7F06D5B4 50400006 */  beql  $v0, $zero, .L7F06D5D0
/* 0A20E8 7F06D5B8 C7A8002C */   lwc1  $f8, 0x2c($sp)
/* 0A20EC 7F06D5BC 0040F809 */  jalr  $v0
/* 0A20F0 7F06D5C0 26070004 */  addiu $a3, $s0, 4
/* 0A20F4 7F06D5C4 50400036 */  beql  $v0, $zero, .L7F06D6A0
/* 0A20F8 7F06D5C8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A20FC 7F06D5CC C7A8002C */  lwc1  $f8, 0x2c($sp)
.L7F06D5D0:
/* 0A2100 7F06D5D0 C7B00038 */  lwc1  $f16, 0x38($sp)
/* 0A2104 7F06D5D4 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 0A2108 7F06D5D8 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 0A210C 7F06D5DC 46104481 */  sub.s $f18, $f8, $f16
/* 0A2110 7F06D5E0 46062281 */  sub.s $f10, $f4, $f6
/* 0A2114 7F06D5E4 E7B20038 */  swc1  $f18, 0x38($sp)
/* 0A2118 7F06D5E8 E7AA0040 */  swc1  $f10, 0x40($sp)
/* 0A211C 7F06D5EC E6080008 */  swc1  $f8, 8($s0)
/* 0A2120 7F06D5F0 C7B00030 */  lwc1  $f16, 0x30($sp)
/* 0A2124 7F06D5F4 C6120004 */  lwc1  $f18, 4($s0)
/* 0A2128 7F06D5F8 C60A0034 */  lwc1  $f10, 0x34($s0)
/* 0A212C 7F06D5FC 82080001 */  lb    $t0, 1($s0)
/* 0A2130 7F06D600 46128100 */  add.s $f4, $f16, $f18
/* 0A2134 7F06D604 C612003C */  lwc1  $f18, 0x3c($s0)
/* 0A2138 7F06D608 E604000C */  swc1  $f4, 0xc($s0)
/* 0A213C 7F06D60C C7A60034 */  lwc1  $f6, 0x34($sp)
/* 0A2140 7F06D610 E6060010 */  swc1  $f6, 0x10($s0)
/* 0A2144 7F06D614 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0A2148 7F06D618 46085400 */  add.s $f16, $f10, $f8
/* 0A214C 7F06D61C E6100034 */  swc1  $f16, 0x34($s0)
/* 0A2150 7F06D620 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0A2154 7F06D624 46049180 */  add.s $f6, $f18, $f4
/* 0A2158 7F06D628 11000009 */  beqz  $t0, .L7F06D650
/* 0A215C 7F06D62C E606003C */   swc1  $f6, 0x3c($s0)
/* 0A2160 7F06D630 C60A0024 */  lwc1  $f10, 0x24($s0)
/* 0A2164 7F06D634 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0A2168 7F06D638 C612002C */  lwc1  $f18, 0x2c($s0)
/* 0A216C 7F06D63C 46085400 */  add.s $f16, $f10, $f8
/* 0A2170 7F06D640 E6100024 */  swc1  $f16, 0x24($s0)
/* 0A2174 7F06D644 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0A2178 7F06D648 46049180 */  add.s $f6, $f18, $f4
/* 0A217C 7F06D64C E606002C */  swc1  $f6, 0x2c($s0)
.L7F06D650:
/* 0A2180 7F06D650 82090002 */  lb    $t1, 2($s0)
/* 0A2184 7F06D654 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0A2188 7F06D658 51200011 */  beql  $t1, $zero, .L7F06D6A0
/* 0A218C 7F06D65C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A2190 7F06D660 C60A004C */  lwc1  $f10, 0x4c($s0)
/* 0A2194 7F06D664 C6120054 */  lwc1  $f18, 0x54($s0)
/* 0A2198 7F06D668 46085400 */  add.s $f16, $f10, $f8
/* 0A219C 7F06D66C C60A0040 */  lwc1  $f10, 0x40($s0)
/* 0A21A0 7F06D670 E610004C */  swc1  $f16, 0x4c($s0)
/* 0A21A4 7F06D674 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0A21A8 7F06D678 46049180 */  add.s $f6, $f18, $f4
/* 0A21AC 7F06D67C C6120048 */  lwc1  $f18, 0x48($s0)
/* 0A21B0 7F06D680 E6060054 */  swc1  $f6, 0x54($s0)
/* 0A21B4 7F06D684 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0A21B8 7F06D688 46085400 */  add.s $f16, $f10, $f8
/* 0A21BC 7F06D68C E6100040 */  swc1  $f16, 0x40($s0)
/* 0A21C0 7F06D690 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0A21C4 7F06D694 46049180 */  add.s $f6, $f18, $f4
/* 0A21C8 7F06D698 E6060048 */  swc1  $f6, 0x48($s0)
/* 0A21CC 7F06D69C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F06D6A0:
/* 0A21D0 7F06D6A0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0A21D4 7F06D6A4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0A21D8 7F06D6A8 03E00008 */  jr    $ra
/* 0A21DC 7F06D6AC 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif








void subcalcpos(Model *arg0)
{
    struct ModelNode *root;

#if defined(LEFTOVERDEBUG)
    if (arg0 == NULL)
    {
        osSyncPrintf("subcalcpos: no objanim!\n");
        return_null();
    }

    if (arg0->obj == 0)
    {
        osSyncPrintf("subcalcpos: no objdesc!\n");
        return_null();
    }
#endif

    root = arg0->obj->RootNode;
    if ((root != NULL) && ((root->Opcode & 0xFF) == 1))
    {
        sub_GAME_7F06D490(arg0, root);
    }
}

void process_01_group_heading(ModelRenderData* renderdata, Model* model, ModelNode* node)
{
    union ModelRoData* rodata;
    union ModelRwData* rwdata;
    f32 scale;
    f32* pos;
    f32 unk14;
    Mtxf* var_a3;
    s32 modeltype;
    RenderPosView* renderpos;
    Mtxf sp20;

    rodata = node->Data;
    rwdata = modelGetNodeRwData(model, node);

    scale = model->scale;
    pos = &rwdata->Header.pos.x;
    unk14 = rwdata->Header.unk14;
    modeltype = (s16)rodata->Header.ModelType;
    renderpos = &model->render_pos[modeltype];

    if (node->Parent != NULL)
    {
        var_a3 = modelFindNodeMtx(model, node->Parent, 0);
    }
    else
    {
        var_a3 = renderdata->unk00;
    }

    if (rwdata->Header.unk18 != 0.0f)
    {
        unk14 = sub_GAME_7F06D0CC(unk14, rwdata->Header.unk1c, rwdata->Header.unk18);
    }

    if (var_a3 != NULL)
    {
        matrix_4x4_set_position_and_rotation_around_y(pos, unk14, &sp20);

        if (scale != 1.0f)
        {
            matrix_scalar_multiply_2(scale, sp20.m[0]);
        }

        matrix_4x4_multiply_homogeneous(var_a3, &sp20, &renderpos->pos);
        return;
    }

    matrix_4x4_set_position_and_rotation_around_y(pos, unk14, &renderpos->pos);

    if (scale != 1.0f)
    {
        matrix_scalar_multiply_2(scale, renderpos->pos.m[0]);
    }
}


#ifdef NONMATCHING
void sub_GAME_7F06D8B0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BC4
.word 0x40490fdb /*3.1415927*/
glabel D_80054BC8
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BCC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BD0
.word 0x40490fdb /*3.1415927*/
glabel D_80054BD4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BD8
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06D8B0
/* 0A23E0 7F06D8B0 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0A23E4 7F06D8B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A23E8 7F06D8B8 AFA500BC */  sw    $a1, 0xbc($sp)
/* 0A23EC 7F06D8BC AFA700C4 */  sw    $a3, 0xc4($sp)
/* 0A23F0 7F06D8C0 94CE0000 */  lhu   $t6, ($a2)
/* 0A23F4 7F06D8C4 AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 0A23F8 7F06D8C8 8CCF0004 */  lw    $t7, 4($a2)
/* 0A23FC 7F06D8CC AFAF00B0 */  sw    $t7, 0xb0($sp)
/* 0A2400 7F06D8D0 85F9000E */  lh    $t9, 0xe($t7)
/* 0A2404 7F06D8D4 AFB90064 */  sw    $t9, 0x64($sp)
/* 0A2408 7F06D8D8 85E80010 */  lh    $t0, 0x10($t7)
/* 0A240C 7F06D8DC AFA80060 */  sw    $t0, 0x60($sp)
/* 0A2410 7F06D8E0 85E90012 */  lh    $t1, 0x12($t7)
/* 0A2414 7F06D8E4 AFA9005C */  sw    $t1, 0x5c($sp)
/* 0A2418 7F06D8E8 8CAB000C */  lw    $t3, 0xc($a1)
/* 0A241C 7F06D8EC AFAB0058 */  sw    $t3, 0x58($sp)
/* 0A2420 7F06D8F0 8CCC0008 */  lw    $t4, 8($a2)
/* 0A2424 7F06D8F4 00003025 */  move  $a2, $zero
/* 0A2428 7F06D8F8 11800006 */  beqz  $t4, .L7F06D914
/* 0A242C 7F06D8FC AFAC001C */   sw    $t4, 0x1c($sp)
/* 0A2430 7F06D900 00A02025 */  move  $a0, $a1
/* 0A2434 7F06D904 0FC1B198 */  jal   modelFindNodeMtx
/* 0A2438 7F06D908 01802825 */   move  $a1, $t4
/* 0A243C 7F06D90C 10000003 */  b     .L7F06D91C
/* 0A2440 7F06D910 AFA200AC */   sw    $v0, 0xac($sp)
.L7F06D914:
/* 0A2444 7F06D914 8C8E0000 */  lw    $t6, ($a0)
/* 0A2448 7F06D918 AFAE00AC */  sw    $t6, 0xac($sp)
.L7F06D91C:
/* 0A244C 7F06D91C 8FAF00AC */  lw    $t7, 0xac($sp)
/* 0A2450 7F06D920 8FA90064 */  lw    $t1, 0x64($sp)
/* 0A2454 7F06D924 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A2458 7F06D928 11E00017 */  beqz  $t7, .L7F06D988
/* 0A245C 7F06D92C 00095980 */   sll   $t3, $t1, 6
/* 0A2460 7F06D930 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A2464 7F06D934 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 0A2468 7F06D938 0FC1624B */  jal   matrix_4x4_set_position_and_rotation_around_xyz
/* 0A246C 7F06D93C 27A60068 */   addiu $a2, $sp, 0x68
/* 0A2470 7F06D940 8FB90064 */  lw    $t9, 0x64($sp)
/* 0A2474 7F06D944 8FB80058 */  lw    $t8, 0x58($sp)
/* 0A2478 7F06D948 8FA400AC */  lw    $a0, 0xac($sp)
/* 0A247C 7F06D94C 00194180 */  sll   $t0, $t9, 6
/* 0A2480 7F06D950 01183021 */  addu  $a2, $t0, $t8
/* 0A2484 7F06D954 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0A2488 7F06D958 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A248C 7F06D95C 27A50068 */   addiu $a1, $sp, 0x68
/* 0A2490 7F06D960 3C028003 */  lui   $v0, %hi(D_80036090)
/* 0A2494 7F06D964 8C426090 */  lw    $v0, %lo(D_80036090)($v0)
/* 0A2498 7F06D968 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0A249C 7F06D96C 8FA40064 */  lw    $a0, 0x64($sp)
/* 0A24A0 7F06D970 5040000A */  beql  $v0, $zero, .L7F06D99C
/* 0A24A4 7F06D974 8FAA00B4 */   lw    $t2, 0xb4($sp)
/* 0A24A8 7F06D978 0040F809 */  jalr  $v0
/* 0A24AC 7F06D97C 00C02825 */  move  $a1, $a2
/* 0A24B0 7F06D980 10000006 */  b     .L7F06D99C
/* 0A24B4 7F06D984 8FAA00B4 */   lw    $t2, 0xb4($sp)
.L7F06D988:
/* 0A24B8 7F06D988 8FAC0058 */  lw    $t4, 0x58($sp)
/* 0A24BC 7F06D98C 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 0A24C0 7F06D990 0FC1624B */  jal   matrix_4x4_set_position_and_rotation_around_xyz
/* 0A24C4 7F06D994 016C3021 */   addu  $a2, $t3, $t4
/* 0A24C8 7F06D998 8FAA00B4 */  lw    $t2, 0xb4($sp)
.L7F06D99C:
/* 0A24CC 7F06D99C 8FA400C4 */  lw    $a0, 0xc4($sp)
/* 0A24D0 7F06D9A0 314D0100 */  andi  $t5, $t2, 0x100
/* 0A24D4 7F06D9A4 51A0001D */  beql  $t5, $zero, .L7F06DA1C
/* 0A24D8 7F06D9A8 8FAC00B4 */   lw    $t4, 0xb4($sp)
/* 0A24DC 7F06D9AC 0FC16CFD */  jal   quaternion_set_rotation_around_xyzf
/* 0A24E0 7F06D9B0 27A5003C */   addiu $a1, $sp, 0x3c
/* 0A24E4 7F06D9B4 27A4003C */  addiu $a0, $sp, 0x3c
/* 0A24E8 7F06D9B8 3C053F00 */  lui   $a1, 0x3f00
/* 0A24EC 7F06D9BC 0FC16F1A */  jal   quaternion_7F05BC68
/* 0A24F0 7F06D9C0 27A6002C */   addiu $a2, $sp, 0x2c
/* 0A24F4 7F06D9C4 8FAE00AC */  lw    $t6, 0xac($sp)
/* 0A24F8 7F06D9C8 8FB80060 */  lw    $t8, 0x60($sp)
/* 0A24FC 7F06D9CC 27A5002C */  addiu $a1, $sp, 0x2c
/* 0A2500 7F06D9D0 11C0000D */  beqz  $t6, .L7F06DA08
/* 0A2504 7F06D9D4 00184980 */   sll   $t1, $t8, 6
/* 0A2508 7F06D9D8 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A250C 7F06D9DC 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A2510 7F06D9E0 27A60068 */   addiu $a2, $sp, 0x68
/* 0A2514 7F06D9E4 8FAF0060 */  lw    $t7, 0x60($sp)
/* 0A2518 7F06D9E8 8FA80058 */  lw    $t0, 0x58($sp)
/* 0A251C 7F06D9EC 8FA400AC */  lw    $a0, 0xac($sp)
/* 0A2520 7F06D9F0 000FC980 */  sll   $t9, $t7, 6
/* 0A2524 7F06D9F4 27A50068 */  addiu $a1, $sp, 0x68
/* 0A2528 7F06D9F8 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A252C 7F06D9FC 03283021 */   addu  $a2, $t9, $t0
/* 0A2530 7F06DA00 10000006 */  b     .L7F06DA1C
/* 0A2534 7F06DA04 8FAC00B4 */   lw    $t4, 0xb4($sp)
.L7F06DA08:
/* 0A2538 7F06DA08 8FAB0058 */  lw    $t3, 0x58($sp)
/* 0A253C 7F06DA0C 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A2540 7F06DA10 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A2544 7F06DA14 012B3021 */   addu  $a2, $t1, $t3
/* 0A2548 7F06DA18 8FAC00B4 */  lw    $t4, 0xb4($sp)
.L7F06DA1C:
/* 0A254C 7F06DA1C 8FAD00AC */  lw    $t5, 0xac($sp)
/* 0A2550 7F06DA20 318A0200 */  andi  $t2, $t4, 0x200
/* 0A2554 7F06DA24 5140004A */  beql  $t2, $zero, .L7F06DB50
/* 0A2558 7F06DA28 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A255C 7F06DA2C 11A00004 */  beqz  $t5, .L7F06DA40
/* 0A2560 7F06DA30 8FAF005C */   lw    $t7, 0x5c($sp)
/* 0A2564 7F06DA34 27AE0068 */  addiu $t6, $sp, 0x68
/* 0A2568 7F06DA38 10000005 */  b     .L7F06DA50
/* 0A256C 7F06DA3C AFAE0028 */   sw    $t6, 0x28($sp)
.L7F06DA40:
/* 0A2570 7F06DA40 8FA80058 */  lw    $t0, 0x58($sp)
/* 0A2574 7F06DA44 000FC980 */  sll   $t9, $t7, 6
/* 0A2578 7F06DA48 0328C021 */  addu  $t8, $t9, $t0
/* 0A257C 7F06DA4C AFB80028 */  sw    $t8, 0x28($sp)
.L7F06DA50:
/* 0A2580 7F06DA50 8FA900C4 */  lw    $t1, 0xc4($sp)
/* 0A2584 7F06DA54 3C018005 */  lui   $at, %hi(D_80054BC4)
/* 0A2588 7F06DA58 C4244BC4 */  lwc1  $f4, %lo(D_80054BC4)($at)
/* 0A258C 7F06DA5C C52C0004 */  lwc1  $f12, 4($t1)
/* 0A2590 7F06DA60 3C018005 */  lui   $at, %hi(D_80054BC8)
/* 0A2594 7F06DA64 8FA50028 */  lw    $a1, 0x28($sp)
/* 0A2598 7F06DA68 4604603C */  c.lt.s $f12, $f4
/* 0A259C 7F06DA6C 00000000 */  nop   
/* 0A25A0 7F06DA70 45000007 */  bc1f  .L7F06DA90
/* 0A25A4 7F06DA74 00000000 */   nop   
/* 0A25A8 7F06DA78 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A25AC 7F06DA7C 44813000 */  mtc1  $at, $f6
/* 0A25B0 7F06DA80 00000000 */  nop   
/* 0A25B4 7F06DA84 46066302 */  mul.s $f12, $f12, $f6
/* 0A25B8 7F06DA88 10000009 */  b     .L7F06DAB0
/* 0A25BC 7F06DA8C 00000000 */   nop   
.L7F06DA90:
/* 0A25C0 7F06DA90 C4284BC8 */  lwc1  $f8, %lo(D_80054BC8)($at)
/* 0A25C4 7F06DA94 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A25C8 7F06DA98 44818000 */  mtc1  $at, $f16
/* 0A25CC 7F06DA9C 460C4281 */  sub.s $f10, $f8, $f12
/* 0A25D0 7F06DAA0 3C018005 */  lui   $at, %hi(D_80054BCC)
/* 0A25D4 7F06DAA4 C4244BCC */  lwc1  $f4, %lo(D_80054BCC)($at)
/* 0A25D8 7F06DAA8 46105482 */  mul.s $f18, $f10, $f16
/* 0A25DC 7F06DAAC 46122301 */  sub.s $f12, $f4, $f18
.L7F06DAB0:
/* 0A25E0 7F06DAB0 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0A25E4 7F06DAB4 E7AC0024 */   swc1  $f12, 0x24($sp)
/* 0A25E8 7F06DAB8 3C018005 */  lui   $at, %hi(D_80054BD0)
/* 0A25EC 7F06DABC C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 0A25F0 7F06DAC0 C4264BD0 */  lwc1  $f6, %lo(D_80054BD0)($at)
/* 0A25F4 7F06DAC4 3C018005 */  lui   $at, %hi(D_80054BD4)
/* 0A25F8 7F06DAC8 460C303E */  c.le.s $f6, $f12
/* 0A25FC 7F06DACC 00000000 */  nop   
/* 0A2600 7F06DAD0 45000003 */  bc1f  .L7F06DAE0
/* 0A2604 7F06DAD4 00000000 */   nop   
/* 0A2608 7F06DAD8 C4284BD4 */  lwc1  $f8, %lo(D_80054BD4)($at)
/* 0A260C 7F06DADC 460C4301 */  sub.s $f12, $f8, $f12
.L7F06DAE0:
/* 0A2610 7F06DAE0 3C018005 */  lui    $at, %hi(D_80054BD8)
/* 0A2614 7F06DAE4 C42A4BD8 */  lwc1  $f10, %lo(D_80054BD8)($at)
/* 0A2618 7F06DAE8 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0A261C 7F06DAEC 460A603C */  c.lt.s $f12, $f10
/* 0A2620 7F06DAF0 00000000 */  nop   
/* 0A2624 7F06DAF4 45020006 */  bc1fl .L7F06DB10
/* 0A2628 7F06DAF8 44816000 */   mtc1  $at, $f12
/* 0A262C 7F06DAFC 0FC16A78 */  jal   sub_GAME_7F05A9E0
/* 0A2630 7F06DB00 00000000 */   nop   
/* 0A2634 7F06DB04 10000003 */  b     .L7F06DB14
/* 0A2638 7F06DB08 46000306 */   mov.s $f12, $f0
/* 0A263C 7F06DB0C 44816000 */  mtc1  $at, $f12
.L7F06DB10:
/* 0A2640 7F06DB10 00000000 */  nop   
.L7F06DB14:
/* 0A2644 7F06DB14 0FC16293 */  jal   matrix_column_3_scalar_multiply_2
/* 0A2648 7F06DB18 8FA50028 */   lw    $a1, 0x28($sp)
/* 0A264C 7F06DB1C 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A2650 7F06DB20 0FC16266 */  jal   matrix_4x4_set_position
/* 0A2654 7F06DB24 8FA50028 */   lw    $a1, 0x28($sp)
/* 0A2658 7F06DB28 8FAB00AC */  lw    $t3, 0xac($sp)
/* 0A265C 7F06DB2C 8FAC005C */  lw    $t4, 0x5c($sp)
/* 0A2660 7F06DB30 8FAD0058 */  lw    $t5, 0x58($sp)
/* 0A2664 7F06DB34 11600005 */  beqz  $t3, .L7F06DB4C
/* 0A2668 7F06DB38 01602025 */   move  $a0, $t3
/* 0A266C 7F06DB3C 000C5180 */  sll   $t2, $t4, 6
/* 0A2670 7F06DB40 014D3021 */  addu  $a2, $t2, $t5
/* 0A2674 7F06DB44 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2678 7F06DB48 8FA50028 */   lw    $a1, 0x28($sp)
.L7F06DB4C:
/* 0A267C 7F06DB4C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06DB50:
/* 0A2680 7F06DB50 27BD00B8 */  addiu $sp, $sp, 0xb8
/* 0A2684 7F06DB54 03E00008 */  jr    $ra
/* 0A2688 7F06DB58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06DB5C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BDC
.word 0x40490fdb /*3.1415927*/
glabel D_80054BE0
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BE4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BE8
.word 0x40490fdb /*3.1415927*/
glabel D_80054BEC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BF0
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06DB5C
/* 0A268C 7F06DB5C 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 0A2690 7F06DB60 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A2694 7F06DB64 AFA500AC */  sw    $a1, 0xac($sp)
/* 0A2698 7F06DB68 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 0A269C 7F06DB6C 94CE0000 */  lhu   $t6, ($a2)
/* 0A26A0 7F06DB70 AFAE00A4 */  sw    $t6, 0xa4($sp)
/* 0A26A4 7F06DB74 8CCF0004 */  lw    $t7, 4($a2)
/* 0A26A8 7F06DB78 AFAF00A0 */  sw    $t7, 0xa0($sp)
/* 0A26AC 7F06DB7C 85F9000E */  lh    $t9, 0xe($t7)
/* 0A26B0 7F06DB80 AFB90054 */  sw    $t9, 0x54($sp)
/* 0A26B4 7F06DB84 85E80010 */  lh    $t0, 0x10($t7)
/* 0A26B8 7F06DB88 AFA80050 */  sw    $t0, 0x50($sp)
/* 0A26BC 7F06DB8C 85E90012 */  lh    $t1, 0x12($t7)
/* 0A26C0 7F06DB90 AFA9004C */  sw    $t1, 0x4c($sp)
/* 0A26C4 7F06DB94 8CAB000C */  lw    $t3, 0xc($a1)
/* 0A26C8 7F06DB98 AFAB0048 */  sw    $t3, 0x48($sp)
/* 0A26CC 7F06DB9C 8CCC0008 */  lw    $t4, 8($a2)
/* 0A26D0 7F06DBA0 00003025 */  move  $a2, $zero
/* 0A26D4 7F06DBA4 11800006 */  beqz  $t4, .L7F06DBC0
/* 0A26D8 7F06DBA8 AFAC001C */   sw    $t4, 0x1c($sp)
/* 0A26DC 7F06DBAC 00A02025 */  move  $a0, $a1
/* 0A26E0 7F06DBB0 0FC1B198 */  jal   modelFindNodeMtx
/* 0A26E4 7F06DBB4 01802825 */   move  $a1, $t4
/* 0A26E8 7F06DBB8 10000003 */  b     .L7F06DBC8
/* 0A26EC 7F06DBBC AFA2009C */   sw    $v0, 0x9c($sp)
.L7F06DBC0:
/* 0A26F0 7F06DBC0 8C8E0000 */  lw    $t6, ($a0)
/* 0A26F4 7F06DBC4 AFAE009C */  sw    $t6, 0x9c($sp)
.L7F06DBC8:
/* 0A26F8 7F06DBC8 8FAF009C */  lw    $t7, 0x9c($sp)
/* 0A26FC 7F06DBCC 8FA90054 */  lw    $t1, 0x54($sp)
/* 0A2700 7F06DBD0 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 0A2704 7F06DBD4 11E00017 */  beqz  $t7, .L7F06DC34
/* 0A2708 7F06DBD8 00095980 */   sll   $t3, $t1, 6
/* 0A270C 7F06DBDC 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 0A2710 7F06DBE0 8FA500B4 */  lw    $a1, 0xb4($sp)
/* 0A2714 7F06DBE4 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A2718 7F06DBE8 27A60058 */   addiu $a2, $sp, 0x58
/* 0A271C 7F06DBEC 8FB90054 */  lw    $t9, 0x54($sp)
/* 0A2720 7F06DBF0 8FB80048 */  lw    $t8, 0x48($sp)
/* 0A2724 7F06DBF4 8FA4009C */  lw    $a0, 0x9c($sp)
/* 0A2728 7F06DBF8 00194180 */  sll   $t0, $t9, 6
/* 0A272C 7F06DBFC 01183021 */  addu  $a2, $t0, $t8
/* 0A2730 7F06DC00 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0A2734 7F06DC04 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2738 7F06DC08 27A50058 */   addiu $a1, $sp, 0x58
/* 0A273C 7F06DC0C 3C028003 */  lui   $v0, %hi(D_80036090)
/* 0A2740 7F06DC10 8C426090 */  lw    $v0, %lo(D_80036090)($v0)
/* 0A2744 7F06DC14 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0A2748 7F06DC18 8FA40054 */  lw    $a0, 0x54($sp)
/* 0A274C 7F06DC1C 5040000A */  beql  $v0, $zero, .L7F06DC48
/* 0A2750 7F06DC20 8FAA00A4 */   lw    $t2, 0xa4($sp)
/* 0A2754 7F06DC24 0040F809 */  jalr  $v0
/* 0A2758 7F06DC28 00C02825 */  move  $a1, $a2
/* 0A275C 7F06DC2C 10000006 */  b     .L7F06DC48
/* 0A2760 7F06DC30 8FAA00A4 */   lw    $t2, 0xa4($sp)
.L7F06DC34:
/* 0A2764 7F06DC34 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0A2768 7F06DC38 8FA500B4 */  lw    $a1, 0xb4($sp)
/* 0A276C 7F06DC3C 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A2770 7F06DC40 016C3021 */   addu  $a2, $t3, $t4
/* 0A2774 7F06DC44 8FAA00A4 */  lw    $t2, 0xa4($sp)
.L7F06DC48:
/* 0A2778 7F06DC48 8FA400B4 */  lw    $a0, 0xb4($sp)
/* 0A277C 7F06DC4C 3C053F00 */  lui   $a1, 0x3f00
/* 0A2780 7F06DC50 314D0100 */  andi  $t5, $t2, 0x100
/* 0A2784 7F06DC54 51A00019 */  beql  $t5, $zero, .L7F06DCBC
/* 0A2788 7F06DC58 8FAC00A4 */   lw    $t4, 0xa4($sp)
/* 0A278C 7F06DC5C 0FC16F1A */  jal   quaternion_7F05BC68
/* 0A2790 7F06DC60 27A6002C */   addiu $a2, $sp, 0x2c
/* 0A2794 7F06DC64 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0A2798 7F06DC68 8FB80050 */  lw    $t8, 0x50($sp)
/* 0A279C 7F06DC6C 27A5002C */  addiu $a1, $sp, 0x2c
/* 0A27A0 7F06DC70 11C0000D */  beqz  $t6, .L7F06DCA8
/* 0A27A4 7F06DC74 00184980 */   sll   $t1, $t8, 6
/* 0A27A8 7F06DC78 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 0A27AC 7F06DC7C 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A27B0 7F06DC80 27A60058 */   addiu $a2, $sp, 0x58
/* 0A27B4 7F06DC84 8FAF0050 */  lw    $t7, 0x50($sp)
/* 0A27B8 7F06DC88 8FA80048 */  lw    $t0, 0x48($sp)
/* 0A27BC 7F06DC8C 8FA4009C */  lw    $a0, 0x9c($sp)
/* 0A27C0 7F06DC90 000FC980 */  sll   $t9, $t7, 6
/* 0A27C4 7F06DC94 27A50058 */  addiu $a1, $sp, 0x58
/* 0A27C8 7F06DC98 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A27CC 7F06DC9C 03283021 */   addu  $a2, $t9, $t0
/* 0A27D0 7F06DCA0 10000006 */  b     .L7F06DCBC
/* 0A27D4 7F06DCA4 8FAC00A4 */   lw    $t4, 0xa4($sp)
.L7F06DCA8:
/* 0A27D8 7F06DCA8 8FAB0048 */  lw    $t3, 0x48($sp)
/* 0A27DC 7F06DCAC 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 0A27E0 7F06DCB0 0FC16E6D */  jal   quaternion_to_transform_matrix
/* 0A27E4 7F06DCB4 012B3021 */   addu  $a2, $t1, $t3
/* 0A27E8 7F06DCB8 8FAC00A4 */  lw    $t4, 0xa4($sp)
.L7F06DCBC:
/* 0A27EC 7F06DCBC 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0A27F0 7F06DCC0 318A0200 */  andi  $t2, $t4, 0x200
/* 0A27F4 7F06DCC4 5140004C */  beql  $t2, $zero, .L7F06DDF8
/* 0A27F8 7F06DCC8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A27FC 7F06DCCC 11A00004 */  beqz  $t5, .L7F06DCE0
/* 0A2800 7F06DCD0 8FAF004C */   lw    $t7, 0x4c($sp)
/* 0A2804 7F06DCD4 27AE0058 */  addiu $t6, $sp, 0x58
/* 0A2808 7F06DCD8 10000005 */  b     .L7F06DCF0
/* 0A280C 7F06DCDC AFAE0028 */   sw    $t6, 0x28($sp)
.L7F06DCE0:
/* 0A2810 7F06DCE0 8FA80048 */  lw    $t0, 0x48($sp)
/* 0A2814 7F06DCE4 000FC980 */  sll   $t9, $t7, 6
/* 0A2818 7F06DCE8 0328C021 */  addu  $t8, $t9, $t0
/* 0A281C 7F06DCEC AFB80028 */  sw    $t8, 0x28($sp)
.L7F06DCF0:
/* 0A2820 7F06DCF0 8FA900B4 */  lw    $t1, 0xb4($sp)
/* 0A2824 7F06DCF4 0FC16B2C */  jal   acosf
/* 0A2828 7F06DCF8 C52C0000 */   lwc1  $f12, ($t1)
/* 0A282C 7F06DCFC 46000080 */  add.s $f2, $f0, $f0
/* 0A2830 7F06DD00 3C018005 */  lui   $at, %hi(D_80054BDC)
/* 0A2834 7F06DD04 C4244BDC */  lwc1  $f4, %lo(D_80054BDC)($at)
/* 0A2838 7F06DD08 3C018005 */  lui   $at, %hi(D_80054BE0)
/* 0A283C 7F06DD0C 8FA50028 */  lw    $a1, 0x28($sp)
/* 0A2840 7F06DD10 4604103C */  c.lt.s $f2, $f4
/* 0A2844 7F06DD14 00000000 */  nop   
/* 0A2848 7F06DD18 45000007 */  bc1f  .L7F06DD38
/* 0A284C 7F06DD1C 00000000 */   nop   
/* 0A2850 7F06DD20 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A2854 7F06DD24 44813000 */  mtc1  $at, $f6
/* 0A2858 7F06DD28 00000000 */  nop   
/* 0A285C 7F06DD2C 46061302 */  mul.s $f12, $f2, $f6
/* 0A2860 7F06DD30 10000009 */  b     .L7F06DD58
/* 0A2864 7F06DD34 00000000 */   nop   
.L7F06DD38:
/* 0A2868 7F06DD38 C4284BE0 */  lwc1  $f8, %lo(D_80054BE0)($at)
/* 0A286C 7F06DD3C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A2870 7F06DD40 44818000 */  mtc1  $at, $f16
/* 0A2874 7F06DD44 46024281 */  sub.s $f10, $f8, $f2
/* 0A2878 7F06DD48 3C018005 */  lui   $at, %hi(D_80054BE4)
/* 0A287C 7F06DD4C C4244BE4 */  lwc1  $f4, %lo(D_80054BE4)($at)
/* 0A2880 7F06DD50 46105482 */  mul.s $f18, $f10, $f16
/* 0A2884 7F06DD54 46122301 */  sub.s $f12, $f4, $f18
.L7F06DD58:
/* 0A2888 7F06DD58 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0A288C 7F06DD5C E7AC0024 */   swc1  $f12, 0x24($sp)
/* 0A2890 7F06DD60 3C018005 */  lui   $at, %hi(D_80054BE8)
/* 0A2894 7F06DD64 C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 0A2898 7F06DD68 C4264BE8 */  lwc1  $f6, %lo(D_80054BE8)($at)
/* 0A289C 7F06DD6C 3C018005 */  lui   $at, %hi(D_80054BEC)
/* 0A28A0 7F06DD70 460C303E */  c.le.s $f6, $f12
/* 0A28A4 7F06DD74 00000000 */  nop   
/* 0A28A8 7F06DD78 45000003 */  bc1f  .L7F06DD88
/* 0A28AC 7F06DD7C 00000000 */   nop   
/* 0A28B0 7F06DD80 C4284BEC */  lwc1  $f8, %lo(D_80054BEC)($at)
/* 0A28B4 7F06DD84 460C4301 */  sub.s $f12, $f8, $f12
.L7F06DD88:
/* 0A28B8 7F06DD88 3C018005 */  lui    $at, %hi(D_80054BF0)
/* 0A28BC 7F06DD8C C42A4BF0 */  lwc1  $f10, %lo(D_80054BF0)($at)
/* 0A28C0 7F06DD90 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0A28C4 7F06DD94 460A603C */  c.lt.s $f12, $f10
/* 0A28C8 7F06DD98 00000000 */  nop   
/* 0A28CC 7F06DD9C 45020006 */  bc1fl .L7F06DDB8
/* 0A28D0 7F06DDA0 44816000 */   mtc1  $at, $f12
/* 0A28D4 7F06DDA4 0FC16A78 */  jal   sub_GAME_7F05A9E0
/* 0A28D8 7F06DDA8 00000000 */   nop   
/* 0A28DC 7F06DDAC 10000003 */  b     .L7F06DDBC
/* 0A28E0 7F06DDB0 46000306 */   mov.s $f12, $f0
/* 0A28E4 7F06DDB4 44816000 */  mtc1  $at, $f12
.L7F06DDB8:
/* 0A28E8 7F06DDB8 00000000 */  nop   
.L7F06DDBC:
/* 0A28EC 7F06DDBC 0FC16293 */  jal   matrix_column_3_scalar_multiply_2
/* 0A28F0 7F06DDC0 8FA50028 */   lw    $a1, 0x28($sp)
/* 0A28F4 7F06DDC4 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 0A28F8 7F06DDC8 0FC16266 */  jal   matrix_4x4_set_position
/* 0A28FC 7F06DDCC 8FA50028 */   lw    $a1, 0x28($sp)
/* 0A2900 7F06DDD0 8FAB009C */  lw    $t3, 0x9c($sp)
/* 0A2904 7F06DDD4 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0A2908 7F06DDD8 8FAD0048 */  lw    $t5, 0x48($sp)
/* 0A290C 7F06DDDC 11600005 */  beqz  $t3, .L7F06DDF4
/* 0A2910 7F06DDE0 01602025 */   move  $a0, $t3
/* 0A2914 7F06DDE4 000C5180 */  sll   $t2, $t4, 6
/* 0A2918 7F06DDE8 014D3021 */  addu  $a2, $t2, $t5
/* 0A291C 7F06DDEC 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2920 7F06DDF0 8FA50028 */   lw    $a1, 0x28($sp)
.L7F06DDF4:
/* 0A2924 7F06DDF4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06DDF8:
/* 0A2928 7F06DDF8 27BD00A8 */  addiu $sp, $sp, 0xa8
/* 0A292C 7F06DDFC 03E00008 */  jr    $ra
/* 0A2930 7F06DE00 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06DE04(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06DE04
/* 0A2934 7F06DE04 30CF0007 */  andi  $t7, $a2, 7
/* 0A2938 7F06DE08 24180008 */  li    $t8, 8
/* 0A293C 7F06DE0C 030F4823 */  subu  $t1, $t8, $t7
/* 0A2940 7F06DE10 30AA00FF */  andi  $t2, $a1, 0xff
/* 0A2944 7F06DE14 313900FF */  andi  $t9, $t1, 0xff
/* 0A2948 7F06DE18 000638C2 */  srl   $a3, $a2, 3
/* 0A294C 7F06DE1C 0159082A */  slt   $at, $t2, $t9
/* 0A2950 7F06DE20 AFA50004 */  sw    $a1, 4($sp)
/* 0A2954 7F06DE24 00001825 */  move  $v1, $zero
/* 0A2958 7F06DE28 314200FF */  andi  $v0, $t2, 0xff
/* 0A295C 7F06DE2C 00872021 */  addu  $a0, $a0, $a3
/* 0A2960 7F06DE30 14200013 */  bnez  $at, .L7F06DE80
/* 0A2964 7F06DE34 312800FF */   andi  $t0, $t1, 0xff
/* 0A2968 7F06DE38 00402825 */  move  $a1, $v0
.L7F06DE3C:
/* 0A296C 7F06DE3C 908C0000 */  lbu   $t4, ($a0)
/* 0A2970 7F06DE40 240D0001 */  li    $t5, 1
/* 0A2974 7F06DE44 010D7004 */  sllv  $t6, $t5, $t0
/* 0A2978 7F06DE48 25CFFFFF */  addiu $t7, $t6, -1
/* 0A297C 7F06DE4C 00A81023 */  subu  $v0, $a1, $t0
/* 0A2980 7F06DE50 018FC024 */  and   $t8, $t4, $t7
/* 0A2984 7F06DE54 304500FF */  andi  $a1, $v0, 0xff
/* 0A2988 7F06DE58 3319FFFF */  andi  $t9, $t8, 0xffff
/* 0A298C 7F06DE5C 00B95804 */  sllv  $t3, $t9, $a1
/* 0A2990 7F06DE60 006B1825 */  or    $v1, $v1, $t3
/* 0A2994 7F06DE64 306DFFFF */  andi  $t5, $v1, 0xffff
/* 0A2998 7F06DE68 28A10008 */  slti  $at, $a1, 8
/* 0A299C 7F06DE6C 00A01025 */  move  $v0, $a1
/* 0A29A0 7F06DE70 01A01825 */  move  $v1, $t5
/* 0A29A4 7F06DE74 24840001 */  addiu $a0, $a0, 1
/* 0A29A8 7F06DE78 1020FFF0 */  beqz  $at, .L7F06DE3C
/* 0A29AC 7F06DE7C 24080008 */   li    $t0, 8
.L7F06DE80:
/* 0A29B0 7F06DE80 1840000A */  blez  $v0, .L7F06DEAC
/* 0A29B4 7F06DE84 01026023 */   subu  $t4, $t0, $v0
/* 0A29B8 7F06DE88 908E0000 */  lbu   $t6, ($a0)
/* 0A29BC 7F06DE8C 24180001 */  li    $t8, 1
/* 0A29C0 7F06DE90 0058C804 */  sllv  $t9, $t8, $v0
/* 0A29C4 7F06DE94 272BFFFF */  addiu $t3, $t9, -1
/* 0A29C8 7F06DE98 018E7807 */  srav  $t7, $t6, $t4
/* 0A29CC 7F06DE9C 01EB6824 */  and   $t5, $t7, $t3
/* 0A29D0 7F06DEA0 006D1825 */  or    $v1, $v1, $t5
/* 0A29D4 7F06DEA4 306EFFFF */  andi  $t6, $v1, 0xffff
/* 0A29D8 7F06DEA8 01C01825 */  move  $v1, $t6
.L7F06DEAC:
/* 0A29DC 7F06DEAC 240C0010 */  li    $t4, 16
/* 0A29E0 7F06DEB0 018AC023 */  subu  $t8, $t4, $t2
/* 0A29E4 7F06DEB4 03031804 */  sllv  $v1, $v1, $t8
/* 0A29E8 7F06DEB8 03E00008 */  jr    $ra
/* 0A29EC 7F06DEBC 3062FFFF */   andi  $v0, $v1, 0xffff
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06DEC0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BF4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06DEC0
/* 0A29F0 7F06DEC0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A29F4 7F06DEC4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A29F8 7F06DEC8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A29FC 7F06DECC AFA50034 */  sw    $a1, 0x34($sp)
/* 0A2A00 7F06DED0 AFA60038 */  sw    $a2, 0x38($sp)
/* 0A2A04 7F06DED4 10A0000B */  beqz  $a1, .L7F06DF04
/* 0A2A08 7F06DED8 90F00006 */   lbu   $s0, 6($a3)
/* 0A2A0C 7F06DEDC 8CD80004 */  lw    $t8, 4($a2)
/* 0A2A10 7F06DEE0 0004C880 */  sll   $t9, $a0, 2
/* 0A2A14 7F06DEE4 0324C823 */  subu  $t9, $t9, $a0
/* 0A2A18 7F06DEE8 0019C840 */  sll   $t9, $t9, 1
/* 0A2A1C 7F06DEEC 03194021 */  addu  $t0, $t8, $t9
/* 0A2A20 7F06DEF0 95090004 */  lhu   $t1, 4($t0)
/* 0A2A24 7F06DEF4 01300019 */  multu $t1, $s0
/* 0A2A28 7F06DEF8 00003012 */  mflo  $a2
/* 0A2A2C 7F06DEFC 1000000D */  b     .L7F06DF34
/* 0A2A30 7F06DF00 8FA40040 */   lw    $a0, 0x40($sp)
.L7F06DF04:
/* 0A2A34 7F06DF04 8FAA0038 */  lw    $t2, 0x38($sp)
/* 0A2A38 7F06DF08 00046080 */  sll   $t4, $a0, 2
/* 0A2A3C 7F06DF0C 01846023 */  subu  $t4, $t4, $a0
/* 0A2A40 7F06DF10 8D4B0004 */  lw    $t3, 4($t2)
/* 0A2A44 7F06DF14 000C6040 */  sll   $t4, $t4, 1
/* 0A2A48 7F06DF18 016C6821 */  addu  $t5, $t3, $t4
/* 0A2A4C 7F06DF1C 95AE0002 */  lhu   $t6, 2($t5)
/* 0A2A50 7F06DF20 01D00019 */  multu $t6, $s0
/* 0A2A54 7F06DF24 00003012 */  mflo  $a2
/* 0A2A58 7F06DF28 00000000 */  nop   
/* 0A2A5C 7F06DF2C 00000000 */  nop   
/* 0A2A60 7F06DF30 8FA40040 */  lw    $a0, 0x40($sp)
.L7F06DF34:
/* 0A2A64 7F06DF34 320500FF */  andi  $a1, $s0, 0xff
/* 0A2A68 7F06DF38 0FC1B781 */  jal   sub_GAME_7F06DE04
/* 0A2A6C 7F06DF3C AFA6002C */   sw    $a2, 0x2c($sp)
/* 0A2A70 7F06DF40 8FA6002C */  lw    $a2, 0x2c($sp)
/* 0A2A74 7F06DF44 A7A20024 */  sh    $v0, 0x24($sp)
/* 0A2A78 7F06DF48 8FA40040 */  lw    $a0, 0x40($sp)
/* 0A2A7C 7F06DF4C 00D03021 */  addu  $a2, $a2, $s0
/* 0A2A80 7F06DF50 AFA6002C */  sw    $a2, 0x2c($sp)
/* 0A2A84 7F06DF54 0FC1B781 */  jal   sub_GAME_7F06DE04
/* 0A2A88 7F06DF58 320500FF */   andi  $a1, $s0, 0xff
/* 0A2A8C 7F06DF5C 8FA6002C */  lw    $a2, 0x2c($sp)
/* 0A2A90 7F06DF60 A7A20026 */  sh    $v0, 0x26($sp)
/* 0A2A94 7F06DF64 8FA40040 */  lw    $a0, 0x40($sp)
/* 0A2A98 7F06DF68 320500FF */  andi  $a1, $s0, 0xff
/* 0A2A9C 7F06DF6C 0FC1B781 */  jal   sub_GAME_7F06DE04
/* 0A2AA0 7F06DF70 00D03021 */   addu  $a2, $a2, $s0
/* 0A2AA4 7F06DF74 97AF0024 */  lhu   $t7, 0x24($sp)
/* 0A2AA8 7F06DF78 3C018005 */  lui   $at, %hi(D_80054BF4)
/* 0A2AAC 7F06DF7C C4204BF4 */  lwc1  $f0, %lo(D_80054BF4)($at)
/* 0A2AB0 7F06DF80 448F2000 */  mtc1  $t7, $f4
/* 0A2AB4 7F06DF84 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0A2AB8 7F06DF88 44811000 */  mtc1  $at, $f2
/* 0A2ABC 7F06DF8C 8FA30044 */  lw    $v1, 0x44($sp)
/* 0A2AC0 7F06DF90 A7A20028 */  sh    $v0, 0x28($sp)
/* 0A2AC4 7F06DF94 05E10005 */  bgez  $t7, .L7F06DFAC
/* 0A2AC8 7F06DF98 468021A0 */   cvt.s.w $f6, $f4
/* 0A2ACC 7F06DF9C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A2AD0 7F06DFA0 44814000 */  mtc1  $at, $f8
/* 0A2AD4 7F06DFA4 00000000 */  nop   
/* 0A2AD8 7F06DFA8 46083180 */  add.s $f6, $f6, $f8
.L7F06DFAC:
/* 0A2ADC 7F06DFAC 46003282 */  mul.s $f10, $f6, $f0
/* 0A2AE0 7F06DFB0 46025403 */  div.s $f16, $f10, $f2
/* 0A2AE4 7F06DFB4 E4700000 */  swc1  $f16, ($v1)
/* 0A2AE8 7F06DFB8 8FB80034 */  lw    $t8, 0x34($sp)
/* 0A2AEC 7F06DFBC 97A20026 */  lhu   $v0, 0x26($sp)
/* 0A2AF0 7F06DFC0 97AB0026 */  lhu   $t3, 0x26($sp)
/* 0A2AF4 7F06DFC4 5300001D */  beql  $t8, $zero, .L7F06E03C
/* 0A2AF8 7F06DFC8 448B5000 */   mtc1  $t3, $f10
/* 0A2AFC 7F06DFCC 10400009 */  beqz  $v0, .L7F06DFF4
/* 0A2B00 7F06DFD0 3C190001 */   lui   $t9, 1
/* 0A2B04 7F06DFD4 03224023 */  subu  $t0, $t9, $v0
/* 0A2B08 7F06DFD8 44889000 */  mtc1  $t0, $f18
/* 0A2B0C 7F06DFDC 00000000 */  nop   
/* 0A2B10 7F06DFE0 46809120 */  cvt.s.w $f4, $f18
/* 0A2B14 7F06DFE4 46002202 */  mul.s $f8, $f4, $f0
/* 0A2B18 7F06DFE8 46024183 */  div.s $f6, $f8, $f2
/* 0A2B1C 7F06DFEC 10000004 */  b     .L7F06E000
/* 0A2B20 7F06DFF0 E4660004 */   swc1  $f6, 4($v1)
.L7F06DFF4:
/* 0A2B24 7F06DFF4 44805000 */  mtc1  $zero, $f10
/* 0A2B28 7F06DFF8 00000000 */  nop   
/* 0A2B2C 7F06DFFC E46A0004 */  swc1  $f10, 4($v1)
.L7F06E000:
/* 0A2B30 7F06E000 97A20028 */  lhu   $v0, 0x28($sp)
/* 0A2B34 7F06E004 3C090001 */  lui   $t1, 1
/* 0A2B38 7F06E008 10400008 */  beqz  $v0, .L7F06E02C
/* 0A2B3C 7F06E00C 01225023 */   subu  $t2, $t1, $v0
/* 0A2B40 7F06E010 448A8000 */  mtc1  $t2, $f16
/* 0A2B44 7F06E014 00000000 */  nop   
/* 0A2B48 7F06E018 468084A0 */  cvt.s.w $f18, $f16
/* 0A2B4C 7F06E01C 46009102 */  mul.s $f4, $f18, $f0
/* 0A2B50 7F06E020 46022203 */  div.s $f8, $f4, $f2
/* 0A2B54 7F06E024 10000019 */  b     .L7F06E08C
/* 0A2B58 7F06E028 E4680008 */   swc1  $f8, 8($v1)
.L7F06E02C:
/* 0A2B5C 7F06E02C 44803000 */  mtc1  $zero, $f6
/* 0A2B60 7F06E030 10000016 */  b     .L7F06E08C
/* 0A2B64 7F06E034 E4660008 */   swc1  $f6, 8($v1)
/* 0A2B68 7F06E038 448B5000 */  mtc1  $t3, $f10
.L7F06E03C:
/* 0A2B6C 7F06E03C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A2B70 7F06E040 05610004 */  bgez  $t3, .L7F06E054
/* 0A2B74 7F06E044 46805420 */   cvt.s.w $f16, $f10
/* 0A2B78 7F06E048 44819000 */  mtc1  $at, $f18
/* 0A2B7C 7F06E04C 00000000 */  nop   
/* 0A2B80 7F06E050 46128400 */  add.s $f16, $f16, $f18
.L7F06E054:
/* 0A2B84 7F06E054 46008102 */  mul.s $f4, $f16, $f0
/* 0A2B88 7F06E058 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A2B8C 7F06E05C 46022203 */  div.s $f8, $f4, $f2
/* 0A2B90 7F06E060 E4680004 */  swc1  $f8, 4($v1)
/* 0A2B94 7F06E064 97AC0028 */  lhu   $t4, 0x28($sp)
/* 0A2B98 7F06E068 448C3000 */  mtc1  $t4, $f6
/* 0A2B9C 7F06E06C 05810004 */  bgez  $t4, .L7F06E080
/* 0A2BA0 7F06E070 468032A0 */   cvt.s.w $f10, $f6
/* 0A2BA4 7F06E074 44819000 */  mtc1  $at, $f18
/* 0A2BA8 7F06E078 00000000 */  nop   
/* 0A2BAC 7F06E07C 46125280 */  add.s $f10, $f10, $f18
.L7F06E080:
/* 0A2BB0 7F06E080 46005402 */  mul.s $f16, $f10, $f0
/* 0A2BB4 7F06E084 46028103 */  div.s $f4, $f16, $f2
/* 0A2BB8 7F06E088 E4640008 */  swc1  $f4, 8($v1)
.L7F06E08C:
/* 0A2BBC 7F06E08C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A2BC0 7F06E090 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A2BC4 7F06E094 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A2BC8 7F06E098 03E00008 */  jr    $ra
/* 0A2BCC 7F06E09C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_02_position(ModelRenderData *arg0, Model *model, ModelNode *node) {

}
#else
void process_02_position(ModelRenderData *arg0, Model *model, ModelNode *node);
GLOBAL_ASM(
.text
glabel process_02_position
/* 0A2BD0 7F06E0A0 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0A2BD4 7F06E0A4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A2BD8 7F06E0A8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0A2BDC 7F06E0AC AFA40098 */  sw    $a0, 0x98($sp)
/* 0A2BE0 7F06E0B0 AFA600A0 */  sw    $a2, 0xa0($sp)
/* 0A2BE4 7F06E0B4 3C188003 */  lui   $t8, %hi(D_80036094) 
/* 0A2BE8 7F06E0B8 8CC20004 */  lw    $v0, 4($a2)
/* 0A2BEC 7F06E0BC 8CAF0008 */  lw    $t7, 8($a1)
/* 0A2BF0 7F06E0C0 27186094 */  addiu $t8, %lo(D_80036094) # addiu $t8, $t8, 0x6094
/* 0A2BF4 7F06E0C4 8F010000 */  lw    $at, ($t8)
/* 0A2BF8 7F06E0C8 9444000C */  lhu   $a0, 0xc($v0)
/* 0A2BFC 7F06E0CC 8DE60004 */  lw    $a2, 4($t7)
/* 0A2C00 7F06E0D0 27A30080 */  addiu $v1, $sp, 0x80
/* 0A2C04 7F06E0D4 AC610000 */  sw    $at, ($v1)
/* 0A2C08 7F06E0D8 8F090004 */  lw    $t1, 4($t8)
/* 0A2C0C 7F06E0DC 00A08025 */  move  $s0, $a1
/* 0A2C10 7F06E0E0 AC690004 */  sw    $t1, 4($v1)
/* 0A2C14 7F06E0E4 8F010008 */  lw    $at, 8($t8)
/* 0A2C18 7F06E0E8 AC610008 */  sw    $at, 8($v1)
/* 0A2C1C 7F06E0EC 8E0A0034 */  lw    $t2, 0x34($s0)
/* 0A2C20 7F06E0F0 8E070020 */  lw    $a3, 0x20($s0)
/* 0A2C24 7F06E0F4 80A50024 */  lb    $a1, 0x24($a1)
/* 0A2C28 7F06E0F8 AFA30014 */  sw    $v1, 0x14($sp)
/* 0A2C2C 7F06E0FC AFA40090 */  sw    $a0, 0x90($sp)
/* 0A2C30 7F06E100 AFA6008C */  sw    $a2, 0x8c($sp)
/* 0A2C34 7F06E104 0FC1B7B0 */  jal   sub_GAME_7F06DEC0
/* 0A2C38 7F06E108 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0A2C3C 7F06E10C 44802000 */  mtc1  $zero, $f4
/* 0A2C40 7F06E110 C606002C */  lwc1  $f6, 0x2c($s0)
/* 0A2C44 7F06E114 3C0B8003 */  lui   $t3, %hi(D_800360A0) 
/* 0A2C48 7F06E118 256B60A0 */  addiu $t3, %lo(D_800360A0) # addiu $t3, $t3, 0x60a0
/* 0A2C4C 7F06E11C 46062032 */  c.eq.s $f4, $f6
/* 0A2C50 7F06E120 00000000 */  nop   
/* 0A2C54 7F06E124 45030015 */  bc1tl .L7F06E17C
/* 0A2C58 7F06E128 44804000 */   mtc1  $zero, $f8
/* 0A2C5C 7F06E12C 8D610000 */  lw    $at, ($t3)
/* 0A2C60 7F06E130 27A20074 */  addiu $v0, $sp, 0x74
/* 0A2C64 7F06E134 AC410000 */  sw    $at, ($v0)
/* 0A2C68 7F06E138 8D6D0004 */  lw    $t5, 4($t3)
/* 0A2C6C 7F06E13C AC4D0004 */  sw    $t5, 4($v0)
/* 0A2C70 7F06E140 8D610008 */  lw    $at, 8($t3)
/* 0A2C74 7F06E144 AC410008 */  sw    $at, 8($v0)
/* 0A2C78 7F06E148 8E0E0038 */  lw    $t6, 0x38($s0)
/* 0A2C7C 7F06E14C 8E070020 */  lw    $a3, 0x20($s0)
/* 0A2C80 7F06E150 82050024 */  lb    $a1, 0x24($s0)
/* 0A2C84 7F06E154 AFA20014 */  sw    $v0, 0x14($sp)
/* 0A2C88 7F06E158 8FA6008C */  lw    $a2, 0x8c($sp)
/* 0A2C8C 7F06E15C 8FA40090 */  lw    $a0, 0x90($sp)
/* 0A2C90 7F06E160 0FC1B7B0 */  jal   sub_GAME_7F06DEC0
/* 0A2C94 7F06E164 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0A2C98 7F06E168 27A40080 */  addiu $a0, $sp, 0x80
/* 0A2C9C 7F06E16C 27A50074 */  addiu $a1, $sp, 0x74
/* 0A2CA0 7F06E170 0FC1B458 */  jal   sub_GAME_7F06D160
/* 0A2CA4 7F06E174 8E06002C */   lw    $a2, 0x2c($s0)
/* 0A2CA8 7F06E178 44804000 */  mtc1  $zero, $f8
.L7F06E17C:
/* 0A2CAC 7F06E17C C60A0084 */  lwc1  $f10, 0x84($s0)
/* 0A2CB0 7F06E180 3C0F8003 */  lui   $t7, %hi(D_800360AC) 
/* 0A2CB4 7F06E184 25EF60AC */  addiu $t7, %lo(D_800360AC) # addiu $t7, $t7, 0x60ac
/* 0A2CB8 7F06E188 460A4032 */  c.eq.s $f8, $f10
/* 0A2CBC 7F06E18C 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A2CC0 7F06E190 02002825 */  move  $a1, $s0
/* 0A2CC4 7F06E194 8FA600A0 */  lw    $a2, 0xa0($sp)
/* 0A2CC8 7F06E198 45010040 */  bc1t  .L7F06E29C
/* 0A2CCC 7F06E19C 00000000 */   nop   
/* 0A2CD0 7F06E1A0 8DE10000 */  lw    $at, ($t7)
/* 0A2CD4 7F06E1A4 27A20068 */  addiu $v0, $sp, 0x68
/* 0A2CD8 7F06E1A8 AC410000 */  sw    $at, ($v0)
/* 0A2CDC 7F06E1AC 8DF90004 */  lw    $t9, 4($t7)
/* 0A2CE0 7F06E1B0 AC590004 */  sw    $t9, 4($v0)
/* 0A2CE4 7F06E1B4 8DE10008 */  lw    $at, 8($t7)
/* 0A2CE8 7F06E1B8 AC410008 */  sw    $at, 8($v0)
/* 0A2CEC 7F06E1BC 8E180064 */  lw    $t8, 0x64($s0)
/* 0A2CF0 7F06E1C0 8E070054 */  lw    $a3, 0x54($s0)
/* 0A2CF4 7F06E1C4 82050025 */  lb    $a1, 0x25($s0)
/* 0A2CF8 7F06E1C8 AFA20014 */  sw    $v0, 0x14($sp)
/* 0A2CFC 7F06E1CC 8FA6008C */  lw    $a2, 0x8c($sp)
/* 0A2D00 7F06E1D0 8FA40090 */  lw    $a0, 0x90($sp)
/* 0A2D04 7F06E1D4 0FC1B7B0 */  jal   sub_GAME_7F06DEC0
/* 0A2D08 7F06E1D8 AFB80010 */   sw    $t8, 0x10($sp)
/* 0A2D0C 7F06E1DC 44808000 */  mtc1  $zero, $f16
/* 0A2D10 7F06E1E0 C612005C */  lwc1  $f18, 0x5c($s0)
/* 0A2D14 7F06E1E4 3C098003 */  lui   $t1, %hi(D_800360B8) 
/* 0A2D18 7F06E1E8 252960B8 */  addiu $t1, %lo(D_800360B8) # addiu $t1, $t1, 0x60b8
/* 0A2D1C 7F06E1EC 46128032 */  c.eq.s $f16, $f18
/* 0A2D20 7F06E1F0 00000000 */  nop   
/* 0A2D24 7F06E1F4 45030015 */  bc1tl .L7F06E24C
/* 0A2D28 7F06E1F8 27A40080 */   addiu $a0, $sp, 0x80
/* 0A2D2C 7F06E1FC 8D210000 */  lw    $at, ($t1)
/* 0A2D30 7F06E200 27A2002C */  addiu $v0, $sp, 0x2c
/* 0A2D34 7F06E204 AC410000 */  sw    $at, ($v0)
/* 0A2D38 7F06E208 8D2C0004 */  lw    $t4, 4($t1)
/* 0A2D3C 7F06E20C AC4C0004 */  sw    $t4, 4($v0)
/* 0A2D40 7F06E210 8D210008 */  lw    $at, 8($t1)
/* 0A2D44 7F06E214 AC410008 */  sw    $at, 8($v0)
/* 0A2D48 7F06E218 8E0B0068 */  lw    $t3, 0x68($s0)
/* 0A2D4C 7F06E21C 8E070054 */  lw    $a3, 0x54($s0)
/* 0A2D50 7F06E220 82050025 */  lb    $a1, 0x25($s0)
/* 0A2D54 7F06E224 AFA20014 */  sw    $v0, 0x14($sp)
/* 0A2D58 7F06E228 8FA6008C */  lw    $a2, 0x8c($sp)
/* 0A2D5C 7F06E22C 8FA40090 */  lw    $a0, 0x90($sp)
/* 0A2D60 7F06E230 0FC1B7B0 */  jal   sub_GAME_7F06DEC0
/* 0A2D64 7F06E234 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0A2D68 7F06E238 27A40068 */  addiu $a0, $sp, 0x68
/* 0A2D6C 7F06E23C 27A5002C */  addiu $a1, $sp, 0x2c
/* 0A2D70 7F06E240 0FC1B458 */  jal   sub_GAME_7F06D160
/* 0A2D74 7F06E244 8E06005C */   lw    $a2, 0x5c($s0)
/* 0A2D78 7F06E248 27A40080 */  addiu $a0, $sp, 0x80
.L7F06E24C:
/* 0A2D7C 7F06E24C 0FC16CFD */  jal   quaternion_set_rotation_around_xyzf
/* 0A2D80 7F06E250 27A50058 */   addiu $a1, $sp, 0x58
/* 0A2D84 7F06E254 27A40068 */  addiu $a0, $sp, 0x68
/* 0A2D88 7F06E258 0FC16CFD */  jal   quaternion_set_rotation_around_xyzf
/* 0A2D8C 7F06E25C 27A50048 */   addiu $a1, $sp, 0x48
/* 0A2D90 7F06E260 27A40058 */  addiu $a0, $sp, 0x58
/* 0A2D94 7F06E264 0FC16F84 */  jal   quaternion_ensure_shortest_path
/* 0A2D98 7F06E268 27A50048 */   addiu $a1, $sp, 0x48
/* 0A2D9C 7F06E26C 27A40058 */  addiu $a0, $sp, 0x58
/* 0A2DA0 7F06E270 27A50048 */  addiu $a1, $sp, 0x48
/* 0A2DA4 7F06E274 8E060084 */  lw    $a2, 0x84($s0)
/* 0A2DA8 7F06E278 0FC16E82 */  jal   quaternion_slerp
/* 0A2DAC 7F06E27C 27A70038 */   addiu $a3, $sp, 0x38
/* 0A2DB0 7F06E280 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A2DB4 7F06E284 02002825 */  move  $a1, $s0
/* 0A2DB8 7F06E288 8FA600A0 */  lw    $a2, 0xa0($sp)
/* 0A2DBC 7F06E28C 0FC1B6D7 */  jal   sub_GAME_7F06DB5C
/* 0A2DC0 7F06E290 27A70038 */   addiu $a3, $sp, 0x38
/* 0A2DC4 7F06E294 10000004 */  b     .L7F06E2A8
/* 0A2DC8 7F06E298 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F06E29C:
/* 0A2DCC 7F06E29C 0FC1B62C */  jal   sub_GAME_7F06D8B0
/* 0A2DD0 7F06E2A0 27A70080 */   addiu $a3, $sp, 0x80
/* 0A2DD4 7F06E2A4 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06E2A8:
/* 0A2DD8 7F06E2A8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0A2DDC 7F06E2AC 27BD0098 */  addiu $sp, $sp, 0x98
/* 0A2DE0 7F06E2B0 03E00008 */  jr    $ra
/* 0A2DE4 7F06E2B4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06E2B8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BF8
.word 0x40490fdb /*3.1415927*/
glabel D_80054BFC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C00
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C04
.word 0x40490fdb /*3.1415927*/
glabel D_80054C08
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C0C
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06E2B8
/* 0A2DE8 7F06E2B8 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 0A2DEC 7F06E2BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A2DF0 7F06E2C0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0A2DF4 7F06E2C4 AFA500A4 */  sw    $a1, 0xa4($sp)
/* 0A2DF8 7F06E2C8 94CE0000 */  lhu   $t6, ($a2)
/* 0A2DFC 7F06E2CC 4487A000 */  mtc1  $a3, $f20
/* 0A2E00 7F06E2D0 AFAE009C */  sw    $t6, 0x9c($sp)
/* 0A2E04 7F06E2D4 8CCF0004 */  lw    $t7, 4($a2)
/* 0A2E08 7F06E2D8 AFAF0098 */  sw    $t7, 0x98($sp)
/* 0A2E0C 7F06E2DC 85F90010 */  lh    $t9, 0x10($t7)
/* 0A2E10 7F06E2E0 85E3000E */  lh    $v1, 0xe($t7)
/* 0A2E14 7F06E2E4 AFB90048 */  sw    $t9, 0x48($sp)
/* 0A2E18 7F06E2E8 85E80012 */  lh    $t0, 0x12($t7)
/* 0A2E1C 7F06E2EC AFA80044 */  sw    $t0, 0x44($sp)
/* 0A2E20 7F06E2F0 8CAA000C */  lw    $t2, 0xc($a1)
/* 0A2E24 7F06E2F4 AFAA0040 */  sw    $t2, 0x40($sp)
/* 0A2E28 7F06E2F8 8CC70008 */  lw    $a3, 8($a2)
/* 0A2E2C 7F06E2FC 00003025 */  move  $a2, $zero
/* 0A2E30 7F06E300 50E00009 */  beql  $a3, $zero, .L7F06E328
/* 0A2E34 7F06E304 8C8B0000 */   lw    $t3, ($a0)
/* 0A2E38 7F06E308 00A02025 */  move  $a0, $a1
/* 0A2E3C 7F06E30C 00E02825 */  move  $a1, $a3
/* 0A2E40 7F06E310 0FC1B198 */  jal   modelFindNodeMtx
/* 0A2E44 7F06E314 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0A2E48 7F06E318 8FA3004C */  lw    $v1, 0x4c($sp)
/* 0A2E4C 7F06E31C 10000003 */  b     .L7F06E32C
/* 0A2E50 7F06E320 AFA20094 */   sw    $v0, 0x94($sp)
/* 0A2E54 7F06E324 8C8B0000 */  lw    $t3, ($a0)
.L7F06E328:
/* 0A2E58 7F06E328 AFAB0094 */  sw    $t3, 0x94($sp)
.L7F06E32C:
/* 0A2E5C 7F06E32C 8FAC0094 */  lw    $t4, 0x94($sp)
/* 0A2E60 7F06E330 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A2E64 7F06E334 00037980 */  sll   $t7, $v1, 6
/* 0A2E68 7F06E338 1180000F */  beqz  $t4, .L7F06E378
/* 0A2E6C 7F06E33C 8FB90040 */   lw    $t9, 0x40($sp)
/* 0A2E70 7F06E340 4405A000 */  mfc1  $a1, $f20
/* 0A2E74 7F06E344 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A2E78 7F06E348 27A60050 */  addiu $a2, $sp, 0x50
/* 0A2E7C 7F06E34C 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A2E80 7F06E350 AFA3004C */   sw    $v1, 0x4c($sp)
/* 0A2E84 7F06E354 8FA3004C */  lw    $v1, 0x4c($sp)
/* 0A2E88 7F06E358 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0A2E8C 7F06E35C 8FA40094 */  lw    $a0, 0x94($sp)
/* 0A2E90 7F06E360 00036980 */  sll   $t5, $v1, 6
/* 0A2E94 7F06E364 27A50050 */  addiu $a1, $sp, 0x50
/* 0A2E98 7F06E368 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2E9C 7F06E36C 01AE3021 */   addu  $a2, $t5, $t6
/* 0A2EA0 7F06E370 10000005 */  b     .L7F06E388
/* 0A2EA4 7F06E374 8FB8009C */   lw    $t8, 0x9c($sp)
.L7F06E378:
/* 0A2EA8 7F06E378 4405A000 */  mfc1  $a1, $f20
/* 0A2EAC 7F06E37C 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A2EB0 7F06E380 01F93021 */   addu  $a2, $t7, $t9
/* 0A2EB4 7F06E384 8FB8009C */  lw    $t8, 0x9c($sp)
.L7F06E388:
/* 0A2EB8 7F06E388 3C018005 */  lui   $at, %hi(D_80054BF8)
/* 0A2EBC 7F06E38C 8FAA0094 */  lw    $t2, 0x94($sp)
/* 0A2EC0 7F06E390 33020100 */  andi  $v0, $t8, 0x100
/* 0A2EC4 7F06E394 14400003 */  bnez  $v0, .L7F06E3A4
/* 0A2EC8 7F06E398 33030200 */   andi  $v1, $t8, 0x200
/* 0A2ECC 7F06E39C 10600017 */  beqz  $v1, .L7F06E3FC
/* 0A2ED0 7F06E3A0 00000000 */   nop   
.L7F06E3A4:
/* 0A2ED4 7F06E3A4 C4244BF8 */  lwc1  $f4, %lo(D_80054BF8)($at)
/* 0A2ED8 7F06E3A8 8FA3009C */  lw    $v1, 0x9c($sp)
/* 0A2EDC 7F06E3AC 3C018005 */  lui   $at, %hi(D_80054BFC)
/* 0A2EE0 7F06E3B0 4604A03C */  c.lt.s $f20, $f4
/* 0A2EE4 7F06E3B4 30680200 */  andi  $t0, $v1, 0x200
/* 0A2EE8 7F06E3B8 01001825 */  move  $v1, $t0
/* 0A2EEC 7F06E3BC 45000007 */  bc1f  .L7F06E3DC
/* 0A2EF0 7F06E3C0 00000000 */   nop   
/* 0A2EF4 7F06E3C4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A2EF8 7F06E3C8 44813000 */  mtc1  $at, $f6
/* 0A2EFC 7F06E3CC 00000000 */  nop   
/* 0A2F00 7F06E3D0 4606A502 */  mul.s $f20, $f20, $f6
/* 0A2F04 7F06E3D4 10000009 */  b     .L7F06E3FC
/* 0A2F08 7F06E3D8 00000000 */   nop   
.L7F06E3DC:
/* 0A2F0C 7F06E3DC C4284BFC */  lwc1  $f8, %lo(D_80054BFC)($at)
/* 0A2F10 7F06E3E0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A2F14 7F06E3E4 44818000 */  mtc1  $at, $f16
/* 0A2F18 7F06E3E8 46144281 */  sub.s $f10, $f8, $f20
/* 0A2F1C 7F06E3EC 3C018005 */  lui   $at, %hi(D_80054C00)
/* 0A2F20 7F06E3F0 C4244C00 */  lwc1  $f4, %lo(D_80054C00)($at)
/* 0A2F24 7F06E3F4 46105482 */  mul.s $f18, $f10, $f16
/* 0A2F28 7F06E3F8 46122501 */  sub.s $f20, $f4, $f18
.L7F06E3FC:
/* 0A2F2C 7F06E3FC 10400019 */  beqz  $v0, .L7F06E464
/* 0A2F30 7F06E400 00000000 */   nop   
/* 0A2F34 7F06E404 1140000F */  beqz  $t2, .L7F06E444
/* 0A2F38 7F06E408 8FA40098 */   lw    $a0, 0x98($sp)
/* 0A2F3C 7F06E40C 4405A000 */  mfc1  $a1, $f20
/* 0A2F40 7F06E410 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A2F44 7F06E414 27A60050 */  addiu $a2, $sp, 0x50
/* 0A2F48 7F06E418 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A2F4C 7F06E41C AFA30024 */   sw    $v1, 0x24($sp)
/* 0A2F50 7F06E420 8FA90048 */  lw    $t1, 0x48($sp)
/* 0A2F54 7F06E424 8FAC0040 */  lw    $t4, 0x40($sp)
/* 0A2F58 7F06E428 8FA40094 */  lw    $a0, 0x94($sp)
/* 0A2F5C 7F06E42C 00095980 */  sll   $t3, $t1, 6
/* 0A2F60 7F06E430 27A50050 */  addiu $a1, $sp, 0x50
/* 0A2F64 7F06E434 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2F68 7F06E438 016C3021 */   addu  $a2, $t3, $t4
/* 0A2F6C 7F06E43C 10000009 */  b     .L7F06E464
/* 0A2F70 7F06E440 8FA30024 */   lw    $v1, 0x24($sp)
.L7F06E444:
/* 0A2F74 7F06E444 8FAD0048 */  lw    $t5, 0x48($sp)
/* 0A2F78 7F06E448 8FAF0040 */  lw    $t7, 0x40($sp)
/* 0A2F7C 7F06E44C 4405A000 */  mfc1  $a1, $f20
/* 0A2F80 7F06E450 000D7180 */  sll   $t6, $t5, 6
/* 0A2F84 7F06E454 AFA30024 */  sw    $v1, 0x24($sp)
/* 0A2F88 7F06E458 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A2F8C 7F06E45C 01CF3021 */   addu  $a2, $t6, $t7
/* 0A2F90 7F06E460 8FA30024 */  lw    $v1, 0x24($sp)
.L7F06E464:
/* 0A2F94 7F06E464 10600031 */  beqz  $v1, .L7F06E52C
/* 0A2F98 7F06E468 8FB90094 */   lw    $t9, 0x94($sp)
/* 0A2F9C 7F06E46C 13200004 */  beqz  $t9, .L7F06E480
/* 0A2FA0 7F06E470 4600A306 */   mov.s $f12, $f20
/* 0A2FA4 7F06E474 27B80050 */  addiu $t8, $sp, 0x50
/* 0A2FA8 7F06E478 10000006 */  b     .L7F06E494
/* 0A2FAC 7F06E47C AFB80030 */   sw    $t8, 0x30($sp)
.L7F06E480:
/* 0A2FB0 7F06E480 8FA80044 */  lw    $t0, 0x44($sp)
/* 0A2FB4 7F06E484 8FA90040 */  lw    $t1, 0x40($sp)
/* 0A2FB8 7F06E488 00085180 */  sll   $t2, $t0, 6
/* 0A2FBC 7F06E48C 01495821 */  addu  $t3, $t2, $t1
/* 0A2FC0 7F06E490 AFAB0030 */  sw    $t3, 0x30($sp)
.L7F06E494:
/* 0A2FC4 7F06E494 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0A2FC8 7F06E498 8FA50030 */   lw    $a1, 0x30($sp)
/* 0A2FCC 7F06E49C 3C018005 */  lui   $at, %hi(D_80054C04)
/* 0A2FD0 7F06E4A0 C4264C04 */  lwc1  $f6, %lo(D_80054C04)($at)
/* 0A2FD4 7F06E4A4 3C018005 */  lui   $at, %hi(D_80054C08)
/* 0A2FD8 7F06E4A8 4614303E */  c.le.s $f6, $f20
/* 0A2FDC 7F06E4AC 00000000 */  nop   
/* 0A2FE0 7F06E4B0 45000003 */  bc1f  .L7F06E4C0
/* 0A2FE4 7F06E4B4 00000000 */   nop   
/* 0A2FE8 7F06E4B8 C4284C08 */  lwc1  $f8, %lo(D_80054C08)($at)
/* 0A2FEC 7F06E4BC 46144501 */  sub.s $f20, $f8, $f20
.L7F06E4C0:
/* 0A2FF0 7F06E4C0 3C018005 */  lui    $at, %hi(D_80054C0C)
/* 0A2FF4 7F06E4C4 C42A4C0C */  lwc1  $f10, %lo(D_80054C0C)($at)
/* 0A2FF8 7F06E4C8 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0A2FFC 7F06E4CC 460AA03C */  c.lt.s $f20, $f10
/* 0A3000 7F06E4D0 00000000 */  nop   
/* 0A3004 7F06E4D4 45020006 */  bc1fl .L7F06E4F0
/* 0A3008 7F06E4D8 44816000 */   mtc1  $at, $f12
/* 0A300C 7F06E4DC 0FC16A78 */  jal   sub_GAME_7F05A9E0
/* 0A3010 7F06E4E0 4600A306 */   mov.s $f12, $f20
/* 0A3014 7F06E4E4 10000003 */  b     .L7F06E4F4
/* 0A3018 7F06E4E8 46000306 */   mov.s $f12, $f0
/* 0A301C 7F06E4EC 44816000 */  mtc1  $at, $f12
.L7F06E4F0:
/* 0A3020 7F06E4F0 00000000 */  nop   
.L7F06E4F4:
/* 0A3024 7F06E4F4 0FC16293 */  jal   matrix_column_3_scalar_multiply_2
/* 0A3028 7F06E4F8 8FA50030 */   lw    $a1, 0x30($sp)
/* 0A302C 7F06E4FC 8FA40098 */  lw    $a0, 0x98($sp)
/* 0A3030 7F06E500 0FC16266 */  jal   matrix_4x4_set_position
/* 0A3034 7F06E504 8FA50030 */   lw    $a1, 0x30($sp)
/* 0A3038 7F06E508 8FAC0094 */  lw    $t4, 0x94($sp)
/* 0A303C 7F06E50C 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0A3040 7F06E510 8FAF0040 */  lw    $t7, 0x40($sp)
/* 0A3044 7F06E514 11800005 */  beqz  $t4, .L7F06E52C
/* 0A3048 7F06E518 01802025 */   move  $a0, $t4
/* 0A304C 7F06E51C 000D7180 */  sll   $t6, $t5, 6
/* 0A3050 7F06E520 01CF3021 */  addu  $a2, $t6, $t7
/* 0A3054 7F06E524 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A3058 7F06E528 8FA50030 */   lw    $a1, 0x30($sp)
.L7F06E52C:
/* 0A305C 7F06E52C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A3060 7F06E530 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0A3064 7F06E534 27BD00A0 */  addiu $sp, $sp, 0xa0
/* 0A3068 7F06E538 03E00008 */  jr    $ra
/* 0A306C 7F06E53C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06E540(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054C10
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C14
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06E540
/* 0A3070 7F06E540 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0A3074 7F06E544 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A3078 7F06E548 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0A307C 7F06E54C AFA60030 */  sw    $a2, 0x30($sp)
/* 0A3080 7F06E550 90EE0006 */  lbu   $t6, 6($a3)
/* 0A3084 7F06E554 44801000 */  mtc1  $zero, $f2
/* 0A3088 7F06E558 10A0000C */  beqz  $a1, .L7F06E58C
/* 0A308C 7F06E55C A3AE001F */   sb    $t6, 0x1f($sp)
/* 0A3090 7F06E560 8CD90004 */  lw    $t9, 4($a2)
/* 0A3094 7F06E564 00044080 */  sll   $t0, $a0, 2
/* 0A3098 7F06E568 01044023 */  subu  $t0, $t0, $a0
/* 0A309C 7F06E56C 00084040 */  sll   $t0, $t0, 1
/* 0A30A0 7F06E570 03284821 */  addu  $t1, $t9, $t0
/* 0A30A4 7F06E574 952A0004 */  lhu   $t2, 4($t1)
/* 0A30A8 7F06E578 31CB00FF */  andi  $t3, $t6, 0xff
/* 0A30AC 7F06E57C 014B0019 */  multu $t2, $t3
/* 0A30B0 7F06E580 00003012 */  mflo  $a2
/* 0A30B4 7F06E584 1000000E */  b     .L7F06E5C0
/* 0A30B8 7F06E588 8FA40038 */   lw    $a0, 0x38($sp)
.L7F06E58C:
/* 0A30BC 7F06E58C 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0A30C0 7F06E590 00047080 */  sll   $t6, $a0, 2
/* 0A30C4 7F06E594 01C47023 */  subu  $t6, $t6, $a0
/* 0A30C8 7F06E598 8D8D0004 */  lw    $t5, 4($t4)
/* 0A30CC 7F06E59C 000E7040 */  sll   $t6, $t6, 1
/* 0A30D0 7F06E5A0 93B9001F */  lbu   $t9, 0x1f($sp)
/* 0A30D4 7F06E5A4 01AE7821 */  addu  $t7, $t5, $t6
/* 0A30D8 7F06E5A8 95F80002 */  lhu   $t8, 2($t7)
/* 0A30DC 7F06E5AC 03190019 */  multu $t8, $t9
/* 0A30E0 7F06E5B0 00003012 */  mflo  $a2
/* 0A30E4 7F06E5B4 00000000 */  nop   
/* 0A30E8 7F06E5B8 00000000 */  nop   
/* 0A30EC 7F06E5BC 8FA40038 */  lw    $a0, 0x38($sp)
.L7F06E5C0:
/* 0A30F0 7F06E5C0 93A5001F */  lbu   $a1, 0x1f($sp)
/* 0A30F4 7F06E5C4 0FC1B781 */  jal   sub_GAME_7F06DE04
/* 0A30F8 7F06E5C8 E7A20018 */   swc1  $f2, 0x18($sp)
/* 0A30FC 7F06E5CC 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0A3100 7F06E5D0 C7A20018 */  lwc1  $f2, 0x18($sp)
/* 0A3104 7F06E5D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A3108 7F06E5D8 1100000D */  beqz  $t0, .L7F06E610
/* 0A310C 7F06E5DC 27BD0028 */   addiu $sp, $sp, 0x28
/* 0A3110 7F06E5E0 10400018 */  beqz  $v0, .L7F06E644
/* 0A3114 7F06E5E4 3C090001 */   lui   $t1, 1
/* 0A3118 7F06E5E8 01225023 */  subu  $t2, $t1, $v0
/* 0A311C 7F06E5EC 448A2000 */  mtc1  $t2, $f4
/* 0A3120 7F06E5F0 3C018005 */  lui   $at, %hi(D_80054C10)
/* 0A3124 7F06E5F4 C4284C10 */  lwc1  $f8, %lo(D_80054C10)($at)
/* 0A3128 7F06E5F8 468021A0 */  cvt.s.w $f6, $f4
/* 0A312C 7F06E5FC 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0A3130 7F06E600 44818000 */  mtc1  $at, $f16
/* 0A3134 7F06E604 46083282 */  mul.s $f10, $f6, $f8
/* 0A3138 7F06E608 1000000E */  b     .L7F06E644
/* 0A313C 7F06E60C 46105083 */   div.s $f2, $f10, $f16
.L7F06E610:
/* 0A3140 7F06E610 44829000 */  mtc1  $v0, $f18
/* 0A3144 7F06E614 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A3148 7F06E618 04410004 */  bgez  $v0, .L7F06E62C
/* 0A314C 7F06E61C 46809120 */   cvt.s.w $f4, $f18
/* 0A3150 7F06E620 44813000 */  mtc1  $at, $f6
/* 0A3154 7F06E624 00000000 */  nop   
/* 0A3158 7F06E628 46062100 */  add.s $f4, $f4, $f6
.L7F06E62C:
/* 0A315C 7F06E62C 3C018005 */  lui   $at, %hi(D_80054C14)
/* 0A3160 7F06E630 C4284C14 */  lwc1  $f8, %lo(D_80054C14)($at)
/* 0A3164 7F06E634 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0A3168 7F06E638 44818000 */  mtc1  $at, $f16
/* 0A316C 7F06E63C 46082282 */  mul.s $f10, $f4, $f8
/* 0A3170 7F06E640 46105083 */  div.s $f2, $f10, $f16
.L7F06E644:
/* 0A3174 7F06E644 03E00008 */  jr    $ra
/* 0A3178 7F06E648 46001006 */   mov.s $f0, $f2
)
#endif





#ifdef NONMATCHING
void process_03_unknown(ModelRenderData *arg0, Model *model, ModelNode *node) {

}
#else
void process_03_unknown(ModelRenderData *arg0, Model *model, ModelNode *node);
GLOBAL_ASM(
.text
glabel process_03_unknown
/* 0A317C 7F06E64C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0A3180 7F06E650 AFB00028 */  sw    $s0, 0x28($sp)
/* 0A3184 7F06E654 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0A3188 7F06E658 AFB20030 */  sw    $s2, 0x30($sp)
/* 0A318C 7F06E65C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0A3190 7F06E660 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0A3194 7F06E664 AFA40050 */  sw    $a0, 0x50($sp)
/* 0A3198 7F06E668 AFA60058 */  sw    $a2, 0x58($sp)
/* 0A319C 7F06E66C 8CC20004 */  lw    $v0, 4($a2)
/* 0A31A0 7F06E670 8CAF0008 */  lw    $t7, 8($a1)
/* 0A31A4 7F06E674 00A08025 */  move  $s0, $a1
/* 0A31A8 7F06E678 8E180034 */  lw    $t8, 0x34($s0)
/* 0A31AC 7F06E67C 9451000C */  lhu   $s1, 0xc($v0)
/* 0A31B0 7F06E680 8DF20004 */  lw    $s2, 4($t7)
/* 0A31B4 7F06E684 8E070020 */  lw    $a3, 0x20($s0)
/* 0A31B8 7F06E688 80A50024 */  lb    $a1, 0x24($a1)
/* 0A31BC 7F06E68C AFB80010 */  sw    $t8, 0x10($sp)
/* 0A31C0 7F06E690 02202025 */  move  $a0, $s1
/* 0A31C4 7F06E694 0FC1B950 */  jal   sub_GAME_7F06E540
/* 0A31C8 7F06E698 02403025 */   move  $a2, $s2
/* 0A31CC 7F06E69C 44802000 */  mtc1  $zero, $f4
/* 0A31D0 7F06E6A0 C606002C */  lwc1  $f6, 0x2c($s0)
/* 0A31D4 7F06E6A4 46000506 */  mov.s $f20, $f0
/* 0A31D8 7F06E6A8 02202025 */  move  $a0, $s1
/* 0A31DC 7F06E6AC 46062032 */  c.eq.s $f4, $f6
/* 0A31E0 7F06E6B0 02403025 */  move  $a2, $s2
/* 0A31E4 7F06E6B4 4503000C */  bc1tl .L7F06E6E8
/* 0A31E8 7F06E6B8 44804000 */   mtc1  $zero, $f8
/* 0A31EC 7F06E6BC 8E190038 */  lw    $t9, 0x38($s0)
/* 0A31F0 7F06E6C0 82050024 */  lb    $a1, 0x24($s0)
/* 0A31F4 7F06E6C4 8E070020 */  lw    $a3, 0x20($s0)
/* 0A31F8 7F06E6C8 0FC1B950 */  jal   sub_GAME_7F06E540
/* 0A31FC 7F06E6CC AFB90010 */   sw    $t9, 0x10($sp)
/* 0A3200 7F06E6D0 4600A306 */  mov.s $f12, $f20
/* 0A3204 7F06E6D4 46000386 */  mov.s $f14, $f0
/* 0A3208 7F06E6D8 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A320C 7F06E6DC 8E06002C */   lw    $a2, 0x2c($s0)
/* 0A3210 7F06E6E0 46000506 */  mov.s $f20, $f0
/* 0A3214 7F06E6E4 44804000 */  mtc1  $zero, $f8
.L7F06E6E8:
/* 0A3218 7F06E6E8 C60A0084 */  lwc1  $f10, 0x84($s0)
/* 0A321C 7F06E6EC 02202025 */  move  $a0, $s1
/* 0A3220 7F06E6F0 02403025 */  move  $a2, $s2
/* 0A3224 7F06E6F4 460A4032 */  c.eq.s $f8, $f10
/* 0A3228 7F06E6F8 00000000 */  nop   
/* 0A322C 7F06E6FC 4503001F */  bc1tl .L7F06E77C
/* 0A3230 7F06E700 4407A000 */   mfc1  $a3, $f20
/* 0A3234 7F06E704 8E080064 */  lw    $t0, 0x64($s0)
/* 0A3238 7F06E708 82050025 */  lb    $a1, 0x25($s0)
/* 0A323C 7F06E70C 8E070054 */  lw    $a3, 0x54($s0)
/* 0A3240 7F06E710 0FC1B950 */  jal   sub_GAME_7F06E540
/* 0A3244 7F06E714 AFA80010 */   sw    $t0, 0x10($sp)
/* 0A3248 7F06E718 E7A00038 */  swc1  $f0, 0x38($sp)
/* 0A324C 7F06E71C C612005C */  lwc1  $f18, 0x5c($s0)
/* 0A3250 7F06E720 44808000 */  mtc1  $zero, $f16
/* 0A3254 7F06E724 02202025 */  move  $a0, $s1
/* 0A3258 7F06E728 02403025 */  move  $a2, $s2
/* 0A325C 7F06E72C 46128032 */  c.eq.s $f16, $f18
/* 0A3260 7F06E730 00000000 */  nop   
/* 0A3264 7F06E734 4503000C */  bc1tl .L7F06E768
/* 0A3268 7F06E738 4600A306 */   mov.s $f12, $f20
/* 0A326C 7F06E73C 8E090068 */  lw    $t1, 0x68($s0)
/* 0A3270 7F06E740 82050025 */  lb    $a1, 0x25($s0)
/* 0A3274 7F06E744 8E070054 */  lw    $a3, 0x54($s0)
/* 0A3278 7F06E748 0FC1B950 */  jal   sub_GAME_7F06E540
/* 0A327C 7F06E74C AFA90010 */   sw    $t1, 0x10($sp)
/* 0A3280 7F06E750 C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 0A3284 7F06E754 46000386 */  mov.s $f14, $f0
/* 0A3288 7F06E758 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A328C 7F06E75C 8E06005C */   lw    $a2, 0x5c($s0)
/* 0A3290 7F06E760 E7A00038 */  swc1  $f0, 0x38($sp)
/* 0A3294 7F06E764 4600A306 */  mov.s $f12, $f20
.L7F06E768:
/* 0A3298 7F06E768 C7AE0038 */  lwc1  $f14, 0x38($sp)
/* 0A329C 7F06E76C 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A32A0 7F06E770 8E060084 */   lw    $a2, 0x84($s0)
/* 0A32A4 7F06E774 46000506 */  mov.s $f20, $f0
/* 0A32A8 7F06E778 4407A000 */  mfc1  $a3, $f20
.L7F06E77C:
/* 0A32AC 7F06E77C 8FA40050 */  lw    $a0, 0x50($sp)
/* 0A32B0 7F06E780 02002825 */  move  $a1, $s0
/* 0A32B4 7F06E784 0FC1B8AE */  jal   sub_GAME_7F06E2B8
/* 0A32B8 7F06E788 8FA60058 */   lw    $a2, 0x58($sp)
/* 0A32BC 7F06E78C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0A32C0 7F06E790 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0A32C4 7F06E794 8FB00028 */  lw    $s0, 0x28($sp)
/* 0A32C8 7F06E798 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0A32CC 7F06E79C 8FB20030 */  lw    $s2, 0x30($sp)
/* 0A32D0 7F06E7A0 03E00008 */  jr    $ra
/* 0A32D4 7F06E7A4 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif


void process_15_subposition(ModelRenderData* arg0, Model *model, ModelNode *node)
{
    union ModelRoData *rodata = node->Data;
    Mtxf *sp68;
    Mtxf sp28;
    s32 mtxindex = rodata->GroupSimple.Group1;
    RenderPosView *matrices = model->render_pos;

    if (node->Parent)
    {
        sp68 = modelFindNodeMtx(model, node->Parent, 0);
    }
    else
    {
        sp68 = arg0->unk00;
    }

    if (sp68)
    {
        matrix_4x4_set_identity_and_position(&rodata->GroupSimple.Origin, &sp28);
        matrix_4x4_multiply_homogeneous(sp68, &sp28, &matrices[mtxindex]);
    }
    else
    {
        matrix_4x4_set_identity_and_position(&rodata->GroupSimple.Origin, &matrices[mtxindex]);
    }
}

/*
* Address: 0x7F06E858
*/
void modelUpdateDistanceRelations(Model* model, ModelNode* node)
{
    union ModelRoData *rodata = node->Data;
    union ModelRwData *rwdata = modelGetNodeRwData(model, node);
    Mtxf *mtx = modelFindNodeMtx(model, node, 0);
    f32 distance;

    if (g_ModelDistanceDisabled)
    {
        distance = 0;
    }
    else
    {
        distance = -mtx->m[3][2] * getPlayer_c_lodscalez();

        if (g_ModelDistanceScale != 1)
        {
            distance *= g_ModelDistanceScale;
        }
    }

    if (distance > rodata->LOD.MinDistance * model->scale || rodata->LOD.MinDistance == 0)
    {
        if (distance <= rodata->LOD.MaxDistance * model->scale)
        {
            rwdata->LOD.visible = TRUE;
            node->Child = rodata->LOD.Affects;
            return;
        }
    }

    rwdata->LOD.visible = FALSE;
    node->Child = NULL;
}

/*
* Address: 0x7F06E970
*/
void modelApplyDistanceRelations(Model* model, ModelNode* node)
{
    ModelRoData_LODRecord *rodata = &node->Data->LOD;
    ModelRwData_LODRecord *rwdata = modelGetNodeRwData(model, node);

    if (rwdata->visible)
    {
        node->Child = rodata->Affects;
    }
    else
    {
        node->Child = NULL;
    }
}


void modelApplyToggleRelations(Model* model, ModelNode* node)
{
    ModelRoData_SwitchRecord *rodata = &node->Data->Switch;
    ModelRwData_SwitchRecord *rwdata = modelGetNodeRwData(model, node);

    if (rwdata->visible)
    {
        node->Child = rodata->Controls;
    }
    else
    {
        node->Child = NULL;
    }
}


void modelApplyHeadRelations(Model* model, ModelNode* bodynode)
{
    struct ModelRwData_HeadPlaceholderRecord *rwdata = modelGetNodeRwData(model, bodynode);

    if (rwdata->ModelFileHeader)
    {
        ModelNode *headnode = rwdata->ModelFileHeader->RootNode;

        bodynode->Child = headnode;

        while (headnode)
        {
            headnode->Parent = bodynode;
            headnode = headnode->Next;
        }
    }
}


void modelApplyReorderRelationsByArg(ModelNode *basenode, bool visible)
{
    union ModelRoData *rodata = basenode->Data;
    ModelNode *node1;
    ModelNode *node2;
    ModelNode *loopnode;

    if (visible)
    {
        node1 = rodata->BSP.leftChild;
        node2 = rodata->BSP.rightChild;
    }
    else
    {
        node1 = rodata->BSP.rightChild;
        node2 = rodata->BSP.leftChild;
    }

    if (node1)
    {
        // I think what's happening here is there's two groups of siblings,
        // where node1 and node2 are the head nodes. Either group can be first,
        // and this is ensuring the node1 group is first.
        // Note that node2 might be NULL.

        basenode->Child = node1;
        node1->Prev = NULL;

        // Skip through node1's siblings until node2 is found or the end is
        // reached
        loopnode = node1;

        while (loopnode->Next && loopnode->Next != node2)
        {
            loopnode = loopnode->Next;
        }

        loopnode->Next = node2;

        if (node2)
        {
            // Append node2 and its siblings to node1's siblings
            node2->Prev = loopnode;
            loopnode = node2;

            while (loopnode->Next && loopnode->Next != node1)
            {
                loopnode = loopnode->Next;
            }

            loopnode->Next = NULL;
        }
    }
    else
    {
        basenode->Child = node2;

        if (node2)
        {
            node2->Prev = NULL;
        }
    }
}


void modelApplyReorderRelations(Model* model, ModelNode* node)
{
    union ModelRwData *rwdata = modelGetNodeRwData(model, node);
    modelApplyReorderRelationsByArg(node, rwdata->BSP.visible);
}


void modelUpdateReorderRelations(Model *model, ModelNode *node)
{
    union ModelRoData *rodata = node->Data;
    union ModelRwData *rwdata = modelGetNodeRwData(model, node);
    Mtxf *mtx = modelFindNodeMtx(model, node, 0);
    coord3d sp38;
    coord3d sp2c;
    f32 tmp;

    if (rodata->BSP.reserved == 0)
    {
        sp38.x = rodata->BSP.Vector.f[0];
        sp38.y = rodata->BSP.Vector.f[1];
        sp38.z = rodata->BSP.Vector.f[2];
        mtx4RotateVecInPlace(mtx, sp38.f);
    }
    else if (rodata->BSP.reserved == 2)
    {
        sp38.x = mtx->m[1][0] * rodata->BSP.Vector.f[1];
        sp38.y = mtx->m[1][1] * rodata->BSP.Vector.f[1];
        sp38.z = mtx->m[1][2] * rodata->BSP.Vector.f[1];
    }
    else if (rodata->BSP.reserved == 3)
    {
        sp38.x = mtx->m[2][0] * rodata->BSP.Vector.f[2];
        sp38.y = mtx->m[2][1] * rodata->BSP.Vector.f[2];
        sp38.z = mtx->m[2][2] * rodata->BSP.Vector.f[2];
    }
    else if (rodata->BSP.reserved == 1)
    {
        sp38.x = mtx->m[0][0] * rodata->BSP.Vector.f[0];
        sp38.y = mtx->m[0][1] * rodata->BSP.Vector.f[0];
        sp38.z = mtx->m[0][2] * rodata->BSP.Vector.f[0];
    }

    sp2c.x = rodata->BSP.Point.f[0];
    sp2c.y = rodata->BSP.Point.f[1];
    sp2c.z = rodata->BSP.Point.f[2];

    mtx4TransformVecInPlace(mtx, &sp2c);

    tmp = sp38.f[0] * sp2c.f[0] + sp38.f[1] * sp2c.f[1] + sp38.f[2] * sp2c.f[2];

    if (tmp < 0)
    {
        rwdata->BSP.visible = TRUE;
    }
    else
    {
        rwdata->BSP.visible = FALSE;
    }

    modelApplyReorderRelations(model, node);
}


void process_07_unknown(Model *model, ModelNode *node)
{
    union ModelRoData *rodata = node->Data;
    union ModelRwData *rwdata = modelGetNodeRwData(model, node);
    Mtxf *mtx = modelFindNodeMtx(model, node, 0);
    f32 ratio;
    f32 coord_multiplied;
    coord3d coord;
    s32 index1;
    f32 theta;
    s32 index2;
    s32 index3;

    sub_GAME_7F06C550(model, &coord);

    theta = acosf(((coord.x * mtx->m[1][0]) + (coord.y * mtx->m[1][1])) + (coord.z * mtx->m[1][2]));
    ratio = acosf((((coord.x * mtx->m[2][0]) + (coord.y * mtx->m[2][1])) + (coord.z * mtx->m[2][2])) / sinf(theta));
    coord_multiplied = ((coord.x * mtx->m[0][0]) + (coord.y * mtx->m[0][1])) + (coord.z * mtx->m[0][2]);

    if ((coord_multiplied < 0.0f) && (ratio > 0.0f))
    {
        ratio = M_TAU_F - ratio;
    }

    index1 = (theta * 64.0f) / M_TAU_F;

    index2 = (s32) ((ratio * M_U16_MAX_VALUE_F) / M_TAU_F);
    index2 += D_800360C4[index1].unk04;
    index2 = index2 >> D_800360C4[index1].unk0C;

    index3 = index2 + D_800360C4[index1].unk00;

    rwdata->Op07.index = rodata->Op07.Data[index3];
}


void modelUpdateRelationsQuick(Model *model, ModelNode *parent)
{
    ModelNode *node = parent->Child;
    ModelNode **unused_parent;

    while (node)
    {
        s32 type = node->Opcode & 0xff;
        bool dochildren = TRUE;

        switch (type)
        {
            case MODELNODE_OPCODE_HEADER:
            case MODELNODE_OPCODE_GROUP:
            case MODELNODE_OPCODE_OP03:
            case MODELNODE_OPCODE_OP11:
            case MODELNODE_OPCODE_GUNFIRE:
            case MODELNODE_OPCODE_SHADOW:
            case MODELNODE_OPCODE_OP14:
            case MODELNODE_OPCODE_INTERLINK:
            case MODELNODE_OPCODE_OP16:
            case MODELNODE_OPCODE_GROUPSIMPLE:
                dochildren = FALSE;
                break;
            case MODELNODE_OPCODE_LOD:
                modelUpdateDistanceRelations(model, node);
                break;
            case MODELNODE_OPCODE_BSP:
                modelUpdateReorderRelations(model, node);
                break;
            case MODELNODE_OPCODE_OP07:
                process_07_unknown(model, node);
                break;
            case MODELNODE_OPCODE_HEAD:
                modelApplyHeadRelations(model, node);
                break;
            case MODELNODE_OPCODE_DLCOLLISION:
                break;
        }

        if (dochildren && node->Child)
        {
            node = node->Child;
        }
        else
        {
            unused_parent = &parent;
            while (node)
            {
                if (node == parent->Parent)
                {
                    node = NULL;
                    break;
                }

                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void sub_GAME_7F06EFC4(Model *model)
{
    ModelNode *node = model->obj->RootNode;

    while (node)
    {
        u32 type = node->Opcode & 0xff;

        switch (type)
        {
            case MODELNODE_OPCODE_LOD:
                modelUpdateDistanceRelations(model, node);
                break;

            case MODELNODE_OPCODE_BSP:
                modelUpdateReorderRelations(model, node);
                break;

            case MODELNODE_OPCODE_OP07:
                process_07_unknown(model, node);
                break;

            case MODELNODE_OPCODE_SWITCH:
                modelApplyToggleRelations(model, node);
                break;

            case MODELNODE_OPCODE_HEAD:
                modelApplyHeadRelations(model, node);
                break;

            case MODELNODE_OPCODE_HEADER:
            case MODELNODE_OPCODE_DLCOLLISION:
            default:
                break;
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void modelUpdateMatrices(ModelRenderData *arg0, Model *model)
{
    ModelNode *node = model->obj->RootNode;

    while (node)
    {
        u32 type = node->Opcode & 0xff;

        switch (type)
        {
            case MODELNODE_OPCODE_HEADER:
                process_01_group_heading(arg0, model, node);
                break;

            case MODELNODE_OPCODE_GROUP:
                process_02_position(arg0, model, node);
                break;

            case MODELNODE_OPCODE_OP03:
                process_03_unknown(arg0, model, node);
                break;

            case MODELNODE_OPCODE_GROUPSIMPLE:
                process_15_subposition(arg0, model, node);
                break;

            case MODELNODE_OPCODE_LOD:
                modelUpdateDistanceRelations(model, node);
                break;

            case MODELNODE_OPCODE_BSP:
                modelUpdateReorderRelations(model, node);
                break;

            case MODELNODE_OPCODE_OP07:
                process_07_unknown(model, node);
                break;

            case MODELNODE_OPCODE_SWITCH:
                modelApplyToggleRelations(model, node);
                break;

            case MODELNODE_OPCODE_HEAD:
                modelApplyHeadRelations(model, node);
                break;

            case MODELNODE_OPCODE_DLCOLLISION:
            default:
                break;
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void instcalcmatrices(struct unk_joint_list* arg0, Model* arg1)
{
#if defined(LEFTOVERDEBUG)
    if (arg1 == NULL)
    {
        osSyncPrintf("instcalcmatrices: no objinst!\n");
        return_null();
    }

    if (arg0->unk_matrix == NULL)
    {
        osSyncPrintf("instcalcmatrices: no basemtx!\n");
        return_null();
    }

    if (arg0->mtxlist == NULL)
    {
        osSyncPrintf("instcalcmatrices: no mtxlist!\n");
        return_null();
    }
#endif
    arg1->render_pos = (RenderPosView* ) arg0->mtxlist;
    arg0->mtxlist += arg1->obj->numMatrices;
    modelUpdateMatrices((ModelRenderData* ) arg0, arg1);
}


/**
 * Address 0x7F06F2F8 (VERSION_US, VERSION_JP)
 * Address 0x7F06F670 (VERSION_EU)
*/
void subcalcmatrices(struct unk_joint_list *arg0, struct Model *arg1)
{
#if defined(LEFTOVERDEBUG)
    if (arg1 == NULL)
    {
        osSyncPrintf("subcalcmatrices: no objanim!\n");
        return_null();
    }

    if (arg0->unk_matrix == NULL)
    {
        osSyncPrintf("subcalcmatrices: no basemtx!\n");
        return_null();
    }

    if (arg0->mtxlist == NULL)
    {
        osSyncPrintf("subcalcmatrices: no mtxlist!\n");
        return_null();
    }
#endif

    if (arg1->anim != NULL)
    {
#if defined(LEFTOVERDEBUG)
        if ((arg1->attachedto != NULL) && (arg1->attachedto_objinst == NULL))
        {
            osSyncPrintf("subcalcmatrices: no attach for objinst!\n");
            return_null();
        }

        if (((s32) arg1->framea < 0) || ((s32) arg1->framea >= (s32) arg1->anim->unk04))
        {
            osSyncPrintf("subcalcmatrices: framea out of range!\n");
            return_null();
        }

        if (((s32) arg1->frameb < 0) || ((s32) arg1->frameb >= (s32) arg1->anim->unk04))
        {
            osSyncPrintf("subcalcmatrices: frameb out of range!\n");
            return_null();
        }

        if ((arg1->unk84 == 0) || ((arg1->unk84 != 0) && (arg1->anim2 != NULL)))
        {
            //
        }
        else
        {
            osSyncPrintf("subcalcmatrices: no anim2!\n");
            return_null();
        }

        if (
            (arg1->anim2 != NULL)
            && (
                (arg1->anim2 == NULL)
                || (arg1->frame2a < 0)
                || ((s32) arg1->frame2a >= (s32) arg1->anim2->unk04)
                )
            )
        {
            osSyncPrintf("subcalcmatrices: frame2a out of range!\n");
            return_null();
        }

        if (
            (arg1->anim2 == NULL) 
            || (
                (arg1->anim2 != NULL)
                 && (arg1->frame2b >= 0)
                 && ((s32) arg1->frame2b < (s32) arg1->anim2->unk04)
                )
            )
        {
            //
        }
        else
        {
            osSyncPrintf("subcalcmatrices: frame2b out of range!\n");
            return_null();
        }
#endif

        arg1->unk34 = sub_GAME_7F0754BC(arg1->anim, arg1->framea, arg1->obj->Skeleton);

        if (arg1->unk2c != 0.0f)
        {
            arg1->unk38 = sub_GAME_7F0754BC(arg1->anim, arg1->frameb, arg1->obj->Skeleton);
        }

        if (arg1->anim2 != NULL)
        {
            arg1->unk64 = sub_GAME_7F0754BC(arg1->anim2, arg1->frame2a, arg1->obj->Skeleton);

            if (arg1->unk5c != 0.0f)
            {
                arg1->unk68 = sub_GAME_7F0754BC(arg1->anim2, arg1->frame2b, arg1->obj->Skeleton);
            }
        }

        sub_GAME_7F0755B0();
    }

    instcalcmatrices(arg0, arg1);
}

/**
 * Address 0x7F06F5AC.
*/
struct ModelAnimation * objecthandlerGetModelAnim(struct Model* model) {
    return model->anim;
}

s8 objecthandlerGetModelGunhand(Model *model) {
    return model->gunhand;
}

/**
 * Address 0x7F06F5BC.
*/
f32 objecthandlerGetModelField28(Model *model)
{
    return model->unk28;
}

f32 sub_GAME_7F06F5C4(Model *model)
{
    f32 unk3c;
    ModelAnimation *modelAnimation;

    unk3c = model->endframe;
    if (unk3c >= 0.0f)
    {
        return unk3c;
    }

    modelAnimation = model->anim;
    
    if (modelAnimation != NULL)
    {
        return modelAnimation->unk04 - 1;
    }
    return 0.0f;
}


f32 modelGetAnimSpeed(Model *model)
{
    return model->speed;
}


/**
 * Address 0x7F06F618.
 * PD: modelGetAbsAnimSpeed
*/
f32 modelGetAbsAnimSpeed(Model *model)
{
    f32 speed;

    speed = model->speed;
    
    if (speed < 0.0f)
    {
        speed = -speed;
    }
    
    return speed;
}

/**
 * Unused Function
*/
f32 modelGetEffectiveAnimSpeed(Model *model) {
    return modelGetAnimSpeed(model) * model->playspeed;
}


#ifdef NONMATCHING
s32 modelConstrainOrWrapAnimFrame(s32 frame, ModelAnimation *anim, f32 endframe)
{
    //s32 frame;
    //u16 animnum->unk4;
    //u16 animnum->unk4;

    //frame = frame;
    if (frame < 0)
    {
        if (animnum->unk7 & 1)
        {
            //animnum->unk4 = animnum->unk4;
            frame = animnum->unk4 - ((s32) -frame % (s32) animnum->unk4);
        }
        else
        {
            frame = 0;
        }
    }
    else if ((endframe >= 0.0f) && ((s32) endframe < frame))
    {
        frame = ceilFloatToInt(endframe);
    }
    else
    {
        //animnum->unk4 = animnum->unk4;
        if (frame >= (s32) animnum->unk4)
        {
            if (animnum->unk7 & 1)
            {
                frame = frame % (s32) animnum->unk4;
            }
            else
            {
                frame = animnum->unk4 - 1;
            }
        }
    }
    return frame;
}
#else
s32 modelConstrainOrWrapAnimFrame(s32 frame, ModelAnimation *anim, f32 endframe);
GLOBAL_ASM(
.text
glabel modelConstrainOrWrapAnimFrame
/* 0A419C 7F06F66C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A41A0 7F06F670 44866000 */  mtc1  $a2, $f12
/* 0A41A4 7F06F674 04810017 */  bgez  $a0, .L7F06F6D4
/* 0A41A8 7F06F678 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0A41AC 7F06F67C 90AE0007 */  lbu   $t6, 7($a1)
/* 0A41B0 7F06F680 31CF0001 */  andi  $t7, $t6, 1
/* 0A41B4 7F06F684 11E00011 */  beqz  $t7, .L7F06F6CC
/* 0A41B8 7F06F688 00000000 */   nop   
/* 0A41BC 7F06F68C 94A20004 */  lhu   $v0, 4($a1)
/* 0A41C0 7F06F690 0004C023 */  negu  $t8, $a0
/* 0A41C4 7F06F694 0302001A */  div   $zero, $t8, $v0
/* 0A41C8 7F06F698 0000C810 */  mfhi  $t9
/* 0A41CC 7F06F69C 00592023 */  subu  $a0, $v0, $t9
/* 0A41D0 7F06F6A0 14400002 */  bnez  $v0, .L7F06F6AC
/* 0A41D4 7F06F6A4 00000000 */   nop   
/* 0A41D8 7F06F6A8 0007000D */  break 7
.L7F06F6AC:
/* 0A41DC 7F06F6AC 2401FFFF */  li    $at, -1
/* 0A41E0 7F06F6B0 14410004 */  bne   $v0, $at, .L7F06F6C4
/* 0A41E4 7F06F6B4 3C018000 */   lui   $at, 0x8000
/* 0A41E8 7F06F6B8 17010002 */  bne   $t8, $at, .L7F06F6C4
/* 0A41EC 7F06F6BC 00000000 */   nop   
/* 0A41F0 7F06F6C0 0006000D */  break 6
.L7F06F6C4:
/* 0A41F4 7F06F6C4 1000002A */  b     .L7F06F770
/* 0A41F8 7F06F6C8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06F6CC:
/* 0A41FC 7F06F6CC 10000027 */  b     .L7F06F76C
/* 0A4200 7F06F6D0 00002025 */   move  $a0, $zero
.L7F06F6D4:
/* 0A4204 7F06F6D4 44802000 */  mtc1  $zero, $f4
/* 0A4208 7F06F6D8 00000000 */  nop   
/* 0A420C 7F06F6DC 460C203E */  c.le.s $f4, $f12
/* 0A4210 7F06F6E0 00000000 */  nop   
/* 0A4214 7F06F6E4 4502000C */  bc1fl .L7F06F718
/* 0A4218 7F06F6E8 94A20004 */   lhu   $v0, 4($a1)
/* 0A421C 7F06F6EC 4600618D */  trunc.w.s $f6, $f12
/* 0A4220 7F06F6F0 44093000 */  mfc1  $t1, $f6
/* 0A4224 7F06F6F4 00000000 */  nop   
/* 0A4228 7F06F6F8 0124082A */  slt   $at, $t1, $a0
/* 0A422C 7F06F6FC 50200006 */  beql  $at, $zero, .L7F06F718
/* 0A4230 7F06F700 94A20004 */   lhu   $v0, 4($a1)
/* 0A4234 7F06F704 0FC1712E */  jal   ceilFloatToInt
/* 0A4238 7F06F708 00000000 */   nop   
/* 0A423C 7F06F70C 10000017 */  b     .L7F06F76C
/* 0A4240 7F06F710 00402025 */   move  $a0, $v0
/* 0A4244 7F06F714 94A20004 */  lhu   $v0, 4($a1)
.L7F06F718:
/* 0A4248 7F06F718 0082082A */  slt   $at, $a0, $v0
/* 0A424C 7F06F71C 54200014 */  bnezl $at, .L7F06F770
/* 0A4250 7F06F720 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A4254 7F06F724 90AA0007 */  lbu   $t2, 7($a1)
/* 0A4258 7F06F728 314B0001 */  andi  $t3, $t2, 1
/* 0A425C 7F06F72C 5160000F */  beql  $t3, $zero, .L7F06F76C
/* 0A4260 7F06F730 2444FFFF */   addiu $a0, $v0, -1
/* 0A4264 7F06F734 0082001A */  div   $zero, $a0, $v0
/* 0A4268 7F06F738 14400002 */  bnez  $v0, .L7F06F744
/* 0A426C 7F06F73C 00000000 */   nop   
/* 0A4270 7F06F740 0007000D */  break 7
.L7F06F744:
/* 0A4274 7F06F744 2401FFFF */  li    $at, -1
/* 0A4278 7F06F748 14410004 */  bne   $v0, $at, .L7F06F75C
/* 0A427C 7F06F74C 3C018000 */   lui   $at, 0x8000
/* 0A4280 7F06F750 14810002 */  bne   $a0, $at, .L7F06F75C
/* 0A4284 7F06F754 00000000 */   nop   
/* 0A4288 7F06F758 0006000D */  break 6
.L7F06F75C:
/* 0A428C 7F06F75C 00002010 */  mfhi  $a0
/* 0A4290 7F06F760 10000003 */  b     .L7F06F770
/* 0A4294 7F06F764 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A4298 7F06F768 2444FFFF */  addiu $a0, $v0, -1
.L7F06F76C:
/* 0A429C 7F06F76C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06F770:
/* 0A42A0 7F06F770 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A42A4 7F06F774 00801025 */  move  $v0, $a0
/* 0A42A8 7F06F778 03E00008 */  jr    $ra
/* 0A42AC 7F06F77C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void modelCopyAnimForMerge(Model *model, f32 arg1)
{
    ModelNode      *temp_a1;
    f32             temp_f10;
    f32             temp_f16;
    f32             temp_f18;
    f32             temp_f4;
    f32             temp_f6;
    f32             temp_f8;
    modeldata_root *temp_v0_2;
    
    if ((arg1 > 0.0f) && (model->anim != 0))
    {
        temp_a1      = model->obj->RootNode;
        model->unk58 = model->unk28;
        model->unk5C = model->unk2C;
        model->unk54 = model->anim;
        model->unk25 = model->unk24;
        model->unk60 = model->unk30;
        model->unk62 = model->unk32;
        model->unk70 = model->speed;
        model->unk74 = model->newspeed;
        model->unk78 = model->oldspeed;
        model->unk7C = model->timespeed;
        model->unk80 = model->elapsespeed;
        model->unk6C = model->endframe;
        if ((temp_a1->Opcode & 0xFF) == 1)
        {
            temp_v0_2                   = modelGetNodeRwData(model, temp_a1);
            temp_f10                    = temp_v0_2->unk34.x;
            temp_f16                    = temp_v0_2->unk34.AsArray[1];
            temp_f18                    = temp_v0_2->unk34.AsArray[2];
            temp_f4                     = temp_v0_2->unk24.x;
            temp_f6                     = temp_v0_2->unk24.AsArray[1];
            temp_f8                     = temp_v0_2->unk24.AsArray[2];
            temp_v0_2->unk02            = 1;
            temp_v0_2->unk4c.x          = temp_f10;
            temp_v0_2->unk4c.AsArray[1] = temp_f16;
            temp_v0_2->unk4c.AsArray[2] = temp_f18;
            temp_v0_2->unk40.x          = temp_f4;
            temp_v0_2->unk40.AsArray[1] = temp_f6;
            temp_v0_2->unk40.AsArray[2] = temp_f8;
            return;
        }
        // Duplicate return node #5. Try simplifying control flow for better match
        return;
    }
    model->unk54 = NULL;
}
#else
GLOBAL_ASM(
.text
glabel modelCopyAnimForMerge
/* 0A42B0 7F06F780 44856000 */  mtc1  $a1, $f12
/* 0A42B4 7F06F784 44802000 */  mtc1  $zero, $f4
/* 0A42B8 7F06F788 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A42BC 7F06F78C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A42C0 7F06F790 460C203C */  c.lt.s $f4, $f12
/* 0A42C4 7F06F794 00000000 */  nop   
/* 0A42C8 7F06F798 45020033 */  bc1fl .L7F06F868
/* 0A42CC 7F06F79C AC800054 */   sw    $zero, 0x54($a0)
/* 0A42D0 7F06F7A0 8C820020 */  lw    $v0, 0x20($a0)
/* 0A42D4 7F06F7A4 24010001 */  li    $at, 1
/* 0A42D8 7F06F7A8 5040002F */  beql  $v0, $zero, .L7F06F868
/* 0A42DC 7F06F7AC AC800054 */   sw    $zero, 0x54($a0)
/* 0A42E0 7F06F7B0 8C8E0008 */  lw    $t6, 8($a0)
/* 0A42E4 7F06F7B4 C4860028 */  lwc1  $f6, 0x28($a0)
/* 0A42E8 7F06F7B8 C488002C */  lwc1  $f8, 0x2c($a0)
/* 0A42EC 7F06F7BC 8DC50000 */  lw    $a1, ($t6)
/* 0A42F0 7F06F7C0 80980024 */  lb    $t8, 0x24($a0)
/* 0A42F4 7F06F7C4 84990030 */  lh    $t9, 0x30($a0)
/* 0A42F8 7F06F7C8 94A30000 */  lhu   $v1, ($a1)
/* 0A42FC 7F06F7CC E4860058 */  swc1  $f6, 0x58($a0)
/* 0A4300 7F06F7D0 E488005C */  swc1  $f8, 0x5c($a0)
/* 0A4304 7F06F7D4 84880032 */  lh    $t0, 0x32($a0)
/* 0A4308 7F06F7D8 C48A0040 */  lwc1  $f10, 0x40($a0)
/* 0A430C 7F06F7DC C4900044 */  lwc1  $f16, 0x44($a0)
/* 0A4310 7F06F7E0 C4920048 */  lwc1  $f18, 0x48($a0)
/* 0A4314 7F06F7E4 C484004C */  lwc1  $f4, 0x4c($a0)
/* 0A4318 7F06F7E8 C4860050 */  lwc1  $f6, 0x50($a0)
/* 0A431C 7F06F7EC C488003C */  lwc1  $f8, 0x3c($a0)
/* 0A4320 7F06F7F0 306F00FF */  andi  $t7, $v1, 0xff
/* 0A4324 7F06F7F4 AC820054 */  sw    $v0, 0x54($a0)
/* 0A4328 7F06F7F8 A0980025 */  sb    $t8, 0x25($a0)
/* 0A432C 7F06F7FC A4990060 */  sh    $t9, 0x60($a0)
/* 0A4330 7F06F800 A4880062 */  sh    $t0, 0x62($a0)
/* 0A4334 7F06F804 E48A0070 */  swc1  $f10, 0x70($a0)
/* 0A4338 7F06F808 E4900074 */  swc1  $f16, 0x74($a0)
/* 0A433C 7F06F80C E4920078 */  swc1  $f18, 0x78($a0)
/* 0A4340 7F06F810 E484007C */  swc1  $f4, 0x7c($a0)
/* 0A4344 7F06F814 E4860080 */  swc1  $f6, 0x80($a0)
/* 0A4348 7F06F818 15E10013 */  bne   $t7, $at, .L7F06F868
/* 0A434C 7F06F81C E488006C */   swc1  $f8, 0x6c($a0)
/* 0A4350 7F06F820 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0A4354 7F06F824 00000000 */   nop   
/* 0A4358 7F06F828 C44A0034 */  lwc1  $f10, 0x34($v0)
/* 0A435C 7F06F82C C4500038 */  lwc1  $f16, 0x38($v0)
/* 0A4360 7F06F830 C452003C */  lwc1  $f18, 0x3c($v0)
/* 0A4364 7F06F834 C4440024 */  lwc1  $f4, 0x24($v0)
/* 0A4368 7F06F838 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0A436C 7F06F83C C448002C */  lwc1  $f8, 0x2c($v0)
/* 0A4370 7F06F840 24090001 */  li    $t1, 1
/* 0A4374 7F06F844 A0490002 */  sb    $t1, 2($v0)
/* 0A4378 7F06F848 E44A004C */  swc1  $f10, 0x4c($v0)
/* 0A437C 7F06F84C E4500050 */  swc1  $f16, 0x50($v0)
/* 0A4380 7F06F850 E4520054 */  swc1  $f18, 0x54($v0)
/* 0A4384 7F06F854 E4440040 */  swc1  $f4, 0x40($v0)
/* 0A4388 7F06F858 E4460044 */  swc1  $f6, 0x44($v0)
/* 0A438C 7F06F85C 10000002 */  b     .L7F06F868
/* 0A4390 7F06F860 E4480048 */   swc1  $f8, 0x48($v0)
/* 0A4394 7F06F864 AC800054 */  sw    $zero, 0x54($a0)
.L7F06F868:
/* 0A4398 7F06F868 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A439C 7F06F86C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A43A0 7F06F870 03E00008 */  jr    $ra
/* 0A43A4 7F06F874 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void modelSetAnimation2(Model *model, void *anim, s32 arg2, f32 startframe, f32 half, f32 arg5)
{
    void           *sp80;
    f32             sp70;
    f32             sp6C;
    f32             sp64;
    f32             sp60;
    f32             sp5C;
    f32             sp58;
    f32             sp54;
    f32             sp50;
    f32             sp4C;
    f32             sp48;
    f32             sp44;
    f32             sp40;
    f32             sp30;
    s32             sp2C;
    ModelNode      *temp_a1;
    f32             temp_f0;
    f32             temp_f0_2;
    f32             temp_f0_3;
    f32             temp_f10;
    f32             temp_f12;
    f32             temp_f12_2;
    f32             temp_f14;
    f32             temp_f14_2;
    f32             temp_f2;
    f32             temp_f2_2;
    f32             temp_f2_3;
    f32             temp_f2_4;
    f32             temp_f4;
    f32             temp_f6;
    modeldata_root *temp_v0;
    f32             phi_f14;

    sp2C = model->anim == 0;
    if (model->unk54 != 0)
    {
        model->unk88 = arg5;
        model->unk8C = 0.0f;
        model->unk84 = 1.0f;
    }
    else
    {
        model->unk88 = 0.0f;
        model->unk84 = 0.0f;
    }
    model->anim  = anim;
    model->unk24 = arg2;
    model->endframe = -1.0f;
    model->speed = half;
    model->timespeed = 0.0f;
    modelSetAnimFrame(startframe, model, startframe, anim);
    model->unk26 = 0;
    temp_a1      = model->obj->RootNode;
    if ((temp_a1->Opcode & 0xFF) == 1)
    {
        sp80      = temp_a1->Data;
        temp_v0   = modelGetNodeRwData(model, temp_a1);
        sp5C.unk0 = D_80036244.unk0;
        temp_f2   = model->scale * model->unkB8;
        sp5C.unk4 = D_80036244.unk4;
        sp5C.unk8 = D_80036244.unk8;
        sp70      = temp_f2;
        sp58      = sub_GAME_7F06D3F4(*sp80, model->unk24, model->obj->Skeleton, model->anim, model->unk32, &sp5C);
        if (temp_f2 != 1.0f)
        {
            sp5C *= temp_f2;
            sp60 *= temp_f2;
            sp64 *= temp_f2;
        }
        sp6C      = cosf(temp_v0->unk14);
        temp_f0   = sinf(temp_v0->unk14);
        temp_f2_2 = model->unk2C;
        if (temp_f2_2 == 0.0f)
        {
            temp_f2_3                 = temp_v0->pos.x;
            temp_v0->unk34.x          = temp_f2_3;
            temp_v0->unk34.AsArray[2] = temp_v0->pos.AsArray[2];
            temp_v0->unk34.AsArray[1] = temp_v0->pos.AsArray[1] - temp_v0->ground;
            temp_v0->unk30            = temp_v0->unk14;
            temp_f4                   = (sp64 * temp_f0) + (temp_f2_3 + (sp5C * sp6C));
            sp4C                      = temp_f4;
            sp50                      = sp60;
            sp54                      = (sp64 * sp6C) + (temp_v0->unk34.AsArray[2] - (sp5C * temp_f0));
            temp_v0->unk24.x          = temp_f4;
            temp_v0->unk24.AsArray[1] = sp50;
            temp_v0->unk24.AsArray[2] = sp54;
            if (temp_v0->unk18 == 0.0f)
            {
                temp_f0_2      = temp_v0->unk30 + sp58;
                temp_v0->unk20 = temp_f0_2;
                if (temp_f0_2 >= M_TAU_F)
                {
                    temp_v0->unk20 -= M_TAU_F;
                }
            }
            temp_v0->unk1 = 1;
        }
        else
        {
            temp_f14                  = (sp64 * temp_f0) + (sp5C * sp6C);
            temp_f10                  = (sp64 * sp6C) + (-sp5C * temp_f0);
            sp30                      = temp_f10;
            sp44                      = sp60;
            temp_f6                   = temp_v0->pos.x + (temp_f14 * (1.0f - temp_f2_2));
            sp40                      = temp_f6;
            sp48                      = temp_v0->pos.AsArray[2] + (temp_f10 * (1.0f - model->unk2C));
            temp_v0->unk24.x          = temp_f6;
            temp_v0->unk24.AsArray[1] = sp44;
            temp_v0->unk24.AsArray[2] = sp48;
            temp_v0->unk34.x          = temp_v0->unk24.x - temp_f14;
            temp_f12                  = temp_v0->pos.AsArray[1] - temp_v0->ground;
            temp_f2_4                 = model->unk2C;
            temp_f12_2                = temp_v0->unk14;
            temp_v0->unk34.AsArray[1] = temp_f12 - (((sp60 - temp_f12) * temp_f2_4) / (1.0f - temp_f2_4));
            temp_v0->unk34.AsArray[2] = temp_v0->unk24.AsArray[2] - sp30;
            temp_f14_2                = temp_f12_2 - sp58;
            phi_f14                   = temp_f14_2;
            if (temp_f14_2 < 0.0f)
            {
                phi_f14 = temp_f14_2 + M_TAU_F;
            }
            temp_v0->unk30 = sub_GAME_7F06D0CC(temp_f12_2, phi_f14, model->unk2C);
            if (temp_v0->unk18 == 0.0f)
            {
                temp_f0_3      = temp_v0->unk30 + sp58;
                temp_v0->unk20 = temp_f0_3;
                if (temp_f0_3 >= M_TAU_F)
                {
                    temp_v0->unk20 -= M_TAU_F;
                }
            }
            temp_v0->unk1 = 1;
        }
        if (sp2C != 0)
        {
            temp_v0->unk34.AsArray[1] = temp_v0->unk24.AsArray[1];
        }
    }
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054D40
.word 0x40c90fdb /*6.2831855*/
glabel D_80054D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80054D48
.word 0x40c90fdb /*6.2831855*/
.text
glabel modelSetAnimation2
/* 0A43A8 7F06F878 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0A43AC 7F06F87C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A43B0 7F06F880 AFB10020 */  sw    $s1, 0x20($sp)
/* 0A43B4 7F06F884 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0A43B8 7F06F888 AFA50094 */  sw    $a1, 0x94($sp)
/* 0A43BC 7F06F88C 8C8E0020 */  lw    $t6, 0x20($a0)
/* 0A43C0 7F06F890 44876000 */  mtc1  $a3, $f12
/* 0A43C4 7F06F894 00A03825 */  move  $a3, $a1
/* 0A43C8 7F06F898 2DCF0001 */  sltiu $t7, $t6, 1
/* 0A43CC 7F06F89C AFAF002C */  sw    $t7, 0x2c($sp)
/* 0A43D0 7F06F8A0 8C980054 */  lw    $t8, 0x54($a0)
/* 0A43D4 7F06F8A4 44056000 */  mfc1  $a1, $f12
/* 0A43D8 7F06F8A8 00808825 */  move  $s1, $a0
/* 0A43DC 7F06F8AC 13000008 */  beqz  $t8, .L7F06F8D0
/* 0A43E0 7F06F8B0 C7A400A4 */   lwc1  $f4, 0xa4($sp)
/* 0A43E4 7F06F8B4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A43E8 7F06F8B8 44803000 */  mtc1  $zero, $f6
/* 0A43EC 7F06F8BC 44814000 */  mtc1  $at, $f8
/* 0A43F0 7F06F8C0 E4840088 */  swc1  $f4, 0x88($a0)
/* 0A43F4 7F06F8C4 E486008C */  swc1  $f6, 0x8c($a0)
/* 0A43F8 7F06F8C8 10000005 */  b     .L7F06F8E0
/* 0A43FC 7F06F8CC E4880084 */   swc1  $f8, 0x84($a0)
.L7F06F8D0:
/* 0A4400 7F06F8D0 44805000 */  mtc1  $zero, $f10
/* 0A4404 7F06F8D4 44802000 */  mtc1  $zero, $f4
/* 0A4408 7F06F8D8 E62A0088 */  swc1  $f10, 0x88($s1)
/* 0A440C 7F06F8DC E6240084 */  swc1  $f4, 0x84($s1)
.L7F06F8E0:
/* 0A4410 7F06F8E0 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0A4414 7F06F8E4 44813000 */  mtc1  $at, $f6
/* 0A4418 7F06F8E8 AE270020 */  sw    $a3, 0x20($s1)
/* 0A441C 7F06F8EC A2260024 */  sb    $a2, 0x24($s1)
/* 0A4420 7F06F8F0 E626003C */  swc1  $f6, 0x3c($s1)
/* 0A4424 7F06F8F4 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 0A4428 7F06F8F8 44805000 */  mtc1  $zero, $f10
/* 0A442C 7F06F8FC 02202025 */  move  $a0, $s1
/* 0A4430 7F06F900 E6280040 */  swc1  $f8, 0x40($s1)
/* 0A4434 7F06F904 0FC1BFD9 */  jal   modelSetAnimFrame
/* 0A4438 7F06F908 E62A004C */   swc1  $f10, 0x4c($s1)
/* 0A443C 7F06F90C 8E390008 */  lw    $t9, 8($s1)
/* 0A4440 7F06F910 A2200026 */  sb    $zero, 0x26($s1)
/* 0A4444 7F06F914 24010001 */  li    $at, 1
/* 0A4448 7F06F918 8F250000 */  lw    $a1, ($t9)
/* 0A444C 7F06F91C 94A20000 */  lhu   $v0, ($a1)
/* 0A4450 7F06F920 304800FF */  andi  $t0, $v0, 0xff
/* 0A4454 7F06F924 550100C5 */  bnel  $t0, $at, .L7F06FC3C
/* 0A4458 7F06F928 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A445C 7F06F92C 8CA90004 */  lw    $t1, 4($a1)
/* 0A4460 7F06F930 02202025 */  move  $a0, $s1
/* 0A4464 7F06F934 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0A4468 7F06F938 AFA90080 */   sw    $t1, 0x80($sp)
/* 0A446C 7F06F93C 3C0C8003 */  lui   $t4, %hi(D_80036244) 
/* 0A4470 7F06F940 8FAA0080 */  lw    $t2, 0x80($sp)
/* 0A4474 7F06F944 8E2B0008 */  lw    $t3, 8($s1)
/* 0A4478 7F06F948 258C6244 */  addiu $t4, %lo(D_80036244) # addiu $t4, $t4, 0x6244
/* 0A447C 7F06F94C 8D810000 */  lw    $at, ($t4)
/* 0A4480 7F06F950 C6240014 */  lwc1  $f4, 0x14($s1)
/* 0A4484 7F06F954 C62600B8 */  lwc1  $f6, 0xb8($s1)
/* 0A4488 7F06F958 27A3005C */  addiu $v1, $sp, 0x5c
/* 0A448C 7F06F95C 95440000 */  lhu   $a0, ($t2)
/* 0A4490 7F06F960 8D660004 */  lw    $a2, 4($t3)
/* 0A4494 7F06F964 AC610000 */  sw    $at, ($v1)
/* 0A4498 7F06F968 8D8F0004 */  lw    $t7, 4($t4)
/* 0A449C 7F06F96C 46062082 */  mul.s $f2, $f4, $f6
/* 0A44A0 7F06F970 00408025 */  move  $s0, $v0
/* 0A44A4 7F06F974 AC6F0004 */  sw    $t7, 4($v1)
/* 0A44A8 7F06F978 8D810008 */  lw    $at, 8($t4)
/* 0A44AC 7F06F97C AC610008 */  sw    $at, 8($v1)
/* 0A44B0 7F06F980 86380032 */  lh    $t8, 0x32($s1)
/* 0A44B4 7F06F984 8E270020 */  lw    $a3, 0x20($s1)
/* 0A44B8 7F06F988 82250024 */  lb    $a1, 0x24($s1)
/* 0A44BC 7F06F98C E7A20070 */  swc1  $f2, 0x70($sp)
/* 0A44C0 7F06F990 AFA30014 */  sw    $v1, 0x14($sp)
/* 0A44C4 7F06F994 0FC1B4FD */  jal   sub_GAME_7F06D3F4
/* 0A44C8 7F06F998 AFB80010 */   sw    $t8, 0x10($sp)
/* 0A44CC 7F06F99C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A44D0 7F06F9A0 C7A20070 */  lwc1  $f2, 0x70($sp)
/* 0A44D4 7F06F9A4 44814000 */  mtc1  $at, $f8
/* 0A44D8 7F06F9A8 E7A00058 */  swc1  $f0, 0x58($sp)
/* 0A44DC 7F06F9AC C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0A44E0 7F06F9B0 46081032 */  c.eq.s $f2, $f8
/* 0A44E4 7F06F9B4 00000000 */  nop   
/* 0A44E8 7F06F9B8 45010009 */  bc1t  .L7F06F9E0
/* 0A44EC 7F06F9BC 00000000 */   nop   
/* 0A44F0 7F06F9C0 46025102 */  mul.s $f4, $f10, $f2
/* 0A44F4 7F06F9C4 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0A44F8 7F06F9C8 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0A44FC 7F06F9CC 46023202 */  mul.s $f8, $f6, $f2
/* 0A4500 7F06F9D0 E7A4005C */  swc1  $f4, 0x5c($sp)
/* 0A4504 7F06F9D4 46025102 */  mul.s $f4, $f10, $f2
/* 0A4508 7F06F9D8 E7A80060 */  swc1  $f8, 0x60($sp)
/* 0A450C 7F06F9DC E7A40064 */  swc1  $f4, 0x64($sp)
.L7F06F9E0:
/* 0A4510 7F06F9E0 0FC15FA8 */  jal   cosf
/* 0A4514 7F06F9E4 C60C0014 */   lwc1  $f12, 0x14($s0)
/* 0A4518 7F06F9E8 C60C0014 */  lwc1  $f12, 0x14($s0)
/* 0A451C 7F06F9EC 0FC15FAB */  jal   sinf
/* 0A4520 7F06F9F0 E7A0006C */   swc1  $f0, 0x6c($sp)
/* 0A4524 7F06F9F4 C622002C */  lwc1  $f2, 0x2c($s1)
/* 0A4528 7F06F9F8 44803000 */  mtc1  $zero, $f6
/* 0A452C 7F06F9FC C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0A4530 7F06FA00 24190001 */  li    $t9, 1
/* 0A4534 7F06FA04 46023032 */  c.eq.s $f6, $f2
/* 0A4538 7F06FA08 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0A453C 7F06FA0C C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0A4540 7F06FA10 45000032 */  bc1f  .L7F06FADC
/* 0A4544 7F06FA14 00000000 */   nop   
/* 0A4548 7F06FA18 C608000C */  lwc1  $f8, 0xc($s0)
/* 0A454C 7F06FA1C C60A0004 */  lwc1  $f10, 4($s0)
/* 0A4550 7F06FA20 C6020008 */  lwc1  $f2, 8($s0)
/* 0A4554 7F06FA24 C6060010 */  lwc1  $f6, 0x10($s0)
/* 0A4558 7F06FA28 460A4101 */  sub.s $f4, $f8, $f10
/* 0A455C 7F06FA2C C6080014 */  lwc1  $f8, 0x14($s0)
/* 0A4560 7F06FA30 E6020034 */  swc1  $f2, 0x34($s0)
/* 0A4564 7F06FA34 E606003C */  swc1  $f6, 0x3c($s0)
/* 0A4568 7F06FA38 E6040038 */  swc1  $f4, 0x38($s0)
/* 0A456C 7F06FA3C E6080030 */  swc1  $f8, 0x30($s0)
/* 0A4570 7F06FA40 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0A4574 7F06FA44 C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 0A4578 7F06FA48 46005102 */  mul.s $f4, $f10, $f0
/* 0A457C 7F06FA4C 00000000 */  nop   
/* 0A4580 7F06FA50 46123202 */  mul.s $f8, $f6, $f18
/* 0A4584 7F06FA54 46081200 */  add.s $f8, $f2, $f8
/* 0A4588 7F06FA58 46003182 */  mul.s $f6, $f6, $f0
/* 0A458C 7F06FA5C 46082100 */  add.s $f4, $f4, $f8
/* 0A4590 7F06FA60 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0A4594 7F06FA64 E7A4004C */  swc1  $f4, 0x4c($sp)
/* 0A4598 7F06FA68 E7A80050 */  swc1  $f8, 0x50($sp)
/* 0A459C 7F06FA6C C608003C */  lwc1  $f8, 0x3c($s0)
/* 0A45A0 7F06FA70 46064201 */  sub.s $f8, $f8, $f6
/* 0A45A4 7F06FA74 46125182 */  mul.s $f6, $f10, $f18
/* 0A45A8 7F06FA78 46083280 */  add.s $f10, $f6, $f8
/* 0A45AC 7F06FA7C E7AA0054 */  swc1  $f10, 0x54($sp)
/* 0A45B0 7F06FA80 E6040024 */  swc1  $f4, 0x24($s0)
/* 0A45B4 7F06FA84 C6040018 */  lwc1  $f4, 0x18($s0)
/* 0A45B8 7F06FA88 44805000 */  mtc1  $zero, $f10
/* 0A45BC 7F06FA8C C7A60050 */  lwc1  $f6, 0x50($sp)
/* 0A45C0 7F06FA90 46045032 */  c.eq.s $f10, $f4
/* 0A45C4 7F06FA94 E6060028 */  swc1  $f6, 0x28($s0)
/* 0A45C8 7F06FA98 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 0A45CC 7F06FA9C 4500000D */  bc1f  .L7F06FAD4
/* 0A45D0 7F06FAA0 E608002C */   swc1  $f8, 0x2c($s0)
/* 0A45D4 7F06FAA4 C6060030 */  lwc1  $f6, 0x30($s0)
/* 0A45D8 7F06FAA8 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 0A45DC 7F06FAAC 3C018005 */  lui    $at, %hi(D_80054D40)
/* 0A45E0 7F06FAB0 C4224D40 */  lwc1  $f2, %lo(D_80054D40)($at)
/* 0A45E4 7F06FAB4 46083000 */  add.s $f0, $f6, $f8
/* 0A45E8 7F06FAB8 4600103E */  c.le.s $f2, $f0
/* 0A45EC 7F06FABC E6000020 */  swc1  $f0, 0x20($s0)
/* 0A45F0 7F06FAC0 45000004 */  bc1f  .L7F06FAD4
/* 0A45F4 7F06FAC4 00000000 */   nop   
/* 0A45F8 7F06FAC8 C60A0020 */  lwc1  $f10, 0x20($s0)
/* 0A45FC 7F06FACC 46025101 */  sub.s $f4, $f10, $f2
/* 0A4600 7F06FAD0 E6040020 */  swc1  $f4, 0x20($s0)
.L7F06FAD4:
/* 0A4604 7F06FAD4 10000053 */  b     .L7F06FC24
/* 0A4608 7F06FAD8 A2190001 */   sb    $t9, 1($s0)
.L7F06FADC:
/* 0A460C 7F06FADC 46003202 */  mul.s $f8, $f6, $f0
/* 0A4610 7F06FAE0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A4614 7F06FAE4 C7B00060 */  lwc1  $f16, 0x60($sp)
/* 0A4618 7F06FAE8 46125102 */  mul.s $f4, $f10, $f18
/* 0A461C 7F06FAEC 46044380 */  add.s $f14, $f8, $f4
/* 0A4620 7F06FAF0 46123202 */  mul.s $f8, $f6, $f18
/* 0A4624 7F06FAF4 46005107 */  neg.s $f4, $f10
/* 0A4628 7F06FAF8 46002182 */  mul.s $f6, $f4, $f0
/* 0A462C 7F06FAFC 46064280 */  add.s $f10, $f8, $f6
/* 0A4630 7F06FB00 44814000 */  mtc1  $at, $f8
/* 0A4634 7F06FB04 00000000 */  nop   
/* 0A4638 7F06FB08 46024181 */  sub.s $f6, $f8, $f2
/* 0A463C 7F06FB0C E7AA0030 */  swc1  $f10, 0x30($sp)
/* 0A4640 7F06FB10 C6040008 */  lwc1  $f4, 8($s0)
/* 0A4644 7F06FB14 E7B00044 */  swc1  $f16, 0x44($sp)
/* 0A4648 7F06FB18 46067202 */  mul.s $f8, $f14, $f6
/* 0A464C 7F06FB1C 46082180 */  add.s $f6, $f4, $f8
/* 0A4650 7F06FB20 44812000 */  mtc1  $at, $f4
/* 0A4654 7F06FB24 E7A60040 */  swc1  $f6, 0x40($sp)
/* 0A4658 7F06FB28 C628002C */  lwc1  $f8, 0x2c($s1)
/* 0A465C 7F06FB2C 46082181 */  sub.s $f6, $f4, $f8
/* 0A4660 7F06FB30 C6080010 */  lwc1  $f8, 0x10($s0)
/* 0A4664 7F06FB34 46065102 */  mul.s $f4, $f10, $f6
/* 0A4668 7F06FB38 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 0A466C 7F06FB3C 46044280 */  add.s $f10, $f8, $f4
/* 0A4670 7F06FB40 E7AA0048 */  swc1  $f10, 0x48($sp)
/* 0A4674 7F06FB44 E6060024 */  swc1  $f6, 0x24($s0)
/* 0A4678 7F06FB48 C7A80044 */  lwc1  $f8, 0x44($sp)
/* 0A467C 7F06FB4C C60A0024 */  lwc1  $f10, 0x24($s0)
/* 0A4680 7F06FB50 E6080028 */  swc1  $f8, 0x28($s0)
/* 0A4684 7F06FB54 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0A4688 7F06FB58 C608000C */  lwc1  $f8, 0xc($s0)
/* 0A468C 7F06FB5C 460E5181 */  sub.s $f6, $f10, $f14
/* 0A4690 7F06FB60 E604002C */  swc1  $f4, 0x2c($s0)
/* 0A4694 7F06FB64 C6040004 */  lwc1  $f4, 4($s0)
/* 0A4698 7F06FB68 E6060034 */  swc1  $f6, 0x34($s0)
/* 0A469C 7F06FB6C 46044301 */  sub.s $f12, $f8, $f4
/* 0A46A0 7F06FB70 C622002C */  lwc1  $f2, 0x2c($s1)
/* 0A46A4 7F06FB74 44814000 */  mtc1  $at, $f8
/* 0A46A8 7F06FB78 3C018005 */  lui   $at, %hi(D_80054D44)
/* 0A46AC 7F06FB7C 460C8281 */  sub.s $f10, $f16, $f12
/* 0A46B0 7F06FB80 46024101 */  sub.s $f4, $f8, $f2
/* 0A46B4 7F06FB84 46025182 */  mul.s $f6, $f10, $f2
/* 0A46B8 7F06FB88 46043283 */  div.s $f10, $f6, $f4
/* 0A46BC 7F06FB8C C606002C */  lwc1  $f6, 0x2c($s0)
/* 0A46C0 7F06FB90 460A6201 */  sub.s $f8, $f12, $f10
/* 0A46C4 7F06FB94 C60C0014 */  lwc1  $f12, 0x14($s0)
/* 0A46C8 7F06FB98 E6080038 */  swc1  $f8, 0x38($s0)
/* 0A46CC 7F06FB9C C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0A46D0 7F06FBA0 46043281 */  sub.s $f10, $f6, $f4
/* 0A46D4 7F06FBA4 44803000 */  mtc1  $zero, $f6
/* 0A46D8 7F06FBA8 E60A003C */  swc1  $f10, 0x3c($s0)
/* 0A46DC 7F06FBAC C7A80058 */  lwc1  $f8, 0x58($sp)
/* 0A46E0 7F06FBB0 46086381 */  sub.s $f14, $f12, $f8
/* 0A46E4 7F06FBB4 4606703C */  c.lt.s $f14, $f6
/* 0A46E8 7F06FBB8 00000000 */  nop   
/* 0A46EC 7F06FBBC 45000003 */  bc1f  .L7F06FBCC
/* 0A46F0 7F06FBC0 00000000 */   nop   
/* 0A46F4 7F06FBC4 C4244D44 */  lwc1  $f4, %lo(D_80054D44)($at)
/* 0A46F8 7F06FBC8 46047380 */  add.s $f14, $f14, $f4
.L7F06FBCC:
/* 0A46FC 7F06FBCC 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A4700 7F06FBD0 8E26002C */   lw    $a2, 0x2c($s1)
/* 0A4704 7F06FBD4 44805000 */  mtc1  $zero, $f10
/* 0A4708 7F06FBD8 C6080018 */  lwc1  $f8, 0x18($s0)
/* 0A470C 7F06FBDC 3C018005 */  lui   $at, %hi(D_80054D48)
/* 0A4710 7F06FBE0 C4224D48 */  lwc1  $f2, %lo(D_80054D48)($at)
/* 0A4714 7F06FBE4 46085032 */  c.eq.s $f10, $f8
/* 0A4718 7F06FBE8 E6000030 */  swc1  $f0, 0x30($s0)
/* 0A471C 7F06FBEC C7A40058 */  lwc1  $f4, 0x58($sp)
/* 0A4720 7F06FBF0 24080001 */  li    $t0, 1
/* 0A4724 7F06FBF4 4502000B */  bc1fl .L7F06FC24
/* 0A4728 7F06FBF8 A2080001 */   sb    $t0, 1($s0)
/* 0A472C 7F06FBFC C6060030 */  lwc1  $f6, 0x30($s0)
/* 0A4730 7F06FC00 46043000 */  add.s $f0, $f6, $f4
/* 0A4734 7F06FC04 4600103E */  c.le.s $f2, $f0
/* 0A4738 7F06FC08 E6000020 */  swc1  $f0, 0x20($s0)
/* 0A473C 7F06FC0C 45020005 */  bc1fl .L7F06FC24
/* 0A4740 7F06FC10 A2080001 */   sb    $t0, 1($s0)
/* 0A4744 7F06FC14 C60A0020 */  lwc1  $f10, 0x20($s0)
/* 0A4748 7F06FC18 46025201 */  sub.s $f8, $f10, $f2
/* 0A474C 7F06FC1C E6080020 */  swc1  $f8, 0x20($s0)
/* 0A4750 7F06FC20 A2080001 */  sb    $t0, 1($s0)
.L7F06FC24:
/* 0A4754 7F06FC24 8FA9002C */  lw    $t1, 0x2c($sp)
/* 0A4758 7F06FC28 51200004 */  beql  $t1, $zero, .L7F06FC3C
/* 0A475C 7F06FC2C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A4760 7F06FC30 C6060028 */  lwc1  $f6, 0x28($s0)
/* 0A4764 7F06FC34 E6060038 */  swc1  $f6, 0x38($s0)
/* 0A4768 7F06FC38 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06FC3C:
/* 0A476C 7F06FC3C 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0A4770 7F06FC40 8FB10020 */  lw    $s1, 0x20($sp)
/* 0A4774 7F06FC44 03E00008 */  jr    $ra
/* 0A4778 7F06FC48 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif


void modelSetAnimationWithMerge(Model *model, ModelAnimation *modelAnimation, s32 flip, f32 startframe, f32 speed, f32 timemerge, s32 domerge) {
    if (domerge != 0) {
        modelCopyAnimForMerge(model, timemerge);
    }
    modelSetAnimation2(model, modelAnimation, flip, startframe, speed, timemerge);
}



void modelSetAnimation(Model *model, ModelAnimation *modelAnimation, s32 flip, f32 startframe, f32 speed, f32 merge) {
    modelCopyAnimForMerge(model, merge);
    modelSetAnimation2(model, modelAnimation, flip, startframe, speed, merge);
}


#ifdef NONMATCHING
void sub_GAME_7F06FCFC()
{

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FCFC
/* 0A482C 7F06FCFC 8CA10000 */  lw    $at, ($a1)
/* 0A4830 7F06FD00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A4834 7F06FD04 27A20000 */  addiu $v0, $sp, 0
/* 0A4838 7F06FD08 AC410000 */  sw    $at, ($v0)
/* 0A483C 7F06FD0C 8CB80004 */  lw    $t8, 4($a1)
/* 0A4840 7F06FD10 00805025 */  move  $t2, $a0
/* 0A4844 7F06FD14 00A05825 */  move  $t3, $a1
/* 0A4848 7F06FD18 AC580004 */  sw    $t8, 4($v0)
/* 0A484C 7F06FD1C 8CA10008 */  lw    $at, 8($a1)
/* 0A4850 7F06FD20 248900B4 */  addiu $t1, $a0, 0xb4
/* 0A4854 7F06FD24 AC410008 */  sw    $at, 8($v0)
/* 0A4858 7F06FD28 8CB8000C */  lw    $t8, 0xc($a1)
/* 0A485C 7F06FD2C AC58000C */  sw    $t8, 0xc($v0)
/* 0A4860 7F06FD30 8CA10010 */  lw    $at, 0x10($a1)
/* 0A4864 7F06FD34 AC410010 */  sw    $at, 0x10($v0)
/* 0A4868 7F06FD38 8CB80014 */  lw    $t8, 0x14($a1)
/* 0A486C 7F06FD3C AC580014 */  sw    $t8, 0x14($v0)
/* 0A4870 7F06FD40 8CA10018 */  lw    $at, 0x18($a1)
/* 0A4874 7F06FD44 AC410018 */  sw    $at, 0x18($v0)
/* 0A4878 7F06FD48 8CB8001C */  lw    $t8, 0x1c($a1)
/* 0A487C 7F06FD4C AC58001C */  sw    $t8, 0x1c($v0)
.L7F06FD50:
/* 0A4880 7F06FD50 8D410000 */  lw    $at, ($t2)
/* 0A4884 7F06FD54 254A000C */  addiu $t2, $t2, 0xc
/* 0A4888 7F06FD58 256B000C */  addiu $t3, $t3, 0xc
/* 0A488C 7F06FD5C AD61FFF4 */  sw    $at, -0xc($t3)
/* 0A4890 7F06FD60 8D41FFF8 */  lw    $at, -8($t2)
/* 0A4894 7F06FD64 AD61FFF8 */  sw    $at, -8($t3)
/* 0A4898 7F06FD68 8D41FFFC */  lw    $at, -4($t2)
/* 0A489C 7F06FD6C 1549FFF8 */  bne   $t2, $t1, .L7F06FD50
/* 0A48A0 7F06FD70 AD61FFFC */   sw    $at, -4($t3)
/* 0A48A4 7F06FD74 8D410000 */  lw    $at, ($t2)
/* 0A48A8 7F06FD78 AD610000 */  sw    $at, ($t3)
/* 0A48AC 7F06FD7C 8D490004 */  lw    $t1, 4($t2)
/* 0A48B0 7F06FD80 AD690004 */  sw    $t1, 4($t3)
/* 0A48B4 7F06FD84 8C410000 */  lw    $at, ($v0)
/* 0A48B8 7F06FD88 ACA10000 */  sw    $at, ($a1)
/* 0A48BC 7F06FD8C 8C4F0004 */  lw    $t7, 4($v0)
/* 0A48C0 7F06FD90 ACAF0004 */  sw    $t7, 4($a1)
/* 0A48C4 7F06FD94 8C410008 */  lw    $at, 8($v0)
/* 0A48C8 7F06FD98 ACA10008 */  sw    $at, 8($a1)
/* 0A48CC 7F06FD9C 8C4F000C */  lw    $t7, 0xc($v0)
/* 0A48D0 7F06FDA0 ACAF000C */  sw    $t7, 0xc($a1)
/* 0A48D4 7F06FDA4 8C410010 */  lw    $at, 0x10($v0)
/* 0A48D8 7F06FDA8 ACA10010 */  sw    $at, 0x10($a1)
/* 0A48DC 7F06FDAC 8C4F0014 */  lw    $t7, 0x14($v0)
/* 0A48E0 7F06FDB0 ACAF0014 */  sw    $t7, 0x14($a1)
/* 0A48E4 7F06FDB4 8C410018 */  lw    $at, 0x18($v0)
/* 0A48E8 7F06FDB8 ACA10018 */  sw    $at, 0x18($a1)
/* 0A48EC 7F06FDBC 8C4F001C */  lw    $t7, 0x1c($v0)
/* 0A48F0 7F06FDC0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A48F4 7F06FDC4 03E00008 */  jr    $ra
/* 0A48F8 7F06FDC8 ACAF001C */   sw    $t7, 0x1c($a1)
)
#endif





void modelSetAnimLooping(Model *model, f32 loopframe, f32 loopmerge) {
    model->animlooping = 1;
    model->animloopframe = loopframe;
    model->animloopmerge = loopmerge;
}


void modelSetAnimEndFrame(Model *model, f32 endframe) {
    ModelAnimation *modelAnimation = model->anim;
    
    if ((modelAnimation != NULL) && (endframe < (modelAnimation->unk04 - 1))) {
        model->endframe = endframe;
    } else {
        model->endframe = -1.0f;
    }
}

void modelSetAnimFlipFunction(Model *model, void *callback) {
    model->animflipfunc = callback;
}


/**
 * Unused Function
*/
void sub_GAME_7F06FE44(Model *model, s32 arg1) {
    model->unk9c = arg1;
}

void modelSetAnimSpeed(Model *model, f32 anim_speed, f32 startframe) {
    
    if (startframe > 0.0f) {
        model->timespeed = startframe;
        model->newspeed = anim_speed;
        model->elapsespeed = 0.0f;
        model->oldspeed = model->speed;
        return;
    }

    model->speed = anim_speed;
    model->timespeed = 0.0f;
}

/**
 * @param arg0:
 * @param arg1:
 * @param arg2: must be non-zero.
 * 
 * Address 0x7F06FE90.
*/
void sub_GAME_7F06FE90(Model *model, f32 arg1, f32 arg2)
{
    f32 temp_f0;
    f32 phi_f2;
    f32 t;

    temp_f0 = model->unk28;
    
    if (temp_f0 <= arg1)
    {
        phi_f2 = arg1 - temp_f0;
    }
    else
    {
        phi_f2 = ( (f32)model->anim->unk04 - temp_f0) + arg1;
    }
    
    t = model->speed + ((2.0f * phi_f2) / arg2);
    modelSetAnimSpeed(model, t, arg2);
}

void modelSetAnimPlaySpeed(Model *model, f32 animation_rate, f32 startframe) {
    if (startframe > 0.0f) {
        model->unkb0 = startframe;
        model->animrate = animation_rate;
        model->unkb4 = 0.0f;
        model->unkac = model->playspeed;
        return;
    }
    model->playspeed = animation_rate;
    model->unkb0 = 0.0f;
}


void sub_GAME_7F06FF5C(Model *model, s32 arg1) {
    model->unka0 = arg1;
}


void modelSetAnimFrame(Model* model, f32 frame)
{
    s32 framea;
    s32 frameb;
    bool forwards;

    framea = floorFloatToInt(frame);

    forwards = (model->speed >= 0);
    frameb = (forwards ? framea + 1 : framea - 1);

    model->framea = modelConstrainOrWrapAnimFrame(framea, model->anim, model->endframe);
    model->frameb = modelConstrainOrWrapAnimFrame(frameb, model->anim, model->endframe);

    if (model->framea == model->frameb)
    {
        model->unk2c = 0.0f;
        model->unk28 = model->framea;
    }
    else if (forwards)
    {
        f32 tmp = frame - framea;
        model->unk2c = tmp;
        model->unk28 = model->framea + tmp;
    }
    else
    {
        f32 tmp = 1.0f - (frame - (f32) frameb);
        model->unk2c = tmp;
        model->unk28 = model->frameb + (1.0f - tmp);
    }
}


void modelSetAnimFrame2(Model* model, f32 frame1, f32 frame2)
{
    s32 framea;
    s32 frameb;
    bool forwards;

    modelSetAnimFrame(model, frame1);

    if (model->anim2 != NULL)
    {
        framea = floorFloatToInt(frame2);

        forwards = (model->speed2 >= 0.0f);
        frameb = forwards ? (framea + 1) : (framea - 1);

        model->frame2a = modelConstrainOrWrapAnimFrame(framea, model->anim2, model->unk6c);
        model->frame2b = modelConstrainOrWrapAnimFrame(frameb, model->anim2, model->unk6c);

        if (model->frame2a == model->frame2b)
        {
            model->unk5c = 0.0f;
            model->unk58 = model->frame2a;
        }
        else if (forwards != 0)
        {
            f32 tmp = frame2 - framea;
            model->unk5c = tmp;
            model->unk58 = model->frame2a + tmp;
        }
        else
        {
            f32 tmp = 1.0f - (frame2 - (f32) frameb);
            model->unk5c = tmp;
            model->unk58 = model->frame2b + (1.0f - tmp);
        }
    }
}


/**
 * Address 0x7F0701D4.
*/
void modelSetAnimMergingEnabled(s32 arg0)
{
    g_ModelAnimMergingEnabled = arg0;
}


/**
 * Address 0x7F0701E0.
*/
u32 modelIsAnimMergingEnabled(void)
{
    return g_ModelAnimMergingEnabled;
}




#ifdef NONMATCHING
void modelSetAnimFrame2WithChrStuff(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054D4C
.word 0x40c90fdb /*6.2831855*/
.text
glabel modelSetAnimFrame2WithChrStuff
/* 0A4D1C 7F0701EC 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0A4D20 7F0701F0 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0A4D24 7F0701F4 AFB30058 */  sw    $s3, 0x58($sp)
/* 0A4D28 7F0701F8 AFB20054 */  sw    $s2, 0x54($sp)
/* 0A4D2C 7F0701FC AFB10050 */  sw    $s1, 0x50($sp)
/* 0A4D30 7F070200 AFB0004C */  sw    $s0, 0x4c($sp)
/* 0A4D34 7F070204 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0A4D38 7F070208 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0A4D3C 7F07020C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0A4D40 7F070210 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0A4D44 7F070214 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0A4D48 7F070218 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0A4D4C 7F07021C AFA60100 */  sw    $a2, 0x100($sp)
/* 0A4D50 7F070220 AFA70104 */  sw    $a3, 0x104($sp)
/* 0A4D54 7F070224 8C8E0008 */  lw    $t6, 8($a0)
/* 0A4D58 7F070228 4485A000 */  mtc1  $a1, $f20
/* 0A4D5C 7F07022C 24010001 */  li    $at, 1
/* 0A4D60 7F070230 8DC50000 */  lw    $a1, ($t6)
/* 0A4D64 7F070234 00808825 */  move  $s1, $a0
/* 0A4D68 7F070238 94A20000 */  lhu   $v0, ($a1)
/* 0A4D6C 7F07023C 304F00FF */  andi  $t7, $v0, 0xff
/* 0A4D70 7F070240 55E10218 */  bnel  $t7, $at, .L7F070AA4
/* 0A4D74 7F070244 C7B40108 */   lwc1  $f20, 0x108($sp)
/* 0A4D78 7F070248 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0A4D7C 7F07024C 8CB20004 */   lw    $s2, 4($a1)
/* 0A4D80 7F070250 80580000 */  lb    $t8, ($v0)
/* 0A4D84 7F070254 00408025 */  move  $s0, $v0
/* 0A4D88 7F070258 5700020A */  bnezl $t8, .L7F070A84
/* 0A4D8C 7F07025C C7B40108 */   lwc1  $f20, 0x108($sp)
/* 0A4D90 7F070260 96590000 */  lhu   $t9, ($s2)
/* 0A4D94 7F070264 3C0B8003 */  lui   $t3, %hi(D_80036254) 
/* 0A4D98 7F070268 256B6254 */  addiu $t3, %lo(D_80036254) # addiu $t3, $t3, 0x6254
/* 0A4D9C 7F07026C AFB900E4 */  sw    $t9, 0xe4($sp)
/* 0A4DA0 7F070270 8E280008 */  lw    $t0, 8($s1)
/* 0A4DA4 7F070274 27AA00C8 */  addiu $t2, $sp, 0xc8
/* 0A4DA8 7F070278 4480C000 */  mtc1  $zero, $f24
/* 0A4DAC 7F07027C 8D090004 */  lw    $t1, 4($t0)
/* 0A4DB0 7F070280 AFA900E0 */  sw    $t1, 0xe0($sp)
/* 0A4DB4 7F070284 C62600B8 */  lwc1  $f6, 0xb8($s1)
/* 0A4DB8 7F070288 C6240014 */  lwc1  $f4, 0x14($s1)
/* 0A4DBC 7F07028C 46062202 */  mul.s $f8, $f4, $f6
/* 0A4DC0 7F070290 E7A800DC */  swc1  $f8, 0xdc($sp)
/* 0A4DC4 7F070294 8D610000 */  lw    $at, ($t3)
/* 0A4DC8 7F070298 8D6E0004 */  lw    $t6, 4($t3)
/* 0A4DCC 7F07029C AD410000 */  sw    $at, ($t2)
/* 0A4DD0 7F0702A0 8D610008 */  lw    $at, 8($t3)
/* 0A4DD4 7F0702A4 AD4E0004 */  sw    $t6, 4($t2)
/* 0A4DD8 7F0702A8 AD410008 */  sw    $at, 8($t2)
/* 0A4DDC 7F0702AC C44A0034 */  lwc1  $f10, 0x34($v0)
/* 0A4DE0 7F0702B0 E7AA00AC */  swc1  $f10, 0xac($sp)
/* 0A4DE4 7F0702B4 C4500038 */  lwc1  $f16, 0x38($v0)
/* 0A4DE8 7F0702B8 E7B000B0 */  swc1  $f16, 0xb0($sp)
/* 0A4DEC 7F0702BC C452003C */  lwc1  $f18, 0x3c($v0)
/* 0A4DF0 7F0702C0 C7B00100 */  lwc1  $f16, 0x100($sp)
/* 0A4DF4 7F0702C4 E7B200B4 */  swc1  $f18, 0xb4($sp)
/* 0A4DF8 7F0702C8 C4440024 */  lwc1  $f4, 0x24($v0)
/* 0A4DFC 7F0702CC C45C0030 */  lwc1  $f28, 0x30($v0)
/* 0A4E00 7F0702D0 E7A4009C */  swc1  $f4, 0x9c($sp)
/* 0A4E04 7F0702D4 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0A4E08 7F0702D8 E7A600A0 */  swc1  $f6, 0xa0($sp)
/* 0A4E0C 7F0702DC C448002C */  lwc1  $f8, 0x2c($v0)
/* 0A4E10 7F0702E0 E7A800A4 */  swc1  $f8, 0xa4($sp)
/* 0A4E14 7F0702E4 C44A0020 */  lwc1  $f10, 0x20($v0)
/* 0A4E18 7F0702E8 E7AA0098 */  swc1  $f10, 0x98($sp)
/* 0A4E1C 7F0702EC 804F0001 */  lb    $t7, 1($v0)
/* 0A4E20 7F0702F0 AFAF0094 */  sw    $t7, 0x94($sp)
/* 0A4E24 7F0702F4 C63E0040 */  lwc1  $f30, 0x40($s1)
/* 0A4E28 7F0702F8 4618F03C */  c.lt.s $f30, $f24
/* 0A4E2C 7F0702FC 00000000 */  nop   
/* 0A4E30 7F070300 45020003 */  bc1fl .L7F070310
/* 0A4E34 7F070304 C6200070 */   lwc1  $f0, 0x70($s1)
/* 0A4E38 7F070308 4600F787 */  neg.s $f30, $f30
/* 0A4E3C 7F07030C C6200070 */  lwc1  $f0, 0x70($s1)
.L7F070310:
/* 0A4E40 7F070310 4618003C */  c.lt.s $f0, $f24
/* 0A4E44 7F070314 00000000 */  nop   
/* 0A4E48 7F070318 45020003 */  bc1fl .L7F070328
/* 0A4E4C 7F07031C 4610A03E */   c.le.s $f20, $f16
/* 0A4E50 7F070320 46000007 */  neg.s $f0, $f0
/* 0A4E54 7F070324 4610A03E */  c.le.s $f20, $f16
.L7F070328:
/* 0A4E58 7F070328 00009825 */  move  $s3, $zero
/* 0A4E5C 7F07032C 45000002 */  bc1f  .L7F070338
/* 0A4E60 7F070330 00000000 */   nop   
/* 0A4E64 7F070334 24130001 */  li    $s3, 1
.L7F070338:
/* 0A4E68 7F070338 5260000A */  beql  $s3, $zero, .L7F070364
/* 0A4E6C 7F07033C 4600A306 */   mov.s $f12, $f20
/* 0A4E70 7F070340 4600A306 */  mov.s $f12, $f20
/* 0A4E74 7F070344 0FC170F6 */  jal   floorFloatToInt
/* 0A4E78 7F070348 E7A00088 */   swc1  $f0, 0x88($sp)
/* 0A4E7C 7F07034C 24520001 */  addiu $s2, $v0, 1
/* 0A4E80 7F070350 0FC170F6 */  jal   floorFloatToInt
/* 0A4E84 7F070354 C7AC0100 */   lwc1  $f12, 0x100($sp)
/* 0A4E88 7F070358 10000008 */  b     .L7F07037C
/* 0A4E8C 7F07035C AFA200B8 */   sw    $v0, 0xb8($sp)
/* 0A4E90 7F070360 4600A306 */  mov.s $f12, $f20
.L7F070364:
/* 0A4E94 7F070364 0FC1712E */  jal   ceilFloatToInt
/* 0A4E98 7F070368 E7A00088 */   swc1  $f0, 0x88($sp)
/* 0A4E9C 7F07036C 2452FFFF */  addiu $s2, $v0, -1
/* 0A4EA0 7F070370 0FC1712E */  jal   ceilFloatToInt
/* 0A4EA4 7F070374 C7AC0100 */   lwc1  $f12, 0x100($sp)
/* 0A4EA8 7F070378 AFA200B8 */  sw    $v0, 0xb8($sp)
.L7F07037C:
/* 0A4EAC 7F07037C 3C018005 */  lui   $at, %hi(D_80054D4C)
/* 0A4EB0 7F070380 8FA700B8 */  lw    $a3, 0xb8($sp)
/* 0A4EB4 7F070384 C43A4D4C */  lwc1  $f26, %lo(D_80054D4C)($at)
.L7F070388:
/* 0A4EB8 7F070388 12600006 */  beqz  $s3, .L7F0703A4
/* 0A4EBC 7F07038C 0247082A */   slt   $at, $s2, $a3
/* 0A4EC0 7F070390 00F2082A */  slt   $at, $a3, $s2
/* 0A4EC4 7F070394 50200006 */  beql  $at, $zero, .L7F0703B0
/* 0A4EC8 7F070398 8E250020 */   lw    $a1, 0x20($s1)
/* 0A4ECC 7F07039C 10000130 */  b     .L7F070860
/* 0A4ED0 7F0703A0 C7A600AC */   lwc1  $f6, 0xac($sp)
.L7F0703A4:
/* 0A4ED4 7F0703A4 5420012E */  bnezl $at, .L7F070860
/* 0A4ED8 7F0703A8 C7A600AC */   lwc1  $f6, 0xac($sp)
/* 0A4EDC 7F0703AC 8E250020 */  lw    $a1, 0x20($s1)
.L7F0703B0:
/* 0A4EE0 7F0703B0 8E26003C */  lw    $a2, 0x3c($s1)
/* 0A4EE4 7F0703B4 AFA700B8 */  sw    $a3, 0xb8($sp)
/* 0A4EE8 7F0703B8 0FC1BD9B */  jal   modelConstrainOrWrapAnimFrame
/* 0A4EEC 7F0703BC 02402025 */   move  $a0, $s2
/* 0A4EF0 7F0703C0 A6220030 */  sh    $v0, 0x30($s1)
/* 0A4EF4 7F0703C4 8FB80094 */  lw    $t8, 0x94($sp)
/* 0A4EF8 7F0703C8 00401825 */  move  $v1, $v0
/* 0A4EFC 7F0703CC 8FA600E0 */  lw    $a2, 0xe0($sp)
/* 0A4F00 7F0703D0 1300000E */  beqz  $t8, .L7F07040C
/* 0A4F04 7F0703D4 8FA400E4 */   lw    $a0, 0xe4($sp)
/* 0A4F08 7F0703D8 C7B2009C */  lwc1  $f18, 0x9c($sp)
/* 0A4F0C 7F0703DC C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0A4F10 7F0703E0 C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 0A4F14 7F0703E4 E7B200AC */  swc1  $f18, 0xac($sp)
/* 0A4F18 7F0703E8 E7A400B0 */  swc1  $f4, 0xb0($sp)
/* 0A4F1C 7F0703EC E7A600B4 */  swc1  $f6, 0xb4($sp)
/* 0A4F20 7F0703F0 C6080018 */  lwc1  $f8, 0x18($s0)
/* 0A4F24 7F0703F4 4608C032 */  c.eq.s $f24, $f8
/* 0A4F28 7F0703F8 00000000 */  nop   
/* 0A4F2C 7F0703FC 45000046 */  bc1f  .L7F070518
/* 0A4F30 7F070400 00000000 */   nop   
/* 0A4F34 7F070404 10000044 */  b     .L7F070518
/* 0A4F38 7F070408 C7BC0098 */   lwc1  $f28, 0x98($sp)
.L7F07040C:
/* 0A4F3C 7F07040C 82250024 */  lb    $a1, 0x24($s1)
/* 0A4F40 7F070410 8E270020 */  lw    $a3, 0x20($s1)
/* 0A4F44 7F070414 27B900C8 */  addiu $t9, $sp, 0xc8
/* 0A4F48 7F070418 AFB90014 */  sw    $t9, 0x14($sp)
/* 0A4F4C 7F07041C 0FC1B4FD */  jal   sub_GAME_7F06D3F4
/* 0A4F50 7F070420 AFA30010 */   sw    $v1, 0x10($sp)
/* 0A4F54 7F070424 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A4F58 7F070428 44818000 */  mtc1  $at, $f16
/* 0A4F5C 7F07042C C7AA00DC */  lwc1  $f10, 0xdc($sp)
/* 0A4F60 7F070430 46000586 */  mov.s $f22, $f0
/* 0A4F64 7F070434 C7A200C8 */  lwc1  $f2, 0xc8($sp)
/* 0A4F68 7F070438 46105032 */  c.eq.s $f10, $f16
/* 0A4F6C 7F07043C C7B200CC */  lwc1  $f18, 0xcc($sp)
/* 0A4F70 7F070440 4503000A */  bc1tl .L7F07046C
/* 0A4F74 7F070444 C7A200C8 */   lwc1  $f2, 0xc8($sp)
/* 0A4F78 7F070448 460A1082 */  mul.s $f2, $f2, $f10
/* 0A4F7C 7F07044C C7AC00D0 */  lwc1  $f12, 0xd0($sp)
/* 0A4F80 7F070450 460A9102 */  mul.s $f4, $f18, $f10
/* 0A4F84 7F070454 00000000 */  nop   
/* 0A4F88 7F070458 460A6302 */  mul.s $f12, $f12, $f10
/* 0A4F8C 7F07045C E7A200C8 */  swc1  $f2, 0xc8($sp)
/* 0A4F90 7F070460 E7A400CC */  swc1  $f4, 0xcc($sp)
/* 0A4F94 7F070464 E7AC00D0 */  swc1  $f12, 0xd0($sp)
/* 0A4F98 7F070468 C7A200C8 */  lwc1  $f2, 0xc8($sp)
.L7F07046C:
/* 0A4F9C 7F07046C 16600008 */  bnez  $s3, .L7F070490
/* 0A4FA0 7F070470 C7AC00D0 */   lwc1  $f12, 0xd0($sp)
/* 0A4FA4 7F070474 4600C03C */  c.lt.s $f24, $f0
/* 0A4FA8 7F070478 46001087 */  neg.s $f2, $f2
/* 0A4FAC 7F07047C 46006307 */  neg.s $f12, $f12
/* 0A4FB0 7F070480 E7A200C8 */  swc1  $f2, 0xc8($sp)
/* 0A4FB4 7F070484 45000002 */  bc1f  .L7F070490
/* 0A4FB8 7F070488 E7AC00D0 */   swc1  $f12, 0xd0($sp)
/* 0A4FBC 7F07048C 4600D581 */  sub.s $f22, $f26, $f0
.L7F070490:
/* 0A4FC0 7F070490 0FC15FA8 */  jal   cosf
/* 0A4FC4 7F070494 C60C0014 */   lwc1  $f12, 0x14($s0)
/* 0A4FC8 7F070498 46000506 */  mov.s $f20, $f0
/* 0A4FCC 7F07049C 0FC15FAB */  jal   sinf
/* 0A4FD0 7F0704A0 C60C0014 */   lwc1  $f12, 0x14($s0)
/* 0A4FD4 7F0704A4 C7A600C8 */  lwc1  $f6, 0xc8($sp)
/* 0A4FD8 7F0704A8 C7B000D0 */  lwc1  $f16, 0xd0($sp)
/* 0A4FDC 7F0704AC C7AA00AC */  lwc1  $f10, 0xac($sp)
/* 0A4FE0 7F0704B0 46143202 */  mul.s $f8, $f6, $f20
/* 0A4FE4 7F0704B4 00000000 */  nop   
/* 0A4FE8 7F0704B8 46008482 */  mul.s $f18, $f16, $f0
/* 0A4FEC 7F0704BC 46124100 */  add.s $f4, $f8, $f18
/* 0A4FF0 7F0704C0 C7B200CC */  lwc1  $f18, 0xcc($sp)
/* 0A4FF4 7F0704C4 46045200 */  add.s $f8, $f10, $f4
/* 0A4FF8 7F0704C8 E7B200B0 */  swc1  $f18, 0xb0($sp)
/* 0A4FFC 7F0704CC 46003287 */  neg.s $f10, $f6
/* 0A5000 7F0704D0 E7A800AC */  swc1  $f8, 0xac($sp)
/* 0A5004 7F0704D4 46005102 */  mul.s $f4, $f10, $f0
/* 0A5008 7F0704D8 C7A600B4 */  lwc1  $f6, 0xb4($sp)
/* 0A500C 7F0704DC 46148202 */  mul.s $f8, $f16, $f20
/* 0A5010 7F0704E0 46082480 */  add.s $f18, $f4, $f8
/* 0A5014 7F0704E4 46123280 */  add.s $f10, $f6, $f18
/* 0A5018 7F0704E8 E7AA00B4 */  swc1  $f10, 0xb4($sp)
/* 0A501C 7F0704EC C6100018 */  lwc1  $f16, 0x18($s0)
/* 0A5020 7F0704F0 4610C032 */  c.eq.s $f24, $f16
/* 0A5024 7F0704F4 00000000 */  nop   
/* 0A5028 7F0704F8 45000007 */  bc1f  .L7F070518
/* 0A502C 7F0704FC 00000000 */   nop   
/* 0A5030 7F070500 4616E700 */  add.s $f28, $f28, $f22
/* 0A5034 7F070504 461CD03E */  c.le.s $f26, $f28
/* 0A5038 7F070508 00000000 */  nop   
/* 0A503C 7F07050C 45000002 */  bc1f  .L7F070518
/* 0A5040 7F070510 00000000 */   nop   
/* 0A5044 7F070514 461AE701 */  sub.s $f28, $f28, $f26
.L7F070518:
/* 0A5048 7F070518 52600004 */  beql  $s3, $zero, .L7F07052C
/* 0A504C 7F07051C 2652FFFF */   addiu $s2, $s2, -1
/* 0A5050 7F070520 10000002 */  b     .L7F07052C
/* 0A5054 7F070524 26520001 */   addiu $s2, $s2, 1
/* 0A5058 7F070528 2652FFFF */  addiu $s2, $s2, -1
.L7F07052C:
/* 0A505C 7F07052C 02402025 */  move  $a0, $s2
/* 0A5060 7F070530 8E250020 */  lw    $a1, 0x20($s1)
/* 0A5064 7F070534 0FC1BD9B */  jal   modelConstrainOrWrapAnimFrame
/* 0A5068 7F070538 8E26003C */   lw    $a2, 0x3c($s1)
/* 0A506C 7F07053C A6220032 */  sh    $v0, 0x32($s1)
/* 0A5070 7F070540 86290032 */  lh    $t1, 0x32($s1)
/* 0A5074 7F070544 86280030 */  lh    $t0, 0x30($s1)
/* 0A5078 7F070548 8FA600E0 */  lw    $a2, 0xe0($sp)
/* 0A507C 7F07054C 8FA400E4 */  lw    $a0, 0xe4($sp)
/* 0A5080 7F070550 110900C0 */  beq   $t0, $t1, .L7F070854
/* 0A5084 7F070554 27AD00C8 */   addiu $t5, $sp, 0xc8
/* 0A5088 7F070558 82250024 */  lb    $a1, 0x24($s1)
/* 0A508C 7F07055C 8E270020 */  lw    $a3, 0x20($s1)
/* 0A5090 7F070560 240C0001 */  li    $t4, 1
/* 0A5094 7F070564 AFAC0094 */  sw    $t4, 0x94($sp)
/* 0A5098 7F070568 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0A509C 7F07056C 0FC1B4FD */  jal   sub_GAME_7F06D3F4
/* 0A50A0 7F070570 AFA20010 */   sw    $v0, 0x10($sp)
/* 0A50A4 7F070574 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A50A8 7F070578 44814000 */  mtc1  $at, $f8
/* 0A50AC 7F07057C C7A400DC */  lwc1  $f4, 0xdc($sp)
/* 0A50B0 7F070580 46000586 */  mov.s $f22, $f0
/* 0A50B4 7F070584 C7A200C8 */  lwc1  $f2, 0xc8($sp)
/* 0A50B8 7F070588 46082032 */  c.eq.s $f4, $f8
/* 0A50BC 7F07058C C7A600CC */  lwc1  $f6, 0xcc($sp)
/* 0A50C0 7F070590 4503000A */  bc1tl .L7F0705BC
/* 0A50C4 7F070594 C7A200C8 */   lwc1  $f2, 0xc8($sp)
/* 0A50C8 7F070598 46041082 */  mul.s $f2, $f2, $f4
/* 0A50CC 7F07059C C7AC00D0 */  lwc1  $f12, 0xd0($sp)
/* 0A50D0 7F0705A0 46043482 */  mul.s $f18, $f6, $f4
/* 0A50D4 7F0705A4 00000000 */  nop   
/* 0A50D8 7F0705A8 46046302 */  mul.s $f12, $f12, $f4
/* 0A50DC 7F0705AC E7A200C8 */  swc1  $f2, 0xc8($sp)
/* 0A50E0 7F0705B0 E7B200CC */  swc1  $f18, 0xcc($sp)
/* 0A50E4 7F0705B4 E7AC00D0 */  swc1  $f12, 0xd0($sp)
/* 0A50E8 7F0705B8 C7A200C8 */  lwc1  $f2, 0xc8($sp)
.L7F0705BC:
/* 0A50EC 7F0705BC 16600008 */  bnez  $s3, .L7F0705E0
/* 0A50F0 7F0705C0 C7AC00D0 */   lwc1  $f12, 0xd0($sp)
/* 0A50F4 7F0705C4 4600C03C */  c.lt.s $f24, $f0
/* 0A50F8 7F0705C8 46001087 */  neg.s $f2, $f2
/* 0A50FC 7F0705CC 46006307 */  neg.s $f12, $f12
/* 0A5100 7F0705D0 E7A200C8 */  swc1  $f2, 0xc8($sp)
/* 0A5104 7F0705D4 45000002 */  bc1f  .L7F0705E0
/* 0A5108 7F0705D8 E7AC00D0 */   swc1  $f12, 0xd0($sp)
/* 0A510C 7F0705DC 4600D581 */  sub.s $f22, $f26, $f0
.L7F0705E0:
/* 0A5110 7F0705E0 0FC15FA8 */  jal   cosf
/* 0A5114 7F0705E4 C60C0030 */   lwc1  $f12, 0x30($s0)
/* 0A5118 7F0705E8 46000506 */  mov.s $f20, $f0
/* 0A511C 7F0705EC 0FC15FAB */  jal   sinf
/* 0A5120 7F0705F0 C60C0030 */   lwc1  $f12, 0x30($s0)
/* 0A5124 7F0705F4 3C0A8003 */  lui   $t2, %hi(g_ModelAnimMergingEnabled) 
/* 0A5128 7F0705F8 8D4A6250 */  lw    $t2, %lo(g_ModelAnimMergingEnabled)($t2)
/* 0A512C 7F0705FC C7A200C8 */  lwc1  $f2, 0xc8($sp)
/* 0A5130 7F070600 C7AC00D0 */  lwc1  $f12, 0xd0($sp)
/* 0A5134 7F070604 11400056 */  beqz  $t2, .L7F070760
/* 0A5138 7F070608 00000000 */   nop   
/* 0A513C 7F07060C 8E2B0054 */  lw    $t3, 0x54($s1)
/* 0A5140 7F070610 11600053 */  beqz  $t3, .L7F070760
/* 0A5144 7F070614 00000000 */   nop   
/* 0A5148 7F070618 C7AC00D0 */  lwc1  $f12, 0xd0($sp)
/* 0A514C 7F07061C C7A200C8 */  lwc1  $f2, 0xc8($sp)
/* 0A5150 7F070620 461EC03C */  c.lt.s $f24, $f30
/* 0A5154 7F070624 46006282 */  mul.s $f10, $f12, $f0
/* 0A5158 7F070628 46001187 */  neg.s $f6, $f2
/* 0A515C 7F07062C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A5160 7F070630 46141402 */  mul.s $f16, $f2, $f20
/* 0A5164 7F070634 00000000 */  nop   
/* 0A5168 7F070638 46146102 */  mul.s $f4, $f12, $f20
/* 0A516C 7F07063C 00000000 */  nop   
/* 0A5170 7F070640 46003482 */  mul.s $f18, $f6, $f0
/* 0A5174 7F070644 46105200 */  add.s $f8, $f10, $f16
/* 0A5178 7F070648 E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0A517C 7F07064C 46122280 */  add.s $f10, $f4, $f18
/* 0A5180 7F070650 45000028 */  bc1f  .L7F0706F4
/* 0A5184 7F070654 E7AA00A4 */   swc1  $f10, 0xa4($sp)
/* 0A5188 7F070658 C6280088 */  lwc1  $f8, 0x88($s1)
/* 0A518C 7F07065C C63000A4 */  lwc1  $f16, 0xa4($s1)
/* 0A5190 7F070660 C6220084 */  lwc1  $f2, 0x84($s1)
/* 0A5194 7F070664 4608F182 */  mul.s $f6, $f30, $f8
/* 0A5198 7F070668 46068103 */  div.s $f4, $f16, $f6
/* 0A519C 7F07066C 46041001 */  sub.s $f0, $f2, $f4
/* 0A51A0 7F070670 4618003C */  c.lt.s $f0, $f24
/* 0A51A4 7F070674 00000000 */  nop   
/* 0A51A8 7F070678 45020003 */  bc1fl .L7F070688
/* 0A51AC 7F07067C 46001480 */   add.s $f18, $f2, $f0
/* 0A51B0 7F070680 4600C006 */  mov.s $f0, $f24
/* 0A51B4 7F070684 46001480 */  add.s $f18, $f2, $f0
.L7F070688:
/* 0A51B8 7F070688 C6080040 */  lwc1  $f8, 0x40($s0)
/* 0A51BC 7F07068C C610004C */  lwc1  $f16, 0x4c($s0)
/* 0A51C0 7F070690 44815000 */  mtc1  $at, $f10
/* 0A51C4 7F070694 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0A51C8 7F070698 46104181 */  sub.s $f6, $f8, $f16
/* 0A51CC 7F07069C 460A9002 */  mul.s $f0, $f18, $f10
/* 0A51D0 7F0706A0 00000000 */  nop   
/* 0A51D4 7F0706A4 46043482 */  mul.s $f18, $f6, $f4
/* 0A51D8 7F0706A8 461E9283 */  div.s $f10, $f18, $f30
/* 0A51DC 7F0706AC E7AA007C */  swc1  $f10, 0x7c($sp)
/* 0A51E0 7F0706B0 C6100054 */  lwc1  $f16, 0x54($s0)
/* 0A51E4 7F0706B4 C6080048 */  lwc1  $f8, 0x48($s0)
/* 0A51E8 7F0706B8 46104181 */  sub.s $f6, $f8, $f16
/* 0A51EC 7F0706BC C7B0009C */  lwc1  $f16, 0x9c($sp)
/* 0A51F0 7F0706C0 46043482 */  mul.s $f18, $f6, $f4
/* 0A51F4 7F0706C4 46105181 */  sub.s $f6, $f10, $f16
/* 0A51F8 7F0706C8 C7AA00A4 */  lwc1  $f10, 0xa4($sp)
/* 0A51FC 7F0706CC 46003102 */  mul.s $f4, $f6, $f0
/* 0A5200 7F0706D0 461E9203 */  div.s $f8, $f18, $f30
/* 0A5204 7F0706D4 46048480 */  add.s $f18, $f16, $f4
/* 0A5208 7F0706D8 E7B2009C */  swc1  $f18, 0x9c($sp)
/* 0A520C 7F0706DC 460A4181 */  sub.s $f6, $f8, $f10
/* 0A5210 7F0706E0 E7A80084 */  swc1  $f8, 0x84($sp)
/* 0A5214 7F0706E4 46003402 */  mul.s $f16, $f6, $f0
/* 0A5218 7F0706E8 46105100 */  add.s $f4, $f10, $f16
/* 0A521C 7F0706EC 10000011 */  b     .L7F070734
/* 0A5220 7F0706F0 E7A400A4 */   swc1  $f4, 0xa4($sp)
.L7F0706F4:
/* 0A5224 7F0706F4 C6120040 */  lwc1  $f18, 0x40($s0)
/* 0A5228 7F0706F8 C608004C */  lwc1  $f8, 0x4c($s0)
/* 0A522C 7F0706FC C62A0084 */  lwc1  $f10, 0x84($s1)
/* 0A5230 7F070700 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0A5234 7F070704 46089181 */  sub.s $f6, $f18, $f8
/* 0A5238 7F070708 460A3402 */  mul.s $f16, $f6, $f10
/* 0A523C 7F07070C 46102480 */  add.s $f18, $f4, $f16
/* 0A5240 7F070710 E7B2009C */  swc1  $f18, 0x9c($sp)
/* 0A5244 7F070714 C6060054 */  lwc1  $f6, 0x54($s0)
/* 0A5248 7F070718 C6080048 */  lwc1  $f8, 0x48($s0)
/* 0A524C 7F07071C C6240084 */  lwc1  $f4, 0x84($s1)
/* 0A5250 7F070720 C7B200A4 */  lwc1  $f18, 0xa4($sp)
/* 0A5254 7F070724 46064281 */  sub.s $f10, $f8, $f6
/* 0A5258 7F070728 46045402 */  mul.s $f16, $f10, $f4
/* 0A525C 7F07072C 46109200 */  add.s $f8, $f18, $f16
/* 0A5260 7F070730 E7A800A4 */  swc1  $f8, 0xa4($sp)
.L7F070734:
/* 0A5264 7F070734 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0A5268 7F070738 C7AA00AC */  lwc1  $f10, 0xac($sp)
/* 0A526C 7F07073C C7B200A4 */  lwc1  $f18, 0xa4($sp)
/* 0A5270 7F070740 C7B000B4 */  lwc1  $f16, 0xb4($sp)
/* 0A5274 7F070744 460A3100 */  add.s $f4, $f6, $f10
/* 0A5278 7F070748 C7A600CC */  lwc1  $f6, 0xcc($sp)
/* 0A527C 7F07074C 46109200 */  add.s $f8, $f18, $f16
/* 0A5280 7F070750 E7A4009C */  swc1  $f4, 0x9c($sp)
/* 0A5284 7F070754 E7A600A0 */  swc1  $f6, 0xa0($sp)
/* 0A5288 7F070758 1000000F */  b     .L7F070798
/* 0A528C 7F07075C E7A800A4 */   swc1  $f8, 0xa4($sp)
.L7F070760:
/* 0A5290 7F070760 46141102 */  mul.s $f4, $f2, $f20
/* 0A5294 7F070764 C7AA00AC */  lwc1  $f10, 0xac($sp)
/* 0A5298 7F070768 C7A600CC */  lwc1  $f6, 0xcc($sp)
/* 0A529C 7F07076C 46006402 */  mul.s $f16, $f12, $f0
/* 0A52A0 7F070770 E7A600A0 */  swc1  $f6, 0xa0($sp)
/* 0A52A4 7F070774 46045480 */  add.s $f18, $f10, $f4
/* 0A52A8 7F070778 46001102 */  mul.s $f4, $f2, $f0
/* 0A52AC 7F07077C C7AA00B4 */  lwc1  $f10, 0xb4($sp)
/* 0A52B0 7F070780 46128200 */  add.s $f8, $f16, $f18
/* 0A52B4 7F070784 46146482 */  mul.s $f18, $f12, $f20
/* 0A52B8 7F070788 46045401 */  sub.s $f16, $f10, $f4
/* 0A52BC 7F07078C E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0A52C0 7F070790 46109200 */  add.s $f8, $f18, $f16
/* 0A52C4 7F070794 E7A800A4 */  swc1  $f8, 0xa4($sp)
.L7F070798:
/* 0A52C8 7F070798 C600005C */  lwc1  $f0, 0x5c($s0)
/* 0A52CC 7F07079C 4600C03C */  c.lt.s $f24, $f0
/* 0A52D0 7F0707A0 00000000 */  nop   
/* 0A52D4 7F0707A4 45020020 */  bc1fl .L7F070828
/* 0A52D8 7F0707A8 C6100018 */   lwc1  $f16, 0x18($s0)
/* 0A52DC 7F0707AC 461EC03C */  c.lt.s $f24, $f30
/* 0A52E0 7F0707B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A52E4 7F0707B4 4502001C */  bc1fl .L7F070828
/* 0A52E8 7F0707B8 C6100018 */   lwc1  $f16, 0x18($s0)
/* 0A52EC 7F0707BC 44813000 */  mtc1  $at, $f6
/* 0A52F0 7F0707C0 00000000 */  nop   
/* 0A52F4 7F0707C4 461E3083 */  div.s $f2, $f6, $f30
/* 0A52F8 7F0707C8 4602003C */  c.lt.s $f0, $f2
/* 0A52FC 7F0707CC 46001306 */  mov.s $f12, $f2
/* 0A5300 7F0707D0 45020005 */  bc1fl .L7F0707E8
/* 0A5304 7F0707D4 46020281 */   sub.s $f10, $f0, $f2
/* 0A5308 7F0707D8 46000306 */  mov.s $f12, $f0
/* 0A530C 7F0707DC 10000003 */  b     .L7F0707EC
/* 0A5310 7F0707E0 E618005C */   swc1  $f24, 0x5c($s0)
/* 0A5314 7F0707E4 46020281 */  sub.s $f10, $f0, $f2
.L7F0707E8:
/* 0A5318 7F0707E8 E60A005C */  swc1  $f10, 0x5c($s0)
.L7F0707EC:
/* 0A531C 7F0707EC C6040058 */  lwc1  $f4, 0x58($s0)
/* 0A5320 7F0707F0 460C2482 */  mul.s $f18, $f4, $f12
/* 0A5324 7F0707F4 4612B580 */  add.s $f22, $f22, $f18
/* 0A5328 7F0707F8 4618B03C */  c.lt.s $f22, $f24
/* 0A532C 7F0707FC 00000000 */  nop   
/* 0A5330 7F070800 45020004 */  bc1fl .L7F070814
/* 0A5334 7F070804 4616D03E */   c.le.s $f26, $f22
/* 0A5338 7F070808 10000006 */  b     .L7F070824
/* 0A533C 7F07080C 461AB580 */   add.s $f22, $f22, $f26
/* 0A5340 7F070810 4616D03E */  c.le.s $f26, $f22
.L7F070814:
/* 0A5344 7F070814 00000000 */  nop   
/* 0A5348 7F070818 45020003 */  bc1fl .L7F070828
/* 0A534C 7F07081C C6100018 */   lwc1  $f16, 0x18($s0)
/* 0A5350 7F070820 461AB581 */  sub.s $f22, $f22, $f26
.L7F070824:
/* 0A5354 7F070824 C6100018 */  lwc1  $f16, 0x18($s0)
.L7F070828:
/* 0A5358 7F070828 4610C032 */  c.eq.s $f24, $f16
/* 0A535C 7F07082C 00000000 */  nop   
/* 0A5360 7F070830 45000008 */  bc1f  .L7F070854
/* 0A5364 7F070834 00000000 */   nop   
/* 0A5368 7F070838 4616E000 */  add.s $f0, $f28, $f22
/* 0A536C 7F07083C 4600D03E */  c.le.s $f26, $f0
/* 0A5370 7F070840 E7A00098 */  swc1  $f0, 0x98($sp)
/* 0A5374 7F070844 45000003 */  bc1f  .L7F070854
/* 0A5378 7F070848 00000000 */   nop   
/* 0A537C 7F07084C 461A0201 */  sub.s $f8, $f0, $f26
/* 0A5380 7F070850 E7A80098 */  swc1  $f8, 0x98($sp)
.L7F070854:
/* 0A5384 7F070854 1000FECC */  b     .L7F070388
/* 0A5388 7F070858 8FA700B8 */   lw    $a3, 0xb8($sp)
/* 0A538C 7F07085C C7A600AC */  lwc1  $f6, 0xac($sp)
.L7F070860:
/* 0A5390 7F070860 E6060034 */  swc1  $f6, 0x34($s0)
/* 0A5394 7F070864 C7AA00B0 */  lwc1  $f10, 0xb0($sp)
/* 0A5398 7F070868 E60A0038 */  swc1  $f10, 0x38($s0)
/* 0A539C 7F07086C C7A400B4 */  lwc1  $f4, 0xb4($sp)
/* 0A53A0 7F070870 E61C0030 */  swc1  $f28, 0x30($s0)
/* 0A53A4 7F070874 E604003C */  swc1  $f4, 0x3c($s0)
/* 0A53A8 7F070878 C7B2009C */  lwc1  $f18, 0x9c($sp)
/* 0A53AC 7F07087C E6120024 */  swc1  $f18, 0x24($s0)
/* 0A53B0 7F070880 C7B000A0 */  lwc1  $f16, 0xa0($sp)
/* 0A53B4 7F070884 E6100028 */  swc1  $f16, 0x28($s0)
/* 0A53B8 7F070888 C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0A53BC 7F07088C E608002C */  swc1  $f8, 0x2c($s0)
/* 0A53C0 7F070890 C7A60098 */  lwc1  $f6, 0x98($sp)
/* 0A53C4 7F070894 E6060020 */  swc1  $f6, 0x20($s0)
/* 0A53C8 7F070898 86220030 */  lh    $v0, 0x30($s1)
/* 0A53CC 7F07089C 86230032 */  lh    $v1, 0x32($s1)
/* 0A53D0 7F0708A0 14620006 */  bne   $v1, $v0, .L7F0708BC
/* 0A53D4 7F0708A4 00000000 */   nop   
/* 0A53D8 7F0708A8 44825000 */  mtc1  $v0, $f10
/* 0A53DC 7F0708AC E638002C */  swc1  $f24, 0x2c($s1)
/* 0A53E0 7F0708B0 46805120 */  cvt.s.w $f4, $f10
/* 0A53E4 7F0708B4 10000019 */  b     .L7F07091C
/* 0A53E8 7F0708B8 E6240028 */   swc1  $f4, 0x28($s1)
.L7F0708BC:
/* 0A53EC 7F0708BC 5260000C */  beql  $s3, $zero, .L7F0708F0
/* 0A53F0 7F0708C0 44878000 */   mtc1  $a3, $f16
/* 0A53F4 7F0708C4 44878000 */  mtc1  $a3, $f16
/* 0A53F8 7F0708C8 44823000 */  mtc1  $v0, $f6
/* 0A53FC 7F0708CC C7B20100 */  lwc1  $f18, 0x100($sp)
/* 0A5400 7F0708D0 46808220 */  cvt.s.w $f8, $f16
/* 0A5404 7F0708D4 468032A0 */  cvt.s.w $f10, $f6
/* 0A5408 7F0708D8 46089001 */  sub.s $f0, $f18, $f8
/* 0A540C 7F0708DC 46005100 */  add.s $f4, $f10, $f0
/* 0A5410 7F0708E0 E620002C */  swc1  $f0, 0x2c($s1)
/* 0A5414 7F0708E4 1000000D */  b     .L7F07091C
/* 0A5418 7F0708E8 E6240028 */   swc1  $f4, 0x28($s1)
/* 0A541C 7F0708EC 44878000 */  mtc1  $a3, $f16
.L7F0708F0:
/* 0A5420 7F0708F0 C7A80100 */  lwc1  $f8, 0x100($sp)
/* 0A5424 7F0708F4 44833000 */  mtc1  $v1, $f6
/* 0A5428 7F0708F8 468084A0 */  cvt.s.w $f18, $f16
/* 0A542C 7F0708FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A5430 7F070900 44812000 */  mtc1  $at, $f4
/* 0A5434 7F070904 468032A0 */  cvt.s.w $f10, $f6
/* 0A5438 7F070908 46089001 */  sub.s $f0, $f18, $f8
/* 0A543C 7F07090C 46002401 */  sub.s $f16, $f4, $f0
/* 0A5440 7F070910 E620002C */  swc1  $f0, 0x2c($s1)
/* 0A5444 7F070914 46105480 */  add.s $f18, $f10, $f16
/* 0A5448 7F070918 E6320028 */  swc1  $f18, 0x28($s1)
.L7F07091C:
/* 0A544C 7F07091C 8E2E0054 */  lw    $t6, 0x54($s1)
/* 0A5450 7F070920 11C00055 */  beqz  $t6, .L7F070A78
/* 0A5454 7F070924 00000000 */   nop   
/* 0A5458 7F070928 0FC170F6 */  jal   floorFloatToInt
/* 0A545C 7F07092C C7AC0104 */   lwc1  $f12, 0x104($sp)
/* 0A5460 7F070930 C7B40108 */  lwc1  $f20, 0x108($sp)
/* 0A5464 7F070934 00409025 */  move  $s2, $v0
/* 0A5468 7F070938 0FC170F6 */  jal   floorFloatToInt
/* 0A546C 7F07093C 4600A306 */   mov.s $f12, $f20
/* 0A5470 7F070940 12600004 */  beqz  $s3, .L7F070954
/* 0A5474 7F070944 AFA2006C */   sw    $v0, 0x6c($sp)
/* 0A5478 7F070948 0242082A */  slt   $at, $s2, $v0
/* 0A547C 7F07094C 54200006 */  bnezl $at, .L7F070968
/* 0A5480 7F070950 820F0002 */   lb    $t7, 2($s0)
.L7F070954:
/* 0A5484 7F070954 1660002C */  bnez  $s3, .L7F070A08
/* 0A5488 7F070958 0052082A */   slt   $at, $v0, $s2
/* 0A548C 7F07095C 5020002B */  beql  $at, $zero, .L7F070A0C
/* 0A5490 7F070960 3C013F80 */   lui   $at, 0x3f80
/* 0A5494 7F070964 820F0002 */  lb    $t7, 2($s0)
.L7F070968:
/* 0A5498 7F070968 51E00005 */  beql  $t7, $zero, .L7F070980
/* 0A549C 7F07096C C6060038 */   lwc1  $f6, 0x38($s0)
/* 0A54A0 7F070970 C6080044 */  lwc1  $f8, 0x44($s0)
/* 0A54A4 7F070974 10000003 */  b     .L7F070984
/* 0A54A8 7F070978 E6080050 */   swc1  $f8, 0x50($s0)
/* 0A54AC 7F07097C C6060038 */  lwc1  $f6, 0x38($s0)
.L7F070980:
/* 0A54B0 7F070980 E6060050 */  swc1  $f6, 0x50($s0)
.L7F070984:
/* 0A54B4 7F070984 8FA4006C */  lw    $a0, 0x6c($sp)
/* 0A54B8 7F070988 8E250054 */  lw    $a1, 0x54($s1)
/* 0A54BC 7F07098C 0FC1BD9B */  jal   modelConstrainOrWrapAnimFrame
/* 0A54C0 7F070990 8E26006C */   lw    $a2, 0x6c($s1)
/* 0A54C4 7F070994 A6220060 */  sh    $v0, 0x60($s1)
/* 0A54C8 7F070998 8FA4006C */  lw    $a0, 0x6c($sp)
/* 0A54CC 7F07099C 8E250054 */  lw    $a1, 0x54($s1)
/* 0A54D0 7F0709A0 8E26006C */  lw    $a2, 0x6c($s1)
/* 0A54D4 7F0709A4 0FC1BD9B */  jal   modelConstrainOrWrapAnimFrame
/* 0A54D8 7F0709A8 24840001 */   addiu $a0, $a0, 1
/* 0A54DC 7F0709AC A6220062 */  sh    $v0, 0x62($s1)
/* 0A54E0 7F0709B0 82250025 */  lb    $a1, 0x25($s1)
/* 0A54E4 7F0709B4 8E270054 */  lw    $a3, 0x54($s1)
/* 0A54E8 7F0709B8 27B800C8 */  addiu $t8, $sp, 0xc8
/* 0A54EC 7F0709BC AFB80014 */  sw    $t8, 0x14($sp)
/* 0A54F0 7F0709C0 AFA20010 */  sw    $v0, 0x10($sp)
/* 0A54F4 7F0709C4 8FA600E0 */  lw    $a2, 0xe0($sp)
/* 0A54F8 7F0709C8 0FC1B4FD */  jal   sub_GAME_7F06D3F4
/* 0A54FC 7F0709CC 8FA400E4 */   lw    $a0, 0xe4($sp)
/* 0A5500 7F0709D0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A5504 7F0709D4 44811000 */  mtc1  $at, $f2
/* 0A5508 7F0709D8 C7AC00DC */  lwc1  $f12, 0xdc($sp)
/* 0A550C 7F0709DC C7A400CC */  lwc1  $f4, 0xcc($sp)
/* 0A5510 7F0709E0 46026032 */  c.eq.s $f12, $f2
/* 0A5514 7F0709E4 00000000 */  nop   
/* 0A5518 7F0709E8 45030004 */  bc1tl .L7F0709FC
/* 0A551C 7F0709EC C7B000CC */   lwc1  $f16, 0xcc($sp)
/* 0A5520 7F0709F0 460C2282 */  mul.s $f10, $f4, $f12
/* 0A5524 7F0709F4 E7AA00CC */  swc1  $f10, 0xcc($sp)
/* 0A5528 7F0709F8 C7B000CC */  lwc1  $f16, 0xcc($sp)
.L7F0709FC:
/* 0A552C 7F0709FC 24190001 */  li    $t9, 1
/* 0A5530 7F070A00 A2190002 */  sb    $t9, 2($s0)
/* 0A5534 7F070A04 E6100044 */  swc1  $f16, 0x44($s0)
.L7F070A08:
/* 0A5538 7F070A08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
.L7F070A0C:
/* 0A553C 7F070A0C 44811000 */  mtc1  $at, $f2
/* 0A5540 7F070A10 1260000C */  beqz  $s3, .L7F070A44
/* 0A5544 7F070A14 8FAD006C */   lw    $t5, 0x6c($sp)
/* 0A5548 7F070A18 8FA8006C */  lw    $t0, 0x6c($sp)
/* 0A554C 7F070A1C 86290060 */  lh    $t1, 0x60($s1)
/* 0A5550 7F070A20 44889000 */  mtc1  $t0, $f18
/* 0A5554 7F070A24 44893000 */  mtc1  $t1, $f6
/* 0A5558 7F070A28 46809220 */  cvt.s.w $f8, $f18
/* 0A555C 7F070A2C 46803120 */  cvt.s.w $f4, $f6
/* 0A5560 7F070A30 4608A001 */  sub.s $f0, $f20, $f8
/* 0A5564 7F070A34 46002280 */  add.s $f10, $f4, $f0
/* 0A5568 7F070A38 E620005C */  swc1  $f0, 0x5c($s1)
/* 0A556C 7F070A3C 1000001E */  b     .L7F070AB8
/* 0A5570 7F070A40 E62A0058 */   swc1  $f10, 0x58($s1)
.L7F070A44:
/* 0A5574 7F070A44 448D8000 */  mtc1  $t5, $f16
/* 0A5578 7F070A48 862C0062 */  lh    $t4, 0x62($s1)
/* 0A557C 7F070A4C 468084A0 */  cvt.s.w $f18, $f16
/* 0A5580 7F070A50 448C3000 */  mtc1  $t4, $f6
/* 0A5584 7F070A54 00000000 */  nop   
/* 0A5588 7F070A58 46803120 */  cvt.s.w $f4, $f6
/* 0A558C 7F070A5C 4612A201 */  sub.s $f8, $f20, $f18
/* 0A5590 7F070A60 46081001 */  sub.s $f0, $f2, $f8
/* 0A5594 7F070A64 46001281 */  sub.s $f10, $f2, $f0
/* 0A5598 7F070A68 E620005C */  swc1  $f0, 0x5c($s1)
/* 0A559C 7F070A6C 460A2400 */  add.s $f16, $f4, $f10
/* 0A55A0 7F070A70 10000011 */  b     .L7F070AB8
/* 0A55A4 7F070A74 E6300058 */   swc1  $f16, 0x58($s1)
.L7F070A78:
/* 0A55A8 7F070A78 1000000F */  b     .L7F070AB8
/* 0A55AC 7F070A7C A2000002 */   sb    $zero, 2($s0)
/* 0A55B0 7F070A80 C7B40108 */  lwc1  $f20, 0x108($sp)
.L7F070A84:
/* 0A55B4 7F070A84 02202025 */  move  $a0, $s1
/* 0A55B8 7F070A88 8FA50100 */  lw    $a1, 0x100($sp)
/* 0A55BC 7F070A8C 4406A000 */  mfc1  $a2, $f20
/* 0A55C0 7F070A90 0FC1C024 */  jal   modelSetAnimFrame2
/* 0A55C4 7F070A94 00000000 */   nop   
/* 0A55C8 7F070A98 10000008 */  b     .L7F070ABC
/* 0A55CC 7F070A9C 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0A55D0 7F070AA0 C7B40108 */  lwc1  $f20, 0x108($sp)
.L7F070AA4:
/* 0A55D4 7F070AA4 02202025 */  move  $a0, $s1
/* 0A55D8 7F070AA8 8FA50100 */  lw    $a1, 0x100($sp)
/* 0A55DC 7F070AAC 4406A000 */  mfc1  $a2, $f20
/* 0A55E0 7F070AB0 0FC1C024 */  jal   modelSetAnimFrame2
/* 0A55E4 7F070AB4 00000000 */   nop   
.L7F070AB8:
/* 0A55E8 7F070AB8 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F070ABC:
/* 0A55EC 7F070ABC D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0A55F0 7F070AC0 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0A55F4 7F070AC4 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0A55F8 7F070AC8 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0A55FC 7F070ACC D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0A5600 7F070AD0 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0A5604 7F070AD4 8FB0004C */  lw    $s0, 0x4c($sp)
/* 0A5608 7F070AD8 8FB10050 */  lw    $s1, 0x50($sp)
/* 0A560C 7F070ADC 8FB20054 */  lw    $s2, 0x54($sp)
/* 0A5610 7F070AE0 8FB30058 */  lw    $s3, 0x58($sp)
/* 0A5614 7F070AE4 03E00008 */  jr    $ra
/* 0A5618 7F070AE8 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif





#ifdef NONMATCHING
void modelTickAnimQuarterSpeed(void) {

}
#else
GLOBAL_ASM(
.text
glabel modelTickAnimQuarterSpeed
/* 0A561C 7F070AEC 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0A5620 7F070AF0 AFBF0054 */  sw    $ra, 0x54($sp)
/* 0A5624 7F070AF4 AFB10050 */  sw    $s1, 0x50($sp)
/* 0A5628 7F070AF8 AFB0004C */  sw    $s0, 0x4c($sp)
/* 0A562C 7F070AFC F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0A5630 7F070B00 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0A5634 7F070B04 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0A5638 7F070B08 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0A563C 7F070B0C F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0A5640 7F070B10 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0A5644 7F070B14 AFA60090 */  sw    $a2, 0x90($sp)
/* 0A5648 7F070B18 C4840058 */  lwc1  $f4, 0x58($a0)
/* 0A564C 7F070B1C C4920028 */  lwc1  $f18, 0x28($a0)
/* 0A5650 7F070B20 00808025 */  move  $s0, $a0
/* 0A5654 7F070B24 00A08825 */  move  $s1, $a1
/* 0A5658 7F070B28 18A0010A */  blez  $a1, .L7F070F54
/* 0A565C 7F070B2C E7A40080 */   swc1  $f4, 0x80($sp)
/* 0A5660 7F070B30 58A000E6 */  blezl $a1, .L7F070ECC
/* 0A5664 7F070B34 8FAB0090 */   lw    $t3, 0x90($sp)
/* 0A5668 7F070B38 4480C000 */  mtc1  $zero, $f24
/* 0A566C 7F070B3C 00000000 */  nop   
/* 0A5670 7F070B40 C60200B0 */  lwc1  $f2, 0xb0($s0)
.L7F070B44:
/* 0A5674 7F070B44 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A5678 7F070B48 4602C03C */  c.lt.s $f24, $f2
/* 0A567C 7F070B4C 00000000 */  nop   
/* 0A5680 7F070B50 45020017 */  bc1fl .L7F070BB0
/* 0A5684 7F070B54 C6080088 */   lwc1  $f8, 0x88($s0)
/* 0A5688 7F070B58 C60600B4 */  lwc1  $f6, 0xb4($s0)
/* 0A568C 7F070B5C 44814000 */  mtc1  $at, $f8
/* 0A5690 7F070B60 00000000 */  nop   
/* 0A5694 7F070B64 46083280 */  add.s $f10, $f6, $f8
/* 0A5698 7F070B68 E60A00B4 */  swc1  $f10, 0xb4($s0)
/* 0A569C 7F070B6C C60C00B4 */  lwc1  $f12, 0xb4($s0)
/* 0A56A0 7F070B70 4602603C */  c.lt.s $f12, $f2
/* 0A56A4 7F070B74 00000000 */  nop   
/* 0A56A8 7F070B78 4502000A */  bc1fl .L7F070BA4
/* 0A56AC 7F070B7C C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 0A56B0 7F070B80 C60000AC */  lwc1  $f0, 0xac($s0)
/* 0A56B4 7F070B84 C60400A8 */  lwc1  $f4, 0xa8($s0)
/* 0A56B8 7F070B88 46002181 */  sub.s $f6, $f4, $f0
/* 0A56BC 7F070B8C 460C3202 */  mul.s $f8, $f6, $f12
/* 0A56C0 7F070B90 46024283 */  div.s $f10, $f8, $f2
/* 0A56C4 7F070B94 460A0100 */  add.s $f4, $f0, $f10
/* 0A56C8 7F070B98 10000004 */  b     .L7F070BAC
/* 0A56CC 7F070B9C E60400A4 */   swc1  $f4, 0xa4($s0)
/* 0A56D0 7F070BA0 C60600A8 */  lwc1  $f6, 0xa8($s0)
.L7F070BA4:
/* 0A56D4 7F070BA4 E61800B0 */  swc1  $f24, 0xb0($s0)
/* 0A56D8 7F070BA8 E60600A4 */  swc1  $f6, 0xa4($s0)
.L7F070BAC:
/* 0A56DC 7F070BAC C6080088 */  lwc1  $f8, 0x88($s0)
.L7F070BB0:
/* 0A56E0 7F070BB0 C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A56E4 7F070BB4 4608C03C */  c.lt.s $f24, $f8
/* 0A56E8 7F070BB8 00000000 */  nop   
/* 0A56EC 7F070BBC 4502001D */  bc1fl .L7F070C34
/* 0A56F0 7F070BC0 C60C004C */   lwc1  $f12, 0x4c($s0)
/* 0A56F4 7F070BC4 C60A008C */  lwc1  $f10, 0x8c($s0)
/* 0A56F8 7F070BC8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A56FC 7F070BCC 46025100 */  add.s $f4, $f10, $f2
/* 0A5700 7F070BD0 E604008C */  swc1  $f4, 0x8c($s0)
/* 0A5704 7F070BD4 C60C008C */  lwc1  $f12, 0x8c($s0)
/* 0A5708 7F070BD8 460CC032 */  c.eq.s $f24, $f12
/* 0A570C 7F070BDC 00000000 */  nop   
/* 0A5710 7F070BE0 45020006 */  bc1fl .L7F070BFC
/* 0A5714 7F070BE4 C6000088 */   lwc1  $f0, 0x88($s0)
/* 0A5718 7F070BE8 44813000 */  mtc1  $at, $f6
/* 0A571C 7F070BEC C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A5720 7F070BF0 1000000F */  b     .L7F070C30
/* 0A5724 7F070BF4 E6060084 */   swc1  $f6, 0x84($s0)
/* 0A5728 7F070BF8 C6000088 */  lwc1  $f0, 0x88($s0)
.L7F070BFC:
/* 0A572C 7F070BFC 4600603C */  c.lt.s $f12, $f0
/* 0A5730 7F070C00 00000000 */  nop   
/* 0A5734 7F070C04 45020007 */  bc1fl .L7F070C24
/* 0A5738 7F070C08 E6180088 */   swc1  $f24, 0x88($s0)
/* 0A573C 7F070C0C 460C0201 */  sub.s $f8, $f0, $f12
/* 0A5740 7F070C10 C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A5744 7F070C14 46004283 */  div.s $f10, $f8, $f0
/* 0A5748 7F070C18 10000005 */  b     .L7F070C30
/* 0A574C 7F070C1C E60A0084 */   swc1  $f10, 0x84($s0)
/* 0A5750 7F070C20 E6180088 */  swc1  $f24, 0x88($s0)
.L7F070C24:
/* 0A5754 7F070C24 E6180084 */  swc1  $f24, 0x84($s0)
/* 0A5758 7F070C28 AE000054 */  sw    $zero, 0x54($s0)
/* 0A575C 7F070C2C C60200A4 */  lwc1  $f2, 0xa4($s0)
.L7F070C30:
/* 0A5760 7F070C30 C60C004C */  lwc1  $f12, 0x4c($s0)
.L7F070C34:
/* 0A5764 7F070C34 460CC03C */  c.lt.s $f24, $f12
/* 0A5768 7F070C38 00000000 */  nop   
/* 0A576C 7F070C3C 45020017 */  bc1fl .L7F070C9C
/* 0A5770 7F070C40 C6100040 */   lwc1  $f16, 0x40($s0)
/* 0A5774 7F070C44 C6040050 */  lwc1  $f4, 0x50($s0)
/* 0A5778 7F070C48 46022180 */  add.s $f6, $f4, $f2
/* 0A577C 7F070C4C E6060050 */  swc1  $f6, 0x50($s0)
/* 0A5780 7F070C50 C60E0050 */  lwc1  $f14, 0x50($s0)
/* 0A5784 7F070C54 460C703C */  c.lt.s $f14, $f12
/* 0A5788 7F070C58 00000000 */  nop   
/* 0A578C 7F070C5C 4502000B */  bc1fl .L7F070C8C
/* 0A5790 7F070C60 C60A0044 */   lwc1  $f10, 0x44($s0)
/* 0A5794 7F070C64 C6000048 */  lwc1  $f0, 0x48($s0)
/* 0A5798 7F070C68 C6080044 */  lwc1  $f8, 0x44($s0)
/* 0A579C 7F070C6C C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A57A0 7F070C70 46004281 */  sub.s $f10, $f8, $f0
/* 0A57A4 7F070C74 460E5102 */  mul.s $f4, $f10, $f14
/* 0A57A8 7F070C78 460C2183 */  div.s $f6, $f4, $f12
/* 0A57AC 7F070C7C 46060200 */  add.s $f8, $f0, $f6
/* 0A57B0 7F070C80 10000005 */  b     .L7F070C98
/* 0A57B4 7F070C84 E6080040 */   swc1  $f8, 0x40($s0)
/* 0A57B8 7F070C88 C60A0044 */  lwc1  $f10, 0x44($s0)
.L7F070C8C:
/* 0A57BC 7F070C8C E618004C */  swc1  $f24, 0x4c($s0)
/* 0A57C0 7F070C90 C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A57C4 7F070C94 E60A0040 */  swc1  $f10, 0x40($s0)
.L7F070C98:
/* 0A57C8 7F070C98 C6100040 */  lwc1  $f16, 0x40($s0)
.L7F070C9C:
/* 0A57CC 7F070C9C 8E0E0054 */  lw    $t6, 0x54($s0)
/* 0A57D0 7F070CA0 46101102 */  mul.s $f4, $f2, $f16
/* 0A57D4 7F070CA4 11C00020 */  beqz  $t6, .L7F070D28
/* 0A57D8 7F070CA8 46049480 */   add.s $f18, $f18, $f4
/* 0A57DC 7F070CAC C60C007C */  lwc1  $f12, 0x7c($s0)
/* 0A57E0 7F070CB0 460CC03C */  c.lt.s $f24, $f12
/* 0A57E4 7F070CB4 00000000 */  nop   
/* 0A57E8 7F070CB8 45020017 */  bc1fl .L7F070D18
/* 0A57EC 7F070CBC C6000070 */   lwc1  $f0, 0x70($s0)
/* 0A57F0 7F070CC0 C6060080 */  lwc1  $f6, 0x80($s0)
/* 0A57F4 7F070CC4 46023200 */  add.s $f8, $f6, $f2
/* 0A57F8 7F070CC8 E6080080 */  swc1  $f8, 0x80($s0)
/* 0A57FC 7F070CCC C60E0080 */  lwc1  $f14, 0x80($s0)
/* 0A5800 7F070CD0 460C703C */  c.lt.s $f14, $f12
/* 0A5804 7F070CD4 00000000 */  nop   
/* 0A5808 7F070CD8 4502000B */  bc1fl .L7F070D08
/* 0A580C 7F070CDC C6040074 */   lwc1  $f4, 0x74($s0)
/* 0A5810 7F070CE0 C6000078 */  lwc1  $f0, 0x78($s0)
/* 0A5814 7F070CE4 C60A0074 */  lwc1  $f10, 0x74($s0)
/* 0A5818 7F070CE8 C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A581C 7F070CEC 46005101 */  sub.s $f4, $f10, $f0
/* 0A5820 7F070CF0 460E2182 */  mul.s $f6, $f4, $f14
/* 0A5824 7F070CF4 460C3203 */  div.s $f8, $f6, $f12
/* 0A5828 7F070CF8 46080280 */  add.s $f10, $f0, $f8
/* 0A582C 7F070CFC 10000005 */  b     .L7F070D14
/* 0A5830 7F070D00 E60A0070 */   swc1  $f10, 0x70($s0)
/* 0A5834 7F070D04 C6040074 */  lwc1  $f4, 0x74($s0)
.L7F070D08:
/* 0A5838 7F070D08 E618007C */  swc1  $f24, 0x7c($s0)
/* 0A583C 7F070D0C C60200A4 */  lwc1  $f2, 0xa4($s0)
/* 0A5840 7F070D10 E6040070 */  swc1  $f4, 0x70($s0)
.L7F070D14:
/* 0A5844 7F070D14 C6000070 */  lwc1  $f0, 0x70($s0)
.L7F070D18:
/* 0A5848 7F070D18 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0A584C 7F070D1C 46001202 */  mul.s $f8, $f2, $f0
/* 0A5850 7F070D20 46083280 */  add.s $f10, $f6, $f8
/* 0A5854 7F070D24 E7AA0080 */  swc1  $f10, 0x80($sp)
.L7F070D28:
/* 0A5858 7F070D28 820F0026 */  lb    $t7, 0x26($s0)
/* 0A585C 7F070D2C 51E00064 */  beql  $t7, $zero, .L7F070EC0
/* 0A5860 7F070D30 2631FFFF */   addiu $s1, $s1, -1
/* 0A5864 7F070D34 8E180020 */  lw    $t8, 0x20($s0)
/* 0A5868 7F070D38 4610C03E */  c.le.s $f24, $f16
/* 0A586C 7F070D3C C616003C */  lwc1  $f22, 0x3c($s0)
/* 0A5870 7F070D40 97190004 */  lhu   $t9, 4($t8)
/* 0A5874 7F070D44 C6020090 */  lwc1  $f2, 0x90($s0)
/* 0A5878 7F070D48 2728FFFF */  addiu $t0, $t9, -1
/* 0A587C 7F070D4C 44882000 */  mtc1  $t0, $f4
/* 0A5880 7F070D50 4500000C */  bc1f  .L7F070D84
/* 0A5884 7F070D54 46802020 */   cvt.s.w $f0, $f4
/* 0A5888 7F070D58 4616C03E */  c.le.s $f24, $f22
/* 0A588C 7F070D5C 46000506 */  mov.s $f20, $f0
/* 0A5890 7F070D60 46001686 */  mov.s $f26, $f2
/* 0A5894 7F070D64 45020012 */  bc1fl .L7F070DB0
/* 0A5898 7F070D68 4610C03E */   c.le.s $f24, $f16
/* 0A589C 7F070D6C 4600B03C */  c.lt.s $f22, $f0
/* 0A58A0 7F070D70 00000000 */  nop   
/* 0A58A4 7F070D74 4502000E */  bc1fl .L7F070DB0
/* 0A58A8 7F070D78 4610C03E */   c.le.s $f24, $f16
/* 0A58AC 7F070D7C 1000000B */  b     .L7F070DAC
/* 0A58B0 7F070D80 4600B506 */   mov.s $f20, $f22
.L7F070D84:
/* 0A58B4 7F070D84 4616C03E */  c.le.s $f24, $f22
/* 0A58B8 7F070D88 46001506 */  mov.s $f20, $f2
/* 0A58BC 7F070D8C 46000686 */  mov.s $f26, $f0
/* 0A58C0 7F070D90 45020007 */  bc1fl .L7F070DB0
/* 0A58C4 7F070D94 4610C03E */   c.le.s $f24, $f16
/* 0A58C8 7F070D98 4600B03C */  c.lt.s $f22, $f0
/* 0A58CC 7F070D9C 00000000 */  nop   
/* 0A58D0 7F070DA0 45020003 */  bc1fl .L7F070DB0
/* 0A58D4 7F070DA4 4610C03E */   c.le.s $f24, $f16
/* 0A58D8 7F070DA8 4600B686 */  mov.s $f26, $f22
.L7F070DAC:
/* 0A58DC 7F070DAC 4610C03E */  c.le.s $f24, $f16
.L7F070DB0:
/* 0A58E0 7F070DB0 00000000 */  nop   
/* 0A58E4 7F070DB4 45020006 */  bc1fl .L7F070DD0
/* 0A58E8 7F070DB8 4618803C */   c.lt.s $f16, $f24
/* 0A58EC 7F070DBC 4612A03E */  c.le.s $f20, $f18
/* 0A58F0 7F070DC0 00000000 */  nop   
/* 0A58F4 7F070DC4 4503000A */  bc1tl .L7F070DF0
/* 0A58F8 7F070DC8 C606004C */   lwc1  $f6, 0x4c($s0)
/* 0A58FC 7F070DCC 4618803C */  c.lt.s $f16, $f24
.L7F070DD0:
/* 0A5900 7F070DD0 00000000 */  nop   
/* 0A5904 7F070DD4 4502003A */  bc1fl .L7F070EC0
/* 0A5908 7F070DD8 2631FFFF */   addiu $s1, $s1, -1
/* 0A590C 7F070DDC 4614903E */  c.le.s $f18, $f20
/* 0A5910 7F070DE0 00000000 */  nop   
/* 0A5914 7F070DE4 45020036 */  bc1fl .L7F070EC0
/* 0A5918 7F070DE8 2631FFFF */   addiu $s1, $s1, -1
/* 0A591C 7F070DEC C606004C */  lwc1  $f6, 0x4c($s0)
.L7F070DF0:
/* 0A5920 7F070DF0 C61C0044 */  lwc1  $f28, 0x44($s0)
/* 0A5924 7F070DF4 C61E0048 */  lwc1  $f30, 0x48($s0)
/* 0A5928 7F070DF8 8FA90090 */  lw    $t1, 0x90($sp)
/* 0A592C 7F070DFC E7A60060 */  swc1  $f6, 0x60($sp)
/* 0A5930 7F070E00 C6080050 */  lwc1  $f8, 0x50($s0)
/* 0A5934 7F070E04 02002025 */  move  $a0, $s0
/* 0A5938 7F070E08 1120000A */  beqz  $t1, .L7F070E34
/* 0A593C 7F070E0C E7A8005C */   swc1  $f8, 0x5c($sp)
/* 0A5940 7F070E10 8E050028 */  lw    $a1, 0x28($s0)
/* 0A5944 7F070E14 4406A000 */  mfc1  $a2, $f20
/* 0A5948 7F070E18 4407C000 */  mfc1  $a3, $f24
/* 0A594C 7F070E1C E7B20084 */  swc1  $f18, 0x84($sp)
/* 0A5950 7F070E20 E7B80010 */  swc1  $f24, 0x10($sp)
/* 0A5954 7F070E24 0FC1C07B */  jal   modelSetAnimFrame2WithChrStuff
/* 0A5958 7F070E28 02002025 */   move  $a0, $s0
/* 0A595C 7F070E2C 10000006 */  b     .L7F070E48
/* 0A5960 7F070E30 C7B20084 */   lwc1  $f18, 0x84($sp)
.L7F070E34:
/* 0A5964 7F070E34 4405A000 */  mfc1  $a1, $f20
/* 0A5968 7F070E38 4406C000 */  mfc1  $a2, $f24
/* 0A596C 7F070E3C 0FC1C024 */  jal   modelSetAnimFrame2
/* 0A5970 7F070E40 E7B20084 */   swc1  $f18, 0x84($sp)
/* 0A5974 7F070E44 C7B20084 */  lwc1  $f18, 0x84($sp)
.L7F070E48:
/* 0A5978 7F070E48 C60A0040 */  lwc1  $f10, 0x40($s0)
/* 0A597C 7F070E4C 8E050020 */  lw    $a1, 0x20($s0)
/* 0A5980 7F070E50 82060024 */  lb    $a2, 0x24($s0)
/* 0A5984 7F070E54 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0A5988 7F070E58 C6040094 */  lwc1  $f4, 0x94($s0)
/* 0A598C 7F070E5C 4407D000 */  mfc1  $a3, $f26
/* 0A5990 7F070E60 E7B20084 */  swc1  $f18, 0x84($sp)
/* 0A5994 7F070E64 02002025 */  move  $a0, $s0
/* 0A5998 7F070E68 0FC1BF2A */  jal   modelSetAnimation
/* 0A599C 7F070E6C E7A40014 */   swc1  $f4, 0x14($sp)
/* 0A59A0 7F070E70 C7B20084 */  lwc1  $f18, 0x84($sp)
/* 0A59A4 7F070E74 240A0001 */  li    $t2, 1
/* 0A59A8 7F070E78 A20A0026 */  sb    $t2, 0x26($s0)
/* 0A59AC 7F070E7C E616003C */  swc1  $f22, 0x3c($s0)
/* 0A59B0 7F070E80 E61C0044 */  swc1  $f28, 0x44($s0)
/* 0A59B4 7F070E84 E61E0048 */  swc1  $f30, 0x48($s0)
/* 0A59B8 7F070E88 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0A59BC 7F070E8C 4612D280 */  add.s $f10, $f26, $f18
/* 0A59C0 7F070E90 E606004C */  swc1  $f6, 0x4c($s0)
/* 0A59C4 7F070E94 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0A59C8 7F070E98 E6080050 */  swc1  $f8, 0x50($s0)
/* 0A59CC 7F070E9C E7B20080 */  swc1  $f18, 0x80($sp)
/* 0A59D0 7F070EA0 8E020098 */  lw    $v0, 0x98($s0)
/* 0A59D4 7F070EA4 46145481 */  sub.s $f18, $f10, $f20
/* 0A59D8 7F070EA8 50400005 */  beql  $v0, $zero, .L7F070EC0
/* 0A59DC 7F070EAC 2631FFFF */   addiu $s1, $s1, -1
/* 0A59E0 7F070EB0 0040F809 */  jalr  $v0
/* 0A59E4 7F070EB4 E7B20084 */  swc1  $f18, 0x84($sp)
/* 0A59E8 7F070EB8 C7B20084 */  lwc1  $f18, 0x84($sp)
/* 0A59EC 7F070EBC 2631FFFF */  addiu $s1, $s1, -1
.L7F070EC0:
/* 0A59F0 7F070EC0 5E20FF20 */  bgtzl $s1, .L7F070B44
/* 0A59F4 7F070EC4 C60200B0 */   lwc1  $f2, 0xb0($s0)
/* 0A59F8 7F070EC8 8FAB0090 */  lw    $t3, 0x90($sp)
.L7F070ECC:
/* 0A59FC 7F070ECC 4480C000 */  mtc1  $zero, $f24
/* 0A5A00 7F070ED0 8E020054 */  lw    $v0, 0x54($s0)
/* 0A5A04 7F070ED4 11600014 */  beqz  $t3, .L7F070F28
/* 0A5A08 7F070ED8 00000000 */   nop   
/* 0A5A0C 7F070EDC 1040000A */  beqz  $v0, .L7F070F08
/* 0A5A10 7F070EE0 C6000028 */   lwc1  $f0, 0x28($s0)
/* 0A5A14 7F070EE4 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0A5A18 7F070EE8 44050000 */  mfc1  $a1, $f0
/* 0A5A1C 7F070EEC 44069000 */  mfc1  $a2, $f18
/* 0A5A20 7F070EF0 8E070058 */  lw    $a3, 0x58($s0)
/* 0A5A24 7F070EF4 02002025 */  move  $a0, $s0
/* 0A5A28 7F070EF8 0FC1C07B */  jal   modelSetAnimFrame2WithChrStuff
/* 0A5A2C 7F070EFC E7A40010 */   swc1  $f4, 0x10($sp)
/* 0A5A30 7F070F00 10000015 */  b     .L7F070F58
/* 0A5A34 7F070F04 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F08:
/* 0A5A38 7F070F08 44050000 */  mfc1  $a1, $f0
/* 0A5A3C 7F070F0C 44069000 */  mfc1  $a2, $f18
/* 0A5A40 7F070F10 4407C000 */  mfc1  $a3, $f24
/* 0A5A44 7F070F14 02002025 */  move  $a0, $s0
/* 0A5A48 7F070F18 0FC1C07B */  jal   modelSetAnimFrame2WithChrStuff
/* 0A5A4C 7F070F1C E7B80010 */   swc1  $f24, 0x10($sp)
/* 0A5A50 7F070F20 1000000D */  b     .L7F070F58
/* 0A5A54 7F070F24 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F28:
/* 0A5A58 7F070F28 10400006 */  beqz  $v0, .L7F070F44
/* 0A5A5C 7F070F2C 02002025 */   move  $a0, $s0
/* 0A5A60 7F070F30 44059000 */  mfc1  $a1, $f18
/* 0A5A64 7F070F34 0FC1C024 */  jal   modelSetAnimFrame2
/* 0A5A68 7F070F38 8FA60080 */   lw    $a2, 0x80($sp)
/* 0A5A6C 7F070F3C 10000006 */  b     .L7F070F58
/* 0A5A70 7F070F40 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F44:
/* 0A5A74 7F070F44 44059000 */  mfc1  $a1, $f18
/* 0A5A78 7F070F48 4406C000 */  mfc1  $a2, $f24
/* 0A5A7C 7F070F4C 0FC1C024 */  jal   modelSetAnimFrame2
/* 0A5A80 7F070F50 02002025 */   move  $a0, $s0
.L7F070F54:
/* 0A5A84 7F070F54 8FBF0054 */  lw    $ra, 0x54($sp)
.L7F070F58:
/* 0A5A88 7F070F58 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0A5A8C 7F070F5C D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0A5A90 7F070F60 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0A5A94 7F070F64 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0A5A98 7F070F68 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0A5A9C 7F070F6C D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0A5AA0 7F070F70 8FB0004C */  lw    $s0, 0x4c($sp)
/* 0A5AA4 7F070F74 8FB10050 */  lw    $s1, 0x50($sp)
/* 0A5AA8 7F070F78 03E00008 */  jr    $ra
/* 0A5AAC 7F070F7C 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif


void modelApplyRenderModeType1(ModelRenderData *renderdata)
{
    gDPPipeSync(renderdata->gdl++);
    gDPSetCycleType(renderdata->gdl++, G_CYC_1CYCLE);

    if (renderdata->zbufferenabled)
    {
        gDPSetRenderMode(renderdata->gdl++, G_RM_AA_ZB_OPA_SURF2, G_RM_AA_ZB_OPA_SURF);
    }
    else
    {
        gDPSetRenderMode(renderdata->gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    }

    gDPSetCombineMode(renderdata->gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
}


/*
--Copy/Paste from Doc
DisplayList Setups Depend on Object Type, Prop Guard or Gun. 
These are applied to each part of an object at runtime and can be overridden. loading the next part will use these values once more.
GeometryMode is not in setup and is persistent accross parts.


7F072A0C Read Displaylist 18 Model Type
7F072A1C Read Displaylist 18 Model Type
7F072A24 Check model type 1
7F072A2C Call to do model type 1 7F070F80
7F072A40 Check model type 3
7F072A48 Call to do model type 3 7F071030
7F072A5C Check model type 4
7F072A64 Call to do model type 4 7F071B44
7F072A78 Check model type 2
7F072A80 Call to do model type 2 7F072644

7F0727F8 Read Displaylist 04 Model Type

A1 is primary = 1, secondary = 0
Inside the T8 or whatever temporary register indicates gun or not gun (0 = gun, or UseZ = 1), for different render mode

Bool UseZ //guns = false
Bool 


Model Type 0: NoSetup.
    type 0 Has No DL Setup and will use whaterver is currently set. 

Model Type 1: 1Cycle No Sec
    E700000000000000 pipesync()
    BA00140200000000 CycleType(1c)
    if UseZ
      B900031D00552078 SetRendermode(AA_ZB_OPA_1) //cin ain cmem amem
    else
      B900031D00552048 SetRendermode(AA_OPA_1) //cin ain cmem amem
    end if
    FC121824FF33FFFF SetCombine(MODULATERGBA)
    No Secondary

Model Type 2: 2Cycle No Sec
    E700000000000000 pipesync()
    BA00140200100000 CycleType(2c)
    if UseZ
      B900031D0C192078 SetRendermode(AA_ZB_OPA_2) // cin 0 cin 1 //colour only
    else
      B900031D0C192048 SetRendermode(AA_OPA_2) // cin 0 cin 1 //colour only
    end if
    FC26A0041F1093FF SetCombine(TRILERP, MODULATERGBA)
    No Secondary
Model Type 3: GunLighting - Reduced Secondary Commands (guns)
    This Type Uses Vertex Alpha for Secondary Surfaces and uses the FOG Alpha value for applying Fog/"Lighting". 
    Primary
    E700000000000000 pipesync()
    BA00140200100000 CycleType(2c)
    F800000000000026 SetFogColor(0,0,0,38)
    if dltype = full
      if guard
        FB0000005A0000FF SetEnvColor(90,0,0,255)
        FC1598045FFEDBF8 SetCombine(((Texel0-Env)*ShadeA+Env) 
                         ((Texel0-Env)*Shade+Env), 
                         MODULATERGB_DECALA)
      else if prop
        FB000000FFFFFFFF SetEnvColor(255,255,255,255)
        FA00000000000000 SetPrimColor(0,0,0,0)
        FC26A0041F1093FB SetCombine(TRILERP, MODULATERGB_ADDPRIM_A)
      endif
    else
      FC26A0041F1093FF SetCombine(TRILERP, MODULATERGBA)
    endif
    if UseZ
      B900031DC4112078 SetRendermode(AA_ZB_OPA_StanFOG_2)
    else
      B900031DC4112048 SetRendermode(AA_OPA_StanFOG_2) //acvg
    endif

    Secondary
    if UseZ
      B900031DC41049D8 SetRendermode(AA_Zcmp_XLU_StanFOG_2)
    else
      B900031DC41041C8 SetRendermode(AA_OPA_StanFOG_2)//FcBl ClrOnCvg
    endif
    
Model Type 4: Normal Fog/Lighting object
    This Type Uses Vertex Alpha for Secondary Surfaces and uses the FOG Alpha value for applying Fog/"Lighting". 
    Primary
    E700000000000000 pipesync()
    BA00140200100000 CycleType(2c)
    F800000000000026 SetFogColor(0,0,0,38)
    if dltype = full
      if guard
        FB0000005A0000FF SetEnvColor(90,0,0,255)
        FC1598045FFEDBF8 SetCombine(((Texel0-Env)*ShadeA+Env) 
                         ((Texel0-Env)*Shade+Env), 
                         MODULATERGB_DECALA)
      else if prop
        FB000000FFFFFFFF SetEnvColor(255,255,255,255)
        FA00000000000000 SetPrimColor(0,0,0,0)
        FC26A0041F1093FB SetCombine(TRILERP, MODULATERGB_ADDPRIM_A)
      endif
    else
      FC26A0041F1093FF SetCombine(TRILERP, MODULATERGBA)
    endif
    if UseZ
      B900031DC4112078 SetRendermode(AA_ZB_OPA_StanFOG_2)
    else
      B900031DC4112048 SetRendermode(AA_OPA_StanFOG_2) //acvg
    endif

    Secondary
    E700000000000000 pipesync()
    BA00140200100000 CycleType(2c)
    F800000000000026 SetFogColor(0,0,0,38)
    if dltype = full
      if guard
        FB0000005A0000FF SetEnvColor(90,0,0,255)
        FC1598045FFEDBF8 SetCombine(((Texel0-Env)*ShadeA+Env) 
                         ((Texel0-Env)*Shade+Env), 
                         MODULATERGB_DECALA)
      else if prop
        FB000000FFFFFFFF SetEnvColor(255,255,255,255)
        FA00000000000000 SetPrimColor(0,0,0,0)
        FC26A0041F1093FB SetCombine(TRILERP, MODULATERGB_ADDPRIM_A)
      endif
    else
      FA00000000000000 SetPrimColor(0,0,0,0)
      FC26A0041F1093FB SetCombine(TRILERP, MODULATERGB_ADDPRIM_A)
    endif
    if UseZ
      B900031DC41049D8 SetRendermode(AA_Zcmp_XLU_StanFOG_2)
    else
      B900031DC41041C8 SetRendermode(AA_OPA_StanFOG_2)//FcBl ClrOnCvg
    endif
*/
void modelApplyRenderModeType3(ModelRenderData *renderdata, bool arg1)
{
    if (renderdata->unk30 == 7)
    {
        if (arg1)
        {
            u8 r, g, b, a;
            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

            r = _SHIFTR(renderdata->fogcolour, 24, 8);
            g = _SHIFTR(renderdata->fogcolour, 16, 8);
            b = _SHIFTR(renderdata->fogcolour, 8, 8);
            a = _SHIFTR(renderdata->fogcolour, 0, 8);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);

            r = _SHIFTR(renderdata->envcolour, 24, 8);
            g = _SHIFTR(renderdata->envcolour, 16, 8);
            b = _SHIFTR(renderdata->envcolour, 8, 8);
            a = 0xFF;
            gDPSetEnvColor(renderdata->gdl++, r, g, b, a);

            gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
    else if (renderdata->unk30 == 8)
    {
        if (arg1)
        {
            u8 r, g, b, a;
            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

            r = _SHIFTR(renderdata->fogcolour, 24, 8);
            g = _SHIFTR(renderdata->fogcolour, 16, 8);
            b = _SHIFTR(renderdata->fogcolour, 8, 8);
            a = _SHIFTR(renderdata->fogcolour, 0, 8);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);

            r = _SHIFTR(renderdata->envcolour, 24, 8);
            g = _SHIFTR(renderdata->envcolour, 16, 8);
            b = _SHIFTR(renderdata->envcolour, 8, 8);
            a = _SHIFTR(renderdata->envcolour, 0, 8);
            gDPSetEnvColor(renderdata->gdl++, r, g, b, a);

            gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
    else if (renderdata->unk30 == 9)
    {
        if ((renderdata->envcolour & 0xFF) == 0)
        {
            if (arg1)
            {
                u8 r = _SHIFTR(renderdata->fogcolour, 24, 8);
                u8 g = _SHIFTR(renderdata->fogcolour, 16, 8);
                u8 b = _SHIFTR(renderdata->fogcolour, 8, 8);
                u8 a = _SHIFTR(renderdata->fogcolour, 0, 8);

                gDPPipeSync(renderdata->gdl++);
                gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
                gDPSetFogColor(renderdata->gdl++, r, g, b, a);
                gDPSetEnvColor(renderdata->gdl++, 0xFF, 0xFF, 0xFF, 0xFF);
                gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xFF);

                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
                }
            }
            else
            {
                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
                }
            }
        }
        else
        {
            if (arg1)
            {
                u8 r = _SHIFTR(renderdata->fogcolour, 24, 8);
                u8 g = _SHIFTR(renderdata->fogcolour, 16, 8);
                u8 b = _SHIFTR(renderdata->fogcolour, 8, 8);
                u8 a = _SHIFTR(renderdata->fogcolour, 0, 8);

                gDPPipeSync(renderdata->gdl++);
                gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
                gDPSetFogColor(renderdata->gdl++, r, g, b, a);
                gDPSetEnvColor(renderdata->gdl++, 0, 0, 0, renderdata->envcolour & 0xFF);

                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
                }
            }
            else
            {
                gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xFF);
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, SHADE, ENVIRONMENT, TEXEL0, 0, COMBINED, 0, SHADE, 0, 1, 0, PRIMITIVE, COMBINED);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
                }
            }
        }
    }
    else if (renderdata->unk30 == 4)
    {
        if (arg1)
        {
            u8 r = _SHIFTR(renderdata->envcolour, 24, 8);
            u8 g = _SHIFTR(renderdata->envcolour, 16, 8);
            u8 b = _SHIFTR(renderdata->envcolour, 8, 8);
            u8 a = _SHIFTR(renderdata->envcolour, 0, 8);

            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);

            gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
    else if (renderdata->unk30 == 5)
    {
        u8 r, g, b, a;
        if (arg1)
        {
            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

            r = _SHIFTR(renderdata->fogcolour, 24, 8);
            g = _SHIFTR(renderdata->fogcolour, 16, 8);
            b = _SHIFTR(renderdata->fogcolour, 8, 8);
            a = _SHIFTR(renderdata->fogcolour, 0, 8);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);

            a = renderdata->envcolour & 0xFF;

            if (a < 255)
            {
                gDPSetEnvColor(renderdata->gdl++, 0xFF, 0xFF, 0xFF, a);

                if (renderdata->envcolour & 0xFF00)
                {
                    gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, SHADE, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
                }
                else
                {
                    gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
                }
            }
            else
            {
                gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
            }

            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
        else
        {
            a = renderdata->envcolour & 0xFF;

            if (a < 255)
            {
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
            }
            else
            {
                gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
            }
        }
    }
    else
    {
        if (arg1)
        {
            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
            gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_XLU_SURF2);
            }
        }
    }
}


void modelApplyRenderModeType4(ModelRenderData *renderdata, bool arg1)
{
    if (renderdata->unk30 == 7)
    {
        u8 r, g, b, a;
        gDPPipeSync(renderdata->gdl++);
        gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

        r = _SHIFTR(renderdata->fogcolour, 24, 8);
        g = _SHIFTR(renderdata->fogcolour, 16, 8);
        b = _SHIFTR(renderdata->fogcolour, 8, 8);
        a = _SHIFTR(renderdata->fogcolour, 0, 8);
        gDPSetFogColor(renderdata->gdl++, r, g, b, a);

        r = _SHIFTR(renderdata->envcolour, 24, 8);
        g = _SHIFTR(renderdata->envcolour, 16, 8);
        b = _SHIFTR(renderdata->envcolour, 8, 8);
        a = 0xFF;
        gDPSetEnvColor(renderdata->gdl++, r, g, b, a);

        gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

        if (arg1)
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
    else if (renderdata->unk30 == 8)
    {
        u8 r, g, b, a;
        gDPPipeSync(renderdata->gdl++);
        gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

        r = _SHIFTR(renderdata->fogcolour, 24, 8);
        g = _SHIFTR(renderdata->fogcolour, 16, 8);
        b = _SHIFTR(renderdata->fogcolour, 8, 8);
        a = _SHIFTR(renderdata->fogcolour, 0, 8);
        gDPSetFogColor(renderdata->gdl++, r, g, b, a);

        r = _SHIFTR(renderdata->envcolour, 24, 8);
        g = _SHIFTR(renderdata->envcolour, 16, 8);
        b = _SHIFTR(renderdata->envcolour, 8, 8);
        a = _SHIFTR(renderdata->envcolour, 0, 8);
        gDPSetEnvColor(renderdata->gdl++, r, g, b, a);

        gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

        if (renderdata->zbufferenabled)
        {
            gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
        }
        else
        {
            gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
        }
    }
    else if (renderdata->unk30 == 9)
    {
        if ((renderdata->envcolour & 0xFF) == 0)
        {
            u8 r = _SHIFTR(renderdata->fogcolour, 24, 8);
            u8 g = _SHIFTR(renderdata->fogcolour, 16, 8);
            u8 b = _SHIFTR(renderdata->fogcolour, 8, 8);
            u8 a = _SHIFTR(renderdata->fogcolour, 0, 8);

            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);
            gDPSetEnvColor(renderdata->gdl++, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xFF);

            if (arg1)
            {
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
                }
            }
            else
            {
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
                }
            }
        }
        else
        {
            u8 r = _SHIFTR(renderdata->fogcolour, 24, 8);
            u8 g = _SHIFTR(renderdata->fogcolour, 16, 8);
            u8 b = _SHIFTR(renderdata->fogcolour, 8, 8);
            u8 a = _SHIFTR(renderdata->fogcolour, 0, 8);

            gDPPipeSync(renderdata->gdl++);
            gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
            gDPSetFogColor(renderdata->gdl++, r, g, b, a);
            gDPSetEnvColor(renderdata->gdl++, 0, 0, 0, renderdata->envcolour & 0xFF);

            if (arg1)
            {
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
                }
            }
            else
            {
                gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xFF);
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, SHADE, ENVIRONMENT, TEXEL0, 0, COMBINED, 0, SHADE, 0, 1, 0, PRIMITIVE, COMBINED);

                if (renderdata->zbufferenabled)
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
                }
            }
        }
    }
    else if (renderdata->unk30 == 4)
    {
        u8 r = _SHIFTR(renderdata->envcolour, 24, 8);
        u8 g = _SHIFTR(renderdata->envcolour, 16, 8);
        u8 b = _SHIFTR(renderdata->envcolour, 8, 8);
        u8 a = _SHIFTR(renderdata->envcolour, 0, 8);

        gDPPipeSync(renderdata->gdl++);
        gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
        gDPSetFogColor(renderdata->gdl++, r, g, b, a);

        gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

        if (arg1)
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
    else if (renderdata->unk30 == 5)
    {
        u8 r, g, b, a;

        gDPPipeSync(renderdata->gdl++);
        gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

        r = _SHIFTR(renderdata->fogcolour, 24, 8);
        g = _SHIFTR(renderdata->fogcolour, 16, 8);
        b = _SHIFTR(renderdata->fogcolour, 8, 8);
        a = _SHIFTR(renderdata->fogcolour, 0, 8);
        gDPSetFogColor(renderdata->gdl++, r, g, b, a);

        a = renderdata->envcolour & 0xFF;

        if (a < 255)
        {
            gDPSetEnvColor(renderdata->gdl++, 0xFF, 0xFF, 0xFF, a);

            if (arg1)
            {
                if (renderdata->envcolour & 0xFF00)
                {
                    gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, SHADE, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
                }
                else
                {
                    gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
                }
            }
            else
            {
                gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
            }
        }
        else
        {
            gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
        }

        if (renderdata->zbufferenabled)
        {
            gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
        }
        else
        {
            gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
        }
    }
    else
    {
        gDPPipeSync(renderdata->gdl++);
        gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
        gDPSetFogColor(renderdata->gdl++, 0xFF, 0xFF, 0xFF, 0x00);
        gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

        if (arg1)
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
            }
        }
        else
        {
            if (renderdata->zbufferenabled)
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
            }
            else
            {
                gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
            }
        }
    }
}


void modelApplyRenderModeType2(ModelRenderData *renderdata)
{
    gDPPipeSync(renderdata->gdl++);
    gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

    if (renderdata->zbufferenabled)
    {
        gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    }
    else
    {
        gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    }

    gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
}


void modelApplyCullMode(ModelRenderData *renderdata)
{
    if (renderdata->cullmode == CULLMODE_NONE)
    {
        gSPClearGeometryMode(renderdata->gdl++, G_CULL_BOTH);
    }
    else if (renderdata->cullmode == CULLMODE_FRONT)
    {
        gSPSetGeometryMode(renderdata->gdl++, G_CULL_FRONT);
    }
    else if (renderdata->cullmode == CULLMODE_BACK)
    {
        gSPSetGeometryMode(renderdata->gdl++, G_CULL_BACK);
    }
}


void modelRenderNodeGundl(ModelRenderData* renderdata, ModelNode* arg1)
{
    ModelRoData_DisplayListRecord* rodata = &arg1->Data->DisplayList;

    if (renderdata->unk18 == 0)
    {
        if ((renderdata->flags & 1) && rodata->Primary)
        {
            gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->BaseAddr));

            if (renderdata->cullmode)
            {
                modelApplyCullMode(renderdata);
            }

            if (rodata->ModelType == 1)
            {
                modelApplyRenderModeType1(renderdata);
            }
            else if (rodata->ModelType == 3)
            {
                modelApplyRenderModeType3(renderdata, 1);
            }
            else if (rodata->ModelType == 4)
            {
                modelApplyRenderModeType4(renderdata, 1);
            }
            else if (rodata->ModelType == 2)
            {
                modelApplyRenderModeType2(renderdata);
            }

            gSPDisplayList(renderdata->gdl++, rodata->Primary);

            if ((rodata->ModelType == 3) && rodata->Secondary)
            {
                modelApplyRenderModeType3(renderdata, 0);
                gSPDisplayList(renderdata->gdl++, rodata->Secondary);
            }
        }

        if ((renderdata->flags & 2) && rodata->Primary && (rodata->ModelType == 4) && rodata->Secondary)
        {
            gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->BaseAddr));

            if (renderdata->cullmode)
            {
                modelApplyCullMode(renderdata);
            }

            modelApplyRenderModeType4(renderdata, 0);
            gSPDisplayList(renderdata->gdl++, rodata->Secondary);
        }
    }
}


void modelRenderNodeDl(ModelRenderData *renderdata, Model *model, ModelNode *node)
{
    union ModelRoData *rodata = node->Data;

    if (!renderdata->unk18)
    {
        if (renderdata->flags & 1)
        {
            union ModelRwData *rwdata = modelGetNodeRwData(model, node);

            if (rwdata->DisplayListCollisions.gdl)
            {
                gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->DisplayListCollisions.BaseAddr));

                if (renderdata->cullmode)
                {
                    modelApplyCullMode(renderdata);
                }

                if (rodata->DisplayListCollisions.ModelType == 1)
                {
                    modelApplyRenderModeType1(renderdata);
                }
                else if (rodata->DisplayListCollisions.ModelType == 3)
                {
                    modelApplyRenderModeType3(renderdata, TRUE);
                }
                else if (rodata->DisplayListCollisions.ModelType == 4)
                {
                    modelApplyRenderModeType4(renderdata, TRUE);
                }
                else if (rodata->DisplayListCollisions.ModelType == 2)
                {
                    modelApplyRenderModeType2(renderdata);
                }

                gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(rwdata->DisplayListCollisions.Vertices));

                gSPDisplayList(renderdata->gdl++, rwdata->DisplayListCollisions.gdl);

                if (rodata->DisplayListCollisions.ModelType == 3 && rodata->DisplayListCollisions.Secondary)
                {
                    modelApplyRenderModeType3(renderdata, FALSE);
                    gSPDisplayList(renderdata->gdl++, rodata->DisplayListCollisions.Secondary);
                }
            }
        }

        if (renderdata->flags & 2)
        {
            union ModelRwData *rwdata = modelGetNodeRwData(model, node);

            if (rwdata->DisplayListCollisions.gdl && rodata->DisplayListCollisions.ModelType == 4 && rodata->DisplayListCollisions.Secondary)
            {
                gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->DisplayListCollisions.BaseAddr));

                if (renderdata->cullmode)
                {
                    modelApplyCullMode(renderdata);
                }

                gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(rwdata->DisplayListCollisions.Vertices));

                modelApplyRenderModeType4(renderdata, FALSE);

                gSPDisplayList(renderdata->gdl++, rodata->DisplayListCollisions.Secondary);
            }
        }
    }
}


void sub_GAME_7F072C10(ModelRenderData *param_1, struct Model *param_2, struct ModelNode *param_3)
{
    return;
}


/**
 * Star gunfire is a muzzle flash in a first person perspective, where the
 * muzzle flash has 3 or 4 "arms" that flare out from the main body.
 *
 * This function reads vertices from the model definition, tweaks them randomly,
 * writes them to a newly allocated vertices table and queues the node's
 * displaylist to the renderdata's DL.
 */
void dorottex(ModelRenderData *renderdata, ModelNode *node)
{
    if (renderdata->unk18 == 0 && (renderdata->flags & 2))
    {

        ModelRoData_DisplayListPrimaryRecord *rodata = &node->Data->DisplayListPrimary;
        s32 i;

        if (rodata->Primary)
        {
            Vertex *src;
            Vertex *dst;

            src = (Vertex *) rodata->Vertices;

#ifndef VERSION_EU
            if (vtxallocator != NULL)
            {
            }
            else
            {
                osSyncPrintf("dorottex: no vtx allocator!\n");
                return_null();
            }
#endif
            dst = vtxallocator(rodata->numVertices * 4);

            gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(dst));
            gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->BaseAddr));

            gDPSetFogColor(renderdata->gdl++, 0x00, 0x00, 0x00, 0x00);
            gSPDisplayList(renderdata->gdl++, rodata->Primary);

            for (i = 0; i < rodata->numVertices; i++)
            {
                u16 rand1 = (randomGetNext() << 10) & 0xffff;
                s32 s4 = ((coss(rand1) << 5) * 181) >> 18;
                s32 s3 = ((sins(rand1) << 5) * 181) >> 18;
                s32 s1 = (u32)randomGetNext() >> 31;
                s32 mult = 0x10000 - (randomGetNext() & 0x3fff);
                s32 corner1 = 0x200 + s3;
                s32 corner2 = 0x200 - s3;
                s32 corner3 = 0x200 - s4;
                s32 corner4 = 0x200 + s4;

                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];

                dst[0].s = corner3;
                dst[0].t = corner2;
                dst[0].coord.x = (src[(s1 + 0) % 4].coord.x * mult) >> 16;
                dst[0].coord.y = (src[(s1 + 0) % 4].coord.y * mult) >> 16;
                dst[0].coord.z = (src[(s1 + 0) % 4].coord.z * mult) >> 16;

                dst[1].s = corner1;
                dst[1].t = corner3;
                dst[1].coord.x = (src[(s1 + 1) % 4].coord.x * mult) >> 16;
                dst[1].coord.y = (src[(s1 + 1) % 4].coord.y * mult) >> 16;
                dst[1].coord.z = (src[(s1 + 1) % 4].coord.z * mult) >> 16;

                dst[2].s = corner4;
                dst[2].t = corner1;
                dst[2].coord.x = (src[(s1 + 2) % 4].coord.x * mult) >> 16;
                dst[2].coord.y = (src[(s1 + 2) % 4].coord.y * mult) >> 16;
                dst[2].coord.z = (src[(s1 + 2) % 4].coord.z * mult) >> 16;

                dst[3].s = corner2;
                dst[3].t = corner4;
                dst[3].coord.x = (src[(s1 + 3) % 4].coord.x * mult) >> 16;
                dst[3].coord.y = (src[(s1 + 3) % 4].coord.y * mult) >> 16;
                dst[3].coord.z = (src[(s1 + 3) % 4].coord.z * mult) >> 16;

                src += 4;
                dst += 4;
            }
        }
    }
}


void sub_GAME_7F073038(ModelRenderData *renderdata, struct sImageTableEntry *tconfig, s32 arg2)
{
	likely_generate_DL_for_image_declaration(&renderdata->gdl, tconfig, arg2, renderdata->zbufferenabled, 2);
}


void sub_GAME_7F07306C(s32 param_1,struct Model *param_2,struct ModelNode *param_3)
{
    return;
}


void dotube(ModelRenderData* renderdata, Model* model, ModelNode* node)
{
    s32 rw_index_sel;
    s32 rw_index_sel2;
    s32 c_entry_count;
    struct ModelRoData_Op07Record *rodata2;
    s32 c_entry2_count;
    s32 c_entry_index;
    s32 renderpos_index;
    ModelNode *node_from_07;
    struct ModelRoData_Child *c_entry2;
    Vertex *vtx2;
    u8 *entry2_04;
    s32 unused1;
    bool swap_order;
    struct ModelRoData_Op07Record *rodata;
    struct ModelRoData_Child *c_entry;
    struct ModelRwData_Op07Record *rwdata;
    Vertex *vtx_10;
    Vertex *vtx_10_2;
    RenderPosView *render_pos2;
    RenderPosView *render_pos;
    s32 rw_index2;
    s32 rw_index;
    Vertex *vtx1;
    struct ModelRwData_Op07Record *rwdata2;
    u8 *entry_04;
    s32 unused2;
    s32 renderpos_index2;
    s32 unused3;

    rodata = &node->Data->Op07;
    rwdata = &modelGetNodeRwData(model, node)->Op07;

    if (rodata->unk00 != NULL)
    {
        node_from_07 = rodata->unk00;
    }
    else
    {
        node_from_07 = rodata->unk04;
    }

    rodata2 = &node_from_07->Data->Op07;
    rwdata2 = &modelGetNodeRwData(model, node_from_07)->Op07;
    swap_order = 1;

    if (renderdata->flags & 1)
    {
        renderpos_index2 = modelFindNodeMtxIndex(node, 0);
        render_pos2 = &model->render_pos[renderpos_index2];
        rw_index = rwdata->index;
        rw_index2 = rwdata2->index;
        c_entry = &rodata->Children[rw_index];

        if (rodata->unk00 != NULL)
        {
            rw_index_sel = rw_index2;
            rw_index_sel2 = rw_index;
            renderpos_index = modelFindNodeMtxIndex(node, 0x200);
        }
        else
        {
            rw_index_sel = rw_index;
            rw_index_sel2 = rw_index2;
            renderpos_index = modelFindNodeMtxIndex(rodata->unk04, 0x200);
        }

        render_pos = &model->render_pos[renderpos_index];

        c_entry_index = ((rw_index_sel2 - rw_index_sel) + rodata->NumChildren) % rodata->NumChildren;

        if ((c_entry_index >= 2) && (c_entry_index < 7))
        {
            if (c_entry_index < 4)
            {
                c_entry_index = ((c_entry_index / 2) + rw_index_sel + rodata->NumChildren) % rodata->NumChildren;
            }
            else
            {
                c_entry_index = ((rw_index_sel - ((8 - c_entry_index) / 2)) + rodata->NumChildren) % rodata->NumChildren;
                swap_order = 0;
            }
        }
        else if ((c_entry_index >= 0xA) && (c_entry_index < 0xF))
        {
            if (c_entry_index >= 0xD)
            {
                c_entry_index = ((rw_index_sel - ((0x10 - c_entry_index) / 2)) + rodata->NumChildren) % rodata->NumChildren;
            }
            else
            {
                c_entry_index = (((c_entry_index - 8) / 2) + rw_index_sel + rodata->NumChildren) % rodata->NumChildren;
                swap_order = 0;
            }
        }
        else
        {
            if ((c_entry_index >= 7) && (c_entry_index < 0xA))
            {
                swap_order = 0;
            }
            c_entry_index = rw_index_sel;
        }

        entry_04 = c_entry->unk04;

        gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->BaseAddr));

        for (c_entry_count = c_entry->NumEntries; c_entry_count > 0; c_entry_count--)
        {
            switch (*entry_04)
            {
                case MODELNODE_CHILD_VTX:
                    {
                        struct ModelRoData_Child_Vtx* child_vtx = ((struct ModelRoData_Child_Vtx*)entry_04);
#if defined(LEFTOVERDEBUG)
                        if (vtxallocator == NULL)
                        {
                            osSyncPrintf("dotube: no vtx allocator!\n");
                            return_null();
                        }
#endif
                        vtx1 = vtxallocator(2);
                        vtx2 = &vtx1[1];

                        *vtx1 = rodata->Vertices[child_vtx->VtxIndex];
                        *vtx2 = rodata->Vertices[child_vtx->VtxIndex+1];

                        if (rodata->unk04 != NULL)
                        {
                            c_entry2 = &rodata->Children[c_entry_index];
                            entry2_04 = c_entry2->unk04;

                            for (c_entry2_count = c_entry2->NumEntries; c_entry2_count > 0; c_entry2_count--)
                            {
                                struct ModelRoData_Child_Vtx* entry2_04_child = ((struct ModelRoData_Child_Vtx*)entry2_04);
                                if (entry2_04_child->Type == (u8) 1) {
                                    vtx_10   = &rodata->Vertices[entry2_04_child->VtxIndex];
                                    vtx_10_2 = vtx_10+1;

                                    vtx1->coord.AsArray[0] = vtx_10->coord.AsArray[0];
                                    vtx1->coord.AsArray[1] = vtx_10->coord.AsArray[1];
                                    vtx1->coord.AsArray[2] = vtx_10->coord.AsArray[2];

                                    vtx2->coord.AsArray[0] = vtx_10_2->coord.AsArray[0];
                                    vtx2->coord.AsArray[1] = vtx_10_2->coord.AsArray[1];
                                    vtx2->coord.AsArray[2] = vtx_10_2->coord.AsArray[2];
                                    break;
                                }

                                switch (*entry2_04)
                                {
                                    case MODELNODE_CHILD_VTX:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Vtx);
                                        break;
                                    case MODELNODE_CHILD_IMAGE:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Image);
                                        break;
                                    case MODELNODE_CHILD_TRI:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Tri);
                                        break;
                                }
                            }

                        }
                        else
                        {
                            c_entry2 = &rodata2->Children[c_entry_index];
                            entry2_04 = c_entry2->unk04;

                            for (c_entry2_count = c_entry2->NumEntries; c_entry2_count > 0; c_entry2_count--)
                            {
                                struct ModelRoData_Child_Vtx* entry2_04_child = ((struct ModelRoData_Child_Vtx*)entry2_04);
                                if (entry2_04_child->Type == (u8) 1)
                                {
                                    vtx_10   = &rodata2->Vertices[entry2_04_child->VtxIndex];
                                    vtx_10_2 = vtx_10 + 1;
                                    if (swap_order != 0)
                                    {
#if defined(LEFTOVERDEBUG)
                                        if (vtx_10->coord.AsArray);
#endif
                                        vtx1->coord.AsArray[0] = vtx_10_2->coord.AsArray[0];
                                        vtx1->coord.AsArray[1] = vtx_10_2->coord.AsArray[1];
                                        vtx1->coord.AsArray[2] = vtx_10_2->coord.AsArray[2];

                                        vtx2->coord.AsArray[0] = vtx_10->coord.AsArray[0];
                                        vtx2->coord.AsArray[1] = vtx_10->coord.AsArray[1];
                                        vtx2->coord.AsArray[2] = vtx_10->coord.AsArray[2];
                                    }
                                    else
                                    {
                                        vtx1->coord.AsArray[0] = vtx_10->coord.AsArray[0];
                                        vtx1->coord.AsArray[1] = vtx_10->coord.AsArray[1];
                                        vtx1->coord.AsArray[2] = vtx_10->coord.AsArray[2];

                                        vtx2->coord.AsArray[0] = vtx_10_2->coord.AsArray[0];
                                        vtx2->coord.AsArray[1] = vtx_10_2->coord.AsArray[1];
                                        vtx2->coord.AsArray[2] = vtx_10_2->coord.AsArray[2];
                                    }
                                    break;
                                }

                                switch (*entry2_04)
                                {
                                    case MODELNODE_CHILD_VTX:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Vtx);
                                        break;

                                    case MODELNODE_CHILD_IMAGE:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Image);
                                        break;

                                    case MODELNODE_CHILD_TRI:
                                        entry2_04 += sizeof(struct ModelRoData_Child_Tri);
                                        break;
                                }
                            }
                        }

                        gSPMatrix(renderdata->gdl++, osVirtualToPhysical(render_pos), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gSPVertex(renderdata->gdl++, osVirtualToPhysical(vtx1), 2, 0);
                        gSPMatrix(renderdata->gdl++, osVirtualToPhysical(render_pos2), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gSPVertex(renderdata->gdl++, osVirtualToPhysical(&rodata->Vertices[child_vtx->VtxIndex] + 2), (u32)(child_vtx->unk01 - 2), 2);

                        entry_04 += sizeof(struct ModelRoData_Child_Vtx);

                        break;
                    }

                case MODELNODE_CHILD_IMAGE:
                    {
                        struct ModelRoData_Child_Image* child_image = (struct ModelRoData_Child_Image*)entry_04;
                        if (child_image->ImageIndex != 0xFF)
                        {
                            sub_GAME_7F073038(renderdata, &rodata->Images[child_image->ImageIndex], 1);
                            entry_04 += sizeof(struct ModelRoData_Child_Image);
                        }
                        else
                        {
                            sub_GAME_7F073038(renderdata, NULL, 1);
                            entry_04 += sizeof(struct ModelRoData_Child_Image);
                        }
                        break;
                    }

                case MODELNODE_CHILD_TRI:
                    {
                        struct ModelRoData_Child_Tri* child_tri = (struct ModelRoData_Child_Tri*)entry_04;
                        gSP1Triangle(renderdata->gdl++, child_tri->VtxIndex1, child_tri->VtxIndex2, child_tri->VtxIndex3, 0);
                        entry_04 += sizeof(struct ModelRoData_Child_Tri);
                        break;
                    }
            }
        }
    }
}


void sub_GAME_7F0737EC(s32 param_1,struct Model *param_2, struct ModelNode *param_3)
{
    return;
}


void sub_GAME_7F0737FC(s32 param_1,struct Model *param_2,struct ModelNode *param_3)
{
    return;
}


// PD: modelRenderNodeChrGunfire
void dogfnegx(ModelRenderData *renderdata, Model *model, ModelNode *node)
{
    u32 unused[3];
    f32 negspc0;
    ModelRoData_GunfireRecord *rodata = &node->Data->Gunfire;
    union ModelRwData *rwdata = modelGetNodeRwData(model, node);
    sImageTableEntry *tconfig;
    f32 spf0;
    f32 spec;
    coord3d spe0;
    f32 spdc;
    f32 spd8;
    f32 spd4;
    f32 spd0;
    f32 spcc;
    f32 spc8;
    f32 spc4;
    f32 spc0;
    f32 spbc;
    f32 negspcc;
    f32 negspc8;
    f32 scale;
    Mtxf *mtx;
    f32 tmp;
    coord3d sp9c;
    coord3d sp90;
    Vertex vtxtemplate = D_800363E0;
    Vertex *vertices;
    f32 distance;

    if ((renderdata->flags & 2) && rwdata->Gunfire.visible)
    {
        s32 index = modelFindNodeMtxIndex(node, 0);
        mtx = &model->render_pos[index].pos;

        spe0.x = -(rodata->Offset.f[0] * mtx->m[0][0] + rodata->Offset.f[1] * mtx->m[1][0] + rodata->Offset.f[2] * mtx->m[2][0] + mtx->m[3][0]);
        spe0.y = -(rodata->Offset.f[0] * mtx->m[0][1] + rodata->Offset.f[1] * mtx->m[1][1] + rodata->Offset.f[2] * mtx->m[2][1] + mtx->m[3][1]);
        spe0.z = -(rodata->Offset.f[0] * mtx->m[0][2] + rodata->Offset.f[1] * mtx->m[1][2] + rodata->Offset.f[2] * mtx->m[2][2] + mtx->m[3][2]);

        distance = sqrtf(spe0.f[0] * spe0.f[0] + spe0.f[1] * spe0.f[1] + spe0.f[2] * spe0.f[2]);

        if (distance > 0)
        {
            f32 tmp = 1 / (model->scale * distance);
            spe0.f[0] *= tmp;
            spe0.f[1] *= tmp;
            spe0.f[2] *= tmp;
        }
        else
        {
            spe0.f[0] = 0;
            spe0.f[1] = 0;
            spe0.f[2] = 1 / model->scale;
        }

        spec = acosf(spe0.f[0] * mtx->m[1][0] + spe0.f[1] * mtx->m[1][1] + spe0.f[2] * mtx->m[1][2]);
        spf0 = acosf(-(spe0.f[0] * mtx->m[2][0] + spe0.f[1] * mtx->m[2][1] + spe0.f[2] * mtx->m[2][2]) / sinf(spec));

        tmp = -(spe0.f[0] * mtx->m[0][0] + spe0.f[1] * mtx->m[0][1] + spe0.f[2] * mtx->m[0][2]);

        if (tmp < 0)
        {
            spf0 = M_TAU_F - spf0;
        }

        spdc = cosf(spf0);
        spd8 = sinf(spf0);
        spd4 = cosf(spec);
        spd0 = sinf(spec);

        scale = 0.75f + (randomGetNext() % 128) * (1.0f / 256.0f); // 0.75 to 1.25

        sp9c.f[0] = rodata->Size.f[0] * scale;
        sp9c.f[1] = rodata->Size.f[1] * scale;
        sp9c.f[2] = rodata->Size.f[2] * scale;

        spcc = sp9c.f[0] * spdc * 0.5f;
        spc8 = sp9c.f[2] * spd8 * 0.5f;
        spc4 = sp9c.f[1] * spd0 * 0.5f;

        spc0 = sp9c.f[0] * spd4 * spd8 * 0.5f;
        spbc = sp9c.f[2] * spd4 * spdc * 0.5f;

        negspcc = -spcc;
        negspc8 = -spc8;
        negspc0 = -spc0;

        sp90.f[0] = rodata->Offset.f[0] - sp9c.f[0] * 0.5f;
        sp90.f[1] = rodata->Offset.f[1];
        sp90.f[2] = rodata->Offset.f[2];

#if defined (LEFTOVERDEBUG)
        if (vtxallocator == NULL) {
            osSyncPrintf("dogfnegx: no vtx allocator!\n");
            return_null();
        }
#endif

        vertices = vtxallocator(4);

        vertices[0] = vtxtemplate;
        vertices[1] = vtxtemplate;
        vertices[2] = vtxtemplate;
        vertices[3] = vtxtemplate;

        vertices[0].coord.x = sp90.f[0] + negspcc + negspc0;
        vertices[0].coord.y = sp90.f[1] - spc4;
        vertices[0].coord.z = sp90.f[2] - negspc8 + -spbc;
        vertices[1].coord.x = sp90.f[0] + negspcc - negspc0;
        vertices[1].coord.y = sp90.f[1] + spc4;
        vertices[1].coord.z = sp90.f[2] - negspc8 - -spbc;
        vertices[2].coord.x = sp90.f[0] - negspcc - negspc0;
        vertices[2].coord.y = sp90.f[1] + spc4;
        vertices[2].coord.z = sp90.f[2] + negspc8 - -spbc;
        vertices[3].coord.x = sp90.f[0] - negspcc + negspc0;
        vertices[3].coord.y = sp90.f[1] - spc4;
        vertices[3].coord.z = sp90.f[2] + negspc8 + -spbc;

        gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->BaseAddr));

        if (rodata->Image)
        {
            s32 centre;
            u16 sp62;
            s32 sp5c;
            s32 sp58;

            tconfig = rodata->Image;

            sp62 = (randomGetNext() * 1024) & 0xffff;
            sp5c = (coss(sp62) * tconfig->width * 0xb5) >> 18;
            sp58 = (sins(sp62) * tconfig->width * 0xb5) >> 18;

            centre = tconfig->width << 4;

            vertices[0].s = centre - sp5c;
            vertices[0].t = centre - sp58;
            vertices[1].s = centre + sp58;
            vertices[1].t = centre - sp5c;
            vertices[2].s = centre + sp5c;
            vertices[2].t = centre + sp58;
            vertices[3].s = centre - sp58;
            vertices[3].t = centre + sp5c;

            sub_GAME_7F073038(renderdata, tconfig, 4);
        }
        else
        {
            sub_GAME_7F073038(renderdata, NULL, 1);
        }

        gSPSetGeometryMode(renderdata->gdl++, G_CULL_BACK);
        gSPMatrix(renderdata->gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(renderdata->gdl++, osVirtualToPhysical(vertices), 4, 0);
        if (1);
        gDPTri2(renderdata->gdl++, 0, 1, 2, 2, 3, 0);
    }
}


void sub_GAME_7F073FC8(s32 arg0)
{
    D_800363F0 = arg0;
}



#ifdef NONMATCHING
void doshadow(void) {

}
#else
#ifndef VERSION_EU
//D:80054A94
const char aDoshadowNoVtxAllocator[] = "doshadow: no vtx allocator!\n";
GLOBAL_ASM(
.text
glabel doshadow
/* 0A8B04 7F073FD4 3C038003 */  lui   $v1, %hi(D_800363F0)
/* 0A8B08 7F073FD8 246363F0 */  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x63f0
/* 0A8B0C 7F073FDC 8C6E0000 */  lw    $t6, ($v1)
/* 0A8B10 7F073FE0 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0A8B14 7F073FE4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A8B18 7F073FE8 00808025 */  move  $s0, $a0
/* 0A8B1C 7F073FEC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A8B20 7F073FF0 AFA60080 */  sw    $a2, 0x80($sp)
/* 0A8B24 7F073FF4 19C00142 */  blez  $t6, .L7F074500
/* 0A8B28 7F073FF8 00A03825 */   move  $a3, $a1
/* 0A8B2C 7F073FFC 3C198003 */  lui   $t9, %hi(D_800363F8) 
/* 0A8B30 7F074000 273963F8 */  addiu $t9, %lo(D_800363F8) # addiu $t9, $t9, 0x63f8
/* 0A8B34 7F074004 8F210000 */  lw    $at, ($t9)
/* 0A8B38 7F074008 8F290004 */  lw    $t1, 4($t9)
/* 0A8B3C 7F07400C 8CC60004 */  lw    $a2, 4($a2)
/* 0A8B40 7F074010 27B80058 */  addiu $t8, $sp, 0x58
/* 0A8B44 7F074014 AF010000 */  sw    $at, ($t8)
/* 0A8B48 7F074018 AF090004 */  sw    $t1, 4($t8)
/* 0A8B4C 7F07401C 8F29000C */  lw    $t1, 0xc($t9)
/* 0A8B50 7F074020 8F210008 */  lw    $at, 8($t9)
/* 0A8B54 7F074024 00A02025 */  move  $a0, $a1
/* 0A8B58 7F074028 AF09000C */  sw    $t1, 0xc($t8)
/* 0A8B5C 7F07402C AF010008 */  sw    $at, 8($t8)
/* 0A8B60 7F074030 8CC50014 */  lw    $a1, 0x14($a2)
/* 0A8B64 7F074034 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0A8B68 7F074038 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0A8B6C 7F07403C AFA6006C */   sw    $a2, 0x6c($sp)
/* 0A8B70 7F074040 8E0A0008 */  lw    $t2, 8($s0)
/* 0A8B74 7F074044 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A8B78 7F074048 C444000C */  lwc1  $f4, 0xc($v0)
/* 0A8B7C 7F07404C C4460004 */  lwc1  $f6, 4($v0)
/* 0A8B80 7F074050 3C038003 */  lui   $v1, %hi(D_800363F0)
/* 0A8B84 7F074054 314B0002 */  andi  $t3, $t2, 2
/* 0A8B88 7F074058 246363F0 */  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x63f0
/* 0A8B8C 7F07405C 8FA7007C */  lw    $a3, 0x7c($sp)
/* 0A8B90 7F074060 C4CC0008 */  lwc1  $f12, 8($a2)
/* 0A8B94 7F074064 C4CE000C */  lwc1  $f14, 0xc($a2)
/* 0A8B98 7F074068 11600125 */  beqz  $t3, .L7F074500
/* 0A8B9C 7F07406C 46062081 */   sub.s $f2, $f4, $f6
/* 0A8BA0 7F074070 8E020030 */  lw    $v0, 0x30($s0)
/* 0A8BA4 7F074074 24010003 */  li    $at, 3
/* 0A8BA8 7F074078 00002825 */  move  $a1, $zero
/* 0A8BAC 7F07407C 10410003 */  beq   $v0, $at, .L7F07408C
/* 0A8BB0 7F074080 24010008 */   li    $at, 8
/* 0A8BB4 7F074084 5441000F */  bnel  $v0, $at, .L7F0740C4
/* 0A8BB8 7F074088 8C780000 */   lw    $t8, ($v1)
.L7F07408C:
/* 0A8BBC 7F07408C 8E0C0034 */  lw    $t4, 0x34($s0)
/* 0A8BC0 7F074090 8C6E0000 */  lw    $t6, ($v1)
/* 0A8BC4 7F074094 240100FF */  li    $at, 255
/* 0A8BC8 7F074098 318D00FF */  andi  $t5, $t4, 0xff
/* 0A8BCC 7F07409C 01AE0019 */  multu $t5, $t6
/* 0A8BD0 7F0740A0 00001012 */  mflo  $v0
/* 0A8BD4 7F0740A4 00000000 */  nop   
/* 0A8BD8 7F0740A8 00000000 */  nop   
/* 0A8BDC 7F0740AC 0041001B */  divu  $zero, $v0, $at
/* 0A8BE0 7F0740B0 00004012 */  mflo  $t0
/* 0A8BE4 7F0740B4 A3A80067 */  sb    $t0, 0x67($sp)
/* 0A8BE8 7F0740B8 10000004 */  b     .L7F0740CC
/* 0A8BEC 7F0740BC 8FA40080 */   lw    $a0, 0x80($sp)
/* 0A8BF0 7F0740C0 8C780000 */  lw    $t8, ($v1)
.L7F0740C4:
/* 0A8BF4 7F0740C4 A3B80067 */  sb    $t8, 0x67($sp)
/* 0A8BF8 7F0740C8 8FA40080 */  lw    $a0, 0x80($sp)
.L7F0740CC:
/* 0A8BFC 7F0740CC AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A8C00 7F0740D0 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0A8C04 7F0740D4 E7A20040 */  swc1  $f2, 0x40($sp)
/* 0A8C08 7F0740D8 E7AC0048 */  swc1  $f12, 0x48($sp)
/* 0A8C0C 7F0740DC 0FC1B15C */  jal   modelFindNodeMtxIndex
/* 0A8C10 7F0740E0 E7AE0044 */   swc1  $f14, 0x44($sp)
/* 0A8C14 7F0740E4 8FA7007C */  lw    $a3, 0x7c($sp)
/* 0A8C18 7F0740E8 00024980 */  sll   $t1, $v0, 6
/* 0A8C1C 7F0740EC 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A8C20 7F0740F0 8CF9000C */  lw    $t9, 0xc($a3)
/* 0A8C24 7F0740F4 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 0A8C28 7F0740F8 C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 0A8C2C 7F0740FC 03295021 */  addu  $t2, $t9, $t1
/* 0A8C30 7F074100 AFAA0070 */  sw    $t2, 0x70($sp)
/* 0A8C34 7F074104 8E0B0004 */  lw    $t3, 4($s0)
/* 0A8C38 7F074108 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0A8C3C 7F07410C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0A8C40 7F074110 1160000B */  beqz  $t3, .L7F074140
/* 0A8C44 7F074114 3C028003 */   lui   $v0, %hi(vtxallocator)
/* 0A8C48 7F074118 44814000 */  mtc1  $at, $f8
/* 0A8C4C 7F07411C C4F20014 */  lwc1  $f18, 0x14($a3)
/* 0A8C50 7F074120 46024281 */  sub.s $f10, $f8, $f2
/* 0A8C54 7F074124 46125103 */  div.s $f4, $f10, $f18
/* 0A8C58 7F074128 4600218D */  trunc.w.s $f6, $f4
/* 0A8C5C 7F07412C 44033000 */  mfc1  $v1, $f6
/* 0A8C60 7F074130 00000000 */  nop   
/* 0A8C64 7F074134 00036C00 */  sll   $t5, $v1, 0x10
/* 0A8C68 7F074138 10000009 */  b     .L7F074160
/* 0A8C6C 7F07413C 000D1C03 */   sra   $v1, $t5, 0x10
.L7F074140:
/* 0A8C70 7F074140 C4EA0014 */  lwc1  $f10, 0x14($a3)
/* 0A8C74 7F074144 46001207 */  neg.s $f8, $f2
/* 0A8C78 7F074148 460A4483 */  div.s $f18, $f8, $f10
/* 0A8C7C 7F07414C 4600910D */  trunc.w.s $f4, $f18
/* 0A8C80 7F074150 44032000 */  mfc1  $v1, $f4
/* 0A8C84 7F074154 00000000 */  nop   
/* 0A8C88 7F074158 00034400 */  sll   $t0, $v1, 0x10
/* 0A8C8C 7F07415C 00081C03 */  sra   $v1, $t0, 0x10
.L7F074160:
/* 0A8C90 7F074160 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0A8C94 7F074164 44813000 */  mtc1  $at, $f6
/* 0A8C98 7F074168 3C048005 */  lui   $a0, %hi(aDoshadowNoVtxAllocator)
/* 0A8C9C 7F07416C 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0A8CA0 7F074170 4606103C */  c.lt.s $f2, $f6
/* 0A8CA4 7F074174 24844A94 */  addiu $a0, %lo(aDoshadowNoVtxAllocator) # addiu $a0, $a0, 0x4a94
/* 0A8CA8 7F074178 4502000A */  bc1fl .L7F0741A4
/* 0A8CAC 7F07417C 44818000 */   mtc1  $at, $f16
/* 0A8CB0 7F074180 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0A8CB4 7F074184 44810000 */  mtc1  $at, $f0
/* 0A8CB8 7F074188 00000000 */  nop   
/* 0A8CBC 7F07418C 46006302 */  mul.s $f12, $f12, $f0
/* 0A8CC0 7F074190 00000000 */  nop   
/* 0A8CC4 7F074194 46007382 */  mul.s $f14, $f14, $f0
/* 0A8CC8 7F074198 10000012 */  b     .L7F0741E4
/* 0A8CCC 7F07419C 00000000 */   nop   
/* 0A8CD0 7F0741A0 44818000 */  mtc1  $at, $f16
.L7F0741A4:
/* 0A8CD4 7F0741A4 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0A8CD8 7F0741A8 4602803C */  c.lt.s $f16, $f2
/* 0A8CDC 7F0741AC 00000000 */  nop   
/* 0A8CE0 7F0741B0 45020005 */  bc1fl .L7F0741C8
/* 0A8CE4 7F0741B4 46028201 */   sub.s $f8, $f16, $f2
/* 0A8CE8 7F0741B8 44807000 */  mtc1  $zero, $f14
/* 0A8CEC 7F0741BC 10000009 */  b     .L7F0741E4
/* 0A8CF0 7F0741C0 46007306 */   mov.s $f12, $f14
/* 0A8CF4 7F0741C4 46028201 */  sub.s $f8, $f16, $f2
.L7F0741C8:
/* 0A8CF8 7F0741C8 44815000 */  mtc1  $at, $f10
/* 0A8CFC 7F0741CC 00000000 */  nop   
/* 0A8D00 7F0741D0 460A4003 */  div.s $f0, $f8, $f10
/* 0A8D04 7F0741D4 46006302 */  mul.s $f12, $f12, $f0
/* 0A8D08 7F0741D8 00000000 */  nop   
/* 0A8D0C 7F0741DC 46007382 */  mul.s $f14, $f14, $f0
/* 0A8D10 7F0741E0 00000000 */  nop   
.L7F0741E4:
/* 0A8D14 7F0741E4 8C42608C */  lw    $v0, %lo(vtxallocator)($v0)
/* 0A8D18 7F0741E8 5440000F */  bnezl $v0, .L7F074228
/* 0A8D1C 7F0741EC 24040004 */   li    $a0, 4
/* 0A8D20 7F0741F0 A7A30052 */  sh    $v1, 0x52($sp)
/* 0A8D24 7F0741F4 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A8D28 7F0741F8 E7AC0048 */  swc1  $f12, 0x48($sp)
/* 0A8D2C 7F0741FC 0C0033D1 */  jal   osSyncPrintf
/* 0A8D30 7F074200 E7AE0044 */   swc1  $f14, 0x44($sp)
/* 0A8D34 7F074204 0FC1B11B */  jal   return_null
/* 0A8D38 7F074208 00000000 */   nop   
/* 0A8D3C 7F07420C 3C028003 */  lui   $v0, %hi(vtxallocator)
/* 0A8D40 7F074210 8C42608C */  lw    $v0, %lo(vtxallocator)($v0)
/* 0A8D44 7F074214 87A30052 */  lh    $v1, 0x52($sp)
/* 0A8D48 7F074218 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A8D4C 7F07421C C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 0A8D50 7F074220 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0A8D54 7F074224 24040004 */  li    $a0, 4
.L7F074228:
/* 0A8D58 7F074228 A7A30052 */  sh    $v1, 0x52($sp)
/* 0A8D5C 7F07422C AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A8D60 7F074230 E7AC0048 */  swc1  $f12, 0x48($sp)
/* 0A8D64 7F074234 0040F809 */  jalr  $v0
/* 0A8D68 7F074238 E7AE0044 */  swc1  $f14, 0x44($sp)
/* 0A8D6C 7F07423C 27A40058 */  addiu $a0, $sp, 0x58
/* 0A8D70 7F074240 8C810000 */  lw    $at, ($a0)
/* 0A8D74 7F074244 87A30052 */  lh    $v1, 0x52($sp)
/* 0A8D78 7F074248 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A8D7C 7F07424C C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 0A8D80 7F074250 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0A8D84 7F074254 AC410000 */  sw    $at, ($v0)
/* 0A8D88 7F074258 8C8A0004 */  lw    $t2, 4($a0)
/* 0A8D8C 7F07425C AC4A0004 */  sw    $t2, 4($v0)
/* 0A8D90 7F074260 8C810008 */  lw    $at, 8($a0)
/* 0A8D94 7F074264 AC410008 */  sw    $at, 8($v0)
/* 0A8D98 7F074268 8C8A000C */  lw    $t2, 0xc($a0)
/* 0A8D9C 7F07426C AC4A000C */  sw    $t2, 0xc($v0)
/* 0A8DA0 7F074270 8C810000 */  lw    $at, ($a0)
/* 0A8DA4 7F074274 AC410010 */  sw    $at, 0x10($v0)
/* 0A8DA8 7F074278 8C8D0004 */  lw    $t5, 4($a0)
/* 0A8DAC 7F07427C AC4D0014 */  sw    $t5, 0x14($v0)
/* 0A8DB0 7F074280 8C810008 */  lw    $at, 8($a0)
/* 0A8DB4 7F074284 AC410018 */  sw    $at, 0x18($v0)
/* 0A8DB8 7F074288 8C8D000C */  lw    $t5, 0xc($a0)
/* 0A8DBC 7F07428C AC4D001C */  sw    $t5, 0x1c($v0)
/* 0A8DC0 7F074290 8C810000 */  lw    $at, ($a0)
/* 0A8DC4 7F074294 AC410020 */  sw    $at, 0x20($v0)
/* 0A8DC8 7F074298 8C880004 */  lw    $t0, 4($a0)
/* 0A8DCC 7F07429C AC480024 */  sw    $t0, 0x24($v0)
/* 0A8DD0 7F0742A0 8C810008 */  lw    $at, 8($a0)
/* 0A8DD4 7F0742A4 AC410028 */  sw    $at, 0x28($v0)
/* 0A8DD8 7F0742A8 8C88000C */  lw    $t0, 0xc($a0)
/* 0A8DDC 7F0742AC AC48002C */  sw    $t0, 0x2c($v0)
/* 0A8DE0 7F0742B0 8C810000 */  lw    $at, ($a0)
/* 0A8DE4 7F0742B4 AC410030 */  sw    $at, 0x30($v0)
/* 0A8DE8 7F0742B8 8C990004 */  lw    $t9, 4($a0)
/* 0A8DEC 7F0742BC AC590034 */  sw    $t9, 0x34($v0)
/* 0A8DF0 7F0742C0 8C810008 */  lw    $at, 8($a0)
/* 0A8DF4 7F0742C4 AC410038 */  sw    $at, 0x38($v0)
/* 0A8DF8 7F0742C8 8C99000C */  lw    $t9, 0xc($a0)
/* 0A8DFC 7F0742CC AC59003C */  sw    $t9, 0x3c($v0)
/* 0A8E00 7F0742D0 C4D20000 */  lwc1  $f18, ($a2)
/* 0A8E04 7F0742D4 A4430002 */  sh    $v1, 2($v0)
/* 0A8E08 7F0742D8 460C9101 */  sub.s $f4, $f18, $f12
/* 0A8E0C 7F0742DC 4600218D */  trunc.w.s $f6, $f4
/* 0A8E10 7F0742E0 440C3000 */  mfc1  $t4, $f6
/* 0A8E14 7F0742E4 00000000 */  nop   
/* 0A8E18 7F0742E8 A44C0000 */  sh    $t4, ($v0)
/* 0A8E1C 7F0742EC C4C80004 */  lwc1  $f8, 4($a2)
/* 0A8E20 7F0742F0 460E4281 */  sub.s $f10, $f8, $f14
/* 0A8E24 7F0742F4 4600548D */  trunc.w.s $f18, $f10
/* 0A8E28 7F0742F8 440D9000 */  mfc1  $t5, $f18
/* 0A8E2C 7F0742FC 00000000 */  nop   
/* 0A8E30 7F074300 A44D0004 */  sh    $t5, 4($v0)
/* 0A8E34 7F074304 C4C40000 */  lwc1  $f4, ($a2)
/* 0A8E38 7F074308 A4430012 */  sh    $v1, 0x12($v0)
/* 0A8E3C 7F07430C 460C2181 */  sub.s $f6, $f4, $f12
/* 0A8E40 7F074310 4600320D */  trunc.w.s $f8, $f6
/* 0A8E44 7F074314 440E4000 */  mfc1  $t6, $f8
/* 0A8E48 7F074318 00000000 */  nop   
/* 0A8E4C 7F07431C A44E0010 */  sh    $t6, 0x10($v0)
/* 0A8E50 7F074320 C4CA0004 */  lwc1  $f10, 4($a2)
/* 0A8E54 7F074324 460E5480 */  add.s $f18, $f10, $f14
/* 0A8E58 7F074328 4600910D */  trunc.w.s $f4, $f18
/* 0A8E5C 7F07432C 44092000 */  mfc1  $t1, $f4
/* 0A8E60 7F074330 00000000 */  nop   
/* 0A8E64 7F074334 A4490014 */  sh    $t1, 0x14($v0)
/* 0A8E68 7F074338 C4C60000 */  lwc1  $f6, ($a2)
/* 0A8E6C 7F07433C A4430022 */  sh    $v1, 0x22($v0)
/* 0A8E70 7F074340 3C09BC00 */  lui   $t1, (0xBC001406 >> 16) # lui $t1, 0xbc00
/* 0A8E74 7F074344 460C3200 */  add.s $f8, $f6, $f12
/* 0A8E78 7F074348 35291406 */  ori   $t1, (0xBC001406 & 0xFFFF) # ori $t1, $t1, 0x1406
/* 0A8E7C 7F07434C 4600428D */  trunc.w.s $f10, $f8
/* 0A8E80 7F074350 44195000 */  mfc1  $t9, $f10
/* 0A8E84 7F074354 00000000 */  nop   
/* 0A8E88 7F074358 A4590020 */  sh    $t9, 0x20($v0)
/* 0A8E8C 7F07435C C4D20004 */  lwc1  $f18, 4($a2)
/* 0A8E90 7F074360 460E9100 */  add.s $f4, $f18, $f14
/* 0A8E94 7F074364 4600218D */  trunc.w.s $f6, $f4
/* 0A8E98 7F074368 440C3000 */  mfc1  $t4, $f6
/* 0A8E9C 7F07436C 00000000 */  nop   
/* 0A8EA0 7F074370 A44C0024 */  sh    $t4, 0x24($v0)
/* 0A8EA4 7F074374 C4C80000 */  lwc1  $f8, ($a2)
/* 0A8EA8 7F074378 A4430032 */  sh    $v1, 0x32($v0)
/* 0A8EAC 7F07437C 460C4280 */  add.s $f10, $f8, $f12
/* 0A8EB0 7F074380 4600548D */  trunc.w.s $f18, $f10
/* 0A8EB4 7F074384 440D9000 */  mfc1  $t5, $f18
/* 0A8EB8 7F074388 00000000 */  nop   
/* 0A8EBC 7F07438C A44D0030 */  sh    $t5, 0x30($v0)
/* 0A8EC0 7F074390 C4C40004 */  lwc1  $f4, 4($a2)
/* 0A8EC4 7F074394 460E2181 */  sub.s $f6, $f4, $f14
/* 0A8EC8 7F074398 4600320D */  trunc.w.s $f8, $f6
/* 0A8ECC 7F07439C 440E4000 */  mfc1  $t6, $f8
/* 0A8ED0 7F0743A0 00000000 */  nop   
/* 0A8ED4 7F0743A4 A44E0034 */  sh    $t6, 0x34($v0)
/* 0A8ED8 7F0743A8 8E03000C */  lw    $v1, 0xc($s0)
/* 0A8EDC 7F0743AC 24680008 */  addiu $t0, $v1, 8
/* 0A8EE0 7F0743B0 AE08000C */  sw    $t0, 0xc($s0)
/* 0A8EE4 7F0743B4 AC690000 */  sw    $t1, ($v1)
/* 0A8EE8 7F0743B8 8CC4001C */  lw    $a0, 0x1c($a2)
/* 0A8EEC 7F0743BC AFA20054 */  sw    $v0, 0x54($sp)
/* 0A8EF0 7F0743C0 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A8EF4 7F0743C4 0C003A2C */  jal   osVirtualToPhysical
/* 0A8EF8 7F0743C8 AFA30038 */   sw    $v1, 0x38($sp)
/* 0A8EFC 7F0743CC 8FA50038 */  lw    $a1, 0x38($sp)
/* 0A8F00 7F0743D0 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A8F04 7F0743D4 8FA70054 */  lw    $a3, 0x54($sp)
/* 0A8F08 7F0743D8 ACA20004 */  sw    $v0, 4($a1)
/* 0A8F0C 7F0743DC 8CC30010 */  lw    $v1, 0x10($a2)
/* 0A8F10 7F0743E0 24060001 */  li    $a2, 1
/* 0A8F14 7F0743E4 00002825 */  move  $a1, $zero
/* 0A8F18 7F0743E8 1060001C */  beqz  $v1, .L7F07445C
/* 0A8F1C 7F0743EC 02002025 */   move  $a0, $s0
/* 0A8F20 7F0743F0 A4E00008 */  sh    $zero, 8($a3)
/* 0A8F24 7F0743F4 A4E0000A */  sh    $zero, 0xa($a3)
/* 0A8F28 7F0743F8 90780004 */  lbu   $t8, 4($v1)
/* 0A8F2C 7F0743FC A4E0001A */  sh    $zero, 0x1a($a3)
/* 0A8F30 7F074400 00602825 */  move  $a1, $v1
/* 0A8F34 7F074404 0018C940 */  sll   $t9, $t8, 5
/* 0A8F38 7F074408 272AFFFF */  addiu $t2, $t9, -1
/* 0A8F3C 7F07440C A4EA0018 */  sh    $t2, 0x18($a3)
/* 0A8F40 7F074410 906C0004 */  lbu   $t4, 4($v1)
/* 0A8F44 7F074414 02002025 */  move  $a0, $s0
/* 0A8F48 7F074418 24060004 */  li    $a2, 4
/* 0A8F4C 7F07441C 000C5940 */  sll   $t3, $t4, 5
/* 0A8F50 7F074420 256DFFFF */  addiu $t5, $t3, -1
/* 0A8F54 7F074424 A4ED0028 */  sh    $t5, 0x28($a3)
/* 0A8F58 7F074428 906F0005 */  lbu   $t7, 5($v1)
/* 0A8F5C 7F07442C A4E00038 */  sh    $zero, 0x38($a3)
/* 0A8F60 7F074430 000F7140 */  sll   $t6, $t7, 5
/* 0A8F64 7F074434 25C8FFFF */  addiu $t0, $t6, -1
/* 0A8F68 7F074438 A4E8002A */  sh    $t0, 0x2a($a3)
/* 0A8F6C 7F07443C 90690005 */  lbu   $t1, 5($v1)
/* 0A8F70 7F074440 0009C140 */  sll   $t8, $t1, 5
/* 0A8F74 7F074444 2719FFFF */  addiu $t9, $t8, -1
/* 0A8F78 7F074448 A4F9003A */  sh    $t9, 0x3a($a3)
/* 0A8F7C 7F07444C 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8F80 7F074450 AFA70054 */   sw    $a3, 0x54($sp)
/* 0A8F84 7F074454 10000004 */  b     .L7F074468
/* 0A8F88 7F074458 8FA70054 */   lw    $a3, 0x54($sp)
.L7F07445C:
/* 0A8F8C 7F07445C 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8F90 7F074460 AFA70054 */   sw    $a3, 0x54($sp)
/* 0A8F94 7F074464 8FA70054 */  lw    $a3, 0x54($sp)
.L7F074468:
/* 0A8F98 7F074468 8E03000C */  lw    $v1, 0xc($s0)
/* 0A8F9C 7F07446C 3C0CB700 */  lui   $t4, 0xb700
/* 0A8FA0 7F074470 240B2000 */  li    $t3, 8192
/* 0A8FA4 7F074474 246A0008 */  addiu $t2, $v1, 8
/* 0A8FA8 7F074478 AE0A000C */  sw    $t2, 0xc($s0)
/* 0A8FAC 7F07447C AC6C0000 */  sw    $t4, ($v1)
/* 0A8FB0 7F074480 AC6B0004 */  sw    $t3, 4($v1)
/* 0A8FB4 7F074484 8E03000C */  lw    $v1, 0xc($s0)
/* 0A8FB8 7F074488 3C0F0102 */  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
/* 0A8FBC 7F07448C 35EF0040 */  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0A8FC0 7F074490 246D0008 */  addiu $t5, $v1, 8
/* 0A8FC4 7F074494 AE0D000C */  sw    $t5, 0xc($s0)
/* 0A8FC8 7F074498 AC6F0000 */  sw    $t7, ($v1)
/* 0A8FCC 7F07449C AFA70054 */  sw    $a3, 0x54($sp)
/* 0A8FD0 7F0744A0 8FA40070 */  lw    $a0, 0x70($sp)
/* 0A8FD4 7F0744A4 0C003A2C */  jal   osVirtualToPhysical
/* 0A8FD8 7F0744A8 AFA3002C */   sw    $v1, 0x2c($sp)
/* 0A8FDC 7F0744AC 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0A8FE0 7F0744B0 8FA40054 */  lw    $a0, 0x54($sp)
/* 0A8FE4 7F0744B4 3C080430 */  lui   $t0, (0x04300040 >> 16) # lui $t0, 0x430
/* 0A8FE8 7F0744B8 ACA20004 */  sw    $v0, 4($a1)
/* 0A8FEC 7F0744BC 8E03000C */  lw    $v1, 0xc($s0)
/* 0A8FF0 7F0744C0 35080040 */  ori   $t0, (0x04300040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0A8FF4 7F0744C4 246E0008 */  addiu $t6, $v1, 8
/* 0A8FF8 7F0744C8 AE0E000C */  sw    $t6, 0xc($s0)
/* 0A8FFC 7F0744CC AC680000 */  sw    $t0, ($v1)
/* 0A9000 7F0744D0 0C003A2C */  jal   osVirtualToPhysical
/* 0A9004 7F0744D4 AFA30028 */   sw    $v1, 0x28($sp)
/* 0A9008 7F0744D8 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A900C 7F0744DC 3C18B100 */  lui   $t8, (0xB1000002 >> 16) # lui $t8, 0xb100
/* 0A9010 7F0744E0 37180002 */  ori   $t8, (0xB1000002 & 0xFFFF) # ori $t8, $t8, 2
/* 0A9014 7F0744E4 ACC20004 */  sw    $v0, 4($a2)
/* 0A9018 7F0744E8 8E03000C */  lw    $v1, 0xc($s0)
/* 0A901C 7F0744EC 24193210 */  li    $t9, 12816
/* 0A9020 7F0744F0 24690008 */  addiu $t1, $v1, 8
/* 0A9024 7F0744F4 AE09000C */  sw    $t1, 0xc($s0)
/* 0A9028 7F0744F8 AC790004 */  sw    $t9, 4($v1)
/* 0A902C 7F0744FC AC780000 */  sw    $t8, ($v1)
.L7F074500:
/* 0A9030 7F074500 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A9034 7F074504 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A9038 7F074508 27BD0078 */  addiu $sp, $sp, 0x78
/* 0A903C 7F07450C 03E00008 */  jr    $ra
/* 0A9040 7F074510 00000000 */   nop   
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel doshadow
/* 0A6AD8 7F0740E8 3C038003 */  lui   $v1, %hi(D_800363F0) # $v1, 0x8003
/* 0A6ADC 7F0740EC 24631940 */  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x1940
/* 0A6AE0 7F0740F0 8C6E0000 */  lw    $t6, ($v1)
/* 0A6AE4 7F0740F4 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0A6AE8 7F0740F8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A6AEC 7F0740FC 00808025 */  move  $s0, $a0
/* 0A6AF0 7F074100 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A6AF4 7F074104 AFA60080 */  sw    $a2, 0x80($sp)
/* 0A6AF8 7F074108 19C00132 */  blez  $t6, .L7F0745D4
/* 0A6AFC 7F07410C 00A03825 */   move  $a3, $a1
/* 0A6B00 7F074110 3C198003 */  lui   $t9, %hi(D_800363F8) # $t9, 0x8003
/* 0A6B04 7F074114 27391948 */  addiu $t9, %lo(D_800363F8) # addiu $t9, $t9, 0x1948
/* 0A6B08 7F074118 8F210000 */  lw    $at, ($t9)
/* 0A6B0C 7F07411C 8F2A0004 */  lw    $t2, 4($t9)
/* 0A6B10 7F074120 8CC60004 */  lw    $a2, 4($a2)
/* 0A6B14 7F074124 27B80058 */  addiu $t8, $sp, 0x58
/* 0A6B18 7F074128 AF010000 */  sw    $at, ($t8)
/* 0A6B1C 7F07412C AF0A0004 */  sw    $t2, 4($t8)
/* 0A6B20 7F074130 8F2A000C */  lw    $t2, 0xc($t9)
/* 0A6B24 7F074134 8F210008 */  lw    $at, 8($t9)
/* 0A6B28 7F074138 00A02025 */  move  $a0, $a1
/* 0A6B2C 7F07413C AF0A000C */  sw    $t2, 0xc($t8)
/* 0A6B30 7F074140 AF010008 */  sw    $at, 8($t8)
/* 0A6B34 7F074144 8CC50014 */  lw    $a1, 0x14($a2)
/* 0A6B38 7F074148 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0A6B3C 7F07414C 0FC1B3A3 */  jal   modelGetNodeRwData
/* 0A6B40 7F074150 AFA6006C */   sw    $a2, 0x6c($sp)
/* 0A6B44 7F074154 8E0B0008 */  lw    $t3, 8($s0)
/* 0A6B48 7F074158 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A6B4C 7F07415C C444000C */  lwc1  $f4, 0xc($v0)
/* 0A6B50 7F074160 C4460004 */  lwc1  $f6, 4($v0)
/* 0A6B54 7F074164 3C038003 */  lui   $v1, %hi(D_800363F0) # $v1, 0x8003
/* 0A6B58 7F074168 316C0002 */  andi  $t4, $t3, 2
/* 0A6B5C 7F07416C 24631940 */  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x1940
/* 0A6B60 7F074170 8FA7007C */  lw    $a3, 0x7c($sp)
/* 0A6B64 7F074174 C4C20008 */  lwc1  $f2, 8($a2)
/* 0A6B68 7F074178 C4CC000C */  lwc1  $f12, 0xc($a2)
/* 0A6B6C 7F07417C 11800115 */  beqz  $t4, .L7F0745D4
/* 0A6B70 7F074180 46062381 */   sub.s $f14, $f4, $f6
/* 0A6B74 7F074184 8E020030 */  lw    $v0, 0x30($s0)
/* 0A6B78 7F074188 24010003 */  li    $at, 3
/* 0A6B7C 7F07418C 00002825 */  move  $a1, $zero
/* 0A6B80 7F074190 10410003 */  beq   $v0, $at, .L7F0741A0
/* 0A6B84 7F074194 24010008 */   li    $at, 8
/* 0A6B88 7F074198 5441000F */  bnel  $v0, $at, .L7F0741D8
/* 0A6B8C 7F07419C 8C790000 */   lw    $t9, ($v1)
.L7F0741A0:
/* 0A6B90 7F0741A0 8E0D0034 */  lw    $t5, 0x34($s0)
/* 0A6B94 7F0741A4 8C6F0000 */  lw    $t7, ($v1)
/* 0A6B98 7F0741A8 240100FF */  li    $at, 255
/* 0A6B9C 7F0741AC 31AE00FF */  andi  $t6, $t5, 0xff
/* 0A6BA0 7F0741B0 01CF0019 */  multu $t6, $t7
/* 0A6BA4 7F0741B4 00001012 */  mflo  $v0
/* 0A6BA8 7F0741B8 00000000 */  nop   
/* 0A6BAC 7F0741BC 00000000 */  nop   
/* 0A6BB0 7F0741C0 0041001B */  divu  $zero, $v0, $at
/* 0A6BB4 7F0741C4 0000C012 */  mflo  $t8
/* 0A6BB8 7F0741C8 A3B80067 */  sb    $t8, 0x67($sp)
/* 0A6BBC 7F0741CC 10000004 */  b     .L7F0741E0
/* 0A6BC0 7F0741D0 8FA40080 */   lw    $a0, 0x80($sp)
/* 0A6BC4 7F0741D4 8C790000 */  lw    $t9, ($v1)
.L7F0741D8:
/* 0A6BC8 7F0741D8 A3B90067 */  sb    $t9, 0x67($sp)
/* 0A6BCC 7F0741DC 8FA40080 */  lw    $a0, 0x80($sp)
.L7F0741E0:
/* 0A6BD0 7F0741E0 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A6BD4 7F0741E4 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0A6BD8 7F0741E8 E7A20048 */  swc1  $f2, 0x48($sp)
/* 0A6BDC 7F0741EC E7AC0044 */  swc1  $f12, 0x44($sp)
/* 0A6BE0 7F0741F0 0FC1B32A */  jal   modelFindNodeMtxIndex
/* 0A6BE4 7F0741F4 E7AE0040 */   swc1  $f14, 0x40($sp)
/* 0A6BE8 7F0741F8 8FA7007C */  lw    $a3, 0x7c($sp)
/* 0A6BEC 7F0741FC 00025980 */  sll   $t3, $v0, 6
/* 0A6BF0 7F074200 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A6BF4 7F074204 8CEA000C */  lw    $t2, 0xc($a3)
/* 0A6BF8 7F074208 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 0A6BFC 7F07420C C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0A6C00 7F074210 014B6021 */  addu  $t4, $t2, $t3
/* 0A6C04 7F074214 AFAC0070 */  sw    $t4, 0x70($sp)
/* 0A6C08 7F074218 8E0D0004 */  lw    $t5, 4($s0)
/* 0A6C0C 7F07421C C7AE0040 */  lwc1  $f14, 0x40($sp)
/* 0A6C10 7F074220 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0A6C14 7F074224 11A0000B */  beqz  $t5, .L7F074254
/* 0A6C18 7F074228 24040004 */   li    $a0, 4
/* 0A6C1C 7F07422C 44814000 */  mtc1  $at, $f8
/* 0A6C20 7F074230 C4F20014 */  lwc1  $f18, 0x14($a3)
/* 0A6C24 7F074234 460E4281 */  sub.s $f10, $f8, $f14
/* 0A6C28 7F074238 46125103 */  div.s $f4, $f10, $f18
/* 0A6C2C 7F07423C 4600218D */  trunc.w.s $f6, $f4
/* 0A6C30 7F074240 44033000 */  mfc1  $v1, $f6
/* 0A6C34 7F074244 00000000 */  nop   
/* 0A6C38 7F074248 00037C00 */  sll   $t7, $v1, 0x10
/* 0A6C3C 7F07424C 10000009 */  b     .L7F074274
/* 0A6C40 7F074250 000F1C03 */   sra   $v1, $t7, 0x10
.L7F074254:
/* 0A6C44 7F074254 C4EA0014 */  lwc1  $f10, 0x14($a3)
/* 0A6C48 7F074258 46007207 */  neg.s $f8, $f14
/* 0A6C4C 7F07425C 460A4483 */  div.s $f18, $f8, $f10
/* 0A6C50 7F074260 4600910D */  trunc.w.s $f4, $f18
/* 0A6C54 7F074264 44032000 */  mfc1  $v1, $f4
/* 0A6C58 7F074268 00000000 */  nop   
/* 0A6C5C 7F07426C 0003CC00 */  sll   $t9, $v1, 0x10
/* 0A6C60 7F074270 00191C03 */  sra   $v1, $t9, 0x10
.L7F074274:
/* 0A6C64 7F074274 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0A6C68 7F074278 44813000 */  mtc1  $at, $f6
/* 0A6C6C 7F07427C 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0A6C70 7F074280 3C198003 */  lui   $t9, %hi(vtxallocator) # $t9, 0x8003
/* 0A6C74 7F074284 4606703C */  c.lt.s $f14, $f6
/* 0A6C78 7F074288 00000000 */  nop   
/* 0A6C7C 7F07428C 4502000A */  bc1fl .L7F0742B8
/* 0A6C80 7F074290 44818000 */   mtc1  $at, $f16
/* 0A6C84 7F074294 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0A6C88 7F074298 44810000 */  mtc1  $at, $f0
/* 0A6C8C 7F07429C 00000000 */  nop   
/* 0A6C90 7F0742A0 46001082 */  mul.s $f2, $f2, $f0
/* 0A6C94 7F0742A4 00000000 */  nop   
/* 0A6C98 7F0742A8 46006302 */  mul.s $f12, $f12, $f0
/* 0A6C9C 7F0742AC 10000012 */  b     .L7F0742F8
/* 0A6CA0 7F0742B0 00000000 */   nop   
/* 0A6CA4 7F0742B4 44818000 */  mtc1  $at, $f16
.L7F0742B8:
/* 0A6CA8 7F0742B8 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0A6CAC 7F0742BC 460E803C */  c.lt.s $f16, $f14
/* 0A6CB0 7F0742C0 00000000 */  nop   
/* 0A6CB4 7F0742C4 45020005 */  bc1fl .L7F0742DC
/* 0A6CB8 7F0742C8 460E8201 */   sub.s $f8, $f16, $f14
/* 0A6CBC 7F0742CC 44806000 */  mtc1  $zero, $f12
/* 0A6CC0 7F0742D0 10000009 */  b     .L7F0742F8
/* 0A6CC4 7F0742D4 46006086 */   mov.s $f2, $f12
/* 0A6CC8 7F0742D8 460E8201 */  sub.s $f8, $f16, $f14
.L7F0742DC:
/* 0A6CCC 7F0742DC 44815000 */  mtc1  $at, $f10
/* 0A6CD0 7F0742E0 00000000 */  nop   
/* 0A6CD4 7F0742E4 460A4003 */  div.s $f0, $f8, $f10
/* 0A6CD8 7F0742E8 46001082 */  mul.s $f2, $f2, $f0
/* 0A6CDC 7F0742EC 00000000 */  nop   
/* 0A6CE0 7F0742F0 46006302 */  mul.s $f12, $f12, $f0
/* 0A6CE4 7F0742F4 00000000 */  nop   
.L7F0742F8:
/* 0A6CE8 7F0742F8 8F3915DC */  lw    $t9, %lo(vtxallocator)($t9)
/* 0A6CEC 7F0742FC A7A30052 */  sh    $v1, 0x52($sp)
/* 0A6CF0 7F074300 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A6CF4 7F074304 E7A20048 */  swc1  $f2, 0x48($sp)
/* 0A6CF8 7F074308 0320F809 */  jalr  $t9
/* 0A6CFC 7F07430C E7AC0044 */  swc1  $f12, 0x44($sp)
/* 0A6D00 7F074310 27A80058 */  addiu $t0, $sp, 0x58
/* 0A6D04 7F074314 8D010000 */  lw    $at, ($t0)
/* 0A6D08 7F074318 87A30052 */  lh    $v1, 0x52($sp)
/* 0A6D0C 7F07431C 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A6D10 7F074320 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 0A6D14 7F074324 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0A6D18 7F074328 AC410000 */  sw    $at, ($v0)
/* 0A6D1C 7F07432C 8D0D0004 */  lw    $t5, 4($t0)
/* 0A6D20 7F074330 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6D24 7F074334 8D010008 */  lw    $at, 8($t0)
/* 0A6D28 7F074338 AC410008 */  sw    $at, 8($v0)
/* 0A6D2C 7F07433C 8D0D000C */  lw    $t5, 0xc($t0)
/* 0A6D30 7F074340 AC4D000C */  sw    $t5, 0xc($v0)
/* 0A6D34 7F074344 8D010000 */  lw    $at, ($t0)
/* 0A6D38 7F074348 AC410010 */  sw    $at, 0x10($v0)
/* 0A6D3C 7F07434C 8D090004 */  lw    $t1, 4($t0)
/* 0A6D40 7F074350 AC490014 */  sw    $t1, 0x14($v0)
/* 0A6D44 7F074354 8D010008 */  lw    $at, 8($t0)
/* 0A6D48 7F074358 AC410018 */  sw    $at, 0x18($v0)
/* 0A6D4C 7F07435C 8D09000C */  lw    $t1, 0xc($t0)
/* 0A6D50 7F074360 AC49001C */  sw    $t1, 0x1c($v0)
/* 0A6D54 7F074364 8D010000 */  lw    $at, ($t0)
/* 0A6D58 7F074368 AC410020 */  sw    $at, 0x20($v0)
/* 0A6D5C 7F07436C 8D190004 */  lw    $t9, 4($t0)
/* 0A6D60 7F074370 AC590024 */  sw    $t9, 0x24($v0)
/* 0A6D64 7F074374 8D010008 */  lw    $at, 8($t0)
/* 0A6D68 7F074378 AC410028 */  sw    $at, 0x28($v0)
/* 0A6D6C 7F07437C 8D19000C */  lw    $t9, 0xc($t0)
/* 0A6D70 7F074380 AC59002C */  sw    $t9, 0x2c($v0)
/* 0A6D74 7F074384 8D010000 */  lw    $at, ($t0)
/* 0A6D78 7F074388 AC410030 */  sw    $at, 0x30($v0)
/* 0A6D7C 7F07438C 8D0D0004 */  lw    $t5, 4($t0)
/* 0A6D80 7F074390 AC4D0034 */  sw    $t5, 0x34($v0)
/* 0A6D84 7F074394 8D010008 */  lw    $at, 8($t0)
/* 0A6D88 7F074398 AC410038 */  sw    $at, 0x38($v0)
/* 0A6D8C 7F07439C 8D0D000C */  lw    $t5, 0xc($t0)
/* 0A6D90 7F0743A0 AC4D003C */  sw    $t5, 0x3c($v0)
/* 0A6D94 7F0743A4 C4D20000 */  lwc1  $f18, ($a2)
/* 0A6D98 7F0743A8 A4430002 */  sh    $v1, 2($v0)
/* 0A6D9C 7F0743AC 3C0DBC00 */  lui   $t5, (0xBC001406 >> 16) # lui $t5, 0xbc00
/* 0A6DA0 7F0743B0 46029101 */  sub.s $f4, $f18, $f2
/* 0A6DA4 7F0743B4 35AD1406 */  ori   $t5, (0xBC001406 & 0xFFFF) # ori $t5, $t5, 0x1406
/* 0A6DA8 7F0743B8 4600218D */  trunc.w.s $f6, $f4
/* 0A6DAC 7F0743BC 440E3000 */  mfc1  $t6, $f6
/* 0A6DB0 7F0743C0 00000000 */  nop   
/* 0A6DB4 7F0743C4 A44E0000 */  sh    $t6, ($v0)
/* 0A6DB8 7F0743C8 C4C80004 */  lwc1  $f8, 4($a2)
/* 0A6DBC 7F0743CC 460C4281 */  sub.s $f10, $f8, $f12
/* 0A6DC0 7F0743D0 4600548D */  trunc.w.s $f18, $f10
/* 0A6DC4 7F0743D4 440A9000 */  mfc1  $t2, $f18
/* 0A6DC8 7F0743D8 00000000 */  nop   
/* 0A6DCC 7F0743DC A44A0004 */  sh    $t2, 4($v0)
/* 0A6DD0 7F0743E0 C4C40000 */  lwc1  $f4, ($a2)
/* 0A6DD4 7F0743E4 A4430012 */  sh    $v1, 0x12($v0)
/* 0A6DD8 7F0743E8 46022181 */  sub.s $f6, $f4, $f2
/* 0A6DDC 7F0743EC 4600320D */  trunc.w.s $f8, $f6
/* 0A6DE0 7F0743F0 44194000 */  mfc1  $t9, $f8
/* 0A6DE4 7F0743F4 00000000 */  nop   
/* 0A6DE8 7F0743F8 A4590010 */  sh    $t9, 0x10($v0)
/* 0A6DEC 7F0743FC C4CA0004 */  lwc1  $f10, 4($a2)
/* 0A6DF0 7F074400 460C5480 */  add.s $f18, $f10, $f12
/* 0A6DF4 7F074404 4600910D */  trunc.w.s $f4, $f18
/* 0A6DF8 7F074408 440C2000 */  mfc1  $t4, $f4
/* 0A6DFC 7F07440C 00000000 */  nop   
/* 0A6E00 7F074410 A44C0014 */  sh    $t4, 0x14($v0)
/* 0A6E04 7F074414 C4C60000 */  lwc1  $f6, ($a2)
/* 0A6E08 7F074418 A4430022 */  sh    $v1, 0x22($v0)
/* 0A6E0C 7F07441C 46023200 */  add.s $f8, $f6, $f2
/* 0A6E10 7F074420 4600428D */  trunc.w.s $f10, $f8
/* 0A6E14 7F074424 440F5000 */  mfc1  $t7, $f10
/* 0A6E18 7F074428 00000000 */  nop   
/* 0A6E1C 7F07442C A44F0020 */  sh    $t7, 0x20($v0)
/* 0A6E20 7F074430 C4D20004 */  lwc1  $f18, 4($a2)
/* 0A6E24 7F074434 460C9100 */  add.s $f4, $f18, $f12
/* 0A6E28 7F074438 4600218D */  trunc.w.s $f6, $f4
/* 0A6E2C 7F07443C 44093000 */  mfc1  $t1, $f6
/* 0A6E30 7F074440 00000000 */  nop   
/* 0A6E34 7F074444 A4490024 */  sh    $t1, 0x24($v0)
/* 0A6E38 7F074448 C4C80000 */  lwc1  $f8, ($a2)
/* 0A6E3C 7F07444C A4430032 */  sh    $v1, 0x32($v0)
/* 0A6E40 7F074450 46024280 */  add.s $f10, $f8, $f2
/* 0A6E44 7F074454 4600548D */  trunc.w.s $f18, $f10
/* 0A6E48 7F074458 44189000 */  mfc1  $t8, $f18
/* 0A6E4C 7F07445C 00000000 */  nop   
/* 0A6E50 7F074460 A4580030 */  sh    $t8, 0x30($v0)
/* 0A6E54 7F074464 C4C40004 */  lwc1  $f4, 4($a2)
/* 0A6E58 7F074468 460C2181 */  sub.s $f6, $f4, $f12
/* 0A6E5C 7F07446C 4600320D */  trunc.w.s $f8, $f6
/* 0A6E60 7F074470 440B4000 */  mfc1  $t3, $f8
/* 0A6E64 7F074474 00000000 */  nop   
/* 0A6E68 7F074478 A44B0034 */  sh    $t3, 0x34($v0)
/* 0A6E6C 7F07447C 8E03000C */  lw    $v1, 0xc($s0)
/* 0A6E70 7F074480 246C0008 */  addiu $t4, $v1, 8
/* 0A6E74 7F074484 AE0C000C */  sw    $t4, 0xc($s0)
/* 0A6E78 7F074488 AC6D0000 */  sw    $t5, ($v1)
/* 0A6E7C 7F07448C 8CC4001C */  lw    $a0, 0x1c($a2)
/* 0A6E80 7F074490 AFA20054 */  sw    $v0, 0x54($sp)
/* 0A6E84 7F074494 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A6E88 7F074498 0C003838 */  jal   osVirtualToPhysical
/* 0A6E8C 7F07449C AFA30038 */   sw    $v1, 0x38($sp)
/* 0A6E90 7F0744A0 8FA50038 */  lw    $a1, 0x38($sp)
/* 0A6E94 7F0744A4 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0A6E98 7F0744A8 8FA70054 */  lw    $a3, 0x54($sp)
/* 0A6E9C 7F0744AC ACA20004 */  sw    $v0, 4($a1)
/* 0A6EA0 7F0744B0 8CC30010 */  lw    $v1, 0x10($a2)
/* 0A6EA4 7F0744B4 24060001 */  li    $a2, 1
/* 0A6EA8 7F0744B8 00002825 */  move  $a1, $zero
/* 0A6EAC 7F0744BC 1060001C */  beqz  $v1, .L7F074530
/* 0A6EB0 7F0744C0 02002025 */   move  $a0, $s0
/* 0A6EB4 7F0744C4 A4E00008 */  sh    $zero, 8($a3)
/* 0A6EB8 7F0744C8 A4E0000A */  sh    $zero, 0xa($a3)
/* 0A6EBC 7F0744CC 906F0004 */  lbu   $t7, 4($v1)
/* 0A6EC0 7F0744D0 A4E0001A */  sh    $zero, 0x1a($a3)
/* 0A6EC4 7F0744D4 00602825 */  move  $a1, $v1
/* 0A6EC8 7F0744D8 000F7140 */  sll   $t6, $t7, 5
/* 0A6ECC 7F0744DC 25C9FFFF */  addiu $t1, $t6, -1
/* 0A6ED0 7F0744E0 A4E90018 */  sh    $t1, 0x18($a3)
/* 0A6ED4 7F0744E4 906A0004 */  lbu   $t2, 4($v1)
/* 0A6ED8 7F0744E8 02002025 */  move  $a0, $s0
/* 0A6EDC 7F0744EC 24060004 */  li    $a2, 4
/* 0A6EE0 7F0744F0 000AC140 */  sll   $t8, $t2, 5
/* 0A6EE4 7F0744F4 2719FFFF */  addiu $t9, $t8, -1
/* 0A6EE8 7F0744F8 A4F90028 */  sh    $t9, 0x28($a3)
/* 0A6EEC 7F0744FC 906B0005 */  lbu   $t3, 5($v1)
/* 0A6EF0 7F074500 A4E00038 */  sh    $zero, 0x38($a3)
/* 0A6EF4 7F074504 000B6140 */  sll   $t4, $t3, 5
/* 0A6EF8 7F074508 258DFFFF */  addiu $t5, $t4, -1
/* 0A6EFC 7F07450C A4ED002A */  sh    $t5, 0x2a($a3)
/* 0A6F00 7F074510 906F0005 */  lbu   $t7, 5($v1)
/* 0A6F04 7F074514 000F7140 */  sll   $t6, $t7, 5
/* 0A6F08 7F074518 25C9FFFF */  addiu $t1, $t6, -1
/* 0A6F0C 7F07451C A4E9003A */  sh    $t1, 0x3a($a3)
/* 0A6F10 7F074520 0FC1CC67 */  jal   sub_GAME_7F073038
/* 0A6F14 7F074524 AFA70054 */   sw    $a3, 0x54($sp)
/* 0A6F18 7F074528 10000004 */  b     .L7F07453C
/* 0A6F1C 7F07452C 8FA70054 */   lw    $a3, 0x54($sp)
.L7F074530:
/* 0A6F20 7F074530 0FC1CC67 */  jal   sub_GAME_7F073038
/* 0A6F24 7F074534 AFA70054 */   sw    $a3, 0x54($sp)
/* 0A6F28 7F074538 8FA70054 */  lw    $a3, 0x54($sp)
.L7F07453C:
/* 0A6F2C 7F07453C 8E03000C */  lw    $v1, 0xc($s0)
/* 0A6F30 7F074540 3C18B700 */  lui   $t8, 0xb700
/* 0A6F34 7F074544 24192000 */  li    $t9, 8192
/* 0A6F38 7F074548 246A0008 */  addiu $t2, $v1, 8
/* 0A6F3C 7F07454C AE0A000C */  sw    $t2, 0xc($s0)
/* 0A6F40 7F074550 AC780000 */  sw    $t8, ($v1)
/* 0A6F44 7F074554 AC790004 */  sw    $t9, 4($v1)
/* 0A6F48 7F074558 8E03000C */  lw    $v1, 0xc($s0)
/* 0A6F4C 7F07455C 3C0C0102 */  lui   $t4, (0x01020040 >> 16) # lui $t4, 0x102
/* 0A6F50 7F074560 358C0040 */  ori   $t4, (0x01020040 & 0xFFFF) # ori $t4, $t4, 0x40
/* 0A6F54 7F074564 246B0008 */  addiu $t3, $v1, 8
/* 0A6F58 7F074568 AE0B000C */  sw    $t3, 0xc($s0)
/* 0A6F5C 7F07456C AC6C0000 */  sw    $t4, ($v1)
/* 0A6F60 7F074570 AFA70054 */  sw    $a3, 0x54($sp)
/* 0A6F64 7F074574 8FA40070 */  lw    $a0, 0x70($sp)
/* 0A6F68 7F074578 0C003838 */  jal   osVirtualToPhysical
/* 0A6F6C 7F07457C AFA3002C */   sw    $v1, 0x2c($sp)
/* 0A6F70 7F074580 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0A6F74 7F074584 8FA40054 */  lw    $a0, 0x54($sp)
/* 0A6F78 7F074588 3C0F0430 */  lui   $t7, (0x04300040 >> 16) # lui $t7, 0x430
/* 0A6F7C 7F07458C ACA20004 */  sw    $v0, 4($a1)
/* 0A6F80 7F074590 8E03000C */  lw    $v1, 0xc($s0)
/* 0A6F84 7F074594 35EF0040 */  ori   $t7, (0x04300040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0A6F88 7F074598 246D0008 */  addiu $t5, $v1, 8
/* 0A6F8C 7F07459C AE0D000C */  sw    $t5, 0xc($s0)
/* 0A6F90 7F0745A0 AC6F0000 */  sw    $t7, ($v1)
/* 0A6F94 7F0745A4 0C003838 */  jal   osVirtualToPhysical
/* 0A6F98 7F0745A8 AFA30028 */   sw    $v1, 0x28($sp)
/* 0A6F9C 7F0745AC 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A6FA0 7F0745B0 3C09B100 */  lui   $t1, (0xB1000002 >> 16) # lui $t1, 0xb100
/* 0A6FA4 7F0745B4 35290002 */  ori   $t1, (0xB1000002 & 0xFFFF) # ori $t1, $t1, 2
/* 0A6FA8 7F0745B8 ACC20004 */  sw    $v0, 4($a2)
/* 0A6FAC 7F0745BC 8E03000C */  lw    $v1, 0xc($s0)
/* 0A6FB0 7F0745C0 240A3210 */  li    $t2, 12816
/* 0A6FB4 7F0745C4 246E0008 */  addiu $t6, $v1, 8
/* 0A6FB8 7F0745C8 AE0E000C */  sw    $t6, 0xc($s0)
/* 0A6FBC 7F0745CC AC6A0004 */  sw    $t2, 4($v1)
/* 0A6FC0 7F0745D0 AC690000 */  sw    $t1, ($v1)
.L7F0745D4:
/* 0A6FC4 7F0745D4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A6FC8 7F0745D8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A6FCC 7F0745DC 27BD0078 */  addiu $sp, $sp, 0x78
/* 0A6FD0 7F0745E0 03E00008 */  jr    $ra
/* 0A6FD4 7F0745E4 00000000 */   nop   
)
#endif
#endif





void sub_GAME_7F074514(s32 param_1,struct Model *param_2,struct ModelNode *param_3)
{
    return;
}


void sub_GAME_7F074524(Gfx *param_1,struct Model *param_2, struct ModelNode *param_3)
{
    return;
}








void sub_GAME_7F074534(ModelRenderData* data, Model* model, ModelNode* node) {
    u32 id = node->Opcode & 0xFF;
    switch (id) {
    case MODELNODE_OPCODE_LOD:
        modelApplyDistanceRelations(model, node);
        return;
    case MODELNODE_OPCODE_SWITCH:
        modelApplyToggleRelations(model, node);
        return;
    case MODELNODE_OPCODE_HEAD:
        modelApplyHeadRelations(model, node);
        return;
    case MODELNODE_OPCODE_BSP:
        modelApplyReorderRelations(model, node);
        return;
    case MODELNODE_OPCODE_OP11:
        sub_GAME_7F0737FC(data, model, node);
        return;
    case MODELNODE_OPCODE_GUNFIRE:
        dogfnegx(data, model, node);
        return;
    case MODELNODE_OPCODE_SHADOW:
        doshadow(data, model, node);
        return;
    case MODELNODE_OPCODE_BBOX:
        sub_GAME_7F074514(data, model, node);
        return;
    case MODELNODE_OPCODE_OP17:
        sub_GAME_7F074524(data, model, node);
        return;
    case MODELNODE_OPCODE_DL:
        modelRenderNodeGundl(data, node);
        return;
    case MODELNODE_OPCODE_DLCOLLISION:
        modelRenderNodeDl(data, model, node);
        return;
    case MODELNODE_OPCODE_OP20:
        sub_GAME_7F072C10(data, model, node);
        return;
    case MODELNODE_OPCODE_DLPRIMARY:
        dorottex(data, node);
        return;
    case MODELNODE_OPCODE_OP05:
        sub_GAME_7F07306C(data, model, node);
        return;
    case MODELNODE_OPCODE_OP07:
        dotube(data, model, node);
        return;
    case MODELNODE_OPCODE_OP06:
        sub_GAME_7F0737EC(data,model,node);
        return;
    case MODELNODE_OPCODE_HEADER:
    case MODELNODE_OPCODE_GROUP:
    case MODELNODE_OPCODE_OP03:
    case MODELNODE_OPCODE_OP14:
    case MODELNODE_OPCODE_INTERLINK:
    case MODELNODE_OPCODE_OP16:
    default:
        return;
    }
}





#ifdef NONMATCHING
void subdraw(void) {

}
#else
#ifndef VERSION_EU
//D:80054AB4
const char aSubdrawNoGfxlist[] = "subdraw: no gfxlist!\n";
//D:80054ACC
const char aSubdrawObjectNotInitialised0xX[] = "subdraw: object not initialised! (0x%X)\n";
GLOBAL_ASM(
.text
glabel subdraw
/* 0A91B4 7F074684 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A91B8 7F074688 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A91BC 7F07468C AFB20020 */  sw    $s2, 0x20($sp)
/* 0A91C0 7F074690 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A91C4 7F074694 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A91C8 7F074698 8C8E000C */  lw    $t6, 0xc($a0)
/* 0A91CC 7F07469C 8CA20008 */  lw    $v0, 8($a1)
/* 0A91D0 7F0746A0 00808825 */  move  $s1, $a0
/* 0A91D4 7F0746A4 00A09025 */  move  $s2, $a1
/* 0A91D8 7F0746A8 15C00007 */  bnez  $t6, .L7F0746C8
/* 0A91DC 7F0746AC 8C500000 */   lw    $s0, ($v0)
/* 0A91E0 7F0746B0 3C048005 */  lui   $a0, %hi(aSubdrawNoGfxlist)
/* 0A91E4 7F0746B4 0C0033D1 */  jal   osSyncPrintf
/* 0A91E8 7F0746B8 24844AB4 */   addiu $a0, %lo(aSubdrawNoGfxlist) # addiu $a0, $a0, 0x4ab4
/* 0A91EC 7F0746BC 0FC1B11B */  jal   return_null
/* 0A91F0 7F0746C0 00000000 */   nop   
/* 0A91F4 7F0746C4 8E420008 */  lw    $v0, 8($s2)
.L7F0746C8:
/* 0A91F8 7F0746C8 8C4F001C */  lw    $t7, 0x1c($v0)
/* 0A91FC 7F0746CC 3C048005 */  lui   $a0, %hi(aSubdrawObjectNotInitialised0xX)
/* 0A9200 7F0746D0 24844ACC */  addiu $a0, %lo(aSubdrawObjectNotInitialised0xX) # addiu $a0, $a0, 0x4acc
/* 0A9204 7F0746D4 11E00003 */  beqz  $t7, .L7F0746E4
/* 0A9208 7F0746D8 00000000 */   nop   
/* 0A920C 7F0746DC 10000006 */  b     .L7F0746F8
/* 0A9210 7F0746E0 8E22000C */   lw    $v0, 0xc($s1)
.L7F0746E4:
/* 0A9214 7F0746E4 0C0033D1 */  jal   osSyncPrintf
/* 0A9218 7F0746E8 00402825 */   move  $a1, $v0
/* 0A921C 7F0746EC 0FC1B11B */  jal   return_null
/* 0A9220 7F0746F0 00000000 */   nop   
/* 0A9224 7F0746F4 8E22000C */  lw    $v0, 0xc($s1)
.L7F0746F8:
/* 0A9228 7F0746F8 24580008 */  addiu $t8, $v0, 8
/* 0A922C 7F0746FC 3C19BC00 */  lui   $t9, (0xBC000C06 >> 16) # lui $t9, 0xbc00
/* 0A9230 7F074700 37390C06 */  ori   $t9, (0xBC000C06 & 0xFFFF) # ori $t9, $t9, 0xc06
/* 0A9234 7F074704 AE38000C */  sw    $t8, 0xc($s1)
/* 0A9238 7F074708 AC590000 */  sw    $t9, ($v0)
/* 0A923C 7F07470C 8E44000C */  lw    $a0, 0xc($s2)
/* 0A9240 7F074710 0C003A2C */  jal   osVirtualToPhysical
/* 0A9244 7F074714 AFA20028 */   sw    $v0, 0x28($sp)
/* 0A9248 7F074718 8FA30028 */  lw    $v1, 0x28($sp)
/* 0A924C 7F07471C 12000016 */  beqz  $s0, .L7F074778
/* 0A9250 7F074720 AC620004 */   sw    $v0, 4($v1)
/* 0A9254 7F074724 02202025 */  move  $a0, $s1
.L7F074728:
/* 0A9258 7F074728 02402825 */  move  $a1, $s2
/* 0A925C 7F07472C 0FC1D14D */  jal   sub_GAME_7F074534
/* 0A9260 7F074730 02003025 */   move  $a2, $s0
/* 0A9264 7F074734 8E020014 */  lw    $v0, 0x14($s0)
/* 0A9268 7F074738 10400003 */  beqz  $v0, .L7F074748
/* 0A926C 7F07473C 00000000 */   nop   
/* 0A9270 7F074740 1000000B */  b     .L7F074770
/* 0A9274 7F074744 00408025 */   move  $s0, $v0
.L7F074748:
/* 0A9278 7F074748 12000009 */  beqz  $s0, .L7F074770
/* 0A927C 7F07474C 00000000 */   nop   
/* 0A9280 7F074750 8E02000C */  lw    $v0, 0xc($s0)
.L7F074754:
/* 0A9284 7F074754 50400004 */  beql  $v0, $zero, .L7F074768
/* 0A9288 7F074758 8E100008 */   lw    $s0, 8($s0)
/* 0A928C 7F07475C 10000004 */  b     .L7F074770
/* 0A9290 7F074760 00408025 */   move  $s0, $v0
/* 0A9294 7F074764 8E100008 */  lw    $s0, 8($s0)
.L7F074768:
/* 0A9298 7F074768 5600FFFA */  bnezl $s0, .L7F074754
/* 0A929C 7F07476C 8E02000C */   lw    $v0, 0xc($s0)
.L7F074770:
/* 0A92A0 7F074770 5600FFED */  bnezl $s0, .L7F074728
/* 0A92A4 7F074774 02202025 */   move  $a0, $s1
.L7F074778:
/* 0A92A8 7F074778 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0A92AC 7F07477C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A92B0 7F074780 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A92B4 7F074784 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A92B8 7F074788 03E00008 */  jr    $ra
/* 0A92BC 7F07478C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel subdraw
/* 0A7148 7F074758 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A714C 7F07475C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A7150 7F074760 AFB20020 */  sw    $s2, 0x20($sp)
/* 0A7154 7F074764 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A7158 7F074768 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A715C 7F07476C 8CAE0008 */  lw    $t6, 8($a1)
/* 0A7160 7F074770 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7164 7F074774 3C18BC00 */  lui   $t8, (0xBC000C06 >> 16) # lui $t8, 0xbc00
/* 0A7168 7F074778 8DD00000 */  lw    $s0, ($t6)
/* 0A716C 7F07477C 244F0008 */  addiu $t7, $v0, 8
/* 0A7170 7F074780 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A7174 7F074784 37180C06 */  ori   $t8, (0xBC000C06 & 0xFFFF) # ori $t8, $t8, 0xc06
/* 0A7178 7F074788 00809025 */  move  $s2, $a0
/* 0A717C 7F07478C AC580000 */  sw    $t8, ($v0)
/* 0A7180 7F074790 8CA4000C */  lw    $a0, 0xc($a1)
/* 0A7184 7F074794 00A08825 */  move  $s1, $a1
/* 0A7188 7F074798 0C003838 */  jal   osVirtualToPhysical
/* 0A718C 7F07479C AFA20028 */   sw    $v0, 0x28($sp)
/* 0A7190 7F0747A0 8FA30028 */  lw    $v1, 0x28($sp)
/* 0A7194 7F0747A4 12000016 */  beqz  $s0, .L7F074800
/* 0A7198 7F0747A8 AC620004 */   sw    $v0, 4($v1)
/* 0A719C 7F0747AC 02402025 */  move  $a0, $s2
.L7F0747B0:
/* 0A71A0 7F0747B0 02202825 */  move  $a1, $s1
/* 0A71A4 7F0747B4 0FC1D182 */  jal   sub_GAME_7F074534
/* 0A71A8 7F0747B8 02003025 */   move  $a2, $s0
/* 0A71AC 7F0747BC 8E020014 */  lw    $v0, 0x14($s0)
/* 0A71B0 7F0747C0 10400003 */  beqz  $v0, .L7F0747D0
/* 0A71B4 7F0747C4 00000000 */   nop   
/* 0A71B8 7F0747C8 1000000B */  b     .L7F0747F8
/* 0A71BC 7F0747CC 00408025 */   move  $s0, $v0
.L7F0747D0:
/* 0A71C0 7F0747D0 12000009 */  beqz  $s0, .L7F0747F8
/* 0A71C4 7F0747D4 00000000 */   nop   
/* 0A71C8 7F0747D8 8E02000C */  lw    $v0, 0xc($s0)
.L7F0747DC:
/* 0A71CC 7F0747DC 50400004 */  beql  $v0, $zero, .L7F0747F0
/* 0A71D0 7F0747E0 8E100008 */   lw    $s0, 8($s0)
/* 0A71D4 7F0747E4 10000004 */  b     .L7F0747F8
/* 0A71D8 7F0747E8 00408025 */   move  $s0, $v0
/* 0A71DC 7F0747EC 8E100008 */  lw    $s0, 8($s0)
.L7F0747F0:
/* 0A71E0 7F0747F0 5600FFFA */  bnezl $s0, .L7F0747DC
/* 0A71E4 7F0747F4 8E02000C */   lw    $v0, 0xc($s0)
.L7F0747F8:
/* 0A71E8 7F0747F8 5600FFED */  bnezl $s0, .L7F0747B0
/* 0A71EC 7F0747FC 02402025 */   move  $a0, $s2
.L7F074800:
/* 0A71F0 7F074800 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0A71F4 7F074804 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A71F8 7F074808 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A71FC 7F07480C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A7200 7F074810 03E00008 */  jr    $ra
/* 0A7204 7F074814 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#endif


void sub_GAME_7F074790(struct unk_joint_list* arg0, Model* arg1)
{
    subcalcpos(arg1);
    subcalcmatrices(arg0, arg1);
    subdraw((s32) arg0, arg1);
}


#ifdef NONMATCHING
void sub_GAME_7F0747D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0747D0
/* 0A9300 7F0747D0 C4A00000 */  lwc1  $f0, ($a1)
/* 0A9304 7F0747D4 C4A20004 */  lwc1  $f2, 4($a1)
/* 0A9308 7F0747D8 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0A930C 7F0747DC 46000402 */  mul.s $f16, $f0, $f0
/* 0A9310 7F0747E0 00000000 */  nop   
/* 0A9314 7F0747E4 46021102 */  mul.s $f4, $f2, $f2
/* 0A9318 7F0747E8 E7A400B0 */  swc1  $f4, 0xb0($sp)
/* 0A931C 7F0747EC C4AC0008 */  lwc1  $f12, 8($a1)
/* 0A9320 7F0747F0 C7A800B0 */  lwc1  $f8, 0xb0($sp)
/* 0A9324 7F0747F4 460C6182 */  mul.s $f6, $f12, $f12
/* 0A9328 7F0747F8 46088280 */  add.s $f10, $f16, $f8
/* 0A932C 7F0747FC E7A600AC */  swc1  $f6, 0xac($sp)
/* 0A9330 7F074800 C7A400AC */  lwc1  $f4, 0xac($sp)
/* 0A9334 7F074804 C4860004 */  lwc1  $f6, 4($a0)
/* 0A9338 7F074808 46045380 */  add.s $f14, $f10, $f4
/* 0A933C 7F07480C 46007387 */  neg.s $f14, $f14
/* 0A9340 7F074810 46067202 */  mul.s $f8, $f14, $f6
/* 0A9344 7F074814 E7A800A4 */  swc1  $f8, 0xa4($sp)
/* 0A9348 7F074818 C48A0008 */  lwc1  $f10, 8($a0)
/* 0A934C 7F07481C 460A7102 */  mul.s $f4, $f14, $f10
/* 0A9350 7F074820 E7A400A0 */  swc1  $f4, 0xa0($sp)
/* 0A9354 7F074824 C4E60008 */  lwc1  $f6, 8($a3)
/* 0A9358 7F074828 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0A935C 7F07482C C4E80000 */  lwc1  $f8, ($a3)
/* 0A9360 7F074830 E7A80010 */  swc1  $f8, 0x10($sp)
/* 0A9364 7F074834 C4EA0004 */  lwc1  $f10, 4($a3)
/* 0A9368 7F074838 C7A40010 */  lwc1  $f4, 0x10($sp)
/* 0A936C 7F07483C E7AA000C */  swc1  $f10, 0xc($sp)
/* 0A9370 7F074840 46040182 */  mul.s $f6, $f0, $f4
/* 0A9374 7F074844 C7A8000C */  lwc1  $f8, 0xc($sp)
/* 0A9378 7F074848 46081282 */  mul.s $f10, $f2, $f8
/* 0A937C 7F07484C C7A80014 */  lwc1  $f8, 0x14($sp)
/* 0A9380 7F074850 460A3100 */  add.s $f4, $f6, $f10
/* 0A9384 7F074854 460C4182 */  mul.s $f6, $f8, $f12
/* 0A9388 7F074858 46043280 */  add.s $f10, $f6, $f4
/* 0A938C 7F07485C E7AA009C */  swc1  $f10, 0x9c($sp)
/* 0A9390 7F074860 C4A60038 */  lwc1  $f6, 0x38($a1)
/* 0A9394 7F074864 C4C80008 */  lwc1  $f8, 8($a2)
/* 0A9398 7F074868 46064101 */  sub.s $f4, $f8, $f6
/* 0A939C 7F07486C E7A40008 */  swc1  $f4, 8($sp)
/* 0A93A0 7F074870 C4A60030 */  lwc1  $f6, 0x30($a1)
/* 0A93A4 7F074874 C4C80000 */  lwc1  $f8, ($a2)
/* 0A93A8 7F074878 46064101 */  sub.s $f4, $f8, $f6
/* 0A93AC 7F07487C E7A40004 */  swc1  $f4, 4($sp)
/* 0A93B0 7F074880 C4A60034 */  lwc1  $f6, 0x34($a1)
/* 0A93B4 7F074884 C4C80004 */  lwc1  $f8, 4($a2)
/* 0A93B8 7F074888 46064101 */  sub.s $f4, $f8, $f6
/* 0A93BC 7F07488C C7A80004 */  lwc1  $f8, 4($sp)
/* 0A93C0 7F074890 E7A40000 */  swc1  $f4, ($sp)
/* 0A93C4 7F074894 46080182 */  mul.s $f6, $f0, $f8
/* 0A93C8 7F074898 C7A40000 */  lwc1  $f4, ($sp)
/* 0A93CC 7F07489C 46041202 */  mul.s $f8, $f2, $f4
/* 0A93D0 7F0748A0 46083100 */  add.s $f4, $f6, $f8
/* 0A93D4 7F0748A4 C7A60008 */  lwc1  $f6, 8($sp)
/* 0A93D8 7F0748A8 460C3202 */  mul.s $f8, $f6, $f12
/* 0A93DC 7F0748AC 44806000 */  mtc1  $zero, $f12
/* 0A93E0 7F0748B0 C7A600A0 */  lwc1  $f6, 0xa0($sp)
/* 0A93E4 7F0748B4 460C503C */  c.lt.s $f10, $f12
/* 0A93E8 7F0748B8 46044480 */  add.s $f18, $f8, $f4
/* 0A93EC 7F0748BC C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0A93F0 7F0748C0 46069000 */  add.s $f0, $f18, $f6
/* 0A93F4 7F0748C4 46089480 */  add.s $f18, $f18, $f8
/* 0A93F8 7F0748C8 46000007 */  neg.s $f0, $f0
/* 0A93FC 7F0748CC 45000005 */  bc1f  .L7F0748E4
/* 0A9400 7F0748D0 46009487 */   neg.s $f18, $f18
/* 0A9404 7F0748D4 46005107 */  neg.s $f4, $f10
/* 0A9408 7F0748D8 46009487 */  neg.s $f18, $f18
/* 0A940C 7F0748DC E7A4009C */  swc1  $f4, 0x9c($sp)
/* 0A9410 7F0748E0 46000007 */  neg.s $f0, $f0
.L7F0748E4:
/* 0A9414 7F0748E4 460C903C */  c.lt.s $f18, $f12
/* 0A9418 7F0748E8 00000000 */  nop   
/* 0A941C 7F0748EC 45020008 */  bc1fl .L7F074910
/* 0A9420 7F0748F0 4612003C */   c.lt.s $f0, $f18
/* 0A9424 7F0748F4 460C003C */  c.lt.s $f0, $f12
/* 0A9428 7F0748F8 00000000 */  nop   
/* 0A942C 7F0748FC 45020004 */  bc1fl .L7F074910
/* 0A9430 7F074900 4612003C */   c.lt.s $f0, $f18
/* 0A9434 7F074904 100000D6 */  b     .L7F074C60
/* 0A9438 7F074908 00001025 */   move  $v0, $zero
/* 0A943C 7F07490C 4612003C */  c.lt.s $f0, $f18
.L7F074910:
/* 0A9440 7F074910 E7A00094 */  swc1  $f0, 0x94($sp)
/* 0A9444 7F074914 45020005 */  bc1fl .L7F07492C
/* 0A9448 7F074918 C4A00010 */   lwc1  $f0, 0x10($a1)
/* 0A944C 7F07491C 46009086 */  mov.s $f2, $f18
/* 0A9450 7F074920 46000486 */  mov.s $f18, $f0
/* 0A9454 7F074924 E7A20094 */  swc1  $f2, 0x94($sp)
/* 0A9458 7F074928 C4A00010 */  lwc1  $f0, 0x10($a1)
.L7F07492C:
/* 0A945C 7F07492C 46000182 */  mul.s $f6, $f0, $f0
/* 0A9460 7F074930 E7A60088 */  swc1  $f6, 0x88($sp)
/* 0A9464 7F074934 C4A20014 */  lwc1  $f2, 0x14($a1)
/* 0A9468 7F074938 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0A946C 7F07493C 46021202 */  mul.s $f8, $f2, $f2
/* 0A9470 7F074940 E7A80084 */  swc1  $f8, 0x84($sp)
/* 0A9474 7F074944 C4AC0018 */  lwc1  $f12, 0x18($a1)
/* 0A9478 7F074948 C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0A947C 7F07494C 460C6282 */  mul.s $f10, $f12, $f12
/* 0A9480 7F074950 46062200 */  add.s $f8, $f4, $f6
/* 0A9484 7F074954 E7AA0080 */  swc1  $f10, 0x80($sp)
/* 0A9488 7F074958 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 0A948C 7F07495C C484000C */  lwc1  $f4, 0xc($a0)
/* 0A9490 7F074960 460A4380 */  add.s $f14, $f8, $f10
/* 0A9494 7F074964 46007387 */  neg.s $f14, $f14
/* 0A9498 7F074968 46047182 */  mul.s $f6, $f14, $f4
/* 0A949C 7F07496C C7A40010 */  lwc1  $f4, 0x10($sp)
/* 0A94A0 7F074970 E7A60078 */  swc1  $f6, 0x78($sp)
/* 0A94A4 7F074974 C4880010 */  lwc1  $f8, 0x10($a0)
/* 0A94A8 7F074978 46087282 */  mul.s $f10, $f14, $f8
/* 0A94AC 7F07497C C7A8000C */  lwc1  $f8, 0xc($sp)
/* 0A94B0 7F074980 46040182 */  mul.s $f6, $f0, $f4
/* 0A94B4 7F074984 E7AA0074 */  swc1  $f10, 0x74($sp)
/* 0A94B8 7F074988 46081282 */  mul.s $f10, $f2, $f8
/* 0A94BC 7F07498C C7A80014 */  lwc1  $f8, 0x14($sp)
/* 0A94C0 7F074990 460A3100 */  add.s $f4, $f6, $f10
/* 0A94C4 7F074994 460C4182 */  mul.s $f6, $f8, $f12
/* 0A94C8 7F074998 C7A80004 */  lwc1  $f8, 4($sp)
/* 0A94CC 7F07499C 46043280 */  add.s $f10, $f6, $f4
/* 0A94D0 7F0749A0 46080182 */  mul.s $f6, $f0, $f8
/* 0A94D4 7F0749A4 C7A40000 */  lwc1  $f4, ($sp)
/* 0A94D8 7F0749A8 E7AA0070 */  swc1  $f10, 0x70($sp)
/* 0A94DC 7F0749AC 46041202 */  mul.s $f8, $f2, $f4
/* 0A94E0 7F0749B0 46005386 */  mov.s $f14, $f10
/* 0A94E4 7F0749B4 46083100 */  add.s $f4, $f6, $f8
/* 0A94E8 7F0749B8 C7A60008 */  lwc1  $f6, 8($sp)
/* 0A94EC 7F0749BC 460C3202 */  mul.s $f8, $f6, $f12
/* 0A94F0 7F0749C0 44806000 */  mtc1  $zero, $f12
/* 0A94F4 7F0749C4 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0A94F8 7F0749C8 460C503C */  c.lt.s $f10, $f12
/* 0A94FC 7F0749CC 46044400 */  add.s $f16, $f8, $f4
/* 0A9500 7F0749D0 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0A9504 7F0749D4 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0A9508 7F0749D8 46068000 */  add.s $f0, $f16, $f6
/* 0A950C 7F0749DC 46088400 */  add.s $f16, $f16, $f8
/* 0A9510 7F0749E0 46000007 */  neg.s $f0, $f0
/* 0A9514 7F0749E4 45000004 */  bc1f  .L7F0749F8
/* 0A9518 7F0749E8 46008407 */   neg.s $f16, $f16
/* 0A951C 7F0749EC 46005387 */  neg.s $f14, $f10
/* 0A9520 7F0749F0 46008407 */  neg.s $f16, $f16
/* 0A9524 7F0749F4 46000007 */  neg.s $f0, $f0
.L7F0749F8:
/* 0A9528 7F0749F8 460C803C */  c.lt.s $f16, $f12
/* 0A952C 7F0749FC 00000000 */  nop   
/* 0A9530 7F074A00 45020008 */  bc1fl .L7F074A24
/* 0A9534 7F074A04 4610003C */   c.lt.s $f0, $f16
/* 0A9538 7F074A08 460C003C */  c.lt.s $f0, $f12
/* 0A953C 7F074A0C 00000000 */  nop   
/* 0A9540 7F074A10 45020004 */  bc1fl .L7F074A24
/* 0A9544 7F074A14 4610003C */   c.lt.s $f0, $f16
/* 0A9548 7F074A18 10000091 */  b     .L7F074C60
/* 0A954C 7F074A1C 00001025 */   move  $v0, $zero
/* 0A9550 7F074A20 4610003C */  c.lt.s $f0, $f16
.L7F074A24:
/* 0A9554 7F074A24 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0A9558 7F074A28 45000004 */  bc1f  .L7F074A3C
/* 0A955C 7F074A2C 00000000 */   nop   
/* 0A9560 7F074A30 46008086 */  mov.s $f2, $f16
/* 0A9564 7F074A34 46000406 */  mov.s $f16, $f0
/* 0A9568 7F074A38 46001006 */  mov.s $f0, $f2
.L7F074A3C:
/* 0A956C 7F074A3C 46048302 */  mul.s $f12, $f16, $f4
/* 0A9570 7F074A40 00000000 */  nop   
/* 0A9574 7F074A44 460E9082 */  mul.s $f2, $f18, $f14
/* 0A9578 7F074A48 4602603C */  c.lt.s $f12, $f2
/* 0A957C 7F074A4C 00000000 */  nop   
/* 0A9580 7F074A50 4500000E */  bc1f  .L7F074A8C
/* 0A9584 7F074A54 00000000 */   nop   
/* 0A9588 7F074A58 46040302 */  mul.s $f12, $f0, $f4
/* 0A958C 7F074A5C 4602603C */  c.lt.s $f12, $f2
/* 0A9590 7F074A60 00000000 */  nop   
/* 0A9594 7F074A64 45020004 */  bc1fl .L7F074A78
/* 0A9598 7F074A68 C7A60094 */   lwc1  $f6, 0x94($sp)
/* 0A959C 7F074A6C 1000007C */  b     .L7F074C60
/* 0A95A0 7F074A70 00001025 */   move  $v0, $zero
/* 0A95A4 7F074A74 C7A60094 */  lwc1  $f6, 0x94($sp)
.L7F074A78:
/* 0A95A8 7F074A78 C7AA009C */  lwc1  $f10, 0x9c($sp)
/* 0A95AC 7F074A7C E7B2005C */  swc1  $f18, 0x5c($sp)
/* 0A95B0 7F074A80 460E3082 */  mul.s $f2, $f6, $f14
/* 0A95B4 7F074A84 1000000D */  b     .L7F074ABC
/* 0A95B8 7F074A88 E7AA0058 */   swc1  $f10, 0x58($sp)
.L7F074A8C:
/* 0A95BC 7F074A8C 460E4082 */  mul.s $f2, $f8, $f14
/* 0A95C0 7F074A90 460C103C */  c.lt.s $f2, $f12
/* 0A95C4 7F074A94 00000000 */  nop   
/* 0A95C8 7F074A98 45020004 */  bc1fl .L7F074AAC
/* 0A95CC 7F074A9C C7A4009C */   lwc1  $f4, 0x9c($sp)
/* 0A95D0 7F074AA0 1000006F */  b     .L7F074C60
/* 0A95D4 7F074AA4 00001025 */   move  $v0, $zero
/* 0A95D8 7F074AA8 C7A4009C */  lwc1  $f4, 0x9c($sp)
.L7F074AAC:
/* 0A95DC 7F074AAC E7B0005C */  swc1  $f16, 0x5c($sp)
/* 0A95E0 7F074AB0 E7AE0058 */  swc1  $f14, 0x58($sp)
/* 0A95E4 7F074AB4 46040302 */  mul.s $f12, $f0, $f4
/* 0A95E8 7F074AB8 00000000 */  nop   
.L7F074ABC:
/* 0A95EC 7F074ABC 460C103C */  c.lt.s $f2, $f12
/* 0A95F0 7F074AC0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 0A95F4 7F074AC4 45020006 */  bc1fl .L7F074AE0
/* 0A95F8 7F074AC8 E7A00054 */   swc1  $f0, 0x54($sp)
/* 0A95FC 7F074ACC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0A9600 7F074AD0 E7AA0054 */  swc1  $f10, 0x54($sp)
/* 0A9604 7F074AD4 10000003 */  b     .L7F074AE4
/* 0A9608 7F074AD8 E7A60050 */   swc1  $f6, 0x50($sp)
/* 0A960C 7F074ADC E7A00054 */  swc1  $f0, 0x54($sp)
.L7F074AE0:
/* 0A9610 7F074AE0 E7AE0050 */  swc1  $f14, 0x50($sp)
.L7F074AE4:
/* 0A9614 7F074AE4 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 0A9618 7F074AE8 C4A20024 */  lwc1  $f2, 0x24($a1)
/* 0A961C 7F074AEC 46000482 */  mul.s $f18, $f0, $f0
/* 0A9620 7F074AF0 00000000 */  nop   
/* 0A9624 7F074AF4 46021202 */  mul.s $f8, $f2, $f2
/* 0A9628 7F074AF8 E7A80040 */  swc1  $f8, 0x40($sp)
/* 0A962C 7F074AFC C4AC0028 */  lwc1  $f12, 0x28($a1)
/* 0A9630 7F074B00 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0A9634 7F074B04 460C6102 */  mul.s $f4, $f12, $f12
/* 0A9638 7F074B08 460A9180 */  add.s $f6, $f18, $f10
/* 0A963C 7F074B0C E7A4003C */  swc1  $f4, 0x3c($sp)
/* 0A9640 7F074B10 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0A9644 7F074B14 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0A9648 7F074B18 46083400 */  add.s $f16, $f6, $f8
/* 0A964C 7F074B1C 46008407 */  neg.s $f16, $f16
/* 0A9650 7F074B20 46048282 */  mul.s $f10, $f16, $f4
/* 0A9654 7F074B24 C7A40010 */  lwc1  $f4, 0x10($sp)
/* 0A9658 7F074B28 E7AA0034 */  swc1  $f10, 0x34($sp)
/* 0A965C 7F074B2C C4860018 */  lwc1  $f6, 0x18($a0)
/* 0A9660 7F074B30 46068202 */  mul.s $f8, $f16, $f6
/* 0A9664 7F074B34 C7A6000C */  lwc1  $f6, 0xc($sp)
/* 0A9668 7F074B38 46040282 */  mul.s $f10, $f0, $f4
/* 0A966C 7F074B3C E7A80030 */  swc1  $f8, 0x30($sp)
/* 0A9670 7F074B40 46061202 */  mul.s $f8, $f2, $f6
/* 0A9674 7F074B44 C7A60014 */  lwc1  $f6, 0x14($sp)
/* 0A9678 7F074B48 46085100 */  add.s $f4, $f10, $f8
/* 0A967C 7F074B4C 460C3282 */  mul.s $f10, $f6, $f12
/* 0A9680 7F074B50 C7A60004 */  lwc1  $f6, 4($sp)
/* 0A9684 7F074B54 46045200 */  add.s $f8, $f10, $f4
/* 0A9688 7F074B58 46060282 */  mul.s $f10, $f0, $f6
/* 0A968C 7F074B5C C7A40000 */  lwc1  $f4, ($sp)
/* 0A9690 7F074B60 E7A8002C */  swc1  $f8, 0x2c($sp)
/* 0A9694 7F074B64 46041182 */  mul.s $f6, $f2, $f4
/* 0A9698 7F074B68 44801000 */  mtc1  $zero, $f2
/* 0A969C 7F074B6C 00000000 */  nop   
/* 0A96A0 7F074B70 4602403C */  c.lt.s $f8, $f2
/* 0A96A4 7F074B74 46065100 */  add.s $f4, $f10, $f6
/* 0A96A8 7F074B78 C7AA0008 */  lwc1  $f10, 8($sp)
/* 0A96AC 7F074B7C 460C5182 */  mul.s $f6, $f10, $f12
/* 0A96B0 7F074B80 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0A96B4 7F074B84 46004306 */  mov.s $f12, $f8
/* 0A96B8 7F074B88 46043380 */  add.s $f14, $f6, $f4
/* 0A96BC 7F074B8C C7A60034 */  lwc1  $f6, 0x34($sp)
/* 0A96C0 7F074B90 C7A4005C */  lwc1  $f4, 0x5c($sp)
/* 0A96C4 7F074B94 460A7000 */  add.s $f0, $f14, $f10
/* 0A96C8 7F074B98 46067380 */  add.s $f14, $f14, $f6
/* 0A96CC 7F074B9C 46000007 */  neg.s $f0, $f0
/* 0A96D0 7F074BA0 45000004 */  bc1f  .L7F074BB4
/* 0A96D4 7F074BA4 46007387 */   neg.s $f14, $f14
/* 0A96D8 7F074BA8 46004307 */  neg.s $f12, $f8
/* 0A96DC 7F074BAC 46007387 */  neg.s $f14, $f14
/* 0A96E0 7F074BB0 46000007 */  neg.s $f0, $f0
.L7F074BB4:
/* 0A96E4 7F074BB4 4602703C */  c.lt.s $f14, $f2
/* 0A96E8 7F074BB8 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 0A96EC 7F074BBC 45020008 */  bc1fl .L7F074BE0
/* 0A96F0 7F074BC0 460E003C */   c.lt.s $f0, $f14
/* 0A96F4 7F074BC4 4602003C */  c.lt.s $f0, $f2
/* 0A96F8 7F074BC8 00000000 */  nop   
/* 0A96FC 7F074BCC 45020004 */  bc1fl .L7F074BE0
/* 0A9700 7F074BD0 460E003C */   c.lt.s $f0, $f14
/* 0A9704 7F074BD4 10000022 */  b     .L7F074C60
/* 0A9708 7F074BD8 00001025 */   move  $v0, $zero
/* 0A970C 7F074BDC 460E003C */  c.lt.s $f0, $f14
.L7F074BE0:
/* 0A9710 7F074BE0 C7A60058 */  lwc1  $f6, 0x58($sp)
/* 0A9714 7F074BE4 45000004 */  bc1f  .L7F074BF8
/* 0A9718 7F074BE8 00000000 */   nop   
/* 0A971C 7F074BEC 46007086 */  mov.s $f2, $f14
/* 0A9720 7F074BF0 46000386 */  mov.s $f14, $f0
/* 0A9724 7F074BF4 46001006 */  mov.s $f0, $f2
.L7F074BF8:
/* 0A9728 7F074BF8 460C2082 */  mul.s $f2, $f4, $f12
/* 0A972C 7F074BFC 00000000 */  nop   
/* 0A9730 7F074C00 46087282 */  mul.s $f10, $f14, $f8
/* 0A9734 7F074C04 460A103C */  c.lt.s $f2, $f10
/* 0A9738 7F074C08 00000000 */  nop   
/* 0A973C 7F074C0C 4500000C */  bc1f  .L7F074C40
/* 0A9740 7F074C10 00000000 */   nop   
/* 0A9744 7F074C14 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 0A9748 7F074C18 C7A80050 */  lwc1  $f8, 0x50($sp)
/* 0A974C 7F074C1C 460C3102 */  mul.s $f4, $f6, $f12
/* 0A9750 7F074C20 00000000 */  nop   
/* 0A9754 7F074C24 46087282 */  mul.s $f10, $f14, $f8
/* 0A9758 7F074C28 460A203C */  c.lt.s $f4, $f10
/* 0A975C 7F074C2C 00000000 */  nop   
/* 0A9760 7F074C30 4500000A */  bc1f  .L7F074C5C
/* 0A9764 7F074C34 00000000 */   nop   
/* 0A9768 7F074C38 10000009 */  b     .L7F074C60
/* 0A976C 7F074C3C 00001025 */   move  $v0, $zero
.L7F074C40:
/* 0A9770 7F074C40 46060202 */  mul.s $f8, $f0, $f6
/* 0A9774 7F074C44 4602403C */  c.lt.s $f8, $f2
/* 0A9778 7F074C48 00000000 */  nop   
/* 0A977C 7F074C4C 45020004 */  bc1fl .L7F074C60
/* 0A9780 7F074C50 24020001 */   li    $v0, 1
/* 0A9784 7F074C54 10000002 */  b     .L7F074C60
/* 0A9788 7F074C58 00001025 */   move  $v0, $zero
.L7F074C5C:
/* 0A978C 7F074C5C 24020001 */  li    $v0, 1
.L7F074C60:
/* 0A9790 7F074C60 03E00008 */  jr    $ra
/* 0A9794 7F074C64 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F074C68(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F074C68
/* 0A9798 7F074C68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A979C 7F074C6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A97A0 7F074C70 AFA60028 */  sw    $a2, 0x28($sp)
/* 0A97A4 7F074C74 AFA7002C */  sw    $a3, 0x2c($sp)
/* 0A97A8 7F074C78 8CAE0004 */  lw    $t6, 4($a1)
/* 0A97AC 7F074C7C 00003025 */  move  $a2, $zero
/* 0A97B0 7F074C80 0FC1B198 */  jal   modelFindNodeMtx
/* 0A97B4 7F074C84 AFAE001C */   sw    $t6, 0x1c($sp)
/* 0A97B8 7F074C88 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0A97BC 7F074C8C 00402825 */  move  $a1, $v0
/* 0A97C0 7F074C90 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A97C4 7F074C94 0FC1D1F4 */  jal   sub_GAME_7F0747D0
/* 0A97C8 7F074C98 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0A97CC 7F074C9C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A97D0 7F074CA0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A97D4 7F074CA4 03E00008 */  jr    $ra
/* 0A97D8 7F074CA8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F074CAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F074CAC
/* 0A97DC 7F074CAC 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 0A97E0 7F074CB0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A97E4 7F074CB4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A97E8 7F074CB8 AFA400B0 */  sw    $a0, 0xb0($sp)
/* 0A97EC 7F074CBC 8CA80004 */  lw    $t0, 4($a1)
/* 0A97F0 7F074CC0 00C08025 */  move  $s0, $a2
/* 0A97F4 7F074CC4 00003025 */  move  $a2, $zero
/* 0A97F8 7F074CC8 AFA700BC */  sw    $a3, 0xbc($sp)
/* 0A97FC 7F074CCC AFA500B4 */  sw    $a1, 0xb4($sp)
/* 0A9800 7F074CD0 0FC1B198 */  jal   modelFindNodeMtx
/* 0A9804 7F074CD4 AFA800AC */   sw    $t0, 0xac($sp)
/* 0A9808 7F074CD8 3C0B8003 */  lui   $t3, %hi(D_80036408) 
/* 0A980C 7F074CDC 256B6408 */  addiu $t3, %lo(D_80036408) # addiu $t3, $t3, 0x6408
/* 0A9810 7F074CE0 8D610000 */  lw    $at, ($t3)
/* 0A9814 7F074CE4 8FA700BC */  lw    $a3, 0xbc($sp)
/* 0A9818 7F074CE8 8FA800AC */  lw    $t0, 0xac($sp)
/* 0A981C 7F074CEC 27AA0090 */  addiu $t2, $sp, 0x90
/* 0A9820 7F074CF0 AD410000 */  sw    $at, ($t2)
/* 0A9824 7F074CF4 8D610008 */  lw    $at, 8($t3)
/* 0A9828 7F074CF8 8D790004 */  lw    $t9, 4($t3)
/* 0A982C 7F074CFC 00401825 */  move  $v1, $v0
/* 0A9830 7F074D00 AD410008 */  sw    $at, 8($t2)
/* 0A9834 7F074D04 AD590004 */  sw    $t9, 4($t2)
/* 0A9838 7F074D08 C5080004 */  lwc1  $f8, 4($t0)
/* 0A983C 7F074D0C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0A9840 7F074D10 E7A8008C */  swc1  $f8, 0x8c($sp)
/* 0A9844 7F074D14 C4E60000 */  lwc1  $f6, ($a3)
/* 0A9848 7F074D18 E7A6009C */  swc1  $f6, 0x9c($sp)
/* 0A984C 7F074D1C C4EA0004 */  lwc1  $f10, 4($a3)
/* 0A9850 7F074D20 E7AA00A0 */  swc1  $f10, 0xa0($sp)
/* 0A9854 7F074D24 C4E40008 */  lwc1  $f4, 8($a3)
/* 0A9858 7F074D28 E7A400A4 */  swc1  $f4, 0xa4($sp)
/* 0A985C 7F074D2C 97040000 */  lhu   $a0, ($t8)
/* 0A9860 7F074D30 308E0100 */  andi  $t6, $a0, 0x100
/* 0A9864 7F074D34 11C0003C */  beqz  $t6, .L7F074E28
/* 0A9868 7F074D38 308F0200 */   andi  $t7, $a0, 0x200
/* 0A986C 7F074D3C C5080008 */  lwc1  $f8, 8($t0)
/* 0A9870 7F074D40 E7A80080 */  swc1  $f8, 0x80($sp)
/* 0A9874 7F074D44 C506000C */  lwc1  $f6, 0xc($t0)
/* 0A9878 7F074D48 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0A987C 7F074D4C E7A60084 */  swc1  $f6, 0x84($sp)
/* 0A9880 7F074D50 C50A0010 */  lwc1  $f10, 0x10($t0)
/* 0A9884 7F074D54 E7AA0088 */  swc1  $f10, 0x88($sp)
/* 0A9888 7F074D58 C4480000 */  lwc1  $f8, ($v0)
/* 0A988C 7F074D5C C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 0A9890 7F074D60 46082182 */  mul.s $f6, $f4, $f8
/* 0A9894 7F074D64 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0A9898 7F074D68 E7A40020 */  swc1  $f4, 0x20($sp)
/* 0A989C 7F074D6C C4440020 */  lwc1  $f4, 0x20($v0)
/* 0A98A0 7F074D70 46085202 */  mul.s $f8, $f10, $f8
/* 0A98A4 7F074D74 46083180 */  add.s $f6, $f6, $f8
/* 0A98A8 7F074D78 C7A80088 */  lwc1  $f8, 0x88($sp)
/* 0A98AC 7F074D7C 46044102 */  mul.s $f4, $f8, $f4
/* 0A98B0 7F074D80 46043180 */  add.s $f6, $f6, $f4
/* 0A98B4 7F074D84 C4440030 */  lwc1  $f4, 0x30($v0)
/* 0A98B8 7F074D88 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0A98BC 7F074D8C C60A0000 */  lwc1  $f10, ($s0)
/* 0A98C0 7F074D90 460A2101 */  sub.s $f4, $f4, $f10
/* 0A98C4 7F074D94 46062280 */  add.s $f10, $f4, $f6
/* 0A98C8 7F074D98 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0A98CC 7F074D9C E7AA0090 */  swc1  $f10, 0x90($sp)
/* 0A98D0 7F074DA0 C4460004 */  lwc1  $f6, 4($v0)
/* 0A98D4 7F074DA4 46062282 */  mul.s $f10, $f4, $f6
/* 0A98D8 7F074DA8 C7A60024 */  lwc1  $f6, 0x24($sp)
/* 0A98DC 7F074DAC E7A80024 */  swc1  $f8, 0x24($sp)
/* 0A98E0 7F074DB0 C4480014 */  lwc1  $f8, 0x14($v0)
/* 0A98E4 7F074DB4 46083202 */  mul.s $f8, $f6, $f8
/* 0A98E8 7F074DB8 46085280 */  add.s $f10, $f10, $f8
/* 0A98EC 7F074DBC C7A80024 */  lwc1  $f8, 0x24($sp)
/* 0A98F0 7F074DC0 E7A40024 */  swc1  $f4, 0x24($sp)
/* 0A98F4 7F074DC4 C4440024 */  lwc1  $f4, 0x24($v0)
/* 0A98F8 7F074DC8 46044102 */  mul.s $f4, $f8, $f4
/* 0A98FC 7F074DCC 46045280 */  add.s $f10, $f10, $f4
/* 0A9900 7F074DD0 C4440034 */  lwc1  $f4, 0x34($v0)
/* 0A9904 7F074DD4 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0A9908 7F074DD8 C6060004 */  lwc1  $f6, 4($s0)
/* 0A990C 7F074DDC 46062101 */  sub.s $f4, $f4, $f6
/* 0A9910 7F074DE0 460A2180 */  add.s $f6, $f4, $f10
/* 0A9914 7F074DE4 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0A9918 7F074DE8 E7A60094 */  swc1  $f6, 0x94($sp)
/* 0A991C 7F074DEC C44A0008 */  lwc1  $f10, 8($v0)
/* 0A9920 7F074DF0 460A2182 */  mul.s $f6, $f4, $f10
/* 0A9924 7F074DF4 C44A0018 */  lwc1  $f10, 0x18($v0)
/* 0A9928 7F074DF8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0A992C 7F074DFC 460A2102 */  mul.s $f4, $f4, $f10
/* 0A9930 7F074E00 46043280 */  add.s $f10, $f6, $f4
/* 0A9934 7F074E04 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0A9938 7F074E08 46064102 */  mul.s $f4, $f8, $f6
/* 0A993C 7F074E0C C4460038 */  lwc1  $f6, 0x38($v0)
/* 0A9940 7F074E10 46045200 */  add.s $f8, $f10, $f4
/* 0A9944 7F074E14 C60A0008 */  lwc1  $f10, 8($s0)
/* 0A9948 7F074E18 460A3101 */  sub.s $f4, $f6, $f10
/* 0A994C 7F074E1C 46082180 */  add.s $f6, $f4, $f8
/* 0A9950 7F074E20 1000003E */  b     .L7F074F1C
/* 0A9954 7F074E24 E7A60098 */   swc1  $f6, 0x98($sp)
.L7F074E28:
/* 0A9958 7F074E28 51E00031 */  beql  $t7, $zero, .L7F074EF0
/* 0A995C 7F074E2C C4460030 */   lwc1  $f6, 0x30($v0)
/* 0A9960 7F074E30 8D050014 */  lw    $a1, 0x14($t0)
/* 0A9964 7F074E34 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0A9968 7F074E38 00003025 */  move  $a2, $zero
/* 0A996C 7F074E3C 50A0001F */  beql  $a1, $zero, .L7F074EBC
/* 0A9970 7F074E40 C4480030 */   lwc1  $f8, 0x30($v0)
/* 0A9974 7F074E44 AFA300A8 */  sw    $v1, 0xa8($sp)
/* 0A9978 7F074E48 0FC1B198 */  jal   modelFindNodeMtx
/* 0A997C 7F074E4C AFA800AC */   sw    $t0, 0xac($sp)
/* 0A9980 7F074E50 8FA300A8 */  lw    $v1, 0xa8($sp)
/* 0A9984 7F074E54 C4440030 */  lwc1  $f4, 0x30($v0)
/* 0A9988 7F074E58 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A998C 7F074E5C C46A0030 */  lwc1  $f10, 0x30($v1)
/* 0A9990 7F074E60 44810000 */  mtc1  $at, $f0
/* 0A9994 7F074E64 8FA800AC */  lw    $t0, 0xac($sp)
/* 0A9998 7F074E68 46045200 */  add.s $f8, $f10, $f4
/* 0A999C 7F074E6C C60A0000 */  lwc1  $f10, ($s0)
/* 0A99A0 7F074E70 46004182 */  mul.s $f6, $f8, $f0
/* 0A99A4 7F074E74 460A3101 */  sub.s $f4, $f6, $f10
/* 0A99A8 7F074E78 E7A40090 */  swc1  $f4, 0x90($sp)
/* 0A99AC 7F074E7C C4460034 */  lwc1  $f6, 0x34($v0)
/* 0A99B0 7F074E80 C4680034 */  lwc1  $f8, 0x34($v1)
/* 0A99B4 7F074E84 46064280 */  add.s $f10, $f8, $f6
/* 0A99B8 7F074E88 C6080004 */  lwc1  $f8, 4($s0)
/* 0A99BC 7F074E8C 46005102 */  mul.s $f4, $f10, $f0
/* 0A99C0 7F074E90 46082181 */  sub.s $f6, $f4, $f8
/* 0A99C4 7F074E94 E7A60094 */  swc1  $f6, 0x94($sp)
/* 0A99C8 7F074E98 C4440038 */  lwc1  $f4, 0x38($v0)
/* 0A99CC 7F074E9C C46A0038 */  lwc1  $f10, 0x38($v1)
/* 0A99D0 7F074EA0 46045200 */  add.s $f8, $f10, $f4
/* 0A99D4 7F074EA4 C60A0008 */  lwc1  $f10, 8($s0)
/* 0A99D8 7F074EA8 46004182 */  mul.s $f6, $f8, $f0
/* 0A99DC 7F074EAC 460A3101 */  sub.s $f4, $f6, $f10
/* 0A99E0 7F074EB0 1000001A */  b     .L7F074F1C
/* 0A99E4 7F074EB4 E7A40098 */   swc1  $f4, 0x98($sp)
/* 0A99E8 7F074EB8 C4480030 */  lwc1  $f8, 0x30($v0)
.L7F074EBC:
/* 0A99EC 7F074EBC C6060000 */  lwc1  $f6, ($s0)
/* 0A99F0 7F074EC0 46064281 */  sub.s $f10, $f8, $f6
/* 0A99F4 7F074EC4 E7AA0090 */  swc1  $f10, 0x90($sp)
/* 0A99F8 7F074EC8 C6080004 */  lwc1  $f8, 4($s0)
/* 0A99FC 7F074ECC C4440034 */  lwc1  $f4, 0x34($v0)
/* 0A9A00 7F074ED0 46082181 */  sub.s $f6, $f4, $f8
/* 0A9A04 7F074ED4 E7A60094 */  swc1  $f6, 0x94($sp)
/* 0A9A08 7F074ED8 C6040008 */  lwc1  $f4, 8($s0)
/* 0A9A0C 7F074EDC C44A0038 */  lwc1  $f10, 0x38($v0)
/* 0A9A10 7F074EE0 46045201 */  sub.s $f8, $f10, $f4
/* 0A9A14 7F074EE4 1000000D */  b     .L7F074F1C
/* 0A9A18 7F074EE8 E7A80098 */   swc1  $f8, 0x98($sp)
/* 0A9A1C 7F074EEC C4460030 */  lwc1  $f6, 0x30($v0)
.L7F074EF0:
/* 0A9A20 7F074EF0 C60A0000 */  lwc1  $f10, ($s0)
/* 0A9A24 7F074EF4 460A3101 */  sub.s $f4, $f6, $f10
/* 0A9A28 7F074EF8 E7A40090 */  swc1  $f4, 0x90($sp)
/* 0A9A2C 7F074EFC C6060004 */  lwc1  $f6, 4($s0)
/* 0A9A30 7F074F00 C4480034 */  lwc1  $f8, 0x34($v0)
/* 0A9A34 7F074F04 46064281 */  sub.s $f10, $f8, $f6
/* 0A9A38 7F074F08 E7AA0094 */  swc1  $f10, 0x94($sp)
/* 0A9A3C 7F074F0C C6080008 */  lwc1  $f8, 8($s0)
/* 0A9A40 7F074F10 C4440038 */  lwc1  $f4, 0x38($v0)
/* 0A9A44 7F074F14 46082181 */  sub.s $f6, $f4, $f8
/* 0A9A48 7F074F18 E7A60098 */  swc1  $f6, 0x98($sp)
.L7F074F1C:
/* 0A9A4C 7F074F1C 8FA900B4 */  lw    $t1, 0xb4($sp)
/* 0A9A50 7F074F20 C7A400A4 */  lwc1  $f4, 0xa4($sp)
/* 0A9A54 7F074F24 C7A600A0 */  lwc1  $f6, 0xa0($sp)
/* 0A9A58 7F074F28 95240000 */  lhu   $a0, ($t1)
/* 0A9A5C 7F074F2C 308D0400 */  andi  $t5, $a0, 0x400
/* 0A9A60 7F074F30 11A00074 */  beqz  $t5, .L7F075104
/* 0A9A64 7F074F34 30820800 */   andi  $v0, $a0, 0x800
/* 0A9A68 7F074F38 C46A0008 */  lwc1  $f10, 8($v1)
/* 0A9A6C 7F074F3C C50C0018 */  lwc1  $f12, 0x18($t0)
/* 0A9A70 7F074F40 C510001C */  lwc1  $f16, 0x1c($t0)
/* 0A9A74 7F074F44 46045202 */  mul.s $f8, $f10, $f4
/* 0A9A78 7F074F48 C46A0004 */  lwc1  $f10, 4($v1)
/* 0A9A7C 7F074F4C C4600000 */  lwc1  $f0, ($v1)
/* 0A9A80 7F074F50 E7A40024 */  swc1  $f4, 0x24($sp)
/* 0A9A84 7F074F54 460A3282 */  mul.s $f10, $f6, $f10
/* 0A9A88 7F074F58 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0A9A8C 7F074F5C E7A80020 */  swc1  $f8, 0x20($sp)
/* 0A9A90 7F074F60 46002202 */  mul.s $f8, $f4, $f0
/* 0A9A94 7F074F64 460A4200 */  add.s $f8, $f8, $f10
/* 0A9A98 7F074F68 C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 0A9A9C 7F074F6C 46085280 */  add.s $f10, $f10, $f8
/* 0A9AA0 7F074F70 460C5082 */  mul.s $f2, $f10, $f12
/* 0A9AA4 7F074F74 00000000 */  nop   
/* 0A9AA8 7F074F78 46020202 */  mul.s $f8, $f0, $f2
/* 0A9AAC 7F074F7C 46044280 */  add.s $f10, $f8, $f4
/* 0A9AB0 7F074F80 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 0A9AB4 7F074F84 C4680004 */  lwc1  $f8, 4($v1)
/* 0A9AB8 7F074F88 46024102 */  mul.s $f4, $f8, $f2
/* 0A9ABC 7F074F8C 46062200 */  add.s $f8, $f4, $f6
/* 0A9AC0 7F074F90 E7A800A0 */  swc1  $f8, 0xa0($sp)
/* 0A9AC4 7F074F94 C4640008 */  lwc1  $f4, 8($v1)
/* 0A9AC8 7F074F98 46022182 */  mul.s $f6, $f4, $f2
/* 0A9ACC 7F074F9C C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0A9AD0 7F074FA0 46043180 */  add.s $f6, $f6, $f4
/* 0A9AD4 7F074FA4 E7A600A4 */  swc1  $f6, 0xa4($sp)
/* 0A9AD8 7F074FA8 C4640008 */  lwc1  $f4, 8($v1)
/* 0A9ADC 7F074FAC C4600000 */  lwc1  $f0, ($v1)
/* 0A9AE0 7F074FB0 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0A9AE4 7F074FB4 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0A9AE8 7F074FB8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 0A9AEC 7F074FBC E7A60028 */  swc1  $f6, 0x28($sp)
/* 0A9AF0 7F074FC0 460A2102 */  mul.s $f4, $f4, $f10
/* 0A9AF4 7F074FC4 C4660004 */  lwc1  $f6, 4($v1)
/* 0A9AF8 7F074FC8 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0A9AFC 7F074FCC E7AA002C */  swc1  $f10, 0x2c($sp)
/* 0A9B00 7F074FD0 C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0A9B04 7F074FD4 46064182 */  mul.s $f6, $f8, $f6
/* 0A9B08 7F074FD8 E7A40030 */  swc1  $f4, 0x30($sp)
/* 0A9B0C 7F074FDC 46005102 */  mul.s $f4, $f10, $f0
/* 0A9B10 7F074FE0 46062100 */  add.s $f4, $f4, $f6
/* 0A9B14 7F074FE4 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 0A9B18 7F074FE8 46043180 */  add.s $f6, $f6, $f4
/* 0A9B1C 7F074FEC 460C3382 */  mul.s $f14, $f6, $f12
/* 0A9B20 7F074FF0 00000000 */  nop   
/* 0A9B24 7F074FF4 460E0102 */  mul.s $f4, $f0, $f14
/* 0A9B28 7F074FF8 460A2180 */  add.s $f6, $f4, $f10
/* 0A9B2C 7F074FFC E7A60090 */  swc1  $f6, 0x90($sp)
/* 0A9B30 7F075000 C4640004 */  lwc1  $f4, 4($v1)
/* 0A9B34 7F075004 460E2282 */  mul.s $f10, $f4, $f14
/* 0A9B38 7F075008 46085100 */  add.s $f4, $f10, $f8
/* 0A9B3C 7F07500C E7A40094 */  swc1  $f4, 0x94($sp)
/* 0A9B40 7F075010 C46A0008 */  lwc1  $f10, 8($v1)
/* 0A9B44 7F075014 460E5202 */  mul.s $f8, $f10, $f14
/* 0A9B48 7F075018 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0A9B4C 7F07501C 460A4200 */  add.s $f8, $f8, $f10
/* 0A9B50 7F075020 C7AA0024 */  lwc1  $f10, 0x24($sp)
/* 0A9B54 7F075024 E7A80098 */  swc1  $f8, 0x98($sp)
/* 0A9B58 7F075028 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0A9B5C 7F07502C E7A60030 */  swc1  $f6, 0x30($sp)
/* 0A9B60 7F075030 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0A9B64 7F075034 E7A80024 */  swc1  $f8, 0x24($sp)
/* 0A9B68 7F075038 46005182 */  mul.s $f6, $f10, $f0
/* 0A9B6C 7F07503C C4680014 */  lwc1  $f8, 0x14($v1)
/* 0A9B70 7F075040 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0A9B74 7F075044 46082202 */  mul.s $f8, $f4, $f8
/* 0A9B78 7F075048 46083180 */  add.s $f6, $f6, $f8
/* 0A9B7C 7F07504C C7A80028 */  lwc1  $f8, 0x28($sp)
/* 0A9B80 7F075050 E7AA0028 */  swc1  $f10, 0x28($sp)
/* 0A9B84 7F075054 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0A9B88 7F075058 46085282 */  mul.s $f10, $f10, $f8
/* 0A9B8C 7F07505C 46065280 */  add.s $f10, $f10, $f6
/* 0A9B90 7F075060 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 0A9B94 7F075064 46105082 */  mul.s $f2, $f10, $f16
/* 0A9B98 7F075068 00000000 */  nop   
/* 0A9B9C 7F07506C 46020282 */  mul.s $f10, $f0, $f2
/* 0A9BA0 7F075070 46065280 */  add.s $f10, $f10, $f6
/* 0A9BA4 7F075074 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 0A9BA8 7F075078 C4660014 */  lwc1  $f6, 0x14($v1)
/* 0A9BAC 7F07507C 46023282 */  mul.s $f10, $f6, $f2
/* 0A9BB0 7F075080 46045180 */  add.s $f6, $f10, $f4
/* 0A9BB4 7F075084 E7A600A0 */  swc1  $f6, 0xa0($sp)
/* 0A9BB8 7F075088 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0A9BBC 7F07508C 46025102 */  mul.s $f4, $f10, $f2
/* 0A9BC0 7F075090 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0A9BC4 7F075094 46082180 */  add.s $f6, $f4, $f8
/* 0A9BC8 7F075098 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 0A9BCC 7F07509C E7A600A4 */  swc1  $f6, 0xa4($sp)
/* 0A9BD0 7F0750A0 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0A9BD4 7F0750A4 C4660014 */  lwc1  $f6, 0x14($v1)
/* 0A9BD8 7F0750A8 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 0A9BDC 7F0750AC 46005102 */  mul.s $f4, $f10, $f0
/* 0A9BE0 7F0750B0 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0A9BE4 7F0750B4 46064182 */  mul.s $f6, $f8, $f6
/* 0A9BE8 7F0750B8 46062100 */  add.s $f4, $f4, $f6
/* 0A9BEC 7F0750BC C7A60024 */  lwc1  $f6, 0x24($sp)
/* 0A9BF0 7F0750C0 46065282 */  mul.s $f10, $f10, $f6
/* 0A9BF4 7F0750C4 46045280 */  add.s $f10, $f10, $f4
/* 0A9BF8 7F0750C8 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0A9BFC 7F0750CC 46105302 */  mul.s $f12, $f10, $f16
/* 0A9C00 7F0750D0 00000000 */  nop   
/* 0A9C04 7F0750D4 460C0282 */  mul.s $f10, $f0, $f12
/* 0A9C08 7F0750D8 46045280 */  add.s $f10, $f10, $f4
/* 0A9C0C 7F0750DC E7AA0090 */  swc1  $f10, 0x90($sp)
/* 0A9C10 7F0750E0 C4640014 */  lwc1  $f4, 0x14($v1)
/* 0A9C14 7F0750E4 460C2282 */  mul.s $f10, $f4, $f12
/* 0A9C18 7F0750E8 46085100 */  add.s $f4, $f10, $f8
/* 0A9C1C 7F0750EC E7A40094 */  swc1  $f4, 0x94($sp)
/* 0A9C20 7F0750F0 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0A9C24 7F0750F4 460C5202 */  mul.s $f8, $f10, $f12
/* 0A9C28 7F0750F8 46064100 */  add.s $f4, $f8, $f6
/* 0A9C2C 7F0750FC 1000004F */  b     .L7F07523C
/* 0A9C30 7F075100 E7A40098 */   swc1  $f4, 0x98($sp)
.L7F075104:
/* 0A9C34 7F075104 14400005 */  bnez  $v0, .L7F07511C
/* 0A9C38 7F075108 308C1000 */   andi  $t4, $a0, 0x1000
/* 0A9C3C 7F07510C 15800003 */  bnez  $t4, .L7F07511C
/* 0A9C40 7F075110 308A2000 */   andi  $t2, $a0, 0x2000
/* 0A9C44 7F075114 5140004A */  beql  $t2, $zero, .L7F075240
/* 0A9C48 7F075118 C7B2009C */   lwc1  $f18, 0x9c($sp)
.L7F07511C:
/* 0A9C4C 7F07511C C50A0018 */  lwc1  $f10, 0x18($t0)
/* 0A9C50 7F075120 308B1000 */  andi  $t3, $a0, 0x1000
/* 0A9C54 7F075124 10400008 */  beqz  $v0, .L7F075148
/* 0A9C58 7F075128 E7AA0060 */   swc1  $f10, 0x60($sp)
/* 0A9C5C 7F07512C C4680000 */  lwc1  $f8, ($v1)
/* 0A9C60 7F075130 E7A80054 */  swc1  $f8, 0x54($sp)
/* 0A9C64 7F075134 C4660004 */  lwc1  $f6, 4($v1)
/* 0A9C68 7F075138 E7A60058 */  swc1  $f6, 0x58($sp)
/* 0A9C6C 7F07513C C4640008 */  lwc1  $f4, 8($v1)
/* 0A9C70 7F075140 10000012 */  b     .L7F07518C
/* 0A9C74 7F075144 E7A4005C */   swc1  $f4, 0x5c($sp)
.L7F075148:
/* 0A9C78 7F075148 11600008 */  beqz  $t3, .L7F07516C
/* 0A9C7C 7F07514C 30992000 */   andi  $t9, $a0, 0x2000
/* 0A9C80 7F075150 C46A0010 */  lwc1  $f10, 0x10($v1)
/* 0A9C84 7F075154 E7AA0054 */  swc1  $f10, 0x54($sp)
/* 0A9C88 7F075158 C4680014 */  lwc1  $f8, 0x14($v1)
/* 0A9C8C 7F07515C E7A80058 */  swc1  $f8, 0x58($sp)
/* 0A9C90 7F075160 C4660018 */  lwc1  $f6, 0x18($v1)
/* 0A9C94 7F075164 10000009 */  b     .L7F07518C
/* 0A9C98 7F075168 E7A6005C */   swc1  $f6, 0x5c($sp)
.L7F07516C:
/* 0A9C9C 7F07516C 53200008 */  beql  $t9, $zero, .L7F075190
/* 0A9CA0 7F075170 C7AC0054 */   lwc1  $f12, 0x54($sp)
/* 0A9CA4 7F075174 C4640020 */  lwc1  $f4, 0x20($v1)
/* 0A9CA8 7F075178 E7A40054 */  swc1  $f4, 0x54($sp)
/* 0A9CAC 7F07517C C46A0024 */  lwc1  $f10, 0x24($v1)
/* 0A9CB0 7F075180 E7AA0058 */  swc1  $f10, 0x58($sp)
/* 0A9CB4 7F075184 C4680028 */  lwc1  $f8, 0x28($v1)
/* 0A9CB8 7F075188 E7A8005C */  swc1  $f8, 0x5c($sp)
.L7F07518C:
/* 0A9CBC 7F07518C C7AC0054 */  lwc1  $f12, 0x54($sp)
.L7F075190:
/* 0A9CC0 7F075190 C7B2009C */  lwc1  $f18, 0x9c($sp)
/* 0A9CC4 7F075194 C7AE0058 */  lwc1  $f14, 0x58($sp)
/* 0A9CC8 7F075198 C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0A9CCC 7F07519C 460C9182 */  mul.s $f6, $f18, $f12
/* 0A9CD0 7F0751A0 C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 0A9CD4 7F0751A4 460E2282 */  mul.s $f10, $f4, $f14
/* 0A9CD8 7F0751A8 460A3200 */  add.s $f8, $f6, $f10
/* 0A9CDC 7F0751AC C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 0A9CE0 7F0751B0 46068282 */  mul.s $f10, $f16, $f6
/* 0A9CE4 7F0751B4 46085280 */  add.s $f10, $f10, $f8
/* 0A9CE8 7F0751B8 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0A9CEC 7F0751BC 46085002 */  mul.s $f0, $f10, $f8
/* 0A9CF0 7F0751C0 E7A80030 */  swc1  $f8, 0x30($sp)
/* 0A9CF4 7F0751C4 46006282 */  mul.s $f10, $f12, $f0
/* 0A9CF8 7F0751C8 46125480 */  add.s $f18, $f10, $f18
/* 0A9CFC 7F0751CC 46007282 */  mul.s $f10, $f14, $f0
/* 0A9D00 7F0751D0 E7B2009C */  swc1  $f18, 0x9c($sp)
/* 0A9D04 7F0751D4 46045280 */  add.s $f10, $f10, $f4
/* 0A9D08 7F0751D8 46008102 */  mul.s $f4, $f16, $f0
/* 0A9D0C 7F0751DC E7AA00A0 */  swc1  $f10, 0xa0($sp)
/* 0A9D10 7F0751E0 46062280 */  add.s $f10, $f4, $f6
/* 0A9D14 7F0751E4 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 0A9D18 7F0751E8 E7AA00A4 */  swc1  $f10, 0xa4($sp)
/* 0A9D1C 7F0751EC 460C2182 */  mul.s $f6, $f4, $f12
/* 0A9D20 7F0751F0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 0A9D24 7F0751F4 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0A9D28 7F0751F8 460E5202 */  mul.s $f8, $f10, $f14
/* 0A9D2C 7F0751FC 46083180 */  add.s $f6, $f6, $f8
/* 0A9D30 7F075200 C7A80098 */  lwc1  $f8, 0x98($sp)
/* 0A9D34 7F075204 46088102 */  mul.s $f4, $f16, $f8
/* 0A9D38 7F075208 46062100 */  add.s $f4, $f4, $f6
/* 0A9D3C 7F07520C C7A60030 */  lwc1  $f6, 0x30($sp)
/* 0A9D40 7F075210 46062082 */  mul.s $f2, $f4, $f6
/* 0A9D44 7F075214 C7A6002C */  lwc1  $f6, 0x2c($sp)
/* 0A9D48 7F075218 46026102 */  mul.s $f4, $f12, $f2
/* 0A9D4C 7F07521C 46062100 */  add.s $f4, $f4, $f6
/* 0A9D50 7F075220 46027182 */  mul.s $f6, $f14, $f2
/* 0A9D54 7F075224 E7A40090 */  swc1  $f4, 0x90($sp)
/* 0A9D58 7F075228 460A3100 */  add.s $f4, $f6, $f10
/* 0A9D5C 7F07522C 46028182 */  mul.s $f6, $f16, $f2
/* 0A9D60 7F075230 E7A40094 */  swc1  $f4, 0x94($sp)
/* 0A9D64 7F075234 46083280 */  add.s $f10, $f6, $f8
/* 0A9D68 7F075238 E7AA0098 */  swc1  $f10, 0x98($sp)
.L7F07523C:
/* 0A9D6C 7F07523C C7B2009C */  lwc1  $f18, 0x9c($sp)
.L7F075240:
/* 0A9D70 7F075240 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 0A9D74 7F075244 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 0A9D78 7F075248 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0A9D7C 7F07524C 46049182 */  mul.s $f6, $f18, $f4
/* 0A9D80 7F075250 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0A9D84 7F075254 E7A40030 */  swc1  $f4, 0x30($sp)
/* 0A9D88 7F075258 46087282 */  mul.s $f10, $f14, $f8
/* 0A9D8C 7F07525C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A9D90 7F075260 00001025 */  move  $v0, $zero
/* 0A9D94 7F075264 460A3180 */  add.s $f6, $f6, $f10
/* 0A9D98 7F075268 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0A9D9C 7F07526C 46105102 */  mul.s $f4, $f10, $f16
/* 0A9DA0 7F075270 46062080 */  add.s $f2, $f4, $f6
/* 0A9DA4 7F075274 44802000 */  mtc1  $zero, $f4
/* 0A9DA8 7F075278 00000000 */  nop   
/* 0A9DAC 7F07527C 4602203C */  c.lt.s $f4, $f2
/* 0A9DB0 7F075280 00000000 */  nop   
/* 0A9DB4 7F075284 4500001A */  bc1f  .L7F0752F0
/* 0A9DB8 7F075288 00000000 */   nop   
/* 0A9DBC 7F07528C 46129182 */  mul.s $f6, $f18, $f18
/* 0A9DC0 7F075290 00000000 */  nop   
/* 0A9DC4 7F075294 460E7102 */  mul.s $f4, $f14, $f14
/* 0A9DC8 7F075298 46043180 */  add.s $f6, $f6, $f4
/* 0A9DCC 7F07529C 46108102 */  mul.s $f4, $f16, $f16
/* 0A9DD0 7F0752A0 46062000 */  add.s $f0, $f4, $f6
/* 0A9DD4 7F0752A4 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0A9DD8 7F0752A8 46042182 */  mul.s $f6, $f4, $f4
/* 0A9DDC 7F0752AC 00000000 */  nop   
/* 0A9DE0 7F0752B0 46084102 */  mul.s $f4, $f8, $f8
/* 0A9DE4 7F0752B4 46043200 */  add.s $f8, $f6, $f4
/* 0A9DE8 7F0752B8 460A5182 */  mul.s $f6, $f10, $f10
/* 0A9DEC 7F0752BC C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0A9DF0 7F0752C0 46021102 */  mul.s $f4, $f2, $f2
/* 0A9DF4 7F0752C4 46083300 */  add.s $f12, $f6, $f8
/* 0A9DF8 7F0752C8 460A6181 */  sub.s $f6, $f12, $f10
/* 0A9DFC 7F0752CC 46003202 */  mul.s $f8, $f6, $f0
/* 0A9E00 7F0752D0 4604403E */  c.le.s $f8, $f4
/* 0A9E04 7F0752D4 00000000 */  nop   
/* 0A9E08 7F0752D8 45000003 */  bc1f  .L7F0752E8
/* 0A9E0C 7F0752DC 00000000 */   nop   
/* 0A9E10 7F0752E0 10000003 */  b     .L7F0752F0
/* 0A9E14 7F0752E4 24020001 */   li    $v0, 1
.L7F0752E8:
/* 0A9E18 7F0752E8 10000001 */  b     .L7F0752F0
/* 0A9E1C 7F0752EC 00001025 */   move  $v0, $zero
.L7F0752F0:
/* 0A9E20 7F0752F0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A9E24 7F0752F4 03E00008 */  jr    $ra
/* 0A9E28 7F0752F8 27BD00B0 */   addiu $sp, $sp, 0xb0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0752FC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054DB4*/
glabel jpt_80054DB4
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F07543C
.word .L7F075470
.word .L7F0753CC
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075404
.word .L7F075450
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075464
.word .L7F075470

.text
glabel sub_GAME_7F0752FC
/* 0A9E2C 7F0752FC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A9E30 7F075300 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0A9E34 7F075304 AFB40028 */  sw    $s4, 0x28($sp)
/* 0A9E38 7F075308 AFB30024 */  sw    $s3, 0x24($sp)
/* 0A9E3C 7F07530C AFB20020 */  sw    $s2, 0x20($sp)
/* 0A9E40 7F075310 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A9E44 7F075314 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A9E48 7F075318 AFA7003C */  sw    $a3, 0x3c($sp)
/* 0A9E4C 7F07531C 8CE20000 */  lw    $v0, ($a3)
/* 0A9E50 7F075320 00809025 */  move  $s2, $a0
/* 0A9E54 7F075324 00A09825 */  move  $s3, $a1
/* 0A9E58 7F075328 00C0A025 */  move  $s4, $a2
/* 0A9E5C 7F07532C 10400004 */  beqz  $v0, .L7F075340
/* 0A9E60 7F075330 24110001 */   li    $s1, 1
/* 0A9E64 7F075334 00408025 */  move  $s0, $v0
/* 0A9E68 7F075338 10000003 */  b     .L7F075348
/* 0A9E6C 7F07533C ACE00000 */   sw    $zero, ($a3)
.L7F075340:
/* 0A9E70 7F075340 8E4F0008 */  lw    $t7, 8($s2)
/* 0A9E74 7F075344 8DF00000 */  lw    $s0, ($t7)
.L7F075348:
/* 0A9E78 7F075348 5200004C */  beql  $s0, $zero, .L7F07547C
/* 0A9E7C 7F07534C 00001025 */   move  $v0, $zero
.L7F075350:
/* 0A9E80 7F075350 12200006 */  beqz  $s1, .L7F07536C
/* 0A9E84 7F075354 00000000 */   nop   
/* 0A9E88 7F075358 8E020014 */  lw    $v0, 0x14($s0)
/* 0A9E8C 7F07535C 10400003 */  beqz  $v0, .L7F07536C
/* 0A9E90 7F075360 00000000 */   nop   
/* 0A9E94 7F075364 1000000D */  b     .L7F07539C
/* 0A9E98 7F075368 00408025 */   move  $s0, $v0
.L7F07536C:
/* 0A9E9C 7F07536C 12000009 */  beqz  $s0, .L7F075394
/* 0A9EA0 7F075370 00000000 */   nop   
/* 0A9EA4 7F075374 8E02000C */  lw    $v0, 0xc($s0)
.L7F075378:
/* 0A9EA8 7F075378 50400004 */  beql  $v0, $zero, .L7F07538C
/* 0A9EAC 7F07537C 8E100008 */   lw    $s0, 8($s0)
/* 0A9EB0 7F075380 10000004 */  b     .L7F075394
/* 0A9EB4 7F075384 00408025 */   move  $s0, $v0
/* 0A9EB8 7F075388 8E100008 */  lw    $s0, 8($s0)
.L7F07538C:
/* 0A9EBC 7F07538C 5600FFFA */  bnezl $s0, .L7F075378
/* 0A9EC0 7F075390 8E02000C */   lw    $v0, 0xc($s0)
.L7F075394:
/* 0A9EC4 7F075394 52000039 */  beql  $s0, $zero, .L7F07547C
/* 0A9EC8 7F075398 00001025 */   move  $v0, $zero
.L7F07539C:
/* 0A9ECC 7F07539C 96020000 */  lhu   $v0, ($s0)
/* 0A9ED0 7F0753A0 24110001 */  li    $s1, 1
/* 0A9ED4 7F0753A4 305800FF */  andi  $t8, $v0, 0xff
/* 0A9ED8 7F0753A8 2719FFFF */  addiu $t9, $t8, -1
/* 0A9EDC 7F0753AC 2F210018 */  sltiu $at, $t9, 0x18
/* 0A9EE0 7F0753B0 1020002F */  beqz  $at, .L7F075470
/* 0A9EE4 7F0753B4 0019C880 */   sll   $t9, $t9, 2
/* 0A9EE8 7F0753B8 3C018005 */  lui   $at, %hi(jpt_80054DB4)
/* 0A9EEC 7F0753BC 00390821 */  addu  $at, $at, $t9
/* 0A9EF0 7F0753C0 8C394DB4 */  lw    $t9, %lo(jpt_80054DB4)($at)
.L7F0753C4:
/* 0A9EF4 7F0753C4 03200008 */  jr    $t9
/* 0A9EF8 7F0753C8 00000000 */   nop   
.L7F0753CC:
/* 0A9EFC 7F0753CC 02402025 */  move  $a0, $s2
/* 0A9F00 7F0753D0 02002825 */  move  $a1, $s0
/* 0A9F04 7F0753D4 02603025 */  move  $a2, $s3
/* 0A9F08 7F0753D8 0FC1D31A */  jal   sub_GAME_7F074C68
/* 0A9F0C 7F0753DC 02803825 */   move  $a3, $s4
/* 0A9F10 7F0753E0 10400006 */  beqz  $v0, .L7F0753FC
/* 0A9F14 7F0753E4 00000000 */   nop   
/* 0A9F18 7F0753E8 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0A9F1C 7F0753EC AD100000 */  sw    $s0, ($t0)
/* 0A9F20 7F0753F0 8E090004 */  lw    $t1, 4($s0)
/* 0A9F24 7F0753F4 10000021 */  b     .L7F07547C
/* 0A9F28 7F0753F8 8D220000 */   lw    $v0, ($t1)
.L7F0753FC:
/* 0A9F2C 7F0753FC 1000001C */  b     .L7F075470
/* 0A9F30 7F075400 00008825 */   move  $s1, $zero
.L7F075404:
/* 0A9F34 7F075404 02402025 */  move  $a0, $s2
/* 0A9F38 7F075408 02002825 */  move  $a1, $s0
/* 0A9F3C 7F07540C 02603025 */  move  $a2, $s3
/* 0A9F40 7F075410 0FC1D32B */  jal   sub_GAME_7F074CAC
/* 0A9F44 7F075414 02803825 */   move  $a3, $s4
/* 0A9F48 7F075418 10400006 */  beqz  $v0, .L7F075434
/* 0A9F4C 7F07541C 00000000 */   nop   
/* 0A9F50 7F075420 8FAA003C */  lw    $t2, 0x3c($sp)
/* 0A9F54 7F075424 AD500000 */  sw    $s0, ($t2)
/* 0A9F58 7F075428 8E0B0004 */  lw    $t3, 4($s0)
/* 0A9F5C 7F07542C 10000013 */  b     .L7F07547C
/* 0A9F60 7F075430 8D620000 */   lw    $v0, ($t3)
.L7F075434:
/* 0A9F64 7F075434 1000000E */  b     .L7F075470
/* 0A9F68 7F075438 00008825 */   move  $s1, $zero
.L7F07543C:
/* 0A9F6C 7F07543C 02402025 */  move  $a0, $s2
/* 0A9F70 7F075440 0FC1BA5C */  jal   modelApplyDistanceRelations
/* 0A9F74 7F075444 02002825 */   move  $a1, $s0
/* 0A9F78 7F075448 10000009 */  b     .L7F075470
/* 0A9F7C 7F07544C 00000000 */   nop   
.L7F075450:
/* 0A9F80 7F075450 02402025 */  move  $a0, $s2
/* 0A9F84 7F075454 0FC1BA6F */  jal   modelApplyToggleRelations
/* 0A9F88 7F075458 02002825 */   move  $a1, $s0
/* 0A9F8C 7F07545C 10000004 */  b     .L7F075470
/* 0A9F90 7F075460 00000000 */   nop   
.L7F075464:
/* 0A9F94 7F075464 02402025 */  move  $a0, $s2
/* 0A9F98 7F075468 0FC1BA82 */  jal   modelApplyHeadRelations
/* 0A9F9C 7F07546C 02002825 */   move  $a1, $s0
def_7F0753C4:
.L7F075470:
/* 0A9FA0 7F075470 1600FFB7 */  bnez  $s0, .L7F075350
/* 0A9FA4 7F075474 00000000 */   nop   
/* 0A9FA8 7F075478 00001025 */  move  $v0, $zero
.L7F07547C:
/* 0A9FAC 7F07547C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0A9FB0 7F075480 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A9FB4 7F075484 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A9FB8 7F075488 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A9FBC 7F07548C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0A9FC0 7F075490 8FB40028 */  lw    $s4, 0x28($sp)
/* 0A9FC4 7F075494 03E00008 */  jr    $ra
/* 0A9FC8 7F075498 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F07549C(s32 arg0, f32 *arg1, f32 *arg2, ModelNode *arg3)
{
    //uses sh vs sw
    arg3->Opcode = 0;
    sub_GAME_7F0752FC(arg0, arg1, arg2, arg3);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F07549C
/* 0A9FCC 7F07549C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A9FD0 7F0754A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A9FD4 7F0754A4 0FC1D4BF */  jal   sub_GAME_7F0752FC
/* 0A9FD8 7F0754A8 ACE00000 */   sw    $zero, ($a3)
/* 0A9FDC 7F0754AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A9FE0 7F0754B0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A9FE4 7F0754B4 03E00008 */  jr    $ra
/* 0A9FE8 7F0754B8 00000000 */   nop   
)
#endif


s32 sub_GAME_7F0754BC(ModelAnimation* arg0, s32 arg1, ModelSkeleton* arg2)
{
    s32 ret;
    s32 var_a1;
    s32 shiftede;
    u32 tmp;
    u32 temp_a2_2;

    ret = 0;
    shiftede = arg0->unk0E >> 3;

    if (arg0->unk00 & 0x80000000)
    {
        ret = arg0->unk00 + (arg1 * shiftede);
    }
    else if (D_80036414 != NULL)
    {
        tmp = ((u32) (D_80036414->unk08 + 0xF) >> 4) * 0x10;
        ret = tmp;
        var_a1 = arg0->unk00 + (arg1 * shiftede);
        if (var_a1 & 1)
        {
            var_a1--;
            shiftede++;
            ret++;
        }
        temp_a2_2 = ((u32) (shiftede + 0xF) >> 4) * 0x10;
        romCopy((void* ) tmp, (void* ) var_a1, temp_a2_2);
        D_80036414->unk00 += 1;
        D_80036414->unk08 = tmp + temp_a2_2;
    }
    return ret;
}


void sub_GAME_7F0755B0(void)
{
    if (D_80036414 != NULL)
    {
        D_80036414->unk08 = D_80036414->unk04;
        D_80036414->unk00 = NULL;
    }
}


#define PROMOTE(var) \
    if (var) \
        var = (void *)((u32)var + diff)

void modelPromoteNodeOffsetsToPointers(ModelNode *node, u32 vma, u32 fileramaddr)
{
    s32 diff = fileramaddr - vma;
    s32 i;

    while (node)
    {
        u32 type = node->Opcode & 0xff;

        PROMOTE(node->Data);
        PROMOTE(node->Parent);
        PROMOTE(node->Next);
        PROMOTE(node->Prev);
        PROMOTE(node->Child);

        switch (type)
        {
            case MODELNODE_OPCODE_HEADER:
                {
                    ModelRoData_HeaderRecord* rodata = &node->Data->Header;
                    PROMOTE(rodata->FirstGroup);
                    break;
                }

            case MODELNODE_OPCODE_GROUP:
                {
                    ModelRoData_GroupRecord* rodata = &node->Data->Group;
                    PROMOTE(rodata->ChildGroup);
                    break;
                }

            case MODELNODE_OPCODE_OP03:
                {
                    ModelRoData_GroupRecord* rodata = &node->Data->Group;
                    PROMOTE(rodata->ChildGroup);
                    break;
                }

            case MODELNODE_OPCODE_DL:
                {
                    ModelRoData_DisplayListRecord* rodata = &node->Data->DisplayList;
                    PROMOTE(rodata->Vertices);
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_DLCOLLISION:
                {
                    ModelRoData_DisplayList_CollisionRecord* rodata = &node->Data->DisplayListCollisions;
                    PROMOTE(rodata->Vertices);
                    PROMOTE(rodata->CollisionVertices);
                    PROMOTE(rodata->PointUsage);
                    for (i = 0; i < rodata->numCollisionVertices; i++)
                    {
                        PROMOTE(rodata->CollisionVertices[i].LinkedTo);
                    }
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_OP20:
                {
                    ModelRoData_HeaderRecord* rodata = &node->Data->Header;
                    PROMOTE(rodata->FirstGroup);
                    break;
                }

            case MODELNODE_OPCODE_OP05:
                {
                    ModelRoData_Op05Record* rodata = &node->Data->Op05;

                    // shared with op07
                    PROMOTE(rodata->Children);
                    PROMOTE(rodata->Vertices);
                    PROMOTE(rodata->Images);
                    for (i = 0; i < rodata->NumChildren; i++)
                    {
                        PROMOTE(rodata->Children[i].unk04);
                    }

                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_OP07:
                {
                    ModelRoData_Op07Record* rodata = &node->Data->Op07;
                    PROMOTE(rodata->unk00);
                    PROMOTE(rodata->unk04);

                    // shared with op05
                    PROMOTE(rodata->Children);
                    PROMOTE(rodata->Vertices);
                    PROMOTE(rodata->Images);
                    for (i = 0; i < rodata->NumChildren; i++)
                    {
                        PROMOTE(rodata->Children[i].unk04);
                    }

                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_OP06:
                {
                    ModelRoData_Op06Record* rodata = &node->Data->Op06;
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_LOD:
                {
                    ModelRoData_LODRecord* rodata = &node->Data->LOD;
                    PROMOTE(rodata->Affects);
                    node->Child = rodata->Affects;
                    break;
                }

            case MODELNODE_OPCODE_SWITCH:
                {
                    ModelRoData_SwitchRecord* rodata = &node->Data->Switch;
                    PROMOTE(rodata->Controls);
                    break;
                }

            case MODELNODE_OPCODE_BSP:
                {
                    ModelRoData_BSPRecord* rodata = &node->Data->BSP;
                    PROMOTE(rodata->leftChild);
                    PROMOTE(rodata->rightChild);
                    break;
                }

            case MODELNODE_OPCODE_OP17:
                {
                    ModelRoData_GroupRecord* rodata = &node->Data->Group;
                    PROMOTE(rodata->ChildGroup);
                    break;
                }

            case MODELNODE_OPCODE_OP11:
                {
                    ModelRoData_Op11Record* rodata = &node->Data->Op11;
                    PROMOTE(rodata->unk0c[15]);
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_GUNFIRE:
                {
                    ModelRoData_GunfireRecord* rodata = &node->Data->Gunfire;
                    PROMOTE(rodata->Image);
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_SHADOW:
                {
                    ModelRoData_ShadowRecord* rodata = &node->Data->Shadow;
                    PROMOTE(rodata->image);
                    PROMOTE(rodata->Header);
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            case MODELNODE_OPCODE_DLPRIMARY:
                {
                    ModelRoData_DisplayListPrimaryRecord* rodata = &node->Data->DisplayListPrimary;
                    PROMOTE(rodata->Vertices);
                    rodata->BaseAddr = (void *)fileramaddr;
                    break;
                }

            default:
                break;
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void sub_GAME_7F075A90(ModelFileHeader *header, s32 vma, u32 addr) {
    s32 diff = addr - vma;
    s32 i;

    for(i = 0;i < header->numSwitches;i++)
    {
        PROMOTE(header->Switches[i]);
    }
    modelPromoteNodeOffsetsToPointers(header->RootNode, vma, addr);
}

void REMOVED_sub_GAME_7F075B08(s32 param_1,s32 param_2,s32 param_3,s32 param_4)
{
    return;
}


s32 modelCalculateRwDataIndexes(ModelNode *basenode)
{
    u16 len = 0;
    ModelNode *node = basenode;
    union ModelRoData *rodata;

    while (node)
    {
        u32 type = node->Opcode & 0xff;

        switch (type)
        {
            case MODELNODE_OPCODE_HEADER:
                if (1)
                {
                    ModelRoData_HeaderRecord *rodata = &node->Data->Header;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_HeaderRecord) / 4;
                    break;
                }
            case MODELNODE_OPCODE_OP07:
                if (1)
                {
                    ModelRoData_Op07Record *rodata = &node->Data->Op07;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_Op07Record) / 4;
                    break;
                }
            case MODELNODE_OPCODE_LOD:
                if (1)
                {
                    ModelRoData_LODRecord *rodata = &node->Data->LOD;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_LODRecord) / 4;
                    node->Child = rodata->Affects;
                    break;
                }
            case MODELNODE_OPCODE_SWITCH:
                if (1)
                {
                    ModelRoData_SwitchRecord *rodata = &node->Data->Switch;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_SwitchRecord) / 4;
                    node->Child = rodata->Controls;
                    break;
                }
            case MODELNODE_OPCODE_HEAD:
                if (1)
                {
                    ModelRoData_HeadPlaceholderRecord *rodata = &node->Data->HeadPlaceholder;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_HeadPlaceholderRecord) / 4;
                    node->Child = NULL;
                    break;
                }
            case MODELNODE_OPCODE_BSP:
                if (1)
                {
                    ModelRoData_BSPRecord *rodata = &node->Data->BSP;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_BSPRecord) / 4;
                    modelApplyReorderRelationsByArg(node, FALSE);
                    break;
                }
            case MODELNODE_OPCODE_OP11:
                if (1)
                {
                    ModelRoData_Op11Record *rodata = &node->Data->Op11;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_Op11Record) / 4;
                    break;
                }
            case MODELNODE_OPCODE_GUNFIRE:
                if (1)
                {
                    ModelRoData_GunfireRecord *rodata = &node->Data->Gunfire;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_GunfireRecord) / 4;
                    break;
                }
            case MODELNODE_OPCODE_DLCOLLISION:
                if (1)
                {
                    ModelRoData_DisplayList_CollisionRecord *rodata = &node->Data->DisplayListCollisions;
                    rodata->RwDataIndex = len;
                    len += sizeof(struct ModelRwData_DisplayList_CollisionRecord) / 4;
                    break;
                }
            default:
                break;
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node == basenode->Parent)
                {
                    node = NULL;
                    break;
                }

                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }

    return len;
}


void modelCalculateRwDataLen(struct ModelFileHeader *objheader)
{
  #if defined(LEFTOVERDEBUG)
    objheader->isLoaded = 1;
  #endif
    objheader->numRecords = modelCalculateRwDataIndexes(objheader->RootNode);
}


void modelInitRwData(Model *model, ModelNode *startnode)
{
    ModelNode *node = startnode;

    while (node)
    {
        u32 type = node->Opcode & 0xFF;

        switch (type)
        {
            case MODELNODE_OPCODE_HEADER:
                if (1)
                {
                    ModelRwData_HeaderRecord* rwdata = &modelGetNodeRwData(model, node)->Header;

                    rwdata->unk00 = 0;
                    rwdata->ground = 0;
                    rwdata->pos.x = 0;
                    rwdata->pos.y = 0;
                    rwdata->pos.z = 0;
                    rwdata->unk14 = 0;
                    rwdata->unk18 = 0;
                    rwdata->unk1c = 0;

                    rwdata->unk01 = 0;
                    rwdata->unk34.x = 0;
                    rwdata->unk34.y = 0;
                    rwdata->unk34.z = 0;
                    rwdata->unk30 = 0;
                    rwdata->unk24.x = 0;
                    rwdata->unk24.y = 0;
                    rwdata->unk24.z = 0;
                    rwdata->unk20 = 0;

                    rwdata->unk02 = 0;
                    rwdata->unk4c.x = 0;
                    rwdata->unk4c.y = 0;
                    rwdata->unk4c.z = 0;
                    rwdata->unk40.x = 0;
                    rwdata->unk40.y = 0;
                    rwdata->unk40.z = 0;
                    rwdata->unk5c = 0;
                    break;
                }

            case MODELNODE_OPCODE_OP07:
                if (1)
                {
                    ModelRwData_Op07Record* rwdata = &modelGetNodeRwData(model, node)->Op07;
                    rwdata->index = 0;
                    break;
                }


            case MODELNODE_OPCODE_LOD:
                if (1)
                {
                    ModelRoData_LODRecord* rodata = &node->Data->LOD;
                    ModelRwData_LODRecord* rwdata = &modelGetNodeRwData(model, node)->LOD;
                    rwdata->visible = FALSE;
                    node->Child = rodata->Affects;
                    break;
                }

            case MODELNODE_OPCODE_SWITCH:
                if (1)
                {
                    ModelRoData_SwitchRecord* rodata = &node->Data->Switch;
                    ModelRwData_SwitchRecord* rwdata = &modelGetNodeRwData(model, node)->Switch;
                    rwdata->visible = TRUE;
                    node->Child = rodata->Controls;
                    break;
                }

            case MODELNODE_OPCODE_HEAD:
                if (1)
                {
                    ModelRwData_HeadPlaceholderRecord* rwdata = &modelGetNodeRwData(model, node)->HeadPlaceholder;
                    rwdata->ModelFileHeader = NULL;
                    rwdata->RwDatas = NULL;
                    break;
                }

            case MODELNODE_OPCODE_BSP:
                if (1)
                {
                    ModelRwData_BSPRecord* rwdata = &modelGetNodeRwData(model, node)->BSP;
                    rwdata->visible = FALSE;
                    modelApplyReorderRelations(model, node);
                    break;
                }

            case MODELNODE_OPCODE_OP11:
                if (1)
                {
                    ModelRwData_Op11Record* rwdata = &modelGetNodeRwData(model, node)->Op11;
                    rwdata->unk00 = FALSE;
                    break;
                }

            case MODELNODE_OPCODE_GUNFIRE:
                if (1)
                {
                    ModelRwData_GunfireRecord* rwdata = &modelGetNodeRwData(model, node)->Gunfire;
                    rwdata->visible = FALSE;
                    break;
                }

            case MODELNODE_OPCODE_DLCOLLISION:
                if (1)
                {
                    ModelRoData_DisplayList_CollisionRecord* rodata = &node->Data->DisplayListCollisions;
                    ModelRwData_DisplayList_CollisionRecord* rwdata = &modelGetNodeRwData(model, node)->DisplayListCollisions;
                    rwdata->Vertices = rodata->Vertices;
                    rwdata->gdl = rodata->Primary;
                    break;
                }

            default:
                break;
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node == startnode->Parent)
                {
                    node = NULL;
                    break;
                }

                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void modelInit(struct Model *objinst, struct ModelFileHeader *header, u32 *data)
{
  objinst->obj = header;
  objinst->datas = data;
  objinst->Type = -1;
  objinst->attachedto = NULL;
  objinst->attachedto_objinst = NULL;
  objinst->scale = 1.0;
  modelInitRwData(objinst, header->RootNode);
}


// PD: animInit
void animInit(struct Model *objinst, struct ModelFileHeader *header, u32 *data)
{    
    modelInit(objinst, header, data);
    objinst->anim = NULL;
    objinst->anim2 = NULL;
    objinst->animlooping = 0;
    objinst->animflipfunc = 0;
    objinst->unk9c = 0;
    objinst->unka0 = 0;
    objinst->unk2c = 0.0f;
    objinst->timespeed = 0.0f;
    objinst->unk5c = 0.0f;
    objinst->unk7c = 0.0f;
    objinst->unk84 = 0.0f;
    objinst->unk88 = 0.0f;
    objinst->unkb0 = 0.0f;
    objinst->speed = 1.0f;
    objinst->speed2 = 1.0f;
    objinst->playspeed = 1.0f;
    objinst->unkb8 = 1.0f;
    objinst->endframe = -1.0f;
    objinst->unk6c = -1.0f;
}


// PD: model00023108
void modelAttachPart(Model *pmodel, ModelFileHeader *pmodeldef, ModelNode *pnode, ModelFileHeader *cmodeldef)
{
    ModelRwData_HeadPlaceholderRecord *rwdata = modelGetNodeRwData(pmodel, pnode);
    ModelNode *node;

    rwdata->ModelFileHeader = cmodeldef;
    rwdata->RwDatas = &pmodel->datas[pmodeldef->numRecords];

    pnode->Child = cmodeldef->RootNode;

    node = pnode->Child;

    while (node)
    {
        node->Parent = pnode;
        node = node->Next;
    }

    pmodeldef->numRecords += modelCalculateRwDataIndexes(pnode->Child);
}


/**
 * This function can be called repeatedly to iterate a model's display lists.
 *
 * On the first call, the value passed as nodeptr should point to a NULL value.
 * Each time the function is called, it will update *gdlptr to point to the next
 * display list, and will update *nodeptr to point to the current node. On
 * subsequent calls, the same values should be passed as nodeptr and gdlptr so
 * the function can continue correctly.
 *
 * Note that some node types support multiple display lists, so the function
 * may return the same node while it iterates the display lists for that node.
 */
void modelIterateDisplayLists(ModelFileHeader *fileheader, ModelNode **nodeptr, Gfx **gdlptr)
{
    ModelNode *node = *nodeptr;
    union ModelRoData *rodata;
    Gfx *gdl = NULL;

    if (node == NULL)
    {
        node = fileheader->RootNode;
    }

    while (node)
    {
        u32 type = node->Opcode & 0xff;

        switch (type)
        {
            case MODELNODE_OPCODE_DL:
                rodata = node->Data;

                if (node != *nodeptr)
                {
                    gdl = rodata->DisplayList.Primary;
                }
                else if (rodata->DisplayList.Secondary != *gdlptr)
                {
                    gdl = rodata->DisplayList.Secondary;
                }
                break;

            case MODELNODE_OPCODE_DLCOLLISION:
                rodata = node->Data;

                if (node != *nodeptr)
                {
                    gdl = rodata->DisplayListCollisions.Primary;
                }
                else if (rodata->DisplayListCollisions.Secondary != *gdlptr)
                {
                    gdl = rodata->DisplayListCollisions.Secondary;
                }
                break;

            case MODELNODE_OPCODE_DLPRIMARY:
                rodata = node->Data;

                if (node != *nodeptr)
                {
                    gdl = rodata->DisplayListPrimary.Primary;
                }
                break;

            case MODELNODE_OPCODE_LOD:
                rodata = node->Data;
                node->Child = rodata->LOD.Affects;
                break;

            case MODELNODE_OPCODE_SWITCH:
                rodata = node->Data;
                node->Child = rodata->Switch.Controls;
                break;

            case MODELNODE_OPCODE_BSP:
                modelApplyReorderRelationsByArg(node, TRUE);
                break;
        }

        if (gdl) { break; }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }

    *gdlptr = gdl;
    *nodeptr = node;
}


void modelNodeReplaceGdl(u32 arg0, ModelNode *node, Gfx *find, Gfx *replacement)
{
    union ModelRoData *rodata;
    u32 type = node->Opcode & 0xff;

    switch (type) {
        case MODELNODE_OPCODE_DL:
            rodata = node->Data;

            if (rodata->DisplayList.Primary == find)
            {
                rodata->DisplayList.Primary = replacement;
                return;
            }

            if (rodata->DisplayList.Secondary == find)
            {
                rodata->DisplayList.Secondary = replacement;
                return;
            }
            break;

        case MODELNODE_OPCODE_DLCOLLISION:
            rodata = node->Data;

            if (rodata->DisplayListCollisions.Primary == find)
            {
                rodata->DisplayListCollisions.Primary = replacement;
                return;
            }

            if (rodata->DisplayListCollisions.Secondary == find)
            {
                rodata->DisplayListCollisions.Secondary = replacement;
                return;
            }
            break;

        case MODELNODE_OPCODE_DLPRIMARY:
            rodata = node->Data;

            if (rodata->DisplayListPrimary.Primary == find)
            {
                rodata->DisplayListPrimary.Primary = replacement;
                return;
            }
            break;
    }
}
