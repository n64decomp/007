#include "ultra64.h"
#include "game/initobjects.h"
#include "game/actionblock.h"
//this file may very well be a few different sub files

struct object_animation_controller ptr_monitorimageobjectanimationcontroller = {&monitor_animation_microcode, 0, 0xFFFF, 0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 1.0, 0.0};
struct object_animation_controller unknown_object_animation_controller = {&dword_D_80031F00, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};
struct object_animation_controller taser_object_animation_controller = {&dword_D_80031F44, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};
f32 unused_8002a3bc = 0.0f;
f32 scale_1_0_item_related = 1.0f;


#ifdef NONMATCHING
void init_sound_effects_registers(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_sound_effects_registers
/* 035FE0 7F0014B0 3C038007 */  lui   $v1, %hi(sfx_related) # $v1, 0x8007
/* 035FE4 7F0014B4 3C028007 */  lui   $v0, %hi(ptr_list_object_lookup_indices) # $v0, 0x8007
/* 035FE8 7F0014B8 24429C30 */  addiu $v0, %lo(ptr_list_object_lookup_indices) # addiu $v0, $v0, -0x63d0
/* 035FEC 7F0014BC 24639B70 */  addiu $v1, %lo(sfx_related) # addiu $v1, $v1, -0x6490
.L7F0014C0:
/* 035FF0 7F0014C0 24630060 */  addiu $v1, $v1, 0x60
/* 035FF4 7F0014C4 AC60FFB8 */  sw    $zero, -0x48($v1)
/* 035FF8 7F0014C8 AC60FFD0 */  sw    $zero, -0x30($v1)
/* 035FFC 7F0014CC AC60FFE8 */  sw    $zero, -0x18($v1)
/* 036000 7F0014D0 1462FFFB */  bne   $v1, $v0, .L7F0014C0
/* 036004 7F0014D4 AC60FFA0 */   sw    $zero, -0x60($v1)
/* 036008 7F0014D8 03E00008 */  jr    $ra
/* 03600C 7F0014DC 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void init_load_objpos_table(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_load_objpos_table
/* 036010 7F0014E0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 036014 7F0014E4 44812000 */  mtc1  $at, $f4
/* 036018 7F0014E8 3C018003 */  lui   $at, %hi(difficulty) # $at, 0x8003
/* 03601C 7F0014EC 3C028003 */  lui   $v0, %hi(ptr_obj_pos_list_first_entry) # $v0, 0x8003
/* 036020 7F0014F0 E4240AAC */  swc1  $f4, %lo(difficulty)($at)
/* 036024 7F0014F4 24420AA4 */  addiu $v0, %lo(ptr_obj_pos_list_first_entry) # addiu $v0, $v0, 0xaa4
/* 036028 7F0014F8 AC400000 */  sw    $zero, ($v0)
/* 03602C 7F0014FC 3C018003 */  lui   $at, %hi(ptr_obj_pos_list_current_entry) # $at, 0x8003
/* 036030 7F001500 AC200AA0 */  sw    $zero, %lo(ptr_obj_pos_list_current_entry)($at)
/* 036034 7F001504 3C018007 */  lui   $at, %hi(dword_CODE_bss_80071DF4) # $at, 0x8007
/* 036038 7F001508 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80071620) # $v1, 0x8007
/* 03603C 7F00150C AC201DF4 */  sw    $zero, %lo(dword_CODE_bss_80071DF4)($at)
/* 036040 7F001510 24631620 */  addiu $v1, %lo(dword_CODE_bss_80071620) # addiu $v1, $v1, 0x1620
/* 036044 7F001514 AC600000 */  sw    $zero, ($v1)
/* 036048 7F001518 3C018007 */  lui   $at, %hi(dword_CODE_bss_80071DF0) # $at, 0x8007
/* 03604C 7F00151C AC231DF0 */  sw    $v1, %lo(dword_CODE_bss_80071DF0)($at)
/* 036050 7F001520 3C0F8007 */  lui   $t7, %hi(pos_data_entry) # $t7, 0x8007
/* 036054 7F001524 25EF9C38 */  addiu $t7, %lo(pos_data_entry) # addiu $t7, $t7, -0x63c8
/* 036058 7F001528 3C018003 */  lui   $at, %hi(ptr_obj_pos_list_final_entry) # $at, 0x8003
/* 03605C 7F00152C AC2F0AA8 */  sw    $t7, %lo(ptr_obj_pos_list_final_entry)($at)
/* 036060 7F001530 3C188007 */  lui   $t8, %hi(dword_CODE_bss_80069C6C) # $t8, 0x8007
/* 036064 7F001534 27189C6C */  addiu $t8, %lo(dword_CODE_bss_80069C6C) # addiu $t8, $t8, -0x6394
/* 036068 7F001538 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069C5C) # $at, 0x8007
/* 03606C 7F00153C AC389C5C */  sw    $t8, %lo(dword_CODE_bss_80069C5C)($at)
/* 036070 7F001540 3C198007 */  lui   $t9, %hi(dword_CODE_bss_80069CA0) # $t9, 0x8007
/* 036074 7F001544 27399CA0 */  addiu $t9, %lo(dword_CODE_bss_80069CA0) # addiu $t9, $t9, -0x6360
/* 036078 7F001548 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069C90) # $at, 0x8007
/* 03607C 7F00154C AC399C90 */  sw    $t9, %lo(dword_CODE_bss_80069C90)($at)
/* 036080 7F001550 3C088007 */  lui   $t0, %hi(dword_CODE_bss_80069CD4)
/* 036084 7F001554 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 036088 7F001558 25029CD4 */  addiu $v0, $t0, %lo(dword_CODE_bss_80069CD4)
/* 03608C 7F00155C 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069CC4) # $at, 0x8007
/* 036090 7F001560 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80069DA4) # $v1, 0x8007
/* 036094 7F001564 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069D08) # $a0, 0x8007
/* 036098 7F001568 3C058007 */  lui   $a1, %hi(dword_CODE_bss_80069D3C) # $a1, 0x8007
/* 03609C 7F00156C 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069D70) # $a2, 0x8007
/* 0360A0 7F001570 3C078007 */  lui   $a3, %hi(dword_CODE_bss_800716B4) # $a3, 0x8007
/* 0360A4 7F001574 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0360A8 7F001578 24E716B4 */  addiu $a3, %lo(dword_CODE_bss_800716B4) # addiu $a3, $a3, 0x16b4
/* 0360AC 7F00157C 24C69D70 */  addiu $a2, %lo(dword_CODE_bss_80069D70) # addiu $a2, $a2, -0x6290
/* 0360B0 7F001580 24A59D3C */  addiu $a1, %lo(dword_CODE_bss_80069D3C) # addiu $a1, $a1, -0x62c4
/* 0360B4 7F001584 24849D08 */  addiu $a0, %lo(dword_CODE_bss_80069D08) # addiu $a0, $a0, -0x62f8
/* 0360B8 7F001588 24639DA4 */  addiu $v1, %lo(dword_CODE_bss_80069DA4) # addiu $v1, $v1, -0x625c
/* 0360BC 7F00158C AC229CC4 */  sw    $v0, %lo(dword_CODE_bss_80069CC4)($at)
.L7F001590:
/* 0360C0 7F001590 AC4300C0 */  sw    $v1, 0xc0($v0)
/* 0360C4 7F001594 246300D0 */  addiu $v1, $v1, 0xd0
/* 0360C8 7F001598 AC450058 */  sw    $a1, 0x58($v0)
/* 0360CC 7F00159C AC46008C */  sw    $a2, 0x8c($v0)
/* 0360D0 7F0015A0 AC440024 */  sw    $a0, 0x24($v0)
/* 0360D4 7F0015A4 248400D0 */  addiu $a0, $a0, 0xd0
/* 0360D8 7F0015A8 24C600D0 */  addiu $a2, $a2, 0xd0
/* 0360DC 7F0015AC 24A500D0 */  addiu $a1, $a1, 0xd0
/* 0360E0 7F0015B0 1467FFF7 */  bne   $v1, $a3, .L7F001590
/* 0360E4 7F0015B4 244200D0 */   addiu $v0, $v0, 0xd0
/* 0360E8 7F0015B8 0FC00574 */  jal   alloc_lookup_buffers
/* 0360EC 7F0015BC 00000000 */   nop   
/* 0360F0 7F0015C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0360F4 7F0015C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0360F8 7F0015C8 03E00008 */  jr    $ra
/* 0360FC 7F0015CC 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void alloc_lookup_buffers(void) {

}
#else
GLOBAL_ASM(
.text
glabel alloc_lookup_buffers
/* 036100 7F0015D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 036104 7F0015D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 036108 7F0015D8 24040400 */  li    $a0, 1024
/* 03610C 7F0015DC 0C0025C8 */  jal   allocate_bytes_in_bank
/* 036110 7F0015E0 24050004 */   li    $a1, 4
/* 036114 7F0015E4 3C068004 */  lui   $a2, %hi(MaxNumRooms) # $a2, 0x8004
/* 036118 7F0015E8 3C018007 */  lui   $at, %hi(ptr_list_object_lookup_indices) # $at, 0x8007
/* 03611C 7F0015EC AC229C30 */  sw    $v0, %lo(ptr_list_object_lookup_indices)($at)
/* 036120 7F0015F0 24C642F4 */  addiu $a2, %lo(MaxNumRooms) # addiu $a2, $a2, 0x42f4
/* 036124 7F0015F4 8CC40000 */  lw    $a0, ($a2)
/* 036128 7F0015F8 24050004 */  li    $a1, 4
/* 03612C 7F0015FC 00047080 */  sll   $t6, $a0, 2
/* 036130 7F001600 25C4000F */  addiu $a0, $t6, 0xf
/* 036134 7F001604 348F000F */  ori   $t7, $a0, 0xf
/* 036138 7F001608 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03613C 7F00160C 39E4000F */   xori  $a0, $t7, 0xf
/* 036140 7F001610 3C078007 */  lui   $a3, %hi(ptr_room_lookup_buffer_maybe) # $a3, 0x8007
/* 036144 7F001614 24E71618 */  addiu $a3, %lo(ptr_room_lookup_buffer_maybe) # addiu $a3, $a3, 0x1618
/* 036148 7F001618 ACE20000 */  sw    $v0, ($a3)
/* 03614C 7F00161C 24042000 */  li    $a0, 8192
/* 036150 7F001620 0C0025C8 */  jal   allocate_bytes_in_bank
/* 036154 7F001624 24050004 */   li    $a1, 4
/* 036158 7F001628 3C048007 */  lui   $a0, %hi(dword_CODE_bss_8007161C) # $a0, 0x8007
/* 03615C 7F00162C 2484161C */  addiu $a0, %lo(dword_CODE_bss_8007161C) # addiu $a0, $a0, 0x161c
/* 036160 7F001630 AC820000 */  sw    $v0, ($a0)
/* 036164 7F001634 3C198007 */  lui   $t9, %hi(ptr_list_object_lookup_indices) # $t9, 0x8007
/* 036168 7F001638 8F399C30 */  lw    $t9, %lo(ptr_list_object_lookup_indices)($t9)
/* 03616C 7F00163C 2405FFFF */  li    $a1, -1
/* 036170 7F001640 3C068004 */  lui   $a2, %hi(MaxNumRooms) # $a2, 0x8004
/* 036174 7F001644 24C642F4 */  addiu $a2, %lo(MaxNumRooms) # addiu $a2, $a2, 0x42f4
/* 036178 7F001648 A7250000 */  sh    $a1, ($t9)
/* 03617C 7F00164C 8CCB0000 */  lw    $t3, ($a2)
/* 036180 7F001650 3C078007 */  lui   $a3, %hi(ptr_room_lookup_buffer_maybe) # $a3, 0x8007
/* 036184 7F001654 24E71618 */  addiu $a3, %lo(ptr_room_lookup_buffer_maybe) # addiu $a3, $a3, 0x1618
/* 036188 7F001658 1960000C */  blez  $t3, .L7F00168C
/* 03618C 7F00165C 00001825 */   move  $v1, $zero
/* 036190 7F001660 00001025 */  move  $v0, $zero
/* 036194 7F001664 8CEC0000 */  lw    $t4, ($a3)
.L7F001668:
/* 036198 7F001668 24630001 */  addiu $v1, $v1, 1
/* 03619C 7F00166C 01826821 */  addu  $t5, $t4, $v0
/* 0361A0 7F001670 A5A50000 */  sh    $a1, ($t5)
/* 0361A4 7F001674 8CCE0000 */  lw    $t6, ($a2)
/* 0361A8 7F001678 24420002 */  addiu $v0, $v0, 2
/* 0361AC 7F00167C 006E082A */  slt   $at, $v1, $t6
/* 0361B0 7F001680 5420FFF9 */  bnezl $at, .L7F001668
/* 0361B4 7F001684 8CEC0000 */   lw    $t4, ($a3)
/* 0361B8 7F001688 00001825 */  move  $v1, $zero
.L7F00168C:
/* 0361BC 7F00168C 00003825 */  move  $a3, $zero
/* 0361C0 7F001690 240A0100 */  li    $t2, 256
/* 0361C4 7F001694 2409FFFE */  li    $t1, -2
/* 0361C8 7F001698 24060020 */  li    $a2, 32
.L7F00169C:
/* 0361CC 7F00169C 8C8F0000 */  lw    $t7, ($a0)
/* 0361D0 7F0016A0 00035940 */  sll   $t3, $v1, 5
/* 0361D4 7F0016A4 00037140 */  sll   $t6, $v1, 5
/* 0361D8 7F0016A8 01E7C021 */  addu  $t8, $t7, $a3
/* 0361DC 7F0016AC A7090000 */  sh    $t1, ($t8)
/* 0361E0 7F0016B0 8C990000 */  lw    $t9, ($a0)
/* 0361E4 7F0016B4 24020008 */  li    $v0, 8
/* 0361E8 7F0016B8 032B6021 */  addu  $t4, $t9, $t3
/* 0361EC 7F0016BC A5850002 */  sh    $a1, 2($t4)
/* 0361F0 7F0016C0 8C8D0000 */  lw    $t5, ($a0)
/* 0361F4 7F0016C4 0003C940 */  sll   $t9, $v1, 5
/* 0361F8 7F0016C8 01AE7821 */  addu  $t7, $t5, $t6
/* 0361FC 7F0016CC A5E50004 */  sh    $a1, 4($t7)
/* 036200 7F0016D0 8C980000 */  lw    $t8, ($a0)
/* 036204 7F0016D4 03195821 */  addu  $t3, $t8, $t9
/* 036208 7F0016D8 A5650006 */  sh    $a1, 6($t3)
.L7F0016DC:
/* 03620C 7F0016DC 8C8C0000 */  lw    $t4, ($a0)
/* 036210 7F0016E0 00036940 */  sll   $t5, $v1, 5
/* 036214 7F0016E4 0003C940 */  sll   $t9, $v1, 5
/* 036218 7F0016E8 018D7021 */  addu  $t6, $t4, $t5
/* 03621C 7F0016EC 01C27821 */  addu  $t7, $t6, $v0
/* 036220 7F0016F0 A5E50000 */  sh    $a1, ($t7)
/* 036224 7F0016F4 8C980000 */  lw    $t8, ($a0)
/* 036228 7F0016F8 00037140 */  sll   $t6, $v1, 5
/* 03622C 7F0016FC 03195821 */  addu  $t3, $t8, $t9
/* 036230 7F001700 01626021 */  addu  $t4, $t3, $v0
/* 036234 7F001704 A5850002 */  sh    $a1, 2($t4)
/* 036238 7F001708 8C8D0000 */  lw    $t5, ($a0)
/* 03623C 7F00170C 00035940 */  sll   $t3, $v1, 5
/* 036240 7F001710 01AE7821 */  addu  $t7, $t5, $t6
/* 036244 7F001714 01E2C021 */  addu  $t8, $t7, $v0
/* 036248 7F001718 A7050004 */  sh    $a1, 4($t8)
/* 03624C 7F00171C 8C990000 */  lw    $t9, ($a0)
/* 036250 7F001720 032B6021 */  addu  $t4, $t9, $t3
/* 036254 7F001724 01826821 */  addu  $t5, $t4, $v0
/* 036258 7F001728 24420008 */  addiu $v0, $v0, 8
/* 03625C 7F00172C 1446FFEB */  bne   $v0, $a2, .L7F0016DC
/* 036260 7F001730 A5A50006 */   sh    $a1, 6($t5)
/* 036264 7F001734 24630001 */  addiu $v1, $v1, 1
/* 036268 7F001738 146AFFD8 */  bne   $v1, $t2, .L7F00169C
/* 03626C 7F00173C 24E70020 */   addiu $a3, $a3, 0x20
/* 036270 7F001740 8FBF0014 */  lw    $ra, 0x14($sp)
/* 036274 7F001744 27BD0018 */  addiu $sp, $sp, 0x18
/* 036278 7F001748 03E00008 */  jr    $ra
/* 03627C 7F00174C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void reinit_between_menus(void) {

}
#else
GLOBAL_ASM(
.text
glabel reinit_between_menus
/* 036280 7F001750 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 036284 7F001754 AFBF0014 */  sw    $ra, 0x14($sp)
/* 036288 7F001758 0FC00656 */  jal   write_monitor_ani_control_blocks
/* 03628C 7F00175C 00000000 */   nop   
/* 036290 7F001760 0FC006C2 */  jal   initialize_80071E00_to_80071E78
/* 036294 7F001764 00000000 */   nop   
/* 036298 7F001768 3C018003 */  lui   $at, %hi(alarm_timer) # $at, 0x8003
/* 03629C 7F00176C AC200AC0 */  sw    $zero, %lo(alarm_timer)($at)
/* 0362A0 7F001770 44800000 */  mtc1  $zero, $f0
/* 0362A4 7F001774 3C018003 */  lui   $at, %hi(ptr_alarm_sfx) # $at, 0x8003
/* 0362A8 7F001778 AC200AC4 */  sw    $zero, %lo(ptr_alarm_sfx)($at)
/* 0362AC 7F00177C 3C018003 */  lui   $at, %hi(toxic_gas_sound_timer) # $at, 0x8003
/* 0362B0 7F001780 E4200AC8 */  swc1  $f0, %lo(toxic_gas_sound_timer)($at)
/* 0362B4 7F001784 3C018003 */  lui   $at, %hi(activate_gas_sound_timer) # $at, 0x8003
/* 0362B8 7F001788 3C048003 */  lui   $a0, %hi(D_80030AD0) # $a0, 0x8003
/* 0362BC 7F00178C AC200ACC */  sw    $zero, %lo(activate_gas_sound_timer)($at)
/* 0362C0 7F001790 24840AD0 */  addiu $a0, %lo(D_80030AD0) # addiu $a0, $a0, 0xad0
/* 0362C4 7F001794 3C018003 */  lui   $at, %hi(D_80030ADC) # $at, 0x8003
/* 0362C8 7F001798 E4800000 */  swc1  $f0, ($a0)
/* 0362CC 7F00179C E4800004 */  swc1  $f0, 4($a0)
/* 0362D0 7F0017A0 E4800008 */  swc1  $f0, 8($a0)
/* 0362D4 7F0017A4 AC200ADC */  sw    $zero, %lo(D_80030ADC)($at)
/* 0362D8 7F0017A8 3C018003 */  lui   $at, %hi(D_80030AE0) # $at, 0x8003
/* 0362DC 7F0017AC E4200AE0 */  swc1  $f0, %lo(D_80030AE0)($at)
/* 0362E0 7F0017B0 3C018003 */  lui   $at, %hi(D_80030AE4) # $at, 0x8003
/* 0362E4 7F0017B4 AC200AE4 */  sw    $zero, %lo(D_80030AE4)($at)
/* 0362E8 7F0017B8 24050001 */  li    $a1, 1
/* 0362EC 7F0017BC 3C018003 */  lui   $at, %hi(clock_drawn_flag) # $at, 0x8003
/* 0362F0 7F0017C0 AC250AE8 */  sw    $a1, %lo(clock_drawn_flag)($at)
/* 0362F4 7F0017C4 3C018003 */  lui   $at, %hi(clock_enable) # $at, 0x8003
/* 0362F8 7F0017C8 AC200AEC */  sw    $zero, %lo(clock_enable)($at)
/* 0362FC 7F0017CC 3C018003 */  lui   $at, %hi(clock_time) # $at, 0x8003
/* 036300 7F0017D0 E4200AF0 */  swc1  $f0, %lo(clock_time)($at)
/* 036304 7F0017D4 3C018003 */  lui   $at, %hi(D_80030AF4) # $at, 0x8003
/* 036308 7F0017D8 3C028007 */  lui   $v0, %hi(ProjectileData_start_address) # $v0, 0x8007
/* 03630C 7F0017DC 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80072E70) # $v1, 0x8007
/* 036310 7F0017E0 AC200AF4 */  sw    $zero, %lo(D_80030AF4)($at)
/* 036314 7F0017E4 24632E70 */  addiu $v1, %lo(dword_CODE_bss_80072E70) # addiu $v1, $v1, 0x2e70
/* 036318 7F0017E8 24421E80 */  addiu $v0, %lo(ProjectileData_start_address) # addiu $v0, $v0, 0x1e80
.L7F0017EC:
/* 03631C 7F0017EC 24420088 */  addiu $v0, $v0, 0x88
/* 036320 7F0017F0 0043082B */  sltu  $at, $v0, $v1
/* 036324 7F0017F4 1420FFFD */  bnez  $at, .L7F0017EC
/* 036328 7F0017F8 AC40FF88 */   sw    $zero, -0x78($v0)
/* 03632C 7F0017FC 3C018003 */  lui   $at, %hi(D_80030AF8) # $at, 0x8003
/* 036330 7F001800 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80072E70) # $v0, 0x8007
/* 036334 7F001804 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80073370) # $v1, 0x8007
/* 036338 7F001808 AC200AF8 */  sw    $zero, %lo(D_80030AF8)($at)
/* 03633C 7F00180C 24633370 */  addiu $v1, %lo(dword_CODE_bss_80073370) # addiu $v1, $v1, 0x3370
/* 036340 7F001810 24422E70 */  addiu $v0, %lo(dword_CODE_bss_80072E70) # addiu $v0, $v0, 0x2e70
.L7F001814:
/* 036344 7F001814 24420080 */  addiu $v0, $v0, 0x80
/* 036348 7F001818 0043082B */  sltu  $at, $v0, $v1
/* 03634C 7F00181C 1420FFFD */  bnez  $at, .L7F001814
/* 036350 7F001820 AC40FF90 */   sw    $zero, -0x70($v0)
/* 036354 7F001824 3C018003 */  lui   $at, %hi(D_80030AFC) # $at, 0x8003
/* 036358 7F001828 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80073370) # $v0, 0x8007
/* 03635C 7F00182C 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80073DC0) # $v1, 0x8007
/* 036360 7F001830 AC200AFC */  sw    $zero, %lo(D_80030AFC)($at)
/* 036364 7F001834 24633DC0 */  addiu $v1, %lo(dword_CODE_bss_80073DC0) # addiu $v1, $v1, 0x3dc0
/* 036368 7F001838 24423370 */  addiu $v0, %lo(dword_CODE_bss_80073370) # addiu $v0, $v0, 0x3370
.L7F00183C:
/* 03636C 7F00183C 24420084 */  addiu $v0, $v0, 0x84
/* 036370 7F001840 0043082B */  sltu  $at, $v0, $v1
/* 036374 7F001844 1420FFFD */  bnez  $at, .L7F00183C
/* 036378 7F001848 AC40FF8C */   sw    $zero, -0x74($v0)
/* 03637C 7F00184C 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80073DC0) # $v0, 0x8007
/* 036380 7F001850 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80075030) # $a0, 0x8007
/* 036384 7F001854 24845030 */  addiu $a0, %lo(dword_CODE_bss_80075030) # addiu $a0, $a0, 0x5030
/* 036388 7F001858 24423DC0 */  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
/* 03638C 7F00185C 3C038000 */  lui   $v1, 0x8000
.L7F001860:
/* 036390 7F001860 244200EC */  addiu $v0, $v0, 0xec
/* 036394 7F001864 0044082B */  sltu  $at, $v0, $a0
/* 036398 7F001868 AC43FF14 */  sw    $v1, -0xec($v0)
/* 03639C 7F00186C AC40FFAC */  sw    $zero, -0x54($v0)
/* 0363A0 7F001870 1420FFFB */  bnez  $at, .L7F001860
/* 0363A4 7F001874 AC40FFB0 */   sw    $zero, -0x50($v0)
/* 0363A8 7F001878 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80075030) # $v0, 0x8007
/* 0363AC 7F00187C 3C038007 */  lui   $v1, %hi(objinst) # $v1, 0x8007
/* 0363B0 7F001880 24635B70 */  addiu $v1, %lo(objinst) # addiu $v1, $v1, 0x5b70
/* 0363B4 7F001884 24425030 */  addiu $v0, %lo(dword_CODE_bss_80075030) # addiu $v0, $v0, 0x5030
.L7F001888:
/* 0363B8 7F001888 24420120 */  addiu $v0, $v0, 0x120
/* 0363BC 7F00188C AC45FF28 */  sw    $a1, -0xd8($v0)
/* 0363C0 7F001890 AC45FF70 */  sw    $a1, -0x90($v0)
/* 0363C4 7F001894 AC45FFB8 */  sw    $a1, -0x48($v0)
/* 0363C8 7F001898 1443FFFB */  bne   $v0, $v1, .L7F001888
/* 0363CC 7F00189C AC45FEE0 */   sw    $a1, -0x120($v0)
/* 0363D0 7F0018A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0363D4 7F0018A4 44810000 */  mtc1  $at, $f0
/* 0363D8 7F0018A8 3C018003 */  lui   $at, %hi(D_80030B00) # $at, 0x8003
/* 0363DC 7F0018AC AC200B00 */  sw    $zero, %lo(D_80030B00)($at)
/* 0363E0 7F0018B0 3C018003 */  lui   $at, %hi(D_80030B04) # $at, 0x8003
/* 0363E4 7F0018B4 AC200B04 */  sw    $zero, %lo(D_80030B04)($at)
/* 0363E8 7F0018B8 3C018003 */  lui   $at, %hi(D_80030B08) # $at, 0x8003
/* 0363EC 7F0018BC AC200B08 */  sw    $zero, %lo(D_80030B08)($at)
/* 0363F0 7F0018C0 3C018003 */  lui   $at, %hi(D_80030B0C) # $at, 0x8003
/* 0363F4 7F0018C4 AC200B0C */  sw    $zero, %lo(D_80030B0C)($at)
/* 0363F8 7F0018C8 3C018003 */  lui   $at, %hi(bodypartshot) # $at, 0x8003
/* 0363FC 7F0018CC 240EFFFF */  li    $t6, -1
/* 036400 7F0018D0 AC2E0B10 */  sw    $t6, %lo(bodypartshot)($at)
/* 036404 7F0018D4 3C018003 */  lui   $at, %hi(D_80030B14) # $at, 0x8003
/* 036408 7F0018D8 E4200B14 */  swc1  $f0, %lo(D_80030B14)($at)
/* 03640C 7F0018DC 3C018003 */  lui   $at, %hi(D_80030B18) # $at, 0x8003
/* 036410 7F0018E0 E4200B18 */  swc1  $f0, %lo(D_80030B18)($at)
/* 036414 7F0018E4 3C018003 */  lui   $at, %hi(D_80030B1C) # $at, 0x8003
/* 036418 7F0018E8 E4200B1C */  swc1  $f0, %lo(D_80030B1C)($at)
/* 03641C 7F0018EC 3C018003 */  lui   $at, %hi(D_80030B20) # $at, 0x8003
/* 036420 7F0018F0 E4200B20 */  swc1  $f0, %lo(D_80030B20)($at)
/* 036424 7F0018F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 036428 7F0018F8 3C018003 */  lui   $at, %hi(D_80030B24) # $at, 0x8003
/* 03642C 7F0018FC E4200B24 */  swc1  $f0, %lo(D_80030B24)($at)
/* 036430 7F001900 3C018003 */  lui   $at, %hi(solo_ammo_multiplier)
/* 036434 7F001904 27BD0018 */  addiu $sp, $sp, 0x18
/* 036438 7F001908 03E00008 */  jr    $ra
/* 03643C 7F00190C E4200B28 */   swc1  $f0, %lo(solo_ammo_multiplier)($at)
)
#endif

