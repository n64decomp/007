#ifndef _OBJECTHANDLER_
#define _OBJECTHANDLER_
#include <ultra64.h>
#include <bondtypes.h>

extern s32 D_80036084;
extern f32 D_80036088;
extern u32 D_80036250;
extern s32 D_80036410;
extern s32 D_80036414;
extern s32 D_80036418;
extern s32 D_8003641C;
extern s32 vtxallocator;

// arg0 unknown pointer
void sub_GAME_7F070090(void *arg0, f32 arg1, f32 arg2);
void sub_GAME_7F06FF18(Model *, f32, f32);
void sub_GAME_7F06FF5C(Model *model, s32 arg1);
void modelSetScale(Model*, f32);
void getsuboffset(Model *, coord3d *);
void sub_GAME_7F070AEC(Model *, s32, s32);
void subcalcpos(Model *);
void modelSetAnimEndFrame(Model *model, f32 endframe);

void sub_GAME_7F06F780(Model *, f32);
void sub_GAME_7F06F878(Model *, ModelAnimation *, s32, f32, f32, f32);

void modelSetAnimation(Model *, ModelAnimation *, s32, f32, f32, f32 duration);
void modelSetAnimLooping(Model *, f32, f32);
void modelSetAnimEndFrame(Model *, f32);
void sub_GAME_7F06CE84(Model *, f32);

void *extract_id_from_object_structure_microcode(Model *Objinst, ModelNode *root);
f32 getsubroty(Model *objinst);
void setsubroty(Model *objinst, f32 radHeading);
void modelSetAnimationWithMerge(Model *, ModelAnimation *, s32, f32, f32, f32, s32);
f32 objecthandlerGetModelField28(Model *model);

ModelAnimation * objecthandlerGetModelAnim(Model *);
f32 modelGetAbsAnimSpeed(Model*);
s8 objecthandlerGetModelGunhand(Model *);
f32 sub_GAME_7F06F5C4(Model *);
void modelSetAnimSpeed(Model *, f32, f32);
f32 modelGetAnimSpeed(Model *);
void sub_GAME_7F06FE90(Model *arg0, f32 arg1, f32 arg2);
f32 getinstsize(Model *arg0);

void fileLoad(ModelFileHeader *header,char *name);
void load_object_into_memory_unused_maybe(ModelFileHeader *header,int *recallstring,int *targetloc,int sizeleft);
void modelCalculateRwDataLen(ModelFileHeader *objheader);
Model *get_aircraft_obj_instance_controller(ModelFileHeader *);
void sub_GAME_7F06C3B4(Model *, s32,  ModelFileHeader *);
Mtxf *getsubmatrix(Model *objinst);

// tentative signature
void setpartoffset(Model *, ModelNode *, coord3d *);

// tentative signature
void setsuboffset(Model *arg0, coord3d *arg1);

// tentative signature
PropRecord *chrGiveWeapon(ChrRecord *self, s32 PropID, ITEM_IDS ItemID, s32 flags);

// tentative signature
Mtxf* sub_GAME_7F06C660(Model *arg0, ModelNode *arg1, s32 arg2);

// called with struct ChrRecord->field_20
void sub_GAME_7F06B248(void *arg0);
void drawjointlist(struct unk_joint_list *arg0, void* arg1);
void sub_GAME_7F073FC8(s32);
void sub_GAME_7F0701D4(s32 arg0);
u32 sub_GAME_7F0701E0(void);

// arg0: unknown type. arg1: unknown type. arg5: unknown type, maybe struct.
void sub_GAME_7F06D2E4(s32, s32, ModelSkeleton*, void* anim, s32, s16*);

// arg2 unknown type.
void sub_GAME_7F075FAC(Model *, ModelFileHeader *, void *);
void modelSetAnimFlipFunction(Model *, void *);
void subcalcmatrices(struct unk_joint_list *, Model *);
void instcalcmatrices(struct unk_joint_list *arg0, Model *arg1);
void load_object_fill_header(struct ModelFileHeader *objheader, u8 *name, void *targetloc, s32 sizeleft, s32 buffer);
void* get_obj_instance_controller_for_header(struct ModelFileHeader* arg0);
void subdraw(s32 arg0, struct Model *);
void sub_GAME_7F06EFC4(struct Model *);

#ifndef VERSION_EU
void return_null(void);
#endif

#endif
