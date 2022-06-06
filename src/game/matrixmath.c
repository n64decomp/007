#include "matrixmath.h"
#include "math_atan2f.h"
#include <PR/gu.h>
#include <math.h>

/* Avoid Gimble Lock? */
#define EPSILON FLT_EPSILON * 16

// bss
//CODE.bss:80075DA0
f32 flt_CODE_bss_80075DA0;


// data
//D:80032310
f32 D_80032310[2] = {M_U16_MAX_VALUE_F, M_U16_MAX_VALUE_F};



//#ifdef VERSION_EU

#ifdef VERSION_EU
#ifdef NONMATCHING
void matrix_4x4_copy_homogeneous_eu(Mtxf *src,Mtxf *dst)
{

}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_copy_homogeneous_eu
/* 08ACC0 7F0582D0 00001025 */  move  $v0, $zero
/* 08ACC4 7F0582D4 00A03025 */  move  $a2, $a1
/* 08ACC8 7F0582D8 00803825 */  move  $a3, $a0
/* 08ACCC 7F0582DC 24080003 */  li    $t0, 3
.L7F0582E0:
/* 08ACD0 7F0582E0 00001825 */  move  $v1, $zero
/* 08ACD4 7F0582E4 00C02025 */  move  $a0, $a2
/* 08ACD8 7F0582E8 00E02825 */  move  $a1, $a3
.L7F0582EC:
/* 08ACDC 7F0582EC C4A40000 */  lwc1  $f4, ($a1)
/* 08ACE0 7F0582F0 24630001 */  addiu $v1, $v1, 1
/* 08ACE4 7F0582F4 24840004 */  addiu $a0, $a0, 4
/* 08ACE8 7F0582F8 24A50004 */  addiu $a1, $a1, 4
/* 08ACEC 7F0582FC 1468FFFB */  bne   $v1, $t0, .L7F0582EC
/* 08ACF0 7F058300 E484FFFC */   swc1  $f4, -4($a0)
/* 08ACF4 7F058304 24420001 */  addiu $v0, $v0, 1
/* 08ACF8 7F058308 24C6000C */  addiu $a2, $a2, 0xc
/* 08ACFC 7F05830C 1448FFF4 */  bne   $v0, $t0, .L7F0582E0
/* 08AD00 7F058310 24E7000C */   addiu $a3, $a3, 0xc
/* 08AD04 7F058314 03E00008 */  jr    $ra
/* 08AD08 7F058318 00000000 */   nop   
)
#endif
#endif


#ifdef VERSION_EU
#ifdef NONMATCHING
void matrix_4x4_multiply_homogeneous_in_place_eu (Mtxf * src, Mtxf * dst)
{

}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_multiply_homogeneous_in_place_eu
/* 08AD0C 7F05831C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 08AD10 7F058320 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08AD14 7F058324 AFA50044 */  sw    $a1, 0x44($sp)
/* 08AD18 7F058328 0FC160D3 */  jal   matrix_4x4_multiply_homogeneous_eu
/* 08AD1C 7F05832C 27A6001C */   addiu $a2, $sp, 0x1c
/* 08AD20 7F058330 27A4001C */  addiu $a0, $sp, 0x1c
/* 08AD24 7F058334 0FC160B4 */  jal   matrix_4x4_copy_homogeneous_eu
/* 08AD28 7F058338 8FA50044 */   lw    $a1, 0x44($sp)
/* 08AD2C 7F05833C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08AD30 7F058340 27BD0040 */  addiu $sp, $sp, 0x40
/* 08AD34 7F058344 03E00008 */  jr    $ra
/* 08AD38 7F058348 00000000 */   nop   
)
#endif
#endif


#ifdef VERSION_EU
#ifdef NONMATCHING
void matrix_4x4_multiply_homogeneous_eu (Mtxf * lhs, Mtxf * rhs, Mtxf * result)
{

}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_multiply_homogeneous_eu
/* 08AD3C 7F05834C 00001825 */  move  $v1, $zero
/* 08AD40 7F058350 00804025 */  move  $t0, $a0
/* 08AD44 7F058354 240A000C */  li    $t2, 12
/* 08AD48 7F058358 24090003 */  li    $t1, 3
.L7F05835C:
/* 08AD4C 7F05835C 00001025 */  move  $v0, $zero
/* 08AD50 7F058360 00C32021 */  addu  $a0, $a2, $v1
/* 08AD54 7F058364 00A03825 */  move  $a3, $a1
.L7F058368:
/* 08AD58 7F058368 C5120000 */  lwc1  $f18, ($t0)
/* 08AD5C 7F05836C C4F00000 */  lwc1  $f16, ($a3)
/* 08AD60 7F058370 C50E000C */  lwc1  $f14, 0xc($t0)
/* 08AD64 7F058374 C4EC0004 */  lwc1  $f12, 4($a3)
/* 08AD68 7F058378 46109402 */  mul.s $f16, $f18, $f16
/* 08AD6C 7F05837C C4F20008 */  lwc1  $f18, 8($a3)
/* 08AD70 7F058380 C50A0018 */  lwc1  $f10, 0x18($t0)
/* 08AD74 7F058384 460C7302 */  mul.s $f12, $f14, $f12
/* 08AD78 7F058388 24420001 */  addiu $v0, $v0, 1
/* 08AD7C 7F05838C 2484000C */  addiu $a0, $a0, 0xc
/* 08AD80 7F058390 460A9282 */  mul.s $f10, $f18, $f10
/* 08AD84 7F058394 24E7000C */  addiu $a3, $a3, 0xc
/* 08AD88 7F058398 460C8300 */  add.s $f12, $f16, $f12
/* 08AD8C 7F05839C 460C5300 */  add.s $f12, $f10, $f12
/* 08AD90 7F0583A0 1449FFF1 */  bne   $v0, $t1, .L7F058368
/* 08AD94 7F0583A4 E48CFFF4 */   swc1  $f12, -0xc($a0)
/* 08AD98 7F0583A8 24630004 */  addiu $v1, $v1, 4
/* 08AD9C 7F0583AC 146AFFEB */  bne   $v1, $t2, .L7F05835C
/* 08ADA0 7F0583B0 25080004 */   addiu $t0, $t0, 4
/* 08ADA4 7F0583B4 03E00008 */  jr    $ra
/* 08ADA8 7F0583B8 00000000 */   nop   
)
#endif
#endif


#ifdef VERSION_EU
#ifdef NONMATCHING
void matrix_4x4_copy_eu (Mtxf * src, Mtxf * dst)
{

}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_copy_eu
/* 08ADAC 7F0583BC 00001025 */  move  $v0, $zero
/* 08ADB0 7F0583C0 00A03025 */  move  $a2, $a1
/* 08ADB4 7F0583C4 00803825 */  move  $a3, $a0
/* 08ADB8 7F0583C8 24090003 */  li    $t1, 3
.L7F0583CC:
/* 08ADBC 7F0583CC 00001825 */  move  $v1, $zero
/* 08ADC0 7F0583D0 00C02025 */  move  $a0, $a2
/* 08ADC4 7F0583D4 00E04025 */  move  $t0, $a3
.L7F0583D8:
/* 08ADC8 7F0583D8 C5040000 */  lwc1  $f4, ($t0)
/* 08ADCC 7F0583DC 24630001 */  addiu $v1, $v1, 1
/* 08ADD0 7F0583E0 24840004 */  addiu $a0, $a0, 4
/* 08ADD4 7F0583E4 25080004 */  addiu $t0, $t0, 4
/* 08ADD8 7F0583E8 1469FFFB */  bne   $v1, $t1, .L7F0583D8
/* 08ADDC 7F0583EC E484FFFC */   swc1  $f4, -4($a0)
/* 08ADE0 7F0583F0 24420001 */  addiu $v0, $v0, 1
/* 08ADE4 7F0583F4 24C60010 */  addiu $a2, $a2, 0x10
/* 08ADE8 7F0583F8 1449FFF4 */  bne   $v0, $t1, .L7F0583CC
/* 08ADEC 7F0583FC 24E7000C */   addiu $a3, $a3, 0xc
/* 08ADF0 7F058400 44800000 */  mtc1  $zero, $f0
/* 08ADF4 7F058404 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08ADF8 7F058408 44813000 */  mtc1  $at, $f6
/* 08ADFC 7F05840C E4A0000C */  swc1  $f0, 0xc($a1)
/* 08AE00 7F058410 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 08AE04 7F058414 E4A0002C */  swc1  $f0, 0x2c($a1)
/* 08AE08 7F058418 E4A00030 */  swc1  $f0, 0x30($a1)
/* 08AE0C 7F05841C E4A00034 */  swc1  $f0, 0x34($a1)
/* 08AE10 7F058420 E4A00038 */  swc1  $f0, 0x38($a1)
/* 08AE14 7F058424 03E00008 */  jr    $ra
/* 08AE18 7F058428 E4A6003C */   swc1  $f6, 0x3c($a1)
)
#endif
#endif

#ifdef VERSION_EU
#ifdef NONMATCHING
void matrix_7f05842c_eu (Mtxf * src, Mtxf * dst)
{
    
}
#else
GLOBAL_ASM(
.text
glabel matrix_7f05842c_eu
/* 08AE1C 7F05842C 00001025 */  move  $v0, $zero
/* 08AE20 7F058430 00A03025 */  move  $a2, $a1
/* 08AE24 7F058434 00803825 */  move  $a3, $a0
/* 08AE28 7F058438 24080003 */  li    $t0, 3
.L7F05843C:
/* 08AE2C 7F05843C 00001825 */  move  $v1, $zero
/* 08AE30 7F058440 00C02025 */  move  $a0, $a2
/* 08AE34 7F058444 00E02825 */  move  $a1, $a3
.L7F058448:
/* 08AE38 7F058448 C4A40000 */  lwc1  $f4, ($a1)
/* 08AE3C 7F05844C 24630001 */  addiu $v1, $v1, 1
/* 08AE40 7F058450 24840004 */  addiu $a0, $a0, 4
/* 08AE44 7F058454 24A50004 */  addiu $a1, $a1, 4
/* 08AE48 7F058458 1468FFFB */  bne   $v1, $t0, .L7F058448
/* 08AE4C 7F05845C E484FFFC */   swc1  $f4, -4($a0)
/* 08AE50 7F058460 24420001 */  addiu $v0, $v0, 1
/* 08AE54 7F058464 24C6000C */  addiu $a2, $a2, 0xc
/* 08AE58 7F058468 1448FFF4 */  bne   $v0, $t0, .L7F05843C
/* 08AE5C 7F05846C 24E70010 */   addiu $a3, $a3, 0x10
/* 08AE60 7F058470 03E00008 */  jr    $ra
/* 08AE64 7F058474 00000000 */   nop  
)
#endif
#endif


//nexthere

//#endif

void matrix_4x4_set_identity(Mtxf *matrix)
{
    matrix->m[0][0] = 1.0f;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = 1.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
}

void matrix_4x4_copy(Mtxf *src, Mtxf *dst)
{
    s32 i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            dst->m[i][j] = src->m[i][j];
        }
    }
}

void matrix_4x4_multiply_in_place(Mtxf *lhs, Mtxf *rhs)
{
    Mtxf result;
    matrix_4x4_multiply(lhs, rhs, &result);
    matrix_4x4_copy(&result, rhs);
}

void matrix_4x4_multiply_homogeneous_in_place(Mtxf *lhs, Mtxf *rhs)
{
    Mtxf result;
    matrix_4x4_multiply_homogeneous(lhs, rhs, &result);
    matrix_4x4_copy(&result, rhs);
}

void matrix_4x4_multiply(Mtxf *lhs, Mtxf *rhs, Mtxf *result)
{
    s32 i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result->m[j][i] = lhs->m[0][i] * rhs->m[j][0] + lhs->m[1][i] * rhs->m[j][1] + lhs->m[2][i] * rhs->m[j][2] + lhs->m[3][i] * rhs->m[j][3];
        }
    }
}

s32 matrix_4x4_multiply_homogeneous(Mtxf *lhs, Mtxf *rhs, Mtxf *result)
{
    s32 i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result->m[j][i] = (lhs->m[0][i] * rhs->m[j][0]) + (lhs->m[1][i] * rhs->m[j][1]) + (lhs->m[2][i] * rhs->m[j][2]);
            if (j == 3)
            {
                result->m[j][i] += lhs->m[3][i];
            }
        }
    }

    result->m[0][3] = 0.0f;
    result->m[1][3] = 0.0f;
    result->m[2][3] = 0.0f;
    result->m[3][3] = 1.0f;
}

void matrix_4x4_7F058274(Mtxf *arg0, Mtxf *arg1, Mtxf *arg2)
{
    arg2->m[0][0] = (arg0->m[0][0] * arg1->m[0][0]);
    arg2->m[1][0] = (arg0->m[0][0] * arg1->m[1][0]);
    arg2->m[2][0] = (arg0->m[0][0] * arg1->m[2][0]);
    arg2->m[3][0] = (arg0->m[0][0] * arg1->m[3][0]);
    arg2->m[0][1] = (arg0->m[1][1] * arg1->m[0][1]);
    arg2->m[1][1] = (arg0->m[1][1] * arg1->m[1][1]);
    arg2->m[2][1] = (arg0->m[1][1] * arg1->m[2][1]);
    arg2->m[3][1] = (arg0->m[1][1] * arg1->m[3][1]);
    arg2->m[0][2] = (arg0->m[2][2] * arg1->m[0][2]);
    arg2->m[1][2] = (arg0->m[2][2] * arg1->m[1][2]);
    arg2->m[2][2] = (arg0->m[2][2] * arg1->m[2][2]);
    arg2->m[3][2] = (arg0->m[2][2] * arg1->m[3][2]) + arg0->m[3][2];
    arg2->m[0][3] = (arg0->m[2][3] * arg1->m[0][2]);
    arg2->m[1][3] = (arg0->m[2][3] * arg1->m[1][2]);
    arg2->m[2][3] = (arg0->m[2][3] * arg1->m[2][2]);
    arg2->m[3][3] = (arg0->m[2][3] * arg1->m[3][2]);
}

void matrix_4x4_rotate_vector(Mtxf *matrix, vec3 vector, vec3 result)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        result[i] = matrix->m[0][i] * vector[0] + matrix->m[1][i] * vector[1] + matrix->m[2][i] * vector[2];
    }
}

void matrix_4x4_rotate_vector_in_place(Mtxf *matrix, vec3 vector)
{
    vec3 result;
    matrix_4x4_rotate_vector(matrix, vector, result);
    vector[0] = result[0];
    vector[1] = result[1];
    vector[2] = result[2];
}

