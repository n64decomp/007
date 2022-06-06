#include <ultra64.h>
#include "math_asinacos.h"
#include "math_asinfacosf.h"

f32 acosf(f32 cosinef)
{
    s16 cosines;

    if (1.0f <= cosinef) {
        cosines = 0x7FFF;
    } else if (cosinef <= -1.0f) {
        cosines = -0x7FFF;
    } else {
        cosines = (cosinef * 32767.0f);
    }

    return (acos(cosines) * 3.1415927f) / 65535.0f;
}

f32 asinf(f32 sinef)
{
    s16 sines;

    if (1.0f <= sinef) {
        sines = 0x7FFF;
    } else if (sinef <= -1.0f) {
        sines = -0x7FFF;
    } else {
        sines = (sinef * 32767.0f);
    }

    return (asin(sines) * 3.1415927f) / 65535.0f;
}
