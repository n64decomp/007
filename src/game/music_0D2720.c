#include <ultra64.h>
#include "bondconstants.h"

struct music_setup
{
  s16 stage_id;
  s16 main_music;
  s16 bg_sound;
  s16 xtrack;
};

// data
//D:8004EB10
struct music_setup music_setup_entries[] = {
    { LEVELID_BUNKER1,   M_BUNKER1,      0xFFFF,   M_BUNKER1X },
    { LEVELID_SILO,      M_SILO,         0xFFFF,   M_SILOX },
    { LEVELID_STATUE,    M_STATUE,       0xFFFF,   M_STATUEPART },
    { LEVELID_CONTROL,   M_CONTROL,      0xFFFF,   M_ELEVATOR_CONTROL },
    { LEVELID_ARCHIVES,  M_ARCHIVES,     0xFFFF,   M_ARCHIVESX },
    { LEVELID_TRAIN,     M_TRAIN,        0xFFFF,   M_TRAINX },
    { LEVELID_FRIGATE,   M_FRIGATE,      0xFFFF,   M_END_SOMETHING },
    { LEVELID_BUNKER2,   M_BUNKER2,      0xFFFF,   M_BUNKER2X },
    { LEVELID_AZTEC,     M_AZTEC,        0xFFFF,   M_AZTECX },
    { LEVELID_STREETS,   M_STREETS,      0xFFFF,   M_STREETSX },
    { LEVELID_DEPOT,     M_DEPOT,        0xFFFF,   M_DEPOTX },
    { LEVELID_EGYPT,     M_EGYPTIAN,     0xFFFF,   M_EGYPTX },
    { LEVELID_DAM,       M_DAM,          0xFFFF,   M_WIND },
    { LEVELID_FACILITY,  M_FACILITY,     0xFFFF,   M_FACILITYX },
    { LEVELID_RUNWAY,    M_RUNWAY,       0xFFFF,   M_RUNWAYPLANE },
    { LEVELID_SURFACE,   M_SURFACE1,     0xFFFF,   M_WIND },
    { LEVELID_JUNGLE,    M_JUNGLE,       0xFFFF,   M_JUNGLEX },
    { LEVELID_CAVERNS,   M_WATERCAVERNS, 0xFFFF,   M_ELEVATOR_WC },
    { LEVELID_CITADEL,   M_CITADEL,      0xFFFF,   0xFFFF },
    { LEVELID_CRADLE,    M_CRADLE,       0xFFFF,   M_CRADLEX },
    { LEVELID_SHO,       M_SURFACE2,     0xFFFF,   0xFFFF },
    { LEVELID_SURFACE2,  M_SURFACE2,     M_WIND,   M_SURFACE2END },
    { LEVELID_CUBA,      M_CUBA,         0xFFFF,   0xFFFF },
    { 0 }
};

//D:8004EBD0
s16 random_tracks[] = {
    M_TRAIN,
    M_DEPOT,
    M_MPTHEME,
    M_CITADEL,
    M_FACILITY,
    M_CONTROL,
    M_DAM,
    M_FRIGATE,
    M_ARCHIVES,
    M_SILO,
    M_MPTHEME2,
    M_STREETS,
    M_BUNKER1,
    M_BUNKER2,
    M_STATUE,
    M_ELEVATOR_CONTROL,
    M_CRADLE,
    M_ELEVATOR_WC,
    M_EGYPTIAN,
    M_AZTEC,
    M_WATERCAVERNS,
    M_SURFACE2,
    M_TRAINX,
    M_FACILITYX,
    M_DEPOTX,
    M_CONTROLX,
    M_WATERCAVERNSX,
    M_DAMX,
    M_FRIGATEX,
    M_ARCHIVESX,
    M_SILOX,
    M_STREETSX,
    M_BUNKER1X,
    M_BUNKER2X,
    M_JUNGLEX,
    M_STATUEX,
    M_AZTECX,
    M_EGYPTX,
    M_CRADLEX,
    M_RUNWAY,
    M_MPTHEME3,
    M_RUNWAYX,
    M_SURFACE1,
    M_NONE
};



