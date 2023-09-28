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




#if defined(LEFTOVERDEBUG)
void gotoRightDebugOption(void)
{
	s32 i;

	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0])
    {
        g_DMenuSelectedOption += g_DMenuCurOffsets[0];

        if (g_DMenuSelectedOption >= g_DMenuCurOffsets[1])
        {
            g_DMenuSelectedOption = g_DMenuCurOffsets[1] - 1;
        }
        
		return;
	}

	for (i = 0; i < g_DMenuNumGroups; i++)
    {
		if (g_DMenuSelectedOption < g_DMenuCurOffsets[i])
        {
			g_DMenuSelectedOption = g_DMenuSelectedOption + g_DMenuCurOffsets[i] - g_DMenuCurOffsets[i - 1];

			if (g_DMenuCurOffsets[i + 1] < 0)
            {
				g_DMenuSelectedOption -= g_DMenuCurOffsets[i];

				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[0])
                {
					g_DMenuSelectedOption = g_DMenuCurOffsets[0] - 1;
				}
			}
            else
            {
				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i + 1])
                {
					g_DMenuSelectedOption = g_DMenuCurOffsets[i + 1] - 1;
				}
			}
            
			return;
		}
	}
}
#else
void gotoRightDebugOption(void)
{

}
#endif



#if defined(LEFTOVERDEBUG)
void gotoLeftDebugOption(void)
{
	s32 i;

	// First group
	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0])
    {
		s32 i;

		for (i = 0; i < g_DMenuNumGroups - 1; i++)
        {}

        g_DMenuSelectedOption += g_DMenuCurOffsets[i - 1];

        if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i])
        {
            g_DMenuSelectedOption = g_DMenuCurOffsets[i] - 1;
        }
        
		return;
	}

	// Any other group
	for (i = 0; g_DMenuSelectedOption >= g_DMenuCurOffsets[i]; i++)
    {}

	g_DMenuSelectedOption -= g_DMenuCurOffsets[i - 1];

	if (i - 2 >= 0)
    {
		g_DMenuSelectedOption += g_DMenuCurOffsets[i - 2];
	}

	if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i - 1])
    {
		g_DMenuSelectedOption = g_DMenuCurOffsets[i - 1] - 1;
	}
}
#else
void gotoLeftDebugOption(void)
{

}
#endif


