#ifndef _GLOBALIMAGETABLE_H_
#define _GLOBALIMAGETABLE_H_
#include <ultra64.h>
#include <bondtypes.h>

enum MONIMGIDS {
    IMGBOND, //0x0
    IMGLOCATION,
    IMGBEGINARMING,
    IMGTARGET,
    IMGSEVERNAYA, //0x4
    IMGBREAKTARGET,
    IMGAIMER,
    IMGEARTH,
    IMGDESKTOPBANG, //0x8
    IMGHEATMAP,
    IMG3DMATH,
    IMGDESKTOPBARS,
    IMG2DMATH, //0xC
    IMGSATELLITE,
    IMGDESKTOP,
    IMGDESKTOPSTAGGERED,
    IMGCUBE1, //0x10
    IMGSHUTTLE1,
    IMGSHUTTLE2,
    IMGEARTHFULL1,
    IMGEARTHFULL2, //0x14
    IMGBLUESTARS,
    IMGGALAXY1,
    IMGGALAXY2,
    IMGEARTHTEXT, //0x18
    IMGTARGETEARTH,
    IMGGALAXY3,
    IMGSTATIC,
    IMGSINE, //0x1C
    IMGTEXT,
    IMGBARS,
    IMGSQUARES,
    IMGFIST1, //0x20
    IMGFIST2,
    IMGFIST3,
    IMGFIST4,
    IMGSKATEBOARD4, //0x24
    IMGSKATEBOARD1,
    IMGSKATEBOARD2,
    IMGSKATEBOARD3,
    IMGTALK1, //0x28
    IMGTALK2,
    IMGTALK3,
    IMGTALK4,
    IMGWORLDMAP, //0x2C
    IMGCUBE2,
    IMGCUBE3,
    IMGCUBE4,
    IMGTRIANGLE, //0x30
    IMGKEYBOARDKEY
};



extern Gfx globalDL_0x000;
extern Gfx globalDL_0x078;
extern Gfx globalDL_0x120;
extern Gfx globalDL_0x1c8;
extern Gfx globalDL_0x270;
extern Gfx globalDL_0x318;
extern Gfx globalDL_0x3c0;
extern Gfx globalDL_0x468;
extern Gfx globalDL_0x510;
extern Gfx globalDL_0x5b8;
extern Gfx globalDL_0x660;
extern Gfx globalDL_0x708;
extern Gfx globalDL_0x7b0;
extern Gfx globalDL_0x858;
extern Gfx globalDL_0x900;
extern Gfx globalDL_0x9a8;
extern Gfx globalDL_0xa50;
extern sImageTableEntry s_genericimage[];
extern sImageTableEntry s_impactimages[];
extern sImageTableEntry s_explosion_smokeimages[];
extern sImageTableEntry s_scattered_explosions[];
extern sImageTableEntry s_flareimage1[];
extern sImageTableEntry s_flareimage2[];
extern sImageTableEntry s_flareimage3[];
extern sImageTableEntry s_flareimage4[];
extern sImageTableEntry s_flareimage5[];
extern sImageTableEntry s_ammo9mmimage[];
extern sImageTableEntry s_rifleammoimage[];
extern sImageTableEntry s_shotgunammoimage[];
extern sImageTableEntry s_knifeammoimage[];
extern sImageTableEntry s_glammoimage[];
extern sImageTableEntry s_rocketammoimage[];
extern sImageTableEntry s_genericmineammoimage[];
extern sImageTableEntry s_grenadeammoimage[];
extern sImageTableEntry s_magnumammoimage[];
extern sImageTableEntry s_goldengunammoimage[];
extern sImageTableEntry s_remotemineammoimage[];
extern sImageTableEntry s_timedmineammoimage[];
extern sImageTableEntry s_proxmineammoimage[];
extern sImageTableEntry s_tankammoimage[];
extern sImageTableEntry s_crosshairimage[];
extern sImageTableEntry s_betacrosshairimage[];
extern sImageTableEntry s_glassoverlayimage[];
extern sImageTableEntry s_monitorimages[];
extern sImageTableEntry s_skywaterimages[];
extern sImageTableEntry s_mainfolderimages[];
extern sImageTableEntry s_mpradarimages[];
extern sImageTableEntry s_mpcharselimages[];
extern sImageTableEntry s_mpstageselimages[];

#endif
