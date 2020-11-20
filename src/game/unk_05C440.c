#include "ultra64.h"
#include "game/unk_05C440.h"


f32 sub_GAME_7F05C440(f32 arg0)
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


s32 sub_GAME_7F05C4B8(f32 arg0)
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
