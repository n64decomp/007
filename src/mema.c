#include "ultra64.h"
#include "mema.h"
#include "deb.h"

/**
 * @file mema.c
 * This file contains memory allocation code. 
 * 
 */

//bss
void *ptr_model_room_buf_secondary;
u32 size_modelroom_buf;
struct s_mem_alloc_table ptr_table_allocated_mem_blocks;

//data
void *ptr_mema_c_debug_notice_list = 0;






void memaSwap(s_mem_alloc_entry *a, s_mem_alloc_entry *b) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = a->addr;
    temp_v1 = a->size;
    a->addr = (s32) b->addr;
    a->size = (s32) b->size;
    b->addr = temp_v0;
    b->size = temp_v1;
}

void memaMerge(s_mem_alloc_entry *a, s_mem_alloc_entry *b) {
    a->size = (s32) (a->size + b->size);
    b->addr = 0;
    b->size = 0;
}






#ifdef NONMATCHING
u32 memaSortMergeEntries(s_mem_alloc_table *param_1)
{
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_s4;
    void *phi_s0;
    u32 phi_s2;
    void *phi_s1;
    void *phi_s0_2;
    ? phi_s3;
    void *phi_s0_3;
    ? phi_s3_2;
    u32 phi_v0;
    ? phi_s3_3;

    temp_s0 = arg0 + 0x10;
    temp_s4 = arg0 + 0xfe8;
    phi_s0 = temp_s0;
    phi_s2 = 0U;
    phi_s1 = arg0 + 8;
    phi_s3 = 0;
    phi_s3_3 = 0;
    if (temp_s4 >= temp_s0)
    {
loop_1:
        phi_s0_2 = phi_s0;
        phi_s2 = phi_s2;
        phi_s1 = phi_s1;
        phi_s3_2 = phi_s3_3;
        if (phi_s0->unk4 != 0)
        {
            if ((u32) phi_s0->unk0 < (u32) phi_s2)
            {
                memaSwap(phi_s0, phi_s1);
            }
            phi_s0_3 = phi_s0;
            phi_v0 = phi_s0->unk0;
            phi_s3_2 = phi_s3_3;
            if (phi_s0->unk0 == (phi_s1->unk4 + phi_s2))
            {
                memaMerge(phi_s1, phi_s0);
                phi_s0_3 = phi_s1;
                phi_v0 = phi_s1->unk0;
                phi_s3_2 = 1;
            }
            phi_s0_2 = phi_s0_3;
            phi_s2 = phi_v0;
            phi_s1 = phi_s0_3;
        }
        temp_s0_2 = phi_s0_2 + 8;
        phi_s0 = temp_s0_2;
        phi_s3 = phi_s3_2;
        phi_s3_3 = phi_s3_2;
        if (temp_s4 >= temp_s0_2)
        {
            goto loop_1;
        }
    }
    return phi_s3;
}
#else
GLOBAL_ASM(
.text
glabel memaSortMergeEntries
/* 00A650 70009A50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00A654 70009A54 AFB40028 */  sw    $s4, 0x28($sp)
/* 00A658 70009A58 AFB00018 */  sw    $s0, 0x18($sp)
/* 00A65C 70009A5C 24900010 */  addiu $s0, $a0, 0x10
/* 00A660 70009A60 24940FE8 */  addiu $s4, $a0, 0xfe8
/* 00A664 70009A64 AFB30024 */  sw    $s3, 0x24($sp)
/* 00A668 70009A68 AFB20020 */  sw    $s2, 0x20($sp)
/* 00A66C 70009A6C AFB1001C */  sw    $s1, 0x1c($sp)
/* 00A670 70009A70 0290082B */  sltu  $at, $s4, $s0
/* 00A674 70009A74 AFBF002C */  sw    $ra, 0x2c($sp)
/* 00A678 70009A78 00009825 */  move  $s3, $zero
/* 00A67C 70009A7C 24910008 */  addiu $s1, $a0, 8
/* 00A680 70009A80 1420001C */  bnez  $at, .L70009AF4
/* 00A684 70009A84 00009025 */   move  $s2, $zero
/* 00A688 70009A88 8E0E0004 */  lw    $t6, 4($s0)
.L70009A8C:
/* 00A68C 70009A8C 51C00016 */  beql  $t6, $zero, .L70009AE8
/* 00A690 70009A90 26100008 */   addiu $s0, $s0, 8
/* 00A694 70009A94 8E020000 */  lw    $v0, ($s0)
/* 00A698 70009A98 02002025 */  move  $a0, $s0
/* 00A69C 70009A9C 0052082B */  sltu  $at, $v0, $s2
/* 00A6A0 70009AA0 50200005 */  beql  $at, $zero, .L70009AB8
/* 00A6A4 70009AA4 8E2F0004 */   lw    $t7, 4($s1)
/* 00A6A8 70009AA8 0C002684 */  jal   memaSwap
/* 00A6AC 70009AAC 02202825 */   move  $a1, $s1
/* 00A6B0 70009AB0 8E020000 */  lw    $v0, ($s0)
/* 00A6B4 70009AB4 8E2F0004 */  lw    $t7, 4($s1)
.L70009AB8:
/* 00A6B8 70009AB8 02202025 */  move  $a0, $s1
/* 00A6BC 70009ABC 02002825 */  move  $a1, $s0
/* 00A6C0 70009AC0 01F2C021 */  addu  $t8, $t7, $s2
/* 00A6C4 70009AC4 54580006 */  bnel  $v0, $t8, .L70009AE0
/* 00A6C8 70009AC8 02008825 */   move  $s1, $s0
/* 00A6CC 70009ACC 0C00268D */  jal   memaMerge
/* 00A6D0 70009AD0 24130001 */   li    $s3, 1
/* 00A6D4 70009AD4 02208025 */  move  $s0, $s1
/* 00A6D8 70009AD8 8E220000 */  lw    $v0, ($s1)
/* 00A6DC 70009ADC 02008825 */  move  $s1, $s0
.L70009AE0:
/* 00A6E0 70009AE0 00409025 */  move  $s2, $v0
/* 00A6E4 70009AE4 26100008 */  addiu $s0, $s0, 8
.L70009AE8:
/* 00A6E8 70009AE8 0290082B */  sltu  $at, $s4, $s0
/* 00A6EC 70009AEC 5020FFE7 */  beql  $at, $zero, .L70009A8C
/* 00A6F0 70009AF0 8E0E0004 */   lw    $t6, 4($s0)
.L70009AF4:
/* 00A6F4 70009AF4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 00A6F8 70009AF8 02601025 */  move  $v0, $s3
/* 00A6FC 70009AFC 8FB30024 */  lw    $s3, 0x24($sp)
/* 00A700 70009B00 8FB00018 */  lw    $s0, 0x18($sp)
/* 00A704 70009B04 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00A708 70009B08 8FB20020 */  lw    $s2, 0x20($sp)
/* 00A70C 70009B0C 8FB40028 */  lw    $s4, 0x28($sp)
/* 00A710 70009B10 03E00008 */  jr    $ra
/* 00A714 70009B14 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif




void memaSortMergeAllEntries(void)
{
    while (memaSortMergeEntries(&ptr_table_allocated_mem_blocks) != 0) {
        ;
    }
}



#ifdef NONMATCHING
s_mem_alloc_entry * memaFindOpening(s_mem_alloc_table *param_1)
{
  u32 entrySize;
  s_mem_alloc_entry *pAStart;
  s_mem_alloc_entry *a;
  int iVar1;
  u32 invalidSize;
  s_mem_alloc_entry *pStart;
  s_mem_alloc_entry *pEnd;
  int count;
  
  pStart = param_1->entries + 2;
  pEnd = param_1->entries + 0x1fd;
  count = 0;
  pAStart = pStart;
  while( 1 ) {
    while (a = pAStart, pEnd < a) {
      count = count + 1;
      pAStart = pStart;
      if (0x1fb < count) {
        if (pEnd < pStart) {
          return pStart;
        }
        invalidSize = 0xffffffff;
        entrySize = param_1->entries[2].size;
        while( 1 ) {
          a = pStart;
          if (invalidSize <= entrySize) {
            entrySize = invalidSize;
            a = pAStart;
          }
          if (pEnd < pStart + 1) break;
          invalidSize = entrySize;
          entrySize = pStart[1].size;
          pStart = pStart + 1;
          pAStart = a;
        }
        return a;
      }
    }
    iVar1 = a->size;
    if (iVar1 == 0) break;
    entrySize = a[1].addr;
    if (entrySize < (u32)a->addr) {
      memaSwap((u8 *)a,(u8 *)(a + 1));
      iVar1 = a->size;
      entrySize = a[1].addr;
      invalidSize = a->addr + iVar1;
    }
    else {
      invalidSize = a->addr + iVar1;
    }
    pAStart = a + 1;
    if (entrySize == invalidSize) {
      count = a[1].size;
      a[1].addr = 0;
      a[1].size = 0;
      a->size = iVar1 + count;
      return a + 1;
    }
  }
  return a;
}
#else
GLOBAL_ASM(
.text
glabel memaFindOpening
/* 00A760 70009B60 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00A764 70009B64 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00A768 70009B68 AFB30020 */  sw    $s3, 0x20($sp)
/* 00A76C 70009B6C AFB10018 */  sw    $s1, 0x18($sp)
/* 00A770 70009B70 AFB00014 */  sw    $s0, 0x14($sp)
/* 00A774 70009B74 24920010 */  addiu $s2, $a0, 0x10
/* 00A778 70009B78 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00A77C 70009B7C 02408025 */  move  $s0, $s2
/* 00A780 70009B80 24910FE8 */  addiu $s1, $a0, 0xfe8
/* 00A784 70009B84 00009825 */  move  $s3, $zero
/* 00A788 70009B88 0232082B */  sltu  $at, $s1, $s2
.L70009B8C:
/* 00A78C 70009B8C 54200020 */  bnezl $at, .L70009C10
/* 00A790 70009B90 26730001 */   addiu $s3, $s3, 1
.L70009B94:
/* 00A794 70009B94 8E040004 */  lw    $a0, 4($s0)
/* 00A798 70009B98 26050008 */  addiu $a1, $s0, 8
/* 00A79C 70009B9C 54800004 */  bnezl $a0, .L70009BB0
/* 00A7A0 70009BA0 8E020008 */   lw    $v0, 8($s0)
/* 00A7A4 70009BA4 1000002C */  b     .L70009C58
/* 00A7A8 70009BA8 02001025 */   move  $v0, $s0
/* 00A7AC 70009BAC 8E020008 */  lw    $v0, 8($s0)
.L70009BB0:
/* 00A7B0 70009BB0 8E030000 */  lw    $v1, ($s0)
/* 00A7B4 70009BB4 0043082B */  sltu  $at, $v0, $v1
/* 00A7B8 70009BB8 50200007 */  beql  $at, $zero, .L70009BD8
/* 00A7BC 70009BBC 00647021 */   addu  $t6, $v1, $a0
/* 00A7C0 70009BC0 0C002684 */  jal   memaSwap
/* 00A7C4 70009BC4 02002025 */   move  $a0, $s0
/* 00A7C8 70009BC8 8E040004 */  lw    $a0, 4($s0)
/* 00A7CC 70009BCC 8E020008 */  lw    $v0, 8($s0)
/* 00A7D0 70009BD0 8E030000 */  lw    $v1, ($s0)
/* 00A7D4 70009BD4 00647021 */  addu  $t6, $v1, $a0
.L70009BD8:
/* 00A7D8 70009BD8 144E0008 */  bne   $v0, $t6, .L70009BFC
/* 00A7DC 70009BDC 26050008 */   addiu $a1, $s0, 8
/* 00A7E0 70009BE0 8E0F000C */  lw    $t7, 0xc($s0)
/* 00A7E4 70009BE4 AE000008 */  sw    $zero, 8($s0)
/* 00A7E8 70009BE8 AE00000C */  sw    $zero, 0xc($s0)
/* 00A7EC 70009BEC 008FC021 */  addu  $t8, $a0, $t7
/* 00A7F0 70009BF0 AE180004 */  sw    $t8, 4($s0)
/* 00A7F4 70009BF4 10000018 */  b     .L70009C58
/* 00A7F8 70009BF8 00A01025 */   move  $v0, $a1
.L70009BFC:
/* 00A7FC 70009BFC 0225082B */  sltu  $at, $s1, $a1
/* 00A800 70009C00 1020FFE4 */  beqz  $at, .L70009B94
/* 00A804 70009C04 00A08025 */   move  $s0, $a1
/* 00A808 70009C08 02408025 */  move  $s0, $s2
/* 00A80C 70009C0C 26730001 */  addiu $s3, $s3, 1
.L70009C10:
/* 00A810 70009C10 2A6101FC */  slti  $at, $s3, 0x1fc
/* 00A814 70009C14 5420FFDD */  bnezl $at, .L70009B8C
/* 00A818 70009C18 0232082B */   sltu  $at, $s1, $s2
/* 00A81C 70009C1C 0232082B */  sltu  $at, $s1, $s2
/* 00A820 70009C20 2402FFFF */  li    $v0, -1
/* 00A824 70009C24 1420000B */  bnez  $at, .L70009C54
/* 00A828 70009C28 02401825 */   move  $v1, $s2
/* 00A82C 70009C2C 8E040004 */  lw    $a0, 4($s0)
.L70009C30:
/* 00A830 70009C30 0082082B */  sltu  $at, $a0, $v0
/* 00A834 70009C34 50200004 */  beql  $at, $zero, .L70009C48
/* 00A838 70009C38 26100008 */   addiu $s0, $s0, 8
/* 00A83C 70009C3C 02001825 */  move  $v1, $s0
/* 00A840 70009C40 00801025 */  move  $v0, $a0
/* 00A844 70009C44 26100008 */  addiu $s0, $s0, 8
.L70009C48:
/* 00A848 70009C48 0230082B */  sltu  $at, $s1, $s0
/* 00A84C 70009C4C 5020FFF8 */  beql  $at, $zero, .L70009C30
/* 00A850 70009C50 8E040004 */   lw    $a0, 4($s0)
.L70009C54:
/* 00A854 70009C54 00601025 */  move  $v0, $v1
.L70009C58:
/* 00A858 70009C58 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00A85C 70009C5C 8FB00014 */  lw    $s0, 0x14($sp)
/* 00A860 70009C60 8FB10018 */  lw    $s1, 0x18($sp)
/* 00A864 70009C64 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00A868 70009C68 8FB30020 */  lw    $s3, 0x20($sp)
/* 00A86C 70009C6C 03E00008 */  jr    $ra
/* 00A870 70009C70 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
void memaAllocRoomBuffer(uint addr,uint size)
{
    int iVar1;
    int iVar2;
    s_mem_alloc_entry *psVar3;
    s_mem_alloc_entry *psVar4;
    s_mem_alloc_entry *psVar5;
    s32 sVar6;
    int iVar7;
    
    iVar7 = (addr - ptr_model_room_buf_secondary) * 0x1fc;
    iVar2 = iVar7 / size_modelroom_buf;
    iVar1 = ptr_table_allocated_mem_blocks.entries[iVar2 + 2].size;
    psVar4 = ptr_table_allocated_mem_blocks.entries + iVar2 + 2;
    if (size_modelroom_buf == 0) {
        trap(0x1c00);
    }
    if ((size_modelroom_buf == -1) && (iVar7 == -0x80000000)) {
        trap(0x1800);
    }
    if (iVar1 == 0) {
        sVar6 = psVar4->addr;
        psVar5 = psVar4;
    }
    else {
        sVar6 = ptr_table_allocated_mem_blocks.entries[iVar2 + 3].size;
        psVar3 = psVar4;
        while (psVar5 = psVar3 + 1, sVar6 != 0) {
            sVar6 = psVar3[2].size;
            psVar3 = psVar5;
        }
        sVar6 = psVar5->addr;
    }
    if (sVar6 == -1) {
        psVar5 = psVar4;
        if (iVar1 != 0) {
            sVar6 = ptr_table_allocated_mem_blocks.entries[iVar2 + 1].size;
            while (psVar5 = psVar4 + -1, sVar6 != 0) {
                sVar6 = psVar4[-2].size;
                psVar4 = psVar5;
            }
        }
        if (psVar5->addr == 0) {
            psVar5 = (s_mem_alloc_entry *)memaFindOpening(&ptr_table_allocated_mem_blocks);
        }
    }
    psVar5->addr = addr;
    psVar5->size = size;
    return;
}
#else
GLOBAL_ASM(
.text
glabel memaAllocRoomBuffer
/* 00A874 70009C74 3C0F8006 */  lui   $t7, %hi(ptr_model_room_buf_secondary) 
/* 00A878 70009C78 8DEF3C20 */  lw    $t7, %lo(ptr_model_room_buf_secondary)($t7)
/* 00A87C 70009C7C 3C098006 */  lui   $t1, %hi(size_modelroom_buf) 
/* 00A880 70009C80 8D293C24 */  lw    $t1, %lo(size_modelroom_buf)($t1)
/* 00A884 70009C84 008FC023 */  subu  $t8, $a0, $t7
/* 00A888 70009C88 0018C9C0 */  sll   $t9, $t8, 7
/* 00A88C 70009C8C 0338C823 */  subu  $t9, $t9, $t8
/* 00A890 70009C90 0019C880 */  sll   $t9, $t9, 2
/* 00A894 70009C94 0329001A */  div   $zero, $t9, $t1
/* 00A898 70009C98 00003012 */  mflo  $a2
/* 00A89C 70009C9C 3C0B8006 */  lui   $t3, %hi(ptr_table_allocated_mem_blocks) 
/* 00A8A0 70009CA0 256B3C28 */  addiu $t3, %lo(ptr_table_allocated_mem_blocks) # addiu $t3, $t3, 0x3c28
/* 00A8A4 70009CA4 000650C0 */  sll   $t2, $a2, 3
/* 00A8A8 70009CA8 014B1021 */  addu  $v0, $t2, $t3
/* 00A8AC 70009CAC 8C480014 */  lw    $t0, 0x14($v0)
/* 00A8B0 70009CB0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A8B4 70009CB4 24470010 */  addiu $a3, $v0, 0x10
/* 00A8B8 70009CB8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A8BC 70009CBC AFA40018 */  sw    $a0, 0x18($sp)
/* 00A8C0 70009CC0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A8C4 70009CC4 00807025 */  move  $t6, $a0
/* 00A8C8 70009CC8 15200002 */  bnez  $t1, .L70009CD4
/* 00A8CC 70009CCC 00000000 */   nop   
/* 00A8D0 70009CD0 0007000D */  break 7
.L70009CD4:
/* 00A8D4 70009CD4 2401FFFF */  li    $at, -1
/* 00A8D8 70009CD8 15210004 */  bne   $t1, $at, .L70009CEC
/* 00A8DC 70009CDC 3C018000 */   lui   $at, 0x8000
/* 00A8E0 70009CE0 17210002 */  bne   $t9, $at, .L70009CEC
/* 00A8E4 70009CE4 00000000 */   nop   
/* 00A8E8 70009CE8 0006000D */  break 6
.L70009CEC:
/* 00A8EC 70009CEC 00E01825 */  move  $v1, $a3
/* 00A8F0 70009CF0 51000006 */  beql  $t0, $zero, .L70009D0C
/* 00A8F4 70009CF4 8C6D0000 */   lw    $t5, ($v1)
/* 00A8F8 70009CF8 8C6C000C */  lw    $t4, 0xc($v1)
.L70009CFC:
/* 00A8FC 70009CFC 24630008 */  addiu $v1, $v1, 8
/* 00A900 70009D00 5580FFFE */  bnezl $t4, .L70009CFC
/* 00A904 70009D04 8C6C000C */   lw    $t4, 0xc($v1)
/* 00A908 70009D08 8C6D0000 */  lw    $t5, ($v1)
.L70009D0C:
/* 00A90C 70009D0C 2401FFFF */  li    $at, -1
/* 00A910 70009D10 55A1000F */  bnel  $t5, $at, .L70009D50
/* 00A914 70009D14 8FB80018 */   lw    $t8, 0x18($sp)
/* 00A918 70009D18 11000005 */  beqz  $t0, .L70009D30
/* 00A91C 70009D1C 00E01825 */   move  $v1, $a3
/* 00A920 70009D20 8C6EFFFC */  lw    $t6, -4($v1)
.L70009D24:
/* 00A924 70009D24 2463FFF8 */  addiu $v1, $v1, -8
/* 00A928 70009D28 55C0FFFE */  bnezl $t6, .L70009D24
/* 00A92C 70009D2C 8C6EFFFC */   lw    $t6, -4($v1)
.L70009D30:
/* 00A930 70009D30 8C6F0000 */  lw    $t7, ($v1)
/* 00A934 70009D34 3C048006 */  lui   $a0, %hi(ptr_table_allocated_mem_blocks)
/* 00A938 70009D38 55E00005 */  bnezl $t7, .L70009D50
/* 00A93C 70009D3C 8FB80018 */   lw    $t8, 0x18($sp)
/* 00A940 70009D40 0C0026D8 */  jal   memaFindOpening
/* 00A944 70009D44 24843C28 */   addiu $a0, %lo(ptr_table_allocated_mem_blocks) # addiu $a0, $a0, 0x3c28
/* 00A948 70009D48 00401825 */  move  $v1, $v0
/* 00A94C 70009D4C 8FB80018 */  lw    $t8, 0x18($sp)
.L70009D50:
/* 00A950 70009D50 AC780000 */  sw    $t8, ($v1)
/* 00A954 70009D54 8FB9001C */  lw    $t9, 0x1c($sp)
/* 00A958 70009D58 AC790004 */  sw    $t9, 4($v1)
/* 00A95C 70009D5C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A960 70009D60 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A964 70009D64 03E00008 */  jr    $ra
/* 00A968 70009D68 00000000 */   nop   
)
#endif



