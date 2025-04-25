#include <ultra64.h>

/**
 * Draws a textured rectangle on the screen.
 * 
 * @param gdlptr    Pointer to the display list.
 * @param position  Position coordinates (center) of the rectangle.
 * @param size      Size (half-width and half-height) of the rectangle.
 * @param width     Texture width.
 * @param height    Texture height.
 * @param flipXY    Flip X and Y flag.
 * @param flipX     Flip X-axis flag.
 * @param flipY     Flip Y-axis flag.
 */
void draw_textured_rectangle(Gfx **gdlptr, f32 *position, f32 *size, s32 width, s32 height, s32 flipXY, s32 flipX, s32 flipY)
{
    // Only proceed if the size values are positive
    if (size[0] > 0.0f && size[1] > 0.0f)
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

        // Disable texture perspective correction
        gDPSetTexturePersp(gdl++, G_TP_NONE);

        // Compute rectangle coordinates
        xl = (position[0] - size[0]) * 4.0f;
        yl = (position[1] - size[1]) * 4.0f;
        xh = (position[0] + size[0]) * 4.0f;
        yh = (position[1] + size[1]) * 4.0f;

        // Proceed if the rectangle is within screen bounds
        if (xh >= 0 && yh >= 0)
        {
            // Handle X coordinate adjustment
            if (xl < 0)
            {
                if (flipXY)
                {
                    t += ((-xl * height) << 5) / (xh - xl);
                }
                else
                {
                    s += ((-xl * width) << 5) / (xh - xl);
                }

                xl = 0;
            }

            // Handle Y coordinate adjustment
            if (yl < 0)
            {
                if (flipXY)
                {
                    s += ((-yl * width) << 5) / (yh - yl);
                }
                else
                {
                    t += ((-yl * height) << 5) / (yh - yl);
                }

                yl = 0;
            }

            // Calculate texture scaling based on flipXY flag
            if (flipXY)
            {
                dsdx = width / (2.0f * size[1]) * 1024.0f;
                dtdy = height / (2.0f * size[0]) * 1024.0f;
            }
            else
            {
                dsdx = width / (2.0f * size[0]) * 1024.0f;
                dtdy = height / (2.0f * size[1]) * 1024.0f;
            }
            
            // Flip texture horizontally if needed
            if (flipX)
            {
                dsdx = 0x10000 - dsdx;
                s = ((width - 1) << 5) - s;
            }

            // Flip texture vertically if needed
            if (flipY)
            {
                dtdy = 0x10000 - dtdy;
                t = ((height - 1) << 5) - t;
            }

            // Draw the textured rectangle with optional flipping
            if (flipXY)
            {
                gSPTextureRectangleFlip(gdl++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy);
            }
            else
            {
                gSPTextureRectangle(gdl++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy);
            }
        }

        // Re-enable texture perspective correction
        gDPSetTexturePersp(gdl++, G_TP_PERSP);

        *gdlptr = gdl;
    }
}

#define G_CC_MODULATEIA_ENV        COMBINED, 0, ENVIRONMENT, 0, COMBINED, 0, ENVIRONMENT, 0

/**
 * Displays an image at a specific on-screen position with color tinting and optional texture flips.
 * 
 * @param gdl       Pointer to the display list.
 * @param position  Position of the image.
 * @param size      Size (half-width and half-height) of the image.
 * @param twidth    Texture width.
 * @param theight   Texture height.
 * @param flipXY    Flip X and Y flag.
 * @param flipX     Flip X-axis flag.
 * @param flipY     Flip Y-axis flag.
 * @param r         Red tint value.
 * @param g         Green tint value.
 * @param b         Blue tint value.
 * @param alpha     Alpha (transparency) value.
 * @param mipmapped_texture  Mipmapped rendering mode flag.
 * @param highlight_mode     Highlight rendering mode flag.
 */
void display_image_at_position(Gfx **gdlptr, f32 *position, f32 *size, s32 twidth, u32 theight, u32 flipXY, u32 flipX, u32 flipY, u32 r, u32 g, u32 b, u32 alpha, u32 mipmapped_texture, u32 highlight_mode)
{
    
    if (size[0] > 0.0f && size[1] > 0.0f)
    {
        Gfx *gdl = *gdlptr;

        gDPSetEnvColor(gdl++, r, g, b, alpha);

        if (mipmapped_texture)
        {
            gDPSetCombineMode(gdl++, G_CC_TRILERP, G_CC_MODULATEIA_ENV);
        }
        else if (highlight_mode)
        {   
            gDPSetCombineMode(gdl++, G_CC_FADEA, G_CC_PASS2);
        }
        else
        {
            gDPSetCombineMode(gdl++, G_CC_FADEA, G_CC_FADEA);
        }

        *gdlptr = gdl;

        draw_textured_rectangle(gdlptr, position, size, twidth, theight, flipXY, flipX, flipY);
    }
}
