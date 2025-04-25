#include <ultra64.h>
#include "bondconstants.h"
#include "image.h"
#include "image_bank.h"
#include <assets/image_externs.h>
#include <PR/R4300.h>
#include "ramrom.h"
#include "decompress.h"

// bss
//8008C720
struct texpool *ptr_texture_alloc_start;
//8008C724
s32 ptr_texture_alloc_end;
//8008C728
s32 ptr_next_available_space;
//8008C72C
s32 ptr_last_entry_facemapping;
//8008C730
struct texcacheitem g_TexCacheItems[150];
//8008D090
s32 g_TexCacheCount;
//8008D094
s32 g_TexNumToLoad;

// data
//D:80049170
u32 bytes = 0x6DDD0;
//D:80049174
u32 D_80049174 = 0;

//D:80049178 #1	#bytes in pixel data for image
s32 g_TexFormatNumChannels[] = 
{
    4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1
};
//D:800491AC #2	1=alphagrab.  Grabs 1 bit of alpha data for each pixel
s32 g_TexFormatHas1BitAlpha[] = 
{
    0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0
};
//D:800491E0 #3	#bits in 'samples', *2	-1=bitmask
s32 g_TexFormatChannelSizes[] = 
{
    0x100, 0x20, 0x100, 0x20, 0x100, 0x10, 8, 0x100, 0x10, 0x100, 0x10, 0x100, 0x10
};
//D:80049214 #4	bitcount for pixel data
s32 g_TexFormatBitsPerPixel[] = 
{
     0x20, 0x10, 0x18, 0xF, 0x10, 8, 4, 8, 4, 0x10, 0x10, 0x10, 0x10, 
};
//D:80049248 #5	N64 image types (0=color, 1=YUV, 2=indexed, 3=IA, 4=I)
s32 g_TexFormatGbiMappings[] = 
{
    G_IM_FMT_RGBA, G_IM_FMT_RGBA, G_IM_FMT_RGBA, G_IM_FMT_RGBA,	
    G_IM_FMT_IA, G_IM_FMT_IA, G_IM_FMT_IA, 
    G_IM_FMT_I, G_IM_FMT_I, 
    G_IM_FMT_CI, G_IM_FMT_CI, G_IM_FMT_CI, G_IM_FMT_CI,
};
//D:8004927C #6	N64 pixel sizes (0=4bit, 1=8bit, 2=16bit, 3=32bit)
s32 g_TexFormatDepths[] = 
{
	G_IM_SIZ_32b,
    G_IM_SIZ_16b,
	G_IM_SIZ_32b,
	G_IM_SIZ_16b,
	G_IM_SIZ_16b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
};
//D:800492B0 #7	imageflip values for indexed types
s32 g_TexFormatLutModes[] = {
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_RGBA16,
	G_TT_RGBA16,
	G_TT_IA16,
	G_TT_IA16,
};
//D:800492e4
s32 D_800492E4[] = 
{
    0, 0, 0, 0, 0, 0, 0
};
#define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) \
    {HS, HT, SZ, F3, F4, F5, F6 },

//D:80049300
//need way to calculate size at compile time from external data
struct image_entry g_Textures[] = {
    #include <assets/images.def>
    {HIT_DEFAULT, HIT_DEFAULT,0xFFFF,0,0,0,0}
};
#undef IMAGE


void nullsub_41(s32 arg0) {
    if (arg0);
}


/**
 * Inflate images (levels of detail) from a zlib-compressed texture.
 *
 * Zlib-compressed textures are always paletted and always use 16-bit colours.
 * The texture header contains palette information, then each image follows with
 * its own header and zlib compresed data.
 *
 * The texture header is:
 *
 * ffffffff nnnnnnnn [palette]
 *
 * f = pixel format (see TEXFORMAT constants)
 * n = number of colours in the palette minus 1
 * [palette] = 16 bits * number of colours
 *
 * Each images's header is:
 *
 * wwwwwwww hhhhhhhh [data]
 *
 * w = width in pixels
 * h = height in pixels
 * [data] = zlib compressed list of indices into the palette
 *
 * The zlib data is prefixed with the standard 5-byte rarezip header.
 */
s32 texInflateZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texpool *arg4)
{
    s32 i;
    s32 imagebytesout;
    s32 numimages;
    s32 totalbytesout;
    s32 format;
    bool foundthething;
    bool writetocache;
    s32 width;
    s32 height;
    u8 *end;
    u8 *start;
    s32 numcolours;
    s32 j;
    s32 unused;
    u8 scratch2[0x800];
    u8 scratch[0x2100];
    u16 palette[0x100];

    totalbytesout = 0;
    writetocache = FALSE;

    texSetBitstring(src);

    if (arg2 && forcenumimages)
    {
        numimages = forcenumimages;
    }
    else
    {
        numimages = 1;
    }

    arg4->rightpos->maxlod = forcenumimages;
    arg4->rightpos->unk0c_02 = arg2;

    if (arg2)
    {
        writetocache = TRUE;

        for (i = 0; i < g_TexCacheCount; i++)
        {
            if (g_TexCacheItems[i].texturenum == arg4->rightpos->texturenum)
            {
                writetocache = FALSE;
            }
        }
    }

    format = texReadBits(8);
    numcolours = texReadBits(8) + 1;

    for (i = 0; i < numcolours; i++)
    {
        palette[i] = texReadBits(16);
    }

    foundthething = FALSE;

    for (j = 0; j < numimages; j++)
    {
        width = texReadBits(8);
        height = texReadBits(8);

        if (j == 0)
        {
            arg4->rightpos->width = width;
            arg4->rightpos->height = height;
            arg4->rightpos->unk0a = numcolours - 1;
            arg4->rightpos->gbiformat = g_TexFormatGbiMappings[format];
            arg4->rightpos->depth = g_TexFormatDepths[format];
            arg4->rightpos->lutmodeindex = g_TexFormatLutModes[format] >> G_MDSFT_TEXTLUT;
        }
        else if (writetocache)
        {
            g_TexCacheItems[g_TexCacheCount].widths[j - 1] = width;
            g_TexCacheItems[g_TexCacheCount].heights[j - 1] = height;
        }

        if ((width * height) >= 4097)
        {
            return j * 0;
        }

        decompressdata(img_curpos, &scratch2, (struct huft *)&scratch);
        imagebytesout = texAlignIndices(scratch2, width, height, format, &dst[totalbytesout]);
        texSetBitstring(rzipGetSomething());

        if ((arg2 == 1) && (forcenumimages > 0))
        {
            texSwapAltRowBytes(&dst[totalbytesout], width, height, format);
        }
        totalbytesout += imagebytesout;
    }

    if (writetocache)
    {
        g_TexCacheItems[g_TexCacheCount].texturenum = arg4->rightpos->texturenum;

        g_TexCacheCount++;

        if (g_TexCacheCount >= ARRAYCOUNT(g_TexCacheItems))
        {
            g_TexCacheCount = 0;
        }
    }

    if (!arg2)
    {
        if (forcenumimages >= 2)
        {
            s32 tmpwidth;
            s32 tmpheight;

            tmpwidth = width;
            tmpheight = height;

            start = dst;
            end = &dst[totalbytesout];

            for (j = 1; j < forcenumimages; j++)
            {
                imagebytesout = texShrinkPaletted(start, end, tmpwidth, tmpheight, format, palette, numcolours);

                if (totalbytesout + imagebytesout > 0x800)
                {
                    arg4->rightpos->maxlod = j;
                    break;
                }

                texSwapAltRowBytes(start, tmpwidth, tmpheight, format);

                totalbytesout += imagebytesout;

                tmpwidth = (tmpwidth + 1) >> 1;
                tmpheight = (tmpheight + 1) >> 1;

                start = end;
                end += imagebytesout;
                if (1);
            }

            texSwapAltRowBytes(start, tmpwidth, tmpheight, format);
        }
        else if (forcenumimages == 1)
        {
            texSwapAltRowBytes(dst, width, height, format);
        }
    }

    for (i = 0; i < numcolours; i++)
    {
        if ((!totalbytesout) && (!totalbytesout));
        dst[totalbytesout + 0] = palette[i] >> 8;
        dst[totalbytesout + 1] = palette[i] & 0xff;
        totalbytesout += 2;
    }

    totalbytesout = (totalbytesout + 7) & ~7;

    return totalbytesout;
}


/**
 * Copy a list of palette indices to the dst buffer, but ensure each row is
 * aligned to an 8 byte boundary.
 *
 * Return the number of output bytes.
 */
s32 texAlignIndices(u8 *src, s32 width, s32 height, s32 format, u8 *dst)
{
    s32 x;
    s32 y;
    u8 *outptr;
    s32 indicesperbyte;

    outptr = dst;

    if (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_IA16_CI8)
    {
        indicesperbyte = 1;
    }
    else if (format == TEXFORMAT_RGBA16_CI4 || format == TEXFORMAT_0C)
    {
        indicesperbyte = 2;
    }
    else if (indicesperbyte)
    {
    }

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x += indicesperbyte)
        {
            *outptr = *src;
            outptr++;
            src++;
        }

        outptr = (u8 *)(((u32)outptr + 7) & ~7);
    }

    return outptr - dst;
}


/**
 * Shrink a paletted texture to half its size by averaging each each 2x2 group
 * of pixels.
 *
 * Return the number of bytes written.
 */