void memaInitDebugNoticeList(void) {
    debCheckAddDebugNoticeListEntry(&ptr_mema_c_debug_notice_list, "mema_c_debug");
}




#ifdef NONMATCHING
void mempInitMallocTable(void *ptr_allocmem,u32 size)
{
    s_mem_alloc_entry *entry;
    
    ptr_table_allocated_mem_blocks.entries[510].addr = -1;
    ptr_table_allocated_mem_blocks.entries[511].addr = -1;
    ptr_table_allocated_mem_blocks.entries[0].addr = 0;
    ptr_table_allocated_mem_blocks.entries[0].size = 0;
    ptr_table_allocated_mem_blocks.entries[1].addr = 0;
    ptr_table_allocated_mem_blocks.entries[1].size = 0;
    ptr_table_allocated_mem_blocks.entries[510].size = 0;
    ptr_table_allocated_mem_blocks.entries[511].size = -1;
    for (entry = ptr_table_allocated_mem_blocks.entries[2]; (entry < (s_mem_alloc_entry *)(&ptr_table_allocated_mem_blocks.entries[0x1fd].addr+1)); ++entry)
    {
        entry->addr = 0;
        entry->size = 0;
    };
    ptr_model_room_buf_secondary = ptr_allocmem;
    size_modelroom_buf = size;
    ptr_table_allocated_mem_blocks.entries[2].addr = (s32)ptr_allocmem;
    ptr_table_allocated_mem_blocks.entries[2].size = size;
}
#else
GLOBAL_ASM(
.text
glabel mempInitMallocTable
/* 00A998 70009D98 3C038006 */  lui   $v1, %hi(ptr_table_allocated_mem_blocks)
/* 00A99C 70009D9C 24633C28 */  addiu $v1, %lo(ptr_table_allocated_mem_blocks) # addiu $v1, $v1, 0x3c28
/* 00A9A0 70009DA0 2406FFFF */  li    $a2, -1
/* 00A9A4 70009DA4 AC660FF0 */  sw    $a2, 0xff0($v1)
/* 00A9A8 70009DA8 AC660FF8 */  sw    $a2, 0xff8($v1)
/* 00A9AC 70009DAC 240EFFFF */  li    $t6, -1
/* 00A9B0 70009DB0 3C068006 */  lui   $a2, %hi(ptr_table_allocated_mem_blocks + 0xFE8)
/* 00A9B4 70009DB4 3C028006 */  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00A9B8 70009DB8 AC600000 */  sw    $zero, ($v1)
/* 00A9BC 70009DBC AC600004 */  sw    $zero, 4($v1)
/* 00A9C0 70009DC0 AC600008 */  sw    $zero, 8($v1)
/* 00A9C4 70009DC4 AC60000C */  sw    $zero, 0xc($v1)
/* 00A9C8 70009DC8 AC600FF4 */  sw    $zero, 0xff4($v1)
/* 00A9CC 70009DCC AC6E0FFC */  sw    $t6, 0xffc($v1)
/* 00A9D0 70009DD0 24423C38 */  addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $v0, $v0, 0x3c38
/* 00A9D4 70009DD4 24C64C10 */  addiu $a2, %lo(ptr_table_allocated_mem_blocks + 0xFE8) # addiu $a2, $a2, 0x4c10
.L70009DD8:
/* 00A9D8 70009DD8 24420008 */  addiu $v0, $v0, 8
/* 00A9DC 70009DDC 00C2082B */  sltu  $at, $a2, $v0
/* 00A9E0 70009DE0 AC40FFF8 */  sw    $zero, -8($v0)
/* 00A9E4 70009DE4 1020FFFC */  beqz  $at, .L70009DD8
/* 00A9E8 70009DE8 AC40FFFC */   sw    $zero, -4($v0)
/* 00A9EC 70009DEC 3C028006 */  lui   $v0, %hi(ptr_model_room_buf_secondary)
/* 00A9F0 70009DF0 3C068006 */  lui   $a2, %hi(size_modelroom_buf)
/* 00A9F4 70009DF4 24C63C24 */  addiu $a2, %lo(size_modelroom_buf) # addiu $a2, $a2, 0x3c24
/* 00A9F8 70009DF8 24423C20 */  addiu $v0, %lo(ptr_model_room_buf_secondary) # addiu $v0, $v0, 0x3c20
/* 00A9FC 70009DFC AC440000 */  sw    $a0, ($v0)
/* 00AA00 70009E00 AC640010 */  sw    $a0, 0x10($v1)
/* 00AA04 70009E04 ACC50000 */  sw    $a1, ($a2)
/* 00AA08 70009E08 03E00008 */  jr    $ra
/* 00AA0C 70009E0C AC650014 */   sw    $a1, 0x14($v1)
)
#endif