#ifdef NONMATCHING
void getmusictrack_or_randomtrack(void) {

}
#else
GLOBAL_ASM(
.text
glabel getmusictrack_or_randomtrack
/* 107250 7F0D2720 3C0E8005 */  lui   $t6, %hi(music_setup_entries) 
/* 107254 7F0D2724 85CEEB10 */  lh    $t6, %lo(music_setup_entries)($t6)
/* 107258 7F0D2728 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10725C 7F0D272C AFBF0014 */  sw    $ra, 0x14($sp)
/* 107260 7F0D2730 11C0002A */  beqz  $t6, .L7F0D27DC
/* 107264 7F0D2734 3C0A8005 */   lui   $t2, %hi(random_tracks) 
/* 107268 7F0D2738 3C0F8005 */  lui   $t7, %hi(music_setup_entries)
/* 10726C 7F0D273C 25E2EB10 */  addiu $v0, $t7, %lo(music_setup_entries)
/* 107270 7F0D2740 84430000 */  lh    $v1, ($v0)
.L7F0D2744:
/* 107274 7F0D2744 54830022 */  bnel  $a0, $v1, .L7F0D27D0
/* 107278 7F0D2748 84430008 */   lh    $v1, 8($v0)
/* 10727C 7F0D274C 84430002 */  lh    $v1, 2($v0)
/* 107280 7F0D2750 2401FFFF */  li    $at, -1
/* 107284 7F0D2754 3C188005 */  lui   $t8, %hi(random_tracks) 
/* 107288 7F0D2758 1461001A */  bne   $v1, $at, .L7F0D27C4
/* 10728C 7F0D275C 00000000 */   nop   
/* 107290 7F0D2760 8718EBD0 */  lh    $t8, %lo(random_tracks)($t8)
/* 107294 7F0D2764 3C028005 */  lui   $v0, %hi(random_tracks)
/* 107298 7F0D2768 00001825 */  move  $v1, $zero
/* 10729C 7F0D276C 13000006 */  beqz  $t8, .L7F0D2788
/* 1072A0 7F0D2770 2442EBD0 */   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
/* 1072A4 7F0D2774 84590002 */  lh    $t9, 2($v0)
.L7F0D2778:
/* 1072A8 7F0D2778 24630001 */  addiu $v1, $v1, 1
/* 1072AC 7F0D277C 24420002 */  addiu $v0, $v0, 2
/* 1072B0 7F0D2780 5720FFFD */  bnezl $t9, .L7F0D2778
/* 1072B4 7F0D2784 84590002 */   lh    $t9, 2($v0)
.L7F0D2788:
/* 1072B8 7F0D2788 0C002914 */  jal   randomGetNext
/* 1072BC 7F0D278C AFA30020 */   sw    $v1, 0x20($sp)
/* 1072C0 7F0D2790 8FA30020 */  lw    $v1, 0x20($sp)
/* 1072C4 7F0D2794 3C048005 */  lui   $a0, %hi(random_tracks)
/* 1072C8 7F0D2798 0043001B */  divu  $zero, $v0, $v1
/* 1072CC 7F0D279C 00004010 */  mfhi  $t0
/* 1072D0 7F0D27A0 00084840 */  sll   $t1, $t0, 1
/* 1072D4 7F0D27A4 00892021 */  addu  $a0, $a0, $t1
/* 1072D8 7F0D27A8 8484EBD0 */  lh    $a0, %lo(random_tracks)($a0)
/* 1072DC 7F0D27AC 14600002 */  bnez  $v1, .L7F0D27B8
/* 1072E0 7F0D27B0 00000000 */   nop   
/* 1072E4 7F0D27B4 0007000D */  break 7
.L7F0D27B8:
/* 1072E8 7F0D27B8 00801025 */  move  $v0, $a0
/* 1072EC 7F0D27BC 1000001F */  b     .L7F0D283C
/* 1072F0 7F0D27C0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0D27C4:
/* 1072F4 7F0D27C4 1000001C */  b     .L7F0D2838
/* 1072F8 7F0D27C8 00601025 */   move  $v0, $v1
/* 1072FC 7F0D27CC 84430008 */  lh    $v1, 8($v0)
.L7F0D27D0:
/* 107300 7F0D27D0 24420008 */  addiu $v0, $v0, 8
/* 107304 7F0D27D4 1460FFDB */  bnez  $v1, .L7F0D2744
/* 107308 7F0D27D8 00000000 */   nop   
.L7F0D27DC:
/* 10730C 7F0D27DC 854AEBD0 */  lh    $t2, %lo(random_tracks)($t2)
/* 107310 7F0D27E0 3C028005 */  lui   $v0, %hi(random_tracks)
/* 107314 7F0D27E4 00001825 */  move  $v1, $zero
/* 107318 7F0D27E8 11400006 */  beqz  $t2, .L7F0D2804
/* 10731C 7F0D27EC 2442EBD0 */   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
/* 107320 7F0D27F0 844B0002 */  lh    $t3, 2($v0)
.L7F0D27F4:
/* 107324 7F0D27F4 24630001 */  addiu $v1, $v1, 1
/* 107328 7F0D27F8 24420002 */  addiu $v0, $v0, 2
/* 10732C 7F0D27FC 5560FFFD */  bnezl $t3, .L7F0D27F4
/* 107330 7F0D2800 844B0002 */   lh    $t3, 2($v0)
.L7F0D2804:
/* 107334 7F0D2804 0C002914 */  jal   randomGetNext
/* 107338 7F0D2808 AFA30018 */   sw    $v1, 0x18($sp)
/* 10733C 7F0D280C 8FA30018 */  lw    $v1, 0x18($sp)
/* 107340 7F0D2810 3C048005 */  lui   $a0, %hi(random_tracks)
/* 107344 7F0D2814 0043001B */  divu  $zero, $v0, $v1
/* 107348 7F0D2818 00006010 */  mfhi  $t4
/* 10734C 7F0D281C 000C6840 */  sll   $t5, $t4, 1
/* 107350 7F0D2820 008D2021 */  addu  $a0, $a0, $t5
/* 107354 7F0D2824 8484EBD0 */  lh    $a0, %lo(random_tracks)($a0)
/* 107358 7F0D2828 14600002 */  bnez  $v1, .L7F0D2834
/* 10735C 7F0D282C 00000000 */   nop   
/* 107360 7F0D2830 0007000D */  break 7
.L7F0D2834:
/* 107364 7F0D2834 00801025 */  move  $v0, $a0
.L7F0D2838:
/* 107368 7F0D2838 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0D283C:
/* 10736C 7F0D283C 27BD0028 */  addiu $sp, $sp, 0x28
/* 107370 7F0D2840 03E00008 */  jr    $ra
/* 107374 7F0D2844 00000000 */   nop   
)
#endif





s32 musicGetBgTrackForStage(s32 stageID)
{
    s32 i;
    for (i=0; music_setup_entries[i].stage_id!=0; i++)
    {
        if (stageID == music_setup_entries[i].stage_id) 
        {
            return music_setup_entries[i].bg_sound;
        }
    }

    return -1;
}


s32 musicGetXTrackForStage(s32 stageID)
{
    s32 i;
    for (i=0; music_setup_entries[i].stage_id!=0; i++)
    {
        if (stageID == music_setup_entries[i].stage_id) 
        {
            return music_setup_entries[i].xtrack;
        }
    }

    return -1;
}