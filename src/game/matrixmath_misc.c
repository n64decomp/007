#include <ultra64.h>
#include "matrixmath.h"

/**
 * result = x vector plus ((y - x vector) * scaler).
 */
void sub_GAME_7F05AE00(vec3d *x, vec3d *y, f32 scaler, vec3d *result)
{
    result->x = ((y->x - x->x) * scaler) + x->x;
    result->y = ((y->y - x->y) * scaler) + x->y;
    result->z = ((y->z - x->z) * scaler) + x->z;
}

/**
 * Unused.
 */ 
f32 sub_GAME_7F05AE50(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 cube;
    f32 square;
    f32 total;
    f32 t2;

    square = arg4 * arg4;
    cube   = square * arg4;

    t2     = square - ((arg4 + cube) * 0.5f);
    total  = arg0 * t2;

    t2     = ((1.5f * cube) - (2.5f * square)) + 1.0f;
    total += arg1 * t2;

    t2     = (-1.5f * cube) + (2.0f * square) + (0.5f * arg4);
    total += arg2 * t2;

    t2     = (cube - square) * 0.5f;
    total += arg3 * t2;

    return total;
}

void sub_GAME_7F05AEFC(coord3d *arg0, coord3d *arg1, coord3d *arg2, coord3d *arg3, f32 arg4, coord3d *arg5)
{
    f32 stack;
    f32 mult0;
    f32 mult1;
    f32 mult2;
    f32 mult3;

    f32 squared = arg4 * arg4;
    f32 cubed = arg4 * arg4 * arg4;

    mult0 = squared - 0.5f * (arg4 + cubed);
    mult1 = 1.5f * cubed - 2.5f * squared + 1.0f;
    mult2 = -1.5f * cubed + 2.0f * squared + 0.5f * arg4;
    mult3 = 0.5f * (cubed - squared);

    arg5->x = mult0 * arg0->f[0] + mult1 * arg1->f[0] + mult2 * arg2->f[0] + mult3 * arg3->f[0];
    arg5->y = mult0 * arg0->f[1] + mult1 * arg1->f[1] + mult2 * arg2->f[1] + mult3 * arg3->f[1];
    arg5->z = mult0 * arg0->f[2] + mult1 * arg1->f[2] + mult2 * arg2->f[2] + mult3 * arg3->f[2];
}

/**
 * Following is cleaned up mips_to_c output.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: fail
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * https://decomp.me/scratch/EHA1A 74.55 %
 */