#ifdef NONMATCHING
void sub_GAME_7F001910(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F001910
/* 036440 7F001910 3C028003 */  lui   $v0, %hi(D_80030B00) # $v0, 0x8003
/* 036444 7F001914 24420B00 */  addiu $v0, %lo(D_80030B00) # addiu $v0, $v0, 0xb00
/* 036448 7F001918 8C4E0000 */  lw    $t6, ($v0)
/* 03644C 7F00191C AC8E000C */  sw    $t6, 0xc($a0)
/* 036450 7F001920 03E00008 */  jr    $ra
/* 036454 7F001924 AC440000 */   sw    $a0, ($v0)
)
#endif

#ifdef NONMATCHING
void sub_GAME_7F001928(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F001928
/* 036458 7F001928 3C028003 */  lui   $v0, %hi(D_80030B04) # $v0, 0x8003
/* 03645C 7F00192C 24420B04 */  addiu $v0, %lo(D_80030B04) # addiu $v0, $v0, 0xb04
/* 036460 7F001930 8C4E0000 */  lw    $t6, ($v0)
/* 036464 7F001934 AC8E000C */  sw    $t6, 0xc($a0)
/* 036468 7F001938 03E00008 */  jr    $ra
/* 03646C 7F00193C AC440000 */   sw    $a0, ($v0)
)
#endif

#ifdef NONMATCHING
void sub_GAME_7F001940(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F001940
/* 036470 7F001940 3C028003 */  lui   $v0, %hi(D_80030B08) # $v0, 0x8003
/* 036474 7F001944 24420B08 */  addiu $v0, %lo(D_80030B08) # addiu $v0, $v0, 0xb08
/* 036478 7F001948 8C4E0000 */  lw    $t6, ($v0)
/* 03647C 7F00194C AC8E0010 */  sw    $t6, 0x10($a0)
/* 036480 7F001950 03E00008 */  jr    $ra
/* 036484 7F001954 AC440000 */   sw    $a0, ($v0)
)
#endif

#ifdef NONMATCHING
void write_monitor_ani_control_blocks(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_monitor_ani_control_blocks
/* 036488 7F001958 27BDFEA0 */  addiu $sp, $sp, -0x160
/* 03648C 7F00195C 3C0E8003 */  lui   $t6, %hi(ptr_monitorimageobjectanimationcontroller)
/* 036490 7F001960 27A200EC */  addiu $v0, $sp, 0xec
/* 036494 7F001964 25CEA260 */  addiu $t6, $t6, %lo(ptr_monitorimageobjectanimationcontroller)
/* 036498 7F001968 27A30078 */  addiu $v1, $sp, 0x78
/* 03649C 7F00196C 27A40004 */  addiu $a0, $sp, 4
/* 0364A0 7F001970 25D9006C */  addiu $t9, $t6, 0x6c
/* 0364A4 7F001974 00404025 */  move  $t0, $v0
.L7F001978:
/* 0364A8 7F001978 8DC10000 */  lw    $at, ($t6)
/* 0364AC 7F00197C 25CE000C */  addiu $t6, $t6, 0xc
/* 0364B0 7F001980 2508000C */  addiu $t0, $t0, 0xc
/* 0364B4 7F001984 AD01FFF4 */  sw    $at, -0xc($t0)
/* 0364B8 7F001988 8DC1FFF8 */  lw    $at, -8($t6)
/* 0364BC 7F00198C AD01FFF8 */  sw    $at, -8($t0)
/* 0364C0 7F001990 8DC1FFFC */  lw    $at, -4($t6)
/* 0364C4 7F001994 15D9FFF8 */  bne   $t6, $t9, .L7F001978
/* 0364C8 7F001998 AD01FFFC */   sw    $at, -4($t0)
/* 0364CC 7F00199C 8DC10000 */  lw    $at, ($t6)
/* 0364D0 7F0019A0 3C098007 */  lui   $t1, %hi(dword_CODE_bss_80075B98) # $t1, 0x8007
/* 0364D4 7F0019A4 25295B98 */  addiu $t1, %lo(dword_CODE_bss_80075B98) # addiu $t1, $t1, 0x5b98
/* 0364D8 7F0019A8 AD010000 */  sw    $at, ($t0)
/* 0364DC 7F0019AC 8DD90004 */  lw    $t9, 4($t6)
/* 0364E0 7F0019B0 00406825 */  move  $t5, $v0
/* 0364E4 7F0019B4 244C006C */  addiu $t4, $v0, 0x6c
/* 0364E8 7F0019B8 AD190004 */  sw    $t9, 4($t0)
.L7F0019BC:
/* 0364EC 7F0019BC 8DA10000 */  lw    $at, ($t5)
/* 0364F0 7F0019C0 25AD000C */  addiu $t5, $t5, 0xc
/* 0364F4 7F0019C4 2529000C */  addiu $t1, $t1, 0xc
/* 0364F8 7F0019C8 AD21FFF4 */  sw    $at, -0xc($t1)
/* 0364FC 7F0019CC 8DA1FFF8 */  lw    $at, -8($t5)
/* 036500 7F0019D0 AD21FFF8 */  sw    $at, -8($t1)
/* 036504 7F0019D4 8DA1FFFC */  lw    $at, -4($t5)
/* 036508 7F0019D8 15ACFFF8 */  bne   $t5, $t4, .L7F0019BC
/* 03650C 7F0019DC AD21FFFC */   sw    $at, -4($t1)
/* 036510 7F0019E0 8DA10000 */  lw    $at, ($t5)
/* 036514 7F0019E4 3C188003 */  lui   $t8, %hi(unknown_object_animation_controller) # $t8, 0x8003
/* 036518 7F0019E8 2718A2D4 */  addiu $t8, %lo(unknown_object_animation_controller) # addiu $t8, $t8, -0x5d2c
/* 03651C 7F0019EC AD210000 */  sw    $at, ($t1)
/* 036520 7F0019F0 8DAC0004 */  lw    $t4, 4($t5)
/* 036524 7F0019F4 270E006C */  addiu $t6, $t8, 0x6c
/* 036528 7F0019F8 00604025 */  move  $t0, $v1
/* 03652C 7F0019FC AD2C0004 */  sw    $t4, 4($t1)
.L7F001A00:
/* 036530 7F001A00 8F010000 */  lw    $at, ($t8)
/* 036534 7F001A04 2718000C */  addiu $t8, $t8, 0xc
/* 036538 7F001A08 2508000C */  addiu $t0, $t0, 0xc
/* 03653C 7F001A0C AD01FFF4 */  sw    $at, -0xc($t0)
/* 036540 7F001A10 8F01FFF8 */  lw    $at, -8($t8)
/* 036544 7F001A14 AD01FFF8 */  sw    $at, -8($t0)
/* 036548 7F001A18 8F01FFFC */  lw    $at, -4($t8)
/* 03654C 7F001A1C 170EFFF8 */  bne   $t8, $t6, .L7F001A00
/* 036550 7F001A20 AD01FFFC */   sw    $at, -4($t0)
/* 036554 7F001A24 8F010000 */  lw    $at, ($t8)
/* 036558 7F001A28 3C0B8007 */  lui   $t3, %hi(dword_CODE_bss_80075C10) # $t3, 0x8007
/* 03655C 7F001A2C 256B5C10 */  addiu $t3, %lo(dword_CODE_bss_80075C10) # addiu $t3, $t3, 0x5c10
/* 036560 7F001A30 AD010000 */  sw    $at, ($t0)
/* 036564 7F001A34 8F0E0004 */  lw    $t6, 4($t8)
/* 036568 7F001A38 00604825 */  move  $t1, $v1
/* 03656C 7F001A3C 246D006C */  addiu $t5, $v1, 0x6c
/* 036570 7F001A40 AD0E0004 */  sw    $t6, 4($t0)
.L7F001A44:
/* 036574 7F001A44 8D210000 */  lw    $at, ($t1)
/* 036578 7F001A48 2529000C */  addiu $t1, $t1, 0xc
/* 03657C 7F001A4C 256B000C */  addiu $t3, $t3, 0xc
/* 036580 7F001A50 AD61FFF4 */  sw    $at, -0xc($t3)
/* 036584 7F001A54 8D21FFF8 */  lw    $at, -8($t1)
/* 036588 7F001A58 AD61FFF8 */  sw    $at, -8($t3)
/* 03658C 7F001A5C 8D21FFFC */  lw    $at, -4($t1)
/* 036590 7F001A60 152DFFF8 */  bne   $t1, $t5, .L7F001A44
/* 036594 7F001A64 AD61FFFC */   sw    $at, -4($t3)
/* 036598 7F001A68 8D210000 */  lw    $at, ($t1)
/* 03659C 7F001A6C 3C198003 */  lui   $t9, %hi(taser_object_animation_controller) # $t9, 0x8003
/* 0365A0 7F001A70 2739A348 */  addiu $t9, %lo(taser_object_animation_controller) # addiu $t9, $t9, -0x5cb8
/* 0365A4 7F001A74 AD610000 */  sw    $at, ($t3)
/* 0365A8 7F001A78 8D2D0004 */  lw    $t5, 4($t1)
/* 0365AC 7F001A7C 2738006C */  addiu $t8, $t9, 0x6c
/* 0365B0 7F001A80 00804025 */  move  $t0, $a0
/* 0365B4 7F001A84 AD6D0004 */  sw    $t5, 4($t3)
.L7F001A88:
/* 0365B8 7F001A88 8F210000 */  lw    $at, ($t9)
/* 0365BC 7F001A8C 2739000C */  addiu $t9, $t9, 0xc
/* 0365C0 7F001A90 2508000C */  addiu $t0, $t0, 0xc
/* 0365C4 7F001A94 AD01FFF4 */  sw    $at, -0xc($t0)
/* 0365C8 7F001A98 8F21FFF8 */  lw    $at, -8($t9)
/* 0365CC 7F001A9C AD01FFF8 */  sw    $at, -8($t0)
/* 0365D0 7F001AA0 8F21FFFC */  lw    $at, -4($t9)
/* 0365D4 7F001AA4 1738FFF8 */  bne   $t9, $t8, .L7F001A88
/* 0365D8 7F001AA8 AD01FFFC */   sw    $at, -4($t0)
/* 0365DC 7F001AAC 8F210000 */  lw    $at, ($t9)
/* 0365E0 7F001AB0 3C0C8007 */  lui   $t4, %hi(dword_CODE_bss_80075C88) # $t4, 0x8007
/* 0365E4 7F001AB4 258C5C88 */  addiu $t4, %lo(dword_CODE_bss_80075C88) # addiu $t4, $t4, 0x5c88
/* 0365E8 7F001AB8 AD010000 */  sw    $at, ($t0)
/* 0365EC 7F001ABC 8F380004 */  lw    $t8, 4($t9)
/* 0365F0 7F001AC0 00805825 */  move  $t3, $a0
/* 0365F4 7F001AC4 2489006C */  addiu $t1, $a0, 0x6c
/* 0365F8 7F001AC8 AD180004 */  sw    $t8, 4($t0)
.L7F001ACC:
/* 0365FC 7F001ACC 8D610000 */  lw    $at, ($t3)
/* 036600 7F001AD0 256B000C */  addiu $t3, $t3, 0xc
/* 036604 7F001AD4 258C000C */  addiu $t4, $t4, 0xc
/* 036608 7F001AD8 AD81FFF4 */  sw    $at, -0xc($t4)
/* 03660C 7F001ADC 8D61FFF8 */  lw    $at, -8($t3)
/* 036610 7F001AE0 AD81FFF8 */  sw    $at, -8($t4)
/* 036614 7F001AE4 8D61FFFC */  lw    $at, -4($t3)
/* 036618 7F001AE8 1569FFF8 */  bne   $t3, $t1, .L7F001ACC
/* 03661C 7F001AEC AD81FFFC */   sw    $at, -4($t4)
/* 036620 7F001AF0 8D610000 */  lw    $at, ($t3)
/* 036624 7F001AF4 AD810000 */  sw    $at, ($t4)
/* 036628 7F001AF8 8D690004 */  lw    $t1, 4($t3)
/* 03662C 7F001AFC 27BD0160 */  addiu $sp, $sp, 0x160
/* 036630 7F001B00 03E00008 */  jr    $ra
/* 036634 7F001B04 AD890004 */   sw    $t1, 4($t4)
)
#endif

#ifdef NONMATCHING
void initialize_80071E00_to_80071E78(void) {

}
#else
GLOBAL_ASM(
.text
glabel initialize_80071E00_to_80071E78
/* 036638 7F001B08 3C018007 */  lui   $at, %hi(dword_CODE_bss_80071E00) # $at, 0x8007
/* 03663C 7F001B0C AC201E00 */  sw    $zero, %lo(dword_CODE_bss_80071E00)($at)
/* 036640 7F001B10 3C018007 */  lui   $at, %hi(dword_CODE_bss_80071E04) # $at, 0x8007
/* 036644 7F001B14 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80071E08) # $v1, 0x8007
/* 036648 7F001B18 3C028007 */  lui   $v0, %hi(gas_damage_flag) # $v0, 0x8007
/* 03664C 7F001B1C 24421E78 */  addiu $v0, %lo(gas_damage_flag) # addiu $v0, $v0, 0x1e78
/* 036650 7F001B20 24631E08 */  addiu $v1, %lo(dword_CODE_bss_80071E08) # addiu $v1, $v1, 0x1e08
/* 036654 7F001B24 AC201E04 */  sw    $zero, %lo(dword_CODE_bss_80071E04)($at)
.L7F001B28:
/* 036658 7F001B28 24630010 */  addiu $v1, $v1, 0x10
/* 03665C 7F001B2C AC60FFF4 */  sw    $zero, -0xc($v1)
/* 036660 7F001B30 AC60FFF8 */  sw    $zero, -8($v1)
/* 036664 7F001B34 AC60FFFC */  sw    $zero, -4($v1)
/* 036668 7F001B38 1462FFFB */  bne   $v1, $v0, .L7F001B28
/* 03666C 7F001B3C AC60FFF0 */   sw    $zero, -0x10($v1)
/* 036670 7F001B40 03E00008 */  jr    $ra
/* 036674 7F001B44 00000000 */   nop   
)
#endif
