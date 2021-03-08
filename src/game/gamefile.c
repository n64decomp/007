#include "ultra64.h"
#include "game/gamefile.h"
#include "game/gamefile2.h"
#include "game/mainmenu.h"

/* EEPROM masks for in-game settings */
#define OPTION_INVERTLOOK    0x0001
#define OPTION_AUTOAIM       0x0002
#define OPTION_AIMCONTROL    0x0004
#define OPTION_SIGHTONSCREEN 0x0008
#define OPTION_LOOKAHEAD     0x0010
#define OPTION_DISPLAYAMMO   0x0020
#define OPTION_SCREENWIDE    0x0040
#define OPTION_SCREENRATIO   0x0080
#define OPTION_CONTROLTYPE   0x0700
#define OPTION_SCREENCINEMA  0x0800

#define DEFAULT_OPTIONS (OPTION_AUTOAIM | OPTION_SIGHTONSCREEN | OPTION_LOOKAHEAD | OPTION_DISPLAYAMMO)

// bss
//CODE.bss:80069920
struct save_data save1;
//CODE.bss:80069980
struct save_data save2;
//CODE.bss:800699E0
struct save_data save3;
//CODE.bss:80069A40
struct save_data save4;
//CODE.bss:80069AA0
struct save_data save5;
//CODE.bss:80069B00
struct save_data save6;

//CODE.bss:80069B60
u32 dword_CODE_bss_80069B60;


//data
//D:8002C510
u32 save_selected_bond[] = {0,0,0,0};

//D:8002C520
struct save_data D_8002C520 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C580
struct save_data D_8002C580 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C5E0
struct save_data D_8002C5E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C640
u32 D_8002C640 = 0x00000000;
u32 D_8002C644 = 0x00000000;
u32 flt_8002C648 = 0x42000000;
u32 dword_8002C64C = 0x00000000;
u32 dword_8002C650 = 0x00000000;
u32 dword_8002C654 = 0x00000000;
u32 dword_8002C658 = 0x00000000;
u32 dword_8002C65C = 0x00000000;




//D:8002C660
struct save_data D_8002C660 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};

//D:8002C6C0
struct save_data D_8002C6C0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C720
struct save_data D_8002C720 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C780
struct save_data D_8002C780 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C7E0
struct save_data D_8002C7E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C840
struct save_data D_8002C840 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C8A0
struct save_data blank_eeprom = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


f32 get_007_reaction_speed(void)
{
    if (get_current_difficulty() == DIFFICULTY_007) {
        return slider_007_mode_reaction;
    }
    return 0.f;
}

f32 get_007_health_mod(void)
{
    if (get_current_difficulty() == DIFFICULTY_007) {
        return slider_007_mode_health;
    }
    return 1.f;
}

f32 get_007_damage_mod(void)
{
    if (get_current_difficulty() == DIFFICULTY_007) {
        return slider_007_mode_accuracy;
    }
    return 1.f;
}

f32 get_007_accuracy_mod(void)
{
    if (get_current_difficulty() == DIFFICULTY_007) {
        return slider_007_mode_damage;
    }
    return 1.f;
}



