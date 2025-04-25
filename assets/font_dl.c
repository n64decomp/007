#include <ultra64.h>

// Display list for basic geometry rendering without textures, shading, or lighting effects.
Gfx dlBasicGeometry[4] = { 
     // Clear all geometry modes to set a basic state
    gsSPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  G_TEXTURE_GEN |  G_TEXTURE_GEN_LINEAR | G_LOD),
    // Disable texture mapping
    gsSPTexture(0x0000, 0x0000, 0, 0, 0),
    // Enable basic shading and smooth shading mode
    gsSPSetGeometryMode(G_SHADE |  G_SHADING_SMOOTH ),
    // End the display list
    gsSPEndDisplayList(),
    };

// Display list for rendering with Z-buffering enabled for depth comparison.
Gfx dlZBufferGeometry[4] = { 
    // Clear all geometry modes to set a basic state
    gsSPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  G_TEXTURE_GEN |  G_TEXTURE_GEN_LINEAR | G_LOD),
    // Disable texture mapping
    gsSPTexture(0x0000, 0x0000, 0, 0, 0),
    // Enable Z-buffering, basic shading, and smooth shading mode
    gsSPSetGeometryMode(G_ZBUFFER |  G_SHADE |  G_SHADING_SMOOTH ),
    // End the display list
    gsSPEndDisplayList(),
};

// Display list for configuring the graphics pipeline for fast rendering with specific texture settings.
Gfx dlFastPipelineSetup[15] = { 
    // Set to one cycle rendering mode (faster rendering, fewer features)
    gsDPSetCycleType(G_CYC_1CYCLE),
    // Set pipeline mode to handle one primitive per cycle
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    // Set texture level of detail to tile (use only one mipmap level)
    gsDPSetTextureLOD(G_TL_TILE),
    // Disable texture lookup table (no color indexing)
    gsDPSetTextureLUT(G_TT_NONE),
    // Clamp texture coordinates to prevent wrapping
    gsDPSetTextureDetail(G_TD_CLAMP),
    // Enable perspective correction for textures
    gsDPSetTexturePersp(G_TP_PERSP),
    // Use bilinear filtering for smoother textures
    gsDPSetTextureFilter(G_TF_BILERP),
    // Convert texture to filtered format
    gsDPSetTextureConvert(G_TC_FILT),
    // Set color combiner to use vertex shading only
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    // Disable color keying (no transparency based on color)
    gsDPSetCombineKey(G_CK_NONE),
    // Disable alpha comparison (no transparency based on alpha)
    gsDPSetAlphaCompare( G_AC_NONE),
    // Set render mode to opaque surface (two cycle mode)
    gsDPSetRenderMode(G_RM_PASS, G_RM_OPA_SURF2),
    // Enable magic square dithering for smoother gradients
    gsDPSetColorDither(G_CD_MAGICSQ),
    // Synchronize the pipeline to ensure commands are executed in order
    gsDPPipeSync(),
    // End the display list
    gsSPEndDisplayList(),
};
