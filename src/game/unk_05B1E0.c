#include "ultra64.h"

typedef u16 vec3u[3];
typedef f32 vec3f[3];
typedef f32 mat44f[4][4];
typedef f32 quatf[4]; // w, x, y, z

float acosf(float);

#define M_PI 3.1415927f
#define HALF2RAD(x) (x * (M_PI / 32768.0f))

void quaternion_set_rotation_around_xyz(vec3u angles, quatf q) {
    f32 cos_x = cosf(HALF2RAD(angles[0]) * 0.5f);
    f32 sin_x = sinf(HALF2RAD(angles[0]) * 0.5f);
    f32 cos_y = cosf(HALF2RAD(angles[1]) * 0.5f);
    f32 sin_y = sinf(HALF2RAD(angles[1]) * 0.5f);
    f32 cos_z = cosf(HALF2RAD(angles[2]) * 0.5f);
    f32 sin_z = sinf(HALF2RAD(angles[2]) * 0.5f);
    f32 cos_x_cos_y = cos_x * cos_y;
    f32 cos_x_sin_y = cos_x * sin_y;
    f32 sin_x_cos_y = sin_x * cos_y;
    f32 sin_x_sin_y = sin_x * sin_y;
    q[0] = ((cos_x_cos_y * cos_z) + (sin_x_sin_y * sin_z));
    q[1] = ((sin_x_cos_y * cos_z) - (cos_x_sin_y * sin_z));
    q[2] = ((cos_x_sin_y * cos_z) + (sin_x_cos_y * sin_z));
    q[3] = ((cos_x_cos_y * sin_z) - (sin_x_sin_y * cos_z));
}

void quaternion_set_rotation_around_xyzf(vec3f angles, quatf q) {
    f32 cos_x = cosf(angles[0] * 0.5f);
    f32 sin_x = sinf(angles[0] * 0.5f);
    f32 cos_y = cosf(angles[1] * 0.5f);
    f32 sin_y = sinf(angles[1] * 0.5f);
    f32 cos_z = cosf(angles[2] * 0.5f);
    f32 sin_z = sinf(angles[2] * 0.5f);
    f32 cos_x_cos_y = cos_x * cos_y;
    f32 cos_x_sin_y = cos_x * sin_y;
    f32 sin_x_cos_y = sin_x * cos_y;
    f32 sin_x_sin_y = sin_x * sin_y;
    q[0] = (cos_x_cos_y * cos_z) + (sin_x_sin_y * sin_z);
    q[1] = (sin_x_cos_y * cos_z) - (cos_x_sin_y * sin_z);
    q[2] = (cos_x_sin_y * cos_z) + (sin_x_cos_y * sin_z);
    q[3] = (cos_x_cos_y * sin_z) - (sin_x_sin_y * cos_z);
}

