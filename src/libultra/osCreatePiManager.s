# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
.ifndef VERSION_EU
glabel osCreatePiManager
/* 0151B0 700145B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0151B4 700145B4 3C0E8002 */  lui   $t6, %hi(__osPiDevMgr) 
/* 0151B8 700145B8 8DCE7790 */  lw    $t6, %lo(__osPiDevMgr)($t6)
/* 0151BC 700145BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0151C0 700145C0 AFA40030 */  sw    $a0, 0x30($sp)
/* 0151C4 700145C4 AFA50034 */  sw    $a1, 0x34($sp)
/* 0151C8 700145C8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0151CC 700145CC 15C00056 */  bnez  $t6, .L70014728
/* 0151D0 700145D0 AFA7003C */   sw    $a3, 0x3c($sp)
/* 0151D4 700145D4 8FA40034 */  lw    $a0, 0x34($sp)
/* 0151D8 700145D8 8FA50038 */  lw    $a1, 0x38($sp)
/* 0151DC 700145DC 0C0035B4 */  jal   osCreateMesgQueue
/* 0151E0 700145E0 8FA6003C */   lw    $a2, 0x3c($sp)
/* 0151E4 700145E4 3C048006 */  lui   $a0, %hi(pieventQueue)
/* 0151E8 700145E8 3C058006 */  lui   $a1, %hi(piEventBuf)
/* 0151EC 700145EC 24A57C98 */  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x7c98
/* 0151F0 700145F0 24847C80 */  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x7c80
/* 0151F4 700145F4 0C0035B4 */  jal   osCreateMesgQueue
/* 0151F8 700145F8 24060001 */   li    $a2, 1
/* 0151FC 700145FC 3C0F8003 */  lui   $t7, %hi(__osPiAccessQueueEnabled) 
/* 015200 70014600 8DEF82E0 */  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
/* 015204 70014604 15E00003 */  bnez  $t7, .L70014614
/* 015208 70014608 00000000 */   nop   
/* 01520C 7001460C 0C0075C4 */  jal   __osPiCreateAccessQueue
/* 015210 70014610 00000000 */   nop   
.L70014614:
/* 015214 70014614 3C058006 */  lui   $a1, %hi(pieventQueue)
/* 015218 70014618 3C062222 */  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
/* 01521C 7001461C 34C62222 */  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
/* 015220 70014620 24A57C80 */  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x7c80
/* 015224 70014624 0C003714 */  jal   osSetEventMesg
/* 015228 70014628 24040008 */   li    $a0, 8
/* 01522C 7001462C 2418FFFF */  li    $t8, -1
/* 015230 70014630 AFB80028 */  sw    $t8, 0x28($sp)
/* 015234 70014634 0C00628C */  jal   osGetThreadPri
/* 015238 70014638 00002025 */   move  $a0, $zero
/* 01523C 7001463C AFA20024 */  sw    $v0, 0x24($sp)
/* 015240 70014640 8FB90024 */  lw    $t9, 0x24($sp)
/* 015244 70014644 8FA80030 */  lw    $t0, 0x30($sp)
/* 015248 70014648 0328082A */  slt   $at, $t9, $t0
/* 01524C 7001464C 10200005 */  beqz  $at, .L70014664
/* 015250 70014650 00000000 */   nop   
/* 015254 70014654 AFB90028 */  sw    $t9, 0x28($sp)
/* 015258 70014658 00002025 */  move  $a0, $zero
/* 01525C 7001465C 0C003600 */  jal   osSetThreadPri
/* 015260 70014660 01002825 */   move  $a1, $t0
.L70014664:
/* 015264 70014664 0C00617C */  jal   __osDisableInt
/* 015268 70014668 00000000 */   nop   
/* 01526C 7001466C 3C018002 */  lui   $at, %hi(__osPiDevMgr.cmdQueue)
/* 015270 70014670 8FAB0034 */  lw    $t3, 0x34($sp)
/* 015274 70014674 3C0A8006 */  lui   $t2, %hi(piThread) 
/* 015278 70014678 3C0C8006 */  lui   $t4, %hi(pieventQueue) 
/* 01527C 7001467C 24090001 */  li    $t1, 1
/* 015280 70014680 254A6AD0 */  addiu $t2, %lo(piThread) # addiu $t2, $t2, 0x6ad0
/* 015284 70014684 258C7C80 */  addiu $t4, %lo(pieventQueue) # addiu $t4, $t4, 0x7c80
/* 015288 70014688 AC297790 */  sw    $t1, %lo(__osPiDevMgr)($at)
/* 01528C 7001468C AC2A7794 */  sw    $t2, %lo(__osPiDevMgr.thread)($at)
/* 015290 70014690 AC2C779C */  sw    $t4, %lo(__osPiDevMgr.evtQueue)($at)
/* 015294 70014694 3C188006 */  lui   $t8, %hi(piThreadStack)
/* 015298 70014698 AC2B7798 */  sw    $t3, %lo(__osPiDevMgr.cmdQueue)($at)
/* 01529C 7001469C 8FA80030 */  lw    $t0, 0x30($sp)
/* 0152A0 700146A0 3C018002 */  lui   $at, %hi(__osPiDevMgr.edma)
/* 0152A4 700146A4 3C0D8007 */  lui   $t5, %hi(__osPiAccessQueue) 
/* 0152A8 700146A8 3C0E7001 */  lui   $t6, %hi(osPiRawStartDma) # $t6, 0x7001
/* 0152AC 700146AC 3C0F7002 */  lui   $t7, %hi(osEPiRawStartDma) # $t7, 0x7002
/* 0152B0 700146B0 27186C80 */  addiu $t8, $t8, %lo(piThreadStack)
/* 0152B4 700146B4 25AD8FE8 */  addiu $t5, %lo(__osPiAccessQueue) # addiu $t5, $t5, -0x7018
/* 0152B8 700146B8 25CECF90 */  addiu $t6, %lo(osPiRawStartDma) # addiu $t6, $t6, -0x3070
/* 0152BC 700146BC 25EFE530 */  addiu $t7, %lo(osEPiRawStartDma) # addiu $t7, $t7, -0x1ad0
/* 0152C0 700146C0 27191000 */  addiu $t9, $t8, 0x1000
/* 0152C4 700146C4 3C067002 */  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7002
/* 0152C8 700146C8 3C078002 */  lui   $a3, %hi(__osPiDevMgr)
/* 0152CC 700146CC AFA2002C */  sw    $v0, 0x2c($sp)
/* 0152D0 700146D0 AC2D77A0 */  sw    $t5, %lo(__osPiDevMgr.acsQueue)($at)
/* 0152D4 700146D4 AC2E77A4 */  sw    $t6, %lo(__osPiDevMgr.dma)($at)
/* 0152D8 700146D8 AC2F77A8 */  sw    $t7, %lo(__osPiDevMgr.edma)($at)
/* 0152DC 700146DC 24E77790 */  addiu $a3, %lo(__osPiDevMgr) # addiu $a3, $a3, 0x7790
/* 0152E0 700146E0 24C6E610 */  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x19f0
/* 0152E4 700146E4 AFB90010 */  sw    $t9, 0x10($sp)
/* 0152E8 700146E8 01402025 */  move  $a0, $t2
/* 0152EC 700146EC 00002825 */  move  $a1, $zero
/* 0152F0 700146F0 0C00350C */  jal   osCreateThread
/* 0152F4 700146F4 AFA80014 */   sw    $t0, 0x14($sp)
/* 0152F8 700146F8 3C048006 */  lui   $a0, %hi(piThread)
/* 0152FC 700146FC 0C003560 */  jal   osStartThread
/* 015300 70014700 24846AD0 */   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x6ad0
/* 015304 70014704 0C006184 */  jal   __osRestoreInt
/* 015308 70014708 8FA4002C */   lw    $a0, 0x2c($sp)
/* 01530C 7001470C 8FA90028 */  lw    $t1, 0x28($sp)
/* 015310 70014710 2401FFFF */  li    $at, -1
/* 015314 70014714 11210004 */  beq   $t1, $at, .L70014728
/* 015318 70014718 00000000 */   nop   
/* 01531C 7001471C 00002025 */  move  $a0, $zero
/* 015320 70014720 0C003600 */  jal   osSetThreadPri
/* 015324 70014724 01202825 */   move  $a1, $t1
.L70014728:
/* 015328 70014728 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01532C 7001472C 27BD0030 */  addiu $sp, $sp, 0x30
/* 015330 70014730 03E00008 */  jr    $ra
/* 015334 70014734 00000000 */   nop   
.endif
.ifdef VERSION_EU
glabel osCreatePiManager
/* 0026F0 70001AF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0026F4 70001AF4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0026F8 70001AF8 3C108002 */  lui   $s0, %hi(__osPiDevMgr) # $s0, 0x8002
/* 0026FC 70001AFC 26100FB0 */  addiu $s0, %lo(__osPiDevMgr) # addiu $s0, $s0, 0xfb0
/* 002700 70001B00 8E0E0000 */  lw    $t6, ($s0)
/* 002704 70001B04 AFBF0024 */  sw    $ra, 0x24($sp)
/* 002708 70001B08 AFA40030 */  sw    $a0, 0x30($sp)
/* 00270C 70001B0C AFA50034 */  sw    $a1, 0x34($sp)
/* 002710 70001B10 15C0004E */  bnez  $t6, .L70001C4C
/* 002714 70001B14 AFA60038 */   sw    $a2, 0x38($sp)
/* 002718 70001B18 00A02025 */  move  $a0, $a1
/* 00271C 70001B1C 00C02825 */  move  $a1, $a2
/* 002720 70001B20 0C00310C */  jal   osCreateMesgQueue
/* 002724 70001B24 00E03025 */   move  $a2, $a3
/* 002728 70001B28 3C048005 */  lui   $a0, %hi(pieventQueue) # $a0, 0x8005
/* 00272C 70001B2C 3C058005 */  lui   $a1, %hi(piEventBuf) # $a1, 0x8005
/* 002730 70001B30 24A52598 */  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x2598
/* 002734 70001B34 24842580 */  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x2580
/* 002738 70001B38 0C00310C */  jal   osCreateMesgQueue
/* 00273C 70001B3C 24060001 */   li    $a2, 1
/* 002740 70001B40 3C0F8002 */  lui   $t7, %hi(__osPiAccessQueueEnabled) # $t7, 0x8002
/* 002744 70001B44 8DEF31D0 */  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
/* 002748 70001B48 15E00003 */  bnez  $t7, .L70001B58
/* 00274C 70001B4C 00000000 */   nop   
/* 002750 70001B50 0C0036D8 */  jal   __osPiCreateAccessQueue
/* 002754 70001B54 00000000 */   nop   
.L70001B58:
/* 002758 70001B58 3C058005 */  lui   $a1, %hi(pieventQueue) # $a1, 0x8005
/* 00275C 70001B5C 3C062222 */  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
/* 002760 70001B60 34C62222 */  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
/* 002764 70001B64 24A52580 */  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x2580
/* 002768 70001B68 0C003194 */  jal   osSetEventMesg
/* 00276C 70001B6C 24040008 */   li    $a0, 8
/* 002770 70001B70 2418FFFF */  li    $t8, -1
/* 002774 70001B74 AFB80028 */  sw    $t8, 0x28($sp)
/* 002778 70001B78 0C0035A0 */  jal   osGetThreadPri
/* 00277C 70001B7C 00002025 */   move  $a0, $zero
/* 002780 70001B80 8FB90030 */  lw    $t9, 0x30($sp)
/* 002784 70001B84 00002025 */  move  $a0, $zero
/* 002788 70001B88 0059082A */  slt   $at, $v0, $t9
/* 00278C 70001B8C 10200003 */  beqz  $at, .L70001B9C
/* 002790 70001B90 03202825 */   move  $a1, $t9
/* 002794 70001B94 0C003158 */  jal   osSetThreadPri
/* 002798 70001B98 AFA20028 */   sw    $v0, 0x28($sp)
.L70001B9C:
/* 00279C 70001B9C 0C0035A8 */  jal   __osDisableInt
/* 0027A0 70001BA0 00000000 */   nop   
/* 0027A4 70001BA4 8FA90034 */  lw    $t1, 0x34($sp)
/* 0027A8 70001BA8 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0027AC 70001BAC 3C048005 */  lui   $a0, %hi(piThread) # $a0, 0x8005
/* 0027B0 70001BB0 3C0A8005 */  lui   $t2, %hi(pieventQueue) # $t2, 0x8005
/* 0027B4 70001BB4 3C0B8005 */  lui   $t3, %hi(__osPiAccessQueue) # $t3, 0x8005
/* 0027B8 70001BB8 3C0C7001 */  lui   $t4, %hi(osPiRawStartDma) # $t4, 0x7001
/* 0027BC 70001BBC 3C0D7001 */  lui   $t5, %hi(osEPiRawStartDma) # $t5, 0x7001
/* 0027C0 70001BC0 3C0E8005 */  lui   $t6, %hi(pieventQueue) # $t6, 0x8005
/* 0027C4 70001BC4 248422D0 */  addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
/* 0027C8 70001BC8 24080001 */  li    $t0, 1
/* 0027CC 70001BCC 254A2580 */  addiu $t2, %lo(pieventQueue) # addiu $t2, $t2, 0x2580
/* 0027D0 70001BD0 256B7CA8 */  addiu $t3, %lo(__osPiAccessQueue) # addiu $t3, $t3, 0x7ca8
/* 0027D4 70001BD4 258CBCF0 */  addiu $t4, %lo(osPiRawStartDma) # addiu $t4, $t4, -0x4310
/* 0027D8 70001BD8 25ADDC20 */  addiu $t5, %lo(osEPiRawStartDma) # addiu $t5, $t5, -0x23e0
/* 0027DC 70001BDC 25CE2580 */  addiu $t6, %lo(pieventQueue) # addiu $t6, $t6, 0x2580
/* 0027E0 70001BE0 3C067001 */  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7001
/* 0027E4 70001BE4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0027E8 70001BE8 AE080000 */  sw    $t0, ($s0)
/* 0027EC 70001BEC AE040004 */  sw    $a0, 4($s0)
/* 0027F0 70001BF0 AE0A000C */  sw    $t2, 0xc($s0)
/* 0027F4 70001BF4 AE0B0010 */  sw    $t3, 0x10($s0)
/* 0027F8 70001BF8 AE0C0014 */  sw    $t4, 0x14($s0)
/* 0027FC 70001BFC AE0D0018 */  sw    $t5, 0x18($s0)
/* 002800 70001C00 24C6DD00 */  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x2300
/* 002804 70001C04 AFAE0010 */  sw    $t6, 0x10($sp)
/* 002808 70001C08 00002825 */  move  $a1, $zero
/* 00280C 70001C0C 02003825 */  move  $a3, $s0
/* 002810 70001C10 AE090008 */  sw    $t1, 8($s0)
/* 002814 70001C14 0C003064 */  jal   osCreateThread
/* 002818 70001C18 AFAF0014 */   sw    $t7, 0x14($sp)
/* 00281C 70001C1C 3C048005 */  lui   $a0, %hi(piThread) # $a0, 0x8005
/* 002820 70001C20 0C0030B8 */  jal   osStartThread
/* 002824 70001C24 248422D0 */   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
/* 002828 70001C28 0C0035B0 */  jal   __osRestoreInt
/* 00282C 70001C2C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 002830 70001C30 8FB80028 */  lw    $t8, 0x28($sp)
/* 002834 70001C34 2401FFFF */  li    $at, -1
/* 002838 70001C38 00002025 */  move  $a0, $zero
/* 00283C 70001C3C 53010004 */  beql  $t8, $at, .L70001C50
/* 002840 70001C40 8FBF0024 */   lw    $ra, 0x24($sp)
/* 002844 70001C44 0C003158 */  jal   osSetThreadPri
/* 002848 70001C48 03002825 */   move  $a1, $t8
.L70001C4C:
/* 00284C 70001C4C 8FBF0024 */  lw    $ra, 0x24($sp)
.L70001C50:
/* 002850 70001C50 8FB00020 */  lw    $s0, 0x20($sp)
/* 002854 70001C54 27BD0030 */  addiu $sp, $sp, 0x30
/* 002858 70001C58 03E00008 */  jr    $ra
/* 00285C 70001C5C 00000000 */   nop   
.endif


.section .data
glabel __osPiDevMgr
glabel __osPiDevMgr.active
.word 0
glabel __osPiDevMgr.thread
.word 0
glabel __osPiDevMgr.cmdQueue
.word 0
glabel __osPiDevMgr.evtQueue
.word 0
glabel __osPiDevMgr.acsQueue
.word 0
glabel __osPiDevMgr.dma
.word 0
glabel __osPiDevMgr.edma
.word 0


glabel __osPiTable
.word 0

.section .bss
glabel piThread
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0

glabel piThreadStack
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0

glabel pieventQueue
.word 0, 0, 0, 0, 0, 0

glabel piEventBuf
.word 0, 0