s32 texShrinkPaletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format, u16 *palette, s32 numcolours)
{
    s32 j;
    s32 i;
    s32 alignedsrcwidth;
    s32 aligneddstwidth;
    s32 dstheight;
    s16 colour1;
    s16 colour2;
    s16 colour3;
    s16 colour4;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 nextrow;
    u8 *dst8;
    s32 nextcol;
    s32 c;
    u8 *src8;

    dst8 = dst;
    src8 = src;
    dstheight = (srcheight + 1) >> 1;

    switch (format)
    {
        case TEXFORMAT_RGBA16_CI8:
        case TEXFORMAT_IA16_CI8:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 7) & 0xff8;
            alignedsrcwidth = (srcwidth + 7) & 0xff8;
            break;

        case TEXFORMAT_RGBA16_CI4:
        case TEXFORMAT_0C:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 15) & 0xff0;
            alignedsrcwidth = (srcwidth + 15) & 0xff0;
            break;
    }


    switch (format)
    {
        case TEXFORMAT_RGBA16_CI8:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    colour1 = palette[src8[j]];
                    colour2 = palette[src8[nextcol]];
                    colour3 = palette[src8[nextrow + j]];
                    colour4 = palette[src8[nextrow + nextcol]];

                    r = ((((colour1 >> 0xB) & 0x1F) + ((colour2 >> 0xB) & 0x1F) + ((colour3 >> 0xB) & 0x1F) + ((colour4 >> 0xB) & 0x1F)) >> 2) & 0x1F;
                    g = ((((colour1 >> 6) & 0x1F) + ((colour2 >> 6) & 0x1F) + ((colour3 >> 6) & 0x1F) + ((colour4 >> 6) & 0x1F)) >> 2) & 0x1F;
                    b = ((((colour1 >> 1) & 0x1F) + ((colour2 >> 1) & 0x1F) + ((colour3 >> 1) & 0x1F) + ((colour4 >> 1) & 0x1F)) >> 2) & 0x1F;
                    a = (((colour1 & 1) + (colour2 & 1) + (colour3 & 1) + (colour4 & 1) + 2) >> 2) & 1;

                    dst8[j >> 1] = texFindClosestColourIndexRGBA(palette, numcolours, r, g, b, a);
                }

                dst8 += aligneddstwidth;
                src8 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth;

        case TEXFORMAT_IA16_CI8:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    colour1 = palette[src8[j]];
                    colour2 = palette[src8[nextcol]];
                    colour3 = palette[src8[nextrow + j]];
                    colour4 = palette[src8[nextrow + nextcol]];

                    c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
                    a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

                    dst8[j >> 1] = texFindClosestColourIndexIA(palette, numcolours, c, a);
                }

                dst8 += aligneddstwidth;
                src8 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth;

        case TEXFORMAT_RGBA16_CI4:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth >> 1 : 0;

                for (j = 0; j < alignedsrcwidth; j += 4)
                {
                    colour1 = palette[(src8[j >> 1] >> 4) & 0xf];
                    colour2 = palette[src8[j >> 1] >> ((j + 1 < srcwidth ? 0 : 4)) & 0xf];
                    colour3 = palette[(src8[nextrow + (j >> 1)] >> 4) & 0xf];
                    colour4 = palette[src8[nextrow + (j >> 1)] >> ((j + 1 < srcwidth ? 0 : 4)) & 0xf];

                    r = ((((colour1 >> 0xB) & 0x1F) + ((colour2 >> 0xB) & 0x1F) + ((colour3 >> 0xB) & 0x1F) + ((colour4 >> 0xB) & 0x1F)) >> 2) & 0x1F;
                    g = ((((colour1 >> 6) & 0x1F) + ((colour2 >> 6) & 0x1F) + ((colour3 >> 6) & 0x1F) + ((colour4 >> 6) & 0x1F)) >> 2) & 0x1F;
                    b = ((((colour1 >> 1) & 0x1F) + ((colour2 >> 1) & 0x1F) + ((colour3 >> 1) & 0x1F) + ((colour4 >> 1) & 0x1F)) >> 2) & 0x1F;
                    a = ((((colour1 & 1) + (colour2 & 1) + (colour3 & 1) + (colour4 & 1) + 2) >> 2) & 1);

                    dst8[j >> 2] = (texFindClosestColourIndexRGBA(palette, numcolours, r, g, b, a) * 0x10) & 0xFFFF;

                    colour1 = palette[(src8[(j + 2) >> 1] >> 4) & 0xf];
                    colour2 = palette[(src8[(j + 2) >> 1] >> (j + 3 < srcwidth ? 0 : 4)) & 0xf];
                    colour3 = palette[(src8[nextrow + ((j + 2) >> 1)] >> 4) & 0xf];
                    colour4 = palette[(src8[nextrow + ((j + 2) >> 1)] >> (j + 3 < srcwidth ? 0 : 4)) & 0xf];

                    r = ((((colour1 >> 0xB) & 0x1F) + ((colour2 >> 0xB) & 0x1F) + ((colour3 >> 0xB) & 0x1F) + ((colour4 >> 0xB) & 0x1F)) >> 2) & 0x1F;
                    g = ((((colour1 >> 6) & 0x1F) + ((colour2 >> 6) & 0x1F) + ((colour3 >> 6) & 0x1F) + ((colour4 >> 6) & 0x1F)) >> 2) & 0x1F;
                    b = ((((colour1 >> 1) & 0x1F) + ((colour2 >> 1) & 0x1F) + ((colour3 >> 1) & 0x1F) + ((colour4 >> 1) & 0x1F)) >> 2) & 0x1F;
                    a = ((((colour1 & 1) + (colour2 & 1) + (colour3 & 1) + (colour4 & 1) + 2) >> 2) & 1);

                    dst8[j >> 2] |= texFindClosestColourIndexRGBA(palette, numcolours, r, g, b, a) & 0xff;
                }

                dst8 += aligneddstwidth >> 1;
                src8 += alignedsrcwidth;
            }

            return (aligneddstwidth >> 1) * dstheight;

        case TEXFORMAT_0C:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth >> 1 : 0;

                for (j = 0; j < alignedsrcwidth; j += 4)
                {
                    // @bug: The brackets are wrong in colour2 and colour4 which
                    // causes the index shift to be part of the ternary condition.
                    // It's done correctly in TEXFORMAT_RGBA16_CI4 (above).
                    // This buggy calculation is repeated further below.
                    colour1 = palette[(src8[j >> 1] >> 4) & 0xf];
                    colour2 = palette[(src8[j >> 1] >> (j + 1 < srcwidth) ? 0 : 4) & 0xf];
                    colour3 = palette[(src8[nextrow + (j >> 1)] >> 4) & 0xf];
                    colour4 = palette[(src8[nextrow + (j >> 1)] >> (j + 1 < srcwidth) ? 0 : 4) & 0xf];

                    c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
                    a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

                    dst8[j >> 2] = (texFindClosestColourIndexIA(palette, numcolours, c, a) * 0x10) & 0xFFFF;

                    colour1 = palette[(src8[(j + 2) >> 1] >> 4) & 0xf];
                    colour2 = palette[(src8[(j + 2) >> 1] >> (j + 3 < srcwidth) ? 0 : 4) & 0xf];
                    colour3 = palette[(src8[nextrow + ((j + 2) >> 1)] >> 4) & 0xf];
                    colour4 = palette[(src8[nextrow + ((j + 2) >> 1)] >> (j + 3 < srcwidth) ? 0 : 4) & 0xf];

                    c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
                    a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

                    dst8[j >> 2] |= texFindClosestColourIndexIA(palette, numcolours, c, a) & 0xff;
                }

                dst8 += aligneddstwidth >> 1;
                src8 += alignedsrcwidth;
            }

            return (aligneddstwidth >> 1) * dstheight;
    }

    return 0;
}


#ifdef NONMATCHING
// https://decomp.me/scratch/m2ol7 79.87%
s32 texFindClosestColourIndexRGBA(u16 *palette, s32 numcolours, s32 r, s32 g, s32 b, s32 a)
{
    s32 var_v1;
    u16 temp_t6;
    s32 temp_t0;
    s32 var_a1;
    s32 temp_a0;

    s32 loop_start;
    s32 loop_end;

    s32 bestindex;
    s32 bestvalue;
    
    u16 local_color;
    s32 local_r;
    s32 local_g;
    s32 local_b;
    s32 local_a;
    s32 temp_s4;

    temp_t6 = ((r << 11) | (g << 6) | (b << 1) | a);
    
    for (var_v1 = 0; var_v1 < numcolours; var_v1++)
    {
        if (temp_t6 == palette[var_v1])
        {
            return var_v1;
        }
    }

    temp_t0 = (r * r) + (g * g) + (b * b) + (a * 0x3C1);
    var_v1 = numcolours - 1;
    var_a1 = 0;

    // binary search for a region
    while (var_v1 - var_a1 >= 2)
    {
        temp_a0 = (s32) (var_v1 + var_a1) >> 1;

        local_color = palette[temp_a0 * 4];
        local_r = ((s32) local_color >> 0xB) & 0x1F;
        local_g = ((s32) local_color >> 0x6) & 0x1F;
        local_b = ((s32) local_color >> 0x1) & 0x1F;
        local_a = local_color & 1;

        temp_s4 = (local_r * local_r) + (local_g * local_g) + (local_b * local_b) + (local_a * 0x3C1);

        if (temp_s4 < temp_t0)
        {
            var_a1 = temp_a0;
        }
        else
        {
            if (temp_t0 < temp_s4)
            {
                var_v1 = temp_a0;
            }
            else
            {
                var_v1 = temp_a0;
                var_a1 = temp_a0;
            }            
        }
    }

    loop_start = var_v1 - 4;
    if (loop_start < 0)
    {
        loop_start = 0;
    }

    loop_end = var_v1 + 4;
    if (loop_end >= numcolours)
    {
        loop_end = numcolours - 1;
    }

    bestindex = 0;
    bestvalue = 999999;

    // search for best within the region
    for (var_v1 = loop_start; var_v1 < loop_end; var_v1++)
    {
        local_color = palette[var_v1 * 4];
        local_r = (((s32) local_color >> 0xB) & 0x1F) - r;
        local_g = (((s32) local_color >> 0x6) & 0x1F) - g;
        local_b = (((s32) local_color >> 0x1) & 0x1F) - b;
        local_a = 0x3C1;
        if (a == (local_color & 1))
        {
            local_a = 0;
        }

        temp_s4 = (local_r * local_r) + (local_g * local_g) + (local_b * local_b) + (local_a);

        if (temp_s4 < bestvalue)
        {
            bestindex = var_v1;
            bestvalue = temp_s4;
        }
    }

    return bestindex;
}

