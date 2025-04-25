#include <bondtypes.h>
#define TEXTURECOUNT 6

#define VERTEXGROUPCOUNT0 16
#define COLLISIONVERTEXCOUNT0 13

#define VERTEXGROUPCOUNT1 4
#define COLLISIONVERTEXCOUNT1 4

#define VERTEXGROUPCOUNT2 24
#define COLLISIONVERTEXCOUNT2 12


extern ModelNode ModelNode1;
extern ModelNode ModelNode2;
extern ModelNode ModelNode3;
extern ModelNode ModelNode4;

extern ModelFileTextures proptextures[TEXTURECOUNT];

extern ModelNode ModelNodeGroup_0;
extern ModelNode ModelNodeBB_0;
extern ModelNode ModelNodeDL_Mount;
extern ModelNode ModelNodeGroup_1;
extern ModelNode ModelNodeSwitch_0;
extern ModelNode ModelNodeBB_Lens;
extern ModelNode ModelNodeDL_Lens;
extern ModelNode ModelNodeDL_Housing;


extern ModelRoData_GroupRecord GroupRecord_0x118;
extern ModelRoData_GroupRecord GroupRecord_0x118;
extern ModelRoData_BoundingBoxRecord BBoxRecord_0x134;
extern Vertex Vertex_ARRAY_0x150[VERTEXGROUPCOUNT0];
extern Vertex Collision_Vertex_ARRAY_0x250[COLLISIONVERTEXCOUNT0];
extern s16 POINT_USAGE_ARRAY_0x320[VERTEXGROUPCOUNT0];
extern ModelRoData_DisplayList_CollisionRecord DL_Mount;
extern ModelRoData_GroupRecord GroupRecord_0x360;
extern ModelRoData_SwitchRecord Switch_0x37c;
extern ModelRoData_BoundingBoxRecord BBox_Lens;
extern Vertex Vertex_ARRAY_0x3a0[VERTEXGROUPCOUNT1];
extern Vertex Collision_Vertex_ARRAY_0x3e0[COLLISIONVERTEXCOUNT1];
extern s16 POINT_USAGE_ARRAY_0x420[VERTEXGROUPCOUNT1];
extern ModelRoData_DisplayList_CollisionRecord DL_Lens;
extern Vertex Vertex_ARRAY_0x448[VERTEXGROUPCOUNT2];
extern Vertex Collision_Vertex_ARRAY_0x5c8[COLLISIONVERTEXCOUNT2];
extern s16 POINT_USAGE_ARRAY_0x688[VERTEXGROUPCOUNT2];
extern ModelRoData_DisplayList_CollisionRecord DL_Housing;
extern Gfx GFX_ARRAY_PRIMARY_0x6d8[];
extern Gfx GFX_ARRAY_SECONDARY_0x738[];
extern Gfx GFX_ARRAY_PRIMARY_0x790[];
extern Gfx GFX_ARRAY_SECONDARY_0x7a8[];
extern Gfx GFX_ARRAY_PRIMARY_0x810[];


ModelNode* ModelNode1 = &ModelNodeGroup_1;
ModelNode* ModelNode2 = &ModelNodeDL_Lens;
ModelNode* ModelNode3 = &ModelNodeBB_Lens;
ModelNode* ModelNode4 = &ModelNodeSwitch_0;

ModelFileTextures proptextures[TEXTURECOUNT] = 
{
    {IMAGE_247, 0x20, 0x40, 0x07, 0x00, 0x01, 0x00, 0x0000},
    {IMAGE_265, 0x40, 0x20, 0x07, 0x00, 0x01, 0x00, 0x0000},
    {IMAGE_511, 0x80, 0x20, 0x07, 0x00, 0x00, 0x00, 0x0000},
    {IMAGE_856, 0x40, 0x40, 0x07, 0x00, 0x00, 0x00, 0x0000},
    {IMAGE_GLASS3, 0x36, 0x36, 0x03, 0x00, 0x01, 0x02, 0x0200},
    {IMAGE_1514, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x0000},
};

                            //  {                       opcode,               data,             parent,                  next,                prev,              child}
