#include <ultra64.h>
#include "math_floor.h"
#include "math_ceil.h"
#include "quaternion.h"
#include "math_asinfacosf.h"
#include "math_unk_05A9E0.h"
#include "chrobjdata.h"
#include "ob.h"
#include "objecthandler.h"
#include "unk_0CC4C0.h"
#include "image.h"

//file split per EU
#ifdef NONMATCHING

/***
 * Perfect Dark:
 * void modeldef0f1a7560(struct modeldef *modeldef, u16 filenum, u32 arg2, struct modeldef *modeldef2, struct texpool *texpool, bool arg5)
 * 
 * NTSC address 0x7F0762E0.
*/
// https://decomp.me/scratch/9a4EO 69.88
void sub_GAME_7F0762E0(ModelFileHeader *arg0, char *arg1, void *arg2, s32 arg3)
{
    ModelNode *sp74;
    uintptr_t gdl; // sp6C
    uintptr_t sp58;
    ModelNode **sp54;
    s32 sp50;
    s32 temp_fp;
    s32 temp_s0;
    Gfx *var_s3;
    Gfx *temp_a0;
    uintptr_t temp_a2;
    uintptr_t temp_a1;
    s32 var_s1;
    s32 var_s2;
    
    sp54 = arg0->Switches;
    sp50 = fileGetIndex(arg1);
    temp_s0 = get_rom_remaining_buffer_for_index(sp50);
    temp_fp = get_pc_remaining_buffer_for_index(sp50);
    sp74 = NULL;
    modelIterateDisplayLists(arg0, &sp74, (Gfx**)&gdl);

    if (gdl)
    {
        var_s3 = gdl;

        //temp_a0 = ((s32)arg0->Switches + ((s32) gdl & 0xFFFFFF));
        temp_a2 = ((s32)temp_fp - (s32)((s32)arg0->Switches + ((s32) gdl & 0xFFFFFF))) + (s32)sp54;
        temp_a1 = ((s32)temp_s0 + (s32)sp54) - (s32)temp_a2;

        sp58 = (s32)temp_a1 - (s32)((s32)arg0->Switches + ((s32) gdl & 0xFFFFFF));
        
        // texCopyGdls
        sub_GAME_7F0CE794(((s32)arg0->Switches + ((s32) gdl & 0xFFFFFF)), temp_a1, (s32) temp_a2);
        
        texLoadFromModelFileHeader(arg0, arg3);

        while (sp74 != NULL)
        {
            modelIterateDisplayLists(arg0, &sp74, (Gfx**)&gdl);
            
            if (gdl)
            {
                var_s2 = (s32) gdl * 0;
                var_s1 = (s32) gdl & 0xFFFFFF;
            }
            else
            {
                var_s1 = (s32) gdl & 0xFFFFFF;
                var_s2 = (temp_fp + (s32)arg0->Switches - (s32)arg0->Switches) - (var_s1);
            }
            
            modelNodeReplaceGdl((u32) arg0, sp74, gdl, var_s3);
            
            var_s3 += texLoadFromGdl(
                (Gfx *)((uintptr_t)arg0->Switches + ((s32)(var_s1) + (s32)sp58)),
                var_s2,
                (Gfx *)((uintptr_t)arg0->Switches + ((s32) var_s3 & 0xFFFFFF)),
                arg3);
        }

        fileSetSize(
            sp50,
            (u8*)sp54,
            (((u32)((s32)arg0->Switches + ((s32) var_s3 & 0xFFFFFF)) - (u32)sp54) + 0xf) & ~0xf,
            arg2 == NULL);
    }
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0762E0
/* 0AAE10 7F0762E0 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0AAE14 7F0762E4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0AAE18 7F0762E8 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0AAE1C 7F0762EC AFB70034 */  sw    $s7, 0x34($sp)
/* 0AAE20 7F0762F0 AFB60030 */  sw    $s6, 0x30($sp)
/* 0AAE24 7F0762F4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0AAE28 7F0762F8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0AAE2C 7F0762FC AFB30024 */  sw    $s3, 0x24($sp)
/* 0AAE30 7F076300 AFB20020 */  sw    $s2, 0x20($sp)
/* 0AAE34 7F076304 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0AAE38 7F076308 AFB00018 */  sw    $s0, 0x18($sp)
/* 0AAE3C 7F07630C AFA60080 */  sw    $a2, 0x80($sp)
/* 0AAE40 7F076310 AFA70084 */  sw    $a3, 0x84($sp)
/* 0AAE44 7F076314 8C8E0008 */  lw    $t6, 8($a0)
/* 0AAE48 7F076318 0080A825 */  move  $s5, $a0
/* 0AAE4C 7F07631C 00A02025 */  move  $a0, $a1
/* 0AAE50 7F076320 0FC2F495 */  jal   fileGetIndex
/* 0AAE54 7F076324 AFAE0054 */   sw    $t6, 0x54($sp)
/* 0AAE58 7F076328 AFA20050 */  sw    $v0, 0x50($sp)
/* 0AAE5C 7F07632C 0FC2F447 */  jal   get_rom_remaining_buffer_for_index
/* 0AAE60 7F076330 00402025 */   move  $a0, $v0
/* 0AAE64 7F076334 00408025 */  move  $s0, $v0
/* 0AAE68 7F076338 0FC2F440 */  jal   get_pc_remaining_buffer_for_index
/* 0AAE6C 7F07633C 8FA40050 */   lw    $a0, 0x50($sp)
/* 0AAE70 7F076340 0040F025 */  move  $fp, $v0
/* 0AAE74 7F076344 AFA00074 */  sw    $zero, 0x74($sp)
/* 0AAE78 7F076348 02A02025 */  move  $a0, $s5
/* 0AAE7C 7F07634C 27A50074 */  addiu $a1, $sp, 0x74
/* 0AAE80 7F076350 0FC1D831 */  jal   modelIterateDisplayLists
/* 0AAE84 7F076354 27A6006C */   addiu $a2, $sp, 0x6c
/* 0AAE88 7F076358 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0AAE8C 7F07635C 3C1600FF */  lui   $s6, (0x00FFFFFF >> 16) # lui $s6, 0xff
/* 0AAE90 7F076360 36D6FFFF */  ori   $s6, (0x00FFFFFF & 0xFFFF) # ori $s6, $s6, 0xffff
/* 0AAE94 7F076364 12E00043 */  beqz  $s7, .L7F076474
/* 0AAE98 7F076368 8FA70054 */   lw    $a3, 0x54($sp)
/* 0AAE9C 7F07636C 8EAF0008 */  lw    $t7, 8($s5)
/* 0AAEA0 7F076370 02F6C824 */  and   $t9, $s7, $s6
/* 0AAEA4 7F076374 02074821 */  addu  $t1, $s0, $a3
/* 0AAEA8 7F076378 01F92021 */  addu  $a0, $t7, $t9
/* 0AAEAC 7F07637C 03C44023 */  subu  $t0, $fp, $a0
/* 0AAEB0 7F076380 01073021 */  addu  $a2, $t0, $a3
/* 0AAEB4 7F076384 01262823 */  subu  $a1, $t1, $a2
/* 0AAEB8 7F076388 00A45023 */  subu  $t2, $a1, $a0
/* 0AAEBC 7F07638C 02E09825 */  move  $s3, $s7
/* 0AAEC0 7F076390 0FC339E5 */  jal   texCopyGdls
/* 0AAEC4 7F076394 AFAA0058 */   sw    $t2, 0x58($sp)
/* 0AAEC8 7F076398 02A02025 */  move  $a0, $s5
/* 0AAECC 7F07639C 0FC32F94 */  jal   texLoadFromModelFileHeader
/* 0AAED0 7F0763A0 8FA50084 */   lw    $a1, 0x84($sp)
/* 0AAED4 7F0763A4 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0AAED8 7F0763A8 51600025 */  beql  $t3, $zero, .L7F076440
/* 0AAEDC 7F0763AC 8EAA0008 */   lw    $t2, 8($s5)
/* 0AAEE0 7F0763B0 8FB0006C */  lw    $s0, 0x6c($sp)
.L7F0763B4:
/* 0AAEE4 7F0763B4 8FB40074 */  lw    $s4, 0x74($sp)
/* 0AAEE8 7F0763B8 02A02025 */  move  $a0, $s5
/* 0AAEEC 7F0763BC 27A50074 */  addiu $a1, $sp, 0x74
/* 0AAEF0 7F0763C0 0FC1D831 */  jal   modelIterateDisplayLists
/* 0AAEF4 7F0763C4 27A6006C */   addiu $a2, $sp, 0x6c
/* 0AAEF8 7F0763C8 8FB7006C */  lw    $s7, 0x6c($sp)
/* 0AAEFC 7F0763CC 02A02025 */  move  $a0, $s5
/* 0AAF00 7F0763D0 02802825 */  move  $a1, $s4
/* 0AAF04 7F0763D4 12E00004 */  beqz  $s7, .L7F0763E8
/* 0AAF08 7F0763D8 02003025 */   move  $a2, $s0
/* 0AAF0C 7F0763DC 02F09023 */  subu  $s2, $s7, $s0
/* 0AAF10 7F0763E0 10000007 */  b     .L7F076400
/* 0AAF14 7F0763E4 02168824 */   and   $s1, $s0, $s6
.L7F0763E8:
/* 0AAF18 7F0763E8 8FAC0054 */  lw    $t4, 0x54($sp)
/* 0AAF1C 7F0763EC 8EAE0008 */  lw    $t6, 8($s5)
/* 0AAF20 7F0763F0 02168824 */  and   $s1, $s0, $s6
/* 0AAF24 7F0763F4 019E6821 */  addu  $t5, $t4, $fp
/* 0AAF28 7F0763F8 01AEC023 */  subu  $t8, $t5, $t6
/* 0AAF2C 7F0763FC 03119023 */  subu  $s2, $t8, $s1
.L7F076400:
/* 0AAF30 7F076400 0FC1D88F */  jal   modelNodeReplaceGdl
/* 0AAF34 7F076404 02603825 */   move  $a3, $s3
/* 0AAF38 7F076408 8EA20008 */  lw    $v0, 8($s5)
/* 0AAF3C 7F07640C 8FB90058 */  lw    $t9, 0x58($sp)
/* 0AAF40 7F076410 02764024 */  and   $t0, $s3, $s6
/* 0AAF44 7F076414 00517821 */  addu  $t7, $v0, $s1
/* 0AAF48 7F076418 02402825 */  move  $a1, $s2
/* 0AAF4C 7F07641C 8FA70084 */  lw    $a3, 0x84($sp)
/* 0AAF50 7F076420 00483021 */  addu  $a2, $v0, $t0
/* 0AAF54 7F076424 0FC33846 */  jal   texLoadFromGdl
/* 0AAF58 7F076428 01F92021 */   addu  $a0, $t7, $t9
/* 0AAF5C 7F07642C 8FA90074 */  lw    $t1, 0x74($sp)
/* 0AAF60 7F076430 02629821 */  addu  $s3, $s3, $v0
/* 0AAF64 7F076434 5520FFDF */  bnezl $t1, .L7F0763B4
/* 0AAF68 7F076438 8FB0006C */   lw    $s0, 0x6c($sp)
/* 0AAF6C 7F07643C 8EAA0008 */  lw    $t2, 8($s5)
.L7F076440:
/* 0AAF70 7F076440 8FA50054 */  lw    $a1, 0x54($sp)
/* 0AAF74 7F076444 02765824 */  and   $t3, $s3, $s6
/* 0AAF78 7F076448 8FA70080 */  lw    $a3, 0x80($sp)
/* 0AAF7C 7F07644C 014B6021 */  addu  $t4, $t2, $t3
/* 0AAF80 7F076450 01859023 */  subu  $s2, $t4, $a1
/* 0AAF84 7F076454 2646000F */  addiu $a2, $s2, 0xf
/* 0AAF88 7F076458 2401FFF0 */  li    $at, -16
/* 0AAF8C 7F07645C 00C16824 */  and   $t5, $a2, $at
/* 0AAF90 7F076460 2CEE0001 */  sltiu $t6, $a3, 1
/* 0AAF94 7F076464 01C03825 */  move  $a3, $t6
/* 0AAF98 7F076468 01A03025 */  move  $a2, $t5
/* 0AAF9C 7F07646C 0FC2F44E */  jal   fileSetSize
/* 0AAFA0 7F076470 8FA40050 */   lw    $a0, 0x50($sp)
.L7F076474:
/* 0AAFA4 7F076474 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0AAFA8 7F076478 8FB00018 */  lw    $s0, 0x18($sp)
/* 0AAFAC 7F07647C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0AAFB0 7F076480 8FB20020 */  lw    $s2, 0x20($sp)
/* 0AAFB4 7F076484 8FB30024 */  lw    $s3, 0x24($sp)
/* 0AAFB8 7F076488 8FB40028 */  lw    $s4, 0x28($sp)
/* 0AAFBC 7F07648C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0AAFC0 7F076490 8FB60030 */  lw    $s6, 0x30($sp)
/* 0AAFC4 7F076494 8FB70034 */  lw    $s7, 0x34($sp)
/* 0AAFC8 7F076498 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0AAFCC 7F07649C 03E00008 */  jr    $ra
/* 0AAFD0 7F0764A0 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif




/***
 * NTSC addres 0x7F0764A4.
*/
void load_object_fill_header(struct ModelFileHeader *objheader, u8 *name, u8* dst, s32 size, struct texpool * buffer)
{
    void *filedata;

    if (dst != 0)
    {
        filedata = _fileNameLoadToAddr(name, 0, dst, size);
    }
    else
    {
        filedata = _fileNameLoadToBank(name, 0, 0x100, 4);
    }
    
    objheader->Switches = (struct ModelNode **)filedata;
    
    // hmmmmmmmmmmmm
    objheader->Textures = (struct ModelFileTextures *)&((s32*)filedata)[objheader->numSwitches];
    
    objheader->RootNode = (struct ModelNode *)&objheader->Textures[objheader->numtextures];
    
    sub_GAME_7F075A90(objheader, 0x5000000, filedata);
    sub_GAME_7F0762E0(objheader, name, dst, buffer);
}




void fileLoad(struct ModelFileHeader *header,char *name)
{
   load_object_fill_header(header,name,0,0,0);
   return;
}


void load_object_into_memory_unused_maybe(struct ModelFileHeader *header,int *recallstring,int *targetloc,int sizeleft)
{
   load_object_fill_header(header,recallstring,targetloc,sizeleft,0);
   return;
}