#ifdef NONMATCHING
void sub_GAME_7F05B024(coord3d *arg0, coord3d *arg1, coord3d *arg2, coord3d *arg3, f32 arg4, f32 arg5, coord3d *result)
{
    f32 square;
    f32 cube;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f6;
    f32 temp_f8;

    square = arg4 * arg4;
    cube = square * arg4;
    temp_f6 = (cube - square) * arg5;
    temp_f16 = ((2.0f * square) - (arg4 + cube)) * arg5;
    temp_f18 = ((2.0f - arg5) * cube) + (square * (arg5 - 3.0f)) + 1.0f;
    temp_f8 = ((arg5 - 2.0f) * cube) + (square * (3.0f - (2.0f * arg5))) + (arg4 * arg5);

    result->f[0] = temp_f16 * arg0->f[0] + temp_f18 * arg1->f[0] + temp_f8 * arg2->f[0] + temp_f6 * arg3->f[0];
    result->f[1] = temp_f16 * arg0->f[1] + temp_f18 * arg1->f[1] + temp_f8 * arg2->f[1] + temp_f6 * arg3->f[1];
    result->f[2] = temp_f16 * arg0->f[2] + temp_f18 * arg1->f[2] + temp_f8 * arg2->f[2] + temp_f6 * arg3->f[2];
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05B024
/* 08FB54 7F05B024 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08FB58 7F05B028 C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 08FB5C 7F05B02C C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 08FB60 7F05B030 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 08FB64 7F05B034 460C6002 */  mul.s $f0, $f12, $f12
/* 08FB68 7F05B038 8FAE0040 */  lw    $t6, 0x40($sp)
/* 08FB6C 7F05B03C 460C0082 */  mul.s $f2, $f0, $f12
/* 08FB70 7F05B040 46000200 */  add.s $f8, $f0, $f0
/* 08FB74 7F05B044 46001101 */  sub.s $f4, $f2, $f0
/* 08FB78 7F05B048 46026280 */  add.s $f10, $f12, $f2
/* 08FB7C 7F05B04C 460E2182 */  mul.s $f6, $f4, $f14
/* 08FB80 7F05B050 460A4101 */  sub.s $f4, $f8, $f10
/* 08FB84 7F05B054 44814000 */  mtc1  $at, $f8
/* 08FB88 7F05B058 3C014040 */  li    $at, 0x40400000 # 3.000000
/* 08FB8C 7F05B05C E7A60000 */  swc1  $f6, ($sp)
/* 08FB90 7F05B060 460E4281 */  sub.s $f10, $f8, $f14
/* 08FB94 7F05B064 460E2402 */  mul.s $f16, $f4, $f14
/* 08FB98 7F05B068 44814000 */  mtc1  $at, $f8
/* 08FB9C 7F05B06C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08FBA0 7F05B070 46025102 */  mul.s $f4, $f10, $f2
/* 08FBA4 7F05B074 46087281 */  sub.s $f10, $f14, $f8
/* 08FBA8 7F05B078 460A0202 */  mul.s $f8, $f0, $f10
/* 08FBAC 7F05B07C 46082280 */  add.s $f10, $f4, $f8
/* 08FBB0 7F05B080 44812000 */  mtc1  $at, $f4
/* 08FBB4 7F05B084 3C014040 */  li    $at, 0x40400000 # 3.000000
/* 08FBB8 7F05B088 44814000 */  mtc1  $at, $f8
/* 08FBBC 7F05B08C 46045480 */  add.s $f18, $f10, $f4
/* 08FBC0 7F05B090 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 08FBC4 7F05B094 460E7280 */  add.s $f10, $f14, $f14
/* 08FBC8 7F05B098 460A4101 */  sub.s $f4, $f8, $f10
/* 08FBCC 7F05B09C 44815000 */  mtc1  $at, $f10
/* 08FBD0 7F05B0A0 46040202 */  mul.s $f8, $f0, $f4
/* 08FBD4 7F05B0A4 460A7101 */  sub.s $f4, $f14, $f10
/* 08FBD8 7F05B0A8 46022282 */  mul.s $f10, $f4, $f2
/* 08FBDC 7F05B0AC 46085100 */  add.s $f4, $f10, $f8
/* 08FBE0 7F05B0B0 460E6282 */  mul.s $f10, $f12, $f14
/* 08FBE4 7F05B0B4 460A2200 */  add.s $f8, $f4, $f10
/* 08FBE8 7F05B0B8 E7A80008 */  swc1  $f8, 8($sp)
/* 08FBEC 7F05B0BC C4840000 */  lwc1  $f4, ($a0)
/* 08FBF0 7F05B0C0 46048282 */  mul.s $f10, $f16, $f4
/* 08FBF4 7F05B0C4 C4A40000 */  lwc1  $f4, ($a1)
/* 08FBF8 7F05B0C8 46049102 */  mul.s $f4, $f18, $f4
/* 08FBFC 7F05B0CC 46045280 */  add.s $f10, $f10, $f4
/* 08FC00 7F05B0D0 C4C40000 */  lwc1  $f4, ($a2)
/* 08FC04 7F05B0D4 46044102 */  mul.s $f4, $f8, $f4
/* 08FC08 7F05B0D8 46045280 */  add.s $f10, $f10, $f4
/* 08FC0C 7F05B0DC C4E40000 */  lwc1  $f4, ($a3)
/* 08FC10 7F05B0E0 46062102 */  mul.s $f4, $f4, $f6
/* 08FC14 7F05B0E4 460A2100 */  add.s $f4, $f4, $f10
/* 08FC18 7F05B0E8 E5C40000 */  swc1  $f4, ($t6)
/* 08FC1C 7F05B0EC C48A0004 */  lwc1  $f10, 4($a0)
/* 08FC20 7F05B0F0 460A8102 */  mul.s $f4, $f16, $f10
/* 08FC24 7F05B0F4 C4AA0004 */  lwc1  $f10, 4($a1)
/* 08FC28 7F05B0F8 460A9282 */  mul.s $f10, $f18, $f10
/* 08FC2C 7F05B0FC 460A2100 */  add.s $f4, $f4, $f10
/* 08FC30 7F05B100 C4CA0004 */  lwc1  $f10, 4($a2)
/* 08FC34 7F05B104 460A4282 */  mul.s $f10, $f8, $f10
/* 08FC38 7F05B108 460A2100 */  add.s $f4, $f4, $f10
/* 08FC3C 7F05B10C C4EA0004 */  lwc1  $f10, 4($a3)
/* 08FC40 7F05B110 46065282 */  mul.s $f10, $f10, $f6
/* 08FC44 7F05B114 46045280 */  add.s $f10, $f10, $f4
/* 08FC48 7F05B118 E5CA0004 */  swc1  $f10, 4($t6)
/* 08FC4C 7F05B11C C4840008 */  lwc1  $f4, 8($a0)
/* 08FC50 7F05B120 46048282 */  mul.s $f10, $f16, $f4
/* 08FC54 7F05B124 C4A40008 */  lwc1  $f4, 8($a1)
/* 08FC58 7F05B128 46049102 */  mul.s $f4, $f18, $f4
/* 08FC5C 7F05B12C 46045280 */  add.s $f10, $f10, $f4
/* 08FC60 7F05B130 C4C40008 */  lwc1  $f4, 8($a2)
/* 08FC64 7F05B134 46044202 */  mul.s $f8, $f8, $f4
/* 08FC68 7F05B138 46085100 */  add.s $f4, $f10, $f8
/* 08FC6C 7F05B13C C4EA0008 */  lwc1  $f10, 8($a3)
/* 08FC70 7F05B140 27BD0028 */  addiu $sp, $sp, 0x28
/* 08FC74 7F05B144 46065202 */  mul.s $f8, $f10, $f6
/* 08FC78 7F05B148 46044280 */  add.s $f10, $f8, $f4
/* 08FC7C 7F05B14C 03E00008 */  jr    $ra
/* 08FC80 7F05B150 E5CA0008 */   swc1  $f10, 8($t6)
)
#endif

/**
 * Unused.
 */ 
f32 sub_GAME_7F05B154(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    /*
    Quick substition (so this may be wrong), but let x=arg4. Then
    return
    x^3 * (arg3 + arg2 - 2*arg1 + 2*arg0) + x^2 * (-arg3 - 2*arg2 + 3*arg1 - 3*arg0) + x^1 * (arg2) + x^0 * (arg0)
    */
    f32 cube;
    f32 temp_f18;
    f32 square;

    square = arg4 * arg4;
    cube = square * arg4;
    temp_f18 = ((2.0f * cube) - (3.0f * square)) + 1.0f;
    return (arg0 * temp_f18) + (arg1 * (1.0f - temp_f18)) + (arg2 * ((cube - (2.0f * square)) + arg4)) + (arg3 * (cube - square));
}