void mem_related_calls_sort_merge_entries(void) {
    memaSortMergeEntries(&ptr_table_allocated_mem_blocks);
}



#ifdef NONMATCHING
int mem_related_something_find_first(uint size)

{
  uint uVar1;
  s_mem_alloc_entry *psVar2;
  uint uVar3;
  s32 sVar4;
  int iVar5;
  int iVar6;
  s_mem_alloc_entry *psVar7;
  
  psVar7 = ptr_table_allocated_mem_blocks.entries + 2;
  uVar3 = 0xffffffff;
  psVar2 = (s_mem_alloc_entry *)0x0;
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
    uVar1 = psVar7->size - size;
    if (size <= (uint)psVar7->size) {
      if ((psVar7->addr == -1) ||
         ((uVar1 < uVar3 && ((psVar2 = psVar7, uVar1 < 0x40 || (uVar3 = uVar1, uVar1 < size >> 2))))
         )) break;
    }
    psVar7 = psVar7 + 1;
  } while (iVar6 != 0x10);
  if (psVar2 == (s_mem_alloc_entry *)0x0) {
    iVar6 = 0;
    psVar2 = psVar7;
    if ((uint)psVar7->size < size) {
      uVar3 = psVar7[1].size;
      while (psVar2 = psVar7 + 1, uVar3 < size) {
        uVar3 = psVar7[2].size;
        psVar7 = psVar2;
      }
    }
    if (psVar2->addr == -1) {
      psVar2 = ptr_table_allocated_mem_blocks.entries + 2;
      do {
        memaSortMergeEntries(&ptr_table_allocated_mem_blocks);
        iVar6 = iVar6 + 1;
      } while (iVar6 != 8);
      uVar3 = ptr_table_allocated_mem_blocks.entries[3].size;
      sVar4 = ptr_table_allocated_mem_blocks.entries[2].addr;
      psVar7 = psVar2;
      if ((uint)ptr_table_allocated_mem_blocks.entries[2].size < size) {
        while (psVar2 = psVar7 + 1, uVar3 < size) {
          uVar3 = psVar7[2].size;
          psVar7 = psVar2;
        }
        sVar4 = psVar2->addr;
      }
      if (sVar4 == -1) {
        return 0;
      }
    }
    iVar6 = psVar2->addr;
  }
  else {
    iVar6 = psVar2->addr;
  }
  iVar5 = psVar2->size - size;
  psVar2->addr = iVar6 + size;
  psVar2->size = iVar5;
  if (iVar5 == 0) {
    psVar2->addr = 0;
  }
  return iVar6;
}
#else
GLOBAL_ASM(
.text
glabel mem_related_something_find_first
/* 00AA34 70009E34 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00AA38 70009E38 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00AA3C 70009E3C AFB10018 */  sw    $s1, 0x18($sp)
/* 00AA40 70009E40 00809025 */  move  $s2, $a0
/* 00AA44 70009E44 AFB50028 */  sw    $s5, 0x28($sp)
/* 00AA48 70009E48 AFB00014 */  sw    $s0, 0x14($sp)
/* 00AA4C 70009E4C 3C118006 */  lui   $s1, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AA50 70009E50 AFBF002C */  sw    $ra, 0x2c($sp)
/* 00AA54 70009E54 AFB40024 */  sw    $s4, 0x24($sp)
/* 00AA58 70009E58 AFB30020 */  sw    $s3, 0x20($sp)
/* 00AA5C 70009E5C 26313C38 */  addiu $s1, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s1, $s1, 0x3c38
/* 00AA60 70009E60 2404FFFF */  li    $a0, -1
/* 00AA64 70009E64 00002825 */  move  $a1, $zero
/* 00AA68 70009E68 00008025 */  move  $s0, $zero
/* 00AA6C 70009E6C 2415FFFF */  li    $s5, -1
/* 00AA70 70009E70 24060010 */  li    $a2, 16
.L70009E74:
/* 00AA74 70009E74 8E230004 */  lw    $v1, 4($s1)
/* 00AA78 70009E78 26100001 */  addiu $s0, $s0, 1
/* 00AA7C 70009E7C 0072082B */  sltu  $at, $v1, $s2
/* 00AA80 70009E80 1420000E */  bnez  $at, .L70009EBC
/* 00AA84 70009E84 00721023 */   subu  $v0, $v1, $s2
/* 00AA88 70009E88 8E2E0000 */  lw    $t6, ($s1)
/* 00AA8C 70009E8C 0044082B */  sltu  $at, $v0, $a0
/* 00AA90 70009E90 00127882 */  srl   $t7, $s2, 2
/* 00AA94 70009E94 12AE000B */  beq   $s5, $t6, .L70009EC4
/* 00AA98 70009E98 00000000 */   nop   
/* 00AA9C 70009E9C 10200007 */  beqz  $at, .L70009EBC
/* 00AAA0 70009EA0 2C410040 */   sltiu $at, $v0, 0x40
/* 00AAA4 70009EA4 00402025 */  move  $a0, $v0
/* 00AAA8 70009EA8 14200006 */  bnez  $at, .L70009EC4
/* 00AAAC 70009EAC 02202825 */   move  $a1, $s1
/* 00AAB0 70009EB0 004F082B */  sltu  $at, $v0, $t7
/* 00AAB4 70009EB4 14200003 */  bnez  $at, .L70009EC4
/* 00AAB8 70009EB8 00000000 */   nop   
.L70009EBC:
/* 00AABC 70009EBC 1606FFED */  bne   $s0, $a2, .L70009E74
/* 00AAC0 70009EC0 26310008 */   addiu $s1, $s1, 8
.L70009EC4:
/* 00AAC4 70009EC4 54A00027 */  bnezl $a1, .L70009F64
/* 00AAC8 70009EC8 8CA30000 */   lw    $v1, ($a1)
/* 00AACC 70009ECC 8E380004 */  lw    $t8, 4($s1)
/* 00AAD0 70009ED0 00008025 */  move  $s0, $zero
/* 00AAD4 70009ED4 24140008 */  li    $s4, 8
/* 00AAD8 70009ED8 0312082B */  sltu  $at, $t8, $s2
/* 00AADC 70009EDC 10200006 */  beqz  $at, .L70009EF8
/* 00AAE0 70009EE0 3C138006 */   lui   $s3, %hi(ptr_table_allocated_mem_blocks)
/* 00AAE4 70009EE4 8E39000C */  lw    $t9, 0xc($s1)
.L70009EE8:
/* 00AAE8 70009EE8 26310008 */  addiu $s1, $s1, 8
/* 00AAEC 70009EEC 0332082B */  sltu  $at, $t9, $s2
/* 00AAF0 70009EF0 5420FFFD */  bnezl $at, .L70009EE8
/* 00AAF4 70009EF4 8E39000C */   lw    $t9, 0xc($s1)
.L70009EF8:
/* 00AAF8 70009EF8 8E280000 */  lw    $t0, ($s1)
/* 00AAFC 70009EFC 26733C28 */  addiu $s3, %lo(ptr_table_allocated_mem_blocks) # addiu $s3, $s3, 0x3c28
/* 00AB00 70009F00 56A80017 */  bnel  $s5, $t0, .L70009F60
/* 00AB04 70009F04 02202825 */   move  $a1, $s1
/* 00AB08 70009F08 3C118006 */  lui   $s1, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AB0C 70009F0C 26313C38 */  addiu $s1, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s1, $s1, 0x3c38
.L70009F10:
/* 00AB10 70009F10 0C002694 */  jal   memaSortMergeEntries
/* 00AB14 70009F14 02602025 */   move  $a0, $s3
/* 00AB18 70009F18 26100001 */  addiu $s0, $s0, 1
/* 00AB1C 70009F1C 1614FFFC */  bne   $s0, $s4, .L70009F10
/* 00AB20 70009F20 00000000 */   nop   
/* 00AB24 70009F24 8E690014 */  lw    $t1, 0x14($s3)
/* 00AB28 70009F28 0132082B */  sltu  $at, $t1, $s2
/* 00AB2C 70009F2C 50200007 */  beql  $at, $zero, .L70009F4C
/* 00AB30 70009F30 8E2B0000 */   lw    $t3, ($s1)
/* 00AB34 70009F34 8E2A000C */  lw    $t2, 0xc($s1)
.L70009F38:
/* 00AB38 70009F38 26310008 */  addiu $s1, $s1, 8
/* 00AB3C 70009F3C 0152082B */  sltu  $at, $t2, $s2
/* 00AB40 70009F40 5420FFFD */  bnezl $at, .L70009F38
/* 00AB44 70009F44 8E2A000C */   lw    $t2, 0xc($s1)
/* 00AB48 70009F48 8E2B0000 */  lw    $t3, ($s1)
.L70009F4C:
/* 00AB4C 70009F4C 56AB0004 */  bnel  $s5, $t3, .L70009F60
/* 00AB50 70009F50 02202825 */   move  $a1, $s1
/* 00AB54 70009F54 1000000B */  b     .L70009F84
/* 00AB58 70009F58 00001025 */   move  $v0, $zero
/* 00AB5C 70009F5C 02202825 */  move  $a1, $s1
.L70009F60:
/* 00AB60 70009F60 8CA30000 */  lw    $v1, ($a1)
.L70009F64:
/* 00AB64 70009F64 8CAD0004 */  lw    $t5, 4($a1)
/* 00AB68 70009F68 00726021 */  addu  $t4, $v1, $s2
/* 00AB6C 70009F6C 01B27023 */  subu  $t6, $t5, $s2
/* 00AB70 70009F70 ACAC0000 */  sw    $t4, ($a1)
/* 00AB74 70009F74 15C00002 */  bnez  $t6, .L70009F80
/* 00AB78 70009F78 ACAE0004 */   sw    $t6, 4($a1)
/* 00AB7C 70009F7C ACA00000 */  sw    $zero, ($a1)
.L70009F80:
/* 00AB80 70009F80 00601025 */  move  $v0, $v1
.L70009F84:
/* 00AB84 70009F84 8FBF002C */  lw    $ra, 0x2c($sp)
/* 00AB88 70009F88 8FB00014 */  lw    $s0, 0x14($sp)
/* 00AB8C 70009F8C 8FB10018 */  lw    $s1, 0x18($sp)
/* 00AB90 70009F90 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00AB94 70009F94 8FB30020 */  lw    $s3, 0x20($sp)
/* 00AB98 70009F98 8FB40024 */  lw    $s4, 0x24($sp)
/* 00AB9C 70009F9C 8FB50028 */  lw    $s5, 0x28($sp)
/* 00ABA0 70009FA0 03E00008 */  jr    $ra
/* 00ABA4 70009FA4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



#ifdef NONMATCHING
s32 mem_related_something_find_first_0(s32 arg0, u32 arg1)
{
    s32 temp_a1;
    u32 temp_a2;
    u32 temp_t4;
    s32 phi_a1;
    void *phi_v1;

    if (-1 == ptr_table_allocated_mem_blocks + 0x10)
    {
        return 0;
    }
    phi_a1 = ptr_table_allocated_mem_blocks + 0x10;
    phi_v1 = &ptr_table_allocated_mem_blocks + 0x10;
loop_2:
    if (arg0 != phi_a1)
    {
block_4:
        temp_a1 = phi_v1->unk8;
        phi_a1 = temp_a1;
        phi_v1 = phi_v1 + 8;
        if (-1 != temp_a1)
        {
            goto loop_2;
        }
        return 0;
    }
    temp_a2 = phi_v1->unk4;
    if (temp_a2 < arg1)
    {
        goto block_4;
    }
    temp_t4 = temp_a2 - arg1;
    phi_v1->unk0 = (s32) (phi_a1 + arg1);
    phi_v1->unk4 = temp_t4;
    if (temp_t4 == 0)
    {
        phi_v1->unk0 = 0;
    }
    return arg0;
}
#else
GLOBAL_ASM(
.text
glabel mem_related_something_find_first_0
/* 00ABA8 70009FA8 3C198006 */  lui   $t9, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00ABAC 70009FAC 8F393C38 */  lw    $t9, %lo(ptr_table_allocated_mem_blocks + 0x10)($t9)
/* 00ABB0 70009FB0 3C188006 */  lui   $t8, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00ABB4 70009FB4 240AFFFF */  li    $t2, -1
/* 00ABB8 70009FB8 27183C38 */  addiu $t8, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $t8, $t8, 0x3c38
/* 00ABBC 70009FBC 00A03825 */  move  $a3, $a1
/* 00ABC0 70009FC0 1159000C */  beq   $t2, $t9, .L70009FF4
/* 00ABC4 70009FC4 03001825 */   move  $v1, $t8
/* 00ABC8 70009FC8 8F050000 */  lw    $a1, ($t8)
.L70009FCC:
/* 00ABCC 70009FCC 54850006 */  bnel  $a0, $a1, .L70009FE8
/* 00ABD0 70009FD0 8C650008 */   lw    $a1, 8($v1)
/* 00ABD4 70009FD4 8C660004 */  lw    $a2, 4($v1)
/* 00ABD8 70009FD8 00C7082B */  sltu  $at, $a2, $a3
/* 00ABDC 70009FDC 50200008 */  beql  $at, $zero, .L7000A000
/* 00ABE0 70009FE0 00A75821 */   addu  $t3, $a1, $a3
/* 00ABE4 70009FE4 8C650008 */  lw    $a1, 8($v1)
.L70009FE8:
/* 00ABE8 70009FE8 24630008 */  addiu $v1, $v1, 8
/* 00ABEC 70009FEC 1545FFF7 */  bne   $t2, $a1, .L70009FCC
/* 00ABF0 70009FF0 00000000 */   nop   
.L70009FF4:
/* 00ABF4 70009FF4 03E00008 */  jr    $ra
/* 00ABF8 70009FF8 00001025 */   move  $v0, $zero

/* 00ABFC 70009FFC 00A75821 */  addu  $t3, $a1, $a3
.L7000A000:
/* 00AC00 7000A000 00C76023 */  subu  $t4, $a2, $a3
/* 00AC04 7000A004 AC6B0000 */  sw    $t3, ($v1)
/* 00AC08 7000A008 15800002 */  bnez  $t4, .L7000A014
/* 00AC0C 7000A00C AC6C0004 */   sw    $t4, 4($v1)
/* 00AC10 7000A010 AC600000 */  sw    $zero, ($v1)
.L7000A014:
/* 00AC14 7000A014 00801025 */  move  $v0, $a0
/* 00AC18 7000A018 03E00008 */  jr    $ra
/* 00AC1C 7000A01C 00000000 */   nop   
)
#endif