ModelNode ModelNodeGroup_0    = {       MODELNODE_OPCODE_GROUP, &GroupRecord_0x118,               NULL,                  NULL,                NULL,     &ModelNodeBB_0};
ModelNode ModelNodeBB_0       = {        MODELNODE_OPCODE_BBOX,  &BBoxRecord_0x134,  &ModelNodeGroup_0,                  NULL,                NULL, &ModelNodeDL_Mount};
ModelNode ModelNodeDL_Mount   = { MODELNODE_OPCODE_DLCOLLISION,          &DL_Mount,     &ModelNodeBB_0,     &ModelNodeGroup_1,                NULL,               NULL};
ModelNode ModelNodeGroup_1    = {       MODELNODE_OPCODE_GROUP, &GroupRecord_0x360,     &ModelNodeBB_0,                  NULL,  &ModelNodeDL_Mount, &ModelNodeSwitch_0};
ModelNode ModelNodeSwitch_0   = {      MODELNODE_OPCODE_SWITCH,      &Switch_0x37c,  &ModelNodeGroup_1,  &ModelNodeDL_Housing,                NULL,  &ModelNodeBB_Lens};
ModelNode ModelNodeBB_Lens    = {        MODELNODE_OPCODE_BBOX,         &BBox_Lens, &ModelNodeSwitch_0,                  NULL,                NULL,  &ModelNodeDL_Lens};
ModelNode ModelNodeDL_Lens    = { MODELNODE_OPCODE_DLCOLLISION,           &DL_Lens,  &ModelNodeBB_Lens,                  NULL,                NULL,               NULL};
ModelNode ModelNodeDL_Housing = { MODELNODE_OPCODE_DLCOLLISION,        &DL_Housing,  &ModelNodeGroup_1,                  NULL,  &ModelNodeSwitch_0,               NULL};

ModelRoData_GroupRecord GroupRecord_0x118 =
{
    {0.005449, -773.8468, -200.64182},
    0x0,
    0x0,
     -1,
     -1,
    &ModelNodeGroup_1,
    291.0673
};

ModelRoData_BoundingBoxRecord BBoxRecord_0x134 = 
{
    0x1,
    {-482.0, 482.0, -119.0, 552.0, -247.0, 514.0}
};

Vertex Vertex_ARRAY_0x150[VERTEXGROUPCOUNT0] =
{
    {{     98,   -119,   -247}, 0x0000, 0x0002, 0x01f2, {0xc6, 0xc6, 0xc6, 0xff} },
    {{      0,     16,     84}, 0x0000, 0x03f6, 0x038b, {0x72, 0x72, 0x72, 0xff} },
    {{    -98,   -119,   -247}, 0x0000, 0x0006, 0x07e3, {0x72, 0x72, 0x72, 0xff} },
    {{      0,     16,     84}, 0x0000, 0x1000, 0x0000, {0xff, 0xff, 0xff, 0xff} },
    {{    -98,     16,   -247}, 0x0000, 0x0000, 0x0000, {0xc3, 0xc3, 0xc3, 0xff} },
    {{    -98,   -119,   -247}, 0x0000, 0x0000, 0xf9c0, {0xc0, 0xc0, 0xc0, 0xff} },
    {{     98,   -119,   -247}, 0x0000, 0x0000, 0x0640, {0xc6, 0xc6, 0xc6, 0xff} },
    {{     98,     16,   -247}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0xff, 0xff} },
    {{      0,     16,     59}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0xff, 0xff} },
    {{      0,     16,     10}, 0x0000, 0x0800, 0x0000, {0xfe, 0xfe, 0xfe, 0xff} },
    {{      0,     77,     10}, 0x0000, 0x0800, 0x0a00, {0xff, 0xff, 0xff, 0xff} },
    {{      0,     77,     59}, 0x0000, 0x0000, 0x0a00, {0xff, 0xff, 0xff, 0xff} },
    {{    -25,     16,     35}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0xff, 0xff} },
    {{     24,     16,     35}, 0x0000, 0x0800, 0x0000, {0xff, 0xff, 0xff, 0xff} },
    {{     24,     77,     35}, 0x0000, 0x0800, 0x0a00, {0xff, 0xff, 0xff, 0xff} },
    {{    -25,     77,     35}, 0x0000, 0x0000, 0x0a00, {0xff, 0xff, 0xff, 0xff} }
};

Vertex Collision_Vertex_ARRAY_0x250[COLLISIONVERTEXCOUNT0] =
{
    {{     98,   -119,   -247}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{      0,     16,     84}, 0x0001, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    -98,   -119,   -247}, 0x0002, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    -98,     16,   -247}, 0x0004, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{     98,     16,   -247}, 0x0007, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{      0,     16,     59}, 0x0008, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{      0,     16,     10}, 0x0009, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{      0,     77,     10}, 0x000a, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{      0,     77,     59}, 0x000b, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    -25,     16,     35}, 0x000c, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{     24,     16,     35}, 0x000d, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{     24,     77,     35}, 0x000e, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    -25,     77,     35}, 0x000f, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} }
};

s16 POINT_USAGE_ARRAY_0x320[VERTEXGROUPCOUNT0] =
{
       0x6,    0x3,    0x5,     -1,
        -1,     -1,     -1,     -1,
        -1,     -1,     -1,     -1,
        -1,     -1,     -1,     -1
};

