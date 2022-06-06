/**
* Isnt atan2f a libc file? 
* there doesnt seem to be any source for it (SDK or IRIX) so maybe part of cc itself?
*/

#include <ultra64.h>
#include <math.h>
#include "math_asinfacosf.h"
#include "math_atan2f.h"

f32 atan2f(f32 y, f32 x)
{
    f32 angle;
    if (y == 0.0f) {
        if (0.0f <= x) {
            angle = 0.0f;
        } else {
            angle = M_PI_F;
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
                angle = M_TAU_F - angle;
            }
        } else {
            angle = M_HALF_PI - acosf(y / angle);
            if (x < 0.0f) {
                angle = M_PI_F - angle;
            }
            if (angle < 0.0f) {
                angle += M_TAU_F;
            }
        }
    }

    return angle;
}