#else
GLOBAL_ASM(
.text
glabel texFindClosestColourIndexRGBA
/* 0FC2DC 7F0C77AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC2E0 7F0C77B0 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FC2E4 7F0C77B4 AFB10008 */  sw    $s1, 8($sp)
/* 0FC2E8 7F0C77B8 AFB00004 */  sw    $s0, 4($sp)
/* 0FC2EC 7F0C77BC 00C08025 */  move  $s0, $a2
/* 0FC2F0 7F0C77C0 00E08825 */  move  $s1, $a3
/* 0FC2F4 7F0C77C4 00809025 */  move  $s2, $a0
/* 0FC2F8 7F0C77C8 AFB40014 */  sw    $s4, 0x14($sp)
/* 0FC2FC 7F0C77CC AFB30010 */  sw    $s3, 0x10($sp)
/* 0FC300 7F0C77D0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0FC304 7F0C77D4 18A0003F */  blez  $a1, .L7F0C78D4
/* 0FC308 7F0C77D8 00001825 */   move  $v1, $zero
/* 0FC30C 7F0C77DC 30A60003 */  andi  $a2, $a1, 3
/* 0FC310 7F0C77E0 10C00018 */  beqz  $a2, .L7F0C7844
/* 0FC314 7F0C77E4 8FA90028 */   lw    $t1, 0x28($sp)
/* 0FC318 7F0C77E8 00007840 */  sll   $t7, $zero, 1
/* 0FC31C 7F0C77EC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC320 7F0C77F0 024F1021 */  addu  $v0, $s2, $t7
/* 0FC324 7F0C77F4 0010C2C0 */  sll   $t8, $s0, 0xb
/* 0FC328 7F0C77F8 0007C980 */  sll   $t9, $a3, 6
/* 0FC32C 7F0C77FC 03197025 */  or    $t6, $t8, $t9
/* 0FC330 7F0C7800 00097840 */  sll   $t7, $t1, 1
/* 0FC334 7F0C7804 01CFC025 */  or    $t8, $t6, $t7
/* 0FC338 7F0C7808 030A2825 */  or    $a1, $t8, $t2
/* 0FC33C 7F0C780C 30B9FFFF */  andi  $t9, $a1, 0xffff
/* 0FC340 7F0C7810 03202825 */  move  $a1, $t9
/* 0FC344 7F0C7814 00C02025 */  move  $a0, $a2
.L7F0C7818:
/* 0FC348 7F0C7818 944E0000 */  lhu   $t6, ($v0)
/* 0FC34C 7F0C781C 54AE0004 */  bnel  $a1, $t6, .L7F0C7830
/* 0FC350 7F0C7820 24630001 */   addiu $v1, $v1, 1
/* 0FC354 7F0C7824 100000E5 */  b     .L7F0C7BBC
/* 0FC358 7F0C7828 00601025 */   move  $v0, $v1
/* 0FC35C 7F0C782C 24630001 */  addiu $v1, $v1, 1
.L7F0C7830:
/* 0FC360 7F0C7830 1483FFF9 */  bne   $a0, $v1, .L7F0C7818
/* 0FC364 7F0C7834 24420002 */   addiu $v0, $v0, 2
/* 0FC368 7F0C7838 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC36C 7F0C783C 506F0026 */  beql  $v1, $t7, .L7F0C78D8
/* 0FC370 7F0C7840 8FA6001C */   lw    $a2, 0x1c($sp)
.L7F0C7844:
/* 0FC374 7F0C7844 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC378 7F0C7848 0003C040 */  sll   $t8, $v1, 1
/* 0FC37C 7F0C784C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC380 7F0C7850 02581021 */  addu  $v0, $s2, $t8
/* 0FC384 7F0C7854 0010CAC0 */  sll   $t9, $s0, 0xb
/* 0FC388 7F0C7858 00117180 */  sll   $t6, $s1, 6
/* 0FC38C 7F0C785C 032E7825 */  or    $t7, $t9, $t6
/* 0FC390 7F0C7860 0009C040 */  sll   $t8, $t1, 1
/* 0FC394 7F0C7864 01F8C825 */  or    $t9, $t7, $t8
/* 0FC398 7F0C7868 032A2825 */  or    $a1, $t9, $t2
/* 0FC39C 7F0C786C 30AEFFFF */  andi  $t6, $a1, 0xffff
/* 0FC3A0 7F0C7870 01C02825 */  move  $a1, $t6
.L7F0C7874:
/* 0FC3A4 7F0C7874 944F0000 */  lhu   $t7, ($v0)
/* 0FC3A8 7F0C7878 54AF0004 */  bnel  $a1, $t7, .L7F0C788C
/* 0FC3AC 7F0C787C 94580002 */   lhu   $t8, 2($v0)
/* 0FC3B0 7F0C7880 100000CE */  b     .L7F0C7BBC
/* 0FC3B4 7F0C7884 00601025 */   move  $v0, $v1
/* 0FC3B8 7F0C7888 94580002 */  lhu   $t8, 2($v0)
.L7F0C788C:
/* 0FC3BC 7F0C788C 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC3C0 7F0C7890 54B80004 */  bnel  $a1, $t8, .L7F0C78A4
/* 0FC3C4 7F0C7894 94590004 */   lhu   $t9, 4($v0)
/* 0FC3C8 7F0C7898 100000C8 */  b     .L7F0C7BBC
/* 0FC3CC 7F0C789C 24620001 */   addiu $v0, $v1, 1
/* 0FC3D0 7F0C78A0 94590004 */  lhu   $t9, 4($v0)
.L7F0C78A4:
/* 0FC3D4 7F0C78A4 54B90004 */  bnel  $a1, $t9, .L7F0C78B8
/* 0FC3D8 7F0C78A8 944E0006 */   lhu   $t6, 6($v0)
/* 0FC3DC 7F0C78AC 100000C3 */  b     .L7F0C7BBC
/* 0FC3E0 7F0C78B0 24620002 */   addiu $v0, $v1, 2
/* 0FC3E4 7F0C78B4 944E0006 */  lhu   $t6, 6($v0)
.L7F0C78B8:
/* 0FC3E8 7F0C78B8 54AE0004 */  bnel  $a1, $t6, .L7F0C78CC
/* 0FC3EC 7F0C78BC 24630004 */   addiu $v1, $v1, 4
/* 0FC3F0 7F0C78C0 100000BE */  b     .L7F0C7BBC
/* 0FC3F4 7F0C78C4 24620003 */   addiu $v0, $v1, 3
/* 0FC3F8 7F0C78C8 24630004 */  addiu $v1, $v1, 4
.L7F0C78CC:
/* 0FC3FC 7F0C78CC 146FFFE9 */  bne   $v1, $t7, .L7F0C7874
/* 0FC400 7F0C78D0 24420008 */   addiu $v0, $v0, 8
.L7F0C78D4:
/* 0FC404 7F0C78D4 8FA6001C */  lw    $a2, 0x1c($sp)
.L7F0C78D8:
/* 0FC408 7F0C78D8 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC40C 7F0C78DC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC410 7F0C78E0 24C6FFFF */  addiu $a2, $a2, -1
/* 0FC414 7F0C78E4 28C10002 */  slti  $at, $a2, 2
/* 0FC418 7F0C78E8 00002825 */  move  $a1, $zero
/* 0FC41C 7F0C78EC 1420003A */  bnez  $at, .L7F0C79D8
/* 0FC420 7F0C78F0 00C03825 */   move  $a3, $a2
/* 0FC424 7F0C78F4 02100019 */  multu $s0, $s0
/* 0FC428 7F0C78F8 0000C012 */  mflo  $t8
/* 0FC42C 7F0C78FC 00000000 */  nop   
/* 0FC430 7F0C7900 00000000 */  nop   
/* 0FC434 7F0C7904 02310019 */  multu $s1, $s1
/* 0FC438 7F0C7908 0000C812 */  mflo  $t9
/* 0FC43C 7F0C790C 03197021 */  addu  $t6, $t8, $t9
/* 0FC440 7F0C7910 000AC900 */  sll   $t9, $t2, 4
/* 0FC444 7F0C7914 01290019 */  multu $t1, $t1
/* 0FC448 7F0C7918 032AC823 */  subu  $t9, $t9, $t2
/* 0FC44C 7F0C791C 0019C980 */  sll   $t9, $t9, 6
/* 0FC450 7F0C7920 032AC821 */  addu  $t9, $t9, $t2
/* 0FC454 7F0C7924 00007812 */  mflo  $t7
/* 0FC458 7F0C7928 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC45C 7F0C792C 03194021 */  addu  $t0, $t8, $t9
/* 0FC460 7F0C7930 00E55821 */  addu  $t3, $a3, $a1
.L7F0C7934:
/* 0FC464 7F0C7934 000B2043 */  sra   $a0, $t3, 1
/* 0FC468 7F0C7938 00047840 */  sll   $t7, $a0, 1
/* 0FC46C 7F0C793C 024FC021 */  addu  $t8, $s2, $t7
/* 0FC470 7F0C7940 97030000 */  lhu   $v1, ($t8)
/* 0FC474 7F0C7944 000362C3 */  sra   $t4, $v1, 0xb
/* 0FC478 7F0C7948 3199001F */  andi  $t9, $t4, 0x1f
/* 0FC47C 7F0C794C 03390019 */  multu $t9, $t9
/* 0FC480 7F0C7950 00036983 */  sra   $t5, $v1, 6
/* 0FC484 7F0C7954 31AE001F */  andi  $t6, $t5, 0x1f
/* 0FC488 7F0C7958 00039843 */  sra   $s3, $v1, 1
/* 0FC48C 7F0C795C 326F001F */  andi  $t7, $s3, 0x1f
/* 0FC490 7F0C7960 0000C012 */  mflo  $t8
/* 0FC494 7F0C7964 00000000 */  nop   
/* 0FC498 7F0C7968 00000000 */  nop   
/* 0FC49C 7F0C796C 01CE0019 */  multu $t6, $t6
/* 0FC4A0 7F0C7970 0000C812 */  mflo  $t9
/* 0FC4A4 7F0C7974 03197021 */  addu  $t6, $t8, $t9
/* 0FC4A8 7F0C7978 30790001 */  andi  $t9, $v1, 1
/* 0FC4AC 7F0C797C 01EF0019 */  multu $t7, $t7
/* 0FC4B0 7F0C7980 00007812 */  mflo  $t7
/* 0FC4B4 7F0C7984 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC4B8 7F0C7988 00197100 */  sll   $t6, $t9, 4
/* 0FC4BC 7F0C798C 01D97023 */  subu  $t6, $t6, $t9
/* 0FC4C0 7F0C7990 000E7180 */  sll   $t6, $t6, 6
/* 0FC4C4 7F0C7994 01D97021 */  addu  $t6, $t6, $t9
/* 0FC4C8 7F0C7998 030EA021 */  addu  $s4, $t8, $t6
/* 0FC4CC 7F0C799C 0288082A */  slt   $at, $s4, $t0
/* 0FC4D0 7F0C79A0 50200004 */  beql  $at, $zero, .L7F0C79B4
/* 0FC4D4 7F0C79A4 0114082A */   slt   $at, $t0, $s4
/* 0FC4D8 7F0C79A8 10000007 */  b     .L7F0C79C8
/* 0FC4DC 7F0C79AC 00802825 */   move  $a1, $a0
/* 0FC4E0 7F0C79B0 0114082A */  slt   $at, $t0, $s4
.L7F0C79B4:
/* 0FC4E4 7F0C79B4 10200003 */  beqz  $at, .L7F0C79C4
/* 0FC4E8 7F0C79B8 00803825 */   move  $a3, $a0
/* 0FC4EC 7F0C79BC 10000002 */  b     .L7F0C79C8
/* 0FC4F0 7F0C79C0 00803825 */   move  $a3, $a0
.L7F0C79C4:
/* 0FC4F4 7F0C79C4 00802825 */  move  $a1, $a0
.L7F0C79C8:
/* 0FC4F8 7F0C79C8 00E57823 */  subu  $t7, $a3, $a1
/* 0FC4FC 7F0C79CC 29E10002 */  slti  $at, $t7, 2
/* 0FC500 7F0C79D0 5020FFD8 */  beql  $at, $zero, .L7F0C7934
/* 0FC504 7F0C79D4 00E55821 */   addu  $t3, $a3, $a1
.L7F0C79D8:
/* 0FC508 7F0C79D8 24E5FFFC */  addiu $a1, $a3, -4
/* 0FC50C 7F0C79DC 04A10002 */  bgez  $a1, .L7F0C79E8
/* 0FC510 7F0C79E0 8FB9001C */   lw    $t9, 0x1c($sp)
/* 0FC514 7F0C79E4 00002825 */  move  $a1, $zero
.L7F0C79E8:
/* 0FC518 7F0C79E8 24E70004 */  addiu $a3, $a3, 4
/* 0FC51C 7F0C79EC 00F9082A */  slt   $at, $a3, $t9
/* 0FC520 7F0C79F0 14200002 */  bnez  $at, .L7F0C79FC
/* 0FC524 7F0C79F4 3C14000F */   lui   $s4, (0x000F423F >> 16) # lui $s4, 0xf
/* 0FC528 7F0C79F8 00C03825 */  move  $a3, $a2
.L7F0C79FC:
/* 0FC52C 7F0C79FC 3694423F */  ori   $s4, (0x000F423F & 0xFFFF) # ori $s4, $s4, 0x423f
/* 0FC530 7F0C7A00 00E5082A */  slt   $at, $a3, $a1
/* 0FC534 7F0C7A04 00004025 */  move  $t0, $zero
/* 0FC538 7F0C7A08 02803025 */  move  $a2, $s4
/* 0FC53C 7F0C7A0C 1420006A */  bnez  $at, .L7F0C7BB8
/* 0FC540 7F0C7A10 00A02025 */   move  $a0, $a1
/* 0FC544 7F0C7A14 00E51023 */  subu  $v0, $a3, $a1
/* 0FC548 7F0C7A18 24420001 */  addiu $v0, $v0, 1
/* 0FC54C 7F0C7A1C 30580001 */  andi  $t8, $v0, 1
/* 0FC550 7F0C7A20 13000023 */  beqz  $t8, .L7F0C7AB0
/* 0FC554 7F0C7A24 00057040 */   sll   $t6, $a1, 1
/* 0FC558 7F0C7A28 024E7821 */  addu  $t7, $s2, $t6
/* 0FC55C 7F0C7A2C 95E20000 */  lhu   $v0, ($t7)
/* 0FC560 7F0C7A30 24A40001 */  addiu $a0, $a1, 1
/* 0FC564 7F0C7A34 240303C1 */  li    $v1, 961
/* 0FC568 7F0C7A38 30590001 */  andi  $t9, $v0, 1
/* 0FC56C 7F0C7A3C 15590003 */  bne   $t2, $t9, .L7F0C7A4C
/* 0FC570 7F0C7A40 0002C2C3 */   sra   $t8, $v0, 0xb
/* 0FC574 7F0C7A44 10000001 */  b     .L7F0C7A4C
/* 0FC578 7F0C7A48 00001825 */   move  $v1, $zero
.L7F0C7A4C:
/* 0FC57C 7F0C7A4C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC580 7F0C7A50 01D05823 */  subu  $t3, $t6, $s0
/* 0FC584 7F0C7A54 016B0019 */  multu $t3, $t3
/* 0FC588 7F0C7A58 00027983 */  sra   $t7, $v0, 6
/* 0FC58C 7F0C7A5C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC590 7F0C7A60 03316023 */  subu  $t4, $t9, $s1
/* 0FC594 7F0C7A64 0002C043 */  sra   $t8, $v0, 1
/* 0FC598 7F0C7A68 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC59C 7F0C7A6C 01C96823 */  subu  $t5, $t6, $t1
/* 0FC5A0 7F0C7A70 00007812 */  mflo  $t7
/* 0FC5A4 7F0C7A74 006FC821 */  addu  $t9, $v1, $t7
/* 0FC5A8 7F0C7A78 00000000 */  nop   
/* 0FC5AC 7F0C7A7C 018C0019 */  multu $t4, $t4
/* 0FC5B0 7F0C7A80 0000C012 */  mflo  $t8
/* 0FC5B4 7F0C7A84 03387021 */  addu  $t6, $t9, $t8
/* 0FC5B8 7F0C7A88 24F90001 */  addiu $t9, $a3, 1
/* 0FC5BC 7F0C7A8C 01AD0019 */  multu $t5, $t5
/* 0FC5C0 7F0C7A90 00007812 */  mflo  $t7
/* 0FC5C4 7F0C7A94 01CF9821 */  addu  $s3, $t6, $t7
/* 0FC5C8 7F0C7A98 0274082A */  slt   $at, $s3, $s4
/* 0FC5CC 7F0C7A9C 10200003 */  beqz  $at, .L7F0C7AAC
/* 0FC5D0 7F0C7AA0 00000000 */   nop   
/* 0FC5D4 7F0C7AA4 00A04025 */  move  $t0, $a1
/* 0FC5D8 7F0C7AA8 02603025 */  move  $a2, $s3
.L7F0C7AAC:
/* 0FC5DC 7F0C7AAC 13240042 */  beq   $t9, $a0, .L7F0C7BB8
.L7F0C7AB0:
/* 0FC5E0 7F0C7AB0 0004C040 */   sll   $t8, $a0, 1
/* 0FC5E4 7F0C7AB4 02582821 */  addu  $a1, $s2, $t8
.L7F0C7AB8:
/* 0FC5E8 7F0C7AB8 94A20000 */  lhu   $v0, ($a1)
/* 0FC5EC 7F0C7ABC 240303C1 */  li    $v1, 961
/* 0FC5F0 7F0C7AC0 304E0001 */  andi  $t6, $v0, 1
/* 0FC5F4 7F0C7AC4 154E0003 */  bne   $t2, $t6, .L7F0C7AD4
/* 0FC5F8 7F0C7AC8 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC5FC 7F0C7ACC 10000001 */  b     .L7F0C7AD4
/* 0FC600 7F0C7AD0 00001825 */   move  $v1, $zero
.L7F0C7AD4:
/* 0FC604 7F0C7AD4 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC608 7F0C7AD8 03306023 */  subu  $t4, $t9, $s0
/* 0FC60C 7F0C7ADC 018C0019 */  multu $t4, $t4
/* 0FC610 7F0C7AE0 0002C183 */  sra   $t8, $v0, 6
/* 0FC614 7F0C7AE4 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC618 7F0C7AE8 01D16823 */  subu  $t5, $t6, $s1
/* 0FC61C 7F0C7AEC 00027843 */  sra   $t7, $v0, 1
/* 0FC620 7F0C7AF0 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC624 7F0C7AF4 03299023 */  subu  $s2, $t9, $t1
/* 0FC628 7F0C7AF8 0000C012 */  mflo  $t8
/* 0FC62C 7F0C7AFC 00787021 */  addu  $t6, $v1, $t8
/* 0FC630 7F0C7B00 240303C1 */  li    $v1, 961
/* 0FC634 7F0C7B04 01AD0019 */  multu $t5, $t5
/* 0FC638 7F0C7B08 00007812 */  mflo  $t7
/* 0FC63C 7F0C7B0C 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC640 7F0C7B10 00000000 */  nop   
/* 0FC644 7F0C7B14 02520019 */  multu $s2, $s2
/* 0FC648 7F0C7B18 0000C012 */  mflo  $t8
/* 0FC64C 7F0C7B1C 03389821 */  addu  $s3, $t9, $t8
/* 0FC650 7F0C7B20 0266082A */  slt   $at, $s3, $a2
/* 0FC654 7F0C7B24 50200004 */  beql  $at, $zero, .L7F0C7B38
/* 0FC658 7F0C7B28 94A20002 */   lhu   $v0, 2($a1)
/* 0FC65C 7F0C7B2C 00804025 */  move  $t0, $a0
/* 0FC660 7F0C7B30 02603025 */  move  $a2, $s3
/* 0FC664 7F0C7B34 94A20002 */  lhu   $v0, 2($a1)
.L7F0C7B38:
/* 0FC668 7F0C7B38 304E0001 */  andi  $t6, $v0, 1
/* 0FC66C 7F0C7B3C 154E0003 */  bne   $t2, $t6, .L7F0C7B4C
/* 0FC670 7F0C7B40 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC674 7F0C7B44 10000001 */  b     .L7F0C7B4C
/* 0FC678 7F0C7B48 00001825 */   move  $v1, $zero
.L7F0C7B4C:
/* 0FC67C 7F0C7B4C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC680 7F0C7B50 03305823 */  subu  $t3, $t9, $s0
/* 0FC684 7F0C7B54 016B0019 */  multu $t3, $t3
/* 0FC688 7F0C7B58 0002C183 */  sra   $t8, $v0, 6
/* 0FC68C 7F0C7B5C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC690 7F0C7B60 01D16023 */  subu  $t4, $t6, $s1
/* 0FC694 7F0C7B64 00027843 */  sra   $t7, $v0, 1
/* 0FC698 7F0C7B68 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC69C 7F0C7B6C 03296823 */  subu  $t5, $t9, $t1
/* 0FC6A0 7F0C7B70 0000C012 */  mflo  $t8
/* 0FC6A4 7F0C7B74 00787021 */  addu  $t6, $v1, $t8
/* 0FC6A8 7F0C7B78 00000000 */  nop   
/* 0FC6AC 7F0C7B7C 018C0019 */  multu $t4, $t4
/* 0FC6B0 7F0C7B80 00007812 */  mflo  $t7
/* 0FC6B4 7F0C7B84 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC6B8 7F0C7B88 24EE0001 */  addiu $t6, $a3, 1
/* 0FC6BC 7F0C7B8C 01AD0019 */  multu $t5, $t5
/* 0FC6C0 7F0C7B90 0000C012 */  mflo  $t8
/* 0FC6C4 7F0C7B94 03389021 */  addu  $s2, $t9, $t8
/* 0FC6C8 7F0C7B98 0246082A */  slt   $at, $s2, $a2
/* 0FC6CC 7F0C7B9C 50200004 */  beql  $at, $zero, .L7F0C7BB0
/* 0FC6D0 7F0C7BA0 24840002 */   addiu $a0, $a0, 2
/* 0FC6D4 7F0C7BA4 24880001 */  addiu $t0, $a0, 1
/* 0FC6D8 7F0C7BA8 02403025 */  move  $a2, $s2
/* 0FC6DC 7F0C7BAC 24840002 */  addiu $a0, $a0, 2
.L7F0C7BB0:
/* 0FC6E0 7F0C7BB0 15C4FFC1 */  bne   $t6, $a0, .L7F0C7AB8
/* 0FC6E4 7F0C7BB4 24A50004 */   addiu $a1, $a1, 4
.L7F0C7BB8:
/* 0FC6E8 7F0C7BB8 01001025 */  move  $v0, $t0
.L7F0C7BBC:
/* 0FC6EC 7F0C7BBC 8FB00004 */  lw    $s0, 4($sp)
/* 0FC6F0 7F0C7BC0 8FB10008 */  lw    $s1, 8($sp)
/* 0FC6F4 7F0C7BC4 8FB2000C */  lw    $s2, 0xc($sp)
/* 0FC6F8 7F0C7BC8 8FB30010 */  lw    $s3, 0x10($sp)
/* 0FC6FC 7F0C7BCC 8FB40014 */  lw    $s4, 0x14($sp)
/* 0FC700 7F0C7BD0 03E00008 */  jr    $ra
/* 0FC704 7F0C7BD4 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
// https://decomp.me/scratch/tmXxj 99.64%
s32 texFindClosestColourIndexIA(u16 *palette, s32 numcolours, s32 intensity, s32 alpha)
{
    s32 loop_start;
    s32 loop_end;
    s32 i;
    s32 j;

    s32 bestindex;
    s32 bestvalue;

    s32 low;
    s32 colour;

    s32 value;
    s32 a;
    s32 b;
    s32 sum;

    u32 sum2; // is this real?

    // check palette for existing color
    colour = (intensity << 8) | alpha;
    for (i = 0; i < numcolours; i++)
    {
        if (palette[i] == (colour & 0xFFFFU))
        {
            return i;
        }
    }

    // binary search for a region
    low = 0;
    loop_end = numcolours - 1;
    colour = (intensity * intensity) + (alpha * alpha);

    while ((loop_end - low) >= 2)
    {
        s32 index;
        
        index = (loop_end + low) >> 1;
        value = palette[index];
        a = (((s32) value) >> 8) & 0xFF;
        b = value & 0xFF;
        sum = (a * a) + (b * b);
        if (sum < colour)
        {
            low = index;
            continue;
        }
        if (colour < sum)
        {
            loop_end = index;
        }
        else
        {
            low = index;
            loop_end = index;
        }
    }

    loop_start = loop_end - 4;
    if (loop_start < 0)
    {
        loop_start = 0;
    }

    loop_end += 4;
    if (loop_end >= numcolours)
    {
        loop_end = numcolours - 1;
    }

    // search for best within the region
    bestindex = 0;
    bestvalue = 999999;

    for (j = loop_start; j <= loop_end; j++)
    {
        value = palette[j];
        a = ((value >> 8) & 0xff) - intensity;
        b = (value & 0xff) - alpha;
        sum = (a * a) + (b * b);

        sum2 = sum; 

        if (sum < bestvalue)
        {
            bestindex = j;
            bestvalue = sum;
        }

        // Seems to need to be any variable used in the loop here?
        if (j);
    }

    return bestindex;
}
#else
GLOBAL_ASM(
.text
glabel texFindClosestColourIndexIA
/* 0FC708 7F0C7BD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0FC70C 7F0C7BDC AFB1000C */  sw    $s1, 0xc($sp)
/* 0FC710 7F0C7BE0 AFB00008 */  sw    $s0, 8($sp)
/* 0FC714 7F0C7BE4 18A00030 */  blez  $a1, .L7F0C7CA8
/* 0FC718 7F0C7BE8 00001825 */   move  $v1, $zero
/* 0FC71C 7F0C7BEC 30AA0003 */  andi  $t2, $a1, 3
/* 0FC720 7F0C7BF0 11400010 */  beqz  $t2, .L7F0C7C34
/* 0FC724 7F0C7BF4 01404025 */   move  $t0, $t2
/* 0FC728 7F0C7BF8 00067A00 */  sll   $t7, $a2, 8
/* 0FC72C 7F0C7BFC 01E74825 */  or    $t1, $t7, $a3
/* 0FC730 7F0C7C00 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC734 7F0C7C04 00007040 */  sll   $t6, $zero, 1
/* 0FC738 7F0C7C08 008E1021 */  addu  $v0, $a0, $t6
/* 0FC73C 7F0C7C0C 03004825 */  move  $t1, $t8
.L7F0C7C10:
/* 0FC740 7F0C7C10 94590000 */  lhu   $t9, ($v0)
/* 0FC744 7F0C7C14 55390004 */  bnel  $t1, $t9, .L7F0C7C28
/* 0FC748 7F0C7C18 24630001 */   addiu $v1, $v1, 1
/* 0FC74C 7F0C7C1C 10000073 */  b     .L7F0C7DEC
/* 0FC750 7F0C7C20 00601025 */   move  $v0, $v1
/* 0FC754 7F0C7C24 24630001 */  addiu $v1, $v1, 1
.L7F0C7C28:
/* 0FC758 7F0C7C28 1503FFF9 */  bne   $t0, $v1, .L7F0C7C10
/* 0FC75C 7F0C7C2C 24420002 */   addiu $v0, $v0, 2
/* 0FC760 7F0C7C30 1065001D */  beq   $v1, $a1, .L7F0C7CA8
.L7F0C7C34:
/* 0FC764 7F0C7C34 00067A00 */   sll   $t7, $a2, 8
/* 0FC768 7F0C7C38 01E74825 */  or    $t1, $t7, $a3
/* 0FC76C 7F0C7C3C 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC770 7F0C7C40 00037040 */  sll   $t6, $v1, 1
/* 0FC774 7F0C7C44 008E1021 */  addu  $v0, $a0, $t6
/* 0FC778 7F0C7C48 03004825 */  move  $t1, $t8
.L7F0C7C4C:
/* 0FC77C 7F0C7C4C 94590000 */  lhu   $t9, ($v0)
/* 0FC780 7F0C7C50 55390004 */  bnel  $t1, $t9, .L7F0C7C64
/* 0FC784 7F0C7C54 944E0002 */   lhu   $t6, 2($v0)
/* 0FC788 7F0C7C58 10000064 */  b     .L7F0C7DEC
/* 0FC78C 7F0C7C5C 00601025 */   move  $v0, $v1
/* 0FC790 7F0C7C60 944E0002 */  lhu   $t6, 2($v0)
.L7F0C7C64:
/* 0FC794 7F0C7C64 552E0004 */  bnel  $t1, $t6, .L7F0C7C78
/* 0FC798 7F0C7C68 944F0004 */   lhu   $t7, 4($v0)
/* 0FC79C 7F0C7C6C 1000005F */  b     .L7F0C7DEC
/* 0FC7A0 7F0C7C70 24620001 */   addiu $v0, $v1, 1
/* 0FC7A4 7F0C7C74 944F0004 */  lhu   $t7, 4($v0)
.L7F0C7C78:
/* 0FC7A8 7F0C7C78 552F0004 */  bnel  $t1, $t7, .L7F0C7C8C
/* 0FC7AC 7F0C7C7C 94580006 */   lhu   $t8, 6($v0)
/* 0FC7B0 7F0C7C80 1000005A */  b     .L7F0C7DEC
/* 0FC7B4 7F0C7C84 24620002 */   addiu $v0, $v1, 2
/* 0FC7B8 7F0C7C88 94580006 */  lhu   $t8, 6($v0)
.L7F0C7C8C:
/* 0FC7BC 7F0C7C8C 55380004 */  bnel  $t1, $t8, .L7F0C7CA0
/* 0FC7C0 7F0C7C90 24630004 */   addiu $v1, $v1, 4
/* 0FC7C4 7F0C7C94 10000055 */  b     .L7F0C7DEC
/* 0FC7C8 7F0C7C98 24620003 */   addiu $v0, $v1, 3
/* 0FC7CC 7F0C7C9C 24630004 */  addiu $v1, $v1, 4
.L7F0C7CA0:
/* 0FC7D0 7F0C7CA0 1465FFEA */  bne   $v1, $a1, .L7F0C7C4C
/* 0FC7D4 7F0C7CA4 24420008 */   addiu $v0, $v0, 8
.L7F0C7CA8:
/* 0FC7D8 7F0C7CA8 24A8FFFF */  addiu $t0, $a1, -1
/* 0FC7DC 7F0C7CAC 29010002 */  slti  $at, $t0, 2
/* 0FC7E0 7F0C7CB0 00001025 */  move  $v0, $zero
/* 0FC7E4 7F0C7CB4 14200027 */  bnez  $at, .L7F0C7D54
/* 0FC7E8 7F0C7CB8 01001825 */   move  $v1, $t0
/* 0FC7EC 7F0C7CBC 00C60019 */  multu $a2, $a2
/* 0FC7F0 7F0C7CC0 0000C812 */  mflo  $t9
/* 0FC7F4 7F0C7CC4 00000000 */  nop   
/* 0FC7F8 7F0C7CC8 00000000 */  nop   
/* 0FC7FC 7F0C7CCC 00E70019 */  multu $a3, $a3
/* 0FC800 7F0C7CD0 00007012 */  mflo  $t6
/* 0FC804 7F0C7CD4 032E4821 */  addu  $t1, $t9, $t6
/* 0FC808 7F0C7CD8 00000000 */  nop   
/* 0FC80C 7F0C7CDC 00625821 */  addu  $t3, $v1, $v0
.L7F0C7CE0:
/* 0FC810 7F0C7CE0 000B5043 */  sra   $t2, $t3, 1
/* 0FC814 7F0C7CE4 000AC040 */  sll   $t8, $t2, 1
/* 0FC818 7F0C7CE8 0098C821 */  addu  $t9, $a0, $t8
/* 0FC81C 7F0C7CEC 972C0000 */  lhu   $t4, ($t9)
/* 0FC820 7F0C7CF0 000C6A03 */  sra   $t5, $t4, 8
/* 0FC824 7F0C7CF4 31AE00FF */  andi  $t6, $t5, 0xff
/* 0FC828 7F0C7CF8 01CE0019 */  multu $t6, $t6
/* 0FC82C 7F0C7CFC 319000FF */  andi  $s0, $t4, 0xff
/* 0FC830 7F0C7D00 00007812 */  mflo  $t7
/* 0FC834 7F0C7D04 00000000 */  nop   
/* 0FC838 7F0C7D08 00000000 */  nop   
/* 0FC83C 7F0C7D0C 02100019 */  multu $s0, $s0
/* 0FC840 7F0C7D10 0000C012 */  mflo  $t8
/* 0FC844 7F0C7D14 01F88821 */  addu  $s1, $t7, $t8
/* 0FC848 7F0C7D18 0229082A */  slt   $at, $s1, $t1
/* 0FC84C 7F0C7D1C 50200004 */  beql  $at, $zero, .L7F0C7D30
/* 0FC850 7F0C7D20 0131082A */   slt   $at, $t1, $s1
/* 0FC854 7F0C7D24 10000007 */  b     .L7F0C7D44
/* 0FC858 7F0C7D28 01401025 */   move  $v0, $t2
/* 0FC85C 7F0C7D2C 0131082A */  slt   $at, $t1, $s1
.L7F0C7D30:
/* 0FC860 7F0C7D30 10200003 */  beqz  $at, .L7F0C7D40
/* 0FC864 7F0C7D34 01401825 */   move  $v1, $t2
/* 0FC868 7F0C7D38 10000002 */  b     .L7F0C7D44
/* 0FC86C 7F0C7D3C 01401825 */   move  $v1, $t2
.L7F0C7D40:
/* 0FC870 7F0C7D40 01401025 */  move  $v0, $t2
.L7F0C7D44:
/* 0FC874 7F0C7D44 0062C823 */  subu  $t9, $v1, $v0
/* 0FC878 7F0C7D48 2B210002 */  slti  $at, $t9, 2
/* 0FC87C 7F0C7D4C 5020FFE4 */  beql  $at, $zero, .L7F0C7CE0
/* 0FC880 7F0C7D50 00625821 */   addu  $t3, $v1, $v0
.L7F0C7D54:
/* 0FC884 7F0C7D54 2462FFFC */  addiu $v0, $v1, -4
/* 0FC888 7F0C7D58 04410002 */  bgez  $v0, .L7F0C7D64
/* 0FC88C 7F0C7D5C 24630004 */   addiu $v1, $v1, 4
/* 0FC890 7F0C7D60 00001025 */  move  $v0, $zero
.L7F0C7D64:
/* 0FC894 7F0C7D64 0065082A */  slt   $at, $v1, $a1
/* 0FC898 7F0C7D68 14200002 */  bnez  $at, .L7F0C7D74
/* 0FC89C 7F0C7D6C 00002825 */   move  $a1, $zero
/* 0FC8A0 7F0C7D70 01001825 */  move  $v1, $t0
.L7F0C7D74:
/* 0FC8A4 7F0C7D74 3C08000F */  lui   $t0, (0x000F423F >> 16) # lui $t0, 0xf
/* 0FC8A8 7F0C7D78 0062082A */  slt   $at, $v1, $v0
/* 0FC8AC 7F0C7D7C 3508423F */  ori   $t0, (0x000F423F & 0xFFFF) # ori $t0, $t0, 0x423f
/* 0FC8B0 7F0C7D80 14200019 */  bnez  $at, .L7F0C7DE8
/* 0FC8B4 7F0C7D84 00405025 */   move  $t2, $v0
/* 0FC8B8 7F0C7D88 00027040 */  sll   $t6, $v0, 1
/* 0FC8BC 7F0C7D8C 008E1021 */  addu  $v0, $a0, $t6
/* 0FC8C0 7F0C7D90 246B0001 */  addiu $t3, $v1, 1
.L7F0C7D94:
/* 0FC8C4 7F0C7D94 944C0000 */  lhu   $t4, ($v0)
/* 0FC8C8 7F0C7D98 000C7A03 */  sra   $t7, $t4, 8
/* 0FC8CC 7F0C7D9C 31F800FF */  andi  $t8, $t7, 0xff
/* 0FC8D0 7F0C7DA0 03061823 */  subu  $v1, $t8, $a2
/* 0FC8D4 7F0C7DA4 00630019 */  multu $v1, $v1
/* 0FC8D8 7F0C7DA8 319900FF */  andi  $t9, $t4, 0xff
/* 0FC8DC 7F0C7DAC 03272023 */  subu  $a0, $t9, $a3
/* 0FC8E0 7F0C7DB0 00007012 */  mflo  $t6
/* 0FC8E4 7F0C7DB4 00000000 */  nop   
/* 0FC8E8 7F0C7DB8 00000000 */  nop   
/* 0FC8EC 7F0C7DBC 00840019 */  multu $a0, $a0
/* 0FC8F0 7F0C7DC0 00007812 */  mflo  $t7
/* 0FC8F4 7F0C7DC4 01CF4821 */  addu  $t1, $t6, $t7
/* 0FC8F8 7F0C7DC8 0128082A */  slt   $at, $t1, $t0
/* 0FC8FC 7F0C7DCC 50200004 */  beql  $at, $zero, .L7F0C7DE0
/* 0FC900 7F0C7DD0 254A0001 */   addiu $t2, $t2, 1
/* 0FC904 7F0C7DD4 01402825 */  move  $a1, $t2
/* 0FC908 7F0C7DD8 01204025 */  move  $t0, $t1
/* 0FC90C 7F0C7DDC 254A0001 */  addiu $t2, $t2, 1
.L7F0C7DE0:
/* 0FC910 7F0C7DE0 156AFFEC */  bne   $t3, $t2, .L7F0C7D94
/* 0FC914 7F0C7DE4 24420002 */   addiu $v0, $v0, 2
.L7F0C7DE8:
/* 0FC918 7F0C7DE8 00A01025 */  move  $v0, $a1
.L7F0C7DEC:
/* 0FC91C 7F0C7DEC 8FB00008 */  lw    $s0, 8($sp)
/* 0FC920 7F0C7DF0 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FC924 7F0C7DF4 03E00008 */  jr    $ra
/* 0FC928 7F0C7DF8 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif


/**
 * Inflate images (levels of detail) from a non-zlib texture.
 *
 * Each image can have a different compression method and pixel format,
 * which is described in a three byte header per image:
 *
 * ffffwwww wwwwhhhh hhhhcccc
 *
 * f = pixel format (see TEXFORMAT constants)
 * w = width in pixels
 * h = height in pixels
 * c = compression method (see TEXCOMPMETHOD constants)
 */
s32 texInflateNonZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texpool *arg4)
{
    u8 scratch[0x2000];
    u8 lookup[0x1000];
    u32 stack;
    s32 i;
    s32 numimages;
    s32 width;
    s32 height;
    s32 compmethod;
    s32 j;
    s32 totalbytesout = 0;
    s32 imagebytesout;
    s32 format;
    s32 value;
    u8 *start;
    u8 *end;
    s32 writetocache = FALSE;

    texSetBitstring(src);

    numimages = arg2 && forcenumimages ? forcenumimages : 1;

    arg4->rightpos->maxlod = forcenumimages;
    arg4->rightpos->unk0c_02 = arg2;

    if (arg2)
    {
        writetocache = TRUE;

        for (i = 0; i < g_TexCacheCount; i++)
        {
            if (g_TexCacheItems[i].texturenum == arg4->rightpos->texturenum)
            {
                writetocache = FALSE;
            }
        }
    }

    for (i = 0; i < numimages; i++)
    {
        format = texReadBits(4);
        width = texReadBits(8);
        height = texReadBits(8);
        compmethod = texReadBits(4);

        if (i == 0)
        {
            arg4->rightpos->width = width;
            arg4->rightpos->height = height;
            arg4->rightpos->gbiformat = g_TexFormatGbiMappings[format];
            arg4->rightpos->depth = g_TexFormatDepths[format];
            arg4->rightpos->lutmodeindex = g_TexFormatLutModes[format] >> G_MDSFT_TEXTLUT;
        }
        else if (writetocache)
        {
            g_TexCacheItems[g_TexCacheCount].widths[i - 1] = width;
            g_TexCacheItems[g_TexCacheCount].heights[i - 1] = height;
        }

        if (width * height > 0x2000)
        {
            return 0;
        }

        switch (compmethod)
        {
            case TEXCOMPMETHOD_UNCOMPRESSED0:
            case TEXCOMPMETHOD_UNCOMPRESSED1:
                imagebytesout = texReadUncompressed(&dst[totalbytesout], width, height, format);
                break;

            case TEXCOMPMETHOD_HUFFMAN:
                texInflateHuffman(scratch, g_TexFormatNumChannels[format] * width * height, g_TexFormatChannelSizes[format]);

                if (g_TexFormatHas1BitAlpha[format])
                {
                    texReadAlphaBits(&scratch[width * height * 3], width * height);
                }

                imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
                break;

            case TEXCOMPMETHOD_HUFFMANPERHCHANNEL:
                for (j = 0; j < g_TexFormatNumChannels[format]; j++)
                {
                    if (1);
                    texInflateHuffman(&scratch[width * height * j], width * height, g_TexFormatChannelSizes[format]);
                }

                if (g_TexFormatHas1BitAlpha[format])
                {
                    texReadAlphaBits(&scratch[width * height * 3], width * height);
                }

                imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
                break;

            case TEXCOMPMETHOD_RLE:
                texInflateRle(scratch, g_TexFormatNumChannels[format] * width * height);

                if (g_TexFormatHas1BitAlpha[format])
                {
                    texReadAlphaBits(&scratch[width * height * 3], width * height);
                }

                imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
                break;

            case TEXCOMPMETHOD_LOOKUP:
                value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
                imagebytesout = texInflateLookup(width, height, &dst[totalbytesout], lookup, value, format);
                break;

            case TEXCOMPMETHOD_HUFFMANLOOKUP:
                value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
                texInflateHuffman(scratch, width * height, value);
                imagebytesout = texInflateLookupFromBuffer(scratch, width, height, &dst[totalbytesout], lookup, value, format);
                break;

            case TEXCOMPMETHOD_RLELOOKUP:
                value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
                texInflateRle(scratch, width * height);
                imagebytesout = texInflateLookupFromBuffer(scratch, width, height, &dst[totalbytesout], lookup, value, format);
                break;

            case TEXCOMPMETHOD_HUFFMANBLUR:
                stack = texReadBits(3);
                texInflateHuffman(scratch, g_TexFormatNumChannels[format] * width * height, g_TexFormatChannelSizes[format]);
                texBlur(scratch, width, g_TexFormatNumChannels[format] * height, stack, g_TexFormatChannelSizes[format]);

                if (g_TexFormatHas1BitAlpha[format])
                {
                    texReadAlphaBits(&scratch[width * height * 3], width * height);
                }

                imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
                break;

            case TEXCOMPMETHOD_RLEBLUR:
                stack = texReadBits(3);
                texInflateRle(scratch, g_TexFormatNumChannels[format] * width * height);
                texBlur(scratch, width, g_TexFormatNumChannels[format] * height, stack, g_TexFormatChannelSizes[format]);

                if (g_TexFormatHas1BitAlpha[format])
                {
                    texReadAlphaBits(&scratch[width * height * 3], width * height);
                }

                imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
                break;

            default:
                while (TRUE)
                {
                    // Hang forever!
                };
        }

        if (arg2 == 1 && forcenumimages > 0)
        {
            texSwapAltRowBytes(&dst[totalbytesout], width, height, format);
        }

        imagebytesout = (imagebytesout + 7) & ~7;
        totalbytesout += imagebytesout;

        if (img_bitcount == 0)
        {
            img_curpos++;
        }
        else
        {
            img_bitcount = 0;
        }
    }

    if (writetocache)
    {
        g_TexCacheItems[g_TexCacheCount].texturenum = arg4->rightpos->texturenum;

        g_TexCacheCount++;

        // Resetting this variable to 0 here suggests that the g_TexCacheItems
        // array is used in a circular manner, and that g_TexCacheCount is just
        // the index of the oldest/next element. But earlier in this function
        // there's a loop that iterates up to g_TexCacheCount, which doesn't
        // make any sense if this value is used as a pointer in a circular list.
        // Could be a @bug, or maybe they intended to reset the cache every time
        // it fills up.
        if (g_TexCacheCount >= ARRAYCOUNT(g_TexCacheItems))
        {
            g_TexCacheCount = 0;
        }
    }

    if (!arg2)
    {
        if (forcenumimages >= 2)
        {
            s32 tmpwidth = width;
            s32 tmpheight = height;

            start = dst;
            end = &dst[totalbytesout];

            for (i = 1; i < forcenumimages; i++)
            {
                imagebytesout = texShrinkNonPaletted(start, end, tmpwidth, tmpheight, format);

                texSwapAltRowBytes(start, tmpwidth, tmpheight, format);

                totalbytesout += imagebytesout;

                tmpwidth = (tmpwidth + 1) >> 1;
                tmpheight = (tmpheight + 1) >> 1;

                start = end;
                end += imagebytesout;
            }

            texSwapAltRowBytes(start, tmpwidth, tmpheight, format);
        }
        else if (forcenumimages == 1)
        {
            texSwapAltRowBytes(dst, width, height, format);
        }
    }

    return totalbytesout;
}


