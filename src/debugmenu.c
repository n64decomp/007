#include <ultra64.h>
#include "debugmenu.h"
#include "vi.h"
#include "game/dyn.h"


#ifdef LEFTOVERDEBUG

// This is a 128 x 21 sprite of characers in greyscale at one byte per pixel.
// Each character is 4 x 7 pixels. There's 3 rows with 32 characters per row.
u32 g_DebugMenuTexture[] = {
	// space    !           "           #           $           %           &           '           (           )           *           +           ,           -           .           /           0           1           2           3           4           5           6           7           8           9           :           ;           <           =           >           ?
	0x00000000, 0x00227a00, 0x007a348b, 0x00223434, 0x00115811, 0x00696900, 0x00000000, 0x00009c00, 0x00004600, 0x00460000, 0x00004600, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00229c11, 0x00346900, 0x00229c11, 0x00699c11, 0x00005834, 0x00adad34, 0x00118b34, 0x009cad7a, 0x00229c11, 0x00229c11, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00113411,
	0x00000000, 0x0046ce00, 0x00ad58de, 0x00466969, 0x009c9c69, 0x008b8b00, 0x00469c00, 0x0022ce00, 0x00583400, 0x00345800, 0x007ace69, 0x00005800, 0x00000000, 0x00000000, 0x00000000, 0x00003446, 0x008b007a, 0x00588b00, 0x008b008b, 0x0022007a, 0x00119c69, 0x008b0000, 0x009c1100, 0x0022008b, 0x008b007a, 0x008b007a, 0x00000000, 0x00000000, 0x00225869, 0x00000000, 0x69582200, 0x009c698b,
	0x00000000, 0x0046ce00, 0x00222258, 0x00deef7a, 0x00ad1111, 0x0069ef9c, 0x008b0000, 0x00460000, 0x008b0000, 0x00008b00, 0x0058ce34, 0x00008b00, 0x00000000, 0x00000000, 0x00000000, 0x00008b00, 0x008b008b, 0x00008b00, 0x0011007a, 0x00118b46, 0x0058467a, 0x00cead22, 0x009c8b00, 0x0000117a, 0x00698b46, 0x008b00ad, 0x0034ad00, 0x0034ad00, 0x228b4600, 0x8b8b8b8b, 0x00468b22, 0x0011008b,
	0x00000000, 0x00007a00, 0x00000000, 0x009c9c00, 0x00118b34, 0x22adbd46, 0x008b8b34, 0x00000000, 0x008b0000, 0x00008b00, 0x007a2269, 0x22adef9c, 0x00000000, 0x22adadad, 0x00000000, 0x00226900, 0x008b008b, 0x00008b00, 0x00007a00, 0x0000117a, 0x009c347a, 0x0000008b, 0x00ce117a, 0x00002269, 0x008b227a, 0x00229c8b, 0x00001100, 0x00001100, 0xad580000, 0x34343434, 0x000058ad, 0x0000bd34,
	0x00000000, 0x00112200, 0x00000000, 0x22dede22, 0x00ce5858, 0x0046468b, 0x008bad00, 0x00000000, 0x008b0000, 0x00008b00, 0x00000000, 0x00008b00, 0x00003400, 0x00000000, 0x00002200, 0x00691100, 0x008b008b, 0x00008b00, 0x00691158, 0x0011008b, 0x007a9cad, 0x1122008b, 0x008b008b, 0x00008b00, 0x008b008b, 0x0000227a, 0x00002200, 0x00002200, 0x228b4600, 0x8b8b8b8b, 0x00468b22, 0x00006900,
	0x00000000, 0x00228b00, 0x00000000, 0x008b8b00, 0x0034bd00, 0x00119c46, 0x007a6969, 0x00000000, 0x00583400, 0x00345800, 0x00000000, 0x00005800, 0x0011ff00, 0x00000000, 0x00228b00, 0x008b0000, 0x00349c22, 0x008bce69, 0x22bdad8b, 0x007a9c11, 0x00008b8b, 0x118b9c11, 0x00349c22, 0x00005800, 0x00349c11, 0x00588b11, 0x00228b00, 0x0069ad00, 0x00225869, 0x00000000, 0x69582200, 0x0000bd00,
	0x00000000, 0x00000000, 0x00000000, 0x00464600, 0x00004600, 0x00000000, 0x00000000, 0x00000000, 0x00004600, 0x00460000, 0x00000000, 0x00000000, 0x00583400, 0x00000000, 0x00000000, 0x58340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x008b0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,

	// @        A           B           C           D           E           F           G           H           I           J           K           L           M           N           O           P           Q           R           S           T           U           V           W           X           Y           Z           [           \           ]           ^           _
	0x00229c11, 0x00221100, 0x11223400, 0x00003411, 0x11342200, 0x00343422, 0x00343422, 0x00002222, 0x00220022, 0x00342222, 0x00003434, 0x00341122, 0x22341100, 0x11110022, 0x22221134, 0x00002200, 0x00343411, 0x00003400, 0x00343411, 0x00113411, 0x00343434, 0x11341134, 0x11220034, 0x34220034, 0x11340022, 0x11220034, 0x00223422, 0x00008b34, 0x00460000, 0x00587a00, 0x00005800, 0x00000000,
	0x348b008b, 0x0069bd00, 0x11de7a58, 0x00ad69de, 0x22ce7a9c, 0x11ce7aad, 0x11ce7aad, 0x00ad7ade, 0x22ce00ce, 0x0069ce58, 0x00008bce, 0x22ce22ce, 0x46ce4600, 0x7abd00ff, 0x58ff46ce, 0x00ad7a9c, 0x11ce7a7a, 0x00ad7a8b, 0x22ce7a7a, 0x118b7abd, 0x469ccece, 0x8b8b34ce, 0x8b8b00bd, 0xbd8b22bd, 0x58ce00ce, 0x22bd00ce, 0x00bd7aad, 0x00008b00, 0x007a1100, 0x00008b00, 0x00694658, 0x00000000,
	0x468b7abd, 0x00588b22, 0x008b008b, 0x46460011, 0x008b007a, 0x118b3458, 0x008b3458, 0x46460011, 0x008b008b, 0x00008b00, 0x0000117a, 0x008b7a11, 0x008b0000, 0x589c58bd, 0x11ad698b, 0x4646007a, 0x118b007a, 0x5846007a, 0x118b007a, 0x46580011, 0x34228b46, 0x6934008b, 0x007a008b, 0x58348b7a, 0x11696946, 0x00695846, 0x00113458, 0x00008b00, 0x00116900, 0x00008b00, 0x00110011, 0x00000000,
	0x468b8b9c, 0x009c228b, 0x00dead7a, 0x58340000, 0x008b007a, 0x11dead00, 0x00dead00, 0x583400ad, 0x46deadbd, 0x00008b00, 0x3411117a, 0x00dead00, 0x008b0000, 0x5846ad7a, 0x118b8b8b, 0x5834007a, 0x11dead34, 0x5834007a, 0x11dede46, 0x0058ad34, 0x00008b00, 0x5834008b, 0x008b117a, 0x00bdde8b, 0x0022ad00, 0x0011bd00, 0x00226900, 0x00008b00, 0x00008b00, 0x00008b00, 0x00000000, 0x00000000,
	0x348b348b, 0x469c8bad, 0x008b007a, 0x347a0058, 0x008b009c, 0x008b008b, 0x008b0000, 0x228b007a, 0x008b008b, 0x00008b00, 0x46462269, 0x008b117a, 0x008b007a, 0x6934347a, 0x118b34de, 0x118b009c, 0x008b0000, 0x228b009c, 0x008b117a, 0x3434008b, 0x00008b00, 0x4646008b, 0x0022ce00, 0x00adbd8b, 0x008b007a, 0x00008b00, 0x008b0058, 0x00008b00, 0x00003446, 0x00008b00, 0x00000000, 0x00000000,
	0x00697a9c, 0x7a9c00bd, 0x69cead58, 0x0058ad58, 0x22bdad34, 0x22cead8b, 0x22bd2200, 0x0058ad58, 0x22ad00ce, 0x008bbd7a, 0x007a7a00, 0x22bd228b, 0x69bdadbd, 0x8b9c00bd, 0x69ce227a, 0x0058ad34, 0x22ce6900, 0x009cef69, 0x22bd2258, 0x7a9c9c22, 0x0046ce34, 0x007aad11, 0x00005800, 0x00580058, 0x22ad00ce, 0x0058bd34, 0x00ad9c9c, 0x00008b00, 0x0000008b, 0x00008b00, 0x00000000, 0x22222222,
	0x00002211, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0058588b, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000ce34, 0x0000007a, 0x1158ad00, 0x00000000, 0x7a7a7a7a,

	// `        a           b           c           d           e           f           g           h           i           j           k           l           m           n           o           p           q           r           s           t           u           v           w           x           y           z           {           |           }           ~           blank/unused
	0x00693400, 0x00000000, 0x22690000, 0x00000000, 0x0000008b, 0x00000000, 0x0000589c, 0x11000000, 0x22690000, 0x00001100, 0x00001100, 0x22690000, 0x008b7a00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00004646, 0x00004600, 0x00464600, 0x00000000, 0x00000000,
	0x0046ad00, 0x00000000, 0x008b0000, 0x00000000, 0x0000008b, 0x00000000, 0x00116900, 0x00000000, 0x008b0000, 0x00006900, 0x00006900, 0x008b0000, 0x00008b00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00226900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00008b00, 0x00008b00, 0x00008b00, 0x00000000, 0x00000000,
	0x00005800, 0x008b9c34, 0x00cead69, 0x007aad9c, 0x008badbd, 0x007aad34, 0x009cde7a, 0x008b9cce, 0x11cead69, 0x00589c00, 0x008bad69, 0x008bad69, 0x00008b00, 0x7aad9c9c, 0x22cead69, 0x007aad34, 0x22cead69, 0x008b9cde, 0x22de9c69, 0x007aad9c, 0x009cde7a, 0x118b00ad, 0x11ce00de, 0x34ce00de, 0x22ce34ad, 0x22ce00de, 0x00bd9cad, 0x00008b00, 0x00008b00, 0x00008b00, 0x229c347a, 0x00000000,
	0x00000000, 0x009cad7a, 0x008b007a, 0x69340034, 0x4634009c, 0x46ce9cbd, 0x00226900, 0x4646008b, 0x008b008b, 0x00008b00, 0x0000007a, 0x00de7a00, 0x00008b00, 0x46468b69, 0x119c008b, 0x4646008b, 0x008b0069, 0x5846008b, 0x008b0000, 0x008b7a58, 0x00226900, 0x008b008b, 0x007a117a, 0x008b8b8b, 0x0058bd00, 0x008b008b, 0x00464646, 0x00467a00, 0x00008b00, 0x00008b46, 0x7a349c22, 0x00000000,
	0x00000000, 0x4634227a, 0x009c007a, 0x58460022, 0x4646009c, 0x34460034, 0x00226900, 0x3446009c, 0x008b008b, 0x00008b00, 0x0000007a, 0x008b6911, 0x00008b00, 0x46468b69, 0x118b008b, 0x3458008b, 0x00ad0069, 0x584600ad, 0x008b0000, 0x0069348b, 0x00226911, 0x008b009c, 0x0011de00, 0x00adbd8b, 0x00699c11, 0x00469c34, 0x00225858, 0x00008b00, 0x00008b00, 0x00008b00, 0x00000000, 0x00000000,
	0x00000000, 0x119c8bce, 0x22adad58, 0x007a9c46, 0x0069adad, 0x1169ad46, 0x008bbd7a, 0x0069adad, 0x22ad00bd, 0x118bce69, 0x0000007a, 0x227a34ce, 0x008bbd7a, 0x7a699c46, 0x69bd00ce, 0x007a9c22, 0x00bd9c58, 0x0069adad, 0x22ce9c34, 0x008bad58, 0x00009c8b, 0x00699cad, 0x11005800, 0x00580069, 0x11bd349c, 0x00009c00, 0x00adad9c, 0x00008b00, 0x00008b00, 0x00008b00, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000008b, 0x00000000, 0x00000000, 0x00004646, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x008b0000, 0x0000008b, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00226900, 0x00000000, 0x00008b46, 0x00008b00, 0x00467a00, 0x00000000, 0x00000000,
};

