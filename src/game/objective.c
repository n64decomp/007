#include "ultra64.h"
#include "boss.h"


#ifdef NONMATCHING
void something_with_stage_objectives(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel something_with_stage_objectives
/* 0399F0 7F004EC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0399F4 7F004EC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0399F8 7F004EC8 0C001A57 */  jal   bossGetStageNum
/* 0399FC 7F004ECC 00000000 */   nop   
/* 039A00 7F004ED0 2401005A */  li    $at, 90
/* 039A04 7F004ED4 10410011 */  beq   $v0, $at, .L7F004F1C
/* 039A08 7F004ED8 240EFFFF */   li    $t6, -1
/* 039A0C 7F004EDC 3C018003 */  lui   $at, %hi(num_objective_ptrs)
/* 039A10 7F004EE0 AC2E22F0 */  sw    $t6, %lo(num_objective_ptrs)($at)
/* 039A14 7F004EE4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D58)
/* 039A18 7F004EE8 AC205D58 */  sw    $zero, %lo(dword_CODE_bss_80075D58)($at)
/* 039A1C 7F004EEC 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D5C)
/* 039A20 7F004EF0 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80075D60)
/* 039A24 7F004EF4 3C038007 */  lui   $v1, %hi(ptr_last_tag_entry_type16)
/* 039A28 7F004EF8 24635D80 */  addiu $v1, %lo(ptr_last_tag_entry_type16) # addiu $v1, $v1, 0x5d80
/* 039A2C 7F004EFC 24425D60 */  addiu $v0, %lo(dword_CODE_bss_80075D60) # addiu $v0, $v0, 0x5d60
/* 039A30 7F004F00 AC205D5C */  sw    $zero, %lo(dword_CODE_bss_80075D5C)($at)
.L7F004F04:
/* 039A34 7F004F04 24420010 */  addiu $v0, $v0, 0x10
/* 039A38 7F004F08 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039A3C 7F004F0C AC40FFF8 */  sw    $zero, -8($v0)
/* 039A40 7F004F10 AC40FFFC */  sw    $zero, -4($v0)
/* 039A44 7F004F14 1443FFFB */  bne   $v0, $v1, .L7F004F04
/* 039A48 7F004F18 AC40FFF0 */   sw    $zero, -0x10($v0)
.L7F004F1C:
/* 039A4C 7F004F1C 3C018007 */  lui   $at, %hi(objective_ptrs)
/* 039A50 7F004F20 AC205D30 */  sw    $zero, %lo(objective_ptrs)($at)
/* 039A54 7F004F24 3C018007 */  lui   $at, %hi(objective_ptrs+4)
/* 039A58 7F004F28 3C028007 */  lui   $v0, %hi(objective_ptrs+8)
/* 039A5C 7F004F2C 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80075D58)
/* 039A60 7F004F30 24635D58 */  addiu $v1, %lo(dword_CODE_bss_80075D58) # addiu $v1, $v1, 0x5d58
/* 039A64 7F004F34 24425D38 */  addiu $v0, %lo(objective_ptrs+8) # addiu $v0, $v0, 0x5d38
/* 039A68 7F004F38 AC205D34 */  sw    $zero, %lo(objective_ptrs+4)($at)
.L7F004F3C:
/* 039A6C 7F004F3C 24420010 */  addiu $v0, $v0, 0x10
/* 039A70 7F004F40 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039A74 7F004F44 AC40FFF8 */  sw    $zero, -8($v0)
/* 039A78 7F004F48 AC40FFFC */  sw    $zero, -4($v0)
/* 039A7C 7F004F4C 1443FFFB */  bne   $v0, $v1, .L7F004F3C
/* 039A80 7F004F50 AC40FFF0 */   sw    $zero, -0x10($v0)
/* 039A84 7F004F54 3C018007 */  lui   $at, %hi(ptr_last_tag_entry_type16)
/* 039A88 7F004F58 AC205D80 */  sw    $zero, %lo(ptr_last_tag_entry_type16)($at)
/* 039A8C 7F004F5C 3C018007 */  lui   $at, %hi(ptr_last_briefing_setup_entry_type23)
/* 039A90 7F004F60 AC205D84 */  sw    $zero, %lo(ptr_last_briefing_setup_entry_type23)($at)
/* 039A94 7F004F64 3C018007 */  lui   $at, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 039A98 7F004F68 AC205D88 */  sw    $zero, %lo(ptr_last_enter_room_subobject_entry_type20)($at)
/* 039A9C 7F004F6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 039AA0 7F004F70 3C018007 */  lui   $at, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 039AA4 7F004F74 AC205D8C */  sw    $zero, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($at)
/* 039AA8 7F004F78 3C018007 */  lui   $at, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 039AAC 7F004F7C AC205D90 */  sw    $zero, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($at)
/* 039AB0 7F004F80 03E00008 */  jr    $ra
/* 039AB4 7F004F84 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel something_with_stage_objectives
/* 039A40 7F004ED0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 039A44 7F004ED4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 039A48 7F004ED8 0C001A57 */  jal   bossGetStageNum
/* 039A4C 7F004EDC 00000000 */   nop   
/* 039A50 7F004EE0 2401005A */  li    $at, 90
/* 039A54 7F004EE4 10410011 */  beq   $v0, $at, .L7F004F2C
/* 039A58 7F004EE8 240EFFFF */   li    $t6, -1
/* 039A5C 7F004EEC 3C018003 */  lui   $at, %hi(num_objective_ptrs) # $at, 0x8003
/* 039A60 7F004EF0 AC2E2330 */  sw    $t6, %lo(num_objective_ptrs)($at)
/* 039A64 7F004EF4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D58) # $at, 0x8007
/* 039A68 7F004EF8 AC205D98 */  sw    $zero, %lo(dword_CODE_bss_80075D58)($at)
/* 039A6C 7F004EFC 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D5C) # $at, 0x8007
/* 039A70 7F004F00 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80075D60) # $v0, 0x8007
/* 039A74 7F004F04 3C038007 */  lui   $v1, %hi(ptr_last_tag_entry_type16) # $v1, 0x8007
/* 039A78 7F004F08 24635DC0 */  addiu $v1, %lo(ptr_last_tag_entry_type16) # addiu $v1, $v1, 0x5dc0
/* 039A7C 7F004F0C 24425DA0 */  addiu $v0, %lo(dword_CODE_bss_80075D60) # addiu $v0, $v0, 0x5da0
/* 039A80 7F004F10 AC205D9C */  sw    $zero, %lo(dword_CODE_bss_80075D5C)($at)
.L7F004F14:
/* 039A84 7F004F14 24420010 */  addiu $v0, $v0, 0x10
/* 039A88 7F004F18 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039A8C 7F004F1C AC40FFF8 */  sw    $zero, -8($v0)
/* 039A90 7F004F20 AC40FFFC */  sw    $zero, -4($v0)
/* 039A94 7F004F24 1443FFFB */  bne   $v0, $v1, .L7F004F14
/* 039A98 7F004F28 AC40FFF0 */   sw    $zero, -0x10($v0)
.L7F004F2C:
/* 039A9C 7F004F2C 3C018003 */  lui   $at, %hi(num_objective_ptrs+4) # $at, 0x8003
/* 039AA0 7F004F30 AC202334 */  sw    $zero, %lo(num_objective_ptrs+4)($at)
/* 039AA4 7F004F34 3C018007 */  lui   $at, %hi(objective_ptrs) # $at, 0x8007
/* 039AA8 7F004F38 AC205D70 */  sw    $zero, %lo(objective_ptrs)($at)
/* 039AAC 7F004F3C 3C018007 */  lui   $at, %hi(objective_ptrs+4) # $at, 0x8007
/* 039AB0 7F004F40 3C028007 */  lui   $v0, %hi(objective_ptrs+8) # $v0, 0x8007
/* 039AB4 7F004F44 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80075D58) # $v1, 0x8007
/* 039AB8 7F004F48 24635D98 */  addiu $v1, %lo(dword_CODE_bss_80075D58) # addiu $v1, $v1, 0x5d98
/* 039ABC 7F004F4C 24425D78 */  addiu $v0, %lo(objective_ptrs+8) # addiu $v0, $v0, 0x5d78
/* 039AC0 7F004F50 AC205D74 */  sw    $zero, %lo(objective_ptrs+4)($at)
.L7F004F54:
/* 039AC4 7F004F54 24420010 */  addiu $v0, $v0, 0x10
/* 039AC8 7F004F58 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039ACC 7F004F5C AC40FFF8 */  sw    $zero, -8($v0)
/* 039AD0 7F004F60 AC40FFFC */  sw    $zero, -4($v0)
/* 039AD4 7F004F64 1443FFFB */  bne   $v0, $v1, .L7F004F54
/* 039AD8 7F004F68 AC40FFF0 */   sw    $zero, -0x10($v0)
/* 039ADC 7F004F6C 3C018007 */  lui   $at, %hi(ptr_last_tag_entry_type16) # $at, 0x8007
/* 039AE0 7F004F70 AC205DC0 */  sw    $zero, %lo(ptr_last_tag_entry_type16)($at)
/* 039AE4 7F004F74 3C018007 */  lui   $at, %hi(ptr_last_briefing_setup_entry_type23) # $at, 0x8007
/* 039AE8 7F004F78 AC205DC4 */  sw    $zero, %lo(ptr_last_briefing_setup_entry_type23)($at)
/* 039AEC 7F004F7C 3C018007 */  lui   $at, %hi(ptr_last_enter_room_subobject_entry_type20) # $at, 0x8007
/* 039AF0 7F004F80 AC205DC8 */  sw    $zero, %lo(ptr_last_enter_room_subobject_entry_type20)($at)
/* 039AF4 7F004F84 8FBF0014 */  lw    $ra, 0x14($sp)
/* 039AF8 7F004F88 3C018007 */  lui   $at, %hi(ptr_last_deposit_in_room_subobject_entry_type21) # $at, 0x8007
/* 039AFC 7F004F8C AC205DCC */  sw    $zero, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($at)
/* 039B00 7F004F90 3C018007 */  lui   $at, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E) # $at, 0x8007
/* 039B04 7F004F94 AC205DD0 */  sw    $zero, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($at)
/* 039B08 7F004F98 03E00008 */  jr    $ra
/* 039B0C 7F004F9C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel something_with_stage_objectives
/* 0399F0 7F004EC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0399F4 7F004EC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0399F8 7F004EC8 0C001A57 */  jal   bossGetStageNum
/* 0399FC 7F004ECC 00000000 */   nop   
/* 039A00 7F004ED0 2401005A */  li    $at, 90
/* 039A04 7F004ED4 10410011 */  beq   $v0, $at, .L7F004F1C
/* 039A08 7F004ED8 240EFFFF */   li    $t6, -1
/* 039A0C 7F004EDC 3C018003 */  lui   $at, %hi(num_objective_ptrs)
/* 039A10 7F004EE0 AC2E22F0 */  sw    $t6, %lo(num_objective_ptrs)($at)
/* 039A14 7F004EE4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D58)
/* 039A18 7F004EE8 AC205D58 */  sw    $zero, %lo(dword_CODE_bss_80075D58)($at)
/* 039A1C 7F004EEC 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D5C)
/* 039A20 7F004EF0 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80075D60)
/* 039A24 7F004EF4 3C038007 */  lui   $v1, %hi(ptr_last_tag_entry_type16)
/* 039A28 7F004EF8 24635D80 */  addiu $v1, %lo(ptr_last_tag_entry_type16) # addiu $v1, $v1, 0x5d80
/* 039A2C 7F004EFC 24425D60 */  addiu $v0, %lo(dword_CODE_bss_80075D60) # addiu $v0, $v0, 0x5d60
/* 039A30 7F004F00 AC205D5C */  sw    $zero, %lo(dword_CODE_bss_80075D5C)($at)
.L7F004F04:
/* 039A34 7F004F04 24420010 */  addiu $v0, $v0, 0x10
/* 039A38 7F004F08 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039A3C 7F004F0C AC40FFF8 */  sw    $zero, -8($v0)
/* 039A40 7F004F10 AC40FFFC */  sw    $zero, -4($v0)
/* 039A44 7F004F14 1443FFFB */  bne   $v0, $v1, .L7F004F04
/* 039A48 7F004F18 AC40FFF0 */   sw    $zero, -0x10($v0)
.L7F004F1C:
/* 039A4C 7F004F1C 3C018007 */  lui   $at, %hi(objective_ptrs)
/* 039A50 7F004F20 AC205D30 */  sw    $zero, %lo(objective_ptrs)($at)
/* 039A54 7F004F24 3C018007 */  lui   $at, %hi(objective_ptrs+4)
/* 039A58 7F004F28 3C028007 */  lui   $v0, %hi(objective_ptrs+8)
/* 039A5C 7F004F2C 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80075D58)
/* 039A60 7F004F30 24635D58 */  addiu $v1, %lo(dword_CODE_bss_80075D58) # addiu $v1, $v1, 0x5d58
/* 039A64 7F004F34 24425D38 */  addiu $v0, %lo(objective_ptrs+8) # addiu $v0, $v0, 0x5d38
/* 039A68 7F004F38 AC205D34 */  sw    $zero, %lo(objective_ptrs+4)($at)
.L7F004F3C:
/* 039A6C 7F004F3C 24420010 */  addiu $v0, $v0, 0x10
/* 039A70 7F004F40 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 039A74 7F004F44 AC40FFF8 */  sw    $zero, -8($v0)
/* 039A78 7F004F48 AC40FFFC */  sw    $zero, -4($v0)
/* 039A7C 7F004F4C 1443FFFB */  bne   $v0, $v1, .L7F004F3C
/* 039A80 7F004F50 AC40FFF0 */   sw    $zero, -0x10($v0)
/* 039A84 7F004F54 3C018007 */  lui   $at, %hi(ptr_last_tag_entry_type16)
/* 039A88 7F004F58 AC205D80 */  sw    $zero, %lo(ptr_last_tag_entry_type16)($at)
/* 039A8C 7F004F5C 3C018007 */  lui   $at, %hi(ptr_last_briefing_setup_entry_type23)
/* 039A90 7F004F60 AC205D84 */  sw    $zero, %lo(ptr_last_briefing_setup_entry_type23)($at)
/* 039A94 7F004F64 3C018007 */  lui   $at, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 039A98 7F004F68 AC205D88 */  sw    $zero, %lo(ptr_last_enter_room_subobject_entry_type20)($at)
/* 039A9C 7F004F6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 039AA0 7F004F70 3C018007 */  lui   $at, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 039AA4 7F004F74 AC205D8C */  sw    $zero, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($at)
/* 039AA8 7F004F78 3C018007 */  lui   $at, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 039AAC 7F004F7C AC205D90 */  sw    $zero, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($at)
/* 039AB0 7F004F80 03E00008 */  jr    $ra
/* 039AB4 7F004F84 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

#endif


#ifdef NONMATCHING
void *set_parent_cur_tag_entry(void *arg0) {
    // Node 0
    arg0->unk8 = (void *) ptr_last_tag_entry_type16;
    ptr_last_tag_entry_type16 = arg0;
    return;
    // (possible return value: &ptr_last_tag_entry_type16)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_tag_entry
/* 039AB8 7F004F88 3C028007 */  lui   $v0, %hi(ptr_last_tag_entry_type16)
/* 039ABC 7F004F8C 24425D80 */  addiu $v0, %lo(ptr_last_tag_entry_type16) # addiu $v0, $v0, 0x5d80
/* 039AC0 7F004F90 8C4E0000 */  lw    $t6, ($v0)
/* 039AC4 7F004F94 AC8E0008 */  sw    $t6, 8($a0)
/* 039AC8 7F004F98 03E00008 */  jr    $ra
/* 039ACC 7F004F9C AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
void *setup_briefing_text_entry_parent(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_briefing_setup_entry_type23;
    ptr_last_briefing_setup_entry_type23 = arg0;
    return;
    // (possible return value: &ptr_last_briefing_setup_entry_type23)
}

#else
GLOBAL_ASM(
.text
glabel setup_briefing_text_entry_parent
/* 039AD0 7F004FA0 3C028007 */  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
/* 039AD4 7F004FA4 24425D84 */  addiu $v0, %lo(ptr_last_briefing_setup_entry_type23) # addiu $v0, $v0, 0x5d84
/* 039AD8 7F004FA8 8C4E0000 */  lw    $t6, ($v0)
/* 039ADC 7F004FAC AC8E000C */  sw    $t6, 0xc($a0)
/* 039AE0 7F004FB0 03E00008 */  jr    $ra
/* 039AE4 7F004FB4 AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
s32 add_ptr_to_objective(void *arg0) {
    // Node 0
    (0x80070000 + (arg0->unk4 * 4))->unk5D30 = arg0;
    if (num_objective_ptrs < arg0->unk4)
    {
        // Node 1
        num_objective_ptrs = (s32) arg0->unk4;
        return;
        // (possible return value: arg0->unk4)
    }
    // (possible return value: arg0->unk4)
}

#else
GLOBAL_ASM(
.text
glabel add_ptr_to_objective
/* 039AE8 7F004FB8 8C8E0004 */  lw    $t6, 4($a0)
/* 039AEC 7F004FBC 3C018007 */  lui   $at, %hi(objective_ptrs)
/* 039AF0 7F004FC0 3C038003 */  lui   $v1, %hi(num_objective_ptrs)
/* 039AF4 7F004FC4 000E7880 */  sll   $t7, $t6, 2
/* 039AF8 7F004FC8 002F0821 */  addu  $at, $at, $t7
/* 039AFC 7F004FCC AC245D30 */  sw    $a0, %lo(objective_ptrs)($at)
/* 039B00 7F004FD0 246322F0 */  addiu $v1, %lo(num_objective_ptrs) # addiu $v1, $v1, 0x22f0
/* 039B04 7F004FD4 8C780000 */  lw    $t8, ($v1)
/* 039B08 7F004FD8 8C820004 */  lw    $v0, 4($a0)
/* 039B0C 7F004FDC 0302082A */  slt   $at, $t8, $v0
/* 039B10 7F004FE0 10200002 */  beqz  $at, .L7F004FEC
/* 039B14 7F004FE4 00000000 */   nop   
/* 039B18 7F004FE8 AC620000 */  sw    $v0, ($v1)
.L7F004FEC:
/* 039B1C 7F004FEC 03E00008 */  jr    $ra
/* 039B20 7F004FF0 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void *set_parent_cur_obj_enter_room(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_enter_room_subobject_entry_type20;
    ptr_last_enter_room_subobject_entry_type20 = arg0;
    return;
    // (possible return value: &ptr_last_enter_room_subobject_entry_type20)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_enter_room
/* 039B24 7F004FF4 3C028007 */  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 039B28 7F004FF8 24425D88 */  addiu $v0, %lo(ptr_last_enter_room_subobject_entry_type20) # addiu $v0, $v0, 0x5d88
/* 039B2C 7F004FFC 8C4E0000 */  lw    $t6, ($v0)
/* 039B30 7F005000 AC8E000C */  sw    $t6, 0xc($a0)
/* 039B34 7F005004 03E00008 */  jr    $ra
/* 039B38 7F005008 AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
void *set_parent_cur_obj_deposited_in_room(void *arg0) {
    // Node 0
    arg0->unk10 = (void *) ptr_last_deposit_in_room_subobject_entry_type21;
    ptr_last_deposit_in_room_subobject_entry_type21 = arg0;
    return;
    // (possible return value: &ptr_last_deposit_in_room_subobject_entry_type21)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_deposited_in_room
/* 039B3C 7F00500C 3C028007 */  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 039B40 7F005010 24425D8C */  addiu $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21) # addiu $v0, $v0, 0x5d8c
/* 039B44 7F005014 8C4E0000 */  lw    $t6, ($v0)
/* 039B48 7F005018 AC8E0010 */  sw    $t6, 0x10($a0)
/* 039B4C 7F00501C 03E00008 */  jr    $ra
/* 039B50 7F005020 AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
void *set_parent_cur_obj_photograph(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_photo_obj_in_room_subobject_entry_type1E;
    ptr_last_photo_obj_in_room_subobject_entry_type1E = arg0;
    return;
    // (possible return value: &ptr_last_photo_obj_in_room_subobject_entry_type1E)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_photograph
/* 039B54 7F005024 3C028007 */  lui   $v0, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 039B58 7F005028 24425D90 */  addiu $v0, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E) # addiu $v0, $v0, 0x5d90
/* 039B5C 7F00502C 8C4E0000 */  lw    $t6, ($v0)
/* 039B60 7F005030 AC8E000C */  sw    $t6, 0xc($a0)
/* 039B64 7F005034 03E00008 */  jr    $ra
/* 039B68 7F005038 AC440000 */   sw    $a0, ($v0)
)
#endif


