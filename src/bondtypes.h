/*
 * Notes:
 * Hacky structures allows coords/rgb etc to be accessed using
 * coord->x, coord->y and coord->z, but also as
 * coord->AsArray[0], coord->AsArray[1] and coord->AsArray[2] or
 * u32 rgba = rgba.AsInteger
 *
 * In some places code only matches when using the float array.
 * Resources of the time including SDK use array.
 * Sometimes its nice to be verbose and see the structures instead of
 * random arrays or conglomerate integers.
 *
 * 
 * While typedefs are used to avoid typing "struct" and to help intellisence
 * they are not foolproof.
 * Using structs before they are declaired need to have the struct keyword or
 * be re-ordered.
 *
 * Structs that "inherit" other structs can use the syntax
 *     struct A {int adef};
 *     struct B {inherits A; int extra};
 * 
 * using adef from B is as simple as calling B->adef, no need for sub-structs anymore
 */
#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include <ultra64.h>
#include <bondconstants.h>
#include "snd.h"
#include "game/chrobjdata.h"

/**
 * Syntax Sugar for clarification of intent
 * Inheritance allows child structs to directly use parent elements 
 * without sub-struct style calls 
 *     obj->type and wep->base.type becomes simply 
 *     obj->type and wep->type (wep inherits obj)
 * Usage:
 * Define the first entry to the inheriting struct as "inherits xxx"
 * to inherit all elements of xxx
 */
#define inherits struct


/*
 * Use of int is faster than char (1 less instruction)
 * If Sepertion of OS from Game means that it is undesirable to edit this file
 * then move bool to bondtypes.h
 */
typedef s32 bool; /* Boolean (TRUE/FALSE) */
typedef u32 romptr_t;
struct object_standard;
struct ChrRecord;
struct PropRecord;
struct ObjectRecord;
struct WeaponObjRecord;
struct WeaponObjRecordExtended;
union ModelRoData;

/**
 * The following region deals with various AI structures that can be applied to 
 * the AI bytestream
 */
#pragma region AI

typedef struct AIRecord
{
    u8 cmd;
    u8 val[];
} AIRecord;
typedef struct AIRecord1
{
    u8 cmd;
    u8 val;
} AIRecord1;
typedef struct AIRecord1s
{
    u8 cmd;
    s8 val;
} AIRecord1s;

typedef struct AIListRecord
{
    AIRecord *ailist;
    int       ID;
} AIListRecord;

#pragma endregion AI

/**
 * This region contains all geometry related structures (points colours and volumes)
 */
#pragma region geometry
/*
    Float version of a graphics matrix, which has higher precision than an Mtx.
    Matrices are stored as Mtxfs then converted to an Mtx when passed to the GPU.
    Mtxs use a union and a long long int to force alignments. Mtxfs are not
    aligned but still use the union for consistency with Mtx.
*/
typedef union
{
    f32 m[4][4];
    s32 unused;
} Mtxf;

typedef union
{
    Mtxf pos;
    s32 view[4][4];
} RenderPosView;


    #pragma region colour

    typedef struct rgba_u8
    {
        union
        {
            struct
            {
                u8 r;
                u8 g;
                u8 b;
                u8 a;
            };
            u8  rgba[4];
            s32 word;
        };
    } rgba_u8;

    typedef struct rgba_16
    {
        union
        {
            struct
            {
                u16 r : 5;
                u16 g : 5;
                u16 b : 5;
                u16 a : 1;
            };
            u16 AsInteger;
        };
    } rgba_16;

    typedef struct rgba_f32
    {
        union
        {
            struct
            {
                f32 r;
                f32 g;
                f32 b;
                f32 a;
            };
            f32 rgba[4];
        };
    } rgba_f32;
    typedef struct rgb_s32
    {
        union
        {
            struct
            {
                s32 r;
                s32 g;
                s32 b;
            };
            s32 rgb[3];
        };
    } rgb_s32;
    typedef struct rgba_s32
    {
        union
        {
            struct
            {
                s32 r;
                s32 g;
                s32 b;
                s32 a;
            };
            s32 rgba[4];
        };
    } rgba_s32;

    #pragma endregion 
    #pragma region coordinates

    /**
     2D Co-ordinate.
     Use either Z OR Y not both
     */
    typedef struct coord2d
    {
        union
        {
            struct
            {
                f32 x;
                f32 y;
            };
            f32 f[2];
        };
    } coord2d;

    /**
     2D Vector.
     Use either Z OR Y not both
     */
    typedef coord2d vec2;

    /**
     2D Co-ordinate.
     Use either Z OR Y not both
     */
    typedef struct point2d
    {
        union
        {
            struct
            {
                s32 x;
                s32 y;
            };
            s32 p[2];
        };
    } point2d;

    typedef struct coord3d
    {
        union
        {
            struct
            {
                f32 x;
                f32 y;
                f32 z;
            };
            f32 f[3];
        };
    } coord3d;
#define New_Coord3d(x, y, z)            \
    {                                   \
        IF_ELSE(IS_EMPTY(x))            \
        (0)(x),                         \
            IF_ELSE(IS_EMPTY(y))(0)(y), \
            IF_ELSE(IS_EMPTY(z))(0)(z)  \
    }
    typedef coord3d vec3d; //canononical name
#define New_Vector(x, y, z)        \
    {                              \
        IF_ELSE(IS_EMPTY(x))(0)(x),\
        IF_ELSE(IS_EMPTY(y))(0)(y),\
        IF_ELSE(IS_EMPTY(z))(0)(z) \
    }

    /**
     16bit Co-Ordinate used for Integer co-ordinates eg, pumping straight to RSP.
     */
    typedef struct coord16
    {
        union
        {
            struct
            {
                s16 x;
                s16 y;
                s16 z;
            };
            s16 AsArray[3];
        };
    } coord16;

    #pragma endregion

    // Used for rendering watch menu
    struct WatchVertex {
        struct coord16 coord1;
        struct coord16 coord2;
        struct rgba_u8 color;
    };

    // Buffer defined on player struct, used
    // to render rectangles in bottom of watch menu.
    // Vertex order:
    // upper left
    // lower left
    // upper right
    // lower right
    struct WatchRectangle {
        struct WatchVertex vtx[4];
    };

    #pragma region volumes and areas

    typedef struct bbox2d
    {
        union
        {
            struct
            {
                coord2d min;
                coord2d max;
            };
            f32 f[2][2];
        };
    } bbox2d;

    typedef struct bbox
    {
        float xmin;
        float xmax;
        float ymin;
        float ymax;
        float zmin;
        float zmax;
    }bbox;

    typedef struct view4s32
    {
        union
        {
            struct
            {
                s32 left;
                s32 top;
                s32 width;
                s32 height;
            };
            s32 v[4];
            f32 f[4];
        };
    }Vew4s32;

    typedef struct view4f
    {
        union
        {
            struct
            {
                f32 left;
                f32 top;
                f32 width;
                f32 height;
            };
            s32 v[4];
            f32 f[4];
        };
    }view4f;

    typedef struct rect4f
    {
        union
        {
            struct coord2d points[4];
            f32            f[8];
        };
    }rect4f;

    struct rectbbox
    {
        f32 left;
        f32 up;
        f32 right;
        f32 down;
    };
    #pragma endregion
#pragma endregion

#pragma region Stand Tiles

    /* They appear to have performed the bit field work themselves here,
        but we provide the members for clarity - it should be unused I believe.
        (I agree if match, I was thinking about other such scenarios too -Trevor)
        seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF'
     */
    typedef struct StandTilePoint
    {
        inherits coord16; //points for tile
        u16 link; //link to nother tile
    } StandTilePoint;

    typedef struct StandTileHeaderMid
    {
        u16 special : 4;// 0=normal 1=kneeling 3=ladder
        u16 r       : 4;
        u16 g       : 4;
        u16 b       : 4;
    } StandTileHeaderMid;

    typedef struct StandTileHeaderTail
    {
        s16 pointCount : 4; // seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF'
        // Indices of the most extreme points (the resulting triangle should encompass _MOST_ of the tile)
        s16 headerC    : 4;
        s16 headerD    : 4;
        s16 headerE    : 4;
    } StandTileHeaderTail;

    typedef struct StandTile
    {
        /* u16 ID;         // Decimal
        u16 GroupID : 4;   // a1,a2,a3...z5,z6,z7
        u16 RoomID : 4;    // compared to 0xFF, not -1 in a function. Seen LBUs.
        */
        u32 name1 : 24;

        u8  room; // compared to 0xFF, not -1 in a function. Seen LBUs.

        union
        {
            StandTileHeaderMid headerMid;
            s16                half;
        } mid;

        /* 0x06 */
        // They appear to have performed the bit field work themselves here,
        //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
        union
        {
            StandTileHeaderTail hdrTail;
            s16                 half;
        } tail;

        /* 0x08 */
        StandTilePoint points[];
    } StandTile;

    typedef struct StandFilePoint
    {
        u16 x;
        u16 y;
        u16 z;
        u16 link;
    } StandFilePoint;

    typedef struct StandFileTile
    {
        u32 name1 : 24;
        //u8 name2;
        u8  room; // compared to 0xFF, not -1 in a function. Seen LBUs.
        union
        {
            StandTileHeaderMid headerMid;
            s16                half;
        } mid;

        /* 0x06 */
        // They appear to have performed the bit field work themselves here,
        //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
        union
        {
            StandTileHeaderTail hdrTail;
            s16                 half;
        } tail;

        /* 0x08 */
        //hack remove for compiling stan files
        //struct StandTilePoint points[1];
    } StandFileTile;

    typedef struct StandFileHeader
    {
        void *     unk1;
        StandTile *firstTile;
        u8         unk2[];
    } StandFileHeader;

    // May be internal only, nice here.
    struct StandTileWalkCallbackRecord
    {
        s32 *roomBuf;
        s32  count;
        s32  bufMax;
        s32  lastRoom;
    };
    typedef void (*standTileWalkCallback_t)(struct StandTile *, struct StandTile *, struct StandTileWalkCallbackRecord *);

    // Very similar but definitely different to the above?
    struct StandTileLocusCallbackRecord
    {
        s32  unk00;
        s32  count;
        s32  bufMax;
        s32  nearEdgeCount;
    };

    typedef struct StandFileFooter
    {
        char  strictstring[8];
        void *unk3;
        void *unk4;
        void *unk5;
        void *unk6;
    } StandFileFooter;

    typedef s32 (*standTileLocusCallback_A_t)(struct StandTile *, struct StandTileLocusCallbackRecord *);
    typedef s32 (*standTileLocusCallback_B_t)(StandTile *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, struct StandTileLocusCallbackRecord *arg5);
    typedef s32 (*standTileLocusCallback_C_t)(struct StandTile **, s32, struct StandTileLocusCallbackRecord *);

    typedef s32 (*tilePredicate_t)(struct StandTile *);

    /* Beta definitions, to allow citadel stan in .c file to build into .bin */

    typedef struct BetaStandFilePoint
    {
        inherits coord3d;
        u32 link;
    } BetaStandFilePoint;

    typedef struct BetaStandTileHeaderTail
    {
        u8 pointCount;
        u8 headerC;
        u8 headerD;
        u8 headerE;
    } BetaStandTileHeaderTail;

    typedef struct BetaStandTile
    {
        const char               *debugName;
        StandTileHeaderMid        headerMid;
        u16                       betaUnknown;
        BetaStandTileHeaderTail   hdrTail;
        struct BetaStandFilePoint points[];
    } BetaStandTile;

    StandTilePoint *stanMatchTileName(char *);

#pragma endregion

//Animation controller located in initobjects.h
#pragma region AnimationStuff

    typedef struct AnimTable2
    {
        int  a;
        char b;
    } AnimTable2;
    // unknown struct, unknown size.
    typedef struct ModelAnimation
    {
        s32 unk00;
        u16 unk04;
        u16 unk06;
        u16 unk08;
        u16 unk0A;
        u16 unk0C;
        u16 unk0E;
        // ...
    } ModelAnimation;

    
    struct object_animation_controller
    {
        void *ptranimation;        // 0x00
        u16   offsettocurcmd;      // 0x04
        u16   waitcounter;         // 0x06
        u32   imagenum;            // 0x08
        f32   rotation;            // 0x0C
        f32   curzoomx;            // 0x10
        f32   startzoomx;          // 0x14
        f32   zoomxtimer;          // 0x18
        f32   initialzoomx;        // 0x1C
        f32   finalzoomx;          // 0x20
        f32   curzoomy;            // 0x24
        f32   startzoomy;          // 0x28
        f32   zoomytimer;          // 0x2C
        f32   initialzoomy;        // 0x30
        f32   finalzoomy;          // 0x34
        f32   curhorizontalpos;    // 0x38
        f32   starthorscroll;      // 0x3C
        f32   horscrolltimer;      // 0x40
        f32   horinitpos;          // 0x44
        f32   horfinalpos;         // 0x48
        f32   curverpos;           // 0x4C
        f32   startverscroll;      // 0x50
        f32   verscrolltimer;      // 0x54
        f32   verinitpos;          // 0x58
        f32   verfinalpos;         // 0x5C
        u8    curredcomponant;     // 0x60
        u8    initredcomponant;    // 0x61
        u8    finalredcomponant;   // 0x62
        u8    curgreencomponant;   // 0x63
        u8    initgreencomponant;  // 0x64
        u8    finalgreencomponant; // 0x65
        u8    curbluecomponant;    // 0x66
        u8    initbluecomponant;   // 0x67
        u8    finalbluecomponant;  // 0x68
        u8    curalphacomponant;   // 0x69
        u8    initalphacomponant;  // 0x6A
        u8    finalalphacomponant; // 0x6B
        f32   startcolorshift;     // 0x6C
        f32   colorshifttimer;     // 0x70
    };

    /*
    typedef struct struck_animation_table
    {
        void *anonymous_0;
        s32   anonymous_1;
        f32   anonymous_2;
        f32   anonymous_3;
        s32   anonymous_4;
        f32   sfx1_timer_60;
        f32   sfx2_timer_60;
    } struck_animation_table;

    struct animation_something
    {
        s32                     anonymous_0;
        s32                     field_4;
        s32                     field_8;
        f32                     field_C;
        s32                     field_10;
        s32                     field_14;
        f32                     field_18;
        struck_animation_table *field_1C;
        s32                     field_20;
        struck_animation_table *field_24;
        s32                     field_28;
    };

    struct explosion_death_animation
    {
        s32 anonymous_0;
        s32 anonymous_1;
        f32 anonymous_2;
        f32 anonymous_3;
        f32 anonymous_4;
        f32 anonymous_5;
        f32 anonymous_6;
    };

    struct explosion_animation
    {
        void *explosion_death_animation;
        s32   count;
    };

    struct weapon_firing_animation_table
    {
        s32 anonymous_0;
        f32 anonymous_1;
        f32 anonymous_2;
        f32 anonymous_3;
        f32 anonymous_4;
        f32 anonymous_5;
        f32 anonymous_6;
        f32 anonymous_7;
        f32 anonymous_8;
        f32 anonymous_9;
        f32 anonymous_10;
        f32 anonymous_11;
        f32 anonymous_12;
        f32 anonymous_13;
        f32 anonymous_14;
        f32 anonymous_15;
        f32 anonymous_16;
        f32 anonymous_17;
    };*/