s32 g_DebugMenuTextStartX = 5;
s32 g_DebugMenuTextStartY = 1;
s32 g_DebugMenuTextCurrentX = 24;
s32 g_DebugMenuTextCurrentY = 16;
Gfx g_DebugMenuTextureDisplayList[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetRenderMode(IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_MEM, G_BL_A_IN, G_BL_CLR_IN, G_BL_1), IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_MEM, G_BL_A_IN, G_BL_CLR_IN, G_BL_1)),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT),
    gsDPSetTexturePersp(G_TP_NONE),
    //gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPLoadTextureBlock(&g_DebugMenuTexture, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 21, 0, (G_TX_NOMIRROR | G_TX_WRAP), (G_TX_NOMIRROR | G_TX_WRAP), G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadSync(),
    gsSPEndDisplayList()
};
character g_DebugMenuTextBuffer[80][35] = {0};
Gfx g_DHudFgGbiPtrs[32] = {0};
Gfx g_DHudBgGbiPtrs[32] = {0};
s32 g_DebugMenuCurrentColorIndex = 0;

#define ANSI_COLOR_CODE_FG_BLACK   "\x1B[30m"
#define ANSI_COLOR_CODE_FG_RED     "\x1B[31m"
#define ANSI_COLOR_CODE_FG_GREEN   "\x1B[32m"
#define ANSI_COLOR_CODE_FG_YELLOW  "\x1B[33m"
#define ANSI_COLOR_CODE_FG_BLUE    "\x1B[34m"
#define ANSI_COLOR_CODE_FG_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CODE_FG_CYAN    "\x1B[36m"
#define ANSI_COLOR_CODE_FG_WHITE   "\x1B[37m"

