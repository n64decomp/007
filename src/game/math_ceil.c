#include <ultra64.h>
#include "math_ceil.h"

/**
 * Math.Ceiling function for floating point value; rounds towards
 * positive infinitiy.
 * 
 * @param arg0 Value to ceiling.
 * @return Returns float. If negative or zero, truncates to integral value. If
 * positive integer, returns that value. Otherwise returns the next largest integral value.
 */
f32 ceilFloat(f32 arg0)
{
    f32 temp_f2;

    if (arg0 <= 0.0f)
    {
        return (f32) (s32) arg0;
    }

    temp_f2 = (f32) (s32) arg0;
    if (arg0 == temp_f2)
    {
        return temp_f2;
    }

    return temp_f2 + 1.0f;
}

/**
 * Math.Ceiling function for floating point value; rounds towards
 * positive infinitiy.
 * 
 * @param arg0 Value to ceiling.
 * @return Returns signed int. If negative or zero, truncates to integer. If
 * positive integer, returns that value. Otherwise returns the next largest integer.
 */
s32 ceilFloatToInt(f32 arg0)
{
    s32 temp_f8;

    if (arg0 <= 0.0f)
    {
        return (s32) arg0;
    }

    temp_f8 = (s32) arg0;
    if (arg0 == (f32) temp_f8)
    {
        return temp_f8;
    }

    return temp_f8 + 1;
}