/**
 * Shrink a non-paletted texture to half its size by averaging each each 2x2
 * group of pixels.
 *
 * Return the number of bytes written.
 *
 * If the source width is an odd number, the destination's final column is
 * calculated by sampling the final source column twice. Likewise for the height.
 */

s32 texShrinkNonPaletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format)
{
    s32 i;
    s32 j;
    s32 alignedsrcwidth;
    s32 aligneddstwidth;
    u32 *dst32 = (u32 *) dst;
    u16 *dst16 = (u16 *) dst;
    u8 *dst8 = dst;
    u32 *src32 = (u32 *) src;
    u16 *src16 = (u16 *) src;
    u8 *src8 = src;
    s32 dstheight = (srcheight + 1) >> 1;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 c;
    u32 tl32;
    u32 tr32;
    u32 bl32;
    u32 br32;
    u16 tl16;
    u16 tr16;
    u16 bl16;
    u16 br16;
    u8 tl8;
    u8 tr8;
    u8 bl8;
    u8 br8;
    s32 nextrow;
    s32 nextcol;

    switch (format)
    {
        case TEXFORMAT_RGBA32:
        case TEXFORMAT_RGB24:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 3) & 0xffc;
            alignedsrcwidth = (srcwidth + 3) & 0xffc;
            break;
        case TEXFORMAT_RGBA16:
        case TEXFORMAT_RGB15:
        case TEXFORMAT_IA16:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 3) & 0xffc;
            alignedsrcwidth = (srcwidth + 3) & 0xffc;
            break;
        case TEXFORMAT_IA8:
        case TEXFORMAT_I8:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 7) & 0xff8;
            alignedsrcwidth = (srcwidth + 7) & 0xff8;
            break;
        case TEXFORMAT_IA4:
        case TEXFORMAT_I4:
            aligneddstwidth = (((srcwidth + 1) >> 1) + 15) & 0xff0;
            alignedsrcwidth = (srcwidth + 15) & 0xff0;
            break;
    }

    switch (format)
    {
        case TEXFORMAT_RGBA32:
        case TEXFORMAT_RGB24:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    tl32 = src32[j];
                    tr32 = src32[nextcol];
                    bl32 = src32[nextrow + j];
                    br32 = src32[nextrow + nextcol];

                    r = ((((tl32 >> 24) & 0xff) + ((tr32 >> 24) & 0xff) + ((bl32 >> 24) & 0xff) + ((br32 >> 24) & 0xff)) >> 2) & 0xff;
                    g = ((((tl32 >> 16) & 0xff) + ((tr32 >> 16) & 0xff) + ((bl32 >> 16) & 0xff) + ((br32 >> 16) & 0xff)) >> 2) & 0xff;
                    b = ((((tl32 >>  8) & 0xff) + ((tr32 >>  8) & 0xff) + ((bl32 >>  8) & 0xff) + ((br32 >>  8) & 0xff)) >> 2) & 0xff;
                    a = ((((tl32 >>  0) & 0xff) + ((tr32 >>  0) & 0xff) + ((bl32 >>  0) & 0xff) + ((br32 >>  0) & 0xff) + 1) >> 2) & 0xff;

                    dst32[j >> 1] = r << 24 | g << 16 | b << 8 | a;
                }

                dst32 += aligneddstwidth;
                src32 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth * 4;

        case TEXFORMAT_RGBA16:
        case TEXFORMAT_RGB15:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    tl16 = src16[j];
                    tr16 = src16[nextcol];
                    bl16 = src16[nextrow + j];
                    br16 = src16[nextrow + nextcol];

                    r = ((((tl16 >> 11) & 0x1f) + ((tr16 >> 11) & 0x1f) + ((bl16 >> 11) & 0x1f) + ((br16 >> 11) & 0x1f)) >> 2) & 0x1f;
                    g = ((((tl16 >>  6) & 0x1f) + ((tr16 >>  6) & 0x1f) + ((bl16 >>  6) & 0x1f) + ((br16 >>  6) & 0x1f)) >> 2) & 0x1f;
                    b = ((((tl16 >>  1) & 0x1f) + ((tr16 >>  1) & 0x1f) + ((bl16 >>  1) & 0x1f) + ((br16 >>  1) & 0x1f)) >> 2) & 0x1f;
                    a = ((((tl16 >>  0) & 0x01) + ((tr16 >>  0) & 0x01) + ((bl16 >>  0) & 0x01) + ((br16 >>  0) & 0x01) + 2) >> 2) & 0x01;

                    dst16[j >> 1] = r << 11 | g << 6 | b << 1 | a;
                }

                dst16 += aligneddstwidth;
                src16 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth * 2;

        case TEXFORMAT_IA16:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    tl16 = src16[j];
                    tr16 = src16[nextcol];
                    bl16 = src16[nextrow + j];
                    br16 = src16[nextrow + nextcol];

                    c = (((tl16 >> 8) & 0xff) + ((tr16 >> 8) & 0xff) + ((bl16 >> 8) & 0xff) + ((br16 >> 8) & 0xff)) >> 2;
                    a = ((tl16 & 0xff) + (tr16 & 0xff) + (bl16 & 0xff) + (br16 & 0xff) + 1) >> 2;

                    dst16[j >> 1] = ((u8)c << 8) | (a & 0xFF);
                }

                dst16 += aligneddstwidth;
                src16 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth * 2;

        case TEXFORMAT_IA8:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    tl8 = src8[j];
                    tr8 = src8[nextcol];
                    bl8 = src8[nextrow + j];
                    br8 = src8[nextrow + nextcol];

                    c = ((((tl8 >> 4) & 0xf) + ((tr8 >> 4) & 0xf) + ((bl8 >> 4) & 0xf) + ((br8 >> 4) & 0xf)) << 2) & 0xF0;
                    a = (((tl8 & 0xf) + (tr8 & 0xf) + (bl8 & 0xf) + (br8 & 0xf) + 1) >> 2) & 0xF;

                    dst8[j >> 1] = c | a;
                }

                dst8 += aligneddstwidth;
                src8 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth;

        case TEXFORMAT_I8:
            for (i = 0; i < srcheight; i += 2)
            {
                nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

                for (j = 0; j < alignedsrcwidth; j += 2)
                {
                    nextcol = j + 1 < srcwidth ? j + 1 : j;

                    tl8 = src8[j];
                    tr8 = src8[nextcol];
                    bl8 = src8[nextrow + j];
                    br8 = src8[nextrow + nextcol];

                    c = (u16)((tl8 + tr8 + bl8 + br8 + 1) >> 2);

                    dst8[j >> 1] = c;
                }

                dst8 += aligneddstwidth;
                src8 += alignedsrcwidth * 2;
            }

            return dstheight * aligneddstwidth;

        case TEXFORMAT_IA4:
            for (i = 0; i < srcheight; i += 2)
            {
                nextcol = i + 1;

                for (j = 0; j < alignedsrcwidth; j += 4)
                {
                    tl8 = src8[j >> 1];
                    tr8 = src8[(nextcol < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1)];
                    bl8 = src8[(j >> 1) + 1];
                    br8 = src8[(nextcol < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1) + 1];

                    c = (((((tl8 >> 5) & 7) + ((tl8 >> 1) & 7) + ((tr8 >> 5) & 7) + ((tr8 >> 1) & 7)) << 3) & 0xe0)
                        | (((((bl8 >> 5) & 7) + ((bl8 >> 1) & 7) + ((br8 >> 5) & 7) + ((br8 >> 1) & 7)) >> 1) & 0xe);

                    a = (((((tl8 >> 4) & 1) + (tl8 & 1) + ((tr8 >> 4) & 1) + (tr8 & 1) + 1) << 2) & 0x10)
                        | (((((bl8 >> 4) & 1) + (bl8 & 1) + ((br8 >> 4) & 1) + (br8 & 1) + 1) >> 2) & 1);

                    dst8[j >> 2] = c | a;
                }

                dst8 += aligneddstwidth >> 1;
                src8 += alignedsrcwidth;
            }

            return (aligneddstwidth >> 1) * dstheight;

        case TEXFORMAT_I4:
            for (i = 0; i < srcheight; i += 2)
            {
                for (j = 0; j < alignedsrcwidth; j += 4)
                {
                    tl8 = src8[j >> 1];
                    tr8 = src8[(i + 1 < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1)];
                    bl8 = src8[(j >> 1) + 1];
                    br8 = src8[(i + 1 < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1) + 1];

                    c = ((((tl8 >> 4) & 0xf) + (tl8 & 0xf) + ((tr8 >> 4) & 0xf) + (tr8 & 0xf)) << 2) & 0xf0;
                    a = ((((bl8 >> 4) & 0xf) + (bl8 & 0xf) + ((br8 >> 4) & 0xf) + (br8 & 0xf)) >> 2) & 0xf;

                    dst8[j >> 2] = c | a;
                }

                dst8 += aligneddstwidth >> 1;
                src8 += alignedsrcwidth;
            }

            return (aligneddstwidth >> 1) * dstheight;
    }

    return 0;
}