#define ANSI_COLOR_CODE_BG_BLACK   "\x1B[40m"
#define ANSI_COLOR_CODE_BG_RED     "\x1B[41m"
#define ANSI_COLOR_CODE_BG_GREEN   "\x1B[42m"
#define ANSI_COLOR_CODE_BG_YELLOW  "\x1B[43m"
#define ANSI_COLOR_CODE_BG_BLUE    "\x1B[44m"
#define ANSI_COLOR_CODE_BG_MAGENTA "\x1B[45m"
#define ANSI_COLOR_CODE_BG_CYAN    "\x1B[46m"
#define ANSI_COLOR_CODE_BG_WHITE   "\x1B[47m"

const char *g_DebugMenuUnusedStrings[] = {
    ANSI_COLOR_CODE_FG_RED     ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_WHITE   ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_GREEN   ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_YELLOW  ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_BLUE    ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_MAGENTA ANSI_COLOR_CODE_BG_BLACK,
    ANSI_COLOR_CODE_FG_CYAN    ANSI_COLOR_CODE_BG_BLACK,

    ANSI_COLOR_CODE_FG_WHITE   ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_RED     ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_GREEN   ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_YELLOW  ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_BLACK   ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_MAGENTA ANSI_COLOR_CODE_BG_BLUE,
    ANSI_COLOR_CODE_FG_CYAN    ANSI_COLOR_CODE_BG_BLUE,

    ANSI_COLOR_CODE_FG_WHITE   ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_BLACK   ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_GREEN   ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_YELLOW  ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_BLUE    ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_MAGENTA ANSI_COLOR_CODE_BG_RED,
    ANSI_COLOR_CODE_FG_CYAN    ANSI_COLOR_CODE_BG_RED,

    ANSI_COLOR_CODE_FG_WHITE   ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_RED     ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_GREEN   ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_YELLOW  ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_BLUE    ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_BLACK   ANSI_COLOR_CODE_BG_MAGENTA,
    ANSI_COLOR_CODE_FG_CYAN    ANSI_COLOR_CODE_BG_MAGENTA,

    ANSI_COLOR_CODE_FG_WHITE   ANSI_COLOR_CODE_BG_GREEN,
    ANSI_COLOR_CODE_FG_RED     ANSI_COLOR_CODE_BG_GREEN,
    ANSI_COLOR_CODE_FG_BLACK   ANSI_COLOR_CODE_BG_GREEN,
    ANSI_COLOR_CODE_FG_YELLOW  ANSI_COLOR_CODE_BG_GREEN
};
Gfx g_DebugMenuEndDisplayList = gsSPEndDisplayList();
Gfx g_DebugMenuNoOp = gsDPNoOp();
Gfx g_DebugMenuPrimitiveColor = gsDPSetPrimColor(0, 0, 255, 255, 255, 0);
Gfx g_DebugMenuEnvironmentColor = gsDPSetEnvColor(0, 0, 0, 0);
u32 g_DebugMenuPercentage = 0xFF; // Static?
#endif