void mem_related_model_room_buffers_0(u32 addr,u32 size) {
    memaAllocRoomBuffer(addr, size);
}





#ifdef NONMATCHING
void *mem_related_allocated_table_related(void)
{
    void *temp_v1;
    void *phi_v1;

    phi_v1 = &ptr_table_allocated_mem_blocks;
loop_1:
    temp_v1 = phi_v1 + 0x20;
    phi_v1 = temp_v1;
    if (temp_v1 != &ptr_table_allocated_mem_blocks + 0xFE0)
    {
        goto loop_1;
    }
    return &ptr_table_allocated_mem_blocks + 0xFE0;
}
#else
GLOBAL_ASM(
.text
glabel mem_related_allocated_table_related
/* 00AC40 7000A040 3C038006 */  lui   $v1, %hi(ptr_table_allocated_mem_blocks)
/* 00AC44 7000A044 3C028006 */  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0xFE0)
/* 00AC48 7000A048 24424C08 */  addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0xFE0) # addiu $v0, $v0, 0x4c08
/* 00AC4C 7000A04C 24633C28 */  addiu $v1, %lo(ptr_table_allocated_mem_blocks) # addiu $v1, $v1, 0x3c28
/* 00AC50 7000A050 24630020 */  addiu $v1, $v1, 0x20
.L7000A054:
/* 00AC54 7000A054 5462FFFF */  bnel  $v1, $v0, .L7000A054
/* 00AC58 7000A058 24630020 */   addiu $v1, $v1, 0x20
/* 00AC5C 7000A05C 03E00008 */  jr    $ra
/* 00AC60 7000A060 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
f32 mem_related_something_first_related(void)
{
    u32 temp_a1;
    u32 temp_v0;
    u32 phi_v1;
    void *phi_a0;
    u32 phi_v0;
    u32 phi_v1_2;
    u32 phi_v1_3;
    u32 phi_v0_2;

    phi_v1 = 0U;
    phi_a0 = &ptr_table_allocated_mem_blocks + 0x10;
    phi_v0 = 0U;
    phi_v1_2 = 0U;
    phi_v0_2 = 0U;
    if (-1 != ptr_table_allocated_mem_blocks + 0x10)
    {
loop_1:
        temp_a1 = phi_a0->unk4;
        temp_v0 = phi_v0_2 + temp_a1;
        phi_v1_3 = phi_v1;
        if ((u32) phi_v1 < temp_a1)
        {
            phi_v1_3 = temp_a1;
        }
        phi_v1 = phi_v1_3;
        phi_a0 = phi_a0 + 8;
        phi_v0 = temp_v0;
        phi_v1_2 = phi_v1_3;
        phi_v0_2 = temp_v0;
        if (-1 != phi_a0->unk8)
        {
            goto loop_1;
        }
    }
    if (phi_v0 == 0)
    {
        return 0;
    }
    return (f32) (u32) (phi_v0 - phi_v1_2) / (f32) (u32) phi_v0;
}
#else
GLOBAL_ASM(
.text
glabel mem_related_something_first_related
/* 00AC64 7000A064 3C0E8006 */  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00AC68 7000A068 8DCE3C38 */  lw    $t6, %lo(ptr_table_allocated_mem_blocks + 0x10)($t6)
/* 00AC6C 7000A06C 2406FFFF */  li    $a2, -1
/* 00AC70 7000A070 3C048006 */  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AC74 7000A074 00001025 */  move  $v0, $zero
/* 00AC78 7000A078 00001825 */  move  $v1, $zero
/* 00AC7C 7000A07C 10CE000A */  beq   $a2, $t6, .L7000A0A8
/* 00AC80 7000A080 24843C38 */   addiu $a0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $a0, $a0, 0x3c38
/* 00AC84 7000A084 8C850004 */  lw    $a1, 4($a0)
.L7000A088:
/* 00AC88 7000A088 0065082B */  sltu  $at, $v1, $a1
/* 00AC8C 7000A08C 10200002 */  beqz  $at, .L7000A098
/* 00AC90 7000A090 00451021 */   addu  $v0, $v0, $a1
/* 00AC94 7000A094 00A01825 */  move  $v1, $a1
.L7000A098:
/* 00AC98 7000A098 8C8F0008 */  lw    $t7, 8($a0)
/* 00AC9C 7000A09C 24840008 */  addiu $a0, $a0, 8
/* 00ACA0 7000A0A0 54CFFFF9 */  bnel  $a2, $t7, .L7000A088
/* 00ACA4 7000A0A4 8C850004 */   lw    $a1, 4($a0)
.L7000A0A8:
/* 00ACA8 7000A0A8 14400004 */  bnez  $v0, .L7000A0BC
/* 00ACAC 7000A0AC 0043C023 */   subu  $t8, $v0, $v1
/* 00ACB0 7000A0B0 44800000 */  mtc1  $zero, $f0
/* 00ACB4 7000A0B4 03E00008 */  jr    $ra
/* 00ACB8 7000A0B8 00000000 */   nop   

