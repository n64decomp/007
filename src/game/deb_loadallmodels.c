#include "ultra64.h"

//i belong in a header, probably to another file
#define PROJECTILES_MAX 0x2E
#define PROJECTILES_TYPE_KNIFE 0xBA
#define PROJECTILES_TYPE_GRENADE 0xC4
#define PROJECTILES_TYPE_REMOTE_MINE 0xC7
#define PROJECTILES_TYPE_PROX_MINE 0xC8
#define PROJECTILES_TYPE_TIMED_MINE 0xC9
#define PROJECTILES_TYPE_ROCKET_ROUND 0xCA
#define PROJECTILES_TYPE_ROCKET_ROUND2 0xCA
#define PROJECTILES_TYPE_GLAUNCH_ROUND 0xCB
#define PROJECTILES_TYPE_BOMBCASE 0xE2
#define PROJECTILES_TYPE_BUG 0xF5
#define PROJECTILES_TYPE_MICROCAMERA 0xF6
#define PROJECTILES_TYPE_GE_KEY 0xF8
#define PROJECTILES_TYPE_PLASTIQUE 0x111





u32 global_action_block_temp_buffer[119] = {0};

s32 weapon_models_for_weapon_load[] = {
PROJECTILES_TYPE_KNIFE, PROJECTILES_TYPE_GRENADE, PROJECTILES_TYPE_REMOTE_MINE,
PROJECTILES_TYPE_PROX_MINE, PROJECTILES_TYPE_TIMED_MINE, PROJECTILES_TYPE_ROCKET_ROUND,
PROJECTILES_TYPE_GLAUNCH_ROUND, 0xFFFFFFFF};



#ifdef NONMATCHING
void init_obj_register_difficulty_vals(void) {
    objectiveregisters1 = 0;
    ai_accuracy_modifier = 1.0f;
    ai_damage_modifier = 1.0f;
    ai_health_modifier = 1.0f;
    ai_reaction_speed = 1.0f;
    setting_007_5 = 0.0f;
}
#else
GLOBAL_ASM(
.text
glabel init_obj_register_difficulty_vals
/* 035B50 7F001020 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 035B54 7F001024 44810000 */  mtc1  $at, $f0
/* 035B58 7F001028 3C018003 */  lui   $at, %hi(objectiveregisters1)
/* 035B5C 7F00102C AC200978 */  sw    $zero, %lo(objectiveregisters1)($at)
/* 035B60 7F001030 3C018003 */  lui   $at, %hi(ai_accuracy_modifier)
/* 035B64 7F001034 E420CE40 */  swc1  $f0, %lo(ai_accuracy_modifier)($at)
/* 035B68 7F001038 3C018003 */  lui   $at, %hi(ai_damage_modifier)
/* 035B6C 7F00103C E420CE44 */  swc1  $f0, %lo(ai_damage_modifier)($at)
/* 035B70 7F001040 3C018003 */  lui   $at, %hi(ai_health_modifier)
/* 035B74 7F001044 E420CE48 */  swc1  $f0, %lo(ai_health_modifier)($at)
/* 035B78 7F001048 3C018003 */  lui   $at, %hi(ai_reaction_speed)
/* 035B7C 7F00104C E420CE4C */  swc1  $f0, %lo(ai_reaction_speed)($at)
/* 035B80 7F001050 3C018003 */  lui   $at, %hi(setting_007_5)
/* 035B84 7F001054 03E00008 */  jr    $ra
/* 035B88 7F001058 AC20CE50 */   sw    $zero, %lo(setting_007_5)($at)
)
#endif