/**
 * Removed
 */
#ifdef LEFTOVERDEBUG
u32 debmenu7000AD80(s32 arg0, s32 arg1) {
    // Removed
    return 0;
}
#endif

/**
 * Removed
 */
#ifdef LEFTOVERDEBUG
u32 debmenu7000AD90(s32 arg0, s32 arg1) {
    // Removed
    return 0;
}
#endif

/**
 * Removed
 */
#ifdef LEFTOVERDEBUG
void debmenu7000ADA0(void) {
    // Removed
}
#endif

/**
 * Removed
 */
void debmenu7000ADA8(void) {
    // Removed
}

void debmenuInit(void) {
    #ifdef LEFTOVERDEBUG
    debmenuReset();
    #endif
}

#ifdef LEFTOVERDEBUG
void debmenuWriteCharAtPos(s32 x, s32 y, unsigned char c) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if ((g_DebugMenuPrimitiveColor.words.w1 == g_DHudFgGbiPtrs[i].words.w1) &&
            (g_DebugMenuEnvironmentColor.words.w1 == g_DHudBgGbiPtrs[i].words.w1)) {
            goto end;
        }
    }
    g_DHudFgGbiPtrs[g_DebugMenuCurrentColorIndex] = g_DebugMenuPrimitiveColor;
    g_DHudBgGbiPtrs[g_DebugMenuCurrentColorIndex] = g_DebugMenuEnvironmentColor;
    g_DebugMenuCurrentColorIndex = ((g_DebugMenuCurrentColorIndex + 1) % 32);
    i = g_DebugMenuCurrentColorIndex;
