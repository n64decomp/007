#include <ultra64.h>


// rodata



#ifdef NONMATCHING
f32 sub_GAME_7F0B3200(f32 *param_1,f32 *param_2,f32 *param_3,f32 *param_4)

{
  if ((*param_2 - *param_1) * param_3[1] - param_4[1] + (param_2[1] - param_1[1]) * *param_4 - *param_3 == 0.00000000) {
    return 1.00000000;
  }
  else {
    
    if ((((*param_3 - *param_1) * param_3[1] - param_4[1] + (param_3[1] - param_1[1]) * *param_4 - *param_3) / (*param_2 - *param_1) * param_3[1] - param_4[1] + (param_2[1] - param_1[1]) * *param_4 - *param_3 < 0.00000000) || (1.00000000 < ((*param_3 - *param_1) * param_3[1] - param_4[1] + (param_3[1] - param_1[1]) * *param_4 - *param_3) / (*param_2 - *param_1) * param_3[1] - param_4[1] + (param_2[1] - param_1[1]) * *param_4 - *param_3)) {
      return 1.00000000;
    }
  }

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B3200
/* 0E7D30 7F0B3200 C4CE0000 */  lwc1  $f14, ($a2)
/* 0E7D34 7F0B3204 C4E60000 */  lwc1  $f6, ($a3)
/* 0E7D38 7F0B3208 C4880004 */  lwc1  $f8, 4($a0)
/* 0E7D3C 7F0B320C C4C20004 */  lwc1  $f2, 4($a2)
/* 0E7D40 7F0B3210 C4E40004 */  lwc1  $f4, 4($a3)
/* 0E7D44 7F0B3214 C4920000 */  lwc1  $f18, ($a0)
/* 0E7D48 7F0B3218 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E7D4C 7F0B321C 460E3301 */  sub.s $f12, $f6, $f14
/* 0E7D50 7F0B3220 E7A80000 */  swc1  $f8, ($sp)
/* 0E7D54 7F0B3224 C7A60000 */  lwc1  $f6, ($sp)
/* 0E7D58 7F0B3228 46041001 */  sub.s $f0, $f2, $f4
/* 0E7D5C 7F0B322C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E7D60 7F0B3230 46127281 */  sub.s $f10, $f14, $f18
/* 0E7D64 7F0B3234 46061201 */  sub.s $f8, $f2, $f6
/* 0E7D68 7F0B3238 46005102 */  mul.s $f4, $f10, $f0
/* 0E7D6C 7F0B323C 00000000 */  nop   
/* 0E7D70 7F0B3240 460C4282 */  mul.s $f10, $f8, $f12
/* 0E7D74 7F0B3244 C4A80004 */  lwc1  $f8, 4($a1)
/* 0E7D78 7F0B3248 460A2400 */  add.s $f16, $f4, $f10
/* 0E7D7C 7F0B324C 46064101 */  sub.s $f4, $f8, $f6
/* 0E7D80 7F0B3250 C4A80000 */  lwc1  $f8, ($a1)
/* 0E7D84 7F0B3254 46124181 */  sub.s $f6, $f8, $f18
/* 0E7D88 7F0B3258 460C2282 */  mul.s $f10, $f4, $f12
/* 0E7D8C 7F0B325C 00000000 */  nop   
/* 0E7D90 7F0B3260 46003102 */  mul.s $f4, $f6, $f0
/* 0E7D94 7F0B3264 44803000 */  mtc1  $zero, $f6
/* 0E7D98 7F0B3268 460A2200 */  add.s $f8, $f4, $f10
/* 0E7D9C 7F0B326C 46064032 */  c.eq.s $f8, $f6
/* 0E7DA0 7F0B3270 E7A80010 */  swc1  $f8, 0x10($sp)
/* 0E7DA4 7F0B3274 C7A40010 */  lwc1  $f4, 0x10($sp)
/* 0E7DA8 7F0B3278 45000004 */  bc1f  .L7F0B328C
/* 0E7DAC 7F0B327C 00000000 */   nop   
/* 0E7DB0 7F0B3280 44810000 */  mtc1  $at, $f0
/* 0E7DB4 7F0B3284 10000012 */  b     .L7F0B32D0
/* 0E7DB8 7F0B3288 00000000 */   nop   
.L7F0B328C:
/* 0E7DBC 7F0B328C 46048403 */  div.s $f16, $f16, $f4
/* 0E7DC0 7F0B3290 44805000 */  mtc1  $zero, $f10
/* 0E7DC4 7F0B3294 3C013F80 */  lui   $at, 0x3f80
/* 0E7DC8 7F0B3298 460A803C */  c.lt.s $f16, $f10
/* 0E7DCC 7F0B329C 00000000 */  nop   
/* 0E7DD0 7F0B32A0 45030007 */  bc1tl .L7F0B32C0
/* 0E7DD4 7F0B32A4 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0E7DD8 7F0B32A8 44814000 */  mtc1  $at, $f8
/* 0E7DDC 7F0B32AC 00000000 */  nop   
/* 0E7DE0 7F0B32B0 4610403C */  c.lt.s $f8, $f16
/* 0E7DE4 7F0B32B4 00000000 */  nop   
/* 0E7DE8 7F0B32B8 45000004 */  bc1f  .L7F0B32CC
/* 0E7DEC 7F0B32BC 3C013F80 */   li    $at, 0x3F800000 # 1.000000
.L7F0B32C0:
/* 0E7DF0 7F0B32C0 44810000 */  mtc1  $at, $f0
/* 0E7DF4 7F0B32C4 10000002 */  b     .L7F0B32D0
/* 0E7DF8 7F0B32C8 00000000 */   nop   
.L7F0B32CC:
/* 0E7DFC 7F0B32CC 46008006 */  mov.s $f0, $f16
.L7F0B32D0:
/* 0E7E00 7F0B32D0 03E00008 */  jr    $ra
/* 0E7E04 7F0B32D4 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F0B32D8(coord3d *param_1,coord3d *param_2,coord3d *param_3)

{

  f32 fVar2;
  float __x;


  __x = (param_1->x - ((param_2->x) * (param_3->y - param_1->z) - (param_3->x - param_1->y) * (param_2->y))) * (param_1->x + ((param_2->x) * (param_3->y - param_1->z) - (param_3->x - param_1->y) * (param_2->y)));
  if (__x < 0.00000000)
  {
    return 340282346638528859811704183484516925440.00000000;
  }
  else {
    __x = sqrtf(__x);
    fVar2 = (f32)(((param_2->x) * (param_3->x - param_1->y) + (param_3->y - param_1->z) * (param_2->y)) - __x);
    if (fVar2 < 0.00000000) {
      if (fVar2 * fVar2 + ((param_2->x) * (param_3->y - param_1->z) - (param_3->x - param_1->y) * (param_2->y)) * ((param_2->x) * (param_3->y - param_1->z) - (param_3->x - param_1->y) * (param_2->y)) <= param_1->x * param_1->x) {
        fVar2 = 0.00000000;
      }
      else {
        fVar2 = (f32)340282346638528859811704183484516925440.00000000;
      }
    }
  }
  return fVar2;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800585E0
.word 0x7f7fffff /*3.4028235e38*/
glabel D_800585E4
.word 0x7f7fffff /*3.4028235e38*/
.text
glabel sub_GAME_7F0B32D8
/* 0E7E08 7F0B32D8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E7E0C 7F0B32DC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E7E10 7F0B32E0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0E7E14 7F0B32E4 C48A0008 */  lwc1  $f10, 8($a0)
/* 0E7E18 7F0B32E8 C4C80004 */  lwc1  $f8, 4($a2)
/* 0E7E1C 7F0B32EC C4860004 */  lwc1  $f6, 4($a0)
/* 0E7E20 7F0B32F0 C4C40000 */  lwc1  $f4, ($a2)
/* 0E7E24 7F0B32F4 460A4301 */  sub.s $f12, $f8, $f10
/* 0E7E28 7F0B32F8 C4AE0000 */  lwc1  $f14, ($a1)
/* 0E7E2C 7F0B32FC C4B00004 */  lwc1  $f16, 4($a1)
/* 0E7E30 7F0B3300 46062001 */  sub.s $f0, $f4, $f6
/* 0E7E34 7F0B3304 460C7102 */  mul.s $f4, $f14, $f12
/* 0E7E38 7F0B3308 C4920000 */  lwc1  $f18, ($a0)
/* 0E7E3C 7F0B330C 3C018006 */  lui   $at, %hi(D_800585E0)
/* 0E7E40 7F0B3310 46100182 */  mul.s $f6, $f0, $f16
/* 0E7E44 7F0B3314 46062501 */  sub.s $f20, $f4, $f6
/* 0E7E48 7F0B3318 46007202 */  mul.s $f8, $f14, $f0
/* 0E7E4C 7F0B331C 00000000 */  nop   
/* 0E7E50 7F0B3320 46106282 */  mul.s $f10, $f12, $f16
/* 0E7E54 7F0B3324 46149101 */  sub.s $f4, $f18, $f20
/* 0E7E58 7F0B3328 46149180 */  add.s $f6, $f18, $f20
/* 0E7E5C 7F0B332C 460A4080 */  add.s $f2, $f8, $f10
/* 0E7E60 7F0B3330 46062202 */  mul.s $f8, $f4, $f6
/* 0E7E64 7F0B3334 44805000 */  mtc1  $zero, $f10
/* 0E7E68 7F0B3338 00000000 */  nop   
/* 0E7E6C 7F0B333C 460A403C */  c.lt.s $f8, $f10
/* 0E7E70 7F0B3340 E7A80024 */  swc1  $f8, 0x24($sp)
/* 0E7E74 7F0B3344 C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 0E7E78 7F0B3348 45000003 */  bc1f  .L7F0B3358
/* 0E7E7C 7F0B334C 00000000 */   nop   
/* 0E7E80 7F0B3350 1000001D */  b     .L7F0B33C8
/* 0E7E84 7F0B3354 C42085E0 */   lwc1  $f0, %lo(D_800585E0)($at)
.L7F0B3358:
/* 0E7E88 7F0B3358 AFA40030 */  sw    $a0, 0x30($sp)
/* 0E7E8C 7F0B335C 0C007DF8 */  jal   sqrtf
/* 0E7E90 7F0B3360 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 0E7E94 7F0B3364 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 0E7E98 7F0B3368 44806000 */  mtc1  $zero, $f12
/* 0E7E9C 7F0B336C 8FA40030 */  lw    $a0, 0x30($sp)
/* 0E7EA0 7F0B3370 46001081 */  sub.s $f2, $f2, $f0
/* 0E7EA4 7F0B3374 460C103C */  c.lt.s $f2, $f12
/* 0E7EA8 7F0B3378 00000000 */  nop   
/* 0E7EAC 7F0B337C 45020012 */  bc1fl .L7F0B33C8
/* 0E7EB0 7F0B3380 46001006 */   mov.s $f0, $f2
/* 0E7EB4 7F0B3384 C4920000 */  lwc1  $f18, ($a0)
/* 0E7EB8 7F0B3388 3C018006 */  lui   $at, %hi(D_800585E4)
/* 0E7EBC 7F0B338C 46129102 */  mul.s $f4, $f18, $f18
/* 0E7EC0 7F0B3390 00000000 */  nop   
/* 0E7EC4 7F0B3394 46021182 */  mul.s $f6, $f2, $f2
/* 0E7EC8 7F0B3398 00000000 */  nop   
/* 0E7ECC 7F0B339C 4614A202 */  mul.s $f8, $f20, $f20
/* 0E7ED0 7F0B33A0 46083280 */  add.s $f10, $f6, $f8
/* 0E7ED4 7F0B33A4 4604503E */  c.le.s $f10, $f4
/* 0E7ED8 7F0B33A8 00000000 */  nop   
/* 0E7EDC 7F0B33AC 45000003 */  bc1f  .L7F0B33BC
/* 0E7EE0 7F0B33B0 00000000 */   nop   
/* 0E7EE4 7F0B33B4 10000004 */  b     .L7F0B33C8
/* 0E7EE8 7F0B33B8 46006006 */   mov.s $f0, $f12
.L7F0B33BC:
/* 0E7EEC 7F0B33BC 10000002 */  b     .L7F0B33C8
/* 0E7EF0 7F0B33C0 C42085E4 */   lwc1  $f0, %lo(D_800585E4)($at)
/* 0E7EF4 7F0B33C4 46001006 */  mov.s $f0, $f2
.L7F0B33C8:
/* 0E7EF8 7F0B33C8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E7EFC 7F0B33CC D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0E7F00 7F0B33D0 27BD0030 */  addiu $sp, $sp, 0x30
/* 0E7F04 7F0B33D4 03E00008 */  jr    $ra
/* 0E7F08 7F0B33D8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0B33DC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0B33DC
/* 0E7F0C 7F0B33DC 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 0E7F10 7F0B33E0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E7F14 7F0B33E4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E7F18 7F0B33E8 AFA600B8 */  sw    $a2, 0xb8($sp)
/* 0E7F1C 7F0B33EC C4E00000 */  lwc1  $f0, ($a3)
/* 0E7F20 7F0B33F0 C4E20004 */  lwc1  $f2, 4($a3)
/* 0E7F24 7F0B33F4 00A08025 */  move  $s0, $a1
/* 0E7F28 7F0B33F8 46000102 */  mul.s $f4, $f0, $f0
/* 0E7F2C 7F0B33FC AFA700BC */  sw    $a3, 0xbc($sp)
/* 0E7F30 7F0B3400 AFA400B0 */  sw    $a0, 0xb0($sp)
/* 0E7F34 7F0B3404 46021282 */  mul.s $f10, $f2, $f2
/* 0E7F38 7F0B3408 0C007DF8 */  jal   sqrtf
/* 0E7F3C 7F0B340C 460A2300 */   add.s $f12, $f4, $f10
/* 0E7F40 7F0B3410 44803000 */  mtc1  $zero, $f6
/* 0E7F44 7F0B3414 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0E7F48 7F0B3418 8FA700BC */  lw    $a3, 0xbc($sp)
/* 0E7F4C 7F0B341C 46060032 */  c.eq.s $f0, $f6
/* 0E7F50 7F0B3420 46000386 */  mov.s $f14, $f0
/* 0E7F54 7F0B3424 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E7F58 7F0B3428 45020006 */  bc1fl .L7F0B3444
/* 0E7F5C 7F0B342C 44814000 */   mtc1  $at, $f8
/* 0E7F60 7F0B3430 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E7F64 7F0B3434 44810000 */  mtc1  $at, $f0
/* 0E7F68 7F0B3438 100000DC */  b     .L7F0B37AC
/* 0E7F6C 7F0B343C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0E7F70 7F0B3440 44814000 */  mtc1  $at, $f8
.L7F0B3444:
/* 0E7F74 7F0B3444 C4E40000 */  lwc1  $f4, ($a3)
/* 0E7F78 7F0B3448 8FA200B8 */  lw    $v0, 0xb8($sp)
/* 0E7F7C 7F0B344C 460E4403 */  div.s $f16, $f8, $f14
/* 0E7F80 7F0B3450 46102282 */  mul.s $f10, $f4, $f16
/* 0E7F84 7F0B3454 E7AA00A0 */  swc1  $f10, 0xa0($sp)
/* 0E7F88 7F0B3458 C4E60004 */  lwc1  $f6, 4($a3)
/* 0E7F8C 7F0B345C 46103202 */  mul.s $f8, $f6, $f16
/* 0E7F90 7F0B3460 E7A800A4 */  swc1  $f8, 0xa4($sp)
/* 0E7F94 7F0B3464 C60A0000 */  lwc1  $f10, ($s0)
/* 0E7F98 7F0B3468 C4440000 */  lwc1  $f4, ($v0)
/* 0E7F9C 7F0B346C C6080004 */  lwc1  $f8, 4($s0)
/* 0E7FA0 7F0B3470 C4460004 */  lwc1  $f6, 4($v0)
/* 0E7FA4 7F0B3474 460A2001 */  sub.s $f0, $f4, $f10
/* 0E7FA8 7F0B3478 E7B00044 */  swc1  $f16, 0x44($sp)
/* 0E7FAC 7F0B347C E7AE00AC */  swc1  $f14, 0xac($sp)
/* 0E7FB0 7F0B3480 46083081 */  sub.s $f2, $f6, $f8
/* 0E7FB4 7F0B3484 46000102 */  mul.s $f4, $f0, $f0
/* 0E7FB8 7F0B3488 E7A00098 */  swc1  $f0, 0x98($sp)
/* 0E7FBC 7F0B348C AFA700BC */  sw    $a3, 0xbc($sp)
/* 0E7FC0 7F0B3490 46021282 */  mul.s $f10, $f2, $f2
/* 0E7FC4 7F0B3494 E7A2009C */  swc1  $f2, 0x9c($sp)
/* 0E7FC8 7F0B3498 AFA400B0 */  sw    $a0, 0xb0($sp)
/* 0E7FCC 7F0B349C 0C007DF8 */  jal   sqrtf
/* 0E7FD0 7F0B34A0 460A2300 */   add.s $f12, $f4, $f10
/* 0E7FD4 7F0B34A4 44803000 */  mtc1  $zero, $f6
/* 0E7FD8 7F0B34A8 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0E7FDC 7F0B34AC 8FA700BC */  lw    $a3, 0xbc($sp)
/* 0E7FE0 7F0B34B0 46060032 */  c.eq.s $f0, $f6
/* 0E7FE4 7F0B34B4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E7FE8 7F0B34B8 27A500A0 */  addiu $a1, $sp, 0xa0
/* 0E7FEC 7F0B34BC 45010077 */  bc1t  .L7F0B369C
/* 0E7FF0 7F0B34C0 00000000 */   nop   
/* 0E7FF4 7F0B34C4 44814000 */  mtc1  $at, $f8
/* 0E7FF8 7F0B34C8 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0E7FFC 7F0B34CC C7A60098 */  lwc1  $f6, 0x98($sp)
/* 0E8000 7F0B34D0 46004483 */  div.s $f18, $f8, $f0
/* 0E8004 7F0B34D4 02001025 */  move  $v0, $s0
/* 0E8008 7F0B34D8 46003207 */  neg.s $f8, $f6
/* 0E800C 7F0B34DC 46122282 */  mul.s $f10, $f4, $f18
/* 0E8010 7F0B34E0 00000000 */  nop   
/* 0E8014 7F0B34E4 46124102 */  mul.s $f4, $f8, $f18
/* 0E8018 7F0B34E8 E7AA002C */  swc1  $f10, 0x2c($sp)
/* 0E801C 7F0B34EC E7AA0088 */  swc1  $f10, 0x88($sp)
/* 0E8020 7F0B34F0 E7A40028 */  swc1  $f4, 0x28($sp)
/* 0E8024 7F0B34F4 E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0E8028 7F0B34F8 C4860000 */  lwc1  $f6, ($a0)
/* 0E802C 7F0B34FC E7A60038 */  swc1  $f6, 0x38($sp)
/* 0E8030 7F0B3500 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 0E8034 7F0B3504 C4860004 */  lwc1  $f6, 4($a0)
/* 0E8038 7F0B3508 460A4382 */  mul.s $f14, $f8, $f10
/* 0E803C 7F0B350C E7A60034 */  swc1  $f6, 0x34($sp)
/* 0E8040 7F0B3510 C48A0008 */  lwc1  $f10, 8($a0)
/* 0E8044 7F0B3514 46044402 */  mul.s $f16, $f8, $f4
/* 0E8048 7F0B3518 C6020000 */  lwc1  $f2, ($s0)
/* 0E804C 7F0B351C C7A80034 */  lwc1  $f8, 0x34($sp)
/* 0E8050 7F0B3520 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 0E8054 7F0B3524 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0E8058 7F0B3528 46024101 */  sub.s $f4, $f8, $f2
/* 0E805C 7F0B352C C60C0004 */  lwc1  $f12, 4($s0)
/* 0E8060 7F0B3530 460C5201 */  sub.s $f8, $f10, $f12
/* 0E8064 7F0B3534 460E2182 */  mul.s $f6, $f4, $f14
/* 0E8068 7F0B3538 00000000 */  nop   
/* 0E806C 7F0B353C 46088102 */  mul.s $f4, $f16, $f8
/* 0E8070 7F0B3540 44804000 */  mtc1  $zero, $f8
/* 0E8074 7F0B3544 46043280 */  add.s $f10, $f6, $f4
/* 0E8078 7F0B3548 4608503C */  c.lt.s $f10, $f8
/* 0E807C 7F0B354C 00000000 */  nop   
/* 0E8080 7F0B3550 45000003 */  bc1f  .L7F0B3560
/* 0E8084 7F0B3554 00000000 */   nop   
/* 0E8088 7F0B3558 46007387 */  neg.s $f14, $f14
/* 0E808C 7F0B355C 46008407 */  neg.s $f16, $f16
.L7F0B3560:
/* 0E8090 7F0B3560 460E1180 */  add.s $f6, $f2, $f14
/* 0E8094 7F0B3564 8FA300B8 */  lw    $v1, 0xb8($sp)
/* 0E8098 7F0B3568 46106100 */  add.s $f4, $f12, $f16
/* 0E809C 7F0B356C E7A60078 */  swc1  $f6, 0x78($sp)
/* 0E80A0 7F0B3570 E7A4007C */  swc1  $f4, 0x7c($sp)
/* 0E80A4 7F0B3574 C46A0000 */  lwc1  $f10, ($v1)
/* 0E80A8 7F0B3578 460E5200 */  add.s $f8, $f10, $f14
/* 0E80AC 7F0B357C E7A80070 */  swc1  $f8, 0x70($sp)
/* 0E80B0 7F0B3580 C4660004 */  lwc1  $f6, 4($v1)
/* 0E80B4 7F0B3584 46103100 */  add.s $f4, $f6, $f16
/* 0E80B8 7F0B3588 C7B0002C */  lwc1  $f16, 0x2c($sp)
/* 0E80BC 7F0B358C E7A40074 */  swc1  $f4, 0x74($sp)
/* 0E80C0 7F0B3590 C4EA0004 */  lwc1  $f10, 4($a3)
/* 0E80C4 7F0B3594 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0E80C8 7F0B3598 E7AA0048 */  swc1  $f10, 0x48($sp)
/* 0E80CC 7F0B359C C4E80000 */  lwc1  $f8, ($a3)
/* 0E80D0 7F0B35A0 C7A60048 */  lwc1  $f6, 0x48($sp)
/* 0E80D4 7F0B35A4 E7A8004C */  swc1  $f8, 0x4c($sp)
/* 0E80D8 7F0B35A8 46043282 */  mul.s $f10, $f6, $f4
/* 0E80DC 7F0B35AC C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 0E80E0 7F0B35B0 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 0E80E4 7F0B35B4 E7A40020 */  swc1  $f4, 0x20($sp)
/* 0E80E8 7F0B35B8 46044202 */  mul.s $f8, $f8, $f4
/* 0E80EC 7F0B35BC C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0E80F0 7F0B35C0 46085281 */  sub.s $f10, $f10, $f8
/* 0E80F4 7F0B35C4 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 0E80F8 7F0B35C8 E7AA0068 */  swc1  $f10, 0x68($sp)
/* 0E80FC 7F0B35CC E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0E8100 7F0B35D0 46064202 */  mul.s $f8, $f8, $f6
/* 0E8104 7F0B35D4 C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 0E8108 7F0B35D8 460A2102 */  mul.s $f4, $f4, $f10
/* 0E810C 7F0B35DC 46044381 */  sub.s $f14, $f8, $f4
/* 0E8110 7F0B35E0 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0E8114 7F0B35E4 46043182 */  mul.s $f6, $f6, $f4
/* 0E8118 7F0B35E8 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 0E811C 7F0B35EC E7AE006C */  swc1  $f14, 0x6c($sp)
/* 0E8120 7F0B35F0 460A2102 */  mul.s $f4, $f4, $f10
/* 0E8124 7F0B35F4 C7AA0024 */  lwc1  $f10, 0x24($sp)
/* 0E8128 7F0B35F8 46005306 */  mov.s $f12, $f10
/* 0E812C 7F0B35FC 46043481 */  sub.s $f18, $f6, $f4
/* 0E8130 7F0B3600 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 0E8134 7F0B3604 460A903C */  c.lt.s $f18, $f10
/* 0E8138 7F0B3608 00000000 */  nop   
/* 0E813C 7F0B360C 4502000A */  bc1fl .L7F0B3638
/* 0E8140 7F0B3610 460C9032 */   c.eq.s $f18, $f12
/* 0E8144 7F0B3614 46008407 */  neg.s $f16, $f16
/* 0E8148 7F0B3618 46003107 */  neg.s $f4, $f6
/* 0E814C 7F0B361C 46009306 */  mov.s $f12, $f18
/* 0E8150 7F0B3620 00608025 */  move  $s0, $v1
/* 0E8154 7F0B3624 46005486 */  mov.s $f18, $f10
/* 0E8158 7F0B3628 00401825 */  move  $v1, $v0
/* 0E815C 7F0B362C E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0E8160 7F0B3630 E7B00088 */  swc1  $f16, 0x88($sp)
/* 0E8164 7F0B3634 460C9032 */  c.eq.s $f18, $f12
.L7F0B3638:
/* 0E8168 7F0B3638 C7B00088 */  lwc1  $f16, 0x88($sp)
/* 0E816C 7F0B363C 02003025 */  move  $a2, $s0
/* 0E8170 7F0B3640 45020012 */  bc1fl .L7F0B368C
/* 0E8174 7F0B3644 460E903C */   c.lt.s $f18, $f14
/* 0E8178 7F0B3648 27A500A0 */  addiu $a1, $sp, 0xa0
/* 0E817C 7F0B364C AFA300B8 */  sw    $v1, 0xb8($sp)
/* 0E8180 7F0B3650 0FC2CCB6 */  jal   sub_GAME_7F0B32D8
/* 0E8184 7F0B3654 AFA400B0 */   sw    $a0, 0xb0($sp)
/* 0E8188 7F0B3658 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 0E818C 7F0B365C 27A500A0 */  addiu $a1, $sp, 0xa0
/* 0E8190 7F0B3660 8FA600B8 */  lw    $a2, 0xb8($sp)
/* 0E8194 7F0B3664 0FC2CCB6 */  jal   sub_GAME_7F0B32D8
/* 0E8198 7F0B3668 E7A00060 */   swc1  $f0, 0x60($sp)
/* 0E819C 7F0B366C C7A20060 */  lwc1  $f2, 0x60($sp)
/* 0E81A0 7F0B3670 4602003C */  c.lt.s $f0, $f2
/* 0E81A4 7F0B3674 00000000 */  nop   
/* 0E81A8 7F0B3678 45020038 */  bc1fl .L7F0B375C
/* 0E81AC 7F0B367C C7A800AC */   lwc1  $f8, 0xac($sp)
/* 0E81B0 7F0B3680 10000035 */  b     .L7F0B3758
/* 0E81B4 7F0B3684 46000086 */   mov.s $f2, $f0
/* 0E81B8 7F0B3688 460E903C */  c.lt.s $f18, $f14
.L7F0B368C:
/* 0E81BC 7F0B368C 00000000 */  nop   
/* 0E81C0 7F0B3690 45020007 */  bc1fl .L7F0B36B0
/* 0E81C4 7F0B3694 460C703C */   c.lt.s $f14, $f12
/* 0E81C8 7F0B3698 AFA300B8 */  sw    $v1, 0xb8($sp)
.L7F0B369C:
/* 0E81CC 7F0B369C 0FC2CCB6 */  jal   sub_GAME_7F0B32D8
/* 0E81D0 7F0B36A0 8FA600B8 */   lw    $a2, 0xb8($sp)
/* 0E81D4 7F0B36A4 1000002C */  b     .L7F0B3758
/* 0E81D8 7F0B36A8 46000086 */   mov.s $f2, $f0
/* 0E81DC 7F0B36AC 460C703C */  c.lt.s $f14, $f12
.L7F0B36B0:
/* 0E81E0 7F0B36B0 27A500A0 */  addiu $a1, $sp, 0xa0
/* 0E81E4 7F0B36B4 C7A80030 */  lwc1  $f8, 0x30($sp)
/* 0E81E8 7F0B36B8 45020006 */  bc1fl .L7F0B36D4
/* 0E81EC 7F0B36BC C60C0004 */   lwc1  $f12, 4($s0)
/* 0E81F0 7F0B36C0 0FC2CCB6 */  jal   sub_GAME_7F0B32D8
/* 0E81F4 7F0B36C4 02003025 */   move  $a2, $s0
/* 0E81F8 7F0B36C8 10000023 */  b     .L7F0B3758
/* 0E81FC 7F0B36CC 46000086 */   mov.s $f2, $f0
/* 0E8200 7F0B36D0 C60C0004 */  lwc1  $f12, 4($s0)
.L7F0B36D4:
/* 0E8204 7F0B36D4 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0E8208 7F0B36D8 C6020000 */  lwc1  $f2, ($s0)
/* 0E820C 7F0B36DC 460C4181 */  sub.s $f6, $f8, $f12
/* 0E8210 7F0B36E0 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0E8214 7F0B36E4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E8218 7F0B36E8 46065102 */  mul.s $f4, $f10, $f6
/* 0E821C 7F0B36EC C7A60034 */  lwc1  $f6, 0x34($sp)
/* 0E8220 7F0B36F0 46023281 */  sub.s $f10, $f6, $f2
/* 0E8224 7F0B36F4 46105282 */  mul.s $f10, $f10, $f16
/* 0E8228 7F0B36F8 46045000 */  add.s $f0, $f10, $f4
/* 0E822C 7F0B36FC C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0E8230 7F0B3700 460A3100 */  add.s $f4, $f6, $f10
/* 0E8234 7F0B3704 46022181 */  sub.s $f6, $f4, $f2
/* 0E8238 7F0B3708 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0E823C 7F0B370C 46103282 */  mul.s $f10, $f6, $f16
/* 0E8240 7F0B3710 46044180 */  add.s $f6, $f8, $f4
/* 0E8244 7F0B3714 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0E8248 7F0B3718 460C3201 */  sub.s $f8, $f6, $f12
/* 0E824C 7F0B371C 46082182 */  mul.s $f6, $f4, $f8
/* 0E8250 7F0B3720 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 0E8254 7F0B3724 46065380 */  add.s $f14, $f10, $f6
/* 0E8258 7F0B3728 460E0032 */  c.eq.s $f0, $f14
/* 0E825C 7F0B372C 00000000 */  nop   
/* 0E8260 7F0B3730 45020005 */  bc1fl .L7F0B3748
/* 0E8264 7F0B3734 46040201 */   sub.s $f8, $f0, $f4
/* 0E8268 7F0B3738 44810000 */  mtc1  $at, $f0
/* 0E826C 7F0B373C 1000001B */  b     .L7F0B37AC
/* 0E8270 7F0B3740 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0E8274 7F0B3744 46040201 */  sub.s $f8, $f0, $f4
.L7F0B3748:
/* 0E8278 7F0B3748 C7AA00AC */  lwc1  $f10, 0xac($sp)
/* 0E827C 7F0B374C 460E0101 */  sub.s $f4, $f0, $f14
/* 0E8280 7F0B3750 460A4182 */  mul.s $f6, $f8, $f10
/* 0E8284 7F0B3754 46043083 */  div.s $f2, $f6, $f4
.L7F0B3758:
/* 0E8288 7F0B3758 C7A800AC */  lwc1  $f8, 0xac($sp)
.L7F0B375C:
/* 0E828C 7F0B375C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0E8290 7F0B3760 4602403C */  c.lt.s $f8, $f2
/* 0E8294 7F0B3764 00000000 */  nop   
/* 0E8298 7F0B3768 45020005 */  bc1fl .L7F0B3780
/* 0E829C 7F0B376C 44805000 */   mtc1  $zero, $f10
/* 0E82A0 7F0B3770 44810000 */  mtc1  $at, $f0
/* 0E82A4 7F0B3774 1000000D */  b     .L7F0B37AC
/* 0E82A8 7F0B3778 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0E82AC 7F0B377C 44805000 */  mtc1  $zero, $f10
.L7F0B3780:
/* 0E82B0 7F0B3780 C7A60044 */  lwc1  $f6, 0x44($sp)
/* 0E82B4 7F0B3784 460A103C */  c.lt.s $f2, $f10
/* 0E82B8 7F0B3788 00000000 */  nop   
/* 0E82BC 7F0B378C 45000004 */  bc1f  .L7F0B37A0
/* 0E82C0 7F0B3790 00000000 */   nop   
/* 0E82C4 7F0B3794 44800000 */  mtc1  $zero, $f0
/* 0E82C8 7F0B3798 10000004 */  b     .L7F0B37AC
/* 0E82CC 7F0B379C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0B37A0:
/* 0E82D0 7F0B37A0 46061002 */  mul.s $f0, $f2, $f6
/* 0E82D4 7F0B37A4 00000000 */  nop   
/* 0E82D8 7F0B37A8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0B37AC:
/* 0E82DC 7F0B37AC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E82E0 7F0B37B0 27BD00B0 */  addiu $sp, $sp, 0xb0
/* 0E82E4 7F0B37B4 03E00008 */  jr    $ra
/* 0E82E8 7F0B37B8 00000000 */   nop   
)
#endif