ModelRoData_DisplayList_CollisionRecord DL_Mount = 
{
    GFX_ARRAY_PRIMARY_0x6d8,
    GFX_ARRAY_SECONDARY_0x738,
    Vertex_ARRAY_0x150,
    VERTEXGROUPCOUNT0,
    COLLISIONVERTEXCOUNT0,
    Collision_Vertex_ARRAY_0x250,
    POINT_USAGE_ARRAY_0x320,
    4,    0,
    0x0
};


ModelRoData_GroupRecord GroupRecord_0x360 = 
{
    {0.0, 70.36643, 31.983679},
    1,
    1,
    -1,
    -1,
    NULL,
    481.60675
};

ModelRoData_SwitchRecord Switch_0x37c = 
{
    &ModelNodeBB_Lens,
    0
};

ModelRoData_BoundingBoxRecord BBox_Lens = 
{
    0x2,
    {-123.0, 122.0, 6.0, 202.0, 199.0, 285.0}
};

 Vertex Vertex_ARRAY_0x3a0[VERTEXGROUPCOUNT1] =
{
    {{    122,    202,    285}, 0x0000, 0x0000, 0x0000, {0x47, 0x40, 0x53, 0xff} },
    {{   -123,    202,    285}, 0x0000, 0x0000, 0x0000, {0xb9, 0x40, 0x53, 0xff} },
    {{   -123,      6,    199}, 0x0000, 0x0000, 0x0000, {0xb9, 0xc0, 0x53, 0xff} },
    {{    122,      6,    199}, 0x0000, 0x0000, 0x0000, {0x47, 0xc0, 0x53, 0xff} },
};
 
Vertex Collision_Vertex_ARRAY_0x3e0[COLLISIONVERTEXCOUNT1] =
{							 
    {{    122,    202,    285}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,    202,    285}, 0x0001, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,      6,    199}, 0x0002, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,      6,    199}, 0x0003, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
};

s16 POINT_USAGE_ARRAY_0x420[VERTEXGROUPCOUNT1] = 
{
        -1,     -1,     -1,     -1
};

ModelRoData_DisplayList_CollisionRecord DL_Lens =
{
    GFX_ARRAY_PRIMARY_0x790,
    GFX_ARRAY_SECONDARY_0x7a8,
    Vertex_ARRAY_0x3a0,
    VERTEXGROUPCOUNT1,
    COLLISIONVERTEXCOUNT1,
    Collision_Vertex_ARRAY_0x3e0,
    POINT_USAGE_ARRAY_0x420,
    4,    0,
    0x0
};

Vertex Vertex_ARRAY_0x448[VERTEXGROUPCOUNT2] =
{
    {{    122,      6,   -205}, 0x0000, 0x1000, 0x07fa, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,   -205}, 0x0000, 0x1000, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,    202,   -205}, 0x0000, 0x081c, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{    122,    202,   -205}, 0x0000, 0x081c, 0x07fa, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,    187}, 0x0000, 0xffa6, 0x0099, {0xe8, 0xe8, 0xe8, 0xff} },
    {{    122,      6,    187}, 0x0000, 0x0895, 0x0081, {0xff, 0xff, 0xff, 0xff} },
    {{    122,    202,    187}, 0x0000, 0x0895, 0x0780, {0xff, 0xff, 0xff, 0xff} },
    {{   -123,    202,    187}, 0x0000, 0xffa6, 0x0799, {0xf0, 0xf0, 0xf0, 0xff} },
    {{    122,      6,    236}, 0x0000, 0x0000, 0x06c4, {0xff, 0xff, 0xff, 0xff} },
    {{    122,      6,   -205}, 0x0000, 0x0000, 0x0000, {0xe2, 0xe2, 0xe2, 0xff} },
    {{    122,    202,   -205}, 0x0000, 0x0400, 0x0000, {0xe6, 0xe6, 0xe6, 0xff} },
    {{    122,    202,    419}, 0x0000, 0x0400, 0x0996, {0xff, 0xff, 0xff, 0xff} },
    {{   -123,    202,    419}, 0x0000, 0x0400, 0x0990, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,    202,   -205}, 0x0000, 0x0400, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,   -205}, 0x0000, 0x0000, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,    236}, 0x0000, 0x0000, 0x06c0, {0x72, 0x72, 0x72, 0xff} },
    {{    122,      6,   -205}, 0x0000, 0x1000, 0x07fa, {0x72, 0x72, 0x72, 0xff} },
    {{    122,      6,    236}, 0x0000, 0x0000, 0x07fa, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,    236}, 0x0000, 0x0000, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{   -123,      6,   -205}, 0x0000, 0x1000, 0x0000, {0x72, 0x72, 0x72, 0xff} },
    {{    122,    202,    419}, 0x0000, 0x0000, 0x0000, {0x36, 0x36, 0x36, 0xff} },
    {{   -123,    202,    419}, 0x0000, 0x0000, 0x0000, {0x36, 0x36, 0x36, 0xff} },
    {{   -123,    202,   -205}, 0x0000, 0x0000, 0x0000, {0x36, 0x36, 0x36, 0xff} },
    {{    122,    202,   -205}, 0x0000, 0x0000, 0x0000, {0x36, 0x36, 0x36, 0xff} }
};
Vertex Collision_Vertex_ARRAY_0x5c8[COLLISIONVERTEXCOUNT2] = 
{
    {{    122,      6,   -205}, 0x0000, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,      6,   -205}, 0x0001, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,    202,   -205}, 0x0002, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,    202,   -205}, 0x0003, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,      6,    187}, 0x0004, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,      6,    187}, 0x0005, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,    202,    187}, 0x0006, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,    202,    187}, 0x0007, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,      6,    236}, 0x0008, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{    122,    202,    419}, 0x000b, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,    202,    419}, 0x000c, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} },
    {{   -123,      6,    236}, 0x000f, 0x0000, 0x0000, {0xff, 0xff, 0x00, 0x00} }
};

