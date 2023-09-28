#ifndef _VIDEO_H_
#define _VIDEO_H_
#include <ultra64.h>

#define NUM_VIDEO_FRAME_BUFFERS    2
#define NUM_VIDEO_SETTINGS         NUM_VIDEO_FRAME_BUFFERS

#define WIDESCREEN_ASPECT ((f32)(16.0f/9.0f))


#define	SCREEN_HEIGHT_MIN   240
#define	SCREEN_HEIGHT_240   240
#define	SCREEN_HEIGHT_272   272
#define	SCREEN_HEIGHT_330   330
#define	SCREEN_HEIGHT_MAX   480
#define	SCREEN_HEIGHT_MAX_EU   572

#define SCREEN_WIDTH_MIN    320
#define SCREEN_WIDTH_320    320
#define SCREEN_WIDTH_440    440
#define SCREEN_WIDTH_MAX    640

#define VIEWPORT_WIDTH_FULLSCREEN SCREEN_WIDTH_320
#define VIEWPORT_WIDTH_WIDESCREEN SCREEN_WIDTH_320
#define VIEWPORT_WIDTH_CINEMA     SCREEN_WIDTH_320

#define SCREEN_HALF_WIDTH (SCREEN_WIDTH_320 / 2)

/* 304 = 320 - 16 ?? */
#define VIEWPORT_HEIGHT_FULLSCREEN 304
#define VIEWPORT_HEIGHT_WIDESCREEN 248
#define VIEWPORT_HEIGHT_CINEMA     190

#define VIEWPORT_HEIGHT_DEFAULT_NTSC    220
#define VIEWPORT_HEIGHT_DEFAULT_PAL     272

#define VIEWPORT_OFFSET_HEIGHT_WIDESCREEN_NTSC 180
#define VIEWPORT_OFFSET_HEIGHT_WIDESCREEN_PAL  216

#define VIEWPORT_OFFSET_HEIGHT_CINEMA_NTSC     136
#define VIEWPORT_OFFSET_HEIGHT_CINEMA_PAL      162

/* 159 = (640 / 4) - 1 */
#define VIEWPORT_WIDTH_4P 159
/* 109 = (440 / 4) - 1 */
#define VIEWPORT_HEIGHT_4P_109 109
/* PAL */
#define VIEWPORT_HEIGHT_4P_135 135

#define WIDESCREEN_SCALE_FACTOR_NTSC 40.0f
#define WIDESCREEN_SCALE_FACTOR_PAL  56.0f

#define CINEMA_SCALE_FACTOR_NTSC  84.0f
#define CINEMA_SCALE_FACTOR_PAL  110.0f

#define WIDESCREEN_ULY_SCALE_FACTOR_NTSC -20.0f
#define WIDESCREEN_ULY_SCALE_FACTOR_PAL  -29.0f

#define CINEMA_ULY_SCALE_FACTOR_NTSC -42.0f
#define CINEMA_ULY_SCALE_FACTOR_PAL  -52.0f


#define VIEWPORT_ULY_2P_PLAYER_1       10

#define VIEWPORT_ULY_2P_PLAYER_2_NTSC       121
#define VIEWPORT_ULY_2P_PLAYER_2_PAL        137

#define VIEWPORT_ULY_4P_PLAYER_12      10

#define VIEWPORT_ULY_4P_PLAYER_34_NTSC      121
#define VIEWPORT_ULY_4P_PLAYER_34_PAL       137

#define VIEWPORT_ULY_CAM_FULLSCREEN    13
#define VIEWPORT_ULY_CAM_WIDESCREEN    41
#define VIEWPORT_ULY_CAM_CINEMA        70

#define VIEWPORT_ULY_WIDESCREEN_OFFSET_NTSC 30
#define VIEWPORT_ULY_WIDESCREEN_OFFSET_PAL  29

#define VIEWPORT_ULY_CINEMA_OFFSET     52
#define VIEWPORT_ULY_DEFAULT           10

#define Z_BUFFER_HEIGHT_NTSC 120
#define Z_BUFFER_HEIGHT_PAL  136

#define Z_BUFFER_4_3_HEIGHT 330
#define Z_BUFFER_4_3_WIDTH  440


// 4:3
#define ASPECT_RATIO_SD    (1.3333334f)
#define ASPECT_RATIO_PAL    (1.1764706f)

#define ASPECT_RATIO_EU_400_330    (1.5873016119f)
#define ASPECT_RATIO_EU_320_272    (1.40056025982f)

