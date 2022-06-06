#include <ultra64.h>

Gfx fontDL_0x000[4] = { 
    gsSPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  G_TEXTURE_GEN |  G_TEXTURE_GEN_LINEAR | G_LOD),
    gsSPTexture(0x0000, 0x0000, 0, 0, 0),
    gsSPSetGeometryMode(G_SHADE |  G_SHADING_SMOOTH ),
    gsSPEndDisplayList(),
    };

Gfx fontDL_0x020[4] = { 
    gsSPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  G_TEXTURE_GEN |  G_TEXTURE_GEN_LINEAR | G_LOD),
    gsSPTexture(0x0000, 0x0000, 0, 0, 0),
    gsSPSetGeometryMode(G_ZBUFFER |  G_SHADE |  G_SHADING_SMOOTH ),
    gsSPEndDisplayList(),
};

Gfx fontDL_0x040[15] = { 
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare( G_AC_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