void quaternion_set_rotation_around_x(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = sinf(angle * 0.5f);
    q[2] = 0.0f;
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_y(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = sinf(angle * 0.5f);
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_z(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = 0.0f;
    q[3] = sinf(angle * 0.5f);
}

void quaternion_to_matrix(quatf q, mat44f matrix) {
    f32 temp_f6 = 2.0f / ((q[0] * q[0]) + (q[1] * q[1]) + (q[2] * q[2]) +  (q[3] * q[3]));
    f32 temp_f18 = q[1] * temp_f6;
    f32 temp_f16 = q[2] * temp_f6;
    f32 temp_f14 = q[3] * temp_f6;
    f32 sp34 = q[0] * temp_f18;
    f32 sp30 = q[0] * temp_f16;
    f32 sp2C = q[0] * temp_f14;
    f32 sp28 = q[1] * temp_f18;
    f32 sp24 = q[1] * temp_f16;
    f32 sp20 = q[1] * temp_f14;
    f32 sp1C = q[2] * temp_f16;
    f32 sp18 = q[2] * temp_f14;
    f32 sp14 = q[3] * temp_f14;
    matrix[0][0] = (1.0f - (sp1C + sp14));
    matrix[0][1] = (sp24 + sp2C);
    matrix[0][2] = (sp20 - sp30);
    matrix[1][0] = (sp24 - sp2C);
    matrix[1][1] = (1.0f - (sp28 + sp14));
    matrix[1][2] = (sp18 + sp34);
    matrix[2][0] = (sp20 + sp30);
    matrix[2][1] = (sp18 - sp34);
    matrix[2][2] = (1.0f - (sp28 + sp1C));
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void quaternion_from_matrix(mat44f arg0, quatf arg1) {
    f32 var1;
    f32 var2;
    f32 trace = arg0[0][0] + arg0[1][1] + arg0[2][2] + 1.0f;
    if (0.0f < trace) {
        var1 = sqrtf(trace);
        var2 = 0.5f / var1;
        arg1[0] = var1 * 0.5f;
        arg1[1] = (arg0[1][2] - arg0[2][1]) * var2;
        arg1[2] = (arg0[2][0] - arg0[0][2]) * var2;
        arg1[3] = (arg0[0][1] - arg0[1][0]) * var2;
    } else {
        s32 i;
        s32 j;
        s32 indices[3] = {1,2,0};
        s32 k;
        i = 0;
        if (arg0[0][0] < arg0[1][1]) {
            i = 1;
        }
        if (arg0[i][i] < arg0[2][2]) {
            i = 2;
        }
        j = indices[i];
        k = indices[j];
        var1 = sqrtf(arg0[i][i] - arg0[j][j] - arg0[k][k] + 1.0f);
        var2 = 0.5f / var1;
        arg1[i + 1] = var1 * 0.5f;
        arg1[    0] = (arg0[j][k] - arg0[k][j]) * var2;
        arg1[j + 1] = (arg0[i][j] + arg0[j][i]) * var2;
        arg1[k + 1] = (arg0[i][k] + arg0[k][i]) * var2;
    }
}

void quaternion_to_transform_matrix(vec3f position, quatf rotation, mat44f matrix) {
    quaternion_to_matrix(rotation, matrix);
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
}

#define EPSILON 0.00001001f

void quaternion_slerp(quatf q1, quatf q2, f32 t, quatf result) {
    f32 dot = (q1[0] * q2[0]) + (q1[1] * q2[1]) + (q1[2] * q2[2]) + (q1[3] * q2[3]);
    f32 theta;
    f32 theta_q1;
    f32 theta_q2;
    f32 sine;
    f32 coeff_q1;
    f32 coeff_q2;
    if (dot < (-1.0f + EPSILON)) {
        result[0] = ((1.0f - t) * q1[0]) - (q2[0] * t);
        result[1] = ((1.0f - t) * q1[1]) - (q2[1] * t);
        result[2] = ((1.0f - t) * q1[2]) - (q2[2] * t);
        result[3] = ((1.0f - t) * q1[3]) - (q2[3] * t);
    }
    else if (dot <= (1.0f - EPSILON)) {
        theta = acosf(dot);
        theta_q1 = (1.0f - t) * theta;
        theta_q2 = t * theta;
        sine = sinf(theta);
        coeff_q1 = sinf(theta_q1) / sine;
        coeff_q2 = sinf(theta_q2) / sine;
        result[0] = (coeff_q1 * q1[0]) + (q2[0] * coeff_q2);
        result[1] = (coeff_q1 * q1[1]) + (q2[1] * coeff_q2);
        result[2] = (coeff_q1 * q1[2]) + (q2[2] * coeff_q2);
        result[3] = (coeff_q1 * q1[3]) + (q2[3] * coeff_q2);
    } else {
        result[0] = ((1.0f - t) * q1[0]) + (q2[0] * t);
        result[1] = ((1.0f - t) * q1[1]) + (q2[1] * t);
        result[2] = ((1.0f - t) * q1[2]) + (q2[2] * t);
        result[3] = ((1.0f - t) * q1[3]) + (q2[3] * t);
    }
}

void quaternion_7F05BC68(quatf q, f32 t, quatf result) {
    f32 phi_f12 = q[0];
    f32 phi_f16 = 1.0f;
    f32 temp_f0_2;
    f32 test2;
    f32 temp_f4;
    f32 sp20;
    f32 temp_f2;
    f32 test;
    if (q[0] < 0.0f) {
        phi_f12 = -phi_f12;
        phi_f16 = -phi_f16;
    }
    if (phi_f12 < -0.99998999f) {
        result[0] = (q[0] * t) - ((1.0f - t) * phi_f16);
        result[1] = (q[1] * t);
        result[2] = (q[2] * t);
        result[3] = (q[3] * t);
    } else if (phi_f12 <= 0.99998999f) {
        temp_f0_2 = acosf(phi_f12);
        test2 = t * temp_f0_2;
        temp_f4 = (1.0f - t) * temp_f0_2;
        sp20 = sinf(temp_f0_2);
        temp_f2 = sinf(test2) / sp20;
        test = sinf(temp_f4) / sp20;
        result[0] = (q[0] * temp_f2) + (test * phi_f16);
        result[1] = (q[1] * temp_f2);
        result[2] = (q[2] * temp_f2);
        result[3] = (q[3] * temp_f2);
    } else {
        result[0] = (q[0] * t) + ((1.0f - t) * phi_f16);
        result[1] = (q[1] * t);
        result[2] = (q[2] * t);
        result[3] = (q[3] * t);
    }
}

void quaternion_ensure_shortest_path(quatf q1, quatf q2) {
    f32 dot = (q1[0] * q2[0]) + (q1[1] * q2[1]) + (q1[2] * q2[2]) + (q1[3] * q2[3]);
    if (dot < 0.0f) {
        q2[0] = -q2[0];
        q2[1] = -q2[1];
        q2[2] = -q2[2];
        q2[3] = -q2[3];
    }
}

void quaternion_multiply(quatf lhs, quatf rhs, quatf result) {
    result[0] = (lhs[0] * rhs[0]) - (lhs[1] * rhs[1]) - (lhs[2] * rhs[2]) - (lhs[3] * rhs[3]);
    result[1] = (lhs[0] * rhs[1]) + (rhs[0] * lhs[1]) + (lhs[2] * rhs[3]) - (lhs[3] * rhs[2]);
    result[2] = (lhs[0] * rhs[2]) + (rhs[0] * lhs[2]) + (lhs[3] * rhs[1]) - (lhs[1] * rhs[3]);
    result[3] = (lhs[0] * rhs[3]) + (rhs[0] * lhs[3]) + (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
}

void quaternion_multiply_in_place(quatf lhs, quatf rhs) {
    quatf result;
    quaternion_multiply(lhs, rhs, result);
    rhs[0] = result[0];
    rhs[1] = result[1];
    rhs[2] = result[2];
    rhs[3] = result[3];
}

void quaternion_7F05BFD4(quatf q1, quatf q2) {
    f32 angle = acosf(q1[0]);
    f32 sine = sinf(angle);
    if (sine == 0.0f) {
        q2[0] = 0.0f;
        q2[1] = 0.0f;
        q2[2] = 0.0f;
        q2[3] = 0.0f;
    } else {
        q2[0] = 0.0f;
        q2[1] = (q1[1] * (angle / sine));
        q2[2] = (q1[2] * (angle / sine));
        q2[3] = (q1[3] * (angle / sine));
    }
}

void quaternion_7F05C068(quatf q1, quatf q2) {
    f32 sine;
    f32 angle = sqrtf((q1[1] * q1[1]) + (q1[2] * q1[2]) + (q1[3] * q1[3]));
    f32 unknown;
    if (angle == 0.0f) {
        q2[0] = 1.0f;
        q2[1] = 0.0f;
        q2[2] = 0.0f;
        q2[3] = 0.0f;
    } else {
        sine = sinf(angle);
        unknown = sine / angle;
        q2[0] = cosf(angle);
        q2[1] = (q1[1] * unknown);
        q2[2] = (q1[2] * unknown);
        q2[3] = (q1[3] * unknown);
    }
}

void quaternion_7F05C138(quatf arg0, quatf arg1, quatf arg2, quatf result) {
    quatf conjugate;
    quatf sp50;
    quatf sp40;
    quatf sp30;
    quatf sp20;
    conjugate[0] = arg1[0];
    conjugate[1] = -arg1[1];
    conjugate[2] = -arg1[2];
    conjugate[3] = -arg1[3];
    quaternion_multiply(conjugate, arg0, sp50);
    quaternion_multiply(conjugate, arg2, sp40);
    quaternion_7F05BFD4(sp50, sp30);
    quaternion_7F05BFD4(sp40, sp20);
    sp30[0] = -(sp30[0] + sp20[0]) * 0.25f;
    sp30[1] = -(sp30[1] + sp20[1]) * 0.25f;
    sp30[2] = -(sp30[2] + sp20[2]) * 0.25f;
    sp30[3] = -(sp30[3] + sp20[3]) * 0.25f;
    quaternion_7F05C068(sp30, sp50);
    quaternion_multiply(arg1, sp50, result);
}

void quaternion_7F05C250(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result) {
    quatf q5;
    quatf q6;
    f32 t2 = (t + t) * (1.0f - t);
    quaternion_ensure_shortest_path(q1, q4);
    quaternion_slerp(q1, q4, t, q5);
    quaternion_ensure_shortest_path(q2, q3);
    quaternion_slerp(q2, q3, t, q6);
    quaternion_ensure_shortest_path(q5, q6);
    quaternion_slerp(q5, q6, t2, result);
}

void quaternion_7F05C2F0(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result) {
    quatf q5;
    quatf q6;
    quaternion_7F05C138(q1, q2, q3, q5);
    quaternion_7F05C138(q2, q3, q4, q6);
    quaternion_7F05C250(q2, q5, q6, q3, t, result);
}
