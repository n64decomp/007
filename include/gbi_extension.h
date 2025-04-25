#ifndef _GBI_EXT_H_
#    define _GBI_EXT_H_
#include <PR/gbi.h>

#define TRI4_Ext

/** 
 * This file should contain most of the extensions to gbi avoiding loosing 
 * changes should the OS ever be updated.
 */

/**
   These are some helper constants. Since they relate to nothing else except GBI
   macros, Ill place them here, to save reserving names that might be used
   elsewhere - though doubtfull.
 */
#define MASK_2 1
#define MASK_4 2
#define MASK_8 3
#define MASK_16 4
#define MASK_32 5
#define MASK_64 6
#define MASK_128 7
#define MASK_256 8
#define MASK_512 9
#define MASK_1024 10

/* Set the Texel Scale (0.0 - 1.0) for multiplying UV's eg, 0.5 * (31 << 6) = 31.0 */
#define CALC_TEXSCALE(scale) scale < 1.0f ? scale * 0x10000 : 0xffff

/* Set the Lower Right S Coordinate using texture width */
#define CALC_LRS(width, height, siz) ((((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1)

#define CALC_TILESIZE(texel)         ((texel)-1) << G_TEXTURE_IMAGE_FRAC



#ifdef TRI4_Ext
#    define G_TRI4 (G_IMMFIRST - 14)
#    define G_SETTEX 0xc0 /*   0 */
#endif

/* Fade Modes ... for GE? */
#define G_CC_MODULATEIFADE    TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
#define G_CC_MODULATERGBFADE  G_CC_MODULATEIFADE
#define G_CC_MODULATEIFADEA   TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_MODULATEFADE     TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, TEXEL0, 0
#define G_CC_MODULATERGBFADEA G_CC_MODULATEIFADEA
#define G_CC_FADE             SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0
#define G_CC_FADEA            TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_DECALFADE        0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT
#define G_CC_DECALFADEA       0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_BLENDRGBFADEA    TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, ENVIRONMENT
#define G_CC_ADDRGBFADE       TEXEL0, 0, TEXEL0, SHADE, 0, 0, 0, ENVIRONMENT
#define G_CC_SHADEFADEA       0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT


/* Custom version of RM_AA_ZB_XLU_SURF with Z_UPD */
#define RM_CUSTOM_AA_ZB_XLU_SURF(clk) \
    RM_AA_ZB_XLU_SURF(clk) | Z_UPD



#define G_RM_CUSTOM_AA_ZB_XLU_SURF  RM_CUSTOM_AA_ZB_XLU_SURF(1)
#define G_RM_CUSTOM_AA_ZB_XLU_SURF2 RM_CUSTOM_AA_ZB_XLU_SURF(2)


#ifdef TRI4_Ext
/***
 ***  4 Triangles
 ***/
/**
 * Remarks:
 * Ryan: I've been learning a lot about PD's graphics microcode lately. It's likely that the decision to
 * implement tri4 was to reduce memory usage in RDRAM. But to fit 4 tris in one command they had to limit
 * themselves to 4 bits per vertex, which means they can only address up to 16 vertices. They could have
 * fit 32 vertices in DMEM if they wanted. In stock microcodes the vertex IDs are pre-multiplied by 10
 * which makes it easy for the RSP to calculate the vertex offset in the DMEM buffer (it can use a
 * single shift operation). But because PD is using a compact format there's more work for the RSP to
 * calculate it. So they've sacrificed RSP performance for memory saving.
*/

//cannot use 2tri with 4tri, so lets just make sure they are undefined so errors happen.
#undef gSP2Triangles
#undef gsSP2Triangles

/**
  Draw up to 4 triangles at a time.
  Vertex index is 0-15, to use a higher index use gSP1Triangle
*/
#define gSP4Triangles(pkt, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4) \
{                                                                          \
    Gfx *_g = (Gfx *)(pkt);                                                \
                                                                           \
    _g->words.w0 = (_SHIFTL(G_TRI4, 24, 8)                                 \
            | _SHIFTL(z4, 12, 4)                                           \
            | _SHIFTL(z3, 8, 4)                                            \
            | _SHIFTL(z2, 4, 4)                                            \
            | _SHIFTL(z1, 0, 4));                                          \
    _g->words.w1 = (_SHIFTL(y4, 28, 4)                                     \
            | _SHIFTL(x4, 24, 4)                                           \
            | _SHIFTL(y3, 20, 4)                                           \
            | _SHIFTL(x3, 16, 4)                                           \
            | _SHIFTL(y2, 12, 4)                                           \
            | _SHIFTL(x2, 8, 4)                                            \
            | _SHIFTL(y1, 4, 4)                                            \
            | _SHIFTL(x1, 0, 4));                                          \
}

