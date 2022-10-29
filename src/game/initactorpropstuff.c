#include <ultra64.h>
#include "initactorpropstuff.h"
#include "chr.h"
#include "gun.h"
#include "math_floor.h"

/** 
 * Gets the number of currently allocated heads and bodies
 * Note: Compile-time static? why bother with a function?
 */
void reset_counter_rand_body_head(void)
{
    num_bodies = 0;
    while (list_of_bodies[num_bodies] >= 0)
    {
        num_bodies++;
    }
#ifdef ISGOLDFINGER
    return; //return early as we have a new function for heads
#endif
    num_male_heads = 0;
    while (random_male_heads[num_male_heads] >= 0)
    {
        num_male_heads++;
    }

    num_female_heads = 0;
    while (random_female_heads[num_female_heads] >= 0)
    {
        num_female_heads++;
    }
}


#ifdef NONMATCHING
//close, ops swapped
//34d80:    addu    s1,s1,v0                        | 34d80:    addiu   s0,s0,1
//34d84:    addiu   s0,s0,1                         | 34d84:    addu    s1,s1,v0
u32 sub_GAME_7F0001F0(void *ani,int aniid,int param_3)
{
  short asStack8 [4];
  u32 uVar1;
  u32 i;
  
  
  i = 0;
  while (aniid < param_3) {
      uVar1 = sub_GAME_7F06D2E4(0,0,&skeleton_guard,ani,aniid,asStack8);
      aniid=1+aniid;
      i = i + uVar1 & 0xffff;
  }
  return i;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0001F0
/* 034D20 7F0001F0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 034D24 7F0001F4 AFB30028 */  sw    $s3, 0x28($sp)
/* 034D28 7F0001F8 AFB20024 */  sw    $s2, 0x24($sp)
/* 034D2C 7F0001FC AFB10020 */  sw    $s1, 0x20($sp)
/* 034D30 7F000200 AFB0001C */  sw    $s0, 0x1c($sp)
/* 034D34 7F000204 00A6082A */  slt   $at, $a1, $a2
/* 034D38 7F000208 00A08025 */  move  $s0, $a1
/* 034D3C 7F00020C 00C09025 */  move  $s2, $a2
/* 034D40 7F000210 00809825 */  move  $s3, $a0
/* 034D44 7F000214 AFBF0034 */  sw    $ra, 0x34($sp)
/* 034D48 7F000218 AFB50030 */  sw    $s5, 0x30($sp)
/* 034D4C 7F00021C AFB4002C */  sw    $s4, 0x2c($sp)
/* 034D50 7F000220 10200011 */  beqz  $at, .L7F000268
/* 034D54 7F000224 00008825 */   move  $s1, $zero
/* 034D58 7F000228 3C148004 */  lui   $s4, %hi(skeleton_guard)
/* 034D5C 7F00022C 2694D400 */  addiu $s4, %lo(skeleton_guard) # addiu $s4, $s4, -0x2c00
/* 034D60 7F000230 27B50040 */  addiu $s5, $sp, 0x40
.L7F000234:
/* 034D64 7F000234 00002025 */  move  $a0, $zero
/* 034D68 7F000238 00002825 */  move  $a1, $zero
/* 034D6C 7F00023C 02803025 */  move  $a2, $s4
/* 034D70 7F000240 02603825 */  move  $a3, $s3
/* 034D74 7F000244 AFB00010 */  sw    $s0, 0x10($sp)
/* 034D78 7F000248 0FC1B4B9 */  jal   sub_GAME_7F06D2E4
/* 034D7C 7F00024C AFB50014 */   sw    $s5, 0x14($sp)
/* 034D80 7F000250 02228821 */  addu  $s1, $s1, $v0
/* 034D84 7F000254 26100001 */  addiu $s0, $s0, 1
/* 034D88 7F000258 322EFFFF */  andi  $t6, $s1, 0xffff
/* 034D8C 7F00025C 0212082A */  slt   $at, $s0, $s2
/* 034D90 7F000260 1420FFF4 */  bnez  $at, .L7F000234
/* 034D94 7F000264 01C08825 */   move  $s1, $t6
.L7F000268:
/* 034D98 7F000268 8FBF0034 */  lw    $ra, 0x34($sp)
/* 034D9C 7F00026C 02201025 */  move  $v0, $s1
/* 034DA0 7F000270 8FB10020 */  lw    $s1, 0x20($sp)
/* 034DA4 7F000274 8FB0001C */  lw    $s0, 0x1c($sp)
/* 034DA8 7F000278 8FB20024 */  lw    $s2, 0x24($sp)
/* 034DAC 7F00027C 8FB30028 */  lw    $s3, 0x28($sp)
/* 034DB0 7F000280 8FB4002C */  lw    $s4, 0x2c($sp)
/* 034DB4 7F000284 8FB50030 */  lw    $s5, 0x30($sp)
/* 034DB8 7F000288 03E00008 */  jr    $ra
/* 034DBC 7F00028C 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F000290(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F000290
/* 034DC0 7F000290 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 034DC4 7F000294 AFB30028 */  sw    $s3, 0x28($sp)
/* 034DC8 7F000298 AFB20024 */  sw    $s2, 0x24($sp)
/* 034DCC 7F00029C AFB10020 */  sw    $s1, 0x20($sp)
/* 034DD0 7F0002A0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 034DD4 7F0002A4 00A6082A */  slt   $at, $a1, $a2
/* 034DD8 7F0002A8 00A08025 */  move  $s0, $a1
/* 034DDC 7F0002AC 00C09025 */  move  $s2, $a2
/* 034DE0 7F0002B0 00809825 */  move  $s3, $a0
/* 034DE4 7F0002B4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 034DE8 7F0002B8 AFB50030 */  sw    $s5, 0x30($sp)
/* 034DEC 7F0002BC AFB4002C */  sw    $s4, 0x2c($sp)
/* 034DF0 7F0002C0 10200010 */  beqz  $at, .L7F000304
/* 034DF4 7F0002C4 00008825 */   move  $s1, $zero
/* 034DF8 7F0002C8 3C148004 */  lui   $s4, %hi(skeleton_guard)
/* 034DFC 7F0002CC 2694D400 */  addiu $s4, %lo(skeleton_guard) # addiu $s4, $s4, -0x2c00
/* 034E00 7F0002D0 27B5003C */  addiu $s5, $sp, 0x3c
.L7F0002D4:
/* 034E04 7F0002D4 00002025 */  move  $a0, $zero
/* 034E08 7F0002D8 00002825 */  move  $a1, $zero
/* 034E0C 7F0002DC 02803025 */  move  $a2, $s4
/* 034E10 7F0002E0 02603825 */  move  $a3, $s3
/* 034E14 7F0002E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 034E18 7F0002E8 0FC1B4B9 */  jal   sub_GAME_7F06D2E4
/* 034E1C 7F0002EC AFB50014 */   sw    $s5, 0x14($sp)
/* 034E20 7F0002F0 87AE0040 */  lh    $t6, 0x40($sp)
/* 034E24 7F0002F4 26100001 */  addiu $s0, $s0, 1
/* 034E28 7F0002F8 0212082A */  slt   $at, $s0, $s2
/* 034E2C 7F0002FC 1420FFF5 */  bnez  $at, .L7F0002D4
/* 034E30 7F000300 022E8821 */   addu  $s1, $s1, $t6
.L7F000304:
/* 034E34 7F000304 8FBF0034 */  lw    $ra, 0x34($sp)
/* 034E38 7F000308 02201025 */  move  $v0, $s1
/* 034E3C 7F00030C 8FB10020 */  lw    $s1, 0x20($sp)
/* 034E40 7F000310 8FB0001C */  lw    $s0, 0x1c($sp)
/* 034E44 7F000314 8FB20024 */  lw    $s2, 0x24($sp)
/* 034E48 7F000318 8FB30028 */  lw    $s3, 0x28($sp)
/* 034E4C 7F00031C 8FB4002C */  lw    $s4, 0x2c($sp)
/* 034E50 7F000320 8FB50030 */  lw    $s5, 0x30($sp)
/* 034E54 7F000324 03E00008 */  jr    $ra
/* 034E58 7F000328 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif



#ifdef NONMATCHING
//pd is raceInitAnimGroup
void sub_GAME_7F00032C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel F32_8004ED70
.word 0x40c90fdb
glabel F32_8004ED74
.word 0x38c90fdb
.text
glabel sub_GAME_7F00032C
/* 034E5C 7F00032C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 034E60 7F000330 AFBF003C */  sw    $ra, 0x3c($sp)
/* 034E64 7F000334 AFB30038 */  sw    $s3, 0x38($sp)
/* 034E68 7F000338 AFB20034 */  sw    $s2, 0x34($sp)
/* 034E6C 7F00033C AFB10030 */  sw    $s1, 0x30($sp)
/* 034E70 7F000340 AFB0002C */  sw    $s0, 0x2c($sp)
/* 034E74 7F000344 F7B80020 */  sdc1  $f24, 0x20($sp)
/* 034E78 7F000348 F7B60018 */  sdc1  $f22, 0x18($sp)
/* 034E7C 7F00034C F7B40010 */  sdc1  $f20, 0x10($sp)
/* 034E80 7F000350 8C8E0000 */  lw    $t6, ($a0)
/* 034E84 7F000354 00008825 */  move  $s1, $zero
/* 034E88 7F000358 00808025 */  move  $s0, $a0
/* 034E8C 7F00035C 11C00038 */  beqz  $t6, .L7F000440
/* 034E90 7F000360 01C01025 */   move  $v0, $t6
/* 034E94 7F000364 3C018005 */  lui   $at, %hi(F32_8004ED70)
/* 034E98 7F000368 C438ED70 */  lwc1  $f24, %lo(F32_8004ED70)($at)
/* 034E9C 7F00036C 3C018005 */  lui   $at, %hi(F32_8004ED74)
/* 034EA0 7F000370 3C128007 */  lui   $s2, %hi(ptr_animation_table)
/* 034EA4 7F000374 4480A000 */  mtc1  $zero, $f20
/* 034EA8 7F000378 26529538 */  addiu $s2, %lo(ptr_animation_table) # addiu $s2, $s2, -0x6ac8
/* 034EAC 7F00037C C436ED74 */  lwc1  $f22, %lo(F32_8004ED74)($at)
/* 034EB0 7F000380 34138000 */  li    $s3, 32768
/* 034EB4 7F000384 8E4F0000 */  lw    $t7, ($s2)
.L7F000388:
/* 034EB8 7F000388 C60C0004 */  lwc1  $f12, 4($s0)
/* 034EBC 7F00038C 004FC021 */  addu  $t8, $v0, $t7
/* 034EC0 7F000390 0FC170F6 */  jal   floorFloatToInt
/* 034EC4 7F000394 AE180000 */   sw    $t8, ($s0)
/* 034EC8 7F000398 8E040000 */  lw    $a0, ($s0)
/* 034ECC 7F00039C 00002825 */  move  $a1, $zero
/* 034ED0 7F0003A0 0FC0007C */  jal   sub_GAME_7F0001F0
/* 034ED4 7F0003A4 00403025 */   move  $a2, $v0
/* 034ED8 7F0003A8 C6000004 */  lwc1  $f0, 4($s0)
/* 034EDC 7F0003AC 3043FFFF */  andi  $v1, $v0, 0xffff
/* 034EE0 7F0003B0 0073082A */  slt   $at, $v1, $s3
/* 034EE4 7F0003B4 4600A03C */  c.lt.s $f20, $f0
/* 034EE8 7F0003B8 00000000 */  nop   
/* 034EEC 7F0003BC 4502001B */  bc1fl .L7F00042C
/* 034EF0 7F0003C0 E6140008 */   swc1  $f20, 8($s0)
/* 034EF4 7F0003C4 5020000D */  beql  $at, $zero, .L7F0003FC
/* 034EF8 7F0003C8 44839000 */   mtc1  $v1, $f18
/* 034EFC 7F0003CC 44832000 */  mtc1  $v1, $f4
/* 034F00 7F0003D0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 034F04 7F0003D4 04610004 */  bgez  $v1, .L7F0003E8
/* 034F08 7F0003D8 468021A0 */   cvt.s.w $f6, $f4
/* 034F0C 7F0003DC 44814000 */  mtc1  $at, $f8
/* 034F10 7F0003E0 00000000 */  nop   
/* 034F14 7F0003E4 46083180 */  add.s $f6, $f6, $f8
.L7F0003E8:
/* 034F18 7F0003E8 46163282 */  mul.s $f10, $f6, $f22
/* 034F1C 7F0003EC 46005403 */  div.s $f16, $f10, $f0
/* 034F20 7F0003F0 1000000E */  b     .L7F00042C
/* 034F24 7F0003F4 E6100008 */   swc1  $f16, 8($s0)
/* 034F28 7F0003F8 44839000 */  mtc1  $v1, $f18
.L7F0003FC:
/* 034F2C 7F0003FC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 034F30 7F000400 04610004 */  bgez  $v1, .L7F000414
/* 034F34 7F000404 46809120 */   cvt.s.w $f4, $f18
/* 034F38 7F000408 44814000 */  mtc1  $at, $f8
/* 034F3C 7F00040C 00000000 */  nop   
/* 034F40 7F000410 46082100 */  add.s $f4, $f4, $f8
.L7F000414:
/* 034F44 7F000414 46162182 */  mul.s $f6, $f4, $f22
/* 034F48 7F000418 46183281 */  sub.s $f10, $f6, $f24
/* 034F4C 7F00041C 46005403 */  div.s $f16, $f10, $f0
/* 034F50 7F000420 10000002 */  b     .L7F00042C
/* 034F54 7F000424 E6100008 */   swc1  $f16, 8($s0)
/* 034F58 7F000428 E6140008 */  swc1  $f20, 8($s0)
.L7F00042C:
/* 034F5C 7F00042C 8E020048 */  lw    $v0, 0x48($s0)
/* 034F60 7F000430 26100048 */  addiu $s0, $s0, 0x48
/* 034F64 7F000434 26310001 */  addiu $s1, $s1, 1
/* 034F68 7F000438 5440FFD3 */  bnezl $v0, .L7F000388
/* 034F6C 7F00043C 8E4F0000 */   lw    $t7, ($s2)
.L7F000440:
/* 034F70 7F000440 8FBF003C */  lw    $ra, 0x3c($sp)
/* 034F74 7F000444 02201025 */  move  $v0, $s1
/* 034F78 7F000448 8FB10030 */  lw    $s1, 0x30($sp)
/* 034F7C 7F00044C D7B40010 */  ldc1  $f20, 0x10($sp)
/* 034F80 7F000450 D7B60018 */  ldc1  $f22, 0x18($sp)
/* 034F84 7F000454 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 034F88 7F000458 8FB0002C */  lw    $s0, 0x2c($sp)
/* 034F8C 7F00045C 8FB20034 */  lw    $s2, 0x34($sp)
/* 034F90 7F000460 8FB30038 */  lw    $s3, 0x38($sp)
/* 034F94 7F000464 03E00008 */  jr    $ra
/* 034F98 7F000468 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif


//pd is raceInitAnimGroups
void sub_GAME_7F00046C(struct attackanimgroup **groups)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		if (groups[i]->len < 0) {
			groups[i]->len = sub_GAME_7F00032C(groups[i]->animcfg);
		}
	}
}



#ifdef NONMATCHING
void sub_GAME_7F0004D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0004D0
/* 035000 7F0004D0 8C8E0000 */  lw    $t6, ($a0)
/* 035004 7F0004D4 00001825 */  move  $v1, $zero
/* 035008 7F0004D8 00801025 */  move  $v0, $a0
/* 03500C 7F0004DC 11C0000C */  beqz  $t6, .L7F000510
/* 035010 7F0004E0 00000000 */   nop   
/* 035014 7F0004E4 8C850000 */  lw    $a1, ($a0)
/* 035018 7F0004E8 3C048007 */  lui   $a0, %hi(ptr_animation_table)
/* 03501C 7F0004EC 24849538 */  addiu $a0, %lo(ptr_animation_table) # addiu $a0, $a0, -0x6ac8
/* 035020 7F0004F0 8C8F0000 */  lw    $t7, ($a0)
.L7F0004F4:
/* 035024 7F0004F4 24630001 */  addiu $v1, $v1, 1
/* 035028 7F0004F8 2442001C */  addiu $v0, $v0, 0x1c
/* 03502C 7F0004FC 00AFC021 */  addu  $t8, $a1, $t7
/* 035030 7F000500 8C450000 */  lw    $a1, ($v0)
/* 035034 7F000504 AC58FFE4 */  sw    $t8, -0x1c($v0)
/* 035038 7F000508 54A0FFFA */  bnezl $a1, .L7F0004F4
/* 03503C 7F00050C 8C8F0000 */   lw    $t7, ($a0)
.L7F000510:
/* 035040 7F000510 03E00008 */  jr    $ra
/* 035044 7F000514 00601025 */   move  $v0, $v1
)
#endif



