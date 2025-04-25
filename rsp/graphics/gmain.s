
 /*
  * File:		gmain.s
  */

Overlay0Address:
  j doInit
 addi $29, $0, 0x110

 #include "ginit.s"

 jal segmented_to_physical
   add $19, $24, $0
 add $20, $0, $22
 jal DMAproc
   addi $17, $0, 0x0

 # $1 = most significant 2 bits of cmd byte << 1
 # $25 = first command word
dispatch_task: #ContDecode
 lh $2, 0xbc($1)
 jr $2
 srl $2, $25, 23



SP_NOOP:
 mfc0 $2, SP_STATUS
 andi $2, $2, 0x80
 bne $2, $0, lbl104c
   lh $21, 0x26($0)
 bgtz $28, lblfe0
   nop
 j lbl10d4
 lh $31, 0x104($0)

lbl_1048:
  lh $21, 0xb6($0)

lbl_104c:
 j lbl10fc
 ori $30, $0, 0x20


load_display_list_dma:
 addi $28, $0, 0x140
 add $21, $0, $31
 addi $20, $0, 0x6a0
 add $19, $0, $26
 addi $18, $0, 0x13f
 jal DMAproc
   addi $17, $0, 0x0
 jr $21
   addi $27, $0, 0x6a0

   // load overlay into IMEM
// $30 = offset into overlay table
// $21 = return address

load_overlay_fcn:
 add $21, $0, $31
load_overlay:
 lw $19, 0x0($30)
 lh $18, 0x4($30)
 lh $20, 0x6($30)
 jal DMAproc
   addi $17, $0, 0x0
 jal DMAwait
   nop
 jr $21
 lw $11, 0xb8($0)
 srl $12, $19, 22
 andi $12, $12, 0x3c



lbl_10a8:
  and $19, $19, $11
 add $13, $0, $12
 lw $12, 0x160($13)
 jr $31



lbl_10b8:
  add $19, $19, $12



lbl_10bc:
  mfc0 $11, DMA_FULL
 bne $11, $0, lbl10bc
   nop



lbl_10c8:
  mtc0 $20, DMA_CACHE
 bgtz $17, lbl10dc
   mtc0 $19, DMA_DRAM



lbl_10d4:
  jr $31
 mtc0 $18, DMA_READ_LENGTH



lbl_10dc:
  jr $31
 mtc0 $18, DMA_WRITE_LENGTH



lbl_10e4:
  mfc0 $11, DMA_BUSY
 bne $11, $0, lbl10e4
   nop
 jr $31
 nop


lbl_10f8:
  add $21, $0, $31



lbl_10fc:
  lw $19, 0x18($29)
 addi $18, $23, 0xf620
 lw $23, 0x44($29)
 blez $18, lbl1174
   add $20, $19, $18
 sub $20, $23, $20
 bgez $20, lbl1138



lbl_1118:
  mfc0 $20, CMD_STATUS



lbl_111c:
  andi $20, $20, 0x400
 bne $20, $0, lbl1118



lbl_1124:
  mfc0 $23, CMD_CURRENT
 lw $19, 0x40($29)
 beq $23, $19, lbl1124
   nop
 mtc0 $19, CMD_START



lbl_1138:
  mfc0 $23, CMD_CURRENT



lbl_113c:
  sub $20, $19, $23
 bgez $20, lbl1154
   add $20, $19, $18
 sub $20, $20, $23
 bgez $20, lbl1138
   nop



lbl_1154:
  add $23, $19, $18
 addi $18, $18, 0xffff
 addi $20, $0, 0x9e0
 jal DMAproc



lbl_1164:
  addi $17, $0, 0x1
 jal DMAwait
   sw $23, 0x18($29)
 mtc0 $23, CMD_END



lbl_1174:
  jr $21



lbl_1178:
  addi $23, $0, 0x9e0
 andi $2, $2, 0xfe
 lh $2, 0x76($2)
 jr $2
 lbu $1, 0xffff($27)
 beq $24, $0, lbl1028
   andi $1, $24, 0xf
 srl $24, $24, 4
 andi $2, $24, 0xf
 srl $24, $24, 4
 andi $3, $25, 0xf
 srl $25, $25, 4
 addi $26, $26, 0xfff8
 addi $27, $27, 0xfff8
 addi $28, $28, 0x8
 sh $25, 0x2($27)
 sw $24, 0x4($27)
 add $5, $0, $0
 lbu $1, 0x2d0($1)
 lbu $2, 0x2d0($2)
 j 0xlbl1264
 lbu $3, 0x2d0($3)
 lbu $5, 0xfffc($27)
 lbu $1, 0xfffd($27)
 lbu $2, 0xfffe($27)
 lbu $3, 0xffff($27)
 sll $5, $5, 2
 sll $1, $1, 2
 sll $2, $2, 2
 sll $3, $3, 2
 addi $1, $1, 0x420
 addi $2, $2, 0x420
 addi $3, $3, 0x420
 sw $1, 0xde0($0)
 sw $2, 0xde4($0)
 sw $3, 0xde8($0)
 lw $4, 0xde0($5)
 j 0xlbl19b0
 lh $30, 0xbe($0)
 lbu $1, 0xfffb($27)
 lhu $2, 0xfff9($27)
 lh $5, 0x30e($1)
 add $5, $5, $2
 j lbl10a8
 sw $24, 0x0($5)
 sw $25, 0x10($29)
 sw $24, 0x14($29)
 lh $2, 0x6($29)
 andi $2, $2, 0xfffd
 andi $3, $25, 0x1
 sll $3, $3, 1
 or $2, $2, $3
 j lbl10a8
 sh $2, 0x6($29)
 j 0xlbl12dc
 addi $7, $29, 0x8
 addi $7, $29, 0xc
 lw $3, 0x0($7)
 addi $8, $0, 0xffff


lbl_1264:
  lbu $5, 0xfffb($27)
 lbu $6, 0xfffa($27)
 addi $2, $0, 0x1
 sllv $2, $2, $5
 addi $2, $2, 0xffff
 sllv $2, $2, $6
 xor $2, $2, $8
 and $2, $2, $3
 or $3, $2, $24
 sw $3, 0x0($7)
 lw $25, 0x8($29)
 j lbl13ac
 lw $24, 0xc($29)
 andi $25, $25, 0x3ff
 ori $2, $0, 0x7030


