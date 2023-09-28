#ifndef _CHRAI_H_
#define _CHRAI_H_
#include <ultra64.h>

#include <bondtypes.h>

#define CHRAI_TICKRATE_F 60.0f

/*
Stop Scolling:
00000000
Sets both scroll timers to zero
*/
#define MONSTOPSCROLL() 0x0
/*
Horizontal Scroll:
00000001	xxxxxxxx	tttttttt
[x] 'width' value like in image mapping to shift the image; short hex percent
[t]ime the move occurs in
*/
#define MONHORZSCROLL(x,t) 0x1, x, t
/*
Vertical Scroll:
00000002	yyyyyyyy	tttttttt
[y] 'height' value like in image mapping to shift image; short hex percent
[t]ime the move occurs in
*/
#define MONVERTSCROLL(y,t) 0x2, y, t
/*
Horizontal Scroll Nonadditive:
00000003	xxxxxxxx	tttttttt
[x] 'width' value shifting the image from original position; short hex percent
[t]ime the move occurs in
*/
#define MONHORZSCROLLNA(x,t) 0x3, x, t
/*
Vertical Scroll Nonadditive:
00000004	yyyyyyyy	tttttttt
[y] 'height' value shifting the image from original position; short hex percent
[t]ime the move occurs in
*/
#define MONVERTSCROLLNA(y,t) 0x4, y, t
/*
Zoom Width:
00000005	xxxxxxxx	tttttttt
[x] zoom factor as a short hex percentage
[t]ime for complete zoom
*/
#define MONZOOMWIDTH(x,t) 0x5, x, t
/*
Zoom Height:
00000006	yyyyyyyy	tttttttt
[x] zoom factor as a short hex percentage
[t]ime for complete zoom
*/
#define MONZOOMHEIGHT(y,t) 0x6, y, t

#define MONZOOMSQUARE(w,t) MONZOOMWIDTH(w, t), MONZOOMHEIGHT(w, t)

/*
Use image:
00000007	000000xx
xx is image number in global image list, starting with 0=BOND
*/
#define MONUSEIMAGE(x) 0x7, x
/*
Hold for Time:
00000008	tttttttt
[t]ime to hold; necessary to break loops, like the 03 action command
*/
#define MONHOLDTIME(t) 0x8, t
/*
Jump to Routine:
00000009	pppppppp
[p]ointer to another animation routine where processing resumes
*/
#define MONJUMPTO(p) 0x9, p
/*
Jump on Chance:
0000000A	pppppppp	0000xxxx
[p]ointer to another animation routine where processing resumes
[x] value to test against a random value.  Jump if rand < xxxx
*/
#define MONJUMPCHANCE(p,x) 0xA, p, x
/*
Loop:
0000000B
restarts group from the beginning of the current animation
*/
#define MONLOOP() 0xB
/*
Stop Animation:
0000000C
Unconditionally stops the animation using the S1 flag.
*/
#define MONSTOPANIM() 0xC
/*
RGBA:
0000000D	RRGGBBAA	tttttttt
New [R]ed, [G]reen, [B]lue, and [A]lpha components
[t]ime for complete transition
*/
#define MONRGBA(rgba, t) 0xD, rgba, t
/*
Set Rotation:
0000000E	rrrrrrrr
set image [r]otation; 0x2000 rotates 360 degrees
primarily used to reset rotation to 0
*/
#define MONSETROTATION(r) 0xE, r
/*
Rotate Image:
0000000F	rrrr.rrrr
[r]otate image incrementally rrrr.rrrr%; 
0x2000 rotates approximately 45 degrees, 0x1555 to mimic a clock
*/
#define MONROTATEIMAGE(r) 0xF, r

#define COLOR_WHITE 0xFFFFFFFF

#define COLOR_SILVER 0xC8C8C8FF
#define COLOR_MINESHAFT 0x383838FF
#define COLOR_MINESHAFT2 0x323232FF
#define COLOR_MINESHAFT3 0x202020FF
#define COLOR_CODGRAY 0x0A0A0AFF
#define COLOR_GRAY 0x808080FF
#define COLOR_BLACK 0x000000FF

#define COLOR_PERSIANRED 0xC83232FF
#define COLOR_THUNDERBIRD 0xC81414FF
#define COLOR_ALIZARINCRIMSON 0xDC2828FF
#define COLOR_DIESEL 0x280000FF
#define COLOR_LOTUS 0x803838FF
#define COLOR_GOVERNORBAY 0x3232C8FF
#define COLOR_CYPRUS 0x004040FF
#define COLOR_MINSK 0x303080FF