#ifdef NONMATCHING
void somethingwith_weapon_animation_groups(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel F32_8004ED78
.word 0x3dccccce
.text
glabel somethingwith_weapon_animation_groups
/* 035048 7F000518 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 03504C 7F00051C 3C0E8003 */  lui   $t6, %hi(D_8002C914) 
/* 035050 7F000520 8DCEC914 */  lw    $t6, %lo(D_8002C914)($t6)
/* 035054 7F000524 AFB10024 */  sw    $s1, 0x24($sp)
/* 035058 7F000528 2411FFFF */  li    $s1, -1
/* 03505C 7F00052C AFBF002C */  sw    $ra, 0x2c($sp)
/* 035060 7F000530 AFB20028 */  sw    $s2, 0x28($sp)
/* 035064 7F000534 AFB00020 */  sw    $s0, 0x20($sp)
/* 035068 7F000538 122E0013 */  beq   $s1, $t6, .L7F000588
/* 03506C 7F00053C F7B40018 */   sdc1  $f20, 0x18($sp)
/* 035070 7F000540 3C108003 */  lui   $s0, %hi(D_8002C914)
/* 035074 7F000544 2610C914 */  addiu $s0, %lo(D_8002C914) # addiu $s0, $s0, -0x36ec
/* 035078 7F000548 8E04001C */  lw    $a0, 0x1c($s0)
.L7F00054C:
/* 03507C 7F00054C 50800005 */  beql  $a0, $zero, .L7F000564
/* 035080 7F000550 8E040024 */   lw    $a0, 0x24($s0)
/* 035084 7F000554 0FC00134 */  jal   sub_GAME_7F0004D0
/* 035088 7F000558 00000000 */   nop   
/* 03508C 7F00055C AE020020 */  sw    $v0, 0x20($s0)
/* 035090 7F000560 8E040024 */  lw    $a0, 0x24($s0)
.L7F000564:
/* 035094 7F000564 50800005 */  beql  $a0, $zero, .L7F00057C
/* 035098 7F000568 8E0F002C */   lw    $t7, 0x2c($s0)
/* 03509C 7F00056C 0FC00134 */  jal   sub_GAME_7F0004D0
/* 0350A0 7F000570 00000000 */   nop   
/* 0350A4 7F000574 AE020028 */  sw    $v0, 0x28($s0)
/* 0350A8 7F000578 8E0F002C */  lw    $t7, 0x2c($s0)
.L7F00057C:
/* 0350AC 7F00057C 2610002C */  addiu $s0, $s0, 0x2c
/* 0350B0 7F000580 562FFFF2 */  bnel  $s1, $t7, .L7F00054C
/* 0350B4 7F000584 8E04001C */   lw    $a0, 0x1c($s0)
.L7F000588:
/* 0350B8 7F000588 3C048003 */  lui   $a0, %hi(D_8002DEBC)
/* 0350BC 7F00058C 0FC00134 */  jal   sub_GAME_7F0004D0
/* 0350C0 7F000590 2484DEBC */   addiu $a0, %lo(D_8002DEBC) # addiu $a0, $a0, -0x2144
/* 0350C4 7F000594 3C048003 */  lui   $a0, %hi(ptr_rifle_firing_animation_groups)
/* 0350C8 7F000598 0FC0011B */  jal   sub_GAME_7F00046C
/* 0350CC 7F00059C 2484ED28 */   addiu $a0, %lo(ptr_rifle_firing_animation_groups) # addiu $a0, $a0, -0x12d8
/* 0350D0 7F0005A0 3C048003 */  lui   $a0, %hi(ptr_pistol_firing_animation_groups)
/* 0350D4 7F0005A4 0FC0011B */  jal   sub_GAME_7F00046C
/* 0350D8 7F0005A8 2484F408 */   addiu $a0, %lo(ptr_pistol_firing_animation_groups) # addiu $a0, $a0, -0xbf8
/* 0350DC 7F0005AC 3C048003 */  lui   $a0, %hi(ptr_doubles_firing_animation_groups)
/* 0350E0 7F0005B0 0FC0011B */  jal   sub_GAME_7F00046C
/* 0350E4 7F0005B4 2484F6E0 */   addiu $a0, %lo(ptr_doubles_firing_animation_groups) # addiu $a0, $a0, -0x920
/* 0350E8 7F0005B8 3C048003 */  lui   $a0, %hi(ptr_crouched_rifle_firing_animation_groups)
/* 0350EC 7F0005BC 0FC0011B */  jal   sub_GAME_7F00046C
/* 0350F0 7F0005C0 2484F970 */   addiu $a0, %lo(ptr_crouched_rifle_firing_animation_groups) # addiu $a0, $a0, -0x690
/* 0350F4 7F0005C4 3C048003 */  lui   $a0, %hi(ptr_crouched_pistol_firing_animation_groups)
/* 0350F8 7F0005C8 0FC0011B */  jal   sub_GAME_7F00046C
/* 0350FC 7F0005CC 2484FCD8 */   addiu $a0, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a0, $a0, -0x328
/* 035100 7F0005D0 3C048003 */  lui   $a0, %hi(ptr_crouched_doubles_firing_animation_groups)
/* 035104 7F0005D4 0FC0011B */  jal   sub_GAME_7F00046C
/* 035108 7F0005D8 2484FFF8 */   addiu $a0, %lo(ptr_crouched_doubles_firing_animation_groups) # addiu $a0, $a0, -8
/* 03510C 7F0005DC 3C048003 */  lui   $a0, %hi(D_80030078)
/* 035110 7F0005E0 0FC000CB */  jal   sub_GAME_7F00032C
/* 035114 7F0005E4 24840078 */   addiu $a0, %lo(D_80030078) # addiu $a0, $a0, 0x78
/* 035118 7F0005E8 3C048003 */  lui   $a0, %hi(D_80030660)
/* 03511C 7F0005EC 0FC000CB */  jal   sub_GAME_7F00032C
/* 035120 7F0005F0 24840660 */   addiu $a0, %lo(D_80030660) # addiu $a0, $a0, 0x660
/* 035124 7F0005F4 3C128007 */  lui   $s2, %hi(ptr_animation_table)
/* 035128 7F0005F8 26529538 */  addiu $s2, %lo(ptr_animation_table) # addiu $s2, $s2, -0x6ac8
/* 03512C 7F0005FC 8E580000 */  lw    $t8, ($s2)
/* 035130 7F000600 3C110000 */  lui   $s1, %hi(0x00004018) # $s1, 0
/* 035134 7F000604 26314018 */  addiu $s1, %lo(0x00004018) # addiu $s1, $s1, 0x4018
/* 035138 7F000608 02382021 */  addu  $a0, $s1, $t8
/* 03513C 7F00060C 94860004 */  lhu   $a2, 4($a0)
/* 035140 7F000610 00002825 */  move  $a1, $zero
/* 035144 7F000614 0FC000A4 */  jal   sub_GAME_7F000290
/* 035148 7F000618 24C6FFFF */   addiu $a2, $a2, -1
/* 03514C 7F00061C 44822000 */  mtc1  $v0, $f4
/* 035150 7F000620 8E500000 */  lw    $s0, ($s2)
/* 035154 7F000624 3C018005 */  lui   $at, %hi(F32_8004ED78)
/* 035158 7F000628 468021A0 */  cvt.s.w $f6, $f4
/* 03515C 7F00062C 0230C821 */  addu  $t9, $s1, $s0
/* 035160 7F000630 97280004 */  lhu   $t0, 4($t9)
/* 035164 7F000634 C434ED78 */  lwc1  $f20, %lo(F32_8004ED78)($at)
/* 035168 7F000638 44885000 */  mtc1  $t0, $f10
/* 03516C 7F00063C 46143202 */  mul.s $f8, $f6, $f20
/* 035170 7F000640 05010005 */  bgez  $t0, .L7F000658
/* 035174 7F000644 46805420 */   cvt.s.w $f16, $f10
/* 035178 7F000648 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 03517C 7F00064C 44819000 */  mtc1  $at, $f18
/* 035180 7F000650 00000000 */  nop   
/* 035184 7F000654 46128400 */  add.s $f16, $f16, $f18
.L7F000658:
/* 035188 7F000658 46104103 */  div.s $f4, $f8, $f16
/* 03518C 7F00065C 3C030000 */  lui   $v1, %hi(0x000040D4) # $v1, 0
/* 035190 7F000660 3C018003 */  lui   $at, %hi(D_80030984)
/* 035194 7F000664 246340D4 */  addiu $v1, %lo(0x000040D4) # addiu $v1, $v1, 0x40d4
/* 035198 7F000668 00702021 */  addu  $a0, $v1, $s0
/* 03519C 7F00066C 00002825 */  move  $a1, $zero
/* 0351A0 7F000670 E4240984 */  swc1  $f4, %lo(D_80030984)($at)
/* 0351A4 7F000674 94860004 */  lhu   $a2, 4($a0)
/* 0351A8 7F000678 AFA30034 */  sw    $v1, 0x34($sp)
/* 0351AC 7F00067C 0FC000A4 */  jal   sub_GAME_7F000290
/* 0351B0 7F000680 24C6FFFF */   addiu $a2, $a2, -1
/* 0351B4 7F000684 44823000 */  mtc1  $v0, $f6
/* 0351B8 7F000688 8FA30034 */  lw    $v1, 0x34($sp)
/* 0351BC 7F00068C 8E500000 */  lw    $s0, ($s2)
/* 0351C0 7F000690 468032A0 */  cvt.s.w $f10, $f6
/* 0351C4 7F000694 00704821 */  addu  $t1, $v1, $s0
/* 0351C8 7F000698 952A0004 */  lhu   $t2, 4($t1)
/* 0351CC 7F00069C 448A4000 */  mtc1  $t2, $f8
/* 0351D0 7F0006A0 46145482 */  mul.s $f18, $f10, $f20
/* 0351D4 7F0006A4 05410005 */  bgez  $t2, .L7F0006BC
/* 0351D8 7F0006A8 46804420 */   cvt.s.w $f16, $f8
/* 0351DC 7F0006AC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0351E0 7F0006B0 44812000 */  mtc1  $at, $f4
/* 0351E4 7F0006B4 00000000 */  nop   
/* 0351E8 7F0006B8 46048400 */  add.s $f16, $f16, $f4
.L7F0006BC:
/* 0351EC 7F0006BC 46109183 */  div.s $f6, $f18, $f16
/* 0351F0 7F0006C0 3C110000 */  lui   $s1, %hi(0x00004070) # $s1, 0
/* 0351F4 7F0006C4 3C018003 */  lui   $at, %hi(D_80030988)
/* 0351F8 7F0006C8 26314070 */  addiu $s1, %lo(0x00004070) # addiu $s1, $s1, 0x4070
/* 0351FC 7F0006CC 02302021 */  addu  $a0, $s1, $s0
/* 035200 7F0006D0 00002825 */  move  $a1, $zero
/* 035204 7F0006D4 E4260988 */  swc1  $f6, %lo(D_80030988)($at)
/* 035208 7F0006D8 94860004 */  lhu   $a2, 4($a0)
/* 03520C 7F0006DC 0FC000A4 */  jal   sub_GAME_7F000290
/* 035210 7F0006E0 24C6FFFF */   addiu $a2, $a2, -1
/* 035214 7F0006E4 44825000 */  mtc1  $v0, $f10
/* 035218 7F0006E8 8E500000 */  lw    $s0, ($s2)
/* 03521C 7F0006EC 46805220 */  cvt.s.w $f8, $f10
/* 035220 7F0006F0 02305821 */  addu  $t3, $s1, $s0
/* 035224 7F0006F4 956C0004 */  lhu   $t4, 4($t3)
/* 035228 7F0006F8 448C9000 */  mtc1  $t4, $f18
/* 03522C 7F0006FC 46144102 */  mul.s $f4, $f8, $f20
/* 035230 7F000700 05810005 */  bgez  $t4, .L7F000718
/* 035234 7F000704 46809420 */   cvt.s.w $f16, $f18
/* 035238 7F000708 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 03523C 7F00070C 44813000 */  mtc1  $at, $f6
/* 035240 7F000710 00000000 */  nop   
/* 035244 7F000714 46068400 */  add.s $f16, $f16, $f6
.L7F000718:
/* 035248 7F000718 46102283 */  div.s $f10, $f4, $f16
/* 03524C 7F00071C 3C030001 */  lui   $v1, %hi(0x00008204) # $v1, 1
/* 035250 7F000720 3C018003 */  lui   $at, %hi(D_8003098C)
/* 035254 7F000724 24638204 */  addiu $v1, %lo(0x00008204) # addiu $v1, $v1, -0x7dfc
/* 035258 7F000728 00702021 */  addu  $a0, $v1, $s0
/* 03525C 7F00072C 00002825 */  move  $a1, $zero
/* 035260 7F000730 E42A098C */  swc1  $f10, %lo(D_8003098C)($at)
/* 035264 7F000734 94860004 */  lhu   $a2, 4($a0)
/* 035268 7F000738 AFA30034 */  sw    $v1, 0x34($sp)
/* 03526C 7F00073C 0FC000A4 */  jal   sub_GAME_7F000290
/* 035270 7F000740 24C6FFFF */   addiu $a2, $a2, -1
/* 035274 7F000744 44824000 */  mtc1  $v0, $f8
/* 035278 7F000748 8FA30034 */  lw    $v1, 0x34($sp)
/* 03527C 7F00074C 8E500000 */  lw    $s0, ($s2)
/* 035280 7F000750 468044A0 */  cvt.s.w $f18, $f8
/* 035284 7F000754 00706821 */  addu  $t5, $v1, $s0
/* 035288 7F000758 95AE0004 */  lhu   $t6, 4($t5)
/* 03528C 7F00075C 448E2000 */  mtc1  $t6, $f4
/* 035290 7F000760 46149182 */  mul.s $f6, $f18, $f20
/* 035294 7F000764 05C10005 */  bgez  $t6, .L7F00077C
/* 035298 7F000768 46802420 */   cvt.s.w $f16, $f4
/* 03529C 7F00076C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0352A0 7F000770 44815000 */  mtc1  $at, $f10
/* 0352A4 7F000774 00000000 */  nop   
/* 0352A8 7F000778 460A8400 */  add.s $f16, $f16, $f10
.L7F00077C:
/* 0352AC 7F00077C 46103203 */  div.s $f8, $f6, $f16
/* 0352B0 7F000780 3C070000 */  lui   $a3, %hi(0x0000777C) # $a3, 0
/* 0352B4 7F000784 3C018003 */  lui   $at, %hi(D_80030990)
/* 0352B8 7F000788 24E7777C */  addiu $a3, %lo(0x0000777C) # addiu $a3, $a3, 0x777c
/* 0352BC 7F00078C 00F02021 */  addu  $a0, $a3, $s0
/* 0352C0 7F000790 00002825 */  move  $a1, $zero
/* 0352C4 7F000794 E4280990 */  swc1  $f8, %lo(D_80030990)($at)
/* 0352C8 7F000798 94860004 */  lhu   $a2, 4($a0)
/* 0352CC 7F00079C AFA70038 */  sw    $a3, 0x38($sp)
/* 0352D0 7F0007A0 0FC000A4 */  jal   sub_GAME_7F000290
/* 0352D4 7F0007A4 24C6FFFF */   addiu $a2, $a2, -1
/* 0352D8 7F0007A8 44829000 */  mtc1  $v0, $f18
/* 0352DC 7F0007AC 8FA70038 */  lw    $a3, 0x38($sp)
/* 0352E0 7F0007B0 8E500000 */  lw    $s0, ($s2)
/* 0352E4 7F0007B4 46809120 */  cvt.s.w $f4, $f18
/* 0352E8 7F0007B8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0352EC 7F0007BC 00F07821 */  addu  $t7, $a3, $s0
/* 0352F0 7F0007C0 95F80004 */  lhu   $t8, 4($t7)
/* 0352F4 7F0007C4 44983000 */  mtc1  $t8, $f6
/* 0352F8 7F0007C8 46142282 */  mul.s $f10, $f4, $f20
/* 0352FC 7F0007CC 07010004 */  bgez  $t8, .L7F0007E0
/* 035300 7F0007D0 46803420 */   cvt.s.w $f16, $f6
/* 035304 7F0007D4 44814000 */  mtc1  $at, $f8
/* 035308 7F0007D8 00000000 */  nop   
/* 03530C 7F0007DC 46088400 */  add.s $f16, $f16, $f8
.L7F0007E0:
/* 035310 7F0007E0 46105483 */  div.s $f18, $f10, $f16
/* 035314 7F0007E4 3C110000 */  lui   $s1, %hi(0x000077D4) # $s1, 0
/* 035318 7F0007E8 3C018003 */  lui   $at, %hi(D_80030994)
/* 03531C 7F0007EC 263177D4 */  addiu $s1, %lo(0x000077D4) # addiu $s1, $s1, 0x77d4
/* 035320 7F0007F0 02302021 */  addu  $a0, $s1, $s0
/* 035324 7F0007F4 00002825 */  move  $a1, $zero
/* 035328 7F0007F8 E4320994 */  swc1  $f18, %lo(D_80030994)($at)
/* 03532C 7F0007FC 94860004 */  lhu   $a2, 4($a0)
/* 035330 7F000800 0FC000A4 */  jal   sub_GAME_7F000290
/* 035334 7F000804 24C6FFFF */   addiu $a2, $a2, -1
/* 035338 7F000808 44822000 */  mtc1  $v0, $f4
/* 03533C 7F00080C 8E500000 */  lw    $s0, ($s2)
/* 035340 7F000810 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 035344 7F000814 468021A0 */  cvt.s.w $f6, $f4
/* 035348 7F000818 0230C821 */  addu  $t9, $s1, $s0
/* 03534C 7F00081C 97280004 */  lhu   $t0, 4($t9)
/* 035350 7F000820 44885000 */  mtc1  $t0, $f10
/* 035354 7F000824 46143202 */  mul.s $f8, $f6, $f20
/* 035358 7F000828 05010004 */  bgez  $t0, .L7F00083C
/* 03535C 7F00082C 46805420 */   cvt.s.w $f16, $f10
/* 035360 7F000830 44819000 */  mtc1  $at, $f18
/* 035364 7F000834 00000000 */  nop   
/* 035368 7F000838 46128400 */  add.s $f16, $f16, $f18
.L7F00083C:
/* 03536C 7F00083C 46104103 */  div.s $f4, $f8, $f16
/* 035370 7F000840 3C030001 */  lui   $v1, %hi(0x000084C4) # $v1, 1
/* 035374 7F000844 3C018003 */  lui   $at, %hi(D_80030998)
/* 035378 7F000848 246384C4 */  addiu $v1, %lo(0x000084C4) # addiu $v1, $v1, -0x7b3c
/* 03537C 7F00084C 00702021 */  addu  $a0, $v1, $s0
/* 035380 7F000850 00002825 */  move  $a1, $zero
/* 035384 7F000854 E4240998 */  swc1  $f4, %lo(D_80030998)($at)
/* 035388 7F000858 94860004 */  lhu   $a2, 4($a0)
/* 03538C 7F00085C AFA30038 */  sw    $v1, 0x38($sp)
/* 035390 7F000860 0FC000A4 */  jal   sub_GAME_7F000290
/* 035394 7F000864 24C6FFFF */   addiu $a2, $a2, -1
/* 035398 7F000868 44823000 */  mtc1  $v0, $f6
/* 03539C 7F00086C 8FA30038 */  lw    $v1, 0x38($sp)
/* 0353A0 7F000870 8E500000 */  lw    $s0, ($s2)
/* 0353A4 7F000874 468032A0 */  cvt.s.w $f10, $f6
/* 0353A8 7F000878 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0353AC 7F00087C 00704821 */  addu  $t1, $v1, $s0
/* 0353B0 7F000880 952A0004 */  lhu   $t2, 4($t1)
/* 0353B4 7F000884 448A4000 */  mtc1  $t2, $f8
/* 0353B8 7F000888 46145482 */  mul.s $f18, $f10, $f20
/* 0353BC 7F00088C 05410004 */  bgez  $t2, .L7F0008A0
/* 0353C0 7F000890 46804420 */   cvt.s.w $f16, $f8
/* 0353C4 7F000894 44812000 */  mtc1  $at, $f4
/* 0353C8 7F000898 00000000 */  nop   
/* 0353CC 7F00089C 46048400 */  add.s $f16, $f16, $f4
.L7F0008A0:
/* 0353D0 7F0008A0 46109183 */  div.s $f6, $f18, $f16
/* 0353D4 7F0008A4 3C070001 */  lui   $a3, %hi(0x00008520) # $a3, 1
/* 0353D8 7F0008A8 3C018003 */  lui   $at, %hi(D_8003099C)
/* 0353DC 7F0008AC 24E78520 */  addiu $a3, %lo(0x00008520) # addiu $a3, $a3, -0x7ae0
/* 0353E0 7F0008B0 00F02021 */  addu  $a0, $a3, $s0
/* 0353E4 7F0008B4 00002825 */  move  $a1, $zero
/* 0353E8 7F0008B8 E426099C */  swc1  $f6, %lo(D_8003099C)($at)
/* 0353EC 7F0008BC 94860004 */  lhu   $a2, 4($a0)
/* 0353F0 7F0008C0 AFA70030 */  sw    $a3, 0x30($sp)
/* 0353F4 7F0008C4 0FC000A4 */  jal   sub_GAME_7F000290
/* 0353F8 7F0008C8 24C6FFFF */   addiu $a2, $a2, -1
/* 0353FC 7F0008CC 44825000 */  mtc1  $v0, $f10
/* 035400 7F0008D0 8FA70030 */  lw    $a3, 0x30($sp)
/* 035404 7F0008D4 8E500000 */  lw    $s0, ($s2)
/* 035408 7F0008D8 46805220 */  cvt.s.w $f8, $f10
/* 03540C 7F0008DC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 035410 7F0008E0 00F05821 */  addu  $t3, $a3, $s0
/* 035414 7F0008E4 956C0004 */  lhu   $t4, 4($t3)
/* 035418 7F0008E8 448C9000 */  mtc1  $t4, $f18
/* 03541C 7F0008EC 46144102 */  mul.s $f4, $f8, $f20
/* 035420 7F0008F0 05810004 */  bgez  $t4, .L7F000904
/* 035424 7F0008F4 46809420 */   cvt.s.w $f16, $f18
/* 035428 7F0008F8 44813000 */  mtc1  $at, $f6
/* 03542C 7F0008FC 00000000 */  nop   
/* 035430 7F000900 46068400 */  add.s $f16, $f16, $f6
.L7F000904:
/* 035434 7F000904 46102283 */  div.s $f10, $f4, $f16
/* 035438 7F000908 3C018003 */  lui   $at, %hi(D_800309A0)
/* 03543C 7F00090C 02302021 */  addu  $a0, $s1, $s0
/* 035440 7F000910 00002825 */  move  $a1, $zero
/* 035444 7F000914 E42A09A0 */  swc1  $f10, %lo(D_800309A0)($at)
/* 035448 7F000918 94860004 */  lhu   $a2, 4($a0)
/* 03544C 7F00091C 0FC000A4 */  jal   sub_GAME_7F000290
/* 035450 7F000920 24C6FFFF */   addiu $a2, $a2, -1
/* 035454 7F000924 44824000 */  mtc1  $v0, $f8
/* 035458 7F000928 8E4D0000 */  lw    $t5, ($s2)
/* 03545C 7F00092C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 035460 7F000930 468044A0 */  cvt.s.w $f18, $f8
/* 035464 7F000934 022D7021 */  addu  $t6, $s1, $t5
/* 035468 7F000938 95CF0004 */  lhu   $t7, 4($t6)
/* 03546C 7F00093C 448F2000 */  mtc1  $t7, $f4
/* 035470 7F000940 46149182 */  mul.s $f6, $f18, $f20
/* 035474 7F000944 05E10004 */  bgez  $t7, .L7F000958
/* 035478 7F000948 46802420 */   cvt.s.w $f16, $f4
/* 03547C 7F00094C 44815000 */  mtc1  $at, $f10
/* 035480 7F000950 00000000 */  nop   
/* 035484 7F000954 460A8400 */  add.s $f16, $f16, $f10
.L7F000958:
/* 035488 7F000958 46103203 */  div.s $f8, $f6, $f16
/* 03548C 7F00095C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 035490 7F000960 3C018003 */  lui   $at, %hi(D_800309A4)
/* 035494 7F000964 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 035498 7F000968 8FB00020 */  lw    $s0, 0x20($sp)
/* 03549C 7F00096C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0354A0 7F000970 8FB20028 */  lw    $s2, 0x28($sp)
/* 0354A4 7F000974 27BD0040 */  addiu $sp, $sp, 0x40
/* 0354A8 7F000978 03E00008 */  jr    $ra
/* 0354AC 7F00097C E42809A4 */   swc1  $f8, %lo(D_800309A4)($at)
)
#endif



void sub_GAME_7F000980(void) {
    sub_GAME_7F0009A0();
}

#if defined (VERSION_EU)
#define POS 0x19
#else
#define POS 0x27
#endif

void sub_GAME_7F0009A0(void) {
    u32 *end = &g_Casings[20];
    u32 *ptr = &g_Casings[0];
    while(end > ptr) {
        ptr[POS] = 0;
        ptr += POS+1;
    }
}

