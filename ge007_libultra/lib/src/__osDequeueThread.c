#include "libultra_internal.h"

//these don't feel like they belong here
//but it makes the most logical since there was printf data before
OSThread *D_80334890 = NULL;
u32 unknown = -1;
OSThread *D_80334898 = (OSThread*)&D_80334890;
OSThread *D_8033489C = (OSThread*)&D_80334890;
OSThread *D_803348A0 = NULL;
u32 D_803348A4 = 0; //UNKNOWN


void __osDequeueThread(OSThread **queue, OSThread *thread)
{
    register OSThread **a2;
    register OSThread *a3;
    a2 = queue;
    a3 = *a2;
    //  move  $a2, $a0
    //  lw    $a3, ($a2)
    //  addiu $sp, $sp, -8
    //  beqz  $a3, .L80326598
    //   nop
    //.L80326574:
    //  bne   $a3, $a1, .L80326588
    //   nop
    while (a3 != NULL)
    {
        if (a3 == thread)
        {
            *a2 = thread->next;
            return;
        }
        //  lw    $t6, ($a1)
        //  b     .L80326598
        //   sw    $t6, ($a2)
        //.L80326588:
        //  move  $a2, $a3
        a2 = &a3->next;
        //  lw    $a3, ($a2)
        a3 = *a2;
        //  bnez  $a3, .L80326574
        //   nop
        //a3 = a3->next;
    }
    //a3->next = thread->next;

    //.L80326598:
    //  jr    $ra
    //   addiu $sp, $sp, 8
}
