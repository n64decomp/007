#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include <PR/gbi.h>
#include <gbi_extension.h>
#include <assets/image_externs.h>



Gfx globalDL_0x000[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_MODULATEIA,G_CC_MODULATEIA),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_11
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_11)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList()
};

Gfx globalDL_0x078[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_0
    gsDPSetTextureImage(G_IM_FMT_IA,  G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_0)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    //IMAGE_FIRE_0
    gsDPSetTextureImage(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_0)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x120[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_2
    gsDPSetTextureImage(G_IM_FMT_IA,  G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_2)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_2
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_2)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x1c8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_7
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_7)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_7
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_7)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x270[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_8
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_8)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_8
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_8)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x318[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_9
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_9)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_9
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_9)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x3c0[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_10
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_10)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_10
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_10)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x468[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_11
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_11)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_11
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_11)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x510[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_12
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_12)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_12
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_12)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x5b8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_13
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_13)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_13
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_13)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x660[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_14
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_14)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_14
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_14)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x708[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_1
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_1)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_1
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_1)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x7b0[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_3
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_3)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_3
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_3)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x858[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_4
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_4)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_4
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_4)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x900[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_5
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_5)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_5
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_5)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x9a8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineMode(G_CC_INTERFERENCE,G_CC_MODULATEIA2),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_SMOKE_6
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_SMOKE_6)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(56,56,G_IM_SIZ_8b), CALC_DXT(56,G_IM_SIZ_8b)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, MASK_64, 0, G_TX_WRAP, MASK_64, 0),
    gsDPSetTileSize(0, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),
    //IMAGE_FIRE_6
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_FIRE_6)),
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, CALC_LRS(16,14,G_IM_SIZ_16b), CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0188, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2, G_TX_NOMIRROR | G_TX_CLAMP, MASK_16, 2),
    gsDPSetTileSize(1, 0, 0, CALC_TILESIZE(56), CALC_TILESIZE(56)),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0xa50[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),

    gsDPSetCombineMode(G_CC_MODULATEIA,G_CC_MODULATEIA),
    gsSPTexture(CALC_TEXSCALE(1), CALC_TEXSCALE(1), 0, G_TX_RENDERTILE, G_ON),
    //IMAGE_STATIC_NOISE
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, IMAGESEG(IMAGE_STATIC_NOISE)),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 511, CALC_DXT(16,G_IM_SIZ_16b)),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0),
    gsDPSetTileSize(0, 0, 0, 124, 124),

    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

