#include <ultra64.h>
#include "gbi_extension.h"
#include "lvl.h"
#include "image.h"
#include "unk_0CC4C0.h"

// bss
//8008D140
s32 g_TexLutMode;
//8008D144
s32 dword_CODE_bss_8008D144;
//8008D148
s_bss_8008D148 g_TexTileStates[8]; //[0x160]; //8 entries of 0x2c ea
//8008D2A8
s_bss_8008D2A8 g_TexTileSizes[8]; //[0xA0]; //8 entries of 0x14 ea
//8008D348
s32 dword_CODE_bss_8008D348;


// data
//D:8004E760
u16 D_8004E760[] = {0xD0, 0xD1};
//D:8004E764
u8 D_8004E764[] = {0x7, 0x0, 0x0, 0x0};
//D:8004E768
struct image_sound isnd_default = {&D_8004E760, &D_8004E764, 0x0, 0x1};

//D:8004E774
u16 D_8004E774[] = {0xD0, 0xD1};
//D:8004E778
u8 D_8004E778[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E77C
struct image_sound isnd_stone = {&D_8004E774, &D_8004E778, 0x2, 0x1};

//D:8004E788
u16 D_8004E788[] = {0x4B, 0xD9};
//D:8004E78C
u8 D_8004E78C[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E790
struct image_sound isnd_wood = {&D_8004E788, &D_8004E78C, 0x2, 0x1};

//D:8004E79C
u16 D_8004E79C[] = {0x48, 0xF0, 0xEF, 0x00};
//D:8004E7A4
u8 D_8004E7A4[] = {0x7, 0x0, 0x0, 0x0};
//D:8004E7A8
struct image_sound isnd_metal = {&D_8004E79C, &D_8004E7A4, 0x3, 0x1};

//D:8004E7B4
u16 D_8004E7B4[] = {0x46, 0x00};
//D:8004E7B8
u8 D_8004E7B8[] = {0x4, 0x5, 0x6, 0x0};
//D:8004E7BC
struct image_sound isnd_glass = {&D_8004E7B4, &D_8004E7B8, 0x1, 0x3};

//D:8004E7C8
u16 D_8004E7C8[] = {0x4C, 0x00};
//D:8004E7CC
u8 D_8004E7CC[] = {0, 0, 0, 0};
//D:8004E7D0
struct image_sound isnd_water = {&D_8004E7C8, &D_8004E7CC, 0x1, 0x0};

//D:8004E7DC
u16 D_8004E7DC[] = {0x4A, 0x00};
//D:8004E7E0
u8 D_8004E7E0[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E7E4
struct image_sound isnd_snow = {&D_8004E7DC, &D_8004E7E0, 0x1, 0x1};

//D:8004E7F0
u16 D_8004E7F0[] = {0xDC, 0xB9};
//D:8004E7F4
u8 D_8004E7F4[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E7F8
struct image_sound isnd_dirt = {&D_8004E7F0, &D_8004E7F4, 0x2, 0x1};

//D:8004E804
u16 D_8004E804[] = {0xE7, 0xE6, 0xE0, 0x00};
//D:8004E80C
u8 D_8004E80C[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E810
struct image_sound isnd_mud = {&D_8004E804, &D_8004E80C, 0x3, 0x1};

//D:8004E81C
u16 D_8004E81C[] = {0xD4, 0x00};
//D:8004E820
u8 D_8004E820[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E824
struct image_sound isnd_tile = {&D_8004E81C, &D_8004E820, 0x1, 0x1};

//D:8004E830
u16 D_8004E830[] = {0x78, 0xDD};
//D:8004E834
u8 D_8004E834[] = {0x1, 0x7, 0x0, 0x0};
//D:8004E838
struct image_sound isnd_metalobj = {&D_8004E830, &D_8004E834, 0x2, 0x2};

//D:8004E844
u16 D_8004E844[] = {0x45, 0x00};
//D:8004E848
u8 D_8004E848[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E84C
struct image_sound isnd_chr = {&D_8004E844, &D_8004E848, 0x1, 0x1};

//D:8004E858
u16 D_8004E858[] = {0x46, 0x00};
//D:8004E85C
u8 D_8004E85C[] = {0x11, 0x12, 0x13, 0x0};
//D:8004E860
struct image_sound isnd_glass_xlu = {&D_8004E858, &D_8004E85C, 0x1, 0x3};

//D:8004E86C
struct image_sound *D_8004E86C[] = { 
    &isnd_default,
    &isnd_stone,
    &isnd_wood,
    &isnd_metal,
    &isnd_glass,
    &isnd_water,
    &isnd_snow,
    &isnd_dirt,
    &isnd_mud,
    &isnd_tile,
    &isnd_metalobj,
    &isnd_chr,
    &isnd_glass_xlu
};

char * image_sound_names[] = {
    "HIT_DEFAULT",
    "HIT_STONE",
    "HIT_WOOD",
    "HIT_METAL",
    "HIT_GLASS",
    "HIT_WATER",
    "HIT_SNOW",
    "HIT_DIRT",
    "HIT_MUD",
    "HIT_TILE",
    "HIT_METALOBJ",
    "HIT_CHR",
    "HIT_GLASS_XLU"
};



void nullsub_47(void) {
    return;
}


void sub_GAME_7F0CC4C8(void)
{
    int i;

    for (i=0; i<8; i++)
    {
        g_TexTileStates[i].inuse = 0;
        g_TexTileSizes[i].inuse = 0;
    }
    g_TexLutMode = -1;
}


s32 unused_copy_byte_array(u8* src, s32 count, u8* dst)
{
    u8* src_itr;
    u8* dst_itr;

    src_itr = src;
    dst_itr = dst;

    while (count > 0)
    {
        *dst_itr = *src_itr;
        dst_itr++;
        src_itr++;
        count--;
    }

    return dst_itr - dst;
}


u32 texSetLutMode(s32 arg0) {
    if (arg0 == g_TexLutMode) {
        return 0;
    }
    g_TexLutMode = arg0;
    return 1;
}


//s32 texTrySetTileState(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA)
s32 texTrySetTileState(s32 tile, s32 format, s32 depth, s32 line, s32 tmem, s32 smode, s32 tmode, s32 masks, s32 maskt, s32 shifts, s32 shiftt)
{
    s32 retval;

    retval = 0;
    if ((g_TexTileStates[tile].inuse == 0) || (format != g_TexTileStates[tile].unk_4) || 
     (depth != g_TexTileStates[tile].unk_8) || (line != g_TexTileStates[tile].unk_C) || 
     (tmem != g_TexTileStates[tile].unk_10) || (smode != g_TexTileStates[tile].unk_14) || 
     (tmode != g_TexTileStates[tile].unk_18) || (masks != g_TexTileStates[tile].unk_1C) || 
     (maskt != g_TexTileStates[tile].unk_20) || (shifts != g_TexTileStates[tile].unk_24) || 
     (shiftt != g_TexTileStates[tile].unk_28))
    {
        retval = 1;
        g_TexTileStates[tile].inuse = 1;
        g_TexTileStates[tile].unk_4 = format;
        g_TexTileStates[tile].unk_8 = depth;
        g_TexTileStates[tile].unk_C = line;
        g_TexTileStates[tile].unk_10 = tmem;
        g_TexTileStates[tile].unk_14 = smode;
        g_TexTileStates[tile].unk_18 = tmode;
        g_TexTileStates[tile].unk_1C = masks;
        g_TexTileStates[tile].unk_20 = maskt;
        g_TexTileStates[tile].unk_24 = shifts;
        g_TexTileStates[tile].unk_28 = shiftt;

    }
    return retval;
}


s32 texTrySetTileSize(s32 tile, s32 uls, s32 ult, s32 lrs, s32 lrt)
{
    s32 retval;

    retval = 0;
    if ((((g_TexTileSizes[tile].inuse == 0) || (uls != g_TexTileSizes[tile].unk_4)) || (ult != g_TexTileSizes[tile].unk_8)) ||
       ((lrs != g_TexTileSizes[tile].unk_C || (lrt != g_TexTileSizes[tile].unk_10))))
    {
        retval = 1;
        g_TexTileSizes[tile].inuse = 1;
        g_TexTileSizes[tile].unk_4 = uls;
        g_TexTileSizes[tile].unk_8 = ult;
        g_TexTileSizes[tile].unk_C = lrs;
        g_TexTileSizes[tile].unk_10 = lrt;
    }
    return retval;
}


s32 texGetWidthAtLod(struct tex *tex, s32 lod)
{
    s32 i;
    s32 width = tex->width;

    if (lod == 0)
    {
        return width;
    }

    if (tex->unk0c_02)
    {
        for (i = 0; i < g_TexCacheCount; i++)
        {
            if (tex->texturenum == g_TexCacheItems[i].texturenum)
            {
                return g_TexCacheItems[i].widths[lod - 1];
            }
        }

        return 1;
    }

    for (i = 0; i < lod; i++)
    {
        width = (width + 1) >> 1;
    }

    return width;
}


s32 texGetHeightAtLod(struct tex *tex, s32 lod)
{
    s32 i;
    s32 height = tex->height;

    if (lod == 0)
    {
        return height;
    }

    if (tex->unk0c_02)
    {
        for (i = 0; i < g_TexCacheCount; i++)
        {
            if (tex->texturenum == g_TexCacheItems[i].texturenum)
            {
                return g_TexCacheItems[i].heights[lod - 1];
            }
        }

        return 1;
    }

    for (i = 0; i < lod; i++)
    {
        height = (height + 1) >> 1;
    }

    return height;
}


s32 texGetLineSizeInBytes(struct tex *tex, s32 lod)
{
    s32 depth = tex->depth;
    s32 width = texGetWidthAtLod(tex, lod);

    if (depth == G_IM_SIZ_32b)
    {
        return (width + 3) / 4;
    }

    if (depth == G_IM_SIZ_16b)
    {
        return (width + 3) / 4;
    }

    if (depth == G_IM_SIZ_8b)
    {
        return (width + 7) / 8;
    }

    return (width + 15) / 16;
}


s32 texGetSizeInBytes(struct tex *tex, s32 lod)
{
    return texGetHeightAtLod(tex, lod) * texGetLineSizeInBytes(tex, lod);
}


void texGetDepthAndSize(struct tex *tex, s32 *deptharg, s32 *lenarg)
{
    s32 depth = tex->depth;
    s32 maxlod = tex->maxlod ? tex->maxlod : 1;
    s32 lod;

    *lenarg = 0;

    if (depth == G_IM_SIZ_32b)
    {
        *deptharg = G_IM_SIZ_32b;
    }
    else if (depth == G_IM_SIZ_16b)
    {
        *deptharg = G_IM_SIZ_16b;
    }
    else if (depth == G_IM_SIZ_8b)
    {
        *deptharg = G_IM_SIZ_16b;
    }
    else
    {
        *deptharg = G_IM_SIZ_16b;
    }

    for (lod = 0; lod < maxlod; lod++) {
        *lenarg += texGetSizeInBytes(tex, lod) * 4;
    }
}


s32 texDimensionToMask(s32 arg0) {
    s32 i = 0;

    arg0--;

    while (arg0 > 0 && i < 8) {
        arg0 >>= 1;
        i++;
    }

    return i;
}





u32 texModeToGbiMode(s32 arg0) {
    if (arg0 == 1) {
        return G_TX_CLAMP;
    }
    if (arg0 == 2) {
        return G_TX_MIRROR;
    }
    return G_TX_WRAP;
}


s32 sub_GAME_7F0CCAFC(f32 arg0)
{
    return (s32)arg0 < (f32)arg0 ? (s32)arg0+1 : (s32)arg0;
}


s32 sub_GAME_7F0CCB38(s32 *arg0)
{
    s32 temp_t7;
    s32 temp_v0;

    temp_v0 = texGetLineSizeInBytes(arg0, 0U);
    temp_t7 = arg0[2] & 3;
    if (temp_t7 == 3)
    {
        return sub_GAME_7F0CCAFC((2.0f / (f32) (temp_v0 * 4)) * 2048.0f);
    }
    if (temp_t7 == 2)
    {
        return sub_GAME_7F0CCAFC((4.0f / (f32) (temp_v0 * 4)) * 2048.0f);
    }
    if (temp_t7 == 1)
    {
        return sub_GAME_7F0CCAFC((8.0f / (f32) (temp_v0 * 8)) * 2048.0f);
    }
    return sub_GAME_7F0CCAFC((16.0f / (f32) (temp_v0 * 0x10)) * 2048.0f);
}


Gfx *texWriteTileFromDefinition(Gfx *gdl, struct tex *tex, s32 offset, s32 shifts, s32 shiftt, s32 arg5)
{
    struct image_entry *s0 = &g_Textures[tex->texturenum];
    s32 sp88;
    s32 sp84;
    s32 line;
    u32 stack[4];
    s32 uls;
    s32 ult;
    s32 lrs;
    s32 lrt;

    sp88 = texDimensionToMask(tex->width);
    sp84 = texDimensionToMask(tex->height);

    line = texGetLineSizeInBytes(tex, 0);

    gDPSetPrimColorViaWord(gdl++, arg5, 0, 0xffffffff);

    if (texSetLutMode(tex->lutmodeindex << G_MDSFT_TEXTLUT))
    {
        gDPSetTextureLUT(gdl++, tex->lutmodeindex << G_MDSFT_TEXTLUT);
    }

    if (texTrySetTileState(0, tex->gbiformat, tex->depth, line, s0->flag3 + line * s0->flag4, 0, 0, sp88 - s0->flag5, sp84 - s0->flag6, shifts, shiftt))
    {
        gDPSetTile(gdl++, tex->gbiformat, tex->depth, line, s0->flag3 + line * s0->flag4, 0, 0,
                texModeToGbiMode(0), sp84 - s0->flag6, shiftt,
                texModeToGbiMode(0), sp88 - s0->flag5, shifts);
    }

    uls = (offset == 2 && !tex->unk0c_02 ? 2 : 0) + 0;
    ult = (offset == 2 && !tex->unk0c_02 ? 2 : 0) + 0;
    lrs = (offset == 2 && !tex->unk0c_02 ? 2 : 0) + ((tex->width - 1) << 2);
    lrt = (offset == 2 && !tex->unk0c_02 ? 2 : 0) + ((tex->height - 1) << 2);

    if (texTrySetTileSize(0, uls, ult, lrs, lrt))
    {
        gDPSetTileSize(gdl++, 0, uls, ult, lrs, lrt);
    }

    return gdl;
}

Gfx* texWriteTextureCmd(Gfx* arg0, Gfx* arg1, struct tex* tex, s32 arg3)
{
    s32 lod = tex->maxlod ? tex->maxlod - 1 : 0;

    if (arg3)
    {
        if (arg1 != NULL)
        {
            u32 v0 = (arg1->words.w0 & ~0x3800) | (lod << 11);

            if (v0 != arg1->words.w0)
            {
                arg0->words.w0 = v0;
                arg0->words.w1 = arg1->words.w1;
                arg0++;
            }
        }
        else
        {
            gSPTexture(arg0++, 0xffff, 0xffff, lod, G_TX_RENDERTILE, G_ON);
        }
    }
    else
    {
        arg1->words.w0 &= ~0x3800;
        arg1->words.w0 |= lod << 11;
    }

    return arg0;
}


#ifdef NONMATCHING
Gfx *texWriteLoadToTmemAddr(Gfx *gdl, struct tex *tex, s32 tmemoffset)
{
	s32 depth;
	s32 len;

	texGetDepthAndSize(tex, &depth, &len);

	if (tex->lutmodeindex == 0) {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!g_TexPipeSynced) {
			gDPPipeSync(gdl++);
			g_TexPipeSynced = true;
		}

		if (depth == G_IM_SIZ_16b && tmemoffset == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (texTrySetTileState(5, 0, depth, 0, tmemoffset, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, tmemoffset, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}
	} else {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!g_TexPipeSynced) {
			gDPPipeSync(gdl++);
			g_TexPipeSynced = true;
		}

		if (depth == G_IM_SIZ_16b && tmemoffset == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (texTrySetTileState(5, 0, depth, 0, tmemoffset, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, tmemoffset, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}

		{
			s32 tmp = len;
			s32 a2 = (u32)(0x3ff - tex->unk0a) < len ? (u32)(0x3ff - tex->unk0a) : 0;

			tmp -= a2;

			gDPLoadSync(gdl++);
			gDPLoadTLUT06(gdl++, tmp, a2, tex->unk0a + tmp, a2);
		}
	}

	return gdl;
}
#else
GLOBAL_ASM(
.text
glabel texWriteLoadToTmemAddr
/* 101BA8 7F0CD078 27BDFF70 */  addiu $sp, $sp, -0x90
/* 101BAC 7F0CD07C AFB00034 */  sw    $s0, 0x34($sp)
/* 101BB0 7F0CD080 00808025 */  move  $s0, $a0
/* 101BB4 7F0CD084 AFB10038 */  sw    $s1, 0x38($sp)
/* 101BB8 7F0CD088 00A08825 */  move  $s1, $a1
/* 101BBC 7F0CD08C AFBF003C */  sw    $ra, 0x3c($sp)
/* 101BC0 7F0CD090 AFA60098 */  sw    $a2, 0x98($sp)
/* 101BC4 7F0CD094 00A02025 */  move  $a0, $a1
/* 101BC8 7F0CD098 27A5008C */  addiu $a1, $sp, 0x8c
/* 101BCC 7F0CD09C 0FC33275 */  jal   texGetDepthAndSize
/* 101BD0 7F0CD0A0 27A60088 */   addiu $a2, $sp, 0x88
/* 101BD4 7F0CD0A4 8E2E000C */  lw    $t6, 0xc($s1)
/* 101BD8 7F0CD0A8 24040007 */  li    $a0, 7
/* 101BDC 7F0CD0AC 02001025 */  move  $v0, $s0
/* 101BE0 7F0CD0B0 000E7F82 */  srl   $t7, $t6, 0x1e
/* 101BE4 7F0CD0B4 15E0004E */  bnez  $t7, .L7F0CD1F0
/* 101BE8 7F0CD0B8 3C01FD00 */   lui   $at, 0xfd00
/* 101BEC 7F0CD0BC 8E380008 */  lw    $t8, 8($s1)
/* 101BF0 7F0CD0C0 8FAF008C */  lw    $t7, 0x8c($sp)
/* 101BF4 7F0CD0C4 3C01FD00 */  lui   $at, 0xfd00
/* 101BF8 7F0CD0C8 0018CEC0 */  sll   $t9, $t8, 0x1b
/* 101BFC 7F0CD0CC 00195F42 */  srl   $t3, $t9, 0x1d
/* 101C00 7F0CD0D0 316C0007 */  andi  $t4, $t3, 7
/* 101C04 7F0CD0D4 000C6D40 */  sll   $t5, $t4, 0x15
/* 101C08 7F0CD0D8 31F80003 */  andi  $t8, $t7, 3
/* 101C0C 7F0CD0DC 0018CCC0 */  sll   $t9, $t8, 0x13
/* 101C10 7F0CD0E0 01A17025 */  or    $t6, $t5, $at
/* 101C14 7F0CD0E4 01D95825 */  or    $t3, $t6, $t9
/* 101C18 7F0CD0E8 02001025 */  move  $v0, $s0
/* 101C1C 7F0CD0EC AC4B0000 */  sw    $t3, ($v0)
/* 101C20 7F0CD0F0 8E2C0004 */  lw    $t4, 4($s1)
/* 101C24 7F0CD0F4 26100008 */  addiu $s0, $s0, 8
/* 101C28 7F0CD0F8 00003825 */  move  $a3, $zero
/* 101C2C 7F0CD0FC AC4C0004 */  sw    $t4, 4($v0)
/* 101C30 7F0CD100 8E250008 */  lw    $a1, 8($s1)
/* 101C34 7F0CD104 8FB80098 */  lw    $t8, 0x98($sp)
/* 101C38 7F0CD108 AFA00028 */  sw    $zero, 0x28($sp)
/* 101C3C 7F0CD10C 00056EC0 */  sll   $t5, $a1, 0x1b
/* 101C40 7F0CD110 000D2F42 */  srl   $a1, $t5, 0x1d
/* 101C44 7F0CD114 AFA00024 */  sw    $zero, 0x24($sp)
/* 101C48 7F0CD118 AFA00020 */  sw    $zero, 0x20($sp)
/* 101C4C 7F0CD11C AFA0001C */  sw    $zero, 0x1c($sp)
/* 101C50 7F0CD120 AFA00018 */  sw    $zero, 0x18($sp)
/* 101C54 7F0CD124 AFA00014 */  sw    $zero, 0x14($sp)
/* 101C58 7F0CD128 8FA6008C */  lw    $a2, 0x8c($sp)
/* 101C5C 7F0CD12C 0FC3315D */  jal   texTrySetTileState
/* 101C60 7F0CD130 AFB80010 */   sw    $t8, 0x10($sp)
/* 101C64 7F0CD134 10400013 */  beqz  $v0, .L7F0CD184
/* 101C68 7F0CD138 3C0A0700 */   lui   $t2, 0x700
/* 101C6C 7F0CD13C 8E2E0008 */  lw    $t6, 8($s1)
/* 101C70 7F0CD140 8FB8008C */  lw    $t8, 0x8c($sp)
/* 101C74 7F0CD144 3C01F500 */  lui   $at, 0xf500
/* 101C78 7F0CD148 000ECEC0 */  sll   $t9, $t6, 0x1b
/* 101C7C 7F0CD14C 00195F42 */  srl   $t3, $t9, 0x1d
/* 101C80 7F0CD150 316C0007 */  andi  $t4, $t3, 7
/* 101C84 7F0CD154 000C6D40 */  sll   $t5, $t4, 0x15
/* 101C88 7F0CD158 8FAC0098 */  lw    $t4, 0x98($sp)
/* 101C8C 7F0CD15C 01A17825 */  or    $t7, $t5, $at
/* 101C90 7F0CD160 330E0003 */  andi  $t6, $t8, 3
/* 101C94 7F0CD164 000ECCC0 */  sll   $t9, $t6, 0x13
/* 101C98 7F0CD168 02001025 */  move  $v0, $s0
/* 101C9C 7F0CD16C 01F95825 */  or    $t3, $t7, $t9
/* 101CA0 7F0CD170 318D01FF */  andi  $t5, $t4, 0x1ff
/* 101CA4 7F0CD174 016DC025 */  or    $t8, $t3, $t5
/* 101CA8 7F0CD178 AC580000 */  sw    $t8, ($v0)
/* 101CAC 7F0CD17C AC4A0004 */  sw    $t2, 4($v0)
/* 101CB0 7F0CD180 26100008 */  addiu $s0, $s0, 8
.L7F0CD184:  /*LoadTexture(){gDPLoadSync(); gDPLoadBlock();}*/
/* 101CB4 7F0CD184 02001025 */  move  $v0, $s0
/* 101CB8 7F0CD188 26100008 */  addiu $s0, $s0, 8
/* 101CBC 7F0CD18C 3C0EE600 */  lui   $t6, 0xe600
/* 101CC0 7F0CD190 AC4E0000 */  sw    $t6, ($v0)
/* 101CC4 7F0CD194 AC400004 */  sw    $zero, 4($v0)
/* 101CC8 7F0CD198 02002825 */  move  $a1, $s0
/* 101CCC 7F0CD19C 3C0FF300 */  lui   $t7, 0xf300
/* 101CD0 7F0CD1A0 ACAF0000 */  sw    $t7, ($a1)
/* 101CD4 7F0CD1A4 8FA30088 */  lw    $v1, 0x88($sp)
/* 101CD8 7F0CD1A8 26100008 */  addiu $s0, $s0, 8
/* 101CDC 7F0CD1AC 3C0A0700 */  lui   $t2, 0x700
/* 101CE0 7F0CD1B0 2463FFFF */  addiu $v1, $v1, -1
/* 101CE4 7F0CD1B4 286107FF */  slti  $at, $v1, 0x7ff
/* 101CE8 7F0CD1B8 10200003 */  beqz  $at, .L7F0CD1C8
/* 101CEC 7F0CD1BC 02001025 */   move  $v0, $s0
/* 101CF0 7F0CD1C0 10000002 */  b     .L7F0CD1CC
/* 101CF4 7F0CD1C4 00602025 */   move  $a0, $v1
.L7F0CD1C8:
/* 101CF8 7F0CD1C8 240407FF */  li    $a0, 2047
.L7F0CD1CC:
/* 101CFC 7F0CD1CC 30990FFF */  andi  $t9, $a0, 0xfff
/* 101D00 7F0CD1D0 00196300 */  sll   $t4, $t9, 0xc
/* 101D04 7F0CD1D4 018A5825 */  or    $t3, $t4, $t2
/* 101D08 7F0CD1D8 ACAB0004 */  sw    $t3, 4($a1)
/* 101D0C 7F0CD1DC 3C0DE700 */  lui   $t5, 0xe700
/* 101D10 7F0CD1E0 AC4D0000 */  sw    $t5, ($v0)
/* 101D14 7F0CD1E4 AC400004 */  sw    $zero, 4($v0)
/* 101D18 7F0CD1E8 1000008B */  b     .L7F0CD418
/* 101D1C 7F0CD1EC 26100008 */   addiu $s0, $s0, 8
.L7F0CD1F0:
/* 101D20 7F0CD1F0 8E380008 */  lw    $t8, 8($s1)
/* 101D24 7F0CD1F4 8FAD008C */  lw    $t5, 0x8c($sp)
/* 101D28 7F0CD1F8 26100008 */  addiu $s0, $s0, 8
/* 101D2C 7F0CD1FC 001876C0 */  sll   $t6, $t8, 0x1b
/* 101D30 7F0CD200 000E7F42 */  srl   $t7, $t6, 0x1d
/* 101D34 7F0CD204 31F90007 */  andi  $t9, $t7, 7
/* 101D38 7F0CD208 00196540 */  sll   $t4, $t9, 0x15
/* 101D3C 7F0CD20C 31B80003 */  andi  $t8, $t5, 3
/* 101D40 7F0CD210 001874C0 */  sll   $t6, $t8, 0x13
/* 101D44 7F0CD214 01815825 */  or    $t3, $t4, $at
/* 101D48 7F0CD218 016E7825 */  or    $t7, $t3, $t6
/* 101D4C 7F0CD21C AC4F0000 */  sw    $t7, ($v0)
/* 101D50 7F0CD220 8E390004 */  lw    $t9, 4($s1)
/* 101D54 7F0CD224 24040007 */  li    $a0, 7
/* 101D58 7F0CD228 00003825 */  move  $a3, $zero
/* 101D5C 7F0CD22C AC590004 */  sw    $t9, 4($v0)
/* 101D60 7F0CD230 8E250008 */  lw    $a1, 8($s1)
/* 101D64 7F0CD234 8FB80098 */  lw    $t8, 0x98($sp)
/* 101D68 7F0CD238 AFA00028 */  sw    $zero, 0x28($sp)
/* 101D6C 7F0CD23C 000566C0 */  sll   $t4, $a1, 0x1b
/* 101D70 7F0CD240 000C2F42 */  srl   $a1, $t4, 0x1d
/* 101D74 7F0CD244 AFA00024 */  sw    $zero, 0x24($sp)
/* 101D78 7F0CD248 AFA00020 */  sw    $zero, 0x20($sp)
/* 101D7C 7F0CD24C AFA0001C */  sw    $zero, 0x1c($sp)
/* 101D80 7F0CD250 AFA00018 */  sw    $zero, 0x18($sp)
/* 101D84 7F0CD254 AFA00014 */  sw    $zero, 0x14($sp)
/* 101D88 7F0CD258 8FA6008C */  lw    $a2, 0x8c($sp)
/* 101D8C 7F0CD25C 0FC3315D */  jal   texTrySetTileState
/* 101D90 7F0CD260 AFB80010 */   sw    $t8, 0x10($sp)
/* 101D94 7F0CD264 10400014 */  beqz  $v0, .L7F0CD2B8
/* 101D98 7F0CD268 00003025 */   move  $a2, $zero
/* 101D9C 7F0CD26C 8E2B0008 */  lw    $t3, 8($s1)
/* 101DA0 7F0CD270 8FB8008C */  lw    $t8, 0x8c($sp)
/* 101DA4 7F0CD274 3C01F500 */  lui   $at, 0xf500
/* 101DA8 7F0CD278 000B76C0 */  sll   $t6, $t3, 0x1b
/* 101DAC 7F0CD27C 000E7F42 */  srl   $t7, $t6, 0x1d
/* 101DB0 7F0CD280 31F90007 */  andi  $t9, $t7, 7
/* 101DB4 7F0CD284 00196540 */  sll   $t4, $t9, 0x15
/* 101DB8 7F0CD288 8FB90098 */  lw    $t9, 0x98($sp)
/* 101DBC 7F0CD28C 01816825 */  or    $t5, $t4, $at
/* 101DC0 7F0CD290 330B0003 */  andi  $t3, $t8, 3
/* 101DC4 7F0CD294 000B74C0 */  sll   $t6, $t3, 0x13
/* 101DC8 7F0CD298 02001025 */  move  $v0, $s0
/* 101DCC 7F0CD29C 01AE7825 */  or    $t7, $t5, $t6
/* 101DD0 7F0CD2A0 332C01FF */  andi  $t4, $t9, 0x1ff
/* 101DD4 7F0CD2A4 3C0A0700 */  lui   $t2, 0x700
/* 101DD8 7F0CD2A8 01ECC025 */  or    $t8, $t7, $t4
/* 101DDC 7F0CD2AC AC580000 */  sw    $t8, ($v0)
/* 101DE0 7F0CD2B0 AC4A0004 */  sw    $t2, 4($v0)
/* 101DE4 7F0CD2B4 26100008 */  addiu $s0, $s0, 8
.L7F0CD2B8:
/* 101DE8 7F0CD2B8 02001025 */  move  $v0, $s0
/* 101DEC 7F0CD2BC 26100008 */  addiu $s0, $s0, 8
/* 101DF0 7F0CD2C0 3C0BE600 */  lui   $t3, 0xe600
/* 101DF4 7F0CD2C4 AC4B0000 */  sw    $t3, ($v0)
/* 101DF8 7F0CD2C8 AC400004 */  sw    $zero, 4($v0)
/* 101DFC 7F0CD2CC 02002825 */  move  $a1, $s0
/* 101E00 7F0CD2D0 3C0DF300 */  lui   $t5, 0xf300
/* 101E04 7F0CD2D4 ACAD0000 */  sw    $t5, ($a1)
/* 101E08 7F0CD2D8 8FA30088 */  lw    $v1, 0x88($sp)
/* 101E0C 7F0CD2DC 26100008 */  addiu $s0, $s0, 8
/* 101E10 7F0CD2E0 3C0A0700 */  lui   $t2, 0x700
/* 101E14 7F0CD2E4 2463FFFF */  addiu $v1, $v1, -1
/* 101E18 7F0CD2E8 286107FF */  slti  $at, $v1, 0x7ff
/* 101E1C 7F0CD2EC 10200003 */  beqz  $at, .L7F0CD2FC
/* 101E20 7F0CD2F0 02001025 */   move  $v0, $s0
/* 101E24 7F0CD2F4 10000002 */  b     .L7F0CD300
/* 101E28 7F0CD2F8 00602025 */   move  $a0, $v1
.L7F0CD2FC:
/* 101E2C 7F0CD2FC 240407FF */  li    $a0, 2047
.L7F0CD300:
/* 101E30 7F0CD300 308E0FFF */  andi  $t6, $a0, 0xfff
/* 101E34 7F0CD304 000ECB00 */  sll   $t9, $t6, 0xc
/* 101E38 7F0CD308 032A7825 */  or    $t7, $t9, $t2
/* 101E3C 7F0CD30C ACAF0004 */  sw    $t7, 4($a1)
/* 101E40 7F0CD310 3C0CE700 */  lui   $t4, 0xe700
/* 101E44 7F0CD314 AC4C0000 */  sw    $t4, ($v0)
/* 101E48 7F0CD318 AC400004 */  sw    $zero, 4($v0)
/* 101E4C 7F0CD31C 9238000A */  lbu   $t8, 0xa($s1)
/* 101E50 7F0CD320 8FA80088 */  lw    $t0, 0x88($sp)
/* 101E54 7F0CD324 240B03FF */  li    $t3, 1023
/* 101E58 7F0CD328 01781823 */  subu  $v1, $t3, $t8
/* 101E5C 7F0CD32C 0068082B */  sltu  $at, $v1, $t0
/* 101E60 7F0CD330 10200003 */  beqz  $at, .L7F0CD340
/* 101E64 7F0CD334 26100008 */   addiu $s0, $s0, 8
/* 101E68 7F0CD338 10000002 */  b     .L7F0CD344
/* 101E6C 7F0CD33C 00604825 */   move  $t1, $v1
.L7F0CD340:
/* 101E70 7F0CD340 00004825 */  move  $t1, $zero
.L7F0CD344:
/* 101E74 7F0CD344 01094023 */  subu  $t0, $t0, $t1
/* 101E78 7F0CD348 240E0100 */  li    $t6, 256
/* 101E7C 7F0CD34C AFAE0010 */  sw    $t6, 0x10($sp)
/* 101E80 7F0CD350 AFA80070 */  sw    $t0, 0x70($sp)
/* 101E84 7F0CD354 24040007 */  li    $a0, 7
/* 101E88 7F0CD358 00002825 */  move  $a1, $zero
/* 101E8C 7F0CD35C 24070001 */  li    $a3, 1
/* 101E90 7F0CD360 AFA00014 */  sw    $zero, 0x14($sp)
/* 101E94 7F0CD364 AFA00018 */  sw    $zero, 0x18($sp)
/* 101E98 7F0CD368 AFA0001C */  sw    $zero, 0x1c($sp)
/* 101E9C 7F0CD36C AFA00020 */  sw    $zero, 0x20($sp)
/* 101EA0 7F0CD370 AFA00024 */  sw    $zero, 0x24($sp)
/* 101EA4 7F0CD374 AFA00028 */  sw    $zero, 0x28($sp)
/* 101EA8 7F0CD378 0FC3315D */  jal   texTrySetTileState
/* 101EAC 7F0CD37C AFA9006C */   sw    $t1, 0x6c($sp)
/* 101EB0 7F0CD380 8FA80070 */  lw    $t0, 0x70($sp)
/* 101EB4 7F0CD384 8FA9006C */  lw    $t1, 0x6c($sp)
/* 101EB8 7F0CD388 10400007 */  beqz  $v0, .L7F0CD3A8
/* 101EBC 7F0CD38C 3C0A0700 */   lui   $t2, 0x700
/* 101EC0 7F0CD390 02001025 */  move  $v0, $s0
/* 101EC4 7F0CD394 3C19F500 */  lui   $t9, (0xF5000300 >> 16) # lui $t9, 0xf500
/* 101EC8 7F0CD398 37390300 */  ori   $t9, (0xF5000300 & 0xFFFF) # ori $t9, $t9, 0x300
/* 101ECC 7F0CD39C AC590000 */  sw    $t9, ($v0)
/* 101ED0 7F0CD3A0 AC4A0004 */  sw    $t2, 4($v0)
/* 101ED4 7F0CD3A4 26100008 */  addiu $s0, $s0, 8
.L7F0CD3A8:
/* 101ED8 7F0CD3A8 02001025 */  move  $v0, $s0
/* 101EDC 7F0CD3AC 310B03FF */  andi  $t3, $t0, 0x3ff
/* 101EE0 7F0CD3B0 000BC380 */  sll   $t8, $t3, 0xe
/* 101EE4 7F0CD3B4 312403FF */  andi  $a0, $t1, 0x3ff
/* 101EE8 7F0CD3B8 3C01F000 */  lui   $at, 0xf000
/* 101EEC 7F0CD3BC 26100008 */  addiu $s0, $s0, 8
/* 101EF0 7F0CD3C0 3C0FE600 */  lui   $t7, 0xe600
/* 101EF4 7F0CD3C4 03016825 */  or    $t5, $t8, $at
/* 101EF8 7F0CD3C8 00046080 */  sll   $t4, $a0, 2
/* 101EFC 7F0CD3CC AC4F0000 */  sw    $t7, ($v0)
/* 101F00 7F0CD3D0 AC400004 */  sw    $zero, 4($v0)
/* 101F04 7F0CD3D4 01AC7025 */  or    $t6, $t5, $t4
/* 101F08 7F0CD3D8 02001825 */  move  $v1, $s0
/* 101F0C 7F0CD3DC AC6E0000 */  sw    $t6, ($v1)
/* 101F10 7F0CD3E0 9239000A */  lbu   $t9, 0xa($s1)
/* 101F14 7F0CD3E4 01802025 */  move  $a0, $t4
/* 101F18 7F0CD3E8 26100008 */  addiu $s0, $s0, 8
/* 101F1C 7F0CD3EC 03287821 */  addu  $t7, $t9, $t0
/* 101F20 7F0CD3F0 31EC03FF */  andi  $t4, $t7, 0x3ff
/* 101F24 7F0CD3F4 000C5B80 */  sll   $t3, $t4, 0xe
/* 101F28 7F0CD3F8 016AC025 */  or    $t8, $t3, $t2
/* 101F2C 7F0CD3FC 03046825 */  or    $t5, $t8, $a0
/* 101F30 7F0CD400 02002825 */  move  $a1, $s0
/* 101F34 7F0CD404 AC6D0004 */  sw    $t5, 4($v1)
/* 101F38 7F0CD408 3C0EE700 */  lui   $t6, 0xe700
/* 101F3C 7F0CD40C ACAE0000 */  sw    $t6, ($a1)
/* 101F40 7F0CD410 ACA00004 */  sw    $zero, 4($a1)
/* 101F44 7F0CD414 26100008 */  addiu $s0, $s0, 8
.L7F0CD418:
/* 101F48 7F0CD418 8FBF003C */  lw    $ra, 0x3c($sp)
/* 101F4C 7F0CD41C 02001025 */  move  $v0, $s0
/* 101F50 7F0CD420 8FB00034 */  lw    $s0, 0x34($sp)
/* 101F54 7F0CD424 8FB10038 */  lw    $s1, 0x38($sp)
/* 101F58 7F0CD428 03E00008 */  jr    $ra
/* 101F5C 7F0CD42C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif





#ifdef NONMATCHING
void texWriteTileLods(void) {

}
#else
GLOBAL_ASM(
.text
glabel texWriteTileLods
/* 101F60 7F0CD430 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 101F64 7F0CD434 8FAE00D0 */  lw    $t6, 0xd0($sp)
/* 101F68 7F0CD438 AFBF005C */  sw    $ra, 0x5c($sp)
/* 101F6C 7F0CD43C AFBE0058 */  sw    $fp, 0x58($sp)
/* 101F70 7F0CD440 AFB70054 */  sw    $s7, 0x54($sp)
/* 101F74 7F0CD444 AFB60050 */  sw    $s6, 0x50($sp)
/* 101F78 7F0CD448 AFB5004C */  sw    $s5, 0x4c($sp)
/* 101F7C 7F0CD44C AFB40048 */  sw    $s4, 0x48($sp)
/* 101F80 7F0CD450 AFB30044 */  sw    $s3, 0x44($sp)
/* 101F84 7F0CD454 AFB20040 */  sw    $s2, 0x40($sp)
/* 101F88 7F0CD458 AFB1003C */  sw    $s1, 0x3c($sp)
/* 101F8C 7F0CD45C AFB00038 */  sw    $s0, 0x38($sp)
/* 101F90 7F0CD460 AFA600C0 */  sw    $a2, 0xc0($sp)
/* 101F94 7F0CD464 AFA700C4 */  sw    $a3, 0xc4($sp)
/* 101F98 7F0CD468 AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 101F9C 7F0CD46C 90A2000B */  lbu   $v0, 0xb($a1)
/* 101FA0 7F0CD470 8FB000CC */  lw    $s0, 0xcc($sp)
/* 101FA4 7F0CD474 00A0A825 */  move  $s5, $a1
/* 101FA8 7F0CD478 00027942 */  srl   $t7, $v0, 5
/* 101FAC 7F0CD47C 01F04021 */  addu  $t0, $t7, $s0
/* 101FB0 7F0CD480 0208082A */  slt   $at, $s0, $t0
/* 101FB4 7F0CD484 102000BC */  beqz  $at, .L7F0CD778
/* 101FB8 7F0CD488 0080B025 */   move  $s6, $a0
/* 101FBC 7F0CD48C 02109023 */  subu  $s2, $s0, $s0
/* 101FC0 7F0CD490 AFB000AC */  sw    $s0, 0xac($sp)
/* 101FC4 7F0CD494 AFA80064 */  sw    $t0, 0x64($sp)
.L7F0CD498:
/* 101FC8 7F0CD498 02A02025 */  move  $a0, $s5
/* 101FCC 7F0CD49C 0FC331C5 */  jal   texGetWidthAtLod
/* 101FD0 7F0CD4A0 02402825 */   move  $a1, $s2
/* 101FD4 7F0CD4A4 0FC332A7 */  jal   texDimensionToMask
/* 101FD8 7F0CD4A8 00402025 */   move  $a0, $v0
/* 101FDC 7F0CD4AC 00409825 */  move  $s3, $v0
/* 101FE0 7F0CD4B0 02A02025 */  move  $a0, $s5
/* 101FE4 7F0CD4B4 0FC331FF */  jal   texGetHeightAtLod
/* 101FE8 7F0CD4B8 02402825 */   move  $a1, $s2
/* 101FEC 7F0CD4BC 0FC332A7 */  jal   texDimensionToMask
/* 101FF0 7F0CD4C0 00402025 */   move  $a0, $v0
/* 101FF4 7F0CD4C4 0040A025 */  move  $s4, $v0
/* 101FF8 7F0CD4C8 02A02025 */  move  $a0, $s5
/* 101FFC 7F0CD4CC 0FC33239 */  jal   texGetLineSizeInBytes
/* 102000 7F0CD4D0 02402825 */   move  $a1, $s2
/* 102004 7F0CD4D4 00408025 */  move  $s0, $v0
/* 102008 7F0CD4D8 02A02025 */  move  $a0, $s5
/* 10200C 7F0CD4DC 0FC33265 */  jal   texGetSizeInBytes
/* 102010 7F0CD4E0 02402825 */   move  $a1, $s2
/* 102014 7F0CD4E4 AFA20080 */  sw    $v0, 0x80($sp)
/* 102018 7F0CD4E8 8EA3000C */  lw    $v1, 0xc($s5)
/* 10201C 7F0CD4EC 0003F080 */  sll   $fp, $v1, 2
/* 102020 7F0CD4F0 00032782 */  srl   $a0, $v1, 0x1e
/* 102024 7F0CD4F4 001EC7C2 */  srl   $t8, $fp, 0x1f
/* 102028 7F0CD4F8 0004CB80 */  sll   $t9, $a0, 0xe
/* 10202C 7F0CD4FC 0300F025 */  move  $fp, $t8
/* 102030 7F0CD500 0FC33152 */  jal   texSetLutMode
/* 102034 7F0CD504 03202025 */   move  $a0, $t9
/* 102038 7F0CD508 1040000A */  beqz  $v0, .L7F0CD534
/* 10203C 7F0CD50C 02003825 */   move  $a3, $s0
/* 102040 7F0CD510 3C09BA00 */  lui   $t1, (0xBA000E02 >> 16) # lui $t1, 0xba00
/* 102044 7F0CD514 35290E02 */  ori   $t1, (0xBA000E02 & 0xFFFF) # ori $t1, $t1, 0xe02
/* 102048 7F0CD518 02C01025 */  move  $v0, $s6
/* 10204C 7F0CD51C AC490000 */  sw    $t1, ($v0)
/* 102050 7F0CD520 8EAA000C */  lw    $t2, 0xc($s5)
/* 102054 7F0CD524 26D60008 */  addiu $s6, $s6, 8
/* 102058 7F0CD528 000A5F82 */  srl   $t3, $t2, 0x1e
/* 10205C 7F0CD52C 000B6380 */  sll   $t4, $t3, 0xe
/* 102060 7F0CD530 AC4C0004 */  sw    $t4, 4($v0)
.L7F0CD534:
/* 102064 7F0CD534 8EA20008 */  lw    $v0, 8($s5)
/* 102068 7F0CD538 8FAE00B4 */  lw    $t6, 0xb4($sp)
/* 10206C 7F0CD53C 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 102070 7F0CD540 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 102074 7F0CD544 00022EC0 */  sll   $a1, $v0, 0x1b
/* 102078 7F0CD548 00056F42 */  srl   $t5, $a1, 0x1d
/* 10207C 7F0CD54C 01A02825 */  move  $a1, $t5
/* 102080 7F0CD550 AFB20028 */  sw    $s2, 0x28($sp)
/* 102084 7F0CD554 AFB20024 */  sw    $s2, 0x24($sp)
/* 102088 7F0CD558 AFB40020 */  sw    $s4, 0x20($sp)
/* 10208C 7F0CD55C AFB3001C */  sw    $s3, 0x1c($sp)
/* 102090 7F0CD560 8FA400AC */  lw    $a0, 0xac($sp)
/* 102094 7F0CD564 30460003 */  andi  $a2, $v0, 3
/* 102098 7F0CD568 AFAE0010 */  sw    $t6, 0x10($sp)
/* 10209C 7F0CD56C AFAF0014 */  sw    $t7, 0x14($sp)
/* 1020A0 7F0CD570 0FC3315D */  jal   texTrySetTileState
/* 1020A4 7F0CD574 AFB80018 */   sw    $t8, 0x18($sp)
/* 1020A8 7F0CD578 1040002D */  beqz  $v0, .L7F0CD630
/* 1020AC 7F0CD57C 02C08825 */   move  $s1, $s6
/* 1020B0 7F0CD580 8EAD0008 */  lw    $t5, 8($s5)
/* 1020B4 7F0CD584 3C01F500 */  lui   $at, 0xf500
/* 1020B8 7F0CD588 26D60008 */  addiu $s6, $s6, 8
/* 1020BC 7F0CD58C 000DCEC0 */  sll   $t9, $t5, 0x1b
/* 1020C0 7F0CD590 00194F42 */  srl   $t1, $t9, 0x1d
/* 1020C4 7F0CD594 312A0007 */  andi  $t2, $t1, 7
/* 1020C8 7F0CD598 000A5D40 */  sll   $t3, $t2, 0x15
/* 1020CC 7F0CD59C 01616025 */  or    $t4, $t3, $at
/* 1020D0 7F0CD5A0 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 1020D4 7F0CD5A4 31AE0003 */  andi  $t6, $t5, 3
/* 1020D8 7F0CD5A8 000E7CC0 */  sll   $t7, $t6, 0x13
/* 1020DC 7F0CD5AC 321901FF */  andi  $t9, $s0, 0x1ff
/* 1020E0 7F0CD5B0 00194A40 */  sll   $t1, $t9, 9
/* 1020E4 7F0CD5B4 018FC025 */  or    $t8, $t4, $t7
/* 1020E8 7F0CD5B8 03095025 */  or    $t2, $t8, $t1
/* 1020EC 7F0CD5BC 316D01FF */  andi  $t5, $t3, 0x1ff
/* 1020F0 7F0CD5C0 014D7025 */  or    $t6, $t2, $t5
/* 1020F4 7F0CD5C4 AE2E0000 */  sw    $t6, ($s1)
/* 1020F8 7F0CD5C8 0FC332B3 */  jal   texModeToGbiMode
/* 1020FC 7F0CD5CC 8FA400C4 */   lw    $a0, 0xc4($sp)
/* 102100 7F0CD5D0 00408025 */  move  $s0, $v0
/* 102104 7F0CD5D4 0FC332B3 */  jal   texModeToGbiMode
/* 102108 7F0CD5D8 8FA400C0 */   lw    $a0, 0xc0($sp)
/* 10210C 7F0CD5DC 8FB900AC */  lw    $t9, 0xac($sp)
/* 102110 7F0CD5E0 304C0003 */  andi  $t4, $v0, 3
/* 102114 7F0CD5E4 000C7A00 */  sll   $t7, $t4, 8
/* 102118 7F0CD5E8 33380007 */  andi  $t8, $t9, 7
/* 10211C 7F0CD5EC 00184E00 */  sll   $t1, $t8, 0x18
/* 102120 7F0CD5F0 01E95825 */  or    $t3, $t7, $t1
/* 102124 7F0CD5F4 320A0003 */  andi  $t2, $s0, 3
/* 102128 7F0CD5F8 000A6C80 */  sll   $t5, $t2, 0x12
/* 10212C 7F0CD5FC 016D7025 */  or    $t6, $t3, $t5
/* 102130 7F0CD600 328C000F */  andi  $t4, $s4, 0xf
/* 102134 7F0CD604 000CCB80 */  sll   $t9, $t4, 0xe
/* 102138 7F0CD608 324F000F */  andi  $t7, $s2, 0xf
/* 10213C 7F0CD60C 000F4A80 */  sll   $t1, $t7, 0xa
/* 102140 7F0CD610 01D9C025 */  or    $t8, $t6, $t9
/* 102144 7F0CD614 326B000F */  andi  $t3, $s3, 0xf
/* 102148 7F0CD618 000B6900 */  sll   $t5, $t3, 4
/* 10214C 7F0CD61C 03095025 */  or    $t2, $t8, $t1
/* 102150 7F0CD620 014D6025 */  or    $t4, $t2, $t5
/* 102154 7F0CD624 324E000F */  andi  $t6, $s2, 0xf
/* 102158 7F0CD628 018EC825 */  or    $t9, $t4, $t6
/* 10215C 7F0CD62C AE390004 */  sw    $t9, 4($s1)
.L7F0CD630:
/* 102160 7F0CD630 8FA200C8 */  lw    $v0, 0xc8($sp)
/* 102164 7F0CD634 24030002 */  li    $v1, 2
/* 102168 7F0CD638 02A02025 */  move  $a0, $s5
/* 10216C 7F0CD63C 14430005 */  bne   $v0, $v1, .L7F0CD654
/* 102170 7F0CD640 02402825 */   move  $a1, $s2
/* 102174 7F0CD644 57C00004 */  bnezl $fp, .L7F0CD658
/* 102178 7F0CD648 00008025 */   move  $s0, $zero
/* 10217C 7F0CD64C 10000002 */  b     .L7F0CD658
/* 102180 7F0CD650 00608025 */   move  $s0, $v1
.L7F0CD654:
/* 102184 7F0CD654 00008025 */  move  $s0, $zero
.L7F0CD658:
/* 102188 7F0CD658 14430005 */  bne   $v0, $v1, .L7F0CD670
/* 10218C 7F0CD65C AFB00090 */   sw    $s0, 0x90($sp)
/* 102190 7F0CD660 57C00004 */  bnezl $fp, .L7F0CD674
/* 102194 7F0CD664 00008025 */   move  $s0, $zero
/* 102198 7F0CD668 10000002 */  b     .L7F0CD674
/* 10219C 7F0CD66C 00608025 */   move  $s0, $v1
.L7F0CD670:
/* 1021A0 7F0CD670 00008025 */  move  $s0, $zero
.L7F0CD674:
/* 1021A4 7F0CD674 0FC331C5 */  jal   texGetWidthAtLod
/* 1021A8 7F0CD678 0200B825 */   move  $s7, $s0
/* 1021AC 7F0CD67C 8FAF00C8 */  lw    $t7, 0xc8($sp)
/* 1021B0 7F0CD680 00409825 */  move  $s3, $v0
/* 1021B4 7F0CD684 24010002 */  li    $at, 2
/* 1021B8 7F0CD688 15E10005 */  bne   $t7, $at, .L7F0CD6A0
/* 1021BC 7F0CD68C 2678FFFF */   addiu $t8, $s3, -1
/* 1021C0 7F0CD690 57C00004 */  bnezl $fp, .L7F0CD6A4
/* 1021C4 7F0CD694 00008025 */   move  $s0, $zero
/* 1021C8 7F0CD698 10000002 */  b     .L7F0CD6A4
/* 1021CC 7F0CD69C 24100002 */   li    $s0, 2
.L7F0CD6A0:
/* 1021D0 7F0CD6A0 00008025 */  move  $s0, $zero
.L7F0CD6A4:
/* 1021D4 7F0CD6A4 00184880 */  sll   $t1, $t8, 2
/* 1021D8 7F0CD6A8 0209A021 */  addu  $s4, $s0, $t1
/* 1021DC 7F0CD6AC 02A02025 */  move  $a0, $s5
/* 1021E0 7F0CD6B0 0FC331FF */  jal   texGetHeightAtLod
/* 1021E4 7F0CD6B4 02402825 */   move  $a1, $s2
/* 1021E8 7F0CD6B8 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 1021EC 7F0CD6BC 24010002 */  li    $at, 2
/* 1021F0 7F0CD6C0 00409825 */  move  $s3, $v0
/* 1021F4 7F0CD6C4 15610005 */  bne   $t3, $at, .L7F0CD6DC
/* 1021F8 7F0CD6C8 8FA400AC */   lw    $a0, 0xac($sp)
/* 1021FC 7F0CD6CC 57C00004 */  bnezl $fp, .L7F0CD6E0
/* 102200 7F0CD6D0 00008025 */   move  $s0, $zero
/* 102204 7F0CD6D4 10000002 */  b     .L7F0CD6E0
/* 102208 7F0CD6D8 24100002 */   li    $s0, 2
.L7F0CD6DC:
/* 10220C 7F0CD6DC 00008025 */  move  $s0, $zero
.L7F0CD6E0:
/* 102210 7F0CD6E0 266AFFFF */  addiu $t2, $s3, -1
/* 102214 7F0CD6E4 000A6880 */  sll   $t5, $t2, 2
/* 102218 7F0CD6E8 020D8821 */  addu  $s1, $s0, $t5
/* 10221C 7F0CD6EC AFB10010 */  sw    $s1, 0x10($sp)
/* 102220 7F0CD6F0 8FA50090 */  lw    $a1, 0x90($sp)
/* 102224 7F0CD6F4 02E03025 */  move  $a2, $s7
/* 102228 7F0CD6F8 0FC331A4 */  jal   texTrySetTileSize
/* 10222C 7F0CD6FC 02803825 */   move  $a3, $s4
/* 102230 7F0CD700 10400014 */  beqz  $v0, .L7F0CD754
/* 102234 7F0CD704 26520001 */   addiu $s2, $s2, 1
/* 102238 7F0CD708 8FAC0090 */  lw    $t4, 0x90($sp)
/* 10223C 7F0CD70C 3C01F200 */  lui   $at, 0xf200
/* 102240 7F0CD710 32F80FFF */  andi  $t8, $s7, 0xfff
/* 102244 7F0CD714 318E0FFF */  andi  $t6, $t4, 0xfff
/* 102248 7F0CD718 000ECB00 */  sll   $t9, $t6, 0xc
/* 10224C 7F0CD71C 03217825 */  or    $t7, $t9, $at
/* 102250 7F0CD720 01F84825 */  or    $t1, $t7, $t8
/* 102254 7F0CD724 02C01025 */  move  $v0, $s6
/* 102258 7F0CD728 AC490000 */  sw    $t1, ($v0)
/* 10225C 7F0CD72C 8FAB00AC */  lw    $t3, 0xac($sp)
/* 102260 7F0CD730 328C0FFF */  andi  $t4, $s4, 0xfff
/* 102264 7F0CD734 000C7300 */  sll   $t6, $t4, 0xc
/* 102268 7F0CD738 316A0007 */  andi  $t2, $t3, 7
/* 10226C 7F0CD73C 000A6E00 */  sll   $t5, $t2, 0x18
/* 102270 7F0CD740 01AEC825 */  or    $t9, $t5, $t6
/* 102274 7F0CD744 322F0FFF */  andi  $t7, $s1, 0xfff
/* 102278 7F0CD748 032FC025 */  or    $t8, $t9, $t7
/* 10227C 7F0CD74C AC580004 */  sw    $t8, 4($v0)
/* 102280 7F0CD750 26D60008 */  addiu $s6, $s6, 8
.L7F0CD754:
/* 102284 7F0CD754 8FAC00AC */  lw    $t4, 0xac($sp)
/* 102288 7F0CD758 8FA900B4 */  lw    $t1, 0xb4($sp)
/* 10228C 7F0CD75C 8FAB0080 */  lw    $t3, 0x80($sp)
/* 102290 7F0CD760 8FAE0064 */  lw    $t6, 0x64($sp)
/* 102294 7F0CD764 258D0001 */  addiu $t5, $t4, 1
/* 102298 7F0CD768 012B5021 */  addu  $t2, $t1, $t3
/* 10229C 7F0CD76C AFAD00AC */  sw    $t5, 0xac($sp)
/* 1022A0 7F0CD770 15AEFF49 */  bne   $t5, $t6, .L7F0CD498
/* 1022A4 7F0CD774 AFAA00B4 */   sw    $t2, 0xb4($sp)
.L7F0CD778:
/* 1022A8 7F0CD778 8FBF005C */  lw    $ra, 0x5c($sp)
/* 1022AC 7F0CD77C 02C01025 */  move  $v0, $s6
/* 1022B0 7F0CD780 8FB60050 */  lw    $s6, 0x50($sp)
/* 1022B4 7F0CD784 8FB00038 */  lw    $s0, 0x38($sp)
/* 1022B8 7F0CD788 8FB1003C */  lw    $s1, 0x3c($sp)
/* 1022BC 7F0CD78C 8FB20040 */  lw    $s2, 0x40($sp)
/* 1022C0 7F0CD790 8FB30044 */  lw    $s3, 0x44($sp)
/* 1022C4 7F0CD794 8FB40048 */  lw    $s4, 0x48($sp)
/* 1022C8 7F0CD798 8FB5004C */  lw    $s5, 0x4c($sp)
/* 1022CC 7F0CD79C 8FB70054 */  lw    $s7, 0x54($sp)
/* 1022D0 7F0CD7A0 8FBE0058 */  lw    $fp, 0x58($sp)
/* 1022D4 7F0CD7A4 03E00008 */  jr    $ra
/* 1022D8 7F0CD7A8 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void texWriteLoadToTmemZero(void) {

}
#else
GLOBAL_ASM(
.text
glabel texWriteLoadToTmemZero
/* 1022DC 7F0CD7AC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 1022E0 7F0CD7B0 AFB00034 */  sw    $s0, 0x34($sp)
/* 1022E4 7F0CD7B4 00808025 */  move  $s0, $a0
/* 1022E8 7F0CD7B8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1022EC 7F0CD7BC AFB10038 */  sw    $s1, 0x38($sp)
/* 1022F0 7F0CD7C0 00A08825 */  move  $s1, $a1
/* 1022F4 7F0CD7C4 0FC332CE */  jal   sub_GAME_7F0CCB38
/* 1022F8 7F0CD7C8 00A02025 */   move  $a0, $a1
/* 1022FC 7F0CD7CC AFA2008C */  sw    $v0, 0x8c($sp)
/* 102300 7F0CD7D0 02202025 */  move  $a0, $s1
/* 102304 7F0CD7D4 27A50094 */  addiu $a1, $sp, 0x94
/* 102308 7F0CD7D8 0FC33275 */  jal   texGetDepthAndSize
/* 10230C 7F0CD7DC 27A60090 */   addiu $a2, $sp, 0x90
/* 102310 7F0CD7E0 8E2E000C */  lw    $t6, 0xc($s1)
/* 102314 7F0CD7E4 24040007 */  li    $a0, 7
/* 102318 7F0CD7E8 02001025 */  move  $v0, $s0
/* 10231C 7F0CD7EC 000E7F82 */  srl   $t7, $t6, 0x1e
/* 102320 7F0CD7F0 15E0004D */  bnez  $t7, .L7F0CD928
/* 102324 7F0CD7F4 3C01FD00 */   lui   $at, 0xfd00
/* 102328 7F0CD7F8 8E380008 */  lw    $t8, 8($s1)
/* 10232C 7F0CD7FC 8FAF0094 */  lw    $t7, 0x94($sp)
/* 102330 7F0CD800 3C01FD00 */  lui   $at, 0xfd00
/* 102334 7F0CD804 0018CEC0 */  sll   $t9, $t8, 0x1b
/* 102338 7F0CD808 00195F42 */  srl   $t3, $t9, 0x1d
/* 10233C 7F0CD80C 316C0007 */  andi  $t4, $t3, 7
/* 102340 7F0CD810 000C6D40 */  sll   $t5, $t4, 0x15
/* 102344 7F0CD814 31F80003 */  andi  $t8, $t7, 3
/* 102348 7F0CD818 0018CCC0 */  sll   $t9, $t8, 0x13
/* 10234C 7F0CD81C 01A17025 */  or    $t6, $t5, $at
/* 102350 7F0CD820 01D95825 */  or    $t3, $t6, $t9
/* 102354 7F0CD824 02001025 */  move  $v0, $s0
/* 102358 7F0CD828 AC4B0000 */  sw    $t3, ($v0)
/* 10235C 7F0CD82C 8E2C0004 */  lw    $t4, 4($s1)
/* 102360 7F0CD830 26100008 */  addiu $s0, $s0, 8
/* 102364 7F0CD834 00003825 */  move  $a3, $zero
/* 102368 7F0CD838 AC4C0004 */  sw    $t4, 4($v0)
/* 10236C 7F0CD83C 8E250008 */  lw    $a1, 8($s1)
/* 102370 7F0CD840 AFA00028 */  sw    $zero, 0x28($sp)
/* 102374 7F0CD844 AFA00024 */  sw    $zero, 0x24($sp)
/* 102378 7F0CD848 00056EC0 */  sll   $t5, $a1, 0x1b
/* 10237C 7F0CD84C 000D2F42 */  srl   $a1, $t5, 0x1d
/* 102380 7F0CD850 AFA00020 */  sw    $zero, 0x20($sp)
/* 102384 7F0CD854 AFA0001C */  sw    $zero, 0x1c($sp)
/* 102388 7F0CD858 AFA00018 */  sw    $zero, 0x18($sp)
/* 10238C 7F0CD85C AFA00014 */  sw    $zero, 0x14($sp)
/* 102390 7F0CD860 AFA00010 */  sw    $zero, 0x10($sp)
/* 102394 7F0CD864 0FC3315D */  jal   texTrySetTileState
/* 102398 7F0CD868 8FA60094 */   lw    $a2, 0x94($sp)
/* 10239C 7F0CD86C 10400010 */  beqz  $v0, .L7F0CD8B0
/* 1023A0 7F0CD870 3C0A0700 */   lui   $t2, 0x700
/* 1023A4 7F0CD874 8E380008 */  lw    $t8, 8($s1)
/* 1023A8 7F0CD878 8FAF0094 */  lw    $t7, 0x94($sp)
/* 1023AC 7F0CD87C 02001025 */  move  $v0, $s0
/* 1023B0 7F0CD880 001876C0 */  sll   $t6, $t8, 0x1b
/* 1023B4 7F0CD884 000ECF42 */  srl   $t9, $t6, 0x1d
/* 1023B8 7F0CD888 332B0007 */  andi  $t3, $t9, 7
/* 1023BC 7F0CD88C 000B6540 */  sll   $t4, $t3, 0x15
/* 1023C0 7F0CD890 3C01F500 */  lui   $at, 0xf500
/* 1023C4 7F0CD894 31F80003 */  andi  $t8, $t7, 3
/* 1023C8 7F0CD898 001874C0 */  sll   $t6, $t8, 0x13
/* 1023CC 7F0CD89C 01816825 */  or    $t5, $t4, $at
/* 1023D0 7F0CD8A0 01AEC825 */  or    $t9, $t5, $t6
/* 1023D4 7F0CD8A4 AC590000 */  sw    $t9, ($v0)
/* 1023D8 7F0CD8A8 AC4A0004 */  sw    $t2, 4($v0)
/* 1023DC 7F0CD8AC 26100008 */  addiu $s0, $s0, 8
.L7F0CD8B0:
/* 1023E0 7F0CD8B0 02001025 */  move  $v0, $s0
/* 1023E4 7F0CD8B4 26100008 */  addiu $s0, $s0, 8
/* 1023E8 7F0CD8B8 3C0BE600 */  lui   $t3, 0xe600
/* 1023EC 7F0CD8BC AC4B0000 */  sw    $t3, ($v0)
/* 1023F0 7F0CD8C0 AC400004 */  sw    $zero, 4($v0)
/* 1023F4 7F0CD8C4 02002825 */  move  $a1, $s0
/* 1023F8 7F0CD8C8 3C0CF300 */  lui   $t4, 0xf300
/* 1023FC 7F0CD8CC ACAC0000 */  sw    $t4, ($a1)
/* 102400 7F0CD8D0 8FA30090 */  lw    $v1, 0x90($sp)
/* 102404 7F0CD8D4 3C0A0700 */  lui   $t2, 0x700
/* 102408 7F0CD8D8 8FAE008C */  lw    $t6, 0x8c($sp)
/* 10240C 7F0CD8DC 2463FFFF */  addiu $v1, $v1, -1
/* 102410 7F0CD8E0 286107FF */  slti  $at, $v1, 0x7ff
/* 102414 7F0CD8E4 10200003 */  beqz  $at, .L7F0CD8F4
/* 102418 7F0CD8E8 26100008 */   addiu $s0, $s0, 8
/* 10241C 7F0CD8EC 10000002 */  b     .L7F0CD8F8
/* 102420 7F0CD8F0 00602025 */   move  $a0, $v1
.L7F0CD8F4:
/* 102424 7F0CD8F4 240407FF */  li    $a0, 2047
.L7F0CD8F8:
/* 102428 7F0CD8F8 308F0FFF */  andi  $t7, $a0, 0xfff
/* 10242C 7F0CD8FC 000FC300 */  sll   $t8, $t7, 0xc
/* 102430 7F0CD900 030A6825 */  or    $t5, $t8, $t2
/* 102434 7F0CD904 31D90FFF */  andi  $t9, $t6, 0xfff
/* 102438 7F0CD908 01B95825 */  or    $t3, $t5, $t9
/* 10243C 7F0CD90C 02001025 */  move  $v0, $s0
/* 102440 7F0CD910 ACAB0004 */  sw    $t3, 4($a1)
/* 102444 7F0CD914 3C0CE700 */  lui   $t4, 0xe700
/* 102448 7F0CD918 AC4C0000 */  sw    $t4, ($v0)
/* 10244C 7F0CD91C AC400004 */  sw    $zero, 4($v0)
/* 102450 7F0CD920 1000008A */  b     .L7F0CDB4C
/* 102454 7F0CD924 26100008 */   addiu $s0, $s0, 8
.L7F0CD928:
/* 102458 7F0CD928 8E2F0008 */  lw    $t7, 8($s1)
/* 10245C 7F0CD92C 8FAC0094 */  lw    $t4, 0x94($sp)
/* 102460 7F0CD930 26100008 */  addiu $s0, $s0, 8
/* 102464 7F0CD934 000FC6C0 */  sll   $t8, $t7, 0x1b
/* 102468 7F0CD938 00187742 */  srl   $t6, $t8, 0x1d
/* 10246C 7F0CD93C 31CD0007 */  andi  $t5, $t6, 7
/* 102470 7F0CD940 000DCD40 */  sll   $t9, $t5, 0x15
/* 102474 7F0CD944 318F0003 */  andi  $t7, $t4, 3
/* 102478 7F0CD948 000FC4C0 */  sll   $t8, $t7, 0x13
/* 10247C 7F0CD94C 03215825 */  or    $t3, $t9, $at
/* 102480 7F0CD950 01787025 */  or    $t6, $t3, $t8
/* 102484 7F0CD954 AC4E0000 */  sw    $t6, ($v0)
/* 102488 7F0CD958 8E2D0004 */  lw    $t5, 4($s1)
/* 10248C 7F0CD95C 24040007 */  li    $a0, 7
/* 102490 7F0CD960 00003825 */  move  $a3, $zero
/* 102494 7F0CD964 AC4D0004 */  sw    $t5, 4($v0)
/* 102498 7F0CD968 8E250008 */  lw    $a1, 8($s1)
/* 10249C 7F0CD96C AFA00028 */  sw    $zero, 0x28($sp)
/* 1024A0 7F0CD970 AFA00024 */  sw    $zero, 0x24($sp)
/* 1024A4 7F0CD974 0005CEC0 */  sll   $t9, $a1, 0x1b
/* 1024A8 7F0CD978 00192F42 */  srl   $a1, $t9, 0x1d
/* 1024AC 7F0CD97C AFA00020 */  sw    $zero, 0x20($sp)
/* 1024B0 7F0CD980 AFA0001C */  sw    $zero, 0x1c($sp)
/* 1024B4 7F0CD984 AFA00018 */  sw    $zero, 0x18($sp)
/* 1024B8 7F0CD988 AFA00014 */  sw    $zero, 0x14($sp)
/* 1024BC 7F0CD98C AFA00010 */  sw    $zero, 0x10($sp)
/* 1024C0 7F0CD990 0FC3315D */  jal   texTrySetTileState
/* 1024C4 7F0CD994 8FA60094 */   lw    $a2, 0x94($sp)
/* 1024C8 7F0CD998 10400011 */  beqz  $v0, .L7F0CD9E0
/* 1024CC 7F0CD99C 00003025 */   move  $a2, $zero
/* 1024D0 7F0CD9A0 8E2F0008 */  lw    $t7, 8($s1)
/* 1024D4 7F0CD9A4 8FAC0094 */  lw    $t4, 0x94($sp)
/* 1024D8 7F0CD9A8 02001025 */  move  $v0, $s0
/* 1024DC 7F0CD9AC 000F5EC0 */  sll   $t3, $t7, 0x1b
/* 1024E0 7F0CD9B0 000BC742 */  srl   $t8, $t3, 0x1d
/* 1024E4 7F0CD9B4 330E0007 */  andi  $t6, $t8, 7
/* 1024E8 7F0CD9B8 000E6D40 */  sll   $t5, $t6, 0x15
/* 1024EC 7F0CD9BC 3C01F500 */  lui   $at, 0xf500
/* 1024F0 7F0CD9C0 318F0003 */  andi  $t7, $t4, 3
/* 1024F4 7F0CD9C4 000F5CC0 */  sll   $t3, $t7, 0x13
/* 1024F8 7F0CD9C8 01A1C825 */  or    $t9, $t5, $at
/* 1024FC 7F0CD9CC 3C0A0700 */  lui   $t2, 0x700
/* 102500 7F0CD9D0 032BC025 */  or    $t8, $t9, $t3
/* 102504 7F0CD9D4 AC580000 */  sw    $t8, ($v0)
/* 102508 7F0CD9D8 AC4A0004 */  sw    $t2, 4($v0)
/* 10250C 7F0CD9DC 26100008 */  addiu $s0, $s0, 8
.L7F0CD9E0:
/* 102510 7F0CD9E0 02001025 */  move  $v0, $s0
/* 102514 7F0CD9E4 26100008 */  addiu $s0, $s0, 8
/* 102518 7F0CD9E8 3C0EE600 */  lui   $t6, 0xe600
/* 10251C 7F0CD9EC AC4E0000 */  sw    $t6, ($v0)
/* 102520 7F0CD9F0 AC400004 */  sw    $zero, 4($v0)
/* 102524 7F0CD9F4 02002825 */  move  $a1, $s0
/* 102528 7F0CD9F8 3C0DF300 */  lui   $t5, 0xf300
/* 10252C 7F0CD9FC ACAD0000 */  sw    $t5, ($a1)
/* 102530 7F0CDA00 8FA30090 */  lw    $v1, 0x90($sp)
/* 102534 7F0CDA04 3C0A0700 */  lui   $t2, 0x700
/* 102538 7F0CDA08 8FAB008C */  lw    $t3, 0x8c($sp)
/* 10253C 7F0CDA0C 2463FFFF */  addiu $v1, $v1, -1
/* 102540 7F0CDA10 286107FF */  slti  $at, $v1, 0x7ff
/* 102544 7F0CDA14 10200003 */  beqz  $at, .L7F0CDA24
/* 102548 7F0CDA18 26100008 */   addiu $s0, $s0, 8
/* 10254C 7F0CDA1C 10000002 */  b     .L7F0CDA28
/* 102550 7F0CDA20 00602025 */   move  $a0, $v1
.L7F0CDA24:
/* 102554 7F0CDA24 240407FF */  li    $a0, 2047
.L7F0CDA28:
/* 102558 7F0CDA28 308C0FFF */  andi  $t4, $a0, 0xfff
/* 10255C 7F0CDA2C 000C7B00 */  sll   $t7, $t4, 0xc
/* 102560 7F0CDA30 01EAC825 */  or    $t9, $t7, $t2
/* 102564 7F0CDA34 31780FFF */  andi  $t8, $t3, 0xfff
/* 102568 7F0CDA38 03387025 */  or    $t6, $t9, $t8
/* 10256C 7F0CDA3C ACAE0004 */  sw    $t6, 4($a1)
/* 102570 7F0CDA40 02001025 */  move  $v0, $s0
/* 102574 7F0CDA44 3C0DE700 */  lui   $t5, 0xe700
/* 102578 7F0CDA48 AC4D0000 */  sw    $t5, ($v0)
/* 10257C 7F0CDA4C AC400004 */  sw    $zero, 4($v0)
/* 102580 7F0CDA50 922C000A */  lbu   $t4, 0xa($s1)
/* 102584 7F0CDA54 8FA80090 */  lw    $t0, 0x90($sp)
/* 102588 7F0CDA58 240F03FF */  li    $t7, 1023
/* 10258C 7F0CDA5C 01EC1823 */  subu  $v1, $t7, $t4
/* 102590 7F0CDA60 0068082B */  sltu  $at, $v1, $t0
/* 102594 7F0CDA64 10200003 */  beqz  $at, .L7F0CDA74
/* 102598 7F0CDA68 26100008 */   addiu $s0, $s0, 8
/* 10259C 7F0CDA6C 10000002 */  b     .L7F0CDA78
/* 1025A0 7F0CDA70 00604825 */   move  $t1, $v1
.L7F0CDA74:
/* 1025A4 7F0CDA74 00004825 */  move  $t1, $zero
.L7F0CDA78:
/* 1025A8 7F0CDA78 01094023 */  subu  $t0, $t0, $t1
/* 1025AC 7F0CDA7C 24190100 */  li    $t9, 256
/* 1025B0 7F0CDA80 AFB90010 */  sw    $t9, 0x10($sp)
/* 1025B4 7F0CDA84 AFA80074 */  sw    $t0, 0x74($sp)
/* 1025B8 7F0CDA88 24040007 */  li    $a0, 7
/* 1025BC 7F0CDA8C 00002825 */  move  $a1, $zero
/* 1025C0 7F0CDA90 24070001 */  li    $a3, 1
/* 1025C4 7F0CDA94 AFA00014 */  sw    $zero, 0x14($sp)
/* 1025C8 7F0CDA98 AFA00018 */  sw    $zero, 0x18($sp)
/* 1025CC 7F0CDA9C AFA0001C */  sw    $zero, 0x1c($sp)
/* 1025D0 7F0CDAA0 AFA00020 */  sw    $zero, 0x20($sp)
/* 1025D4 7F0CDAA4 AFA00024 */  sw    $zero, 0x24($sp)
/* 1025D8 7F0CDAA8 AFA00028 */  sw    $zero, 0x28($sp)
/* 1025DC 7F0CDAAC 0FC3315D */  jal   texTrySetTileState
/* 1025E0 7F0CDAB0 AFA90070 */   sw    $t1, 0x70($sp)
/* 1025E4 7F0CDAB4 8FA80074 */  lw    $t0, 0x74($sp)
/* 1025E8 7F0CDAB8 8FA90070 */  lw    $t1, 0x70($sp)
/* 1025EC 7F0CDABC 10400007 */  beqz  $v0, .L7F0CDADC
/* 1025F0 7F0CDAC0 3C0A0700 */   lui   $t2, 0x700
/* 1025F4 7F0CDAC4 02001025 */  move  $v0, $s0
/* 1025F8 7F0CDAC8 3C18F500 */  lui   $t8, (0xF5000300 >> 16) # lui $t8, 0xf500
/* 1025FC 7F0CDACC 37180300 */  ori   $t8, (0xF5000300 & 0xFFFF) # ori $t8, $t8, 0x300
/* 102600 7F0CDAD0 AC580000 */  sw    $t8, ($v0)
/* 102604 7F0CDAD4 AC4A0004 */  sw    $t2, 4($v0)
/* 102608 7F0CDAD8 26100008 */  addiu $s0, $s0, 8
.L7F0CDADC:
/* 10260C 7F0CDADC 02001025 */  move  $v0, $s0
/* 102610 7F0CDAE0 310F03FF */  andi  $t7, $t0, 0x3ff
/* 102614 7F0CDAE4 000F6380 */  sll   $t4, $t7, 0xe
/* 102618 7F0CDAE8 312403FF */  andi  $a0, $t1, 0x3ff
/* 10261C 7F0CDAEC 3C01F000 */  lui   $at, 0xf000
/* 102620 7F0CDAF0 26100008 */  addiu $s0, $s0, 8
/* 102624 7F0CDAF4 3C0EE600 */  lui   $t6, 0xe600
/* 102628 7F0CDAF8 01815825 */  or    $t3, $t4, $at
/* 10262C 7F0CDAFC 00046880 */  sll   $t5, $a0, 2
/* 102630 7F0CDB00 AC4E0000 */  sw    $t6, ($v0)
/* 102634 7F0CDB04 AC400004 */  sw    $zero, 4($v0)
/* 102638 7F0CDB08 016DC825 */  or    $t9, $t3, $t5
/* 10263C 7F0CDB0C 02001825 */  move  $v1, $s0
/* 102640 7F0CDB10 AC790000 */  sw    $t9, ($v1)
/* 102644 7F0CDB14 9238000A */  lbu   $t8, 0xa($s1)
/* 102648 7F0CDB18 01A02025 */  move  $a0, $t5
/* 10264C 7F0CDB1C 26100008 */  addiu $s0, $s0, 8
/* 102650 7F0CDB20 03087021 */  addu  $t6, $t8, $t0
/* 102654 7F0CDB24 31CD03FF */  andi  $t5, $t6, 0x3ff
/* 102658 7F0CDB28 000D7B80 */  sll   $t7, $t5, 0xe
/* 10265C 7F0CDB2C 01EA6025 */  or    $t4, $t7, $t2
/* 102660 7F0CDB30 01845825 */  or    $t3, $t4, $a0
/* 102664 7F0CDB34 02002825 */  move  $a1, $s0
/* 102668 7F0CDB38 AC6B0004 */  sw    $t3, 4($v1)
/* 10266C 7F0CDB3C 3C19E700 */  lui   $t9, 0xe700
/* 102670 7F0CDB40 ACB90000 */  sw    $t9, ($a1)
/* 102674 7F0CDB44 ACA00004 */  sw    $zero, 4($a1)
/* 102678 7F0CDB48 26100008 */  addiu $s0, $s0, 8
.L7F0CDB4C:
/* 10267C 7F0CDB4C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 102680 7F0CDB50 02001025 */  move  $v0, $s0
/* 102684 7F0CDB54 8FB00034 */  lw    $s0, 0x34($sp)
/* 102688 7F0CDB58 8FB10038 */  lw    $s1, 0x38($sp)
/* 10268C 7F0CDB5C 03E00008 */  jr    $ra
/* 102690 7F0CDB60 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif


Gfx *texWriteTile(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4, s32 tile)
{
    s32 masks;
    s32 maskt;
    s32 line;
    s32 uls;
    s32 ult;
    s32 lrs;
    s32 lrt;
    s32 sp50;

    masks = texDimensionToMask(tex->width);
    maskt = texDimensionToMask(tex->height);
    line = texGetLineSizeInBytes(tex, 0);
    sp50 = tex->unk0c_02;

    if (texSetLutMode(tex->lutmodeindex << G_MDSFT_TEXTLUT))
    {
        gDPSetTextureLUT(gdl++, tex->lutmodeindex << G_MDSFT_TEXTLUT);
    }

    if (texTrySetTileState(tile, tex->gbiformat, tex->depth, line, 0, arg2, arg3, masks, maskt, 0, 0))
    {
        gDPSetTile(gdl++, tex->gbiformat, tex->depth, line, 0x0000, tile, 0,
                texModeToGbiMode(arg3), maskt, G_TX_NOLOD,
                texModeToGbiMode(arg2), masks, G_TX_NOLOD);
    }

    uls = (arg4 == 2 && sp50 == 0 ? 2 : 0) + 0;
    ult = (arg4 == 2 && sp50 == 0 ? 2 : 0) + 0;
    lrs = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((tex->width - 1) << 2);
    lrt = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((tex->height - 1) << 2);

    if (texTrySetTileSize(tile, uls, ult, lrs, lrt))
    {
        gDPSetTileSize(gdl++, tile, uls, ult, lrs, lrt);
    }

    return gdl;
}


Gfx *texHandleType2(Gfx *gdl, struct tex *tex, s32 smode, s32 tmode, s32 offset)
{
    gdl = texWriteLoadToTmemAddr(gdl,tex,0);
    gdl = texWriteTileLods(gdl,tex,smode,tmode,offset,0,0);
    if (tex->maxlod == 1) {
        gdl = texWriteTileLods(gdl,tex,smode,tmode,offset,1,0);
    }
    return gdl;
}


Gfx * texHandleType1(Gfx *gdl,struct tex *tex1,s32 smode,s32 tmode,s32 offset,struct tex *tex2,u32 shifts,u32 shiftt,u32 min)
{
    u32 size;

    size = texGetSizeInBytes(tex2,0);
    gdl = texWriteLoadToTmemZero(gdl,tex2);
    gDPTileSync(gdl++);
    gdl = texWriteLoadToTmemAddr(gdl,tex1,size);
    gdl = texWriteTileFromDefinition(gdl,tex2,offset,shifts,shiftt,min);
    gdl = texWriteTileLods(gdl,tex1,smode,tmode,offset,1,size);
    if (tex1->maxlod == 1) {
        gdl = texWriteTileLods(gdl,tex1,smode,tmode,offset,2,size);
    }
    return gdl;
}


Gfx * texHandleType0(Gfx *gdl,struct tex *tex,s32 smode,s32 tmode,s32 offset,u32 shifts,u32 shiftt,u32 min)
{
    gdl = texWriteLoadToTmemAddr(gdl,tex,0);
    gdl = texWriteTileFromDefinition(gdl,tex,offset,shifts,shiftt,min);
    gdl = texWriteTileLods(gdl,tex,smode,tmode,offset,1,0);
    if (tex->maxlod == 1) {
        gdl = texWriteTileLods(gdl,tex,smode,tmode,offset,2,0);
    }
    return gdl;
}


Gfx * texHandleType4(Gfx *DL,u32 *arg1,s32 arg2,s32 arg3,s32 arg4)
{
    DL = texWriteLoadToTmemZero(DL,arg1);
    DL = texWriteTile(DL,arg1,arg2,arg3,arg4,0);
    return DL;
}


Gfx * texHandleType3(Gfx *DL,u32 *arg1,s32 arg2,s32 arg3,s32 arg4)
{
    DL = texWriteLoadToTmemZero(DL,arg1);
    DL = texWriteTile(DL,arg1,arg2,arg3,arg4,0);
    DL = texWriteTile(DL,arg1,arg2,arg3,arg4,1);
    return DL;
}





#ifdef NONMATCHING
void texLoadFromGdl(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel PADDINGHACKING
.word 0
/*D:8005BF20*/
glabel jpt_tlb_ptrDL_type_B1toC0
.word .L7F0CE66C
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE6B8
.word .L7F0CE694
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE66C
.word .L7F0CE1D8

/*D:8005BF60*/
glabel jpt_tlb_ptr_C0_image_recall_types
.word .L7F0CE2BC
.word .L7F0CE428
.word .L7F0CE4B8
.word .L7F0CE584
.word .L7F0CE5BC
.text
glabel texLoadFromGdl
/* 102C48 7F0CE118 27BDFF68 */  addiu $sp, $sp, -0x98
/* 102C4C 7F0CE11C AFB20038 */  sw    $s2, 0x38($sp)
/* 102C50 7F0CE120 AFBF0054 */  sw    $ra, 0x54($sp)
/* 102C54 7F0CE124 AFBE0050 */  sw    $fp, 0x50($sp)
/* 102C58 7F0CE128 AFB60048 */  sw    $s6, 0x48($sp)
/* 102C5C 7F0CE12C AFB40040 */  sw    $s4, 0x40($sp)
/* 102C60 7F0CE130 AFB10034 */  sw    $s1, 0x34($sp)
/* 102C64 7F0CE134 AFB00030 */  sw    $s0, 0x30($sp)
/* 102C68 7F0CE138 240E0001 */  li    $t6, 1
/* 102C6C 7F0CE13C 000590C3 */  sra   $s2, $a1, 3
/* 102C70 7F0CE140 00E0B025 */  move  $s6, $a3
/* 102C74 7F0CE144 AFB7004C */  sw    $s7, 0x4c($sp)
/* 102C78 7F0CE148 AFB50044 */  sw    $s5, 0x44($sp)
/* 102C7C 7F0CE14C AFB3003C */  sw    $s3, 0x3c($sp)
/* 102C80 7F0CE150 AFA600A0 */  sw    $a2, 0xa0($sp)
/* 102C84 7F0CE154 AFA0008C */  sw    $zero, 0x8c($sp)
/* 102C88 7F0CE158 0000A025 */  move  $s4, $zero
/* 102C8C 7F0CE15C 0000F025 */  move  $fp, $zero
/* 102C90 7F0CE160 AFAE005C */  sw    $t6, 0x5c($sp)
/* 102C94 7F0CE164 AFA00058 */  sw    $zero, 0x58($sp)
/* 102C98 7F0CE168 00808825 */  move  $s1, $a0
/* 102C9C 7F0CE16C 00C08025 */  move  $s0, $a2
/* 102CA0 7F0CE170 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 102CA4 7F0CE174 AFB20088 */   sw    $s2, 0x88($sp)
/* 102CA8 7F0CE178 16C00003 */  bnez  $s6, .L7F0CE188
/* 102CAC 7F0CE17C 2417000F */   li    $s7, 15
/* 102CB0 7F0CE180 3C168009 */  lui   $s6, %hi(ptr_texture_alloc_start)
/* 102CB4 7F0CE184 26D6C720 */  addiu $s6, %lo(ptr_texture_alloc_start) # addiu $s6, $s6, -0x38e0
.L7F0CE188:
/* 102CB8 7F0CE188 1A40016F */  blez  $s2, .L7F0CE748
/* 102CBC 7F0CE18C 3C158005 */   lui   $s5, %hi(D_800483C8)
/* 102CC0 7F0CE190 26B583C8 */  addiu $s5, %lo(D_800483C8) # addiu $s5, $s5, -0x7c38
.L7F0CE194:
/* 102CC4 7F0CE194 92220000 */  lbu   $v0, ($s1)
/* 102CC8 7F0CE198 284100C1 */  slti  $at, $v0, 0xc1
/* 102CCC 7F0CE19C 14200006 */  bnez  $at, .L7F0CE1B8
/* 102CD0 7F0CE1A0 244FFF4F */   addiu $t7, $v0, -0xb1
/* 102CD4 7F0CE1A4 240100E7 */  li    $at, 231
/* 102CD8 7F0CE1A8 50410129 */  beql  $v0, $at, .L7F0CE650
/* 102CDC 7F0CE1AC 8E210000 */   lw    $at, ($s1)
/* 102CE0 7F0CE1B0 1000015C */  b     .L7F0CE724
/* 102CE4 7F0CE1B4 8E210000 */   lw    $at, ($s1)
.L7F0CE1B8:
/* 102CE8 7F0CE1B8 2DE10010 */  sltiu $at, $t7, 0x10
/* 102CEC 7F0CE1BC 10200158 */  beqz  $at, .L7F0CE720
/* 102CF0 7F0CE1C0 000F7880 */   sll   $t7, $t7, 2
/* 102CF4 7F0CE1C4 3C018006 */  lui   $at, %hi(jpt_tlb_ptrDL_type_B1toC0)
/* 102CF8 7F0CE1C8 002F0821 */  addu  $at, $at, $t7
/* 102CFC 7F0CE1CC 8C2FBF20 */  lw    $t7, %lo(jpt_tlb_ptrDL_type_B1toC0)($at)
/* 102D00 7F0CE1D0 01E00008 */  jr    $t7
/* 102D04 7F0CE1D4 00000000 */   nop   
.L7F0CE1D8:
/* 102D08 7F0CE1D8 17C00006 */  bnez  $fp, .L7F0CE1F4
/* 102D0C 7F0CE1DC 02001025 */   move  $v0, $s0
/* 102D10 7F0CE1E0 3C18E700 */  lui   $t8, 0xe700
/* 102D14 7F0CE1E4 AC580000 */  sw    $t8, ($v0)
/* 102D18 7F0CE1E8 26100008 */  addiu $s0, $s0, 8
/* 102D1C 7F0CE1EC AC400004 */  sw    $zero, 4($v0)
/* 102D20 7F0CE1F0 241E0001 */  li    $fp, 1
.L7F0CE1F4:
/* 102D24 7F0CE1F4 8FB90058 */  lw    $t9, 0x58($sp)
/* 102D28 7F0CE1F8 02002025 */  move  $a0, $s0
/* 102D2C 7F0CE1FC 53200004 */  beql  $t9, $zero, .L7F0CE210
/* 102D30 7F0CE200 8E330004 */   lw    $s3, 4($s1)
/* 102D34 7F0CE204 0FC2ED80 */  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
/* 102D38 7F0CE208 AFA00058 */   sw    $zero, 0x58($sp)
/* 102D3C 7F0CE20C 8E330004 */  lw    $s3, 4($s1)
.L7F0CE210:
/* 102D40 7F0CE210 3C0E8005 */  lui   $t6, %hi(D_800483C4) 
/* 102D44 7F0CE214 8DCE83C4 */  lw    $t6, %lo(D_800483C4)($t6)
/* 102D48 7F0CE218 326D0FFF */  andi  $t5, $s3, 0xfff
/* 102D4C 7F0CE21C 01A09825 */  move  $s3, $t5
/* 102D50 7F0CE220 15AE000D */  bne   $t5, $t6, .L7F0CE258
/* 102D54 7F0CE224 02C02825 */   move  $a1, $s6
/* 102D58 7F0CE228 8EA40000 */  lw    $a0, ($s5)
/* 102D5C 7F0CE22C 000D7880 */  sll   $t7, $t5, 2
/* 102D60 7F0CE230 10800009 */  beqz  $a0, .L7F0CE258
/* 102D64 7F0CE234 008FC021 */   addu  $t8, $a0, $t7
/* 102D68 7F0CE238 93190000 */  lbu   $t9, ($t8)
/* 102D6C 7F0CE23C 2F2100FF */  sltiu $at, $t9, 0xff
/* 102D70 7F0CE240 10200003 */  beqz  $at, .L7F0CE250
/* 102D74 7F0CE244 00000000 */   nop   
/* 102D78 7F0CE248 10000004 */  b     .L7F0CE25C
/* 102D7C 7F0CE24C 24140001 */   li    $s4, 1
.L7F0CE250:
/* 102D80 7F0CE250 10000002 */  b     .L7F0CE25C
/* 102D84 7F0CE254 0000A025 */   move  $s4, $zero
.L7F0CE258:
/* 102D88 7F0CE258 0000A025 */  move  $s4, $zero
.L7F0CE25C:
/* 102D8C 7F0CE25C 0FC32FBA */  jal   texLoadFromTextureNum
/* 102D90 7F0CE260 02602025 */   move  $a0, $s3
/* 102D94 7F0CE264 02602025 */  move  $a0, $s3
/* 102D98 7F0CE268 0FC32EC3 */  jal   texFindInPool
/* 102D9C 7F0CE26C 02C02825 */   move  $a1, $s6
/* 102DA0 7F0CE270 104000F4 */  beqz  $v0, .L7F0CE644
/* 102DA4 7F0CE274 00409025 */   move  $s2, $v0
/* 102DA8 7F0CE278 8FA7005C */  lw    $a3, 0x5c($sp)
/* 102DAC 7F0CE27C AFA0005C */  sw    $zero, 0x5c($sp)
/* 102DB0 7F0CE280 02002025 */  move  $a0, $s0
/* 102DB4 7F0CE284 8FA5008C */  lw    $a1, 0x8c($sp)
/* 102DB8 7F0CE288 0FC333EF */  jal   texWriteTextureCmd
/* 102DBC 7F0CE28C 00403025 */   move  $a2, $v0
/* 102DC0 7F0CE290 8E230000 */  lw    $v1, ($s1)
/* 102DC4 7F0CE294 00408025 */  move  $s0, $v0
/* 102DC8 7F0CE298 306D0007 */  andi  $t5, $v1, 7
/* 102DCC 7F0CE29C 2DA10005 */  sltiu $at, $t5, 5
/* 102DD0 7F0CE2A0 102000D3 */  beqz  $at, .L7F0CE5F0
/* 102DD4 7F0CE2A4 000D6880 */   sll   $t5, $t5, 2
/* 102DD8 7F0CE2A8 3C018006 */  lui   $at, %hi(jpt_tlb_ptr_C0_image_recall_types)
/* 102DDC 7F0CE2AC 002D0821 */  addu  $at, $at, $t5
/* 102DE0 7F0CE2B0 8C2DBF60 */  lw    $t5, %lo(jpt_tlb_ptr_C0_image_recall_types)($at)
/* 102DE4 7F0CE2B4 01A00008 */  jr    $t5
/* 102DE8 7F0CE2B8 00000000 */   nop   
.L7F0CE2BC:
/* 102DEC 7F0CE2BC 8E290004 */  lw    $t1, 4($s1)
/* 102DF0 7F0CE2C0 8EA40000 */  lw    $a0, ($s5)
/* 102DF4 7F0CE2C4 00033582 */  srl   $a2, $v1, 0x16
/* 102DF8 7F0CE2C8 00097602 */  srl   $t6, $t1, 0x18
/* 102DFC 7F0CE2CC 31C900FF */  andi  $t1, $t6, 0xff
/* 102E00 7F0CE2D0 00033D02 */  srl   $a3, $v1, 0x14
/* 102E04 7F0CE2D4 00034482 */  srl   $t0, $v1, 0x12
/* 102E08 7F0CE2D8 00035382 */  srl   $t2, $v1, 0xe
/* 102E0C 7F0CE2DC 00035A82 */  srl   $t3, $v1, 0xa
/* 102E10 7F0CE2E0 30D80003 */  andi  $t8, $a2, 3
/* 102E14 7F0CE2E4 30F90003 */  andi  $t9, $a3, 3
/* 102E18 7F0CE2E8 310D0003 */  andi  $t5, $t0, 3
/* 102E1C 7F0CE2EC 314E000F */  andi  $t6, $t2, 0xf
/* 102E20 7F0CE2F0 316F000F */  andi  $t7, $t3, 0xf
/* 102E24 7F0CE2F4 03003025 */  move  $a2, $t8
/* 102E28 7F0CE2F8 03203825 */  move  $a3, $t9
/* 102E2C 7F0CE2FC 01A04025 */  move  $t0, $t5
/* 102E30 7F0CE300 01C05025 */  move  $t2, $t6
/* 102E34 7F0CE304 1080001B */  beqz  $a0, .L7F0CE374
/* 102E38 7F0CE308 01E05825 */   move  $t3, $t7
/* 102E3C 7F0CE30C 00131880 */  sll   $v1, $s3, 2
/* 102E40 7F0CE310 00831021 */  addu  $v0, $a0, $v1
/* 102E44 7F0CE314 90580000 */  lbu   $t8, ($v0)
/* 102E48 7F0CE318 240100FF */  li    $at, 255
/* 102E4C 7F0CE31C 17010015 */  bne   $t8, $at, .L7F0CE374
/* 102E50 7F0CE320 00000000 */   nop   
/* 102E54 7F0CE324 A0490000 */  sb    $t1, ($v0)
/* 102E58 7F0CE328 8EB90000 */  lw    $t9, ($s5)
/* 102E5C 7F0CE32C 2404000F */  li    $a0, 15
/* 102E60 7F0CE330 008E6823 */  subu  $t5, $a0, $t6
/* 102E64 7F0CE334 03231021 */  addu  $v0, $t9, $v1
/* 102E68 7F0CE338 90590001 */  lbu   $t9, 1($v0)
/* 102E6C 7F0CE33C 01A07025 */  move  $t6, $t5
/* 102E70 7F0CE340 000EC140 */  sll   $t8, $t6, 5
/* 102E74 7F0CE344 332DFF1F */  andi  $t5, $t9, 0xff1f
/* 102E78 7F0CE348 030D7025 */  or    $t6, $t8, $t5
/* 102E7C 7F0CE34C A04E0001 */  sb    $t6, 1($v0)
/* 102E80 7F0CE350 8EAF0000 */  lw    $t7, ($s5)
/* 102E84 7F0CE354 008BC023 */  subu  $t8, $a0, $t3
/* 102E88 7F0CE358 00186880 */  sll   $t5, $t8, 2
/* 102E8C 7F0CE35C 01E31021 */  addu  $v0, $t7, $v1
/* 102E90 7F0CE360 904F0001 */  lbu   $t7, 1($v0)
/* 102E94 7F0CE364 31AE001C */  andi  $t6, $t5, 0x1c
/* 102E98 7F0CE368 31F9FFE3 */  andi  $t9, $t7, 0xffe3
/* 102E9C 7F0CE36C 01D9C025 */  or    $t8, $t6, $t9
/* 102EA0 7F0CE370 A0580001 */  sb    $t8, 1($v0)
.L7F0CE374:
/* 102EA4 7F0CE374 12800024 */  beqz  $s4, .L7F0CE408
/* 102EA8 7F0CE378 02002025 */   move  $a0, $s0
/* 102EAC 7F0CE37C 8EAD0000 */  lw    $t5, ($s5)
/* 102EB0 7F0CE380 00137880 */  sll   $t7, $s3, 2
/* 102EB4 7F0CE384 AFA80010 */  sw    $t0, 0x10($sp)
/* 102EB8 7F0CE388 01AF1021 */  addu  $v0, $t5, $t7
/* 102EBC 7F0CE38C 904E0001 */  lbu   $t6, 1($v0)
/* 102EC0 7F0CE390 02002025 */  move  $a0, $s0
/* 102EC4 7F0CE394 02402825 */  move  $a1, $s2
/* 102EC8 7F0CE398 000EC942 */  srl   $t9, $t6, 5
/* 102ECC 7F0CE39C 02F9C023 */  subu  $t8, $s7, $t9
/* 102ED0 7F0CE3A0 AFB80014 */  sw    $t8, 0x14($sp)
/* 102ED4 7F0CE3A4 8C4D0000 */  lw    $t5, ($v0)
/* 102ED8 7F0CE3A8 000D7AC0 */  sll   $t7, $t5, 0xb
/* 102EDC 7F0CE3AC 000F7742 */  srl   $t6, $t7, 0x1d
/* 102EE0 7F0CE3B0 02EEC823 */  subu  $t9, $s7, $t6
/* 102EE4 7F0CE3B4 AFB90018 */  sw    $t9, 0x18($sp)
/* 102EE8 7F0CE3B8 90580000 */  lbu   $t8, ($v0)
/* 102EEC 7F0CE3BC 0FC337EA */  jal   texHandleType0
/* 102EF0 7F0CE3C0 AFB8001C */   sw    $t8, 0x1c($sp)
/* 102EF4 7F0CE3C4 3C0DBA00 */  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
/* 102EF8 7F0CE3C8 35AD1402 */  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
/* 102EFC 7F0CE3CC AC4D0000 */  sw    $t5, ($v0)
/* 102F00 7F0CE3D0 3C0EBA00 */  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
/* 102F04 7F0CE3D4 3C18BA00 */  lui   $t8, (0xBA001102 >> 16) # lui $t8, 0xba00
/* 102F08 7F0CE3D8 3C0F0010 */  lui   $t7, 0x10
/* 102F0C 7F0CE3DC 35CE1001 */  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
/* 102F10 7F0CE3E0 3C190001 */  lui   $t9, 1
/* 102F14 7F0CE3E4 37181102 */  ori   $t8, (0xBA001102 & 0xFFFF) # ori $t8, $t8, 0x1102
/* 102F18 7F0CE3E8 3C0D0004 */  lui   $t5, 4
/* 102F1C 7F0CE3EC AC4F0004 */  sw    $t7, 4($v0)
/* 102F20 7F0CE3F0 AC59000C */  sw    $t9, 0xc($v0)
/* 102F24 7F0CE3F4 AC4E0008 */  sw    $t6, 8($v0)
/* 102F28 7F0CE3F8 AC4D0014 */  sw    $t5, 0x14($v0)
/* 102F2C 7F0CE3FC AC580010 */  sw    $t8, 0x10($v0)
/* 102F30 7F0CE400 1000007B */  b     .L7F0CE5F0
/* 102F34 7F0CE404 24500018 */   addiu $s0, $v0, 0x18
.L7F0CE408:
/* 102F38 7F0CE408 02402825 */  move  $a1, $s2
/* 102F3C 7F0CE40C AFA80010 */  sw    $t0, 0x10($sp)
/* 102F40 7F0CE410 AFAA0014 */  sw    $t2, 0x14($sp)
/* 102F44 7F0CE414 AFAB0018 */  sw    $t3, 0x18($sp)
/* 102F48 7F0CE418 0FC337EA */  jal   texHandleType0
/* 102F4C 7F0CE41C AFA9001C */   sw    $t1, 0x1c($sp)
/* 102F50 7F0CE420 10000073 */  b     .L7F0CE5F0
/* 102F54 7F0CE424 00408025 */   move  $s0, $v0
.L7F0CE428:
/* 102F58 7F0CE428 8E240004 */  lw    $a0, 4($s1)
/* 102F5C 7F0CE42C 02C02825 */  move  $a1, $s6
/* 102F60 7F0CE430 00047B02 */  srl   $t7, $a0, 0xc
/* 102F64 7F0CE434 31E40FFF */  andi  $a0, $t7, 0xfff
/* 102F68 7F0CE438 0FC32FBA */  jal   texLoadFromTextureNum
/* 102F6C 7F0CE43C AFA40080 */   sw    $a0, 0x80($sp)
/* 102F70 7F0CE440 8FA40080 */  lw    $a0, 0x80($sp)
/* 102F74 7F0CE444 0FC32EC3 */  jal   texFindInPool
/* 102F78 7F0CE448 02C02825 */   move  $a1, $s6
/* 102F7C 7F0CE44C 10400068 */  beqz  $v0, .L7F0CE5F0
/* 102F80 7F0CE450 02002025 */   move  $a0, $s0
/* 102F84 7F0CE454 8E230000 */  lw    $v1, ($s1)
/* 102F88 7F0CE458 8E290004 */  lw    $t1, 4($s1)
/* 102F8C 7F0CE45C AFA20014 */  sw    $v0, 0x14($sp)
/* 102F90 7F0CE460 00033582 */  srl   $a2, $v1, 0x16
/* 102F94 7F0CE464 0009CE02 */  srl   $t9, $t1, 0x18
/* 102F98 7F0CE468 332900FF */  andi  $t1, $t9, 0xff
/* 102F9C 7F0CE46C 00033D02 */  srl   $a3, $v1, 0x14
/* 102FA0 7F0CE470 00034482 */  srl   $t0, $v1, 0x12
/* 102FA4 7F0CE474 00035382 */  srl   $t2, $v1, 0xe
/* 102FA8 7F0CE478 00035A82 */  srl   $t3, $v1, 0xa
/* 102FAC 7F0CE47C 30CD0003 */  andi  $t5, $a2, 3
/* 102FB0 7F0CE480 30EF0003 */  andi  $t7, $a3, 3
/* 102FB4 7F0CE484 310E0003 */  andi  $t6, $t0, 3
/* 102FB8 7F0CE488 3159000F */  andi  $t9, $t2, 0xf
/* 102FBC 7F0CE48C 3178000F */  andi  $t8, $t3, 0xf
/* 102FC0 7F0CE490 01A03025 */  move  $a2, $t5
/* 102FC4 7F0CE494 01E03825 */  move  $a3, $t7
/* 102FC8 7F0CE498 AFB8001C */  sw    $t8, 0x1c($sp)
/* 102FCC 7F0CE49C AFB90018 */  sw    $t9, 0x18($sp)
/* 102FD0 7F0CE4A0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 102FD4 7F0CE4A4 AFA90020 */  sw    $t1, 0x20($sp)
/* 102FD8 7F0CE4A8 0FC337AA */  jal   texHandleType1
/* 102FDC 7F0CE4AC 02402825 */   move  $a1, $s2
/* 102FE0 7F0CE4B0 1000004F */  b     .L7F0CE5F0
/* 102FE4 7F0CE4B4 00408025 */   move  $s0, $v0
.L7F0CE4B8:
/* 102FE8 7F0CE4B8 00033582 */  srl   $a2, $v1, 0x16
/* 102FEC 7F0CE4BC 00033D02 */  srl   $a3, $v1, 0x14
/* 102FF0 7F0CE4C0 00034482 */  srl   $t0, $v1, 0x12
/* 102FF4 7F0CE4C4 30CD0003 */  andi  $t5, $a2, 3
/* 102FF8 7F0CE4C8 30EF0003 */  andi  $t7, $a3, 3
/* 102FFC 7F0CE4CC 310E0003 */  andi  $t6, $t0, 3
/* 103000 7F0CE4D0 01A03025 */  move  $a2, $t5
/* 103004 7F0CE4D4 01E03825 */  move  $a3, $t7
/* 103008 7F0CE4D8 12800024 */  beqz  $s4, .L7F0CE56C
/* 10300C 7F0CE4DC 01C04025 */   move  $t0, $t6
/* 103010 7F0CE4E0 8EB90000 */  lw    $t9, ($s5)
/* 103014 7F0CE4E4 0013C080 */  sll   $t8, $s3, 2
/* 103018 7F0CE4E8 AFAE0010 */  sw    $t6, 0x10($sp)
/* 10301C 7F0CE4EC 03381021 */  addu  $v0, $t9, $t8
/* 103020 7F0CE4F0 904D0001 */  lbu   $t5, 1($v0)
/* 103024 7F0CE4F4 02002025 */  move  $a0, $s0
/* 103028 7F0CE4F8 02402825 */  move  $a1, $s2
/* 10302C 7F0CE4FC 000D7942 */  srl   $t7, $t5, 5
/* 103030 7F0CE500 02EF7023 */  subu  $t6, $s7, $t7
/* 103034 7F0CE504 AFAE0014 */  sw    $t6, 0x14($sp)
/* 103038 7F0CE508 8C590000 */  lw    $t9, ($v0)
/* 10303C 7F0CE50C 0019C2C0 */  sll   $t8, $t9, 0xb
/* 103040 7F0CE510 00186F42 */  srl   $t5, $t8, 0x1d
/* 103044 7F0CE514 02ED7823 */  subu  $t7, $s7, $t5
/* 103048 7F0CE518 AFAF0018 */  sw    $t7, 0x18($sp)
/* 10304C 7F0CE51C 904E0000 */  lbu   $t6, ($v0)
/* 103050 7F0CE520 0FC337EA */  jal   texHandleType0
/* 103054 7F0CE524 AFAE001C */   sw    $t6, 0x1c($sp)
/* 103058 7F0CE528 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 10305C 7F0CE52C 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 103060 7F0CE530 AC590000 */  sw    $t9, ($v0)
/* 103064 7F0CE534 3C0DBA00 */  lui   $t5, (0xBA001001 >> 16) # lui $t5, 0xba00
/* 103068 7F0CE538 3C0EBA00 */  lui   $t6, (0xBA001102 >> 16) # lui $t6, 0xba00
/* 10306C 7F0CE53C 3C180010 */  lui   $t8, 0x10
/* 103070 7F0CE540 35AD1001 */  ori   $t5, (0xBA001001 & 0xFFFF) # ori $t5, $t5, 0x1001
/* 103074 7F0CE544 3C0F0001 */  lui   $t7, 1
/* 103078 7F0CE548 35CE1102 */  ori   $t6, (0xBA001102 & 0xFFFF) # ori $t6, $t6, 0x1102
/* 10307C 7F0CE54C 3C190004 */  lui   $t9, 4
/* 103080 7F0CE550 AC580004 */  sw    $t8, 4($v0)
/* 103084 7F0CE554 AC4F000C */  sw    $t7, 0xc($v0)
/* 103088 7F0CE558 AC4D0008 */  sw    $t5, 8($v0)
/* 10308C 7F0CE55C AC590014 */  sw    $t9, 0x14($v0)
/* 103090 7F0CE560 AC4E0010 */  sw    $t6, 0x10($v0)
/* 103094 7F0CE564 10000022 */  b     .L7F0CE5F0
/* 103098 7F0CE568 24500018 */   addiu $s0, $v0, 0x18
.L7F0CE56C:
/* 10309C 7F0CE56C 02002025 */  move  $a0, $s0
/* 1030A0 7F0CE570 02402825 */  move  $a1, $s2
/* 1030A4 7F0CE574 0FC33786 */  jal   texHandleType2
/* 1030A8 7F0CE578 AFA80010 */   sw    $t0, 0x10($sp)
/* 1030AC 7F0CE57C 1000001C */  b     .L7F0CE5F0
/* 1030B0 7F0CE580 00408025 */   move  $s0, $v0
.L7F0CE584:
/* 1030B4 7F0CE584 00033582 */  srl   $a2, $v1, 0x16
/* 1030B8 7F0CE588 00033D02 */  srl   $a3, $v1, 0x14
/* 1030BC 7F0CE58C 00034482 */  srl   $t0, $v1, 0x12
/* 1030C0 7F0CE590 30D80003 */  andi  $t8, $a2, 3
/* 1030C4 7F0CE594 30ED0003 */  andi  $t5, $a3, 3
/* 1030C8 7F0CE598 310F0003 */  andi  $t7, $t0, 3
/* 1030CC 7F0CE59C 03003025 */  move  $a2, $t8
/* 1030D0 7F0CE5A0 01A03825 */  move  $a3, $t5
/* 1030D4 7F0CE5A4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 1030D8 7F0CE5A8 02002025 */  move  $a0, $s0
/* 1030DC 7F0CE5AC 0FC3382B */  jal   texHandleType3
/* 1030E0 7F0CE5B0 02402825 */   move  $a1, $s2
/* 1030E4 7F0CE5B4 1000000E */  b     .L7F0CE5F0
/* 1030E8 7F0CE5B8 00408025 */   move  $s0, $v0
.L7F0CE5BC:
/* 1030EC 7F0CE5BC 00033582 */  srl   $a2, $v1, 0x16
/* 1030F0 7F0CE5C0 00033D02 */  srl   $a3, $v1, 0x14
/* 1030F4 7F0CE5C4 00034482 */  srl   $t0, $v1, 0x12
/* 1030F8 7F0CE5C8 30CE0003 */  andi  $t6, $a2, 3
/* 1030FC 7F0CE5CC 30F90003 */  andi  $t9, $a3, 3
/* 103100 7F0CE5D0 31180003 */  andi  $t8, $t0, 3
/* 103104 7F0CE5D4 01C03025 */  move  $a2, $t6
/* 103108 7F0CE5D8 03203825 */  move  $a3, $t9
/* 10310C 7F0CE5DC AFB80010 */  sw    $t8, 0x10($sp)
/* 103110 7F0CE5E0 02002025 */  move  $a0, $s0
/* 103114 7F0CE5E4 0FC33819 */  jal   texHandleType4
/* 103118 7F0CE5E8 02402825 */   move  $a1, $s2
/* 10311C 7F0CE5EC 00408025 */  move  $s0, $v0
def_7F0CE2B4:
.L7F0CE5F0:
/* 103120 7F0CE5F0 240105E4 */  li    $at, 1508
/* 103124 7F0CE5F4 16610005 */  bne   $s3, $at, .L7F0CE60C
/* 103128 7F0CE5F8 02002025 */   move  $a0, $s0
/* 10312C 7F0CE5FC 0FC24D0F */  jal   sub_GAME_7F09343C
/* 103130 7F0CE600 24050001 */   li    $a1, 1
/* 103134 7F0CE604 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 103138 7F0CE608 00408025 */   move  $s0, $v0
.L7F0CE60C:
/* 10313C 7F0CE60C 240105E7 */  li    $at, 1511
/* 103140 7F0CE610 16610005 */  bne   $s3, $at, .L7F0CE628
/* 103144 7F0CE614 02002025 */   move  $a0, $s0
/* 103148 7F0CE618 0FC24D97 */  jal   sub_GAME_7F09365C
/* 10314C 7F0CE61C 24050001 */   li    $a1, 1
/* 103150 7F0CE620 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 103154 7F0CE624 00408025 */   move  $s0, $v0
.L7F0CE628:
/* 103158 7F0CE628 0FC2ED8C */  jal   check_if_imageID_is_light
/* 10315C 7F0CE62C 02602025 */   move  $a0, $s3
/* 103160 7F0CE630 10400004 */  beqz  $v0, .L7F0CE644
/* 103164 7F0CE634 02002025 */   move  $a0, $s0
/* 103168 7F0CE638 240D0001 */  li    $t5, 1
/* 10316C 7F0CE63C 0FC2ED67 */  jal   add_entry_to_init_lightfixture_table
/* 103170 7F0CE640 AFAD0058 */   sw    $t5, 0x58($sp)
.L7F0CE644:
/* 103174 7F0CE644 1000003C */  b     .L7F0CE738
/* 103178 7F0CE648 26310008 */   addiu $s1, $s1, 8
/* 10317C 7F0CE64C 8E210000 */  lw    $at, ($s1)
.L7F0CE650:
/* 103180 7F0CE650 241E0001 */  li    $fp, 1
/* 103184 7F0CE654 26100008 */  addiu $s0, $s0, 8
/* 103188 7F0CE658 AE01FFF8 */  sw    $at, -8($s0)
/* 10318C 7F0CE65C 8E390004 */  lw    $t9, 4($s1)
/* 103190 7F0CE660 26310008 */  addiu $s1, $s1, 8
/* 103194 7F0CE664 10000034 */  b     .L7F0CE738
/* 103198 7F0CE668 AE19FFFC */   sw    $t9, -4($s0)
.L7F0CE66C:
/* 10319C 7F0CE66C 24180001 */  li    $t8, 1
/* 1031A0 7F0CE670 AFB8005C */  sw    $t8, 0x5c($sp)
/* 1031A4 7F0CE674 8E210000 */  lw    $at, ($s1)
/* 1031A8 7F0CE678 0000F025 */  move  $fp, $zero
/* 1031AC 7F0CE67C 26100008 */  addiu $s0, $s0, 8
/* 1031B0 7F0CE680 AE01FFF8 */  sw    $at, -8($s0)
/* 1031B4 7F0CE684 8E2F0004 */  lw    $t7, 4($s1)
/* 1031B8 7F0CE688 26310008 */  addiu $s1, $s1, 8
/* 1031BC 7F0CE68C 1000002A */  b     .L7F0CE738
/* 1031C0 7F0CE690 AE0FFFFC */   sw    $t7, -4($s0)
.L7F0CE694:
/* 1031C4 7F0CE694 AFB0008C */  sw    $s0, 0x8c($sp)
/* 1031C8 7F0CE698 AFA0005C */  sw    $zero, 0x5c($sp)
/* 1031CC 7F0CE69C 8E210000 */  lw    $at, ($s1)
/* 1031D0 7F0CE6A0 26100008 */  addiu $s0, $s0, 8
/* 1031D4 7F0CE6A4 26310008 */  addiu $s1, $s1, 8
/* 1031D8 7F0CE6A8 AE01FFF8 */  sw    $at, -8($s0)
/* 1031DC 7F0CE6AC 8E2EFFFC */  lw    $t6, -4($s1)
/* 1031E0 7F0CE6B0 10000021 */  b     .L7F0CE738
/* 1031E4 7F0CE6B4 AE0EFFFC */   sw    $t6, -4($s0)
.L7F0CE6B8:
/* 1031E8 7F0CE6B8 52800013 */  beql  $s4, $zero, .L7F0CE708
/* 1031EC 7F0CE6BC 8E210000 */   lw    $at, ($s1)
/* 1031F0 7F0CE6C0 82220002 */  lb    $v0, 2($s1)
/* 1031F4 7F0CE6C4 24010011 */  li    $at, 17
/* 1031F8 7F0CE6C8 10410005 */  beq   $v0, $at, .L7F0CE6E0
/* 1031FC 7F0CE6CC 24010014 */   li    $at, 20
/* 103200 7F0CE6D0 10410003 */  beq   $v0, $at, .L7F0CE6E0
/* 103204 7F0CE6D4 24010010 */   li    $at, 16
/* 103208 7F0CE6D8 54410004 */  bnel  $v0, $at, .L7F0CE6EC
/* 10320C 7F0CE6DC 8E210000 */   lw    $at, ($s1)
.L7F0CE6E0:
/* 103210 7F0CE6E0 10000015 */  b     .L7F0CE738
/* 103214 7F0CE6E4 26310008 */   addiu $s1, $s1, 8
/* 103218 7F0CE6E8 8E210000 */  lw    $at, ($s1)
.L7F0CE6EC:
/* 10321C 7F0CE6EC 26100008 */  addiu $s0, $s0, 8
/* 103220 7F0CE6F0 26310008 */  addiu $s1, $s1, 8
/* 103224 7F0CE6F4 AE01FFF8 */  sw    $at, -8($s0)
/* 103228 7F0CE6F8 8E2FFFFC */  lw    $t7, -4($s1)
/* 10322C 7F0CE6FC 1000000E */  b     .L7F0CE738
/* 103230 7F0CE700 AE0FFFFC */   sw    $t7, -4($s0)
/* 103234 7F0CE704 8E210000 */  lw    $at, ($s1)
.L7F0CE708:
/* 103238 7F0CE708 26100008 */  addiu $s0, $s0, 8
/* 10323C 7F0CE70C 26310008 */  addiu $s1, $s1, 8
/* 103240 7F0CE710 AE01FFF8 */  sw    $at, -8($s0)
/* 103244 7F0CE714 8E39FFFC */  lw    $t9, -4($s1)
/* 103248 7F0CE718 10000007 */  b     .L7F0CE738
/* 10324C 7F0CE71C AE19FFFC */   sw    $t9, -4($s0)
.L7F0CE720:
/* 103250 7F0CE720 8E210000 */  lw    $at, ($s1)
.L7F0CE724:
/* 103254 7F0CE724 26100008 */  addiu $s0, $s0, 8
/* 103258 7F0CE728 26310008 */  addiu $s1, $s1, 8
/* 10325C 7F0CE72C AE01FFF8 */  sw    $at, -8($s0)
/* 103260 7F0CE730 8E2DFFFC */  lw    $t5, -4($s1)
/* 103264 7F0CE734 AE0DFFFC */  sw    $t5, -4($s0)
.L7F0CE738:
/* 103268 7F0CE738 8FAF0088 */  lw    $t7, 0x88($sp)
/* 10326C 7F0CE73C 25F8FFFF */  addiu $t8, $t7, -1
/* 103270 7F0CE740 1F00FE94 */  bgtz  $t8, .L7F0CE194
/* 103274 7F0CE744 AFB80088 */   sw    $t8, 0x88($sp)
.L7F0CE748:
/* 103278 7F0CE748 8FB90058 */  lw    $t9, 0x58($sp)
/* 10327C 7F0CE74C 53200004 */  beql  $t9, $zero, .L7F0CE760
/* 103280 7F0CE750 8FAE00A0 */   lw    $t6, 0xa0($sp)
/* 103284 7F0CE754 0FC2ED80 */  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
/* 103288 7F0CE758 02002025 */   move  $a0, $s0
/* 10328C 7F0CE75C 8FAE00A0 */  lw    $t6, 0xa0($sp)
.L7F0CE760:
/* 103290 7F0CE760 8FBF0054 */  lw    $ra, 0x54($sp)
/* 103294 7F0CE764 8FB10034 */  lw    $s1, 0x34($sp)
/* 103298 7F0CE768 020E1023 */  subu  $v0, $s0, $t6
/* 10329C 7F0CE76C 8FB00030 */  lw    $s0, 0x30($sp)
/* 1032A0 7F0CE770 8FB20038 */  lw    $s2, 0x38($sp)
/* 1032A4 7F0CE774 8FB3003C */  lw    $s3, 0x3c($sp)
/* 1032A8 7F0CE778 8FB40040 */  lw    $s4, 0x40($sp)
/* 1032AC 7F0CE77C 8FB50044 */  lw    $s5, 0x44($sp)
/* 1032B0 7F0CE780 8FB60048 */  lw    $s6, 0x48($sp)
/* 1032B4 7F0CE784 8FB7004C */  lw    $s7, 0x4c($sp)
/* 1032B8 7F0CE788 8FBE0050 */  lw    $fp, 0x50($sp)
/* 1032BC 7F0CE78C 03E00008 */  jr    $ra
/* 1032C0 7F0CE790 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif


/***
 * NTSC address 0x7F0CE794.
*/
void texCopyGdls(Gfx *arg0, Gfx *arg1, s32 arg2)
{
    arg2 = (arg2 >> 3);
    arg0 = arg0 + (arg2 - 1);
    arg1 = arg1 + (arg2 - 1);

    while (arg2--)
    {
        arg1->force_structure_alignment = arg0->force_structure_alignment;
        arg1--;
        arg0--;
    }
}
