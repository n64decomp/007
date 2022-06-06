#include <ultra64.h>

#if defined(LEFTOVERDEBUG)
// data
//D:80036B70
s32 g_DMenuSelectedOption = 0;
//D:80036B74
s32 g_DMenuNumOptions = 0;
//D:80036B78
char **g_DMenuCurLabels = 0;
//D:80036B7C
s32 (*g_DMenuCurPositions)[2] = 0;
//D:80036B80
s32 g_DMenuNumGroups  = 0;
//D:80036B84
s32 *g_DMenuCurOffsets = 0;
//D:80036B88
s32 g_DMenuScaleIndex = 2;
//D:80036B8C
u8 g_DMenuXScales[] = { 4, 4, 4 };
//D:80036B90
u8 g_DMenuYScales[] = { 7, 7, 7 };
/*
D:80036B94                     .word 0
D:80036B98                     .word 0
D:80036B9C                     .word 0
*/

// rodata
//D:80055340
//const char aMenu_cErrorTriedToCallFont_makegt[] = "menu.c: ERROR! Tried to call font_makegt\n";
#endif


#if defined(LEFTOVERDEBUG)
void nullsub_32(void) {
    return;
}
#endif


void debmenuSetScaleIndex(s32 param_1) {
#if defined(LEFTOVERDEBUG)
    g_DMenuScaleIndex = param_1;
#endif
}



void debmenuSetMenu(char **labels, s32 (*positions)[2], s32 *offsets)
{
    #if defined(LEFTOVERDEBUG)
	s32 numgroups;

	g_DMenuCurLabels = labels;
	g_DMenuCurPositions = positions;
	g_DMenuCurOffsets = offsets;

	for (numgroups = 0; offsets[numgroups] >= 0; numgroups++);

	g_DMenuNumOptions = offsets[numgroups - 1];
	g_DMenuNumGroups = numgroups;
    #endif
}


Gfx *debugmenuRender(Gfx *gdl)
{
    #if defined (LEFTOVERDEBUG)
	s32 i;
	s32 xscale = g_DMenuXScales[g_DMenuScaleIndex];
	s32 yscale = g_DMenuYScales[g_DMenuScaleIndex];


	for (i = 0; i < g_DMenuNumOptions; i++) {
        nullsub_32();
		if (i == g_DMenuSelectedOption) {
			debmenuSetFgColour(0xc0, 0x00, 0x00, 0xc0);
        }else{
            debmenuSetFgColour(0xc0, 0xC0, 0xC0, 0xc0);
        }
		debmenuSetPos((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
		debmenuPrintString(g_DMenuCurLabels[i]);
	}
    #endif
	return gdl;
}


void sub_GAME_7F09000C(int a0,int a1,int a2)
{
    #if defined (LEFTOVERDEBUG)
	s32 i;
	s32 xscale = g_DMenuXScales[g_DMenuScaleIndex];
	s32 yscale = g_DMenuYScales[g_DMenuScaleIndex];

    for (i = 0; i < g_DMenuNumOptions; i++) {
        nullsub_32();       
        if (i == g_DMenuSelectedOption) {
            debmenuSetFgColour(0xC0, 0, 0, 0xC0);
        } else {
            debmenuSetFgColour(0xC0, 0xC0, 0xC0, 0xC0);
        }
        debmenuSetPos((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
        debmenuPrintString(g_DMenuCurLabels[i]);
        osSyncPrintf("menu.c: ERROR! Tried to call font_makegt\n");
    }
    #endif
}




s32 get_highlighted_debug_option(void) {
#if defined(LEFTOVERDEBUG)
    return g_DMenuSelectedOption;
#else
    return 0;
#endif
}


void set_highlighted_debug_option(s32 value) {
#if defined(LEFTOVERDEBUG)
    g_DMenuSelectedOption = value;
#endif
}


void gotoAboveDebugOption(void)
{
    #if defined(LEFTOVERDEBUG)
	s32 i;

	g_DMenuSelectedOption--;

	// If at the top of the first group, wrap to the bottom of the group.
	// This must be treated differently to the other groups because the first
	// group's offset is omitted from the offsets array.
	if (g_DMenuSelectedOption < 0) {
		g_DMenuSelectedOption = g_DMenuCurOffsets[0] - 1;
		return;
	}

	// If at the top of any other group, wrap to the bottom of that group.
	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption == g_DMenuCurOffsets[i] - 1) {
			g_DMenuSelectedOption = g_DMenuCurOffsets[i + 1] - 1;
			return;
		}
	}
    #endif
}


void gotoBelowDebugOption(void)
{
    #if defined(LEFTOVERDEBUG)
	s32 i;

	g_DMenuSelectedOption++;

	// If at the bottom of the first group, wrap to the top of the group.
	// This must be treated differently to the other groups because the first
	// group's offset is omitted from the offsets array.
	if (g_DMenuSelectedOption == g_DMenuCurOffsets[0]) {
		g_DMenuSelectedOption = 0;
		return;
	}

	// If at the bottom of any other group, wrap to the top of that group.
	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption == g_DMenuCurOffsets[i]) {
			g_DMenuSelectedOption = g_DMenuCurOffsets[i - 1];
			return;
		}
	}
    #endif
}




