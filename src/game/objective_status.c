#include "ultra64.h"
#include "bondconstants.h"
#include "bondtypes.h"

// bss
//CODE.bss:80075D30
struct objective_entry * objective_ptrs[10];
u32 dword_CODE_bss_80075D58;
u32 dword_CODE_bss_80075D5C;
char dword_CODE_bss_80075D60[0x20];
//CODE.bss:80075D80
u32 *ptr_last_tag_entry_type16;
//CODE.bss:80075D84
u32 *ptr_last_briefing_setup_entry_type23;
//CODE.bss:80075D88
u32 *ptr_last_enter_room_subobject_entry_type20;
//CODE.bss:80075D8C
u32 *ptr_last_deposit_in_room_subobject_entry_type21;
//CODE.bss:80075D90
u32 *ptr_last_photo_obj_in_room_subobject_entry_type1E;

// data
s32 num_objective_ptrs[] = {0xFFFFFFFF, 0};



// rodata
const u32 D_80053610[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
//D:80053644
const u32 aSAC[] = {0x25732080, 0x25632000};
//D:8005364C
const char aSC[] = "%s %c: ";



#ifdef NONMATCHING
void sub_GAME_7F057080(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F057080
/* 08BBB0 7F057080 3C038007 */  lui   $v1, %hi(ptr_last_tag_entry_type16)
/* 08BBB4 7F057084 8C635D80 */  lw    $v1, %lo(ptr_last_tag_entry_type16)($v1)
/* 08BBB8 7F057088 3082FFFF */  andi  $v0, $a0, 0xffff
/* 08BBBC 7F05708C 5060000A */  beql  $v1, $zero, .L7F0570B8
/* 08BBC0 7F057090 00001025 */   move  $v0, $zero
/* 08BBC4 7F057094 946E0004 */  lhu   $t6, 4($v1)
.L7F057098:
/* 08BBC8 7F057098 544E0004 */  bnel  $v0, $t6, .L7F0570AC
/* 08BBCC 7F05709C 8C630008 */   lw    $v1, 8($v1)
/* 08BBD0 7F0570A0 03E00008 */  jr    $ra
/* 08BBD4 7F0570A4 00601025 */   move  $v0, $v1

/* 08BBD8 7F0570A8 8C630008 */  lw    $v1, 8($v1)
.L7F0570AC:
/* 08BBDC 7F0570AC 5460FFFA */  bnezl $v1, .L7F057098
/* 08BBE0 7F0570B0 946E0004 */   lhu   $t6, 4($v1)
/* 08BBE4 7F0570B4 00001025 */  move  $v0, $zero
.L7F0570B8:
/* 08BBE8 7F0570B8 03E00008 */  jr    $ra
/* 08BBEC 7F0570BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_handle_to_tagged_object(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_handle_to_tagged_object
/* 08BBF0 7F0570C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08BBF4 7F0570C4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08BBF8 7F0570C8 0FC15C20 */  jal   sub_GAME_7F057080
/* 08BBFC 7F0570CC 00000000 */   nop   
/* 08BC00 7F0570D0 10400002 */  beqz  $v0, .L7F0570DC
/* 08BC04 7F0570D4 00001825 */   move  $v1, $zero
/* 08BC08 7F0570D8 8C43000C */  lw    $v1, 0xc($v0)
.L7F0570DC:
/* 08BC0C 7F0570DC 10600006 */  beqz  $v1, .L7F0570F8
/* 08BC10 7F0570E0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 08BC14 7F0570E4 8C6E0064 */  lw    $t6, 0x64($v1)
/* 08BC18 7F0570E8 31CF0010 */  andi  $t7, $t6, 0x10
/* 08BC1C 7F0570EC 55E00003 */  bnezl $t7, .L7F0570FC
/* 08BC20 7F0570F0 00601025 */   move  $v0, $v1
/* 08BC24 7F0570F4 00001825 */  move  $v1, $zero
.L7F0570F8:
/* 08BC28 7F0570F8 00601025 */  move  $v0, $v1
.L7F0570FC:
/* 08BC2C 7F0570FC 03E00008 */  jr    $ra
/* 08BC30 7F057100 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif






#ifdef NONMATCHING
u8 * get_ptr_text_for_watch_breifing_page(WATCH_BRIEFING_PAGE page)
{
    struct watchMenuObjectiveText * curentry;
    u8 * textptr;

    textptr = 0;
    for (curentry = ptr_last_briefing_setup_entry_type23; curentry != 0; curentry = curentry->nextentry)
    {
        if (page == curentry->menu)
        {
            textptr = get_textptr_for_textID(curentry->text);
        }
        textptr = 0;
    }
    if (textptr == 0)
    {
        if (page == 0)
        {
            textptr = get_textptr_for_textID(TEXT(LMISC, 0x29)); //"E R R O R\n"
        }
        else
        {
            if (page == 1)
            {
                textptr = get_textptr_for_textID(TEXT(LMISC, 0x2a)); //"no briefing for this mission\n"
            }
            else
            {
                textptr = get_textptr_for_textID(TEXT(LMISC, 0x2b)); //"\n"
            }
        }
    }
    return textptr;
}
#else
GLOBAL_ASM(
.text
glabel get_ptr_text_for_watch_breifing_page
/* 08BC34 7F057104 3C028007 */  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
/* 08BC38 7F057108 8C425D84 */  lw    $v0, %lo(ptr_last_briefing_setup_entry_type23)($v0)
/* 08BC3C 7F05710C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08BC40 7F057110 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08BC44 7F057114 00802825 */  move  $a1, $a0
/* 08BC48 7F057118 1040000D */  beqz  $v0, .L7F057150
/* 08BC4C 7F05711C 00001825 */   move  $v1, $zero
/* 08BC50 7F057120 8C4E0004 */  lw    $t6, 4($v0)
.L7F057124:
/* 08BC54 7F057124 54AE0008 */  bnel  $a1, $t6, .L7F057148
/* 08BC58 7F057128 8C42000C */   lw    $v0, 0xc($v0)
/* 08BC5C 7F05712C 9444000A */  lhu   $a0, 0xa($v0)
/* 08BC60 7F057130 0FC30776 */  jal   get_textptr_for_textID
/* 08BC64 7F057134 AFA50018 */   sw    $a1, 0x18($sp)
/* 08BC68 7F057138 8FA50018 */  lw    $a1, 0x18($sp)
/* 08BC6C 7F05713C 10000004 */  b     .L7F057150
/* 08BC70 7F057140 00401825 */   move  $v1, $v0
/* 08BC74 7F057144 8C42000C */  lw    $v0, 0xc($v0)
.L7F057148:
/* 08BC78 7F057148 5440FFF6 */  bnezl $v0, .L7F057124
/* 08BC7C 7F05714C 8C4E0004 */   lw    $t6, 4($v0)
.L7F057150:
/* 08BC80 7F057150 54600011 */  bnezl $v1, .L7F057198
/* 08BC84 7F057154 8FBF0014 */   lw    $ra, 0x14($sp)
/* 08BC88 7F057158 14A00005 */  bnez  $a1, .L7F057170
/* 08BC8C 7F05715C 24010001 */   li    $at, 1
/* 08BC90 7F057160 0FC30776 */  jal   get_textptr_for_textID
/* 08BC94 7F057164 3404B029 */   li    $a0, 45097
/* 08BC98 7F057168 1000000A */  b     .L7F057194
/* 08BC9C 7F05716C 00401825 */   move  $v1, $v0
.L7F057170:
/* 08BCA0 7F057170 14A10005 */  bne   $a1, $at, .L7F057188
/* 08BCA4 7F057174 00000000 */   nop   
/* 08BCA8 7F057178 0FC30776 */  jal   get_textptr_for_textID
/* 08BCAC 7F05717C 3404B02A */   li    $a0, 45098
/* 08BCB0 7F057180 10000004 */  b     .L7F057194
/* 08BCB4 7F057184 00401825 */   move  $v1, $v0
.L7F057188:
/* 08BCB8 7F057188 0FC30776 */  jal   get_textptr_for_textID
/* 08BCBC 7F05718C 3404B02B */   li    $a0, 45099
/* 08BCC0 7F057190 00401825 */  move  $v1, $v0
.L7F057194:
/* 08BCC4 7F057194 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F057198:
/* 08BCC8 7F057198 27BD0018 */  addiu $sp, $sp, 0x18
/* 08BCCC 7F05719C 00601025 */  move  $v0, $v1
/* 08BCD0 7F0571A0 03E00008 */  jr    $ra
/* 08BCD4 7F0571A4 00000000 */   nop   
)
#endif






s32 add_objective(void)
{
    return num_objective_ptrs[0]+1;
}



u8 * get_text_for_objective(int objective)
{
    u8 *textptr;
    
    if ((objective < 10) && (objective_ptrs[objective] != 0)) {
        return get_textptr_for_textID(objective_ptrs[objective]->text);
    }
    return 0;
}





#ifdef NONMATCHING
void get_difficulty_for_objective(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_difficulty_for_objective
/* 08BD34 7F057204 2881000A */  slti  $at, $a0, 0xa
/* 08BD38 7F057208 10200008 */  beqz  $at, .L7F05722C
/* 08BD3C 7F05720C 00047080 */   sll   $t6, $a0, 2
/* 08BD40 7F057210 3C038007 */  lui   $v1, %hi(objective_ptrs)
/* 08BD44 7F057214 006E1821 */  addu  $v1, $v1, $t6
/* 08BD48 7F057218 8C635D30 */  lw    $v1, %lo(objective_ptrs)($v1)
/* 08BD4C 7F05721C 50600004 */  beql  $v1, $zero, .L7F057230
/* 08BD50 7F057220 00001025 */   move  $v0, $zero
/* 08BD54 7F057224 03E00008 */  jr    $ra
/* 08BD58 7F057228 8062000F */   lb    $v0, 0xf($v1)

.L7F05722C:
/* 08BD5C 7F05722C 00001025 */  move  $v0, $zero
.L7F057230:
/* 08BD60 7F057230 03E00008 */  jr    $ra
/* 08BD64 7F057234 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_status_of_objective(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80053654*/
glabel jpt_objectives_microcode_handler
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_19_destroy_object
.word objective_microcode_type_1A_complete_if_true
.word objective_microcode_type_1B_fail_if_true
.word objective_microcode_type_1C_collect_object
.word objective_microcode_type_1D_deposit_object
.word objective_microcode_type_1E_photograph_object
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_20_enter_room
.word objective_microcode_type_21_deposit_object_in_room
.word objective_microcode_type_22_use_key_analyzer_on_object
.word 0,0,0

.text
glabel get_status_of_objective
/* 08BD68 7F057238 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08BD6C 7F05723C AFB30024 */  sw    $s3, 0x24($sp)
/* 08BD70 7F057240 2881000A */  slti  $at, $a0, 0xa
/* 08BD74 7F057244 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08BD78 7F057248 AFB40028 */  sw    $s4, 0x28($sp)
/* 08BD7C 7F05724C AFB20020 */  sw    $s2, 0x20($sp)
/* 08BD80 7F057250 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08BD84 7F057254 AFB00018 */  sw    $s0, 0x18($sp)
/* 08BD88 7F057258 1020008A */  beqz  $at, .L7F057484
/* 08BD8C 7F05725C 24130001 */   li    $s3, 1
/* 08BD90 7F057260 00041080 */  sll   $v0, $a0, 2
/* 08BD94 7F057264 3C048007 */  lui   $a0, %hi(objective_ptrs)
/* 08BD98 7F057268 00822021 */  addu  $a0, $a0, $v0
/* 08BD9C 7F05726C 8C845D30 */  lw    $a0, %lo(objective_ptrs)($a0)
/* 08BDA0 7F057270 54800006 */  bnezl $a0, .L7F05728C
/* 08BDA4 7F057274 90830003 */   lbu   $v1, 3($a0)
/* 08BDA8 7F057278 3C138007 */  lui   $s3, %hi(dword_CODE_bss_80075D58)
/* 08BDAC 7F05727C 02629821 */  addu  $s3, $s3, $v0
/* 08BDB0 7F057280 10000080 */  b     .L7F057484
/* 08BDB4 7F057284 8E735D58 */   lw    $s3, %lo(dword_CODE_bss_80075D58)($s3)
/* 08BDB8 7F057288 90830003 */  lbu   $v1, 3($a0)
.L7F05728C:
/* 08BDBC 7F05728C 24010018 */  li    $at, 24
/* 08BDC0 7F057290 00809025 */  move  $s2, $a0
/* 08BDC4 7F057294 1061007B */  beq   $v1, $at, .L7F057484
/* 08BDC8 7F057298 24140001 */   li    $s4, 1
/* 08BDCC 7F05729C 246EFFE9 */  addiu $t6, $v1, -0x17
.L7F0572A0:
/* 08BDD0 7F0572A0 2DC1000C */  sltiu $at, $t6, 0xc
/* 08BDD4 7F0572A4 10200064 */  beqz  $at, .L7F057438
/* 08BDD8 7F0572A8 02808825 */   move  $s1, $s4
/* 08BDDC 7F0572AC 000E7080 */  sll   $t6, $t6, 2
/* 08BDE0 7F0572B0 3C018005 */  lui   $at, %hi(jpt_objectives_microcode_handler)
/* 08BDE4 7F0572B4 002E0821 */  addu  $at, $at, $t6
/* 08BDE8 7F0572B8 8C2E3654 */  lw    $t6, %lo(jpt_objectives_microcode_handler)($at)
/* 08BDEC 7F0572BC 01C00008 */  jr    $t6
/* 08BDF0 7F0572C0 00000000 */   nop   
objective_microcode_type_19_destroy_object:
/* 08BDF4 7F0572C4 0FC15C30 */  jal   get_handle_to_tagged_object
/* 08BDF8 7F0572C8 8E440004 */   lw    $a0, 4($s2)
/* 08BDFC 7F0572CC 1040005A */  beqz  $v0, .L7F057438
/* 08BE00 7F0572D0 00402025 */   move  $a0, $v0
/* 08BE04 7F0572D4 8C4F0010 */  lw    $t7, 0x10($v0)
/* 08BE08 7F0572D8 11E00057 */  beqz  $t7, .L7F057438
/* 08BE0C 7F0572DC 00000000 */   nop   
/* 08BE10 7F0572E0 0FC13BCD */  jal   check_if_object_has_not_been_destroyed
/* 08BE14 7F0572E4 00000000 */   nop   
/* 08BE18 7F0572E8 10400053 */  beqz  $v0, .L7F057438
/* 08BE1C 7F0572EC 00000000 */   nop   
/* 08BE20 7F0572F0 10000051 */  b     .L7F057438
/* 08BE24 7F0572F4 00008825 */   move  $s1, $zero
objective_microcode_type_1A_complete_if_true:
/* 08BE28 7F0572F8 00002025 */  move  $a0, $zero
/* 08BE2C 7F0572FC 0FC0CCCE */  jal   check_if_objective_bitflags_set
/* 08BE30 7F057300 8E450004 */   lw    $a1, 4($s2)
/* 08BE34 7F057304 1440004C */  bnez  $v0, .L7F057438
/* 08BE38 7F057308 00000000 */   nop   
/* 08BE3C 7F05730C 1000004A */  b     .L7F057438
/* 08BE40 7F057310 00008825 */   move  $s1, $zero
objective_microcode_type_1B_fail_if_true:
/* 08BE44 7F057314 00002025 */  move  $a0, $zero
/* 08BE48 7F057318 0FC0CCCE */  jal   check_if_objective_bitflags_set
/* 08BE4C 7F05731C 8E450004 */   lw    $a1, 4($s2)
/* 08BE50 7F057320 10400045 */  beqz  $v0, .L7F057438
/* 08BE54 7F057324 00000000 */   nop   
/* 08BE58 7F057328 10000043 */  b     .L7F057438
/* 08BE5C 7F05732C 24110002 */   li    $s1, 2
objective_microcode_type_1C_collect_object:
/* 08BE60 7F057330 0FC15C30 */  jal   get_handle_to_tagged_object
/* 08BE64 7F057334 8E440004 */   lw    $a0, 4($s2)
/* 08BE68 7F057338 10400008 */  beqz  $v0, .L7F05735C
/* 08BE6C 7F05733C 00408025 */   move  $s0, $v0
/* 08BE70 7F057340 8C580010 */  lw    $t8, 0x10($v0)
/* 08BE74 7F057344 13000005 */  beqz  $t8, .L7F05735C
/* 08BE78 7F057348 00000000 */   nop   
/* 08BE7C 7F05734C 0FC13BCD */  jal   check_if_object_has_not_been_destroyed
/* 08BE80 7F057350 00402025 */   move  $a0, $v0
/* 08BE84 7F057354 14400003 */  bnez  $v0, .L7F057364
/* 08BE88 7F057358 00000000 */   nop   
.L7F05735C:
/* 08BE8C 7F05735C 10000036 */  b     .L7F057438
/* 08BE90 7F057360 24110002 */   li    $s1, 2
.L7F057364:
/* 08BE94 7F057364 0FC233F8 */  jal   sub_GAME_7F08CFE0
/* 08BE98 7F057368 8E040010 */   lw    $a0, 0x10($s0)
/* 08BE9C 7F05736C 14400032 */  bnez  $v0, .L7F057438
/* 08BEA0 7F057370 00000000 */   nop   
/* 08BEA4 7F057374 10000030 */  b     .L7F057438
/* 08BEA8 7F057378 00008825 */   move  $s1, $zero
objective_microcode_type_1D_deposit_object:
/* 08BEAC 7F05737C 0FC15C30 */  jal   get_handle_to_tagged_object
/* 08BEB0 7F057380 8E440004 */   lw    $a0, 4($s2)
/* 08BEB4 7F057384 1040002C */  beqz  $v0, .L7F057438
/* 08BEB8 7F057388 00000000 */   nop   
/* 08BEBC 7F05738C 8C590010 */  lw    $t9, 0x10($v0)
/* 08BEC0 7F057390 13200029 */  beqz  $t9, .L7F057438
/* 08BEC4 7F057394 00000000 */   nop   
/* 08BEC8 7F057398 0FC233F8 */  jal   sub_GAME_7F08CFE0
/* 08BECC 7F05739C 03202025 */   move  $a0, $t9
/* 08BED0 7F0573A0 10400025 */  beqz  $v0, .L7F057438
/* 08BED4 7F0573A4 00000000 */   nop   
/* 08BED8 7F0573A8 10000023 */  b     .L7F057438
/* 08BEDC 7F0573AC 00008825 */   move  $s1, $zero
objective_microcode_type_1E_photograph_object:
/* 08BEE0 7F0573B0 0FC15C30 */  jal   get_handle_to_tagged_object
/* 08BEE4 7F0573B4 8E440004 */   lw    $a0, 4($s2)
/* 08BEE8 7F0573B8 8E480008 */  lw    $t0, 8($s2)
/* 08BEEC 7F0573BC 00402025 */  move  $a0, $v0
/* 08BEF0 7F0573C0 1500001D */  bnez  $t0, .L7F057438
/* 08BEF4 7F0573C4 00000000 */   nop   
/* 08BEF8 7F0573C8 10400008 */  beqz  $v0, .L7F0573EC
/* 08BEFC 7F0573CC 00000000 */   nop   
/* 08BF00 7F0573D0 8C490010 */  lw    $t1, 0x10($v0)
/* 08BF04 7F0573D4 11200005 */  beqz  $t1, .L7F0573EC
/* 08BF08 7F0573D8 00000000 */   nop   
/* 08BF0C 7F0573DC 0FC13BCD */  jal   check_if_object_has_not_been_destroyed
/* 08BF10 7F0573E0 00000000 */   nop   
/* 08BF14 7F0573E4 14400003 */  bnez  $v0, .L7F0573F4
/* 08BF18 7F0573E8 00000000 */   nop   
.L7F0573EC:
/* 08BF1C 7F0573EC 10000012 */  b     .L7F057438
/* 08BF20 7F0573F0 24110002 */   li    $s1, 2
.L7F0573F4:
/* 08BF24 7F0573F4 10000010 */  b     .L7F057438
/* 08BF28 7F0573F8 00008825 */   move  $s1, $zero
objective_microcode_type_20_enter_room:
/* 08BF2C 7F0573FC 8E4A0008 */  lw    $t2, 8($s2)
/* 08BF30 7F057400 1540000D */  bnez  $t2, .L7F057438
/* 08BF34 7F057404 00000000 */   nop   
/* 08BF38 7F057408 1000000B */  b     .L7F057438
/* 08BF3C 7F05740C 00008825 */   move  $s1, $zero
objective_microcode_type_21_deposit_object_in_room:
/* 08BF40 7F057410 8E4B000C */  lw    $t3, 0xc($s2)
/* 08BF44 7F057414 15600008 */  bnez  $t3, .L7F057438
/* 08BF48 7F057418 00000000 */   nop   
/* 08BF4C 7F05741C 10000006 */  b     .L7F057438
/* 08BF50 7F057420 00008825 */   move  $s1, $zero
objective_microcode_type_22_use_key_analyzer_on_object:
/* 08BF54 7F057424 0FC19BBE */  jal   get_keyanalyzer_flag
/* 08BF58 7F057428 00000000 */   nop   
/* 08BF5C 7F05742C 14400002 */  bnez  $v0, .L7F057438
/* 08BF60 7F057430 00000000 */   nop   
/* 08BF64 7F057434 00008825 */  move  $s1, $zero
objective_microcode_type_17_18_1F_default:
.L7F057438:
/* 08BF68 7F057438 16740005 */  bne   $s3, $s4, .L7F057450
/* 08BF6C 7F05743C 00000000 */   nop   
/* 08BF70 7F057440 12340008 */  beq   $s1, $s4, .L7F057464
/* 08BF74 7F057444 00000000 */   nop   
/* 08BF78 7F057448 10000006 */  b     .L7F057464
/* 08BF7C 7F05744C 02209825 */   move  $s3, $s1
.L7F057450:
/* 08BF80 7F057450 16600004 */  bnez  $s3, .L7F057464
/* 08BF84 7F057454 24010002 */   li    $at, 2
/* 08BF88 7F057458 16210002 */  bne   $s1, $at, .L7F057464
/* 08BF8C 7F05745C 00000000 */   nop   
/* 08BF90 7F057460 02209825 */  move  $s3, $s1
.L7F057464:
/* 08BF94 7F057464 0FC15A3D */  jal   get_size_of_setup_object_type
/* 08BF98 7F057468 02402025 */   move  $a0, $s2
/* 08BF9C 7F05746C 00026080 */  sll   $t4, $v0, 2
/* 08BFA0 7F057470 01929021 */  addu  $s2, $t4, $s2
/* 08BFA4 7F057474 92430003 */  lbu   $v1, 3($s2)
/* 08BFA8 7F057478 24010018 */  li    $at, 24
/* 08BFAC 7F05747C 5461FF88 */  bnel  $v1, $at, .L7F0572A0
/* 08BFB0 7F057480 246EFFE9 */   addiu $t6, $v1, -0x17
.L7F057484:
/* 08BFB4 7F057484 0FC2440C */  jal   get_debug_all_obj_complete_flag
/* 08BFB8 7F057488 00000000 */   nop   
/* 08BFBC 7F05748C 10400002 */  beqz  $v0, .L7F057498
/* 08BFC0 7F057490 8FB00018 */   lw    $s0, 0x18($sp)
/* 08BFC4 7F057494 24130001 */  li    $s3, 1
.L7F057498:
/* 08BFC8 7F057498 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08BFCC 7F05749C 02601025 */  move  $v0, $s3
/* 08BFD0 7F0574A0 8FB30024 */  lw    $s3, 0x24($sp)
/* 08BFD4 7F0574A4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08BFD8 7F0574A8 8FB20020 */  lw    $s2, 0x20($sp)
/* 08BFDC 7F0574AC 8FB40028 */  lw    $s4, 0x28($sp)
/* 08BFE0 7F0574B0 03E00008 */  jr    $ra
/* 08BFE4 7F0574B4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



u32 check_objectives_complete(void)
{
    DIFFICULTY objdiff;
    DIFFICULTY curdiff;
    int objective;
    
    for (objective = 0; objective < add_objective(); objective++)
    {
        objdiff = get_difficulty_for_objective(objective);
        curdiff = get_current_difficulty();
        if ((objdiff <= curdiff) && (get_status_of_objective(objective) != 1)) {
            return 0;
        }
    }
    return 1;
}


#ifdef VERSION_JP
void FUN_7f057a40(void)
{
  num_objective_ptrs[1] = 1;
  return;
}
#endif

#ifdef NONMATCHING
void display_objective_status_text_on_status_change(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.rdata
/*glabel D_80053610*/
/*.word 0,0,0,0,0,0,0,0,0,0*/
/*glabel D_80053640*/
/*.word 0*/
.text
glabel display_objective_status_text_on_status_change
/* 08C070 7F057540 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08C074 7F057544 AFB60030 */  sw    $s6, 0x30($sp)
/* 08C078 7F057548 AFB30024 */  sw    $s3, 0x24($sp)
/* 08C07C 7F05754C 3C0E8005 */  lui   $t6, %hi(D_80053610) 
/* 08C080 7F057550 27B30054 */  addiu $s3, $sp, 0x54
/* 08C084 7F057554 3C168003 */  lui   $s6, %hi(num_objective_ptrs)
/* 08C088 7F057558 AFB40028 */  sw    $s4, 0x28($sp)
/* 08C08C 7F05755C 25CE3610 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3610
/* 08C090 7F057560 26D622F0 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x22f0
/* 08C094 7F057564 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08C098 7F057568 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08C09C 7F05756C AFB70034 */  sw    $s7, 0x34($sp)
/* 08C0A0 7F057570 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08C0A4 7F057574 AFB20020 */  sw    $s2, 0x20($sp)
/* 08C0A8 7F057578 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08C0AC 7F05757C AFB00018 */  sw    $s0, 0x18($sp)
/* 08C0B0 7F057580 0000A025 */  move  $s4, $zero
/* 08C0B4 7F057584 25D90030 */  addiu $t9, $t6, 0x30
/* 08C0B8 7F057588 02604025 */  move  $t0, $s3
.L7F05758C:
/* 08C0BC 7F05758C 8DC10000 */  lw    $at, ($t6)
/* 08C0C0 7F057590 25CE000C */  addiu $t6, $t6, 0xc
/* 08C0C4 7F057594 2508000C */  addiu $t0, $t0, 0xc
/* 08C0C8 7F057598 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08C0CC 7F05759C 8DC1FFF8 */  lw    $at, -8($t6)
/* 08C0D0 7F0575A0 AD01FFF8 */  sw    $at, -8($t0)
/* 08C0D4 7F0575A4 8DC1FFFC */  lw    $at, -4($t6)
/* 08C0D8 7F0575A8 15D9FFF8 */  bne   $t6, $t9, .L7F05758C
/* 08C0DC 7F0575AC AD01FFFC */   sw    $at, -4($t0)
/* 08C0E0 7F0575B0 95C10000 */  lhu   $at, ($t6)
/* 08C0E4 7F0575B4 3C158007 */  lui   $s5, %hi(dword_CODE_bss_80075D58)
/* 08C0E8 7F0575B8 3C1E8005 */  lui   $fp, %hi(aSAC) 
/* 08C0EC 7F0575BC A5010000 */  sh    $at, ($t0)
/* 08C0F0 7F0575C0 8EC90000 */  lw    $t1, ($s6)
/* 08C0F4 7F0575C4 27DE3644 */  addiu $fp, %lo(aSAC) # addiu $fp, $fp, 0x3644
/* 08C0F8 7F0575C8 26B55D58 */  addiu $s5, %lo(dword_CODE_bss_80075D58) # addiu $s5, $s5, 0x5d58
/* 08C0FC 7F0575CC 05200051 */  bltz  $t1, .L7F057714
/* 08C100 7F0575D0 00009025 */   move  $s2, $zero
/* 08C104 7F0575D4 3C178005 */  lui   $s7, %hi(j_text_trigger) 
/* 08C108 7F0575D8 26F784D0 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b30
.L7F0575DC:
/* 08C10C 7F0575DC 0FC15C8E */  jal   get_status_of_objective
/* 08C110 7F0575E0 02402025 */   move  $a0, $s2
/* 08C114 7F0575E4 8EAA0000 */  lw    $t2, ($s5)
/* 08C118 7F0575E8 00408825 */  move  $s1, $v0
/* 08C11C 7F0575EC 02402025 */  move  $a0, $s2
/* 08C120 7F0575F0 104A003A */  beq   $v0, $t2, .L7F0576DC
/* 08C124 7F0575F4 00000000 */   nop   
/* 08C128 7F0575F8 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C12C 7F0575FC AEA20000 */   sw    $v0, ($s5)
/* 08C130 7F057600 0FC2FF04 */  jal   get_current_difficulty
/* 08C134 7F057604 00408025 */   move  $s0, $v0
/* 08C138 7F057608 0050082A */  slt   $at, $v0, $s0
/* 08C13C 7F05760C 14200033 */  bnez  $at, .L7F0576DC
/* 08C140 7F057610 00000000 */   nop   
/* 08C144 7F057614 8EEB0000 */  lw    $t3, ($s7)
/* 08C148 7F057618 2690001A */  addiu $s0, $s4, 0x1a
/* 08C14C 7F05761C 3404B02C */  li    $a0, 45100
/* 08C150 7F057620 1160000A */  beqz  $t3, .L7F05764C
/* 08C154 7F057624 00000000 */   nop   
/* 08C158 7F057628 0FC30776 */  jal   get_textptr_for_textID
/* 08C15C 7F05762C 3404B02C */   li    $a0, 45100
/* 08C160 7F057630 02602025 */  move  $a0, $s3
/* 08C164 7F057634 03C02825 */  move  $a1, $fp
/* 08C168 7F057638 00403025 */  move  $a2, $v0
/* 08C16C 7F05763C 0C002B25 */  jal   sprintf
/* 08C170 7F057640 02003825 */   move  $a3, $s0
/* 08C174 7F057644 1000000A */  b     .L7F057670
/* 08C178 7F057648 24010001 */   li    $at, 1
.L7F05764C:
/* 08C17C 7F05764C 0FC30776 */  jal   get_textptr_for_textID
/* 08C180 7F057650 26900061 */   addiu $s0, $s4, 0x61
/* 08C184 7F057654 3C058005 */  lui   $a1, %hi(aSC)
/* 08C188 7F057658 24A5364C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x364c
/* 08C18C 7F05765C 02602025 */  move  $a0, $s3
/* 08C190 7F057660 00403025 */  move  $a2, $v0
/* 08C194 7F057664 0C002B25 */  jal   sprintf
/* 08C198 7F057668 02003825 */   move  $a3, $s0
/* 08C19C 7F05766C 24010001 */  li    $at, 1
.L7F057670:
/* 08C1A0 7F057670 16210008 */  bne   $s1, $at, .L7F057694
/* 08C1A4 7F057674 00000000 */   nop   
/* 08C1A8 7F057678 0FC30776 */  jal   get_textptr_for_textID
/* 08C1AC 7F05767C 3404B02D */   li    $a0, 45101
/* 08C1B0 7F057680 02602025 */  move  $a0, $s3
/* 08C1B4 7F057684 0C0029FF */  jal   strcat
/* 08C1B8 7F057688 00402825 */   move  $a1, $v0
/* 08C1BC 7F05768C 10000011 */  b     .L7F0576D4
/* 08C1C0 7F057690 00000000 */   nop   
.L7F057694:
/* 08C1C4 7F057694 16200008 */  bnez  $s1, .L7F0576B8
/* 08C1C8 7F057698 24010002 */   li    $at, 2
/* 08C1CC 7F05769C 0FC30776 */  jal   get_textptr_for_textID
/* 08C1D0 7F0576A0 3404B02E */   li    $a0, 45102
/* 08C1D4 7F0576A4 02602025 */  move  $a0, $s3
/* 08C1D8 7F0576A8 0C0029FF */  jal   strcat
/* 08C1DC 7F0576AC 00402825 */   move  $a1, $v0
/* 08C1E0 7F0576B0 10000008 */  b     .L7F0576D4
/* 08C1E4 7F0576B4 00000000 */   nop   
.L7F0576B8:
/* 08C1E8 7F0576B8 16210006 */  bne   $s1, $at, .L7F0576D4
/* 08C1EC 7F0576BC 00000000 */   nop   
/* 08C1F0 7F0576C0 0FC30776 */  jal   get_textptr_for_textID
/* 08C1F4 7F0576C4 3404B02F */   li    $a0, 45103
/* 08C1F8 7F0576C8 02602025 */  move  $a0, $s3
/* 08C1FC 7F0576CC 0C0029FF */  jal   strcat
/* 08C200 7F0576D0 00402825 */   move  $a1, $v0
.L7F0576D4:
/* 08C204 7F0576D4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 08C208 7F0576D8 02602025 */   move  $a0, $s3
.L7F0576DC:
/* 08C20C 7F0576DC 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C210 7F0576E0 02402025 */   move  $a0, $s2
/* 08C214 7F0576E4 0FC2FF04 */  jal   get_current_difficulty
/* 08C218 7F0576E8 00408025 */   move  $s0, $v0
/* 08C21C 7F0576EC 0050082A */  slt   $at, $v0, $s0
/* 08C220 7F0576F0 54200003 */  bnezl $at, .L7F057700
/* 08C224 7F0576F4 8ECC0000 */   lw    $t4, ($s6)
/* 08C228 7F0576F8 26940001 */  addiu $s4, $s4, 1
/* 08C22C 7F0576FC 8ECC0000 */  lw    $t4, ($s6)
.L7F057700:
/* 08C230 7F057700 26520001 */  addiu $s2, $s2, 1
/* 08C234 7F057704 26B50004 */  addiu $s5, $s5, 4
/* 08C238 7F057708 0192082A */  slt   $at, $t4, $s2
/* 08C23C 7F05770C 1020FFB3 */  beqz  $at, .L7F0575DC
/* 08C240 7F057710 00000000 */   nop   
.L7F057714:
/* 08C244 7F057714 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08C248 7F057718 8FB00018 */  lw    $s0, 0x18($sp)
/* 08C24C 7F05771C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08C250 7F057720 8FB20020 */  lw    $s2, 0x20($sp)
/* 08C254 7F057724 8FB30024 */  lw    $s3, 0x24($sp)
/* 08C258 7F057728 8FB40028 */  lw    $s4, 0x28($sp)
/* 08C25C 7F05772C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08C260 7F057730 8FB60030 */  lw    $s6, 0x30($sp)
/* 08C264 7F057734 8FB70034 */  lw    $s7, 0x34($sp)
/* 08C268 7F057738 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08C26C 7F05773C 03E00008 */  jr    $ra
/* 08C270 7F057740 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel display_objective_status_text_on_status_change
/* 08C5C0 7F057A50 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08C5C4 7F057A54 AFB30024 */  sw    $s3, 0x24($sp)
/* 08C5C8 7F057A58 3C0E8005 */  lui   $t6, %hi(D_80053610) # $t6, 0x8005
/* 08C5CC 7F057A5C 27B30054 */  addiu $s3, $sp, 0x54
/* 08C5D0 7F057A60 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08C5D4 7F057A64 25CE3640 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3640
/* 08C5D8 7F057A68 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08C5DC 7F057A6C AFBE0038 */  sw    $fp, 0x38($sp)
/* 08C5E0 7F057A70 AFB70034 */  sw    $s7, 0x34($sp)
/* 08C5E4 7F057A74 AFB60030 */  sw    $s6, 0x30($sp)
/* 08C5E8 7F057A78 AFB40028 */  sw    $s4, 0x28($sp)
/* 08C5EC 7F057A7C AFB20020 */  sw    $s2, 0x20($sp)
/* 08C5F0 7F057A80 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08C5F4 7F057A84 AFB00018 */  sw    $s0, 0x18($sp)
/* 08C5F8 7F057A88 0000A825 */  move  $s5, $zero
/* 08C5FC 7F057A8C 25D90030 */  addiu $t9, $t6, 0x30
/* 08C600 7F057A90 02604025 */  move  $t0, $s3
.L7F057A94:
/* 08C604 7F057A94 8DC10000 */  lw    $at, ($t6)
/* 08C608 7F057A98 25CE000C */  addiu $t6, $t6, 0xc
/* 08C60C 7F057A9C 2508000C */  addiu $t0, $t0, 0xc
/* 08C610 7F057AA0 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08C614 7F057AA4 8DC1FFF8 */  lw    $at, -8($t6)
/* 08C618 7F057AA8 AD01FFF8 */  sw    $at, -8($t0)
/* 08C61C 7F057AAC 8DC1FFFC */  lw    $at, -4($t6)
/* 08C620 7F057AB0 15D9FFF8 */  bne   $t6, $t9, .L7F057A94
/* 08C624 7F057AB4 AD01FFFC */   sw    $at, -4($t0)
/* 08C628 7F057AB8 95C10000 */  lhu   $at, ($t6)
/* 08C62C 7F057ABC 3C098003 */  lui   $t1, %hi(num_objective_ptrs+4) # $t1, 0x8003
/* 08C630 7F057AC0 3C168003 */  lui   $s6, %hi(num_objective_ptrs) # $s6, 0x8003
/* 08C634 7F057AC4 A5010000 */  sh    $at, ($t0)
/* 08C638 7F057AC8 8D292334 */  lw    $t1, %lo(num_objective_ptrs+4)($t1)
/* 08C63C 7F057ACC 26D62330 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x2330
/* 08C640 7F057AD0 55200058 */  bnezl $t1, .L7F057C34
/* 08C644 7F057AD4 8FBF003C */   lw    $ra, 0x3c($sp)
/* 08C648 7F057AD8 8ECA0000 */  lw    $t2, ($s6)
/* 08C64C 7F057ADC 3C148007 */  lui   $s4, %hi(dword_CODE_bss_80075D58) # $s4, 0x8007
/* 08C650 7F057AE0 26945D98 */  addiu $s4, %lo(dword_CODE_bss_80075D58) # addiu $s4, $s4, 0x5d98
/* 08C654 7F057AE4 05400052 */  bltz  $t2, .L7F057C30
/* 08C658 7F057AE8 00009025 */   move  $s2, $zero
/* 08C65C 7F057AEC 3C178005 */  lui   $s7, %hi(j_text_trigger) # $s7, 0x8005
/* 08C660 7F057AF0 26F78500 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b00
/* 08C664 7F057AF4 241E0001 */  li    $fp, 1
.L7F057AF8:
/* 08C668 7F057AF8 0FC15DCE */  jal   get_status_of_objective
/* 08C66C 7F057AFC 02402025 */   move  $a0, $s2
/* 08C670 7F057B00 8E8B0000 */  lw    $t3, ($s4)
/* 08C674 7F057B04 00408825 */  move  $s1, $v0
/* 08C678 7F057B08 02402025 */  move  $a0, $s2
/* 08C67C 7F057B0C 104B003A */  beq   $v0, $t3, .L7F057BF8
/* 08C680 7F057B10 00000000 */   nop   
/* 08C684 7F057B14 0FC15DC1 */  jal   get_difficulty_for_objective
/* 08C688 7F057B18 AE820000 */   sw    $v0, ($s4)
/* 08C68C 7F057B1C 0FC3021E */  jal   get_current_difficulty
/* 08C690 7F057B20 00408025 */   move  $s0, $v0
/* 08C694 7F057B24 0050082A */  slt   $at, $v0, $s0
/* 08C698 7F057B28 14200033 */  bnez  $at, .L7F057BF8
/* 08C69C 7F057B2C 00000000 */   nop   
/* 08C6A0 7F057B30 8EEC0000 */  lw    $t4, ($s7)
/* 08C6A4 7F057B34 26B0001A */  addiu $s0, $s5, 0x1a
/* 08C6A8 7F057B38 3404B02C */  li    $a0, 45100
/* 08C6AC 7F057B3C 1180000B */  beqz  $t4, .L7F057B6C
/* 08C6B0 7F057B40 00000000 */   nop   
/* 08C6B4 7F057B44 0FC30AA2 */  jal   get_textptr_for_textID
/* 08C6B8 7F057B48 3404B02C */   li    $a0, 45100
/* 08C6BC 7F057B4C 3C058005 */  lui   $a1, %hi(aSAC) # $a1, 0x8005
/* 08C6C0 7F057B50 24A53674 */  addiu $a1, %lo(aSAC) # addiu $a1, $a1, 0x3674
/* 08C6C4 7F057B54 02602025 */  move  $a0, $s3
/* 08C6C8 7F057B58 00403025 */  move  $a2, $v0
/* 08C6CC 7F057B5C 0C002B29 */  jal   sprintf
/* 08C6D0 7F057B60 02003825 */   move  $a3, $s0
/* 08C6D4 7F057B64 10000009 */  b     .L7F057B8C
/* 08C6D8 7F057B68 00000000 */   nop   
.L7F057B6C:
/* 08C6DC 7F057B6C 0FC30AA2 */  jal   get_textptr_for_textID
/* 08C6E0 7F057B70 26B00061 */   addiu $s0, $s5, 0x61
/* 08C6E4 7F057B74 3C058005 */  lui   $a1, %hi(aSC) # $a1, 0x8005
/* 08C6E8 7F057B78 24A5367C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x367c
/* 08C6EC 7F057B7C 02602025 */  move  $a0, $s3
/* 08C6F0 7F057B80 00403025 */  move  $a2, $v0
/* 08C6F4 7F057B84 0C002B29 */  jal   sprintf
/* 08C6F8 7F057B88 02003825 */   move  $a3, $s0
.L7F057B8C:
/* 08C6FC 7F057B8C 163E0008 */  bne   $s1, $fp, .L7F057BB0
/* 08C700 7F057B90 00000000 */   nop   
/* 08C704 7F057B94 0FC30AA2 */  jal   get_textptr_for_textID
/* 08C708 7F057B98 3404B02D */   li    $a0, 45101
/* 08C70C 7F057B9C 02602025 */  move  $a0, $s3
/* 08C710 7F057BA0 0C002A03 */  jal   strcat
/* 08C714 7F057BA4 00402825 */   move  $a1, $v0
/* 08C718 7F057BA8 10000011 */  b     .L7F057BF0
/* 08C71C 7F057BAC 00000000 */   nop   
.L7F057BB0:
/* 08C720 7F057BB0 16200008 */  bnez  $s1, .L7F057BD4
/* 08C724 7F057BB4 24010002 */   li    $at, 2
/* 08C728 7F057BB8 0FC30AA2 */  jal   get_textptr_for_textID
/* 08C72C 7F057BBC 3404B02E */   li    $a0, 45102
/* 08C730 7F057BC0 02602025 */  move  $a0, $s3
/* 08C734 7F057BC4 0C002A03 */  jal   strcat
/* 08C738 7F057BC8 00402825 */   move  $a1, $v0
/* 08C73C 7F057BCC 10000008 */  b     .L7F057BF0
/* 08C740 7F057BD0 00000000 */   nop   
.L7F057BD4:
/* 08C744 7F057BD4 16210006 */  bne   $s1, $at, .L7F057BF0
/* 08C748 7F057BD8 00000000 */   nop   
/* 08C74C 7F057BDC 0FC30AA2 */  jal   get_textptr_for_textID
/* 08C750 7F057BE0 3404B02F */   li    $a0, 45103
/* 08C754 7F057BE4 02602025 */  move  $a0, $s3
/* 08C758 7F057BE8 0C002A03 */  jal   strcat
/* 08C75C 7F057BEC 00402825 */   move  $a1, $v0
.L7F057BF0:
/* 08C760 7F057BF0 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 08C764 7F057BF4 02602025 */   move  $a0, $s3
.L7F057BF8:
/* 08C768 7F057BF8 0FC15DC1 */  jal   get_difficulty_for_objective
/* 08C76C 7F057BFC 02402025 */   move  $a0, $s2
/* 08C770 7F057C00 0FC3021E */  jal   get_current_difficulty
/* 08C774 7F057C04 00408025 */   move  $s0, $v0
/* 08C778 7F057C08 0050082A */  slt   $at, $v0, $s0
/* 08C77C 7F057C0C 54200003 */  bnezl $at, .L7F057C1C
/* 08C780 7F057C10 8ECD0000 */   lw    $t5, ($s6)
/* 08C784 7F057C14 26B50001 */  addiu $s5, $s5, 1
/* 08C788 7F057C18 8ECD0000 */  lw    $t5, ($s6)
.L7F057C1C:
/* 08C78C 7F057C1C 26520001 */  addiu $s2, $s2, 1
/* 08C790 7F057C20 26940004 */  addiu $s4, $s4, 4
/* 08C794 7F057C24 01B2082A */  slt   $at, $t5, $s2
/* 08C798 7F057C28 1020FFB3 */  beqz  $at, .L7F057AF8
/* 08C79C 7F057C2C 00000000 */   nop   
.L7F057C30:
/* 08C7A0 7F057C30 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F057C34:
/* 08C7A4 7F057C34 8FB00018 */  lw    $s0, 0x18($sp)
/* 08C7A8 7F057C38 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08C7AC 7F057C3C 8FB20020 */  lw    $s2, 0x20($sp)
/* 08C7B0 7F057C40 8FB30024 */  lw    $s3, 0x24($sp)
/* 08C7B4 7F057C44 8FB40028 */  lw    $s4, 0x28($sp)
/* 08C7B8 7F057C48 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08C7BC 7F057C4C 8FB60030 */  lw    $s6, 0x30($sp)
/* 08C7C0 7F057C50 8FB70034 */  lw    $s7, 0x34($sp)
/* 08C7C4 7F057C54 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08C7C8 7F057C58 03E00008 */  jr    $ra
/* 08C7CC 7F057C5C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.rdata
/*glabel D_80053610*/
/*.word 0,0,0,0,0,0,0,0,0,0*/
/*glabel D_80053640*/
/*.word 0*/
.text
glabel display_objective_status_text_on_status_change
/* 08C070 7F057540 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08C074 7F057544 AFB60030 */  sw    $s6, 0x30($sp)
/* 08C078 7F057548 AFB30024 */  sw    $s3, 0x24($sp)
/* 08C07C 7F05754C 3C0E8005 */  lui   $t6, %hi(D_80053610) 
/* 08C080 7F057550 27B30054 */  addiu $s3, $sp, 0x54
/* 08C084 7F057554 3C168003 */  lui   $s6, %hi(num_objective_ptrs)
/* 08C088 7F057558 AFB40028 */  sw    $s4, 0x28($sp)
/* 08C08C 7F05755C 25CE3610 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3610
/* 08C090 7F057560 26D622F0 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x22f0
/* 08C094 7F057564 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08C098 7F057568 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08C09C 7F05756C AFB70034 */  sw    $s7, 0x34($sp)
/* 08C0A0 7F057570 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08C0A4 7F057574 AFB20020 */  sw    $s2, 0x20($sp)
/* 08C0A8 7F057578 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08C0AC 7F05757C AFB00018 */  sw    $s0, 0x18($sp)
/* 08C0B0 7F057580 0000A025 */  move  $s4, $zero
/* 08C0B4 7F057584 25D90030 */  addiu $t9, $t6, 0x30
/* 08C0B8 7F057588 02604025 */  move  $t0, $s3
.L7F05758C:
/* 08C0BC 7F05758C 8DC10000 */  lw    $at, ($t6)
/* 08C0C0 7F057590 25CE000C */  addiu $t6, $t6, 0xc
/* 08C0C4 7F057594 2508000C */  addiu $t0, $t0, 0xc
/* 08C0C8 7F057598 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08C0CC 7F05759C 8DC1FFF8 */  lw    $at, -8($t6)
/* 08C0D0 7F0575A0 AD01FFF8 */  sw    $at, -8($t0)
/* 08C0D4 7F0575A4 8DC1FFFC */  lw    $at, -4($t6)
/* 08C0D8 7F0575A8 15D9FFF8 */  bne   $t6, $t9, .L7F05758C
/* 08C0DC 7F0575AC AD01FFFC */   sw    $at, -4($t0)
/* 08C0E0 7F0575B0 95C10000 */  lhu   $at, ($t6)
/* 08C0E4 7F0575B4 3C158007 */  lui   $s5, %hi(dword_CODE_bss_80075D58)
/* 08C0E8 7F0575B8 3C1E8005 */  lui   $fp, %hi(aSAC) 
/* 08C0EC 7F0575BC A5010000 */  sh    $at, ($t0)
/* 08C0F0 7F0575C0 8EC90000 */  lw    $t1, ($s6)
/* 08C0F4 7F0575C4 27DE3644 */  addiu $fp, %lo(aSAC) # addiu $fp, $fp, 0x3644
/* 08C0F8 7F0575C8 26B55D58 */  addiu $s5, %lo(dword_CODE_bss_80075D58) # addiu $s5, $s5, 0x5d58
/* 08C0FC 7F0575CC 05200051 */  bltz  $t1, .L7F057714
/* 08C100 7F0575D0 00009025 */   move  $s2, $zero
/* 08C104 7F0575D4 3C178005 */  lui   $s7, %hi(j_text_trigger) 
/* 08C108 7F0575D8 26F784D0 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b30
.L7F0575DC:
/* 08C10C 7F0575DC 0FC15C8E */  jal   get_status_of_objective
/* 08C110 7F0575E0 02402025 */   move  $a0, $s2
/* 08C114 7F0575E4 8EAA0000 */  lw    $t2, ($s5)
/* 08C118 7F0575E8 00408825 */  move  $s1, $v0
/* 08C11C 7F0575EC 02402025 */  move  $a0, $s2
/* 08C120 7F0575F0 104A003A */  beq   $v0, $t2, .L7F0576DC
/* 08C124 7F0575F4 00000000 */   nop   
/* 08C128 7F0575F8 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C12C 7F0575FC AEA20000 */   sw    $v0, ($s5)
/* 08C130 7F057600 0FC2FF04 */  jal   get_current_difficulty
/* 08C134 7F057604 00408025 */   move  $s0, $v0
/* 08C138 7F057608 0050082A */  slt   $at, $v0, $s0
/* 08C13C 7F05760C 14200033 */  bnez  $at, .L7F0576DC
/* 08C140 7F057610 00000000 */   nop   
/* 08C144 7F057614 8EEB0000 */  lw    $t3, ($s7)
/* 08C148 7F057618 2690001A */  addiu $s0, $s4, 0x1a
/* 08C14C 7F05761C 3404B02C */  li    $a0, 45100
/* 08C150 7F057620 1160000A */  beqz  $t3, .L7F05764C
/* 08C154 7F057624 00000000 */   nop   
/* 08C158 7F057628 0FC30776 */  jal   get_textptr_for_textID
/* 08C15C 7F05762C 3404B02C */   li    $a0, 45100
/* 08C160 7F057630 02602025 */  move  $a0, $s3
/* 08C164 7F057634 03C02825 */  move  $a1, $fp
/* 08C168 7F057638 00403025 */  move  $a2, $v0
/* 08C16C 7F05763C 0C002B25 */  jal   sprintf
/* 08C170 7F057640 02003825 */   move  $a3, $s0
/* 08C174 7F057644 1000000A */  b     .L7F057670
/* 08C178 7F057648 24010001 */   li    $at, 1
.L7F05764C:
/* 08C17C 7F05764C 0FC30776 */  jal   get_textptr_for_textID
/* 08C180 7F057650 26900061 */   addiu $s0, $s4, 0x61
/* 08C184 7F057654 3C058005 */  lui   $a1, %hi(aSC)
/* 08C188 7F057658 24A5364C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x364c
/* 08C18C 7F05765C 02602025 */  move  $a0, $s3
/* 08C190 7F057660 00403025 */  move  $a2, $v0
/* 08C194 7F057664 0C002B25 */  jal   sprintf
/* 08C198 7F057668 02003825 */   move  $a3, $s0
/* 08C19C 7F05766C 24010001 */  li    $at, 1
.L7F057670:
/* 08C1A0 7F057670 16210008 */  bne   $s1, $at, .L7F057694
/* 08C1A4 7F057674 00000000 */   nop   
/* 08C1A8 7F057678 0FC30776 */  jal   get_textptr_for_textID
/* 08C1AC 7F05767C 3404B02D */   li    $a0, 45101
/* 08C1B0 7F057680 02602025 */  move  $a0, $s3
/* 08C1B4 7F057684 0C0029FF */  jal   strcat
/* 08C1B8 7F057688 00402825 */   move  $a1, $v0
/* 08C1BC 7F05768C 10000011 */  b     .L7F0576D4
/* 08C1C0 7F057690 00000000 */   nop   
.L7F057694:
/* 08C1C4 7F057694 16200008 */  bnez  $s1, .L7F0576B8
/* 08C1C8 7F057698 24010002 */   li    $at, 2
/* 08C1CC 7F05769C 0FC30776 */  jal   get_textptr_for_textID
/* 08C1D0 7F0576A0 3404B02E */   li    $a0, 45102
/* 08C1D4 7F0576A4 02602025 */  move  $a0, $s3
/* 08C1D8 7F0576A8 0C0029FF */  jal   strcat
/* 08C1DC 7F0576AC 00402825 */   move  $a1, $v0
/* 08C1E0 7F0576B0 10000008 */  b     .L7F0576D4
/* 08C1E4 7F0576B4 00000000 */   nop   
.L7F0576B8:
/* 08C1E8 7F0576B8 16210006 */  bne   $s1, $at, .L7F0576D4
/* 08C1EC 7F0576BC 00000000 */   nop   
/* 08C1F0 7F0576C0 0FC30776 */  jal   get_textptr_for_textID
/* 08C1F4 7F0576C4 3404B02F */   li    $a0, 45103
/* 08C1F8 7F0576C8 02602025 */  move  $a0, $s3
/* 08C1FC 7F0576CC 0C0029FF */  jal   strcat
/* 08C200 7F0576D0 00402825 */   move  $a1, $v0
.L7F0576D4:
/* 08C204 7F0576D4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 08C208 7F0576D8 02602025 */   move  $a0, $s3
.L7F0576DC:
/* 08C20C 7F0576DC 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C210 7F0576E0 02402025 */   move  $a0, $s2
/* 08C214 7F0576E4 0FC2FF04 */  jal   get_current_difficulty
/* 08C218 7F0576E8 00408025 */   move  $s0, $v0
/* 08C21C 7F0576EC 0050082A */  slt   $at, $v0, $s0
/* 08C220 7F0576F0 54200003 */  bnezl $at, .L7F057700
/* 08C224 7F0576F4 8ECC0000 */   lw    $t4, ($s6)
/* 08C228 7F0576F8 26940001 */  addiu $s4, $s4, 1
/* 08C22C 7F0576FC 8ECC0000 */  lw    $t4, ($s6)
.L7F057700:
/* 08C230 7F057700 26520001 */  addiu $s2, $s2, 1
/* 08C234 7F057704 26B50004 */  addiu $s5, $s5, 4
/* 08C238 7F057708 0192082A */  slt   $at, $t4, $s2
/* 08C23C 7F05770C 1020FFB3 */  beqz  $at, .L7F0575DC
/* 08C240 7F057710 00000000 */   nop   
.L7F057714:
/* 08C244 7F057714 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08C248 7F057718 8FB00018 */  lw    $s0, 0x18($sp)
/* 08C24C 7F05771C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08C250 7F057720 8FB20020 */  lw    $s2, 0x20($sp)
/* 08C254 7F057724 8FB30024 */  lw    $s3, 0x24($sp)
/* 08C258 7F057728 8FB40028 */  lw    $s4, 0x28($sp)
/* 08C25C 7F05772C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08C260 7F057730 8FB60030 */  lw    $s6, 0x30($sp)
/* 08C264 7F057734 8FB70034 */  lw    $s7, 0x34($sp)
/* 08C268 7F057738 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08C26C 7F05773C 03E00008 */  jr    $ra
/* 08C270 7F057740 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F057744(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F057744
/* 08C274 7F057744 3C028007 */  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 08C278 7F057748 8C425D88 */  lw    $v0, %lo(ptr_last_enter_room_subobject_entry_type20)($v0)
/* 08C27C 7F05774C 3C0AFFF5 */  lui   $t2, (0xFFF59FC0 >> 16) # lui $t2, 0xfff5
/* 08C280 7F057750 00802825 */  move  $a1, $a0
/* 08C284 7F057754 10400022 */  beqz  $v0, .L7F0577E0
/* 08C288 7F057758 354A9FC0 */   ori   $t2, (0xFFF59FC0 & 0xFFFF) # ori $t2, $t2, 0x9fc0
/* 08C28C 7F05775C 3C078007 */  lui   $a3, %hi(ptr_setup_path_tbl)
/* 08C290 7F057760 24E75D00 */  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
/* 08C294 7F057764 24090044 */  li    $t1, 68
/* 08C298 7F057768 24080001 */  li    $t0, 1
/* 08C29C 7F05776C 2406002C */  li    $a2, 44
/* 08C2A0 7F057770 8C4E0008 */  lw    $t6, 8($v0)
.L7F057774:
/* 08C2A4 7F057774 55C00018 */  bnezl $t6, .L7F0577D8
/* 08C2A8 7F057778 8C42000C */   lw    $v0, 0xc($v0)
/* 08C2AC 7F05777C 8C430004 */  lw    $v1, 4($v0)
/* 08C2B0 7F057780 2C612710 */  sltiu $at, $v1, 0x2710
/* 08C2B4 7F057784 10200007 */  beqz  $at, .L7F0577A4
/* 08C2B8 7F057788 00000000 */   nop   
/* 08C2BC 7F05778C 00660019 */  multu $v1, $a2
/* 08C2C0 7F057790 8CF80018 */  lw    $t8, 0x18($a3)
/* 08C2C4 7F057794 00007812 */  mflo  $t7
/* 08C2C8 7F057798 01F82021 */  addu  $a0, $t7, $t8
/* 08C2CC 7F05779C 10000007 */  b     .L7F0577BC
/* 08C2D0 7F0577A0 8C830028 */   lw    $v1, 0x28($a0)
.L7F0577A4:
/* 08C2D4 7F0577A4 00690019 */  multu $v1, $t1
/* 08C2D8 7F0577A8 8CEB001C */  lw    $t3, 0x1c($a3)
/* 08C2DC 7F0577AC 0000C812 */  mflo  $t9
/* 08C2E0 7F0577B0 032B6021 */  addu  $t4, $t9, $t3
/* 08C2E4 7F0577B4 018A2021 */  addu  $a0, $t4, $t2
/* 08C2E8 7F0577B8 8C830028 */  lw    $v1, 0x28($a0)
.L7F0577BC:
/* 08C2EC 7F0577BC 50600006 */  beql  $v1, $zero, .L7F0577D8
/* 08C2F0 7F0577C0 8C42000C */   lw    $v0, 0xc($v0)
/* 08C2F4 7F0577C4 906D0003 */  lbu   $t5, 3($v1)
/* 08C2F8 7F0577C8 54AD0003 */  bnel  $a1, $t5, .L7F0577D8
/* 08C2FC 7F0577CC 8C42000C */   lw    $v0, 0xc($v0)
/* 08C300 7F0577D0 AC480008 */  sw    $t0, 8($v0)
/* 08C304 7F0577D4 8C42000C */  lw    $v0, 0xc($v0)
.L7F0577D8:
/* 08C308 7F0577D8 5440FFE6 */  bnezl $v0, .L7F057774
/* 08C30C 7F0577DC 8C4E0008 */   lw    $t6, 8($v0)
.L7F0577E0:
/* 08C310 7F0577E0 03E00008 */  jr    $ra
/* 08C314 7F0577E4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0577E8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0577E8
/* 08C318 7F0577E8 3C028007 */  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 08C31C 7F0577EC 8C425D8C */  lw    $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($v0)
/* 08C320 7F0577F0 3C0BFFF5 */  lui   $t3, (0xFFF59FC0 >> 16) # lui $t3, 0xfff5
/* 08C324 7F0577F4 00A03025 */  move  $a2, $a1
/* 08C328 7F0577F8 10400025 */  beqz  $v0, .L7F057890
/* 08C32C 7F0577FC 356B9FC0 */   ori   $t3, (0xFFF59FC0 & 0xFFFF) # ori $t3, $t3, 0x9fc0
/* 08C330 7F057800 3C088007 */  lui   $t0, %hi(ptr_setup_path_tbl) 
/* 08C334 7F057804 25085D00 */  addiu $t0, %lo(ptr_setup_path_tbl) # addiu $t0, $t0, 0x5d00
/* 08C338 7F057808 240A0044 */  li    $t2, 68
/* 08C33C 7F05780C 24090001 */  li    $t1, 1
/* 08C340 7F057810 2407002C */  li    $a3, 44
/* 08C344 7F057814 8C4E000C */  lw    $t6, 0xc($v0)
.L7F057818:
/* 08C348 7F057818 55C0001B */  bnezl $t6, .L7F057888
/* 08C34C 7F05781C 8C420010 */   lw    $v0, 0x10($v0)
/* 08C350 7F057820 8C4F0004 */  lw    $t7, 4($v0)
/* 08C354 7F057824 548F0018 */  bnel  $a0, $t7, .L7F057888
/* 08C358 7F057828 8C420010 */   lw    $v0, 0x10($v0)
/* 08C35C 7F05782C 8C430008 */  lw    $v1, 8($v0)
/* 08C360 7F057830 2C612710 */  sltiu $at, $v1, 0x2710
/* 08C364 7F057834 10200007 */  beqz  $at, .L7F057854
/* 08C368 7F057838 00000000 */   nop   
/* 08C36C 7F05783C 00670019 */  multu $v1, $a3
/* 08C370 7F057840 8D190018 */  lw    $t9, 0x18($t0)
/* 08C374 7F057844 0000C012 */  mflo  $t8
/* 08C378 7F057848 03192821 */  addu  $a1, $t8, $t9
/* 08C37C 7F05784C 10000007 */  b     .L7F05786C
/* 08C380 7F057850 8CA30028 */   lw    $v1, 0x28($a1)
.L7F057854:
/* 08C384 7F057854 006A0019 */  multu $v1, $t2
/* 08C388 7F057858 8D0D001C */  lw    $t5, 0x1c($t0)
/* 08C38C 7F05785C 00006012 */  mflo  $t4
/* 08C390 7F057860 018D7021 */  addu  $t6, $t4, $t5
/* 08C394 7F057864 01CB2821 */  addu  $a1, $t6, $t3
/* 08C398 7F057868 8CA30028 */  lw    $v1, 0x28($a1)
.L7F05786C:
/* 08C39C 7F05786C 50600006 */  beql  $v1, $zero, .L7F057888
/* 08C3A0 7F057870 8C420010 */   lw    $v0, 0x10($v0)
/* 08C3A4 7F057874 906F0003 */  lbu   $t7, 3($v1)
/* 08C3A8 7F057878 54CF0003 */  bnel  $a2, $t7, .L7F057888
/* 08C3AC 7F05787C 8C420010 */   lw    $v0, 0x10($v0)
/* 08C3B0 7F057880 AC49000C */  sw    $t1, 0xc($v0)
/* 08C3B4 7F057884 8C420010 */  lw    $v0, 0x10($v0)
.L7F057888:
/* 08C3B8 7F057888 5440FFE3 */  bnezl $v0, .L7F057818
/* 08C3BC 7F05788C 8C4E000C */   lw    $t6, 0xc($v0)
.L7F057890:
/* 08C3C0 7F057890 03E00008 */  jr    $ra
/* 08C3C4 7F057894 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F057898(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F057898
/* 08C3C8 7F057898 27BDFF68 */  addiu $sp, $sp, -0x98
/* 08C3CC 7F05789C AFB10034 */  sw    $s1, 0x34($sp)
/* 08C3D0 7F0578A0 3C118007 */  lui   $s1, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 08C3D4 7F0578A4 8E315D90 */  lw    $s1, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($s1)
/* 08C3D8 7F0578A8 AFBF004C */  sw    $ra, 0x4c($sp)
/* 08C3DC 7F0578AC AFB60048 */  sw    $s6, 0x48($sp)
/* 08C3E0 7F0578B0 AFB50044 */  sw    $s5, 0x44($sp)
/* 08C3E4 7F0578B4 AFB40040 */  sw    $s4, 0x40($sp)
/* 08C3E8 7F0578B8 AFB3003C */  sw    $s3, 0x3c($sp)
/* 08C3EC 7F0578BC AFB20038 */  sw    $s2, 0x38($sp)
/* 08C3F0 7F0578C0 AFB00030 */  sw    $s0, 0x30($sp)
/* 08C3F4 7F0578C4 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 08C3F8 7F0578C8 12200071 */  beqz  $s1, .L7F057A90
/* 08C3FC 7F0578CC F7B40020 */   sdc1  $f20, 0x20($sp)
/* 08C400 7F0578D0 4480B000 */  mtc1  $zero, $f22
/* 08C404 7F0578D4 24160001 */  li    $s6, 1
/* 08C408 7F0578D8 27B50064 */  addiu $s5, $sp, 0x64
/* 08C40C 7F0578DC 27B40074 */  addiu $s4, $sp, 0x74
/* 08C410 7F0578E0 27B3007C */  addiu $s3, $sp, 0x7c
/* 08C414 7F0578E4 27B20084 */  addiu $s2, $sp, 0x84
/* 08C418 7F0578E8 8E2E0008 */  lw    $t6, 8($s1)
.L7F0578EC:
/* 08C41C 7F0578EC 55C00066 */  bnezl $t6, .L7F057A88
/* 08C420 7F0578F0 8E31000C */   lw    $s1, 0xc($s1)
/* 08C424 7F0578F4 0FC15C30 */  jal   get_handle_to_tagged_object
/* 08C428 7F0578F8 8E240004 */   lw    $a0, 4($s1)
/* 08C42C 7F0578FC 10400061 */  beqz  $v0, .L7F057A84
/* 08C430 7F057900 00408025 */   move  $s0, $v0
/* 08C434 7F057904 8C430010 */  lw    $v1, 0x10($v0)
/* 08C438 7F057908 5060005F */  beql  $v1, $zero, .L7F057A88
/* 08C43C 7F05790C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C440 7F057910 906F0001 */  lbu   $t7, 1($v1)
/* 08C444 7F057914 31F80002 */  andi  $t8, $t7, 2
/* 08C448 7F057918 5300005B */  beql  $t8, $zero, .L7F057A88
/* 08C44C 7F05791C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C450 7F057920 C4640018 */  lwc1  $f4, 0x18($v1)
/* 08C454 7F057924 4604B03E */  c.le.s $f22, $f4
/* 08C458 7F057928 00000000 */  nop   
/* 08C45C 7F05792C 45020056 */  bc1fl .L7F057A88
/* 08C460 7F057930 8E31000C */   lw    $s1, 0xc($s1)
/* 08C464 7F057934 0FC13BCD */  jal   check_if_object_has_not_been_destroyed
/* 08C468 7F057938 00402025 */   move  $a0, $v0
/* 08C46C 7F05793C 10400051 */  beqz  $v0, .L7F057A84
/* 08C470 7F057940 02402825 */   move  $a1, $s2
/* 08C474 7F057944 8E040010 */  lw    $a0, 0x10($s0)
/* 08C478 7F057948 02603025 */  move  $a2, $s3
/* 08C47C 7F05794C 0FC1434C */  jal   sub_GAME_7F050D30
/* 08C480 7F057950 02803825 */   move  $a3, $s4
/* 08C484 7F057954 1040004B */  beqz  $v0, .L7F057A84
/* 08C488 7F057958 02402025 */   move  $a0, $s2
/* 08C48C 7F05795C 02602825 */  move  $a1, $s3
/* 08C490 7F057960 02803025 */  move  $a2, $s4
/* 08C494 7F057964 27A7006C */  addiu $a3, $sp, 0x6c
/* 08C498 7F057968 0FC0FE52 */  jal   sub_GAME_7F03F948
/* 08C49C 7F05796C AFB50010 */   sw    $s5, 0x10($sp)
/* 08C4A0 7F057970 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4A4 7F057974 00000000 */   nop   
/* 08C4A8 7F057978 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08C4AC 7F05797C 4606003C */  c.lt.s $f0, $f6
/* 08C4B0 7F057980 00000000 */  nop   
/* 08C4B4 7F057984 45020040 */  bc1fl .L7F057A88
/* 08C4B8 7F057988 8E31000C */   lw    $s1, 0xc($s1)
/* 08C4BC 7F05798C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4C0 7F057990 00000000 */   nop   
/* 08C4C4 7F057994 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 08C4C8 7F057998 46000506 */   mov.s $f20, $f0
/* 08C4CC 7F05799C 46140280 */  add.s $f10, $f0, $f20
/* 08C4D0 7F0579A0 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08C4D4 7F0579A4 460A403C */  c.lt.s $f8, $f10
/* 08C4D8 7F0579A8 00000000 */  nop   
/* 08C4DC 7F0579AC 45020036 */  bc1fl .L7F057A88
/* 08C4E0 7F0579B0 8E31000C */   lw    $s1, 0xc($s1)
/* 08C4E4 7F0579B4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4E8 7F0579B8 00000000 */   nop   
/* 08C4EC 7F0579BC C7B00064 */  lwc1  $f16, 0x64($sp)
/* 08C4F0 7F0579C0 4610003C */  c.lt.s $f0, $f16
/* 08C4F4 7F0579C4 00000000 */  nop   
/* 08C4F8 7F0579C8 4502002F */  bc1fl .L7F057A88
/* 08C4FC 7F0579CC 8E31000C */   lw    $s1, 0xc($s1)
/* 08C500 7F0579D0 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C504 7F0579D4 00000000 */   nop   
/* 08C508 7F0579D8 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 08C50C 7F0579DC 46000506 */   mov.s $f20, $f0
/* 08C510 7F0579E0 46140100 */  add.s $f4, $f0, $f20
/* 08C514 7F0579E4 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 08C518 7F0579E8 4604903C */  c.lt.s $f18, $f4
/* 08C51C 7F0579EC 00000000 */  nop   
/* 08C520 7F0579F0 45020025 */  bc1fl .L7F057A88
/* 08C524 7F0579F4 8E31000C */   lw    $s1, 0xc($s1)
/* 08C528 7F0579F8 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C52C 7F0579FC 00000000 */   nop   
/* 08C530 7F057A00 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08C534 7F057A04 4606003C */  c.lt.s $f0, $f6
/* 08C538 7F057A08 00000000 */  nop   
/* 08C53C 7F057A0C 4502001E */  bc1fl .L7F057A88
/* 08C540 7F057A10 8E31000C */   lw    $s1, 0xc($s1)
/* 08C544 7F057A14 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C548 7F057A18 00000000 */   nop   
/* 08C54C 7F057A1C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 08C550 7F057A20 46000506 */   mov.s $f20, $f0
/* 08C554 7F057A24 46140280 */  add.s $f10, $f0, $f20
/* 08C558 7F057A28 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08C55C 7F057A2C 460A403C */  c.lt.s $f8, $f10
/* 08C560 7F057A30 00000000 */  nop   
/* 08C564 7F057A34 45020014 */  bc1fl .L7F057A88
/* 08C568 7F057A38 8E31000C */   lw    $s1, 0xc($s1)
/* 08C56C 7F057A3C 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C570 7F057A40 00000000 */   nop   
/* 08C574 7F057A44 C7B00068 */  lwc1  $f16, 0x68($sp)
/* 08C578 7F057A48 4610003C */  c.lt.s $f0, $f16
/* 08C57C 7F057A4C 00000000 */  nop   
/* 08C580 7F057A50 4502000D */  bc1fl .L7F057A88
/* 08C584 7F057A54 8E31000C */   lw    $s1, 0xc($s1)
/* 08C588 7F057A58 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C58C 7F057A5C 00000000 */   nop   
/* 08C590 7F057A60 0FC1E12D */  jal   getPlayer_c_screenheight
/* 08C594 7F057A64 46000506 */   mov.s $f20, $f0
/* 08C598 7F057A68 46140100 */  add.s $f4, $f0, $f20
/* 08C59C 7F057A6C C7B20068 */  lwc1  $f18, 0x68($sp)
/* 08C5A0 7F057A70 4604903C */  c.lt.s $f18, $f4
/* 08C5A4 7F057A74 00000000 */  nop   
/* 08C5A8 7F057A78 45020003 */  bc1fl .L7F057A88
/* 08C5AC 7F057A7C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C5B0 7F057A80 AE360008 */  sw    $s6, 8($s1)
.L7F057A84:
/* 08C5B4 7F057A84 8E31000C */  lw    $s1, 0xc($s1)
.L7F057A88:
/* 08C5B8 7F057A88 5620FF98 */  bnezl $s1, .L7F0578EC
/* 08C5BC 7F057A8C 8E2E0008 */   lw    $t6, 8($s1)
.L7F057A90:
/* 08C5C0 7F057A90 8FBF004C */  lw    $ra, 0x4c($sp)
/* 08C5C4 7F057A94 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 08C5C8 7F057A98 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 08C5CC 7F057A9C 8FB00030 */  lw    $s0, 0x30($sp)
/* 08C5D0 7F057AA0 8FB10034 */  lw    $s1, 0x34($sp)
/* 08C5D4 7F057AA4 8FB20038 */  lw    $s2, 0x38($sp)
/* 08C5D8 7F057AA8 8FB3003C */  lw    $s3, 0x3c($sp)
/* 08C5DC 7F057AAC 8FB40040 */  lw    $s4, 0x40($sp)
/* 08C5E0 7F057AB0 8FB50044 */  lw    $s5, 0x44($sp)
/* 08C5E4 7F057AB4 8FB60048 */  lw    $s6, 0x48($sp)
/* 08C5E8 7F057AB8 03E00008 */  jr    $ra
/* 08C5EC 7F057ABC 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif


//filebreak