void matrix_4x4_transform_vector(Mtxf *matrix, vec3 vector, vec3 result)
{
    matrix_4x4_rotate_vector(matrix, vector, result);
    result[0] += matrix->m[3][0];
    result[1] += matrix->m[3][1];
    result[2] += matrix->m[3][2];
}

void matrix_4x4_transform_vector_in_place(Mtxf *matrix, vec3 vector)
{
    matrix_4x4_rotate_vector_in_place(matrix, vector);
    vector[0] += matrix->m[3][0];
    vector[1] += matrix->m[3][1];
    vector[2] += matrix->m[3][2];
}

void matrix_4x4_set_position_and_rotation_around_y(f32 *position, f32 angle, Mtxf *matrix)
{
    f32 cosine      = cosf(angle);
    f32 sine        = sinf(angle);
    matrix->m[0][0] = cosine;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = -sine;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = sine;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = cosine;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = position[0];
    matrix->m[3][1] = position[1];
    matrix->m[3][2] = position[2];
    matrix->m[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_x(f32 angle, Mtxf *matrix)
{
    f32 cosine      = cosf(angle);
    f32 sine        = sinf(angle);
    matrix->m[0][0] = 1.0f;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = cosine;
    matrix->m[1][2] = sine;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = -sine;
    matrix->m[2][2] = cosine;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_y(f32 angle, Mtxf *matrix)
{
    f32 cosine      = cosf(angle);
    f32 sine        = sinf(angle);
    matrix->m[0][0] = cosine;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = -sine;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = sine;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = cosine;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_z(f32 angle, Mtxf *matrix)
{
    f32 cosine      = cosf(angle);
    f32 sine        = sinf(angle);
    matrix->m[0][0] = cosine;
    matrix->m[0][1] = sine;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = -sine;
    matrix->m[1][1] = cosine;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = 1.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_xyz(vec3 angles, Mtxf *matrix)
{
    f32 cos_x       = cosf(angles[0]);
    f32 sin_x       = sinf(angles[0]);
    f32 cos_y       = cosf(angles[1]);
    f32 sin_y       = sinf(angles[1]);
    f32 cos_z       = cosf(angles[2]);
    f32 sin_z       = sinf(angles[2]);
    f32 sin_x_sin_z = sin_x * sin_z;
    f32 cos_x_sin_z = cos_x * sin_z;
    f32 sin_x_cos_z = sin_x * cos_z;
    f32 cos_x_cos_z = cos_x * cos_z;
    matrix->m[0][0] = (cos_y * cos_z);
    matrix->m[0][1] = (cos_y * sin_z);
    matrix->m[0][2] = -sin_y;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = ((sin_x_cos_z * sin_y) - cos_x_sin_z);
    matrix->m[1][1] = ((sin_x_sin_z * sin_y) + cos_x_cos_z);
    matrix->m[1][2] = sin_x * cos_y;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = ((cos_x_cos_z * sin_y) + sin_x_sin_z);
    matrix->m[2][1] = ((cos_x_sin_z * sin_y) - sin_x_cos_z);
    matrix->m[2][2] = cos_x * cos_y;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
}

// https://stackoverflow.com/a/15029416
void matrix_4x4_get_rotation_around_xyz(Mtxf *matrix, vec3 angles)
{
    f32 norm;
    f32 sin_x_cos_y = matrix->m[1][2];
    f32 cos_x_cos_y = matrix->m[2][2];
    norm            = sqrtf(SQR(sin_x_cos_y) + SQR(cos_x_cos_y));
    if (EPSILON < norm)
    {
        angles[0] = atan2f(matrix->m[1][2], matrix->m[2][2]);
        angles[1] = atan2f(-matrix->m[0][2], norm);
        angles[2] = atan2f(matrix->m[0][1], matrix->m[0][0]);
    }
    else
    {
        angles[0] = 0.0f;
        angles[1] = atan2f(-matrix->m[0][2], norm);
        angles[2] = atan2f(-matrix->m[1][0], matrix->m[1][1]);
    }
}

void matrix_4x4_set_position_and_rotation_around_xyz(vec3 position, vec3 rotation, Mtxf *matrix)
{
    matrix_4x4_set_rotation_around_xyz(rotation, matrix);
    matrix_4x4_set_position(position, matrix);
}

void matrix_4x4_set_identity_and_position(vec3 position, Mtxf *matrix)
{
    matrix_4x4_set_identity(matrix);
    matrix_4x4_set_position(position, matrix);
}

void matrix_4x4_set_position(vec3 position, Mtxf *matrix)
{
    matrix->m[3][0] = position[0];
    matrix->m[3][1] = position[1];
    matrix->m[3][2] = position[2];
}

void matrix_column_1_scalar_multiply(f32 scalar, f32 *matrix)
{
    matrix[0] *= scalar;
    matrix[1] *= scalar;
    matrix[2] *= scalar;
}

void matrix_column_2_scalar_multiply(f32 scalar, f32 *matrix)
{
    matrix[4] *= scalar;
    matrix[5] *= scalar;
    matrix[6] *= scalar;
}

void matrix_column_3_scalar_multiply(f32 scalar, f32 *matrix)
{
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
    matrix[11] *= scalar;
}

void matrix_column_3_scalar_multiply_2(f32 scalar, f32 *matrix)
{
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
}

void matrix_scalar_multiply(f32 scalar, f32 *matrix)
{
    matrix[0] *= scalar;
    matrix[1] *= scalar;
    matrix[2] *= scalar;
    matrix[3] *= scalar;
    matrix[4] *= scalar;
    matrix[5] *= scalar;
    matrix[6] *= scalar;
    matrix[7] *= scalar;
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
    matrix[11] *= scalar;
}

void matrix_scalar_multiply_2(f32 scalar, f32 *matrix)
{
    matrix[0] *= scalar;
    matrix[1] *= scalar;
    matrix[2] *= scalar;
    matrix[4] *= scalar;
    matrix[5] *= scalar;
    matrix[6] *= scalar;
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
}

void matrix_row_3_scalar_multiply(f32 scalar, f32 *matrix)
{
    matrix[2] *= scalar;
    matrix[6] *= scalar;
    matrix[10] *= scalar;
    matrix[14] *= scalar;
}

void matrix_scalar_multiply_3(f32 scalar, f32 *matrix)
{
    matrix[0] *= scalar;
    matrix[4] *= scalar;
    matrix[8] *= scalar;
    matrix[12] *= scalar;
    matrix[1] *= scalar;
    matrix[5] *= scalar;
    matrix[9] *= scalar;
    matrix[13] *= scalar;
    matrix[2] *= scalar;
    matrix[6] *= scalar;
    matrix[10] *= scalar;
    matrix[14] *= scalar;
}

void matrix_4x4_7F058C4C(f32 arg0)
{
    D_80032310[0] = (M_U16_MAX_VALUE_F * arg0);
}

void matrix_4x4_7F058C64(void)
{
    flt_CODE_bss_80075DA0 = D_80032310[0];
    D_80032310[0]         = M_U16_MAX_VALUE_F;
}

void matrix_4x4_7F058C88(void)
{
    D_80032310[0] = flt_CODE_bss_80075DA0;
}

#ifdef NONMATCHING
// #define GET_HIGH_S16(x, y) (x & 0xFFFF0000) | (y >> 16);
// #define GET_LOW_S16(x, y) (x << 16) | (y & 0xFFFF);

// #define STORE_HIGH_AND_LOW_16(index) \
//     var1 = (s32)(matrix[(index) * 2 + 0] * D_80032310[(index) & 0]); \
//     var2 = (s32)(matrix[(index) * 2 + 1] * D_80032310[(index) & 1]); \
//     result[index + 0] = GET_HIGH_S16(var1, var2); \
//     result[index + 8] = GET_LOW_S16(var1, var2);
#    define FTOFIX32(x) (long)((x)*D_80032310[0])

void matrix_4x4_f32_to_s32(f32 mf[4][4], s32 ms[4][4])
{
    int  i, j;
    int  e1, e2;
    int *ai, *af;

    ai = (int *)&ms[0][0];
    af = (int *)&ms[2][0];

    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++)
        {
            e1      = FTOFIX32(mf[i][j * 2]);
            e2      = FTOFIX32(mf[i][j * 2 + 1]);
            *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
            *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
        }
}


//     // s32 i;
//     // s32 x;
//     // s32 y;
//     // for (i = 0; i < 8; i++) {
//     //     result[i] =
//     //     //x = D_80032310[(i + 0) & 0] * matrix[i][0];
//     //     //y = D_80032310[(i + 0) & 0] * matrix[0][i];
//     //     //y = D_80032310[(i + 0) & 1]
//     // }

//     s32 i;
//     u32 var1;
//     u32 var2;
//     // u32 var3;
//     // u32 var4;
//     // u32 var5;
//     // u32 var6;
//     // u32 var7;
//     // u32 var8;
//     for (i = 0; i < 8; i += 4) {
//         STORE_HIGH_AND_LOW_16(i + 0)
//         STORE_HIGH_AND_LOW_16(i + 1)
//         STORE_HIGH_AND_LOW_16(i + 2)
//         STORE_HIGH_AND_LOW_16(i + 3)



//         // var1 = (s32)(D_80032310[0] * matrix[(i + 0) * 2 + 0]);
//         // var2 = (s32)(D_80032310[0] * matrix[(i + 0) * 2 + 1]);
//         // result[i + 0] = GET_HIGH_S16(var1, var2);
//         // result[i + 8] = GET_LOW_S16(var1, var2);
//         // var3 = (s32)(D_80032310[0] * matrix[(i + 1) * 2 + 0]);
//         // var4 = (s32)(D_80032310[1] * matrix[(i + 1) * 2 + 1]);
//         // result[i + 1]= GET_HIGH_S16(var3, var4);
//         // result[i + 9] = GET_LOW_S16(var3, var4);
//         // var5 = (s32)(D_80032310[0] * matrix[(i + 2) * 2 + 0]);
//         // var6 = (s32)(D_80032310[0] * matrix[(i + 2) * 2 + 1]);
//         // result[i + 2] = GET_HIGH_S16(var5, var6);
//         // result[i + 10] = GET_LOW_S16(var5, var6);
//         // var7 = (s32)(D_80032310[0] * matrix[(i + 3) * 2 + 0]);
//         // var8 = (s32)(D_80032310[1] * matrix[(i + 3) * 2 + 1]);
//         // result[i + 3] = GET_HIGH_S16(var7, var8);
//         // result[i + 11] = GET_LOW_S16(var7, var8);
//     }
// }
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_f32_to_s32
/* 08D7CC 7F058C9C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D7D0 7F058CA0 AFB1000C */  sw    $s1, 0xc($sp)
/* 08D7D4 7F058CA4 AFB30014 */  sw    $s3, 0x14($sp)
/* 08D7D8 7F058CA8 AFB20010 */  sw    $s2, 0x10($sp)
/* 08D7DC 7F058CAC 3C118003 */  lui   $s1, %hi(D_80032310)
/* 08D7E0 7F058CB0 AFB00008 */  sw    $s0, 8($sp)
/* 08D7E4 7F058CB4 26312310 */  addiu $s1, %lo(D_80032310) # addiu $s1, $s1, 0x2310
/* 08D7E8 7F058CB8 3C12FFFF */  lui   $s2, 0xffff
/* 08D7EC 7F058CBC 24130008 */  li    $s3, 8
/* 08D7F0 7F058CC0 00001025 */  move  $v0, $zero
/* 08D7F4 7F058CC4 00A05825 */  move  $t3, $a1
.L7F058CC8:
/* 08D7F8 7F058CC8 C6320000 */  lwc1  $f18, ($s1)
/* 08D7FC 7F058CCC 000278C0 */  sll   $t7, $v0, 3
/* 08D800 7F058CD0 008F5021 */  addu  $t2, $a0, $t7
/* 08D804 7F058CD4 C5500000 */  lwc1  $f16, ($t2)
/* 08D808 7F058CD8 C54E0004 */  lwc1  $f14, 4($t2)
/* 08D80C 7F058CDC 30590001 */  andi  $t9, $v0, 1
/* 08D810 7F058CE0 46109402 */  mul.s $f16, $f18, $f16
/* 08D814 7F058CE4 00197080 */  sll   $t6, $t9, 2
/* 08D818 7F058CE8 022E7821 */  addu  $t7, $s1, $t6
/* 08D81C 7F058CEC C5F20000 */  lwc1  $f18, ($t7)
/* 08D820 7F058CF0 24470001 */  addiu $a3, $v0, 1
/* 08D824 7F058CF4 24480002 */  addiu $t0, $v0, 2
/* 08D828 7F058CF8 460E9382 */  mul.s $f14, $f18, $f14
/* 08D82C 7F058CFC 4600840D */  trunc.w.s $f16, $f16
/* 08D830 7F058D00 24490003 */  addiu $t1, $v0, 3
/* 08D834 7F058D04 24420004 */  addiu $v0, $v0, 4
/* 08D838 7F058D08 256B0010 */  addiu $t3, $t3, 0x10
/* 08D83C 7F058D0C 44038000 */  mfc1  $v1, $f16
/* 08D840 7F058D10 4600738D */  trunc.w.s $f14, $f14
/* 08D844 7F058D14 0072C824 */  and   $t9, $v1, $s2
/* 08D848 7F058D18 0003C400 */  sll   $t8, $v1, 0x10
/* 08D84C 7F058D1C 44067000 */  mfc1  $a2, $f14
/* 08D850 7F058D20 00000000 */  nop   
/* 08D854 7F058D24 00067402 */  srl   $t6, $a2, 0x10
/* 08D858 7F058D28 032E7825 */  or    $t7, $t9, $t6
/* 08D85C 7F058D2C AD6FFFF0 */  sw    $t7, -0x10($t3)
/* 08D860 7F058D30 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08D864 7F058D34 03197025 */  or    $t6, $t8, $t9
/* 08D868 7F058D38 AD6E0010 */  sw    $t6, 0x10($t3)
/* 08D86C 7F058D3C C62E0000 */  lwc1  $f14, ($s1)
/* 08D870 7F058D40 0007C0C0 */  sll   $t8, $a3, 3
/* 08D874 7F058D44 00986021 */  addu  $t4, $a0, $t8
/* 08D878 7F058D48 C5900000 */  lwc1  $f16, ($t4)
/* 08D87C 7F058D4C C5920004 */  lwc1  $f18, 4($t4)
/* 08D880 7F058D50 30EE0001 */  andi  $t6, $a3, 1
/* 08D884 7F058D54 46107402 */  mul.s $f16, $f14, $f16
/* 08D888 7F058D58 000E7880 */  sll   $t7, $t6, 2
/* 08D88C 7F058D5C 022FC021 */  addu  $t8, $s1, $t7
/* 08D890 7F058D60 C70E0000 */  lwc1  $f14, ($t8)
/* 08D894 7F058D64 46127482 */  mul.s $f18, $f14, $f18
/* 08D898 7F058D68 4600840D */  trunc.w.s $f16, $f16
/* 08D89C 7F058D6C 44038000 */  mfc1  $v1, $f16
/* 08D8A0 7F058D70 4600948D */  trunc.w.s $f18, $f18
/* 08D8A4 7F058D74 00727024 */  and   $t6, $v1, $s2
/* 08D8A8 7F058D78 0003CC00 */  sll   $t9, $v1, 0x10
/* 08D8AC 7F058D7C 44069000 */  mfc1  $a2, $f18
/* 08D8B0 7F058D80 00000000 */  nop   
/* 08D8B4 7F058D84 00067C02 */  srl   $t7, $a2, 0x10
/* 08D8B8 7F058D88 01CFC025 */  or    $t8, $t6, $t7
/* 08D8BC 7F058D8C AD78FFF4 */  sw    $t8, -0xc($t3)
/* 08D8C0 7F058D90 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08D8C4 7F058D94 032E7825 */  or    $t7, $t9, $t6
/* 08D8C8 7F058D98 AD6F0014 */  sw    $t7, 0x14($t3)
/* 08D8CC 7F058D9C C6320000 */  lwc1  $f18, ($s1)
/* 08D8D0 7F058DA0 0008C8C0 */  sll   $t9, $t0, 3
/* 08D8D4 7F058DA4 00996821 */  addu  $t5, $a0, $t9
/* 08D8D8 7F058DA8 C5B00000 */  lwc1  $f16, ($t5)
/* 08D8DC 7F058DAC C5AE0004 */  lwc1  $f14, 4($t5)
/* 08D8E0 7F058DB0 310F0001 */  andi  $t7, $t0, 1
/* 08D8E4 7F058DB4 46109402 */  mul.s $f16, $f18, $f16
/* 08D8E8 7F058DB8 000FC080 */  sll   $t8, $t7, 2
/* 08D8EC 7F058DBC 0238C821 */  addu  $t9, $s1, $t8
/* 08D8F0 7F058DC0 C7320000 */  lwc1  $f18, ($t9)
/* 08D8F4 7F058DC4 460E9382 */  mul.s $f14, $f18, $f14
/* 08D8F8 7F058DC8 4600840D */  trunc.w.s $f16, $f16
/* 08D8FC 7F058DCC 44038000 */  mfc1  $v1, $f16
/* 08D900 7F058DD0 4600738D */  trunc.w.s $f14, $f14
/* 08D904 7F058DD4 00727824 */  and   $t7, $v1, $s2
/* 08D908 7F058DD8 00037400 */  sll   $t6, $v1, 0x10
/* 08D90C 7F058DDC 44067000 */  mfc1  $a2, $f14
/* 08D910 7F058DE0 00000000 */  nop   
/* 08D914 7F058DE4 0006C402 */  srl   $t8, $a2, 0x10
/* 08D918 7F058DE8 01F8C825 */  or    $t9, $t7, $t8
/* 08D91C 7F058DEC 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08D920 7F058DF0 AD79FFF8 */  sw    $t9, -8($t3)
/* 08D924 7F058DF4 01CFC025 */  or    $t8, $t6, $t7
/* 08D928 7F058DF8 AD780018 */  sw    $t8, 0x18($t3)
/* 08D92C 7F058DFC C62E0000 */  lwc1  $f14, ($s1)
/* 08D930 7F058E00 000970C0 */  sll   $t6, $t1, 3
/* 08D934 7F058E04 008E8021 */  addu  $s0, $a0, $t6
/* 08D938 7F058E08 C6100000 */  lwc1  $f16, ($s0)
/* 08D93C 7F058E0C C6120004 */  lwc1  $f18, 4($s0)
/* 08D940 7F058E10 31380001 */  andi  $t8, $t1, 1
/* 08D944 7F058E14 46107402 */  mul.s $f16, $f14, $f16
/* 08D948 7F058E18 0018C880 */  sll   $t9, $t8, 2
/* 08D94C 7F058E1C 02397021 */  addu  $t6, $s1, $t9
/* 08D950 7F058E20 C5CE0000 */  lwc1  $f14, ($t6)
/* 08D954 7F058E24 46127482 */  mul.s $f18, $f14, $f18
/* 08D958 7F058E28 4600840D */  trunc.w.s $f16, $f16
/* 08D95C 7F058E2C 44038000 */  mfc1  $v1, $f16
/* 08D960 7F058E30 4600948D */  trunc.w.s $f18, $f18
/* 08D964 7F058E34 0072C024 */  and   $t8, $v1, $s2
/* 08D968 7F058E38 00037C00 */  sll   $t7, $v1, 0x10
/* 08D96C 7F058E3C 44069000 */  mfc1  $a2, $f18
/* 08D970 7F058E40 00000000 */  nop   
/* 08D974 7F058E44 0006CC02 */  srl   $t9, $a2, 0x10
/* 08D978 7F058E48 03197025 */  or    $t6, $t8, $t9
/* 08D97C 7F058E4C 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08D980 7F058E50 01F8C825 */  or    $t9, $t7, $t8
/* 08D984 7F058E54 AD6EFFFC */  sw    $t6, -4($t3)
/* 08D988 7F058E58 1453FF9B */  bne   $v0, $s3, .L7F058CC8
/* 08D98C 7F058E5C AD79001C */   sw    $t9, 0x1c($t3)
/* 08D990 7F058E60 8FB00008 */  lw    $s0, 8($sp)
/* 08D994 7F058E64 8FB1000C */  lw    $s1, 0xc($sp)
/* 08D998 7F058E68 8FB20010 */  lw    $s2, 0x10($sp)
/* 08D99C 7F058E6C 8FB30014 */  lw    $s3, 0x14($sp)
/* 08D9A0 7F058E70 03E00008 */  jr    $ra
/* 08D9A4 7F058E74 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058E78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058E78
/* 08D9A8 7F058E78 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D9AC 7F058E7C AFB20010 */  sw    $s2, 0x10($sp)
/* 08D9B0 7F058E80 AFB30014 */  sw    $s3, 0x14($sp)
/* 08D9B4 7F058E84 AFB1000C */  sw    $s1, 0xc($sp)
/* 08D9B8 7F058E88 3C128003 */  lui   $s2, %hi(D_80032310)
/* 08D9BC 7F058E8C AFB00008 */  sw    $s0, 8($sp)
/* 08D9C0 7F058E90 26522310 */  addiu $s2, %lo(D_80032310) # addiu $s2, $s2, 0x2310
/* 08D9C4 7F058E94 3C11FFFF */  lui   $s1, 0xffff
/* 08D9C8 7F058E98 24130008 */  li    $s3, 8
/* 08D9CC 7F058E9C 00001025 */  move  $v0, $zero
/* 08D9D0 7F058EA0 00805025 */  move  $t2, $a0
.L7F058EA4:
/* 08D9D4 7F058EA4 8D430000 */  lw    $v1, ($t2)
/* 08D9D8 7F058EA8 8D460020 */  lw    $a2, 0x20($t2)
/* 08D9DC 7F058EAC C6480000 */  lwc1  $f8, ($s2)
/* 08D9E0 7F058EB0 0071C024 */  and   $t8, $v1, $s1
/* 08D9E4 7F058EB4 0006CC02 */  srl   $t9, $a2, 0x10
/* 08D9E8 7F058EB8 03197025 */  or    $t6, $t8, $t9
/* 08D9EC 7F058EBC 448E2000 */  mtc1  $t6, $f4
/* 08D9F0 7F058EC0 000278C0 */  sll   $t7, $v0, 3
/* 08D9F4 7F058EC4 00AF5821 */  addu  $t3, $a1, $t7
/* 08D9F8 7F058EC8 468021A0 */  cvt.s.w $f6, $f4
/* 08D9FC 7F058ECC 00037C00 */  sll   $t7, $v1, 0x10
/* 08DA00 7F058ED0 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DA04 7F058ED4 01F8C825 */  or    $t9, $t7, $t8
/* 08DA08 7F058ED8 44998000 */  mtc1  $t9, $f16
/* 08DA0C 7F058EDC 304E0001 */  andi  $t6, $v0, 1
/* 08DA10 7F058EE0 46083283 */  div.s $f10, $f6, $f8
/* 08DA14 7F058EE4 000E7880 */  sll   $t7, $t6, 2
/* 08DA18 7F058EE8 024FC021 */  addu  $t8, $s2, $t7
/* 08DA1C 7F058EEC 24470001 */  addiu $a3, $v0, 1
/* 08DA20 7F058EF0 468084A0 */  cvt.s.w $f18, $f16
/* 08DA24 7F058EF4 000770C0 */  sll   $t6, $a3, 3
/* 08DA28 7F058EF8 00AE6021 */  addu  $t4, $a1, $t6
/* 08DA2C 7F058EFC 24480002 */  addiu $t0, $v0, 2
/* 08DA30 7F058F00 24490003 */  addiu $t1, $v0, 3
/* 08DA34 7F058F04 24420004 */  addiu $v0, $v0, 4
/* 08DA38 7F058F08 254A0010 */  addiu $t2, $t2, 0x10
/* 08DA3C 7F058F0C E56A0000 */  swc1  $f10, ($t3)
/* 08DA40 7F058F10 C7040000 */  lwc1  $f4, ($t8)
/* 08DA44 7F058F14 46049183 */  div.s $f6, $f18, $f4
/* 08DA48 7F058F18 E5660004 */  swc1  $f6, 4($t3)
/* 08DA4C 7F058F1C 8D460014 */  lw    $a2, 0x14($t2)
/* 08DA50 7F058F20 8D43FFF4 */  lw    $v1, -0xc($t2)
/* 08DA54 7F058F24 C6500000 */  lwc1  $f16, ($s2)
/* 08DA58 7F058F28 0006C402 */  srl   $t8, $a2, 0x10
/* 08DA5C 7F058F2C 00717824 */  and   $t7, $v1, $s1
/* 08DA60 7F058F30 01F8C825 */  or    $t9, $t7, $t8
/* 08DA64 7F058F34 44994000 */  mtc1  $t9, $f8
/* 08DA68 7F058F38 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DA6C 7F058F3C 00037400 */  sll   $t6, $v1, 0x10
/* 08DA70 7F058F40 468042A0 */  cvt.s.w $f10, $f8
/* 08DA74 7F058F44 01CFC025 */  or    $t8, $t6, $t7
/* 08DA78 7F058F48 44982000 */  mtc1  $t8, $f4
/* 08DA7C 7F058F4C 30F90001 */  andi  $t9, $a3, 1
/* 08DA80 7F058F50 00197080 */  sll   $t6, $t9, 2
/* 08DA84 7F058F54 468021A0 */  cvt.s.w $f6, $f4
/* 08DA88 7F058F58 024E7821 */  addu  $t7, $s2, $t6
/* 08DA8C 7F058F5C 0008C8C0 */  sll   $t9, $t0, 3
/* 08DA90 7F058F60 00B96821 */  addu  $t5, $a1, $t9
/* 08DA94 7F058F64 46105483 */  div.s $f18, $f10, $f16
/* 08DA98 7F058F68 E5920000 */  swc1  $f18, ($t4)
/* 08DA9C 7F058F6C C5E80000 */  lwc1  $f8, ($t7)
/* 08DAA0 7F058F70 46083283 */  div.s $f10, $f6, $f8
/* 08DAA4 7F058F74 E58A0004 */  swc1  $f10, 4($t4)
/* 08DAA8 7F058F78 8D460018 */  lw    $a2, 0x18($t2)
/* 08DAAC 7F058F7C 8D43FFF8 */  lw    $v1, -8($t2)
/* 08DAB0 7F058F80 C6440000 */  lwc1  $f4, ($s2)
/* 08DAB4 7F058F84 00067C02 */  srl   $t7, $a2, 0x10
/* 08DAB8 7F058F88 00717024 */  and   $t6, $v1, $s1
/* 08DABC 7F058F8C 01CFC025 */  or    $t8, $t6, $t7
/* 08DAC0 7F058F90 44988000 */  mtc1  $t8, $f16
/* 08DAC4 7F058F94 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DAC8 7F058F98 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DACC 7F058F9C 468084A0 */  cvt.s.w $f18, $f16
/* 08DAD0 7F058FA0 032E7825 */  or    $t7, $t9, $t6
/* 08DAD4 7F058FA4 448F4000 */  mtc1  $t7, $f8
/* 08DAD8 7F058FA8 31180001 */  andi  $t8, $t0, 1
/* 08DADC 7F058FAC 0018C880 */  sll   $t9, $t8, 2
/* 08DAE0 7F058FB0 468042A0 */  cvt.s.w $f10, $f8
/* 08DAE4 7F058FB4 02597021 */  addu  $t6, $s2, $t9
/* 08DAE8 7F058FB8 0009C0C0 */  sll   $t8, $t1, 3
/* 08DAEC 7F058FBC 00B88021 */  addu  $s0, $a1, $t8
/* 08DAF0 7F058FC0 46049183 */  div.s $f6, $f18, $f4
/* 08DAF4 7F058FC4 E5A60000 */  swc1  $f6, ($t5)
/* 08DAF8 7F058FC8 C5D00000 */  lwc1  $f16, ($t6)
/* 08DAFC 7F058FCC 46105483 */  div.s $f18, $f10, $f16
/* 08DB00 7F058FD0 E5B20004 */  swc1  $f18, 4($t5)
/* 08DB04 7F058FD4 8D46001C */  lw    $a2, 0x1c($t2)
/* 08DB08 7F058FD8 8D43FFFC */  lw    $v1, -4($t2)
/* 08DB0C 7F058FDC C6480000 */  lwc1  $f8, ($s2)
/* 08DB10 7F058FE0 00067402 */  srl   $t6, $a2, 0x10
/* 08DB14 7F058FE4 0071C824 */  and   $t9, $v1, $s1
/* 08DB18 7F058FE8 032E7825 */  or    $t7, $t9, $t6
/* 08DB1C 7F058FEC 448F2000 */  mtc1  $t7, $f4
/* 08DB20 7F058FF0 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DB24 7F058FF4 0003C400 */  sll   $t8, $v1, 0x10
/* 08DB28 7F058FF8 468021A0 */  cvt.s.w $f6, $f4
/* 08DB2C 7F058FFC 03197025 */  or    $t6, $t8, $t9
/* 08DB30 7F059000 448E8000 */  mtc1  $t6, $f16
/* 08DB34 7F059004 312F0001 */  andi  $t7, $t1, 1
/* 08DB38 7F059008 000FC080 */  sll   $t8, $t7, 2
/* 08DB3C 7F05900C 468084A0 */  cvt.s.w $f18, $f16
/* 08DB40 7F059010 0258C821 */  addu  $t9, $s2, $t8
/* 08DB44 7F059014 46083283 */  div.s $f10, $f6, $f8
/* 08DB48 7F059018 E60A0000 */  swc1  $f10, ($s0)
/* 08DB4C 7F05901C C7240000 */  lwc1  $f4, ($t9)
/* 08DB50 7F059020 46049183 */  div.s $f6, $f18, $f4
/* 08DB54 7F059024 1453FF9F */  bne   $v0, $s3, .L7F058EA4
/* 08DB58 7F059028 E6060004 */   swc1  $f6, 4($s0)
/* 08DB5C 7F05902C 8FB00008 */  lw    $s0, 8($sp)
/* 08DB60 7F059030 8FB1000C */  lw    $s1, 0xc($sp)
/* 08DB64 7F059034 8FB20010 */  lw    $s2, 0x10($sp)
/* 08DB68 7F059038 8FB30014 */  lw    $s3, 0x14($sp)
/* 08DB6C 7F05903C 03E00008 */  jr    $ra
/* 08DB70 7F059040 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

void matrix_4x4_7F059044(Mtxf *arg0, Mtx* arg1) {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg1->m[i][j] = arg0->m[i][j] * M_U16_MAX_VALUE_F;
        }
    }
}

void matrix_4x4_7F05914C(Mtx* arg0, Mtxf *arg1) {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg1->m[i][j] = arg0->m[i][j] / M_U16_MAX_VALUE_F;
        }
    }
}

//#ifdef NONMATCHING
#if 0
#define MTX_INTPART_PACK(w1, w2) (((w1) & 0xFFFF0000) | ((w2) >> 16))
#define MTX_FRACPART_PACK(w1, w2) (((w1) << 16) | ((w2) & 0xFFFF))

void sub_GAME_7F059244(Mtx* a0, Mtx* a1) {
    // s32 i;
    // s32 j;
    // u32 w1;
    // u32 w2;
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < 4; j++) {
    //         w1 = a0->m[i * 2 + j / 2][((j * 2) % 4) + 0];
    //         w2 = a0->m[i * 2 + j / 2][((j * 2) % 4) + 1];
    //         a1->m[i + 0][j] = MTX_INTPART_PACK(w1, w2);
    //         a1->m[i + 2][j] = MTX_FRACPART_PACK(w1, w2);
    //     }
    // }

    // Reg alloc and iteration mostly!
    // s32 i;
    // s32 j;
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < 4; j++) {
    //         u32 w1 = a0[i * 2 + j / 2][(j % 2) * 2 + 0];
    //         u32 w2 = a0[i * 2 + j / 2][(j % 2) * 2 + 1];
    //         a1[i + 0][j] = MTX_INTPART_PACK(w1, w2);
    //         a1[i + 2][j] = MTX_FRACPART_PACK(w1, w2);
    //     }
    // }

    // s32 i;
    // s32 j;
    // s32 *mtxInt = (s32 *)&a1[0][0];
    // s32 *mtxFrc = (s32 *)&a1[2][0];
    // for (i = 0; i < 8; i++) {
    //     *mtxInt++ = MTX_INTPART_PACK(a0[i * 2], (u32)a0[i * 2 + 1]);
    //     *mtxFrc++ = MTX_FRACPART_PACK(a0[i * 2], a0[i * 2 + 1]);
    // }

    // s32 i;
    // s32 j;
    // s32 *mtxInt = (s32 *)&a1[0][0];
    // s32 *mtxFrc = (s32 *)&a1[2][0];
    // for (i = 0; i < 8; i++) {
    //     *mtxInt++ = MTX_INTPART_PACK(a0[i * 2], (u32)a0[i * 2 + 1]);
    //     *mtxFrc++ = MTX_FRACPART_PACK(a0[i * 2], a0[i * 2 + 1]);
    // }
    // s32 i;
    // s32 j;
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < 4; j++) {
    //         a1[i + 0][j] = MTX_INTPART_PACK(a0[i * 8 + j * 2], (u32)a0[i * 8 + j*2 + 1]);
    //         a1[i + 2][j] = MTX_FRACPART_PACK(a0[i * 8 + j * 2], a0[i * 8 + j*2 + 1]);
    //     }
    // }

    s32 i;
    s32 j;
    s32* ptr = &a0->m[0][0];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            s32 w1 = *ptr++;
            s32 w2 = *ptr++;
            a1->m[i + 0][j] = MTX_INTPART_PACK(w1, (u32)w2);
            a1->m[i + 2][j] = MTX_FRACPART_PACK(w1, w2);
        }
    }

    // s32 i;
    // s32 j;
    // s32 w1;
    // s32 w2;
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < 4; j++) {
    //         w1 = a0[i * 8 + j * 2 + 0];
    //         w2 = a0[i * 8 + j * 2 + 1];
    //         a1[i + 0][j] = MTX_INTPART_PACK(w1, (u32)w2);
    //         a1[i + 2][j] = MTX_FRACPART_PACK(w1, w2);
    //     }
    // }

    // s32 i = 0;
    // s32 *w1 = &a0[0][0];
    // s32 *w2 = &a0[0][1];
    // for (i = 0; i < 2; i++) {
    //     a1[i + 0][0] = MTX_INTPART_PACK(*w1, (u32)*w2);
    //     a1[i + 2][0] = MTX_FRACPART_PACK(*w1, *w2);
    //     w1 += 2;
    //     w2 += 2;
    //     a1[i + 0][1] = MTX_INTPART_PACK(*w1, (u32)*w2);
    //     a1[i + 2][1] = MTX_FRACPART_PACK(*w1, *w2);
    //     w1 += 2;
    //     w2 += 2;
    //     a1[i + 0][2] = MTX_INTPART_PACK(*w1, (u32)*w2);
    //     a1[i + 2][2] = MTX_FRACPART_PACK(*w1, *w2);
    //     w1 += 2;
    //     w2 += 2;
    //     a1[i + 0][3] = MTX_INTPART_PACK(*w1, (u32)*w2);
    //     a1[i + 2][3] = MTX_FRACPART_PACK(*w1, *w2);
    // }

    // s32 i = 0;
    // s32 w1;
    // s32 w2;
    // for (i = 0; i < 2; i++) {
    //     w1 = a0[i * 2 + 0][0];
    //     w2 = a0[i * 2 + 0][1];
    //     a1[i + 0][0] = MTX_INTPART_PACK(w1, (u32)w2);
    //     a1[i + 2][0] = MTX_FRACPART_PACK(w1, w2);
    //     w1 = a0[i * 2 + 0][2];
    //     w2 = a0[i * 2 + 0][3];
    //     a1[i + 0][1] = MTX_INTPART_PACK(w1, (u32)w2);
    //     a1[i + 2][1] = MTX_FRACPART_PACK(w1, w2);
    //     w1 = a0[i * 2 + 1][0];
    //     w2 = a0[i * 2 + 1][1];
    //     a1[i + 0][2] = MTX_INTPART_PACK(w1, (u32)w2);
    //     a1[i + 2][2] = MTX_FRACPART_PACK(w1, w2);
    //     w1 = a0[i * 2 + 1][2];
    //     w2 = a0[i * 2 + 1][3];
    //     a1[i + 0][3] = MTX_INTPART_PACK(w1, (u32)w2);
    //     a1[i + 2][3] = MTX_FRACPART_PACK(w1, w2);
    // }


    // s32 i;
    // for (i = 0; i < 2; i++) {
    //     a1[i + 0][0] = MTX_INTPART_PACK(a0[i * 2 + 0][0], (u32)a0[i * 2 + 0][1]);
    //     a1[i + 2][0] = MTX_FRACPART_PACK(a0[i * 2 + 0][0], a0[i * 2 + 0][1]);
    //     a1[i + 0][1] = MTX_INTPART_PACK(a0[i * 2 + 0][2], (u32)a0[i * 2 + 0][3]);
    //     a1[i + 2][1] = MTX_FRACPART_PACK(a0[i * 2 + 0][2], a0[i * 2 + 0][3]);
    //     a1[i + 0][2] = MTX_INTPART_PACK(a0[i * 2 + 1][0], (u32)a0[i * 2 + 1][1]);
    //     a1[i + 2][2] = MTX_FRACPART_PACK(a0[i * 2 + 1][0], a0[i * 2 + 1][1]);
    //     a1[i + 0][3] = MTX_INTPART_PACK(a0[i * 2 + 1][2], (u32)a0[i * 2 + 1][3]);
    //     a1[i + 2][3] = MTX_FRACPART_PACK(a0[i * 2 + 1][2], a0[i * 2 + 1][3]);
    // }


    // a1[0][0] = MTX_INTPART_PACK(a0[0][0], (u32)a0[0][1]);
    // a1[2][0] = MTX_FRACPART_PACK(a0[0][0], a0[0][1]);
    // a1[0][1] = MTX_INTPART_PACK(a0[0][2], (u32)a0[0][3]);
    // a1[2][1] = MTX_FRACPART_PACK(a0[0][2], a0[0][3]);
    // a1[0][2] = MTX_INTPART_PACK(a0[1][0], (u32)a0[1][1]);
    // a1[2][2] = MTX_FRACPART_PACK(a0[1][0], a0[1][1]);
    // a1[0][3] = MTX_INTPART_PACK(a0[1][2], (u32)a0[1][3]);
    // a1[2][3] = MTX_FRACPART_PACK(a0[1][2], a0[1][3]);

    // a1[1][0] = MTX_INTPART_PACK(a0[2][0], (u32)a0[2][1]);
    // a1[3][0] = MTX_FRACPART_PACK(a0[2][0], a0[2][1]);    
    // a1[1][1] = MTX_INTPART_PACK(a0[2][2], (u32)a0[2][3]);
    // a1[3][1] = MTX_FRACPART_PACK(a0[2][2], a0[2][3]);
    // a1[1][2] = MTX_INTPART_PACK(a0[3][0], (u32)a0[3][1]);
    // a1[3][2] = MTX_FRACPART_PACK(a0[3][0], a0[3][1]);
    // a1[1][3] = MTX_INTPART_PACK(a0[3][2], (u32)a0[3][3]);
    // a1[3][3] = MTX_FRACPART_PACK(a0[3][2], a0[3][3]);

/*  $v0 = 0
    loop:
    $a1 += 0x10
    $v1 = *($a0 + $v0 * 8 + 0x00)
    $a2 = *($a0 + $v0 * 8 + 0x04)
    *($a1 - 0x10) = MTX_INTPART_PACK($v1, (u32)$a2)
    *($a1 + 0x10) = MTX_FRACPART_PACK($v1, $a2)
    $v1 = *($a0 + ($v0 + 1) * 8 + 0x00)
    $a2 = *($a0 + ($v0 + 1) * 8 + 0x04)
    *($a1 - 0x0C) = MTX_INTPART_PACK($v1, (u32)$a2)
    *($a1 + 0x14) = MTX_FRACPART_PACK($v1, $a2)
    $v1 = *($a0 + ($v0 + 2) * 8 + 0x00)
    $a2 = *($a0 + ($v0 + 2) * 8 + 0x04)
    *($a1 - 0x08) = MTX_INTPART_PACK($v1, (u32)$a2)
    *($a1 + 0x18) = MTX_FRACPART_PACK($v1, $a2)
    $v1 = *($a0 + ($v0 + 3) * 8 + 0x00)
    $a2 = *($a0 + ($v0 + 3) * 8 + 0x04)
    *($a1 - 0x04) = MTX_INTPART_PACK($v1, (u32)$a2)
    *($a1 + 0x1C) = MTX_FRACPART_PACK($v1, $a2)
    $v0 += 4
    if ($v0 != 8) {
        goto loop;
    }*/
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059244
/* 08DD74 7F059244 00001025 */  move  $v0, $zero
/* 08DD78 7F059248 00A04025 */  move  $t0, $a1
/* 08DD7C 7F05924C 240D0008 */  li    $t5, 8
/* 08DD80 7F059250 3C0CFFFF */  lui   $t4, 0xffff
.L7F059254:
/* 08DD84 7F059254 000278C0 */  sll   $t7, $v0, 3
/* 08DD88 7F059258 008F3821 */  addu  $a3, $a0, $t7
/* 08DD8C 7F05925C 8CE30000 */  lw    $v1, ($a3)
/* 08DD90 7F059260 8CE60004 */  lw    $a2, 4($a3)
/* 08DD94 7F059264 25080010 */  addiu $t0, $t0, 0x10
/* 08DD98 7F059268 006CC024 */  and   $t8, $v1, $t4
/* 08DD9C 7F05926C 0006CC02 */  srl   $t9, $a2, 0x10
/* 08DDA0 7F059270 03197025 */  or    $t6, $t8, $t9
/* 08DDA4 7F059274 00037C00 */  sll   $t7, $v1, 0x10
/* 08DDA8 7F059278 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DDAC 7F05927C 01F8C825 */  or    $t9, $t7, $t8
/* 08DDB0 7F059280 244F0001 */  addiu $t7, $v0, 1
/* 08DDB4 7F059284 000FC0C0 */  sll   $t8, $t7, 3
/* 08DDB8 7F059288 00984821 */  addu  $t1, $a0, $t8
/* 08DDBC 7F05928C AD0EFFF0 */  sw    $t6, -0x10($t0)
/* 08DDC0 7F059290 AD190010 */  sw    $t9, 0x10($t0)
/* 08DDC4 7F059294 8D260004 */  lw    $a2, 4($t1)
/* 08DDC8 7F059298 8D230000 */  lw    $v1, ($t1)
/* 08DDCC 7F05929C 00067402 */  srl   $t6, $a2, 0x10
/* 08DDD0 7F0592A0 006CC824 */  and   $t9, $v1, $t4
/* 08DDD4 7F0592A4 032E7825 */  or    $t7, $t9, $t6
/* 08DDD8 7F0592A8 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DDDC 7F0592AC 0003C400 */  sll   $t8, $v1, 0x10
/* 08DDE0 7F0592B0 03197025 */  or    $t6, $t8, $t9
/* 08DDE4 7F0592B4 24580002 */  addiu $t8, $v0, 2
/* 08DDE8 7F0592B8 0018C8C0 */  sll   $t9, $t8, 3
/* 08DDEC 7F0592BC 00995021 */  addu  $t2, $a0, $t9
/* 08DDF0 7F0592C0 AD0E0014 */  sw    $t6, 0x14($t0)
/* 08DDF4 7F0592C4 AD0FFFF4 */  sw    $t7, -0xc($t0)
/* 08DDF8 7F0592C8 8D460004 */  lw    $a2, 4($t2)
/* 08DDFC 7F0592CC 8D430000 */  lw    $v1, ($t2)
/* 08DE00 7F0592D0 00067C02 */  srl   $t7, $a2, 0x10
/* 08DE04 7F0592D4 006C7024 */  and   $t6, $v1, $t4
/* 08DE08 7F0592D8 01CFC025 */  or    $t8, $t6, $t7
/* 08DE0C 7F0592DC 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DE10 7F0592E0 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DE14 7F0592E4 032E7825 */  or    $t7, $t9, $t6
/* 08DE18 7F0592E8 24590003 */  addiu $t9, $v0, 3
/* 08DE1C 7F0592EC 001970C0 */  sll   $t6, $t9, 3
/* 08DE20 7F0592F0 008E5821 */  addu  $t3, $a0, $t6
/* 08DE24 7F0592F4 AD0F0018 */  sw    $t7, 0x18($t0)
/* 08DE28 7F0592F8 AD18FFF8 */  sw    $t8, -8($t0)
/* 08DE2C 7F0592FC 8D660004 */  lw    $a2, 4($t3)
/* 08DE30 7F059300 8D630000 */  lw    $v1, ($t3)
/* 08DE34 7F059304 24420004 */  addiu $v0, $v0, 4
/* 08DE38 7F059308 0006C402 */  srl   $t8, $a2, 0x10
/* 08DE3C 7F05930C 006C7824 */  and   $t7, $v1, $t4
/* 08DE40 7F059310 01F8C825 */  or    $t9, $t7, $t8
/* 08DE44 7F059314 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DE48 7F059318 00037400 */  sll   $t6, $v1, 0x10
/* 08DE4C 7F05931C 01CFC025 */  or    $t8, $t6, $t7
/* 08DE50 7F059320 AD18001C */  sw    $t8, 0x1c($t0)
/* 08DE54 7F059324 144DFFCB */  bne   $v0, $t5, .L7F059254
/* 08DE58 7F059328 AD19FFFC */   sw    $t9, -4($t0)
/* 08DE5C 7F05932C 03E00008 */  jr    $ra
/* 08DE60 7F059330 00000000 */   nop   
)
#endif

/*
for ($v0 = 0; $v0 < 2; $v0++) { // pointers?
	$a1[$v0 * 2 + 0][0] = $a0[$v0][0] & 0xFFFF0000 | ($a0[$v0 + 2][0] >> 16)
	$a1[$v0 * 2 + 0][1] = $a0[$v0][0] << 16 | ($a0[$v0 + 2][0] & 0xFFFF)
	$a1[$v0 * 2 + 0][2] = $a0[$v0][1] & 0xFFFF0000 | $a0[$v0 + 2][1] >> 16
	$a1[$v0 * 2 + 0][3] = $a0[$v0][1] << 16 | $a0[$v0 + 2][1] & 0xFFFF
	$a1[$v0 * 2 + 1][0] = $a0[$v0][2] & 0xFFFF0000 | $a0[$v0 + 2][2] << 16
	$a1[$v0 * 2 + 1][1] = $a0[$v0][2] << 16 | $a0[$v0 + 2][2] & 0xFFFF
	$a1[$v0 * 2 + 1][2] = $a0[$v0][3] & 0xFFFF0000 | $a0[$v0 + 2][3] >> 16
	$a1[$v0 * 2 + 1][3] = $a0[$v0][3] << 16 | $a0[$v0 + 2][3] & 0xffff
}

*/

/* 
$v0 = 0
$a3 = $a0
loop:
	$v1 = *($a3)
	$a2 = *($a3 + 0x20)
    $t0 = $a1 + (($v0 + 0) * 8)
	*($t0) = ($v1 & 0xFFFF0000) | ($a2 >> 16)
	*($t0 + 0x4) = ($v1 << 16) | ($a2 & 0xFFFF)
    $a2 = *($a3 + 0x24)
	$v1 = *($a3 + 0x4)
	$t1 = $a1 + (($v0 + 1) * 8)
	*($t1 + 0) = $v1 & 0xFFFF0000 | $a2 >> 16
	*($t1 + 4) = $v1 << 16 | $a2 & 0xFFFF
	$a2 = *($a3 + 0x28)
	$v1 = *($a3 + 0x8)
	$t2 = $a1 + (($v0 + 2) * 8)
	*($t2 + 0) = $v1 & 0xFFFF0000 | $a2 << 16
	*($t2 + 4) = $v1 << 16 | $a2 & 0xFFFF
	$a2 = *($a3 + 0x2C)
	$v1 = *($a3 + 0xC)
	$t3 = $a1 + (($v0 + 3) * 8)
	$v0 += 4
	*($t3 + 0) = $v1 & 0xFFFF0000 | $a2 >> 16
	*($t3 + 4) = $v1 << 16 | $a2 & 0xffff
	if ($v0 != 8)
	{
		$a3 += 0x10;
		goto loop;
	}
return

*/
/*
0, 0
0, 1
0, 2
0, 3
1, 0
1, 1
1, 2
1, 3
2, 0
*/

// void sub_GAME_7F059334(mat4s arg0, mat4s arg1) {
//     s32 var1;
//     s32 var2;
//     s32 i, j;
//     for (i = 0; i < 2; i++) {
//         for (j = 0; j < 2; j++) {
//             var1 = arg0[i + 0][j + 0];
//             var2 = arg0[i + 2][j + 0];
//             arg1[i * 2 + 0][] [i * 8 + j * 2 + 0] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//             arg1[i * 2 + 0] * 2 + 1]  = ((var1 << 16) | (var2 & 0xFFFF));
//             var1 = arg0[i + 0][j + 1];
//             var2 = arg0[i + 2][j + 1];
//             arg1[i * 2 + 1][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//             arg1[i * 2 + 1][3] = ((var1 << 16) | (var2 & 0xFFFF));
//             // var1 = arg0[i + 0][2];
//             // var2 = arg0[i + 2][2];
//             // arg1[i * 2 + 1][0] = ((var1 & 0xFFFF0000) | (var2 << 16));
//             // arg1[i * 2 + 1][1] = ((var1 << 16) | (var2 & 0xFFFF));
//             // var1 = arg0[i + 0][3];
//             // var2 = arg0[i + 2][3];
//             // arg1[i * 2 + 1][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//             // arg1[i * 2 + 1][3] = ((var1 << 16) | (var2 & 0xffff));
//         }
//     }




// sub_GAME_7F059334(s32* arg0, s32* arg1) {  
//     s32* var1 = arg0;
//     s32* var2 = arg1;
//     for (i = 0; i < 2; i++) {
//     for (; var1 < (arg0 + 8); var1++, var2 += 4)
//         var1 = arg0[i + 0][0];
//         var2 = arg0[i + 2][0];
//         arg1[i * 2 + 0][0] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 0][1] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][1];
//         var2 = arg0[i + 2][1];
//         arg1[i * 2 + 0][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 0][3] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][2];
//         var2 = arg0[i + 2][2];
//         arg1[i * 2 + 1][0] = ((var1 & 0xFFFF0000) | (var2 << 16));
//         arg1[i * 2 + 1][1] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][3];
//         var2 = arg0[i + 2][3];
//         arg1[i * 2 + 1][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 1][3] = ((var1 << 16) | (var2 & 0xffff));
//     }

//     s32 var1;
//     s32 var2;
//     s32 i;
//     for (i = 0; i < 2; i++) {
//         var1 = arg0[i + 0][0];
//         var2 = arg0[i + 2][0];
//         arg1[i * 2 + 0][0] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 0][1] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][1];
//         var2 = arg0[i + 2][1];
//         arg1[i * 2 + 0][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 0][3] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][2];
//         var2 = arg0[i + 2][2];
//         arg1[i * 2 + 1][0] = ((var1 & 0xFFFF0000) | (var2 << 16));
//         arg1[i * 2 + 1][1] = ((var1 << 16) | (var2 & 0xFFFF));
//         var1 = arg0[i + 0][3];
//         var2 = arg0[i + 2][3];
//         arg1[i * 2 + 1][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
//         arg1[i * 2 + 1][3] = ((var1 << 16) | (var2 & 0xffff));
//     }

    // s32 temp_v1;
    // s32 temp_v1_2;
    // s32 temp_v1_3;
    // s32 temp_v1_4;
    // u32 temp_a2;
    // u32 temp_a2_2;
    // u32 temp_a2_3;
    // u32 temp_a2_4;
    // s32 i;

    // for (i = 0; i < 2; i++) {
    //     temp_v1 = arg0[i + 0][0];
    //     temp_a2 = arg0[i + 2][0];
    //     arg1[i * 2][0] = ((temp_v1 & 0xFFFF0000) | (temp_a2 >> 0x10));
    //     arg1[i * 2][1] = ((temp_v1 << 0x10) | (temp_a2 & 0xFFFF));
    //     temp_v1_2 = arg0[i + 0][1];
    //     temp_a2_2 = arg0[i + 2][1];
    //     arg1[i * 2][2] = ((temp_v1_2 & 0xFFFF0000) | (temp_a2_2 >> 0x10));
    //     arg1[i * 2][3] = ((temp_v1_2 << 0x10) | (temp_a2_2 & 0xFFFF));
    //     temp_v1_3 = arg0[i + 0][2];
    //     temp_a2_3 = arg0[i + 2][2];
    //     arg1[i * 2 + 1][0] = ((temp_v1_3 & 0xFFFF0000) | (temp_a2_3 >> 0x10));
    //     arg1[i * 2 + 1][1] = ((temp_v1_3 << 0x10) | (temp_a2_3 & 0xFFFF));
    //     temp_v1_4 = arg0[i + 0][3];
    //     temp_a2_4 = arg0[i + 2][3];
    //     arg1[i * 2 + 1][2] = ((temp_v1_4 & 0xFFFF0000) | (temp_a2_4 >> 0x10));
    //     arg1[i * 2 + 1][3] = ((temp_v1_4 << 0x10) | (temp_a2_4 & 0xFFFF));
    // }
//}

#ifdef NONMATCHING
#define MTX_INTPART_PACK(w1, w2) (((w1) & 0xFFFF0000) | (((w2) >> 16)/* & 0xFFFF*/))
#define MTX_FRACPART_PACK(w1, w2) ((((w1) << 16) & 0xFFFF0000) | ((w2) & 0xFFFF))

// void sub_GAME_7F059334(s32 arg0[4][4], s32 arg1[4][4]) {    
//     s32 i;
//     s32 j;
//     u32 *m1 = (u32*)&arg0[0][0];
//     u32 *m2 = (u32*)&arg0[2][0];
//     for (i = 0; i < 4; i++) {
//         for (j = 0; j < 2; j++) {
//             arg1[i][j * 2 + 0] = MTX_INTPART_PACK((*m1), (*m2));
//             m1++;
//             arg1[i][j * 2 + 1] = MTX_FRACPART_PACK((*m1), (*m2));
//             m2++;
//         }
//     }
    
    
    // s32 var1;
    // u32 var2;
    // s32 i;
    // for ()
    // for (i = 0; i < 2; i++) {
    //     var1 = arg0[i + 0][0];
    //     var2 = arg0[i + 2][0];
    //     arg1[i * 2 + 0][0] = ((var1 & 0xFFFF0000) | (var2 >> 16));
    //     arg1[i * 2 + 0][1] = ((var1 << 16) | (var2 & 0xFFFF));
    //     var1 = arg0[i + 0][1];
    //     var2 = arg0[i + 2][1];
    //     arg1[i * 2 + 0][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
    //     arg1[i * 2 + 0][3] = ((var1 << 16) | (var2 & 0xFFFF));
    //     var1 = arg0[i + 0][2];
    //     var2 = arg0[i + 2][2];
    //     arg1[i * 2 + 1][0] = ((var1 & 0xFFFF0000) | (var2 << 16));
    //     arg1[i * 2 + 1][1] = ((var1 << 16) | (var2 & 0xFFFF));
    //     var1 = arg0[i + 0][3];
    //     var2 = arg0[i + 2][3];
    //     arg1[i * 2 + 1][2] = ((var1 & 0xFFFF0000) | (var2 >> 16));
    //     arg1[i * 2 + 1][3] = ((var1 << 16) | (var2 & 0xffff));
    // }
//}
// void sub_GAME_7F059334(s32 m1[4][4], s32 m2[4][4]) {
//     int i;
//     int j;
//     int *ai = &m1[0][0];
//     u32 *af = &m1[2][0];

//     for (j=0; j<2; j++) {
//         for (i=0; i<4; i++) {
//             m2[i][j*2+0] = (*ai & 0xffff0000) | ((*af >> 16) & 0xffff);
//             m2[i][j*2+1] = ((*(ai++) << 16) & 0xffff0000) | (*(af++) & 0xffff);
//         }
//     }
// }

//void sub_GAME_7F059334(s32 m1[16], s32 m2[16]) {
    // s32 i;
    // for (i = 0; i < 8; i++) {
    //     s32 t1 = m1[i+0];
    //     s32 t2 = m1[i+8];
    //     m2[i * 2 + 0] = MTX_INTPART_PACK(t1, t2);
    //     m2[i * 2 + 1] = MTX_FRACPART_PACK(t1, t2);
    // }
    // s32 i, j;
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < 4; j++) {
    //         s32 t1 = m1[i+0][j];
    //         s32 t2 = m1[i+2][j];
    //         m2[i*8+j*2+0] = MTX_INTPART_PACK(t1, t2);
    //         m2[i*8+j*2+1] = MTX_FRACPART_PACK(t1, t2);
    //     }
    // }
//}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059334
/* 08DE64 7F059334 00001025 */  move  $v0, $zero
/* 08DE68 7F059338 00803825 */  move  $a3, $a0
/* 08DE6C 7F05933C 240D0008 */  li    $t5, 8
/* 08DE70 7F059340 3C0CFFFF */  lui   $t4, 0xffff
.L7F059344:
/* 08DE74 7F059344 8CE30000 */  lw    $v1, ($a3)
/* 08DE78 7F059348 8CE60020 */  lw    $a2, 0x20($a3)
/* 08DE7C 7F05934C 000278C0 */  sll   $t7, $v0, 3
/* 08DE80 7F059350 006CC024 */  and   $t8, $v1, $t4
/* 08DE84 7F059354 0006CC02 */  srl   $t9, $a2, 0x10
/* 08DE88 7F059358 03197025 */  or    $t6, $t8, $t9
/* 08DE8C 7F05935C 00AF4021 */  addu  $t0, $a1, $t7
/* 08DE90 7F059360 00037C00 */  sll   $t7, $v1, 0x10
/* 08DE94 7F059364 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DE98 7F059368 01F8C825 */  or    $t9, $t7, $t8
/* 08DE9C 7F05936C AD0E0000 */  sw    $t6, ($t0)
/* 08DEA0 7F059370 AD190004 */  sw    $t9, 4($t0)
/* 08DEA4 7F059374 8CE60024 */  lw    $a2, 0x24($a3)
/* 08DEA8 7F059378 8CE30004 */  lw    $v1, 4($a3)
/* 08DEAC 7F05937C 244F0001 */  addiu $t7, $v0, 1
/* 08DEB0 7F059380 000FC0C0 */  sll   $t8, $t7, 3
/* 08DEB4 7F059384 00067402 */  srl   $t6, $a2, 0x10
/* 08DEB8 7F059388 006CC824 */  and   $t9, $v1, $t4
/* 08DEBC 7F05938C 032E7825 */  or    $t7, $t9, $t6
/* 08DEC0 7F059390 00B84821 */  addu  $t1, $a1, $t8
/* 08DEC4 7F059394 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DEC8 7F059398 0003C400 */  sll   $t8, $v1, 0x10
/* 08DECC 7F05939C 03197025 */  or    $t6, $t8, $t9
/* 08DED0 7F0593A0 AD2E0004 */  sw    $t6, 4($t1)
/* 08DED4 7F0593A4 AD2F0000 */  sw    $t7, ($t1)
/* 08DED8 7F0593A8 8CE60028 */  lw    $a2, 0x28($a3)
/* 08DEDC 7F0593AC 8CE30008 */  lw    $v1, 8($a3)
/* 08DEE0 7F0593B0 24580002 */  addiu $t8, $v0, 2
/* 08DEE4 7F0593B4 0018C8C0 */  sll   $t9, $t8, 3
/* 08DEE8 7F0593B8 00067C02 */  srl   $t7, $a2, 0x10
/* 08DEEC 7F0593BC 006C7024 */  and   $t6, $v1, $t4
/* 08DEF0 7F0593C0 01CFC025 */  or    $t8, $t6, $t7
/* 08DEF4 7F0593C4 00B95021 */  addu  $t2, $a1, $t9
/* 08DEF8 7F0593C8 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DEFC 7F0593CC 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DF00 7F0593D0 032E7825 */  or    $t7, $t9, $t6
/* 08DF04 7F0593D4 AD4F0004 */  sw    $t7, 4($t2)
/* 08DF08 7F0593D8 AD580000 */  sw    $t8, ($t2)
/* 08DF0C 7F0593DC 8CE6002C */  lw    $a2, 0x2c($a3)
/* 08DF10 7F0593E0 8CE3000C */  lw    $v1, 0xc($a3)
/* 08DF14 7F0593E4 24590003 */  addiu $t9, $v0, 3
/* 08DF18 7F0593E8 001970C0 */  sll   $t6, $t9, 3
/* 08DF1C 7F0593EC 0006C402 */  srl   $t8, $a2, 0x10
/* 08DF20 7F0593F0 006C7824 */  and   $t7, $v1, $t4
/* 08DF24 7F0593F4 01F8C825 */  or    $t9, $t7, $t8
/* 08DF28 7F0593F8 00AE5821 */  addu  $t3, $a1, $t6
/* 08DF2C 7F0593FC 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DF30 7F059400 00037400 */  sll   $t6, $v1, 0x10
/* 08DF34 7F059404 01CFC025 */  or    $t8, $t6, $t7
/* 08DF38 7F059408 24420004 */  addiu $v0, $v0, 4
/* 08DF3C 7F05940C AD780004 */  sw    $t8, 4($t3)
/* 08DF40 7F059410 AD790000 */  sw    $t9, ($t3)
/* 08DF44 7F059414 144DFFCB */  bne   $v0, $t5, .L7F059344
/* 08DF48 7F059418 24E70010 */   addiu $a3, $a3, 0x10
/* 08DF4C 7F05941C 03E00008 */  jr    $ra
/* 08DF50 7F059420 00000000 */   nop   
)
#endif

void matrix_4x4_7F059424(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f30;
    f32 temp_f2 = -1.0f / sqrtf((arg4 * arg4) + (arg5 * arg5) + (arg6 * arg6));
    arg4 *= temp_f2;
    arg5 *= temp_f2;
    arg6 *= temp_f2;
    temp_f26 = (arg8 * arg6) - (arg9 * arg5);
    temp_f28 = (arg9 * arg4) - (arg7 * arg6);
    temp_f30 = (arg7 * arg5) - (arg8 * arg4);
    temp_f2_2 = 1.0f / sqrtf((temp_f26 * temp_f26) + (temp_f28 * temp_f28) + (temp_f30 * temp_f30));
    temp_f26 *= temp_f2_2;
    temp_f28 *= temp_f2_2;
    temp_f30 *= temp_f2_2;
    arg7 = (arg5 * temp_f30) - (arg6 * temp_f28);
    arg8 = (arg6 * temp_f26) - (arg4 * temp_f30);
    arg9 = (arg4 * temp_f28) - (arg5 * temp_f26);
    temp_f2_3 = 1.0f / sqrtf((arg7 * arg7) + (arg8 * arg8) + (arg9 * arg9));
    arg7 *= temp_f2_3;
    arg8 *= temp_f2_3;
    arg9 *= temp_f2_3;
    arg0->m[0][0] = temp_f26;
    arg0->m[1][0] = temp_f28;
    arg0->m[2][0] = temp_f30;
    arg0->m[3][0] = -((arg1 * temp_f26) + (arg2 * temp_f28) + (arg3 * temp_f30));
    arg0->m[0][1] = arg7;
    arg0->m[1][1] = arg8;
    arg0->m[2][1] = arg9;
    arg0->m[3][1] = -((arg1 * arg7) + (arg2 * arg8) + (arg3 * arg9));
    arg0->m[0][2] = arg4;
    arg0->m[1][2] = arg5;
    arg0->m[2][2] = arg6;
    arg0->m[3][2] = -((arg1 * arg4) + (arg2 * arg5) + (arg3 * arg6));
    arg0->m[0][3] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void matrix_4x4_7F059694(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    matrix_4x4_7F059424(arg0, arg1, arg2, arg3, arg4 - arg1, arg5 - arg2, arg6 - arg3, arg7, arg8, arg9);
}

void matrix_4x4_7F059708(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f30;
    f32 temp_f2 = -1.0f / sqrtf((arg4 * arg4) + (arg5 * arg5) + (arg6 * arg6));
    arg4 *= temp_f2;
    arg5 *= temp_f2;
    arg6 *= temp_f2;
    temp_f26 = (arg8 * arg6) - (arg9 * arg5);
    temp_f28 = (arg9 * arg4) - (arg7 * arg6);
    temp_f30 = (arg7 * arg5) - (arg8 * arg4);
    temp_f2_2 = 1.0f / sqrtf((temp_f26 * temp_f26) + (temp_f28 * temp_f28) + (temp_f30 * temp_f30));
    temp_f26 *= temp_f2_2;
    temp_f28 *= temp_f2_2;
    temp_f30 *= temp_f2_2;
    arg7 = (arg5 * temp_f30) - (arg6 * temp_f28);
    arg8 = (arg6 * temp_f26) - (arg4 * temp_f30);
    arg9 = (arg4 * temp_f28) - (arg5 * temp_f26);
    temp_f2_3 = 1.0f / sqrtf((arg7 * arg7) + (arg8 * arg8) + (arg9 * arg9));
    arg7 *= temp_f2_3;
    arg8 *= temp_f2_3;
    arg9 *= temp_f2_3;
    arg0->m[0][0] = temp_f26;
    arg0->m[1][0] = arg7;
    arg0->m[2][0] = arg4;
    arg0->m[3][0] = arg1;
    arg0->m[0][1] = temp_f28;
    arg0->m[1][1] = arg8;
    arg0->m[2][1] = arg5;
    arg0->m[3][1] = arg2;
    arg0->m[0][2] = temp_f30;
    arg0->m[1][2] = arg9;
    arg0->m[2][2] = arg6;
    arg0->m[3][2] = arg3;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void matrix_4x4_7F059908(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    matrix_4x4_7F059708(arg0, arg1, arg2, arg3, arg4 - arg1, arg5 - arg2, arg6 - arg3, arg7, arg8, arg9);
}

#ifdef NONMATCHING
//                                                   > 8e570:    move    v0,v1
// 8e570:    jr      ra                                8e574:    jr      ra
// 8e574:    move    v0,v1                           | 8e578:    nop
u16 sub_GAME_7F05997C(f32 arg0, f32 arg1) {
    u16 phi_v1;
    f32 temp_f0 = arg0 + arg1;
    if (temp_f0 <= 2.0f)
        return -1;
    phi_v1 = (131072.0f / temp_f0);
    if (phi_v1 <= 0) 
        phi_v1 = 1;
    return phi_v1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05997C
/* 08E4AC 7F05997C 460E6000 */  add.s $f0, $f12, $f14
/* 08E4B0 7F059980 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 08E4B4 7F059984 44812000 */  mtc1  $at, $f4
/* 08E4B8 7F059988 3C014800 */  li    $at, 0x48000000 # 131072.000000
/* 08E4BC 7F05998C 4604003E */  c.le.s $f0, $f4
/* 08E4C0 7F059990 00000000 */  nop   
/* 08E4C4 7F059994 45020004 */  bc1fl .L7F0599A8
/* 08E4C8 7F059998 44813000 */   mtc1  $at, $f6
/* 08E4CC 7F05999C 03E00008 */  jr    $ra
/* 08E4D0 7F0599A0 3402FFFF */   li    $v0, 65535

/* 08E4D4 7F0599A4 44813000 */  mtc1  $at, $f6
.L7F0599A8:
/* 08E4D8 7F0599A8 24020001 */  li    $v0, 1
/* 08E4DC 7F0599AC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 08E4E0 7F0599B0 46003203 */  div.s $f8, $f6, $f0
/* 08E4E4 7F0599B4 444EF800 */  cfc1  $t6, $31
/* 08E4E8 7F0599B8 44C2F800 */  ctc1  $v0, $31
/* 08E4EC 7F0599BC 00000000 */  nop   
/* 08E4F0 7F0599C0 460042A4 */  cvt.w.s $f10, $f8
/* 08E4F4 7F0599C4 4442F800 */  cfc1  $v0, $31
/* 08E4F8 7F0599C8 00000000 */  nop   
/* 08E4FC 7F0599CC 30420078 */  andi  $v0, $v0, 0x78
/* 08E500 7F0599D0 50400013 */  beql  $v0, $zero, .L7F059A20
/* 08E504 7F0599D4 44025000 */   mfc1  $v0, $f10
/* 08E508 7F0599D8 44815000 */  mtc1  $at, $f10
/* 08E50C 7F0599DC 24020001 */  li    $v0, 1
/* 08E510 7F0599E0 460A4281 */  sub.s $f10, $f8, $f10
/* 08E514 7F0599E4 44C2F800 */  ctc1  $v0, $31
/* 08E518 7F0599E8 00000000 */  nop   
/* 08E51C 7F0599EC 460052A4 */  cvt.w.s $f10, $f10
/* 08E520 7F0599F0 4442F800 */  cfc1  $v0, $31
/* 08E524 7F0599F4 00000000 */  nop   
/* 08E528 7F0599F8 30420078 */  andi  $v0, $v0, 0x78
/* 08E52C 7F0599FC 14400005 */  bnez  $v0, .L7F059A14
/* 08E530 7F059A00 00000000 */   nop   
/* 08E534 7F059A04 44025000 */  mfc1  $v0, $f10
/* 08E538 7F059A08 3C018000 */  lui   $at, 0x8000
/* 08E53C 7F059A0C 10000007 */  b     .L7F059A2C
/* 08E540 7F059A10 00411025 */   or    $v0, $v0, $at
.L7F059A14:
/* 08E544 7F059A14 10000005 */  b     .L7F059A2C
/* 08E548 7F059A18 2402FFFF */   li    $v0, -1
/* 08E54C 7F059A1C 44025000 */  mfc1  $v0, $f10
.L7F059A20:
/* 08E550 7F059A20 00000000 */  nop   
/* 08E554 7F059A24 0440FFFB */  bltz  $v0, .L7F059A14
/* 08E558 7F059A28 00000000 */   nop   
.L7F059A2C:
/* 08E55C 7F059A2C 44CEF800 */  ctc1  $t6, $31
/* 08E560 7F059A30 304FFFFF */  andi  $t7, $v0, 0xffff
/* 08E564 7F059A34 1DE00002 */  bgtz  $t7, .L7F059A40
/* 08E568 7F059A38 3043FFFF */   andi  $v1, $v0, 0xffff
/* 08E56C 7F059A3C 24030001 */  li    $v1, 1
.L7F059A40:
/* 08E570 7F059A40 03E00008 */  jr    $ra
/* 08E574 7F059A44 00601025 */   move  $v0, $v1
)
#endif

void matrix_4x4_7F059A48(Mtxf *matrix, u16* arg1, f32 angle, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_f12_2 = cosf(angle * 0.5f) / sinf(angle * 0.5f);
    arg6 *= M_U16_MAX_VALUE_F;
    matrix->m[0][0] = ((temp_f12_2 / arg3) * arg6);
    matrix->m[1][1] = (temp_f12_2 * arg6);
    matrix->m[1][0] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[0][1] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[2][2] = (((arg4 + arg5) / (arg4 - arg5)) * arg6);
    matrix->m[3][2] = ((((arg4 + arg4) * arg5) / (arg4 - arg5)) * arg6);
    matrix->m[2][3] =  -arg6;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[3][3] = 0.0f;
    if (arg1 != 0) {
        *arg1 = sub_GAME_7F05997C(arg4, arg5);
    }
}

void matrix_4x4_7F059B58(Mtxf *matrix, f32 angle, f32 x, f32 y, f32 z) {
    f32 sine;
    f32 cosine;
    f32 norm;
    f32 invnorm;
    f32 cos_x;
    f32 sin_x;
    f32 cos_z;
    f32 sin_z;
    guNormalize(&x, &y, &z);
    sine = sinf(angle);
    cosine = cosf(angle);
    norm = sqrtf((x * x) + (z * z));
    if (norm != 0.0f) {
        cos_x = x * cosine;
        sin_x = x * sine;
        cos_z = z * cosine;
        sin_z = z * sine;
        invnorm = 1.0f / norm;
        matrix->m[0][0] = ((-cos_z - (y * sin_x)) * invnorm);
        matrix->m[1][0] = (sine * norm);
        matrix->m[2][0] = ((cos_x - (y * sin_z)) * invnorm);
        matrix->m[3][0] = 0.0f;
        matrix->m[0][1] = ((sin_z - (y * cos_x)) * invnorm);
        matrix->m[1][1] = (cosine * norm);
        matrix->m[2][1] = ((-sin_x - (y * cos_z)) * invnorm);
        matrix->m[3][1] = 0.0f;
        matrix->m[0][2] = -x;
        matrix->m[1][2] = -y;
        matrix->m[2][2] = -z;
        matrix->m[3][2] = 0.0f;
        matrix->m[0][3] = 0.0f;
        matrix->m[1][3] = 0.0f;
        matrix->m[2][3] = 0.0f;
        matrix->m[3][3] = 1.0f;
        return;
    }
    matrix_4x4_set_identity(matrix);
}

void matrix_4x4_align(Mtxf *matrix, f32 angle, f32 x, f32 y, f32 z) {
    angle = RadToDeg(angle);
    guAlignF(matrix->m, angle, x, y, z);
}

void matrix_4x4_7F059D30(u32 arg0) {
    return;
}

void matrix_4x4_set_rotation_inverse(Mtxf *rotation, Mtxf *transpose) {
    transpose->m[0][0] = rotation->m[0][0];
    transpose->m[0][1] = rotation->m[1][0];
    transpose->m[0][2] = rotation->m[2][0];
    transpose->m[1][0] = rotation->m[0][1];
    transpose->m[1][1] = rotation->m[1][1];
    transpose->m[1][2] = rotation->m[2][1];
    transpose->m[2][0] = rotation->m[0][2];
    transpose->m[2][1] = rotation->m[1][2];
    transpose->m[2][2] = rotation->m[2][2];
    transpose->m[3][0] = 0.0f;
    transpose->m[3][1] = 0.0f;
    transpose->m[3][2] = 0.0f;
    transpose->m[0][3] = 0.0f;
    transpose->m[1][3] = 0.0f;
    transpose->m[2][3] = 0.0f;
    transpose->m[3][3] = 1.0f;
}

void matrix_4x4_7F059DAC(Mtxf *arg0, Mtxf *arg1) {
    f32 temp_f0 = ((arg0->m[0][0] * arg0->m[0][0]) + (arg0->m[1][0] * arg0->m[1][0]) + (arg0->m[2][0] * arg0->m[2][0]));
    temp_f0 = 1.0f / temp_f0;
    arg1->m[0][0] = (arg0->m[0][0] * temp_f0);
    arg1->m[0][1] = (arg0->m[1][0] * temp_f0);
    arg1->m[0][2] = (arg0->m[2][0] * temp_f0);
    arg1->m[1][0] = (arg0->m[0][1] * temp_f0);
    arg1->m[1][1] = (arg0->m[1][1] * temp_f0);
    arg1->m[1][2] = (arg0->m[2][1] * temp_f0);
    arg1->m[2][0] = (arg0->m[0][2] * temp_f0);
    arg1->m[2][1] = (arg0->m[1][2] * temp_f0);
    arg1->m[2][2] = (arg0->m[2][2] * temp_f0);
    arg1->m[3][0] = 0.0f;
    arg1->m[3][1] = 0.0f;
    arg1->m[3][2] = 0.0f;
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
    arg1->m[3][3] = 1.0f;
}

void matrix_4x4_7F059E64(Mtxf *arg0, Mtxf *arg1) {
    f32 temp_f0 = (arg0->m[0][0] * arg0->m[0][0]) + (arg0->m[1][0] * arg0->m[1][0]) + (arg0->m[2][0] * arg0->m[2][0]);
    temp_f0 = 1.0f / temp_f0;
    arg1->m[0][0] = (arg0->m[0][0] * temp_f0);
    arg1->m[0][1] = (arg0->m[1][0] * temp_f0);
    arg1->m[0][2] = (arg0->m[2][0] * temp_f0);
    arg1->m[1][0] = (arg0->m[0][1] * temp_f0);
    arg1->m[1][1] = (arg0->m[1][1] * temp_f0);
    arg1->m[1][2] = (arg0->m[2][1] * temp_f0);
    arg1->m[2][0] = (arg0->m[0][2] * temp_f0);
    arg1->m[2][1] = (arg0->m[1][2] * temp_f0);
    arg1->m[2][2] = (arg0->m[2][2] * temp_f0);
    arg1->m[3][0] = -((arg1->m[0][0] * arg0->m[3][0]) + (arg1->m[1][0] * arg0->m[3][1]) + (arg1->m[2][0] * arg0->m[3][2]));
    arg1->m[3][1] = -((arg1->m[0][1] * arg0->m[3][0]) + (arg1->m[1][1] * arg0->m[3][1]) + (arg1->m[2][1] * arg0->m[3][2]));
    arg1->m[3][2] = -((arg1->m[0][2] * arg0->m[3][0]) + (arg1->m[1][2] * arg0->m[3][1]) + (arg1->m[2][2] * arg0->m[3][2]));
    arg1->m[3][3] = 1.0f;
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
}


#ifdef NONMATCHING
void sub_GAME_7F059FB8(Mtxf *arg0, Mtxf *arg1) {
    f32 temp_f0 = (arg0->m[0][0] * arg0->m[1][1] * arg0->m[2][2]) + (arg0->m[0][1] * arg0->m[1][2] * arg0->m[2][0]) + (arg0->m[0][2] * arg0->m[1][0] * arg0->m[2][1]) - (arg0->m[0][2] * arg0->m[1][1] * arg0->m[2][0]) - (arg0->m[0][1] * arg0->m[1][0] * arg0->m[2][2]) - (arg0->m[0][0] * arg0->m[1][2] * arg0->m[2][1]);
    temp_f0 = 1.0f / temp_f0;
    arg1->m[0][0] = (((arg0->m[1][1] * arg0->m[2][2]) - (arg0->m[2][1] * arg0->m[1][2])) * temp_f0);
    arg1->m[1][0] = (((arg0->m[1][2] * arg0->m[2][0]) - (arg0->m[2][2] * arg0->m[1][0])) * temp_f0);
    arg1->m[2][0] = (((arg0->m[1][0] * arg0->m[2][1]) - (arg0->m[2][0] * arg0->m[1][1])) * temp_f0);
    arg1->m[0][1] = (((arg0->m[0][2] * arg0->m[2][1]) - (arg0->m[2][2] * arg0->m[0][1])) * temp_f0);
    arg1->m[1][1] = (((arg0->m[0][0] * arg0->m[2][2]) - (arg0->m[2][0] * arg0->m[0][2])) * temp_f0);
    arg1->m[2][1] = (((arg0->m[0][1] * arg0->m[2][0]) - (arg0->m[2][1] * arg0->m[0][0])) * temp_f0);
    arg1->m[0][2] = (((arg0->m[0][1] * arg0->m[1][2]) - (arg0->m[1][1] * arg0->m[0][2])) * temp_f0);
    arg1->m[1][2] = (((arg0->m[0][2] * arg0->m[1][0]) - (arg0->m[1][2] * arg0->m[0][0])) * temp_f0);
    arg1->m[2][2] = (((arg0->m[0][0] * arg0->m[1][1]) - (arg0->m[1][0] * arg0->m[0][1])) * temp_f0);
    arg1->m[3][0] = -((arg1->m[0][0] * arg0->m[3][0]) + (arg1->m[1][0] * arg0->m[3][1]) + (arg1->m[2][0] * arg0->m[3][2]));
    arg1->m[3][1] = -((arg1->m[0][1] * arg0->m[3][0]) + (arg1->m[1][1] * arg0->m[3][1]) + (arg1->m[2][1] * arg0->m[3][2]));
    arg1->m[3][2] = -((arg1->m[0][2] * arg0->m[3][0]) + (arg1->m[1][2] * arg0->m[3][1]) + (arg1->m[2][2] * arg0->m[3][2]));
    arg1->m[3][3] = 1.0f;
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059FB8
/* 08EAE8 7F059FB8 C4820000 */  lwc1  $f2, ($a0)
/* 08EAEC 7F059FBC C48C0014 */  lwc1  $f12, 0x14($a0)
/* 08EAF0 7F059FC0 C48E0028 */  lwc1  $f14, 0x28($a0)
/* 08EAF4 7F059FC4 C4900004 */  lwc1  $f16, 4($a0)
/* 08EAF8 7F059FC8 460C1102 */  mul.s $f4, $f2, $f12
/* 08EAFC 7F059FCC C4920018 */  lwc1  $f18, 0x18($a0)
/* 08EB00 7F059FD0 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08EB04 7F059FD4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08EB08 7F059FD8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08EB0C 7F059FDC E7AA0010 */  swc1  $f10, 0x10($sp)
/* 08EB10 7F059FE0 C7A80010 */  lwc1  $f8, 0x10($sp)
/* 08EB14 7F059FE4 460E2002 */  mul.s $f0, $f4, $f14
/* 08EB18 7F059FE8 C48A0008 */  lwc1  $f10, 8($a0)
/* 08EB1C 7F059FEC 46128182 */  mul.s $f6, $f16, $f18
/* 08EB20 7F059FF0 E7AA000C */  swc1  $f10, 0xc($sp)
/* 08EB24 7F059FF4 C7AA000C */  lwc1  $f10, 0xc($sp)
/* 08EB28 7F059FF8 46083102 */  mul.s $f4, $f6, $f8
/* 08EB2C 7F059FFC C4860010 */  lwc1  $f6, 0x10($a0)
/* 08EB30 7F05A000 E7A60008 */  swc1  $f6, 8($sp)
/* 08EB34 7F05A004 C7A60008 */  lwc1  $f6, 8($sp)
/* 08EB38 7F05A008 46040000 */  add.s $f0, $f0, $f4
/* 08EB3C 7F05A00C C4840024 */  lwc1  $f4, 0x24($a0)
/* 08EB40 7F05A010 E7A80000 */  swc1  $f8, ($sp)
/* 08EB44 7F05A014 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08EB48 7F05A018 46065102 */  mul.s $f4, $f10, $f6
/* 08EB4C 7F05A01C C7A8001C */  lwc1  $f8, 0x1c($sp)
/* 08EB50 7F05A020 46082102 */  mul.s $f4, $f4, $f8
/* 08EB54 7F05A024 46040000 */  add.s $f0, $f0, $f4
/* 08EB58 7F05A028 460C5102 */  mul.s $f4, $f10, $f12
/* 08EB5C 7F05A02C C7AA0000 */  lwc1  $f10, ($sp)
/* 08EB60 7F05A030 460A2102 */  mul.s $f4, $f4, $f10
/* 08EB64 7F05A034 00000000 */  nop   
/* 08EB68 7F05A038 46068282 */  mul.s $f10, $f16, $f6
/* 08EB6C 7F05A03C 46040001 */  sub.s $f0, $f0, $f4
/* 08EB70 7F05A040 460E5102 */  mul.s $f4, $f10, $f14
/* 08EB74 7F05A044 00000000 */  nop   
/* 08EB78 7F05A048 46121182 */  mul.s $f6, $f2, $f18
/* 08EB7C 7F05A04C 44811000 */  mtc1  $at, $f2
/* 08EB80 7F05A050 46040001 */  sub.s $f0, $f0, $f4
/* 08EB84 7F05A054 46083282 */  mul.s $f10, $f6, $f8
/* 08EB88 7F05A058 460A0001 */  sub.s $f0, $f0, $f10
/* 08EB8C 7F05A05C 460E6102 */  mul.s $f4, $f12, $f14
/* 08EB90 7F05A060 00000000 */  nop   
/* 08EB94 7F05A064 46124182 */  mul.s $f6, $f8, $f18
/* 08EB98 7F05A068 46001003 */  div.s $f0, $f2, $f0
/* 08EB9C 7F05A06C 46062281 */  sub.s $f10, $f4, $f6
/* 08EBA0 7F05A070 46005202 */  mul.s $f8, $f10, $f0
/* 08EBA4 7F05A074 E4A80000 */  swc1  $f8, ($a1)
/* 08EBA8 7F05A078 C4840018 */  lwc1  $f4, 0x18($a0)
/* 08EBAC 7F05A07C C4860020 */  lwc1  $f6, 0x20($a0)
/* 08EBB0 7F05A080 C4880028 */  lwc1  $f8, 0x28($a0)
/* 08EBB4 7F05A084 46062282 */  mul.s $f10, $f4, $f6
/* 08EBB8 7F05A088 C4840010 */  lwc1  $f4, 0x10($a0)
/* 08EBBC 7F05A08C 46044182 */  mul.s $f6, $f8, $f4
/* 08EBC0 7F05A090 46065201 */  sub.s $f8, $f10, $f6
/* 08EBC4 7F05A094 46004102 */  mul.s $f4, $f8, $f0
/* 08EBC8 7F05A098 E4A40010 */  swc1  $f4, 0x10($a1)
/* 08EBCC 7F05A09C C48A0010 */  lwc1  $f10, 0x10($a0)
/* 08EBD0 7F05A0A0 C4860024 */  lwc1  $f6, 0x24($a0)
/* 08EBD4 7F05A0A4 C4840020 */  lwc1  $f4, 0x20($a0)
/* 08EBD8 7F05A0A8 46065202 */  mul.s $f8, $f10, $f6
/* 08EBDC 7F05A0AC C48A0014 */  lwc1  $f10, 0x14($a0)
/* 08EBE0 7F05A0B0 460A2182 */  mul.s $f6, $f4, $f10
/* 08EBE4 7F05A0B4 46064101 */  sub.s $f4, $f8, $f6
/* 08EBE8 7F05A0B8 46002282 */  mul.s $f10, $f4, $f0
/* 08EBEC 7F05A0BC E4AA0020 */  swc1  $f10, 0x20($a1)
/* 08EBF0 7F05A0C0 C4880008 */  lwc1  $f8, 8($a0)
/* 08EBF4 7F05A0C4 C4860024 */  lwc1  $f6, 0x24($a0)
/* 08EBF8 7F05A0C8 C48A0028 */  lwc1  $f10, 0x28($a0)
/* 08EBFC 7F05A0CC 46064102 */  mul.s $f4, $f8, $f6
/* 08EC00 7F05A0D0 C4880004 */  lwc1  $f8, 4($a0)
/* 08EC04 7F05A0D4 46085182 */  mul.s $f6, $f10, $f8
/* 08EC08 7F05A0D8 46062281 */  sub.s $f10, $f4, $f6
/* 08EC0C 7F05A0DC 46005202 */  mul.s $f8, $f10, $f0
/* 08EC10 7F05A0E0 E4A80004 */  swc1  $f8, 4($a1)
/* 08EC14 7F05A0E4 C4840000 */  lwc1  $f4, ($a0)
/* 08EC18 7F05A0E8 C4860028 */  lwc1  $f6, 0x28($a0)
/* 08EC1C 7F05A0EC C4880020 */  lwc1  $f8, 0x20($a0)
/* 08EC20 7F05A0F0 46062282 */  mul.s $f10, $f4, $f6
/* 08EC24 7F05A0F4 C4840008 */  lwc1  $f4, 8($a0)
/* 08EC28 7F05A0F8 46044182 */  mul.s $f6, $f8, $f4
/* 08EC2C 7F05A0FC 46065201 */  sub.s $f8, $f10, $f6
/* 08EC30 7F05A100 46004102 */  mul.s $f4, $f8, $f0
/* 08EC34 7F05A104 E4A40014 */  swc1  $f4, 0x14($a1)
/* 08EC38 7F05A108 C48A0004 */  lwc1  $f10, 4($a0)
/* 08EC3C 7F05A10C C4860020 */  lwc1  $f6, 0x20($a0)
/* 08EC40 7F05A110 C4840024 */  lwc1  $f4, 0x24($a0)
/* 08EC44 7F05A114 46065202 */  mul.s $f8, $f10, $f6
/* 08EC48 7F05A118 C48A0000 */  lwc1  $f10, ($a0)
/* 08EC4C 7F05A11C 460A2182 */  mul.s $f6, $f4, $f10
/* 08EC50 7F05A120 46064101 */  sub.s $f4, $f8, $f6
/* 08EC54 7F05A124 46002282 */  mul.s $f10, $f4, $f0
/* 08EC58 7F05A128 E4AA0024 */  swc1  $f10, 0x24($a1)
/* 08EC5C 7F05A12C C4880004 */  lwc1  $f8, 4($a0)
/* 08EC60 7F05A130 C4860018 */  lwc1  $f6, 0x18($a0)
/* 08EC64 7F05A134 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 08EC68 7F05A138 46064102 */  mul.s $f4, $f8, $f6
/* 08EC6C 7F05A13C C4880008 */  lwc1  $f8, 8($a0)
/* 08EC70 7F05A140 46085182 */  mul.s $f6, $f10, $f8
/* 08EC74 7F05A144 46062281 */  sub.s $f10, $f4, $f6
/* 08EC78 7F05A148 46005202 */  mul.s $f8, $f10, $f0
/* 08EC7C 7F05A14C E4A80008 */  swc1  $f8, 8($a1)
/* 08EC80 7F05A150 C4860010 */  lwc1  $f6, 0x10($a0)
/* 08EC84 7F05A154 C4840008 */  lwc1  $f4, 8($a0)
/* 08EC88 7F05A158 C4880018 */  lwc1  $f8, 0x18($a0)
/* 08EC8C 7F05A15C 46062282 */  mul.s $f10, $f4, $f6
/* 08EC90 7F05A160 C4840000 */  lwc1  $f4, ($a0)
/* 08EC94 7F05A164 46044182 */  mul.s $f6, $f8, $f4
/* 08EC98 7F05A168 46065201 */  sub.s $f8, $f10, $f6
/* 08EC9C 7F05A16C 46004102 */  mul.s $f4, $f8, $f0
/* 08ECA0 7F05A170 E4A40018 */  swc1  $f4, 0x18($a1)
/* 08ECA4 7F05A174 C4860014 */  lwc1  $f6, 0x14($a0)
/* 08ECA8 7F05A178 C48A0000 */  lwc1  $f10, ($a0)
/* 08ECAC 7F05A17C C4840010 */  lwc1  $f4, 0x10($a0)
/* 08ECB0 7F05A180 46065202 */  mul.s $f8, $f10, $f6
/* 08ECB4 7F05A184 C48A0004 */  lwc1  $f10, 4($a0)
/* 08ECB8 7F05A188 460A2182 */  mul.s $f6, $f4, $f10
/* 08ECBC 7F05A18C 46064101 */  sub.s $f4, $f8, $f6
/* 08ECC0 7F05A190 C4A60000 */  lwc1  $f6, ($a1)
/* 08ECC4 7F05A194 46002282 */  mul.s $f10, $f4, $f0
/* 08ECC8 7F05A198 44800000 */  mtc1  $zero, $f0
/* 08ECCC 7F05A19C E4AA0028 */  swc1  $f10, 0x28($a1)
/* 08ECD0 7F05A1A0 C4880030 */  lwc1  $f8, 0x30($a0)
/* 08ECD4 7F05A1A4 C48A0034 */  lwc1  $f10, 0x34($a0)
/* 08ECD8 7F05A1A8 46064102 */  mul.s $f4, $f8, $f6
/* 08ECDC 7F05A1AC C4A80010 */  lwc1  $f8, 0x10($a1)
/* 08ECE0 7F05A1B0 46085182 */  mul.s $f6, $f10, $f8
/* 08ECE4 7F05A1B4 C4A80020 */  lwc1  $f8, 0x20($a1)
/* 08ECE8 7F05A1B8 46062280 */  add.s $f10, $f4, $f6
/* 08ECEC 7F05A1BC C4840038 */  lwc1  $f4, 0x38($a0)
/* 08ECF0 7F05A1C0 46044182 */  mul.s $f6, $f8, $f4
/* 08ECF4 7F05A1C4 460A3200 */  add.s $f8, $f6, $f10
/* 08ECF8 7F05A1C8 C4AA0004 */  lwc1  $f10, 4($a1)
/* 08ECFC 7F05A1CC 46004107 */  neg.s $f4, $f8
/* 08ED00 7F05A1D0 E4A40030 */  swc1  $f4, 0x30($a1)
/* 08ED04 7F05A1D4 C4860030 */  lwc1  $f6, 0x30($a0)
/* 08ED08 7F05A1D8 C4840034 */  lwc1  $f4, 0x34($a0)
/* 08ED0C 7F05A1DC 460A3202 */  mul.s $f8, $f6, $f10
/* 08ED10 7F05A1E0 C4A60014 */  lwc1  $f6, 0x14($a1)
/* 08ED14 7F05A1E4 46062282 */  mul.s $f10, $f4, $f6
/* 08ED18 7F05A1E8 C4A60024 */  lwc1  $f6, 0x24($a1)
/* 08ED1C 7F05A1EC 460A4100 */  add.s $f4, $f8, $f10
/* 08ED20 7F05A1F0 C4880038 */  lwc1  $f8, 0x38($a0)
/* 08ED24 7F05A1F4 46083282 */  mul.s $f10, $f6, $f8
/* 08ED28 7F05A1F8 46045180 */  add.s $f6, $f10, $f4
/* 08ED2C 7F05A1FC C4A40008 */  lwc1  $f4, 8($a1)
/* 08ED30 7F05A200 46003207 */  neg.s $f8, $f6
/* 08ED34 7F05A204 E4A80034 */  swc1  $f8, 0x34($a1)
/* 08ED38 7F05A208 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 08ED3C 7F05A20C C4880034 */  lwc1  $f8, 0x34($a0)
/* 08ED40 7F05A210 46045182 */  mul.s $f6, $f10, $f4
/* 08ED44 7F05A214 C4AA0018 */  lwc1  $f10, 0x18($a1)
/* 08ED48 7F05A218 460A4102 */  mul.s $f4, $f8, $f10
/* 08ED4C 7F05A21C C4AA0028 */  lwc1  $f10, 0x28($a1)
/* 08ED50 7F05A220 46043200 */  add.s $f8, $f6, $f4
/* 08ED54 7F05A224 C4860038 */  lwc1  $f6, 0x38($a0)
/* 08ED58 7F05A228 27BD0030 */  addiu $sp, $sp, 0x30
/* 08ED5C 7F05A22C E4A2003C */  swc1  $f2, 0x3c($a1)
/* 08ED60 7F05A230 46065102 */  mul.s $f4, $f10, $f6
/* 08ED64 7F05A234 E4A0000C */  swc1  $f0, 0xc($a1)
/* 08ED68 7F05A238 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 08ED6C 7F05A23C E4A0002C */  swc1  $f0, 0x2c($a1)
/* 08ED70 7F05A240 46082280 */  add.s $f10, $f4, $f8
/* 08ED74 7F05A244 46005187 */  neg.s $f6, $f10
/* 08ED78 7F05A248 03E00008 */  jr    $ra
/* 08ED7C 7F05A24C E4A60038 */   swc1  $f6, 0x38($a1)
)
#endif

void matrix_4x4_7F05A250(Mtxf *arg0, Mtxf *arg1) {
    s32 i, j;
    f32 inv_det;
    matrix_4x4_7F05A310(arg0, arg1);
    inv_det = 1.0f / matrix_4x4_determinant(arg0);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg1->m[i][j] *= inv_det;
        }
    }
}

void matrix_4x4_7F05A310(Mtxf *arg0, Mtxf *arg1)
{
    f32 mtx00, mtx10, mtx20, mtx30;
	f32 mtx04, mtx14, mtx24, mtx34;
	f32 mtx08, mtx18, mtx28, mtx38;
	f32 mtx0c, mtx1c, mtx2c, mtx3c;

	mtx00 = arg0->m[0][0]; mtx04 = arg0->m[0][1];
	mtx08 = arg0->m[0][2]; mtx0c = arg0->m[0][3];
	mtx10 = arg0->m[1][0]; mtx14 = arg0->m[1][1];
	mtx18 = arg0->m[1][2]; mtx1c = arg0->m[1][3];
	mtx20 = arg0->m[2][0]; mtx24 = arg0->m[2][1];
	mtx28 = arg0->m[2][2]; mtx2c = arg0->m[2][3];
	mtx30 = arg0->m[3][0]; mtx34 = arg0->m[3][1];
	mtx38 = arg0->m[3][2]; mtx3c = arg0->m[3][3];

	arg1->m[0][0] =  matrix_3x3_determinant(mtx14, mtx24, mtx34, mtx18, mtx28, mtx38, mtx1c, mtx2c, mtx3c);
	arg1->m[1][0] = -matrix_3x3_determinant(mtx10, mtx20, mtx30, mtx18, mtx28, mtx38, mtx1c, mtx2c, mtx3c);
	arg1->m[2][0] =  matrix_3x3_determinant(mtx10, mtx20, mtx30, mtx14, mtx24, mtx34, mtx1c, mtx2c, mtx3c);
	arg1->m[3][0] = -matrix_3x3_determinant(mtx10, mtx20, mtx30, mtx14, mtx24, mtx34, mtx18, mtx28, mtx38);
	arg1->m[0][1] = -matrix_3x3_determinant(mtx04, mtx24, mtx34, mtx08, mtx28, mtx38, mtx0c, mtx2c, mtx3c);
	arg1->m[1][1] =  matrix_3x3_determinant(mtx00, mtx20, mtx30, mtx08, mtx28, mtx38, mtx0c, mtx2c, mtx3c);
	arg1->m[2][1] = -matrix_3x3_determinant(mtx00, mtx20, mtx30, mtx04, mtx24, mtx34, mtx0c, mtx2c, mtx3c);
	arg1->m[3][1] =  matrix_3x3_determinant(mtx00, mtx20, mtx30, mtx04, mtx24, mtx34, mtx08, mtx28, mtx38);
	arg1->m[0][2] =  matrix_3x3_determinant(mtx04, mtx14, mtx34, mtx08, mtx18, mtx38, mtx0c, mtx1c, mtx3c);
	arg1->m[1][2] = -matrix_3x3_determinant(mtx00, mtx10, mtx30, mtx08, mtx18, mtx38, mtx0c, mtx1c, mtx3c);
	arg1->m[2][2] =  matrix_3x3_determinant(mtx00, mtx10, mtx30, mtx04, mtx14, mtx34, mtx0c, mtx1c, mtx3c);
	arg1->m[3][2] = -matrix_3x3_determinant(mtx00, mtx10, mtx30, mtx04, mtx14, mtx34, mtx08, mtx18, mtx38);
	arg1->m[0][3] = -matrix_3x3_determinant(mtx04, mtx14, mtx24, mtx08, mtx18, mtx28, mtx0c, mtx1c, mtx2c);
	arg1->m[1][3] =  matrix_3x3_determinant(mtx00, mtx10, mtx20, mtx08, mtx18, mtx28, mtx0c, mtx1c, mtx2c);
	arg1->m[2][3] = -matrix_3x3_determinant(mtx00, mtx10, mtx20, mtx04, mtx14, mtx24, mtx0c, mtx1c, mtx2c);
	arg1->m[3][3] =  matrix_3x3_determinant(mtx00, mtx10, mtx20, mtx04, mtx14, mtx24, mtx08, mtx18, mtx28);
}

f32 matrix_4x4_determinant(Mtxf *matrix)
{
    f32 tmp;
	f32 sp78, sp74, sp70, sp6c;
	f32 sp68, sp64, sp60, sp5c;
	f32 sp58, sp54, sp50, sp4c;
	f32 sp48, sp44, sp40, sp3c;
	f32 sp38;
	f32 sp34;
	f32 sp30;

	sp78 = matrix->m[0][0]; sp68 = matrix->m[0][1];
	sp58 = matrix->m[0][2]; sp48 = matrix->m[0][3];
	sp74 = matrix->m[1][0]; sp64 = matrix->m[1][1];
	sp54 = matrix->m[1][2]; sp44 = matrix->m[1][3];
	sp70 = matrix->m[2][0]; sp60 = matrix->m[2][1];
	sp50 = matrix->m[2][2]; sp40 = matrix->m[2][3];
	sp6c = matrix->m[3][0]; sp5c = matrix->m[3][1];
	sp4c = matrix->m[3][2]; sp3c = matrix->m[3][3];

	sp30 = matrix_3x3_determinant(sp74, sp70, sp6c, sp64, sp60, sp5c, sp44, sp40, sp3c);
	sp34 = matrix_3x3_determinant(sp74, sp70, sp6c, sp54, sp50, sp4c, sp44, sp40, sp3c);
	sp38 = matrix_3x3_determinant(sp64, sp60, sp5c, sp54, sp50, sp4c, sp44, sp40, sp3c);

	tmp = matrix_3x3_determinant(sp74, sp70, sp6c, sp64, sp60, sp5c, sp54, sp50, sp4c);

	return (sp78 * sp38 - sp68 * sp34 + sp58 * sp30) - tmp * sp48;

}

f32 matrix_3x3_determinant(f32 a, f32 d, f32 g, f32 b, f32 e, f32 h, f32 c, f32 f, f32 i) {
    f32 determinant = (a * matrix_2x2_determinant(e, h, f, i)) - (b * matrix_2x2_determinant(d, g, f, i)) + (c * matrix_2x2_determinant(d, g, e, h));
    return determinant;
}

f32 matrix_2x2_determinant(f32 a, f32 c, f32 b, f32 d) {
     return (a * d) - (c * b);
}