#ifdef NONMATCHING
void end_of_mission_briefing(void)
{
    if (((-1 < briefingpage) && (selected_difficulty != DIFFICULTY_007)) && (append_cheat_sp == FALSE)) 
    {
        unlock_stage_in_folder_on_difficulty(selected_folder_num, mission_folder_setup_entries[briefingpage].mission_num, selected_difficulty, get_mission_timer() / 0x3c);

        if ((get_mission_timer() / 0x3c) <= (&solo_target_time_array[mission_folder_setup_entries[briefingpage].mission_num].agent_time)[selected_difficulty]) 
        {      
            if (check_if_cheat_unlocked(get_save_folder_ptr(selected_folder_num), mission_folder_setup_entries[briefingpage].mission_num) == 0)
            {
                sub_GAME_7F01E760(selected_folder_num, mission_folder_setup_entries[briefingpage].mission_num);
                newcheatunlocked = 1;
                return;
            }
        }
        newcheatunlocked = 0;
    }
    return;
}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel end_of_mission_briefing
/* 051ECC 7F01D39C 3C028003 */  lui   $v0, %hi(briefingpage)
/* 051ED0 7F01D3A0 8C42A8F8 */  lw    $v0, %lo(briefingpage)($v0)
/* 051ED4 7F01D3A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 051ED8 7F01D3A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 051EDC 7F01D3AC 04400050 */  bltz  $v0, .L7F01D4F0
/* 051EE0 7F01D3B0 3C038003 */   lui   $v1, %hi(selected_difficulty)
/* 051EE4 7F01D3B4 8C63A8FC */  lw    $v1, %lo(selected_difficulty)($v1)
/* 051EE8 7F01D3B8 24010003 */  li    $at, 3
/* 051EEC 7F01D3BC 3C0E8003 */  lui   $t6, %hi(append_cheat_sp) 
/* 051EF0 7F01D3C0 5061004C */  beql  $v1, $at, .L7F01D4F4
/* 051EF4 7F01D3C4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 051EF8 7F01D3C8 8DCEA900 */  lw    $t6, %lo(append_cheat_sp)($t6)
/* 051EFC 7F01D3CC 000278C0 */  sll   $t7, $v0, 3
/* 051F00 7F01D3D0 01E27823 */  subu  $t7, $t7, $v0
/* 051F04 7F01D3D4 15C00046 */  bnez  $t6, .L7F01D4F0
/* 051F08 7F01D3D8 000F7880 */   sll   $t7, $t7, 2
/* 051F0C 7F01D3DC 3C188003 */  lui   $t8, %hi(mission_folder_setup_entries+0x14)
/* 051F10 7F01D3E0 030FC021 */  addu  $t8, $t8, $t7
/* 051F14 7F01D3E4 8F18ABF8 */  lw    $t8, %lo(mission_folder_setup_entries+0x14)($t8)
/* 051F18 7F01D3E8 00034040 */  sll   $t0, $v1, 1
/* 051F1C 7F01D3EC 3C0A8003 */  lui   $t2, %hi(solo_target_time_array)
/* 051F20 7F01D3F0 0018C880 */  sll   $t9, $t8, 2
/* 051F24 7F01D3F4 0338C823 */  subu  $t9, $t9, $t8
/* 051F28 7F01D3F8 0019C840 */  sll   $t9, $t9, 1
/* 051F2C 7F01D3FC 03284821 */  addu  $t1, $t9, $t0
/* 051F30 7F01D400 01495021 */  addu  $t2, $t2, $t1
/* 051F34 7F01D404 854AB564 */  lh    $t2, %lo(solo_target_time_array)($t2)
/* 051F38 7F01D408 0FC22FEE */  jal   get_mission_timer
/* 051F3C 7F01D40C A7AA001E */   sh    $t2, 0x1e($sp)
/* 051F40 7F01D410 2401003C */  li    $at, 60
/* 051F44 7F01D414 0041001A */  div   $zero, $v0, $at
/* 051F48 7F01D418 3C0B8003 */  lui   $t3, %hi(briefingpage) 
/* 051F4C 7F01D41C 8D6BA8F8 */  lw    $t3, %lo(briefingpage)($t3)
/* 051F50 7F01D420 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051F54 7F01D424 00003812 */  mflo  $a3
/* 051F58 7F01D428 000B60C0 */  sll   $t4, $t3, 3
/* 051F5C 7F01D42C 018B6023 */  subu  $t4, $t4, $t3
/* 051F60 7F01D430 000C6080 */  sll   $t4, $t4, 2
/* 051F64 7F01D434 00AC2821 */  addu  $a1, $a1, $t4
/* 051F68 7F01D438 3C048003 */  lui   $a0, %hi(selected_folder_num)
/* 051F6C 7F01D43C 3C068003 */  lui   $a2, %hi(selected_difficulty)
/* 051F70 7F01D440 8CC6A8FC */  lw    $a2, %lo(selected_difficulty)($a2)
/* 051F74 7F01D444 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 051F78 7F01D448 0FC0797E */  jal   unlock_stage_in_folder_on_difficulty
/* 051F7C 7F01D44C 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 051F80 7F01D450 0FC22FEE */  jal   get_mission_timer
/* 051F84 7F01D454 00000000 */   nop   
/* 051F88 7F01D458 2401003C */  li    $at, 60
/* 051F8C 7F01D45C 0041001A */  div   $zero, $v0, $at
/* 051F90 7F01D460 87AD001E */  lh    $t5, 0x1e($sp)
/* 051F94 7F01D464 00007012 */  mflo  $t6
/* 051F98 7F01D468 3C048003 */  lui   $a0, %hi(selected_folder_num)
/* 051F9C 7F01D46C 01AE082A */  slt   $at, $t5, $t6
/* 051FA0 7F01D470 1420001D */  bnez  $at, .L7F01D4E8
/* 051FA4 7F01D474 00000000 */   nop   
/* 051FA8 7F01D478 0FC07771 */  jal   get_save_folder_ptr
/* 051FAC 7F01D47C 8C84A8E8 */   lw    $a0, %lo(selected_folder_num)($a0)
/* 051FB0 7F01D480 3C0F8003 */  lui   $t7, %hi(briefingpage) 
/* 051FB4 7F01D484 8DEFA8F8 */  lw    $t7, %lo(briefingpage)($t7)
/* 051FB8 7F01D488 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051FBC 7F01D48C 00402025 */  move  $a0, $v0
/* 051FC0 7F01D490 000FC0C0 */  sll   $t8, $t7, 3
/* 051FC4 7F01D494 030FC023 */  subu  $t8, $t8, $t7
/* 051FC8 7F01D498 0018C080 */  sll   $t8, $t8, 2
/* 051FCC 7F01D49C 00B82821 */  addu  $a1, $a1, $t8
/* 051FD0 7F01D4A0 0FC07748 */  jal   check_if_cheat_unlocked
/* 051FD4 7F01D4A4 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 051FD8 7F01D4A8 1440000F */  bnez  $v0, .L7F01D4E8
/* 051FDC 7F01D4AC 3C048003 */   lui   $a0, %hi(selected_folder_num)
/* 051FE0 7F01D4B0 3C198003 */  lui   $t9, %hi(briefingpage) 
/* 051FE4 7F01D4B4 8F39A8F8 */  lw    $t9, %lo(briefingpage)($t9)
/* 051FE8 7F01D4B8 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051FEC 7F01D4BC 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 051FF0 7F01D4C0 001940C0 */  sll   $t0, $t9, 3
/* 051FF4 7F01D4C4 01194023 */  subu  $t0, $t0, $t9
/* 051FF8 7F01D4C8 00084080 */  sll   $t0, $t0, 2
/* 051FFC 7F01D4CC 00A82821 */  addu  $a1, $a1, $t0
/* 052000 7F01D4D0 0FC079D8 */  jal   sub_GAME_7F01E760
/* 052004 7F01D4D4 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 052008 7F01D4D8 24090001 */  li    $t1, 1
/* 05200C 7F01D4DC 3C018007 */  lui   $at, %hi(newcheatunlocked)
/* 052010 7F01D4E0 10000003 */  b     .L7F01D4F0
/* 052014 7F01D4E4 AC299790 */   sw    $t1, %lo(newcheatunlocked)($at)
.L7F01D4E8:
/* 052018 7F01D4E8 3C018007 */  lui   $at, %hi(newcheatunlocked)
/* 05201C 7F01D4EC AC209790 */  sw    $zero, %lo(newcheatunlocked)($at)
.L7F01D4F0:
/* 052020 7F01D4F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01D4F4:
/* 052024 7F01D4F4 27BD0020 */  addiu $sp, $sp, 0x20
/* 052028 7F01D4F8 03E00008 */  jr    $ra
/* 05202C 7F01D4FC 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel end_of_mission_briefing
/* 0520BC 7F01D54C 3C028003 */  lui   $v0, %hi(briefingpage) # $v0, 0x8003
/* 0520C0 7F01D550 8C42A938 */  lw    $v0, %lo(briefingpage)($v0)
/* 0520C4 7F01D554 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0520C8 7F01D558 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0520CC 7F01D55C 0440004D */  bltz  $v0, .L7F01D694
/* 0520D0 7F01D560 3C038003 */   lui   $v1, %hi(selected_difficulty) # $v1, 0x8003
/* 0520D4 7F01D564 8C63A93C */  lw    $v1, %lo(selected_difficulty)($v1)
/* 0520D8 7F01D568 24010003 */  li    $at, 3
/* 0520DC 7F01D56C 3C0E8003 */  lui   $t6, %hi(append_cheat_sp) # $t6, 0x8003
/* 0520E0 7F01D570 50610049 */  beql  $v1, $at, .L7F01D698
/* 0520E4 7F01D574 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0520E8 7F01D578 8DCEA940 */  lw    $t6, %lo(append_cheat_sp)($t6)
/* 0520EC 7F01D57C 000278C0 */  sll   $t7, $v0, 3
/* 0520F0 7F01D580 01E27823 */  subu  $t7, $t7, $v0
/* 0520F4 7F01D584 15C00043 */  bnez  $t6, .L7F01D694
/* 0520F8 7F01D588 000F7880 */   sll   $t7, $t7, 2
/* 0520FC 7F01D58C 3C188003 */  lui   $t8, %hi(mission_folder_setup_entries+0x14)
/* 052100 7F01D590 030FC021 */  addu  $t8, $t8, $t7
/* 052104 7F01D594 8F18AC38 */  lw    $t8, %lo(mission_folder_setup_entries+0x14)($t8)
/* 052108 7F01D598 00034040 */  sll   $t0, $v1, 1
/* 05210C 7F01D59C 3C0A8003 */  lui   $t2, %hi(solo_target_time_array)
/* 052110 7F01D5A0 0018C880 */  sll   $t9, $t8, 2
/* 052114 7F01D5A4 0338C823 */  subu  $t9, $t9, $t8
/* 052118 7F01D5A8 0019C840 */  sll   $t9, $t9, 1
/* 05211C 7F01D5AC 03284821 */  addu  $t1, $t9, $t0
/* 052120 7F01D5B0 01495021 */  addu  $t2, $t2, $t1
/* 052124 7F01D5B4 854AB5A4 */  lh    $t2, %lo(solo_target_time_array)($t2)
/* 052128 7F01D5B8 0FC23210 */  jal   get_mission_timer
/* 05212C 7F01D5BC A7AA001E */   sh    $t2, 0x1e($sp)
/* 052130 7F01D5C0 2401003C */  li    $at, 60
/* 052134 7F01D5C4 0041001A */  div   $zero, $v0, $at
/* 052138 7F01D5C8 3C0B8003 */  lui   $t3, %hi(briefingpage) # $t3, 0x8003
/* 05213C 7F01D5CC 8D6BA938 */  lw    $t3, %lo(briefingpage)($t3)
/* 052140 7F01D5D0 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 052144 7F01D5D4 00003812 */  mflo  $a3
/* 052148 7F01D5D8 000B60C0 */  sll   $t4, $t3, 3
/* 05214C 7F01D5DC 018B6023 */  subu  $t4, $t4, $t3
/* 052150 7F01D5E0 000C6080 */  sll   $t4, $t4, 2
/* 052154 7F01D5E4 00AC2821 */  addu  $a1, $a1, $t4
/* 052158 7F01D5E8 3C048003 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 05215C 7F01D5EC 3C068003 */  lui   $a2, %hi(selected_difficulty) # $a2, 0x8003
/* 052160 7F01D5F0 8CC6A93C */  lw    $a2, %lo(selected_difficulty)($a2)
/* 052164 7F01D5F4 8C84A928 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 052168 7F01D5F8 0FC079EA */  jal   unlock_stage_in_folder_on_difficulty
/* 05216C 7F01D5FC 8CA5AC38 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 052170 7F01D600 0FC23210 */  jal   get_mission_timer
/* 052174 7F01D604 00000000 */   nop   
/* 052178 7F01D608 2401003C */  li    $at, 60
/* 05217C 7F01D60C 0041001A */  div   $zero, $v0, $at
/* 052180 7F01D610 87AD001E */  lh    $t5, 0x1e($sp)
/* 052184 7F01D614 00007012 */  mflo  $t6
/* 052188 7F01D618 3C048003 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 05218C 7F01D61C 01AE082A */  slt   $at, $t5, $t6
/* 052190 7F01D620 5420001D */  bnezl $at, .L7F01D698
/* 052194 7F01D624 8FBF0014 */   lw    $ra, 0x14($sp)
/* 052198 7F01D628 0FC077DD */  jal   get_save_folder_ptr
/* 05219C 7F01D62C 8C84A928 */   lw    $a0, %lo(selected_folder_num)($a0)
/* 0521A0 7F01D630 3C0F8003 */  lui   $t7, %hi(briefingpage) # $t7, 0x8003
/* 0521A4 7F01D634 8DEFA938 */  lw    $t7, %lo(briefingpage)($t7)
/* 0521A8 7F01D638 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 0521AC 7F01D63C 00402025 */  move  $a0, $v0
/* 0521B0 7F01D640 000FC0C0 */  sll   $t8, $t7, 3
/* 0521B4 7F01D644 030FC023 */  subu  $t8, $t8, $t7
/* 0521B8 7F01D648 0018C080 */  sll   $t8, $t8, 2
/* 0521BC 7F01D64C 00B82821 */  addu  $a1, $a1, $t8
/* 0521C0 7F01D650 0FC077B4 */  jal   check_if_cheat_unlocked
/* 0521C4 7F01D654 8CA5AC38 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 0521C8 7F01D658 1440000E */  bnez  $v0, .L7F01D694
/* 0521CC 7F01D65C 3C048003 */   lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 0521D0 7F01D660 3C198003 */  lui   $t9, %hi(briefingpage) # $t9, 0x8003
/* 0521D4 7F01D664 8F39A938 */  lw    $t9, %lo(briefingpage)($t9)
/* 0521D8 7F01D668 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 0521DC 7F01D66C 8C84A928 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0521E0 7F01D670 001940C0 */  sll   $t0, $t9, 3
/* 0521E4 7F01D674 01194023 */  subu  $t0, $t0, $t9
/* 0521E8 7F01D678 00084080 */  sll   $t0, $t0, 2
/* 0521EC 7F01D67C 00A82821 */  addu  $a1, $a1, $t0
/* 0521F0 7F01D680 0FC07A44 */  jal   sub_GAME_7F01E760
/* 0521F4 7F01D684 8CA5AC38 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 0521F8 7F01D688 24090001 */  li    $t1, 1
/* 0521FC 7F01D68C 3C018007 */  lui   $at, %hi(newcheatunlocked) # $at, 0x8007
/* 052200 7F01D690 AC2997D0 */  sw    $t1, %lo(newcheatunlocked)($at)
.L7F01D694:
/* 052204 7F01D694 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01D698:
/* 052208 7F01D698 27BD0020 */  addiu $sp, $sp, 0x20
/* 05220C 7F01D69C 03E00008 */  jr    $ra
/* 052210 7F01D6A0 00000000 */   nop    
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel end_of_mission_briefing
/* 051ECC 7F01D39C 3C028003 */  lui   $v0, %hi(briefingpage)
/* 051ED0 7F01D3A0 8C42A8F8 */  lw    $v0, %lo(briefingpage)($v0)
/* 051ED4 7F01D3A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 051ED8 7F01D3A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 051EDC 7F01D3AC 04400050 */  bltz  $v0, .L7F01D4F0
/* 051EE0 7F01D3B0 3C038003 */   lui   $v1, %hi(selected_difficulty)
/* 051EE4 7F01D3B4 8C63A8FC */  lw    $v1, %lo(selected_difficulty)($v1)
/* 051EE8 7F01D3B8 24010003 */  li    $at, 3
/* 051EEC 7F01D3BC 3C0E8003 */  lui   $t6, %hi(append_cheat_sp) 
/* 051EF0 7F01D3C0 5061004C */  beql  $v1, $at, .L7F01D4F4
/* 051EF4 7F01D3C4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 051EF8 7F01D3C8 8DCEA900 */  lw    $t6, %lo(append_cheat_sp)($t6)
/* 051EFC 7F01D3CC 000278C0 */  sll   $t7, $v0, 3
/* 051F00 7F01D3D0 01E27823 */  subu  $t7, $t7, $v0
/* 051F04 7F01D3D4 15C00046 */  bnez  $t6, .L7F01D4F0
/* 051F08 7F01D3D8 000F7880 */   sll   $t7, $t7, 2
/* 051F0C 7F01D3DC 3C188003 */  lui   $t8, %hi(mission_folder_setup_entries+0x14)
/* 051F10 7F01D3E0 030FC021 */  addu  $t8, $t8, $t7
/* 051F14 7F01D3E4 8F18ABF8 */  lw    $t8, %lo(mission_folder_setup_entries+0x14)($t8)
/* 051F18 7F01D3E8 00034040 */  sll   $t0, $v1, 1
/* 051F1C 7F01D3EC 3C0A8003 */  lui   $t2, %hi(solo_target_time_array)
/* 051F20 7F01D3F0 0018C880 */  sll   $t9, $t8, 2
/* 051F24 7F01D3F4 0338C823 */  subu  $t9, $t9, $t8
/* 051F28 7F01D3F8 0019C840 */  sll   $t9, $t9, 1
/* 051F2C 7F01D3FC 03284821 */  addu  $t1, $t9, $t0
/* 051F30 7F01D400 01495021 */  addu  $t2, $t2, $t1
/* 051F34 7F01D404 854AB564 */  lh    $t2, %lo(solo_target_time_array)($t2)
/* 051F38 7F01D408 0FC22FEE */  jal   get_mission_timer
/* 051F3C 7F01D40C A7AA001E */   sh    $t2, 0x1e($sp)
/* 051F40 7F01D410 2401003C */  li    $at, 60
/* 051F44 7F01D414 0041001A */  div   $zero, $v0, $at
/* 051F48 7F01D418 3C0B8003 */  lui   $t3, %hi(briefingpage) 
/* 051F4C 7F01D41C 8D6BA8F8 */  lw    $t3, %lo(briefingpage)($t3)
/* 051F50 7F01D420 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051F54 7F01D424 00003812 */  mflo  $a3
/* 051F58 7F01D428 000B60C0 */  sll   $t4, $t3, 3
/* 051F5C 7F01D42C 018B6023 */  subu  $t4, $t4, $t3
/* 051F60 7F01D430 000C6080 */  sll   $t4, $t4, 2
/* 051F64 7F01D434 00AC2821 */  addu  $a1, $a1, $t4
/* 051F68 7F01D438 3C048003 */  lui   $a0, %hi(selected_folder_num)
/* 051F6C 7F01D43C 3C068003 */  lui   $a2, %hi(selected_difficulty)
/* 051F70 7F01D440 8CC6A8FC */  lw    $a2, %lo(selected_difficulty)($a2)
/* 051F74 7F01D444 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 051F78 7F01D448 0FC0797E */  jal   unlock_stage_in_folder_on_difficulty
/* 051F7C 7F01D44C 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 051F80 7F01D450 0FC22FEE */  jal   get_mission_timer
/* 051F84 7F01D454 00000000 */   nop   
/* 051F88 7F01D458 2401003C */  li    $at, 60
/* 051F8C 7F01D45C 0041001A */  div   $zero, $v0, $at
/* 051F90 7F01D460 87AD001E */  lh    $t5, 0x1e($sp)
/* 051F94 7F01D464 00007012 */  mflo  $t6
/* 051F98 7F01D468 3C048003 */  lui   $a0, %hi(selected_folder_num)
/* 051F9C 7F01D46C 01AE082A */  slt   $at, $t5, $t6
/* 051FA0 7F01D470 1420001D */  bnez  $at, .L7F01D4E8
/* 051FA4 7F01D474 00000000 */   nop   
/* 051FA8 7F01D478 0FC07771 */  jal   get_save_folder_ptr
/* 051FAC 7F01D47C 8C84A8E8 */   lw    $a0, %lo(selected_folder_num)($a0)
/* 051FB0 7F01D480 3C0F8003 */  lui   $t7, %hi(briefingpage) 
/* 051FB4 7F01D484 8DEFA8F8 */  lw    $t7, %lo(briefingpage)($t7)
/* 051FB8 7F01D488 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051FBC 7F01D48C 00402025 */  move  $a0, $v0
/* 051FC0 7F01D490 000FC0C0 */  sll   $t8, $t7, 3
/* 051FC4 7F01D494 030FC023 */  subu  $t8, $t8, $t7
/* 051FC8 7F01D498 0018C080 */  sll   $t8, $t8, 2
/* 051FCC 7F01D49C 00B82821 */  addu  $a1, $a1, $t8
/* 051FD0 7F01D4A0 0FC07748 */  jal   check_if_cheat_unlocked
/* 051FD4 7F01D4A4 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 051FD8 7F01D4A8 1440000F */  bnez  $v0, .L7F01D4E8
/* 051FDC 7F01D4AC 3C048003 */   lui   $a0, %hi(selected_folder_num)
/* 051FE0 7F01D4B0 3C198003 */  lui   $t9, %hi(briefingpage) 
/* 051FE4 7F01D4B4 8F39A8F8 */  lw    $t9, %lo(briefingpage)($t9)
/* 051FE8 7F01D4B8 3C058003 */  lui   $a1, %hi(mission_folder_setup_entries+0x14)
/* 051FEC 7F01D4BC 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 051FF0 7F01D4C0 001940C0 */  sll   $t0, $t9, 3
/* 051FF4 7F01D4C4 01194023 */  subu  $t0, $t0, $t9
/* 051FF8 7F01D4C8 00084080 */  sll   $t0, $t0, 2
/* 051FFC 7F01D4CC 00A82821 */  addu  $a1, $a1, $t0
/* 052000 7F01D4D0 0FC079D8 */  jal   sub_GAME_7F01E760
/* 052004 7F01D4D4 8CA5ABF8 */   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
/* 052008 7F01D4D8 24090001 */  li    $t1, 1
/* 05200C 7F01D4DC 3C018007 */  lui   $at, %hi(newcheatunlocked)
/* 052010 7F01D4E0 10000003 */  b     .L7F01D4F0
/* 052014 7F01D4E4 AC299790 */   sw    $t1, %lo(newcheatunlocked)($at)
.L7F01D4E8:
/* 052018 7F01D4E8 3C018007 */  lui   $at, %hi(newcheatunlocked)
/* 05201C 7F01D4EC AC209790 */  sw    $zero, %lo(newcheatunlocked)($at)
.L7F01D4F0:
/* 052020 7F01D4F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01D4F4:
/* 052024 7F01D4F4 27BD0020 */  addiu $sp, $sp, 0x20
/* 052028 7F01D4F8 03E00008 */  jr    $ra
/* 05202C 7F01D4FC 00000000 */   nop   
)
#endif

