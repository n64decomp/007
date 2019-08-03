#include "ultra64.h"


// rodata





#ifdef NONMATCHING
float convert_angle_using_inverse(f32 vector1,f32 vector2)
{
  float fVar1;
  
  if ((float)vector1 == 0.00000000) {
    fVar1 = flt_80053700;
    if (0.00000000 <= (float)vector2) {
      fVar1 = 0.00000000;
    }
  }
  else {
    if ((float)vector2 == 0.00000000) {
      fVar1 = flt_80053704;
      if ((float)vector1 <= 0.00000000) {
        fVar1 = flt_80053708;
      }
    }
    else {
      fVar1 = sqrtf((float)vector1 * (float)vector1 + (float)vector2 * (float)vector2);
      if ((float)vector2 < (float)vector1) {
        fVar1 = proc_7F05ACB0((float)vector2 / fVar1);
        if ((float)vector1 < 0.00000000) {
          fVar1 = flt_8005370C - fVar1;
        }
      }
      else {
        fVar1 = proc_7F05ACB0((float)vector1 / fVar1);
        fVar1 = flt_80053710 - fVar1;
        if ((float)vector2 < 0.00000000) {
          fVar1 = flt_80053714 - fVar1;
        }
        if (fVar1 < 0.00000000) {
          fVar1 = fVar1 + flt_80053718;
        }
      }
    }
  }
  return fVar1;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053700
.word 0x40490fdb /*3.1415927*/
glabel D_80053704
.word 0x3fc90fdb /*1.5707964*/
glabel D_80053708
.word 0x4096cbe4 /*4.712389*/
glabel D_8005370C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053710
.word 0x3fc90fdb /*1.5707964*/
glabel D_80053714
.word 0x40490fdb /*3.1415927*/
glabel D_80053718
.word 0x40c90fdb /*6.2831855*/
.text
glabel convert_angle_using_inverse
/* 08F560 7F05AA30 44808000 */  mtc1  $zero, $f16
/* 08F564 7F05AA34 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08F568 7F05AA38 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 08F56C 7F05AA3C 46106032 */  c.eq.s $f12, $f16
/* 08F570 7F05AA40 46006506 */  mov.s $f20, $f12
/* 08F574 7F05AA44 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08F578 7F05AA48 4502000A */  bc1fl .L7F05AA74
/* 08F57C 7F05AA4C 46107032 */   c.eq.s $f14, $f16
/* 08F580 7F05AA50 460E803E */  c.le.s $f16, $f14
/* 08F584 7F05AA54 3C018005 */  lui   $at, %hi(D_80053700) # $at, 0x8005
/* 08F588 7F05AA58 45000003 */  bc1f  .L7F05AA68
/* 08F58C 7F05AA5C 00000000 */   nop   
/* 08F590 7F05AA60 1000003B */  b     .L7F05AB50
/* 08F594 7F05AA64 46008086 */   mov.s $f2, $f16
.L7F05AA68:
/* 08F598 7F05AA68 10000039 */  b     .L7F05AB50
/* 08F59C 7F05AA6C C4223700 */   lwc1  $f2, %lo(D_80053700)($at)
/* 08F5A0 7F05AA70 46107032 */  c.eq.s $f14, $f16
.L7F05AA74:
/* 08F5A4 7F05AA74 00000000 */  nop   
/* 08F5A8 7F05AA78 4500000A */  bc1f  .L7F05AAA4
/* 08F5AC 7F05AA7C 00000000 */   nop   
/* 08F5B0 7F05AA80 4614803C */  c.lt.s $f16, $f20
/* 08F5B4 7F05AA84 3C018005 */  lui   $at, %hi(D_80053708)
/* 08F5B8 7F05AA88 45000004 */  bc1f  .L7F05AA9C
/* 08F5BC 7F05AA8C 00000000 */   nop   
/* 08F5C0 7F05AA90 3C018005 */  lui   $at, %hi(D_80053704) # $at, 0x8005
/* 08F5C4 7F05AA94 1000002E */  b     .L7F05AB50
/* 08F5C8 7F05AA98 C4223704 */   lwc1  $f2, %lo(D_80053704)($at)
.L7F05AA9C:
/* 08F5CC 7F05AA9C 1000002C */  b     .L7F05AB50
/* 08F5D0 7F05AAA0 C4223708 */   lwc1  $f2, %lo(D_80053708)($at)
.L7F05AAA4:
/* 08F5D4 7F05AAA4 4614A102 */  mul.s $f4, $f20, $f20
/* 08F5D8 7F05AAA8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 08F5DC 7F05AAAC 460E7182 */  mul.s $f6, $f14, $f14
/* 08F5E0 7F05AAB0 0C007DF8 */  jal   sqrtf
/* 08F5E4 7F05AAB4 46062300 */   add.s $f12, $f4, $f6
/* 08F5E8 7F05AAB8 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 08F5EC 7F05AABC 46000086 */  mov.s $f2, $f0
/* 08F5F0 7F05AAC0 4614703C */  c.lt.s $f14, $f20
/* 08F5F4 7F05AAC4 00000000 */  nop   
/* 08F5F8 7F05AAC8 4502000E */  bc1fl .L7F05AB04
/* 08F5FC 7F05AACC 4602A303 */   div.s $f12, $f20, $f2
/* 08F600 7F05AAD0 0FC16B2C */  jal   sub_GAME_7F05ACB0
/* 08F604 7F05AAD4 46007303 */   div.s $f12, $f14, $f0
/* 08F608 7F05AAD8 44808000 */  mtc1  $zero, $f16
/* 08F60C 7F05AADC 46000086 */  mov.s $f2, $f0
/* 08F610 7F05AAE0 3C018005 */  lui   $at, %hi(D_8005370C) # $at, 0x8005
/* 08F614 7F05AAE4 4610A03C */  c.lt.s $f20, $f16
/* 08F618 7F05AAE8 00000000 */  nop   
/* 08F61C 7F05AAEC 45020019 */  bc1fl .L7F05AB54
/* 08F620 7F05AAF0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 08F624 7F05AAF4 C428370C */  lwc1  $f8, %lo(D_8005370C)($at)
/* 08F628 7F05AAF8 10000015 */  b     .L7F05AB50
/* 08F62C 7F05AAFC 46004081 */   sub.s $f2, $f8, $f0
/* 08F630 7F05AB00 4602A303 */  div.s $f12, $f20, $f2
.L7F05AB04:
/* 08F634 7F05AB04 0FC16B2C */  jal   sub_GAME_7F05ACB0
/* 08F638 7F05AB08 E7AE0024 */   swc1  $f14, 0x24($sp)
/* 08F63C 7F05AB0C C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 08F640 7F05AB10 44808000 */  mtc1  $zero, $f16
/* 08F644 7F05AB14 3C018005 */  lui   $at, %hi(D_80053710) # $at, 0x8005
/* 08F648 7F05AB18 C42A3710 */  lwc1  $f10, %lo(D_80053710)($at)
/* 08F64C 7F05AB1C 4610703C */  c.lt.s $f14, $f16
/* 08F650 7F05AB20 3C018005 */  lui   $at, %hi(D_80053714) # $at, 0x8005
/* 08F654 7F05AB24 46005301 */  sub.s $f12, $f10, $f0
/* 08F658 7F05AB28 45000003 */  bc1f  .L7F05AB38
/* 08F65C 7F05AB2C 46006086 */   mov.s $f2, $f12
/* 08F660 7F05AB30 C4323714 */  lwc1  $f18, %lo(D_80053714)($at)
/* 08F664 7F05AB34 460C9081 */  sub.s $f2, $f18, $f12
.L7F05AB38:
/* 08F668 7F05AB38 4610103C */  c.lt.s $f2, $f16
/* 08F66C 7F05AB3C 3C018005 */  lui   $at, %hi(D_80053718) # $at, 0x8005
/* 08F670 7F05AB40 45020004 */  bc1fl .L7F05AB54
/* 08F674 7F05AB44 8FBF001C */   lw    $ra, 0x1c($sp)
/* 08F678 7F05AB48 C4243718 */  lwc1  $f4, %lo(D_80053718)($at)
/* 08F67C 7F05AB4C 46041080 */  add.s $f2, $f2, $f4
.L7F05AB50:
/* 08F680 7F05AB50 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F05AB54:
/* 08F684 7F05AB54 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 08F688 7F05AB58 27BD0020 */  addiu $sp, $sp, 0x20
/* 08F68C 7F05AB5C 03E00008 */  jr    $ra
/* 08F690 7F05AB60 46001006 */   mov.s $f0, $f2
)
#endif