#ifdef NONMATCHING
void gotoRightDebugOption(void)
{
	s32 i;

	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0]) {
		if (g_DMenuNumGroups >= 2) {
			g_DMenuSelectedOption += g_DMenuCurOffsets[0];

			if (g_DMenuSelectedOption >= g_DMenuCurOffsets[1]) {
				g_DMenuSelectedOption = g_DMenuCurOffsets[1] - 1;
			}
		}
		return;
	}

	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption < g_DMenuCurOffsets[i]) {
			g_DMenuSelectedOption = g_DMenuSelectedOption + g_DMenuCurOffsets[i] - g_DMenuCurOffsets[i - 1];

			if (g_DMenuCurOffsets[i + 1] < 0) {
				g_DMenuSelectedOption -= g_DMenuCurOffsets[i];

				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[0]) {
					g_DMenuSelectedOption = g_DMenuCurOffsets[0] - 1;
				}
			} else {
				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i + 1]) {
					g_DMenuSelectedOption = g_DMenuCurOffsets[i + 1] - 1;
				}
			}
			return;
		}
	}
}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel gotoRightDebugOption
/* 0C4DF0 7F0902C0 3C038003 */  lui   $v1, %hi(g_DMenuCurOffsets)
/* 0C4DF4 7F0902C4 8C636B84 */  lw    $v1, %lo(g_DMenuCurOffsets)($v1)
/* 0C4DF8 7F0902C8 3C088003 */  lui   $t0, %hi(g_DMenuSelectedOption) 
/* 0C4DFC 7F0902CC 25086B70 */  addiu $t0, %lo(g_DMenuSelectedOption) # addiu $t0, $t0, 0x6b70
/* 0C4E00 7F0902D0 8D020000 */  lw    $v0, ($t0)
/* 0C4E04 7F0902D4 8C640000 */  lw    $a0, ($v1)
/* 0C4E08 7F0902D8 3C058003 */  lui   $a1, %hi(g_DMenuNumGroups )
/* 0C4E0C 7F0902DC 0044082A */  slt   $at, $v0, $a0
/* 0C4E10 7F0902E0 10200008 */  beqz  $at, .L7F090304
/* 0C4E14 7F0902E4 00447021 */   addu  $t6, $v0, $a0
/* 0C4E18 7F0902E8 AD0E0000 */  sw    $t6, ($t0)
/* 0C4E1C 7F0902EC 8C650004 */  lw    $a1, 4($v1)
/* 0C4E20 7F0902F0 01C5082A */  slt   $at, $t6, $a1
/* 0C4E24 7F0902F4 14200027 */  bnez  $at, .L7F090394
/* 0C4E28 7F0902F8 24B8FFFF */   addiu $t8, $a1, -1
/* 0C4E2C 7F0902FC 03E00008 */  jr    $ra
/* 0C4E30 7F090300 AD180000 */   sw    $t8, ($t0)