#if defined(VERSION_EU)
/* PAL */
#define	SCREEN_HEIGHT                      SCREEN_HEIGHT_272
#define	VIEWPORT_HEIGHT_4P                 VIEWPORT_HEIGHT_4P_135
#define WIDESCREEN_SCALE_FACTOR            WIDESCREEN_SCALE_FACTOR_PAL
#define CINEMA_SCALE_FACTOR                CINEMA_SCALE_FACTOR_PAL
#define VIEWPORT_OFFSET_HEIGHT_WIDESCREEN  VIEWPORT_OFFSET_HEIGHT_WIDESCREEN_PAL
#define VIEWPORT_HEIGHT_DEFAULT            VIEWPORT_HEIGHT_DEFAULT_PAL
#define VIEWPORT_OFFSET_HEIGHT_CINEMA      VIEWPORT_OFFSET_HEIGHT_CINEMA_PAL
#define VIEWPORT_ULY_2P_PLAYER_2           VIEWPORT_ULY_2P_PLAYER_2_PAL
#define WIDESCREEN_ULY_SCALE_FACTOR        WIDESCREEN_ULY_SCALE_FACTOR_PAL
#define CINEMA_ULY_SCALE_FACTOR            CINEMA_ULY_SCALE_FACTOR_PAL
#define VIEWPORT_ULY_4P_PLAYER_34          VIEWPORT_ULY_4P_PLAYER_34_PAL
#define VIEWPORT_ULY_WIDESCREEN_OFFSET     VIEWPORT_ULY_WIDESCREEN_OFFSET_PAL
#define Z_BUFFER_HEIGHT                    Z_BUFFER_HEIGHT_PAL
#define ASPECT_RATIO                       ASPECT_RATIO_PAL
#else
/* NTSC */
#define	SCREEN_HEIGHT                      SCREEN_HEIGHT_240
#define	VIEWPORT_HEIGHT_4P                 VIEWPORT_HEIGHT_4P_109
#define WIDESCREEN_SCALE_FACTOR            WIDESCREEN_SCALE_FACTOR_NTSC
#define CINEMA_SCALE_FACTOR                CINEMA_SCALE_FACTOR_NTSC
#define VIEWPORT_OFFSET_HEIGHT_WIDESCREEN  VIEWPORT_OFFSET_HEIGHT_WIDESCREEN_NTSC
#define VIEWPORT_HEIGHT_DEFAULT            VIEWPORT_HEIGHT_DEFAULT_NTSC
#define VIEWPORT_OFFSET_HEIGHT_CINEMA      VIEWPORT_OFFSET_HEIGHT_CINEMA_NTSC
#define VIEWPORT_ULY_2P_PLAYER_2           VIEWPORT_ULY_2P_PLAYER_2_NTSC
#define WIDESCREEN_ULY_SCALE_FACTOR        WIDESCREEN_ULY_SCALE_FACTOR_NTSC
#define CINEMA_ULY_SCALE_FACTOR            CINEMA_ULY_SCALE_FACTOR_NTSC
#define VIEWPORT_ULY_4P_PLAYER_34          VIEWPORT_ULY_4P_PLAYER_34_NTSC
#define VIEWPORT_ULY_WIDESCREEN_OFFSET     VIEWPORT_ULY_WIDESCREEN_OFFSET_NTSC
#define Z_BUFFER_HEIGHT                    Z_BUFFER_HEIGHT_NTSC
#define ASPECT_RATIO                       ASPECT_RATIO_SD
#endif


#define SCREEN_WIDTH      SCREEN_WIDTH_320

#define XSCALE_MAX      0x400
#define YSCALE_MAX      0x800

#define FOV_Y_F         60.0f

typedef struct VideoSettings_s {
    /**
     * enum VIDEOMODE.
     */
    u8 mode;
    s8 field_01;
    s8 field_02;
    s8 field_03;
    s16 x;
    s16 y;
    f32 fovy;
    f32 aspect;
    f32 znear;
    f32 zfar;

    /**
     * Screen width.
     */
    s16 bufx;

    /**
     * Screen height.
     */
    s16 bufy;
    s16 viewx;
    s16 viewy;
    s16 viewleft;
    s16 viewtop;
    s32 usezbuf;
    u8* framebuf;
} VideoSettings;

extern OSViMode *viMode;
extern u32 g_viOriginalHstart;
extern u32 g_viOriginalVstart0;
extern u32 g_viOriginalVstart1;
extern Mtx *g_viProjectionMatrix;

/* SCREEN_HEIGHT #define changes based on version (PAL or NTSC) */
extern u8 cfb_16[NUM_VIDEO_FRAME_BUFFERS][SCREEN_WIDTH * SCREEN_HEIGHT * 2];

void viShake(f32 param_1);

void viInitVideoSettings(void);
s16 viGetX(void);
s16 viGetY(void);
s16 viGetViewLeft(void);
s16 viGetViewTop(void);
s16 viGetViewWidth(void);
s16 viGetViewHeight(void);
u8 *viGetFrameBuf2(void);
void viSetFrameBuf2(u8 *buf);
void viSetFovY(f32 fovy);
f32 viGetFovY(void);
void viSetAspect(f32 aspect);
void viSetZRange(f32 near, f32 far);
void viSetUseZBuf(s32 usezbuf);
void viSetViewSize(s16 x, s16 y);
void viSetViewPosition(s16 left, s16 top);
void viInitBuffers(void);
void viVsyncRelated(void);
void viSetHorizontalOffset(s32 arg0);
s32 viGetHorizontalOffset(void);
void video_related_8(void);
void viSetBuf(s16 x, s16 y);
void viSetXY(s16 x, s16 y);
Gfx *viSetFillColor(Gfx *gdl, s32 r, s32 g, s32 b);
Gfx *viFillScreen(Gfx *gdl);
Gfx *viSetupScreensForNumPlayers(Gfx *gdl);

void indyGrabJpg16bit(void);
void indyGrabJpg32bit(void);
void indyGrabRgb16bit(void);
void indyGrabRgb32bit(void);

void viSetVideoMode(s32 m);
s32 viGet800232A0(void);
void viSet800232A0(s32 arg0);

Gfx *viClearZBufCurrentPlayer(Gfx *gdl);
Gfx *video_related_F(Gfx *gdl);
void viGetZRange(f32 *zrange);
#endif


