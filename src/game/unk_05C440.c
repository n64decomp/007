#include "ultra64.h"



#ifdef NONMATCHING
f32 sub_GAME_7F05C440(f32 arg0) {
    f32 temp_f2;

    // Node 0
    if (arg0 <= 0.0f)
    {
        // Node 1
        return (f32) (s32) arg0;
    }
    // Node 2
    temp_f2 = (f32) (s32) arg0;
    if (arg0 == temp_f2)
    {
        // Node 3
        return temp_f2;
    }
    // Node 4
    return (temp_f2 + 1.0f);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05C440
/* 090F70 7F05C440 44802000 */  mtc1  $zero, $f4
/* 090F74 7F05C444 00000000 */  nop   
/* 090F78 7F05C448 4604603E */  c.le.s $f12, $f4
/* 090F7C 7F05C44C 00000000 */  nop   
/* 090F80 7F05C450 45020008 */  bc1fl .L7F05C474
/* 090F84 7F05C454 4600628D */   trunc.w.s $f10, $f12
/* 090F88 7F05C458 4600618D */  trunc.w.s $f6, $f12
/* 090F8C 7F05C45C 440F3000 */  mfc1  $t7, $f6
/* 090F90 7F05C460 00000000 */  nop   
/* 090F94 7F05C464 448F4000 */  mtc1  $t7, $f8
/* 090F98 7F05C468 03E00008 */  jr    $ra
/* 090F9C 7F05C46C 46804020 */   cvt.s.w $f0, $f8

/* 090FA0 7F05C470 4600628D */  trunc.w.s $f10, $f12
.L7F05C474:
/* 090FA4 7F05C474 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090FA8 7F05C478 44195000 */  mfc1  $t9, $f10
/* 090FAC 7F05C47C 00000000 */  nop   
/* 090FB0 7F05C480 44998000 */  mtc1  $t9, $f16
/* 090FB4 7F05C484 00000000 */  nop   
/* 090FB8 7F05C488 468080A0 */  cvt.s.w $f2, $f16
/* 090FBC 7F05C48C 46026032 */  c.eq.s $f12, $f2
/* 090FC0 7F05C490 00000000 */  nop   
/* 090FC4 7F05C494 45020004 */  bc1fl .L7F05C4A8
/* 090FC8 7F05C498 44819000 */   mtc1  $at, $f18
/* 090FCC 7F05C49C 03E00008 */  jr    $ra
/* 090FD0 7F05C4A0 46001006 */   mov.s $f0, $f2

/* 090FD4 7F05C4A4 44819000 */  mtc1  $at, $f18
.L7F05C4A8:
/* 090FD8 7F05C4A8 00000000 */  nop   
/* 090FDC 7F05C4AC 46121000 */  add.s $f0, $f2, $f18
/* 090FE0 7F05C4B0 03E00008 */  jr    $ra
/* 090FE4 7F05C4B4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F05C4B8(f32 arg0) {
    s32 temp_f8;

    // Node 0
    if (arg0 <= 0.0f)
    {
        // Node 1
        return (s32) arg0;
    }
    // Node 2
    temp_f8 = (s32) arg0;
    if (arg0 == (f32) temp_f8)
    {
        // Node 3
        return temp_f8;
    }
    // Node 4
    return (temp_f8 + 1);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05C4B8
/* 090FE8 7F05C4B8 44802000 */  mtc1  $zero, $f4
/* 090FEC 7F05C4BC 00000000 */  nop   
/* 090FF0 7F05C4C0 4604603E */  c.le.s $f12, $f4
/* 090FF4 7F05C4C4 00000000 */  nop   
/* 090FF8 7F05C4C8 45020006 */  bc1fl .L7F05C4E4
/* 090FFC 7F05C4CC 4600620D */   trunc.w.s $f8, $f12
/* 091000 7F05C4D0 4600618D */  trunc.w.s $f6, $f12
/* 091004 7F05C4D4 44023000 */  mfc1  $v0, $f6
/* 091008 7F05C4D8 03E00008 */  jr    $ra
/* 09100C 7F05C4DC 00000000 */   nop   

/* 091010 7F05C4E0 4600620D */  trunc.w.s $f8, $f12
.L7F05C4E4:
/* 091014 7F05C4E4 44034000 */  mfc1  $v1, $f8
/* 091018 7F05C4E8 00000000 */  nop   
/* 09101C 7F05C4EC 44835000 */  mtc1  $v1, $f10
/* 091020 7F05C4F0 24620001 */  addiu $v0, $v1, 1
/* 091024 7F05C4F4 46805420 */  cvt.s.w $f16, $f10
/* 091028 7F05C4F8 46106032 */  c.eq.s $f12, $f16
/* 09102C 7F05C4FC 00000000 */  nop   
/* 091030 7F05C500 45000003 */  bc1f  .L7F05C510
/* 091034 7F05C504 00000000 */   nop   
/* 091038 7F05C508 03E00008 */  jr    $ra
/* 09103C 7F05C50C 00601025 */   move  $v0, $v1

.L7F05C510:
/* 091040 7F05C510 03E00008 */  jr    $ra
/* 091044 7F05C514 00000000 */   nop   
)
#endif