#pragma endregion AnimationStuff

#pragma region ModelTypes

    /**
     * Taken from PD, unsure that all of the fields line up
     */
    typedef struct ModelRenderData {
        /*0x00*/ Mtxf *unk00;
        /*0x04*/ bool zbufferenabled;
        /*0x08*/ u32 flags;
        /*0x0c*/ Gfx *gdl;
        /*0x10*/ Mtxf *unk10;
        /*0x14*/ u32 unk14;
        /*0x18*/ u32 unk18;
        /*0x1c*/ u32 unk1c;
        /*0x20*/ u32 unk20;
        /*0x24*/ u32 unk24;
        /*0x28*/ u32 unk28;
        /*0x2c*/ u32 unk2c;
        /*0x30*/ s32 unk30;
        /*0x34*/ u32 envcolour;
        /*0x38*/ u32 fogcolour;
        /*0x3c*/ u32 cullmode;
    } ModelRenderData;

    /**
     * Binary compatible with gbi Vtx but more verbose and  with "collision" 
     * information in place of "flags" for use in Openflight Records below
     */
    typedef struct Vertex
    {
        coord16 coord;
        s16     index; /*0x6 Collisions Only - points to vertex*/
        union
        {
            struct
            {
                s16 s; /*0x8*/
                s16 t; /*0xa*/
            };
            struct Vertex *LinkedTo;
        };
        union
        {
            u8 r; /*0xc*/
            u8 nx;
        };
        union
        {
            u8 g; /*0xd*/
            u8 ny;
        };
        union
        {
            u8 b; /*0xe*/
            u8 nz;
        };
        u8 a; /*0xf*/
    } Vertex;

    #pragma region OpenFlight Records
    /*
     The following structures are derived from the MultiGen OpenFlight binary data
     format for use in GE/PD.
     Databases in this format can be created and edited using PerfectGold

     The format supports variable levels of detail, degrees of freedom, instancing
     (both within a file and to external files), animation sequences, bounding
     volumes (box for collision, sphere for culling), shadows, and several other
     features.

     The OpenFlight database hierarchy allows the visual database to be organized
     in logical groupings and is designed to facilitate real-time functions such
     as level of detail switching and instancing. The OpenFlight database is
     organized in a tree structure. Each node (or bead) of the tree can point down
     and/or across (see Figure 1-1).

     Header: There is one header record per file. It is always the first record in
     the file and represents the top of the database hierarchy and tree structure.
     The header always points down to a group.

     Group: A group node is used to organize a logical subset of a database.
     MultiGen allows groups to be manipulated (translated, rotated, scaled, etc.)
     as a single entity. Groups can point down and across to other groups, level
     of detail nodes, or objects.

     Level of Detail: A level of detail (LOD) node is similar to a group, but
     serves as a switch to turn the display of everything below it on or off based
     on range (the switch in/switch out distance and center location).

     Switch: A switch node is a more general case of an LOD node. It allows the
     selection of multiple children by invoking a selector mask.

     Object: An object node contains a logical collection of polygons. An object
     can point across to another object, group or LOD.

     Bounding Volume: A Bounding Volume can be used by the real-time software to
     determine if a particular group is in view. The (optional) bounding volume
     opcode records are placed immediately after the group record and include the
     extents created by instancing and replication. A bounding volume can be
     either a box, a sphere, or a cylinder. Each group node can have only one
     bounding volume.

     Pointers:
     Pointers are offsets relative to model root.
     eg, the first child of the model has an offset of
    */

    typedef struct ModelFileTextures
    {
        u32 TextureID;
        u8  Width;
        u8  Height;
        u8  MipMapTiles;
        u8  Type;
        u8  RenderDepth; /*use G_IM_SIZ_ Note: CI uses 16bit*/
        u8  sflags;      /*use G_TX_*/
        u8  tflags;      /*use G_TX_*/

    } ModelFileTextures;

    /*
     This defines each row of the Node Table
     */
    typedef struct ModelNode
    {
        //u8 UseAdditionalMatrices; //1 = group use MatrixID1 also. not actually used
        u16                  Opcode; /*0x00*/
        union ModelRoData    *Data;   /*0x04 Node Data*/
        struct ModelNode     *Parent; /*0x08*/
        struct ModelNode     *Next;   /*0x0c*/
        struct ModelNode     *Prev;   /*0x10*/
        struct ModelNode     *Child;  /*0x14*/
    } ModelNode;


    #pragma region Model Node OpCode Definitions

        /*
         * These are some extra RoData structs that are used by Op07 (and presumably Op05)
         * Not sure how these fit in with the rest, they appear to be separate
         */

        typedef struct ModelRoData_Child
        {
            u8   NumEntries; /*0x00*/
            u8   unk01;      /*0x01*/
            u16  unk02;      /*0x02*/
            u8  *unk04;      /*0x04*/
        } ModelRoData_Child;

        typedef struct ModelRoData_Child_Vtx
        {
            u8  Type;     /*0x00*/
            u8  unk01;    /*0x01*/
            u16 VtxIndex; /*0x02*/
        } ModelRoData_Child_Vtx;

        typedef struct ModelRoData_Child_Tri
        {
            u8 Type;      /*0x00*/
            u8 VtxIndex1; /*0x01*/
            u8 VtxIndex2; /*0x02*/
            u8 VtxIndex3; /*0x03*/
        } ModelRoData_Child_Tri;

        typedef struct ModelRoData_Child_Image
        {
            u8 Type;       /*0x00*/
            u8 ImageIndex; /*0x01*/
        } ModelRoData_Child_Image;

    #pragma endregion

    #pragma region Model Node OpCode Definitions

        /**
         *  Opcode 1
         *  The header record is found at the beginning of the database file.
         *  Used on Character Bodies Only
         */
        typedef struct ModelRoData_HeaderRecord
        {
            u32                           ModelType;    /*0x0 Legnth of Record (4)*/
            struct ModelRoData_GroupRecord *FirstGroup; /*0x4 First group in tree*/

            union
            {
                struct
                {
                    u16 Group1;      /*0x8*/
                    u16 Group2;      /*0xA*/
                };
                f32 GroupsAsF32; /*0x8*/
            };

            u16 RwDataIndex; /*0xC*/
            u16 reserved;    /*0xE padding*/
        } ModelRoData_HeaderRecord;

        typedef struct ModelRwData_HeaderRecord
        {
            s8 unk00;
            s8 unk01;
            s8 unk02;
            f32 ground;
            coord3d pos;
            f32 unk14; // angle
            f32 unk18;
            f32 unk1c;
            f32 unk20; // angle
            coord3d unk24;
            f32 unk30; // angle
            coord3d unk34;
            coord3d unk40; // "2" version of unk24
            coord3d unk4c; // "2" version of unk34
            f32 unk58;
            f32 unk5c;
        } ModelRwData_HeaderRecord;

        /**
         * Opcode 2
         * Positions Child nodes reletivly.
         * Used for character joints with assosiated Matrices
         *
         * Group flags are available to the real-time software as follows:
         * The animation flags specify that the nodes directly below the group are an
         * animation sequence, each node being one frame of the sequence.
         * The special effects IDs are normally zero, but can be set to support an
         * application program's interpretation of the data.
         * The group's relative priority specifies a fixed ordering of the object
         * relative to the other groups at this level.
         * Since MultiGen sorts based on this field before saving the database, it can
         * be ignored by the real-time software.
         */
        typedef struct ModelRoData_GroupRecord
        {
            coord3d                       Origin;               /*0x0*/
            u16                           JointID;              /*0xC*/
            union {
                s16 MatrixIDs[3]; /*0xE*/
                struct {
                    s16 MatrixID0; /*0xE*/
                    s16 MatrixID1; /*0x10*/
                    s16 MatrixID2; /*0x12 never used*/
                };
            };
            struct ModelRoData_GroupRecord *ChildGroup;           /*0x14*/
            f32                           BoundingVolumeRadius; /*0x18*/
        } ModelRoData_GroupRecord;

        /**
         *  Opcode 3
         *  unused
         */

        /**
         *  Opcode 4
         *  Collisionless Display List used primarely for guns
         */
        typedef struct ModelRoData_DisplayListRecord
        {
            Gfx    *Primary;           /*0x0*/
            Gfx    *Secondary;         /*0x4*/ // optional
            void   *BaseAddr;          /*0x8*/
            Vertex *Vertices;          /*0xC*/
            u16     numVertices;       /*0x10*/
            /*
                0x12 Type of pre-defined rendermode and combiner setup to use
                0 = NoSetup - RenderMode and Combiner must be set in DList
                1 = 1Cycle No Sec
                2 = 2Cycle No Sec
                3 = GunLighting - Reduced Secondary Commands (guns)
                4 = Normal Fog/Lighting object
            */
            s8      ModelType;
        } ModelRoData_DisplayListRecord;

        typedef struct ModelRwData_DisplayListRecord // this record is a guess
        {
            s32 unk00;
        } ModelRwData_DisplayListRecord;

        /**
         *  Opcode 5
         *  unused
         */
        typedef struct ModelRoData_Op05Record
        {
            // shares this structure with op07
            s32                       NumChildren; /*0x00*/
            struct ModelRoData_Child *Children;    /*0x04*/
            struct Vertex            *Vertices;    /*0x08*/
            struct sImageTableEntry  *Images;      /*0x0C*/
            u8                        Data[400];   /*0x10*/

            u32 unk1A0;     /*0x1A0*/
            void* BaseAddr; /*0x1A4*/
        } ModelRoData_Op05Record;

        /**
         *  Opcode 6
         *  unused
         */
        typedef struct ModelRoData_Op06Record
        {
            u32 unk00;
            u32 unk04;
            u32 unk08;
            u32 unk0C;
            u32 unk10;
            void* BaseAddr; /*0x14*/
        } ModelRoData_Op06Record;

        /**
         *  Opcode 7
         *  unused but referenced
         */
        typedef struct ModelRoData_Op07Record
        {
            struct ModelNode* unk00;     /*0x00*/
            struct ModelNode* unk04;     /*0x04*/

            // shares this structure with op05
            s32                       NumChildren; /*0x08*/
            struct ModelRoData_Child *Children;    /*0x0C*/
            struct Vertex            *Vertices;    /*0x10*/
            struct sImageTableEntry  *Images;      /*0x14*/
            u8                        Data[400];   /*0x18*/

            u16 unk1A8;      /*0x1A8*/
            u16 RwDataIndex; /*0x1AA*/
            void* BaseAddr;
        } ModelRoData_Op07Record;

        typedef struct ModelRwData_Op07Record
        {
            s32 index;
        } ModelRwData_Op07Record;

        /**
         *  Opcode 8
         *  Level of Detail Record
         *  The distance is calculated by the real-time software by using the distance
         *  from the eye-point to the LOD center found
         */
        typedef struct ModelRoData_LODRecord
        {
            f32        MinDistance; /*0x0 Switch in distance*/
            f32        MaxDistance; /*0x4 Switch out distance*/
            ModelNode *Affects;     /*0x8 Affects this node (Must be child)*/
            u16        RwDataIndex; /*0xC*/
            u16        reserved;    /*0xE padding*/
        } ModelRoData_LODRecord;

        typedef struct ModelRwData_LODRecord
        {
            bool visible;
        } ModelRwData_LODRecord;

        /**
         *  Opcode 9
         *  Binary Separating Plane
         *  BSPs allow you to model 3D databases with the Z buffer turned off.
         */
        typedef struct ModelRoData_BSPRecord
        {
            coord3d    Point;       /*0x0*/
            coord3d    Vector;      /*0xC*/
            ModelNode *leftChild;   /*0x18 back/first */
            ModelNode *rightChild;  /*0x1C front/last */
            s16        reserved;    /*0x20 padding or u32*/
            u16        RwDataIndex; /*0x22*/
        } ModelRoData_BSPRecord;

        typedef struct ModelRwData_BSPRecord
        {
            bool visible;
        } ModelRwData_BSPRecord;

        /**
         *  Opcode 10 0xA
         *  Box within which collisions are tested
         */
        typedef struct ModelRoData_BoundingBoxRecord
        {
            u32         ModelNumber; /*0x0*/
            struct bbox Bounds;      /*0x4*/
        } ModelRoData_BoundingBoxRecord;

        /**
         *  Opcode 11
         *  unused but referenced
         */
        typedef struct ModelRoData_Op11Record
        {
            u32 unk0c[16]; /*0x0*/
            f32 BoundingVolumeRadius;
            u16 RwDataIndex; /*0x44*/
            u16 unk46;
            void* BaseAddr;
        } ModelRoData_Op11Record;

        typedef struct ModelRwData_Op11Record
        {
            s16 unk00;
            s16 unk02;
        } ModelRwData_Op11Record;

        /**
         *  Opcode 12 0xC
         */
        typedef struct ModelRoData_GunfireRecord
        {
            coord3d Offset;      /*0x0*/
            coord3d Size;        /*0xC*/
            void *  Image;       /*0x18*/
            f32     Scale;       /*0x1c*/
            u16     RwDataIndex; /*0x20*/
            u16     reserved;    /*0x22 padding*/
            u32     BaseAddr;    /*0x24 padding*/
        } ModelRoData_GunfireRecord;

        typedef struct ModelRwData_GunfireRecord
        {
            s16 visible;
            u16 unk02;
        } ModelRwData_GunfireRecord;

        /**
         *  Opcode 13 0xD
         *  Draws a shadow under character only
         */
        typedef struct ModelRoData_ShadowRecord
        {
            coord2d                   pos;      /*0x0*/
            coord2d                   size;     /*0x8*/
            void                     *image;    /*0x10*/
            ModelRoData_HeaderRecord *Header;   /*0x14*/
            f32                       Scale;    /*0x18*/
            void                     *BaseAddr; /*0x1C*/
        } ModelRoData_ShadowRecord;

        /**
         *  Opcode 14
         *  unused
         */
        typedef struct ModelRoData_Op14Record
        {
            coord3d pos;   /*0x0*/
            f32     Scale; /*0xC*/

        } ModelRoData_Op14Record;

        /**
         *  Opcode 15 0xF
         *  Database linkages use key table records.
         *  Linkage data consists of two different constructs: nodes and arcs.
         *  Nodes usually contain data pertaining to database entities such as
         *  degrees of freedom (DOFs).
         *  In addition, the nodes may represent modeling driver functions and code nodes.
         *  The arcs contain information on how all the nodes are connected to each other.
         *  The key value is used to represent a node, an arc, or a node name, if the
         *  node represents a database entity
         */
        typedef struct ModelRoData_InterlinkageRecord
        {
            coord3d pos;      /*0x0*/
            u32     unknown1; /*0xC*/
            u32     unknown2; /*0x10*/
            u32     unknown3; /*0x14*/
            f32     Scale;    /*0x18*/
        } ModelRoData_InterlinkageRecord;

        /**
         *  Opcode 16
         *  unused
         */
        typedef struct ModelNode_Op16Record
        {
            coord3d pos;      /*0x0*/
            u32     unknown1; /*0xC*/
            u32     unknown2; /*0x10*/
            f32     Scale;    /*0x14*/
        } ModelNode_Op16Record;

        /**
         *  Opcode 17
         *  unused
         */

        /**
         *  Opcode 18 0x12
         *  A switch node is a set of masks that controls the display of its children.
         *  The mask may inhibit the display of some, none, or all of the switch node
         *  children.
         */
        typedef struct ModelRoData_SwitchRecord
        {
            ModelNode *Controls;    /*0x0 Which node to display (Must be Child)*/
            u16        RwDataIndex; /*0x4*/
            u16        reserved;    /*0x6 padding*/
        } ModelRoData_SwitchRecord;

        typedef struct ModelRwData_SwitchRecord
        {
            bool visible;
        } ModelRwData_SwitchRecord;

        /**
         *  Opcode 19
         *  unused
         */

        /**
         *  Opcode 20
         *  unused
         */

        /**
         *  Opcode 21 0x15
         *  Simple Group used to position Cartridge ejection and held items
         */
        typedef struct ModelRoData_GroupSimpleRecord
        {
            coord3d Origin;               /*0x0*/
            s16     Group1;               /*0xC*/
            u16     Group2;               /*0xE*/
            f32     BoundingVolumeRadius; /*0x10*/
        } ModelRoData_GroupSimpleRecord;

        /**
         *  Opcode 22 0x16
         *  Primary Display List Only
         */
        typedef struct ModelRoData_DisplayListPrimaryRecord
        {
            s32     numVertices; /*0x0*/
            Vertex *Vertices;    /*0x4*/
            Gfx    *Primary;     /*0x8*/
            void   *BaseAddr;    /*0xC*/
        } ModelRoData_DisplayListPrimaryRecord;

        /**
         *  Opcode 23 0x17
         *  Head Placeholder for Random Heads
         */
        typedef struct ModelRoData_HeadPlaceholderRecord
        {
            u16 RwDataIndex;
        } ModelRoData_HeadPlaceholderRecord;

        typedef struct ModelRwData_HeadPlaceholderRecord
        {
            struct ModelFileHeader *ModelFileHeader;
            void *RwDatas;
        } ModelRwData_HeadPlaceholderRecord;

        /**
         *  Opcode 24 0x18
         *  Full Display List with Collision Table
         */
        typedef struct ModelRoData_DisplayList_CollisionRecord
        {
            Gfx     *Primary;              /*0x0*/
            Gfx     *Secondary;            /*0x4*/    // optional
            Vertex  *Vertices;             /*0x8*/
            s16      numVertices;          /*0xC*/
            s16      numCollisionVertices; /*0xE*/
            Vertex  *CollisionVertices;    /*0x10 Table of vertices with unique point in space (UV's and Colour are disregarded). */
            s16     *PointUsage;           /*0x14*/
            s16      ModelType;            /*0x18*/
            u16      RwDataIndex;          /*0x1A*/
            void    *BaseAddr;             /*0x1C*/

        } ModelRoData_DisplayList_CollisionRecord;

        typedef struct ModelRwData_DisplayList_CollisionRecord
        {
            Vertex *Vertices;
            Gfx *gdl;
        } ModelRwData_DisplayList_CollisionRecord;

    #pragma endregion Model Node OpCode Definitions

    /*
     * Handy Union for each type of RoData
     */
    union ModelRoData
    {
        struct ModelRoData_HeaderRecord Header;
        struct ModelRoData_GroupRecord Group;
        struct ModelRoData_DisplayListRecord DisplayList;
        struct ModelRoData_Op05Record Op05;
        struct ModelRoData_Op06Record Op06;
        struct ModelRoData_Op07Record Op07;
        struct ModelRoData_LODRecord LOD;
        struct ModelRoData_BSPRecord BSP;
        struct ModelRoData_BoundingBoxRecord BoundingBox;
        struct ModelRoData_Op11Record Op11;
        struct ModelRoData_GunfireRecord Gunfire;
        struct ModelRoData_ShadowRecord Shadow;
        struct ModelRoData_Op14Record Op14;
        struct ModelRoData_InterlinkageRecord Interlinkage;
        struct ModelNode_Op16Record Op16;
        struct ModelRoData_SwitchRecord Switch;
        struct ModelRoData_GroupSimpleRecord GroupSimple;
        struct ModelRoData_DisplayListPrimaryRecord DisplayListPrimary;
        struct ModelRoData_HeadPlaceholderRecord HeadPlaceholder;
        struct ModelRoData_DisplayList_CollisionRecord DisplayListCollisions;
    };

    /*
     * Handy Union for each type of RwData
     */
    union ModelRwData
    {
        struct ModelRwData_HeaderRecord Header;
        struct ModelRwData_DisplayListRecord DisplayList;
        struct ModelRwData_Op07Record Op07;
        struct ModelRwData_LODRecord LOD;
        struct ModelRwData_BSPRecord BSP;
        struct ModelRwData_Op11Record Op11;
        struct ModelRwData_GunfireRecord Gunfire;
        struct ModelRwData_SwitchRecord Switch;
        struct ModelRwData_HeadPlaceholderRecord HeadPlaceholder;
        struct ModelRwData_DisplayList_CollisionRecord DisplayListCollisions;
    };


