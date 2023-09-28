#include <ultra64.h>




s32 is_less_than_certain_power_of_2(int number)

{
  if (number < 2) {
    return 0;
  }
  if (number < 3) {
    return 1;
  }
  if (number < 5) {
    return 2;
  }
  if (number < 9) {
    return 3;
  }
  if (number < 0x11) {
    return 4;
  }
  if (number < 0x21) {
    return 5;
  }
  if (number < 0x41) {
    return 6;
  }
  if (number < 0x81) {
    return 7;
  }
  return 8;
}


s32 ceil8000(s32 arg0)
{
    f32 temp_f0;
    s32 temp_f10;

    temp_f0 = 32768.0f / ((((s32) (arg0 + 15)) / 16) * 16);
    temp_f10 = temp_f0;

    return (temp_f10 & 0xFFFFFFFF)
         + ((s32) ((temp_f0 - temp_f10) + 0.999999f));
}


s32 ceil4000(s32 arg0)
{
    f32 temp_f0;
    s32 temp_f10;

    temp_f0 = 16384.0f / ((((s32) (arg0 + 7)) / 8) * 8);
    temp_f10 = temp_f0;

    return (temp_f10 & 0xFFFFFFFF)
         + ((s32) ((temp_f0 - temp_f10) + 0.999999f));
}


s32 ceil2000(s32 arg0)
{
    f32 temp_f0;
    s32 temp_f10;

    temp_f0 = 8192.0f / ((((s32) (arg0 + 3)) / 4) * 4);
    temp_f10 = temp_f0;

    return (temp_f10 & 0xFFFFFFFF)
         + ((s32) ((temp_f0 - temp_f10) + 0.999999f));
}


s32 ceil1000(s32 arg0)
{
    f32 temp_f0;
    s32 temp_f10;

    temp_f0 = 4096.0f / ((((s32) (arg0 + 3)) / 4) * 4);
    temp_f10 = temp_f0;

    return (temp_f10 & 0xFFFFFFFF)
         + ((s32) ((temp_f0 - temp_f10) + 0.999999f));
}


s32 sub_GAME_7F0767D8(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    ret = 0;

    if (arg2 <= 0) { arg2 = 1; }

    while (arg2 > 0)
    {
        ret += ((arg0 + 15) / 16) * 4 * arg1;
        arg2--;
        if (arg0 >= 2) { arg0 >>= 1; }
        if (arg1 >= 2) { arg1 >>= 1; }
    }
    return ret;
}


s32 sub_GAME_7F076848(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    ret = 0;

    if (arg2 <= 0) { arg2 = 1; }

    while (arg2 > 0)
    {
        ret += ((arg0 + 7) / 8) * 4 * arg1;
        arg2--;
        if (arg0 >= 2) { arg0 >>= 1; }
        if (arg1 >= 2) { arg1 >>= 1; }
    }
    return ret;
}


s32 sub_GAME_7F0768B8(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    ret = 0;

    if (arg2 <= 0) { arg2 = 1; }

    while (arg2 > 0)
    {
        ret += ((arg0 + 3) / 4) * 4 * arg1;
        arg2--;
        if (arg0 >= 2) { arg0 >>= 1; }
        if (arg1 >= 2) { arg1 >>= 1; }
    }
    return ret;
}


s32 sub_GAME_7F076928(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    ret = 0;

    if (arg2 <= 0) { arg2 = 1; }

    while (arg2 > 0)
    {
        ret += ((arg0 + 3) / 4) * 4 * arg1;
        arg2--;
        if (arg0 >= 2) { arg0 >>= 1; }
        if (arg1 >= 2) { arg1 >>= 1; }
    }
    return ret;
}


void texSetRenderMode(Gfx **gdlptr, s32 arg1, s32 numcycles, s32 arg3)
{
    Gfx *gdl = *gdlptr;

    if (numcycles == 1)
    {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);

        switch (arg1)
        {
            default:
            case 1:
                if (arg3)
                {
                    if (arg3 >= 2)
                    {
                        gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_DECAL, G_RM_AA_ZB_OPA_DECAL2);
                    }
                    else
                    {
                        gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
                    }
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
                }
                break;

            case 2:
                if (arg3)
                {
                    if (arg3 >= 2)
                    {
                        gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2);
                    }
                    else
                    {
                        gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                    }
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
                }
                break;

            case 3:
                if (arg3)
                {
                    gDPSetRenderMode(gdl++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                }
                break;

            case 4:
                if (arg3)
                {
                    gDPSetRenderMode(gdl++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                }
                break;
        }
    }
    else
    {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_2CYCLE);

        switch (arg1)
        {
            default:
            case 1:
                if (arg3)
                {
                    if (arg3 >= 2)
                    {
                        gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2);
                    }
                    else
                    {
                        gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
                    }
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_OPA_SURF2);
                }
                break;

            case 2:
                if (arg3)
                {
                    if (arg3 >= 2)
                    {
                        gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2);
                    }
                    else
                    {
                        gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
                    }
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_XLU_SURF2);
                }
                break;

            case 3:
                if (arg3)
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2);
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_TEX_EDGE2);
                }
                break;

            case 4:
                if (arg3)
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
                }
                else
                {
                    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_CLD_SURF2);
                }
                break;
        }
    }

    *gdlptr = gdl;
}


#ifdef NONMATCHING