#ifdef NONMATCHING
void alloc_false_GUARDdata_to_exec_global_action(void) {

}
#else
GLOBAL_ASM(
.text
glabel alloc_false_GUARDdata_to_exec_global_action
/* 035B8C 7F00105C 3C0D8007 */  lui   $t5, %hi(ptr_setup_path_tbl) 
/* 035B90 7F001060 25AD5D00 */  addiu $t5, %lo(ptr_setup_path_tbl) # addiu $t5, $t5, 0x5d00
/* 035B94 7F001064 8DA50014 */  lw    $a1, 0x14($t5)
/* 035B98 7F001068 3C028003 */  lui   $v0, %hi(objectiveregisters3)
/* 035B9C 7F00106C 3C068003 */  lui   $a2, %hi(objectiveregisters2)
/* 035BA0 7F001070 24C6097C */  addiu $a2, %lo(objectiveregisters2) # addiu $a2, $a2, 0x97c
/* 035BA4 7F001074 24420980 */  addiu $v0, %lo(objectiveregisters3) # addiu $v0, $v0, 0x980
/* 035BA8 7F001078 27BDFDF8 */  addiu $sp, $sp, -0x208
/* 035BAC 7F00107C AFBF0014 */  sw    $ra, 0x14($sp)
/* 035BB0 7F001080 ACC00000 */  sw    $zero, ($a2)
/* 035BB4 7F001084 10A00070 */  beqz  $a1, .L7F001248
/* 035BB8 7F001088 AC400000 */   sw    $zero, ($v0)
/* 035BBC 7F00108C 8CAE0000 */  lw    $t6, ($a1)
/* 035BC0 7F001090 00A01825 */  move  $v1, $a1
/* 035BC4 7F001094 00003825 */  move  $a3, $zero
/* 035BC8 7F001098 11C0000C */  beqz  $t6, .L7F0010CC
/* 035BCC 7F00109C 24050004 */   li    $a1, 4
/* 035BD0 7F0010A0 8C6F0004 */  lw    $t7, 4($v1)
.L7F0010A4:
/* 035BD4 7F0010A4 29E11000 */  slti  $at, $t7, 0x1000
/* 035BD8 7F0010A8 54200005 */  bnezl $at, .L7F0010C0
/* 035BDC 7F0010AC 8C6E0008 */   lw    $t6, 8($v1)
/* 035BE0 7F0010B0 8C580000 */  lw    $t8, ($v0)
/* 035BE4 7F0010B4 27190001 */  addiu $t9, $t8, 1
/* 035BE8 7F0010B8 AC590000 */  sw    $t9, ($v0)
/* 035BEC 7F0010BC 8C6E0008 */  lw    $t6, 8($v1)
.L7F0010C0:
/* 035BF0 7F0010C0 24630008 */  addiu $v1, $v1, 8
/* 035BF4 7F0010C4 55C0FFF7 */  bnezl $t6, .L7F0010A4
/* 035BF8 7F0010C8 8C6F0004 */   lw    $t7, 4($v1)
.L7F0010CC:
/* 035BFC 7F0010CC 8C430000 */  lw    $v1, ($v0)
/* 035C00 7F0010D0 00004025 */  move  $t0, $zero
/* 035C04 7F0010D4 1860005C */  blez  $v1, .L7F001248
/* 035C08 7F0010D8 00032100 */   sll   $a0, $v1, 4
/* 035C0C 7F0010DC 00832023 */  subu  $a0, $a0, $v1
/* 035C10 7F0010E0 000420C0 */  sll   $a0, $a0, 3
/* 035C14 7F0010E4 00832023 */  subu  $a0, $a0, $v1
/* 035C18 7F0010E8 00042080 */  sll   $a0, $a0, 2
/* 035C1C 7F0010EC 2484000F */  addiu $a0, $a0, 0xf
/* 035C20 7F0010F0 348F000F */  ori   $t7, $a0, 0xf
/* 035C24 7F0010F4 39E4000F */  xori  $a0, $t7, 0xf
/* 035C28 7F0010F8 0C0025C8 */  jal   mempAllocBytesInBank
/* 035C2C 7F0010FC AFA70200 */   sw    $a3, 0x200($sp)
/* 035C30 7F001100 3C0D8007 */  lui   $t5, %hi(ptr_setup_path_tbl) 
/* 035C34 7F001104 25AD5D00 */  addiu $t5, %lo(ptr_setup_path_tbl) # addiu $t5, $t5, 0x5d00
/* 035C38 7F001108 8DA50014 */  lw    $a1, 0x14($t5)
/* 035C3C 7F00110C 3C068003 */  lui   $a2, %hi(objectiveregisters2)
/* 035C40 7F001110 24C6097C */  addiu $a2, %lo(objectiveregisters2) # addiu $a2, $a2, 0x97c
/* 035C44 7F001114 ACC20000 */  sw    $v0, ($a2)
/* 035C48 7F001118 8CB90000 */  lw    $t9, ($a1)
/* 035C4C 7F00111C 8FA70200 */  lw    $a3, 0x200($sp)
/* 035C50 7F001120 00002025 */  move  $a0, $zero
/* 035C54 7F001124 13200048 */  beqz  $t9, .L7F001248
/* 035C58 7F001128 00A01825 */   move  $v1, $a1
/* 035C5C 7F00112C 3C088003 */  lui   $t0, %hi(global_action_block_temp_buffer) 
/* 035C60 7F001130 2508A060 */  addiu $t0, %lo(global_action_block_temp_buffer) # addiu $t0, $t0, -0x5fa0
/* 035C64 7F001134 240C001A */  li    $t4, 26
/* 035C68 7F001138 240BFFFF */  li    $t3, -1
/* 035C6C 7F00113C 240A00FE */  li    $t2, 254
/* 035C70 7F001140 240901DC */  li    $t1, 476
/* 035C74 7F001144 27A50024 */  addiu $a1, $sp, 0x24
/* 035C78 7F001148 8C6E0004 */  lw    $t6, 4($v1)
.L7F00114C:
/* 035C7C 7F00114C 0100C825 */  move  $t9, $t0
/* 035C80 7F001150 251801D4 */  addiu $t8, $t0, 0x1d4
/* 035C84 7F001154 29C11000 */  slti  $at, $t6, 0x1000
/* 035C88 7F001158 14200036 */  bnez  $at, .L7F001234
/* 035C8C 7F00115C 00A07025 */   move  $t6, $a1
.L7F001160:
/* 035C90 7F001160 8F210000 */  lw    $at, ($t9)
/* 035C94 7F001164 2739000C */  addiu $t9, $t9, 0xc
/* 035C98 7F001168 25CE000C */  addiu $t6, $t6, 0xc
/* 035C9C 7F00116C ADC1FFF4 */  sw    $at, -0xc($t6)
/* 035CA0 7F001170 8F21FFF8 */  lw    $at, -8($t9)
/* 035CA4 7F001174 ADC1FFF8 */  sw    $at, -8($t6)
/* 035CA8 7F001178 8F21FFFC */  lw    $at, -4($t9)
/* 035CAC 7F00117C 1738FFF8 */  bne   $t9, $t8, .L7F001160
/* 035CB0 7F001180 ADC1FFFC */   sw    $at, -4($t6)
/* 035CB4 7F001184 00E90019 */  multu $a3, $t1
/* 035CB8 7F001188 8F210000 */  lw    $at, ($t9)
/* 035CBC 7F00118C ADC10000 */  sw    $at, ($t6)
/* 035CC0 7F001190 8F380004 */  lw    $t8, 4($t9)
/* 035CC4 7F001194 ADD80004 */  sw    $t8, 4($t6)
/* 035CC8 7F001198 8CCF0000 */  lw    $t7, ($a2)
/* 035CCC 7F00119C 00001012 */  mflo  $v0
/* 035CD0 7F0011A0 24AE01D4 */  addiu $t6, $a1, 0x1d4
/* 035CD4 7F0011A4 01E2C021 */  addu  $t8, $t7, $v0
/* 035CD8 7F0011A8 00A07825 */  move  $t7, $a1
.L7F0011AC:
/* 035CDC 7F0011AC 8DE10000 */  lw    $at, ($t7)
/* 035CE0 7F0011B0 25EF000C */  addiu $t7, $t7, 0xc
/* 035CE4 7F0011B4 2718000C */  addiu $t8, $t8, 0xc
/* 035CE8 7F0011B8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 035CEC 7F0011BC 8DE1FFF8 */  lw    $at, -8($t7)
/* 035CF0 7F0011C0 AF01FFF8 */  sw    $at, -8($t8)
/* 035CF4 7F0011C4 8DE1FFFC */  lw    $at, -4($t7)
/* 035CF8 7F0011C8 15EEFFF8 */  bne   $t7, $t6, .L7F0011AC
/* 035CFC 7F0011CC AF01FFFC */   sw    $at, -4($t8)
/* 035D00 7F0011D0 8DE10000 */  lw    $at, ($t7)
/* 035D04 7F0011D4 24E70001 */  addiu $a3, $a3, 1
/* 035D08 7F0011D8 AF010000 */  sw    $at, ($t8)
/* 035D0C 7F0011DC 8DEE0004 */  lw    $t6, 4($t7)
/* 035D10 7F0011E0 AF0E0004 */  sw    $t6, 4($t8)
/* 035D14 7F0011E4 8CD90000 */  lw    $t9, ($a2)
/* 035D18 7F0011E8 03227021 */  addu  $t6, $t9, $v0
/* 035D1C 7F0011EC A5CA0000 */  sh    $t2, ($t6)
/* 035D20 7F0011F0 8DAF0014 */  lw    $t7, 0x14($t5)
/* 035D24 7F0011F4 8CCE0000 */  lw    $t6, ($a2)
/* 035D28 7F0011F8 01E4C021 */  addu  $t8, $t7, $a0
/* 035D2C 7F0011FC 8F190000 */  lw    $t9, ($t8)
/* 035D30 7F001200 01C27821 */  addu  $t7, $t6, $v0
/* 035D34 7F001204 ADF90104 */  sw    $t9, 0x104($t7)
/* 035D38 7F001208 8CD80000 */  lw    $t8, ($a2)
/* 035D3C 7F00120C 03027021 */  addu  $t6, $t8, $v0
/* 035D40 7F001210 A5C00108 */  sh    $zero, 0x108($t6)
/* 035D44 7F001214 8CD90000 */  lw    $t9, ($a2)
/* 035D48 7F001218 03227821 */  addu  $t7, $t9, $v0
/* 035D4C 7F00121C A5EB010A */  sh    $t3, 0x10a($t7)
/* 035D50 7F001220 8CD80000 */  lw    $t8, ($a2)
/* 035D54 7F001224 03027021 */  addu  $t6, $t8, $v0
/* 035D58 7F001228 A1CC0007 */  sb    $t4, 7($t6)
/* 035D5C 7F00122C 8DB90014 */  lw    $t9, 0x14($t5)
/* 035D60 7F001230 03241821 */  addu  $v1, $t9, $a0
.L7F001234:
/* 035D64 7F001234 8C6F0008 */  lw    $t7, 8($v1)
/* 035D68 7F001238 24840008 */  addiu $a0, $a0, 8
/* 035D6C 7F00123C 24630008 */  addiu $v1, $v1, 8
/* 035D70 7F001240 55E0FFC2 */  bnezl $t7, .L7F00114C
/* 035D74 7F001244 8C6E0004 */   lw    $t6, 4($v1)
.L7F001248:
/* 035D78 7F001248 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035D7C 7F00124C 27BD0208 */  addiu $sp, $sp, 0x208
/* 035D80 7F001250 03E00008 */  jr    $ra
/* 035D84 7F001254 00000000 */   nop   
)
#endif

