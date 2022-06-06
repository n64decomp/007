
#include <ultra64.h>
#include "deb_print.h"
#include <bondgame.h>
#include "fr.h"
#include <PR/R4300.h>

/**
 * EU .data, offset from start of data_seg : 0x2540
*/

// Padding
u32 D_80023300 = 0;

//The following regDesc's are similar to PR/Tools/Gload/Server.c 
/*
 * Cause Register
 */
static regDesc_t causeDesc[] = {
    {CAUSE_BD, CAUSE_BD, "BD"},
    /* Interrupt pending bits */
    {CAUSE_IP8, CAUSE_IP8, "IP8"},
    {CAUSE_IP7, CAUSE_IP7, "IP7"},
    {CAUSE_IP6, CAUSE_IP6, "IP6"},
    {CAUSE_IP5, CAUSE_IP5, "IP5"},
    {CAUSE_IP4, CAUSE_IP4, "IP4"},
    {CAUSE_IP3, CAUSE_IP3, "IP3"},
    {CAUSE_SW2, CAUSE_SW2, "IP2"},
    {CAUSE_SW1, CAUSE_SW1, "IP1"},
    /* Hardware exception codes */
    {CAUSE_EXCMASK, EXC_INT, "Int"},
    {CAUSE_EXCMASK, EXC_MOD, "TLBmod"},
    {CAUSE_EXCMASK, EXC_RMISS, "TLBload"},
    {CAUSE_EXCMASK, EXC_WMISS, "TLBstore"},
    {CAUSE_EXCMASK, EXC_RADE, "Address error on load or instruction fetch"},
    {CAUSE_EXCMASK, EXC_WADE, "Address error on store"},
    {CAUSE_EXCMASK, EXC_IBE, "Bus error exception on instruction fetch"},
    {CAUSE_EXCMASK, EXC_DBE, "Bus error exception on data reference"},
    {CAUSE_EXCMASK, EXC_SYSCALL, "Syscall"},
    {CAUSE_EXCMASK, EXC_BREAK, "Brk"},
    {CAUSE_EXCMASK, EXC_II, "Reserved instruction"},
    {CAUSE_EXCMASK, EXC_CPU, "Cop unusable"},
    {CAUSE_EXCMASK, EXC_OV, "Overflow"},
    {CAUSE_EXCMASK, EXC_TRAP, "Trap"},
    {CAUSE_EXCMASK,
     EXC_VCEI,
     "Virtual coherency exception on intruction fetch"},
    {CAUSE_EXCMASK, EXC_FPE, "Fp exception"},
    {CAUSE_EXCMASK, EXC_WATCH, "Watchpoint"},
    {CAUSE_EXCMASK, EXC_VCED, "Virtual coherency exception on data reference"},
    {0, 0, ""},
};

/*
 * Status register
 */
static regDesc_t srDesc[] = {
    {SR_CU3, SR_CU3, "CU3"},
    {SR_CU2, SR_CU2, "CU2"},
    {SR_CU1, SR_CU1, "CU1"},
    {SR_CU0, SR_CU0, "CU0"},
    {SR_RP, SR_RP, "RP"},
    {SR_FR, SR_FR, "FR"},
    {SR_RE, SR_RE, "RE"},
    {SR_BEV, SR_BEV, "BEV"},
    {SR_TS, SR_TS, "TS"},
    {SR_SR, SR_SR, "SR"},
    {SR_CH, SR_CH, "CH"},
    {SR_CE, SR_CE, "CE"},
    {SR_DE, SR_DE, "DE"},

    /*
     * Interrupt enable bits
     * (NOTE: bits set to 1 enable the corresponding level interrupt)
     */

    {SR_IBIT8, SR_IBIT8, "IM8"},
    {SR_IBIT7, SR_IBIT7, "IM7"},
    {SR_IBIT6, SR_IBIT6, "IM6"},
    {SR_IBIT5, SR_IBIT5, "IM5"},
    {SR_IBIT4, SR_IBIT4, "IM4"},
    {SR_IBIT3, SR_IBIT3, "IM3"},
    {SR_IBIT2, SR_IBIT2, "IM2"},
    {SR_IBIT1, SR_IBIT1, "IM1"},
    {SR_KX, SR_KX, "KX"},
    {SR_SX, SR_SX, "SX"},
    {SR_UX, SR_UX, "UX"},
    {SR_KSU_MASK, SR_KSU_USR, "USR"},
    {SR_KSU_MASK, SR_KSU_SUP, "SUP"},
    {SR_KSU_MASK, SR_KSU_KER, "KER"},
    {SR_ERL, SR_ERL, "ERL"},
    {SR_EXL, SR_EXL, "EXL"},
    {SR_IE, SR_IE, "IE"},
    {0, 0, ""}
};

