#ifndef _OBJECTHANDLER_
#define _OBJECTHANDLER_
#include <ultra64.h>
#include <bondtypes.h>

struct bondstruct_unk_animation_related {
    char* unk00;
    char* unk04;
    char* unk08;
};

struct bondstruct_unk_op07_related {
    s32 unk00;
    s32 unk04;
    s32 unk0C;
};

extern s32 g_ModelDistanceDisabled;
extern f32 g_ModelDistanceScale;
extern u32 g_ModelAnimMergingEnabled;
extern s32 D_80036410;
extern struct bondstruct_unk_animation_related* D_80036414;
extern s32 D_80036418;
extern s32 D_8003641C;
extern u32 D_800363F0;
extern struct Vertex* (*vtxallocator)(s32 numvertices);
extern struct bondstruct_unk_op07_related D_800360C4[];
extern Vertex D_800363E0;

// arg0 unknown pointer
void modelSetAnimFrame2(Model* model, f32 frame1, f32 frame2);
void modelSetAnimPlaySpeed(Model *, f32, f32);
void sub_GAME_7F06FF5C(Model *model, s32 arg1);
void modelSetScale(Model*, f32);
void getsuboffset(Model *, coord3d *);
void modelTickAnimQuarterSpeed(Model *, s32, s32);
void subcalcpos(Model *);
void modelSetAnimEndFrame(Model *model, f32 endframe);

void modelCopyAnimForMerge(Model *, f32);
void modelSetAnimation2(Model *, ModelAnimation *, s32, f32, f32, f32);

void modelSetAnimation(Model *, ModelAnimation *, s32, f32, f32, f32 duration);
void modelSetAnimLooping(Model *, f32, f32);
void modelSetAnimEndFrame(Model *, f32);
void sub_GAME_7F06CE84(Model *, f32);

union ModelRwData* modelGetNodeRwData(Model *Objinst, ModelNode *root);
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
void modelAttachHead(Model *, ModelNode*,  ModelFileHeader *);
Mtxf *getsubmatrix(Model *objinst);

// tentative signature
void setpartoffset(Model *, ModelNode *, coord3d *);

// tentative signature
void setsuboffset(Model *arg0, coord3d *arg1);

// tentative signature
PropRecord *chrGiveWeapon(ChrRecord *self, s32 PropID, ITEM_IDS ItemID, s32 flags);

// tentative signature
Mtxf* modelFindNodeMtx(Model *arg0, ModelNode *arg1, s32 arg2);

// called with struct ChrRecord->field_20
void sub_GAME_7F06B248(void *arg0);
void drawjointlist(struct unk_joint_list *arg0, void* arg1);
void sub_GAME_7F073FC8(s32);
void modelSetAnimMergingEnabled(s32 arg0);
u32 modelIsAnimMergingEnabled(void);

// arg0: unknown type. arg1: unknown type. arg5: unknown type, maybe struct.
void sub_GAME_7F06D2E4(s32, s32, ModelSkeleton*, void* anim, s32, s16*);

void modelInit(struct Model *, struct ModelFileHeader *, u32 *);
void animInit(struct Model *, struct ModelFileHeader *, u32 *);
void modelSetAnimFlipFunction(Model *, void *);
void subcalcmatrices(struct unk_joint_list *, Model *);
void instcalcmatrices(struct unk_joint_list *arg0, Model *arg1);
void load_object_fill_header(struct ModelFileHeader *objheader, u8 *name, void *targetloc, s32 sizeleft, struct texpool * buffer);
void* get_obj_instance_controller_for_header(struct ModelFileHeader* arg0);
void subdraw(struct unk_joint_list *arg0, struct Model *);
void sub_GAME_7F06EFC4(struct Model *);
void modelAttachPart(Model *pmodel, ModelFileHeader *pmodeldef, ModelNode *pnode, ModelFileHeader *cmodeldef);
void modelInitRwData(Model *model, ModelNode *startnode);
void modelApplyDistanceRelations(Model* model, ModelNode* node);
void modelApplyHeadRelations(Model* model, ModelNode* bodynode);
void modelApplyToggleRelations(Model* model, ModelNode* node);

#ifndef VERSION_EU
void return_null(void);
#endif

#endif
