#include "ultra64.h"
#include "game/mp_weapon.h"

// data
//D:80048670
struct struct_2 type_0_stru_800490F0[] = {
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1}
};

//D:80048730
struct struct_2 type_1_stru_800490F0[] = {
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1}
};

//D:800487F0
struct struct_2 type_D_stru_800490F0[] = {
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0}
};

//D:800488B0
struct struct_2 type_2_stru_800490F0[] = {
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {0xA, 0xBD, 1.0, 1, 0x64, 1},
    {0xA, 0xBD, 1.0, 1, 0x64, 1}
};

//D:80048970
struct struct_2 type_3_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0xE, 0xC5, 1.0, 1, 0x64, 1},
    {0xE, 0xC5, 1.0, 1, 0x64, 1},
    {0x10, 0xCF, 1.0, 4, 0x1E, 1},
    {0x10, 0xCF, 1.0, 4, 0x1E, 1}
};

//D:80048A30
struct struct_2 type_4_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {7, 0xC1, 1.0, 1, 0x64, 1},
    {7, 0xC1, 1.0, 1, 0x64, 1},
    {0x11, 0xD2, 1.0, 3, 0x32, 1},
    {0x11, 0xD2, 1.0, 3, 0x32, 1}
};

//D:80048AF0
struct struct_2 type_5_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x1A, 0xC4, 1.5, 5, 5, 0},
    {0x1A, 0xC4, 1.5, 5, 5, 0}
};

//D:80048BB0
#ifdef VERSION_US
struct struct_2 type_6_stru_800490F0[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0x1D, 0xC7, 1.5, 7, 5, 0},
    {0x1D, 0xC7, 1.5, 7, 5, 0}
};
#endif
#ifdef VERSION_JP
struct struct_2 type_6_stru_800490F0[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1D, 0xC7, 1.5, 7, 5, 0},
    {0x1D, 0xC7, 1.5, 7, 5, 0}
};
#endif

//D:80048C70
struct struct_2 type_7_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x18, 0xB9, 1.0, 0xB, 6, 1},
    {0x18, 0xB9, 1.0, 0xB, 6, 1}
};

//D:80048D30
#ifdef VERSION_US
struct struct_2 type_8_stru_800490F0[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0x1B, 0xC9, 1.5, 9, 5, 0},
    {0x1B, 0xC9, 1.5, 9, 5, 0}
};
#endif
#ifdef VERSION_JP
struct struct_2 type_8_stru_800490F0[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1B, 0xC9, 1.5, 9, 5, 0},
    {0x1B, 0xC9, 1.5, 9, 5, 0}
};
#endif

//D:80048DF0 
struct struct_2 type_9_stru_800490F0[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1C, 0xC8, 1.5, 8, 5, 0},
    {0x1C, 0xC8, 1.5, 8, 5, 0}
};

//D:80048EB0
struct struct_2 type_A_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x19, 0xD3, 1.5, 6, 6, 1},
    {0x19, 0xD3, 1.5, 6, 6, 1}
};

//D:80048F70
struct struct_2 type_B_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x16, 0xBB, 1.5, 0, 0, 1},
    {0x16, 0xBB, 1.5, 0, 0, 1}
};

//D:80049030
struct struct_2 type_C_stru_800490F0[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {0x13, 0xD0, 1.5, 0xD, 0xA, 1}
};

//D:800490F0
struct struct_8 mp_weapon_set_text_table[] = {
    {0xA8, 0, 0, 0, type_0_stru_800490F0},
    {0xA8, 1, 0, 0, type_1_stru_800490F0},
    {0xA8, 0xD, 0, 0, type_D_stru_800490F0},
    {0xA8, 2, 0, 0, type_2_stru_800490F0},
    {0xA8, 3, 0, 0, type_3_stru_800490F0},
    {0xA8, 4, 0, 0, type_4_stru_800490F0},
    {0xA8, 5, 0, 0, type_5_stru_800490F0},
    {0xA8, 6, 0, 0, type_6_stru_800490F0},
    {0xA8, 7, 0, 0, type_7_stru_800490F0},
    {0xA8, 8, 0, 0, type_8_stru_800490F0},
    {0xA8, 9, 0, 0, type_9_stru_800490F0},
    {0xA8, 0xA, 0, 0, type_A_stru_800490F0},
    {0xA8, 0xB, 0, 0, type_B_stru_800490F0},
    {0xA8, 0xC, 0, 0, type_C_stru_800490F0}
};

