#include "ultra64.h"

// bss
//CODE.bss:80075DA0
f32 flt_CODE_bss_80075DA0;


// data
//D:80032310
f32 D_80032310[2] = {65536.0f, 65536.0f};

// f32 D_80032310 = 65536.0;
// //D:80032314     
// f32 D_80032314 = 65536.0;


// rodata
//D:800536F0

typedef f32 vec3[3];
typedef f32 mat44[4][4];

void matrix_4x4_set_identity(mat44 matrix) {
    matrix[0][0] = 1.0f;
    matrix[0][1] = 0.0f;
    matrix[0][2] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f;
    matrix[1][1] = 1.0f;
    matrix[1][2] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][0] = 0.0f;
    matrix[2][1] = 0.0f;
    matrix[2][2] = 1.0f;
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

void matrix_4x4_copy(mat44 src, mat44 dst) {
    s32 i;
    for (i = 0; i < 4; i++) {
        dst[i][0] = src[i][0];
        dst[i][1] = src[i][1];
        dst[i][2] = src[i][2];
        dst[i][3] = src[i][3];
    }
}

void matrix_4x4_multiply(mat44 lhs, mat44 rhs, mat44 result);

void matrix_4x4_multiply_in_place(mat44 lhs, mat44 rhs) {
    mat44 result;
    matrix_4x4_multiply(lhs, rhs, result);
    matrix_4x4_copy(result, rhs);
}

void matrix_4x4_multiply_homogeneous_in_place(mat44 lhs, mat44 rhs) {
    mat44 result;
    matrix_4x4_multiply_homogeneous(lhs, rhs, result);
    matrix_4x4_copy(result, rhs);
}

#ifdef NONMATCHING
// 8cbf8:    move    v1,zero                           8cbf8:    move    v1,zero
// 8cbfc:    move    t0,a0                           r 8cbfc:    move    t1,a0
// 8cc00:    li      t2,0x10                         r 8cc00:    li      t3,0x10
// 8cc04:    li      t1,4                            r 8cc04:    li      t2,0x40
// 8cc08:    move    v0,zero                         | 8cc08:    addu    a0,a2,v1
// 8cc0c:    addu    a0,a2,v1                        | 8cc0c:    move    a3,zero
// 8cc10:    move    a3,a1                           r 8cc10:    move    t0,a1
// 8cc14:    lwc1    $f18,0(t0)                      r 8cc14:    lwc1    $f18,0(t1)
// 8cc18:    lwc1    $f16,0(a3)                      r 8cc18:    lwc1    $f16,0(t0)
// 8cc1c:    lwc1    $f14,0x10(t0)                   r 8cc1c:    lwc1    $f14,0x10(t1)
// 8cc20:    lwc1    $f12,4(a3)                      r 8cc20:    lwc1    $f12,4(t0)
// 8cc24:    mul.s   $f16,$f18,$f16                    8cc24:    mul.s   $f16,$f18,$f16
// 8cc28:    lwc1    $f18,0x20(t0)                   r 8cc28:    lwc1    $f18,0x20(t1)
// 8cc2c:    lwc1    $f10,8(a3)                      r 8cc2c:    lwc1    $f10,8(t0)
// 8cc30:    mul.s   $f12,$f14,$f12                    8cc30:    mul.s   $f12,$f14,$f12
// 8cc34:    lwc1    $f14,0xc(a3)                    r 8cc34:    lwc1    $f14,0xc(t0)
// 8cc38:    lwc1    $f8,0x30(t0)                    r 8cc38:    lwc1    $f8,0x30(t1)
// 8cc3c:    mul.s   $f10,$f18,$f10                    8cc3c:    mul.s   $f10,$f18,$f10
// 8cc40:    addiu   v0,v0,2                         r 8cc40:    addiu   a3,a3,0x20
// 8cc44:    addiu   a0,a0,0x20                        8cc44:    addiu   a0,a0,0x20
// 8cc48:    mul.s   $f8,$f14,$f8                      8cc48:    mul.s   $f8,$f14,$f8
// 8cc4c:    addiu   a3,a3,0x20                      r 8cc4c:    addiu   t0,t0,0x20
// 8cc50:    add.s   $f12,$f16,$f12                    8cc50:    add.s   $f12,$f16,$f12
// 8cc54:    add.s   $f10,$f12,$f10                    8cc54:    add.s   $f10,$f12,$f10
// 8cc58:    add.s   $f10,$f8,$f10                     8cc58:    add.s   $f10,$f8,$f10
// 8cc5c:    swc1    $f10,-0x20(a0)                    8cc5c:    swc1    $f10,-0x20(a0)
// 8cc60:    lwc1    $f10,0(t0)                      r 8cc60:    lwc1    $f10,0(t1)
// 8cc64:    lwc1    $f8,-0x10(a3)                   r 8cc64:    lwc1    $f8,-0x10(t0)
// 8cc68:    lwc1    $f12,0x10(t0)                   r 8cc68:    lwc1    $f12,0x10(t1)
// 8cc6c:    lwc1    $f16,-0xc(a3)                   r 8cc6c:    lwc1    $f16,-0xc(t0)
// 8cc70:    mul.s   $f8,$f10,$f8                      8cc70:    mul.s   $f8,$f10,$f8
// 8cc74:    lwc1    $f10,0x20(t0)                   r 8cc74:    lwc1    $f10,0x20(t1)
// 8cc78:    lwc1    $f14,-8(a3)                     r 8cc78:    lwc1    $f14,-8(t0)
// 8cc7c:    mul.s   $f16,$f12,$f16                    8cc7c:    mul.s   $f16,$f12,$f16
// 8cc80:    lwc1    $f12,-4(a3)                     r 8cc80:    lwc1    $f12,-4(t0)
// 8cc84:    lwc1    $f18,0x30(t0)                   r 8cc84:    lwc1    $f18,0x30(t1)
// 8cc88:    mul.s   $f14,$f10,$f14                    8cc88:    mul.s   $f14,$f10,$f14
// 8cc8c:    nop                                       8cc8c:    nop
// 8cc90:    mul.s   $f18,$f12,$f18                    8cc90:    mul.s   $f18,$f12,$f18
// 8cc94:    add.s   $f16,$f8,$f16                     8cc94:    add.s   $f16,$f8,$f16
// 8cc98:    add.s   $f14,$f16,$f14                    8cc98:    add.s   $f14,$f16,$f14
// 8cc9c:    add.s   $f14,$f18,$f14                    8cc9c:    add.s   $f14,$f18,$f14
// 8cca0:    bne     v0,t1,0x8cc14 ~>                r 8cca0:    bne     a3,t2,0x8cc14 ~>
// 8cca4:    swc1    $f14,-0x10(a0)                    8cca4:    swc1    $f14,-0x10(a0)
// 8cca8:    addiu   v1,v1,4                           8cca8:    addiu   v1,v1,4
// 8ccac:    bne     v1,t2,0x8cc08 ~>                r 8ccac:    bne     v1,t3,0x8cc08 ~>
// 8ccb0:    addiu   t0,t0,4                         r 8ccb0:    addiu   t1,t1,4
// 8ccb4:    jr      ra                                8ccb4:    jr      ra
void matrix_4x4_multiply(mat44 lhs, mat44 rhs, mat44 result) {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j += 2) {
            result[j + 0][i] = lhs[0][i] * rhs[j + 0][0] + lhs[1][i] * rhs[j + 0][1] + lhs[2][i] * rhs[j + 0][2] + lhs[3][i] * rhs[j + 0][3];
            result[j + 1][i] = lhs[0][i] * rhs[j + 1][0] + lhs[1][i] * rhs[j + 1][1] + lhs[2][i] * rhs[j + 1][2] + lhs[3][i] * rhs[j + 1][3];
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_multiply
/* 08CBF8 7F0580C8 00001825 */  move  $v1, $zero
/* 08CBFC 7F0580CC 00804025 */  move  $t0, $a0
/* 08CC00 7F0580D0 240A0010 */  li    $t2, 16
/* 08CC04 7F0580D4 24090004 */  li    $t1, 4
.L7F0580D8:
/* 08CC08 7F0580D8 00001025 */  move  $v0, $zero
/* 08CC0C 7F0580DC 00C32021 */  addu  $a0, $a2, $v1
/* 08CC10 7F0580E0 00A03825 */  move  $a3, $a1
.L7F0580E4:
/* 08CC14 7F0580E4 C5120000 */  lwc1  $f18, ($t0)
/* 08CC18 7F0580E8 C4F00000 */  lwc1  $f16, ($a3)
/* 08CC1C 7F0580EC C50E0010 */  lwc1  $f14, 0x10($t0)
/* 08CC20 7F0580F0 C4EC0004 */  lwc1  $f12, 4($a3)
/* 08CC24 7F0580F4 46109402 */  mul.s $f16, $f18, $f16
/* 08CC28 7F0580F8 C5120020 */  lwc1  $f18, 0x20($t0)
/* 08CC2C 7F0580FC C4EA0008 */  lwc1  $f10, 8($a3)
/* 08CC30 7F058100 460C7302 */  mul.s $f12, $f14, $f12
/* 08CC34 7F058104 C4EE000C */  lwc1  $f14, 0xc($a3)
/* 08CC38 7F058108 C5080030 */  lwc1  $f8, 0x30($t0)
/* 08CC3C 7F05810C 460A9282 */  mul.s $f10, $f18, $f10
/* 08CC40 7F058110 24420002 */  addiu $v0, $v0, 2
/* 08CC44 7F058114 24840020 */  addiu $a0, $a0, 0x20
/* 08CC48 7F058118 46087202 */  mul.s $f8, $f14, $f8
/* 08CC4C 7F05811C 24E70020 */  addiu $a3, $a3, 0x20
/* 08CC50 7F058120 460C8300 */  add.s $f12, $f16, $f12
/* 08CC54 7F058124 460A6280 */  add.s $f10, $f12, $f10
/* 08CC58 7F058128 460A4280 */  add.s $f10, $f8, $f10
/* 08CC5C 7F05812C E48AFFE0 */  swc1  $f10, -0x20($a0)
/* 08CC60 7F058130 C50A0000 */  lwc1  $f10, ($t0)
/* 08CC64 7F058134 C4E8FFF0 */  lwc1  $f8, -0x10($a3)
/* 08CC68 7F058138 C50C0010 */  lwc1  $f12, 0x10($t0)
/* 08CC6C 7F05813C C4F0FFF4 */  lwc1  $f16, -0xc($a3)
/* 08CC70 7F058140 46085202 */  mul.s $f8, $f10, $f8
/* 08CC74 7F058144 C50A0020 */  lwc1  $f10, 0x20($t0)
/* 08CC78 7F058148 C4EEFFF8 */  lwc1  $f14, -8($a3)
/* 08CC7C 7F05814C 46106402 */  mul.s $f16, $f12, $f16
/* 08CC80 7F058150 C4ECFFFC */  lwc1  $f12, -4($a3)
/* 08CC84 7F058154 C5120030 */  lwc1  $f18, 0x30($t0)
/* 08CC88 7F058158 460E5382 */  mul.s $f14, $f10, $f14
/* 08CC8C 7F05815C 00000000 */  nop   
/* 08CC90 7F058160 46126482 */  mul.s $f18, $f12, $f18
/* 08CC94 7F058164 46104400 */  add.s $f16, $f8, $f16
/* 08CC98 7F058168 460E8380 */  add.s $f14, $f16, $f14
/* 08CC9C 7F05816C 460E9380 */  add.s $f14, $f18, $f14
/* 08CCA0 7F058170 1449FFDC */  bne   $v0, $t1, .L7F0580E4
/* 08CCA4 7F058174 E48EFFF0 */   swc1  $f14, -0x10($a0)
/* 08CCA8 7F058178 24630004 */  addiu $v1, $v1, 4
/* 08CCAC 7F05817C 146AFFD6 */  bne   $v1, $t2, .L7F0580D8
/* 08CCB0 7F058180 25080004 */   addiu $t0, $t0, 4
/* 08CCB4 7F058184 03E00008 */  jr    $ra
/* 08CCB8 7F058188 00000000 */   nop   
)
#endif

