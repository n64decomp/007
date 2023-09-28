#include <ultra64.h>
#include "math.h"
#include "bondconstants.h"
#include "bondtypes.h"
#include "random.h"
#include "matrixmath.h"

//D:80032300
coord3d ZeroCoord = { 0, 0, 0 };


void mtxLoadRandomRotation(Mtxf *mtx)
{
	coord3d coord;
    coord = ZeroCoord;
#if defined(LEFTOVERDEBUG)
	coord.x = RANDOMFRAC() * M_TAU_F * 0.03125f - 0.09817477f;
	coord.y = RANDOMFRAC() * M_TAU_F * 0.03125f - 0.09817477f;
	coord.z = RANDOMFRAC() * M_TAU_F * 0.03125f - 0.09817477f;
#else
	coord.x = RANDOMFRAC() * 7.53982257f * 0.03125f - 0.11780973f;
	coord.y = RANDOMFRAC() * 7.53982257f * 0.03125f - 0.11780973f;
	coord.z = RANDOMFRAC() * 7.53982257f * 0.03125f - 0.11780973f;
#endif
	matrix_4x4_set_rotation_around_xyz(&coord, mtx);
}


void sub_GAME_7F057C14(coord3d *coord, Mtxf *mtx)
{
	coord->x = RANDOMFRAC() * 1.6666666f * 4.0f - 3.3333333f;
	coord->y = RANDOMFRAC() * 1.6666666f * 4.0f;
	coord->z = RANDOMFRAC() * 1.6666666f * 4.0f - 3.3333333f;

	mtxLoadRandomRotation(mtx);
}


void sub_GAME_7F057D44(f32* arg0, f32* arg1, f32 arg2)
{
    f32 temp_f0;
    f32 temp_f2;
    temp_f0 = *arg1;
    temp_f2 = temp_f0;
    temp_f0 = temp_f2 - (arg2 * 0.2777778f);
    *arg0 += (arg2 * (temp_f2 + temp_f0)) * 0.5f;
    *arg1 = temp_f0;
}


void sub_GAME_7F057D88(f32* arg0, f32* arg1, f32 arg2)
{
    sub_GAME_7F057D44(arg0 + 1, arg1 + 1, arg2);
    arg0[0] += (arg2 * arg1[0]);
    arg0[2] += (arg2 * arg1[2]);
}


void sub_GAME_7F057DF8(struct Mtxf *arg0, struct Mtxf *arg1, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++) {
        matrix_4x4_multiply_homogeneous_in_place(arg1, arg0);
    }
}


void sub_GAME_7F057E58(f32* arg0, f32* arg1, struct Mtxf* arg2, struct Mtxf* arg3, s32 arg4)
{
    sub_GAME_7F057D88(arg0, arg1, (f32) arg4);
    sub_GAME_7F057DF8(arg2, arg3, arg4);
}