lbl_12a0:
  lh $3, 0x444($25)
 addi $25, $25, 0x28
 bne $25, $24, 0xlbl12a0
   and $2, $2, $3
 beq $2, $0, lbl1028
   lb $2, 0x4a($29)
 addi $2, $2, 0xfffc
 bltz $2, lbl1048
   addi $3, $2, 0x336
 lw $26, 0x0($3)
 sb $2, 0x4a($29)
 j lbl10a8
 addi $28, $0, 0x0
 lw $2, 0x4($29)
 or $2, $2, $24


lbl_12dc:
  j lbl10a8
 sw $2, 0x4($29)
 lw $2, 0x4($29)
 addi $3, $0, 0xffff
 xor $3, $3, $24
 and $2, $2, $3
 j lbl10a8
 sw $2, 0x4($29)
 j lbl10b8
 sw $24, 0xfffc($29)
 ori $2, $0, 0x0
 j lbl13ac
 lw $25, 0xfffc($29)
 sra $2, $25, 24
 addi $2, $2, 0x3
 bltz $2, lbl132c
   addi $2, $2, 0x18
 jal segmented_to_physical
   add $19, $24, $0
 add $24, $19, $0



lbl_132c:
  sw $25, 0x0($23)
 sw $24, 0x4($23)
 jal lbl1178
   addi $23, $23, 0x8
 bgtz $2, lbl1028
   nop
 j lbl10b8
 andi $2, $2, 0x1fe
 lh $2, 0xc4($2)
 jal DMAwait
   lbu $1, 0xfff9($27)
 jr $2
 andi $6, $1, 0xf
 sbv $v31[6], 0x1c($29)
 andi $8, $1, 0x1
 bne $8, $0, 0xlbl13d8
   andi $7, $1, 0x2
 addi $20, $0, 0x360
 andi $8, $1, 0x4
 beq $8, $0, 0xlbl13a4
   lqv $v26[0], 0x30($22)
 lw $19, 0x24($29)
 lw $8, 0x4c($29)
 addi $17, $0, 0x1
 addi $1, $19, 0x40
 beq $19, $8, 0xlbl13a4
   addi $12, $0, 0x3f
 jal DMAproc
   sw $1, 0x24($29)
 jal DMAwait


lbl_13a4:
 , 0x10($22)
 beq $7, $0, 0xlbl13e4



lbl_13ac:
 , 0x20($22)
 sqv $v26[0], 0x30($20)
 lqv $v29[0], 0x0($22)
 sqv $v28[0], 0x10($20)
 addi $3, $0, 0x3e0
 sqv $v27[0], 0x20($20)
 sqv $v29[0], 0x0($20)
 addi $1, $0, 0x360
 addi $2, $0, 0x3a0
 j 0xlbl1488
 lh $31, 0xbe($0)


lbl_13d8:
 , 0x30($22)
 j 0xlbl1424
 addi $20, $0, 0x3a0


lbl_13e4:
  addiu $3, $0, 0xde0
 addu $1, $0, $22
 jal 0xlbl1488
   addu $2, $0, $20
 sqv $v6[0], 0x30($20)
 sqv $v5[0], 0x10($20)
 lqv $v27[0], 0x0($3)
 j 0xlbl143c
 lqv $v29[0], -0x20($3)
 addi $19, $3, 0x10


lbl_140c:

 addi $18, $1, 0x8


lbl_1414:
 , 0x0($2)
 ldv $v4[0], 0x20($2)
 lqv $v1[0], 0x0($1)
 lqv $v2[0], 0x20($1)


lbl_1424:
 , 0x0($2)
 ldv $v4[8], 0x20($2)
 vmadl $v6, $v4, $v2[0h]
 addi $1, $1, 0x2
 vmadm $v6, $v3, $v2[0h]
 addi $2, $2, 0x8


lbl_143c:

 vmadh $v5, $v3, $v1[0h]
 bne $1, $18, 0xlbl1414
   vmadn $v6, $v31, $v31[0]
 addi $2, $2, 0xffe0
 addi $1, $1, 0x8
 sqv $v5[0], 0x0($3)
 sqv $v6[0], 0x20($3)
 bne $3, $19, 0xlbl140c
   addi $3, $3, 0x10
 jr $31
 nop
 addi $8, $0, 0x320
 lqv $v3[0], 0x50($0)
 lsv $v19[0], 0x2($29)
 lh $3, 0x4($29)
 ldv $v0[0], 0x0($8)
 ldv $v1[0], 0x8($8)
 ldv $v0[8], 0x0($8)


lbl_1488:
 , 0x8($8)
 jr $31
 vmudh $v0, $v0, $v3
 addi $8, $0, 0x3e0
 ldv $v11[0], 0x18($8)
 ldv $v11[8], 0x18($8)
 ldv $v15[0], 0x38($8)
 ldv $v15[8], 0x38($8)
 ldv $v8[0], 0x0($8)
 ldv $v9[0], 0x8($8)
 ldv $v10[0], 0x10($8)
 ldv $v12[0], 0x20($8)
 ldv $v13[0], 0x28($8)
 ldv $v14[0], 0x30($8)
 ldv $v8[8], 0x0($8)
 ldv $v9[8], 0x8($8)
 ldv $v10[8], 0x10($8)
 ldv $v12[8], 0x20($8)
 ldv $v13[8], 0x28($8)
 jr $31
 ldv $v14[8], 0x30($8)
 lqv $v0[0], 0x0($22)
 lh $5, 0x270($1)
 j lbl10a8
 sqv $v0[0], 0x0($5)


lbl_14ec:
  lh $8, 0xbe($0)
 sh $8, 0x106($0)
 srl $1, $1, 4
 addi $5, $1, 0x1
 addi $9, $5, 0x0
 ldv $v2[0], 0x0($22)
 ldv $v2[8], 0x10($22)
 addi $7, $0, 0x420
 sll $8, $6, 5
 sll $6, $6, 3


lbl_1514:
  add $8, $6, $8
 jal 0xlbl14ec
   add $7, $7, $8
 llv $v17[0], 0x14($29)
 jal 0xlbl1514


lbl_1528:
 , 0x14($29)


