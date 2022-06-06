#include <ultra64.h>

/**
 * Math.Floor function for floating point value; rounds towards
 * negative infinitiy.
 * 
 * @param arg0 Value to floor.
 * @return Returns float. If non-negative, returns closest integral value toward zero. If
 * negative integer, returns that value. Otherwise returns the next lowest integral value.
 */
f32 floorFloat(f32 arg0)
{
    f32 temp_f2;

    // Truncate if greater than zero
    if (arg0 >= 0.0f)
    {
        return (f32) (s32) arg0;
    }

    // Negative value. If exact integer, return this value.
    temp_f2 = (f32) (s32) arg0;
    if (arg0 == temp_f2)
    {
        return temp_f2;
    }

    // Truncating above rounds towards a larger integer closest
    // to zero, so this is the Math.Floor part which rounds
    // towards negative infinitiy.
    return temp_f2 - 1.0f;
}

/**
 * Math.Floor function for floating point value; rounds towards
 * negative infinitiy.
 * 
 * @param arg0 Value to floor.
 * @return Returns signed int. If non-negative, returns closest integer value toward zero. If
 * negative integer, returns that value. Otherwise returns the next lowest integer value.
 */
s32 floorFloatToInt(f32 arg0)
{
    s32 temp_f8;

    // Truncate if greater than zero
    if (arg0 >= 0.0f)
    {
        return (s32) arg0;
    }

    // Negative value. If exact integer, return this value.
    temp_f8 = (s32) arg0;
    if (arg0 == (f32) temp_f8)
    {
        return temp_f8;
    }

    // Truncating above rounds towards a larger integer closest
    // to zero, so this is the Math.Floor part which rounds
    // towards negative infinitiy.
    return temp_f8 - 1;
}