sImageTableEntry s_genericimage[] = { 
    {IMAGE_FLAREWHITEROUND, 0x36, 0x36, 3, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_impactimages[] = { // bg/debris?
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT2, 0x40, 0x20, 7, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/bullethit
    {IMAGE_IMPACT3, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhit
    {IMAGE_IMPACTLOTS, 0x40, 0x20, 7, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/bulletholesplaster
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT4, 0x20, 0x20, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/bullethole
    {IMAGE_IMPACTMULTI, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/bulletholesplasterrgb
    {IMAGE_IMPACTREDBRICK1, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole1
    {IMAGE_IMPACTREDBRICK2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole2
    {IMAGE_IMPACTREDBRICK3, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole3
    {IMAGE_IMPACTBRICK2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole6
    {IMAGE_IMPACTBRICK3, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole7
    {IMAGE_IMPACTBROWNBRICK1, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole8
    {IMAGE_IMPACTBROWNBRICK2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhole9
    {IMAGE_IMPACT3, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/wallhit
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // bg/windowhit
    {IMAGE_IMPACT1, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}  // bg/windowhit
};

sImageTableEntry s_explosion_smokeimages[] = {  // sfx/smoke?
    {IMAGE_SMOKE1, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/hit5
    {IMAGE_SMOKE2, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/hit10
    {IMAGE_SMOKE3, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/hit15
    {IMAGE_SMOKE4, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/hit20
    {IMAGE_SMOKE5, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/hit25
    {IMAGE_SMOKE6, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}  // sfx/hit30
};

sImageTableEntry s_scattered_explosions[] = { // sfx/firebomb?
    {IMAGE_SMOKEBALLS1, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/backhit6
    {IMAGE_SMOKEBALLS2, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/backhit12
    {IMAGE_SMOKEBALLS3, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/backhit18
    {IMAGE_SMOKEBALLS4, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // sfx/backhit24
    {IMAGE_SMOKEBALLS5, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}  // sfx/backhit30
};

sImageTableEntry s_flareimage1[] = { 
    {IMAGE_FLARENOVA, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage2[] = { 
    {IMAGE_WHITEBOX, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0} // sfx/white
};

sImageTableEntry s_flareimage3[] = { 
    {IMAGE_FLAREORANGELINE, 0x10, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0} // sfx/laser
};

sImageTableEntry s_flareimage4[] = { 
    {IMAGE_FLAREBLUELINE, 0x10, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0} // sfx/beam
};

sImageTableEntry s_flareimage5[] = { 
    {IMAGE_FLAREBLUEROUND, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0} // sfx/beamhead
};



sImageTableEntry s_ammo9mmimage[] = { 
    {IMAGE_9MMAMMO, 5, 0xC, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoicon9mm
};

sImageTableEntry s_rifleammoimage[] = {
    {IMAGE_RIFLEAMMO, 5, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconrifle
};

sImageTableEntry s_shotgunammoimage[] = {
    {IMAGE_SHOTAMMO, 6, 0x14, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconshell
};

sImageTableEntry s_knifeammoimage[] = {
    {IMAGE_KNIFEAMMO, 6, 0x18, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconknife
};

sImageTableEntry s_glammoimage[] = {
    {IMAGE_GLAMMO, 8, 0x15, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0} // bg/ammoicongrenade
};

sImageTableEntry s_rocketammoimage[] = {
    {IMAGE_ROCKETAMMO, 7, 0x16, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconrocket
};

sImageTableEntry s_genericmineammoimage[] = {
    {IMAGE_PLAINMINEAMMO, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconmine
};

sImageTableEntry s_grenadeammoimage[] = {
    {IMAGE_GRENADEAMMO, 0xE, 0x12, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammogrenadehand
};

sImageTableEntry s_magnumammoimage[] = {
    {IMAGE_MAGAMMO, 5, 0xF, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconmagnum
};

sImageTableEntry s_goldengunammoimage[] = {
    {IMAGE_GGAMMO, 5, 0xC, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoicongold
};

sImageTableEntry s_remotemineammoimage[] = {
    {IMAGE_MINEAMMO, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconminered
};

sImageTableEntry s_timedmineammoimage[] = {
    {IMAGE_TIMEAMMO, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconmineyellow
};

sImageTableEntry s_proxmineammoimage[] = {
    {IMAGE_PROXAMMO, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoiconminegreen
};

sImageTableEntry s_tankammoimage[] = {
    {IMAGE_TANKAMMO, 7, 0x16, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0} // bg/ammoicontankshell
};

sImageTableEntry s_crosshairimage[] = {
    {IMAGE_CROSSHAIR1, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0} // bg/sight
};

sImageTableEntry s_betacrosshairimage[] = {
    {IMAGE_CROSSHAIR2, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0} //
};

sImageTableEntry s_glassoverlayimage[] = {
    {IMAGE_GLASS7, 0x20, 1, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},     // sfx/glass?
    {IMAGE_GLASS3, 0x36, 0x36, 3, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0} // sfx/glass?
};

sImageTableEntry s_monitorimages[] = { 
    {IMAGE_MONITOR_BOND, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                 // monitors/bondlogo
    {IMAGE_MONITOR_LOCATION, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},             // monitors/cyrlocation
    {IMAGE_MONITOR_BEGINARMING, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/cyrweaponarmed
    {IMAGE_MONITOR_TARGET, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},               // monitors/cyrtarget
    {IMAGE_MONITOR_SEVERNAYA, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},            // monitors/cyrsevernaya
    {IMAGE_MONITOR_BREAKTARGET, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/cyrtimetotarget
    {IMAGE_MONITOR_AIMER, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/cyrxhairspanel
    {IMAGE_MONITOR_EARTH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},            // monitors/screen1
    {IMAGE_MONITOR_DESKTOPBANG, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},      // monitors/screen2
    {IMAGE_MONITOR_HEATMAP, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/screen3
    {IMAGE_MONITOR_3DMATH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},           // monitors/screen4
    {IMAGE_MONITOR_DESKTOPBARS, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},      // monitors/screen5
    {IMAGE_MONITOR_2DMATH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},           // monitors/screen6
    {IMAGE_MONITOR_SATELLITE, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},        // monitors/screen7
    {IMAGE_MONITOR_DESKTOP, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/screen8
    {IMAGE_MONITOR_DESKTOPSTAGGERED, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}, // monitors/screen9
    {IMAGE_MONITOR_CUBE1, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim2.0
    {IMAGE_MONITOR_SHUTTLE1, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},         // monitors/drax1
    {IMAGE_MONITOR_SHUTTLE2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},         // monitors/drax2
    {IMAGE_MONITOR_EARTHFULL1, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},       // monitors/drax3
    {IMAGE_MONITOR_EARTHFULL2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},       // monitors/drax4
    {IMAGE_MONITOR_BLUESTARS, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},        // monitors/drax5
    {IMAGE_MONITOR_GALAXY1, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/drax6
    {IMAGE_MONITOR_GALAXY2, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/drax7
    {IMAGE_MONITOR_EARTHTEXT, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},        // monitors/drax10
    {IMAGE_MONITOR_TARGETEARTH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},      // monitors/drax11
    {IMAGE_MONITOR_GALAXY3, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/drax12
    {IMAGE_MONITOR_STATIC, 0x40, 0x40, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},               // monitors/screenstatic
    {IMAGE_MONITOR_SINE, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                 // monitors/screennew1
    {IMAGE_MONITOR_TEXT, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                 // monitors/screennew2
    {IMAGE_MONITOR_BARS, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                 // monitors/screennew3
    {IMAGE_MONITOR_SQUARES, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},              // monitors/screennew4
    {IMAGE_MONITOR_FIST1, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim4.1
    {IMAGE_MONITOR_FIST2, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim4.2
    {IMAGE_MONITOR_FIST3, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim4.3
    {IMAGE_MONITOR_FIST4, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim4.4
    {IMAGE_MONITOR_SKATEBOARD4, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/anim5.1
    {IMAGE_MONITOR_SKATEBOARD1, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/anim5.2
    {IMAGE_MONITOR_SKATEBOARD2, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/anim5.3
    {IMAGE_MONITOR_SKATEBOARD3, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},          // monitors/anim5.4
    {IMAGE_MONITOR_TALK1, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim3.1
    {IMAGE_MONITOR_TALK2, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim3.2
    {IMAGE_MONITOR_TALK3, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim3.3
    {IMAGE_MONITOR_TALK4, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim3.4
    {IMAGE_MONITOR_WORLDMAP, 0x80, 0x30, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_CLAMP, 0},            // monitors/earthmap
    {IMAGE_MONITOR_CUBE2, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim2.1
    {IMAGE_MONITOR_CUBE3, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim2.2
    {IMAGE_MONITOR_CUBE4, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},                // monitors/anim2.3
    {IMAGE_MONITOR_TRIANGLE, 0x36, 0x36, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},          // monitors/animradar
    {IMAGE_MONITOR_KEYBOARDKEY, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}       // monitors/keyboardkey
};

sImageTableEntry s_skywaterimages[] = { 
    {IMAGE_CLOUDS_GRAYSCALE, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}, // bg/clouds
    {IMAGE_WATER_GRAYSCALE, 0x40, 0x40, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},   // bg/water1
    {IMAGE_WATER_BLUE, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}     // bg/water2
};

sImageTableEntry s_mainfolderimages[] = { 
    {IMAGE_COPYICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0}, //
    {IMAGE_DELICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0}, //
    {IMAGE_SELECTFILE, 0x7A, 0x12, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, //
    {IMAGE_X, 0xF, 0xF, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // cross
    {IMAGE_CHECK, 0x14, 0x14, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // tick
    {IMAGE_DOT, 0x10, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0} //
};

sImageTableEntry s_mpradarimages[] = { 
    {IMAGE_RUSTYDRUM_END, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0} //circle
};

sImageTableEntry s_mpcharselimages[] = { 
    {IMAGE_BROSNAN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/brosnan
    {IMAGE_BROSNAN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/brosnan
    {IMAGE_BROSNAN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/brosnan
    {IMAGE_BROSNAN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/brosnan
    {IMAGE_MOORE_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/moore
    {IMAGE_MOORE_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/moore
    {IMAGE_MOORE_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/moore
    {IMAGE_MOORE_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/moore
    {IMAGE_DALTON_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/dalton
    {IMAGE_DALTON_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/dalton
    {IMAGE_DALTON_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/dalton
    {IMAGE_DALTON_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/dalton
    {IMAGE_CONNERY_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/connery
    {IMAGE_CONNERY_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/connery
    {IMAGE_CONNERY_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/connery
    {IMAGE_CONNERY_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/connery
    {IMAGE_BORIS_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/boris
    {IMAGE_BORIS_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/boris
    {IMAGE_BORIS_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/boris
    {IMAGE_BORIS_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/boris
    {IMAGE_OURUMOV_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/ourumov/oumorov
    {IMAGE_OURUMOV_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/ourumov/oumorov
    {IMAGE_OURUMOV_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/ourumov/oumorov
    {IMAGE_OURUMOV_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/ourumov/oumorov
    {IMAGE_TREVELYAN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0 }, // characters/trevelyan 
    {IMAGE_TREVELYAN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0 }, // characters/trevelyan 
    {IMAGE_TREVELYAN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0 }, // characters/trevelyan 
    {IMAGE_TREVELYAN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0 }, // characters/trevelyan 
    {IMAGE_VALENTIN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/valentin
    {IMAGE_VALENTIN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/valentin
    {IMAGE_VALENTIN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/valentin
    {IMAGE_VALENTIN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/valentin
    {IMAGE_XENIA_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/xenia
    {IMAGE_XENIA_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/xenia
    {IMAGE_XENIA_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/xenia
    {IMAGE_XENIA_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/xenia
    {IMAGE_NATALYA_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/natalya
    {IMAGE_NATALYA_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/natalya
    {IMAGE_NATALYA_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/natalya
    {IMAGE_NATALYA_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/natalya
    {IMAGE_BARON_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/baron
    {IMAGE_BARON_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/baron
    {IMAGE_BARON_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/baron
    {IMAGE_BARON_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/baron 
    {IMAGE_JAWS_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/jaws
    {IMAGE_JAWS_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/jaws
    {IMAGE_JAWS_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/jaws
    {IMAGE_JAWS_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/jaws
    {IMAGE_MAYDAY_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mayday
    {IMAGE_MAYDAY_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mayday
    {IMAGE_MAYDAY_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mayday
    {IMAGE_MAYDAY_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mayday
    {IMAGE_ODDJOB_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/oddjob
    {IMAGE_ODDJOB_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/oddjob
    {IMAGE_ODDJOB_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/oddjob
    {IMAGE_ODDJOB_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/oddjob
    {IMAGE_RANDOM_UL, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/who
    {IMAGE_RANDOM_UR, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/who
    {IMAGE_RANDOM_LL, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/who
    {IMAGE_RANDOM_LR, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/who
    {IMAGE_MISHKIN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mishkin
    {IMAGE_MISHKIN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mishkin
    {IMAGE_MISHKIN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}, // characters/mishkin
    {IMAGE_MISHKIN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}  // characters/mishkin
};

sImageTableEntry s_mpstageselimages[] = { 
    //{IMAGE_MP_BUNKER, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},   // level/sevicon
    //{IMAGE_MP_SILO, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},     // level/siloicon
    //{IMAGE_MP_CONTROL, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},  // level/arecicon
    //{IMAGE_MP_TRAIN, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},    // level/traicon
    //{IMAGE_MP_STREETS, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},  // level/peteicon
    //{IMAGE_MP_SURFACE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},  // level/sevxicon
    //{IMAGE_MP_JUNGLE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},   // level/junicon
    //{IMAGE_MP_SURFACE2, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}, // level/sevxbicon
    {IMAGE_MP_BUNKER2, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},    // level/sevbicon
    {IMAGE_MP_CAVERNS, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},    // level/caveicon
    {IMAGE_MP_ARCHIVES, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},   // level/archicon
    {IMAGE_MP_DAM, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},        // level/damicon
    {IMAGE_MP_FACILITY, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},   // level/arkicon
    {IMAGE_MP_RUNWAY, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},     // level/runicon
    {IMAGE_MP_FRIGATE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},    // level/desticon
    {IMAGE_MP_STATUE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},     // level/staticon
    {IMAGE_MP_CRADLE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},     // level/cradicon
    {IMAGE_MP_AZTEC, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},      // level/azticon
    {IMAGE_MP_EGYPT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},      // level/crypicon
    {IMAGE_MP_DEPOT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},      // level/depoicon
    {IMAGE_MP_TEMPLE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},     // level/smptempleicon
    {IMAGE_MP_BASEMENT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},   // level/smplibicon
    {IMAGE_MP_COMPLEX, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},    // level/smpcomplexicon
    {IMAGE_MP_CAVES, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},      // level/smpcaveicon
    {IMAGE_MP_RANDOM, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}      // bg/where
};