lbl_152c:

 llv $v18[0], 0x8($22)
 vmadh $v28, $v8, $v2[0h]
 lw $15, 0xc($22)
 vmadn $v28, $v13, $v2[1h]
 lw $16, 0x1c($22)
 vmadh $v28, $v9, $v2[1h]
 andi $1, $3, 0x2
 vmadn $v28, $v14, $v2[2h]
 vmadh $v28, $v10, $v2[2h]
 vmadn $v28, $v15, $v31[1]
 llv $v18[8], 0x18($22)
 vmadh $v29, $v11, $v31[1]
 bne $1, $0, 0xlbl171c
   addi $22, $22, 0x20
 vmudm $v18, $v18, $v17
 lsv $v21[0], 0x76($0)
 vmudn $v20, $v28, $v21[0]
 mfc2 $13, $v29[6]
 andi $13, $13, 0x8000
 srl $13, $13, 13
 vmadh $v21, $v29, $v21[0]
 mfc2 $14, $v29[14]
 andi $14, $14, 0x8000
 srl $14, $14, 9
 vch $v3, $v29, $v29[3h]
 or $14, $14, $13
 vcl $v3, $v28, $v28[3h]
 cfc2 $13, $vcc
 vch $v3, $v29, $v21[3h]
 vcl $v3, $v28, $v20[3h]
 andi $8, $13, 0x703
 andi $13, $13, 0x7030
 or $13, $13, $14
 sll $8, $8, 4
 sll $13, $13, 16
 or $13, $13, $8
 cfc2 $14, $vcc
 andi $8, $14, 0x707
 vadd $v21, $v29, $v31[0]
 andi $14, $14, 0x7070
 vadd $v20, $v28, $v31[0]
 sll $14, $14, 12
 vmudl $v28, $v28, $v19[0]
 or $8, $8, $14
 vmadm $v29, $v29, $v19[0]
 or $8, $8, $13


lbl_15e8:



lbl_15ec:
  sh $8, 0x24($7)
 jal 0xlbl1000
   lh $13, 0xffe6($22)
 vge $v6, $v27, $v31[0]
 sdv $v21[0], 0x0($7)
 vmrg $v6, $v27, $v30[0]
 sdv $v20[0], 0x8($7)
 vmudl $v5, $v20, $v26[3h]
 vmadm $v5, $v21, $v26[3h]
 vmadn $v5, $v20, $v6[3h]
 vmadh $v4, $v21, $v6[3h]
 addi $9, $9, 0xffff
 vmudl $v5, $v5, $v19[0]
 vmadm $v4, $v4, $v19[0]
 vmadn $v5, $v31, $v31[0]
 andi $12, $3, 0x1
 ldv $v2[0], 0x0($22)
 vmudh $v7, $v1, $v31[1]
 ldv $v2[8], 0x10($22)
 vmadn $v7, $v5, $v0
 ldv $v29[0], 0x28($0)
 vmadh $v6, $v4, $v0
 ldv $v29[8], 0x28($0)
 vmadn $v7, $v31, $v31[0]
 vge $v6, $v6, $v29[1q]
 sw $15, 0x10($7)
 beq $12, $0, 0xlbl1684
   vlt $v6, $v6, $v29[0q]
 lqv $v3[0], 0x330($0)
 vmudn $v5, $v5, $v3[0]
 vmadh $v4, $v4, $v3[0]
 vadd $v4, $v4, $v3[1]
 vge $v4, $v4, $v31[0]
 vlt $v4, $v4, $v3[2]
 sbv $v4[5], 0x13($7)
 sw $16, 0x18($7)
 sbv $v4[13], 0x1b($7)
 lw $16, 0x18($7)


lbl_1684:
 , 0x14($7)
 sdv $v6[0], 0x18($7)
 ssv $v7[4], 0x1e($7)
 ssv $v27[6], 0x20($7)
 ssv $v26[6], 0x22($7)
 blez $9, 0xlbl16cc
   addi $9, $9, 0xffff
 sdv $v21[8], 0x28($7)
 sdv $v20[8], 0x30($7)
 slv $v18[8], 0x3c($7)
 sw $16, 0x38($7)
 sdv $v6[8], 0x40($7)
 ssv $v7[12], 0x46($7)
 ssv $v27[14], 0x48($7)
 ssv $v26[14], 0x4a($7)
 sw $8, 0x4c($7)
 addi $7, $7, 0x50
 bgtz $9, 0xlbl152c


lbl_16cc:
  lh $8, 0x106($0)
 jr $8
 nop
 bgtz $1, 0xlbl16f8
   lb $2, 0x4a($29)
 addi $4, $2, 0xffdc
 bgtz $4, lbl1028
   addi $3, $2, 0x336
 addi $2, $2, 0x4
 sw $26, 0x0($3)
 sb $2, 0x4a($29)


lbl_16f8:
  jal segmented_to_physical
   add $19, $24, $0
 add $26, $19, $0
 j lbl10a8
 addi $28, $0, 0x0
 nop


lbl_1710:
  ori $30, $0, 0x10
 beq $0, $0, 0xlbl107c
   lh $21, 0x100($0)


lbl_171c:
  ori $30, $0, 0x18
 beq $0, $0, 0xlbl107c
   lh $21, 0xa0($0)
 ori $2, $0, 0x2800
 mtc0 $2, SP_STATUS
 lqv $v31[0], 0x30($0)
 lqv $v30[0], 0x40($0)
 lw $4, 0xfc4($0)
 andi $4, $4, 0x1
 bne $4, $0, 0xlbl1818
   nop
 lw $23, 0x28($1)
 lw $3, 0x2c($1)
 sw $23, 0x40($29)
 sw $3, 0x44($29)
 mfc0 $4, CMD_STATUS
 andi $4, $4, 0x1
 bne $4, $0, 0xlbl178c
   mfc0 $4, CMD_END
 sub $23, $23, $4
 bgtz $23, 0xlbl178c
   mfc0 $5, CMD_CURRENT
 beq $5, $0, 0xlbl178c
   nop
 beq $5, $4, 0xlbl178c
   nop
 j 0xlbl1828
 ori $3, $4, 0x0