#pragma endregion OpenFlight Records

    #pragma region Data Structures

        //21990 stuff below

        /*
         Defines which Node is the Joint and which matrices are applied to it.
         This Node (usualy a group) will move/rotate accordingly, however to animate
         vertices, remember to paint them with the same matrices.
         */
        typedef struct ModelJoint
        {
            u16 NodeType;
            u16 mtxA;
            u16 mtxB;
        } ModelJoint;

        /*
          This struct defines joint nodes and the matrices assosiated with them.
          There is Always at least 1 Joint used for positioning the object in-game
         */
        typedef struct ModelSkeleton
        {
            short       numjoints; //Always at least 1 (root)
            short       pad1;      //pad
            ModelJoint *Joints;
            short       SkeletonSize;
            short       pad2;
#ifdef DEBUG
            char      **JointNames;
#endif
        } ModelSkeleton;

        typedef struct ModelFileHeader
        {
            ModelNode         *RootNode;             //possibly this is "root data"
            ModelSkeleton     *Skeleton;
            /* This is a pointer to a variable length array of pointers to modelnodes, but the array is followed by an s16 array of part numbers.*/
            ModelNode        **Switches;
            s16                numSwitches;          // c Number of "05"s, these link to positions/switches Note: Does not reflect number actually used
            s16                numMatrices;          // Number of matrices used. (GE Name is LCase)
            f32                BoundingVolumeRadius; // 10 radius from model center to frustrum edge before culling.
            s16                numRecords;           // 14 used in runtime for number of records
            s16                numtextures;          // 16 Number of textures in table
            ModelFileTextures *Textures;             // 18 offset to texture table
#ifdef DEBUG
            char             **SwitchNames;
#endif
#if defined(VERSION_EU)
#else
            s32                isLoaded;
#endif
        } ModelFileHeader;

        typedef struct ItemModelFileRecord
        {
            ModelFileHeader *header;
            char            *filename;
            float            scale;
#ifdef DEBUG
            bool             isLoaded;
#endif
        } ItemModelFileRecord;

        typedef struct ChrModelFileRecord
        {
            ModelFileHeader *header;
            char            *filename;
            float            scale;
            float            pov;
            u8               isMale;
            u8               hasHead;
            u8               pad1;
            u8               pad2;
#ifdef DEBUG
            char           **SwitchNames;
#endif
        } ChrModelFileRecord;
        /*
        typedef struct GunModelFileRecord
        {
            ModelFileHeader     *Header;
            char                *Filename;
            s32                  HasNoModel;
            struct weapon_stats *Stats;
            u16                  WatchUpperTextID;
            u16                  WatchLowerTextID;
            coord3d              WatchPos;
            coord2d              WatchRot;
            u16                  WeaponOfChoiceTextID;
            u16                  WatchEquipmentTextID;
            coord3d              WatchRotationOrigin;
        } GunModelFileRecord;

        struct CartrigeModelFileRecord
        {
            ModelFileHeader *Header;
            char            *FileName;
        };
        */
        /*
         * Model Root Runtime Data (pos, heading, height etc)
         */
        struct modeldata_root
        {                    // type 0x01
            u16     unk00;   /*0*/
            u8      unk02;   /*2*/
            f32     ground;  /*4*/
            coord3d pos;     //8, 12, 16 - this is the right poition for this, but no idea what this node actually is (used in modelGetNodeRwData)
            f32     subroty; //14 angle - this also happens to fit best for getsubroty
            f32     unk18;   /*18*/
            u32     unk1c;   /*1c*/
            f32     unk20;   //20 angle
            coord3d unk24;
            f32     unk30; // angle copy of 20
            coord3d unk34;
            coord3d unk40; // "2" version of unk24
            coord3d unk4c; // "2" version of unk34
            f32     unk58;
            f32     unk5c;
        };

        /**
         * I beleve that "datas" is actually " struct modeldata_root" and that 
         * unk1c is the model node data array
         */
        typedef struct Model
        {
            u8                unk00; /*0x00*/   // objInit() indicates that unk00 is a s16...
            s16                Type;  /*0x01*/  // but modelInit() indicates that Type is a s16...
                                                // not sure which is correct.

            struct ChrRecord  *chr;   /*0x04*/
            ModelFileHeader   *obj;   /*0x08 GE Name confirmed*/

            /**
             * List of length model->obj->numMatrices dynamically allocated.
            */
            RenderPosView     *render_pos; /*0x0c*/
            union ModelRwData **datas; // array of pointers to modeldata structs /*0x10*/

            f32               scale;              /*0x14*/
            struct Model     *attachedto;         /*0x18*/
            ModelNode        *attachedto_objinst; /*0x1c*/

            // need `struct anim` definition from AI branch.
            ModelAnimation   *anim; /*0x20*/

            s8                gunhand; // used by ACT_STAND
            s8                unk25;
            s8                animlooping; /*0x26*/
            s8                unk27;

            f32               unk28; // animation related
            f32               unk2c;

            /**
             * Animation framea (per debug message)
             * Offset 0x30.
            */
            s16               framea;

            /**
             * Animation frameb (per debug message)
             * Offset 0x32.
            */
            s16               frameb;
            s32               unk34;
            s32               unk38;
            f32               endframe;

            f32               speed; /*0x40*/
            f32               newspeed; /*0x44*/
            f32               oldspeed; /*0x48*/
            f32               timespeed; /*0x4C*/
            f32               elapsespeed; /*0x50*/

            ModelAnimation   *anim2;

            f32               unk58;
            f32               unk5c;

            /**
             * Animation frame2a (per debug message)
             * Offset 0x60.
            */
            s16               frame2a;

            /**
             * Animation frame2b (per debug message)
             * Offset 0x62.
            */
            s16               frame2b;

            s32               unk64;
            s32               unk68;
            f32               unk6c;
            // 0x70
            f32               speed2;
            s32               unk74;
            s32               unk78;
            f32               unk7c;
            // 0x80
            s32               unk80;

            /**
             * Related to "anim2", per debug message.
            */
            f32               unk84;

            f32               unk88;
            s32               unk8c;
            // 0x90
            f32               animloopframe; /*0x90*/
            f32               animloopmerge; /*0x94*/
            s32               animflipfunc; /*0x98*/
            s32               unk9c;
            // 0xa0
            s32               unka0;
            f32               playspeed; // used by ACT_STAND in chrlv
            f32               animrate;
            f32               unkac;
            // 0xb0
            f32               unkb0;
            f32               unkb4;
            f32               unkb8; // used by ACT_ANIM in chrlv
            s32               unkbc;
        } Model;

        /*
        typedef struct headHat
        {
            float xoffset;
            float yoffset;
            float zoffset;
            float xsize;
            float ysize;
            float zsize;
        } headHat;*/
    #pragma endregion Data Structures

