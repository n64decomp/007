#include "ultra64.h"
#include "initunk_0072B0.h"
#include "game/unk_093880.h"

#ifdef NONMATCHING
void sub_GAME_7F0072B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0072B0
/* 03BDE0 7F0072B0 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 03BDE4 7F0072B4 A0209E30 */  sb    $zero, %lo(off_CODE_bss_80079E30)($at)
/* 03BDE8 7F0072B8 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30+1)
/* 03BDEC 7F0072BC A0209E31 */  sb    $zero, %lo(off_CODE_bss_80079E30+1)($at)
/* 03BDF0 7F0072C0 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30+2)
/* 03BDF4 7F0072C4 3C038008 */  lui   $v1, %hi(off_CODE_bss_80079E30+3)
/* 03BDF8 7F0072C8 3C028008 */  lui   $v0, %hi(off_CODE_bss_80079E30+0x4b)
/* 03BDFC 7F0072CC 24429E7B */  addiu $v0, %lo(off_CODE_bss_80079E30+0x4b) # addiu $v0, $v0, -0x6185
/* 03BE00 7F0072D0 24639E33 */  addiu $v1, %lo(off_CODE_bss_80079E30+3) # addiu $v1, $v1, -0x61cd
/* 03BE04 7F0072D4 A0209E32 */  sb    $zero, %lo(off_CODE_bss_80079E30+2)($at)
.L7F0072D8:
/* 03BE08 7F0072D8 24630004 */  addiu $v1, $v1, 4
/* 03BE0C 7F0072DC A060FFFD */  sb    $zero, -3($v1)
/* 03BE10 7F0072E0 A060FFFE */  sb    $zero, -2($v1)
/* 03BE14 7F0072E4 A060FFFF */  sb    $zero, -1($v1)
/* 03BE18 7F0072E8 1462FFFB */  bne   $v1, $v0, .L7F0072D8
/* 03BE1C 7F0072EC A060FFFC */   sb    $zero, -4($v1)
/* 03BE20 7F0072F0 03E00008 */  jr    $ra
/* 03BE24 7F0072F4 00000000 */   nop   
)
#endif


void disable_onscreen_cheat_text(void)
{
  pPlayer->something_with_cheat_text = 0;
  pPlayer->can_display_cheat_text = 0;
}