end:
    g_DebugMenuTextBuffer[x][y].chr = c;
    g_DebugMenuTextBuffer[x][y].color = i;
}
#endif

void debmenuResetPosition(void) {
    #ifdef LEFTOVERDEBUG
    g_DebugMenuTextCurrentX = g_DebugMenuTextStartX;
    g_DebugMenuTextCurrentY = g_DebugMenuTextStartY;
    #endif
}

void debmenuReset(void) {
    #ifdef LEFTOVERDEBUG
    s32 x;
    s32 y;
    for (y = 0; y < 35; y++) {
        for (x = 0; x < 80; x++) {
            debmenuWriteCharAtPos(x, y, '\0');
        }
    }
    debmenuResetPosition();
    debmenu7000ADA0();
    g_DebugMenuCurrentColorIndex = 0;
    #endif
}

/**
 * Removed.
 * Called from debmenu7000AF98
 */
#ifdef LEFTOVERDEBUG
void debmenu7000AF84(s32 x1, s32 y1, s32 x2, s32 y2) {
    // Removed
}
#endif


void debmenu7000AF98(s32 height)
{
#ifdef LEFTOVERDEBUG
    s32 x;
    s32 y;

    for (y = 34, height += y - 1; y--; height-- )
    {
        if ((height >= 0) && (height < 35))
        {
            for ( x = 0; x != 80; x++)
            {
                debmenu7000AF84(x, height, x, y);
            }
        }
        else
        {
            for (x = 0; x != 80; x++)
            {
                debmenuWriteCharAtPos(x, y, 0);
            }
        }
    }
#endif
}


/*
* Address: 0x7000b040
*/
void debmenuSetPos(s32 x, s32 y) {
    #ifdef LEFTOVERDEBUG
    x += g_DebugMenuTextStartX;
    y += g_DebugMenuTextStartY;
    g_DebugMenuTextCurrentX = x;
    g_DebugMenuTextCurrentY = y;
    #endif
}

void debmenuSetFgColour(s32 r, s32 g, s32 b, s32 a) {
    #ifdef LEFTOVERDEBUG
    g_DebugMenuPrimitiveColor.words.w1 = ((r << 24) | (g << 16) | (b << 8) | (255 - a));
    #endif
}

void debmenuSetEnvColor(s32 r, s32 g, s32 b, s32 a) {
    #ifdef LEFTOVERDEBUG
    g_DebugMenuEnvironmentColor.words.w1 = ((r << 24) | (g << 16) | (b << 8) | (255 - a));
    #endif
}

void debmenuWriteChar(unsigned char c) {
    #ifdef LEFTOVERDEBUG
    s32 width = ((viGetX() - 13) / 4);
    s32 height = ((viGetY() - 10) / 7);
    if ((c == '\0') || ((c >= ' ') && (c <= '~'))) {
        debmenuWriteCharAtPos(g_DebugMenuTextCurrentX, g_DebugMenuTextCurrentY, c);
    }
    g_DebugMenuTextCurrentX++;
    if ((c == '\r') || (c == '\n') || (g_DebugMenuTextCurrentX >= width)) {
        g_DebugMenuTextCurrentX = g_DebugMenuTextStartX;
        g_DebugMenuTextCurrentY++;
        if (g_DebugMenuTextCurrentY >= height) {
            g_DebugMenuTextCurrentY = g_DebugMenuTextStartY;
        }
    }
    #endif
}