#pragma endregion ModelTypes


#pragma region Explosion Stuff

        typedef struct ExplosionDetailsRecord
        {
            s16 TypeID;
            s16 Seed[6];
        } ExplosionDetailsRecord;

        struct ExplosionDetailsRecordSeed
        {
            s16 seed[6];
        };

        typedef struct ExplosionDetailsRecordEuList
        {
            u8                                typeids[344];
            struct ExplosionDetailsRecordSeed seeds[105];
        } ExplosionDetailsRecordEuList;
#pragma endregion Explosion Stuff

#pragma region PadAndPaths
    /**
     * Pads hold a location in space and are tied to a specified Stand Tile.
     * Other attributes include its roation and normal.
     */
    typedef struct PadRecord /*0x2c (44) long confirmed*/
    {
        coord3d    pos;   /*0x00*/
        coord3d    up;    /*0x0c*/
        coord3d    look;  /*0x18*/
        char      *plink; /*0x24 canonical name */
        StandTile *stan;  /*0x28 canonical name */
    } PadRecord;

    /**
     * Bound Pads hold an extra Bounding Box which any prop assigned will try to
     * fill (non-uniform scaling).
     */
    typedef struct BoundPadRecord /*0x44 (68) long confirmed*/
    {
        //inherits PadRecord; /*0x00 confirmed*/
        coord3d    pos;       /*0x00*/
        coord3d    up;        /*0x0c*/
        coord3d    look;      /*0x18*/
        char *     plink;     /*0x24 canonical name */
        StandTile *stan;      /*0x28 canonical name */
        //temporary fix for no inheritance support by glibtools
        bbox     bbox;      /*0x2c - 0x40 confirmed*/
    } BoundPadRecord;


    /**
     //##Paths
      Paths are formed by connecting several pads together in 3 tables.
      The first table is the waypoint node table which lists the pad used, and 
      the subset group the waypoint belongs to.
     
      Next is the waygroup table which lists the IDs of the waypoints that 
      belong to each group. waypoints are grouped into subsets to reduce
      calculations on large numbers of nodes.
      
      Finally is the Path table which again lists all the waypoints used in
      the path and gives the path an ID. Paths do not contribute to pathfinding.

      Possible Graph Algorithm used A*
     */


    /**
     * The waypoint table lists the pad used, and the group the waypoint 
     * belongs to as well as any connected waypoints.
     */
    typedef struct waypoint
    {
        s32  padID;      // Pad ID to anchor waypoint to.
        s32 *neighbours; // Array of neighbouring (connected) waypoint IDs (ending in -1)
        s32  groupNum;   // index entry in the waygroup table that contains this path entry
        s32  dist;       // Initialise to 0, used by engine for pathfinding Heuristics between waypoints within a set.
    } waypoint;


    /**
     * The Subset waygroup table which lists the IDs of the waypoints that 
     * belong to each group as well as any connected groups
     */
    typedef struct waygroup
    {
        s32 *neighbours; // Array of neighbouring (connected) waygroup IDs (ending in -1)
        s32 *waypoints;  // Array of waypoint IDs (ending in -1)
        s32  dist;       // Initialise to 0, used by engine for pathfinding Heuristics between sets
    } waygroup;


    /**
     * Path for guard to patrol (loop) or get from A to B (linear)
     */
    typedef struct PathRecord
    {
        s32 *waypoints; // array of waypoint IDs in path (ending in -1)
        u8   ID;        // path ID
        u8   isLoop;    // 0x05 Path loops
        u16  len;       /*0x06 unused*/
    } PathRecord;


    //path finder
    struct waydata
    {
        /**
         * player.act_gopos.waydata starts at 0x5c.
        */

        s8      mode; /*0x00 */

        // next mode?
        s8      unk01; /*0x01 */

        /**
         * Related to pos field.
         * Set/unset flag?
         * Offset 0x2.
        */
        s8      unk02;

        /**
         * Related to pos_copy field.
         * Set/unset flag?
         * Offset 0x3.
        */
        s8      unk03;

        coord3d pos; /*0x04 */

        // from PD - unverified/unmatched
        coord3d pos2; /*0x10 */

        coord3d pos3; /*0x1c */

        // from PD - unverified/unmatched
        s32     age; /*0x28 */

        // from PD - unverified/unmatched
        coord3d pos_copy; /*0x2c */

        // These are the distances between the current waypoint and the previous
        // when using cheap mode.
        // from PD - unverified/unmatched
        f32     segdistdone; /*0x38 */

        // from PD - unverified/unmatched
        f32     segdisttotal; /*0x3c */
    };


#pragma endregion PadAndPaths

#pragma region ACT_TYPES

    struct act_init
    {
        int padding[30];
    };

    struct act_stand
    {
        s32 prestand;          /*0x2c*/
        s32 face_entitytype; /*0x30*/
        s32 face_entityid;   /*0x34*/
        s32 reaim;          /*0x38*/
        s32 turning;          /*0x3c*/
        u32 checkfacingwall;          /*0x40*/
        s32 wallcount;          /*0x44*/
        f32 mergetime;          /*0x48*/
        s8  face_target;     /*0x4c*/
    };

    struct act_kneel
    {
        int padding[30];
    };

    struct act_anim
    {
        u32 unk02c;     /*0x2c*/
        u32 unk30;      /*0x30*/
        u32 unk034;     /*0x34*/
        u32 unk038;     /*0x38*/
        u32 unk03c;     /*0x3c*/
        u8  unk040;     /*0x40*/
        u8  unk041;     /*0x41*/
        u16 unk042;     /*0x42*/
        u16 unk044;     /*0x44*/
        u16 unk046;     /*0x46*/
        s16 animnum;    /*0x48*/
        u8  flip;       /*0x4a*/
        f32 startframe; /*0x4c*/
        f32 endframe;   /*0x50*/
        f32 unk054;     /*0x54*/
        f32 unk058;     /*0x58*/
    };

    struct act_die
    {
        s32     notifychrindex;                 /*0x2c*/
        f32     thudframe1;                     /*0x30*/
        f32     thudframe2;                     /*0x34*/
        f32     timeextra; /* name from PD */   /*0x38*/
        f32     elapseextra; /* name from PD */ /*0x3c*/
        coord3d extraspeed; /* name from PD */  /*0x40*/
        s16     drcarollimagedelay;             /*0x4c*/
    };

    struct act_dead
    {
        bool allowfade;      /*0x2c*/
        bool allowreap;      /*0x30*/
        s32  reaptimer;      /*0x34*/
        s32  fadetimer;      /*0x38*/
        s32  notifychrindex; /*0x3c*/
    };

    struct act_argh
    {
        s32 notifychrindex; /*0x2c*/
        s32 unk30;
    };

    struct act_preargh
    {
        coord3d pos;    /*0x2c vec*/
        f32     unk038; /*0x38 relshotangle*/
        s32     unk03c; /*0x3c hitpart*/
        s32     unk040; /*0x40 weaponid*/
        u32     unk044; /*0x44*/
    };

    struct act_attack
    {
        struct weapon_firing_animation_table *animfloats; /*0x2c*/

        s8                                    unk30; /*0x30*/
        s8                                    unk31;
        s8                                    unk32; /*0x32*/
        s8                                    unk33; /*0x33*/

        s8                                    unk34; /*0x34*/
        s8                                    unk35; /*0x35*/
        s8                                    unk36; /*0x36*/
        s8                                    unk37;

        s8                                    unk38[2]; /*0x38*/
        s8                                    unk3a[2];

        s8                                    unk3c[2]; /*0x3c*/
        s8                                    unk3e;
        s8                                    unk3f;

        u32                                   unk40; /*0x40*/

        /**
         * Related to attack_time, maybe previous attack time?
         * Offset 0x44.
         */
        s32                                   unk44;

        /**
         * Offset 0x48.
         */
        s32                                   attack_time;

        /**
         * attack type is the target flag used by the AI fire at target commands.
         * chr offset 0x4c.
         */
        u32                                   attacktype;
        u32                                   entityid; /*0x50*/
        u32                                   unk54;    /*0x54*/

        s32                                   type_of_motion; /*0x58 reaim*/
        u32                                   unk5C;

        u32                                   unk60;
        u32                                   unk64;
        u32                                   unk68;
        u32                                   unk6c;

        u32                                   unk70;
        u32                                   unk74;
        u32                                   unk78;
        u32                                   unk7c;

        s8                                    attack_item;
        u8                                    unk81;
        u8                                    unk82;
        u8                                    unk83;
    };

    struct act_attackwalk
    {
        u32                                   unk02c;        /*0x2c*/
        s32                                   clock_timer30; /*0x30*/
        s32                                   clock_timer34; /*0x34*/
        u32                                   unk038;        /*0x38*/
        struct weapon_firing_animation_table *animfloats;    /*0x3c*/
        s32                                   timer40;       /*0x40*/

        s32                                   unk044; /*0x44*/

        s8                                    unk48[2]; /*0x48*/
        s8                                    unk4a[2]; /*0x48*/

        s8                                    unk4C[2]; /*0x4c*/
        u8                                    flip;     /*0x4e*/
        s8                                    unk4f;

        s32                                   unk50;
        f32                                   speed;

        u32                                   unk58;
        u32                                   unk5C;

        u32                                   unk60;
        u32                                   unk64;
        u32                                   unk68;
        u32                                   unk6c;

        u32                                   unk70;
        u32                                   unk74;
        u32                                   unk78;
        u32                                   unk7c;

        s8                                    attack_item;
        u8                                    unk81;
        u8                                    unk82;
        u8                                    unk83;
    };

    struct act_attackroll
    {
        struct weapon_firing_animation_table *animfloats; /*0x2c*/

        s8                                    unk30; /*0x30*/
        s8                                    unk31;
        s8                                    unk32; /*0x32*/
        s8                                    unk33; /*0x33*/

        s8                                    unk34; /*0x34*/
        s8                                    unk35; /*0x35*/
        s8                                    unk36; /*0x36*/
        s8                                    unk37;

        s8                                    unk38[2]; /*0x38*/
        s8                                    unk3a[2];

        s8                                    unk3c[2]; /*0x3c*/
        s8                                    unk3e;
        s8                                    unk3f;

        u32                                   unk40; /*0x40*/

        /**
         * Related to attack_time, maybe previous attack time?
         * Offset 0x44.
         */
        s32                                   unk44;

        /**
         * Offset 0x48.
         */
        s32                                   attack_time;

        s32                                   unk4c[2];
        s32                                   unk54[2];

        u32                                   unk5C;

        u32                                   unk60;
        u32                                   unk64;
        u32                                   unk68;
        u32                                   unk6c;

        u32                                   unk70;
        u32                                   unk74;
        u32                                   unk78;
        u32                                   unk7c;

        s8                                    attack_item;
        u8                                    unk81;
        u8                                    unk82;
        u8                                    unk83;
    };

    struct act_sidestep
    {
        bool side; /*0x2c*/
    };

    struct act_jumpout
    {
        bool side; /*0x2c*/
    };

    struct act_runpos
    {
        coord3d pos; /*0x2c*/

        /**
         * chr offset 0x38.
         */
        f32     neardist; /*0x38*/

        /**
         * chr offset 0x3c.
         */
        s32     eta60; /*0x3c*/

        /**
         * chr offset 0x40.
         */
        f32     turnspeed; /*0x40*/
    };

    struct patrol_path
    {
        s32 *data;
        u8   unk04;
        u8   flags;
        u16  len;
    };

    struct act_patrol
    {
        struct patrol_path *path;     /*0x02c*/
        s32                 nextstep; /*0x030*/
        bool                forward;  /*0x034*/
        struct waydata      waydata;  /*0x038*/
        s32                 lastvisible60;

        /**
         * Offset 0x7c.
         */
        f32                 speed;

        s32                 unk80;
        s32                 unk84;
        s32                 unk88;
        s32                 unk8c;
        s32                 unk90;
        s32                 unk94;
        s32                 unk98;
        s32                 unk9c;
        s32                 unka0;
    };

    struct act_gopos
    {
        coord3d        targetpos; // Target pos                           /*0x02c*/
        StandTile     *target;    // Target/final waypoint                  /*0x038*/

        waypoint      *target_path; /*0x03c*/

        // Array of pointers to the next couple of waypoints. Recalculated each time
        // a waypoint is reached, and probably even more frequently than that.
        waypoint      *waypoints[MAX_CHRWAYPOINTS]; /*0x040*/

        // Index of the waypoint in the above array that the chr is running to. If
        // the chr has line of sight (through doors) to the next or next + 1 then
        // the index can be changed to that one and the chr will run straight to it.
        // This index will always be 0, 1 or 2. When it reaches 3 the pathfinding is
        // recalculated, the array replaced with a new one and index set to 0.
        /* player offset 0x58 */
        u8             curindex;
        u8             unk59; // guess: room

        // g_ClockTimer related
        u16            unk5a;

        // offset 0x5c
        struct waydata waydata;

        // last update time?
        s32            unk9c;

        /**
         * Offset 0x9a.
         */
        f32            speed;

        // PD reference below:

        // Array of pointers to the next couple of waypoints. Recalculated each time
        // a waypoint is reached, and probably even more frequently than that.
        // struct waypoint *waypoints[5]; // MAX_CHRWAYPOINTS];               /*0x040*/

        // Index of the waypoint in the above array that the chr is running to. If
        // the chr has line of sight (through doors) to the next or next + 1 then
        // the index can be changed to that one and the chr will run straight to it.
        // This index will always be 0, 1 or 2. When it reaches 3 the pathfinding is
        // recalculated, the array replaced with a new one and index set to 0.
        //u8 curindex;                                                       /*0x054*/

        // x....... = walking directly to pad due to PADFLAG_AIWALKDIRECT
        // .x...... = ducking due to PADFLAG_AIDUCK
        // ....x... = on preset path
        // ......xx = speed
        //u8 flags;                                                          /*0x055*/
        //u16 restartttl;                                                    /*0x056*/

        //struct waydata waydata;                                            /*0x058*/
        ///////////////////////////////////////////
        // u8 mode;                 /*0x00 58*/
        // u8 unk01;                /*0x01 59*/
        // u16 unk02;               /*0x02 5a*/
        // coord3d pos;      /*0x04 5c*/
        // coord3d pos2;     /*0x10 68*/
        // u32 unk1c;               /*0x1c 74*/
        // u32 unk20;               /*0x20 78*/
        // u32 unk24;               /*0x24 7c*/
        // s32 age;                 /*0x28 80*/
        // coord3d pos_copy; /*0x2c 84*/

        // // These are the distances between the current waypoint and the previous
        // // when using cheap mode.
        // f32 segdistdone;  /*0x38 90*/
        // f32 segdisttotal; /*0x3c 94*/
        ///////////////////////////////////////////

        //s32 cheapend60; // lvframe60 time that the chr exited cheap method of wayfinding /*0x098*/
        //f32 unk0ac;                                                        /*0x09c*/
    };
    struct act_surrender
    {
        int padding[30];
    };

    struct act_lookattarget
    {
        int padding[30];
    };

    struct act_surprised
    {
        u32 type; /*0x2c*/
    };

    struct act_startalarm
    {
        int padding[30];
    };

    struct act_throwgrenade
    {
        u32  entitytype; /*0x2c*/
        u32  entityid;   /*0x30*/
        u32  hand;       /*0x34*/
        bool needsequip; /*0x38*/
    };

    struct act_turndir
    {
        int padding[30];
    };

    struct act_test
    {
        int padding[30];
    };

    struct act_bondintro
    {
        int padding[30];
    };

    struct act_bonddie
    {
        int padding[30];
    };

    struct act_bondmulti
    {
        f32 *unk2c; // probably pointer to animation data, similar to weapon_firing_animation_table

        s32  unk30;
        s32  unk34;
        s32  unk38;
        s32  unk3c;

        int  padding[25];
    };

    struct act_null
    {
        int padding[30];
    };

    struct act_bytes
    {
        s8 padding[120];
    };

    struct act_ubytes
    {
        u8 padding[120];
    };