lbl_178c:
  mfc0 $4, CMD_STATUS
 andi $4, $4, 0x400
 bne $4, $0, 0xlbl178c
   addi $4, $0, 0x1
 mtc0 $4, CMD_STATUS
 mtc0 $3, CMD_START
 mtc0 $3, CMD_END



lbl_17a8:
  sw $3, 0x18($29)
 addi $23, $0, 0x9e0


lbl_17b0:
  lw $5, 0x10($1)
 lw $2, 0x8($0)
 lw $3, 0x10($0)
 lw $4, 0x18($0)
 lw $6, 0x20($0)
 add $2, $2, $5
 add $3, $3, $5
 add $4, $4, $5
 add $6, $6, $5
 sw $2, 0x8($0)
 sw $3, 0x10($0)
 sw $4, 0x18($0)
 sw $6, 0x20($0)
 jal 0xlbl10f8
   addi $30, $0, 0x8
 jal lbl10d4
   lw $26, 0x30($1)
 lw $2, 0x20($1)
 sw $2, 0x20($29)


lbl_17fc:
  sw $2, 0x24($29)
 addi $2, $2, 0x280
 sw $2, 0x4c($29)
 lw $2, 0xfff8($0)
 sw $2, 0x108($0)
 j 0xlbl1058
 nop


lbl_1818:
  jal 0xlbl10f8
   addi $30, $0, 0x8
 lw $23, 0x8f0($0)
 lw $28, 0x8e4($0)


lbl_1828:
  lw $27, 0x8e8($0)
 j lbl10a8
 lw $26, 0x8ec($0)
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 nop
 lh $11, 0x24($3)
 lh $8, 0x24($2)
 lh $9, 0x24($1)
 and $12, $11, $8
 or $11, $11, $8
 and $12, $12, $9
 andi $12, $12, 0x7030
 bne $12, $0, lbl1028
   or $11, $11, $9
 andi $11, $11, 0x4343
 bne $11, $0, 0xlbl1710
   llv $v13[0], 0x18($1)
 llv $v14[0], 0x18($2)
 llv $v15[0], 0x18($3)
 lw $13, 0x4($29)


lbl_001c:
  addi $8, $0, 0x8e0
 lsv $v21[0], 0x2($29)
 lsv $v5[0], 0x6($1)
 vsub $v10, $v14, $v13
 lsv $v6[0], 0xe($1)
 vsub $v9, $v15, $v13
 lsv $v5[2], 0x6($2)
 vsub $v12, $v13, $v14
 lsv $v6[2], 0xe($2)
 lsv $v5[4], 0x6($3)
 lsv $v6[4], 0xe($3)
 vmudh $v16, $v9, $v10[1]
 lh $9, 0x1a($1)
 vsar $v18, $v18, $v18[1]
 lh $10, 0x1a($2)


lbl_19a8:

 lh $11, 0x1a($3)


lbl_19b0:

 andi $14, $13, 0x1000
 vsar $v20, $v20, $v20[1]
 andi $15, $13, 0x2000
 vsar $v19, $v19, $v19[0]
 addi $12, $0, 0x0
 slt $7, $10, $9
 blez $7, 0xlbl19f0
   add $7, $10, $0
 add $10, $9, $0
 add $9, $7, $0
 addu $7, $2, $0
 addu $2, $1, $0
 addu $1, $7, $0
 xori $12, $12, 0x1
 nop


lbl_19f0:
  vaddc $v28, $v18, $v20
 slt $7, $11, $10
 vadd $v29, $v17, $v19
 blez $7, 0xlbl1a20
   add $7, $11, $0
 add $11, $10, $0
 add $10, $7, $0
 addu $7, $3, $0
 addu $3, $2, $0
 addu $2, $7, $0
 j 0xlbl1a48
 xori $12, $12, 0x1


lbl_1a20:

 llv $v15[0], 0x18($3)
 vor $v26, $v29, $v28
 llv $v14[0], 0x18($2)
 llv $v13[0], 0x18($1)
 blez $12, 0xlbl1a48
   vsub $v4, $v15, $v14
 vmudn $v28, $v28, $v31[3]
 vmadh $v29, $v29, $v31[3]
 vmadn $v28, $v31, $v31[0]


lbl_1a48:
  vsub $v10, $v14, $v13
 mfc2 $17, $v27[0]
 vsub $v9, $v15, $v13
 mfc2 $16, $v26[0]
 sra $17, $17, 31
 vmov $v29[3], $v29[0]
 and $15, $15, $17
 vmov $v28[3], $v28[0]
 vmov $v4[2], $v10[0]
 beq $16, $0, 0xlbl1f68
   xori $17, $17, 0xffff
 vlt $v27, $v29, $v31[0]
 and $14, $14, $17
 vmov $v4[3], $v10[1]
 or $16, $15, $14
 vmov $v4[4], $v9[0]
 bgtz $16, 0xlbl1f68
   vmov $v4[5], $v9[1]
 mfc2 $7, $v27[0]
 jal 0xlbl1000
   addi $6, $0, 0x80
 bltz $7, 0xlbl1aa8
   lb $5, 0x7($29)
 addi $6, $0, 0x0


