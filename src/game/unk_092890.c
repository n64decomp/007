#include <ultra64.h>


#ifdef NONMATCHING
void sub_GAME_7F092890(void) {

    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 temp_f10;
    f64 temp_f10_2;
    f64 temp_f12;
    f64 temp_f12_2;
    f64 temp_f14;
    f64 temp_f16;
    f64 temp_f18;
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f24;
    f64 temp_f26;
    f64 temp_f28;
    f64 temp_f2;
    f64 temp_f30;
    f64 temp_f4;
    f64 temp_f4_2;
    f64 temp_f6;
    f64 temp_f6_2;
    f64 temp_f6_3;
    f64 temp_f6_4;
    f64 temp_f8;
    f64 temp_f8_2;
    f64 temp_f8_3;
    f64 temp_f8_4;
    f64 temp_f8_5;
    f64 phi_f0;
    f64 phi_f2;

    sp90 = (f64) arg3->unk0;
    temp_f6 = (f64) arg3->unk4;
    sp98 = temp_f6;
    temp_f8 = (f64) arg3->unk8;
    spA0 = temp_f8;
    temp_f6_2 = (f64) arg6->unk0;
    sp78 = temp_f6_2;
    temp_f8_2 = (f64) arg6->unk4;
    sp80 = temp_f8_2;
    temp_f4 = (f64) arg6->unk8;
    sp88 = temp_f4;
    sp60 = (f64) arg5->unk0;
    sp68 = (f64) arg5->unk4;
    sp70 = (f64) arg5->unk8;
    temp_f10 = (f64) (arg1->unk0 - arg0->unk0);
    sp140 = temp_f10;
    sp38 = temp_f6_2;
    temp_f6_3 = (f64) (arg2->unk0 - arg1->unk0);
    sp128 = temp_f6_3;
    sp40 = temp_f8_2;
    temp_f8_3 = (f64) (arg1->unk2 - arg0->unk2);
    sp148 = temp_f8_3;
    temp_f8_4 = (f64) (arg2->unk2 - arg1->unk2);
    sp130 = temp_f8_4;
    temp_f8_5 = (f64) (arg1->unk4 - arg0->unk4);
    sp150 = temp_f8_5;
    sp138 = (f64) (arg2->unk4 - arg1->unk4);
    sp110 = (f64) (arg2->unk0 - arg0->unk0);
    sp118 = (f64) (arg2->unk2 - arg0->unk2);
    sp48 = temp_f4;
    sp120 = (f64) (arg2->unk4 - arg0->unk4);
    temp_f18 = temp_f8_3 * sp138;
    temp_f20 = temp_f8_5 * sp130;
    temp_f22 = temp_f8_5 * temp_f6_3;
    temp_f24 = temp_f10 * sp138;
    temp_f12 = temp_f18 - temp_f20;
    temp_f26 = temp_f10 * temp_f8_4;
    temp_f28 = sp148 * temp_f6_3;
    temp_f14 = temp_f22 - temp_f24;
    temp_f16 = temp_f26 - temp_f28;
    spF8 = temp_f16;
    sp100 = temp_f14;
    sp108 = temp_f12;
    spF0 = ((temp_f8 + (f64) arg0->unk4) * temp_f16) + ((temp_f12 * ((f64) arg0->unk0 + sp90)) + (temp_f14 * ((f64) arg0->unk2 + temp_f6)));
    if (((sp48 * temp_f16) + ((temp_f12 * sp38) + (temp_f14 * sp40))) == 0.0) {
        return 0;
    }
    sp48 = sp60;
    temp_f30 = temp_f28 - temp_f26;
    sp40 = sp68;
    sp38 = sp70;
    sp50 = ((spF0 - (temp_f12 * sp60)) - (temp_f14 * sp68)) - (sp70 * temp_f16);
    sp58 = sp78;
    temp_f2 = sp50 / ((sp88 * temp_f16) + ((temp_f12 * sp78) + (temp_f14 * sp80)));
    temp_f6_4 = (sp58 * temp_f2) + sp48;
    spC8 = temp_f6_4;
    temp_f10_2 = (sp80 * temp_f2) + sp40;
    spD0 = temp_f10_2;
    temp_f4_2 = (sp88 * temp_f2) + sp38;
    spD8 = temp_f4_2;
    sp58 = temp_f10_2;
    spB0 = temp_f6_4 - (sp90 + (f64) arg0->unk0);
    spB8 = sp58 - (sp98 + (f64) arg0->unk2);
    spC0 = temp_f4_2 - (spA0 + (f64) arg0->unk4);
    if (temp_f30 != 0.0) {
        phi_f2 = ((spB0 * sp148) - (sp140 * spB8)) / temp_f30;
    } else {
        temp_f12_2 = temp_f20 - temp_f18;
        if (temp_f12_2 != 0.0) {
            phi_f2 = ((spB8 * sp150) - (sp148 * spC0)) / temp_f12_2;
        } else {
            phi_f2 = ((spC0 * sp140) - (sp150 * spB0)) / (temp_f24 - temp_f22);
        }
    }
    if (sp140 != 0.0) {
        phi_f0 = (spB0 - (phi_f2 * sp110)) / sp140;
    } else if (sp148 != 0.0) {
        phi_f0 = (spB8 - (phi_f2 * sp118)) / sp148;
    } else {
        phi_f0 = (spC0 - (phi_f2 * sp120)) / sp150;
    }
    if ((phi_f0 >= 0.0) && (phi_f2 >= 0.0) && ((phi_f0 + phi_f2) <= 1.0)) {
        if ((((spD8 - (f64) arg4->unk8) * sp88) + ((sp78 * (spC8 - (f64) arg4->unk0)) + (sp80 * (spD0 - (f64) arg4->unk4)))) >= 0.0) {
            arg7->unk0 = (f32) spC8;
            arg7->unk4 = (f32) spD0;
            arg7->unk8 = (f32) spD8;
            arg7->unkC = (f32) sp108;
            arg7->unk10 = (f32) sp100;
            arg7->unk2A = 0;
            arg7->unk14 = (f32) spF8;
            return 1;
        }
        /* Duplicate return node #18. Try simplifying control flow for better match */
        return 0;
    }
    return 0;


}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F092890
/* 0C73C0 7F092890 27BDFEA8 */  addiu $sp, $sp, -0x158
/* 0C73C4 7F092894 F7BE0030 */  sdc1  $f30, 0x30($sp)
/* 0C73C8 7F092898 F7BC0028 */  sdc1  $f28, 0x28($sp)
/* 0C73CC 7F09289C F7BA0020 */  sdc1  $f26, 0x20($sp)
/* 0C73D0 7F0928A0 F7B80018 */  sdc1  $f24, 0x18($sp)
/* 0C73D4 7F0928A4 F7B60010 */  sdc1  $f22, 0x10($sp)
/* 0C73D8 7F0928A8 F7B40008 */  sdc1  $f20, 8($sp)
/* 0C73DC 7F0928AC C4E40000 */  lwc1  $f4, ($a3)
/* 0C73E0 7F0928B0 8FA90170 */  lw    $t1, 0x170($sp)
/* 0C73E4 7F0928B4 8FAA016C */  lw    $t2, 0x16c($sp)
/* 0C73E8 7F0928B8 46002221 */  cvt.d.s $f8, $f4
/* 0C73EC 7F0928BC F7A80090 */  sdc1  $f8, 0x90($sp)
/* 0C73F0 7F0928C0 C4EA0004 */  lwc1  $f10, 4($a3)
/* 0C73F4 7F0928C4 460051A1 */  cvt.d.s $f6, $f10
/* 0C73F8 7F0928C8 F7A60098 */  sdc1  $f6, 0x98($sp)
/* 0C73FC 7F0928CC C4E40008 */  lwc1  $f4, 8($a3)
/* 0C7400 7F0928D0 46002221 */  cvt.d.s $f8, $f4
/* 0C7404 7F0928D4 F7A800A0 */  sdc1  $f8, 0xa0($sp)
/* 0C7408 7F0928D8 C52A0000 */  lwc1  $f10, ($t1)
/* 0C740C 7F0928DC 460051A1 */  cvt.d.s $f6, $f10
/* 0C7410 7F0928E0 F7A60078 */  sdc1  $f6, 0x78($sp)
/* 0C7414 7F0928E4 C5240004 */  lwc1  $f4, 4($t1)
/* 0C7418 7F0928E8 46002221 */  cvt.d.s $f8, $f4
/* 0C741C 7F0928EC F7A80080 */  sdc1  $f8, 0x80($sp)
/* 0C7420 7F0928F0 C52A0008 */  lwc1  $f10, 8($t1)
/* 0C7424 7F0928F4 46005121 */  cvt.d.s $f4, $f10
/* 0C7428 7F0928F8 F7A40088 */  sdc1  $f4, 0x88($sp)
/* 0C742C 7F0928FC C54A0000 */  lwc1  $f10, ($t2)
/* 0C7430 7F092900 460052A1 */  cvt.d.s $f10, $f10
/* 0C7434 7F092904 F7AA0060 */  sdc1  $f10, 0x60($sp)
/* 0C7438 7F092908 C54A0004 */  lwc1  $f10, 4($t2)
/* 0C743C 7F09290C 460052A1 */  cvt.d.s $f10, $f10
/* 0C7440 7F092910 F7AA0068 */  sdc1  $f10, 0x68($sp)
/* 0C7444 7F092914 C54A0008 */  lwc1  $f10, 8($t2)
/* 0C7448 7F092918 460052A1 */  cvt.d.s $f10, $f10
/* 0C744C 7F09291C F7AA0070 */  sdc1  $f10, 0x70($sp)
/* 0C7450 7F092920 848C0000 */  lh    $t4, ($a0)
/* 0C7454 7F092924 84AB0000 */  lh    $t3, ($a1)
/* 0C7458 7F092928 016C6823 */  subu  $t5, $t3, $t4
/* 0C745C 7F09292C 448D5000 */  mtc1  $t5, $f10
/* 0C7460 7F092930 00000000 */  nop   
/* 0C7464 7F092934 468052A1 */  cvt.d.w $f10, $f10
/* 0C7468 7F092938 F7AA0140 */  sdc1  $f10, 0x140($sp)
/* 0C746C 7F09293C 84CE0000 */  lh    $t6, ($a2)
/* 0C7470 7F092940 84AF0000 */  lh    $t7, ($a1)
/* 0C7474 7F092944 F7A60038 */  sdc1  $f6, 0x38($sp)
/* 0C7478 7F092948 01CFC023 */  subu  $t8, $t6, $t7
/* 0C747C 7F09294C 44983000 */  mtc1  $t8, $f6
/* 0C7480 7F092950 00000000 */  nop   
/* 0C7484 7F092954 468031A1 */  cvt.d.w $f6, $f6
/* 0C7488 7F092958 F7A60128 */  sdc1  $f6, 0x128($sp)
/* 0C748C 7F09295C 84880002 */  lh    $t0, 2($a0)
/* 0C7490 7F092960 84B90002 */  lh    $t9, 2($a1)
/* 0C7494 7F092964 F7A80040 */  sdc1  $f8, 0x40($sp)
/* 0C7498 7F092968 03284823 */  subu  $t1, $t9, $t0
/* 0C749C 7F09296C 44894000 */  mtc1  $t1, $f8
/* 0C74A0 7F092970 00000000 */  nop   
/* 0C74A4 7F092974 46804221 */  cvt.d.w $f8, $f8
/* 0C74A8 7F092978 F7A80148 */  sdc1  $f8, 0x148($sp)
/* 0C74AC 7F09297C 84CA0002 */  lh    $t2, 2($a2)
/* 0C74B0 7F092980 84AB0002 */  lh    $t3, 2($a1)
/* 0C74B4 7F092984 014B6023 */  subu  $t4, $t2, $t3
/* 0C74B8 7F092988 448C4000 */  mtc1  $t4, $f8
/* 0C74BC 7F09298C 00000000 */  nop   
/* 0C74C0 7F092990 46804221 */  cvt.d.w $f8, $f8
/* 0C74C4 7F092994 F7A80130 */  sdc1  $f8, 0x130($sp)
/* 0C74C8 7F092998 848E0004 */  lh    $t6, 4($a0)
/* 0C74CC 7F09299C 84AD0004 */  lh    $t5, 4($a1)
/* 0C74D0 7F0929A0 01AE7823 */  subu  $t7, $t5, $t6
/* 0C74D4 7F0929A4 448F4000 */  mtc1  $t7, $f8
/* 0C74D8 7F0929A8 00000000 */  nop   
/* 0C74DC 7F0929AC 46804221 */  cvt.d.w $f8, $f8
/* 0C74E0 7F0929B0 F7A80150 */  sdc1  $f8, 0x150($sp)
/* 0C74E4 7F0929B4 84D80004 */  lh    $t8, 4($a2)
/* 0C74E8 7F0929B8 84B90004 */  lh    $t9, 4($a1)
/* 0C74EC 7F0929BC 03194023 */  subu  $t0, $t8, $t9
/* 0C74F0 7F0929C0 44884000 */  mtc1  $t0, $f8
/* 0C74F4 7F0929C4 00000000 */  nop   
/* 0C74F8 7F0929C8 46804221 */  cvt.d.w $f8, $f8
/* 0C74FC 7F0929CC F7A80138 */  sdc1  $f8, 0x138($sp)
/* 0C7500 7F0929D0 848A0000 */  lh    $t2, ($a0)
/* 0C7504 7F0929D4 84C90000 */  lh    $t1, ($a2)
/* 0C7508 7F0929D8 012A5823 */  subu  $t3, $t1, $t2
/* 0C750C 7F0929DC 448B4000 */  mtc1  $t3, $f8
/* 0C7510 7F0929E0 00000000 */  nop   
/* 0C7514 7F0929E4 46804221 */  cvt.d.w $f8, $f8
/* 0C7518 7F0929E8 F7A80110 */  sdc1  $f8, 0x110($sp)
/* 0C751C 7F0929EC 848D0002 */  lh    $t5, 2($a0)
/* 0C7520 7F0929F0 84CC0002 */  lh    $t4, 2($a2)
/* 0C7524 7F0929F4 018D7023 */  subu  $t6, $t4, $t5
/* 0C7528 7F0929F8 448E4000 */  mtc1  $t6, $f8
/* 0C752C 7F0929FC 00000000 */  nop   
/* 0C7530 7F092A00 46804221 */  cvt.d.w $f8, $f8
/* 0C7534 7F092A04 F7A80118 */  sdc1  $f8, 0x118($sp)
/* 0C7538 7F092A08 84980004 */  lh    $t8, 4($a0)
/* 0C753C 7F092A0C 84CF0004 */  lh    $t7, 4($a2)
/* 0C7540 7F092A10 F7A40048 */  sdc1  $f4, 0x48($sp)
/* 0C7544 7F092A14 D7A40138 */  ldc1  $f4, 0x138($sp)
/* 0C7548 7F092A18 01F8C823 */  subu  $t9, $t7, $t8
/* 0C754C 7F092A1C 44994000 */  mtc1  $t9, $f8
/* 0C7550 7F092A20 00000000 */  nop   
/* 0C7554 7F092A24 46804221 */  cvt.d.w $f8, $f8
/* 0C7558 7F092A28 F7A80120 */  sdc1  $f8, 0x120($sp)
/* 0C755C 7F092A2C D7A80148 */  ldc1  $f8, 0x148($sp)
/* 0C7560 7F092A30 46244482 */  mul.d $f18, $f8, $f4
/* 0C7564 7F092A34 D7A40130 */  ldc1  $f4, 0x130($sp)
/* 0C7568 7F092A38 D7A80150 */  ldc1  $f8, 0x150($sp)
/* 0C756C 7F092A3C 46244502 */  mul.d $f20, $f8, $f4
/* 0C7570 7F092A40 D7A40138 */  ldc1  $f4, 0x138($sp)
/* 0C7574 7F092A44 46264582 */  mul.d $f22, $f8, $f6
/* 0C7578 7F092A48 D7A80130 */  ldc1  $f8, 0x130($sp)
/* 0C757C 7F092A4C 46245602 */  mul.d $f24, $f10, $f4
/* 0C7580 7F092A50 D7A40148 */  ldc1  $f4, 0x148($sp)
/* 0C7584 7F092A54 46349301 */  sub.d $f12, $f18, $f20
/* 0C7588 7F092A58 46285682 */  mul.d $f26, $f10, $f8
/* 0C758C 7F092A5C 00000000 */  nop   
/* 0C7590 7F092A60 46262702 */  mul.d $f28, $f4, $f6
/* 0C7594 7F092A64 D7A40090 */  ldc1  $f4, 0x90($sp)
/* 0C7598 7F092A68 4638B381 */  sub.d $f14, $f22, $f24
/* 0C759C 7F092A6C 463CD401 */  sub.d $f16, $f26, $f28
/* 0C75A0 7F092A70 F7B000F8 */  sdc1  $f16, 0xf8($sp)
/* 0C75A4 7F092A74 84880000 */  lh    $t0, ($a0)
/* 0C75A8 7F092A78 84890002 */  lh    $t1, 2($a0)
/* 0C75AC 7F092A7C 848A0004 */  lh    $t2, 4($a0)
/* 0C75B0 7F092A80 44885000 */  mtc1  $t0, $f10
/* 0C75B4 7F092A84 F7AE0100 */  sdc1  $f14, 0x100($sp)
/* 0C75B8 7F092A88 F7AC0108 */  sdc1  $f12, 0x108($sp)
/* 0C75BC 7F092A8C 46805221 */  cvt.d.w $f8, $f10
/* 0C75C0 7F092A90 46244180 */  add.d $f6, $f8, $f4
/* 0C75C4 7F092A94 44894000 */  mtc1  $t1, $f8
/* 0C75C8 7F092A98 00000000 */  nop   
/* 0C75CC 7F092A9C 46804121 */  cvt.d.w $f4, $f8
/* 0C75D0 7F092AA0 46266282 */  mul.d $f10, $f12, $f6
/* 0C75D4 7F092AA4 D7A60098 */  ldc1  $f6, 0x98($sp)
/* 0C75D8 7F092AA8 46262200 */  add.d $f8, $f4, $f6
/* 0C75DC 7F092AAC 46287102 */  mul.d $f4, $f14, $f8
/* 0C75E0 7F092AB0 D7A800A0 */  ldc1  $f8, 0xa0($sp)
/* 0C75E4 7F092AB4 46245180 */  add.d $f6, $f10, $f4
/* 0C75E8 7F092AB8 448A5000 */  mtc1  $t2, $f10
/* 0C75EC 7F092ABC 00000000 */  nop   
/* 0C75F0 7F092AC0 46805121 */  cvt.d.w $f4, $f10
/* 0C75F4 7F092AC4 46244280 */  add.d $f10, $f8, $f4
/* 0C75F8 7F092AC8 D7A80048 */  ldc1  $f8, 0x48($sp)
/* 0C75FC 7F092ACC 46305102 */  mul.d $f4, $f10, $f16
/* 0C7600 7F092AD0 46262280 */  add.d $f10, $f4, $f6
/* 0C7604 7F092AD4 46304182 */  mul.d $f6, $f8, $f16
/* 0C7608 7F092AD8 D7A40040 */  ldc1  $f4, 0x40($sp)
/* 0C760C 7F092ADC F7AA00F0 */  sdc1  $f10, 0xf0($sp)
/* 0C7610 7F092AE0 D7AA0038 */  ldc1  $f10, 0x38($sp)
/* 0C7614 7F092AE4 462A6202 */  mul.d $f8, $f12, $f10
/* 0C7618 7F092AE8 00000000 */  nop   
/* 0C761C 7F092AEC 46247282 */  mul.d $f10, $f14, $f4
/* 0C7620 7F092AF0 462A4100 */  add.d $f4, $f8, $f10
/* 0C7624 7F092AF4 44804000 */  mtc1  $zero, $f8
/* 0C7628 7F092AF8 44804800 */  mtc1  $zero, $f9
/* 0C762C 7F092AFC 46243000 */  add.d $f0, $f6, $f4
/* 0C7630 7F092B00 D7A60060 */  ldc1  $f6, 0x60($sp)
/* 0C7634 7F092B04 46280032 */  c.eq.d $f0, $f8
/* 0C7638 7F092B08 00000000 */  nop   
/* 0C763C 7F092B0C 45000003 */  bc1f  .L7F092B1C
/* 0C7640 7F092B10 00000000 */   nop   
/* 0C7644 7F092B14 100000C5 */  b     .L7F092E2C
/* 0C7648 7F092B18 00001025 */   move  $v0, $zero
.L7F092B1C:
/* 0C764C 7F092B1C 46266102 */  mul.d $f4, $f12, $f6
/* 0C7650 7F092B20 D7AA00F0 */  ldc1  $f10, 0xf0($sp)
/* 0C7654 7F092B24 F7A60048 */  sdc1  $f6, 0x48($sp)
/* 0C7658 7F092B28 463AE781 */  sub.d $f30, $f28, $f26
/* 0C765C 7F092B2C 00001025 */  move  $v0, $zero
/* 0C7660 7F092B30 46245201 */  sub.d $f8, $f10, $f4
/* 0C7664 7F092B34 D7AA0068 */  ldc1  $f10, 0x68($sp)
/* 0C7668 7F092B38 462A7102 */  mul.d $f4, $f14, $f10
/* 0C766C 7F092B3C F7AA0040 */  sdc1  $f10, 0x40($sp)
/* 0C7670 7F092B40 46244201 */  sub.d $f8, $f8, $f4
/* 0C7674 7F092B44 D7A40070 */  ldc1  $f4, 0x70($sp)
/* 0C7678 7F092B48 46302182 */  mul.d $f6, $f4, $f16
/* 0C767C 7F092B4C F7A40038 */  sdc1  $f4, 0x38($sp)
/* 0C7680 7F092B50 D7A40080 */  ldc1  $f4, 0x80($sp)
/* 0C7684 7F092B54 46264201 */  sub.d $f8, $f8, $f6
/* 0C7688 7F092B58 D7A60078 */  ldc1  $f6, 0x78($sp)
/* 0C768C 7F092B5C 46266282 */  mul.d $f10, $f12, $f6
/* 0C7690 7F092B60 F7A80050 */  sdc1  $f8, 0x50($sp)
/* 0C7694 7F092B64 F7A60058 */  sdc1  $f6, 0x58($sp)
/* 0C7698 7F092B68 46247202 */  mul.d $f8, $f14, $f4
/* 0C769C 7F092B6C D7AE0148 */  ldc1  $f14, 0x148($sp)
/* 0C76A0 7F092B70 46285280 */  add.d $f10, $f10, $f8
/* 0C76A4 7F092B74 D7A80088 */  ldc1  $f8, 0x88($sp)
/* 0C76A8 7F092B78 46304182 */  mul.d $f6, $f8, $f16
/* 0C76AC 7F092B7C 44808000 */  mtc1  $zero, $f16
/* 0C76B0 7F092B80 44808800 */  mtc1  $zero, $f17
/* 0C76B4 7F092B84 462A3180 */  add.d $f6, $f6, $f10
/* 0C76B8 7F092B88 D7AA0050 */  ldc1  $f10, 0x50($sp)
/* 0C76BC 7F092B8C 46265083 */  div.d $f2, $f10, $f6
/* 0C76C0 7F092B90 D7AA0058 */  ldc1  $f10, 0x58($sp)
/* 0C76C4 7F092B94 46225182 */  mul.d $f6, $f10, $f2
/* 0C76C8 7F092B98 D7AA0048 */  ldc1  $f10, 0x48($sp)
/* 0C76CC 7F092B9C 462A3180 */  add.d $f6, $f6, $f10
/* 0C76D0 7F092BA0 46222282 */  mul.d $f10, $f4, $f2
/* 0C76D4 7F092BA4 D7A40040 */  ldc1  $f4, 0x40($sp)
/* 0C76D8 7F092BA8 F7A600C8 */  sdc1  $f6, 0xc8($sp)
/* 0C76DC 7F092BAC 46245280 */  add.d $f10, $f10, $f4
/* 0C76E0 7F092BB0 46224102 */  mul.d $f4, $f8, $f2
/* 0C76E4 7F092BB4 D7A80038 */  ldc1  $f8, 0x38($sp)
/* 0C76E8 7F092BB8 F7AA00D0 */  sdc1  $f10, 0xd0($sp)
/* 0C76EC 7F092BBC 46282100 */  add.d $f4, $f4, $f8
/* 0C76F0 7F092BC0 D7A80090 */  ldc1  $f8, 0x90($sp)
/* 0C76F4 7F092BC4 F7A400D8 */  sdc1  $f4, 0xd8($sp)
/* 0C76F8 7F092BC8 848B0000 */  lh    $t3, ($a0)
/* 0C76FC 7F092BCC F7AA0058 */  sdc1  $f10, 0x58($sp)
/* 0C7700 7F092BD0 448B5000 */  mtc1  $t3, $f10
/* 0C7704 7F092BD4 00000000 */  nop   
/* 0C7708 7F092BD8 468052A1 */  cvt.d.w $f10, $f10
/* 0C770C 7F092BDC 462A4200 */  add.d $f8, $f8, $f10
/* 0C7710 7F092BE0 46283281 */  sub.d $f10, $f6, $f8
/* 0C7714 7F092BE4 D7A80098 */  ldc1  $f8, 0x98($sp)
/* 0C7718 7F092BE8 D7A60058 */  ldc1  $f6, 0x58($sp)
/* 0C771C 7F092BEC F7AA00B0 */  sdc1  $f10, 0xb0($sp)
/* 0C7720 7F092BF0 848C0002 */  lh    $t4, 2($a0)
/* 0C7724 7F092BF4 448C5000 */  mtc1  $t4, $f10
/* 0C7728 7F092BF8 00000000 */  nop   
/* 0C772C 7F092BFC 468052A1 */  cvt.d.w $f10, $f10
/* 0C7730 7F092C00 462A4200 */  add.d $f8, $f8, $f10
/* 0C7734 7F092C04 46283281 */  sub.d $f10, $f6, $f8
/* 0C7738 7F092C08 D7A600A0 */  ldc1  $f6, 0xa0($sp)
/* 0C773C 7F092C0C F7AA00B8 */  sdc1  $f10, 0xb8($sp)
/* 0C7740 7F092C10 848D0004 */  lh    $t5, 4($a0)
/* 0C7744 7F092C14 448D4000 */  mtc1  $t5, $f8
/* 0C7748 7F092C18 00000000 */  nop   
/* 0C774C 7F092C1C 468042A1 */  cvt.d.w $f10, $f8
/* 0C7750 7F092C20 462A3200 */  add.d $f8, $f6, $f10
/* 0C7754 7F092C24 44805000 */  mtc1  $zero, $f10
/* 0C7758 7F092C28 44805800 */  mtc1  $zero, $f11
/* 0C775C 7F092C2C 46282181 */  sub.d $f6, $f4, $f8
/* 0C7760 7F092C30 D7A400B0 */  ldc1  $f4, 0xb0($sp)
/* 0C7764 7F092C34 462AF032 */  c.eq.d $f30, $f10
/* 0C7768 7F092C38 F7A600C0 */  sdc1  $f6, 0xc0($sp)
/* 0C776C 7F092C3C D7A600B8 */  ldc1  $f6, 0xb8($sp)
/* 0C7770 7F092C40 45030008 */  bc1tl .L7F092C64
/* 0C7774 7F092C44 4632A301 */   sub.d $f12, $f20, $f18
/* 0C7778 7F092C48 462E2202 */  mul.d $f8, $f4, $f14
/* 0C777C 7F092C4C D7AC0140 */  ldc1  $f12, 0x140($sp)
/* 0C7780 7F092C50 46266282 */  mul.d $f10, $f12, $f6
/* 0C7784 7F092C54 462A4101 */  sub.d $f4, $f8, $f10
/* 0C7788 7F092C58 1000001C */  b     .L7F092CCC
/* 0C778C 7F092C5C 463E2083 */   div.d $f2, $f4, $f30
/* 0C7790 7F092C60 4632A301 */  sub.d $f12, $f20, $f18
.L7F092C64:
/* 0C7794 7F092C64 44803800 */  mtc1  $zero, $f7
/* 0C7798 7F092C68 44803000 */  mtc1  $zero, $f6
/* 0C779C 7F092C6C D7A800B8 */  ldc1  $f8, 0xb8($sp)
/* 0C77A0 7F092C70 D7A400B0 */  ldc1  $f4, 0xb0($sp)
/* 0C77A4 7F092C74 46266032 */  c.eq.d $f12, $f6
/* 0C77A8 7F092C78 D7A60150 */  ldc1  $f6, 0x150($sp)
/* 0C77AC 7F092C7C D7AA00C0 */  ldc1  $f10, 0xc0($sp)
/* 0C77B0 7F092C80 4501000B */  bc1t  .L7F092CB0
/* 0C77B4 7F092C84 00000000 */   nop   
/* 0C77B8 7F092C88 D7AA0150 */  ldc1  $f10, 0x150($sp)
/* 0C77BC 7F092C8C D7AE0148 */  ldc1  $f14, 0x148($sp)
/* 0C77C0 7F092C90 D7A600C0 */  ldc1  $f6, 0xc0($sp)
/* 0C77C4 7F092C94 462A4102 */  mul.d $f4, $f8, $f10
/* 0C77C8 7F092C98 00000000 */  nop   
/* 0C77CC 7F092C9C 46267202 */  mul.d $f8, $f14, $f6
/* 0C77D0 7F092CA0 46282281 */  sub.d $f10, $f4, $f8
/* 0C77D4 7F092CA4 462C5083 */  div.d $f2, $f10, $f12
/* 0C77D8 7F092CA8 10000008 */  b     .L7F092CCC
/* 0C77DC 7F092CAC D7AC0140 */   ldc1  $f12, 0x140($sp)
.L7F092CB0:
/* 0C77E0 7F092CB0 46243202 */  mul.d $f8, $f6, $f4
/* 0C77E4 7F092CB4 D7AC0140 */  ldc1  $f12, 0x140($sp)
/* 0C77E8 7F092CB8 4636C001 */  sub.d $f0, $f24, $f22
/* 0C77EC 7F092CBC D7AE0148 */  ldc1  $f14, 0x148($sp)
/* 0C77F0 7F092CC0 462C5182 */  mul.d $f6, $f10, $f12
/* 0C77F4 7F092CC4 46283101 */  sub.d $f4, $f6, $f8
/* 0C77F8 7F092CC8 46202083 */  div.d $f2, $f4, $f0
.L7F092CCC:
/* 0C77FC 7F092CCC 462C8032 */  c.eq.d $f16, $f12
/* 0C7800 7F092CD0 D7A60110 */  ldc1  $f6, 0x110($sp)
/* 0C7804 7F092CD4 45030007 */  bc1tl .L7F092CF4
/* 0C7808 7F092CD8 462E8032 */   c.eq.d $f16, $f14
/* 0C780C 7F092CDC 46261202 */  mul.d $f8, $f2, $f6
/* 0C7810 7F092CE0 D7AA00B0 */  ldc1  $f10, 0xb0($sp)
/* 0C7814 7F092CE4 46285101 */  sub.d $f4, $f10, $f8
/* 0C7818 7F092CE8 10000010 */  b     .L7F092D2C
/* 0C781C 7F092CEC 462C2003 */   div.d $f0, $f4, $f12
/* 0C7820 7F092CF0 462E8032 */  c.eq.d $f16, $f14
.L7F092CF4:
/* 0C7824 7F092CF4 D7AA0118 */  ldc1  $f10, 0x118($sp)
/* 0C7828 7F092CF8 D7A60120 */  ldc1  $f6, 0x120($sp)
/* 0C782C 7F092CFC 45010006 */  bc1t  .L7F092D18
/* 0C7830 7F092D00 00000000 */   nop   
/* 0C7834 7F092D04 462A1202 */  mul.d $f8, $f2, $f10
/* 0C7838 7F092D08 D7A600B8 */  ldc1  $f6, 0xb8($sp)
/* 0C783C 7F092D0C 46283101 */  sub.d $f4, $f6, $f8
/* 0C7840 7F092D10 10000006 */  b     .L7F092D2C
/* 0C7844 7F092D14 462E2003 */   div.d $f0, $f4, $f14
.L7F092D18:
/* 0C7848 7F092D18 46261202 */  mul.d $f8, $f2, $f6
/* 0C784C 7F092D1C D7AA00C0 */  ldc1  $f10, 0xc0($sp)
/* 0C7850 7F092D20 D7A60150 */  ldc1  $f6, 0x150($sp)
/* 0C7854 7F092D24 46285101 */  sub.d $f4, $f10, $f8
/* 0C7858 7F092D28 46262003 */  div.d $f0, $f4, $f6
.L7F092D2C:
/* 0C785C 7F092D2C 4620803E */  c.le.d $f16, $f0
/* 0C7860 7F092D30 00000000 */  nop   
/* 0C7864 7F092D34 4500003D */  bc1f  .L7F092E2C
/* 0C7868 7F092D38 00000000 */   nop   
/* 0C786C 7F092D3C 4622803E */  c.le.d $f16, $f2
/* 0C7870 7F092D40 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0C7874 7F092D44 45000039 */  bc1f  .L7F092E2C
/* 0C7878 7F092D48 00000000 */   nop   
/* 0C787C 7F092D4C 46220200 */  add.d $f8, $f0, $f2
/* 0C7880 7F092D50 44815800 */  mtc1  $at, $f11
/* 0C7884 7F092D54 44805000 */  mtc1  $zero, $f10
/* 0C7888 7F092D58 00000000 */  nop   
/* 0C788C 7F092D5C 462A403E */  c.le.d $f8, $f10
/* 0C7890 7F092D60 00000000 */  nop   
/* 0C7894 7F092D64 45000031 */  bc1f  .L7F092E2C
/* 0C7898 7F092D68 00000000 */   nop   
/* 0C789C 7F092D6C 8FA20168 */  lw    $v0, 0x168($sp)
/* 0C78A0 7F092D70 D7A400C8 */  ldc1  $f4, 0xc8($sp)
/* 0C78A4 7F092D74 C4460000 */  lwc1  $f6, ($v0)
/* 0C78A8 7F092D78 460032A1 */  cvt.d.s $f10, $f6
/* 0C78AC 7F092D7C D7A60078 */  ldc1  $f6, 0x78($sp)
/* 0C78B0 7F092D80 462A2201 */  sub.d $f8, $f4, $f10
/* 0C78B4 7F092D84 46283282 */  mul.d $f10, $f6, $f8
/* 0C78B8 7F092D88 C4480004 */  lwc1  $f8, 4($v0)
/* 0C78BC 7F092D8C D7A600D0 */  ldc1  $f6, 0xd0($sp)
/* 0C78C0 7F092D90 46004221 */  cvt.d.s $f8, $f8
/* 0C78C4 7F092D94 46283181 */  sub.d $f6, $f6, $f8
/* 0C78C8 7F092D98 D7A80080 */  ldc1  $f8, 0x80($sp)
/* 0C78CC 7F092D9C 46264202 */  mul.d $f8, $f8, $f6
/* 0C78D0 7F092DA0 46285180 */  add.d $f6, $f10, $f8
/* 0C78D4 7F092DA4 C4480008 */  lwc1  $f8, 8($v0)
/* 0C78D8 7F092DA8 D7AA00D8 */  ldc1  $f10, 0xd8($sp)
/* 0C78DC 7F092DAC 46004221 */  cvt.d.s $f8, $f8
/* 0C78E0 7F092DB0 46285281 */  sub.d $f10, $f10, $f8
/* 0C78E4 7F092DB4 D7A80088 */  ldc1  $f8, 0x88($sp)
/* 0C78E8 7F092DB8 46285282 */  mul.d $f10, $f10, $f8
/* 0C78EC 7F092DBC 46265200 */  add.d $f8, $f10, $f6
/* 0C78F0 7F092DC0 4628803E */  c.le.d $f16, $f8
/* 0C78F4 7F092DC4 00000000 */  nop   
/* 0C78F8 7F092DC8 45000016 */  bc1f  .L7F092E24
/* 0C78FC 7F092DCC 00000000 */   nop   
/* 0C7900 7F092DD0 462022A0 */  cvt.s.d $f10, $f4
/* 0C7904 7F092DD4 8FA30174 */  lw    $v1, 0x174($sp)
/* 0C7908 7F092DD8 24020001 */  li    $v0, 1
/* 0C790C 7F092DDC E46A0000 */  swc1  $f10, ($v1)
/* 0C7910 7F092DE0 D7A600D0 */  ldc1  $f6, 0xd0($sp)
/* 0C7914 7F092DE4 46203220 */  cvt.s.d $f8, $f6
/* 0C7918 7F092DE8 E4680004 */  swc1  $f8, 4($v1)
/* 0C791C 7F092DEC D7A400D8 */  ldc1  $f4, 0xd8($sp)
/* 0C7920 7F092DF0 462022A0 */  cvt.s.d $f10, $f4
/* 0C7924 7F092DF4 E46A0008 */  swc1  $f10, 8($v1)
/* 0C7928 7F092DF8 D7A60108 */  ldc1  $f6, 0x108($sp)
/* 0C792C 7F092DFC 46203220 */  cvt.s.d $f8, $f6
/* 0C7930 7F092E00 E468000C */  swc1  $f8, 0xc($v1)
/* 0C7934 7F092E04 D7A40100 */  ldc1  $f4, 0x100($sp)
/* 0C7938 7F092E08 462022A0 */  cvt.s.d $f10, $f4
/* 0C793C 7F092E0C E46A0010 */  swc1  $f10, 0x10($v1)
/* 0C7940 7F092E10 D7A600F8 */  ldc1  $f6, 0xf8($sp)
/* 0C7944 7F092E14 A460002A */  sh    $zero, 0x2a($v1)
/* 0C7948 7F092E18 46203220 */  cvt.s.d $f8, $f6
/* 0C794C 7F092E1C 10000003 */  b     .L7F092E2C
/* 0C7950 7F092E20 E4680014 */   swc1  $f8, 0x14($v1)
.L7F092E24:
/* 0C7954 7F092E24 10000001 */  b     .L7F092E2C
/* 0C7958 7F092E28 00001025 */   move  $v0, $zero
.L7F092E2C:
/* 0C795C 7F092E2C D7B40008 */  ldc1  $f20, 8($sp)
/* 0C7960 7F092E30 D7B60010 */  ldc1  $f22, 0x10($sp)
/* 0C7964 7F092E34 D7B80018 */  ldc1  $f24, 0x18($sp)
/* 0C7968 7F092E38 D7BA0020 */  ldc1  $f26, 0x20($sp)
/* 0C796C 7F092E3C D7BC0028 */  ldc1  $f28, 0x28($sp)
/* 0C7970 7F092E40 D7BE0030 */  ldc1  $f30, 0x30($sp)
/* 0C7974 7F092E44 03E00008 */  jr    $ra
/* 0C7978 7F092E48 27BD0158 */   addiu $sp, $sp, 0x158
)
#endif