.L7F090304:
/* 0C4E34 7F090304 8CA56B80 */  lw    $a1, %lo(g_DMenuNumGroups )($a1)
/* 0C4E38 7F090308 00002025 */  move  $a0, $zero
/* 0C4E3C 7F09030C 00603025 */  move  $a2, $v1
/* 0C4E40 7F090310 18A00020 */  blez  $a1, .L7F090394
/* 0C4E44 7F090314 00000000 */   nop   
.L7F090318:
/* 0C4E48 7F090318 8CC70000 */  lw    $a3, ($a2)
/* 0C4E4C 7F09031C 24840001 */  addiu $a0, $a0, 1
/* 0C4E50 7F090320 0047082A */  slt   $at, $v0, $a3
/* 0C4E54 7F090324 50200019 */  beql  $at, $zero, .L7F09038C
/* 0C4E58 7F090328 0085082A */   slt   $at, $a0, $a1
/* 0C4E5C 7F09032C 8CC9FFFC */  lw    $t1, -4($a2)
/* 0C4E60 7F090330 0047C821 */  addu  $t9, $v0, $a3
/* 0C4E64 7F090334 03295023 */  subu  $t2, $t9, $t1
/* 0C4E68 7F090338 AD0A0000 */  sw    $t2, ($t0)
/* 0C4E6C 7F09033C 8CC40004 */  lw    $a0, 4($a2)
/* 0C4E70 7F090340 0483000B */  bgezl $a0, .L7F090370
/* 0C4E74 7F090344 8D180000 */   lw    $t8, ($t0)
/* 0C4E78 7F090348 8CCC0000 */  lw    $t4, ($a2)
/* 0C4E7C 7F09034C 014C6823 */  subu  $t5, $t2, $t4
/* 0C4E80 7F090350 AD0D0000 */  sw    $t5, ($t0)
/* 0C4E84 7F090354 8C640000 */  lw    $a0, ($v1)
/* 0C4E88 7F090358 01A4082A */  slt   $at, $t5, $a0
/* 0C4E8C 7F09035C 1420000D */  bnez  $at, .L7F090394
/* 0C4E90 7F090360 248FFFFF */   addiu $t7, $a0, -1
/* 0C4E94 7F090364 03E00008 */  jr    $ra
/* 0C4E98 7F090368 AD0F0000 */   sw    $t7, ($t0)

/* 0C4E9C 7F09036C 8D180000 */  lw    $t8, ($t0)
.L7F090370:
/* 0C4EA0 7F090370 2499FFFF */  addiu $t9, $a0, -1
/* 0C4EA4 7F090374 0304082A */  slt   $at, $t8, $a0
/* 0C4EA8 7F090378 14200006 */  bnez  $at, .L7F090394
/* 0C4EAC 7F09037C 00000000 */   nop   
/* 0C4EB0 7F090380 03E00008 */  jr    $ra
/* 0C4EB4 7F090384 AD190000 */   sw    $t9, ($t0)

/* 0C4EB8 7F090388 0085082A */  slt   $at, $a0, $a1
.L7F09038C:
/* 0C4EBC 7F09038C 1420FFE2 */  bnez  $at, .L7F090318
/* 0C4EC0 7F090390 24C60004 */   addiu $a2, $a2, 4
.L7F090394:
/* 0C4EC4 7F090394 03E00008 */  jr    $ra
/* 0C4EC8 7F090398 00000000 */   nop   
)
#else
void gotoRightDebugOption(void)
{

}
#endif
#endif




#ifdef NONMATCHING
void gotoLeftDebugOption(void)
{
	s32 i;

	// First group
	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0]) {
		s32 i;

		for (i = 0; i < g_DMenuNumGroups - 1; i++);

		if (i > 0) {
			g_DMenuSelectedOption += g_DMenuCurOffsets[i - 1];

			if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i]) {
				g_DMenuSelectedOption = g_DMenuCurOffsets[i] - 1;
			}
		}
		return;
	}

	// Any other group
	for (i = 0; g_DMenuSelectedOption >= g_DMenuCurOffsets[i]; i++);

	g_DMenuSelectedOption -= g_DMenuCurOffsets[i - 1];

	if (i - 2 >= 0) {
		g_DMenuSelectedOption += g_DMenuCurOffsets[i - 2];
	}

	if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i - 1]) {
		g_DMenuSelectedOption = g_DMenuCurOffsets[i - 1] - 1;
	}
}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel gotoLeftDebugOption
/* 0C4ECC 7F09039C 3C038003 */  lui   $v1, %hi(g_DMenuCurOffsets)
/* 0C4ED0 7F0903A0 8C636B84 */  lw    $v1, %lo(g_DMenuCurOffsets)($v1)
/* 0C4ED4 7F0903A4 3C078003 */  lui   $a3, %hi(g_DMenuSelectedOption)
/* 0C4ED8 7F0903A8 24E76B70 */  addiu $a3, %lo(g_DMenuSelectedOption) # addiu $a3, $a3, 0x6b70
/* 0C4EDC 7F0903AC 8CE20000 */  lw    $v0, ($a3)
/* 0C4EE0 7F0903B0 8C640000 */  lw    $a0, ($v1)
/* 0C4EE4 7F0903B4 3C058003 */  lui   $a1, %hi(g_DMenuNumGroups )
/* 0C4EE8 7F0903B8 0044082A */  slt   $at, $v0, $a0
/* 0C4EEC 7F0903BC 50200016 */  beql  $at, $zero, .L7F090418
/* 0C4EF0 7F0903C0 0044082A */   slt   $at, $v0, $a0
/* 0C4EF4 7F0903C4 8CA56B80 */  lw    $a1, %lo(g_DMenuNumGroups )($a1)
/* 0C4EF8 7F0903C8 00002025 */  move  $a0, $zero
/* 0C4EFC 7F0903CC 24A5FFFF */  addiu $a1, $a1, -1
/* 0C4F00 7F0903D0 58A00006 */  blezl $a1, .L7F0903EC
/* 0C4F04 7F0903D4 00047080 */   sll   $t6, $a0, 2
/* 0C4F08 7F0903D8 24840001 */  addiu $a0, $a0, 1
.L7F0903DC:
/* 0C4F0C 7F0903DC 0085082A */  slt   $at, $a0, $a1
/* 0C4F10 7F0903E0 5420FFFE */  bnezl $at, .L7F0903DC
/* 0C4F14 7F0903E4 24840001 */   addiu $a0, $a0, 1
/* 0C4F18 7F0903E8 00047080 */  sll   $t6, $a0, 2
.L7F0903EC:
/* 0C4F1C 7F0903EC 006E2821 */  addu  $a1, $v1, $t6
/* 0C4F20 7F0903F0 8CAFFFFC */  lw    $t7, -4($a1)
/* 0C4F24 7F0903F4 004FC021 */  addu  $t8, $v0, $t7
/* 0C4F28 7F0903F8 ACF80000 */  sw    $t8, ($a3)
/* 0C4F2C 7F0903FC 8CA60000 */  lw    $a2, ($a1)
/* 0C4F30 7F090400 0306082A */  slt   $at, $t8, $a2
/* 0C4F34 7F090404 1420001E */  bnez  $at, .L7F090480
/* 0C4F38 7F090408 24C8FFFF */   addiu $t0, $a2, -1
/* 0C4F3C 7F09040C 03E00008 */  jr    $ra
/* 0C4F40 7F090410 ACE80000 */   sw    $t0, ($a3)

