#include <ultra64.h>
#include "bondtypes.h"

// rodata

f32 unkGeometry7F0B3200(coord2d *arg0, coord2d *arg1, coord2d *arg2, coord2d *arg3)
{
    f32 mult1 = arg2->f[1] - arg3->f[1];
    f32 mult2 = arg3->f[0] - arg2->f[0];
    f32 a = (arg2->f[1] - arg0->f[1]) * mult2 + (arg2->f[0] - arg0->f[0]) * mult1;
    f32 b = (arg1->f[1] - arg0->f[1]) * mult2 + (arg1->f[0] - arg0->f[0]) * mult1;

    if (b == 0.0f)
    {
        return 1.0f;
    }

    a /= b;

    if (a < 0.0f || a > 1.0f)
    {
        return 1.0f;
    }

    return a;
}


f32 sub_GAME_7F0B32D8(struct coord3d *arg0, coord2d *arg1, coord2d *arg2)
{
    f32 value2;
    f32 value1;
    f32 sp24;
    f32 mult1;
    f32 mult2;

    mult1 = arg2->x - arg0->y;
    mult2 = arg2->y - arg0->z;

    value1 = mult2 * arg1->x - mult1 * arg1->y;
    value2 = mult1 * arg1->x + mult2 * arg1->y;

    sp24 = (arg0->x - value1) * (arg0->x + value1);

    if (sp24 < 0.0f)
    {
        return 3.4028235e38f;
    }

    value2 -= sqrtf(sp24);

    if (value2 < 0.0f)
    {
        if (value2 * value2 + value1 * value1 <= arg0->x * arg0->x)
        {
            return 0.0f;
        }

        return 3.4028235e38f;
    }

    return value2;
}


f32 unkGeometry7F0B33DC(coord3d *arg0, coord2d *arg1, coord2d *arg2,coord2d *arg3)
{
    f32 spac;
    f32 spa8;
    coord2d spa0;
    f32 sp9c;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8c;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7c;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6c;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5c;
    f32 sp58;
    f32 sp54;

    spac = sqrtf(arg3->x * arg3->x + arg3->y * arg3->y);

    if (spac == 0.0f)
    {
        return 1.0f;
    }

    spa0.x = arg3->x * (1.0f / spac);
    spa0.y = arg3->y * (1.0f / spac);

    sp98 = arg2->x - arg1->x;
    sp9c = arg2->y - arg1->y;

    sp94 = sqrtf(sp98 * sp98 + sp9c * sp9c);

    if (sp94 == 0.0f)
    {
        goto handlezero;
    }

    sp90 = 1.0f / sp94;
    sp88 = sp9c * sp90;
    sp8c = -sp98 * sp90;

    sp84 = arg0->x * sp88;
    sp80 = arg0->x * sp8c;

    if (sp84 * (arg0->y - arg1->x) + sp80 * (arg0->z - arg1->y) < 0.0f)
    {
        sp84 = -sp84;
        sp80 = -sp80;
    }

    sp78 = arg1->x + sp84;
    sp7c = arg1->y + sp80;
    sp70 = arg2->x + sp84;
    sp74 = arg2->y + sp80;

    sp68 = (arg3->y * sp78) - (sp7c * arg3->x);
    sp6c = (arg0->y * arg3->y) - (arg0->z * arg3->x);
    sp64 = (arg3->y * sp70) - (sp74 * arg3->x);

    if (sp64 < sp68)
    {
        coord2d *tmp;

        spa8 = sp68;
        sp68 = sp64;
        sp64 = spa8;

        tmp = arg1;
        arg1 = arg2;
        arg2 = tmp;

        sp88 = -sp88;
        sp8c = -sp8c;
    }

    if (sp64 == sp68)
    {
        sp60 = sub_GAME_7F0B32D8(arg0, &spa0, arg1);
        sp5c = sub_GAME_7F0B32D8(arg0, &spa0, arg2);

        if (sp5c < sp60)
        {
            sp60 = sp5c;
        }
    }
    else if (sp64 < sp6c)
    {
handlezero:
        sp60 = sub_GAME_7F0B32D8(arg0, &spa0, arg2);
    }
    else if (sp6c < sp68)
    {
        sp60 = sub_GAME_7F0B32D8(arg0, &spa0, arg1);
    }
    else
    {
        sp58 = sp88 * (arg0->y - arg1->x) + sp8c * (arg0->z - arg1->y);
        sp54 = sp88 * (arg0->y + arg3->x - arg1->x) + sp8c * (arg0->z + arg3->y - arg1->y);

        if (sp58 == sp54)
        {
            return 1.0f;
        }

        sp60 = (sp58 - arg0->x) * spac / (sp58 - sp54);
    }

    if (spac < sp60)
    {
        return 1.0f;
    }

    if (sp60 < 0.0f)
    {
        return 0.0f;
    }

    return (f32) sp60 * (1.0f / spac);
}
