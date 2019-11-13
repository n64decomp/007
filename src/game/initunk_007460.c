#include "ultra64.h"




#ifdef NONMATCHING
void cleanupObjectSounds(void) {
    s32 temp_a0;
    void *temp_s0;
    void *phi_s0;

    // Node 0
    phi_s0 = &sfx_related;
loop_1:
    // Node 1
    temp_a0 = *phi_s0;
    if (temp_a0 != 0)
    {
        // Node 2
        if (sfxGetArg0Unk3F(temp_a0) != 0)
        {
            // Node 3
            sfxDeactivate(*phi_s0);
        }
    }
    // Node 4
    temp_s0 = (phi_s0 + 0x18);
    phi_s0 = temp_s0;
    if (temp_s0 != &ptr_list_object_lookup_indices)
    {
        goto loop_1;
    }
    // Node 5
    return;
}
#else
GLOBAL_ASM(
.text
glabel cleanupObjectSounds
/* 03BF90 7F007460 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03BF94 7F007464 AFB10018 */  sw    $s1, 0x18($sp)
/* 03BF98 7F007468 AFB00014 */  sw    $s0, 0x14($sp)
/* 03BF9C 7F00746C 3C108007 */  lui   $s0, %hi(sfx_related)
/* 03BFA0 7F007470 3C118007 */  lui   $s1, %hi(ptr_list_object_lookup_indices)
/* 03BFA4 7F007474 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03BFA8 7F007478 26319C30 */  addiu $s1, %lo(ptr_list_object_lookup_indices) # addiu $s1, $s1, -0x63d0
/* 03BFAC 7F00747C 26109B70 */  addiu $s0, %lo(sfx_related) # addiu $s0, $s0, -0x6490
/* 03BFB0 7F007480 8E040000 */  lw    $a0, ($s0)
.L7F007484:
/* 03BFB4 7F007484 50800008 */  beql  $a0, $zero, .L7F0074A8
/* 03BFB8 7F007488 26100018 */   addiu $s0, $s0, 0x18
/* 03BFBC 7F00748C 0C00237C */  jal   sfxGetArg0Unk3F
/* 03BFC0 7F007490 00000000 */   nop   
/* 03BFC4 7F007494 50400004 */  beql  $v0, $zero, .L7F0074A8
/* 03BFC8 7F007498 26100018 */   addiu $s0, $s0, 0x18
/* 03BFCC 7F00749C 0C002408 */  jal   sfxDeactivate
/* 03BFD0 7F0074A0 8E040000 */   lw    $a0, ($s0)
/* 03BFD4 7F0074A4 26100018 */  addiu $s0, $s0, 0x18
.L7F0074A8:
/* 03BFD8 7F0074A8 5611FFF6 */  bnel  $s0, $s1, .L7F007484
/* 03BFDC 7F0074AC 8E040000 */   lw    $a0, ($s0)
/* 03BFE0 7F0074B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03BFE4 7F0074B4 8FB00014 */  lw    $s0, 0x14($sp)
/* 03BFE8 7F0074B8 8FB10018 */  lw    $s1, 0x18($sp)
/* 03BFEC 7F0074BC 03E00008 */  jr    $ra
/* 03BFF0 7F0074C0 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif


