#ifndef _PD_OBJ_TYPES_
#define _PD_OBJ_TYPES_

#include "Rare.h"

/*defines structures for each known PD OBJ type
  maybe some other object-related things too*/
#ifdef __cplusplus /*my compiler fries without this*/
extern "C" {
#endif

#ifndef _GE_OBJ_TYPES_
/*this attaches pnemonics to all the object archetypes
  being tricky here; if GEtypes.h is linked first, then ignore PD
  yes, I'm already aware the mess this makes...*/

/*PD archetype list; note that all loading animations (lod) use same ID as weapon!*/
/*enum{
     STD_OBJ=2,
     CHR_OBJ=3,
     CTRL=4,
     UZI_GUN=5,  //NOTE: GE uzi only
     STD_GUN=7,  //NOTE: used by most GE weapons
     ACTOR=9,
     HEAD=0xD,
     CAM=0xF,
     TV1=0x14,
     AUTOGUN=0x16,
     ACTOR_SKEDAR=0x1C,
     GUN_PC=0x23,
     GUN_K7=0x24,
     GUN_FALCON=0x25,
     GUN_KNIFE=0x26,
     ACTOR_DRCARROL=0x28,
     ACTOR_EYESPY=0x2A,
     GUN_CMP150=0x46,
     GUN_DRAGON=0x47,
     GUN_SDRAGON=0x48,
     GUN_RLAUNCH=0x49,
     GUN_SHOTGUN=0x4B,
     GUN_FARSIGHT=0x4C,
     GUN_REAPER=0x4E,
     GUN_MAULER=0x64,
     GUN_GLAUNCH=0x65,
     GUN_LEE=0x66,		//NOTE: also includes GE handguns
     GUN_AR34=0x67,
     GUN_MAGNUM=0x68,
     GUN_SRLAUNCH=0x69,
     GUN_CYCLONE=0x6A,
     GUN_SNIPE=0x6B,
     GUN_DRUG=0x6C,
     GUN_CROSSBOW=0x6D,
     GUN_PTMINE=0x6E,
     GUN_PHOENIX=0x6F,
     GUN_CALLISTO=0x70,
     GUN_RCP120=0x71,
	 GUN_GRENADE=0x73
     GUN_RMINE=0x76;
     ARM=0xFA,

     
     TV4=0x8003A084,
     RACK=0x8003A0B0,
     EYE_DOOR=0x8003A100,
     IRIS_DOOR=0x8003A15C,
     MENU=0x8003A170,
     CAR=0x8003A19C,
     AIR=0x8003A1C8,
     WIN_DOOR=0x8003A1DC,
     TANK=0x8003A208,
     HAT=0x8003A21C,
     RARE=0x8003C570,
     NULL_OBJ=0x8003C728,
     BARREL_GUN=0x8003C76C,
     };*/
#endif

/*Specific type data follows*/
/*type 01  0xC  main object heading*/
typedef struct{
        long group;
        float unknown1;
        unsigned long RESERVED;
        } PD01;

/*type 02 0x18   position*/
typedef struct{
        float xpos;
        float ypos;
        float zpos;
        unsigned short grp1;
        unsigned short grp2;
        unsigned short grp3;
        unsigned short grp4;
        float unknown;
        } PD02;

/*type 04 0x14   display list*/
typedef struct{
        unsigned long DL1;
        unsigned long DL2;
        unsigned short grp1;
        unsigned short grp2;
        unsigned long PIN;
        unsigned short pinnum;
        unsigned short rgbOPnum;    /*number of RGB(07) ops in DLs*/
        } PD04;

/*type 08 0x10   distance trigger*/
typedef struct{
        float min;
	    float max;
        unsigned long target;
        } PD08;

/*type 0A 0x1C   dimentions*/
typedef struct{
        long group;
        float xmin;
        float xmax;
        float ymin;
        float ymax;
        float zmin;
        float zmax;
        } PD0A;

/*type 0C 0x28   gunfire*/
typedef struct{
        float xpos;
        float ypos;
        float zpos;
        float xdim;
        float ydim;
        float zdim;
        unsigned long imgdecl;
        float unknown;
        unsigned long unknown1;
        unsigned long unknown2;
        } PD0C;

/*type 11 0x20   unknown*/
typedef struct{
        unsigned long unknown1;
        unsigned long unknown2;
        unsigned long unknown3;
        unsigned long unknown4;
        unsigned long unknown5;
        unsigned short unknown6;
        unsigned short value;
        unsigned long unknown7;
        unsigned long unknown8;
        } PD11;

/*type 12 0x8    handle*/
typedef struct{
        unsigned long target;
        unsigned long RESERVED;
        } PD12;

/*type 15 0x14   position - held items, especially*/
typedef struct{
        float xpos;
        float ypos;
        float zpos;
        unsigned short grp1;
        unsigned short grp2;
        float unknown;
        } PD15;

/*type 16 0x10   display list - simple*/
typedef struct{
        unsigned short unknown;
        unsigned short ID;
        unsigned long PIN;
        unsigned long DL;
        unsigned long RESERVED;
        } PD16;

/*type 17 0x4    placeholder for pointer to head*/
typedef unsigned long PD17;

/*type 18 0x18   display list*/
typedef struct{
        unsigned long DL1;
        unsigned long DL2;
        unsigned long unknown1;
        unsigned long PIN;
        unsigned short PINnum;
        unsigned short TAG;
        unsigned short unknown2;
        unsigned short RGBnum;
        } PD18;

#ifdef __cplusplus
}
#endif
#endif  /*_PD_OBJ_TYPES_*/