lbl_1aa8:

 vmadn $v10, $v31, $v31[0]
 vrcp $v8[1], $v4[1]
 vrcph $v7[1], $v31[0]
 ori $5, $5, 0xc8
 lb $7, 0x12($29)
 vrcp $v8[3], $v4[3]
 vrcph $v7[3], $v31[0]
 vrcp $v8[5], $v4[5]
 vrcph $v7[5], $v31[0]
 or $6, $6, $7
 vmudl $v8, $v8, $v30[4]
 sb $5, 0x0($23)
 vmadm $v7, $v7, $v30[4]
 sb $6, 0x1($23)
 vmadn $v8, $v31, $v31[0]
 vmudh $v4, $v4, $v31[5]
 lsv $v12[0], 0x18($2)
 vmudl $v6, $v6, $v21[0]
 lsv $v12[4], 0x18($1)
 vmadm $v5, $v5, $v21[0]
 lsv $v12[8], 0x18($1)
 vmadn $v6, $v31, $v31[0]
 sll $7, $9, 14
 vmudl $v1, $v8, $v10[0q]
 vmadm $v1, $v7, $v10[0q]
 vmadn $v1, $v8, $v9[0q]
 vmadh $v0, $v7, $v9[0q]
 mtc2 $7, $v2[0]
 vmadn $v1, $v31, $v31[0]
 sw $3, 0x0($8)
 vmudl $v8, $v8, $v31[4]
 vmadm $v7, $v7, $v31[4]
 vmadn $v8, $v31, $v31[0]
 vmudl $v1, $v1, $v31[4]
 vmadm $v0, $v0, $v31[4]
 vmadn $v1, $v31, $v31[0]
 sh $11, 0x2($23)
 vand $v16, $v1, $v30[1]
 sh $9, 0x6($23)
 vmudm $v12, $v12, $v31[4]
 sw $2, 0x4($8)
 vmadn $v13, $v31, $v31[0]
 sw $1, 0x8($8)
 sh $10, 0x4($23)
 vcr $v0, $v0, $v30[6]
 ssv $v12[0], 0x8($23)
 vmudl $v11, $v16, $v2[0]
 ssv $v13[0], 0xa($23)
 vmadm $v10, $v0, $v2[0]
 ssv $v0[2], 0xc($23)
 vmadn $v11, $v31, $v31[0]
 ssv $v1[2], 0xe($23)
 andi $7, $5, 0x2
 addi $15, $8, 0x8
 addi $16, $8, 0x10
 vsubc $v3, $v13, $v11[1q]


lbl_1b8c:
 , 0x14($23)
 vsub $v9, $v12, $v10[1q]
 ssv $v1[10], 0x16($23)
 vsubc $v21, $v6, $v6[1]
 ssv $v0[6], 0x1c($23)
 vlt $v19, $v5, $v5[1]
 ssv $v1[6], 0x1e($23)
 vmrg $v20, $v6, $v6[1]
 ssv $v9[8], 0x10($23)
 vsubc $v21, $v20, $v6[2]
 ssv $v3[8], 0x12($23)
 vlt $v19, $v19, $v5[2]
 ssv $v9[4], 0x18($23)
 vmrg $v20, $v20, $v6[2]
 ssv $v3[4], 0x1a($23)
 addi $23, $23, 0x20
 blez $7, lbl1c94
   vmudl $v20, $v20, $v30[5]
 lw $14, 0x0($15)
 vmadm $v19, $v19, $v30[5]
 lw $17, 0xfffc($15)
 vmadn $v20, $v31, $v31[0]
 lw $18, 0xfff8($15)
 llv $v9[0], 0x14($14)
 llv $v9[8], 0x14($17)
 llv $v22[0], 0x14($18)
 lsv $v11[0], 0x22($14)
 lsv $v12[0], 0x20($14)
 lsv $v11[8], 0x22($17)
 vmov $v9[2], $v30[0]
 lsv $v12[8], 0x20($17)
 vmov $v9[6], $v30[0]
 lsv $v24[0], 0x22($18)
 vmov $v22[2], $v30[0]
 lsv $v25[0], 0x20($18)
 vmudl $v6, $v11, $v20[0]
 vmadm $v6, $v12, $v20[0]
 ssv $v19[0], 0x44($8)
 vmadn $v6, $v11, $v19[0]
 ssv $v20[0], 0x4c($8)
 vmadh $v5, $v12, $v19[0]
 vmudl $v16, $v24, $v20[0]
 vmadm $v16, $v25, $v20[0]
 vmadn $v20, $v24, $v19[0]
 vmadh $v19, $v25, $v19[0]
 vmudm $v16, $v9, $v6[0h]
 vmadh $v9, $v9, $v5[0h]
 vmadn $v10, $v31, $v31[0]
 vmudm $v16, $v22, $v20[0]
 vmadh $v22, $v22, $v19[0]
 vmadn $v23, $v31, $v31[0]
 sdv $v9[8], 0x10($16)
 sdv $v10[8], 0x18($16)
 sdv $v9[0], 0x0($16)
 sdv $v10[0], 0x8($16)
 sdv $v22[0], 0x20($16)
 sdv $v23[0], 0x28($16)
 vabs $v9, $v9, $v9
 llv $v19[0], 0x10($16)
 vabs $v22, $v22, $v22
 llv $v20[0], 0x18($16)
 vabs $v19, $v19, $v19
 vge $v17, $v9, $v22
 vmrg $v18, $v10, $v23
 vge $v17, $v17, $v19
 vmrg $v18, $v18, $v20


lbl_1c94:
 , 0x40($8)
 slv $v18[0], 0x48($8)
 andi $7, $5, 0x7
 blez $7, 0xlbl1f64
   vxor $v18, $v31, $v31
 luv $v25[0], 0x10($3)
 vadd $v16, $v18, $v30[5]
 luv $v15[0], 0x10($1)
 vadd $v24, $v18, $v30[5]
 andi $7, $13, 0x200
 vadd $v5, $v18, $v30[5]
 bgtz $7, 0xlbl1cd4
   luv $v23[0], 0x10($2)
 luv $v25[0], 0x10($4)
 luv $v15[0], 0x10($4)
 luv $v23[0], 0x10($4)