/**
 * Inflate Huffman data.
 *
 * This function operates on single channels rather than whole colours.
 * For example, for an RGBA32 image this function may be called once for each
 * channel with chansize = 256. This means the resulting data is in the format
 * RRR...GGG...BBB...AAA..., and the caller must convert it into a proper pixel
 * format.
 *
 * A typical Huffman implementation stores a tree, where each node contains
 * the lookup value and its frequency (number of uses). However, Rare's
 * implementation only stores a list of frequencies. It uses the chansize
 * to know how many values there are.
 */
void texInflateHuffman(u8 *dst, s32 numiterations, s32 chansize)
{
	u16 frequencies[2048];
	s16 nodes[2048][2];
	s32 i;
	s32 rootindex;
	s32 sum;
	u16 minfreq1;
	u16 minfreq2;
	s32 minindex1; // 5c
	s32 minindex2; // 58
	s32  done = 0;

	// Read the frequencies list
	for (i = 0; i < chansize; i++) {
		frequencies[i] = texReadBits(8);
	}

	// Initialise the tree
	for (i = 0; i < 2048; i++) {
		nodes[i][0] = -1;
		nodes[i][1] = -1;
	}

	// Find the two smallest frequencies
	minfreq1 = 9999;
	minfreq2 = 9999;

	for (i = 0; i < chansize; i++) {
		if (frequencies[i] < minfreq1) {
			if (minfreq2 < minfreq1) {
				minfreq1 = frequencies[i];
				minindex1 = i;
			} else {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		} else if (frequencies[i] < minfreq2) {
			minfreq2 = frequencies[i];
			minindex2 = i;
		}
	}

	// Build the tree.
	// For each node in tree, a branch value < 10000 means this branch
	// leads to another node, and the value is the target node's index.
	// A branch value >= 10000 means the branch is a leaf node,
	// and the value is the channel value + 10000.
	while (!done) {
		sum = frequencies[minindex1] + frequencies[minindex2];

		if (sum == 0) {
			sum = 1;
		}

		frequencies[minindex1] = 9999;
		frequencies[minindex2] = 9999;

		if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
			nodes[minindex1][0] = minindex1 + 10000;
			rootindex = minindex1;
			frequencies[minindex1] = sum;

			if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
				nodes[minindex1][1] = minindex2 + 10000;
			} else {
				nodes[minindex1][1] = minindex2;
			}
		} else if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
			nodes[minindex2][0] = minindex2 + 10000;
			rootindex = minindex2;
			frequencies[minindex2] = sum;

			if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
				nodes[minindex2][1] = minindex1 + 10000;
			} else {
				nodes[minindex2][1] = minindex1;
			}
		} else {
			for (rootindex = 0; nodes[rootindex][0] >= 0 || nodes[rootindex][1] >= 0 || frequencies[rootindex] < 9999; rootindex++);

			frequencies[rootindex] = sum;
			nodes[rootindex][0] = minindex1;
			nodes[rootindex][1] = minindex2;
		}

		// Find the two smallest frequencies again for the next iteration
		minfreq1 = 9999;
		minfreq2 = 9999;

		for (i = 0; i < chansize; i++) {
			if (frequencies[i] < minfreq1) {
				if (minfreq1 > minfreq2) {
					minfreq1 = frequencies[i];
					minindex1 = i;
				} else {
					minfreq2 = frequencies[i];
					minindex2 = i;
				}
			} else if (frequencies[i] < minfreq2) {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		}

		if (minfreq1 == 9999 || minfreq2 == 9999) {
			done = 1;
		}
	}

	// Read bits off the bitstring, traverse the tree
	// and write the channel values to dst
	for (i = 0; i < numiterations; i++) {
		s32 indexorvalue = rootindex;

		while (indexorvalue < 10000) {
			indexorvalue = nodes[indexorvalue][texReadBits(1)];
		}

		if (chansize <= 256) {
			dst[i] = indexorvalue - 10000;
		} else {
			u16 *tmp = (u16 *)dst;
			tmp[i] = indexorvalue - 10000;
		}
	}
}