s16 POINT_USAGE_ARRAY_0x688[VERTEXGROUPCOUNT2] = 
{
       0x9,     0xE,     0xD,     0xA,
        -1,      -1,      -1,      -1,
      0x11,    0x10,    0x17,    0x14,
      0x15,    0x16,    0x13,    0x12,
        -1,      -1,      -1,      -1,
        -1,      -1,      -1,      -1,
};

ModelRoData_DisplayList_CollisionRecord DL_Housing =
{
    GFX_ARRAY_PRIMARY_0x810,
    NULL,
    Vertex_ARRAY_0x448,
    VERTEXGROUPCOUNT2,
    COLLISIONVERTEXCOUNT2,
    Collision_Vertex_ARRAY_0x5c8,
    POINT_USAGE_ARRAY_0x688,
    4,    0,
    0x0
};

Gfx GFX_ARRAY_PRIMARY_0x6d8[] =
{
    gsDPPipeSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, G_TX_RENDERTILE, G_ON),
    gsDPNoOpTag(IMAGE_247),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPMatrix(0x03000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPVertex(0x04000000, 8, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPNoOpTag(IMAGE_511),
    0xB1000035, 0x00007643,
    gsSPEndDisplayList(),
};

Gfx GFX_ARRAY_SECONDARY_0x738[] =
{
    gsDPPipeSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, G_TX_RENDERTILE, G_ON),
    gsDPNoOpTag(IMAGE_265),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPMatrix(0x03000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPVertex(0x04000080, 8, 0),
    gsSP2Triangles(0, 59, 25, 0, 42, 16, 8, 0),
    gsSPEndDisplayList(),
};

Gfx GFX_ARRAY_PRIMARY_0x790[] =
{
    gsDPPipeSync(), 
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Gfx GFX_ARRAY_SECONDARY_0x7a8[] =
{
    gsDPPipeSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(3456, 3456, 2, G_TX_RENDERTILE, G_ON),
    gsDPNoOpTag(IMAGE_GLASS3),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPSetGeometryMode(G_LIGHTING | G_TEXTURE_GEN),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPMatrix(0x03000040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPVertex(0x04000000, 4, 0),
    gsSP2Triangles(0, 0, 25, 0, 0, 16, 8, 0),
    gsSPClearGeometryMode(G_LIGHTING | G_TEXTURE_GEN),
    gsSPEndDisplayList(),
};


Gfx GFX_ARRAY_PRIMARY_0x810[] =
{
    gsDPPipeSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, G_TX_RENDERTILE, G_ON),
    gsDPNoOpTag(IMAGE_511),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPMatrix(0x03000040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPVertex(0x04000000, 16, 0),
    gsSP2Triangles(0, 0, 25, 0, 0, 16, 8, 0),
    gsDPNoOpTag(IMAGE_856),
    gsSP2Triangles(0, 0, 59, 0, 0, 50, 42, 0),
    gsDPNoOpTag(IMAGE_247),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSP2Triangles(0, 127, 93, 0, 110, 84, 76, 0),
    gsDPNoOpTag(IMAGE_511),
    gsSPVertex(0x04000100, 8, 0),
    gsSP2Triangles(0, 0, 25, 0, 0, 16, 8, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 1, G_TX_RENDERTILE, G_ON),
    gsDPNoOpTag(IMAGE_1514),
    gsSP2Triangles(0, 0, 59, 0, 0, 50, 42, 0),
    gsSPEndDisplayList(),
};