s32 mp_weapon_set = 0xB;




#ifdef NONMATCHING
void *advance_mp_weapon_set_by_one_save_value(void) {
    // Node 0
    mp_weapon_set = (s32) ((s32) (mp_weapon_set + 1) % 0xe);
    return &mp_weapon_set;
}
#else
GLOBAL_ASM(
.text
glabel advance_mp_weapon_set_by_one_save_value
/* 0FB100 7F0C65D0 3C028005 */  lui   $v0, %hi(mp_weapon_set)
/* 0FB104 7F0C65D4 24429160 */  addiu $v0, %lo(mp_weapon_set) # addiu $v0, $v0, -0x6ea0
/* 0FB108 7F0C65D8 8C4E0000 */  lw    $t6, ($v0)
/* 0FB10C 7F0C65DC 2401000E */  li    $at, 14
/* 0FB110 7F0C65E0 25CF0001 */  addiu $t7, $t6, 1
/* 0FB114 7F0C65E4 01E1001A */  div   $zero, $t7, $at
/* 0FB118 7F0C65E8 0000C010 */  mfhi  $t8
/* 0FB11C 7F0C65EC AC580000 */  sw    $t8, ($v0)
/* 0FB120 7F0C65F0 03E00008 */  jr    $ra
/* 0FB124 7F0C65F4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 get_ptr_current_mp_weapon_set_text_code(void) {
    // Node 0
    return ((mp_weapon_set * 8) + &mp_weapon_set_text_table);
}
#else
GLOBAL_ASM(
.text
glabel get_ptr_current_mp_weapon_set_text_code
/* 0FB128 7F0C65F8 3C0E8005 */  lui   $t6, %hi(mp_weapon_set) 
/* 0FB12C 7F0C65FC 8DCE9160 */  lw    $t6, %lo(mp_weapon_set)($t6)
/* 0FB130 7F0C6600 3C188005 */  lui   $t8, %hi(mp_weapon_set_text_table) 
/* 0FB134 7F0C6604 271890F0 */  addiu $t8, %lo(mp_weapon_set_text_table) # addiu $t8, $t8, -0x6f10
/* 0FB138 7F0C6608 000E78C0 */  sll   $t7, $t6, 3
/* 0FB13C 7F0C660C 03E00008 */  jr    $ra
/* 0FB140 7F0C6610 01F81021 */   addu  $v0, $t7, $t8
)
#endif





#ifdef NONMATCHING
void get_ptr_mp_weapon_set_data(void) {
    // Node 0
    return *(&mp_weapon_set_text_table + (mp_weapon_set * 8));
}

#else
GLOBAL_ASM(
.text
glabel get_ptr_mp_weapon_set_data
/* 0FB144 7F0C6614 3C0E8005 */  lui   $t6, %hi(mp_weapon_set) 
/* 0FB148 7F0C6618 8DCE9160 */  lw    $t6, %lo(mp_weapon_set)($t6)
/* 0FB14C 7F0C661C 3C028005 */  lui   $v0, %hi(mp_weapon_set_text_table+4)
/* 0FB150 7F0C6620 000E78C0 */  sll   $t7, $t6, 3
/* 0FB154 7F0C6624 004F1021 */  addu  $v0, $v0, $t7
/* 0FB158 7F0C6628 03E00008 */  jr    $ra
/* 0FB15C 7F0C662C 8C4290F4 */   lw    $v0, %lo(mp_weapon_set_text_table+4)($v0)
)
#endif





void set_mp_weapon_set(s32 arg0) {
    mp_weapon_set = arg0;
}

s32 get_mp_weapon_set(void) {
    return mp_weapon_set;
}