s32 matrix_4x4_multiply_homogeneous(mat44 lhs, mat44 rhs, mat44 result) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j += 2) {
            result[j + 0][i] = (lhs[0][i] * rhs[j + 0][0]) + (lhs[1][i] * rhs[j + 0][1]) + (lhs[2][i] * rhs[j + 0][2]);
            if (j == 3) {
                result[j + 0][i] += lhs[3][i];
            }
            result[j + 1][i] = (lhs[0][i] * rhs[j + 1][0]) + (lhs[1][i] * rhs[j + 1][1]) + (lhs[2][i] * rhs[j + 1][2]);
            if (j == 2) {
                result[j + 1][i] += lhs[3][i];
            }
        }
    }

    result[0][3] = 0.0f;
    result[1][3] = 0.0f;
    result[2][3] = 0.0f;
    result[3][3] = 1.0f;
}

void sub_GAME_7F058274(mat44 arg0, mat44 arg1, mat44 arg2) {
    arg2[0][0] = (arg0[0][0] * arg1[0][0]);
    arg2[1][0] = (arg0[0][0] * arg1[1][0]);
    arg2[2][0] = (arg0[0][0] * arg1[2][0]);
    arg2[3][0] = (arg0[0][0] * arg1[3][0]);
    arg2[0][1] = (arg0[1][1] * arg1[0][1]);
    arg2[1][1] = (arg0[1][1] * arg1[1][1]);
    arg2[2][1] = (arg0[1][1] * arg1[2][1]);
    arg2[3][1] = (arg0[1][1] * arg1[3][1]);
    arg2[0][2] = (arg0[2][2] * arg1[0][2]);
    arg2[1][2] = (arg0[2][2] * arg1[1][2]);
    arg2[2][2] = (arg0[2][2] * arg1[2][2]);
    arg2[3][2] = (arg0[2][2] * arg1[3][2]) + arg0[3][2];
    arg2[0][3] = (arg0[2][3] * arg1[0][2]);
    arg2[1][3] = (arg0[2][3] * arg1[1][2]);
    arg2[2][3] = (arg0[2][3] * arg1[2][2]);
    arg2[3][3] = (arg0[2][3] * arg1[3][2]);
}

void matrix_4x4_rotate_vector(mat44 matrix, vec3 vector, vec3 result) {
    s32 i;
    for (i = 0; i < 3; i++) {
        result[i] = matrix[0][i] * vector[0] + matrix[1][i] * vector[1] + matrix[2][i] * vector[2];
    }
}

void matrix_4x4_rotate_vector_in_place(mat44 matrix, vec3 vector) {
    vec3 result;
    matrix_4x4_rotate_vector(matrix, vector, result);
    vector[0] = result[0];
    vector[1] = result[1];
    vector[2] = result[2];
}

void matrix_4x4_transform_vector(mat44 matrix, vec3 vector, vec3 result) {
    matrix_4x4_rotate_vector(matrix, vector, result);
    result[0] += matrix[3][0];
    result[1] += matrix[3][1];
    result[2] += matrix[3][2];
}

void matrix_4x4_transform_vector_in_place(mat44 matrix, vec3 vector) {
    matrix_4x4_rotate_vector_in_place(matrix, vector);
    vector[0] += matrix[3][0];
    vector[1] += matrix[3][1];
    vector[2] += matrix[3][2];
}