/* 0C4F44 7F090414 0044082A */  slt   $at, $v0, $a0
.L7F090418:
/* 0C4F48 7F090418 14200008 */  bnez  $at, .L7F09043C
/* 0C4F4C 7F09041C 00002825 */   move  $a1, $zero
/* 0C4F50 7F090420 00602025 */  move  $a0, $v1
/* 0C4F54 7F090424 8C890004 */  lw    $t1, 4($a0)
.L7F090428:
/* 0C4F58 7F090428 24A50001 */  addiu $a1, $a1, 1
/* 0C4F5C 7F09042C 24840004 */  addiu $a0, $a0, 4
/* 0C4F60 7F090430 0049082A */  slt   $at, $v0, $t1
/* 0C4F64 7F090434 5020FFFC */  beql  $at, $zero, .L7F090428
/* 0C4F68 7F090438 8C890004 */   lw    $t1, 4($a0)
.L7F09043C:
/* 0C4F6C 7F09043C 00055080 */  sll   $t2, $a1, 2
/* 0C4F70 7F090440 006A2021 */  addu  $a0, $v1, $t2
/* 0C4F74 7F090444 8C8BFFFC */  lw    $t3, -4($a0)
/* 0C4F78 7F090448 24ADFFFE */  addiu $t5, $a1, -2
/* 0C4F7C 7F09044C 004B6023 */  subu  $t4, $v0, $t3
/* 0C4F80 7F090450 05A00004 */  bltz  $t5, .L7F090464
/* 0C4F84 7F090454 ACEC0000 */   sw    $t4, ($a3)
/* 0C4F88 7F090458 8C8FFFF8 */  lw    $t7, -8($a0)
/* 0C4F8C 7F09045C 018FC021 */  addu  $t8, $t4, $t7
/* 0C4F90 7F090460 ACF80000 */  sw    $t8, ($a3)
.L7F090464:
/* 0C4F94 7F090464 8C82FFFC */  lw    $v0, -4($a0)
/* 0C4F98 7F090468 8CF90000 */  lw    $t9, ($a3)
/* 0C4F9C 7F09046C 2448FFFF */  addiu $t0, $v0, -1
/* 0C4FA0 7F090470 0322082A */  slt   $at, $t9, $v0
/* 0C4FA4 7F090474 14200002 */  bnez  $at, .L7F090480
/* 0C4FA8 7F090478 00000000 */   nop   
/* 0C4FAC 7F09047C ACE80000 */  sw    $t0, ($a3)
.L7F090480:
/* 0C4FB0 7F090480 03E00008 */  jr    $ra
/* 0C4FB4 7F090484 00000000 */   nop   
)
#else
void gotoLeftDebugOption(void)
{

}
#endif
#endif


