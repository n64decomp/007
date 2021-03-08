#include "ultra64.h"
#include "game/mainmenu.h"

#ifdef NONMATCHING
u32 mempAllocBytesInBank(u32 bytes,u8 bank);

void init_menus_or_reset(void)
{
    current_menu = ~MENU_LEGAL_SCREEN;
    maybe_prev_menu = ~MENU_LEGAL_SCREEN;
    screen_size = SCREEN_SIZE_320x240;
    spectrum_related_flag = TRUE;
    is_emulating_spectrum = FALSE;
    folder_selection_screen_option_icon = 0;
    folder_selected_for_deletion = -1;
    folder_selected_for_deletion_choice = 1;
    tab_1_highlight = FALSE;
    tab_2_highlight = FALSE;
    tab_3_highlight = FALSE;
    maybe_is_in_menu = TRUE;
    if (prev_keypresses) {
        menu_update = MENU_FILE_SELECT;
    }
    if (menu_update < 0) {
        menu_update = MENU_FILE_SELECT;
    }
    ptr_logo_and_walletbond_DL = (Gfx *)mempAllocBytesInBank(0x78000,'\x04');

    //incorrect here
    ptr_menu_videobuffer = (u8 *)((mempAllocBytesInBank(0x4b040,'\x04') + 0x3f) & 0xffffffc0);
    ptr_folder_object_instance = 0x0;
    set0_never_used = 0;
    set0_never_used_0 = 0;
    D_8002A968 = 0;
    alloc_intro_matrices();
}
#else
GLOBAL_ASM(
.text
glabel init_menus_or_reset
/* 035850 7F000D20 2402FFFF */  li    $v0, -1
/* 035854 7F000D24 3C018003 */  lui   $at, %hi(current_menu)
/* 035858 7F000D28 AC22A8C0 */  sw    $v0, %lo(current_menu)($at)
/* 03585C 7F000D2C 3C018003 */  lui   $at, %hi(maybe_prev_menu)
/* 035860 7F000D30 AC22A8C8 */  sw    $v0, %lo(maybe_prev_menu)($at)
/* 035864 7F000D34 3C018003 */  lui   $at, %hi(screen_size)
/* 035868 7F000D38 AC20A940 */  sw    $zero, %lo(screen_size)($at)
/* 03586C 7F000D3C 24030001 */  li    $v1, 1
/* 035870 7F000D40 3C018003 */  lui   $at, %hi(spectrum_related_flag)
/* 035874 7F000D44 AC23A944 */  sw    $v1, %lo(spectrum_related_flag)($at)
/* 035878 7F000D48 3C018003 */  lui   $at, %hi(is_emulating_spectrum)
/* 03587C 7F000D4C AC20A948 */  sw    $zero, %lo(is_emulating_spectrum)($at)
/* 035880 7F000D50 3C018003 */  lui   $at, %hi(folder_selection_screen_option_icon)
/* 035884 7F000D54 AC20A918 */  sw    $zero, %lo(folder_selection_screen_option_icon)($at)
/* 035888 7F000D58 3C018003 */  lui   $at, %hi(folder_selected_for_deletion)
/* 03588C 7F000D5C AC22A91C */  sw    $v0, %lo(folder_selected_for_deletion)($at)
/* 035890 7F000D60 3C018003 */  lui   $at, %hi(folder_selected_for_deletion_choice)
/* 035894 7F000D64 AC23A920 */  sw    $v1, %lo(folder_selected_for_deletion_choice)($at)
/* 035898 7F000D68 3C018003 */  lui   $at, %hi(tab_1_highlight)
/* 03589C 7F000D6C AC20A8DC */  sw    $zero, %lo(tab_1_highlight)($at)
/* 0358A0 7F000D70 3C018003 */  lui   $at, %hi(tab_2_highlight)
/* 0358A4 7F000D74 AC20A8E0 */  sw    $zero, %lo(tab_2_highlight)($at)
/* 0358A8 7F000D78 3C0E8003 */  lui   $t6, %hi(prev_keypresses) 
/* 0358AC 7F000D7C 8DCEA934 */  lw    $t6, %lo(prev_keypresses)($t6)
/* 0358B0 7F000D80 3C018003 */  lui   $at, %hi(tab_3_highlight)
/* 0358B4 7F000D84 AC20A8E4 */  sw    $zero, %lo(tab_3_highlight)($at)
/* 0358B8 7F000D88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0358BC 7F000D8C 3C018003 */  lui   $at, %hi(maybe_is_in_menu)
/* 0358C0 7F000D90 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0358C4 7F000D94 11C00005 */  beqz  $t6, .L7F000DAC
/* 0358C8 7F000D98 AC23A93C */   sw    $v1, %lo(maybe_is_in_menu)($at)
/* 0358CC 7F000D9C 3C028003 */  lui   $v0, %hi(menu_update)
/* 0358D0 7F000DA0 2442A8C4 */  addiu $v0, %lo(menu_update) # addiu $v0, $v0, -0x573c
/* 0358D4 7F000DA4 240F0005 */  li    $t7, 5
/* 0358D8 7F000DA8 AC4F0000 */  sw    $t7, ($v0)
.L7F000DAC:
/* 0358DC 7F000DAC 3C028003 */  lui   $v0, %hi(menu_update)
/* 0358E0 7F000DB0 2442A8C4 */  addiu $v0, %lo(menu_update) # addiu $v0, $v0, -0x573c
/* 0358E4 7F000DB4 8C580000 */  lw    $t8, ($v0)
/* 0358E8 7F000DB8 3C040007 */  lui   $a0, (0x00078000 >> 16) # lui $a0, 7
/* 0358EC 7F000DBC 24190005 */  li    $t9, 5
/* 0358F0 7F000DC0 07010002 */  bgez  $t8, .L7F000DCC
/* 0358F4 7F000DC4 34848000 */   ori   $a0, (0x00078000 & 0xFFFF) # ori $a0, $a0, 0x8000
/* 0358F8 7F000DC8 AC590000 */  sw    $t9, ($v0)
.L7F000DCC:
/* 0358FC 7F000DCC 0C0025C8 */  jal   mempAllocBytesInBank
/* 035900 7F000DD0 24050004 */   li    $a1, 4
/* 035904 7F000DD4 3C018003 */  lui   $at, %hi(ptr_logo_and_walletbond_DL)
/* 035908 7F000DD8 3C040004 */  lui   $a0, (0x0004B040 >> 16) # lui $a0, 4
/* 03590C 7F000DDC AC22A950 */  sw    $v0, %lo(ptr_logo_and_walletbond_DL)($at)
/* 035910 7F000DE0 3484B040 */  ori   $a0, (0x0004B040 & 0xFFFF) # ori $a0, $a0, 0xb040
/* 035914 7F000DE4 0C0025C8 */  jal   mempAllocBytesInBank
/* 035918 7F000DE8 24050004 */   li    $a1, 4
/* 03591C 7F000DEC 3C038003 */  lui   $v1, %hi(ptr_menu_videobuffer)
/* 035920 7F000DF0 2449003F */  addiu $t1, $v0, 0x3f
/* 035924 7F000DF4 2401FFC0 */  li    $at, -64
/* 035928 7F000DF8 2463A954 */  addiu $v1, %lo(ptr_menu_videobuffer) # addiu $v1, $v1, -0x56ac
/* 03592C 7F000DFC 01215024 */  and   $t2, $t1, $at
/* 035930 7F000E00 AC620000 */  sw    $v0, ($v1)
/* 035934 7F000E04 AC6A0000 */  sw    $t2, ($v1)
/* 035938 7F000E08 3C018003 */  lui   $at, %hi(ptr_folder_object_instance)
/* 03593C 7F000E0C AC20A95C */  sw    $zero, %lo(ptr_folder_object_instance)($at)
/* 035940 7F000E10 3C018003 */  lui   $at, %hi(set0_never_used)
/* 035944 7F000E14 AC20A960 */  sw    $zero, %lo(set0_never_used)($at)
/* 035948 7F000E18 3C018003 */  lui   $at, %hi(set0_never_used_0)
/* 03594C 7F000E1C AC20A964 */  sw    $zero, %lo(set0_never_used_0)($at)
/* 035950 7F000E20 3C018003 */  lui   $at, %hi(D_8002A968)
/* 035954 7F000E24 0FC0031C */  jal   alloc_intro_matrices
/* 035958 7F000E28 AC20A968 */   sw    $zero, %lo(D_8002A968)($at)
/* 03595C 7F000E2C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035960 7F000E30 27BD0018 */  addiu $sp, $sp, 0x18
/* 035964 7F000E34 03E00008 */  jr    $ra
/* 035968 7F000E38 00000000 */   nop   
)
#endif