/**
  Draw up to 4 triangles at a time.
  Vertex index is 0-15, to use a higher index use gSP1Triangle
*/
#define gsSP4Triangles(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4) \
{                                                                      \
    {                                                                  \
        (_SHIFTL(G_TRI4, 24, 8)                                        \
            | _SHIFTL(z4, 12, 4)                                       \
            | _SHIFTL(z3, 8, 4)                                        \
            | _SHIFTL(z2, 4, 4)                                        \
            | _SHIFTL(z1, 0, 4)),                                      \
        (_SHIFTL(y4, 28, 4)                                            \
            | _SHIFTL(x4, 24, 4)                                       \
            | _SHIFTL(y3, 20, 4)                                       \
            | _SHIFTL(x3, 16, 4)                                       \
            | _SHIFTL(y2, 12, 4)                                       \
            | _SHIFTL(x2, 8, 4)                                        \
            | _SHIFTL(y1, 4, 4)                                        \
            | _SHIFTL(x1, 0, 4))                                       \
    }                                                                  \
}

/**
  Source compatable F3DEX gSP2Triangles for GE
  Vertex index is 0-15, to use a higher index use gSP1Triangle
*/
#define gSP2Triangles(pkt, x1, y1, z1, flag0, x2, y2, z2, flag1) \
	gSP4Triangles(pkt, x1, y1, z1, x2, y2, z2, 0, 0, 0, 0, 0, 0)
#define gsSP2Triangles(x1, y1, z1, flag0, x2, y2, z2, flag1) \
	gsSP4Triangles(x1, y1, z1, x2, y2, z2, 0, 0, 0, 0, 0, 0)


/**
 * B1	rsp_tri4
 * Draws up to four triangles at a time.
 * Expects values from 0-F, corresponding with # points declared by vertex command.
 * Triangles with all points set to 0 are not drawn.
 *
 * upper word
 * 0000F000	z4
 * 00000F00	z3
 * 000000F0	z2
 * 0000000F	z1
 *
 * lower word
 * f0000000	y4
 * 0f000000	x4
 * 00f00000	y3
 * 000f0000	x3
 * 0000f000	y2
 * 00000f00	x2
 * 000000f0	y1
 * 0000000f	x1
 */
#define	gDPTri4(pkt, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4) \
{                                          \
    Gfx *_g = (Gfx *)(pkt);                \
    _g->words.w0 = (_SHIFTL(G_TRI4, 24, 8) \
            | _SHIFTL(z4, 12, 4)           \
            | _SHIFTL(z3, 8, 4)            \
            | _SHIFTL(z2, 4, 4)            \
            | _SHIFTL(z1, 0, 4));          \
    _g->words.w1 = (_SHIFTL(y4, 28, 4)     \
            | _SHIFTL(x4, 24, 4)           \
            | _SHIFTL(y3, 20, 4)           \
            | _SHIFTL(x3, 16, 4)           \
            | _SHIFTL(y2, 12, 4)           \
            | _SHIFTL(x2, 8, 4)            \
            | _SHIFTL(y1, 4, 4)            \
            | _SHIFTL(x1, 0, 4));          \
}

#define gDPTri3(pkt, x1, y1, z1, x2, y2, z2, x3, y3, z3) \
    gDPTri4(pkt, x1, y1, z1, x2, y2, z2, x3, y3, z3, 0, 0, 0)

#define gDPTri2(pkt, x1, y1, z1, x2, y2, z2) \
    gDPTri4(pkt, x1, y1, z1, x2, y2, z2, 0, 0, 0, 0, 0, 0)

#define gDPTri1(pkt, x1, y1, z1) \
    gDPTri4(pkt, x1, y1, z1, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define	gDPLoadTLUT06(pkt, a, b, c, d)				                                        \
{                                                                                           \
    Gfx *_g = (Gfx *)pkt;                                                                   \
    _g->words.w0 = _SHIFTL(G_LOADTLUT, 24, 8) | _SHIFTL((a), 14, 10) | _SHIFTL((b), 2, 10); \
    _g->words.w1 = _SHIFTL(0x06, 24, 8) | _SHIFTL((c), 14, 10) | _SHIFTL((d), 2, 10);       \
}
#define	gDPLoadTLUT07(pkt, a, b, c, d)				                                        \
{                                                                                           \
    Gfx *_g = (Gfx *)pkt;                                                                   \
    _g->words.w0 = _SHIFTL(G_LOADTLUT, 24, 8) | _SHIFTL((a), 14, 10) | _SHIFTL((b), 2, 10); \
    _g->words.w1 = _SHIFTL(0x07, 24, 8) | _SHIFTL((c), 14, 10) | _SHIFTL((d), 2, 10);       \
}

#define	gDPLoadTLUTCmd2(pkt, tile, count)				\
{									\
	Gfx *_g = (Gfx *)pkt;						\
									\
	_g->words.w0 = _SHIFTL(G_LOADTLUT, 24, 8) | 0xff0;			\
	_g->words.w1 = _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10) | 0xff0;\
}

/*
 * Texturing macro Overrides
 */

#define gsSPUseTexture()\
{                                 \
        {                             \
            (_SHIFTL(G_SETTEX, 24, 8) | \
             /*STUFF GOES HERE*/),    \
            /*STUFF GOES HERE*/       \
        }                             \
    }


#endif

/**
 * Like gDPSetPrimColor, but is useful when the input colour is already in
 * RGBA format. It avoids unnecessary bitshifting and masking.
 */
#define	gDPSetPrimColorViaWord(pkt, m, l, rgba)     \
{                                                   \
	Gfx *_g = (Gfx *)(pkt);                         \
	_g->words.w0 =	(_SHIFTL(G_SETPRIMCOLOR, 24, 8) \
			| _SHIFTL(m, 8, 8)                      \
			| _SHIFTL(l, 0, 8));                    \
	_g->words.w1 =  (rgba);                         \
}

#define gDPSetEnvColorViaWord(pkt, rgba) gDPSetColor(pkt, G_SETENVCOLOR, rgba)
#define gDPSetFogColorViaWord(pkt, rgba) gDPSetColor(pkt, G_SETFOGCOLOR, rgba)



#if 0 //Rare - so far - didnt seem to use this
#undef gDPLoadTextureBlock
/**
 Override of Load Texture Block without the PipeSync.
 Loads a Texture and sets its tile
 @param   timg: Address of the texture image. E.g. IMAGESEG(IMAGE_SMOKE_0)
 @param    fmt: Texture image format: E.g. G_IM_FMT_IA 
 @param    siz: Pixel component size: E.g. G_IM_SIZ_8b 
 @param  width: Texture image width
 @param height: Texture image height
 @param    pal: Location of palette for 4-bit color index texture (0 - 15)
 @param    cms: s-axis mirror, no-mirror, wrap, and clamp flags
 @param    cmt: t-axis mirror, no-mirror, wrap, and clamp flags
 @param  masks: s-axis mask (0 - 15 or G_TX_NOMASK)
 @param  maskt: t-axis mask (0 - 15 or G_TX_NOMASK)
 @param shifts: s-coordinate shift value or G_TX_NOLOD 
 @param shiftt: t-coordinate shift value or G_TX_NOLOD 
 */
#define gDPLoadTextureBlock(pkt, timg, fmt, siz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt)                               \
    {                                                                                                                                      \
        gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg);                                                                           \
        gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);                            \
        gDPLoadSync(pkt);                                                                                                                  \
        gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1, CALC_DXT(width, siz##_BYTES));      \
        gDPSetTile(pkt, fmt, siz, (((width)*siz##_LINE_BYTES) + 7) >> 3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); \
        gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)              \
    }

#undef gsDPLoadTextureBlock
/**
 Override of Load Texture Block (static) without the PipeSync.
 Loads a Texture and sets its tile
 @param   timg: Address of the texture image. E.g. IMAGESEG(IMAGE_SMOKE_0)
 @param    fmt: Texture image format: E.g. G_IM_FMT_IA 
 @param    siz: Pixel component size: E.g. G_IM_SIZ_8b 
 @param  width: Texture image width
 @param height: Texture image height
 @param    pal: Location of palette for 4-bit color index texture (0 - 15)
 @param    cms: s-axis mirror, no-mirror, wrap, and clamp flags
 @param    cmt: t-axis mirror, no-mirror, wrap, and clamp flags
 @param  masks: s-axis mask (0 - 15 or G_TX_NOMASK)
 @param  maskt: t-axis mask (0 - 15 or G_TX_NOMASK)
 @param shifts: s-coordinate shift value or G_TX_NOLOD 
 @param shiftt: t-coordinate shift value or G_TX_NOLOD 
 */
#define gsDPLoadTextureBlock(timg, fmt, siz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt)                             \
                                                                                                                                     \
    gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg),                                                                             \
    gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts),                              \
    gsDPLoadSync(),                                                                                                                  \
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1, CALC_DXT(width, siz##_BYTES)),        \
    gsDPSetTile(fmt, siz, ((((width)*siz##_LINE_BYTES) + 7) >> 3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), \
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#endif
#endif
