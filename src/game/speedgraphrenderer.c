#include <ultra64.h>
#include "speedgraphrenderer.h"

/**
 * @brief The current position on the graph being drawn.
 *
 * This variable keeps track of the current position in the graph where the next 
 * bar or line will be drawn. It is used to determine the starting point for 
 * rendering new elements on the graph.
 */
f32 gCurrentGraphPosition = 0.0f;
/**
 * @brief The next position on the graph for rendering.
 *
 * This variable is incremented as new bars or lines are drawn on the graph.
 * It represents the position where the next graphical element will begin, 
 * allowing for the sequential rendering of the graph.
 */
f32 gNextGraphPosition = 0.0f;







/**
 * @brief Initializes the display list for rendering the speed graph.
 *
 * This function sets up the graphics pipeline with specific configurations,
 * such as disabling the Z-buffer, setting the texture filter to point mode,
 * and configuring the cycle type to fill mode. It also resets the graph 
 * position variables to their initial state.
 *
 * @param gdl A pointer to the current display list.
 * @return A pointer to the next available display list entry.
 */
Gfx * InitializeSpeedGraphDL(Gfx *gdl)
{
    gCurrentGraphPosition = gNextGraphPosition = 0.0f;
    
    gDPSetTextureFilter(gdl++, G_TF_POINT);
    gDPSetColorDither(gdl++, G_CD_DISABLE);
    gSPClearGeometryMode(gdl++, G_ZBUFFER );
    gDPPipeSync(gdl++);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_OPA_SURF2);
    gDPPipelineMode(gdl++, G_PM_1PRIMITIVE);
    return gdl++;
}


/**
 * @brief Draws a simple graph bar with specified color and offset.
 *
 * This function draws a filled rectangle representing a bar in the speed graph,
 * with a simple offset and fixed dimensions. The bar is colored using the 
 * provided RGB values.
 *
 * @param gdl A pointer to the current display list.
 * @param offset The position of the bar.
 * @param r The red component of the bar's color (0-255).
 * @param g The green component of the bar's color (0-255).
 * @param b The blue component of the bar's color (0-255).
 * @return A pointer to the next available display list entry.
 */
Gfx *DrawGraphBarWithSimpleOffset(Gfx *gdl, f32 offset, s32 r, s32 g, s32 b)
{
    return DrawGraphBar(gdl, offset, r, g, b, 2, 1);
}


/**
 * @brief Draws a graph bar with specified dimensions and color.
 *
 * This function calculates the start and end positions of a graph bar, 
 * adjusting for segment offsets and ensuring the bar is drawn within the 
 * screen boundaries. The bar is filled with the specified color.
 *
 * @param gdl A pointer to the current display list.
 * @param offset The position of the bar.
 * @param r The red component of the bar's color (0-255).
 * @param g The green component of the bar's color (0-255).
 * @param b The blue component of the bar's color (0-255).
 * @param width The width applied to the bar.
 * @param height The height applied to the bar.
 * @return A pointer to the next available display list entry.
 */
Gfx *DrawGraphBar(Gfx *gdl, f32 offset, s32 r, s32 g, s32 b, s32 width, s32 height)
{
    f32 nextPosition;
    s32 start;
    s32 upper;
    s32 segmentOffsetX;
    s32 i;
    s32 ulx;
    s32 lrx;
    s32 leftSide;
    s32 rightSide;
    
    if (offset > 0)
    {
        start = (s32) (gNextGraphPosition / 10.0f);
        
        nextPosition = gNextGraphPosition + offset;
        upper = (s32) ((nextPosition) / 10.0f);
        
        leftSide = (s32) ((gNextGraphPosition * 219.0f) / 10.0f);
        rightSide = (s32) (((nextPosition) * 219.0f) / 10.0f);
        
        gDPSetFillColor(gdl++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));
                
        for (i = start; (upper >= i) && (i < 3); i++)
        {
            segmentOffsetX = (i * 219);
            ulx = (leftSide - segmentOffsetX) + 50;
            lrx = (rightSide - segmentOffsetX) + 50;
            
            if (ulx < 50)
            {
                ulx = 50;
            }
            
            if (lrx >= 270)
            {
                lrx = 269;
            }

            if (lrx >= ulx)
            {
                gDPFillRectangle(gdl++, ulx, (height + (i * 7) + 18), lrx, (width + height + (i * 7) + 17));
            }

            ulx -= 219;
        }

        gNextGraphPosition += offset;        
    }
    
    return gdl;
}