lbl_1cd4:

 vmudm $v15, $v15, $v31[7]
 vmudm $v23, $v23, $v31[7]
 ldv $v16[8], 0x18($8)
 ldv $v15[8], 0x10($8)
 ldv $v24[8], 0x28($8)
 ldv $v23[8], 0x20($8)
 ldv $v5[8], 0x38($8)
 ldv $v25[8], 0x30($8)
 lsv $v16[14], 0x1e($1)
 lsv $v15[14], 0x1c($1)
 lsv $v24[14], 0x1e($2)
 lsv $v23[14], 0x1c($2)
 lsv $v5[14], 0x1e($3)
 lsv $v25[14], 0x1c($3)
 vsubc $v12, $v24, $v16
 vsub $v11, $v23, $v15
 vsubc $v20, $v16, $v5
 vsub $v19, $v15, $v25
 vsubc $v10, $v5, $v16
 vsub $v9, $v25, $v15
 vsubc $v22, $v16, $v24
 vsub $v21, $v15, $v23
 vmudn $v6, $v10, $v4[3]
 vmadh $v6, $v9, $v4[3]
 vmadn $v6, $v22, $v4[5]
 vmadh $v6, $v21, $v4[5]
 vsar $v9, $v9, $v9[0]
 vsar $v10, $v10, $v10[1]
 vmudn $v6, $v12, $v4[4]
 vmadh $v6, $v11, $v4[4]
 vmadn $v6, $v20, $v4[2]
 vmadh $v6, $v19, $v4[2]
 vsar $v11, $v11, $v11[0]
 vsar $v12, $v12, $v12[1]
 vmudl $v6, $v10, $v26[3]
 vmadm $v6, $v9, $v26[3]
 vmadn $v10, $v10, $v27[3]
 vmadh $v9, $v9, $v27[3]
 vmudl $v6, $v12, $v26[3]
 vmadm $v6, $v11, $v26[3]
 vmadn $v12, $v12, $v27[3]
 sdv $v9[0], 0x8($23)
 vmadh $v11, $v11, $v27[3]
 sdv $v10[0], 0x18($23)
 vmudn $v6, $v12, $v31[1]
 vmadh $v6, $v11, $v31[1]
 vmadl $v6, $v10, $v1[5]
 vmadm $v6, $v9, $v1[5]
 vmadn $v14, $v10, $v0[5]
 sdv $v11[0], 0x28($23)
 vmadh $v13, $v9, $v0[5]
 sdv $v12[0], 0x38($23)
 vmudl $v28, $v14, $v2[0]
 sdv $v13[0], 0x20($23)
 vmadm $v6, $v13, $v2[0]
 sdv $v14[0], 0x30($23)
 vmadn $v28, $v31, $v31[0]
 vsubc $v18, $v16, $v28
 vsub $v17, $v15, $v6
 andi $7, $5, 0x4
 blez $7, 0xlbl1ddc
   andi $7, $5, 0x2
 addi $23, $23, 0x40
 sdv $v17[0], -0x40($23)
 sdv $v18[0], -0x30($23)


lbl_1ddc:
  blez $7, 0xlbl1ee0
 andi $7, $5, 0x1
 addi $16, $0, 0x800
 mtc2 $16, $v19[0]
 vabs $v24, $v9, $v9
 ldv $v20[8], 0x40($8)
 vabs $v25, $v11, $v11
 ldv $v21[8], 0x48($8)
 vmudm $v24, $v24, $v19[0]
 vmadn $v26, $v31, $v31[0]
 vmudm $v25, $v25, $v19[0]
 vmadn $v27, $v31, $v31[0]
 vmudl $v21, $v21, $v19[0]
 vmadm $v20, $v20, $v19[0]
 vmadn $v21, $v31, $v31[0]
 vmudn $v26, $v26, $v31[2]
 vmadh $v24, $v24, $v31[2]
 vmadn $v26, $v31, $v31[0]
 vmadn $v23, $v27, $v31[1]
 vmadh $v22, $v25, $v31[1]
 addi $16, $0, 0x40
 vmadn $v6, $v21, $v31[1]
 mtc2 $16, $v19[0]
 vmadh $v5, $v20, $v31[1]
 vsubc $v23, $v6, $v6[5]
 vge $v5, $v5, $v5[5]
 vmrg $v6, $v6, $v6[5]
 vsubc $v23, $v6, $v6[6]
 vge $v5, $v5, $v5[6]
 vmrg $v6, $v6, $v6[6]
 vmudl $v6, $v6, $v19[0]
 vmadm $v5, $v5, $v19[0]
 vmadn $v6, $v31, $v31[0]
 vrcph $v23[0], $v5[4]
 vrcpl $v6[0], $v6[4]
 vrcph $v5[0], $v31[0]
 vmudn $v6, $v6, $v31[2]
 vmadh $v5, $v5, $v31[2]
 vlt $v5, $v5, $v31[1]
 vmrg $v6, $v6, $v31[0]
 vmudl $v20, $v18, $v6[0]
 vmadm $v20, $v17, $v6[0]
 vmadn $v20, $v18, $v5[0]
 vmadh $v19, $v17, $v5[0]
 vmudl $v22, $v10, $v6[0]
 vmadm $v22, $v9, $v6[0]
 vmadn $v22, $v10, $v5[0]
 sdv $v19[8], 0x0($23)
 vmadh $v21, $v9, $v5[0]
 sdv $v20[8], 0x10($23)
 vmudl $v24, $v12, $v6[0]
 vmadm $v24, $v11, $v6[0]
 vmadn $v24, $v12, $v5[0]
 sdv $v21[8], 0x8($23)
 vmadh $v23, $v11, $v5[0]
 sdv $v22[8], 0x18($23)
 vmudl $v26, $v14, $v6[0]
 vmadm $v26, $v13, $v6[0]
 vmadn $v26, $v14, $v5[0]
 sdv $v23[8], 0x28($23)
 vmadh $v25, $v13, $v5[0]
 sdv $v24[8], 0x38($23)
 addi $23, $23, 0x40
 sdv $v25[8], -0x20($23)
 sdv $v26[8], -0x10($23)


lbl_1ee0:
  blez $7, 0xlbl1f64
 vmudn $v14, $v14, $v30[4]
 vmadh $v13, $v13, $v30[4]
 vmadn $v14, $v31, $v31[0]
 vmudn $v16, $v16, $v30[4]
 vmadh $v15, $v15, $v30[4]
 vmadn $v16, $v31, $v31[0]
 ssv $v13[14], 0x8($23)
 vmudn $v10, $v10, $v30[4]
 ssv $v14[14], 0xa($23)
 vmadh $v9, $v9, $v30[4]
 vmadn $v10, $v31, $v31[0]
 vmudn $v12, $v12, $v30[4]
 vmadh $v11, $v11, $v30[4]
 vmadn $v12, $v31, $v31[0]
 lbu $7, 0x11($29)
 sub $7, $0, $7
 beq $7, $0, 0xlbl1f34
   mtc2 $7, $v6[0]
 vch $v11, $v11, $v6[0]
 vcl $v12, $v12, $v31[0]


lbl_1f34:
 , 0x4($23)
 vmudl $v28, $v14, $v2[0]
 ssv $v10[14], 0x6($23)
 vmadm $v6, $v13, $v2[0]
 ssv $v11[14], 0xc($23)
 vmadn $v28, $v31, $v31[0]
 ssv $v12[14], 0xe($23)
 vsubc $v18, $v16, $v28
 vsub $v17, $v15, $v6
 addi $23, $23, 0x10
 ssv $v17[14], -0x10($23)
 ssv $v18[14], -0xe($23)