void debmenuSetPositionAndWriteChar(s32 x, s32 y, unsigned char c)
{
    #ifdef LEFTOVERDEBUG
    debmenuSetPos(x, y);
    debmenuWriteChar(c);
    #endif
}

void debmenuPrintString(const unsigned char *str) {
    #ifdef LEFTOVERDEBUG
    while (*str != '\0') {
        debmenuWriteChar(*str++);
    }
    #endif
}

void debmenuSetPositionAndWriteString(s32 x, s32 y, const unsigned char *str) {
    #ifdef LEFTOVERDEBUG
    debmenuSetPos(x, y);
    while (*str != '\0') {
        debmenuWriteChar(*str++);
    }
    #endif
}


/*
* Address: 0x7000b27c
*/
Gfx *debmenuDraw(Gfx *gdl)
{
#if defined(LEFTOVERDEBUG)

	s32 y;
    s32 x;
	s32 appliedpaletteindex;
	s32 needed;
	s32 available;
	Gfx *gdl2;

	// Calculate how much space is needed in the display list
	// based on the number of characters to draw and the number
	// of times the colours will be changed.
	gdl2 = gdl;
	appliedpaletteindex = -1;

	for (y = 0; y < 35; y++)
    {
		for (x = 0; x < 80; x++)
        {
			u32 c = g_DebugMenuTextBuffer[x][y].chr;
			s32 paletteindex = g_DebugMenuTextBuffer[x][y].color;

			if (c != '\0')
            {
				if (paletteindex != appliedpaletteindex)
                {
					gdl2 += 2;
					appliedpaletteindex = paletteindex;
				}

				if (1)
                {
				    gdl2 += 3;
                }
			}
		}
	}

	// Make sure there'll be a least 256 GBI commands free (2KB)
	available = dynGetFreeGfx(gdl) - 256 * sizeof(Gfx);
	needed = (u32)gdl2 - (u32)gdl;

	if (needed <= 0) { // shouldn't be possible
		return gdl;
	}

    if(1)
	{
		s32 appliedpaletteindex = -1;

		// Write a "g_DebugMenuPercentage" (out of 255) into a global variable
		// which shows how much of the displaylist will be committed,
		// provided 2KB is kept free.
		if (available <= 0)
        {
			// There's already less than 2KB free in the display list
			g_DebugMenuPercentage = 0;
		}
        else if (needed > available)
        {
			// The display list would end with less than 2KB free,
			// so calculate the g_DebugMenuPercentage
			g_DebugMenuPercentage = available * 255 / needed;
		}
        else
        {
			// The display list would end with at least 2KB free,
			// so the displaylist can be committed in full
			g_DebugMenuPercentage = 256;
		}

		gSPDisplayList(gdl++, g_DebugMenuTextureDisplayList);

        // Build the display list for real this time.
		// Regardless of the availability checks above, just stop when
		// there's less than 1KB of free space... sort of. It still writes
		// the colour change commands, but the debug HUD doesn't exactly
		// draw rainbows so it's no big deal.
		for (y = 0; y < 35; y++)
        {
            s32 x;
			for (x = 0; x < 80; x++)
            {
				u32 c = g_DebugMenuTextBuffer[x][y].chr;
				s32 paletteindex = g_DebugMenuTextBuffer[x][y].color;

                if(x == 80);

                if (c != '\0')
                {
                    if (paletteindex != appliedpaletteindex)
                    {
                        *gdl = g_DHudFgGbiPtrs[paletteindex];
                        gdl++;
						*gdl = g_DHudBgGbiPtrs[paletteindex];
                        gdl++;
						appliedpaletteindex = paletteindex;
					}

#ifndef DEBUGMENU
                    if ((randomGetNext() & 0xFF) < g_DebugMenuPercentage )
#else
                    if(1)
#endif
                    {
				    	if (dynGetFreeGfx(gdl) >= 1024)
                        {

				    		gSPTextureRectangle(gdl++,
                                // Screen coords to draw at
                                x * 4 * 4,
                                y * 7 * 4,
                                x * 4 * 4 + 4 * 4,
                                y * 7 * 4 + 7 * 4,
                                G_TX_RENDERTILE,
                                // Sprite X and Y positions
                                ((c - ' ') % 32) * 4 * 32,
                                ((s32)(c - ' ') >> 5) * 7 * 32,
                                1024,
                                1024);
				    	}
                    }
				}

                if (appliedpaletteindex == 1);
                if(y);
			}
		}
	}

#endif // defined(LEFTOVERDEBUG)

    return gdl;
}