/*
 * floating-point status register
 */
static regDesc_t fpcsrDesc[] = {
    {FPCSR_FS, FPCSR_FS, "FS"},
    {FPCSR_C, FPCSR_C, "C"},
    {FPCSR_CE, FPCSR_CE, "Unimplemented"},
    {FPCSR_CV, FPCSR_CV, "Invalid op"},
    {FPCSR_CZ, FPCSR_CZ, "/ by 0.0"},
    {FPCSR_CO, FPCSR_CO, "Overflow"},
    {FPCSR_CU, FPCSR_CU, "Underflow"},
    {FPCSR_CI, FPCSR_CI, "Inexact op"},
    {FPCSR_EV, FPCSR_EV, "EV"},
    {FPCSR_EZ, FPCSR_EZ, "EZ"},
    {FPCSR_EO, FPCSR_EO, "EO"},
    {FPCSR_EU, FPCSR_EU, "EU"},
    {FPCSR_EI, FPCSR_EI, "EI"},
    {FPCSR_FV, FPCSR_FV, "FV"},
    {FPCSR_FZ, FPCSR_FZ, "FZ"},
    {FPCSR_FO, FPCSR_FO, "FO"},
    {FPCSR_FU, FPCSR_FU, "FU"},
    {FPCSR_FI, FPCSR_FI, "FI"},
    {FPCSR_RM_MASK, FPCSR_RM_RN, "RN"},
    {FPCSR_RM_MASK, FPCSR_RM_RZ, "RZ"},
    {FPCSR_RM_MASK, FPCSR_RM_RP, "RP"},
    {FPCSR_RM_MASK, FPCSR_RM_RM, "RM"},
    {0, 0, ""}
};

void *g_StackPtrs1[STACK_POINTER_COUNT] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

#ifndef VERSION_EU
void *g_StackPtrs2[STACK_POINTER_COUNT] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &sp_debug};
#else
// no sp_debug
void *g_StackPtrs2[STACK_POINTER_COUNT] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &cfb_16};
#endif

void *g_StackPtrs3[STACK_POINTER_COUNT] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

// 71 x 32 text buffer (32th line is not drawn)
unsigned char g_DebugOutputTextBuffer[32][71] = {0};

static s32 g_DebugOutputCurrentPosX = 0;
static s32 g_DebugOutputCurrentPosY = 0;

