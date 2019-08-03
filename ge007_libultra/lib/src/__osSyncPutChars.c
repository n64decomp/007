#include "libultra_internal.h"

typedef struct
{
    u8 unk00 : 2;
    u8 pad : 4;
    u8 unk01 : 2;
    u8 unk2[3];
} unkStruct;
u32 D_80334A40 = 0;
u32 D_80334A44 = 1;

void __osSyncPutChars(s32 a0, s32 a1, u8 *a2)
{
    unkStruct sp24;
    s32 sp20;
    u32 sp1c;
    //  addiu $sp, $sp, -0x28
    //  sw    $a0, a0
    //  lw    $t6, a0
    //  lbu   $t0, 0x24($sp)
    //  sw    $a1, a1
    //  andi  $t7, $t6, 3
    //  lw    $t3, a1
    //  sll   $t8, $t7, 6
    //  andi  $t9, $t8, 0xc0
    //  andi  $t1, $t0, 0xff3f
    //  or    $t2, $t9, $t1
    //  andi  $t6, $t2, 0xff
    //  andi  $t4, $t3, 3
    //  andi  $t5, $t4, 3
    //  andi  $t7, $t6, 0xfffc
    //  sb    $t2, 0x24($sp)
    //  or    $t8, $t5, $t7
    //  sw    $ra, 0x14($sp)
    //  sw    $a2, a2
    //  sb    $t8, 0x24($sp)
    //  blez  $t3, .L80329E28
    //   sw    $zero, 0x20($sp)
    sp24.unk00 = a0;
    sp24.unk01 = a1;
    for (sp20 = 0; sp20 < a1; sp20++)
    {
        //.L80329DF8:
        //  lw    $t0, a2
        //  lw    $t9, 0x20($sp)
        //  addu  $t1, $t0, $t9
        //  lbu   $t4, ($t1)
        //  addu  $t2, $sp, $t9
        //  sb    $t4, 0x25($t2)
        sp24.unk2[sp20] = a2[sp20];
        //  lw    $t6, 0x20($sp)
        //  lw    $t7, a1
        //  addiu $t5, $t6, 1
        //  slt   $at, $t5, $t7
        //  bnez  $at, .L80329DF8
        //   sw    $t5, 0x20($sp)
    }
    //.L80329E28:
    //  lui   $a0, %hi(D_80334A44) # $a0, 0x8033
    //  jal   __osAtomicDec
    //   addiu $a0, %lo(D_80334A44) # addiu $a0, $a0, 0x4a44
    //  bnez  $v0, .L80329E50
    //   nop
    while (!__osAtomicDec(&D_80334A44))
        ;
    //.L80329E3C:
    //  lui   $a0, %hi(D_80334A44) # $a0, 0x8033
    //  jal   __osAtomicDec
    //   addiu $a0, %lo(D_80334A44) # addiu $a0, $a0, 0x4a44
    //  beqz  $v0, .L80329E3C
    //   nop
    //.L80329E50:
    //  jal   __osDisableInt
    //   nop
    sp1c = __osDisableInt();
    //  sw    $v0, 0x1c($sp)
    //  addiu $t8, $sp, 0x24
    //  lw    $t3, ($t8)
    //  lui   $t0, 0xc000
    //  jal   __osGetCause
    //   sw    $t3, ($t0)
    *(u32 *)0xC0000000 = *(u32 *)&sp24;
    //  andi  $t1, $v0, 0x2000
    //  bnez  $t1, .L80329E90
    //   nop
    //.L80329E7C:
    //  jal   __osGetCause
    //   nop
    //  andi  $t4, $v0, 0x2000
    //  beqz  $t4, .L80329E7C
    //   nop
    while (!(__osGetCause() & 0x2000))
        ;
    //.L80329E90:
    //  lui   $t9, %hi(D_C000000C) # $t9, 0xc000
    //  sw    $zero, %lo(D_C000000C)($t9)
    *(u32 *)0xC000000C = 0;
    //  lui   $t2, %hi(D_80334A44) # $t2, 0x8033
    //  lw    $t2, %lo(D_80334A44)($t2)
    //  lui   $at, %hi(D_80334A44) # $at, 0x8033
    //  lw    $a0, 0x1c($sp)
    //  addiu $t6, $t2, 1
    //  jal   __osRestoreInt
    //   sw    $t6, %lo(D_80334A44)($at)
    D_80334A44++;
    __osRestoreInt(sp1c);
    //  lw    $ra, 0x14($sp)
    //  addiu $sp, $sp, 0x28
    //  jr    $ra
    //   nop

    //  nop
    //  nop
    //  nop
}