#pragma endregion ACT_TYPES

#pragma region Prop, Chr and Definition Records

    

    /**
     * Prop Record holds the relationship between various "props" on a stage.
     */
    typedef struct PropRecord
    {
        u8  type;        /*0x00   PROP_TYPE */
        u8  flags;       /*0x01*/
        s16 timetoregen; // ticks down /*0x02*/
        union
        {
            struct ChrRecord       *chr;
            struct ObjectRecord    *obj;
            struct DoorRecord      *door;
            struct WeaponObjRecord *weapon;
            void                   *explosion;
            void                   *smoke;
            void                   *voidp;
        };                       /*0x04*/
        coord3d            pos;  /*0x08*/
        StandTile         *stan; /*0x14 canonical name */

        /**
         * Maybe float. Something related to draw (render) distance.
         */
        f32                Unk18;
        struct PropRecord *parent;                          /*0x1c*/
        struct PropRecord *child;                           /*0x20*/
        struct PropRecord *prev;                            /*0x24*/
        struct PropRecord *next;                            /*0x28*/
        u8                 rooms[PROPRECORD_STAN_ROOM_LEN]; /*0x2c*/
        s32                unk30;

        // u16 unk38;         /*0x38* /
        // s16 unk3a;         /*0x3a* /
        // u8 unk3c;          /*0x3c* /
        // u8 propstateindex; /*0x3d* /
        // u8 unk3e;          /*0x3e* /
        // u8 unk3f_00 : 1;   /*0x3f* /
        // u8 unk3f_01 : 1;   /*0x3f* /
        // u8 unk3f_02 : 1;   /*0x3f* /
        // u8 unk3f_03 : 1;   /*0x3f* /
        // u8 unk3f_04 : 1;   /*0x3f* /
        // u8 unk3f_05 : 1;   /*0x3f* /
        // u8 unk3f_06 : 1;   /*0x3f* /
        // u8 unk3f_07 : 1;   /*0x3f* /
        // u32 unk40;         /*0x40* /
        // u32 unk44;         /*0x44*/
    } PropRecord;

    #pragma region GlobalPropDef
  
    /**
     * sizeof = 0x2c = 44 bytes.
     */
    typedef struct ChrRecord_f180
    {
        /***/
        s8      unk00;
        s8      item_id; // type ITEM_IDS
        char    unk02;
        char    unk03;

        coord3d pos;

        /**
     * Offset 0x10
    */
        struct coord3d delta;
        f32     unk1c;

        f32     unk20;
        f32     unk24;
        f32     unk28;
    } ChrRecord_f180;


    typedef struct PropDefHeaderRecord
    {
        u16 extrascale; /*0x0 Fixed-Point format u8.8 eg: 0x03.80 = 3.5*/
        /*
          Destroyed, respawn, defused etc
            8x    destroyed
            4x    datathief/defuser/decoder used on obj (activated?)
            2x
            1x
            x8    external allocated collision block present
            x4    respawn enabled
            x2
            x1    damaged
        */
        u8  state;      
        u8  type;       /*0x3*/
    } PropDefHeaderRecord;
    #define New_PropDefHeaderRecord(scale, Type) \
        {                                 \
            (scale) * 256, PROPSTATE_NORMAL, Type \
        }

    #pragma endregion GlobalPropDef

    /* unfinished struct, WIP */
    typedef struct ChrRecord
    {
        s16         chrnum;                      /* 0x0000 */
        s8          accuracyrating;              /* 0x0002 */
        s8          speedrating; /* 0x0003 */    //0-100
        u8          firecount[2];                /* 0x0004 */
        s8          headnum;                     /* 0x0006 */
        ACT_TYPE    actiontype : 8; /* 0x0007 */ //force 8bit
        s8          sleep;                       /* 0x0008 */
        s8          invalidmove;                 /* 0x0009 */
        s8          numclosearghs;               /* 0x000A */
        s8          numarghs;                    /* 0x000B */
        u8          fadealpha;                   /* 0x000C */
        s8          arghrating;                  /* 0x000D */
        s8          aimendcount;                 /* 0x000E */
        s8          bodynum;                     /* 0x000F */
        u8          grenadeprob;                 /* 0x0010 */
        s8          flinchcnt;                   /* 0x0011 */
        u16         hidden;                      /* 0x0012 */
        CHRFLAG     chrflags;                    /* 0x0014 */
        PropRecord *prop;                        /* 0x0018 */
        Model      *model;                       /* 0x001C */
        /* 0x0020 */
        void       *field_20; /* 0x0020 */ //path?
        f32         chrwidth;              /* 0x0024 */
        f32         chrheight;             /* 0x0028 */
        union
        {
            struct act_init         act_init;
            struct act_stand        act_stand;
            struct act_kneel        act_kneel;
            struct act_anim         act_anim;
            struct act_die          act_die;
            struct act_dead         act_dead;
            struct act_argh         act_argh;
            struct act_preargh      act_preargh;
            struct act_attack       act_attack;
            struct act_attackwalk   act_attackwalk;
            struct act_attackroll   act_attackroll;
            struct act_sidestep     act_sidestep;
            struct act_jumpout      act_jumpout;
            struct act_runpos       act_runpos;
            struct act_patrol       act_patrol;
            struct act_gopos        act_gopos;
            struct act_surrender    act_surrender;
            struct act_lookattarget act_lookattarget;
            struct act_surprised    act_surprised;
            struct act_startalarm   act_startalarm;
            struct act_throwgrenade act_throwgrenade;
            struct act_turndir      act_turndir;
            struct act_test         act_test;
            struct act_bondintro    act_bondintro;
            struct act_bonddie      act_bonddie;
            struct act_bondmulti    act_bondmulti;
            struct act_null         act_null;
            struct act_bytes        act_bytes;
            struct act_ubytes       act_ubytes;
        };
        f32     sumground;          /*0xA4*/
        f32     manground;          /*0xA8*/
        f32     ground;             /*0xAC*/
        coord3d fallspeed;          /*0xB0*/
        coord3d prevpos;            /*0xBC*/
        s32     lastwalk60;         /*0xC8*/
        s32     lastmoveok60;       /*0xCC*/
        f32     visionrange;        /*0xD0*/
        s32     lastseetarget60;    /*0xD4*/
        coord3d lastknowntargetpos; /*0xD8 confirmed*/
        void   *targetTile;         /*0xE4 maybe lastshooter*/

        /*0xE8 */
        union
        {
            s32 seen_bond_time;
            struct
            {
                s16 lastshooter; /*0xE8 */
                s16 timeshooter; /*0xEA*/
            };
        };
        f32            hearingscale;     /*0xEC increases when shot at*/
        s32            lastheartarget60; /*0xF0 increases after hearing bond (NOTE s32 not u32) */
                                         /* this next block MUST exist here */
        rgba_u8        shadecol;         /*0xF4 stan colour eg, white = 0,0,0,0, grey = 0,0,0,64, black = 0,0,0,128, red = 255,0,0,128*/
        rgba_u8        nextcol;          /*0xF8 (allows gradual transition) Stan colour is applied via "FOG" colour reg*/
        f32            damage;           /* 0x00FC confirmed*/
        f32            maxdamage;        /* 0x0100 confirmed*/
        AIRecord      *ailist;           /* 0x0104 confirmed*/
        u16            aioffset;         /* 0x0108 confirmed*/
        s16            aireturnlist;     /* 0x010A confirmed*/
        u8             morale;           /* used by ai commands 81-85 */
        u8             alertness;        /* used by ai commands 86-8A */
        u8             flags2;         /*canonical name */
        u8             random;
        s32            timer60;    /* 0x0110 */
        s16            padpreset1; /* ID PAD_PRESET */
        s16            chrpreset1; /* ID CHR_PRESET */
        s16            chrseeshot; /* ID CHR_SEE_SHOT - ignores invincible/armoured guards */
        s16            chrseedie;  /* ID CHR_SEE_DIE */
                                   /* 0x011C */
        /**
         * Four pairs are:
         * - Stans? head
         * - yminmax
         * - xz
         * - width
         * Offset 0x011c.
         */
        rect4f         collision_bounds;

        /* 0x013c */
        f32            shotbondsum;
        /* 0x0140 */
        f32            aimuplshoulder;
        f32            aimuprshoulder;
        f32            aimupback;
        f32            aimsideback;
        /* 0x0150 */
        f32            aimendlshoulder;
        f32            aimendrshoulder;
        f32            aimendback;
        f32            aimendsideback;

        /* 0x0160 */
        // this section needs work, see:
        // - sub_GAME_7F02BFE4
        // - disable_sounds_attached_to_player_then_something
        // there should be some ALSoundState * pointers in here.
        //
        PropRecord    *weapons_held[3]; /* handle_positiondata 0x0160 0x0164  0x0168 Right, Left, Hat*/
        s8             fireslot[2];     /* 0x016C 0x0170*/
        int           *ptr_SEbuffer3;
        int           *ptr_SEbuffer4;
        int            field_178[2];
        //int field_17C;

        /* 0x0180 */
        /**
         * Method chrlvFireWeaponRelated calls CapBeamLengthAndDecideIfRendered, and passes an address
         * which makes it look like this is an array at ChrRecord offset 180.
        */
        ChrRecord_f180 unk180[2];

        PropRecord    *handle_positiondata_hat;
    } ChrRecord;
    // ChrRecord *pChrData; //not Global, local to Object or function

    #pragma region IndividualObjectTypes

    struct collision_data {
        s32 unk00;

        rect4f unk04;

        s32 unk24;
        s32 unk28;
        s32 unk2C;

        s32 unk30;
        s32 unk34;
        s32 unk38;
        s32 unk3C;

        s32 unk40;
        f32 unk44;

        // Might be related to collision radius
        f32 unk48;
    };

    typedef struct Projectile {
        u32 flags;
        coord3d speed;
        coord3d unk10;

        f32 unk1C;
        Mtxf mtx; // 0x20-0x5c

        f32 unk60;
        f32 unk64;

        f32 unk68[4];
        f32 unk78[4];

        struct PropRecord* ownerprop; // 0x88
        f32 unk8C; 

        u32 unk90;
        f32 unk94;
        struct ALSoundState* sound1; // 0x98
        struct ALSoundState* sound2; // 0x9C

        u32 unkA0;
        u32 unkA4;
        u32 unkA8;
        u32 unkAC;

        f32 unkB0; // runtime y position?
        f32 unkB4; // previous pos.y?
        DROPTYPE droptype; // 0xB8
        u32 refreshrate; // 0xBC;

        f32 unkC0;
        f32 unkC4;
        f32 unkC8;

        u8 unkCC;
        u8 unkCD;
        u8 unkCE;
        u8 unkCF;

        u32 unkD0;
        f32 unkd4; // probably struct coord3d
        u32 unkD8;
        u32 unkDC;

        u32 unkE0;
        struct ObjectRecord* obj; // 0xE4;
        s32 unkE8;
    } Projectile;

    typedef struct Embedment {
        /*0x000*/ s32 flags;
        /*0x004*/ Mtxf matrix;
        /*0x044*/ struct Projectile *projectile;
    } Embedment;

    /**
     * Object (Prop Definition) Record holds common data such as pad and health.
     */
    typedef struct ObjectRecord
    {
        inherits    PropDefHeaderRecord;
        s16         obj; //canonical name, use with PROP_ enum eg PROP_ALARM1
        /* ID 0x6
            0000+ or 2710+ (10,000+) to use standard presets.
            -1 to -256 to set this object
                inside the previous object.(solo only)
            if control nibble 4x is set at 0xB,
            then this number matches the ID of a guard
        */
        s16         pad;
        /*0x8
            8x    indicates right-handed gun assignment
            4x    08 weapon does not provide ammunition when collected
            2x    indicates object in motion or special function is activated
            1x    indicates left-handed normal pickup or opposite alignment
            0x    indicates no control features set
            x8
            x4    (unknown) Jungle bushes
            x2    (unknown) pete grenade
            x1    indicates embedded crate or other object, creating a chain of boxes, for
            example      x0    indicates normal preset, or beginning/end of chain
            Doors:
            8x    open by default
            4x    area behind door is always visible (no blackouts for gates, lab doors, etc)
            2x    open backwards
            1x    same as 0 as far as I can tell
            x8    always open away from the player regardless what side you're on
            x4
            x2    player can't activate door (spawn block or 16 type activation)
            x1
            0x9:
            8x
            4x    immobile
            2x    (unknown) Silo DAT tape
            1x    uncollectable
            x8
            x4    allows object pickup (chr_name objects only)
            x2    invincibility
            x1
            0xA:
            8x    indicates contained within another object (forward or back # objects = preset value)
            4x    indicates object does not use normal presets but is assigned to guard #preset
            2x    (unknown) part of forced collectable objects
            1x    think this sets object to absolute position.  (similar to 2xxx type)
            x8    something to do with free-standing glass (glass walls)
            x4    (unknown) streets buildings/roadblocks
            x2    seems to align image to preset values for glass
            x1    force collisions (2xxx presets, mostly)
            0xB:
                0xxx presets:
                00    default, on ground
                x1    forced to ground
                x2    room upper limit, rotated y 90 degrees.  top faces direction, front faces up
                x4    room upper limit, upside-down
                x8    room upper limit, right side up
            2xxx presets:
                x1    normal placement
                x2    rotated y 90 degrees.  top faces direction, front faces up. (use on obj 68-6B)
                x4    upside-down
                x8    in-air
                1x    scale object to fit completely within preset bounds
                2x    x set to preset bounds
                4x    y set to preset bounds
                8x    z set to preset bounds
        */
        u32         flags;
        /*0xC:
            8x    force maximum explosion radius/disable detecting
                    player
            4x    autoturrets: reset to default, not preset position
            2x    no AI interaction
            1x    1-way lock (back)
            x8    1-way lock (front)
            x4
            x2    Objects (rockets, mines, etc) do not collide with object
            x1    don't load 4 player
            0xD:
            8x    don't load 3 player
            4x    don't load 2 player
            2x    immune to explosions (only gunfire damages object)
            1x    bulletproof
            x8    invisible! can't shoot, but can hit with rockets, bugs, etc.  not counted as a hit
            x4
            x2    (unknown) streets buildings
            x1
            0xE:
            8x    Can fire through object
            4x    immune to gunfire (Only explosives damage object)
            2x    Remove from game when destroyed (anything on top doesn't fall off!  Just Poof! gone)
            1x
            x8    only activate at close range
            x4
            x2    explode on contact with tank?
            x1    (unknown) jungle bush
            0xF:
            8x    don't load on 007
            4x    don't load on 00 agent
            2x    don't load on secret agent
            1x    don't load on agent
            x8    don't load multiplayer (difficulty = -1)
            x4    disable activation text
            x2    lightweight (previous: 2xxx drops to ground when destroyed)
            x1    used on stuff in egyptian, sevx
        */
        u32         flags2;
        PropRecord *prop;  /*0x10*/
        Model      *model; /*0x14*/
                           // mtx realrot;
#if 0 
        void *runtime_MATRIX0; /*0x18*/
        void *runtime_MATRIX1; /*0x1c*/
        void *runtime_MATRIX2; /*0x20*/
        void *runtime_MATRIX3; /*0x14*/
        void *runtime_MATRIX4; /*0x28*/
        void *runtime_MATRIX5; /*0x2c*/
        void *runtime_MATRIX6; /*0x30*/
        void *runtime_MATRIX7; /*0x34*/
        void *runtime_MATRIX8; /*0x38*/
        void *runtime_MATRIX9; /*0x3c*/
        void *runtime_MATRIXA; /*0x40*/
        void *runtime_MATRIXB; /*0x44*/
        void *runtime_MATRIXC; /*0x48*/
        void *runtime_MATRIXD; /*0x4c*/
        void *runtime_MATRIXE; /*0x50*/
        void *runtime_MATRIXF; /*0x54*/
#endif
        Mtxf    mtx;         /* Hopefully this is 16 words long*/
        coord3d runtime_pos; /*0x58 - 0x60*/
        union
        {
            /*This union is a test but is less efficant than doing binary compare by hand eg runtimebitflags && REMOVED*/
            struct
            {
                bool a00000001     : 1;
                bool a00000002     : 1;
                bool remove        : 1; /* removes object when set   */
                bool a00000008     : 1;
                bool a00000010     : 1;
                bool a00000020     : 1;
                bool a00000040     : 1;
                bool isDeposited   : 1; /* depositted (thrown)  */
                bool hasBeenOpened : 1;
                bool isDestroyed   : 1; /* only set with disabled or destroyed doors    */
                bool a00000400     : 1;
                bool a00000800     : 1;
                bool a00001000     : 1;
                bool a00002000     : 1;
                bool isActivated   : 1; /* activated*/
                bool a00008000     : 1;
                bool a00010000     : 1;
                s32  owner         : 2; /*Owner 2bit (0-3)*/
                bool a00080000     : 1;
                bool a00100000     : 1;
                bool a00200000     : 1;
                bool a00400000     : 1;
                bool a00800000     : 1;
                bool a01000000     : 1;
                bool a02000000     : 1;
                bool a04000000     : 1;
                bool a08000000     : 1;
                bool a10000000     : 1;
                bool a20000000     : 1;
                bool a40000000     : 1;
                bool a80000000     : 1;
            };
            /*0x64*
                10000000
                00060000    owner (0-3); used to attribute kills to players
                00004000    activated
                00000200    only set with disabled or destroyed doors
                00000080    depositted (thrown)
                00000004    removes object when set
            */
            u32 runtime_bitflags;
        };
        struct collision_data *ptr_allocated_collisiondata_block;

        union {
            struct Projectile *projectile; // 0x6c
            struct Embedment *embedment; // 0x6c
        };

        f32             maxdamage; // 0x70
        f32             damage; // 0x74
        rgba_u8         shadecol; // 0x78
        rgba_u8         nextcol; // 0x7C
    } ObjectRecord;
    #define New_ObjectRecord(pad)                                                       \
        {                                                                               \
            New_PropDefHeaderRecord(3), 0, pad + 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xbadbee6c, 0, 1000, 0, 0,       \
                0, 0, 0, 0, 0, 0, 0                                                     \
        }

    // PROPDEF_DOOR (1)
    typedef struct DoorRecord
    {
        inherits           ObjectRecord;
        /* GE Door maybe different to PD?
        80:	linked with other doors (4 bytes)
            if used, uses # objects up/down to other door.
            when this object activates, targetted object also activates
            you usually want both doors to point at each other, obviously
        84:	distance door travels when opening/closing (total%)
        88:	distance before door loses collisions (total%)
        00150000 -> 41a80000
        8C:	open/close accelleration rate
        90:	rate used when someone activates a door as it opens/closes
        0100 -> 3B800000
        94:	open/close max speed
        1999 -> 3DCCC800
        note:	*speed sets the speed the door opens at.
            the two rate features affect how long it takes to reach this max speed.
        98:	open technique (2+2 bytes)
            0000 0000	slider (left/right) clears the door away as it slides, stopping visual problems when opening into a wall
            0004 0000	slider (left/right)
            0000 0004	shutter (up/down) clears the door as it slides
            0004 0004	shutter (up/down)
            0000 0005	special (swinging) defined here
            0000 0006	special (eye) defined here in block
            0000 0007	special (iris) defined here
        9F:	nonzero to lock
        A0:	amount of ms door remains open
        A7:	opening sound effect
        A8:	runtime - (float)
        AC:	runtime - (float)
        B0:	runtime - (float)
        B4:	runtime - (float) current distance travelled
        B8:	runtime - (float)
        BC:	runtime -
        BD:	runtime -
        C8:	runtime -
        CC:	runtime - p->vertex buffer when door does not clear
        F0:	runtime -
        F4:	runtime -
        F8:	runtime -
        */

        s32                linkedDoorOffset; /*0x80*/

        /**
         * Distance door travels when opening/closing (total%).
         * Offset 0x84.
         */
        f32                maxFrac;

        /**
         * Distance before door loses collisions (total%) (vertical height % until Bond can walk through).
         * Offset 0x88.
         */
        f32                perimFrac;

        /**
         * Start moving acceleration rate (when a door is first opened/closed).
         * Offset 0x8c.
         */
        f32                accel;

        /**
         * Start slowing down acceleration rate (when a door is almost entirely opened/closed).
         * Offset 0x90.
         */
        f32                decel;

        /**
         * Maximum speed door can move on each update.
         * Offset 0x94.
         */
        f32                maxSpeed;

        /**
         * open technique (2+2 bytes).
         *
         *  0000 0000	slider (left/right) clears the door away as it slides, stopping visual problems when opening into a wall
         *  0004 0000	slider (left/right)
         *  0000 0004	shutter (up/down) clears the door as it slides
         *  0004 0004	shutter (up/down)
         *  0000 0005	special (swinging) defined here
         *  0000 0006	special (eye) defined here in block
         *  0000 0007	special (iris) defined here
         *
         * Offset 0x98.
         */
        u16                doorFlags;

        /**
         * See doorFlags.
         * Offset 0x9a.
         */
        u16                doorType;

        /**
         * nonzero to lock.
         * Offset 0x9c.
         */
        u32                keyflags;

        /**
         * Number of frames the door remains open before closing.
         * Offset 0xa0.
         */
        u32                autoCloseFrames;

        /**
         * Sound effect played when the door is opened.
         * (Actually sets the initial open, continued opening, and final open sounds).
         * Offset 0xa4.
         */
        u32                doorOpenSound;

        /**
         * Max fraction open, aka max displacement.
         * Offset 0xa8.
         */
        f32                frac;

        f32                unkac; /*0xac*/
        f32                unkb0; /*0xb0*/

        /**
         * Current distance travelled, aka displacement percent.
         * Offset 0xb4.
         */
        f32                openPosition;

        /**
         * Current speed of the door as it is opening or closing.
         * Offset 0xb8.
         */
        f32                speed;

        /**
         * Current open/close/other state of the door.
         * States are defined in enum DOORSTATE, but asm expects a single byte.
         * Offset 0xbc.
         */
        s8                 openstate;

        u8                 unkbd; /*0xbd*/

        // something related to rendering
        s16                calculatedopacity;      /*0xbe*/
        s32                TintDist;      /*0xc0*/
        s16                CullDist;      /*0xc4*/
        s8                 soundType;  /*0xc6*/
        s8                 fadeTime60; /*0xc7*/

        /**
        * Connected door. Opening/closing this door will also open the linkedDoor.
        * Offset 0xc8.
        */
        struct DoorRecord *linkedDoor;

        Vertex*            unkcc; /*0xcc*/

        // maybe struct ModelRoData_BoundingBoxRecord *
        u32 unkd0;

        u32                unkd4;
        u32                unkd8;
        u32                unkdc;
        u32                unke0;
        u32                unke4;
        u32                unke8;

        /**
         * When the door completely opens, the current global timer value is
         * copied into this property. Once autoCloseFrames have elapsed
         * (once the difference between the timer and this value has exceeded autoCloseFrames)
         * the door will start closing.
         * Offset 0xec.
         */
        u32                openedTime;

        /**
         * Portal number.
         * Offset 0xf0.
         */
        s32                portalNumber;

        /**
         * Unknown. Changes at runtime. Appears to be set to a pointer
         * while the door is moving, then cleared when the door is stationary.
         * If you reset this to 0 (NULL pointer), then the door opening
         * sound never stops playing.
         */
        ALSoundState *openSoundState;

        ALSoundState *closeSoundState;

        /**
         * Copy of global timer value.
         * Offset 0xfc.
         */
        u32                timer;
    } DoorRecord;

    #define New_DoorRecord(pad)                               \
        {                                                     \
            New_PropDefHeaderRecord(1), New_ObjectRecord(pad) \
        }

   
    /** PROPDEF_GLOBAL_DOOR_SCALE (2)
     * The value is used for door calculations.  Changing it will shrink/enlarge doors.
     * Why they ever made it is beyond me.
     * @param Scale: Fixed-Point converted to float and divided by 65536 (0x10000)
     */
    typedef struct GlobalDoorScaleRecord 
    {
        inherits PropDefHeaderRecord;
        s32      Scale;
    } GlobalDoorScaleRecord;

    #define New_GlobalDoorScaleRecord(Scale)      \
        {                                         \
            New_PropDefHeaderRecord(2), Scale + 0 \
        }

    // PROPDEF_PROP (3) - See ObjectRecord above

    // PROPDEF_KEY (4)
    typedef struct KeyRecord
    {
        inherits ObjectRecord;
        union
        {
            s8  keyID;
            u32 keyflags;
        };
    } KeyRecord;

    #define New_KeyRecord              \
        {                              \
            New_PropDefHeaderRecord(4) \
        }

    // PROPDEF_ALARM = ObjectRecord (5)
    #define New_AlarmRecord(pad)                   \
        {                                          \
            New_PropDefHeaderRecord(5), 0, pad + 0 \
        }

    struct beam {
        /*0x00*/ s8 age;
        /*0x01*/ s8 weaponnum;
        /*0x04*/ struct coord3d from;
        /*0x10*/ struct coord3d dir;
        /*0x1c*/ f32 maxdist;
        /*0x20*/ f32 speed;
        /*0x24*/ f32 mindist;
        /*0x28*/ f32 dist;
    };

    typedef struct AutogunRecord
    {
        inherits ObjectRecord;
        s32 padID; // 0x80

        // Units seem to be radians.
        f32 rot_related; // 0x84

        // Units seem to be radians.
        f32 unk88;

        // yzero or limit related. Units might be radians.
        f32 unk8C;

        // Units seem to be radians. Changes when active/firing.
        f32 unk90;

        // changes when active/firing
        f32 unk94;
        f32 unk98;

        // changes when active/firing
        f32 unk9C;

        // Units seem to be radians. Changes when active/firing
        f32 unkA0;

        // How fast the gun turns. Runway default is around 0.01f.
        f32 speed; // 0xA4

        /**
         * Distance before deactivating.
         * Default (on Runway at least): 7500.0f
         * Offset 0xa0.
        */
        f32 aimdist; // 0xA8
        s32 unkAC;

        // changes when active/firing
        f32 unkB0;

        // changes when active/firing
        f32 unkB4;
        s32 unkB8;
        s32 unkBC;
        s32  unkC0;
        ALSoundState *unkC4;
        ALSoundState *unkC8;
        struct beam *beam;

        /**
         * Offset 0xd0.
         * Used in object_interaction, setting to zero won't disable.
        */
        s32 is_active; // 0xD0

        // changes when active/firing
        f32 unkD4;
    } AutogunRecord;

    // PROPDEF_CCTV (6)
    typedef struct CCTVRecord
    {
        struct ObjectRecord;
        s32 unk80;
        Mtxf unk84;
        f32 unkC4;
        f32 unkC8;
        f32 unkCC;
        
        f32 unkD0;
        s32 unkD4;
        f32 unkD8;
        f32 unkDC;
        
        s32 timer; // 0xe0
        s32 unkE4;
        f32 unkE8;
        s32 unkEC;
        
        s32 unkF0;
        s32 unkF4;
        s32 unkF8;
    } CCTVRecord;

    #define New_CCTVRecord(pad)                    \
        {                                          \
            New_PropDefHeaderRecord(6), 0, pad + 0 \
        }

    // PROPDEF_MAGAZINE (7)
    typedef struct AmmoCrateRecord
    {
        inherits ObjectRecord;
        AMMOTYPE ammoType; /*0x80*/
    } AmmoCrateRecord;

    #define New_AmmoCrateRecord(pad)               \
        {                                          \
            New_PropDefHeaderRecord(7), 0, pad + 0 \
        }

    // PROPDEF_COLLECTABLE (8)
    typedef struct WeaponObjRecord
    {
        inherits                ObjectRecord;
        s8                      weaponnum;        /*0x80 ITEM_IDS*/
        s8                      LinkedWeaponType; /*0x81*/
        s16                     timer;            /*0x82*/
        //u8 thrown;        // Dragon and Laptop Gun /*0x83*/
        //s8 unk60;         /*0x60*/
        //s8 dualweaponnum; /*0x61*/

        /**
         * Appears to have multiple uses:
         * Grenades = timer?
         * Proxy mines = timer? Or isarmed
         * CTC briefcase = team index
         */
        //s16 unk62; /*0x62*/

        struct WeaponObjRecord *dualweapon; // other weapon when dual wielding /*0x84*/
    } WeaponObjRecord;

    #define New_WeaponObjRecord(pad)               \
        {                                          \
            New_PropDefHeaderRecord(8), 0, pad + 0 \
        }

    // PROPDEF_GUARD (9) (7 words)
    typedef struct GuardRecord
    {
        inherits   PropDefHeaderRecord;
        u16        chrnum;       /*0x4*/
        u16        PadID;        /*0x6*/
        u16        BodyID;       /*0x8*/
        u16        AIListID;     /*0xa*/
        u16        Preset;       /*0xc*/
        u16        chrpreset1;   /*0xe*/
        u16        health;       /*0x10*/
        u16        ReactionTime; /*0x12*/

        /**
         * Bitflags.
         * See enum GUARD_SETUP_FLAG.
        */
        u16        bitflags;     /*0x14*/
        s16        HeadID;       /*0x16*/
        ChrRecord *Data;         /*0x18*/
    } GuardRecord;

    #define New_GuardRecord(pad)                   \
        {                                          \
            New_PropDefHeaderRecord(9), 0, pad + 0 \
        }

    //[This struct uses original names]
    typedef struct MonitorRecord
    {
        u32 *cmdlist;   // 0x80	4	image pointer for this monitor
        u16 offset;     // 0x84	2	[runtime] cur. #commands from start of routine
        s16 pause60;    // 0x86	2	[runtime] loop counter
        struct sImageTableEntry *tconfig;      //0x88	4	[runtime] monitor image# or p->image header
        f32 rot;        // 0x8C 4 [runtime][float] rotation
        f32 xscale;     // 0x90	4	[runtime] [float] cur. horizontal zoom
        f32 xscalefrac; // 0x94	4	[runtime] [float] cur. h.zoom time
        f32 xscaleinc;  // 0x98	4	[runtime] [float] final h.zoom time
        f32 xscaleold;  // 0x9C	4	[runtime] [float] initial h.zoom
        f32 xscalenew;  // 0xA0	4	[runtime] [float] final h.zoom
        f32 yscale;     // 0xA4	4	[runtime] [float] cur. vertical zoom
        f32 yscalefrac; // 0xA8	4	[runtime] [float] cur. v.zoom time
        f32 yscaleinc;  // 0xAC	4	[runtime] [float] final v.zoom time
        f32 yscaleold;  // 0xB0	4	[runtime] [float] initial v.zoom
        f32 yscalenew;  // 0xB4	4	[runtime] [float] final v.zoom
        f32 xmid;       // 0xB8	4	[runtime] [float] cur. horizontal position
        f32 xmidfrac;   // 0xBC	4	[runtime] [float] cur. h.scroll time
        f32 xmidinc;    // 0xC0	4	[runtime] [float] final h.scroll time
        f32 xmidold;    // 0xC4	4	[runtime] [float] initial h.pos.
        f32 xmidnew;    // 0xC8	4	[runtime] [float] final h.pos.
        f32 ymid;       // 0xCC	4	[runtime] [float] cur. vertical position
        f32 ymidfrac;   // 0xD0	4	[runtime] [float] cur. v.scroll time
        f32 ymidinc;    // 0xD4	4	[runtime] [float] final v.scroll time
        f32 ymidold;    // 0xD8	4	[runtime] [float] initial v.pos.
        f32 ymidnew;    // 0xDC	4	[runtime] [float] final v.pos.
        u8  red;        // 0xE0	1	[runtime] cur. Red
        u8  redold;     // 0xE1	1	[runtime] initial R
        u8  rednew;     // 0xE2	1	[runtime] final R
        u8  green;      // 0xE3	1	[runtime] cur. Green
        u8  greenold;   // 0xE4	1	[runtime] initial G
        u8  greennew;   // 0xE5	1	[runtime] final G
        u8  blue;       // 0xE6	1	[runtime] cur. Blue
        u8  blueold;    // 0xE7	1	[runtime] initial B
        u8  bluenew;    // 0xE8	1	[runtime] final B
        u8  alpha;      // 0xE9	1	[runtime] cur. Alpha
        u8  alphaold;   // 0xEA	1	[runtime] initial A
        u8  alphanew;   // 0xEB	1	[runtime] final A
        f32 colfrac;    // 0xEC	4	[runtime] [float] cur. colour transition time
        f32 colinc;     // 0xF0	4	[runtime] [float] final colour transition time
    } MonitorRecord;

    // PROPDEF_MONITOR (10)
    typedef struct MonitorObjRecord /*116 (0x74) long*/
    {
        inherits      ObjectRecord;
        MonitorRecord Monitor;
        s32           OwnerOffset;
        s32           OwnerPart;
        s32           ImageNum;
    } MonitorObjRecord;
    #define New_MonitorObjRecord(pad)               \
        {                                           \
            New_PropDefHeaderRecord(10), 0, pad + 0 \
        }

    // PROPDEF_MULTI_MONITOR (11)
    typedef struct MultiMonitorObjRecord
    {
        inherits      ObjectRecord;
        MonitorRecord Monitor[4];
        u8            ImageNums[4];
    } MultiMonitorObjRecord;
    #define New_MultiMonitorObjRecord(pad)                \
        {                                           \
            New_PropDefHeaderRecord(11), 0, pad + 0 \
        }

    // PROPDEF_RACK (12) - see ObjectRecrd
        #define New_RackRecord(pad)                  \
        {                                           \
            New_PropDefHeaderRecord(12), 0, pad + 0 \
        }

    // PROPDEF_AUTOGUN (13)
    #define New_AutogunRecord(pad)                  \
        {                                           \
            New_PropDefHeaderRecord(13), 0, pad + 0 \
        }

    // PROPDEF_LINK (14)
    typedef struct LinkRecord
    {
        inherits PropDefHeaderRecord;
        s32      Index1;
        s32      Index2;
    } LinkRecord;
    #define New_LinkRecord(ID1, ID2)                      \
        {                                                 \
            New_PropDefHeaderRecord(14), ID1 + 0, ID2 + 0 \
        }

    //Types 15,16 missing?

    // PROPDEF_HAT (17)
    typedef struct HatRecord
    {
        inherits ObjectRecord;
    } HatRecord;

    // PROPDEF_GUARD_ATTRIBUTE (18)
    typedef struct GuardAttributeRecord
    {
        inherits PropDefHeaderRecord;
        s32      chrnum; //0x4
        s16      unk8; //0x8
        s8       unkA;   // 0xa  
        s8       GrenadeProb; //0xb
    } GuardAttributeRecord;
    #define New_SwitchRecord(ID1, ID2)                    \
        {                                                 \
            New_PropDefHeaderRecord(19), ID1 + 0, ID2 + 0 \
        }

    // PROPDEF_SWITCH (19) - see LinkRecord
    #define New_SwitchRecord(ID1, ID2)                    \
        {                                                 \
            New_PropDefHeaderRecord(19), ID1 + 0, ID2 + 0 \
        }

    // PROPDEF_AMMO (20)
    typedef struct MultiAmmoCrateRecord
    {
        inherits ObjectRecord;
        s16      unk80;
        u16      quantities[AMMOTYPE_GLOBAL_MAX]; // indexed by ammotype /*0x80*/
    } MultiAmmoCrateRecord;
    #define New_MultiAmmoCrateRecord(pad)           \
        {                                           \
            New_PropDefHeaderRecord(20), 0, pad + 0 \
        }

    // PROPDEF_ARMOUR (21)
    typedef struct BodyArmourRecord
    {
        inherits ObjectRecord;
        u32      Strength;
    } BodyArmourRecord;
    #define New_BodyArmourRecord(pad)               \
        {                                           \
            New_PropDefHeaderRecord(21), 0, pad + 0 \
        }

    // PROPDEF_TAG (22)
    typedef struct TagObjectRecord
    {
        inherits                PropDefHeaderRecord;
        u16                     ID;
        s16                     OffsetToObj; //offset from tag
        struct TagObjectRecord *NextTag;
        ObjectRecord *          TaggedObject;
    } TagObjectRecord;