.L7000A0BC:
/* 00ACBC 7000A0BC 44982000 */  mtc1  $t8, $f4
/* 00ACC0 7000A0C0 44825000 */  mtc1  $v0, $f10
/* 00ACC4 7000A0C4 07010005 */  bgez  $t8, .L7000A0DC
/* 00ACC8 7000A0C8 468021A0 */   cvt.s.w $f6, $f4
/* 00ACCC 7000A0CC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 00ACD0 7000A0D0 44814000 */  mtc1  $at, $f8
/* 00ACD4 7000A0D4 00000000 */  nop   
/* 00ACD8 7000A0D8 46083180 */  add.s $f6, $f6, $f8
.L7000A0DC:
/* 00ACDC 7000A0DC 04410005 */  bgez  $v0, .L7000A0F4
/* 00ACE0 7000A0E0 46805420 */   cvt.s.w $f16, $f10
/* 00ACE4 7000A0E4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 00ACE8 7000A0E8 44819000 */  mtc1  $at, $f18
/* 00ACEC 7000A0EC 00000000 */  nop   
/* 00ACF0 7000A0F0 46128400 */  add.s $f16, $f16, $f18
.L7000A0F4:
/* 00ACF4 7000A0F4 46103003 */  div.s $f0, $f6, $f16
/* 00ACF8 7000A0F8 03E00008 */  jr    $ra
/* 00ACFC 7000A0FC 00000000 */   nop   
)
#endif