#ifdef NONMATCHING
void debug_object_load_all_models(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_object_load_all_models
/* 035D88 7F001258 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 035D8C 7F00125C 3C0E8007 */  lui   $t6, %hi(ptr_setup_actions) 
/* 035D90 7F001260 8DCE5D14 */  lw    $t6, %lo(ptr_setup_actions)($t6)
/* 035D94 7F001264 AFBF0034 */  sw    $ra, 0x34($sp)
/* 035D98 7F001268 AFB70030 */  sw    $s7, 0x30($sp)
/* 035D9C 7F00126C AFB6002C */  sw    $s6, 0x2c($sp)
/* 035DA0 7F001270 AFB50028 */  sw    $s5, 0x28($sp)
/* 035DA4 7F001274 AFB40024 */  sw    $s4, 0x24($sp)
/* 035DA8 7F001278 AFB30020 */  sw    $s3, 0x20($sp)
/* 035DAC 7F00127C AFB2001C */  sw    $s2, 0x1c($sp)
/* 035DB0 7F001280 AFB10018 */  sw    $s1, 0x18($sp)
/* 035DB4 7F001284 AFB00014 */  sw    $s0, 0x14($sp)
/* 035DB8 7F001288 8DD00000 */  lw    $s0, ($t6)
/* 035DBC 7F00128C 241500BF */  li    $s5, 191
/* 035DC0 7F001290 241600C0 */  li    $s6, 192
/* 035DC4 7F001294 12000052 */  beqz  $s0, .L7F0013E0
/* 035DC8 7F001298 0000B825 */   move  $s7, $zero
/* 035DCC 7F00129C 241400BE */  li    $s4, 190
/* 035DD0 7F0012A0 241300BD */  li    $s3, 189
/* 035DD4 7F0012A4 2412001B */  li    $s2, 27
/* 035DD8 7F0012A8 24110004 */  li    $s1, 4
.L7F0012AC:
/* 035DDC 7F0012AC 92030000 */  lbu   $v1, ($s0)
.L7F0012B0:
/* 035DE0 7F0012B0 3C0F8007 */  lui   $t7, %hi(ptr_setup_actions) 
/* 035DE4 7F0012B4 16230004 */  bne   $s1, $v1, .L7F0012C8
/* 035DE8 7F0012B8 00000000 */   nop   
/* 035DEC 7F0012BC 8DEF5D14 */  lw    $t7, %lo(ptr_setup_actions)($t7)
/* 035DF0 7F0012C0 10000042 */  b     .L7F0013CC
/* 035DF4 7F0012C4 01F71021 */   addu  $v0, $t7, $s7
.L7F0012C8:
/* 035DF8 7F0012C8 5072000C */  beql  $v1, $s2, .L7F0012FC
/* 035DFC 7F0012CC 92180001 */   lbu   $t8, 1($s0)
/* 035E00 7F0012D0 10730013 */  beq   $v1, $s3, .L7F001320
/* 035E04 7F0012D4 00000000 */   nop   
/* 035E08 7F0012D8 1074001C */  beq   $v1, $s4, .L7F00134C
/* 035E0C 7F0012DC 00000000 */   nop   
/* 035E10 7F0012E0 50750026 */  beql  $v1, $s5, .L7F00137C
/* 035E14 7F0012E4 920A0001 */   lbu   $t2, 1($s0)
/* 035E18 7F0012E8 5076002F */  beql  $v1, $s6, .L7F0013A8
/* 035E1C 7F0012EC 920D0001 */   lbu   $t5, 1($s0)
/* 035E20 7F0012F0 10000032 */  b     .L7F0013BC
/* 035E24 7F0012F4 02002025 */   move  $a0, $s0
/* 035E28 7F0012F8 92180001 */  lbu   $t8, 1($s0)
.L7F0012FC:
/* 035E2C 7F0012FC 92080002 */  lbu   $t0, 2($s0)
/* 035E30 7F001300 0018CA00 */  sll   $t9, $t8, 8
/* 035E34 7F001304 03281025 */  or    $v0, $t9, $t0
/* 035E38 7F001308 0FC15B0E */  jal   load_model
/* 035E3C 7F00130C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 035E40 7F001310 5040002A */  beql  $v0, $zero, .L7F0013BC
/* 035E44 7F001314 02002025 */   move  $a0, $s0
/* 035E48 7F001318 10000028 */  b     .L7F0013BC
/* 035E4C 7F00131C 02002025 */   move  $a0, $s0
.L7F001320:
/* 035E50 7F001320 0FC08CA4 */  jal   load_body_head_if_not_loaded
/* 035E54 7F001324 92040001 */   lbu   $a0, 1($s0)
/* 035E58 7F001328 82040002 */  lb    $a0, 2($s0)
/* 035E5C 7F00132C 04820023 */  bltzl $a0, .L7F0013BC
/* 035E60 7F001330 02002025 */   move  $a0, $s0
/* 035E64 7F001334 0FC08CA4 */  jal   load_body_head_if_not_loaded
/* 035E68 7F001338 00000000 */   nop   
/* 035E6C 7F00133C 5040001F */  beql  $v0, $zero, .L7F0013BC
/* 035E70 7F001340 02002025 */   move  $a0, $s0
/* 035E74 7F001344 1000001D */  b     .L7F0013BC
/* 035E78 7F001348 02002025 */   move  $a0, $s0
.L7F00134C:
/* 035E7C 7F00134C 0FC08CA4 */  jal   load_body_head_if_not_loaded
/* 035E80 7F001350 92040001 */   lbu   $a0, 1($s0)
/* 035E84 7F001354 82040002 */  lb    $a0, 2($s0)
/* 035E88 7F001358 04820018 */  bltzl $a0, .L7F0013BC
/* 035E8C 7F00135C 02002025 */   move  $a0, $s0
/* 035E90 7F001360 0FC08CA4 */  jal   load_body_head_if_not_loaded
/* 035E94 7F001364 00000000 */   nop   
/* 035E98 7F001368 50400014 */  beql  $v0, $zero, .L7F0013BC
/* 035E9C 7F00136C 02002025 */   move  $a0, $s0
/* 035EA0 7F001370 10000012 */  b     .L7F0013BC
/* 035EA4 7F001374 02002025 */   move  $a0, $s0
/* 035EA8 7F001378 920A0001 */  lbu   $t2, 1($s0)
.L7F00137C:
/* 035EAC 7F00137C 920C0002 */  lbu   $t4, 2($s0)
/* 035EB0 7F001380 000A5A00 */  sll   $t3, $t2, 8
/* 035EB4 7F001384 0FC15B0E */  jal   load_model
/* 035EB8 7F001388 016C2025 */   or    $a0, $t3, $t4
/* 035EBC 7F00138C 0FC015C4 */  jal   set_weapon_model_generated_thrown_object
/* 035EC0 7F001390 92040003 */   lbu   $a0, 3($s0)
/* 035EC4 7F001394 50400009 */  beql  $v0, $zero, .L7F0013BC
/* 035EC8 7F001398 02002025 */   move  $a0, $s0
/* 035ECC 7F00139C 10000007 */  b     .L7F0013BC
/* 035ED0 7F0013A0 02002025 */   move  $a0, $s0
/* 035ED4 7F0013A4 920D0001 */  lbu   $t5, 1($s0)
.L7F0013A8:
/* 035ED8 7F0013A8 920F0002 */  lbu   $t7, 2($s0)
/* 035EDC 7F0013AC 000D7200 */  sll   $t6, $t5, 8
/* 035EE0 7F0013B0 0FC15B0E */  jal   load_model
/* 035EE4 7F0013B4 01CF2025 */   or    $a0, $t6, $t7
/* 035EE8 7F0013B8 02002025 */  move  $a0, $s0
.L7F0013BC:
/* 035EEC 7F0013BC 0FC0D27F */  jal   get_length_of_action_block
/* 035EF0 7F0013C0 00002825 */   move  $a1, $zero
/* 035EF4 7F0013C4 1000FFB9 */  b     .L7F0012AC
/* 035EF8 7F0013C8 02028021 */   addu  $s0, $s0, $v0
.L7F0013CC:
/* 035EFC 7F0013CC 8C500008 */  lw    $s0, 8($v0)
/* 035F00 7F0013D0 26F70008 */  addiu $s7, $s7, 8
/* 035F04 7F0013D4 24420008 */  addiu $v0, $v0, 8
/* 035F08 7F0013D8 5600FFB5 */  bnezl $s0, .L7F0012B0
/* 035F0C 7F0013DC 92030000 */   lbu   $v1, ($s0)
.L7F0013E0:
/* 035F10 7F0013E0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 035F14 7F0013E4 8FB00014 */  lw    $s0, 0x14($sp)
/* 035F18 7F0013E8 8FB10018 */  lw    $s1, 0x18($sp)
/* 035F1C 7F0013EC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 035F20 7F0013F0 8FB30020 */  lw    $s3, 0x20($sp)
/* 035F24 7F0013F4 8FB40024 */  lw    $s4, 0x24($sp)
/* 035F28 7F0013F8 8FB50028 */  lw    $s5, 0x28($sp)
/* 035F2C 7F0013FC 8FB6002C */  lw    $s6, 0x2c($sp)
/* 035F30 7F001400 8FB70030 */  lw    $s7, 0x30($sp)
/* 035F34 7F001404 03E00008 */  jr    $ra
/* 035F38 7F001408 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif


#ifdef NONMATCHING
void debug_weapon_load_table(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_weapon_load_table
/* 035F3C 7F00140C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 035F40 7F001410 3C0F8003 */  lui   $t7, %hi(weapon_models_for_weapon_load) 
/* 035F44 7F001414 AFBF001C */  sw    $ra, 0x1c($sp)
/* 035F48 7F001418 AFB00018 */  sw    $s0, 0x18($sp)
/* 035F4C 7F00141C 25EFA23C */  addiu $t7, %lo(weapon_models_for_weapon_load) # addiu $t7, $t7, -0x5dc4
/* 035F50 7F001420 8DE10000 */  lw    $at, ($t7)
/* 035F54 7F001424 8DE80004 */  lw    $t0, 4($t7)
/* 035F58 7F001428 27AE0030 */  addiu $t6, $sp, 0x30
/* 035F5C 7F00142C ADC10000 */  sw    $at, ($t6)
/* 035F60 7F001430 ADC80004 */  sw    $t0, 4($t6)
/* 035F64 7F001434 8DE8000C */  lw    $t0, 0xc($t7)
/* 035F68 7F001438 8DE10008 */  lw    $at, 8($t7)
/* 035F6C 7F00143C 27B00030 */  addiu $s0, $sp, 0x30
/* 035F70 7F001440 ADC8000C */  sw    $t0, 0xc($t6)
/* 035F74 7F001444 ADC10008 */  sw    $at, 8($t6)
/* 035F78 7F001448 8DE10010 */  lw    $at, 0x10($t7)
/* 035F7C 7F00144C 8DE80014 */  lw    $t0, 0x14($t7)
/* 035F80 7F001450 ADC10010 */  sw    $at, 0x10($t6)
/* 035F84 7F001454 ADC80014 */  sw    $t0, 0x14($t6)
/* 035F88 7F001458 8DE8001C */  lw    $t0, 0x1c($t7)
/* 035F8C 7F00145C 8DE10018 */  lw    $at, 0x18($t7)
/* 035F90 7F001460 ADC8001C */  sw    $t0, 0x1c($t6)
/* 035F94 7F001464 ADC10018 */  sw    $at, 0x18($t6)
/* 035F98 7F001468 8FA90030 */  lw    $t1, 0x30($sp)
/* 035F9C 7F00146C 05220009 */  bltzl $t1, .L7F001494
/* 035FA0 7F001470 8FBF001C */   lw    $ra, 0x1c($sp)
/* 035FA4 7F001474 8E040000 */  lw    $a0, ($s0)
.L7F001478:
/* 035FA8 7F001478 0FC15B0E */  jal   load_model
/* 035FAC 7F00147C 00000000 */   nop   
/* 035FB0 7F001480 8E040004 */  lw    $a0, 4($s0)
/* 035FB4 7F001484 26100004 */  addiu $s0, $s0, 4
/* 035FB8 7F001488 0481FFFB */  bgez  $a0, .L7F001478
/* 035FBC 7F00148C 00000000 */   nop   
/* 035FC0 7F001490 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F001494:
/* 035FC4 7F001494 8FB00018 */  lw    $s0, 0x18($sp)
/* 035FC8 7F001498 27BD0050 */  addiu $sp, $sp, 0x50
/* 035FCC 7F00149C 03E00008 */  jr    $ra
/* 035FD0 7F0014A0 00000000 */   nop
)
#endif