lbl_1f64:
  jal lbl1178


lbl_1f68:
  nop
 jr $30
 nop
 nop
 vrcph $v27[3], $v29[3]
 vrcpl $v26[3], $v28[3]
 vrcph $v27[3], $v29[7]
 vrcpl $v26[7], $v28[7]
 vrcph $v27[7], $v31[0]
 vmudn $v26, $v26, $v31[2]
 vmadh $v27, $v27, $v31[2]
 vmadn $v26, $v31, $v31[0]
 lqv $v23[0], 0x60($0)
 vxor $v22, $v31, $v31
 vmudl $v24, $v26, $v28
 vmadm $v24, $v27, $v28
 vmadn $v24, $v26, $v29
 vmadh $v25, $v27, $v29
 vsubc $v24, $v22, $v24
 vsub $v25, $v23, $v25
 vmudl $v22, $v26, $v24
 vmadm $v23, $v27, $v24
 vmadn $v26, $v26, $v25
 vmadh $v27, $v27, $v25
 jr $31
 nop
 jal DMAwait
   addi $27, $0, 0x6a0
 lw $25, 0x0($27)
 lw $24, 0x4($27)
 srl $1, $25, 29
 andi $1, $1, 0x6
 addi $26, $26, 0x8
 addi $27, $27, 0x8
 addi $28, $28, 0xfff8
 bgtz $1, 0xlbl0014
   andi $18, $25, 0x1ff
 addi $22, $0, 0x7e0
 beq $0, $0, lbl001c
   sh $31, 0x158($0)
 nop
 nop
 ori $30, $0, 0x18
 beq $0, $0, lbl001c
   lh $21, 0xa0($0)
 sh $3, 0x940($0)
 sh $2, 0x942($0)
 sh $1, 0x944($0)
 sh $0, 0x946($0)
 ori $7, $0, 0xdb8
 ori $30, $0, 0x940
 ori $6, $0, 0xc
 or $5, $30, $30
 xori $30, $30, 0x14
 beq $6, $0, 0xlbl00ec
   lh $11, 0xa6($6)
 addi $6, $6, 0xfffe
 ori $17, $0, 0x0
 or $18, $0, $0
 ori $2, $5, 0x0
 j lbl17fc
 addi $14, $30, 0x2
 and $8, $8, $11
 beq $8, $18, 0xlbl009c
   addi $2, $2, 0x2
 or $20, $10, $0
 sh $10, 0x0($14)
 addi $14, $14, 0x2
 lh $10, 0x0($2)
 bne $10, $0, 0xlbl0060
   lh $8, 0x24($10)
 addi $8, $17, 0xfffe
 bgtz $8, 0xlbl0078
   ori $2, $5, 0x0
 beq $8, $0, 0xlbl0040
   nop
 j lbl19a8
 xor $18, $18, $11
 lh $8, 0xf6($17)
 addi $17, $17, 0x2
 jr $8
 lh $8, 0x102($0)
 mtc2 $10, $v13[0]
 or $10, $20, $0
 mfc2 $20, $v13[0]
 ori $14, $30, 0x0
 lh $8, 0xf8($0)
 sh $8, 0x106($0)
 addi $7, $7, 0x28
 sh $7, 0x0($14)
 sh $0, 0x2($14)
 ldv $v9[0], 0x0($10)
 ldv $v10[0], 0x8($10)
 ldv $v4[0], 0x0($20)
 ldv $v5[0], 0x8($20)
 sll $8, $6, 2
 ldv $v1[0], 0x70($8)
 vmudh $v0, $v1, $v31[3]
 vmudn $v12, $v5, $v1
 vmadh $v11, $v4, $v1
 vmadn $v12, $v31, $v31[0]
 vmadn $v28, $v10, $v0
 vmadh $v29, $v9, $v0
 vmadn $v28, $v31, $v31[0]
 vaddc $v26, $v28, $v28[0q]
 vadd $v27, $v29, $v29[0q]
 vaddc $v28, $v26, $v26[1h]
 vadd $v29, $v27, $v27[1h]
 mfc2 $8, $v29[6]
 vrcph $v7[3], $v29[3]
 vrcpl $v3[3], $v28[3]
 vrcph $v7[3], $v31[0]
 vmudn $v3, $v3, $v31[2]
 bgez $8, 0xlbl013c
   vmadh $v7, $v7, $v31[2]
 vmudn $v3, $v3, $v31[3]
 vmadh $v7, $v7, $v31[3]
 veq $v7, $v7, $v31[0]
 vmrg $v3, $v3, $v31[3]
 vmudl $v28, $v28, $v3[3]
 vmadm $v29, $v29, $v3[3]
 jal 0xlbl1000
   vmadn $v28, $v31, $v31[0]
 vaddc $v28, $v12, $v12[0q]
 vadd $v29, $v11, $v11[0q]
 vaddc $v12, $v28, $v28[1h]
 vadd $v11, $v29, $v29[1h]
 vmudl $v15, $v12, $v26
 vmadm $v15, $v11, $v26
 vmadn $v15, $v12, $v27
 vmadh $v8, $v11, $v27
 vmudl $v28, $v31, $v31[5]
 vmadl $v15, $v15, $v3[3]
 vmadm $v8, $v8, $v3[3]
 vmadn $v15, $v31, $v31[0]
 veq $v8, $v8, $v31[0]
 vmrg $v15, $v15, $v31[3]
 vne $v15, $v15, $v31[0]
 vmrg $v15, $v15, $v31[1]
 vnxor $v8, $v15, $v31[0]
 vaddc $v8, $v8, $v31[1]
 vadd $v29, $v29, $v29
 vmudl $v28, $v5, $v8[3h]
 vmadm $v29, $v4, $v8[3h]
 vmadl $v28, $v10, $v15[3h]
 vmadm $v29, $v9, $v15[3h]
 vmadn $v28, $v31, $v31[0]
 luv $v12[0], 0x10($10)
 luv $v11[0], 0x10($20)
 llv $v12[8], 0x14($10)
 llv $v11[8], 0x14($20)
 vmudm $v18, $v12, $v15[3]
 vmadm $v18, $v11, $v8[3]
 suv $v18[0], 0x0($7)
 sdv $v18[8], 0x8($7)
 ldv $v18[0], 0x8($7)
 jal 0xlbl14ec
   lw $15, 0x0($7)
 mfc2 $10, $v13[0]
 j lbl15ec
 ori $9, $0, 0x1
 lh $8, 0x0($5)
 sh $8, 0xb4($0)
 sh $5, 0x106($0)
 lh $30, 0xfe($0)
 lh $8, 0x106($0)
 lh $3, 0xb4($0)
 lh $2, 0x2($8)
 lh $1, 0x4($8)
 addi $8, $8, 0x2
 bne $1, $0, 0xlbl024c
   sh $8, 0x106($0)
 j lbl10a8
 nop
 ori $30, $0, 0x10
 beq $0, $0, lbl1b8c
   lh $21, 0x100($0)
 lw $1, 0x12c($0)
 sw $15, 0x0($7)
 sw $16, 0x4($7)
 bltz $1, 0xlbl02c4
   lpv $v4[0], 0x0($7)
 luv $v7[0], 0x1d0($1)
 vxor $v27, $v27, $v27
 vge $v7, $v7, $v31[0]
 lpv $v5[0], 0x1c0($1)
 vadd $v27, $v27, $v7
 luv $v7[0], 0x1b0($1)
 vor $v20, $v6, $v31[0]
 vmulf $v6, $v4, $v5
 vadd $v3, $v6, $v6[1q]
 vadd $v6, $v3, $v6[2h]
 vmulf $v7, $v7, $v6[0h]
 bgtz $1, 0xlbl0248
   addi $1, $1, 0xffe0
 suv $v27[0], 0x0($7)
 andi $8, $3, 0x4
 sb $15, 0x3($7)
 sb $16, 0x7($7)
 lw $15, 0x0($7)
 beq $8, $0, 0xlbl0078
   lw $16, 0x4($7)
 andi $8, $3, 0x8
 lpv $v7[0], 0x90($29)
 ldv $v6[0], 0xa0($0)
 vmadn $v20, $v7, $v20[0h]
 beq $8, $0, 0x40002bc
   vmadm $v18, $v31, $v31[0]
 vmulf $v7, $v18, $v18
 vmulf $v7, $v7, $v18
 vmulf $v20, $v7, $v6[1]
 vmacf $v20, $v7, $v6[3]
 vmacf $v18, $v18, $v6[2]
 j lbl15e8
 vadd $v18, $v18, $v31[4]
 andi $1, $1, 0xfff
 sw $1, 0x12c($0)
 jal lbl1528
   addi $8, $0, 0x360
 ori $8, $0, 0xde0
 stv $v8[2], 0x10($8)
 stv $v8[4], 0x20($8)
 stv $v8[12], 0x30($8)
 stv $v8[14], 0x40($8)
 ltv $v8[14], 0x10($8)
 ltv $v8[12], 0x20($8)
 ltv $v8[4], 0x30($8)
 ltv $v8[2], 0x40($8)
 sdv $v12[8], 0x10($8)
 sdv $v13[8], 0x20($8)
 sdv $v14[8], 0x30($8)
 ldv $v12[0], 0x10($8)
 ldv $v13[0], 0x20($8)
 ldv $v14[0], 0x30($8)
 lpv $v5[0], 0x1b8($1)
 vmulf $v5, $v5, $v31[4]
 vmudn $v6, $v12, $v5[0h]
 vmadn $v6, $v13, $v5[1h]
 vmadn $v6, $v14, $v5[2h]
 vmadm $v3, $v31, $v31[0]
 vmudm $v6, $v3, $v31[2]
 vmacf $v3, $v8, $v5[0h]
 vmacf $v3, $v9, $v5[1h]
 vmacf $v3, $v10, $v5[2h]
 vmadn $v6, $v31, $v31[0]
 vmudl $v5, $v6, $v6
 vmadm $v5, $v3, $v6
 vmadn $v5, $v6, $v3
 vmadh $v26, $v3, $v3
 vaddc $v7, $v5, $v5[1q]
 vadd $v4, $v26, $v26[1q]
 vaddc $v7, $v5, $v7[0h]
 vadd $v4, $v26, $v4[0h]
 vrsqh $v11[0], $v4[2]
 vrsql $v15[0], $v7[2]
 vrsqh $v11[0], $v31[0]
 vmudl $v15, $v15, $v30[3]
 vmadm $v11, $v11, $v30[3]
 vmadn $v15, $v31, $v31[0]
 vmudl $v7, $v6, $v15[0]
 vmadm $v7, $v3, $v15[0]
 vmadn $v7, $v6, $v11[0]
 vmadh $v4, $v3, $v11[0]
 vmadn $v7, $v31, $v31[0]
 ldv $v2[0], 0xf8($29)
 vge $v7, $v7, $v2[0]
 vlt $v7, $v7, $v2[1]
 vmudn $v7, $v7, $v2[2]
 spv $v7[0], 0x1c0($1)
 lw $8, 0x1c0($1)
 sw $8, 0x1c4($1)
 bgtz $1, 0xlbl0310
   addi $1, $1, 0xffe0
 j 0xlbl1514
 lh $31, 0xa0($0)
 nop
 j lbl17b0
 nop
 nop




 /*
 * File:		gdone.s
 */

 TaskHalt:
 jal DMAwait
   ori $2, $0, 0x4000
 mtc0 $2, SP_STATUS
 break 0
   nop

 #include "gyield.s"
 	/*
 	 * File:		gyield.s
 	 */
 	RSPYield:
 	ori $2, $0, 0x1000
 	sw $28, 0x8e4($0)
 	sw $27, 0x8e8($0)
 	sw $26, 0x8ec($0)
 	sw $23, 0x8f0($0)
 	lw $19, 0x108($0)
 	ori $20, $0, 0x0
 	ori $18, $0, 0x8ff

 	jal DMAproc
 	  ori $17, $0, 0x1
 	jal DMAwait
 	  nop
 	j TaskDone
 	mtc0 $2, SP_STATUS

 nop
 nop
 addiu $0, $0, 0xbeef
 nop