const char aD_3[] = "%d ";
const char a___[] = "...";
const char aD_5[] = "[%d]";

#ifdef NONMATCHING
void generate_list_alloc_mem(void) {

}
#else
GLOBAL_ASM(
.text
glabel generate_list_alloc_mem
/* 00AD00 7000A100 27BDEF98 */  addiu $sp, $sp, -0x1068
/* 00AD04 7000A104 3C048006 */  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AD08 7000A108 8C843C38 */  lw    $a0, %lo(ptr_table_allocated_mem_blocks + 0x10)($a0)
/* 00AD0C 7000A10C AFB5002C */  sw    $s5, 0x2c($sp)
/* 00AD10 7000A110 AFB00018 */  sw    $s0, 0x18($sp)
/* 00AD14 7000A114 2415FFFF */  li    $s5, -1
/* 00AD18 7000A118 AFB20020 */  sw    $s2, 0x20($sp)
/* 00AD1C 7000A11C 3C108006 */  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AD20 7000A120 AFBF003C */  sw    $ra, 0x3c($sp)
/* 00AD24 7000A124 AFBE0038 */  sw    $fp, 0x38($sp)
/* 00AD28 7000A128 AFB70034 */  sw    $s7, 0x34($sp)
/* 00AD2C 7000A12C AFB60030 */  sw    $s6, 0x30($sp)
/* 00AD30 7000A130 AFB40028 */  sw    $s4, 0x28($sp)
/* 00AD34 7000A134 AFB30024 */  sw    $s3, 0x24($sp)
/* 00AD38 7000A138 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00AD3C 7000A13C 3C038000 */  lui   $v1, 0x8000
/* 00AD40 7000A140 00009025 */  move  $s2, $zero
/* 00AD44 7000A144 26103C38 */  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
/* 00AD48 7000A148 12A40008 */  beq   $s5, $a0, .L7000A16C
/* 00AD4C 7000A14C 00001025 */   move  $v0, $zero
.L7000A150:
/* 00AD50 7000A150 8E0F0008 */  lw    $t7, 8($s0)
/* 00AD54 7000A154 8E0E0004 */  lw    $t6, 4($s0)
/* 00AD58 7000A158 26100008 */  addiu $s0, $s0, 8
/* 00AD5C 7000A15C 16AFFFFC */  bne   $s5, $t7, .L7000A150
/* 00AD60 7000A160 004E1021 */   addu  $v0, $v0, $t6
/* 00AD64 7000A164 3C108006 */  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AD68 7000A168 26103C38 */  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A16C:
/* 00AD6C 7000A16C 3C1E8003 */  lui   $fp, %hi(a___) 
/* 00AD70 7000A170 3C168003 */  lui   $s6, %hi(aD_3)
/* 00AD74 7000A174 27B10054 */  addiu $s1, $sp, 0x54
/* 00AD78 7000A178 26D691E0 */  addiu $s6, %lo(aD_3) # addiu $s6, $s6, -0x6e20
/* 00AD7C 7000A17C 27DE91E4 */  addiu $fp, %lo(a___) # addiu $fp, $fp, -0x6e1c
/* 00AD80 7000A180 00009825 */  move  $s3, $zero
/* 00AD84 7000A184 0000A025 */  move  $s4, $zero
/* 00AD88 7000A188 241700C8 */  li    $s7, 200
.L7000A18C:
/* 00AD8C 7000A18C 12A4000D */  beq   $s5, $a0, .L7000A1C4
/* 00AD90 7000A190 00000000 */   nop   
/* 00AD94 7000A194 8E020004 */  lw    $v0, 4($s0)
.L7000A198:
/* 00AD98 7000A198 0043082B */  sltu  $at, $v0, $v1
/* 00AD9C 7000A19C 10200005 */  beqz  $at, .L7000A1B4
/* 00ADA0 7000A1A0 0262082B */   sltu  $at, $s3, $v0
/* 00ADA4 7000A1A4 50200004 */  beql  $at, $zero, .L7000A1B8
/* 00ADA8 7000A1A8 8E180008 */   lw    $t8, 8($s0)
/* 00ADAC 7000A1AC 00409825 */  move  $s3, $v0
/* 00ADB0 7000A1B0 26940001 */  addiu $s4, $s4, 1
.L7000A1B4:
/* 00ADB4 7000A1B4 8E180008 */  lw    $t8, 8($s0)
.L7000A1B8:
/* 00ADB8 7000A1B8 26100008 */  addiu $s0, $s0, 8
/* 00ADBC 7000A1BC 56B8FFF6 */  bnel  $s5, $t8, .L7000A198
/* 00ADC0 7000A1C0 8E020004 */   lw    $v0, 4($s0)
.L7000A1C4:
/* 00ADC4 7000A1C4 12800022 */  beqz  $s4, .L7000A250
/* 00ADC8 7000A1C8 3C108006 */   lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00ADCC 7000A1CC 26103C38 */  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
/* 00ADD0 7000A1D0 12A4001C */  beq   $s5, $a0, .L7000A244
/* 00ADD4 7000A1D4 0000A025 */   move  $s4, $zero
/* 00ADD8 7000A1D8 8E020004 */  lw    $v0, 4($s0)
.L7000A1DC:
/* 00ADDC 7000A1DC 2A4100C8 */  slti  $at, $s2, 0xc8
/* 00ADE0 7000A1E0 56620011 */  bnel  $s3, $v0, .L7000A228
/* 00ADE4 7000A1E4 8E080008 */   lw    $t0, 8($s0)
/* 00ADE8 7000A1E8 10200008 */  beqz  $at, .L7000A20C
/* 00ADEC 7000A1EC 02202025 */   move  $a0, $s1
/* 00ADF0 7000A1F0 24460200 */  addiu $a2, $v0, 0x200
/* 00ADF4 7000A1F4 0006CA82 */  srl   $t9, $a2, 0xa
/* 00ADF8 7000A1F8 03203025 */  move  $a2, $t9
/* 00ADFC 7000A1FC 0C002B25 */  jal   sprintf
/* 00AE00 7000A200 02C02825 */   move  $a1, $s6
/* 00AE04 7000A204 10000006 */  b     .L7000A220
/* 00AE08 7000A208 02228821 */   addu  $s1, $s1, $v0
.L7000A20C:
/* 00AE0C 7000A20C 16570004 */  bne   $s2, $s7, .L7000A220
/* 00AE10 7000A210 02202025 */   move  $a0, $s1
/* 00AE14 7000A214 0C002B25 */  jal   sprintf
/* 00AE18 7000A218 03C02825 */   move  $a1, $fp
/* 00AE1C 7000A21C 02228821 */  addu  $s1, $s1, $v0
.L7000A220:
/* 00AE20 7000A220 26520001 */  addiu $s2, $s2, 1
/* 00AE24 7000A224 8E080008 */  lw    $t0, 8($s0)
.L7000A228:
/* 00AE28 7000A228 26100008 */  addiu $s0, $s0, 8
/* 00AE2C 7000A22C 56A8FFEB */  bnel  $s5, $t0, .L7000A1DC
/* 00AE30 7000A230 8E020004 */   lw    $v0, 4($s0)
/* 00AE34 7000A234 3C108006 */  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AE38 7000A238 3C048006 */  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AE3C 7000A23C 8C843C38 */  lw    $a0, %lo(ptr_table_allocated_mem_blocks + 0x10)($a0)
/* 00AE40 7000A240 26103C38 */  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A244:
/* 00AE44 7000A244 02601825 */  move  $v1, $s3
/* 00AE48 7000A248 1000FFD0 */  b     .L7000A18C
/* 00AE4C 7000A24C 00009825 */   move  $s3, $zero
.L7000A250:
/* 00AE50 7000A250 2A4100C9 */  slti  $at, $s2, 0xc9
/* 00AE54 7000A254 14200005 */  bnez  $at, .L7000A26C
/* 00AE58 7000A258 02202025 */   move  $a0, $s1
/* 00AE5C 7000A25C 3C058003 */  lui   $a1, %hi(aD_5)
/* 00AE60 7000A260 24A591E8 */  addiu $a1, %lo(aD_5) # addiu $a1, $a1, -0x6e18
/* 00AE64 7000A264 0C002B25 */  jal   sprintf
/* 00AE68 7000A268 02403025 */   move  $a2, $s2
.L7000A26C:
/* 00AE6C 7000A26C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00AE70 7000A270 8FB00018 */  lw    $s0, 0x18($sp)
/* 00AE74 7000A274 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00AE78 7000A278 8FB20020 */  lw    $s2, 0x20($sp)
/* 00AE7C 7000A27C 8FB30024 */  lw    $s3, 0x24($sp)
/* 00AE80 7000A280 8FB40028 */  lw    $s4, 0x28($sp)
/* 00AE84 7000A284 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00AE88 7000A288 8FB60030 */  lw    $s6, 0x30($sp)
/* 00AE8C 7000A28C 8FB70034 */  lw    $s7, 0x34($sp)
/* 00AE90 7000A290 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00AE94 7000A294 03E00008 */  jr    $ra
/* 00AE98 7000A298 27BD1068 */   addiu $sp, $sp, 0x1068
)
#endif