#define New_TagObjectRecord(Object)                \
    {                                              \
        New_PropDefHeaderRecord(22), 0, Object + 0 \
    }

    // PROPDEF_WATCH_MENU_OBJECTIVE_TEXT (35)
    typedef struct WatchMenuObjectiveTextRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } WatchMenuObjectiveTextRecord;
#define New_CollectObjectRecord(TagID)         \
    {                                          \
        New_PropDefHeaderRecord(28), TagID + 0 \
    }

    // PROPDEF_OBJECTIVE_x (23,24 ) - maybe wrong...
    typedef struct MissionObjectiveRecord
    {
        inherits                      PropDefHeaderRecord; /*0*/
        s32                           ObjRefID;            /*4*/
        u32                           TextID;              /*8*/
        DIFFICULTY                    MinDificulty;        /*c*/
        WatchMenuObjectiveTextRecord *nextentry;           /*10*/
    } MissionObjectiveRecord;
    #define New_MissionObjectiveRecord(TextID)         \
        {                                              \
            New_PropDefHeaderRecord(23), 0, TextID + 0 \
        }
    #define New_EndMissionObjectiveRecord(TextID)      \
        {                                              \
            New_PropDefHeaderRecord(24), 0, TextID + 0 \
        }

    // PROPDEF_OBJECTIVE_DESTROY_OBJECT (25)
    typedef struct DestroyObjectRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } DestroyObjectRecord;
    #define New_DestroyObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(25), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_COMPLETE_CONDITION (26)
    typedef struct CompleteConditionRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } CompleteConditionRecord;
    #define New_CompleteConditionRecord(TagID)     \
        {                                          \
            New_PropDefHeaderRecord(25), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_FAIL_CONDITION (27)
    typedef struct FailConditionRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } FailConditionRecord;
    #define New_FailConditionRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(27), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_COLLECT_OBJECT (28)
    typedef struct CollectObjectRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } CollectObjectRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_DEPOSIT_OBJECT (29) 
    typedef struct DepositObjectRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } DepositObjectRecord;