void matrix_4x4_set_position_and_rotation_around_y(f32* position, f32 angle, mat44 matrix) {
    f32 cosine = cosf(angle);
    f32 sine = sinf(angle);
    matrix[0][0] = cosine;
    matrix[0][1] = 0.0f;
    matrix[0][2] = -sine;
    matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f;
    matrix[1][1] = 1.0f;
    matrix[1][2] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][0] = sine;
    matrix[2][1] = 0.0f;
    matrix[2][2] = cosine;
    matrix[2][3] = 0.0f;
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
    matrix[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_x(f32 angle, mat44 matrix) {
    f32 cosine = cosf(angle);
    f32 sine = sinf(angle);
    matrix[0][0] = 1.0f;
    matrix[0][1] = 0.0f;
    matrix[0][2] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f;
    matrix[1][1] = cosine;
    matrix[1][2] = sine;
    matrix[1][3] = 0.0f;
    matrix[2][0] = 0.0f;
    matrix[2][1] = -sine;
    matrix[2][2] = cosine;
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_y(f32 angle, mat44 matrix) {
    f32 cosine = cosf(angle);
    f32 sine = sinf(angle);
    matrix[0][0] = cosine;
    matrix[0][1] = 0.0f;
    matrix[0][2] = -sine;
    matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f;
    matrix[1][1] = 1.0f;
    matrix[1][2] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][0] = sine;
    matrix[2][1] = 0.0f;
    matrix[2][2] = cosine;
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

void matrix_4x4_set_rotation_around_z(f32 angle, mat44 matrix) {
    f32 cosine = cosf(angle);
    f32 sine = sinf(angle);
    matrix[0][0] = cosine;
    matrix[0][1] = sine;
    matrix[0][2] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[1][0] = -sine;
    matrix[1][1] = cosine;
    matrix[1][2] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][0] = 0.0f;
    matrix[2][1] = 0.0f;
    matrix[2][2] = 1.0f;
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

#ifdef NONMATCHING
// 8d300:    lwc1    $f10,0x54(sp)                   r 8d300:    lwc1    $f8,0x54(sp)
// 8d304:    mul.s   $f18,$f4,$f0                    r 8d304:    mul.s   $f10,$f4,$f0
// 8d308:    nop                                       8d308:    nop
// 8d30c:    mul.s   $f8,$f10,$f16                   r 8d30c:    mul.s   $f18,$f8,$f16
// 8d310:    nop                                       8d310:    nop
// 8d314:    mul.s   $f6,$f18,$f2                    r 8d314:    mul.s   $f6,$f10,$f2
// 8d318:    swc1    $f8,0x20(sp)                    r 8d318:    swc1    $f10,0x20(sp)
// 8d31c:    add.s   $f4,$f6,$f8                     r 8d31c:    add.s   $f4,$f6,$f18
// 8d320:    swc1    $f4,0x14(s0)                      8d320:    swc1    $f4,0x14(s0)
// 8d324:    lwc1    $f10,0x50(sp)                   r 8d324:    lwc1    $f8,0x50(sp)
// 8d328:    swc1    $f12,0x1c(s0)                     8d328:    swc1    $f12,0x1c(s0)
// 8d32c:    mul.s   $f6,$f10,$f14                   r 8d32c:    mul.s   $f10,$f8,$f14
// 8d330:    swc1    $f6,0x18(s0)                    r 8d330:    swc1    $f10,0x18(s0)
// 8d334:    lwc1    $f8,0x20(sp)                    | 8d334:    mul.s   $f6,$f18,$f2
// 8d338:    mul.s   $f4,$f8,$f2                     | 8d338:    lwc1    $f4,0x20(sp)
// 8d33c:    add.s   $f10,$f4,$f18                   r 8d33c:    add.s   $f8,$f6,$f4
// 8d340:    swc1    $f10,0x20(s0)                   r 8d340:    swc1    $f8,0x20(s0)
// 8d344:    lwc1    $f6,0x28(sp)                    r 8d344:    lwc1    $f10,0x28(sp)
// 8d348:    lwc1    $f4,0x24(sp)                      8d348:    lwc1    $f4,0x24(sp)
// 8d34c:    mul.s   $f8,$f6,$f2                     r 8d34c:    mul.s   $f6,$f10,$f2
// 8d350:    sub.s   $f10,$f8,$f4                    r 8d350:    sub.s   $f8,$f6,$f4
// 8d354:    mtc1    at,$f4                            8d354:    mtc1    at,$f4
// 8d358:    swc1    $f10,0x24(s0)                   r 8d358:    swc1    $f8,0x24(s0)
// 8d35c:    lwc1    $f6,0x54(sp)                    r 8d35c:    lwc1    $f10,0x54(sp)
// 8d360:    swc1    $f12,0x2c(s0)                     8d360:    swc1    $f12,0x2c(s0)
// 8d364:    swc1    $f12,0x30(s0)                     8d364:    swc1    $f12,0x30(s0)
// 8d368:    mul.s   $f8,$f6,$f14                    r 8d368:    mul.s   $f6,$f10,$f14
// 8d36c:    swc1    $f12,0x34(s0)                     8d36c:    swc1    $f12,0x34(s0)
// 8d370:    swc1    $f12,0x38(s0)                     8d370:    swc1    $f12,0x38(s0)
// 8d374:    swc1    $f4,0x3c(s0)                      8d374:    swc1    $f4,0x3c(s0)
// 8d378:    swc1    $f8,0x28(s0)                    r 8d378:    swc1    $f6,0x28(s0)
// void matrix_4x4_set_rotation_around_xyz(vec3 angles, mat44 matrix) {
//     f32 cos_x = cosf(angles[0]);
//     f32 sin_x = sinf(angles[0]);
//     f32 cos_y = cosf(angles[1]);
//     f32 sin_y = sinf(angles[1]);
//     f32 cos_z = cosf(angles[2]);
//     f32 sin_z = sinf(angles[2]);
//     f32 cos_x_cos_z = cos_x * cos_z;
//     f32 cos_x_sin_z = cos_x * sin_z;
//     f32 sin_x_cos_z = sin_x * cos_z;
//     f32 sin_x_sin_z = sin_x * sin_z;
//     matrix[0][0] = (cos_y * cos_z);
//     matrix[0][1] = (cos_y * sin_z);
//     matrix[0][2] = -sin_y;
//     matrix[0][3] = 0.0f;
//     matrix[1][0] = ((sin_x_cos_z * sin_y) - cos_x_sin_z);
//     matrix[1][1] = ((sin_x_sin_z * sin_y) + cos_x_cos_z);
//     matrix[1][2] = sin_x * cos_y;
//     matrix[1][3] = 0.0f;
//     matrix[2][0] = ((cos_x_cos_z * sin_y) + sin_x_sin_z);
//     matrix[2][1] = ((cos_x_sin_z * sin_y) - sin_x_cos_z);
//     matrix[2][2] = cos_x * cos_y;
//     matrix[2][3] = 0.0f;
//     matrix[3][0] = 0.0f;
//     matrix[3][1] = 0.0f;
//     matrix[3][2] = 0.0f;
//     matrix[3][3] = 1.0f;
// }
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_set_rotation_around_xyz
/* 08D244 7F058714 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 08D248 7F058718 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08D24C 7F05871C AFB10018 */  sw    $s1, 0x18($sp)
/* 08D250 7F058720 AFB00014 */  sw    $s0, 0x14($sp)
/* 08D254 7F058724 00A08025 */  move  $s0, $a1
/* 08D258 7F058728 00808825 */  move  $s1, $a0
/* 08D25C 7F05872C 0FC15FA8 */  jal   cosf
/* 08D260 7F058730 C48C0000 */   lwc1  $f12, ($a0)
/* 08D264 7F058734 E7A00054 */  swc1  $f0, 0x54($sp)
/* 08D268 7F058738 0FC15FAB */  jal   sinf
/* 08D26C 7F05873C C62C0000 */   lwc1  $f12, ($s1)
/* 08D270 7F058740 E7A00050 */  swc1  $f0, 0x50($sp)
/* 08D274 7F058744 0FC15FA8 */  jal   cosf
/* 08D278 7F058748 C62C0004 */   lwc1  $f12, 4($s1)
/* 08D27C 7F05874C C62C0004 */  lwc1  $f12, 4($s1)
/* 08D280 7F058750 0FC15FAB */  jal   sinf
/* 08D284 7F058754 E7A0004C */   swc1  $f0, 0x4c($sp)
/* 08D288 7F058758 C62C0008 */  lwc1  $f12, 8($s1)
/* 08D28C 7F05875C 0FC15FA8 */  jal   cosf
/* 08D290 7F058760 E7A00048 */   swc1  $f0, 0x48($sp)
/* 08D294 7F058764 C62C0008 */  lwc1  $f12, 8($s1)
/* 08D298 7F058768 0FC15FAB */  jal   sinf
/* 08D29C 7F05876C E7A00044 */   swc1  $f0, 0x44($sp)
/* 08D2A0 7F058770 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 08D2A4 7F058774 C7B00044 */  lwc1  $f16, 0x44($sp)
/* 08D2A8 7F058778 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 08D2AC 7F05877C 44806000 */  mtc1  $zero, $f12
/* 08D2B0 7F058780 46107102 */  mul.s $f4, $f14, $f16
/* 08D2B4 7F058784 46001207 */  neg.s $f8, $f2
/* 08D2B8 7F058788 E60C000C */  swc1  $f12, 0xc($s0)
/* 08D2BC 7F05878C 46007182 */  mul.s $f6, $f14, $f0
/* 08D2C0 7F058790 E6080008 */  swc1  $f8, 8($s0)
/* 08D2C4 7F058794 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D2C8 7F058798 E6040000 */  swc1  $f4, ($s0)
/* 08D2CC 7F05879C E6060004 */  swc1  $f6, 4($s0)
/* 08D2D0 7F0587A0 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08D2D4 7F0587A4 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08D2D8 7F0587A8 46105102 */  mul.s $f4, $f10, $f16
/* 08D2DC 7F0587AC 00000000 */  nop   
/* 08D2E0 7F0587B0 46003202 */  mul.s $f8, $f6, $f0
/* 08D2E4 7F0587B4 00000000 */  nop   
/* 08D2E8 7F0587B8 46022282 */  mul.s $f10, $f4, $f2
/* 08D2EC 7F0587BC E7A40024 */  swc1  $f4, 0x24($sp)
/* 08D2F0 7F0587C0 E7A80028 */  swc1  $f8, 0x28($sp)
/* 08D2F4 7F0587C4 46085181 */  sub.s $f6, $f10, $f8
/* 08D2F8 7F0587C8 E6060010 */  swc1  $f6, 0x10($s0)
/* 08D2FC 7F0587CC C7A40050 */  lwc1  $f4, 0x50($sp)
/* 08D300 7F0587D0 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 08D304 7F0587D4 46002482 */  mul.s $f18, $f4, $f0
/* 08D308 7F0587D8 00000000 */  nop   
/* 08D30C 7F0587DC 46105202 */  mul.s $f8, $f10, $f16
/* 08D310 7F0587E0 00000000 */  nop   
/* 08D314 7F0587E4 46029182 */  mul.s $f6, $f18, $f2
/* 08D318 7F0587E8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08D31C 7F0587EC 46083100 */  add.s $f4, $f6, $f8
/* 08D320 7F0587F0 E6040014 */  swc1  $f4, 0x14($s0)
/* 08D324 7F0587F4 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08D328 7F0587F8 E60C001C */  swc1  $f12, 0x1c($s0)
/* 08D32C 7F0587FC 460E5182 */  mul.s $f6, $f10, $f14
/* 08D330 7F058800 E6060018 */  swc1  $f6, 0x18($s0)
/* 08D334 7F058804 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 08D338 7F058808 46024102 */  mul.s $f4, $f8, $f2
/* 08D33C 7F05880C 46122280 */  add.s $f10, $f4, $f18
/* 08D340 7F058810 E60A0020 */  swc1  $f10, 0x20($s0)
/* 08D344 7F058814 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 08D348 7F058818 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 08D34C 7F05881C 46023202 */  mul.s $f8, $f6, $f2
/* 08D350 7F058820 46044281 */  sub.s $f10, $f8, $f4
/* 08D354 7F058824 44812000 */  mtc1  $at, $f4
/* 08D358 7F058828 E60A0024 */  swc1  $f10, 0x24($s0)
/* 08D35C 7F05882C C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08D360 7F058830 E60C002C */  swc1  $f12, 0x2c($s0)
/* 08D364 7F058834 E60C0030 */  swc1  $f12, 0x30($s0)
/* 08D368 7F058838 460E3202 */  mul.s $f8, $f6, $f14
/* 08D36C 7F05883C E60C0034 */  swc1  $f12, 0x34($s0)
/* 08D370 7F058840 E60C0038 */  swc1  $f12, 0x38($s0)
/* 08D374 7F058844 E604003C */  swc1  $f4, 0x3c($s0)
/* 08D378 7F058848 E6080028 */  swc1  $f8, 0x28($s0)
/* 08D37C 7F05884C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08D380 7F058850 8FB10018 */  lw    $s1, 0x18($sp)
/* 08D384 7F058854 8FB00014 */  lw    $s0, 0x14($sp)
/* 08D388 7F058858 03E00008 */  jr    $ra
/* 08D38C 7F05885C 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

f32 atan2f(f32, f32);

#define EPSILON 0.0000019073486f

// https://stackoverflow.com/a/15029416
void matrix_4x4_get_rotation_around_xyz(mat44 matrix, vec3 angles) {
    f32 norm;
    f32 sin_x_cos_y = matrix[1][2];
    f32 cos_x_cos_y = matrix[2][2];
    norm = sqrtf((sin_x_cos_y * sin_x_cos_y) + (cos_x_cos_y * cos_x_cos_y));
    if (EPSILON < norm) {
        angles[0] = atan2f(matrix[1][2], matrix[2][2]);
        angles[1] = atan2f(-matrix[0][2], norm);
        angles[2] = atan2f(matrix[0][1], matrix[0][0]);
    } else {
        angles[0] = 0.0f;
        angles[1] = atan2f(-matrix[0][2], norm);
        angles[2] = atan2f(-matrix[1][0], matrix[1][1]);
    }
}

void matrix_4x4_set_position(vec3 position, mat44 matrix);

void matrix_4x4_set_position_and_rotation_around_xyz(vec3 position, vec3 rotation, mat44 matrix) {
    matrix_4x4_set_rotation_around_xyz(rotation, matrix);
    matrix_4x4_set_position(position, matrix);
}

void matrix_4x4_set_identity_and_position(vec3 position, mat44 matrix) {
    matrix_4x4_set_identity(matrix);
    matrix_4x4_set_position(position, matrix);
}

void matrix_4x4_set_position(vec3 position, mat44 matrix) {
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
}

void matrix_column_1_scalar_multiply(f32 scalar, f32* matrix) {
    matrix[0] *= scalar;
    matrix[1] *= scalar;
    matrix[2] *= scalar;
}

void matrix_column_2_scalar_multiply(f32 scalar, f32* matrix) {
    matrix[4] *= scalar;
    matrix[5] *= scalar;
    matrix[6] *= scalar;
}

void matrix_column_3_scalar_multiply(f32 scalar, f32* matrix) {
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
    matrix[11] *= scalar;
}

void matrix_column_3_scalar_multiply_2(f32 scalar, f32* matrix) {
    matrix[8] *= scalar;
    matrix[9] *= scalar;
    matrix[10] *= scalar;
}

void matrix_scalar_multiply(f32 scalar, f32* matrix) {
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

void matrix_scalar_multiply_2(f32 scalar, f32* matrix) {
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

void matrix_row_3_scalar_multiply(f32 scalar, f32* matrix) {
    matrix[2] *= scalar;
    matrix[6] *= scalar;
    matrix[10] *= scalar;
    matrix[14] *= scalar;
}

void matrix_scalar_multiply_3(f32 scalar, f32* matrix) {
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

void sub_GAME_7F058C4C(f32 arg0) {
    D_80032310[0] = (65536.0f * arg0);
}

void sub_GAME_7F058C64(void) {
    flt_CODE_bss_80075DA0 = D_80032310[0];
    D_80032310[0] = 65536.0f;
}

void sub_GAME_7F058C88(void) {
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
// void sub_GAME_7F058C9C(f32* matrix, s32* result) {
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
glabel sub_GAME_7F058C9C
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





#ifdef NONMATCHING
void sub_GAME_7F059044(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059044
/* 08DB74 7F059044 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08DB78 7F059048 00803025 */  move  $a2, $a0
/* 08DB7C 7F05904C 44810000 */  mtc1  $at, $f0
/* 08DB80 7F059050 24040004 */  li    $a0, 4
/* 08DB84 7F059054 00001025 */  move  $v0, $zero
/* 08DB88 7F059058 00A01825 */  move  $v1, $a1
/* 08DB8C 7F05905C C4D00000 */  lwc1  $f16, ($a2)
/* 08DB90 7F059060 24420001 */  addiu $v0, $v0, 1
/* 08DB94 7F059064 46008482 */  mul.s $f18, $f16, $f0
/* 08DB98 7F059068 5044001F */  beql  $v0, $a0, .L7F0590E8
/* 08DB9C 7F05906C 4600940D */   trunc.w.s $f16, $f18
/* 08DBA0 7F059070 4600940D */  trunc.w.s $f16, $f18
.L7F059074:
/* 08DBA4 7F059074 24420001 */  addiu $v0, $v0, 1
/* 08DBA8 7F059078 24630010 */  addiu $v1, $v1, 0x10
/* 08DBAC 7F05907C 24C60010 */  addiu $a2, $a2, 0x10
/* 08DBB0 7F059080 440F8000 */  mfc1  $t7, $f16
/* 08DBB4 7F059084 00000000 */  nop   
/* 08DBB8 7F059088 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 08DBBC 7F05908C C4D0FFF4 */  lwc1  $f16, -0xc($a2)
/* 08DBC0 7F059090 46008402 */  mul.s $f16, $f16, $f0
/* 08DBC4 7F059094 4600840D */  trunc.w.s $f16, $f16
/* 08DBC8 7F059098 44198000 */  mfc1  $t9, $f16
/* 08DBCC 7F05909C 00000000 */  nop   
/* 08DBD0 7F0590A0 AC79FFF4 */  sw    $t9, -0xc($v1)
/* 08DBD4 7F0590A4 C4D0FFF8 */  lwc1  $f16, -8($a2)
/* 08DBD8 7F0590A8 46008402 */  mul.s $f16, $f16, $f0
/* 08DBDC 7F0590AC 4600840D */  trunc.w.s $f16, $f16
/* 08DBE0 7F0590B0 44098000 */  mfc1  $t1, $f16
/* 08DBE4 7F0590B4 00000000 */  nop   
/* 08DBE8 7F0590B8 AC69FFF8 */  sw    $t1, -8($v1)
/* 08DBEC 7F0590BC C4D0FFFC */  lwc1  $f16, -4($a2)
/* 08DBF0 7F0590C0 46008402 */  mul.s $f16, $f16, $f0
/* 08DBF4 7F0590C4 4600840D */  trunc.w.s $f16, $f16
/* 08DBF8 7F0590C8 440B8000 */  mfc1  $t3, $f16
/* 08DBFC 7F0590CC 00000000 */  nop   
/* 08DC00 7F0590D0 AC6BFFFC */  sw    $t3, -4($v1)
/* 08DC04 7F0590D4 C4D00000 */  lwc1  $f16, ($a2)
/* 08DC08 7F0590D8 46008482 */  mul.s $f18, $f16, $f0
/* 08DC0C 7F0590DC 5444FFE5 */  bnel  $v0, $a0, .L7F059074
/* 08DC10 7F0590E0 4600940D */   trunc.w.s $f16, $f18
/* 08DC14 7F0590E4 4600940D */  trunc.w.s $f16, $f18
.L7F0590E8:
/* 08DC18 7F0590E8 24630010 */  addiu $v1, $v1, 0x10
/* 08DC1C 7F0590EC 24C60010 */  addiu $a2, $a2, 0x10
/* 08DC20 7F0590F0 440F8000 */  mfc1  $t7, $f16
/* 08DC24 7F0590F4 00000000 */  nop   
/* 08DC28 7F0590F8 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 08DC2C 7F0590FC C4D0FFF4 */  lwc1  $f16, -0xc($a2)
/* 08DC30 7F059100 46008402 */  mul.s $f16, $f16, $f0
/* 08DC34 7F059104 4600840D */  trunc.w.s $f16, $f16
/* 08DC38 7F059108 44198000 */  mfc1  $t9, $f16
/* 08DC3C 7F05910C 00000000 */  nop   
/* 08DC40 7F059110 AC79FFF4 */  sw    $t9, -0xc($v1)
/* 08DC44 7F059114 C4D0FFF8 */  lwc1  $f16, -8($a2)
/* 08DC48 7F059118 46008402 */  mul.s $f16, $f16, $f0
/* 08DC4C 7F05911C 4600840D */  trunc.w.s $f16, $f16
/* 08DC50 7F059120 44098000 */  mfc1  $t1, $f16
/* 08DC54 7F059124 00000000 */  nop   
/* 08DC58 7F059128 AC69FFF8 */  sw    $t1, -8($v1)
/* 08DC5C 7F05912C C4D0FFFC */  lwc1  $f16, -4($a2)
/* 08DC60 7F059130 46008402 */  mul.s $f16, $f16, $f0
/* 08DC64 7F059134 4600840D */  trunc.w.s $f16, $f16
/* 08DC68 7F059138 440B8000 */  mfc1  $t3, $f16
/* 08DC6C 7F05913C 00000000 */  nop   
/* 08DC70 7F059140 AC6BFFFC */  sw    $t3, -4($v1)
/* 08DC74 7F059144 03E00008 */  jr    $ra
/* 08DC78 7F059148 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05914C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05914C
/* 08DC7C 7F05914C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08DC80 7F059150 00803025 */  move  $a2, $a0
/* 08DC84 7F059154 44810000 */  mtc1  $at, $f0
/* 08DC88 7F059158 24040004 */  li    $a0, 4
/* 08DC8C 7F05915C 00001025 */  move  $v0, $zero
/* 08DC90 7F059160 00A01825 */  move  $v1, $a1
/* 08DC94 7F059164 24420001 */  addiu $v0, $v0, 1
/* 08DC98 7F059168 1044001C */  beq   $v0, $a0, .L7F0591DC
/* 08DC9C 7F05916C 8CCE0000 */   lw    $t6, ($a2)
.L7F059170:
/* 08DCA0 7F059170 448E9000 */  mtc1  $t6, $f18
/* 08DCA4 7F059174 24420001 */  addiu $v0, $v0, 1
/* 08DCA8 7F059178 24630010 */  addiu $v1, $v1, 0x10
/* 08DCAC 7F05917C 468094A0 */  cvt.s.w $f18, $f18
/* 08DCB0 7F059180 24C60010 */  addiu $a2, $a2, 0x10
/* 08DCB4 7F059184 46009483 */  div.s $f18, $f18, $f0
/* 08DCB8 7F059188 E472FFF0 */  swc1  $f18, -0x10($v1)
/* 08DCBC 7F05918C 8CCFFFF4 */  lw    $t7, -0xc($a2)
/* 08DCC0 7F059190 448F9000 */  mtc1  $t7, $f18
/* 08DCC4 7F059194 00000000 */  nop   
/* 08DCC8 7F059198 468094A0 */  cvt.s.w $f18, $f18
/* 08DCCC 7F05919C 46009483 */  div.s $f18, $f18, $f0
/* 08DCD0 7F0591A0 E472FFF4 */  swc1  $f18, -0xc($v1)
/* 08DCD4 7F0591A4 8CD8FFF8 */  lw    $t8, -8($a2)
/* 08DCD8 7F0591A8 44989000 */  mtc1  $t8, $f18
/* 08DCDC 7F0591AC 00000000 */  nop   
/* 08DCE0 7F0591B0 468094A0 */  cvt.s.w $f18, $f18
/* 08DCE4 7F0591B4 46009483 */  div.s $f18, $f18, $f0
/* 08DCE8 7F0591B8 E472FFF8 */  swc1  $f18, -8($v1)
/* 08DCEC 7F0591BC 8CD9FFFC */  lw    $t9, -4($a2)
/* 08DCF0 7F0591C0 44999000 */  mtc1  $t9, $f18
/* 08DCF4 7F0591C4 00000000 */  nop   
/* 08DCF8 7F0591C8 468094A0 */  cvt.s.w $f18, $f18
/* 08DCFC 7F0591CC 46009483 */  div.s $f18, $f18, $f0
/* 08DD00 7F0591D0 E472FFFC */  swc1  $f18, -4($v1)
/* 08DD04 7F0591D4 1444FFE6 */  bne   $v0, $a0, .L7F059170
/* 08DD08 7F0591D8 8CCE0000 */   lw    $t6, ($a2)
.L7F0591DC:
/* 08DD0C 7F0591DC 448E9000 */  mtc1  $t6, $f18
/* 08DD10 7F0591E0 24630010 */  addiu $v1, $v1, 0x10
/* 08DD14 7F0591E4 24C60010 */  addiu $a2, $a2, 0x10
/* 08DD18 7F0591E8 468094A0 */  cvt.s.w $f18, $f18
/* 08DD1C 7F0591EC 46009483 */  div.s $f18, $f18, $f0
/* 08DD20 7F0591F0 E472FFF0 */  swc1  $f18, -0x10($v1)
/* 08DD24 7F0591F4 8CCFFFF4 */  lw    $t7, -0xc($a2)
/* 08DD28 7F0591F8 448F9000 */  mtc1  $t7, $f18
/* 08DD2C 7F0591FC 00000000 */  nop   
/* 08DD30 7F059200 468094A0 */  cvt.s.w $f18, $f18
/* 08DD34 7F059204 46009483 */  div.s $f18, $f18, $f0
/* 08DD38 7F059208 E472FFF4 */  swc1  $f18, -0xc($v1)
/* 08DD3C 7F05920C 8CD8FFF8 */  lw    $t8, -8($a2)
/* 08DD40 7F059210 44989000 */  mtc1  $t8, $f18
/* 08DD44 7F059214 00000000 */  nop   
/* 08DD48 7F059218 468094A0 */  cvt.s.w $f18, $f18
/* 08DD4C 7F05921C 46009483 */  div.s $f18, $f18, $f0
/* 08DD50 7F059220 E472FFF8 */  swc1  $f18, -8($v1)
/* 08DD54 7F059224 8CD9FFFC */  lw    $t9, -4($a2)
/* 08DD58 7F059228 44999000 */  mtc1  $t9, $f18
/* 08DD5C 7F05922C 00000000 */  nop   
/* 08DD60 7F059230 468094A0 */  cvt.s.w $f18, $f18
/* 08DD64 7F059234 46009483 */  div.s $f18, $f18, $f0
/* 08DD68 7F059238 E472FFFC */  swc1  $f18, -4($v1)
/* 08DD6C 7F05923C 03E00008 */  jr    $ra
/* 08DD70 7F059240 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059244(void) {

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
//typedef s32 mat4s[4][4];

//void sub_GAME_7F059334(mat4s arg0, mat4s arg1) {
//sub_GAME_7F059334(s32* arg0, s32* arg1) {  
    //s32* var1 = arg0;
    //s32* var2 = arg1;
    //for (i = 0; i < 2; i++) {
    // for (; var1 < (arg0 + 8); var1++, var2 += 4)
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

    // s32 var1;
    // s32 var2;
    // s32 i;
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
void sub_GAME_7F059334(void) {

}
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

void sub_GAME_7F059424(mat44 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
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
    arg0[0][0] = temp_f26;
    arg0[1][0] = temp_f28;
    arg0[2][0] = temp_f30;
    arg0[3][0] = -((arg1 * temp_f26) + (arg2 * temp_f28) + (arg3 * temp_f30));
    arg0[0][1] = arg7;
    arg0[1][1] = arg8;
    arg0[2][1] = arg9;
    arg0[3][1] = -((arg1 * arg7) + (arg2 * arg8) + (arg3 * arg9));
    arg0[0][2] = arg4;
    arg0[1][2] = arg5;
    arg0[2][2] = arg6;
    arg0[3][2] = -((arg1 * arg4) + (arg2 * arg5) + (arg3 * arg6));
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void sub_GAME_7F059424(mat44 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void sub_GAME_7F059694(mat44 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    sub_GAME_7F059424(arg0, arg1, arg2, arg3, arg4 - arg1, arg5 - arg2, arg6 - arg3, arg7, arg8, arg9);
}

void sub_GAME_7F059708(mat44 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
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
    arg0[0][0] = temp_f26;
    arg0[1][0] = arg7;
    arg0[2][0] = arg4;
    arg0[3][0] = arg1;
    arg0[0][1] = temp_f28;
    arg0[1][1] = arg8;
    arg0[2][1] = arg5;
    arg0[3][1] = arg2;
    arg0[0][2] = temp_f30;
    arg0[1][2] = arg9;
    arg0[2][2] = arg6;
    arg0[3][2] = arg3;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void sub_GAME_7F059908(mat44 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    sub_GAME_7F059708(arg0, arg1, arg2, arg3, arg4 - arg1, arg5 - arg2, arg6 - arg3, arg7, arg8, arg9);
}

#ifdef NONMATCHING
//<    8e568:     3043ffff        andi    v1,v0,0xffff
//---
//>    8e568:     31e3ffff        andi    v1,t7,0xffff
//57,58c57,58
//<    8e570:     03e00008        jr      ra
//<    8e574:     00601025        move    v0,v1
//---
//>    8e570:     00601025        move    v0,v1
//>    8e574:     03e00008        jr      ra
s32 sub_GAME_7F05997C(f32 arg0, f32 arg1) {
    f32 temp_f0;
    u32 temp_v0;
    s32 phi_v1;

    temp_f0 = arg0 + arg1;
    if (temp_f0 <= 2.0f) {
        return 0xFFFF;
    }
    temp_v0 = (u32) (131072.0f / temp_f0) & 0xFFFF;
    phi_v1 = temp_v0 & 0xFFFF;
    if ((s32)temp_v0 <= 0) {
        phi_v1 = 1;
    }
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

s16 sub_GAME_7F05997C(f32 arg0, f32 arg1);

void sub_GAME_7F059A48(mat44 matrix, s16* arg1, f32 angle, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_f12_2 = cosf(angle * 0.5f) / sinf(angle * 0.5f);
    arg6 *= 65536.0f;
    matrix[0][0] = ((temp_f12_2 / arg3) * arg6);
    matrix[1][1] = (temp_f12_2 * arg6);
    matrix[1][0] = 0.0f;
    matrix[2][0] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[0][1] = 0.0f;
    matrix[2][1] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[0][2] = 0.0f;
    matrix[1][2] = 0.0f;
    matrix[2][2] = (((arg4 + arg5) / (arg4 - arg5)) * arg6);
    matrix[3][2] = ((((arg4 + arg4) * arg5) / (arg4 - arg5)) * arg6);
    matrix[2][3] =  -arg6;
    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[3][3] = 0.0f;
    if (arg1 != 0) {
        *arg1 = sub_GAME_7F05997C(arg4, arg5);
    }
}

void guNormalize(f32 *x, f32 *y, f32 *z);

void sub_GAME_7F059B58(mat44 matrix, f32 angle, f32 x, f32 y, f32 z) {
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
        matrix[0][0] = ((-cos_z - (y * sin_x)) * invnorm);
        matrix[1][0] = (sine * norm);
        matrix[2][0] = ((cos_x - (y * sin_z)) * invnorm);
        matrix[3][0] = 0.0f;
        matrix[0][1] = ((sin_z - (y * cos_x)) * invnorm);
        matrix[1][1] = (cosine * norm);
        matrix[2][1] = ((-sin_x - (y * cos_z)) * invnorm);
        matrix[3][1] = 0.0f;
        matrix[0][2] = -x;
        matrix[1][2] = -y;
        matrix[2][2] = -z;
        matrix[3][2] = 0.0f;
        matrix[0][3] = 0.0f;
        matrix[1][3] = 0.0f;
        matrix[2][3] = 0.0f;
        matrix[3][3] = 1.0f;
        return;
    }
    matrix_4x4_set_identity(matrix);
}

void guAlignF(float mf[4][4], float a, float x, float y, float z);

#define RAD2DEG(x) x * 57.295776f

void matrix_4x4_align(mat44 matrix, f32 angle, f32 x, f32 y, f32 z) {
    angle = RAD2DEG(angle);
    guAlignF(matrix, angle, x, y, z);
}

void sub_GAME_7F059D30(u32 arg0) {
    return;
}

void matrix_4x4_set_rotation_inverse(mat44 rotation, mat44 transpose) {
    transpose[0][0] = rotation[0][0];
    transpose[0][1] = rotation[1][0];
    transpose[0][2] = rotation[2][0];
    transpose[1][0] = rotation[0][1];
    transpose[1][1] = rotation[1][1];
    transpose[1][2] = rotation[2][1];
    transpose[2][0] = rotation[0][2];
    transpose[2][1] = rotation[1][2];
    transpose[2][2] = rotation[2][2];
    transpose[3][0] = 0.0f;
    transpose[3][1] = 0.0f;
    transpose[3][2] = 0.0f;
    transpose[0][3] = 0.0f;
    transpose[1][3] = 0.0f;
    transpose[2][3] = 0.0f;
    transpose[3][3] = 1.0f;
}

void sub_GAME_7F059DAC(mat44 arg0, mat44 arg1) {
    f32 temp_f0 = ((arg0[0][0] * arg0[0][0]) + (arg0[1][0] * arg0[1][0]) + (arg0[2][0] * arg0[2][0]));
    temp_f0 = 1.0f / temp_f0;
    arg1[0][0] = (arg0[0][0] * temp_f0);
    arg1[0][1] = (arg0[1][0] * temp_f0);
    arg1[0][2] = (arg0[2][0] * temp_f0);
    arg1[1][0] = (arg0[0][1] * temp_f0);
    arg1[1][1] = (arg0[1][1] * temp_f0);
    arg1[1][2] = (arg0[2][1] * temp_f0);
    arg1[2][0] = (arg0[0][2] * temp_f0);
    arg1[2][1] = (arg0[1][2] * temp_f0);
    arg1[2][2] = (arg0[2][2] * temp_f0);
    arg1[3][0] = 0.0f;
    arg1[3][1] = 0.0f;
    arg1[3][2] = 0.0f;
    arg1[0][3] = 0.0f;
    arg1[1][3] = 0.0f;
    arg1[2][3] = 0.0f;
    arg1[3][3] = 1.0f;
}

void sub_GAME_7F059E64(mat44 arg0, mat44 arg1) {
    f32 temp_f0 = (arg0[0][0] * arg0[0][0]) + (arg0[1][0] * arg0[1][0]) + (arg0[2][0] * arg0[2][0]);
    temp_f0 = 1.0f / temp_f0;
    arg1[0][0] = (arg0[0][0] * temp_f0);
    arg1[0][1] = (arg0[1][0] * temp_f0);
    arg1[0][2] = (arg0[2][0] * temp_f0);
    arg1[1][0] = (arg0[0][1] * temp_f0);
    arg1[1][1] = (arg0[1][1] * temp_f0);
    arg1[1][2] = (arg0[2][1] * temp_f0);
    arg1[2][0] = (arg0[0][2] * temp_f0);
    arg1[2][1] = (arg0[1][2] * temp_f0);
    arg1[2][2] = (arg0[2][2] * temp_f0);
    arg1[3][0] = -((arg1[0][0] * arg0[3][0]) + (arg1[1][0] * arg0[3][1]) + (arg1[2][0] * arg0[3][2]));
    arg1[3][1] = -((arg1[0][1] * arg0[3][0]) + (arg1[1][1] * arg0[3][1]) + (arg1[2][1] * arg0[3][2]));
    arg1[3][2] = -((arg1[0][2] * arg0[3][0]) + (arg1[1][2] * arg0[3][1]) + (arg1[2][2] * arg0[3][2]));
    arg1[3][3] = 1.0f;
    arg1[0][3] = 0.0f;
    arg1[1][3] = 0.0f;
    arg1[2][3] = 0.0f;
}


#ifdef NONMATCHING
void sub_GAME_7F059FB8(mat44 arg0, mat44 arg1) {
    f32 temp_f0 = (arg0[0][0] * arg0[1][1] * arg0[2][2]) + (arg0[0][1] * arg0[1][2] * arg0[2][0]) + (arg0[0][2] * arg0[1][0] * arg0[2][1]) - (arg0[0][2] * arg0[1][1] * arg0[2][0]) - (arg0[0][1] * arg0[1][0] * arg0[2][2]) - (arg0[0][0] * arg0[1][2] * arg0[2][1]);
    temp_f0 = 1.0f / temp_f0;
    arg1[0][0] = (((arg0[1][1] * arg0[2][2]) - (arg0[2][1] * arg0[1][2])) * temp_f0);
    arg1[1][0] = (((arg0[1][2] * arg0[2][0]) - (arg0[2][2] * arg0[1][0])) * temp_f0);
    arg1[2][0] = (((arg0[1][0] * arg0[2][1]) - (arg0[2][0] * arg0[1][1])) * temp_f0);
    arg1[0][1] = (((arg0[0][2] * arg0[2][1]) - (arg0[2][2] * arg0[0][1])) * temp_f0);
    arg1[1][1] = (((arg0[0][0] * arg0[2][2]) - (arg0[2][0] * arg0[0][2])) * temp_f0);
    arg1[2][1] = (((arg0[0][1] * arg0[2][0]) - (arg0[2][1] * arg0[0][0])) * temp_f0);
    arg1[0][2] = (((arg0[0][1] * arg0[1][2]) - (arg0[1][1] * arg0[0][2])) * temp_f0);
    arg1[1][2] = (((arg0[0][2] * arg0[1][0]) - (arg0[1][2] * arg0[0][0])) * temp_f0);
    arg1[2][2] = (((arg0[0][0] * arg0[1][1]) - (arg0[1][0] * arg0[0][1])) * temp_f0);
    arg1[3][0] = -((arg1[0][0] * arg0[3][0]) + (arg1[1][0] * arg0[3][1]) + (arg1[2][0] * arg0[3][2]));
    arg1[3][1] = -((arg1[0][1] * arg0[3][0]) + (arg1[1][1] * arg0[3][1]) + (arg1[2][1] * arg0[3][2]));
    arg1[3][2] = -((arg1[0][2] * arg0[3][0]) + (arg1[1][2] * arg0[3][1]) + (arg1[2][2] * arg0[3][2]));
    arg1[3][3] = 1.0f;
    arg1[0][3] = 0.0f;
    arg1[1][3] = 0.0f;
    arg1[2][3] = 0.0f;
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





#ifdef NONMATCHING
void sub_GAME_7F05A250(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A250
/* 08ED80 7F05A250 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08ED84 7F05A254 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08ED88 7F05A258 AFA40018 */  sw    $a0, 0x18($sp)
/* 08ED8C 7F05A25C 0FC168C4 */  jal   sub_GAME_7F05A310
/* 08ED90 7F05A260 AFA5001C */   sw    $a1, 0x1c($sp)
/* 08ED94 7F05A264 0FC169DD */  jal   matrix_4x4_determinant
/* 08ED98 7F05A268 8FA40018 */   lw    $a0, 0x18($sp)
/* 08ED9C 7F05A26C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08EDA0 7F05A270 44812000 */  mtc1  $at, $f4
/* 08EDA4 7F05A274 00001825 */  move  $v1, $zero
/* 08EDA8 7F05A278 8FA2001C */  lw    $v0, 0x1c($sp)
/* 08EDAC 7F05A27C 24040004 */  li    $a0, 4
/* 08EDB0 7F05A280 46002083 */  div.s $f2, $f4, $f0
/* 08EDB4 7F05A284 C4480000 */  lwc1  $f8, ($v0)
/* 08EDB8 7F05A288 24630001 */  addiu $v1, $v1, 1
/* 08EDBC 7F05A28C C44E0004 */  lwc1  $f14, 4($v0)
/* 08EDC0 7F05A290 46024402 */  mul.s $f16, $f8, $f2
/* 08EDC4 7F05A294 C44C0008 */  lwc1  $f12, 8($v0)
/* 08EDC8 7F05A298 10640010 */  beq   $v1, $a0, .L7F05A2DC
/* 08EDCC 7F05A29C C452000C */   lwc1  $f18, 0xc($v0)
.L7F05A2A0:
/* 08EDD0 7F05A2A0 46027282 */  mul.s $f10, $f14, $f2
/* 08EDD4 7F05A2A4 C4480010 */  lwc1  $f8, 0x10($v0)
/* 08EDD8 7F05A2A8 C44E0014 */  lwc1  $f14, 0x14($v0)
/* 08EDDC 7F05A2AC 46026182 */  mul.s $f6, $f12, $f2
/* 08EDE0 7F05A2B0 C44C0018 */  lwc1  $f12, 0x18($v0)
/* 08EDE4 7F05A2B4 24630001 */  addiu $v1, $v1, 1
/* 08EDE8 7F05A2B8 46029102 */  mul.s $f4, $f18, $f2
/* 08EDEC 7F05A2BC C452001C */  lwc1  $f18, 0x1c($v0)
/* 08EDF0 7F05A2C0 E4500000 */  swc1  $f16, ($v0)
/* 08EDF4 7F05A2C4 46024402 */  mul.s $f16, $f8, $f2
/* 08EDF8 7F05A2C8 E44A0004 */  swc1  $f10, 4($v0)
/* 08EDFC 7F05A2CC E4460008 */  swc1  $f6, 8($v0)
/* 08EE00 7F05A2D0 24420010 */  addiu $v0, $v0, 0x10
/* 08EE04 7F05A2D4 1464FFF2 */  bne   $v1, $a0, .L7F05A2A0
/* 08EE08 7F05A2D8 E444FFFC */   swc1  $f4, -4($v0)
.L7F05A2DC:
/* 08EE0C 7F05A2DC 46027282 */  mul.s $f10, $f14, $f2
/* 08EE10 7F05A2E0 24420010 */  addiu $v0, $v0, 0x10
/* 08EE14 7F05A2E4 E450FFF0 */  swc1  $f16, -0x10($v0)
/* 08EE18 7F05A2E8 46026182 */  mul.s $f6, $f12, $f2
/* 08EE1C 7F05A2EC 00000000 */  nop   
/* 08EE20 7F05A2F0 46029102 */  mul.s $f4, $f18, $f2
/* 08EE24 7F05A2F4 E44AFFF4 */  swc1  $f10, -0xc($v0)
/* 08EE28 7F05A2F8 E446FFF8 */  swc1  $f6, -8($v0)
/* 08EE2C 7F05A2FC E444FFFC */  swc1  $f4, -4($v0)
/* 08EE30 7F05A300 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08EE34 7F05A304 27BD0018 */  addiu $sp, $sp, 0x18
/* 08EE38 7F05A308 03E00008 */  jr    $ra
/* 08EE3C 7F05A30C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A310(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A310
/* 08EE40 7F05A310 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 08EE44 7F05A314 AFBF0064 */  sw    $ra, 0x64($sp)
/* 08EE48 7F05A318 AFB00060 */  sw    $s0, 0x60($sp)
/* 08EE4C 7F05A31C F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 08EE50 7F05A320 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 08EE54 7F05A324 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 08EE58 7F05A328 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 08EE5C 7F05A32C F7B60038 */  sdc1  $f22, 0x38($sp)
/* 08EE60 7F05A330 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 08EE64 7F05A334 C4840008 */  lwc1  $f4, 8($a0)
/* 08EE68 7F05A338 C49E0004 */  lwc1  $f30, 4($a0)
/* 08EE6C 7F05A33C C49C0000 */  lwc1  $f28, ($a0)
/* 08EE70 7F05A340 E7A40084 */  swc1  $f4, 0x84($sp)
/* 08EE74 7F05A344 C486000C */  lwc1  $f6, 0xc($a0)
/* 08EE78 7F05A348 00A08025 */  move  $s0, $a1
/* 08EE7C 7F05A34C E7A60074 */  swc1  $f6, 0x74($sp)
/* 08EE80 7F05A350 C4880010 */  lwc1  $f8, 0x10($a0)
/* 08EE84 7F05A354 E7A800A0 */  swc1  $f8, 0xa0($sp)
/* 08EE88 7F05A358 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08EE8C 7F05A35C C48C0014 */  lwc1  $f12, 0x14($a0)
/* 08EE90 7F05A360 C482001C */  lwc1  $f2, 0x1c($a0)
/* 08EE94 7F05A364 C4800018 */  lwc1  $f0, 0x18($a0)
/* 08EE98 7F05A368 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 08EE9C 7F05A36C C4960034 */  lwc1  $f22, 0x34($a0)
/* 08EEA0 7F05A370 C48E0024 */  lwc1  $f14, 0x24($a0)
/* 08EEA4 7F05A374 C492002C */  lwc1  $f18, 0x2c($a0)
/* 08EEA8 7F05A378 C4900028 */  lwc1  $f16, 0x28($a0)
/* 08EEAC 7F05A37C C49A003C */  lwc1  $f26, 0x3c($a0)
/* 08EEB0 7F05A380 C4980038 */  lwc1  $f24, 0x38($a0)
/* 08EEB4 7F05A384 C4940030 */  lwc1  $f20, 0x30($a0)
/* 08EEB8 7F05A388 44070000 */  mfc1  $a3, $f0
/* 08EEBC 7F05A38C 4406B000 */  mfc1  $a2, $f22
/* 08EEC0 7F05A390 E7AC0090 */  swc1  $f12, 0x90($sp)
/* 08EEC4 7F05A394 E7A20070 */  swc1  $f2, 0x70($sp)
/* 08EEC8 7F05A398 E7A20018 */  swc1  $f2, 0x18($sp)
/* 08EECC 7F05A39C E7A00080 */  swc1  $f0, 0x80($sp)
/* 08EED0 7F05A3A0 E7AE008C */  swc1  $f14, 0x8c($sp)
/* 08EED4 7F05A3A4 E7B2006C */  swc1  $f18, 0x6c($sp)
/* 08EED8 7F05A3A8 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 08EEDC 7F05A3AC E7B0007C */  swc1  $f16, 0x7c($sp)
/* 08EEE0 7F05A3B0 E7B00010 */  swc1  $f16, 0x10($sp)
/* 08EEE4 7F05A3B4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EEE8 7F05A3B8 0FC16A4A */  jal   matrix_3x3_determinant
/* 08EEEC 7F05A3BC E7B80014 */   swc1  $f24, 0x14($sp)
/* 08EEF0 7F05A3C0 E6000000 */  swc1  $f0, ($s0)
/* 08EEF4 7F05A3C4 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08EEF8 7F05A3C8 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08EEFC 7F05A3CC C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08EF00 7F05A3D0 4406A000 */  mfc1  $a2, $f20
/* 08EF04 7F05A3D4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EF08 7F05A3D8 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EF0C 7F05A3DC 8FA70080 */  lw    $a3, 0x80($sp)
/* 08EF10 7F05A3E0 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF14 7F05A3E4 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF18 7F05A3E8 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08EF1C 7F05A3EC E7A60018 */  swc1  $f6, 0x18($sp)
/* 08EF20 7F05A3F0 0FC16A4A */  jal   matrix_3x3_determinant
/* 08EF24 7F05A3F4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08EF28 7F05A3F8 46000287 */  neg.s $f10, $f0
/* 08EF2C 7F05A3FC 4406A000 */  mfc1  $a2, $f20
/* 08EF30 7F05A400 E60A0010 */  swc1  $f10, 0x10($s0)
/* 08EF34 7F05A404 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08EF38 7F05A408 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08EF3C 7F05A40C C7A4008C */  lwc1  $f4, 0x8c($sp)
/* 08EF40 7F05A410 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EF44 7F05A414 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08EF48 7F05A418 8FA70090 */  lw    $a3, 0x90($sp)
/* 08EF4C 7F05A41C C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF50 7F05A420 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF54 7F05A424 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08EF58 7F05A428 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08EF5C 7F05A42C 0FC16A4A */  jal   matrix_3x3_determinant
/* 08EF60 7F05A430 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08EF64 7F05A434 E6000020 */  swc1  $f0, 0x20($s0)
/* 08EF68 7F05A438 C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 08EF6C 7F05A43C C7A40080 */  lwc1  $f4, 0x80($sp)
/* 08EF70 7F05A440 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 08EF74 7F05A444 4406A000 */  mfc1  $a2, $f20
/* 08EF78 7F05A448 E7B80020 */  swc1  $f24, 0x20($sp)
/* 08EF7C 7F05A44C E7B60014 */  swc1  $f22, 0x14($sp)
/* 08EF80 7F05A450 8FA70090 */  lw    $a3, 0x90($sp)
/* 08EF84 7F05A454 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF88 7F05A458 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF8C 7F05A45C E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08EF90 7F05A460 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08EF94 7F05A464 0FC16A4A */  jal   matrix_3x3_determinant
/* 08EF98 7F05A468 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08EF9C 7F05A46C 46000207 */  neg.s $f8, $f0
/* 08EFA0 7F05A470 4406B000 */  mfc1  $a2, $f22
/* 08EFA4 7F05A474 E6080030 */  swc1  $f8, 0x30($s0)
/* 08EFA8 7F05A478 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08EFAC 7F05A47C C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08EFB0 7F05A480 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 08EFB4 7F05A484 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EFB8 7F05A488 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EFBC 7F05A48C 8FA70084 */  lw    $a3, 0x84($sp)
/* 08EFC0 7F05A490 C7AE008C */  lwc1  $f14, 0x8c($sp)
/* 08EFC4 7F05A494 4600F306 */  mov.s $f12, $f30
/* 08EFC8 7F05A498 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08EFCC 7F05A49C E7A40018 */  swc1  $f4, 0x18($sp)
/* 08EFD0 7F05A4A0 0FC16A4A */  jal   matrix_3x3_determinant
/* 08EFD4 7F05A4A4 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08EFD8 7F05A4A8 46000207 */  neg.s $f8, $f0
/* 08EFDC 7F05A4AC 4406A000 */  mfc1  $a2, $f20
/* 08EFE0 7F05A4B0 E6080004 */  swc1  $f8, 4($s0)
/* 08EFE4 7F05A4B4 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08EFE8 7F05A4B8 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08EFEC 7F05A4BC C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 08EFF0 7F05A4C0 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EFF4 7F05A4C4 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EFF8 7F05A4C8 8FA70084 */  lw    $a3, 0x84($sp)
/* 08EFFC 7F05A4CC C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F000 7F05A4D0 4600E306 */  mov.s $f12, $f28
/* 08F004 7F05A4D4 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F008 7F05A4D8 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F00C 7F05A4DC 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F010 7F05A4E0 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08F014 7F05A4E4 E6000014 */  swc1  $f0, 0x14($s0)
/* 08F018 7F05A4E8 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 08F01C 7F05A4EC C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 08F020 7F05A4F0 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 08F024 7F05A4F4 4406A000 */  mfc1  $a2, $f20
/* 08F028 7F05A4F8 4407F000 */  mfc1  $a3, $f30
/* 08F02C 7F05A4FC E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F030 7F05A500 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F034 7F05A504 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F038 7F05A508 4600E306 */  mov.s $f12, $f28
/* 08F03C 7F05A50C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F040 7F05A510 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F044 7F05A514 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F048 7F05A518 E7A80010 */   swc1  $f8, 0x10($sp)
/* 08F04C 7F05A51C 46000187 */  neg.s $f6, $f0
/* 08F050 7F05A520 4406A000 */  mfc1  $a2, $f20
/* 08F054 7F05A524 E6060024 */  swc1  $f6, 0x24($s0)
/* 08F058 7F05A528 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F05C 7F05A52C C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 08F060 7F05A530 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 08F064 7F05A534 4407F000 */  mfc1  $a3, $f30
/* 08F068 7F05A538 E7B80020 */  swc1  $f24, 0x20($sp)
/* 08F06C 7F05A53C E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F070 7F05A540 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F074 7F05A544 4600E306 */  mov.s $f12, $f28
/* 08F078 7F05A548 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F07C 7F05A54C E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F080 7F05A550 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F084 7F05A554 E7A80010 */   swc1  $f8, 0x10($sp)
/* 08F088 7F05A558 E6000034 */  swc1  $f0, 0x34($s0)
/* 08F08C 7F05A55C C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 08F090 7F05A560 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 08F094 7F05A564 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F098 7F05A568 4406B000 */  mfc1  $a2, $f22
/* 08F09C 7F05A56C E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F0A0 7F05A570 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08F0A4 7F05A574 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F0A8 7F05A578 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 08F0AC 7F05A57C 4600F306 */  mov.s $f12, $f30
/* 08F0B0 7F05A580 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 08F0B4 7F05A584 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F0B8 7F05A588 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F0BC 7F05A58C E7A60010 */   swc1  $f6, 0x10($sp)
/* 08F0C0 7F05A590 E6000008 */  swc1  $f0, 8($s0)
/* 08F0C4 7F05A594 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F0C8 7F05A598 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F0CC 7F05A59C C7A40080 */  lwc1  $f4, 0x80($sp)
/* 08F0D0 7F05A5A0 4406A000 */  mfc1  $a2, $f20
/* 08F0D4 7F05A5A4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F0D8 7F05A5A8 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08F0DC 7F05A5AC 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F0E0 7F05A5B0 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F0E4 7F05A5B4 4600E306 */  mov.s $f12, $f28
/* 08F0E8 7F05A5B8 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F0EC 7F05A5BC E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F0F0 7F05A5C0 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F0F4 7F05A5C4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08F0F8 7F05A5C8 46000287 */  neg.s $f10, $f0
/* 08F0FC 7F05A5CC 4406A000 */  mfc1  $a2, $f20
/* 08F100 7F05A5D0 E60A0018 */  swc1  $f10, 0x18($s0)
/* 08F104 7F05A5D4 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F108 7F05A5D8 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F10C 7F05A5DC C7A40090 */  lwc1  $f4, 0x90($sp)
/* 08F110 7F05A5E0 4407F000 */  mfc1  $a3, $f30
/* 08F114 7F05A5E4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F118 7F05A5E8 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F11C 7F05A5EC C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F120 7F05A5F0 4600E306 */  mov.s $f12, $f28
/* 08F124 7F05A5F4 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F128 7F05A5F8 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F12C 7F05A5FC 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F130 7F05A600 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08F134 7F05A604 E6000028 */  swc1  $f0, 0x28($s0)
/* 08F138 7F05A608 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F13C 7F05A60C C7A40084 */  lwc1  $f4, 0x84($sp)
/* 08F140 7F05A610 C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 08F144 7F05A614 4406A000 */  mfc1  $a2, $f20
/* 08F148 7F05A618 4407F000 */  mfc1  $a3, $f30
/* 08F14C 7F05A61C E7B80020 */  swc1  $f24, 0x20($sp)
/* 08F150 7F05A620 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F154 7F05A624 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F158 7F05A628 4600E306 */  mov.s $f12, $f28
/* 08F15C 7F05A62C E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F160 7F05A630 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F164 7F05A634 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F168 7F05A638 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08F16C 7F05A63C 46000207 */  neg.s $f8, $f0
/* 08F170 7F05A640 4600F306 */  mov.s $f12, $f30
/* 08F174 7F05A644 E6080038 */  swc1  $f8, 0x38($s0)
/* 08F178 7F05A648 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 08F17C 7F05A64C C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F180 7F05A650 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F184 7F05A654 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 08F188 7F05A658 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 08F18C 7F05A65C C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F190 7F05A660 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F194 7F05A664 8FA6008C */  lw    $a2, 0x8c($sp)
/* 08F198 7F05A668 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 08F19C 7F05A66C E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F1A0 7F05A670 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F1A4 7F05A674 E7AA0020 */  swc1  $f10, 0x20($sp)
/* 08F1A8 7F05A678 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F1AC 7F05A67C E7A40014 */   swc1  $f4, 0x14($sp)
/* 08F1B0 7F05A680 46000107 */  neg.s $f4, $f0
/* 08F1B4 7F05A684 4600E306 */  mov.s $f12, $f28
/* 08F1B8 7F05A688 E604000C */  swc1  $f4, 0xc($s0)
/* 08F1BC 7F05A68C C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F1C0 7F05A690 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 08F1C4 7F05A694 C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 08F1C8 7F05A698 E7A60010 */  swc1  $f6, 0x10($sp)
/* 08F1CC 7F05A69C C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08F1D0 7F05A6A0 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 08F1D4 7F05A6A4 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F1D8 7F05A6A8 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F1DC 7F05A6AC C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F1E0 7F05A6B0 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F1E4 7F05A6B4 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F1E8 7F05A6B8 E7A60020 */  swc1  $f6, 0x20($sp)
/* 08F1EC 7F05A6BC 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F1F0 7F05A6C0 E7A80014 */   swc1  $f8, 0x14($sp)
/* 08F1F4 7F05A6C4 E600001C */  swc1  $f0, 0x1c($s0)
/* 08F1F8 7F05A6C8 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 08F1FC 7F05A6CC C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08F200 7F05A6D0 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08F204 7F05A6D4 E7A80010 */  swc1  $f8, 0x10($sp)
/* 08F208 7F05A6D8 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08F20C 7F05A6DC C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 08F210 7F05A6E0 4407F000 */  mfc1  $a3, $f30
/* 08F214 7F05A6E4 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F218 7F05A6E8 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F21C 7F05A6EC 4600E306 */  mov.s $f12, $f28
/* 08F220 7F05A6F0 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F224 7F05A6F4 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F228 7F05A6F8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08F22C 7F05A6FC 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F230 7F05A700 E7AA0014 */   swc1  $f10, 0x14($sp)
/* 08F234 7F05A704 46000287 */  neg.s $f10, $f0
/* 08F238 7F05A708 4407F000 */  mfc1  $a3, $f30
/* 08F23C 7F05A70C E60A002C */  swc1  $f10, 0x2c($s0)
/* 08F240 7F05A710 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 08F244 7F05A714 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 08F248 7F05A718 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 08F24C 7F05A71C E7A40010 */  swc1  $f4, 0x10($sp)
/* 08F250 7F05A720 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F254 7F05A724 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 08F258 7F05A728 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F25C 7F05A72C C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F260 7F05A730 4600E306 */  mov.s $f12, $f28
/* 08F264 7F05A734 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 08F268 7F05A738 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F26C 7F05A73C E7A40020 */  swc1  $f4, 0x20($sp)
/* 08F270 7F05A740 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F274 7F05A744 E7A60014 */   swc1  $f6, 0x14($sp)
/* 08F278 7F05A748 E600003C */  swc1  $f0, 0x3c($s0)
/* 08F27C 7F05A74C 8FBF0064 */  lw    $ra, 0x64($sp)
/* 08F280 7F05A750 8FB00060 */  lw    $s0, 0x60($sp)
/* 08F284 7F05A754 D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 08F288 7F05A758 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 08F28C 7F05A75C D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 08F290 7F05A760 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 08F294 7F05A764 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 08F298 7F05A768 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 08F29C 7F05A76C 03E00008 */  jr    $ra
/* 08F2A0 7F05A770 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif

f32 matrix_3x3_determinant(f32 m11, f32 m21, f32 m31, f32 m12, f32 m22, f32 m32, f32 m13, f32 m23, f32 m33);

 #ifdef NONMATCHING
 // Stack pointer mostly
f32 matrix_4x4_determinant(mat44 matrix) {
    f32 det;
    f32 a = matrix[0][0];
    f32 b = matrix[0][1];
    f32 c = matrix[0][2];
    f32 d = matrix[0][3];
    f32 e = matrix[1][0];
    f32 f = matrix[1][1];
    f32 g = matrix[1][2];
    f32 h = matrix[1][3];
    f32 i = matrix[2][0];
    f32 j = matrix[2][1];
    f32 k = matrix[2][2];
    f32 l = matrix[2][3];
    f32 m = matrix[3][0];
    f32 n = matrix[3][1];
    f32 o = matrix[3][2];
    f32 p = matrix[3][3];
    det = (a * matrix_3x3_determinant(f, j, n, g, k, o, h, l, p)) - (b * matrix_3x3_determinant(e, i, m, g, k, o, h, l, p)) + (c * matrix_3x3_determinant(e, i, m, f, j, n, h, l, p)) - (d * matrix_3x3_determinant(e, i, m, f, j, n, g, k, o));
    return det;
}
#else
GLOBAL_ASM(
.text
glabel matrix_4x4_determinant
/* 08F2A4 7F05A774 27BDFF80 */  addiu $sp, $sp, -0x80
/* 08F2A8 7F05A778 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08F2AC 7F05A77C C4840000 */  lwc1  $f4, ($a0)
/* 08F2B0 7F05A780 E7A40078 */  swc1  $f4, 0x78($sp)
/* 08F2B4 7F05A784 C4860004 */  lwc1  $f6, 4($a0)
/* 08F2B8 7F05A788 E7A60068 */  swc1  $f6, 0x68($sp)
/* 08F2BC 7F05A78C C4880008 */  lwc1  $f8, 8($a0)
/* 08F2C0 7F05A790 E7A80058 */  swc1  $f8, 0x58($sp)
/* 08F2C4 7F05A794 C48A000C */  lwc1  $f10, 0xc($a0)
/* 08F2C8 7F05A798 E7AA0048 */  swc1  $f10, 0x48($sp)
/* 08F2CC 7F05A79C C4840018 */  lwc1  $f4, 0x18($a0)
/* 08F2D0 7F05A7A0 C4800014 */  lwc1  $f0, 0x14($a0)
/* 08F2D4 7F05A7A4 C48C0010 */  lwc1  $f12, 0x10($a0)
/* 08F2D8 7F05A7A8 E7A40054 */  swc1  $f4, 0x54($sp)
/* 08F2DC 7F05A7AC C4860028 */  lwc1  $f6, 0x28($a0)
/* 08F2E0 7F05A7B0 C482001C */  lwc1  $f2, 0x1c($a0)
/* 08F2E4 7F05A7B4 C4900024 */  lwc1  $f16, 0x24($a0)
/* 08F2E8 7F05A7B8 C48E0020 */  lwc1  $f14, 0x20($a0)
/* 08F2EC 7F05A7BC E7A60050 */  swc1  $f6, 0x50($sp)
/* 08F2F0 7F05A7C0 C4880030 */  lwc1  $f8, 0x30($a0)
/* 08F2F4 7F05A7C4 C492002C */  lwc1  $f18, 0x2c($a0)
/* 08F2F8 7F05A7C8 44070000 */  mfc1  $a3, $f0
/* 08F2FC 7F05A7CC E7A8006C */  swc1  $f8, 0x6c($sp)
/* 08F300 7F05A7D0 C48A0034 */  lwc1  $f10, 0x34($a0)
/* 08F304 7F05A7D4 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F308 7F05A7D8 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 08F30C 7F05A7DC C4840038 */  lwc1  $f4, 0x38($a0)
/* 08F310 7F05A7E0 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 08F314 7F05A7E4 E7A4004C */  swc1  $f4, 0x4c($sp)
/* 08F318 7F05A7E8 C486003C */  lwc1  $f6, 0x3c($a0)
/* 08F31C 7F05A7EC E7A00064 */  swc1  $f0, 0x64($sp)
/* 08F320 7F05A7F0 E7AC0074 */  swc1  $f12, 0x74($sp)
/* 08F324 7F05A7F4 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 08F328 7F05A7F8 C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 08F32C 7F05A7FC E7A20044 */  swc1  $f2, 0x44($sp)
/* 08F330 7F05A800 E7A20018 */  swc1  $f2, 0x18($sp)
/* 08F334 7F05A804 E7B00060 */  swc1  $f16, 0x60($sp)
/* 08F338 7F05A808 E7B00010 */  swc1  $f16, 0x10($sp)
/* 08F33C 7F05A80C E7AE0070 */  swc1  $f14, 0x70($sp)
/* 08F340 7F05A810 E7B20040 */  swc1  $f18, 0x40($sp)
/* 08F344 7F05A814 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 08F348 7F05A818 E7A80014 */  swc1  $f8, 0x14($sp)
/* 08F34C 7F05A81C 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F350 7F05A820 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08F354 7F05A824 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 08F358 7F05A828 C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 08F35C 7F05A82C C7A80044 */  lwc1  $f8, 0x44($sp)
/* 08F360 7F05A830 E7A40010 */  swc1  $f4, 0x10($sp)
/* 08F364 7F05A834 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08F368 7F05A838 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 08F36C 7F05A83C E7A00030 */  swc1  $f0, 0x30($sp)
/* 08F370 7F05A840 C7AC0074 */  lwc1  $f12, 0x74($sp)
/* 08F374 7F05A844 C7AE0070 */  lwc1  $f14, 0x70($sp)
/* 08F378 7F05A848 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F37C 7F05A84C 8FA70054 */  lw    $a3, 0x54($sp)
/* 08F380 7F05A850 E7A60014 */  swc1  $f6, 0x14($sp)
/* 08F384 7F05A854 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F388 7F05A858 E7A40020 */  swc1  $f4, 0x20($sp)
/* 08F38C 7F05A85C 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F390 7F05A860 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 08F394 7F05A864 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 08F398 7F05A868 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08F39C 7F05A86C C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 08F3A0 7F05A870 E7A60010 */  swc1  $f6, 0x10($sp)
/* 08F3A4 7F05A874 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 08F3A8 7F05A878 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 08F3AC 7F05A87C E7A00034 */  swc1  $f0, 0x34($sp)
/* 08F3B0 7F05A880 C7AC0064 */  lwc1  $f12, 0x64($sp)
/* 08F3B4 7F05A884 C7AE0060 */  lwc1  $f14, 0x60($sp)
/* 08F3B8 7F05A888 8FA6005C */  lw    $a2, 0x5c($sp)
/* 08F3BC 7F05A88C 8FA70054 */  lw    $a3, 0x54($sp)
/* 08F3C0 7F05A890 E7A80014 */  swc1  $f8, 0x14($sp)
/* 08F3C4 7F05A894 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F3C8 7F05A898 E7A60020 */  swc1  $f6, 0x20($sp)
/* 08F3CC 7F05A89C 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F3D0 7F05A8A0 E7A4001C */   swc1  $f4, 0x1c($sp)
/* 08F3D4 7F05A8A4 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 08F3D8 7F05A8A8 C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 08F3DC 7F05A8AC C7A40054 */  lwc1  $f4, 0x54($sp)
/* 08F3E0 7F05A8B0 E7A80010 */  swc1  $f8, 0x10($sp)
/* 08F3E4 7F05A8B4 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08F3E8 7F05A8B8 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 08F3EC 7F05A8BC E7A00038 */  swc1  $f0, 0x38($sp)
/* 08F3F0 7F05A8C0 C7AC0074 */  lwc1  $f12, 0x74($sp)
/* 08F3F4 7F05A8C4 C7AE0070 */  lwc1  $f14, 0x70($sp)
/* 08F3F8 7F05A8C8 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F3FC 7F05A8CC 8FA70064 */  lw    $a3, 0x64($sp)
/* 08F400 7F05A8D0 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 08F404 7F05A8D4 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F408 7F05A8D8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08F40C 7F05A8DC 0FC16A4A */  jal   matrix_3x3_determinant
/* 08F410 7F05A8E0 E7A6001C */   swc1  $f6, 0x1c($sp)
/* 08F414 7F05A8E4 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 08F418 7F05A8E8 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 08F41C 7F05A8EC C7A80068 */  lwc1  $f8, 0x68($sp)
/* 08F420 7F05A8F0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08F424 7F05A8F4 46045182 */  mul.s $f6, $f10, $f4
/* 08F428 7F05A8F8 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 08F42C 7F05A8FC 460A4102 */  mul.s $f4, $f8, $f10
/* 08F430 7F05A900 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 08F434 7F05A904 46043201 */  sub.s $f8, $f6, $f4
/* 08F438 7F05A908 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 08F43C 7F05A90C 46065102 */  mul.s $f4, $f10, $f6
/* 08F440 7F05A910 C7A60048 */  lwc1  $f6, 0x48($sp)
/* 08F444 7F05A914 27BD0080 */  addiu $sp, $sp, 0x80
/* 08F448 7F05A918 46044280 */  add.s $f10, $f8, $f4
/* 08F44C 7F05A91C 46060202 */  mul.s $f8, $f0, $f6
/* 08F450 7F05A920 03E00008 */  jr    $ra
/* 08F454 7F05A924 46085001 */   sub.s $f0, $f10, $f8
)
#endif


f32 matrix_2x2_determinant(f32 a, f32 c, f32 b, f32 d);

f32 matrix_3x3_determinant(f32 a, f32 d, f32 g, f32 b, f32 e, f32 h, f32 c, f32 f, f32 i) {
    f32 determinant = (a * matrix_2x2_determinant(e, h, f, i)) - (b * matrix_2x2_determinant(d, g, f, i)) + (c * matrix_2x2_determinant(d, g, e, h));
    return determinant;
}

f32 matrix_2x2_determinant(f32 a, f32 c, f32 b, f32 d) {
     return (a * d) - (c * b);
}