/**
 * @brief Updates the current position of the graph by a specified delta.
 *
 * This function increments the graph's position by the specified delta, 
 * allowing for dynamic movement or extension of the graph.
 *
 * @param delta The amount to increment the graph position by.
 */
void UpdateGraphPosition(f32 delta) {
    if (0.0f < delta) {
        gNextGraphPosition = (f32) (gNextGraphPosition + delta);
        return;
    }
}


/**
 * @brief Draws a graph bar with an adjusted offset.
 *
 * This unreferenced function draws a graph bar with an offset that accounts 
 * for the difference between the current and next graph positions. This may 
 * be used for drawing bars relative to the previous position.
 *
 * @param gdl A pointer to the current display list.
 * @param offset The position of the bar.
 * @param r The red component of the bar's color (0-255).
 * @param g The green component of the bar's color (0-255).
 * @param b The blue component of the bar's color (0-255).
 * @return A pointer to the next available display list entry.
 */
Gfx *DrawAdjustedGraphBar(Gfx *gdl, f32 offset, s32 r, s32 g, s32 b)
{
    return DrawGraphBarWithSimpleOffset(gdl, (gCurrentGraphPosition + offset) - gNextGraphPosition, r, g, b);
}


/**
 * @brief Draws a graph bar with a specified offset and dimensions.
 *
 * This unreferenced function draws a graph bar with an offset that takes into 
 * account both the current graph position and the provided width and height 
 * offsets.
 *
 * @param gdl A pointer to the current display list.
 * @param offset The position of the bar.
 * @param r The red component of the bar's color (0-255).
 * @param g The green component of the bar's color (0-255).
 * @param b The blue component of the bar's color (0-255).
 * @param width The width of the bar.
 * @param height The height of the bar.
 * @return A pointer to the next available display list entry.
 */
Gfx *DrawGraphBarWithOffset(Gfx *gdl, f32 offset, s32 r, s32 g, s32 b, s32 width, s32 height)
{
    return DrawGraphBar(gdl, (gCurrentGraphPosition + offset) - gNextGraphPosition, r, g, b, width, height);
}


/**
 * @brief Draws vertical lines on the graph.
 *
 * This function draws vertical lines on the graph, using the specified 
 * color. The lines are spaced based on the current graph position.
 *
 * @param gdl A pointer to the current display list.
 * @param r The red component of the line color (0-255).
 * @param g The green component of the line color (0-255).
 * @param b The blue component of the line color (0-255).
 * @return A pointer to the next available display list entry.
 */
Gfx *DrawVerticalLines(Gfx *gdl, s32 r, s32 g, s32 b)
{
    s32 start;
    s32 i;
    s32 j;
    
    start = (s32) (gNextGraphPosition / 10.0f);

    gDPSetFillColor(gdl++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));

    for (j = 0; start >= j && j < 3; j++)
    {
        for (i = 0; i < 11; i++)
        {
            gDPFillRectangle(
                gdl++,
                (s32) (((f32) i * 219.0f) / 10.0f) + 50,
                j*7 + 0x12,
                (s32) (((f32) i * 219.0f) / 10.0f) + 50,
                j*7 + 0x15);
        }
    }
    
    return gdl;
}


/**
 * @brief Aligns the current graph position to the nearest 10-unit boundary.
 *
 * This function adjusts the graph's position to align with the nearest 10-unit 
 * boundary, which may be used to ensure consistent spacing or grid alignment.
 */
void AlignGraphPosition(void)
{
    s32 t;

    t = (s32) (gNextGraphPosition / 10.0f);
    t = (t * 10) + 10;
    
    gNextGraphPosition = t;
    gCurrentGraphPosition = gNextGraphPosition;
}




