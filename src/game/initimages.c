#include "ultra64.h"

extern image_entries;

#ifdef NONMATCHING
void image_entries_load(void) {

}
#else
GLOBAL_ASM(
.text
glabel image_entries_load
/* 035700 7F000BD0 3C048005 */  lui   $a0, 0x8005
/* 035704 7F000BD4 24829300 */  addiu $v0, $a0, -0x6d00
/* 035708 7F000BD8 8C4E0000 */  lw    $t6, ($v0)
/* 03570C 7F000BDC 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 035710 7F000BE0 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 035714 7F000BE4 3407FFFF */  li    $a3, 65535
/* 035718 7F000BE8 01C17824 */  and   $t7, $t6, $at
/* 03571C 7F000BEC 10EF0014 */  beq   $a3, $t7, .L7F000C40
/* 035720 7F000BF0 00001825 */   move  $v1, $zero
/* 035724 7F000BF4 3C188005 */  lui   $t8, %hi(image_entries) # $t8, 0x8005
/* 035728 7F000BF8 27189300 */  addiu $t8, %lo(image_entries) # addiu $t8, $t8, -0x6d00
/* 03572C 7F000BFC 8F050000 */  lw    $a1, ($t8)
/* 035730 7F000C00 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 035734 7F000C04 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 035738 7F000C08 00A13024 */  and   $a2, $a1, $at
.L7F000C0C:
/* 03573C 7F000C0C 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 035740 7F000C10 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 035744 7F000C14 0061C824 */  and   $t9, $v1, $at
/* 035748 7F000C18 03254026 */  xor   $t0, $t9, $a1
/* 03574C 7F000C1C 00084A00 */  sll   $t1, $t0, 8
/* 035750 7F000C20 00095202 */  srl   $t2, $t1, 8
/* 035754 7F000C24 01455826 */  xor   $t3, $t2, $a1
/* 035758 7F000C28 8C450008 */  lw    $a1, 8($v0)
/* 03575C 7F000C2C 00661821 */  addu  $v1, $v1, $a2
/* 035760 7F000C30 AC4B0000 */  sw    $t3, ($v0)
/* 035764 7F000C34 00A13024 */  and   $a2, $a1, $at
/* 035768 7F000C38 14E6FFF4 */  bne   $a3, $a2, .L7F000C0C
/* 03576C 7F000C3C 24420008 */   addiu $v0, $v0, 8
.L7F000C40:
/* 035770 7F000C40 8C450000 */  lw    $a1, ($v0)
/* 035774 7F000C44 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 035778 7F000C48 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 03577C 7F000C4C 00616024 */  and   $t4, $v1, $at
/* 035780 7F000C50 01856826 */  xor   $t5, $t4, $a1
/* 035784 7F000C54 000D7200 */  sll   $t6, $t5, 8
/* 035788 7F000C58 000E7A02 */  srl   $t7, $t6, 8
/* 03578C 7F000C5C 01E5C026 */  xor   $t8, $t7, $a1
/* 035790 7F000C60 03E00008 */  jr    $ra
/* 035794 7F000C64 AC580000 */   sw    $t8, ($v0)
)
#endif