/**
 * Inflate runlength-encoded data.
 *
 * This data consists of a 10 bit header followed by a list of directives,
 * where each directive can either be a literal block or a repeat (run) of
 * blocks within a sliding window.
 *
 * The header format is:
 *
 * 3 bits btfieldsize: The size in bits of the backtrack distance fields
 * 3 bits rlfieldsize: The size in bits of the runlen fields
 * 4 bits blocksize: The size in bits of each block of data
 *
 * In the data, the first bit is 0 if it's a literal block or 1 if it's a run.
 *
 * For literal blocks, the next <blocksize> bits should be read and appended to
 * the output stream.
 *
 * For runs, the next <btfieldsize> bits are the backtrack length (in blocks)
 * plus one, and the next <rlfieldsize> bits are the run length (in blocks)
 * minus a calculated fudge value.
 *
 * The fudge value is calculated based on the field sizes. For small runs it is
 * more space efficient to use multiple literal directives rather than a run
 * directive. Because of this, smaller runs are not used and the run lengths
 * in the data can be offset accordingly - this offset is the fudge value.
 *
 * Every run must be followed by a literal block without the 1-bit marker.
 * The algorithm does not support back to back runs.
 */
void texInflateRle(u8 *dst, s32 blockstotal)
{
	s32 btfieldsize = texReadBits(3);
	s32 rlfieldsize = texReadBits(3);
	s32 blocksize = texReadBits(4);
	s32 cost;
	s32 fudge;
	s32 blocksdone;
	s32 i;

	// Calculate the fudge value
	cost = btfieldsize + rlfieldsize + blocksize + 1;
	fudge = 0;

	while (cost > 0) {
		cost = cost - blocksize - 1;
		fudge++;
	}

	blocksdone = 0;

	while (blocksdone < blockstotal) {
		if (texReadBits(1) == 0) {
			// Found a literal directive
			if (blocksize <= 8) {
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		} else {
			// Found a run directive
			s32 startblockindex = blocksdone - texReadBits(btfieldsize) - 1;
			s32 runnumblocks = texReadBits(rlfieldsize) + fudge;

			if (blocksize <= 8) {
				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					dst[blocksdone] = dst[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;

				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					tmp[blocksdone] = tmp[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		}
	}
}




/**
 * Populate a lookup table by reading it out of the bit string.
 *
 * The first 11 bits denote the number of colours in the lookup table.
 * The data following this is a list of colours, where each colour is sized
 * according to the texture's format.
 *
 * This function does NOT work with pixel formats of 8 bits or less.
 */
s32 texBuildLookup(s8 *lookup, s32 bitsperpixel)
{
    s32 numcolors = texReadBits(11);
    s32 i;
    
    if (bitsperpixel <= 16)
    {
        u16 *image = (u16*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(bitsperpixel);
        }
    }
    else if (bitsperpixel <= 24)
    {
        u32 *image = (u32*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(bitsperpixel);
        }
    }
    else
    {
        u32 *image = (u32*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(24) << 8 | texReadBits(bitsperpixel - 24);
        }
    }
    return numcolors;
}






s32 texGetBitSize(s32 decimal)
{
	s32 count = 0;

	decimal--;

	while (decimal > 0) {
		decimal >>= 1;
		count++;
	}

	return count;
}



void texReadAlphaBits(u8 *image,s32 count)
{
  int i;
  
    for(i = 0; i < count; i++)
    {
          image[i] = texReadBits(1);
    }
}



/**
 * Read pixel data from the bitstream and write to dst,
 * ensuring each row is aligned according to the pixel format.
 *
 * Return the number of output bytes.
 */
s32 texReadUncompressed(u8 *dst, s32 width, s32 height, s32 format)
{
	u32 *dst32 = (u32 *)(((u32)dst + 0xf) & ~0xf);
	u16 *dst16 = (u16 *)(((u32)dst + 7) & ~7);
	u8 *dst8 = (u8 *)(((u32)dst + 7) & ~7);
	s32 x;
	s32 y;

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(16) << 16;
				dst32[x] |= texReadBits(16);
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(24) << 8 | 0xff;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(16);
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(15) << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = texReadBits(8);
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = texReadBits(8);
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}


s32 texChannelsToPixels(u8 *src, s32 width, s32 height, u8 *dst, s32 format)
{
    u32 *dst32;
    u16 *dst16;
    u8 *dst8;
    s32 x;
    s32 y;
    s32 pos;
    s32 mult;
    s32 rgb_width;

    dst32 = (u32 *)dst;
    dst16 = (u16 *)dst;
    dst8  = (u8 *)dst;

    pos = 0;
    mult = width * height;
    rgb_width = (width + 3) & 0xffc;

    switch (format)
    {
        case TEXFORMAT_RGBA32:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | src[pos + mult * 3];
                    pos++;
                }

                dst32 += rgb_width;
            }

            return (rgb_width) * height * 4;

        case TEXFORMAT_RGB24:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | 0xff;
                    pos++;
                }

                dst32 += rgb_width;
            }

            return (rgb_width) * height * 4;

        case TEXFORMAT_RGBA16:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | src[pos + mult * 3];
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_IA16:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 8 | src[pos + mult];
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_RGB15:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | 1;
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_IA8:
            for (y = 0; y < height; y++)
            {
                if ((width + 7) & 0xff8);

                for (x = 0; x < width; x++)
                {
                    dst8[x] = src[pos] << 4 | src[pos + mult];
                    pos++;
                }

                dst8 += (width + 7) & 0xff8;
            }

            return ((width + 7) & 0xff8) * height;

        case TEXFORMAT_I8:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst8[x] = src[pos];
                    pos++;
                }

                dst8 += (width + 7) & 0xff8;
            }

            return ((width + 7) & 0xff8) * height;

        case TEXFORMAT_IA4:
            for (y = 0; y < height; y++)
            {
                if ((width + 15) & 0xff0);

                for (x = 0; x < width; x += 2)
                {
                    dst8[x >> 1] = src[pos] << 5 | src[pos + mult * 3] << 4 | src[pos + 1] << 1 | src[pos + mult * 3 + 1];
                    pos += 2;
                }

                if (width & 1) { pos--; }

                dst8 += (width + 15) & 0xff0;
            }

            return (((width + 15) & 0xff0) >> 1) * height;

        case TEXFORMAT_I4:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x += 2)
                {
                    dst8[x >> 1] = src[pos] << 4 | src[pos + 1];
                    pos += 2;
                }

                if (width & 1) { pos--; }

                dst8 += ((width + 15) & 0xff0) >> 1;
            }

            return (((width + 15) & 0xff0) >> 1) * height;
    }

    return 0;
}