// 4 x 7 bitmaps of ascii characters (0x20 - 0x7E), each padded to 32 bits
u32 g_DebugOutputBitmaps[] = {
    0x00000000, 0x22220200, 0x55000000, 0x05F5F500, 0x27427200,     // ' ',  '!',  '\"', '#',  '$'
    0x05124500, 0x34255300, 0x22000000, 0x24444420, 0x42222240,     // '%',  '&',  '\'', '(',  ')'
    0x06F6F600, 0x00272000, 0x00000240, 0x00070000, 0x00000200,     // '*',  '+',  '\,',  '-',  '.'
    0x11224480, 0x25555200, 0x26222700, 0x25125700, 0x61211600,     // '/',  '0',  '1',  '2',  '3'
    0x33557300, 0x64611600, 0x24655200, 0x71112200, 0x25755200,     // '4',  '5',  '6',  '7',  '8'
    0x25531600, 0x00200200, 0x00200640, 0x01242100, 0x00707000,     // '9',  ':',  ';',  '<',  '='
    0x04212400, 0x07120200, 0x25FF5700, 0x02557D00, 0x06575E00,     // '>',  '?',  '@',  'A',  'B'
    0x07445300, 0x07555600, 0x07565700, 0x07564400, 0x07C95700,     // 'C',  'D',  'E',  'F',  'G'
    0x05575500, 0x07222700, 0x03111600, 0x05665500, 0x04445F00,     // 'H',  'I',  'J',  'K',  'L'
    0x0DFF9D00, 0x0F777D00, 0x07DD5700, 0x07564600, 0x07995770,     // 'M',  'N',  'O',  'P',  'Q'
    0x07565500, 0x07461E00, 0x07222200, 0x0D999600, 0x0D552200,     // 'R',  'S',  'T',  'U',  'V'
    0x0DF77500, 0x0D625500, 0x05622600, 0x07125700, 0x32222230,     // 'W',  'X',  'Y',  'Z',  '['
    0x44222110, 0x62222260, 0x25000000, 0x00000700, 0x42200000,     // '\\', ']',  '^',  '_',  '`'
    0x0067D700, 0x44755700, 0x00788600, 0x117DD700, 0x006FC700,     // 'a',  'b',  'c',  'd',  'e'
    0x32722700, 0x007DD730, 0x44755500, 0x02622700, 0x02711130,     // 'f',  'g',  'h',  'i',  'j',
    0x44766500, 0x62222700, 0x00FFFF00, 0x00755D00, 0x006DD600,     // 'k',  'l',  'm',  'n',  'o'
    0x00755740, 0x00799710, 0x00744600, 0x00775700, 0x02722300,     // 'p',  'q',  'r',  's',  't'
    0x00555700, 0x00552200, 0x00577500, 0x00562500, 0x00552220,     // 'u',  'v',  'w',  'x',  'y'
    0x00703700, 0x12242210, 0x02222220, 0x42212240, 0x005A0000      // 'z',  '{',  '|',  '}',  '~'
};

u16 *g_DebugOutputVideoBuffer1 = NULL;
u16 *g_DebugOutputVideoBuffer2 = NULL;

// Padding
u32 D_80024184[4] = {0};

/**
 * DebConTextPos
 * Sets the position where text will be displayed inside console window
 * (Does not draw - see print_to_vidbuff1)
 * @param x: column in which to display text (0-71)
 * @param y: line in which to display text (0-31)
 * @param c: Character to Print
 */
void deboutWriteCharAtPos(s32 x, s32 y, unsigned char c)
{
    // replace tabs and line feeds with nothing
    if ((c == '\t') || (c == '\n'))
    {
        c = '\0';
    }
    // is printable char? if not replace with "?"
    if ((c > '\0') && (c < ' ') || (c > '~'))
    {
        c = '?';
    }
    if (((x >= 0) && (x <= 71)) && ((y >= 0) && (y <= 31)))
    {
        // Debug Window is 71 chars wide 32 rows high
        //! BUG 71 is accepted as xpos but will overflow the buffer
        g_DebugOutputTextBuffer[y][x] = c;
    }
}

/**
 * deboutWriteChar
 * Parse Character and save to On-Screen Buffer
 * @param c: Character to parse
 */
void deboutWriteChar(unsigned char c)
{
    if (c != '\0')
    {
        if (c == '\t')
        {
            do
            {
                deboutWriteChar(' '); // fill with blanks
            } while (g_DebugOutputCurrentPosX & 7);

            return;
        }
        if (c == '\n')
        {
            g_DebugOutputCurrentPosY++;
            g_DebugOutputCurrentPosX = 0;
        }
        if (g_DebugOutputCurrentPosY > 30)
        {
            deboutScrollUp(g_DebugOutputCurrentPosY - 30);
            g_DebugOutputCurrentPosY = 30;
        }
        if (c != '\n')
        {
            deboutWriteCharAtPos(g_DebugOutputCurrentPosX, g_DebugOutputCurrentPosY, c);
            g_DebugOutputCurrentPosX++;
            if (g_DebugOutputCurrentPosX > 70)
            {
                g_DebugOutputCurrentPosX = 0;
                g_DebugOutputCurrentPosY++;
            }
        }
    }
}