#endif

void sub_GAME_7F01D500(void)
{
  get_screen_ratio_settings_for_mpgame_from_folder(selected_folder_num);
}

void deleteCurrentSelectedFolder(void)
{
  delete_update_eeprom_file(selected_folder_num);
}

void copyCurrentEEPROMtoStack(void)
{
  copy_eeprom_to_stack_set_folder_num(selected_folder_num);
}

u8 getSelectedFolderBond(void)
{
  return removed_would_have_returned_bond_for_folder_num(selected_folder_num);
}

void set_selected_folder_num(u32 foldernum)
{
  selected_folder_num = foldernum;
}

void set_selected_difficulty(DIFFICULTY difficulty)
{
    switch(difficulty)
    {
    case DIFFICULTY_AGENT:
    default:
        selected_difficulty = DIFFICULTY_AGENT;
        return;    
    case DIFFICULTY_SECRET:
        selected_difficulty = DIFFICULTY_SECRET;
        return;
    case DIFFICULTY_00:
        selected_difficulty = DIFFICULTY_00;
        return;
    case DIFFICULTY_007:
        selected_difficulty = DIFFICULTY_007;
        return;
    }
}

void set_solo_and_ptr_briefing(LEVELID stage)
{
    gamemode = GAMEMODE_SOLO;
    selected_stage = stage;
    briefingpage = pull_and_display_text_for_folder_a0(stage);
}

void sub_GAME_7F01D61C(struct save_file *savefile)
{
    copy_eeprom_from_to(selected_folder_num,savefile);
}



//this feels fake, generated with a permuter session i forgot was running
void sub_GAME_7F01D644(struct save_file *eeprom)
{
  int new_var;
  long long new_var2;
  new_var2 = (long long) 0x64;
  new_var = new_var2;
  selected_folder_num_copy = (s32) selected_folder_num;
  selected_folder_num = new_var;
  copy_eepromfile_a0_from_a1_to_buffer(new_var, eeprom);
}


void store_favorite_weapon_current_player(u32 right,u32 left)
{
  u32 playerNum;
  
  playerNum = get_cur_playernum();
  array_favweapon[playerNum][RIGHT_HAND] = right;
  array_favweapon[playerNum][LEFT_HAND] = left;
}