// First pass mips2c output (initial guess at variables, everything compiles).
// Display list commands are probably correct, but almost every single one has wrong arguments.
// https://decomp.me/scratch/Q6Ss8 28%
void likely_generate_DL_for_image_declaration(Gfx **arg0, sImageTableEntry *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Gfx *sp16C;
    u32 sp144;
    s32 sp140;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    s32 spD0;
    s32 spCC;
    s32 spCA;
    s32 spC4;
    s32 spC0;
    s32 spBC;

    struct tex *temp_s6;
    
    u8 var_s1;
    u8 var_s2;
    s32 var_s3;
    u8 var_s4;
    u8 var_s5;
    s32 var_a2;
    s32 var_v0;
    s32 var_s0;

    sp16C = *arg0;

    if (arg1 == NULL)
    {
        texSetRenderMode(&sp16C, arg2, 1, arg3);

        if (arg3 >= 2)
        {
            gSPTexture(sp16C++, 0xffff, 0xffff, arg3, G_TX_RENDERTILE, G_ON);
        }
        else
        {
            gSPTexture(sp16C++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
        }

        gDPSetCombineMode(sp16C++, G_CC_SHADE, G_CC_SHADE);
    }
    else
    {
        var_s5 = arg1->width;
        var_s4 = arg1->height;
        
        if ((u32) arg1->index < 0xBB9U)
        {
            texLoad((s32 *) arg1, NULL);
        }

        temp_s6 = texFindInPool((s32) (arg1->index | 0x80000000) - 8, NULL);

        if (arg1->level == 0)
        {
            if (temp_s6 != NULL)
            {
                var_s1 = temp_s6->gbiformat;
                var_s2 = temp_s6->depth;
                sp144 = temp_s6->next;
            }
            else
            {
                var_s1 = arg1->format;
                var_s2 = arg1->depth;
            }

            switch (var_s2)
            {
                default:                                /* switch 1 */
                    var_s3 = sp13C;
                    break;
                case 3:                                 /* switch 1 */
                    sp140 = 3;
                    var_s3 = sub_GAME_7F076928((s32) var_s5, (s32) var_s4, 1) - 1;
                    sp138 = ceil1000((s32) var_s5);
                    sp134 = (s32) (var_s5 + 3) >> 2;
                    break;
                case 2:                                 /* switch 1 */
                    sp140 = 2;
                    var_s3 = sub_GAME_7F0768B8((s32) var_s5, (s32) var_s4, 1) - 1;
                    sp138 = ceil2000((s32) var_s5);
                    sp134 = (s32) (var_s5 + 3) >> 2;
                    break;
                case 1:                                 /* switch 1 */
                    sp140 = 2;
                    var_s3 = sub_GAME_7F076848((s32) var_s5, (s32) var_s4, 1) - 1;
                    sp138 = ceil4000((s32) var_s5);
                    sp134 = (s32) (var_s5 + 7) >> 3;
                    break;
                case 0:                                 /* switch 1 */
                    sp140 = 2;
                    var_s3 = sub_GAME_7F0767D8((s32) var_s5, (s32) var_s4, 1) - 1;
                    sp138 = ceil8000((s32) var_s5);
                    sp134 = (s32) (var_s5 + 0xF) >> 4;
                    break;
            }

            texSetRenderMode(&sp16C, arg2, 1, arg3);

            if (arg3 >= 2)
            {
                gSPTexture(sp16C++, 0xffff, 0xffff, arg3, G_TX_RENDERTILE, G_ON);
            }
            else
            {
                gSPTexture(sp16C++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
            }
    
            gSPTexture(sp16C++, 0, 0, 2, G_TX_RENDERTILE, G_ON);

            // line 206
            switch (var_s1)
            {
                case 0:
                    gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                break;

                case 3:
                    gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                break;

                case 4:
                    gDPSetCombineLERP(sp16C++, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, COMBINED, 0, COMBINED, 0, SHADE);
                break;

                case 2:
                    switch (sp144)
                    {
                        case 0x8000:
                            gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                        break;

                        case 0xc000:
                            gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                        break;
                    }
                break;
            }

            // line 264
            // temp_v0_4->words.w0 = (var_s1 & 7) << 0x15 | 0xFD000000 | (sp140 & 3) << 0x13;
            // temp_v0_4->words.w1 = arg1->index;
            gDPSetTextureImage(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 1, arg1->index);

            // temp_a1->words.w0 = (var_s1 & 7) << 0x15 | 0xF5000000 | (sp140 & 3) << 0x13;
            // temp_a1->words.w1 = ((arg1->flagsT & 3) << 0x12) | 0x07000000U | ((arg1->flagsS & 3) << 8);
            gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

            gDPLoadSync(sp16C++);

            //if (var_s3 < 0x7FF)
            //{
            //    var_a3 = var_s3;
            //}

            // temp_t0->words.w0 = 0xF3000000;
            // temp_t0->words.w1 = ((var_a3 & 0xFFF) << 0xC) | 0x07000000U | (sp138 & 0xFFF);
            gDPLoadBlock(sp16C++, G_TX_LOADTILE, 0, 0, 0, 0);

            gDPPipeSync(sp16C++);

            if (var_s1 == 2)
            {
                gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(sp16C++);

                // temp_a0_2->words.w0 = ((temp_a2 & 0x3FF) << 0xE) | 0xF0000000 | temp_t6_3;
                // temp_a0_2->words.w1 = (((temp_s6->unk0a + temp_a2) & 0x3FF) << 0xE) | 0x07000000U | temp_t6_3;
                gDPLoadTLUTCmd(sp16C++, G_TX_LOADTILE, 0);
                gDPPipeSync(sp16C++);

                // temp_t8_8->words.w0 = 0xBA000E02;
                // temp_t8_8->words.w1 = sp144;
                gDPSetTextureLUT(sp16C++, sp144);
            }
            else
            {
                gDPSetTextureLUT(sp16C++, G_TT_NONE);
            }

            // temp_s0->words.w0 = (var_s1 & 7) << 0x15 | 0xF5000000 | ((var_s2 & 3) << 0x13) | ((sp134 & 0x1FF) << 9);
            // temp_s0->words.w1 = ((is_less_than_certain_power_of_2((s32) var_s5) & 0xF) * 0x10) | ((arg1->flagsT & 3) << 0x12) | ((sp58 & 0xF) << 0xE) | ((arg1->flagsS & 3) << 8);
            gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

            // temp_v1_2->words.w0 = (temp_a0_3 << 0xC) | 0xF2000000 | temp_a0_3;
            // temp_v1_2->words.w1 = (((((var_s5 - 1) * 4) + arg4) & 0xFFF) << 0xC) | ((((var_s4 - 1) * 4) + arg4) & 0xFFF);
            gDPSetTileSize(sp16C++, G_TX_RENDERTILE, 0, 0, 0, 0);
        }
        else
        {
            spD0 = 0;
            spCC = (s32) arg1->level;

            if (temp_s6 != NULL)
            {
                var_s1 = temp_s6->gbiformat;
                var_s2 = temp_s6->depth;
                spCA = temp_s6->maxlod;
            }
            else
            {
                var_s1 = arg1->format;
                var_s2 = spC4;
                spCA = arg1->depth;
            }

            // line 362
            if ((temp_s6 != NULL) && (temp_s6->next & 0x20000000))
            {
                sub_GAME_7F0CC9D4(temp_s6, &spC0, &spBC);
            }
            else if (spCA == 0)
            {
                spC0 = 2;
                spBC = sub_GAME_7F0767D8((s32) var_s5, (s32) var_s4, spCC) - 1;
            }
            else if (spCA == 1)
            {
                spC0 = 2;
                spBC = sub_GAME_7F076848((s32) var_s5, (s32) var_s4, spCC) - 1;
            }
            else if (spCA == 2)
            {
                spC0 = 2;
                spBC = sub_GAME_7F0768B8((s32) var_s5, (s32) var_s4, spCC) - 1;
            }
            else if (spCA == 3)
            {
                spC0 = 3;
                spBC = sub_GAME_7F076928((s32) var_s5, (s32) var_s4, spCC) - 1;
            }

            texSetRenderMode(&sp16C, arg2, 2, arg3);

            // line 400
            if (arg3 >= 2)
            {
                gSPTexture(sp16C++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF);
            }
            else
            {
                gSPTexture(sp16C++, 0xffff, 0xffff, 1, G_TX_RENDERTILE, G_OFF);
            }

            // line 417
            switch (var_s1)
            {
                case 0:
                    gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                break;

                case 3:
                    gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                break;

                case 4:
                    gDPSetCombineLERP(sp16C++, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, COMBINED, 0, COMBINED, 0, SHADE);
                break;

                case 2:
                    switch (var_s2)
                    {
                        case 0x8000:
                            gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                        break;

                        case 0xc000:
                            gDPSetCombineMode(sp16C++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                        break;
                    }
                break;
            }

            // line 478
            // temp_v0_8->words.w0 = (var_s1_2 & 7) << 0x15 | 0xFD000000 | ((spC0 & 3) << 0x13);
            // temp_v0_8->words.w1 = arg1->index;
            gDPSetTextureImage(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 1, arg1->index);

            // temp_a0_4->words.w0 = (var_s1_2 & 7) << 0x15 | 0xF5000000 | ((spC0 & 3) << 0x13);
            // temp_a0_4->words.w1 = 0x07000000;
            gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

            gDPLoadSync(sp16C++);

            // line 496
            // if (spBC < 0x7FF)
            // {
            //     var_a3_2 = spBC;
            // }

            // temp_a2_2->words.w0 = 0xF3000000;
            // temp_a2_2->words.w1 = ((var_a3_2 & 0xFFF) << 0xC) | 0x07000000U;
            gDPLoadBlock(sp16C++, G_TX_LOADTILE, 0, 0, 0, 0);

            gDPPipeSync(sp16C++);

            // line 505
            if (var_s1 == 2)
            {
                gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(sp16C++);

                // temp_a2_4 = temp_a2_3 - var_a3_3;
                
                // temp_a0_5->words.w0 = ((temp_a2_4 & 0x3FF) << 0xE) | 0xF0000000 | (var_a3_3 & 0x3FF) * 4;
                // temp_a0_5->words.w1 = (((temp_s6->unk0a + temp_a2_4) & 0x3FF) << 0xE) | 0x07000000U | (var_a3_3 & 0x3FF) * 4;
                gDPLoadTLUTCmd(sp16C++, G_TX_LOADTILE, 0);
                gDPPipeSync(sp16C++);

                // temp_t9_4->words.w0 = 0xBA000E02;
                // temp_t9_4->words.w1 = var_s2_2;
                gDPSetTextureLUT(sp16C++, var_s2);
            }
            else
            {
                gDPSetTextureLUT(sp16C++, G_TT_NONE);
            }

            for (var_s1 = 0; var_s1 < spCC; var_s1++)
            {
                if (var_s1 > 0)
                {
                    if ((temp_s6 != NULL) && (temp_s6->next & 0x20000000))
                        {
                            var_s5 = texGetWidthAtLod(temp_s6, var_s1);
                            var_s4 = texGetHeightAtLod(temp_s6, var_s1);
                        }
                        else
                        {
                            if ((s32) var_s5 >= 2)
                            {
                                var_s5 = (u8) ((s32) var_s5 >> 1);
                            }
                            
                            if ((s32) var_s4 >= 2)
                            {
                                var_s4 = (u8) ((s32) var_s4 >> 1);
                            }
                        }
                }

                switch (spCA)
                {
                    default:
                        var_v0 = ((var_s0 & 0x1FF) << 9);
                        var_a2 = var_s0 * var_s4;
                        break;
                    case 3:
                        var_s0 = (s32) (var_s5 + 3) / 4;
                        var_v0 = ((var_s0 & 0x1FF) << 9);
                        var_a2 = var_s0 * var_s4;
                        break;
                    case 2:
                        var_s0 = (s32) (var_s5 + 3) / 4;
                        var_v0 = ((var_s0 & 0x1FF) << 9);
                        var_a2 = var_s0 * var_s4;
                        break;
                    case 1:
                        var_s0 = (s32) (var_s5 + 7) / 8;
                        var_v0 = ((var_s0 & 0x1FF) << 9);
                        var_a2 = var_s0 * var_s4;
                        break;
                    case 0:
                        var_s0 = (s32) (var_s5 + 0xF) / 16;
                        var_v0 = ((var_s0 & 0x1FF) << 9);
                        var_a2 = var_s0 * var_s4;
                        break;
                }
                
                gDPSetTile(sp16C++, G_IM_FMT_RGBA, G_IM_SIZ_4b, is_less_than_certain_power_of_2(var_s5), 0x0000, G_TX_RENDERTILE, var_v0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(sp16C++, G_TX_RENDERTILE, 0, arg4, var_s5 - 1, var_s4 - 1);

                spD0 += var_a2;
            }
        }
        
    }

    *arg0 = sp16C;
}
#else
GLOBAL_ASM(
.text
glabel likely_generate_DL_for_image_declaration
/* 0AB898 7F076D68 27BDFE90 */  addiu $sp, $sp, -0x170
/* 0AB89C 7F076D6C AFBF0034 */  sw    $ra, 0x34($sp)
/* 0AB8A0 7F076D70 AFB70030 */  sw    $s7, 0x30($sp)
/* 0AB8A4 7F076D74 AFB6002C */  sw    $s6, 0x2c($sp)
/* 0AB8A8 7F076D78 AFB50028 */  sw    $s5, 0x28($sp)
/* 0AB8AC 7F076D7C AFB40024 */  sw    $s4, 0x24($sp)
/* 0AB8B0 7F076D80 AFB30020 */  sw    $s3, 0x20($sp)
/* 0AB8B4 7F076D84 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0AB8B8 7F076D88 AFB10018 */  sw    $s1, 0x18($sp)
/* 0AB8BC 7F076D8C AFB00014 */  sw    $s0, 0x14($sp)
/* 0AB8C0 7F076D90 AFA40170 */  sw    $a0, 0x170($sp)
/* 0AB8C4 7F076D94 AFA60178 */  sw    $a2, 0x178($sp)
/* 0AB8C8 7F076D98 8C8F0000 */  lw    $t7, ($a0)
/* 0AB8CC 7F076D9C 00E08025 */  move  $s0, $a3
/* 0AB8D0 7F076DA0 00A0B825 */  move  $s7, $a1
/* 0AB8D4 7F076DA4 14A00025 */  bnez  $a1, .L7F076E3C
/* 0AB8D8 7F076DA8 AFAF016C */   sw    $t7, 0x16c($sp)
/* 0AB8DC 7F076DAC 00C02825 */  move  $a1, $a2
/* 0AB8E0 7F076DB0 24060001 */  li    $a2, 1
/* 0AB8E4 7F076DB4 0FC1DA66 */  jal   texSetRenderMode
/* 0AB8E8 7F076DB8 27A4016C */   addiu $a0, $sp, 0x16c
/* 0AB8EC 7F076DBC 2A010002 */  slti  $at, $s0, 2
/* 0AB8F0 7F076DC0 1420000D */  bnez  $at, .L7F076DF8
/* 0AB8F4 7F076DC4 8FAF016C */   lw    $t7, 0x16c($sp)
/* 0AB8F8 7F076DC8 8FA2016C */  lw    $v0, 0x16c($sp)
/* 0AB8FC 7F076DCC 320E00FF */  andi  $t6, $s0, 0xff
/* 0AB900 7F076DD0 000E7C00 */  sll   $t7, $t6, 0x10
/* 0AB904 7F076DD4 3C01BB00 */  lui   $at, 0xbb00
/* 0AB908 7F076DD8 24590008 */  addiu $t9, $v0, 8
/* 0AB90C 7F076DDC AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AB910 7F076DE0 01E1C025 */  or    $t8, $t7, $at
/* 0AB914 7F076DE4 37190001 */  ori   $t9, $t8, 1
/* 0AB918 7F076DE8 240EFFFF */  li    $t6, -1
/* 0AB91C 7F076DEC AC4E0004 */  sw    $t6, 4($v0)
/* 0AB920 7F076DF0 10000008 */  b     .L7F076E14
/* 0AB924 7F076DF4 AC590000 */   sw    $t9, ($v0)
.L7F076DF8:
/* 0AB928 7F076DF8 25F80008 */  addiu $t8, $t7, 8
/* 0AB92C 7F076DFC AFB8016C */  sw    $t8, 0x16c($sp)
/* 0AB930 7F076E00 3C19BB00 */  lui   $t9, (0xBB000001 >> 16) # lui $t9, 0xbb00     #
/* 0AB934 7F076E04 37390001 */  ori   $t9, (0xBB000001 & 0xFFFF) # ori $t9, $t9, 1  #
/* 0AB938 7F076E08 240EFFFF */  li    $t6, -1
/* 0AB93C 7F076E0C ADEE0004 */  sw    $t6, 4($t7)                                   # As with above gbi, I forgot to include *dl since I dont know where it is saving the Gfx array (*dl)
/* 0AB940 7F076E10 ADF90000 */  sw    $t9, ($t7)                                    #gSPTexture(*dl, 0xFFFF, 0xFFFF, 1, 0, G_ON) #use FFFF since 1.0 cannot be represented directly
.L7F076E14:
/* 0AB944 7F076E14 8FAF016C */  lw    $t7, 0x16c($sp)
/* 0AB948 7F076E18 3C19FCFF */  lui   $t9, (0xFCFFFFFF >> 16) # lui $t9, 0xfcff         #
/* 0AB94C 7F076E1C 3C0EFFFE */  lui   $t6, (0xFFFE793C >> 16) # lui $t6, 0xfffe         #FCFFFFFFFFFE793C
/* 0AB950 7F076E20 25F80008 */  addiu $t8, $t7, 8
/* 0AB954 7F076E24 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0AB958 7F076E28 35CE793C */  ori   $t6, (0xFFFE793C & 0xFFFF) # ori $t6, $t6, 0x793c #
/* 0AB95C 7F076E2C 3739FFFF */  ori   $t9, (0xFCFFFFFF & 0xFFFF) # ori $t9, $t9, 0xffff #
/* 0AB960 7F076E30 ADF90000 */  sw    $t9, ($t7)                                        #
/* 0AB964 7F076E34 10000352 */  b     .L7F077B80
/* 0AB968 7F076E38 ADEE0004 */   sw    $t6, 4($t7)                                      #gDPSetCombineMode()
.L7F076E3C:
/* 0AB96C 7F076E3C 8EE20000 */  lw    $v0, ($s7)
/* 0AB970 7F076E40 92F50004 */  lbu   $s5, 4($s7)
/* 0AB974 7F076E44 92F40005 */  lbu   $s4, 5($s7)
/* 0AB978 7F076E48 2C410BB9 */  sltiu $at, $v0, 0xbb9
/* 0AB97C 7F076E4C 10200004 */  beqz  $at, .L7F076E60
/* 0AB980 7F076E50 02E02025 */   move  $a0, $s7
/* 0AB984 7F076E54 0FC32F06 */  jal   texLoad
/* 0AB988 7F076E58 00002825 */   move  $a1, $zero
/* 0AB98C 7F076E5C 8EE20000 */  lw    $v0, ($s7)
.L7F076E60:
/* 0AB990 7F076E60 3C018000 */  lui   $at, 0x8000
/* 0AB994 7F076E64 00411825 */  or    $v1, $v0, $at
/* 0AB998 7F076E68 9464FFF8 */  lhu   $a0, -8($v1)
/* 0AB99C 7F076E6C 0FC32EC3 */  jal   texFindInPool
/* 0AB9A0 7F076E70 00002825 */   move  $a1, $zero
/* 0AB9A4 7F076E74 92E30006 */  lbu   $v1, 6($s7)
/* 0AB9A8 7F076E78 0040B025 */  move  $s6, $v0
/* 0AB9AC 7F076E7C 54600167 */  bnezl $v1, .L7F07741C
/* 0AB9B0 7F076E80 AFA000D0 */   sw    $zero, 0xd0($sp)
/* 0AB9B4 7F076E84 5040000D */  beql  $v0, $zero, .L7F076EBC
/* 0AB9B8 7F076E88 92F10007 */   lbu   $s1, 7($s7)
/* 0AB9BC 7F076E8C 8C520008 */  lw    $s2, 8($v0)
/* 0AB9C0 7F076E90 8C4E000C */  lw    $t6, 0xc($v0)
/* 0AB9C4 7F076E94 00128EC0 */  sll   $s1, $s2, 0x1b
/* 0AB9C8 7F076E98 00117F42 */  srl   $t7, $s1, 0x1d
/* 0AB9CC 7F076E9C 31F100FF */  andi  $s1, $t7, 0xff
/* 0AB9D0 7F076EA0 000E7F82 */  srl   $t7, $t6, 0x1e
/* 0AB9D4 7F076EA4 000FC380 */  sll   $t8, $t7, 0xe
/* 0AB9D8 7F076EA8 32590003 */  andi  $t9, $s2, 3
/* 0AB9DC 7F076EAC 03209025 */  move  $s2, $t9
/* 0AB9E0 7F076EB0 10000003 */  b     .L7F076EC0
/* 0AB9E4 7F076EB4 AFB80144 */   sw    $t8, 0x144($sp)
/* 0AB9E8 7F076EB8 92F10007 */  lbu   $s1, 7($s7)
.L7F076EBC:
/* 0AB9EC 7F076EBC 92F20008 */  lbu   $s2, 8($s7)
.L7F076EC0:
/* 0AB9F0 7F076EC0 12400033 */  beqz  $s2, .L7F076F90
/* 0AB9F4 7F076EC4 02401025 */   move  $v0, $s2
/* 0AB9F8 7F076EC8 24010001 */  li    $at, 1
/* 0AB9FC 7F076ECC 10410023 */  beq   $v0, $at, .L7F076F5C
/* 0ABA00 7F076ED0 240F0002 */   li    $t7, 2
/* 0ABA04 7F076ED4 24010002 */  li    $at, 2
/* 0ABA08 7F076ED8 10410013 */  beq   $v0, $at, .L7F076F28
/* 0ABA0C 7F076EDC 24180002 */   li    $t8, 2
/* 0ABA10 7F076EE0 24010003 */  li    $at, 3
/* 0ABA14 7F076EE4 10410003 */  beq   $v0, $at, .L7F076EF4
/* 0ABA18 7F076EE8 24190003 */   li    $t9, 3
/* 0ABA1C 7F076EEC 10000035 */  b     .L7F076FC4
/* 0ABA20 7F076EF0 8FB3013C */   lw    $s3, 0x13c($sp)
.L7F076EF4:
/* 0ABA24 7F076EF4 AFB90140 */  sw    $t9, 0x140($sp)
/* 0ABA28 7F076EF8 02A02025 */  move  $a0, $s5
/* 0ABA2C 7F076EFC 02802825 */  move  $a1, $s4
/* 0ABA30 7F076F00 0FC1DA4A */  jal   sub_GAME_7F076928
/* 0ABA34 7F076F04 24060001 */   li    $a2, 1
/* 0ABA38 7F076F08 2453FFFF */  addiu $s3, $v0, -1
/* 0ABA3C 7F076F0C 0FC1D9DD */  jal   ceil1000
/* 0ABA40 7F076F10 02A02025 */   move  $a0, $s5
/* 0ABA44 7F076F14 26AE0003 */  addiu $t6, $s5, 3
/* 0ABA48 7F076F18 000E7883 */  sra   $t7, $t6, 2
/* 0ABA4C 7F076F1C AFA20138 */  sw    $v0, 0x138($sp)
/* 0ABA50 7F076F20 10000028 */  b     .L7F076FC4
/* 0ABA54 7F076F24 AFAF0134 */   sw    $t7, 0x134($sp)
.L7F076F28:
/* 0ABA58 7F076F28 AFB80140 */  sw    $t8, 0x140($sp)
/* 0ABA5C 7F076F2C 02A02025 */  move  $a0, $s5
/* 0ABA60 7F076F30 02802825 */  move  $a1, $s4
/* 0ABA64 7F076F34 0FC1DA2E */  jal   sub_GAME_7F0768B8
/* 0ABA68 7F076F38 24060001 */   li    $a2, 1
/* 0ABA6C 7F076F3C 2453FFFF */  addiu $s3, $v0, -1
/* 0ABA70 7F076F40 0FC1D9C4 */  jal   ceil2000
/* 0ABA74 7F076F44 02A02025 */   move  $a0, $s5
/* 0ABA78 7F076F48 26B90003 */  addiu $t9, $s5, 3
/* 0ABA7C 7F076F4C 00197083 */  sra   $t6, $t9, 2
/* 0ABA80 7F076F50 AFA20138 */  sw    $v0, 0x138($sp)
/* 0ABA84 7F076F54 1000001B */  b     .L7F076FC4
/* 0ABA88 7F076F58 AFAE0134 */   sw    $t6, 0x134($sp)
.L7F076F5C:
/* 0ABA8C 7F076F5C AFAF0140 */  sw    $t7, 0x140($sp)
/* 0ABA90 7F076F60 02A02025 */  move  $a0, $s5
/* 0ABA94 7F076F64 02802825 */  move  $a1, $s4
/* 0ABA98 7F076F68 0FC1DA12 */  jal   sub_GAME_7F076848
/* 0ABA9C 7F076F6C 24060001 */   li    $a2, 1
/* 0ABAA0 7F076F70 2453FFFF */  addiu $s3, $v0, -1
/* 0ABAA4 7F076F74 0FC1D9AB */  jal   ceil4000
/* 0ABAA8 7F076F78 02A02025 */   move  $a0, $s5
/* 0ABAAC 7F076F7C 26B80007 */  addiu $t8, $s5, 7
/* 0ABAB0 7F076F80 0018C8C3 */  sra   $t9, $t8, 3
/* 0ABAB4 7F076F84 AFA20138 */  sw    $v0, 0x138($sp)
/* 0ABAB8 7F076F88 1000000E */  b     .L7F076FC4
/* 0ABABC 7F076F8C AFB90134 */   sw    $t9, 0x134($sp)
.L7F076F90:
/* 0ABAC0 7F076F90 240E0002 */  li    $t6, 2
/* 0ABAC4 7F076F94 AFAE0140 */  sw    $t6, 0x140($sp)
/* 0ABAC8 7F076F98 02A02025 */  move  $a0, $s5
/* 0ABACC 7F076F9C 02802825 */  move  $a1, $s4
/* 0ABAD0 7F076FA0 0FC1D9F6 */  jal   sub_GAME_7F0767D8
/* 0ABAD4 7F076FA4 24060001 */   li    $a2, 1
/* 0ABAD8 7F076FA8 2453FFFF */  addiu $s3, $v0, -1
/* 0ABADC 7F076FAC 0FC1D992 */  jal   ceil8000
/* 0ABAE0 7F076FB0 02A02025 */   move  $a0, $s5
/* 0ABAE4 7F076FB4 26AF000F */  addiu $t7, $s5, 0xf
/* 0ABAE8 7F076FB8 000FC103 */  sra   $t8, $t7, 4
/* 0ABAEC 7F076FBC AFA20138 */  sw    $v0, 0x138($sp)
/* 0ABAF0 7F076FC0 AFB80134 */  sw    $t8, 0x134($sp)
.L7F076FC4:
/* 0ABAF4 7F076FC4 27A4016C */  addiu $a0, $sp, 0x16c
/* 0ABAF8 7F076FC8 8FA50178 */  lw    $a1, 0x178($sp)
/* 0ABAFC 7F076FCC 24060001 */  li    $a2, 1
/* 0ABB00 7F076FD0 0FC1DA66 */  jal   texSetRenderMode
/* 0ABB04 7F076FD4 02003825 */   move  $a3, $s0
/* 0ABB08 7F076FD8 2A010002 */  slti  $at, $s0, 2
/* 0ABB0C 7F076FDC 1420000D */  bnez  $at, .L7F077014
/* 0ABB10 7F076FE0 02204825 */   move  $t1, $s1
/* 0ABB14 7F076FE4 8FA2016C */  lw    $v0, 0x16c($sp)
/* 0ABB18 7F076FE8 320F00FF */  andi  $t7, $s0, 0xff
/* 0ABB1C 7F076FEC 000FC400 */  sll   $t8, $t7, 0x10
/* 0ABB20 7F076FF0 3C01BB00 */  lui   $at, 0xbb00
/* 0ABB24 7F076FF4 244E0008 */  addiu $t6, $v0, 8
/* 0ABB28 7F076FF8 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0ABB2C 7F076FFC 0301C825 */  or    $t9, $t8, $at
/* 0ABB30 7F077000 372E0001 */  ori   $t6, $t9, 1
/* 0ABB34 7F077004 240FFFFF */  li    $t7, -1
/* 0ABB38 7F077008 AC4F0004 */  sw    $t7, 4($v0)
/* 0ABB3C 7F07700C 10000009 */  b     .L7F077034
/* 0ABB40 7F077010 AC4E0000 */   sw    $t6, ($v0)
.L7F077014:
/* 0ABB44 7F077014 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABB48 7F077018 3C0EBB00 */  lui   $t6, (0xBB000001 >> 16) # lui $t6, 0xbb00     #
/* 0ABB4C 7F07701C 35CE0001 */  ori   $t6, (0xBB000001 & 0xFFFF) # ori $t6, $t6, 1  #
/* 0ABB50 7F077020 27190008 */  addiu $t9, $t8, 8
/* 0ABB54 7F077024 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABB58 7F077028 240FFFFF */  li    $t7, -1                                       #
/* 0ABB5C 7F07702C AF0F0004 */  sw    $t7, 4($t8)                                   #
/* 0ABB60 7F077030 AF0E0000 */  sw    $t6, ($t8)                                    #gSPTexture(*dl, 0xFFFF, 0xFFFF, 1, 0, G_ON) #use FFFF since 1.0 cannot be represented directly
.L7F077034:
/* 0ABB64 7F077034 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABB68 7F077038 3C0EBA00 */  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00         #
/* 0ABB6C 7F07703C 35CE1001 */  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001 #
/* 0ABB70 7F077040 27190008 */  addiu $t9, $t8, 8
/* 0ABB74 7F077044 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABB78 7F077048 AF000004 */  sw    $zero, 4($t8)
/* 0ABB7C 7F07704C 1220000C */  beqz  $s1, .L7F077080
/* 0ABB80 7F077050 AF0E0000 */   sw    $t6, ($t8)                                       #gDPSetTextureLOD(G_TL_TILE)
/* 0ABB84 7F077054 24010002 */  li    $at, 2
/* 0ABB88 7F077058 11210024 */  beq   $t1, $at, .L7F0770EC
/* 0ABB8C 7F07705C 8FAF0144 */   lw    $t7, 0x144($sp)
/* 0ABB90 7F077060 24010003 */  li    $at, 3
/* 0ABB94 7F077064 11210010 */  beq   $t1, $at, .L7F0770A8
/* 0ABB98 7F077068 8FAF016C */   lw    $t7, 0x16c($sp)
/* 0ABB9C 7F07706C 24010004 */  li    $at, 4
/* 0ABBA0 7F077070 11210016 */  beq   $t1, $at, .L7F0770CC
/* 0ABBA4 7F077074 8FAF016C */   lw    $t7, 0x16c($sp)
/* 0ABBA8 7F077078 10000036 */  b     .L7F077154
/* 0ABBAC 7F07707C 8FA2016C */   lw    $v0, 0x16c($sp)
.L7F077080:
/* 0ABBB0 7F077080 8FAF016C */  lw    $t7, 0x16c($sp)
/* 0ABBB4 7F077084 3C19FC12 */  lui   $t9, (0xFC121824 >> 16) # lui $t9, 0xfc12         #
/* 0ABBB8 7F077088 3C0EFF33 */  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33         #
/* 0ABBBC 7F07708C 25F80008 */  addiu $t8, $t7, 8
/* 0ABBC0 7F077090 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0ABBC4 7F077094 35CEFFFF */  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff #
/* 0ABBC8 7F077098 37391824 */  ori   $t9, (0xFC121824 & 0xFFFF) # ori $t9, $t9, 0x1824 #
/* 0ABBCC 7F07709C ADF90000 */  sw    $t9, ($t7)
/* 0ABBD0 7F0770A0 1000002B */  b     .L7F077150
/* 0ABBD4 7F0770A4 ADEE0004 */   sw    $t6, 4($t7)                                      #gDPSetCombineMode()
.L7F0770A8:
/* 0ABBD8 7F0770A8 25F80008 */  addiu $t8, $t7, 8
/* 0ABBDC 7F0770AC 3C19FC12 */  lui   $t9, (0xFC121824 >> 16) # lui $t9, 0xfc12         #
/* 0ABBE0 7F0770B0 3C0EFF33 */  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33         #
/* 0ABBE4 7F0770B4 35CEFFFF */  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff #
/* 0ABBE8 7F0770B8 37391824 */  ori   $t9, (0xFC121824 & 0xFFFF) # ori $t9, $t9, 0x1824 #
/* 0ABBEC 7F0770BC AFB8016C */  sw    $t8, 0x16c($sp)
/* 0ABBF0 7F0770C0 ADEE0004 */  sw    $t6, 4($t7)
/* 0ABBF4 7F0770C4 10000022 */  b     .L7F077150
/* 0ABBF8 7F0770C8 ADF90000 */   sw    $t9, ($t7)                                       #gDPSetCombineMode()
.L7F0770CC:
/* 0ABBFC 7F0770CC 25F80008 */  addiu $t8, $t7, 8
/* 0ABC00 7F0770D0 3C19FC12 */  lui   $t9, (0xFC127E24 >> 16) # lui $t9, 0xfc12         #
/* 0ABC04 7F0770D4 37397E24 */  ori   $t9, (0xFC127E24 & 0xFFFF) # ori $t9, $t9, 0x7e24 #
/* 0ABC08 7F0770D8 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0ABC0C 7F0770DC 240EF9FC */  li    $t6, -1540
/* 0ABC10 7F0770E0 ADEE0004 */  sw    $t6, 4($t7)
/* 0ABC14 7F0770E4 1000001A */  b     .L7F077150
/* 0ABC18 7F0770E8 ADF90000 */   sw    $t9, ($t7)                                       #gDPSetCombineMode()
.L7F0770EC:
/* 0ABC1C 7F0770EC 34018000 */  li    $at, 32768
/* 0ABC20 7F0770F0 11E10006 */  beq   $t7, $at, .L7F07710C
/* 0ABC24 7F0770F4 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0ABC28 7F0770F8 3401C000 */  li    $at, 49152
/* 0ABC2C 7F0770FC 11E1000C */  beq   $t7, $at, .L7F077130
/* 0ABC30 7F077100 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0ABC34 7F077104 10000013 */  b     .L7F077154
/* 0ABC38 7F077108 8FA2016C */   lw    $v0, 0x16c($sp)
.L7F07710C:
/* 0ABC3C 7F07710C 27190008 */  addiu $t9, $t8, 8
/* 0ABC40 7F077110 3C0EFC12 */  lui   $t6, (0xFC121824 >> 16) # lui $t6, 0xfc12         #
/* 0ABC44 7F077114 3C0FFF33 */  lui   $t7, (0xFF33FFFF >> 16) # lui $t7, 0xff33         #
/* 0ABC48 7F077118 35EFFFFF */  ori   $t7, (0xFF33FFFF & 0xFFFF) # ori $t7, $t7, 0xffff #
/* 0ABC4C 7F07711C 35CE1824 */  ori   $t6, (0xFC121824 & 0xFFFF) # ori $t6, $t6, 0x1824 #
/* 0ABC50 7F077120 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABC54 7F077124 AF0F0004 */  sw    $t7, 4($t8)
/* 0ABC58 7F077128 10000009 */  b     .L7F077150
/* 0ABC5C 7F07712C AF0E0000 */   sw    $t6, ($t8)                                       #gDPSetCombineMode()
.L7F077130:
/* 0ABC60 7F077130 27190008 */  addiu $t9, $t8, 8
/* 0ABC64 7F077134 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABC68 7F077138 3C0EFC12 */  lui   $t6, (0xFC121824 >> 16) # lui $t6, 0xfc12         #
/* 0ABC6C 7F07713C 3C0FFF33 */  lui   $t7, (0xFF33FFFF >> 16) # lui $t7, 0xff33         #
/* 0ABC70 7F077140 35EFFFFF */  ori   $t7, (0xFF33FFFF & 0xFFFF) # ori $t7, $t7, 0xffff #
/* 0ABC74 7F077144 35CE1824 */  ori   $t6, (0xFC121824 & 0xFFFF) # ori $t6, $t6, 0x1824 #
/* 0ABC78 7F077148 AF0E0000 */  sw    $t6, ($t8)
/* 0ABC7C 7F07714C AF0F0004 */  sw    $t7, 4($t8)                                       #gDPSetCombineMode()
.L7F077150:
/* 0ABC80 7F077150 8FA2016C */  lw    $v0, 0x16c($sp)
.L7F077154:
/* 0ABC84 7F077154 8FA40140 */  lw    $a0, 0x140($sp)
/* 0ABC88 7F077158 32230007 */  andi  $v1, $s1, 7
/* 0ABC8C 7F07715C 00037540 */  sll   $t6, $v1, 0x15
/* 0ABC90 7F077160 24590008 */  addiu $t9, $v0, 8
/* 0ABC94 7F077164 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABC98 7F077168 3C01FD00 */  lui   $at, 0xfd00
/* 0ABC9C 7F07716C 308F0003 */  andi  $t7, $a0, 3
/* 0ABCA0 7F077170 000F24C0 */  sll   $a0, $t7, 0x13
/* 0ABCA4 7F077174 01C1C825 */  or    $t9, $t6, $at
/* 0ABCA8 7F077178 01C01825 */  move  $v1, $t6
/* 0ABCAC 7F07717C 03247025 */  or    $t6, $t9, $a0
/* 0ABCB0 7F077180 AC4E0000 */  sw    $t6, ($v0)
/* 0ABCB4 7F077184 8EEF0000 */  lw    $t7, ($s7)
/* 0ABCB8 7F077188 3C01F500 */  lui   $at, 0xf500
/* 0ABCBC 7F07718C 00615825 */  or    $t3, $v1, $at
/* 0ABCC0 7F077190 AC4F0004 */  sw    $t7, 4($v0)
/* 0ABCC4 7F077194 8FA5016C */  lw    $a1, 0x16c($sp)
/* 0ABCC8 7F077198 01647025 */  or    $t6, $t3, $a0
/* 0ABCCC 7F07719C 3C0A0700 */  lui   $t2, 0x700
/* 0ABCD0 7F0771A0 24B90008 */  addiu $t9, $a1, 8
/* 0ABCD4 7F0771A4 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABCD8 7F0771A8 ACAE0000 */  sw    $t6, ($a1)
/* 0ABCDC 7F0771AC 92EF000A */  lbu   $t7, 0xa($s7)
/* 0ABCE0 7F0771B0 3C0DE600 */  lui   $t5, 0xe600
/* 0ABCE4 7F0771B4 2A6107FF */  slti  $at, $s3, 0x7ff
/* 0ABCE8 7F0771B8 31F80003 */  andi  $t8, $t7, 3
/* 0ABCEC 7F0771BC 92EF0009 */  lbu   $t7, 9($s7)
/* 0ABCF0 7F0771C0 0018CC80 */  sll   $t9, $t8, 0x12
/* 0ABCF4 7F0771C4 032A7025 */  or    $t6, $t9, $t2
/* 0ABCF8 7F0771C8 31F80003 */  andi  $t8, $t7, 3
/* 0ABCFC 7F0771CC 0018CA00 */  sll   $t9, $t8, 8
/* 0ABD00 7F0771D0 01D97825 */  or    $t7, $t6, $t9
/* 0ABD04 7F0771D4 ACAF0004 */  sw    $t7, 4($a1)
/* 0ABD08 7F0771D8 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABD0C 7F0771DC 240707FF */  li    $a3, 2047
/* 0ABD10 7F0771E0 270E0008 */  addiu $t6, $t8, 8
/* 0ABD14 7F0771E4 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0ABD18 7F0771E8 AF000004 */  sw    $zero, 4($t8)
/* 0ABD1C 7F0771EC AF0D0000 */  sw    $t5, ($t8)
/* 0ABD20 7F0771F0 8FA8016C */  lw    $t0, 0x16c($sp)
/* 0ABD24 7F0771F4 3C18F300 */  lui   $t8, 0xf300
/* 0ABD28 7F0771F8 250F0008 */  addiu $t7, $t0, 8
/* 0ABD2C 7F0771FC AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABD30 7F077200 10200003 */  beqz  $at, .L7F077210
/* 0ABD34 7F077204 AD180000 */   sw    $t8, ($t0)
/* 0ABD38 7F077208 10000001 */  b     .L7F077210
/* 0ABD3C 7F07720C 02603825 */   move  $a3, $s3
.L7F077210:
/* 0ABD40 7F077210 8FB80138 */  lw    $t8, 0x138($sp)
/* 0ABD44 7F077214 30EE0FFF */  andi  $t6, $a3, 0xfff
/* 0ABD48 7F077218 000ECB00 */  sll   $t9, $t6, 0xc
/* 0ABD4C 7F07721C 032A7825 */  or    $t7, $t9, $t2
/* 0ABD50 7F077220 330E0FFF */  andi  $t6, $t8, 0xfff
/* 0ABD54 7F077224 01EEC825 */  or    $t9, $t7, $t6
/* 0ABD58 7F077228 AD190004 */  sw    $t9, 4($t0)
/* 0ABD5C 7F07722C 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABD60 7F077230 3C0CE700 */  lui   $t4, 0xe700
/* 0ABD64 7F077234 24010002 */  li    $at, 2
/* 0ABD68 7F077238 270F0008 */  addiu $t7, $t8, 8
/* 0ABD6C 7F07723C AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABD70 7F077240 AF000004 */  sw    $zero, 4($t8)
/* 0ABD74 7F077244 15210038 */  bne   $t1, $at, .L7F077328
/* 0ABD78 7F077248 AF0C0000 */   sw    $t4, ($t8)
/* 0ABD7C 7F07724C 92CE000A */  lbu   $t6, 0xa($s6)
/* 0ABD80 7F077250 241903FF */  li    $t9, 1023
/* 0ABD84 7F077254 26670001 */  addiu $a3, $s3, 1
/* 0ABD88 7F077258 032E1023 */  subu  $v0, $t9, $t6
/* 0ABD8C 7F07725C 0047082B */  sltu  $at, $v0, $a3
/* 0ABD90 7F077260 10200003 */  beqz  $at, .L7F077270
/* 0ABD94 7F077264 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0ABD98 7F077268 10000002 */  b     .L7F077274
/* 0ABD9C 7F07726C 00404025 */   move  $t0, $v0
.L7F077270:
/* 0ABDA0 7F077270 00004025 */  move  $t0, $zero
.L7F077274:
/* 0ABDA4 7F077274 270F0008 */  addiu $t7, $t8, 8
/* 0ABDA8 7F077278 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABDAC 7F07727C 3C19F500 */  lui   $t9, (0xF5000100 >> 16) # lui $t9, 0xf500         #
/* 0ABDB0 7F077280 37390100 */  ori   $t9, (0xF5000100 & 0xFFFF) # ori $t9, $t9, 0x100  #gDPSetTile()
/* 0ABDB4 7F077284 AF190000 */  sw    $t9, ($t8)
/* 0ABDB8 7F077288 AF0A0004 */  sw    $t2, 4($t8)
/* 0ABDBC 7F07728C 8FAE016C */  lw    $t6, 0x16c($sp)
/* 0ABDC0 7F077290 00E83023 */  subu  $a2, $a3, $t0
/* 0ABDC4 7F077294 310503FF */  andi  $a1, $t0, 0x3ff
/* 0ABDC8 7F077298 25D80008 */  addiu $t8, $t6, 8
/* 0ABDCC 7F07729C AFB8016C */  sw    $t8, 0x16c($sp)
/* 0ABDD0 7F0772A0 ADC00004 */  sw    $zero, 4($t6)
/* 0ABDD4 7F0772A4 ADCD0000 */  sw    $t5, ($t6)
/* 0ABDD8 7F0772A8 8FA4016C */  lw    $a0, 0x16c($sp)
/* 0ABDDC 7F0772AC 30D803FF */  andi  $t8, $a2, 0x3ff
/* 0ABDE0 7F0772B0 00187B80 */  sll   $t7, $t8, 0xe
/* 0ABDE4 7F0772B4 24990008 */  addiu $t9, $a0, 8
/* 0ABDE8 7F0772B8 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0ABDEC 7F0772BC 00057080 */  sll   $t6, $a1, 2
/* 0ABDF0 7F0772C0 3C01F000 */  lui   $at, 0xf000
/* 0ABDF4 7F0772C4 01E1C825 */  or    $t9, $t7, $at
/* 0ABDF8 7F0772C8 01C02825 */  move  $a1, $t6
/* 0ABDFC 7F0772CC 032E7025 */  or    $t6, $t9, $t6
/* 0ABE00 7F0772D0 AC8E0000 */  sw    $t6, ($a0)
/* 0ABE04 7F0772D4 92D8000A */  lbu   $t8, 0xa($s6)
/* 0ABE08 7F0772D8 03067821 */  addu  $t7, $t8, $a2
/* 0ABE0C 7F0772DC 31F903FF */  andi  $t9, $t7, 0x3ff
/* 0ABE10 7F0772E0 00197380 */  sll   $t6, $t9, 0xe
/* 0ABE14 7F0772E4 01CAC025 */  or    $t8, $t6, $t2
/* 0ABE18 7F0772E8 03057825 */  or    $t7, $t8, $a1
/* 0ABE1C 7F0772EC AC8F0004 */  sw    $t7, 4($a0)
/* 0ABE20 7F0772F0 8FB9016C */  lw    $t9, 0x16c($sp)
/* 0ABE24 7F0772F4 272E0008 */  addiu $t6, $t9, 8
/* 0ABE28 7F0772F8 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0ABE2C 7F0772FC AF200004 */  sw    $zero, 4($t9)
/* 0ABE30 7F077300 AF2C0000 */  sw    $t4, ($t9)
/* 0ABE34 7F077304 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABE38 7F077308 3C19BA00 */  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00         #
/* 0ABE3C 7F07730C 37390E02 */  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02  #gDPSetTextureLUT()
/* 0ABE40 7F077310 270F0008 */  addiu $t7, $t8, 8
/* 0ABE44 7F077314 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABE48 7F077318 AF190000 */  sw    $t9, ($t8)
/* 0ABE4C 7F07731C 8FAE0144 */  lw    $t6, 0x144($sp)
/* 0ABE50 7F077320 10000008 */  b     .L7F077344
/* 0ABE54 7F077324 AF0E0004 */   sw    $t6, 4($t8)
.L7F077328:
/* 0ABE58 7F077328 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0ABE5C 7F07732C 3C19BA00 */  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00         #
/* 0ABE60 7F077330 37390E02 */  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02  #gDPSetTextureLUT()
/* 0ABE64 7F077334 270F0008 */  addiu $t7, $t8, 8
/* 0ABE68 7F077338 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABE6C 7F07733C AF000004 */  sw    $zero, 4($t8)
/* 0ABE70 7F077340 AF190000 */  sw    $t9, ($t8)
.L7F077344:
/* 0ABE74 7F077344 8FB0016C */  lw    $s0, 0x16c($sp)
/* 0ABE78 7F077348 324F0003 */  andi  $t7, $s2, 3
/* 0ABE7C 7F07734C 000FCCC0 */  sll   $t9, $t7, 0x13
/* 0ABE80 7F077350 26180008 */  addiu $t8, $s0, 8
/* 0ABE84 7F077354 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0ABE88 7F077358 8FB80134 */  lw    $t8, 0x134($sp)
/* 0ABE8C 7F07735C 01797025 */  or    $t6, $t3, $t9
/* 0ABE90 7F077360 02802025 */  move  $a0, $s4
/* 0ABE94 7F077364 330F01FF */  andi  $t7, $t8, 0x1ff
/* 0ABE98 7F077368 000FCA40 */  sll   $t9, $t7, 9
/* 0ABE9C 7F07736C 01D9C025 */  or    $t8, $t6, $t9
/* 0ABEA0 7F077370 0FC1D968 */  jal   is_less_than_certain_power_of_2
/* 0ABEA4 7F077374 AE180000 */   sw    $t8, ($s0)
/* 0ABEA8 7F077378 02A02025 */  move  $a0, $s5
/* 0ABEAC 7F07737C 0FC1D968 */  jal   is_less_than_certain_power_of_2
/* 0ABEB0 7F077380 AFA20058 */   sw    $v0, 0x58($sp)
/* 0ABEB4 7F077384 92F9000A */  lbu   $t9, 0xa($s7)
/* 0ABEB8 7F077388 304F000F */  andi  $t7, $v0, 0xf
/* 0ABEBC 7F07738C 8FA70058 */  lw    $a3, 0x58($sp)
/* 0ABEC0 7F077390 000F7100 */  sll   $t6, $t7, 4
/* 0ABEC4 7F077394 33380003 */  andi  $t8, $t9, 3
/* 0ABEC8 7F077398 00187C80 */  sll   $t7, $t8, 0x12
/* 0ABECC 7F07739C 01CFC825 */  or    $t9, $t6, $t7
/* 0ABED0 7F0773A0 30F8000F */  andi  $t8, $a3, 0xf
/* 0ABED4 7F0773A4 00187380 */  sll   $t6, $t8, 0xe
/* 0ABED8 7F0773A8 92F80009 */  lbu   $t8, 9($s7)
/* 0ABEDC 7F0773AC 032E7825 */  or    $t7, $t9, $t6
/* 0ABEE0 7F0773B0 8FA50180 */  lw    $a1, 0x180($sp)
/* 0ABEE4 7F0773B4 33190003 */  andi  $t9, $t8, 3
/* 0ABEE8 7F0773B8 00197200 */  sll   $t6, $t9, 8
/* 0ABEEC 7F0773BC 01EEC025 */  or    $t8, $t7, $t6
/* 0ABEF0 7F0773C0 AE180004 */  sw    $t8, 4($s0)
/* 0ABEF4 7F0773C4 8FA3016C */  lw    $v1, 0x16c($sp)
/* 0ABEF8 7F0773C8 30A40FFF */  andi  $a0, $a1, 0xfff
/* 0ABEFC 7F0773CC 00047300 */  sll   $t6, $a0, 0xc
/* 0ABF00 7F0773D0 3C01F200 */  lui   $at, 0xf200
/* 0ABF04 7F0773D4 246F0008 */  addiu $t7, $v1, 8
/* 0ABF08 7F0773D8 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0ABF0C 7F0773DC 01C1C025 */  or    $t8, $t6, $at
/* 0ABF10 7F0773E0 0304C825 */  or    $t9, $t8, $a0
/* 0ABF14 7F0773E4 26AFFFFF */  addiu $t7, $s5, -1
/* 0ABF18 7F0773E8 000F7080 */  sll   $t6, $t7, 2
/* 0ABF1C 7F0773EC 01C5C021 */  addu  $t8, $t6, $a1
/* 0ABF20 7F0773F0 AC790000 */  sw    $t9, ($v1)
/* 0ABF24 7F0773F4 33190FFF */  andi  $t9, $t8, 0xfff
/* 0ABF28 7F0773F8 268EFFFF */  addiu $t6, $s4, -1
/* 0ABF2C 7F0773FC 000EC080 */  sll   $t8, $t6, 2
/* 0ABF30 7F077400 00197B00 */  sll   $t7, $t9, 0xc
/* 0ABF34 7F077404 0305C821 */  addu  $t9, $t8, $a1
/* 0ABF38 7F077408 332E0FFF */  andi  $t6, $t9, 0xfff
/* 0ABF3C 7F07740C 01EEC025 */  or    $t8, $t7, $t6
/* 0ABF40 7F077410 100001DB */  b     .L7F077B80
/* 0ABF44 7F077414 AC780004 */   sw    $t8, 4($v1)
/* 0ABF48 7F077418 AFA000D0 */  sw    $zero, 0xd0($sp)
.L7F07741C:
/* 0ABF4C 7F07741C 1040000B */  beqz  $v0, .L7F07744C
/* 0ABF50 7F077420 AFA300CC */   sw    $v1, 0xcc($sp)
/* 0ABF54 7F077424 8C430008 */  lw    $v1, 8($v0)
/* 0ABF58 7F077428 306E0003 */  andi  $t6, $v1, 3
/* 0ABF5C 7F07742C A3AE00CA */  sb    $t6, 0xca($sp)
/* 0ABF60 7F077430 8C52000C */  lw    $s2, 0xc($v0)
/* 0ABF64 7F077434 00038EC0 */  sll   $s1, $v1, 0x1b
/* 0ABF68 7F077438 0011CF42 */  srl   $t9, $s1, 0x1d
/* 0ABF6C 7F07743C 0012C782 */  srl   $t8, $s2, 0x1e
/* 0ABF70 7F077440 333100FF */  andi  $s1, $t9, 0xff
/* 0ABF74 7F077444 10000005 */  b     .L7F07745C
/* 0ABF78 7F077448 00189380 */   sll   $s2, $t8, 0xe
.L7F07744C:
/* 0ABF7C 7F07744C 92EF0008 */  lbu   $t7, 8($s7)
/* 0ABF80 7F077450 92F10007 */  lbu   $s1, 7($s7)
/* 0ABF84 7F077454 8FB200C4 */  lw    $s2, 0xc4($sp)
/* 0ABF88 7F077458 A3AF00CA */  sb    $t7, 0xca($sp)
.L7F07745C:
/* 0ABF8C 7F07745C 1040000B */  beqz  $v0, .L7F07748C
/* 0ABF90 7F077460 93B300CA */   lbu   $s3, 0xca($sp)
/* 0ABF94 7F077464 8C4E000C */  lw    $t6, 0xc($v0)
/* 0ABF98 7F077468 02C02025 */  move  $a0, $s6
/* 0ABF9C 7F07746C 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0ABFA0 7F077470 000EC880 */  sll   $t9, $t6, 2
/* 0ABFA4 7F077474 07210005 */  bgez  $t9, .L7F07748C
/* 0ABFA8 7F077478 00000000 */   nop   
/* 0ABFAC 7F07747C 0FC33275 */  jal   sub_GAME_7F0CC9D4
/* 0ABFB0 7F077480 27A600BC */   addiu $a2, $sp, 0xbc
/* 0ABFB4 7F077484 1000002C */  b     .L7F077538
/* 0ABFB8 7F077488 27A4016C */   addiu $a0, $sp, 0x16c
.L7F07748C:
/* 0ABFBC 7F07748C 12600022 */  beqz  $s3, .L7F077518
/* 0ABFC0 7F077490 24180002 */   li    $t8, 2
/* 0ABFC4 7F077494 24010001 */  li    $at, 1
/* 0ABFC8 7F077498 12610017 */  beq   $s3, $at, .L7F0774F8
/* 0ABFCC 7F07749C 240F0002 */   li    $t7, 2
/* 0ABFD0 7F0774A0 24010002 */  li    $at, 2
/* 0ABFD4 7F0774A4 1261000C */  beq   $s3, $at, .L7F0774D8
/* 0ABFD8 7F0774A8 24180002 */   li    $t8, 2
/* 0ABFDC 7F0774AC 24010003 */  li    $at, 3
/* 0ABFE0 7F0774B0 16610020 */  bne   $s3, $at, .L7F077534
/* 0ABFE4 7F0774B4 240F0003 */   li    $t7, 3
/* 0ABFE8 7F0774B8 AFAF00C0 */  sw    $t7, 0xc0($sp)
/* 0ABFEC 7F0774BC 02A02025 */  move  $a0, $s5
/* 0ABFF0 7F0774C0 02802825 */  move  $a1, $s4
/* 0ABFF4 7F0774C4 0FC1DA4A */  jal   sub_GAME_7F076928
/* 0ABFF8 7F0774C8 8FA600CC */   lw    $a2, 0xcc($sp)
/* 0ABFFC 7F0774CC 244EFFFF */  addiu $t6, $v0, -1
/* 0AC000 7F0774D0 10000018 */  b     .L7F077534
/* 0AC004 7F0774D4 AFAE00BC */   sw    $t6, 0xbc($sp)
.L7F0774D8:
/* 0AC008 7F0774D8 AFB800C0 */  sw    $t8, 0xc0($sp)
/* 0AC00C 7F0774DC 02A02025 */  move  $a0, $s5
/* 0AC010 7F0774E0 02802825 */  move  $a1, $s4
/* 0AC014 7F0774E4 0FC1DA2E */  jal   sub_GAME_7F0768B8
/* 0AC018 7F0774E8 8FA600CC */   lw    $a2, 0xcc($sp)
/* 0AC01C 7F0774EC 2459FFFF */  addiu $t9, $v0, -1
/* 0AC020 7F0774F0 10000010 */  b     .L7F077534
/* 0AC024 7F0774F4 AFB900BC */   sw    $t9, 0xbc($sp)
.L7F0774F8:
/* 0AC028 7F0774F8 AFAF00C0 */  sw    $t7, 0xc0($sp)
/* 0AC02C 7F0774FC 02A02025 */  move  $a0, $s5
/* 0AC030 7F077500 02802825 */  move  $a1, $s4
/* 0AC034 7F077504 0FC1DA12 */  jal   sub_GAME_7F076848
/* 0AC038 7F077508 8FA600CC */   lw    $a2, 0xcc($sp)
/* 0AC03C 7F07750C 244EFFFF */  addiu $t6, $v0, -1
/* 0AC040 7F077510 10000008 */  b     .L7F077534
/* 0AC044 7F077514 AFAE00BC */   sw    $t6, 0xbc($sp)
.L7F077518:
/* 0AC048 7F077518 AFB800C0 */  sw    $t8, 0xc0($sp)
/* 0AC04C 7F07751C 02A02025 */  move  $a0, $s5
/* 0AC050 7F077520 02802825 */  move  $a1, $s4
/* 0AC054 7F077524 0FC1D9F6 */  jal   sub_GAME_7F0767D8
/* 0AC058 7F077528 8FA600CC */   lw    $a2, 0xcc($sp)
/* 0AC05C 7F07752C 2459FFFF */  addiu $t9, $v0, -1
/* 0AC060 7F077530 AFB900BC */  sw    $t9, 0xbc($sp)
.L7F077534:
/* 0AC064 7F077534 27A4016C */  addiu $a0, $sp, 0x16c
.L7F077538:
/* 0AC068 7F077538 8FA50178 */  lw    $a1, 0x178($sp)
/* 0AC06C 7F07753C 24060002 */  li    $a2, 2
/* 0AC070 7F077540 0FC1DA66 */  jal   texSetRenderMode
/* 0AC074 7F077544 02003825 */   move  $a3, $s0
/* 0AC078 7F077548 2A010002 */  slti  $at, $s0, 2
/* 0AC07C 7F07754C 14200012 */  bnez  $at, .L7F077598
/* 0AC080 7F077550 02204025 */   move  $t0, $s1
/* 0AC084 7F077554 8FA2016C */  lw    $v0, 0x16c($sp)
/* 0AC088 7F077558 321800FF */  andi  $t8, $s0, 0xff
/* 0AC08C 7F07755C 0018CC00 */  sll   $t9, $t8, 0x10
/* 0AC090 7F077560 244E0008 */  addiu $t6, $v0, 8
/* 0AC094 7F077564 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0AC098 7F077568 8FAE00CC */  lw    $t6, 0xcc($sp)
/* 0AC09C 7F07756C 3C01BB00 */  lui   $at, 0xbb00
/* 0AC0A0 7F077570 03217825 */  or    $t7, $t9, $at
/* 0AC0A4 7F077574 25D8FFFF */  addiu $t8, $t6, -1
/* 0AC0A8 7F077578 33190007 */  andi  $t9, $t8, 7
/* 0AC0AC 7F07757C 001972C0 */  sll   $t6, $t9, 0xb
/* 0AC0B0 7F077580 01EEC025 */  or    $t8, $t7, $t6
/* 0AC0B4 7F077584 37190001 */  ori   $t9, $t8, 1
/* 0AC0B8 7F077588 240FFFFF */  li    $t7, -1
/* 0AC0BC 7F07758C AC4F0004 */  sw    $t7, 4($v0)
/* 0AC0C0 7F077590 1000000E */  b     .L7F0775CC
/* 0AC0C4 7F077594 AC590000 */   sw    $t9, ($v0)
.L7F077598:
/* 0AC0C8 7F077598 8FA2016C */  lw    $v0, 0x16c($sp)
/* 0AC0CC 7F07759C 8FB900CC */  lw    $t9, 0xcc($sp)
/* 0AC0D0 7F0775A0 3C01BB00 */  lui   $at, 0xbb00
/* 0AC0D4 7F0775A4 24580008 */  addiu $t8, $v0, 8
/* 0AC0D8 7F0775A8 272FFFFF */  addiu $t7, $t9, -1
/* 0AC0DC 7F0775AC 31EE0007 */  andi  $t6, $t7, 7
/* 0AC0E0 7F0775B0 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0AC0E4 7F0775B4 000EC2C0 */  sll   $t8, $t6, 0xb
/* 0AC0E8 7F0775B8 0301C825 */  or    $t9, $t8, $at
/* 0AC0EC 7F0775BC 372F0001 */  ori   $t7, $t9, 1
/* 0AC0F0 7F0775C0 240EFFFF */  li    $t6, -1
/* 0AC0F4 7F0775C4 AC4E0004 */  sw    $t6, 4($v0)
/* 0AC0F8 7F0775C8 AC4F0000 */  sw    $t7, ($v0)
.L7F0775CC:
/* 0AC0FC 7F0775CC 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0AC100 7F0775D0 3C0FBA00 */  lui   $t7, (0xBA001001 >> 16) # lui $t7, 0xba00         #
/* 0AC104 7F0775D4 35EF1001 */  ori   $t7, (0xBA001001 & 0xFFFF) # ori $t7, $t7, 0x1001 #
/* 0AC108 7F0775D8 27190008 */  addiu $t9, $t8, 8
/* 0AC10C 7F0775DC AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC110 7F0775E0 3C0E0001 */  lui   $t6, 1
/* 0AC114 7F0775E4 AF0E0004 */  sw    $t6, 4($t8)
/* 0AC118 7F0775E8 1220000B */  beqz  $s1, .L7F077618
/* 0AC11C 7F0775EC AF0F0000 */   sw    $t7, ($t8)                                       #gDPSetTextureLOD(G_TL_LOD)
/* 0AC120 7F0775F0 24010002 */  li    $at, 2
/* 0AC124 7F0775F4 11010024 */  beq   $t0, $at, .L7F077688
/* 0AC128 7F0775F8 24010003 */   li    $at, 3
/* 0AC12C 7F0775FC 11010010 */  beq   $t0, $at, .L7F077640
/* 0AC130 7F077600 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0AC134 7F077604 24010004 */  li    $at, 4
/* 0AC138 7F077608 11010016 */  beq   $t0, $at, .L7F077664
/* 0AC13C 7F07760C 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0AC140 7F077610 10000037 */  b     .L7F0776F0
/* 0AC144 7F077614 8FA2016C */   lw    $v0, 0x16c($sp)
.L7F077618:
/* 0AC148 7F077618 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0AC14C 7F07761C 3C0FFC26 */  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26          #
/* 0AC150 7F077620 3C0E1F10 */  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10          #
/* 0AC154 7F077624 27190008 */  addiu $t9, $t8, 8
/* 0AC158 7F077628 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC15C 7F07762C 35CE93FF */  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff #
/* 0AC160 7F077630 35EFA004 */  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004 #
/* 0AC164 7F077634 AF0F0000 */  sw    $t7, ($t8)
/* 0AC168 7F077638 1000002C */  b     .L7F0776EC
/* 0AC16C 7F07763C AF0E0004 */   sw    $t6, 4($t8)                                       #gDPSetCombineMode()
.L7F077640:
/* 0AC170 7F077640 27190008 */  addiu $t9, $t8, 8
/* 0AC174 7F077644 3C0FFC26 */  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
/* 0AC178 7F077648 3C0E1F10 */  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10
/* 0AC17C 7F07764C 35CE93FF */  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff
/* 0AC180 7F077650 35EFA004 */  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
/* 0AC184 7F077654 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC188 7F077658 AF0E0004 */  sw    $t6, 4($t8)
/* 0AC18C 7F07765C 10000023 */  b     .L7F0776EC
/* 0AC190 7F077660 AF0F0000 */   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F077664:
/* 0AC194 7F077664 27190008 */  addiu $t9, $t8, 8
/* 0AC198 7F077668 3C0FFC26 */  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
/* 0AC19C 7F07766C 3C0E1FFC */  lui   $t6, (0x1FFC93FC >> 16) # lui $t6, 0x1ffc
/* 0AC1A0 7F077670 35CE93FC */  ori   $t6, (0x1FFC93FC & 0xFFFF) # ori $t6, $t6, 0x93fc
/* 0AC1A4 7F077674 35EFA004 */  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
/* 0AC1A8 7F077678 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC1AC 7F07767C AF0E0004 */  sw    $t6, 4($t8)
/* 0AC1B0 7F077680 1000001A */  b     .L7F0776EC
/* 0AC1B4 7F077684 AF0F0000 */   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F077688:
/* 0AC1B8 7F077688 34018000 */  li    $at, 32768
/* 0AC1BC 7F07768C 12410006 */  beq   $s2, $at, .L7F0776A8
/* 0AC1C0 7F077690 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0AC1C4 7F077694 3401C000 */  li    $at, 49152
/* 0AC1C8 7F077698 1241000C */  beq   $s2, $at, .L7F0776CC
/* 0AC1CC 7F07769C 8FB8016C */   lw    $t8, 0x16c($sp)
/* 0AC1D0 7F0776A0 10000013 */  b     .L7F0776F0
/* 0AC1D4 7F0776A4 8FA2016C */   lw    $v0, 0x16c($sp)
.L7F0776A8:
/* 0AC1D8 7F0776A8 27190008 */  addiu $t9, $t8, 8
/* 0AC1DC 7F0776AC 3C0FFC12 */  lui   $t7, (0xFC121824 >> 16) # lui $t7, 0xfc12
/* 0AC1E0 7F0776B0 3C0EFF33 */  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33
/* 0AC1E4 7F0776B4 35CEFFFF */  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff
/* 0AC1E8 7F0776B8 35EF1824 */  ori   $t7, (0xFC121824 & 0xFFFF) # ori $t7, $t7, 0x1824
/* 0AC1EC 7F0776BC AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC1F0 7F0776C0 AF0E0004 */  sw    $t6, 4($t8)
/* 0AC1F4 7F0776C4 10000009 */  b     .L7F0776EC
/* 0AC1F8 7F0776C8 AF0F0000 */   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F0776CC:
/* 0AC1FC 7F0776CC 27190008 */  addiu $t9, $t8, 8
/* 0AC200 7F0776D0 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC204 7F0776D4 3C0FFC12 */  lui   $t7, (0xFC121824 >> 16) # lui $t7, 0xfc12
/* 0AC208 7F0776D8 3C0EFF33 */  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33
/* 0AC20C 7F0776DC 35CEFFFF */  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff
/* 0AC210 7F0776E0 35EF1824 */  ori   $t7, (0xFC121824 & 0xFFFF) # ori $t7, $t7, 0x1824
/* 0AC214 7F0776E4 AF0F0000 */  sw    $t7, ($t8)
/* 0AC218 7F0776E8 AF0E0004 */  sw    $t6, 4($t8)                                       #gDPSetCombineMode()
.L7F0776EC:
/* 0AC21C 7F0776EC 8FA2016C */  lw    $v0, 0x16c($sp)
.L7F0776F0:
/* 0AC220 7F0776F0 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0AC224 7F0776F4 32230007 */  andi  $v1, $s1, 7
/* 0AC228 7F0776F8 00037D40 */  sll   $t7, $v1, 0x15
/* 0AC22C 7F0776FC 24590008 */  addiu $t9, $v0, 8
/* 0AC230 7F077700 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC234 7F077704 3C01FD00 */  lui   $at, 0xfd00
/* 0AC238 7F077708 01E17025 */  or    $t6, $t7, $at
/* 0AC23C 7F07770C 01E01825 */  move  $v1, $t7
/* 0AC240 7F077710 33190003 */  andi  $t9, $t8, 3
/* 0AC244 7F077714 00197CC0 */  sll   $t7, $t9, 0x13
/* 0AC248 7F077718 01CFC025 */  or    $t8, $t6, $t7
/* 0AC24C 7F07771C AC580000 */  sw    $t8, ($v0)
/* 0AC250 7F077720 8EF90000 */  lw    $t9, ($s7)
/* 0AC254 7F077724 3C01F500 */  lui   $at, 0xf500
/* 0AC258 7F077728 00614825 */  or    $t1, $v1, $at
/* 0AC25C 7F07772C AC590004 */  sw    $t9, 4($v0)
/* 0AC260 7F077730 8FA4016C */  lw    $a0, 0x16c($sp)
/* 0AC264 7F077734 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0AC268 7F077738 3C0A0700 */  lui   $t2, 0x700
/* 0AC26C 7F07773C 248F0008 */  addiu $t7, $a0, 8
/* 0AC270 7F077740 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0AC274 7F077744 33190003 */  andi  $t9, $t8, 3
/* 0AC278 7F077748 001974C0 */  sll   $t6, $t9, 0x13
/* 0AC27C 7F07774C 012E7825 */  or    $t7, $t1, $t6
/* 0AC280 7F077750 AC8F0000 */  sw    $t7, ($a0)
/* 0AC284 7F077754 AC8A0004 */  sw    $t2, 4($a0)
/* 0AC288 7F077758 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0AC28C 7F07775C 3C0DE600 */  lui   $t5, 0xe600
/* 0AC290 7F077760 240707FF */  li    $a3, 2047
/* 0AC294 7F077764 27190008 */  addiu $t9, $t8, 8
/* 0AC298 7F077768 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC29C 7F07776C AF000004 */  sw    $zero, 4($t8)
/* 0AC2A0 7F077770 AF0D0000 */  sw    $t5, ($t8)
/* 0AC2A4 7F077774 8FA6016C */  lw    $a2, 0x16c($sp)
/* 0AC2A8 7F077778 3C18F300 */  lui   $t8, 0xf300
/* 0AC2AC 7F07777C 24CF0008 */  addiu $t7, $a2, 8
/* 0AC2B0 7F077780 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0AC2B4 7F077784 ACD80000 */  sw    $t8, ($a2)
/* 0AC2B8 7F077788 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0AC2BC 7F07778C 2B2107FF */  slti  $at, $t9, 0x7ff
/* 0AC2C0 7F077790 10200003 */  beqz  $at, .L7F0777A0
/* 0AC2C4 7F077794 00000000 */   nop   
/* 0AC2C8 7F077798 10000001 */  b     .L7F0777A0
/* 0AC2CC 7F07779C 03203825 */   move  $a3, $t9
.L7F0777A0:
/* 0AC2D0 7F0777A0 30EE0FFF */  andi  $t6, $a3, 0xfff
/* 0AC2D4 7F0777A4 000E7B00 */  sll   $t7, $t6, 0xc
/* 0AC2D8 7F0777A8 01EAC025 */  or    $t8, $t7, $t2
/* 0AC2DC 7F0777AC ACD80004 */  sw    $t8, 4($a2)
/* 0AC2E0 7F0777B0 8FB9016C */  lw    $t9, 0x16c($sp)
/* 0AC2E4 7F0777B4 3C0CE700 */  lui   $t4, 0xe700
/* 0AC2E8 7F0777B8 24010002 */  li    $at, 2
/* 0AC2EC 7F0777BC 272E0008 */  addiu $t6, $t9, 8
/* 0AC2F0 7F0777C0 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0AC2F4 7F0777C4 AF200004 */  sw    $zero, 4($t9)
/* 0AC2F8 7F0777C8 15010038 */  bne   $t0, $at, .L7F0778AC
/* 0AC2FC 7F0777CC AF2C0000 */   sw    $t4, ($t9)
/* 0AC300 7F0777D0 8FA300BC */  lw    $v1, 0xbc($sp)
/* 0AC304 7F0777D4 92CF000A */  lbu   $t7, 0xa($s6)
/* 0AC308 7F0777D8 241803FF */  li    $t8, 1023
/* 0AC30C 7F0777DC 24660001 */  addiu $a2, $v1, 1
/* 0AC310 7F0777E0 030F1023 */  subu  $v0, $t8, $t7
/* 0AC314 7F0777E4 0046082B */  sltu  $at, $v0, $a2
/* 0AC318 7F0777E8 10200003 */  beqz  $at, .L7F0777F8
/* 0AC31C 7F0777EC 8FB9016C */   lw    $t9, 0x16c($sp)
/* 0AC320 7F0777F0 10000002 */  b     .L7F0777FC
/* 0AC324 7F0777F4 00403825 */   move  $a3, $v0
.L7F0777F8:
/* 0AC328 7F0777F8 00003825 */  move  $a3, $zero
.L7F0777FC:
/* 0AC32C 7F0777FC 272E0008 */  addiu $t6, $t9, 8
/* 0AC330 7F077800 AFAE016C */  sw    $t6, 0x16c($sp)
/* 0AC334 7F077804 3C18F500 */  lui   $t8, (0xF5000100 >> 16) # lui $t8, 0xf500         #
/* 0AC338 7F077808 37180100 */  ori   $t8, (0xF5000100 & 0xFFFF) # ori $t8, $t8, 0x100  #gDPSetTile()
/* 0AC33C 7F07780C AF380000 */  sw    $t8, ($t9)
/* 0AC340 7F077810 AF2A0004 */  sw    $t2, 4($t9)
/* 0AC344 7F077814 8FAF016C */  lw    $t7, 0x16c($sp)
/* 0AC348 7F077818 00C73023 */  subu  $a2, $a2, $a3
/* 0AC34C 7F07781C 30E503FF */  andi  $a1, $a3, 0x3ff
/* 0AC350 7F077820 25F90008 */  addiu $t9, $t7, 8
/* 0AC354 7F077824 AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC358 7F077828 ADE00004 */  sw    $zero, 4($t7)
/* 0AC35C 7F07782C ADED0000 */  sw    $t5, ($t7)
/* 0AC360 7F077830 8FA4016C */  lw    $a0, 0x16c($sp)
/* 0AC364 7F077834 30D903FF */  andi  $t9, $a2, 0x3ff
/* 0AC368 7F077838 00197380 */  sll   $t6, $t9, 0xe
/* 0AC36C 7F07783C 24980008 */  addiu $t8, $a0, 8
/* 0AC370 7F077840 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0AC374 7F077844 00057880 */  sll   $t7, $a1, 2
/* 0AC378 7F077848 3C01F000 */  lui   $at, 0xf000
/* 0AC37C 7F07784C 01C1C025 */  or    $t8, $t6, $at
/* 0AC380 7F077850 01E02825 */  move  $a1, $t7
/* 0AC384 7F077854 030F7825 */  or    $t7, $t8, $t7
/* 0AC388 7F077858 AC8F0000 */  sw    $t7, ($a0)
/* 0AC38C 7F07785C 92D9000A */  lbu   $t9, 0xa($s6)
/* 0AC390 7F077860 03267021 */  addu  $t6, $t9, $a2
/* 0AC394 7F077864 31D803FF */  andi  $t8, $t6, 0x3ff
/* 0AC398 7F077868 00187B80 */  sll   $t7, $t8, 0xe
/* 0AC39C 7F07786C 01EAC825 */  or    $t9, $t7, $t2
/* 0AC3A0 7F077870 03257025 */  or    $t6, $t9, $a1
/* 0AC3A4 7F077874 AC8E0004 */  sw    $t6, 4($a0)
/* 0AC3A8 7F077878 8FB8016C */  lw    $t8, 0x16c($sp)
/* 0AC3AC 7F07787C 270F0008 */  addiu $t7, $t8, 8
/* 0AC3B0 7F077880 AFAF016C */  sw    $t7, 0x16c($sp)
/* 0AC3B4 7F077884 AF000004 */  sw    $zero, 4($t8)
/* 0AC3B8 7F077888 AF0C0000 */  sw    $t4, ($t8)
/* 0AC3BC 7F07788C 8FB9016C */  lw    $t9, 0x16c($sp)
/* 0AC3C0 7F077890 3C18BA00 */  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00         #
/* 0AC3C4 7F077894 37180E02 */  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02  #gDPSetTextureLUT()
/* 0AC3C8 7F077898 272E0008 */  addiu $t6, $t9, 8
/* 0AC3CC 7F07789C AFAE016C */  sw    $t6, 0x16c($sp)
/* 0AC3D0 7F0778A0 AF320004 */  sw    $s2, 4($t9)
/* 0AC3D4 7F0778A4 10000008 */  b     .L7F0778C8
/* 0AC3D8 7F0778A8 AF380000 */   sw    $t8, ($t9)
.L7F0778AC:
/* 0AC3DC 7F0778AC 8FAF016C */  lw    $t7, 0x16c($sp)
/* 0AC3E0 7F0778B0 3C0EBA00 */  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00         #
/* 0AC3E4 7F0778B4 35CE0E02 */  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02  #gDPSetTextureLUT()
/* 0AC3E8 7F0778B8 25F90008 */  addiu $t9, $t7, 8
/* 0AC3EC 7F0778BC AFB9016C */  sw    $t9, 0x16c($sp)
/* 0AC3F0 7F0778C0 ADE00004 */  sw    $zero, 4($t7)
/* 0AC3F4 7F0778C4 ADEE0000 */  sw    $t6, ($t7)
.L7F0778C8:
/* 0AC3F8 7F0778C8 8FB800CC */  lw    $t8, 0xcc($sp)
/* 0AC3FC 7F0778CC 8FA70180 */  lw    $a3, 0x180($sp)
/* 0AC400 7F0778D0 00008825 */  move  $s1, $zero
/* 0AC404 7F0778D4 1B0000AA */  blez  $t8, .L7F077B80
/* 0AC408 7F0778D8 30E40FFF */   andi  $a0, $a3, 0xfff
/* 0AC40C 7F0778DC 93B300CA */  lbu   $s3, 0xca($sp)
/* 0AC410 7F0778E0 00047B00 */  sll   $t7, $a0, 0xc
/* 0AC414 7F0778E4 3C01F200 */  lui   $at, 0xf200
/* 0AC418 7F0778E8 01E1C825 */  or    $t9, $t7, $at
/* 0AC41C 7F0778EC 03247025 */  or    $t6, $t9, $a0
/* 0AC420 7F0778F0 326F0003 */  andi  $t7, $s3, 3
/* 0AC424 7F0778F4 000FCCC0 */  sll   $t9, $t7, 0x13
/* 0AC428 7F0778F8 01399025 */  or    $s2, $t1, $t9
/* 0AC42C 7F0778FC AFAE0050 */  sw    $t6, 0x50($sp)
/* 0AC430 7F077900 8FB00064 */  lw    $s0, 0x64($sp)
.L7F077904:
/* 0AC434 7F077904 1A200018 */  blez  $s1, .L7F077968
/* 0AC438 7F077908 8FA70180 */   lw    $a3, 0x180($sp)
/* 0AC43C 7F07790C 12C0000F */  beqz  $s6, .L7F07794C
/* 0AC440 7F077910 2AA10002 */   slti  $at, $s5, 2
/* 0AC444 7F077914 8ECE000C */  lw    $t6, 0xc($s6)
/* 0AC448 7F077918 02C02025 */  move  $a0, $s6
/* 0AC44C 7F07791C 000E7880 */  sll   $t7, $t6, 2
/* 0AC450 7F077920 05E1000A */  bgez  $t7, .L7F07794C
/* 0AC454 7F077924 00000000 */   nop   
/* 0AC458 7F077928 0FC331C5 */  jal   texGetWidthAtLod
/* 0AC45C 7F07792C 02202825 */   move  $a1, $s1
/* 0AC460 7F077930 0040A825 */  move  $s5, $v0
/* 0AC464 7F077934 02C02025 */  move  $a0, $s6
/* 0AC468 7F077938 0FC331FF */  jal   texGetHeightAtLod
/* 0AC46C 7F07793C 02202825 */   move  $a1, $s1
/* 0AC470 7F077940 0040A025 */  move  $s4, $v0
/* 0AC474 7F077944 10000008 */  b     .L7F077968
/* 0AC478 7F077948 8FA70180 */   lw    $a3, 0x180($sp)
.L7F07794C:
/* 0AC47C 7F07794C 14200002 */  bnez  $at, .L7F077958
/* 0AC480 7F077950 0015C843 */   sra   $t9, $s5, 1
/* 0AC484 7F077954 0320A825 */  move  $s5, $t9
.L7F077958:
/* 0AC488 7F077958 2A810002 */  slti  $at, $s4, 2
/* 0AC48C 7F07795C 14200002 */  bnez  $at, .L7F077968
/* 0AC490 7F077960 00147043 */   sra   $t6, $s4, 1
/* 0AC494 7F077964 01C0A025 */  move  $s4, $t6
.L7F077968:
/* 0AC498 7F077968 26B8FFFF */  addiu $t8, $s5, -1
/* 0AC49C 7F07796C 00187880 */  sll   $t7, $t8, 2
/* 0AC4A0 7F077970 01E7C821 */  addu  $t9, $t7, $a3
/* 0AC4A4 7F077974 332E0FFF */  andi  $t6, $t9, 0xfff
/* 0AC4A8 7F077978 000EC300 */  sll   $t8, $t6, 0xc
/* 0AC4AC 7F07797C 268FFFFF */  addiu $t7, $s4, -1
/* 0AC4B0 7F077980 000FC880 */  sll   $t9, $t7, 2
/* 0AC4B4 7F077984 03277021 */  addu  $t6, $t9, $a3
/* 0AC4B8 7F077988 AFB80054 */  sw    $t8, 0x54($sp)
/* 0AC4BC 7F07798C 31D80FFF */  andi  $t8, $t6, 0xfff
/* 0AC4C0 7F077990 12600036 */  beqz  $s3, .L7F077A6C
/* 0AC4C4 7F077994 AFB8004C */   sw    $t8, 0x4c($sp)
/* 0AC4C8 7F077998 24010001 */  li    $at, 1
/* 0AC4CC 7F07799C 12610026 */  beq   $s3, $at, .L7F077A38
/* 0AC4D0 7F0779A0 24010002 */   li    $at, 2
/* 0AC4D4 7F0779A4 12610017 */  beq   $s3, $at, .L7F077A04
/* 0AC4D8 7F0779A8 24010003 */   li    $at, 3
/* 0AC4DC 7F0779AC 52610009 */  beql  $s3, $at, .L7F0779D4
/* 0AC4E0 7F0779B0 26B00003 */   addiu $s0, $s5, 3
/* 0AC4E4 7F0779B4 02140019 */  multu $s0, $s4
/* 0AC4E8 7F0779B8 320F01FF */  andi  $t7, $s0, 0x1ff
/* 0AC4EC 7F0779BC 000FCA40 */  sll   $t9, $t7, 9
/* 0AC4F0 7F0779C0 02591025 */  or    $v0, $s2, $t9
/* 0AC4F4 7F0779C4 00003012 */  mflo  $a2
/* 0AC4F8 7F0779C8 10000036 */  b     .L7F077AA4
/* 0AC4FC 7F0779CC 8FA3016C */   lw    $v1, 0x16c($sp)
/* 0AC500 7F0779D0 26B00003 */  addiu $s0, $s5, 3
.L7F0779D4:
/* 0AC504 7F0779D4 06010003 */  bgez  $s0, .L7F0779E4
/* 0AC508 7F0779D8 00107083 */   sra   $t6, $s0, 2
/* 0AC50C 7F0779DC 26010003 */  addiu $at, $s0, 3
/* 0AC510 7F0779E0 00017083 */  sra   $t6, $at, 2
.L7F0779E4:
/* 0AC514 7F0779E4 01D40019 */  multu $t6, $s4
/* 0AC518 7F0779E8 31D801FF */  andi  $t8, $t6, 0x1ff
/* 0AC51C 7F0779EC 00187A40 */  sll   $t7, $t8, 9
/* 0AC520 7F0779F0 01C08025 */  move  $s0, $t6
/* 0AC524 7F0779F4 024F1025 */  or    $v0, $s2, $t7
/* 0AC528 7F0779F8 00003012 */  mflo  $a2
/* 0AC52C 7F0779FC 10000029 */  b     .L7F077AA4
/* 0AC530 7F077A00 8FA3016C */   lw    $v1, 0x16c($sp)
.L7F077A04:
/* 0AC534 7F077A04 26B00003 */  addiu $s0, $s5, 3
/* 0AC538 7F077A08 06010003 */  bgez  $s0, .L7F077A18
/* 0AC53C 7F077A0C 0010C883 */   sra   $t9, $s0, 2
/* 0AC540 7F077A10 26010003 */  addiu $at, $s0, 3
/* 0AC544 7F077A14 0001C883 */  sra   $t9, $at, 2
.L7F077A18:
/* 0AC548 7F077A18 03340019 */  multu $t9, $s4
/* 0AC54C 7F077A1C 332E01FF */  andi  $t6, $t9, 0x1ff
/* 0AC550 7F077A20 000EC240 */  sll   $t8, $t6, 9
/* 0AC554 7F077A24 03208025 */  move  $s0, $t9
/* 0AC558 7F077A28 02581025 */  or    $v0, $s2, $t8
/* 0AC55C 7F077A2C 00003012 */  mflo  $a2
/* 0AC560 7F077A30 1000001C */  b     .L7F077AA4
/* 0AC564 7F077A34 8FA3016C */   lw    $v1, 0x16c($sp)
.L7F077A38:
/* 0AC568 7F077A38 26B00007 */  addiu $s0, $s5, 7
/* 0AC56C 7F077A3C 06010003 */  bgez  $s0, .L7F077A4C
/* 0AC570 7F077A40 001078C3 */   sra   $t7, $s0, 3
/* 0AC574 7F077A44 26010007 */  addiu $at, $s0, 7
/* 0AC578 7F077A48 000178C3 */  sra   $t7, $at, 3
.L7F077A4C:
/* 0AC57C 7F077A4C 01F40019 */  multu $t7, $s4
/* 0AC580 7F077A50 31F901FF */  andi  $t9, $t7, 0x1ff
/* 0AC584 7F077A54 00197240 */  sll   $t6, $t9, 9
/* 0AC588 7F077A58 01E08025 */  move  $s0, $t7
/* 0AC58C 7F077A5C 024E1025 */  or    $v0, $s2, $t6
/* 0AC590 7F077A60 00003012 */  mflo  $a2
/* 0AC594 7F077A64 1000000F */  b     .L7F077AA4
/* 0AC598 7F077A68 8FA3016C */   lw    $v1, 0x16c($sp)
.L7F077A6C:
/* 0AC59C 7F077A6C 26B0000F */  addiu $s0, $s5, 0xf
/* 0AC5A0 7F077A70 06010003 */  bgez  $s0, .L7F077A80
/* 0AC5A4 7F077A74 0010C103 */   sra   $t8, $s0, 4
/* 0AC5A8 7F077A78 2601000F */  addiu $at, $s0, 0xf
/* 0AC5AC 7F077A7C 0001C103 */  sra   $t8, $at, 4
.L7F077A80:
/* 0AC5B0 7F077A80 03140019 */  multu $t8, $s4
/* 0AC5B4 7F077A84 330F01FF */  andi  $t7, $t8, 0x1ff
/* 0AC5B8 7F077A88 000FCA40 */  sll   $t9, $t7, 9
/* 0AC5BC 7F077A8C 03008025 */  move  $s0, $t8
/* 0AC5C0 7F077A90 02591025 */  or    $v0, $s2, $t9
/* 0AC5C4 7F077A94 00003012 */  mflo  $a2
/* 0AC5C8 7F077A98 00000000 */  nop   
/* 0AC5CC 7F077A9C 00000000 */  nop   
/* 0AC5D0 7F077AA0 8FA3016C */  lw    $v1, 0x16c($sp)
.L7F077AA4:
/* 0AC5D4 7F077AA4 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0AC5D8 7F077AA8 02802025 */  move  $a0, $s4
/* 0AC5DC 7F077AAC 24780008 */  addiu $t8, $v1, 8
/* 0AC5E0 7F077AB0 31F901FF */  andi  $t9, $t7, 0x1ff
/* 0AC5E4 7F077AB4 00597025 */  or    $t6, $v0, $t9
/* 0AC5E8 7F077AB8 AFB8016C */  sw    $t8, 0x16c($sp)
/* 0AC5EC 7F077ABC AC6E0000 */  sw    $t6, ($v1)
/* 0AC5F0 7F077AC0 AFA6003C */  sw    $a2, 0x3c($sp)
/* 0AC5F4 7F077AC4 0FC1D968 */  jal   is_less_than_certain_power_of_2
/* 0AC5F8 7F077AC8 AFA30060 */   sw    $v1, 0x60($sp)
/* 0AC5FC 7F077ACC 02A02025 */  move  $a0, $s5
/* 0AC600 7F077AD0 0FC1D968 */  jal   is_less_than_certain_power_of_2
/* 0AC604 7F077AD4 AFA20058 */   sw    $v0, 0x58($sp)
/* 0AC608 7F077AD8 32230007 */  andi  $v1, $s1, 7
/* 0AC60C 7F077ADC 0003C600 */  sll   $t8, $v1, 0x18
/* 0AC610 7F077AE0 304F000F */  andi  $t7, $v0, 0xf
/* 0AC614 7F077AE4 000FC900 */  sll   $t9, $t7, 4
/* 0AC618 7F077AE8 03387025 */  or    $t6, $t9, $t8
/* 0AC61C 7F077AEC 03001825 */  move  $v1, $t8
/* 0AC620 7F077AF0 92F8000A */  lbu   $t8, 0xa($s7)
/* 0AC624 7F077AF4 8FA70058 */  lw    $a3, 0x58($sp)
/* 0AC628 7F077AF8 3224000F */  andi  $a0, $s1, 0xf
/* 0AC62C 7F077AFC 330F0003 */  andi  $t7, $t8, 3
/* 0AC630 7F077B00 000FCC80 */  sll   $t9, $t7, 0x12
/* 0AC634 7F077B04 01D9C025 */  or    $t8, $t6, $t9
/* 0AC638 7F077B08 30EF000F */  andi  $t7, $a3, 0xf
/* 0AC63C 7F077B0C 000F7380 */  sll   $t6, $t7, 0xe
/* 0AC640 7F077B10 030EC825 */  or    $t9, $t8, $t6
/* 0AC644 7F077B14 92EE0009 */  lbu   $t6, 9($s7)
/* 0AC648 7F077B18 00047A80 */  sll   $t7, $a0, 0xa
/* 0AC64C 7F077B1C 032FC025 */  or    $t8, $t9, $t7
/* 0AC650 7F077B20 31D90003 */  andi  $t9, $t6, 3
/* 0AC654 7F077B24 00197A00 */  sll   $t7, $t9, 8
/* 0AC658 7F077B28 030F7025 */  or    $t6, $t8, $t7
/* 0AC65C 7F077B2C 8FB80060 */  lw    $t8, 0x60($sp)
/* 0AC660 7F077B30 8FA6003C */  lw    $a2, 0x3c($sp)
/* 0AC664 7F077B34 01C4C825 */  or    $t9, $t6, $a0
/* 0AC668 7F077B38 AF190004 */  sw    $t9, 4($t8)
/* 0AC66C 7F077B3C 8FA5016C */  lw    $a1, 0x16c($sp)
/* 0AC670 7F077B40 8FB90050 */  lw    $t9, 0x50($sp)
/* 0AC674 7F077B44 26310001 */  addiu $s1, $s1, 1
/* 0AC678 7F077B48 24AE0008 */  addiu $t6, $a1, 8
/* 0AC67C 7F077B4C AFAE016C */  sw    $t6, 0x16c($sp)
/* 0AC680 7F077B50 ACB90000 */  sw    $t9, ($a1)
/* 0AC684 7F077B54 8FB80054 */  lw    $t8, 0x54($sp)
/* 0AC688 7F077B58 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0AC68C 7F077B5C 00787825 */  or    $t7, $v1, $t8
/* 0AC690 7F077B60 01EEC825 */  or    $t9, $t7, $t6
/* 0AC694 7F077B64 ACB90004 */  sw    $t9, 4($a1)
/* 0AC698 7F077B68 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0AC69C 7F077B6C 8FAE00CC */  lw    $t6, 0xcc($sp)
/* 0AC6A0 7F077B70 03067821 */  addu  $t7, $t8, $a2
/* 0AC6A4 7F077B74 162EFF63 */  bne   $s1, $t6, .L7F077904
/* 0AC6A8 7F077B78 AFAF00D0 */   sw    $t7, 0xd0($sp)
/* 0AC6AC 7F077B7C AFB00064 */  sw    $s0, 0x64($sp)
.L7F077B80:
/* 0AC6B0 7F077B80 8FB9016C */  lw    $t9, 0x16c($sp)
/* 0AC6B4 7F077B84 8FB80170 */  lw    $t8, 0x170($sp)
/* 0AC6B8 7F077B88 AF190000 */  sw    $t9, ($t8)
/* 0AC6BC 7F077B8C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0AC6C0 7F077B90 8FB70030 */  lw    $s7, 0x30($sp)
/* 0AC6C4 7F077B94 8FB6002C */  lw    $s6, 0x2c($sp)
/* 0AC6C8 7F077B98 8FB50028 */  lw    $s5, 0x28($sp)
/* 0AC6CC 7F077B9C 8FB40024 */  lw    $s4, 0x24($sp)
/* 0AC6D0 7F077BA0 8FB30020 */  lw    $s3, 0x20($sp)
/* 0AC6D4 7F077BA4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0AC6D8 7F077BA8 8FB10018 */  lw    $s1, 0x18($sp)
/* 0AC6DC 7F077BAC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0AC6E0 7F077BB0 03E00008 */  jr    $ra
/* 0AC6E4 7F077BB4 27BD0170 */   addiu $sp, $sp, 0x170
)
#endif





void sub_GAME_7F077BB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return;
}