#define COLOR_PESTO 0x808032FF
#define COLOR_VERDUNGREEN 0x404000FF
#define COLOR_APPLE 0x32C832FF
#define COLOR_APPLE2 0x38C838FF
#define COLOR_STRONGGREEN 0x00C800FF
#define COLOR_GREEN 0x0AFF0AFE
#define COLOR_TOMTHUMB 0x406440FF
#define COLOR_SANFELIX 0x0A640AFE
#define COLOR_SEAGREEN 0x308030FF
#define COLOR_GREENKELP 0x1E381EFF
#define COLOR_DARKGREEN 0x0A960AFF
#define COLOR_ALMOSTDARKGREEN 0x0A960AFE
#define COLOR_DARKGREEN2 0x0A780AFF
#define COLOR_DARKERGREEN 0x087808FF
#define COLOR_DEEPFIR 0x003C00FF
#define COLOR_BARELYGREEN 0x00800000
#define COLOR_BARELYGREENOPAQUE 0x008000FF

#define TWO_PERCENT_CHANCE 0x051E
#define TEN_PERCENT_CHANCE 0x1999
#define TWENTY_PERCENT_CHANCE 0x3333
#define FOURTY_PERCENT_CHANCE 0x6666
#define SIXTY_PERCENT_CHANCE 0x9999
#define HUNDRED_PERCENT_CHANCE 0xFFFF

#define SFX_RELATED_LEN 8
#define POS_DATA_ENTRY_LEN 600
#define PTR_LIST_OBJECT_LOOKUP_INDICES_LEN 512
#define BSS_8007161C_LEN 256
#define BSS_8007161C_DATA_LEN 16
#define MAX_WEAPON_SLOTS 30
#define MAX_HAT_SLOTS 10
#define MAX_AMMO_CRATES 20
#define PROJECTILES_ARR_MAX 20
#define EMBEDMENT_ARR_MAX 40
#define ONSCREEN_PROP_LIST_LEN 500



/**
 * Getting a match on alloc_lookup_buffers makes it seem
 * the struct is just one continuous array. (or maybe there's no struct....)
*/
struct roomproplistchunk
{
    s16 propnums[16];
};

extern struct SetupPtrs g_SetupPtrs;

extern u32 monAnimRadarSub1[];
extern u32 monAnimRadarSub2[];
extern u32 monAnimRadarSub3[];
extern u32 monAnim0BRadar[];
extern u32 monAnim0CSpinningCube[];
extern u32 monAnim17RandImageEffect[];
extern u32 monRandEffectChanceSHUTTLE1[];
extern u32 monRandEffectChanceSHUTTLE2[];
extern u32 monRandEffectChanceEARTHFULL1[];
extern u32 monRandEffectChanceEARTHFULL2[];
extern u32 monRandEffectChanceBLUESTARS[];
extern u32 monRandEffectChanceGALAXY1[];
extern u32 monRandEffectChanceGALAXY2[];
extern u32 monRandEffectChanceEARTHTEXT[];
extern u32 monRandEffectChanceTARGETEARTH[];
extern u32 monRandEffectChanceGALAXY3[];
extern u32 monRandChanceScrollOrZoomRandRGBN[];
extern u32 D_80031B10[];
extern u32 monRandChanceScrollOrZoomRed[];
extern u32 monRandChanceScrollOrZoomGreen[];
extern u32 monRandChanceScrollOrZoomBlue[];
extern u32 monRandChanceScrollOrZoom[];
extern u32 monAnim27RandomEffectScrollRight[];
extern u32 monAnim28RandomEffectScrollUpFast[];
extern u32 monAnim29RandomEffectScrollUp[];
extern u32 monAnim2ARandEffectScrollZoom1[];
extern u32 monAnim2ARandEffectScrollZoom2[];
extern u32 monAnim2CRandEffectWaitRoute[];
extern u32 monAnim2DRandEffectFlash[];
extern u32 monAnim00Bond[];
extern u32 monAnim34[];
extern u32 monAnim35Taser[];
extern WeaponObjRecord* temp_mine_table[30];
extern f32 gas_damage_flag;
extern u32 gas_cutoff_flag;
extern f32 difficulty ;
extern stagesetup g_CurrentSetup;
extern s16 * ptr_list_object_lookup_indices;
extern PropRecord pos_data_entry[];

