#include "libultra_internal.h"

void __osDevMgrMain(void *args)
{
    OSIoMesg *sp34;
    OSMesg sp30;
    OSMesg sp2c;
    s32 sp28;
    OSMgrArgs *sp24;
    //  addiu $sp, $sp, -0x38
    //  sw    $a0, 0x38($sp)
    //  lw    $t6, 0x38($sp)
    //  sw    $ra, 0x1c($sp)
    //  sw    $s0, 0x18($sp)
    //  sw    $zero, 0x34($sp)
    sp34 = NULL;
    //  sw    $zero, 0x28($sp)
    sp28 = 0;
    //  sw    $t6, 0x24($sp)
    sp24 = (OSMgrArgs *)args;
    while (1)
    {
        //.L80327630:
        //  lw    $t7, 0x24($sp)
        //  addiu $a1, $sp, 0x34
        //  li    $a2, 1
        //  jal   osRecvMesg
        //   lw    $a0, 8($t7)
        osRecvMesg(sp24->unk08, (OSMesg)&sp34, OS_MESG_BLOCK);
        //  lw    $t8, 0x34($sp)
        //  li    $at, 10
        //  lhu   $s0, ($t8)
        //  beq   $s0, $at, .L803276E8
        //   li    $at, 11
        //  beq   $s0, $at, .L80327670
        //   li    $at, 12
        //  beq   $s0, $at, .L803276AC
        //   nop
        //  b     .L80327708
        //   nop
        switch (sp34->hdr.type)
        {
        case 11:
            //.L80327670:
            //  lw    $t9, 0x24($sp)
            //  addiu $a1, $sp, 0x2c
            //  li    $a2, 1
            //  jal   osRecvMesg
            //   lw    $a0, 0x10($t9)
            osRecvMesg(sp24->unk10, &sp2c, OS_MESG_BLOCK);
            //  lw    $t1, 0x24($sp)
            //  lw    $t0, 0x34($sp)
            //  move  $a0, $zero
            //  lw    $t9, 0x14($t1)
            //  lw    $a1, 0xc($t0)
            //  lw    $a2, 8($t0)
            //  jalr  $t9
            //  lw    $a3, 0x10($t0)
            //  b     .L80327710
            //   sw    $v0, 0x28($sp)
            sp28 = sp24->dma_func(0 /*write*/, sp34->devAddr, sp34->dramAddr, sp34->size);
            break;
        case 12:
            //.L803276AC:
            //  lw    $t2, 0x24($sp)
            //  addiu $a1, $sp, 0x2c
            //  li    $a2, 1
            //  jal   osRecvMesg
            //   lw    $a0, 0x10($t2)
            osRecvMesg(sp24->unk10, &sp2c, OS_MESG_BLOCK);
            //  lw    $t4, 0x24($sp)
            //  lw    $t3, 0x34($sp)
            //  li    $a0, 1
            //  lw    $t9, 0x14($t4)
            //  lw    $a1, 0xc($t3)
            //  lw    $a2, 8($t3)
            //  jalr  $t9
            //  lw    $a3, 0x10($t3)
            //  b     .L80327710
            //   sw    $v0, 0x28($sp)
            sp28 = sp24->dma_func(1 /*read*/, sp34->devAddr, sp34->dramAddr, sp34->size);
            break;
        case 10:
            //.L803276E8:
            //  lw    $t5, 0x34($sp)
            //  move  $a2, $zero
            //  lw    $a0, 4($t5)
            //  jal   osSendMesg
            //   move  $a1, $t5
            osSendMesg(sp34->hdr.retQueue, sp34, OS_MESG_NOBLOCK);
            //  li    $t6, -1
            //  b     .L80327710
            //   sw    $t6, 0x28($sp)
            sp28 = -1;
            break;
        default:
            //.L80327708:
            //  li    $t7, -1
            //  sw    $t7, 0x28($sp)
            sp28 = -1;
            break;
        }
        //.L80327710:
        //  lw    $t8, 0x28($sp)
        //  bnez  $t8, .L80327630
        //   nop
        if (sp28 == 0)
        {
            //  lw    $t0, 0x24($sp)
            //  addiu $a1, $sp, 0x30
            //  li    $a2, 1
            //  jal   osRecvMesg
            //   lw    $a0, 0xc($t0)
            osRecvMesg(sp24->unk0c, &sp30, OS_MESG_BLOCK);
            //  lw    $t1, 0x34($sp)
            //  move  $a2, $zero
            //  lw    $a0, 4($t1)
            //  jal   osSendMesg
            //   move  $a1, $t1
            osSendMesg(sp34->hdr.retQueue, sp34, OS_MESG_NOBLOCK);
            //  lw    $t2, 0x24($sp)
            //  move  $a1, $zero
            //  move  $a2, $zero
            //  jal   osSendMesg
            //   lw    $a0, 0x10($t2)
            osSendMesg(sp24->unk10, NULL, OS_MESG_NOBLOCK);
        }
        //  b     .L80327630
        //   nop
    }
    //  nop
    //  nop
    //  nop
    //  nop
    //  lw    $ra, 0x1c($sp)
    //  lw    $s0, 0x18($sp)
    //  addiu $sp, $sp, 0x38
    //  jr    $ra
    //   nop

    //  nop
    //  nop
    //  nop
}
