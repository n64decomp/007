#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <ultra64.h>

typedef u16 vec3u[3];
typedef f32 vec3f[3];
typedef f32 mat44f[4][4];
typedef f32 quatf[4]; // w, x, y, z

void quaternion_set_rotation_around_xyz(vec3u angles, quatf q);
void quaternion_set_rotation_around_xyzf(vec3f angles, quatf q);
void quaternion_set_rotation_around_x(f32 angle, quatf q);
void quaternion_set_rotation_around_y(f32 angle, quatf q);
void quaternion_set_rotation_around_z(f32 angle, quatf q);
void quaternion_to_matrix(quatf q, mat44f matrix);
void quaternion_from_matrix(mat44f arg0, quatf arg1);
void quaternion_to_transform_matrix(vec3f position, quatf rotation, mat44f matrix);
void quaternion_slerp(quatf q1, quatf q2, f32 t, quatf result);
void quaternion_7F05BC68(quatf q, f32 t, quatf result);
void quaternion_ensure_shortest_path(quatf q1, quatf q2);
void quaternion_multiply(quatf lhs, quatf rhs, quatf result);
void quaternion_multiply_in_place(quatf lhs, quatf rhs);
void quaternion_7F05BFD4(quatf q1, quatf q2);
void quaternion_7F05C068(quatf q1, quatf q2);
void quaternion_7F05C138(quatf arg0, quatf arg1, quatf arg2, quatf result);
void quaternion_7F05C250(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result);
void quaternion_7F05C2F0(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result);

#endif