#define New_CollectObjectRecord(TagID)         \
    {                                          \
        New_PropDefHeaderRecord(28), TagID + 0 \
    }

    // PROPDEF_OBJECTIVE_PHOTOGRAPH (30)
    typedef struct PhotographObjectRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } PhotographObjectRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_NULL (31)
    typedef struct NULLObjectRecord
    {
        inherits PropDefHeaderRecord;
    } NULLObjectRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_ENTER_ROOM (32)
    typedef struct EnterRoomRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } EnterRoomRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM (33)
    typedef struct DepositObjectInRoomRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } DepositObjectInRoomRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_OBJECTIVE_COPY_ITEM (34)
    typedef struct CoopyObjectRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } CoopyObjectRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_GAS_RELEASING (36)
    typedef struct GasReleasingRecord
    {
        inherits PropDefHeaderRecord;
        u16      unk4;
    } GasReleasingRecord;
    #define New_CollectObjectRecord(TagID)         \
        {                                          \
            New_PropDefHeaderRecord(28), TagID + 0 \
        }

    // PROPDEF_RENAME (37)
    typedef struct RenameObjectRecord
    {
        inherits PropDefHeaderRecord;
        //u16 TagID;
    } RenameObjectRecord;
    #define New_RenameObjectRecord(TagID)          \
        {                                          \
            New_PropDefHeaderRecord(37), TagID + 0 \
        }

    // PROPDEF_LOCK_DOOR (38)
    typedef struct LockDoorRecord
    {
        inherits PropDefHeaderRecord;
        struct DoorRecord*     door;
        struct ObjectRecord*   lock;
        struct LockDoorRecord* next;
        //u16 TagID;
    } LockDoorRecord;
    #define New_RenameObjectRecord(TagID)          \
        {                                          \
            New_PropDefHeaderRecord(37), TagID + 0 \
        }

    // PROPDEF_TRUCK (39)
    // Vehichle Record attaches AI ailist to Object.
    // [This struct uses original names]
    typedef struct VehichleRecord
    {
        inherits    ObjectRecord;
        AIRecord *  ailist;       /*0x80*/
        u16         aioffset;     /*0x84*/
        s16         aireturnlist; /*0x86*/
        f32         speed;        /*0x88 ?*/
        f32         wheelxrot;    /*0x8c ? changes when onscreen*/
        f32         wheelyrot;    /*0x90 ?*/
        f32         speedaim;     /*0x94 CONFIRNMED*/
        f32         speedtime60;  /*0x98 CONFIRNMED*/
        f32         turnrot60;    /*0x9c*/
        f32         roty;         /*0xa0*/
        PathRecord *path;         /*0xa4*/
        s32         nextstep;     /*0xa8*/
        struct ALSoundState *Sound;      /*0xac*/
    } VehichleRecord;
    // VehichleRecord *pVehichleData;//not Global, local to Object or function
    // VehichleRecord *pAircraftData;//not Global, local to Object or function
    #define New_VehichleRecord(pad)                 \
        {                                           \
            New_PropDefHeaderRecord(39), 0, pad + 0 \
        }

    // PROPDEF_HELI (40)
    // Aircraft Record attaches Rotors to Vehichle.
    // [This struct uses original names]
    typedef struct AircraftRecord
    {
        inherits      ObjectRecord;
        AIRecord *    ailist;          /*0x80*/
        u16           aioffset;        /*0x84*/
        s16           aireturnlist;    /*0x86*/
        f32           rotoryrot;       /*0x88 changes when onscreen even after destruction*/
        f32           rotaryspeed;     /*0x8c*/
        f32           rotaryspeedaim;  /*0x90 CONFIRMED*/
        f32           rotaryspeedtime; /*0x94 CONFIRMED*/
        f32           speed;           /*0x98*/
        f32           speedaim;        /*0x9c*/
        f32           speedtime60;     /*0xa0*/
        f32           yrot;            /*0xa4*/
        f32           nextstep;        /*0xa8*/
        PathRecord   *path;            /*0xac*/
        struct ALSoundState *Sound;           /*0xb0*/
    } AircraftRecord;
    #define New_AircraftRecord(pad)                 \
        {                                           \
            New_PropDefHeaderRecord(40), 0, pad + 0 \
        }

    //PROPDEF_UNKNOWN (41)

    //PROPDEF_glass (42)
    typedef struct GlassRecord
    {
        inherits ObjectRecord;
        coord3d  normal;
    } GlassRecord;

    //PROPDEF_SAFE (42)
    typedef struct SafeRecord
    {
        inherits ObjectRecord;
        coord3d  normal;
    } SafeRecord;

    //PROPDEF_SAFE_ITEM (42)
    typedef struct SafeObjectRecord
    {
        u32 unk00;
        struct ObjectRecord *item;
        struct SafeRecord *safe;
        struct DoorRecord *door;
        struct SafeObjectRecord *next;
    } SafeObjectRecord;

    // PROPDEF_TANK (45)
    // [This struct uses original names] - Locs need confirming
    typedef struct TankRecord
    {
        inherits ObjectRecord;
        struct collision_data *unk80;
        struct rect4f  rect;       /*0x84*/
        //s32 unk88;
        //s32 unk8C;
        //s32 unk90;
        //s32 unk94;
        //s32 unk98;
        //s32 unk9C;
        //s32 unkA0;
        s32 unkA4;
        s32 unkA8;
        s32 unkAC;
        s32 unkB0;
        s32 unkB4;
        s32 unkB8;
        s32 unkBC;
        s32 unkC0;
        s32 is_firing_tank;
        f32 turret_vertical_angle;
        f32 turret_orientation_angle;
        f32 unkD0;
        f32 stan_y;
        s32 unkD8; // ammo related
        f32 tank_orientation_angle;
    } TankRecord;
    #define New_TankRecord(pad)                     \
        {                                           \
            New_PropDefHeaderRecord(45), 0, pad + 0 \
        }

    // PROPDEF_CAMERAPOS (46)
    typedef struct CutsceneRecord
    {
        inherits PropDefHeaderRecord;
        struct coord3d pos;
        f32      theta; //10
        f32      verta; //14
        s32      pad;   //18
    } CutsceneRecord;
    #define New_CutsceneRecord(pad)                             \
        {                                                       \
            New_PropDefHeaderRecord(46), 0, 0, 0, 0, 0, pad + 0 \
        }

    // objtype 47
    typedef struct TintedGlassRecord
    {
        inherits ObjectRecord;
        s32      TintDist;
        s32      CullDist;
        s32      calculatedopacity;
        s32      unk8c;
        f32      unk90;
    } TintedGlassRecord;
    #define New_TintedGlassRecord(pad)              \
        {                                           \
            New_PropDefHeaderRecord(47), 0, pad + 0 \
        }
    // objtype 48+
    #define EndObjectList PropDefHeaderRecord endme = New_PropDefHeaderRecord(48)
    #pragma endregion IndividualObjectTypes
