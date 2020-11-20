#include "ultra64.h"

//D:80054600
const char aGetsubmatrixNoObjinst[] = "getsubmatrix: no objinst!\n";
//D:8005461C
const char aGetsubmatrixObjinstHasNoObject[] = "getsubmatrix: objinst has no object!\n";
//D:80054644
const char aGetpartoffsetNoObjinst[] = "getpartoffset: no objinst!";
//D:80054660
const char aGetpartoffsetNoPartdesc[] = "getpartoffset: no partdesc!";
//D:8005467C
const char aSetpartoffsetNoObjinst[] = "setpartoffset: no objinst!";
//D:80054698
const char aSetpartoffsetNoPartdesc[] = "setpartoffset: no partdesc!";
//D:800546B4
const char aGetsuboffsetNoObjinst[] = "getsuboffset: no objinst!";
//D:800546D0
const char aGetsuboffsetObjinstHasNoObject[] = "getsuboffset: objinst has no object!";
//D:800546F8
const char aSetsuboffsetNoObjinst[] = "setsuboffset: no objinst!";
//D:80054714
const char aSetsuboffsetObjinstHasNoObject[] = "setsuboffset: objinst has no object!";
//D:8005473C
const char aGetsubrotyNoObjinst[] = "getsubroty: no objinst!";
//D:80054754
const char aGetsubrotyObjinstHasNoObject[] = "getsubroty: objinst has no object!";
//D:80054778
const char aGetsubrotyObjinstHasNoRootPart[] = "getsubroty: objinst has no root part!";
//D:800547A0
const char aSetsubrotyNoObjinst[] = "setsubroty: no objinst!";
//D:800547B8
const char aSetsubrotyObjinstHasNoObject[] = "setsubroty: objinst has no object!";
//D:800547DC
const char aSetsubrotyObjinstHasNoRootPart[] = "setsubroty: objinst has no root part!";
//D:80054804
const char aGetjointsizeNoObjinst[] = "getjointsize: no objinst!\n";
//D:80054820
const char aGetinstsizeNoObjinst[] = "getinstsize: no objinst!\n";
//D:8005483C
const char aGetinstsizeNoObjdesc[] = "getinstsize: no objdesc!\n";
//D:80054858
const char aSubcalcposNoObjanim[] = "subcalcpos: no objanim!\n";
//D:80054874
const char aSubcalcposNoObjdesc[] = "subcalcpos: no objdesc!\n";
//D:80054890
const char aInstcalcmatricesNoObjinst[] = "instcalcmatrices: no objinst!\n";
//D:800548B0
const char aInstcalcmatricesNoBasemtx[] = "instcalcmatrices: no basemtx!\n";
//D:800548D0
const char aInstcalcmatricesNoMtxlist[] = "instcalcmatrices: no mtxlist!\n";
//D:800548F0
const char aSubcalcmatricesNoObjanim[] = "subcalcmatrices: no objanim!\n";
//D:80054910
const char aSubcalcmatricesNoBasemtx[] = "subcalcmatrices: no basemtx!\n";
//D:80054930
const char aSubcalcmatricesNoMtxlist[] = "subcalcmatrices: no mtxlist!\n";
//D:80054950
const char aSubcalcmatricesNoAttachForObjinst[] = "subcalcmatrices: no attach for objinst!\n";
//D:8005497C
const char aSubcalcmatricesFrameaOutOfRange[] = "subcalcmatrices: framea out of range!\n";
//D:800549A4
const char aSubcalcmatricesFramebOutOfRange[] = "subcalcmatrices: frameb out of range!\n";
//D:800549CC
const char aSubcalcmatricesNoAnim2[] = "subcalcmatrices: no anim2!\n";
//D:800549E8
const char aSubcalcmatricesFrame2aOutOfRange[] = "subcalcmatrices: frame2a out of range!\n";
//D:80054A10
const char aSubcalcmatricesFrame2bOutOfRange[] = "subcalcmatrices: frame2b out of range!\n";
//D:80054A38
const char aDorottexNoVtxAllocator[] = "dorottex: no vtx allocator!\n";
//D:80054A58
const char aDotubeNoVtxAllocator[] = "dotube: no vtx allocator!\n";
//D:80054A74
const char aDogfnegxNoVtxAllocator[] = "dogfnegx: no vtx allocator!\n";
//D:80054A94
const char aDoshadowNoVtxAllocator[] = "doshadow: no vtx allocator!\n";
//D:80054AB4
const char aSubdrawNoGfxlist[] = "subdraw: no gfxlist!\n";
//D:80054ACC
const char aSubdrawObjectNotInitialised0xX[] = "subdraw: object not initialised! (0x%X)\n";

/*
*/

/*
*/

/*
*/

/*
*/


#ifdef NONMATCHING
void getsubmatrix(void) {

}
#else
GLOBAL_ASM(
.late_rodata


.text
glabel getsubmatrix
/* 0A11D0 7F06C6A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A11D4 7F06C6A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A11D8 7F06C6A8 14800006 */  bnez  $a0, .L7F06C6C4
/* 0A11DC 7F06C6AC AFA40018 */   sw    $a0, 0x18($sp)
/* 0A11E0 7F06C6B0 3C048005 */  lui   $a0, %hi(aGetsubmatrixNoObjinst)
/* 0A11E4 7F06C6B4 0C0033D1 */  jal   osSyncPrintf
/* 0A11E8 7F06C6B8 24844600 */   addiu $a0, %lo(aGetsubmatrixNoObjinst) # addiu $a0, $a0, 0x4600
/* 0A11EC 7F06C6BC 0FC1B11B */  jal   return_null
/* 0A11F0 7F06C6C0 00000000 */   nop   
.L7F06C6C4:
/* 0A11F4 7F06C6C4 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A11F8 7F06C6C8 3C048005 */  lui   $a0, %hi(aGetsubmatrixObjinstHasNoObject)
/* 0A11FC 7F06C6CC 8DE20008 */  lw    $v0, 8($t7)
/* 0A1200 7F06C6D0 54400008 */  bnezl $v0, .L7F06C6F4
/* 0A1204 7F06C6D4 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A1208 7F06C6D8 0C0033D1 */  jal   osSyncPrintf
/* 0A120C 7F06C6DC 2484461C */   addiu $a0, $a0, %lo(aGetsubmatrixObjinstHasNoObject)
/* 0A1210 7F06C6E0 0FC1B11B */  jal   return_null
/* 0A1214 7F06C6E4 00000000 */   nop   
/* 0A1218 7F06C6E8 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A121C 7F06C6EC 8F020008 */  lw    $v0, 8($t8)
/* 0A1220 7F06C6F0 8FA40018 */  lw    $a0, 0x18($sp)
.L7F06C6F4:
/* 0A1224 7F06C6F4 8C450000 */  lw    $a1, ($v0)
/* 0A1228 7F06C6F8 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A122C 7F06C6FC 00003025 */   move  $a2, $zero
/* 0A1230 7F06C700 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A1234 7F06C704 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1238 7F06C708 03E00008 */  jr    $ra
/* 0A123C 7F06C70C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06C710(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C710
/* 0A1240 7F06C710 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A1244 7F06C714 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A1248 7F06C718 0FC1B1A8 */  jal   getsubmatrix
/* 0A124C 7F06C71C AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A1250 7F06C720 10400008 */  beqz  $v0, .L7F06C744
/* 0A1254 7F06C724 8FA5001C */   lw    $a1, 0x1c($sp)
/* 0A1258 7F06C728 C4440030 */  lwc1  $f4, 0x30($v0)
/* 0A125C 7F06C72C E4A40000 */  swc1  $f4, ($a1)
/* 0A1260 7F06C730 C4460034 */  lwc1  $f6, 0x34($v0)
/* 0A1264 7F06C734 E4A60004 */  swc1  $f6, 4($a1)
/* 0A1268 7F06C738 C4480038 */  lwc1  $f8, 0x38($v0)
/* 0A126C 7F06C73C 10000006 */  b     .L7F06C758
/* 0A1270 7F06C740 E4A80008 */   swc1  $f8, 8($a1)
.L7F06C744:
/* 0A1274 7F06C744 44800000 */  mtc1  $zero, $f0
/* 0A1278 7F06C748 00000000 */  nop   
/* 0A127C 7F06C74C E4A00000 */  swc1  $f0, ($a1)
/* 0A1280 7F06C750 E4A00004 */  swc1  $f0, 4($a1)
/* 0A1284 7F06C754 E4A00008 */  swc1  $f0, 8($a1)
.L7F06C758:
/* 0A1288 7F06C758 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A128C 7F06C75C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1290 7F06C760 03E00008 */  jr    $ra
/* 0A1294 7F06C764 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06C768(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C768
/* 0A1298 7F06C768 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A129C 7F06C76C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A12A0 7F06C770 0FC1B1A8 */  jal   getsubmatrix
/* 0A12A4 7F06C774 00000000 */   nop   
/* 0A12A8 7F06C778 10400004 */  beqz  $v0, .L7F06C78C
/* 0A12AC 7F06C77C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A12B0 7F06C780 C4400038 */  lwc1  $f0, 0x38($v0)
/* 0A12B4 7F06C784 10000003 */  b     .L7F06C794
/* 0A12B8 7F06C788 46000007 */   neg.s $f0, $f0
.L7F06C78C:
/* 0A12BC 7F06C78C 44800000 */  mtc1  $zero, $f0
/* 0A12C0 7F06C790 00000000 */  nop   
.L7F06C794:
/* 0A12C4 7F06C794 03E00008 */  jr    $ra
/* 0A12C8 7F06C798 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void extract_id_from_object_structure_microcode(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054AF8*/
glabel jpt_obj_struct_microcode_id
.word .L7F06C7D8
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C7F0
.word .L7F06C7FC
.word .L7F06C814
.word .L7F06C840
.word .L7F06C820
.word .L7F06C82C
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C808
.word .L7F06C840
.word .L7F06C840
/*.word .L7F06C840*/
/*.word .L7F06C840*/
/*.word .L7F06C838*/
/*.word .L7F06C7E4*/

.text
glabel extract_id_from_object_structure_microcode
/* 0A12CC 7F06C79C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A12D0 7F06C7A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A12D4 7F06C7A4 94AE0000 */  lhu   $t6, ($a1)
/* 0A12D8 7F06C7A8 00003025 */  move  $a2, $zero
/* 0A12DC 7F06C7AC 8C870010 */  lw    $a3, 0x10($a0)
/* 0A12E0 7F06C7B0 31CF00FF */  andi  $t7, $t6, 0xff
/* 0A12E4 7F06C7B4 25F8FFFF */  addiu $t8, $t7, -1
/* 0A12E8 7F06C7B8 2F010018 */  sltiu $at, $t8, 0x18
/* 0A12EC 7F06C7BC 10200020 */  beqz  $at, .L7F06C840
/* 0A12F0 7F06C7C0 0018C080 */   sll   $t8, $t8, 2
/* 0A12F4 7F06C7C4 3C018005 */  lui   $at, %hi(jpt_obj_struct_microcode_id)
/* 0A12F8 7F06C7C8 00380821 */  addu  $at, $at, $t8
/* 0A12FC 7F06C7CC 8C384AF8 */  lw    $t8, %lo(jpt_obj_struct_microcode_id)($at)
.L7F06C7D0:
/* 0A1300 7F06C7D0 03000008 */  jr    $t8
/* 0A1304 7F06C7D4 00000000 */   nop   
.L7F06C7D8:
/* 0A1308 7F06C7D8 8CB90004 */  lw    $t9, 4($a1)
/* 0A130C 7F06C7DC 10000018 */  b     .L7F06C840
/* 0A1310 7F06C7E0 9726000C */   lhu   $a2, 0xc($t9)
.L7F06C7E4:
/* 0A1314 7F06C7E4 8CA80004 */  lw    $t0, 4($a1)
/* 0A1318 7F06C7E8 10000015 */  b     .L7F06C840
/* 0A131C 7F06C7EC 9506001A */   lhu   $a2, 0x1a($t0)
.L7F06C7F0:
/* 0A1320 7F06C7F0 8CA90004 */  lw    $t1, 4($a1)
/* 0A1324 7F06C7F4 10000012 */  b     .L7F06C840
/* 0A1328 7F06C7F8 952601AA */   lhu   $a2, 0x1aa($t1)
.L7F06C7FC:
/* 0A132C 7F06C7FC 8CAA0004 */  lw    $t2, 4($a1)
/* 0A1330 7F06C800 1000000F */  b     .L7F06C840
/* 0A1334 7F06C804 9546000C */   lhu   $a2, 0xc($t2)
.L7F06C808:
/* 0A1338 7F06C808 8CAB0004 */  lw    $t3, 4($a1)
/* 0A133C 7F06C80C 1000000C */  b     .L7F06C840
/* 0A1340 7F06C810 95660004 */   lhu   $a2, 4($t3)
.L7F06C814:
/* 0A1344 7F06C814 8CAC0004 */  lw    $t4, 4($a1)
/* 0A1348 7F06C818 10000009 */  b     .L7F06C840
/* 0A134C 7F06C81C 95860022 */   lhu   $a2, 0x22($t4)
.L7F06C820:
/* 0A1350 7F06C820 8CAD0004 */  lw    $t5, 4($a1)
/* 0A1354 7F06C824 10000006 */  b     .L7F06C840
/* 0A1358 7F06C828 95A60044 */   lhu   $a2, 0x44($t5)
.L7F06C82C:
/* 0A135C 7F06C82C 8CAE0004 */  lw    $t6, 4($a1)
/* 0A1360 7F06C830 10000003 */  b     .L7F06C840
/* 0A1364 7F06C834 95C60020 */   lhu   $a2, 0x20($t6)
.L7F06C838:
/* 0A1368 7F06C838 8CAF0004 */  lw    $t7, 4($a1)
/* 0A136C 7F06C83C 95E60000 */  lhu   $a2, ($t7)
def_7F06C7D0:
.L7F06C840:
/* 0A1370 7F06C840 8CA20008 */  lw    $v0, 8($a1)
/* 0A1374 7F06C844 24030017 */  li    $v1, 23
/* 0A1378 7F06C848 5040000F */  beql  $v0, $zero, .L7F06C888
/* 0A137C 7F06C84C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A1380 7F06C850 94580000 */  lhu   $t8, ($v0)
.L7F06C854:
/* 0A1384 7F06C854 00402825 */  move  $a1, $v0
/* 0A1388 7F06C858 331900FF */  andi  $t9, $t8, 0xff
/* 0A138C 7F06C85C 54790007 */  bnel  $v1, $t9, .L7F06C87C
/* 0A1390 7F06C860 8CA20008 */   lw    $v0, 8($a1)
/* 0A1394 7F06C864 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A1398 7F06C868 AFA6001C */   sw    $a2, 0x1c($sp)
/* 0A139C 7F06C86C 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0A13A0 7F06C870 10000004 */  b     .L7F06C884
/* 0A13A4 7F06C874 8C470004 */   lw    $a3, 4($v0)
/* 0A13A8 7F06C878 8CA20008 */  lw    $v0, 8($a1)
.L7F06C87C:
/* 0A13AC 7F06C87C 5440FFF5 */  bnezl $v0, .L7F06C854
/* 0A13B0 7F06C880 94580000 */   lhu   $t8, ($v0)
.L7F06C884:
/* 0A13B4 7F06C884 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06C888:
/* 0A13B8 7F06C888 00064080 */  sll   $t0, $a2, 2
/* 0A13BC 7F06C88C 01071021 */  addu  $v0, $t0, $a3
/* 0A13C0 7F06C890 03E00008 */  jr    $ra
/* 0A13C4 7F06C894 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void getpartoffset(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*HACKY, above jtable too big*/
.word .L7F06C840
.word .L7F06C840
.word .L7F06C838
.word .L7F06C7E4

.text
glabel getpartoffset
/* 0A13C8 7F06C898 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A13CC 7F06C89C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A13D0 7F06C8A0 1480000A */  bnez  $a0, .L7F06C8CC
/* 0A13D4 7F06C8A4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0A13D8 7F06C8A8 3C048005 */  lui   $a0, %hi(aGetpartoffsetNoObjinst)
/* 0A13DC 7F06C8AC 24844644 */  addiu $a0, %lo(aGetpartoffsetNoObjinst) # addiu $a0, $a0, 0x4644
/* 0A13E0 7F06C8B0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0A13E4 7F06C8B4 0C0033D1 */  jal   osSyncPrintf
/* 0A13E8 7F06C8B8 AFA60020 */   sw    $a2, 0x20($sp)
/* 0A13EC 7F06C8BC 0FC1B11B */  jal   return_null
/* 0A13F0 7F06C8C0 00000000 */   nop   
/* 0A13F4 7F06C8C4 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0A13F8 7F06C8C8 8FA60020 */  lw    $a2, 0x20($sp)
.L7F06C8CC:
/* 0A13FC 7F06C8CC 14A00009 */  bnez  $a1, .L7F06C8F4
/* 0A1400 7F06C8D0 3C048005 */   lui   $a0, %hi(aGetpartoffsetNoPartdesc)
/* 0A1404 7F06C8D4 24844660 */  addiu $a0, %lo(aGetpartoffsetNoPartdesc) # addiu $a0, $a0, 0x4660
/* 0A1408 7F06C8D8 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0A140C 7F06C8DC 0C0033D1 */  jal   osSyncPrintf
/* 0A1410 7F06C8E0 AFA60020 */   sw    $a2, 0x20($sp)
/* 0A1414 7F06C8E4 0FC1B11B */  jal   return_null
/* 0A1418 7F06C8E8 00000000 */   nop   
/* 0A141C 7F06C8EC 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0A1420 7F06C8F0 8FA60020 */  lw    $a2, 0x20($sp)
.L7F06C8F4:
/* 0A1424 7F06C8F4 94A20000 */  lhu   $v0, ($a1)
/* 0A1428 7F06C8F8 24010001 */  li    $at, 1
/* 0A142C 7F06C8FC 8FA40018 */  lw    $a0, 0x18($sp)
/* 0A1430 7F06C900 304F00FF */  andi  $t7, $v0, 0xff
/* 0A1434 7F06C904 11E1000D */  beq   $t7, $at, .L7F06C93C
/* 0A1438 7F06C908 24010002 */   li    $at, 2
/* 0A143C 7F06C90C 11E10015 */  beq   $t7, $at, .L7F06C964
/* 0A1440 7F06C910 24010003 */   li    $at, 3
/* 0A1444 7F06C914 11E1001B */  beq   $t7, $at, .L7F06C984
/* 0A1448 7F06C918 24010015 */   li    $at, 21
/* 0A144C 7F06C91C 51E10022 */  beql  $t7, $at, .L7F06C9A8
/* 0A1450 7F06C920 8CA20004 */   lw    $v0, 4($a1)
/* 0A1454 7F06C924 44800000 */  mtc1  $zero, $f0
/* 0A1458 7F06C928 00000000 */  nop   
/* 0A145C 7F06C92C E4C00000 */  swc1  $f0, ($a2)
/* 0A1460 7F06C930 E4C00004 */  swc1  $f0, 4($a2)
/* 0A1464 7F06C934 10000022 */  b     .L7F06C9C0
/* 0A1468 7F06C938 E4C00008 */   swc1  $f0, 8($a2)
.L7F06C93C:
/* 0A146C 7F06C93C 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A1470 7F06C940 AFA60020 */   sw    $a2, 0x20($sp)
/* 0A1474 7F06C944 8FA60020 */  lw    $a2, 0x20($sp)
/* 0A1478 7F06C948 C4440008 */  lwc1  $f4, 8($v0)
/* 0A147C 7F06C94C E4C40000 */  swc1  $f4, ($a2)
/* 0A1480 7F06C950 C446000C */  lwc1  $f6, 0xc($v0)
/* 0A1484 7F06C954 E4C60004 */  swc1  $f6, 4($a2)
/* 0A1488 7F06C958 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0A148C 7F06C95C 10000018 */  b     .L7F06C9C0
/* 0A1490 7F06C960 E4C80008 */   swc1  $f8, 8($a2)
.L7F06C964:
/* 0A1494 7F06C964 8CA20004 */  lw    $v0, 4($a1)
/* 0A1498 7F06C968 C44A0000 */  lwc1  $f10, ($v0)
/* 0A149C 7F06C96C E4CA0000 */  swc1  $f10, ($a2)
/* 0A14A0 7F06C970 C4500004 */  lwc1  $f16, 4($v0)
/* 0A14A4 7F06C974 E4D00004 */  swc1  $f16, 4($a2)
/* 0A14A8 7F06C978 C4520008 */  lwc1  $f18, 8($v0)
/* 0A14AC 7F06C97C 10000010 */  b     .L7F06C9C0
/* 0A14B0 7F06C980 E4D20008 */   swc1  $f18, 8($a2)
.L7F06C984:
/* 0A14B4 7F06C984 8CA20004 */  lw    $v0, 4($a1)
/* 0A14B8 7F06C988 C4440000 */  lwc1  $f4, ($v0)
/* 0A14BC 7F06C98C E4C40000 */  swc1  $f4, ($a2)
/* 0A14C0 7F06C990 C4460004 */  lwc1  $f6, 4($v0)
/* 0A14C4 7F06C994 E4C60004 */  swc1  $f6, 4($a2)
/* 0A14C8 7F06C998 C4480008 */  lwc1  $f8, 8($v0)
/* 0A14CC 7F06C99C 10000008 */  b     .L7F06C9C0
/* 0A14D0 7F06C9A0 E4C80008 */   swc1  $f8, 8($a2)
/* 0A14D4 7F06C9A4 8CA20004 */  lw    $v0, 4($a1)
.L7F06C9A8:
/* 0A14D8 7F06C9A8 C44A0000 */  lwc1  $f10, ($v0)
/* 0A14DC 7F06C9AC E4CA0000 */  swc1  $f10, ($a2)
/* 0A14E0 7F06C9B0 C4500004 */  lwc1  $f16, 4($v0)
/* 0A14E4 7F06C9B4 E4D00004 */  swc1  $f16, 4($a2)
/* 0A14E8 7F06C9B8 C4520008 */  lwc1  $f18, 8($v0)
/* 0A14EC 7F06C9BC E4D20008 */  swc1  $f18, 8($a2)
.L7F06C9C0:
/* 0A14F0 7F06C9C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A14F4 7F06C9C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A14F8 7F06C9C8 03E00008 */  jr    $ra
/* 0A14FC 7F06C9CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void setpartoffset(void) {

}
#else
GLOBAL_ASM(
.text
glabel setpartoffset
/* 0A1500 7F06C9D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0A1504 7F06C9D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A1508 7F06C9D8 1480000A */  bnez  $a0, .L7F06CA04
/* 0A150C 7F06C9DC AFA40028 */   sw    $a0, 0x28($sp)
/* 0A1510 7F06C9E0 3C048005 */  lui   $a0, %hi(aSetpartoffsetNoObjinst)
/* 0A1514 7F06C9E4 2484467C */  addiu $a0, %lo(aSetpartoffsetNoObjinst) # addiu $a0, $a0, 0x467c
/* 0A1518 7F06C9E8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0A151C 7F06C9EC 0C0033D1 */  jal   osSyncPrintf
/* 0A1520 7F06C9F0 AFA60030 */   sw    $a2, 0x30($sp)
/* 0A1524 7F06C9F4 0FC1B11B */  jal   return_null
/* 0A1528 7F06C9F8 00000000 */   nop   
/* 0A152C 7F06C9FC 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0A1530 7F06CA00 8FA60030 */  lw    $a2, 0x30($sp)
.L7F06CA04:
/* 0A1534 7F06CA04 14A00009 */  bnez  $a1, .L7F06CA2C
/* 0A1538 7F06CA08 3C048005 */   lui   $a0, %hi(aSetpartoffsetNoPartdesc)
/* 0A153C 7F06CA0C 24844698 */  addiu $a0, %lo(aSetpartoffsetNoPartdesc) # addiu $a0, $a0, 0x4698
/* 0A1540 7F06CA10 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0A1544 7F06CA14 0C0033D1 */  jal   osSyncPrintf
/* 0A1548 7F06CA18 AFA60030 */   sw    $a2, 0x30($sp)
/* 0A154C 7F06CA1C 0FC1B11B */  jal   return_null
/* 0A1550 7F06CA20 00000000 */   nop   
/* 0A1554 7F06CA24 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0A1558 7F06CA28 8FA60030 */  lw    $a2, 0x30($sp)
.L7F06CA2C:
/* 0A155C 7F06CA2C 94A20000 */  lhu   $v0, ($a1)
/* 0A1560 7F06CA30 24010001 */  li    $at, 1
/* 0A1564 7F06CA34 8FA40028 */  lw    $a0, 0x28($sp)
/* 0A1568 7F06CA38 304F00FF */  andi  $t7, $v0, 0xff
/* 0A156C 7F06CA3C 11E10009 */  beq   $t7, $at, .L7F06CA64
/* 0A1570 7F06CA40 24010002 */   li    $at, 2
/* 0A1574 7F06CA44 11E10039 */  beq   $t7, $at, .L7F06CB2C
/* 0A1578 7F06CA48 24010003 */   li    $at, 3
/* 0A157C 7F06CA4C 11E1003F */  beq   $t7, $at, .L7F06CB4C
/* 0A1580 7F06CA50 24010015 */   li    $at, 21
/* 0A1584 7F06CA54 51E10046 */  beql  $t7, $at, .L7F06CB70
/* 0A1588 7F06CA58 8CA20004 */   lw    $v0, 4($a1)
/* 0A158C 7F06CA5C 1000004B */  b     .L7F06CB8C
/* 0A1590 7F06CA60 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CA64:
/* 0A1594 7F06CA64 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A1598 7F06CA68 AFA60030 */   sw    $a2, 0x30($sp)
/* 0A159C 7F06CA6C 8FA60030 */  lw    $a2, 0x30($sp)
/* 0A15A0 7F06CA70 C4460008 */  lwc1  $f6, 8($v0)
/* 0A15A4 7F06CA74 C4C40000 */  lwc1  $f4, ($a2)
/* 0A15A8 7F06CA78 46062201 */  sub.s $f8, $f4, $f6
/* 0A15AC 7F06CA7C E7A80018 */  swc1  $f8, 0x18($sp)
/* 0A15B0 7F06CA80 C4500010 */  lwc1  $f16, 0x10($v0)
/* 0A15B4 7F06CA84 C4CA0008 */  lwc1  $f10, 8($a2)
/* 0A15B8 7F06CA88 46105481 */  sub.s $f18, $f10, $f16
/* 0A15BC 7F06CA8C E7B20020 */  swc1  $f18, 0x20($sp)
/* 0A15C0 7F06CA90 C4C40000 */  lwc1  $f4, ($a2)
/* 0A15C4 7F06CA94 C44A0024 */  lwc1  $f10, 0x24($v0)
/* 0A15C8 7F06CA98 E4440008 */  swc1  $f4, 8($v0)
/* 0A15CC 7F06CA9C C4C60004 */  lwc1  $f6, 4($a2)
/* 0A15D0 7F06CAA0 C444002C */  lwc1  $f4, 0x2c($v0)
/* 0A15D4 7F06CAA4 E446000C */  swc1  $f6, 0xc($v0)
/* 0A15D8 7F06CAA8 C4C80008 */  lwc1  $f8, 8($a2)
/* 0A15DC 7F06CAAC E4480010 */  swc1  $f8, 0x10($v0)
/* 0A15E0 7F06CAB0 C7B00018 */  lwc1  $f16, 0x18($sp)
/* 0A15E4 7F06CAB4 46105480 */  add.s $f18, $f10, $f16
/* 0A15E8 7F06CAB8 C44A0034 */  lwc1  $f10, 0x34($v0)
/* 0A15EC 7F06CABC E4520024 */  swc1  $f18, 0x24($v0)
/* 0A15F0 7F06CAC0 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 0A15F4 7F06CAC4 46062200 */  add.s $f8, $f4, $f6
/* 0A15F8 7F06CAC8 C444003C */  lwc1  $f4, 0x3c($v0)
/* 0A15FC 7F06CACC E448002C */  swc1  $f8, 0x2c($v0)
/* 0A1600 7F06CAD0 C7B00018 */  lwc1  $f16, 0x18($sp)
/* 0A1604 7F06CAD4 46105480 */  add.s $f18, $f10, $f16
/* 0A1608 7F06CAD8 C44A0040 */  lwc1  $f10, 0x40($v0)
/* 0A160C 7F06CADC E4520034 */  swc1  $f18, 0x34($v0)
/* 0A1610 7F06CAE0 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 0A1614 7F06CAE4 46062200 */  add.s $f8, $f4, $f6
/* 0A1618 7F06CAE8 C4440048 */  lwc1  $f4, 0x48($v0)
/* 0A161C 7F06CAEC E448003C */  swc1  $f8, 0x3c($v0)
/* 0A1620 7F06CAF0 C7B00018 */  lwc1  $f16, 0x18($sp)
/* 0A1624 7F06CAF4 46105480 */  add.s $f18, $f10, $f16
/* 0A1628 7F06CAF8 C44A004C */  lwc1  $f10, 0x4c($v0)
/* 0A162C 7F06CAFC E4520040 */  swc1  $f18, 0x40($v0)
/* 0A1630 7F06CB00 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 0A1634 7F06CB04 46062200 */  add.s $f8, $f4, $f6
/* 0A1638 7F06CB08 C4440054 */  lwc1  $f4, 0x54($v0)
/* 0A163C 7F06CB0C E4480048 */  swc1  $f8, 0x48($v0)
/* 0A1640 7F06CB10 C7B00018 */  lwc1  $f16, 0x18($sp)
/* 0A1644 7F06CB14 46105480 */  add.s $f18, $f10, $f16
/* 0A1648 7F06CB18 E452004C */  swc1  $f18, 0x4c($v0)
/* 0A164C 7F06CB1C C7A60020 */  lwc1  $f6, 0x20($sp)
/* 0A1650 7F06CB20 46062200 */  add.s $f8, $f4, $f6
/* 0A1654 7F06CB24 10000018 */  b     .L7F06CB88
/* 0A1658 7F06CB28 E4480054 */   swc1  $f8, 0x54($v0)
.L7F06CB2C:
/* 0A165C 7F06CB2C 8CA20004 */  lw    $v0, 4($a1)
/* 0A1660 7F06CB30 C4CA0000 */  lwc1  $f10, ($a2)
/* 0A1664 7F06CB34 E44A0000 */  swc1  $f10, ($v0)
/* 0A1668 7F06CB38 C4D00004 */  lwc1  $f16, 4($a2)
/* 0A166C 7F06CB3C E4500004 */  swc1  $f16, 4($v0)
/* 0A1670 7F06CB40 C4D20008 */  lwc1  $f18, 8($a2)
/* 0A1674 7F06CB44 10000010 */  b     .L7F06CB88
/* 0A1678 7F06CB48 E4520008 */   swc1  $f18, 8($v0)
.L7F06CB4C:
/* 0A167C 7F06CB4C 8CA20004 */  lw    $v0, 4($a1)
/* 0A1680 7F06CB50 C4C40000 */  lwc1  $f4, ($a2)
/* 0A1684 7F06CB54 E4440000 */  swc1  $f4, ($v0)
/* 0A1688 7F06CB58 C4C60004 */  lwc1  $f6, 4($a2)
/* 0A168C 7F06CB5C E4460004 */  swc1  $f6, 4($v0)
/* 0A1690 7F06CB60 C4C80008 */  lwc1  $f8, 8($a2)
/* 0A1694 7F06CB64 10000008 */  b     .L7F06CB88
/* 0A1698 7F06CB68 E4480008 */   swc1  $f8, 8($v0)
/* 0A169C 7F06CB6C 8CA20004 */  lw    $v0, 4($a1)
.L7F06CB70:
/* 0A16A0 7F06CB70 C4CA0000 */  lwc1  $f10, ($a2)
/* 0A16A4 7F06CB74 E44A0000 */  swc1  $f10, ($v0)
/* 0A16A8 7F06CB78 C4D00004 */  lwc1  $f16, 4($a2)
/* 0A16AC 7F06CB7C E4500004 */  swc1  $f16, 4($v0)
/* 0A16B0 7F06CB80 C4D20008 */  lwc1  $f18, 8($a2)
/* 0A16B4 7F06CB84 E4520008 */  swc1  $f18, 8($v0)
.L7F06CB88:
/* 0A16B8 7F06CB88 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06CB8C:
/* 0A16BC 7F06CB8C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0A16C0 7F06CB90 03E00008 */  jr    $ra
/* 0A16C4 7F06CB94 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void getsuboffset(void) {

}
#else
GLOBAL_ASM(
.text
glabel getsuboffset
/* 0A16C8 7F06CB98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A16CC 7F06CB9C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A16D0 7F06CBA0 AFA40018 */  sw    $a0, 0x18($sp)
/* 0A16D4 7F06CBA4 14800006 */  bnez  $a0, .L7F06CBC0
/* 0A16D8 7F06CBA8 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A16DC 7F06CBAC 3C048005 */  lui   $a0, %hi(aGetsuboffsetNoObjinst)
/* 0A16E0 7F06CBB0 0C0033D1 */  jal   osSyncPrintf
/* 0A16E4 7F06CBB4 248446B4 */   addiu $a0, %lo(aGetsuboffsetNoObjinst) # addiu $a0, $a0, 0x46b4
/* 0A16E8 7F06CBB8 0FC1B11B */  jal   return_null
/* 0A16EC 7F06CBBC 00000000 */   nop   
.L7F06CBC0:
/* 0A16F0 7F06CBC0 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A16F4 7F06CBC4 3C048005 */  lui   $a0, %hi(aGetsuboffsetObjinstHasNoObject)
/* 0A16F8 7F06CBC8 8DE20008 */  lw    $v0, 8($t7)
/* 0A16FC 7F06CBCC 54400008 */  bnezl $v0, .L7F06CBF0
/* 0A1700 7F06CBD0 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A1704 7F06CBD4 0C0033D1 */  jal   osSyncPrintf
/* 0A1708 7F06CBD8 248446D0 */   addiu $a0, $a0, %lo(aGetsuboffsetObjinstHasNoObject)
/* 0A170C 7F06CBDC 0FC1B11B */  jal   return_null
/* 0A1710 7F06CBE0 00000000 */   nop   
/* 0A1714 7F06CBE4 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A1718 7F06CBE8 8F020008 */  lw    $v0, 8($t8)
/* 0A171C 7F06CBEC 8FA40018 */  lw    $a0, 0x18($sp)
.L7F06CBF0:
/* 0A1720 7F06CBF0 8C450000 */  lw    $a1, ($v0)
/* 0A1724 7F06CBF4 0FC1B226 */  jal   getpartoffset
/* 0A1728 7F06CBF8 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0A172C 7F06CBFC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A1730 7F06CC00 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1734 7F06CC04 03E00008 */  jr    $ra
/* 0A1738 7F06CC08 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void setsuboffset(void) {

}
#else
GLOBAL_ASM(
.text
glabel setsuboffset
/* 0A173C 7F06CC0C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A1740 7F06CC10 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A1744 7F06CC14 AFA40018 */  sw    $a0, 0x18($sp)
/* 0A1748 7F06CC18 14800006 */  bnez  $a0, .L7F06CC34
/* 0A174C 7F06CC1C AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A1750 7F06CC20 3C048005 */  lui   $a0, %hi(aSetsuboffsetNoObjinst)
/* 0A1754 7F06CC24 0C0033D1 */  jal   osSyncPrintf
/* 0A1758 7F06CC28 248446F8 */   addiu $a0, %lo(aSetsuboffsetNoObjinst) # addiu $a0, $a0, 0x46f8
/* 0A175C 7F06CC2C 0FC1B11B */  jal   return_null
/* 0A1760 7F06CC30 00000000 */   nop   
.L7F06CC34:
/* 0A1764 7F06CC34 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A1768 7F06CC38 3C048005 */  lui   $a0, %hi(aSetsuboffsetObjinstHasNoObject)
/* 0A176C 7F06CC3C 8DE20008 */  lw    $v0, 8($t7)
/* 0A1770 7F06CC40 54400008 */  bnezl $v0, .L7F06CC64
/* 0A1774 7F06CC44 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A1778 7F06CC48 0C0033D1 */  jal   osSyncPrintf
/* 0A177C 7F06CC4C 24844714 */   addiu $a0, $a0, %lo(aSetsuboffsetObjinstHasNoObject)
/* 0A1780 7F06CC50 0FC1B11B */  jal   return_null
/* 0A1784 7F06CC54 00000000 */   nop   
/* 0A1788 7F06CC58 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A178C 7F06CC5C 8F020008 */  lw    $v0, 8($t8)
/* 0A1790 7F06CC60 8FA40018 */  lw    $a0, 0x18($sp)
.L7F06CC64:
/* 0A1794 7F06CC64 8C450000 */  lw    $a1, ($v0)
/* 0A1798 7F06CC68 0FC1B274 */  jal   setpartoffset
/* 0A179C 7F06CC6C 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0A17A0 7F06CC70 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A17A4 7F06CC74 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A17A8 7F06CC78 03E00008 */  jr    $ra
/* 0A17AC 7F06CC7C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void getsubroty(void) {

}
#else
GLOBAL_ASM(
.text
glabel getsubroty
/* 0A17B0 7F06CC80 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A17B4 7F06CC84 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A17B8 7F06CC88 14800006 */  bnez  $a0, .L7F06CCA4
/* 0A17BC 7F06CC8C AFA40018 */   sw    $a0, 0x18($sp)
/* 0A17C0 7F06CC90 3C048005 */  lui   $a0, %hi(aGetsubrotyNoObjinst)
/* 0A17C4 7F06CC94 0C0033D1 */  jal   osSyncPrintf
/* 0A17C8 7F06CC98 2484473C */   addiu $a0, %lo(aGetsubrotyNoObjinst) # addiu $a0, $a0, 0x473c
/* 0A17CC 7F06CC9C 0FC1B11B */  jal   return_null
/* 0A17D0 7F06CCA0 00000000 */   nop   
.L7F06CCA4:
/* 0A17D4 7F06CCA4 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A17D8 7F06CCA8 3C048005 */  lui   $a0, %hi(aGetsubrotyObjinstHasNoObject)
/* 0A17DC 7F06CCAC 8DE20008 */  lw    $v0, 8($t7)
/* 0A17E0 7F06CCB0 54400008 */  bnezl $v0, .L7F06CCD4
/* 0A17E4 7F06CCB4 8C430000 */   lw    $v1, ($v0)
/* 0A17E8 7F06CCB8 0C0033D1 */  jal   osSyncPrintf
/* 0A17EC 7F06CCBC 24844754 */   addiu $a0, %lo(aGetsubrotyObjinstHasNoObject) # addiu $a0, $a0, 0x4754
/* 0A17F0 7F06CCC0 0FC1B11B */  jal   return_null
/* 0A17F4 7F06CCC4 00000000 */   nop   
/* 0A17F8 7F06CCC8 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A17FC 7F06CCCC 8F020008 */  lw    $v0, 8($t8)
/* 0A1800 7F06CCD0 8C430000 */  lw    $v1, ($v0)
.L7F06CCD4:
/* 0A1804 7F06CCD4 3C048005 */  lui   $a0, %hi(aGetsubrotyObjinstHasNoRootPart)
/* 0A1808 7F06CCD8 54600009 */  bnezl $v1, .L7F06CD00
/* 0A180C 7F06CCDC 94690000 */   lhu   $t1, ($v1)
/* 0A1810 7F06CCE0 0C0033D1 */  jal   osSyncPrintf
/* 0A1814 7F06CCE4 24844778 */   addiu $a0, %lo(aGetsubrotyObjinstHasNoRootPart) # addiu $a0, $a0, 0x4778
/* 0A1818 7F06CCE8 0FC1B11B */  jal   return_null
/* 0A181C 7F06CCEC 00000000 */   nop   
/* 0A1820 7F06CCF0 8FB90018 */  lw    $t9, 0x18($sp)
/* 0A1824 7F06CCF4 8F280008 */  lw    $t0, 8($t9)
/* 0A1828 7F06CCF8 8D030000 */  lw    $v1, ($t0)
/* 0A182C 7F06CCFC 94690000 */  lhu   $t1, ($v1)
.L7F06CD00:
/* 0A1830 7F06CD00 24010001 */  li    $at, 1
/* 0A1834 7F06CD04 00602825 */  move  $a1, $v1
/* 0A1838 7F06CD08 312A00FF */  andi  $t2, $t1, 0xff
/* 0A183C 7F06CD0C 55410006 */  bnel  $t2, $at, .L7F06CD28
/* 0A1840 7F06CD10 44800000 */   mtc1  $zero, $f0
/* 0A1844 7F06CD14 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A1848 7F06CD18 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A184C 7F06CD1C 10000003 */  b     .L7F06CD2C
/* 0A1850 7F06CD20 C4400014 */   lwc1  $f0, 0x14($v0)
/* 0A1854 7F06CD24 44800000 */  mtc1  $zero, $f0
.L7F06CD28:
/* 0A1858 7F06CD28 00000000 */  nop   
.L7F06CD2C:
/* 0A185C 7F06CD2C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A1860 7F06CD30 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1864 7F06CD34 03E00008 */  jr    $ra
/* 0A1868 7F06CD38 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void setsubroty(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054B58
.word 0x40c90fdb /*6.2831855*/
glabel D_80054B5C
.word 0x40c90fdb /*6.2831855*/
.text
glabel setsubroty
/* 0A186C 7F06CD3C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A1870 7F06CD40 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A1874 7F06CD44 AFA40018 */  sw    $a0, 0x18($sp)
/* 0A1878 7F06CD48 14800006 */  bnez  $a0, .L7F06CD64
/* 0A187C 7F06CD4C AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A1880 7F06CD50 3C048005 */  lui   $a0, %hi(aSetsubrotyNoObjinst)
/* 0A1884 7F06CD54 0C0033D1 */  jal   osSyncPrintf
/* 0A1888 7F06CD58 248447A0 */   addiu $a0, %lo(aSetsubrotyNoObjinst) # addiu $a0, $a0, 0x47a0
/* 0A188C 7F06CD5C 0FC1B11B */  jal   return_null
/* 0A1890 7F06CD60 00000000 */   nop   
.L7F06CD64:
/* 0A1894 7F06CD64 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A1898 7F06CD68 3C048005 */  lui   $a0, %hi(aSetsubrotyObjinstHasNoObject)
/* 0A189C 7F06CD6C 8DE20008 */  lw    $v0, 8($t7)
/* 0A18A0 7F06CD70 54400008 */  bnezl $v0, .L7F06CD94
/* 0A18A4 7F06CD74 8C430000 */   lw    $v1, ($v0)
/* 0A18A8 7F06CD78 0C0033D1 */  jal   osSyncPrintf
/* 0A18AC 7F06CD7C 248447B8 */   addiu $a0, %lo(aSetsubrotyObjinstHasNoObject) # addiu $a0, $a0, 0x47b8
/* 0A18B0 7F06CD80 0FC1B11B */  jal   return_null
/* 0A18B4 7F06CD84 00000000 */   nop   
/* 0A18B8 7F06CD88 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A18BC 7F06CD8C 8F020008 */  lw    $v0, 8($t8)
/* 0A18C0 7F06CD90 8C430000 */  lw    $v1, ($v0)
.L7F06CD94:
/* 0A18C4 7F06CD94 3C048005 */  lui   $a0, %hi(aSetsubrotyObjinstHasNoRootPart)
/* 0A18C8 7F06CD98 54600009 */  bnezl $v1, .L7F06CDC0
/* 0A18CC 7F06CD9C 94690000 */   lhu   $t1, ($v1)
/* 0A18D0 7F06CDA0 0C0033D1 */  jal   osSyncPrintf
/* 0A18D4 7F06CDA4 248447DC */   addiu $a0, %lo(aSetsubrotyObjinstHasNoRootPart) # addiu $a0, $a0, 0x47dc
/* 0A18D8 7F06CDA8 0FC1B11B */  jal   return_null
/* 0A18DC 7F06CDAC 00000000 */   nop   
/* 0A18E0 7F06CDB0 8FB90018 */  lw    $t9, 0x18($sp)
/* 0A18E4 7F06CDB4 8F280008 */  lw    $t0, 8($t9)
/* 0A18E8 7F06CDB8 8D030000 */  lw    $v1, ($t0)
/* 0A18EC 7F06CDBC 94690000 */  lhu   $t1, ($v1)
.L7F06CDC0:
/* 0A18F0 7F06CDC0 24010001 */  li    $at, 1
/* 0A18F4 7F06CDC4 00602825 */  move  $a1, $v1
/* 0A18F8 7F06CDC8 312A00FF */  andi  $t2, $t1, 0xff
/* 0A18FC 7F06CDCC 55410027 */  bnel  $t2, $at, .L7F06CE6C
/* 0A1900 7F06CDD0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A1904 7F06CDD4 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A1908 7F06CDD8 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A190C 7F06CDDC C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0A1910 7F06CDE0 C4460014 */  lwc1  $f6, 0x14($v0)
/* 0A1914 7F06CDE4 44804000 */  mtc1  $zero, $f8
/* 0A1918 7F06CDE8 3C018005 */  lui   $at, %hi(D_80054B58)
/* 0A191C 7F06CDEC 46062001 */  sub.s $f0, $f4, $f6
/* 0A1920 7F06CDF0 4608003C */  c.lt.s $f0, $f8
/* 0A1924 7F06CDF4 00000000 */  nop   
/* 0A1928 7F06CDF8 45020004 */  bc1fl .L7F06CE0C
/* 0A192C 7F06CDFC C44A0030 */   lwc1  $f10, 0x30($v0)
/* 0A1930 7F06CE00 C42C4B58 */  lwc1  $f12, %lo(D_80054B58)($at)
/* 0A1934 7F06CE04 460C0000 */  add.s $f0, $f0, $f12
/* 0A1938 7F06CE08 C44A0030 */  lwc1  $f10, 0x30($v0)
.L7F06CE0C:
/* 0A193C 7F06CE0C 3C018005 */  lui   $at, %hi(D_80054B5C)
/* 0A1940 7F06CE10 C42C4B5C */  lwc1  $f12, %lo(D_80054B5C)($at)
/* 0A1944 7F06CE14 46005400 */  add.s $f16, $f10, $f0
/* 0A1948 7F06CE18 E4500030 */  swc1  $f16, 0x30($v0)
/* 0A194C 7F06CE1C C4420030 */  lwc1  $f2, 0x30($v0)
/* 0A1950 7F06CE20 4602603E */  c.le.s $f12, $f2
/* 0A1954 7F06CE24 00000000 */  nop   
/* 0A1958 7F06CE28 45020004 */  bc1fl .L7F06CE3C
/* 0A195C 7F06CE2C C4440020 */   lwc1  $f4, 0x20($v0)
/* 0A1960 7F06CE30 460C1481 */  sub.s $f18, $f2, $f12
/* 0A1964 7F06CE34 E4520030 */  swc1  $f18, 0x30($v0)
/* 0A1968 7F06CE38 C4440020 */  lwc1  $f4, 0x20($v0)
.L7F06CE3C:
/* 0A196C 7F06CE3C 46002180 */  add.s $f6, $f4, $f0
/* 0A1970 7F06CE40 E4460020 */  swc1  $f6, 0x20($v0)
/* 0A1974 7F06CE44 C4420020 */  lwc1  $f2, 0x20($v0)
/* 0A1978 7F06CE48 4602603E */  c.le.s $f12, $f2
/* 0A197C 7F06CE4C 00000000 */  nop   
/* 0A1980 7F06CE50 45020004 */  bc1fl .L7F06CE64
/* 0A1984 7F06CE54 C7AA001C */   lwc1  $f10, 0x1c($sp)
/* 0A1988 7F06CE58 460C1201 */  sub.s $f8, $f2, $f12
/* 0A198C 7F06CE5C E4480020 */  swc1  $f8, 0x20($v0)
/* 0A1990 7F06CE60 C7AA001C */  lwc1  $f10, 0x1c($sp)
.L7F06CE64:
/* 0A1994 7F06CE64 E44A0014 */  swc1  $f10, 0x14($v0)
/* 0A1998 7F06CE68 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06CE6C:
/* 0A199C 7F06CE6C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A19A0 7F06CE70 03E00008 */  jr    $ra
/* 0A19A4 7F06CE74 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void set_obj_instance_controller_scale(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_obj_instance_controller_scale
/* 0A19A8 7F06CE78 44856000 */  mtc1  $a1, $f12
/* 0A19AC 7F06CE7C 03E00008 */  jr    $ra
/* 0A19B0 7F06CE80 E48C0014 */   swc1  $f12, 0x14($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06CE84(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06CE84
/* 0A19B4 7F06CE84 44856000 */  mtc1  $a1, $f12
/* 0A19B8 7F06CE88 03E00008 */  jr    $ra
/* 0A19BC 7F06CE8C E48C00B8 */   swc1  $f12, 0xb8($a0)
)
#endif





#ifdef NONMATCHING
void getjointsize(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054B60*/
glabel jpt_getjointsize
.word .L7F06CEF8
.word .L7F06CF10
.word .L7F06CF28
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CF58
.word .L7F06CF70
.word .L7F06CF88
.word .L7F06CFA0
.word .L7F06CFB8
.word .L7F06CFD0
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CF40

.text
glabel getjointsize
/* 0A19C0 7F06CE90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A19C4 7F06CE94 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A19C8 7F06CE98 1480000A */  bnez  $a0, .L7F06CEC4
/* 0A19CC 7F06CE9C 00803025 */   move  $a2, $a0
/* 0A19D0 7F06CEA0 3C048005 */  lui   $a0, %hi(aGetjointsizeNoObjinst)
/* 0A19D4 7F06CEA4 24844804 */  addiu $a0, %lo(aGetjointsizeNoObjinst) # addiu $a0, $a0, 0x4804
/* 0A19D8 7F06CEA8 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0A19DC 7F06CEAC 0C0033D1 */  jal   osSyncPrintf
/* 0A19E0 7F06CEB0 AFA60018 */   sw    $a2, 0x18($sp)
/* 0A19E4 7F06CEB4 0FC1B11B */  jal   return_null
/* 0A19E8 7F06CEB8 00000000 */   nop   
/* 0A19EC 7F06CEBC 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0A19F0 7F06CEC0 8FA60018 */  lw    $a2, 0x18($sp)
.L7F06CEC4:
/* 0A19F4 7F06CEC4 50A0004C */  beql  $a1, $zero, .L7F06CFF8
/* 0A19F8 7F06CEC8 44800000 */   mtc1  $zero, $f0
/* 0A19FC 7F06CECC 94AE0000 */  lhu   $t6, ($a1)
.L7F06CED0:
/* 0A1A00 7F06CED0 31CF00FF */  andi  $t7, $t6, 0xff
/* 0A1A04 7F06CED4 25F8FFFF */  addiu $t8, $t7, -1
/* 0A1A08 7F06CED8 2F010015 */  sltiu $at, $t8, 0x15
/* 0A1A0C 7F06CEDC 10200042 */  beqz  $at, .L7F06CFE8
/* 0A1A10 7F06CEE0 0018C080 */   sll   $t8, $t8, 2
/* 0A1A14 7F06CEE4 3C018005 */  lui   $at, %hi(jpt_getjointsize)
/* 0A1A18 7F06CEE8 00380821 */  addu  $at, $at, $t8
/* 0A1A1C 7F06CEEC 8C384B60 */  lw    $t8, %lo(jpt_getjointsize)($at)
.L7F06CEF0:
/* 0A1A20 7F06CEF0 03000008 */  jr    $t8
/* 0A1A24 7F06CEF4 00000000 */   nop   
.L7F06CEF8:
/* 0A1A28 7F06CEF8 8CA20004 */  lw    $v0, 4($a1)
/* 0A1A2C 7F06CEFC C4C60014 */  lwc1  $f6, 0x14($a2)
/* 0A1A30 7F06CF00 C4440008 */  lwc1  $f4, 8($v0)
/* 0A1A34 7F06CF04 46062002 */  mul.s $f0, $f4, $f6
/* 0A1A38 7F06CF08 1000003D */  b     .L7F06D000
/* 0A1A3C 7F06CF0C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF10:
/* 0A1A40 7F06CF10 8CA20004 */  lw    $v0, 4($a1)
/* 0A1A44 7F06CF14 C4CA0014 */  lwc1  $f10, 0x14($a2)
/* 0A1A48 7F06CF18 C4480018 */  lwc1  $f8, 0x18($v0)
/* 0A1A4C 7F06CF1C 460A4002 */  mul.s $f0, $f8, $f10
/* 0A1A50 7F06CF20 10000037 */  b     .L7F06D000
/* 0A1A54 7F06CF24 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF28:
/* 0A1A58 7F06CF28 8CA20004 */  lw    $v0, 4($a1)
/* 0A1A5C 7F06CF2C C4D20014 */  lwc1  $f18, 0x14($a2)
/* 0A1A60 7F06CF30 C4500018 */  lwc1  $f16, 0x18($v0)
/* 0A1A64 7F06CF34 46128002 */  mul.s $f0, $f16, $f18
/* 0A1A68 7F06CF38 10000031 */  b     .L7F06D000
/* 0A1A6C 7F06CF3C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF40:
/* 0A1A70 7F06CF40 8CA20004 */  lw    $v0, 4($a1)
/* 0A1A74 7F06CF44 C4C60014 */  lwc1  $f6, 0x14($a2)
/* 0A1A78 7F06CF48 C4440010 */  lwc1  $f4, 0x10($v0)
/* 0A1A7C 7F06CF4C 46062002 */  mul.s $f0, $f4, $f6
/* 0A1A80 7F06CF50 1000002B */  b     .L7F06D000
/* 0A1A84 7F06CF54 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF58:
/* 0A1A88 7F06CF58 8CA20004 */  lw    $v0, 4($a1)
/* 0A1A8C 7F06CF5C C4CA0014 */  lwc1  $f10, 0x14($a2)
/* 0A1A90 7F06CF60 C4480040 */  lwc1  $f8, 0x40($v0)
/* 0A1A94 7F06CF64 460A4002 */  mul.s $f0, $f8, $f10
/* 0A1A98 7F06CF68 10000025 */  b     .L7F06D000
/* 0A1A9C 7F06CF6C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF70:
/* 0A1AA0 7F06CF70 8CA20004 */  lw    $v0, 4($a1)
/* 0A1AA4 7F06CF74 C4D20014 */  lwc1  $f18, 0x14($a2)
/* 0A1AA8 7F06CF78 C450001C */  lwc1  $f16, 0x1c($v0)
/* 0A1AAC 7F06CF7C 46128002 */  mul.s $f0, $f16, $f18
/* 0A1AB0 7F06CF80 1000001F */  b     .L7F06D000
/* 0A1AB4 7F06CF84 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CF88:
/* 0A1AB8 7F06CF88 8CA20004 */  lw    $v0, 4($a1)
/* 0A1ABC 7F06CF8C C4C60014 */  lwc1  $f6, 0x14($a2)
/* 0A1AC0 7F06CF90 C4440018 */  lwc1  $f4, 0x18($v0)
/* 0A1AC4 7F06CF94 46062002 */  mul.s $f0, $f4, $f6
/* 0A1AC8 7F06CF98 10000019 */  b     .L7F06D000
/* 0A1ACC 7F06CF9C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CFA0:
/* 0A1AD0 7F06CFA0 8CA20004 */  lw    $v0, 4($a1)
/* 0A1AD4 7F06CFA4 C4CA0014 */  lwc1  $f10, 0x14($a2)
/* 0A1AD8 7F06CFA8 C448000C */  lwc1  $f8, 0xc($v0)
/* 0A1ADC 7F06CFAC 460A4002 */  mul.s $f0, $f8, $f10
/* 0A1AE0 7F06CFB0 10000013 */  b     .L7F06D000
/* 0A1AE4 7F06CFB4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CFB8:
/* 0A1AE8 7F06CFB8 8CA20004 */  lw    $v0, 4($a1)
/* 0A1AEC 7F06CFBC C4D20014 */  lwc1  $f18, 0x14($a2)
/* 0A1AF0 7F06CFC0 C4500018 */  lwc1  $f16, 0x18($v0)
/* 0A1AF4 7F06CFC4 46128002 */  mul.s $f0, $f16, $f18
/* 0A1AF8 7F06CFC8 1000000D */  b     .L7F06D000
/* 0A1AFC 7F06CFCC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06CFD0:
/* 0A1B00 7F06CFD0 8CA20004 */  lw    $v0, 4($a1)
/* 0A1B04 7F06CFD4 C4C60014 */  lwc1  $f6, 0x14($a2)
/* 0A1B08 7F06CFD8 C4440014 */  lwc1  $f4, 0x14($v0)
/* 0A1B0C 7F06CFDC 46062002 */  mul.s $f0, $f4, $f6
/* 0A1B10 7F06CFE0 10000007 */  b     .L7F06D000
/* 0A1B14 7F06CFE4 8FBF0014 */   lw    $ra, 0x14($sp)
def_7F06CEF0:
.L7F06CFE8:
/* 0A1B18 7F06CFE8 8CA50008 */  lw    $a1, 8($a1)
/* 0A1B1C 7F06CFEC 54A0FFB8 */  bnezl $a1, .L7F06CED0
/* 0A1B20 7F06CFF0 94AE0000 */   lhu   $t6, ($a1)
/* 0A1B24 7F06CFF4 44800000 */  mtc1  $zero, $f0
.L7F06CFF8:
/* 0A1B28 7F06CFF8 00000000 */  nop   
/* 0A1B2C 7F06CFFC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06D000:
/* 0A1B30 7F06D000 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1B34 7F06D004 03E00008 */  jr    $ra
/* 0A1B38 7F06D008 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void getinstsize(void) {

}
#else
GLOBAL_ASM(
.text
glabel getinstsize
/* 0A1B3C 7F06D00C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A1B40 7F06D010 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A1B44 7F06D014 14800006 */  bnez  $a0, .L7F06D030
/* 0A1B48 7F06D018 AFA40018 */   sw    $a0, 0x18($sp)
/* 0A1B4C 7F06D01C 3C048005 */  lui   $a0, %hi(aGetinstsizeNoObjinst)
/* 0A1B50 7F06D020 0C0033D1 */  jal   osSyncPrintf
/* 0A1B54 7F06D024 24844820 */   addiu $a0, %lo(aGetinstsizeNoObjinst) # addiu $a0, $a0, 0x4820
/* 0A1B58 7F06D028 0FC1B11B */  jal   return_null
/* 0A1B5C 7F06D02C 00000000 */   nop   
.L7F06D030:
/* 0A1B60 7F06D030 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A1B64 7F06D034 3C048005 */  lui   $a0, %hi(aGetinstsizeNoObjdesc)
/* 0A1B68 7F06D038 8DE20008 */  lw    $v0, 8($t7)
/* 0A1B6C 7F06D03C 54400008 */  bnezl $v0, .L7F06D060
/* 0A1B70 7F06D040 8FB90018 */   lw    $t9, 0x18($sp)
/* 0A1B74 7F06D044 0C0033D1 */  jal   osSyncPrintf
/* 0A1B78 7F06D048 2484483C */   addiu $a0, %lo(aGetinstsizeNoObjdesc) # addiu $a0, $a0, 0x483c
/* 0A1B7C 7F06D04C 0FC1B11B */  jal   return_null
/* 0A1B80 7F06D050 00000000 */   nop   
/* 0A1B84 7F06D054 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A1B88 7F06D058 8F020008 */  lw    $v0, 8($t8)
/* 0A1B8C 7F06D05C 8FB90018 */  lw    $t9, 0x18($sp)
.L7F06D060:
/* 0A1B90 7F06D060 C4440010 */  lwc1  $f4, 0x10($v0)
/* 0A1B94 7F06D064 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A1B98 7F06D068 C7260014 */  lwc1  $f6, 0x14($t9)
/* 0A1B9C 7F06D06C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A1BA0 7F06D070 46062002 */  mul.s $f0, $f4, $f6
/* 0A1BA4 7F06D074 03E00008 */  jr    $ra
/* 0A1BA8 7F06D078 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D07C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06D07C
/* 0A1BAC 7F06D07C C4800000 */  lwc1  $f0, ($a0)
/* 0A1BB0 7F06D080 C4A40000 */  lwc1  $f4, ($a1)
/* 0A1BB4 7F06D084 44866000 */  mtc1  $a2, $f12
/* 0A1BB8 7F06D088 C4820004 */  lwc1  $f2, 4($a0)
/* 0A1BBC 7F06D08C 46002181 */  sub.s $f6, $f4, $f0
/* 0A1BC0 7F06D090 C48E0008 */  lwc1  $f14, 8($a0)
/* 0A1BC4 7F06D094 460C3202 */  mul.s $f8, $f6, $f12
/* 0A1BC8 7F06D098 46080280 */  add.s $f10, $f0, $f8
/* 0A1BCC 7F06D09C E48A0000 */  swc1  $f10, ($a0)
/* 0A1BD0 7F06D0A0 C4B00004 */  lwc1  $f16, 4($a1)
/* 0A1BD4 7F06D0A4 46028481 */  sub.s $f18, $f16, $f2
/* 0A1BD8 7F06D0A8 460C9102 */  mul.s $f4, $f18, $f12
/* 0A1BDC 7F06D0AC 46041180 */  add.s $f6, $f2, $f4
/* 0A1BE0 7F06D0B0 E4860004 */  swc1  $f6, 4($a0)
/* 0A1BE4 7F06D0B4 C4A80008 */  lwc1  $f8, 8($a1)
/* 0A1BE8 7F06D0B8 460E4281 */  sub.s $f10, $f8, $f14
/* 0A1BEC 7F06D0BC 460C5402 */  mul.s $f16, $f10, $f12
/* 0A1BF0 7F06D0C0 46107480 */  add.s $f18, $f14, $f16
/* 0A1BF4 7F06D0C4 03E00008 */  jr    $ra
/* 0A1BF8 7F06D0C8 E4920008 */   swc1  $f18, 8($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D0CC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054BB4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BB8
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BBC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F06D0CC
/* 0A1BFC 7F06D0CC 460C703C */  c.lt.s $f14, $f12
/* 0A1C00 7F06D0D0 AFA60008 */  sw    $a2, 8($sp)
/* 0A1C04 7F06D0D4 460C7081 */  sub.s $f2, $f14, $f12
/* 0A1C08 7F06D0D8 3C018005 */  lui   $at, %hi(D_80054BB4)
/* 0A1C0C 7F06D0DC C7A60008 */  lwc1  $f6, 8($sp)
/* 0A1C10 7F06D0E0 45000003 */  bc1f  .L7F06D0F0
/* 0A1C14 7F06D0E4 46001006 */   mov.s $f0, $f2
/* 0A1C18 7F06D0E8 C42E4BB4 */  lwc1  $f14, %lo(D_80054BB4)($at)
/* 0A1C1C 7F06D0EC 460E1000 */  add.s $f0, $f2, $f14
.L7F06D0F0:
/* 0A1C20 7F06D0F0 3C018005 */  lui   $at, %hi(D_80054BB8)
/* 0A1C24 7F06D0F4 C42E4BB8 */  lwc1  $f14, %lo(D_80054BB8)($at)
/* 0A1C28 7F06D0F8 3C018005 */  lui   $at, %hi(D_80054BBC)
/* 0A1C2C 7F06D0FC C4244BBC */  lwc1  $f4, %lo(D_80054BBC)($at)
/* 0A1C30 7F06D100 4604003C */  c.lt.s $f0, $f4
/* 0A1C34 7F06D104 00000000 */  nop   
/* 0A1C38 7F06D108 4502000A */  bc1fl .L7F06D134
/* 0A1C3C 7F06D10C 46007281 */   sub.s $f10, $f14, $f0
/* 0A1C40 7F06D110 46060202 */  mul.s $f8, $f0, $f6
/* 0A1C44 7F06D114 46086300 */  add.s $f12, $f12, $f8
/* 0A1C48 7F06D118 460C703E */  c.le.s $f14, $f12
/* 0A1C4C 7F06D11C 00000000 */  nop   
/* 0A1C50 7F06D120 4500000D */  bc1f  .L7F06D158
/* 0A1C54 7F06D124 00000000 */   nop   
/* 0A1C58 7F06D128 03E00008 */  jr    $ra
/* 0A1C5C 7F06D12C 460E6001 */   sub.s $f0, $f12, $f14

/* 0A1C60 7F06D130 46007281 */  sub.s $f10, $f14, $f0
.L7F06D134:
/* 0A1C64 7F06D134 C7B00008 */  lwc1  $f16, 8($sp)
/* 0A1C68 7F06D138 44802000 */  mtc1  $zero, $f4
/* 0A1C6C 7F06D13C 46105482 */  mul.s $f18, $f10, $f16
/* 0A1C70 7F06D140 46126301 */  sub.s $f12, $f12, $f18
/* 0A1C74 7F06D144 4604603C */  c.lt.s $f12, $f4
/* 0A1C78 7F06D148 00000000 */  nop   
/* 0A1C7C 7F06D14C 45000002 */  bc1f  .L7F06D158
/* 0A1C80 7F06D150 00000000 */   nop   
/* 0A1C84 7F06D154 460E6300 */  add.s $f12, $f12, $f14
.L7F06D158:
/* 0A1C88 7F06D158 03E00008 */  jr    $ra
/* 0A1C8C 7F06D15C 46006006 */   mov.s $f0, $f12
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06D160(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06D160
/* 0A1C90 7F06D160 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A1C94 7F06D164 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A1C98 7F06D168 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A1C9C 7F06D16C AFA50024 */  sw    $a1, 0x24($sp)
/* 0A1CA0 7F06D170 AFA60028 */  sw    $a2, 0x28($sp)
/* 0A1CA4 7F06D174 00808025 */  move  $s0, $a0
/* 0A1CA8 7F06D178 C4AE0000 */  lwc1  $f14, ($a1)
/* 0A1CAC 7F06D17C 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A1CB0 7F06D180 C48C0000 */   lwc1  $f12, ($a0)
/* 0A1CB4 7F06D184 E6000000 */  swc1  $f0, ($s0)
/* 0A1CB8 7F06D188 8FAF0024 */  lw    $t7, 0x24($sp)
/* 0A1CBC 7F06D18C 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A1CC0 7F06D190 C60C0004 */  lwc1  $f12, 4($s0)
/* 0A1CC4 7F06D194 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A1CC8 7F06D198 C5EE0004 */   lwc1  $f14, 4($t7)
/* 0A1CCC 7F06D19C E6000004 */  swc1  $f0, 4($s0)
/* 0A1CD0 7F06D1A0 8FB80024 */  lw    $t8, 0x24($sp)
/* 0A1CD4 7F06D1A4 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A1CD8 7F06D1A8 C60C0008 */  lwc1  $f12, 8($s0)
/* 0A1CDC 7F06D1AC 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A1CE0 7F06D1B0 C70E0008 */   lwc1  $f14, 8($t8)
/* 0A1CE4 7F06D1B4 E6000008 */  swc1  $f0, 8($s0)
/* 0A1CE8 7F06D1B8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A1CEC 7F06D1BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A1CF0 7F06D1C0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A1CF4 7F06D1C4 03E00008 */  jr    $ra
/* 0A1CF8 7F06D1C8 00000000 */   nop   
)
#endif





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
/* 0A1FD0 7F06D4A0 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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
/* 0A2034 7F06D504 0FC1B41F */  jal   sub_GAME_7F06D07C
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





#ifdef NONMATCHING
void subcalcpos(void) {

}
#else
GLOBAL_ASM(
.text
glabel subcalcpos
/* 0A21E0 7F06D6B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A21E4 7F06D6B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A21E8 7F06D6B8 14800006 */  bnez  $a0, .L7F06D6D4
/* 0A21EC 7F06D6BC AFA40018 */   sw    $a0, 0x18($sp)
/* 0A21F0 7F06D6C0 3C048005 */  lui   $a0, %hi(aSubcalcposNoObjanim)
/* 0A21F4 7F06D6C4 0C0033D1 */  jal   osSyncPrintf
/* 0A21F8 7F06D6C8 24844858 */   addiu $a0, %lo(aSubcalcposNoObjanim) # addiu $a0, $a0, 0x4858
/* 0A21FC 7F06D6CC 0FC1B11B */  jal   return_null
/* 0A2200 7F06D6D0 00000000 */   nop   
.L7F06D6D4:
/* 0A2204 7F06D6D4 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0A2208 7F06D6D8 3C048005 */  lui   $a0, %hi(aSubcalcposNoObjdesc)
/* 0A220C 7F06D6DC 8DE20008 */  lw    $v0, 8($t7)
/* 0A2210 7F06D6E0 54400008 */  bnezl $v0, .L7F06D704
/* 0A2214 7F06D6E4 8C450000 */   lw    $a1, ($v0)
/* 0A2218 7F06D6E8 0C0033D1 */  jal   osSyncPrintf
/* 0A221C 7F06D6EC 24844874 */   addiu $a0, %lo(aSubcalcposNoObjdesc) # addiu $a0, $a0, 0x4874
/* 0A2220 7F06D6F0 0FC1B11B */  jal   return_null
/* 0A2224 7F06D6F4 00000000 */   nop   
/* 0A2228 7F06D6F8 8FB80018 */  lw    $t8, 0x18($sp)
/* 0A222C 7F06D6FC 8F020008 */  lw    $v0, 8($t8)
/* 0A2230 7F06D700 8C450000 */  lw    $a1, ($v0)
.L7F06D704:
/* 0A2234 7F06D704 50A00009 */  beql  $a1, $zero, .L7F06D72C
/* 0A2238 7F06D708 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A223C 7F06D70C 94B90000 */  lhu   $t9, ($a1)
/* 0A2240 7F06D710 24010001 */  li    $at, 1
/* 0A2244 7F06D714 332800FF */  andi  $t0, $t9, 0xff
/* 0A2248 7F06D718 55010004 */  bnel  $t0, $at, .L7F06D72C
/* 0A224C 7F06D71C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A2250 7F06D720 0FC1B524 */  jal   sub_GAME_7F06D490
/* 0A2254 7F06D724 8FA40018 */   lw    $a0, 0x18($sp)
/* 0A2258 7F06D728 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06D72C:
/* 0A225C 7F06D72C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A2260 7F06D730 03E00008 */  jr    $ra
/* 0A2264 7F06D734 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_01_group_heading(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_01_group_heading
/* 0A2268 7F06D738 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0A226C 7F06D73C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A2270 7F06D740 AFA40080 */  sw    $a0, 0x80($sp)
/* 0A2274 7F06D744 8CCE0004 */  lw    $t6, 4($a2)
/* 0A2278 7F06D748 00A03825 */  move  $a3, $a1
/* 0A227C 7F06D74C 00A02025 */  move  $a0, $a1
/* 0A2280 7F06D750 00C02825 */  move  $a1, $a2
/* 0A2284 7F06D754 AFA70084 */  sw    $a3, 0x84($sp)
/* 0A2288 7F06D758 AFA60088 */  sw    $a2, 0x88($sp)
/* 0A228C 7F06D75C 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A2290 7F06D760 AFAE007C */   sw    $t6, 0x7c($sp)
/* 0A2294 7F06D764 8FA70084 */  lw    $a3, 0x84($sp)
/* 0A2298 7F06D768 8FB8007C */  lw    $t8, 0x7c($sp)
/* 0A229C 7F06D76C 244F0008 */  addiu $t7, $v0, 8
/* 0A22A0 7F06D770 C4E40014 */  lwc1  $f4, 0x14($a3)
/* 0A22A4 7F06D774 AFAF0070 */  sw    $t7, 0x70($sp)
/* 0A22A8 7F06D778 8FA60088 */  lw    $a2, 0x88($sp)
/* 0A22AC 7F06D77C E7A40074 */  swc1  $f4, 0x74($sp)
/* 0A22B0 7F06D780 87030002 */  lh    $v1, 2($t8)
/* 0A22B4 7F06D784 8CF9000C */  lw    $t9, 0xc($a3)
/* 0A22B8 7F06D788 C44C0014 */  lwc1  $f12, 0x14($v0)
/* 0A22BC 7F06D78C 00034980 */  sll   $t1, $v1, 6
/* 0A22C0 7F06D790 03295021 */  addu  $t2, $t9, $t1
/* 0A22C4 7F06D794 AFAA0060 */  sw    $t2, 0x60($sp)
/* 0A22C8 7F06D798 8CC50008 */  lw    $a1, 8($a2)
/* 0A22CC 7F06D79C 00404025 */  move  $t0, $v0
/* 0A22D0 7F06D7A0 8FAB0080 */  lw    $t3, 0x80($sp)
/* 0A22D4 7F06D7A4 10A00009 */  beqz  $a1, .L7F06D7CC
/* 0A22D8 7F06D7A8 00E02025 */   move  $a0, $a3
/* 0A22DC 7F06D7AC 00003025 */  move  $a2, $zero
/* 0A22E0 7F06D7B0 AFA20078 */  sw    $v0, 0x78($sp)
/* 0A22E4 7F06D7B4 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A22E8 7F06D7B8 E7AC006C */   swc1  $f12, 0x6c($sp)
/* 0A22EC 7F06D7BC 8FA80078 */  lw    $t0, 0x78($sp)
/* 0A22F0 7F06D7C0 C7AC006C */  lwc1  $f12, 0x6c($sp)
/* 0A22F4 7F06D7C4 10000002 */  b     .L7F06D7D0
/* 0A22F8 7F06D7C8 00403825 */   move  $a3, $v0
.L7F06D7CC:
/* 0A22FC 7F06D7CC 8D670000 */  lw    $a3, ($t3)
.L7F06D7D0:
/* 0A2300 7F06D7D0 C5000018 */  lwc1  $f0, 0x18($t0)
/* 0A2304 7F06D7D4 44803000 */  mtc1  $zero, $f6
/* 0A2308 7F06D7D8 00000000 */  nop   
/* 0A230C 7F06D7DC 46003032 */  c.eq.s $f6, $f0
/* 0A2310 7F06D7E0 00000000 */  nop   
/* 0A2314 7F06D7E4 45010007 */  bc1t  .L7F06D804
/* 0A2318 7F06D7E8 00000000 */   nop   
/* 0A231C 7F06D7EC C50E001C */  lwc1  $f14, 0x1c($t0)
/* 0A2320 7F06D7F0 44060000 */  mfc1  $a2, $f0
/* 0A2324 7F06D7F4 0FC1B433 */  jal   sub_GAME_7F06D0CC
/* 0A2328 7F06D7F8 AFA70068 */   sw    $a3, 0x68($sp)
/* 0A232C 7F06D7FC 8FA70068 */  lw    $a3, 0x68($sp)
/* 0A2330 7F06D800 46000306 */  mov.s $f12, $f0
.L7F06D804:
/* 0A2334 7F06D804 10E00019 */  beqz  $a3, .L7F06D86C
/* 0A2338 7F06D808 8FA40070 */   lw    $a0, 0x70($sp)
/* 0A233C 7F06D80C 44056000 */  mfc1  $a1, $f12
/* 0A2340 7F06D810 8FA40070 */  lw    $a0, 0x70($sp)
/* 0A2344 7F06D814 27A60020 */  addiu $a2, $sp, 0x20
/* 0A2348 7F06D818 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A234C 7F06D81C AFA70068 */   sw    $a3, 0x68($sp)
/* 0A2350 7F06D820 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A2354 7F06D824 44815000 */  mtc1  $at, $f10
/* 0A2358 7F06D828 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0A235C 7F06D82C 8FA70068 */  lw    $a3, 0x68($sp)
/* 0A2360 7F06D830 27A50020 */  addiu $a1, $sp, 0x20
/* 0A2364 7F06D834 460A4032 */  c.eq.s $f8, $f10
/* 0A2368 7F06D838 00000000 */  nop   
/* 0A236C 7F06D83C 45030006 */  bc1tl .L7F06D858
/* 0A2370 7F06D840 00E02025 */   move  $a0, $a3
/* 0A2374 7F06D844 46004306 */  mov.s $f12, $f8
/* 0A2378 7F06D848 0FC162C4 */  jal   matrix_scalar_multiply_2
/* 0A237C 7F06D84C AFA70068 */   sw    $a3, 0x68($sp)
/* 0A2380 7F06D850 8FA70068 */  lw    $a3, 0x68($sp)
/* 0A2384 7F06D854 00E02025 */  move  $a0, $a3
.L7F06D858:
/* 0A2388 7F06D858 27A50020 */  addiu $a1, $sp, 0x20
/* 0A238C 7F06D85C 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A2390 7F06D860 8FA60060 */   lw    $a2, 0x60($sp)
/* 0A2394 7F06D864 1000000F */  b     .L7F06D8A4
/* 0A2398 7F06D868 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06D86C:
/* 0A239C 7F06D86C 44056000 */  mfc1  $a1, $f12
/* 0A23A0 7F06D870 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0A23A4 7F06D874 8FA60060 */   lw    $a2, 0x60($sp)
/* 0A23A8 7F06D878 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A23AC 7F06D87C 44819000 */  mtc1  $at, $f18
/* 0A23B0 7F06D880 C7B00074 */  lwc1  $f16, 0x74($sp)
/* 0A23B4 7F06D884 8FA50060 */  lw    $a1, 0x60($sp)
/* 0A23B8 7F06D888 46128032 */  c.eq.s $f16, $f18
/* 0A23BC 7F06D88C 00000000 */  nop   
/* 0A23C0 7F06D890 45030004 */  bc1tl .L7F06D8A4
/* 0A23C4 7F06D894 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A23C8 7F06D898 0FC162C4 */  jal   matrix_scalar_multiply_2
/* 0A23CC 7F06D89C 46008306 */   mov.s $f12, $f16
/* 0A23D0 7F06D8A0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06D8A4:
/* 0A23D4 7F06D8A4 27BD0080 */  addiu $sp, $sp, 0x80
/* 0A23D8 7F06D8A8 03E00008 */  jr    $ra
/* 0A23DC 7F06D8AC 00000000 */   nop   
)
#endif





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
/* 0A2434 7F06D904 0FC1B198 */  jal   sub_GAME_7F06C660
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
/* 0A26E0 7F06DBB0 0FC1B198 */  jal   sub_GAME_7F06C660
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
void process_02_position(void) {

}
#else
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
/* 0A2E40 7F06E310 0FC1B198 */  jal   sub_GAME_7F06C660
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
void process_03_unknown(void) {

}
#else
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





#ifdef NONMATCHING
void process_15_subposition(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_15_subposition
/* 0A32D8 7F06E7A8 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0A32DC 7F06E7AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A32E0 7F06E7B0 AFA50074 */  sw    $a1, 0x74($sp)
/* 0A32E4 7F06E7B4 8CCE0004 */  lw    $t6, 4($a2)
/* 0A32E8 7F06E7B8 AFAE006C */  sw    $t6, 0x6c($sp)
/* 0A32EC 7F06E7BC 8CC70008 */  lw    $a3, 8($a2)
/* 0A32F0 7F06E7C0 8CA8000C */  lw    $t0, 0xc($a1)
/* 0A32F4 7F06E7C4 00003025 */  move  $a2, $zero
/* 0A32F8 7F06E7C8 10E0000A */  beqz  $a3, .L7F06E7F4
/* 0A32FC 7F06E7CC 85C3000C */   lh    $v1, 0xc($t6)
/* 0A3300 7F06E7D0 00A02025 */  move  $a0, $a1
/* 0A3304 7F06E7D4 00E02825 */  move  $a1, $a3
/* 0A3308 7F06E7D8 AFA30024 */  sw    $v1, 0x24($sp)
/* 0A330C 7F06E7DC 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A3310 7F06E7E0 AFA80020 */   sw    $t0, 0x20($sp)
/* 0A3314 7F06E7E4 8FA30024 */  lw    $v1, 0x24($sp)
/* 0A3318 7F06E7E8 8FA80020 */  lw    $t0, 0x20($sp)
/* 0A331C 7F06E7EC 10000002 */  b     .L7F06E7F8
/* 0A3320 7F06E7F0 00403825 */   move  $a3, $v0
.L7F06E7F4:
/* 0A3324 7F06E7F4 8C870000 */  lw    $a3, ($a0)
.L7F06E7F8:
/* 0A3328 7F06E7F8 10E00010 */  beqz  $a3, .L7F06E83C
/* 0A332C 7F06E7FC 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0A3330 7F06E800 8FA4006C */  lw    $a0, 0x6c($sp)
/* 0A3334 7F06E804 27A50028 */  addiu $a1, $sp, 0x28
/* 0A3338 7F06E808 AFA30024 */  sw    $v1, 0x24($sp)
/* 0A333C 7F06E80C AFA70068 */  sw    $a3, 0x68($sp)
/* 0A3340 7F06E810 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 0A3344 7F06E814 AFA80020 */   sw    $t0, 0x20($sp)
/* 0A3348 7F06E818 8FA30024 */  lw    $v1, 0x24($sp)
/* 0A334C 7F06E81C 8FA80020 */  lw    $t0, 0x20($sp)
/* 0A3350 7F06E820 8FA40068 */  lw    $a0, 0x68($sp)
/* 0A3354 7F06E824 0003C980 */  sll   $t9, $v1, 6
/* 0A3358 7F06E828 27A50028 */  addiu $a1, $sp, 0x28
/* 0A335C 7F06E82C 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0A3360 7F06E830 03283021 */   addu  $a2, $t9, $t0
/* 0A3364 7F06E834 10000005 */  b     .L7F06E84C
/* 0A3368 7F06E838 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F06E83C:
/* 0A336C 7F06E83C 00034980 */  sll   $t1, $v1, 6
/* 0A3370 7F06E840 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 0A3374 7F06E844 01282821 */   addu  $a1, $t1, $t0
/* 0A3378 7F06E848 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06E84C:
/* 0A337C 7F06E84C 27BD0070 */  addiu $sp, $sp, 0x70
/* 0A3380 7F06E850 03E00008 */  jr    $ra
/* 0A3384 7F06E854 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_08_distance_triggers(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_08_distance_triggers
/* 0A3388 7F06E858 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A338C 7F06E85C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3390 7F06E860 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3394 7F06E864 AFA40030 */  sw    $a0, 0x30($sp)
/* 0A3398 7F06E868 8CAE0004 */  lw    $t6, 4($a1)
/* 0A339C 7F06E86C 00A08025 */  move  $s0, $a1
/* 0A33A0 7F06E870 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A33A4 7F06E874 AFAE002C */   sw    $t6, 0x2c($sp)
/* 0A33A8 7F06E878 AFA20028 */  sw    $v0, 0x28($sp)
/* 0A33AC 7F06E87C 8FA40030 */  lw    $a0, 0x30($sp)
/* 0A33B0 7F06E880 02002825 */  move  $a1, $s0
/* 0A33B4 7F06E884 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A33B8 7F06E888 00003025 */   move  $a2, $zero
/* 0A33BC 7F06E88C 3C0F8003 */  lui   $t7, %hi(D_80036084) 
/* 0A33C0 7F06E890 8DEF6084 */  lw    $t7, %lo(D_80036084)($t7)
/* 0A33C4 7F06E894 00401825 */  move  $v1, $v0
/* 0A33C8 7F06E898 11E00004 */  beqz  $t7, .L7F06E8AC
/* 0A33CC 7F06E89C 00000000 */   nop   
/* 0A33D0 7F06E8A0 44801000 */  mtc1  $zero, $f2
/* 0A33D4 7F06E8A4 10000011 */  b     .L7F06E8EC
/* 0A33D8 7F06E8A8 8FA2002C */   lw    $v0, 0x2c($sp)
.L7F06E8AC:
/* 0A33DC 7F06E8AC 0FC1E121 */  jal   getPlayer_c_lodscalez
/* 0A33E0 7F06E8B0 AFA30024 */   sw    $v1, 0x24($sp)
/* 0A33E4 7F06E8B4 3C018003 */  lui   $at, %hi(D_80036088)
/* 0A33E8 7F06E8B8 8FA30024 */  lw    $v1, 0x24($sp)
/* 0A33EC 7F06E8BC C42C6088 */  lwc1  $f12, %lo(D_80036088)($at)
/* 0A33F0 7F06E8C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A33F4 7F06E8C4 44814000 */  mtc1  $at, $f8
/* 0A33F8 7F06E8C8 C4640038 */  lwc1  $f4, 0x38($v1)
/* 0A33FC 7F06E8CC 460C4032 */  c.eq.s $f8, $f12
/* 0A3400 7F06E8D0 46002187 */  neg.s $f6, $f4
/* 0A3404 7F06E8D4 46060082 */  mul.s $f2, $f0, $f6
/* 0A3408 7F06E8D8 45030004 */  bc1tl .L7F06E8EC
/* 0A340C 7F06E8DC 8FA2002C */   lw    $v0, 0x2c($sp)
/* 0A3410 7F06E8E0 460C1082 */  mul.s $f2, $f2, $f12
/* 0A3414 7F06E8E4 00000000 */  nop   
/* 0A3418 7F06E8E8 8FA2002C */  lw    $v0, 0x2c($sp)
.L7F06E8EC:
/* 0A341C 7F06E8EC 8FB80030 */  lw    $t8, 0x30($sp)
/* 0A3420 7F06E8F0 C4400000 */  lwc1  $f0, ($v0)
/* 0A3424 7F06E8F4 C70C0014 */  lwc1  $f12, 0x14($t8)
/* 0A3428 7F06E8F8 460C0282 */  mul.s $f10, $f0, $f12
/* 0A342C 7F06E8FC 4602503C */  c.lt.s $f10, $f2
/* 0A3430 7F06E900 00000000 */  nop   
/* 0A3434 7F06E904 45030008 */  bc1tl .L7F06E928
/* 0A3438 7F06E908 C4520004 */   lwc1  $f18, 4($v0)
/* 0A343C 7F06E90C 44808000 */  mtc1  $zero, $f16
/* 0A3440 7F06E910 00000000 */  nop   
/* 0A3444 7F06E914 46008032 */  c.eq.s $f16, $f0
/* 0A3448 7F06E918 00000000 */  nop   
/* 0A344C 7F06E91C 4502000D */  bc1fl .L7F06E954
/* 0A3450 7F06E920 8FAA0028 */   lw    $t2, 0x28($sp)
/* 0A3454 7F06E924 C4520004 */  lwc1  $f18, 4($v0)
.L7F06E928:
/* 0A3458 7F06E928 8FA80028 */  lw    $t0, 0x28($sp)
/* 0A345C 7F06E92C 460C9102 */  mul.s $f4, $f18, $f12
/* 0A3460 7F06E930 4604103E */  c.le.s $f2, $f4
/* 0A3464 7F06E934 00000000 */  nop   
/* 0A3468 7F06E938 45000005 */  bc1f  .L7F06E950
/* 0A346C 7F06E93C 24190001 */   li    $t9, 1
/* 0A3470 7F06E940 AD190000 */  sw    $t9, ($t0)
/* 0A3474 7F06E944 8C490008 */  lw    $t1, 8($v0)
/* 0A3478 7F06E948 10000004 */  b     .L7F06E95C
/* 0A347C 7F06E94C AE090014 */   sw    $t1, 0x14($s0)
.L7F06E950:
/* 0A3480 7F06E950 8FAA0028 */  lw    $t2, 0x28($sp)
.L7F06E954:
/* 0A3484 7F06E954 AD400000 */  sw    $zero, ($t2)
/* 0A3488 7F06E958 AE000014 */  sw    $zero, 0x14($s0)
.L7F06E95C:
/* 0A348C 7F06E95C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A3490 7F06E960 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A3494 7F06E964 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A3498 7F06E968 03E00008 */  jr    $ra
/* 0A349C 7F06E96C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06E970(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06E970
/* 0A34A0 7F06E970 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A34A4 7F06E974 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A34A8 7F06E978 8CAE0004 */  lw    $t6, 4($a1)
/* 0A34AC 7F06E97C AFA50024 */  sw    $a1, 0x24($sp)
/* 0A34B0 7F06E980 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A34B4 7F06E984 AFAE001C */   sw    $t6, 0x1c($sp)
/* 0A34B8 7F06E988 8C4F0000 */  lw    $t7, ($v0)
/* 0A34BC 7F06E98C 8FA50024 */  lw    $a1, 0x24($sp)
/* 0A34C0 7F06E990 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0A34C4 7F06E994 51E00005 */  beql  $t7, $zero, .L7F06E9AC
/* 0A34C8 7F06E998 ACA00014 */   sw    $zero, 0x14($a1)
/* 0A34CC 7F06E99C 8F190008 */  lw    $t9, 8($t8)
/* 0A34D0 7F06E9A0 10000002 */  b     .L7F06E9AC
/* 0A34D4 7F06E9A4 ACB90014 */   sw    $t9, 0x14($a1)
/* 0A34D8 7F06E9A8 ACA00014 */  sw    $zero, 0x14($a1)
.L7F06E9AC:
/* 0A34DC 7F06E9AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A34E0 7F06E9B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A34E4 7F06E9B4 03E00008 */  jr    $ra
/* 0A34E8 7F06E9B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_12_handle_switch(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_12_handle_switch
/* 0A34EC 7F06E9BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A34F0 7F06E9C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A34F4 7F06E9C4 8CAE0004 */  lw    $t6, 4($a1)
/* 0A34F8 7F06E9C8 AFA50024 */  sw    $a1, 0x24($sp)
/* 0A34FC 7F06E9CC 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A3500 7F06E9D0 AFAE001C */   sw    $t6, 0x1c($sp)
/* 0A3504 7F06E9D4 8C4F0000 */  lw    $t7, ($v0)
/* 0A3508 7F06E9D8 8FA50024 */  lw    $a1, 0x24($sp)
/* 0A350C 7F06E9DC 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0A3510 7F06E9E0 51E00005 */  beql  $t7, $zero, .L7F06E9F8
/* 0A3514 7F06E9E4 ACA00014 */   sw    $zero, 0x14($a1)
/* 0A3518 7F06E9E8 8F190000 */  lw    $t9, ($t8)
/* 0A351C 7F06E9EC 10000002 */  b     .L7F06E9F8
/* 0A3520 7F06E9F0 ACB90014 */   sw    $t9, 0x14($a1)
/* 0A3524 7F06E9F4 ACA00014 */  sw    $zero, 0x14($a1)
.L7F06E9F8:
/* 0A3528 7F06E9F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A352C 7F06E9FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A3530 7F06EA00 03E00008 */  jr    $ra
/* 0A3534 7F06EA04 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_17_pointer_to_head(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_17_pointer_to_head
/* 0A3538 7F06EA08 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A353C 7F06EA0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A3540 7F06EA10 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A3544 7F06EA14 AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A3548 7F06EA18 8C440000 */  lw    $a0, ($v0)
/* 0A354C 7F06EA1C 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0A3550 7F06EA20 50800009 */  beql  $a0, $zero, .L7F06EA48
/* 0A3554 7F06EA24 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A3558 7F06EA28 8C830000 */  lw    $v1, ($a0)
/* 0A355C 7F06EA2C 10600005 */  beqz  $v1, .L7F06EA44
/* 0A3560 7F06EA30 ACA30014 */   sw    $v1, 0x14($a1)
/* 0A3564 7F06EA34 AC650008 */  sw    $a1, 8($v1)
.L7F06EA38:
/* 0A3568 7F06EA38 8C63000C */  lw    $v1, 0xc($v1)
/* 0A356C 7F06EA3C 5460FFFE */  bnezl $v1, .L7F06EA38
/* 0A3570 7F06EA40 AC650008 */   sw    $a1, 8($v1)
.L7F06EA44:
/* 0A3574 7F06EA44 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F06EA48:
/* 0A3578 7F06EA48 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A357C 7F06EA4C 03E00008 */  jr    $ra
/* 0A3580 7F06EA50 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06EA54(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06EA54
/* 0A3584 7F06EA54 10A00004 */  beqz  $a1, .L7F06EA68
/* 0A3588 7F06EA58 8C820004 */   lw    $v0, 4($a0)
/* 0A358C 7F06EA5C 8C430018 */  lw    $v1, 0x18($v0)
/* 0A3590 7F06EA60 10000003 */  b     .L7F06EA70
/* 0A3594 7F06EA64 8C45001C */   lw    $a1, 0x1c($v0)
.L7F06EA68:
/* 0A3598 7F06EA68 8C43001C */  lw    $v1, 0x1c($v0)
/* 0A359C 7F06EA6C 8C450018 */  lw    $a1, 0x18($v0)
.L7F06EA70:
/* 0A35A0 7F06EA70 10600022 */  beqz  $v1, .L7F06EAFC
/* 0A35A4 7F06EA74 00000000 */   nop   
/* 0A35A8 7F06EA78 AC830014 */  sw    $v1, 0x14($a0)
/* 0A35AC 7F06EA7C 8C66000C */  lw    $a2, 0xc($v1)
/* 0A35B0 7F06EA80 AC600010 */  sw    $zero, 0x10($v1)
/* 0A35B4 7F06EA84 00601025 */  move  $v0, $v1
/* 0A35B8 7F06EA88 10C0000A */  beqz  $a2, .L7F06EAB4
/* 0A35BC 7F06EA8C 00000000 */   nop   
/* 0A35C0 7F06EA90 10A60008 */  beq   $a1, $a2, .L7F06EAB4
/* 0A35C4 7F06EA94 00000000 */   nop   
/* 0A35C8 7F06EA98 8C44000C */  lw    $a0, 0xc($v0)
/* 0A35CC 7F06EA9C 00801025 */  move  $v0, $a0
.L7F06EAA0:
/* 0A35D0 7F06EAA0 8C84000C */  lw    $a0, 0xc($a0)
/* 0A35D4 7F06EAA4 10800003 */  beqz  $a0, .L7F06EAB4
/* 0A35D8 7F06EAA8 00000000 */   nop   
/* 0A35DC 7F06EAAC 54A4FFFC */  bnel  $a1, $a0, .L7F06EAA0
/* 0A35E0 7F06EAB0 00801025 */   move  $v0, $a0
.L7F06EAB4:
/* 0A35E4 7F06EAB4 10A00014 */  beqz  $a1, .L7F06EB08
/* 0A35E8 7F06EAB8 AC45000C */   sw    $a1, 0xc($v0)
/* 0A35EC 7F06EABC 8CA4000C */  lw    $a0, 0xc($a1)
/* 0A35F0 7F06EAC0 ACA20010 */  sw    $v0, 0x10($a1)
/* 0A35F4 7F06EAC4 00A01025 */  move  $v0, $a1
/* 0A35F8 7F06EAC8 1080000A */  beqz  $a0, .L7F06EAF4
/* 0A35FC 7F06EACC 00000000 */   nop   
/* 0A3600 7F06EAD0 10640008 */  beq   $v1, $a0, .L7F06EAF4
/* 0A3604 7F06EAD4 00000000 */   nop   
/* 0A3608 7F06EAD8 8CA4000C */  lw    $a0, 0xc($a1)
/* 0A360C 7F06EADC 00801025 */  move  $v0, $a0
.L7F06EAE0:
/* 0A3610 7F06EAE0 8C84000C */  lw    $a0, 0xc($a0)
/* 0A3614 7F06EAE4 10800003 */  beqz  $a0, .L7F06EAF4
/* 0A3618 7F06EAE8 00000000 */   nop   
/* 0A361C 7F06EAEC 5464FFFC */  bnel  $v1, $a0, .L7F06EAE0
/* 0A3620 7F06EAF0 00801025 */   move  $v0, $a0
.L7F06EAF4:
/* 0A3624 7F06EAF4 03E00008 */  jr    $ra
/* 0A3628 7F06EAF8 AC40000C */   sw    $zero, 0xc($v0)

.L7F06EAFC:
/* 0A362C 7F06EAFC 10A00002 */  beqz  $a1, .L7F06EB08
/* 0A3630 7F06EB00 AC850014 */   sw    $a1, 0x14($a0)
/* 0A3634 7F06EB04 ACA00010 */  sw    $zero, 0x10($a1)
.L7F06EB08:
/* 0A3638 7F06EB08 03E00008 */  jr    $ra
/* 0A363C 7F06EB0C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06EB10(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06EB10
/* 0A3640 7F06EB10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A3644 7F06EB14 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A3648 7F06EB18 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A364C 7F06EB1C AFA5001C */   sw    $a1, 0x1c($sp)
/* 0A3650 7F06EB20 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0A3654 7F06EB24 0FC1BA95 */  jal   sub_GAME_7F06EA54
/* 0A3658 7F06EB28 8C450000 */   lw    $a1, ($v0)
/* 0A365C 7F06EB2C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A3660 7F06EB30 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A3664 7F06EB34 03E00008 */  jr    $ra
/* 0A3668 7F06EB38 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_09_head_hat_placement_interlink(void) {

}
#else
GLOBAL_ASM(
.text
glabel process_09_head_hat_placement_interlink
/* 0A366C 7F06EB3C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0A3670 7F06EB40 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3674 7F06EB44 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3678 7F06EB48 AFA40050 */  sw    $a0, 0x50($sp)
/* 0A367C 7F06EB4C 8CB00004 */  lw    $s0, 4($a1)
/* 0A3680 7F06EB50 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A3684 7F06EB54 AFA50054 */   sw    $a1, 0x54($sp)
/* 0A3688 7F06EB58 AFA20048 */  sw    $v0, 0x48($sp)
/* 0A368C 7F06EB5C 8FA40050 */  lw    $a0, 0x50($sp)
/* 0A3690 7F06EB60 8FA50054 */  lw    $a1, 0x54($sp)
/* 0A3694 7F06EB64 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A3698 7F06EB68 00003025 */   move  $a2, $zero
/* 0A369C 7F06EB6C 86030020 */  lh    $v1, 0x20($s0)
/* 0A36A0 7F06EB70 00402025 */  move  $a0, $v0
/* 0A36A4 7F06EB74 24010002 */  li    $at, 2
/* 0A36A8 7F06EB78 1460000C */  bnez  $v1, .L7F06EBAC
/* 0A36AC 7F06EB7C 00000000 */   nop   
/* 0A36B0 7F06EB80 C604000C */  lwc1  $f4, 0xc($s0)
/* 0A36B4 7F06EB84 27A50038 */  addiu $a1, $sp, 0x38
/* 0A36B8 7F06EB88 E7A40038 */  swc1  $f4, 0x38($sp)
/* 0A36BC 7F06EB8C C6060010 */  lwc1  $f6, 0x10($s0)
/* 0A36C0 7F06EB90 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0A36C4 7F06EB94 C6080014 */  lwc1  $f8, 0x14($s0)
/* 0A36C8 7F06EB98 AFA40044 */  sw    $a0, 0x44($sp)
/* 0A36CC 7F06EB9C 0FC160F6 */  jal   matrix_4x4_rotate_vector_in_place
/* 0A36D0 7F06EBA0 E7A80040 */   swc1  $f8, 0x40($sp)
/* 0A36D4 7F06EBA4 1000002F */  b     .L7F06EC64
/* 0A36D8 7F06EBA8 8FA40044 */   lw    $a0, 0x44($sp)
.L7F06EBAC:
/* 0A36DC 7F06EBAC 5461000F */  bnel  $v1, $at, .L7F06EBEC
/* 0A36E0 7F06EBB0 24010003 */   li    $at, 3
/* 0A36E4 7F06EBB4 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 0A36E8 7F06EBB8 C4500010 */  lwc1  $f16, 0x10($v0)
/* 0A36EC 7F06EBBC 46105482 */  mul.s $f18, $f10, $f16
/* 0A36F0 7F06EBC0 E7B20038 */  swc1  $f18, 0x38($sp)
/* 0A36F4 7F06EBC4 C6040010 */  lwc1  $f4, 0x10($s0)
/* 0A36F8 7F06EBC8 C4460014 */  lwc1  $f6, 0x14($v0)
/* 0A36FC 7F06EBCC 46062202 */  mul.s $f8, $f4, $f6
/* 0A3700 7F06EBD0 E7A8003C */  swc1  $f8, 0x3c($sp)
/* 0A3704 7F06EBD4 C4500018 */  lwc1  $f16, 0x18($v0)
/* 0A3708 7F06EBD8 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 0A370C 7F06EBDC 46105482 */  mul.s $f18, $f10, $f16
/* 0A3710 7F06EBE0 10000020 */  b     .L7F06EC64
/* 0A3714 7F06EBE4 E7B20040 */   swc1  $f18, 0x40($sp)
/* 0A3718 7F06EBE8 24010003 */  li    $at, 3
.L7F06EBEC:
/* 0A371C 7F06EBEC 5461000F */  bnel  $v1, $at, .L7F06EC2C
/* 0A3720 7F06EBF0 24010001 */   li    $at, 1
/* 0A3724 7F06EBF4 C6040014 */  lwc1  $f4, 0x14($s0)
/* 0A3728 7F06EBF8 C4460020 */  lwc1  $f6, 0x20($v0)
/* 0A372C 7F06EBFC 46062202 */  mul.s $f8, $f4, $f6
/* 0A3730 7F06EC00 E7A80038 */  swc1  $f8, 0x38($sp)
/* 0A3734 7F06EC04 C60A0014 */  lwc1  $f10, 0x14($s0)
/* 0A3738 7F06EC08 C4500024 */  lwc1  $f16, 0x24($v0)
/* 0A373C 7F06EC0C 46105482 */  mul.s $f18, $f10, $f16
/* 0A3740 7F06EC10 E7B2003C */  swc1  $f18, 0x3c($sp)
/* 0A3744 7F06EC14 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0A3748 7F06EC18 C6040014 */  lwc1  $f4, 0x14($s0)
/* 0A374C 7F06EC1C 46062202 */  mul.s $f8, $f4, $f6
/* 0A3750 7F06EC20 10000010 */  b     .L7F06EC64
/* 0A3754 7F06EC24 E7A80040 */   swc1  $f8, 0x40($sp)
/* 0A3758 7F06EC28 24010001 */  li    $at, 1
.L7F06EC2C:
/* 0A375C 7F06EC2C 5461000E */  bnel  $v1, $at, .L7F06EC68
/* 0A3760 7F06EC30 C6040000 */   lwc1  $f4, ($s0)
/* 0A3764 7F06EC34 C60A000C */  lwc1  $f10, 0xc($s0)
/* 0A3768 7F06EC38 C4500000 */  lwc1  $f16, ($v0)
/* 0A376C 7F06EC3C 46105482 */  mul.s $f18, $f10, $f16
/* 0A3770 7F06EC40 E7B20038 */  swc1  $f18, 0x38($sp)
/* 0A3774 7F06EC44 C604000C */  lwc1  $f4, 0xc($s0)
/* 0A3778 7F06EC48 C4460004 */  lwc1  $f6, 4($v0)
/* 0A377C 7F06EC4C 46062202 */  mul.s $f8, $f4, $f6
/* 0A3780 7F06EC50 E7A8003C */  swc1  $f8, 0x3c($sp)
/* 0A3784 7F06EC54 C4500008 */  lwc1  $f16, 8($v0)
/* 0A3788 7F06EC58 C60A000C */  lwc1  $f10, 0xc($s0)
/* 0A378C 7F06EC5C 46105482 */  mul.s $f18, $f10, $f16
/* 0A3790 7F06EC60 E7B20040 */  swc1  $f18, 0x40($sp)
.L7F06EC64:
/* 0A3794 7F06EC64 C6040000 */  lwc1  $f4, ($s0)
.L7F06EC68:
/* 0A3798 7F06EC68 27A5002C */  addiu $a1, $sp, 0x2c
/* 0A379C 7F06EC6C E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0A37A0 7F06EC70 C6060004 */  lwc1  $f6, 4($s0)
/* 0A37A4 7F06EC74 E7A60030 */  swc1  $f6, 0x30($sp)
/* 0A37A8 7F06EC78 C6080008 */  lwc1  $f8, 8($s0)
/* 0A37AC 7F06EC7C 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 0A37B0 7F06EC80 E7A80034 */   swc1  $f8, 0x34($sp)
/* 0A37B4 7F06EC84 C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 0A37B8 7F06EC88 C7B0002C */  lwc1  $f16, 0x2c($sp)
/* 0A37BC 7F06EC8C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0A37C0 7F06EC90 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 0A37C4 7F06EC94 46105482 */  mul.s $f18, $f10, $f16
/* 0A37C8 7F06EC98 C7B00034 */  lwc1  $f16, 0x34($sp)
/* 0A37CC 7F06EC9C 8FAF0048 */  lw    $t7, 0x48($sp)
/* 0A37D0 7F06ECA0 46062202 */  mul.s $f8, $f4, $f6
/* 0A37D4 7F06ECA4 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0A37D8 7F06ECA8 8FB80048 */  lw    $t8, 0x48($sp)
/* 0A37DC 7F06ECAC 46048182 */  mul.s $f6, $f16, $f4
/* 0A37E0 7F06ECB0 46089280 */  add.s $f10, $f18, $f8
/* 0A37E4 7F06ECB4 44809000 */  mtc1  $zero, $f18
/* 0A37E8 7F06ECB8 460A3000 */  add.s $f0, $f6, $f10
/* 0A37EC 7F06ECBC 4612003C */  c.lt.s $f0, $f18
/* 0A37F0 7F06ECC0 00000000 */  nop   
/* 0A37F4 7F06ECC4 45000003 */  bc1f  .L7F06ECD4
/* 0A37F8 7F06ECC8 240E0001 */   li    $t6, 1
/* 0A37FC 7F06ECCC 10000002 */  b     .L7F06ECD8
/* 0A3800 7F06ECD0 ADEE0000 */   sw    $t6, ($t7)
.L7F06ECD4:
/* 0A3804 7F06ECD4 AF000000 */  sw    $zero, ($t8)
.L7F06ECD8:
/* 0A3808 7F06ECD8 8FA40050 */  lw    $a0, 0x50($sp)
/* 0A380C 7F06ECDC 0FC1BAC4 */  jal   sub_GAME_7F06EB10
/* 0A3810 7F06ECE0 8FA50054 */   lw    $a1, 0x54($sp)
/* 0A3814 7F06ECE4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A3818 7F06ECE8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A381C 7F06ECEC 27BD0050 */  addiu $sp, $sp, 0x50
/* 0A3820 7F06ECF0 03E00008 */  jr    $ra
/* 0A3824 7F06ECF4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_07_unknown(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054C18
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C1C
.word 0x40c90fdb /*6.2831855*/
.text
glabel process_07_unknown
/* 0A3828 7F06ECF8 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0A382C 7F06ECFC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3830 7F06ED00 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3834 7F06ED04 AFA40058 */  sw    $a0, 0x58($sp)
/* 0A3838 7F06ED08 8CAE0004 */  lw    $t6, 4($a1)
/* 0A383C 7F06ED0C 00A08025 */  move  $s0, $a1
/* 0A3840 7F06ED10 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A3844 7F06ED14 AFAE0054 */   sw    $t6, 0x54($sp)
/* 0A3848 7F06ED18 AFA20050 */  sw    $v0, 0x50($sp)
/* 0A384C 7F06ED1C 8FA40058 */  lw    $a0, 0x58($sp)
/* 0A3850 7F06ED20 02002825 */  move  $a1, $s0
/* 0A3854 7F06ED24 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0A3858 7F06ED28 00003025 */   move  $a2, $zero
/* 0A385C 7F06ED2C 00408025 */  move  $s0, $v0
/* 0A3860 7F06ED30 8FA40058 */  lw    $a0, 0x58($sp)
/* 0A3864 7F06ED34 0FC1B154 */  jal   sub_GAME_7F06C550
/* 0A3868 7F06ED38 27A50038 */   addiu $a1, $sp, 0x38
/* 0A386C 7F06ED3C C7A40038 */  lwc1  $f4, 0x38($sp)
/* 0A3870 7F06ED40 C6060010 */  lwc1  $f6, 0x10($s0)
/* 0A3874 7F06ED44 C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 0A3878 7F06ED48 C6100014 */  lwc1  $f16, 0x14($s0)
/* 0A387C 7F06ED4C 46062202 */  mul.s $f8, $f4, $f6
/* 0A3880 7F06ED50 C6060018 */  lwc1  $f6, 0x18($s0)
/* 0A3884 7F06ED54 46105482 */  mul.s $f18, $f10, $f16
/* 0A3888 7F06ED58 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0A388C 7F06ED5C 460A3402 */  mul.s $f16, $f6, $f10
/* 0A3890 7F06ED60 46124100 */  add.s $f4, $f8, $f18
/* 0A3894 7F06ED64 0FC16B2C */  jal   acosf
/* 0A3898 7F06ED68 46048300 */   add.s $f12, $f16, $f4
/* 0A389C 7F06ED6C E7A00030 */  swc1  $f0, 0x30($sp)
/* 0A38A0 7F06ED70 0FC15FAB */  jal   sinf
/* 0A38A4 7F06ED74 46000306 */   mov.s $f12, $f0
/* 0A38A8 7F06ED78 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0A38AC 7F06ED7C C6120020 */  lwc1  $f18, 0x20($s0)
/* 0A38B0 7F06ED80 C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 0A38B4 7F06ED84 C6100024 */  lwc1  $f16, 0x24($s0)
/* 0A38B8 7F06ED88 46124182 */  mul.s $f6, $f8, $f18
/* 0A38BC 7F06ED8C C7B20040 */  lwc1  $f18, 0x40($sp)
/* 0A38C0 7F06ED90 46105102 */  mul.s $f4, $f10, $f16
/* 0A38C4 7F06ED94 C60A0028 */  lwc1  $f10, 0x28($s0)
/* 0A38C8 7F06ED98 460A9402 */  mul.s $f16, $f18, $f10
/* 0A38CC 7F06ED9C 46043200 */  add.s $f8, $f6, $f4
/* 0A38D0 7F06EDA0 46104180 */  add.s $f6, $f8, $f16
/* 0A38D4 7F06EDA4 0FC16B2C */  jal   acosf
/* 0A38D8 7F06EDA8 46003303 */   div.s $f12, $f6, $f0
/* 0A38DC 7F06EDAC C7A40038 */  lwc1  $f4, 0x38($sp)
/* 0A38E0 7F06EDB0 C6120000 */  lwc1  $f18, ($s0)
/* 0A38E4 7F06EDB4 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0A38E8 7F06EDB8 C6100004 */  lwc1  $f16, 4($s0)
/* 0A38EC 7F06EDBC 46122282 */  mul.s $f10, $f4, $f18
/* 0A38F0 7F06EDC0 C6120008 */  lwc1  $f18, 8($s0)
/* 0A38F4 7F06EDC4 44807000 */  mtc1  $zero, $f14
/* 0A38F8 7F06EDC8 46104182 */  mul.s $f6, $f8, $f16
/* 0A38FC 7F06EDCC C7A80040 */  lwc1  $f8, 0x40($sp)
/* 0A3900 7F06EDD0 46000306 */  mov.s $f12, $f0
/* 0A3904 7F06EDD4 46089402 */  mul.s $f16, $f18, $f8
/* 0A3908 7F06EDD8 46065100 */  add.s $f4, $f10, $f6
/* 0A390C 7F06EDDC C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0A3910 7F06EDE0 46048080 */  add.s $f2, $f16, $f4
/* 0A3914 7F06EDE4 460E103C */  c.lt.s $f2, $f14
/* 0A3918 7F06EDE8 00000000 */  nop   
/* 0A391C 7F06EDEC 45000007 */  bc1f  .L7F06EE0C
/* 0A3920 7F06EDF0 00000000 */   nop   
/* 0A3924 7F06EDF4 4600703C */  c.lt.s $f14, $f0
/* 0A3928 7F06EDF8 3C018005 */  lui   $at, %hi(D_80054C18)
/* 0A392C 7F06EDFC 45000003 */  bc1f  .L7F06EE0C
/* 0A3930 7F06EE00 00000000 */   nop   
/* 0A3934 7F06EE04 C4224C18 */  lwc1  $f2, %lo(D_80054C18)($at)
/* 0A3938 7F06EE08 46001301 */  sub.s $f12, $f2, $f0
.L7F06EE0C:
/* 0A393C 7F06EE0C 3C018005 */  lui   $at, %hi(D_80054C1C)
/* 0A3940 7F06EE10 C4224C1C */  lwc1  $f2, %lo(D_80054C1C)($at)
/* 0A3944 7F06EE14 3C014280 */  li    $at, 0x42800000 # 64.000000
/* 0A3948 7F06EE18 44813000 */  mtc1  $at, $f6
/* 0A394C 7F06EE1C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0A3950 7F06EE20 44812000 */  mtc1  $at, $f4
/* 0A3954 7F06EE24 46065482 */  mul.s $f18, $f10, $f6
/* 0A3958 7F06EE28 3C088003 */  lui   $t0, %hi(D_800360C4) 
/* 0A395C 7F06EE2C 250860C4 */  addiu $t0, %lo(D_800360C4) # addiu $t0, $t0, 0x60c4
/* 0A3960 7F06EE30 46046282 */  mul.s $f10, $f12, $f4
/* 0A3964 7F06EE34 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0A3968 7F06EE38 46029203 */  div.s $f8, $f18, $f2
/* 0A396C 7F06EE3C 46025183 */  div.s $f6, $f10, $f2
/* 0A3970 7F06EE40 4600440D */  trunc.w.s $f16, $f8
/* 0A3974 7F06EE44 44188000 */  mfc1  $t8, $f16
/* 0A3978 7F06EE48 00000000 */  nop   
/* 0A397C 7F06EE4C 0018C880 */  sll   $t9, $t8, 2
/* 0A3980 7F06EE50 0338C823 */  subu  $t9, $t9, $t8
/* 0A3984 7F06EE54 0019C880 */  sll   $t9, $t9, 2
/* 0A3988 7F06EE58 03281821 */  addu  $v1, $t9, $t0
/* 0A398C 7F06EE5C 8C6B0004 */  lw    $t3, 4($v1)
/* 0A3990 7F06EE60 8C6C0008 */  lw    $t4, 8($v1)
/* 0A3994 7F06EE64 8C6D0000 */  lw    $t5, ($v1)
/* 0A3998 7F06EE68 8FB90050 */  lw    $t9, 0x50($sp)
/* 0A399C 7F06EE6C 4600348D */  trunc.w.s $f18, $f6
/* 0A39A0 7F06EE70 440A9000 */  mfc1  $t2, $f18
/* 0A39A4 7F06EE74 00000000 */  nop   
/* 0A39A8 7F06EE78 014B1021 */  addu  $v0, $t2, $t3
/* 0A39AC 7F06EE7C 01821007 */  srav  $v0, $v0, $t4
/* 0A39B0 7F06EE80 01A22021 */  addu  $a0, $t5, $v0
/* 0A39B4 7F06EE84 01C47821 */  addu  $t7, $t6, $a0
/* 0A39B8 7F06EE88 91F80018 */  lbu   $t8, 0x18($t7)
/* 0A39BC 7F06EE8C AF380000 */  sw    $t8, ($t9)
/* 0A39C0 7F06EE90 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A39C4 7F06EE94 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A39C8 7F06EE98 27BD0058 */  addiu $sp, $sp, 0x58
/* 0A39CC 7F06EE9C 03E00008 */  jr    $ra
/* 0A39D0 7F06EEA0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06EEA4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054C20*/
glabel jpt_80054C20
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF2C
.word .L7F06EF04
.word .L7F06EF18
.word .L7F06EF4C
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF40
/*.word .L7F06EF4C*/

.text
glabel sub_GAME_7F06EEA4
/* 0A39D4 7F06EEA4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0A39D8 7F06EEA8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A39DC 7F06EEAC AFB20020 */  sw    $s2, 0x20($sp)
/* 0A39E0 7F06EEB0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A39E4 7F06EEB4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A39E8 7F06EEB8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0A39EC 7F06EEBC 8CB00014 */  lw    $s0, 0x14($a1)
/* 0A39F0 7F06EEC0 00809025 */  move  $s2, $a0
/* 0A39F4 7F06EEC4 5200003A */  beql  $s0, $zero, .L7F06EFB0
/* 0A39F8 7F06EEC8 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A39FC 7F06EECC 96020000 */  lhu   $v0, ($s0)
.L7F06EED0:
/* 0A3A00 7F06EED0 24110001 */  li    $s1, 1
/* 0A3A04 7F06EED4 304F00FF */  andi  $t7, $v0, 0xff
/* 0A3A08 7F06EED8 25F8FFFF */  addiu $t8, $t7, -1
/* 0A3A0C 7F06EEDC 2F010018 */  sltiu $at, $t8, 0x18
/* 0A3A10 7F06EEE0 1020001A */  beqz  $at, .L7F06EF4C
/* 0A3A14 7F06EEE4 0018C080 */   sll   $t8, $t8, 2
/* 0A3A18 7F06EEE8 3C018005 */  lui   $at, %hi(jpt_80054C20)
/* 0A3A1C 7F06EEEC 00380821 */  addu  $at, $at, $t8
/* 0A3A20 7F06EEF0 8C384C20 */  lw    $t8, %lo(jpt_80054C20)($at)
.L7F06EEF4:
/* 0A3A24 7F06EEF4 03000008 */  jr    $t8
/* 0A3A28 7F06EEF8 00000000 */   nop   
.L7F06EEFC:
/* 0A3A2C 7F06EEFC 10000013 */  b     .L7F06EF4C
/* 0A3A30 7F06EF00 00008825 */   move  $s1, $zero
.L7F06EF04:
/* 0A3A34 7F06EF04 02402025 */  move  $a0, $s2
/* 0A3A38 7F06EF08 0FC1BA16 */  jal   process_08_distance_triggers
/* 0A3A3C 7F06EF0C 02002825 */   move  $a1, $s0
/* 0A3A40 7F06EF10 1000000E */  b     .L7F06EF4C
/* 0A3A44 7F06EF14 00000000 */   nop   
.L7F06EF18:
/* 0A3A48 7F06EF18 02402025 */  move  $a0, $s2
/* 0A3A4C 7F06EF1C 0FC1BACF */  jal   process_09_head_hat_placement_interlink
/* 0A3A50 7F06EF20 02002825 */   move  $a1, $s0
/* 0A3A54 7F06EF24 10000009 */  b     .L7F06EF4C
/* 0A3A58 7F06EF28 00000000 */   nop   
.L7F06EF2C:
/* 0A3A5C 7F06EF2C 02402025 */  move  $a0, $s2
/* 0A3A60 7F06EF30 0FC1BB3E */  jal   process_07_unknown
/* 0A3A64 7F06EF34 02002825 */   move  $a1, $s0
/* 0A3A68 7F06EF38 10000004 */  b     .L7F06EF4C
/* 0A3A6C 7F06EF3C 00000000 */   nop   
.L7F06EF40:
/* 0A3A70 7F06EF40 02402025 */  move  $a0, $s2
/* 0A3A74 7F06EF44 0FC1BA82 */  jal   process_17_pointer_to_head
/* 0A3A78 7F06EF48 02002825 */   move  $a1, $s0
def_7F06EEF4:
.L7F06EF4C:
/* 0A3A7C 7F06EF4C 12200006 */  beqz  $s1, .L7F06EF68
/* 0A3A80 7F06EF50 00000000 */   nop   
/* 0A3A84 7F06EF54 8E020014 */  lw    $v0, 0x14($s0)
/* 0A3A88 7F06EF58 10400003 */  beqz  $v0, .L7F06EF68
/* 0A3A8C 7F06EF5C 00000000 */   nop   
/* 0A3A90 7F06EF60 10000010 */  b     .L7F06EFA4
/* 0A3A94 7F06EF64 00408025 */   move  $s0, $v0
.L7F06EF68:
/* 0A3A98 7F06EF68 1200000E */  beqz  $s0, .L7F06EFA4
/* 0A3A9C 7F06EF6C 8FB9002C */   lw    $t9, 0x2c($sp)
/* 0A3AA0 7F06EF70 8F230008 */  lw    $v1, 8($t9)
.L7F06EF74:
/* 0A3AA4 7F06EF74 56030004 */  bnel  $s0, $v1, .L7F06EF88
/* 0A3AA8 7F06EF78 8E02000C */   lw    $v0, 0xc($s0)
/* 0A3AAC 7F06EF7C 10000009 */  b     .L7F06EFA4
/* 0A3AB0 7F06EF80 00008025 */   move  $s0, $zero
/* 0A3AB4 7F06EF84 8E02000C */  lw    $v0, 0xc($s0)
.L7F06EF88:
/* 0A3AB8 7F06EF88 50400004 */  beql  $v0, $zero, .L7F06EF9C
/* 0A3ABC 7F06EF8C 8E100008 */   lw    $s0, 8($s0)
/* 0A3AC0 7F06EF90 10000004 */  b     .L7F06EFA4
/* 0A3AC4 7F06EF94 00408025 */   move  $s0, $v0
/* 0A3AC8 7F06EF98 8E100008 */  lw    $s0, 8($s0)
.L7F06EF9C:
/* 0A3ACC 7F06EF9C 1600FFF5 */  bnez  $s0, .L7F06EF74
/* 0A3AD0 7F06EFA0 00000000 */   nop   
.L7F06EFA4:
/* 0A3AD4 7F06EFA4 5600FFCA */  bnezl $s0, .L7F06EED0
/* 0A3AD8 7F06EFA8 96020000 */   lhu   $v0, ($s0)
/* 0A3ADC 7F06EFAC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06EFB0:
/* 0A3AE0 7F06EFB0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A3AE4 7F06EFB4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A3AE8 7F06EFB8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A3AEC 7F06EFBC 03E00008 */  jr    $ra
/* 0A3AF0 7F06EFC0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06EFC4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for above jtbl being too big*/
.word .L7F06EF4C

/*D:80054C80*/
glabel jpt_80054C80
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F03C
.word .L7F06F014
.word .L7F06F028
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F050
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
/*.word .L7F06F078*/
/*.word .L7F06F064*/
/*.word .L7F06F078*/

.text
glabel sub_GAME_7F06EFC4
/* 0A3AF4 7F06EFC4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A3AF8 7F06EFC8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3AFC 7F06EFCC AFB10018 */  sw    $s1, 0x18($sp)
/* 0A3B00 7F06EFD0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0A3B04 7F06EFD4 8C8E0008 */  lw    $t6, 8($a0)
/* 0A3B08 7F06EFD8 00808825 */  move  $s1, $a0
/* 0A3B0C 7F06EFDC 8DD00000 */  lw    $s0, ($t6)
/* 0A3B10 7F06EFE0 52000037 */  beql  $s0, $zero, .L7F06F0C0
/* 0A3B14 7F06EFE4 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A3B18 7F06EFE8 96020000 */  lhu   $v0, ($s0)
.L7F06EFEC:
/* 0A3B1C 7F06EFEC 304F00FF */  andi  $t7, $v0, 0xff
/* 0A3B20 7F06EFF0 25F8FFFF */  addiu $t8, $t7, -1
/* 0A3B24 7F06EFF4 2F010018 */  sltiu $at, $t8, 0x18
/* 0A3B28 7F06EFF8 1020001F */  beqz  $at, .L7F06F078
/* 0A3B2C 7F06EFFC 0018C080 */   sll   $t8, $t8, 2
/* 0A3B30 7F06F000 3C018005 */  lui   $at, %hi(jpt_80054C80)
/* 0A3B34 7F06F004 00380821 */  addu  $at, $at, $t8
/* 0A3B38 7F06F008 8C384C80 */  lw    $t8, %lo(jpt_80054C80)($at)
.L7F06F00C:
/* 0A3B3C 7F06F00C 03000008 */  jr    $t8
/* 0A3B40 7F06F010 00000000 */   nop   
.L7F06F014:
/* 0A3B44 7F06F014 02202025 */  move  $a0, $s1
/* 0A3B48 7F06F018 0FC1BA16 */  jal   process_08_distance_triggers
/* 0A3B4C 7F06F01C 02002825 */   move  $a1, $s0
/* 0A3B50 7F06F020 10000016 */  b     .L7F06F07C
/* 0A3B54 7F06F024 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F028:
/* 0A3B58 7F06F028 02202025 */  move  $a0, $s1
/* 0A3B5C 7F06F02C 0FC1BACF */  jal   process_09_head_hat_placement_interlink
/* 0A3B60 7F06F030 02002825 */   move  $a1, $s0
/* 0A3B64 7F06F034 10000011 */  b     .L7F06F07C
/* 0A3B68 7F06F038 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F03C:
/* 0A3B6C 7F06F03C 02202025 */  move  $a0, $s1
/* 0A3B70 7F06F040 0FC1BB3E */  jal   process_07_unknown
/* 0A3B74 7F06F044 02002825 */   move  $a1, $s0
/* 0A3B78 7F06F048 1000000C */  b     .L7F06F07C
/* 0A3B7C 7F06F04C 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F050:
/* 0A3B80 7F06F050 02202025 */  move  $a0, $s1
/* 0A3B84 7F06F054 0FC1BA6F */  jal   process_12_handle_switch
/* 0A3B88 7F06F058 02002825 */   move  $a1, $s0
/* 0A3B8C 7F06F05C 10000007 */  b     .L7F06F07C
/* 0A3B90 7F06F060 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F064:
/* 0A3B94 7F06F064 02202025 */  move  $a0, $s1
/* 0A3B98 7F06F068 0FC1BA82 */  jal   process_17_pointer_to_head
/* 0A3B9C 7F06F06C 02002825 */   move  $a1, $s0
/* 0A3BA0 7F06F070 10000002 */  b     .L7F06F07C
/* 0A3BA4 7F06F074 8E020014 */   lw    $v0, 0x14($s0)
def_7F06F00C:
.L7F06F078:
/* 0A3BA8 7F06F078 8E020014 */  lw    $v0, 0x14($s0)
.L7F06F07C:
/* 0A3BAC 7F06F07C 10400003 */  beqz  $v0, .L7F06F08C
/* 0A3BB0 7F06F080 00000000 */   nop   
/* 0A3BB4 7F06F084 1000000B */  b     .L7F06F0B4
/* 0A3BB8 7F06F088 00408025 */   move  $s0, $v0
.L7F06F08C:
/* 0A3BBC 7F06F08C 12000009 */  beqz  $s0, .L7F06F0B4
/* 0A3BC0 7F06F090 00000000 */   nop   
/* 0A3BC4 7F06F094 8E02000C */  lw    $v0, 0xc($s0)
.L7F06F098:
/* 0A3BC8 7F06F098 50400004 */  beql  $v0, $zero, .L7F06F0AC
/* 0A3BCC 7F06F09C 8E100008 */   lw    $s0, 8($s0)
/* 0A3BD0 7F06F0A0 10000004 */  b     .L7F06F0B4
/* 0A3BD4 7F06F0A4 00408025 */   move  $s0, $v0
/* 0A3BD8 7F06F0A8 8E100008 */  lw    $s0, 8($s0)
.L7F06F0AC:
/* 0A3BDC 7F06F0AC 5600FFFA */  bnezl $s0, .L7F06F098
/* 0A3BE0 7F06F0B0 8E02000C */   lw    $v0, 0xc($s0)
.L7F06F0B4:
/* 0A3BE4 7F06F0B4 5600FFCD */  bnezl $s0, .L7F06EFEC
/* 0A3BE8 7F06F0B8 96020000 */   lhu   $v0, ($s0)
/* 0A3BEC 7F06F0BC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F06F0C0:
/* 0A3BF0 7F06F0C0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0A3BF4 7F06F0C4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0A3BF8 7F06F0C8 03E00008 */  jr    $ra
/* 0A3BFC 7F06F0CC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F0D0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for above jtbl*/
.word .L7F06F078
.word .L7F06F064
.word .L7F06F078

/*D:80054CE0*/
glabel jpt_80054CE0
.word .L7F06F128
.word .L7F06F140
.word .L7F06F158
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1B0
.word .L7F06F188
.word .L7F06F19C
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1C4
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F170
.word .L7F06F1EC
.word .L7F06F1D8
.word .L7F06F1EC

.text
glabel sub_GAME_7F06F0D0
/* 0A3C00 7F06F0D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0A3C04 7F06F0D4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A3C08 7F06F0D8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0A3C0C 7F06F0DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A3C10 7F06F0E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3C14 7F06F0E4 8CAE0008 */  lw    $t6, 8($a1)
/* 0A3C18 7F06F0E8 00A08825 */  move  $s1, $a1
/* 0A3C1C 7F06F0EC 00809025 */  move  $s2, $a0
/* 0A3C20 7F06F0F0 8DD00000 */  lw    $s0, ($t6)
/* 0A3C24 7F06F0F4 5200004F */  beql  $s0, $zero, .L7F06F234
/* 0A3C28 7F06F0F8 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A3C2C 7F06F0FC 96020000 */  lhu   $v0, ($s0)
.L7F06F100:
/* 0A3C30 7F06F100 304F00FF */  andi  $t7, $v0, 0xff
/* 0A3C34 7F06F104 25F8FFFF */  addiu $t8, $t7, -1
/* 0A3C38 7F06F108 2F010018 */  sltiu $at, $t8, 0x18
/* 0A3C3C 7F06F10C 10200037 */  beqz  $at, .L7F06F1EC
/* 0A3C40 7F06F110 0018C080 */   sll   $t8, $t8, 2
/* 0A3C44 7F06F114 3C018005 */  lui   $at, %hi(jpt_80054CE0)
/* 0A3C48 7F06F118 00380821 */  addu  $at, $at, $t8
/* 0A3C4C 7F06F11C 8C384CE0 */  lw    $t8, %lo(jpt_80054CE0)($at)
.L7F06F120:
/* 0A3C50 7F06F120 03000008 */  jr    $t8
/* 0A3C54 7F06F124 00000000 */   nop   
.L7F06F128:
/* 0A3C58 7F06F128 02402025 */  move  $a0, $s2
/* 0A3C5C 7F06F12C 02202825 */  move  $a1, $s1
/* 0A3C60 7F06F130 0FC1B5CE */  jal   process_01_group_heading
/* 0A3C64 7F06F134 02003025 */   move  $a2, $s0
/* 0A3C68 7F06F138 1000002D */  b     .L7F06F1F0
/* 0A3C6C 7F06F13C 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F140:
/* 0A3C70 7F06F140 02402025 */  move  $a0, $s2
/* 0A3C74 7F06F144 02202825 */  move  $a1, $s1
/* 0A3C78 7F06F148 0FC1B828 */  jal   process_02_position
/* 0A3C7C 7F06F14C 02003025 */   move  $a2, $s0
/* 0A3C80 7F06F150 10000027 */  b     .L7F06F1F0
/* 0A3C84 7F06F154 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F158:
/* 0A3C88 7F06F158 02402025 */  move  $a0, $s2
/* 0A3C8C 7F06F15C 02202825 */  move  $a1, $s1
/* 0A3C90 7F06F160 0FC1B993 */  jal   process_03_unknown
/* 0A3C94 7F06F164 02003025 */   move  $a2, $s0
/* 0A3C98 7F06F168 10000021 */  b     .L7F06F1F0
/* 0A3C9C 7F06F16C 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F170:
/* 0A3CA0 7F06F170 02402025 */  move  $a0, $s2
/* 0A3CA4 7F06F174 02202825 */  move  $a1, $s1
/* 0A3CA8 7F06F178 0FC1B9EA */  jal   process_15_subposition
/* 0A3CAC 7F06F17C 02003025 */   move  $a2, $s0
/* 0A3CB0 7F06F180 1000001B */  b     .L7F06F1F0
/* 0A3CB4 7F06F184 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F188:
/* 0A3CB8 7F06F188 02202025 */  move  $a0, $s1
/* 0A3CBC 7F06F18C 0FC1BA16 */  jal   process_08_distance_triggers
/* 0A3CC0 7F06F190 02002825 */   move  $a1, $s0
/* 0A3CC4 7F06F194 10000016 */  b     .L7F06F1F0
/* 0A3CC8 7F06F198 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F19C:
/* 0A3CCC 7F06F19C 02202025 */  move  $a0, $s1
/* 0A3CD0 7F06F1A0 0FC1BACF */  jal   process_09_head_hat_placement_interlink
/* 0A3CD4 7F06F1A4 02002825 */   move  $a1, $s0
/* 0A3CD8 7F06F1A8 10000011 */  b     .L7F06F1F0
/* 0A3CDC 7F06F1AC 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F1B0:
/* 0A3CE0 7F06F1B0 02202025 */  move  $a0, $s1
/* 0A3CE4 7F06F1B4 0FC1BB3E */  jal   process_07_unknown
/* 0A3CE8 7F06F1B8 02002825 */   move  $a1, $s0
/* 0A3CEC 7F06F1BC 1000000C */  b     .L7F06F1F0
/* 0A3CF0 7F06F1C0 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F1C4:
/* 0A3CF4 7F06F1C4 02202025 */  move  $a0, $s1
/* 0A3CF8 7F06F1C8 0FC1BA6F */  jal   process_12_handle_switch
/* 0A3CFC 7F06F1CC 02002825 */   move  $a1, $s0
/* 0A3D00 7F06F1D0 10000007 */  b     .L7F06F1F0
/* 0A3D04 7F06F1D4 8E020014 */   lw    $v0, 0x14($s0)
.L7F06F1D8:
/* 0A3D08 7F06F1D8 02202025 */  move  $a0, $s1
/* 0A3D0C 7F06F1DC 0FC1BA82 */  jal   process_17_pointer_to_head
/* 0A3D10 7F06F1E0 02002825 */   move  $a1, $s0
/* 0A3D14 7F06F1E4 10000002 */  b     .L7F06F1F0
/* 0A3D18 7F06F1E8 8E020014 */   lw    $v0, 0x14($s0)
def_7F06F120:
.L7F06F1EC:
/* 0A3D1C 7F06F1EC 8E020014 */  lw    $v0, 0x14($s0)
.L7F06F1F0:
/* 0A3D20 7F06F1F0 10400003 */  beqz  $v0, .L7F06F200
/* 0A3D24 7F06F1F4 00000000 */   nop   
/* 0A3D28 7F06F1F8 1000000B */  b     .L7F06F228
/* 0A3D2C 7F06F1FC 00408025 */   move  $s0, $v0
.L7F06F200:
/* 0A3D30 7F06F200 12000009 */  beqz  $s0, .L7F06F228
/* 0A3D34 7F06F204 00000000 */   nop   
/* 0A3D38 7F06F208 8E02000C */  lw    $v0, 0xc($s0)
.L7F06F20C:
/* 0A3D3C 7F06F20C 50400004 */  beql  $v0, $zero, .L7F06F220
/* 0A3D40 7F06F210 8E100008 */   lw    $s0, 8($s0)
/* 0A3D44 7F06F214 10000004 */  b     .L7F06F228
/* 0A3D48 7F06F218 00408025 */   move  $s0, $v0
/* 0A3D4C 7F06F21C 8E100008 */  lw    $s0, 8($s0)
.L7F06F220:
/* 0A3D50 7F06F220 5600FFFA */  bnezl $s0, .L7F06F20C
/* 0A3D54 7F06F224 8E02000C */   lw    $v0, 0xc($s0)
.L7F06F228:
/* 0A3D58 7F06F228 5600FFB5 */  bnezl $s0, .L7F06F100
/* 0A3D5C 7F06F22C 96020000 */   lhu   $v0, ($s0)
/* 0A3D60 7F06F230 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F06F234:
/* 0A3D64 7F06F234 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A3D68 7F06F238 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A3D6C 7F06F23C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A3D70 7F06F240 03E00008 */  jr    $ra
/* 0A3D74 7F06F244 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void instcalcmatrices(void) {

}
#else
GLOBAL_ASM(
.text
glabel instcalcmatrices
/* 0A3D78 7F06F248 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A3D7C 7F06F24C AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3D80 7F06F250 00808025 */  move  $s0, $a0
/* 0A3D84 7F06F254 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3D88 7F06F258 14A00006 */  bnez  $a1, .L7F06F274
/* 0A3D8C 7F06F25C AFA50024 */   sw    $a1, 0x24($sp)
/* 0A3D90 7F06F260 3C048005 */  lui   $a0, %hi(aInstcalcmatricesNoObjinst)
/* 0A3D94 7F06F264 0C0033D1 */  jal   osSyncPrintf
/* 0A3D98 7F06F268 24844890 */   addiu $a0, %lo(aInstcalcmatricesNoObjinst) # addiu $a0, $a0, 0x4890
/* 0A3D9C 7F06F26C 0FC1B11B */  jal   return_null
/* 0A3DA0 7F06F270 00000000 */   nop   
.L7F06F274:
/* 0A3DA4 7F06F274 8E0F0000 */  lw    $t7, ($s0)
/* 0A3DA8 7F06F278 3C048005 */  lui   $a0, %hi(aInstcalcmatricesNoBasemtx)
/* 0A3DAC 7F06F27C 55E00006 */  bnezl $t7, .L7F06F298
/* 0A3DB0 7F06F280 8E020010 */   lw    $v0, 0x10($s0)
/* 0A3DB4 7F06F284 0C0033D1 */  jal   osSyncPrintf
/* 0A3DB8 7F06F288 248448B0 */   addiu $a0, %lo(aInstcalcmatricesNoBasemtx) # addiu $a0, $a0, 0x48b0
/* 0A3DBC 7F06F28C 0FC1B11B */  jal   return_null
/* 0A3DC0 7F06F290 00000000 */   nop   
/* 0A3DC4 7F06F294 8E020010 */  lw    $v0, 0x10($s0)
.L7F06F298:
/* 0A3DC8 7F06F298 3C048005 */  lui   $a0, %hi(aInstcalcmatricesNoMtxlist)
/* 0A3DCC 7F06F29C 54400007 */  bnezl $v0, .L7F06F2BC
/* 0A3DD0 7F06F2A0 8FB80024 */   lw    $t8, 0x24($sp)
/* 0A3DD4 7F06F2A4 0C0033D1 */  jal   osSyncPrintf
/* 0A3DD8 7F06F2A8 248448D0 */   addiu $a0, %lo(aInstcalcmatricesNoMtxlist) # addiu $a0, $a0, 0x48d0
/* 0A3DDC 7F06F2AC 0FC1B11B */  jal   return_null
/* 0A3DE0 7F06F2B0 00000000 */   nop   
/* 0A3DE4 7F06F2B4 8E020010 */  lw    $v0, 0x10($s0)
/* 0A3DE8 7F06F2B8 8FB80024 */  lw    $t8, 0x24($sp)
.L7F06F2BC:
/* 0A3DEC 7F06F2BC 02002025 */  move  $a0, $s0
/* 0A3DF0 7F06F2C0 8F080008 */  lw    $t0, 8($t8)
/* 0A3DF4 7F06F2C4 AF02000C */  sw    $v0, 0xc($t8)
/* 0A3DF8 7F06F2C8 8E190010 */  lw    $t9, 0x10($s0)
/* 0A3DFC 7F06F2CC 8509000E */  lh    $t1, 0xe($t0)
/* 0A3E00 7F06F2D0 00095180 */  sll   $t2, $t1, 6
/* 0A3E04 7F06F2D4 032A5821 */  addu  $t3, $t9, $t2
/* 0A3E08 7F06F2D8 AE0B0010 */  sw    $t3, 0x10($s0)
/* 0A3E0C 7F06F2DC 0FC1BC34 */  jal   sub_GAME_7F06F0D0
/* 0A3E10 7F06F2E0 8FA50024 */   lw    $a1, 0x24($sp)
/* 0A3E14 7F06F2E4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A3E18 7F06F2E8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A3E1C 7F06F2EC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A3E20 7F06F2F0 03E00008 */  jr    $ra
/* 0A3E24 7F06F2F4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void subcalcmatrices(void) {

}
#else
GLOBAL_ASM(
.text
glabel subcalcmatrices
/* 0A3E28 7F06F2F8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A3E2C 7F06F2FC AFB00018 */  sw    $s0, 0x18($sp)
/* 0A3E30 7F06F300 00A08025 */  move  $s0, $a1
/* 0A3E34 7F06F304 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A3E38 7F06F308 14A00006 */  bnez  $a1, .L7F06F324
/* 0A3E3C 7F06F30C AFA40020 */   sw    $a0, 0x20($sp)
/* 0A3E40 7F06F310 3C048005 */  lui   $a0, %hi(aSubcalcmatricesNoObjanim)
/* 0A3E44 7F06F314 0C0033D1 */  jal   osSyncPrintf
/* 0A3E48 7F06F318 248448F0 */   addiu $a0, %lo(aSubcalcmatricesNoObjanim) # addiu $a0, $a0, 0x48f0
/* 0A3E4C 7F06F31C 0FC1B11B */  jal   return_null
/* 0A3E50 7F06F320 00000000 */   nop   
.L7F06F324:
/* 0A3E54 7F06F324 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0A3E58 7F06F328 3C048005 */  lui   $a0, %hi(aSubcalcmatricesNoBasemtx)
/* 0A3E5C 7F06F32C 8DCF0000 */  lw    $t7, ($t6)
/* 0A3E60 7F06F330 55E00006 */  bnezl $t7, .L7F06F34C
/* 0A3E64 7F06F334 8FB80020 */   lw    $t8, 0x20($sp)
/* 0A3E68 7F06F338 0C0033D1 */  jal   osSyncPrintf
/* 0A3E6C 7F06F33C 24844910 */   addiu $a0, %lo(aSubcalcmatricesNoBasemtx) # addiu $a0, $a0, 0x4910
/* 0A3E70 7F06F340 0FC1B11B */  jal   return_null
/* 0A3E74 7F06F344 00000000 */   nop   
/* 0A3E78 7F06F348 8FB80020 */  lw    $t8, 0x20($sp)
.L7F06F34C:
/* 0A3E7C 7F06F34C 3C048005 */  lui   $a0, %hi(aSubcalcmatricesNoMtxlist)
/* 0A3E80 7F06F350 8F190010 */  lw    $t9, 0x10($t8)
/* 0A3E84 7F06F354 57200006 */  bnezl $t9, .L7F06F370
/* 0A3E88 7F06F358 8E080020 */   lw    $t0, 0x20($s0)
/* 0A3E8C 7F06F35C 0C0033D1 */  jal   osSyncPrintf
/* 0A3E90 7F06F360 24844930 */   addiu $a0, %lo(aSubcalcmatricesNoMtxlist) # addiu $a0, $a0, 0x4930
/* 0A3E94 7F06F364 0FC1B11B */  jal   return_null
/* 0A3E98 7F06F368 00000000 */   nop   
/* 0A3E9C 7F06F36C 8E080020 */  lw    $t0, 0x20($s0)
.L7F06F370:
/* 0A3EA0 7F06F370 51000087 */  beql  $t0, $zero, .L7F06F590
/* 0A3EA4 7F06F374 8FA40020 */   lw    $a0, 0x20($sp)
/* 0A3EA8 7F06F378 8E090018 */  lw    $t1, 0x18($s0)
/* 0A3EAC 7F06F37C 5120000A */  beql  $t1, $zero, .L7F06F3A8
/* 0A3EB0 7F06F380 86050030 */   lh    $a1, 0x30($s0)
/* 0A3EB4 7F06F384 8E0A001C */  lw    $t2, 0x1c($s0)
/* 0A3EB8 7F06F388 3C048005 */  lui   $a0, %hi(aSubcalcmatricesNoAttachForObjinst)
/* 0A3EBC 7F06F38C 55400006 */  bnezl $t2, .L7F06F3A8
/* 0A3EC0 7F06F390 86050030 */   lh    $a1, 0x30($s0)
/* 0A3EC4 7F06F394 0C0033D1 */  jal   osSyncPrintf
/* 0A3EC8 7F06F398 24844950 */   addiu $a0, %lo(aSubcalcmatricesNoAttachForObjinst) # addiu $a0, $a0, 0x4950
/* 0A3ECC 7F06F39C 0FC1B11B */  jal   return_null
/* 0A3ED0 7F06F3A0 00000000 */   nop   
/* 0A3ED4 7F06F3A4 86050030 */  lh    $a1, 0x30($s0)
.L7F06F3A8:
/* 0A3ED8 7F06F3A8 3C048005 */  lui   $a0, %hi(aSubcalcmatricesFrameaOutOfRange)
/* 0A3EDC 7F06F3AC 04A00006 */  bltz  $a1, .L7F06F3C8
/* 0A3EE0 7F06F3B0 00000000 */   nop   
/* 0A3EE4 7F06F3B4 8E0B0020 */  lw    $t3, 0x20($s0)
/* 0A3EE8 7F06F3B8 956C0004 */  lhu   $t4, 4($t3)
/* 0A3EEC 7F06F3BC 00AC082A */  slt   $at, $a1, $t4
/* 0A3EF0 7F06F3C0 54200006 */  bnezl $at, .L7F06F3DC
/* 0A3EF4 7F06F3C4 86020032 */   lh    $v0, 0x32($s0)
.L7F06F3C8:
/* 0A3EF8 7F06F3C8 0C0033D1 */  jal   osSyncPrintf
/* 0A3EFC 7F06F3CC 2484497C */   addiu $a0, %lo(aSubcalcmatricesFrameaOutOfRange) # addiu $a0, $a0, 0x497c
/* 0A3F00 7F06F3D0 0FC1B11B */  jal   return_null
/* 0A3F04 7F06F3D4 00000000 */   nop   
/* 0A3F08 7F06F3D8 86020032 */  lh    $v0, 0x32($s0)
.L7F06F3DC:
/* 0A3F0C 7F06F3DC 3C048005 */  lui   $a0, %hi(aSubcalcmatricesFramebOutOfRange)
/* 0A3F10 7F06F3E0 04400006 */  bltz  $v0, .L7F06F3FC
/* 0A3F14 7F06F3E4 00000000 */   nop   
/* 0A3F18 7F06F3E8 8E0D0020 */  lw    $t5, 0x20($s0)
/* 0A3F1C 7F06F3EC 95AE0004 */  lhu   $t6, 4($t5)
/* 0A3F20 7F06F3F0 004E082A */  slt   $at, $v0, $t6
/* 0A3F24 7F06F3F4 54200006 */  bnezl $at, .L7F06F410
/* 0A3F28 7F06F3F8 44801000 */   mtc1  $zero, $f2
.L7F06F3FC:
/* 0A3F2C 7F06F3FC 0C0033D1 */  jal   osSyncPrintf
/* 0A3F30 7F06F400 248449A4 */   addiu $a0, %lo(aSubcalcmatricesFramebOutOfRange) # addiu $a0, $a0, 0x49a4
/* 0A3F34 7F06F404 0FC1B11B */  jal   return_null
/* 0A3F38 7F06F408 00000000 */   nop   
/* 0A3F3C 7F06F40C 44801000 */  mtc1  $zero, $f2
.L7F06F410:
/* 0A3F40 7F06F410 C6000084 */  lwc1  $f0, 0x84($s0)
/* 0A3F44 7F06F414 46001032 */  c.eq.s $f2, $f0
/* 0A3F48 7F06F418 00000000 */  nop   
/* 0A3F4C 7F06F41C 45010008 */  bc1t  .L7F06F440
/* 0A3F50 7F06F420 00000000 */   nop   
/* 0A3F54 7F06F424 46001032 */  c.eq.s $f2, $f0
/* 0A3F58 7F06F428 3C048005 */  lui   $a0, %hi(aSubcalcmatricesNoAnim2)
/* 0A3F5C 7F06F42C 45010006 */  bc1t  .L7F06F448
/* 0A3F60 7F06F430 00000000 */   nop   
/* 0A3F64 7F06F434 8E0F0054 */  lw    $t7, 0x54($s0)
/* 0A3F68 7F06F438 11E00003 */  beqz  $t7, .L7F06F448
/* 0A3F6C 7F06F43C 00000000 */   nop   
.L7F06F440:
/* 0A3F70 7F06F440 10000006 */  b     .L7F06F45C
/* 0A3F74 7F06F444 8E040054 */   lw    $a0, 0x54($s0)
.L7F06F448:
/* 0A3F78 7F06F448 0C0033D1 */  jal   osSyncPrintf
/* 0A3F7C 7F06F44C 248449CC */   addiu $a0, $a0, %lo(aSubcalcmatricesNoAnim2)
/* 0A3F80 7F06F450 0FC1B11B */  jal   return_null
/* 0A3F84 7F06F454 00000000 */   nop   
/* 0A3F88 7F06F458 8E040054 */  lw    $a0, 0x54($s0)
.L7F06F45C:
/* 0A3F8C 7F06F45C 10800010 */  beqz  $a0, .L7F06F4A0
/* 0A3F90 7F06F460 00000000 */   nop   
/* 0A3F94 7F06F464 10800008 */  beqz  $a0, .L7F06F488
/* 0A3F98 7F06F468 00000000 */   nop   
/* 0A3F9C 7F06F46C 86020060 */  lh    $v0, 0x60($s0)
/* 0A3FA0 7F06F470 04400005 */  bltz  $v0, .L7F06F488
/* 0A3FA4 7F06F474 00000000 */   nop   
/* 0A3FA8 7F06F478 94980004 */  lhu   $t8, 4($a0)
/* 0A3FAC 7F06F47C 0058082A */  slt   $at, $v0, $t8
/* 0A3FB0 7F06F480 14200007 */  bnez  $at, .L7F06F4A0
/* 0A3FB4 7F06F484 00000000 */   nop   
.L7F06F488:
/* 0A3FB8 7F06F488 3C048005 */  lui   $a0, %hi(aSubcalcmatricesFrame2aOutOfRange)
/* 0A3FBC 7F06F48C 0C0033D1 */  jal   osSyncPrintf
/* 0A3FC0 7F06F490 248449E8 */   addiu $a0, %lo(aSubcalcmatricesFrame2aOutOfRange) # addiu $a0, $a0, 0x49e8
/* 0A3FC4 7F06F494 0FC1B11B */  jal   return_null
/* 0A3FC8 7F06F498 00000000 */   nop   
/* 0A3FCC 7F06F49C 8E040054 */  lw    $a0, 0x54($s0)
.L7F06F4A0:
/* 0A3FD0 7F06F4A0 5080000B */  beql  $a0, $zero, .L7F06F4D0
/* 0A3FD4 7F06F4A4 8E040020 */   lw    $a0, 0x20($s0)
/* 0A3FD8 7F06F4A8 1080000B */  beqz  $a0, .L7F06F4D8
/* 0A3FDC 7F06F4AC 00000000 */   nop   
/* 0A3FE0 7F06F4B0 86020062 */  lh    $v0, 0x62($s0)
/* 0A3FE4 7F06F4B4 04400008 */  bltz  $v0, .L7F06F4D8
/* 0A3FE8 7F06F4B8 00000000 */   nop   
/* 0A3FEC 7F06F4BC 94990004 */  lhu   $t9, 4($a0)
/* 0A3FF0 7F06F4C0 0059082A */  slt   $at, $v0, $t9
/* 0A3FF4 7F06F4C4 10200004 */  beqz  $at, .L7F06F4D8
/* 0A3FF8 7F06F4C8 00000000 */   nop   
/* 0A3FFC 7F06F4CC 8E040020 */  lw    $a0, 0x20($s0)
.L7F06F4D0:
/* 0A4000 7F06F4D0 10000008 */  b     .L7F06F4F4
/* 0A4004 7F06F4D4 86050030 */   lh    $a1, 0x30($s0)
.L7F06F4D8:
/* 0A4008 7F06F4D8 3C048005 */  lui   $a0, %hi(aSubcalcmatricesFrame2bOutOfRange)
/* 0A400C 7F06F4DC 0C0033D1 */  jal   osSyncPrintf
/* 0A4010 7F06F4E0 24844A10 */   addiu $a0, %lo(aSubcalcmatricesFrame2bOutOfRange) # addiu $a0, $a0, 0x4a10
/* 0A4014 7F06F4E4 0FC1B11B */  jal   return_null
/* 0A4018 7F06F4E8 00000000 */   nop   
/* 0A401C 7F06F4EC 8E040020 */  lw    $a0, 0x20($s0)
/* 0A4020 7F06F4F0 86050030 */  lh    $a1, 0x30($s0)
.L7F06F4F4:
/* 0A4024 7F06F4F4 8E080008 */  lw    $t0, 8($s0)
/* 0A4028 7F06F4F8 0FC1D52F */  jal   sub_GAME_7F0754BC
/* 0A402C 7F06F4FC 8D060004 */   lw    $a2, 4($t0)
/* 0A4030 7F06F500 44802000 */  mtc1  $zero, $f4
/* 0A4034 7F06F504 C606002C */  lwc1  $f6, 0x2c($s0)
/* 0A4038 7F06F508 AE020034 */  sw    $v0, 0x34($s0)
/* 0A403C 7F06F50C 46062032 */  c.eq.s $f4, $f6
/* 0A4040 7F06F510 00000000 */  nop   
/* 0A4044 7F06F514 45030008 */  bc1tl .L7F06F538
/* 0A4048 7F06F518 8E040054 */   lw    $a0, 0x54($s0)
/* 0A404C 7F06F51C 8E090008 */  lw    $t1, 8($s0)
/* 0A4050 7F06F520 8E040020 */  lw    $a0, 0x20($s0)
/* 0A4054 7F06F524 86050032 */  lh    $a1, 0x32($s0)
/* 0A4058 7F06F528 0FC1D52F */  jal   sub_GAME_7F0754BC
/* 0A405C 7F06F52C 8D260004 */   lw    $a2, 4($t1)
/* 0A4060 7F06F530 AE020038 */  sw    $v0, 0x38($s0)
/* 0A4064 7F06F534 8E040054 */  lw    $a0, 0x54($s0)
.L7F06F538:
/* 0A4068 7F06F538 10800012 */  beqz  $a0, .L7F06F584
/* 0A406C 7F06F53C 00000000 */   nop   
/* 0A4070 7F06F540 8E0A0008 */  lw    $t2, 8($s0)
/* 0A4074 7F06F544 86050060 */  lh    $a1, 0x60($s0)
/* 0A4078 7F06F548 0FC1D52F */  jal   sub_GAME_7F0754BC
/* 0A407C 7F06F54C 8D460004 */   lw    $a2, 4($t2)
/* 0A4080 7F06F550 44804000 */  mtc1  $zero, $f8
/* 0A4084 7F06F554 C60A005C */  lwc1  $f10, 0x5c($s0)
/* 0A4088 7F06F558 AE020064 */  sw    $v0, 0x64($s0)
/* 0A408C 7F06F55C 460A4032 */  c.eq.s $f8, $f10
/* 0A4090 7F06F560 00000000 */  nop   
/* 0A4094 7F06F564 45010007 */  bc1t  .L7F06F584
/* 0A4098 7F06F568 00000000 */   nop   
/* 0A409C 7F06F56C 8E0B0008 */  lw    $t3, 8($s0)
/* 0A40A0 7F06F570 8E040054 */  lw    $a0, 0x54($s0)
/* 0A40A4 7F06F574 86050062 */  lh    $a1, 0x62($s0)
/* 0A40A8 7F06F578 0FC1D52F */  jal   sub_GAME_7F0754BC
/* 0A40AC 7F06F57C 8D660004 */   lw    $a2, 4($t3)
/* 0A40B0 7F06F580 AE020068 */  sw    $v0, 0x68($s0)
.L7F06F584:
/* 0A40B4 7F06F584 0FC1D56C */  jal   sub_GAME_7F0755B0
/* 0A40B8 7F06F588 00000000 */   nop   
/* 0A40BC 7F06F58C 8FA40020 */  lw    $a0, 0x20($sp)
.L7F06F590:
/* 0A40C0 7F06F590 0FC1BC92 */  jal   instcalcmatrices
/* 0A40C4 7F06F594 02002825 */   move  $a1, $s0
/* 0A40C8 7F06F598 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A40CC 7F06F59C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A40D0 7F06F5A0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A40D4 7F06F5A4 03E00008 */  jr    $ra
/* 0A40D8 7F06F5A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F5AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F5AC
/* 0A40DC 7F06F5AC 03E00008 */  jr    $ra
/* 0A40E0 7F06F5B0 8C820020 */   lw    $v0, 0x20($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F5B4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F5B4
/* 0A40E4 7F06F5B4 03E00008 */  jr    $ra
/* 0A40E8 7F06F5B8 80820024 */   lb    $v0, 0x24($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F5BC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F5BC
/* 0A40EC 7F06F5BC 03E00008 */  jr    $ra
/* 0A40F0 7F06F5C0 C4800028 */   lwc1  $f0, 0x28($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F5C4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F5C4
/* 0A40F4 7F06F5C4 44806000 */  mtc1  $zero, $f12
/* 0A40F8 7F06F5C8 C482003C */  lwc1  $f2, 0x3c($a0)
/* 0A40FC 7F06F5CC 4602603E */  c.le.s $f12, $f2
/* 0A4100 7F06F5D0 00000000 */  nop   
/* 0A4104 7F06F5D4 45020004 */  bc1fl .L7F06F5E8
/* 0A4108 7F06F5D8 8C820020 */   lw    $v0, 0x20($a0)
/* 0A410C 7F06F5DC 03E00008 */  jr    $ra
/* 0A4110 7F06F5E0 46001006 */   mov.s $f0, $f2

/* 0A4114 7F06F5E4 8C820020 */  lw    $v0, 0x20($a0)
.L7F06F5E8:
/* 0A4118 7F06F5E8 50400007 */  beql  $v0, $zero, .L7F06F608
/* 0A411C 7F06F5EC 46006006 */   mov.s $f0, $f12
/* 0A4120 7F06F5F0 944E0004 */  lhu   $t6, 4($v0)
/* 0A4124 7F06F5F4 25CFFFFF */  addiu $t7, $t6, -1
/* 0A4128 7F06F5F8 448F2000 */  mtc1  $t7, $f4
/* 0A412C 7F06F5FC 03E00008 */  jr    $ra
/* 0A4130 7F06F600 46802020 */   cvt.s.w $f0, $f4

/* 0A4134 7F06F604 46006006 */  mov.s $f0, $f12
.L7F06F608:
/* 0A4138 7F06F608 03E00008 */  jr    $ra
/* 0A413C 7F06F60C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F610(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F610
/* 0A4140 7F06F610 03E00008 */  jr    $ra
/* 0A4144 7F06F614 C4800040 */   lwc1  $f0, 0x40($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F618(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F618
/* 0A4148 7F06F618 C4820040 */  lwc1  $f2, 0x40($a0)
/* 0A414C 7F06F61C 44802000 */  mtc1  $zero, $f4
/* 0A4150 7F06F620 00000000 */  nop   
/* 0A4154 7F06F624 4604103C */  c.lt.s $f2, $f4
/* 0A4158 7F06F628 00000000 */  nop   
/* 0A415C 7F06F62C 45000002 */  bc1f  .L7F06F638
/* 0A4160 7F06F630 00000000 */   nop   
/* 0A4164 7F06F634 46001087 */  neg.s $f2, $f2
.L7F06F638:
/* 0A4168 7F06F638 03E00008 */  jr    $ra
/* 0A416C 7F06F63C 46001006 */   mov.s $f0, $f2
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F640(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F640
/* 0A4170 7F06F640 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A4174 7F06F644 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A4178 7F06F648 0FC1BD84 */  jal   sub_GAME_7F06F610
/* 0A417C 7F06F64C AFA40018 */   sw    $a0, 0x18($sp)
/* 0A4180 7F06F650 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0A4184 7F06F654 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A4188 7F06F658 C5C400A4 */  lwc1  $f4, 0xa4($t6)
/* 0A418C 7F06F65C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A4190 7F06F660 46040002 */  mul.s $f0, $f0, $f4
/* 0A4194 7F06F664 03E00008 */  jr    $ra
/* 0A4198 7F06F668 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06F66C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F66C
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
/* 0A4234 7F06F704 0FC1712E */  jal   sub_GAME_7F05C4B8
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
void sub_GAME_7F06F780(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06F780
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
/* 0A4350 7F06F820 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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
void sub_GAME_7F06F878(void) {

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
glabel sub_GAME_7F06F878
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
/* 0A4434 7F06F904 0FC1BFD9 */  jal   sub_GAME_7F06FF64
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
/* 0A4464 7F06F934 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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





#ifdef NONMATCHING
void sub_GAME_7F06FC4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FC4C
/* 0A477C 7F06FC4C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A4780 7F06FC50 8FAE0038 */  lw    $t6, 0x38($sp)
/* 0A4784 7F06FC54 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A4788 7F06FC58 AFA40020 */  sw    $a0, 0x20($sp)
/* 0A478C 7F06FC5C AFA50024 */  sw    $a1, 0x24($sp)
/* 0A4790 7F06FC60 AFA60028 */  sw    $a2, 0x28($sp)
/* 0A4794 7F06FC64 11C00003 */  beqz  $t6, .L7F06FC74
/* 0A4798 7F06FC68 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0A479C 7F06FC6C 0FC1BDE0 */  jal   sub_GAME_7F06F780
/* 0A47A0 7F06FC70 8FA50034 */   lw    $a1, 0x34($sp)
.L7F06FC74:
/* 0A47A4 7F06FC74 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0A47A8 7F06FC78 C7A60034 */  lwc1  $f6, 0x34($sp)
/* 0A47AC 7F06FC7C 8FA40020 */  lw    $a0, 0x20($sp)
/* 0A47B0 7F06FC80 8FA50024 */  lw    $a1, 0x24($sp)
/* 0A47B4 7F06FC84 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A47B8 7F06FC88 8FA7002C */  lw    $a3, 0x2c($sp)
/* 0A47BC 7F06FC8C E7A40010 */  swc1  $f4, 0x10($sp)
/* 0A47C0 7F06FC90 0FC1BE1E */  jal   sub_GAME_7F06F878
/* 0A47C4 7F06FC94 E7A60014 */   swc1  $f6, 0x14($sp)
/* 0A47C8 7F06FC98 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A47CC 7F06FC9C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A47D0 7F06FCA0 03E00008 */  jr    $ra
/* 0A47D4 7F06FCA4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FCA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FCA8
/* 0A47D8 7F06FCA8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A47DC 7F06FCAC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A47E0 7F06FCB0 AFA50024 */  sw    $a1, 0x24($sp)
/* 0A47E4 7F06FCB4 AFA40020 */  sw    $a0, 0x20($sp)
/* 0A47E8 7F06FCB8 AFA60028 */  sw    $a2, 0x28($sp)
/* 0A47EC 7F06FCBC AFA7002C */  sw    $a3, 0x2c($sp)
/* 0A47F0 7F06FCC0 0FC1BDE0 */  jal   sub_GAME_7F06F780
/* 0A47F4 7F06FCC4 8FA50034 */   lw    $a1, 0x34($sp)
/* 0A47F8 7F06FCC8 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0A47FC 7F06FCCC C7A60034 */  lwc1  $f6, 0x34($sp)
/* 0A4800 7F06FCD0 8FA40020 */  lw    $a0, 0x20($sp)
/* 0A4804 7F06FCD4 8FA50024 */  lw    $a1, 0x24($sp)
/* 0A4808 7F06FCD8 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A480C 7F06FCDC 8FA7002C */  lw    $a3, 0x2c($sp)
/* 0A4810 7F06FCE0 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0A4814 7F06FCE4 0FC1BE1E */  jal   sub_GAME_7F06F878
/* 0A4818 7F06FCE8 E7A60014 */   swc1  $f6, 0x14($sp)
/* 0A481C 7F06FCEC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A4820 7F06FCF0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A4824 7F06FCF4 03E00008 */  jr    $ra
/* 0A4828 7F06FCF8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FCFC(void) {

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





#ifdef NONMATCHING
void sub_GAME_7F06FDCC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FDCC
/* 0A48FC 7F06FDCC 44856000 */  mtc1  $a1, $f12
/* 0A4900 7F06FDD0 44867000 */  mtc1  $a2, $f14
/* 0A4904 7F06FDD4 240E0001 */  li    $t6, 1
/* 0A4908 7F06FDD8 A08E0026 */  sb    $t6, 0x26($a0)
/* 0A490C 7F06FDDC E48C0090 */  swc1  $f12, 0x90($a0)
/* 0A4910 7F06FDE0 03E00008 */  jr    $ra
/* 0A4914 7F06FDE4 E48E0094 */   swc1  $f14, 0x94($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FDE8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FDE8
/* 0A4918 7F06FDE8 8C820020 */  lw    $v0, 0x20($a0)
/* 0A491C 7F06FDEC 44856000 */  mtc1  $a1, $f12
/* 0A4920 7F06FDF0 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0A4924 7F06FDF4 5040000D */  beql  $v0, $zero, .L7F06FE2C
/* 0A4928 7F06FDF8 44814000 */   mtc1  $at, $f8
/* 0A492C 7F06FDFC 944E0004 */  lhu   $t6, 4($v0)
/* 0A4930 7F06FE00 25CFFFFF */  addiu $t7, $t6, -1
/* 0A4934 7F06FE04 448F2000 */  mtc1  $t7, $f4
/* 0A4938 7F06FE08 00000000 */  nop   
/* 0A493C 7F06FE0C 468021A0 */  cvt.s.w $f6, $f4
/* 0A4940 7F06FE10 4606603C */  c.lt.s $f12, $f6
/* 0A4944 7F06FE14 00000000 */  nop   
/* 0A4948 7F06FE18 45020004 */  bc1fl .L7F06FE2C
/* 0A494C 7F06FE1C 44814000 */   mtc1  $at, $f8
/* 0A4950 7F06FE20 03E00008 */  jr    $ra
/* 0A4954 7F06FE24 E48C003C */   swc1  $f12, 0x3c($a0)

/* 0A4958 7F06FE28 44814000 */  mtc1  $at, $f8
.L7F06FE2C:
/* 0A495C 7F06FE2C 00000000 */  nop   
/* 0A4960 7F06FE30 E488003C */  swc1  $f8, 0x3c($a0)
/* 0A4964 7F06FE34 03E00008 */  jr    $ra
/* 0A4968 7F06FE38 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FE3C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FE3C
/* 0A496C 7F06FE3C 03E00008 */  jr    $ra
/* 0A4970 7F06FE40 AC850098 */   sw    $a1, 0x98($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FE44(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FE44
/* 0A4974 7F06FE44 03E00008 */  jr    $ra
/* 0A4978 7F06FE48 AC85009C */   sw    $a1, 0x9c($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FE4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FE4C
/* 0A497C 7F06FE4C 44866000 */  mtc1  $a2, $f12
/* 0A4980 7F06FE50 44800000 */  mtc1  $zero, $f0
/* 0A4984 7F06FE54 44857000 */  mtc1  $a1, $f14
/* 0A4988 7F06FE58 460C003C */  c.lt.s $f0, $f12
/* 0A498C 7F06FE5C 00000000 */  nop   
/* 0A4990 7F06FE60 45020008 */  bc1fl .L7F06FE84
/* 0A4994 7F06FE64 E48E0040 */   swc1  $f14, 0x40($a0)
/* 0A4998 7F06FE68 C4840040 */  lwc1  $f4, 0x40($a0)
/* 0A499C 7F06FE6C E48C004C */  swc1  $f12, 0x4c($a0)
/* 0A49A0 7F06FE70 E48E0044 */  swc1  $f14, 0x44($a0)
/* 0A49A4 7F06FE74 E4800050 */  swc1  $f0, 0x50($a0)
/* 0A49A8 7F06FE78 03E00008 */  jr    $ra
/* 0A49AC 7F06FE7C E4840048 */   swc1  $f4, 0x48($a0)

/* 0A49B0 7F06FE80 E48E0040 */  swc1  $f14, 0x40($a0)
.L7F06FE84:
/* 0A49B4 7F06FE84 E480004C */  swc1  $f0, 0x4c($a0)
/* 0A49B8 7F06FE88 03E00008 */  jr    $ra
/* 0A49BC 7F06FE8C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FE90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FE90
/* 0A49C0 7F06FE90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A49C4 7F06FE94 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A49C8 7F06FE98 44856000 */  mtc1  $a1, $f12
/* 0A49CC 7F06FE9C C4800028 */  lwc1  $f0, 0x28($a0)
/* 0A49D0 7F06FEA0 44867000 */  mtc1  $a2, $f14
/* 0A49D4 7F06FEA4 460C003E */  c.le.s $f0, $f12
/* 0A49D8 7F06FEA8 00000000 */  nop   
/* 0A49DC 7F06FEAC 45020004 */  bc1fl .L7F06FEC0
/* 0A49E0 7F06FEB0 8C8E0020 */   lw    $t6, 0x20($a0)
/* 0A49E4 7F06FEB4 1000000C */  b     .L7F06FEE8
/* 0A49E8 7F06FEB8 46006081 */   sub.s $f2, $f12, $f0
/* 0A49EC 7F06FEBC 8C8E0020 */  lw    $t6, 0x20($a0)
.L7F06FEC0:
/* 0A49F0 7F06FEC0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A49F4 7F06FEC4 95CF0004 */  lhu   $t7, 4($t6)
/* 0A49F8 7F06FEC8 448F2000 */  mtc1  $t7, $f4
/* 0A49FC 7F06FECC 05E10004 */  bgez  $t7, .L7F06FEE0
/* 0A4A00 7F06FED0 468021A0 */   cvt.s.w $f6, $f4
/* 0A4A04 7F06FED4 44814000 */  mtc1  $at, $f8
/* 0A4A08 7F06FED8 00000000 */  nop   
/* 0A4A0C 7F06FEDC 46083180 */  add.s $f6, $f6, $f8
.L7F06FEE0:
/* 0A4A10 7F06FEE0 46003281 */  sub.s $f10, $f6, $f0
/* 0A4A14 7F06FEE4 460C5080 */  add.s $f2, $f10, $f12
.L7F06FEE8:
/* 0A4A18 7F06FEE8 46021480 */  add.s $f18, $f2, $f2
/* 0A4A1C 7F06FEEC C4900040 */  lwc1  $f16, 0x40($a0)
/* 0A4A20 7F06FEF0 44067000 */  mfc1  $a2, $f14
/* 0A4A24 7F06FEF4 460E9103 */  div.s $f4, $f18, $f14
/* 0A4A28 7F06FEF8 46048000 */  add.s $f0, $f16, $f4
/* 0A4A2C 7F06FEFC 44050000 */  mfc1  $a1, $f0
/* 0A4A30 7F06FF00 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 0A4A34 7F06FF04 00000000 */   nop   
/* 0A4A38 7F06FF08 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A4A3C 7F06FF0C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A4A40 7F06FF10 03E00008 */  jr    $ra
/* 0A4A44 7F06FF14 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FF18(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FF18
/* 0A4A48 7F06FF18 44866000 */  mtc1  $a2, $f12
/* 0A4A4C 7F06FF1C 44800000 */  mtc1  $zero, $f0
/* 0A4A50 7F06FF20 44857000 */  mtc1  $a1, $f14
/* 0A4A54 7F06FF24 460C003C */  c.lt.s $f0, $f12
/* 0A4A58 7F06FF28 00000000 */  nop   
/* 0A4A5C 7F06FF2C 45020008 */  bc1fl .L7F06FF50
/* 0A4A60 7F06FF30 E48E00A4 */   swc1  $f14, 0xa4($a0)
/* 0A4A64 7F06FF34 C48400A4 */  lwc1  $f4, 0xa4($a0)
/* 0A4A68 7F06FF38 E48C00B0 */  swc1  $f12, 0xb0($a0)
/* 0A4A6C 7F06FF3C E48E00A8 */  swc1  $f14, 0xa8($a0)
/* 0A4A70 7F06FF40 E48000B4 */  swc1  $f0, 0xb4($a0)
/* 0A4A74 7F06FF44 03E00008 */  jr    $ra
/* 0A4A78 7F06FF48 E48400AC */   swc1  $f4, 0xac($a0)

/* 0A4A7C 7F06FF4C E48E00A4 */  swc1  $f14, 0xa4($a0)
.L7F06FF50:
/* 0A4A80 7F06FF50 E48000B0 */  swc1  $f0, 0xb0($a0)
/* 0A4A84 7F06FF54 03E00008 */  jr    $ra
/* 0A4A88 7F06FF58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FF5C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FF5C
/* 0A4A8C 7F06FF5C 03E00008 */  jr    $ra
/* 0A4A90 7F06FF60 AC8500A0 */   sw    $a1, 0xa0($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06FF64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06FF64
/* 0A4A94 7F06FF64 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A4A98 7F06FF68 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A4A9C 7F06FF6C AFB00018 */  sw    $s0, 0x18($sp)
/* 0A4AA0 7F06FF70 AFA50034 */  sw    $a1, 0x34($sp)
/* 0A4AA4 7F06FF74 00808025 */  move  $s0, $a0
/* 0A4AA8 7F06FF78 0FC170F6 */  jal   sub_GAME_7F05C3D8
/* 0A4AAC 7F06FF7C C7AC0034 */   lwc1  $f12, 0x34($sp)
/* 0A4AB0 7F06FF80 C6040040 */  lwc1  $f4, 0x40($s0)
/* 0A4AB4 7F06FF84 44803000 */  mtc1  $zero, $f6
/* 0A4AB8 7F06FF88 00402025 */  move  $a0, $v0
/* 0A4ABC 7F06FF8C 00004025 */  move  $t0, $zero
/* 0A4AC0 7F06FF90 4604303E */  c.le.s $f6, $f4
/* 0A4AC4 7F06FF94 2447FFFF */  addiu $a3, $v0, -1
/* 0A4AC8 7F06FF98 45000002 */  bc1f  .L7F06FFA4
/* 0A4ACC 7F06FF9C 00000000 */   nop   
/* 0A4AD0 7F06FFA0 24080001 */  li    $t0, 1
.L7F06FFA4:
/* 0A4AD4 7F06FFA4 11000003 */  beqz  $t0, .L7F06FFB4
/* 0A4AD8 7F06FFA8 00000000 */   nop   
/* 0A4ADC 7F06FFAC 10000001 */  b     .L7F06FFB4
/* 0A4AE0 7F06FFB0 24470001 */   addiu $a3, $v0, 1
.L7F06FFB4:
/* 0A4AE4 7F06FFB4 8E050020 */  lw    $a1, 0x20($s0)
/* 0A4AE8 7F06FFB8 8E06003C */  lw    $a2, 0x3c($s0)
/* 0A4AEC 7F06FFBC AFA80024 */  sw    $t0, 0x24($sp)
/* 0A4AF0 7F06FFC0 AFA70028 */  sw    $a3, 0x28($sp)
/* 0A4AF4 7F06FFC4 0FC1BD9B */  jal   sub_GAME_7F06F66C
/* 0A4AF8 7F06FFC8 AFA4002C */   sw    $a0, 0x2c($sp)
/* 0A4AFC 7F06FFCC 8FA40028 */  lw    $a0, 0x28($sp)
/* 0A4B00 7F06FFD0 A6020030 */  sh    $v0, 0x30($s0)
/* 0A4B04 7F06FFD4 8E050020 */  lw    $a1, 0x20($s0)
/* 0A4B08 7F06FFD8 0FC1BD9B */  jal   sub_GAME_7F06F66C
/* 0A4B0C 7F06FFDC 8E06003C */   lw    $a2, 0x3c($s0)
/* 0A4B10 7F06FFE0 8FA70028 */  lw    $a3, 0x28($sp)
/* 0A4B14 7F06FFE4 8FA80024 */  lw    $t0, 0x24($sp)
/* 0A4B18 7F06FFE8 A6020032 */  sh    $v0, 0x32($s0)
/* 0A4B1C 7F06FFEC 86040032 */  lh    $a0, 0x32($s0)
/* 0A4B20 7F06FFF0 86030030 */  lh    $v1, 0x30($s0)
/* 0A4B24 7F06FFF4 14830007 */  bne   $a0, $v1, .L7F070014
/* 0A4B28 7F06FFF8 00000000 */   nop   
/* 0A4B2C 7F06FFFC 44835000 */  mtc1  $v1, $f10
/* 0A4B30 7F070000 44804000 */  mtc1  $zero, $f8
/* 0A4B34 7F070004 46805420 */  cvt.s.w $f16, $f10
/* 0A4B38 7F070008 E608002C */  swc1  $f8, 0x2c($s0)
/* 0A4B3C 7F07000C 1000001B */  b     .L7F07007C
/* 0A4B40 7F070010 E6100028 */   swc1  $f16, 0x28($s0)
.L7F070014:
/* 0A4B44 7F070014 1100000B */  beqz  $t0, .L7F070044
/* 0A4B48 7F070018 8FAE002C */   lw    $t6, 0x2c($sp)
/* 0A4B4C 7F07001C 448E2000 */  mtc1  $t6, $f4
/* 0A4B50 7F070020 44834000 */  mtc1  $v1, $f8
/* 0A4B54 7F070024 C7B20034 */  lwc1  $f18, 0x34($sp)
/* 0A4B58 7F070028 468021A0 */  cvt.s.w $f6, $f4
/* 0A4B5C 7F07002C 468042A0 */  cvt.s.w $f10, $f8
/* 0A4B60 7F070030 46069001 */  sub.s $f0, $f18, $f6
/* 0A4B64 7F070034 46005400 */  add.s $f16, $f10, $f0
/* 0A4B68 7F070038 E600002C */  swc1  $f0, 0x2c($s0)
/* 0A4B6C 7F07003C 1000000F */  b     .L7F07007C
/* 0A4B70 7F070040 E6100028 */   swc1  $f16, 0x28($s0)
.L7F070044:
/* 0A4B74 7F070044 44879000 */  mtc1  $a3, $f18
/* 0A4B78 7F070048 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 0A4B7C 7F07004C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A4B80 7F070050 468091A0 */  cvt.s.w $f6, $f18
/* 0A4B84 7F070054 44811000 */  mtc1  $at, $f2
/* 0A4B88 7F070058 44845000 */  mtc1  $a0, $f10
/* 0A4B8C 7F07005C 00000000 */  nop   
/* 0A4B90 7F070060 46805420 */  cvt.s.w $f16, $f10
/* 0A4B94 7F070064 46062201 */  sub.s $f8, $f4, $f6
/* 0A4B98 7F070068 46081001 */  sub.s $f0, $f2, $f8
/* 0A4B9C 7F07006C 46001481 */  sub.s $f18, $f2, $f0
/* 0A4BA0 7F070070 E600002C */  swc1  $f0, 0x2c($s0)
/* 0A4BA4 7F070074 46128100 */  add.s $f4, $f16, $f18
/* 0A4BA8 7F070078 E6040028 */  swc1  $f4, 0x28($s0)
.L7F07007C:
/* 0A4BAC 7F07007C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A4BB0 7F070080 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A4BB4 7F070084 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A4BB8 7F070088 03E00008 */  jr    $ra
/* 0A4BBC 7F07008C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F070090(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F070090
/* 0A4BC0 7F070090 44856000 */  mtc1  $a1, $f12
/* 0A4BC4 7F070094 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A4BC8 7F070098 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A4BCC 7F07009C AFB00018 */  sw    $s0, 0x18($sp)
/* 0A4BD0 7F0700A0 44056000 */  mfc1  $a1, $f12
/* 0A4BD4 7F0700A4 00808025 */  move  $s0, $a0
/* 0A4BD8 7F0700A8 0FC1BFD9 */  jal   sub_GAME_7F06FF64
/* 0A4BDC 7F0700AC AFA60038 */   sw    $a2, 0x38($sp)
/* 0A4BE0 7F0700B0 8E0E0054 */  lw    $t6, 0x54($s0)
/* 0A4BE4 7F0700B4 51C00043 */  beql  $t6, $zero, .L7F0701C4
/* 0A4BE8 7F0700B8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A4BEC 7F0700BC 0FC170F6 */  jal   sub_GAME_7F05C3D8
/* 0A4BF0 7F0700C0 C7AC0038 */   lwc1  $f12, 0x38($sp)
/* 0A4BF4 7F0700C4 C6040070 */  lwc1  $f4, 0x70($s0)
/* 0A4BF8 7F0700C8 44803000 */  mtc1  $zero, $f6
/* 0A4BFC 7F0700CC 00402025 */  move  $a0, $v0
/* 0A4C00 7F0700D0 00004025 */  move  $t0, $zero
/* 0A4C04 7F0700D4 4604303E */  c.le.s $f6, $f4
/* 0A4C08 7F0700D8 2447FFFF */  addiu $a3, $v0, -1
/* 0A4C0C 7F0700DC 45000002 */  bc1f  .L7F0700E8
/* 0A4C10 7F0700E0 00000000 */   nop   
/* 0A4C14 7F0700E4 24080001 */  li    $t0, 1
.L7F0700E8:
/* 0A4C18 7F0700E8 11000003 */  beqz  $t0, .L7F0700F8
/* 0A4C1C 7F0700EC 00000000 */   nop   
/* 0A4C20 7F0700F0 10000001 */  b     .L7F0700F8
/* 0A4C24 7F0700F4 24470001 */   addiu $a3, $v0, 1
.L7F0700F8:
/* 0A4C28 7F0700F8 8E050054 */  lw    $a1, 0x54($s0)
/* 0A4C2C 7F0700FC 8E06006C */  lw    $a2, 0x6c($s0)
/* 0A4C30 7F070100 AFA80024 */  sw    $t0, 0x24($sp)
/* 0A4C34 7F070104 AFA70028 */  sw    $a3, 0x28($sp)
/* 0A4C38 7F070108 0FC1BD9B */  jal   sub_GAME_7F06F66C
/* 0A4C3C 7F07010C AFA4002C */   sw    $a0, 0x2c($sp)
/* 0A4C40 7F070110 8FA40028 */  lw    $a0, 0x28($sp)
/* 0A4C44 7F070114 A6020060 */  sh    $v0, 0x60($s0)
/* 0A4C48 7F070118 8E050054 */  lw    $a1, 0x54($s0)
/* 0A4C4C 7F07011C 0FC1BD9B */  jal   sub_GAME_7F06F66C
/* 0A4C50 7F070120 8E06006C */   lw    $a2, 0x6c($s0)
/* 0A4C54 7F070124 8FA70028 */  lw    $a3, 0x28($sp)
/* 0A4C58 7F070128 8FA80024 */  lw    $t0, 0x24($sp)
/* 0A4C5C 7F07012C A6020062 */  sh    $v0, 0x62($s0)
/* 0A4C60 7F070130 86040062 */  lh    $a0, 0x62($s0)
/* 0A4C64 7F070134 86030060 */  lh    $v1, 0x60($s0)
/* 0A4C68 7F070138 14830007 */  bne   $a0, $v1, .L7F070158
/* 0A4C6C 7F07013C 00000000 */   nop   
/* 0A4C70 7F070140 44835000 */  mtc1  $v1, $f10
/* 0A4C74 7F070144 44804000 */  mtc1  $zero, $f8
/* 0A4C78 7F070148 46805420 */  cvt.s.w $f16, $f10
/* 0A4C7C 7F07014C E608005C */  swc1  $f8, 0x5c($s0)
/* 0A4C80 7F070150 1000001B */  b     .L7F0701C0
/* 0A4C84 7F070154 E6100058 */   swc1  $f16, 0x58($s0)
.L7F070158:
/* 0A4C88 7F070158 1100000B */  beqz  $t0, .L7F070188
/* 0A4C8C 7F07015C 8FAF002C */   lw    $t7, 0x2c($sp)
/* 0A4C90 7F070160 448F2000 */  mtc1  $t7, $f4
/* 0A4C94 7F070164 44834000 */  mtc1  $v1, $f8
/* 0A4C98 7F070168 C7B20038 */  lwc1  $f18, 0x38($sp)
/* 0A4C9C 7F07016C 468021A0 */  cvt.s.w $f6, $f4
/* 0A4CA0 7F070170 468042A0 */  cvt.s.w $f10, $f8
/* 0A4CA4 7F070174 46069001 */  sub.s $f0, $f18, $f6
/* 0A4CA8 7F070178 46005400 */  add.s $f16, $f10, $f0
/* 0A4CAC 7F07017C E600005C */  swc1  $f0, 0x5c($s0)
/* 0A4CB0 7F070180 1000000F */  b     .L7F0701C0
/* 0A4CB4 7F070184 E6100058 */   swc1  $f16, 0x58($s0)
.L7F070188:
/* 0A4CB8 7F070188 44879000 */  mtc1  $a3, $f18
/* 0A4CBC 7F07018C C7A40038 */  lwc1  $f4, 0x38($sp)
/* 0A4CC0 7F070190 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A4CC4 7F070194 468091A0 */  cvt.s.w $f6, $f18
/* 0A4CC8 7F070198 44811000 */  mtc1  $at, $f2
/* 0A4CCC 7F07019C 44845000 */  mtc1  $a0, $f10
/* 0A4CD0 7F0701A0 00000000 */  nop   
/* 0A4CD4 7F0701A4 46805420 */  cvt.s.w $f16, $f10
/* 0A4CD8 7F0701A8 46062201 */  sub.s $f8, $f4, $f6
/* 0A4CDC 7F0701AC 46081001 */  sub.s $f0, $f2, $f8
/* 0A4CE0 7F0701B0 46001481 */  sub.s $f18, $f2, $f0
/* 0A4CE4 7F0701B4 E600005C */  swc1  $f0, 0x5c($s0)
/* 0A4CE8 7F0701B8 46128100 */  add.s $f4, $f16, $f18
/* 0A4CEC 7F0701BC E6040058 */  swc1  $f4, 0x58($s0)
.L7F0701C0:
/* 0A4CF0 7F0701C0 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0701C4:
/* 0A4CF4 7F0701C4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A4CF8 7F0701C8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A4CFC 7F0701CC 03E00008 */  jr    $ra
/* 0A4D00 7F0701D0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0701D4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0701D4
/* 0A4D04 7F0701D4 3C018003 */  lui   $at, %hi(D_80036250)
/* 0A4D08 7F0701D8 03E00008 */  jr    $ra
/* 0A4D0C 7F0701DC AC246250 */   sw    $a0, %lo(D_80036250)($at)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0701E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0701E0
/* 0A4D10 7F0701E0 3C028003 */  lui   $v0, %hi(D_80036250)
/* 0A4D14 7F0701E4 03E00008 */  jr    $ra
/* 0A4D18 7F0701E8 8C426250 */   lw    $v0, %lo(D_80036250)($v0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0701EC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054D4C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0701EC
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
/* 0A4D78 7F070248 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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
/* 0A4E74 7F070344 0FC170F6 */  jal   sub_GAME_7F05C3D8
/* 0A4E78 7F070348 E7A00088 */   swc1  $f0, 0x88($sp)
/* 0A4E7C 7F07034C 24520001 */  addiu $s2, $v0, 1
/* 0A4E80 7F070350 0FC170F6 */  jal   sub_GAME_7F05C3D8
/* 0A4E84 7F070354 C7AC0100 */   lwc1  $f12, 0x100($sp)
/* 0A4E88 7F070358 10000008 */  b     .L7F07037C
/* 0A4E8C 7F07035C AFA200B8 */   sw    $v0, 0xb8($sp)
/* 0A4E90 7F070360 4600A306 */  mov.s $f12, $f20
.L7F070364:
/* 0A4E94 7F070364 0FC1712E */  jal   sub_GAME_7F05C4B8
/* 0A4E98 7F070368 E7A00088 */   swc1  $f0, 0x88($sp)
/* 0A4E9C 7F07036C 2452FFFF */  addiu $s2, $v0, -1
/* 0A4EA0 7F070370 0FC1712E */  jal   sub_GAME_7F05C4B8
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
/* 0A4EE8 7F0703B8 0FC1BD9B */  jal   sub_GAME_7F06F66C
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
/* 0A5064 7F070534 0FC1BD9B */  jal   sub_GAME_7F06F66C
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
/* 0A5124 7F0705F4 3C0A8003 */  lui   $t2, %hi(D_80036250) 
/* 0A5128 7F0705F8 8D4A6250 */  lw    $t2, %lo(D_80036250)($t2)
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
/* 0A5458 7F070928 0FC170F6 */  jal   sub_GAME_7F05C3D8
/* 0A545C 7F07092C C7AC0104 */   lwc1  $f12, 0x104($sp)
/* 0A5460 7F070930 C7B40108 */  lwc1  $f20, 0x108($sp)
/* 0A5464 7F070934 00409025 */  move  $s2, $v0
/* 0A5468 7F070938 0FC170F6 */  jal   sub_GAME_7F05C3D8
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
/* 0A54BC 7F07098C 0FC1BD9B */  jal   sub_GAME_7F06F66C
/* 0A54C0 7F070990 8E26006C */   lw    $a2, 0x6c($s1)
/* 0A54C4 7F070994 A6220060 */  sh    $v0, 0x60($s1)
/* 0A54C8 7F070998 8FA4006C */  lw    $a0, 0x6c($sp)
/* 0A54CC 7F07099C 8E250054 */  lw    $a1, 0x54($s1)
/* 0A54D0 7F0709A0 8E26006C */  lw    $a2, 0x6c($s1)
/* 0A54D4 7F0709A4 0FC1BD9B */  jal   sub_GAME_7F06F66C
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
/* 0A55C0 7F070A90 0FC1C024 */  jal   sub_GAME_7F070090
/* 0A55C4 7F070A94 00000000 */   nop   
/* 0A55C8 7F070A98 10000008 */  b     .L7F070ABC
/* 0A55CC 7F070A9C 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0A55D0 7F070AA0 C7B40108 */  lwc1  $f20, 0x108($sp)
.L7F070AA4:
/* 0A55D4 7F070AA4 02202025 */  move  $a0, $s1
/* 0A55D8 7F070AA8 8FA50100 */  lw    $a1, 0x100($sp)
/* 0A55DC 7F070AAC 4406A000 */  mfc1  $a2, $f20
/* 0A55E0 7F070AB0 0FC1C024 */  jal   sub_GAME_7F070090
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
void sub_GAME_7F070AEC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F070AEC
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
/* 0A5954 7F070E24 0FC1C07B */  jal   sub_GAME_7F0701EC
/* 0A5958 7F070E28 02002025 */   move  $a0, $s0
/* 0A595C 7F070E2C 10000006 */  b     .L7F070E48
/* 0A5960 7F070E30 C7B20084 */   lwc1  $f18, 0x84($sp)
.L7F070E34:
/* 0A5964 7F070E34 4405A000 */  mfc1  $a1, $f20
/* 0A5968 7F070E38 4406C000 */  mfc1  $a2, $f24
/* 0A596C 7F070E3C 0FC1C024 */  jal   sub_GAME_7F070090
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
/* 0A5998 7F070E68 0FC1BF2A */  jal   sub_GAME_7F06FCA8
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
/* 0A5A28 7F070EF8 0FC1C07B */  jal   sub_GAME_7F0701EC
/* 0A5A2C 7F070EFC E7A40010 */   swc1  $f4, 0x10($sp)
/* 0A5A30 7F070F00 10000015 */  b     .L7F070F58
/* 0A5A34 7F070F04 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F08:
/* 0A5A38 7F070F08 44050000 */  mfc1  $a1, $f0
/* 0A5A3C 7F070F0C 44069000 */  mfc1  $a2, $f18
/* 0A5A40 7F070F10 4407C000 */  mfc1  $a3, $f24
/* 0A5A44 7F070F14 02002025 */  move  $a0, $s0
/* 0A5A48 7F070F18 0FC1C07B */  jal   sub_GAME_7F0701EC
/* 0A5A4C 7F070F1C E7B80010 */   swc1  $f24, 0x10($sp)
/* 0A5A50 7F070F20 1000000D */  b     .L7F070F58
/* 0A5A54 7F070F24 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F28:
/* 0A5A58 7F070F28 10400006 */  beqz  $v0, .L7F070F44
/* 0A5A5C 7F070F2C 02002025 */   move  $a0, $s0
/* 0A5A60 7F070F30 44059000 */  mfc1  $a1, $f18
/* 0A5A64 7F070F34 0FC1C024 */  jal   sub_GAME_7F070090
/* 0A5A68 7F070F38 8FA60080 */   lw    $a2, 0x80($sp)
/* 0A5A6C 7F070F3C 10000006 */  b     .L7F070F58
/* 0A5A70 7F070F40 8FBF0054 */   lw    $ra, 0x54($sp)
.L7F070F44:
/* 0A5A74 7F070F44 44059000 */  mfc1  $a1, $f18
/* 0A5A78 7F070F48 4406C000 */  mfc1  $a2, $f24
/* 0A5A7C 7F070F4C 0FC1C024 */  jal   sub_GAME_7F070090
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





#ifdef NONMATCHING
void sub_GAME_7F070F80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F070F80
/* 0A5AB0 7F070F80 8C83000C */  lw    $v1, 0xc($a0)
/* 0A5AB4 7F070F84 3C0FE700 */  lui   $t7, 0xe700
/* 0A5AB8 7F070F88 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0A5ABC 7F070F8C 246E0008 */  addiu $t6, $v1, 8
/* 0A5AC0 7F070F90 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5AC4 7F070F94 AC600004 */  sw    $zero, 4($v1)
/* 0A5AC8 7F070F98 AC6F0000 */  sw    $t7, ($v1)
/* 0A5ACC 7F070F9C 8C83000C */  lw    $v1, 0xc($a0)
/* 0A5AD0 7F070FA0 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0A5AD4 7F070FA4 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A5AD8 7F070FA8 24780008 */  addiu $t8, $v1, 8
/* 0A5ADC 7F070FAC AC98000C */  sw    $t8, 0xc($a0)
/* 0A5AE0 7F070FB0 AC600004 */  sw    $zero, 4($v1)
/* 0A5AE4 7F070FB4 AC790000 */  sw    $t9, ($v1)
/* 0A5AE8 7F070FB8 8C880004 */  lw    $t0, 4($a0)
/* 0A5AEC 7F070FBC 3C18FC12 */  lui   $t8, (0xFC121824 >> 16) # lui $t8, 0xfc12
/* 0A5AF0 7F070FC0 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A5AF4 7F070FC4 1100000B */  beqz  $t0, .L7F070FF4
/* 0A5AF8 7F070FC8 37181824 */   ori   $t8, (0xFC121824 & 0xFFFF) # ori $t8, $t8, 0x1824
/* 0A5AFC 7F070FCC 8C83000C */  lw    $v1, 0xc($a0)
/* 0A5B00 7F070FD0 3C0AB900 */  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
/* 0A5B04 7F070FD4 3C0B0055 */  lui   $t3, (0x00552078 >> 16) # lui $t3, 0x55
/* 0A5B08 7F070FD8 24690008 */  addiu $t1, $v1, 8
/* 0A5B0C 7F070FDC AC89000C */  sw    $t1, 0xc($a0)
/* 0A5B10 7F070FE0 356B2078 */  ori   $t3, (0x00552078 & 0xFFFF) # ori $t3, $t3, 0x2078
/* 0A5B14 7F070FE4 354A031D */  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
/* 0A5B18 7F070FE8 AC6A0000 */  sw    $t2, ($v1)
/* 0A5B1C 7F070FEC 10000008 */  b     .L7F071010
/* 0A5B20 7F070FF0 AC6B0004 */   sw    $t3, 4($v1)
.L7F070FF4:
/* 0A5B24 7F070FF4 8C83000C */  lw    $v1, 0xc($a0)
/* 0A5B28 7F070FF8 3C0E0055 */  lui   $t6, (0x00552048 >> 16) # lui $t6, 0x55
/* 0A5B2C 7F070FFC 35CE2048 */  ori   $t6, (0x00552048 & 0xFFFF) # ori $t6, $t6, 0x2048
/* 0A5B30 7F071000 246C0008 */  addiu $t4, $v1, 8
/* 0A5B34 7F071004 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5B38 7F071008 AC6E0004 */  sw    $t6, 4($v1)
/* 0A5B3C 7F07100C AC6D0000 */  sw    $t5, ($v1)
.L7F071010:
/* 0A5B40 7F071010 8C83000C */  lw    $v1, 0xc($a0)
/* 0A5B44 7F071014 3C19FF33 */  lui   $t9, (0xFF33FFFF >> 16) # lui $t9, 0xff33
/* 0A5B48 7F071018 3739FFFF */  ori   $t9, (0xFF33FFFF & 0xFFFF) # ori $t9, $t9, 0xffff
/* 0A5B4C 7F07101C 246F0008 */  addiu $t7, $v1, 8
/* 0A5B50 7F071020 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5B54 7F071024 AC790004 */  sw    $t9, 4($v1)
/* 0A5B58 7F071028 03E00008 */  jr    $ra
/* 0A5B5C 7F07102C AC780000 */   sw    $t8, ($v1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F071030(void) {
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
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F071030 /*DisplayListSetup(obj)*/
/* 0A5B60 7F071030 8C820030 */  lw    $v0, 0x30($a0)    /*a0=obj?*/
/* 0A5B64 7F071034 24010007 */  li    $at, 7
/* 0A5B68 7F071038 5441006C */  bnel  $v0, $at, .L7F0711EC      /*obj.ModelType <= 7? */
/* 0A5B6C 7F07103C 24010008 */   li    $at, 8
/* 0A5B70 7F071040 50A00054 */  beql  $a1, $zero, .L7F071194    /*a1 = */
/* 0A5B74 7F071044 8C990004 */   lw    $t9, 4($a0)
/* 0A5B78 7F071048 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5B7C 7F07104C 3C0FE700 */  lui   $t7, 0xe700
/* 0A5B80 7F071050 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0A5B84 7F071054 244E0008 */  addiu $t6, $v0, 8
/* 0A5B88 7F071058 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5B8C 7F07105C AC400004 */  sw    $zero, 4($v0)
/* 0A5B90 7F071060 AC4F0000 */  sw    $t7, ($v0)
/* 0A5B94 7F071064 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5B98 7F071068 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402 /*2Cycle*/
/* 0A5B9C 7F07106C 3C0C0010 */  lui   $t4, 0x10
/* 0A5BA0 7F071070 24580008 */  addiu $t8, $v0, 8
/* 0A5BA4 7F071074 AC98000C */  sw    $t8, 0xc($a0)
/* 0A5BA8 7F071078 AC4C0004 */  sw    $t4, 4($v0)
/* 0A5BAC 7F07107C AC590000 */  sw    $t9, ($v0)
/* 0A5BB0 7F071080 8C8A0038 */  lw    $t2, 0x38($a0)
/* 0A5BB4 7F071084 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5BB8 7F071088 3C0FF800 */  lui   $t7, 0xf800
/* 0A5BBC 7F07108C 000A4402 */  srl   $t0, $t2, 0x10
/* 0A5BC0 7F071090 244E0008 */  addiu $t6, $v0, 8
/* 0A5BC4 7F071094 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5BC8 7F071098 310C00FF */  andi  $t4, $t0, 0xff
/* 0A5BCC 7F07109C 000AC602 */  srl   $t8, $t2, 0x18
/* 0A5BD0 7F0710A0 0018CE00 */  sll   $t9, $t8, 0x18
/* 0A5BD4 7F0710A4 000C6C00 */  sll   $t5, $t4, 0x10
/* 0A5BD8 7F0710A8 000A4A02 */  srl   $t1, $t2, 8
/* 0A5BDC 7F0710AC AC4F0000 */  sw    $t7, ($v0)
/* 0A5BE0 7F0710B0 312F00FF */  andi  $t7, $t1, 0xff
/* 0A5BE4 7F0710B4 032D7025 */  or    $t6, $t9, $t5
/* 0A5BE8 7F0710B8 000FC200 */  sll   $t8, $t7, 8
/* 0A5BEC 7F0710BC 01D86025 */  or    $t4, $t6, $t8
/* 0A5BF0 7F0710C0 315900FF */  andi  $t9, $t2, 0xff
/* 0A5BF4 7F0710C4 01996825 */  or    $t5, $t4, $t9
/* 0A5BF8 7F0710C8 AC4D0004 */  sw    $t5, 4($v0)
/* 0A5BFC 7F0710CC 8C830034 */  lw    $v1, 0x34($a0)
/* 0A5C00 7F0710D0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5C04 7F0710D4 3C0EFB00 */  lui   $t6, 0xfb00
/* 0A5C08 7F0710D8 00034402 */  srl   $t0, $v1, 0x10
/* 0A5C0C 7F0710DC 244F0008 */  addiu $t7, $v0, 8
/* 0A5C10 7F0710E0 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5C14 7F0710E4 311900FF */  andi  $t9, $t0, 0xff
/* 0A5C18 7F0710E8 00033E02 */  srl   $a3, $v1, 0x18
/* 0A5C1C 7F0710EC 00034A02 */  srl   $t1, $v1, 8
/* 0A5C20 7F0710F0 AC4E0000 */  sw    $t6, ($v0)
/* 0A5C24 7F0710F4 312E00FF */  andi  $t6, $t1, 0xff
/* 0A5C28 7F0710F8 00076600 */  sll   $t4, $a3, 0x18
/* 0A5C2C 7F0710FC 00196C00 */  sll   $t5, $t9, 0x10
/* 0A5C30 7F071100 018D7825 */  or    $t7, $t4, $t5
/* 0A5C34 7F071104 000EC200 */  sll   $t8, $t6, 8
/* 0A5C38 7F071108 01F8C825 */  or    $t9, $t7, $t8
/* 0A5C3C 7F07110C 372C00FF */  ori   $t4, $t9, 0xff
/* 0A5C40 7F071110 AC4C0004 */  sw    $t4, 4($v0)
/* 0A5C44 7F071114 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5C48 7F071118 3C0F5FFE */  lui   $t7, (0x5FFEDBF8 >> 16) # lui $t7, 0x5ffe    /*fulldl guard */
/* 0A5C4C 7F07111C 3C0EFC15 */  lui   $t6, (0xFC159804 >> 16) # lui $t6, 0xfc15
/* 0A5C50 7F071120 244D0008 */  addiu $t5, $v0, 8
/* 0A5C54 7F071124 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A5C58 7F071128 35CE9804 */  ori   $t6, (0xFC159804 & 0xFFFF) # ori $t6, $t6, 0x9804
/* 0A5C5C 7F07112C 35EFDBF8 */  ori   $t7, (0x5FFEDBF8 & 0xFFFF) # ori $t7, $t7, 0xdbf8
/* 0A5C60 7F071130 AC4F0004 */  sw    $t7, 4($v0)
/* 0A5C64 7F071134 AC4E0000 */  sw    $t6, ($v0)
/* 0A5C68 7F071138 8C980004 */  lw    $t8, 4($a0)
/* 0A5C6C 7F07113C 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A5C70 7F071140 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 0A5C74 7F071144 1300000A */  beqz  $t8, .L7F071170
/* 0A5C78 7F071148 35EF031D */   ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A5C7C 7F07114C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5C80 7F071150 3C0DC411 */  lui   $t5, (0xC4112078 >> 16) # lui $t5, 0xc411
/* 0A5C84 7F071154 35AD2078 */  ori   $t5, (0xC4112078 & 0xFFFF) # ori $t5, $t5, 0x2078
/* 0A5C88 7F071158 24590008 */  addiu $t9, $v0, 8
/* 0A5C8C 7F07115C AC99000C */  sw    $t9, 0xc($a0)
/* 0A5C90 7F071160 358C031D */  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 0A5C94 7F071164 AC4C0000 */  sw    $t4, ($v0)
/* 0A5C98 7F071168 03E00008 */  jr    $ra
/* 0A5C9C 7F07116C AC4D0004 */   sw    $t5, 4($v0)

.L7F071170:
/* 0A5CA0 7F071170 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5CA4 7F071174 3C18C411 */  lui   $t8, (0xC4112048 >> 16) # lui $t8, 0xc411
/* 0A5CA8 7F071178 37182048 */  ori   $t8, (0xC4112048 & 0xFFFF) # ori $t8, $t8, 0x2048
/* 0A5CAC 7F07117C 244E0008 */  addiu $t6, $v0, 8
/* 0A5CB0 7F071180 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5CB4 7F071184 AC580004 */  sw    $t8, 4($v0)
/* 0A5CB8 7F071188 03E00008 */  jr    $ra
/* 0A5CBC 7F07118C AC4F0000 */   sw    $t7, ($v0)

/* 0A5CC0 7F071190 8C990004 */  lw    $t9, 4($a0)
.L7F071194: /*UseZ - Transparent Gun Rendermode*/
/* 0A5CC4 7F071194 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A5CC8 7F071198 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A5CCC 7F07119C 1320000A */  beqz  $t9, .L7F0711C8
/* 0A5CD0 7F0711A0 3718031D */   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A5CD4 7F0711A4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5CD8 7F0711A8 3C0EC410 */  lui   $t6, (0xC41049D8 >> 16) # lui $t6, 0xc410
/* 0A5CDC 7F0711AC 35CE49D8 */  ori   $t6, (0xC41049D8 & 0xFFFF) # ori $t6, $t6, 0x49d8
/* 0A5CE0 7F0711B0 244C0008 */  addiu $t4, $v0, 8
/* 0A5CE4 7F0711B4 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5CE8 7F0711B8 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A5CEC 7F0711BC AC4D0000 */  sw    $t5, ($v0)
/* 0A5CF0 7F0711C0 03E00008 */  jr    $ra
/* 0A5CF4 7F0711C4 AC4E0004 */   sw    $t6, 4($v0)

.L7F0711C8: /*not UseZ - Opaque Gun Rendermode*/
/* 0A5CF8 7F0711C8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5CFC 7F0711CC 3C19C410 */  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
/* 0A5D00 7F0711D0 373941C8 */  ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
/* 0A5D04 7F0711D4 244F0008 */  addiu $t7, $v0, 8
/* 0A5D08 7F0711D8 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5D0C 7F0711DC AC590004 */  sw    $t9, 4($v0)
/* 0A5D10 7F0711E0 03E00008 */  jr    $ra
/* 0A5D14 7F0711E4 AC580000 */   sw    $t8, ($v0)

/* 0A5D18 7F0711E8 24010008 */  li    $at, 8
.L7F0711EC:
/* 0A5D1C 7F0711EC 54410057 */  bnel  $v0, $at, .L7F07134C
/* 0A5D20 7F0711F0 24010009 */   li    $at, 9
/* 0A5D24 7F0711F4 10A00251 */  beqz  $a1, .L7F071B3C
/* 0A5D28 7F0711F8 00000000 */   nop   
/* 0A5D2C 7F0711FC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5D30 7F071200 3C0DE700 */  lui   $t5, 0xe700
/* 0A5D34 7F071204 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0A5D38 7F071208 244C0008 */  addiu $t4, $v0, 8
/* 0A5D3C 7F07120C AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5D40 7F071210 AC400004 */  sw    $zero, 4($v0)
/* 0A5D44 7F071214 AC4D0000 */  sw    $t5, ($v0)
/* 0A5D48 7F071218 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5D4C 7F07121C 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0A5D50 7F071220 3C180010 */  lui   $t8, 0x10
/* 0A5D54 7F071224 244E0008 */  addiu $t6, $v0, 8
/* 0A5D58 7F071228 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5D5C 7F07122C AC580004 */  sw    $t8, 4($v0)       /*add to t7 = */
/* 0A5D60 7F071230 AC4F0000 */  sw    $t7, ($v0)        /*0xBA00140200000010 2cycle*/
/* 0A5D64 7F071234 8C8A0038 */  lw    $t2, 0x38($a0)
/* 0A5D68 7F071238 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5D6C 7F07123C 3C0DF800 */  lui   $t5, 0xf800       /*fogcolour*/
/* 0A5D70 7F071240 000A4402 */  srl   $t0, $t2, 0x10
/* 0A5D74 7F071244 244C0008 */  addiu $t4, $v0, 8
/* 0A5D78 7F071248 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5D7C 7F07124C 311800FF */  andi  $t8, $t0, 0xff
/* 0A5D80 7F071250 000A7602 */  srl   $t6, $t2, 0x18
/* 0A5D84 7F071254 000E7E00 */  sll   $t7, $t6, 0x18
/* 0A5D88 7F071258 0018CC00 */  sll   $t9, $t8, 0x10
/* 0A5D8C 7F07125C 000A4A02 */  srl   $t1, $t2, 8
/* 0A5D90 7F071260 AC4D0000 */  sw    $t5, ($v0)        /*black*/
/* 0A5D94 7F071264 312D00FF */  andi  $t5, $t1, 0xff
/* 0A5D98 7F071268 01F96025 */  or    $t4, $t7, $t9
/* 0A5D9C 7F07126C 000D7200 */  sll   $t6, $t5, 8
/* 0A5DA0 7F071270 018EC025 */  or    $t8, $t4, $t6
/* 0A5DA4 7F071274 314F00FF */  andi  $t7, $t2, 0xff
/* 0A5DA8 7F071278 030FC825 */  or    $t9, $t8, $t7
/* 0A5DAC 7F07127C AC590004 */  sw    $t9, 4($v0)
/* 0A5DB0 7F071280 8C8A0034 */  lw    $t2, 0x34($a0)
/* 0A5DB4 7F071284 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5DB8 7F071288 3C0EFB00 */  lui   $t6, 0xfb00       /*envcolour*/
/* 0A5DBC 7F07128C 000A4402 */  srl   $t0, $t2, 0x10
/* 0A5DC0 7F071290 244C0008 */  addiu $t4, $v0, 8
/* 0A5DC4 7F071294 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5DC8 7F071298 311900FF */  andi  $t9, $t0, 0xff
/* 0A5DCC 7F07129C 000AC602 */  srl   $t8, $t2, 0x18
/* 0A5DD0 7F0712A0 00187E00 */  sll   $t7, $t8, 0x18
/* 0A5DD4 7F0712A4 00196C00 */  sll   $t5, $t9, 0x10
/* 0A5DD8 7F0712A8 000A4A02 */  srl   $t1, $t2, 8
/* 0A5DDC 7F0712AC AC4E0000 */  sw    $t6, ($v0)        /*black*/
/* 0A5DE0 7F0712B0 312E00FF */  andi  $t6, $t1, 0xff
/* 0A5DE4 7F0712B4 01ED6025 */  or    $t4, $t7, $t5
/* 0A5DE8 7F0712B8 000EC200 */  sll   $t8, $t6, 8
/* 0A5DEC 7F0712BC 0198C825 */  or    $t9, $t4, $t8
/* 0A5DF0 7F0712C0 314F00FF */  andi  $t7, $t2, 0xff
/* 0A5DF4 7F0712C4 032F6825 */  or    $t5, $t9, $t7
/* 0A5DF8 7F0712C8 AC4D0004 */  sw    $t5, 4($v0)
/* 0A5DFC 7F0712CC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5E00 7F0712D0 3C185FFE */  lui   $t8, (0x5FFEFFF8 >> 16) # lui $t8, 0x5ffe
/* 0A5E04 7F0712D4 3C0CFC15 */  lui   $t4, (0xFC159A04 >> 16) # lui $t4, 0xfc15
/* 0A5E08 7F0712D8 244E0008 */  addiu $t6, $v0, 8
/* 0A5E0C 7F0712DC AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5E10 7F0712E0 358C9A04 */  ori   $t4, (0xFC159A04 & 0xFFFF) # ori $t4, $t4, 0x9a04
/* 0A5E14 7F0712E4 3718FFF8 */  ori   $t8, (0x5FFEFFF8 & 0xFFFF) # ori $t8, $t8, 0xfff8
/* 0A5E18 7F0712E8 AC580004 */  sw    $t8, 4($v0)
/* 0A5E1C 7F0712EC AC4C0000 */  sw    $t4, ($v0)
/* 0A5E20 7F0712F0 8C990004 */  lw    $t9, 4($a0)
/* 0A5E24 7F0712F4 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A5E28 7F0712F8 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A5E2C 7F0712FC 1320000A */  beqz  $t9, .L7F071328
/* 0A5E30 7F071300 3718031D */   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A5E34 7F071304 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5E38 7F071308 3C0EC410 */  lui   $t6, (0xC41049D8 >> 16) # lui $t6, 0xc410
/* 0A5E3C 7F07130C 35CE49D8 */  ori   $t6, (0xC41049D8 & 0xFFFF) # ori $t6, $t6, 0x49d8
/* 0A5E40 7F071310 244F0008 */  addiu $t7, $v0, 8
/* 0A5E44 7F071314 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5E48 7F071318 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d  /*Transparent Gun Rendermode Z*/
/* 0A5E4C 7F07131C AC4D0000 */  sw    $t5, ($v0)
/* 0A5E50 7F071320 03E00008 */  jr    $ra
/* 0A5E54 7F071324 AC4E0004 */   sw    $t6, 4($v0)

.L7F071328:
/* 0A5E58 7F071328 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5E5C 7F07132C 3C19C410 */  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
/* 0A5E60 7F071330 373941C8 */  ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8 /*transparent Gun rendermode NoZ*/
/* 0A5E64 7F071334 244C0008 */  addiu $t4, $v0, 8
/* 0A5E68 7F071338 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5E6C 7F07133C AC590004 */  sw    $t9, 4($v0)
/* 0A5E70 7F071340 03E00008 */  jr    $ra
/* 0A5E74 7F071344 AC580000 */   sw    $t8, ($v0)

/* 0A5E78 7F071348 24010009 */  li    $at, 9
.L7F07134C:
/* 0A5E7C 7F07134C 544100DE */  bnel  $v0, $at, .L7F0716C8
/* 0A5E80 7F071350 24010004 */   li    $at, 4
/* 0A5E84 7F071354 8C8F0034 */  lw    $t7, 0x34($a0)
/* 0A5E88 7F071358 31ED00FF */  andi  $t5, $t7, 0xff
/* 0A5E8C 7F07135C 15A00068 */  bnez  $t5, .L7F071500
/* 0A5E90 7F071360 00000000 */   nop   
/* 0A5E94 7F071364 10A00050 */  beqz  $a1, .L7F0714A8
/* 0A5E98 7F071368 3C18E700 */   lui   $t8, 0xe700
/* 0A5E9C 7F07136C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5EA0 7F071370 8C880038 */  lw    $t0, 0x38($a0)
/* 0A5EA4 7F071374 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0A5EA8 7F071378 244C0008 */  addiu $t4, $v0, 8
/* 0A5EAC 7F07137C AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5EB0 7F071380 AC400004 */  sw    $zero, 4($v0)
/* 0A5EB4 7F071384 AC580000 */  sw    $t8, ($v0)
/* 0A5EB8 7F071388 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5EBC 7F07138C 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0A5EC0 7F071390 3C0D0010 */  lui   $t5, 0x10
/* 0A5EC4 7F071394 24590008 */  addiu $t9, $v0, 8
/* 0A5EC8 7F071398 AC99000C */  sw    $t9, 0xc($a0)
/* 0A5ECC 7F07139C AC4D0004 */  sw    $t5, 4($v0)       /*add to t4 =*/
/* 0A5ED0 7F0713A0 AC4F0000 */  sw    $t7, ($v0)        /*2cycle*/
/* 0A5ED4 7F0713A4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5ED8 7F0713A8 00083402 */  srl   $a2, $t0, 0x10
/* 0A5EDC 7F0713AC 30CF00FF */  andi  $t7, $a2, 0xff
/* 0A5EE0 7F0713B0 244E0008 */  addiu $t6, $v0, 8
/* 0A5EE4 7F0713B4 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5EE8 7F0713B8 3C0CF800 */  lui   $t4, 0xf800       /*fogcolour*/
/* 0A5EEC 7F0713BC 00082E02 */  srl   $a1, $t0, 0x18
/* 0A5EF0 7F0713C0 0005CE00 */  sll   $t9, $a1, 0x18
/* 0A5EF4 7F0713C4 000F6C00 */  sll   $t5, $t7, 0x10
/* 0A5EF8 7F0713C8 00083A02 */  srl   $a3, $t0, 8
/* 0A5EFC 7F0713CC AC4C0000 */  sw    $t4, ($v0)        /*black*/
/* 0A5F00 7F0713D0 30EC00FF */  andi  $t4, $a3, 0xff
/* 0A5F04 7F0713D4 032D7025 */  or    $t6, $t9, $t5
/* 0A5F08 7F0713D8 000CC200 */  sll   $t8, $t4, 8
/* 0A5F0C 7F0713DC 01D87825 */  or    $t7, $t6, $t8
/* 0A5F10 7F0713E0 311900FF */  andi  $t9, $t0, 0xff
/* 0A5F14 7F0713E4 01F96825 */  or    $t5, $t7, $t9
/* 0A5F18 7F0713E8 AC4D0004 */  sw    $t5, 4($v0)
/* 0A5F1C 7F0713EC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5F20 7F0713F0 2418FFFF */  li    $t8, -1
/* 0A5F24 7F0713F4 3C0EFB00 */  lui   $t6, 0xfb00       /*envcolour*/
/* 0A5F28 7F0713F8 244C0008 */  addiu $t4, $v0, 8
/* 0A5F2C 7F0713FC AC8C000C */  sw    $t4, 0xc($a0)
/* 0A5F30 7F071400 AC580004 */  sw    $t8, 4($v0)
/* 0A5F34 7F071404 AC4E0000 */  sw    $t6, ($v0)        /*black*/
/* 0A5F38 7F071408 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5F3C 7F07140C 3C19FA00 */  lui   $t9, 0xfa00
/* 0A5F40 7F071410 244F0008 */  addiu $t7, $v0, 8
/* 0A5F44 7F071414 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5F48 7F071418 AC590000 */  sw    $t9, ($v0)
/* 0A5F4C 7F07141C 8C8D0034 */  lw    $t5, 0x34($a0)
/* 0A5F50 7F071420 3C19FC26 */  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
/* 0A5F54 7F071424 3739A004 */  ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004     /*prop combiner*/
/* 0A5F58 7F071428 000D7202 */  srl   $t6, $t5, 8
/* 0A5F5C 7F07142C 31D800FF */  andi  $t8, $t6, 0xff
/* 0A5F60 7F071430 AC580004 */  sw    $t8, 4($v0)
/* 0A5F64 7F071434 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5F68 7F071438 3C0D1F10 */  lui   $t5, (0x1F1093FB >> 16) # lui $t5, 0x1f10
/* 0A5F6C 7F07143C 35AD93FB */  ori   $t5, (0x1F1093FB & 0xFFFF) # ori $t5, $t5, 0x93fb
/* 0A5F70 7F071440 244F0008 */  addiu $t7, $v0, 8
/* 0A5F74 7F071444 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A5F78 7F071448 AC4D0004 */  sw    $t5, 4($v0)
/* 0A5F7C 7F07144C AC590000 */  sw    $t9, ($v0)
/* 0A5F80 7F071450 8C8C0004 */  lw    $t4, 4($a0)
/* 0A5F84 7F071454 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A5F88 7F071458 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A5F8C 7F07145C 1180000A */  beqz  $t4, .L7F071488
/* 0A5F90 7F071460 35AD031D */   ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A5F94 7F071464 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5F98 7F071468 3C0FC411 */  lui   $t7, (0xC4112078 >> 16) # lui $t7, 0xc411
/* 0A5F9C 7F07146C 35EF2078 */  ori   $t7, (0xC4112078 & 0xFFFF) # ori $t7, $t7, 0x2078     /*primary prop useZ rendermode*/
/* 0A5FA0 7F071470 244E0008 */  addiu $t6, $v0, 8
/* 0A5FA4 7F071474 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A5FA8 7F071478 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A5FAC 7F07147C AC580000 */  sw    $t8, ($v0)
/* 0A5FB0 7F071480 03E00008 */  jr    $ra
/* 0A5FB4 7F071484 AC4F0004 */   sw    $t7, 4($v0)

.L7F071488: /*Not UseZ*/
/* 0A5FB8 7F071488 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5FBC 7F07148C 3C0CC411 */  lui   $t4, (0xC4112048 >> 16) # lui $t4, 0xc411
/* 0A5FC0 7F071490 358C2048 */  ori   $t4, (0xC4112048 & 0xFFFF) # ori $t4, $t4, 0x2048 /*primary prop noz rendermode*/
/* 0A5FC4 7F071494 24590008 */  addiu $t9, $v0, 8
/* 0A5FC8 7F071498 AC99000C */  sw    $t9, 0xc($a0)
/* 0A5FCC 7F07149C AC4C0004 */  sw    $t4, 4($v0)
/* 0A5FD0 7F0714A0 03E00008 */  jr    $ra
/* 0A5FD4 7F0714A4 AC4D0000 */   sw    $t5, ($v0)

.L7F0714A8: /*sec UseZ*/
/* 0A5FD8 7F0714A8 8C8E0004 */  lw    $t6, 4($a0)
/* 0A5FDC 7F0714AC 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 0A5FE0 7F0714B0 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A5FE4 7F0714B4 11C0000A */  beqz  $t6, .L7F0714E0
/* 0A5FE8 7F0714B8 358C031D */   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 0A5FEC 7F0714BC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A5FF0 7F0714C0 3C19C410 */  lui   $t9, (0xC41049D8 >> 16) # lui $t9, 0xc410
/* 0A5FF4 7F0714C4 373949D8 */  ori   $t9, (0xC41049D8 & 0xFFFF) # ori $t9, $t9, 0x49d8
/* 0A5FF8 7F0714C8 24580008 */  addiu $t8, $v0, 8
/* 0A5FFC 7F0714CC AC98000C */  sw    $t8, 0xc($a0)
/* 0A6000 7F0714D0 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A6004 7F0714D4 AC4F0000 */  sw    $t7, ($v0)
/* 0A6008 7F0714D8 03E00008 */  jr    $ra
/* 0A600C 7F0714DC AC590004 */   sw    $t9, 4($v0)

.L7F0714E0: /*Sec Not UseZ*/
/* 0A6010 7F0714E0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6014 7F0714E4 3C0EC410 */  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
/* 0A6018 7F0714E8 35CE41C8 */  ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
/* 0A601C 7F0714EC 244D0008 */  addiu $t5, $v0, 8
/* 0A6020 7F0714F0 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6024 7F0714F4 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6028 7F0714F8 03E00008 */  jr    $ra
/* 0A602C 7F0714FC AC4C0000 */   sw    $t4, ($v0)

.L7F071500:
/* 0A6030 7F071500 10A00048 */  beqz  $a1, .L7F071624
/* 0A6034 7F071504 3C19E700 */   lui   $t9, 0xe700
/* 0A6038 7F071508 8C82000C */  lw    $v0, 0xc($a0)
/* 0A603C 7F07150C 8C880038 */  lw    $t0, 0x38($a0)
/* 0A6040 7F071510 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 0A6044 7F071514 244F0008 */  addiu $t7, $v0, 8
/* 0A6048 7F071518 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A604C 7F07151C AC400004 */  sw    $zero, 4($v0)
/* 0A6050 7F071520 AC590000 */  sw    $t9, ($v0)
/* 0A6054 7F071524 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6058 7F071528 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 0A605C 7F07152C 3C0E0010 */  lui   $t6, 0x10     /*add to t4 = */
/* 0A6060 7F071530 244D0008 */  addiu $t5, $v0, 8
/* 0A6064 7F071534 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6068 7F071538 AC4E0004 */  sw    $t6, 4($v0)
/* 0A606C 7F07153C AC4C0000 */  sw    $t4, ($v0)       /*2cycle*/
/* 0A6070 7F071540 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6074 7F071544 00083402 */  srl   $a2, $t0, 0x10
/* 0A6078 7F071548 30CC00FF */  andi  $t4, $a2, 0xff
/* 0A607C 7F07154C 24580008 */  addiu $t8, $v0, 8
/* 0A6080 7F071550 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6084 7F071554 3C0FF800 */  lui   $t7, 0xf800
/* 0A6088 7F071558 00082E02 */  srl   $a1, $t0, 0x18
/* 0A608C 7F07155C 00056E00 */  sll   $t5, $a1, 0x18
/* 0A6090 7F071560 000C7400 */  sll   $t6, $t4, 0x10
/* 0A6094 7F071564 00083A02 */  srl   $a3, $t0, 8
/* 0A6098 7F071568 AC4F0000 */  sw    $t7, ($v0)
/* 0A609C 7F07156C 30EF00FF */  andi  $t7, $a3, 0xff
/* 0A60A0 7F071570 01AEC025 */  or    $t8, $t5, $t6
/* 0A60A4 7F071574 000FCA00 */  sll   $t9, $t7, 8
/* 0A60A8 7F071578 03196025 */  or    $t4, $t8, $t9
/* 0A60AC 7F07157C 310D00FF */  andi  $t5, $t0, 0xff
/* 0A60B0 7F071580 018D7025 */  or    $t6, $t4, $t5
/* 0A60B4 7F071584 AC4E0004 */  sw    $t6, 4($v0)
/* 0A60B8 7F071588 8C82000C */  lw    $v0, 0xc($a0)
/* 0A60BC 7F07158C 3C18FB00 */  lui   $t8, 0xfb00
/* 0A60C0 7F071590 244F0008 */  addiu $t7, $v0, 8
/* 0A60C4 7F071594 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A60C8 7F071598 AC580000 */  sw    $t8, ($v0)
/* 0A60CC 7F07159C 8C8C0034 */  lw    $t4, 0x34($a0)
/* 0A60D0 7F0715A0 3C181FFC */  lui   $t8, (0x1FFCFBF8 >> 16) # lui $t8, 0x1ffc
/* 0A60D4 7F0715A4 3C0FFC26 */  lui   $t7, (0xFC26E804 >> 16) # lui $t7, 0xfc26
/* 0A60D8 7F0715A8 318D00FF */  andi  $t5, $t4, 0xff
/* 0A60DC 7F0715AC AC4D0004 */  sw    $t5, 4($v0)
/* 0A60E0 7F0715B0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A60E4 7F0715B4 35EFE804 */  ori   $t7, (0xFC26E804 & 0xFFFF) # ori $t7, $t7, 0xe804
/* 0A60E8 7F0715B8 3718FBF8 */  ori   $t8, (0x1FFCFBF8 & 0xFFFF) # ori $t8, $t8, 0xfbf8
/* 0A60EC 7F0715BC 244E0008 */  addiu $t6, $v0, 8
/* 0A60F0 7F0715C0 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A60F4 7F0715C4 AC580004 */  sw    $t8, 4($v0)
/* 0A60F8 7F0715C8 AC4F0000 */  sw    $t7, ($v0)
/* 0A60FC 7F0715CC 8C990004 */  lw    $t9, 4($a0)
/* 0A6100 7F0715D0 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6104 7F0715D4 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A6108 7F0715D8 1320000A */  beqz  $t9, .L7F071604
/* 0A610C 7F0715DC 3718031D */   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A6110 7F0715E0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6114 7F0715E4 3C0EC411 */  lui   $t6, (0xC4113078 >> 16) # lui $t6, 0xc411
/* 0A6118 7F0715E8 35CE3078 */  ori   $t6, (0xC4113078 & 0xFFFF) # ori $t6, $t6, 0x3078
/* 0A611C 7F0715EC 244C0008 */  addiu $t4, $v0, 8
/* 0A6120 7F0715F0 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A6124 7F0715F4 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A6128 7F0715F8 AC4D0000 */  sw    $t5, ($v0)
/* 0A612C 7F0715FC 03E00008 */  jr    $ra
/* 0A6130 7F071600 AC4E0004 */   sw    $t6, 4($v0)

.L7F071604:
/* 0A6134 7F071604 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6138 7F071608 3C19C411 */  lui   $t9, (0xC4113048 >> 16) # lui $t9, 0xc411
/* 0A613C 7F07160C 37393048 */  ori   $t9, (0xC4113048 & 0xFFFF) # ori $t9, $t9, 0x3048
/* 0A6140 7F071610 244F0008 */  addiu $t7, $v0, 8
/* 0A6144 7F071614 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6148 7F071618 AC590004 */  sw    $t9, 4($v0)
/* 0A614C 7F07161C 03E00008 */  jr    $ra
/* 0A6150 7F071620 AC580000 */   sw    $t8, ($v0)

.L7F071624:
/* 0A6154 7F071624 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6158 7F071628 3C0DFA00 */  lui   $t5, 0xfa00
/* 0A615C 7F07162C 244C0008 */  addiu $t4, $v0, 8
/* 0A6160 7F071630 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A6164 7F071634 AC4D0000 */  sw    $t5, ($v0)
/* 0A6168 7F071638 8C8E0034 */  lw    $t6, 0x34($a0)
/* 0A616C 7F07163C 3C0DFC26 */  lui   $t5, (0xFC26C204 >> 16) # lui $t5, 0xfc26
/* 0A6170 7F071640 35ADC204 */  ori   $t5, (0xFC26C204 & 0xFFFF) # ori $t5, $t5, 0xc204
/* 0A6174 7F071644 000EC202 */  srl   $t8, $t6, 8
/* 0A6178 7F071648 331900FF */  andi  $t9, $t8, 0xff
/* 0A617C 7F07164C AC590004 */  sw    $t9, 4($v0)
/* 0A6180 7F071650 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6184 7F071654 3C0E1FCC */  lui   $t6, (0x1FCCDFF8 >> 16) # lui $t6, 0x1fcc
/* 0A6188 7F071658 35CEDFF8 */  ori   $t6, (0x1FCCDFF8 & 0xFFFF) # ori $t6, $t6, 0xdff8
/* 0A618C 7F07165C 244C0008 */  addiu $t4, $v0, 8
/* 0A6190 7F071660 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A6194 7F071664 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6198 7F071668 AC4D0000 */  sw    $t5, ($v0)
/* 0A619C 7F07166C 8C8F0004 */  lw    $t7, 4($a0)
/* 0A61A0 7F071670 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A61A4 7F071674 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A61A8 7F071678 11E0000A */  beqz  $t7, .L7F0716A4
/* 0A61AC 7F07167C 35CE031D */   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A61B0 7F071680 8C82000C */  lw    $v0, 0xc($a0)
/* 0A61B4 7F071684 3C0CC411 */  lui   $t4, (0xC4113078 >> 16) # lui $t4, 0xc411
/* 0A61B8 7F071688 358C3078 */  ori   $t4, (0xC4113078 & 0xFFFF) # ori $t4, $t4, 0x3078
/* 0A61BC 7F07168C 24580008 */  addiu $t8, $v0, 8
/* 0A61C0 7F071690 AC98000C */  sw    $t8, 0xc($a0)
/* 0A61C4 7F071694 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A61C8 7F071698 AC590000 */  sw    $t9, ($v0)
/* 0A61CC 7F07169C 03E00008 */  jr    $ra
/* 0A61D0 7F0716A0 AC4C0004 */   sw    $t4, 4($v0)

.L7F0716A4:
/* 0A61D4 7F0716A4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A61D8 7F0716A8 3C0FC411 */  lui   $t7, (0xC4113048 >> 16) # lui $t7, 0xc411
/* 0A61DC 7F0716AC 35EF3048 */  ori   $t7, (0xC4113048 & 0xFFFF) # ori $t7, $t7, 0x3048
/* 0A61E0 7F0716B0 244D0008 */  addiu $t5, $v0, 8
/* 0A61E4 7F0716B4 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A61E8 7F0716B8 AC4F0004 */  sw    $t7, 4($v0)
/* 0A61EC 7F0716BC 03E00008 */  jr    $ra
/* 0A61F0 7F0716C0 AC4E0000 */   sw    $t6, ($v0)

/* 0A61F4 7F0716C4 24010004 */  li    $at, 4
.L7F0716C8:
/* 0A61F8 7F0716C8 54410059 */  bnel  $v0, $at, .L7F071830
/* 0A61FC 7F0716CC 24010005 */   li    $at, 5
/* 0A6200 7F0716D0 10A00040 */  beqz  $a1, .L7F0717D4
/* 0A6204 7F0716D4 3C0CE700 */   lui   $t4, 0xe700
/* 0A6208 7F0716D8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A620C 7F0716DC 8C880034 */  lw    $t0, 0x34($a0)
/* 0A6210 7F0716E0 3C0EBA00 */  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
/* 0A6214 7F0716E4 24590008 */  addiu $t9, $v0, 8
/* 0A6218 7F0716E8 AC99000C */  sw    $t9, 0xc($a0)
/* 0A621C 7F0716EC AC400004 */  sw    $zero, 4($v0)
/* 0A6220 7F0716F0 AC4C0000 */  sw    $t4, ($v0)
/* 0A6224 7F0716F4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6228 7F0716F8 35CE1402 */  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
/* 0A622C 7F0716FC 3C0F0010 */  lui   $t7, 0x10
/* 0A6230 7F071700 244D0008 */  addiu $t5, $v0, 8
/* 0A6234 7F071704 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6238 7F071708 AC4F0004 */  sw    $t7, 4($v0)
/* 0A623C 7F07170C AC4E0000 */  sw    $t6, ($v0)
/* 0A6240 7F071710 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6244 7F071714 00083402 */  srl   $a2, $t0, 0x10
/* 0A6248 7F071718 30CE00FF */  andi  $t6, $a2, 0xff
/* 0A624C 7F07171C 24580008 */  addiu $t8, $v0, 8
/* 0A6250 7F071720 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6254 7F071724 3C19F800 */  lui   $t9, 0xf800
/* 0A6258 7F071728 00082E02 */  srl   $a1, $t0, 0x18
/* 0A625C 7F07172C 00056E00 */  sll   $t5, $a1, 0x18
/* 0A6260 7F071730 000E7C00 */  sll   $t7, $t6, 0x10
/* 0A6264 7F071734 00083A02 */  srl   $a3, $t0, 8
/* 0A6268 7F071738 AC590000 */  sw    $t9, ($v0)
/* 0A626C 7F07173C 30F900FF */  andi  $t9, $a3, 0xff
/* 0A6270 7F071740 01AFC025 */  or    $t8, $t5, $t7
/* 0A6274 7F071744 00196200 */  sll   $t4, $t9, 8
/* 0A6278 7F071748 030C7025 */  or    $t6, $t8, $t4
/* 0A627C 7F07174C 310D00FF */  andi  $t5, $t0, 0xff
/* 0A6280 7F071750 01CD7825 */  or    $t7, $t6, $t5
/* 0A6284 7F071754 AC4F0004 */  sw    $t7, 4($v0)
/* 0A6288 7F071758 8C82000C */  lw    $v0, 0xc($a0)
/* 0A628C 7F07175C 3C0C1F10 */  lui   $t4, (0x1F1093FF >> 16) # lui $t4, 0x1f10
/* 0A6290 7F071760 3C18FC26 */  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
/* 0A6294 7F071764 24590008 */  addiu $t9, $v0, 8
/* 0A6298 7F071768 AC99000C */  sw    $t9, 0xc($a0)
/* 0A629C 7F07176C 3718A004 */  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
/* 0A62A0 7F071770 358C93FF */  ori   $t4, (0x1F1093FF & 0xFFFF) # ori $t4, $t4, 0x93ff
/* 0A62A4 7F071774 AC4C0004 */  sw    $t4, 4($v0)
/* 0A62A8 7F071778 AC580000 */  sw    $t8, ($v0)
/* 0A62AC 7F07177C 8C8E0004 */  lw    $t6, 4($a0)
/* 0A62B0 7F071780 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 0A62B4 7F071784 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A62B8 7F071788 11C0000A */  beqz  $t6, .L7F0717B4
/* 0A62BC 7F07178C 358C031D */   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 0A62C0 7F071790 8C82000C */  lw    $v0, 0xc($a0)
/* 0A62C4 7F071794 3C19C411 */  lui   $t9, (0xC4112078 >> 16) # lui $t9, 0xc411
/* 0A62C8 7F071798 37392078 */  ori   $t9, (0xC4112078 & 0xFFFF) # ori $t9, $t9, 0x2078
/* 0A62CC 7F07179C 244D0008 */  addiu $t5, $v0, 8
/* 0A62D0 7F0717A0 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A62D4 7F0717A4 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A62D8 7F0717A8 AC4F0000 */  sw    $t7, ($v0)
/* 0A62DC 7F0717AC 03E00008 */  jr    $ra
/* 0A62E0 7F0717B0 AC590004 */   sw    $t9, 4($v0)

.L7F0717B4:
/* 0A62E4 7F0717B4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A62E8 7F0717B8 3C0EC411 */  lui   $t6, (0xC4112048 >> 16) # lui $t6, 0xc411
/* 0A62EC 7F0717BC 35CE2048 */  ori   $t6, (0xC4112048 & 0xFFFF) # ori $t6, $t6, 0x2048
/* 0A62F0 7F0717C0 24580008 */  addiu $t8, $v0, 8
/* 0A62F4 7F0717C4 AC98000C */  sw    $t8, 0xc($a0)
/* 0A62F8 7F0717C8 AC4E0004 */  sw    $t6, 4($v0)
/* 0A62FC 7F0717CC 03E00008 */  jr    $ra
/* 0A6300 7F0717D0 AC4C0000 */   sw    $t4, ($v0)

.L7F0717D4:
/* 0A6304 7F0717D4 8C8D0004 */  lw    $t5, 4($a0)
/* 0A6308 7F0717D8 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A630C 7F0717DC 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A6310 7F0717E0 11A0000A */  beqz  $t5, .L7F07180C
/* 0A6314 7F0717E4 35CE031D */   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A6318 7F0717E8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A631C 7F0717EC 3C18C410 */  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
/* 0A6320 7F0717F0 371849D8 */  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
/* 0A6324 7F0717F4 244F0008 */  addiu $t7, $v0, 8
/* 0A6328 7F0717F8 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A632C 7F0717FC 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A6330 7F071800 AC590000 */  sw    $t9, ($v0)
/* 0A6334 7F071804 03E00008 */  jr    $ra
/* 0A6338 7F071808 AC580004 */   sw    $t8, 4($v0)

.L7F07180C:
/* 0A633C 7F07180C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6340 7F071810 3C0DC410 */  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
/* 0A6344 7F071814 35AD41C8 */  ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
/* 0A6348 7F071818 244C0008 */  addiu $t4, $v0, 8
/* 0A634C 7F07181C AC8C000C */  sw    $t4, 0xc($a0)
/* 0A6350 7F071820 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6354 7F071824 03E00008 */  jr    $ra
/* 0A6358 7F071828 AC4E0000 */   sw    $t6, ($v0)

/* 0A635C 7F07182C 24010005 */  li    $at, 5
.L7F071830:
/* 0A6360 7F071830 1441007F */  bne   $v0, $at, .L7F071A30
/* 0A6364 7F071834 00000000 */   nop   
/* 0A6368 7F071838 50A00066 */  beql  $a1, $zero, .L7F0719D4
/* 0A636C 7F07183C 8C990034 */   lw    $t9, 0x34($a0)
/* 0A6370 7F071840 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6374 7F071844 3C19E700 */  lui   $t9, 0xe700
/* 0A6378 7F071848 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 0A637C 7F07184C 244F0008 */  addiu $t7, $v0, 8
/* 0A6380 7F071850 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6384 7F071854 AC400004 */  sw    $zero, 4($v0)
/* 0A6388 7F071858 AC590000 */  sw    $t9, ($v0)
/* 0A638C 7F07185C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6390 7F071860 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 0A6394 7F071864 3C0E0010 */  lui   $t6, 0x10
/* 0A6398 7F071868 24580008 */  addiu $t8, $v0, 8
/* 0A639C 7F07186C AC98000C */  sw    $t8, 0xc($a0)
/* 0A63A0 7F071870 AC4E0004 */  sw    $t6, 4($v0)
/* 0A63A4 7F071874 AC4C0000 */  sw    $t4, ($v0)
/* 0A63A8 7F071878 8C8A0038 */  lw    $t2, 0x38($a0)
/* 0A63AC 7F07187C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A63B0 7F071880 3C19F800 */  lui   $t9, 0xf800
/* 0A63B4 7F071884 000A4402 */  srl   $t0, $t2, 0x10
/* 0A63B8 7F071888 244F0008 */  addiu $t7, $v0, 8
/* 0A63BC 7F07188C AC8F000C */  sw    $t7, 0xc($a0)
/* 0A63C0 7F071890 310E00FF */  andi  $t6, $t0, 0xff
/* 0A63C4 7F071894 000AC602 */  srl   $t8, $t2, 0x18
/* 0A63C8 7F071898 00186600 */  sll   $t4, $t8, 0x18
/* 0A63CC 7F07189C 000E6C00 */  sll   $t5, $t6, 0x10
/* 0A63D0 7F0718A0 000A4A02 */  srl   $t1, $t2, 8
/* 0A63D4 7F0718A4 AC590000 */  sw    $t9, ($v0)
/* 0A63D8 7F0718A8 313900FF */  andi  $t9, $t1, 0xff
/* 0A63DC 7F0718AC 018D7825 */  or    $t7, $t4, $t5
/* 0A63E0 7F0718B0 0019C200 */  sll   $t8, $t9, 8
/* 0A63E4 7F0718B4 01F87025 */  or    $t6, $t7, $t8
/* 0A63E8 7F0718B8 314C00FF */  andi  $t4, $t2, 0xff
/* 0A63EC 7F0718BC 01CC6825 */  or    $t5, $t6, $t4
/* 0A63F0 7F0718C0 AC4D0004 */  sw    $t5, 4($v0)
/* 0A63F4 7F0718C4 8C990034 */  lw    $t9, 0x34($a0)
/* 0A63F8 7F0718C8 3C0EFC26 */  lui   $t6, (0xFC26A004 >> 16) # lui $t6, 0xfc26
/* 0A63FC 7F0718CC 35CEA004 */  ori   $t6, (0xFC26A004 & 0xFFFF) # ori $t6, $t6, 0xa004
/* 0A6400 7F0718D0 332F00FF */  andi  $t7, $t9, 0xff
/* 0A6404 7F0718D4 29E100FF */  slti  $at, $t7, 0xff
/* 0A6408 7F0718D8 10200020 */  beqz  $at, .L7F07195C
/* 0A640C 7F0718DC 31EC00FF */   andi  $t4, $t7, 0xff
/* 0A6410 7F0718E0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6414 7F0718E4 2401FF00 */  li    $at, -256
/* 0A6418 7F0718E8 01816825 */  or    $t5, $t4, $at
/* 0A641C 7F0718EC 24580008 */  addiu $t8, $v0, 8
/* 0A6420 7F0718F0 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6424 7F0718F4 3C0EFB00 */  lui   $t6, 0xfb00
/* 0A6428 7F0718F8 AC4E0000 */  sw    $t6, ($v0)
/* 0A642C 7F0718FC AC4D0004 */  sw    $t5, 4($v0)
/* 0A6430 7F071900 8C990034 */  lw    $t9, 0x34($a0)
/* 0A6434 7F071904 3C0EFC26 */  lui   $t6, (0xFC26EA04 >> 16) # lui $t6, 0xfc26
/* 0A6438 7F071908 35CEEA04 */  ori   $t6, (0xFC26EA04 & 0xFFFF) # ori $t6, $t6, 0xea04
/* 0A643C 7F07190C 332FFF00 */  andi  $t7, $t9, 0xff00
/* 0A6440 7F071910 11E00009 */  beqz  $t7, .L7F071938
/* 0A6444 7F071914 3C19FC26 */   lui   $t9, (0xFC26EA04 >> 16) # lui $t9, 0xfc26
/* 0A6448 7F071918 8C82000C */  lw    $v0, 0xc($a0)
/* 0A644C 7F07191C 3C0C1F10 */  lui   $t4, (0x1F10CFFF >> 16) # lui $t4, 0x1f10
/* 0A6450 7F071920 358CCFFF */  ori   $t4, (0x1F10CFFF & 0xFFFF) # ori $t4, $t4, 0xcfff
/* 0A6454 7F071924 24580008 */  addiu $t8, $v0, 8
/* 0A6458 7F071928 AC98000C */  sw    $t8, 0xc($a0)
/* 0A645C 7F07192C AC4C0004 */  sw    $t4, 4($v0)
/* 0A6460 7F071930 10000011 */  b     .L7F071978
/* 0A6464 7F071934 AC4E0000 */   sw    $t6, ($v0)
.L7F071938:
/* 0A6468 7F071938 8C82000C */  lw    $v0, 0xc($a0)
/* 0A646C 7F07193C 3C0F1F10 */  lui   $t7, (0x1F10FFFF >> 16) # lui $t7, 0x1f10
/* 0A6470 7F071940 35EFFFFF */  ori   $t7, (0x1F10FFFF & 0xFFFF) # ori $t7, $t7, 0xffff
/* 0A6474 7F071944 244D0008 */  addiu $t5, $v0, 8
/* 0A6478 7F071948 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A647C 7F07194C 3739EA04 */  ori   $t9, (0xFC26EA04 & 0xFFFF) # ori $t9, $t9, 0xea04
/* 0A6480 7F071950 AC590000 */  sw    $t9, ($v0)
/* 0A6484 7F071954 10000008 */  b     .L7F071978
/* 0A6488 7F071958 AC4F0004 */   sw    $t7, 4($v0)
.L7F07195C:
/* 0A648C 7F07195C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6490 7F071960 3C0C1F10 */  lui   $t4, (0x1F1093FF >> 16) # lui $t4, 0x1f10
/* 0A6494 7F071964 358C93FF */  ori   $t4, (0x1F1093FF & 0xFFFF) # ori $t4, $t4, 0x93ff
/* 0A6498 7F071968 24580008 */  addiu $t8, $v0, 8
/* 0A649C 7F07196C AC98000C */  sw    $t8, 0xc($a0)
/* 0A64A0 7F071970 AC4C0004 */  sw    $t4, 4($v0)
/* 0A64A4 7F071974 AC4E0000 */  sw    $t6, ($v0)
.L7F071978:
/* 0A64A8 7F071978 8C8D0004 */  lw    $t5, 4($a0)
/* 0A64AC 7F07197C 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 0A64B0 7F071980 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A64B4 7F071984 11A0000A */  beqz  $t5, .L7F0719B0
/* 0A64B8 7F071988 358C031D */   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 0A64BC 7F07198C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A64C0 7F071990 3C18C410 */  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
/* 0A64C4 7F071994 371849D8 */  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
/* 0A64C8 7F071998 24590008 */  addiu $t9, $v0, 8
/* 0A64CC 7F07199C AC99000C */  sw    $t9, 0xc($a0)
/* 0A64D0 7F0719A0 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A64D4 7F0719A4 AC4F0000 */  sw    $t7, ($v0)
/* 0A64D8 7F0719A8 03E00008 */  jr    $ra
/* 0A64DC 7F0719AC AC580004 */   sw    $t8, 4($v0)

.L7F0719B0:
/* 0A64E0 7F0719B0 8C82000C */  lw    $v0, 0xc($a0)
/* 0A64E4 7F0719B4 3C0DC410 */  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
/* 0A64E8 7F0719B8 35AD41C8 */  ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
/* 0A64EC 7F0719BC 244E0008 */  addiu $t6, $v0, 8
/* 0A64F0 7F0719C0 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A64F4 7F0719C4 AC4D0004 */  sw    $t5, 4($v0)
/* 0A64F8 7F0719C8 03E00008 */  jr    $ra
/* 0A64FC 7F0719CC AC4C0000 */   sw    $t4, ($v0)

/* 0A6500 7F0719D0 8C990034 */  lw    $t9, 0x34($a0)
.L7F0719D4:
/* 0A6504 7F0719D4 3C0EFC26 */  lui   $t6, (0xFC269A04 >> 16) # lui $t6, 0xfc26
/* 0A6508 7F0719D8 35CE9A04 */  ori   $t6, (0xFC269A04 & 0xFFFF) # ori $t6, $t6, 0x9a04
/* 0A650C 7F0719DC 332F00FF */  andi  $t7, $t9, 0xff
/* 0A6510 7F0719E0 29E100FF */  slti  $at, $t7, 0xff
/* 0A6514 7F0719E4 10200009 */  beqz  $at, .L7F071A0C
/* 0A6518 7F0719E8 3C19FC26 */   lui   $t9, 0xfc26
/* 0A651C 7F0719EC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6520 7F0719F0 3C0C1F10 */  lui   $t4, (0x1F10FFFF >> 16) # lui $t4, 0x1f10
/* 0A6524 7F0719F4 358CFFFF */  ori   $t4, (0x1F10FFFF & 0xFFFF) # ori $t4, $t4, 0xffff
/* 0A6528 7F0719F8 24580008 */  addiu $t8, $v0, 8
/* 0A652C 7F0719FC AC98000C */  sw    $t8, 0xc($a0)
/* 0A6530 7F071A00 AC4C0004 */  sw    $t4, 4($v0)
/* 0A6534 7F071A04 03E00008 */  jr    $ra
/* 0A6538 7F071A08 AC4E0000 */   sw    $t6, ($v0)

.L7F071A0C:
/* 0A653C 7F071A0C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6540 7F071A10 3C0F1F10 */  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
/* 0A6544 7F071A14 35EF93FF */  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
/* 0A6548 7F071A18 244D0008 */  addiu $t5, $v0, 8
/* 0A654C 7F071A1C AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6550 7F071A20 3739A004 */  ori   $t9, $t9, 0xa004
/* 0A6554 7F071A24 AC590000 */  sw    $t9, ($v0)
/* 0A6558 7F071A28 03E00008 */  jr    $ra
/* 0A655C 7F071A2C AC4F0004 */   sw    $t7, 4($v0)

.L7F071A30:
/* 0A6560 7F071A30 10A0002D */  beqz  $a1, .L7F071AE8
/* 0A6564 7F071A34 3C0EE700 */   lui   $t6, 0xe700
/* 0A6568 7F071A38 8C82000C */  lw    $v0, 0xc($a0)
/* 0A656C 7F071A3C 3C0DBA00 */  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
/* 0A6570 7F071A40 35AD1402 */  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
/* 0A6574 7F071A44 24580008 */  addiu $t8, $v0, 8
/* 0A6578 7F071A48 AC98000C */  sw    $t8, 0xc($a0)
/* 0A657C 7F071A4C AC400004 */  sw    $zero, 4($v0)
/* 0A6580 7F071A50 AC4E0000 */  sw    $t6, ($v0)
/* 0A6584 7F071A54 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6588 7F071A58 3C190010 */  lui   $t9, 0x10
/* 0A658C 7F071A5C 3C0E1F10 */  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10
/* 0A6590 7F071A60 244C0008 */  addiu $t4, $v0, 8
/* 0A6594 7F071A64 AC8C000C */  sw    $t4, 0xc($a0)
/* 0A6598 7F071A68 AC590004 */  sw    $t9, 4($v0)
/* 0A659C 7F071A6C AC4D0000 */  sw    $t5, ($v0)
/* 0A65A0 7F071A70 8C82000C */  lw    $v0, 0xc($a0)
/* 0A65A4 7F071A74 3C18FC26 */  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
/* 0A65A8 7F071A78 3718A004 */  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
/* 0A65AC 7F071A7C 244F0008 */  addiu $t7, $v0, 8
/* 0A65B0 7F071A80 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A65B4 7F071A84 35CE93FF */  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff
/* 0A65B8 7F071A88 AC4E0004 */  sw    $t6, 4($v0)
/* 0A65BC 7F071A8C AC580000 */  sw    $t8, ($v0)
/* 0A65C0 7F071A90 8C8C0004 */  lw    $t4, 4($a0)
/* 0A65C4 7F071A94 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A65C8 7F071A98 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A65CC 7F071A9C 1180000A */  beqz  $t4, .L7F071AC8
/* 0A65D0 7F071AA0 35CE031D */   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A65D4 7F071AA4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A65D8 7F071AA8 3C0F0C19 */  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
/* 0A65DC 7F071AAC 35EF2078 */  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
/* 0A65E0 7F071AB0 244D0008 */  addiu $t5, $v0, 8
/* 0A65E4 7F071AB4 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A65E8 7F071AB8 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A65EC 7F071ABC AC590000 */  sw    $t9, ($v0)
/* 0A65F0 7F071AC0 03E00008 */  jr    $ra
/* 0A65F4 7F071AC4 AC4F0004 */   sw    $t7, 4($v0)

.L7F071AC8:
/* 0A65F8 7F071AC8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A65FC 7F071ACC 3C0C0C19 */  lui   $t4, (0x0C192048 >> 16) # lui $t4, 0xc19
/* 0A6600 7F071AD0 358C2048 */  ori   $t4, (0x0C192048 & 0xFFFF) # ori $t4, $t4, 0x2048
/* 0A6604 7F071AD4 24580008 */  addiu $t8, $v0, 8
/* 0A6608 7F071AD8 AC98000C */  sw    $t8, 0xc($a0)
/* 0A660C 7F071ADC AC4C0004 */  sw    $t4, 4($v0)
/* 0A6610 7F071AE0 03E00008 */  jr    $ra
/* 0A6614 7F071AE4 AC4E0000 */   sw    $t6, ($v0)

.L7F071AE8:
/* 0A6618 7F071AE8 8C8D0004 */  lw    $t5, 4($a0)
/* 0A661C 7F071AEC 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
/* 0A6620 7F071AF0 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A6624 7F071AF4 11A0000A */  beqz  $t5, .L7F071B20
/* 0A6628 7F071AF8 358C031D */   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 0A662C 7F071AFC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6630 7F071B00 3C180C18 */  lui   $t8, (0x0C1849D8 >> 16) # lui $t8, 0xc18
/* 0A6634 7F071B04 371849D8 */  ori   $t8, (0x0C1849D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
/* 0A6638 7F071B08 24590008 */  addiu $t9, $v0, 8
/* 0A663C 7F071B0C AC99000C */  sw    $t9, 0xc($a0)
/* 0A6640 7F071B10 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A6644 7F071B14 AC4F0000 */  sw    $t7, ($v0)
/* 0A6648 7F071B18 03E00008 */  jr    $ra
/* 0A664C 7F071B1C AC580004 */   sw    $t8, 4($v0)

.L7F071B20:
/* 0A6650 7F071B20 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6654 7F071B24 3C0D0C18 */  lui   $t5, (0x0C1841C8 >> 16) # lui $t5, 0xc18
/* 0A6658 7F071B28 35AD41C8 */  ori   $t5, (0x0C1841C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
/* 0A665C 7F071B2C 244E0008 */  addiu $t6, $v0, 8
/* 0A6660 7F071B30 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6664 7F071B34 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6668 7F071B38 AC4C0000 */  sw    $t4, ($v0)
.L7F071B3C:
/* 0A666C 7F071B3C 03E00008 */  jr    $ra
/* 0A6670 7F071B40 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F071B44(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F071B44
/* 0A6674 7F071B44 8C820030 */  lw    $v0, 0x30($a0)
/* 0A6678 7F071B48 24010007 */  li    $at, 7
/* 0A667C 7F071B4C 5441006B */  bnel  $v0, $at, .L7F071CFC
/* 0A6680 7F071B50 24010008 */   li    $at, 8
/* 0A6684 7F071B54 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6688 7F071B58 3C0FE700 */  lui   $t7, 0xe700
/* 0A668C 7F071B5C 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0A6690 7F071B60 244E0008 */  addiu $t6, $v0, 8
/* 0A6694 7F071B64 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6698 7F071B68 AC400004 */  sw    $zero, 4($v0)
/* 0A669C 7F071B6C AC4F0000 */  sw    $t7, ($v0)
/* 0A66A0 7F071B70 8C82000C */  lw    $v0, 0xc($a0)
/* 0A66A4 7F071B74 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0A66A8 7F071B78 3C0D0010 */  lui   $t5, 0x10
/* 0A66AC 7F071B7C 24580008 */  addiu $t8, $v0, 8
/* 0A66B0 7F071B80 AC98000C */  sw    $t8, 0xc($a0)
/* 0A66B4 7F071B84 AC4D0004 */  sw    $t5, 4($v0)
/* 0A66B8 7F071B88 AC590000 */  sw    $t9, ($v0)
/* 0A66BC 7F071B8C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A66C0 7F071B90 8C8B0038 */  lw    $t3, 0x38($a0)
/* 0A66C4 7F071B94 3C19F800 */  lui   $t9, 0xf800
/* 0A66C8 7F071B98 24580008 */  addiu $t8, $v0, 8
/* 0A66CC 7F071B9C AC98000C */  sw    $t8, 0xc($a0)
/* 0A66D0 7F071BA0 000B4C02 */  srl   $t1, $t3, 0x10
/* 0A66D4 7F071BA4 312F00FF */  andi  $t7, $t1, 0xff
/* 0A66D8 7F071BA8 000B4602 */  srl   $t0, $t3, 0x18
/* 0A66DC 7F071BAC 00087600 */  sll   $t6, $t0, 0x18
/* 0A66E0 7F071BB0 000FC400 */  sll   $t8, $t7, 0x10
/* 0A66E4 7F071BB4 AC590000 */  sw    $t9, ($v0)
/* 0A66E8 7F071BB8 000B5202 */  srl   $t2, $t3, 8
/* 0A66EC 7F071BBC 314D00FF */  andi  $t5, $t2, 0xff
/* 0A66F0 7F071BC0 01D8C825 */  or    $t9, $t6, $t8
/* 0A66F4 7F071BC4 000D7A00 */  sll   $t7, $t5, 8
/* 0A66F8 7F071BC8 032F7025 */  or    $t6, $t9, $t7
/* 0A66FC 7F071BCC 317800FF */  andi  $t8, $t3, 0xff
/* 0A6700 7F071BD0 01D86825 */  or    $t5, $t6, $t8
/* 0A6704 7F071BD4 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6708 7F071BD8 8C830034 */  lw    $v1, 0x34($a0)
/* 0A670C 7F071BDC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6710 7F071BE0 3C0EFB00 */  lui   $t6, 0xfb00
/* 0A6714 7F071BE4 00034C02 */  srl   $t1, $v1, 0x10
/* 0A6718 7F071BE8 244F0008 */  addiu $t7, $v0, 8
/* 0A671C 7F071BEC AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6720 7F071BF0 313900FF */  andi  $t9, $t1, 0xff
/* 0A6724 7F071BF4 0003C602 */  srl   $t8, $v1, 0x18
/* 0A6728 7F071BF8 00186E00 */  sll   $t5, $t8, 0x18
/* 0A672C 7F071BFC 00197C00 */  sll   $t7, $t9, 0x10
/* 0A6730 7F071C00 00035202 */  srl   $t2, $v1, 8
/* 0A6734 7F071C04 315800FF */  andi  $t8, $t2, 0xff
/* 0A6738 7F071C08 AC4E0000 */  sw    $t6, ($v0)
/* 0A673C 7F071C0C 01AF7025 */  or    $t6, $t5, $t7
/* 0A6740 7F071C10 0018CA00 */  sll   $t9, $t8, 8
/* 0A6744 7F071C14 01D96825 */  or    $t5, $t6, $t9
/* 0A6748 7F071C18 35AF00FF */  ori   $t7, $t5, 0xff
/* 0A674C 7F071C1C AC4F0004 */  sw    $t7, 4($v0)
/* 0A6750 7F071C20 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6754 7F071C24 3C195FFE */  lui   $t9, (0x5FFEDBF8 >> 16) # lui $t9, 0x5ffe
/* 0A6758 7F071C28 3C0EFC15 */  lui   $t6, (0xFC159804 >> 16) # lui $t6, 0xfc15
/* 0A675C 7F071C2C 24580008 */  addiu $t8, $v0, 8
/* 0A6760 7F071C30 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6764 7F071C34 35CE9804 */  ori   $t6, (0xFC159804 & 0xFFFF) # ori $t6, $t6, 0x9804
/* 0A6768 7F071C38 3739DBF8 */  ori   $t9, (0x5FFEDBF8 & 0xFFFF) # ori $t9, $t9, 0xdbf8
/* 0A676C 7F071C3C AC590004 */  sw    $t9, 4($v0)
/* 0A6770 7F071C40 10A00017 */  beqz  $a1, .L7F071CA0
/* 0A6774 7F071C44 AC4E0000 */   sw    $t6, ($v0)
/* 0A6778 7F071C48 8C8D0004 */  lw    $t5, 4($a0)
/* 0A677C 7F071C4C 3C0FC411 */  lui   $t7, (0xC4112048 >> 16) # lui $t7, 0xc411
/* 0A6780 7F071C50 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6784 7F071C54 11A0000A */  beqz  $t5, .L7F071C80
/* 0A6788 7F071C58 35EF2048 */   ori   $t7, (0xC4112048 & 0xFFFF) # ori $t7, $t7, 0x2048
/* 0A678C 7F071C5C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6790 7F071C60 3C0EC411 */  lui   $t6, (0xC4112078 >> 16) # lui $t6, 0xc411
/* 0A6794 7F071C64 35CE2078 */  ori   $t6, (0xC4112078 & 0xFFFF) # ori $t6, $t6, 0x2078
/* 0A6798 7F071C68 244F0008 */  addiu $t7, $v0, 8
/* 0A679C 7F071C6C AC8F000C */  sw    $t7, 0xc($a0)
/* 0A67A0 7F071C70 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A67A4 7F071C74 AC580000 */  sw    $t8, ($v0)
/* 0A67A8 7F071C78 03E00008 */  jr    $ra
/* 0A67AC 7F071C7C AC4E0004 */   sw    $t6, 4($v0)

.L7F071C80:
/* 0A67B0 7F071C80 8C82000C */  lw    $v0, 0xc($a0)
/* 0A67B4 7F071C84 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A67B8 7F071C88 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A67BC 7F071C8C 24590008 */  addiu $t9, $v0, 8
/* 0A67C0 7F071C90 AC99000C */  sw    $t9, 0xc($a0)
/* 0A67C4 7F071C94 AC4F0004 */  sw    $t7, 4($v0)
/* 0A67C8 7F071C98 03E00008 */  jr    $ra
/* 0A67CC 7F071C9C AC4D0000 */   sw    $t5, ($v0)

.L7F071CA0:
/* 0A67D0 7F071CA0 8C980004 */  lw    $t8, 4($a0)
/* 0A67D4 7F071CA4 3C0EC410 */  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
/* 0A67D8 7F071CA8 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A67DC 7F071CAC 1300000A */  beqz  $t8, .L7F071CD8
/* 0A67E0 7F071CB0 35CE41C8 */   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
/* 0A67E4 7F071CB4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A67E8 7F071CB8 3C0DC410 */  lui   $t5, (0xC41049D8 >> 16) # lui $t5, 0xc410
/* 0A67EC 7F071CBC 35AD49D8 */  ori   $t5, (0xC41049D8 & 0xFFFF) # ori $t5, $t5, 0x49d8
/* 0A67F0 7F071CC0 244E0008 */  addiu $t6, $v0, 8
/* 0A67F4 7F071CC4 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A67F8 7F071CC8 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A67FC 7F071CCC AC590000 */  sw    $t9, ($v0)
/* 0A6800 7F071CD0 03E00008 */  jr    $ra
/* 0A6804 7F071CD4 AC4D0004 */   sw    $t5, 4($v0)

.L7F071CD8:
/* 0A6808 7F071CD8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A680C 7F071CDC 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6810 7F071CE0 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A6814 7F071CE4 244F0008 */  addiu $t7, $v0, 8
/* 0A6818 7F071CE8 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A681C 7F071CEC AC4E0004 */  sw    $t6, 4($v0)
/* 0A6820 7F071CF0 03E00008 */  jr    $ra
/* 0A6824 7F071CF4 AC580000 */   sw    $t8, ($v0)

/* 0A6828 7F071CF8 24010008 */  li    $at, 8
.L7F071CFC:
/* 0A682C 7F071CFC 54410055 */  bnel  $v0, $at, .L7F071E54
/* 0A6830 7F071D00 24010009 */   li    $at, 9
/* 0A6834 7F071D04 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6838 7F071D08 3C0DE700 */  lui   $t5, 0xe700
/* 0A683C 7F071D0C 3C18BA00 */  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
/* 0A6840 7F071D10 24590008 */  addiu $t9, $v0, 8
/* 0A6844 7F071D14 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6848 7F071D18 AC400004 */  sw    $zero, 4($v0)
/* 0A684C 7F071D1C AC4D0000 */  sw    $t5, ($v0)
/* 0A6850 7F071D20 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6854 7F071D24 37181402 */  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
/* 0A6858 7F071D28 3C0E0010 */  lui   $t6, 0x10
/* 0A685C 7F071D2C 244F0008 */  addiu $t7, $v0, 8
/* 0A6860 7F071D30 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6864 7F071D34 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6868 7F071D38 AC580000 */  sw    $t8, ($v0)
/* 0A686C 7F071D3C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6870 7F071D40 8C8A0038 */  lw    $t2, 0x38($a0)
/* 0A6874 7F071D44 3C18F800 */  lui   $t8, 0xf800
/* 0A6878 7F071D48 244F0008 */  addiu $t7, $v0, 8
/* 0A687C 7F071D4C AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6880 7F071D50 000A4402 */  srl   $t0, $t2, 0x10
/* 0A6884 7F071D54 310D00FF */  andi  $t5, $t0, 0xff
/* 0A6888 7F071D58 000A3E02 */  srl   $a3, $t2, 0x18
/* 0A688C 7F071D5C 0007CE00 */  sll   $t9, $a3, 0x18
/* 0A6890 7F071D60 000D7C00 */  sll   $t7, $t5, 0x10
/* 0A6894 7F071D64 AC580000 */  sw    $t8, ($v0)
/* 0A6898 7F071D68 000A4A02 */  srl   $t1, $t2, 8
/* 0A689C 7F071D6C 312E00FF */  andi  $t6, $t1, 0xff
/* 0A68A0 7F071D70 032FC025 */  or    $t8, $t9, $t7
/* 0A68A4 7F071D74 000E6A00 */  sll   $t5, $t6, 8
/* 0A68A8 7F071D78 030DC825 */  or    $t9, $t8, $t5
/* 0A68AC 7F071D7C 314F00FF */  andi  $t7, $t2, 0xff
/* 0A68B0 7F071D80 032F7025 */  or    $t6, $t9, $t7
/* 0A68B4 7F071D84 AC4E0004 */  sw    $t6, 4($v0)
/* 0A68B8 7F071D88 8C82000C */  lw    $v0, 0xc($a0)
/* 0A68BC 7F071D8C 8C8A0034 */  lw    $t2, 0x34($a0)
/* 0A68C0 7F071D90 3C0FFB00 */  lui   $t7, 0xfb00
/* 0A68C4 7F071D94 24590008 */  addiu $t9, $v0, 8
/* 0A68C8 7F071D98 AC99000C */  sw    $t9, 0xc($a0)
/* 0A68CC 7F071D9C 000A4402 */  srl   $t0, $t2, 0x10
/* 0A68D0 7F071DA0 310D00FF */  andi  $t5, $t0, 0xff
/* 0A68D4 7F071DA4 000A3E02 */  srl   $a3, $t2, 0x18
/* 0A68D8 7F071DA8 0007C600 */  sll   $t8, $a3, 0x18
/* 0A68DC 7F071DAC 000DCC00 */  sll   $t9, $t5, 0x10
/* 0A68E0 7F071DB0 AC4F0000 */  sw    $t7, ($v0)
/* 0A68E4 7F071DB4 000A4A02 */  srl   $t1, $t2, 8
/* 0A68E8 7F071DB8 312E00FF */  andi  $t6, $t1, 0xff
/* 0A68EC 7F071DBC 03197825 */  or    $t7, $t8, $t9
/* 0A68F0 7F071DC0 000E6A00 */  sll   $t5, $t6, 8
/* 0A68F4 7F071DC4 01EDC025 */  or    $t8, $t7, $t5
/* 0A68F8 7F071DC8 315900FF */  andi  $t9, $t2, 0xff
/* 0A68FC 7F071DCC 03197025 */  or    $t6, $t8, $t9
/* 0A6900 7F071DD0 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6904 7F071DD4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6908 7F071DD8 3C185FFE */  lui   $t8, (0x5FFEFFF8 >> 16) # lui $t8, 0x5ffe
/* 0A690C 7F071DDC 3C0DFC15 */  lui   $t5, (0xFC159A04 >> 16) # lui $t5, 0xfc15
/* 0A6910 7F071DE0 244F0008 */  addiu $t7, $v0, 8
/* 0A6914 7F071DE4 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6918 7F071DE8 35AD9A04 */  ori   $t5, (0xFC159A04 & 0xFFFF) # ori $t5, $t5, 0x9a04
/* 0A691C 7F071DEC 3718FFF8 */  ori   $t8, (0x5FFEFFF8 & 0xFFFF) # ori $t8, $t8, 0xfff8
/* 0A6920 7F071DF0 AC580004 */  sw    $t8, 4($v0)
/* 0A6924 7F071DF4 AC4D0000 */  sw    $t5, ($v0)
/* 0A6928 7F071DF8 8C990004 */  lw    $t9, 4($a0)
/* 0A692C 7F071DFC 3C0EC410 */  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
/* 0A6930 7F071E00 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A6934 7F071E04 1320000A */  beqz  $t9, .L7F071E30
/* 0A6938 7F071E08 35CE41C8 */   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
/* 0A693C 7F071E0C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6940 7F071E10 3C0DC410 */  lui   $t5, (0xC41049D8 >> 16) # lui $t5, 0xc410
/* 0A6944 7F071E14 35AD49D8 */  ori   $t5, (0xC41049D8 & 0xFFFF) # ori $t5, $t5, 0x49d8
/* 0A6948 7F071E18 244E0008 */  addiu $t6, $v0, 8
/* 0A694C 7F071E1C AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6950 7F071E20 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A6954 7F071E24 AC4F0000 */  sw    $t7, ($v0)
/* 0A6958 7F071E28 03E00008 */  jr    $ra
/* 0A695C 7F071E2C AC4D0004 */   sw    $t5, 4($v0)

.L7F071E30:
/* 0A6960 7F071E30 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6964 7F071E34 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A6968 7F071E38 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A696C 7F071E3C 24580008 */  addiu $t8, $v0, 8
/* 0A6970 7F071E40 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6974 7F071E44 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6978 7F071E48 03E00008 */  jr    $ra
/* 0A697C 7F071E4C AC590000 */   sw    $t9, ($v0)

/* 0A6980 7F071E50 24010009 */  li    $at, 9
.L7F071E54:
/* 0A6984 7F071E54 544100E6 */  bnel  $v0, $at, .L7F0721F0
/* 0A6988 7F071E58 24010004 */   li    $at, 4
/* 0A698C 7F071E5C 8C8F0034 */  lw    $t7, 0x34($a0)
/* 0A6990 7F071E60 3C190010 */  lui   $t9, 0x10
/* 0A6994 7F071E64 3C18E700 */  lui   $t8, 0xe700
/* 0A6998 7F071E68 31ED00FF */  andi  $t5, $t7, 0xff
/* 0A699C 7F071E6C 15A00070 */  bnez  $t5, .L7F072030
/* 0A69A0 7F071E70 3C0F0010 */   lui   $t7, 0x10
/* 0A69A4 7F071E74 8C82000C */  lw    $v0, 0xc($a0)
/* 0A69A8 7F071E78 8C890038 */  lw    $t1, 0x38($a0)
/* 0A69AC 7F071E7C 3C0FE700 */  lui   $t7, 0xe700
/* 0A69B0 7F071E80 244E0008 */  addiu $t6, $v0, 8
/* 0A69B4 7F071E84 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A69B8 7F071E88 AC400004 */  sw    $zero, 4($v0)
/* 0A69BC 7F071E8C AC4F0000 */  sw    $t7, ($v0)
/* 0A69C0 7F071E90 8C82000C */  lw    $v0, 0xc($a0)
/* 0A69C4 7F071E94 3C18BA00 */  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
/* 0A69C8 7F071E98 37181402 */  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
/* 0A69CC 7F071E9C 244D0008 */  addiu $t5, $v0, 8
/* 0A69D0 7F071EA0 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A69D4 7F071EA4 AC590004 */  sw    $t9, 4($v0)
/* 0A69D8 7F071EA8 AC580000 */  sw    $t8, ($v0)
/* 0A69DC 7F071EAC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A69E0 7F071EB0 00093C02 */  srl   $a3, $t1, 0x10
/* 0A69E4 7F071EB4 30F900FF */  andi  $t9, $a3, 0xff
/* 0A69E8 7F071EB8 244E0008 */  addiu $t6, $v0, 8
/* 0A69EC 7F071EBC AC8E000C */  sw    $t6, 0xc($a0)
/* 0A69F0 7F071EC0 3C0FF800 */  lui   $t7, 0xf800
/* 0A69F4 7F071EC4 00093602 */  srl   $a2, $t1, 0x18
/* 0A69F8 7F071EC8 0006C600 */  sll   $t8, $a2, 0x18
/* 0A69FC 7F071ECC 00197400 */  sll   $t6, $t9, 0x10
/* 0A6A00 7F071ED0 00094202 */  srl   $t0, $t1, 8
/* 0A6A04 7F071ED4 AC4F0000 */  sw    $t7, ($v0)
/* 0A6A08 7F071ED8 030E7825 */  or    $t7, $t8, $t6
/* 0A6A0C 7F071EDC 310D00FF */  andi  $t5, $t0, 0xff
/* 0A6A10 7F071EE0 000DCA00 */  sll   $t9, $t5, 8
/* 0A6A14 7F071EE4 01F9C025 */  or    $t8, $t7, $t9
/* 0A6A18 7F071EE8 312E00FF */  andi  $t6, $t1, 0xff
/* 0A6A1C 7F071EEC 030E6825 */  or    $t5, $t8, $t6
/* 0A6A20 7F071EF0 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6A24 7F071EF4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6A28 7F071EF8 2418FFFF */  li    $t8, -1
/* 0A6A2C 7F071EFC 3C19FB00 */  lui   $t9, 0xfb00
/* 0A6A30 7F071F00 244F0008 */  addiu $t7, $v0, 8
/* 0A6A34 7F071F04 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6A38 7F071F08 AC580004 */  sw    $t8, 4($v0)
/* 0A6A3C 7F071F0C AC590000 */  sw    $t9, ($v0)
/* 0A6A40 7F071F10 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6A44 7F071F14 3C0DFA00 */  lui   $t5, 0xfa00
/* 0A6A48 7F071F18 3C191F10 */  lui   $t9, (0x1F1093FB >> 16) # lui $t9, 0x1f10
/* 0A6A4C 7F071F1C 244E0008 */  addiu $t6, $v0, 8
/* 0A6A50 7F071F20 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6A54 7F071F24 AC4D0000 */  sw    $t5, ($v0)
/* 0A6A58 7F071F28 8C8F0034 */  lw    $t7, 0x34($a0)
/* 0A6A5C 7F071F2C 373993FB */  ori   $t9, (0x1F1093FB & 0xFFFF) # ori $t9, $t9, 0x93fb
/* 0A6A60 7F071F30 000FC202 */  srl   $t8, $t7, 8
/* 0A6A64 7F071F34 330E00FF */  andi  $t6, $t8, 0xff
/* 0A6A68 7F071F38 10A00020 */  beqz  $a1, .L7F071FBC
/* 0A6A6C 7F071F3C AC4E0004 */   sw    $t6, 4($v0)
/* 0A6A70 7F071F40 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6A74 7F071F44 3C0FFC26 */  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
/* 0A6A78 7F071F48 3C191F10 */  lui   $t9, (0x1F1093FB >> 16) # lui $t9, 0x1f10
/* 0A6A7C 7F071F4C 244D0008 */  addiu $t5, $v0, 8
/* 0A6A80 7F071F50 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6A84 7F071F54 373993FB */  ori   $t9, (0x1F1093FB & 0xFFFF) # ori $t9, $t9, 0x93fb
/* 0A6A88 7F071F58 35EFA004 */  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
/* 0A6A8C 7F071F5C AC4F0000 */  sw    $t7, ($v0)
/* 0A6A90 7F071F60 AC590004 */  sw    $t9, 4($v0)
/* 0A6A94 7F071F64 8C980004 */  lw    $t8, 4($a0)
/* 0A6A98 7F071F68 3C0EC411 */  lui   $t6, (0xC4112048 >> 16) # lui $t6, 0xc411
/* 0A6A9C 7F071F6C 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A6AA0 7F071F70 1300000A */  beqz  $t8, .L7F071F9C
/* 0A6AA4 7F071F74 35CE2048 */   ori   $t6, (0xC4112048 & 0xFFFF) # ori $t6, $t6, 0x2048
/* 0A6AA8 7F071F78 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6AAC 7F071F7C 3C0FC411 */  lui   $t7, (0xC4112078 >> 16) # lui $t7, 0xc411
/* 0A6AB0 7F071F80 35EF2078 */  ori   $t7, (0xC4112078 & 0xFFFF) # ori $t7, $t7, 0x2078
/* 0A6AB4 7F071F84 244E0008 */  addiu $t6, $v0, 8
/* 0A6AB8 7F071F88 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6ABC 7F071F8C 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A6AC0 7F071F90 AC4D0000 */  sw    $t5, ($v0)
/* 0A6AC4 7F071F94 03E00008 */  jr    $ra
/* 0A6AC8 7F071F98 AC4F0004 */   sw    $t7, 4($v0)

.L7F071F9C:
/* 0A6ACC 7F071F9C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6AD0 7F071FA0 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6AD4 7F071FA4 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A6AD8 7F071FA8 24590008 */  addiu $t9, $v0, 8
/* 0A6ADC 7F071FAC AC99000C */  sw    $t9, 0xc($a0)
/* 0A6AE0 7F071FB0 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6AE4 7F071FB4 03E00008 */  jr    $ra
/* 0A6AE8 7F071FB8 AC580000 */   sw    $t8, ($v0)

.L7F071FBC:
/* 0A6AEC 7F071FBC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6AF0 7F071FC0 3C0FFC26 */  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
/* 0A6AF4 7F071FC4 35EFA004 */  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
/* 0A6AF8 7F071FC8 244D0008 */  addiu $t5, $v0, 8
/* 0A6AFC 7F071FCC AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6B00 7F071FD0 AC590004 */  sw    $t9, 4($v0)
/* 0A6B04 7F071FD4 AC4F0000 */  sw    $t7, ($v0)
/* 0A6B08 7F071FD8 8C980004 */  lw    $t8, 4($a0)
/* 0A6B0C 7F071FDC 3C0EC410 */  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
/* 0A6B10 7F071FE0 3C0DB900 */  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
/* 0A6B14 7F071FE4 1300000A */  beqz  $t8, .L7F072010
/* 0A6B18 7F071FE8 35CE41C8 */   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
/* 0A6B1C 7F071FEC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6B20 7F071FF0 3C0FC410 */  lui   $t7, (0xC41049D8 >> 16) # lui $t7, 0xc410
/* 0A6B24 7F071FF4 35EF49D8 */  ori   $t7, (0xC41049D8 & 0xFFFF) # ori $t7, $t7, 0x49d8
/* 0A6B28 7F071FF8 244E0008 */  addiu $t6, $v0, 8
/* 0A6B2C 7F071FFC AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6B30 7F072000 35AD031D */  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
/* 0A6B34 7F072004 AC4D0000 */  sw    $t5, ($v0)
/* 0A6B38 7F072008 03E00008 */  jr    $ra
/* 0A6B3C 7F07200C AC4F0004 */   sw    $t7, 4($v0)

.L7F072010:
/* 0A6B40 7F072010 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6B44 7F072014 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6B48 7F072018 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A6B4C 7F07201C 24590008 */  addiu $t9, $v0, 8
/* 0A6B50 7F072020 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6B54 7F072024 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6B58 7F072028 03E00008 */  jr    $ra
/* 0A6B5C 7F07202C AC580000 */   sw    $t8, ($v0)

.L7F072030:
/* 0A6B60 7F072030 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6B64 7F072034 8C890038 */  lw    $t1, 0x38($a0)
/* 0A6B68 7F072038 3C0DBA00 */  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
/* 0A6B6C 7F07203C 24590008 */  addiu $t9, $v0, 8
/* 0A6B70 7F072040 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6B74 7F072044 AC400004 */  sw    $zero, 4($v0)
/* 0A6B78 7F072048 AC580000 */  sw    $t8, ($v0)
/* 0A6B7C 7F07204C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6B80 7F072050 35AD1402 */  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
/* 0A6B84 7F072054 00093C02 */  srl   $a3, $t1, 0x10
/* 0A6B88 7F072058 244E0008 */  addiu $t6, $v0, 8
/* 0A6B8C 7F07205C AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6B90 7F072060 AC4F0004 */  sw    $t7, 4($v0)
/* 0A6B94 7F072064 AC4D0000 */  sw    $t5, ($v0)
/* 0A6B98 7F072068 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6B9C 7F07206C 30EF00FF */  andi  $t7, $a3, 0xff
/* 0A6BA0 7F072070 3C18F800 */  lui   $t8, 0xf800
/* 0A6BA4 7F072074 24590008 */  addiu $t9, $v0, 8
/* 0A6BA8 7F072078 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6BAC 7F07207C 00093602 */  srl   $a2, $t1, 0x18
/* 0A6BB0 7F072080 00066E00 */  sll   $t5, $a2, 0x18
/* 0A6BB4 7F072084 000FCC00 */  sll   $t9, $t7, 0x10
/* 0A6BB8 7F072088 00094202 */  srl   $t0, $t1, 8
/* 0A6BBC 7F07208C AC580000 */  sw    $t8, ($v0)
/* 0A6BC0 7F072090 01B9C025 */  or    $t8, $t5, $t9
/* 0A6BC4 7F072094 310E00FF */  andi  $t6, $t0, 0xff
/* 0A6BC8 7F072098 000E7A00 */  sll   $t7, $t6, 8
/* 0A6BCC 7F07209C 030F6825 */  or    $t5, $t8, $t7
/* 0A6BD0 7F0720A0 313900FF */  andi  $t9, $t1, 0xff
/* 0A6BD4 7F0720A4 01B97025 */  or    $t6, $t5, $t9
/* 0A6BD8 7F0720A8 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6BDC 7F0720AC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6BE0 7F0720B0 3C0FFB00 */  lui   $t7, 0xfb00
/* 0A6BE4 7F0720B4 24580008 */  addiu $t8, $v0, 8
/* 0A6BE8 7F0720B8 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6BEC 7F0720BC AC4F0000 */  sw    $t7, ($v0)
/* 0A6BF0 7F0720C0 8C990034 */  lw    $t9, 0x34($a0)
/* 0A6BF4 7F0720C4 3C0FFC26 */  lui   $t7, (0xFC26E804 >> 16) # lui $t7, 0xfc26
/* 0A6BF8 7F0720C8 35EFE804 */  ori   $t7, (0xFC26E804 & 0xFFFF) # ori $t7, $t7, 0xe804
/* 0A6BFC 7F0720CC 332E00FF */  andi  $t6, $t9, 0xff
/* 0A6C00 7F0720D0 10A0001E */  beqz  $a1, .L7F07214C
/* 0A6C04 7F0720D4 AC4E0004 */   sw    $t6, 4($v0)
/* 0A6C08 7F0720D8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6C0C 7F0720DC 3C0D1FFC */  lui   $t5, (0x1FFCFBF8 >> 16) # lui $t5, 0x1ffc
/* 0A6C10 7F0720E0 35ADFBF8 */  ori   $t5, (0x1FFCFBF8 & 0xFFFF) # ori $t5, $t5, 0xfbf8
/* 0A6C14 7F0720E4 24580008 */  addiu $t8, $v0, 8
/* 0A6C18 7F0720E8 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6C1C 7F0720EC AC4D0004 */  sw    $t5, 4($v0)
/* 0A6C20 7F0720F0 AC4F0000 */  sw    $t7, ($v0)
/* 0A6C24 7F0720F4 8C990004 */  lw    $t9, 4($a0)
/* 0A6C28 7F0720F8 3C0EC411 */  lui   $t6, (0xC4113048 >> 16) # lui $t6, 0xc411
/* 0A6C2C 7F0720FC 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A6C30 7F072100 1320000A */  beqz  $t9, .L7F07212C
/* 0A6C34 7F072104 35CE3048 */   ori   $t6, (0xC4113048 & 0xFFFF) # ori $t6, $t6, 0x3048
/* 0A6C38 7F072108 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6C3C 7F07210C 3C0FC411 */  lui   $t7, (0xC4113078 >> 16) # lui $t7, 0xc411
/* 0A6C40 7F072110 35EF3078 */  ori   $t7, (0xC4113078 & 0xFFFF) # ori $t7, $t7, 0x3078
/* 0A6C44 7F072114 244E0008 */  addiu $t6, $v0, 8
/* 0A6C48 7F072118 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6C4C 7F07211C 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A6C50 7F072120 AC580000 */  sw    $t8, ($v0)
/* 0A6C54 7F072124 03E00008 */  jr    $ra
/* 0A6C58 7F072128 AC4F0004 */   sw    $t7, 4($v0)

.L7F07212C:
/* 0A6C5C 7F07212C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6C60 7F072130 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A6C64 7F072134 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A6C68 7F072138 244D0008 */  addiu $t5, $v0, 8
/* 0A6C6C 7F07213C AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6C70 7F072140 AC4E0004 */  sw    $t6, 4($v0)
/* 0A6C74 7F072144 03E00008 */  jr    $ra
/* 0A6C78 7F072148 AC590000 */   sw    $t9, ($v0)

.L7F07214C:
/* 0A6C7C 7F07214C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6C80 7F072150 3C0FFA00 */  lui   $t7, 0xfa00
/* 0A6C84 7F072154 3C191FCC */  lui   $t9, (0x1FCCDFF8 >> 16) # lui $t9, 0x1fcc
/* 0A6C88 7F072158 24580008 */  addiu $t8, $v0, 8
/* 0A6C8C 7F07215C AC98000C */  sw    $t8, 0xc($a0)
/* 0A6C90 7F072160 AC4F0000 */  sw    $t7, ($v0)
/* 0A6C94 7F072164 8C8D0034 */  lw    $t5, 0x34($a0)
/* 0A6C98 7F072168 3739DFF8 */  ori   $t9, (0x1FCCDFF8 & 0xFFFF) # ori $t9, $t9, 0xdff8
/* 0A6C9C 7F07216C 000D7202 */  srl   $t6, $t5, 8
/* 0A6CA0 7F072170 31D800FF */  andi  $t8, $t6, 0xff
/* 0A6CA4 7F072174 AC580004 */  sw    $t8, 4($v0)
/* 0A6CA8 7F072178 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6CAC 7F07217C 3C0DFC26 */  lui   $t5, (0xFC26C204 >> 16) # lui $t5, 0xfc26
/* 0A6CB0 7F072180 35ADC204 */  ori   $t5, (0xFC26C204 & 0xFFFF) # ori $t5, $t5, 0xc204
/* 0A6CB4 7F072184 244F0008 */  addiu $t7, $v0, 8
/* 0A6CB8 7F072188 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6CBC 7F07218C AC590004 */  sw    $t9, 4($v0)
/* 0A6CC0 7F072190 AC4D0000 */  sw    $t5, ($v0)
/* 0A6CC4 7F072194 8C8E0004 */  lw    $t6, 4($a0)
/* 0A6CC8 7F072198 3C18C411 */  lui   $t8, (0xC4113048 >> 16) # lui $t8, 0xc411
/* 0A6CCC 7F07219C 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A6CD0 7F0721A0 11C0000A */  beqz  $t6, .L7F0721CC
/* 0A6CD4 7F0721A4 37183048 */   ori   $t8, (0xC4113048 & 0xFFFF) # ori $t8, $t8, 0x3048
/* 0A6CD8 7F0721A8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6CDC 7F0721AC 3C0DC411 */  lui   $t5, (0xC4113078 >> 16) # lui $t5, 0xc411
/* 0A6CE0 7F0721B0 35AD3078 */  ori   $t5, (0xC4113078 & 0xFFFF) # ori $t5, $t5, 0x3078
/* 0A6CE4 7F0721B4 24580008 */  addiu $t8, $v0, 8
/* 0A6CE8 7F0721B8 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6CEC 7F0721BC 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A6CF0 7F0721C0 AC4F0000 */  sw    $t7, ($v0)
/* 0A6CF4 7F0721C4 03E00008 */  jr    $ra
/* 0A6CF8 7F0721C8 AC4D0004 */   sw    $t5, 4($v0)

.L7F0721CC:
/* 0A6CFC 7F0721CC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6D00 7F0721D0 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A6D04 7F0721D4 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A6D08 7F0721D8 24590008 */  addiu $t9, $v0, 8
/* 0A6D0C 7F0721DC AC99000C */  sw    $t9, 0xc($a0)
/* 0A6D10 7F0721E0 AC580004 */  sw    $t8, 4($v0)
/* 0A6D14 7F0721E4 03E00008 */  jr    $ra
/* 0A6D18 7F0721E8 AC4E0000 */   sw    $t6, ($v0)

/* 0A6D1C 7F0721EC 24010004 */  li    $at, 4
.L7F0721F0:
/* 0A6D20 7F0721F0 14410057 */  bne   $v0, $at, .L7F072350
/* 0A6D24 7F0721F4 3C0EE700 */   lui   $t6, 0xe700
/* 0A6D28 7F0721F8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6D2C 7F0721FC 8C890034 */  lw    $t1, 0x34($a0)
/* 0A6D30 7F072200 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0A6D34 7F072204 24590008 */  addiu $t9, $v0, 8
/* 0A6D38 7F072208 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6D3C 7F07220C AC400004 */  sw    $zero, 4($v0)
/* 0A6D40 7F072210 AC4E0000 */  sw    $t6, ($v0)
/* 0A6D44 7F072214 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6D48 7F072218 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0A6D4C 7F07221C 3C0D0010 */  lui   $t5, 0x10
/* 0A6D50 7F072220 24580008 */  addiu $t8, $v0, 8
/* 0A6D54 7F072224 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6D58 7F072228 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6D5C 7F07222C AC4F0000 */  sw    $t7, ($v0)
/* 0A6D60 7F072230 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6D64 7F072234 00093C02 */  srl   $a3, $t1, 0x10
/* 0A6D68 7F072238 30ED00FF */  andi  $t5, $a3, 0xff
/* 0A6D6C 7F07223C 24590008 */  addiu $t9, $v0, 8
/* 0A6D70 7F072240 AC99000C */  sw    $t9, 0xc($a0)
/* 0A6D74 7F072244 3C0EF800 */  lui   $t6, 0xf800
/* 0A6D78 7F072248 00093602 */  srl   $a2, $t1, 0x18
/* 0A6D7C 7F07224C 00067E00 */  sll   $t7, $a2, 0x18
/* 0A6D80 7F072250 000DCC00 */  sll   $t9, $t5, 0x10
/* 0A6D84 7F072254 00094202 */  srl   $t0, $t1, 8
/* 0A6D88 7F072258 AC4E0000 */  sw    $t6, ($v0)
/* 0A6D8C 7F07225C 01F97025 */  or    $t6, $t7, $t9
/* 0A6D90 7F072260 311800FF */  andi  $t8, $t0, 0xff
/* 0A6D94 7F072264 00186A00 */  sll   $t5, $t8, 8
/* 0A6D98 7F072268 01CD7825 */  or    $t7, $t6, $t5
/* 0A6D9C 7F07226C 313900FF */  andi  $t9, $t1, 0xff
/* 0A6DA0 7F072270 01F9C025 */  or    $t8, $t7, $t9
/* 0A6DA4 7F072274 AC580004 */  sw    $t8, 4($v0)
/* 0A6DA8 7F072278 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6DAC 7F07227C 3C0F1F10 */  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
/* 0A6DB0 7F072280 3C0DFC26 */  lui   $t5, (0xFC26A004 >> 16) # lui $t5, 0xfc26
/* 0A6DB4 7F072284 244E0008 */  addiu $t6, $v0, 8
/* 0A6DB8 7F072288 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A6DBC 7F07228C 35ADA004 */  ori   $t5, (0xFC26A004 & 0xFFFF) # ori $t5, $t5, 0xa004
/* 0A6DC0 7F072290 35EF93FF */  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
/* 0A6DC4 7F072294 AC4F0004 */  sw    $t7, 4($v0)
/* 0A6DC8 7F072298 10A00017 */  beqz  $a1, .L7F0722F8
/* 0A6DCC 7F07229C AC4D0000 */   sw    $t5, ($v0)
/* 0A6DD0 7F0722A0 8C990004 */  lw    $t9, 4($a0)
/* 0A6DD4 7F0722A4 3C18C411 */  lui   $t8, (0xC4112048 >> 16) # lui $t8, 0xc411
/* 0A6DD8 7F0722A8 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A6DDC 7F0722AC 1320000A */  beqz  $t9, .L7F0722D8
/* 0A6DE0 7F0722B0 37182048 */   ori   $t8, (0xC4112048 & 0xFFFF) # ori $t8, $t8, 0x2048
/* 0A6DE4 7F0722B4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6DE8 7F0722B8 3C0DC411 */  lui   $t5, (0xC4112078 >> 16) # lui $t5, 0xc411
/* 0A6DEC 7F0722BC 35AD2078 */  ori   $t5, (0xC4112078 & 0xFFFF) # ori $t5, $t5, 0x2078
/* 0A6DF0 7F0722C0 24580008 */  addiu $t8, $v0, 8
/* 0A6DF4 7F0722C4 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6DF8 7F0722C8 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A6DFC 7F0722CC AC4E0000 */  sw    $t6, ($v0)
/* 0A6E00 7F0722D0 03E00008 */  jr    $ra
/* 0A6E04 7F0722D4 AC4D0004 */   sw    $t5, 4($v0)

.L7F0722D8:
/* 0A6E08 7F0722D8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6E0C 7F0722DC 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0A6E10 7F0722E0 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0A6E14 7F0722E4 244F0008 */  addiu $t7, $v0, 8
/* 0A6E18 7F0722E8 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6E1C 7F0722EC AC580004 */  sw    $t8, 4($v0)
/* 0A6E20 7F0722F0 03E00008 */  jr    $ra
/* 0A6E24 7F0722F4 AC590000 */   sw    $t9, ($v0)

.L7F0722F8:
/* 0A6E28 7F0722F8 8C8E0004 */  lw    $t6, 4($a0)
/* 0A6E2C 7F0722FC 3C0DC410 */  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
/* 0A6E30 7F072300 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A6E34 7F072304 11C0000A */  beqz  $t6, .L7F072330
/* 0A6E38 7F072308 35AD41C8 */   ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
/* 0A6E3C 7F07230C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6E40 7F072310 3C19C410 */  lui   $t9, (0xC41049D8 >> 16) # lui $t9, 0xc410
/* 0A6E44 7F072314 373949D8 */  ori   $t9, (0xC41049D8 & 0xFFFF) # ori $t9, $t9, 0x49d8
/* 0A6E48 7F072318 244D0008 */  addiu $t5, $v0, 8
/* 0A6E4C 7F07231C AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6E50 7F072320 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A6E54 7F072324 AC4F0000 */  sw    $t7, ($v0)
/* 0A6E58 7F072328 03E00008 */  jr    $ra
/* 0A6E5C 7F07232C AC590004 */   sw    $t9, 4($v0)

.L7F072330:
/* 0A6E60 7F072330 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6E64 7F072334 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A6E68 7F072338 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A6E6C 7F07233C 24580008 */  addiu $t8, $v0, 8
/* 0A6E70 7F072340 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6E74 7F072344 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6E78 7F072348 03E00008 */  jr    $ra
/* 0A6E7C 7F07234C AC4E0000 */   sw    $t6, ($v0)

.L7F072350:
/* 0A6E80 7F072350 24010005 */  li    $at, 5
/* 0A6E84 7F072354 14410070 */  bne   $v0, $at, .L7F072518
/* 0A6E88 7F072358 3C18E700 */   lui   $t8, 0xe700
/* 0A6E8C 7F07235C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6E90 7F072360 3C19E700 */  lui   $t9, 0xe700
/* 0A6E94 7F072364 3C0EBA00 */  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
/* 0A6E98 7F072368 244F0008 */  addiu $t7, $v0, 8
/* 0A6E9C 7F07236C AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6EA0 7F072370 AC400004 */  sw    $zero, 4($v0)
/* 0A6EA4 7F072374 AC590000 */  sw    $t9, ($v0)
/* 0A6EA8 7F072378 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6EAC 7F07237C 35CE1402 */  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
/* 0A6EB0 7F072380 3C0D0010 */  lui   $t5, 0x10
/* 0A6EB4 7F072384 24580008 */  addiu $t8, $v0, 8
/* 0A6EB8 7F072388 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6EBC 7F07238C AC4D0004 */  sw    $t5, 4($v0)
/* 0A6EC0 7F072390 AC4E0000 */  sw    $t6, ($v0)
/* 0A6EC4 7F072394 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6EC8 7F072398 8C8B0038 */  lw    $t3, 0x38($a0)
/* 0A6ECC 7F07239C 3C0EF800 */  lui   $t6, 0xf800
/* 0A6ED0 7F0723A0 24580008 */  addiu $t8, $v0, 8
/* 0A6ED4 7F0723A4 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6ED8 7F0723A8 000B4C02 */  srl   $t1, $t3, 0x10
/* 0A6EDC 7F0723AC 313900FF */  andi  $t9, $t1, 0xff
/* 0A6EE0 7F0723B0 000B4602 */  srl   $t0, $t3, 0x18
/* 0A6EE4 7F0723B4 00087E00 */  sll   $t7, $t0, 0x18
/* 0A6EE8 7F0723B8 0019C400 */  sll   $t8, $t9, 0x10
/* 0A6EEC 7F0723BC AC4E0000 */  sw    $t6, ($v0)
/* 0A6EF0 7F0723C0 000B5202 */  srl   $t2, $t3, 8
/* 0A6EF4 7F0723C4 314D00FF */  andi  $t5, $t2, 0xff
/* 0A6EF8 7F0723C8 01F87025 */  or    $t6, $t7, $t8
/* 0A6EFC 7F0723CC 000DCA00 */  sll   $t9, $t5, 8
/* 0A6F00 7F0723D0 01D97825 */  or    $t7, $t6, $t9
/* 0A6F04 7F0723D4 317800FF */  andi  $t8, $t3, 0xff
/* 0A6F08 7F0723D8 01F86825 */  or    $t5, $t7, $t8
/* 0A6F0C 7F0723DC AC4D0004 */  sw    $t5, 4($v0)
/* 0A6F10 7F0723E0 8C8E0034 */  lw    $t6, 0x34($a0)
/* 0A6F14 7F0723E4 3C18FC26 */  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
/* 0A6F18 7F0723E8 3718A004 */  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
/* 0A6F1C 7F0723EC 31D900FF */  andi  $t9, $t6, 0xff
/* 0A6F20 7F0723F0 2B2100FF */  slti  $at, $t9, 0xff
/* 0A6F24 7F0723F4 1020002B */  beqz  $at, .L7F0724A4
/* 0A6F28 7F0723F8 332D00FF */   andi  $t5, $t9, 0xff
/* 0A6F2C 7F0723FC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6F30 7F072400 2401FF00 */  li    $at, -256
/* 0A6F34 7F072404 01A17025 */  or    $t6, $t5, $at
/* 0A6F38 7F072408 244F0008 */  addiu $t7, $v0, 8
/* 0A6F3C 7F07240C AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6F40 7F072410 3C18FB00 */  lui   $t8, 0xfb00
/* 0A6F44 7F072414 AC580000 */  sw    $t8, ($v0)
/* 0A6F48 7F072418 10A00018 */  beqz  $a1, .L7F07247C
/* 0A6F4C 7F07241C AC4E0004 */   sw    $t6, 4($v0)
/* 0A6F50 7F072420 8C990034 */  lw    $t9, 0x34($a0)
/* 0A6F54 7F072424 3C181F10 */  lui   $t8, (0x1F10FFFF >> 16) # lui $t8, 0x1f10
/* 0A6F58 7F072428 3C0DFC26 */  lui   $t5, (0xFC26EA04 >> 16) # lui $t5, 0xfc26
/* 0A6F5C 7F07242C 332FFF00 */  andi  $t7, $t9, 0xff00
/* 0A6F60 7F072430 11E0000A */  beqz  $t7, .L7F07245C
/* 0A6F64 7F072434 3718FFFF */   ori   $t8, (0x1F10FFFF & 0xFFFF) # ori $t8, $t8, 0xffff
/* 0A6F68 7F072438 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6F6C 7F07243C 3C0E1F10 */  lui   $t6, (0x1F10CFFF >> 16) # lui $t6, 0x1f10
/* 0A6F70 7F072440 35CECFFF */  ori   $t6, (0x1F10CFFF & 0xFFFF) # ori $t6, $t6, 0xcfff
/* 0A6F74 7F072444 24580008 */  addiu $t8, $v0, 8
/* 0A6F78 7F072448 AC98000C */  sw    $t8, 0xc($a0)
/* 0A6F7C 7F07244C 35ADEA04 */  ori   $t5, (0xFC26EA04 & 0xFFFF) # ori $t5, $t5, 0xea04
/* 0A6F80 7F072450 AC4D0000 */  sw    $t5, ($v0)
/* 0A6F84 7F072454 1000001A */  b     .L7F0724C0
/* 0A6F88 7F072458 AC4E0004 */   sw    $t6, 4($v0)
.L7F07245C:
/* 0A6F8C 7F07245C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6F90 7F072460 3C0FFC26 */  lui   $t7, (0xFC26EA04 >> 16) # lui $t7, 0xfc26
/* 0A6F94 7F072464 35EFEA04 */  ori   $t7, (0xFC26EA04 & 0xFFFF) # ori $t7, $t7, 0xea04
/* 0A6F98 7F072468 24590008 */  addiu $t9, $v0, 8
/* 0A6F9C 7F07246C AC99000C */  sw    $t9, 0xc($a0)
/* 0A6FA0 7F072470 AC580004 */  sw    $t8, 4($v0)
/* 0A6FA4 7F072474 10000012 */  b     .L7F0724C0
/* 0A6FA8 7F072478 AC4F0000 */   sw    $t7, ($v0)
.L7F07247C:
/* 0A6FAC 7F07247C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6FB0 7F072480 3C0EFC26 */  lui   $t6, (0xFC269A04 >> 16) # lui $t6, 0xfc26
/* 0A6FB4 7F072484 3C191F10 */  lui   $t9, (0x1F10FFFF >> 16) # lui $t9, 0x1f10
/* 0A6FB8 7F072488 244D0008 */  addiu $t5, $v0, 8
/* 0A6FBC 7F07248C AC8D000C */  sw    $t5, 0xc($a0)
/* 0A6FC0 7F072490 3739FFFF */  ori   $t9, (0x1F10FFFF & 0xFFFF) # ori $t9, $t9, 0xffff
/* 0A6FC4 7F072494 35CE9A04 */  ori   $t6, (0xFC269A04 & 0xFFFF) # ori $t6, $t6, 0x9a04
/* 0A6FC8 7F072498 AC4E0000 */  sw    $t6, ($v0)
/* 0A6FCC 7F07249C 10000008 */  b     .L7F0724C0
/* 0A6FD0 7F0724A0 AC590004 */   sw    $t9, 4($v0)
.L7F0724A4:
/* 0A6FD4 7F0724A4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A6FD8 7F0724A8 3C0D1F10 */  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
/* 0A6FDC 7F0724AC 35AD93FF */  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
/* 0A6FE0 7F0724B0 244F0008 */  addiu $t7, $v0, 8
/* 0A6FE4 7F0724B4 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A6FE8 7F0724B8 AC4D0004 */  sw    $t5, 4($v0)
/* 0A6FEC 7F0724BC AC580000 */  sw    $t8, ($v0)
.L7F0724C0:
/* 0A6FF0 7F0724C0 8C8E0004 */  lw    $t6, 4($a0)
/* 0A6FF4 7F0724C4 3C19C410 */  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
/* 0A6FF8 7F0724C8 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A6FFC 7F0724CC 11C0000A */  beqz  $t6, .L7F0724F8
/* 0A7000 7F0724D0 373941C8 */   ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
/* 0A7004 7F0724D4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7008 7F0724D8 3C18C410 */  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
/* 0A700C 7F0724DC 371849D8 */  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
/* 0A7010 7F0724E0 24590008 */  addiu $t9, $v0, 8
/* 0A7014 7F0724E4 AC99000C */  sw    $t9, 0xc($a0)
/* 0A7018 7F0724E8 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A701C 7F0724EC AC4F0000 */  sw    $t7, ($v0)
/* 0A7020 7F0724F0 03E00008 */  jr    $ra
/* 0A7024 7F0724F4 AC580004 */   sw    $t8, 4($v0)

.L7F0724F8:
/* 0A7028 7F0724F8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A702C 7F0724FC 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A7030 7F072500 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A7034 7F072504 244D0008 */  addiu $t5, $v0, 8
/* 0A7038 7F072508 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A703C 7F07250C AC590004 */  sw    $t9, 4($v0)
/* 0A7040 7F072510 03E00008 */  jr    $ra
/* 0A7044 7F072514 AC4E0000 */   sw    $t6, ($v0)

.L7F072518:
/* 0A7048 7F072518 8C82000C */  lw    $v0, 0xc($a0)
/* 0A704C 7F07251C 3C0EBA00 */  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
/* 0A7050 7F072520 35CE1402 */  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
/* 0A7054 7F072524 244F0008 */  addiu $t7, $v0, 8
/* 0A7058 7F072528 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A705C 7F07252C AC400004 */  sw    $zero, 4($v0)
/* 0A7060 7F072530 AC580000 */  sw    $t8, ($v0)
/* 0A7064 7F072534 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7068 7F072538 3C190010 */  lui   $t9, 0x10
/* 0A706C 7F07253C 3C18F800 */  lui   $t8, 0xf800
/* 0A7070 7F072540 244D0008 */  addiu $t5, $v0, 8
/* 0A7074 7F072544 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A7078 7F072548 AC590004 */  sw    $t9, 4($v0)
/* 0A707C 7F07254C AC4E0000 */  sw    $t6, ($v0)
/* 0A7080 7F072550 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7084 7F072554 240DFF00 */  li    $t5, -256
/* 0A7088 7F072558 3C19FC26 */  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
/* 0A708C 7F07255C 244F0008 */  addiu $t7, $v0, 8
/* 0A7090 7F072560 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A7094 7F072564 AC4D0004 */  sw    $t5, 4($v0)
/* 0A7098 7F072568 AC580000 */  sw    $t8, ($v0)
/* 0A709C 7F07256C 8C82000C */  lw    $v0, 0xc($a0)
/* 0A70A0 7F072570 3C0F1F10 */  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
/* 0A70A4 7F072574 35EF93FF */  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
/* 0A70A8 7F072578 244E0008 */  addiu $t6, $v0, 8
/* 0A70AC 7F07257C AC8E000C */  sw    $t6, 0xc($a0)
/* 0A70B0 7F072580 3739A004 */  ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004
/* 0A70B4 7F072584 AC590000 */  sw    $t9, ($v0)
/* 0A70B8 7F072588 10A00017 */  beqz  $a1, .L7F0725E8
/* 0A70BC 7F07258C AC4F0004 */   sw    $t7, 4($v0)
/* 0A70C0 7F072590 8C980004 */  lw    $t8, 4($a0)
/* 0A70C4 7F072594 3C0DC411 */  lui   $t5, (0xC4112048 >> 16) # lui $t5, 0xc411
/* 0A70C8 7F072598 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A70CC 7F07259C 1300000A */  beqz  $t8, .L7F0725C8
/* 0A70D0 7F0725A0 35AD2048 */   ori   $t5, (0xC4112048 & 0xFFFF) # ori $t5, $t5, 0x2048
/* 0A70D4 7F0725A4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A70D8 7F0725A8 3C19C411 */  lui   $t9, (0xC4112078 >> 16) # lui $t9, 0xc411
/* 0A70DC 7F0725AC 37392078 */  ori   $t9, (0xC4112078 & 0xFFFF) # ori $t9, $t9, 0x2078
/* 0A70E0 7F0725B0 244D0008 */  addiu $t5, $v0, 8
/* 0A70E4 7F0725B4 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A70E8 7F0725B8 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A70EC 7F0725BC AC4E0000 */  sw    $t6, ($v0)
/* 0A70F0 7F0725C0 03E00008 */  jr    $ra
/* 0A70F4 7F0725C4 AC590004 */   sw    $t9, 4($v0)

.L7F0725C8:
/* 0A70F8 7F0725C8 8C82000C */  lw    $v0, 0xc($a0)
/* 0A70FC 7F0725CC 3C18B900 */  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
/* 0A7100 7F0725D0 3718031D */  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
/* 0A7104 7F0725D4 244F0008 */  addiu $t7, $v0, 8
/* 0A7108 7F0725D8 AC8F000C */  sw    $t7, 0xc($a0)
/* 0A710C 7F0725DC AC4D0004 */  sw    $t5, 4($v0)
/* 0A7110 7F0725E0 03E00008 */  jr    $ra
/* 0A7114 7F0725E4 AC580000 */   sw    $t8, ($v0)

.L7F0725E8:
/* 0A7118 7F0725E8 8C8E0004 */  lw    $t6, 4($a0)
/* 0A711C 7F0725EC 3C19C410 */  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
/* 0A7120 7F0725F0 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0A7124 7F0725F4 11C0000A */  beqz  $t6, .L7F072620
/* 0A7128 7F0725F8 373941C8 */   ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
/* 0A712C 7F0725FC 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7130 7F072600 3C18C410 */  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
/* 0A7134 7F072604 371849D8 */  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
/* 0A7138 7F072608 24590008 */  addiu $t9, $v0, 8
/* 0A713C 7F07260C AC99000C */  sw    $t9, 0xc($a0)
/* 0A7140 7F072610 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0A7144 7F072614 AC4F0000 */  sw    $t7, ($v0)
/* 0A7148 7F072618 03E00008 */  jr    $ra
/* 0A714C 7F07261C AC580004 */   sw    $t8, 4($v0)

.L7F072620:
/* 0A7150 7F072620 8C82000C */  lw    $v0, 0xc($a0)
/* 0A7154 7F072624 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A7158 7F072628 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A715C 7F07262C 244D0008 */  addiu $t5, $v0, 8
/* 0A7160 7F072630 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A7164 7F072634 AC590004 */  sw    $t9, 4($v0)
/* 0A7168 7F072638 AC4E0000 */  sw    $t6, ($v0)
/* 0A716C 7F07263C 03E00008 */  jr    $ra
/* 0A7170 7F072640 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F072644(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F072644
/* 0A7174 7F072644 8C83000C */  lw    $v1, 0xc($a0)
/* 0A7178 7F072648 3C0FE700 */  lui   $t7, 0xe700
/* 0A717C 7F07264C 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0A7180 7F072650 246E0008 */  addiu $t6, $v1, 8
/* 0A7184 7F072654 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A7188 7F072658 AC600004 */  sw    $zero, 4($v1)
/* 0A718C 7F07265C AC6F0000 */  sw    $t7, ($v1)
/* 0A7190 7F072660 8C83000C */  lw    $v1, 0xc($a0)
/* 0A7194 7F072664 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0A7198 7F072668 3C080010 */  lui   $t0, 0x10
/* 0A719C 7F07266C 24780008 */  addiu $t8, $v1, 8
/* 0A71A0 7F072670 AC98000C */  sw    $t8, 0xc($a0)
/* 0A71A4 7F072674 AC680004 */  sw    $t0, 4($v1)
/* 0A71A8 7F072678 AC790000 */  sw    $t9, ($v1)
/* 0A71AC 7F07267C 8C890004 */  lw    $t1, 4($a0)
/* 0A71B0 7F072680 3C19FC26 */  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
/* 0A71B4 7F072684 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0A71B8 7F072688 1120000B */  beqz  $t1, .L7F0726B8
/* 0A71BC 7F07268C 3739A004 */   ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004
/* 0A71C0 7F072690 8C83000C */  lw    $v1, 0xc($a0)
/* 0A71C4 7F072694 3C0BB900 */  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
/* 0A71C8 7F072698 3C0C0C19 */  lui   $t4, (0x0C192078 >> 16) # lui $t4, 0xc19
/* 0A71CC 7F07269C 246A0008 */  addiu $t2, $v1, 8
/* 0A71D0 7F0726A0 AC8A000C */  sw    $t2, 0xc($a0)
/* 0A71D4 7F0726A4 358C2078 */  ori   $t4, (0x0C192078 & 0xFFFF) # ori $t4, $t4, 0x2078
/* 0A71D8 7F0726A8 356B031D */  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
/* 0A71DC 7F0726AC AC6B0000 */  sw    $t3, ($v1)
/* 0A71E0 7F0726B0 10000009 */  b     .L7F0726D8
/* 0A71E4 7F0726B4 AC6C0004 */   sw    $t4, 4($v1)
.L7F0726B8:
/* 0A71E8 7F0726B8 8C83000C */  lw    $v1, 0xc($a0)
/* 0A71EC 7F0726BC 3C0F0C19 */  lui   $t7, (0x0C192048 >> 16) # lui $t7, 0xc19
/* 0A71F0 7F0726C0 35EF2048 */  ori   $t7, (0x0C192048 & 0xFFFF) # ori $t7, $t7, 0x2048
/* 0A71F4 7F0726C4 246D0008 */  addiu $t5, $v1, 8
/* 0A71F8 7F0726C8 AC8D000C */  sw    $t5, 0xc($a0)
/* 0A71FC 7F0726CC 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0A7200 7F0726D0 AC6E0000 */  sw    $t6, ($v1)
/* 0A7204 7F0726D4 AC6F0004 */  sw    $t7, 4($v1)
.L7F0726D8:
/* 0A7208 7F0726D8 8C83000C */  lw    $v1, 0xc($a0)
/* 0A720C 7F0726DC 3C081F10 */  lui   $t0, (0x1F1093FF >> 16) # lui $t0, 0x1f10
/* 0A7210 7F0726E0 350893FF */  ori   $t0, (0x1F1093FF & 0xFFFF) # ori $t0, $t0, 0x93ff
/* 0A7214 7F0726E4 24780008 */  addiu $t8, $v1, 8
/* 0A7218 7F0726E8 AC98000C */  sw    $t8, 0xc($a0)
/* 0A721C 7F0726EC AC680004 */  sw    $t0, 4($v1)
/* 0A7220 7F0726F0 03E00008 */  jr    $ra
/* 0A7224 7F0726F4 AC790000 */   sw    $t9, ($v1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0726F8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0726F8
/* 0A7228 7F0726F8 8C82003C */  lw    $v0, 0x3c($a0)
/* 0A722C 7F0726FC 24010001 */  li    $at, 1
/* 0A7230 7F072700 5441000A */  bnel  $v0, $at, .L7F07272C
/* 0A7234 7F072704 24010002 */   li    $at, 2
/* 0A7238 7F072708 8C83000C */  lw    $v1, 0xc($a0)
/* 0A723C 7F07270C 3C0FB600 */  lui   $t7, 0xb600
/* 0A7240 7F072710 24183000 */  li    $t8, 12288
/* 0A7244 7F072714 246E0008 */  addiu $t6, $v1, 8
/* 0A7248 7F072718 AC8E000C */  sw    $t6, 0xc($a0)
/* 0A724C 7F07271C AC780004 */  sw    $t8, 4($v1)
/* 0A7250 7F072720 03E00008 */  jr    $ra
/* 0A7254 7F072724 AC6F0000 */   sw    $t7, ($v1)

/* 0A7258 7F072728 24010002 */  li    $at, 2
.L7F07272C:
/* 0A725C 7F07272C 5441000A */  bnel  $v0, $at, .L7F072758
/* 0A7260 7F072730 24010003 */   li    $at, 3
/* 0A7264 7F072734 8C83000C */  lw    $v1, 0xc($a0)
/* 0A7268 7F072738 3C08B700 */  lui   $t0, 0xb700
/* 0A726C 7F07273C 24091000 */  li    $t1, 4096
/* 0A7270 7F072740 24790008 */  addiu $t9, $v1, 8
/* 0A7274 7F072744 AC99000C */  sw    $t9, 0xc($a0)
/* 0A7278 7F072748 AC690004 */  sw    $t1, 4($v1)
/* 0A727C 7F07274C 03E00008 */  jr    $ra
/* 0A7280 7F072750 AC680000 */   sw    $t0, ($v1)

/* 0A7284 7F072754 24010003 */  li    $at, 3
.L7F072758:
/* 0A7288 7F072758 14410008 */  bne   $v0, $at, .L7F07277C
/* 0A728C 7F07275C 00000000 */   nop   
/* 0A7290 7F072760 8C83000C */  lw    $v1, 0xc($a0)
/* 0A7294 7F072764 3C0BB700 */  lui   $t3, 0xb700
/* 0A7298 7F072768 240C2000 */  li    $t4, 8192
/* 0A729C 7F07276C 246A0008 */  addiu $t2, $v1, 8
/* 0A72A0 7F072770 AC8A000C */  sw    $t2, 0xc($a0)
/* 0A72A4 7F072774 AC6C0004 */  sw    $t4, 4($v1)
/* 0A72A8 7F072778 AC6B0000 */  sw    $t3, ($v1)
.L7F07277C:
/* 0A72AC 7F07277C 03E00008 */  jr    $ra
/* 0A72B0 7F072780 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F072784(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F072784
/* 0A72B4 7F072784 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0A72B8 7F072788 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A72BC 7F07278C AFB10018 */  sw    $s1, 0x18($sp)
/* 0A72C0 7F072790 AFB00014 */  sw    $s0, 0x14($sp)
/* 0A72C4 7F072794 8C8E0018 */  lw    $t6, 0x18($a0)
/* 0A72C8 7F072798 00808025 */  move  $s0, $a0
/* 0A72CC 7F07279C 8CB10004 */  lw    $s1, 4($a1)
/* 0A72D0 7F0727A0 55C00074 */  bnezl $t6, .L7F072974
/* 0A72D4 7F0727A4 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A72D8 7F0727A8 8C8F0008 */  lw    $t7, 8($a0)
/* 0A72DC 7F0727AC 31F80001 */  andi  $t8, $t7, 1
/* 0A72E0 7F0727B0 53000048 */  beql  $t8, $zero, .L7F0728D4
/* 0A72E4 7F0727B4 8E090008 */   lw    $t1, 8($s0)
/* 0A72E8 7F0727B8 8E390000 */  lw    $t9, ($s1)
/* 0A72EC 7F0727BC 53200045 */  beql  $t9, $zero, .L7F0728D4
/* 0A72F0 7F0727C0 8E090008 */   lw    $t1, 8($s0)
/* 0A72F4 7F0727C4 8C82000C */  lw    $v0, 0xc($a0)
/* 0A72F8 7F0727C8 3C09BC00 */  lui   $t1, (0xBC001406 >> 16) # lui $t1, 0xbc00
/* 0A72FC 7F0727CC 35291406 */  ori   $t1, (0xBC001406 & 0xFFFF) # ori $t1, $t1, 0x1406
/* 0A7300 7F0727D0 24480008 */  addiu $t0, $v0, 8
/* 0A7304 7F0727D4 AC88000C */  sw    $t0, 0xc($a0)
/* 0A7308 7F0727D8 AC490000 */  sw    $t1, ($v0)
/* 0A730C 7F0727DC 8E240008 */  lw    $a0, 8($s1)
/* 0A7310 7F0727E0 0C003A2C */  jal   osVirtualToPhysical
/* 0A7314 7F0727E4 AFA20030 */   sw    $v0, 0x30($sp)
/* 0A7318 7F0727E8 8FA30030 */  lw    $v1, 0x30($sp)
/* 0A731C 7F0727EC AC620004 */  sw    $v0, 4($v1)
/* 0A7320 7F0727F0 8E0A003C */  lw    $t2, 0x3c($s0)
/* 0A7324 7F0727F4 51400004 */  beql  $t2, $zero, .L7F072808
/* 0A7328 7F0727F8 82220012 */   lb    $v0, 0x12($s1)
/* 0A732C 7F0727FC 0FC1C9BE */  jal   sub_GAME_7F0726F8
/* 0A7330 7F072800 02002025 */   move  $a0, $s0
/* 0A7334 7F072804 82220012 */  lb    $v0, 0x12($s1)
.L7F072808:
/* 0A7338 7F072808 24010001 */  li    $at, 1
/* 0A733C 7F07280C 54410006 */  bnel  $v0, $at, .L7F072828
/* 0A7340 7F072810 24010003 */   li    $at, 3
/* 0A7344 7F072814 0FC1C3E0 */  jal   sub_GAME_7F070F80
/* 0A7348 7F072818 02002025 */   move  $a0, $s0
/* 0A734C 7F07281C 10000015 */  b     .L7F072874
/* 0A7350 7F072820 8E02000C */   lw    $v0, 0xc($s0)
/* 0A7354 7F072824 24010003 */  li    $at, 3
.L7F072828:
/* 0A7358 7F072828 14410005 */  bne   $v0, $at, .L7F072840
/* 0A735C 7F07282C 02002025 */   move  $a0, $s0
/* 0A7360 7F072830 0FC1C40C */  jal   sub_GAME_7F071030
/* 0A7364 7F072834 24050001 */   li    $a1, 1
/* 0A7368 7F072838 1000000E */  b     .L7F072874
/* 0A736C 7F07283C 8E02000C */   lw    $v0, 0xc($s0)
.L7F072840:
/* 0A7370 7F072840 24010004 */  li    $at, 4
/* 0A7374 7F072844 14410005 */  bne   $v0, $at, .L7F07285C
/* 0A7378 7F072848 02002025 */   move  $a0, $s0
/* 0A737C 7F07284C 0FC1C6D1 */  jal   sub_GAME_7F071B44
/* 0A7380 7F072850 24050001 */   li    $a1, 1
/* 0A7384 7F072854 10000007 */  b     .L7F072874
/* 0A7388 7F072858 8E02000C */   lw    $v0, 0xc($s0)
.L7F07285C:
/* 0A738C 7F07285C 24010002 */  li    $at, 2
/* 0A7390 7F072860 54410004 */  bnel  $v0, $at, .L7F072874
/* 0A7394 7F072864 8E02000C */   lw    $v0, 0xc($s0)
/* 0A7398 7F072868 0FC1C991 */  jal   sub_GAME_7F072644
/* 0A739C 7F07286C 02002025 */   move  $a0, $s0
/* 0A73A0 7F072870 8E02000C */  lw    $v0, 0xc($s0)
.L7F072874:
/* 0A73A4 7F072874 3C0C0600 */  lui   $t4, 0x600
/* 0A73A8 7F072878 24010003 */  li    $at, 3
/* 0A73AC 7F07287C 244B0008 */  addiu $t3, $v0, 8
/* 0A73B0 7F072880 AE0B000C */  sw    $t3, 0xc($s0)
/* 0A73B4 7F072884 AC4C0000 */  sw    $t4, ($v0)
/* 0A73B8 7F072888 8E2D0000 */  lw    $t5, ($s1)
/* 0A73BC 7F07288C AC4D0004 */  sw    $t5, 4($v0)
/* 0A73C0 7F072890 822E0012 */  lb    $t6, 0x12($s1)
/* 0A73C4 7F072894 55C1000F */  bnel  $t6, $at, .L7F0728D4
/* 0A73C8 7F072898 8E090008 */   lw    $t1, 8($s0)
/* 0A73CC 7F07289C 8E2F0004 */  lw    $t7, 4($s1)
/* 0A73D0 7F0728A0 02002025 */  move  $a0, $s0
/* 0A73D4 7F0728A4 51E0000B */  beql  $t7, $zero, .L7F0728D4
/* 0A73D8 7F0728A8 8E090008 */   lw    $t1, 8($s0)
/* 0A73DC 7F0728AC 0FC1C40C */  jal   sub_GAME_7F071030
/* 0A73E0 7F0728B0 00002825 */   move  $a1, $zero
/* 0A73E4 7F0728B4 8E02000C */  lw    $v0, 0xc($s0)
/* 0A73E8 7F0728B8 3C190600 */  lui   $t9, 0x600
/* 0A73EC 7F0728BC 24580008 */  addiu $t8, $v0, 8
/* 0A73F0 7F0728C0 AE18000C */  sw    $t8, 0xc($s0)
/* 0A73F4 7F0728C4 AC590000 */  sw    $t9, ($v0)
/* 0A73F8 7F0728C8 8E280004 */  lw    $t0, 4($s1)
/* 0A73FC 7F0728CC AC480004 */  sw    $t0, 4($v0)
/* 0A7400 7F0728D0 8E090008 */  lw    $t1, 8($s0)
.L7F0728D4:
/* 0A7404 7F0728D4 312A0002 */  andi  $t2, $t1, 2
/* 0A7408 7F0728D8 51400026 */  beql  $t2, $zero, .L7F072974
/* 0A740C 7F0728DC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7410 7F0728E0 8E2B0000 */  lw    $t3, ($s1)
/* 0A7414 7F0728E4 51600023 */  beql  $t3, $zero, .L7F072974
/* 0A7418 7F0728E8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A741C 7F0728EC 822C0012 */  lb    $t4, 0x12($s1)
/* 0A7420 7F0728F0 24010004 */  li    $at, 4
/* 0A7424 7F0728F4 5581001F */  bnel  $t4, $at, .L7F072974
/* 0A7428 7F0728F8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A742C 7F0728FC 8E2D0004 */  lw    $t5, 4($s1)
/* 0A7430 7F072900 51A0001C */  beql  $t5, $zero, .L7F072974
/* 0A7434 7F072904 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7438 7F072908 8E02000C */  lw    $v0, 0xc($s0)
/* 0A743C 7F07290C 3C0FBC00 */  lui   $t7, (0xBC001406 >> 16) # lui $t7, 0xbc00
/* 0A7440 7F072910 35EF1406 */  ori   $t7, (0xBC001406 & 0xFFFF) # ori $t7, $t7, 0x1406
/* 0A7444 7F072914 244E0008 */  addiu $t6, $v0, 8
/* 0A7448 7F072918 AE0E000C */  sw    $t6, 0xc($s0)
/* 0A744C 7F07291C AC4F0000 */  sw    $t7, ($v0)
/* 0A7450 7F072920 8E240008 */  lw    $a0, 8($s1)
/* 0A7454 7F072924 0C003A2C */  jal   osVirtualToPhysical
/* 0A7458 7F072928 AFA20024 */   sw    $v0, 0x24($sp)
/* 0A745C 7F07292C 8FA30024 */  lw    $v1, 0x24($sp)
/* 0A7460 7F072930 AC620004 */  sw    $v0, 4($v1)
/* 0A7464 7F072934 8E18003C */  lw    $t8, 0x3c($s0)
/* 0A7468 7F072938 53000004 */  beql  $t8, $zero, .L7F07294C
/* 0A746C 7F07293C 02002025 */   move  $a0, $s0
/* 0A7470 7F072940 0FC1C9BE */  jal   sub_GAME_7F0726F8
/* 0A7474 7F072944 02002025 */   move  $a0, $s0
/* 0A7478 7F072948 02002025 */  move  $a0, $s0
.L7F07294C:
/* 0A747C 7F07294C 0FC1C6D1 */  jal   sub_GAME_7F071B44
/* 0A7480 7F072950 00002825 */   move  $a1, $zero
/* 0A7484 7F072954 8E02000C */  lw    $v0, 0xc($s0)
/* 0A7488 7F072958 3C080600 */  lui   $t0, 0x600
/* 0A748C 7F07295C 24590008 */  addiu $t9, $v0, 8
/* 0A7490 7F072960 AE19000C */  sw    $t9, 0xc($s0)
/* 0A7494 7F072964 AC480000 */  sw    $t0, ($v0)
/* 0A7498 7F072968 8E290004 */  lw    $t1, 4($s1)
/* 0A749C 7F07296C AC490004 */  sw    $t1, 4($v0)
/* 0A74A0 7F072970 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F072974:
/* 0A74A4 7F072974 8FB00014 */  lw    $s0, 0x14($sp)
/* 0A74A8 7F072978 8FB10018 */  lw    $s1, 0x18($sp)
/* 0A74AC 7F07297C 03E00008 */  jr    $ra
/* 0A74B0 7F072980 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F072984(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F072984
/* 0A74B4 7F072984 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0A74B8 7F072988 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A74BC 7F07298C AFB10018 */  sw    $s1, 0x18($sp)
/* 0A74C0 7F072990 AFB00014 */  sw    $s0, 0x14($sp)
/* 0A74C4 7F072994 AFA5004C */  sw    $a1, 0x4c($sp)
/* 0A74C8 7F072998 AFA60050 */  sw    $a2, 0x50($sp)
/* 0A74CC 7F07299C 8C8F0018 */  lw    $t7, 0x18($a0)
/* 0A74D0 7F0729A0 00808025 */  move  $s0, $a0
/* 0A74D4 7F0729A4 8CD10004 */  lw    $s1, 4($a2)
/* 0A74D8 7F0729A8 55E00095 */  bnezl $t7, .L7F072C00
/* 0A74DC 7F0729AC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A74E0 7F0729B0 8C980008 */  lw    $t8, 8($a0)
/* 0A74E4 7F0729B4 00A02025 */  move  $a0, $a1
/* 0A74E8 7F0729B8 33190001 */  andi  $t9, $t8, 1
/* 0A74EC 7F0729BC 53200058 */  beql  $t9, $zero, .L7F072B20
/* 0A74F0 7F0729C0 8E0F0008 */   lw    $t7, 8($s0)
/* 0A74F4 7F0729C4 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A74F8 7F0729C8 00C02825 */   move  $a1, $a2
/* 0A74FC 7F0729CC AFA20040 */  sw    $v0, 0x40($sp)
/* 0A7500 7F0729D0 8C480004 */  lw    $t0, 4($v0)
/* 0A7504 7F0729D4 51000052 */  beql  $t0, $zero, .L7F072B20
/* 0A7508 7F0729D8 8E0F0008 */   lw    $t7, 8($s0)
/* 0A750C 7F0729DC 8E03000C */  lw    $v1, 0xc($s0)
/* 0A7510 7F0729E0 3C0ABC00 */  lui   $t2, (0xBC001406 >> 16) # lui $t2, 0xbc00
/* 0A7514 7F0729E4 354A1406 */  ori   $t2, (0xBC001406 & 0xFFFF) # ori $t2, $t2, 0x1406
/* 0A7518 7F0729E8 24690008 */  addiu $t1, $v1, 8
/* 0A751C 7F0729EC AE09000C */  sw    $t1, 0xc($s0)
/* 0A7520 7F0729F0 AC6A0000 */  sw    $t2, ($v1)
/* 0A7524 7F0729F4 8E24001C */  lw    $a0, 0x1c($s1)
/* 0A7528 7F0729F8 0C003A2C */  jal   osVirtualToPhysical
/* 0A752C 7F0729FC AFA3003C */   sw    $v1, 0x3c($sp)
/* 0A7530 7F072A00 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0A7534 7F072A04 ACA20004 */  sw    $v0, 4($a1)
/* 0A7538 7F072A08 8E0B003C */  lw    $t3, 0x3c($s0)
/* 0A753C 7F072A0C 51600004 */  beql  $t3, $zero, .L7F072A20
/* 0A7540 7F072A10 86220018 */   lh    $v0, 0x18($s1)
/* 0A7544 7F072A14 0FC1C9BE */  jal   sub_GAME_7F0726F8
/* 0A7548 7F072A18 02002025 */   move  $a0, $s0
/* 0A754C 7F072A1C 86220018 */  lh    $v0, 0x18($s1)
.L7F072A20:
/* 0A7550 7F072A20 24010001 */  li    $at, 1
/* 0A7554 7F072A24 54410006 */  bnel  $v0, $at, .L7F072A40
/* 0A7558 7F072A28 24010003 */   li    $at, 3
/* 0A755C 7F072A2C 0FC1C3E0 */  jal   sub_GAME_7F070F80
/* 0A7560 7F072A30 02002025 */   move  $a0, $s0
/* 0A7564 7F072A34 10000015 */  b     .L7F072A8C
/* 0A7568 7F072A38 8E03000C */   lw    $v1, 0xc($s0)
/* 0A756C 7F072A3C 24010003 */  li    $at, 3
.L7F072A40:
/* 0A7570 7F072A40 14410005 */  bne   $v0, $at, .L7F072A58
/* 0A7574 7F072A44 02002025 */   move  $a0, $s0
/* 0A7578 7F072A48 0FC1C40C */  jal   sub_GAME_7F071030
/* 0A757C 7F072A4C 24050001 */   li    $a1, 1
/* 0A7580 7F072A50 1000000E */  b     .L7F072A8C
/* 0A7584 7F072A54 8E03000C */   lw    $v1, 0xc($s0)
.L7F072A58:
/* 0A7588 7F072A58 24010004 */  li    $at, 4
/* 0A758C 7F072A5C 14410005 */  bne   $v0, $at, .L7F072A74
/* 0A7590 7F072A60 02002025 */   move  $a0, $s0
/* 0A7594 7F072A64 0FC1C6D1 */  jal   sub_GAME_7F071B44
/* 0A7598 7F072A68 24050001 */   li    $a1, 1
/* 0A759C 7F072A6C 10000007 */  b     .L7F072A8C
/* 0A75A0 7F072A70 8E03000C */   lw    $v1, 0xc($s0)
.L7F072A74:
/* 0A75A4 7F072A74 24010002 */  li    $at, 2
/* 0A75A8 7F072A78 54410004 */  bnel  $v0, $at, .L7F072A8C
/* 0A75AC 7F072A7C 8E03000C */   lw    $v1, 0xc($s0)
/* 0A75B0 7F072A80 0FC1C991 */  jal   sub_GAME_7F072644
/* 0A75B4 7F072A84 02002025 */   move  $a0, $s0
/* 0A75B8 7F072A88 8E03000C */  lw    $v1, 0xc($s0)
.L7F072A8C:
/* 0A75BC 7F072A8C 3C0DBC00 */  lui   $t5, (0xBC001006 >> 16) # lui $t5, 0xbc00
/* 0A75C0 7F072A90 35AD1006 */  ori   $t5, (0xBC001006 & 0xFFFF) # ori $t5, $t5, 0x1006
/* 0A75C4 7F072A94 246C0008 */  addiu $t4, $v1, 8
/* 0A75C8 7F072A98 AE0C000C */  sw    $t4, 0xc($s0)
/* 0A75CC 7F072A9C AC6D0000 */  sw    $t5, ($v1)
/* 0A75D0 7F072AA0 8FAF0040 */  lw    $t7, 0x40($sp)
/* 0A75D4 7F072AA4 8DE40000 */  lw    $a0, ($t7)
/* 0A75D8 7F072AA8 0C003A2C */  jal   osVirtualToPhysical
/* 0A75DC 7F072AAC AFA30038 */   sw    $v1, 0x38($sp)
/* 0A75E0 7F072AB0 8FA50038 */  lw    $a1, 0x38($sp)
/* 0A75E4 7F072AB4 3C190600 */  lui   $t9, 0x600
/* 0A75E8 7F072AB8 24010003 */  li    $at, 3
/* 0A75EC 7F072ABC ACA20004 */  sw    $v0, 4($a1)
/* 0A75F0 7F072AC0 8E03000C */  lw    $v1, 0xc($s0)
/* 0A75F4 7F072AC4 24780008 */  addiu $t8, $v1, 8
/* 0A75F8 7F072AC8 AE18000C */  sw    $t8, 0xc($s0)
/* 0A75FC 7F072ACC AC790000 */  sw    $t9, ($v1)
/* 0A7600 7F072AD0 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0A7604 7F072AD4 8DC80004 */  lw    $t0, 4($t6)
/* 0A7608 7F072AD8 AC680004 */  sw    $t0, 4($v1)
/* 0A760C 7F072ADC 86290018 */  lh    $t1, 0x18($s1)
/* 0A7610 7F072AE0 5521000F */  bnel  $t1, $at, .L7F072B20
/* 0A7614 7F072AE4 8E0F0008 */   lw    $t7, 8($s0)
/* 0A7618 7F072AE8 8E2A0004 */  lw    $t2, 4($s1)
/* 0A761C 7F072AEC 02002025 */  move  $a0, $s0
/* 0A7620 7F072AF0 5140000B */  beql  $t2, $zero, .L7F072B20
/* 0A7624 7F072AF4 8E0F0008 */   lw    $t7, 8($s0)
/* 0A7628 7F072AF8 0FC1C40C */  jal   sub_GAME_7F071030
/* 0A762C 7F072AFC 00002825 */   move  $a1, $zero
/* 0A7630 7F072B00 8E03000C */  lw    $v1, 0xc($s0)
/* 0A7634 7F072B04 3C0C0600 */  lui   $t4, 0x600
/* 0A7638 7F072B08 246B0008 */  addiu $t3, $v1, 8
/* 0A763C 7F072B0C AE0B000C */  sw    $t3, 0xc($s0)
/* 0A7640 7F072B10 AC6C0000 */  sw    $t4, ($v1)
/* 0A7644 7F072B14 8E2D0004 */  lw    $t5, 4($s1)
/* 0A7648 7F072B18 AC6D0004 */  sw    $t5, 4($v1)
/* 0A764C 7F072B1C 8E0F0008 */  lw    $t7, 8($s0)
.L7F072B20:
/* 0A7650 7F072B20 8FA4004C */  lw    $a0, 0x4c($sp)
/* 0A7654 7F072B24 31F80002 */  andi  $t8, $t7, 2
/* 0A7658 7F072B28 53000035 */  beql  $t8, $zero, .L7F072C00
/* 0A765C 7F072B2C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7660 7F072B30 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A7664 7F072B34 8FA50050 */   lw    $a1, 0x50($sp)
/* 0A7668 7F072B38 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0A766C 7F072B3C 8C590004 */  lw    $t9, 4($v0)
/* 0A7670 7F072B40 5320002F */  beql  $t9, $zero, .L7F072C00
/* 0A7674 7F072B44 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7678 7F072B48 862E0018 */  lh    $t6, 0x18($s1)
/* 0A767C 7F072B4C 24010004 */  li    $at, 4
/* 0A7680 7F072B50 55C1002B */  bnel  $t6, $at, .L7F072C00
/* 0A7684 7F072B54 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7688 7F072B58 8E280004 */  lw    $t0, 4($s1)
/* 0A768C 7F072B5C 51000028 */  beql  $t0, $zero, .L7F072C00
/* 0A7690 7F072B60 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0A7694 7F072B64 8E03000C */  lw    $v1, 0xc($s0)
/* 0A7698 7F072B68 3C0ABC00 */  lui   $t2, (0xBC001406 >> 16) # lui $t2, 0xbc00
/* 0A769C 7F072B6C 354A1406 */  ori   $t2, (0xBC001406 & 0xFFFF) # ori $t2, $t2, 0x1406
/* 0A76A0 7F072B70 24690008 */  addiu $t1, $v1, 8
/* 0A76A4 7F072B74 AE09000C */  sw    $t1, 0xc($s0)
/* 0A76A8 7F072B78 AC6A0000 */  sw    $t2, ($v1)
/* 0A76AC 7F072B7C 8E24001C */  lw    $a0, 0x1c($s1)
/* 0A76B0 7F072B80 0C003A2C */  jal   osVirtualToPhysical
/* 0A76B4 7F072B84 AFA30028 */   sw    $v1, 0x28($sp)
/* 0A76B8 7F072B88 8FA50028 */  lw    $a1, 0x28($sp)
/* 0A76BC 7F072B8C ACA20004 */  sw    $v0, 4($a1)
/* 0A76C0 7F072B90 8E0B003C */  lw    $t3, 0x3c($s0)
/* 0A76C4 7F072B94 51600004 */  beql  $t3, $zero, .L7F072BA8
/* 0A76C8 7F072B98 8E03000C */   lw    $v1, 0xc($s0)
/* 0A76CC 7F072B9C 0FC1C9BE */  jal   sub_GAME_7F0726F8
/* 0A76D0 7F072BA0 02002025 */   move  $a0, $s0
/* 0A76D4 7F072BA4 8E03000C */  lw    $v1, 0xc($s0)
.L7F072BA8:
/* 0A76D8 7F072BA8 3C0DBC00 */  lui   $t5, (0xBC001006 >> 16) # lui $t5, 0xbc00
/* 0A76DC 7F072BAC 35AD1006 */  ori   $t5, (0xBC001006 & 0xFFFF) # ori $t5, $t5, 0x1006
/* 0A76E0 7F072BB0 246C0008 */  addiu $t4, $v1, 8
/* 0A76E4 7F072BB4 AE0C000C */  sw    $t4, 0xc($s0)
/* 0A76E8 7F072BB8 AC6D0000 */  sw    $t5, ($v1)
/* 0A76EC 7F072BBC 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0A76F0 7F072BC0 8DE40000 */  lw    $a0, ($t7)
/* 0A76F4 7F072BC4 0C003A2C */  jal   osVirtualToPhysical
/* 0A76F8 7F072BC8 AFA30024 */   sw    $v1, 0x24($sp)
/* 0A76FC 7F072BCC 8FA60024 */  lw    $a2, 0x24($sp)
/* 0A7700 7F072BD0 02002025 */  move  $a0, $s0
/* 0A7704 7F072BD4 00002825 */  move  $a1, $zero
/* 0A7708 7F072BD8 0FC1C6D1 */  jal   sub_GAME_7F071B44
/* 0A770C 7F072BDC ACC20004 */   sw    $v0, 4($a2)
/* 0A7710 7F072BE0 8E03000C */  lw    $v1, 0xc($s0)
/* 0A7714 7F072BE4 3C190600 */  lui   $t9, 0x600
/* 0A7718 7F072BE8 24780008 */  addiu $t8, $v1, 8
/* 0A771C 7F072BEC AE18000C */  sw    $t8, 0xc($s0)
/* 0A7720 7F072BF0 AC790000 */  sw    $t9, ($v1)
/* 0A7724 7F072BF4 8E2E0004 */  lw    $t6, 4($s1)
/* 0A7728 7F072BF8 AC6E0004 */  sw    $t6, 4($v1)
/* 0A772C 7F072BFC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F072C00:
/* 0A7730 7F072C00 8FB00014 */  lw    $s0, 0x14($sp)
/* 0A7734 7F072C04 8FB10018 */  lw    $s1, 0x18($sp)
/* 0A7738 7F072C08 03E00008 */  jr    $ra
/* 0A773C 7F072C0C 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F072C10(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F072C10
/* 0A7740 7F072C10 AFA40000 */  sw    $a0, ($sp)
/* 0A7744 7F072C14 AFA50004 */  sw    $a1, 4($sp)
/* 0A7748 7F072C18 03E00008 */  jr    $ra
/* 0A774C 7F072C1C AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void dorottex(void) {

}
#else
GLOBAL_ASM(
.text
glabel dorottex
/* 0A7750 7F072C20 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0A7754 7F072C24 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0A7758 7F072C28 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0A775C 7F072C2C AFB70034 */  sw    $s7, 0x34($sp)
/* 0A7760 7F072C30 AFB60030 */  sw    $s6, 0x30($sp)
/* 0A7764 7F072C34 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0A7768 7F072C38 AFB40028 */  sw    $s4, 0x28($sp)
/* 0A776C 7F072C3C AFB30024 */  sw    $s3, 0x24($sp)
/* 0A7770 7F072C40 AFB20020 */  sw    $s2, 0x20($sp)
/* 0A7774 7F072C44 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A7778 7F072C48 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A777C 7F072C4C 8C8E0018 */  lw    $t6, 0x18($a0)
/* 0A7780 7F072C50 00809825 */  move  $s3, $a0
/* 0A7784 7F072C54 55C000ED */  bnezl $t6, .L7F07300C
/* 0A7788 7F072C58 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0A778C 7F072C5C 8C8F0008 */  lw    $t7, 8($a0)
/* 0A7790 7F072C60 31F80002 */  andi  $t8, $t7, 2
/* 0A7794 7F072C64 530000E9 */  beql  $t8, $zero, .L7F07300C
/* 0A7798 7F072C68 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0A779C 7F072C6C 8CA30004 */  lw    $v1, 4($a1)
/* 0A77A0 7F072C70 3C028003 */  lui   $v0, %hi(D_8003608C)
/* 0A77A4 7F072C74 8C790008 */  lw    $t9, 8($v1)
/* 0A77A8 7F072C78 532000E4 */  beql  $t9, $zero, .L7F07300C
/* 0A77AC 7F072C7C 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0A77B0 7F072C80 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
/* 0A77B4 7F072C84 3C048005 */  lui   $a0, %hi(aDorottexNoVtxAllocator)
/* 0A77B8 7F072C88 8C720004 */  lw    $s2, 4($v1)
/* 0A77BC 7F072C8C 10400003 */  beqz  $v0, .L7F072C9C
/* 0A77C0 7F072C90 24844A38 */   addiu $a0, %lo(aDorottexNoVtxAllocator) # addiu $a0, $a0, 0x4a38
/* 0A77C4 7F072C94 10000007 */  b     .L7F072CB4
/* 0A77C8 7F072C98 AFA30044 */   sw    $v1, 0x44($sp)
.L7F072C9C:
/* 0A77CC 7F072C9C 0C0033D1 */  jal   osSyncPrintf
/* 0A77D0 7F072CA0 AFA30044 */   sw    $v1, 0x44($sp)
/* 0A77D4 7F072CA4 0FC1B11B */  jal   return_null
/* 0A77D8 7F072CA8 00000000 */   nop   
/* 0A77DC 7F072CAC 3C028003 */  lui   $v0, %hi(D_8003608C)
/* 0A77E0 7F072CB0 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
.L7F072CB4:
/* 0A77E4 7F072CB4 8FA30044 */  lw    $v1, 0x44($sp)
/* 0A77E8 7F072CB8 8C640000 */  lw    $a0, ($v1)
/* 0A77EC 7F072CBC 00044880 */  sll   $t1, $a0, 2
/* 0A77F0 7F072CC0 0040F809 */  jalr  $v0
/* 0A77F4 7F072CC4 01202025 */  move  $a0, $t1
/* 0A77F8 7F072CC8 8E74000C */  lw    $s4, 0xc($s3)
/* 0A77FC 7F072CCC 3C0BBC00 */  lui   $t3, (0xBC001006 >> 16) # lui $t3, 0xbc00
/* 0A7800 7F072CD0 356B1006 */  ori   $t3, (0xBC001006 & 0xFFFF) # ori $t3, $t3, 0x1006
/* 0A7804 7F072CD4 268A0008 */  addiu $t2, $s4, 8
/* 0A7808 7F072CD8 AE6A000C */  sw    $t2, 0xc($s3)
/* 0A780C 7F072CDC 00408025 */  move  $s0, $v0
/* 0A7810 7F072CE0 00402025 */  move  $a0, $v0
/* 0A7814 7F072CE4 0C003A2C */  jal   osVirtualToPhysical
/* 0A7818 7F072CE8 AE8B0000 */   sw    $t3, ($s4)
/* 0A781C 7F072CEC AE820004 */  sw    $v0, 4($s4)
/* 0A7820 7F072CF0 8E76000C */  lw    $s6, 0xc($s3)
/* 0A7824 7F072CF4 3C0DBC00 */  lui   $t5, (0xBC001406 >> 16) # lui $t5, 0xbc00
/* 0A7828 7F072CF8 35AD1406 */  ori   $t5, (0xBC001406 & 0xFFFF) # ori $t5, $t5, 0x1406
/* 0A782C 7F072CFC 26CC0008 */  addiu $t4, $s6, 8
/* 0A7830 7F072D00 AE6C000C */  sw    $t4, 0xc($s3)
/* 0A7834 7F072D04 AECD0000 */  sw    $t5, ($s6)
/* 0A7838 7F072D08 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0A783C 7F072D0C 0C003A2C */  jal   osVirtualToPhysical
/* 0A7840 7F072D10 8DC4000C */   lw    $a0, 0xc($t6)
/* 0A7844 7F072D14 8FA50044 */  lw    $a1, 0x44($sp)
/* 0A7848 7F072D18 AEC20004 */  sw    $v0, 4($s6)
/* 0A784C 7F072D1C 8E71000C */  lw    $s1, 0xc($s3)
/* 0A7850 7F072D20 3C18F800 */  lui   $t8, 0xf800
/* 0A7854 7F072D24 3C090600 */  lui   $t1, 0x600
/* 0A7858 7F072D28 262F0008 */  addiu $t7, $s1, 8
/* 0A785C 7F072D2C AE6F000C */  sw    $t7, 0xc($s3)
/* 0A7860 7F072D30 AE200004 */  sw    $zero, 4($s1)
/* 0A7864 7F072D34 AE380000 */  sw    $t8, ($s1)
/* 0A7868 7F072D38 8E71000C */  lw    $s1, 0xc($s3)
/* 0A786C 7F072D3C 241600B5 */  li    $s6, 181
/* 0A7870 7F072D40 0000A825 */  move  $s5, $zero
/* 0A7874 7F072D44 26390008 */  addiu $t9, $s1, 8
/* 0A7878 7F072D48 AE79000C */  sw    $t9, 0xc($s3)
/* 0A787C 7F072D4C AE290000 */  sw    $t1, ($s1)
/* 0A7880 7F072D50 8CAA0008 */  lw    $t2, 8($a1)
/* 0A7884 7F072D54 3C1E0001 */  lui   $fp, 1
/* 0A7888 7F072D58 24170200 */  li    $s7, 512
/* 0A788C 7F072D5C AE2A0004 */  sw    $t2, 4($s1)
/* 0A7890 7F072D60 8CAB0000 */  lw    $t3, ($a1)
/* 0A7894 7F072D64 596000A9 */  blezl $t3, .L7F07300C
/* 0A7898 7F072D68 8FBF003C */   lw    $ra, 0x3c($sp)
.L7F072D6C:
/* 0A789C 7F072D6C 0C002914 */  jal   get_random_value
/* 0A78A0 7F072D70 00000000 */   nop   
/* 0A78A4 7F072D74 00026280 */  sll   $t4, $v0, 0xa
/* 0A78A8 7F072D78 3191FFFF */  andi  $s1, $t4, 0xffff
/* 0A78AC 7F072D7C 0C005B0C */  jal   coss
/* 0A78B0 7F072D80 3184FFFF */   andi  $a0, $t4, 0xffff
/* 0A78B4 7F072D84 00026940 */  sll   $t5, $v0, 5
/* 0A78B8 7F072D88 01B60019 */  multu $t5, $s6
/* 0A78BC 7F072D8C 3224FFFF */  andi  $a0, $s1, 0xffff
/* 0A78C0 7F072D90 0000A012 */  mflo  $s4
/* 0A78C4 7F072D94 00147483 */  sra   $t6, $s4, 0x12
/* 0A78C8 7F072D98 0C005B18 */  jal   sins
/* 0A78CC 7F072D9C 01C0A025 */   move  $s4, $t6
/* 0A78D0 7F072DA0 00027940 */  sll   $t7, $v0, 5
/* 0A78D4 7F072DA4 01F60019 */  multu $t7, $s6
/* 0A78D8 7F072DA8 00009812 */  mflo  $s3
/* 0A78DC 7F072DAC 0013C483 */  sra   $t8, $s3, 0x12
/* 0A78E0 7F072DB0 0C002914 */  jal   get_random_value
/* 0A78E4 7F072DB4 03009825 */   move  $s3, $t8
/* 0A78E8 7F072DB8 0C002914 */  jal   get_random_value
/* 0A78EC 7F072DBC 00028FC2 */   srl   $s1, $v0, 0x1f
/* 0A78F0 7F072DC0 8E410000 */  lw    $at, ($s2)
/* 0A78F4 7F072DC4 30593FFF */  andi  $t9, $v0, 0x3fff
/* 0A78F8 7F072DC8 03D92023 */  subu  $a0, $fp, $t9
/* 0A78FC 7F072DCC AE010000 */  sw    $at, ($s0)
/* 0A7900 7F072DD0 8E4A0004 */  lw    $t2, 4($s2)
/* 0A7904 7F072DD4 02F44023 */  subu  $t0, $s7, $s4
/* 0A7908 7F072DD8 02F33823 */  subu  $a3, $s7, $s3
/* 0A790C 7F072DDC AE0A0004 */  sw    $t2, 4($s0)
/* 0A7910 7F072DE0 8E410008 */  lw    $at, 8($s2)
/* 0A7914 7F072DE4 00801825 */  move  $v1, $a0
/* 0A7918 7F072DE8 26660200 */  addiu $a2, $s3, 0x200
/* 0A791C 7F072DEC AE010008 */  sw    $at, 8($s0)
/* 0A7920 7F072DF0 8E4A000C */  lw    $t2, 0xc($s2)
/* 0A7924 7F072DF4 26B50001 */  addiu $s5, $s5, 1
/* 0A7928 7F072DF8 26100040 */  addiu $s0, $s0, 0x40
/* 0A792C 7F072DFC AE0AFFCC */  sw    $t2, -0x34($s0)
/* 0A7930 7F072E00 8E410010 */  lw    $at, 0x10($s2)
/* 0A7934 7F072E04 AE01FFD0 */  sw    $at, -0x30($s0)
/* 0A7938 7F072E08 8E4C0014 */  lw    $t4, 0x14($s2)
/* 0A793C 7F072E0C AE0CFFD4 */  sw    $t4, -0x2c($s0)
/* 0A7940 7F072E10 8E410018 */  lw    $at, 0x18($s2)
/* 0A7944 7F072E14 AE01FFD8 */  sw    $at, -0x28($s0)
/* 0A7948 7F072E18 8E4C001C */  lw    $t4, 0x1c($s2)
/* 0A794C 7F072E1C AE0CFFDC */  sw    $t4, -0x24($s0)
/* 0A7950 7F072E20 8E410020 */  lw    $at, 0x20($s2)
/* 0A7954 7F072E24 AE01FFE0 */  sw    $at, -0x20($s0)
/* 0A7958 7F072E28 8E4E0024 */  lw    $t6, 0x24($s2)
/* 0A795C 7F072E2C AE0EFFE4 */  sw    $t6, -0x1c($s0)
/* 0A7960 7F072E30 8E410028 */  lw    $at, 0x28($s2)
/* 0A7964 7F072E34 AE01FFE8 */  sw    $at, -0x18($s0)
/* 0A7968 7F072E38 8E4E002C */  lw    $t6, 0x2c($s2)
/* 0A796C 7F072E3C AE0EFFEC */  sw    $t6, -0x14($s0)
/* 0A7970 7F072E40 8E410030 */  lw    $at, 0x30($s2)
/* 0A7974 7F072E44 AE01FFF0 */  sw    $at, -0x10($s0)
/* 0A7978 7F072E48 8E580034 */  lw    $t8, 0x34($s2)
/* 0A797C 7F072E4C AE18FFF4 */  sw    $t8, -0xc($s0)
/* 0A7980 7F072E50 8E410038 */  lw    $at, 0x38($s2)
/* 0A7984 7F072E54 AE01FFF8 */  sw    $at, -8($s0)
/* 0A7988 7F072E58 8E58003C */  lw    $t8, 0x3c($s2)
/* 0A798C 7F072E5C A608FFC8 */  sh    $t0, -0x38($s0)
/* 0A7990 7F072E60 A607FFCA */  sh    $a3, -0x36($s0)
/* 0A7994 7F072E64 AE18FFFC */  sw    $t8, -4($s0)
/* 0A7998 7F072E68 06210004 */  bgez  $s1, .L7F072E7C
/* 0A799C 7F072E6C 32390003 */   andi  $t9, $s1, 3
/* 0A79A0 7F072E70 13200002 */  beqz  $t9, .L7F072E7C
/* 0A79A4 7F072E74 00000000 */   nop   
/* 0A79A8 7F072E78 2739FFFC */  addiu $t9, $t9, -4
.L7F072E7C:
/* 0A79AC 7F072E7C 00194900 */  sll   $t1, $t9, 4
/* 0A79B0 7F072E80 02492821 */  addu  $a1, $s2, $t1
/* 0A79B4 7F072E84 84AA0000 */  lh    $t2, ($a1)
/* 0A79B8 7F072E88 01440019 */  multu $t2, $a0
/* 0A79BC 7F072E8C 262A0001 */  addiu $t2, $s1, 1
/* 0A79C0 7F072E90 00005812 */  mflo  $t3
/* 0A79C4 7F072E94 000B6403 */  sra   $t4, $t3, 0x10
/* 0A79C8 7F072E98 A60CFFC0 */  sh    $t4, -0x40($s0)
/* 0A79CC 7F072E9C 84AD0002 */  lh    $t5, 2($a1)
/* 0A79D0 7F072EA0 01A40019 */  multu $t5, $a0
/* 0A79D4 7F072EA4 26840200 */  addiu $a0, $s4, 0x200
/* 0A79D8 7F072EA8 00007012 */  mflo  $t6
/* 0A79DC 7F072EAC 000E7C03 */  sra   $t7, $t6, 0x10
/* 0A79E0 7F072EB0 A60FFFC2 */  sh    $t7, -0x3e($s0)
/* 0A79E4 7F072EB4 84B80004 */  lh    $t8, 4($a1)
/* 0A79E8 7F072EB8 A606FFD8 */  sh    $a2, -0x28($s0)
/* 0A79EC 7F072EBC A608FFDA */  sh    $t0, -0x26($s0)
/* 0A79F0 7F072EC0 03030019 */  multu $t8, $v1
/* 0A79F4 7F072EC4 0000C812 */  mflo  $t9
/* 0A79F8 7F072EC8 00194C03 */  sra   $t1, $t9, 0x10
/* 0A79FC 7F072ECC A609FFC4 */  sh    $t1, -0x3c($s0)
/* 0A7A00 7F072ED0 05410004 */  bgez  $t2, .L7F072EE4
/* 0A7A04 7F072ED4 314B0003 */   andi  $t3, $t2, 3
/* 0A7A08 7F072ED8 11600002 */  beqz  $t3, .L7F072EE4
/* 0A7A0C 7F072EDC 00000000 */   nop   
/* 0A7A10 7F072EE0 256BFFFC */  addiu $t3, $t3, -4
.L7F072EE4:
/* 0A7A14 7F072EE4 000B6100 */  sll   $t4, $t3, 4
/* 0A7A18 7F072EE8 024C1021 */  addu  $v0, $s2, $t4
/* 0A7A1C 7F072EEC 844D0000 */  lh    $t5, ($v0)
/* 0A7A20 7F072EF0 01A30019 */  multu $t5, $v1
/* 0A7A24 7F072EF4 262D0002 */  addiu $t5, $s1, 2
/* 0A7A28 7F072EF8 00007012 */  mflo  $t6
/* 0A7A2C 7F072EFC 000E7C03 */  sra   $t7, $t6, 0x10
/* 0A7A30 7F072F00 A60FFFD0 */  sh    $t7, -0x30($s0)
/* 0A7A34 7F072F04 84580002 */  lh    $t8, 2($v0)
/* 0A7A38 7F072F08 03030019 */  multu $t8, $v1
/* 0A7A3C 7F072F0C 0000C812 */  mflo  $t9
/* 0A7A40 7F072F10 00194C03 */  sra   $t1, $t9, 0x10
/* 0A7A44 7F072F14 A609FFD2 */  sh    $t1, -0x2e($s0)
/* 0A7A48 7F072F18 844A0004 */  lh    $t2, 4($v0)
/* 0A7A4C 7F072F1C A604FFE8 */  sh    $a0, -0x18($s0)
/* 0A7A50 7F072F20 A606FFEA */  sh    $a2, -0x16($s0)
/* 0A7A54 7F072F24 01430019 */  multu $t2, $v1
/* 0A7A58 7F072F28 00005812 */  mflo  $t3
/* 0A7A5C 7F072F2C 000B6403 */  sra   $t4, $t3, 0x10
/* 0A7A60 7F072F30 A60CFFD4 */  sh    $t4, -0x2c($s0)
/* 0A7A64 7F072F34 05A10004 */  bgez  $t5, .L7F072F48
/* 0A7A68 7F072F38 31AE0003 */   andi  $t6, $t5, 3
/* 0A7A6C 7F072F3C 11C00002 */  beqz  $t6, .L7F072F48
/* 0A7A70 7F072F40 00000000 */   nop   
/* 0A7A74 7F072F44 25CEFFFC */  addiu $t6, $t6, -4
.L7F072F48:
/* 0A7A78 7F072F48 000E7900 */  sll   $t7, $t6, 4
/* 0A7A7C 7F072F4C 024F1021 */  addu  $v0, $s2, $t7
/* 0A7A80 7F072F50 84580000 */  lh    $t8, ($v0)
/* 0A7A84 7F072F54 03030019 */  multu $t8, $v1
/* 0A7A88 7F072F58 26380003 */  addiu $t8, $s1, 3
/* 0A7A8C 7F072F5C 0000C812 */  mflo  $t9
/* 0A7A90 7F072F60 00194C03 */  sra   $t1, $t9, 0x10
/* 0A7A94 7F072F64 A609FFE0 */  sh    $t1, -0x20($s0)
/* 0A7A98 7F072F68 844A0002 */  lh    $t2, 2($v0)
/* 0A7A9C 7F072F6C 01430019 */  multu $t2, $v1
/* 0A7AA0 7F072F70 00005812 */  mflo  $t3
/* 0A7AA4 7F072F74 000B6403 */  sra   $t4, $t3, 0x10
/* 0A7AA8 7F072F78 A60CFFE2 */  sh    $t4, -0x1e($s0)
/* 0A7AAC 7F072F7C 844D0004 */  lh    $t5, 4($v0)
/* 0A7AB0 7F072F80 A607FFF8 */  sh    $a3, -8($s0)
/* 0A7AB4 7F072F84 A604FFFA */  sh    $a0, -6($s0)
/* 0A7AB8 7F072F88 01A30019 */  multu $t5, $v1
/* 0A7ABC 7F072F8C 00007012 */  mflo  $t6
/* 0A7AC0 7F072F90 000E7C03 */  sra   $t7, $t6, 0x10
/* 0A7AC4 7F072F94 A60FFFE4 */  sh    $t7, -0x1c($s0)
/* 0A7AC8 7F072F98 07010004 */  bgez  $t8, .L7F072FAC
/* 0A7ACC 7F072F9C 33190003 */   andi  $t9, $t8, 3
/* 0A7AD0 7F072FA0 13200002 */  beqz  $t9, .L7F072FAC
/* 0A7AD4 7F072FA4 00000000 */   nop   
/* 0A7AD8 7F072FA8 2739FFFC */  addiu $t9, $t9, -4
.L7F072FAC:
/* 0A7ADC 7F072FAC 00194900 */  sll   $t1, $t9, 4
/* 0A7AE0 7F072FB0 02491021 */  addu  $v0, $s2, $t1
/* 0A7AE4 7F072FB4 844A0000 */  lh    $t2, ($v0)
/* 0A7AE8 7F072FB8 26520040 */  addiu $s2, $s2, 0x40
/* 0A7AEC 7F072FBC 01430019 */  multu $t2, $v1
/* 0A7AF0 7F072FC0 00005812 */  mflo  $t3
/* 0A7AF4 7F072FC4 000B6403 */  sra   $t4, $t3, 0x10
/* 0A7AF8 7F072FC8 A60CFFF0 */  sh    $t4, -0x10($s0)
/* 0A7AFC 7F072FCC 844D0002 */  lh    $t5, 2($v0)
/* 0A7B00 7F072FD0 01A30019 */  multu $t5, $v1
/* 0A7B04 7F072FD4 00007012 */  mflo  $t6
/* 0A7B08 7F072FD8 000E7C03 */  sra   $t7, $t6, 0x10
/* 0A7B0C 7F072FDC A60FFFF2 */  sh    $t7, -0xe($s0)
/* 0A7B10 7F072FE0 84580004 */  lh    $t8, 4($v0)
/* 0A7B14 7F072FE4 03030019 */  multu $t8, $v1
/* 0A7B18 7F072FE8 0000C812 */  mflo  $t9
/* 0A7B1C 7F072FEC 00194C03 */  sra   $t1, $t9, 0x10
/* 0A7B20 7F072FF0 A609FFF4 */  sh    $t1, -0xc($s0)
/* 0A7B24 7F072FF4 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0A7B28 7F072FF8 8D4B0000 */  lw    $t3, ($t2)
/* 0A7B2C 7F072FFC 02AB082A */  slt   $at, $s5, $t3
/* 0A7B30 7F073000 1420FF5A */  bnez  $at, .L7F072D6C
/* 0A7B34 7F073004 00000000 */   nop   
/* 0A7B38 7F073008 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F07300C:
/* 0A7B3C 7F07300C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A7B40 7F073010 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A7B44 7F073014 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A7B48 7F073018 8FB30024 */  lw    $s3, 0x24($sp)
/* 0A7B4C 7F07301C 8FB40028 */  lw    $s4, 0x28($sp)
/* 0A7B50 7F073020 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0A7B54 7F073024 8FB60030 */  lw    $s6, 0x30($sp)
/* 0A7B58 7F073028 8FB70034 */  lw    $s7, 0x34($sp)
/* 0A7B5C 7F07302C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0A7B60 7F073030 03E00008 */  jr    $ra
/* 0A7B64 7F073034 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F073038(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F073038
/* 0A7B68 7F073038 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A7B6C 7F07303C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A7B70 7F073040 AFA40020 */  sw    $a0, 0x20($sp)
/* 0A7B74 7F073044 00807025 */  move  $t6, $a0
/* 0A7B78 7F073048 8DC70004 */  lw    $a3, 4($t6)
/* 0A7B7C 7F07304C 240F0002 */  li    $t7, 2
/* 0A7B80 7F073050 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0A7B84 7F073054 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0A7B88 7F073058 2484000C */   addiu $a0, $a0, 0xc
/* 0A7B8C 7F07305C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A7B90 7F073060 27BD0020 */  addiu $sp, $sp, 0x20
/* 0A7B94 7F073064 03E00008 */  jr    $ra
/* 0A7B98 7F073068 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F07306C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F07306C
/* 0A7B9C 7F07306C AFA40000 */  sw    $a0, ($sp)
/* 0A7BA0 7F073070 AFA50004 */  sw    $a1, 4($sp)
/* 0A7BA4 7F073074 03E00008 */  jr    $ra
/* 0A7BA8 7F073078 AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void dotube(void) {

}
#else
GLOBAL_ASM(
.text
glabel dotube
/* 0A7BAC 7F07307C 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0A7BB0 7F073080 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0A7BB4 7F073084 0080A825 */  move  $s5, $a0
/* 0A7BB8 7F073088 AFB30024 */  sw    $s3, 0x24($sp)
/* 0A7BBC 7F07308C 00A09825 */  move  $s3, $a1
/* 0A7BC0 7F073090 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0A7BC4 7F073094 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0A7BC8 7F073098 AFB70034 */  sw    $s7, 0x34($sp)
/* 0A7BCC 7F07309C AFB60030 */  sw    $s6, 0x30($sp)
/* 0A7BD0 7F0730A0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0A7BD4 7F0730A4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0A7BD8 7F0730A8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A7BDC 7F0730AC AFB00018 */  sw    $s0, 0x18($sp)
/* 0A7BE0 7F0730B0 00A02025 */  move  $a0, $a1
/* 0A7BE4 7F0730B4 00C08825 */  move  $s1, $a2
/* 0A7BE8 7F0730B8 8CD60004 */  lw    $s6, 4($a2)
/* 0A7BEC 7F0730BC 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A7BF0 7F0730C0 00C02825 */   move  $a1, $a2
/* 0A7BF4 7F0730C4 8EC30000 */  lw    $v1, ($s6)
/* 0A7BF8 7F0730C8 00409025 */  move  $s2, $v0
/* 0A7BFC 7F0730CC 50600004 */  beql  $v1, $zero, .L7F0730E0
/* 0A7C00 7F0730D0 8EC50004 */   lw    $a1, 4($s6)
/* 0A7C04 7F0730D4 10000002 */  b     .L7F0730E0
/* 0A7C08 7F0730D8 00602825 */   move  $a1, $v1
/* 0A7C0C 7F0730DC 8EC50004 */  lw    $a1, 4($s6)
.L7F0730E0:
/* 0A7C10 7F0730E0 8CAE0004 */  lw    $t6, 4($a1)
/* 0A7C14 7F0730E4 02602025 */  move  $a0, $s3
/* 0A7C18 7F0730E8 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A7C1C 7F0730EC AFAE00C0 */   sw    $t6, 0xc0($sp)
/* 0A7C20 7F0730F0 240F0001 */  li    $t7, 1
/* 0A7C24 7F0730F4 AFAF009C */  sw    $t7, 0x9c($sp)
/* 0A7C28 7F0730F8 8EB80008 */  lw    $t8, 8($s5)
/* 0A7C2C 7F0730FC 00408025 */  move  $s0, $v0
/* 0A7C30 7F073100 02202025 */  move  $a0, $s1
/* 0A7C34 7F073104 33190001 */  andi  $t9, $t8, 1
/* 0A7C38 7F073108 532001AD */  beql  $t9, $zero, .L7F0737C0
/* 0A7C3C 7F07310C 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0A7C40 7F073110 0FC1B15C */  jal   sub_GAME_7F06C570
/* 0A7C44 7F073114 00002825 */   move  $a1, $zero
/* 0A7C48 7F073118 8E68000C */  lw    $t0, 0xc($s3)
/* 0A7C4C 7F07311C 00024980 */  sll   $t1, $v0, 6
/* 0A7C50 7F073120 24050200 */  li    $a1, 512
/* 0A7C54 7F073124 01095021 */  addu  $t2, $t0, $t1
/* 0A7C58 7F073128 AFAA0084 */  sw    $t2, 0x84($sp)
/* 0A7C5C 7F07312C 8E430000 */  lw    $v1, ($s2)
/* 0A7C60 7F073130 8ECD0000 */  lw    $t5, ($s6)
/* 0A7C64 7F073134 8ECB000C */  lw    $t3, 0xc($s6)
/* 0A7C68 7F073138 000360C0 */  sll   $t4, $v1, 3
/* 0A7C6C 7F07313C 8E060000 */  lw    $a2, ($s0)
/* 0A7C70 7F073140 11A00008 */  beqz  $t5, .L7F073164
/* 0A7C74 7F073144 016CF021 */   addu  $fp, $t3, $t4
/* 0A7C78 7F073148 00C09025 */  move  $s2, $a2
/* 0A7C7C 7F07314C 00608025 */  move  $s0, $v1
/* 0A7C80 7F073150 02202025 */  move  $a0, $s1
/* 0A7C84 7F073154 0FC1B15C */  jal   sub_GAME_7F06C570
/* 0A7C88 7F073158 24050200 */   li    $a1, 512
/* 0A7C8C 7F07315C 10000006 */  b     .L7F073178
/* 0A7C90 7F073160 8E6E000C */   lw    $t6, 0xc($s3)
.L7F073164:
/* 0A7C94 7F073164 00609025 */  move  $s2, $v1
/* 0A7C98 7F073168 00C08025 */  move  $s0, $a2
/* 0A7C9C 7F07316C 0FC1B15C */  jal   sub_GAME_7F06C570
/* 0A7CA0 7F073170 8EC40004 */   lw    $a0, 4($s6)
/* 0A7CA4 7F073174 8E6E000C */  lw    $t6, 0xc($s3)
.L7F073178:
/* 0A7CA8 7F073178 00027980 */  sll   $t7, $v0, 6
/* 0A7CAC 7F07317C 0212C823 */  subu  $t9, $s0, $s2
/* 0A7CB0 7F073180 01CFC021 */  addu  $t8, $t6, $t7
/* 0A7CB4 7F073184 AFB80080 */  sw    $t8, 0x80($sp)
/* 0A7CB8 7F073188 8EC30008 */  lw    $v1, 8($s6)
/* 0A7CBC 7F07318C 03234021 */  addu  $t0, $t9, $v1
/* 0A7CC0 7F073190 0103001A */  div   $zero, $t0, $v1
/* 0A7CC4 7F073194 14600002 */  bnez  $v1, .L7F0731A0
/* 0A7CC8 7F073198 00000000 */   nop   
/* 0A7CCC 7F07319C 0007000D */  break 7
.L7F0731A0:
/* 0A7CD0 7F0731A0 2401FFFF */  li    $at, -1
/* 0A7CD4 7F0731A4 14610004 */  bne   $v1, $at, .L7F0731B8
/* 0A7CD8 7F0731A8 3C018000 */   lui   $at, 0x8000
/* 0A7CDC 7F0731AC 15010002 */  bne   $t0, $at, .L7F0731B8
/* 0A7CE0 7F0731B0 00000000 */   nop   
/* 0A7CE4 7F0731B4 0006000D */  break 6
.L7F0731B8:
/* 0A7CE8 7F0731B8 00002810 */  mfhi  $a1
/* 0A7CEC 7F0731BC 28A10002 */  slti  $at, $a1, 2
/* 0A7CF0 7F0731C0 1420002E */  bnez  $at, .L7F07327C
/* 0A7CF4 7F0731C4 28A10007 */   slti  $at, $a1, 7
/* 0A7CF8 7F0731C8 1020002C */  beqz  $at, .L7F07327C
/* 0A7CFC 7F0731CC 28A10004 */   slti  $at, $a1, 4
/* 0A7D00 7F0731D0 50200015 */  beql  $at, $zero, .L7F073228
/* 0A7D04 7F0731D4 240C0008 */   li    $t4, 8
/* 0A7D08 7F0731D8 04A10003 */  bgez  $a1, .L7F0731E8
/* 0A7D0C 7F0731DC 00054843 */   sra   $t1, $a1, 1
/* 0A7D10 7F0731E0 24A10001 */  addiu $at, $a1, 1
/* 0A7D14 7F0731E4 00014843 */  sra   $t1, $at, 1
.L7F0731E8:
/* 0A7D18 7F0731E8 01325021 */  addu  $t2, $t1, $s2
/* 0A7D1C 7F0731EC 01435821 */  addu  $t3, $t2, $v1
/* 0A7D20 7F0731F0 0163001A */  div   $zero, $t3, $v1
/* 0A7D24 7F0731F4 00002810 */  mfhi  $a1
/* 0A7D28 7F0731F8 14600002 */  bnez  $v1, .L7F073204
/* 0A7D2C 7F0731FC 00000000 */   nop   
/* 0A7D30 7F073200 0007000D */  break 7
.L7F073204:
/* 0A7D34 7F073204 2401FFFF */  li    $at, -1
/* 0A7D38 7F073208 14610004 */  bne   $v1, $at, .L7F07321C
/* 0A7D3C 7F07320C 3C018000 */   lui   $at, 0x8000
/* 0A7D40 7F073210 15610002 */  bne   $t3, $at, .L7F07321C
/* 0A7D44 7F073214 00000000 */   nop   
/* 0A7D48 7F073218 0006000D */  break 6
.L7F07321C:
/* 0A7D4C 7F07321C 10000050 */  b     .L7F073360
/* 0A7D50 7F073220 8EB1000C */   lw    $s1, 0xc($s5)
/* 0A7D54 7F073224 240C0008 */  li    $t4, 8
.L7F073228:
/* 0A7D58 7F073228 01856823 */  subu  $t5, $t4, $a1
/* 0A7D5C 7F07322C 05A10003 */  bgez  $t5, .L7F07323C
/* 0A7D60 7F073230 000D7043 */   sra   $t6, $t5, 1
/* 0A7D64 7F073234 25A10001 */  addiu $at, $t5, 1
/* 0A7D68 7F073238 00017043 */  sra   $t6, $at, 1
.L7F07323C:
/* 0A7D6C 7F07323C 024E7823 */  subu  $t7, $s2, $t6
/* 0A7D70 7F073240 01E3C021 */  addu  $t8, $t7, $v1
/* 0A7D74 7F073244 0303001A */  div   $zero, $t8, $v1
/* 0A7D78 7F073248 00002810 */  mfhi  $a1
/* 0A7D7C 7F07324C AFA0009C */  sw    $zero, 0x9c($sp)
/* 0A7D80 7F073250 14600002 */  bnez  $v1, .L7F07325C
/* 0A7D84 7F073254 00000000 */   nop   
/* 0A7D88 7F073258 0007000D */  break 7
.L7F07325C:
/* 0A7D8C 7F07325C 2401FFFF */  li    $at, -1
/* 0A7D90 7F073260 14610004 */  bne   $v1, $at, .L7F073274
/* 0A7D94 7F073264 3C018000 */   lui   $at, 0x8000
/* 0A7D98 7F073268 17010002 */  bne   $t8, $at, .L7F073274
/* 0A7D9C 7F07326C 00000000 */   nop   
/* 0A7DA0 7F073270 0006000D */  break 6
.L7F073274:
/* 0A7DA4 7F073274 1000003A */  b     .L7F073360
/* 0A7DA8 7F073278 8EB1000C */   lw    $s1, 0xc($s5)
.L7F07327C:
/* 0A7DAC 7F07327C 28A1000A */  slti  $at, $a1, 0xa
/* 0A7DB0 7F073280 1420002F */  bnez  $at, .L7F073340
/* 0A7DB4 7F073284 28A1000F */   slti  $at, $a1, 0xf
/* 0A7DB8 7F073288 1020002D */  beqz  $at, .L7F073340
/* 0A7DBC 7F07328C 28A1000D */   slti  $at, $a1, 0xd
/* 0A7DC0 7F073290 54200017 */  bnezl $at, .L7F0732F0
/* 0A7DC4 7F073294 24ACFFF8 */   addiu $t4, $a1, -8
/* 0A7DC8 7F073298 24190010 */  li    $t9, 16
/* 0A7DCC 7F07329C 03254023 */  subu  $t0, $t9, $a1
/* 0A7DD0 7F0732A0 05010003 */  bgez  $t0, .L7F0732B0
/* 0A7DD4 7F0732A4 00084843 */   sra   $t1, $t0, 1
/* 0A7DD8 7F0732A8 25010001 */  addiu $at, $t0, 1
/* 0A7DDC 7F0732AC 00014843 */  sra   $t1, $at, 1
.L7F0732B0:
/* 0A7DE0 7F0732B0 02495023 */  subu  $t2, $s2, $t1
/* 0A7DE4 7F0732B4 01435821 */  addu  $t3, $t2, $v1
/* 0A7DE8 7F0732B8 0163001A */  div   $zero, $t3, $v1
/* 0A7DEC 7F0732BC 00002810 */  mfhi  $a1
/* 0A7DF0 7F0732C0 14600002 */  bnez  $v1, .L7F0732CC
/* 0A7DF4 7F0732C4 00000000 */   nop   
/* 0A7DF8 7F0732C8 0007000D */  break 7
.L7F0732CC:
/* 0A7DFC 7F0732CC 2401FFFF */  li    $at, -1
/* 0A7E00 7F0732D0 14610004 */  bne   $v1, $at, .L7F0732E4
/* 0A7E04 7F0732D4 3C018000 */   lui   $at, 0x8000
/* 0A7E08 7F0732D8 15610002 */  bne   $t3, $at, .L7F0732E4
/* 0A7E0C 7F0732DC 00000000 */   nop   
/* 0A7E10 7F0732E0 0006000D */  break 6
.L7F0732E4:
/* 0A7E14 7F0732E4 1000001E */  b     .L7F073360
/* 0A7E18 7F0732E8 8EB1000C */   lw    $s1, 0xc($s5)
/* 0A7E1C 7F0732EC 24ACFFF8 */  addiu $t4, $a1, -8
.L7F0732F0:
/* 0A7E20 7F0732F0 05810003 */  bgez  $t4, .L7F073300
/* 0A7E24 7F0732F4 000C6843 */   sra   $t5, $t4, 1
/* 0A7E28 7F0732F8 25810001 */  addiu $at, $t4, 1
/* 0A7E2C 7F0732FC 00016843 */  sra   $t5, $at, 1
.L7F073300:
/* 0A7E30 7F073300 01B27021 */  addu  $t6, $t5, $s2
/* 0A7E34 7F073304 01C37821 */  addu  $t7, $t6, $v1
/* 0A7E38 7F073308 01E3001A */  div   $zero, $t7, $v1
/* 0A7E3C 7F07330C 00002810 */  mfhi  $a1
/* 0A7E40 7F073310 AFA0009C */  sw    $zero, 0x9c($sp)
/* 0A7E44 7F073314 14600002 */  bnez  $v1, .L7F073320
/* 0A7E48 7F073318 00000000 */   nop   
/* 0A7E4C 7F07331C 0007000D */  break 7
.L7F073320:
/* 0A7E50 7F073320 2401FFFF */  li    $at, -1
/* 0A7E54 7F073324 14610004 */  bne   $v1, $at, .L7F073338
/* 0A7E58 7F073328 3C018000 */   lui   $at, 0x8000
/* 0A7E5C 7F07332C 15E10002 */  bne   $t7, $at, .L7F073338
/* 0A7E60 7F073330 00000000 */   nop   
/* 0A7E64 7F073334 0006000D */  break 6
.L7F073338:
/* 0A7E68 7F073338 10000009 */  b     .L7F073360
/* 0A7E6C 7F07333C 8EB1000C */   lw    $s1, 0xc($s5)
.L7F073340:
/* 0A7E70 7F073340 28A10007 */  slti  $at, $a1, 7
/* 0A7E74 7F073344 14200004 */  bnez  $at, .L7F073358
/* 0A7E78 7F073348 28A1000A */   slti  $at, $a1, 0xa
/* 0A7E7C 7F07334C 50200003 */  beql  $at, $zero, .L7F07335C
/* 0A7E80 7F073350 02402825 */   move  $a1, $s2
/* 0A7E84 7F073354 AFA0009C */  sw    $zero, 0x9c($sp)
.L7F073358:
/* 0A7E88 7F073358 02402825 */  move  $a1, $s2
.L7F07335C:
/* 0A7E8C 7F07335C 8EB1000C */  lw    $s1, 0xc($s5)
.L7F073360:
/* 0A7E90 7F073360 8FD40004 */  lw    $s4, 4($fp)
/* 0A7E94 7F073364 3C19BC00 */  lui   $t9, (0xBC001406 >> 16) # lui $t9, 0xbc00
/* 0A7E98 7F073368 26380008 */  addiu $t8, $s1, 8
/* 0A7E9C 7F07336C AEB8000C */  sw    $t8, 0xc($s5)
/* 0A7EA0 7F073370 37391406 */  ori   $t9, (0xBC001406 & 0xFFFF) # ori $t9, $t9, 0x1406
/* 0A7EA4 7F073374 AE390000 */  sw    $t9, ($s1)
/* 0A7EA8 7F073378 8EC401AC */  lw    $a0, 0x1ac($s6)
/* 0A7EAC 7F07337C 0C003A2C */  jal   osVirtualToPhysical
/* 0A7EB0 7F073380 AFA500B8 */   sw    $a1, 0xb8($sp)
/* 0A7EB4 7F073384 AE220004 */  sw    $v0, 4($s1)
/* 0A7EB8 7F073388 93D70000 */  lbu   $s7, ($fp)
/* 0A7EBC 7F07338C 241E000A */  li    $fp, 10
/* 0A7EC0 7F073390 24130003 */  li    $s3, 3
/* 0A7EC4 7F073394 1AE00109 */  blez  $s7, .L7F0737BC
/* 0A7EC8 7F073398 24120002 */   li    $s2, 2
/* 0A7ECC 7F07339C 24110001 */  li    $s1, 1
/* 0A7ED0 7F0733A0 92840000 */  lbu   $a0, ($s4)
.L7F0733A4:
/* 0A7ED4 7F0733A4 3C028003 */  lui   $v0, %hi(D_8003608C)
/* 0A7ED8 7F0733A8 8FB000B8 */  lw    $s0, 0xb8($sp)
/* 0A7EDC 7F0733AC 10910007 */  beq   $a0, $s1, .L7F0733CC
/* 0A7EE0 7F0733B0 00000000 */   nop   
/* 0A7EE4 7F0733B4 509200D5 */  beql  $a0, $s2, .L7F07370C
/* 0A7EE8 7F0733B8 92820001 */   lbu   $v0, 1($s4)
/* 0A7EEC 7F0733BC 509300E6 */  beql  $a0, $s3, .L7F073758
/* 0A7EF0 7F0733C0 8EB0000C */   lw    $s0, 0xc($s5)
/* 0A7EF4 7F0733C4 100000FB */  b     .L7F0737B4
/* 0A7EF8 7F0733C8 26F7FFFF */   addiu $s7, $s7, -1
.L7F0733CC:
/* 0A7EFC 7F0733CC 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
/* 0A7F00 7F0733D0 001040C0 */  sll   $t0, $s0, 3
/* 0A7F04 7F0733D4 01008025 */  move  $s0, $t0
/* 0A7F08 7F0733D8 14400007 */  bnez  $v0, .L7F0733F8
/* 0A7F0C 7F0733DC 3C048005 */   lui   $a0, %hi(aDotubeNoVtxAllocator)
/* 0A7F10 7F0733E0 0C0033D1 */  jal   osSyncPrintf
/* 0A7F14 7F0733E4 24844A58 */   addiu $a0, %lo(aDotubeNoVtxAllocator) # addiu $a0, $a0, 0x4a58
/* 0A7F18 7F0733E8 0FC1B11B */  jal   return_null
/* 0A7F1C 7F0733EC 00000000 */   nop   
/* 0A7F20 7F0733F0 3C028003 */  lui   $v0, %hi(D_8003608C)
/* 0A7F24 7F0733F4 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
.L7F0733F8:
/* 0A7F28 7F0733F8 0040F809 */  jalr  $v0
/* 0A7F2C 7F0733FC 02402025 */  move  $a0, $s2
/* 0A7F30 7F073400 AFA20074 */  sw    $v0, 0x74($sp)
/* 0A7F34 7F073404 968A0002 */  lhu   $t2, 2($s4)
/* 0A7F38 7F073408 8EC90010 */  lw    $t1, 0x10($s6)
/* 0A7F3C 7F07340C 24470010 */  addiu $a3, $v0, 0x10
/* 0A7F40 7F073410 000A5900 */  sll   $t3, $t2, 4
/* 0A7F44 7F073414 012B6021 */  addu  $t4, $t1, $t3
/* 0A7F48 7F073418 8D810000 */  lw    $at, ($t4)
/* 0A7F4C 7F07341C AC410000 */  sw    $at, ($v0)
/* 0A7F50 7F073420 8D8F0004 */  lw    $t7, 4($t4)
/* 0A7F54 7F073424 AC4F0004 */  sw    $t7, 4($v0)
/* 0A7F58 7F073428 8D810008 */  lw    $at, 8($t4)
/* 0A7F5C 7F07342C AC410008 */  sw    $at, 8($v0)
/* 0A7F60 7F073430 8D8F000C */  lw    $t7, 0xc($t4)
/* 0A7F64 7F073434 AC4F000C */  sw    $t7, 0xc($v0)
/* 0A7F68 7F073438 96990002 */  lhu   $t9, 2($s4)
/* 0A7F6C 7F07343C 8ED80010 */  lw    $t8, 0x10($s6)
/* 0A7F70 7F073440 00194100 */  sll   $t0, $t9, 4
/* 0A7F74 7F073444 03085021 */  addu  $t2, $t8, $t0
/* 0A7F78 7F073448 8D410010 */  lw    $at, 0x10($t2)
/* 0A7F7C 7F07344C ACE10000 */  sw    $at, ($a3)
/* 0A7F80 7F073450 8D4E0014 */  lw    $t6, 0x14($t2)
/* 0A7F84 7F073454 ACEE0004 */  sw    $t6, 4($a3)
/* 0A7F88 7F073458 8D410018 */  lw    $at, 0x18($t2)
/* 0A7F8C 7F07345C ACE10008 */  sw    $at, 8($a3)
/* 0A7F90 7F073460 8D4E001C */  lw    $t6, 0x1c($t2)
/* 0A7F94 7F073464 ACEE000C */  sw    $t6, 0xc($a3)
/* 0A7F98 7F073468 8ECD0004 */  lw    $t5, 4($s6)
/* 0A7F9C 7F07346C 8FAC00C0 */  lw    $t4, 0xc0($sp)
/* 0A7FA0 7F073470 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 0A7FA4 7F073474 51A0002E */  beql  $t5, $zero, .L7F073530
/* 0A7FA8 7F073478 8D99000C */   lw    $t9, 0xc($t4)
/* 0A7FAC 7F07347C 8ECC000C */  lw    $t4, 0xc($s6)
/* 0A7FB0 7F073480 01901821 */  addu  $v1, $t4, $s0
/* 0A7FB4 7F073484 90660000 */  lbu   $a2, ($v1)
/* 0A7FB8 7F073488 8C650004 */  lw    $a1, 4($v1)
/* 0A7FBC 7F07348C 58C00063 */  blezl $a2, .L7F07361C
/* 0A7FC0 7F073490 8EB0000C */   lw    $s0, 0xc($s5)
/* 0A7FC4 7F073494 90A30000 */  lbu   $v1, ($a1)
.L7F073498:
/* 0A7FC8 7F073498 24C6FFFF */  addiu $a2, $a2, -1
/* 0A7FCC 7F07349C 16230012 */  bne   $s1, $v1, .L7F0734E8
/* 0A7FD0 7F0734A0 00000000 */   nop   
/* 0A7FD4 7F0734A4 94B90002 */  lhu   $t9, 2($a1)
/* 0A7FD8 7F0734A8 8ECF0010 */  lw    $t7, 0x10($s6)
/* 0A7FDC 7F0734AC 0019C100 */  sll   $t8, $t9, 4
/* 0A7FE0 7F0734B0 01F81821 */  addu  $v1, $t7, $t8
/* 0A7FE4 7F0734B4 84680000 */  lh    $t0, ($v1)
/* 0A7FE8 7F0734B8 A4480000 */  sh    $t0, ($v0)
/* 0A7FEC 7F0734BC 846B0002 */  lh    $t3, 2($v1)
/* 0A7FF0 7F0734C0 A44B0002 */  sh    $t3, 2($v0)
/* 0A7FF4 7F0734C4 84690004 */  lh    $t1, 4($v1)
/* 0A7FF8 7F0734C8 A4490004 */  sh    $t1, 4($v0)
/* 0A7FFC 7F0734CC 846A0010 */  lh    $t2, 0x10($v1)
/* 0A8000 7F0734D0 A4EA0000 */  sh    $t2, ($a3)
/* 0A8004 7F0734D4 846E0012 */  lh    $t6, 0x12($v1)
/* 0A8008 7F0734D8 A4EE0002 */  sh    $t6, 2($a3)
/* 0A800C 7F0734DC 846D0014 */  lh    $t5, 0x14($v1)
/* 0A8010 7F0734E0 1000004D */  b     .L7F073618
/* 0A8014 7F0734E4 A4ED0004 */   sh    $t5, 4($a3)
.L7F0734E8:
/* 0A8018 7F0734E8 10710007 */  beq   $v1, $s1, .L7F073508
/* 0A801C 7F0734EC 00000000 */   nop   
/* 0A8020 7F0734F0 10720007 */  beq   $v1, $s2, .L7F073510
/* 0A8024 7F0734F4 00000000 */   nop   
/* 0A8028 7F0734F8 50730008 */  beql  $v1, $s3, .L7F07351C
/* 0A802C 7F0734FC 24A50004 */   addiu $a1, $a1, 4
/* 0A8030 7F073500 10000006 */  b     .L7F07351C
/* 0A8034 7F073504 00000000 */   nop   
.L7F073508:
/* 0A8038 7F073508 10000004 */  b     .L7F07351C
/* 0A803C 7F07350C 24A50004 */   addiu $a1, $a1, 4
.L7F073510:
/* 0A8040 7F073510 10000002 */  b     .L7F07351C
/* 0A8044 7F073514 24A50002 */   addiu $a1, $a1, 2
/* 0A8048 7F073518 24A50004 */  addiu $a1, $a1, 4
.L7F07351C:
/* 0A804C 7F07351C 5CC0FFDE */  bgtzl $a2, .L7F073498
/* 0A8050 7F073520 90A30000 */   lbu   $v1, ($a1)
/* 0A8054 7F073524 1000003D */  b     .L7F07361C
/* 0A8058 7F073528 8EB0000C */   lw    $s0, 0xc($s5)
/* 0A805C 7F07352C 8D99000C */  lw    $t9, 0xc($t4)
.L7F073530:
/* 0A8060 7F073530 03301821 */  addu  $v1, $t9, $s0
/* 0A8064 7F073534 90660000 */  lbu   $a2, ($v1)
/* 0A8068 7F073538 8C650004 */  lw    $a1, 4($v1)
/* 0A806C 7F07353C 58C00037 */  blezl $a2, .L7F07361C
/* 0A8070 7F073540 8EB0000C */   lw    $s0, 0xc($s5)
/* 0A8074 7F073544 90A30000 */  lbu   $v1, ($a1)
.L7F073548:
/* 0A8078 7F073548 24C6FFFF */  addiu $a2, $a2, -1
/* 0A807C 7F07354C 16230023 */  bne   $s1, $v1, .L7F0735DC
/* 0A8080 7F073550 00000000 */   nop   
/* 0A8084 7F073554 94A80002 */  lhu   $t0, 2($a1)
/* 0A8088 7F073558 8FA9009C */  lw    $t1, 0x9c($sp)
/* 0A808C 7F07355C 8DF80010 */  lw    $t8, 0x10($t7)
/* 0A8090 7F073560 00085900 */  sll   $t3, $t0, 4
/* 0A8094 7F073564 1120000F */  beqz  $t1, .L7F0735A4
/* 0A8098 7F073568 030B1821 */   addu  $v1, $t8, $t3
/* 0A809C 7F07356C 24640010 */  addiu $a0, $v1, 0x10
/* 0A80A0 7F073570 848A0000 */  lh    $t2, ($a0)
/* 0A80A4 7F073574 A44A0000 */  sh    $t2, ($v0)
/* 0A80A8 7F073578 848E0002 */  lh    $t6, 2($a0)
/* 0A80AC 7F07357C A44E0002 */  sh    $t6, 2($v0)
/* 0A80B0 7F073580 848D0004 */  lh    $t5, 4($a0)
/* 0A80B4 7F073584 A44D0004 */  sh    $t5, 4($v0)
/* 0A80B8 7F073588 846C0000 */  lh    $t4, ($v1)
/* 0A80BC 7F07358C A4EC0000 */  sh    $t4, ($a3)
/* 0A80C0 7F073590 84790002 */  lh    $t9, 2($v1)
/* 0A80C4 7F073594 A4F90002 */  sh    $t9, 2($a3)
/* 0A80C8 7F073598 846F0004 */  lh    $t7, 4($v1)
/* 0A80CC 7F07359C 1000001E */  b     .L7F073618
/* 0A80D0 7F0735A0 A4EF0004 */   sh    $t7, 4($a3)
.L7F0735A4:
/* 0A80D4 7F0735A4 84680000 */  lh    $t0, ($v1)
/* 0A80D8 7F0735A8 24640010 */  addiu $a0, $v1, 0x10
/* 0A80DC 7F0735AC A4480000 */  sh    $t0, ($v0)
/* 0A80E0 7F0735B0 84780002 */  lh    $t8, 2($v1)
/* 0A80E4 7F0735B4 A4580002 */  sh    $t8, 2($v0)
/* 0A80E8 7F0735B8 846B0004 */  lh    $t3, 4($v1)
/* 0A80EC 7F0735BC A44B0004 */  sh    $t3, 4($v0)
/* 0A80F0 7F0735C0 84890000 */  lh    $t1, ($a0)
/* 0A80F4 7F0735C4 A4E90000 */  sh    $t1, ($a3)
/* 0A80F8 7F0735C8 848A0002 */  lh    $t2, 2($a0)
/* 0A80FC 7F0735CC A4EA0002 */  sh    $t2, 2($a3)
/* 0A8100 7F0735D0 848E0004 */  lh    $t6, 4($a0)
/* 0A8104 7F0735D4 10000010 */  b     .L7F073618
/* 0A8108 7F0735D8 A4EE0004 */   sh    $t6, 4($a3)
.L7F0735DC:
/* 0A810C 7F0735DC 10710007 */  beq   $v1, $s1, .L7F0735FC
/* 0A8110 7F0735E0 00000000 */   nop   
/* 0A8114 7F0735E4 10720007 */  beq   $v1, $s2, .L7F073604
/* 0A8118 7F0735E8 00000000 */   nop   
/* 0A811C 7F0735EC 50730008 */  beql  $v1, $s3, .L7F073610
/* 0A8120 7F0735F0 24A50004 */   addiu $a1, $a1, 4
/* 0A8124 7F0735F4 10000006 */  b     .L7F073610
/* 0A8128 7F0735F8 00000000 */   nop   
.L7F0735FC:
/* 0A812C 7F0735FC 10000004 */  b     .L7F073610
/* 0A8130 7F073600 24A50004 */   addiu $a1, $a1, 4
.L7F073604:
/* 0A8134 7F073604 10000002 */  b     .L7F073610
/* 0A8138 7F073608 24A50002 */   addiu $a1, $a1, 2
/* 0A813C 7F07360C 24A50004 */  addiu $a1, $a1, 4
.L7F073610:
/* 0A8140 7F073610 5CC0FFCD */  bgtzl $a2, .L7F073548
/* 0A8144 7F073614 90A30000 */   lbu   $v1, ($a1)
.L7F073618:
/* 0A8148 7F073618 8EB0000C */  lw    $s0, 0xc($s5)
.L7F07361C:
/* 0A814C 7F07361C 3C0C0102 */  lui   $t4, (0x01020040 >> 16) # lui $t4, 0x102
/* 0A8150 7F073620 358C0040 */  ori   $t4, (0x01020040 & 0xFFFF) # ori $t4, $t4, 0x40
/* 0A8154 7F073624 260D0008 */  addiu $t5, $s0, 8
/* 0A8158 7F073628 AEAD000C */  sw    $t5, 0xc($s5)
/* 0A815C 7F07362C AE0C0000 */  sw    $t4, ($s0)
/* 0A8160 7F073630 8FA40080 */  lw    $a0, 0x80($sp)
/* 0A8164 7F073634 0C003A2C */  jal   osVirtualToPhysical
/* 0A8168 7F073638 AFB0004C */   sw    $s0, 0x4c($sp)
/* 0A816C 7F07363C 8FA3004C */  lw    $v1, 0x4c($sp)
/* 0A8170 7F073640 3C0F0410 */  lui   $t7, (0x04100020 >> 16) # lui $t7, 0x410
/* 0A8174 7F073644 35EF0020 */  ori   $t7, (0x04100020 & 0xFFFF) # ori $t7, $t7, 0x20
/* 0A8178 7F073648 AC620004 */  sw    $v0, 4($v1)
/* 0A817C 7F07364C 8EB0000C */  lw    $s0, 0xc($s5)
/* 0A8180 7F073650 26190008 */  addiu $t9, $s0, 8
/* 0A8184 7F073654 AEB9000C */  sw    $t9, 0xc($s5)
/* 0A8188 7F073658 AE0F0000 */  sw    $t7, ($s0)
/* 0A818C 7F07365C 8FA40074 */  lw    $a0, 0x74($sp)
/* 0A8190 7F073660 0C003A2C */  jal   osVirtualToPhysical
/* 0A8194 7F073664 AFB00048 */   sw    $s0, 0x48($sp)
/* 0A8198 7F073668 8FA50048 */  lw    $a1, 0x48($sp)
/* 0A819C 7F07366C 3C180102 */  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
/* 0A81A0 7F073670 37180040 */  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0A81A4 7F073674 ACA20004 */  sw    $v0, 4($a1)
/* 0A81A8 7F073678 8EB0000C */  lw    $s0, 0xc($s5)
/* 0A81AC 7F07367C 26080008 */  addiu $t0, $s0, 8
/* 0A81B0 7F073680 AEA8000C */  sw    $t0, 0xc($s5)
/* 0A81B4 7F073684 AE180000 */  sw    $t8, ($s0)
/* 0A81B8 7F073688 8FA40084 */  lw    $a0, 0x84($sp)
/* 0A81BC 7F07368C 0C003A2C */  jal   osVirtualToPhysical
/* 0A81C0 7F073690 AFB00044 */   sw    $s0, 0x44($sp)
/* 0A81C4 7F073694 8FA60044 */  lw    $a2, 0x44($sp)
/* 0A81C8 7F073698 3C010400 */  lui   $at, 0x400
/* 0A81CC 7F07369C ACC20004 */  sw    $v0, 4($a2)
/* 0A81D0 7F0736A0 8EB0000C */  lw    $s0, 0xc($s5)
/* 0A81D4 7F0736A4 260B0008 */  addiu $t3, $s0, 8
/* 0A81D8 7F0736A8 AEAB000C */  sw    $t3, 0xc($s5)
/* 0A81DC 7F0736AC 92830001 */  lbu   $v1, 1($s4)
/* 0A81E0 7F0736B0 2463FFFE */  addiu $v1, $v1, -2
/* 0A81E4 7F0736B4 2469FFFF */  addiu $t1, $v1, -1
/* 0A81E8 7F0736B8 00095100 */  sll   $t2, $t1, 4
/* 0A81EC 7F0736BC 354E0002 */  ori   $t6, $t2, 2
/* 0A81F0 7F0736C0 31CD00FF */  andi  $t5, $t6, 0xff
/* 0A81F4 7F0736C4 000D6400 */  sll   $t4, $t5, 0x10
/* 0A81F8 7F0736C8 00037900 */  sll   $t7, $v1, 4
/* 0A81FC 7F0736CC 31E8FFFF */  andi  $t0, $t7, 0xffff
/* 0A8200 7F0736D0 0181C825 */  or    $t9, $t4, $at
/* 0A8204 7F0736D4 0328C025 */  or    $t8, $t9, $t0
/* 0A8208 7F0736D8 AE180000 */  sw    $t8, ($s0)
/* 0A820C 7F0736DC 96890002 */  lhu   $t1, 2($s4)
/* 0A8210 7F0736E0 8ECB0010 */  lw    $t3, 0x10($s6)
/* 0A8214 7F0736E4 AFB00040 */  sw    $s0, 0x40($sp)
/* 0A8218 7F0736E8 00095100 */  sll   $t2, $t1, 4
/* 0A821C 7F0736EC 016A2021 */  addu  $a0, $t3, $t2
/* 0A8220 7F0736F0 0C003A2C */  jal   osVirtualToPhysical
/* 0A8224 7F0736F4 24840020 */   addiu $a0, $a0, 0x20
/* 0A8228 7F0736F8 8FA50040 */  lw    $a1, 0x40($sp)
/* 0A822C 7F0736FC 26940004 */  addiu $s4, $s4, 4
/* 0A8230 7F073700 1000002B */  b     .L7F0737B0
/* 0A8234 7F073704 ACA20004 */   sw    $v0, 4($a1)
/* 0A8238 7F073708 92820001 */  lbu   $v0, 1($s4)
.L7F07370C:
/* 0A823C 7F07370C 240100FF */  li    $at, 255
/* 0A8240 7F073710 02A02025 */  move  $a0, $s5
/* 0A8244 7F073714 1041000B */  beq   $v0, $at, .L7F073744
/* 0A8248 7F073718 00002825 */   move  $a1, $zero
/* 0A824C 7F07371C 00026880 */  sll   $t5, $v0, 2
/* 0A8250 7F073720 8ECE0014 */  lw    $t6, 0x14($s6)
/* 0A8254 7F073724 01A26823 */  subu  $t5, $t5, $v0
/* 0A8258 7F073728 000D6880 */  sll   $t5, $t5, 2
/* 0A825C 7F07372C 02A02025 */  move  $a0, $s5
/* 0A8260 7F073730 02203025 */  move  $a2, $s1
/* 0A8264 7F073734 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8268 7F073738 01CD2821 */   addu  $a1, $t6, $t5
/* 0A826C 7F07373C 1000001C */  b     .L7F0737B0
/* 0A8270 7F073740 26940002 */   addiu $s4, $s4, 2
.L7F073744:
/* 0A8274 7F073744 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8278 7F073748 02203025 */   move  $a2, $s1
/* 0A827C 7F07374C 10000018 */  b     .L7F0737B0
/* 0A8280 7F073750 26940002 */   addiu $s4, $s4, 2
/* 0A8284 7F073754 8EB0000C */  lw    $s0, 0xc($s5)
.L7F073758:
/* 0A8288 7F073758 3C0FBF00 */  lui   $t7, 0xbf00
/* 0A828C 7F07375C 26940004 */  addiu $s4, $s4, 4
/* 0A8290 7F073760 260C0008 */  addiu $t4, $s0, 8
/* 0A8294 7F073764 AEAC000C */  sw    $t4, 0xc($s5)
/* 0A8298 7F073768 AE0F0000 */  sw    $t7, ($s0)
/* 0A829C 7F07376C 9299FFFD */  lbu   $t9, -3($s4)
/* 0A82A0 7F073770 928BFFFE */  lbu   $t3, -2($s4)
/* 0A82A4 7F073774 928FFFFF */  lbu   $t7, -1($s4)
/* 0A82A8 7F073778 033E0019 */  multu $t9, $fp
/* 0A82AC 7F07377C 00004012 */  mflo  $t0
/* 0A82B0 7F073780 311800FF */  andi  $t8, $t0, 0xff
/* 0A82B4 7F073784 00184C00 */  sll   $t1, $t8, 0x10
/* 0A82B8 7F073788 017E0019 */  multu $t3, $fp
/* 0A82BC 7F07378C 00005012 */  mflo  $t2
/* 0A82C0 7F073790 314E00FF */  andi  $t6, $t2, 0xff
/* 0A82C4 7F073794 000E6A00 */  sll   $t5, $t6, 8
/* 0A82C8 7F073798 01FE0019 */  multu $t7, $fp
/* 0A82CC 7F07379C 012D6025 */  or    $t4, $t1, $t5
/* 0A82D0 7F0737A0 0000C812 */  mflo  $t9
/* 0A82D4 7F0737A4 332800FF */  andi  $t0, $t9, 0xff
/* 0A82D8 7F0737A8 0188C025 */  or    $t8, $t4, $t0
/* 0A82DC 7F0737AC AE180004 */  sw    $t8, 4($s0)
.L7F0737B0:
/* 0A82E0 7F0737B0 26F7FFFF */  addiu $s7, $s7, -1
.L7F0737B4:
/* 0A82E4 7F0737B4 5EE0FEFB */  bgtzl $s7, .L7F0733A4
/* 0A82E8 7F0737B8 92840000 */   lbu   $a0, ($s4)
.L7F0737BC:
/* 0A82EC 7F0737BC 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0737C0:
/* 0A82F0 7F0737C0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A82F4 7F0737C4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A82F8 7F0737C8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A82FC 7F0737CC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0A8300 7F0737D0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0A8304 7F0737D4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0A8308 7F0737D8 8FB60030 */  lw    $s6, 0x30($sp)
/* 0A830C 7F0737DC 8FB70034 */  lw    $s7, 0x34($sp)
/* 0A8310 7F0737E0 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0A8314 7F0737E4 03E00008 */  jr    $ra
/* 0A8318 7F0737E8 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0737EC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0737EC
/* 0A831C 7F0737EC AFA40000 */  sw    $a0, ($sp)
/* 0A8320 7F0737F0 AFA50004 */  sw    $a1, 4($sp)
/* 0A8324 7F0737F4 03E00008 */  jr    $ra
/* 0A8328 7F0737F8 AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0737FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0737FC
/* 0A832C 7F0737FC AFA40000 */  sw    $a0, ($sp)
/* 0A8330 7F073800 AFA50004 */  sw    $a1, 4($sp)
/* 0A8334 7F073804 03E00008 */  jr    $ra
/* 0A8338 7F073808 AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void dogfnegx(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80054D50
.word 0x40c90fdb /*6.2831855*/
.text
glabel dogfnegx
/* 0A833C 7F07380C 27BDFF00 */  addiu $sp, $sp, -0x100
/* 0A8340 7F073810 AFB20020 */  sw    $s2, 0x20($sp)
/* 0A8344 7F073814 00809025 */  move  $s2, $a0
/* 0A8348 7F073818 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0A834C 7F07381C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A8350 7F073820 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A8354 7F073824 AFA50104 */  sw    $a1, 0x104($sp)
/* 0A8358 7F073828 00A02025 */  move  $a0, $a1
/* 0A835C 7F07382C 00C08025 */  move  $s0, $a2
/* 0A8360 7F073830 8CD10004 */  lw    $s1, 4($a2)
/* 0A8364 7F073834 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0A8368 7F073838 00C02825 */   move  $a1, $a2
/* 0A836C 7F07383C 3C0F8003 */  lui   $t7, %hi(D_800363E0) 
/* 0A8370 7F073840 25EF63E0 */  addiu $t7, %lo(D_800363E0) # addiu $t7, $t7, 0x63e0
/* 0A8374 7F073844 8DE10000 */  lw    $at, ($t7)
/* 0A8378 7F073848 8DF90004 */  lw    $t9, 4($t7)
/* 0A837C 7F07384C 27AE0070 */  addiu $t6, $sp, 0x70
/* 0A8380 7F073850 ADC10000 */  sw    $at, ($t6)
/* 0A8384 7F073854 ADD90004 */  sw    $t9, 4($t6)
/* 0A8388 7F073858 8DF9000C */  lw    $t9, 0xc($t7)
/* 0A838C 7F07385C 8DE10008 */  lw    $at, 8($t7)
/* 0A8390 7F073860 ADD9000C */  sw    $t9, 0xc($t6)
/* 0A8394 7F073864 ADC10008 */  sw    $at, 8($t6)
/* 0A8398 7F073868 8E580008 */  lw    $t8, 8($s2)
/* 0A839C 7F07386C 330D0002 */  andi  $t5, $t8, 2
/* 0A83A0 7F073870 51A001D0 */  beql  $t5, $zero, .L7F073FB4
/* 0A83A4 7F073874 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A83A8 7F073878 844C0000 */  lh    $t4, ($v0)
/* 0A83AC 7F07387C 02002025 */  move  $a0, $s0
/* 0A83B0 7F073880 518001CC */  beql  $t4, $zero, .L7F073FB4
/* 0A83B4 7F073884 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0A83B8 7F073888 0FC1B15C */  jal   sub_GAME_7F06C570
/* 0A83BC 7F07388C 00002825 */   move  $a1, $zero
/* 0A83C0 7F073890 8FAE0104 */  lw    $t6, 0x104($sp)
/* 0A83C4 7F073894 0002C980 */  sll   $t9, $v0, 6
/* 0A83C8 7F073898 C6280000 */  lwc1  $f8, ($s1)
/* 0A83CC 7F07389C 8DCF000C */  lw    $t7, 0xc($t6)
/* 0A83D0 7F0738A0 C6240004 */  lwc1  $f4, 4($s1)
/* 0A83D4 7F0738A4 01F98021 */  addu  $s0, $t7, $t9
/* 0A83D8 7F0738A8 C60A0000 */  lwc1  $f10, ($s0)
/* 0A83DC 7F0738AC 460A4182 */  mul.s $f6, $f8, $f10
/* 0A83E0 7F0738B0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 0A83E4 7F0738B4 46082282 */  mul.s $f10, $f4, $f8
/* 0A83E8 7F0738B8 C6280008 */  lwc1  $f8, 8($s1)
/* 0A83EC 7F0738BC 460A3100 */  add.s $f4, $f6, $f10
/* 0A83F0 7F0738C0 C6060020 */  lwc1  $f6, 0x20($s0)
/* 0A83F4 7F0738C4 46064282 */  mul.s $f10, $f8, $f6
/* 0A83F8 7F0738C8 C6060030 */  lwc1  $f6, 0x30($s0)
/* 0A83FC 7F0738CC 460A2200 */  add.s $f8, $f4, $f10
/* 0A8400 7F0738D0 46083100 */  add.s $f4, $f6, $f8
/* 0A8404 7F0738D4 46002287 */  neg.s $f10, $f4
/* 0A8408 7F0738D8 E7AA00D0 */  swc1  $f10, 0xd0($sp)
/* 0A840C 7F0738DC C6260000 */  lwc1  $f6, ($s1)
/* 0A8410 7F0738E0 C6080004 */  lwc1  $f8, 4($s0)
/* 0A8414 7F0738E4 46083102 */  mul.s $f4, $f6, $f8
/* 0A8418 7F0738E8 C6080014 */  lwc1  $f8, 0x14($s0)
/* 0A841C 7F0738EC C6260004 */  lwc1  $f6, 4($s1)
/* 0A8420 7F0738F0 46083182 */  mul.s $f6, $f6, $f8
/* 0A8424 7F0738F4 46062200 */  add.s $f8, $f4, $f6
/* 0A8428 7F0738F8 C6060024 */  lwc1  $f6, 0x24($s0)
/* 0A842C 7F0738FC C6240008 */  lwc1  $f4, 8($s1)
/* 0A8430 7F073900 46062102 */  mul.s $f4, $f4, $f6
/* 0A8434 7F073904 46044180 */  add.s $f6, $f8, $f4
/* 0A8438 7F073908 C6080034 */  lwc1  $f8, 0x34($s0)
/* 0A843C 7F07390C 46064100 */  add.s $f4, $f8, $f6
/* 0A8440 7F073910 46002207 */  neg.s $f8, $f4
/* 0A8444 7F073914 E7A800D4 */  swc1  $f8, 0xd4($sp)
/* 0A8448 7F073918 C6040008 */  lwc1  $f4, 8($s0)
/* 0A844C 7F07391C C6260000 */  lwc1  $f6, ($s1)
/* 0A8450 7F073920 46043182 */  mul.s $f6, $f6, $f4
/* 0A8454 7F073924 C6240004 */  lwc1  $f4, 4($s1)
/* 0A8458 7F073928 E7AA0028 */  swc1  $f10, 0x28($sp)
/* 0A845C 7F07392C C60A0018 */  lwc1  $f10, 0x18($s0)
/* 0A8460 7F073930 460A2102 */  mul.s $f4, $f4, $f10
/* 0A8464 7F073934 46043280 */  add.s $f10, $f6, $f4
/* 0A8468 7F073938 C6040028 */  lwc1  $f4, 0x28($s0)
/* 0A846C 7F07393C C6260008 */  lwc1  $f6, 8($s1)
/* 0A8470 7F073940 46043182 */  mul.s $f6, $f6, $f4
/* 0A8474 7F073944 46065100 */  add.s $f4, $f10, $f6
/* 0A8478 7F073948 C60A0038 */  lwc1  $f10, 0x38($s0)
/* 0A847C 7F07394C 46045180 */  add.s $f6, $f10, $f4
/* 0A8480 7F073950 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 0A8484 7F073954 46003287 */  neg.s $f10, $f6
/* 0A8488 7F073958 46042182 */  mul.s $f6, $f4, $f4
/* 0A848C 7F07395C E7AA00D8 */  swc1  $f10, 0xd8($sp)
/* 0A8490 7F073960 46084102 */  mul.s $f4, $f8, $f8
/* 0A8494 7F073964 46043200 */  add.s $f8, $f6, $f4
/* 0A8498 7F073968 460A5282 */  mul.s $f10, $f10, $f10
/* 0A849C 7F07396C 0C007DF8 */  jal   sqrtf
/* 0A84A0 7F073970 46085300 */   add.s $f12, $f10, $f8
/* 0A84A4 7F073974 44807000 */  mtc1  $zero, $f14
/* 0A84A8 7F073978 00000000 */  nop   
/* 0A84AC 7F07397C 4600703C */  c.lt.s $f14, $f0
/* 0A84B0 7F073980 00000000 */  nop   
/* 0A84B4 7F073984 45020012 */  bc1fl .L7F0739D0
/* 0A84B8 7F073988 8FAD0104 */   lw    $t5, 0x104($sp)
/* 0A84BC 7F07398C 8FB80104 */  lw    $t8, 0x104($sp)
/* 0A84C0 7F073990 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A84C4 7F073994 44813000 */  mtc1  $at, $f6
/* 0A84C8 7F073998 C7040014 */  lwc1  $f4, 0x14($t8)
/* 0A84CC 7F07399C C7A800D0 */  lwc1  $f8, 0xd0($sp)
/* 0A84D0 7F0739A0 46002282 */  mul.s $f10, $f4, $f0
/* 0A84D4 7F0739A4 460A3083 */  div.s $f2, $f6, $f10
/* 0A84D8 7F0739A8 C7A600D4 */  lwc1  $f6, 0xd4($sp)
/* 0A84DC 7F0739AC 46024102 */  mul.s $f4, $f8, $f2
/* 0A84E0 7F0739B0 C7A800D8 */  lwc1  $f8, 0xd8($sp)
/* 0A84E4 7F0739B4 46023282 */  mul.s $f10, $f6, $f2
/* 0A84E8 7F0739B8 E7A400D0 */  swc1  $f4, 0xd0($sp)
/* 0A84EC 7F0739BC 46024102 */  mul.s $f4, $f8, $f2
/* 0A84F0 7F0739C0 E7AA00D4 */  swc1  $f10, 0xd4($sp)
/* 0A84F4 7F0739C4 10000009 */  b     .L7F0739EC
/* 0A84F8 7F0739C8 E7A400D8 */   swc1  $f4, 0xd8($sp)
/* 0A84FC 7F0739CC 8FAD0104 */  lw    $t5, 0x104($sp)
.L7F0739D0:
/* 0A8500 7F0739D0 E7AE00D0 */  swc1  $f14, 0xd0($sp)
/* 0A8504 7F0739D4 E7AE00D4 */  swc1  $f14, 0xd4($sp)
/* 0A8508 7F0739D8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A850C 7F0739DC 44813000 */  mtc1  $at, $f6
/* 0A8510 7F0739E0 C5AA0014 */  lwc1  $f10, 0x14($t5)
/* 0A8514 7F0739E4 460A3203 */  div.s $f8, $f6, $f10
/* 0A8518 7F0739E8 E7A800D8 */  swc1  $f8, 0xd8($sp)
.L7F0739EC:
/* 0A851C 7F0739EC C7A400D0 */  lwc1  $f4, 0xd0($sp)
/* 0A8520 7F0739F0 C6060010 */  lwc1  $f6, 0x10($s0)
/* 0A8524 7F0739F4 C7A800D4 */  lwc1  $f8, 0xd4($sp)
/* 0A8528 7F0739F8 46062282 */  mul.s $f10, $f4, $f6
/* 0A852C 7F0739FC C6040014 */  lwc1  $f4, 0x14($s0)
/* 0A8530 7F073A00 46044182 */  mul.s $f6, $f8, $f4
/* 0A8534 7F073A04 C6040018 */  lwc1  $f4, 0x18($s0)
/* 0A8538 7F073A08 46065200 */  add.s $f8, $f10, $f6
/* 0A853C 7F073A0C C7AA00D8 */  lwc1  $f10, 0xd8($sp)
/* 0A8540 7F073A10 460A2182 */  mul.s $f6, $f4, $f10
/* 0A8544 7F073A14 0FC16B2C */  jal   acosf
/* 0A8548 7F073A18 46083300 */   add.s $f12, $f6, $f8
/* 0A854C 7F073A1C E7A000DC */  swc1  $f0, 0xdc($sp)
/* 0A8550 7F073A20 0FC15FAB */  jal   sinf
/* 0A8554 7F073A24 46000306 */   mov.s $f12, $f0
/* 0A8558 7F073A28 C7A400D0 */  lwc1  $f4, 0xd0($sp)
/* 0A855C 7F073A2C C60A0020 */  lwc1  $f10, 0x20($s0)
/* 0A8560 7F073A30 C7A800D4 */  lwc1  $f8, 0xd4($sp)
/* 0A8564 7F073A34 460A2182 */  mul.s $f6, $f4, $f10
/* 0A8568 7F073A38 C6040024 */  lwc1  $f4, 0x24($s0)
/* 0A856C 7F073A3C 46044282 */  mul.s $f10, $f8, $f4
/* 0A8570 7F073A40 C7A400D8 */  lwc1  $f4, 0xd8($sp)
/* 0A8574 7F073A44 460A3200 */  add.s $f8, $f6, $f10
/* 0A8578 7F073A48 C6060028 */  lwc1  $f6, 0x28($s0)
/* 0A857C 7F073A4C 46062282 */  mul.s $f10, $f4, $f6
/* 0A8580 7F073A50 460A4100 */  add.s $f4, $f8, $f10
/* 0A8584 7F073A54 46002187 */  neg.s $f6, $f4
/* 0A8588 7F073A58 0FC16B2C */  jal   acosf
/* 0A858C 7F073A5C 46003303 */   div.s $f12, $f6, $f0
/* 0A8590 7F073A60 C7A800D0 */  lwc1  $f8, 0xd0($sp)
/* 0A8594 7F073A64 C60A0000 */  lwc1  $f10, ($s0)
/* 0A8598 7F073A68 C7A600D4 */  lwc1  $f6, 0xd4($sp)
/* 0A859C 7F073A6C 46000306 */  mov.s $f12, $f0
/* 0A85A0 7F073A70 460A4102 */  mul.s $f4, $f8, $f10
/* 0A85A4 7F073A74 C6080004 */  lwc1  $f8, 4($s0)
/* 0A85A8 7F073A78 46083282 */  mul.s $f10, $f6, $f8
/* 0A85AC 7F073A7C C6080008 */  lwc1  $f8, 8($s0)
/* 0A85B0 7F073A80 460A2180 */  add.s $f6, $f4, $f10
/* 0A85B4 7F073A84 C7A400D8 */  lwc1  $f4, 0xd8($sp)
/* 0A85B8 7F073A88 46044282 */  mul.s $f10, $f8, $f4
/* 0A85BC 7F073A8C 44804000 */  mtc1  $zero, $f8
/* 0A85C0 7F073A90 46065080 */  add.s $f2, $f10, $f6
/* 0A85C4 7F073A94 46001087 */  neg.s $f2, $f2
/* 0A85C8 7F073A98 4608103C */  c.lt.s $f2, $f8
/* 0A85CC 7F073A9C 00000000 */  nop   
/* 0A85D0 7F073AA0 45000003 */  bc1f  .L7F073AB0
/* 0A85D4 7F073AA4 3C018005 */   lui   $at, %hi(D_80054D50)
/* 0A85D8 7F073AA8 C4244D50 */  lwc1  $f4, %lo(D_80054D50)($at)
/* 0A85DC 7F073AAC 46002301 */  sub.s $f12, $f4, $f0
.L7F073AB0:
/* 0A85E0 7F073AB0 0FC15FA8 */  jal   cosf
/* 0A85E4 7F073AB4 E7AC00E0 */   swc1  $f12, 0xe0($sp)
/* 0A85E8 7F073AB8 C7AC00E0 */  lwc1  $f12, 0xe0($sp)
/* 0A85EC 7F073ABC 0FC15FAB */  jal   sinf
/* 0A85F0 7F073AC0 E7A000CC */   swc1  $f0, 0xcc($sp)
/* 0A85F4 7F073AC4 E7A000C8 */  swc1  $f0, 0xc8($sp)
/* 0A85F8 7F073AC8 0FC15FA8 */  jal   cosf
/* 0A85FC 7F073ACC C7AC00DC */   lwc1  $f12, 0xdc($sp)
/* 0A8600 7F073AD0 E7A000C4 */  swc1  $f0, 0xc4($sp)
/* 0A8604 7F073AD4 0FC15FAB */  jal   sinf
/* 0A8608 7F073AD8 C7AC00DC */   lwc1  $f12, 0xdc($sp)
/* 0A860C 7F073ADC 0C002914 */  jal   get_random_value
/* 0A8610 7F073AE0 E7A000C0 */   swc1  $f0, 0xc0($sp)
/* 0A8614 7F073AE4 304C007F */  andi  $t4, $v0, 0x7f
/* 0A8618 7F073AE8 448C5000 */  mtc1  $t4, $f10
/* 0A861C 7F073AEC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0A8620 7F073AF0 44810000 */  mtc1  $at, $f0
/* 0A8624 7F073AF4 C7AC00CC */  lwc1  $f12, 0xcc($sp)
/* 0A8628 7F073AF8 C7AE00C8 */  lwc1  $f14, 0xc8($sp)
/* 0A862C 7F073AFC C7B200C4 */  lwc1  $f18, 0xc4($sp)
/* 0A8630 7F073B00 05810005 */  bgez  $t4, .L7F073B18
/* 0A8634 7F073B04 468051A0 */   cvt.s.w $f6, $f10
/* 0A8638 7F073B08 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0A863C 7F073B0C 44814000 */  mtc1  $at, $f8
/* 0A8640 7F073B10 00000000 */  nop   
/* 0A8644 7F073B14 46083180 */  add.s $f6, $f6, $f8
.L7F073B18:
/* 0A8648 7F073B18 3C013B80 */  li    $at, 0x3B800000 # 0.003906
/* 0A864C 7F073B1C 44812000 */  mtc1  $at, $f4
/* 0A8650 7F073B20 3C013F40 */  li    $at, 0x3F400000 # 0.750000
/* 0A8654 7F073B24 44814000 */  mtc1  $at, $f8
/* 0A8658 7F073B28 46043282 */  mul.s $f10, $f6, $f4
/* 0A865C 7F073B2C C626000C */  lwc1  $f6, 0xc($s1)
/* 0A8660 7F073B30 3C038003 */  lui   $v1, %hi(D_8003608C)
/* 0A8664 7F073B34 8C63608C */  lw    $v1, %lo(D_8003608C)($v1)
/* 0A8668 7F073B38 3C048005 */  lui   $a0, %hi(aDogfnegxNoVtxAllocator)
/* 0A866C 7F073B3C 24844A74 */  addiu $a0, %lo(aDogfnegxNoVtxAllocator) # addiu $a0, $a0, 0x4a74
/* 0A8670 7F073B40 46085080 */  add.s $f2, $f10, $f8
/* 0A8674 7F073B44 46023102 */  mul.s $f4, $f6, $f2
/* 0A8678 7F073B48 E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0A867C 7F073B4C C62A0010 */  lwc1  $f10, 0x10($s1)
/* 0A8680 7F073B50 46025202 */  mul.s $f8, $f10, $f2
/* 0A8684 7F073B54 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0A8688 7F073B58 E7A80090 */  swc1  $f8, 0x90($sp)
/* 0A868C 7F073B5C C6260014 */  lwc1  $f6, 0x14($s1)
/* 0A8690 7F073B60 46023102 */  mul.s $f4, $f6, $f2
/* 0A8694 7F073B64 00000000 */  nop   
/* 0A8698 7F073B68 460C5202 */  mul.s $f8, $f10, $f12
/* 0A869C 7F073B6C E7A40094 */  swc1  $f4, 0x94($sp)
/* 0A86A0 7F073B70 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0A86A4 7F073B74 46004182 */  mul.s $f6, $f8, $f0
/* 0A86A8 7F073B78 00000000 */  nop   
/* 0A86AC 7F073B7C 460E2202 */  mul.s $f8, $f4, $f14
/* 0A86B0 7F073B80 E7A600BC */  swc1  $f6, 0xbc($sp)
/* 0A86B4 7F073B84 46004182 */  mul.s $f6, $f8, $f0
/* 0A86B8 7F073B88 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 0A86BC 7F073B8C E7A600B8 */  swc1  $f6, 0xb8($sp)
/* 0A86C0 7F073B90 C7A600C0 */  lwc1  $f6, 0xc0($sp)
/* 0A86C4 7F073B94 46064202 */  mul.s $f8, $f8, $f6
/* 0A86C8 7F073B98 00000000 */  nop   
/* 0A86CC 7F073B9C 46004402 */  mul.s $f16, $f8, $f0
/* 0A86D0 7F073BA0 00000000 */  nop   
/* 0A86D4 7F073BA4 46125182 */  mul.s $f6, $f10, $f18
/* 0A86D8 7F073BA8 00000000 */  nop   
/* 0A86DC 7F073BAC 460E3202 */  mul.s $f8, $f6, $f14
/* 0A86E0 7F073BB0 00000000 */  nop   
/* 0A86E4 7F073BB4 46004182 */  mul.s $f6, $f8, $f0
/* 0A86E8 7F073BB8 00000000 */  nop   
/* 0A86EC 7F073BBC 46122202 */  mul.s $f8, $f4, $f18
/* 0A86F0 7F073BC0 E7A600B0 */  swc1  $f6, 0xb0($sp)
/* 0A86F4 7F073BC4 460C4182 */  mul.s $f6, $f8, $f12
/* 0A86F8 7F073BC8 00000000 */  nop   
/* 0A86FC 7F073BCC 46003102 */  mul.s $f4, $f6, $f0
/* 0A8700 7F073BD0 E7A400AC */  swc1  $f4, 0xac($sp)
/* 0A8704 7F073BD4 46005182 */  mul.s $f6, $f10, $f0
/* 0A8708 7F073BD8 C6280000 */  lwc1  $f8, ($s1)
/* 0A870C 7F073BDC 46064101 */  sub.s $f4, $f8, $f6
/* 0A8710 7F073BE0 E7A40080 */  swc1  $f4, 0x80($sp)
/* 0A8714 7F073BE4 C62A0004 */  lwc1  $f10, 4($s1)
/* 0A8718 7F073BE8 E7AA0084 */  swc1  $f10, 0x84($sp)
/* 0A871C 7F073BEC C6280008 */  lwc1  $f8, 8($s1)
/* 0A8720 7F073BF0 14600008 */  bnez  $v1, .L7F073C14
/* 0A8724 7F073BF4 E7A80088 */   swc1  $f8, 0x88($sp)
/* 0A8728 7F073BF8 0C0033D1 */  jal   osSyncPrintf
/* 0A872C 7F073BFC E7B000B4 */   swc1  $f16, 0xb4($sp)
/* 0A8730 7F073C00 0FC1B11B */  jal   return_null
/* 0A8734 7F073C04 00000000 */   nop   
/* 0A8738 7F073C08 3C038003 */  lui   $v1, %hi(D_8003608C)
/* 0A873C 7F073C0C 8C63608C */  lw    $v1, %lo(D_8003608C)($v1)
/* 0A8740 7F073C10 C7B000B4 */  lwc1  $f16, 0xb4($sp)
.L7F073C14:
/* 0A8744 7F073C14 24040004 */  li    $a0, 4
/* 0A8748 7F073C18 0060F809 */  jalr  $v1
/* 0A874C 7F073C1C E7B000B4 */  swc1  $f16, 0xb4($sp)
/* 0A8750 7F073C20 27A30070 */  addiu $v1, $sp, 0x70
/* 0A8754 7F073C24 AFA2006C */  sw    $v0, 0x6c($sp)
/* 0A8758 7F073C28 8C610000 */  lw    $at, ($v1)
/* 0A875C 7F073C2C C7B000B4 */  lwc1  $f16, 0xb4($sp)
/* 0A8760 7F073C30 AC410000 */  sw    $at, ($v0)
/* 0A8764 7F073C34 8C790004 */  lw    $t9, 4($v1)
/* 0A8768 7F073C38 AC590004 */  sw    $t9, 4($v0)
/* 0A876C 7F073C3C 8C610008 */  lw    $at, 8($v1)
/* 0A8770 7F073C40 AC410008 */  sw    $at, 8($v0)
/* 0A8774 7F073C44 8C79000C */  lw    $t9, 0xc($v1)
/* 0A8778 7F073C48 AC59000C */  sw    $t9, 0xc($v0)
/* 0A877C 7F073C4C 8C610000 */  lw    $at, ($v1)
/* 0A8780 7F073C50 AC410010 */  sw    $at, 0x10($v0)
/* 0A8784 7F073C54 8C6C0004 */  lw    $t4, 4($v1)
/* 0A8788 7F073C58 AC4C0014 */  sw    $t4, 0x14($v0)
/* 0A878C 7F073C5C 8C610008 */  lw    $at, 8($v1)
/* 0A8790 7F073C60 AC410018 */  sw    $at, 0x18($v0)
/* 0A8794 7F073C64 8C6C000C */  lw    $t4, 0xc($v1)
/* 0A8798 7F073C68 AC4C001C */  sw    $t4, 0x1c($v0)
/* 0A879C 7F073C6C 8C610000 */  lw    $at, ($v1)
/* 0A87A0 7F073C70 AC410020 */  sw    $at, 0x20($v0)
/* 0A87A4 7F073C74 8C790004 */  lw    $t9, 4($v1)
/* 0A87A8 7F073C78 AC590024 */  sw    $t9, 0x24($v0)
/* 0A87AC 7F073C7C 8C610008 */  lw    $at, 8($v1)
/* 0A87B0 7F073C80 AC410028 */  sw    $at, 0x28($v0)
/* 0A87B4 7F073C84 8C79000C */  lw    $t9, 0xc($v1)
/* 0A87B8 7F073C88 AC59002C */  sw    $t9, 0x2c($v0)
/* 0A87BC 7F073C8C 8C610000 */  lw    $at, ($v1)
/* 0A87C0 7F073C90 AC410030 */  sw    $at, 0x30($v0)
/* 0A87C4 7F073C94 8C6C0004 */  lw    $t4, 4($v1)
/* 0A87C8 7F073C98 AC4C0034 */  sw    $t4, 0x34($v0)
/* 0A87CC 7F073C9C 8C610008 */  lw    $at, 8($v1)
/* 0A87D0 7F073CA0 AC410038 */  sw    $at, 0x38($v0)
/* 0A87D4 7F073CA4 8C6C000C */  lw    $t4, 0xc($v1)
/* 0A87D8 7F073CA8 AC4C003C */  sw    $t4, 0x3c($v0)
/* 0A87DC 7F073CAC C7A000BC */  lwc1  $f0, 0xbc($sp)
/* 0A87E0 7F073CB0 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0A87E4 7F073CB4 C7AC00B0 */  lwc1  $f12, 0xb0($sp)
/* 0A87E8 7F073CB8 46000007 */  neg.s $f0, $f0
/* 0A87EC 7F073CBC 46003100 */  add.s $f4, $f6, $f0
/* 0A87F0 7F073CC0 46006307 */  neg.s $f12, $f12
/* 0A87F4 7F073CC4 460C2280 */  add.s $f10, $f4, $f12
/* 0A87F8 7F073CC8 4600520D */  trunc.w.s $f8, $f10
/* 0A87FC 7F073CCC 440F4000 */  mfc1  $t7, $f8
/* 0A8800 7F073CD0 00000000 */  nop   
/* 0A8804 7F073CD4 A44F0000 */  sh    $t7, ($v0)
/* 0A8808 7F073CD8 C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0A880C 7F073CDC 46103101 */  sub.s $f4, $f6, $f16
/* 0A8810 7F073CE0 4600228D */  trunc.w.s $f10, $f4
/* 0A8814 7F073CE4 44185000 */  mfc1  $t8, $f10
/* 0A8818 7F073CE8 00000000 */  nop   
/* 0A881C 7F073CEC A4580002 */  sh    $t8, 2($v0)
/* 0A8820 7F073CF0 C7A200B8 */  lwc1  $f2, 0xb8($sp)
/* 0A8824 7F073CF4 C7A80088 */  lwc1  $f8, 0x88($sp)
/* 0A8828 7F073CF8 C7AE00AC */  lwc1  $f14, 0xac($sp)
/* 0A882C 7F073CFC 46001087 */  neg.s $f2, $f2
/* 0A8830 7F073D00 46024181 */  sub.s $f6, $f8, $f2
/* 0A8834 7F073D04 46007387 */  neg.s $f14, $f14
/* 0A8838 7F073D08 460E3100 */  add.s $f4, $f6, $f14
/* 0A883C 7F073D0C 4600228D */  trunc.w.s $f10, $f4
/* 0A8840 7F073D10 440C5000 */  mfc1  $t4, $f10
/* 0A8844 7F073D14 00000000 */  nop   
/* 0A8848 7F073D18 A44C0004 */  sh    $t4, 4($v0)
/* 0A884C 7F073D1C C7A80080 */  lwc1  $f8, 0x80($sp)
/* 0A8850 7F073D20 46004180 */  add.s $f6, $f8, $f0
/* 0A8854 7F073D24 460C3101 */  sub.s $f4, $f6, $f12
/* 0A8858 7F073D28 4600228D */  trunc.w.s $f10, $f4
/* 0A885C 7F073D2C 440F5000 */  mfc1  $t7, $f10
/* 0A8860 7F073D30 00000000 */  nop   
/* 0A8864 7F073D34 A44F0010 */  sh    $t7, 0x10($v0)
/* 0A8868 7F073D38 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 0A886C 7F073D3C 46104180 */  add.s $f6, $f8, $f16
/* 0A8870 7F073D40 4600310D */  trunc.w.s $f4, $f6
/* 0A8874 7F073D44 44182000 */  mfc1  $t8, $f4
/* 0A8878 7F073D48 00000000 */  nop   
/* 0A887C 7F073D4C A4580012 */  sh    $t8, 0x12($v0)
/* 0A8880 7F073D50 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 0A8884 7F073D54 46025201 */  sub.s $f8, $f10, $f2
/* 0A8888 7F073D58 460E4181 */  sub.s $f6, $f8, $f14
/* 0A888C 7F073D5C 4600310D */  trunc.w.s $f4, $f6
/* 0A8890 7F073D60 440C2000 */  mfc1  $t4, $f4
/* 0A8894 7F073D64 00000000 */  nop   
/* 0A8898 7F073D68 A44C0014 */  sh    $t4, 0x14($v0)
/* 0A889C 7F073D6C C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 0A88A0 7F073D70 46005201 */  sub.s $f8, $f10, $f0
/* 0A88A4 7F073D74 460C4181 */  sub.s $f6, $f8, $f12
/* 0A88A8 7F073D78 4600310D */  trunc.w.s $f4, $f6
/* 0A88AC 7F073D7C 440F2000 */  mfc1  $t7, $f4
/* 0A88B0 7F073D80 00000000 */  nop   
/* 0A88B4 7F073D84 A44F0020 */  sh    $t7, 0x20($v0)
/* 0A88B8 7F073D88 C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 0A88BC 7F073D8C 46105200 */  add.s $f8, $f10, $f16
/* 0A88C0 7F073D90 4600418D */  trunc.w.s $f6, $f8
/* 0A88C4 7F073D94 44183000 */  mfc1  $t8, $f6
/* 0A88C8 7F073D98 00000000 */  nop   
/* 0A88CC 7F073D9C A4580022 */  sh    $t8, 0x22($v0)
/* 0A88D0 7F073DA0 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0A88D4 7F073DA4 46022280 */  add.s $f10, $f4, $f2
/* 0A88D8 7F073DA8 460E5201 */  sub.s $f8, $f10, $f14
/* 0A88DC 7F073DAC 4600418D */  trunc.w.s $f6, $f8
/* 0A88E0 7F073DB0 440C3000 */  mfc1  $t4, $f6
/* 0A88E4 7F073DB4 00000000 */  nop   
/* 0A88E8 7F073DB8 A44C0024 */  sh    $t4, 0x24($v0)
/* 0A88EC 7F073DBC C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0A88F0 7F073DC0 46002281 */  sub.s $f10, $f4, $f0
/* 0A88F4 7F073DC4 460C5200 */  add.s $f8, $f10, $f12
/* 0A88F8 7F073DC8 4600418D */  trunc.w.s $f6, $f8
/* 0A88FC 7F073DCC 440F3000 */  mfc1  $t7, $f6
/* 0A8900 7F073DD0 00000000 */  nop   
/* 0A8904 7F073DD4 A44F0030 */  sh    $t7, 0x30($v0)
/* 0A8908 7F073DD8 C7A40084 */  lwc1  $f4, 0x84($sp)
/* 0A890C 7F073DDC 3C0FBC00 */  lui   $t7, (0xBC001406 >> 16) # lui $t7, 0xbc00
/* 0A8910 7F073DE0 35EF1406 */  ori   $t7, (0xBC001406 & 0xFFFF) # ori $t7, $t7, 0x1406
/* 0A8914 7F073DE4 46102281 */  sub.s $f10, $f4, $f16
/* 0A8918 7F073DE8 4600520D */  trunc.w.s $f8, $f10
/* 0A891C 7F073DEC 44184000 */  mfc1  $t8, $f8
/* 0A8920 7F073DF0 00000000 */  nop   
/* 0A8924 7F073DF4 A4580032 */  sh    $t8, 0x32($v0)
/* 0A8928 7F073DF8 C7A60088 */  lwc1  $f6, 0x88($sp)
/* 0A892C 7F073DFC 46023100 */  add.s $f4, $f6, $f2
/* 0A8930 7F073E00 460E2280 */  add.s $f10, $f4, $f14
/* 0A8934 7F073E04 4600520D */  trunc.w.s $f8, $f10
/* 0A8938 7F073E08 440C4000 */  mfc1  $t4, $f8
/* 0A893C 7F073E0C 00000000 */  nop   
/* 0A8940 7F073E10 A44C0034 */  sh    $t4, 0x34($v0)
/* 0A8944 7F073E14 8E43000C */  lw    $v1, 0xc($s2)
/* 0A8948 7F073E18 246E0008 */  addiu $t6, $v1, 8
/* 0A894C 7F073E1C AE4E000C */  sw    $t6, 0xc($s2)
/* 0A8950 7F073E20 AC6F0000 */  sw    $t7, ($v1)
/* 0A8954 7F073E24 8E240024 */  lw    $a0, 0x24($s1)
/* 0A8958 7F073E28 0C003A2C */  jal   osVirtualToPhysical
/* 0A895C 7F073E2C AFA3005C */   sw    $v1, 0x5c($sp)
/* 0A8960 7F073E30 8FA5005C */  lw    $a1, 0x5c($sp)
/* 0A8964 7F073E34 02402025 */  move  $a0, $s2
/* 0A8968 7F073E38 ACA20004 */  sw    $v0, 4($a1)
/* 0A896C 7F073E3C 8E230018 */  lw    $v1, 0x18($s1)
/* 0A8970 7F073E40 00002825 */  move  $a1, $zero
/* 0A8974 7F073E44 10600037 */  beqz  $v1, .L7F073F24
/* 0A8978 7F073E48 00000000 */   nop   
/* 0A897C 7F073E4C 0C002914 */  jal   get_random_value
/* 0A8980 7F073E50 00608825 */   move  $s1, $v1
/* 0A8984 7F073E54 0002CA80 */  sll   $t9, $v0, 0xa
/* 0A8988 7F073E58 A7B90056 */  sh    $t9, 0x56($sp)
/* 0A898C 7F073E5C 0C005B0C */  jal   coss
/* 0A8990 7F073E60 3324FFFF */   andi  $a0, $t9, 0xffff
/* 0A8994 7F073E64 92380004 */  lbu   $t8, 4($s1)
/* 0A8998 7F073E68 97A40056 */  lhu   $a0, 0x56($sp)
/* 0A899C 7F073E6C 00580019 */  multu $v0, $t8
/* 0A89A0 7F073E70 00004812 */  mflo  $t1
/* 0A89A4 7F073E74 00096880 */  sll   $t5, $t1, 2
/* 0A89A8 7F073E78 01A96823 */  subu  $t5, $t5, $t1
/* 0A89AC 7F073E7C 000D6880 */  sll   $t5, $t5, 2
/* 0A89B0 7F073E80 01A96823 */  subu  $t5, $t5, $t1
/* 0A89B4 7F073E84 000D6880 */  sll   $t5, $t5, 2
/* 0A89B8 7F073E88 01A96821 */  addu  $t5, $t5, $t1
/* 0A89BC 7F073E8C 000D6880 */  sll   $t5, $t5, 2
/* 0A89C0 7F073E90 01A96821 */  addu  $t5, $t5, $t1
/* 0A89C4 7F073E94 000D6483 */  sra   $t4, $t5, 0x12
/* 0A89C8 7F073E98 0C005B18 */  jal   sins
/* 0A89CC 7F073E9C AFAC0050 */   sw    $t4, 0x50($sp)
/* 0A89D0 7F073EA0 92240004 */  lbu   $a0, 4($s1)
/* 0A89D4 7F073EA4 8FA8006C */  lw    $t0, 0x6c($sp)
/* 0A89D8 7F073EA8 8FA90050 */  lw    $t1, 0x50($sp)
/* 0A89DC 7F073EAC 00440019 */  multu $v0, $a0
/* 0A89E0 7F073EB0 00041900 */  sll   $v1, $a0, 4
/* 0A89E4 7F073EB4 00693023 */  subu  $a2, $v1, $t1
/* 0A89E8 7F073EB8 A5060008 */  sh    $a2, 8($t0)
/* 0A89EC 7F073EBC A506001A */  sh    $a2, 0x1a($t0)
/* 0A89F0 7F073EC0 00695821 */  addu  $t3, $v1, $t1
/* 0A89F4 7F073EC4 24060004 */  li    $a2, 4
/* 0A89F8 7F073EC8 02402025 */  move  $a0, $s2
/* 0A89FC 7F073ECC A50B0028 */  sh    $t3, 0x28($t0)
/* 0A8A00 7F073ED0 A50B003A */  sh    $t3, 0x3a($t0)
/* 0A8A04 7F073ED4 00002812 */  mflo  $a1
/* 0A8A08 7F073ED8 00057080 */  sll   $t6, $a1, 2
/* 0A8A0C 7F073EDC 01C57023 */  subu  $t6, $t6, $a1
/* 0A8A10 7F073EE0 000E7080 */  sll   $t6, $t6, 2
/* 0A8A14 7F073EE4 01C57023 */  subu  $t6, $t6, $a1
/* 0A8A18 7F073EE8 000E7080 */  sll   $t6, $t6, 2
/* 0A8A1C 7F073EEC 01C57021 */  addu  $t6, $t6, $a1
/* 0A8A20 7F073EF0 000E7080 */  sll   $t6, $t6, 2
/* 0A8A24 7F073EF4 01C57021 */  addu  $t6, $t6, $a1
/* 0A8A28 7F073EF8 000E7C83 */  sra   $t7, $t6, 0x12
/* 0A8A2C 7F073EFC 006F5023 */  subu  $t2, $v1, $t7
/* 0A8A30 7F073F00 006F3821 */  addu  $a3, $v1, $t7
/* 0A8A34 7F073F04 02202825 */  move  $a1, $s1
/* 0A8A38 7F073F08 A50A000A */  sh    $t2, 0xa($t0)
/* 0A8A3C 7F073F0C A5070018 */  sh    $a3, 0x18($t0)
/* 0A8A40 7F073F10 A507002A */  sh    $a3, 0x2a($t0)
/* 0A8A44 7F073F14 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8A48 7F073F18 A50A0038 */   sh    $t2, 0x38($t0)
/* 0A8A4C 7F073F1C 10000004 */  b     .L7F073F30
/* 0A8A50 7F073F20 8E43000C */   lw    $v1, 0xc($s2)
.L7F073F24:
/* 0A8A54 7F073F24 0FC1CC0E */  jal   sub_GAME_7F073038
/* 0A8A58 7F073F28 24060001 */   li    $a2, 1
/* 0A8A5C 7F073F2C 8E43000C */  lw    $v1, 0xc($s2)
.L7F073F30:
/* 0A8A60 7F073F30 3C18B700 */  lui   $t8, 0xb700
/* 0A8A64 7F073F34 240D2000 */  li    $t5, 8192
/* 0A8A68 7F073F38 24790008 */  addiu $t9, $v1, 8
/* 0A8A6C 7F073F3C AE59000C */  sw    $t9, 0xc($s2)
/* 0A8A70 7F073F40 AC6D0004 */  sw    $t5, 4($v1)
/* 0A8A74 7F073F44 AC780000 */  sw    $t8, ($v1)
/* 0A8A78 7F073F48 8E51000C */  lw    $s1, 0xc($s2)
/* 0A8A7C 7F073F4C 3C0E0102 */  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
/* 0A8A80 7F073F50 35CE0040 */  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 0A8A84 7F073F54 262C0008 */  addiu $t4, $s1, 8
/* 0A8A88 7F073F58 AE4C000C */  sw    $t4, 0xc($s2)
/* 0A8A8C 7F073F5C 02002025 */  move  $a0, $s0
/* 0A8A90 7F073F60 0C003A2C */  jal   osVirtualToPhysical
/* 0A8A94 7F073F64 AE2E0000 */   sw    $t6, ($s1)
/* 0A8A98 7F073F68 AE220004 */  sw    $v0, 4($s1)
/* 0A8A9C 7F073F6C 8E50000C */  lw    $s0, 0xc($s2)
/* 0A8AA0 7F073F70 3C190430 */  lui   $t9, (0x04300040 >> 16) # lui $t9, 0x430
/* 0A8AA4 7F073F74 37390040 */  ori   $t9, (0x04300040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0A8AA8 7F073F78 260F0008 */  addiu $t7, $s0, 8
/* 0A8AAC 7F073F7C AE4F000C */  sw    $t7, 0xc($s2)
/* 0A8AB0 7F073F80 AE190000 */  sw    $t9, ($s0)
/* 0A8AB4 7F073F84 0C003A2C */  jal   osVirtualToPhysical
/* 0A8AB8 7F073F88 8FA4006C */   lw    $a0, 0x6c($sp)
/* 0A8ABC 7F073F8C AE020004 */  sw    $v0, 4($s0)
/* 0A8AC0 7F073F90 8E43000C */  lw    $v1, 0xc($s2)
/* 0A8AC4 7F073F94 3C0DB100 */  lui   $t5, (0xB1000002 >> 16) # lui $t5, 0xb100    # gSP4Triangles(6,1,2,8,2,0,1,0,0,0,0,0
/* 0A8AC8 7F073F98 35AD0002 */  ori   $t5, (0xB1000002 & 0xFFFF) # ori $t5, $t5, 2
/* 0A8ACC 7F073F9C 24780008 */  addiu $t8, $v1, 8
/* 0A8AD0 7F073FA0 AE58000C */  sw    $t8, 0xc($s2)
/* 0A8AD4 7F073FA4 240C3210 */  li    $t4, 12816
/* 0A8AD8 7F073FA8 AC6C0004 */  sw    $t4, 4($v1)
/* 0A8ADC 7F073FAC AC6D0000 */  sw    $t5, ($v1)                                    # ),
/* 0A8AE0 7F073FB0 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F073FB4:
/* 0A8AE4 7F073FB4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A8AE8 7F073FB8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A8AEC 7F073FBC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A8AF0 7F073FC0 03E00008 */  jr    $ra
/* 0A8AF4 7F073FC4 27BD0100 */   addiu $sp, $sp, 0x100
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F073FC8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F073FC8
/* 0A8AF8 7F073FC8 3C018003 */  lui   $at, %hi(D_800363F0)
/* 0A8AFC 7F073FCC 03E00008 */  jr    $ra
/* 0A8B00 7F073FD0 AC2463F0 */   sw    $a0, %lo(D_800363F0)($at)
)
#endif





#ifdef NONMATCHING
void doshadow(void) {

}
#else
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
/* 0A8B68 7F074038 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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
/* 0A8C0C 7F0740DC 0FC1B15C */  jal   sub_GAME_7F06C570
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
/* 0A8C44 7F074114 3C028003 */   lui   $v0, %hi(D_8003608C)
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
/* 0A8D14 7F0741E4 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
/* 0A8D18 7F0741E8 5440000F */  bnezl $v0, .L7F074228
/* 0A8D1C 7F0741EC 24040004 */   li    $a0, 4
/* 0A8D20 7F0741F0 A7A30052 */  sh    $v1, 0x52($sp)
/* 0A8D24 7F0741F4 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0A8D28 7F0741F8 E7AC0048 */  swc1  $f12, 0x48($sp)
/* 0A8D2C 7F0741FC 0C0033D1 */  jal   osSyncPrintf
/* 0A8D30 7F074200 E7AE0044 */   swc1  $f14, 0x44($sp)
/* 0A8D34 7F074204 0FC1B11B */  jal   return_null
/* 0A8D38 7F074208 00000000 */   nop   
/* 0A8D3C 7F07420C 3C028003 */  lui   $v0, %hi(D_8003608C)
/* 0A8D40 7F074210 8C42608C */  lw    $v0, %lo(D_8003608C)($v0)
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





#ifdef NONMATCHING
void sub_GAME_7F074514(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F074514
/* 0A9044 7F074514 AFA40000 */  sw    $a0, ($sp)
/* 0A9048 7F074518 AFA50004 */  sw    $a1, 4($sp)
/* 0A904C 7F07451C 03E00008 */  jr    $ra
/* 0A9050 7F074520 AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F074524(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F074524
/* 0A9054 7F074524 AFA40000 */  sw    $a0, ($sp)
/* 0A9058 7F074528 AFA50004 */  sw    $a1, 4($sp)
/* 0A905C 7F07452C 03E00008 */  jr    $ra
/* 0A9060 7F074530 AFA60008 */   sw    $a2, 8($sp)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F074534(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*80054D54*/
glabel jpt_80054D54
.word .L7F074674
.word .L7F074674
.word .L7F074674
.word .L7F07460C
.word .L7F07464C
.word .L7F07466C
.word .L7F07465C
.word .L7F07456C
.word .L7F0745A8
.word .L7F0745EC
.word .L7F0745BC
.word .L7F0745CC
.word .L7F0745DC
.word .L7F074674
.word .L7F074674
.word .L7F074674
.word .L7F0745FC
.word .L7F074580
.word .L7F074674
.word .L7F07462C
.word .L7F074674
.word .L7F07463C
.word .L7F074594
.word .L7F07461C
.text
glabel sub_GAME_7F074534
/* 0A9064 7F074534 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A9068 7F074538 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A906C 7F07453C 94C20000 */  lhu   $v0, ($a2)
/* 0A9070 7F074540 00A03825 */  move  $a3, $a1
/* 0A9074 7F074544 304E00FF */  andi  $t6, $v0, 0xff
/* 0A9078 7F074548 25CFFFFF */  addiu $t7, $t6, -1
/* 0A907C 7F07454C 2DE10018 */  sltiu $at, $t7, 0x18
/* 0A9080 7F074550 10200048 */  beqz  $at, .L7F074674
/* 0A9084 7F074554 000F7880 */   sll   $t7, $t7, 2
/* 0A9088 7F074558 3C018005 */  lui   $at, %hi(jpt_80054D54)
/* 0A908C 7F07455C 002F0821 */  addu  $at, $at, $t7
/* 0A9090 7F074560 8C2F4D54 */  lw    $t7, %lo(jpt_80054D54)($at)
.L7F074564:
/* 0A9094 7F074564 01E00008 */  jr    $t7
/* 0A9098 7F074568 00000000 */   nop   
.L7F07456C:
/* 0A909C 7F07456C 00E02025 */  move  $a0, $a3
/* 0A90A0 7F074570 0FC1BA5C */  jal   sub_GAME_7F06E970
/* 0A90A4 7F074574 00C02825 */   move  $a1, $a2
/* 0A90A8 7F074578 1000003F */  b     .L7F074678
/* 0A90AC 7F07457C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F074580:
/* 0A90B0 7F074580 00E02025 */  move  $a0, $a3
/* 0A90B4 7F074584 0FC1BA6F */  jal   process_12_handle_switch
/* 0A90B8 7F074588 00C02825 */   move  $a1, $a2
/* 0A90BC 7F07458C 1000003A */  b     .L7F074678
/* 0A90C0 7F074590 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F074594:
/* 0A90C4 7F074594 00E02025 */  move  $a0, $a3
/* 0A90C8 7F074598 0FC1BA82 */  jal   process_17_pointer_to_head
/* 0A90CC 7F07459C 00C02825 */   move  $a1, $a2
/* 0A90D0 7F0745A0 10000035 */  b     .L7F074678
/* 0A90D4 7F0745A4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745A8:
/* 0A90D8 7F0745A8 00E02025 */  move  $a0, $a3
/* 0A90DC 7F0745AC 0FC1BAC4 */  jal   sub_GAME_7F06EB10
/* 0A90E0 7F0745B0 00C02825 */   move  $a1, $a2
/* 0A90E4 7F0745B4 10000030 */  b     .L7F074678
/* 0A90E8 7F0745B8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745BC:
/* 0A90EC 7F0745BC 0FC1CDFF */  jal   sub_GAME_7F0737FC
/* 0A90F0 7F0745C0 00E02825 */   move  $a1, $a3
/* 0A90F4 7F0745C4 1000002C */  b     .L7F074678
/* 0A90F8 7F0745C8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745CC:
/* 0A90FC 7F0745CC 0FC1CE03 */  jal   dogfnegx
/* 0A9100 7F0745D0 00E02825 */   move  $a1, $a3
/* 0A9104 7F0745D4 10000028 */  b     .L7F074678
/* 0A9108 7F0745D8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745DC:
/* 0A910C 7F0745DC 0FC1CFF5 */  jal   doshadow
/* 0A9110 7F0745E0 00E02825 */   move  $a1, $a3
/* 0A9114 7F0745E4 10000024 */  b     .L7F074678
/* 0A9118 7F0745E8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745EC:
/* 0A911C 7F0745EC 0FC1D145 */  jal   sub_GAME_7F074514
/* 0A9120 7F0745F0 00E02825 */   move  $a1, $a3
/* 0A9124 7F0745F4 10000020 */  b     .L7F074678
/* 0A9128 7F0745F8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0745FC:
/* 0A912C 7F0745FC 0FC1D149 */  jal   sub_GAME_7F074524
/* 0A9130 7F074600 00E02825 */   move  $a1, $a3
/* 0A9134 7F074604 1000001C */  b     .L7F074678
/* 0A9138 7F074608 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07460C:
/* 0A913C 7F07460C 0FC1C9E1 */  jal   sub_GAME_7F072784
/* 0A9140 7F074610 00C02825 */   move  $a1, $a2
/* 0A9144 7F074614 10000018 */  b     .L7F074678
/* 0A9148 7F074618 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07461C:
/* 0A914C 7F07461C 0FC1CA61 */  jal   sub_GAME_7F072984
/* 0A9150 7F074620 00E02825 */   move  $a1, $a3
/* 0A9154 7F074624 10000014 */  b     .L7F074678
/* 0A9158 7F074628 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07462C:
/* 0A915C 7F07462C 0FC1CB04 */  jal   sub_GAME_7F072C10
/* 0A9160 7F074630 00E02825 */   move  $a1, $a3
/* 0A9164 7F074634 10000010 */  b     .L7F074678
/* 0A9168 7F074638 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07463C:
/* 0A916C 7F07463C 0FC1CB08 */  jal   dorottex
/* 0A9170 7F074640 00C02825 */   move  $a1, $a2
/* 0A9174 7F074644 1000000C */  b     .L7F074678
/* 0A9178 7F074648 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07464C:
/* 0A917C 7F07464C 0FC1CC1B */  jal   sub_GAME_7F07306C
/* 0A9180 7F074650 00E02825 */   move  $a1, $a3
/* 0A9184 7F074654 10000008 */  b     .L7F074678
/* 0A9188 7F074658 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07465C:
/* 0A918C 7F07465C 0FC1CC1F */  jal   dotube
/* 0A9190 7F074660 00E02825 */   move  $a1, $a3
/* 0A9194 7F074664 10000004 */  b     .L7F074678
/* 0A9198 7F074668 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07466C:
/* 0A919C 7F07466C 0FC1CDFB */  jal   sub_GAME_7F0737EC
/* 0A91A0 7F074670 00E02825 */   move  $a1, $a3
def_7F074564:
.L7F074674:
/* 0A91A4 7F074674 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F074678:
/* 0A91A8 7F074678 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A91AC 7F07467C 03E00008 */  jr    $ra
/* 0A91B0 7F074680 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void subdraw(void) {

}
#else
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





#ifdef NONMATCHING
void sub_GAME_7F074790(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F074790
/* 0A92C0 7F074790 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A92C4 7F074794 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A92C8 7F074798 AFA40018 */  sw    $a0, 0x18($sp)
/* 0A92CC 7F07479C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0A92D0 7F0747A0 0FC1B5AC */  jal   subcalcpos
/* 0A92D4 7F0747A4 00A02025 */   move  $a0, $a1
/* 0A92D8 7F0747A8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0A92DC 7F0747AC 0FC1BCBE */  jal   subcalcmatrices
/* 0A92E0 7F0747B0 8FA5001C */   lw    $a1, 0x1c($sp)
/* 0A92E4 7F0747B4 8FA40018 */  lw    $a0, 0x18($sp)
/* 0A92E8 7F0747B8 0FC1D1A1 */  jal   subdraw
/* 0A92EC 7F0747BC 8FA5001C */   lw    $a1, 0x1c($sp)
/* 0A92F0 7F0747C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A92F4 7F0747C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A92F8 7F0747C8 03E00008 */  jr    $ra
/* 0A92FC 7F0747CC 00000000 */   nop   
)
#endif





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
/* 0A97B0 7F074C80 0FC1B198 */  jal   sub_GAME_7F06C660
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
/* 0A9800 7F074CD0 0FC1B198 */  jal   sub_GAME_7F06C660
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
/* 0A9978 7F074E48 0FC1B198 */  jal   sub_GAME_7F06C660
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
/* 0A9F70 7F075440 0FC1BA5C */  jal   sub_GAME_7F06E970
/* 0A9F74 7F075444 02002825 */   move  $a1, $s0
/* 0A9F78 7F075448 10000009 */  b     .L7F075470
/* 0A9F7C 7F07544C 00000000 */   nop   
.L7F075450:
/* 0A9F80 7F075450 02402025 */  move  $a0, $s2
/* 0A9F84 7F075454 0FC1BA6F */  jal   process_12_handle_switch
/* 0A9F88 7F075458 02002825 */   move  $a1, $s0
/* 0A9F8C 7F07545C 10000004 */  b     .L7F075470
/* 0A9F90 7F075460 00000000 */   nop   
.L7F075464:
/* 0A9F94 7F075464 02402025 */  move  $a0, $s2
/* 0A9F98 7F075468 0FC1BA82 */  jal   process_17_pointer_to_head
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
void sub_GAME_7F07549C(void) {

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





#ifdef NONMATCHING
s32 sub_GAME_7F0754BC(void *arg0, s32 arg1, ? arg2) {
    s32 temp_t6;
    s32 temp_t2;
    s32 temp_a1;
    s32 phi_a1;
    s32 phi_v1;
    s32 phi_a3;
    s32 phi_a3_2;

    // Node 0
    temp_t6 = ((s32) arg0->unkE >> 3);
    if ((*arg0 << 0) < 0)
    {
        // Node 1
        phi_a3_2 = (*arg0 + (arg1 * temp_t6));
    }
    else
    {
        // Node 2
        phi_a3_2 = 0;
        if (D_80036414 != 0)
        {
            // Node 3
            temp_t2 = (((u32) (D_80036414->unk8 + 0xf) >> 4) * 0x10);
            temp_a1 = (*arg0 + (arg1 * temp_t6));
            phi_a1 = temp_a1;
            phi_v1 = temp_t6;
            phi_a3 = temp_t2;
            if ((temp_a1 & 1) != 0)
            {
                // Node 4
                phi_a1 = (temp_a1 + -1);
                phi_v1 = (temp_t6 + 1);
                phi_a3 = (temp_t2 + 1);
            }
            // Node 5
            romCopy(temp_t2, phi_a1, (((u32) (phi_v1 + 0xf) >> 4) * 0x10), phi_a3);
            *D_80036414 = (s32) (*D_80036414 + 1);
            D_80036414->unk8 = (s32) (sp20 + sp18);
            phi_a3_2 = sp2C;
        }
        // Node 6
    }
    // Node 7
    return phi_a3_2;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0754BC
/* 0A9FEC 7F0754BC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A9FF0 7F0754C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A9FF4 7F0754C4 AFA50034 */  sw    $a1, 0x34($sp)
/* 0A9FF8 7F0754C8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0A9FFC 7F0754CC 9483000E */  lhu   $v1, 0xe($a0)
/* 0AA000 7F0754D0 8C860000 */  lw    $a2, ($a0)
/* 0AA004 7F0754D4 00003825 */  move  $a3, $zero
/* 0AA008 7F0754D8 000370C3 */  sra   $t6, $v1, 3
/* 0AA00C 7F0754DC 00067800 */  sll   $t7, $a2, 0
/* 0AA010 7F0754E0 05E10006 */  bgez  $t7, .L7F0754FC
/* 0AA014 7F0754E4 01C01825 */   move  $v1, $t6
/* 0AA018 7F0754E8 00AE0019 */  multu $a1, $t6
/* 0AA01C 7F0754EC 0000C812 */  mflo  $t9
/* 0AA020 7F0754F0 00D93821 */  addu  $a3, $a2, $t9
/* 0AA024 7F0754F4 1000002A */  b     .L7F0755A0
/* 0AA028 7F0754F8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0754FC:
/* 0AA02C 7F0754FC 3C088003 */  lui   $t0, %hi(D_80036414) 
/* 0AA030 7F075500 25086414 */  addiu $t0, %lo(D_80036414) # addiu $t0, $t0, 0x6414
/* 0AA034 7F075504 8D020000 */  lw    $v0, ($t0)
/* 0AA038 7F075508 8FAB0034 */  lw    $t3, 0x34($sp)
/* 0AA03C 7F07550C 50400024 */  beql  $v0, $zero, .L7F0755A0
/* 0AA040 7F075510 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0AA044 7F075514 01630019 */  multu $t3, $v1
/* 0AA048 7F075518 8C440008 */  lw    $a0, 8($v0)
/* 0AA04C 7F07551C 2484000F */  addiu $a0, $a0, 0xf
/* 0AA050 7F075520 00044902 */  srl   $t1, $a0, 4
/* 0AA054 7F075524 00095100 */  sll   $t2, $t1, 4
/* 0AA058 7F075528 01402025 */  move  $a0, $t2
/* 0AA05C 7F07552C 01403825 */  move  $a3, $t2
/* 0AA060 7F075530 00006012 */  mflo  $t4
/* 0AA064 7F075534 00CC2821 */  addu  $a1, $a2, $t4
/* 0AA068 7F075538 30AD0001 */  andi  $t5, $a1, 1
/* 0AA06C 7F07553C 51A00005 */  beql  $t5, $zero, .L7F075554
/* 0AA070 7F075540 2466000F */   addiu $a2, $v1, 0xf
/* 0AA074 7F075544 24A5FFFF */  addiu $a1, $a1, -1
/* 0AA078 7F075548 24630001 */  addiu $v1, $v1, 1
/* 0AA07C 7F07554C 25470001 */  addiu $a3, $t2, 1
/* 0AA080 7F075550 2466000F */  addiu $a2, $v1, 0xf
.L7F075554:
/* 0AA084 7F075554 00067102 */  srl   $t6, $a2, 4
/* 0AA088 7F075558 000E3100 */  sll   $a2, $t6, 4
/* 0AA08C 7F07555C AFA60018 */  sw    $a2, 0x18($sp)
/* 0AA090 7F075560 AFA40020 */  sw    $a0, 0x20($sp)
/* 0AA094 7F075564 0C001707 */  jal   romCopy
/* 0AA098 7F075568 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0AA09C 7F07556C 3C088003 */  lui   $t0, %hi(D_80036414) 
/* 0AA0A0 7F075570 25086414 */  addiu $t0, %lo(D_80036414) # addiu $t0, $t0, 0x6414
/* 0AA0A4 7F075574 8D020000 */  lw    $v0, ($t0)
/* 0AA0A8 7F075578 8FA40020 */  lw    $a0, 0x20($sp)
/* 0AA0AC 7F07557C 8FA60018 */  lw    $a2, 0x18($sp)
/* 0AA0B0 7F075580 8C580000 */  lw    $t8, ($v0)
/* 0AA0B4 7F075584 8FA7002C */  lw    $a3, 0x2c($sp)
/* 0AA0B8 7F075588 00864821 */  addu  $t1, $a0, $a2
/* 0AA0BC 7F07558C 27190001 */  addiu $t9, $t8, 1
/* 0AA0C0 7F075590 AC590000 */  sw    $t9, ($v0)
/* 0AA0C4 7F075594 8D0A0000 */  lw    $t2, ($t0)
/* 0AA0C8 7F075598 AD490008 */  sw    $t1, 8($t2)
/* 0AA0CC 7F07559C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0755A0:
/* 0AA0D0 7F0755A0 27BD0030 */  addiu $sp, $sp, 0x30
/* 0AA0D4 7F0755A4 00E01025 */  move  $v0, $a3
/* 0AA0D8 7F0755A8 03E00008 */  jr    $ra
/* 0AA0DC 7F0755AC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0755B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0755B0
/* 0AA0E0 7F0755B0 3C038003 */  lui   $v1, %hi(D_80036414)
/* 0AA0E4 7F0755B4 24636414 */  addiu $v1, %lo(D_80036414) # addiu $v1, $v1, 0x6414
/* 0AA0E8 7F0755B8 8C620000 */  lw    $v0, ($v1)
/* 0AA0EC 7F0755BC 10400005 */  beqz  $v0, .L7F0755D4
/* 0AA0F0 7F0755C0 00000000 */   nop   
/* 0AA0F4 7F0755C4 8C4E0004 */  lw    $t6, 4($v0)
/* 0AA0F8 7F0755C8 AC4E0008 */  sw    $t6, 8($v0)
/* 0AA0FC 7F0755CC 8C6F0000 */  lw    $t7, ($v1)
/* 0AA100 7F0755D0 ADE00000 */  sw    $zero, ($t7)
.L7F0755D4:
/* 0AA104 7F0755D4 03E00008 */  jr    $ra
/* 0AA108 7F0755D8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void convert_obj_microcode_offset_to_rdram_addr(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054E14*/
glabel jpt_80054E14
.word .L7F075678
.word .L7F075698
.word .L7F0756B8
.word .L7F0756D8
.word .L7F0757AC
.word .L7F0758F4
.word .L7F07583C
.word .L7F075904
.word .L7F07594C
.word .L7F075A44
.word .L7F0759A0
.word .L7F0759C4
.word .L7F0759E8
.word .L7F075A44
.word .L7F075A44
.word .L7F075A44
.word .L7F075980
.word .L7F07592C
.word .L7F075A44
.word .L7F07578C
.word .L7F075A44
.word .L7F075A20
.word .L7F075A44
.word .L7F0756FC

.text
glabel convert_obj_microcode_offset_to_rdram_addr
/* 0AA10C 7F0755DC 1080012A */  beqz  $a0, .L7F075A88
/* 0AA110 7F0755E0 00000000 */   nop   
/* 0AA114 7F0755E4 94820000 */  lhu   $v0, ($a0)
.L7F0755E8:
/* 0AA118 7F0755E8 8C830004 */  lw    $v1, 4($a0)
/* 0AA11C 7F0755EC 00C57823 */  subu  $t7, $a2, $a1
/* 0AA120 7F0755F0 304E00FF */  andi  $t6, $v0, 0xff
/* 0AA124 7F0755F4 10600003 */  beqz  $v1, .L7F075604
/* 0AA128 7F0755F8 01C01025 */   move  $v0, $t6
/* 0AA12C 7F0755FC 006FC021 */  addu  $t8, $v1, $t7
/* 0AA130 7F075600 AC980004 */  sw    $t8, 4($a0)
.L7F075604:
/* 0AA134 7F075604 8C830008 */  lw    $v1, 8($a0)
/* 0AA138 7F075608 00C5C823 */  subu  $t9, $a2, $a1
/* 0AA13C 7F07560C 00C56023 */  subu  $t4, $a2, $a1
/* 0AA140 7F075610 10600002 */  beqz  $v1, .L7F07561C
/* 0AA144 7F075614 00795821 */   addu  $t3, $v1, $t9
/* 0AA148 7F075618 AC8B0008 */  sw    $t3, 8($a0)
.L7F07561C:
/* 0AA14C 7F07561C 8C83000C */  lw    $v1, 0xc($a0)
/* 0AA150 7F075620 244BFFFF */  addiu $t3, $v0, -1
/* 0AA154 7F075624 2D610018 */  sltiu $at, $t3, 0x18
/* 0AA158 7F075628 10600002 */  beqz  $v1, .L7F075634
/* 0AA15C 7F07562C 006C6821 */   addu  $t5, $v1, $t4
/* 0AA160 7F075630 AC8D000C */  sw    $t5, 0xc($a0)
.L7F075634:
/* 0AA164 7F075634 8C830010 */  lw    $v1, 0x10($a0)
/* 0AA168 7F075638 00C57023 */  subu  $t6, $a2, $a1
/* 0AA16C 7F07563C 00C5C023 */  subu  $t8, $a2, $a1
/* 0AA170 7F075640 10600002 */  beqz  $v1, .L7F07564C
/* 0AA174 7F075644 006E7821 */   addu  $t7, $v1, $t6
/* 0AA178 7F075648 AC8F0010 */  sw    $t7, 0x10($a0)
.L7F07564C:
/* 0AA17C 7F07564C 8C830014 */  lw    $v1, 0x14($a0)
/* 0AA180 7F075650 000B5880 */  sll   $t3, $t3, 2
/* 0AA184 7F075654 10600002 */  beqz  $v1, .L7F075660
/* 0AA188 7F075658 0078C821 */   addu  $t9, $v1, $t8
/* 0AA18C 7F07565C AC990014 */  sw    $t9, 0x14($a0)
.L7F075660:
/* 0AA190 7F075660 102000F8 */  beqz  $at, .L7F075A44
/* 0AA194 7F075664 3C018005 */   lui   $at, %hi(jpt_80054E14)
/* 0AA198 7F075668 002B0821 */  addu  $at, $at, $t3
/* 0AA19C 7F07566C 8C2B4E14 */  lw    $t3, %lo(jpt_80054E14)($at)
.L7F075670:
/* 0AA1A0 7F075670 01600008 */  jr    $t3
/* 0AA1A4 7F075674 00000000 */   nop   
.L7F075678:
/* 0AA1A8 7F075678 8C820004 */  lw    $v0, 4($a0)
/* 0AA1AC 7F07567C 00C56023 */  subu  $t4, $a2, $a1
/* 0AA1B0 7F075680 8C430004 */  lw    $v1, 4($v0)
/* 0AA1B4 7F075684 10600002 */  beqz  $v1, .L7F075690
/* 0AA1B8 7F075688 006C6821 */   addu  $t5, $v1, $t4
/* 0AA1BC 7F07568C AC4D0004 */  sw    $t5, 4($v0)
.L7F075690:
/* 0AA1C0 7F075690 100000ED */  b     .L7F075A48
/* 0AA1C4 7F075694 8C830014 */   lw    $v1, 0x14($a0)
.L7F075698:
/* 0AA1C8 7F075698 8C820004 */  lw    $v0, 4($a0)
/* 0AA1CC 7F07569C 00C57023 */  subu  $t6, $a2, $a1
/* 0AA1D0 7F0756A0 8C430014 */  lw    $v1, 0x14($v0)
/* 0AA1D4 7F0756A4 10600002 */  beqz  $v1, .L7F0756B0
/* 0AA1D8 7F0756A8 006E7821 */   addu  $t7, $v1, $t6
/* 0AA1DC 7F0756AC AC4F0014 */  sw    $t7, 0x14($v0)
.L7F0756B0:
/* 0AA1E0 7F0756B0 100000E5 */  b     .L7F075A48
/* 0AA1E4 7F0756B4 8C830014 */   lw    $v1, 0x14($a0)
.L7F0756B8:
/* 0AA1E8 7F0756B8 8C820004 */  lw    $v0, 4($a0)
/* 0AA1EC 7F0756BC 00C5C023 */  subu  $t8, $a2, $a1
/* 0AA1F0 7F0756C0 8C430014 */  lw    $v1, 0x14($v0)
/* 0AA1F4 7F0756C4 10600002 */  beqz  $v1, .L7F0756D0
/* 0AA1F8 7F0756C8 0078C821 */   addu  $t9, $v1, $t8
/* 0AA1FC 7F0756CC AC590014 */  sw    $t9, 0x14($v0)
.L7F0756D0:
/* 0AA200 7F0756D0 100000DD */  b     .L7F075A48
/* 0AA204 7F0756D4 8C830014 */   lw    $v1, 0x14($a0)
.L7F0756D8:
/* 0AA208 7F0756D8 8C820004 */  lw    $v0, 4($a0)
/* 0AA20C 7F0756DC 00C55823 */  subu  $t3, $a2, $a1
/* 0AA210 7F0756E0 8C43000C */  lw    $v1, 0xc($v0)
/* 0AA214 7F0756E4 10600002 */  beqz  $v1, .L7F0756F0
/* 0AA218 7F0756E8 006B6021 */   addu  $t4, $v1, $t3
/* 0AA21C 7F0756EC AC4C000C */  sw    $t4, 0xc($v0)
.L7F0756F0:
/* 0AA220 7F0756F0 AC460008 */  sw    $a2, 8($v0)
/* 0AA224 7F0756F4 100000D4 */  b     .L7F075A48
/* 0AA228 7F0756F8 8C830014 */   lw    $v1, 0x14($a0)
.L7F0756FC:
/* 0AA22C 7F0756FC 8C870004 */  lw    $a3, 4($a0)
/* 0AA230 7F075700 00C56823 */  subu  $t5, $a2, $a1
/* 0AA234 7F075704 00001025 */  move  $v0, $zero
/* 0AA238 7F075708 8CE30008 */  lw    $v1, 8($a3)
/* 0AA23C 7F07570C 00C57823 */  subu  $t7, $a2, $a1
/* 0AA240 7F075710 00C5C823 */  subu  $t9, $a2, $a1
/* 0AA244 7F075714 10600002 */  beqz  $v1, .L7F075720
/* 0AA248 7F075718 006D7021 */   addu  $t6, $v1, $t5
/* 0AA24C 7F07571C ACEE0008 */  sw    $t6, 8($a3)
.L7F075720:
/* 0AA250 7F075720 8CE30010 */  lw    $v1, 0x10($a3)
/* 0AA254 7F075724 00004025 */  move  $t0, $zero
/* 0AA258 7F075728 10600002 */  beqz  $v1, .L7F075734
/* 0AA25C 7F07572C 006FC021 */   addu  $t8, $v1, $t7
/* 0AA260 7F075730 ACF80010 */  sw    $t8, 0x10($a3)
.L7F075734:
/* 0AA264 7F075734 8CE30014 */  lw    $v1, 0x14($a3)
/* 0AA268 7F075738 10600002 */  beqz  $v1, .L7F075744
/* 0AA26C 7F07573C 00795821 */   addu  $t3, $v1, $t9
/* 0AA270 7F075740 ACEB0014 */  sw    $t3, 0x14($a3)
.L7F075744:
/* 0AA274 7F075744 84E3000E */  lh    $v1, 0xe($a3)
/* 0AA278 7F075748 5860000E */  blezl $v1, .L7F075784
/* 0AA27C 7F07574C ACE6001C */   sw    $a2, 0x1c($a3)
.L7F075750:
/* 0AA280 7F075750 8CEC0010 */  lw    $t4, 0x10($a3)
/* 0AA284 7F075754 00C56823 */  subu  $t5, $a2, $a1
/* 0AA288 7F075758 24420001 */  addiu $v0, $v0, 1
/* 0AA28C 7F07575C 01884821 */  addu  $t1, $t4, $t0
/* 0AA290 7F075760 8D2A0008 */  lw    $t2, 8($t1)
/* 0AA294 7F075764 11400003 */  beqz  $t2, .L7F075774
/* 0AA298 7F075768 014D7021 */   addu  $t6, $t2, $t5
/* 0AA29C 7F07576C AD2E0008 */  sw    $t6, 8($t1)
/* 0AA2A0 7F075770 84E3000E */  lh    $v1, 0xe($a3)
.L7F075774:
/* 0AA2A4 7F075774 0043082A */  slt   $at, $v0, $v1
/* 0AA2A8 7F075778 1420FFF5 */  bnez  $at, .L7F075750
/* 0AA2AC 7F07577C 25080010 */   addiu $t0, $t0, 0x10
/* 0AA2B0 7F075780 ACE6001C */  sw    $a2, 0x1c($a3)
.L7F075784:
/* 0AA2B4 7F075784 100000B0 */  b     .L7F075A48
/* 0AA2B8 7F075788 8C830014 */   lw    $v1, 0x14($a0)
.L7F07578C:
/* 0AA2BC 7F07578C 8C820004 */  lw    $v0, 4($a0)
/* 0AA2C0 7F075790 00C57823 */  subu  $t7, $a2, $a1
/* 0AA2C4 7F075794 8C430004 */  lw    $v1, 4($v0)
/* 0AA2C8 7F075798 10600002 */  beqz  $v1, .L7F0757A4
/* 0AA2CC 7F07579C 006FC021 */   addu  $t8, $v1, $t7
/* 0AA2D0 7F0757A0 AC580004 */  sw    $t8, 4($v0)
.L7F0757A4:
/* 0AA2D4 7F0757A4 100000A8 */  b     .L7F075A48
/* 0AA2D8 7F0757A8 8C830014 */   lw    $v1, 0x14($a0)
.L7F0757AC:
/* 0AA2DC 7F0757AC 8C870004 */  lw    $a3, 4($a0)
/* 0AA2E0 7F0757B0 00C5C823 */  subu  $t9, $a2, $a1
/* 0AA2E4 7F0757B4 00001025 */  move  $v0, $zero
/* 0AA2E8 7F0757B8 8CE30004 */  lw    $v1, 4($a3)
/* 0AA2EC 7F0757BC 00C56023 */  subu  $t4, $a2, $a1
/* 0AA2F0 7F0757C0 00C57023 */  subu  $t6, $a2, $a1
/* 0AA2F4 7F0757C4 10600002 */  beqz  $v1, .L7F0757D0
/* 0AA2F8 7F0757C8 00795821 */   addu  $t3, $v1, $t9
/* 0AA2FC 7F0757CC ACEB0004 */  sw    $t3, 4($a3)
.L7F0757D0:
/* 0AA300 7F0757D0 8CE30008 */  lw    $v1, 8($a3)
/* 0AA304 7F0757D4 00004025 */  move  $t0, $zero
/* 0AA308 7F0757D8 10600002 */  beqz  $v1, .L7F0757E4
/* 0AA30C 7F0757DC 006C6821 */   addu  $t5, $v1, $t4
/* 0AA310 7F0757E0 ACED0008 */  sw    $t5, 8($a3)
.L7F0757E4:
/* 0AA314 7F0757E4 8CE3000C */  lw    $v1, 0xc($a3)
/* 0AA318 7F0757E8 10600002 */  beqz  $v1, .L7F0757F4
/* 0AA31C 7F0757EC 006E7821 */   addu  $t7, $v1, $t6
/* 0AA320 7F0757F0 ACEF000C */  sw    $t7, 0xc($a3)
.L7F0757F4:
/* 0AA324 7F0757F4 8CE30000 */  lw    $v1, ($a3)
/* 0AA328 7F0757F8 5860000E */  blezl $v1, .L7F075834
/* 0AA32C 7F0757FC ACE601A4 */   sw    $a2, 0x1a4($a3)
.L7F075800:
/* 0AA330 7F075800 8CF80004 */  lw    $t8, 4($a3)
/* 0AA334 7F075804 00C5C823 */  subu  $t9, $a2, $a1
/* 0AA338 7F075808 24420001 */  addiu $v0, $v0, 1
/* 0AA33C 7F07580C 03084821 */  addu  $t1, $t8, $t0
/* 0AA340 7F075810 8D2A0004 */  lw    $t2, 4($t1)
/* 0AA344 7F075814 11400003 */  beqz  $t2, .L7F075824
/* 0AA348 7F075818 01595821 */   addu  $t3, $t2, $t9
/* 0AA34C 7F07581C AD2B0004 */  sw    $t3, 4($t1)
/* 0AA350 7F075820 8CE30000 */  lw    $v1, ($a3)
.L7F075824:
/* 0AA354 7F075824 0043082A */  slt   $at, $v0, $v1
/* 0AA358 7F075828 1420FFF5 */  bnez  $at, .L7F075800
/* 0AA35C 7F07582C 25080008 */   addiu $t0, $t0, 8
/* 0AA360 7F075830 ACE601A4 */  sw    $a2, 0x1a4($a3)
.L7F075834:
/* 0AA364 7F075834 10000084 */  b     .L7F075A48
/* 0AA368 7F075838 8C830014 */   lw    $v1, 0x14($a0)
.L7F07583C:
/* 0AA36C 7F07583C 8C870004 */  lw    $a3, 4($a0)
/* 0AA370 7F075840 00C56023 */  subu  $t4, $a2, $a1
/* 0AA374 7F075844 00001025 */  move  $v0, $zero
/* 0AA378 7F075848 8CE30000 */  lw    $v1, ($a3)
/* 0AA37C 7F07584C 00C57023 */  subu  $t6, $a2, $a1
/* 0AA380 7F075850 00C5C023 */  subu  $t8, $a2, $a1
/* 0AA384 7F075854 10600002 */  beqz  $v1, .L7F075860
/* 0AA388 7F075858 006C6821 */   addu  $t5, $v1, $t4
/* 0AA38C 7F07585C ACED0000 */  sw    $t5, ($a3)
.L7F075860:
/* 0AA390 7F075860 8CE30004 */  lw    $v1, 4($a3)
/* 0AA394 7F075864 00C55823 */  subu  $t3, $a2, $a1
/* 0AA398 7F075868 00C56823 */  subu  $t5, $a2, $a1
/* 0AA39C 7F07586C 10600002 */  beqz  $v1, .L7F075878
/* 0AA3A0 7F075870 006E7821 */   addu  $t7, $v1, $t6
/* 0AA3A4 7F075874 ACEF0004 */  sw    $t7, 4($a3)
.L7F075878:
/* 0AA3A8 7F075878 8CE3000C */  lw    $v1, 0xc($a3)
/* 0AA3AC 7F07587C 00004025 */  move  $t0, $zero
/* 0AA3B0 7F075880 10600002 */  beqz  $v1, .L7F07588C
/* 0AA3B4 7F075884 0078C821 */   addu  $t9, $v1, $t8
/* 0AA3B8 7F075888 ACF9000C */  sw    $t9, 0xc($a3)
.L7F07588C:
/* 0AA3BC 7F07588C 8CE30010 */  lw    $v1, 0x10($a3)
/* 0AA3C0 7F075890 10600002 */  beqz  $v1, .L7F07589C
/* 0AA3C4 7F075894 006B6021 */   addu  $t4, $v1, $t3
/* 0AA3C8 7F075898 ACEC0010 */  sw    $t4, 0x10($a3)
.L7F07589C:
/* 0AA3CC 7F07589C 8CE30014 */  lw    $v1, 0x14($a3)
/* 0AA3D0 7F0758A0 10600002 */  beqz  $v1, .L7F0758AC
/* 0AA3D4 7F0758A4 006D7021 */   addu  $t6, $v1, $t5
/* 0AA3D8 7F0758A8 ACEE0014 */  sw    $t6, 0x14($a3)
.L7F0758AC:
/* 0AA3DC 7F0758AC 8CE30008 */  lw    $v1, 8($a3)
/* 0AA3E0 7F0758B0 5860000E */  blezl $v1, .L7F0758EC
/* 0AA3E4 7F0758B4 ACE601AC */   sw    $a2, 0x1ac($a3)
.L7F0758B8:
/* 0AA3E8 7F0758B8 8CEF000C */  lw    $t7, 0xc($a3)
/* 0AA3EC 7F0758BC 00C5C023 */  subu  $t8, $a2, $a1
/* 0AA3F0 7F0758C0 24420001 */  addiu $v0, $v0, 1
/* 0AA3F4 7F0758C4 01E84821 */  addu  $t1, $t7, $t0
/* 0AA3F8 7F0758C8 8D2A0004 */  lw    $t2, 4($t1)
/* 0AA3FC 7F0758CC 11400003 */  beqz  $t2, .L7F0758DC
/* 0AA400 7F0758D0 0158C821 */   addu  $t9, $t2, $t8
/* 0AA404 7F0758D4 AD390004 */  sw    $t9, 4($t1)
/* 0AA408 7F0758D8 8CE30008 */  lw    $v1, 8($a3)
.L7F0758DC:
/* 0AA40C 7F0758DC 0043082A */  slt   $at, $v0, $v1
/* 0AA410 7F0758E0 1420FFF5 */  bnez  $at, .L7F0758B8
/* 0AA414 7F0758E4 25080008 */   addiu $t0, $t0, 8
/* 0AA418 7F0758E8 ACE601AC */  sw    $a2, 0x1ac($a3)
.L7F0758EC:
/* 0AA41C 7F0758EC 10000056 */  b     .L7F075A48
/* 0AA420 7F0758F0 8C830014 */   lw    $v1, 0x14($a0)
.L7F0758F4:
/* 0AA424 7F0758F4 8C820004 */  lw    $v0, 4($a0)
/* 0AA428 7F0758F8 AC460014 */  sw    $a2, 0x14($v0)
/* 0AA42C 7F0758FC 10000052 */  b     .L7F075A48
/* 0AA430 7F075900 8C830014 */   lw    $v1, 0x14($a0)
.L7F075904:
/* 0AA434 7F075904 8C820004 */  lw    $v0, 4($a0)
/* 0AA438 7F075908 00C55823 */  subu  $t3, $a2, $a1
/* 0AA43C 7F07590C 8C470008 */  lw    $a3, 8($v0)
/* 0AA440 7F075910 10E00003 */  beqz  $a3, .L7F075920
/* 0AA444 7F075914 00EB6021 */   addu  $t4, $a3, $t3
/* 0AA448 7F075918 AC4C0008 */  sw    $t4, 8($v0)
/* 0AA44C 7F07591C 01803825 */  move  $a3, $t4
.L7F075920:
/* 0AA450 7F075920 AC870014 */  sw    $a3, 0x14($a0)
/* 0AA454 7F075924 10000048 */  b     .L7F075A48
/* 0AA458 7F075928 00E01825 */   move  $v1, $a3
.L7F07592C:
/* 0AA45C 7F07592C 8C820004 */  lw    $v0, 4($a0)
/* 0AA460 7F075930 00C56823 */  subu  $t5, $a2, $a1
/* 0AA464 7F075934 8C430000 */  lw    $v1, ($v0)
/* 0AA468 7F075938 10600002 */  beqz  $v1, .L7F075944
/* 0AA46C 7F07593C 006D7021 */   addu  $t6, $v1, $t5
/* 0AA470 7F075940 AC4E0000 */  sw    $t6, ($v0)
.L7F075944:
/* 0AA474 7F075944 10000040 */  b     .L7F075A48
/* 0AA478 7F075948 8C830014 */   lw    $v1, 0x14($a0)
.L7F07594C:
/* 0AA47C 7F07594C 8C820004 */  lw    $v0, 4($a0)
/* 0AA480 7F075950 00C57823 */  subu  $t7, $a2, $a1
/* 0AA484 7F075954 00C5C823 */  subu  $t9, $a2, $a1
/* 0AA488 7F075958 8C430018 */  lw    $v1, 0x18($v0)
/* 0AA48C 7F07595C 10600002 */  beqz  $v1, .L7F075968
/* 0AA490 7F075960 006FC021 */   addu  $t8, $v1, $t7
/* 0AA494 7F075964 AC580018 */  sw    $t8, 0x18($v0)
.L7F075968:
/* 0AA498 7F075968 8C43001C */  lw    $v1, 0x1c($v0)
/* 0AA49C 7F07596C 10600002 */  beqz  $v1, .L7F075978
/* 0AA4A0 7F075970 00795821 */   addu  $t3, $v1, $t9
/* 0AA4A4 7F075974 AC4B001C */  sw    $t3, 0x1c($v0)
.L7F075978:
/* 0AA4A8 7F075978 10000033 */  b     .L7F075A48
/* 0AA4AC 7F07597C 8C830014 */   lw    $v1, 0x14($a0)
.L7F075980:
/* 0AA4B0 7F075980 8C820004 */  lw    $v0, 4($a0)
/* 0AA4B4 7F075984 00C56023 */  subu  $t4, $a2, $a1
/* 0AA4B8 7F075988 8C430014 */  lw    $v1, 0x14($v0)
/* 0AA4BC 7F07598C 10600002 */  beqz  $v1, .L7F075998
/* 0AA4C0 7F075990 006C6821 */   addu  $t5, $v1, $t4
/* 0AA4C4 7F075994 AC4D0014 */  sw    $t5, 0x14($v0)
.L7F075998:
/* 0AA4C8 7F075998 1000002B */  b     .L7F075A48
/* 0AA4CC 7F07599C 8C830014 */   lw    $v1, 0x14($a0)
.L7F0759A0:
/* 0AA4D0 7F0759A0 8C820004 */  lw    $v0, 4($a0)
/* 0AA4D4 7F0759A4 00C57023 */  subu  $t6, $a2, $a1
/* 0AA4D8 7F0759A8 8C43003C */  lw    $v1, 0x3c($v0)
/* 0AA4DC 7F0759AC 10600002 */  beqz  $v1, .L7F0759B8
/* 0AA4E0 7F0759B0 006E7821 */   addu  $t7, $v1, $t6
/* 0AA4E4 7F0759B4 AC4F003C */  sw    $t7, 0x3c($v0)
.L7F0759B8:
/* 0AA4E8 7F0759B8 AC460048 */  sw    $a2, 0x48($v0)
/* 0AA4EC 7F0759BC 10000022 */  b     .L7F075A48
/* 0AA4F0 7F0759C0 8C830014 */   lw    $v1, 0x14($a0)
.L7F0759C4:
/* 0AA4F4 7F0759C4 8C820004 */  lw    $v0, 4($a0)
/* 0AA4F8 7F0759C8 00C5C023 */  subu  $t8, $a2, $a1
/* 0AA4FC 7F0759CC 8C430018 */  lw    $v1, 0x18($v0)
/* 0AA500 7F0759D0 10600002 */  beqz  $v1, .L7F0759DC
/* 0AA504 7F0759D4 0078C821 */   addu  $t9, $v1, $t8
/* 0AA508 7F0759D8 AC590018 */  sw    $t9, 0x18($v0)
.L7F0759DC:
/* 0AA50C 7F0759DC AC460024 */  sw    $a2, 0x24($v0)
/* 0AA510 7F0759E0 10000019 */  b     .L7F075A48
/* 0AA514 7F0759E4 8C830014 */   lw    $v1, 0x14($a0)
.L7F0759E8:
/* 0AA518 7F0759E8 8C820004 */  lw    $v0, 4($a0)
/* 0AA51C 7F0759EC 00C55823 */  subu  $t3, $a2, $a1
/* 0AA520 7F0759F0 00C56823 */  subu  $t5, $a2, $a1
/* 0AA524 7F0759F4 8C430010 */  lw    $v1, 0x10($v0)
/* 0AA528 7F0759F8 10600002 */  beqz  $v1, .L7F075A04
/* 0AA52C 7F0759FC 006B6021 */   addu  $t4, $v1, $t3
/* 0AA530 7F075A00 AC4C0010 */  sw    $t4, 0x10($v0)
.L7F075A04:
/* 0AA534 7F075A04 8C430014 */  lw    $v1, 0x14($v0)
/* 0AA538 7F075A08 10600002 */  beqz  $v1, .L7F075A14
/* 0AA53C 7F075A0C 006D7021 */   addu  $t6, $v1, $t5
/* 0AA540 7F075A10 AC4E0014 */  sw    $t6, 0x14($v0)
.L7F075A14:
/* 0AA544 7F075A14 AC46001C */  sw    $a2, 0x1c($v0)
/* 0AA548 7F075A18 1000000B */  b     .L7F075A48
/* 0AA54C 7F075A1C 8C830014 */   lw    $v1, 0x14($a0)
.L7F075A20:
/* 0AA550 7F075A20 8C820004 */  lw    $v0, 4($a0)
/* 0AA554 7F075A24 00C57823 */  subu  $t7, $a2, $a1
/* 0AA558 7F075A28 8C430004 */  lw    $v1, 4($v0)
/* 0AA55C 7F075A2C 10600002 */  beqz  $v1, .L7F075A38
/* 0AA560 7F075A30 006FC021 */   addu  $t8, $v1, $t7
/* 0AA564 7F075A34 AC580004 */  sw    $t8, 4($v0)
.L7F075A38:
/* 0AA568 7F075A38 AC46000C */  sw    $a2, 0xc($v0)
/* 0AA56C 7F075A3C 10000002 */  b     .L7F075A48
/* 0AA570 7F075A40 8C830014 */   lw    $v1, 0x14($a0)
def_7F075670:
.L7F075A44:
/* 0AA574 7F075A44 8C830014 */  lw    $v1, 0x14($a0)
.L7F075A48:
/* 0AA578 7F075A48 10600003 */  beqz  $v1, .L7F075A58
/* 0AA57C 7F075A4C 00000000 */   nop   
/* 0AA580 7F075A50 1000000B */  b     .L7F075A80
/* 0AA584 7F075A54 00602025 */   move  $a0, $v1
.L7F075A58:
/* 0AA588 7F075A58 10800009 */  beqz  $a0, .L7F075A80
/* 0AA58C 7F075A5C 00000000 */   nop   
/* 0AA590 7F075A60 8C83000C */  lw    $v1, 0xc($a0)
.L7F075A64:
/* 0AA594 7F075A64 50600004 */  beql  $v1, $zero, .L7F075A78
/* 0AA598 7F075A68 8C840008 */   lw    $a0, 8($a0)
/* 0AA59C 7F075A6C 10000004 */  b     .L7F075A80
/* 0AA5A0 7F075A70 00602025 */   move  $a0, $v1
/* 0AA5A4 7F075A74 8C840008 */  lw    $a0, 8($a0)
.L7F075A78:
/* 0AA5A8 7F075A78 5480FFFA */  bnezl $a0, .L7F075A64
/* 0AA5AC 7F075A7C 8C83000C */   lw    $v1, 0xc($a0)
.L7F075A80:
/* 0AA5B0 7F075A80 5480FED9 */  bnezl $a0, .L7F0755E8
/* 0AA5B4 7F075A84 94820000 */   lhu   $v0, ($a0)
.L7F075A88:
/* 0AA5B8 7F075A88 03E00008 */  jr    $ra
/* 0AA5BC 7F075A8C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F075A90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F075A90
/* 0AA5C0 7F075A90 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AA5C4 7F075A94 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AA5C8 7F075A98 AFB10018 */  sw    $s1, 0x18($sp)
/* 0AA5CC 7F075A9C AFB00014 */  sw    $s0, 0x14($sp)
/* 0AA5D0 7F075AA0 8487000C */  lh    $a3, 0xc($a0)
/* 0AA5D4 7F075AA4 00808025 */  move  $s0, $a0
/* 0AA5D8 7F075AA8 00A08825 */  move  $s1, $a1
/* 0AA5DC 7F075AAC 18E0000E */  blez  $a3, .L7F075AE8
/* 0AA5E0 7F075AB0 00001025 */   move  $v0, $zero
/* 0AA5E4 7F075AB4 00001825 */  move  $v1, $zero
.L7F075AB8:
/* 0AA5E8 7F075AB8 8E0E0008 */  lw    $t6, 8($s0)
/* 0AA5EC 7F075ABC 00D17823 */  subu  $t7, $a2, $s1
/* 0AA5F0 7F075AC0 24420001 */  addiu $v0, $v0, 1
/* 0AA5F4 7F075AC4 01C32021 */  addu  $a0, $t6, $v1
/* 0AA5F8 7F075AC8 8C850000 */  lw    $a1, ($a0)
/* 0AA5FC 7F075ACC 10A00003 */  beqz  $a1, .L7F075ADC
/* 0AA600 7F075AD0 00AFC021 */   addu  $t8, $a1, $t7
/* 0AA604 7F075AD4 AC980000 */  sw    $t8, ($a0)
/* 0AA608 7F075AD8 8607000C */  lh    $a3, 0xc($s0)
.L7F075ADC:
/* 0AA60C 7F075ADC 0047082A */  slt   $at, $v0, $a3
/* 0AA610 7F075AE0 1420FFF5 */  bnez  $at, .L7F075AB8
/* 0AA614 7F075AE4 24630004 */   addiu $v1, $v1, 4
.L7F075AE8:
/* 0AA618 7F075AE8 8E040000 */  lw    $a0, ($s0)
/* 0AA61C 7F075AEC 0FC1D577 */  jal   convert_obj_microcode_offset_to_rdram_addr
/* 0AA620 7F075AF0 02202825 */   move  $a1, $s1
/* 0AA624 7F075AF4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AA628 7F075AF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0AA62C 7F075AFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0AA630 7F075B00 03E00008 */  jr    $ra
/* 0AA634 7F075B04 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F075B08(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F075B08
/* 0AA638 7F075B08 AFA40000 */  sw    $a0, ($sp)
/* 0AA63C 7F075B0C AFA50004 */  sw    $a1, 4($sp)
/* 0AA640 7F075B10 AFA60008 */  sw    $a2, 8($sp)
/* 0AA644 7F075B14 03E00008 */  jr    $ra
/* 0AA648 7F075B18 AFA7000C */   sw    $a3, 0xc($sp)
)
#endif





#ifdef NONMATCHING
void set_microcode_entry_numbers(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054E74*/
glabel jpt_80054E74
.word .L7F075B68
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075B84
.word .L7F075BA0
.word .L7F075C00
.word .L7F075C84
.word .L7F075C30
.word .L7F075C4C
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075BC0
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075BE0
.word .L7F075C68

.text
glabel set_microcode_entry_numbers
/* 0AA64C 7F075B1C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AA650 7F075B20 AFB10018 */  sw    $s1, 0x18($sp)
/* 0AA654 7F075B24 AFB00014 */  sw    $s0, 0x14($sp)
/* 0AA658 7F075B28 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AA65C 7F075B2C 00803025 */  move  $a2, $a0
/* 0AA660 7F075B30 00008825 */  move  $s1, $zero
/* 0AA664 7F075B34 10800069 */  beqz  $a0, .L7F075CDC
/* 0AA668 7F075B38 00808025 */   move  $s0, $a0
/* 0AA66C 7F075B3C 96020000 */  lhu   $v0, ($s0)
.L7F075B40:
/* 0AA670 7F075B40 304E00FF */  andi  $t6, $v0, 0xff
/* 0AA674 7F075B44 25CFFFFF */  addiu $t7, $t6, -1
/* 0AA678 7F075B48 2DE10018 */  sltiu $at, $t7, 0x18
/* 0AA67C 7F075B4C 1020004D */  beqz  $at, .L7F075C84
/* 0AA680 7F075B50 000F7880 */   sll   $t7, $t7, 2
/* 0AA684 7F075B54 3C018005 */  lui   $at, %hi(jpt_80054E74)
/* 0AA688 7F075B58 002F0821 */  addu  $at, $at, $t7
/* 0AA68C 7F075B5C 8C2F4E74 */  lw    $t7, %lo(jpt_80054E74)($at)
.L7F075B60:
/* 0AA690 7F075B60 01E00008 */  jr    $t7
/* 0AA694 7F075B64 00000000 */   nop   
.L7F075B68:
/* 0AA698 7F075B68 8E020004 */  lw    $v0, 4($s0)
/* 0AA69C 7F075B6C A451000C */  sh    $s1, 0xc($v0)
/* 0AA6A0 7F075B70 26310018 */  addiu $s1, $s1, 0x18
/* 0AA6A4 7F075B74 3238FFFF */  andi  $t8, $s1, 0xffff
/* 0AA6A8 7F075B78 03008825 */  move  $s1, $t8
/* 0AA6AC 7F075B7C 10000042 */  b     .L7F075C88
/* 0AA6B0 7F075B80 8E030014 */   lw    $v1, 0x14($s0)
.L7F075B84:
/* 0AA6B4 7F075B84 8E020004 */  lw    $v0, 4($s0)
/* 0AA6B8 7F075B88 A45101AA */  sh    $s1, 0x1aa($v0)
/* 0AA6BC 7F075B8C 26310001 */  addiu $s1, $s1, 1
/* 0AA6C0 7F075B90 3239FFFF */  andi  $t9, $s1, 0xffff
/* 0AA6C4 7F075B94 03208825 */  move  $s1, $t9
/* 0AA6C8 7F075B98 1000003B */  b     .L7F075C88
/* 0AA6CC 7F075B9C 8E030014 */   lw    $v1, 0x14($s0)
.L7F075BA0:
/* 0AA6D0 7F075BA0 8E020004 */  lw    $v0, 4($s0)
/* 0AA6D4 7F075BA4 A451000C */  sh    $s1, 0xc($v0)
/* 0AA6D8 7F075BA8 8C430008 */  lw    $v1, 8($v0)
/* 0AA6DC 7F075BAC 26310001 */  addiu $s1, $s1, 1
/* 0AA6E0 7F075BB0 3228FFFF */  andi  $t0, $s1, 0xffff
/* 0AA6E4 7F075BB4 01008825 */  move  $s1, $t0
/* 0AA6E8 7F075BB8 10000033 */  b     .L7F075C88
/* 0AA6EC 7F075BBC AE030014 */   sw    $v1, 0x14($s0)
.L7F075BC0:
/* 0AA6F0 7F075BC0 8E020004 */  lw    $v0, 4($s0)
/* 0AA6F4 7F075BC4 A4510004 */  sh    $s1, 4($v0)
/* 0AA6F8 7F075BC8 8C430000 */  lw    $v1, ($v0)
/* 0AA6FC 7F075BCC 26310001 */  addiu $s1, $s1, 1
/* 0AA700 7F075BD0 322AFFFF */  andi  $t2, $s1, 0xffff
/* 0AA704 7F075BD4 01408825 */  move  $s1, $t2
/* 0AA708 7F075BD8 1000002B */  b     .L7F075C88
/* 0AA70C 7F075BDC AE030014 */   sw    $v1, 0x14($s0)
.L7F075BE0:
/* 0AA710 7F075BE0 8E020004 */  lw    $v0, 4($s0)
/* 0AA714 7F075BE4 00001825 */  move  $v1, $zero
/* 0AA718 7F075BE8 A4510000 */  sh    $s1, ($v0)
/* 0AA71C 7F075BEC 26310002 */  addiu $s1, $s1, 2
/* 0AA720 7F075BF0 322CFFFF */  andi  $t4, $s1, 0xffff
/* 0AA724 7F075BF4 01808825 */  move  $s1, $t4
/* 0AA728 7F075BF8 10000023 */  b     .L7F075C88
/* 0AA72C 7F075BFC AE000014 */   sw    $zero, 0x14($s0)
.L7F075C00:
/* 0AA730 7F075C00 8E020004 */  lw    $v0, 4($s0)
/* 0AA734 7F075C04 02002025 */  move  $a0, $s0
/* 0AA738 7F075C08 00002825 */  move  $a1, $zero
/* 0AA73C 7F075C0C A4510022 */  sh    $s1, 0x22($v0)
/* 0AA740 7F075C10 26310001 */  addiu $s1, $s1, 1
/* 0AA744 7F075C14 322DFFFF */  andi  $t5, $s1, 0xffff
/* 0AA748 7F075C18 01A08825 */  move  $s1, $t5
/* 0AA74C 7F075C1C 0FC1BA95 */  jal   sub_GAME_7F06EA54
/* 0AA750 7F075C20 AFA60020 */   sw    $a2, 0x20($sp)
/* 0AA754 7F075C24 8FA60020 */  lw    $a2, 0x20($sp)
/* 0AA758 7F075C28 10000017 */  b     .L7F075C88
/* 0AA75C 7F075C2C 8E030014 */   lw    $v1, 0x14($s0)
.L7F075C30:
/* 0AA760 7F075C30 8E020004 */  lw    $v0, 4($s0)
/* 0AA764 7F075C34 A4510044 */  sh    $s1, 0x44($v0)
/* 0AA768 7F075C38 26310001 */  addiu $s1, $s1, 1
/* 0AA76C 7F075C3C 322EFFFF */  andi  $t6, $s1, 0xffff
/* 0AA770 7F075C40 01C08825 */  move  $s1, $t6
/* 0AA774 7F075C44 10000010 */  b     .L7F075C88
/* 0AA778 7F075C48 8E030014 */   lw    $v1, 0x14($s0)
.L7F075C4C:
/* 0AA77C 7F075C4C 8E020004 */  lw    $v0, 4($s0)
/* 0AA780 7F075C50 A4510020 */  sh    $s1, 0x20($v0)
/* 0AA784 7F075C54 26310001 */  addiu $s1, $s1, 1
/* 0AA788 7F075C58 322FFFFF */  andi  $t7, $s1, 0xffff
/* 0AA78C 7F075C5C 01E08825 */  move  $s1, $t7
/* 0AA790 7F075C60 10000009 */  b     .L7F075C88
/* 0AA794 7F075C64 8E030014 */   lw    $v1, 0x14($s0)
.L7F075C68:
/* 0AA798 7F075C68 8E020004 */  lw    $v0, 4($s0)
/* 0AA79C 7F075C6C A451001A */  sh    $s1, 0x1a($v0)
/* 0AA7A0 7F075C70 26310002 */  addiu $s1, $s1, 2
/* 0AA7A4 7F075C74 3238FFFF */  andi  $t8, $s1, 0xffff
/* 0AA7A8 7F075C78 03008825 */  move  $s1, $t8
/* 0AA7AC 7F075C7C 10000002 */  b     .L7F075C88
/* 0AA7B0 7F075C80 8E030014 */   lw    $v1, 0x14($s0)
def_7F075B60:
.L7F075C84:
/* 0AA7B4 7F075C84 8E030014 */  lw    $v1, 0x14($s0)
.L7F075C88:
/* 0AA7B8 7F075C88 10600003 */  beqz  $v1, .L7F075C98
/* 0AA7BC 7F075C8C 00000000 */   nop   
/* 0AA7C0 7F075C90 10000010 */  b     .L7F075CD4
/* 0AA7C4 7F075C94 00608025 */   move  $s0, $v1
.L7F075C98:
/* 0AA7C8 7F075C98 1200000E */  beqz  $s0, .L7F075CD4
/* 0AA7CC 7F075C9C 00000000 */   nop   
/* 0AA7D0 7F075CA0 8CC30008 */  lw    $v1, 8($a2)
.L7F075CA4:
/* 0AA7D4 7F075CA4 56030004 */  bnel  $s0, $v1, .L7F075CB8
/* 0AA7D8 7F075CA8 8E02000C */   lw    $v0, 0xc($s0)
/* 0AA7DC 7F075CAC 10000009 */  b     .L7F075CD4
/* 0AA7E0 7F075CB0 00008025 */   move  $s0, $zero
/* 0AA7E4 7F075CB4 8E02000C */  lw    $v0, 0xc($s0)
.L7F075CB8:
/* 0AA7E8 7F075CB8 50400004 */  beql  $v0, $zero, .L7F075CCC
/* 0AA7EC 7F075CBC 8E100008 */   lw    $s0, 8($s0)
/* 0AA7F0 7F075CC0 10000004 */  b     .L7F075CD4
/* 0AA7F4 7F075CC4 00408025 */   move  $s0, $v0
/* 0AA7F8 7F075CC8 8E100008 */  lw    $s0, 8($s0)
.L7F075CCC:
/* 0AA7FC 7F075CCC 1600FFF5 */  bnez  $s0, .L7F075CA4
/* 0AA800 7F075CD0 00000000 */   nop   
.L7F075CD4:
/* 0AA804 7F075CD4 5600FF9A */  bnezl $s0, .L7F075B40
/* 0AA808 7F075CD8 96020000 */   lhu   $v0, ($s0)
.L7F075CDC:
/* 0AA80C 7F075CDC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AA810 7F075CE0 02201025 */  move  $v0, $s1
/* 0AA814 7F075CE4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0AA818 7F075CE8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0AA81C 7F075CEC 03E00008 */  jr    $ra
/* 0AA820 7F075CF0 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void set_objuse_flag_compute_grp_nums_set_obj_loaded(void *arg0, void *arg6) {
    // Node 0
    arg0->unk1C = 1;
    arg6->unk14 = set_microcode_entry_numbers(*arg0, arg0);
    return;
    // (possible return value: set_microcode_entry_numbers(*arg0, arg0))
}

#else
GLOBAL_ASM(
.text
glabel set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 0AA824 7F075CF4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AA828 7F075CF8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0AA82C 7F075CFC 240E0001 */  li    $t6, 1
/* 0AA830 7F075D00 00802825 */  move  $a1, $a0
/* 0AA834 7F075D04 AC8E001C */  sw    $t6, 0x1c($a0)
/* 0AA838 7F075D08 8C840000 */  lw    $a0, ($a0)
/* 0AA83C 7F075D0C 0FC1D6C7 */  jal   set_microcode_entry_numbers
/* 0AA840 7F075D10 AFA50018 */   sw    $a1, 0x18($sp)
/* 0AA844 7F075D14 8FA50018 */  lw    $a1, 0x18($sp)
/* 0AA848 7F075D18 A4A20014 */  sh    $v0, 0x14($a1)
/* 0AA84C 7F075D1C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0AA850 7F075D20 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AA854 7F075D24 03E00008 */  jr    $ra
/* 0AA858 7F075D28 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void unknown_object_microcode_handler(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054ED4*/
glabel jpt_80054ED4
.word .L7F075D88
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E00
.word .L7F075E18
.word .L7F075E78
.word .L7F075EF4
.word .L7F075E9C
.word .L7F075EB4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E38
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E5C
.word .L7F075ECC

.text
glabel unknown_object_microcode_handler
/* 0AA85C 7F075D2C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0AA860 7F075D30 AFB20028 */  sw    $s2, 0x28($sp)
/* 0AA864 7F075D34 AFB00020 */  sw    $s0, 0x20($sp)
/* 0AA868 7F075D38 00809025 */  move  $s2, $a0
/* 0AA86C 7F075D3C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0AA870 7F075D40 AFB10024 */  sw    $s1, 0x24($sp)
/* 0AA874 7F075D44 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0AA878 7F075D48 AFA50034 */  sw    $a1, 0x34($sp)
/* 0AA87C 7F075D4C 10A0007F */  beqz  $a1, .L7F075F4C
/* 0AA880 7F075D50 00A08025 */   move  $s0, $a1
/* 0AA884 7F075D54 4480A000 */  mtc1  $zero, $f20
/* 0AA888 7F075D58 00000000 */  nop   
/* 0AA88C 7F075D5C 96020000 */  lhu   $v0, ($s0)
.L7F075D60:
/* 0AA890 7F075D60 304F00FF */  andi  $t7, $v0, 0xff
/* 0AA894 7F075D64 25F8FFFF */  addiu $t8, $t7, -1
/* 0AA898 7F075D68 2F010018 */  sltiu $at, $t8, 0x18
/* 0AA89C 7F075D6C 10200061 */  beqz  $at, .L7F075EF4
/* 0AA8A0 7F075D70 0018C080 */   sll   $t8, $t8, 2
/* 0AA8A4 7F075D74 3C018005 */  lui   $at, %hi(jpt_80054ED4)
/* 0AA8A8 7F075D78 00380821 */  addu  $at, $at, $t8
/* 0AA8AC 7F075D7C 8C384ED4 */  lw    $t8, %lo(jpt_80054ED4)($at)
.L7F075D80:
/* 0AA8B0 7F075D80 03000008 */  jr    $t8
/* 0AA8B4 7F075D84 00000000 */   nop   
.L7F075D88:
/* 0AA8B8 7F075D88 02402025 */  move  $a0, $s2
/* 0AA8BC 7F075D8C 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA8C0 7F075D90 02002825 */   move  $a1, $s0
/* 0AA8C4 7F075D94 A0400000 */  sb    $zero, ($v0)
/* 0AA8C8 7F075D98 E4540004 */  swc1  $f20, 4($v0)
/* 0AA8CC 7F075D9C E4540008 */  swc1  $f20, 8($v0)
/* 0AA8D0 7F075DA0 E454000C */  swc1  $f20, 0xc($v0)
/* 0AA8D4 7F075DA4 E4540010 */  swc1  $f20, 0x10($v0)
/* 0AA8D8 7F075DA8 E4540014 */  swc1  $f20, 0x14($v0)
/* 0AA8DC 7F075DAC E4540018 */  swc1  $f20, 0x18($v0)
/* 0AA8E0 7F075DB0 E454001C */  swc1  $f20, 0x1c($v0)
/* 0AA8E4 7F075DB4 A0400001 */  sb    $zero, 1($v0)
/* 0AA8E8 7F075DB8 E4540034 */  swc1  $f20, 0x34($v0)
/* 0AA8EC 7F075DBC E4540038 */  swc1  $f20, 0x38($v0)
/* 0AA8F0 7F075DC0 E454003C */  swc1  $f20, 0x3c($v0)
/* 0AA8F4 7F075DC4 E4540030 */  swc1  $f20, 0x30($v0)
/* 0AA8F8 7F075DC8 E4540024 */  swc1  $f20, 0x24($v0)
/* 0AA8FC 7F075DCC E4540028 */  swc1  $f20, 0x28($v0)
/* 0AA900 7F075DD0 E454002C */  swc1  $f20, 0x2c($v0)
/* 0AA904 7F075DD4 E4540020 */  swc1  $f20, 0x20($v0)
/* 0AA908 7F075DD8 A0400002 */  sb    $zero, 2($v0)
/* 0AA90C 7F075DDC E454004C */  swc1  $f20, 0x4c($v0)
/* 0AA910 7F075DE0 E4540050 */  swc1  $f20, 0x50($v0)
/* 0AA914 7F075DE4 E4540054 */  swc1  $f20, 0x54($v0)
/* 0AA918 7F075DE8 E4540040 */  swc1  $f20, 0x40($v0)
/* 0AA91C 7F075DEC E4540044 */  swc1  $f20, 0x44($v0)
/* 0AA920 7F075DF0 E4540048 */  swc1  $f20, 0x48($v0)
/* 0AA924 7F075DF4 E454005C */  swc1  $f20, 0x5c($v0)
/* 0AA928 7F075DF8 1000003F */  b     .L7F075EF8
/* 0AA92C 7F075DFC 8E030014 */   lw    $v1, 0x14($s0)
.L7F075E00:
/* 0AA930 7F075E00 02402025 */  move  $a0, $s2
/* 0AA934 7F075E04 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA938 7F075E08 02002825 */   move  $a1, $s0
/* 0AA93C 7F075E0C AC400000 */  sw    $zero, ($v0)
/* 0AA940 7F075E10 10000039 */  b     .L7F075EF8
/* 0AA944 7F075E14 8E030014 */   lw    $v1, 0x14($s0)
.L7F075E18:
/* 0AA948 7F075E18 8E110004 */  lw    $s1, 4($s0)
/* 0AA94C 7F075E1C 02402025 */  move  $a0, $s2
/* 0AA950 7F075E20 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA954 7F075E24 02002825 */   move  $a1, $s0
/* 0AA958 7F075E28 AC400000 */  sw    $zero, ($v0)
/* 0AA95C 7F075E2C 8E230008 */  lw    $v1, 8($s1)
/* 0AA960 7F075E30 10000031 */  b     .L7F075EF8
/* 0AA964 7F075E34 AE030014 */   sw    $v1, 0x14($s0)
.L7F075E38:
/* 0AA968 7F075E38 8E110004 */  lw    $s1, 4($s0)
/* 0AA96C 7F075E3C 02402025 */  move  $a0, $s2
/* 0AA970 7F075E40 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA974 7F075E44 02002825 */   move  $a1, $s0
/* 0AA978 7F075E48 24080001 */  li    $t0, 1
/* 0AA97C 7F075E4C AC480000 */  sw    $t0, ($v0)
/* 0AA980 7F075E50 8E230000 */  lw    $v1, ($s1)
/* 0AA984 7F075E54 10000028 */  b     .L7F075EF8
/* 0AA988 7F075E58 AE030014 */   sw    $v1, 0x14($s0)
.L7F075E5C:
/* 0AA98C 7F075E5C 02402025 */  move  $a0, $s2
/* 0AA990 7F075E60 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA994 7F075E64 02002825 */   move  $a1, $s0
/* 0AA998 7F075E68 AC400000 */  sw    $zero, ($v0)
/* 0AA99C 7F075E6C AC400004 */  sw    $zero, 4($v0)
/* 0AA9A0 7F075E70 10000021 */  b     .L7F075EF8
/* 0AA9A4 7F075E74 8E030014 */   lw    $v1, 0x14($s0)
.L7F075E78:
/* 0AA9A8 7F075E78 02402025 */  move  $a0, $s2
/* 0AA9AC 7F075E7C 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA9B0 7F075E80 02002825 */   move  $a1, $s0
/* 0AA9B4 7F075E84 AC400000 */  sw    $zero, ($v0)
/* 0AA9B8 7F075E88 02402025 */  move  $a0, $s2
/* 0AA9BC 7F075E8C 0FC1BAC4 */  jal   sub_GAME_7F06EB10
/* 0AA9C0 7F075E90 02002825 */   move  $a1, $s0
/* 0AA9C4 7F075E94 10000018 */  b     .L7F075EF8
/* 0AA9C8 7F075E98 8E030014 */   lw    $v1, 0x14($s0)
.L7F075E9C:
/* 0AA9CC 7F075E9C 02402025 */  move  $a0, $s2
/* 0AA9D0 7F075EA0 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA9D4 7F075EA4 02002825 */   move  $a1, $s0
/* 0AA9D8 7F075EA8 A4400000 */  sh    $zero, ($v0)
/* 0AA9DC 7F075EAC 10000012 */  b     .L7F075EF8
/* 0AA9E0 7F075EB0 8E030014 */   lw    $v1, 0x14($s0)
.L7F075EB4:
/* 0AA9E4 7F075EB4 02402025 */  move  $a0, $s2
/* 0AA9E8 7F075EB8 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AA9EC 7F075EBC 02002825 */   move  $a1, $s0
/* 0AA9F0 7F075EC0 A4400000 */  sh    $zero, ($v0)
/* 0AA9F4 7F075EC4 1000000C */  b     .L7F075EF8
/* 0AA9F8 7F075EC8 8E030014 */   lw    $v1, 0x14($s0)
.L7F075ECC:
/* 0AA9FC 7F075ECC 8E110004 */  lw    $s1, 4($s0)
/* 0AAA00 7F075ED0 02402025 */  move  $a0, $s2
/* 0AAA04 7F075ED4 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AAA08 7F075ED8 02002825 */   move  $a1, $s0
/* 0AAA0C 7F075EDC 8E2A0008 */  lw    $t2, 8($s1)
/* 0AAA10 7F075EE0 AC4A0000 */  sw    $t2, ($v0)
/* 0AAA14 7F075EE4 8E2B0000 */  lw    $t3, ($s1)
/* 0AAA18 7F075EE8 AC4B0004 */  sw    $t3, 4($v0)
/* 0AAA1C 7F075EEC 10000002 */  b     .L7F075EF8
/* 0AAA20 7F075EF0 8E030014 */   lw    $v1, 0x14($s0)
def_7F075D80:
.L7F075EF4:
/* 0AAA24 7F075EF4 8E030014 */  lw    $v1, 0x14($s0)
.L7F075EF8:
/* 0AAA28 7F075EF8 10600003 */  beqz  $v1, .L7F075F08
/* 0AAA2C 7F075EFC 00000000 */   nop   
/* 0AAA30 7F075F00 10000010 */  b     .L7F075F44
/* 0AAA34 7F075F04 00608025 */   move  $s0, $v1
.L7F075F08:
/* 0AAA38 7F075F08 1200000E */  beqz  $s0, .L7F075F44
/* 0AAA3C 7F075F0C 8FAC0034 */   lw    $t4, 0x34($sp)
/* 0AAA40 7F075F10 8D830008 */  lw    $v1, 8($t4)
.L7F075F14:
/* 0AAA44 7F075F14 56030004 */  bnel  $s0, $v1, .L7F075F28
/* 0AAA48 7F075F18 8E02000C */   lw    $v0, 0xc($s0)
/* 0AAA4C 7F075F1C 10000009 */  b     .L7F075F44
/* 0AAA50 7F075F20 00008025 */   move  $s0, $zero
/* 0AAA54 7F075F24 8E02000C */  lw    $v0, 0xc($s0)
.L7F075F28:
/* 0AAA58 7F075F28 50400004 */  beql  $v0, $zero, .L7F075F3C
/* 0AAA5C 7F075F2C 8E100008 */   lw    $s0, 8($s0)
/* 0AAA60 7F075F30 10000004 */  b     .L7F075F44
/* 0AAA64 7F075F34 00408025 */   move  $s0, $v0
/* 0AAA68 7F075F38 8E100008 */  lw    $s0, 8($s0)
.L7F075F3C:
/* 0AAA6C 7F075F3C 1600FFF5 */  bnez  $s0, .L7F075F14
/* 0AAA70 7F075F40 00000000 */   nop   
.L7F075F44:
/* 0AAA74 7F075F44 5600FF86 */  bnezl $s0, .L7F075D60
/* 0AAA78 7F075F48 96020000 */   lhu   $v0, ($s0)
.L7F075F4C:
/* 0AAA7C 7F075F4C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0AAA80 7F075F50 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0AAA84 7F075F54 8FB00020 */  lw    $s0, 0x20($sp)
/* 0AAA88 7F075F58 8FB10024 */  lw    $s1, 0x24($sp)
/* 0AAA8C 7F075F5C 8FB20028 */  lw    $s2, 0x28($sp)
/* 0AAA90 7F075F60 03E00008 */  jr    $ra
/* 0AAA94 7F075F64 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F075F68(void *arg0, void *arg1, ?32 arg2) {
    // Node 0
    arg0->unk8 = arg1;
    arg0->unk10 = arg2;
    arg0->unk2 = (u16)-1;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = 1.0f;
    unknown_object_microcode_handler(*arg1);
    return;
    // (possible return value: unknown_object_microcode_handler(*arg1))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F075F68
/* 0AAA98 7F075F68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AAA9C 7F075F6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0AAAA0 7F075F70 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AAAA4 7F075F74 44812000 */  mtc1  $at, $f4
/* 0AAAA8 7F075F78 240EFFFF */  li    $t6, -1
/* 0AAAAC 7F075F7C AC850008 */  sw    $a1, 8($a0)
/* 0AAAB0 7F075F80 AC860010 */  sw    $a2, 0x10($a0)
/* 0AAAB4 7F075F84 A48E0002 */  sh    $t6, 2($a0)
/* 0AAAB8 7F075F88 AC800018 */  sw    $zero, 0x18($a0)
/* 0AAABC 7F075F8C AC80001C */  sw    $zero, 0x1c($a0)
/* 0AAAC0 7F075F90 E4840014 */  swc1  $f4, 0x14($a0)
/* 0AAAC4 7F075F94 0FC1D74B */  jal   unknown_object_microcode_handler
/* 0AAAC8 7F075F98 8CA50000 */   lw    $a1, ($a1)
/* 0AAACC 7F075F9C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0AAAD0 7F075FA0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AAAD4 7F075FA4 03E00008 */  jr    $ra
/* 0AAAD8 7F075FA8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F075FAC(s32 arg0, void *arg6) {
    // Node 0
    sub_GAME_7F075F68();
    arg6->unk20 = 0;
    arg6->unk54 = 0;
    arg6->unk26 = (u8)0;
    arg6->unk98 = 0;
    arg6->unk9C = 0;
    arg6->unkA0 = 0;
    arg6->unk2C = 0.0f;
    arg6->unk4C = 0.0f;
    arg6->unk5C = 0.0f;
    arg6->unk7C = 0.0f;
    arg6->unk84 = 0.0f;
    arg6->unk88 = 0.0f;
    arg6->unkB0 = 0.0f;
    arg6->unk40 = 1.0f;
    arg6->unk70 = 1.0f;
    arg6->unkA4 = 1.0f;
    arg6->unkB8 = 1.0f;
    arg6->unk3C = -1.0f;
    arg6->unk6C = -1.0f;
    return;
    // (possible return value: 0.0f)
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F075FAC
/* 0AAADC 7F075FAC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AAAE0 7F075FB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0AAAE4 7F075FB4 0FC1D7DA */  jal   sub_GAME_7F075F68
/* 0AAAE8 7F075FB8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0AAAEC 7F075FBC 8FA40018 */  lw    $a0, 0x18($sp)
/* 0AAAF0 7F075FC0 44800000 */  mtc1  $zero, $f0
/* 0AAAF4 7F075FC4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AAAF8 7F075FC8 44811000 */  mtc1  $at, $f2
/* 0AAAFC 7F075FCC 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0AAB00 7F075FD0 44816000 */  mtc1  $at, $f12
/* 0AAB04 7F075FD4 AC800020 */  sw    $zero, 0x20($a0)
/* 0AAB08 7F075FD8 AC800054 */  sw    $zero, 0x54($a0)
/* 0AAB0C 7F075FDC A0800026 */  sb    $zero, 0x26($a0)
/* 0AAB10 7F075FE0 AC800098 */  sw    $zero, 0x98($a0)
/* 0AAB14 7F075FE4 AC80009C */  sw    $zero, 0x9c($a0)
/* 0AAB18 7F075FE8 AC8000A0 */  sw    $zero, 0xa0($a0)
/* 0AAB1C 7F075FEC E480002C */  swc1  $f0, 0x2c($a0)
/* 0AAB20 7F075FF0 E480004C */  swc1  $f0, 0x4c($a0)
/* 0AAB24 7F075FF4 E480005C */  swc1  $f0, 0x5c($a0)
/* 0AAB28 7F075FF8 E480007C */  swc1  $f0, 0x7c($a0)
/* 0AAB2C 7F075FFC E4800084 */  swc1  $f0, 0x84($a0)
/* 0AAB30 7F076000 E4800088 */  swc1  $f0, 0x88($a0)
/* 0AAB34 7F076004 E48000B0 */  swc1  $f0, 0xb0($a0)
/* 0AAB38 7F076008 E4820040 */  swc1  $f2, 0x40($a0)
/* 0AAB3C 7F07600C E4820070 */  swc1  $f2, 0x70($a0)
/* 0AAB40 7F076010 E48200A4 */  swc1  $f2, 0xa4($a0)
/* 0AAB44 7F076014 E48200B8 */  swc1  $f2, 0xb8($a0)
/* 0AAB48 7F076018 E48C003C */  swc1  $f12, 0x3c($a0)
/* 0AAB4C 7F07601C E48C006C */  swc1  $f12, 0x6c($a0)
/* 0AAB50 7F076020 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0AAB54 7F076024 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AAB58 7F076028 03E00008 */  jr    $ra
/* 0AAB5C 7F07602C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F076030(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F076030
/* 0AAB60 7F076030 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AAB64 7F076034 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0AAB68 7F076038 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0AAB6C 7F07603C AFA40018 */  sw    $a0, 0x18($sp)
/* 0AAB70 7F076040 AFA70024 */  sw    $a3, 0x24($sp)
/* 0AAB74 7F076044 00C02825 */  move  $a1, $a2
/* 0AAB78 7F076048 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 0AAB7C 7F07604C AFA60020 */   sw    $a2, 0x20($sp)
/* 0AAB80 7F076050 8FA50024 */  lw    $a1, 0x24($sp)
/* 0AAB84 7F076054 8FA60020 */  lw    $a2, 0x20($sp)
/* 0AAB88 7F076058 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0AAB8C 7F07605C AC450000 */  sw    $a1, ($v0)
/* 0AAB90 7F076060 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0AAB94 7F076064 84F80014 */  lh    $t8, 0x14($a3)
/* 0AAB98 7F076068 8DCF0010 */  lw    $t7, 0x10($t6)
/* 0AAB9C 7F07606C 0018C880 */  sll   $t9, $t8, 2
/* 0AABA0 7F076070 01F94021 */  addu  $t0, $t7, $t9
/* 0AABA4 7F076074 AC480004 */  sw    $t0, 4($v0)
/* 0AABA8 7F076078 8CA30000 */  lw    $v1, ($a1)
/* 0AABAC 7F07607C ACC30014 */  sw    $v1, 0x14($a2)
/* 0AABB0 7F076080 10600006 */  beqz  $v1, .L7F07609C
/* 0AABB4 7F076084 00602025 */   move  $a0, $v1
/* 0AABB8 7F076088 AC660008 */  sw    $a2, 8($v1)
.L7F07608C:
/* 0AABBC 7F07608C 8C63000C */  lw    $v1, 0xc($v1)
/* 0AABC0 7F076090 5460FFFE */  bnezl $v1, .L7F07608C
/* 0AABC4 7F076094 AC660008 */   sw    $a2, 8($v1)
/* 0AABC8 7F076098 8CC40014 */  lw    $a0, 0x14($a2)
.L7F07609C:
/* 0AABCC 7F07609C 0FC1D6C7 */  jal   set_microcode_entry_numbers
/* 0AABD0 7F0760A0 00000000 */   nop   
/* 0AABD4 7F0760A4 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0AABD8 7F0760A8 84EA0014 */  lh    $t2, 0x14($a3)
/* 0AABDC 7F0760AC 01425821 */  addu  $t3, $t2, $v0
/* 0AABE0 7F0760B0 A4EB0014 */  sh    $t3, 0x14($a3)
/* 0AABE4 7F0760B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0AABE8 7F0760B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AABEC 7F0760BC 03E00008 */  jr    $ra
/* 0AABF0 7F0760C0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0760C4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80054F34*/
glabel jpt_80054F34
.word .L7F076128
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761A0
.word .L7F0761C0
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761B0
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F076188
.word .L7F0761CC
.word .L7F076158

.text
glabel sub_GAME_7F0760C4
/* 0AABF4 7F0760C4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0AABF8 7F0760C8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0AABFC 7F0760CC AFB30020 */  sw    $s3, 0x20($sp)
/* 0AAC00 7F0760D0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0AAC04 7F0760D4 AFB10018 */  sw    $s1, 0x18($sp)
/* 0AAC08 7F0760D8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0AAC0C 7F0760DC 8CB00000 */  lw    $s0, ($a1)
/* 0AAC10 7F0760E0 00A09025 */  move  $s2, $a1
/* 0AAC14 7F0760E4 00C09825 */  move  $s3, $a2
/* 0AAC18 7F0760E8 16000002 */  bnez  $s0, .L7F0760F4
/* 0AAC1C 7F0760EC 00008825 */   move  $s1, $zero
/* 0AAC20 7F0760F0 8C900000 */  lw    $s0, ($a0)
.L7F0760F4:
/* 0AAC24 7F0760F4 52000049 */  beql  $s0, $zero, .L7F07621C
/* 0AAC28 7F0760F8 AE710000 */   sw    $s1, ($s3)
/* 0AAC2C 7F0760FC 96020000 */  lhu   $v0, ($s0)
.L7F076100:
/* 0AAC30 7F076100 304E00FF */  andi  $t6, $v0, 0xff
/* 0AAC34 7F076104 25CFFFFC */  addiu $t7, $t6, -4
/* 0AAC38 7F076108 2DE10015 */  sltiu $at, $t7, 0x15
/* 0AAC3C 7F07610C 1020002F */  beqz  $at, .L7F0761CC
/* 0AAC40 7F076110 000F7880 */   sll   $t7, $t7, 2
/* 0AAC44 7F076114 3C018005 */  lui   $at, %hi(jpt_80054F34)
/* 0AAC48 7F076118 002F0821 */  addu  $at, $at, $t7
/* 0AAC4C 7F07611C 8C2F4F34 */  lw    $t7, %lo(jpt_80054F34)($at)
.L7F076120:
/* 0AAC50 7F076120 01E00008 */  jr    $t7
/* 0AAC54 7F076124 00000000 */   nop   
.L7F076128:
/* 0AAC58 7F076128 8E580000 */  lw    $t8, ($s2)
/* 0AAC5C 7F07612C 8E020004 */  lw    $v0, 4($s0)
/* 0AAC60 7F076130 52180004 */  beql  $s0, $t8, .L7F076144
/* 0AAC64 7F076134 8C430004 */   lw    $v1, 4($v0)
/* 0AAC68 7F076138 10000024 */  b     .L7F0761CC
/* 0AAC6C 7F07613C 8C510000 */   lw    $s1, ($v0)
/* 0AAC70 7F076140 8C430004 */  lw    $v1, 4($v0)
.L7F076144:
/* 0AAC74 7F076144 8E790000 */  lw    $t9, ($s3)
/* 0AAC78 7F076148 10790020 */  beq   $v1, $t9, .L7F0761CC
/* 0AAC7C 7F07614C 00000000 */   nop   
/* 0AAC80 7F076150 1000001E */  b     .L7F0761CC
/* 0AAC84 7F076154 00608825 */   move  $s1, $v1
.L7F076158:
/* 0AAC88 7F076158 8E480000 */  lw    $t0, ($s2)
/* 0AAC8C 7F07615C 8E020004 */  lw    $v0, 4($s0)
/* 0AAC90 7F076160 52080004 */  beql  $s0, $t0, .L7F076174
/* 0AAC94 7F076164 8C430004 */   lw    $v1, 4($v0)
/* 0AAC98 7F076168 10000018 */  b     .L7F0761CC
/* 0AAC9C 7F07616C 8C510000 */   lw    $s1, ($v0)
/* 0AACA0 7F076170 8C430004 */  lw    $v1, 4($v0)
.L7F076174:
/* 0AACA4 7F076174 8E690000 */  lw    $t1, ($s3)
/* 0AACA8 7F076178 10690014 */  beq   $v1, $t1, .L7F0761CC
/* 0AACAC 7F07617C 00000000 */   nop   
/* 0AACB0 7F076180 10000012 */  b     .L7F0761CC
/* 0AACB4 7F076184 00608825 */   move  $s1, $v1
.L7F076188:
/* 0AACB8 7F076188 8E4A0000 */  lw    $t2, ($s2)
/* 0AACBC 7F07618C 8E020004 */  lw    $v0, 4($s0)
/* 0AACC0 7F076190 120A000E */  beq   $s0, $t2, .L7F0761CC
/* 0AACC4 7F076194 00000000 */   nop   
/* 0AACC8 7F076198 1000000C */  b     .L7F0761CC
/* 0AACCC 7F07619C 8C510008 */   lw    $s1, 8($v0)
.L7F0761A0:
/* 0AACD0 7F0761A0 8E020004 */  lw    $v0, 4($s0)
/* 0AACD4 7F0761A4 8C4B0008 */  lw    $t3, 8($v0)
/* 0AACD8 7F0761A8 10000008 */  b     .L7F0761CC
/* 0AACDC 7F0761AC AE0B0014 */   sw    $t3, 0x14($s0)
.L7F0761B0:
/* 0AACE0 7F0761B0 8E020004 */  lw    $v0, 4($s0)
/* 0AACE4 7F0761B4 8C4C0000 */  lw    $t4, ($v0)
/* 0AACE8 7F0761B8 10000004 */  b     .L7F0761CC
/* 0AACEC 7F0761BC AE0C0014 */   sw    $t4, 0x14($s0)
.L7F0761C0:
/* 0AACF0 7F0761C0 02002025 */  move  $a0, $s0
/* 0AACF4 7F0761C4 0FC1BA95 */  jal   sub_GAME_7F06EA54
/* 0AACF8 7F0761C8 24050001 */   li    $a1, 1
def_7F076120:
.L7F0761CC:
/* 0AACFC 7F0761CC 56200013 */  bnezl $s1, .L7F07621C
/* 0AAD00 7F0761D0 AE710000 */   sw    $s1, ($s3)
/* 0AAD04 7F0761D4 8E020014 */  lw    $v0, 0x14($s0)
/* 0AAD08 7F0761D8 10400003 */  beqz  $v0, .L7F0761E8
/* 0AAD0C 7F0761DC 00000000 */   nop   
/* 0AAD10 7F0761E0 1000000B */  b     .L7F076210
/* 0AAD14 7F0761E4 00408025 */   move  $s0, $v0
.L7F0761E8:
/* 0AAD18 7F0761E8 12000009 */  beqz  $s0, .L7F076210
/* 0AAD1C 7F0761EC 00000000 */   nop   
/* 0AAD20 7F0761F0 8E02000C */  lw    $v0, 0xc($s0)
.L7F0761F4:
/* 0AAD24 7F0761F4 50400004 */  beql  $v0, $zero, .L7F076208
/* 0AAD28 7F0761F8 8E100008 */   lw    $s0, 8($s0)
/* 0AAD2C 7F0761FC 10000004 */  b     .L7F076210
/* 0AAD30 7F076200 00408025 */   move  $s0, $v0
/* 0AAD34 7F076204 8E100008 */  lw    $s0, 8($s0)
.L7F076208:
/* 0AAD38 7F076208 5600FFFA */  bnezl $s0, .L7F0761F4
/* 0AAD3C 7F07620C 8E02000C */   lw    $v0, 0xc($s0)
.L7F076210:
/* 0AAD40 7F076210 5600FFBB */  bnezl $s0, .L7F076100
/* 0AAD44 7F076214 96020000 */   lhu   $v0, ($s0)
/* 0AAD48 7F076218 AE710000 */  sw    $s1, ($s3)
.L7F07621C:
/* 0AAD4C 7F07621C AE500000 */  sw    $s0, ($s2)
/* 0AAD50 7F076220 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0AAD54 7F076224 8FB30020 */  lw    $s3, 0x20($sp)
/* 0AAD58 7F076228 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0AAD5C 7F07622C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0AAD60 7F076230 8FB00014 */  lw    $s0, 0x14($sp)
/* 0AAD64 7F076234 03E00008 */  jr    $ra
/* 0AAD68 7F076238 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F07623C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F07623C
/* 0AAD6C 7F07623C AFA40000 */  sw    $a0, ($sp)
/* 0AAD70 7F076240 94A20000 */  lhu   $v0, ($a1)
/* 0AAD74 7F076244 24010004 */  li    $at, 4
/* 0AAD78 7F076248 304E00FF */  andi  $t6, $v0, 0xff
/* 0AAD7C 7F07624C 11C10007 */  beq   $t6, $at, .L7F07626C
/* 0AAD80 7F076250 24010016 */   li    $at, 22
/* 0AAD84 7F076254 11C1001B */  beq   $t6, $at, .L7F0762C4
/* 0AAD88 7F076258 24010018 */   li    $at, 24
/* 0AAD8C 7F07625C 51C1000F */  beql  $t6, $at, .L7F07629C
/* 0AAD90 7F076260 8CA20004 */   lw    $v0, 4($a1)
/* 0AAD94 7F076264 03E00008 */  jr    $ra
/* 0AAD98 7F076268 00000000 */   nop   

.L7F07626C:
/* 0AAD9C 7F07626C 8CA20004 */  lw    $v0, 4($a1)
/* 0AADA0 7F076270 8C4F0000 */  lw    $t7, ($v0)
/* 0AADA4 7F076274 54CF0004 */  bnel  $a2, $t7, .L7F076288
/* 0AADA8 7F076278 8C580004 */   lw    $t8, 4($v0)
/* 0AADAC 7F07627C 03E00008 */  jr    $ra
/* 0AADB0 7F076280 AC470000 */   sw    $a3, ($v0)

/* 0AADB4 7F076284 8C580004 */  lw    $t8, 4($v0)
.L7F076288:
/* 0AADB8 7F076288 14D80013 */  bne   $a2, $t8, .L7F0762D8
/* 0AADBC 7F07628C 00000000 */   nop   
/* 0AADC0 7F076290 03E00008 */  jr    $ra
/* 0AADC4 7F076294 AC470004 */   sw    $a3, 4($v0)

/* 0AADC8 7F076298 8CA20004 */  lw    $v0, 4($a1)
.L7F07629C:
/* 0AADCC 7F07629C 8C590000 */  lw    $t9, ($v0)
/* 0AADD0 7F0762A0 54D90004 */  bnel  $a2, $t9, .L7F0762B4
/* 0AADD4 7F0762A4 8C480004 */   lw    $t0, 4($v0)
/* 0AADD8 7F0762A8 03E00008 */  jr    $ra
/* 0AADDC 7F0762AC AC470000 */   sw    $a3, ($v0)

/* 0AADE0 7F0762B0 8C480004 */  lw    $t0, 4($v0)
.L7F0762B4:
/* 0AADE4 7F0762B4 14C80008 */  bne   $a2, $t0, .L7F0762D8
/* 0AADE8 7F0762B8 00000000 */   nop   
/* 0AADEC 7F0762BC 03E00008 */  jr    $ra
/* 0AADF0 7F0762C0 AC470004 */   sw    $a3, 4($v0)

.L7F0762C4:
/* 0AADF4 7F0762C4 8CA20004 */  lw    $v0, 4($a1)
/* 0AADF8 7F0762C8 8C490008 */  lw    $t1, 8($v0)
/* 0AADFC 7F0762CC 14C90002 */  bne   $a2, $t1, .L7F0762D8
/* 0AAE00 7F0762D0 00000000 */   nop   
/* 0AAE04 7F0762D4 AC470008 */  sw    $a3, 8($v0)
.L7F0762D8:
/* 0AAE08 7F0762D8 03E00008 */  jr    $ra
/* 0AAE0C 7F0762DC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0762E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0762E0
/* 0AAE10 7F0762E0 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0AAE14 7F0762E4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0AAE18 7F0762E8 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0AAE1C 7F0762EC AFB70034 */  sw    $s7, 0x34($sp)
/* 0AAE20 7F0762F0 AFB60030 */  sw    $s6, 0x30($sp)
/* 0AAE24 7F0762F4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0AAE28 7F0762F8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0AAE2C 7F0762FC AFB30024 */  sw    $s3, 0x24($sp)
/* 0AAE30 7F076300 AFB20020 */  sw    $s2, 0x20($sp)
/* 0AAE34 7F076304 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0AAE38 7F076308 AFB00018 */  sw    $s0, 0x18($sp)
/* 0AAE3C 7F07630C AFA60080 */  sw    $a2, 0x80($sp)
/* 0AAE40 7F076310 AFA70084 */  sw    $a3, 0x84($sp)
/* 0AAE44 7F076314 8C8E0008 */  lw    $t6, 8($a0)
/* 0AAE48 7F076318 0080A825 */  move  $s5, $a0
/* 0AAE4C 7F07631C 00A02025 */  move  $a0, $a1
/* 0AAE50 7F076320 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0AAE54 7F076324 AFAE0054 */   sw    $t6, 0x54($sp)
/* 0AAE58 7F076328 AFA20050 */  sw    $v0, 0x50($sp)
/* 0AAE5C 7F07632C 0FC2F447 */  jal   get_rom_remaining_buffer_for_index
/* 0AAE60 7F076330 00402025 */   move  $a0, $v0
/* 0AAE64 7F076334 00408025 */  move  $s0, $v0
/* 0AAE68 7F076338 0FC2F440 */  jal   get_pc_remaining_buffer_for_index
/* 0AAE6C 7F07633C 8FA40050 */   lw    $a0, 0x50($sp)
/* 0AAE70 7F076340 0040F025 */  move  $fp, $v0
/* 0AAE74 7F076344 AFA00074 */  sw    $zero, 0x74($sp)
/* 0AAE78 7F076348 02A02025 */  move  $a0, $s5
/* 0AAE7C 7F07634C 27A50074 */  addiu $a1, $sp, 0x74
/* 0AAE80 7F076350 0FC1D831 */  jal   sub_GAME_7F0760C4
/* 0AAE84 7F076354 27A6006C */   addiu $a2, $sp, 0x6c
/* 0AAE88 7F076358 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0AAE8C 7F07635C 3C1600FF */  lui   $s6, (0x00FFFFFF >> 16) # lui $s6, 0xff
/* 0AAE90 7F076360 36D6FFFF */  ori   $s6, (0x00FFFFFF & 0xFFFF) # ori $s6, $s6, 0xffff
/* 0AAE94 7F076364 12E00043 */  beqz  $s7, .L7F076474
/* 0AAE98 7F076368 8FA70054 */   lw    $a3, 0x54($sp)
/* 0AAE9C 7F07636C 8EAF0008 */  lw    $t7, 8($s5)
/* 0AAEA0 7F076370 02F6C824 */  and   $t9, $s7, $s6
/* 0AAEA4 7F076374 02074821 */  addu  $t1, $s0, $a3
/* 0AAEA8 7F076378 01F92021 */  addu  $a0, $t7, $t9
/* 0AAEAC 7F07637C 03C44023 */  subu  $t0, $fp, $a0
/* 0AAEB0 7F076380 01073021 */  addu  $a2, $t0, $a3
/* 0AAEB4 7F076384 01262823 */  subu  $a1, $t1, $a2
/* 0AAEB8 7F076388 00A45023 */  subu  $t2, $a1, $a0
/* 0AAEBC 7F07638C 02E09825 */  move  $s3, $s7
/* 0AAEC0 7F076390 0FC339E5 */  jal   sub_GAME_7F0CE794
/* 0AAEC4 7F076394 AFAA0058 */   sw    $t2, 0x58($sp)
/* 0AAEC8 7F076398 02A02025 */  move  $a0, $s5
/* 0AAECC 7F07639C 0FC32F94 */  jal   sub_GAME_7F0CBE50
/* 0AAED0 7F0763A0 8FA50084 */   lw    $a1, 0x84($sp)
/* 0AAED4 7F0763A4 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0AAED8 7F0763A8 51600025 */  beql  $t3, $zero, .L7F076440
/* 0AAEDC 7F0763AC 8EAA0008 */   lw    $t2, 8($s5)
/* 0AAEE0 7F0763B0 8FB0006C */  lw    $s0, 0x6c($sp)
.L7F0763B4:
/* 0AAEE4 7F0763B4 8FB40074 */  lw    $s4, 0x74($sp)
/* 0AAEE8 7F0763B8 02A02025 */  move  $a0, $s5
/* 0AAEEC 7F0763BC 27A50074 */  addiu $a1, $sp, 0x74
/* 0AAEF0 7F0763C0 0FC1D831 */  jal   sub_GAME_7F0760C4
/* 0AAEF4 7F0763C4 27A6006C */   addiu $a2, $sp, 0x6c
/* 0AAEF8 7F0763C8 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0AAEFC 7F0763CC 02A02025 */  move  $a0, $s5
/* 0AAF00 7F0763D0 02802825 */  move  $a1, $s4
/* 0AAF04 7F0763D4 12E00004 */  beqz  $s7, .L7F0763E8
/* 0AAF08 7F0763D8 02003025 */   move  $a2, $s0
/* 0AAF0C 7F0763DC 02F09023 */  subu  $s2, $s7, $s0
/* 0AAF10 7F0763E0 10000007 */  b     .L7F076400
/* 0AAF14 7F0763E4 02168824 */   and   $s1, $s0, $s6
.L7F0763E8:
/* 0AAF18 7F0763E8 8FAC0054 */  lw    $t4, 0x54($sp)
/* 0AAF1C 7F0763EC 8EAE0008 */  lw    $t6, 8($s5)
/* 0AAF20 7F0763F0 02168824 */  and   $s1, $s0, $s6
/* 0AAF24 7F0763F4 019E6821 */  addu  $t5, $t4, $fp
/* 0AAF28 7F0763F8 01AEC023 */  subu  $t8, $t5, $t6
/* 0AAF2C 7F0763FC 03119023 */  subu  $s2, $t8, $s1
.L7F076400:
/* 0AAF30 7F076400 0FC1D88F */  jal   sub_GAME_7F07623C
/* 0AAF34 7F076404 02603825 */   move  $a3, $s3
/* 0AAF38 7F076408 8EA20008 */  lw    $v0, 8($s5)
/* 0AAF3C 7F07640C 8FB90058 */  lw    $t9, 0x58($sp)
/* 0AAF40 7F076410 02764024 */  and   $t0, $s3, $s6
/* 0AAF44 7F076414 00517821 */  addu  $t7, $v0, $s1
/* 0AAF48 7F076418 02402825 */  move  $a1, $s2
/* 0AAF4C 7F07641C 8FA70084 */  lw    $a3, 0x84($sp)
/* 0AAF50 7F076420 00483021 */  addu  $a2, $v0, $t0
/* 0AAF54 7F076424 0FC33846 */  jal   process_microcode_sort_display_modes_expand_image_calls
/* 0AAF58 7F076428 01F92021 */   addu  $a0, $t7, $t9
/* 0AAF5C 7F07642C 8FA90074 */  lw    $t1, 0x74($sp)
/* 0AAF60 7F076430 02629821 */  addu  $s3, $s3, $v0
/* 0AAF64 7F076434 5520FFDF */  bnezl $t1, .L7F0763B4
/* 0AAF68 7F076438 8FB0006C */   lw    $s0, 0x6c($sp)
/* 0AAF6C 7F07643C 8EAA0008 */  lw    $t2, 8($s5)
.L7F076440:
/* 0AAF70 7F076440 8FA50054 */  lw    $a1, 0x54($sp)
/* 0AAF74 7F076444 02765824 */  and   $t3, $s3, $s6
/* 0AAF78 7F076448 8FA70080 */  lw    $a3, 0x80($sp)
/* 0AAF7C 7F07644C 014B6021 */  addu  $t4, $t2, $t3
/* 0AAF80 7F076450 01859023 */  subu  $s2, $t4, $a1
/* 0AAF84 7F076454 2646000F */  addiu $a2, $s2, 0xf
/* 0AAF88 7F076458 2401FFF0 */  li    $at, -16
/* 0AAF8C 7F07645C 00C16824 */  and   $t5, $a2, $at
/* 0AAF90 7F076460 2CEE0001 */  sltiu $t6, $a3, 1
/* 0AAF94 7F076464 01C03825 */  move  $a3, $t6
/* 0AAF98 7F076468 01A03025 */  move  $a2, $t5
/* 0AAF9C 7F07646C 0FC2F44E */  jal   sub_GAME_7F0BD138
/* 0AAFA0 7F076470 8FA40050 */   lw    $a0, 0x50($sp)
.L7F076474:
/* 0AAFA4 7F076474 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0AAFA8 7F076478 8FB00018 */  lw    $s0, 0x18($sp)
/* 0AAFAC 7F07647C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0AAFB0 7F076480 8FB20020 */  lw    $s2, 0x20($sp)
/* 0AAFB4 7F076484 8FB30024 */  lw    $s3, 0x24($sp)
/* 0AAFB8 7F076488 8FB40028 */  lw    $s4, 0x28($sp)
/* 0AAFBC 7F07648C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0AAFC0 7F076490 8FB60030 */  lw    $s6, 0x30($sp)
/* 0AAFC4 7F076494 8FB70034 */  lw    $s7, 0x34($sp)
/* 0AAFC8 7F076498 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0AAFCC 7F07649C 03E00008 */  jr    $ra
/* 0AAFD0 7F0764A0 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif





#ifdef NONMATCHING
void load_object_fill_header(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_object_fill_header
/* 0AAFD4 7F0764A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AAFD8 7F0764A8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0AAFDC 7F0764AC 00808025 */  move  $s0, $a0
/* 0AAFE0 7F0764B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AAFE4 7F0764B4 AFA50024 */  sw    $a1, 0x24($sp)
/* 0AAFE8 7F0764B8 10C00006 */  beqz  $a2, .L7F0764D4
/* 0AAFEC 7F0764BC AFA60028 */   sw    $a2, 0x28($sp)
/* 0AAFF0 7F0764C0 00A02025 */  move  $a0, $a1
/* 0AAFF4 7F0764C4 0FC2F350 */  jal   _load_resource_named_to_buffer
/* 0AAFF8 7F0764C8 00002825 */   move  $a1, $zero
/* 0AAFFC 7F0764CC 10000007 */  b     .L7F0764EC
/* 0AB000 7F0764D0 00403025 */   move  $a2, $v0
.L7F0764D4:
/* 0AB004 7F0764D4 8FA40024 */  lw    $a0, 0x24($sp)
/* 0AB008 7F0764D8 00002825 */  move  $a1, $zero
/* 0AB00C 7F0764DC 24060100 */  li    $a2, 256
/* 0AB010 7F0764E0 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0AB014 7F0764E4 24070004 */   li    $a3, 4
/* 0AB018 7F0764E8 00403025 */  move  $a2, $v0
.L7F0764EC:
/* 0AB01C 7F0764EC 86190016 */  lh    $t9, 0x16($s0)
/* 0AB020 7F0764F0 860F000C */  lh    $t7, 0xc($s0)
/* 0AB024 7F0764F4 AE060008 */  sw    $a2, 8($s0)
/* 0AB028 7F0764F8 00194080 */  sll   $t0, $t9, 2
/* 0AB02C 7F0764FC 01194023 */  subu  $t0, $t0, $t9
/* 0AB030 7F076500 000FC080 */  sll   $t8, $t7, 2
/* 0AB034 7F076504 00D81021 */  addu  $v0, $a2, $t8
/* 0AB038 7F076508 00084080 */  sll   $t0, $t0, 2
/* 0AB03C 7F07650C 00484821 */  addu  $t1, $v0, $t0
/* 0AB040 7F076510 AE020018 */  sw    $v0, 0x18($s0)
/* 0AB044 7F076514 AE090000 */  sw    $t1, ($s0)
/* 0AB048 7F076518 02002025 */  move  $a0, $s0
/* 0AB04C 7F07651C 0FC1D6A4 */  jal   sub_GAME_7F075A90
/* 0AB050 7F076520 3C050500 */   lui   $a1, 0x500
/* 0AB054 7F076524 02002025 */  move  $a0, $s0
/* 0AB058 7F076528 8FA50024 */  lw    $a1, 0x24($sp)
/* 0AB05C 7F07652C 8FA60028 */  lw    $a2, 0x28($sp)
/* 0AB060 7F076530 0FC1D8B8 */  jal   sub_GAME_7F0762E0
/* 0AB064 7F076534 8FA70030 */   lw    $a3, 0x30($sp)
/* 0AB068 7F076538 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AB06C 7F07653C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0AB070 7F076540 27BD0020 */  addiu $sp, $sp, 0x20
/* 0AB074 7F076544 03E00008 */  jr    $ra
/* 0AB078 7F076548 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_object_into_memory(void) {
    // Node 0
    load_object_fill_header(0, 0, 0);
    return;
    // (possible return value: load_object_fill_header(0, 0, 0))
}

#else
GLOBAL_ASM(
.text
glabel load_object_into_memory
/* 0AB07C 7F07654C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AB080 7F076550 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AB084 7F076554 AFA00010 */  sw    $zero, 0x10($sp)
/* 0AB088 7F076558 00003025 */  move  $a2, $zero
/* 0AB08C 7F07655C 0FC1D929 */  jal   load_object_fill_header
/* 0AB090 7F076560 00003825 */   move  $a3, $zero
/* 0AB094 7F076564 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AB098 7F076568 27BD0020 */  addiu $sp, $sp, 0x20
/* 0AB09C 7F07656C 03E00008 */  jr    $ra
/* 0AB0A0 7F076570 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_object_into_memory_unused_maybe(void) {
    // Node 0
    load_object_fill_header(0);
    return;
    // (possible return value: load_object_fill_header(0))
}

#else
GLOBAL_ASM(
.text
glabel load_object_into_memory_unused_maybe
/* 0AB0A4 7F076574 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AB0A8 7F076578 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AB0AC 7F07657C 0FC1D929 */  jal   load_object_fill_header
/* 0AB0B0 7F076580 AFA00010 */   sw    $zero, 0x10($sp)
/* 0AB0B4 7F076584 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AB0B8 7F076588 27BD0020 */  addiu $sp, $sp, 0x20
/* 0AB0BC 7F07658C 03E00008 */  jr    $ra
/* 0AB0C0 7F076590 00000000 */   nop   
)
#endif