void memaGenerateListsBeforeAfterMerge(void)
{
    s32 count;
    
    generate_list_alloc_mem();
    for (count = 0; count != 0x1fc; count +=1)
    {
        memaSortMergeEntries(&ptr_table_allocated_mem_blocks);
    }
    generate_list_alloc_mem();
}



#ifdef NONMATCHING
void mem_related_something_first_related_0(void *arg0)
{
    s32 temp_s1;
    s32 phi_s1;
    void *phi_s0;

    if (-1 != ptr_table_allocated_mem_blocks + 0x10)
    {
        phi_s1 = ptr_table_allocated_mem_blocks + 0x10;
        phi_s0 = &ptr_table_allocated_mem_blocks + 0x10;
loop_2:
        arg0(phi_s1 + phi_s0->unk4, phi_s0);
        temp_s1 = phi_s0->unk8;
        phi_s1 = temp_s1;
        phi_s0 = phi_s0 + 8;
        if (-1 != temp_s1)
        {
            goto loop_2;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel mem_related_something_first_related_0
/* 00AEF8 7000A2F8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00AEFC 7000A2FC 3C0F8006 */  lui   $t7, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00AF00 7000A300 8DEF3C38 */  lw    $t7, %lo(ptr_table_allocated_mem_blocks + 0x10)($t7)
/* 00AF04 7000A304 AFB30020 */  sw    $s3, 0x20($sp)
/* 00AF08 7000A308 3C0E8006 */  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00AF0C 7000A30C 2413FFFF */  li    $s3, -1
/* 00AF10 7000A310 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00AF14 7000A314 AFB00014 */  sw    $s0, 0x14($sp)
/* 00AF18 7000A318 25CE3C38 */  addiu $t6, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $t6, $t6, 0x3c38
/* 00AF1C 7000A31C 00809025 */  move  $s2, $a0
/* 00AF20 7000A320 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00AF24 7000A324 AFB10018 */  sw    $s1, 0x18($sp)
/* 00AF28 7000A328 126F000A */  beq   $s3, $t7, .L7000A354
/* 00AF2C 7000A32C 01C08025 */   move  $s0, $t6
/* 00AF30 7000A330 8DD10000 */  lw    $s1, ($t6)
/* 00AF34 7000A334 8E180004 */  lw    $t8, 4($s0)
.L7000A338:
/* 00AF38 7000A338 02002825 */  move  $a1, $s0
/* 00AF3C 7000A33C 0240F809 */  jalr  $s2
/* 00AF40 7000A340 02382021 */  addu  $a0, $s1, $t8
/* 00AF44 7000A344 8E110008 */  lw    $s1, 8($s0)
/* 00AF48 7000A348 26100008 */  addiu $s0, $s0, 8
/* 00AF4C 7000A34C 5671FFFA */  bnel  $s3, $s1, .L7000A338
/* 00AF50 7000A350 8E180004 */   lw    $t8, 4($s0)
.L7000A354:
/* 00AF54 7000A354 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00AF58 7000A358 8FB00014 */  lw    $s0, 0x14($sp)
/* 00AF5C 7000A35C 8FB10018 */  lw    $s1, 0x18($sp)
/* 00AF60 7000A360 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00AF64 7000A364 8FB30020 */  lw    $s3, 0x20($sp)
/* 00AF68 7000A368 03E00008 */  jr    $ra
/* 00AF6C 7000A36C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
u32 mem_related_0(void) {
    u32 sp18;

    // Node 0
    sp18 = 0U;
    memaSortMergeAllEntries();
    if (-1 != ptr_table_allocated_mem_blocks + 0x10)
    {
        loop_1:
        // Node 1
        if (sp18 < (u32) ptr_table_allocated_mem_blocks + 0x10.unk4)
        {
            // Node 2
        }
        // Node 3
        if (-1 != ptr_table_allocated_mem_blocks + 0x10.unk8)
        {
            goto loop_1;
        }
    }
    // Node 4
    if (sp18 != 0)
    {
        // Node 5
        return;
        // (possible return value: sp18)
    }
    // Node 6
    return;
    // (possible return value: 0U)
}

#else
GLOBAL_ASM(
.text
glabel mem_related_0
/* 00AF70 7000A370 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00AF74 7000A374 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00AF78 7000A378 0C0026C6 */  jal   memaSortMergeAllEntries
/* 00AF7C 7000A37C AFA00018 */   sw    $zero, 0x18($sp)
/* 00AF80 7000A380 3C0E8006 */  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
/* 00AF84 7000A384 8DCE3C38 */  lw    $t6, %lo(ptr_table_allocated_mem_blocks + 0x10)($t6)
/* 00AF88 7000A388 2405FFFF */  li    $a1, -1
/* 00AF8C 7000A38C 3C028006 */  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0x10)
/* 00AF90 7000A390 8FA40018 */  lw    $a0, 0x18($sp)
/* 00AF94 7000A394 10AE000A */  beq   $a1, $t6, .L7000A3C0
/* 00AF98 7000A398 24423C38 */   addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $v0, $v0, 0x3c38
/* 00AF9C 7000A39C 8C430004 */  lw    $v1, 4($v0)
.L7000A3A0:
/* 00AFA0 7000A3A0 0083082B */  sltu  $at, $a0, $v1
/* 00AFA4 7000A3A4 50200003 */  beql  $at, $zero, .L7000A3B4
/* 00AFA8 7000A3A8 8C4F0008 */   lw    $t7, 8($v0)
/* 00AFAC 7000A3AC 00602025 */  move  $a0, $v1
/* 00AFB0 7000A3B0 8C4F0008 */  lw    $t7, 8($v0)
.L7000A3B4:
/* 00AFB4 7000A3B4 24420008 */  addiu $v0, $v0, 8
/* 00AFB8 7000A3B8 54AFFFF9 */  bnel  $a1, $t7, .L7000A3A0
/* 00AFBC 7000A3BC 8C430004 */   lw    $v1, 4($v0)
.L7000A3C0:
/* 00AFC0 7000A3C0 10800003 */  beqz  $a0, .L7000A3D0
/* 00AFC4 7000A3C4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00AFC8 7000A3C8 10000002 */  b     .L7000A3D4
/* 00AFCC 7000A3CC 00801025 */   move  $v0, $a0
.L7000A3D0:
/* 00AFD0 7000A3D0 00001025 */  move  $v0, $zero
.L7000A3D4:
/* 00AFD4 7000A3D4 03E00008 */  jr    $ra
/* 00AFD8 7000A3D8 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



#ifdef NONMATCHING
//close C, regalloc
u32 mem_related_1(u32 addr,u32 length,u32 maxsize)
{
    if (length < maxsize) {
        if (mem_related_something_find_first_0((addr + length), (maxsize - length)) == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if (maxsize < length) {
            mem_related_model_room_buffers_0((addr + maxsize), (length - maxsize));
        }
        return 1;
    }
}
#else
GLOBAL_ASM(
.text
glabel mem_related_1
/* 00AFDC 7000A3DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00AFE0 7000A3E0 00A6082B */  sltu  $at, $a1, $a2
/* 00AFE4 7000A3E4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00AFE8 7000A3E8 AFA40018 */  sw    $a0, 0x18($sp)
/* 00AFEC 7000A3EC 1020000A */  beqz  $at, .L7000A418
/* 00AFF0 7000A3F0 00A03825 */   move  $a3, $a1
/* 00AFF4 7000A3F4 00852021 */  addu  $a0, $a0, $a1
/* 00AFF8 7000A3F8 0C0027EA */  jal   mem_related_something_find_first_0
/* 00AFFC 7000A3FC 00C52823 */   subu  $a1, $a2, $a1
/* 00B000 7000A400 14400003 */  bnez  $v0, .L7000A410
/* 00B004 7000A404 00000000 */   nop   
/* 00B008 7000A408 1000000A */  b     .L7000A434
/* 00B00C 7000A40C 00001025 */   move  $v0, $zero
.L7000A410:
/* 00B010 7000A410 10000008 */  b     .L7000A434
/* 00B014 7000A414 24020001 */   li    $v0, 1
.L7000A418:
/* 00B018 7000A418 00C7082B */  sltu  $at, $a2, $a3
/* 00B01C 7000A41C 10200004 */  beqz  $at, .L7000A430
/* 00B020 7000A420 8FA90018 */   lw    $t1, 0x18($sp)
/* 00B024 7000A424 01262021 */  addu  $a0, $t1, $a2
/* 00B028 7000A428 0C002808 */  jal   mem_related_model_room_buffers_0
/* 00B02C 7000A42C 00E62823 */   subu  $a1, $a3, $a2
.L7000A430:
/* 00B030 7000A430 24020001 */  li    $v0, 1
.L7000A434:
/* 00B034 7000A434 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00B038 7000A438 27BD0018 */  addiu $sp, $sp, 0x18
/* 00B03C 7000A43C 03E00008 */  jr    $ra
/* 00B040 7000A440 00000000 */   nop   
)
#endif