#pragma endregion

#pragma region Intro

union SetupFloatInt
{
    f32 fval;
    s32 ival;
};

/**
 * sizeof == 0x4
*/
struct SetupIntroEmpty
{
    s32 type;
};

/**
 * type == INTROTYPE_SPAWN
 * sizeof == 0xc
*/
struct SetupIntroSpawn
{
    s32 type;
    s32 index;
    s32 is_demo_playback;
};

/**
 * type == INTROTYPE_ITEM
 * sizeof == 0x10
*/
struct SetupIntroItem
{
    s32 type;
    s32 item_right;
    s32 item_left;
    s32 is_demo_playback;
};

/**
 * type == INTROTYPE_AMMO
 * sizeof == 0x10
*/
struct SetupIntroAmmo
{
    s32 type;
    s32 ammo_type;
    s32 ammo_amount;
    s32 is_demo_playback;
};

/**
 * type == INTROTYPE_SWIRL
 * sizeof == 0x20
*/
struct SetupIntroSwirl
{
    s32 type;
    s32 unk04;
    union SetupFloatInt unk08;
    union SetupFloatInt unk0C;
    union SetupFloatInt unk10;
    union SetupFloatInt unk14;
    union SetupFloatInt unk18;
    s32 unk1C;
};

/**
 * type == INTROTYPE_ANIM
 * sizeof == 0x8
*/
struct SetupIntroAnim
{
    s32 type;
    s32 intro_anim;
};

/**
 * type == INTROTYPE_CUFF
 * sizeof == 0x8
*/
struct SetupIntroCuff
{
    s32 type;
    s32 bondtype;
};

/**
 * type == INTROTYPE_CAMERA
 * sizeof == 0x28
*/
struct SetupIntroCamera
{
    s32 type;
    union SetupFloatInt unk04;
    union SetupFloatInt unk08;
    union SetupFloatInt unk0C;
    union SetupFloatInt unk10;
    union SetupFloatInt unk14;
    s32 unk18;
    union {
        u16 lang_index[2];
        char* lang_ptr;
    } lang1c;
    union {
        s32 lang_index;
        char *lang_ptr;
    } lang20;
    struct SetupIntroCamera *prev;
};

/**
 * type == INTROTYPE_WATCH
 * sizeof == 0xc
*/
struct SetupIntroWatch
{
    s32 type;
    s32 hours;
    s32 minutes;
};

/**
 * sizeof == 0xc
*/
typedef struct CreditsEntry_s {
    u16 TextId1;
    u16 TextId2;
    s16 Position1;

    /**
     * See CREDITS_ALIGNMENT.
    */
    u16 Alignment1;

    s16 Position2;

    /**
     * See CREDITS_ALIGNMENT.
    */
    u16 Alignment2;

} CreditsEntry;

/**
 * type == INTROTYPE_CREDITS
 * sizeof == 0x8
*/
struct SetupIntroCredits
{
    s32 type;
    s32 unk04;
};


#pragma endregion Intro

#pragma region Objectives
    // PROPDEF_WATCH_MENU_OBJECTIVE_TEXT (35)
    struct watchMenuObjectiveText
    {
        u32                            id;
        enum WATCH_BRIEFING_PAGE       menu;
        u16                            reserved;
        u16                            text;
        struct watchMenuObjectiveText *nextentry;
    };
    // PROPDEF_OBJECTIVE_x (23,24 ) - maybe not a propdef
    //!FIXME all but text field cannot be trusted
    struct objective_entry
    {
        u32                            id; //0
        enum WATCH_BRIEFING_PAGE       menu;//4
        u16                            reserved;//8
        u16                            text; //a
        u16                            unkC; //c
        s8                             unkD; //d
        s8                             difficulty; //f
    };
#pragma endregion Objectives

#pragma region gamefile
#pragma endregion gamefile

#pragma region Images
    typedef struct sImageTableEntry
    {
        u32 index;
        u8  width;
        u8  height;
        u8  level;
        u8  format;
        u8  depth;
        u8  flagsS;
        u8  flagsT;
        u8  pad;
    } sImageTableEntry;
#pragma endregion Images

#pragma region Player

    typedef struct SkyRelated38 {
        f32 unk00; /*0x00*/
        f32 unk04; /*0x04*/
        f32 unk08; /*0x08*/
        f32 unk0c; /*0x0c*/
        f32 r;     /*0x10*/
        f32 g;     /*0x14*/
        f32 b;     /*0x18*/
        f32 a;     /*0x1c*/
        f32 unk20; /*0x20*/
        f32 unk24; /*0x24*/
        f32 unk28; /*0x28*/
        f32 unk2c; /*0x2c*/
        f32 unk30; /*0x30*/
        f32 unk34; /*0x34*/
    } SkyRelated38;

    typedef struct SkyRelated18 {
        f32 unk00; /*0x00*/
        f32 unk04; /*0x04*/
        f32 unk08; /*0x08*/
        f32 unk0c; /*0x0c*/
        f32 unk10; /*0x10*/
        u8 r;      /*0x14*/
        u8 g;      /*0x15*/
        u8 b;      /*0x16*/
        u8 a;      /*0x17*/
    } SkyRelated18;

#pragma endregion Player

#pragma region stagesetup.h
        typedef struct stagesetup
        {
            waypoint       *pathwaypoints;
            waygroup       *waypointgroups;
            struct SetupIntroEmpty *intro;
            PropDefHeaderRecord    *propDefs;
            PathRecord     *patrolpaths;
            AIListRecord   *ailists;
            PadRecord      *pads;
            BoundPadRecord *boundpads;
            char           *padnames;
            char           *boundpadnames;
        } stagesetup;


#pragma endregion stagesetup.h

        typedef struct sfxRecord //Need 24 size
        {
            ALSoundState *state; //0
            s32           Volume2;   //4
            s32           sfxID;     //8
            s32           Volume;    //12
            coord3d      *pos;       //16
            ObjectRecord *Obj;       //20
        } sfxRecord;


















typedef struct object_standard {
    s16 scale;
    u8 state;
    u8 type;
    u16 objectID;
    u16 presetID;
    u32 flags1;
    u32 flags2;
    void* ptrPOSData;
    void* ptrObjInstanceController;
    f32 runtime_MATRIX[4][4];
    f32 xPOS;
    f32 yPOS;
    f32 zPOS;
    int bitflags;
    int ptrCollisionblock;
    int field_6C;
    float field_70;
    short damage;
    short maxdamage;
    int field_78;
    int field_7C;
} object_standard;

typedef struct object_weapon {
    object_standard object;
    u8 gun_pickup;
    u8 linked_item;
    s16 timer;
    void* ptr_linkeditem;
} object_weapon;


struct MoveData {
    // 0x0, bondviewProcessInput sp120
    s32 analogWalk;  // sp120 ?
    s32 analogStrafe;  // sp124 ?
    s32 analogPitch; // sp128 ?
    s32 analogTurn; // sp12C ?

    // 0x10
    s32 controlStickYRaw;
    s32 controlStickXRaw;
    s32 controlStickYSafe;
    s32 controlStickXSafe;

    // 0x20
    s32 disableLookAhead;
    s32 invertPitch;
    s32 canAutoAim;
    s32 detonating;

    // 0x30
    s32 rLeanRight;
    s32 rLeanLeft;
    s32 crouchUp;
    s32 crouchDown;

    // 0x40, bondviewProcessInput sp160
    f32 zoomInFovPersec;
    // sp164
    f32 zoomOutFovPersec;
    s32 zooming;
    s32 aiming;
    
    // 0x50
    s32 weaponForwardOffset;
    s32 weaponBackOffset;
    f32 aimTurnRightSpeed;
    f32 aimTurnLeftSpeed;

    // 0x60
    f32 speedVertaUp;
    f32 speedVertaDown;
    f32 tankTurnRightSpeed;
    f32 tankTurnLeftSpeed;

    // 0x70
    s32 digitalStepRight;
    s32 digitalStepLeft;
    s32 digitalStepBack;
    s32 digitalStepForward;

    // 0x80
    s32 canNaturalPitch;
    s32 canNaturalTurn;
    s32 canTurnTank;
    s32 canLookAhead;

    // 0x90
    s32 btap;
    s32 triggerOn;
    s32 canManualAim;
    // sp1BC
    s32 canSwivelGun;
};


struct unkown_gun_struct
{
    union
    {
        u32 arr[2];
        struct
        {
            s32 unk00;
            s32 unk04;        
        };
    };
};

/* matches Perfect Dark */
struct criteria_roomentered {
    u32 unk00;
    u32 pad;
    u32 status;
    struct criteria_roomentered *next;
};

/* completely made up */
struct criteria_deposit {
    s32 unk00;
    s32 weaponnum;
    s32 padid;
    s32 flag;
    struct criteria_deposit *next;
};

struct PortalMetric {
    struct coord3d normal;
    f32 min;
    f32 max;
};

struct FolderSelect {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

#endif