/**
 * Inflate a texture using the provided lookup table.
 *
 * The lookup table is a bitstring of colours in the pixel format described by
 * the format argument. The number of colours in the lookup table is given by
 * the numcolours argument.
 *
 * The data in the global source bitstring is expected to be a tightly packed
 * list of indices into the lookup table. The number of bits for each index
 * is calculated based on the number of colours in the lookup table. For
 * example, if the lookup table contains 8 colours then the indices will be 0-7,
 * which requires 3 bits per index.
 *
 * Return the number of bytes written to dst.
 */
s32 texInflateLookup(s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
	u32 *lookup32 = (u32 *)lookup;
	u16 *lookup16 = (u16 *)lookup;
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;
	s32 x;
	s32 y;
	s32 bitspercolour = texGetBitSize(numcolours);

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)];
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)] << 8;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)] << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = lookup16[texReadBits(bitspercolour)] << 4;

				if (x + 1 < width) {
					dst8[x >> 1] |= lookup[(texReadBits(bitspercolour) * 2) + 1];
				}
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}


/**
 * Like texInflateLookup, but the indices are provided in the src argument
 * as u8s or u16s rather than read from the global bitstring as tightly packed
 * bits.
 *
 * Whether u8s or u16s are expected depends on whether the number of colours
 * in the lookup table. If there are more than 256 colours then it must use
 * u16s, otherwise it expects u8s.
 */

