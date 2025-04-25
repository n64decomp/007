#include <ultra64.h>
#include "initpathtablelinks.h"
#include "padhalllv.h"


#ifdef NONMATCHING

/***
* Ryan spent a few minutes looking at this and left some notes about what this function does:
*
* var_s6 is an "error" variable. If set anywhere, the function goes into an infinite loop at the end.
* The first outer loop appears to be verifying that the waypoints don't list themselves as their own neighbour.
* The second outer loop appears to do the same but for waygroups. It also calls sub_GAME_7F08F438, which is a more simple version of PD's waypointFindSegmentIntoGroup, so it's likely verifying that there is a waypoint path between this group and each neighbour.
* The third outer loop is iterating waygroups, then iterating each group's waypoints, and assigning each waypoint's groupNum if it's less than 0. If a value is stored and it's wrong, the error variable is set.
* The fourth outer loop is checking that all waypoints have a groupNum assigned.
* The fifth outer loop I'm not sure about without actually decompiling it and naming stuff. It appears to be using the waypoint->dist property temporary so it can validate something. If it doesn't like it then the error variable is set.
* The final outer loop is the infinite loop which occurs if the error variable is true.
*/

/**
 * NTSC address 0x7F006890.
 * https://decomp.me/scratch/nSCDd 40.03%
*/
void init_path_table_links(void)
{    
    waypoint *spA0;
    waypoint *sp9C;
    
    s32 var_s6;
    waypoint *temp_s0;
    waygroup *spD8;
    
    waypoint *var_t5;
    s32 var_v0_2;
    s32 var_s3;
    s32 var_s1;
    s32 *temp_a2;
    s32 var_a1;
    s32 var_a3;
    s32 *temp_v0;
    s32 var_a0;
    s32 *temp_v1;
    s32 var_t1;
    s32 *var_v1_3;
    waypoint *temp_a1_2;
    s32 temp_a2_2;
    waygroup *var_t3;
    s32 *var_v0_4;
    s32 var_a3_2;
    waypoint *var_a2_2;
    s32 var_t4;
    s32 var_t0_2;
    s32 var_t1_2;
    s32 var_v0_5;
    s32 var_v1_4;
    s32 var_t1_3;
    waypoint *temp_a2_3;
    s32 var_v1_5;
    s32 var_v0_6;

    var_s6 = 0;

    temp_s0 = g_CurrentSetup.pathwaypoints;
    spD8 = g_CurrentSetup.waypointgroups;

    if (temp_s0 != NULL)
    {
        var_a3 = 0;
        
        var_t5 = temp_s0;
        while (var_t5->padID >= 0)
        {
            temp_v0 = var_t5->neighbours;

            while (*temp_v0 >= 0)
            {
                if (*temp_v0 == var_a3)
                {
                    var_s6 = 1;
                    if (g_CurrentSetup.padnames != NULL)
                    {
                        // removed
                    }
                }
                else
                {
                    var_a0 = 0;

                    temp_v1 = temp_s0[*temp_v0].neighbours;

                    while (*temp_v1 >= 0)
                    {
                        var_a0++;
                        
                        if (var_a3 != *temp_v1)
                        {
                            continue;
                        }

                        break;
                    }

                    if (var_a3 != temp_s0[*temp_v0].neighbours[var_a0])
                    {
                        var_s6 = 1;
                    }
                }

                temp_v0++;
            }
            
            var_a3++;
            var_t5 = &temp_s0[var_a3];
        }
    }

    if (spD8 != NULL)
    {
        var_s1 = 0;
        
        var_s3 = 0;
        var_v0_2 = spD8->neighbours[var_s3];
        
        while (var_v0_2 >= 0)
        {
            if (var_v0_2 == var_s1)
            {
                var_s6 = 1;
                if (g_CurrentSetup.boundpadnames != NULL)
                {
                    // removed
                }
            }
            else
            {
                var_a1 = 0;
                temp_a2 = &spD8->neighbours[var_v0_2];

                while (*temp_a2 >= 0)
                {
                    var_a1++;
                    
                    if (var_s1 != *temp_a2)
                    {
                        temp_a2++;
                        continue;
                    }

                    break;
                }

                if (var_s1 != temp_a2[var_a1])
                {
                    var_s6 = 1;
                    if (g_CurrentSetup.boundpadnames != NULL)
                    {
                        // removed
                    }
                }
                else if (g_CurrentSetup.pathwaypoints != NULL)
                {
                    sub_GAME_7F08F438(spD8, &spD8[var_v0_2], &spA0, &sp9C);
                    
                    if (spA0 == NULL || sp9C == NULL)
                    {
                        var_s6 = 1;                    
                    }
                }
            }
            
            var_s3++;
            var_v0_2 = spD8->neighbours[var_s3];
        }
    }

    if ((temp_s0 != NULL) && (spD8 != NULL))
    {
        var_t1 = 0;

        var_t3 = spD8;
        while (var_t3 != NULL)
        {
            if (var_t3->neighbours != NULL)
            {
                var_a3_2 = 0;
                var_v1_3 = var_t3->waypoints;
                while (*var_v1_3 >= 0)
                {
                    temp_a1_2 = &temp_s0[*var_v1_3];
                    temp_a2_2 = temp_a1_2->groupNum;
    
                    if (temp_a2_2 < 0)
                    {
                        temp_a1_2->groupNum = var_t1;
                        var_v0_4 = &var_t3->waypoints[var_a3_2];
                    }
                    else
                    {
                        var_v0_4 = &var_t3->waypoints[var_a3_2];
                        if (var_t1 != temp_a2_2)
                        {
                            var_s6 = 1;
                        }
                    }

                    var_a3_2++;         
                    
                    var_v1_3 = var_v0_4 + 1;
                }
    
                var_t1 = 0;
            }

            var_t3++;
        }

        var_a2_2 = temp_s0;
        while (var_a2_2->padID >= 0)
        {
            var_a2_2 = &temp_s0[var_t1];
            if (var_a2_2->groupNum < 0)
            {
                var_s6 = 1;
            }
            var_t1++;
        }

        if (spD8->neighbours != NULL)
        {
            var_t3 = spD8;

            
            while (var_t3 != NULL)
            {
                var_v1_4 = 0;
                var_t0_2 = 0;
                var_t4 = 0;
                var_t1_2 = 0;

                var_v0_5 = *var_t3->waypoints;
                while (var_v0_5 >= 0)
                {
                    if (var_t1_2 == 0)
                    {
                        temp_s0[var_v0_5].dist = 1;
                    }
                    else
                    {
                        temp_s0[var_v0_5].dist = 0;
                    }

                    var_v0_5 = var_t3->waypoints[var_t1_2];
                    var_t1_2++;
                }

                // loop_57
                var_t1_3 = 0;
                var_v0_5 = var_t3->waypoints[var_t1_3];
                while (var_v0_5 >= 0)
                {
                    temp_a2_3 = &temp_s0[var_v0_5];

                    if (temp_a2_3->dist == 1)
                    {
                        var_v1_5 = 0;
                        var_v0_6 = temp_a2_3->neighbours[var_v1_5];
                        while (var_v0_6 >= 0) //var_v0_6 >= 0
                        {
                            if (temp_s0[var_v0_6].dist != 1)
                            {
                                temp_s0[var_v0_6].dist = 1;
                                var_t0_2 = 1;
                            }
                            
                            var_v1_5++;
                            var_v0_6 = temp_a2_3->neighbours[var_v1_5];
                        }
                    }
                    
                    var_v0_5 = var_t3->waypoints[var_t1_3];
                }
                
                // loop_67
                var_v0_5 = *var_t3->waypoints;
                while (var_v0_5 >= 0) // var_v0_5 >= 0
                {
                    var_v1_4++;
                    if (temp_s0[var_v0_5].dist != 1)
                    {
                        var_t4 = 1;
                        break;
                    }

                    var_v0_5 = var_t3->waypoints[var_v1_4];
                }

                //var_v1_4 = 0;
                if (var_t0_2 != 0)
                {
                    //var_v0_5 = var_a1_2;
                    if (var_t4 != 0)
                    {
                        //var_t0_2 = 0;
                        //var_t4 = 0;
                        
                        continue;
                    }
                }

                if (var_t4 != 0)
                {
                    var_s6 = 1;
                    
                    if (g_CurrentSetup.boundpadnames != NULL)
                    {
                        //
                    }
                }
                
                var_t3++;
            }
        }
    }

    if (var_s6 != 0)
    {
        while(1);
    }
}