extern PropRecord *ptr_obj_pos_list_current_entry;
extern PropRecord *ptr_obj_pos_list_first_entry;
extern PropRecord *ptr_obj_pos_list_final_entry;

extern s32                                g_OnScreenPropCount;
extern PropRecord **                      g_LastOnScreenProp;
extern PropRecord *                       g_OnScreenPropList[];
extern PropRecord *                       g_InteractProp;
extern s16 *                              RoomPropListChunkIndexes;
extern struct roomproplistchunk *         RoomPropListChunks;
extern sfxRecord                          sfx_related[];
extern struct WeaponObjRecord             g_WeaponSlots[];
extern struct HatRecord                   g_HatSlots[];
extern struct AmmoCrateRecord             g_AmmoCrates[];
extern struct Projectile                  g_Projectiles[];
extern struct Embedment                   g_Embedments[];
extern struct coord3d                     flt_CODE_bss_80075B78;
extern struct coord3d                     flt_CODE_bss_80075B88;


extern MonitorRecord g_MonitorAnimController;
extern struct object_animation_controller g_UnknownAnimController;
extern struct object_animation_controller g_TaserAnimController;

extern stagesetup                        *g_ptrStageSetupFile;

void          alarmDeactivate(void);
s32           chraiitemsize(u8 *AIList, s32 offset);
void          check_deactivate_gas_sound(void);
void          handle_mp_respawn_and_some_things(void);
void          determing_type_of_object_and_detection(void);
void          chraiUpdateOnscreenPropCount(void);
void          chrpropUpdateAutoaimTarget(void);
void          chraiCheckUseHeldItems(void);
bool          bond_interact_object(void);
void          sub_GAME_7F03D0D4(void);
void          chrpropRegisterRoom(PropRecord *, s16);
PropRecord*           propAllocate();
void          chrpropDeregisterRooms(PropRecord *);
void          sub_GAME_7F03E27C(PropRecord *, coord3d *, coord3d *, f32);
void          chrpropRegisterRooms(PropRecord *posData);

void          chrpropActivate(PropRecord *);
void          chrpropEnable(PropRecord *);
void          chrpropActivateThisFrame(PropRecord *);
void          chrpropReparent(PropRecord *newChild, PropRecord *host);
AIRecord     *ailistFindById(s32 ID);
void          chraiGetCollisionBounds(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *arg3, f32 *arg4);
void          sub_GAME_7F03D058(PropRecord *prop, bool unset);
void          chraiGetCollisionBoundsWithoutY(PropRecord *arg0, struct rect4f **arg1, s32 *arg2);
s32 chrpropTestPointInPolygon(coord3d *point, struct rect4f *polygon, s32 edges);
void          roomGetProps(s32 *roomids);
ObjectRecord *scan_position_data_table_for_normal_object_at_preset(s32 arg0);
Gfx          *chrpropsRenderPass(Gfx *arg0, s32 roomid, s32 arg2);
PropRecord   *get_ptr_obj_pos_list_current_entry(void);
void          chraiGetPropRoomIds(PropRecord *self, s32 *roomids);
void          chrpropFree(PropRecord *prop);
void          chrpropDisable(PropRecord *prop);
f32           chrpropBBOXGetXmin(ModelRoData_BoundingBoxRecord *modelBoundingBox);
f32           chrpropBBOXGetYmin(ModelRoData_BoundingBoxRecord *modelBoundingBox);
f32           chrpropBBOXGetYmax(ModelRoData_BoundingBoxRecord *modelBoundingBox);
f32           chrpropBBOXGetZmin(ModelRoData_BoundingBoxRecord *modelBoundingBox);
ObjectRecord *sub_GAME_7F03FAB0(PadRecord *pad, s32 RoomID);
void          chraiGetCollisionBounds(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *arg3, f32 *arg4);
void chrpropGetCollisionBounds(PropRecord *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
f32 sub_GAME_7F03CFE8(PropRecord *arg0);
f32 chrpropSumMatrixPosX(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
f32 chrpropSumMatrixNegX(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
f32 chrpropSumMatrixPosY(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
f32 chrpropSumMatrixNegY(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
f32 chrpropSumMatrixPosZ(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
f32 chrpropSumMatrixNegZ(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1);
void sub_GAME_7F03F540(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1, struct rect4f* arg2, struct collision_data *arg3);
void sub_GAME_7F03F948(struct coord3d *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
#endif