s32 texInflateLookupFromBuffer(u8 *src, s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
    s32 x;
    s32 y;
    u32 *lookup32;
    u16 *lookup16;
    u8 *src8;
    u16 *src16;
    u32 *dst32;
    u16 *dst16;
    u8 *dst8;
    u32 basic_and_val;

    lookup32 = (u32 *)lookup;
    lookup16 = (u16 *)lookup;

    basic_and_val = 0xffc;

    dst32 = (u32 *)dst;
    dst16 = (u16 *)dst;
    dst8 = (u8 *)dst;

    if (numcolours <= 256)
    {
        src8 = (u8 *)src;
    }
    else
    {
        src16 = (u16 *)src;
    }

    switch (format)
    {
        case TEXFORMAT_RGBA32:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    if (numcolours <= 256)
                    {
                        dst32[x] = lookup32[src8[x]];
                    }
                    else
                    {
                        dst32[x] = lookup32[src16[x]];
                    }
                }

                dst32 += (width + 3) & basic_and_val;
                src8 += width;
                src16 += width;
            }

            return ((width + 3) & basic_and_val) * height * 4;

        case TEXFORMAT_RGB24:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    if (numcolours <= 256)
                    {
                        dst32[x] = lookup32[src8[x]] << 8 | 0xff;
                    }
                    else
                    {
                        dst32[x] = lookup32[src16[x]] << 8 | 0xff;
                    }
                }

                dst32 += (width + 3) & basic_and_val;
                src8 += width;
                src16 += width;
            }

            return ((width + 3) & basic_and_val) * height * 4;

        case TEXFORMAT_RGBA16:
        case TEXFORMAT_IA16:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    if (numcolours <= 256)
                    {
                        dst16[x] = lookup16[src8[x]];
                    }
                    else
                    {
                        dst16[x] = lookup16[src16[x]];
                    }
                }

                dst16 += (width + 3) & basic_and_val;
                src8 += width;
                src16 += width;
            }

            return ((width + 3) & basic_and_val) * height * 2;

        case TEXFORMAT_RGB15:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    if (numcolours <= 256)
                    {
                        dst16[x] = lookup16[src8[x]] << 1 | 1;
                    }
                    else
                    {
                        dst16[x] = lookup16[src16[x]] << 1 | 1;
                    }
                }

                dst16 += (width + 3) & basic_and_val;
                src8 += width;
                src16 += width;
            }

            return ((width + 3) & basic_and_val) * height * 2;

        case TEXFORMAT_IA8:
        case TEXFORMAT_I8:
            for (y = 0; y < height; y++)
            {
                if ((width + 7) & 0xff8);

                for (x = 0; x < width; x++)
                {
                    if (numcolours <= 256)
                    {
                        dst8[x] = lookup16[src8[x]];
                    }
                    else
                    {
                        dst8[x] = lookup16[src16[x]];
                    }
                }

                dst8 += (width + 7) & 0xff8;
                src8 += width;
                src16 += width;
            }

            return ((width + 7) & 0xff8) * height;

        case TEXFORMAT_IA4:
        case TEXFORMAT_I4:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x += 2)
                {
                    if (numcolours <= 256)
                    {
                        dst8[x >> 1] = lookup16[src8[x]] << 4 | lookup16[src8[x + 1]];
                    }
                    else
                    {
                        dst8[x >> 1] = lookup16[src16[x]] << 4 | lookup16[src16[x + 1]];
                    }
                }

                dst8 += ((width + 15) & 0xff0) >> 1;
                src8 += width;
                src16 += width;
            }

            return (((width + 15) & 0xff0) >> 1) * height;
    }

    return 0;
}


/**
 * For every second row, swap the bytes within that row.
 *
 * For textures with 32-bit colour values (in GBI format), swap every pair
 * within each word. For all other textures, swap every byte within each pair.
 */
void texSwapAltRowBytes(u8 *dst, s32 width, s32 height, s32 format)
{
	s32 x;
	s32 y;
	s32 alignedwidth;
	u32 *row = (u32 *)dst;
	s32 tmp;

	switch (format) {
	case TEXFORMAT_RGBA32:
	case TEXFORMAT_RGB24:
		alignedwidth = (width + 3) & 0xffc;
		break;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_RGB15:
	case TEXFORMAT_IA16:
		alignedwidth = ((width + 3) & 0xffc) >> 1;
		break;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
	case TEXFORMAT_RGBA16_CI8:
	case TEXFORMAT_IA16_CI8:
		alignedwidth = ((width + 7) & 0xff8) >> 2;
		break;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
	case TEXFORMAT_RGBA16_CI4:
	case TEXFORMAT_0C:
		alignedwidth = ((width + 0xf) & 0xff0) >> 3;
		break;
	}

	row += alignedwidth;

	if (format == TEXFORMAT_RGBA32 || format == TEXFORMAT_RGB24) {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 4) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 2];
				row[x + 2] = tmp;

				tmp = row[x + 1];
				row[x + 1] = row[x + 3];
				row[x + 3] = tmp;
			}

			row += alignedwidth * 2;
		}
	} else {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 2) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 1];
				row[x + 1] = tmp;
			}

			row += alignedwidth * 2;
		}
	}
}






/**
 * Blur the pixels in the image with the surrounding pixels.
 */
void texBlur(u8 *pixels, s32 width, s32 height, s32 method, s32 chansize)
{
	s32 x;
	s32 y;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			s32 cur = pixels[y * width + x] + chansize * 2;
			s32 left = x > 0 ? pixels[y * width + x - 1] : 0;
			s32 above = y > 0 ? pixels[(y - 1) * width + x] : 0;
			s32 aboveleft = x > 0 && y > 0 ? pixels[(y - 1) * width + x - 1] : 0;

			switch (method) {
			case 0:
				pixels[y * width + x] = (cur + left) % chansize;
				break;
			case 1:
				pixels[y * width + x] = (cur + above) % chansize;
				break;
			case 2:
				pixels[y * width + x] = (cur + aboveleft) % chansize;
				break;
			case 3:
				pixels[y * width + x] = (cur + (left + above - aboveleft)) % chansize;
				break;
			case 4:
				pixels[y * width + x] = (cur + ((above - aboveleft) / 2 + left)) % chansize;
				break;
			case 5:
				pixels[y * width + x] = (cur + ((left - aboveleft) / 2 + above)) % chansize;
				break;
			case 6:
				pixels[y * width + x] = (cur + ((left + above) / 2)) % chansize;
				break;
			}
		}
	}
}


void texInitPool(struct texpool *arg0, u8 *arg1, s32 arg2)
{
    arg0->start = arg1;
	arg0->end = (struct tex *)(arg1 + arg2);
    arg0->leftpos = arg1;
    arg0->rightpos = (struct tex *)(arg1 + arg2);
}


struct tex *texFindInPool(s32 texturenum, struct texpool *arg1)
{
    struct tex *end;
    struct tex *cur;
    s32 i;

    if (arg1 == NULL)
    {
        arg1 = &ptr_texture_alloc_start;
    }

    end = arg1->end;
    cur = arg1->rightpos;

    while (cur < end)
    {
        if (cur->texturenum == texturenum)
        {
            return cur;
        }

        cur++;
    }

    return NULL;
}


s32 texFreeBytesInBuffer(struct texpool *arg0)
{
	return (u32)arg0->rightpos - (u32)arg0->leftpos;
}


void texLoadFromDisplayList(Gfx *gdl, struct texpool *arg1)
{
    u8 *bytes = (u8 *)gdl;

    while (bytes[0] != (u8)G_ENDDL)
    {
        // Look for GBI sequence: fd...... abcd....
        if (bytes[0] == G_SETTIMG && bytes[4] == 0xab && bytes[5] == 0xcd)
        {
            texLoad((u32 *)((s32)bytes + 4), arg1);
        }

        bytes += 8;
    }
}


extern u8 _imagesSegmentRomStart;

/**
 * Load and decompress a texture from ROM.
 *
 * The given pointer points to a word which determines what to load.
 * The formats of the word are:
 *
 *     abcdxxxx -> load texture number xxxx
 *     0000xxxx -> load texture number xxxx
 *     (memory address) -> the texture is already loaded, so do nothing
 *
 * After loading and decompressing the texture, the value that's pointed to is
 * changed to be a pointer to... something.
 *
 * There are two types of textures:
 *
 * - Zlib-compressed textures, which are always paletted
 * - Non-zlib textures, which use a variety of (non-zlib) compression methods
 *   and are sometimes paletted
 *
 * Both types have support for multiple levels of detail (ie. multiple images
 * of varying size) within each texture. There are enough bits in the header
 * byte to support 64 levels of detail, but this function caps it to 5. Some
 * textures actually specify up to 7 levels of detail. However testing suggests
 * that the additional levels of detail are not even read.
 *
 * This function reads the above information from the first byte of texture data,
 * then calls the texInflateZlib or texInflateNonZlib to inflate the images.
 *
 * The format of the first byte is:
 * uzllllll
 *
 * u = unknown
 * z = texture is compressed with zlib
 * l = number of levels of detail within the texture
 */
void texLoad(s32 *updateword, struct texpool *pool)
{
    u8 compbuffer[4000];
    u8 *compptr;
    s32 sp14a8;
    s32 iszlib;
    s32 lod;
    struct tex *tex;
    u8 *alignedcompbuffer;
    s32 thisoffset;
    s32 nextoffset;
    s16 *texnumptr;
    s32 bytesout;

    if (pool == NULL)
    {
        pool = (struct texpool*) &ptr_texture_alloc_start;
    }

    g_TexNumToLoad = *updateword & 0xffff;
    tex = texFindInPool(g_TexNumToLoad, pool);

    if (tex == NULL)
    {
        alignedcompbuffer = (u8 *) (((u32)compbuffer + 0xF) >> 4 << 4);

        if (alignedcompbuffer);
        if (tex);

        osWritebackDCacheAll();
        osInvalDCache(alignedcompbuffer, DCACHE_SIZE);

        thisoffset = *((s32*)&g_Textures[g_TexNumToLoad]) & 0xFFFFFF;
        nextoffset = (*((s32 *) (&g_Textures[g_TexNumToLoad + 1]))) & ((unsigned long) 0xFFFFFF);

        if (TRUE)
        {
            // Copy the compressed texture to RAM
            romCopy(alignedcompbuffer,
                    (u32) &_imagesSegmentRomStart + (thisoffset & 0xfffffff8),
                    ((u32) (nextoffset - thisoffset) + 0x1f) >> 4 << 4);

            compptr = (u8 *) alignedcompbuffer + (thisoffset & 7);
            thisoffset = 0;
            sp14a8 = (*compptr & 0x80) >> 7;
            iszlib = (*compptr & 0x40) >> 6;
            lod = *compptr & 0x3f;
            compptr++;

            // If there's not enough memory to load the texture, set the texture
            // pointer to the start of the pool. It'll be garbage data but the
            // only other option is a crash. GBI commands contain texture IDs
            // instead of pointers, and they must be replaced with pointers.
            if ((!iszlib && (texFreeBytesInBuffer(pool) < 0x10CC)) || (iszlib && texFreeBytesInBuffer(pool) < 0xA28)) {
                *updateword = osVirtualToPhysical(pool->start);
                return;
            }

            // Write the texturenum into the allocation
            texnumptr = (s16 *) pool->leftpos;
            *texnumptr = g_TexNumToLoad;
            pool->leftpos += 8;

            // Write a tex into the allocation
            pool->rightpos--;
            tex = pool->rightpos;
            tex->texturenum = g_TexNumToLoad;
            tex->data = pool->leftpos;

            // Extract the texture data to the allocation (pool->leftpos)
            if (iszlib) {
                bytesout = texInflateZlib(compptr, pool->leftpos, sp14a8, lod, pool);
            } else {
                bytesout = texInflateNonZlib(compptr, pool->leftpos, sp14a8, lod, pool);
            }

            pool->leftpos += bytesout;
        }

        texFreeBytesInBuffer(pool);
    }

    *updateword = osVirtualToPhysical(tex->data);
}


void texLoadFromModelFileHeader(ModelFileHeader* arg0, struct texpool* arg1)
{
    s32 i;
    ModelFileTextures* textures;

    textures = arg0->Textures;

    for (i = 0; i < arg0->numtextures; i++)
    {
        if ((s32)textures[i].TextureID < (s32)MAX_TEXTURES)
        {
            texLoad(&textures[i], arg1);
        }
    }
}


void texLoadFromTextureNum(s32 texturenum, struct texpool *arg1)
{
    u32 texturenumcopy;
    texturenumcopy = texturenum;
    texLoad(&texturenumcopy, arg1);
}
