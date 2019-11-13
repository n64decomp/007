#include "ultra64.h"

//.section .bss
OSTask tmp_task;


#ifdef NONMATCHING
void *_VirtualToPhysicalTask(s32 arg0, ? arg8) {
    void *sp1C;

    // Node 0
    sp1C = &tmp_task;
    _bcopy(arg8, &tmp_task, 0x40);
    if (sp1C->unk10 != 0)
    {
        // Node 1
        sp1C->unk10 = osVirtualToPhysical(sp1C->unk10);
    }
    // Node 2
    if (sp1C->unk18 != 0)
    {
        // Node 3
        sp1C->unk18 = osVirtualToPhysical(sp1C->unk18);
    }
    // Node 4
    if (sp1C->unk20 != 0)
    {
        // Node 5
        sp1C->unk20 = osVirtualToPhysical(sp1C->unk20);
    }
    // Node 6
    if (sp1C->unk28 != 0)
    {
        // Node 7
        sp1C->unk28 = osVirtualToPhysical(sp1C->unk28);
    }
    // Node 8
    if (sp1C->unk2C != 0)
    {
        // Node 9
        sp1C->unk2C = osVirtualToPhysical(sp1C->unk2C);
    }
    // Node 10
    if (sp1C->unk30 != 0)
    {
        // Node 11
        sp1C->unk30 = osVirtualToPhysical(sp1C->unk30);
    }
    // Node 12
    if (sp1C->unk38 != 0)
    {
        // Node 13
        sp1C->unk38 = osVirtualToPhysical(sp1C->unk38);
        return;
        // (possible return value: sp1C)
    }
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel _VirtualToPhysicalTask
/* 00F0F0 7000E4F0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00F0F4 7000E4F4 3C0E8006 */  lui   $t6, %hi(tmp_task) 
/* 00F0F8 7000E4F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F0FC 7000E4FC AFA40020 */  sw    $a0, 0x20($sp)
/* 00F100 7000E500 25CE6A90 */  addiu $t6, %lo(tmp_task) # addiu $t6, $t6, 0x6a90
/* 00F104 7000E504 AFAE001C */  sw    $t6, 0x1c($sp)
/* 00F108 7000E508 01C02825 */  move  $a1, $t6
/* 00F10C 7000E50C 8FA40020 */  lw    $a0, 0x20($sp)
/* 00F110 7000E510 0C003E5C */  jal   _bcopy
/* 00F114 7000E514 24060040 */   li    $a2, 64
/* 00F118 7000E518 8FAF001C */  lw    $t7, 0x1c($sp)
/* 00F11C 7000E51C 8DF80010 */  lw    $t8, 0x10($t7)
/* 00F120 7000E520 13000005 */  beqz  $t8, .L7000E538
/* 00F124 7000E524 00000000 */   nop   
/* 00F128 7000E528 0C003A2C */  jal   osVirtualToPhysical
/* 00F12C 7000E52C 03002025 */   move  $a0, $t8
/* 00F130 7000E530 8FB9001C */  lw    $t9, 0x1c($sp)
/* 00F134 7000E534 AF220010 */  sw    $v0, 0x10($t9)
.L7000E538:
/* 00F138 7000E538 8FA8001C */  lw    $t0, 0x1c($sp)
/* 00F13C 7000E53C 8D090018 */  lw    $t1, 0x18($t0)
/* 00F140 7000E540 11200005 */  beqz  $t1, .L7000E558
/* 00F144 7000E544 00000000 */   nop   
/* 00F148 7000E548 0C003A2C */  jal   osVirtualToPhysical
/* 00F14C 7000E54C 01202025 */   move  $a0, $t1
/* 00F150 7000E550 8FAA001C */  lw    $t2, 0x1c($sp)
/* 00F154 7000E554 AD420018 */  sw    $v0, 0x18($t2)
.L7000E558:
/* 00F158 7000E558 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00F15C 7000E55C 8D6C0020 */  lw    $t4, 0x20($t3)
/* 00F160 7000E560 11800005 */  beqz  $t4, .L7000E578
/* 00F164 7000E564 00000000 */   nop   
/* 00F168 7000E568 0C003A2C */  jal   osVirtualToPhysical
/* 00F16C 7000E56C 01802025 */   move  $a0, $t4
/* 00F170 7000E570 8FAD001C */  lw    $t5, 0x1c($sp)
/* 00F174 7000E574 ADA20020 */  sw    $v0, 0x20($t5)
.L7000E578:
/* 00F178 7000E578 8FAE001C */  lw    $t6, 0x1c($sp)
/* 00F17C 7000E57C 8DCF0028 */  lw    $t7, 0x28($t6)
/* 00F180 7000E580 11E00005 */  beqz  $t7, .L7000E598
/* 00F184 7000E584 00000000 */   nop   
/* 00F188 7000E588 0C003A2C */  jal   osVirtualToPhysical
/* 00F18C 7000E58C 01E02025 */   move  $a0, $t7
/* 00F190 7000E590 8FB8001C */  lw    $t8, 0x1c($sp)
/* 00F194 7000E594 AF020028 */  sw    $v0, 0x28($t8)
.L7000E598:
/* 00F198 7000E598 8FB9001C */  lw    $t9, 0x1c($sp)
/* 00F19C 7000E59C 8F28002C */  lw    $t0, 0x2c($t9)
/* 00F1A0 7000E5A0 11000005 */  beqz  $t0, .L7000E5B8
/* 00F1A4 7000E5A4 00000000 */   nop   
/* 00F1A8 7000E5A8 0C003A2C */  jal   osVirtualToPhysical
/* 00F1AC 7000E5AC 01002025 */   move  $a0, $t0
/* 00F1B0 7000E5B0 8FA9001C */  lw    $t1, 0x1c($sp)
/* 00F1B4 7000E5B4 AD22002C */  sw    $v0, 0x2c($t1)
.L7000E5B8:
/* 00F1B8 7000E5B8 8FAA001C */  lw    $t2, 0x1c($sp)
/* 00F1BC 7000E5BC 8D4B0030 */  lw    $t3, 0x30($t2)
/* 00F1C0 7000E5C0 11600005 */  beqz  $t3, .L7000E5D8
/* 00F1C4 7000E5C4 00000000 */   nop   
/* 00F1C8 7000E5C8 0C003A2C */  jal   osVirtualToPhysical
/* 00F1CC 7000E5CC 01602025 */   move  $a0, $t3
/* 00F1D0 7000E5D0 8FAC001C */  lw    $t4, 0x1c($sp)
/* 00F1D4 7000E5D4 AD820030 */  sw    $v0, 0x30($t4)
.L7000E5D8:
/* 00F1D8 7000E5D8 8FAD001C */  lw    $t5, 0x1c($sp)
/* 00F1DC 7000E5DC 8DAE0038 */  lw    $t6, 0x38($t5)
/* 00F1E0 7000E5E0 11C00005 */  beqz  $t6, .L7000E5F8
/* 00F1E4 7000E5E4 00000000 */   nop   
/* 00F1E8 7000E5E8 0C003A2C */  jal   osVirtualToPhysical
/* 00F1EC 7000E5EC 01C02025 */   move  $a0, $t6
/* 00F1F0 7000E5F0 8FAF001C */  lw    $t7, 0x1c($sp)
/* 00F1F4 7000E5F4 ADE20038 */  sw    $v0, 0x38($t7)
.L7000E5F8:
/* 00F1F8 7000E5F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F1FC 7000E5FC 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00F200 7000E600 27BD0020 */  addiu $sp, $sp, 0x20
/* 00F204 7000E604 03E00008 */  jr    $ra
/* 00F208 7000E608 00000000 */   nop 
)
#endif