/**
 * Scroll Buffer up by a number of lines
 * @param LinesToScroll: Number of Lines to scroll upward
 */
void deboutScrollUp(s32 numlines)
{
    s32 y;
    s32 x;
    while (numlines-- > 0)
    {
        for (y = 0; y < 31; y++)
        {
            for (x = 0; x < 71; x++)
            {
                g_DebugOutputTextBuffer[y][x] = g_DebugOutputTextBuffer[y + 1][x];
            }
        }
    }
}
/**
 * Print 4x8 1bit Glyph to stderr screen at position (x,y)
 * @param x: Pixels from left within the stderr box
 * @param y: Pixels from top within the stderr box
 * @param c: the character to display
 */
void deboutDrawChar(s32 x, s32 y, unsigned char c)
{
    s32  bitmap_x;
    s32  bitmap_y;
    u32  bitmap;
    s16  screen_w = viGetX();
    u16 *Vidbufp;
    if (c == '\0')
    {
        c = ' '; //replace nul with space
    }
    if ((c >= ' ') && (c <= '~')) //if valid char
    {
        Vidbufp = (g_DebugOutputVideoBuffer1 + x + (y * screen_w));
        bitmap  = g_DebugOutputBitmaps[c - ' '];
        for (bitmap_y = 0; bitmap_y < 7; bitmap_y++)
        {
            for (bitmap_x = 0; bitmap_x < 4; bitmap_x++)
            {
                if (bitmap & (1 << 31))
                {
                    *Vidbufp = GPACK_RGBA5551(255, 255, 255, 1);
                }
                else
                {
                    *Vidbufp = GPACK_RGBA5551(0, 0, 0, 1);
                }
                Vidbufp++;
                bitmap <<= 1; //
            }
            Vidbufp += screen_w;
            Vidbufp -= 4;
        }
    }
}

/**
 * Set pointers to video buffers 1 & 2.
 * Converts values to uncached addresses
 * @param cfba | A0000000 -> 8002417C
 * @param cfbb | A0000000 -> 80024180
 */
void deboutSetBuffers(u16 *buffer1, u16 *buffer2)
{
    g_DebugOutputVideoBuffer1 = (void *)K0_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = (void *)K0_TO_K1(buffer2);
}

/**
 * Set up the 2 16bit CFBs to Direct mapped, uncached memory
 */
void deboutInitBuffers(void)
{
    deboutSetBuffers(&cfb_16[0], &cfb_16[1]);
}

/**
 * deboutDrawToBuffer
 * write stderr to video buffer
 * @param buffer: video buffer to render output 
 */
void deboutDrawToBuffer(u16 *buffer)
{
    s32 screen_w;
    s32 screen_h;
    s32 output_w;
    s32 output_h;
    s32 x;
    s32 y;
    deboutInitBuffers();
    g_DebugOutputVideoBuffer1 = (void *)K0_TO_K1(buffer); // overwrite cfba
    screen_w                  = ((viGetX() - 13) / 4);
    screen_h                  = ((viGetY() - 10) / 7);
    output_w                  = screen_w - 5; // - margin_w
    output_h                  = screen_h - 1; // - margin_h
    for (y = 0; ((y < output_h) && (y < 31)); y++)
    {
        for (x = 0; ((x < output_w) && (x < 71)); x++)
        {
            deboutDrawChar(((x + 5) * 4), ((y + 1) * 7), g_DebugOutputTextBuffer[y][x]);
        }
    }
}