#else
GLOBAL_ASM(
.text
glabel init_path_table_links
/* 03B3C0 7F006890 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 03B3C4 7F006894 AFB40028 */  sw    $s4, 0x28($sp)
/* 03B3C8 7F006898 3C148007 */  lui   $s4, %hi(g_CurrentSetup+0)
/* 03B3CC 7F00689C 26945D00 */  addiu $s4, %lo(g_CurrentSetup+0) # addiu $s4, $s4, 0x5d00
/* 03B3D0 7F0068A0 AFB00018 */  sw    $s0, 0x18($sp)
/* 03B3D4 7F0068A4 8E900000 */  lw    $s0, ($s4)
/* 03B3D8 7F0068A8 8E8E0004 */  lw    $t6, 4($s4)
/* 03B3DC 7F0068AC AFB60030 */  sw    $s6, 0x30($sp)
/* 03B3E0 7F0068B0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 03B3E4 7F0068B4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 03B3E8 7F0068B8 AFB70034 */  sw    $s7, 0x34($sp)
/* 03B3EC 7F0068BC AFB5002C */  sw    $s5, 0x2c($sp)
/* 03B3F0 7F0068C0 AFB30024 */  sw    $s3, 0x24($sp)
/* 03B3F4 7F0068C4 AFB20020 */  sw    $s2, 0x20($sp)
/* 03B3F8 7F0068C8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03B3FC 7F0068CC 0000B025 */  move  $s6, $zero
/* 03B400 7F0068D0 12000036 */  beqz  $s0, .L7F0069AC
/* 03B404 7F0068D4 AFAE00D8 */   sw    $t6, 0xd8($sp)
/* 03B408 7F0068D8 8E0F0000 */  lw    $t7, ($s0)
/* 03B40C 7F0068DC 00003825 */  move  $a3, $zero
/* 03B410 7F0068E0 02006825 */  move  $t5, $s0
/* 03B414 7F0068E4 05E20032 */  bltzl $t7, .L7F0069B0
/* 03B418 7F0068E8 8FAE00D8 */   lw    $t6, 0xd8($sp)
/* 03B41C 7F0068EC 8DA20004 */  lw    $v0, 4($t5)
.L7F0068F0:
/* 03B420 7F0068F0 8C460000 */  lw    $a2, ($v0)
/* 03B424 7F0068F4 00404025 */  move  $t0, $v0
/* 03B428 7F0068F8 04C20027 */  bltzl $a2, .L7F006998
/* 03B42C 7F0068FC 24E70001 */   addiu $a3, $a3, 1
.L7F006900:
/* 03B430 7F006900 14C70007 */  bne   $a2, $a3, .L7F006920
/* 03B434 7F006904 0006C900 */   sll   $t9, $a2, 4
/* 03B438 7F006908 8E980020 */  lw    $t8, 0x20($s4)
/* 03B43C 7F00690C 24160001 */  li    $s6, 1
/* 03B440 7F006910 5300001D */  beql  $t8, $zero, .L7F006988
/* 03B444 7F006914 8D060004 */   lw    $a2, 4($t0)
/* 03B448 7F006918 1000001B */  b     .L7F006988
/* 03B44C 7F00691C 8D060004 */   lw    $a2, 4($t0)
.L7F006920:
/* 03B450 7F006920 03301821 */  addu  $v1, $t9, $s0
/* 03B454 7F006924 8C650004 */  lw    $a1, 4($v1)
/* 03B458 7F006928 00002025 */  move  $a0, $zero
/* 03B45C 7F00692C 8CAE0000 */  lw    $t6, ($a1)
/* 03B460 7F006930 05C2000F */  bltzl $t6, .L7F006970
/* 03B464 7F006934 0004C880 */   sll   $t9, $a0, 2
/* 03B468 7F006938 10EE000C */  beq   $a3, $t6, .L7F00696C
/* 03B46C 7F00693C 00001080 */   sll   $v0, $zero, 2
/* 03B470 7F006940 24420004 */  addiu $v0, $v0, 4
.L7F006944:
/* 03B474 7F006944 00A2C021 */  addu  $t8, $a1, $v0
/* 03B478 7F006948 8F190000 */  lw    $t9, ($t8)
/* 03B47C 7F00694C 24840001 */  addiu $a0, $a0, 1
/* 03B480 7F006950 07220007 */  bltzl $t9, .L7F006970
/* 03B484 7F006954 0004C880 */   sll   $t9, $a0, 2
/* 03B488 7F006958 8C6E0004 */  lw    $t6, 4($v1)
/* 03B48C 7F00695C 01C27821 */  addu  $t7, $t6, $v0
/* 03B490 7F006960 8DF80000 */  lw    $t8, ($t7)
/* 03B494 7F006964 54F8FFF7 */  bnel  $a3, $t8, .L7F006944
/* 03B498 7F006968 24420004 */   addiu $v0, $v0, 4
.L7F00696C:
/* 03B49C 7F00696C 0004C880 */  sll   $t9, $a0, 2
.L7F006970:
/* 03B4A0 7F006970 00B97021 */  addu  $t6, $a1, $t9
/* 03B4A4 7F006974 8DCF0000 */  lw    $t7, ($t6)
/* 03B4A8 7F006978 50EF0003 */  beql  $a3, $t7, .L7F006988
/* 03B4AC 7F00697C 8D060004 */   lw    $a2, 4($t0)
/* 03B4B0 7F006980 24160001 */  li    $s6, 1
/* 03B4B4 7F006984 8D060004 */  lw    $a2, 4($t0)
.L7F006988:
/* 03B4B8 7F006988 25080004 */  addiu $t0, $t0, 4
/* 03B4BC 7F00698C 04C1FFDC */  bgez  $a2, .L7F006900
/* 03B4C0 7F006990 00000000 */   nop   
/* 03B4C4 7F006994 24E70001 */  addiu $a3, $a3, 1
.L7F006998:
/* 03B4C8 7F006998 0007C100 */  sll   $t8, $a3, 4
/* 03B4CC 7F00699C 03106821 */  addu  $t5, $t8, $s0
/* 03B4D0 7F0069A0 8DB90000 */  lw    $t9, ($t5)
/* 03B4D4 7F0069A4 0723FFD2 */  bgezl $t9, .L7F0068F0
/* 03B4D8 7F0069A8 8DA20004 */   lw    $v0, 4($t5)
.L7F0069AC:
/* 03B4DC 7F0069AC 8FAE00D8 */  lw    $t6, 0xd8($sp)
.L7F0069B0:
/* 03B4E0 7F0069B0 11C00054 */  beqz  $t6, .L7F006B04
/* 03B4E4 7F0069B4 00000000 */   nop   
/* 03B4E8 7F0069B8 8DCF0000 */  lw    $t7, ($t6)
/* 03B4EC 7F0069BC 00008825 */  move  $s1, $zero
/* 03B4F0 7F0069C0 01C0A825 */  move  $s5, $t6
/* 03B4F4 7F0069C4 11E0004F */  beqz  $t7, .L7F006B04
/* 03B4F8 7F0069C8 27BE00A0 */   addiu $fp, $sp, 0xa0
/* 03B4FC 7F0069CC AFAE0048 */  sw    $t6, 0x48($sp)
/* 03B500 7F0069D0 2417000C */  li    $s7, 12
/* 03B504 7F0069D4 8EB80000 */  lw    $t8, ($s5)
.L7F0069D8:
/* 03B508 7F0069D8 00009825 */  move  $s3, $zero
/* 03B50C 7F0069DC 8F020000 */  lw    $v0, ($t8)
/* 03B510 7F0069E0 04420042 */  bltzl $v0, .L7F006AEC
/* 03B514 7F0069E4 8FAE0048 */   lw    $t6, 0x48($sp)
.L7F0069E8:
/* 03B518 7F0069E8 14510007 */  bne   $v0, $s1, .L7F006A08
/* 03B51C 7F0069EC 00000000 */   nop   
/* 03B520 7F0069F0 8E990024 */  lw    $t9, 0x24($s4)
/* 03B524 7F0069F4 24160001 */  li    $s6, 1
/* 03B528 7F0069F8 53200036 */  beql  $t9, $zero, .L7F006AD4
/* 03B52C 7F0069FC 8EB90000 */   lw    $t9, ($s5)
/* 03B530 7F006A00 10000034 */  b     .L7F006AD4
/* 03B534 7F006A04 8EB90000 */   lw    $t9, ($s5)
.L7F006A08:
/* 03B538 7F006A08 00570019 */  multu $v0, $s7
/* 03B53C 7F006A0C 8FAE00D8 */  lw    $t6, 0xd8($sp)
/* 03B540 7F006A10 00002825 */  move  $a1, $zero
/* 03B544 7F006A14 00007812 */  mflo  $t7
/* 03B548 7F006A18 01EE9021 */  addu  $s2, $t7, $t6
/* 03B54C 7F006A1C 8E460000 */  lw    $a2, ($s2)
/* 03B550 7F006A20 02402025 */  move  $a0, $s2
/* 03B554 7F006A24 8CD80000 */  lw    $t8, ($a2)
/* 03B558 7F006A28 07020011 */  bltzl $t8, .L7F006A70
/* 03B55C 7F006A2C 00057880 */   sll   $t7, $a1, 2
/* 03B560 7F006A30 8CD90000 */  lw    $t9, ($a2)
/* 03B564 7F006A34 00001080 */  sll   $v0, $zero, 2
/* 03B568 7F006A38 00C21821 */  addu  $v1, $a2, $v0
/* 03B56C 7F006A3C 5239000C */  beql  $s1, $t9, .L7F006A70
/* 03B570 7F006A40 00057880 */   sll   $t7, $a1, 2
/* 03B574 7F006A44 8C6F0004 */  lw    $t7, 4($v1)
.L7F006A48:
/* 03B578 7F006A48 24A50001 */  addiu $a1, $a1, 1
/* 03B57C 7F006A4C 24420004 */  addiu $v0, $v0, 4
/* 03B580 7F006A50 05E00006 */  bltz  $t7, .L7F006A6C
/* 03B584 7F006A54 24630004 */   addiu $v1, $v1, 4
/* 03B588 7F006A58 8C8E0000 */  lw    $t6, ($a0)
/* 03B58C 7F006A5C 01C2C021 */  addu  $t8, $t6, $v0
/* 03B590 7F006A60 8F190000 */  lw    $t9, ($t8)
/* 03B594 7F006A64 5639FFF8 */  bnel  $s1, $t9, .L7F006A48
/* 03B598 7F006A68 8C6F0004 */   lw    $t7, 4($v1)
.L7F006A6C:
/* 03B59C 7F006A6C 00057880 */  sll   $t7, $a1, 2
.L7F006A70:
/* 03B5A0 7F006A70 00CF7021 */  addu  $t6, $a2, $t7
/* 03B5A4 7F006A74 8DD80000 */  lw    $t8, ($t6)
/* 03B5A8 7F006A78 52380008 */  beql  $s1, $t8, .L7F006A9C
/* 03B5AC 7F006A7C 8E8F0000 */   lw    $t7, ($s4)
/* 03B5B0 7F006A80 8E990024 */  lw    $t9, 0x24($s4)
/* 03B5B4 7F006A84 24160001 */  li    $s6, 1
/* 03B5B8 7F006A88 53200012 */  beql  $t9, $zero, .L7F006AD4
/* 03B5BC 7F006A8C 8EB90000 */   lw    $t9, ($s5)
/* 03B5C0 7F006A90 10000010 */  b     .L7F006AD4
/* 03B5C4 7F006A94 8EB90000 */   lw    $t9, ($s5)
/* 03B5C8 7F006A98 8E8F0000 */  lw    $t7, ($s4)
.L7F006A9C:
/* 03B5CC 7F006A9C 02A02025 */  move  $a0, $s5
/* 03B5D0 7F006AA0 02402825 */  move  $a1, $s2
/* 03B5D4 7F006AA4 11E0000A */  beqz  $t7, .L7F006AD0
/* 03B5D8 7F006AA8 03C03025 */   move  $a2, $fp
/* 03B5DC 7F006AAC 0FC23D0E */  jal   sub_GAME_7F08F438
/* 03B5E0 7F006AB0 27A7009C */   addiu $a3, $sp, 0x9c
/* 03B5E4 7F006AB4 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 03B5E8 7F006AB8 8FB8009C */  lw    $t8, 0x9c($sp)
/* 03B5EC 7F006ABC 51C00004 */  beql  $t6, $zero, .L7F006AD0
/* 03B5F0 7F006AC0 24160001 */   li    $s6, 1
/* 03B5F4 7F006AC4 57000003 */  bnezl $t8, .L7F006AD4
/* 03B5F8 7F006AC8 8EB90000 */   lw    $t9, ($s5)
/* 03B5FC 7F006ACC 24160001 */  li    $s6, 1
.L7F006AD0:
/* 03B600 7F006AD0 8EB90000 */  lw    $t9, ($s5)
.L7F006AD4:
/* 03B604 7F006AD4 26730004 */  addiu $s3, $s3, 4
/* 03B608 7F006AD8 03337821 */  addu  $t7, $t9, $s3
/* 03B60C 7F006ADC 8DE20000 */  lw    $v0, ($t7)
/* 03B610 7F006AE0 0441FFC1 */  bgez  $v0, .L7F0069E8
/* 03B614 7F006AE4 00000000 */   nop   
/* 03B618 7F006AE8 8FAE0048 */  lw    $t6, 0x48($sp)
.L7F006AEC:
/* 03B61C 7F006AEC 26310001 */  addiu $s1, $s1, 1
/* 03B620 7F006AF0 25D5000C */  addiu $s5, $t6, 0xc
/* 03B624 7F006AF4 AFB50048 */  sw    $s5, 0x48($sp)
/* 03B628 7F006AF8 8EB90000 */  lw    $t9, ($s5)
/* 03B62C 7F006AFC 5720FFB6 */  bnezl $t9, .L7F0069D8
/* 03B630 7F006B00 8EB80000 */   lw    $t8, ($s5)
.L7F006B04:
/* 03B634 7F006B04 12000091 */  beqz  $s0, .L7F006D4C
/* 03B638 7F006B08 8FAF00D8 */   lw    $t7, 0xd8($sp)
/* 03B63C 7F006B0C 11E0008F */  beqz  $t7, .L7F006D4C
/* 03B640 7F006B10 00000000 */   nop   
/* 03B644 7F006B14 8DE30000 */  lw    $v1, ($t7)
/* 03B648 7F006B18 00004825 */  move  $t1, $zero
/* 03B64C 7F006B1C 01E05825 */  move  $t3, $t7
/* 03B650 7F006B20 1060001F */  beqz  $v1, .L7F006BA0
/* 03B654 7F006B24 0200B825 */   move  $s7, $s0
/* 03B658 7F006B28 01E06825 */  move  $t5, $t7
.L7F006B2C:
/* 03B65C 7F006B2C 8D640004 */  lw    $a0, 4($t3)
/* 03B660 7F006B30 00003825 */  move  $a3, $zero
/* 03B664 7F006B34 8C830000 */  lw    $v1, ($a0)
/* 03B668 7F006B38 04600011 */  bltz  $v1, .L7F006B80
/* 03B66C 7F006B3C 00037100 */   sll   $t6, $v1, 4
.L7F006B40:
/* 03B670 7F006B40 01D02821 */  addu  $a1, $t6, $s0
/* 03B674 7F006B44 8CA60008 */  lw    $a2, 8($a1)
/* 03B678 7F006B48 04C10005 */  bgez  $a2, .L7F006B60
/* 03B67C 7F006B4C 00000000 */   nop   
/* 03B680 7F006B50 ACA90008 */  sw    $t1, 8($a1)
/* 03B684 7F006B54 8D640004 */  lw    $a0, 4($t3)
/* 03B688 7F006B58 10000004 */  b     .L7F006B6C
/* 03B68C 7F006B5C 00871021 */   addu  $v0, $a0, $a3
.L7F006B60:
/* 03B690 7F006B60 11260002 */  beq   $t1, $a2, .L7F006B6C
/* 03B694 7F006B64 00871021 */   addu  $v0, $a0, $a3
/* 03B698 7F006B68 24160001 */  li    $s6, 1
.L7F006B6C:
/* 03B69C 7F006B6C 8C430004 */  lw    $v1, 4($v0)
/* 03B6A0 7F006B70 24E70004 */  addiu $a3, $a3, 4
/* 03B6A4 7F006B74 24420004 */  addiu $v0, $v0, 4
/* 03B6A8 7F006B78 0463FFF1 */  bgezl $v1, .L7F006B40
/* 03B6AC 7F006B7C 00037100 */   sll   $t6, $v1, 4
.L7F006B80:
/* 03B6B0 7F006B80 8DB8000C */  lw    $t8, 0xc($t5)
/* 03B6B4 7F006B84 25AD000C */  addiu $t5, $t5, 0xc
/* 03B6B8 7F006B88 01A05825 */  move  $t3, $t5
/* 03B6BC 7F006B8C 1700FFE7 */  bnez  $t8, .L7F006B2C
/* 03B6C0 7F006B90 25290001 */   addiu $t1, $t1, 1
/* 03B6C4 7F006B94 8FAB00D8 */  lw    $t3, 0xd8($sp)
/* 03B6C8 7F006B98 00004825 */  move  $t1, $zero
/* 03B6CC 7F006B9C 8D630000 */  lw    $v1, ($t3)
.L7F006BA0:
/* 03B6D0 7F006BA0 8EEF0000 */  lw    $t7, ($s7)
/* 03B6D4 7F006BA4 02E03025 */  move  $a2, $s7
/* 03B6D8 7F006BA8 8FAD00D8 */  lw    $t5, 0xd8($sp)
/* 03B6DC 7F006BAC 05E0000A */  bltz  $t7, .L7F006BD8
/* 03B6E0 7F006BB0 24070001 */   li    $a3, 1
/* 03B6E4 7F006BB4 8CCE0008 */  lw    $t6, 8($a2)
.L7F006BB8:
/* 03B6E8 7F006BB8 25290001 */  addiu $t1, $t1, 1
/* 03B6EC 7F006BBC 0009C100 */  sll   $t8, $t1, 4
/* 03B6F0 7F006BC0 05C10002 */  bgez  $t6, .L7F006BCC
/* 03B6F4 7F006BC4 03103021 */   addu  $a2, $t8, $s0
/* 03B6F8 7F006BC8 24160001 */  li    $s6, 1
.L7F006BCC:
/* 03B6FC 7F006BCC 8CD90000 */  lw    $t9, ($a2)
/* 03B700 7F006BD0 0723FFF9 */  bgezl $t9, .L7F006BB8
/* 03B704 7F006BD4 8CCE0008 */   lw    $t6, 8($a2)
.L7F006BD8:
/* 03B708 7F006BD8 1060005C */  beqz  $v1, .L7F006D4C
/* 03B70C 7F006BDC 00000000 */   nop   
/* 03B710 7F006BE0 8D640004 */  lw    $a0, 4($t3)
.L7F006BE4:
/* 03B714 7F006BE4 00001825 */  move  $v1, $zero
/* 03B718 7F006BE8 00004025 */  move  $t0, $zero
/* 03B71C 7F006BEC 8C850000 */  lw    $a1, ($a0)
/* 03B720 7F006BF0 00006025 */  move  $t4, $zero
/* 03B724 7F006BF4 00004825 */  move  $t1, $zero
/* 03B728 7F006BF8 04A00012 */  bltz  $a1, .L7F006C44
/* 03B72C 7F006BFC 00A01025 */   move  $v0, $a1
.L7F006C00:
/* 03B730 7F006C00 15200005 */  bnez  $t1, .L7F006C18
/* 03B734 7F006C04 0002C100 */   sll   $t8, $v0, 4
/* 03B738 7F006C08 00027900 */  sll   $t7, $v0, 4
/* 03B73C 7F006C0C 01F07021 */  addu  $t6, $t7, $s0
/* 03B740 7F006C10 10000003 */  b     .L7F006C20
/* 03B744 7F006C14 ADC7000C */   sw    $a3, 0xc($t6)
.L7F006C18:
/* 03B748 7F006C18 0310C821 */  addu  $t9, $t8, $s0
/* 03B74C 7F006C1C AF20000C */  sw    $zero, 0xc($t9)
.L7F006C20:
/* 03B750 7F006C20 8D640004 */  lw    $a0, 4($t3)
/* 03B754 7F006C24 25290004 */  addiu $t1, $t1, 4
/* 03B758 7F006C28 00897821 */  addu  $t7, $a0, $t1
/* 03B75C 7F006C2C 8DE20000 */  lw    $v0, ($t7)
/* 03B760 7F006C30 0441FFF3 */  bgez  $v0, .L7F006C00
/* 03B764 7F006C34 00000000 */   nop   
/* 03B768 7F006C38 8C850000 */  lw    $a1, ($a0)
/* 03B76C 7F006C3C 00001825 */  move  $v1, $zero
/* 03B770 7F006C40 00A01025 */  move  $v0, $a1
.L7F006C44:
/* 03B774 7F006C44 04400020 */  bltz  $v0, .L7F006CC8
/* 03B778 7F006C48 00004825 */   move  $t1, $zero
/* 03B77C 7F006C4C 00027100 */  sll   $t6, $v0, 4
.L7F006C50:
/* 03B780 7F006C50 01D03021 */  addu  $a2, $t6, $s0
/* 03B784 7F006C54 8CD8000C */  lw    $t8, 0xc($a2)
/* 03B788 7F006C58 25290004 */  addiu $t1, $t1, 4
/* 03B78C 7F006C5C 54F80014 */  bnel  $a3, $t8, .L7F006CB0
/* 03B790 7F006C60 0089C021 */   addu  $t8, $a0, $t1
/* 03B794 7F006C64 8CC50004 */  lw    $a1, 4($a2)
/* 03B798 7F006C68 00001825 */  move  $v1, $zero
/* 03B79C 7F006C6C 8CA20000 */  lw    $v0, ($a1)
/* 03B7A0 7F006C70 0440000E */  bltz  $v0, .L7F006CAC
/* 03B7A4 7F006C74 0002C900 */   sll   $t9, $v0, 4
.L7F006C78:
/* 03B7A8 7F006C78 03302021 */  addu  $a0, $t9, $s0
/* 03B7AC 7F006C7C 8C8F000C */  lw    $t7, 0xc($a0)
/* 03B7B0 7F006C80 24630004 */  addiu $v1, $v1, 4
/* 03B7B4 7F006C84 50EF0005 */  beql  $a3, $t7, .L7F006C9C
/* 03B7B8 7F006C88 00A37021 */   addu  $t6, $a1, $v1
/* 03B7BC 7F006C8C AC87000C */  sw    $a3, 0xc($a0)
/* 03B7C0 7F006C90 8CC50004 */  lw    $a1, 4($a2)
/* 03B7C4 7F006C94 00E04025 */  move  $t0, $a3
/* 03B7C8 7F006C98 00A37021 */  addu  $t6, $a1, $v1
.L7F006C9C:
/* 03B7CC 7F006C9C 8DC20000 */  lw    $v0, ($t6)
/* 03B7D0 7F006CA0 0443FFF5 */  bgezl $v0, .L7F006C78
/* 03B7D4 7F006CA4 0002C900 */   sll   $t9, $v0, 4
/* 03B7D8 7F006CA8 8D640004 */  lw    $a0, 4($t3)
.L7F006CAC:
/* 03B7DC 7F006CAC 0089C021 */  addu  $t8, $a0, $t1
.L7F006CB0:
/* 03B7E0 7F006CB0 8F020000 */  lw    $v0, ($t8)
/* 03B7E4 7F006CB4 0443FFE6 */  bgezl $v0, .L7F006C50
/* 03B7E8 7F006CB8 00027100 */   sll   $t6, $v0, 4
/* 03B7EC 7F006CBC 8C850000 */  lw    $a1, ($a0)
/* 03B7F0 7F006CC0 00001825 */  move  $v1, $zero
/* 03B7F4 7F006CC4 00A01025 */  move  $v0, $a1
.L7F006CC8:
/* 03B7F8 7F006CC8 0440000C */  bltz  $v0, .L7F006CFC
/* 03B7FC 7F006CCC 0002C900 */   sll   $t9, $v0, 4
.L7F006CD0:
/* 03B800 7F006CD0 03307821 */  addu  $t7, $t9, $s0
/* 03B804 7F006CD4 8DEE000C */  lw    $t6, 0xc($t7)
/* 03B808 7F006CD8 24630001 */  addiu $v1, $v1, 1
/* 03B80C 7F006CDC 0003C080 */  sll   $t8, $v1, 2
/* 03B810 7F006CE0 10EE0003 */  beq   $a3, $t6, .L7F006CF0
/* 03B814 7F006CE4 0098C821 */   addu  $t9, $a0, $t8
/* 03B818 7F006CE8 10000004 */  b     .L7F006CFC
/* 03B81C 7F006CEC 00E06025 */   move  $t4, $a3
.L7F006CF0:
/* 03B820 7F006CF0 8F220000 */  lw    $v0, ($t9)
/* 03B824 7F006CF4 0443FFF6 */  bgezl $v0, .L7F006CD0
/* 03B828 7F006CF8 0002C900 */   sll   $t9, $v0, 4
.L7F006CFC:
/* 03B82C 7F006CFC 11000003 */  beqz  $t0, .L7F006D0C
/* 03B830 7F006D00 00001825 */   move  $v1, $zero
/* 03B834 7F006D04 15800009 */  bnez  $t4, .L7F006D2C
/* 03B838 7F006D08 00A01025 */   move  $v0, $a1
.L7F006D0C:
/* 03B83C 7F006D0C 5180000B */  beql  $t4, $zero, .L7F006D3C
/* 03B840 7F006D10 8DAE000C */   lw    $t6, 0xc($t5)
/* 03B844 7F006D14 8E8F0024 */  lw    $t7, 0x24($s4)
/* 03B848 7F006D18 24160001 */  li    $s6, 1
/* 03B84C 7F006D1C 51E00007 */  beql  $t7, $zero, .L7F006D3C
/* 03B850 7F006D20 8DAE000C */   lw    $t6, 0xc($t5)
/* 03B854 7F006D24 10000005 */  b     .L7F006D3C
/* 03B858 7F006D28 8DAE000C */   lw    $t6, 0xc($t5)
.L7F006D2C:
/* 03B85C 7F006D2C 00004025 */  move  $t0, $zero
/* 03B860 7F006D30 1000FFC4 */  b     .L7F006C44
/* 03B864 7F006D34 00006025 */   move  $t4, $zero
/* 03B868 7F006D38 8DAE000C */  lw    $t6, 0xc($t5)
.L7F006D3C:
/* 03B86C 7F006D3C 25AD000C */  addiu $t5, $t5, 0xc
/* 03B870 7F006D40 01A05825 */  move  $t3, $t5
/* 03B874 7F006D44 55C0FFA7 */  bnezl $t6, .L7F006BE4
/* 03B878 7F006D48 8D640004 */   lw    $a0, 4($t3)
.L7F006D4C:
/* 03B87C 7F006D4C 12C00003 */  beqz  $s6, .L7F006D5C
/* 03B880 7F006D50 8FB00018 */   lw    $s0, 0x18($sp)
.L7F006D54:
/* 03B884 7F006D54 1000FFFF */  b     .L7F006D54
/* 03B888 7F006D58 00000000 */   nop   
.L7F006D5C:
/* 03B88C 7F006D5C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 03B890 7F006D60 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03B894 7F006D64 8FB20020 */  lw    $s2, 0x20($sp)
/* 03B898 7F006D68 8FB30024 */  lw    $s3, 0x24($sp)
/* 03B89C 7F006D6C 8FB40028 */  lw    $s4, 0x28($sp)
/* 03B8A0 7F006D70 8FB5002C */  lw    $s5, 0x2c($sp)
/* 03B8A4 7F006D74 8FB60030 */  lw    $s6, 0x30($sp)
/* 03B8A8 7F006D78 8FB70034 */  lw    $s7, 0x34($sp)
/* 03B8AC 7F006D7C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 03B8B0 7F006D80 03E00008 */  jr    $ra
/* 03B8B4 7F006D84 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#endif