#ifdef NONMATCHING
void osSpTaskLoad(s32 arg0, void *arg8) {
    s32 sp1C;

    // Node 0
    sp1C = _VirtualToPhysicalTask(arg8);
    if ((sp1C->unk4 & 1) != 0)
    {
        // Node 1
        sp1C->unk18 = (?32) sp1C->unk38;
        sp1C->unk1C = (?32) sp1C->unk3C;
        arg8->unk4 = (s32) (arg8->unk4 & -2);
    }
    // Node 2
    osWritebackDCache(sp1C, 0x40);
    __osSpSetStatus(0x2b00);
    if (__osSpSetPc(0x4001000) == -1)
    {
        loop_3:
        // Node 3
        if (__osSpSetPc(0x4001000) == -1)
        {
            goto loop_3;
        }
    }
    // Node 4
    if (__osSpRawStartDma(1, 0x4000fc0, sp1C, 0x40) == -1)
    {
        loop_5:
        // Node 5
        if (__osSpRawStartDma(1, 0x4000fc0, sp1C, 0x40) == -1)
        {
            goto loop_5;
        }
    }
    // Node 6
    if (__osSpDeviceBusy() != 0)
    {
        loop_7:
        // Node 7
        if (__osSpDeviceBusy() != 0)
        {
            goto loop_7;
        }
    }
    // Node 8
    if (__osSpRawStartDma(1, 0x4001000, sp1C->unk8, sp1C->unkC) == -1)
    {
        loop_9:
        // Node 9
        if (__osSpRawStartDma(1, 0x4001000, sp1C->unk8, sp1C->unkC) == -1)
        {
            goto loop_9;
        }
    }
    // (possible return value: __osSpRawStartDma(1, 0x4001000, sp1C->unk8, sp1C->unkC))
}
#else
GLOBAL_ASM(
.text
glabel osSpTaskLoad
/* 00F20C 7000E60C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00F210 7000E610 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F214 7000E614 AFA40020 */  sw    $a0, 0x20($sp)
/* 00F218 7000E618 0C00393C */  jal   _VirtualToPhysicalTask
/* 00F21C 7000E61C 8FA40020 */   lw    $a0, 0x20($sp)
/* 00F220 7000E620 AFA2001C */  sw    $v0, 0x1c($sp)
/* 00F224 7000E624 8FAE001C */  lw    $t6, 0x1c($sp)
/* 00F228 7000E628 8DCF0004 */  lw    $t7, 4($t6)
/* 00F22C 7000E62C 31F80001 */  andi  $t8, $t7, 1
/* 00F230 7000E630 1300000B */  beqz  $t8, .L7000E660
/* 00F234 7000E634 00000000 */   nop   
/* 00F238 7000E638 8DD90038 */  lw    $t9, 0x38($t6)
/* 00F23C 7000E63C 2401FFFE */  li    $at, -2
/* 00F240 7000E640 ADD90018 */  sw    $t9, 0x18($t6)
/* 00F244 7000E644 8FA8001C */  lw    $t0, 0x1c($sp)
/* 00F248 7000E648 8D09003C */  lw    $t1, 0x3c($t0)
/* 00F24C 7000E64C AD09001C */  sw    $t1, 0x1c($t0)
/* 00F250 7000E650 8FAA0020 */  lw    $t2, 0x20($sp)
/* 00F254 7000E654 8D4B0004 */  lw    $t3, 4($t2)
/* 00F258 7000E658 01616024 */  and   $t4, $t3, $at
/* 00F25C 7000E65C AD4C0004 */  sw    $t4, 4($t2)
.L7000E660:
/* 00F260 7000E660 8FA4001C */  lw    $a0, 0x1c($sp)
/* 00F264 7000E664 0C0042F4 */  jal   osWritebackDCache
/* 00F268 7000E668 24050040 */   li    $a1, 64
/* 00F26C 7000E66C 0C0063B8 */  jal   __osSpSetStatus
/* 00F270 7000E670 24042B00 */   li    $a0, 11008
/* 00F274 7000E674 3C040400 */  lui   $a0, (0x04001000 >> 16) # lui $a0, 0x400
/* 00F278 7000E678 0C0063BC */  jal   __osSpSetPc
/* 00F27C 7000E67C 34841000 */   ori   $a0, (0x04001000 & 0xFFFF) # ori $a0, $a0, 0x1000
/* 00F280 7000E680 2401FFFF */  li    $at, -1
/* 00F284 7000E684 14410007 */  bne   $v0, $at, .L7000E6A4
/* 00F288 7000E688 00000000 */   nop   
.L7000E68C:
/* 00F28C 7000E68C 3C040400 */  lui   $a0, (0x04001000 >> 16) # lui $a0, 0x400
/* 00F290 7000E690 0C0063BC */  jal   __osSpSetPc
/* 00F294 7000E694 34841000 */   ori   $a0, (0x04001000 & 0xFFFF) # ori $a0, $a0, 0x1000
/* 00F298 7000E698 2401FFFF */  li    $at, -1
/* 00F29C 7000E69C 1041FFFB */  beq   $v0, $at, .L7000E68C
/* 00F2A0 7000E6A0 00000000 */   nop   
.L7000E6A4:
/* 00F2A4 7000E6A4 3C050400 */  lui   $a1, (0x04000FC0 >> 16) # lui $a1, 0x400
/* 00F2A8 7000E6A8 34A50FC0 */  ori   $a1, (0x04000FC0 & 0xFFFF) # ori $a1, $a1, 0xfc0
/* 00F2AC 7000E6AC 24040001 */  li    $a0, 1
/* 00F2B0 7000E6B0 8FA6001C */  lw    $a2, 0x1c($sp)
/* 00F2B4 7000E6B4 0C0063CC */  jal   __osSpRawStartDma
/* 00F2B8 7000E6B8 24070040 */   li    $a3, 64
/* 00F2BC 7000E6BC 2401FFFF */  li    $at, -1
/* 00F2C0 7000E6C0 1441000A */  bne   $v0, $at, .L7000E6EC
/* 00F2C4 7000E6C4 00000000 */   nop   
.L7000E6C8:
/* 00F2C8 7000E6C8 3C050400 */  lui   $a1, (0x04000FC0 >> 16) # lui $a1, 0x400
/* 00F2CC 7000E6CC 34A50FC0 */  ori   $a1, (0x04000FC0 & 0xFFFF) # ori $a1, $a1, 0xfc0
/* 00F2D0 7000E6D0 24040001 */  li    $a0, 1
/* 00F2D4 7000E6D4 8FA6001C */  lw    $a2, 0x1c($sp)
/* 00F2D8 7000E6D8 0C0063CC */  jal   __osSpRawStartDma
/* 00F2DC 7000E6DC 24070040 */   li    $a3, 64
/* 00F2E0 7000E6E0 2401FFFF */  li    $at, -1
/* 00F2E4 7000E6E4 1041FFF8 */  beq   $v0, $at, .L7000E6C8
/* 00F2E8 7000E6E8 00000000 */   nop   
.L7000E6EC:
/* 00F2EC 7000E6EC 0C0063F0 */  jal   __osSpDeviceBusy
/* 00F2F0 7000E6F0 00000000 */   nop   
/* 00F2F4 7000E6F4 10400005 */  beqz  $v0, .L7000E70C
/* 00F2F8 7000E6F8 00000000 */   nop   
.L7000E6FC:
/* 00F2FC 7000E6FC 0C0063F0 */  jal   __osSpDeviceBusy
/* 00F300 7000E700 00000000 */   nop   
/* 00F304 7000E704 1440FFFD */  bnez  $v0, .L7000E6FC
/* 00F308 7000E708 00000000 */   nop   
.L7000E70C:
/* 00F30C 7000E70C 8FAD001C */  lw    $t5, 0x1c($sp)
/* 00F310 7000E710 3C050400 */  lui   $a1, (0x04001000 >> 16) # lui $a1, 0x400
/* 00F314 7000E714 34A51000 */  ori   $a1, (0x04001000 & 0xFFFF) # ori $a1, $a1, 0x1000
/* 00F318 7000E718 24040001 */  li    $a0, 1
/* 00F31C 7000E71C 8DA60008 */  lw    $a2, 8($t5)
/* 00F320 7000E720 0C0063CC */  jal   __osSpRawStartDma
/* 00F324 7000E724 8DA7000C */   lw    $a3, 0xc($t5)
/* 00F328 7000E728 2401FFFF */  li    $at, -1
/* 00F32C 7000E72C 1441000B */  bne   $v0, $at, .L7000E75C
/* 00F330 7000E730 00000000 */   nop   
.L7000E734:
/* 00F334 7000E734 8FAF001C */  lw    $t7, 0x1c($sp)
/* 00F338 7000E738 3C050400 */  lui   $a1, (0x04001000 >> 16) # lui $a1, 0x400
/* 00F33C 7000E73C 34A51000 */  ori   $a1, (0x04001000 & 0xFFFF) # ori $a1, $a1, 0x1000
/* 00F340 7000E740 24040001 */  li    $a0, 1
/* 00F344 7000E744 8DE60008 */  lw    $a2, 8($t7)
/* 00F348 7000E748 0C0063CC */  jal   __osSpRawStartDma
/* 00F34C 7000E74C 8DE7000C */   lw    $a3, 0xc($t7)
/* 00F350 7000E750 2401FFFF */  li    $at, -1
/* 00F354 7000E754 1041FFF7 */  beq   $v0, $at, .L7000E734
/* 00F358 7000E758 00000000 */   nop   
.L7000E75C:
/* 00F35C 7000E75C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F360 7000E760 27BD0020 */  addiu $sp, $sp, 0x20
/* 00F364 7000E764 03E00008 */  jr    $ra
/* 00F368 7000E768 00000000 */   nop  
)
#endif

