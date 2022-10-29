#include <ultra64.h>


void sub_GAME_7F06ABB0(Gfx **gdlptr, f32 *arg1, f32 *arg2, s32 width, s32 height, s32 arg5, s32 arg6, s32 arg7)
{
    if (arg2[0] > 0.0f && arg2[1] > 0.0f)
    {
        Gfx *gdl = *gdlptr;
        s32 xl;
        s32 yl;
        s32 xh;
        s32 yh;
        s32 s = 0;
        s32 t = 0;
        s32 dsdx;
        s32 dtdy;

        gDPSetTexturePersp(gdl++, G_TP_NONE);

        xl = (arg1[0] - arg2[0]) * 4.0f;
        yl = (arg1[1] - arg2[1]) * 4.0f;
        xh = (arg1[0] + arg2[0]) * 4.0f;
        yh = (arg1[1] + arg2[1]) * 4.0f;

        if (xh >= 0 && yh >= 0)
        {
            if (xl < 0)
            {
                if (arg5)
                {
                    t += ((-xl * height) << 5) / (xh - xl);
                }
                else
                {
                    s += ((-xl * width) << 5) / (xh - xl);
                }

                xl = 0;
            }

            if (yl < 0)
            {
                if (arg5)
                {
                    s += ((-yl * width) << 5) / (yh - yl);
                }
                else
                {
                    t += ((-yl * height) << 5) / (yh - yl);
                }

                yl = 0;
            }

            if (arg5)
            {
                dsdx = width / (2.0f * arg2[1]) * 1024.0f;
                dtdy = height / (2.0f * arg2[0]) * 1024.0f;
            }
            else
            {
                dsdx = width / (2.0f * arg2[0]) * 1024.0f;
                dtdy = height / (2.0f * arg2[1]) * 1024.0f;
            }

            if (arg6)
            {
                dsdx = 0x10000 - dsdx;
                s = ((width - 1) << 5) - s;
            }

            if (arg7)
            {
                dtdy = 0x10000 - dtdy;
                t = ((height - 1) << 5) - t;
            }

            if (arg5)
            {
                gSPTextureRectangleFlip(gdl++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy);
            }
            else
            {
                gSPTextureRectangle(gdl++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy);
            }
        }

        gDPSetTexturePersp(gdl++, G_TP_PERSP);

        *gdlptr = gdl;
    }
}


void display_image_at_on_screen_coord(Gfx **gdlptr, f32 *arg1, f32 *arg2, s32 twidth, u32 theight, u32 arg5, u32 arg6, u32 arg7, u32 r, u32 g, u32 b, u32 alpha, u32 arg12, u32 arg13)
{
    if (arg2[0] > 0.0f && arg2[1] > 0.0f)
    {
        Gfx *gdl = *gdlptr;

        gDPSetEnvColor(gdl++, r, g, b, alpha);

        if (arg12)
        {
            gDPSetCombineLERP(gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, ENVIRONMENT, 0, COMBINED, 0, ENVIRONMENT, 0);
        }
        else if (arg13)
        {
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
        }
        else
        {
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);
        }

        *gdlptr = gdl;

        sub_GAME_7F06ABB0(gdlptr, arg1, arg2, twidth, theight, arg5, arg6, arg7);
    }
}
