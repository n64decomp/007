#include "ultra64.h"

#define M_PI 3.1415927f
#define M_HALF_PI M_PI / 2
#define M_THREE_HALF_PI 3 * M_HALF_PI
#define M_TAU 2 * M_PI

f32 acosf(f32);

f32 atan2f(f32 y, f32 x) {
    f32 angle;
    if (y == 0.0f) {
        if (0.0f <= x) {
            angle = 0.0f;
        } else {
            angle = M_PI;
        }
    } else if (x == 0.0f) {
        if (0.0f < y) {
            angle = M_HALF_PI;
        } else {
            angle = M_THREE_HALF_PI;
        }
    } else {
        angle = sqrtf((y * y) + (x * x));
        if (x < y) {
            angle = acosf(x / angle);
            if (y < 0.0f) {
                angle = M_TAU - angle;
            }
        } else {
            angle = M_HALF_PI - acosf(y / angle);
            if (x < 0.0f) {
                angle = M_PI - angle;
            }
            if (angle < 0.0f) {
                angle += M_TAU;
            }
        }
    }
    return angle;
}

