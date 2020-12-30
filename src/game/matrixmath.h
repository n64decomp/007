#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include "ultra64.h"

typedef f32 vec3[3];

// Float version of a graphics matrix, which has higher precision than an Mtx.
// Matrices are stored as Mtxfs then converted to an Mtx when passed to the GPU.
// Mtxs use a union and a long long int to force alignments. Mtxfs are not
// aligned but still use the union for consistency with Mtx.
typedef union {
    f32 m[4][4];
    s32 unused;
} Mtxf;

void matrix_4x4_rotate_vector_in_place(Mtxf *matrix, vec3 vector);

#endif
