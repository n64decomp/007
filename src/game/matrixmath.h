#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include <ultra64.h>
#include <bondtypes.h>

void matrix_4x4_rotate_vector_in_place(Mtxf *matrix, vec3 vector);
void matrix_4x4_7F059694(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void matrix_4x4_multiply(Mtxf *lhs, Mtxf *rhs, Mtxf *result);
void matrix_4x4_set_position(vec3 position, Mtxf *matrix);
void matrix_4x4_7F059424(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
u32 sub_GAME_7F05997C(f32 arg0, f32 arg1);
void matrix_4x4_7F05A310(Mtxf *arg0, Mtxf *arg1);

f32  matrix_4x4_determinant(Mtxf *matrix);
f32  matrix_3x3_determinant(f32 a, f32 d, f32 g, f32 b, f32 e, f32 h, f32 c, f32 f, f32 i);
f32  matrix_2x2_determinant(f32 a, f32 c, f32 b, f32 d);

void matrix_4x4_7F058C4C(f32 arg0);
void matrix_4x4_copy(Mtxf *src, Mtxf *dst);
void matrix_4x4_multiply_homogeneous(Mtxf *lhs, Mtxf *rhs, Mtxf *result);

void matrix_4x4_f32_to_s32(Mtxf *a, Mtxf *b);
void matrix_4x4_multiply_homogeneous_in_place(Mtxf *lhs, Mtxf *rhs);
void matrix_4x4_transform_vector_in_place(Mtxf *matrix, vec3 vector);
void matrix_4x4_set_identity(Mtxf *matrix);
void matrix_4x4_set_rotation_around_x(f32 angle, Mtxf *matrix);
void matrix_4x4_set_rotation_around_y(f32 angle, Mtxf *matrix);
void matrix_scalar_multiply(f32 scalar, f32 *matrix);
void matrix_4x4_7F059908(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void matrix_4x4_set_rotation_around_z(f32 angle, Mtxf *matrix);
void matrix_4x4_multiply_in_place(Mtxf *lhs, Mtxf *rhs);
void matrix_4x4_set_identity_and_position(vec3 position, Mtxf *matrix);
void matrix_column_3_scalar_multiply_2(f32 scalar, f32 *matrix);
void matrix_4x4_set_position_and_rotation_around_y(f32 *position, f32 angle, Mtxf *matrix);
void matrix_scalar_multiply_2(f32 scalar, f32 *matrix);
void matrix_4x4_set_rotation_around_xyz(vec3 angles, Mtxf *matrix);

// tenative guess
void sub_GAME_7F058E78(Mtxf *arg0, Mtxf *arg1);
void matrix_7f05842c_eu (Mtxf * src, f32 dst[3][3]);
void matrix_4x4_multiply_homogeneous_in_place_eu (f32 src[3][3], f32 dst[3][3]);

/* matrixmath_misc.h */

void sub_GAME_7F05AE00(vec3d *x, vec3d *y, f32 scaler, vec3d *result);

#endif