#ifdef NONMATCHING
void osSpTaskStartGo(s32 arg0) {
    // Node 0
    if (__osSpDeviceBusy() != 0)
    {
        loop_1:
        // Node 1
        if (__osSpDeviceBusy() != 0)
        {
            goto loop_1;
        }
    }
    // Node 2
    __osSpSetStatus(0x125);
    return;
    // (possible return value: __osSpSetStatus(0x125))
}
#else
GLOBAL_ASM(
.text
glabel osSpTaskStartGo
/* 00F36C 7000E76C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00F370 7000E770 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F374 7000E774 0C0063F0 */  jal   __osSpDeviceBusy
/* 00F378 7000E778 AFA40018 */   sw    $a0, 0x18($sp)
/* 00F37C 7000E77C 10400005 */  beqz  $v0, .L7000E794
/* 00F380 7000E780 00000000 */   nop   
.L7000E784:
/* 00F384 7000E784 0C0063F0 */  jal   __osSpDeviceBusy
/* 00F388 7000E788 00000000 */   nop   
/* 00F38C 7000E78C 1440FFFD */  bnez  $v0, .L7000E784
/* 00F390 7000E790 00000000 */   nop   
.L7000E794:
/* 00F394 7000E794 0C0063B8 */  jal   __osSpSetStatus
/* 00F398 7000E798 24040125 */   li    $a0, 293
/* 00F39C 7000E79C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F3A0 7000E7A0 27BD0018 */  addiu $sp, $sp, 0x18
/* 00F3A4 7000E7A4 03E00008 */  jr    $ra
/* 00F3A8 7000E7A8 00000000 */   nop 
)
#endif